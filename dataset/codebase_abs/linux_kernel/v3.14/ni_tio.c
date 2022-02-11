static inline enum V_1 F_1 ( enum
V_2
V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
break;
case V_5 :
return V_6 ;
break;
case V_7 :
return V_8 ;
break;
default:
F_2 () ;
break;
}
return 0 ;
}
static inline enum V_1 F_3 ( enum
V_2
V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
break;
case V_5 :
return V_9 ;
break;
case V_7 :
return V_10 ;
break;
default:
F_2 () ;
break;
}
return 0 ;
}
static inline enum V_1 F_4 ( enum
V_2
V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
break;
case V_5 :
return V_11 ;
break;
case V_7 :
return V_12 ;
break;
default:
F_2 () ;
break;
}
return 0 ;
}
static inline enum V_1 F_5 ( enum
V_2
V_3 )
{
switch ( V_3 ) {
case V_4 :
return 0 ;
break;
case V_5 :
return V_13 ;
break;
case V_7 :
return V_14 ;
break;
default:
F_2 () ;
break;
}
return 0 ;
}
static inline unsigned F_6 ( unsigned V_15 )
{
F_7 ( V_15 > V_16 ) ;
return 0xb + V_15 ;
}
static inline unsigned F_8 ( unsigned V_15 )
{
F_7 ( V_15 > V_17 ) ;
return 0x2 + V_15 ;
}
static inline unsigned F_9 ( unsigned V_15 )
{
F_7 ( V_15 > V_18 ) ;
if ( V_15 < 10 )
return 1 + V_15 ;
else
return 0xb + V_15 ;
}
static inline unsigned F_10 ( unsigned V_15 )
{
F_7 ( V_15 > V_19 ) ;
if ( V_15 == 7 )
return 0x1b ;
else
return 0xb + V_15 ;
}
static inline unsigned F_11 ( unsigned V_15 )
{
F_7 ( V_15 > V_20 ) ;
return 0x2 + V_15 ;
}
static inline unsigned F_12 ( unsigned V_15 )
{
F_7 ( V_15 > V_16 ) ;
return 0xb + V_15 ;
}
static inline unsigned F_13 ( unsigned V_15 )
{
F_7 ( V_15 > V_19 ) ;
if ( V_15 == 7 )
return 0x1b ;
return 0xb + V_15 ;
}
static inline unsigned F_14 ( unsigned V_15 )
{
F_7 ( V_15 > V_18 ) ;
if ( V_15 < 10 )
return 1 + V_15 ;
return 0xb + V_15 ;
}
static inline unsigned F_15 ( unsigned V_21 )
{
return ( V_21 << V_22 ) & V_23 ;
}
static inline unsigned F_16 ( unsigned V_24 )
{
return ( V_24 << V_25 ) & V_26 ;
}
static inline unsigned F_17 ( unsigned V_15 )
{
F_7 ( V_15 > V_27 ) ;
return 0x2 + V_15 ;
}
static inline unsigned F_18 ( unsigned V_15 )
{
F_7 ( V_15 > V_16 ) ;
return 0xb + V_15 ;
}
struct V_28 * F_19 ( struct V_29 * V_30 ,
void (* F_20) ( struct
V_31
*
V_32 ,
unsigned
V_33 ,
enum
V_34
V_35 ) ,
unsigned (* F_21)
( struct V_31 * V_32 ,
enum V_34 V_35 ) ,
enum V_2 V_3 ,
unsigned V_36 )
{
unsigned V_37 ;
struct V_28 * V_38 =
F_22 ( sizeof( struct V_28 ) , V_39 ) ;
if ( V_38 == NULL )
return NULL ;
V_38 -> V_30 = V_30 ;
V_38 -> F_20 = F_20 ;
V_38 -> F_21 = F_21 ;
V_38 -> V_3 = V_3 ;
F_23 ( & V_38 -> V_40 ) ;
F_7 ( V_36 == 0 ) ;
V_38 -> V_41 =
F_22 ( sizeof( struct V_31 ) * V_36 , V_39 ) ;
if ( V_38 -> V_41 == NULL ) {
F_24 ( V_38 ) ;
return NULL ;
}
for ( V_37 = 0 ; V_37 < V_36 ; ++ V_37 ) {
V_38 -> V_41 [ V_37 ] . V_38 = V_38 ;
F_23 ( & V_38 -> V_41 [ V_37 ] . V_42 ) ;
}
V_38 -> V_36 = V_36 ;
return V_38 ;
}
void F_25 ( struct V_28 * V_38 )
{
if ( V_38 -> V_41 == NULL )
return;
F_24 ( V_38 -> V_41 ) ;
F_24 ( V_38 ) ;
}
static int F_26 ( const struct V_28
* V_38 )
{
switch ( V_38 -> V_3 ) {
case V_4 :
return 0 ;
break;
case V_5 :
case V_7 :
return 1 ;
break;
default:
F_2 () ;
break;
}
return 0 ;
}
static void F_27 ( struct V_31 * V_32 )
{
unsigned V_43 = V_32 -> V_44 ;
F_20 ( V_32 , F_28 ( V_43 ) , F_29 ( V_43 ) ) ;
}
void F_30 ( struct V_31 * V_32 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
F_27 ( V_32 ) ;
V_38 -> V_45 [ F_31 ( V_43 ) ] = 0x0 ;
F_20 ( V_32 , V_38 -> V_45 [ F_31 ( V_43 ) ] ,
F_31 ( V_43 ) ) ;
F_32 ( V_32 , F_33 ( V_43 ) ,
~ 0 , V_46 ) ;
F_32 ( V_32 , F_34 ( V_43 ) , ~ 0 , 0 ) ;
V_38 -> V_45 [ F_35 ( V_43 ) ] = 0x0 ;
F_20 ( V_32 , V_38 -> V_45 [ F_35 ( V_43 ) ] ,
F_35 ( V_43 ) ) ;
V_38 -> V_45 [ F_36 ( V_43 ) ] = 0x0 ;
F_20 ( V_32 , V_38 -> V_45 [ F_36 ( V_43 ) ] ,
F_36 ( V_43 ) ) ;
F_32 ( V_32 , F_37 ( V_43 ) , ~ 0 , 0 ) ;
if ( F_38 ( V_38 ) )
F_32 ( V_32 , F_39 ( V_43 ) , ~ 0 , 0 ) ;
if ( F_26 ( V_38 ) ) {
V_38 -> V_45 [ F_40 ( V_43 ) ] = 0x0 ;
F_20 ( V_32 ,
V_38 -> V_45 [ F_40 ( V_43 ) ] ,
F_40 ( V_43 ) ) ;
}
F_32 ( V_32 , F_41 ( V_43 ) , ~ 0 , 0x0 ) ;
F_32 ( V_32 , F_42 ( V_43 ) , ~ 0 , 0x0 ) ;
}
static unsigned int F_43 ( struct V_31 * V_32 )
{
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_33 = F_21 ( V_32 ,
F_44 ( V_43 ) ) ;
unsigned int V_47 = 0 ;
if ( V_33 & F_45 ( V_43 ) ) {
V_47 |= V_48 ;
if ( V_33 & F_46 ( V_43 ) )
V_47 |= V_49 ;
}
return V_47 ;
}
static void F_47 ( struct V_31 * V_32 , int V_50 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_51 = F_39 ( V_43 ) ;
static const T_1 V_52 = 25000 ;
const T_1 V_53 = F_48 ( V_32 ,
F_49
( V_32 ) ) ;
if ( F_38 ( V_38 ) == 0 )
return;
switch ( F_50 ( V_32 , V_51 ) & V_54 ) {
case V_55 :
case V_56 :
case V_57 :
case V_58 :
V_50 = 1 ;
break;
default:
break;
}
if ( V_50 ||
( V_53 && V_53 < V_52 ) ) {
F_32 ( V_32 , V_51 ,
F_1 ( V_38 -> V_3 ) ,
F_1 ( V_38 -> V_3 ) ) ;
} else {
F_32 ( V_32 , V_51 ,
F_1 ( V_38 -> V_3 ) ,
0x0 ) ;
}
}
static int F_51 ( struct V_31 * V_32 , unsigned V_59 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
unsigned V_60 ;
unsigned V_61 ;
unsigned V_62 = 0 ;
static const unsigned V_63 =
V_64 | V_65 |
V_66 | V_67 |
V_68 | V_69 |
V_70 | V_71 ;
V_60 = V_63 | V_72 ;
V_61 = V_59 & V_63 ;
switch ( V_59 & V_73 ) {
case V_74 :
break;
case V_75 :
V_61 |= V_72 ;
break;
case V_76 :
V_62 |= V_77 ;
V_60 |= V_78 ;
V_61 |= V_79 ;
break;
default:
break;
}
F_32 ( V_32 , F_34 ( V_43 ) ,
V_60 , V_61 ) ;
if ( F_38 ( V_38 ) ) {
unsigned V_80 = 0 ;
V_80 |=
( V_59 >> V_81 ) &
V_54 ;
V_80 |=
( ( V_59 >> V_82 ) <<
V_83 ) & V_84 ;
if ( V_59 & V_85 )
V_80 |= V_86 ;
F_32 ( V_32 , F_39 ( V_43 ) ,
V_54 | V_84 |
V_86 , V_80 ) ;
F_47 ( V_32 , 0 ) ;
}
F_32 ( V_32 , F_33 ( V_43 ) ,
V_87 ,
( V_59 >> V_88 ) <<
V_89 ) ;
if ( V_59 & V_90 )
V_62 |= V_91 ;
if ( V_59 & V_92 )
V_62 |= V_93 ;
F_32 ( V_32 , F_37 ( V_43 ) ,
V_77 | V_91 |
V_93 , V_62 ) ;
return 0 ;
}
int F_52 ( struct V_31 * V_32 , int V_94 , unsigned V_95 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
unsigned V_96 = 0 ;
if ( V_94 ) {
switch ( V_95 ) {
case V_97 :
V_96 |= V_98 ;
break;
case V_99 :
V_96 |= V_98 | V_100 ;
break;
default:
break;
}
if ( F_38 ( V_38 ) ) {
unsigned V_80 = 0 ;
switch ( V_95 ) {
case V_97 :
case V_99 :
break;
default:
if ( V_95 & V_101 ) {
unsigned V_102 =
( V_95 <<
V_103 ) &
F_5
( V_38 -> V_3 ) ;
V_80 |=
V_104 |
V_102 ;
} else {
return - V_105 ;
}
break;
}
F_32 ( V_32 , F_39 ( V_43 ) ,
F_5
( V_38 -> V_3 ) |
V_104 ,
V_80 ) ;
}
} else {
V_96 |= V_106 ;
}
F_53 ( V_32 , F_33 ( V_43 ) ,
0 , 0 , V_96 ) ;
return 0 ;
}
static unsigned F_54 ( unsigned int V_107 )
{
unsigned V_108 ;
unsigned V_37 ;
const unsigned V_109 =
V_107 & V_110 ;
switch ( V_109 ) {
case V_111 :
V_108 = V_112 ;
break;
case V_113 :
V_108 = V_114 ;
break;
case V_115 :
V_108 = V_116 ;
break;
case V_117 :
V_108 = V_118 ;
break;
case V_119 :
V_108 = V_120 ;
break;
case V_121 :
V_108 = V_122 ;
break;
case V_123 :
V_108 = V_124 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_109 == F_55 ( V_37 ) ) {
V_108 = F_6 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_17 ; ++ V_37 ) {
if ( V_109 ==
F_56 ( V_37 ) ) {
V_108 = F_8 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_17 )
break;
V_108 = 0 ;
F_2 () ;
break;
}
return F_15 ( V_108 ) ;
}
static unsigned F_57 ( unsigned int V_107 )
{
unsigned V_125 ;
unsigned V_37 ;
const unsigned V_109 =
V_107 & V_110 ;
switch ( V_109 ) {
case V_111 :
V_125 = V_126 ;
break;
case V_113 :
V_125 = V_127 ;
break;
case V_115 :
V_125 = V_128 ;
break;
case V_117 :
V_125 = V_129 ;
break;
case V_121 :
V_125 = V_130 ;
break;
case V_123 :
V_125 = V_131 ;
break;
case V_132 :
V_125 = V_133 ;
break;
case V_134 :
V_125 = V_135 ;
break;
case V_136 :
V_125 = V_137 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_19 ; ++ V_37 ) {
if ( V_109 == F_55 ( V_37 ) ) {
V_125 = F_10 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_19 )
break;
for ( V_37 = 0 ; V_37 <= V_18 ; ++ V_37 ) {
if ( V_109 == F_58 ( V_37 ) ) {
V_125 = F_9 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_18 )
break;
F_59 ( V_138 L_1 ,
( unsigned long ) V_107 ) ;
F_2 () ;
V_125 = 0 ;
break;
}
return F_15 ( V_125 ) ;
}
static void F_60 ( struct V_31 * V_32 ,
unsigned int V_107 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_139 = F_40 ( V_43 ) ;
if ( V_38 -> V_3 != V_5 )
return;
switch ( V_107 & V_110 ) {
case V_121 :
case V_115 :
V_38 -> V_45 [ V_139 ] &= ~ V_140 ;
break;
case V_136 :
case V_134 :
V_38 -> V_45 [ V_139 ] |= V_140 ;
break;
default:
return;
break;
}
F_20 ( V_32 , V_38 -> V_45 [ V_139 ] ,
V_139 ) ;
}
static int F_61 ( struct V_31 * V_32 ,
unsigned int V_107 ,
unsigned int V_141 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
unsigned V_62 = 0 ;
static const T_1 V_142 = 1000 ;
switch ( V_38 -> V_3 ) {
case V_7 :
V_62 |= F_54 ( V_107 ) ;
break;
case V_4 :
case V_5 :
V_62 |=
F_57 ( V_107 ) ;
break;
default:
F_2 () ;
break;
}
if ( V_107 & V_143 )
V_62 |= V_144 ;
F_32 ( V_32 , F_37 ( V_43 ) ,
V_23 | V_144 ,
V_62 ) ;
F_60 ( V_32 , V_107 ) ;
if ( F_38 ( V_38 ) ) {
const unsigned V_145 =
V_107 & V_146 ;
unsigned V_80 = 0 ;
switch ( V_145 ) {
case V_147 :
break;
case V_148 :
V_80 |=
F_3 ( V_38 -> V_3 ) ;
break;
case V_149 :
V_80 |=
F_4 ( V_38 -> V_3 ) ;
break;
default:
return - V_105 ;
break;
}
F_32 ( V_32 , F_39 ( V_43 ) ,
F_3 ( V_38 -> V_3 ) |
F_4 ( V_38 -> V_3 ) ,
V_80 ) ;
}
V_32 -> V_53 = V_142 * V_141 ;
F_47 ( V_32 , 0 ) ;
return 0 ;
}
static unsigned F_62 ( const struct V_31 * V_32 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_80 =
F_50 ( V_32 , F_39 ( V_43 ) ) ;
unsigned V_33 = 0 ;
if ( F_50 ( V_32 , F_37 ( V_43 ) ) &
V_144 )
V_33 |= V_143 ;
if ( V_80 & F_3 ( V_38 -> V_3 ) )
V_33 |= V_148 ;
if ( V_80 & F_4 ( V_38 -> V_3 ) )
V_33 |= V_149 ;
return V_33 ;
}
static unsigned F_63 ( const struct V_31 * V_32 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_139 = F_40 ( V_43 ) ;
unsigned V_107 = 0 ;
unsigned V_37 ;
const unsigned V_150 =
( F_50 ( V_32 , F_37 ( V_43 ) ) &
V_23 ) >> V_22 ;
switch ( V_150 ) {
case V_126 :
V_107 = V_111 ;
break;
case V_127 :
V_107 = V_113 ;
break;
case V_128 :
if ( V_38 -> V_45 [ V_139 ] &
V_140 )
V_107 =
V_136 ;
else
V_107 = V_115 ;
break;
case V_129 :
V_107 = V_117 ;
break;
case V_130 :
if ( V_38 -> V_45 [ V_139 ] &
V_140 )
V_107 = V_134 ;
else
V_107 = V_121 ;
break;
case V_133 :
V_107 = V_132 ;
break;
case V_131 :
V_107 = V_123 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_19 ; ++ V_37 ) {
if ( V_150 == F_10 ( V_37 ) ) {
V_107 = F_55 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_19 )
break;
for ( V_37 = 0 ; V_37 <= V_18 ; ++ V_37 ) {
if ( V_150 == F_9 ( V_37 ) ) {
V_107 = F_58 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_18 )
break;
F_2 () ;
break;
}
V_107 |= F_62 ( V_32 ) ;
return V_107 ;
}
static unsigned F_64 ( const struct V_31 * V_32 )
{
unsigned V_107 = 0 ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_150 =
( F_50 ( V_32 , F_37 ( V_43 ) ) &
V_23 ) >> V_22 ;
unsigned V_37 ;
switch ( V_150 ) {
case V_112 :
V_107 = V_111 ;
break;
case V_114 :
V_107 = V_113 ;
break;
case V_116 :
V_107 = V_115 ;
break;
case V_118 :
V_107 = V_117 ;
break;
case V_120 :
V_107 = V_119 ;
break;
case V_122 :
V_107 = V_121 ;
break;
case V_124 :
V_107 = V_123 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_150 == F_6 ( V_37 ) ) {
V_107 = F_55 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_17 ; ++ V_37 ) {
if ( V_150 == F_8 ( V_37 ) ) {
V_107 =
F_56 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_17 )
break;
F_2 () ;
break;
}
V_107 |= F_62 ( V_32 ) ;
return V_107 ;
}
static unsigned F_49 ( const struct V_31 * V_32 )
{
switch ( V_32 -> V_38 -> V_3 ) {
case V_4 :
case V_5 :
return F_63 ( V_32 ) ;
break;
case V_7 :
return F_64 ( V_32 ) ;
break;
default:
F_2 () ;
break;
}
return 0 ;
}
static T_1 F_48 ( const struct V_31 * V_32 ,
unsigned V_151 )
{
T_1 V_53 ;
switch ( V_151 & V_110 ) {
case V_111 :
V_53 = 50000 ;
break;
case V_113 :
V_53 = 10000000 ;
break;
case V_115 :
V_53 = 12500 ;
break;
case V_132 :
V_53 = 100000 ;
break;
default:
return V_32 -> V_53 ;
break;
}
switch ( V_151 & V_146 ) {
case V_147 :
break;
case V_148 :
V_53 *= 2 ;
break;
case V_149 :
V_53 *= 8 ;
break;
default:
F_2 () ;
break;
}
return V_53 ;
}
static void F_65 ( struct V_31 * V_32 ,
unsigned int * V_107 ,
unsigned int * V_141 )
{
static const unsigned V_142 = 1000 ;
T_1 V_152 ;
* V_107 = F_49 ( V_32 ) ;
V_152 = F_48 ( V_32 , * V_107 ) ;
F_66 ( V_152 , V_142 ) ;
* V_141 = V_152 ;
}
static void F_67 ( struct V_31 * V_32 ,
unsigned int V_153 )
{
const unsigned V_154 = V_155 | V_78 ;
unsigned V_43 = V_32 -> V_44 ;
unsigned V_156 = 0 ;
if ( V_153 & V_157 )
V_156 |= V_155 ;
if ( V_153 & V_158 )
V_156 |= V_159 ;
else
V_156 |= V_79 ;
F_32 ( V_32 , F_34 ( V_43 ) ,
V_154 , V_156 ) ;
}
static int F_68 ( struct V_31 * V_32 ,
unsigned int V_153 )
{
const unsigned V_160 = F_69 ( V_153 ) ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_161 = 0x1f ;
unsigned V_162 ;
unsigned V_37 ;
switch ( V_160 ) {
case V_163 :
V_162 = V_164 ;
break;
case V_165 :
case V_166 :
case V_167 :
case V_168 :
V_162 = V_160 & V_161 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_160 == F_70 ( V_37 ) ) {
V_162 =
V_160 & V_161 ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_20 ; ++ V_37 ) {
if ( V_160 == F_71 ( V_37 ) ) {
V_162 =
V_160 & V_161 ;
break;
}
}
if ( V_37 <= V_20 )
break;
return - V_105 ;
break;
}
F_32 ( V_32 , F_37 ( V_43 ) ,
V_26 ,
F_16 ( V_162 ) ) ;
return 0 ;
}
static int F_72 ( struct V_31 * V_32 ,
unsigned int V_153 )
{
const unsigned V_160 = F_69 ( V_153 ) ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_161 = 0x1f ;
unsigned V_169 ;
unsigned V_37 ;
switch ( V_160 ) {
case V_170 :
case V_171 :
case V_172 :
case V_165 :
case V_173 :
case V_163 :
case V_174 :
case V_166 :
V_169 = V_160 & V_161 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_19 ; ++ V_37 ) {
if ( V_160 == F_70 ( V_37 ) ) {
V_169 =
V_160 & V_161 ;
break;
}
}
if ( V_37 <= V_19 )
break;
for ( V_37 = 0 ; V_37 <= V_18 ; ++ V_37 ) {
if ( V_160 == F_73 ( V_37 ) ) {
V_169 =
V_160 & V_161 ;
break;
}
}
if ( V_37 <= V_18 )
break;
return - V_105 ;
break;
}
F_32 ( V_32 , F_37 ( V_43 ) ,
V_26 ,
F_16 ( V_169 ) ) ;
return 0 ;
}
static int F_74 ( struct V_31 * V_32 ,
unsigned int V_153 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_139 = F_40 ( V_43 ) ;
const unsigned V_175 = F_69 ( V_153 ) ;
static const unsigned V_176 = 0x1f ;
unsigned V_177 ;
unsigned V_37 ;
switch ( V_175 ) {
case V_167 :
case V_178 :
case V_179 :
case V_165 :
case V_166 :
V_177 =
V_175 & V_176 ;
break;
case V_163 :
V_177 =
V_180 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_175 == F_70 ( V_37 ) ) {
V_177 =
V_175 &
V_176 ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_27 ; ++ V_37 ) {
if ( V_175 ==
F_75 ( V_37 ) ) {
V_177 =
V_175 &
V_176 ;
break;
}
}
if ( V_37 <= V_27 )
break;
return - V_105 ;
break;
}
V_38 -> V_45 [ V_139 ] |= V_181 ;
V_38 -> V_45 [ V_139 ] &= ~ V_182 ;
V_38 -> V_45 [ V_139 ] |=
F_76 ( V_177 ) ;
F_20 ( V_32 , V_38 -> V_45 [ V_139 ] ,
V_139 ) ;
return 0 ;
}
static int F_77 ( struct V_31 * V_32 ,
unsigned int V_153 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_139 = F_40 ( V_43 ) ;
const unsigned V_175 = F_69 ( V_153 ) ;
static const unsigned V_176 = 0x1f ;
unsigned V_183 ;
switch ( V_175 ) {
default:
V_183 =
V_175 & V_176 ;
break;
}
V_38 -> V_45 [ V_139 ] |= V_181 ;
V_38 -> V_45 [ V_139 ] &= ~ V_182 ;
V_38 -> V_45 [ V_139 ] |=
F_76 ( V_183 ) ;
F_20 ( V_32 , V_38 -> V_45 [ V_139 ] ,
V_139 ) ;
return 0 ;
}
int F_78 ( struct V_31 * V_32 , unsigned V_184 ,
unsigned int V_153 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_139 = F_40 ( V_43 ) ;
switch ( V_184 ) {
case 0 :
if ( F_69 ( V_153 ) == V_185 ) {
F_32 ( V_32 , F_34 ( V_43 ) ,
V_78 ,
V_186 ) ;
return 0 ;
}
F_67 ( V_32 , V_153 ) ;
switch ( V_38 -> V_3 ) {
case V_4 :
case V_5 :
return F_72 ( V_32 , V_153 ) ;
break;
case V_7 :
return F_68 ( V_32 , V_153 ) ;
break;
default:
F_2 () ;
break;
}
break;
case 1 :
if ( F_26 ( V_38 ) == 0 )
return - V_105 ;
if ( F_69 ( V_153 ) == V_185 ) {
V_38 -> V_45 [ V_139 ] &=
~ V_181 ;
F_20 ( V_32 ,
V_38 -> V_45 [ V_139 ] ,
V_139 ) ;
return 0 ;
}
if ( V_153 & V_157 ) {
V_38 -> V_45 [ V_139 ] |=
V_187 ;
} else {
V_38 -> V_45 [ V_139 ] &=
~ V_187 ;
}
switch ( V_38 -> V_3 ) {
case V_5 :
return F_77 ( V_32 ,
V_153 ) ;
break;
case V_7 :
return F_74 ( V_32 , V_153 ) ;
break;
default:
F_2 () ;
break;
}
break;
default:
return - V_105 ;
break;
}
return 0 ;
}
static int F_79 ( struct V_31 * V_32 , unsigned V_188 ,
unsigned int V_21 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
if ( V_38 -> V_3 == V_5 ) {
unsigned int V_189 , V_190 , V_191 ;
V_189 = F_80 ( V_43 ) ;
switch ( V_188 ) {
case V_192 :
V_190 = 10 ;
break;
case V_193 :
V_190 = 5 ;
break;
case V_194 :
V_190 = 0 ;
break;
default:
return - V_105 ;
break;
}
V_191 = 0x1f << V_190 ;
if ( V_21 > 0x1f ) {
V_21 = 0x1f ;
}
V_38 -> V_45 [ V_189 ] &= ~ V_191 ;
V_38 -> V_45 [ V_189 ] |= ( V_21 << V_190 ) & V_191 ;
F_20 ( V_32 , V_38 -> V_45 [ V_189 ] , V_189 ) ;
return 0 ;
}
return - V_105 ;
}
static unsigned F_81 ( unsigned
V_162 )
{
unsigned V_37 ;
switch ( V_162 ) {
case V_195 :
return V_167 ;
break;
case V_196 :
return V_168 ;
break;
case V_164 :
return V_163 ;
break;
case V_197 :
return V_165 ;
break;
case V_198 :
return V_166 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_162 == F_12 ( V_37 ) ) {
return F_70 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_20 ; ++ V_37 ) {
if ( V_162 ==
F_11 ( V_37 ) ) {
return F_71 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_20 )
break;
F_2 () ;
break;
}
return 0 ;
}
static unsigned F_82 ( unsigned
V_169 )
{
unsigned V_37 ;
switch ( V_169 ) {
case V_199 :
return V_170 ;
break;
case V_200 :
return V_171 ;
break;
case V_201 :
return V_172 ;
break;
case V_202 :
return V_165 ;
break;
case V_203 :
return V_173 ;
break;
case V_204 :
return V_163 ;
break;
case V_205 :
return V_174 ;
break;
case V_206 :
return V_166 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_19 ; ++ V_37 ) {
if ( V_169 ==
F_13 ( V_37 ) ) {
return F_70 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_19 )
break;
for ( V_37 = 0 ; V_37 <= V_18 ; ++ V_37 ) {
if ( V_169 ==
F_14 ( V_37 ) ) {
return F_73 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_18 )
break;
F_2 () ;
break;
}
return 0 ;
}
static unsigned F_83 ( unsigned
V_162 )
{
unsigned V_37 ;
switch ( V_162 ) {
case V_207 :
return V_167 ;
break;
case V_208 :
return V_178 ;
break;
case V_180 :
return V_163 ;
break;
case V_209 :
return V_165 ;
break;
case V_210 :
return V_179 ;
break;
case V_211 :
return V_166 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_162 ==
F_18 ( V_37 ) ) {
return F_70 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_27 ; ++ V_37 ) {
if ( V_162 ==
F_17 ( V_37 ) ) {
return F_75 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_27 )
break;
F_2 () ;
break;
}
return 0 ;
}
static unsigned F_84 ( unsigned
V_169 )
{
switch ( V_169 ) {
default:
return V_169 ;
break;
}
return 0 ;
}
static int F_85 ( struct V_31 * V_32 , unsigned V_184 ,
unsigned int * V_153 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_212 =
F_50 ( V_32 , F_34 ( V_43 ) ) ;
const unsigned V_139 = F_40 ( V_43 ) ;
unsigned V_213 ;
switch ( V_184 ) {
case 0 :
if ( ( V_212 & V_78 ) ==
V_186 ) {
* V_153 = V_185 ;
return 0 ;
} else {
V_213 =
( F_50 ( V_32 ,
F_37 ( V_43 ) ) &
V_26 ) >> V_25 ;
}
switch ( V_38 -> V_3 ) {
case V_4 :
case V_5 :
* V_153 =
F_82
( V_213 ) ;
break;
case V_7 :
* V_153 =
F_81
( V_213 ) ;
break;
default:
F_2 () ;
break;
}
if ( V_212 & V_155 )
* V_153 |= V_157 ;
if ( ( V_212 & V_78 ) != V_79 )
* V_153 |= V_158 ;
break;
case 1 :
if ( ( V_212 & V_78 ) == V_186
|| ( V_38 -> V_45 [ V_139 ] &
V_181 )
== 0 ) {
* V_153 = V_185 ;
return 0 ;
} else {
V_213 =
( V_38 -> V_45 [ V_139 ] &
V_182 ) >>
V_214 ;
}
switch ( V_38 -> V_3 ) {
case V_4 :
case V_5 :
* V_153 =
F_84
( V_213 ) ;
break;
case V_7 :
* V_153 =
F_83
( V_213 ) ;
break;
default:
F_2 () ;
break;
}
if ( V_38 -> V_45 [ V_139 ] &
V_187 ) {
* V_153 |= V_157 ;
}
if ( ( V_212 & V_78 ) != V_79 )
* V_153 |= V_158 ;
break;
default:
return - V_105 ;
break;
}
return 0 ;
}
int F_86 ( struct V_29 * V_30 ,
struct V_215 * V_216 ,
struct V_217 * V_218 ,
unsigned int * V_219 )
{
struct V_31 * V_32 = V_216 -> V_220 ;
switch ( V_219 [ 0 ] ) {
case V_221 :
return F_51 ( V_32 , V_219 [ 1 ] ) ;
break;
case V_222 :
return F_52 ( V_32 , 1 , V_219 [ 1 ] ) ;
break;
case V_223 :
F_52 ( V_32 , 0 , 0 ) ;
return 0 ;
break;
case V_224 :
V_219 [ 1 ] = F_43 ( V_32 ) ;
V_219 [ 2 ] = V_225 ;
return 0 ;
break;
case V_226 :
return F_61 ( V_32 , V_219 [ 1 ] , V_219 [ 2 ] ) ;
break;
case V_227 :
F_65 ( V_32 , & V_219 [ 1 ] , & V_219 [ 2 ] ) ;
return 0 ;
break;
case V_228 :
return F_78 ( V_32 , V_219 [ 1 ] , V_219 [ 2 ] ) ;
break;
case V_229 :
return F_85 ( V_32 , V_219 [ 1 ] , & V_219 [ 2 ] ) ;
break;
case V_230 :
return F_79 ( V_32 , V_219 [ 1 ] , V_219 [ 2 ] ) ;
break;
case V_231 :
F_27 ( V_32 ) ;
return 0 ;
break;
default:
break;
}
return - V_105 ;
}
int F_87 ( struct V_29 * V_30 ,
struct V_215 * V_216 ,
struct V_217 * V_218 ,
unsigned int * V_219 )
{
struct V_31 * V_32 = V_216 -> V_220 ;
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_232 = F_69 ( V_218 -> V_233 ) ;
unsigned V_43 = V_32 -> V_44 ;
unsigned V_234 ;
unsigned V_235 ;
unsigned V_236 ;
if ( V_218 -> V_15 < 1 )
return 0 ;
switch ( V_232 ) {
case 0 :
F_32 ( V_32 , F_33 ( V_43 ) ,
V_237 , 0 ) ;
F_32 ( V_32 , F_33 ( V_43 ) ,
V_237 , V_237 ) ;
V_234 = F_21 ( V_32 , F_88 ( V_43 ) ) ;
V_235 = F_21 ( V_32 , F_88 ( V_43 ) ) ;
if ( V_234 != V_235 )
V_236 =
F_21 ( V_32 , F_88 ( V_43 ) ) ;
else
V_236 = V_234 ;
V_219 [ 0 ] = V_236 ;
return 0 ;
break;
case 1 :
V_219 [ 0 ] = V_38 -> V_45 [ F_35 ( V_43 ) ] ;
break;
case 2 :
V_219 [ 0 ] = V_38 -> V_45 [ F_36 ( V_43 ) ] ;
break;
}
return 0 ;
}
static unsigned F_89 ( struct V_31 * V_32 )
{
unsigned V_43 = V_32 -> V_44 ;
const unsigned V_33 =
F_21 ( V_32 , F_44 ( V_43 ) ) ;
if ( V_33 & F_90 ( V_43 ) )
return F_36 ( V_43 ) ;
else
return F_35 ( V_43 ) ;
}
int F_91 ( struct V_29 * V_30 ,
struct V_215 * V_216 ,
struct V_217 * V_218 ,
unsigned int * V_219 )
{
struct V_31 * V_32 = V_216 -> V_220 ;
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_232 = F_69 ( V_218 -> V_233 ) ;
unsigned V_43 = V_32 -> V_44 ;
unsigned V_238 ;
if ( V_218 -> V_15 < 1 )
return 0 ;
switch ( V_232 ) {
case 0 :
V_238 = F_89 ( V_32 ) ;
F_20 ( V_32 , V_219 [ 0 ] , V_238 ) ;
F_53 ( V_32 , F_33 ( V_43 ) ,
0 , 0 , V_239 ) ;
F_20 ( V_32 , V_38 -> V_45 [ V_238 ] , V_238 ) ;
break;
case 1 :
V_38 -> V_45 [ F_35 ( V_43 ) ] = V_219 [ 0 ] ;
F_20 ( V_32 , V_219 [ 0 ] , F_35 ( V_43 ) ) ;
break;
case 2 :
V_38 -> V_45 [ F_36 ( V_43 ) ] = V_219 [ 0 ] ;
F_20 ( V_32 , V_219 [ 0 ] , F_36 ( V_43 ) ) ;
break;
default:
return - V_105 ;
break;
}
return 0 ;
}
static int T_2 F_92 ( void )
{
return 0 ;
}
static void T_3 F_93 ( void )
{
}
