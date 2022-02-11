static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
return F_2 ( V_2 , V_8 -> V_9 ) ;
}
static bool F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
if ( ! V_4 -> V_14 . V_15 )
return false ;
if ( V_4 -> V_16 == V_17 )
return false ;
if ( F_4 ( F_5 ( V_2 ) ) < 2 )
return false ;
if ( ! F_6 ( V_2 , V_4 ) )
return false ;
V_11 = F_7 ( V_4 ) ;
V_13 = F_8 ( V_11 -> V_18 ) ;
if ( V_2 -> V_19 -> V_20 )
return false ;
return true ;
}
static bool F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! V_4 -> V_14 . V_15 )
return false ;
return true ;
}
static bool F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_21 * V_14 = & V_4 -> V_14 ;
struct V_22 * V_23 = & V_4 -> V_23 ;
if ( F_11 ( V_6 ) && ( V_14 -> V_24 &
V_25 ) )
return true ;
if ( F_12 ( V_6 ) && ( V_14 -> V_24 &
V_26 ) )
return true ;
if ( F_13 ( V_6 ) && ( V_23 -> V_24 &
V_27 ) )
return true ;
return false ;
}
static inline T_1 F_14 ( T_2 V_28 )
{
return ( T_1 ) ( V_28 & V_29 ) ;
}
static int F_15 ( T_2 V_28 )
{
int V_30 = 0 ;
if ( V_28 & V_31 ) {
V_30 = V_28 & V_32 ;
V_30 += V_33 ;
if ( V_30 >= V_34 )
V_30 += 1 ;
if ( ( V_30 >= V_35 ) && ( V_30 <= V_36 ) )
return V_30 ;
} else if ( V_28 & V_37 ) {
V_30 = V_28 & V_38 ;
V_30 += V_33 ;
if ( V_30 >= V_34 )
V_30 ++ ;
if ( ( V_30 >= V_39 ) && ( V_30 <= V_40 ) )
return V_30 ;
} else {
T_1 V_41 = F_14 ( V_28 ) ;
for ( V_30 = 0 ; V_30 < F_16 ( V_42 ) ; V_30 ++ )
if ( V_42 [ V_30 ] . V_43 == V_41 )
return V_30 ;
}
return V_44 ;
}
static const char * F_17 ( T_1 V_9 )
{
static const char * const V_45 [] = {
[ V_46 ] = L_1 ,
[ V_47 ] = L_2 ,
[ V_48 ] = L_3 ,
[ V_49 ] = L_4 ,
[ V_50 ] = L_5 ,
[ V_51 ] = L_6 ,
[ V_52 ] = L_7 ,
[ V_53 ] = L_8 ,
} ;
if ( V_9 > V_53 )
return L_9 ;
return V_45 [ V_9 ] ;
}
static const char * F_18 ( enum V_54 type )
{
static const char * const V_55 [] = {
[ V_56 ] = L_10 ,
[ V_57 ] = L_11 ,
[ V_58 ] = L_12 ,
[ V_59 ] = L_13 ,
[ V_60 ] = L_14 ,
[ V_61 ] = L_15 ,
[ V_62 ] = L_16 ,
} ;
if ( type < V_56 || type >= V_63 )
return L_9 ;
return V_55 [ type ] ;
}
static char * F_19 ( const struct V_5 * V_6 )
{
static char V_64 [ 40 ] ;
static const char * const V_65 [] = {
[ V_66 ] = L_17 ,
[ V_67 ] = L_18 ,
[ V_68 ] = L_19 ,
[ V_69 ] = L_20 ,
[ V_70 ] = L_21 ,
[ V_34 ] = L_22 ,
[ V_71 ] = L_23 ,
[ V_72 ] = L_24 ,
[ V_73 ] = L_25 ,
[ V_74 ] = L_26 ,
[ V_75 ] = L_27 ,
[ V_76 ] = L_28 ,
} ;
static const char * const V_77 [] = {
[ V_33 ] = L_29 ,
[ V_78 ] = L_30 ,
[ V_79 ] = L_31 ,
[ V_80 ] = L_32 ,
[ V_81 ] = L_33 ,
[ V_82 ] = L_34 ,
[ V_83 ] = L_35 ,
[ V_84 ] = L_36 ,
[ V_85 ] = L_37 ,
[ V_86 ] = L_38 ,
} ;
const char * V_87 ;
if ( F_20 ( V_6 -> type ) )
V_87 = V_65 [ V_6 -> V_88 ] ;
else if ( F_21 ( V_6 -> type ) || F_22 ( V_6 -> type ) )
V_87 = V_77 [ V_6 -> V_88 ] ;
else
V_87 = L_39 ;
sprintf ( V_64 , L_40 , F_18 ( V_6 -> type ) ,
F_17 ( V_6 -> V_9 ) , V_87 ) ;
return V_64 ;
}
static inline void F_23 ( struct V_1 * V_2 , const struct V_5 * V_6 ,
const char * V_89 )
{
F_24 ( V_2 ,
L_41 ,
V_89 , F_19 ( V_6 ) , V_6 -> V_90 ,
V_6 -> V_91 , V_6 -> V_92 , V_6 -> V_93 ) ;
}
static void F_25 ( struct V_94 * V_95 )
{
V_95 -> V_96 = 0 ;
V_95 -> V_97 = 0 ;
V_95 -> V_98 = V_99 ;
V_95 -> V_100 = 0 ;
V_95 -> V_101 = V_99 ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
int V_104 ;
F_24 ( V_2 , L_42 ) ;
for ( V_104 = 0 ; V_104 < V_105 ; V_104 ++ )
F_25 ( & V_103 -> V_106 [ V_104 ] ) ;
for ( V_104 = 0 ; V_104 < F_16 ( V_103 -> V_107 ) ; V_104 ++ )
F_25 ( & V_103 -> V_107 [ V_104 ] ) ;
}
static inline T_1 F_27 ( T_1 V_108 , T_1 V_109 )
{
return ( V_109 & V_108 ) == V_109 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_110 * V_111 , T_1 V_112 ,
struct V_3 * V_4 )
{
int V_113 = - V_114 ;
F_29 ( V_2 , L_43 ,
V_4 -> V_115 , V_112 ) ;
V_113 = F_30 ( V_4 , V_112 , 5000 ) ;
if ( V_113 == - V_114 ) {
F_31 ( V_2 , L_44 ,
V_112 ) ;
F_32 ( V_4 , V_112 ) ;
}
return V_113 ;
}
static void F_33 ( struct V_1 * V_2 , T_1 V_112 ,
struct V_110 * V_111 ,
struct V_3 * V_4 )
{
if ( V_112 < V_116 )
F_28 ( V_2 , V_111 , V_112 , V_4 ) ;
else
F_31 ( V_2 , L_45 ,
V_112 , V_116 ) ;
}
static inline int F_34 ( T_2 V_28 )
{
return ! ! ( V_28 & V_117 ) +
! ! ( V_28 & V_118 ) +
! ! ( V_28 & V_119 ) ;
}
static T_3 F_35 ( struct V_102 * V_103 , int V_120 )
{
if ( V_103 -> V_121 )
return V_103 -> V_121 [ V_120 ] ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_102 * V_103 ,
int V_122 , int V_123 , int V_124 ,
struct V_94 * V_95 )
{
static const T_4 V_125 = ( ( ( T_4 ) 1 ) << ( V_126 - 1 ) ) ;
T_3 V_127 , V_128 ;
V_128 = F_35 ( V_103 , V_122 ) ;
while ( V_123 > 0 ) {
if ( V_95 -> V_100 >= V_126 ) {
V_95 -> V_100 = V_126 - 1 ;
if ( V_95 -> V_96 & V_125 ) {
V_95 -> V_96 &= ~ V_125 ;
V_95 -> V_97 -- ;
}
}
V_95 -> V_100 ++ ;
V_95 -> V_96 <<= 1 ;
if ( V_124 > 0 ) {
V_95 -> V_97 ++ ;
V_95 -> V_96 |= 0x1 ;
V_124 -- ;
}
V_123 -- ;
}
if ( V_95 -> V_100 > 0 )
V_95 -> V_98 = 128 * ( 100 * V_95 -> V_97 )
/ V_95 -> V_100 ;
else
V_95 -> V_98 = V_99 ;
V_127 = V_95 -> V_100 - V_95 -> V_97 ;
if ( ( V_127 >= V_129 ) ||
( V_95 -> V_97 >= V_130 ) )
V_95 -> V_101 = ( V_95 -> V_98 * V_128 + 64 ) / 128 ;
else
V_95 -> V_101 = V_99 ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_110 * V_131 ,
struct V_102 * V_103 ,
int V_122 , int V_123 , int V_124 ,
T_1 V_132 )
{
struct V_94 * V_95 = NULL ;
int V_113 ;
if ( V_122 < 0 || V_122 >= V_105 )
return - V_133 ;
if ( V_103 -> V_134 != V_135 ) {
struct V_136 * V_137 = & V_131 -> V_137 ;
V_137 -> V_138 [ V_103 -> V_134 ] [ V_122 ] . V_139 += V_123 ;
V_137 -> V_138 [ V_103 -> V_134 ] [ V_122 ] . V_140 += V_124 ;
}
V_95 = & ( V_103 -> V_106 [ V_122 ] ) ;
V_113 = F_36 ( V_2 , V_103 , V_122 , V_123 , V_124 ,
V_95 ) ;
if ( V_113 )
return V_113 ;
if ( F_38 ( V_132 > V_141 ) )
return - V_133 ;
V_95 = & V_103 -> V_107 [ V_132 ] ;
return F_36 ( V_2 , V_103 , V_122 , V_123 , V_124 ,
V_95 ) ;
}
static T_2 F_39 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_2 V_142 = 0 ;
int V_88 = V_6 -> V_88 ;
V_142 |= ( ( V_6 -> V_9 << V_143 ) &
V_144 ) ;
if ( F_40 ( V_6 ) ) {
V_142 |= V_42 [ V_88 ] . V_43 ;
if ( V_88 >= V_145 && V_88 <= V_146 )
V_142 |= V_147 ;
return V_142 ;
}
if ( F_41 ( V_6 ) ) {
if ( V_88 < V_35 || V_88 > V_36 ) {
F_31 ( V_2 , L_46 , V_88 ) ;
V_88 = V_36 ;
}
V_142 |= V_31 ;
if ( F_42 ( V_6 ) )
V_142 |= V_42 [ V_88 ] . V_148 ;
else if ( F_43 ( V_6 ) )
V_142 |= V_42 [ V_88 ] . V_149 ;
else
F_38 ( 1 ) ;
} else if ( F_44 ( V_6 ) ) {
if ( V_88 < V_39 || V_88 > V_40 ) {
F_31 ( V_2 , L_47 , V_88 ) ;
V_88 = V_40 ;
}
V_142 |= V_37 ;
if ( F_45 ( V_6 ) )
V_142 |= V_42 [ V_88 ] . V_150 ;
else if ( F_46 ( V_6 ) )
V_142 |= V_42 [ V_88 ] . V_151 ;
else
F_38 ( 1 ) ;
} else {
F_31 ( V_2 , L_48 , V_6 -> type ) ;
}
if ( F_47 ( V_6 ) && V_6 -> V_93 ) {
V_142 |= V_152 ;
V_142 |= V_153 ;
}
V_142 |= V_6 -> V_90 ;
if ( V_6 -> V_91 )
V_142 |= V_154 ;
if ( V_6 -> V_92 )
V_142 |= V_155 ;
return V_142 ;
}
static int F_48 ( const T_2 V_142 ,
enum V_156 V_157 ,
struct V_5 * V_6 )
{
T_2 V_158 = V_142 & V_144 ;
T_1 F_4 = F_34 ( V_142 ) ;
T_1 V_159 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_88 = F_15 ( V_142 ) ;
if ( V_6 -> V_88 == V_44 )
return - V_133 ;
V_6 -> V_9 = ( V_158 >> V_143 ) ;
if ( ! ( V_142 & V_31 ) &&
! ( V_142 & V_37 ) ) {
if ( F_4 == 1 ) {
if ( V_157 == V_160 )
V_6 -> type = V_57 ;
else
V_6 -> type = V_58 ;
}
return 0 ;
}
if ( V_142 & V_154 )
V_6 -> V_91 = true ;
if ( V_142 & V_155 )
V_6 -> V_92 = true ;
if ( V_142 & V_153 )
V_6 -> V_93 = true ;
if ( V_142 & V_161 )
V_6 -> V_162 = true ;
V_6 -> V_90 = V_142 & V_163 ;
if ( V_142 & V_31 ) {
V_159 = ( ( V_142 & V_164 ) >>
V_165 ) + 1 ;
if ( V_159 == 1 ) {
V_6 -> type = V_59 ;
F_49 ( ! V_6 -> V_93 && ! V_6 -> V_162 && F_4 != 1 ,
L_49 ,
V_6 -> V_93 , V_6 -> V_162 ) ;
} else if ( V_159 == 2 ) {
V_6 -> type = V_60 ;
F_38 ( F_4 != 2 ) ;
} else {
F_38 ( 1 ) ;
}
} else if ( V_142 & V_37 ) {
V_159 = ( ( V_142 & V_166 ) >>
V_167 ) + 1 ;
if ( V_159 == 1 ) {
V_6 -> type = V_61 ;
F_49 ( ! V_6 -> V_93 && ! V_6 -> V_162 && F_4 != 1 ,
L_49 ,
V_6 -> V_93 , V_6 -> V_162 ) ;
} else if ( V_159 == 2 ) {
V_6 -> type = V_62 ;
F_38 ( F_4 != 2 ) ;
} else {
F_38 ( 1 ) ;
}
}
F_38 ( V_6 -> V_90 == V_168 ) ;
F_38 ( V_6 -> V_90 == V_169 &&
! F_44 ( V_6 ) ) ;
return 0 ;
}
static int F_50 ( T_2 V_170 , struct V_5 * V_6 )
{
T_1 V_171 ;
if ( ! V_6 -> V_9 || V_6 -> V_9 > V_53 )
return 0 ;
if ( ! F_27 ( V_170 , V_6 -> V_9 ) )
return 0 ;
V_171 = V_172 [ V_6 -> V_9 ] ;
while ( ( V_171 != V_6 -> V_9 ) &&
! F_27 ( V_170 , V_171 ) )
V_171 = V_172 [ V_171 ] ;
if ( V_171 == V_6 -> V_9 )
return 0 ;
V_6 -> V_9 = V_171 ;
return 1 ;
}
static T_5 F_51 ( struct V_110 * V_131 ,
struct V_5 * V_6 )
{
if ( F_40 ( V_6 ) )
return V_131 -> V_173 ;
else if ( F_47 ( V_6 ) )
return V_131 -> V_174 ;
else if ( F_52 ( V_6 ) )
return V_131 -> V_175 ;
F_38 ( 1 ) ;
return 0 ;
}
static T_5 F_53 ( struct V_1 * V_2 , T_1 V_88 , T_5 V_176 ,
int V_177 )
{
T_1 V_178 = V_44 ;
T_1 V_179 = V_44 ;
if ( F_54 ( V_177 ) || ! F_20 ( V_177 ) ) {
int V_104 ;
T_2 V_125 ;
V_104 = V_88 - 1 ;
for ( V_125 = ( 1 << V_104 ) ; V_104 >= 0 ; V_104 -- , V_125 >>= 1 ) {
if ( V_176 & V_125 ) {
V_179 = V_104 ;
break;
}
}
V_104 = V_88 + 1 ;
for ( V_125 = ( 1 << V_104 ) ; V_104 < V_105 ; V_104 ++ , V_125 <<= 1 ) {
if ( V_176 & V_125 ) {
V_178 = V_104 ;
break;
}
}
return ( V_178 << 8 ) | V_179 ;
}
V_179 = V_88 ;
while ( V_179 != V_44 ) {
V_179 = V_42 [ V_179 ] . V_180 ;
if ( V_179 == V_44 )
break;
if ( V_176 & ( 1 << V_179 ) )
break;
}
V_178 = V_88 ;
while ( V_178 != V_44 ) {
V_178 = V_42 [ V_178 ] . V_181 ;
if ( V_178 == V_44 )
break;
if ( V_176 & ( 1 << V_178 ) )
break;
}
return ( V_178 << 8 ) | V_179 ;
}
static inline bool F_55 ( struct V_110 * V_131 ,
struct V_5 * V_6 )
{
return F_56 ( V_6 -> V_88 ) & F_51 ( V_131 , V_6 ) ;
}
static bool F_57 ( struct V_110 * V_131 ,
struct V_5 * V_6 )
{
T_1 V_179 ;
T_5 V_182 ;
T_5 V_176 ;
struct V_1 * V_2 = V_131 -> V_137 . V_183 ;
V_176 = F_51 ( V_131 , V_6 ) ;
V_182 = F_53 ( V_2 , V_6 -> V_88 , V_176 ,
V_6 -> type ) ;
V_179 = V_182 & 0xff ;
if ( V_179 == V_44 )
return true ;
V_6 -> V_88 = V_179 ;
return false ;
}
static void F_58 ( struct V_110 * V_131 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_131 -> V_137 . V_183 ;
if ( F_40 ( V_6 ) ) {
return;
} else if ( F_47 ( V_6 ) ) {
if ( V_131 -> V_157 == V_160 )
V_6 -> type = V_57 ;
else
V_6 -> type = V_58 ;
V_6 -> V_90 = V_184 ;
F_38 ( V_6 -> V_88 < V_33 ||
V_6 -> V_88 > V_86 ) ;
V_6 -> V_88 = V_185 [ V_6 -> V_88 ] ;
V_6 -> V_92 = false ;
} else {
V_6 -> type = F_46 ( V_6 ) ?
V_61 : V_59 ;
}
if ( F_4 ( V_6 -> V_9 ) > 1 )
V_6 -> V_9 = F_59 ( F_5 ( V_2 ) ) ;
V_6 -> V_91 = false ;
if ( ! F_55 ( V_131 , V_6 ) )
F_57 ( V_131 , V_6 ) ;
}
static inline bool F_60 ( struct V_5 * V_186 ,
struct V_5 * V_187 ,
bool V_188 )
{
bool V_189 = ( V_186 -> V_9 == V_187 -> V_9 ) && ( V_186 -> V_93 == V_187 -> V_93 ) &&
( V_186 -> V_162 == V_187 -> V_162 ) ;
if ( V_188 ) {
if ( V_186 -> V_93 || V_186 -> V_162 ) {
F_49 ( V_186 -> V_9 != V_49 , L_50 ,
V_186 -> V_93 , V_186 -> V_162 , V_186 -> V_9 ) ;
V_189 |= ( V_187 -> V_9 == V_47 || V_187 -> V_9 == V_48 ) ;
} else if ( V_187 -> V_93 || V_187 -> V_162 ) {
F_49 ( V_187 -> V_9 != V_49 , L_50 ,
V_187 -> V_93 , V_187 -> V_162 , V_187 -> V_9 ) ;
V_189 |= ( V_186 -> V_9 == V_47 || V_186 -> V_9 == V_48 ) ;
}
}
return ( V_186 -> type == V_187 -> type ) && ( V_186 -> V_90 == V_187 -> V_90 ) && ( V_186 -> V_91 == V_187 -> V_91 ) &&
( V_186 -> V_92 == V_187 -> V_92 ) && ( V_186 -> V_88 == V_187 -> V_88 ) && V_189 ;
}
static inline bool F_61 ( struct V_5 * V_186 ,
struct V_5 * V_187 )
{
bool V_189 ;
if ( V_186 -> V_93 || V_186 -> V_162 )
V_189 = ( V_187 -> V_9 == V_47 || V_187 -> V_9 == V_48 ) ;
else
V_189 = ( V_186 -> V_9 == V_187 -> V_9 ) ;
return ( V_186 -> type == V_187 -> type ) && ( V_186 -> V_90 == V_187 -> V_90 ) && ( V_186 -> V_91 == V_187 -> V_91 )
&& V_189 ;
}
static inline enum V_190 F_62 ( struct V_5 * V_6 )
{
if ( F_40 ( V_6 ) ) {
if ( V_6 -> V_9 == V_47 )
return V_191 ;
if ( V_6 -> V_9 == V_48 )
return V_192 ;
goto V_193;
}
if ( F_47 ( V_6 ) ) {
if ( V_6 -> V_9 == V_47 || V_6 -> V_93 || V_6 -> V_162 )
return V_6 -> V_91 ? V_194 :
V_195 ;
if ( V_6 -> V_9 == V_48 )
return V_6 -> V_91 ? V_196 :
V_197 ;
goto V_193;
}
if ( F_63 ( V_6 ) )
return V_6 -> V_91 ? V_198 : V_199 ;
V_193:
return V_135 ;
}
static T_1 F_64 ( struct V_200 * V_201 )
{
T_1 V_112 = V_116 ;
if ( F_65 ( V_201 -> V_202 ) ) {
T_1 * V_203 = F_66 ( V_201 ) ;
V_112 = V_203 [ 0 ] & 0xf ;
}
if ( F_67 ( V_112 > V_116 ) )
V_112 = V_116 ;
return V_112 ;
}
void F_68 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_112 , struct V_204 * V_205 )
{
int V_206 ;
int V_207 ;
int V_104 ;
struct V_208 * V_209 ;
T_2 V_210 ;
struct V_5 V_211 , V_212 ;
struct V_102 * V_213 , * V_214 , * V_215 ;
T_1 V_132 = ( V_216 ) V_205 -> V_217 . V_218 [ 0 ] ;
T_2 V_219 = ( V_216 ) V_205 -> V_217 . V_218 [ 1 ] ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_110 * V_131 = & V_11 -> V_131 ;
bool V_188 = F_69 ( & V_2 -> V_220 -> V_221 ,
V_222 ) ;
if ( ! V_131 ) {
F_24 ( V_2 , L_51 ) ;
return;
} else if ( ! V_131 -> V_137 . V_183 ) {
F_24 ( V_2 , L_52 ) ;
return;
}
if ( ( V_205 -> V_223 & V_224 ) &&
! ( V_205 -> V_223 & V_225 ) )
return;
F_48 ( V_219 , V_205 -> V_157 , & V_212 ) ;
#ifdef F_70
if ( V_131 -> V_137 . V_226 ) {
int V_88 = V_212 . V_88 ;
enum V_190 V_134 ;
int V_123 , V_140 ;
V_134 = F_62 ( & V_212 ) ;
if ( F_49 ( V_134 == V_135 ,
L_53 ,
V_219 ) )
return;
if ( V_205 -> V_223 & V_225 ) {
V_123 = V_205 -> V_217 . V_227 ;
V_140 = V_205 -> V_217 . V_228 ;
} else {
V_123 = V_205 -> V_217 . V_229 [ 0 ] . V_230 ;
V_140 = ! ! ( V_205 -> V_223 & V_231 ) ;
}
V_131 -> V_137 . V_138 [ V_134 ] [ V_88 ] . V_139 += V_123 ;
V_131 -> V_137 . V_138 [ V_134 ] [ V_88 ] . V_140 += V_140 ;
F_24 ( V_2 , L_54 ,
V_219 , V_140 , V_123 ) ;
return;
}
#endif
if ( F_71 ( V_232 ,
( unsigned long ) ( V_131 -> V_233 +
( V_234 * V_235 ) ) ) ) {
int V_236 ;
F_24 ( V_2 , L_55 ) ;
for ( V_236 = 0 ; V_236 < V_116 ; V_236 ++ )
F_32 ( V_4 , V_236 ) ;
F_72 ( V_2 , V_4 , V_205 -> V_157 , false ) ;
return;
}
V_131 -> V_233 = V_232 ;
V_209 = & V_131 -> V_237 ;
V_210 = F_73 ( V_209 -> V_238 [ 0 ] ) ;
F_48 ( V_210 , V_205 -> V_157 , & V_211 ) ;
if ( ! F_60 ( & V_212 , & V_211 , V_188 ) ) {
F_24 ( V_2 ,
L_56 ,
V_219 , V_210 ) ;
V_131 -> V_239 ++ ;
if ( V_131 -> V_239 > V_240 ) {
V_131 -> V_239 = 0 ;
F_24 ( V_2 ,
L_57 ,
V_131 -> V_241 ) ;
F_74 ( V_2 , & V_131 -> V_237 , false ) ;
}
return;
} else
V_131 -> V_239 = 0 ;
if ( ! V_131 -> V_242 ) {
V_213 = & ( V_131 -> V_243 [ V_131 -> V_244 ] ) ;
V_214 = & ( V_131 -> V_243 [ 1 - V_131 -> V_244 ] ) ;
} else {
V_213 = & ( V_131 -> V_243 [ 1 - V_131 -> V_244 ] ) ;
V_214 = & ( V_131 -> V_243 [ V_131 -> V_244 ] ) ;
}
if ( F_38 ( ! F_61 ( & V_211 , & V_213 -> V_6 ) ) ) {
F_24 ( V_2 ,
L_58 ) ;
V_215 = & ( V_131 -> V_243 [ V_131 -> V_244 ] ) ;
F_23 ( V_2 , & V_215 -> V_6 , L_59 ) ;
V_215 = & ( V_131 -> V_243 [ 1 - V_131 -> V_244 ] ) ;
F_23 ( V_2 , & V_215 -> V_6 , L_60 ) ;
F_23 ( V_2 , & V_211 , L_61 ) ;
F_75 ( V_131 , true ) ;
goto V_245;
}
if ( V_205 -> V_223 & V_225 ) {
if ( V_205 -> V_217 . V_228 == 0 )
V_205 -> V_217 . V_227 = 1 ;
F_37 ( V_2 , V_131 , V_213 , V_211 . V_88 ,
V_205 -> V_217 . V_227 ,
V_205 -> V_217 . V_228 ,
V_132 ) ;
if ( V_131 -> V_241 == V_246 ) {
V_131 -> V_247 += V_205 -> V_217 . V_228 ;
V_131 -> V_248 += ( V_205 -> V_217 . V_227 -
V_205 -> V_217 . V_228 ) ;
}
} else {
V_207 = V_205 -> V_217 . V_229 [ 0 ] . V_230 - 1 ;
V_207 = F_76 ( V_207 , 15 ) ;
V_206 = ! ! ( V_205 -> V_223 & V_231 ) ;
for ( V_104 = 0 ; V_104 <= V_207 ; ++ V_104 ) {
V_210 = F_73 ( V_209 -> V_238 [ V_104 ] ) ;
F_48 ( V_210 , V_205 -> V_157 ,
& V_211 ) ;
if ( F_61 ( & V_211 , & V_213 -> V_6 ) )
V_215 = V_213 ;
else if ( F_61 ( & V_211 ,
& V_214 -> V_6 ) )
V_215 = V_214 ;
else
continue;
F_37 ( V_2 , V_131 , V_215 , V_211 . V_88 ,
1 , V_104 < V_207 ? 0 : V_206 ,
V_132 ) ;
}
if ( V_131 -> V_241 == V_246 ) {
V_131 -> V_247 += V_206 ;
V_131 -> V_248 += V_207 + ( 1 - V_206 ) ;
}
}
V_131 -> V_249 = V_210 ;
F_24 ( V_2 , L_62 , V_132 ) ;
V_245:
if ( V_4 -> V_250 [ V_205 -> V_157 ] )
F_77 ( V_2 , V_4 , V_131 , V_112 ) ;
}
static void F_78 ( void * V_251 ,
struct V_252 * V_253 ,
struct V_3 * V_4 , void * V_254 ,
struct V_255 * V_256 )
{
struct V_200 * V_201 = (struct V_200 * ) V_256 -> V_96 ;
struct V_257 * V_258 = (struct V_257 * ) V_251 ;
struct V_1 * V_2 = F_79 ( V_258 ) ;
struct V_204 * V_205 = F_80 ( V_256 ) ;
if ( ! F_7 ( V_4 ) -> V_18 )
return;
if ( ! F_81 ( V_201 -> V_202 ) ||
V_205 -> V_223 & V_259 )
return;
F_68 ( V_2 , V_4 , F_64 ( V_201 ) , V_205 ) ;
}
static void F_82 ( struct V_1 * V_2 , T_1 F_40 ,
struct V_110 * V_131 )
{
F_24 ( V_2 , L_63 ) ;
V_131 -> V_241 = V_246 ;
if ( F_40 ) {
V_131 -> V_260 = V_261 ;
V_131 -> V_262 = V_263 ;
V_131 -> V_264 = V_265 ;
} else {
V_131 -> V_260 = V_266 ;
V_131 -> V_262 = V_267 ;
V_131 -> V_264 = V_268 ;
}
V_131 -> V_269 = 0 ;
V_131 -> V_248 = 0 ;
V_131 -> V_247 = 0 ;
V_131 -> V_270 = V_232 ;
V_131 -> V_271 = 0 ;
}
static inline int F_83 ( unsigned long V_176 )
{
if ( V_176 )
return F_84 ( & V_176 , V_272 ) ;
return V_44 ;
}
static int F_85 ( struct V_110 * V_131 ,
const struct V_7 * V_134 )
{
switch ( V_134 -> V_273 ) {
case V_274 :
return V_131 -> V_275 ;
case V_276 :
return V_131 -> V_277 ;
case V_278 :
return V_131 -> V_279 ;
default:
F_38 ( 1 ) ;
}
return V_131 -> V_275 ;
}
static const T_5 * F_86 ( struct V_110 * V_131 ,
const struct V_7 * V_134 ,
T_2 V_90 )
{
const T_5 ( * V_280 ) [ V_105 ] ;
if ( F_38 ( V_134 -> V_273 != V_274 &&
V_134 -> V_273 != V_276 &&
V_134 -> V_273 != V_278 ) )
return V_281 ;
if ( V_134 -> V_273 == V_274 )
return V_281 ;
V_280 = V_282 ;
if ( V_134 -> V_273 == V_276 ) {
switch ( V_90 ) {
case V_184 :
V_280 = V_283 ;
break;
case V_284 :
V_280 = V_285 ;
break;
case V_169 :
V_280 = V_286 ;
break;
default:
F_38 ( 1 ) ;
}
} else if ( V_134 -> V_273 == V_278 ) {
switch ( V_90 ) {
case V_184 :
V_280 = V_282 ;
break;
case V_284 :
V_280 = V_287 ;
break;
case V_169 :
V_280 = V_288 ;
break;
default:
F_38 ( 1 ) ;
}
} else {
F_38 ( 1 ) ;
}
if ( ! V_134 -> V_91 && ! V_131 -> V_289 )
return V_280 [ 0 ] ;
else if ( V_134 -> V_91 && ! V_131 -> V_289 )
return V_280 [ 1 ] ;
else if ( ! V_134 -> V_91 && V_131 -> V_289 )
return V_280 [ 2 ] ;
else
return V_280 [ 3 ] ;
}
static void F_87 ( struct V_110 * V_131 ,
struct V_102 * V_103 )
{
struct V_5 * V_6 = & V_103 -> V_6 ;
const struct V_7 * V_134 = & V_290 [ V_103 -> V_134 ] ;
V_103 -> V_121 = F_86 ( V_131 , V_134 , V_6 -> V_90 ) ;
}
static T_3 F_88 ( struct V_1 * V_2 ,
struct V_110 * V_131 ,
struct V_102 * V_103 ,
unsigned long V_176 , T_6 V_88 )
{
struct V_102 * V_244 =
& ( V_131 -> V_243 [ V_131 -> V_244 ] ) ;
T_3 V_98 = V_244 -> V_106 [ V_88 ] . V_98 ;
T_5 V_291 = V_244 -> V_121 [ V_88 ] ;
const T_5 * V_292 = V_103 -> V_121 ;
T_5 V_182 ;
T_2 V_293 ;
int V_294 ;
if ( V_98 >= F_89 ( V_295 ) ) {
V_293 = 100 * V_291 ;
F_24 ( V_2 ,
L_64 ,
V_98 , V_293 ) ;
} else {
V_293 = V_131 -> V_296 ;
F_24 ( V_2 ,
L_65 ,
V_98 , V_293 ) ;
}
V_294 = F_90 ( & V_176 , V_272 ) ;
while ( V_294 != V_44 ) {
if ( V_293 < ( 100 * V_292 [ V_294 ] ) )
break;
V_182 = F_53 ( V_2 , V_294 , V_176 ,
V_103 -> V_6 . type ) ;
V_294 = ( V_182 >> 8 ) & 0xff ;
}
F_24 ( V_2 , L_66 ,
V_294 , V_293 ,
V_294 != V_44 ?
100 * V_292 [ V_294 ] : V_99 ) ;
return V_294 ;
}
static T_2 F_91 ( struct V_3 * V_4 )
{
if ( V_4 -> V_297 >= V_298 )
return V_169 ;
else if ( V_4 -> V_297 >= V_299 )
return V_284 ;
return V_184 ;
}
static void F_75 ( struct V_110 * V_131 , bool V_300 )
{
struct V_102 * V_103 ;
int V_244 ;
int V_301 = 0 ;
struct V_1 * V_2 ;
V_2 = V_131 -> V_137 . V_183 ;
V_244 = V_131 -> V_244 ;
V_103 = & ( V_131 -> V_243 [ V_244 ] ) ;
if ( V_131 -> V_241 == V_246 ) {
if ( V_131 -> V_270 )
V_301 =
F_71 ( V_232 ,
( unsigned long ) ( V_131 -> V_270 +
( V_302 * V_235 ) ) ) ;
if ( V_300 ||
( V_131 -> V_248 > V_131 -> V_262 ) ||
( V_131 -> V_247 > V_131 -> V_264 ) ||
( ( ! V_131 -> V_242 ) &&
( V_131 -> V_270 ) && ( V_301 ) ) ) {
F_24 ( V_2 ,
L_67 ,
V_131 -> V_248 ,
V_131 -> V_247 ,
V_301 ) ;
V_131 -> V_241 = V_303 ;
F_24 ( V_2 ,
L_68 ) ;
V_131 -> V_248 = 0 ;
V_131 -> V_247 = 0 ;
V_131 -> V_270 = 0 ;
V_131 -> V_271 = F_56 ( V_103 -> V_134 ) ;
} else {
V_131 -> V_269 ++ ;
if ( V_131 -> V_269 >=
V_131 -> V_260 ) {
V_131 -> V_269 = 0 ;
F_24 ( V_2 ,
L_69 ) ;
F_26 ( V_2 , V_103 ) ;
}
}
if ( V_131 -> V_241 == V_303 ) {
F_26 ( V_2 , V_103 ) ;
}
}
}
static void F_92 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
struct V_102 * V_103 )
{
F_93 ( V_2 , V_4 , V_131 , & V_103 -> V_6 ) ;
F_74 ( V_2 , & V_131 -> V_237 , false ) ;
}
static bool F_94 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
struct V_102 * V_103 ,
enum V_304 V_305 )
{
if ( V_4 -> V_297 != V_298 )
return false ;
if ( ! F_45 ( & V_103 -> V_6 ) )
return false ;
if ( ( V_103 -> V_6 . V_90 == V_169 ) &&
( V_103 -> V_6 . V_88 == V_33 ) &&
( V_305 == V_306 ) ) {
V_103 -> V_6 . V_90 = V_184 ;
V_103 -> V_6 . V_88 = V_81 ;
F_24 ( V_2 , L_70 ) ;
goto V_307;
}
if ( ( V_103 -> V_6 . V_90 == V_184 ) &&
( ( ( V_103 -> V_6 . V_88 == V_82 ) &&
( V_305 == V_308 ) ) ||
( ( V_103 -> V_6 . V_88 > V_82 ) &&
( V_305 == V_309 ) ) ) ) {
V_103 -> V_6 . V_90 = V_169 ;
V_103 -> V_6 . V_88 = V_78 ;
F_24 ( V_2 , L_71 ) ;
goto V_307;
}
return false ;
V_307:
F_87 ( V_131 , V_103 ) ;
F_26 ( V_2 , V_103 ) ;
return true ;
}
static enum V_190 F_95 ( struct V_1 * V_2 ,
struct V_110 * V_131 ,
struct V_3 * V_4 ,
struct V_102 * V_103 )
{
int V_104 , V_310 , V_311 ;
enum V_190 V_312 ;
const struct V_7 * V_313 = & V_290 [ V_103 -> V_134 ] ;
const struct V_7 * V_8 ;
T_7 V_314 ;
T_1 V_315 = F_5 ( V_2 ) ;
const T_5 * V_316 ;
T_5 V_128 , V_317 ;
for ( V_104 = 0 ; V_104 < V_318 ; V_104 ++ ) {
V_312 = V_313 -> V_319 [ V_104 ] ;
if ( V_312 == V_135 )
continue;
if ( V_131 -> V_271 & F_56 ( V_312 ) ) {
F_24 ( V_2 , L_72 ,
V_312 ) ;
continue;
}
V_8 = & V_290 [ V_312 ] ;
if ( ! F_27 ( V_315 , V_8 -> V_9 ) ) {
F_24 ( V_2 ,
L_73 ,
V_312 , V_315 , V_8 -> V_9 ) ;
continue;
}
for ( V_310 = 0 ; V_310 < V_320 ; V_310 ++ ) {
V_314 = V_8 -> V_321 [ V_310 ] ;
if ( V_314 && ! V_314 ( V_2 , V_4 , & V_103 -> V_6 ,
V_8 ) )
break;
}
if ( V_310 != V_320 ) {
F_24 ( V_2 ,
L_74 ,
V_312 , V_310 ) ;
continue;
}
V_128 = V_131 -> V_296 / 100 ;
V_316 = F_86 ( V_131 , V_8 ,
F_91 ( V_4 ) ) ;
if ( F_38 ( ! V_316 ) )
continue;
V_311 = F_85 ( V_131 , V_8 ) ;
if ( V_311 == V_44 ) {
F_24 ( V_2 ,
L_75 ,
V_312 ) ;
continue;
}
V_317 = V_316 [ V_311 ] ;
if ( V_128 >= V_317 ) {
F_24 ( V_2 ,
L_76 ,
V_312 , V_317 , V_128 ) ;
continue;
}
F_24 ( V_2 ,
L_77 ,
V_312 , V_317 , V_128 ) ;
break;
}
if ( V_104 == V_318 )
return V_135 ;
return V_312 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_110 * V_131 ,
struct V_3 * V_4 ,
enum V_190 V_322 )
{
struct V_102 * V_103 = & ( V_131 -> V_243 [ V_131 -> V_244 ] ) ;
struct V_102 * V_323 =
& ( V_131 -> V_243 [ ( 1 - V_131 -> V_244 ) ] ) ;
struct V_5 * V_6 = & V_323 -> V_6 ;
const struct V_7 * V_134 = & V_290 [ V_322 ] ;
const struct V_7 * V_324 = & V_290 [ V_103 -> V_134 ] ;
T_2 V_325 = ( sizeof( struct V_102 ) -
( sizeof( struct V_94 ) * V_105 ) ) ;
unsigned long V_176 = 0 ;
T_2 V_294 = 0 ;
memcpy ( V_323 , V_103 , V_325 ) ;
V_6 -> V_91 = V_134 -> V_91 ;
V_6 -> V_9 = V_134 -> V_9 ;
if ( V_134 -> V_273 == V_274 ) {
if ( V_131 -> V_157 == V_160 )
V_6 -> type = V_57 ;
else
V_6 -> type = V_58 ;
V_6 -> V_90 = V_184 ;
V_6 -> V_92 = false ;
V_176 = V_131 -> V_173 ;
} else if ( V_134 -> V_273 == V_276 ) {
V_6 -> type = V_131 -> F_44 ? V_61 : V_59 ;
V_176 = V_131 -> V_174 ;
} else if ( V_134 -> V_273 == V_278 ) {
V_6 -> type = V_131 -> F_44 ? V_62 : V_60 ;
V_176 = V_131 -> V_175 ;
} else {
F_38 ( L_78 ) ;
}
if ( V_134 -> V_273 != V_274 ) {
V_6 -> V_90 = F_91 ( V_4 ) ;
V_6 -> V_92 = V_131 -> V_92 ;
}
V_323 -> V_134 = V_322 ;
F_87 ( V_131 , V_323 ) ;
V_131 -> V_271 |= F_56 ( V_322 ) ;
if ( V_324 -> V_273 != V_134 -> V_273 ) {
V_294 = F_88 ( V_2 , V_131 , V_323 ,
V_176 , V_6 -> V_88 ) ;
if ( ( V_294 == V_44 ) ||
! ( F_56 ( V_294 ) & V_176 ) ) {
F_24 ( V_2 ,
L_79
L_80 ,
V_294 , V_176 ) ;
goto V_193;
}
V_6 -> V_88 = V_294 ;
}
F_24 ( V_2 , L_81 ,
V_322 , V_6 -> V_88 ) ;
return 0 ;
V_193:
V_6 -> type = V_56 ;
return - 1 ;
}
static enum V_304 F_97 ( struct V_1 * V_2 ,
struct V_102 * V_103 ,
T_3 V_326 , int V_179 , int V_178 ,
int V_327 ,
int V_328 , int V_329 )
{
enum V_304 V_330 = V_308 ;
if ( ( V_326 <= F_89 ( V_331 ) ) ||
( V_327 == 0 ) ) {
F_24 ( V_2 ,
L_82 ) ;
return V_306 ;
}
if ( ( V_328 == V_99 ) &&
( V_329 == V_99 ) &&
( V_178 != V_44 ) ) {
F_24 ( V_2 ,
L_83 ) ;
return V_309 ;
}
if ( ( V_329 == V_99 ) &&
( V_178 != V_44 ) &&
( V_328 != V_99 ) &&
( V_328 < V_327 ) ) {
F_24 ( V_2 ,
L_84 ) ;
return V_309 ;
}
if ( ( V_329 != V_99 ) &&
( V_329 > V_327 ) ) {
F_24 ( V_2 ,
L_85 ) ;
return V_309 ;
}
if ( ( V_328 != V_99 ) &&
( V_329 != V_99 ) &&
( V_328 < V_327 ) &&
( V_329 < V_327 ) ) {
F_24 ( V_2 ,
L_86 ) ;
return V_308 ;
}
if ( ( V_328 != V_99 ) &&
( V_328 > V_327 ) ) {
F_24 ( V_2 ,
L_87 ) ;
V_330 = V_306 ;
goto V_332;
}
if ( ( V_328 == V_99 ) &&
( V_179 != V_44 ) ) {
F_24 ( V_2 ,
L_88 ) ;
V_330 = V_306 ;
goto V_332;
}
F_24 ( V_2 , L_89 ) ;
V_332:
if ( ( V_330 == V_306 ) && ( V_179 != V_44 ) ) {
if ( V_326 >= F_89 ( V_295 ) ) {
F_24 ( V_2 ,
L_90 ) ;
V_330 = V_308 ;
} else if ( V_327 > ( 100 * V_103 -> V_121 [ V_179 ] ) ) {
F_24 ( V_2 ,
L_91 ) ;
V_330 = V_308 ;
} else {
F_24 ( V_2 , L_92 ) ;
}
}
return V_330 ;
}
static bool F_98 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_110 * V_131 )
{
if ( ! V_131 -> V_333 )
return false ;
if ( ! F_6 ( V_2 , V_4 ) )
return false ;
return true ;
}
static void F_99 ( struct V_1 * V_2 , int V_88 ,
int * V_334 , int * V_335 )
{
* V_334 = V_88 + V_336 ;
if ( * V_334 > V_141 )
* V_334 = V_337 ;
* V_335 = V_88 - V_336 ;
if ( * V_335 < 0 )
* V_335 = V_337 ;
}
static bool F_100 ( struct V_1 * V_2 , struct V_338 * V_18 ,
struct V_5 * V_6 , enum V_156 V_157 )
{
int V_88 = V_6 -> V_88 ;
bool V_339 = ( V_340 . V_341 == V_342 ) ;
bool V_343 = ( V_18 -> type == V_344 &&
! V_18 -> V_345 . V_346 ) ;
F_24 ( V_2 , L_93 ,
V_339 , V_343 ) ;
if ( ( V_339 || V_343 ) &&
! F_101 ( V_2 , V_157 ) )
return false ;
F_24 ( V_2 , L_94 , V_6 -> type ) ;
if ( F_40 ( V_6 ) )
return V_88 == V_76 ;
if ( F_41 ( V_6 ) )
return V_88 == V_84 ;
if ( F_44 ( V_6 ) )
return V_88 == V_84 ||
V_88 == V_85 ||
V_88 == V_86 ;
F_38 ( 1 ) ;
return false ;
}
static enum V_347 F_102 ( struct V_1 * V_2 ,
T_3 V_326 , int V_348 , int V_349 ,
int V_327 ,
int V_350 , int V_351 )
{
if ( V_327 == V_99 ) {
F_24 ( V_2 , L_95 ) ;
return V_352 ;
}
if ( V_326 <= F_89 ( V_353 ) ||
V_327 == 0 ) {
F_24 ( V_2 , L_96 ) ;
return V_354 ;
}
if ( V_348 != V_337 ) {
if ( V_350 == V_99 &&
( V_351 == V_99 ||
V_327 >= V_351 ) ) {
F_24 ( V_2 ,
L_97 ) ;
return V_355 ;
}
if ( V_350 > V_327 ) {
F_24 ( V_2 ,
L_98 ) ;
return V_355 ;
}
}
if ( V_326 < F_89 ( V_356 ) &&
V_349 != V_337 ) {
if ( V_350 == V_99 &&
V_351 != V_99 &&
V_327 < V_351 ) {
F_24 ( V_2 ,
L_99 ) ;
return V_357 ;
}
if ( V_350 < V_327 &&
( V_351 == V_99 ||
V_351 > V_327 ) ) {
F_24 ( V_2 ,
L_100 ) ;
return V_357 ;
}
}
F_24 ( V_2 , L_101 ) ;
return V_352 ;
}
static bool F_103 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
struct V_102 * V_103 )
{
struct V_10 * V_358 = F_7 ( V_4 ) ;
struct V_338 * V_18 = V_358 -> V_18 ;
struct V_359 * V_360 ;
enum V_156 V_157 ;
struct V_94 * V_95 ;
struct V_5 * V_6 = & V_103 -> V_6 ;
enum V_347 V_330 ;
T_3 V_326 ;
T_1 V_361 = V_131 -> V_237 . V_362 ;
int V_327 ;
int V_348 , V_349 ;
int V_350 = V_99 , V_351 = V_99 ;
#ifdef F_70
if ( V_131 -> V_137 . V_363 <= V_141 ) {
F_24 ( V_2 , L_102 ,
V_131 -> V_137 . V_363 ) ;
V_131 -> V_237 . V_362 = V_131 -> V_137 . V_363 ;
return V_361 != V_131 -> V_137 . V_363 ;
}
#endif
F_104 () ;
V_360 = F_105 ( V_18 -> V_360 ) ;
if ( F_106 ( ! V_360 ) )
V_157 = V_364 ;
else
V_157 = V_360 -> V_365 . V_366 -> V_157 ;
F_107 () ;
if ( ! F_100 ( V_2 , V_18 , V_6 , V_157 ) ) {
F_24 ( V_2 ,
L_103 ) ;
V_131 -> V_237 . V_362 = V_367 ;
return V_361 != V_367 ;
}
F_99 ( V_2 , V_361 , & V_348 , & V_349 ) ;
V_95 = V_103 -> V_107 ;
V_326 = V_95 [ V_361 ] . V_98 ;
V_327 = V_95 [ V_361 ] . V_101 ;
if ( V_348 != V_337 )
V_350 = V_95 [ V_348 ] . V_101 ;
if ( V_349 != V_337 )
V_351 = V_95 [ V_349 ] . V_101 ;
F_24 ( V_2 ,
L_104 ,
V_361 , V_327 , V_326 , V_348 , V_349 ,
V_350 , V_351 ) ;
V_330 = F_102 ( V_2 , V_326 , V_348 , V_349 ,
V_327 , V_350 , V_351 ) ;
if ( V_348 == V_337 && V_330 == V_355 ) {
F_24 ( V_2 , L_105 ) ;
V_330 = V_352 ;
} else if ( V_349 == V_337 &&
( V_330 == V_357 ||
V_330 == V_354 ) ) {
F_24 ( V_2 , L_106 ) ;
V_330 = V_352 ;
}
switch ( V_330 ) {
case V_355 :
V_131 -> V_237 . V_362 = V_348 ;
return true ;
case V_357 :
V_131 -> V_237 . V_362 = V_349 ;
return true ;
case V_354 :
V_131 -> V_237 . V_362 = V_367 ;
return true ;
case V_352 :
break;
}
return false ;
}
static void F_77 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
int V_112 )
{
int V_179 = V_44 ;
int V_178 = V_44 ;
int V_88 ;
struct V_94 * V_95 = NULL ;
int V_327 = V_99 ;
int V_328 = V_99 ;
int V_329 = V_99 ;
T_2 V_127 ;
enum V_304 V_305 = V_308 ;
T_5 V_176 ;
T_1 V_368 = 0 ;
struct V_102 * V_103 , * V_369 ;
T_1 V_244 = 0 ;
T_1 V_370 = 0 ;
T_5 V_182 ;
T_3 V_326 ;
T_1 V_371 = V_131 -> V_289 ;
struct V_10 * V_372 = F_7 ( V_4 ) ;
struct V_373 * V_374 ;
struct V_5 * V_6 ;
V_131 -> V_289 = ! ! V_372 -> V_375 ;
if ( ! V_131 -> V_242 )
V_244 = V_131 -> V_244 ;
else
V_244 = 1 - V_131 -> V_244 ;
V_103 = & ( V_131 -> V_243 [ V_244 ] ) ;
V_6 = & V_103 -> V_6 ;
if ( V_371 != V_131 -> V_289 ) {
F_24 ( V_2 ,
L_107 ,
V_371 , V_131 -> V_289 ) ;
F_87 ( V_131 , V_103 ) ;
F_26 ( V_2 , V_103 ) ;
}
V_88 = V_6 -> V_88 ;
V_176 = F_51 ( V_131 , V_6 ) ;
if ( ! ( F_56 ( V_88 ) & V_176 ) ) {
F_31 ( V_2 , L_108 ) ;
if ( V_131 -> V_242 ) {
V_6 -> type = V_56 ;
V_131 -> V_242 = 0 ;
V_103 = & ( V_131 -> V_243 [ V_131 -> V_244 ] ) ;
F_92 ( V_2 , V_4 , V_131 , V_103 ) ;
}
return;
}
if ( ! V_103 -> V_121 ) {
F_31 ( V_2 , L_109 ) ;
return;
}
V_95 = & ( V_103 -> V_106 [ V_88 ] ) ;
V_127 = V_95 -> V_100 - V_95 -> V_97 ;
if ( ( V_127 < V_129 ) &&
( V_95 -> V_97 < V_130 ) ) {
F_24 ( V_2 ,
L_110 ,
F_19 ( V_6 ) ,
V_95 -> V_97 , V_95 -> V_100 ) ;
V_95 -> V_101 = V_99 ;
F_75 ( V_131 , false ) ;
return;
}
if ( V_131 -> V_242 ) {
if ( V_95 -> V_101 > V_131 -> V_296 ) {
F_24 ( V_2 ,
L_111
L_112 ,
V_95 -> V_98 ,
V_95 -> V_101 ,
V_131 -> V_296 ) ;
V_131 -> V_244 = V_244 ;
V_327 = V_95 -> V_101 ;
} else {
F_24 ( V_2 ,
L_113
L_112 ,
V_95 -> V_98 ,
V_95 -> V_101 ,
V_131 -> V_296 ) ;
V_6 -> type = V_56 ;
V_244 = V_131 -> V_244 ;
V_103 = & ( V_131 -> V_243 [ V_244 ] ) ;
V_88 = V_103 -> V_6 . V_88 ;
V_327 = V_131 -> V_296 ;
V_368 = 1 ;
}
V_131 -> V_242 = 0 ;
V_370 = 1 ;
goto V_376;
}
V_182 = F_53 ( V_2 , V_88 , V_176 , V_6 -> type ) ;
V_179 = V_182 & 0xff ;
V_178 = ( V_182 >> 8 ) & 0xff ;
V_326 = V_95 -> V_98 ;
V_327 = V_95 -> V_101 ;
if ( V_179 != V_44 )
V_328 = V_103 -> V_106 [ V_179 ] . V_101 ;
if ( V_178 != V_44 )
V_329 = V_103 -> V_106 [ V_178 ] . V_101 ;
F_24 ( V_2 ,
L_114 ,
F_19 ( V_6 ) , V_327 , V_326 ,
V_179 , V_178 , V_328 , V_329 ) ;
V_305 = F_97 ( V_2 , V_103 , V_326 , V_179 , V_178 ,
V_327 , V_328 , V_329 ) ;
if ( F_63 ( V_6 ) &&
! F_6 ( V_2 , V_4 ) ) {
F_24 ( V_2 ,
L_115 ) ;
F_75 ( V_131 , true ) ;
goto V_376;
}
switch ( V_305 ) {
case V_306 :
if ( V_179 != V_44 ) {
V_368 = 1 ;
V_88 = V_179 ;
} else {
F_24 ( V_2 ,
L_116 ) ;
}
break;
case V_309 :
if ( V_178 != V_44 ) {
V_368 = 1 ;
V_88 = V_178 ;
} else {
F_24 ( V_2 ,
L_117 ) ;
}
break;
case V_308 :
if ( V_131 -> V_241 == V_246 )
V_368 = F_103 ( V_2 , V_4 , V_131 , V_103 ) ;
break;
default:
break;
}
V_376:
if ( V_368 ) {
V_103 -> V_6 . V_88 = V_88 ;
if ( V_377 )
F_94 ( V_2 , V_4 , V_131 , V_103 , V_305 ) ;
F_92 ( V_2 , V_4 , V_131 , V_103 ) ;
}
F_75 ( V_131 , false ) ;
if ( ! V_368 && ! V_370 &&
V_131 -> V_241 == V_303
&& V_95 -> V_100 ) {
enum V_190 V_378 ;
V_131 -> V_296 = V_327 ;
F_24 ( V_2 ,
L_118 ,
V_368 , V_370 , V_131 -> V_241 ,
V_95 -> V_100 ) ;
V_378 = F_95 ( V_2 , V_131 , V_4 , V_103 ) ;
if ( V_378 != V_135 ) {
int V_113 = F_96 ( V_2 , V_131 , V_4 ,
V_378 ) ;
if ( ! V_113 )
V_131 -> V_242 = 1 ;
} else {
F_24 ( V_2 ,
L_119 ) ;
V_131 -> V_241 = V_379 ;
}
if ( V_131 -> V_242 ) {
V_103 = & ( V_131 -> V_243 [ ( 1 - V_131 -> V_244 ) ] ) ;
F_26 ( V_2 , V_103 ) ;
V_88 = V_103 -> V_6 . V_88 ;
F_23 ( V_2 , & V_103 -> V_6 ,
L_120 ) ;
F_92 ( V_2 , V_4 , V_131 , V_103 ) ;
} else {
V_370 = 1 ;
}
}
if ( V_370 && V_131 -> V_241 == V_379 ) {
V_369 = & ( V_131 -> V_243 [ V_131 -> V_244 ] ) ;
if ( F_40 ( & V_369 -> V_6 ) ) {
F_24 ( V_2 , L_121 ) ;
if ( V_112 != V_116 ) {
V_374 = & V_372 -> V_374 [ V_112 ] ;
if ( V_374 -> V_380 != V_381 ) {
F_24 ( V_2 ,
L_122 ,
V_112 ) ;
F_32 ( V_4 , V_112 ) ;
}
}
F_82 ( V_2 , 1 , V_131 ) ;
} else {
if ( ( V_131 -> V_296 > V_382 ) &&
( V_131 -> V_383 & ( 1 << V_112 ) ) &&
( V_112 != V_116 ) ) {
V_374 = & V_372 -> V_374 [ V_112 ] ;
if ( V_374 -> V_380 == V_381 ) {
F_24 ( V_2 ,
L_123 ,
V_112 ) ;
F_33 ( V_2 , V_112 ,
V_131 , V_4 ) ;
}
}
F_82 ( V_2 , 0 , V_131 ) ;
}
}
}
static void F_108 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 )
{
struct V_5 * V_6 = & V_131 -> V_384 ;
if ( V_131 -> V_279 != V_44 )
V_6 -> type = V_131 -> F_44 ? V_62 : V_60 ;
else if ( V_131 -> V_277 != V_44 )
V_6 -> type = V_131 -> F_44 ? V_61 : V_59 ;
else if ( V_131 -> V_157 == V_160 )
V_6 -> type = V_57 ;
else
V_6 -> type = V_58 ;
V_6 -> V_90 = F_91 ( V_4 ) ;
V_6 -> V_91 = F_10 ( V_2 , V_4 , V_6 , NULL ) ;
if ( F_63 ( V_6 ) ) {
V_131 -> V_385 = V_131 -> V_175 ;
} else if ( F_47 ( V_6 ) ) {
V_131 -> V_385 = V_131 -> V_174 ;
} else {
V_131 -> V_385 = V_131 -> V_173 ;
if ( V_131 -> V_157 == V_160 ) {
V_131 -> V_386 = V_387 ;
V_131 -> V_388 =
F_16 ( V_387 ) ;
} else {
V_131 -> V_386 = V_389 ;
V_131 -> V_388 =
F_16 ( V_389 ) ;
}
}
if ( F_44 ( V_6 ) ) {
if ( V_6 -> V_90 == V_184 ) {
V_131 -> V_386 = V_390 ;
V_131 -> V_388 =
F_16 ( V_390 ) ;
} else {
V_131 -> V_386 = V_391 ;
V_131 -> V_388 =
F_16 ( V_391 ) ;
}
} else if ( F_41 ( V_6 ) ) {
V_131 -> V_386 = V_392 ;
V_131 -> V_388 = F_16 ( V_392 ) ;
}
}
static struct V_5 * F_109 ( struct V_1 * V_2 ,
struct V_110 * V_131 )
{
struct V_5 * V_6 = & V_131 -> V_384 ;
int V_104 ;
V_6 -> V_88 = F_90 ( & V_131 -> V_385 ,
V_272 ) ;
for ( V_104 = 0 ; V_104 < V_131 -> V_388 ; V_104 ++ ) {
int V_294 = V_131 -> V_386 [ V_104 ] . V_294 ;
if ( ( V_131 -> V_137 . V_393 >= V_131 -> V_386 [ V_104 ] . V_394 ) &&
( F_56 ( V_294 ) & V_131 -> V_385 ) ) {
V_6 -> V_88 = V_294 ;
break;
}
}
return V_6 ;
}
static void F_110 ( struct V_1 * V_2 ,
struct V_110 * V_131 ,
enum V_156 V_157 ,
struct V_5 * V_6 )
{
int V_104 , V_395 ;
T_6 V_396 = V_397 ;
T_1 V_398 = V_46 ;
T_1 V_399 = F_5 ( V_2 ) ;
const struct V_400 * V_401 ;
for ( V_104 = 0 ; V_104 < F_16 ( V_131 -> V_137 . V_402 ) ; V_104 ++ ) {
if ( ! ( V_131 -> V_137 . V_403 & F_56 ( V_104 ) ) )
continue;
if ( V_131 -> V_137 . V_402 [ V_104 ] > V_396 ) {
V_396 = V_131 -> V_137 . V_402 [ V_104 ] ;
V_398 = F_56 ( V_104 ) ;
}
}
F_24 ( V_2 , L_124 ,
F_17 ( V_398 ) , V_396 ) ;
if ( V_398 != V_47 && V_398 != V_48 )
V_6 -> V_9 = F_59 ( V_399 ) ;
else
V_6 -> V_9 = V_398 ;
V_6 -> V_91 = false ;
V_6 -> V_92 = false ;
V_6 -> V_90 = V_184 ;
V_6 -> V_88 = F_90 ( & V_131 -> V_173 ,
V_272 ) ;
if ( V_157 == V_160 ) {
V_6 -> type = V_57 ;
V_401 = V_387 ;
V_395 = F_16 ( V_387 ) ;
} else {
V_6 -> type = V_58 ;
V_401 = V_389 ;
V_395 = F_16 ( V_389 ) ;
}
if ( V_404 ) {
for ( V_104 = 0 ; V_104 < V_395 ; V_104 ++ ) {
int V_294 = V_401 [ V_104 ] . V_294 ;
if ( ( V_396 >= V_401 [ V_104 ] . V_394 ) &&
( F_56 ( V_294 ) & V_131 -> V_173 ) ) {
V_6 -> V_88 = V_294 ;
break;
}
}
}
F_24 ( V_2 , L_125 , V_6 -> V_88 ,
F_17 ( V_6 -> V_9 ) ) ;
}
void F_111 ( struct V_1 * V_2 ,
struct V_110 * V_131 ,
struct V_405 * V_406 )
{
int V_104 ;
V_131 -> V_137 . V_403 = V_406 -> V_403 ;
V_131 -> V_137 . V_402 [ 0 ] = V_406 -> V_402 [ 0 ] ;
V_131 -> V_137 . V_402 [ 1 ] = V_406 -> V_402 [ 1 ] ;
V_131 -> V_137 . V_402 [ 2 ] = V_406 -> V_402 [ 2 ] ;
V_131 -> V_137 . V_393 = V_397 ;
for ( V_104 = 0 ; V_104 < F_16 ( V_131 -> V_137 . V_402 ) ; V_104 ++ ) {
if ( ! ( V_131 -> V_137 . V_403 & F_56 ( V_104 ) ) )
continue;
if ( V_131 -> V_137 . V_402 [ V_104 ] > V_131 -> V_137 . V_393 )
V_131 -> V_137 . V_393 = V_131 -> V_137 . V_402 [ V_104 ] ;
}
}
static void F_112 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
enum V_156 V_157 ,
bool V_407 )
{
struct V_102 * V_103 ;
struct V_5 * V_6 ;
T_1 V_244 = 0 ;
if ( ! V_4 || ! V_131 )
return;
if ( ! V_131 -> V_242 )
V_244 = V_131 -> V_244 ;
else
V_244 = 1 - V_131 -> V_244 ;
V_103 = & ( V_131 -> V_243 [ V_244 ] ) ;
V_6 = & V_103 -> V_6 ;
F_110 ( V_2 , V_131 , V_157 , V_6 ) ;
F_108 ( V_2 , V_4 , V_131 ) ;
F_38 ( V_6 -> V_9 != V_47 && V_6 -> V_9 != V_48 ) ;
if ( V_6 -> V_9 == V_47 )
V_103 -> V_134 = V_191 ;
else
V_103 -> V_134 = V_192 ;
F_87 ( V_131 , V_103 ) ;
F_93 ( V_2 , V_4 , V_131 , V_6 ) ;
F_74 ( V_2 , & V_131 -> V_237 , V_407 ) ;
}
static void F_113 ( void * V_251 , struct V_3 * V_4 , void * V_358 ,
struct V_408 * V_409 )
{
struct V_255 * V_256 = V_409 -> V_256 ;
struct V_257 * V_258 V_410 =
(struct V_257 * ) V_251 ;
struct V_1 * V_2 V_410 = F_79 ( V_258 ) ;
struct V_204 * V_205 = F_80 ( V_256 ) ;
struct V_110 * V_131 = V_358 ;
struct V_5 * V_384 ;
T_2 V_411 ;
if ( V_4 && ! F_7 ( V_4 ) -> V_18 ) {
V_4 = NULL ;
V_358 = NULL ;
}
if ( V_131 && ! V_131 -> V_137 . V_183 ) {
F_24 ( V_2 , L_52 ) ;
V_358 = NULL ;
}
if ( F_114 ( V_4 , V_358 , V_409 ) )
return;
F_115 ( V_131 -> V_249 ,
V_205 -> V_157 , & V_205 -> V_412 . V_229 [ 0 ] ) ;
V_205 -> V_412 . V_229 [ 0 ] . V_230 = 1 ;
if ( V_131 -> V_241 != V_246 ) {
V_384 = F_109 ( V_2 , V_131 ) ;
V_411 = F_39 ( V_2 ,
V_384 ) ;
F_115 ( V_411 , V_205 -> V_157 ,
& V_409 -> V_413 ) ;
}
}
static void * F_116 ( void * V_414 , struct V_3 * V_4 ,
T_8 V_415 )
{
struct V_10 * V_372 = F_7 ( V_4 ) ;
struct V_257 * V_258 = (struct V_257 * ) V_414 ;
struct V_1 * V_2 = F_79 ( V_258 ) ;
struct V_110 * V_131 = & V_372 -> V_131 ;
F_24 ( V_2 , L_126 ) ;
V_131 -> V_137 . V_183 = V_2 ;
#ifdef F_70
V_131 -> V_137 . V_226 = 0 ;
V_131 -> V_137 . V_363 = V_337 ;
V_131 -> V_137 . V_416 = V_417 ;
#endif
V_131 -> V_137 . V_403 = 0 ;
memset ( V_131 -> V_137 . V_402 , 0 , sizeof( V_131 -> V_137 . V_402 ) ) ;
V_131 -> V_137 . V_393 = V_397 ;
return & V_372 -> V_131 ;
}
static int F_117 ( struct V_22 * V_23 ,
int V_159 )
{
T_5 V_418 = F_118 ( V_23 -> V_419 . V_420 ) &
( 0x3 << ( 2 * ( V_159 - 1 ) ) ) ;
V_418 >>= ( 2 * ( V_159 - 1 ) ) ;
if ( V_418 == V_421 )
return V_84 ;
else if ( V_418 == V_422 )
return V_85 ;
else if ( V_418 == V_423 )
return V_86 ;
F_38 ( V_418 != V_424 ) ;
return - 1 ;
}
static void F_119 ( struct V_3 * V_4 ,
struct V_22 * V_23 ,
struct V_110 * V_131 )
{
int V_104 ;
int V_425 = F_117 ( V_23 , 1 ) ;
if ( V_425 >= V_33 ) {
for ( V_104 = V_33 ; V_104 <= V_425 ; V_104 ++ ) {
if ( V_104 == V_34 )
continue;
if ( V_104 == V_86 &&
V_4 -> V_297 == V_426 )
continue;
V_131 -> V_174 |= F_56 ( V_104 ) ;
}
}
if ( V_4 -> V_427 < 2 )
return;
V_425 = F_117 ( V_23 , 2 ) ;
if ( V_425 >= V_33 ) {
for ( V_104 = V_33 ; V_104 <= V_425 ; V_104 ++ ) {
if ( V_104 == V_34 )
continue;
if ( V_104 == V_86 &&
V_4 -> V_297 == V_426 )
continue;
V_131 -> V_175 |= F_56 ( V_104 ) ;
}
}
}
static void F_120 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
struct V_21 * V_14 )
{
V_131 -> V_174 = V_14 -> V_428 . V_429 [ 0 ] << 1 ;
V_131 -> V_174 |= V_14 -> V_428 . V_429 [ 0 ] & 0x1 ;
V_131 -> V_174 &= ~ ( ( T_5 ) 0x2 ) ;
V_131 -> V_174 <<= V_430 ;
V_131 -> V_175 = V_14 -> V_428 . V_429 [ 1 ] << 1 ;
V_131 -> V_175 |= V_14 -> V_428 . V_429 [ 1 ] & 0x1 ;
V_131 -> V_175 &= ~ ( ( T_5 ) 0x2 ) ;
V_131 -> V_175 <<= V_430 ;
if ( V_2 -> V_431 -> V_432 -> V_92 &&
( V_14 -> V_24 & V_433 ) )
V_131 -> V_92 = true ;
if ( V_2 -> V_431 -> V_432 -> V_93 &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_14 -> V_24 & V_434 ) )
V_131 -> V_333 = true ;
V_131 -> F_44 = false ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
struct V_22 * V_23 )
{
F_119 ( V_4 , V_23 , V_131 ) ;
if ( V_2 -> V_431 -> V_432 -> V_92 &&
( V_23 -> V_24 & V_435 ) )
V_131 -> V_92 = true ;
if ( V_2 -> V_431 -> V_432 -> V_93 &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_23 -> V_24 & V_436 ) )
V_131 -> V_333 = true ;
if ( F_122 ( & V_2 -> V_220 -> V_221 , V_437 ) &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_23 -> V_24 & V_438 ) )
V_131 -> V_439 = true ;
V_131 -> F_44 = true ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_124 ( & V_2 -> V_440 ) ;
memset ( & V_2 -> V_441 , 0 , sizeof( V_2 -> V_441 ) ) ;
F_125 ( & V_2 -> V_440 ) ;
}
void F_126 ( struct V_1 * V_2 , T_2 V_6 , bool V_442 )
{
T_1 V_159 = 0 , V_428 = 0 ;
F_127 ( & V_2 -> V_440 ) ;
if ( V_442 )
V_2 -> V_441 . V_443 ++ ;
V_2 -> V_441 . V_444 ++ ;
switch ( V_6 & V_163 ) {
case V_184 :
V_2 -> V_441 . V_445 ++ ;
break;
case V_284 :
V_2 -> V_441 . V_446 ++ ;
break;
case V_169 :
V_2 -> V_441 . V_447 ++ ;
break;
default:
F_49 ( 1 , L_127 , V_6 ) ;
}
if ( V_6 & V_31 ) {
V_2 -> V_441 . V_448 ++ ;
V_428 = V_6 & V_32 ;
V_159 = ( ( V_6 & V_164 ) >> V_165 ) + 1 ;
} else if ( V_6 & V_37 ) {
V_2 -> V_441 . V_449 ++ ;
V_428 = V_6 & V_38 ;
V_159 = ( ( V_6 & V_166 ) >>
V_167 ) + 1 ;
} else {
V_2 -> V_441 . V_450 ++ ;
}
if ( V_159 == 1 )
V_2 -> V_441 . V_451 ++ ;
else if ( V_159 == 2 )
V_2 -> V_441 . V_452 ++ ;
if ( V_6 & V_154 )
V_2 -> V_441 . V_453 ++ ;
else
V_2 -> V_441 . V_454 ++ ;
V_2 -> V_441 . V_455 [ V_2 -> V_441 . V_456 ] = V_6 ;
V_2 -> V_441 . V_456 =
( V_2 -> V_441 . V_456 + 1 ) %
F_16 ( V_2 -> V_441 . V_455 ) ;
F_128 ( & V_2 -> V_440 ) ;
}
void F_72 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_156 V_157 , bool V_407 )
{
int V_104 , V_310 ;
struct V_457 * V_458 = V_2 -> V_458 ;
struct V_21 * V_14 = & V_4 -> V_14 ;
struct V_22 * V_23 = & V_4 -> V_23 ;
struct V_10 * V_372 = F_7 ( V_4 ) ;
struct V_110 * V_131 = & V_372 -> V_131 ;
struct V_252 * V_253 ;
unsigned long V_459 ;
memset ( V_131 , 0 , F_129 ( F_130 ( * V_131 ) , V_137 ) ) ;
V_253 = V_458 -> V_460 -> V_461 [ V_157 ] ;
V_131 -> V_237 . V_462 = V_372 -> V_462 ;
for ( V_310 = 0 ; V_310 < V_463 ; V_310 ++ )
F_26 ( V_2 , & V_131 -> V_243 [ V_310 ] ) ;
V_131 -> V_270 = 0 ;
V_131 -> V_233 = V_232 ;
F_24 ( V_2 ,
L_128 ,
V_372 -> V_462 ) ;
V_131 -> V_239 = V_240 ;
V_131 -> V_157 = V_253 -> V_157 ;
V_459 = V_4 -> V_250 [ V_253 -> V_157 ] ;
V_131 -> V_173 = 0 ;
F_131 (i, &supp, BITS_PER_LONG)
V_131 -> V_173 |= F_56 ( V_253 -> V_464 [ V_104 ] . V_465 ) ;
if ( ! V_23 || ! V_23 -> V_466 )
F_120 ( V_2 , V_4 , V_131 , V_14 ) ;
else
F_121 ( V_2 , V_4 , V_131 , V_23 ) ;
V_131 -> V_275 =
F_83 ( V_131 -> V_173 ) ;
V_131 -> V_277 =
F_83 ( V_131 -> V_174 ) ;
V_131 -> V_279 =
F_83 ( V_131 -> V_175 ) ;
F_24 ( V_2 ,
L_129 ,
V_131 -> V_173 ,
V_131 -> V_174 ,
V_131 -> V_175 ,
V_131 -> F_44 , V_131 -> V_92 , V_131 -> V_333 ,
V_131 -> V_439 ) ;
F_24 ( V_2 , L_130 ,
V_131 -> V_275 ,
V_131 -> V_277 ,
V_131 -> V_279 ) ;
V_131 -> V_237 . V_467 =
F_59 ( F_5 ( V_2 ) ) ;
V_131 -> V_237 . V_468 = V_49 ;
V_131 -> V_383 = V_469 ;
V_131 -> V_289 = 0 ;
#ifdef F_132
F_123 ( V_2 ) ;
#endif
F_112 ( V_2 , V_4 , V_131 , V_157 , V_407 ) ;
}
static void F_133 ( void * V_251 ,
struct V_252 * V_253 ,
struct V_470 * V_471 ,
struct V_3 * V_4 , void * V_254 ,
T_2 V_472 )
{
T_1 V_112 ;
struct V_257 * V_258 =
(struct V_257 * ) V_251 ;
struct V_1 * V_2 = F_79 ( V_258 ) ;
if ( ! F_7 ( V_4 ) -> V_18 )
return;
for ( V_112 = 0 ; V_112 < V_116 ; V_112 ++ )
F_32 ( V_4 , V_112 ) ;
F_72 ( V_2 , V_4 , V_253 -> V_157 , false ) ;
}
static void F_134 ( struct V_1 * V_2 ,
struct V_208 * V_473 ,
enum V_156 V_157 ,
T_2 V_142 )
{
struct V_5 V_6 ;
int V_104 ;
int V_474 = F_16 ( V_473 -> V_238 ) ;
T_9 V_475 = F_135 ( V_142 ) ;
T_1 V_9 = ( V_142 & V_144 ) >> V_143 ;
for ( V_104 = 0 ; V_104 < V_474 ; V_104 ++ )
V_473 -> V_238 [ V_104 ] = V_475 ;
F_48 ( V_142 , V_157 , & V_6 ) ;
if ( F_63 ( & V_6 ) )
V_473 -> V_476 = V_474 - 1 ;
else
V_473 -> V_476 = 0 ;
V_473 -> V_362 = 0 ;
if ( F_4 ( V_9 ) == 1 )
V_473 -> V_467 = V_9 ;
V_473 -> V_477 = V_478 ;
}
static void F_136 ( struct V_1 * V_2 ,
struct V_110 * V_131 ,
struct V_5 * V_6 ,
T_9 * V_238 , int * V_479 ,
int V_474 , int V_480 ,
T_1 V_399 , bool V_481 )
{
int V_104 , V_310 ;
T_9 V_142 ;
bool V_482 = false ;
int V_483 = V_6 -> V_88 ;
int V_484 = V_485 ;
int V_88 = * V_479 ;
for ( V_104 = 0 ; V_104 < V_474 && V_88 < V_484 ; V_104 ++ ) {
for ( V_310 = 0 ; V_310 < V_480 && V_88 < V_484 ; V_310 ++ , V_88 ++ ) {
V_142 = F_135 ( F_39 ( V_2 ,
V_6 ) ) ;
V_238 [ V_88 ] = V_142 ;
if ( V_481 )
F_50 ( V_399 , V_6 ) ;
}
V_483 = V_6 -> V_88 ;
V_482 = F_57 ( V_131 , V_6 ) ;
if ( V_482 && ! F_40 ( V_6 ) )
break;
}
if ( ! V_482 && ! F_40 ( V_6 ) )
V_6 -> V_88 = V_483 ;
* V_479 = V_88 ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
const struct V_5 * V_486 )
{
struct V_5 V_6 ;
int V_474 , V_480 , V_88 = 0 ;
T_1 V_399 = 0 ;
struct V_208 * V_473 = & V_131 -> V_237 ;
bool V_481 = false ;
memcpy ( & V_6 , V_486 , sizeof( V_6 ) ) ;
V_399 = F_5 ( V_2 ) ;
if ( ! F_69 ( & V_2 -> V_220 -> V_221 , V_222 ) &&
F_98 ( V_2 , V_4 , V_131 ) )
V_6 . V_93 = true ;
if ( F_47 ( & V_6 ) ) {
V_474 = V_487 ;
V_480 = V_488 ;
} else if ( F_63 ( & V_6 ) ) {
V_474 = V_489 ;
V_480 = V_488 ;
} else {
V_474 = V_490 ;
V_480 = V_491 ;
V_481 = true ;
}
F_136 ( V_2 , V_131 , & V_6 , V_473 -> V_238 , & V_88 ,
V_474 , V_480 , V_399 ,
V_481 ) ;
F_58 ( V_131 , & V_6 ) ;
if ( F_47 ( & V_6 ) ) {
V_474 = V_492 ;
V_480 = V_493 ;
V_473 -> V_476 = V_88 ;
} else if ( F_40 ( & V_6 ) ) {
V_474 = V_494 ;
V_480 = V_495 ;
} else {
F_38 ( 1 ) ;
}
V_481 = true ;
F_136 ( V_2 , V_131 , & V_6 , V_473 -> V_238 , & V_88 ,
V_474 , V_480 , V_399 ,
V_481 ) ;
F_58 ( V_131 , & V_6 ) ;
V_474 = V_494 ;
V_480 = V_495 ;
F_136 ( V_2 , V_131 , & V_6 , V_473 -> V_238 , & V_88 ,
V_474 , V_480 , V_399 ,
V_481 ) ;
}
static void F_138 ( void * V_496 ,
struct V_3 * V_4 )
{
struct V_497 * V_96 = V_496 ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_208 * V_473 = & V_11 -> V_131 . V_237 ;
T_2 V_498 = F_73 ( V_473 -> V_498 ) ;
if ( V_4 == V_96 -> V_499 )
return;
if ( V_498 & V_500 ) {
F_38 ( V_96 -> V_501 != NULL ) ;
V_96 -> V_501 = V_11 ;
}
}
static int F_139 ( struct V_10 * V_4 )
{
int V_502 = - 1 ;
enum V_503 V_504 = F_140 ( V_4 -> V_18 ) ;
switch ( V_504 ) {
case V_505 :
case V_506 :
V_502 = 3 ;
break;
case V_507 :
V_502 = 2 ;
break;
case V_344 :
V_502 = 1 ;
break;
default:
F_49 ( true , L_131 , V_504 , V_4 -> V_462 ) ;
V_502 = - 1 ;
}
return V_502 ;
}
static int F_141 ( struct V_10 * V_508 ,
struct V_10 * V_509 )
{
int V_510 = F_139 ( V_508 ) ;
int V_511 = F_139 ( V_509 ) ;
if ( V_510 > V_511 )
return 1 ;
if ( V_510 < V_511 )
return - 1 ;
return 0 ;
}
static void F_142 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
const struct V_5 * V_486 )
{
struct V_208 * V_473 = & V_131 -> V_237 ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_497 V_96 = {
. V_499 = V_4 ,
. V_501 = NULL ,
} ;
struct V_10 * V_501 = NULL ;
T_2 V_498 = V_512 ;
if ( ! F_6 ( V_2 , V_4 ) )
goto V_332;
#ifdef F_70
if ( V_131 -> V_137 . V_416 == V_513 )
V_498 |= ( V_514 | V_515 ) ;
else if ( V_131 -> V_137 . V_416 == V_516 )
V_498 |= ( V_500 | V_515 ) ;
if ( V_131 -> V_137 . V_416 != V_417 ) {
F_24 ( V_2 , L_132 ,
V_131 -> V_137 . V_416 ) ;
goto V_332;
}
#endif
if ( V_131 -> V_333 )
V_498 |= V_514 ;
if ( ! V_131 -> V_439 )
goto V_332;
F_143 ( V_2 -> V_458 ,
F_138 ,
& V_96 ) ;
V_501 = V_96 . V_501 ;
if ( ! V_501 ) {
F_24 ( V_2 , L_133 ) ;
V_498 |= V_500 ;
goto V_332;
}
F_24 ( V_2 , L_134 ,
V_501 -> V_462 ) ;
if ( F_141 ( V_11 , V_501 ) > 0 ) {
struct V_208 * V_517 = & V_501 -> V_131 . V_237 ;
T_2 V_518 = F_73 ( V_517 -> V_498 ) ;
V_518 &= ~ V_500 ;
V_517 -> V_498 = F_135 ( V_518 ) ;
F_74 ( V_2 , V_517 , false ) ;
V_498 |= V_500 ;
F_24 ( V_2 ,
L_135 ,
V_501 -> V_462 ) ;
}
V_332:
V_473 -> V_498 = F_135 ( V_498 ) ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_110 * V_131 ,
const struct V_5 * V_486 )
{
struct V_208 * V_473 = & V_131 -> V_237 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_473 -> V_519 = V_520 ;
V_473 -> V_521 =
F_144 ( V_522 ) ;
#ifdef F_70
if ( V_131 -> V_137 . V_226 ) {
F_134 ( V_2 , V_473 ,
V_131 -> V_157 ,
V_131 -> V_137 . V_226 ) ;
return;
}
#endif
if ( F_38 ( ! V_4 || ! V_486 ) )
return;
F_137 ( V_2 , V_4 , V_131 , V_486 ) ;
if ( F_69 ( & V_2 -> V_220 -> V_221 , V_222 ) )
F_142 ( V_2 , V_4 , V_131 , V_486 ) ;
V_11 = F_7 ( V_4 ) ;
V_13 = F_8 ( V_11 -> V_18 ) ;
if ( F_4 ( V_486 -> V_9 ) == 1 )
V_473 -> V_467 = V_486 -> V_9 ;
V_473 -> V_477 = V_11 -> V_523 ;
if ( F_145 ( V_13 ) ) {
V_473 -> V_477 -- ;
if ( V_2 -> V_524 )
V_473 -> V_477 =
F_76 ( V_473 -> V_477 ,
V_2 -> V_524 ) ;
}
if ( V_11 -> V_18 -> V_525 )
V_473 -> V_223 |= V_526 ;
V_473 -> V_521 =
F_144 ( F_146 ( V_2 , V_4 ) ) ;
}
static void * F_147 ( struct V_457 * V_458 , struct V_527 * V_528 )
{
return V_458 -> V_529 ;
}
static void F_148 ( void * V_414 )
{
return;
}
static void F_149 ( void * V_251 , struct V_3 * V_4 ,
void * V_358 )
{
struct V_257 * V_258 V_410 = V_251 ;
struct V_1 * V_2 V_410 = F_79 ( V_258 ) ;
F_24 ( V_2 , L_136 ) ;
F_24 ( V_2 , L_137 ) ;
}
int F_150 ( char * V_64 , const T_2 V_6 )
{
char * type , * V_90 ;
T_1 V_428 = 0 , V_159 = 0 ;
T_1 V_9 = ( V_6 & V_144 ) >> V_143 ;
if ( ! ( V_6 & V_31 ) &&
! ( V_6 & V_37 ) ) {
int V_88 = F_15 ( V_6 ) ;
return sprintf ( V_64 , L_138 ,
F_17 ( V_9 ) ,
V_88 == V_44 ? L_139 :
V_530 [ V_88 ] . V_531 ) ;
}
if ( V_6 & V_37 ) {
type = L_140 ;
V_428 = V_6 & V_38 ;
V_159 = ( ( V_6 & V_166 )
>> V_167 ) + 1 ;
} else if ( V_6 & V_31 ) {
type = L_141 ;
V_428 = V_6 & V_532 ;
} else {
type = L_142 ;
}
switch ( V_6 & V_163 ) {
case V_184 :
V_90 = L_143 ;
break;
case V_284 :
V_90 = L_144 ;
break;
case V_169 :
V_90 = L_145 ;
break;
case V_168 :
V_90 = L_146 ;
break;
default:
V_90 = L_147 ;
}
return sprintf ( V_64 , L_148 ,
type , F_17 ( V_9 ) , V_90 , V_428 , V_159 ,
( V_6 & V_154 ) ? L_149 : L_150 ,
( V_6 & V_533 ) ? L_151 : L_152 ,
( V_6 & V_155 ) ? L_153 : L_152 ,
( V_6 & V_161 ) ? L_154 : L_152 ,
( V_6 & V_534 ) ? L_155 : L_152 ) ;
}
static void F_151 ( struct V_1 * V_2 ,
struct V_110 * V_131 )
{
V_131 -> V_173 = 0x0FFF ;
V_131 -> V_174 = 0x1FD0 ;
V_131 -> V_175 = 0x1FD0 ;
F_24 ( V_2 , L_156 ,
V_131 -> V_237 . V_462 , V_131 -> V_137 . V_226 ) ;
if ( V_131 -> V_137 . V_226 ) {
F_93 ( V_2 , NULL , V_131 , NULL ) ;
F_74 ( V_131 -> V_137 . V_183 , & V_131 -> V_237 , false ) ;
}
}
static T_10 F_152 ( struct V_535 * V_535 ,
const char T_11 * V_536 , T_12 V_230 , T_13 * V_537 )
{
struct V_110 * V_131 = V_535 -> V_538 ;
struct V_1 * V_2 ;
char V_64 [ 64 ] ;
T_12 V_539 ;
T_2 V_540 ;
V_2 = V_131 -> V_137 . V_183 ;
memset ( V_64 , 0 , sizeof( V_64 ) ) ;
V_539 = F_76 ( V_230 , sizeof( V_64 ) - 1 ) ;
if ( F_153 ( V_64 , V_536 , V_539 ) )
return - V_541 ;
if ( sscanf ( V_64 , L_157 , & V_540 ) == 1 )
V_131 -> V_137 . V_226 = V_540 ;
else
V_131 -> V_137 . V_226 = 0 ;
F_151 ( V_2 , V_131 ) ;
return V_230 ;
}
static T_10 F_154 ( struct V_535 * V_535 ,
char T_11 * V_536 , T_12 V_230 , T_13 * V_537 )
{
char * V_542 ;
int V_543 = 0 ;
int V_104 = 0 ;
T_10 V_113 ;
struct V_110 * V_131 = V_535 -> V_538 ;
struct V_1 * V_2 ;
struct V_102 * V_103 = & ( V_131 -> V_243 [ V_131 -> V_244 ] ) ;
struct V_5 * V_6 = & V_103 -> V_6 ;
T_2 V_498 ;
V_2 = V_131 -> V_137 . V_183 ;
V_542 = F_155 ( 2048 , V_544 ) ;
if ( ! V_542 )
return - V_545 ;
V_543 += sprintf ( V_542 + V_543 , L_158 , V_131 -> V_237 . V_462 ) ;
V_543 += sprintf ( V_542 + V_543 , L_159 ,
V_131 -> V_248 , V_131 -> V_247 ,
V_131 -> V_173 ) ;
V_543 += sprintf ( V_542 + V_543 , L_160 ,
V_131 -> V_137 . V_226 ) ;
V_543 += sprintf ( V_542 + V_543 , L_161 ,
( F_5 ( V_2 ) & V_47 ) ? L_162 : L_152 ,
( F_5 ( V_2 ) & V_48 ) ? L_163 : L_152 ,
( F_5 ( V_2 ) & V_50 ) ? L_164 : L_152 ) ;
V_543 += sprintf ( V_542 + V_543 , L_165 ,
( F_40 ( V_6 ) ) ? L_166 :
F_44 ( V_6 ) ? L_140 : L_141 ) ;
if ( ! F_40 ( V_6 ) ) {
V_543 += sprintf ( V_542 + V_543 , L_167 ,
( F_47 ( V_6 ) ) ? L_168 : L_169 ) ;
V_543 += sprintf ( V_542 + V_543 , L_167 ,
( F_11 ( V_6 ) ) ? L_170 :
( F_12 ( V_6 ) ) ? L_171 :
( F_13 ( V_6 ) ) ? L_145 : L_147 ) ;
V_543 += sprintf ( V_542 + V_543 , L_172 ,
( V_6 -> V_91 ) ? L_173 : L_174 ,
( V_6 -> V_92 ) ? L_175 : L_176 ,
( V_131 -> V_289 ) ? L_177 : L_152 ) ;
}
V_543 += sprintf ( V_542 + V_543 , L_178 ,
V_131 -> V_249 ) ;
V_543 += sprintf ( V_542 + V_543 ,
L_179 ,
V_131 -> V_237 . V_223 ,
V_131 -> V_237 . V_476 ,
V_131 -> V_237 . V_467 ,
V_131 -> V_237 . V_468 ) ;
V_543 += sprintf ( V_542 + V_543 ,
L_180 ,
F_118 ( V_131 -> V_237 . V_521 ) ,
V_131 -> V_237 . V_519 ,
V_131 -> V_237 . V_477 ) ;
V_543 += sprintf ( V_542 + V_543 , L_181 , V_131 -> V_237 . V_362 ) ;
V_498 = F_73 ( V_131 -> V_237 . V_498 ) ;
V_543 += sprintf ( V_542 + V_543 , L_182 ,
( V_498 & V_512 ) ?
L_183 : L_184 ,
( V_498 & V_500 ) ?
L_185 : L_152 ,
( V_498 & V_514 ) ?
L_186 : L_152 ,
( V_498 & V_515 ) ?
L_187 : L_152 ) ;
V_543 += sprintf ( V_542 + V_543 ,
L_188 ,
V_131 -> V_237 . V_546 [ 0 ] ,
V_131 -> V_237 . V_546 [ 1 ] ,
V_131 -> V_237 . V_546 [ 2 ] ,
V_131 -> V_237 . V_546 [ 3 ] ) ;
for ( V_104 = 0 ; V_104 < V_485 ; V_104 ++ ) {
T_2 V_547 = F_73 ( V_131 -> V_237 . V_238 [ V_104 ] ) ;
V_543 += sprintf ( V_542 + V_543 , L_189 , V_104 , V_547 ) ;
V_543 += F_150 ( V_542 + V_543 , V_547 ) ;
}
V_113 = F_156 ( V_536 , V_230 , V_537 , V_542 , V_543 ) ;
F_157 ( V_542 ) ;
return V_113 ;
}
static T_10 F_158 ( struct V_535 * V_535 ,
char T_11 * V_536 , T_12 V_230 , T_13 * V_537 )
{
char * V_542 ;
int V_543 = 0 ;
int V_104 , V_310 ;
T_10 V_113 ;
struct V_102 * V_103 ;
struct V_5 * V_6 ;
struct V_110 * V_131 = V_535 -> V_538 ;
V_542 = F_155 ( 1024 , V_544 ) ;
if ( ! V_542 )
return - V_545 ;
for ( V_104 = 0 ; V_104 < V_463 ; V_104 ++ ) {
V_103 = & ( V_131 -> V_243 [ V_104 ] ) ;
V_6 = & V_103 -> V_6 ;
V_543 += sprintf ( V_542 + V_543 ,
L_190
L_191 ,
V_131 -> V_244 == V_104 ? L_192 : L_193 ,
V_6 -> type ,
V_6 -> V_91 ,
F_11 ( V_6 ) ? L_143 :
F_12 ( V_6 ) ? L_144 :
F_13 ( V_6 ) ? L_145 : L_194 ,
V_6 -> V_88 ) ;
for ( V_310 = 0 ; V_310 < V_105 ; V_310 ++ ) {
V_543 += sprintf ( V_542 + V_543 ,
L_195 ,
V_103 -> V_106 [ V_310 ] . V_100 ,
V_103 -> V_106 [ V_310 ] . V_97 ,
V_103 -> V_106 [ V_310 ] . V_98 ) ;
}
}
V_113 = F_156 ( V_536 , V_230 , V_537 , V_542 , V_543 ) ;
F_157 ( V_542 ) ;
return V_113 ;
}
static T_10 F_159 ( struct V_535 * V_535 ,
char T_11 * V_536 ,
T_12 V_230 , T_13 * V_537 )
{
static const char * const V_548 [] = {
[ V_191 ] = L_196 ,
[ V_192 ] = L_197 ,
[ V_195 ] = L_198 ,
[ V_197 ] = L_199 ,
[ V_194 ] = L_200 ,
[ V_196 ] = L_201 ,
[ V_199 ] = L_169 ,
[ V_198 ] = L_202 ,
} ;
static const char * const V_549 [] = {
[ V_66 ] = L_17 ,
[ V_67 ] = L_18 ,
[ V_68 ] = L_19 ,
[ V_69 ] = L_20 ,
[ V_70 ] = L_203 ,
[ V_34 ] = L_22 ,
[ V_71 ] = L_204 ,
[ V_72 ] = L_205 ,
[ V_73 ] = L_206 ,
[ V_74 ] = L_207 ,
[ V_75 ] = L_208 ,
[ V_76 ] = L_209 ,
[ V_84 ] = L_36 ,
[ V_85 ] = L_37 ,
[ V_86 ] = L_38 ,
} ;
char * V_542 , * V_550 , * V_551 ;
int V_552 , V_6 ;
T_10 V_113 ;
struct V_110 * V_131 = V_535 -> V_538 ;
struct V_553 * V_554 ;
static const T_12 V_555 = 1024 ;
V_542 = F_155 ( V_555 , V_544 ) ;
if ( ! V_542 )
return - V_545 ;
V_550 = V_542 ;
V_551 = V_550 + V_555 ;
V_550 += F_160 ( V_550 , V_551 - V_550 , L_210 ) ;
for ( V_6 = 0 ; V_6 < V_105 ; V_6 ++ )
V_550 += F_160 ( V_550 , V_551 - V_550 , L_211 , V_549 [ V_6 ] ) ;
V_550 += F_160 ( V_550 , V_551 - V_550 , L_212 ) ;
for ( V_552 = 0 ; V_552 < V_556 ; V_552 ++ ) {
V_550 += F_160 ( V_550 , V_551 - V_550 ,
L_211 , V_548 [ V_552 ] ) ;
for ( V_6 = 0 ; V_6 < V_105 ; V_6 ++ ) {
V_554 = & ( V_131 -> V_137 . V_138 [ V_552 ] [ V_6 ] ) ;
V_550 += F_160 ( V_550 , V_551 - V_550 ,
L_213 ,
V_554 -> V_140 ,
V_554 -> V_139 ) ;
}
V_550 += F_160 ( V_550 , V_551 - V_550 , L_212 ) ;
}
V_113 = F_156 ( V_536 , V_230 , V_537 , V_542 , V_550 - V_542 ) ;
F_157 ( V_542 ) ;
return V_113 ;
}
static T_10 F_161 ( struct V_535 * V_535 ,
const char T_11 * V_536 ,
T_12 V_230 , T_13 * V_537 )
{
struct V_110 * V_131 = V_535 -> V_538 ;
memset ( V_131 -> V_137 . V_138 , 0 , sizeof( V_131 -> V_137 . V_138 ) ) ;
return V_230 ;
}
static T_10 F_162 ( struct V_535 * V_535 ,
char T_11 * V_536 ,
T_12 V_230 , T_13 * V_537 )
{
struct V_110 * V_131 = V_535 -> V_538 ;
char V_64 [ 12 ] ;
int V_555 = sizeof( V_64 ) ;
int V_550 = 0 ;
static const char * const V_557 [] = {
[ V_417 ] = L_214 ,
[ V_513 ] = L_215 ,
[ V_516 ] = L_216 ,
[ V_558 ] = L_217 ,
} ;
V_550 += F_160 ( V_64 + V_550 , V_555 - V_550 , L_218 ,
V_557 [ V_131 -> V_137 . V_416 ] ) ;
return F_156 ( V_536 , V_230 , V_537 , V_64 , V_550 ) ;
}
static T_10 F_163 ( struct V_110 * V_131 , char * V_64 ,
T_12 V_230 , T_13 * V_537 )
{
struct V_1 * V_2 = V_131 -> V_137 . V_183 ;
int V_113 = 0 ;
if ( ! strncmp ( L_214 , V_64 , 4 ) ) {
V_131 -> V_137 . V_416 = V_417 ;
} else if ( ! strncmp ( L_217 , V_64 , 4 ) ) {
V_131 -> V_137 . V_416 = V_558 ;
} else if ( ! strncmp ( L_215 , V_64 , 4 ) ) {
if ( V_131 -> V_333 ) {
V_131 -> V_137 . V_416 = V_513 ;
} else {
F_31 ( V_2 ,
L_219 ) ;
V_113 = - V_133 ;
}
} else if ( ! strncmp ( L_216 , V_64 , 4 ) ) {
if ( V_131 -> V_439 ) {
V_131 -> V_137 . V_416 = V_516 ;
} else {
F_31 ( V_2 ,
L_220 ) ;
V_113 = - V_133 ;
}
} else {
F_31 ( V_2 , L_221 ) ;
V_113 = - V_133 ;
}
return V_113 ? : V_230 ;
}
static void F_164 ( void * V_2 , void * V_254 , struct V_527 * V_559 )
{
struct V_110 * V_131 = V_254 ;
struct V_10 * V_11 ;
V_11 = F_165 ( V_131 , struct V_10 , V_131 ) ;
if ( ! V_11 -> V_18 )
return;
F_166 ( L_222 , V_560 | V_561 , V_559 ,
V_131 , & V_562 ) ;
F_166 ( L_223 , V_560 , V_559 ,
V_131 , & V_563 ) ;
F_166 ( L_224 , V_560 | V_561 , V_559 ,
V_131 , & V_564 ) ;
F_167 ( L_225 , V_560 | V_561 , V_559 ,
& V_131 -> V_383 ) ;
F_167 ( L_226 , V_560 | V_561 , V_559 ,
& V_131 -> V_137 . V_363 ) ;
F_168 ( V_416 , V_559 , V_560 | V_561 ) ;
return;
V_193:
F_31 ( (struct V_1 * ) V_2 , L_227 ) ;
}
static void F_169 ( void * V_2 , void * V_358 )
{
}
static void F_170 ( void * V_251 ,
struct V_252 * V_253 ,
struct V_470 * V_471 ,
struct V_3 * V_4 , void * V_358 )
{
}
int F_171 ( void )
{
return F_172 ( & V_565 ) ;
}
void F_173 ( void )
{
F_174 ( & V_565 ) ;
}
int F_175 ( struct V_1 * V_2 , struct V_10 * V_11 ,
bool V_566 )
{
struct V_208 * V_237 = & V_11 -> V_131 . V_237 ;
F_176 ( & V_2 -> V_567 ) ;
if ( V_566 ) {
if ( V_11 -> V_568 == 0 )
V_237 -> V_223 |= V_526 ;
V_11 -> V_568 ++ ;
} else {
V_11 -> V_568 -- ;
if ( V_11 -> V_568 == 0 )
V_237 -> V_223 &= ~ V_526 ;
}
return F_74 ( V_2 , V_237 , false ) ;
}
