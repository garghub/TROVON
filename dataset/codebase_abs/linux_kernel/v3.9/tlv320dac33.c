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
F_26 ( V_9 -> V_51 , V_46 -> V_2 ) ;
F_27 ( V_9 -> V_51 , V_46 -> V_2 ) ;
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
static int F_31 ( struct V_1 * V_2 ,
enum V_60 V_61 )
{
int V_11 ;
switch ( V_61 ) {
case V_62 :
break;
case V_63 :
break;
case V_64 :
if ( V_2 -> V_65 . V_66 == V_67 ) {
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 != 0 )
return V_11 ;
F_12 ( V_2 ) ;
}
break;
case V_67 :
if ( V_2 -> V_65 . V_66 == V_67 )
return 0 ;
V_11 = F_18 ( V_2 , 0 ) ;
if ( V_11 != 0 )
return V_11 ;
break;
}
V_2 -> V_65 . V_66 = V_61 ;
return 0 ;
}
static inline void F_32 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_68 ;
unsigned long V_69 ;
switch ( V_9 -> V_55 ) {
case V_70 :
F_11 ( V_2 , V_71 ,
F_33 ( V_9 -> V_72 ) ) ;
F_34 ( & V_9 -> V_73 , V_69 ) ;
V_9 -> V_74 = F_35 ( F_36 () ) ;
V_9 -> V_75 = V_9 -> V_74 ;
F_37 ( & V_9 -> V_73 , V_69 ) ;
F_11 ( V_2 , V_76 ,
F_33 ( V_9 -> V_77 ) ) ;
V_68 = F_38 ( V_9 -> V_78 ,
V_9 -> V_77 ) + 1000 ;
F_39 ( V_68 , V_68 + 500 ) ;
F_7 ( V_2 , V_79 , V_80 ) ;
break;
case V_81 :
F_34 ( & V_9 -> V_73 , V_69 ) ;
V_9 -> V_75 = F_35 ( F_36 () ) ;
V_9 -> V_75 -= V_9 -> V_82 ;
F_37 ( & V_9 -> V_73 , V_69 ) ;
F_11 ( V_2 , V_76 ,
F_33 ( V_83 ) ) ;
F_7 ( V_2 , V_79 , V_84 ) ;
break;
default:
F_40 ( V_2 -> V_14 , L_8 ,
V_9 -> V_55 ) ;
break;
}
}
static inline void F_41 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_69 ;
switch ( V_9 -> V_55 ) {
case V_70 :
F_34 ( & V_9 -> V_73 , V_69 ) ;
V_9 -> V_74 = F_35 ( F_36 () ) ;
F_37 ( & V_9 -> V_73 , V_69 ) ;
F_11 ( V_2 , V_71 ,
F_33 ( V_9 -> V_72 ) ) ;
break;
case V_81 :
break;
default:
F_40 ( V_2 -> V_14 , L_8 ,
V_9 -> V_55 ) ;
break;
}
}
static void F_42 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
T_1 V_3 ;
V_9 = F_43 ( V_86 , struct V_8 , V_86 ) ;
V_2 = V_9 -> V_2 ;
F_9 ( & V_9 -> V_17 ) ;
switch ( V_9 -> V_87 ) {
case V_88 :
V_9 -> V_87 = V_89 ;
F_32 ( V_9 ) ;
break;
case V_89 :
F_41 ( V_9 ) ;
break;
case V_90 :
break;
case V_91 :
V_9 -> V_87 = V_90 ;
F_7 ( V_2 , V_79 , 0 ) ;
V_3 = F_1 ( V_2 , V_92 ) ;
V_3 |= V_93 ;
F_7 ( V_2 , V_92 , V_3 ) ;
break;
}
F_10 ( & V_9 -> V_17 ) ;
}
static T_2 F_44 ( int V_94 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned long V_69 ;
F_34 ( & V_9 -> V_73 , V_69 ) ;
V_9 -> V_75 = F_35 ( F_36 () ) ;
F_37 ( & V_9 -> V_73 , V_69 ) ;
if ( V_9 -> V_55 != V_81 )
F_45 ( V_9 -> V_95 , & V_9 -> V_86 ) ;
return V_96 ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_97 = 60 ;
T_1 V_3 ;
do {
F_39 ( 1000 , 2000 ) ;
F_3 ( V_2 , V_98 , & V_3 ) ;
} while ( ( ( V_3 & 0x03 ) != V_99 ) && V_97 -- );
if ( ( V_3 & 0x03 ) != V_99 )
F_6 ( V_2 -> V_14 ,
L_9 ) ;
}
static int F_47 ( struct V_100 * V_51 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_51 = V_51 ;
return 0 ;
}
static void F_48 ( struct V_100 * V_51 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_51 = NULL ;
}
static int F_49 ( struct V_100 * V_51 ,
struct V_103 * V_104 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
switch ( F_50 ( V_104 ) ) {
case 44100 :
case 48000 :
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
F_50 ( V_104 ) ) ;
return - V_59 ;
}
switch ( F_51 ( V_104 ) ) {
case V_105 :
V_9 -> V_106 = V_107 ;
V_9 -> V_78 = F_52 ( V_9 -> V_108 , 32 ) ;
break;
case V_109 :
V_9 -> V_106 = V_110 ;
V_9 -> V_78 = F_52 ( V_9 -> V_108 , 64 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_11 ,
F_51 ( V_104 ) ) ;
return - V_59 ;
}
return 0 ;
}
static int F_27 ( struct V_100 * V_51 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_111 , V_112 , V_113 , V_114 ;
T_1 V_115 , V_116 , V_117 ;
switch ( V_51 -> V_118 -> V_119 ) {
case 44100 :
case 48000 :
V_111 = F_53 ( V_51 -> V_118 -> V_119 , V_9 -> V_120 ) ;
V_112 = F_54 ( V_51 -> V_118 -> V_119 ,
V_9 -> V_120 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
V_51 -> V_118 -> V_119 ) ;
return - V_59 ;
}
V_115 = F_1 ( V_2 , V_121 ) ;
V_115 &= ~ ( V_122 | V_123 ) ;
V_117 = F_1 ( V_2 , V_92 ) ;
V_117 &= ~ V_93 ;
V_117 &= ~ V_124 ;
switch ( V_51 -> V_118 -> V_125 ) {
case V_105 :
V_115 |= ( V_126 | V_127 ) ;
V_117 |= V_124 ;
break;
case V_109 :
V_115 |= ( V_128 | V_129 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_11 ,
V_51 -> V_118 -> V_125 ) ;
return - V_59 ;
}
F_9 ( & V_9 -> V_17 ) ;
if ( ! V_9 -> V_12 ) {
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
F_16 ( V_2 , 0 ) ;
F_16 ( V_2 , 1 ) ;
V_114 = F_1 ( V_2 , V_130 ) ;
F_7 ( V_2 , V_130 , V_114 ) ;
F_11 ( V_2 , V_131 , V_111 ) ;
F_7 ( V_2 , V_132 , 96 ) ;
F_7 ( V_2 , V_133 , F_55 ( 2 ) |
F_56 ( 1 ) ) ;
F_7 ( V_2 , V_134 , F_57 ( 4 ) ) ;
V_113 = F_1 ( V_2 , V_36 ) ;
V_113 |= V_38 | V_39 | V_40 ;
F_7 ( V_2 , V_36 , V_113 ) ;
F_46 ( V_2 ) ;
if ( V_9 -> V_55 ) {
F_7 ( V_2 , V_135 , F_58 ( 1 ) ) ;
F_7 ( V_2 , V_136 , 1 ) ;
F_11 ( V_2 , V_137 , V_112 ) ;
F_7 ( V_2 , V_138 , V_139 ) ;
} else {
F_7 ( V_2 , V_135 , V_140 ) ;
F_7 ( V_2 , V_136 , 0 ) ;
}
switch ( V_9 -> V_55 ) {
case V_70 :
F_7 ( V_2 , V_141 ,
F_59 ( V_142 ) ) ;
break;
case V_81 :
F_7 ( V_2 , V_143 ,
F_60 ( V_142 ) ) ;
break;
default:
break;
}
V_116 = F_1 ( V_2 , V_41 ) ;
switch ( V_9 -> V_55 ) {
case V_70 :
V_117 &= ~ V_144 ;
V_117 &= ~ V_145 ;
if ( V_9 -> V_146 )
V_116 |= V_42 ;
else
V_116 &= ~ V_42 ;
break;
case V_81 :
V_117 &= ~ V_144 ;
V_117 |= V_145 ;
if ( V_9 -> V_146 )
V_116 |= V_42 ;
else
V_116 &= ~ V_42 ;
break;
default:
V_117 |= V_144 ;
V_116 |= V_42 ;
break;
}
F_7 ( V_2 , V_92 , V_117 ) ;
F_7 ( V_2 , V_121 , V_115 ) ;
F_7 ( V_2 , V_41 , V_116 ) ;
if ( V_9 -> V_55 )
F_7 ( V_2 , V_147 ,
V_9 -> V_108 ) ;
else
if ( V_51 -> V_118 -> V_125 == V_105 )
F_7 ( V_2 , V_147 , 32 ) ;
else
F_7 ( V_2 , V_147 , 16 ) ;
switch ( V_9 -> V_55 ) {
case V_70 :
F_11 ( V_2 , V_148 ,
F_33 ( V_9 -> V_77 ) ) ;
break;
case V_81 :
F_11 ( V_2 , V_149 , F_33 ( V_9 -> V_150 ) ) ;
F_11 ( V_2 , V_151 ,
F_33 ( V_83 ) ) ;
break;
default:
break;
}
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
static void F_26 ( struct V_100 * V_51 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_152 = V_51 -> V_118 -> V_152 ;
unsigned int V_119 = V_51 -> V_118 -> V_119 ;
unsigned int V_153 ;
if ( ! V_9 -> V_55 )
return;
switch ( V_9 -> V_55 ) {
case V_70 :
V_9 -> V_77 = F_61 ( V_119 ,
V_9 -> V_154 ) ;
V_153 = V_9 -> V_106 - V_9 -> V_77 ;
if ( V_152 <= V_9 -> V_77 )
V_9 -> V_72 = V_152 *
( ( V_9 -> V_77 / V_152 ) +
( V_9 -> V_77 % V_152 ?
1 : 0 ) ) ;
else if ( V_152 > V_153 )
V_9 -> V_72 = V_153 ;
else
V_9 -> V_72 = V_152 ;
V_9 -> V_155 = F_38 ( V_9 -> V_78 ,
V_9 -> V_72 ) ;
V_9 -> V_75 = 0 ;
V_9 -> V_74 = 0 ;
break;
case V_81 :
V_9 -> V_150 = F_62 ( V_152 , V_119 ,
V_9 -> V_78 ) + 9 ;
if ( V_9 -> V_150 > ( V_9 -> V_106 - V_83 ) )
V_9 -> V_150 = V_9 -> V_106 - V_83 ;
if ( V_9 -> V_150 < ( V_83 + 10 ) )
V_9 -> V_150 = ( V_83 + 10 ) ;
V_9 -> V_82 =
F_38 ( V_51 -> V_118 -> V_119 ,
V_9 -> V_150 - V_83 + 1 ) ;
V_9 -> V_75 = 0 ;
break;
default:
break;
}
}
static int F_63 ( struct V_100 * V_51 , int V_156 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
switch ( V_156 ) {
case V_157 :
case V_158 :
case V_159 :
if ( V_9 -> V_55 ) {
V_9 -> V_87 = V_88 ;
F_45 ( V_9 -> V_95 , & V_9 -> V_86 ) ;
}
break;
case V_160 :
case V_161 :
case V_162 :
if ( V_9 -> V_55 ) {
V_9 -> V_87 = V_91 ;
F_45 ( V_9 -> V_95 , & V_9 -> V_86 ) ;
}
break;
default:
V_11 = - V_59 ;
}
return V_11 ;
}
static T_3 F_64 (
struct V_100 * V_51 ,
struct V_101 * V_102 )
{
struct V_1 * V_2 = V_102 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned long long V_163 , V_164 , V_165 ;
unsigned int V_166 , V_150 ;
int V_167 , V_168 , V_169 ;
T_3 V_68 = 0 ;
unsigned long V_69 ;
switch ( V_9 -> V_55 ) {
case V_170 :
break;
case V_70 :
F_34 ( & V_9 -> V_73 , V_69 ) ;
V_163 = V_9 -> V_75 ;
V_164 = V_9 -> V_74 ;
F_37 ( & V_9 -> V_73 , V_69 ) ;
V_165 = F_35 ( F_36 () ) ;
if ( ! V_164 )
goto V_171;
if ( V_163 > V_164 ) {
V_166 = V_165 - V_163 ;
V_167 = V_166 ? F_61 (
V_51 -> V_118 -> V_119 ,
V_166 ) : 0 ;
if ( F_25 ( V_9 -> V_77 > V_167 ) )
V_68 = V_9 -> V_77 - V_167 ;
else
V_68 = 0 ;
} else if ( ( V_165 - V_164 ) <= V_9 -> V_155 ) {
V_166 = V_165 - V_163 ;
V_167 = V_166 ? F_61 (
V_51 -> V_118 -> V_119 ,
V_166 ) : 0 ;
V_166 = V_165 - V_164 ;
V_168 = V_166 ? F_61 (
V_9 -> V_78 ,
V_166 ) : 0 ;
V_169 = V_9 -> V_77 ;
V_169 += ( V_168 - V_167 ) ;
if ( F_25 ( V_169 > 0 ) )
V_68 = V_169 ;
else
V_68 = 0 ;
} else {
V_166 = V_165 - V_163 ;
V_167 = V_166 ? F_61 (
V_51 -> V_118 -> V_119 ,
V_166 ) : 0 ;
V_168 = V_9 -> V_72 ;
V_169 = V_9 -> V_77 ;
V_169 += ( V_168 - V_167 ) ;
if ( F_25 ( V_169 > 0 ) )
V_68 = V_169 > V_9 -> V_106 ?
V_9 -> V_106 : V_169 ;
else
V_68 = 0 ;
}
break;
case V_81 :
F_34 ( & V_9 -> V_73 , V_69 ) ;
V_163 = V_9 -> V_75 ;
V_150 = V_9 -> V_150 ;
F_37 ( & V_9 -> V_73 , V_69 ) ;
V_165 = F_35 ( F_36 () ) ;
if ( ! V_163 )
goto V_171;
if ( V_165 <= V_163 ) {
V_68 = V_150 ;
goto V_171;
}
V_166 = V_165 - V_163 ;
if ( V_166 <= V_9 -> V_82 ) {
V_167 = F_61 (
V_51 -> V_118 -> V_119 ,
V_166 ) ;
if ( F_25 ( V_150 > V_167 ) )
V_68 = V_150 - V_167 ;
else
V_68 = 0 ;
} else {
V_166 = V_166 - V_9 -> V_82 ;
V_167 = F_61 (
V_51 -> V_118 -> V_119 ,
V_166 ) ;
V_168 = F_61 (
V_9 -> V_78 ,
V_166 ) ;
V_68 = V_83 + V_168 - V_167 ;
if ( F_13 ( V_68 > V_150 ) )
V_68 = V_150 ;
}
break;
default:
F_40 ( V_2 -> V_14 , L_8 ,
V_9 -> V_55 ) ;
break;
}
V_171:
return V_68 ;
}
static int F_65 ( struct V_101 * V_172 ,
int V_173 , unsigned int V_174 , int V_175 )
{
struct V_1 * V_2 = V_172 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_176 , V_177 ;
V_176 = F_1 ( V_2 , V_130 ) ;
V_177 = F_1 ( V_2 , V_136 ) ;
switch ( V_173 ) {
case V_178 :
V_176 |= V_179 ;
V_177 |= V_180 ;
break;
case V_181 :
V_176 &= ~ V_179 ;
V_177 &= ~ V_180 ;
break;
default:
F_6 ( V_2 -> V_14 , L_12 , V_173 ) ;
break;
}
V_9 -> V_120 = V_174 ;
F_2 ( V_2 , V_130 , V_176 ) ;
F_2 ( V_2 , V_136 , V_177 ) ;
return 0 ;
}
static int F_66 ( struct V_101 * V_172 ,
unsigned int V_182 )
{
struct V_1 * V_2 = V_172 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_115 , V_116 ;
V_115 = F_1 ( V_2 , V_121 ) ;
V_116 = F_1 ( V_2 , V_41 ) ;
switch ( V_182 & V_183 ) {
case V_184 :
V_115 |= ( V_185 | V_186 ) ;
break;
case V_187 :
if ( V_9 -> V_55 ) {
F_6 ( V_2 -> V_14 , L_13 ) ;
return - V_59 ;
} else
V_115 &= ~ ( V_185 | V_186 ) ;
break;
default:
return - V_59 ;
}
V_115 &= ~ V_188 ;
switch ( V_182 & V_189 ) {
case V_190 :
V_115 |= V_191 ;
break;
case V_192 :
V_115 |= V_193 ;
V_116 &= ~ V_194 ;
V_116 |= F_67 ( 0 ) ;
break;
case V_195 :
V_115 |= V_196 ;
break;
case V_197 :
V_115 |= V_198 ;
break;
default:
F_6 ( V_2 -> V_14 , L_14 ,
V_182 & V_189 ) ;
return - V_59 ;
}
F_2 ( V_2 , V_121 , V_115 ) ;
F_2 ( V_2 , V_41 , V_116 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_16 = ( V_199 ) V_200 ;
V_9 -> V_2 = V_2 ;
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 -> V_14 , L_15 , V_11 ) ;
goto V_201;
}
V_11 = F_15 ( V_2 ) ;
F_18 ( V_2 , 0 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_16 , V_11 ) ;
V_11 = - V_202 ;
goto V_201;
}
if ( V_9 -> V_94 >= 0 ) {
V_11 = F_69 ( V_9 -> V_94 , F_44 ,
V_203 ,
V_2 -> V_204 , V_2 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_17 ,
V_9 -> V_94 , V_11 ) ;
V_9 -> V_94 = - 1 ;
}
if ( V_9 -> V_94 != - 1 ) {
V_9 -> V_95 =
F_70 ( L_18 ) ;
if ( V_9 -> V_95 == NULL ) {
F_71 ( V_9 -> V_94 , V_2 ) ;
return - V_205 ;
}
F_72 ( & V_9 -> V_86 , F_42 ) ;
}
}
if ( V_9 -> V_94 >= 0 )
F_73 ( V_2 , V_206 ,
F_21 ( V_206 ) ) ;
V_201:
return V_11 ;
}
static int F_74 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
F_31 ( V_2 , V_67 ) ;
if ( V_9 -> V_94 >= 0 ) {
F_71 ( V_9 -> V_94 , V_9 -> V_2 ) ;
F_75 ( V_9 -> V_95 ) ;
}
return 0 ;
}
static int F_76 ( struct V_207 * V_208 ,
const struct V_209 * V_210 )
{
struct V_211 * V_212 ;
struct V_8 * V_9 ;
int V_11 , V_33 ;
if ( V_208 -> V_14 . V_213 == NULL ) {
F_6 ( & V_208 -> V_14 , L_19 ) ;
return - V_202 ;
}
V_212 = V_208 -> V_14 . V_213 ;
V_9 = F_77 ( & V_208 -> V_14 , sizeof( struct V_8 ) ,
V_214 ) ;
if ( V_9 == NULL )
return - V_205 ;
V_9 -> V_13 = V_208 ;
F_78 ( & V_9 -> V_17 ) ;
F_79 ( & V_9 -> V_73 ) ;
F_80 ( V_208 , V_9 ) ;
V_9 -> V_44 = V_212 -> V_44 ;
V_9 -> V_108 = V_212 -> V_108 ;
V_9 -> V_146 = V_212 -> V_146 ;
V_9 -> V_154 = V_212 -> V_154 ;
if ( ! V_9 -> V_154 )
V_9 -> V_154 = 10000 ;
V_9 -> V_94 = V_208 -> V_94 ;
V_9 -> V_55 = V_170 ;
if ( V_9 -> V_44 >= 0 ) {
V_11 = F_81 ( V_9 -> V_44 , L_20 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_208 -> V_14 ,
L_21 ,
V_9 -> V_44 ) ;
goto V_215;
}
F_82 ( V_9 -> V_44 , 0 ) ;
}
for ( V_33 = 0 ; V_33 < F_21 ( V_9 -> V_43 ) ; V_33 ++ )
V_9 -> V_43 [ V_33 ] . V_216 = V_217 [ V_33 ] ;
V_11 = F_83 ( & V_208 -> V_14 , F_21 ( V_9 -> V_43 ) ,
V_9 -> V_43 ) ;
if ( V_11 != 0 ) {
F_6 ( & V_208 -> V_14 , L_22 , V_11 ) ;
goto V_218;
}
V_11 = F_84 ( & V_208 -> V_14 ,
& V_219 , & V_220 , 1 ) ;
if ( V_11 < 0 )
goto V_221;
return V_11 ;
V_221:
F_85 ( F_21 ( V_9 -> V_43 ) , V_9 -> V_43 ) ;
V_218:
if ( V_9 -> V_44 >= 0 )
F_86 ( V_9 -> V_44 ) ;
V_215:
return V_11 ;
}
static int F_87 ( struct V_207 * V_208 )
{
struct V_8 * V_9 = F_88 ( V_208 ) ;
if ( F_13 ( V_9 -> V_12 ) )
F_18 ( V_9 -> V_2 , 0 ) ;
if ( V_9 -> V_44 >= 0 )
F_86 ( V_9 -> V_44 ) ;
F_85 ( F_21 ( V_9 -> V_43 ) , V_9 -> V_43 ) ;
F_89 ( & V_208 -> V_14 ) ;
return 0 ;
}
