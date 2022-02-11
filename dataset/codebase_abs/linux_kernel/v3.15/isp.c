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
for ( V_30 = 0 ; V_30 < F_22 ( V_2 -> V_31 ) ; ++ V_30 )
V_2 -> V_31 [ V_30 ] . V_32 = F_23 ( - V_33 ) ;
for ( V_30 = 0 ; V_30 < F_22 ( V_2 -> V_31 ) ; ++ V_30 ) {
struct V_5 * V_6 = & V_2 -> V_31 [ V_30 ] ;
V_6 -> V_2 = V_2 ;
V_6 -> V_8 = V_30 == 0 ? V_9 : V_13 ;
V_6 -> V_7 = 1 ;
F_24 ( & V_6 -> V_19 ) ;
V_29 . V_34 = V_30 == 0 ? L_2 : L_3 ;
V_29 . V_35 = & V_36 ;
V_29 . V_37 = & V_38 ;
V_29 . V_39 = 1 ;
V_6 -> V_17 . V_29 = & V_29 ;
V_6 -> V_32 = F_25 ( NULL , & V_6 -> V_17 ) ;
if ( F_26 ( V_6 -> V_32 ) )
return F_27 ( V_6 -> V_32 ) ;
if ( V_27 -> V_31 [ V_30 ] . V_40 == NULL &&
V_27 -> V_31 [ V_30 ] . V_41 == NULL )
continue;
V_6 -> V_42 = F_28 ( sizeof( * V_6 -> V_42 ) , V_43 ) ;
if ( V_6 -> V_42 == NULL )
return - V_44 ;
V_6 -> V_42 -> V_40 = V_27 -> V_31 [ V_30 ] . V_40 ;
V_6 -> V_42 -> V_41 = V_27 -> V_31 [ V_30 ] . V_41 ;
V_6 -> V_42 -> V_32 = V_6 -> V_32 ;
F_29 ( V_6 -> V_42 ) ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_22 ( V_2 -> V_31 ) ; ++ V_30 ) {
struct V_5 * V_6 = & V_2 -> V_31 [ V_30 ] ;
if ( ! F_26 ( V_6 -> V_32 ) )
F_31 ( V_6 -> V_32 ) ;
if ( V_6 -> V_42 )
F_32 ( V_6 -> V_42 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
static const T_1 V_45 = V_46
| V_47
| V_48
| V_49
| V_50
| V_51
| V_52
| V_53
| V_54
| V_55
| V_56
| V_57 ;
F_2 ( V_2 , V_45 , V_3 , V_58 ) ;
F_2 ( V_2 , V_45 , V_3 , V_59 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , V_59 ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_60 )
{
F_2 ( V_2 ,
( ( V_60 ? V_61 :
V_62 ) <<
V_63 ) |
( ( V_2 -> V_64 == V_65 ) ?
V_66 : 0 ) ,
V_3 , V_67 ) ;
F_2 ( V_2 ,
( V_2 -> V_68 ? V_69 : 0 ) |
V_70 ,
V_3 , V_71 ) ;
}
void F_36 ( struct V_1 * V_2 ,
enum V_72 V_73 ,
const struct V_74 * V_27 ,
unsigned int V_75 , unsigned int V_76 )
{
T_1 V_77 ;
V_77 = F_3 ( V_2 , V_3 , V_71 ) ;
V_77 &= ~ V_78 ;
V_77 &= ~ V_79 ;
V_77 &= ~ V_80 ;
V_77 &= ~ V_81 ;
V_77 |= V_76 ;
switch ( V_73 ) {
case V_82 :
V_77 |= V_83 ;
V_77 |= V_27 -> V_84 << V_85 ;
V_75 += V_27 -> V_86 * 2 ;
break;
case V_87 :
V_77 |= V_88 ;
break;
case V_89 :
V_77 |= V_90 ;
break;
case V_91 :
V_77 |= V_92 ;
break;
default:
return;
}
V_77 |= ( ( V_75 / 2 ) << V_93 ) & V_78 ;
F_2 ( V_2 , V_77 , V_3 , V_71 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( F_38 ( & V_2 -> V_94 ) ||
F_39 ( & V_2 -> V_95 ) ) {
F_40 ( & V_2 -> V_95 . V_96 , 1 ) ;
F_20 ( V_2 -> V_24 , L_4
L_5 ) ;
}
}
static inline void F_41 ( struct V_1 * V_2 , T_1 V_97 )
{
static const char * V_34 [] = {
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
for ( V_30 = 0 ; V_30 < F_22 ( V_34 ) ; V_30 ++ ) {
if ( ( 1 << V_30 ) & V_97 )
F_42 ( V_98 L_39 , V_34 [ V_30 ] ) ;
}
F_42 ( V_98 L_40 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_99 * V_24 = V_2 -> V_24 ;
struct V_100 * V_101 ;
T_1 V_102 ;
V_102 = F_3 ( V_2 , V_103 , V_104 ) ;
F_2 ( V_2 , V_102 , V_103 , V_104 ) ;
V_102 &= ~ V_105 ;
if ( V_102 )
F_20 ( V_24 , L_41 , V_102 ) ;
if ( V_102 & V_106 ) {
V_101 = F_44 ( & V_2 -> V_107 . V_108 . V_109 ) ;
if ( V_101 != NULL )
V_101 -> error = true ;
}
if ( V_102 & V_110 ) {
V_101 = F_44 ( & V_2 -> V_111 . V_108 . V_109 ) ;
if ( V_101 != NULL )
V_101 -> error = true ;
}
if ( V_102 & V_112 ) {
V_101 = F_44 ( & V_2 -> V_94 . V_108 . V_109 ) ;
if ( V_101 != NULL )
V_101 -> error = true ;
}
if ( V_102 & V_113 ) {
V_101 = F_44 ( & V_2 -> V_114 . V_108 . V_109 ) ;
if ( V_101 != NULL )
V_101 -> error = true ;
}
if ( V_102 & ( V_115
| V_116
| V_117
| V_118 ) ) {
V_101 = F_44 ( & V_2 -> V_119 . V_108 . V_109 ) ;
if ( V_101 != NULL )
V_101 -> error = true ;
}
if ( V_102 & V_120 )
F_45 ( & V_2 -> V_121 ) ;
if ( V_102 & V_122 )
F_45 ( & V_2 -> V_123 ) ;
}
static T_2 F_46 ( int V_45 , void * V_124 )
{
static const T_1 V_125 = V_126 |
V_127 |
V_128 |
V_129 |
V_130 ;
struct V_1 * V_2 = V_124 ;
T_1 V_97 ;
V_97 = F_3 ( V_2 , V_3 , V_58 ) ;
F_2 ( V_2 , V_97 , V_3 , V_58 ) ;
F_43 ( V_2 ) ;
if ( V_97 & V_131 )
F_47 ( & V_2 -> V_111 ) ;
if ( V_97 & V_132 )
F_48 ( & V_2 -> V_107 ) ;
if ( V_97 & V_128 ) {
if ( V_2 -> V_94 . V_133 & V_134 )
F_49 ( & V_2 -> V_114 ) ;
if ( V_2 -> V_94 . V_133 & V_135 )
F_50 ( & V_2 -> V_119 ) ;
F_51 ( & V_2 -> V_123 ) ;
F_51 ( & V_2 -> V_121 ) ;
F_51 ( & V_2 -> V_95 ) ;
}
if ( V_97 & V_125 )
F_52 ( & V_2 -> V_94 , V_97 & V_125 ) ;
if ( V_97 & V_136 ) {
if ( V_2 -> V_114 . V_133 & V_137 )
F_50 ( & V_2 -> V_119 ) ;
F_53 ( & V_2 -> V_114 ) ;
}
if ( V_97 & V_138 )
F_54 ( & V_2 -> V_119 ) ;
if ( V_97 & V_139 )
F_55 ( & V_2 -> V_123 ) ;
if ( V_97 & V_140 )
F_55 ( & V_2 -> V_121 ) ;
if ( V_97 & V_141 )
F_55 ( & V_2 -> V_95 ) ;
F_1 ( V_2 ) ;
#if F_56 ( V_142 ) && F_56 ( V_143 )
F_41 ( V_2 , V_97 ) ;
#endif
return V_144 ;
}
static int F_57 ( struct V_145 * V_109 )
{
struct V_146 V_147 ;
int V_148 = 0 ;
F_58 ( & V_147 , V_109 ) ;
while ( ( V_109 = F_59 ( & V_147 ) ) ) {
if ( F_60 ( V_109 ) == V_149 )
V_148 += V_109 -> V_150 ;
}
return V_148 ;
}
static int F_61 ( struct V_145 * V_109 , int V_151 )
{
struct V_152 * V_108 ;
int V_153 ;
V_108 = F_60 ( V_109 ) == V_154
? F_62 ( V_109 ) : NULL ;
if ( V_109 -> V_150 == 0 && V_151 > 0 && V_108 != NULL ) {
V_153 = F_63 ( V_108 , V_155 , V_156 , 1 ) ;
if ( V_153 < 0 && V_153 != - V_157 )
return V_153 ;
}
V_109 -> V_150 += V_151 ;
F_64 ( V_109 -> V_150 < 0 ) ;
if ( V_109 -> V_150 == 0 && V_151 < 0 && V_108 != NULL )
F_63 ( V_108 , V_155 , V_156 , 0 ) ;
return 0 ;
}
static int F_65 ( struct V_145 * V_109 , int V_151 )
{
struct V_146 V_147 ;
struct V_145 * V_158 = V_109 ;
int V_153 = 0 ;
if ( ! V_151 )
return 0 ;
F_58 ( & V_147 , V_109 ) ;
while ( ! V_153 && ( V_109 = F_59 ( & V_147 ) ) )
if ( F_60 ( V_109 ) != V_149 )
V_153 = F_61 ( V_109 , V_151 ) ;
if ( ! V_153 )
return 0 ;
F_58 ( & V_147 , V_158 ) ;
while ( ( V_158 = F_59 ( & V_147 ) )
&& V_158 != V_109 )
if ( F_60 ( V_158 ) != V_149 )
F_61 ( V_158 , - V_151 ) ;
return V_153 ;
}
int F_66 ( struct V_145 * V_109 , int V_148 )
{
int V_151 = V_148 ? 1 : - 1 ;
int V_153 ;
F_67 ( & V_109 -> V_159 -> V_160 ) ;
V_109 -> V_150 += V_151 ;
F_64 ( V_109 -> V_150 < 0 ) ;
V_153 = F_65 ( V_109 , V_151 ) ;
if ( V_153 < 0 )
V_109 -> V_150 -= V_151 ;
F_68 ( & V_109 -> V_159 -> V_160 ) ;
return V_153 ;
}
static int F_69 ( struct V_161 * V_162 , T_1 V_18 ,
unsigned int V_163 )
{
struct V_145 * V_164 = V_162 -> V_164 -> V_109 ;
struct V_145 * V_165 = V_162 -> V_165 -> V_109 ;
int V_166 = F_57 ( V_164 ) ;
int V_167 = F_57 ( V_165 ) ;
int V_153 ;
if ( V_163 == V_168 &&
! ( V_162 -> V_18 & V_169 ) ) {
F_65 ( V_164 , - V_167 ) ;
F_65 ( V_165 , - V_166 ) ;
return 0 ;
}
if ( V_163 == V_168 &&
( V_18 & V_169 ) ) {
V_153 = F_65 ( V_164 , V_167 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_65 ( V_165 , V_166 ) ;
if ( V_153 < 0 )
F_65 ( V_164 , - V_167 ) ;
return V_153 ;
}
return 0 ;
}
static int F_70 ( struct V_100 * V_101 ,
enum V_170 V_171 )
{
struct V_1 * V_2 = V_101 -> V_133 -> V_2 ;
struct V_145 * V_109 ;
struct V_172 * V_173 ;
struct V_152 * V_108 ;
unsigned long V_18 ;
int V_153 ;
if ( V_101 -> V_174 & V_2 -> V_175 )
return - V_176 ;
F_12 ( & V_101 -> V_19 , V_18 ) ;
V_101 -> V_177 &= ~ ( V_178 | V_179 ) ;
F_13 ( & V_101 -> V_19 , V_18 ) ;
V_101 -> V_180 = false ;
V_109 = & V_101 -> V_133 -> V_181 . V_109 ;
while ( 1 ) {
V_173 = & V_109 -> V_182 [ 0 ] ;
if ( ! ( V_173 -> V_18 & V_183 ) )
break;
V_173 = F_71 ( V_173 ) ;
if ( V_173 == NULL ||
F_60 ( V_173 -> V_109 ) != V_154 )
break;
V_109 = V_173 -> V_109 ;
V_108 = F_62 ( V_109 ) ;
V_153 = F_63 ( V_108 , V_181 , V_184 , V_171 ) ;
if ( V_153 < 0 && V_153 != - V_157 )
return V_153 ;
if ( V_108 == & V_2 -> V_94 . V_108 ) {
F_63 ( & V_2 -> V_123 . V_108 , V_181 ,
V_184 , V_171 ) ;
F_63 ( & V_2 -> V_121 . V_108 , V_181 ,
V_184 , V_171 ) ;
F_63 ( & V_2 -> V_95 . V_108 , V_181 ,
V_184 , V_171 ) ;
V_101 -> V_180 = true ;
}
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
return F_73 ( & V_2 -> V_119 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
return F_75 ( & V_2 -> V_114 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
return F_77 ( & V_2 -> V_121 )
|| F_77 ( & V_2 -> V_123 )
|| F_77 ( & V_2 -> V_95 )
|| F_38 ( & V_2 -> V_94 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
int (* F_79)( struct V_1 * V_2 ) )
{
unsigned long V_185 = V_186 + V_187 ;
while ( ! F_80 ( V_186 , V_185 ) ) {
if ( ! F_79 ( V_2 ) )
return 0 ;
}
return 1 ;
}
static int F_81 ( struct V_100 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_133 -> V_2 ;
struct V_145 * V_109 ;
struct V_172 * V_173 ;
struct V_152 * V_108 ;
int V_188 = 0 ;
int V_153 ;
V_109 = & V_101 -> V_133 -> V_181 . V_109 ;
while ( 1 ) {
V_173 = & V_109 -> V_182 [ 0 ] ;
if ( ! ( V_173 -> V_18 & V_183 ) )
break;
V_173 = F_71 ( V_173 ) ;
if ( V_173 == NULL ||
F_60 ( V_173 -> V_109 ) != V_154 )
break;
V_109 = V_173 -> V_109 ;
V_108 = F_62 ( V_109 ) ;
if ( V_108 == & V_2 -> V_94 . V_108 ) {
F_63 ( & V_2 -> V_123 . V_108 ,
V_181 , V_184 , 0 ) ;
F_63 ( & V_2 -> V_121 . V_108 ,
V_181 , V_184 , 0 ) ;
F_63 ( & V_2 -> V_95 . V_108 ,
V_181 , V_184 , 0 ) ;
}
F_63 ( V_108 , V_181 , V_184 , 0 ) ;
if ( V_108 == & V_2 -> V_119 . V_108 )
V_153 = F_78 ( V_2 , F_72 ) ;
else if ( V_108 == & V_2 -> V_114 . V_108 )
V_153 = F_78 ( V_2 , F_74 ) ;
else if ( V_108 == & V_2 -> V_94 . V_108 )
V_153 = F_78 ( V_2 , F_76 ) ;
else
V_153 = 0 ;
if ( V_153 ) {
F_82 ( V_2 -> V_24 , L_42 , V_108 -> V_34 ) ;
V_2 -> V_189 = true ;
if ( V_108 == & V_2 -> V_114 . V_108 )
V_2 -> V_175 |= 1U << V_108 -> V_109 . V_8 ;
V_188 = - V_190 ;
}
}
return V_188 ;
}
int F_83 ( struct V_100 * V_101 ,
enum V_170 V_177 )
{
int V_153 ;
if ( V_177 == V_191 )
V_153 = F_81 ( V_101 ) ;
else
V_153 = F_70 ( V_101 , V_177 ) ;
if ( V_153 == 0 || V_177 == V_191 )
V_101 -> V_192 = V_177 ;
return V_153 ;
}
void F_84 ( struct V_100 * V_101 )
{
if ( V_101 -> V_73 )
F_85 ( V_101 -> V_73 ) ;
if ( V_101 -> V_133 )
F_85 ( V_101 -> V_133 ) ;
}
static void F_86 ( struct V_100 * V_101 )
{
int V_193 = V_101 -> V_192 == V_194 ;
F_87 ( V_101 -> V_133 , ! V_193 ) ;
if ( V_193 )
F_87 ( V_101 -> V_73 , 0 ) ;
F_70 ( V_101 , V_101 -> V_192 ) ;
}
static void F_88 ( struct V_100 * V_101 )
{
F_81 ( V_101 ) ;
}
static int F_89 ( struct V_145 * V_195 )
{
struct V_100 * V_101 ;
struct V_172 * V_173 ;
if ( ! V_195 -> V_101 )
return 0 ;
V_101 = F_44 ( V_195 ) ;
if ( V_101 -> V_192 == V_191 )
return 0 ;
V_173 = F_71 ( & V_101 -> V_133 -> V_173 ) ;
return V_173 -> V_109 == V_195 ;
}
static void F_90 ( struct V_145 * V_195 )
{
if ( F_89 ( V_195 ) )
F_88 ( F_44 ( V_195 ) ) ;
}
static void F_91 ( struct V_145 * V_195 )
{
if ( F_89 ( V_195 ) )
F_86 ( F_44 ( V_195 ) ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
unsigned long V_185 ;
F_93 ( & V_2 -> V_123 ) ;
F_93 ( & V_2 -> V_121 ) ;
F_93 ( & V_2 -> V_95 ) ;
F_90 ( & V_2 -> V_119 . V_108 . V_109 ) ;
F_90 ( & V_2 -> V_114 . V_108 . V_109 ) ;
F_90 ( & V_2 -> V_94 . V_108 . V_109 ) ;
F_90 ( & V_2 -> V_111 . V_108 . V_109 ) ;
F_90 ( & V_2 -> V_107 . V_108 . V_109 ) ;
V_185 = V_186 + V_187 ;
while ( F_77 ( & V_2 -> V_121 )
|| F_77 ( & V_2 -> V_123 )
|| F_77 ( & V_2 -> V_95 )
|| F_75 ( & V_2 -> V_114 )
|| F_73 ( & V_2 -> V_119 )
|| F_38 ( & V_2 -> V_94 ) ) {
if ( F_80 ( V_186 , V_185 ) ) {
F_82 ( V_2 -> V_24 , L_43 ) ;
return 1 ;
}
F_94 ( 1 ) ;
}
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_96 ( & V_2 -> V_123 ) ;
F_96 ( & V_2 -> V_121 ) ;
F_96 ( & V_2 -> V_95 ) ;
F_91 ( & V_2 -> V_119 . V_108 . V_109 ) ;
F_91 ( & V_2 -> V_114 . V_108 . V_109 ) ;
F_91 ( & V_2 -> V_94 . V_108 . V_109 ) ;
F_91 ( & V_2 -> V_111 . V_108 . V_109 ) ;
F_91 ( & V_2 -> V_107 . V_108 . V_109 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
unsigned long V_185 = 0 ;
F_2 ( V_2 ,
F_3 ( V_2 , V_3 , V_67 )
| V_196 ,
V_3 , V_67 ) ;
while ( ! ( F_3 ( V_2 , V_3 ,
V_197 ) & 0x1 ) ) {
if ( V_185 ++ > 10000 ) {
F_98 ( V_2 -> V_24 , L_44 ) ;
return - V_190 ;
}
F_99 ( 1 ) ;
}
V_2 -> V_189 = false ;
V_2 -> V_175 = 0 ;
return 0 ;
}
static void
F_100 ( struct V_1 * V_2 , struct V_198 * V_199 )
{
struct V_198 * V_200 = V_199 ;
for (; V_200 -> V_201 != V_202 ; V_200 ++ )
V_200 -> V_203 = F_3 ( V_2 , V_200 -> V_204 , V_200 -> V_201 ) ;
}
static void
F_101 ( struct V_1 * V_2 , struct V_198 * V_199 )
{
struct V_198 * V_200 = V_199 ;
for (; V_200 -> V_201 != V_202 ; V_200 ++ )
F_2 ( V_2 , V_200 -> V_203 , V_200 -> V_204 , V_200 -> V_201 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_100 ( V_2 , V_205 ) ;
F_103 ( V_2 -> V_24 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
F_101 ( V_2 , V_205 ) ;
F_105 ( V_2 -> V_24 ) ;
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
}
void F_108 ( struct V_1 * V_2 , enum V_206 V_207 )
{
T_1 V_208 = 0 ;
V_2 -> V_209 |= V_207 ;
if ( V_2 -> V_209 & V_210 )
V_208 |= V_211 ;
if ( V_2 -> V_209 & V_212 )
V_208 |= V_213 ;
if ( V_2 -> V_209 & V_214 )
V_208 |= V_215 ;
if ( V_2 -> V_209 & V_216 )
V_208 |= V_217 ;
if ( V_2 -> V_209 & V_218 )
V_208 |= V_219 ;
if ( V_2 -> V_209 & V_220 )
V_208 |= V_221 ;
F_109 ( V_2 , V_3 , V_71 , V_208 ) ;
}
void F_110 ( struct V_1 * V_2 , enum V_206 V_207 )
{
T_1 V_208 = 0 ;
V_2 -> V_209 &= ~ V_207 ;
if ( ! ( V_2 -> V_209 & V_210 ) )
V_208 |= V_211 ;
if ( ! ( V_2 -> V_209 & V_212 ) )
V_208 |= V_213 ;
if ( ! ( V_2 -> V_209 & V_214 ) )
V_208 |= V_215 ;
if ( ! ( V_2 -> V_209 & V_216 ) )
V_208 |= V_217 ;
if ( ! ( V_2 -> V_209 & V_218 ) )
V_208 |= V_219 ;
if ( ! ( V_2 -> V_209 & V_220 ) )
V_208 |= V_221 ;
F_111 ( V_2 , V_3 , V_71 , V_208 ) ;
}
int F_112 ( struct V_145 * V_195 , T_3 * V_222 ,
T_4 * V_223 )
{
struct V_100 * V_101 = F_44 ( V_195 ) ;
if ( V_101 -> V_192 == V_191 ||
( V_101 -> V_192 == V_194 &&
! F_113 ( V_101 ) ) )
return 0 ;
F_40 ( V_223 , 1 ) ;
F_114 () ;
if ( F_89 ( V_195 ) ) {
struct V_224 * V_181 = V_101 -> V_133 ;
unsigned long V_18 ;
F_12 ( & V_181 -> V_225 -> V_226 , V_18 ) ;
if ( V_181 -> V_227 & V_228 ) {
F_13 ( & V_181 -> V_225 -> V_226 , V_18 ) ;
F_40 ( V_223 , 0 ) ;
F_114 () ;
return 0 ;
}
F_13 ( & V_181 -> V_225 -> V_226 , V_18 ) ;
if ( ! F_115 ( * V_222 , ! F_116 ( V_223 ) ,
F_117 ( 1000 ) ) ) {
F_40 ( V_223 , 0 ) ;
F_114 () ;
return - V_190 ;
}
}
return 0 ;
}
int F_118 ( T_3 * V_222 ,
T_4 * V_223 )
{
if ( F_119 ( V_223 , 1 , 0 ) ) {
F_120 ( V_222 ) ;
return 1 ;
}
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_32 = 0 ;
if ( V_2 -> V_229 &
( V_230 | V_231 ) )
V_32 |= V_232 ;
if ( V_2 -> V_229 & V_233 )
V_32 |= V_234 ;
if ( V_2 -> V_229 & V_235 )
V_32 |= V_236 ;
if ( V_2 -> V_229 & V_237 )
V_32 |= V_238 | V_239 ;
if ( V_2 -> V_229 & V_240 )
V_32 |= V_241 | V_242 ;
F_5 ( V_2 , V_3 , V_71 ,
V_243 , V_32 ) ;
}
void F_122 ( struct V_1 * V_2 ,
enum V_244 V_207 )
{
V_2 -> V_229 |= V_207 ;
F_121 ( V_2 ) ;
}
void F_123 ( struct V_1 * V_2 ,
enum V_244 V_207 )
{
V_2 -> V_229 &= ~ V_207 ;
F_121 ( V_2 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
int V_245 ;
unsigned long V_22 ;
V_245 = F_125 ( V_2 -> clock [ V_246 ] ) ;
if ( V_245 ) {
F_126 ( V_2 -> V_24 , L_45 ) ;
goto V_247;
}
V_245 = F_127 ( V_2 -> clock [ V_248 ] , V_249 ) ;
if ( V_245 ) {
F_126 ( V_2 -> V_24 , L_46 ) ;
goto V_250;
}
V_245 = F_125 ( V_2 -> clock [ V_248 ] ) ;
if ( V_245 ) {
F_126 ( V_2 -> V_24 , L_47 ) ;
goto V_250;
}
V_22 = F_128 ( V_2 -> clock [ V_248 ] ) ;
if ( V_22 != V_249 )
F_129 ( V_2 -> V_24 , L_48
L_49
L_50 , V_249 , V_22 ) ;
V_245 = F_125 ( V_2 -> clock [ V_251 ] ) ;
if ( V_245 ) {
F_126 ( V_2 -> V_24 , L_51 ) ;
goto V_252;
}
return 0 ;
V_252:
F_130 ( V_2 -> clock [ V_248 ] ) ;
V_250:
F_130 ( V_2 -> clock [ V_246 ] ) ;
V_247:
return V_245 ;
}
static void F_131 ( struct V_1 * V_2 )
{
F_130 ( V_2 -> clock [ V_246 ] ) ;
F_130 ( V_2 -> clock [ V_248 ] ) ;
F_130 ( V_2 -> clock [ V_251 ] ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_32 * V_32 ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_22 ( V_253 ) ; ++ V_30 ) {
V_32 = F_133 ( V_2 -> V_24 , V_253 [ V_30 ] ) ;
if ( F_26 ( V_32 ) ) {
F_126 ( V_2 -> V_24 , L_52 , V_253 [ V_30 ] ) ;
return F_27 ( V_32 ) ;
}
V_2 -> clock [ V_30 ] = V_32 ;
}
return 0 ;
}
static struct V_1 * F_134 ( struct V_1 * V_2 , bool V_45 )
{
struct V_1 * V_254 = V_2 ;
if ( V_2 == NULL )
return NULL ;
F_67 ( & V_2 -> V_255 ) ;
if ( V_2 -> V_256 > 0 )
goto V_257;
if ( F_124 ( V_2 ) < 0 ) {
V_254 = NULL ;
goto V_257;
}
if ( V_2 -> V_258 )
F_104 ( V_2 ) ;
if ( V_45 )
F_33 ( V_2 ) ;
V_257:
if ( V_254 != NULL )
V_2 -> V_256 ++ ;
F_68 ( & V_2 -> V_255 ) ;
return V_254 ;
}
struct V_1 * F_8 ( struct V_1 * V_2 )
{
return F_134 ( V_2 , true ) ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_67 ( & V_2 -> V_255 ) ;
F_135 ( V_2 -> V_256 == 0 ) ;
if ( -- V_2 -> V_256 == 0 ) {
F_34 ( V_2 ) ;
if ( V_2 -> V_259 ) {
F_102 ( V_2 ) ;
V_2 -> V_258 = 1 ;
}
if ( V_2 -> V_175 || V_2 -> V_189 )
F_97 ( V_2 ) ;
F_131 ( V_2 ) ;
}
F_68 ( & V_2 -> V_255 ) ;
}
void F_136 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_24 , L_53 ) ;
F_137 ( V_2 , V_260 ) ;
F_137 ( V_2 , V_261 ) ;
F_137 ( V_2 , V_262 ) ;
F_137 ( V_2 , V_263 ) ;
F_137 ( V_2 , V_264 ) ;
F_137 ( V_2 , V_265 ) ;
F_137 ( V_2 , V_266 ) ;
F_137 ( V_2 , V_267 ) ;
F_137 ( V_2 , V_268 ) ;
F_137 ( V_2 , V_269 ) ;
F_137 ( V_2 , V_270 ) ;
F_137 ( V_2 , V_271 ) ;
F_137 ( V_2 , V_272 ) ;
F_137 ( V_2 , V_273 ) ;
F_137 ( V_2 , V_274 ) ;
F_138 ( V_2 , V_275 ) ;
F_138 ( V_2 , V_276 ) ;
F_20 ( V_2 -> V_24 , L_54 ) ;
}
static int F_139 ( struct V_99 * V_24 )
{
struct V_1 * V_2 = F_140 ( V_24 ) ;
int V_277 ;
F_64 ( F_141 ( & V_2 -> V_255 ) ) ;
if ( V_2 -> V_256 == 0 )
return 0 ;
V_277 = F_92 ( V_2 ) ;
F_34 ( V_2 ) ;
F_102 ( V_2 ) ;
if ( V_277 )
F_97 ( V_2 ) ;
return 0 ;
}
static int F_142 ( struct V_99 * V_24 )
{
struct V_1 * V_2 = F_140 ( V_24 ) ;
F_64 ( F_141 ( & V_2 -> V_255 ) ) ;
if ( V_2 -> V_256 )
F_131 ( V_2 ) ;
return 0 ;
}
static int F_143 ( struct V_99 * V_24 )
{
struct V_1 * V_2 = F_140 ( V_24 ) ;
if ( V_2 -> V_256 == 0 )
return 0 ;
return F_124 ( V_2 ) ;
}
static void F_144 ( struct V_99 * V_24 )
{
struct V_1 * V_2 = F_140 ( V_24 ) ;
if ( V_2 -> V_256 == 0 )
return;
F_104 ( V_2 ) ;
F_33 ( V_2 ) ;
F_95 ( V_2 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
F_146 ( & V_2 -> V_111 ) ;
F_147 ( & V_2 -> V_107 ) ;
F_148 ( & V_2 -> V_94 ) ;
F_149 ( & V_2 -> V_114 ) ;
F_150 ( & V_2 -> V_119 ) ;
F_151 ( & V_2 -> V_123 ) ;
F_151 ( & V_2 -> V_121 ) ;
F_151 ( & V_2 -> V_95 ) ;
F_152 ( & V_2 -> V_278 ) ;
F_153 ( & V_2 -> V_279 ) ;
}
static struct V_152 *
F_154 ( struct V_1 * V_2 ,
struct V_280 * V_281 )
{
struct V_152 * V_282 = NULL ;
unsigned int V_158 ;
if ( V_281 -> V_281 == NULL )
return NULL ;
for ( V_158 = 1 ; V_281 -> V_281 ; ++ V_281 , V_158 = 0 ) {
struct V_152 * V_108 ;
struct V_283 * V_284 ;
V_284 = F_155 ( V_281 -> V_285 ) ;
if ( V_284 == NULL ) {
F_126 ( V_2 -> V_24 , L_55
L_56 , V_25 ,
V_281 -> V_285 ,
V_281 -> V_281 -> type ) ;
continue;
}
V_108 = F_156 ( & V_2 -> V_278 , V_284 ,
V_281 -> V_281 , NULL ) ;
if ( V_108 == NULL ) {
F_126 ( V_2 -> V_24 , L_57 ,
V_25 , V_281 -> V_281 -> type ) ;
continue;
}
if ( V_158 )
V_282 = V_108 ;
}
return V_282 ;
}
static int F_157 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = V_2 -> V_27 ;
struct V_286 * V_287 ;
int V_153 ;
V_2 -> V_279 . V_24 = V_2 -> V_24 ;
F_158 ( V_2 -> V_279 . V_288 , L_58 ,
sizeof( V_2 -> V_279 . V_288 ) ) ;
V_2 -> V_279 . V_289 = V_2 -> V_64 ;
V_2 -> V_279 . V_290 = F_69 ;
V_153 = F_159 ( & V_2 -> V_279 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_59 ,
V_25 , V_153 ) ;
return V_153 ;
}
V_2 -> V_278 . V_291 = & V_2 -> V_279 ;
V_153 = F_160 ( V_2 -> V_24 , & V_2 -> V_278 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_60 ,
V_25 , V_153 ) ;
goto V_292;
}
V_153 = F_161 ( & V_2 -> V_107 , & V_2 -> V_278 ) ;
if ( V_153 < 0 )
goto V_292;
V_153 = F_162 ( & V_2 -> V_111 , & V_2 -> V_278 ) ;
if ( V_153 < 0 )
goto V_292;
V_153 = F_163 ( & V_2 -> V_94 , & V_2 -> V_278 ) ;
if ( V_153 < 0 )
goto V_292;
V_153 = F_164 ( & V_2 -> V_114 ,
& V_2 -> V_278 ) ;
if ( V_153 < 0 )
goto V_292;
V_153 = F_165 ( & V_2 -> V_119 , & V_2 -> V_278 ) ;
if ( V_153 < 0 )
goto V_292;
V_153 = F_166 ( & V_2 -> V_123 , & V_2 -> V_278 ) ;
if ( V_153 < 0 )
goto V_292;
V_153 = F_166 ( & V_2 -> V_121 , & V_2 -> V_278 ) ;
if ( V_153 < 0 )
goto V_292;
V_153 = F_166 ( & V_2 -> V_95 , & V_2 -> V_278 ) ;
if ( V_153 < 0 )
goto V_292;
for ( V_287 = V_27 -> V_287 ; V_287 && V_287 -> V_287 ; ++ V_287 ) {
struct V_152 * V_282 ;
struct V_145 * V_73 ;
unsigned int V_18 ;
unsigned int V_173 ;
unsigned int V_30 ;
V_282 = F_154 ( V_2 , V_287 -> V_287 ) ;
if ( V_282 == NULL )
continue;
V_282 -> V_293 = V_287 ;
switch ( V_287 -> V_294 ) {
case V_295 :
V_73 = & V_2 -> V_94 . V_108 . V_109 ;
V_173 = V_296 ;
V_18 = 0 ;
break;
case V_297 :
V_73 = & V_2 -> V_111 . V_108 . V_109 ;
V_173 = V_298 ;
V_18 = V_299
| V_169 ;
break;
case V_300 :
case V_301 :
V_73 = & V_2 -> V_107 . V_108 . V_109 ;
V_173 = V_302 ;
V_18 = 0 ;
break;
case V_303 :
V_73 = & V_2 -> V_304 . V_108 . V_109 ;
V_173 = V_298 ;
V_18 = V_299
| V_169 ;
break;
default:
F_126 ( V_2 -> V_24 , L_61 ,
V_25 , V_287 -> V_294 ) ;
V_153 = - V_33 ;
goto V_292;
}
for ( V_30 = 0 ; V_30 < V_282 -> V_109 . V_305 ; V_30 ++ ) {
if ( V_282 -> V_109 . V_182 [ V_30 ] . V_18 & V_306 )
break;
}
if ( V_30 == V_282 -> V_109 . V_305 ) {
F_126 ( V_2 -> V_24 ,
L_62 ,
V_25 ) ;
V_153 = - V_33 ;
goto V_292;
}
V_153 = F_167 ( & V_282 -> V_109 , V_30 , V_73 , V_173 ,
V_18 ) ;
if ( V_153 < 0 )
goto V_292;
}
V_153 = F_168 ( & V_2 -> V_278 ) ;
V_292:
if ( V_153 < 0 )
F_145 ( V_2 ) ;
return V_153 ;
}
static void F_169 ( struct V_1 * V_2 )
{
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
F_175 ( V_2 ) ;
F_176 ( V_2 ) ;
F_177 ( V_2 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
int V_153 ;
V_153 = F_179 ( V_2 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_63 ) ;
goto V_307;
}
V_153 = F_180 ( V_2 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_64 ) ;
goto V_308;
}
V_153 = F_181 ( V_2 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_65 ) ;
goto V_309;
}
V_153 = F_182 ( V_2 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_66 ) ;
goto V_310;
}
V_153 = F_183 ( V_2 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_67 ) ;
goto V_311;
}
V_153 = F_184 ( V_2 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_68 ) ;
goto V_312;
}
V_153 = F_185 ( V_2 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_69 ) ;
goto V_313;
}
V_153 = F_186 ( V_2 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_70 ) ;
goto V_314;
}
V_153 = F_187 ( V_2 ) ;
if ( V_153 < 0 ) {
F_126 ( V_2 -> V_24 , L_71 ) ;
goto V_315;
}
V_153 = F_167 (
& V_2 -> V_111 . V_108 . V_109 , V_316 ,
& V_2 -> V_94 . V_108 . V_109 , V_296 , 0 ) ;
if ( V_153 < 0 )
goto V_317;
V_153 = F_167 (
& V_2 -> V_107 . V_108 . V_109 , V_318 ,
& V_2 -> V_94 . V_108 . V_109 , V_296 , 0 ) ;
if ( V_153 < 0 )
goto V_317;
V_153 = F_167 (
& V_2 -> V_94 . V_108 . V_109 , V_319 ,
& V_2 -> V_114 . V_108 . V_109 , V_320 , 0 ) ;
if ( V_153 < 0 )
goto V_317;
V_153 = F_167 (
& V_2 -> V_94 . V_108 . V_109 , V_321 ,
& V_2 -> V_119 . V_108 . V_109 , V_322 , 0 ) ;
if ( V_153 < 0 )
goto V_317;
V_153 = F_167 (
& V_2 -> V_114 . V_108 . V_109 , V_323 ,
& V_2 -> V_119 . V_108 . V_109 , V_322 , 0 ) ;
if ( V_153 < 0 )
goto V_317;
V_153 = F_167 (
& V_2 -> V_94 . V_108 . V_109 , V_319 ,
& V_2 -> V_123 . V_108 . V_109 , 0 ,
V_169 | V_299 ) ;
if ( V_153 < 0 )
goto V_317;
V_153 = F_167 (
& V_2 -> V_94 . V_108 . V_109 , V_319 ,
& V_2 -> V_121 . V_108 . V_109 , 0 ,
V_169 | V_299 ) ;
if ( V_153 < 0 )
goto V_317;
V_153 = F_167 (
& V_2 -> V_94 . V_108 . V_109 , V_319 ,
& V_2 -> V_95 . V_108 . V_109 , 0 ,
V_169 | V_299 ) ;
if ( V_153 < 0 )
goto V_317;
return 0 ;
V_317:
F_171 ( V_2 ) ;
V_315:
F_170 ( V_2 ) ;
V_314:
F_172 ( V_2 ) ;
V_313:
F_173 ( V_2 ) ;
V_312:
F_174 ( V_2 ) ;
V_311:
F_175 ( V_2 ) ;
V_310:
F_176 ( V_2 ) ;
V_309:
F_177 ( V_2 ) ;
V_308:
V_307:
return V_153 ;
}
static int F_188 ( struct V_324 * V_325 )
{
struct V_1 * V_2 = F_189 ( V_325 ) ;
F_145 ( V_2 ) ;
F_169 ( V_2 ) ;
F_30 ( V_2 ) ;
F_134 ( V_2 , false ) ;
F_190 ( V_2 -> V_259 , & V_325 -> V_24 ) ;
F_191 ( V_2 -> V_259 ) ;
V_2 -> V_259 = NULL ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_192 ( struct V_324 * V_325 ,
struct V_1 * V_2 ,
enum V_326 V_207 )
{
struct V_327 * V_328 ;
V_328 = F_193 ( V_325 , V_329 , V_207 ) ;
V_2 -> V_330 [ V_207 ] = F_194 ( V_2 -> V_24 , V_328 ) ;
if ( F_26 ( V_2 -> V_330 [ V_207 ] ) )
return F_27 ( V_2 -> V_330 [ V_207 ] ) ;
V_2 -> V_331 [ V_207 ] = V_328 -> V_332 ;
return 0 ;
}
static int F_195 ( struct V_324 * V_325 )
{
struct V_26 * V_27 = V_325 -> V_24 . V_333 ;
struct V_1 * V_2 ;
int V_153 ;
int V_30 , V_334 ;
if ( V_27 == NULL )
return - V_33 ;
V_2 = F_196 ( & V_325 -> V_24 , sizeof( * V_2 ) , V_43 ) ;
if ( ! V_2 ) {
F_126 ( & V_325 -> V_24 , L_72 ) ;
return - V_44 ;
}
V_2 -> V_68 = V_68 ;
F_197 ( & V_2 -> V_255 ) ;
F_24 ( & V_2 -> V_335 ) ;
V_2 -> V_24 = & V_325 -> V_24 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_256 = 0 ;
V_153 = F_198 ( V_2 -> V_24 , F_199 ( 32 ) ) ;
if ( V_153 )
return V_153 ;
F_200 ( V_325 , V_2 ) ;
V_2 -> V_336 . V_337 = F_201 ( & V_325 -> V_24 , L_73 ) ;
V_2 -> V_338 . V_337 = F_201 ( & V_325 -> V_24 , L_74 ) ;
V_153 = F_192 ( V_325 , V_2 , V_3 ) ;
if ( V_153 < 0 )
goto error;
V_153 = F_132 ( V_2 ) ;
if ( V_153 < 0 )
goto error;
V_153 = F_202 ( V_2 -> clock [ V_246 ] ) ;
if ( V_153 < 0 )
goto error;
V_2 -> V_64 = F_3 ( V_2 , V_3 , V_4 ) ;
F_82 ( V_2 -> V_24 , L_75 ,
( V_2 -> V_64 & 0xf0 ) >> 4 , V_2 -> V_64 & 0x0f ) ;
F_203 ( V_2 -> clock [ V_246 ] ) ;
if ( F_134 ( V_2 , false ) == NULL ) {
V_153 = - V_339 ;
goto error;
}
V_153 = F_97 ( V_2 ) ;
if ( V_153 < 0 )
goto V_340;
V_153 = F_21 ( V_2 ) ;
if ( V_153 < 0 )
goto V_340;
for ( V_334 = 0 ; V_334 < F_22 ( V_341 ) ; V_334 ++ )
if ( V_2 -> V_64 == V_341 [ V_334 ] . V_342 )
break;
if ( V_334 == F_22 ( V_341 ) ) {
F_126 ( V_2 -> V_24 , L_76 ,
( V_2 -> V_64 & 0xf0 ) >> 4 , V_2 -> V_64 & 0xf ) ;
V_153 = - V_339 ;
goto V_340;
}
for ( V_30 = 1 ; V_30 < V_343 ; V_30 ++ ) {
if ( V_341 [ V_334 ] . V_344 & 1 << V_30 ) {
V_153 = F_192 ( V_325 , V_2 , V_30 ) ;
if ( V_153 )
goto V_340;
}
}
V_2 -> V_259 = F_204 ( V_325 -> V_24 . V_345 ) ;
if ( ! V_2 -> V_259 ) {
F_126 ( V_2 -> V_24 , L_77 ) ;
V_153 = - V_44 ;
goto V_340;
}
V_153 = F_205 ( V_2 -> V_259 , & V_325 -> V_24 ) ;
if ( V_153 ) {
F_126 ( & V_325 -> V_24 , L_78 , V_153 ) ;
V_153 = - V_346 ;
goto V_347;
}
V_2 -> V_348 = F_206 ( V_325 , 0 ) ;
if ( V_2 -> V_348 <= 0 ) {
F_126 ( V_2 -> V_24 , L_79 ) ;
V_153 = - V_339 ;
goto V_349;
}
if ( F_207 ( V_2 -> V_24 , V_2 -> V_348 , F_46 , V_350 ,
L_80 , V_2 ) ) {
F_126 ( V_2 -> V_24 , L_81 ) ;
V_153 = - V_33 ;
goto V_349;
}
V_153 = F_178 ( V_2 ) ;
if ( V_153 < 0 )
goto V_349;
V_153 = F_157 ( V_2 ) ;
if ( V_153 < 0 )
goto V_351;
F_35 ( V_2 , 1 ) ;
F_10 ( V_2 ) ;
return 0 ;
V_351:
F_169 ( V_2 ) ;
V_349:
F_190 ( V_2 -> V_259 , & V_325 -> V_24 ) ;
V_347:
F_191 ( V_2 -> V_259 ) ;
V_2 -> V_259 = NULL ;
V_340:
F_30 ( V_2 ) ;
F_10 ( V_2 ) ;
error:
F_208 ( & V_2 -> V_255 ) ;
return V_153 ;
}
