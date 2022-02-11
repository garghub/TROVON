static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ((0 == (3 & smc_addr)), L_1 , return -EINVAL) ;
F_2 ((limit > (smc_addr + 3)), L_2 , return -EINVAL) ;
F_3 ( V_2 -> V_5 , V_6 , V_3 ) ;
F_4 ( V_2 -> V_5 , V_7 , V_8 , 0 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 V_9 , T_1 * V_10 , T_1 V_11 , T_1 V_4 )
{
T_1 V_12 ;
T_1 V_13 ;
T_2 * V_14 ;
T_2 V_15 , V_16 [ 4 ] = { 0 } ;
T_1 * V_17 = ( T_1 * ) & V_16 ;
F_2 ((0 == (3 & smc_start_address)), L_1 , return -1;) ;
F_2 ((limit > (smc_start_address + byte_count)), L_3 , return -1 ) ;
V_13 = V_9 ;
while ( V_11 >= 4 ) {
F_6 ( V_2 , V_13 , & V_12 , V_4 ) ;
* V_10 = F_7 ( V_12 ) ;
V_10 += 1 ;
V_11 -= 4 ;
V_13 += 4 ;
}
if ( V_11 ) {
F_6 ( V_2 , V_13 , & V_12 , V_4 ) ;
* V_17 = F_7 ( V_12 ) ;
V_14 = ( T_2 * ) V_10 ;
for ( V_15 = 0 ; V_15 < V_11 ; V_15 ++ )
V_14 [ V_15 ] = V_16 [ V_15 ] ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 V_9 ,
const T_2 * V_18 , T_1 V_11 , T_1 V_4 )
{
int V_19 ;
T_1 V_12 = 0 ;
T_1 V_20 ;
T_1 V_13 = 0 ;
T_1 V_21 ;
F_2 ((0 == (3 & smc_start_address)), L_1 , return -1 ) ;
F_2 ((limit > (smc_start_address + byte_count)), L_3 , return -1 ) ;
V_13 = V_9 ;
while ( V_11 >= 4 ) {
V_12 = V_18 [ 0 ] * 0x1000000 + V_18 [ 1 ] * 0x10000 + V_18 [ 2 ] * 0x100 + V_18 [ 3 ] ;
V_19 = F_1 ( V_2 , V_13 , V_4 ) ;
if ( 0 != V_19 )
return V_19 ;
F_3 ( V_2 -> V_5 , V_22 , V_12 ) ;
V_18 += 4 ;
V_11 -= 4 ;
V_13 += 4 ;
}
if ( 0 != V_11 ) {
V_12 = 0 ;
V_19 = F_1 ( V_2 , V_13 , V_4 ) ;
if ( 0 != V_19 )
return V_19 ;
V_20 = F_9 ( V_2 -> V_5 , V_22 ) ;
V_21 = 8 * ( 4 - V_11 ) ;
while ( V_11 > 0 ) {
V_12 = ( 0x100 * V_12 ) + * V_18 ++ ;
V_11 -- ;
}
V_12 <<= V_21 ;
V_12 |= ( V_20 & ~ ( ( ~ 0UL ) << V_21 ) ) ;
V_19 = F_1 ( V_2 , V_13 , V_4 ) ;
if ( 0 != V_19 )
return V_19 ;
F_3 ( V_2 -> V_5 , V_22 , V_12 ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
static const unsigned char V_12 [ 4 ] = { 0xE0 , 0x00 , 0x80 , 0x40 } ;
F_8 ( V_2 , 0x0 , V_12 , 4 , sizeof( V_12 ) + 1 ) ;
return 0 ;
}
bool F_11 ( struct V_1 * V_2 )
{
return ( ( 0 == F_12 ( V_2 -> V_5 , V_23 , V_24 , V_25 ) )
&& ( 0x20100 <= F_13 ( V_2 -> V_5 , V_23 , V_26 ) ) ) ;
}
static bool F_14 ( struct V_1 * V_2 )
{
T_1 V_27 ;
V_27 = F_13 ( V_2 -> V_5 , V_23 , V_28 + ( 49 * 4 ) ) ;
V_27 &= 0x00000001 ;
if ( V_27 )
return true ;
return false ;
}
int F_15 ( struct V_1 * V_2 , T_3 V_29 )
{
int V_30 ;
if ( ! F_11 ( V_2 ) )
return - 1 ;
F_16 ( V_2 , V_31 , V_32 , 0 ) ;
V_30 = F_17 ( V_2 -> V_5 , V_31 , V_32 ) ;
if ( V_30 != 1 )
F_18 ( L_4 , V_29 , V_30 ) ;
F_3 ( V_2 -> V_5 , V_33 , V_29 ) ;
F_16 ( V_2 , V_31 , V_32 , 0 ) ;
V_30 = F_17 ( V_2 -> V_5 , V_31 , V_32 ) ;
if ( V_30 != 1 )
F_18 ( L_5 , V_29 , V_30 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , T_3 V_29 )
{
F_3 ( V_2 -> V_5 , V_33 , V_29 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , T_3 V_29 , T_1 V_34 )
{
if ( ! F_11 ( V_2 ) ) {
return - 1 ;
}
F_16 ( V_2 , V_31 , V_32 , 0 ) ;
F_3 ( V_2 -> V_5 , V_35 , V_34 ) ;
return F_15 ( V_2 , V_29 ) ;
}
int F_21 ( struct V_1 * V_2 , T_3 V_29 , T_1 V_34 )
{
F_3 ( V_2 -> V_5 , V_35 , V_34 ) ;
return F_19 ( V_2 , V_29 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_5 , V_35 , 0x20000 ) ;
F_3 ( V_2 -> V_5 , V_33 , V_36 ) ;
F_16 ( V_2 , V_31 , V_32 , 0 ) ;
if ( 1 != F_17 ( V_2 -> V_5 , V_31 , V_32 ) )
F_18 ( L_6 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
if ( ! F_11 ( V_2 ) )
return - 1 ;
F_24 ( V_2 , V_37 , V_24 , V_38 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_39 , T_1 * V_18 , T_1 V_4 )
{
T_1 V_11 = V_39 ;
F_2 ((limit >= byte_count), L_3 , return -1 ) ;
F_3 ( V_2 -> V_5 , V_6 , 0x20000 ) ;
F_4 ( V_2 -> V_5 , V_7 , V_8 , 1 ) ;
for (; V_11 >= 4 ; V_11 -= 4 )
F_3 ( V_2 -> V_5 , V_22 , * V_18 ++ ) ;
F_4 ( V_2 -> V_5 , V_7 , V_8 , 0 ) ;
F_2 ((0 == byte_count), L_7 , return -1 ) ;
return 0 ;
}
static enum V_40 F_26 ( T_1 V_41 )
{
enum V_40 V_19 = V_42 ;
switch ( V_41 ) {
case V_43 :
V_19 = V_44 ;
break;
case V_45 :
V_19 = V_46 ;
break;
case V_47 :
V_19 = V_48 ;
break;
case V_49 :
V_19 = V_50 ;
break;
case V_51 :
V_19 = V_52 ;
break;
case V_53 :
V_19 = V_54 ;
break;
case V_55 :
V_19 = V_56 ;
break;
case V_57 :
V_19 = V_58 ;
break;
case V_59 :
V_19 = V_60 ;
break;
case V_61 :
V_19 = V_62 ;
break;
case V_63 :
V_19 = V_64 ;
break;
default:
break;
}
return V_19 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_19 = 0 ;
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
struct V_68 V_69 = { 0 } ;
if ( V_66 -> V_70 == 1 )
F_28 ( V_2 -> V_5 ,
F_26 ( V_43 ) , & V_69 ) ;
else
F_28 ( V_2 -> V_5 ,
F_26 ( V_45 ) , & V_69 ) ;
V_19 = F_25 ( V_2 , V_69 . V_71 , ( T_1 * ) V_69 . V_72 , V_73 ) ;
return V_19 ;
}
int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_74 , T_1 V_4 )
{
int V_19 ;
V_19 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_19 )
return V_19 ;
* V_74 = F_9 ( V_2 -> V_5 , V_22 ) ;
return 0 ;
}
int F_29 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_74 , T_1 V_4 )
{
int V_19 ;
V_19 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_19 )
return V_19 ;
F_3 ( V_2 -> V_5 , V_22 , V_74 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 ) {
F_31 ( V_2 -> V_67 ) ;
V_2 -> V_67 = NULL ;
}
F_32 ( V_2 -> V_5 , V_44 ) ;
return 0 ;
}
static T_1 F_33 ( T_1 V_41 )
{
T_1 V_19 = 0 ;
switch ( V_41 ) {
case V_47 :
V_19 = V_75 ;
break;
case V_49 :
V_19 = V_76 ;
break;
case V_51 :
V_19 = V_77 ;
break;
case V_53 :
V_19 = V_78 ;
break;
case V_55 :
V_19 = V_79 ;
break;
case V_59 :
case V_61 :
V_19 = V_80 ;
break;
case V_63 :
V_19 = V_81 ;
break;
default:
F_18 ( L_8 ) ;
V_19 = 0 ;
}
return V_19 ;
}
static int F_34 ( struct V_1 * V_2 ,
T_1 V_41 ,
struct V_82 * V_83 )
{
int V_19 = 0 ;
struct V_68 V_69 = { 0 } ;
V_19 = F_28 ( V_2 -> V_5 ,
F_26 ( V_41 ) ,
& V_69 ) ;
if ( ! V_19 ) {
V_83 -> V_84 = V_69 . V_84 ;
V_83 -> V_85 = ( T_3 ) V_41 ;
V_83 -> V_86 = F_35 ( V_69 . V_87 ) ;
V_83 -> V_88 = F_36 ( V_69 . V_87 ) ;
V_83 -> V_89 = 0 ;
V_83 -> V_90 = 0 ;
V_83 -> V_91 = V_69 . V_71 ;
V_83 -> V_92 = 0 ;
}
if ( V_41 == V_63 )
V_83 -> V_93 = 1 ;
else
V_83 -> V_93 = 0 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
T_1 V_94 ;
int V_19 = 0 ;
struct V_95 * V_96 ;
if ( ! V_2 -> V_97 ) {
F_18 ( V_98 L_9 ) ;
return 0 ;
}
if ( V_66 -> V_99 )
F_38 ( V_2 -> V_5 , V_23 ,
V_66 -> V_99 + F_39 ( V_100 , V_101 ) ,
0x0 ) ;
F_20 ( V_2 , V_102 , V_66 -> V_103 . V_104 ) ;
F_20 ( V_2 , V_105 , V_66 -> V_103 . V_106 ) ;
V_96 = (struct V_95 * ) V_66 -> V_107 ;
V_96 -> V_108 = 0 ;
V_96 -> V_109 = 1 ;
F_2 ( 0 == polaris10_populate_single_firmware_entry(smumgr, UCODE_ID_RLC_G, &toc->entry[toc->num_entries++]), L_10 , return -1 ) ;
F_2 ( 0 == polaris10_populate_single_firmware_entry(smumgr, UCODE_ID_CP_CE, &toc->entry[toc->num_entries++]), L_10 , return -1 ) ;
F_2 ( 0 == polaris10_populate_single_firmware_entry(smumgr, UCODE_ID_CP_PFP, &toc->entry[toc->num_entries++]), L_10 , return -1 ) ;
F_2 ( 0 == polaris10_populate_single_firmware_entry(smumgr, UCODE_ID_CP_ME, &toc->entry[toc->num_entries++]), L_10 , return -1 ) ;
F_2 ( 0 == polaris10_populate_single_firmware_entry(smumgr, UCODE_ID_CP_MEC, &toc->entry[toc->num_entries++]), L_10 , return -1 ) ;
F_2 ( 0 == polaris10_populate_single_firmware_entry(smumgr, UCODE_ID_CP_MEC_JT1, &toc->entry[toc->num_entries++]), L_10 , return -1 ) ;
F_2 ( 0 == polaris10_populate_single_firmware_entry(smumgr, UCODE_ID_CP_MEC_JT2, &toc->entry[toc->num_entries++]), L_10 , return -1 ) ;
F_2 ( 0 == polaris10_populate_single_firmware_entry(smumgr, UCODE_ID_SDMA0, &toc->entry[toc->num_entries++]), L_10 , return -1 ) ;
F_2 ( 0 == polaris10_populate_single_firmware_entry(smumgr, UCODE_ID_SDMA1, &toc->entry[toc->num_entries++]), L_10 , return -1 ) ;
F_20 ( V_2 , V_110 , V_66 -> V_111 . V_104 ) ;
F_20 ( V_2 , V_112 , V_66 -> V_111 . V_106 ) ;
V_94 = V_81
+ V_75
+ V_76
+ V_77
+ V_79
+ V_78
+ V_80 ;
if ( F_20 ( V_2 , V_113 , V_94 ) )
F_18 ( V_114 L_11 ) ;
return V_19 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_41 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
T_1 V_115 = F_33 ( V_41 ) ;
T_1 V_30 ;
V_30 = F_41 ( V_2 , V_6 ,
V_66 -> V_99 + F_39 ( V_100 , V_101 ) ,
V_115 , V_115 ) ;
return V_30 ;
}
static int F_42 ( struct V_1 * V_2 )
{
return V_2 -> V_116 -> V_117 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_15 ;
int V_19 = - 1 ;
T_1 V_118 , V_12 ;
const T_4 * V_119 = V_120 ;
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
for ( V_15 = 0 ; V_15 < V_121 ; V_15 ++ ) {
switch ( V_119 -> V_122 ) {
case V_123 :
V_118 = V_119 -> V_118 ;
V_12 = V_119 -> V_12 ;
F_3 ( V_2 -> V_5 , V_118 , V_12 ) ;
break;
case V_124 :
V_19 = 0 ;
break;
default:
F_18 ( L_12 ) ;
V_66 -> V_125 . V_126 = V_127 ;
V_19 = - 1 ;
break;
}
V_119 ++ ;
}
return V_19 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_19 = 0 ;
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
if ( 0 != V_66 -> V_125 . V_128 ) {
if ( 0 != F_20 ( V_2 , V_129 , V_66 -> V_125 . V_128 ) ) {
F_18 ( L_13 ) ;
V_19 = - 1 ;
}
}
if ( V_66 -> V_125 . V_128 > 1 ) {
F_3 ( V_2 -> V_5 , V_130 , 0x50000000 ) ;
F_3 ( V_2 -> V_5 , V_131 , 0xffffffff ) ;
F_3 ( V_2 -> V_5 , V_131 , 0 ) ;
}
return V_19 ;
}
int F_45 ( struct V_1 * V_2 )
{
T_1 V_132 ;
T_1 V_133 ;
T_3 V_134 ;
T_1 V_135 , V_136 , V_137 ;
V_137 = sizeof( V_138 ) ;
V_134 = F_46 ( 1300 * V_139 ) ;
F_2 ( 0 == polaris10_read_smc_sram_dword(smumgr,
SMU7_FIRMWARE_HEADER_LOCATION + offsetof(SMU74_Firmware_Header, DpmTable),
&dpm_table_start, 0x40000),
L_14 ,
return -1 ) ;
V_132 = 0x01000500 ;
V_136 = V_133 + F_39 ( V_140 , V_141 ) ;
F_2 ( 0 == polaris10_copy_bytes_to_smc(smumgr, vr_config_address,
(uint8_t *)&vr_config, sizeof(uint32_t), 0x40000),
L_15 ,
return -1 ) ;
V_135 = V_133 + F_39 ( V_140 , V_142 ) ;
F_2 ( 0 == polaris10_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&avfs_graphics_level_polaris10),
graphics_level_size, 0x40000),
L_16 ,
return -1 ) ;
V_135 = V_133 + F_39 ( V_140 , V_143 ) ;
F_2 ( 0 == polaris10_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&avfs_memory_level_polaris10), sizeof(avfs_memory_level_polaris10), 0x40000),
L_17 ,
return -1 ) ;
V_135 = V_133 + F_39 ( V_140 , V_144 ) ;
F_2 ( 0 == polaris10_copy_bytes_to_smc(smumgr, graphics_level_address,
(uint8_t *)(&u16_boot_mvdd), sizeof(u16_boot_mvdd), 0x40000),
L_18 ,
return -1 ) ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , bool V_145 )
{
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
switch ( V_66 -> V_125 . V_126 ) {
case V_146 :
break;
case V_147 :
V_66 -> V_125 . V_126 = V_148 ;
F_2 ( 0 == polaris10_setup_graphics_level_structure(smumgr),
L_19 ,
return -1 ) ;
if ( V_66 -> V_125 . V_128 > 1 ) {
F_18 ( L_20 ) ;
V_66 -> V_125 . V_126 = V_127 ;
F_2 (-1 == polaris10_setup_pwr_virus(smumgr),
L_21 ,
return -1 ) ;
}
V_66 -> V_125 . V_126 = V_149 ;
F_2 ( 0 == polaris10_perform_btc(smumgr),
L_22 ,
return -1 ) ;
break;
case V_150 :
case V_151 :
break;
default:
F_18 ( L_23 ) ;
break;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
int V_19 = 0 ;
F_49 ( V_2 -> V_5 , V_23 ,
V_152 , V_153 , 1 ) ;
V_19 = F_27 ( V_2 ) ;
if ( V_19 != 0 )
return V_19 ;
F_38 ( V_2 -> V_5 , V_23 , V_154 , 0 ) ;
F_49 ( V_2 -> V_5 , V_23 ,
V_24 , V_25 , 0 ) ;
F_49 ( V_2 -> V_5 , V_23 ,
V_152 , V_153 , 0 ) ;
F_24 ( V_2 , V_37 , V_155 , V_156 , 1 ) ;
F_22 ( V_2 ) ;
F_50 ( V_2 , V_37 , V_157 , V_158 , 0 ) ;
if ( 1 != F_12 ( V_2 -> V_5 , V_23 ,
V_157 , V_159 ) )
F_2 (false, L_24 , return -1 ) ;
F_38 ( V_2 -> V_5 , V_23 , V_160 , 0 ) ;
F_49 ( V_2 -> V_5 , V_23 ,
V_152 , V_153 , 1 ) ;
F_49 ( V_2 -> V_5 , V_23 ,
V_152 , V_153 , 0 ) ;
F_24 ( V_2 , V_37 , V_161 , V_156 , 1 ) ;
return V_19 ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_19 = 0 ;
F_50 ( V_2 , V_37 , V_155 , V_162 , 0 ) ;
F_38 ( V_2 -> V_5 , V_23 ,
V_160 , 0 ) ;
F_49 ( V_2 -> V_5 , V_23 ,
V_152 ,
V_153 , 1 ) ;
V_19 = F_27 ( V_2 ) ;
if ( V_19 != 0 )
return V_19 ;
F_10 ( V_2 ) ;
F_49 ( V_2 -> V_5 , V_23 ,
V_24 , V_25 , 0 ) ;
F_49 ( V_2 -> V_5 , V_23 ,
V_152 , V_153 , 0 ) ;
F_24 ( V_2 , V_37 ,
V_161 , V_156 , 1 ) ;
return V_19 ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_19 = 0 ;
struct V_65 * V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
bool V_145 ;
if ( ! F_11 ( V_2 ) ) {
V_145 = false ;
V_66 -> V_163 = ( T_2 ) ( F_12 ( V_2 -> V_5 , V_23 , V_164 , V_165 ) ) ;
V_66 -> V_70 = ( T_2 ) ( F_12 ( V_2 -> V_5 , V_23 , V_164 , V_166 ) ) ;
if ( V_66 -> V_163 == 0 ) {
V_19 = F_51 ( V_2 ) ;
} else {
V_19 = F_48 ( V_2 ) ;
if ( V_19 != 0 ) {
V_66 -> V_70 ^= 1 ;
V_19 = F_48 ( V_2 ) ;
}
}
if ( V_19 != 0 )
F_2 ( 0 , L_25 , return result) ;
F_47 ( V_2 , true ) ;
} else
V_145 = true ;
V_66 -> V_167 = true ;
F_47 ( V_2 , V_145 ) ;
F_6 ( V_2 , V_168 + F_39 ( V_169 , V_170 ) ,
& ( V_66 -> V_99 ) , 0x40000 ) ;
V_19 = F_37 ( V_2 ) ;
return V_19 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
T_2 * V_171 ;
T_5 V_87 = 0 ;
V_66 = (struct V_65 * ) ( V_2 -> V_67 ) ;
V_66 -> V_111 . V_172 =
( ( sizeof( struct V_95 ) / 4096 ) + 1 ) * 4096 ;
V_66 -> V_103 . V_172 = 200 * 4096 ;
V_66 -> V_125 . V_126 = V_151 ;
F_54 ( V_2 -> V_5 ,
V_66 -> V_111 . V_172 ,
V_173 ,
V_174 ,
& V_87 ,
& V_66 -> V_111 . V_175 ,
& V_66 -> V_111 . V_176 ) ;
V_66 -> V_107 = V_66 -> V_111 . V_175 ;
V_66 -> V_111 . V_104 = F_35 ( V_87 ) ;
V_66 -> V_111 . V_106 = F_36 ( V_87 ) ;
F_2 ((NULL != smu_data->header),
L_26 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)smu_data->header_buffer.handle);
return -1 ) ;
F_54 ( V_2 -> V_5 ,
V_66 -> V_103 . V_172 ,
V_173 ,
V_174 ,
& V_87 ,
& V_66 -> V_103 . V_175 ,
& V_66 -> V_103 . V_176 ) ;
V_171 = V_66 -> V_103 . V_175 ;
V_66 -> V_103 . V_104 = F_35 ( V_87 ) ;
V_66 -> V_103 . V_106 = F_36 ( V_87 ) ;
F_2 ((NULL != internal_buf),
L_26 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)smu_data->smu_buffer.handle);
return -1;) ;
if ( F_14 ( V_2 ) )
V_66 -> V_125 . V_126 = V_147 ;
else
V_66 -> V_125 . V_126 = V_151 ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_65 * V_177 = NULL ;
V_177 = F_56 ( sizeof( struct V_65 ) , V_178 ) ;
if ( V_177 == NULL )
return - 1 ;
V_2 -> V_67 = V_177 ;
V_2 -> V_116 = & V_179 ;
return 0 ;
}
