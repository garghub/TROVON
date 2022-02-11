static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_7 , 1 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_4 ( V_2 -> V_4 , V_5 ,
V_8 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_9 , V_10 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_7 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_11 , V_12 , 1 ) ;
F_4 ( V_2 -> V_4 , V_5 ,
V_13 , 0 ) ;
F_5 ( V_2 , V_14 , V_15 ,
V_16 , 1 ) ;
F_6 ( V_2 -> V_4 , V_17 , 0x20000 ) ;
F_6 ( V_2 -> V_4 , V_18 , V_19 ) ;
F_7 ( V_2 , V_20 , V_21 , 0 ) ;
F_8 ( V_2 , V_14 ,
V_22 , V_23 , 0 ) ;
if ( F_9 ( V_2 -> V_4 , V_5 ,
V_22 , V_24 ) != 1 ) {
F_10 (false,
L_1 , return -1 ) ;
}
F_5 ( V_2 , V_14 ,
V_25 , V_16 , 1 ) ;
return V_3 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_8 ( V_2 , V_14 ,
V_15 , V_26 , 0 ) ;
F_4 ( V_2 -> V_4 , V_5 ,
V_13 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_7 , 1 ) ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_12 ( V_2 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_9 , V_10 , 0 ) ;
F_2 ( V_2 -> V_4 , V_5 ,
V_6 , V_7 , 0 ) ;
F_5 ( V_2 , V_14 ,
V_25 , V_16 , 1 ) ;
return V_3 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_27 , V_3 = - 1 ;
T_1 V_28 , V_29 ;
const T_2 * V_30 = V_31 ;
struct V_32 * V_33 = (struct V_32 * ) ( V_2 -> V_34 ) ;
V_33 -> V_35 . V_36 = V_37 ;
for ( V_27 = 0 ; ( V_27 < V_38 ) ; V_27 ++ ) {
switch ( V_30 -> V_39 ) {
case V_40 :
V_28 = V_30 -> V_28 ;
V_29 = V_30 -> V_29 ;
F_6 ( V_2 -> V_4 , V_28 , V_29 ) ;
break;
case V_41 :
V_33 -> V_35 . V_36 = V_42 ;
V_3 = 0 ;
break;
default:
F_14 ( L_2 ) ;
V_33 -> V_35 . V_36 = V_43 ;
V_3 = - 1 ;
break;
}
V_30 ++ ;
}
return V_3 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_32 * V_33 = (struct V_32 * ) ( V_2 -> V_34 ) ;
V_33 -> V_35 . V_36 = V_44 ;
if ( V_33 -> V_35 . V_45 ) {
if ( ! F_16 ( V_2 ,
V_46 , V_33 -> V_35 . V_45 ) ) {
if ( ! F_17 ( V_2 , V_47 ) ) {
V_33 -> V_35 . V_36 = V_48 ;
V_3 = 0 ;
} else {
F_14 ( L_3
L_4 ) ;
F_17 ( V_2 , V_49 ) ;
V_3 = - 1 ;
}
} else {
F_14 ( L_5
L_6 ) ;
V_3 = - 1 ;
}
}
F_6 ( V_2 -> V_4 , V_50 , 0x50000000 ) ;
F_6 ( V_2 -> V_4 , V_51 , 0xffffffff ) ;
F_6 ( V_2 -> V_4 , V_51 , 0 ) ;
return V_3 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
T_1 V_52 ;
T_1 V_53 , V_54 , V_55 ;
T_3 V_56 ;
V_55 = 0x30750000 ;
V_56 = 0x1A04 ;
F_10 ( 0 == smu7_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION + offsetof(SMU73_Firmware_Header,
PmFuseTable), &table_start, 0x40000),
L_7
L_8 ,
return -1;) ;
V_53 = V_52 +
F_19 ( struct V_57 , V_58 ) ;
V_54 = V_52 +
F_19 ( struct V_57 , V_59 ) ;
V_3 = F_20 ( V_2 , V_53 ,
( V_60 * ) ( & V_55 ) , sizeof( V_55 ) , 0x40000 ) ;
F_10 ( 0 == result,
L_9
L_10 , return -1;) ;
V_3 = F_20 ( V_2 , V_54 ,
( V_60 * ) ( & V_56 ) , sizeof( V_56 ) , 0x40000 ) ;
F_10 ( 0 == result, L_11
L_12 , return -1;) ;
return V_3 ;
}
static int F_21 ( struct V_1 * V_2 )
{
T_4 V_61 ;
T_1 V_52 ;
T_1 V_62 , V_63 ;
T_1 V_64 = sizeof( V_65 ) ;
F_10 ( 0 == smu7_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION +
offsetof(SMU73_Firmware_Header, DpmTable),
&table_start, 0x40000),
L_13
L_14 ,
return -1;) ;
V_61 = 0x01000500 ;
V_63 = V_52 +
F_19 ( V_66 , V_67 ) ;
F_10 ( 0 == smu7_copy_bytes_to_smc(smumgr, vr_config_addr,
(uint8_t *)&vr_config, sizeof(int32_t), 0x40000),
L_15
L_16 ,
return -1;) ;
V_62 = V_52 + F_19 ( V_66 , V_68 ) ;
F_10 ( 0 == smu7_copy_bytes_to_smc(smumgr, level_addr,
(uint8_t *)(&avfs_graphics_level), level_size, 0x40000),
L_17 ,
return -1;) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) ( V_2 -> V_34 ) ;
if ( V_69 == V_33 -> V_35 . V_36 ) {
V_33 -> V_35 . V_36 = V_70 ;
return 0 ;
} else
return - V_71 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = (struct V_32 * ) ( V_2 -> V_34 ) ;
if ( V_69 == V_33 -> V_35 . V_36 ) {
V_33 -> V_35 . V_36 = V_70 ;
return 0 ;
} else
return - V_71 ;
}
static int F_24 ( struct V_1 * V_2 , bool V_72 )
{
struct V_32 * V_33 = (struct V_32 * ) ( V_2 -> V_34 ) ;
switch ( V_33 -> V_35 . V_36 ) {
case V_69 :
V_33 -> V_35 . V_36 = V_73 ;
F_10 ( 0 == fiji_restore_vft_table(smumgr),
L_18
L_19 ,
return -1;) ;
V_33 -> V_35 . V_36 = V_70 ;
break;
case V_70 :
V_33 -> V_35 . V_36 = V_74 ;
F_10 ( 0 == smum_send_msg_to_smc(smumgr,
0x666),
L_20
L_21 ,
return -1;) ;
V_33 -> V_35 . V_36 = V_74 ;
F_10 ( 0 == smum_send_msg_to_smc(smumgr,
PPSMC_MSG_EnableAvfs),
L_20
L_22 ,
return -1;) ;
V_33 -> V_35 . V_36 = V_69 ;
break;
case V_75 :
if ( ! V_72 )
break;
V_33 -> V_35 . V_36 = V_76 ;
F_10 ( 0 == fiji_setup_pm_fuse_for_avfs(smumgr),
L_23
L_24 ,
return -1;) ;
V_33 -> V_35 . V_36 = V_77 ;
F_10 ( 0 == fiji_setup_graphics_level_structure(smumgr),
L_25
L_26 ,
return -1;) ;
V_33 -> V_35 . V_36 = V_43 ;
F_10 ( 0 == fiji_setup_pwr_virus(smumgr),
L_27
L_28 ,
return -1;) ;
V_33 -> V_35 . V_36 = V_76 ;
F_10 ( 0 == fiji_start_avfs_btc(smumgr),
L_23
L_29 ,
return -1;) ;
V_33 -> V_35 . V_36 = V_78 ;
F_10 ( 0 == fiji_save_vft_table(smumgr),
L_30 ,
return -1;) ;
V_33 -> V_35 . V_36 = V_69 ;
break;
case V_79 :
break;
case V_80 :
break;
default:
F_14 ( L_31 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_32 * V_33 = (struct V_32 * ) ( V_2 -> V_34 ) ;
if ( ! ( F_26 ( V_2 )
|| F_27 ( V_2 -> V_4 ) ) ) {
F_24 ( V_2 , false ) ;
if ( 0 == F_9 ( V_2 -> V_4 ,
V_5 ,
V_81 , V_82 ) ) {
V_3 = F_11 ( V_2 ) ;
if ( V_3 )
return V_3 ;
} else {
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
}
F_24 ( V_2 , true ) ;
}
F_28 ( V_2 -> V_4 ,
V_83 , V_84 ) ;
F_28 ( V_2 -> V_4 ,
V_85 , V_84 ) ;
F_28 ( V_2 -> V_4 ,
V_86 , V_84 ) ;
F_28 ( V_2 -> V_4 ,
V_87 , V_84 ) ;
F_29 ( V_2 ,
V_88 +
F_19 ( V_89 , V_90 ) ,
& ( V_33 -> V_91 . V_92 ) , 0x40000 ) ;
V_3 = F_30 ( V_2 ) ;
return V_3 ;
}
static bool F_31 ( struct V_1 * V_2 )
{
T_1 V_93 = 0 ;
T_1 V_94 = ( 1 << ( ( V_95 - V_96 ) + 1 ) ) - 1 ;
if ( F_27 ( V_2 -> V_4 ) )
return 0 ;
if ( ! F_32 ( V_2 -> V_4 , V_96 , V_95 ,
V_94 , & V_93 ) ) {
if ( V_93 )
return true ;
}
return false ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_32 * V_97 = NULL ;
V_97 = F_34 ( sizeof( struct V_32 ) , V_98 ) ;
if ( V_97 == NULL )
return - V_99 ;
V_2 -> V_34 = V_97 ;
if ( F_35 ( V_2 ) )
return - V_71 ;
V_97 -> V_35 . V_36 = V_75 ;
if ( F_31 ( V_2 ) )
V_97 -> V_35 . V_45 = 0 ;
else
V_97 -> V_35 . V_36 = V_80 ;
for ( V_27 = 0 ; V_27 < V_100 ; V_27 ++ )
V_97 -> V_101 [ V_27 ] = 30 ;
return 0 ;
}
