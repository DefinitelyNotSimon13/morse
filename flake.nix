{
  description = "Flake for direnv";
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
  inputs.systems.url = "github:nix-systems/default";
  inputs.flake-utils = {
    url = "github:numtide/flake-utils";
    inputs.systems.follows = "systems";
  };

  outputs =
    { nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (
      system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        llvm = pkgs.llvmPackages_latest;
        lib = nixpkgs.lib;
      in
      {
        devShells.default = pkgs.mkShell {
          # Uncomment relevant sections!

          # Packages e.g. used in cli
          # packages = with pkgs; [];

          # Dependencies used during runtime
          # pkgs of hosts architecture, e.g. added to "$NIX_LD_FLAGS"
          buildInputs = [
            # llvm.libcxx
          ];

          # Dependencies used during compiletime
          # pkgs of buildPlatform's architecture, added to "$PATH"
          nativeBuildInputs = with pkgs; [
            # cmake
            # llvm.lldb
            clang-tools
            # clang
          ];

          # CPATH = builtins.concatStringsSep ":" [
          #   (lib.makeSearchPathOutput "dev" "include" [ llvm.libcxx ])
          #   (lib.makeSearchPath "resource-root/include" [ llvm.clang ])
          # ];

          shellHook = ''
            echo -e "\n\e[1;32mUsing flake development environment!\e[0m\n"
          '';
        };
      }
    );
}
