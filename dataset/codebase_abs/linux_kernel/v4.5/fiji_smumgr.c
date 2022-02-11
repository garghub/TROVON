static enum V_1 F_1 ( T_1 V_2 )
{
enum V_1 V_3 = V_4 ;
switch ( V_2 ) {
case V_5 :
V_3 = V_6 ;
break;
case V_7 :
V_3 = V_8 ;
break;
case V_9 :
V_3 = V_10 ;
break;
case V_11 :
V_3 = V_12 ;
break;
case V_13 :
V_3 = V_14 ;
break;
case V_15 :
V_3 = V_16 ;
break;
case V_17 :
V_3 = V_18 ;
break;
case V_19 :
V_3 = V_20 ;
break;
case V_21 :
V_3 = V_22 ;
break;
case V_23 :
V_3 = V_24 ;
break;
default:
break;
}
return V_3 ;
}
static int F_2 ( struct V_25 * V_26 ,
T_1 V_27 , T_1 V_28 )
{
F_3 ((0 == (3 & smc_addr)),
L_1 , return -EINVAL;) ;
F_3 ((limit > (smc_addr + 3)),
L_2 , return -EINVAL;) ;
F_4 ( V_26 -> V_29 , V_30 , V_27 ) ;
F_5 ( V_26 -> V_29 , V_31 , V_32 , 0 ) ;
return 0 ;
}
int F_6 ( struct V_25 * V_26 ,
T_1 V_33 , const T_2 * V_34 ,
T_1 V_35 , T_1 V_28 )
{
int V_3 ;
T_1 V_36 , V_37 ;
T_1 V_38 , V_39 ;
F_3 ((0 == (3 & smcStartAddress)),
L_1 , return -EINVAL;) ;
F_3 ((limit > (smcStartAddress + byteCount)),
L_2 , return -EINVAL;) ;
V_38 = V_33 ;
while ( V_35 >= 4 ) {
V_36 = V_34 [ 0 ] * 0x1000000 + V_34 [ 1 ] * 0x10000 + V_34 [ 2 ] * 0x100 + V_34 [ 3 ] ;
V_3 = F_2 ( V_26 , V_38 , V_28 ) ;
if ( V_3 )
return V_3 ;
F_4 ( V_26 -> V_29 , V_40 , V_36 ) ;
V_34 += 4 ;
V_35 -= 4 ;
V_38 += 4 ;
}
if ( V_35 ) {
V_36 = 0 ;
V_3 = F_2 ( V_26 , V_38 , V_28 ) ;
if ( V_3 )
return V_3 ;
V_37 = F_7 ( V_26 -> V_29 , V_40 ) ;
V_39 = 8 * ( 4 - V_35 ) ;
while ( V_35 > 0 ) {
V_36 = ( 0x100 * V_36 ) + * V_34 ++ ;
V_35 -- ;
}
V_36 <<= V_39 ;
V_36 |= ( V_37 & ~ ( ( ~ 0UL ) << V_39 ) ) ;
V_3 = F_2 ( V_26 , V_38 , V_28 ) ;
if ( ! V_3 )
return V_3 ;
F_4 ( V_26 -> V_29 , V_40 , V_36 ) ;
}
return 0 ;
}
int F_8 ( struct V_25 * V_26 )
{
static unsigned char V_36 [] = { 0xE0 , 0x00 , 0x80 , 0x40 } ;
F_6 ( V_26 , 0x0 , V_36 , 4 , sizeof( V_36 ) + 1 ) ;
return 0 ;
}
bool F_9 ( struct V_25 * V_26 )
{
return ( ( 0 == F_10 ( V_26 -> V_29 ,
V_41 ,
V_42 , V_43 ) )
&& ( 0x20100 <= F_11 ( V_26 -> V_29 ,
V_41 , V_44 ) ) ) ;
}
int F_12 ( struct V_25 * V_26 , T_3 V_45 )
{
if ( ! F_9 ( V_26 ) )
return - 1 ;
if ( 1 != F_13 ( V_26 -> V_29 , V_46 , V_47 ) ) {
F_14 ( V_48 L_3 ) ;
F_15 ( V_26 , V_46 , V_47 , 0 ) ;
}
F_4 ( V_26 -> V_29 , V_49 , V_45 ) ;
F_15 ( V_26 , V_46 , V_47 , 0 ) ;
return 0 ;
}
int F_16 ( struct V_25 * V_26 ,
T_3 V_45 , T_1 V_50 )
{
if ( ! F_9 ( V_26 ) )
return - 1 ;
if ( 1 != F_13 ( V_26 -> V_29 , V_46 , V_47 ) ) {
F_14 ( V_48 L_3 ) ;
F_15 ( V_26 , V_46 , V_47 , 0 ) ;
}
F_4 ( V_26 -> V_29 , V_51 , V_50 ) ;
F_4 ( V_26 -> V_29 , V_49 , V_45 ) ;
F_15 ( V_26 , V_46 , V_47 , 0 ) ;
return 0 ;
}
int F_17 (
struct V_25 * V_26 , T_3 V_45 , T_1 V_50 )
{
if ( 1 != F_13 ( V_26 -> V_29 , V_46 , V_47 ) ) {
F_14 ( V_48 L_3 ) ;
F_15 ( V_26 , V_46 , V_47 , 0 ) ;
}
F_4 ( V_26 -> V_29 , V_51 , V_50 ) ;
F_4 ( V_26 -> V_29 , V_49 , V_45 ) ;
return 0 ;
}
static int F_18 ( struct V_25 * V_26 )
{
const T_2 * V_34 ;
T_1 V_52 ;
T_1 * V_36 ;
struct V_53 V_54 = { 0 } ;
F_19 ( V_26 -> V_29 ,
F_1 ( V_5 ) , & V_54 ) ;
if ( V_54 . V_55 & 3 ) {
F_14 ( V_48 L_4 ) ;
return - V_56 ;
}
if ( V_54 . V_55 > V_57 ) {
F_14 ( V_48 L_5 ) ;
return - V_56 ;
}
F_4 ( V_26 -> V_29 , V_30 , 0x20000 ) ;
F_5 ( V_26 -> V_29 , V_31 , V_32 , 1 ) ;
V_52 = V_54 . V_55 ;
V_34 = ( const T_2 * ) V_54 . V_58 ;
V_36 = ( T_1 * ) V_34 ;
for (; V_52 >= 4 ; V_36 ++ , V_52 -= 4 )
F_4 ( V_26 -> V_29 , V_40 , V_36 [ 0 ] ) ;
F_5 ( V_26 -> V_29 , V_31 , V_32 , 0 ) ;
return 0 ;
}
int F_20 ( struct V_25 * V_26 , T_1 V_27 ,
T_1 * V_59 , T_1 V_28 )
{
int V_3 = F_2 ( V_26 , V_27 , V_28 ) ;
if ( V_3 )
return V_3 ;
* V_59 = F_7 ( V_26 -> V_29 , V_40 ) ;
return 0 ;
}
int F_21 ( struct V_25 * V_26 , T_1 V_27 ,
T_1 V_59 , T_1 V_28 )
{
int V_3 ;
V_3 = F_2 ( V_26 , V_27 , V_28 ) ;
if ( V_3 )
return V_3 ;
F_4 ( V_26 -> V_29 , V_40 , V_59 ) ;
return 0 ;
}
static T_1 F_22 ( T_1 V_2 )
{
T_1 V_3 = 0 ;
switch ( V_2 ) {
case V_7 :
V_3 = V_60 ;
break;
case V_9 :
V_3 = V_61 ;
break;
case V_11 :
V_3 = V_62 ;
break;
case V_13 :
V_3 = V_63 ;
break;
case V_15 :
V_3 = V_64 ;
break;
case V_19 :
V_3 = V_65 | V_66 ;
break;
case V_21 :
V_3 = V_65 | V_67 ;
break;
case V_23 :
V_3 = V_68 ;
break;
default:
F_14 ( V_48 L_6 ) ;
V_3 = 0 ;
}
return V_3 ;
}
static int F_23 ( struct V_25 * V_26 ,
T_1 V_2 , struct V_69 * V_70 )
{
int V_3 ;
struct V_53 V_54 = { 0 } ;
V_3 = F_19 (
V_26 -> V_29 ,
F_1 ( V_2 ) ,
& V_54 ) ;
if ( ! V_3 ) {
V_70 -> V_71 = 0 ;
V_70 -> V_72 = ( T_3 ) V_2 ;
V_70 -> V_73 = F_24 ( V_54 . V_74 ) ;
V_70 -> V_75 = F_25 ( V_54 . V_74 ) ;
V_70 -> V_76 = 0 ;
V_70 -> V_77 = 0 ;
V_70 -> V_78 = V_54 . V_55 ;
V_70 -> V_79 = 0 ;
if ( V_2 == V_23 )
V_70 -> V_80 = 1 ;
else
V_70 -> V_80 = 0 ;
}
return V_3 ;
}
static int F_26 ( struct V_25 * V_26 )
{
struct V_81 * V_82 = (struct V_81 * ) ( V_26 -> V_83 ) ;
T_1 V_84 ;
struct V_85 * V_86 ;
if ( V_82 -> V_87 )
F_27 ( V_26 -> V_29 , V_41 ,
V_82 -> V_87 +
F_28 ( V_88 , V_89 ) ,
0x0 ) ;
V_86 = (struct V_85 * ) V_82 -> V_90 ;
V_86 -> V_91 = 0 ;
V_86 -> V_92 = 1 ;
F_3 (
0 == fiji_populate_single_firmware_entry(smumgr,
UCODE_ID_RLC_G, &toc->entry[toc->num_entries++]),
L_7 , return -1 ) ;
F_3 (
0 == fiji_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_CE, &toc->entry[toc->num_entries++]),
L_7 , return -1 ) ;
F_3 (
0 == fiji_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_PFP, &toc->entry[toc->num_entries++]),
L_7 , return -1 ) ;
F_3 (
0 == fiji_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_ME, &toc->entry[toc->num_entries++]),
L_7 , return -1 ) ;
F_3 (
0 == fiji_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_MEC, &toc->entry[toc->num_entries++]),
L_7 , return -1 ) ;
F_3 (
0 == fiji_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_MEC_JT1, &toc->entry[toc->num_entries++]),
L_7 , return -1 ) ;
F_3 (
0 == fiji_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_MEC_JT2, &toc->entry[toc->num_entries++]),
L_7 , return -1 ) ;
F_3 (
0 == fiji_populate_single_firmware_entry(smumgr,
UCODE_ID_SDMA0, &toc->entry[toc->num_entries++]),
L_7 , return -1 ) ;
F_3 (
0 == fiji_populate_single_firmware_entry(smumgr,
UCODE_ID_SDMA1, &toc->entry[toc->num_entries++]),
L_7 , return -1 ) ;
F_16 ( V_26 , V_93 ,
V_82 -> V_94 . V_95 ) ;
F_16 ( V_26 , V_96 ,
V_82 -> V_94 . V_97 ) ;
V_84 = V_68
+ V_60
+ V_61
+ V_62
+ V_64
+ V_63
+ V_65
+ V_66
+ V_67 ;
if ( F_16 ( V_26 ,
V_98 , V_84 ) )
F_14 ( V_48 L_8 ) ;
return 0 ;
}
static int F_29 ( struct V_25 * V_26 ,
T_1 V_2 )
{
struct V_81 * V_82 = (struct V_81 * ) ( V_26 -> V_83 ) ;
T_1 V_99 = F_22 ( V_2 ) ;
if ( F_30 ( V_26 , V_100 ,
V_82 -> V_87 +
F_28 ( V_88 , V_89 ) ,
V_99 , V_99 ) ) {
F_14 ( V_48 L_9 ) ;
return - V_56 ;
}
return 0 ;
}
static int F_31 ( struct V_25 * V_26 )
{
return V_26 -> V_101 -> V_102 ( V_26 ) ;
}
static bool F_32 ( struct V_25 * V_26 )
{
T_1 V_59 ;
V_59 = F_7 ( V_26 -> V_29 , V_103 ) ;
if ( V_59 & V_104 ) {
return true ;
}
return false ;
}
static int F_33 ( struct V_25 * V_26 , T_1 V_2 )
{
if ( F_32 ( V_26 ) ) {
T_1 V_105 = F_22 ( V_2 ) ;
if ( F_17 ( V_26 ,
V_98 , V_105 ) )
F_14 ( V_48 L_8 ) ;
}
return 0 ;
}
static int F_34 ( struct V_25 * V_26 )
{
int V_3 = 0 ;
F_35 ( V_26 -> V_29 , V_41 ,
V_106 , V_107 , 1 ) ;
V_3 = F_18 ( V_26 ) ;
if ( V_3 )
return V_3 ;
F_27 ( V_26 -> V_29 , V_41 ,
V_108 , 0 ) ;
F_35 ( V_26 -> V_29 , V_41 ,
V_42 , V_43 , 0 ) ;
F_35 ( V_26 -> V_29 , V_41 ,
V_106 , V_107 , 0 ) ;
F_35 ( V_26 -> V_29 , V_41 ,
V_109 , V_110 , 1 ) ;
F_27 ( V_26 -> V_29 , V_41 ,
V_111 , 0 ) ;
F_36 ( V_26 , V_112 , V_113 ,
V_114 , 1 ) ;
F_4 ( V_26 -> V_29 , V_51 , 0x20000 ) ;
F_4 ( V_26 -> V_29 , V_49 , V_115 ) ;
F_15 ( V_26 , V_46 , V_47 , 0 ) ;
F_37 ( V_26 , V_112 ,
V_116 , V_117 , 0 ) ;
if ( 1 != F_10 ( V_26 -> V_29 , V_41 ,
V_116 , V_118 ) ) {
F_3 (false,
L_10 , return -1 ) ;
}
F_36 ( V_26 , V_112 ,
V_119 , V_114 , 1 ) ;
return V_3 ;
}
static int F_38 ( struct V_25 * V_26 )
{
int V_3 = 0 ;
F_37 ( V_26 , V_112 ,
V_113 , V_120 , 0 ) ;
F_27 ( V_26 -> V_29 , V_41 ,
V_111 , 0 ) ;
F_35 ( V_26 -> V_29 , V_41 ,
V_106 , V_107 , 1 ) ;
V_3 = F_18 ( V_26 ) ;
if ( V_3 )
return V_3 ;
F_8 ( V_26 ) ;
F_35 ( V_26 -> V_29 , V_41 ,
V_42 , V_43 , 0 ) ;
F_35 ( V_26 -> V_29 , V_41 ,
V_106 , V_107 , 0 ) ;
F_36 ( V_26 , V_112 ,
V_119 , V_114 , 1 ) ;
return V_3 ;
}
int F_39 ( struct V_25 * V_26 )
{
int V_121 , V_3 = - 1 ;
T_1 V_122 , V_36 ;
T_4 * V_123 = V_124 ;
struct V_81 * V_82 = (struct V_81 * ) ( V_26 -> V_83 ) ;
V_82 -> V_125 . V_126 = V_127 ;
for ( V_121 = 0 ; ( V_121 < V_128 ) ; V_121 ++ ) {
switch ( V_123 -> V_129 ) {
case V_130 :
V_122 = V_123 -> V_122 ;
V_36 = V_123 -> V_36 ;
F_4 ( V_26 -> V_29 , V_122 , V_36 ) ;
break;
case V_131 :
V_82 -> V_125 . V_126 = V_132 ;
V_3 = 0 ;
break;
default:
F_14 ( V_48 L_11 ) ;
V_82 -> V_125 . V_126 = V_133 ;
V_3 = - 1 ;
break;
}
V_123 ++ ;
}
return V_3 ;
}
static int F_40 ( struct V_25 * V_26 )
{
int V_3 = 0 ;
struct V_81 * V_82 = (struct V_81 * ) ( V_26 -> V_83 ) ;
V_82 -> V_125 . V_126 = V_134 ;
if ( V_82 -> V_125 . V_135 ) {
if ( ! F_16 ( V_26 ,
V_136 , V_82 -> V_125 . V_135 ) ) {
if ( ! F_12 ( V_26 , V_137 ) ) {
V_82 -> V_125 . V_126 = V_138 ;
V_3 = 0 ;
} else {
F_14 ( V_48 L_12
L_13 ) ;
F_12 ( V_26 , V_139 ) ;
V_3 = - 1 ;
}
} else {
F_14 ( V_48 L_14
L_15 ) ;
V_3 = - 1 ;
}
}
F_4 ( V_26 -> V_29 , V_140 , 0x50000000 ) ;
F_4 ( V_26 -> V_29 , V_141 , 0xffffffff ) ;
F_4 ( V_26 -> V_29 , V_141 , 0 ) ;
return V_3 ;
}
int F_41 ( struct V_25 * V_26 )
{
int V_3 = 0 ;
T_1 V_142 ;
T_1 V_143 , V_144 , V_145 ;
T_3 V_146 ;
V_145 = 0x30750000 ;
V_146 = 0x1A04 ;
F_3 ( 0 == fiji_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION + offsetof(SMU73_Firmware_Header,
PmFuseTable), &table_start, 0x40000),
L_16
L_17 ,
return -1;) ;
V_143 = V_142 +
F_28 ( struct V_147 , V_148 ) ;
V_144 = V_142 +
F_28 ( struct V_147 , V_149 ) ;
V_3 = F_6 ( V_26 , V_143 ,
( T_2 * ) ( & V_145 ) , sizeof( V_145 ) , 0x40000 ) ;
F_3 ( 0 == result,
L_18
L_19 , return -1;) ;
V_3 = F_6 ( V_26 , V_144 ,
( T_2 * ) ( & V_146 ) , sizeof( V_146 ) , 0x40000 ) ;
F_3 ( 0 == result, L_20
L_21 , return -1;) ;
return V_3 ;
}
int F_42 ( struct V_25 * V_26 )
{
T_5 V_150 ;
T_1 V_142 ;
T_1 V_151 , V_152 ;
T_1 V_153 = sizeof( V_154 ) ;
F_3 ( 0 == fiji_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION +
offsetof(SMU73_Firmware_Header, DpmTable),
&table_start, 0x40000),
L_22
L_23 ,
return -1;) ;
V_150 = 0x01000500 ;
V_152 = V_142 +
F_28 ( V_155 , V_156 ) ;
F_3 ( 0 == fiji_copy_bytes_to_smc(smumgr, vr_config_addr,
(uint8_t *)&vr_config, sizeof(int32_t), 0x40000),
L_24
L_25 ,
return -1;) ;
V_151 = V_142 + F_28 ( V_155 , V_157 ) ;
F_3 ( 0 == fiji_copy_bytes_to_smc(smumgr, level_addr,
(uint8_t *)(&avfs_graphics_level), level_size, 0x40000),
L_26 ,
return -1;) ;
return 0 ;
}
int F_43 ( struct V_25 * V_26 )
{
struct V_81 * V_82 = (struct V_81 * ) ( V_26 -> V_83 ) ;
if ( V_158 == V_82 -> V_125 . V_126 ) {
V_82 -> V_125 . V_126 = V_159 ;
return 0 ;
} else
return - V_56 ;
}
int F_44 ( struct V_25 * V_26 )
{
struct V_81 * V_82 = (struct V_81 * ) ( V_26 -> V_83 ) ;
if ( V_158 == V_82 -> V_125 . V_126 ) {
V_82 -> V_125 . V_126 = V_159 ;
return 0 ;
} else
return - V_56 ;
}
int F_45 ( struct V_25 * V_26 , bool V_160 )
{
struct V_81 * V_82 = (struct V_81 * ) ( V_26 -> V_83 ) ;
switch ( V_82 -> V_125 . V_126 ) {
case V_158 :
V_82 -> V_125 . V_126 = V_161 ;
F_3 ( 0 == fiji_restore_vft_table(smumgr),
L_27
L_28 ,
return -1;) ;
V_82 -> V_125 . V_126 = V_159 ;
break;
case V_159 :
V_82 -> V_125 . V_126 = V_162 ;
F_3 ( 0 == fiji_send_msg_to_smc(smumgr,
PPSMC_MSG_VftTableIsValid),
L_29
L_30 ,
return -1;) ;
V_82 -> V_125 . V_126 = V_162 ;
F_3 ( 0 == fiji_send_msg_to_smc(smumgr,
PPSMC_MSG_EnableAvfs),
L_29
L_31 ,
return -1;) ;
V_82 -> V_125 . V_126 = V_158 ;
break;
case V_163 :
if ( ! V_160 )
break;
V_82 -> V_125 . V_126 = V_164 ;
F_3 ( 0 == fiji_setup_pm_fuse_for_avfs(smumgr),
L_32
L_33 ,
return -1;) ;
V_82 -> V_125 . V_126 = V_165 ;
F_3 ( 0 == fiji_setup_graphics_level_structure(smumgr),
L_34
L_35 ,
return -1;) ;
V_82 -> V_125 . V_126 = V_133 ;
F_3 ( 0 == fiji_setup_pwr_virus(smumgr),
L_36
L_37 ,
return -1;) ;
V_82 -> V_125 . V_126 = V_164 ;
F_3 ( 0 == fiji_start_avfs_btc(smumgr),
L_32
L_38 ,
return -1;) ;
V_82 -> V_125 . V_126 = V_166 ;
F_3 ( 0 == fiji_save_vft_table(smumgr),
L_39 ,
return -1;) ;
V_82 -> V_125 . V_126 = V_158 ;
break;
case V_167 :
break;
case V_168 :
break;
default:
F_14 ( V_48 L_40 ) ;
break;
}
return 0 ;
}
static int F_46 ( struct V_25 * V_26 )
{
int V_3 = 0 ;
struct V_81 * V_82 = (struct V_81 * ) ( V_26 -> V_83 ) ;
if ( ! F_9 ( V_26 ) ) {
F_45 ( V_26 , false ) ;
if ( 0 == F_10 ( V_26 -> V_29 ,
V_41 ,
V_169 , V_170 ) ) {
V_3 = F_38 ( V_26 ) ;
if ( V_3 )
return V_3 ;
} else {
V_3 = F_34 ( V_26 ) ;
if ( V_3 )
return V_3 ;
}
F_45 ( V_26 , true ) ;
}
F_47 ( V_26 -> V_29 ,
V_171 , V_172 ) ;
F_47 ( V_26 -> V_29 ,
V_173 , V_172 ) ;
F_47 ( V_26 -> V_29 ,
V_174 , V_172 ) ;
F_47 ( V_26 -> V_29 ,
V_175 , V_172 ) ;
F_20 ( V_26 ,
V_176 +
F_28 ( V_177 , V_178 ) ,
& ( V_82 -> V_87 ) , 0x40000 ) ;
V_3 = F_26 ( V_26 ) ;
return V_3 ;
}
static bool F_48 ( struct V_25 * V_26 )
{
T_1 V_179 = 0 ;
T_1 V_99 = ( 1 << ( ( V_180 - V_181 ) + 1 ) ) - 1 ;
if ( ! F_49 ( V_26 -> V_29 , V_181 , V_180 ,
V_99 , & V_179 ) ) {
if ( V_179 )
return true ;
}
return false ;
}
static int F_50 ( struct V_25 * V_26 )
{
struct V_81 * V_82 = (struct V_81 * ) ( V_26 -> V_83 ) ;
T_6 V_74 ;
V_82 -> V_94 . V_182 =
( ( sizeof( struct V_85 ) / 4096 ) + 1 ) * 4096 ;
F_51 ( V_26 -> V_29 ,
V_82 -> V_94 . V_182 ,
V_183 ,
V_184 ,
& V_74 ,
& V_82 -> V_94 . V_185 ,
& V_82 -> V_94 . V_186 ) ;
V_82 -> V_90 = V_82 -> V_94 . V_185 ;
V_82 -> V_94 . V_95 = F_24 ( V_74 ) ;
V_82 -> V_94 . V_97 = F_25 ( V_74 ) ;
F_3 ((NULL != priv->header),
L_41 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)priv->header_buffer.handle);
return -1 ) ;
V_82 -> V_125 . V_126 = V_163 ;
if ( F_48 ( V_26 ) )
V_82 -> V_125 . V_135 = 0 ;
else
V_82 -> V_125 . V_126 = V_168 ;
V_82 -> V_187 = 1 ;
return 0 ;
}
static int F_52 ( struct V_25 * V_26 )
{
if ( V_26 -> V_83 ) {
F_53 ( V_26 -> V_83 ) ;
V_26 -> V_83 = NULL ;
}
return 0 ;
}
int F_54 ( struct V_25 * V_26 )
{
struct V_81 * V_188 = NULL ;
V_188 = F_55 ( sizeof( struct V_81 ) , V_189 ) ;
if ( V_188 == NULL )
return - V_190 ;
V_26 -> V_83 = V_188 ;
V_26 -> V_101 = & V_191 ;
return 0 ;
}
