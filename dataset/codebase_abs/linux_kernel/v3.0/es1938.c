static void F_1 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_3 , F_4 ( V_2 , V_7 ) ) ;
F_3 ( V_4 , F_4 ( V_2 , V_8 ) ) ;
F_5 ( & V_2 -> V_6 , V_5 ) ;
#ifdef F_6
F_7 ( V_9 L_1 , V_3 , V_4 ) ;
#endif
}
static int F_8 ( struct V_1 * V_2 , unsigned char V_3 )
{
int V_10 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_3 , F_4 ( V_2 , V_7 ) ) ;
V_10 = F_9 ( F_4 ( V_2 , V_8 ) ) ;
F_5 ( & V_2 -> V_6 , V_5 ) ;
#ifdef F_6
F_7 ( V_9 L_2 , V_3 , V_10 ) ;
#endif
return V_10 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_11 , unsigned char V_4 )
{
unsigned long V_5 ;
unsigned char V_12 , V_13 , V_14 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
F_3 ( V_3 , F_4 ( V_2 , V_7 ) ) ;
V_12 = F_9 ( F_4 ( V_2 , V_8 ) ) ;
V_14 = V_12 & V_11 ;
if ( V_4 != V_14 ) {
V_13 = ( V_12 & ~ V_11 ) | ( V_4 & V_11 ) ;
F_3 ( V_13 , F_4 ( V_2 , V_8 ) ) ;
#ifdef F_6
F_7 ( V_9 L_3 ,
V_3 , V_12 , V_13 ) ;
#endif
}
F_5 ( & V_2 -> V_6 , V_5 ) ;
return V_14 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned char V_15 )
{
int V_16 ;
unsigned char V_17 ;
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
if ( ! ( V_17 = F_9 ( F_4 ( V_2 , V_19 ) ) & 0x80 ) ) {
F_3 ( V_15 , F_4 ( V_2 , V_20 ) ) ;
return;
}
}
F_12 ( V_21 L_4 , V_15 , V_17 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_16 ;
unsigned char V_17 ;
for ( V_16 = V_22 ; V_16 ; V_16 -- )
if ( ( V_17 = F_9 ( F_4 ( V_2 , V_23 ) ) ) & 0x80 )
return F_9 ( F_4 ( V_2 , V_24 ) ) ;
F_7 ( V_21 L_5 , V_17 ) ;
return - V_25 ;
}
static void F_14 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_26 , V_5 ) ;
F_11 ( V_2 , V_3 ) ;
F_11 ( V_2 , V_4 ) ;
F_5 ( & V_2 -> V_26 , V_5 ) ;
#ifdef F_6
F_7 ( V_9 L_6 , V_3 , V_4 ) ;
#endif
}
static unsigned char F_15 ( struct V_1 * V_2 , unsigned char V_3 )
{
unsigned char V_4 ;
unsigned long V_5 ;
F_2 ( & V_2 -> V_26 , V_5 ) ;
F_11 ( V_2 , V_27 ) ;
F_11 ( V_2 , V_3 ) ;
V_4 = F_13 ( V_2 ) ;
F_5 ( & V_2 -> V_26 , V_5 ) ;
#ifdef F_6
F_7 ( V_9 L_7 , V_3 , V_4 ) ;
#endif
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned char V_3 , unsigned char V_11 ,
unsigned char V_4 )
{
unsigned long V_5 ;
unsigned char V_12 , V_13 , V_14 ;
F_2 ( & V_2 -> V_26 , V_5 ) ;
F_11 ( V_2 , V_27 ) ;
F_11 ( V_2 , V_3 ) ;
V_12 = F_13 ( V_2 ) ;
V_14 = V_12 & V_11 ;
if ( V_4 != V_14 ) {
F_11 ( V_2 , V_3 ) ;
V_13 = ( V_12 & ~ V_11 ) | ( V_4 & V_11 ) ;
F_11 ( V_2 , V_13 ) ;
#ifdef F_6
F_7 ( V_9 L_8 ,
V_3 , V_12 , V_13 ) ;
#endif
}
F_5 ( & V_2 -> V_26 , V_5 ) ;
return V_14 ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_16 ;
F_3 ( 3 , F_4 ( V_2 , V_28 ) ) ;
F_9 ( F_4 ( V_2 , V_28 ) ) ;
F_3 ( 0 , F_4 ( V_2 , V_28 ) ) ;
for ( V_16 = 0 ; V_16 < V_29 ; V_16 ++ ) {
if ( F_9 ( F_4 ( V_2 , V_23 ) ) & 0x80 ) {
if ( F_9 ( F_4 ( V_2 , V_24 ) ) == 0xaa )
goto V_30;
}
}
F_7 ( V_21 L_9 ) ;
V_30:
F_11 ( V_2 , V_31 ) ;
F_14 ( V_2 , V_32 , 2 ) ;
F_1 ( V_2 , V_33 , 0x32 ) ;
F_16 ( V_2 , V_34 , 0xf0 , 0x50 ) ;
F_16 ( V_2 , V_35 , 0xf0 , 0x50 ) ;
F_11 ( V_2 , V_36 ) ;
F_1 ( V_2 , 0x54 , 0x8f ) ;
F_1 ( V_2 , 0x56 , 0x95 ) ;
F_1 ( V_2 , 0x58 , 0x94 ) ;
F_1 ( V_2 , 0x5a , 0x80 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_3 ( 2 , F_4 ( V_2 , V_28 ) ) ;
F_3 ( 0 , F_4 ( V_2 , V_28 ) ) ;
}
static void F_19 ( struct V_1 * V_2 ,
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
F_14 ( V_2 , 0xA1 , V_40 ) ;
F_14 ( V_2 , 0xA2 , V_41 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
F_3 ( 0x00 , F_21 ( V_2 , V_50 ) ) ;
F_22 ( V_2 -> V_51 , F_21 ( V_2 , V_52 ) ) ;
F_23 ( 0 , F_21 ( V_2 , V_53 ) ) ;
F_23 ( V_2 -> V_54 , F_21 ( V_2 , V_53 ) ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_3 ( 0xc4 , F_25 ( V_2 , V_55 ) ) ;
F_3 ( 0 , F_25 ( V_2 , V_56 ) ) ;
F_3 ( 1 , F_25 ( V_2 , V_57 ) ) ;
F_3 ( 0x18 , F_25 ( V_2 , V_58 ) ) ;
F_22 ( V_2 -> V_59 , F_25 ( V_2 , V_60 ) ) ;
F_23 ( V_2 -> V_61 - 1 , F_25 ( V_2 , V_62 ) ) ;
F_3 ( 0 , F_25 ( V_2 , V_57 ) ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_3 ( 0xc4 , F_25 ( V_2 , V_55 ) ) ;
F_3 ( 0 , F_25 ( V_2 , V_56 ) ) ;
F_3 ( 1 , F_25 ( V_2 , V_57 ) ) ;
F_3 ( 0x14 , F_25 ( V_2 , V_58 ) ) ;
F_22 ( V_2 -> V_59 , F_25 ( V_2 , V_60 ) ) ;
V_2 -> V_63 = V_2 -> V_59 ;
F_23 ( V_2 -> V_61 - 1 , F_25 ( V_2 , V_62 ) ) ;
F_3 ( 0 , F_25 ( V_2 , V_57 ) ) ;
}
static int F_27 ( struct V_37 * V_38 ,
int V_15 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
int V_4 ;
switch ( V_15 ) {
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
F_14 ( V_2 , V_71 , V_4 ) ;
return 0 ;
}
static int F_29 ( struct V_37 * V_38 ,
int V_15 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
switch ( V_15 ) {
case V_64 :
case V_65 :
F_1 ( V_2 , V_72 , 0x92 ) ;
F_30 ( 10 ) ;
F_1 ( V_2 , V_72 , 0x93 ) ;
F_3 ( 0x0a , F_21 ( V_2 , V_50 ) ) ;
V_2 -> V_66 |= V_49 ;
break;
case V_68 :
case V_69 :
F_3 ( 0 , F_21 ( V_2 , V_50 ) ) ;
F_1 ( V_2 , V_72 , 0 ) ;
V_2 -> V_66 &= ~ V_49 ;
break;
default:
return - V_70 ;
}
return 0 ;
}
static int F_31 ( struct V_37 * V_38 ,
int V_15 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
int V_4 ;
switch ( V_15 ) {
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
F_14 ( V_2 , V_71 , V_4 ) ;
return 0 ;
}
static int F_32 ( struct V_37 * V_38 ,
int V_15 )
{
switch ( V_38 -> V_74 ) {
case 0 :
return F_29 ( V_38 , V_15 ) ;
case 1 :
return F_31 ( V_38 , V_15 ) ;
}
F_33 () ;
return - V_70 ;
}
static int F_34 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_43 ;
int V_75 , V_76 , V_77 ;
unsigned int V_78 = F_35 ( V_38 ) ;
unsigned int V_79 = F_36 ( V_38 ) ;
V_2 -> V_61 = V_78 ;
V_2 -> V_59 = V_43 -> V_80 ;
V_77 = ( V_43 -> V_81 > 1 ) ? 0 : 1 ;
V_76 = F_37 ( V_43 -> V_82 ) == 16 ? 0 : 1 ;
V_75 = F_38 ( V_43 -> V_82 ) ;
V_2 -> V_83 = 2 - V_77 - V_76 ;
F_18 ( V_2 ) ;
F_16 ( V_2 , V_84 , 0x03 , ( V_77 ? 2 : 1 ) ) ;
F_19 ( V_2 , V_38 , V_67 ) ;
V_79 = 0x10000 - V_79 ;
F_14 ( V_2 , V_85 , V_79 & 0xff ) ;
F_14 ( V_2 , V_86 , V_79 >> 8 ) ;
F_14 ( V_2 , V_87 , V_75 ? 0x51 : 0x71 ) ;
F_14 ( V_2 , V_87 , 0x90 |
( V_75 ? 0x00 : 0x20 ) |
( V_76 ? 0x00 : 0x04 ) |
( V_77 ? 0x40 : 0x08 ) ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_43 ;
int V_75 , V_76 , V_77 ;
unsigned int V_78 = F_35 ( V_38 ) ;
unsigned int V_79 = F_36 ( V_38 ) ;
V_2 -> V_54 = V_78 ;
V_2 -> V_51 = V_43 -> V_80 ;
V_77 = ( V_43 -> V_81 > 1 ) ? 0 : 1 ;
V_76 = F_37 ( V_43 -> V_82 ) == 16 ? 0 : 1 ;
V_75 = F_38 ( V_43 -> V_82 ) ;
V_2 -> V_88 = 2 - V_77 - V_76 ;
F_18 ( V_2 ) ;
F_19 ( V_2 , V_38 , V_49 ) ;
V_79 >>= 1 ;
V_79 = 0x10000 - V_79 ;
F_1 ( V_2 , V_89 , V_79 & 0xff ) ;
F_1 ( V_2 , V_90 , V_79 >> 8 ) ;
F_1 ( V_2 , V_91 , 0x40 | ( V_75 ? 0 : 4 ) |
( V_77 ? 0 : 2 ) | ( V_76 ? 0 : 1 ) ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_43 ;
int V_75 , V_76 , V_77 ;
unsigned int V_78 = F_35 ( V_38 ) ;
unsigned int V_79 = F_36 ( V_38 ) ;
V_2 -> V_61 = V_78 ;
V_2 -> V_59 = V_43 -> V_80 ;
V_77 = ( V_43 -> V_81 > 1 ) ? 0 : 1 ;
V_76 = F_37 ( V_43 -> V_82 ) == 16 ? 0 : 1 ;
V_75 = F_38 ( V_43 -> V_82 ) ;
V_2 -> V_83 = 2 - V_77 - V_76 ;
V_79 = 0x10000 - V_79 ;
F_18 ( V_2 ) ;
F_16 ( V_2 , V_84 , 0x03 , ( V_77 ? 2 : 1 ) ) ;
F_19 ( V_2 , V_38 , V_73 ) ;
F_14 ( V_2 , V_85 , V_79 & 0xff ) ;
F_14 ( V_2 , V_86 , V_79 >> 8 ) ;
F_14 ( V_2 , V_92 , V_75 ? 0x80 : 0x00 ) ;
F_14 ( V_2 , V_92 , V_75 ? 0x51 : 0x71 ) ;
F_14 ( V_2 , V_87 ,
0x90 | ( V_77 ? 0x40 : 0x08 ) |
( V_76 ? 0x00 : 0x04 ) | ( V_75 ? 0x00 : 0x20 ) ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_37 * V_38 )
{
switch ( V_38 -> V_74 ) {
case 0 :
return F_39 ( V_38 ) ;
case 1 :
return F_40 ( V_38 ) ;
}
F_33 () ;
return - V_70 ;
}
static T_1 F_42 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
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
V_93 = F_43 ( F_25 ( V_2 , V_60 ) ) ;
V_79 = F_44 ( F_25 ( V_2 , V_62 ) ) ;
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
static T_1 F_45 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
T_2 V_93 ;
#if 1
V_93 = V_2 -> V_54 - F_44 ( F_21 ( V_2 , V_53 ) ) ;
#else
V_93 = F_43 ( F_21 ( V_2 , V_52 ) ) - V_2 -> V_51 ;
#endif
return V_93 >> V_2 -> V_88 ;
}
static T_1 F_46 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
T_2 V_93 ;
T_2 V_12 , V_13 ;
#if 1
V_12 = F_44 ( F_25 ( V_2 , V_62 ) ) ;
while ( ( V_13 = F_44 ( F_25 ( V_2 , V_62 ) ) ) != V_12 )
V_12 = V_13 ;
V_93 = V_2 -> V_61 - 1 - V_13 ;
#else
V_93 = F_43 ( F_25 ( V_2 , V_60 ) ) - V_2 -> V_59 ;
#endif
return V_93 >> V_2 -> V_83 ;
}
static T_1 F_47 ( struct V_37 * V_38 )
{
switch ( V_38 -> V_74 ) {
case 0 :
return F_45 ( V_38 ) ;
case 1 :
return F_46 ( V_38 ) ;
}
F_33 () ;
return - V_70 ;
}
static int F_48 ( struct V_37 * V_38 ,
int V_95 ,
T_1 V_96 ,
void T_3 * V_97 ,
T_1 V_79 )
{
struct V_42 * V_43 = V_38 -> V_43 ;
struct V_1 * V_2 = F_28 ( V_38 ) ;
V_96 <<= V_2 -> V_83 ;
V_79 <<= V_2 -> V_83 ;
if ( F_49 ( V_96 + V_79 > V_2 -> V_61 ) )
return - V_70 ;
if ( V_96 + V_79 < V_2 -> V_61 ) {
if ( F_50 ( V_97 , V_43 -> V_98 + V_96 + 1 , V_79 ) )
return - V_99 ;
} else {
if ( F_50 ( V_97 , V_43 -> V_98 + V_96 + 1 , V_79 - 1 ) )
return - V_99 ;
if ( F_51 ( V_43 -> V_98 [ 0 ] , ( ( unsigned char T_3 * ) V_97 ) + V_79 - 1 ) )
return - V_99 ;
}
return 0 ;
}
static int F_52 ( struct V_37 * V_38 ,
struct V_100 * V_101 )
{
int V_102 ;
if ( ( V_102 = F_53 ( V_38 , F_54 ( V_101 ) ) ) < 0 )
return V_102 ;
return 0 ;
}
static int F_55 ( struct V_37 * V_38 )
{
return F_56 ( V_38 ) ;
}
static int F_57 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
struct V_42 * V_43 = V_38 -> V_43 ;
if ( V_2 -> V_103 )
return - V_104 ;
V_2 -> V_105 = V_38 ;
V_43 -> V_106 = V_107 ;
F_58 ( V_43 , 0 , V_108 ,
& V_109 ) ;
F_59 ( V_43 , V_110 , 0 , 0xff00 ) ;
return 0 ;
}
static int F_60 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
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
F_33 () ;
return - V_70 ;
}
V_43 -> V_106 = V_112 ;
F_58 ( V_43 , 0 , V_108 ,
& V_109 ) ;
F_59 ( V_43 , V_110 , 0 , 0xff00 ) ;
return 0 ;
}
static int F_61 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
V_2 -> V_105 = NULL ;
return 0 ;
}
static int F_62 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_28 ( V_38 ) ;
switch ( V_38 -> V_74 ) {
case 0 :
V_2 -> V_111 = NULL ;
break;
case 1 :
V_2 -> V_103 = NULL ;
break;
default:
F_33 () ;
return - V_70 ;
}
return 0 ;
}
static int T_4 F_63 ( struct V_1 * V_2 , int V_113 )
{
struct V_114 * V_115 ;
int V_102 ;
if ( ( V_102 = F_64 ( V_2 -> V_116 , L_10 , V_113 , 2 , 1 , & V_115 ) ) < 0 )
return V_102 ;
F_65 ( V_115 , V_117 , & V_118 ) ;
F_65 ( V_115 , V_119 , & V_120 ) ;
V_115 -> V_121 = V_2 ;
V_115 -> V_122 = 0 ;
strcpy ( V_115 -> V_123 , L_11 ) ;
F_66 ( V_115 , V_124 ,
F_67 ( V_2 -> V_125 ) , 64 * 1024 , 64 * 1024 ) ;
V_2 -> V_115 = V_115 ;
return 0 ;
}
static int F_68 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
static char * V_130 [ 8 ] = {
L_12 , L_13 , L_14 , L_15 ,
L_16 , L_17 , L_18 , L_19
} ;
V_129 -> type = V_131 ;
V_129 -> V_79 = 1 ;
V_129 -> V_132 . V_133 . V_134 = 8 ;
if ( V_129 -> V_132 . V_133 . V_135 > 7 )
V_129 -> V_132 . V_133 . V_135 = 7 ;
strcpy ( V_129 -> V_132 . V_133 . V_123 , V_130 [ V_129 -> V_132 . V_133 . V_135 ] ) ;
return 0 ;
}
static int F_69 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
V_137 -> V_132 . V_133 . V_135 [ 0 ] = F_8 ( V_2 , 0x1c ) & 0x07 ;
return 0 ;
}
static int F_71 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
unsigned char V_4 = V_137 -> V_132 . V_133 . V_135 [ 0 ] ;
if ( V_4 > 7 )
return - V_70 ;
return F_10 ( V_2 , 0x1c , 0x07 , V_4 ) != V_4 ;
}
static int F_72 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
unsigned char V_4 = F_8 ( V_2 , 0x50 ) ;
V_137 -> V_132 . integer . V_132 [ 0 ] = ! ! ( V_4 & 8 ) ;
return 0 ;
}
static int F_73 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
unsigned char V_14 , V_138 ;
int V_139 ;
V_138 = V_137 -> V_132 . integer . V_132 [ 0 ] ? 0x0c : 0x04 ;
V_14 = F_8 ( V_2 , 0x50 ) & 0x0c ;
V_139 = V_138 != V_14 ;
if ( V_139 ) {
F_1 ( V_2 , 0x50 , V_138 & ~ 0x04 ) ;
F_1 ( V_2 , 0x50 , V_138 ) ;
}
return V_139 ;
}
static int F_74 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
V_129 -> type = V_140 ;
V_129 -> V_79 = 2 ;
V_129 -> V_132 . integer . V_141 = 0 ;
V_129 -> V_132 . integer . V_142 = 63 ;
return 0 ;
}
static int F_75 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
V_137 -> V_132 . integer . V_132 [ 0 ] = F_8 ( V_2 , 0x61 ) & 0x3f ;
V_137 -> V_132 . integer . V_132 [ 1 ] = F_8 ( V_2 , 0x63 ) & 0x3f ;
return 0 ;
}
static int F_76 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
V_137 -> V_132 . integer . V_132 [ 0 ] = ! ( F_8 ( V_2 , 0x61 ) & 0x40 ) ;
V_137 -> V_132 . integer . V_132 [ 1 ] = ! ( F_8 ( V_2 , 0x63 ) & 0x40 ) ;
return 0 ;
}
static void F_77 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
V_2 -> V_143 = NULL ;
V_2 -> V_144 = NULL ;
V_2 -> V_145 = NULL ;
V_2 -> V_146 = NULL ;
}
static int F_78 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_11 , unsigned char V_4 )
{
if ( V_3 < 0xa0 )
return F_10 ( V_2 , V_3 , V_11 , V_4 ) ;
else
return F_16 ( V_2 , V_3 , V_11 , V_4 ) ;
}
static int F_79 ( struct V_1 * V_2 , unsigned char V_3 )
{
if ( V_3 < 0xa0 )
return F_8 ( V_2 , V_3 ) ;
else
return F_15 ( V_2 , V_3 ) ;
}
static int F_80 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
int V_11 = ( V_127 -> V_147 >> 16 ) & 0xff ;
V_129 -> type = V_11 == 1 ? V_148 : V_140 ;
V_129 -> V_79 = 1 ;
V_129 -> V_132 . integer . V_141 = 0 ;
V_129 -> V_132 . integer . V_142 = V_11 ;
return 0 ;
}
static int F_81 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
int V_3 = V_127 -> V_147 & 0xff ;
int V_149 = ( V_127 -> V_147 >> 8 ) & 0xff ;
int V_11 = ( V_127 -> V_147 >> 16 ) & 0xff ;
int V_150 = ( V_127 -> V_147 >> 24 ) & 0xff ;
int V_4 ;
V_4 = F_79 ( V_2 , V_3 ) ;
V_137 -> V_132 . integer . V_132 [ 0 ] = ( V_4 >> V_149 ) & V_11 ;
if ( V_150 )
V_137 -> V_132 . integer . V_132 [ 0 ] = V_11 - V_137 -> V_132 . integer . V_132 [ 0 ] ;
return 0 ;
}
static int F_82 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
int V_3 = V_127 -> V_147 & 0xff ;
int V_149 = ( V_127 -> V_147 >> 8 ) & 0xff ;
int V_11 = ( V_127 -> V_147 >> 16 ) & 0xff ;
int V_150 = ( V_127 -> V_147 >> 24 ) & 0xff ;
unsigned char V_4 ;
V_4 = ( V_137 -> V_132 . integer . V_132 [ 0 ] & V_11 ) ;
if ( V_150 )
V_4 = V_11 - V_4 ;
V_11 <<= V_149 ;
V_4 <<= V_149 ;
return F_78 ( V_2 , V_3 , V_11 , V_4 ) != V_4 ;
}
static int F_83 ( struct V_126 * V_127 ,
struct V_128 * V_129 )
{
int V_11 = ( V_127 -> V_147 >> 24 ) & 0xff ;
V_129 -> type = V_11 == 1 ? V_148 : V_140 ;
V_129 -> V_79 = 2 ;
V_129 -> V_132 . integer . V_141 = 0 ;
V_129 -> V_132 . integer . V_142 = V_11 ;
return 0 ;
}
static int F_84 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
int V_151 = V_127 -> V_147 & 0xff ;
int V_152 = ( V_127 -> V_147 >> 8 ) & 0xff ;
int V_153 = ( V_127 -> V_147 >> 16 ) & 0x07 ;
int V_154 = ( V_127 -> V_147 >> 19 ) & 0x07 ;
int V_11 = ( V_127 -> V_147 >> 24 ) & 0xff ;
int V_150 = ( V_127 -> V_147 >> 22 ) & 1 ;
unsigned char V_155 , V_156 ;
V_155 = F_79 ( V_2 , V_151 ) ;
if ( V_151 != V_152 )
V_156 = F_79 ( V_2 , V_152 ) ;
else
V_156 = V_155 ;
V_137 -> V_132 . integer . V_132 [ 0 ] = ( V_155 >> V_153 ) & V_11 ;
V_137 -> V_132 . integer . V_132 [ 1 ] = ( V_156 >> V_154 ) & V_11 ;
if ( V_150 ) {
V_137 -> V_132 . integer . V_132 [ 0 ] = V_11 - V_137 -> V_132 . integer . V_132 [ 0 ] ;
V_137 -> V_132 . integer . V_132 [ 1 ] = V_11 - V_137 -> V_132 . integer . V_132 [ 1 ] ;
}
return 0 ;
}
static int F_85 ( struct V_126 * V_127 ,
struct V_136 * V_137 )
{
struct V_1 * V_2 = F_70 ( V_127 ) ;
int V_151 = V_127 -> V_147 & 0xff ;
int V_152 = ( V_127 -> V_147 >> 8 ) & 0xff ;
int V_153 = ( V_127 -> V_147 >> 16 ) & 0x07 ;
int V_154 = ( V_127 -> V_147 >> 19 ) & 0x07 ;
int V_11 = ( V_127 -> V_147 >> 24 ) & 0xff ;
int V_150 = ( V_127 -> V_147 >> 22 ) & 1 ;
int V_139 ;
unsigned char V_157 , V_158 , V_159 , V_160 ;
V_157 = V_137 -> V_132 . integer . V_132 [ 0 ] & V_11 ;
V_158 = V_137 -> V_132 . integer . V_132 [ 1 ] & V_11 ;
if ( V_150 ) {
V_157 = V_11 - V_157 ;
V_158 = V_11 - V_158 ;
}
V_157 <<= V_153 ;
V_158 <<= V_154 ;
V_159 = V_11 << V_153 ;
V_160 = V_11 << V_154 ;
if ( V_151 != V_152 ) {
V_139 = 0 ;
if ( F_78 ( V_2 , V_151 , V_159 , V_157 ) != V_157 )
V_139 = 1 ;
if ( F_78 ( V_2 , V_152 , V_160 , V_158 ) != V_158 )
V_139 = 1 ;
} else {
V_139 = ( F_78 ( V_2 , V_151 , V_159 | V_160 ,
V_157 | V_158 ) != ( V_157 | V_158 ) ) ;
}
return V_139 ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_87 ( V_2 -> V_125 ) ;
F_88 ( V_2 -> V_125 , V_161 , 0x805f ) ;
F_88 ( V_2 -> V_125 , V_162 , V_2 -> V_163 | 1 ) ;
F_89 ( V_2 -> V_125 , V_164 , 0 ) ;
F_3 ( 0xf0 , F_21 ( V_2 , V_165 ) ) ;
F_3 ( 0 , F_25 ( V_2 , V_56 ) ) ;
}
static int F_90 ( struct V_166 * V_125 , T_5 V_167 )
{
struct V_168 * V_116 = F_91 ( V_125 ) ;
struct V_1 * V_2 = V_116 -> V_121 ;
unsigned char * V_169 , * V_170 ;
F_92 ( V_116 , V_171 ) ;
F_93 ( V_2 -> V_115 ) ;
for ( V_169 = V_172 , V_170 = V_2 -> V_172 ; * V_169 ; V_169 ++ , V_170 ++ )
* V_170 = F_79 ( V_2 , * V_169 ) ;
F_3 ( 0x00 , F_21 ( V_2 , V_165 ) ) ;
if ( V_2 -> V_173 >= 0 ) {
F_94 ( V_2 -> V_173 , V_2 ) ;
V_2 -> V_173 = - 1 ;
}
F_95 ( V_125 ) ;
F_96 ( V_125 ) ;
F_97 ( V_125 , F_98 ( V_125 , V_167 ) ) ;
return 0 ;
}
static int F_99 ( struct V_166 * V_125 )
{
struct V_168 * V_116 = F_91 ( V_125 ) ;
struct V_1 * V_2 = V_116 -> V_121 ;
unsigned char * V_169 , * V_170 ;
F_97 ( V_125 , V_174 ) ;
F_100 ( V_125 ) ;
if ( F_101 ( V_125 ) < 0 ) {
F_12 ( V_21 L_20
L_21 ) ;
F_102 ( V_116 ) ;
return - V_175 ;
}
if ( F_103 ( V_125 -> V_173 , V_176 ,
V_177 , L_22 , V_2 ) ) {
F_12 ( V_21 L_23
L_21 , V_125 -> V_173 ) ;
F_102 ( V_116 ) ;
return - V_175 ;
}
V_2 -> V_173 = V_125 -> V_173 ;
F_86 ( V_2 ) ;
for ( V_169 = V_172 , V_170 = V_2 -> V_172 ; * V_169 ; V_169 ++ , V_170 ++ ) {
if ( * V_169 < 0xa0 )
F_1 ( V_2 , * V_169 , * V_170 ) ;
else
F_14 ( V_2 , * V_169 , * V_170 ) ;
}
F_92 ( V_116 , V_178 ) ;
return 0 ;
}
static int T_4 F_104 ( struct V_1 * V_2 )
{
struct V_179 * V_180 ;
V_2 -> V_179 = V_180 = F_105 () ;
if ( ! V_180 ) {
F_12 ( V_21 L_24 ) ;
return - V_181 ;
}
F_106 ( V_180 , L_22 ) ;
F_107 ( V_180 , L_25 , F_108 ( V_2 -> V_125 ) ) ;
F_109 ( V_180 , & V_2 -> V_125 -> V_182 ) ;
V_180 -> V_183 = V_2 -> V_184 ;
F_110 ( V_180 ) ;
return 0 ;
}
static void F_111 ( struct V_1 * V_2 )
{
if ( V_2 -> V_179 ) {
F_112 ( V_2 -> V_179 ) ;
V_2 -> V_179 = NULL ;
}
}
static inline int F_104 ( struct V_1 * V_2 ) { return - V_185 ; }
static inline void F_111 ( struct V_1 * V_2 ) { }
static int F_113 ( struct V_1 * V_2 )
{
F_3 ( 0x00 , F_21 ( V_2 , V_165 ) ) ;
if ( V_2 -> V_186 )
F_10 ( V_2 , V_187 , 0x40 , 0 ) ;
F_111 ( V_2 ) ;
if ( V_2 -> V_173 >= 0 )
F_94 ( V_2 -> V_173 , V_2 ) ;
F_114 ( V_2 -> V_125 ) ;
F_95 ( V_2 -> V_125 ) ;
F_115 ( V_2 ) ;
return 0 ;
}
static int F_116 ( struct V_188 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_189 ;
return F_113 ( V_2 ) ;
}
static int T_4 F_117 ( struct V_168 * V_116 ,
struct V_166 * V_125 ,
struct V_1 * * V_190 )
{
struct V_1 * V_2 ;
int V_102 ;
static struct V_191 V_192 = {
. V_193 = F_116 ,
} ;
* V_190 = NULL ;
if ( ( V_102 = F_101 ( V_125 ) ) < 0 )
return V_102 ;
if ( F_118 ( V_125 , F_119 ( 24 ) ) < 0 ||
F_120 ( V_125 , F_119 ( 24 ) ) < 0 ) {
F_7 ( V_21 L_26 ) ;
F_95 ( V_125 ) ;
return - V_194 ;
}
V_2 = F_121 ( sizeof( * V_2 ) , V_195 ) ;
if ( V_2 == NULL ) {
F_95 ( V_125 ) ;
return - V_181 ;
}
F_122 ( & V_2 -> V_26 ) ;
F_122 ( & V_2 -> V_6 ) ;
V_2 -> V_116 = V_116 ;
V_2 -> V_125 = V_125 ;
V_2 -> V_173 = - 1 ;
if ( ( V_102 = F_123 ( V_125 , L_11 ) ) < 0 ) {
F_115 ( V_2 ) ;
F_95 ( V_125 ) ;
return V_102 ;
}
V_2 -> V_196 = F_124 ( V_125 , 0 ) ;
V_2 -> V_197 = F_124 ( V_125 , 1 ) ;
V_2 -> V_198 = F_124 ( V_125 , 2 ) ;
V_2 -> V_199 = F_124 ( V_125 , 3 ) ;
V_2 -> V_184 = F_124 ( V_125 , 4 ) ;
if ( F_103 ( V_125 -> V_173 , V_176 , V_177 ,
L_22 , V_2 ) ) {
F_7 ( V_21 L_27 , V_125 -> V_173 ) ;
F_113 ( V_2 ) ;
return - V_200 ;
}
V_2 -> V_173 = V_125 -> V_173 ;
#ifdef F_125
F_7 ( V_9 L_28 ,
V_2 -> V_196 , V_2 -> V_197 , V_2 -> V_198 , V_2 -> V_199 , V_2 -> V_184 ) ;
#endif
V_2 -> V_163 = V_2 -> V_198 + 0x00 ;
F_86 ( V_2 ) ;
if ( ( V_102 = F_126 ( V_116 , V_201 , V_2 , & V_192 ) ) < 0 ) {
F_113 ( V_2 ) ;
return V_102 ;
}
F_127 ( V_116 , & V_125 -> V_182 ) ;
* V_190 = V_2 ;
return 0 ;
}
static T_6 V_176 ( int V_173 , void * V_202 )
{
struct V_1 * V_2 = V_202 ;
unsigned char V_203 , V_204 ;
int V_205 = 0 ;
V_203 = F_9 ( F_21 ( V_2 , V_165 ) ) ;
#if 0
printk(KERN_DEBUG "Es1938debug - interrupt status: =0x%x\n", status);
#endif
if ( V_203 & 0x10 ) {
#if 0
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 1 interrupt\n");
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 1 DMAC DMA count: %u\n",
inw(SLDM_REG(chip, DMACOUNT)));
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 1 DMAC DMA base: %u\n",
inl(SLDM_REG(chip, DMAADDR)));
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 1 DMAC DMA status: 0x%x\n",
inl(SLDM_REG(chip, DMASTATUS)));
#endif
V_205 = 1 ;
V_204 = F_9 ( F_4 ( V_2 , V_23 ) ) ;
if ( V_2 -> V_66 & V_67 )
F_128 ( V_2 -> V_105 ) ;
else if ( V_2 -> V_66 & V_73 )
F_128 ( V_2 -> V_103 ) ;
}
if ( V_203 & 0x20 ) {
#if 0
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 2 interrupt\n");
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 2 DMAC DMA count: %u\n",
inw(SLIO_REG(chip, AUDIO2DMACOUNT)));
printk(KERN_DEBUG
"Es1938debug - AUDIO channel 2 DMAC DMA base: %u\n",
inl(SLIO_REG(chip, AUDIO2DMAADDR)));
#endif
V_205 = 1 ;
F_10 ( V_2 , V_91 , 0x80 , 0 ) ;
if ( V_2 -> V_66 & V_49 )
F_128 ( V_2 -> V_111 ) ;
}
if ( V_203 & 0x40 ) {
int V_206 = F_8 ( V_2 , 0x64 ) & 0x80 ;
V_205 = 1 ;
F_129 ( V_2 -> V_116 , V_207 , & V_2 -> V_146 -> V_208 ) ;
F_129 ( V_2 -> V_116 , V_207 , & V_2 -> V_145 -> V_208 ) ;
if ( ! V_206 ) {
F_129 ( V_2 -> V_116 , V_207 ,
& V_2 -> V_144 -> V_208 ) ;
F_129 ( V_2 -> V_116 , V_207 ,
& V_2 -> V_143 -> V_208 ) ;
}
F_1 ( V_2 , 0x66 , 0x00 ) ;
}
if ( V_203 & 0x80 ) {
if ( V_2 -> V_186 ) {
V_205 = 1 ;
F_130 ( V_173 , V_2 -> V_186 -> V_121 ) ;
}
}
return F_131 ( V_205 ) ;
}
static int T_4 F_132 ( struct V_1 * V_2 )
{
struct V_168 * V_116 ;
unsigned int V_209 ;
int V_102 ;
V_116 = V_2 -> V_116 ;
strcpy ( V_116 -> V_210 , L_11 ) ;
for ( V_209 = 0 ; V_209 < F_133 ( V_211 ) ; V_209 ++ ) {
struct V_126 * V_212 ;
V_212 = F_134 ( & V_211 [ V_209 ] , V_2 ) ;
switch ( V_209 ) {
case 0 :
V_2 -> V_143 = V_212 ;
V_212 -> V_213 = F_77 ;
break;
case 1 :
V_2 -> V_144 = V_212 ;
V_212 -> V_213 = F_77 ;
break;
case 2 :
V_2 -> V_145 = V_212 ;
V_212 -> V_213 = F_77 ;
break;
case 3 :
V_2 -> V_146 = V_212 ;
V_212 -> V_213 = F_77 ;
break;
}
if ( ( V_102 = F_135 ( V_116 , V_212 ) ) < 0 )
return V_102 ;
}
return 0 ;
}
static int T_4 F_136 ( struct V_166 * V_125 ,
const struct V_214 * V_215 )
{
static int V_182 ;
struct V_168 * V_116 ;
struct V_1 * V_2 ;
struct V_216 * V_217 ;
int V_209 , V_102 ;
if ( V_182 >= V_218 )
return - V_25 ;
if ( ! V_219 [ V_182 ] ) {
V_182 ++ ;
return - V_220 ;
}
V_102 = F_137 ( V_221 [ V_182 ] , V_208 [ V_182 ] , V_222 , 0 , & V_116 ) ;
if ( V_102 < 0 )
return V_102 ;
for ( V_209 = 0 ; V_209 < 5 ; V_209 ++ ) {
if ( F_124 ( V_125 , V_209 ) == 0 ||
! ( F_138 ( V_125 , V_209 ) & V_223 ) ) {
F_139 ( V_116 ) ;
return - V_25 ;
}
}
if ( ( V_102 = F_117 ( V_116 , V_125 , & V_2 ) ) < 0 ) {
F_139 ( V_116 ) ;
return V_102 ;
}
V_116 -> V_121 = V_2 ;
strcpy ( V_116 -> V_224 , L_22 ) ;
strcpy ( V_116 -> V_225 , L_29 ) ;
sprintf ( V_116 -> V_226 , L_30 ,
V_116 -> V_225 ,
V_2 -> V_227 ,
V_2 -> V_173 ) ;
if ( ( V_102 = F_63 ( V_2 , 0 ) ) < 0 ) {
F_139 ( V_116 ) ;
return V_102 ;
}
if ( ( V_102 = F_132 ( V_2 ) ) < 0 ) {
F_139 ( V_116 ) ;
return V_102 ;
}
if ( F_140 ( V_116 ,
F_4 ( V_2 , V_228 ) ,
F_4 ( V_2 , V_229 ) ,
V_230 , 1 , & V_217 ) < 0 ) {
F_12 ( V_21 L_31 ,
F_4 ( V_2 , V_228 ) ) ;
} else {
if ( ( V_102 = F_141 ( V_217 , 0 , 1 ) ) < 0 ) {
F_139 ( V_116 ) ;
return V_102 ;
}
if ( ( V_102 = F_142 ( V_217 , 0 , 1 , NULL ) ) < 0 ) {
F_139 ( V_116 ) ;
return V_102 ;
}
}
if ( F_143 ( V_116 , 0 , V_231 ,
V_2 -> V_199 , V_232 ,
V_2 -> V_173 , 0 , & V_2 -> V_186 ) < 0 ) {
F_12 ( V_21 L_32 ) ;
} else {
F_10 ( V_2 , V_187 , 0x40 , 0x40 ) ;
}
F_104 ( V_2 ) ;
if ( ( V_102 = F_144 ( V_116 ) ) < 0 ) {
F_139 ( V_116 ) ;
return V_102 ;
}
F_145 ( V_125 , V_116 ) ;
V_182 ++ ;
return 0 ;
}
static void T_7 F_146 ( struct V_166 * V_125 )
{
F_139 ( F_91 ( V_125 ) ) ;
F_145 ( V_125 , NULL ) ;
}
static int T_8 F_147 ( void )
{
return F_148 ( & V_224 ) ;
}
static void T_9 F_149 ( void )
{
F_150 ( & V_224 ) ;
}
