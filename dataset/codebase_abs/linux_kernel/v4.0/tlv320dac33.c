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
struct V_1 * V_2 = F_25 ( V_46 -> V_50 ) ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
switch ( V_49 ) {
case V_51 :
if ( F_26 ( V_9 -> V_52 ) ) {
F_27 ( V_9 -> V_52 , V_2 ) ;
F_28 ( V_9 -> V_52 , V_2 ) ;
}
break;
case V_53 :
F_17 ( V_2 ) ;
break;
}
return 0 ;
}
static int F_29 ( struct V_47 * V_48 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_30 ( V_48 ) ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_55 -> V_7 . integer . V_7 [ 0 ] = V_9 -> V_56 ;
return 0 ;
}
static int F_31 ( struct V_47 * V_48 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_30 ( V_48 ) ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
if ( V_9 -> V_56 == V_55 -> V_7 . integer . V_7 [ 0 ] )
return 0 ;
if ( F_32 ( V_2 ) )
return - V_57 ;
if ( V_55 -> V_7 . integer . V_7 [ 0 ] < 0 ||
V_55 -> V_7 . integer . V_7 [ 0 ] >= V_58 )
V_11 = - V_59 ;
else
V_9 -> V_56 = V_55 -> V_7 . integer . V_7 [ 0 ] ;
return V_11 ;
}
static int F_33 ( struct V_1 * V_2 ,
enum V_60 V_61 )
{
int V_11 ;
switch ( V_61 ) {
case V_62 :
break;
case V_63 :
break;
case V_64 :
if ( V_2 -> V_50 . V_65 == V_66 ) {
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 != 0 )
return V_11 ;
F_12 ( V_2 ) ;
}
break;
case V_66 :
if ( V_2 -> V_50 . V_65 == V_66 )
return 0 ;
V_11 = F_18 ( V_2 , 0 ) ;
if ( V_11 != 0 )
return V_11 ;
break;
}
V_2 -> V_50 . V_65 = V_61 ;
return 0 ;
}
static inline void F_34 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_67 ;
unsigned long V_68 ;
switch ( V_9 -> V_56 ) {
case V_69 :
F_11 ( V_2 , V_70 ,
F_35 ( V_9 -> V_71 ) ) ;
F_36 ( & V_9 -> V_72 , V_68 ) ;
V_9 -> V_73 = F_37 ( F_38 () ) ;
V_9 -> V_74 = V_9 -> V_73 ;
F_39 ( & V_9 -> V_72 , V_68 ) ;
F_11 ( V_2 , V_75 ,
F_35 ( V_9 -> V_76 ) ) ;
V_67 = F_40 ( V_9 -> V_77 ,
V_9 -> V_76 ) + 1000 ;
F_41 ( V_67 , V_67 + 500 ) ;
F_7 ( V_2 , V_78 , V_79 ) ;
break;
case V_80 :
F_36 ( & V_9 -> V_72 , V_68 ) ;
V_9 -> V_74 = F_37 ( F_38 () ) ;
V_9 -> V_74 -= V_9 -> V_81 ;
F_39 ( & V_9 -> V_72 , V_68 ) ;
F_11 ( V_2 , V_75 ,
F_35 ( V_82 ) ) ;
F_7 ( V_2 , V_78 , V_83 ) ;
break;
default:
F_42 ( V_2 -> V_14 , L_8 ,
V_9 -> V_56 ) ;
break;
}
}
static inline void F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_68 ;
switch ( V_9 -> V_56 ) {
case V_69 :
F_36 ( & V_9 -> V_72 , V_68 ) ;
V_9 -> V_73 = F_37 ( F_38 () ) ;
F_39 ( & V_9 -> V_72 , V_68 ) ;
F_11 ( V_2 , V_70 ,
F_35 ( V_9 -> V_71 ) ) ;
break;
case V_80 :
break;
default:
F_42 ( V_2 -> V_14 , L_8 ,
V_9 -> V_56 ) ;
break;
}
}
static void F_44 ( struct V_84 * V_85 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
T_1 V_3 ;
V_9 = F_45 ( V_85 , struct V_8 , V_85 ) ;
V_2 = V_9 -> V_2 ;
F_9 ( & V_9 -> V_17 ) ;
switch ( V_9 -> V_86 ) {
case V_87 :
V_9 -> V_86 = V_88 ;
F_34 ( V_9 ) ;
break;
case V_88 :
F_43 ( V_9 ) ;
break;
case V_89 :
break;
case V_90 :
V_9 -> V_86 = V_89 ;
F_7 ( V_2 , V_78 , 0 ) ;
V_3 = F_1 ( V_2 , V_91 ) ;
V_3 |= V_92 ;
F_7 ( V_2 , V_91 , V_3 ) ;
break;
}
F_10 ( & V_9 -> V_17 ) ;
}
static T_2 F_46 ( int V_93 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned long V_68 ;
F_36 ( & V_9 -> V_72 , V_68 ) ;
V_9 -> V_74 = F_37 ( F_38 () ) ;
F_39 ( & V_9 -> V_72 , V_68 ) ;
if ( V_9 -> V_56 != V_80 )
F_47 ( V_9 -> V_94 , & V_9 -> V_85 ) ;
return V_95 ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_96 = 60 ;
T_1 V_3 ;
do {
F_41 ( 1000 , 2000 ) ;
F_3 ( V_2 , V_97 , & V_3 ) ;
} while ( ( ( V_3 & 0x03 ) != V_98 ) && V_96 -- );
if ( ( V_3 & 0x03 ) != V_98 )
F_6 ( V_2 -> V_14 ,
L_9 ) ;
}
static int F_49 ( struct V_99 * V_52 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_52 = V_52 ;
return 0 ;
}
static void F_50 ( struct V_99 * V_52 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_52 = NULL ;
}
static int F_51 ( struct V_99 * V_52 ,
struct V_102 * V_103 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
switch ( F_52 ( V_103 ) ) {
case 44100 :
case 48000 :
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
F_52 ( V_103 ) ) ;
return - V_59 ;
}
switch ( F_53 ( V_103 ) ) {
case 16 :
V_9 -> V_104 = V_105 ;
V_9 -> V_77 = F_54 ( V_9 -> V_106 , 32 ) ;
break;
case 32 :
V_9 -> V_104 = V_107 ;
V_9 -> V_77 = F_54 ( V_9 -> V_106 , 64 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_11 ,
F_53 ( V_103 ) ) ;
return - V_59 ;
}
return 0 ;
}
static int F_28 ( struct V_99 * V_52 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_108 , V_109 , V_110 , V_111 ;
T_1 V_112 , V_113 , V_114 ;
switch ( V_52 -> V_115 -> V_116 ) {
case 44100 :
case 48000 :
V_108 = F_55 ( V_52 -> V_115 -> V_116 , V_9 -> V_117 ) ;
V_109 = F_56 ( V_52 -> V_115 -> V_116 ,
V_9 -> V_117 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
V_52 -> V_115 -> V_116 ) ;
return - V_59 ;
}
V_112 = F_1 ( V_2 , V_118 ) ;
V_112 &= ~ ( V_119 | V_120 ) ;
V_114 = F_1 ( V_2 , V_91 ) ;
V_114 &= ~ V_92 ;
V_114 &= ~ V_121 ;
switch ( V_52 -> V_115 -> V_122 ) {
case V_123 :
V_112 |= ( V_124 | V_125 ) ;
V_114 |= V_121 ;
break;
case V_126 :
V_112 |= ( V_127 | V_128 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_12 ,
V_52 -> V_115 -> V_122 ) ;
return - V_59 ;
}
F_9 ( & V_9 -> V_17 ) ;
if ( ! V_9 -> V_12 ) {
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
F_16 ( V_2 , 0 ) ;
F_16 ( V_2 , 1 ) ;
V_111 = F_1 ( V_2 , V_129 ) ;
F_7 ( V_2 , V_129 , V_111 ) ;
F_11 ( V_2 , V_130 , V_108 ) ;
F_7 ( V_2 , V_131 , 96 ) ;
F_7 ( V_2 , V_132 , F_57 ( 2 ) |
F_58 ( 1 ) ) ;
F_7 ( V_2 , V_133 , F_59 ( 4 ) ) ;
V_110 = F_1 ( V_2 , V_36 ) ;
V_110 |= V_38 | V_39 | V_40 ;
F_7 ( V_2 , V_36 , V_110 ) ;
F_48 ( V_2 ) ;
if ( V_9 -> V_56 ) {
F_7 ( V_2 , V_134 , F_60 ( 1 ) ) ;
F_7 ( V_2 , V_135 , 1 ) ;
F_11 ( V_2 , V_136 , V_109 ) ;
F_7 ( V_2 , V_137 , V_138 ) ;
} else {
F_7 ( V_2 , V_134 , V_139 ) ;
F_7 ( V_2 , V_135 , 0 ) ;
}
switch ( V_9 -> V_56 ) {
case V_69 :
F_7 ( V_2 , V_140 ,
F_61 ( V_141 ) ) ;
break;
case V_80 :
F_7 ( V_2 , V_142 ,
F_62 ( V_141 ) ) ;
break;
default:
break;
}
V_113 = F_1 ( V_2 , V_41 ) ;
switch ( V_9 -> V_56 ) {
case V_69 :
V_114 &= ~ V_143 ;
V_114 &= ~ V_144 ;
if ( V_9 -> V_145 )
V_113 |= V_42 ;
else
V_113 &= ~ V_42 ;
break;
case V_80 :
V_114 &= ~ V_143 ;
V_114 |= V_144 ;
if ( V_9 -> V_145 )
V_113 |= V_42 ;
else
V_113 &= ~ V_42 ;
break;
default:
V_114 |= V_143 ;
V_113 |= V_42 ;
break;
}
F_7 ( V_2 , V_91 , V_114 ) ;
F_7 ( V_2 , V_118 , V_112 ) ;
F_7 ( V_2 , V_41 , V_113 ) ;
if ( V_9 -> V_56 )
F_7 ( V_2 , V_146 ,
V_9 -> V_106 ) ;
else
if ( V_52 -> V_115 -> V_122 == V_123 )
F_7 ( V_2 , V_146 , 32 ) ;
else
F_7 ( V_2 , V_146 , 16 ) ;
switch ( V_9 -> V_56 ) {
case V_69 :
F_11 ( V_2 , V_147 ,
F_35 ( V_9 -> V_76 ) ) ;
break;
case V_80 :
F_11 ( V_2 , V_148 , F_35 ( V_9 -> V_149 ) ) ;
F_11 ( V_2 , V_150 ,
F_35 ( V_82 ) ) ;
break;
default:
break;
}
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
static void F_27 ( struct V_99 * V_52 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_151 = V_52 -> V_115 -> V_151 ;
unsigned int V_116 = V_52 -> V_115 -> V_116 ;
unsigned int V_152 ;
if ( ! V_9 -> V_56 )
return;
switch ( V_9 -> V_56 ) {
case V_69 :
V_9 -> V_76 = F_63 ( V_116 ,
V_9 -> V_153 ) ;
V_152 = V_9 -> V_104 - V_9 -> V_76 ;
if ( V_151 <= V_9 -> V_76 )
V_9 -> V_71 = V_151 *
( ( V_9 -> V_76 / V_151 ) +
( V_9 -> V_76 % V_151 ?
1 : 0 ) ) ;
else if ( V_151 > V_152 )
V_9 -> V_71 = V_152 ;
else
V_9 -> V_71 = V_151 ;
V_9 -> V_154 = F_40 ( V_9 -> V_77 ,
V_9 -> V_71 ) ;
V_9 -> V_74 = 0 ;
V_9 -> V_73 = 0 ;
break;
case V_80 :
V_9 -> V_149 = F_64 ( V_151 , V_116 ,
V_9 -> V_77 ) + 9 ;
if ( V_9 -> V_149 > ( V_9 -> V_104 - V_82 ) )
V_9 -> V_149 = V_9 -> V_104 - V_82 ;
if ( V_9 -> V_149 < ( V_82 + 10 ) )
V_9 -> V_149 = ( V_82 + 10 ) ;
V_9 -> V_81 =
F_40 ( V_52 -> V_115 -> V_116 ,
V_9 -> V_149 - V_82 + 1 ) ;
V_9 -> V_74 = 0 ;
break;
default:
break;
}
}
static int F_65 ( struct V_99 * V_52 , int V_155 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
switch ( V_155 ) {
case V_156 :
case V_157 :
case V_158 :
if ( V_9 -> V_56 ) {
V_9 -> V_86 = V_87 ;
F_47 ( V_9 -> V_94 , & V_9 -> V_85 ) ;
}
break;
case V_159 :
case V_160 :
case V_161 :
if ( V_9 -> V_56 ) {
V_9 -> V_86 = V_90 ;
F_47 ( V_9 -> V_94 , & V_9 -> V_85 ) ;
}
break;
default:
V_11 = - V_59 ;
}
return V_11 ;
}
static T_3 F_66 (
struct V_99 * V_52 ,
struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned long long V_162 , V_163 , V_164 ;
unsigned int V_165 , V_149 ;
int V_166 , V_167 , V_168 ;
T_3 V_67 = 0 ;
unsigned long V_68 ;
switch ( V_9 -> V_56 ) {
case V_169 :
break;
case V_69 :
F_36 ( & V_9 -> V_72 , V_68 ) ;
V_162 = V_9 -> V_74 ;
V_163 = V_9 -> V_73 ;
F_39 ( & V_9 -> V_72 , V_68 ) ;
V_164 = F_37 ( F_38 () ) ;
if ( ! V_163 )
goto V_170;
if ( V_162 > V_163 ) {
V_165 = V_164 - V_162 ;
V_166 = V_165 ? F_63 (
V_52 -> V_115 -> V_116 ,
V_165 ) : 0 ;
if ( F_26 ( V_9 -> V_76 > V_166 ) )
V_67 = V_9 -> V_76 - V_166 ;
else
V_67 = 0 ;
} else if ( ( V_164 - V_163 ) <= V_9 -> V_154 ) {
V_165 = V_164 - V_162 ;
V_166 = V_165 ? F_63 (
V_52 -> V_115 -> V_116 ,
V_165 ) : 0 ;
V_165 = V_164 - V_163 ;
V_167 = V_165 ? F_63 (
V_9 -> V_77 ,
V_165 ) : 0 ;
V_168 = V_9 -> V_76 ;
V_168 += ( V_167 - V_166 ) ;
if ( F_26 ( V_168 > 0 ) )
V_67 = V_168 ;
else
V_67 = 0 ;
} else {
V_165 = V_164 - V_162 ;
V_166 = V_165 ? F_63 (
V_52 -> V_115 -> V_116 ,
V_165 ) : 0 ;
V_167 = V_9 -> V_71 ;
V_168 = V_9 -> V_76 ;
V_168 += ( V_167 - V_166 ) ;
if ( F_26 ( V_168 > 0 ) )
V_67 = V_168 > V_9 -> V_104 ?
V_9 -> V_104 : V_168 ;
else
V_67 = 0 ;
}
break;
case V_80 :
F_36 ( & V_9 -> V_72 , V_68 ) ;
V_162 = V_9 -> V_74 ;
V_149 = V_9 -> V_149 ;
F_39 ( & V_9 -> V_72 , V_68 ) ;
V_164 = F_37 ( F_38 () ) ;
if ( ! V_162 )
goto V_170;
if ( V_164 <= V_162 ) {
V_67 = V_149 ;
goto V_170;
}
V_165 = V_164 - V_162 ;
if ( V_165 <= V_9 -> V_81 ) {
V_166 = F_63 (
V_52 -> V_115 -> V_116 ,
V_165 ) ;
if ( F_26 ( V_149 > V_166 ) )
V_67 = V_149 - V_166 ;
else
V_67 = 0 ;
} else {
V_165 = V_165 - V_9 -> V_81 ;
V_166 = F_63 (
V_52 -> V_115 -> V_116 ,
V_165 ) ;
V_167 = F_63 (
V_9 -> V_77 ,
V_165 ) ;
V_67 = V_82 + V_167 - V_166 ;
if ( F_13 ( V_67 > V_149 ) )
V_67 = V_149 ;
}
break;
default:
F_42 ( V_2 -> V_14 , L_8 ,
V_9 -> V_56 ) ;
break;
}
V_170:
return V_67 ;
}
static int F_67 ( struct V_100 * V_171 ,
int V_172 , unsigned int V_173 , int V_174 )
{
struct V_1 * V_2 = V_171 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_175 , V_176 ;
V_175 = F_1 ( V_2 , V_129 ) ;
V_176 = F_1 ( V_2 , V_135 ) ;
switch ( V_172 ) {
case V_177 :
V_175 |= V_178 ;
V_176 |= V_179 ;
break;
case V_180 :
V_175 &= ~ V_178 ;
V_176 &= ~ V_179 ;
break;
default:
F_6 ( V_2 -> V_14 , L_13 , V_172 ) ;
break;
}
V_9 -> V_117 = V_173 ;
F_2 ( V_2 , V_129 , V_175 ) ;
F_2 ( V_2 , V_135 , V_176 ) ;
return 0 ;
}
static int F_68 ( struct V_100 * V_171 ,
unsigned int V_181 )
{
struct V_1 * V_2 = V_171 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_112 , V_113 ;
V_112 = F_1 ( V_2 , V_118 ) ;
V_113 = F_1 ( V_2 , V_41 ) ;
switch ( V_181 & V_182 ) {
case V_183 :
V_112 |= ( V_184 | V_185 ) ;
break;
case V_186 :
if ( V_9 -> V_56 ) {
F_6 ( V_2 -> V_14 , L_14 ) ;
return - V_59 ;
} else
V_112 &= ~ ( V_184 | V_185 ) ;
break;
default:
return - V_59 ;
}
V_112 &= ~ V_187 ;
switch ( V_181 & V_188 ) {
case V_189 :
V_112 |= V_190 ;
break;
case V_191 :
V_112 |= V_192 ;
V_113 &= ~ V_193 ;
V_113 |= F_69 ( 0 ) ;
break;
case V_194 :
V_112 |= V_195 ;
break;
case V_196 :
V_112 |= V_197 ;
break;
default:
F_6 ( V_2 -> V_14 , L_15 ,
V_181 & V_188 ) ;
return - V_59 ;
}
F_2 ( V_2 , V_118 , V_112 ) ;
F_2 ( V_2 , V_41 , V_113 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_16 = ( V_198 ) V_199 ;
V_9 -> V_2 = V_2 ;
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 -> V_14 , L_16 , V_11 ) ;
goto V_200;
}
V_11 = F_15 ( V_2 ) ;
F_18 ( V_2 , 0 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_17 , V_11 ) ;
V_11 = - V_201 ;
goto V_200;
}
if ( V_9 -> V_93 >= 0 ) {
V_11 = F_71 ( V_9 -> V_93 , F_46 ,
V_202 ,
V_2 -> V_203 . V_204 , V_2 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_18 ,
V_9 -> V_93 , V_11 ) ;
V_9 -> V_93 = - 1 ;
}
if ( V_9 -> V_93 != - 1 ) {
V_9 -> V_94 =
F_72 ( L_19 ) ;
if ( V_9 -> V_94 == NULL ) {
F_73 ( V_9 -> V_93 , V_2 ) ;
return - V_205 ;
}
F_74 ( & V_9 -> V_85 , F_44 ) ;
}
}
if ( V_9 -> V_93 >= 0 )
F_75 ( V_2 , V_206 ,
F_21 ( V_206 ) ) ;
V_200:
return V_11 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
if ( V_9 -> V_93 >= 0 ) {
F_73 ( V_9 -> V_93 , V_9 -> V_2 ) ;
F_77 ( V_9 -> V_94 ) ;
}
return 0 ;
}
static int F_78 ( struct V_207 * V_208 ,
const struct V_209 * V_210 )
{
struct V_211 * V_212 ;
struct V_8 * V_9 ;
int V_11 , V_33 ;
if ( V_208 -> V_14 . V_213 == NULL ) {
F_6 ( & V_208 -> V_14 , L_20 ) ;
return - V_201 ;
}
V_212 = V_208 -> V_14 . V_213 ;
V_9 = F_79 ( & V_208 -> V_14 , sizeof( struct V_8 ) ,
V_214 ) ;
if ( V_9 == NULL )
return - V_205 ;
V_9 -> V_13 = V_208 ;
F_80 ( & V_9 -> V_17 ) ;
F_81 ( & V_9 -> V_72 ) ;
F_82 ( V_208 , V_9 ) ;
V_9 -> V_44 = V_212 -> V_44 ;
V_9 -> V_106 = V_212 -> V_106 ;
V_9 -> V_145 = V_212 -> V_145 ;
V_9 -> V_153 = V_212 -> V_153 ;
if ( ! V_9 -> V_153 )
V_9 -> V_153 = 10000 ;
V_9 -> V_93 = V_208 -> V_93 ;
V_9 -> V_56 = V_169 ;
if ( V_9 -> V_44 >= 0 ) {
V_11 = F_83 ( V_9 -> V_44 , L_21 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_208 -> V_14 ,
L_22 ,
V_9 -> V_44 ) ;
goto V_215;
}
F_84 ( V_9 -> V_44 , 0 ) ;
}
for ( V_33 = 0 ; V_33 < F_21 ( V_9 -> V_43 ) ; V_33 ++ )
V_9 -> V_43 [ V_33 ] . V_216 = V_217 [ V_33 ] ;
V_11 = F_85 ( & V_208 -> V_14 , F_21 ( V_9 -> V_43 ) ,
V_9 -> V_43 ) ;
if ( V_11 != 0 ) {
F_6 ( & V_208 -> V_14 , L_23 , V_11 ) ;
goto V_218;
}
V_11 = F_86 ( & V_208 -> V_14 ,
& V_219 , & V_220 , 1 ) ;
if ( V_11 < 0 )
goto V_218;
return V_11 ;
V_218:
if ( V_9 -> V_44 >= 0 )
F_87 ( V_9 -> V_44 ) ;
V_215:
return V_11 ;
}
static int F_88 ( struct V_207 * V_208 )
{
struct V_8 * V_9 = F_89 ( V_208 ) ;
if ( F_13 ( V_9 -> V_12 ) )
F_18 ( V_9 -> V_2 , 0 ) ;
if ( V_9 -> V_44 >= 0 )
F_87 ( V_9 -> V_44 ) ;
F_90 ( & V_208 -> V_14 ) ;
return 0 ;
}
