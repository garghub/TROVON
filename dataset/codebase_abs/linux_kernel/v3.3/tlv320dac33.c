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
struct V_103 * V_104 = V_51 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_51 = V_51 ;
F_48 ( V_51 -> V_106 , 0 , 32 , 24 ) ;
return 0 ;
}
static void F_49 ( struct V_100 * V_51 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 = V_51 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_51 = NULL ;
}
static int F_50 ( struct V_100 * V_51 ,
struct V_107 * V_108 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 = V_51 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
switch ( F_51 ( V_108 ) ) {
case 44100 :
case 48000 :
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
F_51 ( V_108 ) ) ;
return - V_59 ;
}
switch ( F_52 ( V_108 ) ) {
case V_109 :
V_9 -> V_110 = V_111 ;
V_9 -> V_78 = F_53 ( V_9 -> V_112 , 32 ) ;
break;
case V_113 :
V_9 -> V_110 = V_114 ;
V_9 -> V_78 = F_53 ( V_9 -> V_112 , 64 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_11 ,
F_52 ( V_108 ) ) ;
return - V_59 ;
}
return 0 ;
}
static int F_27 ( struct V_100 * V_51 )
{
struct V_103 * V_104 = V_51 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_115 , V_116 , V_117 , V_118 ;
T_1 V_119 , V_120 , V_121 ;
switch ( V_51 -> V_106 -> V_122 ) {
case 44100 :
case 48000 :
V_115 = F_54 ( V_51 -> V_106 -> V_122 , V_9 -> V_123 ) ;
V_116 = F_55 ( V_51 -> V_106 -> V_122 ,
V_9 -> V_123 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
V_51 -> V_106 -> V_122 ) ;
return - V_59 ;
}
V_119 = F_1 ( V_2 , V_124 ) ;
V_119 &= ~ ( V_125 | V_126 ) ;
V_121 = F_1 ( V_2 , V_92 ) ;
V_121 &= ~ V_93 ;
V_121 &= ~ V_127 ;
switch ( V_51 -> V_106 -> V_128 ) {
case V_109 :
V_119 |= ( V_129 | V_130 ) ;
V_121 |= V_127 ;
break;
case V_113 :
V_119 |= ( V_131 | V_132 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_11 ,
V_51 -> V_106 -> V_128 ) ;
return - V_59 ;
}
F_9 ( & V_9 -> V_17 ) ;
if ( ! V_9 -> V_12 ) {
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
F_16 ( V_2 , 0 ) ;
F_16 ( V_2 , 1 ) ;
V_118 = F_1 ( V_2 , V_133 ) ;
F_7 ( V_2 , V_133 , V_118 ) ;
F_11 ( V_2 , V_134 , V_115 ) ;
F_7 ( V_2 , V_135 , 96 ) ;
F_7 ( V_2 , V_136 , F_56 ( 2 ) |
F_57 ( 1 ) ) ;
F_7 ( V_2 , V_137 , F_58 ( 4 ) ) ;
V_117 = F_1 ( V_2 , V_36 ) ;
V_117 |= V_38 | V_39 | V_40 ;
F_7 ( V_2 , V_36 , V_117 ) ;
F_46 ( V_2 ) ;
if ( V_9 -> V_55 ) {
F_7 ( V_2 , V_138 , F_59 ( 1 ) ) ;
F_7 ( V_2 , V_139 , 1 ) ;
F_11 ( V_2 , V_140 , V_116 ) ;
F_7 ( V_2 , V_141 , V_142 ) ;
} else {
F_7 ( V_2 , V_138 , V_143 ) ;
F_7 ( V_2 , V_139 , 0 ) ;
}
switch ( V_9 -> V_55 ) {
case V_70 :
F_7 ( V_2 , V_144 ,
F_60 ( V_145 ) ) ;
break;
case V_81 :
F_7 ( V_2 , V_146 ,
F_61 ( V_145 ) ) ;
break;
default:
break;
}
V_120 = F_1 ( V_2 , V_41 ) ;
switch ( V_9 -> V_55 ) {
case V_70 :
V_121 &= ~ V_147 ;
V_121 &= ~ V_148 ;
if ( V_9 -> V_149 )
V_120 |= V_42 ;
else
V_120 &= ~ V_42 ;
break;
case V_81 :
V_121 &= ~ V_147 ;
V_121 |= V_148 ;
if ( V_9 -> V_149 )
V_120 |= V_42 ;
else
V_120 &= ~ V_42 ;
break;
default:
V_121 |= V_147 ;
V_120 |= V_42 ;
break;
}
F_7 ( V_2 , V_92 , V_121 ) ;
F_7 ( V_2 , V_124 , V_119 ) ;
F_7 ( V_2 , V_41 , V_120 ) ;
if ( V_9 -> V_55 )
F_7 ( V_2 , V_150 ,
V_9 -> V_112 ) ;
else
if ( V_51 -> V_106 -> V_128 == V_109 )
F_7 ( V_2 , V_150 , 32 ) ;
else
F_7 ( V_2 , V_150 , 16 ) ;
switch ( V_9 -> V_55 ) {
case V_70 :
F_11 ( V_2 , V_151 ,
F_33 ( V_9 -> V_77 ) ) ;
break;
case V_81 :
F_11 ( V_2 , V_152 , F_33 ( V_9 -> V_153 ) ) ;
F_11 ( V_2 , V_154 ,
F_33 ( V_83 ) ) ;
break;
default:
break;
}
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
static void F_26 ( struct V_100 * V_51 )
{
struct V_103 * V_104 = V_51 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_155 = V_51 -> V_106 -> V_155 ;
unsigned int V_122 = V_51 -> V_106 -> V_122 ;
unsigned int V_156 ;
if ( ! V_9 -> V_55 )
return;
switch ( V_9 -> V_55 ) {
case V_70 :
V_9 -> V_77 = F_62 ( V_122 ,
V_9 -> V_157 ) ;
V_156 = V_9 -> V_110 - V_9 -> V_77 ;
if ( V_155 <= V_9 -> V_77 )
V_9 -> V_72 = V_155 *
( ( V_9 -> V_77 / V_155 ) +
( V_9 -> V_77 % V_155 ?
1 : 0 ) ) ;
else if ( V_155 > V_156 )
V_9 -> V_72 = V_156 ;
else
V_9 -> V_72 = V_155 ;
V_9 -> V_158 = F_38 ( V_9 -> V_78 ,
V_9 -> V_72 ) ;
V_9 -> V_75 = 0 ;
V_9 -> V_74 = 0 ;
break;
case V_81 :
V_9 -> V_153 = F_63 ( V_155 , V_122 ,
V_9 -> V_78 ) + 9 ;
if ( V_9 -> V_153 > ( V_9 -> V_110 - V_83 ) )
V_9 -> V_153 = V_9 -> V_110 - V_83 ;
if ( V_9 -> V_153 < ( V_83 + 10 ) )
V_9 -> V_153 = ( V_83 + 10 ) ;
V_9 -> V_82 =
F_38 ( V_51 -> V_106 -> V_122 ,
V_9 -> V_153 - V_83 + 1 ) ;
V_9 -> V_75 = 0 ;
break;
default:
break;
}
}
static int F_64 ( struct V_100 * V_51 , int V_159 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 = V_51 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
switch ( V_159 ) {
case V_160 :
case V_161 :
case V_162 :
if ( V_9 -> V_55 ) {
V_9 -> V_87 = V_88 ;
F_45 ( V_9 -> V_95 , & V_9 -> V_86 ) ;
}
break;
case V_163 :
case V_164 :
case V_165 :
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
static T_3 F_65 (
struct V_100 * V_51 ,
struct V_101 * V_102 )
{
struct V_103 * V_104 = V_51 -> V_105 ;
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned long long V_166 , V_167 , V_168 ;
unsigned int V_169 , V_153 ;
int V_170 , V_171 , V_172 ;
T_3 V_68 = 0 ;
unsigned long V_69 ;
switch ( V_9 -> V_55 ) {
case V_173 :
break;
case V_70 :
F_34 ( & V_9 -> V_73 , V_69 ) ;
V_166 = V_9 -> V_75 ;
V_167 = V_9 -> V_74 ;
F_37 ( & V_9 -> V_73 , V_69 ) ;
V_168 = F_35 ( F_36 () ) ;
if ( ! V_167 )
goto V_174;
if ( V_166 > V_167 ) {
V_169 = V_168 - V_166 ;
V_170 = V_169 ? F_62 (
V_51 -> V_106 -> V_122 ,
V_169 ) : 0 ;
if ( F_25 ( V_9 -> V_77 > V_170 ) )
V_68 = V_9 -> V_77 - V_170 ;
else
V_68 = 0 ;
} else if ( ( V_168 - V_167 ) <= V_9 -> V_158 ) {
V_169 = V_168 - V_166 ;
V_170 = V_169 ? F_62 (
V_51 -> V_106 -> V_122 ,
V_169 ) : 0 ;
V_169 = V_168 - V_167 ;
V_171 = V_169 ? F_62 (
V_9 -> V_78 ,
V_169 ) : 0 ;
V_172 = V_9 -> V_77 ;
V_172 += ( V_171 - V_170 ) ;
if ( F_25 ( V_172 > 0 ) )
V_68 = V_172 ;
else
V_68 = 0 ;
} else {
V_169 = V_168 - V_166 ;
V_170 = V_169 ? F_62 (
V_51 -> V_106 -> V_122 ,
V_169 ) : 0 ;
V_171 = V_9 -> V_72 ;
V_172 = V_9 -> V_77 ;
V_172 += ( V_171 - V_170 ) ;
if ( F_25 ( V_172 > 0 ) )
V_68 = V_172 > V_9 -> V_110 ?
V_9 -> V_110 : V_172 ;
else
V_68 = 0 ;
}
break;
case V_81 :
F_34 ( & V_9 -> V_73 , V_69 ) ;
V_166 = V_9 -> V_75 ;
V_153 = V_9 -> V_153 ;
F_37 ( & V_9 -> V_73 , V_69 ) ;
V_168 = F_35 ( F_36 () ) ;
if ( ! V_166 )
goto V_174;
if ( V_168 <= V_166 ) {
V_68 = V_153 ;
goto V_174;
}
V_169 = V_168 - V_166 ;
if ( V_169 <= V_9 -> V_82 ) {
V_170 = F_62 (
V_51 -> V_106 -> V_122 ,
V_169 ) ;
if ( F_25 ( V_153 > V_170 ) )
V_68 = V_153 - V_170 ;
else
V_68 = 0 ;
} else {
V_169 = V_169 - V_9 -> V_82 ;
V_170 = F_62 (
V_51 -> V_106 -> V_122 ,
V_169 ) ;
V_171 = F_62 (
V_9 -> V_78 ,
V_169 ) ;
V_68 = V_83 + V_171 - V_170 ;
if ( F_13 ( V_68 > V_153 ) )
V_68 = V_153 ;
}
break;
default:
F_40 ( V_2 -> V_14 , L_8 ,
V_9 -> V_55 ) ;
break;
}
V_174:
return V_68 ;
}
static int F_66 ( struct V_101 * V_175 ,
int V_176 , unsigned int V_177 , int V_178 )
{
struct V_1 * V_2 = V_175 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_179 , V_180 ;
V_179 = F_1 ( V_2 , V_133 ) ;
V_180 = F_1 ( V_2 , V_139 ) ;
switch ( V_176 ) {
case V_181 :
V_179 |= V_182 ;
V_180 |= V_183 ;
break;
case V_184 :
V_179 &= ~ V_182 ;
V_180 &= ~ V_183 ;
break;
default:
F_6 ( V_2 -> V_14 , L_12 , V_176 ) ;
break;
}
V_9 -> V_123 = V_177 ;
F_2 ( V_2 , V_133 , V_179 ) ;
F_2 ( V_2 , V_139 , V_180 ) ;
return 0 ;
}
static int F_67 ( struct V_101 * V_175 ,
unsigned int V_185 )
{
struct V_1 * V_2 = V_175 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_119 , V_120 ;
V_119 = F_1 ( V_2 , V_124 ) ;
V_120 = F_1 ( V_2 , V_41 ) ;
switch ( V_185 & V_186 ) {
case V_187 :
V_119 |= ( V_188 | V_189 ) ;
break;
case V_190 :
if ( V_9 -> V_55 ) {
F_6 ( V_2 -> V_14 , L_13 ) ;
return - V_59 ;
} else
V_119 &= ~ ( V_188 | V_189 ) ;
break;
default:
return - V_59 ;
}
V_119 &= ~ V_191 ;
switch ( V_185 & V_192 ) {
case V_193 :
V_119 |= V_194 ;
break;
case V_195 :
V_119 |= V_196 ;
V_120 &= ~ V_197 ;
V_120 |= F_68 ( 0 ) ;
break;
case V_198 :
V_119 |= V_199 ;
break;
case V_200 :
V_119 |= V_201 ;
break;
default:
F_6 ( V_2 -> V_14 , L_14 ,
V_185 & V_192 ) ;
return - V_59 ;
}
F_2 ( V_2 , V_124 , V_119 ) ;
F_2 ( V_2 , V_41 , V_120 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_16 = ( V_202 ) V_203 ;
V_2 -> V_65 . V_204 = 1 ;
V_9 -> V_2 = V_2 ;
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 -> V_14 , L_15 , V_11 ) ;
goto V_205;
}
V_11 = F_15 ( V_2 ) ;
F_18 ( V_2 , 0 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_16 , V_11 ) ;
V_11 = - V_206 ;
goto V_205;
}
if ( V_9 -> V_94 >= 0 ) {
V_11 = F_70 ( V_9 -> V_94 , F_44 ,
V_207 ,
V_2 -> V_208 , V_2 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_17 ,
V_9 -> V_94 , V_11 ) ;
V_9 -> V_94 = - 1 ;
}
if ( V_9 -> V_94 != - 1 ) {
V_9 -> V_95 =
F_71 ( L_18 ) ;
if ( V_9 -> V_95 == NULL ) {
F_72 ( V_9 -> V_94 , V_2 ) ;
return - V_209 ;
}
F_73 ( & V_9 -> V_86 , F_42 ) ;
}
}
if ( V_9 -> V_94 >= 0 )
F_74 ( V_2 , V_210 ,
F_21 ( V_210 ) ) ;
V_205:
return V_11 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
F_31 ( V_2 , V_67 ) ;
if ( V_9 -> V_94 >= 0 ) {
F_72 ( V_9 -> V_94 , V_9 -> V_2 ) ;
F_76 ( V_9 -> V_95 ) ;
}
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_67 ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_64 ) ;
return 0 ;
}
static int T_4 F_79 ( struct V_211 * V_212 ,
const struct V_213 * V_214 )
{
struct V_215 * V_216 ;
struct V_8 * V_9 ;
int V_11 , V_33 ;
if ( V_212 -> V_14 . V_217 == NULL ) {
F_6 ( & V_212 -> V_14 , L_19 ) ;
return - V_206 ;
}
V_216 = V_212 -> V_14 . V_217 ;
V_9 = F_80 ( & V_212 -> V_14 , sizeof( struct V_8 ) ,
V_218 ) ;
if ( V_9 == NULL )
return - V_209 ;
V_9 -> V_13 = V_212 ;
F_81 ( & V_9 -> V_17 ) ;
F_82 ( & V_9 -> V_73 ) ;
F_83 ( V_212 , V_9 ) ;
V_9 -> V_44 = V_216 -> V_44 ;
V_9 -> V_112 = V_216 -> V_112 ;
V_9 -> V_149 = V_216 -> V_149 ;
V_9 -> V_157 = V_216 -> V_157 ;
if ( ! V_9 -> V_157 )
V_9 -> V_157 = 10000 ;
V_9 -> V_94 = V_212 -> V_94 ;
V_9 -> V_55 = V_173 ;
if ( V_9 -> V_44 >= 0 ) {
V_11 = F_84 ( V_9 -> V_44 , L_20 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_212 -> V_14 ,
L_21 ,
V_9 -> V_44 ) ;
goto V_219;
}
F_85 ( V_9 -> V_44 , 0 ) ;
}
for ( V_33 = 0 ; V_33 < F_21 ( V_9 -> V_43 ) ; V_33 ++ )
V_9 -> V_43 [ V_33 ] . V_220 = V_221 [ V_33 ] ;
V_11 = F_86 ( & V_212 -> V_14 , F_21 ( V_9 -> V_43 ) ,
V_9 -> V_43 ) ;
if ( V_11 != 0 ) {
F_6 ( & V_212 -> V_14 , L_22 , V_11 ) ;
goto V_222;
}
V_11 = F_87 ( & V_212 -> V_14 ,
& V_223 , & V_224 , 1 ) ;
if ( V_11 < 0 )
goto V_225;
return V_11 ;
V_225:
F_88 ( F_21 ( V_9 -> V_43 ) , V_9 -> V_43 ) ;
V_222:
if ( V_9 -> V_44 >= 0 )
F_89 ( V_9 -> V_44 ) ;
V_219:
return V_11 ;
}
static int T_5 F_90 ( struct V_211 * V_212 )
{
struct V_8 * V_9 = F_91 ( V_212 ) ;
if ( F_13 ( V_9 -> V_12 ) )
F_18 ( V_9 -> V_2 , 0 ) ;
if ( V_9 -> V_44 >= 0 )
F_89 ( V_9 -> V_44 ) ;
F_88 ( F_21 ( V_9 -> V_43 ) , V_9 -> V_43 ) ;
F_92 ( & V_212 -> V_14 ) ;
return 0 ;
}
static int T_6 F_93 ( void )
{
int V_226 ;
V_226 = F_94 ( & V_227 ) ;
if ( V_226 < 0 ) {
F_95 ( V_228 L_23 ) ;
return V_226 ;
}
return 0 ;
}
static void T_7 F_96 ( void )
{
F_97 ( & V_227 ) ;
}
