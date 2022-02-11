static void F_1 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_3 , F_4 ( V_2 , V_7 ) ) ;
F_3 ( V_4 , F_4 ( V_2 , V_8 ) ) ;
F_5 ( & V_2 -> V_6 , V_5 ) ;
F_6 ( V_2 -> V_9 -> V_10 , L_1 , V_3 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char V_3 )
{
int V_11 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_3 , F_4 ( V_2 , V_7 ) ) ;
V_11 = F_8 ( F_4 ( V_2 , V_8 ) ) ;
F_5 ( & V_2 -> V_6 , V_5 ) ;
F_6 ( V_2 -> V_9 -> V_10 , L_2 , V_3 , V_11 ) ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_12 , unsigned char V_4 )
{
unsigned long V_5 ;
unsigned char V_13 , V_14 , V_15 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_3 , F_4 ( V_2 , V_7 ) ) ;
V_13 = F_8 ( F_4 ( V_2 , V_8 ) ) ;
V_15 = V_13 & V_12 ;
if ( V_4 != V_15 ) {
V_14 = ( V_13 & ~ V_12 ) | ( V_4 & V_12 ) ;
F_3 ( V_14 , F_4 ( V_2 , V_8 ) ) ;
F_6 ( V_2 -> V_9 -> V_10 ,
L_3 ,
V_3 , V_13 , V_14 ) ;
}
F_5 ( & V_2 -> V_6 , V_5 ) ;
return V_15 ;
}
static void F_10 ( struct V_1 * V_2 , unsigned char V_16 )
{
int V_17 ;
unsigned char V_18 ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
if ( ! ( V_18 = F_8 ( F_4 ( V_2 , V_20 ) ) & 0x80 ) ) {
F_3 ( V_16 , F_4 ( V_2 , V_21 ) ) ;
return;
}
}
F_11 ( V_2 -> V_9 -> V_10 ,
L_4 , V_16 , V_18 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_17 ;
unsigned char V_18 ;
for ( V_17 = V_22 ; V_17 ; V_17 -- )
if ( ( V_18 = F_8 ( F_4 ( V_2 , V_23 ) ) ) & 0x80 )
return F_8 ( F_4 ( V_2 , V_24 ) ) ;
F_11 ( V_2 -> V_9 -> V_10 , L_5 , V_18 ) ;
return - V_25 ;
}
static void F_13 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_26 , V_5 ) ;
F_10 ( V_2 , V_3 ) ;
F_10 ( V_2 , V_4 ) ;
F_5 ( & V_2 -> V_26 , V_5 ) ;
F_6 ( V_2 -> V_9 -> V_10 , L_6 , V_3 , V_4 ) ;
}
static unsigned char F_14 ( struct V_1 * V_2 , unsigned char V_3 )
{
unsigned char V_4 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_26 , V_5 ) ;
F_10 ( V_2 , V_27 ) ;
F_10 ( V_2 , V_3 ) ;
V_4 = F_12 ( V_2 ) ;
F_5 ( & V_2 -> V_26 , V_5 ) ;
F_6 ( V_2 -> V_9 -> V_10 , L_7 , V_3 , V_4 ) ;
return V_4 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_12 ,
unsigned char V_4 )
{
unsigned long V_5 ;
unsigned char V_13 , V_14 , V_15 ;
F_2 ( & V_2 -> V_26 , V_5 ) ;
F_10 ( V_2 , V_27 ) ;
F_10 ( V_2 , V_3 ) ;
V_13 = F_12 ( V_2 ) ;
V_15 = V_13 & V_12 ;
if ( V_4 != V_15 ) {
F_10 ( V_2 , V_3 ) ;
V_14 = ( V_13 & ~ V_12 ) | ( V_4 & V_12 ) ;
F_10 ( V_2 , V_14 ) ;
F_6 ( V_2 -> V_9 -> V_10 , L_8 ,
V_3 , V_13 , V_14 ) ;
}
F_5 ( & V_2 -> V_26 , V_5 ) ;
return V_15 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_17 ;
F_3 ( 3 , F_4 ( V_2 , V_28 ) ) ;
F_8 ( F_4 ( V_2 , V_28 ) ) ;
F_3 ( 0 , F_4 ( V_2 , V_28 ) ) ;
for ( V_17 = 0 ; V_17 < V_29 ; V_17 ++ ) {
if ( F_8 ( F_4 ( V_2 , V_23 ) ) & 0x80 ) {
if ( F_8 ( F_4 ( V_2 , V_24 ) ) == 0xaa )
goto V_30;
}
}
F_11 ( V_2 -> V_9 -> V_10 , L_9 ) ;
V_30:
F_10 ( V_2 , V_31 ) ;
F_13 ( V_2 , V_32 , 2 ) ;
F_1 ( V_2 , V_33 , 0x32 ) ;
F_15 ( V_2 , V_34 , 0xf0 , 0x50 ) ;
F_15 ( V_2 , V_35 , 0xf0 , 0x50 ) ;
F_10 ( V_2 , V_36 ) ;
F_1 ( V_2 , 0x54 , 0x8f ) ;
F_1 ( V_2 , 0x56 , 0x95 ) ;
F_1 ( V_2 , 0x58 , 0x94 ) ;
F_1 ( V_2 , 0x5a , 0x80 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_3 ( 2 , F_4 ( V_2 , V_28 ) ) ;
F_3 ( 0 , F_4 ( V_2 , V_28 ) ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_37 * V_38 ,
int V_39 )
{
unsigned int V_40 , V_41 ;
struct V_42 * V_43 = V_38 -> V_43 ;
if ( V_43 -> V_44 == V_45 [ 0 ] . V_46 )
V_40 = 128 - V_43 -> V_47 ;
else
V_40 = 256 - V_43 -> V_47 ;
V_41 = 256 - 7160000 * 20 / ( 8 * 82 * V_43 -> V_48 ) ;
if ( V_39 == V_49 ) {
F_1 ( V_2 , 0x70 , V_40 ) ;
F_1 ( V_2 , 0x72 , V_41 ) ;
} else {
F_13 ( V_2 , 0xA1 , V_40 ) ;
F_13 ( V_2 , 0xA2 , V_41 ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
F_3 ( 0x00 , F_20 ( V_2 , V_50 ) ) ;
F_21 ( V_2 -> V_51 , F_20 ( V_2 , V_52 ) ) ;
F_22 ( 0 , F_20 ( V_2 , V_53 ) ) ;
F_22 ( V_2 -> V_54 , F_20 ( V_2 , V_53 ) ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_3 ( 0xc4 , F_24 ( V_2 , V_55 ) ) ;
F_3 ( 0 , F_24 ( V_2 , V_56 ) ) ;
F_3 ( 1 , F_24 ( V_2 , V_57 ) ) ;
F_3 ( 0x18 , F_24 ( V_2 , V_58 ) ) ;
F_21 ( V_2 -> V_59 , F_24 ( V_2 , V_60 ) ) ;
F_22 ( V_2 -> V_61 - 1 , F_24 ( V_2 , V_62 ) ) ;
F_3 ( 0 , F_24 ( V_2 , V_57 ) ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_3 ( 0xc4 , F_24 ( V_2 , V_55 ) ) ;
F_3 ( 0 , F_24 ( V_2 , V_56 ) ) ;
F_3 ( 1 , F_24 ( V_2 , V_57 ) ) ;
F_3 ( 0x14 , F_24 ( V_2 , V_58 ) ) ;
F_21 ( V_2 -> V_59 , F_24 ( V_2 , V_60 ) ) ;
V_2 -> V_63 = V_2 -> V_59 ;
F_22 ( V_2 -> V_61 - 1 , F_24 ( V_2 , V_62 ) ) ;
F_3 ( 0 , F_24 ( V_2 , V_57 ) ) ;
}
static int F_26 ( struct V_37 * V_38 ,
int V_16 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
int V_4 ;
switch ( V_16 ) {
case V_64 :
case V_65 :
V_4 = 0x0f ;
V_2 -> V_66 |= V_67 ;
break;
case V_68 :
case V_69 :
V_4 = 0x00 ;
V_2 -> V_66 &= ~ V_67 ;
break;
default:
return - V_70 ;
}
F_13 ( V_2 , V_71 , V_4 ) ;
return 0 ;
}
static int F_28 ( struct V_37 * V_38 ,
int V_16 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
switch ( V_16 ) {
case V_64 :
case V_65 :
F_1 ( V_2 , V_72 , 0x92 ) ;
F_29 ( 10 ) ;
F_1 ( V_2 , V_72 , 0x93 ) ;
F_3 ( 0x0a , F_20 ( V_2 , V_50 ) ) ;
V_2 -> V_66 |= V_49 ;
break;
case V_68 :
case V_69 :
F_3 ( 0 , F_20 ( V_2 , V_50 ) ) ;
F_1 ( V_2 , V_72 , 0 ) ;
V_2 -> V_66 &= ~ V_49 ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static int F_30 ( struct V_37 * V_38 ,
int V_16 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
int V_4 ;
switch ( V_16 ) {
case V_64 :
case V_65 :
V_4 = 5 ;
V_2 -> V_66 |= V_73 ;
break;
case V_68 :
case V_69 :
V_4 = 0 ;
V_2 -> V_66 &= ~ V_73 ;
break;
default:
return - V_70 ;
}
F_13 ( V_2 , V_71 , V_4 ) ;
return 0 ;
}
static int F_31 ( struct V_37 * V_38 ,
int V_16 )
{
switch ( V_38 -> V_74 ) {
case 0 :
return F_28 ( V_38 , V_16 ) ;
case 1 :
return F_30 ( V_38 , V_16 ) ;
}
F_32 () ;
return - V_70 ;
}
static int F_33 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_43 ;
int V_75 , V_76 , V_77 ;
unsigned int V_78 = F_34 ( V_38 ) ;
unsigned int V_79 = F_35 ( V_38 ) ;
V_2 -> V_61 = V_78 ;
V_2 -> V_59 = V_43 -> V_80 ;
V_77 = ( V_43 -> V_81 > 1 ) ? 0 : 1 ;
V_76 = F_36 ( V_43 -> V_82 ) == 16 ? 0 : 1 ;
V_75 = F_37 ( V_43 -> V_82 ) ;
V_2 -> V_83 = 2 - V_77 - V_76 ;
F_17 ( V_2 ) ;
F_15 ( V_2 , V_84 , 0x03 , ( V_77 ? 2 : 1 ) ) ;
F_18 ( V_2 , V_38 , V_67 ) ;
V_79 = 0x10000 - V_79 ;
F_13 ( V_2 , V_85 , V_79 & 0xff ) ;
F_13 ( V_2 , V_86 , V_79 >> 8 ) ;
F_13 ( V_2 , V_87 , V_75 ? 0x51 : 0x71 ) ;
F_13 ( V_2 , V_87 , 0x90 |
( V_75 ? 0x00 : 0x20 ) |
( V_76 ? 0x00 : 0x04 ) |
( V_77 ? 0x40 : 0x08 ) ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_43 ;
int V_75 , V_76 , V_77 ;
unsigned int V_78 = F_34 ( V_38 ) ;
unsigned int V_79 = F_35 ( V_38 ) ;
V_2 -> V_54 = V_78 ;
V_2 -> V_51 = V_43 -> V_80 ;
V_77 = ( V_43 -> V_81 > 1 ) ? 0 : 1 ;
V_76 = F_36 ( V_43 -> V_82 ) == 16 ? 0 : 1 ;
V_75 = F_37 ( V_43 -> V_82 ) ;
V_2 -> V_88 = 2 - V_77 - V_76 ;
F_17 ( V_2 ) ;
F_18 ( V_2 , V_38 , V_49 ) ;
V_79 >>= 1 ;
V_79 = 0x10000 - V_79 ;
F_1 ( V_2 , V_89 , V_79 & 0xff ) ;
F_1 ( V_2 , V_90 , V_79 >> 8 ) ;
F_1 ( V_2 , V_91 , 0x40 | ( V_75 ? 0 : 4 ) |
( V_77 ? 0 : 2 ) | ( V_76 ? 0 : 1 ) ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_43 ;
int V_75 , V_76 , V_77 ;
unsigned int V_78 = F_34 ( V_38 ) ;
unsigned int V_79 = F_35 ( V_38 ) ;
V_2 -> V_61 = V_78 ;
V_2 -> V_59 = V_43 -> V_80 ;
V_77 = ( V_43 -> V_81 > 1 ) ? 0 : 1 ;
V_76 = F_36 ( V_43 -> V_82 ) == 16 ? 0 : 1 ;
V_75 = F_37 ( V_43 -> V_82 ) ;
V_2 -> V_83 = 2 - V_77 - V_76 ;
V_79 = 0x10000 - V_79 ;
F_17 ( V_2 ) ;
F_15 ( V_2 , V_84 , 0x03 , ( V_77 ? 2 : 1 ) ) ;
F_18 ( V_2 , V_38 , V_73 ) ;
F_13 ( V_2 , V_85 , V_79 & 0xff ) ;
F_13 ( V_2 , V_86 , V_79 >> 8 ) ;
F_13 ( V_2 , V_92 , V_75 ? 0x80 : 0x00 ) ;
F_13 ( V_2 , V_92 , V_75 ? 0x51 : 0x71 ) ;
F_13 ( V_2 , V_87 ,
0x90 | ( V_77 ? 0x40 : 0x08 ) |
( V_76 ? 0x00 : 0x04 ) | ( V_75 ? 0x00 : 0x20 ) ) ;
F_23 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_37 * V_38 )
{
switch ( V_38 -> V_74 ) {
case 0 :
return F_38 ( V_38 ) ;
case 1 :
return F_39 ( V_38 ) ;
}
F_32 () ;
return - V_70 ;
}
static T_1 F_41 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
T_2 V_93 ;
#if 0
size_t old, new;
old = inw(SLDM_REG(chip, DMACOUNT));
while ((new = inw(SLDM_REG(chip, DMACOUNT))) != old)
old = new;
ptr = chip->dma1_size - 1 - new;
#else
T_2 V_79 ;
unsigned int V_94 ;
V_93 = F_42 ( F_24 ( V_2 , V_60 ) ) ;
V_79 = F_43 ( F_24 ( V_2 , V_62 ) ) ;
V_94 = V_2 -> V_59 + V_2 -> V_61 - V_93 - V_79 ;
if ( V_94 > 3 || V_93 < V_2 -> V_59
|| V_93 >= V_2 -> V_59 + V_2 -> V_61 )
V_93 = V_2 -> V_63 ;
else
V_2 -> V_63 = V_93 ;
V_93 -= V_2 -> V_59 ;
#endif
return V_93 >> V_2 -> V_83 ;
}
static T_1 F_44 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
T_2 V_93 ;
#if 1
V_93 = V_2 -> V_54 - F_43 ( F_20 ( V_2 , V_53 ) ) ;
#else
V_93 = F_42 ( F_20 ( V_2 , V_52 ) ) - V_2 -> V_51 ;
#endif
return V_93 >> V_2 -> V_88 ;
}
static T_1 F_45 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
T_2 V_93 ;
T_2 V_13 , V_14 ;
#if 1
V_13 = F_43 ( F_24 ( V_2 , V_62 ) ) ;
while ( ( V_14 = F_43 ( F_24 ( V_2 , V_62 ) ) ) != V_13 )
V_13 = V_14 ;
V_93 = V_2 -> V_61 - 1 - V_14 ;
#else
V_93 = F_42 ( F_24 ( V_2 , V_60 ) ) - V_2 -> V_59 ;
#endif
return V_93 >> V_2 -> V_83 ;
}
static T_1 F_46 ( struct V_37 * V_38 )
{
switch ( V_38 -> V_74 ) {
case 0 :
return F_44 ( V_38 ) ;
case 1 :
return F_45 ( V_38 ) ;
}
F_32 () ;
return - V_70 ;
}
static int F_47 ( struct V_37 * V_38 ,
int V_95 ,
T_1 V_96 ,
void T_3 * V_97 ,
T_1 V_79 )
{
struct V_42 * V_43 = V_38 -> V_43 ;
struct V_1 * V_2 = F_27 ( V_38 ) ;
V_96 <<= V_2 -> V_83 ;
V_79 <<= V_2 -> V_83 ;
if ( F_48 ( V_96 + V_79 > V_2 -> V_61 ) )
return - V_70 ;
if ( V_96 + V_79 < V_2 -> V_61 ) {
if ( F_49 ( V_97 , V_43 -> V_98 + V_96 + 1 , V_79 ) )
return - V_99 ;
} else {
if ( F_49 ( V_97 , V_43 -> V_98 + V_96 + 1 , V_79 - 1 ) )
return - V_99 ;
if ( F_50 ( V_43 -> V_98 [ 0 ] , ( ( unsigned char T_3 * ) V_97 ) + V_79 - 1 ) )
return - V_99 ;
}
return 0 ;
}
static int F_51 ( struct V_37 * V_38 ,
struct V_100 * V_101 )
{
int V_102 ;
if ( ( V_102 = F_52 ( V_38 , F_53 ( V_101 ) ) ) < 0 )
return V_102 ;
return 0 ;
}
static int F_54 ( struct V_37 * V_38 )
{
return F_55 ( V_38 ) ;
}
static int F_56 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_43 ;
if ( V_2 -> V_103 )
return - V_104 ;
V_2 -> V_105 = V_38 ;
V_43 -> V_106 = V_107 ;
F_57 ( V_43 , 0 , V_108 ,
& V_109 ) ;
F_58 ( V_43 , V_110 , 0 , 0xff00 ) ;
return 0 ;
}
static int F_59 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_43 ;
switch ( V_38 -> V_74 ) {
case 0 :
V_2 -> V_111 = V_38 ;
break;
case 1 :
if ( V_2 -> V_105 )
return - V_104 ;
V_2 -> V_103 = V_38 ;
break;
default:
F_32 () ;
return - V_70 ;
}
V_43 -> V_106 = V_112 ;
F_57 ( V_43 , 0 , V_108 ,
& V_109 ) ;
F_58 ( V_43 , V_110 , 0 , 0xff00 ) ;
return 0 ;
}
static int F_60 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
V_2 -> V_105 = NULL ;
return 0 ;
}
static int F_61 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_27 ( V_38 ) ;
switch ( V_38 -> V_74 ) {
case 0 :
V_2 -> V_111 = NULL ;
break;
case 1 :
V_2 -> V_103 = NULL ;
break;
default:
F_32 () ;
return - V_70 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 , int V_113 )
{
struct V_114 * V_115 ;
int V_102 ;
if ( ( V_102 = F_63 ( V_2 -> V_9 , L_10 , V_113 , 2 , 1 , & V_115 ) ) < 0 )
return V_102 ;
F_64 ( V_115 , V_116 , & V_117 ) ;
F_64 ( V_115 , V_118 , & V_119 ) ;
V_115 -> V_120 = V_2 ;
V_115 -> V_121 = 0 ;
strcpy ( V_115 -> V_122 , L_11 ) ;
F_65 ( V_115 , V_123 ,
F_66 ( V_2 -> V_124 ) , 64 * 1024 , 64 * 1024 ) ;
V_2 -> V_115 = V_115 ;
return 0 ;
}
static int F_67 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
static const char * const V_129 [ 8 ] = {
L_12 , L_13 , L_14 , L_15 ,
L_16 , L_17 , L_18 , L_19
} ;
return F_68 ( V_128 , 1 , 8 , V_129 ) ;
}
static int F_69 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
V_131 -> V_132 . V_133 . V_134 [ 0 ] = F_7 ( V_2 , 0x1c ) & 0x07 ;
return 0 ;
}
static int F_71 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
unsigned char V_4 = V_131 -> V_132 . V_133 . V_134 [ 0 ] ;
if ( V_4 > 7 )
return - V_70 ;
return F_9 ( V_2 , 0x1c , 0x07 , V_4 ) != V_4 ;
}
static int F_72 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
unsigned char V_4 = F_7 ( V_2 , 0x50 ) ;
V_131 -> V_132 . integer . V_132 [ 0 ] = ! ! ( V_4 & 8 ) ;
return 0 ;
}
static int F_73 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
unsigned char V_15 , V_135 ;
int V_136 ;
V_135 = V_131 -> V_132 . integer . V_132 [ 0 ] ? 0x0c : 0x04 ;
V_15 = F_7 ( V_2 , 0x50 ) & 0x0c ;
V_136 = V_135 != V_15 ;
if ( V_136 ) {
F_1 ( V_2 , 0x50 , V_135 & ~ 0x04 ) ;
F_1 ( V_2 , 0x50 , V_135 ) ;
}
return V_136 ;
}
static int F_74 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
V_128 -> type = V_137 ;
V_128 -> V_79 = 2 ;
V_128 -> V_132 . integer . V_138 = 0 ;
V_128 -> V_132 . integer . V_139 = 63 ;
return 0 ;
}
static int F_75 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
V_131 -> V_132 . integer . V_132 [ 0 ] = F_7 ( V_2 , 0x61 ) & 0x3f ;
V_131 -> V_132 . integer . V_132 [ 1 ] = F_7 ( V_2 , 0x63 ) & 0x3f ;
return 0 ;
}
static int F_76 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
V_131 -> V_132 . integer . V_132 [ 0 ] = ! ( F_7 ( V_2 , 0x61 ) & 0x40 ) ;
V_131 -> V_132 . integer . V_132 [ 1 ] = ! ( F_7 ( V_2 , 0x63 ) & 0x40 ) ;
return 0 ;
}
static void F_77 ( struct V_125 * V_126 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
V_2 -> V_140 = NULL ;
V_2 -> V_141 = NULL ;
V_2 -> V_142 = NULL ;
V_2 -> V_143 = NULL ;
}
static int F_78 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_12 , unsigned char V_4 )
{
if ( V_3 < 0xa0 )
return F_9 ( V_2 , V_3 , V_12 , V_4 ) ;
else
return F_15 ( V_2 , V_3 , V_12 , V_4 ) ;
}
static int F_79 ( struct V_1 * V_2 , unsigned char V_3 )
{
if ( V_3 < 0xa0 )
return F_7 ( V_2 , V_3 ) ;
else
return F_14 ( V_2 , V_3 ) ;
}
static int F_80 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
int V_12 = ( V_126 -> V_144 >> 16 ) & 0xff ;
V_128 -> type = V_12 == 1 ? V_145 : V_137 ;
V_128 -> V_79 = 1 ;
V_128 -> V_132 . integer . V_138 = 0 ;
V_128 -> V_132 . integer . V_139 = V_12 ;
return 0 ;
}
static int F_81 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
int V_3 = V_126 -> V_144 & 0xff ;
int V_146 = ( V_126 -> V_144 >> 8 ) & 0xff ;
int V_12 = ( V_126 -> V_144 >> 16 ) & 0xff ;
int V_147 = ( V_126 -> V_144 >> 24 ) & 0xff ;
int V_4 ;
V_4 = F_79 ( V_2 , V_3 ) ;
V_131 -> V_132 . integer . V_132 [ 0 ] = ( V_4 >> V_146 ) & V_12 ;
if ( V_147 )
V_131 -> V_132 . integer . V_132 [ 0 ] = V_12 - V_131 -> V_132 . integer . V_132 [ 0 ] ;
return 0 ;
}
static int F_82 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
int V_3 = V_126 -> V_144 & 0xff ;
int V_146 = ( V_126 -> V_144 >> 8 ) & 0xff ;
int V_12 = ( V_126 -> V_144 >> 16 ) & 0xff ;
int V_147 = ( V_126 -> V_144 >> 24 ) & 0xff ;
unsigned char V_4 ;
V_4 = ( V_131 -> V_132 . integer . V_132 [ 0 ] & V_12 ) ;
if ( V_147 )
V_4 = V_12 - V_4 ;
V_12 <<= V_146 ;
V_4 <<= V_146 ;
return F_78 ( V_2 , V_3 , V_12 , V_4 ) != V_4 ;
}
static int F_83 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
int V_12 = ( V_126 -> V_144 >> 24 ) & 0xff ;
V_128 -> type = V_12 == 1 ? V_145 : V_137 ;
V_128 -> V_79 = 2 ;
V_128 -> V_132 . integer . V_138 = 0 ;
V_128 -> V_132 . integer . V_139 = V_12 ;
return 0 ;
}
static int F_84 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
int V_148 = V_126 -> V_144 & 0xff ;
int V_149 = ( V_126 -> V_144 >> 8 ) & 0xff ;
int V_150 = ( V_126 -> V_144 >> 16 ) & 0x07 ;
int V_151 = ( V_126 -> V_144 >> 19 ) & 0x07 ;
int V_12 = ( V_126 -> V_144 >> 24 ) & 0xff ;
int V_147 = ( V_126 -> V_144 >> 22 ) & 1 ;
unsigned char V_152 , V_153 ;
V_152 = F_79 ( V_2 , V_148 ) ;
if ( V_148 != V_149 )
V_153 = F_79 ( V_2 , V_149 ) ;
else
V_153 = V_152 ;
V_131 -> V_132 . integer . V_132 [ 0 ] = ( V_152 >> V_150 ) & V_12 ;
V_131 -> V_132 . integer . V_132 [ 1 ] = ( V_153 >> V_151 ) & V_12 ;
if ( V_147 ) {
V_131 -> V_132 . integer . V_132 [ 0 ] = V_12 - V_131 -> V_132 . integer . V_132 [ 0 ] ;
V_131 -> V_132 . integer . V_132 [ 1 ] = V_12 - V_131 -> V_132 . integer . V_132 [ 1 ] ;
}
return 0 ;
}
static int F_85 ( struct V_125 * V_126 ,
struct V_130 * V_131 )
{
struct V_1 * V_2 = F_70 ( V_126 ) ;
int V_148 = V_126 -> V_144 & 0xff ;
int V_149 = ( V_126 -> V_144 >> 8 ) & 0xff ;
int V_150 = ( V_126 -> V_144 >> 16 ) & 0x07 ;
int V_151 = ( V_126 -> V_144 >> 19 ) & 0x07 ;
int V_12 = ( V_126 -> V_144 >> 24 ) & 0xff ;
int V_147 = ( V_126 -> V_144 >> 22 ) & 1 ;
int V_136 ;
unsigned char V_154 , V_155 , V_156 , V_157 ;
V_154 = V_131 -> V_132 . integer . V_132 [ 0 ] & V_12 ;
V_155 = V_131 -> V_132 . integer . V_132 [ 1 ] & V_12 ;
if ( V_147 ) {
V_154 = V_12 - V_154 ;
V_155 = V_12 - V_155 ;
}
V_154 <<= V_150 ;
V_155 <<= V_151 ;
V_156 = V_12 << V_150 ;
V_157 = V_12 << V_151 ;
if ( V_148 != V_149 ) {
V_136 = 0 ;
if ( F_78 ( V_2 , V_148 , V_156 , V_154 ) != V_154 )
V_136 = 1 ;
if ( F_78 ( V_2 , V_149 , V_157 , V_155 ) != V_155 )
V_136 = 1 ;
} else {
V_136 = ( F_78 ( V_2 , V_148 , V_156 | V_157 ,
V_154 | V_155 ) != ( V_154 | V_155 ) ) ;
}
return V_136 ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_87 ( V_2 -> V_124 ) ;
F_88 ( V_2 -> V_124 , V_158 , 0x805f ) ;
F_88 ( V_2 -> V_124 , V_159 , V_2 -> V_160 | 1 ) ;
F_89 ( V_2 -> V_124 , V_161 , 0 ) ;
F_3 ( 0xf0 , F_20 ( V_2 , V_162 ) ) ;
F_3 ( 0 , F_24 ( V_2 , V_56 ) ) ;
}
static int F_90 ( struct V_113 * V_10 )
{
struct V_163 * V_9 = F_91 ( V_10 ) ;
struct V_1 * V_2 = V_9 -> V_120 ;
unsigned char * V_164 , * V_165 ;
F_92 ( V_9 , V_166 ) ;
F_93 ( V_2 -> V_115 ) ;
for ( V_164 = V_167 , V_165 = V_2 -> V_167 ; * V_164 ; V_164 ++ , V_165 ++ )
* V_165 = F_79 ( V_2 , * V_164 ) ;
F_3 ( 0x00 , F_20 ( V_2 , V_162 ) ) ;
if ( V_2 -> V_168 >= 0 ) {
F_94 ( V_2 -> V_168 , V_2 ) ;
V_2 -> V_168 = - 1 ;
}
return 0 ;
}
static int F_95 ( struct V_113 * V_10 )
{
struct V_169 * V_124 = F_96 ( V_10 ) ;
struct V_163 * V_9 = F_91 ( V_10 ) ;
struct V_1 * V_2 = V_9 -> V_120 ;
unsigned char * V_164 , * V_165 ;
if ( F_97 ( V_124 -> V_168 , V_170 ,
V_171 , V_172 , V_2 ) ) {
F_11 ( V_10 , L_20 ,
V_124 -> V_168 ) ;
F_98 ( V_9 ) ;
return - V_173 ;
}
V_2 -> V_168 = V_124 -> V_168 ;
F_86 ( V_2 ) ;
for ( V_164 = V_167 , V_165 = V_2 -> V_167 ; * V_164 ; V_164 ++ , V_165 ++ ) {
if ( * V_164 < 0xa0 )
F_1 ( V_2 , * V_164 , * V_165 ) ;
else
F_13 ( V_2 , * V_164 , * V_165 ) ;
}
F_92 ( V_9 , V_174 ) ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_175 * V_176 ;
V_2 -> V_175 = V_176 = F_100 () ;
if ( ! V_176 ) {
F_11 ( V_2 -> V_9 -> V_10 ,
L_21 ) ;
return - V_177 ;
}
F_101 ( V_176 , L_22 ) ;
F_102 ( V_176 , L_23 , F_103 ( V_2 -> V_124 ) ) ;
F_104 ( V_176 , & V_2 -> V_124 -> V_10 ) ;
V_176 -> V_178 = V_2 -> V_179 ;
F_105 ( V_176 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
if ( V_2 -> V_175 ) {
F_107 ( V_2 -> V_175 ) ;
V_2 -> V_175 = NULL ;
}
}
static inline int F_99 ( struct V_1 * V_2 ) { return - V_180 ; }
static inline void F_106 ( struct V_1 * V_2 ) { }
static int F_108 ( struct V_1 * V_2 )
{
F_3 ( 0x00 , F_20 ( V_2 , V_162 ) ) ;
if ( V_2 -> V_181 )
F_9 ( V_2 , V_182 , 0x40 , 0 ) ;
F_106 ( V_2 ) ;
if ( V_2 -> V_168 >= 0 )
F_94 ( V_2 -> V_168 , V_2 ) ;
F_109 ( V_2 -> V_124 ) ;
F_110 ( V_2 -> V_124 ) ;
F_111 ( V_2 ) ;
return 0 ;
}
static int F_112 ( struct V_183 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_184 ;
return F_108 ( V_2 ) ;
}
static int F_113 ( struct V_163 * V_9 ,
struct V_169 * V_124 ,
struct V_1 * * V_185 )
{
struct V_1 * V_2 ;
int V_102 ;
static struct V_186 V_187 = {
. V_188 = F_112 ,
} ;
* V_185 = NULL ;
if ( ( V_102 = F_114 ( V_124 ) ) < 0 )
return V_102 ;
if ( F_115 ( & V_124 -> V_10 , F_116 ( 24 ) ) < 0 ||
F_117 ( & V_124 -> V_10 , F_116 ( 24 ) ) < 0 ) {
F_11 ( V_9 -> V_10 ,
L_24 ) ;
F_110 ( V_124 ) ;
return - V_189 ;
}
V_2 = F_118 ( sizeof( * V_2 ) , V_190 ) ;
if ( V_2 == NULL ) {
F_110 ( V_124 ) ;
return - V_177 ;
}
F_119 ( & V_2 -> V_26 ) ;
F_119 ( & V_2 -> V_6 ) ;
V_2 -> V_9 = V_9 ;
V_2 -> V_124 = V_124 ;
V_2 -> V_168 = - 1 ;
if ( ( V_102 = F_120 ( V_124 , L_11 ) ) < 0 ) {
F_111 ( V_2 ) ;
F_110 ( V_124 ) ;
return V_102 ;
}
V_2 -> V_191 = F_121 ( V_124 , 0 ) ;
V_2 -> V_192 = F_121 ( V_124 , 1 ) ;
V_2 -> V_193 = F_121 ( V_124 , 2 ) ;
V_2 -> V_194 = F_121 ( V_124 , 3 ) ;
V_2 -> V_179 = F_121 ( V_124 , 4 ) ;
if ( F_97 ( V_124 -> V_168 , V_170 , V_171 ,
V_172 , V_2 ) ) {
F_11 ( V_9 -> V_10 , L_25 , V_124 -> V_168 ) ;
F_108 ( V_2 ) ;
return - V_195 ;
}
V_2 -> V_168 = V_124 -> V_168 ;
F_6 ( V_9 -> V_10 ,
L_26 ,
V_2 -> V_191 , V_2 -> V_192 , V_2 -> V_193 , V_2 -> V_194 , V_2 -> V_179 ) ;
V_2 -> V_160 = V_2 -> V_193 + 0x00 ;
F_86 ( V_2 ) ;
if ( ( V_102 = F_122 ( V_9 , V_196 , V_2 , & V_187 ) ) < 0 ) {
F_108 ( V_2 ) ;
return V_102 ;
}
* V_185 = V_2 ;
return 0 ;
}
static T_4 V_170 ( int V_168 , void * V_197 )
{
struct V_1 * V_2 = V_197 ;
unsigned char V_198 , V_199 ;
int V_200 = 0 ;
V_198 = F_8 ( F_20 ( V_2 , V_162 ) ) ;
#if 0
dev_dbg(chip->card->dev,
"Es1938debug - interrupt status: =0x%x\n", status);
#endif
if ( V_198 & 0x10 ) {
#if 0
dev_dbg(chip->card->dev,
"Es1938debug - AUDIO channel 1 interrupt\n");
dev_dbg(chip->card->dev,
"Es1938debug - AUDIO channel 1 DMAC DMA count: %u\n",
inw(SLDM_REG(chip, DMACOUNT)));
dev_dbg(chip->card->dev,
"Es1938debug - AUDIO channel 1 DMAC DMA base: %u\n",
inl(SLDM_REG(chip, DMAADDR)));
dev_dbg(chip->card->dev,
"Es1938debug - AUDIO channel 1 DMAC DMA status: 0x%x\n",
inl(SLDM_REG(chip, DMASTATUS)));
#endif
V_200 = 1 ;
V_199 = F_8 ( F_4 ( V_2 , V_23 ) ) ;
if ( V_2 -> V_66 & V_67 )
F_123 ( V_2 -> V_105 ) ;
else if ( V_2 -> V_66 & V_73 )
F_123 ( V_2 -> V_103 ) ;
}
if ( V_198 & 0x20 ) {
#if 0
dev_dbg(chip->card->dev,
"Es1938debug - AUDIO channel 2 interrupt\n");
dev_dbg(chip->card->dev,
"Es1938debug - AUDIO channel 2 DMAC DMA count: %u\n",
inw(SLIO_REG(chip, AUDIO2DMACOUNT)));
dev_dbg(chip->card->dev,
"Es1938debug - AUDIO channel 2 DMAC DMA base: %u\n",
inl(SLIO_REG(chip, AUDIO2DMAADDR)));
#endif
V_200 = 1 ;
F_9 ( V_2 , V_91 , 0x80 , 0 ) ;
if ( V_2 -> V_66 & V_49 )
F_123 ( V_2 -> V_111 ) ;
}
if ( V_198 & 0x40 ) {
int V_201 = F_7 ( V_2 , 0x64 ) & 0x80 ;
V_200 = 1 ;
F_124 ( V_2 -> V_9 , V_202 , & V_2 -> V_143 -> V_203 ) ;
F_124 ( V_2 -> V_9 , V_202 , & V_2 -> V_142 -> V_203 ) ;
if ( ! V_201 ) {
F_124 ( V_2 -> V_9 , V_202 ,
& V_2 -> V_141 -> V_203 ) ;
F_124 ( V_2 -> V_9 , V_202 ,
& V_2 -> V_140 -> V_203 ) ;
}
F_1 ( V_2 , 0x66 , 0x00 ) ;
}
if ( V_198 & 0x80 ) {
if ( V_2 -> V_181 ) {
V_200 = 1 ;
F_125 ( V_168 , V_2 -> V_181 -> V_120 ) ;
}
}
return F_126 ( V_200 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_163 * V_9 ;
unsigned int V_204 ;
int V_102 ;
V_9 = V_2 -> V_9 ;
strcpy ( V_9 -> V_205 , L_11 ) ;
for ( V_204 = 0 ; V_204 < F_128 ( V_206 ) ; V_204 ++ ) {
struct V_125 * V_207 ;
V_207 = F_129 ( & V_206 [ V_204 ] , V_2 ) ;
switch ( V_204 ) {
case 0 :
V_2 -> V_140 = V_207 ;
V_207 -> V_208 = F_77 ;
break;
case 1 :
V_2 -> V_141 = V_207 ;
V_207 -> V_208 = F_77 ;
break;
case 2 :
V_2 -> V_142 = V_207 ;
V_207 -> V_208 = F_77 ;
break;
case 3 :
V_2 -> V_143 = V_207 ;
V_207 -> V_208 = F_77 ;
break;
}
if ( ( V_102 = F_130 ( V_9 , V_207 ) ) < 0 )
return V_102 ;
}
return 0 ;
}
static int F_131 ( struct V_169 * V_124 ,
const struct V_209 * V_210 )
{
static int V_10 ;
struct V_163 * V_9 ;
struct V_1 * V_2 ;
struct V_211 * V_212 ;
int V_204 , V_102 ;
if ( V_10 >= V_213 )
return - V_25 ;
if ( ! V_214 [ V_10 ] ) {
V_10 ++ ;
return - V_215 ;
}
V_102 = F_132 ( & V_124 -> V_10 , V_216 [ V_10 ] , V_203 [ V_10 ] , V_217 ,
0 , & V_9 ) ;
if ( V_102 < 0 )
return V_102 ;
for ( V_204 = 0 ; V_204 < 5 ; V_204 ++ ) {
if ( F_121 ( V_124 , V_204 ) == 0 ||
! ( F_133 ( V_124 , V_204 ) & V_218 ) ) {
F_134 ( V_9 ) ;
return - V_25 ;
}
}
if ( ( V_102 = F_113 ( V_9 , V_124 , & V_2 ) ) < 0 ) {
F_134 ( V_9 ) ;
return V_102 ;
}
V_9 -> V_120 = V_2 ;
strcpy ( V_9 -> V_219 , L_22 ) ;
strcpy ( V_9 -> V_220 , L_27 ) ;
sprintf ( V_9 -> V_221 , L_28 ,
V_9 -> V_220 ,
V_2 -> V_222 ,
V_2 -> V_168 ) ;
if ( ( V_102 = F_62 ( V_2 , 0 ) ) < 0 ) {
F_134 ( V_9 ) ;
return V_102 ;
}
if ( ( V_102 = F_127 ( V_2 ) ) < 0 ) {
F_134 ( V_9 ) ;
return V_102 ;
}
if ( F_135 ( V_9 ,
F_4 ( V_2 , V_223 ) ,
F_4 ( V_2 , V_224 ) ,
V_225 , 1 , & V_212 ) < 0 ) {
F_11 ( V_9 -> V_10 , L_29 ,
F_4 ( V_2 , V_223 ) ) ;
} else {
if ( ( V_102 = F_136 ( V_212 , 0 , 1 ) ) < 0 ) {
F_134 ( V_9 ) ;
return V_102 ;
}
if ( ( V_102 = F_137 ( V_212 , 0 , 1 , NULL ) ) < 0 ) {
F_134 ( V_9 ) ;
return V_102 ;
}
}
if ( F_138 ( V_9 , 0 , V_226 ,
V_2 -> V_194 ,
V_227 | V_228 ,
- 1 , & V_2 -> V_181 ) < 0 ) {
F_11 ( V_9 -> V_10 , L_30 ) ;
} else {
F_9 ( V_2 , V_182 , 0x40 , 0x40 ) ;
}
F_99 ( V_2 ) ;
if ( ( V_102 = F_139 ( V_9 ) ) < 0 ) {
F_134 ( V_9 ) ;
return V_102 ;
}
F_140 ( V_124 , V_9 ) ;
V_10 ++ ;
return 0 ;
}
static void F_141 ( struct V_169 * V_124 )
{
F_134 ( F_142 ( V_124 ) ) ;
}
