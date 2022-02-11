static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = - 1 ;
T_1 V_5 , V_6 ;
const T_2 * V_7 = V_8 ;
struct V_9 * V_10 = (struct V_9 * ) ( V_2 -> V_11 ) ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
switch ( V_7 -> V_13 ) {
case V_14 :
V_5 = V_7 -> V_5 ;
V_6 = V_7 -> V_6 ;
F_2 ( V_2 -> V_15 , V_5 , V_6 ) ;
break;
case V_16 :
V_4 = 0 ;
break;
default:
F_3 ( L_1 ) ;
V_10 -> V_17 . V_18 = V_19 ;
V_4 = - 1 ;
break;
}
V_7 ++ ;
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
struct V_9 * V_10 = (struct V_9 * ) ( V_2 -> V_11 ) ;
if ( 0 != V_10 -> V_17 . V_20 ) {
if ( 0 != F_5 ( V_2 , V_21 , V_10 -> V_17 . V_20 ) ) {
F_3 ( L_2 ) ;
V_4 = - 1 ;
}
}
if ( V_10 -> V_17 . V_20 > 1 ) {
F_2 ( V_2 -> V_15 , V_22 , 0x50000000 ) ;
F_2 ( V_2 -> V_15 , V_23 , 0xffffffff ) ;
F_2 ( V_2 -> V_15 , V_23 , 0 ) ;
}
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_24 ;
T_1 V_25 ;
T_3 V_26 ;
T_1 V_27 , V_28 , V_29 ;
V_29 = sizeof( V_30 ) ;
V_26 = F_7 ( 1300 * V_31 ) ;
F_8 ( 0 == smu7_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION + offsetof(SMU74_Firmware_Header, DpmTable),
&dpm_table_start, 0x40000),
L_3 ,
return -1 ) ;
V_24 = 0x01000500 ;
V_28 = V_25 + F_9 ( V_32 , V_33 ) ;
F_8 ( 0 == smu7_copy_bytes_to_smc(smumgr, vr_config_address,
(uint8_t *)&vr_config, sizeof(uint32_t), 0x40000),
L_4 ,
return -1 ) ;
V_27 = V_25 + F_9 ( V_32 , V_34 ) ;
F_8 ( 0 == smu7_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&avfs_graphics_level_polaris10),
graphics_level_size, 0x40000),
L_5 ,
return -1 ) ;
V_27 = V_25 + F_9 ( V_32 , V_35 ) ;
F_8 ( 0 == smu7_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&avfs_memory_level_polaris10), sizeof(avfs_memory_level_polaris10), 0x40000),
L_6 ,
return -1 ) ;
V_27 = V_25 + F_9 ( V_32 , V_36 ) ;
F_8 ( 0 == smu7_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&u16_boot_mvdd), sizeof(u16_boot_mvdd), 0x40000),
L_7 ,
return -1 ) ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , bool V_37 )
{
struct V_9 * V_10 = (struct V_9 * ) ( V_2 -> V_11 ) ;
switch ( V_10 -> V_17 . V_18 ) {
case V_38 :
break;
case V_39 :
V_10 -> V_17 . V_18 = V_40 ;
F_8 ( 0 == polaris10_setup_graphics_level_structure(smumgr),
L_8 ,
return -1 ) ;
if ( V_10 -> V_17 . V_20 > 1 ) {
F_3 ( L_9 ) ;
V_10 -> V_17 . V_18 = V_19 ;
F_8 (-1 == polaris10_setup_pwr_virus(smumgr),
L_10 ,
return -1 ) ;
}
V_10 -> V_17 . V_18 = V_41 ;
F_8 ( 0 == polaris10_perform_btc(smumgr),
L_11 ,
return -1 ) ;
break;
case V_42 :
case V_43 :
break;
default:
F_3 ( L_12 ) ;
break;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
F_12 ( V_2 -> V_15 , V_44 ,
V_45 , V_46 , 1 ) ;
V_4 = F_13 ( V_2 ) ;
if ( V_4 != 0 )
return V_4 ;
F_14 ( V_2 -> V_15 , V_44 , V_47 , 0 ) ;
F_12 ( V_2 -> V_15 , V_44 ,
V_48 , V_49 , 0 ) ;
F_12 ( V_2 -> V_15 , V_44 ,
V_45 , V_46 , 0 ) ;
F_15 ( V_2 , V_50 , V_51 , V_52 , 1 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 , V_50 , V_53 , V_54 , 0 ) ;
if ( 1 != F_18 ( V_2 -> V_15 , V_44 ,
V_53 , V_55 ) )
F_8 (false, L_13 , return -1 ) ;
F_14 ( V_2 -> V_15 , V_44 , V_56 , 0 ) ;
F_12 ( V_2 -> V_15 , V_44 ,
V_45 , V_46 , 1 ) ;
F_12 ( V_2 -> V_15 , V_44 ,
V_45 , V_46 , 0 ) ;
F_15 ( V_2 , V_50 , V_57 , V_52 , 1 ) ;
return V_4 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
F_17 ( V_2 , V_50 , V_51 , V_58 , 0 ) ;
F_14 ( V_2 -> V_15 , V_44 ,
V_56 , 0 ) ;
F_12 ( V_2 -> V_15 , V_44 ,
V_45 ,
V_46 , 1 ) ;
V_4 = F_13 ( V_2 ) ;
if ( V_4 != 0 )
return V_4 ;
F_20 ( V_2 ) ;
F_12 ( V_2 -> V_15 , V_44 ,
V_48 , V_49 , 0 ) ;
F_12 ( V_2 -> V_15 , V_44 ,
V_45 , V_46 , 0 ) ;
F_15 ( V_2 , V_50 ,
V_57 , V_52 , 1 ) ;
return V_4 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
struct V_9 * V_10 = (struct V_9 * ) ( V_2 -> V_11 ) ;
bool V_37 ;
if ( ! F_22 ( V_2 ) ) {
V_37 = false ;
V_10 -> V_59 = ( V_60 ) ( F_18 ( V_2 -> V_15 , V_44 , V_61 , V_62 ) ) ;
V_10 -> V_63 . V_64 = ( V_60 ) ( F_18 ( V_2 -> V_15 , V_44 , V_61 , V_65 ) ) ;
if ( V_10 -> V_59 == 0 ) {
V_4 = F_19 ( V_2 ) ;
} else {
V_4 = F_11 ( V_2 ) ;
if ( V_4 != 0 ) {
V_10 -> V_63 . V_64 ^= 1 ;
F_23 ( V_2 -> V_15 , V_66 ) ;
V_4 = F_11 ( V_2 ) ;
}
}
if ( V_4 != 0 )
F_8 ( 0 , L_14 , return result) ;
F_10 ( V_2 , true ) ;
} else
V_37 = true ;
F_10 ( V_2 , V_37 ) ;
F_24 ( V_2 , V_67 + F_9 ( V_68 , V_69 ) ,
& ( V_10 -> V_63 . V_70 ) , 0x40000 ) ;
V_4 = F_25 ( V_2 ) ;
return V_4 ;
}
static bool F_26 ( struct V_1 * V_2 )
{
T_1 V_71 ;
V_71 = F_27 ( V_2 -> V_15 , V_44 , V_72 + ( 49 * 4 ) ) ;
V_71 &= 0x00000001 ;
if ( V_71 )
return true ;
return false ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_3 ;
V_10 = F_29 ( sizeof( struct V_9 ) , V_73 ) ;
if ( V_10 == NULL )
return - V_74 ;
V_2 -> V_11 = V_10 ;
if ( F_30 ( V_2 ) )
return - V_75 ;
if ( F_26 ( V_2 ) )
V_10 -> V_17 . V_18 = V_39 ;
else
V_10 -> V_17 . V_18 = V_43 ;
for ( V_3 = 0 ; V_3 < V_76 ; V_3 ++ )
V_10 -> V_77 [ V_3 ] = V_78 ;
return 0 ;
}
