static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( V_2 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
F_2 ((0 == (3 & smcAddress)),
L_1 ,
return -1;) ;
F_2 ((limit > (smcAddress + 3)),
L_2 ,
return -1;) ;
F_3 ( V_2 -> V_5 , V_7 , V_3 ) ;
F_4 ( V_2 -> V_5 , V_8 , V_9 , 0 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
T_1 V_10 , const T_2 * V_11 ,
T_1 V_12 , T_1 V_4 )
{
T_1 V_13 ;
T_1 V_14 , V_15 ;
int V_16 = 0 ;
T_1 V_17 ;
if ( V_2 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
F_2 ((0 == (3 & smcStartAddress)),
L_1 ,
return 0;) ;
F_2 ((limit > (smcStartAddress + byteCount)),
L_2 ,
return 0;) ;
V_13 = V_10 ;
while ( V_12 >= 4 ) {
V_14 = ( V_11 [ 0 ] << 24 ) + ( V_11 [ 1 ] << 16 ) + ( V_11 [ 2 ] << 8 ) + V_11 [ 3 ] ;
V_16 = F_1 ( V_2 , V_13 , V_4 ) ;
if ( V_16 )
goto V_18;
F_3 ( V_2 -> V_5 , V_19 , V_14 ) ;
V_11 += 4 ;
V_12 -= 4 ;
V_13 += 4 ;
}
if ( 0 != V_12 ) {
V_14 = 0 ;
V_16 = F_1 ( V_2 , V_13 , V_4 ) ;
if ( V_16 )
goto V_18;
V_15 = F_6 ( V_2 -> V_5 ,
V_19 ) ;
V_17 = 8 * ( 4 - V_12 ) ;
while ( V_12 > 0 ) {
V_14 = ( V_14 << 8 ) + * V_11 ++ ;
V_12 -- ;
}
V_14 <<= V_17 ;
V_14 |= ( V_15 & ~ ( ( ~ 0UL ) << V_17 ) ) ;
V_16 = F_1 ( V_2 , V_13 , V_4 ) ;
if ( V_16 )
goto V_18;
F_3 ( V_2 -> V_5 , V_19 , V_14 ) ;
}
V_18:
return V_16 ;
}
int F_7 ( struct V_1 * V_2 )
{
static unsigned char V_20 [] = { 0xE0 , 0x00 , 0x80 , 0x40 } ;
F_5 ( V_2 , 0x0 , V_20 , 4 , sizeof( V_20 ) + 1 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
return ( ( 0 == F_9 ( V_2 -> V_5 , V_21 ,
V_22 , V_23 ) )
&& ( 0x20100 <= F_10 ( V_2 -> V_5 ,
V_21 , V_24 ) ) ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
if ( V_2 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
F_12 ( V_2 , V_25 , V_26 , 0 ) ;
F_3 ( V_2 -> V_5 , V_27 , 0x20000 ) ;
F_3 ( V_2 -> V_5 , V_28 , V_29 ) ;
F_12 ( V_2 , V_25 , V_26 , 0 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_3 V_30 )
{
if ( V_2 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
if ( ! F_8 ( V_2 ) )
return - 1 ;
F_12 ( V_2 , V_25 , V_26 , 0 ) ;
F_2 (
1 == F_14 ( V_2 -> V_5 , V_25 , V_26 ) ,
L_3 ,
) ;
F_3 ( V_2 -> V_5 , V_28 , V_30 ) ;
F_12 ( V_2 , V_25 , V_26 , 0 ) ;
F_2 (
1 == F_14 ( V_2 -> V_5 , V_25 , V_26 ) ,
L_4 ,
) ;
return 0 ;
}
static int F_15
( struct V_1 * V_2 , T_3 V_30 )
{
if ( V_2 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
F_12 ( V_2 , V_25 , V_26 , 0 ) ;
F_2 (
1 == F_14 ( V_2 -> V_5 , V_25 , V_26 ) ,
L_3 ,
) ;
F_3 ( V_2 -> V_5 , V_28 , V_30 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_3 V_30 , T_1 V_31 )
{
if ( V_2 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
if ( ! F_8 ( V_2 ) )
return V_32 ;
F_12 ( V_2 , V_25 , V_26 , 0 ) ;
F_3 ( V_2 -> V_5 , V_27 , V_31 ) ;
return F_13 ( V_2 , V_30 ) ;
}
static int F_17 (
struct V_1 * V_2 ,
T_3 V_30 , T_1 V_31 )
{
if ( V_2 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
F_12 ( V_2 , V_25 , V_26 , 0 ) ;
F_3 ( V_2 -> V_5 , V_27 , V_31 ) ;
return F_15 ( V_2 , V_30 ) ;
}
int F_18 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_33 ,
T_1 V_4 )
{
int V_16 ;
V_16 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( 0 != V_16 )
return V_16 ;
* V_33 = F_6 ( V_2 -> V_5 , V_19 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_33 ,
T_1 V_4 )
{
int V_16 ;
V_16 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( 0 != V_16 )
return V_16 ;
F_3 ( V_2 -> V_5 , V_19 , V_33 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_34 != NULL ) {
F_21 ( V_2 -> V_34 ) ;
V_2 -> V_34 = NULL ;
}
return 0 ;
}
static enum V_35 F_22 ( T_1 V_36 )
{
enum V_35 V_16 = V_37 ;
switch ( V_36 ) {
case V_38 :
V_16 = V_39 ;
break;
case V_40 :
V_16 = V_41 ;
break;
case V_42 :
V_16 = V_43 ;
break;
case V_44 :
V_16 = V_45 ;
break;
case V_46 :
V_16 = V_47 ;
break;
case V_48 :
V_16 = V_49 ;
break;
case V_50 :
V_16 = V_51 ;
break;
case V_52 :
V_16 = V_53 ;
break;
case V_54 :
V_16 = V_55 ;
break;
case V_56 :
V_16 = V_57 ;
break;
default:
break;
}
return V_16 ;
}
static T_3 F_23 ( T_3 V_58 )
{
T_3 V_16 = 0 ;
switch ( V_58 ) {
case V_40 :
V_16 = V_59 ;
break;
case V_42 :
V_16 = V_60 ;
break;
case V_44 :
V_16 = V_61 ;
break;
case V_46 :
V_16 = V_62 ;
break;
case V_48 :
V_16 = V_63 ;
break;
case V_50 :
case V_52 :
case V_54 :
V_16 = V_64 ;
break;
case V_56 :
V_16 = V_65 ;
break;
default:
break;
}
return V_16 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_66 )
{
T_3 V_67 = F_23 ( V_66 ) ;
if ( 0 != F_25 ( V_2 , V_68 ,
V_69 , V_67 , V_67 ) ) {
F_26 ( V_70 L_5 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
T_3 V_71 ,
struct V_72 * V_73 )
{
int V_16 ;
struct V_74 V_75 = { 0 } ;
V_16 = F_28 (
V_2 -> V_5 ,
F_22 ( V_71 ) ,
& V_75 ) ;
if ( V_16 == 0 ) {
V_73 -> V_76 = 0 ;
V_73 -> V_77 = ( T_3 ) V_71 ;
V_73 -> V_78 = F_29 ( V_75 . V_79 ) ;
V_73 -> V_80 = F_30 ( V_75 . V_79 ) ;
V_73 -> V_81 = 0 ;
V_73 -> V_82 = 0 ;
V_73 -> V_83 = V_75 . V_84 ;
V_73 -> V_85 = 0 ;
if ( V_71 == V_56 )
V_73 -> V_86 = 1 ;
else
V_73 -> V_86 = 0 ;
} else {
return V_16 ;
}
return V_16 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_87 * V_88 =
(struct V_87 * ) ( V_2 -> V_34 ) ;
T_3 V_89 ;
int V_16 = 0 ;
struct V_90 * V_91 ;
F_32 ( V_2 -> V_5 ,
V_21 , V_92 , 0 ) ;
F_16 ( V_2 ,
V_93 ,
V_88 -> V_94 . V_95 ) ;
F_16 ( V_2 ,
V_96 ,
V_88 -> V_94 . V_97 ) ;
V_91 = (struct V_90 * ) V_88 -> V_98 ;
V_91 -> V_99 = 0 ;
V_91 -> V_100 = 1 ;
F_2 (
0 == tonga_populate_single_firmware_entry(smumgr,
UCODE_ID_RLC_G,
&toc->entry[toc->num_entries++]),
L_6 ,
return -1 ) ;
F_2 (
0 == tonga_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_CE,
&toc->entry[toc->num_entries++]),
L_6 ,
return -1 ) ;
F_2 (
0 == tonga_populate_single_firmware_entry
(smumgr, UCODE_ID_CP_PFP, &toc->entry[toc->num_entries++]),
L_6 , return -1 ) ;
F_2 (
0 == tonga_populate_single_firmware_entry
(smumgr, UCODE_ID_CP_ME, &toc->entry[toc->num_entries++]),
L_6 , return -1 ) ;
F_2 (
0 == tonga_populate_single_firmware_entry
(smumgr, UCODE_ID_CP_MEC, &toc->entry[toc->num_entries++]),
L_6 , return -1 ) ;
F_2 (
0 == tonga_populate_single_firmware_entry
(smumgr, UCODE_ID_CP_MEC_JT1, &toc->entry[toc->num_entries++]),
L_6 , return -1 ) ;
F_2 (
0 == tonga_populate_single_firmware_entry
(smumgr, UCODE_ID_CP_MEC_JT2, &toc->entry[toc->num_entries++]),
L_6 , return -1 ) ;
F_2 (
0 == tonga_populate_single_firmware_entry
(smumgr, UCODE_ID_SDMA0, &toc->entry[toc->num_entries++]),
L_6 , return -1 ) ;
F_2 (
0 == tonga_populate_single_firmware_entry
(smumgr, UCODE_ID_SDMA1, &toc->entry[toc->num_entries++]),
L_6 , return -1 ) ;
F_16 ( V_2 ,
V_101 ,
V_88 -> V_102 . V_95 ) ;
F_16 ( V_2 ,
V_103 ,
V_88 -> V_102 . V_97 ) ;
V_89 = V_65
+ V_59
+ V_60
+ V_61
+ V_63
+ V_62
+ V_64 ;
F_2 (
0 == tonga_send_msg_to_smc_with_parameter_without_waiting(
smumgr, PPSMC_MSG_LoadUcodes, fw_to_load),
L_7 , return 0 ) ;
return V_16 ;
}
static int F_33 ( struct V_1 * V_2 ,
T_1 V_58 )
{
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
const T_2 * V_11 ;
T_1 V_104 ;
T_1 * V_14 ;
struct V_74 V_75 = { 0 } ;
if ( V_2 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
F_28 ( V_2 -> V_5 ,
F_22 ( V_38 ) , & V_75 ) ;
if ( V_75 . V_84 & 3 ) {
F_26 ( V_70 L_8 ) ;
return - V_6 ;
}
if ( V_75 . V_84 > V_105 ) {
F_26 ( V_70 L_9 ) ;
return - V_6 ;
}
F_3 ( V_2 -> V_5 , V_7 , 0x20000 ) ;
F_4 ( V_2 -> V_5 , V_8 , V_106 , 1 ) ;
V_104 = V_75 . V_84 ;
V_11 = ( const T_2 * ) V_75 . V_107 ;
V_14 = ( T_1 * ) V_11 ;
for (; V_104 >= 4 ; V_14 ++ , V_104 -= 4 )
F_3 ( V_2 -> V_5 , V_19 , V_14 [ 0 ] ) ;
F_4 ( V_2 -> V_5 , V_8 , V_106 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_16 ;
F_36 ( V_2 -> V_5 , V_21 ,
V_108 , V_109 , 1 ) ;
V_16 = F_34 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_32 ( V_2 -> V_5 , V_21 ,
V_110 , 0 ) ;
F_36 ( V_2 -> V_5 , V_21 ,
V_22 , V_23 , 0 ) ;
F_36 ( V_2 -> V_5 , V_21 ,
V_108 , V_109 , 0 ) ;
F_36 ( V_2 -> V_5 , V_21 ,
V_111 , V_112 , 1 ) ;
F_32 ( V_2 -> V_5 , V_21 ,
V_113 , 0 ) ;
F_37 ( V_2 , V_68 ,
V_114 , V_115 , 1 ) ;
F_11 ( V_2 ) ;
F_38 ( V_2 , V_68 ,
V_116 , V_117 , 0 ) ;
if ( 1 != F_9 ( V_2 -> V_5 ,
V_21 , V_116 , V_118 ) ) {
F_26 ( V_70 L_10 ) ;
return - V_6 ;
}
F_37 ( V_2 , V_68 ,
V_119 , V_115 , 1 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
F_38 ( V_2 , V_68 ,
V_114 , V_120 , 0 ) ;
F_32 ( V_2 -> V_5 , V_21 ,
V_113 , 0 ) ;
F_36 ( V_2 -> V_5 , V_21 ,
V_108 , V_109 , 1 ) ;
V_16 = F_34 ( V_2 ) ;
if ( V_16 != 0 )
return V_16 ;
F_7 ( V_2 ) ;
F_36 ( V_2 -> V_5 , V_21 ,
V_22 , V_23 , 0 ) ;
F_36 ( V_2 -> V_5 , V_21 ,
V_108 , V_109 , 0 ) ;
F_37 ( V_2 , V_68 ,
V_119 , V_115 , 1 ) ;
return V_16 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_16 ;
if ( ! F_8 ( V_2 ) ) {
if ( 0 == F_9 ( V_2 -> V_5 , V_21 ,
V_121 , V_122 ) ) {
V_16 = F_39 ( V_2 ) ;
if ( V_16 )
return V_16 ;
} else {
V_16 = F_35 ( V_2 ) ;
if ( V_16 )
return V_16 ;
}
}
V_16 = F_31 ( V_2 ) ;
return V_16 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_87 * V_88 ;
T_2 * V_123 ;
T_4 V_79 = 0 ;
V_88 = (struct V_87 * ) ( V_2 -> V_34 ) ;
V_88 -> V_102 . V_124 =
( ( sizeof( struct V_90 ) / 4096 ) + 1 ) * 4096 ;
V_88 -> V_94 . V_124 = 200 * 4096 ;
F_42 ( V_2 -> V_5 ,
V_88 -> V_102 . V_124 ,
V_125 ,
V_126 ,
& V_79 ,
& V_88 -> V_102 . V_127 ,
& V_88 -> V_102 . V_128 ) ;
V_88 -> V_98 = V_88 -> V_102 . V_127 ;
V_88 -> V_102 . V_95 = F_29 ( V_79 ) ;
V_88 -> V_102 . V_97 = F_30 ( V_79 ) ;
F_2 ((NULL != tonga_smu->pHeader),
L_11 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)tonga_smu->header_buffer.handle);
return -1 ) ;
F_42 ( V_2 -> V_5 ,
V_88 -> V_94 . V_124 ,
V_125 ,
V_126 ,
& V_79 ,
& V_88 -> V_94 . V_127 ,
& V_88 -> V_94 . V_128 ) ;
V_123 = V_88 -> V_94 . V_127 ;
V_88 -> V_94 . V_95 = F_29 ( V_79 ) ;
V_88 -> V_94 . V_97 = F_30 ( V_79 ) ;
F_2 ((NULL != internal_buf),
L_11 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)tonga_smu->smu_buffer.handle);
return -1;) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = NULL ;
V_88 = F_44 ( sizeof( struct V_87 ) , V_129 ) ;
if ( V_88 == NULL )
return - V_130 ;
V_2 -> V_34 = V_88 ;
V_2 -> V_131 = & V_132 ;
return 0 ;
}
