static void F_1 ( struct V_1 * V_2 , char * V_3 )
{
struct V_4 * V_5 ;
if ( ! V_2 )
return;
V_5 = F_2 ( V_2 -> V_6 ) ;
if ( F_3 ( V_5 ) )
return;
snprintf ( V_3 , V_7 , L_1 ,
F_4 ( V_5 ) ,
F_5 ( V_5 ) ) ;
F_6 ( V_5 ) ;
}
static void
F_7 ( struct V_1 * V_2 , struct V_8 * V_9 ,
const char * V_10 , struct V_11 * V_12 )
{
char V_13 [ V_7 ] = {} ;
F_8 ( V_12 -> V_14 , V_9 -> V_14 -> V_15 , sizeof( V_12 -> V_14 ) ) ;
F_8 ( V_12 -> V_3 , V_16 , sizeof( V_12 -> V_3 ) ) ;
F_1 ( V_2 , V_13 ) ;
snprintf ( V_12 -> V_17 , sizeof( V_12 -> V_17 ) ,
L_2 , V_10 , V_13 ,
F_9 ( V_2 ) , F_10 ( V_2 ) ) ;
}
static void
F_11 ( struct V_18 * V_19 , struct V_11 * V_12 )
{
char V_10 [ V_7 ] = {} ;
struct V_20 * V_21 = F_12 ( V_19 ) ;
snprintf ( V_10 , sizeof( V_10 ) , L_3 ,
V_21 -> V_22 . V_23 , V_21 -> V_22 . V_24 ,
V_21 -> V_22 . V_25 , V_21 -> V_22 . V_26 ) ;
F_8 ( V_12 -> V_27 , F_13 ( V_21 -> V_9 ) ,
sizeof( V_12 -> V_27 ) ) ;
F_7 ( V_21 -> V_2 , V_21 -> V_9 , V_10 , V_12 ) ;
}
static void
F_14 ( struct V_18 * V_19 , struct V_11 * V_12 )
{
struct V_1 * V_2 ;
V_2 = F_15 ( V_19 ) ;
if ( ! V_2 )
return;
F_7 ( V_2 , V_2 -> V_9 , L_4 , V_12 ) ;
}
static int
F_16 ( struct V_18 * V_19 ,
struct V_28 * V_29 )
{
static const T_1 V_30 [] = {
[ V_31 ] = 0 ,
[ V_32 ] = V_33 ,
[ V_34 ] = V_35 ,
[ V_36 ] = V_37 ,
[ V_38 ] = V_39 ,
[ V_40 ] = V_41 ,
[ V_42 ] = V_43 ,
[ V_44 ] = V_45 ,
} ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_20 * V_21 ;
T_1 V_50 , V_51 ;
F_17 ( V_29 , V_52 , V_53 ) ;
V_29 -> V_54 . V_49 = V_55 ;
V_29 -> V_54 . V_56 = V_33 ;
V_29 -> V_54 . V_57 = V_58 ;
V_49 = F_18 ( V_19 ) ;
V_47 = F_19 ( V_49 ) ;
if ( V_47 )
V_29 -> V_54 . V_59 = V_47 -> V_60 != V_61 ?
V_62 : V_63 ;
if ( ! F_20 ( V_19 ) )
return 0 ;
if ( V_47 ) {
V_29 -> V_54 . V_49 = V_47 -> V_64 ;
V_29 -> V_54 . V_56 = V_47 -> V_56 ;
V_29 -> V_54 . V_57 = V_65 ;
return 0 ;
}
if ( ! F_21 ( V_19 ) )
return - V_66 ;
V_21 = F_12 ( V_19 ) ;
V_50 = F_22 ( V_21 , V_67 ) ;
V_51 = F_23 ( V_68 , V_50 ) ;
if ( V_51 == V_31 )
return - V_66 ;
if ( V_51 == V_32 ||
V_51 >= F_24 ( V_30 ) )
return 0 ;
V_29 -> V_54 . V_56 = V_30 [ V_50 ] ;
V_29 -> V_54 . V_57 = V_65 ;
return 0 ;
}
static int
F_25 ( struct V_18 * V_19 ,
const struct V_28 * V_29 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_4 * V_5 ;
int V_69 ;
V_49 = F_18 ( V_19 ) ;
V_47 = F_26 ( V_49 ) ;
if ( ! V_47 )
return - V_66 ;
if ( F_27 ( V_19 ) ) {
F_28 ( V_19 , L_5 ) ;
return - V_70 ;
}
V_5 = F_29 ( V_49 -> V_2 -> V_6 , V_47 -> V_71 ) ;
if ( F_3 ( V_5 ) )
return F_30 ( V_5 ) ;
V_69 = F_31 ( V_5 , V_29 -> V_54 . V_59 == V_62 ?
V_72 : V_61 ) ;
if ( V_69 )
goto V_73;
if ( V_29 -> V_54 . V_56 != V_33 ) {
T_1 V_56 = V_29 -> V_54 . V_56 / V_47 -> V_74 ;
V_69 = F_32 ( V_5 , V_56 ) ;
if ( V_69 )
goto V_73;
}
V_69 = F_33 ( V_5 ) ;
if ( V_69 > 0 )
return 0 ;
F_34 ( V_49 ) ;
return V_69 ;
V_73:
F_35 ( V_5 ) ;
return V_69 ;
}
static void F_36 ( struct V_18 * V_19 ,
struct V_75 * V_76 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
V_76 -> V_77 = V_78 ;
V_76 -> V_79 = V_80 ;
V_76 -> V_81 = V_21 -> V_82 . V_83 ;
V_76 -> V_84 = V_21 -> V_82 . V_85 ;
}
static int F_37 ( struct V_20 * V_21 , T_1 V_83 , T_1 V_85 )
{
struct V_86 * V_82 ;
V_82 = F_38 ( V_21 ) ;
if ( ! V_82 )
return - V_87 ;
V_82 -> V_83 = V_83 ;
V_82 -> V_85 = V_85 ;
return F_39 ( V_21 , V_82 , NULL ) ;
}
static int F_40 ( struct V_18 * V_19 ,
struct V_75 * V_76 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
T_1 V_83 , V_85 ;
if ( V_76 -> V_88 || V_76 -> V_89 )
return - V_90 ;
V_83 = F_41 ( V_76 -> V_81 ) ;
V_85 = F_41 ( V_76 -> V_84 ) ;
if ( V_83 < V_91 || V_83 > V_78 ||
V_85 < V_92 || V_85 > V_80 )
return - V_90 ;
if ( V_21 -> V_82 . V_83 == V_83 && V_21 -> V_82 . V_85 == V_85 )
return 0 ;
F_42 ( V_21 , L_6 ,
V_21 -> V_82 . V_83 , V_83 , V_21 -> V_82 . V_85 , V_85 ) ;
return F_37 ( V_21 , V_83 , V_85 ) ;
}
static unsigned int F_43 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
return V_93 + V_21 -> V_82 . V_94 * 3 ;
}
static T_2 * F_44 ( struct V_18 * V_19 , T_2 * V_95 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
int V_96 ;
for ( V_96 = 0 ; V_96 < V_21 -> V_82 . V_94 ; V_96 ++ ) {
V_95 = F_45 ( V_95 , L_7 , V_96 ) ;
V_95 = F_45 ( V_95 , L_8 , V_96 ) ;
V_95 = F_45 ( V_95 , L_9 , V_96 ) ;
}
V_95 = F_45 ( V_95 , L_10 ) ;
V_95 = F_45 ( V_95 , L_11 ) ;
V_95 = F_45 ( V_95 , L_12 ) ;
V_95 = F_45 ( V_95 , L_13 ) ;
V_95 = F_45 ( V_95 , L_14 ) ;
V_95 = F_45 ( V_95 , L_15 ) ;
V_95 = F_45 ( V_95 , L_16 ) ;
return V_95 ;
}
static T_3 * F_46 ( struct V_18 * V_19 , T_3 * V_95 )
{
T_3 V_97 [ V_93 ] = {} ;
struct V_20 * V_21 = F_12 ( V_19 ) ;
T_3 V_98 [ V_93 ] ;
unsigned int V_96 , V_99 ;
for ( V_96 = 0 ; V_96 < V_21 -> V_82 . V_94 ; V_96 ++ ) {
unsigned int V_100 ;
do {
V_100 = F_47 ( & V_21 -> V_101 [ V_96 ] . V_102 ) ;
V_95 [ 0 ] = V_21 -> V_101 [ V_96 ] . V_103 ;
V_98 [ 0 ] = V_21 -> V_101 [ V_96 ] . V_104 ;
V_98 [ 1 ] = V_21 -> V_101 [ V_96 ] . V_105 ;
V_98 [ 2 ] = V_21 -> V_101 [ V_96 ] . V_106 ;
} while ( F_48 ( & V_21 -> V_101 [ V_96 ] . V_102 , V_100 ) );
do {
V_100 = F_47 ( & V_21 -> V_101 [ V_96 ] . V_107 ) ;
V_95 [ 1 ] = V_21 -> V_101 [ V_96 ] . V_108 ;
V_95 [ 2 ] = V_21 -> V_101 [ V_96 ] . V_109 ;
V_98 [ 3 ] = V_21 -> V_101 [ V_96 ] . V_110 ;
V_98 [ 4 ] = V_21 -> V_101 [ V_96 ] . V_111 ;
V_98 [ 5 ] = V_21 -> V_101 [ V_96 ] . V_112 ;
V_98 [ 6 ] = V_21 -> V_101 [ V_96 ] . V_113 ;
} while ( F_48 ( & V_21 -> V_101 [ V_96 ] . V_107 , V_100 ) );
V_95 += 3 ;
for ( V_99 = 0 ; V_99 < V_93 ; V_99 ++ )
V_97 [ V_99 ] += V_98 [ V_99 ] ;
}
for ( V_99 = 0 ; V_99 < V_93 ; V_99 ++ )
* V_95 ++ = V_97 [ V_99 ] ;
return V_95 ;
}
static unsigned int
F_49 ( unsigned int V_114 , unsigned int V_115 )
{
return V_116 + ( V_114 + V_115 ) * 2 ;
}
static T_2 *
F_50 ( T_2 * V_95 , unsigned int V_114 ,
unsigned int V_115 , bool V_117 )
{
int V_118 , V_96 ;
F_51 ( V_116 < V_119 * 2 ) ;
V_118 = V_117 * V_119 ;
for ( V_96 = 0 ; V_96 < V_119 ; V_96 ++ )
V_95 = F_45 ( V_95 , V_120 [ V_96 + V_118 ] . V_15 ) ;
for ( V_96 = V_119 ; V_96 < V_119 * 2 ; V_96 ++ )
V_95 = F_45 ( V_95 , V_120 [ V_96 - V_118 ] . V_15 ) ;
for ( V_96 = V_119 * 2 ; V_96 < V_116 ; V_96 ++ )
V_95 = F_45 ( V_95 , V_120 [ V_96 ] . V_15 ) ;
for ( V_96 = 0 ; V_96 < V_115 ; V_96 ++ ) {
V_95 = F_45 ( V_95 , L_17 , V_96 ) ;
V_95 = F_45 ( V_95 , L_18 , V_96 ) ;
}
for ( V_96 = 0 ; V_96 < V_114 ; V_96 ++ ) {
V_95 = F_45 ( V_95 , L_19 , V_96 ) ;
V_95 = F_45 ( V_95 , L_20 , V_96 ) ;
}
return V_95 ;
}
static T_3 *
F_52 ( T_3 * V_95 , T_2 T_4 * V_121 ,
unsigned int V_114 , unsigned int V_115 )
{
unsigned int V_96 ;
for ( V_96 = 0 ; V_96 < V_116 ; V_96 ++ )
* V_95 ++ = F_53 ( V_121 + V_120 [ V_96 ] . V_122 ) ;
for ( V_96 = 0 ; V_96 < V_115 ; V_96 ++ ) {
* V_95 ++ = F_53 ( V_121 + F_54 ( V_96 ) ) ;
* V_95 ++ = F_53 ( V_121 + F_54 ( V_96 ) + 8 ) ;
}
for ( V_96 = 0 ; V_96 < V_114 ; V_96 ++ ) {
* V_95 ++ = F_53 ( V_121 + F_55 ( V_96 ) ) ;
* V_95 ++ = F_53 ( V_121 + F_55 ( V_96 ) + 8 ) ;
}
return V_95 ;
}
static unsigned int F_56 ( struct V_18 * V_19 )
{
struct V_48 * V_49 ;
V_49 = F_18 ( V_19 ) ;
if ( ! F_26 ( V_49 ) || ! V_49 -> V_123 )
return 0 ;
return F_24 ( V_124 ) ;
}
static T_2 * F_57 ( struct V_18 * V_19 , T_2 * V_95 )
{
struct V_48 * V_49 ;
unsigned int V_96 ;
V_49 = F_18 ( V_19 ) ;
if ( ! F_26 ( V_49 ) || ! V_49 -> V_123 )
return V_95 ;
for ( V_96 = 0 ; V_96 < F_24 ( V_124 ) ; V_96 ++ )
V_95 = F_45 ( V_95 , L_21 , V_124 [ V_96 ] . V_15 ) ;
return V_95 ;
}
static T_3 * F_58 ( struct V_18 * V_19 , T_3 * V_95 )
{
struct V_48 * V_49 ;
unsigned int V_96 ;
V_49 = F_18 ( V_19 ) ;
if ( ! F_26 ( V_49 ) || ! V_49 -> V_123 )
return V_95 ;
for ( V_96 = 0 ; V_96 < F_24 ( V_124 ) ; V_96 ++ )
* V_95 ++ = F_53 ( V_49 -> V_123 + V_124 [ V_96 ] . V_122 ) ;
return V_95 ;
}
static void F_59 ( struct V_18 * V_19 ,
T_1 V_125 , T_2 * V_95 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
switch ( V_125 ) {
case V_126 :
V_95 = F_44 ( V_19 , V_95 ) ;
V_95 = F_50 ( V_95 , V_21 -> V_82 . V_127 ,
V_21 -> V_82 . V_128 ,
false ) ;
V_95 = F_57 ( V_19 , V_95 ) ;
break;
}
}
static void
F_60 ( struct V_18 * V_19 , struct V_129 * V_130 ,
T_3 * V_95 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
V_95 = F_46 ( V_19 , V_95 ) ;
V_95 = F_52 ( V_95 , V_21 -> V_82 . V_131 ,
V_21 -> V_82 . V_127 , V_21 -> V_82 . V_128 ) ;
V_95 = F_58 ( V_19 , V_95 ) ;
}
static int F_61 ( struct V_18 * V_19 , int V_132 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
switch ( V_132 ) {
case V_126 :
return F_43 ( V_19 ) +
F_49 ( V_21 -> V_82 . V_127 ,
V_21 -> V_82 . V_128 ) +
F_56 ( V_19 ) ;
default:
return - V_66 ;
}
}
static void F_62 ( struct V_18 * V_19 ,
T_1 V_125 , T_2 * V_95 )
{
struct V_48 * V_49 = F_18 ( V_19 ) ;
switch ( V_125 ) {
case V_126 :
if ( F_63 ( V_49 ) )
V_95 = F_50 ( V_95 , 0 , 0 , true ) ;
else
V_95 = F_57 ( V_19 , V_95 ) ;
break;
}
}
static void
F_64 ( struct V_18 * V_19 , struct V_129 * V_130 ,
T_3 * V_95 )
{
struct V_48 * V_49 = F_18 ( V_19 ) ;
if ( F_63 ( V_49 ) )
V_95 = F_52 ( V_95 , V_49 -> V_133 , 0 , 0 ) ;
else
V_95 = F_58 ( V_19 , V_95 ) ;
}
static int F_65 ( struct V_18 * V_19 , int V_132 )
{
struct V_48 * V_49 = F_18 ( V_19 ) ;
unsigned int V_134 ;
switch ( V_132 ) {
case V_126 :
if ( F_63 ( V_49 ) )
V_134 = F_49 ( 0 , 0 ) ;
else
V_134 = F_56 ( V_19 ) ;
return V_134 ;
default:
return - V_66 ;
}
}
static T_1 F_66 ( T_1 V_135 )
{
static const T_1 V_136 [ V_137 + 1 ] = {
[ V_138 ] = V_139 ,
[ V_140 ] = V_141 ,
[ V_142 ] = V_143 ,
[ V_144 ] = V_145 ,
[ V_146 ] = V_147 ,
[ V_137 ] = V_148 ,
} ;
if ( V_135 >= F_24 ( V_136 ) )
return 0 ;
return V_136 [ V_135 ] ;
}
static int F_67 ( struct V_20 * V_21 ,
struct V_149 * V_29 )
{
T_1 V_150 ;
V_29 -> V_95 = 0 ;
if ( ! ( V_21 -> V_151 & V_152 ) )
return - V_66 ;
V_150 = F_66 ( V_29 -> V_135 ) ;
if ( ! V_150 )
return - V_90 ;
V_29 -> V_95 |= V_153 | V_154 ;
if ( V_21 -> V_155 & V_150 )
V_29 -> V_95 |= V_156 | V_157 ;
return 0 ;
}
static int F_68 ( struct V_18 * V_19 ,
struct V_149 * V_29 , T_1 * V_158 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
switch ( V_29 -> V_29 ) {
case V_159 :
V_29 -> V_95 = V_21 -> V_82 . V_127 ;
return 0 ;
case V_160 :
return F_67 ( V_21 , V_29 ) ;
default:
return - V_66 ;
}
}
static int F_69 ( struct V_20 * V_21 ,
struct V_149 * V_161 )
{
T_1 V_162 = V_21 -> V_155 ;
T_1 V_150 ;
int V_69 ;
if ( ! ( V_21 -> V_151 & V_152 ) )
return - V_66 ;
if ( V_161 -> V_95 & ~ ( V_153 | V_154 |
V_156 | V_157 ) )
return - V_90 ;
if ( ! ( V_161 -> V_95 & V_153 ) ||
! ( V_161 -> V_95 & V_154 ) )
return - V_90 ;
V_150 = F_66 ( V_161 -> V_135 ) ;
if ( ! V_150 )
return - V_90 ;
switch ( V_161 -> V_95 & ( V_156 | V_157 ) ) {
case 0 :
V_162 &= ~ V_150 ;
break;
case ( V_156 | V_157 ) :
V_162 |= V_150 ;
break;
default:
return - V_90 ;
}
V_162 |= F_70 ( V_163 , V_21 -> V_164 ) ;
V_162 |= V_165 ;
if ( V_162 == V_21 -> V_155 )
return 0 ;
F_71 ( V_162 , V_21 -> V_82 . V_131 + V_166 ) ;
V_69 = F_72 ( V_21 , V_167 ) ;
if ( V_69 )
return V_69 ;
V_21 -> V_155 = V_162 ;
F_42 ( V_21 , L_22 , V_21 -> V_155 ) ;
return 0 ;
}
static int F_73 ( struct V_18 * V_19 ,
struct V_149 * V_29 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
switch ( V_29 -> V_29 ) {
case V_168 :
return F_69 ( V_21 , V_29 ) ;
default:
return - V_66 ;
}
}
static T_1 F_74 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
if ( ! ( V_21 -> V_151 & V_152 ) )
return 0 ;
return F_24 ( V_21 -> V_169 ) ;
}
static T_1 F_75 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
if ( ! ( V_21 -> V_151 & V_152 ) )
return - V_66 ;
return F_76 ( V_21 ) ;
}
static int F_77 ( struct V_18 * V_19 , T_1 * V_170 , T_2 * V_171 ,
T_2 * V_172 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
int V_96 ;
if ( ! ( V_21 -> V_151 & V_152 ) )
return - V_66 ;
if ( V_170 )
for ( V_96 = 0 ; V_96 < F_24 ( V_21 -> V_169 ) ; V_96 ++ )
V_170 [ V_96 ] = V_21 -> V_169 [ V_96 ] ;
if ( V_171 )
memcpy ( V_171 , V_21 -> V_173 , F_76 ( V_21 ) ) ;
if ( V_172 ) {
* V_172 = V_21 -> V_164 ;
if ( * V_172 >= 1 << V_174 )
* V_172 = V_175 ;
}
return 0 ;
}
static int F_78 ( struct V_18 * V_19 ,
const T_1 * V_170 , const T_2 * V_171 ,
const T_2 V_172 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
int V_96 ;
if ( ! ( V_21 -> V_151 & V_152 ) ||
! ( V_172 == V_176 || V_172 == V_21 -> V_164 ) )
return - V_66 ;
if ( ! V_171 && ! V_170 )
return 0 ;
if ( V_171 ) {
memcpy ( V_21 -> V_173 , V_171 , F_76 ( V_21 ) ) ;
F_79 ( V_21 ) ;
}
if ( V_170 ) {
for ( V_96 = 0 ; V_96 < F_24 ( V_21 -> V_169 ) ; V_96 ++ )
V_21 -> V_169 [ V_96 ] = V_170 [ V_96 ] ;
F_80 ( V_21 ) ;
}
return F_72 ( V_21 , V_167 ) ;
}
static int F_81 ( struct V_18 * V_19 )
{
return V_177 ;
}
static void F_82 ( struct V_18 * V_19 ,
struct V_178 * V_179 , void * V_180 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
T_1 * V_181 = V_180 ;
int V_96 ;
V_179 -> V_3 = F_22 ( V_21 , V_182 ) ;
for ( V_96 = 0 ; V_96 < V_177 / sizeof( T_1 ) ; V_96 ++ )
V_181 [ V_96 ] = F_83 ( V_21 -> V_82 . V_131 + ( V_96 * sizeof( T_1 ) ) ) ;
}
static int F_84 ( struct V_18 * V_19 ,
struct V_183 * V_184 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
if ( ! ( V_21 -> V_151 & V_185 ) )
return - V_90 ;
V_184 -> V_186 = V_21 -> V_186 ;
V_184 -> V_187 = V_21 -> V_188 ;
V_184 -> V_189 = V_21 -> V_189 ;
V_184 -> V_190 = V_21 -> V_191 ;
return 0 ;
}
static int
F_85 ( struct V_1 * V_2 , struct V_192 * V_193 , void * V_194 )
{
struct V_195 * V_196 ;
int V_197 ;
if ( ! V_2 )
return - V_66 ;
V_193 -> V_3 = 1 ;
V_193 -> V_198 = V_199 ;
V_196 = F_86 ( V_2 -> V_6 , V_200 ) ;
if ( F_3 ( V_196 ) )
return F_30 ( V_196 ) ;
if ( V_194 ) {
if ( V_193 -> V_201 != F_87 ( V_196 ) ) {
V_197 = - V_90 ;
goto V_202;
}
V_197 = F_88 ( V_2 -> V_6 , F_89 ( V_196 ) ,
F_90 ( V_196 ) ,
V_194 , V_193 -> V_201 ) ;
if ( V_197 != V_193 -> V_201 )
V_197 = V_197 < 0 ? V_197 : - V_203 ;
else
V_197 = 0 ;
} else {
V_193 -> V_201 = F_87 ( V_196 ) ;
V_197 = 0 ;
}
V_202:
F_91 ( V_196 ) ;
return V_197 ;
}
static int F_92 ( struct V_18 * V_19 , struct V_192 * V_204 )
{
struct V_1 * V_2 = F_15 ( V_19 ) ;
if ( ! V_2 )
return - V_66 ;
if ( V_204 -> V_198 != V_199 )
return - V_90 ;
return 0 ;
}
static int
F_93 ( struct V_18 * V_19 , struct V_192 * V_193 )
{
return F_85 ( F_15 ( V_19 ) , V_193 , NULL ) ;
}
static int
F_94 ( struct V_18 * V_19 , struct V_192 * V_193 ,
void * V_194 )
{
return F_85 ( F_15 ( V_19 ) , V_193 , V_194 ) ;
}
static int F_95 ( struct V_18 * V_19 ,
struct V_183 * V_184 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
unsigned int V_205 ;
if ( V_184 -> V_206 ||
V_184 -> V_207 ||
V_184 -> V_208 ||
V_184 -> V_209 ||
V_184 -> V_210 ||
V_184 -> V_211 ||
V_184 -> V_212 ||
V_184 -> V_213 ||
V_184 -> V_214 ||
V_184 -> V_215 ||
V_184 -> V_216 ||
V_184 -> V_217 ||
V_184 -> V_218 ||
V_184 -> V_219 ||
V_184 -> V_220 ||
V_184 -> V_221 ||
V_184 -> V_222 ||
V_184 -> V_223 )
return - V_66 ;
V_205 = V_21 -> V_224 / 16 ;
if ( ! ( V_21 -> V_151 & V_185 ) )
return - V_90 ;
if ( ! V_184 -> V_186 && ! V_184 -> V_187 )
return - V_90 ;
if ( ! V_184 -> V_189 && ! V_184 -> V_190 )
return - V_90 ;
if ( V_184 -> V_186 * V_205 >= ( ( 1 << 16 ) - 1 ) )
return - V_90 ;
if ( V_184 -> V_189 * V_205 >= ( ( 1 << 16 ) - 1 ) )
return - V_90 ;
if ( V_184 -> V_187 >= ( ( 1 << 16 ) - 1 ) )
return - V_90 ;
if ( V_184 -> V_190 >= ( ( 1 << 16 ) - 1 ) )
return - V_90 ;
V_21 -> V_186 = V_184 -> V_186 ;
V_21 -> V_188 = V_184 -> V_187 ;
V_21 -> V_189 = V_184 -> V_189 ;
V_21 -> V_191 = V_184 -> V_190 ;
F_96 ( V_21 ) ;
return F_72 ( V_21 , V_225 ) ;
}
static void F_97 ( struct V_18 * V_19 ,
struct V_226 * V_227 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
unsigned int V_128 ;
V_128 = V_21 -> V_82 . V_128 ;
if ( V_21 -> V_82 . V_228 )
V_128 -= V_21 -> V_82 . V_127 ;
V_227 -> V_229 = F_98 ( V_21 -> V_230 , V_21 -> V_231 ) ;
V_227 -> V_232 = F_98 ( V_21 -> V_233 , V_21 -> V_231 ) ;
V_227 -> V_234 = F_98 ( V_227 -> V_229 , V_227 -> V_232 ) ;
V_227 -> V_235 = V_236 ;
V_227 -> V_237 = F_98 ( V_21 -> V_82 . V_127 , V_128 ) ;
V_227 -> V_238 = V_21 -> V_82 . V_127 - V_227 -> V_237 ;
V_227 -> V_239 = V_128 - V_227 -> V_237 ;
V_227 -> V_240 = V_236 ;
}
static int F_99 ( struct V_20 * V_21 , unsigned int V_241 ,
unsigned int V_242 )
{
struct V_86 * V_82 ;
V_82 = F_38 ( V_21 ) ;
if ( ! V_82 )
return - V_87 ;
V_82 -> V_127 = V_241 ;
V_82 -> V_128 = V_242 ;
if ( V_82 -> V_228 )
V_82 -> V_128 += V_241 ;
return F_39 ( V_21 , V_82 , NULL ) ;
}
static int F_100 ( struct V_18 * V_19 ,
struct V_226 * V_227 )
{
struct V_20 * V_21 = F_12 ( V_19 ) ;
unsigned int V_241 , V_242 ;
if ( ! V_227 -> V_237 ||
V_227 -> V_240 != V_236 ||
( V_227 -> V_238 && V_227 -> V_239 ) )
return - V_90 ;
V_241 = V_227 -> V_237 + V_227 -> V_238 ;
V_242 = V_227 -> V_237 + V_227 -> V_239 ;
if ( V_241 > F_98 ( V_21 -> V_230 , V_21 -> V_231 ) ||
V_242 > F_98 ( V_21 -> V_233 , V_21 -> V_231 ) )
return - V_90 ;
return F_99 ( V_21 , V_241 , V_242 ) ;
}
void F_101 ( struct V_18 * V_19 )
{
V_19 -> V_243 = & V_244 ;
}
