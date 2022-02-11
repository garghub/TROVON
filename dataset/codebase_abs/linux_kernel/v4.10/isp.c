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
if ( * V_22 == 0 )
* V_22 = 1 ;
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
static struct V_26 * F_21 ( struct V_27 * V_28 , void * V_29 )
{
unsigned int V_30 = V_28 -> args [ 0 ] ;
struct V_1 * V_2 = V_29 ;
if ( V_30 >= F_22 ( V_2 -> V_31 ) )
return F_23 ( - V_32 ) ;
return V_2 -> V_31 [ V_30 ] . V_26 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_24 -> V_35 ;
struct V_36 V_37 ;
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < F_22 ( V_2 -> V_31 ) ; ++ V_38 )
V_2 -> V_31 [ V_38 ] . V_26 = F_23 ( - V_39 ) ;
for ( V_38 = 0 ; V_38 < F_22 ( V_2 -> V_31 ) ; ++ V_38 ) {
struct V_5 * V_6 = & V_2 -> V_31 [ V_38 ] ;
V_6 -> V_2 = V_2 ;
V_6 -> V_8 = V_38 == 0 ? V_9 : V_13 ;
V_6 -> V_7 = 1 ;
F_25 ( & V_6 -> V_19 ) ;
V_37 . V_40 = V_38 == 0 ? L_2 : L_3 ;
V_37 . V_41 = & V_42 ;
V_37 . V_43 = & V_44 ;
V_37 . V_45 = 1 ;
V_6 -> V_17 . V_37 = & V_37 ;
V_6 -> V_26 = F_26 ( NULL , & V_6 -> V_17 ) ;
if ( F_27 ( V_6 -> V_26 ) )
return F_28 ( V_6 -> V_26 ) ;
}
if ( V_34 )
F_29 ( V_34 , F_21 , V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_24 -> V_35 ;
unsigned int V_38 ;
if ( V_34 )
F_31 ( V_34 ) ;
for ( V_38 = 0 ; V_38 < F_22 ( V_2 -> V_31 ) ; ++ V_38 ) {
struct V_5 * V_6 = & V_2 -> V_31 [ V_38 ] ;
if ( ! F_27 ( V_6 -> V_26 ) )
F_32 ( V_6 -> V_26 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
static const T_1 V_46 = V_47
| V_48
| V_49
| V_50
| V_51
| V_52
| V_53
| V_54
| V_55
| V_56
| V_57
| V_58 ;
F_2 ( V_2 , V_46 , V_3 , V_59 ) ;
F_2 ( V_2 , V_46 , V_3 , V_60 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , V_60 ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_61 )
{
F_2 ( V_2 ,
( ( V_61 ? V_62 :
V_63 ) <<
V_64 ) |
( ( V_2 -> V_65 == V_66 ) ?
V_67 : 0 ) ,
V_3 , V_68 ) ;
F_2 ( V_2 ,
( V_2 -> V_69 ? V_70 : 0 ) |
V_71 ,
V_3 , V_72 ) ;
}
void F_36 ( struct V_1 * V_2 ,
enum V_73 V_74 ,
const struct V_75 * V_76 ,
unsigned int V_77 , unsigned int V_78 )
{
T_1 V_79 ;
V_79 = F_3 ( V_2 , V_3 , V_72 ) ;
V_79 &= ~ V_80 ;
V_79 &= ~ V_81 ;
V_79 &= ~ V_82 ;
V_79 &= ~ V_83 ;
V_79 |= V_78 ;
switch ( V_74 ) {
case V_84 :
V_79 |= V_85 ;
V_79 |= V_76 -> V_86 << V_87 ;
V_77 += V_76 -> V_88 ;
break;
case V_89 :
V_79 |= V_90 ;
break;
case V_91 :
V_79 |= V_92 ;
break;
case V_93 :
V_79 |= V_94 ;
break;
default:
return;
}
V_79 |= ( ( V_77 / 2 ) << V_95 ) & V_80 ;
F_2 ( V_2 , V_79 , V_3 , V_72 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( F_38 ( & V_2 -> V_96 ) ||
F_39 ( & V_2 -> V_97 ) ) {
F_40 ( & V_2 -> V_97 . V_98 , 1 ) ;
F_20 ( V_2 -> V_24 ,
L_4 ) ;
}
}
static inline void F_41 ( struct V_1 * V_2 , T_1 V_99 )
{
static const char * V_40 [] = {
L_5 ,
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
} ;
int V_38 ;
F_20 ( V_2 -> V_24 , L_37 ) ;
for ( V_38 = 0 ; V_38 < F_22 ( V_40 ) ; V_38 ++ ) {
if ( ( 1 << V_38 ) & V_99 )
F_42 ( V_100 L_38 , V_40 [ V_38 ] ) ;
}
F_42 ( V_100 L_39 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_101 * V_24 = V_2 -> V_24 ;
struct V_102 * V_103 ;
T_1 V_104 ;
V_104 = F_3 ( V_2 , V_105 , V_106 ) ;
F_2 ( V_2 , V_104 , V_105 , V_106 ) ;
V_104 &= ~ V_107 ;
if ( V_104 )
F_20 ( V_24 , L_40 , V_104 ) ;
if ( V_104 & V_108 ) {
V_103 = F_44 ( & V_2 -> V_109 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & V_112 ) {
V_103 = F_44 ( & V_2 -> V_113 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & V_114 ) {
V_103 = F_44 ( & V_2 -> V_96 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & V_115 ) {
V_103 = F_44 ( & V_2 -> V_116 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & ( V_117
| V_118
| V_119
| V_120 ) ) {
V_103 = F_44 ( & V_2 -> V_121 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & V_122 )
F_45 ( & V_2 -> V_123 ) ;
if ( V_104 & V_124 )
F_45 ( & V_2 -> V_125 ) ;
}
static T_2 F_46 ( int V_46 , void * V_126 )
{
static const T_1 V_127 = V_128 |
V_129 |
V_130 |
V_131 |
V_132 ;
struct V_1 * V_2 = V_126 ;
T_1 V_99 ;
V_99 = F_3 ( V_2 , V_3 , V_59 ) ;
F_2 ( V_2 , V_99 , V_3 , V_59 ) ;
F_43 ( V_2 ) ;
if ( V_99 & V_133 )
F_47 ( & V_2 -> V_113 ) ;
if ( V_99 & V_134 )
F_48 ( & V_2 -> V_109 ) ;
if ( V_99 & V_130 ) {
if ( V_2 -> V_96 . V_135 & V_136 )
F_49 ( & V_2 -> V_116 ) ;
if ( V_2 -> V_96 . V_135 & V_137 )
F_50 ( & V_2 -> V_121 ) ;
F_51 ( & V_2 -> V_125 ) ;
F_51 ( & V_2 -> V_123 ) ;
F_51 ( & V_2 -> V_97 ) ;
}
if ( V_99 & V_127 )
F_52 ( & V_2 -> V_96 , V_99 & V_127 ) ;
if ( V_99 & V_138 ) {
if ( V_2 -> V_116 . V_135 & V_139 )
F_50 ( & V_2 -> V_121 ) ;
F_53 ( & V_2 -> V_116 ) ;
}
if ( V_99 & V_140 )
F_54 ( & V_2 -> V_121 ) ;
if ( V_99 & V_141 )
F_55 ( & V_2 -> V_125 ) ;
if ( V_99 & V_142 )
F_55 ( & V_2 -> V_123 ) ;
if ( V_99 & V_143 )
F_55 ( & V_2 -> V_97 ) ;
F_1 ( V_2 ) ;
#if F_56 ( V_144 ) && F_56 ( V_145 )
F_41 ( V_2 , V_99 ) ;
#endif
return V_146 ;
}
static int F_57 ( struct V_102 * V_103 ,
enum V_147 V_148 )
{
struct V_1 * V_2 = V_103 -> V_135 -> V_2 ;
struct V_149 * V_111 ;
struct V_150 * V_151 ;
struct V_152 * V_110 ;
unsigned long V_18 ;
int V_153 ;
if ( F_58 ( & V_103 -> V_154 , & V_2 -> V_155 ) )
return - V_156 ;
F_12 ( & V_103 -> V_19 , V_18 ) ;
V_103 -> V_157 &= ~ ( V_158 | V_159 ) ;
F_13 ( & V_103 -> V_19 , V_18 ) ;
V_103 -> V_160 = false ;
V_111 = & V_103 -> V_135 -> V_161 . V_111 ;
while ( 1 ) {
V_151 = & V_111 -> V_162 [ 0 ] ;
if ( ! ( V_151 -> V_18 & V_163 ) )
break;
V_151 = F_59 ( V_151 ) ;
if ( ! V_151 || ! F_60 ( V_151 -> V_111 ) )
break;
V_111 = V_151 -> V_111 ;
V_110 = F_61 ( V_111 ) ;
V_153 = F_62 ( V_110 , V_161 , V_164 , V_148 ) ;
if ( V_153 < 0 && V_153 != - V_165 )
return V_153 ;
if ( V_110 == & V_2 -> V_96 . V_110 ) {
F_62 ( & V_2 -> V_125 . V_110 , V_161 ,
V_164 , V_148 ) ;
F_62 ( & V_2 -> V_123 . V_110 , V_161 ,
V_164 , V_148 ) ;
F_62 ( & V_2 -> V_97 . V_110 , V_161 ,
V_164 , V_148 ) ;
V_103 -> V_160 = true ;
}
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
return F_64 ( & V_2 -> V_121 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
return F_66 ( & V_2 -> V_116 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
return F_68 ( & V_2 -> V_123 )
|| F_68 ( & V_2 -> V_125 )
|| F_68 ( & V_2 -> V_97 )
|| F_38 ( & V_2 -> V_96 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
int (* F_70)( struct V_1 * V_2 ) )
{
unsigned long V_166 = V_167 + V_168 ;
while ( ! F_71 ( V_167 , V_166 ) ) {
if ( ! F_70 ( V_2 ) )
return 0 ;
}
return 1 ;
}
static int F_72 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = V_103 -> V_135 -> V_2 ;
struct V_149 * V_111 ;
struct V_150 * V_151 ;
struct V_152 * V_110 ;
int V_169 = 0 ;
int V_153 ;
V_111 = & V_103 -> V_135 -> V_161 . V_111 ;
while ( 1 ) {
V_151 = & V_111 -> V_162 [ 0 ] ;
if ( ! ( V_151 -> V_18 & V_163 ) )
break;
V_151 = F_59 ( V_151 ) ;
if ( ! V_151 || ! F_60 ( V_151 -> V_111 ) )
break;
V_111 = V_151 -> V_111 ;
V_110 = F_61 ( V_111 ) ;
if ( V_110 == & V_2 -> V_96 . V_110 ) {
F_62 ( & V_2 -> V_125 . V_110 ,
V_161 , V_164 , 0 ) ;
F_62 ( & V_2 -> V_123 . V_110 ,
V_161 , V_164 , 0 ) ;
F_62 ( & V_2 -> V_97 . V_110 ,
V_161 , V_164 , 0 ) ;
}
V_153 = F_62 ( V_110 , V_161 , V_164 , 0 ) ;
if ( V_110 == & V_2 -> V_121 . V_110 )
V_153 |= F_69 ( V_2 , F_63 ) ;
else if ( V_110 == & V_2 -> V_116 . V_110 )
V_153 |= F_69 ( V_2 , F_65 ) ;
else if ( V_110 == & V_2 -> V_96 . V_110 )
V_153 |= F_69 ( V_2 , F_67 ) ;
if ( V_153 ) {
F_73 ( V_2 -> V_24 , L_41 , V_110 -> V_40 ) ;
V_2 -> V_170 = true ;
if ( V_110 == & V_2 -> V_116 . V_110 )
F_74 ( & V_2 -> V_155 ,
& V_110 -> V_111 ) ;
V_169 = - V_171 ;
}
}
return V_169 ;
}
int F_75 ( struct V_102 * V_103 ,
enum V_147 V_157 )
{
int V_153 ;
if ( V_157 == V_172 )
V_153 = F_72 ( V_103 ) ;
else
V_153 = F_57 ( V_103 , V_157 ) ;
if ( V_153 == 0 || V_157 == V_172 )
V_103 -> V_173 = V_157 ;
return V_153 ;
}
void F_76 ( struct V_102 * V_103 )
{
if ( V_103 -> V_74 )
F_77 ( V_103 -> V_74 ) ;
if ( V_103 -> V_135 )
F_77 ( V_103 -> V_135 ) ;
}
static void F_78 ( struct V_102 * V_103 )
{
int V_174 = V_103 -> V_173 == V_175 ;
F_79 ( V_103 -> V_135 , ! V_174 ) ;
if ( V_174 )
F_79 ( V_103 -> V_74 , 0 ) ;
F_57 ( V_103 , V_103 -> V_173 ) ;
}
static void F_80 ( struct V_102 * V_103 )
{
F_72 ( V_103 ) ;
}
static int F_81 ( struct V_149 * V_176 )
{
struct V_102 * V_103 ;
struct V_150 * V_151 ;
if ( ! V_176 -> V_103 )
return 0 ;
V_103 = F_44 ( V_176 ) ;
if ( V_103 -> V_173 == V_172 )
return 0 ;
V_151 = F_59 ( & V_103 -> V_135 -> V_151 ) ;
return V_151 -> V_111 == V_176 ;
}
static void F_82 ( struct V_149 * V_176 )
{
if ( F_81 ( V_176 ) )
F_80 ( F_44 ( V_176 ) ) ;
}
static void F_83 ( struct V_149 * V_176 )
{
if ( F_81 ( V_176 ) )
F_78 ( F_44 ( V_176 ) ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
unsigned long V_166 ;
F_85 ( & V_2 -> V_125 ) ;
F_85 ( & V_2 -> V_123 ) ;
F_85 ( & V_2 -> V_97 ) ;
F_82 ( & V_2 -> V_121 . V_110 . V_111 ) ;
F_82 ( & V_2 -> V_116 . V_110 . V_111 ) ;
F_82 ( & V_2 -> V_96 . V_110 . V_111 ) ;
F_82 ( & V_2 -> V_113 . V_110 . V_111 ) ;
F_82 ( & V_2 -> V_109 . V_110 . V_111 ) ;
V_166 = V_167 + V_168 ;
while ( F_68 ( & V_2 -> V_123 )
|| F_68 ( & V_2 -> V_125 )
|| F_68 ( & V_2 -> V_97 )
|| F_66 ( & V_2 -> V_116 )
|| F_64 ( & V_2 -> V_121 )
|| F_38 ( & V_2 -> V_96 ) ) {
if ( F_71 ( V_167 , V_166 ) ) {
F_73 ( V_2 -> V_24 , L_42 ) ;
return 1 ;
}
F_86 ( 1 ) ;
}
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
F_88 ( & V_2 -> V_125 ) ;
F_88 ( & V_2 -> V_123 ) ;
F_88 ( & V_2 -> V_97 ) ;
F_83 ( & V_2 -> V_121 . V_110 . V_111 ) ;
F_83 ( & V_2 -> V_116 . V_110 . V_111 ) ;
F_83 ( & V_2 -> V_96 . V_110 . V_111 ) ;
F_83 ( & V_2 -> V_113 . V_110 . V_111 ) ;
F_83 ( & V_2 -> V_109 . V_110 . V_111 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
unsigned long V_166 = 0 ;
F_2 ( V_2 ,
F_3 ( V_2 , V_3 , V_68 )
| V_177 ,
V_3 , V_68 ) ;
while ( ! ( F_3 ( V_2 , V_3 ,
V_178 ) & 0x1 ) ) {
if ( V_166 ++ > 10000 ) {
F_90 ( V_2 -> V_24 , L_43 ) ;
return - V_171 ;
}
F_91 ( 1 ) ;
}
V_2 -> V_170 = false ;
F_92 ( & V_2 -> V_155 ) ;
return 0 ;
}
static void
F_93 ( struct V_1 * V_2 , struct V_179 * V_180 )
{
struct V_179 * V_181 = V_180 ;
for (; V_181 -> V_182 != V_183 ; V_181 ++ )
V_181 -> V_184 = F_3 ( V_2 , V_181 -> V_185 , V_181 -> V_182 ) ;
}
static void
F_94 ( struct V_1 * V_2 , struct V_179 * V_180 )
{
struct V_179 * V_181 = V_180 ;
for (; V_181 -> V_182 != V_183 ; V_181 ++ )
F_2 ( V_2 , V_181 -> V_184 , V_181 -> V_185 , V_181 -> V_182 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_93 ( V_2 , V_186 ) ;
F_96 ( V_2 -> V_24 ) ;
}
static void F_97 ( struct V_1 * V_2 )
{
F_94 ( V_2 , V_186 ) ;
F_98 ( V_2 -> V_24 ) ;
F_99 ( V_2 ) ;
F_100 ( V_2 ) ;
}
void F_101 ( struct V_1 * V_2 , enum V_187 V_188 )
{
T_1 V_189 = 0 ;
V_2 -> V_190 |= V_188 ;
if ( V_2 -> V_190 & V_191 )
V_189 |= V_192 ;
if ( V_2 -> V_190 & V_193 )
V_189 |= V_194 ;
if ( V_2 -> V_190 & V_195 )
V_189 |= V_196 ;
if ( V_2 -> V_190 & V_197 )
V_189 |= V_198 ;
if ( V_2 -> V_190 & V_199 )
V_189 |= V_200 ;
if ( V_2 -> V_190 & V_201 )
V_189 |= V_202 ;
F_102 ( V_2 , V_3 , V_72 , V_189 ) ;
}
void F_103 ( struct V_1 * V_2 , enum V_187 V_188 )
{
T_1 V_189 = 0 ;
V_2 -> V_190 &= ~ V_188 ;
if ( ! ( V_2 -> V_190 & V_191 ) )
V_189 |= V_192 ;
if ( ! ( V_2 -> V_190 & V_193 ) )
V_189 |= V_194 ;
if ( ! ( V_2 -> V_190 & V_195 ) )
V_189 |= V_196 ;
if ( ! ( V_2 -> V_190 & V_197 ) )
V_189 |= V_198 ;
if ( ! ( V_2 -> V_190 & V_199 ) )
V_189 |= V_200 ;
if ( ! ( V_2 -> V_190 & V_201 ) )
V_189 |= V_202 ;
F_104 ( V_2 , V_3 , V_72 , V_189 ) ;
}
int F_105 ( struct V_149 * V_176 , T_3 * V_203 ,
T_4 * V_204 )
{
struct V_102 * V_103 = F_44 ( V_176 ) ;
if ( V_103 -> V_173 == V_172 ||
( V_103 -> V_173 == V_175 &&
! F_106 ( V_103 ) ) )
return 0 ;
F_40 ( V_204 , 1 ) ;
F_107 () ;
if ( F_81 ( V_176 ) ) {
struct V_205 * V_161 = V_103 -> V_135 ;
unsigned long V_18 ;
F_12 ( & V_161 -> V_206 , V_18 ) ;
if ( V_161 -> V_207 & V_208 ) {
F_13 ( & V_161 -> V_206 , V_18 ) ;
F_40 ( V_204 , 0 ) ;
F_107 () ;
return 0 ;
}
F_13 ( & V_161 -> V_206 , V_18 ) ;
if ( ! F_108 ( * V_203 , ! F_109 ( V_204 ) ,
F_110 ( 1000 ) ) ) {
F_40 ( V_204 , 0 ) ;
F_107 () ;
return - V_171 ;
}
}
return 0 ;
}
int F_111 ( T_3 * V_203 ,
T_4 * V_204 )
{
if ( F_112 ( V_204 , 1 , 0 ) ) {
F_113 ( V_203 ) ;
return 1 ;
}
return 0 ;
}
static void F_114 ( struct V_1 * V_2 )
{
T_1 V_26 = 0 ;
if ( V_2 -> V_209 &
( V_210 | V_211 ) )
V_26 |= V_212 ;
if ( V_2 -> V_209 & V_213 )
V_26 |= V_214 ;
if ( V_2 -> V_209 & V_215 )
V_26 |= V_216 ;
if ( V_2 -> V_209 & V_217 )
V_26 |= V_218 | V_219 ;
if ( V_2 -> V_209 & V_220 )
V_26 |= V_221 | V_222 ;
F_5 ( V_2 , V_3 , V_72 ,
V_223 , V_26 ) ;
}
void F_115 ( struct V_1 * V_2 ,
enum V_224 V_188 )
{
V_2 -> V_209 |= V_188 ;
F_114 ( V_2 ) ;
}
void F_116 ( struct V_1 * V_2 ,
enum V_224 V_188 )
{
V_2 -> V_209 &= ~ V_188 ;
F_114 ( V_2 ) ;
}
static int F_117 ( struct V_1 * V_2 )
{
int V_225 ;
unsigned long V_22 ;
V_225 = F_118 ( V_2 -> clock [ V_226 ] ) ;
if ( V_225 ) {
F_119 ( V_2 -> V_24 , L_44 ) ;
goto V_227;
}
V_225 = F_120 ( V_2 -> clock [ V_228 ] , V_229 ) ;
if ( V_225 ) {
F_119 ( V_2 -> V_24 , L_45 ) ;
goto V_230;
}
V_225 = F_118 ( V_2 -> clock [ V_228 ] ) ;
if ( V_225 ) {
F_119 ( V_2 -> V_24 , L_46 ) ;
goto V_230;
}
V_22 = F_121 ( V_2 -> clock [ V_228 ] ) ;
if ( V_22 != V_229 )
F_122 ( V_2 -> V_24 , L_47
L_48
L_49 , V_229 , V_22 ) ;
V_225 = F_118 ( V_2 -> clock [ V_231 ] ) ;
if ( V_225 ) {
F_119 ( V_2 -> V_24 , L_50 ) ;
goto V_232;
}
return 0 ;
V_232:
F_123 ( V_2 -> clock [ V_228 ] ) ;
V_230:
F_123 ( V_2 -> clock [ V_226 ] ) ;
V_227:
return V_225 ;
}
static void F_124 ( struct V_1 * V_2 )
{
F_123 ( V_2 -> clock [ V_226 ] ) ;
F_123 ( V_2 -> clock [ V_228 ] ) ;
F_123 ( V_2 -> clock [ V_231 ] ) ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_26 * V_26 ;
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < F_22 ( V_233 ) ; ++ V_38 ) {
V_26 = F_126 ( V_2 -> V_24 , V_233 [ V_38 ] ) ;
if ( F_27 ( V_26 ) ) {
F_119 ( V_2 -> V_24 , L_51 , V_233 [ V_38 ] ) ;
return F_28 ( V_26 ) ;
}
V_2 -> clock [ V_38 ] = V_26 ;
}
return 0 ;
}
static struct V_1 * F_127 ( struct V_1 * V_2 , bool V_46 )
{
struct V_1 * V_234 = V_2 ;
if ( V_2 == NULL )
return NULL ;
F_128 ( & V_2 -> V_235 ) ;
if ( V_2 -> V_236 > 0 )
goto V_237;
if ( F_117 ( V_2 ) < 0 ) {
V_234 = NULL ;
goto V_237;
}
if ( V_2 -> V_238 )
F_97 ( V_2 ) ;
if ( V_46 )
F_33 ( V_2 ) ;
V_237:
if ( V_234 != NULL )
V_2 -> V_236 ++ ;
F_129 ( & V_2 -> V_235 ) ;
return V_234 ;
}
struct V_1 * F_8 ( struct V_1 * V_2 )
{
return F_127 ( V_2 , true ) ;
}
static void F_130 ( struct V_1 * V_2 , bool V_239 )
{
if ( V_2 == NULL )
return;
F_128 ( & V_2 -> V_235 ) ;
F_131 ( V_2 -> V_236 == 0 ) ;
if ( -- V_2 -> V_236 == 0 ) {
F_34 ( V_2 ) ;
if ( V_239 ) {
F_95 ( V_2 ) ;
V_2 -> V_238 = 1 ;
}
if ( ! F_132 ( & V_2 -> V_155 ) ||
V_2 -> V_170 )
F_89 ( V_2 ) ;
F_124 ( V_2 ) ;
}
F_129 ( & V_2 -> V_235 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_130 ( V_2 , true ) ;
}
void F_133 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_24 , L_52 ) ;
F_134 ( V_2 , V_240 ) ;
F_134 ( V_2 , V_241 ) ;
F_134 ( V_2 , V_242 ) ;
F_134 ( V_2 , V_243 ) ;
F_134 ( V_2 , V_244 ) ;
F_134 ( V_2 , V_245 ) ;
F_134 ( V_2 , V_246 ) ;
F_134 ( V_2 , V_247 ) ;
F_134 ( V_2 , V_248 ) ;
F_134 ( V_2 , V_249 ) ;
F_134 ( V_2 , V_250 ) ;
F_134 ( V_2 , V_251 ) ;
F_134 ( V_2 , V_252 ) ;
F_134 ( V_2 , V_253 ) ;
F_134 ( V_2 , V_254 ) ;
F_135 ( V_2 , V_255 ) ;
F_135 ( V_2 , V_256 ) ;
F_20 ( V_2 -> V_24 , L_53 ) ;
}
static int F_136 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_137 ( V_24 ) ;
int V_257 ;
F_138 ( F_139 ( & V_2 -> V_235 ) ) ;
if ( V_2 -> V_236 == 0 )
return 0 ;
V_257 = F_84 ( V_2 ) ;
F_34 ( V_2 ) ;
F_95 ( V_2 ) ;
if ( V_257 )
F_89 ( V_2 ) ;
return 0 ;
}
static int F_140 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_137 ( V_24 ) ;
F_138 ( F_139 ( & V_2 -> V_235 ) ) ;
if ( V_2 -> V_236 )
F_124 ( V_2 ) ;
return 0 ;
}
static int F_141 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_137 ( V_24 ) ;
if ( V_2 -> V_236 == 0 )
return 0 ;
return F_117 ( V_2 ) ;
}
static void F_142 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_137 ( V_24 ) ;
if ( V_2 -> V_236 == 0 )
return;
F_97 ( V_2 ) ;
F_33 ( V_2 ) ;
F_87 ( V_2 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
F_144 ( & V_2 -> V_113 ) ;
F_145 ( & V_2 -> V_109 ) ;
F_146 ( & V_2 -> V_96 ) ;
F_147 ( & V_2 -> V_116 ) ;
F_148 ( & V_2 -> V_121 ) ;
F_149 ( & V_2 -> V_125 ) ;
F_149 ( & V_2 -> V_123 ) ;
F_149 ( & V_2 -> V_97 ) ;
F_150 ( & V_2 -> V_258 ) ;
F_151 ( & V_2 -> V_259 ) ;
F_152 ( & V_2 -> V_259 ) ;
}
static int F_153 (
struct V_1 * V_2 , struct V_149 * V_111 ,
enum V_260 V_261 )
{
struct V_149 * V_74 ;
unsigned int V_18 ;
unsigned int V_151 ;
unsigned int V_38 ;
switch ( V_261 ) {
case V_262 :
V_74 = & V_2 -> V_96 . V_110 . V_111 ;
V_151 = V_263 ;
V_18 = 0 ;
break;
case V_264 :
V_74 = & V_2 -> V_113 . V_110 . V_111 ;
V_151 = V_265 ;
V_18 = V_266 | V_267 ;
break;
case V_268 :
case V_269 :
V_74 = & V_2 -> V_109 . V_110 . V_111 ;
V_151 = V_270 ;
V_18 = 0 ;
break;
case V_271 :
V_74 = & V_2 -> V_272 . V_110 . V_111 ;
V_151 = V_265 ;
V_18 = V_266 | V_267 ;
break;
default:
F_119 ( V_2 -> V_24 , L_54 , V_25 ,
V_261 ) ;
return - V_39 ;
}
if ( ! V_74 -> V_273 ) {
F_119 ( V_2 -> V_24 , L_55 , V_111 -> V_40 ,
V_261 ) ;
return - V_39 ;
}
for ( V_38 = 0 ; V_38 < V_111 -> V_273 ; V_38 ++ ) {
if ( V_111 -> V_162 [ V_38 ] . V_18 & V_274 )
break;
}
if ( V_38 == V_111 -> V_273 ) {
F_119 ( V_2 -> V_24 , L_56 ,
V_25 ) ;
return - V_39 ;
}
return F_154 ( V_111 , V_38 , V_74 , V_151 , V_18 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_153 ;
V_2 -> V_259 . V_24 = V_2 -> V_24 ;
F_156 ( V_2 -> V_259 . V_275 , L_57 ,
sizeof( V_2 -> V_259 . V_275 ) ) ;
V_2 -> V_259 . V_276 = V_2 -> V_65 ;
V_2 -> V_259 . V_41 = & V_277 ;
F_157 ( & V_2 -> V_259 ) ;
V_2 -> V_258 . V_278 = & V_2 -> V_259 ;
V_153 = F_158 ( V_2 -> V_24 , & V_2 -> V_258 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_58 ,
V_25 , V_153 ) ;
goto V_279;
}
V_153 = F_159 ( & V_2 -> V_109 , & V_2 -> V_258 ) ;
if ( V_153 < 0 )
goto V_279;
V_153 = F_160 ( & V_2 -> V_113 , & V_2 -> V_258 ) ;
if ( V_153 < 0 )
goto V_279;
V_153 = F_161 ( & V_2 -> V_96 , & V_2 -> V_258 ) ;
if ( V_153 < 0 )
goto V_279;
V_153 = F_162 ( & V_2 -> V_116 ,
& V_2 -> V_258 ) ;
if ( V_153 < 0 )
goto V_279;
V_153 = F_163 ( & V_2 -> V_121 , & V_2 -> V_258 ) ;
if ( V_153 < 0 )
goto V_279;
V_153 = F_164 ( & V_2 -> V_125 , & V_2 -> V_258 ) ;
if ( V_153 < 0 )
goto V_279;
V_153 = F_164 ( & V_2 -> V_123 , & V_2 -> V_258 ) ;
if ( V_153 < 0 )
goto V_279;
V_153 = F_164 ( & V_2 -> V_97 , & V_2 -> V_258 ) ;
if ( V_153 < 0 )
goto V_279;
V_279:
if ( V_153 < 0 )
F_143 ( V_2 ) ;
return V_153 ;
}
static int F_165 ( struct V_1 * V_2 )
{
int V_153 ;
V_153 = F_154 (
& V_2 -> V_113 . V_110 . V_111 , V_280 ,
& V_2 -> V_113 . V_281 . V_161 . V_111 , 0 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_109 . V_282 . V_161 . V_111 , 0 ,
& V_2 -> V_109 . V_110 . V_111 , V_270 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_96 . V_110 . V_111 , V_283 ,
& V_2 -> V_96 . V_281 . V_161 . V_111 , 0 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_116 . V_282 . V_161 . V_111 , 0 ,
& V_2 -> V_116 . V_110 . V_111 , V_284 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_116 . V_110 . V_111 , V_285 ,
& V_2 -> V_116 . V_281 . V_161 . V_111 , 0 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_121 . V_282 . V_161 . V_111 , 0 ,
& V_2 -> V_121 . V_110 . V_111 , V_286 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_121 . V_110 . V_111 , V_287 ,
& V_2 -> V_121 . V_281 . V_161 . V_111 , 0 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_113 . V_110 . V_111 , V_280 ,
& V_2 -> V_96 . V_110 . V_111 , V_263 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_109 . V_110 . V_111 , V_288 ,
& V_2 -> V_96 . V_110 . V_111 , V_263 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_96 . V_110 . V_111 , V_289 ,
& V_2 -> V_116 . V_110 . V_111 , V_284 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_96 . V_110 . V_111 , V_283 ,
& V_2 -> V_121 . V_110 . V_111 , V_286 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_116 . V_110 . V_111 , V_285 ,
& V_2 -> V_121 . V_110 . V_111 , V_286 , 0 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_96 . V_110 . V_111 , V_289 ,
& V_2 -> V_125 . V_110 . V_111 , 0 ,
V_267 | V_266 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_96 . V_110 . V_111 , V_289 ,
& V_2 -> V_123 . V_110 . V_111 , 0 ,
V_267 | V_266 ) ;
if ( V_153 < 0 )
return V_153 ;
V_153 = F_154 (
& V_2 -> V_96 . V_110 . V_111 , V_289 ,
& V_2 -> V_97 . V_110 . V_111 , 0 ,
V_267 | V_266 ) ;
if ( V_153 < 0 )
return V_153 ;
return 0 ;
}
static void F_166 ( struct V_1 * V_2 )
{
F_167 ( V_2 ) ;
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
}
static int F_175 ( struct V_1 * V_2 )
{
int V_153 ;
V_153 = F_176 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_59 ) ;
goto V_290;
}
V_153 = F_177 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_60 ) ;
goto V_291;
}
V_153 = F_178 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_61 ) ;
goto V_292;
}
V_153 = F_179 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_62 ) ;
goto V_293;
}
V_153 = F_180 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_63 ) ;
goto V_294;
}
V_153 = F_181 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_64 ) ;
goto V_295;
}
V_153 = F_182 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_65 ) ;
goto V_296;
}
V_153 = F_183 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_66 ) ;
goto V_297;
}
V_153 = F_184 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_67 ) ;
goto V_298;
}
return 0 ;
V_298:
F_167 ( V_2 ) ;
V_297:
F_169 ( V_2 ) ;
V_296:
F_170 ( V_2 ) ;
V_295:
F_171 ( V_2 ) ;
V_294:
F_172 ( V_2 ) ;
V_293:
F_173 ( V_2 ) ;
V_292:
F_174 ( V_2 ) ;
V_291:
V_290:
return V_153 ;
}
static void F_185 ( struct V_1 * V_2 )
{
F_186 ( V_2 -> V_299 ) ;
V_2 -> V_299 = NULL ;
F_187 ( V_2 -> V_24 ) ;
}
static int F_188 ( struct V_1 * V_2 )
{
struct V_300 * V_299 ;
struct V_301 * V_302 ;
int V_153 ;
V_302 = F_189 () ;
if ( F_27 ( V_302 ) ) {
F_119 ( V_2 -> V_24 , L_68 ) ;
return F_28 ( V_302 ) ;
}
V_153 = F_190 ( V_302 , V_2 -> V_24 ) ;
F_191 ( V_302 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_69 ) ;
return V_153 ;
}
V_299 = F_192 ( & V_303 , V_304 , V_305 ) ;
if ( F_27 ( V_299 ) ) {
F_119 ( V_2 -> V_24 , L_70 ) ;
V_153 = F_28 ( V_299 ) ;
goto error;
}
V_2 -> V_299 = V_299 ;
V_153 = F_193 ( V_2 -> V_24 , V_299 ) ;
if ( V_153 < 0 ) {
F_119 ( V_2 -> V_24 , L_71 ) ;
goto error;
}
return 0 ;
error:
F_185 ( V_2 ) ;
return V_153 ;
}
static int F_194 ( struct V_306 * V_307 )
{
struct V_1 * V_2 = F_195 ( V_307 ) ;
F_196 ( & V_2 -> V_308 ) ;
F_143 ( V_2 ) ;
F_166 ( V_2 ) ;
F_30 ( V_2 ) ;
F_127 ( V_2 , false ) ;
F_185 ( V_2 ) ;
F_130 ( V_2 , false ) ;
F_197 ( & V_2 -> V_155 ) ;
return 0 ;
}
static int F_198 ( struct V_101 * V_24 , struct V_33 * V_309 ,
struct V_310 * V_311 )
{
struct V_312 * V_313 = & V_311 -> V_314 ;
struct V_315 V_316 ;
unsigned int V_38 ;
int V_153 ;
V_153 = F_199 ( V_309 , & V_316 ) ;
if ( V_153 )
return V_153 ;
F_20 ( V_24 , L_72 , V_309 -> V_317 ,
V_316 . V_318 . V_319 ) ;
switch ( V_316 . V_318 . V_319 ) {
case V_320 :
V_313 -> V_261 = V_262 ;
V_313 -> V_314 . V_321 . V_88 =
V_316 . V_314 . V_321 . V_322 ;
V_313 -> V_314 . V_321 . V_86 =
! ! ( V_316 . V_314 . V_321 . V_18
& V_323 ) ;
V_313 -> V_314 . V_321 . V_324 =
! ! ( V_316 . V_314 . V_321 . V_18 & V_325 ) ;
V_313 -> V_314 . V_321 . V_326 =
! ! ( V_316 . V_314 . V_321 . V_18 & V_327 ) ;
V_313 -> V_314 . V_321 . V_328 =
! ! ( V_316 . V_314 . V_321 . V_18 & V_329 ) ;
V_313 -> V_314 . V_321 . V_330 =
! ! ( V_316 . V_314 . V_321 . V_18 & V_331 ) ;
break;
case V_332 :
case V_333 :
switch ( V_316 . V_318 . V_319 ) {
case V_332 :
V_313 -> V_261 = V_271 ;
break;
case V_333 :
V_313 -> V_261 = V_264 ;
break;
}
V_313 -> V_314 . V_334 . V_335 . V_26 . V_336 = V_316 . V_314 . V_337 . V_338 ;
V_313 -> V_314 . V_334 . V_335 . V_26 . V_339 =
V_316 . V_314 . V_337 . V_340 [ 0 ] ;
F_20 ( V_24 , L_73 ,
V_313 -> V_314 . V_334 . V_335 . V_26 . V_339 ,
V_313 -> V_314 . V_334 . V_335 . V_26 . V_336 ) ;
for ( V_38 = 0 ; V_38 < V_341 ; V_38 ++ ) {
V_313 -> V_314 . V_334 . V_335 . V_29 [ V_38 ] . V_336 =
V_316 . V_314 . V_337 . V_342 [ V_38 ] ;
V_313 -> V_314 . V_334 . V_335 . V_29 [ V_38 ] . V_339 =
V_316 . V_314 . V_337 . V_340 [ V_38 + 1 ] ;
F_20 ( V_24 , L_74 , V_38 ,
V_313 -> V_314 . V_334 . V_335 . V_29 [ V_38 ] . V_339 ,
V_313 -> V_314 . V_334 . V_335 . V_29 [ V_38 ] . V_336 ) ;
}
V_313 -> V_314 . V_334 . V_343 = 1 ;
break;
default:
F_122 ( V_24 , L_75 , V_309 -> V_317 ,
V_316 . V_318 . V_319 ) ;
break;
}
return 0 ;
}
static int F_200 ( struct V_101 * V_24 ,
struct V_344 * V_308 )
{
struct V_33 * V_309 = NULL ;
V_308 -> V_345 = F_201 (
V_24 , V_346 , sizeof( * V_308 -> V_345 ) , V_347 ) ;
if ( ! V_308 -> V_345 )
return - V_348 ;
while ( V_308 -> V_349 < V_346 &&
( V_309 = F_202 ( V_24 -> V_35 , V_309 ) ) ) {
struct V_310 * V_311 ;
V_311 = F_203 ( V_24 , sizeof( * V_311 ) , V_347 ) ;
if ( ! V_311 )
goto error;
V_308 -> V_345 [ V_308 -> V_349 ] = & V_311 -> V_350 ;
if ( F_198 ( V_24 , V_309 , V_311 ) )
goto error;
V_311 -> V_350 . V_351 . V_352 . V_309 = F_204 ( V_309 ) ;
if ( ! V_311 -> V_350 . V_351 . V_352 . V_309 ) {
F_122 ( V_24 , L_76 ) ;
goto error;
}
V_311 -> V_350 . V_353 = V_354 ;
V_308 -> V_349 ++ ;
}
return V_308 -> V_349 ;
error:
F_205 ( V_309 ) ;
return - V_39 ;
}
static int F_206 ( struct V_344 * V_355 ,
struct V_152 * V_110 ,
struct V_356 * V_350 )
{
struct V_310 * V_311 =
F_207 ( V_350 , struct V_310 , V_350 ) ;
V_311 -> V_357 = V_110 ;
V_311 -> V_357 -> V_358 = & V_311 -> V_314 ;
return 0 ;
}
static int F_208 ( struct V_344 * V_355 )
{
struct V_1 * V_2 = F_207 ( V_355 , struct V_1 ,
V_308 ) ;
struct V_359 * V_258 = & V_2 -> V_258 ;
struct V_152 * V_357 ;
struct V_312 * V_314 ;
int V_153 ;
V_153 = F_209 ( & V_2 -> V_155 , & V_2 -> V_259 ) ;
if ( V_153 )
return V_153 ;
F_210 (sd, &v4l2_dev->subdevs, list) {
if ( V_357 -> V_358 ) {
V_314 = (struct V_312 * ) V_357 -> V_358 ;
V_153 = F_153 ( V_2 , & V_357 -> V_111 , V_314 -> V_261 ) ;
if ( V_153 < 0 )
return V_153 ;
}
}
V_153 = F_211 ( & V_2 -> V_258 ) ;
if ( V_153 < 0 )
return V_153 ;
return F_212 ( & V_2 -> V_259 ) ;
}
static int F_213 ( struct V_306 * V_307 )
{
struct V_1 * V_2 ;
struct V_360 * V_361 ;
int V_153 ;
int V_38 , V_362 ;
V_2 = F_203 ( & V_307 -> V_24 , sizeof( * V_2 ) , V_347 ) ;
if ( ! V_2 ) {
F_119 ( & V_307 -> V_24 , L_77 ) ;
return - V_348 ;
}
V_153 = F_214 ( V_307 -> V_24 . V_35 , L_78 ,
& V_2 -> V_363 ) ;
if ( V_153 )
return V_153 ;
V_2 -> V_364 = F_215 ( V_307 -> V_24 . V_35 ,
L_79 ) ;
if ( F_27 ( V_2 -> V_364 ) )
return F_28 ( V_2 -> V_364 ) ;
V_153 = F_216 ( V_307 -> V_24 . V_35 , L_79 , 1 ,
& V_2 -> V_365 ) ;
if ( V_153 )
return V_153 ;
V_153 = F_200 ( & V_307 -> V_24 , & V_2 -> V_308 ) ;
if ( V_153 < 0 )
return V_153 ;
V_2 -> V_69 = V_69 ;
F_217 ( & V_2 -> V_235 ) ;
F_25 ( & V_2 -> V_366 ) ;
V_2 -> V_24 = & V_307 -> V_24 ;
V_2 -> V_236 = 0 ;
V_153 = F_218 ( V_2 -> V_24 , F_219 ( 32 ) ) ;
if ( V_153 )
goto error;
F_220 ( V_307 , V_2 ) ;
V_2 -> V_367 . V_368 = F_221 ( & V_307 -> V_24 , L_80 ) ;
V_2 -> V_369 . V_368 = F_221 ( & V_307 -> V_24 , L_81 ) ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
unsigned int V_370 = V_38 ? V_371 : 0 ;
V_361 = F_222 ( V_307 , V_372 , V_38 ) ;
V_2 -> V_373 [ V_370 ] =
F_223 ( V_2 -> V_24 , V_361 ) ;
if ( F_27 ( V_2 -> V_373 [ V_370 ] ) )
return F_28 ( V_2 -> V_373 [ V_370 ] ) ;
}
V_153 = F_125 ( V_2 ) ;
if ( V_153 < 0 )
goto error;
V_153 = F_224 ( V_2 -> clock [ V_226 ] ) ;
if ( V_153 < 0 )
goto error;
V_2 -> V_65 = F_3 ( V_2 , V_3 , V_4 ) ;
F_73 ( V_2 -> V_24 , L_82 ,
( V_2 -> V_65 & 0xf0 ) >> 4 , V_2 -> V_65 & 0x0f ) ;
F_225 ( V_2 -> clock [ V_226 ] ) ;
if ( F_127 ( V_2 , false ) == NULL ) {
V_153 = - V_374 ;
goto error;
}
V_153 = F_89 ( V_2 ) ;
if ( V_153 < 0 )
goto V_375;
V_153 = F_24 ( V_2 ) ;
if ( V_153 < 0 )
goto V_375;
for ( V_362 = 0 ; V_362 < F_22 ( V_376 ) ; V_362 ++ )
if ( V_2 -> V_65 == V_376 [ V_362 ] . V_377 )
break;
if ( V_362 == F_22 ( V_376 ) ) {
F_119 ( V_2 -> V_24 , L_83 ,
( V_2 -> V_65 & 0xf0 ) >> 4 , V_2 -> V_65 & 0xf ) ;
V_153 = - V_374 ;
goto V_375;
}
for ( V_38 = 1 ; V_38 < V_371 ; V_38 ++ )
V_2 -> V_373 [ V_38 ] =
V_2 -> V_373 [ 0 ] + V_376 [ V_362 ] . V_378 [ V_38 ] ;
for ( V_38 = V_379 ; V_38 < V_380 ; V_38 ++ )
V_2 -> V_373 [ V_38 ] =
V_2 -> V_373 [ V_371 ]
+ V_376 [ V_362 ] . V_378 [ V_38 ] ;
V_2 -> V_381 =
V_361 -> V_382 + V_376 [ V_362 ] . V_378 [ V_383 ] ;
V_153 = F_188 ( V_2 ) ;
if ( V_153 < 0 ) {
F_119 ( & V_307 -> V_24 , L_84 ) ;
goto V_375;
}
V_153 = F_226 ( V_307 , 0 ) ;
if ( V_153 <= 0 ) {
F_119 ( V_2 -> V_24 , L_85 ) ;
V_153 = - V_374 ;
goto V_384;
}
V_2 -> V_385 = V_153 ;
if ( F_227 ( V_2 -> V_24 , V_2 -> V_385 , F_46 , V_386 ,
L_86 , V_2 ) ) {
F_119 ( V_2 -> V_24 , L_87 ) ;
V_153 = - V_39 ;
goto V_384;
}
V_153 = F_175 ( V_2 ) ;
if ( V_153 < 0 )
goto V_384;
V_153 = F_155 ( V_2 ) ;
if ( V_153 < 0 )
goto V_387;
V_153 = F_165 ( V_2 ) ;
if ( V_153 < 0 )
goto V_388;
V_2 -> V_308 . V_389 = F_206 ;
V_2 -> V_308 . V_390 = F_208 ;
V_153 = F_228 ( & V_2 -> V_258 , & V_2 -> V_308 ) ;
if ( V_153 )
goto V_388;
F_35 ( V_2 , 1 ) ;
F_10 ( V_2 ) ;
return 0 ;
V_388:
F_143 ( V_2 ) ;
V_387:
F_166 ( V_2 ) ;
V_384:
F_185 ( V_2 ) ;
V_375:
F_30 ( V_2 ) ;
F_130 ( V_2 , false ) ;
error:
F_229 ( & V_2 -> V_235 ) ;
return V_153 ;
}
