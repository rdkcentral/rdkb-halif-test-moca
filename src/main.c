/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2023 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <ut.h>
#include <ut_log.h>
#include <stdlib.h>
#include "moca_hal.h"

extern int register_hal_tests( void );

int init_moca_hal_init(void)
{
    UT_LOG("moca_hal_init Initialized successfully.");
    UT_LOG("moca_hal_init returned success");
    return 0;
}


int main(int argc, char** argv)
{
    int registerReturn = 0;
     /* Register tests as required, then call the UT-main to support switches and triggering */
    UT_init( argc, argv );
    /* Check if tests are registered successfully */
    registerReturn = register_hal_tests();
    if (registerReturn == 0)
    {
        printf("register_hal_tests() returned success \n");
    }
    else
    {
        printf("register_hal_tests() returned failure");
        return 1;
    }
    UT_run_tests();

    return 0;
}
