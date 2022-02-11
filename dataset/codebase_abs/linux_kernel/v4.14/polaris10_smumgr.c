static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = - V_5 ;
T_1 V_6 , V_7 ;
const T_2 * V_8 = V_9 ;
struct V_10 * V_11 = (struct V_10 * ) ( V_2 -> V_12 ) ;
for ( V_3 = 0 ; V_3 < V_13 ; V_3 ++ ) {
switch ( V_8 -> V_14 ) {
case V_15 :
V_6 = V_8 -> V_6 ;
V_7 = V_8 -> V_7 ;
F_2 ( V_2 -> V_16 , V_6 , V_7 ) ;
break;
case V_17 :
V_4 = 0 ;
break;
default:
F_3 ( L_1 ) ;
V_11 -> V_18 . V_19 = V_20 ;
V_4 = - V_5 ;
break;
}
V_8 ++ ;
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
struct V_10 * V_11 = (struct V_10 * ) ( V_2 -> V_12 ) ;
if ( 0 != V_11 -> V_18 . V_21 ) {
if ( 0 != F_5 ( V_2 , V_22 , V_11 -> V_18 . V_21 ) ) {
F_3 ( L_2 ) ;
V_4 = - 1 ;
}
}
if ( V_11 -> V_18 . V_21 > 1 ) {
F_2 ( V_2 -> V_16 , V_23 , 0x50000000 ) ;
F_2 ( V_2 -> V_16 , V_24 , 0xffffffff ) ;
F_2 ( V_2 -> V_16 , V_24 , 0 ) ;
}
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_25 ;
T_1 V_26 ;
T_3 V_27 ;
T_1 V_28 , V_29 , V_30 ;
V_30 = sizeof( V_31 ) ;
V_27 = F_7 ( 1300 * V_32 ) ;
F_8 ( 0 == smu7_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION + offsetof(SMU74_Firmware_Header, DpmTable),
&dpm_table_start, 0x40000),
L_3 ,
return -1 ) ;
V_25 = 0x01000500 ;
V_29 = V_26 + F_9 ( V_33 , V_34 ) ;
F_8 ( 0 == smu7_copy_bytes_to_smc(smumgr, vr_config_address,
(uint8_t *)&vr_config, sizeof(uint32_t), 0x40000),
L_4 ,
return -1 ) ;
V_28 = V_26 + F_9 ( V_33 , V_35 ) ;
F_8 ( 0 == smu7_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&avfs_graphics_level_polaris10),
graphics_level_size, 0x40000),
L_5 ,
return -1 ) ;
V_28 = V_26 + F_9 ( V_33 , V_36 ) ;
F_8 ( 0 == smu7_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&avfs_memory_level_polaris10), sizeof(avfs_memory_level_polaris10), 0x40000),
L_6 ,
return -1 ) ;
V_28 = V_26 + F_9 ( V_33 , V_37 ) ;
F_8 ( 0 == smu7_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&u16_boot_mvdd), sizeof(u16_boot_mvdd), 0x40000),
L_7 ,
return -1 ) ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , bool V_38 )
{
struct V_10 * V_11 = (struct V_10 * ) ( V_2 -> V_12 ) ;
switch ( V_11 -> V_18 . V_19 ) {
case V_39 :
break;
case V_40 :
V_11 -> V_18 . V_19 = V_41 ;
F_8 ( 0 == polaris10_setup_graphics_level_structure(smumgr),
L_8 ,
return -EINVAL) ;
if ( V_11 -> V_18 . V_21 > 1 ) {
F_3 ( L_9 ) ;
V_11 -> V_18 . V_19 = V_20 ;
F_8 ( 0 == polaris10_setup_pwr_virus(smumgr),
L_10 ,
return -EINVAL) ;
}
V_11 -> V_18 . V_19 = V_42 ;
F_8 ( 0 == polaris10_perform_btc(smumgr),
L_11 ,
return -EINVAL) ;
V_11 -> V_18 . V_19 = V_43 ;
break;
case V_44 :
case V_43 :
case V_45 :
break;
default:
F_11 ( L_12 , V_11 -> V_18 . V_19 ) ;
break;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
F_13 ( V_2 -> V_16 , V_46 ,
V_47 , V_48 , 1 ) ;
V_4 = F_14 ( V_2 ) ;
if ( V_4 != 0 )
return V_4 ;
F_15 ( V_2 -> V_16 , V_46 , V_49 , 0 ) ;
F_13 ( V_2 -> V_16 , V_46 ,
V_50 , V_51 , 0 ) ;
F_13 ( V_2 -> V_16 , V_46 ,
V_47 , V_48 , 0 ) ;
F_16 ( V_2 , V_52 , V_53 , V_54 , 1 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 , V_52 , V_55 , V_56 , 0 ) ;
if ( 1 != F_19 ( V_2 -> V_16 , V_46 ,
V_55 , V_57 ) )
F_8 (false, L_13 , return -1 ) ;
F_15 ( V_2 -> V_16 , V_46 , V_58 , 0 ) ;
F_13 ( V_2 -> V_16 , V_46 ,
V_47 , V_48 , 1 ) ;
F_13 ( V_2 -> V_16 , V_46 ,
V_47 , V_48 , 0 ) ;
F_16 ( V_2 , V_52 , V_59 , V_54 , 1 ) ;
return V_4 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
F_18 ( V_2 , V_52 , V_53 , V_60 , 0 ) ;
F_15 ( V_2 -> V_16 , V_46 ,
V_58 , 0 ) ;
F_13 ( V_2 -> V_16 , V_46 ,
V_47 ,
V_48 , 1 ) ;
V_4 = F_14 ( V_2 ) ;
if ( V_4 != 0 )
return V_4 ;
F_21 ( V_2 ) ;
F_13 ( V_2 -> V_16 , V_46 ,
V_50 , V_51 , 0 ) ;
F_13 ( V_2 -> V_16 , V_46 ,
V_47 , V_48 , 0 ) ;
F_16 ( V_2 , V_52 ,
V_59 , V_54 , 1 ) ;
return V_4 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
struct V_61 * V_11 = (struct V_61 * ) ( V_2 -> V_12 ) ;
bool V_38 ;
if ( ! F_23 ( V_2 ) ) {
V_38 = false ;
V_11 -> V_62 = ( V_63 ) ( F_19 ( V_2 -> V_16 , V_46 , V_64 , V_65 ) ) ;
V_11 -> V_66 . V_67 = ( V_63 ) ( F_19 ( V_2 -> V_16 , V_46 , V_64 , V_68 ) ) ;
if ( V_11 -> V_62 == 0 ) {
V_4 = F_20 ( V_2 ) ;
} else {
V_4 = F_12 ( V_2 ) ;
if ( V_4 != 0 ) {
V_11 -> V_66 . V_67 ^= 1 ;
F_24 ( V_2 -> V_16 , V_69 ) ;
V_4 = F_12 ( V_2 ) ;
}
}
if ( V_4 != 0 )
F_8 ( 0 , L_14 , return result) ;
F_10 ( V_2 , true ) ;
} else
V_38 = true ;
F_10 ( V_2 , V_38 ) ;
F_25 ( V_2 , V_70 + F_9 ( V_71 , V_72 ) ,
& ( V_11 -> V_66 . V_73 ) , 0x40000 ) ;
V_4 = F_26 ( V_2 ) ;
return V_4 ;
}
static bool F_27 ( struct V_1 * V_2 )
{
T_1 V_74 ;
V_74 = F_28 ( V_2 -> V_16 , V_46 , V_75 + ( 49 * 4 ) ) ;
V_74 &= 0x00000001 ;
if ( V_74 )
return true ;
return false ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_61 * V_11 ;
int V_3 ;
V_11 = F_30 ( sizeof( struct V_61 ) , V_76 ) ;
if ( V_11 == NULL )
return - V_77 ;
V_2 -> V_12 = V_11 ;
if ( F_31 ( V_2 ) )
return - V_5 ;
for ( V_3 = 0 ; V_3 < V_78 ; V_3 ++ )
V_11 -> V_79 [ V_3 ] = V_80 ;
return 0 ;
}
