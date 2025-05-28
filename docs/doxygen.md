# Doxygen Comment Templates
Below are the documentation comments we used in our last C project.
Note as the comments where intended for an embedded C project some
documentation fields may be unneccessary/missing.

## 📝 Documentation

- All files should contain a top level comment.
- All public functions should be documented in the header file.
- All private functions should be documented at the definition in the source files.
- All structs and enums should be documented.
- All global variables should be documented.
- All "complicated" macros should be documented.
- All typedefs should be documented.

### Documentation templates

To ensure a uniform documentation all doc comments, should be loosely based on the following
templates. Irrelevant fields can and should be ommited to avoid bloat.

> ![NOTE]
> HTML Tags were used to the way our documentation page for the project was generated
> A more structured overview of doc comments can be found [here](https://tiktaktoe.episko.de/html/d8/d50/md__2github_2workspace_2Conventions.html).

<div class="tabbed">

- <b class="tab-title"> Files </b>

    ```c
    /**
     * @file  [File name]
     *
     * @brief [Brief description]
     *
     * @details
     * This file contains [...].
     *
     * @ingroup [HAL/Logic/Presentation/Utility]
     *
     * @see 
     *  [Header/Source]
     *  [Any other relevant]
     *
     * @note
     *  [Additional notes, if relevant...]
     *
     * @copyright
     * This Source Code Form is subject to the terms of the Mozilla Public
     * License, v2.0. If a copy of the MPL was not distributed with this
     * file, You can obtain one at http://mozilla.org/MPL/2.0/.
     */
    ```

- <b class="tab-title"> Functions </b>

    ```c
    /**
     * @brief [Brief description]
     *
     * @details 
     * [Detailed description, only if relevant]
     * 
     * @param[in/out/inout] param1 Description of paramater
     * ...
     *
     * @return [Description of return value, or "void"]
     *
     * @note [Any additional notes or constraints, if relevant.]
     */
    void example_function(uint8_t param1);
    ```

- <b class="tab-title"> Structs </b>

    ```c
    /**
     * @brief [Brief description]
     *
     * @details 
     * [Detailed description, only if relevant]
     *
     * @note [Any additional notes or constraints, if relevant.]
     */
    typedef struct {
        int member1; /**< [Description of member1] */
        float member2; /**< [Description of member2] */
        // ...
    } ExampleStruct;
    ```

- <b class="tab-title"> Enums </b>

    ```c
    /**
     * @brief [Brief description]
     *
     * @details 
     * [Detailed description, only if relevant]
     *
     * @note [Any additional notes or constraints, if relevant.]
     */
    typedef enum {
        ENUM_VALUE1; /**< [Description of ENUM_VALUE1] */
        ENUM_VALUE2; /**< [Description of ENUM_VALUE2] */
        ENUM_VALUE3; /**< [Description of ENUM_VALUE3] */
        // ...
    } ExampleEnum;
    ```

- <b class="tab-title"> Typedefs </b>

    ```c
    /**
     * @brief [Brief description]
     *
     * @details 
     * [Detailed description, only if relevant]
     *
     * @note [Any additional notes or constraints, if relevant.]
     */
    typedef unsigned long ExampleType;
    ```

- <b class="tab-title"> Macros </b>

    ```c
    /**
     * @def EXAMPLE_MACRO
     * @brief [Short description of what the macro does or represents.]
     *
     * @details
     * [If neccessary, explain the purpose of the macro, 
     *  parameters (if function-like macro),...]
     *
     * @note [Any additional notes or constraints, if relevant.]
     *
     * Example: [if relevant]
     * @code
     *   int value = MY_MACRO;
     * @endcode
     */
    #define EXAMPLE_MACRO 42
    ```

- <b class="tab-title"> Global Variables </b>

    ```c
    /**
     * @brief [Brief description]
     *
     * @details 
     * [What global variable is used for, scope, and initialization details.]
     *
     * @note [Any additional notes or constraints, if relevant.]
     */
    extern int g_exampleGlobal;
    ```
</div>
