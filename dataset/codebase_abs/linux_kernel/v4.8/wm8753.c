static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 == V_4 ;
}
static int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
V_8 -> V_13 . V_14 . V_15 [ 0 ] = V_12 -> V_16 ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
T_1 V_17 ;
if ( V_12 -> V_16 == V_8 -> V_13 . V_14 . V_15 [ 0 ] )
return 0 ;
if ( F_6 ( V_10 ) )
return - V_18 ;
V_17 = F_7 ( V_10 , V_19 ) ;
V_12 -> V_16 = V_8 -> V_13 . V_14 . V_15 [ 0 ] ;
if ( ( ( V_17 >> 2 ) & 0x3 ) == V_12 -> V_16 )
return 1 ;
V_17 = ( V_17 & 0x1f3 ) | ( V_12 -> V_16 << 2 ) ;
F_8 ( V_10 , V_19 , V_17 ) ;
F_9 ( V_10 , V_12 -> V_20 ) ;
F_10 ( V_10 , V_12 -> V_21 ) ;
return 1 ;
}
static void F_11 ( struct V_22 * V_23 , unsigned int V_24 ,
unsigned int V_25 )
{
T_2 V_26 ;
unsigned int V_27 , V_28 , V_29 ;
V_28 = V_24 / V_25 ;
if ( V_28 < 6 ) {
V_25 >>= 1 ;
V_23 -> V_30 = 1 ;
V_28 = V_24 / V_25 ;
} else
V_23 -> V_30 = 0 ;
if ( ( V_28 < 6 ) || ( V_28 > 12 ) )
F_12 ( V_31
L_1 , V_28 ) ;
V_23 -> V_32 = V_28 ;
V_29 = V_24 % V_25 ;
V_26 = V_33 * ( long long ) V_29 ;
F_13 ( V_26 , V_25 ) ;
V_27 = V_26 & 0xFFFFFFFF ;
if ( ( V_27 % 10 ) >= 5 )
V_27 += 5 ;
V_27 /= 10 ;
V_23 -> V_34 = V_27 ;
}
static int F_14 ( struct V_35 * V_36 , int V_37 ,
int V_25 , unsigned int V_38 , unsigned int V_39 )
{
T_1 V_3 , V_40 ;
int V_41 ;
struct V_9 * V_10 = V_36 -> V_10 ;
if ( V_37 < V_42 || V_37 > V_43 )
return - V_44 ;
if ( V_37 == V_42 ) {
V_41 = 0 ;
V_40 = 0x10 ;
V_3 = F_7 ( V_10 , V_45 ) & 0xffef ;
} else {
V_41 = 4 ;
V_40 = 0x8 ;
V_3 = F_7 ( V_10 , V_45 ) & 0xfff7 ;
}
if ( ! V_38 || ! V_39 ) {
F_8 ( V_10 , V_46 + V_41 , 0x0026 ) ;
F_8 ( V_10 , V_45 , V_3 ) ;
return 0 ;
} else {
T_1 V_13 = 0 ;
struct V_22 V_23 ;
F_11 ( & V_23 , V_39 * 8 , V_38 ) ;
V_13 = ( V_23 . V_32 << 5 ) + ( ( V_23 . V_34 & 0x3c0000 ) >> 18 ) ;
F_8 ( V_10 , V_47 + V_41 , V_13 ) ;
V_13 = ( V_23 . V_34 & 0x03fe00 ) >> 9 ;
F_8 ( V_10 , V_48 + V_41 , V_13 ) ;
V_13 = V_23 . V_34 & 0x0001ff ;
F_8 ( V_10 , V_49 + V_41 , V_13 ) ;
F_8 ( V_10 , V_46 + V_41 , 0x0027 |
( V_23 . V_30 << 3 ) ) ;
F_8 ( V_10 , V_45 , V_3 | V_40 ) ;
}
return 0 ;
}
static int F_15 ( int V_50 , int V_51 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < F_16 ( V_53 ) ; V_52 ++ ) {
if ( V_53 [ V_52 ] . V_51 == V_51 && V_53 [ V_52 ] . V_50 == V_50 )
return V_52 ;
}
return - V_54 ;
}
static int F_17 ( struct V_35 * V_36 ,
int V_55 , unsigned int V_56 , int V_57 )
{
struct V_9 * V_10 = V_36 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
switch ( V_56 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
if ( V_55 == V_58 ) {
V_12 -> V_59 = V_56 ;
return 0 ;
} else if ( V_55 == V_60 ) {
V_12 -> V_61 = V_56 ;
return 0 ;
}
break;
}
return - V_54 ;
}
static int F_18 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
T_1 V_63 = F_7 ( V_10 , V_64 ) & 0x01ec ;
switch ( V_62 & V_65 ) {
case V_66 :
V_63 |= 0x0002 ;
break;
case V_67 :
break;
case V_68 :
V_63 |= 0x0001 ;
break;
case V_69 :
V_63 |= 0x0003 ;
break;
case V_70 :
V_63 |= 0x0013 ;
break;
default:
return - V_54 ;
}
F_8 ( V_10 , V_64 , V_63 ) ;
return 0 ;
}
static int F_19 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_35 * V_75 )
{
struct V_9 * V_10 = V_75 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
T_1 V_63 = F_7 ( V_10 , V_64 ) & 0x01f3 ;
T_1 V_76 = F_7 ( V_10 , V_77 ) & 0x017f ;
switch ( F_20 ( V_74 ) ) {
case 16 :
break;
case 20 :
V_63 |= 0x0004 ;
break;
case 24 :
V_63 |= 0x0008 ;
break;
case 32 :
V_63 |= 0x000c ;
break;
}
if ( F_21 ( V_74 ) * 384 == V_12 -> V_61 )
V_76 |= 0x80 ;
F_8 ( V_10 , V_77 , V_76 ) ;
F_8 ( V_10 , V_64 , V_63 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
T_1 V_63 , V_17 ;
V_63 = F_7 ( V_10 , V_64 ) & 0x011f ;
V_17 = F_7 ( V_10 , V_19 ) & 0x015d ;
switch ( V_62 & V_78 ) {
case V_79 :
break;
case V_80 :
V_17 |= 0x2 ;
case V_81 :
V_63 |= 0x0040 ;
break;
default:
return - V_54 ;
}
switch ( V_62 & V_65 ) {
case V_69 :
case V_70 :
switch ( V_62 & V_82 ) {
case V_83 :
break;
case V_84 :
V_63 |= 0x0080 ;
break;
default:
return - V_54 ;
}
break;
case V_66 :
case V_67 :
case V_68 :
V_63 &= ~ 0x0010 ;
switch ( V_62 & V_82 ) {
case V_83 :
break;
case V_85 :
V_63 |= 0x0090 ;
break;
case V_84 :
V_63 |= 0x0080 ;
break;
case V_86 :
V_63 |= 0x0010 ;
break;
default:
return - V_54 ;
}
break;
default:
return - V_54 ;
}
F_8 ( V_10 , V_64 , V_63 ) ;
F_8 ( V_10 , V_19 , V_17 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
int V_87 , int div )
{
struct V_9 * V_10 = V_36 -> V_10 ;
T_1 V_3 ;
switch ( V_87 ) {
case V_88 :
V_3 = F_7 ( V_10 , V_45 ) & 0x003f ;
F_8 ( V_10 , V_45 , V_3 | div ) ;
break;
case V_89 :
V_3 = F_7 ( V_10 , V_90 ) & 0x01c7 ;
F_8 ( V_10 , V_90 , V_3 | div ) ;
break;
case V_91 :
V_3 = F_7 ( V_10 , V_90 ) & 0x003f ;
F_8 ( V_10 , V_90 , V_3 | div ) ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_24 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
T_1 V_92 = F_7 ( V_10 , V_93 ) & 0x01e0 ;
switch ( V_62 & V_65 ) {
case V_66 :
V_92 |= 0x0002 ;
break;
case V_67 :
break;
case V_68 :
V_92 |= 0x0001 ;
break;
case V_69 :
V_92 |= 0x0003 ;
break;
case V_70 :
V_92 |= 0x0013 ;
break;
default:
return - V_54 ;
}
F_8 ( V_10 , V_93 , V_92 ) ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
T_1 V_17 , V_92 ;
V_92 = F_7 ( V_10 , V_93 ) & 0x011f ;
V_17 = F_7 ( V_10 , V_19 ) & 0x00ae ;
switch ( V_62 & V_78 ) {
case V_79 :
break;
case V_80 :
V_17 |= 0x1 ;
case V_81 :
V_92 |= 0x0040 ;
break;
default:
return - V_54 ;
}
switch ( V_62 & V_65 ) {
case V_69 :
case V_70 :
switch ( V_62 & V_82 ) {
case V_83 :
break;
case V_84 :
V_92 |= 0x0080 ;
break;
default:
return - V_54 ;
}
break;
case V_66 :
case V_67 :
case V_68 :
V_92 &= ~ 0x0010 ;
switch ( V_62 & V_82 ) {
case V_83 :
break;
case V_85 :
V_92 |= 0x0090 ;
break;
case V_84 :
V_92 |= 0x0080 ;
break;
case V_86 :
V_92 |= 0x0010 ;
break;
default:
return - V_54 ;
}
break;
default:
return - V_54 ;
}
F_8 ( V_10 , V_93 , V_92 ) ;
F_8 ( V_10 , V_19 , V_17 ) ;
return 0 ;
}
static int F_26 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_35 * V_75 )
{
struct V_9 * V_10 = V_75 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
T_1 V_76 = F_7 ( V_10 , V_77 ) & 0x01c0 ;
T_1 V_92 = F_7 ( V_10 , V_93 ) & 0x01f3 ;
int V_94 ;
V_94 = F_15 ( V_12 -> V_59 , F_21 ( V_74 ) ) ;
if ( V_94 < 0 ) {
F_12 ( V_95 L_2 ) ;
return V_94 ;
}
F_8 ( V_10 , V_77 , V_76 | ( V_53 [ V_94 ] . V_96 << 1 ) |
V_53 [ V_94 ] . V_97 ) ;
switch ( F_20 ( V_74 ) ) {
case 16 :
break;
case 20 :
V_92 |= 0x0004 ;
break;
case 24 :
V_92 |= 0x0008 ;
break;
case 32 :
V_92 |= 0x000c ;
break;
}
F_8 ( V_10 , V_93 , V_92 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
T_1 clock ;
clock = F_7 ( V_10 , V_45 ) & 0xfffb ;
F_8 ( V_10 , V_45 , clock ) ;
return F_18 ( V_10 , V_62 ) ;
}
static int F_28 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
return F_24 ( V_10 , V_62 ) ;
}
static int F_29 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
T_1 clock ;
clock = F_7 ( V_10 , V_45 ) & 0xfffb ;
F_8 ( V_10 , V_45 , clock ) ;
return F_18 ( V_10 , V_62 ) ;
}
static int F_30 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
T_1 clock ;
clock = F_7 ( V_10 , V_45 ) & 0xfffb ;
F_8 ( V_10 , V_45 , clock | 0x4 ) ;
if ( F_24 ( V_10 , V_62 ) < 0 )
return - V_54 ;
return F_18 ( V_10 , V_62 ) ;
}
static int F_9 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_98 = 0 ;
switch ( V_12 -> V_16 ) {
case 0 :
V_98 = F_28 ( V_10 , V_62 ) ;
break;
case 1 :
V_98 = F_29 ( V_10 , V_62 ) ;
break;
case 2 :
case 3 :
V_98 = F_30 ( V_10 , V_62 ) ;
break;
default:
break;
}
if ( V_98 )
return V_98 ;
return F_25 ( V_10 , V_62 ) ;
}
static int F_31 ( struct V_35 * V_36 ,
unsigned int V_62 )
{
struct V_9 * V_10 = V_36 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
V_12 -> V_20 = V_62 ;
return F_9 ( V_10 , V_62 ) ;
}
static int F_10 ( struct V_9 * V_10 ,
unsigned int V_62 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_98 = 0 ;
if ( V_12 -> V_16 != 0 )
return 0 ;
V_98 = F_27 ( V_10 , V_62 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_22 ( V_10 , V_62 ) ;
if ( V_98 )
return V_98 ;
return 0 ;
}
static int F_32 ( struct V_35 * V_36 ,
unsigned int V_62 )
{
struct V_9 * V_10 = V_36 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
V_12 -> V_21 = V_62 ;
return F_10 ( V_10 , V_62 ) ;
}
static int F_33 ( struct V_35 * V_75 , int V_99 )
{
struct V_9 * V_10 = V_75 -> V_10 ;
T_1 V_100 = F_7 ( V_10 , V_101 ) & 0xfff7 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
if ( V_99 && V_12 -> V_16 == 1 ) {
if ( ! F_6 ( V_10 ) )
F_8 ( V_10 , V_101 , V_100 | 0x8 ) ;
} else {
if ( V_99 )
F_8 ( V_10 , V_101 , V_100 | 0x8 ) ;
else
F_8 ( V_10 , V_101 , V_100 ) ;
}
return 0 ;
}
static void F_34 ( struct V_102 * V_103 )
{
struct V_11 * V_12 =
F_35 ( V_103 , struct V_11 , V_104 . V_103 ) ;
F_36 ( V_12 -> V_105 , V_106 , 0x0180 , 0x0100 ) ;
}
static int F_37 ( struct V_9 * V_10 ,
enum V_107 V_108 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
T_1 V_109 = F_7 ( V_10 , V_106 ) & 0xfe3e ;
switch ( V_108 ) {
case V_110 :
F_8 ( V_10 , V_106 , V_109 | 0x00c0 ) ;
break;
case V_111 :
F_38 ( & V_12 -> V_104 ) ;
break;
case V_112 :
if ( F_39 ( V_10 ) == V_113 ) {
F_8 ( V_10 , V_106 , V_109 | 0x01c1 ) ;
F_40 ( & V_12 -> V_104 ,
F_41 ( V_114 ) ) ;
} else {
F_8 ( V_10 , V_106 , V_109 | 0x0141 ) ;
}
break;
case V_113 :
F_42 ( & V_12 -> V_104 ) ;
F_8 ( V_10 , V_106 , 0x0001 ) ;
break;
}
return 0 ;
}
static int F_43 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
F_44 ( V_12 -> V_105 ) ;
return 0 ;
}
static int F_45 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_98 ;
F_46 ( & V_12 -> V_104 , F_34 ) ;
V_98 = F_47 ( V_10 ) ;
if ( V_98 < 0 ) {
F_48 ( V_10 -> V_2 , L_3 , V_98 ) ;
return V_98 ;
}
V_12 -> V_16 = 0 ;
F_49 ( V_10 , V_115 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_116 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_117 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_118 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_119 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_120 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_121 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_122 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_123 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_124 , 0x0100 , 0x0100 ) ;
return 0 ;
}
static int F_50 ( struct V_125 * V_126 )
{
struct V_11 * V_12 ;
int V_98 ;
V_12 = F_51 ( & V_126 -> V_2 , sizeof( struct V_11 ) ,
V_127 ) ;
if ( V_12 == NULL )
return - V_128 ;
F_52 ( V_126 , V_12 ) ;
V_12 -> V_105 = F_53 ( V_126 , & V_129 ) ;
if ( F_54 ( V_12 -> V_105 ) ) {
V_98 = F_55 ( V_12 -> V_105 ) ;
F_48 ( & V_126 -> V_2 , L_4 ,
V_98 ) ;
return V_98 ;
}
V_98 = F_56 ( & V_126 -> V_2 , & V_130 ,
V_131 , F_16 ( V_131 ) ) ;
if ( V_98 != 0 )
F_48 ( & V_126 -> V_2 , L_5 , V_98 ) ;
return V_98 ;
}
static int F_57 ( struct V_125 * V_126 )
{
F_58 ( & V_126 -> V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_132 * V_133 ,
const struct V_134 * V_135 )
{
struct V_11 * V_12 ;
int V_98 ;
V_12 = F_51 ( & V_133 -> V_2 , sizeof( struct V_11 ) ,
V_127 ) ;
if ( V_12 == NULL )
return - V_128 ;
F_60 ( V_133 , V_12 ) ;
V_12 -> V_105 = F_61 ( V_133 , & V_129 ) ;
if ( F_54 ( V_12 -> V_105 ) ) {
V_98 = F_55 ( V_12 -> V_105 ) ;
F_48 ( & V_133 -> V_2 , L_4 ,
V_98 ) ;
return V_98 ;
}
V_98 = F_56 ( & V_133 -> V_2 , & V_130 ,
V_131 , F_16 ( V_131 ) ) ;
if ( V_98 != 0 )
F_48 ( & V_133 -> V_2 , L_5 , V_98 ) ;
return V_98 ;
}
static int F_62 ( struct V_132 * V_136 )
{
F_58 ( & V_136 -> V_2 ) ;
return 0 ;
}
static int T_3 F_63 ( void )
{
int V_98 = 0 ;
#if F_64 ( V_137 )
V_98 = F_65 ( & V_138 ) ;
if ( V_98 != 0 ) {
F_12 ( V_95 L_6 ,
V_98 ) ;
}
#endif
#if F_66 ( V_139 )
V_98 = F_67 ( & V_140 ) ;
if ( V_98 != 0 ) {
F_12 ( V_95 L_7 ,
V_98 ) ;
}
#endif
return V_98 ;
}
static void T_4 F_68 ( void )
{
#if F_64 ( V_137 )
F_69 ( & V_138 ) ;
#endif
#if F_66 ( V_139 )
F_70 ( & V_140 ) ;
#endif
}
