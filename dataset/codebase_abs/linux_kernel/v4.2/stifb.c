static void
F_1 ( struct V_1 * V_2 )
{
char V_3 ;
do {
V_3 = F_2 ( V_2 , V_4 ) ;
if ( ! V_3 )
V_3 = F_2 ( V_2 , V_4 ) ;
} while ( V_3 );
}
static void
F_3 ( struct V_1 * V_2 )
{
unsigned int V_5 = 0 ;
F_1 ( V_2 ) ;
switch ( V_2 -> V_6 )
{
case V_7 :
case V_8 :
case V_9 :
V_5 = 0x13601000 ;
break;
case V_10 :
if ( V_2 -> V_11 . V_12 . V_13 == 32 )
V_5 = 0xBBA0A000 ;
else
V_5 = 0x13601000 ;
break;
case V_14 :
if ( V_2 -> V_11 . V_12 . V_13 == 32 )
V_5 = 0xBBA0A000 ;
else
V_5 = 0x13602000 ;
break;
case V_15 :
case V_16 :
V_5 = 0x13602000 ;
break;
}
if ( V_5 )
F_4 ( V_5 , V_2 , V_17 ) ;
F_4 ( 0x83000300 , V_2 , V_18 ) ;
F_1 ( V_2 ) ;
F_5 ( 1 , V_2 , V_19 ) ;
}
static void
F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( 0xBBE0F000 , V_2 , V_17 ) ;
F_4 ( 0x03000300 , V_2 , V_18 ) ;
F_4 ( ~ 0 , V_2 , V_20 ) ;
}
static void
F_7 ( struct V_1 * V_2 , int V_21 , int V_22 )
{
F_1 ( V_2 ) ;
F_4 ( ( ( 0x100 + V_21 ) << 2 ) , V_2 , V_23 ) ;
F_4 ( V_22 , V_2 , V_24 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
F_4 ( 0x400 , V_2 , V_25 ) ;
if ( V_2 -> V_11 . V_12 . V_13 == 32 ) {
F_4 ( 0x83000100 , V_2 , V_26 ) ;
} else {
if ( V_2 -> V_6 == V_8 || V_2 -> V_6 == V_7 )
F_4 ( 0x80000100 , V_2 , V_27 ) ;
else
F_4 ( 0x80000100 , V_2 , V_26 ) ;
}
F_3 ( V_2 ) ;
}
static void
F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( 0x04000000 , V_2 , 0x1020 ) ;
F_4 ( 0xff000000 , V_2 , 0x1028 ) ;
}
static void
F_10 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( 0x04000000 , V_2 , 0x1000 ) ;
F_4 ( 0x02000000 , V_2 , 0x1004 ) ;
F_4 ( 0xff000000 , V_2 , 0x1008 ) ;
F_4 ( 0x05000000 , V_2 , 0x1000 ) ;
F_4 ( 0x02000000 , V_2 , 0x1004 ) ;
F_4 ( 0x03000000 , V_2 , 0x1008 ) ;
}
static void
F_11 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( 0x13a02000 , V_2 , V_28 ) ;
F_4 ( 0x03000300 , V_2 , V_18 ) ;
F_4 ( 0x000017f0 , V_2 , V_23 ) ;
F_4 ( 0xffffffff , V_2 , V_20 ) ;
F_4 ( 0xffffffff , V_2 , V_29 ) ;
F_4 ( 0x00000000 , V_2 , V_30 ) ;
}
static void
F_12 ( struct V_1 * V_2 , int V_31 )
{
unsigned int V_32 = V_31 ? 0x43000000 : 0x03000000 ;
F_1 ( V_2 ) ;
F_4 ( 0x06000000 , V_2 , 0x1030 ) ;
F_4 ( V_32 , V_2 , 0x1038 ) ;
}
static void
F_13 ( struct V_1 * V_2 , int V_31 )
{
unsigned int V_32 = V_31 ? 0x10000000 : 0x30000000 ;
F_1 ( V_2 ) ;
F_4 ( 0x01000000 , V_2 , 0x1000 ) ;
F_4 ( 0x02000000 , V_2 , 0x1004 ) ;
F_4 ( V_32 , V_2 , 0x1008 ) ;
}
static void
F_14 ( struct V_1 * V_2 , int V_31 )
{
T_1 V_33 = V_34 ;
T_1 V_35 = V_36 ;
F_1 ( V_2 ) ;
if ( V_31 ) {
F_4 ( F_15 ( V_2 , V_33 ) | 0x0A000000 , V_2 , V_33 ) ;
F_4 ( F_15 ( V_2 , V_35 ) | 0x00800000 , V_2 , V_35 ) ;
} else {
F_4 ( F_15 ( V_2 , V_33 ) & ~ 0x0A000000 , V_2 , V_33 ) ;
F_4 ( F_15 ( V_2 , V_35 ) & ~ 0x00800000 , V_2 , V_35 ) ;
}
}
static void
F_16 ( struct V_1 * V_2 , int V_31 )
{
T_1 V_37 = V_38 ;
unsigned int V_32 ;
F_1 ( V_2 ) ;
V_32 = F_15 ( V_2 , V_37 ) ;
if ( V_31 )
V_32 |= 0x0A000000 ;
else
V_32 &= ~ 0x0A000000 ;
F_4 ( V_32 , V_2 , V_37 ) ;
}
static void
F_17 ( struct V_1 * V_2 , unsigned V_39 )
{
F_1 ( V_2 ) ;
F_4 ( 0x2EA0D000 , V_2 , V_28 ) ;
F_4 ( 0x23000302 , V_2 , V_18 ) ;
F_4 ( V_39 , V_2 , V_40 ) ;
F_4 ( 0xffffffff , V_2 , V_41 ) ;
}
static void
F_18 ( struct V_1 * V_2 , int V_42 , int V_43 )
{
F_4 ( 0x00000000 , V_2 , V_44 ) ;
F_4 ( ( V_42 << 16 ) | V_43 , V_2 , V_45 ) ;
F_4 ( 0x05000000 , V_2 , V_44 ) ;
F_4 ( 0x00040001 , V_2 , V_45 ) ;
}
static void
F_19 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_4 ( 0x00000000 , V_2 , V_40 ) ;
}
static void
F_20 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void
F_21 ( struct V_1 * V_2 , int V_39 )
{
F_17 ( V_2 , V_39 ) ;
F_18 ( V_2 , V_2 -> V_11 . V_12 . V_46 , V_2 -> V_11 . V_12 . V_47 ) ;
F_19 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static void
F_22 ( struct V_1 * V_2 )
{
int V_48 , V_49 ;
F_10 ( V_2 ) ;
V_48 = V_2 -> V_6 ;
V_2 -> V_6 = V_16 ;
F_3 ( V_2 ) ;
V_2 -> V_6 = V_48 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_11 . V_12 . V_47 ; ++ V_49 )
memset ( V_2 -> V_11 . V_50 + V_49 * V_2 -> V_11 . V_51 . V_52 ,
0xff , V_2 -> V_11 . V_12 . V_46 * V_2 -> V_11 . V_12 . V_13 / 8 ) ;
F_11 ( V_2 ) ;
F_3 ( V_2 ) ;
}
static T_2
F_23 ( struct V_1 * V_2 , int V_53 , int V_54 )
{
T_2 V_55 ;
V_55 . V_56 = 0x80000000 ;
V_55 . V_57 . V_54 = V_54 ;
V_55 . V_57 . V_58 = V_59 ;
if ( V_2 -> V_11 . V_12 . V_13 == 8 )
V_55 . V_57 . V_60 = 2 * 256 ;
else
V_55 . V_57 . V_60 = 0 * 256 ;
V_55 . V_57 . V_60 += V_53 ;
return V_55 ;
}
static void F_24 ( struct V_1 * V_2 )
{
int V_61 = 0 ;
T_1 V_62 ;
F_25 ( V_2 ) ;
F_26 ( V_2 , V_61 , 1 ) ;
F_4 ( 0xffffffff , V_2 , V_63 ) ;
F_26 ( V_2 , V_61 , 7 ) ;
F_27 ( V_2 ,
F_28 ( V_64 , V_65 , V_66 , V_67 ,
F_29 ( 0 ) , V_68 , F_30 ( 0 ) ) ) ;
F_31 ( V_2 ,
F_32 ( V_69 , F_33 ( 0 ) ,
V_70 , F_34 ( 0 ) ,
V_71 , V_72 , F_35 ( 0 ) , F_36 ( 0 ) ) ) ;
V_62 = F_37 ( 0 , 1532 , 0 ) ;
F_38 ( V_2 , V_62 ) ;
F_39 ( V_2 , 0xffffff ) ;
F_40 ( V_2 , 0xffffffff ) ;
F_41 ( V_2 , 0 ) ;
F_42 ( V_2 ) ;
}
static void
F_43 ( struct V_1 * V_2 )
{
}
static void
F_44 ( struct V_1 * V_2 )
{
}
static void
F_45 ( struct V_1 * V_2 , unsigned int V_73 )
{
int V_61 = 0 ;
T_1 V_74 ;
T_1 V_75 ;
F_25 ( V_2 ) ;
F_26 ( V_2 , V_61 , 4 ) ;
F_27 ( V_2 ,
F_28 ( V_64 , V_76 , V_77 ,
V_67 , F_29 ( 0 ) ,
V_78 , F_30 ( 0 ) ) ) ;
F_46 ( V_2 , V_73 ) ;
F_47 ( V_2 , 0xffffffff ) ;
F_31 ( V_2 ,
F_32 ( V_69 , F_33 ( 0 ) ,
V_70 , F_34 ( 1 ) ,
V_71 , V_72 ,
F_35 ( 0 ) , F_36 ( 0 ) ) ) ;
V_74 = 0 ;
V_75 = ( V_2 -> V_11 . V_12 . V_46 << 16 ) | V_2 -> V_11 . V_12 . V_47 ;
F_26 ( V_2 , V_61 , 2 ) ;
F_48 ( V_2 , V_74 ) ;
F_49 ( V_2 , V_75 ) ;
if ( V_2 -> V_6 == V_9 ) {
V_74 = ( 1280 << 16 ) ;
F_26 ( V_2 , V_61 , 2 ) ;
F_48 ( V_2 , V_74 ) ;
V_75 = ( 4 << 16 ) | 1 ;
F_49 ( V_2 , V_75 ) ;
}
F_26 ( V_2 , V_61 , 1 ) ;
F_46 ( V_2 , 0 ) ;
F_42 ( V_2 ) ;
}
static void
F_50 ( struct V_1 * V_2 , int V_79 , int V_80 )
{
int V_61 = 0 ;
T_1 V_74 ;
T_1 V_75 ;
F_25 ( V_2 ) ;
F_26 ( V_2 , V_61 , 8 ) ;
F_27 ( V_2 ,
F_28 ( V_64 , V_65 , V_66 , V_67 ,
F_29 ( 0 ) , V_68 , F_30 ( 0 ) ) ) ;
F_47 ( V_2 , 0xffffffff ) ;
F_51 ( V_2 , V_80 ) ;
F_39 ( V_2 , V_79 ) ;
V_74 = 0 ;
V_75 = ( V_2 -> V_11 . V_12 . V_46 << 16 ) | V_2 -> V_11 . V_12 . V_47 ;
F_48 ( V_2 , V_74 ) ;
F_31 ( V_2 ,
F_32 ( V_69 , F_33 ( 0 ) ,
V_70 , F_34 ( 0 ) ,
V_71 , V_72 , F_35 ( 0 ) , F_36 ( 0 ) ) ) ;
F_49 ( V_2 , V_75 ) ;
F_42 ( V_2 ) ;
}
static void
F_52 ( struct V_1 * V_2 , int V_31 )
{
unsigned int V_81 ;
F_25 ( V_2 ) ;
if ( F_53 ( V_2 ) )
if ( V_2 -> V_11 . V_12 . V_13 == 32 )
V_81 = 0x04000F00 ;
else
V_81 = 0x00000F00 ;
else
V_81 = 0x00000F00 ;
switch ( V_31 ) {
case V_82 :
if ( F_53 ( V_2 ) )
F_44 ( V_2 ) ;
else
F_43 ( V_2 ) ;
F_45 ( V_2 , V_81 ) ;
F_50 ( V_2 , 0xff , 255 ) ;
F_24 ( V_2 ) ;
break;
case V_83 :
if ( F_53 ( V_2 ) )
F_44 ( V_2 ) ;
else
F_43 ( V_2 ) ;
F_45 ( V_2 , V_81 ) ;
F_50 ( V_2 , 0xff , 0 ) ;
break;
case - 1 :
F_24 ( V_2 ) ;
F_45 ( V_2 , V_81 ) ;
break;
}
F_42 ( V_2 ) ;
}
static void
F_54 ( struct V_1 * V_2 )
{
#if 0
XXX: FIXME: !!!
int *pBytePerLongDevDepData;
int *pRomTable;
NgleDevRomData *pPackedDevRomData;
int sizePackedDevRomData = sizeof(*pPackedDevRomData);
char *pCard8;
int i;
char *mapOrigin = NULL;
int romTableIdx;
pPackedDevRomData = fb->ngle_rom;
SETUP_HW(fb);
if (fb->id == S9000_ID_ARTIST) {
pPackedDevRomData->cursor_pipeline_delay = 4;
pPackedDevRomData->video_interleaves = 4;
} else {
pBytePerLongDevDepData = fb->sti->regions[NGLEDEVDEPROM_CRT_REGION];
if (fb->id == S9000_ID_TOMCAT)
{
GET_ROMTABLE_INDEX(romTableIdx);
while (romTableIdx > 0)
{
pCard8 = (Card8 *) pPackedDevRomData;
pRomTable = pBytePerLongDevDepData;
for (i = 0; i < sizePackedDevRomData; i++)
{
*pCard8++ = (Card8) (*pRomTable++);
}
pBytePerLongDevDepData = (Card32 *)
((Card8 *) pBytePerLongDevDepData +
pPackedDevRomData->sizeof_ngle_data);
romTableIdx--;
}
}
pCard8 = (Card8 *) pPackedDevRomData;
for (i = 0; i < sizePackedDevRomData; i++)
{
*pCard8++ = (Card8) (*pBytePerLongDevDepData++);
}
}
SETUP_FB(fb);
#endif
}
static void T_3
F_55 ( struct V_1 * V_2 )
{
int V_84 ;
int V_61 = 0 ;
if ( V_2 -> V_6 != V_14 )
return;
F_26 ( V_2 , V_61 , 7 ) ;
if ( F_53 ( V_2 ) ) {
V_84 = ( V_2 -> V_11 . V_12 . V_13 == 32 ) ?
V_85 :
V_86 ;
F_4 ( V_84 , V_2 , V_87 ) ;
F_4 ( V_84 , V_2 , V_87 ) ;
F_4 ( V_88 , V_2 , V_89 ) ;
F_4 ( 0x014c0148 , V_2 , V_90 ) ;
F_4 ( 0x404c4048 , V_2 , V_91 ) ;
F_4 ( 0x034c0348 , V_2 , V_92 ) ;
F_4 ( 0x444c4448 , V_2 , V_93 ) ;
} else {
V_84 = V_94 ;
F_4 ( V_84 , V_2 , V_87 ) ;
F_4 ( V_84 , V_2 , V_87 ) ;
F_4 ( 0x00000000 , V_2 , V_90 ) ;
F_4 ( 0x00000000 , V_2 , V_91 ) ;
F_4 ( 0x00000000 , V_2 , V_92 ) ;
F_4 ( 0x444c4048 , V_2 , V_93 ) ;
}
}
static int
F_56 ( T_4 V_95 , T_4 V_96 , T_4 V_97 ,
T_4 V_98 , T_4 V_99 , struct V_100 * V_11 )
{
struct V_1 * V_2 = F_57 ( V_11 , struct V_1 , V_11 ) ;
T_1 V_22 ;
if ( V_95 >= V_101 )
return 1 ;
V_96 >>= 8 ;
V_97 >>= 8 ;
V_98 >>= 8 ;
F_58 () ;
F_6 ( V_2 ) ;
if ( F_59 ( V_2 -> V_11 . V_12 . V_102 ) ) {
V_22 = ( ( V_96 * 77 ) +
( V_97 * 151 ) +
( V_98 * 28 ) ) >> 8 ;
} else {
V_22 = ( ( V_96 << 16 ) |
( V_97 << 8 ) |
( V_98 ) ) ;
}
if ( V_2 -> V_11 . V_51 . V_103 == V_104 ) {
struct V_105 * V_12 = & V_2 -> V_11 . V_12 ;
if ( V_95 < 16 )
( ( T_1 * ) V_2 -> V_11 . V_106 ) [ V_95 ] =
V_95 << V_12 -> V_96 . V_107 |
V_95 << V_12 -> V_97 . V_107 |
V_95 << V_12 -> V_98 . V_107 ;
}
F_7 ( V_2 , V_95 , V_22 ) ;
if ( V_2 -> V_6 == V_14 ) {
T_2 V_55 ;
V_55 = F_23 ( V_2 ,
0 ,
256 ) ;
F_60 ( V_2 ,
F_37 ( 0 , 0x100 , 0 ) ) ;
F_61 ( V_2 , V_55 . V_56 ) ;
F_3 ( V_2 ) ;
} else {
F_8 ( V_2 ) ;
}
F_62 () ;
return 0 ;
}
static int
F_63 ( int V_108 , struct V_100 * V_11 )
{
struct V_1 * V_2 = F_57 ( V_11 , struct V_1 , V_11 ) ;
int V_31 = ( V_108 == 0 ) ? V_82 : V_83 ;
switch ( V_2 -> V_6 ) {
case V_10 :
F_13 ( V_2 , V_31 ) ;
break;
case V_7 :
case V_8 :
F_14 ( V_2 , V_31 ) ;
break;
case V_14 :
F_16 ( V_2 , V_31 ) ;
break;
case V_9 :
case V_15 :
case V_16 :
default:
F_12 ( V_2 , V_31 ) ;
break;
}
F_3 ( V_2 ) ;
return 0 ;
}
static void
F_64 ( struct V_100 * V_11 , const struct V_109 * V_110 )
{
struct V_1 * V_2 = F_57 ( V_11 , struct V_1 , V_11 ) ;
F_65 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_11 . V_12 . V_13 == 32 ) {
F_4 ( 0xBBA0A000 , V_2 , V_17 ) ;
F_39 ( V_2 , 0xffffffff ) ;
} else {
F_4 ( V_2 -> V_6 == V_14 ? 0x13a02000 : 0x13a01000 , V_2 , V_17 ) ;
F_39 ( V_2 , 0xff ) ;
}
F_31 ( V_2 ,
F_32 ( V_69 , F_33 ( 0 ) ,
V_70 , F_34 ( 1 ) ,
V_71 , V_72 , F_35 ( 0 ) , F_36 ( 0 ) ) ) ;
F_4 ( ( ( V_110 -> V_111 << 16 ) | V_110 -> V_112 ) , V_2 , V_113 ) ;
F_4 ( ( ( V_110 -> V_42 << 16 ) | V_110 -> V_43 ) , V_2 , V_114 ) ;
F_4 ( ( ( V_110 -> V_115 << 16 ) | V_110 -> V_116 ) , V_2 , V_117 ) ;
F_3 ( V_2 ) ;
}
static void T_3
F_66 ( struct V_1 * V_2 )
{
int V_6 = V_2 -> V_6 ;
F_3 ( V_2 ) ;
F_55 ( V_2 ) ;
switch ( V_6 ) {
case V_14 :
F_52 ( V_2 , V_82 ) ;
break;
case V_10 :
F_22 ( V_2 ) ;
break;
case V_9 :
case V_8 :
case V_7 :
F_20 ( V_2 ) ;
break;
}
switch ( V_6 ) {
case V_9 :
case V_10 :
if ( V_2 -> V_11 . V_12 . V_13 == 32 )
F_21 ( V_2 , V_118 ) ;
else {
F_21 ( V_2 , V_119 ) ;
}
if ( V_6 == V_10 )
F_50 ( V_2 , 0xff , 0 ) ;
break;
case V_8 :
case V_7 :
if ( V_2 -> V_11 . V_12 . V_13 == 32 )
F_21 ( V_2 , V_118 ) ;
else {
F_21 ( V_2 , V_120 ) ;
}
break;
}
F_63 ( 0 , (struct V_100 * ) V_2 ) ;
F_3 ( V_2 ) ;
}
static int T_3 F_67 ( struct V_121 * V_122 , int V_123 )
{
struct V_124 * V_51 ;
struct V_105 * V_12 ;
struct V_1 * V_2 ;
struct V_100 * V_11 ;
unsigned long V_125 ;
char * V_126 ;
int V_127 , V_46 , V_47 ;
V_2 = F_68 ( sizeof( * V_2 ) , V_128 ) ;
if ( ! V_2 ) {
F_69 ( V_129 L_1 ) ;
return - V_130 ;
}
V_11 = & V_2 -> V_11 ;
V_51 = & V_11 -> V_51 ;
V_12 = & V_11 -> V_12 ;
V_2 -> V_122 = V_122 ;
V_126 = V_122 -> V_131 -> V_132 . V_126 ;
V_2 -> V_6 = V_2 -> V_122 -> V_133 [ 0 ] ;
switch ( V_2 -> V_6 ) {
case V_7 :
if ( strstr ( V_126 , L_2 ) ) {
F_69 ( V_134
L_3
L_4 ,
V_126 ) ;
goto V_135;
}
case V_8 :
case V_14 :
case V_15 :
case V_9 :
case V_10 :
break;
default:
F_69 ( V_134 L_5 ,
V_126 , V_2 -> V_6 ) ;
goto V_135;
}
V_127 = 8 ;
V_46 = F_70 ( V_2 -> V_122 ) ;
V_47 = F_71 ( V_2 -> V_122 ) ;
F_54 ( V_2 ) ;
V_51 -> V_136 = F_72 ( V_2 , 2 ) ;
V_51 -> V_137 = 0x400000 ;
switch ( V_2 -> V_6 ) {
case V_9 :
break;
case V_138 :
V_12 -> V_102 = 1 ;
V_2 -> V_6 = V_9 ;
break;
case V_15 :
if ( strstr ( V_126 , L_6 ) ||
strstr ( V_126 , L_7 ) ||
strstr ( V_126 , L_8 ) )
V_12 -> V_102 = 1 ;
break;
case V_139 :
V_46 = V_2 -> V_140 . V_141 ;
V_47 = V_2 -> V_140 . V_142 ;
V_2 -> V_6 = V_9 ;
break;
case V_10 :
V_127 = 32 ;
break;
case V_14 :
memset ( & V_2 -> V_140 , 0 , sizeof( V_2 -> V_140 ) ) ;
if ( ( V_2 -> V_122 -> V_143 [ 0 ] & 0xfc000000 ) ==
( V_2 -> V_122 -> V_143 [ 2 ] & 0xfc000000 ) )
V_125 = F_73 ( V_2 -> V_122 -> V_143 [ 0 ] ) ;
else
V_125 = F_73 ( V_2 -> V_122 -> V_143 [ 1 ] ) ;
V_2 -> V_144 = F_74 ( V_125 ) ;
if ( F_53 ( V_2 ) ) {
if ( V_123 == 8 || V_123 == 32 )
V_127 = V_123 ;
else
V_127 = 32 ;
} else
V_127 = 8 ;
F_15 ( V_2 , V_145 ) ;
F_1 ( V_2 ) ;
break;
case V_7 :
case V_8 :
break;
default:
#ifdef F_75
F_69 ( V_134
L_9
L_10 ,
V_2 -> V_6 ) ;
V_127 = 1 ;
break;
#else
F_69 ( V_134
L_9
L_11 ,
V_2 -> V_6 ) ;
goto V_135;
#endif
}
V_51 -> V_146 = F_73 ( V_2 -> V_122 -> V_143 [ 1 ] ) ;
V_51 -> V_147 = V_2 -> V_122 -> V_148 [ 1 ] . V_149 . V_54 * 4096 ;
V_51 -> V_52 = ( V_2 -> V_122 -> V_150 -> V_151 * V_127 ) / 8 ;
if ( ! V_51 -> V_52 )
V_51 -> V_52 = 2048 ;
if ( V_51 -> V_147 > V_47 * V_51 -> V_52 )
V_51 -> V_147 = V_47 * V_51 -> V_52 ;
V_51 -> V_152 = V_153 ;
switch ( V_127 ) {
case 1 :
V_51 -> type = V_154 ;
V_51 -> V_103 = V_155 ;
V_12 -> V_96 . V_54 = V_12 -> V_97 . V_54 = V_12 -> V_98 . V_54 = 1 ;
break;
case 8 :
V_51 -> type = V_156 ;
V_51 -> V_103 = V_157 ;
V_12 -> V_96 . V_54 = V_12 -> V_97 . V_54 = V_12 -> V_98 . V_54 = 8 ;
break;
case 32 :
V_51 -> type = V_156 ;
V_51 -> V_103 = V_104 ;
V_12 -> V_96 . V_54 = V_12 -> V_97 . V_54 = V_12 -> V_98 . V_54 = V_12 -> V_99 . V_54 = 8 ;
V_12 -> V_98 . V_107 = 0 ;
V_12 -> V_97 . V_107 = 8 ;
V_12 -> V_96 . V_107 = 16 ;
V_12 -> V_99 . V_107 = 24 ;
break;
default:
break;
}
V_12 -> V_46 = V_12 -> V_158 = V_46 ;
V_12 -> V_47 = V_12 -> V_159 = V_47 ;
V_12 -> V_13 = V_127 ;
strcpy ( V_51 -> V_6 , L_12 ) ;
V_11 -> V_160 = & V_161 ;
V_11 -> V_50 = F_76 ( F_72 ( V_2 , 1 ) , V_51 -> V_147 ) ;
V_11 -> V_162 = V_51 -> V_147 ;
V_11 -> V_163 = V_164 | V_165 ;
V_11 -> V_106 = & V_2 -> V_106 ;
if ( F_77 ( & V_11 -> V_166 , V_101 , 0 ) )
goto V_167;
F_66 ( V_2 ) ;
if ( ! F_78 ( V_51 -> V_146 , V_51 -> V_147 , L_13 ) ) {
F_69 ( V_129 L_14 ,
V_51 -> V_146 , V_51 -> V_146 + V_51 -> V_147 ) ;
goto V_168;
}
if ( ! F_78 ( V_51 -> V_136 , V_51 -> V_137 , L_15 ) ) {
F_69 ( V_129 L_16 ,
V_51 -> V_136 , V_51 -> V_136 + V_51 -> V_137 ) ;
goto V_169;
}
if ( F_79 ( & V_2 -> V_11 ) < 0 )
goto V_170;
V_122 -> V_11 = V_11 ;
V_100 ( & V_2 -> V_11 , L_17 ,
V_51 -> V_6 ,
V_12 -> V_46 ,
V_12 -> V_47 ,
V_12 -> V_13 ,
V_126 ,
V_2 -> V_6 ,
V_51 -> V_136 ) ;
return 0 ;
V_170:
F_80 ( V_51 -> V_136 , V_51 -> V_137 ) ;
V_169:
F_80 ( V_51 -> V_146 , V_51 -> V_147 ) ;
V_168:
F_81 ( & V_11 -> V_166 ) ;
V_167:
F_82 ( V_11 -> V_50 ) ;
V_135:
F_83 ( V_2 ) ;
return - V_171 ;
}
static int T_3 F_84 ( void )
{
struct V_121 * V_122 ;
struct V_121 * V_172 ;
int V_173 ;
#ifndef F_85
char * V_174 = NULL ;
if ( F_86 ( L_12 , & V_174 ) )
return - V_130 ;
F_87 ( V_174 ) ;
#endif
if ( V_175 ) {
F_69 ( V_176 L_18 ) ;
return - V_171 ;
}
V_172 = F_88 ( 0 ) ;
if ( V_172 ) {
for ( V_173 = 1 ; V_173 <= V_177 ; V_173 ++ ) {
V_122 = F_88 ( V_173 ) ;
if ( ! V_122 )
break;
if ( V_122 == V_172 ) {
F_67 ( V_122 , V_178 [ V_173 - 1 ] ) ;
break;
}
}
}
for ( V_173 = 1 ; V_173 <= V_177 ; V_173 ++ ) {
V_122 = F_88 ( V_173 ) ;
if ( ! V_122 )
break;
if ( V_122 == V_172 )
continue;
F_67 ( V_122 , V_178 [ V_173 - 1 ] ) ;
}
return 0 ;
}
static void T_5
F_89 ( void )
{
struct V_121 * V_122 ;
int V_173 ;
for ( V_173 = 1 ; V_173 <= V_177 ; V_173 ++ ) {
V_122 = F_88 ( V_173 ) ;
if ( ! V_122 )
break;
if ( V_122 -> V_11 ) {
struct V_100 * V_11 = V_122 -> V_11 ;
F_90 ( V_122 -> V_11 ) ;
F_80 ( V_11 -> V_51 . V_136 , V_11 -> V_51 . V_137 ) ;
F_80 ( V_11 -> V_51 . V_146 , V_11 -> V_51 . V_147 ) ;
if ( V_11 -> V_50 )
F_82 ( V_11 -> V_50 ) ;
F_81 ( & V_11 -> V_166 ) ;
F_91 ( V_11 ) ;
}
V_122 -> V_11 = NULL ;
}
}
int T_3
F_87 ( char * V_179 )
{
int V_173 ;
if ( ! V_179 || ! * V_179 )
return 1 ;
if ( strncmp ( V_179 , L_19 , 3 ) == 0 ) {
V_175 = 1 ;
V_179 += 3 ;
}
if ( strncmp ( V_179 , L_20 , 3 ) == 0 ) {
V_179 += 3 ;
for ( V_173 = 0 ; V_173 < V_177 ; V_173 ++ ) {
if ( * V_179 ++ != ':' )
break;
V_178 [ V_173 ] = F_92 ( V_179 , & V_179 , 10 ) ;
}
}
return 1 ;
}
