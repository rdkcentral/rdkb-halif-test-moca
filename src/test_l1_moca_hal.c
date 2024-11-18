/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:*
* Copyright 2016 RDK Management
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

/**
* @file test_moca_hal.c
* @page moca_hal Level 1 Tests
*
* ## Module's Role
* This module includes Level 1 functional tests (success and failure scenarios).
* This is to ensure that the moca_hal APIs meet the requirements across all vendors.
*
* **Pre-Conditions:**  None
* **Dependencies:** None
*
* Ref to API Definition specification documentation : [halSpec.md](../../../docs/halSpec.md)
*/

#include <ut.h>
#include <ut_log.h>
#include "moca_hal.h"
#include <limits.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

extern int init_moca_hal_init(void);

/**
* @brief This test is used to verify the functionality of the moca_GetIfConfig API in positive scenario.
*
* This test case verifies the behavior of the moca_GetIfConfig API by checking the return value and the values of the output parameters.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 001
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | First set of conditions | ifIndex = 0, mocaConfig = uninitialized | ret = STATUS_SUCCESS, mocaConfig.InstanceNumber = 0 | Should be successful |
*/

void test_l1_moca_hal_positive1_moca_GetIfConfig(void) {
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_GetIfConfig...");

    ULONG ifIndex = 0;
    moca_cfg_t mocaConfig;

    // Invoke the API
    UT_LOG("Invoking moca_GetIfConfig.");
    INT ret = moca_GetIfConfig(ifIndex, &mocaConfig);
    UT_LOG("Return Value: %d", ret);
    
    // Perform assertions
    UT_ASSERT_EQUAL(ret, STATUS_SUCCESS);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_GetIfConfig...");
}

/**
* @brief Test case to verify the failure scenario of the moca_GetIfConfig function.
*
* This test case verifies if the moca_GetIfConfig function returns the expected failure status when invoked with invalid inputs.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 002
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | First set of conditions | ifIndex = 0, mocaConfig = NULL | ret = STATUS_FAILURE | Should be successful |
*/
void test_l1_moca_hal_negative1_moca_GetIfConfig(void) {
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_GetIfConfig...");

    ULONG ifIndex = 1;
    
    // Invoke the API
    UT_LOG("Invoking moca_GetIfConfig.");
    INT ret = moca_GetIfConfig(ifIndex, NULL);
    UT_LOG("Return Value: %d", ret);
    
    // Perform assertions
    UT_ASSERT_EQUAL(ret, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_GetIfConfig...");
}

/**
 * @brief This test case is used to verify the functionality of the moca_IfGetStats function with valid input parameters.
 *
 * The moca_IfGetStats function is called with a valid ifIndex parameter and a valid pointer to stats structure.
 * The test aims to verify the correctness of the returned status and the values of the stats structure.
 *
 * Test Group ID: Basic: 01
 * Test Case ID: 003
 * Priority: High
 *
 * Pre-Conditions: None
 * Dependencies: None
 * User Interaction: If the user chooses to run the test in interactive mode, then the test case has to be selected via the console.
 *
 * Test Procedure:
 *  - |01| First set of conditions | ifIndex = 0, pmoca_stats = ValidPtr | The function is expected to return STATUS_SUCCESS | Should be successful
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :--------------: | ----------- | --------- | --------------- | ----- |
 * |      01          | First set of conditions | ifIndex = 0, pmoca_stats = ValidPtr | The function is expected to return STATUS_SUCCESS | Should be successful |
 */
void test_l1_moca_hal_positive1_moca_IfGetStats(void)
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_IfGetStats...");

    ULONG ifIndex = 0;
    moca_stats_t stats;
    
    UT_LOG("Invoking moca_IfGetStats with ifIndex = %lu and pmoca_stats = ValidPtr", ifIndex);
    INT status = moca_IfGetStats(ifIndex, &stats);

    UT_LOG("Output: BytesSent = %lu, BytesReceived = %lu, ...", stats.BytesSent, stats.BytesReceived);
    UT_LOG("Return: STATUS = %d", status);

    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_IfGetStats...");
}

/**
* @brief Test case to verify behavior when passing NULL for pmocaStats in moca_IfGetStats function
*
* This test case is to verify the behavior of the moca_IfGetStats function when the pmocaStats parameter is passed as NULL. The objective is to
* ensure that the function returns STATUS_FAILURE when the input parameter is invalid.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 004
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Pass NULL for pmocaStats | ifIndex = 0, pmoca_stats = NULL | STATUS_FAILURE | The function should return STATUS_FAILURE |
*/
void test_l1_moca_hal_negative1_moca_IfGetStats(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_IfGetStats...");

    ULONG ifIndex = 0;
    moca_stats_t *pmoca_stats = NULL;
    
    UT_LOG("Invoking moca_IfGetStats with ifIndex = %lu and pmoca_stats = NULL");
    INT status = moca_IfGetStats(ifIndex, pmoca_stats);

    UT_LOG("Return: STATUS = %d", status);

    UT_ASSERT_EQUAL(status, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_IfGetStats...");
}

/**
 * @brief Test to verify the functionality of the moca_SetIfConfig API with valid interface index and configuration.
 *
 * This test case verifies the behavior of the moca_SetIfConfig API when called with a valid interface index and configuration. It ensures that the API correctly sets the MOCA interface configuration.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 005
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * 01 | Verify that the moca_SetIfConfig API correctly sets the MOCA interface configuration with valid input.
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Verify that the API sets the MOCA interface configuration correctly. | ifIndex = 0, mocaConfig = {0} | Success | Should be successful |
 */

void test_l1_moca_hal_positive1_moca_SetIfConfig( void )
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_SetIfConfig...");

    ULONG ifIndex = 0;
    moca_cfg_t *pmoca_config;
    
    UT_LOG("Invoking moca_SetIfConfig.");
    INT ret = moca_SetIfConfig(ifIndex, pmoca_config);
    UT_LOG("Return: ret = %d", ret);
    if(ret == STATUS_SUCCESS) {
        UT_LOG("Test Case Passed: moca_SetIfConfig was successful");
    } else {
        UT_LOG("Test Case Failed: moca_SetIfConfig returned error");
    }
    UT_ASSERT_EQUAL(ret, STATUS_SUCCESS);
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_SetIfConfig...");
}

/**
* @brief Test case to verify the functionality of moca_SetIfConfig API with an invalid interface index
*
* This test case verifies whether the moca_SetIfConfig API returns an error when an invalid interface index is provided.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 006
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data |Expected Result | Notes |
* | :-------------: | ----------- | --------- | -------------- | ----- |
* | 01 | Provide an invalid interface index | ifIndex = ULONG_MAX | Error code indicating invalid interface index | The API should return an error |
*/

void test_l1_moca_hal_negative1_moca_SetIfConfig( void )
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_SetIfConfig...");

    ULONG ifIndex = ULONG_MAX;  // Invalid interface index

    UT_LOG("Invoking moca_SetIfConfig.");
    INT ret = moca_SetIfConfig(ifIndex, NULL);
    UT_LOG("Return: ret = %d", ret);
    if(ret == STATUS_FAILURE) {
        UT_LOG("Test Case Passed: Expected failure when setting MoCA configuration with NULL %lu", ifIndex);
    } else {
        UT_LOG("Test Case Failed: Unexpectedly succeeded in setting MoCA configuration with NULL %lu", ifIndex);
    }

    UT_ASSERT_EQUAL(ret, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_SetIfConfig...");
}

/**
 * @brief Test to verify the functionality of the moca_SetIfConfig API with valid interface index and configuration.
 *
 * This test case verifies the behavior of the moca_SetIfConfig API when called with a valid interface index and configuration. It ensures that the API correctly sets the MOCA interface configuration.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 007
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * 01 | Verify that the moca_SetIfConfig API correctly sets the MOCA interface configuration with valid input.
 *
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Verify that the API sets the MOCA interface configuration correctly. | ifIndex = 0, mocaConfig = {0} | Success | Should be successful |
 */
// if txpowerlimit is morethan 7 and less than -31, should return failure.
void test_l1_moca_hal_negative2_moca_SetIfConfig( void )
{
    UT_LOG("Entering test_l1_moca_hal_negative2_moca_SetIfConfig...");

    ULONG ifIndex = 0;
    moca_cfg_t *pmoca_config = (moca_cfg_t *)malloc(sizeof(moca_cfg_t));
    pmoca_config->TxPowerLimit = 8;
    
    if (pmoca_config == NULL) {
    // Handle malloc failure
    UT_LOG("Memory allocation failed");
    return -1;
    }
    
    UT_LOG("Invoking moca_SetIfConfig.");
    INT ret = moca_SetIfConfig(ifIndex, pmoca_config);
    UT_LOG("Return: ret = %d", ret);
    if(ret == STATUS_FAILURE) {
        UT_LOG("Test Case Passed: moca_SetIfConfig returned error");
    } else {
        UT_LOG("Test Case Failed: moca_SetIfConfig was successful");
    }
    UT_ASSERT_EQUAL(ret, STATUS_FAILURE);
    UT_LOG("Exiting test_l1_moca_hal_negative2_moca_SetIfConfig...");
}


/**
 * @brief Test case to validate the moca_IfGetExtCounter function with a valid ifIndex.
 *
 * This test case is designed to validate the moca_IfGetExtCounter function when it is invoked with a valid ifIndex.
 * It verifies whether the function returns STATUS_SUCCESS and updates the moca_mac_counters structure correctly.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 008
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoke moca_IfGetExtCounter function with valid ifIndex | ifIndex = 0, &counters | STATUS_SUCCESS | The function should execute successfully |
 */

void test_l1_moca_hal_positive1_moca_IfGetExtCounter(void) {
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_IfGetExtCounter...");

    ULONG ifIndex = 0;
    moca_mac_counters_t counters;
    UT_LOG("Invoking moca_IfGetExtCounter with ifIndex = %lu, pmoca_mac_counters = %p", ifIndex, &counters);
    INT status = moca_IfGetExtCounter(ifIndex, &counters);

    UT_LOG("Return Value: %d", status);

    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_IfGetExtCounter...");
}

/**
* @brief This test verifies that the moca_IfGetExtCounter function returns STATUS_FAILURE when a NULL pointer is provided for counters.
*
* The purpose of this test is to ensure that the moca_IfGetExtCounter function correctly handles the scenario where a NULL pointer is provided for counters.
* This test is part of the Basic (L1) test group and has a high priority, as it is critical to the functionality of the API.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 009
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Verify the behavior when a NULL pointer is provided for counters | ifIndex = 0, counters = NULL | STATUS_FAILURE | The function should return STATUS_FAILURE |
*/
void test_l1_moca_hal_negative1_moca_IfGetExtCounter(void) {
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_IfGetExtCounter...");

    ULONG ifIndex = 0;
    moca_mac_counters_t *counters = NULL;
    UT_LOG("Invoking moca_IfGetExtCounter with ifIndex = %lu, pmoca_mac_counters = NULL", ifIndex);
    INT status = moca_IfGetExtCounter(ifIndex, counters);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_IfGetExtCounter...");
}

/**
* @brief Test for the function moca_IfGetExtAggrCounter.
*
* This test validates the functionality of the moca_IfGetExtAggrCounter function. The function is responsible for retrieving the aggregate counters for a given MOCA interface.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 010
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Retrieve aggregate counters | ifIndex = 0 | The function should return STATUS_SUCCESS | - |
*/

void test_l1_moca_hal_positive1_moca_IfGetExtAggrCounter() {
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_IfGetExtAggrCounter...");

    // Test Input
    ULONG ifIndex = 0;
    moca_aggregate_counters_t pmoca_aggregate_counts;

    // Invoke the API
    UT_LOG("Invoking moca_IfGetExtAggrCounter");
    INT result = moca_IfGetExtAggrCounter(ifIndex, &pmoca_aggregate_counts);

    UT_LOG("Return Value: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, STATUS_SUCCESS);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_IfGetExtAggrCounter...");
}

/**
* @brief Test for the negative scenario of moca_IfGetExtAggrCounter() API.
*
* This test verifies the functionality of moca_IfGetExtAggrCounter() API when provided with invalid input parameters.
* The objective of this test is to ensure that the API returns STATUS_FAILURE when invalid input is provided.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 011
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | First set of conditions | ifIndex = 0, pmoca_aggregate_counts = NULL | STATUS_FAILURE | Should be unsuccessful with invalid input |
*/
void test_l1_moca_hal_negative1_moca_IfGetExtAggrCounter() {
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_IfGetExtAggrCounter...");

    // Test Input
    ULONG ifIndex = 0;
    moca_aggregate_counters_t* pmoca_aggregate_counts = NULL;

    // Invoke the API
    UT_LOG("Invoking moca_IfGetExtAggrCounter");
    INT result = moca_IfGetExtAggrCounter(ifIndex, pmoca_aggregate_counts);
    UT_LOG("Return Value: %d", result);
    // Check the return status
    UT_ASSERT_EQUAL(result, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_IfGetExtAggrCounter...");
}

/**
* @brief This function tests the functionality of the moca_GetMocaCPEs API.
*
* The objective of this test is to verify that the moca_GetMocaCPEs API returns the correct number of MoCA nodes and the correct return status when called with a valid interface index and memory allocation for output parameters.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 012
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke moca_GetMocaCPEs API with valid interface index and memory allocation for output parameter | ifIndex = 0, cpes = {} (empty array), num_cpes = 0 | The API returns STATUS_SUCCESS and num_cpes should be non-zero | Should be successful |
*/
void test_l1_moca_hal_positive1_moca_GetMocaCPEs(void) {
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_GetMocaCPEs...");

    ULONG ifIndex = 0;
    moca_cpe_t cpes[10];
    INT num_cpes = 0;
    UT_LOG("Invoking moca_GetMocaCPEs with valid interface index and memory allocation for output parameter.");
    INT status = moca_GetMocaCPEs(ifIndex, cpes, &num_cpes);

    UT_LOG("Return status: %d", status);
    UT_LOG("Number of MoCA Nodes: %d", num_cpes);

    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);
    CU_ASSERT_NOT_EQUAL_FATAL(num_cpes, 0);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_GetMocaCPEs...");
}

/**
* @brief This test case is to verify the behavior of the moca_GetMocaCPEs function when the output parameter is a null pointer.
*
* The purpose of this test is to check if the moca_GetMocaCPEs function handles the case where the output parameter is a null pointer correctly.
* This test is important to ensure that the API properly handles invalid or null input parameters and returns the expected status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 013
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoking moca_GetMocaCPEs with NULL pointer for output parameter. | ifIndex = 0, cpes = NULL, num_cpes = 0 | STATUS_FAILURE | Should return STATUS_FAILURE |
*/

void test_l1_moca_hal_negative1_moca_GetMocaCPEs(void) {
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_GetMocaCPEs...");

    ULONG ifIndex = 0;
    moca_cpe_t *cpes = NULL; // NULL pointer for output parameter
    INT num_cpes = 0;
    UT_LOG("Invoking moca_GetMocaCPEs with NULL pointer for output parameter.");
    INT status = moca_GetMocaCPEs(ifIndex, cpes, &num_cpes);

    UT_LOG("Return status: %d", status);

    UT_ASSERT_EQUAL(status, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_GetMocaCPEs...");
}

/**
 * @brief Positive test case to verify the functionality of moca_GetNumAssociatedDevices API.
 *
 * This test case checks the correctness of the moca_GetNumAssociatedDevices API by invoking it with valid input values and verifying the returned result and output value.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 014
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- |-------------- | ----- |
 * | 01 | Invoking moca_GetNumAssociatedDevices with valid ifIndex and valid pulCount | ifIndex = validValue, pulCount = allocateMemory() | result = STATUS_SUCCESS | Should be successful |
 */
void test_l1_moca_hal_positive1_moca_GetNumAssociatedDevices(void) {
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_GetNumAssociatedDevices...");

    ULONG ifIndex = 1;
    ULONG pulCount = 0;

    UT_LOG("Invoking moca_GetNumAssociatedDevices with valid ifIndex and valid pulCount...");
    INT result = moca_GetNumAssociatedDevices(ifIndex, &pulCount);

    UT_LOG("moca_GetNumAssociatedDevices returned: %d", result);
    UT_LOG("pulCount value: %d", pulCount);

    UT_ASSERT_EQUAL(result, STATUS_SUCCESS);
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_GetNumAssociatedDevices...");
}

/**
* @brief Test case to verify the negative scenario of the moca_GetNumAssociatedDevices function.
*
* This test case checks the behavior of the moca_GetNumAssociatedDevices function when invoked with a valid ifIndex and NULL pulCount parameter.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 015
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke moca_GetNumAssociatedDevices with valid ifIndex and NULL pulCount | ifIndex = 1 | Returns STATUS_FAILURE | N/A |
*/
void test_l1_moca_hal_negative1_moca_GetNumAssociatedDevices(void) {
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_GetNumAssociatedDevices...");

    ULONG ifIndex = 1;

    UT_LOG("Invoking moca_GetNumAssociatedDevices with valid ifIndex and NULL pulCount...");
    INT result = moca_GetNumAssociatedDevices(ifIndex, NULL);

    UT_LOG("moca_GetNumAssociatedDevices returned: %d", result);

    UT_ASSERT_EQUAL(result, STATUS_FAILURE);
    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_GetNumAssociatedDevices...");
}

/**
* @brief Test the function moca_GetFullMeshRates with positive input.
*
* This test case is used to ensure that the moca_GetFullMeshRates function returns the expected result and properly populates the deviceArray and count parameters.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 016
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
*
* **Test Procedure:**
* | Variation / Step    | Description                                        | Test Data                                              | Expected Result                      | Notes                 |
* | :----: | --------- | :------------------------------------------------- | ----------------------------------- | ----------- |
* | 01 | Invoke moca_GetFullMeshRates function | ifIndex = 0, deviceArray = NULL, count = 0 | STATUS_SUCCESS | Should be successful |
*/
void test_l1_moca_hal_positive1_moca_GetFullMeshRates(void) {
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_GetFullMeshRates...");
    
    //Input Parameters
    ULONG ifIndex = 1;
    moca_mesh_table_t *pDeviceArray;
    ULONG pulCount = 0;

    //Invoking moca_GetFullMeshRates with valid inputs
    int result = moca_GetFullMeshRates(ifIndex, pDeviceArray, &pulCount);
    UT_ASSERT_EQUAL(STATUS_SUCCESS, result);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_GetFullMeshRates...");
}

/**
* @brief This function tests the negative scenario of the moca_GetFullMeshRates API.
*
* This test case is designed to verify the behavior of moca_GetFullMeshRates API when it fails to retrieve the full mesh rates.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 017
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | The API fails to retrieve the full mesh rates | ifIndex = 0, deviceArray = NULL | STATUS_FAILURE | Should return a failure status |
*/

void test_l1_moca_hal_negative1_moca_GetFullMeshRates(void) {
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_GetFullMeshRates...");

    // Input parameters
    ULONG ifIndex = 1;
    moca_mesh_table_t *pDeviceArray = NULL;
    ULONG pulCount = 0;

    //Invoking moca_GetFullMeshRates with Invalid input
    int result = moca_GetFullMeshRates(ifIndex, pDeviceArray, &pulCount);
    UT_ASSERT_EQUAL(STATUS_FAILURE, result);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_GetFullMeshRates...");
}

/**
* @brief This test verifies the functionality of the moca_GetFlowStatistics API.
*
* The purpose of this test is to check if the moca_GetFlowStatistics API correctly retrieves flow statistics for a given ifIndex.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 018
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | -------------- | ----- |
* | 01 | Invoking moca_GetFlowStatistics with valid arguments | ifIndex = 0, cpes = valid memory location, num_cpes = valid memory location | ret = STATUS_SUCCESS, num_cpes != 0 | Should be successful |
*/
void test_l1_moca_hal_positive1_moca_GetFlowStatistics(void) {
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_GetFlowStatistics...");

    ULONG ifIndex = 0;
    moca_flow_table_t pDeviceArray;
    ULONG num_cpes;

    /* Test implementation */
    UT_LOG("Invoking moca_GetFlowStatistics with ifIndex = %lu, cpes = valid memory location, num_cpes = valid memory location");
    INT ret = moca_GetFlowStatistics(ifIndex, &pDeviceArray, &num_cpes);

    /* Test description */
    UT_LOG("Output: ret = %d", ret);

    /* Asserts */
    UT_ASSERT_EQUAL(ret, STATUS_SUCCESS);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_GetFlowStatistics...");
}



/**
* @brief This test case verifies the behavior of the moca_GetFlowStatistics function when the cpes parameter is NULL.
*
* The purpose of this test is to ensure that the moca_GetFlowStatistics function returns the expected status when the cpes parameter is NULL.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 019
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- | --------------- | ----- |
* | 01 | Invoking moca_GetFlowStatistics with ifIndex = 0, cpes = NULL, num_cpes = valid memory location | ifIndex = 0, cpes = NULL, num_cpes = valid memory location | ret = STATUS_FAILURE | Should return STATUS_FAILURE |
*/
void test_l1_moca_hal_negative1_moca_GetFlowStatistics(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_GetFlowStatistics...");

    ULONG ifIndex = 0;
    moca_flow_table_t *pDeviceArray = NULL;
    ULONG num_cpes;

    //Test implementation
    UT_LOG("Invoking moca_GetFlowStatistics with ifIndex = %lu, cpes = NULL, num_cpes = valid memory location");
    INT ret = moca_GetFlowStatistics(ifIndex, pDeviceArray, &num_cpes);

    //Test description
    UT_LOG("Output: ret = %d", ret);

    //Asserts
    UT_ASSERT_EQUAL(ret, STATUS_FAILURE);
    
    
    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_GetFlowStatistics...");
}

/**
 * @brief Unit test for the function moca_GetAssociatedDevices.
 *
 * This test validates the behavior of the moca_GetAssociatedDevices function by invoking it with a specific set of inputs.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 020
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * 1. | Variation / Step | Description | Test Data | Expected Result | Notes |
 * 2. | :----: | --------- | ---------- | -------------- | ----- |
 * 3. | 01 | Invoking moca_GetAssociatedDevices with valid ifIndex and ppdevice_array | ifIndex = 0, ppdevice_array = Valid memory location | STATUS_SUCCESS | Should return successfully |
 */
void test_l1_moca_hal_positive1_moca_GetAssociatedDevices(void) {
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_GetAssociatedDevices...");

    // Input
    ULONG ifIndex = 0;
    moca_associated_device_t **ppdevice_array;
    
    
    // Invoking API
    UT_LOG("Invoking moca_GetAssociatedDevices with ifIndex: %lu, ppdevice_array: Valid memory location", ifIndex);
    UT_LOG("Print 1");
    INT status = moca_GetAssociatedDevices(ifIndex, ppdevice_array);

    // Test Description
    UT_LOG("Return Status: %d", status);

    // Assertion
    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_GetAssociatedDevices...");
}

/**
* @brief Test to validate the failure scenario of the moca_GetAssociatedDevices function.
*
* This test validates the failure scenario of the moca_GetAssociatedDevices function, where the API returns a failure status. The test aims to ensure that the API handles the failure condition correctly and returns the expected status code.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 021
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data |Expected Result |Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoking moca_GetAssociatedDevices with NULL ppdevice_array | ifIndex = 0, ppdevice_array = NULL | STATUS_FAILURE | The API should return a failure status |
*/

void test_l1_moca_hal_negative1_moca_GetAssociatedDevices(void) {
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_GetAssociatedDevices...");

    // Input
    ULONG ifIndex = 0;
    moca_associated_device_t **ppdevice_array = NULL;

    UT_LOG("Invoking moca_GetAssociatedDevices with ifIndex: %lu, ppdevice_array: NULL", ifIndex);
    INT status = moca_GetAssociatedDevices(ifIndex, ppdevice_array);

    // Test Description
    UT_LOG("Return Status: %d", status);

    // Assertion
    UT_ASSERT_EQUAL(status, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_GetAssociatedDevices...");
}

/**
* @brief Test case to verify the functionality of the moca_cancelIfAca API.
*
* This test case verifies the moca_cancelIfAca API by invoking it with a valid interface index and checks if the API returns STATUS_SUCCESS.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 022
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke moca_cancelIfAca with valid interface index | interfaceIndex = 0 | STATUS_SUCCESS | Should be successful |
*/
void test_l1_moca_hal_positive1_moca_cancelIfAca(void)
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_cancelIfAca...");

    int interfaceIndex = 0;
    
    UT_LOG("Invoking moca_cancelIfAca with valid interface index: %d", interfaceIndex);
    int status = moca_cancelIfAca(interfaceIndex);

    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_cancelIfAca...");
}

/**
 * @brief This test case checks if the MOCA hardware is equipped.
 *
 * This test case verifies if the MOCA hardware is equipped by calling the moca_HardwareEquipped() API and checking the return value.
 *
 * **Test Group ID:** Basic (for L1): 01
 * **Test Case ID:** 023
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Check if MOCA hardware is equipped | - | TRUE | Should indicate that the MOCA hardware is equipped |
 * | 02 | Check if MOCA hardware is not equipped | - | FALSE | Should indicate that the MOCA hardware is not equipped |
 */
void test_l1_moca_hal_positive1_moca_HardwareEquipped( void )
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_HardwareEquipped...");

    // Action
    UT_LOG("Invoking moca_HardwareEquipped().");
    // Simulate access returning 0 (device exists)
    
    BOOL result = moca_HardwareEquipped();
    UT_LOG("Result: %d\n", result);
    if(access("/dev/bmoca0") == 0)
    {
    UT_ASSERT_EQUAL(TRUE, result);
    }
    
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_HardwareEquipped...");
}

/**
 * @brief This test case checks if the MOCA hardware is equipped.
 *
 * This test case verifies if the MOCA hardware is equipped by calling the moca_HardwareEquipped() API and checking the return value.
 *
 * **Test Group ID:** Basic (for L1): 01
 * **Test Case ID:** 024
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Check if MOCA hardware is equipped | - | TRUE | Should indicate that the MOCA hardware is equipped |
 * | 02 | Check if MOCA hardware is not equipped | - | FALSE | Should indicate that the MOCA hardware is not equipped |
 */
void test_l1_moca_hal_negative1_moca_HardwareEquipped( void )
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_HardwareEquipped...");

    // Assuming no hardware check (BRCM_LATTICE_IMPL not defined)
    BOOL result = moca_HardwareEquipped();
    UT_LOG("Result: %d\n", result);
    UT_ASSERT_EQUAL(FALSE, result);  // Assert that it returns FALSE
    
    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_HardwareEquipped...");
}


/**
 * @brief This test case is used to test the functionality of moca_getIfScmod API.
 *
 * The objective of this test is to ensure that the API returns the correct status and output values.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 025
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :--------------: | ----------- | --------- | --------------- | ----- |
 * |       01         | First set of conditions | interfaceIndex = 0 | The API should return STATUS_SUCCESS | Should be successful |
 */
void test_l1_moca_hal_positive1_moca_getIfScmod(void)
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_getIfScmod...");

    int interfaceIndex = 0;
    int numOfEntries = 0;
    moca_scmod_stat_t *pscmodStat;
    
    // Invoke the API
    UT_LOG("Invoking moca_getIfScmod.");
    int status = moca_getIfScmod(interfaceIndex, &numOfEntries, &pscmodStat);
    UT_LOG("Return Value: %d", status);
    // Validate the return status
    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);

    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_getIfScmod...");
}

/**
* @brief This test case is used to verify the functionality of the moca_getIfScmod API when the interface index is invalid.
*
* The objective of this test is to verify that the API returns the expected failure status when invoked with an invalid interface index.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 026
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Test with invalid interface index | interfaceIndex = 2, numOfEntries = 0, pscmodStat = NULL | The API should return the expected failure status | Should be unsuccessful |
*/
void test_l1_moca_hal_negative1_moca_getIfScmod(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_getIfScmod...");

    int interfaceIndex = 2;
    int numOfEntries = 0;
    moca_scmod_stat_t *pscmodStat = NULL;
    
    // Invoke the API
    UT_LOG("Invoking moca_getIfScmod.");
    int status = moca_getIfScmod(interfaceIndex, &numOfEntries, &pscmodStat);
    UT_LOG("Return Value: %d", status);
    // Validate the return status
    UT_ASSERT_EQUAL(status, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_getIfScmod...");
}

/**
* @brief This test case is used to verify the functionality of the moca_getIfScmod API when the interface index is invalid.
*
* The objective of this test is to verify that the API returns the expected failure status when invoked with an invalid interface index.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 027
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Test with invalid interface index | interfaceIndex = 2, numOfEntries = 0, pscmodStat = NULL | The API should return the expected failure status | Should be unsuccessful |
*/
void test_l1_moca_hal_negative2_moca_getIfScmod(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative2_moca_getIfScmod...");

    int interfaceIndex = 2;
    int numOfEntries = NULL;
    moca_scmod_stat_t *pscmodStat;
    
    // Invoke the API
    UT_LOG("Invoking moca_getIfScmod.");
    int status = moca_getIfScmod(interfaceIndex, &numOfEntries, &pscmodStat);
    UT_LOG("Return Value: %d", status);
    // Validate the return status
    UT_ASSERT_EQUAL(status, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative2_moca_getIfScmod...");
}

/**
* @brief Test the function moca_GetResetCount() to retrieve the reset count.
*
* The test is performed to ensure that the function moca_GetResetCount() correctly retrieves the reset count and returns STATUS_SUCCESS.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 028
* **Priority:** High
*
* **Pre-Conditions:** None
* **Dependencies:** None
* **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
*
* **Test Procedure:**
* | Variation / Step | Description | Test Data | Expected Result | Notes |
* | :----: | --------- | ---------- |-------------- | ----- |
* | 01 | Invoke moca_GetResetCount() to retrieve the reset count. | resetcnt = 0 | Function returns STATUS_SUCCESS. | The reset count is retrieved successfully. |
*/
void test_l1_moca_hal_positive1_moca_GetResetCount(void)
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_GetResetCount...");
    
    ULONG resetcnt = 3;
    
    UT_LOG("Invoking moca_GetResetCount with resetcnt=%lu", resetcnt);
    INT status = moca_GetResetCount(&resetcnt);
    
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);
    
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_GetResetCount...");
}

/**
 * @brief Test the moca_GetResetCount function with NULL resetcnt parameter.
 *
 * This test case verifies that the moca_GetResetCount function returns STATUS_FAILURE when resetcnt is NULL.
 *
 * **Test Group ID:** Basic: 01
 * **Test Case ID:** 029
 * **Priority:** High
 *
 * **Pre-Conditions:** None
 * **Dependencies:** None
 * **User Interaction:** If user chose to run the test in interactive mode, then the test case has to be selected via console.
 *
 * **Test Procedure:**
 * | Variation / Step | Description | Test Data | Expected Result | Notes |
 * | :----: | --------- | ---------- | -------------- | ----- |
 * | 01 | Invoke moca_GetResetCount function with resetcnt=NULL | resetcnt = NULL | STATUS_FAILURE | Should return STATUS_FAILURE |
 */

void test_l1_moca_hal_negative1_moca_GetResetCount(void) 
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_GetResetCount...");

    ULONG *resetcnt = NULL;
    
    UT_LOG("Invoking moca_GetResetCount with resetcnt=NULL");
    INT status = moca_GetResetCount(resetcnt);

    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_FAILURE);

    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_GetResetCount...");
}

/**
* @brief This test is to verify the functionality of the moca_IfGetDynamicInfo API when the API returns a success status.
*
* This test case is designed to check the behavior of the moca_IfGetDynamicInfo API when it returns a success status.
* It is essential to ensure that the API correctly handles the success scenario and returns the expected status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 030
* **Priority:** High
*
* **Pre-Conditions:** Proper initialization of the moca_dynamic_info_t structure.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                       | Test Data                | Expected Result   | Notes                                             |
* | :----:           | ---------                                         | ----------               |--------------     | -----                                             |
* | 01               | Invoking moca_IfGetDynamicInfo API with valid parameters | dynamic_info pointer   | STATUS_SUCCESS    | The API should return a success status.           |
*/
void test_l1_moca_hal_positive1_moca_IfGetDynamicInfo(void)
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_IfGetDynamicInfo...");
    
    ULONG ifIndex =0;
    moca_dynamic_info_t dynamic_info;
    
    UT_LOG("Invoking moca_IfGetDynamicInfo");
    INT status = moca_IfGetDynamicInfo(ifIndex, &dynamic_info);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);
    
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_IfGetDynamicInfo...");
}

/**
* @brief This test is to verify the functionality of the moca_IfGetDynamicInfo API when invoked with a NULL pointer for dynamic info.
*
* This test case is designed to check the behavior of the moca_IfGetDynamicInfo API when a NULL pointer is provided for dynamic info. The purpose is to ensure that the API correctly handles erroneous inputs and returns the expected failure status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 031
* **Priority:** High
*
* **Pre-Conditions:** None.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                     | Test Data        | Expected Result   | Notes                                                                     |
* | :----:           | ---------                                                       | ----------       |--------------     | -----                                                                     |
* | 01               | Invoking moca_IfGetDynamicInfo API with a NULL pointer for dynamic info | NULL pointer  | STATUS_FAILURE    | The API should detect the erroneous input and return a failure status.    |
*/
void test_l1_moca_hal_negative1_moca_IfGetDynamicInfo(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_IfGetDynamicInfo...");
    
    ULONG ifIndex=0;
    
    UT_LOG("Invoking moca_IfGetDynamicInfo");
    INT status = moca_IfGetDynamicInfo(ifIndex, NULL);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_FAILURE);
    
    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_IfGetDynamicInfo...");
}

/**
* @brief This test is to verify the functionality of the moca_IfGetStaticInfo API when the API returns a success status.
*
* This test case is designed to check the behavior of the moca_IfGetStaticInfo API when it returns a success status.
* The aim is to ensure that the API correctly retrieves static information and returns the expected success status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 032
* **Priority:** High
*
* **Pre-Conditions:** Proper initialization of the moca_static_info_t structure.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                           | Test Data                   | Expected Result   | Notes                                                                        |
* | :----:           | ---------                                                             | ----------                  |--------------     | -----                                                                        |
* | 01               | Invoking moca_IfGetStaticInfo API with valid parameters               | static_info pointer         | STATUS_SUCCESS    | The API should correctly retrieve the static information and return a success status. |
*/
void test_l1_moca_hal_positive1_moca_IfGetStaticInfo(void)
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_IfGetStaticInfo...");
    
    ULONG ifIndex=0;
    moca_static_info_t static_info;
    
    UT_LOG("Invoking moca_IfGetStaticInfo");
    INT status = moca_IfGetStaticInfo(ifIndex, &static_info);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);
    
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_IfGetStaticInfo...");
}

/**
* @brief This test is to verify the functionality of the moca_IfGetStaticInfo API when invoked with a NULL pointer for static info.
*
* This test case is designed to check the behavior of the moca_IfGetStaticInfo API when a NULL pointer is provided for static info. The objective is to ascertain that the API correctly handles erroneous inputs and returns the expected failure status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 033
* **Priority:** High
*
* **Pre-Conditions:** None.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                              | Test Data         | Expected Result   | Notes                                                                         |
* | :----:           | ---------                                                                | ----------        |--------------     | -----                                                                         |
* | 01               | Invoking moca_IfGetStaticInfo API with a NULL pointer for static info    | NULL pointer      | STATUS_FAILURE    | The API should recognize the erroneous input and return a failure status.      |
*/
void test_l1_moca_hal_negative1_moca_IfGetStaticInfo(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_IfGetStaticInfo...");
    
    ULONG ifIndex=0;
    
    UT_LOG("Invoking moca_IfGetStaticInfo");
    INT status = moca_IfGetStaticInfo(ifIndex, NULL);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_FAILURE);
    
    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_IfGetStaticInfo...");
}

/**
* @brief This test aims to verify the functionality of the moca_setIfAcaConfig API when provided with valid configuration parameters.
*
* This test case is designed to check the behavior of the moca_setIfAcaConfig API when given valid configuration values, particularly those at the lowest bounds or initial settings. The goal is to ensure that the API correctly sets the ACA (Aggregated Channel Assignment) configuration and returns the expected success status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 034
* **Priority:** High
*
* **Pre-Conditions:** Proper initialization of the moca_aca_cfg_t structure.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                                               | Test Data                              | Expected Result                             | Notes                                                                                     |
* | :----:           | ---------                                                                                 | ----------                             |--------------                               | -----                                                                                     |
* | 01               | Set up the ACA configuration with valid parameters, particularly edge or initial values. | Configuration settings as in the test  | None                                       | Setting up known valid configurations for the API.                                        |
* | 02               | Invoke the moca_setIfAcaConfig API with the previously set configuration.                | `config` as input                      | STATUS_SUCCESS                             | The API should accept the valid configuration and return a success status.               |
*/
void test_l1_moca_hal_positive1_moca_setIfAcaConfig(void) {
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_setIfAcaConfig...");
    
    int interfaceIndex = 0;
    moca_aca_cfg_t config;

    UT_LOG("Invoking moca_setIfAcaConfig");
    int status = moca_setIfAcaConfig(interfaceIndex, config);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);
    
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_setIfAcaConfig...");
}

/**
* @brief This test aims to verify the successful retrieval of ACA configurations using the moca_getIfAcaConfig API.
*
* This test case is designed to check the behavior of the moca_getIfAcaConfig API when invoked with valid parameters. The objective is to ensure that the API can successfully retrieve the ACA (Aggregated Channel Assignment) configuration and return the expected success status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 035
* **Priority:** High
*
* **Pre-Conditions:** The MoCA interface should be properly initialized and have a set ACA configuration.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                               | Test Data                             | Expected Result                             | Notes                                                                                        |
* | :----:           | ---------                                                                 | ----------                            |--------------                               | -----                                                                                        |
* | 01               | Invoke the moca_getIfAcaConfig API to retrieve the ACA configuration.    | `0` as interface index, `&config`    | STATUS_SUCCESS                             | The API should fetch the ACA configuration and return a success status.                     |
* | 02               | Optionally, assert and validate specific values in the retrieved config.  | Values within `config`                | Values should match the expected settings.  | Additional assertions can be added to ensure the correctness of retrieved configuration.    |
*/
void test_l1_moca_hal_positive1_moca_getIfAcaConfig(void)
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_getIfAcaConfig...");
    
    int interfaceIndex = 0;
    moca_aca_cfg_t config;
    
    UT_LOG("Invoking moca_getIfAcaConfig");
    int status = moca_getIfAcaConfig(interfaceIndex, &config);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);
    
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_getIfAcaConfig...");
}

/**
* @brief This test aims to verify the behavior of the moca_getIfAcaConfig API when provided with an invalid interface index.
*
* This test case is designed to check the behavior of the moca_getIfAcaConfig API when given a negative value (`-1`) as the interface index. Such a value should be considered invalid. The primary goal is to ensure that the API recognizes this inappropriate input and returns the expected failure status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 036
* **Priority:** High
*
* **Pre-Conditions:** The MoCA interface should be properly initialized.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                                   | Test Data                         | Expected Result                             | Notes                                                                                      |
* | :----:           | ---------                                                                     | ----------                        |--------------                               | -----                                                                                      |
* | 01               | Invoke the moca_getIfAcaConfig API with an invalid interface index.          | `-1` as interface index           | STATUS_FAILURE                             | The API should detect the invalid interface index and return a failure status.          |
*/
void test_l1_moca_hal_negative1_moca_getIfAcaConfig(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_getIfAcaConfig...");
    
    int interfaceIndex = 0;
    
    UT_LOG("Invoking moca_getIfAcaConfig");
    int status = moca_getIfAcaConfig(interfaceIndex, NULL);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_FAILURE);
    
    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_getIfAcaConfig...");
}

/**
* @brief This test aims to verify the successful retrieval of ACA status using the moca_getIfAcaStatus API.
*
* This test case is designed to check the behavior of the moca_getIfAcaStatus API when invoked with valid parameters. The primary goal is to ensure that the API can successfully retrieve the ACA (Aggregated Channel Assignment) status and return the expected success status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 037
* **Priority:** High
*
* **Pre-Conditions:** The MoCA interface should be properly initialized and have a set ACA status.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                                          | Test Data                           | Expected Result                             | Notes                                                                                      |
* | :----:           | ---------                                                                            | ----------                          |--------------                               | -----                                                                                      |
* | 01               | Invoke the moca_getIfAcaStatus API to retrieve the ACA status.                      | `0` as interface index, `&acaStatus` | STATUS_SUCCESS                             | The API should fetch the ACA status and return a success status.                         |
* | 02               | Optionally, assert and validate specific values in the retrieved ACA status.         | Values within `acaStatus`            | Values should match the expected settings.  | Additional assertions can be added to ensure the correctness of the retrieved status.    |
*/
void test_l1_moca_hal_positive1_moca_getIfAcaStatus(void)
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_getIfAcaStatus...");
    
    moca_aca_stat_t acaStatus;
    
    UT_LOG("Invoking moca_getIfAcaStatus");
    int status = moca_getIfAcaStatus(0, &acaStatus);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_SUCCESS);
    // Here you can add more assertions to validate specific values in acaStatus if necessary
    
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_getIfAcaStatus...");
}

/**
* @brief This test aims to verify the behavior of the moca_getIfAcaStatus API when provided with an invalid interface index.
*
* This test case is designed to check the behavior of the moca_getIfAcaStatus API when given a negative value (`-1`) as the interface index. Such a value should be considered invalid. The primary objective is to ensure that the API recognizes this inappropriate input and returns the expected failure status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 038
* **Priority:** High
*
* **Pre-Conditions:** The MoCA interface should be properly initialized.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                                        | Test Data                      | Expected Result                             | Notes                                                                                       |
* | :----:           | ---------                                                                          | ----------                     |--------------                               | -----                                                                                       |
* | 01               | Invoke the moca_getIfAcaStatus API with an invalid interface index.                | `-1` as interface index        | STATUS_FAILURE                             | The API should detect the invalid interface index and return a failure status.            |
*/
void test_l1_moca_hal_negative1_moca_getIfAcaStatus(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_getIfAcaStatus...");
    
    UT_LOG("Invoking moca_moca_getIfAcaStatus");
    int status = moca_getIfAcaStatus(0, NULL);
    UT_LOG("Return Value: %d", status);
    UT_ASSERT_EQUAL(status, STATUS_FAILURE);
    
    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_getIfAcaStatus...");
}

/**
* @brief This test is to verify the behavior of the moca_FreqMaskToValue API when provided with a NULL frequency mask.
*
* This test case is designed to check the response of the moca_FreqMaskToValue API when provided with a NULL frequency mask. The main objective is to ensure that the API identifies this inappropriate input and returns the expected failure status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 039
* **Priority:** High
*
* **Pre-Conditions:** The MoCA interface should be properly initialized.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                                                   | Test Data    | Expected Result           | Notes                                                                           |
* | :----:           | ---------                                                                                     | ----------   |--------------             | -----                                                                           |
* | 01               | Invoke the moca_FreqMaskToValue API with a NULL frequency mask.                              | NULL mask    | STATUS_FAILURE            | The API should detect the NULL mask and return the expected failure status.     |
*/
// Test when the input mask is valid (16 characters)
void test_l1_moca_hal_positive1_moca_FreqMaskToValue(void)
{
    UT_LOG("Entering test_l1_moca_hal_positive1_moca_FreqMaskToValue");
    
    UCHAR mask[] = "0000000100000001";  // Valid 16-character mask
    
    //Invoking moca_FreqMaskToValue for ReturnsLastOperFreq WhenValidMask
    int result = moca_FreqMaskToValue(mask);
    UT_LOG("Result: %d\n", result);
    if(result > 0)
    {
    UT_LOG("STATUS_SUCCESS\n");  // Print "STATUS_SUCCESS" when result is non-zero
    }
    else
    {
    UT_ASSERT_EQUAL(result, STATUS_FAILURE);  // Ensure correct comparison with expected failure status
    }
    UT_LOG("Exiting test_l1_moca_hal_positive1_moca_FreqMaskToValue");
}

/**
* @brief This test is to verify the behavior of the moca_FreqMaskToValue API when provided with a NULL frequency mask.
*
* This test case is designed to check the response of the moca_FreqMaskToValue API when provided with a NULL frequency mask. The main objective is to ensure that the API identifies this inappropriate input and returns the expected failure status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 040
* **Priority:** High
*
* **Pre-Conditions:** The MoCA interface should be properly initialized.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                                                   | Test Data    | Expected Result           | Notes                                                                           |
* | :----:           | ---------                                                                                     | ----------   |--------------             | -----                                                                           |
* | 01               | Invoke the moca_FreqMaskToValue API with a NULL frequency mask.                              | NULL mask    | STATUS_FAILURE            | The API should detect the NULL mask and return the expected failure status.     |
*/
void test_l1_moca_hal_negative1_moca_FreqMaskToValue(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative1_moca_FreqMaskToValue");
    
    UCHAR *mask = NULL;
    
    //Invoking moca_FreqMaskToValue for ReturnsFailure WhenMaskIsNull
    int result = moca_FreqMaskToValue(mask);
    UT_ASSERT_EQUAL(STATUS_FAILURE, result); // Assert that it returns STATUS_FAILURE
    
    UT_LOG("Exiting test_l1_moca_hal_negative1_moca_FreqMaskToValue");
}

/**
* @brief This test is to verify the behavior of the moca_FreqMaskToValue API when provided with a NULL frequency mask.
*
* This test case is designed to check the response of the moca_FreqMaskToValue API when provided with a NULL frequency mask. The main objective is to ensure that the API identifies this inappropriate input and returns the expected failure status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 041
* **Priority:** High
*
* **Pre-Conditions:** The MoCA interface should be properly initialized.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                                                   | Test Data    | Expected Result           | Notes                                                                           |
* | :----:           | ---------                                                                                     | ----------   |--------------             | -----                                                                           |
* | 01               | Invoke the moca_FreqMaskToValue API with a NULL frequency mask.                              | NULL mask    | STATUS_FAILURE            | The API should detect the NULL mask and return the expected failure status.     |
*/
void test_l1_moca_hal_negative2_moca_FreqMaskToValue(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative2_moca_FreqMaskToValue");
    
    UCHAR mask[] = "1234567";  // Less than 16 characters
    
    //Invoking moca_FreqMaskToValue for ReturnsFailure_WhenMaskLengthLessThan16
    int result = moca_FreqMaskToValue(mask);
    UT_ASSERT_EQUAL(STATUS_FAILURE, result); // Assert that it returns STATUS_FAILURE
    
    UT_LOG("Exiting test_l1_moca_hal_negative2_moca_FreqMaskToValue");
}

/**
* @brief This test is to verify the behavior of the moca_FreqMaskToValue API when provided with a NULL frequency mask.
*
* This test case is designed to check the response of the moca_FreqMaskToValue API when provided with a NULL frequency mask. The main objective is to ensure that the API identifies this inappropriate input and returns the expected failure status.
*
* **Test Group ID:** Basic: 01
* **Test Case ID:** 042
* **Priority:** High
*
* **Pre-Conditions:** The MoCA interface should be properly initialized.
* **Dependencies:** None
* **User Interaction:** If the user chooses to run the test in interactive mode, the test case must be selected via the console.
*
* **Test Procedure:**
* | Variation / Step | Description                                                                                   | Test Data    | Expected Result           | Notes                                                                           |
* | :----:           | ---------                                                                                     | ----------   |--------------             | -----                                                                           |
* | 01               | Invoke the moca_FreqMaskToValue API with a NULL frequency mask.                              | NULL mask    | STATUS_FAILURE            | The API should detect the NULL mask and return the expected failure status.     |
*/
void test_l1_moca_hal_negative3_moca_FreqMaskToValue(void)
{
    UT_LOG("Entering test_l1_moca_hal_negative3_moca_FreqMaskToValue");
    
    UCHAR mask[] = "12345678901234567890";  // More than 16 characters
    
    //Invoking moca_FreqMaskToValue for ReturnsFailure WhenMaskLengthGreaterThan16
    int result = moca_FreqMaskToValue(mask);
    UT_ASSERT_EQUAL(STATUS_FAILURE, result); // Assert that it returns STATUS_FAILURE
    
    UT_LOG("Exiting test_l1_moca_hal_negative3_moca_FreqMaskToValue");
}



static UT_test_suite_t * pSuite = NULL;

/**
 * @brief Register the main tests for this module
 *
 * @return int - 0 on success, otherwise failure
 */
int test_moca_hal_register(void)
{
    // Create the test suite
    pSuite = UT_add_suite("[L1 moca_hal]", init_moca_hal_init, NULL);
    if (pSuite == NULL) {
        return -1;
    }
    // List of test function names and strings
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_GetIfConfig", test_l1_moca_hal_positive1_moca_GetIfConfig);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_GetIfConfig", test_l1_moca_hal_negative1_moca_GetIfConfig);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_IfGetStats", test_l1_moca_hal_positive1_moca_IfGetStats); 
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_IfGetStats", test_l1_moca_hal_negative1_moca_IfGetStats);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_SetIfConfig", test_l1_moca_hal_positive1_moca_SetIfConfig);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_SetIfConfig", test_l1_moca_hal_negative1_moca_SetIfConfig);
    UT_add_test(pSuite, "l1_moca_hal_negative2_moca_SetIfConfig", test_l1_moca_hal_negative2_moca_SetIfConfig);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_IfGetExtCounter", test_l1_moca_hal_positive1_moca_IfGetExtCounter);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_IfGetExtCounter", test_l1_moca_hal_negative1_moca_IfGetExtCounter);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_IfGetExtAggrCounter", test_l1_moca_hal_positive1_moca_IfGetExtAggrCounter);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_IfGetExtAggrCounter", test_l1_moca_hal_negative1_moca_IfGetExtAggrCounter);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_GetMocaCPEs", test_l1_moca_hal_positive1_moca_GetMocaCPEs);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_GetMocaCPEs", test_l1_moca_hal_negative1_moca_GetMocaCPEs);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_GetNumAssociatedDevices", test_l1_moca_hal_positive1_moca_GetNumAssociatedDevices);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_GetNumAssociatedDevices", test_l1_moca_hal_negative1_moca_GetNumAssociatedDevices);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_GetFullMeshRates", test_l1_moca_hal_positive1_moca_GetFullMeshRates);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_GetFullMeshRates", test_l1_moca_hal_negative1_moca_GetFullMeshRates);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_GetFlowStatistics", test_l1_moca_hal_positive1_moca_GetFlowStatistics);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_GetFlowStatistics", test_l1_moca_hal_negative1_moca_GetFlowStatistics);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_GetAssociatedDevices", test_l1_moca_hal_positive1_moca_GetAssociatedDevices);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_GetAssociatedDevices", test_l1_moca_hal_negative1_moca_GetAssociatedDevices);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_cancelIfAca", test_l1_moca_hal_positive1_moca_cancelIfAca);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_HardwareEquipped", test_l1_moca_hal_positive1_moca_HardwareEquipped);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_HardwareEquipped", test_l1_moca_hal_negative1_moca_HardwareEquipped);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_getIfScmod", test_l1_moca_hal_positive1_moca_getIfScmod);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_getIfScmod", test_l1_moca_hal_negative1_moca_getIfScmod);
    UT_add_test(pSuite, "l1_moca_hal_negative2_moca_getIfScmod", test_l1_moca_hal_negative2_moca_getIfScmod);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_GetResetCount", test_l1_moca_hal_positive1_moca_GetResetCount);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_GetResetCount", test_l1_moca_hal_negative1_moca_GetResetCount);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_IfGetDynamicInfo", test_l1_moca_hal_positive1_moca_IfGetDynamicInfo);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_IfGetDynamicInfo", test_l1_moca_hal_negative1_moca_IfGetDynamicInfo);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_IfGetStaticInfo", test_l1_moca_hal_positive1_moca_IfGetStaticInfo);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_IfGetStaticInfo", test_l1_moca_hal_negative1_moca_IfGetStaticInfo);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_setIfAcaConfig", test_l1_moca_hal_positive1_moca_setIfAcaConfig);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_getIfAcaConfig", test_l1_moca_hal_positive1_moca_getIfAcaConfig);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_getIfAcaConfig", test_l1_moca_hal_negative1_moca_getIfAcaConfig);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_getIfAcaStatus", test_l1_moca_hal_positive1_moca_getIfAcaStatus);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_getIfAcaStatus", test_l1_moca_hal_negative1_moca_getIfAcaStatus);
    UT_add_test(pSuite, "l1_moca_hal_positive1_moca_FreqMaskToValue", test_l1_moca_hal_positive1_moca_FreqMaskToValue);
    UT_add_test(pSuite, "l1_moca_hal_negative1_moca_FreqMaskToValue", test_l1_moca_hal_negative1_moca_FreqMaskToValue);
    UT_add_test(pSuite, "l1_moca_hal_negative2_moca_FreqMaskToValue", test_l1_moca_hal_negative2_moca_FreqMaskToValue);
    UT_add_test(pSuite, "l1_moca_hal_negative3_moca_FreqMaskToValue", test_l1_moca_hal_negative3_moca_FreqMaskToValue);

    return 0;
}

