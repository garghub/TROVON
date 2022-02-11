void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , V_4 ) ;
F_3 ( V_2 , V_3 , V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 , T_1 V_7 )
{
switch ( V_6 -> V_8 ) {
case V_9 :
F_5 ( V_6 -> V_2 , V_3 , V_10 ,
V_11 ,
V_7 << V_12 ) ;
break;
case V_13 :
F_5 ( V_6 -> V_2 , V_3 , V_10 ,
V_14 ,
V_7 << V_15 ) ;
break;
}
}
static int F_6 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
F_8 ( V_6 -> V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
F_10 ( V_6 -> V_2 ) ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
unsigned long V_18 ;
F_12 ( & V_6 -> V_19 , V_18 ) ;
F_4 ( V_6 , V_6 -> V_7 ) ;
V_6 -> V_20 = true ;
F_13 ( & V_6 -> V_19 , V_18 ) ;
return 0 ;
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
unsigned long V_18 ;
F_12 ( & V_6 -> V_19 , V_18 ) ;
F_4 ( V_6 , 0 ) ;
V_6 -> V_20 = false ;
F_13 ( & V_6 -> V_19 , V_18 ) ;
}
static unsigned long F_15 ( struct V_16 * V_17 ,
unsigned long V_21 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
return V_21 / V_6 -> V_7 ;
}
static T_1 F_16 ( unsigned long * V_22 , unsigned long V_21 )
{
T_1 V_7 ;
if ( * V_22 >= V_21 ) {
* V_22 = V_21 ;
return V_23 ;
}
V_7 = F_17 ( V_21 , * V_22 ) ;
if ( V_7 >= V_23 )
V_7 = V_23 - 1 ;
* V_22 = V_21 / V_7 ;
return V_7 ;
}
static long F_18 ( struct V_16 * V_17 , unsigned long V_22 ,
unsigned long * V_21 )
{
F_16 ( & V_22 , * V_21 ) ;
return V_22 ;
}
static int F_19 ( struct V_16 * V_17 , unsigned long V_22 ,
unsigned long V_21 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
unsigned long V_18 ;
T_1 V_7 ;
V_7 = F_16 ( & V_22 , V_21 ) ;
F_12 ( & V_6 -> V_19 , V_18 ) ;
V_6 -> V_7 = V_7 ;
if ( V_6 -> V_20 )
F_4 ( V_6 , V_7 ) ;
F_13 ( & V_6 -> V_19 , V_18 ) ;
F_20 ( V_6 -> V_2 -> V_24 , L_1 ,
V_25 , V_6 -> V_8 == V_9 ? 'a' : 'b' , V_22 , V_7 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_28 V_29 ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_22 ( V_2 -> V_31 ) ; ++ V_30 ) {
struct V_5 * V_6 = & V_2 -> V_31 [ V_30 ] ;
struct V_32 * V_32 ;
V_6 -> V_2 = V_2 ;
V_6 -> V_8 = V_30 == 0 ? V_9 : V_13 ;
V_6 -> V_7 = 1 ;
F_23 ( & V_6 -> V_19 ) ;
V_29 . V_33 = V_30 == 0 ? L_2 : L_3 ;
V_29 . V_34 = & V_35 ;
V_29 . V_36 = & V_37 ;
V_29 . V_38 = 1 ;
V_6 -> V_17 . V_29 = & V_29 ;
V_32 = F_24 ( V_2 -> V_24 , & V_6 -> V_17 ) ;
if ( F_25 ( V_32 ) )
return F_26 ( V_32 ) ;
if ( V_27 -> V_31 [ V_30 ] . V_39 == NULL &&
V_27 -> V_31 [ V_30 ] . V_40 == NULL )
continue;
V_6 -> V_41 = F_27 ( sizeof( * V_6 -> V_41 ) , V_42 ) ;
if ( V_6 -> V_41 == NULL )
return - V_43 ;
V_6 -> V_41 -> V_39 = V_27 -> V_31 [ V_30 ] . V_39 ;
V_6 -> V_41 -> V_40 = V_27 -> V_31 [ V_30 ] . V_40 ;
V_6 -> V_41 -> V_32 = V_32 ;
F_28 ( V_6 -> V_41 ) ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_22 ( V_2 -> V_31 ) ; ++ V_30 ) {
struct V_5 * V_6 = & V_2 -> V_31 [ V_30 ] ;
if ( V_6 -> V_41 )
F_30 ( V_6 -> V_41 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
static const T_1 V_44 = V_45
| V_46
| V_47
| V_48
| V_49
| V_50
| V_51
| V_52
| V_53
| V_54
| V_55
| V_56 ;
F_2 ( V_2 , V_44 , V_3 , V_57 ) ;
F_2 ( V_2 , V_44 , V_3 , V_58 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , V_58 ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_59 )
{
F_2 ( V_2 ,
( ( V_59 ? V_60 :
V_61 ) <<
V_62 ) |
( ( V_2 -> V_63 == V_64 ) ?
V_65 : 0 ) ,
V_3 , V_66 ) ;
F_2 ( V_2 ,
( V_2 -> V_67 ? V_68 : 0 ) |
V_69 ,
V_3 , V_70 ) ;
}
void F_34 ( struct V_1 * V_2 ,
enum V_71 V_72 ,
const struct V_73 * V_27 ,
unsigned int V_74 , unsigned int V_75 )
{
T_1 V_76 ;
V_76 = F_3 ( V_2 , V_3 , V_70 ) ;
V_76 &= ~ V_77 ;
V_76 &= ~ V_78 ;
V_76 &= ~ V_79 ;
V_76 &= ~ V_80 ;
V_76 |= V_75 ;
switch ( V_72 ) {
case V_81 :
V_76 |= V_82 ;
V_76 |= V_27 -> V_83 << V_84 ;
V_74 += V_27 -> V_85 * 2 ;
break;
case V_86 :
V_76 |= V_87 ;
break;
case V_88 :
V_76 |= V_89 ;
break;
case V_90 :
V_76 |= V_91 ;
break;
default:
return;
}
V_76 |= ( ( V_74 / 2 ) << V_92 ) & V_77 ;
F_2 ( V_2 , V_76 , V_3 , V_70 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( F_36 ( & V_2 -> V_93 ) ||
F_37 ( & V_2 -> V_94 ) ) {
F_38 ( & V_2 -> V_94 . V_95 , 1 ) ;
F_20 ( V_2 -> V_24 , L_4
L_5 ) ;
}
}
static inline void F_39 ( struct V_1 * V_2 , T_1 V_96 )
{
static const char * V_33 [] = {
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
} ;
int V_30 ;
F_20 ( V_2 -> V_24 , L_38 ) ;
for ( V_30 = 0 ; V_30 < F_22 ( V_33 ) ; V_30 ++ ) {
if ( ( 1 << V_30 ) & V_96 )
F_40 ( V_97 L_39 , V_33 [ V_30 ] ) ;
}
F_40 ( V_97 L_40 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_98 * V_24 = V_2 -> V_24 ;
struct V_99 * V_100 ;
T_1 V_101 ;
V_101 = F_3 ( V_2 , V_102 , V_103 ) ;
F_2 ( V_2 , V_101 , V_102 , V_103 ) ;
V_101 &= ~ V_104 ;
if ( V_101 )
F_20 ( V_24 , L_41 , V_101 ) ;
if ( V_101 & V_105 ) {
V_100 = F_42 ( & V_2 -> V_106 . V_107 . V_108 ) ;
if ( V_100 != NULL )
V_100 -> error = true ;
}
if ( V_101 & V_109 ) {
V_100 = F_42 ( & V_2 -> V_110 . V_107 . V_108 ) ;
if ( V_100 != NULL )
V_100 -> error = true ;
}
if ( V_101 & V_111 ) {
V_100 = F_42 ( & V_2 -> V_93 . V_107 . V_108 ) ;
if ( V_100 != NULL )
V_100 -> error = true ;
}
if ( V_101 & V_112 ) {
V_100 = F_42 ( & V_2 -> V_113 . V_107 . V_108 ) ;
if ( V_100 != NULL )
V_100 -> error = true ;
}
if ( V_101 & ( V_114
| V_115
| V_116
| V_117 ) ) {
V_100 = F_42 ( & V_2 -> V_118 . V_107 . V_108 ) ;
if ( V_100 != NULL )
V_100 -> error = true ;
}
if ( V_101 & V_119 )
F_43 ( & V_2 -> V_120 ) ;
if ( V_101 & V_121 )
F_43 ( & V_2 -> V_122 ) ;
}
static T_2 F_44 ( int V_44 , void * V_123 )
{
static const T_1 V_124 = V_125 |
V_126 |
V_127 |
V_128 |
V_129 ;
struct V_1 * V_2 = V_123 ;
T_1 V_96 ;
V_96 = F_3 ( V_2 , V_3 , V_57 ) ;
F_2 ( V_2 , V_96 , V_3 , V_57 ) ;
F_41 ( V_2 ) ;
if ( V_96 & V_130 )
F_45 ( & V_2 -> V_110 ) ;
if ( V_96 & V_131 )
F_46 ( & V_2 -> V_106 ) ;
if ( V_96 & V_127 ) {
if ( V_2 -> V_93 . V_132 & V_133 )
F_47 ( & V_2 -> V_113 ) ;
if ( V_2 -> V_93 . V_132 & V_134 )
F_48 ( & V_2 -> V_118 ) ;
F_49 ( & V_2 -> V_122 ) ;
F_49 ( & V_2 -> V_120 ) ;
F_49 ( & V_2 -> V_94 ) ;
}
if ( V_96 & V_124 )
F_50 ( & V_2 -> V_93 , V_96 & V_124 ) ;
if ( V_96 & V_135 ) {
if ( V_2 -> V_113 . V_132 & V_136 )
F_48 ( & V_2 -> V_118 ) ;
F_51 ( & V_2 -> V_113 ) ;
}
if ( V_96 & V_137 )
F_52 ( & V_2 -> V_118 ) ;
if ( V_96 & V_138 )
F_53 ( & V_2 -> V_122 ) ;
if ( V_96 & V_139 )
F_53 ( & V_2 -> V_120 ) ;
if ( V_96 & V_140 )
F_53 ( & V_2 -> V_94 ) ;
F_1 ( V_2 ) ;
#if F_54 ( V_141 ) && F_54 ( V_142 )
F_39 ( V_2 , V_96 ) ;
#endif
return V_143 ;
}
static int F_55 ( struct V_144 * V_108 )
{
struct V_145 V_146 ;
int V_147 = 0 ;
F_56 ( & V_146 , V_108 ) ;
while ( ( V_108 = F_57 ( & V_146 ) ) ) {
if ( F_58 ( V_108 ) == V_148 )
V_147 += V_108 -> V_149 ;
}
return V_147 ;
}
static int F_59 ( struct V_144 * V_108 , int V_150 )
{
struct V_151 * V_107 ;
int V_152 ;
V_107 = F_58 ( V_108 ) == V_153
? F_60 ( V_108 ) : NULL ;
if ( V_108 -> V_149 == 0 && V_150 > 0 && V_107 != NULL ) {
V_152 = F_61 ( V_107 , V_154 , V_155 , 1 ) ;
if ( V_152 < 0 && V_152 != - V_156 )
return V_152 ;
}
V_108 -> V_149 += V_150 ;
F_62 ( V_108 -> V_149 < 0 ) ;
if ( V_108 -> V_149 == 0 && V_150 < 0 && V_107 != NULL )
F_61 ( V_107 , V_154 , V_155 , 0 ) ;
return 0 ;
}
static int F_63 ( struct V_144 * V_108 , int V_150 )
{
struct V_145 V_146 ;
struct V_144 * V_157 = V_108 ;
int V_152 = 0 ;
if ( ! V_150 )
return 0 ;
F_56 ( & V_146 , V_108 ) ;
while ( ! V_152 && ( V_108 = F_57 ( & V_146 ) ) )
if ( F_58 ( V_108 ) != V_148 )
V_152 = F_59 ( V_108 , V_150 ) ;
if ( ! V_152 )
return 0 ;
F_56 ( & V_146 , V_157 ) ;
while ( ( V_157 = F_57 ( & V_146 ) )
&& V_157 != V_108 )
if ( F_58 ( V_157 ) != V_148 )
F_59 ( V_157 , - V_150 ) ;
return V_152 ;
}
int F_64 ( struct V_144 * V_108 , int V_147 )
{
int V_150 = V_147 ? 1 : - 1 ;
int V_152 ;
F_65 ( & V_108 -> V_158 -> V_159 ) ;
V_108 -> V_149 += V_150 ;
F_62 ( V_108 -> V_149 < 0 ) ;
V_152 = F_63 ( V_108 , V_150 ) ;
if ( V_152 < 0 )
V_108 -> V_149 -= V_150 ;
F_66 ( & V_108 -> V_158 -> V_159 ) ;
return V_152 ;
}
static int F_67 ( struct V_160 * V_161 ,
struct V_160 * V_162 , T_1 V_18 )
{
int V_163 = F_55 ( V_161 -> V_108 ) ;
int V_164 = F_55 ( V_162 -> V_108 ) ;
int V_152 ;
if ( ! ( V_18 & V_165 ) ) {
F_63 ( V_161 -> V_108 , - V_164 ) ;
F_63 ( V_162 -> V_108 , - V_163 ) ;
return 0 ;
}
V_152 = F_63 ( V_161 -> V_108 , V_164 ) ;
if ( V_152 < 0 )
return V_152 ;
V_152 = F_63 ( V_162 -> V_108 , V_163 ) ;
if ( V_152 < 0 )
F_63 ( V_161 -> V_108 , - V_164 ) ;
return V_152 ;
}
static int F_68 ( struct V_99 * V_100 ,
enum V_166 V_167 )
{
struct V_1 * V_2 = V_100 -> V_132 -> V_2 ;
struct V_144 * V_108 ;
struct V_160 * V_168 ;
struct V_151 * V_107 ;
unsigned long V_18 ;
int V_152 ;
if ( ( V_100 -> V_169 & V_2 -> V_170 ) &
( 1U << V_2 -> V_113 . V_107 . V_108 . V_8 ) )
return - V_171 ;
F_12 ( & V_100 -> V_19 , V_18 ) ;
V_100 -> V_172 &= ~ ( V_173 | V_174 ) ;
F_13 ( & V_100 -> V_19 , V_18 ) ;
V_100 -> V_175 = false ;
V_108 = & V_100 -> V_132 -> V_176 . V_108 ;
while ( 1 ) {
V_168 = & V_108 -> V_177 [ 0 ] ;
if ( ! ( V_168 -> V_18 & V_178 ) )
break;
V_168 = F_69 ( V_168 ) ;
if ( V_168 == NULL ||
F_58 ( V_168 -> V_108 ) != V_153 )
break;
V_108 = V_168 -> V_108 ;
V_107 = F_60 ( V_108 ) ;
V_152 = F_61 ( V_107 , V_176 , V_179 , V_167 ) ;
if ( V_152 < 0 && V_152 != - V_156 )
return V_152 ;
if ( V_107 == & V_2 -> V_93 . V_107 ) {
F_61 ( & V_2 -> V_122 . V_107 , V_176 ,
V_179 , V_167 ) ;
F_61 ( & V_2 -> V_120 . V_107 , V_176 ,
V_179 , V_167 ) ;
F_61 ( & V_2 -> V_94 . V_107 , V_176 ,
V_179 , V_167 ) ;
V_100 -> V_175 = true ;
}
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
return F_71 ( & V_2 -> V_118 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
return F_73 ( & V_2 -> V_113 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
return F_75 ( & V_2 -> V_120 )
|| F_75 ( & V_2 -> V_122 )
|| F_75 ( & V_2 -> V_94 )
|| F_36 ( & V_2 -> V_93 ) ;
}
static int F_76 ( struct V_1 * V_2 ,
int (* F_77)( struct V_1 * V_2 ) )
{
unsigned long V_180 = V_181 + V_182 ;
while ( ! F_78 ( V_181 , V_180 ) ) {
if ( ! F_77 ( V_2 ) )
return 0 ;
}
return 1 ;
}
static int F_79 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = V_100 -> V_132 -> V_2 ;
struct V_144 * V_108 ;
struct V_160 * V_168 ;
struct V_151 * V_107 ;
int V_183 = 0 ;
int V_152 ;
V_108 = & V_100 -> V_132 -> V_176 . V_108 ;
while ( 1 ) {
V_168 = & V_108 -> V_177 [ 0 ] ;
if ( ! ( V_168 -> V_18 & V_178 ) )
break;
V_168 = F_69 ( V_168 ) ;
if ( V_168 == NULL ||
F_58 ( V_168 -> V_108 ) != V_153 )
break;
V_108 = V_168 -> V_108 ;
V_107 = F_60 ( V_108 ) ;
if ( V_107 == & V_2 -> V_93 . V_107 ) {
F_61 ( & V_2 -> V_122 . V_107 ,
V_176 , V_179 , 0 ) ;
F_61 ( & V_2 -> V_120 . V_107 ,
V_176 , V_179 , 0 ) ;
F_61 ( & V_2 -> V_94 . V_107 ,
V_176 , V_179 , 0 ) ;
}
F_61 ( V_107 , V_176 , V_179 , 0 ) ;
if ( V_107 == & V_2 -> V_118 . V_107 )
V_152 = F_76 ( V_2 , F_70 ) ;
else if ( V_107 == & V_2 -> V_113 . V_107 )
V_152 = F_76 ( V_2 , F_72 ) ;
else if ( V_107 == & V_2 -> V_93 . V_107 )
V_152 = F_76 ( V_2 , F_74 ) ;
else
V_152 = 0 ;
if ( V_152 ) {
F_80 ( V_2 -> V_24 , L_42 , V_107 -> V_33 ) ;
V_2 -> V_170 |= 1U << V_107 -> V_108 . V_8 ;
V_183 = - V_184 ;
}
}
return V_183 ;
}
int F_81 ( struct V_99 * V_100 ,
enum V_166 V_172 )
{
int V_152 ;
if ( V_172 == V_185 )
V_152 = F_79 ( V_100 ) ;
else
V_152 = F_68 ( V_100 , V_172 ) ;
if ( V_152 == 0 || V_172 == V_185 )
V_100 -> V_186 = V_172 ;
return V_152 ;
}
static void F_82 ( struct V_99 * V_100 )
{
int V_187 = V_100 -> V_186 == V_188 ;
F_83 ( V_100 -> V_132 , ! V_187 ) ;
if ( V_187 )
F_83 ( V_100 -> V_72 , 0 ) ;
F_68 ( V_100 , V_100 -> V_186 ) ;
}
static void F_84 ( struct V_99 * V_100 )
{
F_79 ( V_100 ) ;
}
static int F_85 ( struct V_144 * V_189 )
{
struct V_99 * V_100 ;
struct V_160 * V_168 ;
if ( ! V_189 -> V_100 )
return 0 ;
V_100 = F_42 ( V_189 ) ;
if ( V_100 -> V_186 == V_185 )
return 0 ;
V_168 = F_69 ( & V_100 -> V_132 -> V_168 ) ;
return V_168 -> V_108 == V_189 ;
}
static void F_86 ( struct V_144 * V_189 )
{
if ( F_85 ( V_189 ) )
F_84 ( F_42 ( V_189 ) ) ;
}
static void F_87 ( struct V_144 * V_189 )
{
if ( F_85 ( V_189 ) )
F_82 ( F_42 ( V_189 ) ) ;
}
static int F_88 ( struct V_1 * V_2 )
{
unsigned long V_180 ;
F_89 ( & V_2 -> V_122 ) ;
F_89 ( & V_2 -> V_120 ) ;
F_89 ( & V_2 -> V_94 ) ;
F_86 ( & V_2 -> V_118 . V_107 . V_108 ) ;
F_86 ( & V_2 -> V_113 . V_107 . V_108 ) ;
F_86 ( & V_2 -> V_93 . V_107 . V_108 ) ;
F_86 ( & V_2 -> V_110 . V_107 . V_108 ) ;
F_86 ( & V_2 -> V_106 . V_107 . V_108 ) ;
V_180 = V_181 + V_182 ;
while ( F_75 ( & V_2 -> V_120 )
|| F_75 ( & V_2 -> V_122 )
|| F_75 ( & V_2 -> V_94 )
|| F_73 ( & V_2 -> V_113 )
|| F_71 ( & V_2 -> V_118 )
|| F_36 ( & V_2 -> V_93 ) ) {
if ( F_78 ( V_181 , V_180 ) ) {
F_80 ( V_2 -> V_24 , L_43 ) ;
return 1 ;
}
F_90 ( 1 ) ;
}
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
F_92 ( & V_2 -> V_122 ) ;
F_92 ( & V_2 -> V_120 ) ;
F_92 ( & V_2 -> V_94 ) ;
F_87 ( & V_2 -> V_118 . V_107 . V_108 ) ;
F_87 ( & V_2 -> V_113 . V_107 . V_108 ) ;
F_87 ( & V_2 -> V_93 . V_107 . V_108 ) ;
F_87 ( & V_2 -> V_110 . V_107 . V_108 ) ;
F_87 ( & V_2 -> V_106 . V_107 . V_108 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
unsigned long V_180 = 0 ;
F_2 ( V_2 ,
F_3 ( V_2 , V_3 , V_66 )
| V_190 ,
V_3 , V_66 ) ;
while ( ! ( F_3 ( V_2 , V_3 ,
V_191 ) & 0x1 ) ) {
if ( V_180 ++ > 10000 ) {
F_94 ( V_2 -> V_24 , L_44 ) ;
return - V_184 ;
}
F_95 ( 1 ) ;
}
V_2 -> V_170 = 0 ;
return 0 ;
}
static void
F_96 ( struct V_1 * V_2 , struct V_192 * V_193 )
{
struct V_192 * V_194 = V_193 ;
for (; V_194 -> V_195 != V_196 ; V_194 ++ )
V_194 -> V_197 = F_3 ( V_2 , V_194 -> V_198 , V_194 -> V_195 ) ;
}
static void
F_97 ( struct V_1 * V_2 , struct V_192 * V_193 )
{
struct V_192 * V_194 = V_193 ;
for (; V_194 -> V_195 != V_196 ; V_194 ++ )
F_2 ( V_2 , V_194 -> V_197 , V_194 -> V_198 , V_194 -> V_195 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
F_96 ( V_2 , V_199 ) ;
F_99 ( V_2 -> V_24 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
F_97 ( V_2 , V_199 ) ;
F_101 ( V_2 -> V_24 ) ;
F_102 ( V_2 ) ;
F_103 ( V_2 ) ;
}
void F_104 ( struct V_1 * V_2 , enum V_200 V_201 )
{
T_1 V_202 = 0 ;
V_2 -> V_203 |= V_201 ;
if ( V_2 -> V_203 & V_204 )
V_202 |= V_205 ;
if ( V_2 -> V_203 & V_206 )
V_202 |= V_207 ;
if ( V_2 -> V_203 & V_208 )
V_202 |= V_209 ;
if ( V_2 -> V_203 & V_210 )
V_202 |= V_211 ;
if ( V_2 -> V_203 & V_212 )
V_202 |= V_213 ;
if ( V_2 -> V_203 & V_214 )
V_202 |= V_215 ;
F_105 ( V_2 , V_3 , V_70 , V_202 ) ;
}
void F_106 ( struct V_1 * V_2 , enum V_200 V_201 )
{
T_1 V_202 = 0 ;
V_2 -> V_203 &= ~ V_201 ;
if ( ! ( V_2 -> V_203 & V_204 ) )
V_202 |= V_205 ;
if ( ! ( V_2 -> V_203 & V_206 ) )
V_202 |= V_207 ;
if ( ! ( V_2 -> V_203 & V_208 ) )
V_202 |= V_209 ;
if ( ! ( V_2 -> V_203 & V_210 ) )
V_202 |= V_211 ;
if ( ! ( V_2 -> V_203 & V_212 ) )
V_202 |= V_213 ;
if ( ! ( V_2 -> V_203 & V_214 ) )
V_202 |= V_215 ;
F_107 ( V_2 , V_3 , V_70 , V_202 ) ;
}
int F_108 ( struct V_144 * V_189 , T_3 * V_216 ,
T_4 * V_217 )
{
struct V_99 * V_100 = F_42 ( V_189 ) ;
if ( V_100 -> V_186 == V_185 ||
( V_100 -> V_186 == V_188 &&
! F_109 ( V_100 ) ) )
return 0 ;
F_38 ( V_217 , 1 ) ;
F_110 () ;
if ( F_85 ( V_189 ) ) {
struct V_218 * V_176 = V_100 -> V_132 ;
unsigned long V_18 ;
F_12 ( & V_176 -> V_219 -> V_220 , V_18 ) ;
if ( V_176 -> V_221 & V_222 ) {
F_13 ( & V_176 -> V_219 -> V_220 , V_18 ) ;
F_38 ( V_217 , 0 ) ;
F_110 () ;
return 0 ;
}
F_13 ( & V_176 -> V_219 -> V_220 , V_18 ) ;
if ( ! F_111 ( * V_216 , ! F_112 ( V_217 ) ,
F_113 ( 1000 ) ) ) {
F_38 ( V_217 , 0 ) ;
F_110 () ;
return - V_184 ;
}
}
return 0 ;
}
int F_114 ( T_3 * V_216 ,
T_4 * V_217 )
{
if ( F_115 ( V_217 , 1 , 0 ) ) {
F_116 ( V_216 ) ;
return 1 ;
}
return 0 ;
}
static void F_117 ( struct V_1 * V_2 )
{
T_1 V_32 = 0 ;
if ( V_2 -> V_223 &
( V_224 | V_225 ) )
V_32 |= V_226 ;
if ( V_2 -> V_223 & V_227 )
V_32 |= V_228 ;
if ( V_2 -> V_223 & V_229 )
V_32 |= V_230 ;
if ( V_2 -> V_223 & V_231 )
V_32 |= V_232 | V_233 ;
if ( V_2 -> V_223 & V_234 )
V_32 |= V_235 | V_236 ;
F_5 ( V_2 , V_3 , V_70 ,
V_237 , V_32 ) ;
}
void F_118 ( struct V_1 * V_2 ,
enum V_238 V_201 )
{
V_2 -> V_223 |= V_201 ;
F_117 ( V_2 ) ;
}
void F_119 ( struct V_1 * V_2 ,
enum V_238 V_201 )
{
V_2 -> V_223 &= ~ V_201 ;
F_117 ( V_2 ) ;
}
static int F_120 ( struct V_1 * V_2 )
{
int V_239 ;
unsigned long V_22 ;
V_239 = F_121 ( V_2 -> clock [ V_240 ] ) ;
if ( V_239 ) {
F_122 ( V_2 -> V_24 , L_45 ) ;
goto V_241;
}
V_239 = F_123 ( V_2 -> clock [ V_242 ] , V_243 ) ;
if ( V_239 ) {
F_122 ( V_2 -> V_24 , L_46 ) ;
goto V_244;
}
V_239 = F_121 ( V_2 -> clock [ V_242 ] ) ;
if ( V_239 ) {
F_122 ( V_2 -> V_24 , L_47 ) ;
goto V_244;
}
V_22 = F_124 ( V_2 -> clock [ V_242 ] ) ;
if ( V_22 != V_243 )
F_125 ( V_2 -> V_24 , L_48
L_49
L_50 , V_243 , V_22 ) ;
V_239 = F_121 ( V_2 -> clock [ V_245 ] ) ;
if ( V_239 ) {
F_122 ( V_2 -> V_24 , L_51 ) ;
goto V_246;
}
return 0 ;
V_246:
F_126 ( V_2 -> clock [ V_242 ] ) ;
V_244:
F_126 ( V_2 -> clock [ V_240 ] ) ;
V_241:
return V_239 ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_126 ( V_2 -> clock [ V_240 ] ) ;
F_126 ( V_2 -> clock [ V_242 ] ) ;
F_126 ( V_2 -> clock [ V_245 ] ) ;
}
static int F_128 ( struct V_1 * V_2 )
{
struct V_32 * V_32 ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_22 ( V_247 ) ; ++ V_30 ) {
V_32 = F_129 ( V_2 -> V_24 , V_247 [ V_30 ] ) ;
if ( F_25 ( V_32 ) ) {
F_122 ( V_2 -> V_24 , L_52 , V_247 [ V_30 ] ) ;
return F_26 ( V_32 ) ;
}
V_2 -> clock [ V_30 ] = V_32 ;
}
return 0 ;
}
static struct V_1 * F_130 ( struct V_1 * V_2 , bool V_44 )
{
struct V_1 * V_248 = V_2 ;
if ( V_2 == NULL )
return NULL ;
F_65 ( & V_2 -> V_249 ) ;
if ( V_2 -> V_250 > 0 )
goto V_251;
if ( F_120 ( V_2 ) < 0 ) {
V_248 = NULL ;
goto V_251;
}
if ( V_2 -> V_252 )
F_100 ( V_2 ) ;
if ( V_44 )
F_31 ( V_2 ) ;
V_251:
if ( V_248 != NULL )
V_2 -> V_250 ++ ;
F_66 ( & V_2 -> V_249 ) ;
return V_248 ;
}
struct V_1 * F_8 ( struct V_1 * V_2 )
{
return F_130 ( V_2 , true ) ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_65 ( & V_2 -> V_249 ) ;
F_131 ( V_2 -> V_250 == 0 ) ;
if ( -- V_2 -> V_250 == 0 ) {
F_32 ( V_2 ) ;
if ( V_2 -> V_253 ) {
F_98 ( V_2 ) ;
V_2 -> V_252 = 1 ;
}
if ( V_2 -> V_170 )
F_93 ( V_2 ) ;
F_127 ( V_2 ) ;
}
F_66 ( & V_2 -> V_249 ) ;
}
void F_132 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_24 , L_53 ) ;
F_133 ( V_2 , V_254 ) ;
F_133 ( V_2 , V_255 ) ;
F_133 ( V_2 , V_256 ) ;
F_133 ( V_2 , V_257 ) ;
F_133 ( V_2 , V_258 ) ;
F_133 ( V_2 , V_259 ) ;
F_133 ( V_2 , V_260 ) ;
F_133 ( V_2 , V_261 ) ;
F_133 ( V_2 , V_262 ) ;
F_133 ( V_2 , V_263 ) ;
F_133 ( V_2 , V_264 ) ;
F_133 ( V_2 , V_265 ) ;
F_133 ( V_2 , V_266 ) ;
F_133 ( V_2 , V_267 ) ;
F_133 ( V_2 , V_268 ) ;
F_134 ( V_2 , V_269 ) ;
F_134 ( V_2 , V_270 ) ;
F_20 ( V_2 -> V_24 , L_54 ) ;
}
static int F_135 ( struct V_98 * V_24 )
{
struct V_1 * V_2 = F_136 ( V_24 ) ;
int V_271 ;
F_62 ( F_137 ( & V_2 -> V_249 ) ) ;
if ( V_2 -> V_250 == 0 )
return 0 ;
V_271 = F_88 ( V_2 ) ;
F_32 ( V_2 ) ;
F_98 ( V_2 ) ;
if ( V_271 )
F_93 ( V_2 ) ;
return 0 ;
}
static int F_138 ( struct V_98 * V_24 )
{
struct V_1 * V_2 = F_136 ( V_24 ) ;
F_62 ( F_137 ( & V_2 -> V_249 ) ) ;
if ( V_2 -> V_250 )
F_127 ( V_2 ) ;
return 0 ;
}
static int F_139 ( struct V_98 * V_24 )
{
struct V_1 * V_2 = F_136 ( V_24 ) ;
if ( V_2 -> V_250 == 0 )
return 0 ;
return F_120 ( V_2 ) ;
}
static void F_140 ( struct V_98 * V_24 )
{
struct V_1 * V_2 = F_136 ( V_24 ) ;
if ( V_2 -> V_250 == 0 )
return;
F_100 ( V_2 ) ;
F_31 ( V_2 ) ;
F_91 ( V_2 ) ;
}
static void F_141 ( struct V_1 * V_2 )
{
F_142 ( & V_2 -> V_110 ) ;
F_143 ( & V_2 -> V_106 ) ;
F_144 ( & V_2 -> V_93 ) ;
F_145 ( & V_2 -> V_113 ) ;
F_146 ( & V_2 -> V_118 ) ;
F_147 ( & V_2 -> V_122 ) ;
F_147 ( & V_2 -> V_120 ) ;
F_147 ( & V_2 -> V_94 ) ;
F_148 ( & V_2 -> V_272 ) ;
F_149 ( & V_2 -> V_273 ) ;
}
static struct V_151 *
F_150 ( struct V_1 * V_2 ,
struct V_274 * V_275 )
{
struct V_151 * V_276 = NULL ;
unsigned int V_157 ;
if ( V_275 -> V_275 == NULL )
return NULL ;
for ( V_157 = 1 ; V_275 -> V_275 ; ++ V_275 , V_157 = 0 ) {
struct V_151 * V_107 ;
struct V_277 * V_278 ;
V_278 = F_151 ( V_275 -> V_279 ) ;
if ( V_278 == NULL ) {
F_122 ( V_2 -> V_24 , L_55
L_56 , V_25 ,
V_275 -> V_279 ,
V_275 -> V_275 -> type ) ;
continue;
}
V_107 = F_152 ( & V_2 -> V_272 , V_278 ,
V_275 -> V_275 , NULL ) ;
if ( V_107 == NULL ) {
F_122 ( V_2 -> V_24 , L_57 ,
V_25 , V_275 -> V_275 -> type ) ;
continue;
}
if ( V_157 )
V_276 = V_107 ;
}
return V_276 ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_280 * V_281 ;
int V_152 ;
V_2 -> V_273 . V_24 = V_2 -> V_24 ;
F_154 ( V_2 -> V_273 . V_282 , L_58 ,
sizeof( V_2 -> V_273 . V_282 ) ) ;
V_2 -> V_273 . V_283 = V_2 -> V_63 ;
V_2 -> V_273 . V_284 = F_67 ;
V_152 = F_155 ( & V_2 -> V_273 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_59 ,
V_25 , V_152 ) ;
return V_152 ;
}
V_2 -> V_272 . V_285 = & V_2 -> V_273 ;
V_152 = F_156 ( V_2 -> V_24 , & V_2 -> V_272 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_60 ,
V_25 , V_152 ) ;
goto V_286;
}
V_152 = F_157 ( & V_2 -> V_106 , & V_2 -> V_272 ) ;
if ( V_152 < 0 )
goto V_286;
V_152 = F_158 ( & V_2 -> V_110 , & V_2 -> V_272 ) ;
if ( V_152 < 0 )
goto V_286;
V_152 = F_159 ( & V_2 -> V_93 , & V_2 -> V_272 ) ;
if ( V_152 < 0 )
goto V_286;
V_152 = F_160 ( & V_2 -> V_113 ,
& V_2 -> V_272 ) ;
if ( V_152 < 0 )
goto V_286;
V_152 = F_161 ( & V_2 -> V_118 , & V_2 -> V_272 ) ;
if ( V_152 < 0 )
goto V_286;
V_152 = F_162 ( & V_2 -> V_122 , & V_2 -> V_272 ) ;
if ( V_152 < 0 )
goto V_286;
V_152 = F_162 ( & V_2 -> V_120 , & V_2 -> V_272 ) ;
if ( V_152 < 0 )
goto V_286;
V_152 = F_162 ( & V_2 -> V_94 , & V_2 -> V_272 ) ;
if ( V_152 < 0 )
goto V_286;
for ( V_281 = V_27 -> V_281 ; V_281 && V_281 -> V_281 ; ++ V_281 ) {
struct V_151 * V_276 ;
struct V_144 * V_72 ;
unsigned int V_18 ;
unsigned int V_168 ;
unsigned int V_30 ;
V_276 = F_150 ( V_2 , V_281 -> V_281 ) ;
if ( V_276 == NULL )
continue;
V_276 -> V_287 = V_281 ;
switch ( V_281 -> V_288 ) {
case V_289 :
V_72 = & V_2 -> V_93 . V_107 . V_108 ;
V_168 = V_290 ;
V_18 = 0 ;
break;
case V_291 :
V_72 = & V_2 -> V_110 . V_107 . V_108 ;
V_168 = V_292 ;
V_18 = V_293
| V_165 ;
break;
case V_294 :
case V_295 :
V_72 = & V_2 -> V_106 . V_107 . V_108 ;
V_168 = V_296 ;
V_18 = 0 ;
break;
case V_297 :
V_72 = & V_2 -> V_298 . V_107 . V_108 ;
V_168 = V_292 ;
V_18 = V_293
| V_165 ;
break;
default:
F_122 ( V_2 -> V_24 , L_61 ,
V_25 , V_281 -> V_288 ) ;
V_152 = - V_299 ;
goto V_286;
}
for ( V_30 = 0 ; V_30 < V_276 -> V_108 . V_300 ; V_30 ++ ) {
if ( V_276 -> V_108 . V_177 [ V_30 ] . V_18 & V_301 )
break;
}
if ( V_30 == V_276 -> V_108 . V_300 ) {
F_122 ( V_2 -> V_24 ,
L_62 ,
V_25 ) ;
V_152 = - V_299 ;
goto V_286;
}
V_152 = F_163 ( & V_276 -> V_108 , V_30 , V_72 , V_168 ,
V_18 ) ;
if ( V_152 < 0 )
goto V_286;
}
V_152 = F_164 ( & V_2 -> V_272 ) ;
V_286:
if ( V_152 < 0 )
F_141 ( V_2 ) ;
return V_152 ;
}
static void F_165 ( struct V_1 * V_2 )
{
F_166 ( V_2 ) ;
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
int V_152 ;
V_152 = F_175 ( V_2 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_63 ) ;
goto V_302;
}
V_152 = F_176 ( V_2 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_64 ) ;
goto V_303;
}
V_152 = F_177 ( V_2 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_65 ) ;
goto V_304;
}
V_152 = F_178 ( V_2 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_66 ) ;
goto V_305;
}
V_152 = F_179 ( V_2 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_67 ) ;
goto V_306;
}
V_152 = F_180 ( V_2 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_68 ) ;
goto V_307;
}
V_152 = F_181 ( V_2 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_69 ) ;
goto V_308;
}
V_152 = F_182 ( V_2 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_70 ) ;
goto V_309;
}
V_152 = F_183 ( V_2 ) ;
if ( V_152 < 0 ) {
F_122 ( V_2 -> V_24 , L_71 ) ;
goto V_310;
}
V_152 = F_163 (
& V_2 -> V_110 . V_107 . V_108 , V_311 ,
& V_2 -> V_93 . V_107 . V_108 , V_290 , 0 ) ;
if ( V_152 < 0 )
goto V_312;
V_152 = F_163 (
& V_2 -> V_106 . V_107 . V_108 , V_313 ,
& V_2 -> V_93 . V_107 . V_108 , V_290 , 0 ) ;
if ( V_152 < 0 )
goto V_312;
V_152 = F_163 (
& V_2 -> V_93 . V_107 . V_108 , V_314 ,
& V_2 -> V_113 . V_107 . V_108 , V_315 , 0 ) ;
if ( V_152 < 0 )
goto V_312;
V_152 = F_163 (
& V_2 -> V_93 . V_107 . V_108 , V_316 ,
& V_2 -> V_118 . V_107 . V_108 , V_317 , 0 ) ;
if ( V_152 < 0 )
goto V_312;
V_152 = F_163 (
& V_2 -> V_113 . V_107 . V_108 , V_318 ,
& V_2 -> V_118 . V_107 . V_108 , V_317 , 0 ) ;
if ( V_152 < 0 )
goto V_312;
V_152 = F_163 (
& V_2 -> V_93 . V_107 . V_108 , V_314 ,
& V_2 -> V_122 . V_107 . V_108 , 0 ,
V_165 | V_293 ) ;
if ( V_152 < 0 )
goto V_312;
V_152 = F_163 (
& V_2 -> V_93 . V_107 . V_108 , V_314 ,
& V_2 -> V_120 . V_107 . V_108 , 0 ,
V_165 | V_293 ) ;
if ( V_152 < 0 )
goto V_312;
V_152 = F_163 (
& V_2 -> V_93 . V_107 . V_108 , V_314 ,
& V_2 -> V_94 . V_107 . V_108 , 0 ,
V_165 | V_293 ) ;
if ( V_152 < 0 )
goto V_312;
return 0 ;
V_312:
F_167 ( V_2 ) ;
V_310:
F_166 ( V_2 ) ;
V_309:
F_168 ( V_2 ) ;
V_308:
F_169 ( V_2 ) ;
V_307:
F_170 ( V_2 ) ;
V_306:
F_171 ( V_2 ) ;
V_305:
F_172 ( V_2 ) ;
V_304:
F_173 ( V_2 ) ;
V_303:
V_302:
return V_152 ;
}
static int F_184 ( struct V_319 * V_320 )
{
struct V_1 * V_2 = F_185 ( V_320 ) ;
F_141 ( V_2 ) ;
F_165 ( V_2 ) ;
F_29 ( V_2 ) ;
F_130 ( V_2 , false ) ;
F_186 ( V_2 -> V_253 , & V_320 -> V_24 ) ;
F_187 ( V_2 -> V_253 ) ;
V_2 -> V_253 = NULL ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_188 ( struct V_319 * V_320 ,
struct V_1 * V_2 ,
enum V_321 V_201 )
{
struct V_322 * V_323 ;
V_323 = F_189 ( V_320 , V_324 , V_201 ) ;
if ( ! V_323 ) {
F_122 ( V_2 -> V_24 , L_72 ) ;
return - V_325 ;
}
if ( ! F_190 ( V_2 -> V_24 , V_323 -> V_326 , F_191 ( V_323 ) ,
V_320 -> V_33 ) ) {
F_122 ( V_2 -> V_24 ,
L_73 ) ;
return - V_325 ;
}
V_2 -> V_327 [ V_201 ] = V_323 -> V_326 ;
V_2 -> V_328 [ V_201 ] = F_191 ( V_323 ) ;
V_2 -> V_329 [ V_201 ] = F_192 ( V_2 -> V_24 ,
V_2 -> V_327 [ V_201 ] ,
V_2 -> V_328 [ V_201 ] ) ;
if ( ! V_2 -> V_329 [ V_201 ] ) {
F_122 ( V_2 -> V_24 , L_74 ) ;
return - V_325 ;
}
return 0 ;
}
static int F_193 ( struct V_319 * V_320 )
{
struct V_26 * V_27 = V_320 -> V_24 . V_330 ;
struct V_1 * V_2 ;
int V_152 ;
int V_30 , V_331 ;
if ( V_27 == NULL )
return - V_299 ;
V_2 = F_194 ( & V_320 -> V_24 , sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 ) {
F_122 ( & V_320 -> V_24 , L_75 ) ;
return - V_43 ;
}
V_2 -> V_67 = V_67 ;
F_195 ( & V_2 -> V_249 ) ;
F_23 ( & V_2 -> V_332 ) ;
V_2 -> V_24 = & V_320 -> V_24 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_250 = 0 ;
V_2 -> V_333 = F_196 ( 32 ) ;
V_2 -> V_24 -> V_334 = & V_2 -> V_333 ;
V_2 -> V_24 -> V_335 = F_196 ( 32 ) ;
F_197 ( V_320 , V_2 ) ;
V_2 -> V_336 . V_337 = F_198 ( & V_320 -> V_24 , L_76 ) ;
V_2 -> V_338 . V_337 = F_198 ( & V_320 -> V_24 , L_77 ) ;
V_152 = F_188 ( V_320 , V_2 , V_3 ) ;
if ( V_152 < 0 )
goto error;
V_152 = F_128 ( V_2 ) ;
if ( V_152 < 0 )
goto error;
V_152 = F_199 ( V_2 -> clock [ V_240 ] ) ;
if ( V_152 < 0 )
goto error;
V_2 -> V_63 = F_3 ( V_2 , V_3 , V_4 ) ;
F_80 ( V_2 -> V_24 , L_78 ,
( V_2 -> V_63 & 0xf0 ) >> 4 , V_2 -> V_63 & 0x0f ) ;
F_200 ( V_2 -> clock [ V_240 ] ) ;
if ( F_130 ( V_2 , false ) == NULL ) {
V_152 = - V_325 ;
goto error;
}
V_152 = F_93 ( V_2 ) ;
if ( V_152 < 0 )
goto V_339;
V_152 = F_21 ( V_2 ) ;
if ( V_152 < 0 )
goto V_339;
for ( V_331 = 0 ; V_331 < F_22 ( V_340 ) ; V_331 ++ )
if ( V_2 -> V_63 == V_340 [ V_331 ] . V_341 )
break;
if ( V_331 == F_22 ( V_340 ) ) {
F_122 ( V_2 -> V_24 , L_79 ,
( V_2 -> V_63 & 0xf0 ) >> 4 , V_2 -> V_63 & 0xf ) ;
V_152 = - V_325 ;
goto V_339;
}
for ( V_30 = 1 ; V_30 < V_342 ; V_30 ++ ) {
if ( V_340 [ V_331 ] . V_343 & 1 << V_30 ) {
V_152 = F_188 ( V_320 , V_2 , V_30 ) ;
if ( V_152 )
goto V_339;
}
}
V_2 -> V_253 = F_201 ( V_320 -> V_24 . V_344 ) ;
if ( ! V_2 -> V_253 ) {
F_122 ( V_2 -> V_24 , L_80 ) ;
V_152 = - V_43 ;
goto V_339;
}
V_152 = F_202 ( V_2 -> V_253 , & V_320 -> V_24 ) ;
if ( V_152 ) {
F_122 ( & V_320 -> V_24 , L_81 , V_152 ) ;
goto V_345;
}
V_2 -> V_346 = F_203 ( V_320 , 0 ) ;
if ( V_2 -> V_346 <= 0 ) {
F_122 ( V_2 -> V_24 , L_82 ) ;
V_152 = - V_325 ;
goto V_347;
}
if ( F_204 ( V_2 -> V_24 , V_2 -> V_346 , F_44 , V_348 ,
L_83 , V_2 ) ) {
F_122 ( V_2 -> V_24 , L_84 ) ;
V_152 = - V_299 ;
goto V_347;
}
V_152 = F_174 ( V_2 ) ;
if ( V_152 < 0 )
goto V_347;
V_152 = F_153 ( V_2 ) ;
if ( V_152 < 0 )
goto V_349;
F_33 ( V_2 , 1 ) ;
F_10 ( V_2 ) ;
return 0 ;
V_349:
F_165 ( V_2 ) ;
V_347:
F_186 ( V_2 -> V_253 , & V_320 -> V_24 ) ;
V_345:
F_187 ( V_2 -> V_253 ) ;
V_339:
F_29 ( V_2 ) ;
F_10 ( V_2 ) ;
error:
F_197 ( V_320 , NULL ) ;
F_205 ( & V_2 -> V_249 ) ;
return V_152 ;
}
