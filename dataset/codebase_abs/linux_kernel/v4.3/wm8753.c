static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 == V_4 ;
}
static int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
V_8 -> V_13 . integer . V_13 [ 0 ] = V_12 -> V_14 ;
return 0 ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
T_1 V_15 ;
if ( V_12 -> V_14 == V_8 -> V_13 . integer . V_13 [ 0 ] )
return 0 ;
if ( F_6 ( V_10 ) )
return - V_16 ;
V_15 = F_7 ( V_10 , V_17 ) ;
V_12 -> V_14 = V_8 -> V_13 . integer . V_13 [ 0 ] ;
if ( ( ( V_15 >> 2 ) & 0x3 ) == V_12 -> V_14 )
return 1 ;
V_15 = ( V_15 & 0x1f3 ) | ( V_12 -> V_14 << 2 ) ;
F_8 ( V_10 , V_17 , V_15 ) ;
F_9 ( V_10 , V_12 -> V_18 ) ;
F_10 ( V_10 , V_12 -> V_19 ) ;
return 1 ;
}
static void F_11 ( struct V_20 * V_21 , unsigned int V_22 ,
unsigned int V_23 )
{
T_2 V_24 ;
unsigned int V_25 , V_26 , V_27 ;
V_26 = V_22 / V_23 ;
if ( V_26 < 6 ) {
V_23 >>= 1 ;
V_21 -> V_28 = 1 ;
V_26 = V_22 / V_23 ;
} else
V_21 -> V_28 = 0 ;
if ( ( V_26 < 6 ) || ( V_26 > 12 ) )
F_12 ( V_29
L_1 , V_26 ) ;
V_21 -> V_30 = V_26 ;
V_27 = V_22 % V_23 ;
V_24 = V_31 * ( long long ) V_27 ;
F_13 ( V_24 , V_23 ) ;
V_25 = V_24 & 0xFFFFFFFF ;
if ( ( V_25 % 10 ) >= 5 )
V_25 += 5 ;
V_25 /= 10 ;
V_21 -> V_32 = V_25 ;
}
static int F_14 ( struct V_33 * V_34 , int V_35 ,
int V_23 , unsigned int V_36 , unsigned int V_37 )
{
T_1 V_3 , V_38 ;
int V_39 ;
struct V_9 * V_10 = V_34 -> V_10 ;
if ( V_35 < V_40 || V_35 > V_41 )
return - V_42 ;
if ( V_35 == V_40 ) {
V_39 = 0 ;
V_38 = 0x10 ;
V_3 = F_7 ( V_10 , V_43 ) & 0xffef ;
} else {
V_39 = 4 ;
V_38 = 0x8 ;
V_3 = F_7 ( V_10 , V_43 ) & 0xfff7 ;
}
if ( ! V_36 || ! V_37 ) {
F_8 ( V_10 , V_44 + V_39 , 0x0026 ) ;
F_8 ( V_10 , V_43 , V_3 ) ;
return 0 ;
} else {
T_1 V_13 = 0 ;
struct V_20 V_21 ;
F_11 ( & V_21 , V_37 * 8 , V_36 ) ;
V_13 = ( V_21 . V_30 << 5 ) + ( ( V_21 . V_32 & 0x3c0000 ) >> 18 ) ;
F_8 ( V_10 , V_45 + V_39 , V_13 ) ;
V_13 = ( V_21 . V_32 & 0x03fe00 ) >> 9 ;
F_8 ( V_10 , V_46 + V_39 , V_13 ) ;
V_13 = V_21 . V_32 & 0x0001ff ;
F_8 ( V_10 , V_47 + V_39 , V_13 ) ;
F_8 ( V_10 , V_44 + V_39 , 0x0027 |
( V_21 . V_28 << 3 ) ) ;
F_8 ( V_10 , V_43 , V_3 | V_38 ) ;
}
return 0 ;
}
static int F_15 ( int V_48 , int V_49 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < F_16 ( V_51 ) ; V_50 ++ ) {
if ( V_51 [ V_50 ] . V_49 == V_49 && V_51 [ V_50 ] . V_48 == V_48 )
return V_50 ;
}
return - V_52 ;
}
static int F_17 ( struct V_33 * V_34 ,
int V_53 , unsigned int V_54 , int V_55 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
switch ( V_54 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
if ( V_53 == V_56 ) {
V_12 -> V_57 = V_54 ;
return 0 ;
} else if ( V_53 == V_58 ) {
V_12 -> V_59 = V_54 ;
return 0 ;
}
break;
}
return - V_52 ;
}
static int F_18 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
T_1 V_61 = F_7 ( V_10 , V_62 ) & 0x01ec ;
switch ( V_60 & V_63 ) {
case V_64 :
V_61 |= 0x0002 ;
break;
case V_65 :
break;
case V_66 :
V_61 |= 0x0001 ;
break;
case V_67 :
V_61 |= 0x0003 ;
break;
case V_68 :
V_61 |= 0x0013 ;
break;
default:
return - V_52 ;
}
F_8 ( V_10 , V_62 , V_61 ) ;
return 0 ;
}
static int F_19 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
struct V_33 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
T_1 V_61 = F_7 ( V_10 , V_62 ) & 0x01f3 ;
T_1 V_74 = F_7 ( V_10 , V_75 ) & 0x017f ;
switch ( F_20 ( V_72 ) ) {
case 16 :
break;
case 20 :
V_61 |= 0x0004 ;
break;
case 24 :
V_61 |= 0x0008 ;
break;
case 32 :
V_61 |= 0x000c ;
break;
}
if ( F_21 ( V_72 ) * 384 == V_12 -> V_59 )
V_74 |= 0x80 ;
F_8 ( V_10 , V_75 , V_74 ) ;
F_8 ( V_10 , V_62 , V_61 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
T_1 V_61 , V_15 ;
V_61 = F_7 ( V_10 , V_62 ) & 0x011f ;
V_15 = F_7 ( V_10 , V_17 ) & 0x015d ;
switch ( V_60 & V_76 ) {
case V_77 :
break;
case V_78 :
V_15 |= 0x2 ;
case V_79 :
V_61 |= 0x0040 ;
break;
default:
return - V_52 ;
}
switch ( V_60 & V_63 ) {
case V_67 :
case V_68 :
switch ( V_60 & V_80 ) {
case V_81 :
break;
case V_82 :
V_61 |= 0x0080 ;
break;
default:
return - V_52 ;
}
break;
case V_64 :
case V_65 :
case V_66 :
V_61 &= ~ 0x0010 ;
switch ( V_60 & V_80 ) {
case V_81 :
break;
case V_83 :
V_61 |= 0x0090 ;
break;
case V_82 :
V_61 |= 0x0080 ;
break;
case V_84 :
V_61 |= 0x0010 ;
break;
default:
return - V_52 ;
}
break;
default:
return - V_52 ;
}
F_8 ( V_10 , V_62 , V_61 ) ;
F_8 ( V_10 , V_17 , V_15 ) ;
return 0 ;
}
static int F_23 ( struct V_33 * V_34 ,
int V_85 , int div )
{
struct V_9 * V_10 = V_34 -> V_10 ;
T_1 V_3 ;
switch ( V_85 ) {
case V_86 :
V_3 = F_7 ( V_10 , V_43 ) & 0x003f ;
F_8 ( V_10 , V_43 , V_3 | div ) ;
break;
case V_87 :
V_3 = F_7 ( V_10 , V_88 ) & 0x01c7 ;
F_8 ( V_10 , V_88 , V_3 | div ) ;
break;
case V_89 :
V_3 = F_7 ( V_10 , V_88 ) & 0x003f ;
F_8 ( V_10 , V_88 , V_3 | div ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_24 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
T_1 V_90 = F_7 ( V_10 , V_91 ) & 0x01e0 ;
switch ( V_60 & V_63 ) {
case V_64 :
V_90 |= 0x0002 ;
break;
case V_65 :
break;
case V_66 :
V_90 |= 0x0001 ;
break;
case V_67 :
V_90 |= 0x0003 ;
break;
case V_68 :
V_90 |= 0x0013 ;
break;
default:
return - V_52 ;
}
F_8 ( V_10 , V_91 , V_90 ) ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
T_1 V_15 , V_90 ;
V_90 = F_7 ( V_10 , V_91 ) & 0x011f ;
V_15 = F_7 ( V_10 , V_17 ) & 0x00ae ;
switch ( V_60 & V_76 ) {
case V_77 :
break;
case V_78 :
V_15 |= 0x1 ;
case V_79 :
V_90 |= 0x0040 ;
break;
default:
return - V_52 ;
}
switch ( V_60 & V_63 ) {
case V_67 :
case V_68 :
switch ( V_60 & V_80 ) {
case V_81 :
break;
case V_82 :
V_90 |= 0x0080 ;
break;
default:
return - V_52 ;
}
break;
case V_64 :
case V_65 :
case V_66 :
V_90 &= ~ 0x0010 ;
switch ( V_60 & V_80 ) {
case V_81 :
break;
case V_83 :
V_90 |= 0x0090 ;
break;
case V_82 :
V_90 |= 0x0080 ;
break;
case V_84 :
V_90 |= 0x0010 ;
break;
default:
return - V_52 ;
}
break;
default:
return - V_52 ;
}
F_8 ( V_10 , V_91 , V_90 ) ;
F_8 ( V_10 , V_17 , V_15 ) ;
return 0 ;
}
static int F_26 ( struct V_69 * V_70 ,
struct V_71 * V_72 ,
struct V_33 * V_73 )
{
struct V_9 * V_10 = V_73 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
T_1 V_74 = F_7 ( V_10 , V_75 ) & 0x01c0 ;
T_1 V_90 = F_7 ( V_10 , V_91 ) & 0x01f3 ;
int V_92 ;
V_92 = F_15 ( V_12 -> V_57 , F_21 ( V_72 ) ) ;
if ( V_92 < 0 ) {
F_12 ( V_93 L_2 ) ;
return V_92 ;
}
F_8 ( V_10 , V_75 , V_74 | ( V_51 [ V_92 ] . V_94 << 1 ) |
V_51 [ V_92 ] . V_95 ) ;
switch ( F_20 ( V_72 ) ) {
case 16 :
break;
case 20 :
V_90 |= 0x0004 ;
break;
case 24 :
V_90 |= 0x0008 ;
break;
case 32 :
V_90 |= 0x000c ;
break;
}
F_8 ( V_10 , V_91 , V_90 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
T_1 clock ;
clock = F_7 ( V_10 , V_43 ) & 0xfffb ;
F_8 ( V_10 , V_43 , clock ) ;
return F_18 ( V_10 , V_60 ) ;
}
static int F_28 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
return F_24 ( V_10 , V_60 ) ;
}
static int F_29 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
T_1 clock ;
clock = F_7 ( V_10 , V_43 ) & 0xfffb ;
F_8 ( V_10 , V_43 , clock ) ;
return F_18 ( V_10 , V_60 ) ;
}
static int F_30 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
T_1 clock ;
clock = F_7 ( V_10 , V_43 ) & 0xfffb ;
F_8 ( V_10 , V_43 , clock | 0x4 ) ;
if ( F_24 ( V_10 , V_60 ) < 0 )
return - V_52 ;
return F_18 ( V_10 , V_60 ) ;
}
static int F_9 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_96 = 0 ;
switch ( V_12 -> V_14 ) {
case 0 :
V_96 = F_28 ( V_10 , V_60 ) ;
break;
case 1 :
V_96 = F_29 ( V_10 , V_60 ) ;
break;
case 2 :
case 3 :
V_96 = F_30 ( V_10 , V_60 ) ;
break;
default:
break;
}
if ( V_96 )
return V_96 ;
return F_25 ( V_10 , V_60 ) ;
}
static int F_31 ( struct V_33 * V_34 ,
unsigned int V_60 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
V_12 -> V_18 = V_60 ;
return F_9 ( V_10 , V_60 ) ;
}
static int F_10 ( struct V_9 * V_10 ,
unsigned int V_60 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_96 = 0 ;
if ( V_12 -> V_14 != 0 )
return 0 ;
V_96 = F_27 ( V_10 , V_60 ) ;
if ( V_96 )
return V_96 ;
V_96 = F_22 ( V_10 , V_60 ) ;
if ( V_96 )
return V_96 ;
return 0 ;
}
static int F_32 ( struct V_33 * V_34 ,
unsigned int V_60 )
{
struct V_9 * V_10 = V_34 -> V_10 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
V_12 -> V_19 = V_60 ;
return F_10 ( V_10 , V_60 ) ;
}
static int F_33 ( struct V_33 * V_73 , int V_97 )
{
struct V_9 * V_10 = V_73 -> V_10 ;
T_1 V_98 = F_7 ( V_10 , V_99 ) & 0xfff7 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
if ( V_97 && V_12 -> V_14 == 1 ) {
if ( ! F_6 ( V_10 ) )
F_8 ( V_10 , V_99 , V_98 | 0x8 ) ;
} else {
if ( V_97 )
F_8 ( V_10 , V_99 , V_98 | 0x8 ) ;
else
F_8 ( V_10 , V_99 , V_98 ) ;
}
return 0 ;
}
static void F_34 ( struct V_100 * V_101 )
{
struct V_11 * V_12 =
F_35 ( V_101 , struct V_11 , V_102 . V_101 ) ;
F_36 ( V_12 -> V_103 , V_104 , 0x0180 , 0x0100 ) ;
}
static int F_37 ( struct V_9 * V_10 ,
enum V_105 V_106 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
T_1 V_107 = F_7 ( V_10 , V_104 ) & 0xfe3e ;
switch ( V_106 ) {
case V_108 :
F_8 ( V_10 , V_104 , V_107 | 0x00c0 ) ;
break;
case V_109 :
F_38 ( & V_12 -> V_102 ) ;
break;
case V_110 :
if ( F_39 ( V_10 ) == V_111 ) {
F_8 ( V_10 , V_104 , V_107 | 0x01c1 ) ;
F_40 ( & V_12 -> V_102 ,
F_41 ( V_112 ) ) ;
} else {
F_8 ( V_10 , V_104 , V_107 | 0x0141 ) ;
}
break;
case V_111 :
F_42 ( & V_12 -> V_102 ) ;
F_8 ( V_10 , V_104 , 0x0001 ) ;
break;
}
return 0 ;
}
static int F_43 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
F_44 ( V_12 -> V_103 ) ;
return 0 ;
}
static int F_45 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
int V_96 ;
F_46 ( & V_12 -> V_102 , F_34 ) ;
V_96 = F_47 ( V_10 ) ;
if ( V_96 < 0 ) {
F_48 ( V_10 -> V_2 , L_3 , V_96 ) ;
return V_96 ;
}
V_12 -> V_14 = 0 ;
F_49 ( V_10 , V_113 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_114 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_115 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_116 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_117 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_118 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_119 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_120 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_121 , 0x0100 , 0x0100 ) ;
F_49 ( V_10 , V_122 , 0x0100 , 0x0100 ) ;
return 0 ;
}
static int F_50 ( struct V_123 * V_124 )
{
struct V_11 * V_12 ;
int V_96 ;
V_12 = F_51 ( & V_124 -> V_2 , sizeof( struct V_11 ) ,
V_125 ) ;
if ( V_12 == NULL )
return - V_126 ;
F_52 ( V_124 , V_12 ) ;
V_12 -> V_103 = F_53 ( V_124 , & V_127 ) ;
if ( F_54 ( V_12 -> V_103 ) ) {
V_96 = F_55 ( V_12 -> V_103 ) ;
F_48 ( & V_124 -> V_2 , L_4 ,
V_96 ) ;
return V_96 ;
}
V_96 = F_56 ( & V_124 -> V_2 , & V_128 ,
V_129 , F_16 ( V_129 ) ) ;
if ( V_96 != 0 )
F_48 ( & V_124 -> V_2 , L_5 , V_96 ) ;
return V_96 ;
}
static int F_57 ( struct V_123 * V_124 )
{
F_58 ( & V_124 -> V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_130 * V_131 ,
const struct V_132 * V_133 )
{
struct V_11 * V_12 ;
int V_96 ;
V_12 = F_51 ( & V_131 -> V_2 , sizeof( struct V_11 ) ,
V_125 ) ;
if ( V_12 == NULL )
return - V_126 ;
F_60 ( V_131 , V_12 ) ;
V_12 -> V_103 = F_61 ( V_131 , & V_127 ) ;
if ( F_54 ( V_12 -> V_103 ) ) {
V_96 = F_55 ( V_12 -> V_103 ) ;
F_48 ( & V_131 -> V_2 , L_4 ,
V_96 ) ;
return V_96 ;
}
V_96 = F_56 ( & V_131 -> V_2 , & V_128 ,
V_129 , F_16 ( V_129 ) ) ;
if ( V_96 != 0 )
F_48 ( & V_131 -> V_2 , L_5 , V_96 ) ;
return V_96 ;
}
static int F_62 ( struct V_130 * V_134 )
{
F_58 ( & V_134 -> V_2 ) ;
return 0 ;
}
static int T_3 F_63 ( void )
{
int V_96 = 0 ;
#if F_64 ( V_135 )
V_96 = F_65 ( & V_136 ) ;
if ( V_96 != 0 ) {
F_12 ( V_93 L_6 ,
V_96 ) ;
}
#endif
#if F_66 ( V_137 )
V_96 = F_67 ( & V_138 ) ;
if ( V_96 != 0 ) {
F_12 ( V_93 L_7 ,
V_96 ) ;
}
#endif
return V_96 ;
}
static void T_4 F_68 ( void )
{
#if F_64 ( V_135 )
F_69 ( & V_136 ) ;
#endif
#if F_66 ( V_137 )
F_70 ( & V_138 ) ;
#endif
}
