int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_4 ;
struct V_5 * V_6 ;
T_1 V_7 ;
struct V_8 * V_9 ;
if ( V_3 && F_2 ( V_2 -> V_10 > 12 ) ) {
V_2 -> V_10 -- ;
return 0 ;
}
V_9 = F_3 ( V_11 , 0 ) ;
if ( F_4 ( ! V_9 ) )
return - V_12 ;
V_7 = F_5 ( V_2 -> V_13 , V_9 , 0 ,
V_14 , V_2 -> V_15 ) ;
if ( F_4 ( F_6 ( V_2 -> V_13 , V_7 ) ) ) {
F_7 ( V_9 ) ;
return - V_12 ;
}
V_4 = & V_2 -> V_16 [ V_2 -> V_17 & V_18 ] ;
V_4 -> V_19 = 0 ;
V_4 -> V_9 = V_9 ;
V_4 -> V_7 = V_7 ;
V_6 = (struct V_5 * ) F_8 ( & V_2 -> V_20 ) ;
F_9 ( ! V_6 ) ;
V_6 -> V_21 . V_22 = F_10 ( F_11 ( V_7 ) ) ;
V_6 -> V_21 . V_23 = F_10 ( F_12 ( V_7 ) ) ;
V_2 -> V_17 ++ ;
V_2 -> V_10 ++ ;
return 0 ;
}
int F_13 ( struct V_24 * V_25 , struct V_26 * V_27 , int * V_28 )
{
T_2 V_29 = V_27 -> V_30 & V_31 ;
struct V_32 * V_33 = V_27 -> V_34 . V_35 [ V_29 ] . V_33 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
int V_40 = 0 ;
int V_41 ;
bool V_42 = V_27 -> V_34 . V_35 [ V_29 ] . V_43 & V_44 ;
int V_45 , V_46 = 0 ;
if ( F_4 ( ! V_33 ) ) {
F_14 ( V_25 ,
L_1 ,
V_29 , V_27 -> V_30 , V_27 -> V_47 ) ;
return - 1 ;
}
* V_28 = V_33 -> V_28 ;
V_37 = (struct V_36 * ) F_15 ( & V_27 -> V_48 ) ;
V_40 ++ ;
V_41 = V_37 -> V_9 . V_41 ;
if ( V_42 ) {
struct V_38 * V_49 = (struct V_38 * )
F_15 ( & V_27 -> V_48 ) ;
V_46 = F_16 ( V_49 ) ;
V_40 ++ ;
}
F_17 ( & V_25 -> V_50 -> V_13 , F_18 ( V_37 ) ,
F_16 ( V_37 ) + V_46 , V_51 ) ;
for ( V_45 = 0 ; V_45 < F_19 ( V_33 ) -> V_52 ; V_45 ++ , V_40 ++ ) {
V_39 = (struct V_38 * )
F_15 ( & V_27 -> V_48 ) ;
F_20 ( & V_25 -> V_50 -> V_13 , F_18 ( V_39 ) ,
F_16 ( V_39 ) , V_51 ) ;
}
while ( V_40 ++ < V_41 )
F_15 ( & V_27 -> V_48 ) ;
F_21 ( V_33 ) ;
V_27 -> V_34 . V_35 [ V_29 ] . V_33 = NULL ;
V_27 -> V_34 . V_35 [ V_29 ] . V_43 = 0 ;
return 0 ;
}
static void F_22 ( struct V_26 * V_27 ,
struct V_36 * V_37 ,
int V_53 , bool V_42 )
{
T_2 V_29 = V_27 -> V_47 & V_31 ;
struct V_32 * V_33 = V_27 -> V_34 . V_35 [ V_29 ] . V_33 ;
struct V_38 * V_39 ;
int V_45 , V_46 = 0 ;
F_23 ( & V_27 -> V_48 ,
F_24 ( V_27 -> V_54 . V_9 . V_55 ) , V_37 ) ;
V_37 = (struct V_36 * ) F_8 ( & V_27 -> V_48 ) ;
if ( V_42 ) {
struct V_38 * V_49 = (struct V_38 * )
F_8 ( & V_27 -> V_48 ) ;
V_46 = F_16 ( V_49 ) ;
V_53 -- ;
}
F_17 ( V_27 -> V_13 , F_18 ( V_37 ) ,
F_16 ( V_37 ) + V_46 , V_51 ) ;
for ( V_45 = 0 ; V_45 < V_53 ; V_45 ++ ) {
V_39 = (struct V_38 * )
F_8 ( & V_27 -> V_48 ) ;
if ( V_39 -> V_56 )
F_20 ( V_27 -> V_13 ,
F_18 ( V_39 ) ,
F_16 ( V_39 ) , V_51 ) ;
}
F_23 ( & V_27 -> V_48 ,
F_24 ( V_27 -> V_54 . V_9 . V_55 ) , V_37 ) ;
F_21 ( V_33 ) ;
V_27 -> V_34 . V_35 [ V_29 ] . V_33 = NULL ;
V_27 -> V_34 . V_35 [ V_29 ] . V_43 = 0 ;
}
static T_3 F_25 ( struct V_32 * V_33 , int * V_57 )
{
T_3 V_58 = V_59 ;
T_4 V_60 ;
if ( V_33 -> V_61 != V_62 )
return V_63 ;
V_60 = F_26 ( V_33 ) ;
if ( V_60 == F_27 ( V_64 ) &&
( F_28 ( V_33 ) -> V_65 == V_66 ) )
* V_57 = 1 ;
if ( V_33 -> V_67 ) {
V_58 |= V_68 ;
if ( F_29 ( V_33 ) ) {
unsigned short V_69 = F_19 ( V_33 ) -> V_69 ;
if ( ( V_69 & V_70 ) ||
( V_69 & V_71 ) )
V_58 |= V_72 ;
V_58 |= V_73 ;
return V_58 ;
}
}
if ( F_29 ( V_33 ) )
V_58 |= V_73 ;
return V_58 ;
}
static void F_30 ( struct V_32 * V_33 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
T_5 V_78 ;
T_2 V_79 = 0 , V_80 = 0 ;
V_79 |= ( 1 << V_81 ) ;
V_80 |= ( ( ( ( T_5 * ) F_31 ( V_33 ) - V_33 -> V_9 ) >> 1 ) &
V_82 )
<< V_83 ;
V_79 |= ( V_84 <<
V_85 ) ;
if ( F_26 ( V_33 ) == F_27 ( V_64 ) )
V_78 = F_28 ( V_33 ) -> V_65 ;
else
V_78 = F_32 ( V_33 ) -> V_86 ;
if ( V_78 == V_87 )
V_79 |= 1 << V_88 ;
if ( V_77 )
V_77 -> V_9 . V_89 |=
F_33 ( ( ( F_34 ( V_33 ) / 4 ) &
V_90 ) <<
V_91 ) ;
V_75 -> V_9 . V_92 = F_33 ( V_79 ) ;
V_75 -> V_9 . V_93 = F_33 ( V_80 ) ;
}
static int F_35 ( struct V_26 * V_27 ,
T_6 * V_94 , struct V_38 * V_95 )
{
T_1 V_7 ;
V_7 = F_36 ( V_27 -> V_13 , V_94 , 0 ,
F_37 ( V_94 ) , V_51 ) ;
if ( F_4 ( F_6 ( V_27 -> V_13 , V_7 ) ) )
return - V_12 ;
F_38 ( V_95 , V_7 , F_37 ( V_94 ) ) ;
return 0 ;
}
static T_2 F_39 ( struct V_32 * V_33 , bool V_96 )
{
if ( V_96 )
return ( F_40 ( V_33 ) +
F_41 ( V_33 ) - V_33 -> V_9 ) ;
else
return ( F_31 ( V_33 ) +
F_34 ( V_33 ) - V_33 -> V_9 ) ;
}
static bool F_42 ( struct V_32 * V_33 , T_5 V_97 )
{
int V_98 = V_99 - 1 ;
if ( V_97 & V_73 ) {
int V_100 ;
V_100 = F_39 ( V_33 , V_97 & V_68 ) ;
if ( F_43 ( V_33 ) > V_100 )
V_98 -- ;
}
return ( F_19 ( V_33 ) -> V_52 > V_98 ) ;
}
static inline void F_44 ( struct V_26 * V_27 )
{
F_45 () ;
F_46 () ;
F_47 ( V_27 -> V_54 . V_101 , V_27 -> V_102 ) ;
F_48 () ;
}
static int F_49 ( struct V_24 * V_25 , struct V_103 * V_104 ,
struct V_4 * V_105 , T_2 V_106 , T_2 V_107 )
{
struct V_26 * V_27 = V_104 -> V_108 ;
T_2 V_29 = V_27 -> V_47 & V_31 ;
struct V_36 * V_37 ;
if ( ! F_50 ( & V_27 -> V_48 ) ) {
V_27 -> V_109 ++ ;
return - V_12 ;
}
V_37 = (struct V_36 * ) F_8 ( & V_27 -> V_48 ) ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_9 . V_110 . V_89 =
F_51 ( V_111 ) ;
V_37 -> V_9 . V_89 |=
( V_107 & V_112 ) <<
V_113 ;
V_37 -> V_9 . V_41 = 1 ;
F_38 ( V_37 , V_105 -> V_7 + V_106 , V_107 ) ;
F_52 ( & V_25 -> V_50 -> V_13 ,
V_105 -> V_7 + V_106 ,
V_107 , V_114 ) ;
V_27 -> V_34 . V_115 [ V_29 ] = V_105 -> V_9 ;
V_27 -> V_47 ++ ;
V_104 -> V_116 = 1 ;
return 0 ;
}
int F_53 ( struct V_26 * V_27 )
{
T_2 V_117 ;
F_46 () ;
V_117 = F_24 ( * V_27 -> V_118 ) ;
if ( F_54 ( & V_27 -> V_48 ) == V_117 + 1 )
return 0 ;
return V_117 != F_54 ( & V_27 -> V_48 ) ;
}
static void F_55 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_36 * V_95 ;
T_2 V_117 ;
V_117 = F_24 ( * V_27 -> V_118 ) ;
F_46 () ;
while ( V_117 != F_54 ( & V_27 -> V_48 ) ) {
V_95 = (struct V_36 * ) F_15 ( & V_27 -> V_48 ) ;
F_17 ( & V_25 -> V_50 -> V_13 , F_18 ( V_95 ) ,
V_14 , V_119 ) ;
F_7 ( V_27 -> V_34 . V_115 [ V_27 -> V_30 &
V_31 ] ) ;
V_27 -> V_30 ++ ;
V_27 -> V_120 ++ ;
}
}
static int F_56 ( struct V_24 * V_25 , struct V_26 * V_27 )
{
struct V_121 * V_122 ;
T_2 V_117 ;
unsigned int V_123 = 0 , V_124 = 0 ;
int V_58 ;
V_122 = F_57 ( V_25 -> V_125 , V_27 -> V_126 ) ;
V_117 = F_24 ( * V_27 -> V_118 ) ;
F_46 () ;
while ( V_117 != F_54 ( & V_27 -> V_48 ) ) {
int V_28 = 0 ;
V_58 = F_13 ( V_25 , V_27 , & V_28 ) ;
if ( V_58 ) {
F_58 ( V_25 , L_2 ,
V_117 ,
F_54 ( & V_27 -> V_48 ) ) ;
break;
}
V_124 += V_28 ;
V_123 ++ ;
V_27 -> V_30 ++ ;
V_27 -> V_120 ++ ;
}
F_59 ( V_122 , V_123 , V_124 ) ;
F_60 () ;
if ( F_4 ( F_61 ( V_122 ) ) ) {
F_62 ( V_122 , F_63 () ) ;
if ( ( F_61 ( V_122 ) ) &&
( V_25 -> V_127 == V_128 ) &&
( F_50 ( & V_27 -> V_48 )
>= ( V_129 + 1 ) ) ) {
F_64 ( V_122 ) ;
F_65 ( V_25 , V_130 ,
L_3 ) ;
}
F_66 ( V_122 ) ;
}
return 0 ;
}
bool F_67 ( struct V_1 * V_2 )
{
T_2 V_131 , V_132 ;
F_46 () ;
V_131 = F_24 ( * V_2 -> V_118 ) ;
V_132 = F_54 ( & V_2 -> V_133 ) ;
return V_131 != V_132 ;
}
static inline void F_68 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_20 ) ;
V_2 -> V_134 ++ ;
}
static inline void F_69 ( struct V_1 * V_2 ,
struct V_4 * V_135 )
{
struct V_5 * V_136 = F_8 ( & V_2 -> V_20 ) ;
struct V_4 * V_137 ;
T_1 V_138 ;
V_137 = & V_2 -> V_16 [ V_2 -> V_17 & V_18 ] ;
* V_137 = * V_135 ;
V_138 = V_137 -> V_7 + V_137 -> V_19 ;
V_136 -> V_21 . V_22 = F_10 ( F_11 ( V_138 ) ) ;
V_136 -> V_21 . V_23 = F_10 ( F_12 ( V_138 ) ) ;
V_2 -> V_17 ++ ;
V_135 -> V_9 = NULL ;
}
void F_70 ( struct V_1 * V_2 , T_5 V_139 )
{
struct V_4 * V_135 ;
for (; V_139 > 0 ; V_139 -- ) {
V_135 = & V_2 -> V_16 [ V_2 -> V_134 & V_18 ] ;
F_69 ( V_2 , V_135 ) ;
F_68 ( V_2 ) ;
}
}
static inline int F_71 ( struct V_1 * V_2 ,
struct V_4 * V_135 )
{
V_135 -> V_19 += V_2 -> V_140 ;
if ( V_135 -> V_19 == V_14 ) {
if ( F_4 ( F_1 ( V_2 , true ) ) ) {
V_135 -> V_19 -= V_2 -> V_140 ;
return - V_12 ;
}
F_20 ( V_2 -> V_13 , V_135 -> V_7 ,
V_14 , V_2 -> V_15 ) ;
} else {
F_72 ( V_135 -> V_9 ) ;
F_69 ( V_2 , V_135 ) ;
}
return 0 ;
}
void F_73 ( struct V_24 * V_25 , struct V_1 * V_2 )
{
T_2 V_55 = F_74 ( & V_2 -> V_20 ) ;
T_2 V_141 = F_74 ( & V_2 -> V_133 ) ;
struct V_142 V_143 = { 0 } ;
V_143 . V_55 = F_33 ( V_55 ) ;
V_143 . V_141 = F_33 ( V_141 ) ;
F_45 () ;
F_75 ( V_2 -> V_144 , sizeof( V_143 ) ,
( T_3 * ) & V_143 ) ;
F_48 () ;
}
static void F_76 ( struct V_32 * V_33 , T_5 V_89 , T_7 V_145 )
{
enum V_146 V_147 = V_148 ;
enum V_149 V_150 ;
T_3 V_151 = 0 ;
V_150 = F_77 ( V_89 , V_152 ) ;
if ( V_150 ) {
V_147 = ( ( V_150 == V_153 ) ||
( V_150 == V_154 ) ) ?
V_155 : V_156 ;
V_151 = F_78 ( V_145 ) ;
}
F_79 ( V_33 , V_151 , V_147 ) ;
}
static void F_80 ( struct V_32 * V_33 , T_5 V_157 )
{
F_81 ( V_33 ) ;
if ( V_157 & V_158 )
V_33 -> V_61 = V_159 ;
if ( V_157 & V_160 ) {
V_33 -> V_161 = 1 ;
V_33 -> V_67 = 1 ;
}
}
static inline void F_82 ( struct V_24 * V_25 ,
struct V_103 * V_104 ,
struct V_1 * V_2 ,
struct V_32 * V_33 , T_2 V_162 )
{
if ( V_162 )
F_83 ( V_33 , F_27 ( V_163 ) , V_162 ) ;
F_84 ( & V_104 -> V_164 , V_33 ) ;
V_2 -> V_165 ++ ;
}
static void F_85 ( struct V_24 * V_25 ,
struct V_32 * V_33 ,
struct V_166 * V_167 )
{
T_2 V_168 = F_24 ( V_167 -> V_169 . V_43 ) ;
if ( ( ( V_168 >> V_170 ) &
V_171 ) == 2 )
F_19 ( V_33 ) -> V_69 = V_172 ;
else
F_19 ( V_33 ) -> V_69 = V_173 ;
F_19 ( V_33 ) -> V_174 = F_86 ( V_167 -> V_175 ) -
V_167 -> V_176 ;
}
static int F_87 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
T_5 V_177 , T_2 V_178 )
{
struct V_4 * V_179 = & V_2 -> V_16 [ V_2 -> V_134 &
V_18 ] ;
struct V_180 * V_181 = & V_2 -> V_181 [ V_177 ] ;
struct V_32 * V_33 = V_181 -> V_33 ;
if ( F_4 ( V_181 -> V_127 != V_182 ) )
goto V_183;
F_88 ( V_33 , V_181 -> V_184 ++ ,
V_179 -> V_9 , V_179 -> V_19 ,
V_178 ) ;
if ( F_4 ( F_71 ( V_2 , V_179 ) ) ) {
F_72 ( V_179 -> V_9 ) ;
goto V_183;
}
F_15 ( & V_2 -> V_20 ) ;
V_2 -> V_134 ++ ;
V_33 -> V_185 += V_178 ;
V_33 -> V_186 += V_2 -> V_140 ;
V_33 -> V_28 += V_178 ;
return 0 ;
V_183:
V_181 -> V_127 = V_187 ;
F_70 ( V_2 , 1 ) ;
return - V_12 ;
}
static bool F_89 ( T_2 V_188 )
{
return ! ! ( V_188 & ( V_189 <<
V_190 ) ) ;
}
static T_5 F_90 ( T_2 V_188 )
{
T_2 V_157 = 0 ;
T_5 V_191 = 0 ;
if ( V_188 & ( V_192 <<
V_193 ) )
V_157 |= V_194 <<
V_195 ;
if ( V_188 & ( V_196 <<
V_197 ) ) {
V_157 |= V_198 <<
V_199 ;
V_191 = V_160 ;
}
V_157 |= V_200 <<
V_201 |
V_202 <<
V_203 ;
if ( V_157 & V_188 )
return V_204 ;
return V_158 | V_191 ;
}
static void F_91 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
struct V_166 * V_167 )
{
struct V_180 * V_181 = & V_2 -> V_181 [ V_167 -> V_177 ] ;
struct V_5 * V_205 = F_15 ( & V_2 -> V_20 ) ;
struct V_5 * V_136 = F_8 ( & V_2 -> V_20 ) ;
struct V_4 * V_206 = & V_181 -> V_207 ;
T_1 V_7 = V_181 -> V_208 ;
struct V_4 * V_209 ;
struct V_4 * V_210 ;
V_209 = & V_2 -> V_16 [ V_2 -> V_134 & V_18 ] ;
V_210 = & V_2 -> V_16 [ V_2 -> V_17 & V_18 ] ;
V_210 -> V_7 = V_206 -> V_7 ;
V_210 -> V_9 = V_206 -> V_9 ;
V_136 -> V_21 . V_22 = F_10 ( F_11 ( V_7 ) ) ;
V_136 -> V_21 . V_23 = F_10 ( F_12 ( V_7 ) ) ;
V_210 -> V_19 = V_206 -> V_19 ;
V_2 -> V_17 ++ ;
V_181 -> V_207 = * V_209 ;
V_7 = F_92 ( F_78 ( V_205 -> V_21 . V_22 ) ,
F_78 ( V_205 -> V_21 . V_23 ) ) ;
V_181 -> V_208 = V_7 ;
V_2 -> V_134 ++ ;
V_181 -> V_33 = F_93 ( V_25 -> V_125 ,
F_24 ( V_167 -> V_175 ) ) ;
if ( F_4 ( ! V_181 -> V_33 ) ) {
F_58 ( V_25 , L_4 ) ;
V_181 -> V_127 = V_187 ;
goto V_211;
}
F_94 ( V_181 -> V_33 , F_24 ( V_167 -> V_175 ) ) ;
V_181 -> V_184 = 0 ;
V_181 -> V_127 = V_182 ;
V_181 -> V_212 = V_167 -> V_213 ;
V_181 -> V_214 = F_24 ( V_167 -> V_175 ) ;
if ( ( F_24 ( V_167 -> V_169 . V_43 ) >>
V_215 ) &
V_216 )
V_181 -> V_162 = F_24 ( V_167 -> V_162 ) ;
else
V_181 -> V_162 = 0 ;
F_76 ( V_181 -> V_33 , V_167 -> V_89 , V_167 -> V_145 ) ;
F_85 ( V_25 , V_181 -> V_33 , V_167 ) ;
V_211:
if ( F_2 ( V_167 -> V_217 [ 0 ] ) )
F_87 ( V_25 , V_2 , V_167 -> V_177 ,
F_24 ( V_167 -> V_217 [ 0 ] ) ) ;
if ( F_4 ( V_167 -> V_217 [ 1 ] ) ) {
F_14 ( V_25 ,
L_5 ) ;
V_181 -> V_127 = V_187 ;
}
}
static void F_95 ( struct V_32 * V_33 )
{
const struct V_218 * V_219 = F_32 ( V_33 ) ;
struct V_220 * V_221 ;
F_96 ( V_33 , sizeof( struct V_218 ) ) ;
V_221 = F_97 ( V_33 ) ;
V_221 -> V_222 = ~ F_98 ( V_33 -> V_28 - F_99 ( V_33 ) ,
V_219 -> V_223 , V_219 -> V_224 , 0 ) ;
F_100 ( V_33 ) ;
}
static void F_101 ( struct V_32 * V_33 )
{
struct V_225 * V_219 = F_28 ( V_33 ) ;
struct V_220 * V_221 ;
F_96 ( V_33 , sizeof( struct V_225 ) ) ;
V_221 = F_97 ( V_33 ) ;
V_221 -> V_222 = ~ F_102 ( V_33 -> V_28 - F_99 ( V_33 ) ,
& V_219 -> V_223 , & V_219 -> V_224 , 0 ) ;
F_100 ( V_33 ) ;
}
static void F_103 ( struct V_24 * V_25 ,
struct V_103 * V_104 ,
struct V_32 * V_33 ,
T_2 V_162 )
{
if ( F_4 ( ! V_33 -> V_185 ) ) {
F_19 ( V_33 ) -> V_69 = 0 ;
F_19 ( V_33 ) -> V_174 = 0 ;
goto V_226;
}
#ifdef F_104
if ( F_19 ( V_33 ) -> V_174 ) {
F_105 ( V_33 ) ;
switch ( V_33 -> V_86 ) {
case F_27 ( V_227 ) :
F_95 ( V_33 ) ;
break;
case F_27 ( V_64 ) :
F_101 ( V_33 ) ;
break;
default:
F_14 ( V_25 ,
L_6 ,
F_106 ( V_33 -> V_86 ) ) ;
}
}
#endif
V_226:
F_107 ( V_33 , V_104 -> V_2 -> V_228 ) ;
F_82 ( V_25 , V_104 , V_104 -> V_2 , V_33 , V_162 ) ;
}
static inline void F_108 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
struct V_229 * V_167 )
{
int V_45 ;
for ( V_45 = 0 ; V_167 -> V_230 [ V_45 ] ; V_45 ++ )
F_87 ( V_25 , V_2 , V_167 -> V_177 ,
F_24 ( V_167 -> V_230 [ V_45 ] ) ) ;
if ( F_4 ( V_45 > 1 ) )
F_14 ( V_25 ,
L_7 ) ;
}
static void F_109 ( struct V_24 * V_25 ,
struct V_103 * V_104 ,
struct V_231 * V_167 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_180 * V_181 ;
struct V_32 * V_33 ;
int V_45 ;
V_181 = & V_2 -> V_181 [ V_167 -> V_177 ] ;
V_33 = V_181 -> V_33 ;
for ( V_45 = 0 ; V_167 -> V_230 [ V_45 ] ; V_45 ++ )
F_87 ( V_25 , V_2 , V_167 -> V_177 ,
F_24 ( V_167 -> V_230 [ V_45 ] ) ) ;
if ( F_4 ( V_45 > 1 ) )
F_14 ( V_25 ,
L_8 ) ;
if ( F_4 ( V_181 -> V_127 != V_182 ) )
goto V_232;
if ( F_4 ( V_167 -> V_233 != V_181 -> V_184 + 1 ) )
F_14 ( V_25 ,
L_9 ,
V_167 -> V_233 , V_181 -> V_184 ) ;
if ( F_4 ( V_33 -> V_28 != F_24 ( V_167 -> V_234 ) ) )
F_14 ( V_25 ,
L_10 ,
F_24 ( V_167 -> V_234 ) , V_33 -> V_28 ) ;
memcpy ( V_33 -> V_9 ,
F_110 ( V_181 -> V_207 . V_9 ) +
V_181 -> V_212 +
V_181 -> V_207 . V_19 , V_181 -> V_214 ) ;
V_33 -> V_86 = F_111 ( V_33 , V_25 -> V_125 ) ;
V_33 -> V_61 = V_159 ;
F_112 ( V_33 ) -> V_139 = F_24 ( V_167 -> V_235 ) ;
F_103 ( V_25 , V_104 , V_33 , V_181 -> V_162 ) ;
V_181 -> V_127 = V_236 ;
return;
V_232:
V_181 -> V_127 = V_236 ;
F_21 ( V_181 -> V_33 ) ;
V_181 -> V_33 = NULL ;
}
static T_5 F_113 ( T_2 V_188 )
{
T_2 V_157 = 0 ;
T_5 V_237 = 0 ;
if ( V_188 & ( V_196 <<
V_197 ) ) {
V_157 |= V_198 <<
V_199 ;
V_237 = V_158 ;
}
V_157 |= V_202 <<
V_203 ;
if ( V_157 & V_188 )
return V_204 ;
return V_237 ;
}
static T_5 F_114 ( T_2 V_188 )
{
if ( ! F_89 ( V_188 ) )
return F_113 ( V_188 ) ;
else
return F_90 ( V_188 ) ;
}
static bool F_115 ( struct V_238 * V_167 ,
T_2 V_188 )
{
T_5 V_239 = V_167 -> V_240 . V_43 ;
if ( ( V_239 & ( V_241 <<
V_242 ) ) ||
( V_188 & ( V_243 <<
V_244 ) ) )
return true ;
return false ;
}
static bool F_116 ( struct V_24 * V_25 ,
struct V_103 * V_104 ,
struct V_1 * V_2 ,
struct V_245 * V_246 ,
struct V_4 * V_95 ,
struct V_238 * V_167 )
{
T_2 V_28 = F_24 ( V_167 -> V_175 ) ;
struct V_247 V_248 ;
enum V_249 V_250 ;
V_248 . V_9 = F_110 ( V_95 -> V_9 ) + V_167 -> V_213 ;
V_248 . V_251 = V_248 . V_9 + V_28 ;
F_117 () ;
V_250 = F_118 ( V_246 , & V_248 ) ;
F_119 () ;
if ( V_250 == V_252 )
return true ;
V_2 -> V_253 ++ ;
switch ( V_250 ) {
case V_254 :
if ( F_1 ( V_2 , true ) ) {
F_70 ( V_2 , 1 ) ;
F_120 ( V_25 -> V_125 , V_246 , V_250 ) ;
return false ;
}
if ( F_49 ( V_25 , V_104 , V_95 , V_167 -> V_213 , V_28 ) ) {
F_20 ( V_2 -> V_13 , V_95 -> V_7 ,
V_14 , V_119 ) ;
F_7 ( V_95 -> V_9 ) ;
F_120 ( V_25 -> V_125 , V_246 , V_250 ) ;
}
F_68 ( V_2 ) ;
return false ;
default:
F_121 ( V_250 ) ;
case V_255 :
F_120 ( V_25 -> V_125 , V_246 , V_250 ) ;
case V_256 :
F_70 ( V_2 , V_167 -> V_257 ) ;
}
return false ;
}
static struct V_32 * F_122 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
struct V_4 * V_95 , T_2 V_28 ,
T_2 V_258 )
{
unsigned int V_259 = V_95 -> V_19 ;
struct V_260 * V_94 ;
struct V_8 * V_8 = V_95 -> V_9 ;
unsigned int V_261 ;
struct V_32 * V_33 ;
unsigned char * V_262 ;
V_33 = F_93 ( V_25 -> V_125 , V_263 ) ;
if ( F_4 ( ! V_33 ) )
return NULL ;
if ( V_28 + V_258 <= V_25 -> V_264 ) {
memcpy ( F_94 ( V_33 , V_28 ) ,
F_110 ( V_8 ) + V_258 + V_259 , V_28 ) ;
F_69 ( V_2 , V_95 ) ;
goto V_183;
}
V_94 = & F_19 ( V_33 ) -> V_265 [ 0 ] ;
F_123 ( V_33 , F_19 ( V_33 ) -> V_52 ,
V_8 , V_258 + V_259 , V_28 , V_2 -> V_140 ) ;
V_262 = F_124 ( V_94 ) ;
V_261 = F_125 ( V_262 , V_263 ) ;
memcpy ( V_33 -> V_9 , V_262 , F_126 ( V_261 , sizeof( long ) ) ) ;
F_127 ( V_94 , V_261 ) ;
V_94 -> V_19 += V_261 ;
V_33 -> V_185 -= V_261 ;
V_33 -> V_266 += V_261 ;
if ( F_4 ( F_71 ( V_2 , V_95 ) ) ) {
F_72 ( V_8 ) ;
F_21 ( V_33 ) ;
return NULL ;
}
V_183:
F_68 ( V_2 ) ;
return V_33 ;
}
static int F_128 ( struct V_24 * V_25 ,
struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_238 * V_167 ,
T_2 V_267 )
{
T_2 V_268 = F_24 ( V_167 -> V_268 ) ;
struct V_4 * V_95 ;
T_2 V_269 ;
T_5 V_270 ;
V_268 -= V_267 ;
for ( V_270 = V_167 -> V_257 - 1 ; V_270 > 0 ; V_270 -- ) {
T_2 V_271 = V_268 > V_2 -> V_272 ? V_2 -> V_272 :
V_268 ;
if ( F_4 ( ! V_271 ) ) {
F_14 ( V_25 ,
L_11 ,
V_270 ) ;
goto V_183;
}
if ( F_4 ( F_1 ( V_2 , true ) ) )
goto V_183;
V_269 = V_2 -> V_134 & V_18 ;
V_95 = & V_2 -> V_16 [ V_269 ] ;
F_68 ( V_2 ) ;
F_20 ( V_2 -> V_13 , V_95 -> V_7 ,
V_14 , V_273 ) ;
F_88 ( V_33 , F_19 ( V_33 ) -> V_52 ++ ,
V_95 -> V_9 , 0 , V_271 ) ;
V_33 -> V_186 += V_14 ;
V_33 -> V_185 += V_271 ;
V_33 -> V_28 += V_271 ;
V_268 -= V_271 ;
}
if ( F_4 ( V_268 ) )
F_14 ( V_25 ,
L_12 ,
V_268 ) ;
V_183:
return V_270 ;
}
static int F_129 ( struct V_24 * V_25 ,
struct V_103 * V_104 ,
struct V_1 * V_2 ,
union V_274 * V_167 ,
enum V_275 type )
{
switch ( type ) {
case V_276 :
F_91 ( V_25 , V_2 , & V_167 -> V_277 ) ;
return 0 ;
case V_278 :
F_108 ( V_25 , V_2 , & V_167 -> V_279 ) ;
return 0 ;
case V_280 :
F_109 ( V_25 , V_104 , & V_167 -> V_281 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_130 ( struct V_24 * V_25 ,
struct V_103 * V_104 ,
struct V_1 * V_2 )
{
struct V_245 * V_282 = F_131 ( V_2 -> V_282 ) ;
struct V_238 * V_283 ;
T_2 V_28 , V_258 , V_269 , V_284 ;
enum V_275 V_285 ;
union V_274 * V_167 ;
struct V_4 * V_95 ;
struct V_32 * V_33 ;
T_8 V_43 ;
T_5 V_157 ;
V_167 = (union V_274 * ) F_15 ( & V_2 -> V_133 ) ;
V_285 = V_167 -> V_286 . type ;
if ( F_4 ( V_285 == V_287 ) ) {
struct V_288 * V_289 ;
V_289 = (struct V_288 * ) V_167 ;
V_25 -> V_290 -> V_291 ( V_25 -> V_292 , V_104 -> V_293 , V_289 ) ;
return 0 ;
}
if ( V_285 != V_294 )
return F_129 ( V_25 , V_104 , V_2 , V_167 , V_285 ) ;
V_269 = V_2 -> V_134 & V_18 ;
V_95 = & V_2 -> V_16 [ V_269 ] ;
V_283 = & V_167 -> V_286 ;
V_28 = F_24 ( V_283 -> V_175 ) ;
V_258 = V_283 -> V_213 ;
if ( V_282 )
if ( ! F_116 ( V_25 , V_104 , V_2 , V_282 , V_95 , V_283 ) )
return 1 ;
V_43 = V_167 -> V_286 . V_169 . V_43 ;
V_284 = F_24 ( V_43 ) ;
V_157 = F_114 ( V_284 ) ;
if ( F_4 ( V_157 == V_204 ) ) {
if ( F_115 ( V_283 , V_284 ) ) {
V_2 -> V_295 ++ ;
} else {
F_58 ( V_25 ,
L_13 ,
V_284 ) ;
V_2 -> V_296 ++ ;
F_70 ( V_2 , V_283 -> V_257 ) ;
return 0 ;
}
}
V_33 = F_122 ( V_25 , V_2 , V_95 , V_28 , V_258 ) ;
if ( ! V_33 ) {
V_2 -> V_297 ++ ;
F_70 ( V_2 , V_283 -> V_257 ) ;
return 0 ;
}
if ( V_283 -> V_257 > 1 ) {
T_2 V_298 = F_128 ( V_25 , V_2 , V_33 ,
V_283 , V_28 ) ;
if ( F_4 ( V_298 > 0 ) ) {
F_70 ( V_2 , V_298 ) ;
F_21 ( V_33 ) ;
return 0 ;
}
}
V_33 -> V_86 = F_111 ( V_33 , V_25 -> V_125 ) ;
F_76 ( V_33 , V_283 -> V_89 , V_283 -> V_145 ) ;
F_80 ( V_33 , V_157 ) ;
F_107 ( V_33 , V_2 -> V_228 ) ;
F_132 ( V_25 , V_167 , V_33 ) ;
F_82 ( V_25 , V_104 , V_2 , V_33 , F_24 ( V_283 -> V_162 ) ) ;
return 1 ;
}
static int F_133 ( struct V_103 * V_104 , int V_299 )
{
struct V_1 * V_2 = V_104 -> V_2 ;
struct V_24 * V_25 = V_104 -> V_25 ;
T_2 V_131 , V_132 ;
int V_300 = 0 ;
V_131 = F_24 ( * V_2 -> V_118 ) ;
V_132 = F_54 ( & V_2 -> V_133 ) ;
F_134 () ;
while ( ( V_132 != V_131 ) && ( V_300 < V_299 ) ) {
F_130 ( V_25 , V_104 , V_2 ) ;
F_135 ( & V_2 -> V_133 ) ;
V_132 = F_54 ( & V_2 -> V_133 ) ;
V_300 ++ ;
}
while ( V_2 -> V_301 - V_2 -> V_10 )
if ( F_1 ( V_2 , false ) )
break;
F_73 ( V_25 , V_2 ) ;
return V_300 ;
}
static bool F_136 ( struct V_103 * V_104 )
{
F_137 ( V_104 -> V_302 ) ;
F_134 () ;
if ( F_2 ( V_104 -> type & V_303 ) )
if ( F_67 ( V_104 -> V_2 ) )
return true ;
if ( V_104 -> type & V_304 )
if ( F_53 ( V_104 -> V_108 ) )
return true ;
if ( F_2 ( V_104 -> type & V_305 ) )
if ( F_53 ( V_104 -> V_27 ) )
return true ;
return false ;
}
int F_138 ( struct V_306 * V_164 , int V_299 )
{
struct V_103 * V_104 = F_139 ( V_164 , struct V_103 ,
V_164 ) ;
struct V_24 * V_25 = V_104 -> V_25 ;
int V_307 = 0 ;
if ( F_2 ( V_104 -> type & V_305 ) && F_53 ( V_104 -> V_27 ) )
F_56 ( V_25 , V_104 -> V_27 ) ;
if ( ( V_104 -> type & V_304 ) && F_53 ( V_104 -> V_108 ) )
F_55 ( V_25 , V_104 -> V_108 ) ;
V_307 = ( F_2 ( V_104 -> type & V_303 ) &&
F_67 ( V_104 -> V_2 ) ) ?
F_133 ( V_104 , V_299 ) : 0 ;
if ( V_307 < V_299 ) {
if ( ! F_136 ( V_104 ) ) {
F_140 ( V_164 , V_307 ) ;
F_141 ( V_104 -> V_302 , V_308 , 1 ) ;
} else {
V_307 = V_299 ;
}
}
if ( V_104 -> V_116 ) {
T_2 V_309 = F_74 ( & V_104 -> V_108 -> V_48 ) ;
V_104 -> V_116 = 0 ;
V_104 -> V_108 -> V_54 . V_9 . V_55 = F_33 ( V_309 ) ;
F_44 ( V_104 -> V_108 ) ;
}
return V_307 ;
}
T_9 F_142 ( int V_310 , void * V_311 )
{
struct V_103 * V_104 = V_311 ;
F_141 ( V_104 -> V_302 , V_312 , 0 ) ;
F_143 ( & V_104 -> V_164 ) ;
return V_313 ;
}
T_10 F_144 ( struct V_32 * V_33 , struct V_314 * V_125 )
{
struct V_24 * V_25 = F_145 ( V_125 ) ;
struct V_121 * V_122 ;
struct V_26 * V_27 ;
struct V_36 * V_37 ;
struct V_74 * V_75 = NULL ;
struct V_76 * V_77 = NULL ;
struct V_38 * V_39 = NULL ;
T_2 V_315 ;
T_5 V_53 = 0 ;
T_1 V_7 ;
int V_58 , V_316 = 0 , V_57 = 0 ;
T_5 V_97 ;
T_2 V_29 ;
T_2 V_100 ;
bool V_42 = false ;
V_315 = F_146 ( V_33 ) ;
F_9 ( V_315 >= F_147 ( V_25 ) ) ;
V_27 = V_25 -> V_317 [ V_25 -> V_318 + V_315 ] . V_27 ;
V_122 = F_57 ( V_125 , V_315 ) ;
F_9 ( F_50 ( & V_27 -> V_48 ) < ( V_129 + 1 ) ) ;
V_97 = F_25 ( V_33 , & V_57 ) ;
#if ( ( V_129 + 2 ) > V_99 )
if ( F_42 ( V_33 , V_97 ) ) {
if ( F_148 ( V_33 ) ) {
F_58 ( V_25 ,
L_14 ) ;
F_21 ( V_33 ) ;
return V_319 ;
}
}
#endif
V_29 = V_27 -> V_47 & V_31 ;
V_27 -> V_34 . V_35 [ V_29 ] . V_33 = V_33 ;
V_37 = (struct V_36 * )
F_8 ( & V_27 -> V_48 ) ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_9 . V_110 . V_89 =
1 << V_111 ;
if ( F_4 ( F_19 ( V_33 ) -> V_320 & V_321 ) )
F_149 ( V_25 , V_33 ) ;
V_7 = F_150 ( V_27 -> V_13 , V_33 -> V_9 ,
F_43 ( V_33 ) , V_51 ) ;
if ( F_4 ( F_6 ( V_27 -> V_13 , V_7 ) ) ) {
F_58 ( V_25 , L_15 ) ;
F_22 ( V_27 , V_37 , 0 , false ) ;
F_44 ( V_27 ) ;
return V_319 ;
}
V_53 ++ ;
F_38 ( V_37 , V_7 , F_43 ( V_33 ) ) ;
if ( F_4 ( ( V_97 & V_73 ) | V_57 ) ) {
V_75 = (struct V_74 * )
F_8 ( & V_27 -> V_48 ) ;
memset ( V_75 , 0 , sizeof( * V_75 ) ) ;
V_53 ++ ;
V_77 = (struct V_76 * )
F_8 ( & V_27 -> V_48 ) ;
memset ( V_77 , 0 , sizeof( * V_77 ) ) ;
V_53 ++ ;
V_39 = (struct V_38 * ) V_75 ;
}
if ( F_151 ( V_33 ) ) {
V_37 -> V_9 . V_322 = F_33 ( F_152 ( V_33 ) ) ;
V_37 -> V_9 . V_110 . V_89 |=
1 << V_323 ;
}
if ( V_97 & V_59 ) {
V_37 -> V_9 . V_110 . V_89 |=
1 << V_324 ;
if ( V_97 & V_68 ) {
V_37 -> V_9 . V_110 . V_89 |=
1 << V_325 ;
V_37 -> V_9 . V_89 |=
1 << V_326 ;
}
if ( F_4 ( V_27 -> V_327 ) )
V_37 -> V_9 . V_89 ^=
1 << V_326 ;
if ( F_4 ( V_57 ) )
F_30 ( V_33 , V_75 , V_77 ) ;
}
if ( V_97 & V_73 ) {
V_37 -> V_9 . V_110 . V_89 |=
( 1 << V_328 ) ;
V_77 -> V_9 . V_329 =
F_33 ( F_19 ( V_33 ) -> V_174 ) ;
if ( F_4 ( V_97 & V_68 ) ) {
V_37 -> V_9 . V_110 . V_89 |=
1 << V_330 ;
if ( V_97 & V_72 ) {
T_5 V_331 = V_332 ;
V_37 -> V_9 . V_110 . V_89 |= 1 << V_331 ;
}
V_100 = F_39 ( V_33 , true ) ;
} else {
V_37 -> V_9 . V_110 . V_89 |=
1 << V_325 ;
V_100 = F_39 ( V_33 , false ) ;
}
V_77 -> V_9 . V_89 |=
F_33 ( 1 << V_333 ) ;
if ( F_4 ( F_43 ( V_33 ) > V_100 ) ) {
F_65 ( V_25 , V_334 ,
L_16 ,
V_37 -> V_56 , V_37 -> V_21 . V_22 ,
V_37 -> V_21 . V_23 ) ;
V_7 = F_92 ( F_78 ( V_37 -> V_21 . V_22 ) ,
F_78 ( V_37 -> V_21 . V_23 ) ) +
V_100 ;
F_38 ( V_39 , V_7 ,
F_24 ( V_37 -> V_56 ) -
V_100 ) ;
V_27 -> V_34 . V_35 [ V_29 ] . V_43 |= V_44 ;
V_37 -> V_56 = F_33 ( V_100 ) ;
V_39 = (struct V_38 * ) V_77 ;
V_42 = true ;
}
} else {
V_37 -> V_9 . V_89 |=
( V_33 -> V_28 & V_112 ) <<
V_113 ;
}
while ( V_39 && V_316 < F_19 ( V_33 ) -> V_52 ) {
V_58 = F_35 ( V_27 ,
& F_19 ( V_33 ) -> V_265 [ V_316 ] ,
V_39 ) ;
if ( V_58 ) {
F_22 ( V_27 , V_37 , V_53 , V_42 ) ;
F_44 ( V_27 ) ;
return V_319 ;
}
if ( V_39 == (struct V_38 * ) V_75 )
V_39 = (struct V_38 * ) V_77 ;
else
V_39 = NULL ;
V_316 ++ ;
}
for (; V_316 < F_19 ( V_33 ) -> V_52 ; V_316 ++ , V_53 ++ ) {
V_39 = (struct V_38 * )
F_8 ( & V_27 -> V_48 ) ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
V_58 = F_35 ( V_27 ,
& F_19 ( V_33 ) -> V_265 [ V_316 ] ,
V_39 ) ;
if ( V_58 ) {
F_22 ( V_27 , V_37 , V_53 , V_42 ) ;
F_44 ( V_27 ) ;
return V_319 ;
}
}
V_37 -> V_9 . V_41 = V_53 ;
F_153 ( V_122 , V_33 -> V_28 ) ;
F_154 ( V_33 ) ;
V_27 -> V_47 ++ ;
V_27 -> V_54 . V_9 . V_55 =
F_33 ( F_74 ( & V_27 -> V_48 ) ) ;
if ( ! V_33 -> V_335 || F_155 ( V_122 ) )
F_44 ( V_27 ) ;
if ( F_4 ( F_50 ( & V_27 -> V_48 )
< ( V_129 + 1 ) ) ) {
if ( V_33 -> V_335 )
F_44 ( V_27 ) ;
F_156 ( V_122 ) ;
V_27 -> V_109 ++ ;
F_65 ( V_25 , V_334 ,
L_17 ) ;
F_60 () ;
if ( ( F_50 ( & V_27 -> V_48 ) >=
( V_129 + 1 ) ) &&
( V_25 -> V_127 == V_128 ) ) {
F_64 ( V_122 ) ;
F_65 ( V_25 , V_334 ,
L_3 ) ;
}
}
return V_319 ;
}
T_11 F_157 ( struct V_32 * V_33 ,
struct V_314 * V_13 ,
T_11 V_336 )
{
if ( V_33 -> V_67 ) {
T_5 V_78 = 0 ;
switch ( F_26 ( V_33 ) ) {
case F_27 ( V_227 ) :
V_78 = F_32 ( V_33 ) -> V_86 ;
break;
case F_27 ( V_64 ) :
V_78 = F_28 ( V_33 ) -> V_65 ;
break;
default:
return V_336 ;
}
if ( ( V_78 == V_87 ) &&
( ( F_158 ( V_33 ) -
F_31 ( V_33 ) ) > V_337 ) )
return V_336 & ~ ( V_338 |
V_339 ) ;
}
return V_336 ;
}
