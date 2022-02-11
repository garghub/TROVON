static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 , V_7 ;
if ( V_4 -> V_8 ) {
V_7 = 1 ;
for ( V_6 = 2 ; V_6 < F_3 ( V_9 ) ; V_6 ++ ) {
if ( abs ( V_9 [ V_6 ] - V_4 -> V_10 ) <
abs ( V_9 [ V_7 ] - V_4 -> V_10 ) )
V_7 = V_6 ;
}
V_5 = V_7 << 1 ;
} else {
V_5 = 0 ;
}
F_4 ( V_2 -> V_11 , L_1 , V_5 ) ;
return F_5 ( V_2 , V_12 ,
0x6 , V_5 ) ;
}
static int F_6 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_16 -> V_17 . V_18 . V_19 [ 0 ] = V_4 -> V_8 ;
return 0 ;
}
static int F_8 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_1 * V_2 = F_7 ( V_14 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_8 = V_16 -> V_17 . V_18 . V_19 [ 0 ] ;
if ( V_8 > 1 )
return - V_20 ;
V_4 -> V_8 = V_8 ;
return F_1 ( V_2 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_11 -> V_23 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_24 * V_25 = & V_2 -> V_25 ;
struct V_26 * V_27 ;
F_10 ( V_25 , V_28 ,
F_3 ( V_28 ) ) ;
F_11 ( V_25 , V_29 , F_3 ( V_29 ) ) ;
if ( V_22 && V_22 -> V_30 ) {
F_10 ( V_25 , V_31 ,
F_3 ( V_31 ) ) ;
F_11 ( V_25 , V_32 ,
F_3 ( V_32 ) ) ;
} else {
F_10 ( V_25 , V_33 ,
F_3 ( V_33 ) ) ;
F_11 ( V_25 , V_34 ,
F_3 ( V_34 ) ) ;
}
F_12 (w, &codec->card->widgets, list) {
if ( V_27 -> V_25 != & V_2 -> V_25 )
continue;
if ( strcmp ( V_27 -> V_35 , L_2 ) == 0 )
V_4 -> V_36 = V_27 ;
if ( strcmp ( V_27 -> V_35 , L_3 ) == 0 )
V_4 -> V_37 = V_27 ;
if ( strcmp ( V_27 -> V_35 , L_4 ) == 0 )
V_4 -> V_38 = V_27 ;
}
return 0 ;
}
static int F_13 ( struct V_39 * V_40 ,
unsigned int V_41 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_42 = 0 ;
switch ( V_41 & V_43 ) {
case V_44 :
V_42 |= 0x0040 ;
break;
case V_45 :
break;
default:
return - V_20 ;
}
switch ( V_41 & V_46 ) {
case V_47 :
V_42 |= 0x0002 ;
break;
case V_48 :
break;
case V_49 :
V_42 |= 0x0001 ;
break;
case V_50 :
V_42 |= 0x0003 ;
break;
case V_51 :
V_42 |= 0x0013 ;
break;
default:
return - V_20 ;
}
switch ( V_41 & V_52 ) {
case V_53 :
break;
case V_54 :
V_42 |= 0x0090 ;
break;
case V_55 :
V_42 |= 0x0080 ;
break;
case V_56 :
V_42 |= 0x0010 ;
break;
default:
return - V_20 ;
}
F_14 ( V_2 , V_57 , V_42 ) ;
return 0 ;
}
static int F_15 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_39 * V_62 )
{
struct V_63 * V_64 = V_59 -> V_65 ;
struct V_1 * V_2 = V_64 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_42 = F_16 ( V_2 , V_57 ) & 0xfff3 ;
int V_6 ;
switch ( F_17 ( V_61 ) ) {
case V_66 :
break;
case V_67 :
V_42 |= 0x0004 ;
break;
case V_68 :
V_42 |= 0x0008 ;
break;
}
if ( V_59 -> V_69 == V_70 ) {
V_4 -> V_10 = F_18 ( V_61 ) ;
F_1 ( V_2 ) ;
} else {
for ( V_6 = 0 ; V_6 < F_3 ( V_71 ) ; V_6 ++ )
if ( V_71 [ V_6 ] . V_72 == F_18 ( V_61 ) )
F_5 ( V_2 ,
V_73 , 0x7 ,
V_71 [ V_6 ] . V_5 ) ;
}
F_14 ( V_2 , V_57 , V_42 ) ;
return 0 ;
}
static int F_19 ( struct V_39 * V_62 , int V_74 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
T_1 V_75 = F_16 ( V_2 , V_12 ) & 0xfff7 ;
if ( V_74 )
F_14 ( V_2 , V_12 , V_75 | 0x8 ) ;
else
F_14 ( V_2 , V_12 , V_75 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_76 V_77 )
{
T_1 V_78 ;
switch ( V_77 ) {
case V_79 :
break;
case V_80 :
V_78 = F_16 ( V_2 , V_81 ) ;
V_78 &= ~ 0x180 ;
V_78 |= 0x80 ;
F_14 ( V_2 , V_81 , V_78 ) ;
break;
case V_82 :
if ( V_2 -> V_25 . V_83 == V_84 ) {
F_14 ( V_2 , V_85 ,
V_86 | V_87 |
V_88 | V_89 ) ;
V_78 = F_16 ( V_2 , V_81 ) ;
V_78 |= 0x80 ;
F_14 ( V_2 , V_81 , V_78 ) ;
F_21 ( 100 ) ;
F_14 ( V_2 , V_81 , V_78 | V_90 ) ;
F_14 ( V_2 , V_85 , V_89 ) ;
}
V_78 = F_16 ( V_2 , V_81 ) ;
V_78 &= ~ 0x180 ;
V_78 |= 0x100 ;
F_14 ( V_2 , V_81 , V_78 ) ;
break;
case V_84 :
F_14 ( V_2 , V_85 ,
V_86 | V_87 |
V_88 | V_89 ) ;
F_14 ( V_2 , V_81 , 0 ) ;
F_21 ( 600 ) ;
break;
}
V_2 -> V_25 . V_83 = V_77 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
enum V_76 V_77 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_78 ;
switch ( V_77 ) {
case V_79 :
break;
case V_80 :
switch ( V_2 -> V_25 . V_83 ) {
case V_82 :
F_5 ( V_2 , V_85 ,
V_86 | V_87 |
V_88 ,
V_86 | V_87 |
V_88 ) ;
V_78 = 0 ;
if ( V_4 -> V_36 && V_4 -> V_36 -> V_91 )
V_78 |= V_92 ;
if ( V_4 -> V_37 && V_4 -> V_37 -> V_91 )
V_78 |= V_93 ;
if ( V_4 -> V_38 && V_4 -> V_38 -> V_91 )
V_78 |= V_94 ;
F_5 ( V_2 , V_95 ,
V_92 |
V_93 |
V_94 , V_78 ) ;
F_5 ( V_2 , V_81 ,
V_96 , 0x80 ) ;
F_21 ( 100 ) ;
F_5 ( V_2 , V_81 ,
V_90 , V_90 ) ;
F_21 ( 100 ) ;
break;
case V_79 :
F_5 ( V_2 , V_85 ,
V_86 | V_87 |
V_88 ,
V_86 | V_87 |
V_88 ) ;
F_5 ( V_2 , V_81 ,
V_90 | V_96 , 0 ) ;
break;
default:
break;
}
break;
case V_82 :
switch ( V_2 -> V_25 . V_83 ) {
case V_80 :
F_5 ( V_2 , V_97 ,
V_98 | V_99 ,
0 ) ;
F_5 ( V_2 , V_85 ,
V_86 | V_87 |
V_88 ,
V_86 | V_87 |
V_88 ) ;
break;
default:
break;
}
break;
case V_84 :
break;
}
V_2 -> V_25 . V_83 = V_77 ;
return 0 ;
}
static int F_23 ( unsigned int V_100 , unsigned int V_101 ,
struct V_102 * V_103 )
{
unsigned long long V_104 ;
unsigned int V_105 , V_106 , V_107 ;
F_24 ( L_5 , V_100 , V_101 ) ;
V_101 *= 4 ;
V_106 = V_101 / V_100 ;
if ( V_106 < 6 ) {
V_100 >>= 1 ;
V_103 -> V_108 = 1 ;
V_106 = V_101 / V_100 ;
} else
V_103 -> V_108 = 0 ;
if ( ( V_106 < 6 ) || ( V_106 > 12 ) ) {
F_25 ( L_6 , V_106 ) ;
return - V_20 ;
}
V_103 -> V_109 = V_106 ;
V_107 = V_101 % V_100 ;
V_104 = V_110 * ( long long ) V_107 ;
F_26 ( V_104 , V_100 ) ;
V_105 = V_104 & 0xFFFFFFFF ;
if ( ( V_105 % 10 ) >= 5 )
V_105 += 5 ;
V_105 /= 10 ;
V_103 -> V_111 = V_105 ;
F_24 ( L_7 ,
V_103 -> V_109 , V_103 -> V_111 , V_103 -> V_108 ) ;
return 0 ;
}
static int F_27 ( struct V_39 * V_40 , int V_112 ,
int V_100 , unsigned int V_113 , unsigned int V_114 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_78 ;
static struct V_102 V_103 ;
int V_115 ;
if ( V_113 && V_114 ) {
V_115 = F_23 ( V_113 , V_114 , & V_103 ) ;
if ( V_115 != 0 )
return V_115 ;
}
F_14 ( V_2 , V_116 ,
F_16 ( V_2 , V_116 ) & ~ 1 ) ;
F_14 ( V_2 , V_95 ,
F_16 ( V_2 , V_95 ) & ~ 1 ) ;
if ( ! V_113 || ! V_114 )
return 0 ;
V_78 = F_16 ( V_2 , V_117 ) & ~ 0x3f ;
V_78 |= V_103 . V_108 << 4 ;
V_78 |= V_103 . V_109 ;
if ( V_103 . V_111 ) {
V_78 |= 0x20 ;
F_14 ( V_2 , V_118 , ( V_103 . V_111 >> 18 ) & 0x3f ) ;
F_14 ( V_2 , V_119 , ( V_103 . V_111 >> 9 ) & 0x1ff ) ;
F_14 ( V_2 , V_120 , V_103 . V_111 & 0x1ff ) ;
}
F_14 ( V_2 , V_117 , V_78 ) ;
F_14 ( V_2 , V_95 ,
F_16 ( V_2 , V_95 ) | 1 ) ;
F_21 ( 250 ) ;
F_14 ( V_2 , V_116 ,
F_16 ( V_2 , V_116 ) | 1 ) ;
return 0 ;
}
static int F_28 ( struct V_39 * V_40 ,
int V_121 , int div )
{
struct V_1 * V_2 = V_40 -> V_2 ;
T_1 V_78 ;
switch ( V_121 ) {
case V_122 :
V_78 = F_16 ( V_2 , V_116 ) & 0x1f9 ;
F_14 ( V_2 , V_116 , V_78 | div ) ;
break;
case V_123 :
V_78 = F_16 ( V_2 , V_116 ) & 0x1c7 ;
F_14 ( V_2 , V_116 , V_78 | div ) ;
break;
case V_124 :
V_78 = F_16 ( V_2 , V_117 ) & 0x03f ;
F_14 ( V_2 , V_117 , V_78 | div ) ;
break;
case V_125 :
V_78 = F_16 ( V_2 , V_126 ) & 0x03f ;
F_14 ( V_2 , V_126 , V_78 | div ) ;
break;
case V_127 :
V_78 = F_16 ( V_2 , V_128 ) & 0x1fd ;
F_14 ( V_2 , V_128 , V_78 | div ) ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
enum V_76 V_77 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_129 ( V_2 , V_77 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_2 V_130 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_129 ( V_2 , V_84 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_6 ;
T_3 V_131 [ 2 ] ;
T_1 * V_132 = V_2 -> V_133 ;
for ( V_6 = 0 ; V_6 < F_3 ( V_134 ) ; V_6 ++ ) {
V_131 [ 0 ] = ( V_6 << 1 ) | ( ( V_132 [ V_6 ] >> 8 ) & 0x0001 ) ;
V_131 [ 1 ] = V_132 [ V_6 ] & 0x00ff ;
V_2 -> V_135 ( V_2 -> V_136 , V_131 , 2 ) ;
}
V_4 -> V_129 ( V_2 , V_82 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_21 * V_22 = F_33 ( V_2 -> V_11 ) ;
int V_115 ;
T_1 V_78 ;
V_4 -> V_129 = F_20 ;
V_2 -> V_136 = V_4 -> V_136 ;
if ( ! V_22 ) {
F_34 ( V_2 -> V_11 , L_8 ) ;
} else {
if ( V_22 -> V_137 > V_138 ) {
F_35 ( V_2 -> V_11 , L_9 , V_22 -> V_137 ) ;
V_22 -> V_137 = 0 ;
}
if ( V_22 -> V_30 )
V_4 -> V_129 = F_22 ;
}
V_115 = F_36 ( V_2 , 7 , 9 , V_4 -> V_139 ) ;
if ( V_115 < 0 ) {
F_35 ( V_2 -> V_11 , L_10 , V_115 ) ;
return V_115 ;
}
V_115 = F_37 ( V_2 ) ;
if ( V_115 < 0 ) {
F_35 ( V_2 -> V_11 , L_11 ) ;
return V_115 ;
}
V_4 -> V_129 ( V_2 , V_82 ) ;
V_78 = F_16 ( V_2 , V_140 ) ;
F_14 ( V_2 , V_140 , V_78 | 0x100 ) ;
V_78 = F_16 ( V_2 , V_141 ) ;
F_14 ( V_2 , V_141 , V_78 | 0x100 ) ;
V_78 = F_16 ( V_2 , V_142 ) ;
F_14 ( V_2 , V_142 , V_78 | 0x100 ) ;
V_78 = F_16 ( V_2 , V_143 ) ;
F_14 ( V_2 , V_143 , V_78 | 0x100 ) ;
V_78 = F_16 ( V_2 , V_144 ) ;
F_14 ( V_2 , V_144 , V_78 | 0x100 ) ;
V_78 = F_16 ( V_2 , V_145 ) ;
F_14 ( V_2 , V_145 , V_78 | 0x100 ) ;
V_78 = F_16 ( V_2 , V_146 ) ;
F_14 ( V_2 , V_146 , V_78 | 0x100 ) ;
V_78 = F_16 ( V_2 , V_147 ) ;
F_14 ( V_2 , V_147 , V_78 | 0x100 ) ;
V_78 = F_16 ( V_2 , V_148 ) ;
F_14 ( V_2 , V_148 , V_78 | 0x100 ) ;
V_78 = F_16 ( V_2 , V_149 ) ;
F_14 ( V_2 , V_149 , V_78 | 0x100 ) ;
F_38 ( V_2 , V_150 ,
F_3 ( V_150 ) ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_129 ( V_2 , V_84 ) ;
return 0 ;
}
static T_4 int F_40 ( struct V_151 * V_152 ,
const struct V_153 * V_154 )
{
struct V_3 * V_4 ;
int V_115 ;
V_4 = F_41 ( sizeof( struct V_3 ) , V_155 ) ;
if ( V_4 == NULL )
return - V_156 ;
F_42 ( V_152 , V_4 ) ;
V_4 -> V_139 = V_157 ;
V_4 -> V_136 = V_152 ;
V_115 = F_43 ( & V_152 -> V_11 ,
& V_158 , & V_159 , 1 ) ;
if ( V_115 < 0 )
F_44 ( V_4 ) ;
return V_115 ;
}
static T_5 int F_45 ( struct V_151 * V_160 )
{
F_46 ( & V_160 -> V_11 ) ;
F_44 ( F_47 ( V_160 ) ) ;
return 0 ;
}
static int T_6 F_48 ( void )
{
int V_115 = 0 ;
#if F_49 ( V_161 ) || F_49 ( V_162 )
V_115 = F_50 ( & V_163 ) ;
if ( V_115 != 0 ) {
F_51 ( V_164 L_12 ,
V_115 ) ;
}
#endif
return V_115 ;
}
static void T_7 F_52 ( void )
{
#if F_49 ( V_161 ) || F_49 ( V_162 )
F_53 ( & V_163 ) ;
#endif
}
