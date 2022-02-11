bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
V_4 = F_2 ( V_5 , 0 ,
V_6 , V_7 ) ;
F_3 ( V_2 -> V_8 , V_4 ,
( V_9 | ( V_10 & 0xffffffff ) ) ) ;
V_4 = F_2 ( V_5 , 0 ,
V_11 , V_12 ) ;
V_3 = F_4 ( V_2 -> V_8 , V_4 ) ;
if ( V_3 & V_13 )
return true ;
return false ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_4 ;
if ( ! F_1 ( V_2 ) )
return - V_14 ;
V_4 = F_2 ( V_15 , 0 ,
V_16 , V_17 ) ;
F_6 ( V_2 , V_4 ,
0 , V_18 ) ;
return F_4 ( V_2 -> V_8 , V_4 ) ;
}
int F_7 ( struct V_1 * V_2 ,
T_2 V_19 )
{
T_1 V_4 ;
if ( ! F_1 ( V_2 ) )
return - V_14 ;
V_4 = F_2 ( V_15 , 0 ,
V_20 , V_21 ) ;
F_3 ( V_2 -> V_8 , V_4 , V_19 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 * V_22 )
{
T_1 V_4 ;
V_4 = F_2 ( V_15 , 0 ,
V_23 , V_24 ) ;
* V_22 = F_4 ( V_2 -> V_8 , V_4 ) ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , T_2 V_19 )
{
T_1 V_4 ;
F_5 ( V_2 ) ;
V_4 = F_2 ( V_15 , 0 ,
V_16 , V_17 ) ;
F_3 ( V_2 -> V_8 , V_4 , 0 ) ;
F_7 ( V_2 , V_19 ) ;
if ( F_5 ( V_2 ) == 0 )
F_10 ( L_1 , V_19 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
T_2 V_19 , T_1 V_25 )
{
T_1 V_4 ;
F_5 ( V_2 ) ;
V_4 = F_2 ( V_15 , 0 ,
V_16 , V_17 ) ;
F_3 ( V_2 -> V_8 , V_4 , 0 ) ;
V_4 = F_2 ( V_15 , 0 ,
V_23 , V_24 ) ;
F_3 ( V_2 -> V_8 , V_4 , V_25 ) ;
F_7 ( V_2 , V_19 ) ;
if ( F_5 ( V_2 ) == 0 )
F_10 ( L_1 , V_19 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 ,
T_3 * V_26 , T_4 V_27 )
{
struct V_28 * V_29 =
(struct V_28 * ) ( V_2 -> V_30 ) ;
F_13 (table_id < MAX_SMU_TABLE,
L_2 , return -EINVAL;) ;
F_13 (priv->smu_tables.entry[table_id].version != 0 ,
L_3 , return -EINVAL;) ;
F_13 (priv->smu_tables.entry[table_id].size != 0 ,
L_4 , return -EINVAL;) ;
F_13 (rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrHigh,
priv->smu_tables.entry[table_id].table_addr_high) == 0 ,
L_5 , return -EINVAL;) ;
F_13 (rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrLow,
priv->smu_tables.entry[table_id].table_addr_low) == 0 ,
L_6 ,
return -EINVAL;) ;
F_13 (rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_TransferTableSmu2Dram,
priv->smu_tables.entry[table_id].table_id) == 0 ,
L_7 ,
return -EINVAL;) ;
memcpy ( V_26 , V_29 -> V_31 . V_32 [ V_27 ] . V_26 ,
V_29 -> V_31 . V_32 [ V_27 ] . V_33 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
T_3 * V_26 , T_4 V_27 )
{
struct V_28 * V_29 =
(struct V_28 * ) ( V_2 -> V_30 ) ;
F_13 (table_id < MAX_SMU_TABLE,
L_2 , return -EINVAL;) ;
F_13 (priv->smu_tables.entry[table_id].version != 0 ,
L_3 , return -EINVAL;) ;
F_13 (priv->smu_tables.entry[table_id].size != 0 ,
L_4 , return -EINVAL;) ;
memcpy ( V_29 -> V_31 . V_32 [ V_27 ] . V_26 , V_26 ,
V_29 -> V_31 . V_32 [ V_27 ] . V_33 ) ;
F_13 (rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrHigh,
priv->smu_tables.entry[table_id].table_addr_high) == 0 ,
L_8 ,
return -EINVAL;) ;
F_13 (rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrLow,
priv->smu_tables.entry[table_id].table_addr_low) == 0 ,
L_9 ,
return -EINVAL;) ;
F_13 (rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_TransferTableDram2Smu,
priv->smu_tables.entry[table_id].table_id) == 0 ,
L_10 ,
return -EINVAL;) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
T_1 V_34 ;
F_13 (!rv_send_msg_to_smc(smumgr,
PPSMC_MSG_GetDriverIfVersion),
L_11 ,
return -EINVAL) ;
F_13 (!rv_read_arg_from_smc(smumgr,
&smc_driver_if_version),
L_12 ,
return -EINVAL) ;
if ( V_34 != V_35 )
return - V_14 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
F_13 (!rv_send_msg_to_smc(smumgr,
PPSMC_MSG_PowerUpSdma),
L_13 ,
return -EINVAL) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_13 (!rv_send_msg_to_smc(smumgr,
PPSMC_MSG_PowerDownSdma),
L_14 ,
return -EINVAL) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_13 (!rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_PowerUpVcn, 0),
L_15 ,
return -EINVAL) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
F_13 (!rv_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_PowerDownVcn, 0),
L_16 ,
return -EINVAL) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
(struct V_28 * ) ( V_2 -> V_30 ) ;
if ( V_29 ) {
F_17 ( V_2 ) ;
F_19 ( V_2 ) ;
F_21 ( V_2 -> V_8 ,
V_29 -> V_31 . V_32 [ V_36 ] . V_37 ) ;
F_21 ( V_2 -> V_8 ,
V_29 -> V_31 . V_32 [ V_38 ] . V_37 ) ;
F_22 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
if ( F_15 ( V_2 ) )
return - V_14 ;
if ( F_16 ( V_2 ) )
return - V_14 ;
if ( F_18 ( V_2 ) )
return - V_14 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
T_5 V_39 ;
void * V_40 = NULL ;
unsigned long V_37 ;
V_29 = F_25 ( sizeof( struct V_28 ) , V_41 ) ;
if ( ! V_29 )
return - V_42 ;
V_2 -> V_30 = V_29 ;
F_26 ( V_2 -> V_8 ,
sizeof( V_43 ) ,
V_44 ,
V_45 ,
& V_39 ,
& V_40 ,
& V_37 ) ;
F_13 (kaddr,
L_17 ,
kfree(smumgr->backend);
smumgr->backend = NULL;
return -EINVAL) ;
V_29 -> V_31 . V_32 [ V_36 ] . V_46 = 0x01 ;
V_29 -> V_31 . V_32 [ V_36 ] . V_33 = sizeof( V_43 ) ;
V_29 -> V_31 . V_32 [ V_36 ] . V_27 = V_47 ;
V_29 -> V_31 . V_32 [ V_36 ] . V_48 =
F_27 ( V_39 ) ;
V_29 -> V_31 . V_32 [ V_36 ] . V_49 =
F_28 ( V_39 ) ;
V_29 -> V_31 . V_32 [ V_36 ] . V_26 = V_40 ;
V_29 -> V_31 . V_32 [ V_36 ] . V_37 = V_37 ;
F_26 ( V_2 -> V_8 ,
sizeof( V_50 ) ,
V_44 ,
V_45 ,
& V_39 ,
& V_40 ,
& V_37 ) ;
F_13 (kaddr,
L_18 ,
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[WMTABLE].handle);
kfree(smumgr->backend);
smumgr->backend = NULL;
return -EINVAL) ;
V_29 -> V_31 . V_32 [ V_38 ] . V_46 = 0x01 ;
V_29 -> V_31 . V_32 [ V_38 ] . V_33 = sizeof( V_50 ) ;
V_29 -> V_31 . V_32 [ V_38 ] . V_27 = V_51 ;
V_29 -> V_31 . V_32 [ V_38 ] . V_48 =
F_27 ( V_39 ) ;
V_29 -> V_31 . V_32 [ V_38 ] . V_49 =
F_28 ( V_39 ) ;
V_29 -> V_31 . V_32 [ V_38 ] . V_26 = V_40 ;
V_29 -> V_31 . V_32 [ V_38 ] . V_37 = V_37 ;
return 0 ;
}
