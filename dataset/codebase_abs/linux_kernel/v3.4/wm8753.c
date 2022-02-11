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
if ( V_11 -> V_17 )
return - V_18 ;
V_16 = F_7 ( V_11 , V_19 ) ;
V_13 -> V_15 = V_9 -> V_14 . integer . V_14 [ 0 ] ;
if ( ( ( V_16 >> 2 ) & 0x3 ) == V_13 -> V_15 )
return 1 ;
V_16 = ( V_16 & 0x1f3 ) | ( V_13 -> V_15 << 2 ) ;
F_8 ( V_11 , V_19 , V_16 ) ;
F_9 ( V_11 , V_13 -> V_20 ) ;
F_10 ( V_11 , V_13 -> V_21 ) ;
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
struct V_10 * V_11 = V_36 -> V_11 ;
if ( V_37 < V_42 || V_37 > V_43 )
return - V_44 ;
if ( V_37 == V_42 ) {
V_41 = 0 ;
V_40 = 0x10 ;
V_3 = F_7 ( V_11 , V_45 ) & 0xffef ;
} else {
V_41 = 4 ;
V_40 = 0x8 ;
V_3 = F_7 ( V_11 , V_45 ) & 0xfff7 ;
}
if ( ! V_38 || ! V_39 ) {
F_8 ( V_11 , V_46 + V_41 , 0x0026 ) ;
F_8 ( V_11 , V_45 , V_3 ) ;
return 0 ;
} else {
T_1 V_14 = 0 ;
struct V_22 V_23 ;
F_11 ( & V_23 , V_39 * 8 , V_38 ) ;
V_14 = ( V_23 . V_32 << 5 ) + ( ( V_23 . V_34 & 0x3c0000 ) >> 18 ) ;
F_8 ( V_11 , V_47 + V_41 , V_14 ) ;
V_14 = ( V_23 . V_34 & 0x03fe00 ) >> 9 ;
F_8 ( V_11 , V_48 + V_41 , V_14 ) ;
V_14 = V_23 . V_34 & 0x0001ff ;
F_8 ( V_11 , V_49 + V_41 , V_14 ) ;
F_8 ( V_11 , V_46 + V_41 , 0x0027 |
( V_23 . V_30 << 3 ) ) ;
F_8 ( V_11 , V_45 , V_3 | V_40 ) ;
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
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
switch ( V_56 ) {
case 11289600 :
case 12000000 :
case 12288000 :
case 16934400 :
case 18432000 :
if ( V_55 == V_58 ) {
V_13 -> V_59 = V_56 ;
return 0 ;
} else if ( V_55 == V_60 ) {
V_13 -> V_61 = V_56 ;
return 0 ;
}
break;
}
return - V_54 ;
}
static int F_18 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
T_1 V_63 = F_7 ( V_11 , V_64 ) & 0x01ec ;
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
F_8 ( V_11 , V_64 , V_63 ) ;
return 0 ;
}
static int F_19 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_35 * V_75 )
{
struct V_76 * V_77 = V_72 -> V_78 ;
struct V_10 * V_11 = V_77 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
T_1 V_63 = F_7 ( V_11 , V_64 ) & 0x01f3 ;
T_1 V_79 = F_7 ( V_11 , V_80 ) & 0x017f ;
switch ( F_20 ( V_74 ) ) {
case V_81 :
break;
case V_82 :
V_63 |= 0x0004 ;
break;
case V_83 :
V_63 |= 0x0008 ;
break;
case V_84 :
V_63 |= 0x000c ;
break;
}
if ( F_21 ( V_74 ) * 384 == V_13 -> V_61 )
V_79 |= 0x80 ;
F_8 ( V_11 , V_80 , V_79 ) ;
F_8 ( V_11 , V_64 , V_63 ) ;
return 0 ;
}
static int F_22 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
T_1 V_63 , V_16 ;
V_63 = F_7 ( V_11 , V_64 ) & 0x011f ;
V_16 = F_7 ( V_11 , V_19 ) & 0x015d ;
switch ( V_62 & V_85 ) {
case V_86 :
break;
case V_87 :
V_16 |= 0x2 ;
case V_88 :
V_63 |= 0x0040 ;
break;
default:
return - V_54 ;
}
switch ( V_62 & V_65 ) {
case V_69 :
case V_70 :
switch ( V_62 & V_89 ) {
case V_90 :
break;
case V_91 :
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
switch ( V_62 & V_89 ) {
case V_90 :
break;
case V_92 :
V_63 |= 0x0090 ;
break;
case V_91 :
V_63 |= 0x0080 ;
break;
case V_93 :
V_63 |= 0x0010 ;
break;
default:
return - V_54 ;
}
break;
default:
return - V_54 ;
}
F_8 ( V_11 , V_64 , V_63 ) ;
F_8 ( V_11 , V_19 , V_16 ) ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 ,
int V_94 , int div )
{
struct V_10 * V_11 = V_36 -> V_11 ;
T_1 V_3 ;
switch ( V_94 ) {
case V_95 :
V_3 = F_7 ( V_11 , V_45 ) & 0x003f ;
F_8 ( V_11 , V_45 , V_3 | div ) ;
break;
case V_96 :
V_3 = F_7 ( V_11 , V_97 ) & 0x01c7 ;
F_8 ( V_11 , V_97 , V_3 | div ) ;
break;
case V_98 :
V_3 = F_7 ( V_11 , V_97 ) & 0x003f ;
F_8 ( V_11 , V_97 , V_3 | div ) ;
break;
default:
return - V_54 ;
}
return 0 ;
}
static int F_24 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
T_1 V_99 = F_7 ( V_11 , V_100 ) & 0x01e0 ;
switch ( V_62 & V_65 ) {
case V_66 :
V_99 |= 0x0002 ;
break;
case V_67 :
break;
case V_68 :
V_99 |= 0x0001 ;
break;
case V_69 :
V_99 |= 0x0003 ;
break;
case V_70 :
V_99 |= 0x0013 ;
break;
default:
return - V_54 ;
}
F_8 ( V_11 , V_100 , V_99 ) ;
return 0 ;
}
static int F_25 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
T_1 V_16 , V_99 ;
V_99 = F_7 ( V_11 , V_100 ) & 0x011f ;
V_16 = F_7 ( V_11 , V_19 ) & 0x00ae ;
switch ( V_62 & V_85 ) {
case V_86 :
break;
case V_87 :
V_16 |= 0x1 ;
case V_88 :
V_99 |= 0x0040 ;
break;
default:
return - V_54 ;
}
switch ( V_62 & V_65 ) {
case V_69 :
case V_70 :
switch ( V_62 & V_89 ) {
case V_90 :
break;
case V_91 :
V_99 |= 0x0080 ;
break;
default:
return - V_54 ;
}
break;
case V_66 :
case V_67 :
case V_68 :
V_99 &= ~ 0x0010 ;
switch ( V_62 & V_89 ) {
case V_90 :
break;
case V_92 :
V_99 |= 0x0090 ;
break;
case V_91 :
V_99 |= 0x0080 ;
break;
case V_93 :
V_99 |= 0x0010 ;
break;
default:
return - V_54 ;
}
break;
default:
return - V_54 ;
}
F_8 ( V_11 , V_100 , V_99 ) ;
F_8 ( V_11 , V_19 , V_16 ) ;
return 0 ;
}
static int F_26 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_35 * V_75 )
{
struct V_76 * V_77 = V_72 -> V_78 ;
struct V_10 * V_11 = V_77 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
T_1 V_79 = F_7 ( V_11 , V_80 ) & 0x01c0 ;
T_1 V_99 = F_7 ( V_11 , V_100 ) & 0x01f3 ;
int V_101 ;
V_101 = F_15 ( V_13 -> V_59 , F_21 ( V_74 ) ) ;
if ( V_101 < 0 ) {
F_12 ( V_102 L_2 ) ;
return V_101 ;
}
F_8 ( V_11 , V_80 , V_79 | ( V_53 [ V_101 ] . V_103 << 1 ) |
V_53 [ V_101 ] . V_104 ) ;
switch ( F_20 ( V_74 ) ) {
case V_81 :
break;
case V_82 :
V_99 |= 0x0004 ;
break;
case V_83 :
V_99 |= 0x0008 ;
break;
case V_84 :
V_99 |= 0x000c ;
break;
}
F_8 ( V_11 , V_100 , V_99 ) ;
return 0 ;
}
static int F_27 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
T_1 clock ;
clock = F_7 ( V_11 , V_45 ) & 0xfffb ;
F_8 ( V_11 , V_45 , clock ) ;
return F_18 ( V_11 , V_62 ) ;
}
static int F_28 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
return F_24 ( V_11 , V_62 ) ;
}
static int F_29 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
T_1 clock ;
clock = F_7 ( V_11 , V_45 ) & 0xfffb ;
F_8 ( V_11 , V_45 , clock ) ;
return F_18 ( V_11 , V_62 ) ;
}
static int F_30 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
T_1 clock ;
clock = F_7 ( V_11 , V_45 ) & 0xfffb ;
F_8 ( V_11 , V_45 , clock | 0x4 ) ;
if ( F_24 ( V_11 , V_62 ) < 0 )
return - V_54 ;
return F_18 ( V_11 , V_62 ) ;
}
static int F_9 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_105 = 0 ;
switch ( V_13 -> V_15 ) {
case 0 :
V_105 = F_28 ( V_11 , V_62 ) ;
break;
case 1 :
V_105 = F_29 ( V_11 , V_62 ) ;
break;
case 2 :
case 3 :
V_105 = F_30 ( V_11 , V_62 ) ;
break;
default:
break;
}
if ( V_105 )
return V_105 ;
return F_25 ( V_11 , V_62 ) ;
}
static int F_31 ( struct V_35 * V_36 ,
unsigned int V_62 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
V_13 -> V_20 = V_62 ;
return F_9 ( V_11 , V_62 ) ;
}
static int F_10 ( struct V_10 * V_11 ,
unsigned int V_62 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_105 = 0 ;
if ( V_13 -> V_15 != 0 )
return 0 ;
V_105 = F_27 ( V_11 , V_62 ) ;
if ( V_105 )
return V_105 ;
V_105 = F_22 ( V_11 , V_62 ) ;
if ( V_105 )
return V_105 ;
return 0 ;
}
static int F_32 ( struct V_35 * V_36 ,
unsigned int V_62 )
{
struct V_10 * V_11 = V_36 -> V_11 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
V_13 -> V_21 = V_62 ;
return F_10 ( V_11 , V_62 ) ;
}
static int F_33 ( struct V_35 * V_75 , int V_106 )
{
struct V_10 * V_11 = V_75 -> V_11 ;
T_1 V_107 = F_7 ( V_11 , V_108 ) & 0xfff7 ;
struct V_12 * V_13 = F_5 ( V_11 ) ;
if ( V_106 && V_13 -> V_15 == 1 ) {
if ( ! V_11 -> V_17 )
F_8 ( V_11 , V_108 , V_107 | 0x8 ) ;
} else {
if ( V_106 )
F_8 ( V_11 , V_108 , V_107 | 0x8 ) ;
else
F_8 ( V_11 , V_108 , V_107 ) ;
}
return 0 ;
}
static int F_34 ( struct V_10 * V_11 ,
enum V_109 V_110 )
{
T_1 V_111 = F_7 ( V_11 , V_112 ) & 0xfe3e ;
switch ( V_110 ) {
case V_113 :
F_8 ( V_11 , V_112 , V_111 | 0x00c0 ) ;
break;
case V_114 :
F_8 ( V_11 , V_112 , V_111 | 0x01c1 ) ;
break;
case V_115 :
F_8 ( V_11 , V_112 , V_111 | 0x0141 ) ;
break;
case V_116 :
F_8 ( V_11 , V_112 , 0x0001 ) ;
break;
}
V_11 -> V_117 . V_118 = V_110 ;
return 0 ;
}
static void F_35 ( struct V_119 * V_120 )
{
struct V_121 * V_117 =
F_36 ( V_120 , struct V_121 ,
V_122 . V_120 ) ;
struct V_10 * V_11 = V_117 -> V_11 ;
F_34 ( V_11 , V_117 -> V_118 ) ;
}
static int F_37 ( struct V_10 * V_11 )
{
F_34 ( V_11 , V_116 ) ;
V_11 -> V_123 = 1 ;
return 0 ;
}
static int F_38 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
F_39 ( V_13 -> V_124 ) ;
F_34 ( V_11 , V_115 ) ;
if ( V_11 -> V_117 . V_125 == V_113 ) {
F_34 ( V_11 , V_114 ) ;
V_11 -> V_117 . V_118 = V_113 ;
F_40 ( & V_11 -> V_117 . V_122 ,
F_41 ( V_126 ) ) ;
}
return 0 ;
}
static int F_42 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_5 ( V_11 ) ;
int V_105 ;
F_43 ( & V_11 -> V_117 . V_122 , F_35 ) ;
V_11 -> V_127 = V_13 -> V_124 ;
V_105 = F_44 ( V_11 , 7 , 9 , V_128 ) ;
if ( V_105 < 0 ) {
F_45 ( V_11 -> V_2 , L_3 , V_105 ) ;
return V_105 ;
}
V_105 = F_46 ( V_11 ) ;
if ( V_105 < 0 ) {
F_45 ( V_11 -> V_2 , L_4 , V_105 ) ;
return V_105 ;
}
F_34 ( V_11 , V_115 ) ;
V_13 -> V_15 = 0 ;
F_34 ( V_11 , V_114 ) ;
F_40 ( & V_11 -> V_117 . V_122 ,
F_41 ( V_126 ) ) ;
F_47 ( V_11 , V_129 , 0x0100 , 0x0100 ) ;
F_47 ( V_11 , V_130 , 0x0100 , 0x0100 ) ;
F_47 ( V_11 , V_131 , 0x0100 , 0x0100 ) ;
F_47 ( V_11 , V_132 , 0x0100 , 0x0100 ) ;
F_47 ( V_11 , V_133 , 0x0100 , 0x0100 ) ;
F_47 ( V_11 , V_134 , 0x0100 , 0x0100 ) ;
F_47 ( V_11 , V_135 , 0x0100 , 0x0100 ) ;
F_47 ( V_11 , V_136 , 0x0100 , 0x0100 ) ;
F_47 ( V_11 , V_137 , 0x0100 , 0x0100 ) ;
F_47 ( V_11 , V_138 , 0x0100 , 0x0100 ) ;
return 0 ;
}
static int F_48 ( struct V_10 * V_11 )
{
F_49 ( & V_11 -> V_117 . V_122 ) ;
F_34 ( V_11 , V_116 ) ;
return 0 ;
}
static int T_3 F_50 ( struct V_139 * V_140 )
{
struct V_12 * V_13 ;
int V_105 ;
V_13 = F_51 ( & V_140 -> V_2 , sizeof( struct V_12 ) ,
V_141 ) ;
if ( V_13 == NULL )
return - V_142 ;
F_52 ( V_140 , V_13 ) ;
V_13 -> V_124 = F_53 ( V_140 , & V_143 ) ;
if ( F_54 ( V_13 -> V_124 ) ) {
V_105 = F_55 ( V_13 -> V_124 ) ;
F_45 ( & V_140 -> V_2 , L_5 ,
V_105 ) ;
goto V_144;
}
V_105 = F_56 ( & V_140 -> V_2 , & V_145 ,
V_146 , F_16 ( V_146 ) ) ;
if ( V_105 != 0 ) {
F_45 ( & V_140 -> V_2 , L_6 , V_105 ) ;
goto V_147;
}
return 0 ;
V_147:
F_57 ( V_13 -> V_124 ) ;
V_144:
return V_105 ;
}
static int T_4 F_58 ( struct V_139 * V_140 )
{
struct V_12 * V_13 = F_59 ( V_140 ) ;
F_60 ( & V_140 -> V_2 ) ;
F_57 ( V_13 -> V_124 ) ;
F_61 ( V_13 ) ;
return 0 ;
}
static T_3 int F_62 ( struct V_148 * V_149 ,
const struct V_150 * V_151 )
{
struct V_12 * V_13 ;
int V_105 ;
V_13 = F_51 ( & V_149 -> V_2 , sizeof( struct V_12 ) ,
V_141 ) ;
if ( V_13 == NULL )
return - V_142 ;
F_63 ( V_149 , V_13 ) ;
V_13 -> V_124 = F_64 ( V_149 , & V_143 ) ;
if ( F_54 ( V_13 -> V_124 ) ) {
V_105 = F_55 ( V_13 -> V_124 ) ;
F_45 ( & V_149 -> V_2 , L_5 ,
V_105 ) ;
goto V_144;
}
V_105 = F_56 ( & V_149 -> V_2 , & V_145 ,
V_146 , F_16 ( V_146 ) ) ;
if ( V_105 != 0 ) {
F_45 ( & V_149 -> V_2 , L_6 , V_105 ) ;
goto V_147;
}
return 0 ;
V_147:
F_57 ( V_13 -> V_124 ) ;
V_144:
return V_105 ;
}
static T_4 int F_65 ( struct V_148 * V_152 )
{
struct V_12 * V_13 = F_66 ( V_152 ) ;
F_60 ( & V_152 -> V_2 ) ;
F_57 ( V_13 -> V_124 ) ;
return 0 ;
}
static int T_5 F_67 ( void )
{
int V_105 = 0 ;
#if F_68 ( V_153 ) || F_68 ( V_154 )
V_105 = F_69 ( & V_155 ) ;
if ( V_105 != 0 ) {
F_12 ( V_102 L_7 ,
V_105 ) ;
}
#endif
#if F_68 ( V_156 )
V_105 = F_70 ( & V_157 ) ;
if ( V_105 != 0 ) {
F_12 ( V_102 L_8 ,
V_105 ) ;
}
#endif
return V_105 ;
}
static void T_6 F_71 ( void )
{
#if F_68 ( V_153 ) || F_68 ( V_154 )
F_72 ( & V_155 ) ;
#endif
#if F_68 ( V_156 )
F_73 ( & V_157 ) ;
#endif
}
