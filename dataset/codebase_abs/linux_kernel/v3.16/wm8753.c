static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 == V_4 ;
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_3 <= V_5 ;
}
static int F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
V_9 -> V_14 . integer . V_14 [ 0 ] = V_13 -> V_15 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = F_4 ( V_7 ) ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
T_1 V_16 ;
if ( V_13 -> V_15 == V_9 -> V_14 . integer . V_14 [ 0 ] )
return 0 ;
if ( F_7 ( V_11 ) )
return - V_17 ;
V_16 = F_8 ( V_11 , V_18 ) ;
V_13 -> V_15 = V_9 -> V_14 . integer . V_14 [ 0 ] ;
if ( ( ( V_16 >> 2 ) & 0x3 ) == V_13 -> V_15 )
return 1 ;
V_16 = ( V_16 & 0x1f3 ) | ( V_13 -> V_15 << 2 ) ;
F_9 ( V_11 , V_18 , V_16 ) ;
F_10 ( V_11 , V_13 -> V_19 ) ;
F_11 ( V_11 , V_13 -> V_20 ) ;
return 1 ;
}
static void F_12 ( struct V_21 * V_22 , unsigned int V_23 ,
unsigned int V_24 )
{
T_2 V_25 ;
unsigned int V_26 , V_27 , V_28 ;
V_27 = V_23 / V_24 ;
if ( V_27 < 6 ) {
V_24 >>= 1 ;
V_22 -> V_29 = 1 ;
V_27 = V_23 / V_24 ;
} else
V_22 -> V_29 = 0 ;
if ( ( V_27 < 6 ) || ( V_27 > 12 ) )
F_13 ( V_30
L_1 , V_27 ) ;
V_22 -> V_31 = V_27 ;
V_28 = V_23 % V_24 ;
V_25 = V_32 * ( long long ) V_28 ;
F_14 ( V_25 , V_24 ) ;
V_26 = V_25 & 0xFFFFFFFF ;
if ( ( V_26 % 10 ) >= 5 )
V_26 += 5 ;
V_26 /= 10 ;
V_22 -> V_33 = V_26 ;
}
static int F_15 ( struct V_34 * V_35 , int V_36 ,
int V_24 , unsigned int V_37 , unsigned int V_38 )
{
T_1 V_3 , V_39 ;
int V_40 ;
struct V_10 * V_11 = V_35 -> V_11 ;
if ( V_36 < V_41 || V_36 > V_42 )
return - V_43 ;
if ( V_36 == V_41 ) {
V_40 = 0 ;
V_39 = 0x10 ;
V_3 = F_8 ( V_11 , V_44 ) & 0xffef ;
} else {
V_40 = 4 ;
V_39 = 0x8 ;
V_3 = F_8 ( V_11 , V_44 ) & 0xfff7 ;
}
if ( ! V_37 || ! V_38 ) {
F_9 ( V_11 , V_45 + V_40 , 0x0026 ) ;
F_9 ( V_11 , V_44 , V_3 ) ;
return 0 ;
} else {
T_1 V_14 = 0 ;
struct V_21 V_22 ;
F_12 ( & V_22 , V_38 * 8 , V_37 ) ;
V_14 = ( V_22 . V_31 << 5 ) + ( ( V_22 . V_33 & 0x3c0000 ) >> 18 ) ;
F_9 ( V_11 , V_46 + V_40 , V_14 ) ;
V_14 = ( V_22 . V_33 & 0x03fe00 ) >> 9 ;
F_9 ( V_11 , V_47 + V_40 , V_14 ) ;
V_14 = V_22 . V_33 & 0x0001ff ;
F_9 ( V_11 , V_48 + V_40 , V_14 ) ;
F_9 ( V_11 , V_45 + V_40 , 0x0027 |
( V_22 . V_29 << 3 ) ) ;
F_9 ( V_11 , V_44 , V_3 | V_39 ) ;
}
return 0 ;
}
static int F_16 ( int V_49 , int V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < F_17 ( V_52 ) ; V_51 ++ ) {
if ( V_52 [ V_51 ] . V_50 == V_50 && V_52 [ V_51 ] . V_49 == V_49 )
return V_51 ;
}
return - V_53 ;
}
static int F_18 ( struct V_34 * V_35 ,
int V_54 , unsigned int V_55 , int V_56 )
{
struct V_10 * V_11 = V_35 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
switch ( V_55 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
if ( V_54 == V_57 ) {
V_13 -> V_58 = V_55 ;
return 0 ;
} else if ( V_54 == V_59 ) {
V_13 -> V_60 = V_55 ;
return 0 ;
}
break;
}
return - V_53 ;
}
static int F_19 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
T_1 V_62 = F_8 ( V_11 , V_63 ) & 0x01ec ;
switch ( V_61 & V_64 ) {
case V_65 :
V_62 |= 0x0002 ;
break;
case V_66 :
break;
case V_67 :
V_62 |= 0x0001 ;
break;
case V_68 :
V_62 |= 0x0003 ;
break;
case V_69 :
V_62 |= 0x0013 ;
break;
default:
return - V_53 ;
}
F_9 ( V_11 , V_63 , V_62 ) ;
return 0 ;
}
static int F_20 ( struct V_70 * V_71 ,
struct V_72 * V_73 ,
struct V_34 * V_74 )
{
struct V_10 * V_11 = V_74 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
T_1 V_62 = F_8 ( V_11 , V_63 ) & 0x01f3 ;
T_1 V_75 = F_8 ( V_11 , V_76 ) & 0x017f ;
switch ( F_21 ( V_73 ) ) {
case V_77 :
break;
case V_78 :
V_62 |= 0x0004 ;
break;
case V_79 :
V_62 |= 0x0008 ;
break;
case V_80 :
V_62 |= 0x000c ;
break;
}
if ( F_22 ( V_73 ) * 384 == V_13 -> V_60 )
V_75 |= 0x80 ;
F_9 ( V_11 , V_76 , V_75 ) ;
F_9 ( V_11 , V_63 , V_62 ) ;
return 0 ;
}
static int F_23 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
T_1 V_62 , V_16 ;
V_62 = F_8 ( V_11 , V_63 ) & 0x011f ;
V_16 = F_8 ( V_11 , V_18 ) & 0x015d ;
switch ( V_61 & V_81 ) {
case V_82 :
break;
case V_83 :
V_16 |= 0x2 ;
case V_84 :
V_62 |= 0x0040 ;
break;
default:
return - V_53 ;
}
switch ( V_61 & V_64 ) {
case V_68 :
case V_69 :
switch ( V_61 & V_85 ) {
case V_86 :
break;
case V_87 :
V_62 |= 0x0080 ;
break;
default:
return - V_53 ;
}
break;
case V_65 :
case V_66 :
case V_67 :
V_62 &= ~ 0x0010 ;
switch ( V_61 & V_85 ) {
case V_86 :
break;
case V_88 :
V_62 |= 0x0090 ;
break;
case V_87 :
V_62 |= 0x0080 ;
break;
case V_89 :
V_62 |= 0x0010 ;
break;
default:
return - V_53 ;
}
break;
default:
return - V_53 ;
}
F_9 ( V_11 , V_63 , V_62 ) ;
F_9 ( V_11 , V_18 , V_16 ) ;
return 0 ;
}
static int F_24 ( struct V_34 * V_35 ,
int V_90 , int div )
{
struct V_10 * V_11 = V_35 -> V_11 ;
T_1 V_3 ;
switch ( V_90 ) {
case V_91 :
V_3 = F_8 ( V_11 , V_44 ) & 0x003f ;
F_9 ( V_11 , V_44 , V_3 | div ) ;
break;
case V_92 :
V_3 = F_8 ( V_11 , V_93 ) & 0x01c7 ;
F_9 ( V_11 , V_93 , V_3 | div ) ;
break;
case V_94 :
V_3 = F_8 ( V_11 , V_93 ) & 0x003f ;
F_9 ( V_11 , V_93 , V_3 | div ) ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_25 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
T_1 V_95 = F_8 ( V_11 , V_96 ) & 0x01e0 ;
switch ( V_61 & V_64 ) {
case V_65 :
V_95 |= 0x0002 ;
break;
case V_66 :
break;
case V_67 :
V_95 |= 0x0001 ;
break;
case V_68 :
V_95 |= 0x0003 ;
break;
case V_69 :
V_95 |= 0x0013 ;
break;
default:
return - V_53 ;
}
F_9 ( V_11 , V_96 , V_95 ) ;
return 0 ;
}
static int F_26 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
T_1 V_16 , V_95 ;
V_95 = F_8 ( V_11 , V_96 ) & 0x011f ;
V_16 = F_8 ( V_11 , V_18 ) & 0x00ae ;
switch ( V_61 & V_81 ) {
case V_82 :
break;
case V_83 :
V_16 |= 0x1 ;
case V_84 :
V_95 |= 0x0040 ;
break;
default:
return - V_53 ;
}
switch ( V_61 & V_64 ) {
case V_68 :
case V_69 :
switch ( V_61 & V_85 ) {
case V_86 :
break;
case V_87 :
V_95 |= 0x0080 ;
break;
default:
return - V_53 ;
}
break;
case V_65 :
case V_66 :
case V_67 :
V_95 &= ~ 0x0010 ;
switch ( V_61 & V_85 ) {
case V_86 :
break;
case V_88 :
V_95 |= 0x0090 ;
break;
case V_87 :
V_95 |= 0x0080 ;
break;
case V_89 :
V_95 |= 0x0010 ;
break;
default:
return - V_53 ;
}
break;
default:
return - V_53 ;
}
F_9 ( V_11 , V_96 , V_95 ) ;
F_9 ( V_11 , V_18 , V_16 ) ;
return 0 ;
}
static int F_27 ( struct V_70 * V_71 ,
struct V_72 * V_73 ,
struct V_34 * V_74 )
{
struct V_10 * V_11 = V_74 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
T_1 V_75 = F_8 ( V_11 , V_76 ) & 0x01c0 ;
T_1 V_95 = F_8 ( V_11 , V_96 ) & 0x01f3 ;
int V_97 ;
V_97 = F_16 ( V_13 -> V_58 , F_22 ( V_73 ) ) ;
if ( V_97 < 0 ) {
F_13 ( V_98 L_2 ) ;
return V_97 ;
}
F_9 ( V_11 , V_76 , V_75 | ( V_52 [ V_97 ] . V_99 << 1 ) |
V_52 [ V_97 ] . V_100 ) ;
switch ( F_21 ( V_73 ) ) {
case V_77 :
break;
case V_78 :
V_95 |= 0x0004 ;
break;
case V_79 :
V_95 |= 0x0008 ;
break;
case V_80 :
V_95 |= 0x000c ;
break;
}
F_9 ( V_11 , V_96 , V_95 ) ;
return 0 ;
}
static int F_28 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
T_1 clock ;
clock = F_8 ( V_11 , V_44 ) & 0xfffb ;
F_9 ( V_11 , V_44 , clock ) ;
return F_19 ( V_11 , V_61 ) ;
}
static int F_29 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
return F_25 ( V_11 , V_61 ) ;
}
static int F_30 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
T_1 clock ;
clock = F_8 ( V_11 , V_44 ) & 0xfffb ;
F_9 ( V_11 , V_44 , clock ) ;
return F_19 ( V_11 , V_61 ) ;
}
static int F_31 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
T_1 clock ;
clock = F_8 ( V_11 , V_44 ) & 0xfffb ;
F_9 ( V_11 , V_44 , clock | 0x4 ) ;
if ( F_25 ( V_11 , V_61 ) < 0 )
return - V_53 ;
return F_19 ( V_11 , V_61 ) ;
}
static int F_10 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_101 = 0 ;
switch ( V_13 -> V_15 ) {
case 0 :
V_101 = F_29 ( V_11 , V_61 ) ;
break;
case 1 :
V_101 = F_30 ( V_11 , V_61 ) ;
break;
case 2 :
case 3 :
V_101 = F_31 ( V_11 , V_61 ) ;
break;
default:
break;
}
if ( V_101 )
return V_101 ;
return F_26 ( V_11 , V_61 ) ;
}
static int F_32 ( struct V_34 * V_35 ,
unsigned int V_61 )
{
struct V_10 * V_11 = V_35 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
V_13 -> V_19 = V_61 ;
return F_10 ( V_11 , V_61 ) ;
}
static int F_11 ( struct V_10 * V_11 ,
unsigned int V_61 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_101 = 0 ;
if ( V_13 -> V_15 != 0 )
return 0 ;
V_101 = F_28 ( V_11 , V_61 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_23 ( V_11 , V_61 ) ;
if ( V_101 )
return V_101 ;
return 0 ;
}
static int F_33 ( struct V_34 * V_35 ,
unsigned int V_61 )
{
struct V_10 * V_11 = V_35 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
V_13 -> V_20 = V_61 ;
return F_11 ( V_11 , V_61 ) ;
}
static int F_34 ( struct V_34 * V_74 , int V_102 )
{
struct V_10 * V_11 = V_74 -> V_11 ;
T_1 V_103 = F_8 ( V_11 , V_104 ) & 0xfff7 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_102 && V_13 -> V_15 == 1 ) {
if ( ! F_7 ( V_11 ) )
F_9 ( V_11 , V_104 , V_103 | 0x8 ) ;
} else {
if ( V_102 )
F_9 ( V_11 , V_104 , V_103 | 0x8 ) ;
else
F_9 ( V_11 , V_104 , V_103 ) ;
}
return 0 ;
}
static int F_35 ( struct V_10 * V_11 ,
enum V_105 V_106 )
{
T_1 V_107 = F_8 ( V_11 , V_108 ) & 0xfe3e ;
switch ( V_106 ) {
case V_109 :
F_9 ( V_11 , V_108 , V_107 | 0x00c0 ) ;
break;
case V_110 :
F_9 ( V_11 , V_108 , V_107 | 0x01c1 ) ;
break;
case V_111 :
F_9 ( V_11 , V_108 , V_107 | 0x0141 ) ;
break;
case V_112 :
F_9 ( V_11 , V_108 , 0x0001 ) ;
break;
}
V_11 -> V_113 . V_114 = V_106 ;
return 0 ;
}
static void F_36 ( struct V_115 * V_116 )
{
struct V_117 * V_113 =
F_37 ( V_116 , struct V_117 ,
V_118 . V_116 ) ;
struct V_10 * V_11 = V_113 -> V_11 ;
F_35 ( V_11 , V_113 -> V_114 ) ;
}
static int F_38 ( struct V_10 * V_11 )
{
F_35 ( V_11 , V_112 ) ;
return 0 ;
}
static int F_39 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_40 ( V_13 -> V_119 ) ;
F_35 ( V_11 , V_111 ) ;
if ( V_11 -> V_113 . V_120 == V_109 ) {
F_35 ( V_11 , V_110 ) ;
V_11 -> V_113 . V_114 = V_109 ;
F_41 ( V_121 ,
& V_11 -> V_113 . V_118 ,
F_42 ( V_122 ) ) ;
}
return 0 ;
}
static int F_43 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_101 ;
F_44 ( & V_11 -> V_113 . V_118 , F_36 ) ;
V_101 = F_45 ( V_11 ) ;
if ( V_101 < 0 ) {
F_46 ( V_11 -> V_2 , L_3 , V_101 ) ;
return V_101 ;
}
F_35 ( V_11 , V_111 ) ;
V_13 -> V_15 = 0 ;
F_35 ( V_11 , V_110 ) ;
F_47 ( & V_11 -> V_113 . V_118 ,
F_42 ( V_122 ) ) ;
F_48 ( V_11 , V_123 , 0x0100 , 0x0100 ) ;
F_48 ( V_11 , V_124 , 0x0100 , 0x0100 ) ;
F_48 ( V_11 , V_125 , 0x0100 , 0x0100 ) ;
F_48 ( V_11 , V_126 , 0x0100 , 0x0100 ) ;
F_48 ( V_11 , V_127 , 0x0100 , 0x0100 ) ;
F_48 ( V_11 , V_128 , 0x0100 , 0x0100 ) ;
F_48 ( V_11 , V_129 , 0x0100 , 0x0100 ) ;
F_48 ( V_11 , V_130 , 0x0100 , 0x0100 ) ;
F_48 ( V_11 , V_131 , 0x0100 , 0x0100 ) ;
F_48 ( V_11 , V_132 , 0x0100 , 0x0100 ) ;
return 0 ;
}
static int F_49 ( struct V_10 * V_11 )
{
F_50 ( & V_11 -> V_113 . V_118 ) ;
F_35 ( V_11 , V_112 ) ;
return 0 ;
}
static int F_51 ( struct V_133 * V_134 )
{
struct V_12 * V_13 ;
int V_101 ;
V_13 = F_52 ( & V_134 -> V_2 , sizeof( struct V_12 ) ,
V_135 ) ;
if ( V_13 == NULL )
return - V_136 ;
F_53 ( V_134 , V_13 ) ;
V_13 -> V_119 = F_54 ( V_134 , & V_137 ) ;
if ( F_55 ( V_13 -> V_119 ) ) {
V_101 = F_56 ( V_13 -> V_119 ) ;
F_46 ( & V_134 -> V_2 , L_4 ,
V_101 ) ;
return V_101 ;
}
V_101 = F_57 ( & V_134 -> V_2 , & V_138 ,
V_139 , F_17 ( V_139 ) ) ;
if ( V_101 != 0 )
F_46 ( & V_134 -> V_2 , L_5 , V_101 ) ;
return V_101 ;
}
static int F_58 ( struct V_133 * V_134 )
{
F_59 ( & V_134 -> V_2 ) ;
return 0 ;
}
static int F_60 ( struct V_140 * V_141 ,
const struct V_142 * V_143 )
{
struct V_12 * V_13 ;
int V_101 ;
V_13 = F_52 ( & V_141 -> V_2 , sizeof( struct V_12 ) ,
V_135 ) ;
if ( V_13 == NULL )
return - V_136 ;
F_61 ( V_141 , V_13 ) ;
V_13 -> V_119 = F_62 ( V_141 , & V_137 ) ;
if ( F_55 ( V_13 -> V_119 ) ) {
V_101 = F_56 ( V_13 -> V_119 ) ;
F_46 ( & V_141 -> V_2 , L_4 ,
V_101 ) ;
return V_101 ;
}
V_101 = F_57 ( & V_141 -> V_2 , & V_138 ,
V_139 , F_17 ( V_139 ) ) ;
if ( V_101 != 0 )
F_46 ( & V_141 -> V_2 , L_5 , V_101 ) ;
return V_101 ;
}
static int F_63 ( struct V_140 * V_144 )
{
F_59 ( & V_144 -> V_2 ) ;
return 0 ;
}
static int T_3 F_64 ( void )
{
int V_101 = 0 ;
#if F_65 ( V_145 )
V_101 = F_66 ( & V_146 ) ;
if ( V_101 != 0 ) {
F_13 ( V_98 L_6 ,
V_101 ) ;
}
#endif
#if F_67 ( V_147 )
V_101 = F_68 ( & V_148 ) ;
if ( V_101 != 0 ) {
F_13 ( V_98 L_7 ,
V_101 ) ;
}
#endif
return V_101 ;
}
static void T_4 F_69 ( void )
{
#if F_65 ( V_145 )
F_70 ( & V_146 ) ;
#endif
#if F_67 ( V_147 )
F_71 ( & V_148 ) ;
#endif
}
