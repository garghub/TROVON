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
static char * V_129 [ 8 ] = {
L_12 , L_13 , L_14 , L_15 ,
L_16 , L_17 , L_18 , L_19
} ;
V_128 -> type = V_130 ;
V_128 -> V_79 = 1 ;
V_128 -> V_131 . V_132 . V_133 = 8 ;
if ( V_128 -> V_131 . V_132 . V_134 > 7 )
V_128 -> V_131 . V_132 . V_134 = 7 ;
strcpy ( V_128 -> V_131 . V_132 . V_122 , V_129 [ V_128 -> V_131 . V_132 . V_134 ] ) ;
return 0 ;
}
static int F_68 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
V_136 -> V_131 . V_132 . V_134 [ 0 ] = F_7 ( V_2 , 0x1c ) & 0x07 ;
return 0 ;
}
static int F_70 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
unsigned char V_4 = V_136 -> V_131 . V_132 . V_134 [ 0 ] ;
if ( V_4 > 7 )
return - V_70 ;
return F_9 ( V_2 , 0x1c , 0x07 , V_4 ) != V_4 ;
}
static int F_71 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
unsigned char V_4 = F_7 ( V_2 , 0x50 ) ;
V_136 -> V_131 . integer . V_131 [ 0 ] = ! ! ( V_4 & 8 ) ;
return 0 ;
}
static int F_72 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
unsigned char V_15 , V_137 ;
int V_138 ;
V_137 = V_136 -> V_131 . integer . V_131 [ 0 ] ? 0x0c : 0x04 ;
V_15 = F_7 ( V_2 , 0x50 ) & 0x0c ;
V_138 = V_137 != V_15 ;
if ( V_138 ) {
F_1 ( V_2 , 0x50 , V_137 & ~ 0x04 ) ;
F_1 ( V_2 , 0x50 , V_137 ) ;
}
return V_138 ;
}
static int F_73 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
V_128 -> type = V_139 ;
V_128 -> V_79 = 2 ;
V_128 -> V_131 . integer . V_140 = 0 ;
V_128 -> V_131 . integer . V_141 = 63 ;
return 0 ;
}
static int F_74 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
V_136 -> V_131 . integer . V_131 [ 0 ] = F_7 ( V_2 , 0x61 ) & 0x3f ;
V_136 -> V_131 . integer . V_131 [ 1 ] = F_7 ( V_2 , 0x63 ) & 0x3f ;
return 0 ;
}
static int F_75 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
V_136 -> V_131 . integer . V_131 [ 0 ] = ! ( F_7 ( V_2 , 0x61 ) & 0x40 ) ;
V_136 -> V_131 . integer . V_131 [ 1 ] = ! ( F_7 ( V_2 , 0x63 ) & 0x40 ) ;
return 0 ;
}
static void F_76 ( struct V_125 * V_126 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
V_2 -> V_142 = NULL ;
V_2 -> V_143 = NULL ;
V_2 -> V_144 = NULL ;
V_2 -> V_145 = NULL ;
}
static int F_77 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char V_12 , unsigned char V_4 )
{
if ( V_3 < 0xa0 )
return F_9 ( V_2 , V_3 , V_12 , V_4 ) ;
else
return F_15 ( V_2 , V_3 , V_12 , V_4 ) ;
}
static int F_78 ( struct V_1 * V_2 , unsigned char V_3 )
{
if ( V_3 < 0xa0 )
return F_7 ( V_2 , V_3 ) ;
else
return F_14 ( V_2 , V_3 ) ;
}
static int F_79 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
int V_12 = ( V_126 -> V_146 >> 16 ) & 0xff ;
V_128 -> type = V_12 == 1 ? V_147 : V_139 ;
V_128 -> V_79 = 1 ;
V_128 -> V_131 . integer . V_140 = 0 ;
V_128 -> V_131 . integer . V_141 = V_12 ;
return 0 ;
}
static int F_80 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
int V_3 = V_126 -> V_146 & 0xff ;
int V_148 = ( V_126 -> V_146 >> 8 ) & 0xff ;
int V_12 = ( V_126 -> V_146 >> 16 ) & 0xff ;
int V_149 = ( V_126 -> V_146 >> 24 ) & 0xff ;
int V_4 ;
V_4 = F_78 ( V_2 , V_3 ) ;
V_136 -> V_131 . integer . V_131 [ 0 ] = ( V_4 >> V_148 ) & V_12 ;
if ( V_149 )
V_136 -> V_131 . integer . V_131 [ 0 ] = V_12 - V_136 -> V_131 . integer . V_131 [ 0 ] ;
return 0 ;
}
static int F_81 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
int V_3 = V_126 -> V_146 & 0xff ;
int V_148 = ( V_126 -> V_146 >> 8 ) & 0xff ;
int V_12 = ( V_126 -> V_146 >> 16 ) & 0xff ;
int V_149 = ( V_126 -> V_146 >> 24 ) & 0xff ;
unsigned char V_4 ;
V_4 = ( V_136 -> V_131 . integer . V_131 [ 0 ] & V_12 ) ;
if ( V_149 )
V_4 = V_12 - V_4 ;
V_12 <<= V_148 ;
V_4 <<= V_148 ;
return F_77 ( V_2 , V_3 , V_12 , V_4 ) != V_4 ;
}
static int F_82 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
int V_12 = ( V_126 -> V_146 >> 24 ) & 0xff ;
V_128 -> type = V_12 == 1 ? V_147 : V_139 ;
V_128 -> V_79 = 2 ;
V_128 -> V_131 . integer . V_140 = 0 ;
V_128 -> V_131 . integer . V_141 = V_12 ;
return 0 ;
}
static int F_83 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
int V_150 = V_126 -> V_146 & 0xff ;
int V_151 = ( V_126 -> V_146 >> 8 ) & 0xff ;
int V_152 = ( V_126 -> V_146 >> 16 ) & 0x07 ;
int V_153 = ( V_126 -> V_146 >> 19 ) & 0x07 ;
int V_12 = ( V_126 -> V_146 >> 24 ) & 0xff ;
int V_149 = ( V_126 -> V_146 >> 22 ) & 1 ;
unsigned char V_154 , V_155 ;
V_154 = F_78 ( V_2 , V_150 ) ;
if ( V_150 != V_151 )
V_155 = F_78 ( V_2 , V_151 ) ;
else
V_155 = V_154 ;
V_136 -> V_131 . integer . V_131 [ 0 ] = ( V_154 >> V_152 ) & V_12 ;
V_136 -> V_131 . integer . V_131 [ 1 ] = ( V_155 >> V_153 ) & V_12 ;
if ( V_149 ) {
V_136 -> V_131 . integer . V_131 [ 0 ] = V_12 - V_136 -> V_131 . integer . V_131 [ 0 ] ;
V_136 -> V_131 . integer . V_131 [ 1 ] = V_12 - V_136 -> V_131 . integer . V_131 [ 1 ] ;
}
return 0 ;
}
static int F_84 ( struct V_125 * V_126 ,
struct V_135 * V_136 )
{
struct V_1 * V_2 = F_69 ( V_126 ) ;
int V_150 = V_126 -> V_146 & 0xff ;
int V_151 = ( V_126 -> V_146 >> 8 ) & 0xff ;
int V_152 = ( V_126 -> V_146 >> 16 ) & 0x07 ;
int V_153 = ( V_126 -> V_146 >> 19 ) & 0x07 ;
int V_12 = ( V_126 -> V_146 >> 24 ) & 0xff ;
int V_149 = ( V_126 -> V_146 >> 22 ) & 1 ;
int V_138 ;
unsigned char V_156 , V_157 , V_158 , V_159 ;
V_156 = V_136 -> V_131 . integer . V_131 [ 0 ] & V_12 ;
V_157 = V_136 -> V_131 . integer . V_131 [ 1 ] & V_12 ;
if ( V_149 ) {
V_156 = V_12 - V_156 ;
V_157 = V_12 - V_157 ;
}
V_156 <<= V_152 ;
V_157 <<= V_153 ;
V_158 = V_12 << V_152 ;
V_159 = V_12 << V_153 ;
if ( V_150 != V_151 ) {
V_138 = 0 ;
if ( F_77 ( V_2 , V_150 , V_158 , V_156 ) != V_156 )
V_138 = 1 ;
if ( F_77 ( V_2 , V_151 , V_159 , V_157 ) != V_157 )
V_138 = 1 ;
} else {
V_138 = ( F_77 ( V_2 , V_150 , V_158 | V_159 ,
V_156 | V_157 ) != ( V_156 | V_157 ) ) ;
}
return V_138 ;
}
static void F_85 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_86 ( V_2 -> V_124 ) ;
F_87 ( V_2 -> V_124 , V_160 , 0x805f ) ;
F_87 ( V_2 -> V_124 , V_161 , V_2 -> V_162 | 1 ) ;
F_88 ( V_2 -> V_124 , V_163 , 0 ) ;
F_3 ( 0xf0 , F_20 ( V_2 , V_164 ) ) ;
F_3 ( 0 , F_24 ( V_2 , V_56 ) ) ;
}
static int F_89 ( struct V_113 * V_10 )
{
struct V_165 * V_124 = F_90 ( V_10 ) ;
struct V_166 * V_9 = F_91 ( V_10 ) ;
struct V_1 * V_2 = V_9 -> V_120 ;
unsigned char * V_167 , * V_168 ;
F_92 ( V_9 , V_169 ) ;
F_93 ( V_2 -> V_115 ) ;
for ( V_167 = V_170 , V_168 = V_2 -> V_170 ; * V_167 ; V_167 ++ , V_168 ++ )
* V_168 = F_78 ( V_2 , * V_167 ) ;
F_3 ( 0x00 , F_20 ( V_2 , V_164 ) ) ;
if ( V_2 -> V_171 >= 0 ) {
F_94 ( V_2 -> V_171 , V_2 ) ;
V_2 -> V_171 = - 1 ;
}
F_95 ( V_124 ) ;
F_96 ( V_124 ) ;
F_97 ( V_124 , V_172 ) ;
return 0 ;
}
static int F_98 ( struct V_113 * V_10 )
{
struct V_165 * V_124 = F_90 ( V_10 ) ;
struct V_166 * V_9 = F_91 ( V_10 ) ;
struct V_1 * V_2 = V_9 -> V_120 ;
unsigned char * V_167 , * V_168 ;
F_97 ( V_124 , V_173 ) ;
F_99 ( V_124 ) ;
if ( F_100 ( V_124 ) < 0 ) {
F_11 ( V_10 , L_20 ) ;
F_101 ( V_9 ) ;
return - V_174 ;
}
if ( F_102 ( V_124 -> V_171 , V_175 ,
V_176 , V_177 , V_2 ) ) {
F_11 ( V_10 , L_21 ,
V_124 -> V_171 ) ;
F_101 ( V_9 ) ;
return - V_174 ;
}
V_2 -> V_171 = V_124 -> V_171 ;
F_85 ( V_2 ) ;
for ( V_167 = V_170 , V_168 = V_2 -> V_170 ; * V_167 ; V_167 ++ , V_168 ++ ) {
if ( * V_167 < 0xa0 )
F_1 ( V_2 , * V_167 , * V_168 ) ;
else
F_13 ( V_2 , * V_167 , * V_168 ) ;
}
F_92 ( V_9 , V_178 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
struct V_179 * V_180 ;
V_2 -> V_179 = V_180 = F_104 () ;
if ( ! V_180 ) {
F_11 ( V_2 -> V_9 -> V_10 ,
L_22 ) ;
return - V_181 ;
}
F_105 ( V_180 , L_23 ) ;
F_106 ( V_180 , L_24 , F_107 ( V_2 -> V_124 ) ) ;
F_108 ( V_180 , & V_2 -> V_124 -> V_10 ) ;
V_180 -> V_182 = V_2 -> V_183 ;
F_109 ( V_180 ) ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 )
{
if ( V_2 -> V_179 ) {
F_111 ( V_2 -> V_179 ) ;
V_2 -> V_179 = NULL ;
}
}
static inline int F_103 ( struct V_1 * V_2 ) { return - V_184 ; }
static inline void F_110 ( struct V_1 * V_2 ) { }
static int F_112 ( struct V_1 * V_2 )
{
F_3 ( 0x00 , F_20 ( V_2 , V_164 ) ) ;
if ( V_2 -> V_185 )
F_9 ( V_2 , V_186 , 0x40 , 0 ) ;
F_110 ( V_2 ) ;
if ( V_2 -> V_171 >= 0 )
F_94 ( V_2 -> V_171 , V_2 ) ;
F_113 ( V_2 -> V_124 ) ;
F_95 ( V_2 -> V_124 ) ;
F_114 ( V_2 ) ;
return 0 ;
}
static int F_115 ( struct V_187 * V_113 )
{
struct V_1 * V_2 = V_113 -> V_188 ;
return F_112 ( V_2 ) ;
}
static int F_116 ( struct V_166 * V_9 ,
struct V_165 * V_124 ,
struct V_1 * * V_189 )
{
struct V_1 * V_2 ;
int V_102 ;
static struct V_190 V_191 = {
. V_192 = F_115 ,
} ;
* V_189 = NULL ;
if ( ( V_102 = F_100 ( V_124 ) ) < 0 )
return V_102 ;
if ( F_117 ( V_124 , F_118 ( 24 ) ) < 0 ||
F_119 ( V_124 , F_118 ( 24 ) ) < 0 ) {
F_11 ( V_9 -> V_10 ,
L_25 ) ;
F_95 ( V_124 ) ;
return - V_193 ;
}
V_2 = F_120 ( sizeof( * V_2 ) , V_194 ) ;
if ( V_2 == NULL ) {
F_95 ( V_124 ) ;
return - V_181 ;
}
F_121 ( & V_2 -> V_26 ) ;
F_121 ( & V_2 -> V_6 ) ;
V_2 -> V_9 = V_9 ;
V_2 -> V_124 = V_124 ;
V_2 -> V_171 = - 1 ;
if ( ( V_102 = F_122 ( V_124 , L_11 ) ) < 0 ) {
F_114 ( V_2 ) ;
F_95 ( V_124 ) ;
return V_102 ;
}
V_2 -> V_195 = F_123 ( V_124 , 0 ) ;
V_2 -> V_196 = F_123 ( V_124 , 1 ) ;
V_2 -> V_197 = F_123 ( V_124 , 2 ) ;
V_2 -> V_198 = F_123 ( V_124 , 3 ) ;
V_2 -> V_183 = F_123 ( V_124 , 4 ) ;
if ( F_102 ( V_124 -> V_171 , V_175 , V_176 ,
V_177 , V_2 ) ) {
F_11 ( V_9 -> V_10 , L_26 , V_124 -> V_171 ) ;
F_112 ( V_2 ) ;
return - V_199 ;
}
V_2 -> V_171 = V_124 -> V_171 ;
F_6 ( V_9 -> V_10 ,
L_27 ,
V_2 -> V_195 , V_2 -> V_196 , V_2 -> V_197 , V_2 -> V_198 , V_2 -> V_183 ) ;
V_2 -> V_162 = V_2 -> V_197 + 0x00 ;
F_85 ( V_2 ) ;
if ( ( V_102 = F_124 ( V_9 , V_200 , V_2 , & V_191 ) ) < 0 ) {
F_112 ( V_2 ) ;
return V_102 ;
}
* V_189 = V_2 ;
return 0 ;
}
static T_4 V_175 ( int V_171 , void * V_201 )
{
struct V_1 * V_2 = V_201 ;
unsigned char V_202 , V_203 ;
int V_204 = 0 ;
V_202 = F_8 ( F_20 ( V_2 , V_164 ) ) ;
#if 0
dev_dbg(chip->card->dev,
"Es1938debug - interrupt status: =0x%x\n", status);
#endif
if ( V_202 & 0x10 ) {
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
V_204 = 1 ;
V_203 = F_8 ( F_4 ( V_2 , V_23 ) ) ;
if ( V_2 -> V_66 & V_67 )
F_125 ( V_2 -> V_105 ) ;
else if ( V_2 -> V_66 & V_73 )
F_125 ( V_2 -> V_103 ) ;
}
if ( V_202 & 0x20 ) {
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
V_204 = 1 ;
F_9 ( V_2 , V_91 , 0x80 , 0 ) ;
if ( V_2 -> V_66 & V_49 )
F_125 ( V_2 -> V_111 ) ;
}
if ( V_202 & 0x40 ) {
int V_205 = F_7 ( V_2 , 0x64 ) & 0x80 ;
V_204 = 1 ;
F_126 ( V_2 -> V_9 , V_206 , & V_2 -> V_145 -> V_207 ) ;
F_126 ( V_2 -> V_9 , V_206 , & V_2 -> V_144 -> V_207 ) ;
if ( ! V_205 ) {
F_126 ( V_2 -> V_9 , V_206 ,
& V_2 -> V_143 -> V_207 ) ;
F_126 ( V_2 -> V_9 , V_206 ,
& V_2 -> V_142 -> V_207 ) ;
}
F_1 ( V_2 , 0x66 , 0x00 ) ;
}
if ( V_202 & 0x80 ) {
if ( V_2 -> V_185 ) {
V_204 = 1 ;
F_127 ( V_171 , V_2 -> V_185 -> V_120 ) ;
}
}
return F_128 ( V_204 ) ;
}
static int F_129 ( struct V_1 * V_2 )
{
struct V_166 * V_9 ;
unsigned int V_208 ;
int V_102 ;
V_9 = V_2 -> V_9 ;
strcpy ( V_9 -> V_209 , L_11 ) ;
for ( V_208 = 0 ; V_208 < F_130 ( V_210 ) ; V_208 ++ ) {
struct V_125 * V_211 ;
V_211 = F_131 ( & V_210 [ V_208 ] , V_2 ) ;
switch ( V_208 ) {
case 0 :
V_2 -> V_142 = V_211 ;
V_211 -> V_212 = F_76 ;
break;
case 1 :
V_2 -> V_143 = V_211 ;
V_211 -> V_212 = F_76 ;
break;
case 2 :
V_2 -> V_144 = V_211 ;
V_211 -> V_212 = F_76 ;
break;
case 3 :
V_2 -> V_145 = V_211 ;
V_211 -> V_212 = F_76 ;
break;
}
if ( ( V_102 = F_132 ( V_9 , V_211 ) ) < 0 )
return V_102 ;
}
return 0 ;
}
static int F_133 ( struct V_165 * V_124 ,
const struct V_213 * V_214 )
{
static int V_10 ;
struct V_166 * V_9 ;
struct V_1 * V_2 ;
struct V_215 * V_216 ;
int V_208 , V_102 ;
if ( V_10 >= V_217 )
return - V_25 ;
if ( ! V_218 [ V_10 ] ) {
V_10 ++ ;
return - V_219 ;
}
V_102 = F_134 ( & V_124 -> V_10 , V_220 [ V_10 ] , V_207 [ V_10 ] , V_221 ,
0 , & V_9 ) ;
if ( V_102 < 0 )
return V_102 ;
for ( V_208 = 0 ; V_208 < 5 ; V_208 ++ ) {
if ( F_123 ( V_124 , V_208 ) == 0 ||
! ( F_135 ( V_124 , V_208 ) & V_222 ) ) {
F_136 ( V_9 ) ;
return - V_25 ;
}
}
if ( ( V_102 = F_116 ( V_9 , V_124 , & V_2 ) ) < 0 ) {
F_136 ( V_9 ) ;
return V_102 ;
}
V_9 -> V_120 = V_2 ;
strcpy ( V_9 -> V_223 , L_23 ) ;
strcpy ( V_9 -> V_224 , L_28 ) ;
sprintf ( V_9 -> V_225 , L_29 ,
V_9 -> V_224 ,
V_2 -> V_226 ,
V_2 -> V_171 ) ;
if ( ( V_102 = F_62 ( V_2 , 0 ) ) < 0 ) {
F_136 ( V_9 ) ;
return V_102 ;
}
if ( ( V_102 = F_129 ( V_2 ) ) < 0 ) {
F_136 ( V_9 ) ;
return V_102 ;
}
if ( F_137 ( V_9 ,
F_4 ( V_2 , V_227 ) ,
F_4 ( V_2 , V_228 ) ,
V_229 , 1 , & V_216 ) < 0 ) {
F_11 ( V_9 -> V_10 , L_30 ,
F_4 ( V_2 , V_227 ) ) ;
} else {
if ( ( V_102 = F_138 ( V_216 , 0 , 1 ) ) < 0 ) {
F_136 ( V_9 ) ;
return V_102 ;
}
if ( ( V_102 = F_139 ( V_216 , 0 , 1 , NULL ) ) < 0 ) {
F_136 ( V_9 ) ;
return V_102 ;
}
}
if ( F_140 ( V_9 , 0 , V_230 ,
V_2 -> V_198 ,
V_231 | V_232 ,
- 1 , & V_2 -> V_185 ) < 0 ) {
F_11 ( V_9 -> V_10 , L_31 ) ;
} else {
F_9 ( V_2 , V_186 , 0x40 , 0x40 ) ;
}
F_103 ( V_2 ) ;
if ( ( V_102 = F_141 ( V_9 ) ) < 0 ) {
F_136 ( V_9 ) ;
return V_102 ;
}
F_142 ( V_124 , V_9 ) ;
V_10 ++ ;
return 0 ;
}
static void F_143 ( struct V_165 * V_124 )
{
F_136 ( F_144 ( V_124 ) ) ;
}
