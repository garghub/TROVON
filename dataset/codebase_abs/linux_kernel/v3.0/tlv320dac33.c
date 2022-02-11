static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return 0 ;
return V_4 [ V_3 ] ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_7 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return;
V_4 [ V_3 ] = V_7 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 * V_7 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_10 , V_11 = 0 ;
* V_7 = V_3 & 0xff ;
if ( V_9 -> V_12 ) {
V_10 = F_5 ( V_2 -> V_13 , V_7 [ 0 ] ) ;
if ( V_10 < 0 ) {
F_6 ( V_2 -> V_14 , L_1 , V_10 ) ;
V_7 [ 0 ] = F_1 ( V_2 , V_3 ) ;
V_11 = V_10 ;
} else {
V_7 [ 0 ] = V_10 ;
F_2 ( V_2 , V_3 , V_10 ) ;
}
} else {
V_7 [ 0 ] = F_1 ( V_2 , V_3 ) ;
}
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_15 [ 2 ] ;
int V_11 = 0 ;
V_15 [ 0 ] = V_3 & 0xff ;
V_15 [ 1 ] = V_7 & 0xff ;
F_2 ( V_2 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
if ( V_9 -> V_12 ) {
V_11 = V_2 -> V_16 ( V_2 -> V_13 , V_15 , 2 ) ;
if ( V_11 != 2 )
F_6 ( V_2 -> V_14 , L_2 , V_11 ) ;
else
V_11 = 0 ;
}
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 ;
F_9 ( & V_9 -> V_17 ) ;
V_11 = F_7 ( V_2 , V_3 , V_7 ) ;
F_10 ( & V_9 -> V_17 ) ;
return V_11 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_15 [ 3 ] ;
int V_11 = 0 ;
V_15 [ 0 ] = V_3 & 0xff ;
V_15 [ 1 ] = ( V_7 >> 8 ) & 0xff ;
V_15 [ 2 ] = V_7 & 0xff ;
F_2 ( V_2 , V_15 [ 0 ] , V_15 [ 1 ] ) ;
F_2 ( V_2 , V_15 [ 0 ] + 1 , V_15 [ 2 ] ) ;
if ( V_9 -> V_12 ) {
V_15 [ 0 ] |= V_18 ;
V_11 = V_2 -> V_16 ( V_2 -> V_13 , V_15 , 3 ) ;
if ( V_11 != 3 )
F_6 ( V_2 -> V_14 , L_2 , V_11 ) ;
else
V_11 = 0 ;
}
return V_11 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
if ( F_13 ( ! V_9 -> V_12 ) )
return;
F_7 ( V_2 , V_19 , F_14 ( 0 ) ) ;
F_7 ( V_2 , V_20 , V_21 |
V_22 ) ;
F_7 ( V_2 , V_23 , 0x00 ) ;
F_7 ( V_2 , V_24 , V_25 ) ;
F_7 ( V_2 , V_26 ,
F_1 ( V_2 , V_26 ) ) ;
F_7 ( V_2 , V_27 ,
F_1 ( V_2 , V_27 ) ) ;
F_7 ( V_2 , V_28 ,
F_1 ( V_2 , V_28 ) ) ;
F_7 ( V_2 , V_29 ,
F_1 ( V_2 , V_29 ) ) ;
F_7 ( V_2 , V_30 ,
F_1 ( V_2 , V_30 ) ) ;
F_7 ( V_2 , V_31 ,
F_1 ( V_2 , V_31 ) ) ;
F_7 ( V_2 , V_32 ,
F_1 ( V_2 , V_32 ) ) ;
}
static inline int F_15 ( struct V_1 * V_2 )
{
int V_33 , V_11 = 0 ;
T_1 V_3 ;
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ ) {
V_11 = F_3 ( V_2 , V_34 + V_33 , & V_3 ) ;
if ( V_11 < 0 )
break;
}
return V_11 ;
}
static inline void F_16 ( struct V_1 * V_2 , int V_35 )
{
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_36 ) ;
if ( V_35 )
V_3 |= V_37 ;
else
V_3 &= ~ ( V_37 | V_38 |
V_39 | V_40 ) ;
F_7 ( V_2 , V_36 , V_3 ) ;
}
static inline void F_17 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_1 ( V_2 , V_41 ) ;
V_3 &= ~ V_42 ;
F_7 ( V_2 , V_41 , V_3 ) ;
V_3 = F_1 ( V_2 , V_36 ) ;
V_3 &= ~ ( V_38 | V_39 | V_40 ) ;
F_7 ( V_2 , V_36 , V_3 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_35 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
F_9 ( & V_9 -> V_17 ) ;
if ( F_13 ( V_35 == V_9 -> V_12 ) ) {
F_19 ( V_2 -> V_14 , L_3 ,
V_35 ? L_4 : L_5 ) ;
goto exit;
}
if ( V_35 ) {
V_11 = F_20 ( F_21 ( V_9 -> V_43 ) ,
V_9 -> V_43 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 -> V_14 ,
L_6 , V_11 ) ;
goto exit;
}
if ( V_9 -> V_44 >= 0 )
F_22 ( V_9 -> V_44 , 1 ) ;
V_9 -> V_12 = 1 ;
} else {
F_16 ( V_2 , 0 ) ;
if ( V_9 -> V_44 >= 0 )
F_22 ( V_9 -> V_44 , 0 ) ;
V_11 = F_23 ( F_21 ( V_9 -> V_43 ) ,
V_9 -> V_43 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 -> V_14 ,
L_7 , V_11 ) ;
goto exit;
}
V_9 -> V_12 = 0 ;
}
exit:
F_10 ( & V_9 -> V_17 ) ;
return V_11 ;
}
static int F_24 ( struct V_45 * V_46 ,
struct V_47 * V_48 , int V_49 )
{
struct V_8 * V_9 = F_4 ( V_46 -> V_2 ) ;
switch ( V_49 ) {
case V_50 :
if ( F_25 ( V_9 -> V_51 ) ) {
F_26 ( V_9 -> V_51 ) ;
F_27 ( V_9 -> V_51 ) ;
}
break;
case V_52 :
F_17 ( V_46 -> V_2 ) ;
break;
}
return 0 ;
}
static int F_28 ( struct V_47 * V_48 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = F_29 ( V_48 ) ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_54 -> V_7 . integer . V_7 [ 0 ] = V_9 -> V_55 ;
return 0 ;
}
static int F_30 ( struct V_47 * V_48 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = F_29 ( V_48 ) ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
if ( V_9 -> V_55 == V_54 -> V_7 . integer . V_7 [ 0 ] )
return 0 ;
if ( V_2 -> V_56 )
return - V_57 ;
if ( V_54 -> V_7 . integer . V_7 [ 0 ] < 0 ||
V_54 -> V_7 . integer . V_7 [ 0 ] >= V_58 )
V_11 = - V_59 ;
else
V_9 -> V_55 = V_54 -> V_7 . integer . V_7 [ 0 ] ;
return V_11 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = & V_2 -> V_61 ;
F_32 ( V_61 , V_62 ,
F_21 ( V_62 ) ) ;
F_33 ( V_61 , V_63 , F_21 ( V_63 ) ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
enum V_64 V_65 )
{
int V_11 ;
switch ( V_65 ) {
case V_66 :
break;
case V_67 :
break;
case V_68 :
if ( V_2 -> V_61 . V_69 == V_70 ) {
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 != 0 )
return V_11 ;
F_12 ( V_2 ) ;
}
break;
case V_70 :
if ( V_2 -> V_61 . V_69 == V_70 )
return 0 ;
V_11 = F_18 ( V_2 , 0 ) ;
if ( V_11 != 0 )
return V_11 ;
break;
}
V_2 -> V_61 . V_69 = V_65 ;
return 0 ;
}
static inline void F_35 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_71 ;
unsigned long V_72 ;
switch ( V_9 -> V_55 ) {
case V_73 :
F_11 ( V_2 , V_74 ,
F_36 ( V_9 -> V_75 ) ) ;
F_37 ( & V_9 -> V_76 , V_72 ) ;
V_9 -> V_77 = F_38 ( F_39 () ) ;
V_9 -> V_78 = V_9 -> V_77 ;
F_40 ( & V_9 -> V_76 , V_72 ) ;
F_11 ( V_2 , V_79 ,
F_36 ( V_9 -> V_80 ) ) ;
V_71 = F_41 ( V_9 -> V_81 ,
V_9 -> V_80 ) + 1000 ;
F_42 ( V_71 , V_71 + 500 ) ;
F_7 ( V_2 , V_82 , V_83 ) ;
break;
case V_84 :
F_37 ( & V_9 -> V_76 , V_72 ) ;
V_9 -> V_78 = F_38 ( F_39 () ) ;
V_9 -> V_78 -= V_9 -> V_85 ;
F_40 ( & V_9 -> V_76 , V_72 ) ;
F_11 ( V_2 , V_79 ,
F_36 ( V_86 ) ) ;
F_7 ( V_2 , V_82 , V_87 ) ;
break;
default:
F_43 ( V_2 -> V_14 , L_8 ,
V_9 -> V_55 ) ;
break;
}
}
static inline void F_44 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_72 ;
switch ( V_9 -> V_55 ) {
case V_73 :
F_37 ( & V_9 -> V_76 , V_72 ) ;
V_9 -> V_77 = F_38 ( F_39 () ) ;
F_40 ( & V_9 -> V_76 , V_72 ) ;
F_11 ( V_2 , V_74 ,
F_36 ( V_9 -> V_75 ) ) ;
break;
case V_84 :
break;
default:
F_43 ( V_2 -> V_14 , L_8 ,
V_9 -> V_55 ) ;
break;
}
}
static void F_45 ( struct V_88 * V_89 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
T_1 V_3 ;
V_9 = F_46 ( V_89 , struct V_8 , V_89 ) ;
V_2 = V_9 -> V_2 ;
F_9 ( & V_9 -> V_17 ) ;
switch ( V_9 -> V_90 ) {
case V_91 :
V_9 -> V_90 = V_92 ;
F_35 ( V_9 ) ;
break;
case V_92 :
F_44 ( V_9 ) ;
break;
case V_93 :
break;
case V_94 :
V_9 -> V_90 = V_93 ;
F_7 ( V_2 , V_82 , 0 ) ;
V_3 = F_1 ( V_2 , V_95 ) ;
V_3 |= V_96 ;
F_7 ( V_2 , V_95 , V_3 ) ;
break;
}
F_10 ( & V_9 -> V_17 ) ;
}
static T_2 F_47 ( int V_97 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned long V_72 ;
F_37 ( & V_9 -> V_76 , V_72 ) ;
V_9 -> V_78 = F_38 ( F_39 () ) ;
F_40 ( & V_9 -> V_76 , V_72 ) ;
if ( V_9 -> V_55 != V_84 )
F_48 ( V_9 -> V_98 , & V_9 -> V_89 ) ;
return V_99 ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_100 = 60 ;
T_1 V_3 ;
do {
F_42 ( 1000 , 2000 ) ;
F_3 ( V_2 , V_101 , & V_3 ) ;
} while ( ( ( V_3 & 0x03 ) != V_102 ) && V_100 -- );
if ( ( V_3 & 0x03 ) != V_102 )
F_6 ( V_2 -> V_14 ,
L_9 ) ;
}
static int F_50 ( struct V_103 * V_51 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = V_51 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_51 = V_51 ;
F_51 ( V_51 -> V_109 , 0 , 32 , 24 ) ;
return 0 ;
}
static void F_52 ( struct V_103 * V_51 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = V_51 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_51 = NULL ;
}
static int F_53 ( struct V_103 * V_51 ,
struct V_110 * V_111 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = V_51 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
switch ( F_54 ( V_111 ) ) {
case 44100 :
case 48000 :
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
F_54 ( V_111 ) ) ;
return - V_59 ;
}
switch ( F_55 ( V_111 ) ) {
case V_112 :
V_9 -> V_113 = V_114 ;
V_9 -> V_81 = F_56 ( V_9 -> V_115 , 32 ) ;
break;
case V_116 :
V_9 -> V_113 = V_117 ;
V_9 -> V_81 = F_56 ( V_9 -> V_115 , 64 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_11 ,
F_55 ( V_111 ) ) ;
return - V_59 ;
}
return 0 ;
}
static int F_27 ( struct V_103 * V_51 )
{
struct V_106 * V_107 = V_51 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_118 , V_119 , V_120 , V_121 ;
T_1 V_122 , V_123 , V_124 ;
switch ( V_51 -> V_109 -> V_125 ) {
case 44100 :
case 48000 :
V_118 = F_57 ( V_51 -> V_109 -> V_125 , V_9 -> V_126 ) ;
V_119 = F_58 ( V_51 -> V_109 -> V_125 ,
V_9 -> V_126 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
V_51 -> V_109 -> V_125 ) ;
return - V_59 ;
}
V_122 = F_1 ( V_2 , V_127 ) ;
V_122 &= ~ ( V_128 | V_129 ) ;
V_124 = F_1 ( V_2 , V_95 ) ;
V_124 &= ~ V_96 ;
V_124 &= ~ V_130 ;
switch ( V_51 -> V_109 -> V_131 ) {
case V_112 :
V_122 |= ( V_132 | V_133 ) ;
V_124 |= V_130 ;
break;
case V_116 :
V_122 |= ( V_134 | V_135 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_11 ,
V_51 -> V_109 -> V_131 ) ;
return - V_59 ;
}
F_9 ( & V_9 -> V_17 ) ;
if ( ! V_9 -> V_12 ) {
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
F_16 ( V_2 , 0 ) ;
F_16 ( V_2 , 1 ) ;
V_121 = F_1 ( V_2 , V_136 ) ;
F_7 ( V_2 , V_136 , V_121 ) ;
F_11 ( V_2 , V_137 , V_118 ) ;
F_7 ( V_2 , V_138 , 96 ) ;
F_7 ( V_2 , V_139 , F_59 ( 2 ) |
F_60 ( 1 ) ) ;
F_7 ( V_2 , V_140 , F_61 ( 4 ) ) ;
V_120 = F_1 ( V_2 , V_36 ) ;
V_120 |= V_38 | V_39 | V_40 ;
F_7 ( V_2 , V_36 , V_120 ) ;
F_49 ( V_2 ) ;
if ( V_9 -> V_55 ) {
F_7 ( V_2 , V_141 , F_62 ( 1 ) ) ;
F_7 ( V_2 , V_142 , 1 ) ;
F_11 ( V_2 , V_143 , V_119 ) ;
F_7 ( V_2 , V_144 , V_145 ) ;
} else {
F_7 ( V_2 , V_141 , V_146 ) ;
F_7 ( V_2 , V_142 , 0 ) ;
}
switch ( V_9 -> V_55 ) {
case V_73 :
F_7 ( V_2 , V_147 ,
F_63 ( V_148 ) ) ;
break;
case V_84 :
F_7 ( V_2 , V_149 ,
F_64 ( V_148 ) ) ;
break;
default:
break;
}
V_123 = F_1 ( V_2 , V_41 ) ;
switch ( V_9 -> V_55 ) {
case V_73 :
V_124 &= ~ V_150 ;
V_124 &= ~ V_151 ;
if ( V_9 -> V_152 )
V_123 |= V_42 ;
else
V_123 &= ~ V_42 ;
break;
case V_84 :
V_124 &= ~ V_150 ;
V_124 |= V_151 ;
if ( V_9 -> V_152 )
V_123 |= V_42 ;
else
V_123 &= ~ V_42 ;
break;
default:
V_124 |= V_150 ;
V_123 |= V_42 ;
break;
}
F_7 ( V_2 , V_95 , V_124 ) ;
F_7 ( V_2 , V_127 , V_122 ) ;
F_7 ( V_2 , V_41 , V_123 ) ;
if ( V_9 -> V_55 )
F_7 ( V_2 , V_153 ,
V_9 -> V_115 ) ;
else
if ( V_51 -> V_109 -> V_131 == V_112 )
F_7 ( V_2 , V_153 , 32 ) ;
else
F_7 ( V_2 , V_153 , 16 ) ;
switch ( V_9 -> V_55 ) {
case V_73 :
F_11 ( V_2 , V_154 ,
F_36 ( V_9 -> V_80 ) ) ;
break;
case V_84 :
F_11 ( V_2 , V_155 , F_36 ( V_9 -> V_156 ) ) ;
F_11 ( V_2 , V_157 ,
F_36 ( V_86 ) ) ;
break;
default:
break;
}
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
static void F_26 ( struct V_103 * V_51 )
{
struct V_106 * V_107 = V_51 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_158 = V_51 -> V_109 -> V_158 ;
unsigned int V_125 = V_51 -> V_109 -> V_125 ;
unsigned int V_159 ;
if ( ! V_9 -> V_55 )
return;
switch ( V_9 -> V_55 ) {
case V_73 :
V_9 -> V_80 = F_65 ( V_125 ,
V_9 -> V_160 ) ;
V_159 = V_9 -> V_113 - V_9 -> V_80 ;
if ( V_158 <= V_9 -> V_80 )
V_9 -> V_75 = V_158 *
( ( V_9 -> V_80 / V_158 ) +
( V_9 -> V_80 % V_158 ?
1 : 0 ) ) ;
else if ( V_158 > V_159 )
V_9 -> V_75 = V_159 ;
else
V_9 -> V_75 = V_158 ;
V_9 -> V_161 = F_41 ( V_9 -> V_81 ,
V_9 -> V_75 ) ;
V_9 -> V_78 = 0 ;
V_9 -> V_77 = 0 ;
break;
case V_84 :
V_9 -> V_156 = F_66 ( V_158 , V_125 ,
V_9 -> V_81 ) + 9 ;
if ( V_9 -> V_156 > ( V_9 -> V_113 - V_86 ) )
V_9 -> V_156 = V_9 -> V_113 - V_86 ;
if ( V_9 -> V_156 < ( V_86 + 10 ) )
V_9 -> V_156 = ( V_86 + 10 ) ;
V_9 -> V_85 =
F_41 ( V_51 -> V_109 -> V_125 ,
V_9 -> V_156 - V_86 + 1 ) ;
V_9 -> V_78 = 0 ;
break;
default:
break;
}
}
static int F_67 ( struct V_103 * V_51 , int V_162 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = V_51 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
switch ( V_162 ) {
case V_163 :
case V_164 :
case V_165 :
if ( V_9 -> V_55 ) {
V_9 -> V_90 = V_91 ;
F_48 ( V_9 -> V_98 , & V_9 -> V_89 ) ;
}
break;
case V_166 :
case V_167 :
case V_168 :
if ( V_9 -> V_55 ) {
V_9 -> V_90 = V_94 ;
F_48 ( V_9 -> V_98 , & V_9 -> V_89 ) ;
}
break;
default:
V_11 = - V_59 ;
}
return V_11 ;
}
static T_3 F_68 (
struct V_103 * V_51 ,
struct V_104 * V_105 )
{
struct V_106 * V_107 = V_51 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned long long V_169 , V_170 , V_171 ;
unsigned int V_172 , V_156 ;
int V_173 , V_174 , V_175 ;
T_3 V_71 = 0 ;
unsigned long V_72 ;
switch ( V_9 -> V_55 ) {
case V_176 :
break;
case V_73 :
F_37 ( & V_9 -> V_76 , V_72 ) ;
V_169 = V_9 -> V_78 ;
V_170 = V_9 -> V_77 ;
F_40 ( & V_9 -> V_76 , V_72 ) ;
V_171 = F_38 ( F_39 () ) ;
if ( ! V_170 )
goto V_177;
if ( V_169 > V_170 ) {
V_172 = V_171 - V_169 ;
V_173 = V_172 ? F_65 (
V_51 -> V_109 -> V_125 ,
V_172 ) : 0 ;
if ( F_25 ( V_9 -> V_80 > V_173 ) )
V_71 = V_9 -> V_80 - V_173 ;
else
V_71 = 0 ;
} else if ( ( V_171 - V_170 ) <= V_9 -> V_161 ) {
V_172 = V_171 - V_169 ;
V_173 = V_172 ? F_65 (
V_51 -> V_109 -> V_125 ,
V_172 ) : 0 ;
V_172 = V_171 - V_170 ;
V_174 = V_172 ? F_65 (
V_9 -> V_81 ,
V_172 ) : 0 ;
V_175 = V_9 -> V_80 ;
V_175 += ( V_174 - V_173 ) ;
if ( F_25 ( V_175 > 0 ) )
V_71 = V_175 ;
else
V_71 = 0 ;
} else {
V_172 = V_171 - V_169 ;
V_173 = V_172 ? F_65 (
V_51 -> V_109 -> V_125 ,
V_172 ) : 0 ;
V_174 = V_9 -> V_75 ;
V_175 = V_9 -> V_80 ;
V_175 += ( V_174 - V_173 ) ;
if ( F_25 ( V_175 > 0 ) )
V_71 = V_175 > V_9 -> V_113 ?
V_9 -> V_113 : V_175 ;
else
V_71 = 0 ;
}
break;
case V_84 :
F_37 ( & V_9 -> V_76 , V_72 ) ;
V_169 = V_9 -> V_78 ;
V_156 = V_9 -> V_156 ;
F_40 ( & V_9 -> V_76 , V_72 ) ;
V_171 = F_38 ( F_39 () ) ;
if ( ! V_169 )
goto V_177;
if ( V_171 <= V_169 ) {
V_71 = V_156 ;
goto V_177;
}
V_172 = V_171 - V_169 ;
if ( V_172 <= V_9 -> V_85 ) {
V_173 = F_65 (
V_51 -> V_109 -> V_125 ,
V_172 ) ;
if ( F_25 ( V_156 > V_173 ) )
V_71 = V_156 - V_173 ;
else
V_71 = 0 ;
} else {
V_172 = V_172 - V_9 -> V_85 ;
V_173 = F_65 (
V_51 -> V_109 -> V_125 ,
V_172 ) ;
V_174 = F_65 (
V_9 -> V_81 ,
V_172 ) ;
V_71 = V_86 + V_174 - V_173 ;
if ( F_13 ( V_71 > V_156 ) )
V_71 = V_156 ;
}
break;
default:
F_43 ( V_2 -> V_14 , L_8 ,
V_9 -> V_55 ) ;
break;
}
V_177:
return V_71 ;
}
static int F_69 ( struct V_104 * V_178 ,
int V_179 , unsigned int V_180 , int V_181 )
{
struct V_1 * V_2 = V_178 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_182 , V_183 ;
V_182 = F_1 ( V_2 , V_136 ) ;
V_183 = F_1 ( V_2 , V_142 ) ;
switch ( V_179 ) {
case V_184 :
V_182 |= V_185 ;
V_183 |= V_186 ;
break;
case V_187 :
V_182 &= ~ V_185 ;
V_183 &= ~ V_186 ;
break;
default:
F_6 ( V_2 -> V_14 , L_12 , V_179 ) ;
break;
}
V_9 -> V_126 = V_180 ;
F_2 ( V_2 , V_136 , V_182 ) ;
F_2 ( V_2 , V_142 , V_183 ) ;
return 0 ;
}
static int F_70 ( struct V_104 * V_178 ,
unsigned int V_188 )
{
struct V_1 * V_2 = V_178 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_122 , V_123 ;
V_122 = F_1 ( V_2 , V_127 ) ;
V_123 = F_1 ( V_2 , V_41 ) ;
switch ( V_188 & V_189 ) {
case V_190 :
V_122 |= ( V_191 | V_192 ) ;
break;
case V_193 :
if ( V_9 -> V_55 ) {
F_6 ( V_2 -> V_14 , L_13 ) ;
return - V_59 ;
} else
V_122 &= ~ ( V_191 | V_192 ) ;
break;
default:
return - V_59 ;
}
V_122 &= ~ V_194 ;
switch ( V_188 & V_195 ) {
case V_196 :
V_122 |= V_197 ;
break;
case V_198 :
V_122 |= V_199 ;
V_123 &= ~ V_200 ;
V_123 |= F_71 ( 0 ) ;
break;
case V_201 :
V_122 |= V_202 ;
break;
case V_203 :
V_122 |= V_204 ;
break;
default:
F_6 ( V_2 -> V_14 , L_14 ,
V_188 & V_195 ) ;
return - V_59 ;
}
F_2 ( V_2 , V_127 , V_122 ) ;
F_2 ( V_2 , V_41 , V_123 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_16 = ( V_205 ) V_206 ;
V_2 -> V_61 . V_207 = 1 ;
V_9 -> V_2 = V_2 ;
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 -> V_14 , L_15 , V_11 ) ;
goto V_208;
}
V_11 = F_15 ( V_2 ) ;
F_18 ( V_2 , 0 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_16 , V_11 ) ;
V_11 = - V_209 ;
goto V_208;
}
if ( V_9 -> V_97 >= 0 ) {
V_11 = F_73 ( V_9 -> V_97 , F_47 ,
V_210 | V_211 ,
V_2 -> V_212 , V_2 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_17 ,
V_9 -> V_97 , V_11 ) ;
V_9 -> V_97 = - 1 ;
}
if ( V_9 -> V_97 != - 1 ) {
V_9 -> V_98 =
F_74 ( L_18 ) ;
if ( V_9 -> V_98 == NULL ) {
F_75 ( V_9 -> V_97 , V_2 ) ;
return - V_213 ;
}
F_76 ( & V_9 -> V_89 , F_45 ) ;
}
}
F_77 ( V_2 , V_214 ,
F_21 ( V_214 ) ) ;
if ( V_9 -> V_97 >= 0 )
F_77 ( V_2 , V_215 ,
F_21 ( V_215 ) ) ;
F_31 ( V_2 ) ;
V_208:
return V_11 ;
}
static int F_78 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
F_34 ( V_2 , V_70 ) ;
if ( V_9 -> V_97 >= 0 ) {
F_75 ( V_9 -> V_97 , V_9 -> V_2 ) ;
F_79 ( V_9 -> V_98 ) ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , T_4 V_90 )
{
F_34 ( V_2 , V_70 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
F_34 ( V_2 , V_68 ) ;
return 0 ;
}
static int T_5 F_82 ( struct V_216 * V_217 ,
const struct V_218 * V_219 )
{
struct V_220 * V_221 ;
struct V_8 * V_9 ;
int V_11 , V_33 ;
if ( V_217 -> V_14 . V_222 == NULL ) {
F_6 ( & V_217 -> V_14 , L_19 ) ;
return - V_209 ;
}
V_221 = V_217 -> V_14 . V_222 ;
V_9 = F_83 ( sizeof( struct V_8 ) , V_223 ) ;
if ( V_9 == NULL )
return - V_213 ;
V_9 -> V_13 = V_217 ;
F_84 ( & V_9 -> V_17 ) ;
F_85 ( & V_9 -> V_76 ) ;
F_86 ( V_217 , V_9 ) ;
V_9 -> V_44 = V_221 -> V_44 ;
V_9 -> V_115 = V_221 -> V_115 ;
V_9 -> V_152 = V_221 -> V_152 ;
V_9 -> V_160 = V_221 -> V_160 ;
if ( ! V_9 -> V_160 )
V_9 -> V_160 = 10000 ;
V_9 -> V_97 = V_217 -> V_97 ;
V_9 -> V_55 = V_176 ;
if ( V_9 -> V_44 >= 0 ) {
V_11 = F_87 ( V_9 -> V_44 , L_20 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_217 -> V_14 ,
L_21 ,
V_9 -> V_44 ) ;
goto V_224;
}
F_88 ( V_9 -> V_44 , 0 ) ;
}
for ( V_33 = 0 ; V_33 < F_21 ( V_9 -> V_43 ) ; V_33 ++ )
V_9 -> V_43 [ V_33 ] . V_225 = V_226 [ V_33 ] ;
V_11 = F_89 ( & V_217 -> V_14 , F_21 ( V_9 -> V_43 ) ,
V_9 -> V_43 ) ;
if ( V_11 != 0 ) {
F_6 ( & V_217 -> V_14 , L_22 , V_11 ) ;
goto V_227;
}
V_11 = F_90 ( & V_217 -> V_14 ,
& V_228 , & V_229 , 1 ) ;
if ( V_11 < 0 )
goto V_230;
return V_11 ;
V_230:
F_91 ( F_21 ( V_9 -> V_43 ) , V_9 -> V_43 ) ;
V_227:
if ( V_9 -> V_44 >= 0 )
F_92 ( V_9 -> V_44 ) ;
V_224:
F_93 ( V_9 ) ;
return V_11 ;
}
static int T_6 F_94 ( struct V_216 * V_217 )
{
struct V_8 * V_9 = F_95 ( V_217 ) ;
if ( F_13 ( V_9 -> V_12 ) )
F_18 ( V_9 -> V_2 , 0 ) ;
if ( V_9 -> V_44 >= 0 )
F_92 ( V_9 -> V_44 ) ;
F_91 ( F_21 ( V_9 -> V_43 ) , V_9 -> V_43 ) ;
F_96 ( & V_217 -> V_14 ) ;
F_93 ( V_9 ) ;
return 0 ;
}
static int T_7 F_97 ( void )
{
int V_231 ;
V_231 = F_98 ( & V_232 ) ;
if ( V_231 < 0 ) {
F_99 ( V_233 L_23 ) ;
return V_231 ;
}
return 0 ;
}
static void T_8 F_100 ( void )
{
F_101 ( & V_232 ) ;
}
