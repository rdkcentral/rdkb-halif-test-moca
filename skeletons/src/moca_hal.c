#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "moca_hal.h"


void moca_associatedDevice_callback_register(moca_associatedDevice_callback callback_proc)
{
  /*TODO: Implement Me!*/
  (void)callback_proc;
}

INT moca_GetIfConfig(ULONG ifIndex, moca_cfg_t* pmoca_config)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pmoca_config;
  return (INT)0;
}

INT moca_SetIfConfig(ULONG ifIndex, moca_cfg_t* pmoca_config)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pmoca_config;
  return (INT)0;
}

INT moca_IfGetDynamicInfo(ULONG ifIndex, moca_dynamic_info_t* pmoca_dynamic_info)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pmoca_dynamic_info;
  return (INT)0;
}

INT moca_IfGetStaticInfo(ULONG ifIndex, moca_static_info_t* pmoca_static_info)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pmoca_static_info;
  return (INT)0;
}

INT moca_IfGetStats(ULONG ifIndex, moca_stats_t* pmoca_stats)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pmoca_stats;
  return (INT)0;
}

INT moca_GetNumAssociatedDevices(ULONG ifIndex, ULONG* pulCount)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pulCount;
  return (INT)0;
}

INT moca_IfGetExtCounter(ULONG ifIndex, moca_mac_counters_t* pmoca_mac_counters)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pmoca_mac_counters;
  return (INT)0;
}

INT moca_IfGetExtAggrCounter(ULONG ifIndex, moca_aggregate_counters_t* pmoca_aggregate_counts)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pmoca_aggregate_counts;
  return (INT)0;
}

INT moca_GetMocaCPEs(ULONG ifIndex, moca_cpe_t* cpes, INT* pnum_cpes)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)cpes;
  (void)pnum_cpes;
  return (INT)0;
}

INT moca_GetAssociatedDevices(ULONG ifIndex, moca_associated_device_t** ppdevice_array)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)ppdevice_array;
  return (INT)0;
}

INT moca_FreqMaskToValue(UCHAR* mask)
{
  /*TODO: Implement Me!*/
  (void)mask;
  return (INT)0;
}

BOOL moca_HardwareEquipped(void)
{
  /*TODO: Implement Me!*/
  return (BOOL)0;
}

INT moca_GetFullMeshRates(ULONG ifIndex, moca_mesh_table_t* pDeviceArray, ULONG* pulCount)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pDeviceArray;
  (void)pulCount;
  return (INT)0;
}

INT moca_GetFlowStatistics(ULONG ifIndex, moca_flow_table_t* pDeviceArray, ULONG* pulCount)
{
  /*TODO: Implement Me!*/
  (void)ifIndex;
  (void)pDeviceArray;
  (void)pulCount;
  return (INT)0;
}

INT moca_GetResetCount(ULONG* resetcnt)
{
  /*TODO: Implement Me!*/
  (void)resetcnt;
  return (INT)0;
}

int moca_setIfAcaConfig(int interfaceIndex, moca_aca_cfg_t acaCfg)
{
  /*TODO: Implement Me!*/
  (void)interfaceIndex;
  (void)acaCfg;
  return (int)0;
}

int moca_getIfAcaConfig(int interfaceIndex, moca_aca_cfg_t* acaCfg)
{
  /*TODO: Implement Me!*/
  (void)interfaceIndex;
  (void)acaCfg;
  return (int)0;
}

int moca_cancelIfAca(int interfaceIndex)
{
  /*TODO: Implement Me!*/
  (void)interfaceIndex;
  return (int)0;
}

int moca_getIfAcaStatus(int interfaceIndex, moca_aca_stat_t* pacaStat)
{
  /*TODO: Implement Me!*/
  (void)interfaceIndex;
  (void)pacaStat;
  return (int)0;
}

int moca_getIfScmod(int interfaceIndex, int* pnumOfEntries, moca_scmod_stat_t** ppscmodStat)
{
  /*TODO: Implement Me!*/
  (void)interfaceIndex;
  (void)pnumOfEntries;
  (void)ppscmodStat;
  return (int)0;
}

