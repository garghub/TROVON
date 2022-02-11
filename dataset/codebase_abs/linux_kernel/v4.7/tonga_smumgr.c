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
static const unsigned char V_20 [] = { 0xE0 , 0x00 , 0x80 , 0x40 } ;
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
struct V_34 * V_35 = (struct V_34 * ) ( V_2 -> V_36 ) ;
F_21 ( V_2 -> V_5 , ( void * ) V_35 -> V_37 . V_38 ) ;
F_21 ( V_2 -> V_5 , ( void * ) V_35 -> V_39 . V_38 ) ;
if ( V_2 -> V_36 != NULL ) {
F_22 ( V_2 -> V_36 ) ;
V_2 -> V_36 = NULL ;
}
F_23 ( V_2 -> V_5 , V_40 ) ;
return 0 ;
}
static enum V_41 F_24 ( T_1 V_42 )
{
enum V_41 V_16 = V_43 ;
switch ( V_42 ) {
case V_44 :
V_16 = V_40 ;
break;
case V_45 :
V_16 = V_46 ;
break;
case V_47 :
V_16 = V_48 ;
break;
case V_49 :
V_16 = V_50 ;
break;
case V_51 :
V_16 = V_52 ;
break;
case V_53 :
V_16 = V_54 ;
break;
case V_55 :
V_16 = V_56 ;
break;
case V_57 :
V_16 = V_58 ;
break;
case V_59 :
V_16 = V_60 ;
break;
case V_61 :
V_16 = V_62 ;
break;
default:
break;
}
return V_16 ;
}
static T_3 F_25 ( T_3 V_63 )
{
T_3 V_16 = 0 ;
switch ( V_63 ) {
case V_45 :
V_16 = V_64 ;
break;
case V_47 :
V_16 = V_65 ;
break;
case V_49 :
V_16 = V_66 ;
break;
case V_51 :
V_16 = V_67 ;
break;
case V_53 :
V_16 = V_68 ;
break;
case V_55 :
case V_57 :
case V_59 :
V_16 = V_69 ;
break;
case V_61 :
V_16 = V_70 ;
break;
default:
break;
}
return V_16 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_71 )
{
T_3 V_72 = F_25 ( V_71 ) ;
if ( 0 != F_27 ( V_2 , V_73 ,
V_74 , V_72 , V_72 ) ) {
F_28 ( V_75 L_5 ) ;
return - V_6 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
T_3 V_76 ,
struct V_77 * V_78 )
{
int V_16 ;
struct V_79 V_80 = { 0 } ;
V_16 = F_30 (
V_2 -> V_5 ,
F_24 ( V_76 ) ,
& V_80 ) ;
if ( V_16 == 0 ) {
V_78 -> V_81 = 0 ;
V_78 -> V_82 = ( T_3 ) V_76 ;
V_78 -> V_83 = F_31 ( V_80 . V_84 ) ;
V_78 -> V_85 = F_32 ( V_80 . V_84 ) ;
V_78 -> V_86 = 0 ;
V_78 -> V_87 = 0 ;
V_78 -> V_88 = V_80 . V_89 ;
V_78 -> V_90 = 0 ;
if ( V_76 == V_61 )
V_78 -> V_91 = 1 ;
else
V_78 -> V_91 = 0 ;
} else {
return V_16 ;
}
return V_16 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_34 * V_92 =
(struct V_34 * ) ( V_2 -> V_36 ) ;
T_3 V_93 ;
int V_16 = 0 ;
struct V_94 * V_95 ;
F_34 ( V_2 -> V_5 ,
V_21 , V_96 , 0 ) ;
F_16 ( V_2 ,
V_97 ,
V_92 -> V_37 . V_98 ) ;
F_16 ( V_2 ,
V_99 ,
V_92 -> V_37 . V_100 ) ;
V_95 = (struct V_94 * ) V_92 -> V_101 ;
V_95 -> V_102 = 0 ;
V_95 -> V_103 = 1 ;
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
V_104 ,
V_92 -> V_39 . V_98 ) ;
F_16 ( V_2 ,
V_105 ,
V_92 -> V_39 . V_100 ) ;
V_93 = V_70
+ V_64
+ V_65
+ V_66
+ V_68
+ V_67
+ V_69 ;
F_2 (
0 == tonga_send_msg_to_smc_with_parameter_without_waiting(
smumgr, PPSMC_MSG_LoadUcodes, fw_to_load),
L_7 , return 0 ) ;
return V_16 ;
}
static int F_35 ( struct V_1 * V_2 ,
T_1 V_63 )
{
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
const T_2 * V_11 ;
T_1 V_106 ;
T_1 * V_14 ;
struct V_79 V_80 = { 0 } ;
if ( V_2 == NULL || V_2 -> V_5 == NULL )
return - V_6 ;
F_30 ( V_2 -> V_5 ,
F_24 ( V_44 ) , & V_80 ) ;
if ( V_80 . V_89 & 3 ) {
F_28 ( V_75 L_8 ) ;
return - V_6 ;
}
if ( V_80 . V_89 > V_107 ) {
F_28 ( V_75 L_9 ) ;
return - V_6 ;
}
F_3 ( V_2 -> V_5 , V_7 , 0x20000 ) ;
F_4 ( V_2 -> V_5 , V_8 , V_108 , 1 ) ;
V_106 = V_80 . V_89 ;
V_11 = ( const T_2 * ) V_80 . V_109 ;
V_14 = ( T_1 * ) V_11 ;
for (; V_106 >= 4 ; V_14 ++ , V_106 -= 4 )
F_3 ( V_2 -> V_5 , V_19 , V_14 [ 0 ] ) ;
F_4 ( V_2 -> V_5 , V_8 , V_108 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_16 ;
F_38 ( V_2 -> V_5 , V_21 ,
V_110 , V_111 , 1 ) ;
V_16 = F_36 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_34 ( V_2 -> V_5 , V_21 ,
V_112 , 0 ) ;
F_38 ( V_2 -> V_5 , V_21 ,
V_22 , V_23 , 0 ) ;
F_38 ( V_2 -> V_5 , V_21 ,
V_110 , V_111 , 0 ) ;
F_38 ( V_2 -> V_5 , V_21 ,
V_113 , V_114 , 1 ) ;
F_34 ( V_2 -> V_5 , V_21 ,
V_115 , 0 ) ;
F_39 ( V_2 , V_73 ,
V_116 , V_117 , 1 ) ;
F_11 ( V_2 ) ;
F_40 ( V_2 , V_73 ,
V_118 , V_119 , 0 ) ;
if ( 1 != F_9 ( V_2 -> V_5 ,
V_21 , V_118 , V_120 ) ) {
F_28 ( V_75 L_10 ) ;
return - V_6 ;
}
F_39 ( V_2 , V_73 ,
V_121 , V_117 , 1 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
F_40 ( V_2 , V_73 ,
V_116 , V_122 , 0 ) ;
F_34 ( V_2 -> V_5 , V_21 ,
V_115 , 0 ) ;
F_38 ( V_2 -> V_5 , V_21 ,
V_110 , V_111 , 1 ) ;
V_16 = F_36 ( V_2 ) ;
if ( V_16 != 0 )
return V_16 ;
F_7 ( V_2 ) ;
F_38 ( V_2 -> V_5 , V_21 ,
V_22 , V_23 , 0 ) ;
F_38 ( V_2 -> V_5 , V_21 ,
V_110 , V_111 , 0 ) ;
F_39 ( V_2 , V_73 ,
V_121 , V_117 , 1 ) ;
return V_16 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_16 ;
if ( ! F_8 ( V_2 ) ) {
if ( 0 == F_9 ( V_2 -> V_5 , V_21 ,
V_123 , V_124 ) ) {
V_16 = F_41 ( V_2 ) ;
if ( V_16 )
return V_16 ;
} else {
V_16 = F_37 ( V_2 ) ;
if ( V_16 )
return V_16 ;
}
}
V_16 = F_33 ( V_2 ) ;
return V_16 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_34 * V_92 ;
T_2 * V_125 ;
T_4 V_84 = 0 ;
V_92 = (struct V_34 * ) ( V_2 -> V_36 ) ;
V_92 -> V_39 . V_126 =
( ( sizeof( struct V_94 ) / 4096 ) + 1 ) * 4096 ;
V_92 -> V_37 . V_126 = 200 * 4096 ;
F_44 ( V_2 -> V_5 ,
V_92 -> V_39 . V_126 ,
V_127 ,
V_128 ,
& V_84 ,
& V_92 -> V_39 . V_129 ,
& V_92 -> V_39 . V_38 ) ;
V_92 -> V_101 = V_92 -> V_39 . V_129 ;
V_92 -> V_39 . V_98 = F_31 ( V_84 ) ;
V_92 -> V_39 . V_100 = F_32 ( V_84 ) ;
F_2 ((NULL != tonga_smu->pHeader),
L_11 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)tonga_smu->header_buffer.handle);
return -1 ) ;
F_44 ( V_2 -> V_5 ,
V_92 -> V_37 . V_126 ,
V_127 ,
V_128 ,
& V_84 ,
& V_92 -> V_37 . V_129 ,
& V_92 -> V_37 . V_38 ) ;
V_125 = V_92 -> V_37 . V_129 ;
V_92 -> V_37 . V_98 = F_31 ( V_84 ) ;
V_92 -> V_37 . V_100 = F_32 ( V_84 ) ;
F_2 ((NULL != internal_buf),
L_11 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)tonga_smu->smu_buffer.handle);
return -1;) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_34 * V_92 = NULL ;
V_92 = F_46 ( sizeof( struct V_34 ) , V_130 ) ;
if ( V_92 == NULL )
return - V_131 ;
V_2 -> V_36 = V_92 ;
V_2 -> V_132 = & V_133 ;
return 0 ;
}
