static bool F_1 ( struct V_1 * V_2 )
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
int F_8 ( struct V_1 * V_2 , T_2 V_19 )
{
T_1 V_4 ;
if ( ! F_1 ( V_2 ) )
return - V_14 ;
F_5 ( V_2 ) ;
V_4 = F_2 ( V_15 , 0 ,
V_16 , V_17 ) ;
F_3 ( V_2 -> V_8 , V_4 , 0 ) ;
F_7 ( V_2 , V_19 ) ;
if ( F_5 ( V_2 ) != 1 )
F_9 ( L_1 , V_19 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 ,
T_2 V_19 , T_1 V_22 )
{
T_1 V_4 ;
if ( ! F_1 ( V_2 ) )
return - V_14 ;
F_5 ( V_2 ) ;
V_4 = F_2 ( V_15 , 0 ,
V_16 , V_17 ) ;
F_3 ( V_2 -> V_8 , V_4 , 0 ) ;
V_4 = F_2 ( V_15 , 0 ,
V_23 , V_24 ) ;
F_3 ( V_2 -> V_8 , V_4 , V_22 ) ;
F_7 ( V_2 , V_19 ) ;
if ( F_5 ( V_2 ) != 1 )
F_9 ( L_1 , V_19 ) ;
return 0 ;
}
int F_11 (
struct V_1 * V_2 , T_2 V_19 , T_1 V_22 )
{
T_1 V_4 ;
V_4 = F_2 ( V_15 , 0 ,
V_23 , V_24 ) ;
F_3 ( V_2 -> V_8 , V_4 , V_22 ) ;
return F_7 ( V_2 , V_19 ) ;
}
int F_12 ( struct V_1 * V_2 , T_1 * V_25 )
{
T_1 V_4 ;
V_4 = F_2 ( V_15 , 0 ,
V_23 , V_24 ) ;
* V_25 = F_4 ( V_2 -> V_8 , V_4 ) ;
return 0 ;
}
int F_13 ( struct V_1 * V_2 ,
T_3 * V_26 , T_4 V_27 )
{
struct V_28 * V_29 =
(struct V_28 * ) ( V_2 -> V_30 ) ;
F_14 (table_id < MAX_SMU_TABLE,
L_2 , return -EINVAL) ;
F_14 (priv->smu_tables.entry[table_id].version != 0 ,
L_3 , return -EINVAL) ;
F_14 (priv->smu_tables.entry[table_id].size != 0 ,
L_4 , return -EINVAL) ;
F_14 (vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrHigh,
priv->smu_tables.entry[table_id].table_addr_high) == 0 ,
L_5 , return -EINVAL) ;
F_14 (vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrLow,
priv->smu_tables.entry[table_id].table_addr_low) == 0 ,
L_6 ,
return -EINVAL) ;
F_14 (vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_TransferTableSmu2Dram,
priv->smu_tables.entry[table_id].table_id) == 0 ,
L_7 ,
return -EINVAL) ;
memcpy ( V_26 , V_29 -> V_31 . V_32 [ V_27 ] . V_26 ,
V_29 -> V_31 . V_32 [ V_27 ] . V_33 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 ,
T_3 * V_26 , T_4 V_27 )
{
struct V_28 * V_29 =
(struct V_28 * ) ( V_2 -> V_30 ) ;
F_14 (table_id < MAX_SMU_TABLE,
L_2 , return -EINVAL) ;
F_14 (priv->smu_tables.entry[table_id].version != 0 ,
L_3 , return -EINVAL) ;
F_14 (priv->smu_tables.entry[table_id].size != 0 ,
L_4 , return -EINVAL) ;
memcpy ( V_29 -> V_31 . V_32 [ V_27 ] . V_26 , V_26 ,
V_29 -> V_31 . V_32 [ V_27 ] . V_33 ) ;
F_14 (vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrHigh,
priv->smu_tables.entry[table_id].table_addr_high) == 0 ,
L_8 ,
return -EINVAL;) ;
F_14 (vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_SetDriverDramAddrLow,
priv->smu_tables.entry[table_id].table_addr_low) == 0 ,
L_9 ,
return -EINVAL) ;
F_14 (vega10_send_msg_to_smc_with_parameter(smumgr,
PPSMC_MSG_TransferTableDram2Smu,
priv->smu_tables.entry[table_id].table_id) == 0 ,
L_10 ,
return -EINVAL) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_3 * V_34 )
{
F_14 (avfs_table,
L_11 ,
return -EINVAL) ;
return F_13 ( V_2 , V_34 , V_35 ) ;
}
int F_17 ( struct V_1 * V_2 , T_3 * V_34 )
{
F_14 (avfs_table,
L_11 ,
return -EINVAL) ;
return F_15 ( V_2 , V_34 , V_35 ) ;
}
int F_18 ( struct V_1 * V_2 ,
bool V_36 , T_1 V_37 )
{
int V_19 = V_36 ? V_38 :
V_39 ;
return F_10 ( V_2 ,
V_19 , V_37 ) ;
}
int F_19 ( struct V_1 * V_2 ,
T_1 * V_40 )
{
if ( V_40 == NULL )
return - V_14 ;
if ( ! F_8 ( V_2 ,
V_41 ) ) {
F_12 ( V_2 , V_40 ) ;
return 0 ;
}
return - V_14 ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
(struct V_28 * ) ( V_2 -> V_30 ) ;
if ( V_29 -> V_31 . V_32 [ V_42 ] . V_43 ||
V_29 -> V_31 . V_32 [ V_42 ] . V_44 ) {
if ( ! F_10 ( V_2 ,
V_45 ,
V_29 -> V_31 . V_32 [ V_42 ] . V_43 ) )
F_10 ( V_2 ,
V_46 ,
V_29 -> V_31 . V_32 [ V_42 ] . V_44 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
T_1 V_47 ;
F_14 (!vega10_send_msg_to_smc(smumgr,
PPSMC_MSG_GetDriverIfVersion),
L_12 ,
return -EINVAL) ;
F_12 ( V_2 , & V_47 ) ;
if ( V_47 != V_48 ) {
F_9 ( L_13 ,
V_47 , V_48 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
T_5 V_49 ;
void * V_50 = NULL ;
unsigned long V_51 , V_52 ;
int V_53 ;
struct V_54 V_55 = { 0 } ;
V_53 = F_23 ( V_2 -> V_8 ,
F_24 ( V_56 ) ,
& V_55 ) ;
if ( V_53 || ! V_55 . V_57 )
return - V_14 ;
V_29 = F_25 ( sizeof( struct V_28 ) , V_58 ) ;
if ( ! V_29 )
return - V_59 ;
V_2 -> V_30 = V_29 ;
F_26 ( V_2 -> V_8 ,
sizeof( V_60 ) ,
V_61 ,
V_62 ,
& V_49 ,
& V_50 ,
& V_51 ) ;
F_14 (kaddr,
L_14 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)handle);
return -EINVAL) ;
V_29 -> V_31 . V_32 [ V_63 ] . V_64 = 0x01 ;
V_29 -> V_31 . V_32 [ V_63 ] . V_33 = sizeof( V_60 ) ;
V_29 -> V_31 . V_32 [ V_63 ] . V_27 = V_65 ;
V_29 -> V_31 . V_32 [ V_63 ] . V_43 =
F_27 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_63 ] . V_44 =
F_28 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_63 ] . V_26 = V_50 ;
V_29 -> V_31 . V_32 [ V_63 ] . V_51 = V_51 ;
F_26 ( V_2 -> V_8 ,
sizeof( V_66 ) ,
V_61 ,
V_62 ,
& V_49 ,
& V_50 ,
& V_51 ) ;
F_14 (kaddr,
L_15 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[PPTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)handle);
return -EINVAL) ;
V_29 -> V_31 . V_32 [ V_67 ] . V_64 = 0x01 ;
V_29 -> V_31 . V_32 [ V_67 ] . V_33 = sizeof( V_66 ) ;
V_29 -> V_31 . V_32 [ V_67 ] . V_27 = V_68 ;
V_29 -> V_31 . V_32 [ V_67 ] . V_43 =
F_27 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_67 ] . V_44 =
F_28 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_67 ] . V_26 = V_50 ;
V_29 -> V_31 . V_32 [ V_67 ] . V_51 = V_51 ;
F_26 ( V_2 -> V_8 ,
sizeof( V_69 ) ,
V_61 ,
V_62 ,
& V_49 ,
& V_50 ,
& V_51 ) ;
F_14 (kaddr,
L_16 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[PPTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[WMTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)handle);
return -EINVAL) ;
V_29 -> V_31 . V_32 [ V_35 ] . V_64 = 0x01 ;
V_29 -> V_31 . V_32 [ V_35 ] . V_33 = sizeof( V_69 ) ;
V_29 -> V_31 . V_32 [ V_35 ] . V_27 = V_70 ;
V_29 -> V_31 . V_32 [ V_35 ] . V_43 =
F_27 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_35 ] . V_44 =
F_28 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_35 ] . V_26 = V_50 ;
V_29 -> V_31 . V_32 [ V_35 ] . V_51 = V_51 ;
V_52 = 0x19000 ;
if ( V_52 ) {
F_26 ( V_2 -> V_8 ,
V_52 ,
V_61 ,
V_62 ,
& V_49 ,
& V_50 ,
& V_51 ) ;
if ( V_50 ) {
V_29 -> V_31 . V_32 [ V_42 ] . V_64 = 0x01 ;
V_29 -> V_31 . V_32 [ V_42 ] . V_33 = V_52 ;
V_29 -> V_31 . V_32 [ V_42 ] . V_27 = V_71 ;
V_29 -> V_31 . V_32 [ V_42 ] . V_43 =
F_27 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_42 ] . V_44 =
F_28 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_42 ] . V_26 = V_50 ;
V_29 -> V_31 . V_32 [ V_42 ] . V_51 = V_51 ;
F_20 ( V_2 ) ;
}
}
F_26 ( V_2 -> V_8 ,
sizeof( V_72 ) ,
V_61 ,
V_62 ,
& V_49 ,
& V_50 ,
& V_51 ) ;
F_14 (kaddr,
L_17 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[PPTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[WMTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[AVFSTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->smu_tables.entry[TOOLSTABLE].handle);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)handle);
return -EINVAL) ;
V_29 -> V_31 . V_32 [ V_73 ] . V_64 = 0x01 ;
V_29 -> V_31 . V_32 [ V_73 ] . V_33 = sizeof( V_72 ) ;
V_29 -> V_31 . V_32 [ V_73 ] . V_27 = V_74 ;
V_29 -> V_31 . V_32 [ V_73 ] . V_43 =
F_27 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_73 ] . V_44 =
F_28 ( V_49 ) ;
V_29 -> V_31 . V_32 [ V_73 ] . V_26 = V_50 ;
V_29 -> V_31 . V_32 [ V_73 ] . V_51 = V_51 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_28 * V_29 =
(struct V_28 * ) ( V_2 -> V_30 ) ;
if ( V_29 ) {
F_30 ( V_2 -> V_8 ,
( V_75 ) V_29 -> V_31 . V_32 [ V_63 ] . V_51 ) ;
F_30 ( V_2 -> V_8 ,
( V_75 ) V_29 -> V_31 . V_32 [ V_67 ] . V_51 ) ;
F_30 ( V_2 -> V_8 ,
( V_75 ) V_29 -> V_31 . V_32 [ V_35 ] . V_51 ) ;
if ( V_29 -> V_31 . V_32 [ V_42 ] . V_26 )
F_30 ( V_2 -> V_8 ,
( V_75 ) V_29 -> V_31 . V_32 [ V_42 ] . V_51 ) ;
F_30 ( V_2 -> V_8 ,
( V_75 ) V_29 -> V_31 . V_32 [ V_73 ] . V_51 ) ;
F_31 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
F_14 (!vega10_verify_smc_interface(smumgr),
L_18 ,
return -EINVAL) ;
return 0 ;
}
