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
static int T_1 F_19 ( void )
{
return 0 ;
}
static void T_2 F_20 ( void )
{
}
struct V_28 * F_21 ( struct V_29 * V_30 ,
void (* F_22) ( struct
V_31
*
V_32 ,
unsigned
V_33 ,
enum
V_34
V_35 ) ,
unsigned (* F_23)
( struct V_31 * V_32 ,
enum V_34 V_35 ) ,
enum V_2 V_3 ,
unsigned V_36 )
{
unsigned V_37 ;
struct V_28 * V_38 =
F_24 ( sizeof( struct V_28 ) , V_39 ) ;
if ( V_38 == NULL )
return NULL ;
V_38 -> V_30 = V_30 ;
V_38 -> F_22 = F_22 ;
V_38 -> F_23 = F_23 ;
V_38 -> V_3 = V_3 ;
F_25 ( & V_38 -> V_40 ) ;
F_7 ( V_36 == 0 ) ;
V_38 -> V_41 =
F_24 ( sizeof( struct V_31 ) * V_36 , V_39 ) ;
if ( V_38 -> V_41 == NULL ) {
F_26 ( V_38 ) ;
return NULL ;
}
for ( V_37 = 0 ; V_37 < V_36 ; ++ V_37 ) {
V_38 -> V_41 [ V_37 ] . V_38 = V_38 ;
F_25 ( & V_38 -> V_41 [ V_37 ] . V_42 ) ;
}
V_38 -> V_36 = V_36 ;
return V_38 ;
}
void F_27 ( struct V_28 * V_38 )
{
if ( V_38 -> V_41 == NULL )
return;
F_26 ( V_38 -> V_41 ) ;
F_26 ( V_38 ) ;
}
static int F_28 ( const struct V_28
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
static void F_29 ( struct V_31 * V_32 )
{
F_22 ( V_32 , F_30 ( V_32 -> V_43 ) ,
F_31 ( V_32 -> V_43 ) ) ;
}
void F_32 ( struct V_31 * V_32 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
F_29 ( V_32 ) ;
V_38 -> V_44 [ F_33 ( V_32 -> V_43 ) ] =
0x0 ;
F_22 ( V_32 ,
V_38 ->
V_44 [ F_33 ( V_32 -> V_43 ) ] ,
F_33 ( V_32 -> V_43 ) ) ;
F_34 ( V_32 , F_35 ( V_32 -> V_43 ) ,
~ 0 , V_45 ) ;
F_34 ( V_32 , F_36 ( V_32 -> V_43 ) , ~ 0 ,
0 ) ;
V_38 -> V_44 [ F_37 ( V_32 -> V_43 ) ] = 0x0 ;
F_22 ( V_32 ,
V_38 ->
V_44 [ F_37 ( V_32 -> V_43 ) ] ,
F_37 ( V_32 -> V_43 ) ) ;
V_38 -> V_44 [ F_38 ( V_32 -> V_43 ) ] = 0x0 ;
F_22 ( V_32 ,
V_38 ->
V_44 [ F_38 ( V_32 -> V_43 ) ] ,
F_38 ( V_32 -> V_43 ) ) ;
F_34 ( V_32 ,
F_39 ( V_32 -> V_43 ) , ~ 0 ,
0 ) ;
if ( F_40 ( V_38 ) ) {
F_34 ( V_32 ,
F_41 ( V_32 ->
V_43 ) , ~ 0 ,
0 ) ;
}
if ( F_28 ( V_38 ) ) {
V_38 ->
V_44 [ F_42 ( V_32 -> V_43 ) ] =
0x0 ;
F_22 ( V_32 ,
V_38 ->
V_44 [ F_42
( V_32 -> V_43 ) ] ,
F_42 ( V_32 ->
V_43 ) ) ;
}
F_34 ( V_32 ,
F_43 ( V_32 -> V_43 ) , ~ 0 ,
0x0 ) ;
F_34 ( V_32 ,
F_44 ( V_32 -> V_43 ) ,
~ 0 , 0x0 ) ;
}
static unsigned int F_45 ( struct V_31 * V_32 )
{
unsigned int V_46 = 0 ;
const unsigned V_33 = F_23 ( V_32 ,
F_46 ( V_32 ->
V_43 ) ) ;
if ( V_33 & F_47 ( V_32 -> V_43 ) ) {
V_46 |= V_47 ;
if ( V_33 & F_48 ( V_32 -> V_43 ) )
V_46 |= V_48 ;
}
return V_46 ;
}
static void F_49 ( struct V_31 * V_32 , int V_49 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_50 =
F_41 ( V_32 -> V_43 ) ;
static const T_3 V_51 = 25000 ;
const T_3 V_52 = F_50 ( V_32 ,
F_51
( V_32 ) ) ;
if ( F_40 ( V_38 ) == 0 )
return;
switch ( F_52 ( V_32 , V_50 ) & V_53 ) {
case V_54 :
case V_55 :
case V_56 :
case V_57 :
V_49 = 1 ;
break;
default:
break;
}
if ( V_49 ||
( V_52 && V_52 < V_51 ) ) {
F_34 ( V_32 , V_50 ,
F_1 ( V_38 -> V_3 ) ,
F_1 ( V_38 -> V_3 ) ) ;
} else {
F_34 ( V_32 , V_50 ,
F_1 ( V_38 -> V_3 ) ,
0x0 ) ;
}
}
static int F_53 ( struct V_31 * V_32 , unsigned V_58 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_59 ;
unsigned V_60 ;
unsigned V_61 = 0 ;
static const unsigned V_62 =
V_63 | V_64 |
V_65 | V_66 |
V_67 | V_68 |
V_69 | V_70 ;
V_59 = V_62 | V_71 ;
V_60 = V_58 & V_62 ;
switch ( V_58 & V_72 ) {
case V_73 :
break;
case V_74 :
V_60 |= V_71 ;
break;
case V_75 :
V_61 |= V_76 ;
V_59 |= V_77 ;
V_60 |= V_78 ;
break;
default:
break;
}
F_34 ( V_32 , F_36 ( V_32 -> V_43 ) ,
V_59 , V_60 ) ;
if ( F_40 ( V_38 ) ) {
unsigned V_79 = 0 ;
V_79 |=
( V_58 >> V_80 ) &
V_53 ;
V_79 |=
( ( V_58 >> V_81 ) <<
V_82 ) & V_83 ;
if ( V_58 & V_84 )
V_79 |= V_85 ;
F_34 ( V_32 ,
F_41 ( V_32 ->
V_43 ) ,
V_53 | V_83 |
V_85 , V_79 ) ;
F_49 ( V_32 , 0 ) ;
}
F_34 ( V_32 , F_35 ( V_32 -> V_43 ) ,
V_86 ,
( V_58 >> V_87 ) <<
V_88 ) ;
if ( V_58 & V_89 )
V_61 |= V_90 ;
if ( V_58 & V_91 )
V_61 |= V_92 ;
F_34 ( V_32 ,
F_39 ( V_32 -> V_43 ) ,
V_76 | V_90 |
V_92 , V_61 ) ;
return 0 ;
}
int F_54 ( struct V_31 * V_32 , int V_93 , unsigned V_94 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_95 = 0 ;
if ( V_93 ) {
switch ( V_94 ) {
case V_96 :
V_95 |= V_97 ;
break;
case V_98 :
V_95 |= V_97 | V_99 ;
break;
default:
break;
}
if ( F_40 ( V_38 ) ) {
unsigned V_79 = 0 ;
switch ( V_94 ) {
case V_96 :
case V_98 :
break;
default:
if ( V_94 & V_100 ) {
unsigned V_101 =
( V_94 <<
V_102 ) &
F_5
( V_38 -> V_3 ) ;
V_79 |=
V_103 |
V_101 ;
} else {
return - V_104 ;
}
break;
}
F_34 ( V_32 ,
F_41
( V_32 -> V_43 ) ,
F_5
( V_38 -> V_3 ) |
V_103 ,
V_79 ) ;
}
} else {
V_95 |= V_105 ;
}
F_55 ( V_32 ,
F_35 ( V_32 -> V_43 ) ,
0 , 0 , V_95 ) ;
return 0 ;
}
static unsigned F_56 ( unsigned int V_106 )
{
unsigned V_107 ;
unsigned V_37 ;
const unsigned V_108 =
V_106 & V_109 ;
switch ( V_108 ) {
case V_110 :
V_107 = V_111 ;
break;
case V_112 :
V_107 = V_113 ;
break;
case V_114 :
V_107 = V_115 ;
break;
case V_116 :
V_107 = V_117 ;
break;
case V_118 :
V_107 = V_119 ;
break;
case V_120 :
V_107 = V_121 ;
break;
case V_122 :
V_107 = V_123 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_108 == F_57 ( V_37 ) ) {
V_107 = F_6 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_17 ; ++ V_37 ) {
if ( V_108 ==
F_58 ( V_37 ) ) {
V_107 = F_8 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_17 )
break;
V_107 = 0 ;
F_2 () ;
break;
}
return F_15 ( V_107 ) ;
}
static unsigned F_59 ( unsigned int V_106 )
{
unsigned V_124 ;
unsigned V_37 ;
const unsigned V_108 =
V_106 & V_109 ;
switch ( V_108 ) {
case V_110 :
V_124 = V_125 ;
break;
case V_112 :
V_124 = V_126 ;
break;
case V_114 :
V_124 = V_127 ;
break;
case V_116 :
V_124 = V_128 ;
break;
case V_120 :
V_124 = V_129 ;
break;
case V_122 :
V_124 = V_130 ;
break;
case V_131 :
V_124 = V_132 ;
break;
case V_133 :
V_124 = V_134 ;
break;
case V_135 :
V_124 = V_136 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_19 ; ++ V_37 ) {
if ( V_108 == F_57 ( V_37 ) ) {
V_124 = F_10 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_19 )
break;
for ( V_37 = 0 ; V_37 <= V_18 ; ++ V_37 ) {
if ( V_108 == F_60 ( V_37 ) ) {
V_124 = F_9 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_18 )
break;
F_61 ( V_137 L_1 ,
( unsigned long ) V_106 ) ;
F_2 () ;
V_124 = 0 ;
break;
}
return F_15 ( V_124 ) ;
}
static void F_62 ( struct V_31 * V_32 ,
unsigned int V_106 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_138 =
F_42 ( V_32 -> V_43 ) ;
if ( V_38 -> V_3 != V_5 )
return;
switch ( V_106 & V_109 ) {
case V_120 :
case V_114 :
V_38 -> V_44 [ V_138 ] &= ~ V_139 ;
break;
case V_135 :
case V_133 :
V_38 -> V_44 [ V_138 ] |= V_139 ;
break;
default:
return;
break;
}
F_22 ( V_32 , V_38 -> V_44 [ V_138 ] ,
V_138 ) ;
}
static int F_63 ( struct V_31 * V_32 ,
unsigned int V_106 ,
unsigned int V_140 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
unsigned V_61 = 0 ;
static const T_3 V_141 = 1000 ;
switch ( V_38 -> V_3 ) {
case V_7 :
V_61 |= F_56 ( V_106 ) ;
break;
case V_4 :
case V_5 :
V_61 |=
F_59 ( V_106 ) ;
break;
default:
F_2 () ;
break;
}
if ( V_106 & V_142 )
V_61 |= V_143 ;
F_34 ( V_32 ,
F_39 ( V_32 -> V_43 ) ,
V_23 | V_143 ,
V_61 ) ;
F_62 ( V_32 , V_106 ) ;
if ( F_40 ( V_38 ) ) {
const unsigned V_144 =
V_106 & V_145 ;
unsigned V_79 = 0 ;
switch ( V_144 ) {
case V_146 :
break;
case V_147 :
V_79 |=
F_3 ( V_38 -> V_3 ) ;
break;
case V_148 :
V_79 |=
F_4 ( V_38 -> V_3 ) ;
break;
default:
return - V_104 ;
break;
}
F_34 ( V_32 ,
F_41 ( V_32 ->
V_43 ) ,
F_3 ( V_38 -> V_3 ) |
F_4 ( V_38 -> V_3 ) ,
V_79 ) ;
}
V_32 -> V_52 = V_141 * V_140 ;
F_49 ( V_32 , 0 ) ;
return 0 ;
}
static unsigned F_64 ( const struct V_31 * V_32 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_79 = F_52 ( V_32 ,
F_41
( V_32 ->
V_43 ) ) ;
unsigned V_33 = 0 ;
if ( F_52 ( V_32 ,
F_39
( V_32 -> V_43 ) ) &
V_143 )
V_33 |= V_142 ;
if ( V_79 & F_3 ( V_38 -> V_3 ) )
V_33 |= V_147 ;
if ( V_79 & F_4 ( V_38 -> V_3 ) )
V_33 |= V_148 ;
return V_33 ;
}
static unsigned F_65 ( const struct V_31 * V_32 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_138 =
F_42 ( V_32 -> V_43 ) ;
unsigned V_106 = 0 ;
unsigned V_37 ;
const unsigned V_149 = ( F_52 ( V_32 ,
F_39
( V_32 -> V_43 ) )
& V_23 ) >>
V_22 ;
switch ( V_149 ) {
case V_125 :
V_106 = V_110 ;
break;
case V_126 :
V_106 = V_112 ;
break;
case V_127 :
if ( V_38 -> V_44 [ V_138 ] &
V_139 )
V_106 =
V_135 ;
else
V_106 = V_114 ;
break;
case V_128 :
V_106 = V_116 ;
break;
case V_129 :
if ( V_38 -> V_44 [ V_138 ] &
V_139 )
V_106 = V_133 ;
else
V_106 = V_120 ;
break;
case V_132 :
V_106 = V_131 ;
break;
case V_130 :
V_106 = V_122 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_19 ; ++ V_37 ) {
if ( V_149 == F_10 ( V_37 ) ) {
V_106 = F_57 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_19 )
break;
for ( V_37 = 0 ; V_37 <= V_18 ; ++ V_37 ) {
if ( V_149 == F_9 ( V_37 ) ) {
V_106 = F_60 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_18 )
break;
F_2 () ;
break;
}
V_106 |= F_64 ( V_32 ) ;
return V_106 ;
}
static unsigned F_66 ( const struct V_31 * V_32 )
{
unsigned V_106 = 0 ;
unsigned V_37 ;
const unsigned V_149 = ( F_52 ( V_32 ,
F_39
( V_32 -> V_43 ) )
& V_23 ) >>
V_22 ;
switch ( V_149 ) {
case V_111 :
V_106 = V_110 ;
break;
case V_113 :
V_106 = V_112 ;
break;
case V_115 :
V_106 = V_114 ;
break;
case V_117 :
V_106 = V_116 ;
break;
case V_119 :
V_106 = V_118 ;
break;
case V_121 :
V_106 = V_120 ;
break;
case V_123 :
V_106 = V_122 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_149 == F_6 ( V_37 ) ) {
V_106 = F_57 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_17 ; ++ V_37 ) {
if ( V_149 == F_8 ( V_37 ) ) {
V_106 =
F_58 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_17 )
break;
F_2 () ;
break;
}
V_106 |= F_64 ( V_32 ) ;
return V_106 ;
}
static unsigned F_51 ( const struct V_31 * V_32 )
{
switch ( V_32 -> V_38 -> V_3 ) {
case V_4 :
case V_5 :
return F_65 ( V_32 ) ;
break;
case V_7 :
return F_66 ( V_32 ) ;
break;
default:
F_2 () ;
break;
}
return 0 ;
}
static T_3 F_50 ( const struct V_31 * V_32 ,
unsigned V_150 )
{
T_3 V_52 ;
switch ( V_150 & V_109 ) {
case V_110 :
V_52 = 50000 ;
break;
case V_112 :
V_52 = 10000000 ;
break;
case V_114 :
V_52 = 12500 ;
break;
case V_131 :
V_52 = 100000 ;
break;
default:
return V_32 -> V_52 ;
break;
}
switch ( V_150 & V_145 ) {
case V_146 :
break;
case V_147 :
V_52 *= 2 ;
break;
case V_148 :
V_52 *= 8 ;
break;
default:
F_2 () ;
break;
}
return V_52 ;
}
static void F_67 ( struct V_31 * V_32 ,
unsigned int * V_106 ,
unsigned int * V_140 )
{
static const unsigned V_141 = 1000 ;
T_3 V_151 ;
* V_106 = F_51 ( V_32 ) ;
V_151 = F_50 ( V_32 , * V_106 ) ;
F_68 ( V_151 , V_141 ) ;
* V_140 = V_151 ;
}
static void F_69 ( struct V_31 * V_32 ,
unsigned int V_152 )
{
const unsigned V_153 = V_154 | V_77 ;
unsigned V_155 = 0 ;
if ( V_152 & V_156 )
V_155 |= V_154 ;
if ( V_152 & V_157 )
V_155 |= V_158 ;
else
V_155 |= V_78 ;
F_34 ( V_32 , F_36 ( V_32 -> V_43 ) ,
V_153 , V_155 ) ;
}
static int F_70 ( struct V_31 * V_32 ,
unsigned int V_152 )
{
const unsigned V_159 = F_71 ( V_152 ) ;
const unsigned V_160 = 0x1f ;
unsigned V_161 ;
unsigned V_37 ;
switch ( V_159 ) {
case V_162 :
V_161 = V_163 ;
break;
case V_164 :
case V_165 :
case V_166 :
case V_167 :
V_161 = V_159 & V_160 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_159 == F_72 ( V_37 ) ) {
V_161 =
V_159 & V_160 ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_20 ; ++ V_37 ) {
if ( V_159 == F_73 ( V_37 ) ) {
V_161 =
V_159 & V_160 ;
break;
}
}
if ( V_37 <= V_20 )
break;
return - V_104 ;
break;
}
F_34 ( V_32 ,
F_39 ( V_32 -> V_43 ) ,
V_26 ,
F_16 ( V_161 ) ) ;
return 0 ;
}
static int F_74 ( struct V_31 * V_32 ,
unsigned int V_152 )
{
const unsigned V_159 = F_71 ( V_152 ) ;
const unsigned V_160 = 0x1f ;
unsigned V_168 ;
unsigned V_37 ;
switch ( V_159 ) {
case V_169 :
case V_170 :
case V_171 :
case V_164 :
case V_172 :
case V_162 :
case V_173 :
case V_165 :
V_168 = V_159 & V_160 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_19 ; ++ V_37 ) {
if ( V_159 == F_72 ( V_37 ) ) {
V_168 =
V_159 & V_160 ;
break;
}
}
if ( V_37 <= V_19 )
break;
for ( V_37 = 0 ; V_37 <= V_18 ; ++ V_37 ) {
if ( V_159 == F_75 ( V_37 ) ) {
V_168 =
V_159 & V_160 ;
break;
}
}
if ( V_37 <= V_18 )
break;
return - V_104 ;
break;
}
F_34 ( V_32 ,
F_39 ( V_32 -> V_43 ) ,
V_26 ,
F_16 ( V_168 ) ) ;
return 0 ;
}
static int F_76 ( struct V_31 * V_32 ,
unsigned int V_152 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_138 =
F_42 ( V_32 -> V_43 ) ;
const unsigned V_174 = F_71 ( V_152 ) ;
static const unsigned V_175 = 0x1f ;
unsigned V_176 ;
unsigned V_37 ;
switch ( V_174 ) {
case V_166 :
case V_177 :
case V_178 :
case V_164 :
case V_165 :
V_176 =
V_174 & V_175 ;
break;
case V_162 :
V_176 =
V_179 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_174 == F_72 ( V_37 ) ) {
V_176 =
V_174 &
V_175 ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_27 ; ++ V_37 ) {
if ( V_174 ==
F_77 ( V_37 ) ) {
V_176 =
V_174 &
V_175 ;
break;
}
}
if ( V_37 <= V_27 )
break;
return - V_104 ;
break;
}
V_38 -> V_44 [ V_138 ] |= V_180 ;
V_38 -> V_44 [ V_138 ] &= ~ V_181 ;
V_38 -> V_44 [ V_138 ] |=
F_78 ( V_176 ) ;
F_22 ( V_32 , V_38 -> V_44 [ V_138 ] ,
V_138 ) ;
return 0 ;
}
static int F_79 ( struct V_31 * V_32 ,
unsigned int V_152 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_138 =
F_42 ( V_32 -> V_43 ) ;
const unsigned V_174 = F_71 ( V_152 ) ;
static const unsigned V_175 = 0x1f ;
unsigned V_182 ;
switch ( V_174 ) {
default:
V_182 =
V_174 & V_175 ;
break;
}
V_38 -> V_44 [ V_138 ] |= V_180 ;
V_38 -> V_44 [ V_138 ] &= ~ V_181 ;
V_38 -> V_44 [ V_138 ] |=
F_78 ( V_182 ) ;
F_22 ( V_32 , V_38 -> V_44 [ V_138 ] ,
V_138 ) ;
return 0 ;
}
int F_80 ( struct V_31 * V_32 , unsigned V_183 ,
unsigned int V_152 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_138 =
F_42 ( V_32 -> V_43 ) ;
switch ( V_183 ) {
case 0 :
if ( F_71 ( V_152 ) == V_184 ) {
F_34 ( V_32 ,
F_36 ( V_32 ->
V_43 ) ,
V_77 ,
V_185 ) ;
return 0 ;
}
F_69 ( V_32 , V_152 ) ;
switch ( V_38 -> V_3 ) {
case V_4 :
case V_5 :
return F_74 ( V_32 , V_152 ) ;
break;
case V_7 :
return F_70 ( V_32 , V_152 ) ;
break;
default:
F_2 () ;
break;
}
break;
case 1 :
if ( F_28 ( V_38 ) == 0 )
return - V_104 ;
if ( F_71 ( V_152 ) == V_184 ) {
V_38 -> V_44 [ V_138 ] &=
~ V_180 ;
F_22 ( V_32 ,
V_38 -> V_44 [ V_138 ] ,
V_138 ) ;
return 0 ;
}
if ( V_152 & V_156 ) {
V_38 -> V_44 [ V_138 ] |=
V_186 ;
} else {
V_38 -> V_44 [ V_138 ] &=
~ V_186 ;
}
switch ( V_38 -> V_3 ) {
case V_5 :
return F_79 ( V_32 ,
V_152 ) ;
break;
case V_7 :
return F_76 ( V_32 , V_152 ) ;
break;
default:
F_2 () ;
break;
}
break;
default:
return - V_104 ;
break;
}
return 0 ;
}
static int F_81 ( struct V_31 * V_32 , unsigned V_187 ,
unsigned int V_21 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
if ( V_38 -> V_3 == V_5 ) {
unsigned int V_188 , V_189 , V_190 ;
V_188 = F_82 ( V_32 -> V_43 ) ;
switch ( V_187 ) {
case V_191 :
V_189 = 10 ;
break;
case V_192 :
V_189 = 5 ;
break;
case V_193 :
V_189 = 0 ;
break;
default:
return - V_104 ;
break;
}
V_190 = 0x1f << V_189 ;
if ( V_21 > 0x1f ) {
V_21 = 0x1f ;
}
V_38 -> V_44 [ V_188 ] &= ~ V_190 ;
V_38 -> V_44 [ V_188 ] |= ( V_21 << V_189 ) & V_190 ;
F_22 ( V_32 , V_38 -> V_44 [ V_188 ] , V_188 ) ;
return 0 ;
}
return - V_104 ;
}
static unsigned F_83 ( unsigned
V_161 )
{
unsigned V_37 ;
switch ( V_161 ) {
case V_194 :
return V_166 ;
break;
case V_195 :
return V_167 ;
break;
case V_163 :
return V_162 ;
break;
case V_196 :
return V_164 ;
break;
case V_197 :
return V_165 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_161 == F_12 ( V_37 ) ) {
return F_72 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_20 ; ++ V_37 ) {
if ( V_161 ==
F_11 ( V_37 ) ) {
return F_73 ( V_37 ) ;
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
static unsigned F_84 ( unsigned
V_168 )
{
unsigned V_37 ;
switch ( V_168 ) {
case V_198 :
return V_169 ;
break;
case V_199 :
return V_170 ;
break;
case V_200 :
return V_171 ;
break;
case V_201 :
return V_164 ;
break;
case V_202 :
return V_172 ;
break;
case V_203 :
return V_162 ;
break;
case V_204 :
return V_173 ;
break;
case V_205 :
return V_165 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_19 ; ++ V_37 ) {
if ( V_168 ==
F_13 ( V_37 ) ) {
return F_72 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_19 )
break;
for ( V_37 = 0 ; V_37 <= V_18 ; ++ V_37 ) {
if ( V_168 ==
F_14 ( V_37 ) ) {
return F_75 ( V_37 ) ;
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
static unsigned F_85 ( unsigned
V_161 )
{
unsigned V_37 ;
switch ( V_161 ) {
case V_206 :
return V_166 ;
break;
case V_207 :
return V_177 ;
break;
case V_179 :
return V_162 ;
break;
case V_208 :
return V_164 ;
break;
case V_209 :
return V_178 ;
break;
case V_210 :
return V_165 ;
break;
default:
for ( V_37 = 0 ; V_37 <= V_16 ; ++ V_37 ) {
if ( V_161 ==
F_18 ( V_37 ) ) {
return F_72 ( V_37 ) ;
break;
}
}
if ( V_37 <= V_16 )
break;
for ( V_37 = 0 ; V_37 <= V_27 ; ++ V_37 ) {
if ( V_161 ==
F_17 ( V_37 ) ) {
return F_77 ( V_37 ) ;
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
static unsigned F_86 ( unsigned
V_168 )
{
switch ( V_168 ) {
default:
return V_168 ;
break;
}
return 0 ;
}
static int F_87 ( struct V_31 * V_32 , unsigned V_183 ,
unsigned int * V_152 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_211 = F_52 ( V_32 ,
F_36
( V_32 ->
V_43 ) ) ;
const unsigned V_138 =
F_42 ( V_32 -> V_43 ) ;
unsigned V_212 ;
switch ( V_183 ) {
case 0 :
if ( ( V_211 & V_77 ) ==
V_185 ) {
* V_152 = V_184 ;
return 0 ;
} else {
V_212 =
( F_52 ( V_32 ,
F_39
( V_32 -> V_43 ) ) &
V_26 ) >> V_25 ;
}
switch ( V_38 -> V_3 ) {
case V_4 :
case V_5 :
* V_152 =
F_84
( V_212 ) ;
break;
case V_7 :
* V_152 =
F_83
( V_212 ) ;
break;
default:
F_2 () ;
break;
}
if ( V_211 & V_154 )
* V_152 |= V_156 ;
if ( ( V_211 & V_77 ) != V_78 )
* V_152 |= V_157 ;
break;
case 1 :
if ( ( V_211 & V_77 ) == V_185
|| ( V_38 -> V_44 [ V_138 ] &
V_180 )
== 0 ) {
* V_152 = V_184 ;
return 0 ;
} else {
V_212 =
( V_38 -> V_44 [ V_138 ] &
V_181 ) >>
V_213 ;
}
switch ( V_38 -> V_3 ) {
case V_4 :
case V_5 :
* V_152 =
F_86
( V_212 ) ;
break;
case V_7 :
* V_152 =
F_85
( V_212 ) ;
break;
default:
F_2 () ;
break;
}
if ( V_38 -> V_44 [ V_138 ] &
V_186 ) {
* V_152 |= V_156 ;
}
if ( ( V_211 & V_77 ) != V_78 )
* V_152 |= V_157 ;
break;
default:
return - V_104 ;
break;
}
return 0 ;
}
int F_88 ( struct V_31 * V_32 ,
struct V_214 * V_215 , unsigned int * V_216 )
{
switch ( V_216 [ 0 ] ) {
case V_217 :
return F_53 ( V_32 , V_216 [ 1 ] ) ;
break;
case V_218 :
return F_54 ( V_32 , 1 , V_216 [ 1 ] ) ;
break;
case V_219 :
F_54 ( V_32 , 0 , 0 ) ;
return 0 ;
break;
case V_220 :
V_216 [ 1 ] = F_45 ( V_32 ) ;
V_216 [ 2 ] = V_221 ;
return 0 ;
break;
case V_222 :
return F_63 ( V_32 , V_216 [ 1 ] , V_216 [ 2 ] ) ;
break;
case V_223 :
F_67 ( V_32 , & V_216 [ 1 ] , & V_216 [ 2 ] ) ;
return 0 ;
break;
case V_224 :
return F_80 ( V_32 , V_216 [ 1 ] , V_216 [ 2 ] ) ;
break;
case V_225 :
return F_87 ( V_32 , V_216 [ 1 ] , & V_216 [ 2 ] ) ;
break;
case V_226 :
return F_81 ( V_32 , V_216 [ 1 ] , V_216 [ 2 ] ) ;
break;
case V_227 :
F_29 ( V_32 ) ;
return 0 ;
break;
default:
break;
}
return - V_104 ;
}
int F_89 ( struct V_31 * V_32 , struct V_214 * V_215 ,
unsigned int * V_216 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_228 = F_71 ( V_215 -> V_229 ) ;
unsigned V_230 ;
unsigned V_231 ;
unsigned V_232 ;
if ( V_215 -> V_15 < 1 )
return 0 ;
switch ( V_228 ) {
case 0 :
F_34 ( V_32 ,
F_35 ( V_32 -> V_43 ) ,
V_233 , 0 ) ;
F_34 ( V_32 ,
F_35 ( V_32 -> V_43 ) ,
V_233 , V_233 ) ;
V_230 =
F_23 ( V_32 ,
F_90 ( V_32 -> V_43 ) ) ;
V_231 =
F_23 ( V_32 ,
F_90 ( V_32 -> V_43 ) ) ;
if ( V_230 != V_231 )
V_232 =
F_23 ( V_32 ,
F_90 ( V_32 ->
V_43 ) ) ;
else
V_232 = V_230 ;
V_216 [ 0 ] = V_232 ;
return 0 ;
break;
case 1 :
V_216 [ 0 ] =
V_38 ->
V_44 [ F_37 ( V_32 -> V_43 ) ] ;
break;
case 2 :
V_216 [ 0 ] =
V_38 ->
V_44 [ F_38 ( V_32 -> V_43 ) ] ;
break;
}
return 0 ;
}
static unsigned F_91 ( struct V_31 * V_32 )
{
const unsigned V_33 = F_23 ( V_32 ,
F_46 ( V_32 ->
V_43 ) ) ;
if ( V_33 & F_92 ( V_32 -> V_43 ) )
return F_38 ( V_32 -> V_43 ) ;
else
return F_37 ( V_32 -> V_43 ) ;
}
int F_93 ( struct V_31 * V_32 , struct V_214 * V_215 ,
unsigned int * V_216 )
{
struct V_28 * V_38 = V_32 -> V_38 ;
const unsigned V_228 = F_71 ( V_215 -> V_229 ) ;
unsigned V_234 ;
if ( V_215 -> V_15 < 1 )
return 0 ;
switch ( V_228 ) {
case 0 :
V_234 = F_91 ( V_32 ) ;
F_22 ( V_32 , V_216 [ 0 ] , V_234 ) ;
F_55 ( V_32 ,
F_35 ( V_32 ->
V_43 ) ,
0 , 0 , V_235 ) ;
F_22 ( V_32 , V_38 -> V_44 [ V_234 ] , V_234 ) ;
break;
case 1 :
V_38 -> V_44 [ F_37 ( V_32 -> V_43 ) ] =
V_216 [ 0 ] ;
F_22 ( V_32 , V_216 [ 0 ] ,
F_37 ( V_32 -> V_43 ) ) ;
break;
case 2 :
V_38 -> V_44 [ F_38 ( V_32 -> V_43 ) ] =
V_216 [ 0 ] ;
F_22 ( V_32 , V_216 [ 0 ] ,
F_38 ( V_32 -> V_43 ) ) ;
break;
default:
return - V_104 ;
break;
}
return 0 ;
}
