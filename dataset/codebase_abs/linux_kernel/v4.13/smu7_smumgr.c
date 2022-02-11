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
F_2 ((0 == (3 & smc_start_address)), L_1 , return -EINVAL) ;
F_2 ((limit > (smc_start_address + byte_count)), L_3 , return -EINVAL) ;
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
F_2 ((0 == (3 & smc_start_address)), L_1 , return -EINVAL) ;
F_2 ((limit > (smc_start_address + byte_count)), L_3 , return -EINVAL) ;
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
int F_10 ( struct V_1 * V_2 )
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
int F_14 ( struct V_1 * V_2 , T_3 V_27 )
{
int V_28 ;
if ( ! F_11 ( V_2 ) )
return - V_29 ;
F_15 ( V_2 , V_30 , V_31 , 0 ) ;
V_28 = F_16 ( V_2 -> V_5 , V_30 , V_31 ) ;
if ( V_28 != 1 )
F_17 ( L_4 , V_27 , V_28 ) ;
F_3 ( V_2 -> V_5 , V_32 , V_27 ) ;
F_15 ( V_2 , V_30 , V_31 , 0 ) ;
V_28 = F_16 ( V_2 -> V_5 , V_30 , V_31 ) ;
if ( V_28 != 1 )
F_17 ( L_5 , V_27 , V_28 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_3 V_27 )
{
F_3 ( V_2 -> V_5 , V_32 , V_27 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , T_3 V_27 , T_1 V_33 )
{
if ( ! F_11 ( V_2 ) ) {
return - V_29 ;
}
F_15 ( V_2 , V_30 , V_31 , 0 ) ;
F_3 ( V_2 -> V_5 , V_34 , V_33 ) ;
return F_14 ( V_2 , V_27 ) ;
}
int F_20 ( struct V_1 * V_2 , T_3 V_27 , T_1 V_33 )
{
F_3 ( V_2 -> V_5 , V_34 , V_33 ) ;
return F_18 ( V_2 , V_27 ) ;
}
int F_21 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_5 , V_34 , 0x20000 ) ;
F_3 ( V_2 -> V_5 , V_32 , V_35 ) ;
F_15 ( V_2 , V_30 , V_31 , 0 ) ;
if ( 1 != F_16 ( V_2 -> V_5 , V_30 , V_31 ) )
F_17 ( L_6 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 )
{
if ( ! F_11 ( V_2 ) )
return - V_29 ;
F_23 ( V_2 , V_36 , V_24 , V_37 , 0 ) ;
return 0 ;
}
enum V_38 F_24 ( T_1 V_39 )
{
enum V_38 V_19 = V_40 ;
switch ( V_39 ) {
case V_41 :
V_19 = V_42 ;
break;
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
int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_65 , T_1 V_4 )
{
int V_19 ;
V_19 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_19 )
return V_19 ;
* V_65 = F_9 ( V_2 -> V_5 , V_22 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_65 , T_1 V_4 )
{
int V_19 ;
V_19 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_19 )
return V_19 ;
F_3 ( V_2 -> V_5 , V_22 , V_65 ) ;
return 0 ;
}
static T_1 F_26 ( T_1 V_39 )
{
T_1 V_19 = 0 ;
switch ( V_39 ) {
case V_45 :
V_19 = V_66 ;
break;
case V_47 :
V_19 = V_67 ;
break;
case V_49 :
V_19 = V_68 ;
break;
case V_51 :
V_19 = V_69 ;
break;
case V_53 :
V_19 = V_70 ;
break;
case V_55 :
case V_57 :
case V_59 :
V_19 = V_71 ;
break;
case V_61 :
V_19 = V_72 ;
break;
default:
F_17 ( L_7 ) ;
V_19 = 0 ;
}
return V_19 ;
}
static int F_27 ( struct V_1 * V_2 ,
T_1 V_39 ,
struct V_73 * V_74 )
{
int V_19 = 0 ;
struct V_75 V_76 = { 0 } ;
V_19 = F_28 ( V_2 -> V_5 ,
F_24 ( V_39 ) ,
& V_76 ) ;
if ( ! V_19 ) {
V_74 -> V_77 = V_76 . V_78 ;
V_74 -> V_79 = ( T_3 ) V_39 ;
V_74 -> V_80 = F_29 ( V_76 . V_81 ) ;
V_74 -> V_82 = F_30 ( V_76 . V_81 ) ;
V_74 -> V_83 = 0 ;
V_74 -> V_84 = 0 ;
if ( F_31 ( V_2 -> V_5 ) )
V_76 . V_85 -= 20 ;
V_74 -> V_86 = V_76 . V_85 ;
V_74 -> V_87 = 0 ;
}
if ( V_39 == V_61 )
V_74 -> V_88 = 1 ;
else
V_74 -> V_88 = 0 ;
return 0 ;
}
int F_32 ( struct V_1 * V_2 )
{
struct V_89 * V_90 = (struct V_89 * ) ( V_2 -> V_91 ) ;
T_1 V_92 ;
int V_19 = 0 ;
struct V_93 * V_94 ;
if ( ! V_2 -> V_95 ) {
F_17 ( L_8 ) ;
return 0 ;
}
if ( V_90 -> V_96 )
F_33 ( V_2 -> V_5 , V_23 ,
V_90 -> V_96 + F_34 ( V_2 ,
V_97 , V_98 ) ,
0x0 ) ;
if ( V_2 -> V_99 > V_100 ) {
if ( ! F_31 ( V_2 -> V_5 ) ) {
F_19 ( V_2 ,
V_101 ,
V_90 -> V_102 . V_103 ) ;
F_19 ( V_2 ,
V_104 ,
V_90 -> V_102 . V_105 ) ;
}
V_92 = V_72
+ V_66
+ V_67
+ V_68
+ V_70
+ V_69
+ V_71 ;
} else {
V_92 = V_72
+ V_66
+ V_67
+ V_68
+ V_70
+ V_69
+ V_71
+ V_106
+ V_107 ;
}
V_94 = (struct V_93 * ) V_90 -> V_108 ;
V_94 -> V_109 = 0 ;
V_94 -> V_110 = 1 ;
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_RLC_G, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_CE, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_PFP, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_ME, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_MEC, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_MEC_JT1, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_CP_MEC_JT2, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_SDMA0, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_SDMA1, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
if ( F_31 ( V_2 -> V_5 ) )
F_2 ( 0 == smu7_populate_single_firmware_entry(smumgr,
UCODE_ID_MEC_STORAGE, &toc->entry[toc->num_entries++]),
L_9 , return -EINVAL) ;
F_19 ( V_2 , V_111 , V_90 -> V_112 . V_103 ) ;
F_19 ( V_2 , V_113 , V_90 -> V_112 . V_105 ) ;
if ( F_19 ( V_2 , V_114 , V_92 ) )
F_35 ( L_10 ) ;
return V_19 ;
}
int F_36 ( struct V_1 * V_2 , T_1 V_39 )
{
struct V_89 * V_90 = (struct V_89 * ) ( V_2 -> V_91 ) ;
T_1 V_115 = F_26 ( V_39 ) ;
T_1 V_28 ;
V_28 = F_37 ( V_2 , V_6 ,
V_90 -> V_96 + F_34 ( V_2 ,
V_97 , V_98 ) ,
V_115 , V_115 ) ;
return V_28 ;
}
int F_38 ( struct V_1 * V_2 )
{
return V_2 -> V_116 -> V_117 ( V_2 ) ;
}
static int F_39 ( struct V_1 * V_2 , T_1 V_118 , T_1 * V_18 , T_1 V_4 )
{
T_1 V_11 = V_118 ;
F_2 ((limit >= byte_count), L_3 , return -EINVAL) ;
F_3 ( V_2 -> V_5 , V_6 , 0x20000 ) ;
F_4 ( V_2 -> V_5 , V_7 , V_8 , 1 ) ;
for (; V_11 >= 4 ; V_11 -= 4 )
F_3 ( V_2 -> V_5 , V_22 , * V_18 ++ ) ;
F_4 ( V_2 -> V_5 , V_7 , V_8 , 0 ) ;
F_2 ((0 == byte_count), L_11 , return -EINVAL) ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 )
{
int V_19 = 0 ;
struct V_89 * V_90 = (struct V_89 * ) ( V_2 -> V_91 ) ;
struct V_75 V_76 = { 0 } ;
if ( V_90 -> V_119 == 1 )
F_28 ( V_2 -> V_5 ,
F_24 ( V_41 ) , & V_76 ) ;
else
F_28 ( V_2 -> V_5 ,
F_24 ( V_43 ) , & V_76 ) ;
V_2 -> V_120 = V_76 . V_120 ;
V_19 = F_39 ( V_2 , V_76 . V_85 , ( T_1 * ) V_76 . V_121 , V_122 ) ;
return V_19 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
T_2 * V_123 ;
T_4 V_81 = 0 ;
V_90 = (struct V_89 * ) ( V_2 -> V_91 ) ;
V_90 -> V_112 . V_124 =
( ( sizeof( struct V_93 ) / 4096 ) + 1 ) * 4096 ;
F_42 ( V_2 -> V_5 ,
V_90 -> V_112 . V_124 ,
V_125 ,
V_126 ,
& V_81 ,
& V_90 -> V_112 . V_127 ,
& V_90 -> V_112 . V_128 ) ;
V_90 -> V_108 = V_90 -> V_112 . V_127 ;
V_90 -> V_112 . V_103 = F_29 ( V_81 ) ;
V_90 -> V_112 . V_105 = F_30 ( V_81 ) ;
F_2 ((NULL != smu_data->header),
L_12 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)smu_data->header_buffer.handle);
return -EINVAL) ;
if ( F_31 ( V_2 -> V_5 ) )
return 0 ;
V_90 -> V_102 . V_124 = 200 * 4096 ;
F_42 ( V_2 -> V_5 ,
V_90 -> V_102 . V_124 ,
V_125 ,
V_126 ,
& V_81 ,
& V_90 -> V_102 . V_127 ,
& V_90 -> V_102 . V_128 ) ;
V_123 = V_90 -> V_102 . V_127 ;
V_90 -> V_102 . V_103 = F_29 ( V_81 ) ;
V_90 -> V_102 . V_105 = F_30 ( V_81 ) ;
F_2 ((NULL != internal_buf),
L_12 ,
kfree(smumgr->backend);
cgs_free_gpu_mem(smumgr->device,
(cgs_handle_t)smu_data->smu_buffer.handle);
return -EINVAL) ;
return 0 ;
}
int F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_91 ) {
F_44 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
}
F_45 ( V_2 -> V_5 , V_42 ) ;
return 0 ;
}
