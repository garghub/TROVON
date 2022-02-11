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
int V_27 ;
int V_3 = - V_28 ;
T_1 V_29 , V_30 ;
const T_2 * V_31 = V_32 ;
struct V_33 * V_34 = (struct V_33 * ) ( V_2 -> V_35 ) ;
for ( V_27 = 0 ; V_27 < V_36 ; V_27 ++ ) {
switch ( V_31 -> V_37 ) {
case V_38 :
V_29 = V_31 -> V_29 ;
V_30 = V_31 -> V_30 ;
F_6 ( V_2 -> V_4 , V_29 , V_30 ) ;
break;
case V_39 :
V_3 = 0 ;
break;
default:
F_14 ( L_2 ) ;
V_34 -> V_40 . V_41 = V_42 ;
V_3 = - V_28 ;
break;
}
V_31 ++ ;
}
return V_3 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_33 * V_34 = (struct V_33 * ) ( V_2 -> V_35 ) ;
if ( 0 != V_34 -> V_40 . V_43 ) {
if ( 0 != F_16 ( V_2 ,
V_44 , V_34 -> V_40 . V_43 ) ) {
F_14 ( L_3 ) ;
V_3 = - V_28 ;
}
}
F_6 ( V_2 -> V_4 , V_45 , 0x50000000 ) ;
F_6 ( V_2 -> V_4 , V_46 , 0xffffffff ) ;
F_6 ( V_2 -> V_4 , V_46 , 0 ) ;
return V_3 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_3 V_47 ;
T_1 V_48 ;
T_1 V_49 , V_50 ;
T_1 V_51 = sizeof( V_52 ) ;
F_10 ( 0 == smu7_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION +
offsetof(SMU73_Firmware_Header, DpmTable),
&table_start, 0x40000),
L_4
L_5 ,
return -1;) ;
V_47 = 0x01000500 ;
V_50 = V_48 +
F_18 ( V_53 , V_54 ) ;
F_10 ( 0 == smu7_copy_bytes_to_smc(smumgr, vr_config_addr,
(uint8_t *)&vr_config, sizeof(int32_t), 0x40000),
L_6
L_7 ,
return -1;) ;
V_49 = V_48 + F_18 ( V_53 , V_55 ) ;
F_10 ( 0 == smu7_copy_bytes_to_smc(smumgr, level_addr,
(uint8_t *)(&avfs_graphics_level), level_size, 0x40000),
L_8 ,
return -1;) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , bool V_56 )
{
struct V_33 * V_34 = (struct V_33 * ) ( V_2 -> V_35 ) ;
switch ( V_34 -> V_40 . V_41 ) {
case V_57 :
break;
case V_58 :
if ( ! V_56 )
break;
V_34 -> V_40 . V_41 = V_59 ;
F_10 ( 0 == fiji_setup_graphics_level_structure(smumgr),
L_9
L_10 ,
return -EINVAL;) ;
V_34 -> V_40 . V_41 = V_42 ;
F_10 ( 0 == fiji_setup_pwr_virus(smumgr),
L_11
L_12 ,
return -EINVAL;) ;
V_34 -> V_40 . V_41 = V_59 ;
F_10 ( 0 == fiji_start_avfs_btc(smumgr),
L_13
L_14 ,
return -EINVAL;) ;
V_34 -> V_40 . V_41 = V_60 ;
break;
case V_61 :
case V_62 :
case V_60 :
break;
default:
F_20 ( L_15 , V_34 -> V_40 . V_41 ) ;
break;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_63 * V_64 = (struct V_63 * ) ( V_2 -> V_35 ) ;
if ( ! ( F_22 ( V_2 )
|| F_23 ( V_2 -> V_4 ) ) ) {
F_19 ( V_2 , false ) ;
if ( 0 == F_9 ( V_2 -> V_4 ,
V_5 ,
V_65 , V_66 ) ) {
V_3 = F_11 ( V_2 ) ;
if ( V_3 )
return V_3 ;
} else {
V_3 = F_1 ( V_2 ) ;
if ( V_3 )
return V_3 ;
}
F_19 ( V_2 , true ) ;
}
F_24 ( V_2 -> V_4 ,
V_67 , V_68 ) ;
F_24 ( V_2 -> V_4 ,
V_69 , V_68 ) ;
F_24 ( V_2 -> V_4 ,
V_70 , V_68 ) ;
F_24 ( V_2 -> V_4 ,
V_71 , V_68 ) ;
F_25 ( V_2 ,
V_72 +
F_18 ( V_73 , V_74 ) ,
& ( V_64 -> V_75 . V_76 ) , 0x40000 ) ;
V_3 = F_26 ( V_2 ) ;
return V_3 ;
}
static bool F_27 ( struct V_1 * V_2 )
{
T_1 V_77 = 0 ;
T_1 V_78 = ( 1 << ( ( V_79 - V_80 ) + 1 ) ) - 1 ;
if ( F_23 ( V_2 -> V_4 ) )
return 0 ;
if ( ! F_28 ( V_2 -> V_4 , V_80 , V_79 ,
V_78 , & V_77 ) ) {
if ( V_77 )
return true ;
}
return false ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_27 ;
struct V_63 * V_81 = NULL ;
V_81 = F_30 ( sizeof( struct V_63 ) , V_82 ) ;
if ( V_81 == NULL )
return - V_83 ;
V_2 -> V_35 = V_81 ;
if ( F_31 ( V_2 ) )
return - V_28 ;
for ( V_27 = 0 ; V_27 < V_84 ; V_27 ++ )
V_81 -> V_85 [ V_27 ] = 30 ;
return 0 ;
}
