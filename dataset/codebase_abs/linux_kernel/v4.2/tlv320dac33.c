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
if ( F_34 ( V_2 ) == V_65 ) {
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 != 0 )
return V_11 ;
F_12 ( V_2 ) ;
}
break;
case V_65 :
if ( F_34 ( V_2 ) == V_65 )
return 0 ;
V_11 = F_18 ( V_2 , 0 ) ;
if ( V_11 != 0 )
return V_11 ;
break;
}
return 0 ;
}
static inline void F_35 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned int V_66 ;
unsigned long V_67 ;
switch ( V_9 -> V_56 ) {
case V_68 :
F_11 ( V_2 , V_69 ,
F_36 ( V_9 -> V_70 ) ) ;
F_37 ( & V_9 -> V_71 , V_67 ) ;
V_9 -> V_72 = F_38 ( F_39 () ) ;
V_9 -> V_73 = V_9 -> V_72 ;
F_40 ( & V_9 -> V_71 , V_67 ) ;
F_11 ( V_2 , V_74 ,
F_36 ( V_9 -> V_75 ) ) ;
V_66 = F_41 ( V_9 -> V_76 ,
V_9 -> V_75 ) + 1000 ;
F_42 ( V_66 , V_66 + 500 ) ;
F_7 ( V_2 , V_77 , V_78 ) ;
break;
case V_79 :
F_37 ( & V_9 -> V_71 , V_67 ) ;
V_9 -> V_73 = F_38 ( F_39 () ) ;
V_9 -> V_73 -= V_9 -> V_80 ;
F_40 ( & V_9 -> V_71 , V_67 ) ;
F_11 ( V_2 , V_74 ,
F_36 ( V_81 ) ) ;
F_7 ( V_2 , V_77 , V_82 ) ;
break;
default:
F_43 ( V_2 -> V_14 , L_8 ,
V_9 -> V_56 ) ;
break;
}
}
static inline void F_44 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_67 ;
switch ( V_9 -> V_56 ) {
case V_68 :
F_37 ( & V_9 -> V_71 , V_67 ) ;
V_9 -> V_72 = F_38 ( F_39 () ) ;
F_40 ( & V_9 -> V_71 , V_67 ) ;
F_11 ( V_2 , V_69 ,
F_36 ( V_9 -> V_70 ) ) ;
break;
case V_79 :
break;
default:
F_43 ( V_2 -> V_14 , L_8 ,
V_9 -> V_56 ) ;
break;
}
}
static void F_45 ( struct V_83 * V_84 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
T_1 V_3 ;
V_9 = F_46 ( V_84 , struct V_8 , V_84 ) ;
V_2 = V_9 -> V_2 ;
F_9 ( & V_9 -> V_17 ) ;
switch ( V_9 -> V_85 ) {
case V_86 :
V_9 -> V_85 = V_87 ;
F_35 ( V_9 ) ;
break;
case V_87 :
F_44 ( V_9 ) ;
break;
case V_88 :
break;
case V_89 :
V_9 -> V_85 = V_88 ;
F_7 ( V_2 , V_77 , 0 ) ;
V_3 = F_1 ( V_2 , V_90 ) ;
V_3 |= V_91 ;
F_7 ( V_2 , V_90 , V_3 ) ;
break;
}
F_10 ( & V_9 -> V_17 ) ;
}
static T_2 F_47 ( int V_92 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned long V_67 ;
F_37 ( & V_9 -> V_71 , V_67 ) ;
V_9 -> V_73 = F_38 ( F_39 () ) ;
F_40 ( & V_9 -> V_71 , V_67 ) ;
if ( V_9 -> V_56 != V_79 )
F_48 ( V_9 -> V_93 , & V_9 -> V_84 ) ;
return V_94 ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_95 = 60 ;
T_1 V_3 ;
do {
F_42 ( 1000 , 2000 ) ;
F_3 ( V_2 , V_96 , & V_3 ) ;
} while ( ( ( V_3 & 0x03 ) != V_97 ) && V_95 -- );
if ( ( V_3 & 0x03 ) != V_97 )
F_6 ( V_2 -> V_14 ,
L_9 ) ;
}
static int F_50 ( struct V_98 * V_52 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = V_100 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_52 = V_52 ;
return 0 ;
}
static void F_51 ( struct V_98 * V_52 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = V_100 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
V_9 -> V_52 = NULL ;
}
static int F_52 ( struct V_98 * V_52 ,
struct V_101 * V_102 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = V_100 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
switch ( F_53 ( V_102 ) ) {
case 44100 :
case 48000 :
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
F_53 ( V_102 ) ) ;
return - V_59 ;
}
switch ( F_54 ( V_102 ) ) {
case 16 :
V_9 -> V_103 = V_104 ;
V_9 -> V_76 = F_55 ( V_9 -> V_105 , 32 ) ;
break;
case 32 :
V_9 -> V_103 = V_106 ;
V_9 -> V_76 = F_55 ( V_9 -> V_105 , 64 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_11 ,
F_54 ( V_102 ) ) ;
return - V_59 ;
}
return 0 ;
}
static int F_28 ( struct V_98 * V_52 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_107 , V_108 , V_109 , V_110 ;
T_1 V_111 , V_112 , V_113 ;
switch ( V_52 -> V_114 -> V_115 ) {
case 44100 :
case 48000 :
V_107 = F_56 ( V_52 -> V_114 -> V_115 , V_9 -> V_116 ) ;
V_108 = F_57 ( V_52 -> V_114 -> V_115 ,
V_9 -> V_116 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_10 ,
V_52 -> V_114 -> V_115 ) ;
return - V_59 ;
}
V_111 = F_1 ( V_2 , V_117 ) ;
V_111 &= ~ ( V_118 | V_119 ) ;
V_113 = F_1 ( V_2 , V_90 ) ;
V_113 &= ~ V_91 ;
V_113 &= ~ V_120 ;
switch ( V_52 -> V_114 -> V_121 ) {
case V_122 :
V_111 |= ( V_123 | V_124 ) ;
V_113 |= V_120 ;
break;
case V_125 :
V_111 |= ( V_126 | V_127 ) ;
break;
default:
F_6 ( V_2 -> V_14 , L_12 ,
V_52 -> V_114 -> V_121 ) ;
return - V_59 ;
}
F_9 ( & V_9 -> V_17 ) ;
if ( ! V_9 -> V_12 ) {
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
F_16 ( V_2 , 0 ) ;
F_16 ( V_2 , 1 ) ;
V_110 = F_1 ( V_2 , V_128 ) ;
F_7 ( V_2 , V_128 , V_110 ) ;
F_11 ( V_2 , V_129 , V_107 ) ;
F_7 ( V_2 , V_130 , 96 ) ;
F_7 ( V_2 , V_131 , F_58 ( 2 ) |
F_59 ( 1 ) ) ;
F_7 ( V_2 , V_132 , F_60 ( 4 ) ) ;
V_109 = F_1 ( V_2 , V_36 ) ;
V_109 |= V_38 | V_39 | V_40 ;
F_7 ( V_2 , V_36 , V_109 ) ;
F_49 ( V_2 ) ;
if ( V_9 -> V_56 ) {
F_7 ( V_2 , V_133 , F_61 ( 1 ) ) ;
F_7 ( V_2 , V_134 , 1 ) ;
F_11 ( V_2 , V_135 , V_108 ) ;
F_7 ( V_2 , V_136 , V_137 ) ;
} else {
F_7 ( V_2 , V_133 , V_138 ) ;
F_7 ( V_2 , V_134 , 0 ) ;
}
switch ( V_9 -> V_56 ) {
case V_68 :
F_7 ( V_2 , V_139 ,
F_62 ( V_140 ) ) ;
break;
case V_79 :
F_7 ( V_2 , V_141 ,
F_63 ( V_140 ) ) ;
break;
default:
break;
}
V_112 = F_1 ( V_2 , V_41 ) ;
switch ( V_9 -> V_56 ) {
case V_68 :
V_113 &= ~ V_142 ;
V_113 &= ~ V_143 ;
if ( V_9 -> V_144 )
V_112 |= V_42 ;
else
V_112 &= ~ V_42 ;
break;
case V_79 :
V_113 &= ~ V_142 ;
V_113 |= V_143 ;
if ( V_9 -> V_144 )
V_112 |= V_42 ;
else
V_112 &= ~ V_42 ;
break;
default:
V_113 |= V_142 ;
V_112 |= V_42 ;
break;
}
F_7 ( V_2 , V_90 , V_113 ) ;
F_7 ( V_2 , V_117 , V_111 ) ;
F_7 ( V_2 , V_41 , V_112 ) ;
if ( V_9 -> V_56 )
F_7 ( V_2 , V_145 ,
V_9 -> V_105 ) ;
else
if ( V_52 -> V_114 -> V_121 == V_122 )
F_7 ( V_2 , V_145 , 32 ) ;
else
F_7 ( V_2 , V_145 , 16 ) ;
switch ( V_9 -> V_56 ) {
case V_68 :
F_11 ( V_2 , V_146 ,
F_36 ( V_9 -> V_75 ) ) ;
break;
case V_79 :
F_11 ( V_2 , V_147 , F_36 ( V_9 -> V_148 ) ) ;
F_11 ( V_2 , V_149 ,
F_36 ( V_81 ) ) ;
break;
default:
break;
}
F_10 ( & V_9 -> V_17 ) ;
return 0 ;
}
static void F_27 ( struct V_98 * V_52 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned int V_150 = V_52 -> V_114 -> V_150 ;
unsigned int V_115 = V_52 -> V_114 -> V_115 ;
unsigned int V_151 ;
if ( ! V_9 -> V_56 )
return;
switch ( V_9 -> V_56 ) {
case V_68 :
V_9 -> V_75 = F_64 ( V_115 ,
V_9 -> V_152 ) ;
V_151 = V_9 -> V_103 - V_9 -> V_75 ;
if ( V_150 <= V_9 -> V_75 )
V_9 -> V_70 = V_150 *
( ( V_9 -> V_75 / V_150 ) +
( V_9 -> V_75 % V_150 ?
1 : 0 ) ) ;
else if ( V_150 > V_151 )
V_9 -> V_70 = V_151 ;
else
V_9 -> V_70 = V_150 ;
V_9 -> V_153 = F_41 ( V_9 -> V_76 ,
V_9 -> V_70 ) ;
V_9 -> V_73 = 0 ;
V_9 -> V_72 = 0 ;
break;
case V_79 :
V_9 -> V_148 = F_65 ( V_150 , V_115 ,
V_9 -> V_76 ) + 9 ;
if ( V_9 -> V_148 > ( V_9 -> V_103 - V_81 ) )
V_9 -> V_148 = V_9 -> V_103 - V_81 ;
if ( V_9 -> V_148 < ( V_81 + 10 ) )
V_9 -> V_148 = ( V_81 + 10 ) ;
V_9 -> V_80 =
F_41 ( V_52 -> V_114 -> V_115 ,
V_9 -> V_148 - V_81 + 1 ) ;
V_9 -> V_73 = 0 ;
break;
default:
break;
}
}
static int F_66 ( struct V_98 * V_52 , int V_154 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = V_100 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
switch ( V_154 ) {
case V_155 :
case V_156 :
case V_157 :
if ( V_9 -> V_56 ) {
V_9 -> V_85 = V_86 ;
F_48 ( V_9 -> V_93 , & V_9 -> V_84 ) ;
}
break;
case V_158 :
case V_159 :
case V_160 :
if ( V_9 -> V_56 ) {
V_9 -> V_85 = V_89 ;
F_48 ( V_9 -> V_93 , & V_9 -> V_84 ) ;
}
break;
default:
V_11 = - V_59 ;
}
return V_11 ;
}
static T_3 F_67 (
struct V_98 * V_52 ,
struct V_99 * V_100 )
{
struct V_1 * V_2 = V_100 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
unsigned long long V_161 , V_162 , V_163 ;
unsigned int V_164 , V_148 ;
int V_165 , V_166 , V_167 ;
T_3 V_66 = 0 ;
unsigned long V_67 ;
switch ( V_9 -> V_56 ) {
case V_168 :
break;
case V_68 :
F_37 ( & V_9 -> V_71 , V_67 ) ;
V_161 = V_9 -> V_73 ;
V_162 = V_9 -> V_72 ;
F_40 ( & V_9 -> V_71 , V_67 ) ;
V_163 = F_38 ( F_39 () ) ;
if ( ! V_162 )
goto V_169;
if ( V_161 > V_162 ) {
V_164 = V_163 - V_161 ;
V_165 = V_164 ? F_64 (
V_52 -> V_114 -> V_115 ,
V_164 ) : 0 ;
if ( F_26 ( V_9 -> V_75 > V_165 ) )
V_66 = V_9 -> V_75 - V_165 ;
else
V_66 = 0 ;
} else if ( ( V_163 - V_162 ) <= V_9 -> V_153 ) {
V_164 = V_163 - V_161 ;
V_165 = V_164 ? F_64 (
V_52 -> V_114 -> V_115 ,
V_164 ) : 0 ;
V_164 = V_163 - V_162 ;
V_166 = V_164 ? F_64 (
V_9 -> V_76 ,
V_164 ) : 0 ;
V_167 = V_9 -> V_75 ;
V_167 += ( V_166 - V_165 ) ;
if ( F_26 ( V_167 > 0 ) )
V_66 = V_167 ;
else
V_66 = 0 ;
} else {
V_164 = V_163 - V_161 ;
V_165 = V_164 ? F_64 (
V_52 -> V_114 -> V_115 ,
V_164 ) : 0 ;
V_166 = V_9 -> V_70 ;
V_167 = V_9 -> V_75 ;
V_167 += ( V_166 - V_165 ) ;
if ( F_26 ( V_167 > 0 ) )
V_66 = V_167 > V_9 -> V_103 ?
V_9 -> V_103 : V_167 ;
else
V_66 = 0 ;
}
break;
case V_79 :
F_37 ( & V_9 -> V_71 , V_67 ) ;
V_161 = V_9 -> V_73 ;
V_148 = V_9 -> V_148 ;
F_40 ( & V_9 -> V_71 , V_67 ) ;
V_163 = F_38 ( F_39 () ) ;
if ( ! V_161 )
goto V_169;
if ( V_163 <= V_161 ) {
V_66 = V_148 ;
goto V_169;
}
V_164 = V_163 - V_161 ;
if ( V_164 <= V_9 -> V_80 ) {
V_165 = F_64 (
V_52 -> V_114 -> V_115 ,
V_164 ) ;
if ( F_26 ( V_148 > V_165 ) )
V_66 = V_148 - V_165 ;
else
V_66 = 0 ;
} else {
V_164 = V_164 - V_9 -> V_80 ;
V_165 = F_64 (
V_52 -> V_114 -> V_115 ,
V_164 ) ;
V_166 = F_64 (
V_9 -> V_76 ,
V_164 ) ;
V_66 = V_81 + V_166 - V_165 ;
if ( F_13 ( V_66 > V_148 ) )
V_66 = V_148 ;
}
break;
default:
F_43 ( V_2 -> V_14 , L_8 ,
V_9 -> V_56 ) ;
break;
}
V_169:
return V_66 ;
}
static int F_68 ( struct V_99 * V_170 ,
int V_171 , unsigned int V_172 , int V_173 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_174 , V_175 ;
V_174 = F_1 ( V_2 , V_128 ) ;
V_175 = F_1 ( V_2 , V_134 ) ;
switch ( V_171 ) {
case V_176 :
V_174 |= V_177 ;
V_175 |= V_178 ;
break;
case V_179 :
V_174 &= ~ V_177 ;
V_175 &= ~ V_178 ;
break;
default:
F_6 ( V_2 -> V_14 , L_13 , V_171 ) ;
break;
}
V_9 -> V_116 = V_172 ;
F_2 ( V_2 , V_128 , V_174 ) ;
F_2 ( V_2 , V_134 , V_175 ) ;
return 0 ;
}
static int F_69 ( struct V_99 * V_170 ,
unsigned int V_180 )
{
struct V_1 * V_2 = V_170 -> V_2 ;
struct V_8 * V_9 = F_4 ( V_2 ) ;
T_1 V_111 , V_112 ;
V_111 = F_1 ( V_2 , V_117 ) ;
V_112 = F_1 ( V_2 , V_41 ) ;
switch ( V_180 & V_181 ) {
case V_182 :
V_111 |= ( V_183 | V_184 ) ;
break;
case V_185 :
if ( V_9 -> V_56 ) {
F_6 ( V_2 -> V_14 , L_14 ) ;
return - V_59 ;
} else
V_111 &= ~ ( V_183 | V_184 ) ;
break;
default:
return - V_59 ;
}
V_111 &= ~ V_186 ;
switch ( V_180 & V_187 ) {
case V_188 :
V_111 |= V_189 ;
break;
case V_190 :
V_111 |= V_191 ;
V_112 &= ~ V_192 ;
V_112 |= F_70 ( 0 ) ;
break;
case V_193 :
V_111 |= V_194 ;
break;
case V_195 :
V_111 |= V_196 ;
break;
default:
F_6 ( V_2 -> V_14 , L_15 ,
V_180 & V_187 ) ;
return - V_59 ;
}
F_2 ( V_2 , V_117 , V_111 ) ;
F_2 ( V_2 , V_41 , V_112 ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
int V_11 = 0 ;
V_2 -> V_13 = V_9 -> V_13 ;
V_2 -> V_16 = ( V_197 ) V_198 ;
V_9 -> V_2 = V_2 ;
V_11 = F_18 ( V_2 , 1 ) ;
if ( V_11 != 0 ) {
F_6 ( V_2 -> V_14 , L_16 , V_11 ) ;
goto V_199;
}
V_11 = F_15 ( V_2 ) ;
F_18 ( V_2 , 0 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_17 , V_11 ) ;
V_11 = - V_200 ;
goto V_199;
}
if ( V_9 -> V_92 >= 0 ) {
V_11 = F_72 ( V_9 -> V_92 , F_47 ,
V_201 ,
V_2 -> V_202 . V_203 , V_2 ) ;
if ( V_11 < 0 ) {
F_6 ( V_2 -> V_14 , L_18 ,
V_9 -> V_92 , V_11 ) ;
V_9 -> V_92 = - 1 ;
}
if ( V_9 -> V_92 != - 1 ) {
V_9 -> V_93 =
F_73 ( L_19 ) ;
if ( V_9 -> V_93 == NULL ) {
F_74 ( V_9 -> V_92 , V_2 ) ;
return - V_204 ;
}
F_75 ( & V_9 -> V_84 , F_45 ) ;
}
}
if ( V_9 -> V_92 >= 0 )
F_76 ( V_2 , V_205 ,
F_21 ( V_205 ) ) ;
V_199:
return V_11 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
if ( V_9 -> V_92 >= 0 ) {
F_74 ( V_9 -> V_92 , V_9 -> V_2 ) ;
F_78 ( V_9 -> V_93 ) ;
}
return 0 ;
}
static int F_79 ( struct V_206 * V_207 ,
const struct V_208 * V_209 )
{
struct V_210 * V_211 ;
struct V_8 * V_9 ;
int V_11 , V_33 ;
if ( V_207 -> V_14 . V_212 == NULL ) {
F_6 ( & V_207 -> V_14 , L_20 ) ;
return - V_200 ;
}
V_211 = V_207 -> V_14 . V_212 ;
V_9 = F_80 ( & V_207 -> V_14 , sizeof( struct V_8 ) ,
V_213 ) ;
if ( V_9 == NULL )
return - V_204 ;
V_9 -> V_13 = V_207 ;
F_81 ( & V_9 -> V_17 ) ;
F_82 ( & V_9 -> V_71 ) ;
F_83 ( V_207 , V_9 ) ;
V_9 -> V_44 = V_211 -> V_44 ;
V_9 -> V_105 = V_211 -> V_105 ;
V_9 -> V_144 = V_211 -> V_144 ;
V_9 -> V_152 = V_211 -> V_152 ;
if ( ! V_9 -> V_152 )
V_9 -> V_152 = 10000 ;
V_9 -> V_92 = V_207 -> V_92 ;
V_9 -> V_56 = V_168 ;
if ( V_9 -> V_44 >= 0 ) {
V_11 = F_84 ( V_9 -> V_44 , L_21 ) ;
if ( V_11 < 0 ) {
F_6 ( & V_207 -> V_14 ,
L_22 ,
V_9 -> V_44 ) ;
goto V_214;
}
F_85 ( V_9 -> V_44 , 0 ) ;
}
for ( V_33 = 0 ; V_33 < F_21 ( V_9 -> V_43 ) ; V_33 ++ )
V_9 -> V_43 [ V_33 ] . V_215 = V_216 [ V_33 ] ;
V_11 = F_86 ( & V_207 -> V_14 , F_21 ( V_9 -> V_43 ) ,
V_9 -> V_43 ) ;
if ( V_11 != 0 ) {
F_6 ( & V_207 -> V_14 , L_23 , V_11 ) ;
goto V_217;
}
V_11 = F_87 ( & V_207 -> V_14 ,
& V_218 , & V_219 , 1 ) ;
if ( V_11 < 0 )
goto V_217;
return V_11 ;
V_217:
if ( V_9 -> V_44 >= 0 )
F_88 ( V_9 -> V_44 ) ;
V_214:
return V_11 ;
}
static int F_89 ( struct V_206 * V_207 )
{
struct V_8 * V_9 = F_90 ( V_207 ) ;
if ( F_13 ( V_9 -> V_12 ) )
F_18 ( V_9 -> V_2 , 0 ) ;
if ( V_9 -> V_44 >= 0 )
F_88 ( V_9 -> V_44 ) ;
F_91 ( & V_207 -> V_14 ) ;
return 0 ;
}
