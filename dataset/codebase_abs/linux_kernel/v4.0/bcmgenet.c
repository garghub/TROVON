static inline void F_1 ( struct V_1 * V_2 ,
void T_1 * V_3 , T_2 V_4 )
{
F_2 ( V_4 , V_3 + V_5 ) ;
}
static inline T_2 F_3 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
return F_4 ( V_3 + V_5 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
void T_1 * V_3 ,
T_3 V_6 )
{
F_2 ( F_6 ( V_6 ) , V_3 + V_7 ) ;
#ifdef F_7
if ( V_2 -> V_8 -> V_9 & V_10 )
F_2 ( F_8 ( V_6 ) , V_3 + V_11 ) ;
#endif
}
static inline void F_9 ( struct V_1 * V_2 ,
void T_1 * V_3 , T_3 V_6 , T_2 V_12 )
{
F_1 ( V_2 , V_3 , V_12 ) ;
F_5 ( V_2 , V_3 , V_6 ) ;
}
static inline T_3 F_10 ( struct V_1 * V_2 ,
void T_1 * V_3 )
{
T_3 V_6 ;
V_6 = F_4 ( V_3 + V_7 ) ;
#ifdef F_7
if ( V_2 -> V_8 -> V_9 & V_10 )
V_6 |= ( V_13 ) F_4 ( V_3 + V_11 ) << 32 ;
#endif
return V_6 ;
}
static inline T_2 F_11 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return F_13 ( V_2 , V_14 ) ;
else
return F_14 ( V_2 , V_15 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , T_2 V_12 )
{
if ( F_12 ( V_2 ) )
F_16 ( V_2 , V_12 , V_14 ) ;
else
F_17 ( V_2 , V_12 , V_15 ) ;
}
static inline T_2 F_18 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return F_13 ( V_2 , V_16 ) ;
else
return F_4 ( V_2 -> V_17 +
V_2 -> V_8 -> V_18 + V_19 ) ;
}
static inline void F_19 ( struct V_1 * V_2 , T_2 V_12 )
{
if ( F_12 ( V_2 ) )
F_16 ( V_2 , V_12 , V_16 ) ;
else
F_2 ( V_12 , V_2 -> V_17 +
V_2 -> V_8 -> V_18 + V_19 ) ;
}
static inline T_2 F_20 ( struct V_1 * V_2 )
{
if ( F_12 ( V_2 ) )
return F_13 ( V_2 , V_20 ) ;
else
return F_4 ( V_2 -> V_17 +
V_2 -> V_8 -> V_18 + V_21 ) ;
}
static inline void F_21 ( struct V_1 * V_2 , T_2 V_12 )
{
if ( F_12 ( V_2 ) )
F_16 ( V_2 , V_12 , V_20 ) ;
else
F_2 ( V_12 , V_2 -> V_17 +
V_2 -> V_8 -> V_18 + V_21 ) ;
}
static inline struct V_1 * F_22 ( struct V_22 * V_23 )
{
return F_23 ( F_24 ( V_23 ) ) ;
}
static inline T_2 F_25 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
return F_4 ( V_2 -> V_17 + V_26 +
V_27 + V_28 [ V_25 ] ) ;
}
static inline void F_26 ( struct V_1 * V_2 ,
T_2 V_12 , enum V_24 V_25 )
{
F_2 ( V_12 , V_2 -> V_17 + V_26 +
V_27 + V_28 [ V_25 ] ) ;
}
static inline T_2 F_27 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
return F_4 ( V_2 -> V_17 + V_29 +
V_27 + V_28 [ V_25 ] ) ;
}
static inline void F_28 ( struct V_1 * V_2 ,
T_2 V_12 , enum V_24 V_25 )
{
F_2 ( V_12 , V_2 -> V_17 + V_29 +
V_27 + V_28 [ V_25 ] ) ;
}
static inline T_2 F_29 ( struct V_1 * V_2 ,
unsigned int V_30 ,
enum V_31 V_25 )
{
return F_4 ( V_2 -> V_17 + V_26 +
( V_32 * V_30 ) +
V_33 [ V_25 ] ) ;
}
static inline void F_30 ( struct V_1 * V_2 ,
unsigned int V_30 , T_2 V_12 ,
enum V_31 V_25 )
{
F_2 ( V_12 , V_2 -> V_17 + V_26 +
( V_32 * V_30 ) +
V_33 [ V_25 ] ) ;
}
static inline T_2 F_31 ( struct V_1 * V_2 ,
unsigned int V_30 ,
enum V_31 V_25 )
{
return F_4 ( V_2 -> V_17 + V_29 +
( V_32 * V_30 ) +
V_33 [ V_25 ] ) ;
}
static inline void F_32 ( struct V_1 * V_2 ,
unsigned int V_30 , T_2 V_12 ,
enum V_31 V_25 )
{
F_2 ( V_12 , V_2 -> V_17 + V_29 +
( V_32 * V_30 ) +
V_33 [ V_25 ] ) ;
}
static int F_33 ( struct V_34 * V_23 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
if ( ! F_34 ( V_23 ) )
return - V_37 ;
if ( ! V_2 -> V_38 )
return - V_39 ;
return F_35 ( V_2 -> V_38 , V_36 ) ;
}
static int F_36 ( struct V_34 * V_23 ,
struct V_35 * V_36 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
if ( ! F_34 ( V_23 ) )
return - V_37 ;
if ( ! V_2 -> V_38 )
return - V_39 ;
return F_37 ( V_2 -> V_38 , V_36 ) ;
}
static int F_38 ( struct V_34 * V_23 ,
T_4 V_40 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_41 ;
bool V_42 ;
V_42 = ! ! ( V_40 & V_43 ) ;
V_41 = F_13 ( V_2 , V_44 ) ;
if ( V_42 )
V_41 |= V_45 ;
else
V_41 &= ~ V_45 ;
V_2 -> V_46 = V_42 ;
if ( V_42 && V_2 -> V_47 )
V_41 |= V_48 ;
else
V_41 &= ~ V_48 ;
F_16 ( V_2 , V_41 , V_44 ) ;
return 0 ;
}
static int F_39 ( struct V_34 * V_23 ,
T_4 V_40 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
bool V_49 ;
T_2 V_50 , V_51 ;
V_50 = F_18 ( V_2 ) ;
V_51 = F_13 ( V_2 , V_52 ) ;
V_49 = ! ! ( V_40 & ( V_53 | V_54 ) ) ;
if ( V_49 ) {
V_50 |= V_55 ;
V_51 |= V_55 ;
} else {
V_50 &= ~ V_55 ;
V_51 &= ~ V_55 ;
}
V_2 -> V_49 = V_49 ;
F_19 ( V_2 , V_50 ) ;
F_16 ( V_2 , V_51 , V_52 ) ;
return 0 ;
}
static int F_40 ( struct V_34 * V_23 ,
T_4 V_56 )
{
T_4 V_57 = V_56 ^ V_23 -> V_56 ;
T_4 V_40 = V_23 -> V_58 ;
int V_59 = 0 ;
if ( V_57 & ( V_53 | V_54 ) )
V_59 = F_39 ( V_23 , V_40 ) ;
if ( V_57 & ( V_43 ) )
V_59 = F_38 ( V_23 , V_40 ) ;
return V_59 ;
}
static T_2 F_41 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
return V_2 -> V_60 ;
}
static void F_42 ( struct V_34 * V_23 , T_2 V_61 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
V_2 -> V_60 = V_61 ;
}
static void F_43 ( struct V_34 * V_23 ,
struct V_62 * V_63 )
{
F_44 ( V_63 -> V_64 , L_1 , sizeof( V_63 -> V_64 ) ) ;
F_44 ( V_63 -> V_65 , L_2 , sizeof( V_63 -> V_65 ) ) ;
V_63 -> V_66 = V_67 ;
}
static int F_45 ( struct V_34 * V_23 , int V_68 )
{
switch ( V_68 ) {
case V_69 :
return V_67 ;
default:
return - V_70 ;
}
}
static void F_46 ( struct V_34 * V_23 , T_2 V_71 ,
T_5 * V_72 )
{
int V_73 ;
switch ( V_71 ) {
case V_69 :
for ( V_73 = 0 ; V_73 < V_67 ; V_73 ++ ) {
memcpy ( V_72 + V_73 * V_74 ,
V_75 [ V_73 ] . V_76 ,
V_74 ) ;
}
break;
}
}
static void F_47 ( struct V_1 * V_2 )
{
int V_73 , V_77 = 0 ;
for ( V_73 = 0 ; V_73 < V_67 ; V_73 ++ ) {
const struct V_78 * V_79 ;
T_5 V_80 = 0 ;
T_2 V_12 = 0 ;
char * V_81 ;
V_79 = & V_75 [ V_73 ] ;
switch ( V_79 -> type ) {
case V_82 :
case V_83 :
continue;
case V_84 :
case V_85 :
case V_86 :
if ( V_79 -> type != V_84 )
V_80 = V_87 ;
V_12 = F_48 ( V_2 ,
V_88 + V_77 + V_80 ) ;
break;
case V_89 :
V_12 = F_48 ( V_2 , V_79 -> V_90 ) ;
if ( V_12 == ~ 0 )
F_49 ( V_2 , 0 , V_79 -> V_90 ) ;
break;
}
V_77 += V_79 -> V_91 ;
V_81 = ( char * ) V_2 + V_79 -> V_92 ;
* ( T_2 * ) V_81 = V_12 ;
}
}
static void F_50 ( struct V_34 * V_23 ,
struct V_93 * V_94 ,
V_13 * V_72 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_73 ;
if ( F_34 ( V_23 ) )
F_47 ( V_2 ) ;
for ( V_73 = 0 ; V_73 < V_67 ; V_73 ++ ) {
const struct V_78 * V_79 ;
char * V_81 ;
V_79 = & V_75 [ V_73 ] ;
if ( V_79 -> type == V_82 )
V_81 = ( char * ) & V_23 -> V_94 ;
else
V_81 = ( char * ) V_2 ;
V_81 += V_79 -> V_92 ;
V_72 [ V_73 ] = * ( T_2 * ) V_81 ;
}
}
static void F_51 ( struct V_34 * V_23 , bool V_95 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
T_2 V_96 = V_2 -> V_8 -> V_18 + V_97 ;
T_2 V_98 ;
if ( V_95 && ! V_2 -> V_99 ) {
F_52 ( V_2 -> V_100 ) ;
V_2 -> V_99 = true ;
}
V_98 = F_48 ( V_2 , V_101 ) ;
if ( V_95 )
V_98 |= V_102 ;
else
V_98 &= ~ V_102 ;
F_49 ( V_2 , V_98 , V_101 ) ;
V_98 = F_4 ( V_2 -> V_17 + V_96 ) ;
if ( V_95 )
V_98 |= V_103 | V_104 ;
else
V_98 &= ~ ( V_103 | V_104 ) ;
F_2 ( V_98 , V_2 -> V_17 + V_96 ) ;
V_98 = F_13 ( V_2 , V_105 ) ;
if ( V_95 )
V_98 |= V_106 | V_107 ;
else
V_98 &= ~ ( V_106 | V_107 ) ;
F_16 ( V_2 , V_98 , V_105 ) ;
if ( ! V_95 && V_2 -> V_99 ) {
F_53 ( V_2 -> V_100 ) ;
V_2 -> V_99 = false ;
}
V_2 -> V_108 . V_109 = V_95 ;
V_2 -> V_108 . V_110 = V_95 ;
}
static int F_54 ( struct V_34 * V_23 , struct V_111 * V_112 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_111 * V_81 = & V_2 -> V_108 ;
if ( F_12 ( V_2 ) )
return - V_70 ;
V_112 -> V_109 = V_81 -> V_109 ;
V_112 -> V_110 = V_81 -> V_110 ;
V_112 -> V_113 = F_48 ( V_2 , V_114 ) ;
return F_55 ( V_2 -> V_38 , V_112 ) ;
}
static int F_56 ( struct V_34 * V_23 , struct V_111 * V_112 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_111 * V_81 = & V_2 -> V_108 ;
int V_59 = 0 ;
if ( F_12 ( V_2 ) )
return - V_70 ;
V_81 -> V_109 = V_112 -> V_109 ;
if ( ! V_81 -> V_109 ) {
F_51 ( V_23 , false ) ;
} else {
V_59 = F_57 ( V_2 -> V_38 , 0 ) ;
if ( V_59 ) {
F_58 ( V_2 , V_115 , V_23 , L_3 ) ;
return V_59 ;
}
F_49 ( V_2 , V_112 -> V_113 , V_114 ) ;
F_51 ( V_23 , true ) ;
}
return F_59 ( V_2 -> V_38 , V_112 ) ;
}
static int F_60 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
return F_61 ( V_2 -> V_38 ) ;
}
static void F_62 ( struct V_1 * V_2 ,
enum V_116 V_117 )
{
T_2 V_98 ;
switch ( V_117 ) {
case V_118 :
F_63 ( V_2 -> V_38 ) ;
break;
case V_119 :
F_64 ( V_2 , V_117 ) ;
break;
case V_120 :
if ( V_2 -> V_8 -> V_9 & V_121 ) {
V_98 = F_65 ( V_2 , V_122 ) ;
V_98 |= ( V_123 |
V_124 | V_125 ) ;
F_66 ( V_2 , V_98 , V_122 ) ;
}
break;
default:
break;
}
}
static void F_67 ( struct V_1 * V_2 ,
enum V_116 V_117 )
{
T_2 V_98 ;
if ( ! ( V_2 -> V_8 -> V_9 & V_121 ) )
return;
V_98 = F_65 ( V_2 , V_122 ) ;
switch ( V_117 ) {
case V_120 :
V_98 &= ~ ( V_124 | V_123 |
V_125 ) ;
case V_118 :
V_98 |= V_126 ;
break;
case V_119 :
F_68 ( V_2 , V_117 ) ;
return;
default:
break;
}
F_66 ( V_2 , V_98 , V_122 ) ;
if ( V_117 == V_120 )
F_69 ( V_2 -> V_23 ) ;
}
static int F_70 ( struct V_34 * V_23 , struct V_127 * V_128 , int V_36 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_12 = 0 ;
if ( ! F_34 ( V_23 ) )
return - V_37 ;
switch ( V_36 ) {
case V_129 :
case V_130 :
case V_131 :
if ( ! V_2 -> V_38 )
V_12 = - V_39 ;
else
V_12 = F_71 ( V_2 -> V_38 , V_128 , V_36 ) ;
break;
default:
V_12 = - V_37 ;
break;
}
return V_12 ;
}
static struct V_132 * F_72 ( struct V_1 * V_2 ,
struct V_133 * V_30 )
{
struct V_132 * V_134 ;
V_134 = V_30 -> V_135 ;
V_134 += V_30 -> V_136 - V_30 -> V_137 ;
V_134 -> V_138 = V_2 -> V_139 + V_30 -> V_136 * V_140 ;
if ( V_30 -> V_136 == V_30 -> V_141 )
V_30 -> V_136 = V_30 -> V_137 ;
else
V_30 -> V_136 ++ ;
return V_134 ;
}
static void F_73 ( struct V_132 * V_142 )
{
F_74 ( V_142 -> V_143 ) ;
V_142 -> V_143 = NULL ;
F_75 ( V_142 , V_144 , 0 ) ;
}
static inline void F_76 ( struct V_1 * V_2 ,
struct V_133 * V_30 )
{
F_77 ( V_2 ,
V_145 | V_146 ,
V_147 ) ;
}
static inline void F_78 ( struct V_1 * V_2 ,
struct V_133 * V_30 )
{
F_77 ( V_2 ,
V_145 | V_146 ,
V_148 ) ;
}
static inline void F_79 ( struct V_1 * V_2 ,
struct V_133 * V_30 )
{
F_80 ( V_2 , ( 1 << V_30 -> V_149 ) ,
V_148 ) ;
V_2 -> V_150 &= ~ ( 1 << V_30 -> V_149 ) ;
}
static inline void F_81 ( struct V_1 * V_2 ,
struct V_133 * V_30 )
{
F_80 ( V_2 , ( 1 << V_30 -> V_149 ) ,
V_147 ) ;
V_2 -> V_150 |= ( 1 << V_30 -> V_149 ) ;
}
static unsigned int F_82 ( struct V_34 * V_23 ,
struct V_133 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_151 , V_152 , V_153 ;
struct V_132 * V_134 ;
struct V_154 * V_155 ;
unsigned int V_156 = 0 ;
unsigned int V_157 ;
unsigned int V_158 ;
V_158 = F_29 ( V_2 , V_30 -> V_149 , V_159 ) ;
V_155 = F_83 ( V_23 , V_30 -> V_160 ) ;
V_152 = V_30 -> V_158 ;
V_153 = V_30 -> V_161 ;
V_158 &= ( V_153 - 1 ) ;
if ( V_158 >= V_152 )
V_151 = V_158 - V_152 ;
else
V_151 = V_153 - V_152 + V_158 ;
F_84 ( V_2 , V_162 , V_23 ,
L_4 ,
V_163 , V_30 -> V_149 ,
V_158 , V_151 , V_152 ) ;
while ( V_151 -- > 0 ) {
V_134 = V_30 -> V_135 + V_152 ;
V_157 = 0 ;
if ( V_134 -> V_143 ) {
V_156 ++ ;
V_157 = F_85 ( V_134 -> V_143 ) -> V_164 + 1 ;
V_23 -> V_94 . V_165 += V_134 -> V_143 -> V_166 ;
F_86 ( & V_23 -> V_23 ,
F_87 ( V_134 , V_144 ) ,
V_134 -> V_143 -> V_166 ,
V_167 ) ;
F_73 ( V_134 ) ;
} else if ( F_87 ( V_134 , V_144 ) ) {
V_23 -> V_94 . V_165 +=
F_88 ( V_134 , V_168 ) ;
F_89 ( & V_23 -> V_23 ,
F_87 ( V_134 , V_144 ) ,
F_88 ( V_134 , V_168 ) ,
V_167 ) ;
F_75 ( V_134 , V_144 , 0 ) ;
}
V_23 -> V_94 . V_169 ++ ;
V_30 -> V_170 += V_157 ;
V_152 ++ ;
V_152 &= ( V_153 - 1 ) ;
}
if ( V_30 -> V_170 > ( V_171 + 1 ) ) {
if ( F_90 ( V_155 ) )
F_91 ( V_155 ) ;
}
V_30 -> V_158 = V_158 ;
return V_156 ;
}
static unsigned int F_92 ( struct V_34 * V_23 ,
struct V_133 * V_30 )
{
unsigned int V_172 ;
unsigned long V_9 ;
F_93 ( & V_30 -> V_173 , V_9 ) ;
V_172 = F_82 ( V_23 , V_30 ) ;
F_94 ( & V_30 -> V_173 , V_9 ) ;
return V_172 ;
}
static int F_95 ( struct V_174 * V_175 , int V_176 )
{
struct V_133 * V_30 =
F_96 ( V_175 , struct V_133 , V_175 ) ;
unsigned int V_177 = 0 ;
V_177 = F_92 ( V_30 -> V_2 -> V_23 , V_30 ) ;
if ( V_177 == 0 ) {
F_97 ( V_175 ) ;
V_30 -> V_178 ( V_30 -> V_2 , V_30 ) ;
return 0 ;
}
return V_176 ;
}
static void F_98 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_73 ;
if ( F_99 ( V_23 ) ) {
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_179 ; V_73 ++ )
F_92 ( V_23 , & V_2 -> V_180 [ V_73 ] ) ;
}
F_92 ( V_23 , & V_2 -> V_180 [ V_181 ] ) ;
}
static int F_100 ( struct V_34 * V_23 ,
struct V_182 * V_143 ,
T_6 V_183 ,
struct V_133 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_184 = & V_2 -> V_185 -> V_23 ;
struct V_132 * V_134 ;
unsigned int V_186 ;
T_3 V_187 ;
T_2 V_188 ;
int V_59 ;
V_134 = F_72 ( V_2 , V_30 ) ;
if ( F_101 ( ! V_134 ) )
F_102 () ;
V_134 -> V_143 = V_143 ;
V_186 = F_103 ( V_143 ) < V_189 ? V_189 : F_103 ( V_143 ) ;
V_187 = F_104 ( V_184 , V_143 -> V_72 , V_186 , V_167 ) ;
V_59 = F_105 ( V_184 , V_187 ) ;
if ( V_59 ) {
V_2 -> V_190 . V_191 ++ ;
F_58 ( V_2 , V_192 , V_23 , L_5 ) ;
F_106 ( V_143 ) ;
return V_59 ;
}
F_75 ( V_134 , V_144 , V_187 ) ;
F_107 ( V_134 , V_168 , V_143 -> V_166 ) ;
V_188 = ( V_186 << V_193 ) | V_183 |
( V_2 -> V_8 -> V_194 << V_195 ) |
V_196 ;
if ( V_143 -> V_197 == V_198 )
V_188 |= V_199 ;
F_9 ( V_2 , V_134 -> V_138 , V_187 , V_188 ) ;
V_30 -> V_170 -= 1 ;
V_30 -> V_200 += 1 ;
V_30 -> V_200 &= V_201 ;
return 0 ;
}
static int F_108 ( struct V_34 * V_23 ,
T_7 * V_202 ,
T_6 V_183 ,
struct V_133 * V_30 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_22 * V_184 = & V_2 -> V_185 -> V_23 ;
struct V_132 * V_134 ;
T_3 V_187 ;
int V_59 ;
V_134 = F_72 ( V_2 , V_30 ) ;
if ( F_101 ( ! V_134 ) )
F_102 () ;
V_134 -> V_143 = NULL ;
V_187 = F_109 ( V_184 , V_202 , 0 ,
F_110 ( V_202 ) , V_167 ) ;
V_59 = F_105 ( V_184 , V_187 ) ;
if ( V_59 ) {
V_2 -> V_190 . V_191 ++ ;
F_58 ( V_2 , V_192 , V_23 , L_6 ,
V_163 ) ;
return V_59 ;
}
F_75 ( V_134 , V_144 , V_187 ) ;
F_107 ( V_134 , V_168 , V_202 -> V_161 ) ;
F_9 ( V_2 , V_134 -> V_138 , V_187 ,
( V_202 -> V_161 << V_193 ) | V_183 |
( V_2 -> V_8 -> V_194 << V_195 ) ) ;
V_30 -> V_170 -= 1 ;
V_30 -> V_200 += 1 ;
V_30 -> V_200 &= V_201 ;
return 0 ;
}
static struct V_182 * F_111 ( struct V_34 * V_23 ,
struct V_182 * V_143 )
{
struct V_203 * V_204 = NULL ;
struct V_182 * V_205 ;
T_6 V_80 ;
T_5 V_206 ;
T_6 V_207 ;
T_2 V_208 ;
if ( F_101 ( F_112 ( V_143 ) < sizeof( * V_204 ) ) ) {
V_205 = F_113 ( V_143 , sizeof( * V_204 ) ) ;
F_106 ( V_143 ) ;
if ( ! V_205 ) {
V_23 -> V_94 . V_209 ++ ;
V_23 -> V_94 . V_210 ++ ;
return NULL ;
}
V_143 = V_205 ;
}
F_114 ( V_143 , sizeof( * V_204 ) ) ;
V_204 = (struct V_203 * ) V_143 -> V_72 ;
if ( V_143 -> V_197 == V_198 ) {
V_207 = F_115 ( V_143 -> V_211 ) ;
switch ( V_207 ) {
case V_212 :
V_206 = F_116 ( V_143 ) -> V_211 ;
break;
case V_213 :
V_206 = F_117 ( V_143 ) -> V_214 ;
break;
default:
return V_143 ;
}
V_80 = F_118 ( V_143 ) - sizeof( * V_204 ) ;
V_208 = ( V_80 << V_215 ) |
( V_80 + V_143 -> V_216 ) ;
if ( V_206 == V_217 || V_206 == V_218 ) {
V_208 |= V_219 ;
if ( V_206 == V_218 && V_207 == V_212 )
V_208 |= V_220 ;
} else {
V_208 = 0 ;
}
V_204 -> V_208 = V_208 ;
}
return V_143 ;
}
static T_8 F_119 ( struct V_182 * V_143 , struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_133 * V_30 = NULL ;
struct V_154 * V_155 ;
unsigned long V_9 = 0 ;
int V_164 , V_149 ;
T_6 V_183 ;
int V_59 ;
int V_73 ;
V_149 = F_120 ( V_143 ) ;
if ( V_149 == 0 )
V_149 = V_181 ;
else
V_149 -= 1 ;
V_164 = F_85 ( V_143 ) -> V_164 ;
V_30 = & V_2 -> V_180 [ V_149 ] ;
V_155 = F_83 ( V_23 , V_30 -> V_160 ) ;
F_93 ( & V_30 -> V_173 , V_9 ) ;
if ( V_30 -> V_170 <= V_164 + 1 ) {
F_121 ( V_155 ) ;
F_122 ( V_23 , L_7 ,
V_163 , V_149 , V_30 -> V_160 ) ;
V_59 = V_221 ;
goto V_222;
}
if ( F_123 ( V_143 , V_189 ) ) {
V_59 = V_223 ;
goto V_222;
}
if ( V_2 -> V_49 ) {
V_143 = F_111 ( V_23 , V_143 ) ;
if ( ! V_143 ) {
V_59 = V_223 ;
goto V_222;
}
}
V_183 = V_224 ;
if ( V_164 == 0 )
V_183 |= V_225 ;
V_59 = F_100 ( V_23 , V_143 , V_183 , V_30 ) ;
if ( V_59 ) {
V_59 = V_223 ;
goto V_222;
}
for ( V_73 = 0 ; V_73 < V_164 ; V_73 ++ ) {
V_59 = F_108 ( V_23 ,
& F_85 ( V_143 ) -> V_226 [ V_73 ] ,
( V_73 == V_164 - 1 ) ? V_225 : 0 ,
V_30 ) ;
if ( V_59 ) {
V_59 = V_223 ;
goto V_222;
}
}
F_124 ( V_143 ) ;
F_30 ( V_2 , V_30 -> V_149 ,
V_30 -> V_200 , V_227 ) ;
if ( V_30 -> V_170 <= ( V_171 + 1 ) )
F_121 ( V_155 ) ;
V_222:
F_94 ( & V_30 -> V_173 , V_9 ) ;
return V_59 ;
}
static int F_125 ( struct V_1 * V_2 , struct V_132 * V_142 )
{
struct V_22 * V_184 = & V_2 -> V_185 -> V_23 ;
struct V_182 * V_143 ;
T_3 V_187 ;
int V_59 ;
V_143 = F_126 ( V_2 -> V_23 , V_2 -> V_228 + V_229 ) ;
if ( ! V_143 )
return - V_230 ;
F_127 ( V_142 -> V_143 != NULL ) ;
V_142 -> V_143 = V_143 ;
V_187 = F_104 ( V_184 , V_143 -> V_72 ,
V_2 -> V_228 , V_231 ) ;
V_59 = F_105 ( V_184 , V_187 ) ;
if ( V_59 ) {
V_2 -> V_190 . V_232 ++ ;
F_73 ( V_142 ) ;
F_58 ( V_2 , V_233 , V_2 -> V_23 ,
L_8 , V_163 ) ;
return V_59 ;
}
F_75 ( V_142 , V_144 , V_187 ) ;
F_5 ( V_2 , V_2 -> V_234 , V_187 ) ;
V_2 -> V_235 ++ ;
V_2 -> V_235 &= ( V_2 -> V_236 - 1 ) ;
V_2 -> V_234 = V_2 -> V_237 +
( V_2 -> V_235 * V_140 ) ;
return 0 ;
}
static unsigned int F_128 ( struct V_1 * V_2 ,
unsigned int V_176 )
{
struct V_34 * V_23 = V_2 -> V_23 ;
struct V_132 * V_142 ;
struct V_182 * V_143 ;
T_2 V_238 ;
unsigned long V_239 ;
int V_166 , V_240 ;
unsigned int V_241 = 0 , V_242 ;
unsigned int V_243 ;
unsigned int V_244 = 0 ;
V_243 = F_31 ( V_2 , V_181 , V_245 ) ;
V_243 &= V_201 ;
if ( V_243 < V_2 -> V_246 )
V_242 = ( V_247 + 1 ) -
V_2 -> V_246 + V_243 ;
else
V_242 = V_243 - V_2 -> V_246 ;
F_84 ( V_2 , V_248 , V_23 ,
L_9 , V_242 ) ;
while ( ( V_241 < V_242 ) &&
( V_241 < V_176 ) ) {
V_142 = & V_2 -> V_249 [ V_2 -> V_250 ] ;
V_143 = V_142 -> V_143 ;
if ( F_101 ( ! V_143 ) ) {
V_23 -> V_94 . V_251 ++ ;
V_23 -> V_94 . V_252 ++ ;
goto V_253;
}
F_86 ( & V_23 -> V_23 , F_87 ( V_142 , V_144 ) ,
V_2 -> V_228 , V_231 ) ;
if ( ! V_2 -> V_49 ) {
V_238 =
F_3 ( V_2 ,
V_2 -> V_237 +
( V_2 -> V_250 *
V_140 ) ) ;
} else {
struct V_203 * V_204 ;
V_204 = (struct V_203 * ) V_143 -> V_72 ;
V_238 = V_204 -> V_188 ;
}
V_239 = V_238 & 0xffff ;
V_166 = V_238 >> V_193 ;
F_84 ( V_2 , V_248 , V_23 ,
L_10 ,
V_163 , V_243 , V_2 -> V_246 ,
V_2 -> V_250 , V_238 ) ;
if ( F_101 ( ! ( V_239 & V_225 ) || ! ( V_239 & V_224 ) ) ) {
F_58 ( V_2 , V_248 , V_23 ,
L_11 ) ;
V_23 -> V_94 . V_251 ++ ;
V_23 -> V_94 . V_252 ++ ;
F_74 ( V_142 -> V_143 ) ;
V_142 -> V_143 = NULL ;
goto V_253;
}
if ( F_101 ( V_239 & ( V_254 |
V_255 |
V_256 |
V_257 |
V_258 ) ) ) {
F_58 ( V_2 , V_248 , V_23 , L_12 ,
( unsigned int ) V_239 ) ;
if ( V_239 & V_254 )
V_23 -> V_94 . V_259 ++ ;
if ( V_239 & V_255 )
V_23 -> V_94 . V_260 ++ ;
if ( V_239 & V_256 )
V_23 -> V_94 . V_261 ++ ;
if ( V_239 & V_257 )
V_23 -> V_94 . V_262 ++ ;
V_23 -> V_94 . V_251 ++ ;
V_23 -> V_94 . V_252 ++ ;
F_74 ( V_142 -> V_143 ) ;
V_142 -> V_143 = NULL ;
goto V_253;
}
V_244 = ( V_239 & V_2 -> V_263 ) &&
V_2 -> V_46 ;
F_129 ( V_143 , V_166 ) ;
if ( V_2 -> V_49 ) {
F_130 ( V_143 , 64 ) ;
V_166 -= 64 ;
}
if ( F_131 ( V_244 ) )
V_143 -> V_197 = V_264 ;
F_130 ( V_143 , 2 ) ;
V_166 -= 2 ;
if ( V_2 -> V_47 ) {
F_132 ( V_143 , V_166 - V_265 ) ;
V_166 -= V_265 ;
}
V_143 -> V_211 = F_133 ( V_143 , V_2 -> V_23 ) ;
V_23 -> V_94 . V_266 ++ ;
V_23 -> V_94 . V_267 += V_166 ;
if ( V_239 & V_268 )
V_23 -> V_94 . V_269 ++ ;
F_134 ( & V_2 -> V_175 , V_143 ) ;
V_142 -> V_143 = NULL ;
F_84 ( V_2 , V_248 , V_23 , L_13 ) ;
V_253:
V_240 = F_125 ( V_2 , V_142 ) ;
if ( V_240 ) {
V_2 -> V_190 . V_270 ++ ;
F_58 ( V_2 , V_233 , V_23 , L_14 ) ;
}
V_241 ++ ;
V_2 -> V_250 ++ ;
V_2 -> V_250 &= ( V_2 -> V_236 - 1 ) ;
}
return V_241 ;
}
static int F_135 ( struct V_1 * V_2 )
{
struct V_132 * V_142 ;
int V_59 = 0 ;
int V_73 ;
F_84 ( V_2 , V_115 , V_2 -> V_23 , L_15 , V_163 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_236 ; V_73 ++ ) {
V_142 = & V_2 -> V_249 [ V_2 -> V_235 ] ;
if ( V_142 -> V_143 )
continue;
V_59 = F_125 ( V_2 , V_142 ) ;
if ( V_59 )
break;
}
return V_59 ;
}
static void F_136 ( struct V_1 * V_2 )
{
struct V_132 * V_142 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_236 ; V_73 ++ ) {
V_142 = & V_2 -> V_249 [ V_73 ] ;
if ( F_87 ( V_142 , V_144 ) ) {
F_86 ( & V_2 -> V_23 -> V_23 ,
F_87 ( V_142 , V_144 ) ,
V_2 -> V_228 , V_231 ) ;
F_75 ( V_142 , V_144 , 0 ) ;
}
if ( V_142 -> V_143 )
F_73 ( V_142 ) ;
}
}
static void F_137 ( struct V_1 * V_2 , T_2 V_271 , bool V_95 )
{
T_2 V_98 ;
V_98 = F_48 ( V_2 , V_272 ) ;
if ( V_95 )
V_98 |= V_271 ;
else
V_98 &= ~ V_271 ;
F_49 ( V_2 , V_98 , V_272 ) ;
if ( V_95 == 0 )
F_138 ( 1000 , 2000 ) ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_22 * V_184 = & V_2 -> V_185 -> V_23 ;
unsigned int V_273 = 0 ;
T_2 V_98 ;
F_15 ( V_2 , 0 ) ;
F_140 ( 10 ) ;
F_49 ( V_2 , 0 , V_272 ) ;
F_49 ( V_2 , V_274 , V_272 ) ;
while ( V_273 ++ < 1000 ) {
V_98 = F_48 ( V_2 , V_272 ) ;
if ( ! ( V_98 & V_274 ) )
return 0 ;
F_140 ( 1 ) ;
}
if ( V_273 == 1000 ) {
F_141 ( V_184 ,
L_16 ) ;
return - V_275 ;
}
return 0 ;
}
static void F_142 ( struct V_1 * V_2 )
{
F_77 ( V_2 , 0xFFFFFFFF , V_147 ) ;
F_77 ( V_2 , 0xFFFFFFFF , V_276 ) ;
F_77 ( V_2 , 0 , V_148 ) ;
F_80 ( V_2 , 0xFFFFFFFF , V_147 ) ;
F_80 ( V_2 , 0xFFFFFFFF , V_276 ) ;
F_80 ( V_2 , 0 , V_148 ) ;
}
static int F_143 ( struct V_1 * V_2 )
{
struct V_22 * V_184 = & V_2 -> V_185 -> V_23 ;
int V_59 ;
T_2 V_98 , V_277 ;
int V_149 ;
F_144 ( & V_2 -> V_185 -> V_23 , L_17 ) ;
V_59 = F_139 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_49 ( V_2 , 0 , V_272 ) ;
F_49 ( V_2 ,
V_278 | V_279 | V_280 ,
V_281 ) ;
F_49 ( V_2 , 0 , V_281 ) ;
F_49 ( V_2 , V_282 , V_283 ) ;
V_98 = F_13 ( V_2 , V_52 ) ;
V_98 |= V_284 ;
F_16 ( V_2 , V_98 , V_52 ) ;
if ( ! F_12 ( V_2 ) && ! F_145 ( V_2 ) )
F_16 ( V_2 , 1 , V_285 ) ;
F_142 ( V_2 ) ;
V_277 = V_286 | V_145 ;
F_144 ( V_184 , L_18 , V_163 ) ;
if ( F_146 ( V_2 -> V_38 ) ) {
V_277 |= ( V_287 | V_288 ) ;
} else if ( V_2 -> V_289 ) {
V_277 |= ( V_287 | V_288 ) ;
} else if ( V_2 -> V_290 == V_291 ) {
V_98 = F_20 ( V_2 ) ;
V_98 |= F_147 ( V_2 -> V_8 -> V_292 ) ;
if ( F_99 ( V_2 -> V_23 ) )
V_98 |= V_2 -> V_8 -> V_293 ;
else
V_98 &= ~ V_2 -> V_8 -> V_293 ;
F_21 ( V_2 , V_98 ) ;
}
if ( V_2 -> V_8 -> V_9 & V_294 )
V_277 |= V_295 | V_296 ;
F_77 ( V_2 , V_277 , V_148 ) ;
for ( V_149 = 0 ; V_149 < V_2 -> V_8 -> V_179 ; V_149 ++ )
F_80 ( V_2 , ( 1 << V_149 ) ,
V_148 ) ;
F_144 ( V_184 , L_19 ) ;
return 0 ;
}
static void F_148 ( struct V_1 * V_2 ,
unsigned int V_149 , unsigned int V_161 ,
unsigned int V_136 , unsigned int V_141 )
{
struct V_133 * V_30 = & V_2 -> V_180 [ V_149 ] ;
T_2 V_297 = F_149 ( V_2 ) ;
T_2 V_298 = 0 ;
unsigned int V_299 ;
F_150 ( & V_30 -> V_173 ) ;
V_30 -> V_2 = V_2 ;
F_151 ( V_2 -> V_23 , & V_30 -> V_175 , F_95 , 64 ) ;
V_30 -> V_149 = V_149 ;
if ( V_149 == V_181 ) {
V_30 -> V_160 = 0 ;
V_30 -> V_178 = F_78 ;
V_30 -> V_300 = F_76 ;
} else {
V_30 -> V_160 = V_149 + 1 ;
V_30 -> V_178 = F_79 ;
V_30 -> V_300 = F_81 ;
}
V_30 -> V_135 = V_2 -> V_301 + V_136 ;
V_30 -> V_161 = V_161 ;
V_30 -> V_158 = 0 ;
V_30 -> V_170 = V_161 ;
V_30 -> V_136 = V_136 ;
V_30 -> V_137 = V_136 ;
V_30 -> V_141 = V_141 - 1 ;
V_30 -> V_200 = 0 ;
if ( V_149 != V_181 )
V_298 = V_282 << 16 ;
F_30 ( V_2 , V_149 , 0 , V_227 ) ;
F_30 ( V_2 , V_149 , 0 , V_159 ) ;
F_30 ( V_2 , V_149 , 1 , V_302 ) ;
F_30 ( V_2 , V_149 , V_298 ,
V_303 ) ;
F_30 ( V_2 , V_149 ,
( ( V_161 << V_304 ) |
V_305 ) , V_306 ) ;
V_299 = V_136 ;
F_30 ( V_2 , V_149 , V_299 * V_297 ,
V_307 ) ;
F_30 ( V_2 , V_149 , V_299 * V_297 ,
V_308 ) ;
F_30 ( V_2 , V_149 , V_299 ,
V_309 ) ;
F_30 ( V_2 , V_149 , V_141 * V_297 - 1 ,
V_310 ) ;
F_152 ( & V_30 -> V_175 ) ;
}
static void F_153 ( struct V_1 * V_2 ,
unsigned int V_149 )
{
struct V_133 * V_30 = & V_2 -> V_180 [ V_149 ] ;
F_154 ( & V_30 -> V_175 ) ;
F_155 ( & V_30 -> V_175 ) ;
}
static int F_156 ( struct V_1 * V_2 ,
unsigned int V_149 , unsigned int V_161 )
{
T_2 V_297 = F_149 ( V_2 ) ;
int V_59 ;
V_2 -> V_236 = V_311 ;
V_2 -> V_237 = V_2 -> V_17 + V_2 -> V_8 -> V_312 ;
V_2 -> V_234 = V_2 -> V_237 ;
V_2 -> V_235 = 0 ;
V_2 -> V_246 = 0 ;
V_2 -> V_250 = 0 ;
V_2 -> V_249 = F_157 ( V_2 -> V_236 , sizeof( struct V_132 ) ,
V_313 ) ;
if ( ! V_2 -> V_249 )
return - V_230 ;
V_59 = F_135 ( V_2 ) ;
if ( V_59 ) {
F_158 ( V_2 -> V_249 ) ;
return V_59 ;
}
F_32 ( V_2 , V_149 , 0 , V_314 ) ;
F_32 ( V_2 , V_149 , 0 , V_245 ) ;
F_32 ( V_2 , V_149 , 0 , V_315 ) ;
F_32 ( V_2 , V_149 ,
( ( V_161 << V_304 ) |
V_305 ) , V_306 ) ;
F_32 ( V_2 , V_149 , 0 , V_307 ) ;
F_32 ( V_2 , V_149 ,
V_297 * V_161 - 1 , V_310 ) ;
F_32 ( V_2 , V_149 ,
( V_316 <<
V_317 ) |
V_318 , V_319 ) ;
F_32 ( V_2 , V_149 , 0 , V_320 ) ;
return V_59 ;
}
static void F_159 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned int V_73 , V_321 ;
T_2 V_98 , V_322 , V_323 = 0 ;
T_2 V_324 [ 3 ] = { 0 , 0 , 0 } ;
if ( ! F_99 ( V_23 ) ) {
F_160 ( V_23 , L_20 ) ;
return;
}
V_322 = F_25 ( V_2 , V_325 ) ;
V_321 = V_322 & V_326 ;
V_322 &= ~ V_326 ;
F_26 ( V_2 , V_322 , V_325 ) ;
F_26 ( V_2 , V_327 , V_328 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_179 ; V_73 ++ ) {
F_148 ( V_2 , V_73 , V_2 -> V_8 -> V_329 ,
V_73 * V_2 -> V_8 -> V_329 ,
( V_73 + 1 ) * V_2 -> V_8 -> V_329 ) ;
V_323 |= 1 << V_73 ;
V_322 |= 1 << ( V_73 + V_330 ) ;
V_324 [ F_161 ( V_73 ) ] |=
( ( V_331 + V_73 ) << F_162 ( V_73 ) ) ;
}
V_324 [ F_161 ( V_181 ) ] |=
( ( V_331 + V_2 -> V_8 -> V_179 ) <<
F_162 ( V_181 ) ) ;
F_26 ( V_2 , V_324 [ 0 ] , V_332 ) ;
F_26 ( V_2 , V_324 [ 1 ] , V_333 ) ;
F_26 ( V_2 , V_324 [ 2 ] , V_334 ) ;
V_98 = F_25 ( V_2 , V_335 ) ;
V_98 |= V_323 ;
F_26 ( V_2 , V_98 , V_335 ) ;
V_98 = F_25 ( V_2 , V_325 ) ;
V_98 |= V_322 ;
if ( V_321 )
V_98 |= V_326 ;
F_26 ( V_2 , V_98 , V_325 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_59 = 0 ;
int V_273 = 0 ;
T_2 V_98 ;
V_98 = F_25 ( V_2 , V_325 ) ;
V_98 &= ~ V_326 ;
F_26 ( V_2 , V_98 , V_325 ) ;
while ( V_273 ++ < V_336 ) {
V_98 = F_25 ( V_2 , V_337 ) ;
if ( V_98 & V_338 )
break;
F_140 ( 1 ) ;
}
if ( V_273 == V_336 ) {
F_160 ( V_2 -> V_23 , L_21 ) ;
V_59 = - V_275 ;
}
F_138 ( 10000 , 20000 ) ;
V_98 = F_27 ( V_2 , V_325 ) ;
V_98 &= ~ V_326 ;
F_28 ( V_2 , V_98 , V_325 ) ;
V_273 = 0 ;
while ( V_273 ++ < V_336 ) {
V_98 = F_27 ( V_2 , V_337 ) ;
if ( V_98 & V_338 )
break;
F_140 ( 1 ) ;
}
if ( V_273 == V_336 ) {
F_160 ( V_2 -> V_23 , L_22 ) ;
V_59 = - V_275 ;
}
return V_59 ;
}
static void F_164 ( struct V_1 * V_2 )
{
int V_73 ;
F_163 ( V_2 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_153 ; V_73 ++ ) {
if ( V_2 -> V_301 [ V_73 ] . V_143 != NULL ) {
F_106 ( V_2 -> V_301 [ V_73 ] . V_143 ) ;
V_2 -> V_301 [ V_73 ] . V_143 = NULL ;
}
}
F_136 ( V_2 ) ;
F_158 ( V_2 -> V_249 ) ;
F_158 ( V_2 -> V_301 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
int V_73 ;
F_153 ( V_2 , V_181 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_8 -> V_179 ; V_73 ++ )
F_153 ( V_2 , V_73 ) ;
F_164 ( V_2 ) ;
}
static int F_166 ( struct V_1 * V_2 )
{
int V_59 ;
F_84 ( V_2 , V_115 , V_2 -> V_23 , L_23 ) ;
V_59 = F_156 ( V_2 , V_181 , V_311 ) ;
if ( V_59 ) {
F_122 ( V_2 -> V_23 , L_24 ) ;
return V_59 ;
}
F_28 ( V_2 , V_339 , V_340 ) ;
F_26 ( V_2 , V_339 , V_340 ) ;
V_2 -> V_139 = V_2 -> V_17 + V_2 -> V_8 -> V_341 ;
V_2 -> V_153 = V_311 ;
V_2 -> V_301 = F_157 ( V_2 -> V_153 , sizeof( struct V_132 ) ,
V_313 ) ;
if ( ! V_2 -> V_301 ) {
F_164 ( V_2 ) ;
return - V_230 ;
}
F_159 ( V_2 -> V_23 ) ;
F_148 ( V_2 , V_181 , V_342 ,
V_2 -> V_8 -> V_179 *
V_2 -> V_8 -> V_329 ,
V_311 ) ;
return 0 ;
}
static int F_167 ( struct V_174 * V_175 , int V_176 )
{
struct V_1 * V_2 = F_96 ( V_175 ,
struct V_1 , V_175 ) ;
unsigned int V_177 ;
V_177 = F_128 ( V_2 , V_176 ) ;
V_2 -> V_246 += V_177 ;
V_2 -> V_246 &= V_247 ;
F_32 ( V_2 , V_181 ,
V_2 -> V_246 , V_315 ) ;
if ( V_177 < V_176 ) {
F_97 ( V_175 ) ;
F_77 ( V_2 , V_286 ,
V_148 ) ;
}
return V_177 ;
}
static void F_168 ( struct V_343 * V_344 )
{
struct V_1 * V_2 = F_96 (
V_344 , struct V_1 , V_345 ) ;
F_84 ( V_2 , V_346 , V_2 -> V_23 , L_25 , V_163 ) ;
if ( V_2 -> V_347 & V_348 ) {
V_2 -> V_347 &= ~ V_348 ;
F_84 ( V_2 , V_349 , V_2 -> V_23 ,
L_26 ) ;
F_67 ( V_2 , V_119 ) ;
}
if ( ( V_2 -> V_8 -> V_9 & V_294 ) &&
( V_2 -> V_347 & ( V_288 | V_287 ) ) ) {
F_169 ( V_2 -> V_38 ,
V_2 -> V_347 & V_288 ) ;
V_2 -> V_347 &= ~ ( V_288 | V_287 ) ;
}
}
static T_9 F_170 ( int V_350 , void * V_351 )
{
struct V_1 * V_2 = V_351 ;
struct V_133 * V_30 ;
unsigned int V_149 ;
V_2 -> V_352 =
F_171 ( V_2 , V_353 ) &
~ F_171 ( V_2 , V_354 ) ;
F_80 ( V_2 , V_2 -> V_352 , V_276 ) ;
F_84 ( V_2 , V_346 , V_2 -> V_23 ,
L_27 , V_163 , V_2 -> V_352 ) ;
for ( V_149 = 0 ; V_149 < V_2 -> V_8 -> V_179 ; V_149 ++ ) {
if ( ! ( V_2 -> V_352 & F_147 ( V_149 ) ) )
continue;
V_30 = & V_2 -> V_180 [ V_149 ] ;
if ( F_131 ( F_172 ( & V_30 -> V_175 ) ) ) {
V_30 -> V_300 ( V_2 , V_30 ) ;
F_173 ( & V_30 -> V_175 ) ;
}
}
return V_355 ;
}
static T_9 F_174 ( int V_350 , void * V_351 )
{
struct V_1 * V_2 = V_351 ;
V_2 -> V_347 =
F_175 ( V_2 , V_353 ) &
~ F_175 ( V_2 , V_354 ) ;
F_77 ( V_2 , V_2 -> V_347 , V_276 ) ;
F_84 ( V_2 , V_346 , V_2 -> V_23 ,
L_28 , V_2 -> V_347 ) ;
if ( V_2 -> V_347 & ( V_286 | V_356 ) ) {
if ( F_131 ( F_172 ( & V_2 -> V_175 ) ) ) {
F_77 ( V_2 , V_286 ,
V_147 ) ;
F_173 ( & V_2 -> V_175 ) ;
}
}
if ( V_2 -> V_347 &
( V_145 | V_146 ) ) {
struct V_133 * V_30 = & V_2 -> V_180 [ V_181 ] ;
if ( F_131 ( F_172 ( & V_30 -> V_175 ) ) ) {
V_30 -> V_300 ( V_2 , V_30 ) ;
F_173 ( & V_30 -> V_175 ) ;
}
}
if ( V_2 -> V_347 & ( V_357 |
V_358 |
V_288 |
V_287 |
V_359 |
V_360 |
V_348 ) ) {
F_176 ( & V_2 -> V_345 ) ;
}
if ( ( V_2 -> V_8 -> V_9 & V_294 ) &&
V_2 -> V_347 & ( V_295 | V_296 ) ) {
V_2 -> V_347 &= ~ ( V_295 | V_296 ) ;
F_177 ( & V_2 -> V_361 ) ;
}
return V_355 ;
}
static T_9 F_178 ( int V_350 , void * V_351 )
{
struct V_1 * V_2 = V_351 ;
F_179 ( & V_2 -> V_185 -> V_23 , 0 ) ;
return V_355 ;
}
static void F_180 ( struct V_1 * V_2 )
{
T_2 V_98 ;
V_98 = F_11 ( V_2 ) ;
V_98 |= F_147 ( 1 ) ;
F_15 ( V_2 , V_98 ) ;
F_140 ( 10 ) ;
V_98 &= ~ F_147 ( 1 ) ;
F_15 ( V_2 , V_98 ) ;
F_140 ( 10 ) ;
}
static void F_181 ( struct V_1 * V_2 ,
unsigned char * V_6 )
{
F_49 ( V_2 , ( V_6 [ 0 ] << 24 ) | ( V_6 [ 1 ] << 16 ) |
( V_6 [ 2 ] << 8 ) | V_6 [ 3 ] , V_362 ) ;
F_49 ( V_2 , ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] , V_363 ) ;
}
static T_2 F_182 ( struct V_1 * V_2 )
{
T_2 V_98 ;
T_2 V_322 ;
V_322 = 1 << ( V_181 + V_330 ) | V_326 ;
V_98 = F_25 ( V_2 , V_325 ) ;
V_98 &= ~ V_322 ;
F_26 ( V_2 , V_98 , V_325 ) ;
V_98 = F_27 ( V_2 , V_325 ) ;
V_98 &= ~ V_322 ;
F_28 ( V_2 , V_98 , V_325 ) ;
F_49 ( V_2 , 1 , V_364 ) ;
F_140 ( 10 ) ;
F_49 ( V_2 , 0 , V_364 ) ;
return V_322 ;
}
static void F_183 ( struct V_1 * V_2 , T_2 V_322 )
{
T_2 V_98 ;
V_98 = F_27 ( V_2 , V_325 ) ;
V_98 |= V_322 ;
F_28 ( V_2 , V_98 , V_325 ) ;
V_98 = F_25 ( V_2 , V_325 ) ;
V_98 |= V_322 ;
F_26 ( V_2 , V_98 , V_325 ) ;
}
static void F_184 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_152 ( & V_2 -> V_175 ) ;
F_137 ( V_2 , V_365 | V_366 , true ) ;
if ( F_146 ( V_2 -> V_38 ) )
F_67 ( V_2 , V_120 ) ;
F_185 ( V_23 ) ;
F_186 ( V_2 -> V_38 ) ;
}
static int F_187 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_322 ;
T_2 V_98 ;
int V_59 ;
F_84 ( V_2 , V_367 , V_23 , L_29 ) ;
if ( ! F_188 ( V_2 -> V_368 ) )
F_52 ( V_2 -> V_368 ) ;
F_180 ( V_2 ) ;
V_59 = F_143 ( V_2 ) ;
if ( V_59 )
goto V_369;
F_137 ( V_2 , V_365 | V_366 , false ) ;
V_98 = F_48 ( V_2 , V_272 ) ;
V_2 -> V_47 = ! ! ( V_98 & V_370 ) ;
F_181 ( V_2 , V_23 -> V_371 ) ;
if ( F_146 ( V_2 -> V_38 ) ) {
V_98 = F_65 ( V_2 , V_122 ) ;
V_98 |= V_372 ;
F_66 ( V_2 , V_98 , V_122 ) ;
}
V_322 = F_182 ( V_2 ) ;
V_59 = F_166 ( V_2 ) ;
if ( V_59 ) {
F_122 ( V_23 , L_30 ) ;
goto V_373;
}
F_183 ( V_2 , V_322 ) ;
V_59 = F_189 ( V_2 -> V_374 , F_174 , V_375 ,
V_23 -> V_376 , V_2 ) ;
if ( V_59 < 0 ) {
F_122 ( V_23 , L_31 , V_2 -> V_374 ) ;
goto V_373;
}
V_59 = F_189 ( V_2 -> V_377 , F_170 , V_375 ,
V_23 -> V_376 , V_2 ) ;
if ( V_59 < 0 ) {
F_122 ( V_23 , L_31 , V_2 -> V_377 ) ;
goto V_378;
}
F_190 ( V_2 -> V_23 , false ) ;
F_191 ( V_23 , V_2 -> V_38 , V_379 ,
V_2 -> V_290 ) ;
F_184 ( V_23 ) ;
return 0 ;
V_378:
F_192 ( V_2 -> V_374 , V_23 ) ;
V_373:
F_165 ( V_2 ) ;
V_369:
if ( ! F_188 ( V_2 -> V_368 ) )
F_53 ( V_2 -> V_368 ) ;
return V_59 ;
}
static void F_193 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_194 ( V_23 ) ;
F_154 ( & V_2 -> V_175 ) ;
F_195 ( V_2 -> V_38 ) ;
F_142 ( V_2 ) ;
F_196 ( & V_2 -> V_345 ) ;
V_2 -> V_380 = - 1 ;
V_2 -> V_381 = - 1 ;
V_2 -> V_382 = - 1 ;
V_2 -> V_383 = - 1 ;
}
static int F_197 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_59 ;
F_84 ( V_2 , V_384 , V_23 , L_32 ) ;
F_193 ( V_23 ) ;
F_198 ( V_2 -> V_38 ) ;
F_137 ( V_2 , V_366 , false ) ;
V_59 = F_163 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_137 ( V_2 , V_365 , false ) ;
F_98 ( V_23 ) ;
F_165 ( V_2 ) ;
F_192 ( V_2 -> V_374 , V_2 ) ;
F_192 ( V_2 -> V_377 , V_2 ) ;
if ( F_146 ( V_2 -> V_38 ) )
F_62 ( V_2 , V_120 ) ;
if ( ! F_188 ( V_2 -> V_368 ) )
F_53 ( V_2 -> V_368 ) ;
return 0 ;
}
static void F_199 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_84 ( V_2 , V_192 , V_23 , L_33 ) ;
V_23 -> V_385 = V_386 ;
V_23 -> V_94 . V_209 ++ ;
F_200 ( V_23 ) ;
}
static inline void F_201 ( struct V_1 * V_2 ,
unsigned char * V_6 ,
int * V_73 ,
int * V_387 )
{
T_2 V_98 ;
F_49 ( V_2 , V_6 [ 0 ] << 8 | V_6 [ 1 ] ,
V_388 + ( * V_73 * 4 ) ) ;
F_49 ( V_2 , V_6 [ 2 ] << 24 | V_6 [ 3 ] << 16 |
V_6 [ 4 ] << 8 | V_6 [ 5 ] ,
V_388 + ( ( * V_73 + 1 ) * 4 ) ) ;
V_98 = F_48 ( V_2 , V_389 ) ;
V_98 |= ( 1 << ( V_390 - * V_387 ) ) ;
F_49 ( V_2 , V_98 , V_389 ) ;
* V_73 += 2 ;
( * V_387 ) ++ ;
}
static void F_202 ( struct V_34 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
struct V_391 * V_392 ;
int V_73 , V_387 ;
T_2 V_98 ;
F_84 ( V_2 , V_115 , V_23 , L_34 , V_163 , V_23 -> V_9 ) ;
V_98 = F_48 ( V_2 , V_272 ) ;
if ( V_23 -> V_9 & V_393 ) {
V_98 |= V_394 ;
F_49 ( V_2 , V_98 , V_272 ) ;
F_49 ( V_2 , 0 , V_389 ) ;
return;
} else {
V_98 &= ~ V_394 ;
F_49 ( V_2 , V_98 , V_272 ) ;
}
if ( V_23 -> V_9 & V_395 ) {
F_160 ( V_23 , L_35 ) ;
return;
}
V_73 = 0 ;
V_387 = 0 ;
F_201 ( V_2 , V_23 -> V_396 , & V_73 , & V_387 ) ;
F_201 ( V_2 , V_23 -> V_371 , & V_73 , & V_387 ) ;
if ( F_203 ( V_23 ) > ( V_390 - V_387 ) )
return;
if ( ! F_204 ( V_23 ) )
F_205 (ha, dev)
F_201 ( V_2 , V_392 -> V_6 , & V_73 , & V_387 ) ;
if ( F_206 ( V_23 ) || F_207 ( V_23 ) >= ( V_390 - V_387 ) )
return;
F_208 (ha, dev)
F_201 ( V_2 , V_392 -> V_6 , & V_73 , & V_387 ) ;
}
static int F_209 ( struct V_34 * V_23 , void * V_81 )
{
struct V_397 * V_6 = V_81 ;
if ( F_34 ( V_23 ) )
return - V_398 ;
F_210 ( V_23 -> V_371 , V_6 -> V_399 ) ;
return 0 ;
}
static void F_211 ( struct V_1 * V_2 )
{
struct V_400 * V_401 ;
T_2 V_98 ;
T_5 V_402 ;
T_6 V_403 ;
if ( F_212 ( V_2 ) ) {
V_28 = V_404 ;
V_33 = V_405 ;
V_2 -> V_263 = V_406 ;
V_2 -> V_65 = V_407 ;
} else if ( F_213 ( V_2 ) ) {
V_28 = V_404 ;
V_33 = V_408 ;
V_2 -> V_263 = V_406 ;
V_2 -> V_65 = V_409 ;
} else if ( F_145 ( V_2 ) ) {
V_28 = V_410 ;
V_33 = V_408 ;
V_2 -> V_263 = V_411 ;
V_2 -> V_65 = V_412 ;
} else if ( F_12 ( V_2 ) ) {
V_28 = V_413 ;
V_33 = V_408 ;
V_2 -> V_263 = V_411 ;
V_2 -> V_65 = V_414 ;
}
V_2 -> V_8 = & V_400 [ V_2 -> V_65 ] ;
V_401 = V_2 -> V_8 ;
V_98 = F_14 ( V_2 , V_415 ) ;
V_402 = ( V_98 >> 24 & 0x0f ) ;
if ( V_402 == 5 )
V_402 = 4 ;
else if ( V_402 == 0 )
V_402 = 1 ;
if ( V_402 != V_2 -> V_65 ) {
F_141 ( & V_2 -> V_185 -> V_23 ,
L_36 ,
V_402 , V_2 -> V_65 ) ;
}
F_214 ( & V_2 -> V_185 -> V_23 , L_37 V_416 ,
V_402 , ( V_98 >> 16 ) & 0x0f , V_98 & 0xffff ) ;
V_403 = V_98 & 0xffff ;
if ( ( V_403 & 0xf0 ) != 0 )
V_2 -> V_403 = V_403 << 8 ;
else if ( ( V_403 & 0xff00 ) != 0 )
V_2 -> V_403 = V_403 ;
else if ( V_403 == 0 || V_403 == 0x01ff ) {
F_215 ( L_38 , V_403 ) ;
return;
}
#ifdef F_7
if ( ! ( V_401 -> V_9 & V_10 ) )
F_215 ( L_39 ) ;
#endif
F_216 ( L_40
L_41
L_42
L_43
L_44
L_45
L_46 ,
V_2 -> V_65 ,
V_401 -> V_179 , V_401 -> V_417 , V_401 -> V_329 ,
V_401 -> V_292 , V_401 -> V_293 ,
V_401 -> V_418 , V_401 -> V_194 ,
V_401 -> V_18 , V_401 -> V_419 ,
V_401 -> V_420 ,
V_401 -> V_312 , V_401 -> V_341 ,
V_401 -> V_297 ) ;
}
static int F_217 ( struct V_421 * V_185 )
{
struct V_422 * V_423 = V_185 -> V_23 . V_424 ;
struct V_425 * V_426 = V_185 -> V_23 . V_427 ;
const struct V_428 * V_429 = NULL ;
struct V_1 * V_2 ;
struct V_34 * V_23 ;
const void * V_430 ;
struct V_431 * V_25 ;
int V_240 = - V_432 ;
V_23 = F_218 ( sizeof( * V_2 ) , V_433 + 1 , 1 ) ;
if ( ! V_23 ) {
F_141 ( & V_185 -> V_23 , L_47 ) ;
return - V_230 ;
}
if ( V_426 ) {
V_429 = F_219 ( V_434 , V_426 ) ;
if ( ! V_429 )
return - V_37 ;
}
V_2 = F_23 ( V_23 ) ;
V_2 -> V_374 = F_220 ( V_185 , 0 ) ;
V_2 -> V_377 = F_220 ( V_185 , 1 ) ;
V_2 -> V_435 = F_220 ( V_185 , 2 ) ;
if ( ! V_2 -> V_374 || ! V_2 -> V_377 ) {
F_141 ( & V_185 -> V_23 , L_48 ) ;
V_240 = - V_37 ;
goto V_240;
}
if ( V_426 ) {
V_430 = F_221 ( V_426 ) ;
if ( ! V_430 ) {
F_141 ( & V_185 -> V_23 , L_49 ) ;
V_240 = - V_37 ;
goto V_240;
}
} else {
V_430 = V_423 -> V_436 ;
}
V_25 = F_222 ( V_185 , V_437 , 0 ) ;
V_2 -> V_17 = F_223 ( & V_185 -> V_23 , V_25 ) ;
if ( F_188 ( V_2 -> V_17 ) ) {
V_240 = F_224 ( V_2 -> V_17 ) ;
goto V_240;
}
F_225 ( V_23 , & V_185 -> V_23 ) ;
F_226 ( & V_185 -> V_23 , V_23 ) ;
F_210 ( V_23 -> V_371 , V_430 ) ;
V_23 -> V_438 = 2 * V_439 ;
V_23 -> V_440 = & V_441 ;
V_23 -> V_442 = & V_443 ;
F_151 ( V_23 , & V_2 -> V_175 , F_167 , 64 ) ;
V_2 -> V_60 = F_227 ( - 1 , V_444 ) ;
V_23 -> V_445 |= V_446 | V_53 |
V_54 | V_43 ;
V_2 -> V_447 = true ;
V_240 = F_228 ( & V_185 -> V_23 , V_2 -> V_435 , F_178 , 0 ,
V_23 -> V_376 , V_2 ) ;
if ( ! V_240 )
F_229 ( & V_185 -> V_23 , 1 ) ;
V_23 -> V_448 += 64 ;
F_230 ( V_23 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_185 = V_185 ;
if ( V_429 )
V_2 -> V_65 = (enum V_449 ) V_429 -> V_72 ;
else
V_2 -> V_65 = V_423 -> V_450 ;
V_2 -> V_368 = F_231 ( & V_2 -> V_185 -> V_23 , L_50 ) ;
if ( F_188 ( V_2 -> V_368 ) )
F_232 ( & V_2 -> V_185 -> V_23 , L_51 ) ;
if ( ! F_188 ( V_2 -> V_368 ) )
F_52 ( V_2 -> V_368 ) ;
F_211 ( V_2 ) ;
F_233 ( & V_2 -> V_361 ) ;
V_2 -> V_228 = V_305 ;
F_234 ( & V_2 -> V_345 , F_168 ) ;
V_2 -> V_451 = F_231 ( & V_2 -> V_185 -> V_23 , L_52 ) ;
if ( F_188 ( V_2 -> V_451 ) )
F_232 ( & V_2 -> V_185 -> V_23 , L_53 ) ;
V_2 -> V_100 = F_231 ( & V_2 -> V_185 -> V_23 , L_54 ) ;
if ( F_188 ( V_2 -> V_100 ) ) {
F_232 ( & V_2 -> V_185 -> V_23 , L_55 ) ;
V_2 -> V_100 = NULL ;
}
V_240 = F_139 ( V_2 ) ;
if ( V_240 )
goto V_369;
V_240 = F_235 ( V_23 ) ;
if ( V_240 )
goto V_369;
F_236 ( V_2 -> V_23 , V_2 -> V_8 -> V_179 + 1 ) ;
F_237 ( V_2 -> V_23 , V_2 -> V_8 -> V_417 + 1 ) ;
F_238 ( V_23 ) ;
if ( ! F_188 ( V_2 -> V_368 ) )
F_53 ( V_2 -> V_368 ) ;
V_240 = F_239 ( V_23 ) ;
if ( V_240 )
goto V_240;
return V_240 ;
V_369:
if ( ! F_188 ( V_2 -> V_368 ) )
F_53 ( V_2 -> V_368 ) ;
V_240:
F_240 ( V_23 ) ;
return V_240 ;
}
static int F_241 ( struct V_421 * V_185 )
{
struct V_1 * V_2 = F_22 ( & V_185 -> V_23 ) ;
F_226 ( & V_185 -> V_23 , NULL ) ;
F_242 ( V_2 -> V_23 ) ;
F_243 ( V_2 -> V_23 ) ;
F_240 ( V_2 -> V_23 ) ;
return 0 ;
}
static int F_244 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
int V_59 ;
if ( ! F_34 ( V_23 ) )
return 0 ;
F_193 ( V_23 ) ;
F_245 ( V_2 -> V_38 ) ;
F_246 ( V_23 ) ;
F_137 ( V_2 , V_366 , false ) ;
V_59 = F_163 ( V_2 ) ;
if ( V_59 )
return V_59 ;
F_137 ( V_2 , V_365 , false ) ;
F_98 ( V_23 ) ;
F_165 ( V_2 ) ;
if ( F_247 ( V_3 ) && V_2 -> V_452 ) {
F_62 ( V_2 , V_119 ) ;
F_52 ( V_2 -> V_451 ) ;
}
F_53 ( V_2 -> V_368 ) ;
return 0 ;
}
static int F_248 ( struct V_22 * V_3 )
{
struct V_34 * V_23 = F_24 ( V_3 ) ;
struct V_1 * V_2 = F_23 ( V_23 ) ;
unsigned long V_322 ;
int V_59 ;
T_2 V_98 ;
if ( ! F_34 ( V_23 ) )
return 0 ;
V_59 = F_52 ( V_2 -> V_368 ) ;
if ( V_59 )
return V_59 ;
F_180 ( V_2 ) ;
V_59 = F_143 ( V_2 ) ;
if ( V_59 )
goto V_453;
if ( V_2 -> V_452 )
F_53 ( V_2 -> V_451 ) ;
F_249 ( V_2 -> V_38 ) ;
F_190 ( V_2 -> V_23 , false ) ;
F_137 ( V_2 , V_365 | V_366 , false ) ;
F_181 ( V_2 , V_23 -> V_371 ) ;
if ( F_146 ( V_2 -> V_38 ) ) {
V_98 = F_65 ( V_2 , V_122 ) ;
V_98 |= V_372 ;
F_66 ( V_2 , V_98 , V_122 ) ;
}
if ( V_2 -> V_452 )
F_67 ( V_2 , V_119 ) ;
V_322 = F_182 ( V_2 ) ;
V_59 = F_166 ( V_2 ) ;
if ( V_59 ) {
F_122 ( V_23 , L_30 ) ;
goto V_453;
}
F_183 ( V_2 , V_322 ) ;
F_250 ( V_23 ) ;
F_251 ( V_2 -> V_38 ) ;
if ( V_2 -> V_108 . V_109 )
F_51 ( V_23 , true ) ;
F_184 ( V_23 ) ;
return 0 ;
V_453:
F_53 ( V_2 -> V_368 ) ;
return V_59 ;
}
