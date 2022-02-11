static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_4 -> V_9 . integer . V_9 [ 0 ] = V_8 -> V_10 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_11 ;
if ( V_8 -> V_10 == V_4 -> V_9 . integer . V_9 [ 0 ] )
return 0 ;
if ( V_6 -> V_12 )
return - V_13 ;
V_11 = F_5 ( V_6 , V_14 ) ;
V_8 -> V_10 = V_4 -> V_9 . integer . V_9 [ 0 ] ;
if ( ( ( V_11 >> 2 ) & 0x3 ) == V_8 -> V_10 )
return 1 ;
V_11 = ( V_11 & 0x1f3 ) | ( V_8 -> V_10 << 2 ) ;
F_6 ( V_6 , V_14 , V_11 ) ;
F_7 ( V_6 , V_8 -> V_15 ) ;
F_8 ( V_6 , V_8 -> V_16 ) ;
return 1 ;
}
static void F_9 ( struct V_17 * V_18 , unsigned int V_19 ,
unsigned int V_20 )
{
T_2 V_21 ;
unsigned int V_22 , V_23 , V_24 ;
V_23 = V_19 / V_20 ;
if ( V_23 < 6 ) {
V_20 >>= 1 ;
V_18 -> V_25 = 1 ;
V_23 = V_19 / V_20 ;
} else
V_18 -> V_25 = 0 ;
if ( ( V_23 < 6 ) || ( V_23 > 12 ) )
F_10 ( V_26
L_1 , V_23 ) ;
V_18 -> V_27 = V_23 ;
V_24 = V_19 % V_20 ;
V_21 = V_28 * ( long long ) V_24 ;
F_11 ( V_21 , V_20 ) ;
V_22 = V_21 & 0xFFFFFFFF ;
if ( ( V_22 % 10 ) >= 5 )
V_22 += 5 ;
V_22 /= 10 ;
V_18 -> V_29 = V_22 ;
}
static int F_12 ( struct V_30 * V_31 , int V_32 ,
int V_20 , unsigned int V_33 , unsigned int V_34 )
{
T_1 V_35 , V_36 ;
int V_37 ;
struct V_5 * V_6 = V_31 -> V_6 ;
if ( V_32 < V_38 || V_32 > V_39 )
return - V_40 ;
if ( V_32 == V_38 ) {
V_37 = 0 ;
V_36 = 0x10 ;
V_35 = F_5 ( V_6 , V_41 ) & 0xffef ;
} else {
V_37 = 4 ;
V_36 = 0x8 ;
V_35 = F_5 ( V_6 , V_41 ) & 0xfff7 ;
}
if ( ! V_33 || ! V_34 ) {
F_6 ( V_6 , V_42 + V_37 , 0x0026 ) ;
F_6 ( V_6 , V_41 , V_35 ) ;
return 0 ;
} else {
T_1 V_9 = 0 ;
struct V_17 V_18 ;
F_9 ( & V_18 , V_34 * 8 , V_33 ) ;
V_9 = ( V_18 . V_27 << 5 ) + ( ( V_18 . V_29 & 0x3c0000 ) >> 18 ) ;
F_6 ( V_6 , V_43 + V_37 , V_9 ) ;
V_9 = ( V_18 . V_29 & 0x03fe00 ) >> 9 ;
F_6 ( V_6 , V_44 + V_37 , V_9 ) ;
V_9 = V_18 . V_29 & 0x0001ff ;
F_6 ( V_6 , V_45 + V_37 , V_9 ) ;
F_6 ( V_6 , V_42 + V_37 , 0x0027 |
( V_18 . V_25 << 3 ) ) ;
F_6 ( V_6 , V_41 , V_35 | V_36 ) ;
}
return 0 ;
}
static int F_13 ( int V_46 , int V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_14 ( V_49 ) ; V_48 ++ ) {
if ( V_49 [ V_48 ] . V_47 == V_47 && V_49 [ V_48 ] . V_46 == V_46 )
return V_48 ;
}
return - V_50 ;
}
static int F_15 ( struct V_30 * V_31 ,
int V_51 , unsigned int V_52 , int V_53 )
{
struct V_5 * V_6 = V_31 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
switch ( V_52 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
if ( V_51 == V_54 ) {
V_8 -> V_55 = V_52 ;
return 0 ;
} else if ( V_51 == V_56 ) {
V_8 -> V_57 = V_52 ;
return 0 ;
}
break;
}
return - V_50 ;
}
static int F_16 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
T_1 V_59 = F_5 ( V_6 , V_60 ) & 0x01ec ;
switch ( V_58 & V_61 ) {
case V_62 :
V_59 |= 0x0002 ;
break;
case V_63 :
break;
case V_64 :
V_59 |= 0x0001 ;
break;
case V_65 :
V_59 |= 0x0003 ;
break;
case V_66 :
V_59 |= 0x0013 ;
break;
default:
return - V_50 ;
}
F_6 ( V_6 , V_60 , V_59 ) ;
return 0 ;
}
static int F_17 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_30 * V_71 )
{
struct V_72 * V_73 = V_68 -> V_74 ;
struct V_5 * V_6 = V_73 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_59 = F_5 ( V_6 , V_60 ) & 0x01f3 ;
T_1 V_75 = F_5 ( V_6 , V_76 ) & 0x017f ;
switch ( F_18 ( V_70 ) ) {
case V_77 :
break;
case V_78 :
V_59 |= 0x0004 ;
break;
case V_79 :
V_59 |= 0x0008 ;
break;
case V_80 :
V_59 |= 0x000c ;
break;
}
if ( F_19 ( V_70 ) * 384 == V_8 -> V_57 )
V_75 |= 0x80 ;
F_6 ( V_6 , V_76 , V_75 ) ;
F_6 ( V_6 , V_60 , V_59 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
T_1 V_59 , V_11 ;
V_59 = F_5 ( V_6 , V_60 ) & 0x011f ;
V_11 = F_5 ( V_6 , V_14 ) & 0x015d ;
switch ( V_58 & V_81 ) {
case V_82 :
break;
case V_83 :
V_11 |= 0x2 ;
case V_84 :
V_59 |= 0x0040 ;
break;
default:
return - V_50 ;
}
switch ( V_58 & V_61 ) {
case V_65 :
case V_66 :
switch ( V_58 & V_85 ) {
case V_86 :
break;
case V_87 :
V_59 |= 0x0080 ;
break;
default:
return - V_50 ;
}
break;
case V_62 :
case V_63 :
case V_64 :
V_59 &= ~ 0x0010 ;
switch ( V_58 & V_85 ) {
case V_86 :
break;
case V_88 :
V_59 |= 0x0090 ;
break;
case V_87 :
V_59 |= 0x0080 ;
break;
case V_89 :
V_59 |= 0x0010 ;
break;
default:
return - V_50 ;
}
break;
default:
return - V_50 ;
}
F_6 ( V_6 , V_60 , V_59 ) ;
F_6 ( V_6 , V_14 , V_11 ) ;
return 0 ;
}
static int F_21 ( struct V_30 * V_31 ,
int V_90 , int div )
{
struct V_5 * V_6 = V_31 -> V_6 ;
T_1 V_35 ;
switch ( V_90 ) {
case V_91 :
V_35 = F_5 ( V_6 , V_41 ) & 0x003f ;
F_6 ( V_6 , V_41 , V_35 | div ) ;
break;
case V_92 :
V_35 = F_5 ( V_6 , V_93 ) & 0x01c7 ;
F_6 ( V_6 , V_93 , V_35 | div ) ;
break;
case V_94 :
V_35 = F_5 ( V_6 , V_93 ) & 0x003f ;
F_6 ( V_6 , V_93 , V_35 | div ) ;
break;
default:
return - V_50 ;
}
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
T_1 V_95 = F_5 ( V_6 , V_96 ) & 0x01e0 ;
switch ( V_58 & V_61 ) {
case V_62 :
V_95 |= 0x0002 ;
break;
case V_63 :
break;
case V_64 :
V_95 |= 0x0001 ;
break;
case V_65 :
V_95 |= 0x0003 ;
break;
case V_66 :
V_95 |= 0x0013 ;
break;
default:
return - V_50 ;
}
F_6 ( V_6 , V_96 , V_95 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
T_1 V_11 , V_95 ;
V_95 = F_5 ( V_6 , V_96 ) & 0x011f ;
V_11 = F_5 ( V_6 , V_14 ) & 0x00ae ;
switch ( V_58 & V_81 ) {
case V_82 :
break;
case V_83 :
V_11 |= 0x1 ;
case V_84 :
V_95 |= 0x0040 ;
break;
default:
return - V_50 ;
}
switch ( V_58 & V_61 ) {
case V_65 :
case V_66 :
switch ( V_58 & V_85 ) {
case V_86 :
break;
case V_87 :
V_95 |= 0x0080 ;
break;
default:
return - V_50 ;
}
break;
case V_62 :
case V_63 :
case V_64 :
V_95 &= ~ 0x0010 ;
switch ( V_58 & V_85 ) {
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
return - V_50 ;
}
break;
default:
return - V_50 ;
}
F_6 ( V_6 , V_96 , V_95 ) ;
F_6 ( V_6 , V_14 , V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_30 * V_71 )
{
struct V_72 * V_73 = V_68 -> V_74 ;
struct V_5 * V_6 = V_73 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
T_1 V_75 = F_5 ( V_6 , V_76 ) & 0x01c0 ;
T_1 V_95 = F_5 ( V_6 , V_96 ) & 0x01f3 ;
int V_97 ;
V_97 = F_13 ( V_8 -> V_55 , F_19 ( V_70 ) ) ;
if ( V_97 < 0 ) {
F_10 ( V_98 L_2 ) ;
return V_97 ;
}
F_6 ( V_6 , V_76 , V_75 | ( V_49 [ V_97 ] . V_99 << 1 ) |
V_49 [ V_97 ] . V_100 ) ;
switch ( F_18 ( V_70 ) ) {
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
F_6 ( V_6 , V_96 , V_95 ) ;
return 0 ;
}
static int F_25 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
T_1 clock ;
clock = F_5 ( V_6 , V_41 ) & 0xfffb ;
F_6 ( V_6 , V_41 , clock ) ;
return F_16 ( V_6 , V_58 ) ;
}
static int F_26 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
return F_22 ( V_6 , V_58 ) ;
}
static int F_27 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
T_1 clock ;
clock = F_5 ( V_6 , V_41 ) & 0xfffb ;
F_6 ( V_6 , V_41 , clock ) ;
return F_16 ( V_6 , V_58 ) ;
}
static int F_28 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
T_1 clock ;
clock = F_5 ( V_6 , V_41 ) & 0xfffb ;
F_6 ( V_6 , V_41 , clock | 0x4 ) ;
if ( F_22 ( V_6 , V_58 ) < 0 )
return - V_50 ;
return F_16 ( V_6 , V_58 ) ;
}
static int F_7 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_101 = 0 ;
switch ( V_8 -> V_10 ) {
case 0 :
V_101 = F_26 ( V_6 , V_58 ) ;
break;
case 1 :
V_101 = F_27 ( V_6 , V_58 ) ;
break;
case 2 :
case 3 :
V_101 = F_28 ( V_6 , V_58 ) ;
break;
default:
break;
}
if ( V_101 )
return V_101 ;
return F_23 ( V_6 , V_58 ) ;
}
static int F_29 ( struct V_30 * V_31 ,
unsigned int V_58 )
{
struct V_5 * V_6 = V_31 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_15 = V_58 ;
return F_7 ( V_6 , V_58 ) ;
}
static int F_8 ( struct V_5 * V_6 ,
unsigned int V_58 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_101 = 0 ;
if ( V_8 -> V_10 != 0 )
return 0 ;
V_101 = F_25 ( V_6 , V_58 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_20 ( V_6 , V_58 ) ;
if ( V_101 )
return V_101 ;
return 0 ;
}
static int F_30 ( struct V_30 * V_31 ,
unsigned int V_58 )
{
struct V_5 * V_6 = V_31 -> V_6 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_16 = V_58 ;
return F_8 ( V_6 , V_58 ) ;
}
static int F_31 ( struct V_30 * V_71 , int V_102 )
{
struct V_5 * V_6 = V_71 -> V_6 ;
T_1 V_103 = F_5 ( V_6 , V_104 ) & 0xfff7 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( V_102 && V_8 -> V_10 == 1 ) {
if ( ! V_6 -> V_12 )
F_6 ( V_6 , V_104 , V_103 | 0x8 ) ;
} else {
if ( V_102 )
F_6 ( V_6 , V_104 , V_103 | 0x8 ) ;
else
F_6 ( V_6 , V_104 , V_103 ) ;
}
return 0 ;
}
static int F_32 ( struct V_5 * V_6 ,
enum V_105 V_106 )
{
T_1 V_107 = F_5 ( V_6 , V_108 ) & 0xfe3e ;
switch ( V_106 ) {
case V_109 :
F_6 ( V_6 , V_108 , V_107 | 0x00c0 ) ;
break;
case V_110 :
F_6 ( V_6 , V_108 , V_107 | 0x01c1 ) ;
break;
case V_111 :
F_6 ( V_6 , V_108 , V_107 | 0x0141 ) ;
break;
case V_112 :
F_6 ( V_6 , V_108 , 0x0001 ) ;
break;
}
V_6 -> V_113 . V_114 = V_106 ;
return 0 ;
}
static void F_33 ( struct V_115 * V_116 )
{
struct V_117 * V_113 =
F_34 ( V_116 , struct V_117 ,
V_118 . V_116 ) ;
struct V_5 * V_6 = V_113 -> V_6 ;
F_32 ( V_6 , V_113 -> V_114 ) ;
}
static int F_35 ( struct V_5 * V_6 )
{
F_32 ( V_6 , V_112 ) ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 )
{
T_1 * V_119 = V_6 -> V_119 ;
int V_48 ;
for ( V_48 = 1 ; V_48 < F_14 ( V_120 ) ; V_48 ++ ) {
if ( V_48 == V_121 )
continue;
if ( V_119 [ V_48 ] == V_120 [ V_48 ] )
continue;
F_6 ( V_6 , V_48 , V_119 [ V_48 ] ) ;
}
F_32 ( V_6 , V_111 ) ;
if ( V_6 -> V_113 . V_122 == V_109 ) {
F_32 ( V_6 , V_110 ) ;
V_6 -> V_113 . V_114 = V_109 ;
F_37 ( & V_6 -> V_113 . V_118 ,
F_38 ( V_123 ) ) ;
}
return 0 ;
}
static int F_39 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_101 ;
F_40 ( & V_6 -> V_113 . V_118 , F_33 ) ;
V_101 = F_41 ( V_6 , 7 , 9 , V_8 -> V_124 ) ;
if ( V_101 < 0 ) {
F_42 ( V_6 -> V_125 , L_3 , V_101 ) ;
return V_101 ;
}
V_101 = F_43 ( V_6 ) ;
if ( V_101 < 0 ) {
F_42 ( V_6 -> V_125 , L_4 , V_101 ) ;
return V_101 ;
}
F_32 ( V_6 , V_111 ) ;
V_8 -> V_10 = 0 ;
F_32 ( V_6 , V_110 ) ;
F_37 ( & V_6 -> V_113 . V_118 ,
F_38 ( V_123 ) ) ;
F_44 ( V_6 , V_126 , 0x0100 , 0x0100 ) ;
F_44 ( V_6 , V_127 , 0x0100 , 0x0100 ) ;
F_44 ( V_6 , V_128 , 0x0100 , 0x0100 ) ;
F_44 ( V_6 , V_129 , 0x0100 , 0x0100 ) ;
F_44 ( V_6 , V_130 , 0x0100 , 0x0100 ) ;
F_44 ( V_6 , V_131 , 0x0100 , 0x0100 ) ;
F_44 ( V_6 , V_132 , 0x0100 , 0x0100 ) ;
F_44 ( V_6 , V_133 , 0x0100 , 0x0100 ) ;
F_44 ( V_6 , V_134 , 0x0100 , 0x0100 ) ;
F_44 ( V_6 , V_135 , 0x0100 , 0x0100 ) ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 )
{
F_46 ( & V_6 -> V_113 . V_118 ) ;
F_32 ( V_6 , V_112 ) ;
return 0 ;
}
static int T_3 F_47 ( struct V_136 * V_137 )
{
struct V_7 * V_8 ;
int V_101 ;
V_8 = F_48 ( sizeof( struct V_7 ) , V_138 ) ;
if ( V_8 == NULL )
return - V_139 ;
V_8 -> V_124 = V_140 ;
F_49 ( V_137 , V_8 ) ;
V_101 = F_50 ( & V_137 -> V_125 ,
& V_141 , V_142 , F_14 ( V_142 ) ) ;
if ( V_101 < 0 )
F_51 ( V_8 ) ;
return V_101 ;
}
static int T_4 F_52 ( struct V_136 * V_137 )
{
F_53 ( & V_137 -> V_125 ) ;
F_51 ( F_54 ( V_137 ) ) ;
return 0 ;
}
static T_3 int F_55 ( struct V_143 * V_144 ,
const struct V_145 * V_146 )
{
struct V_7 * V_8 ;
int V_101 ;
V_8 = F_48 ( sizeof( struct V_7 ) , V_138 ) ;
if ( V_8 == NULL )
return - V_139 ;
F_56 ( V_144 , V_8 ) ;
V_8 -> V_124 = V_147 ;
V_101 = F_50 ( & V_144 -> V_125 ,
& V_141 , V_142 , F_14 ( V_142 ) ) ;
if ( V_101 < 0 )
F_51 ( V_8 ) ;
return V_101 ;
}
static T_4 int F_57 ( struct V_143 * V_148 )
{
F_53 ( & V_148 -> V_125 ) ;
F_51 ( F_58 ( V_148 ) ) ;
return 0 ;
}
static int T_5 F_59 ( void )
{
int V_101 = 0 ;
#if F_60 ( V_149 ) || F_60 ( V_150 )
V_101 = F_61 ( & V_151 ) ;
if ( V_101 != 0 ) {
F_10 ( V_98 L_5 ,
V_101 ) ;
}
#endif
#if F_60 ( V_152 )
V_101 = F_62 ( & V_153 ) ;
if ( V_101 != 0 ) {
F_10 ( V_98 L_6 ,
V_101 ) ;
}
#endif
return V_101 ;
}
static void T_6 F_63 ( void )
{
#if F_60 ( V_149 ) || F_60 ( V_150 )
F_64 ( & V_151 ) ;
#endif
#if F_60 ( V_152 )
F_65 ( & V_153 ) ;
#endif
}
