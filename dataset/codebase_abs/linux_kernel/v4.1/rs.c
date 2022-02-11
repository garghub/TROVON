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
if ( F_9 ( V_13 ) && V_11 -> V_18 -> V_19 )
return false ;
if ( V_2 -> V_20 -> V_21 )
return false ;
return true ;
}
static bool F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! V_4 -> V_14 . V_15 )
return false ;
return true ;
}
static bool F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_22 * V_23 = & V_6 -> V_23 ;
struct V_24 * V_14 = & V_4 -> V_14 ;
struct V_25 * V_26 = & V_4 -> V_26 ;
if ( F_12 ( V_23 ) && ( V_14 -> V_27 &
V_28 ) )
return true ;
if ( F_13 ( V_23 ) && ( V_14 -> V_27 &
V_29 ) )
return true ;
if ( F_14 ( V_23 ) && ( V_26 -> V_27 &
V_30 ) )
return true ;
return false ;
}
static inline T_1 F_15 ( T_2 V_31 )
{
return ( T_1 ) ( V_31 & V_32 ) ;
}
static int F_16 ( T_2 V_31 )
{
int V_33 = 0 ;
if ( V_31 & V_34 ) {
V_33 = V_31 & V_35 ;
V_33 += V_36 ;
if ( V_33 >= V_37 )
V_33 += 1 ;
if ( ( V_33 >= V_38 ) && ( V_33 <= V_39 ) )
return V_33 ;
} else if ( V_31 & V_40 ) {
V_33 = V_31 & V_41 ;
V_33 += V_36 ;
if ( V_33 >= V_37 )
V_33 ++ ;
if ( ( V_33 >= V_42 ) && ( V_33 <= V_43 ) )
return V_33 ;
} else {
T_1 V_44 = F_15 ( V_31 ) ;
for ( V_33 = 0 ; V_33 < F_17 ( V_45 ) ; V_33 ++ )
if ( V_45 [ V_33 ] . V_46 == V_44 )
return V_33 ;
}
return V_47 ;
}
static const char * F_18 ( T_1 V_9 )
{
static const char * const V_48 [] = {
[ V_49 ] = L_1 ,
[ V_50 ] = L_2 ,
[ V_51 ] = L_3 ,
[ V_52 ] = L_4 ,
[ V_53 ] = L_5 ,
[ V_54 ] = L_6 ,
[ V_55 ] = L_7 ,
[ V_56 ] = L_8 ,
} ;
if ( V_9 > V_56 )
return L_9 ;
return V_48 [ V_9 ] ;
}
static const char * F_19 ( enum V_57 type )
{
static const char * const V_58 [] = {
[ V_59 ] = L_10 ,
[ V_60 ] = L_11 ,
[ V_61 ] = L_12 ,
[ V_62 ] = L_13 ,
[ V_63 ] = L_14 ,
[ V_64 ] = L_15 ,
[ V_65 ] = L_16 ,
} ;
if ( type < V_59 || type >= V_66 )
return L_9 ;
return V_58 [ type ] ;
}
static inline void F_20 ( struct V_1 * V_2 , const struct V_22 * V_23 ,
const char * V_67 )
{
F_21 ( V_2 ,
L_17 ,
V_67 , F_19 ( V_23 -> type ) ,
V_23 -> V_68 , F_18 ( V_23 -> V_9 ) ,
V_23 -> V_69 , V_23 -> V_70 , V_23 -> V_71 , V_23 -> V_72 ) ;
}
static void F_22 ( struct V_73 * V_74 )
{
V_74 -> V_75 = 0 ;
V_74 -> V_76 = 0 ;
V_74 -> V_77 = V_78 ;
V_74 -> V_79 = 0 ;
V_74 -> V_80 = V_78 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_81 ;
F_21 ( V_2 , L_18 ) ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ )
F_22 ( & V_6 -> V_83 [ V_81 ] ) ;
for ( V_81 = 0 ; V_81 < F_17 ( V_6 -> V_84 ) ; V_81 ++ )
F_22 ( & V_6 -> V_84 [ V_81 ] ) ;
}
static inline T_1 F_24 ( T_1 V_85 , T_1 V_86 )
{
return ( V_86 & V_85 ) == V_86 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_87 * V_88 , T_1 V_89 ,
struct V_3 * V_4 )
{
int V_90 = - V_91 ;
F_26 ( V_2 , L_19 ,
V_4 -> V_92 , V_89 ) ;
V_90 = F_27 ( V_4 , V_89 , 5000 ) ;
if ( V_90 == - V_91 ) {
F_28 ( V_2 , L_20 ,
V_89 ) ;
F_29 ( V_4 , V_89 ) ;
}
return V_90 ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_89 ,
struct V_87 * V_88 ,
struct V_3 * V_4 )
{
if ( V_89 < V_93 )
F_25 ( V_2 , V_88 , V_89 , V_4 ) ;
else
F_28 ( V_2 , L_21 ,
V_89 , V_93 ) ;
}
static inline int F_31 ( T_2 V_31 )
{
return ! ! ( V_31 & V_94 ) +
! ! ( V_31 & V_95 ) +
! ! ( V_31 & V_96 ) ;
}
static T_3 F_32 ( struct V_5 * V_6 , int V_97 )
{
if ( V_6 -> V_98 )
return V_6 -> V_98 [ V_97 ] ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int V_99 , int V_100 , int V_101 ,
struct V_73 * V_74 )
{
static const T_4 V_102 = ( ( ( T_4 ) 1 ) << ( V_103 - 1 ) ) ;
T_3 V_104 , V_105 ;
V_105 = F_32 ( V_6 , V_99 ) ;
while ( V_100 > 0 ) {
if ( V_74 -> V_79 >= V_103 ) {
V_74 -> V_79 = V_103 - 1 ;
if ( V_74 -> V_75 & V_102 ) {
V_74 -> V_75 &= ~ V_102 ;
V_74 -> V_76 -- ;
}
}
V_74 -> V_79 ++ ;
V_74 -> V_75 <<= 1 ;
if ( V_101 > 0 ) {
V_74 -> V_76 ++ ;
V_74 -> V_75 |= 0x1 ;
V_101 -- ;
}
V_100 -- ;
}
if ( V_74 -> V_79 > 0 )
V_74 -> V_77 = 128 * ( 100 * V_74 -> V_76 )
/ V_74 -> V_79 ;
else
V_74 -> V_77 = V_78 ;
V_104 = V_74 -> V_79 - V_74 -> V_76 ;
if ( ( V_104 >= V_106 ) ||
( V_74 -> V_76 >= V_107 ) )
V_74 -> V_80 = ( V_74 -> V_77 * V_105 + 64 ) / 128 ;
else
V_74 -> V_80 = V_78 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_5 * V_6 ,
int V_99 , int V_100 , int V_101 ,
T_1 V_109 )
{
struct V_73 * V_74 = NULL ;
int V_90 ;
if ( V_99 < 0 || V_99 >= V_82 )
return - V_110 ;
if ( V_6 -> V_111 != V_112 ) {
struct V_113 * V_114 = & V_108 -> V_114 ;
V_114 -> V_115 [ V_6 -> V_111 ] [ V_99 ] . V_116 += V_100 ;
V_114 -> V_115 [ V_6 -> V_111 ] [ V_99 ] . V_117 += V_101 ;
}
V_74 = & ( V_6 -> V_83 [ V_99 ] ) ;
V_90 = F_33 ( V_2 , V_6 , V_99 , V_100 , V_101 ,
V_74 ) ;
if ( V_90 )
return V_90 ;
if ( F_35 ( V_109 > V_118 ) )
return - V_110 ;
V_74 = & V_6 -> V_84 [ V_109 ] ;
return F_33 ( V_2 , V_6 , V_99 , V_100 , V_101 ,
V_74 ) ;
}
static T_2 F_36 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
T_2 V_119 = 0 ;
int V_68 = V_23 -> V_68 ;
V_119 |= ( ( V_23 -> V_9 << V_120 ) &
V_121 ) ;
if ( F_37 ( V_23 ) ) {
V_119 |= V_45 [ V_68 ] . V_46 ;
if ( V_68 >= V_122 && V_68 <= V_123 )
V_119 |= V_124 ;
return V_119 ;
}
if ( F_38 ( V_23 ) ) {
if ( V_68 < V_38 || V_68 > V_39 ) {
F_28 ( V_2 , L_22 , V_68 ) ;
V_68 = V_39 ;
}
V_119 |= V_34 ;
if ( F_39 ( V_23 ) )
V_119 |= V_45 [ V_68 ] . V_125 ;
else if ( F_40 ( V_23 ) )
V_119 |= V_45 [ V_68 ] . V_126 ;
else
F_35 ( 1 ) ;
} else if ( F_41 ( V_23 ) ) {
if ( V_68 < V_42 || V_68 > V_43 ) {
F_28 ( V_2 , L_23 , V_68 ) ;
V_68 = V_43 ;
}
V_119 |= V_40 ;
if ( F_42 ( V_23 ) )
V_119 |= V_45 [ V_68 ] . V_127 ;
else if ( F_43 ( V_23 ) )
V_119 |= V_45 [ V_68 ] . V_128 ;
else
F_35 ( 1 ) ;
} else {
F_28 ( V_2 , L_24 , V_23 -> type ) ;
}
if ( F_44 ( V_23 ) && V_23 -> V_72 ) {
V_119 |= V_129 ;
V_119 |= V_130 ;
}
V_119 |= V_23 -> V_69 ;
if ( V_23 -> V_70 )
V_119 |= V_131 ;
if ( V_23 -> V_71 )
V_119 |= V_132 ;
return V_119 ;
}
static int F_45 ( const T_2 V_119 ,
enum V_133 V_134 ,
struct V_22 * V_23 )
{
T_2 V_135 = V_119 & V_121 ;
T_1 F_4 = F_31 ( V_119 ) ;
T_1 V_136 ;
memset ( V_23 , 0 , sizeof( * V_23 ) ) ;
V_23 -> V_68 = F_16 ( V_119 ) ;
if ( V_23 -> V_68 == V_47 )
return - V_110 ;
V_23 -> V_9 = ( V_135 >> V_120 ) ;
if ( ! ( V_119 & V_34 ) &&
! ( V_119 & V_40 ) ) {
if ( F_4 == 1 ) {
if ( V_134 == V_137 )
V_23 -> type = V_60 ;
else
V_23 -> type = V_61 ;
}
return 0 ;
}
if ( V_119 & V_131 )
V_23 -> V_70 = true ;
if ( V_119 & V_132 )
V_23 -> V_71 = true ;
if ( V_119 & V_130 )
V_23 -> V_72 = true ;
if ( V_119 & V_138 )
V_23 -> V_139 = true ;
V_23 -> V_69 = V_119 & V_140 ;
if ( V_119 & V_34 ) {
V_136 = ( ( V_119 & V_141 ) >>
V_142 ) + 1 ;
if ( V_136 == 1 ) {
V_23 -> type = V_62 ;
F_46 ( ! V_23 -> V_72 && ! V_23 -> V_139 && F_4 != 1 ,
L_25 ,
V_23 -> V_72 , V_23 -> V_139 ) ;
} else if ( V_136 == 2 ) {
V_23 -> type = V_63 ;
F_35 ( F_4 != 2 ) ;
} else {
F_35 ( 1 ) ;
}
} else if ( V_119 & V_40 ) {
V_136 = ( ( V_119 & V_143 ) >>
V_144 ) + 1 ;
if ( V_136 == 1 ) {
V_23 -> type = V_64 ;
F_46 ( ! V_23 -> V_72 && ! V_23 -> V_139 && F_4 != 1 ,
L_25 ,
V_23 -> V_72 , V_23 -> V_139 ) ;
} else if ( V_136 == 2 ) {
V_23 -> type = V_65 ;
F_35 ( F_4 != 2 ) ;
} else {
F_35 ( 1 ) ;
}
}
F_35 ( V_23 -> V_69 == V_145 ) ;
F_35 ( V_23 -> V_69 == V_146 &&
! F_41 ( V_23 ) ) ;
return 0 ;
}
static int F_47 ( T_2 V_147 , struct V_22 * V_23 )
{
T_1 V_148 ;
if ( ! V_23 -> V_9 || V_23 -> V_9 > V_56 )
return 0 ;
if ( ! F_24 ( V_147 , V_23 -> V_9 ) )
return 0 ;
V_148 = V_149 [ V_23 -> V_9 ] ;
while ( ( V_148 != V_23 -> V_9 ) &&
! F_24 ( V_147 , V_148 ) )
V_148 = V_149 [ V_148 ] ;
if ( V_148 == V_23 -> V_9 )
return 0 ;
V_23 -> V_9 = V_148 ;
return 1 ;
}
static T_5 F_48 ( struct V_87 * V_108 ,
struct V_22 * V_23 )
{
if ( F_37 ( V_23 ) )
return V_108 -> V_150 ;
else if ( F_44 ( V_23 ) )
return V_108 -> V_151 ;
else if ( F_49 ( V_23 ) )
return V_108 -> V_152 ;
F_35 ( 1 ) ;
return 0 ;
}
static T_5 F_50 ( struct V_1 * V_2 , T_1 V_68 , T_5 V_153 ,
int V_154 )
{
T_1 V_155 = V_47 ;
T_1 V_156 = V_47 ;
if ( F_51 ( V_154 ) || ! F_52 ( V_154 ) ) {
int V_81 ;
T_2 V_102 ;
V_81 = V_68 - 1 ;
for ( V_102 = ( 1 << V_81 ) ; V_81 >= 0 ; V_81 -- , V_102 >>= 1 ) {
if ( V_153 & V_102 ) {
V_156 = V_81 ;
break;
}
}
V_81 = V_68 + 1 ;
for ( V_102 = ( 1 << V_81 ) ; V_81 < V_82 ; V_81 ++ , V_102 <<= 1 ) {
if ( V_153 & V_102 ) {
V_155 = V_81 ;
break;
}
}
return ( V_155 << 8 ) | V_156 ;
}
V_156 = V_68 ;
while ( V_156 != V_47 ) {
V_156 = V_45 [ V_156 ] . V_157 ;
if ( V_156 == V_47 )
break;
if ( V_153 & ( 1 << V_156 ) )
break;
}
V_155 = V_68 ;
while ( V_155 != V_47 ) {
V_155 = V_45 [ V_155 ] . V_158 ;
if ( V_155 == V_47 )
break;
if ( V_153 & ( 1 << V_155 ) )
break;
}
return ( V_155 << 8 ) | V_156 ;
}
static inline bool F_53 ( struct V_87 * V_108 ,
struct V_22 * V_23 )
{
return F_54 ( V_23 -> V_68 ) & F_48 ( V_108 , V_23 ) ;
}
static bool F_55 ( struct V_87 * V_108 ,
struct V_22 * V_23 )
{
T_1 V_156 ;
T_5 V_159 ;
T_5 V_153 ;
struct V_1 * V_2 = V_108 -> V_114 . V_160 ;
V_153 = F_48 ( V_108 , V_23 ) ;
V_159 = F_50 ( V_2 , V_23 -> V_68 , V_153 ,
V_23 -> type ) ;
V_156 = V_159 & 0xff ;
if ( V_156 == V_47 )
return true ;
V_23 -> V_68 = V_156 ;
return false ;
}
static void F_56 ( struct V_87 * V_108 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = V_108 -> V_114 . V_160 ;
if ( F_37 ( V_23 ) ) {
return;
} else if ( F_44 ( V_23 ) ) {
if ( V_108 -> V_134 == V_137 )
V_23 -> type = V_60 ;
else
V_23 -> type = V_61 ;
V_23 -> V_69 = V_161 ;
F_35 ( V_23 -> V_68 < V_36 ||
V_23 -> V_68 > V_162 ) ;
V_23 -> V_68 = V_163 [ V_23 -> V_68 ] ;
V_23 -> V_71 = false ;
} else {
V_23 -> type = F_43 ( V_23 ) ?
V_64 : V_62 ;
}
if ( F_4 ( V_23 -> V_9 ) > 1 )
V_23 -> V_9 = F_57 ( F_5 ( V_2 ) ) ;
V_23 -> V_70 = false ;
if ( ! F_53 ( V_108 , V_23 ) )
F_55 ( V_108 , V_23 ) ;
}
static inline bool F_58 ( struct V_22 * V_164 ,
struct V_22 * V_165 ,
bool V_166 )
{
bool V_167 = ( V_164 -> V_9 == V_165 -> V_9 ) && ( V_164 -> V_72 == V_165 -> V_72 ) &&
( V_164 -> V_139 == V_165 -> V_139 ) ;
if ( V_166 ) {
if ( V_164 -> V_72 || V_164 -> V_139 ) {
F_46 ( V_164 -> V_9 != V_52 , L_26 ,
V_164 -> V_72 , V_164 -> V_139 , V_164 -> V_9 ) ;
V_167 |= ( V_165 -> V_9 == V_50 || V_165 -> V_9 == V_51 ) ;
} else if ( V_165 -> V_72 || V_165 -> V_139 ) {
F_46 ( V_165 -> V_9 != V_52 , L_26 ,
V_165 -> V_72 , V_165 -> V_139 , V_165 -> V_9 ) ;
V_167 |= ( V_164 -> V_9 == V_50 || V_164 -> V_9 == V_51 ) ;
}
}
return ( V_164 -> type == V_165 -> type ) && ( V_164 -> V_69 == V_165 -> V_69 ) && ( V_164 -> V_70 == V_165 -> V_70 ) &&
( V_164 -> V_71 == V_165 -> V_71 ) && ( V_164 -> V_68 == V_165 -> V_68 ) && V_167 ;
}
static inline bool F_59 ( struct V_22 * V_164 ,
struct V_22 * V_165 )
{
bool V_167 ;
if ( V_164 -> V_72 || V_164 -> V_139 )
V_167 = ( V_165 -> V_9 == V_50 || V_165 -> V_9 == V_51 ) ;
else
V_167 = ( V_164 -> V_9 == V_165 -> V_9 ) ;
return ( V_164 -> type == V_165 -> type ) && ( V_164 -> V_69 == V_165 -> V_69 ) && ( V_164 -> V_70 == V_165 -> V_70 )
&& V_167 ;
}
static inline enum V_168 F_60 ( struct V_22 * V_23 )
{
if ( F_37 ( V_23 ) ) {
if ( V_23 -> V_9 == V_50 )
return V_169 ;
if ( V_23 -> V_9 == V_51 )
return V_170 ;
goto V_171;
}
if ( F_44 ( V_23 ) ) {
if ( V_23 -> V_9 == V_50 || V_23 -> V_72 || V_23 -> V_139 )
return V_23 -> V_70 ? V_172 :
V_173 ;
if ( V_23 -> V_9 == V_51 )
return V_23 -> V_70 ? V_174 :
V_175 ;
goto V_171;
}
if ( F_61 ( V_23 ) )
return V_23 -> V_70 ? V_176 : V_177 ;
V_171:
return V_112 ;
}
static T_1 F_62 ( struct V_178 * V_179 )
{
T_1 V_89 = V_93 ;
if ( F_63 ( V_179 -> V_180 ) ) {
T_1 * V_181 = F_64 ( V_179 ) ;
V_89 = V_181 [ 0 ] & 0xf ;
}
if ( F_65 ( V_89 > V_93 ) )
V_89 = V_93 ;
return V_89 ;
}
void F_66 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_89 , struct V_182 * V_183 )
{
int V_184 ;
int V_185 ;
int V_81 ;
struct V_186 * V_187 ;
T_2 V_188 ;
struct V_22 V_189 , V_190 ;
struct V_5 * V_191 , * V_192 , * V_193 ;
T_1 V_109 = ( V_194 ) V_183 -> V_195 . V_196 [ 0 ] ;
T_2 V_197 = ( V_194 ) V_183 -> V_195 . V_196 [ 1 ] ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_87 * V_108 = & V_11 -> V_108 ;
bool V_166 = V_2 -> V_198 -> V_199 . V_200 [ 0 ] &
V_201 ;
if ( ! V_108 ) {
F_21 ( V_2 , L_27 ) ;
return;
} else if ( ! V_108 -> V_114 . V_160 ) {
F_21 ( V_2 , L_28 ) ;
return;
}
if ( ( V_183 -> V_202 & V_203 ) &&
! ( V_183 -> V_202 & V_204 ) )
return;
F_45 ( V_197 , V_183 -> V_134 , & V_190 ) ;
#ifdef F_67
if ( V_108 -> V_114 . V_205 ) {
int V_68 = V_190 . V_68 ;
enum V_168 V_111 ;
int V_100 , V_117 ;
V_111 = F_60 ( & V_190 ) ;
if ( F_46 ( V_111 == V_112 ,
L_29 ,
V_197 ) )
return;
if ( V_183 -> V_202 & V_204 ) {
V_100 = V_183 -> V_195 . V_206 ;
V_117 = V_183 -> V_195 . V_207 ;
} else {
V_100 = V_183 -> V_195 . V_208 [ 0 ] . V_209 ;
V_117 = ! ! ( V_183 -> V_202 & V_210 ) ;
}
V_108 -> V_114 . V_115 [ V_111 ] [ V_68 ] . V_116 += V_100 ;
V_108 -> V_114 . V_115 [ V_111 ] [ V_68 ] . V_117 += V_117 ;
F_21 ( V_2 , L_30 ,
V_197 , V_117 , V_100 ) ;
return;
}
#endif
if ( F_68 ( V_211 ,
( unsigned long ) ( V_108 -> V_212 +
( V_213 * V_214 ) ) ) ) {
int V_215 ;
F_21 ( V_2 , L_31 ) ;
for ( V_215 = 0 ; V_215 < V_93 ; V_215 ++ )
F_29 ( V_4 , V_215 ) ;
F_69 ( V_2 , V_4 , V_183 -> V_134 , false ) ;
return;
}
V_108 -> V_212 = V_211 ;
V_187 = & V_108 -> V_216 ;
V_188 = F_70 ( V_187 -> V_217 [ 0 ] ) ;
F_45 ( V_188 , V_183 -> V_134 , & V_189 ) ;
if ( ! F_58 ( & V_190 , & V_189 , V_166 ) ) {
F_21 ( V_2 ,
L_32 ,
V_197 , V_188 ) ;
V_108 -> V_218 ++ ;
if ( V_108 -> V_218 > V_219 ) {
V_108 -> V_218 = 0 ;
F_21 ( V_2 ,
L_33 ,
V_108 -> V_220 ) ;
F_71 ( V_2 , & V_108 -> V_216 , false ) ;
}
return;
} else
V_108 -> V_218 = 0 ;
if ( ! V_108 -> V_221 ) {
V_191 = & ( V_108 -> V_222 [ V_108 -> V_223 ] ) ;
V_192 = & ( V_108 -> V_222 [ 1 - V_108 -> V_223 ] ) ;
} else {
V_191 = & ( V_108 -> V_222 [ 1 - V_108 -> V_223 ] ) ;
V_192 = & ( V_108 -> V_222 [ V_108 -> V_223 ] ) ;
}
if ( F_35 ( ! F_59 ( & V_189 , & V_191 -> V_23 ) ) ) {
F_21 ( V_2 ,
L_34 ) ;
V_193 = & ( V_108 -> V_222 [ V_108 -> V_223 ] ) ;
F_20 ( V_2 , & V_193 -> V_23 , L_35 ) ;
V_193 = & ( V_108 -> V_222 [ 1 - V_108 -> V_223 ] ) ;
F_20 ( V_2 , & V_193 -> V_23 , L_36 ) ;
F_20 ( V_2 , & V_189 , L_37 ) ;
F_72 ( V_108 , true ) ;
goto V_224;
}
if ( V_183 -> V_202 & V_204 ) {
if ( V_183 -> V_195 . V_207 == 0 )
V_183 -> V_195 . V_206 = 1 ;
F_34 ( V_2 , V_108 , V_191 , V_189 . V_68 ,
V_183 -> V_195 . V_206 ,
V_183 -> V_195 . V_207 ,
V_109 ) ;
if ( V_108 -> V_220 == V_225 ) {
V_108 -> V_226 += V_183 -> V_195 . V_207 ;
V_108 -> V_227 += ( V_183 -> V_195 . V_206 -
V_183 -> V_195 . V_207 ) ;
}
} else {
V_185 = V_183 -> V_195 . V_208 [ 0 ] . V_209 - 1 ;
V_185 = F_73 ( V_185 , 15 ) ;
V_184 = ! ! ( V_183 -> V_202 & V_210 ) ;
for ( V_81 = 0 ; V_81 <= V_185 ; ++ V_81 ) {
V_188 = F_70 ( V_187 -> V_217 [ V_81 ] ) ;
F_45 ( V_188 , V_183 -> V_134 ,
& V_189 ) ;
if ( F_59 ( & V_189 , & V_191 -> V_23 ) )
V_193 = V_191 ;
else if ( F_59 ( & V_189 ,
& V_192 -> V_23 ) )
V_193 = V_192 ;
else
continue;
F_34 ( V_2 , V_108 , V_193 , V_189 . V_68 ,
1 , V_81 < V_185 ? 0 : V_184 ,
V_109 ) ;
}
if ( V_108 -> V_220 == V_225 ) {
V_108 -> V_226 += V_184 ;
V_108 -> V_227 += V_185 + ( 1 - V_184 ) ;
}
}
V_108 -> V_228 = V_188 ;
F_21 ( V_2 , L_38 , V_109 ) ;
V_224:
if ( V_4 -> V_229 [ V_183 -> V_134 ] )
F_74 ( V_2 , V_4 , V_108 , V_89 ) ;
}
static void F_75 ( void * V_230 ,
struct V_231 * V_232 ,
struct V_3 * V_4 , void * V_233 ,
struct V_234 * V_235 )
{
struct V_178 * V_179 = (struct V_178 * ) V_235 -> V_75 ;
struct V_236 * V_237 = (struct V_236 * ) V_230 ;
struct V_1 * V_2 = F_76 ( V_237 ) ;
struct V_182 * V_183 = F_77 ( V_235 ) ;
if ( ! F_7 ( V_4 ) -> V_18 )
return;
if ( ! F_78 ( V_179 -> V_180 ) ||
V_183 -> V_202 & V_238 )
return;
F_66 ( V_2 , V_4 , F_62 ( V_179 ) , V_183 ) ;
}
static void F_79 ( struct V_1 * V_2 , T_1 F_37 ,
struct V_87 * V_108 )
{
F_21 ( V_2 , L_39 ) ;
V_108 -> V_220 = V_225 ;
if ( F_37 ) {
V_108 -> V_239 = V_240 ;
V_108 -> V_241 = V_242 ;
V_108 -> V_243 = V_244 ;
} else {
V_108 -> V_239 = V_245 ;
V_108 -> V_241 = V_246 ;
V_108 -> V_243 = V_247 ;
}
V_108 -> V_248 = 0 ;
V_108 -> V_227 = 0 ;
V_108 -> V_226 = 0 ;
V_108 -> V_249 = V_211 ;
V_108 -> V_250 = 0 ;
}
static inline int F_80 ( unsigned long V_153 )
{
if ( V_153 )
return F_81 ( & V_153 , V_251 ) ;
return V_47 ;
}
static int F_82 ( struct V_87 * V_108 ,
const struct V_7 * V_111 )
{
switch ( V_111 -> V_252 ) {
case V_253 :
return V_108 -> V_254 ;
case V_255 :
return V_108 -> V_256 ;
case V_257 :
return V_108 -> V_258 ;
default:
F_35 ( 1 ) ;
}
return V_108 -> V_254 ;
}
static const T_5 * F_83 ( struct V_87 * V_108 ,
const struct V_7 * V_111 ,
T_2 V_69 )
{
const T_5 ( * V_259 ) [ V_82 ] ;
if ( F_35 ( V_111 -> V_252 != V_253 &&
V_111 -> V_252 != V_255 &&
V_111 -> V_252 != V_257 ) )
return V_260 ;
if ( V_111 -> V_252 == V_253 )
return V_260 ;
V_259 = V_261 ;
if ( V_111 -> V_252 == V_255 ) {
switch ( V_69 ) {
case V_161 :
V_259 = V_262 ;
break;
case V_263 :
V_259 = V_264 ;
break;
case V_146 :
V_259 = V_265 ;
break;
default:
F_35 ( 1 ) ;
}
} else if ( V_111 -> V_252 == V_257 ) {
switch ( V_69 ) {
case V_161 :
V_259 = V_261 ;
break;
case V_263 :
V_259 = V_266 ;
break;
case V_146 :
V_259 = V_267 ;
break;
default:
F_35 ( 1 ) ;
}
} else {
F_35 ( 1 ) ;
}
if ( ! V_111 -> V_70 && ! V_108 -> V_268 )
return V_259 [ 0 ] ;
else if ( V_111 -> V_70 && ! V_108 -> V_268 )
return V_259 [ 1 ] ;
else if ( ! V_111 -> V_70 && V_108 -> V_268 )
return V_259 [ 2 ] ;
else
return V_259 [ 3 ] ;
}
static void F_84 ( struct V_87 * V_108 ,
struct V_5 * V_6 )
{
struct V_22 * V_23 = & V_6 -> V_23 ;
const struct V_7 * V_111 = & V_269 [ V_6 -> V_111 ] ;
V_6 -> V_98 = F_83 ( V_108 , V_111 , V_23 -> V_69 ) ;
}
static T_3 F_85 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_5 * V_6 ,
unsigned long V_153 , T_6 V_68 )
{
struct V_5 * V_223 =
& ( V_108 -> V_222 [ V_108 -> V_223 ] ) ;
T_3 V_77 = V_223 -> V_83 [ V_68 ] . V_77 ;
T_5 V_270 = V_223 -> V_98 [ V_68 ] ;
const T_5 * V_271 = V_6 -> V_98 ;
T_5 V_159 ;
T_2 V_272 ;
int V_273 ;
if ( V_77 > V_274 ) {
V_272 = 100 * V_270 ;
F_21 ( V_2 ,
L_40 ,
V_77 , V_272 ) ;
} else {
V_272 = V_108 -> V_275 ;
F_21 ( V_2 ,
L_41 ,
V_77 , V_272 ) ;
}
V_273 = F_86 ( & V_153 , V_251 ) ;
while ( V_273 != V_47 ) {
if ( V_272 < ( 100 * V_271 [ V_273 ] ) )
break;
V_159 = F_50 ( V_2 , V_273 , V_153 ,
V_6 -> V_23 . type ) ;
V_273 = ( V_159 >> 8 ) & 0xff ;
}
F_21 ( V_2 , L_42 ,
V_273 , V_272 ,
V_273 != V_47 ?
100 * V_271 [ V_273 ] : V_78 ) ;
return V_273 ;
}
static T_2 F_87 ( struct V_3 * V_4 )
{
if ( V_4 -> V_276 >= V_277 )
return V_146 ;
else if ( V_4 -> V_276 >= V_278 )
return V_263 ;
return V_161 ;
}
static void F_72 ( struct V_87 * V_108 , bool V_279 )
{
struct V_5 * V_6 ;
int V_223 ;
int V_280 = 0 ;
struct V_1 * V_2 ;
V_2 = V_108 -> V_114 . V_160 ;
V_223 = V_108 -> V_223 ;
V_6 = & ( V_108 -> V_222 [ V_223 ] ) ;
if ( V_108 -> V_220 == V_225 ) {
if ( V_108 -> V_249 )
V_280 =
F_68 ( V_211 ,
( unsigned long ) ( V_108 -> V_249 +
( V_281 * V_214 ) ) ) ;
if ( V_279 ||
( V_108 -> V_227 > V_108 -> V_241 ) ||
( V_108 -> V_226 > V_108 -> V_243 ) ||
( ( ! V_108 -> V_221 ) &&
( V_108 -> V_249 ) && ( V_280 ) ) ) {
F_21 ( V_2 ,
L_43 ,
V_108 -> V_227 ,
V_108 -> V_226 ,
V_280 ) ;
V_108 -> V_220 = V_282 ;
F_21 ( V_2 ,
L_44 ) ;
V_108 -> V_227 = 0 ;
V_108 -> V_226 = 0 ;
V_108 -> V_249 = 0 ;
V_108 -> V_250 = F_54 ( V_6 -> V_111 ) ;
} else {
V_108 -> V_248 ++ ;
if ( V_108 -> V_248 >=
V_108 -> V_239 ) {
V_108 -> V_248 = 0 ;
F_21 ( V_2 ,
L_45 ) ;
F_23 ( V_2 , V_6 ) ;
}
}
if ( V_108 -> V_220 == V_282 ) {
F_23 ( V_2 , V_6 ) ;
}
}
}
static void F_88 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
struct V_5 * V_6 )
{
F_89 ( V_2 , V_4 , V_108 , & V_6 -> V_23 ) ;
F_71 ( V_2 , & V_108 -> V_216 , false ) ;
}
static enum V_168 F_90 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_81 , V_283 , V_284 ;
enum V_168 V_285 ;
const struct V_7 * V_286 = & V_269 [ V_6 -> V_111 ] ;
const struct V_7 * V_8 ;
T_7 V_287 ;
T_1 V_288 = F_5 ( V_2 ) ;
const T_5 * V_289 ;
T_5 V_105 , V_290 ;
for ( V_81 = 0 ; V_81 < V_291 ; V_81 ++ ) {
V_285 = V_286 -> V_292 [ V_81 ] ;
if ( V_285 == V_112 )
continue;
if ( V_108 -> V_250 & F_54 ( V_285 ) ) {
F_21 ( V_2 , L_46 ,
V_285 ) ;
continue;
}
V_8 = & V_269 [ V_285 ] ;
if ( ! F_24 ( V_288 , V_8 -> V_9 ) ) {
F_21 ( V_2 ,
L_47 ,
V_285 , V_288 , V_8 -> V_9 ) ;
continue;
}
for ( V_283 = 0 ; V_283 < V_293 ; V_283 ++ ) {
V_287 = V_8 -> V_294 [ V_283 ] ;
if ( V_287 && ! V_287 ( V_2 , V_4 , V_6 , V_8 ) )
break;
}
if ( V_283 != V_293 ) {
F_21 ( V_2 ,
L_48 ,
V_285 , V_283 ) ;
continue;
}
V_105 = V_108 -> V_275 / 100 ;
V_289 = F_83 ( V_108 , V_8 ,
F_87 ( V_4 ) ) ;
if ( F_35 ( ! V_289 ) )
continue;
V_284 = F_82 ( V_108 , V_8 ) ;
if ( V_284 == V_47 ) {
F_21 ( V_2 ,
L_49 ,
V_285 ) ;
continue;
}
V_290 = V_289 [ V_284 ] ;
if ( V_105 >= V_290 ) {
F_21 ( V_2 ,
L_50 ,
V_285 , V_290 , V_105 ) ;
continue;
}
F_21 ( V_2 ,
L_51 ,
V_285 , V_290 , V_105 ) ;
break;
}
if ( V_81 == V_291 )
return V_112 ;
return V_285 ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_3 * V_4 ,
enum V_168 V_295 )
{
struct V_5 * V_6 = & ( V_108 -> V_222 [ V_108 -> V_223 ] ) ;
struct V_5 * V_296 =
& ( V_108 -> V_222 [ ( 1 - V_108 -> V_223 ) ] ) ;
struct V_22 * V_23 = & V_296 -> V_23 ;
const struct V_7 * V_111 = & V_269 [ V_295 ] ;
const struct V_7 * V_297 = & V_269 [ V_6 -> V_111 ] ;
T_2 V_298 = ( sizeof( struct V_5 ) -
( sizeof( struct V_73 ) * V_82 ) ) ;
unsigned long V_153 = 0 ;
T_2 V_273 = 0 ;
memcpy ( V_296 , V_6 , V_298 ) ;
V_23 -> V_70 = V_111 -> V_70 ;
V_23 -> V_9 = V_111 -> V_9 ;
if ( V_111 -> V_252 == V_253 ) {
if ( V_108 -> V_134 == V_137 )
V_23 -> type = V_60 ;
else
V_23 -> type = V_61 ;
V_23 -> V_69 = V_161 ;
V_23 -> V_71 = false ;
V_153 = V_108 -> V_150 ;
} else if ( V_111 -> V_252 == V_255 ) {
V_23 -> type = V_108 -> F_41 ? V_64 : V_62 ;
V_153 = V_108 -> V_151 ;
} else if ( V_111 -> V_252 == V_257 ) {
V_23 -> type = V_108 -> F_41 ? V_65 : V_63 ;
V_153 = V_108 -> V_152 ;
} else {
F_35 ( L_52 ) ;
}
if ( V_111 -> V_252 != V_253 ) {
V_23 -> V_69 = F_87 ( V_4 ) ;
V_23 -> V_71 = V_108 -> V_71 ;
}
V_296 -> V_111 = V_295 ;
F_84 ( V_108 , V_296 ) ;
V_108 -> V_250 |= F_54 ( V_295 ) ;
if ( V_297 -> V_252 != V_111 -> V_252 ) {
V_273 = F_85 ( V_2 , V_108 , V_296 ,
V_153 , V_23 -> V_68 ) ;
if ( ( V_273 == V_47 ) ||
! ( F_54 ( V_273 ) & V_153 ) ) {
F_21 ( V_2 ,
L_53
L_54 ,
V_273 , V_153 ) ;
goto V_171;
}
V_23 -> V_68 = V_273 ;
}
F_21 ( V_2 , L_55 ,
V_295 , V_23 -> V_68 ) ;
return 0 ;
V_171:
V_23 -> type = V_59 ;
return - 1 ;
}
static enum V_299 F_92 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_3 V_300 , int V_156 , int V_155 ,
int V_301 ,
int V_302 , int V_303 )
{
enum V_299 V_304 = V_305 ;
if ( ( V_300 <= F_93 ( V_306 ) ) ||
( V_301 == 0 ) ) {
F_21 ( V_2 ,
L_56 ) ;
return V_307 ;
}
if ( ( V_302 == V_78 ) &&
( V_303 == V_78 ) &&
( V_155 != V_47 ) ) {
F_21 ( V_2 ,
L_57 ) ;
return V_308 ;
}
if ( ( V_303 == V_78 ) &&
( V_155 != V_47 ) &&
( V_302 != V_78 ) &&
( V_302 < V_301 ) ) {
F_21 ( V_2 ,
L_58 ) ;
return V_308 ;
}
if ( ( V_303 != V_78 ) &&
( V_303 > V_301 ) ) {
F_21 ( V_2 ,
L_59 ) ;
return V_308 ;
}
if ( ( V_302 != V_78 ) &&
( V_303 != V_78 ) &&
( V_302 < V_301 ) &&
( V_303 < V_301 ) ) {
F_21 ( V_2 ,
L_60 ) ;
return V_305 ;
}
if ( ( V_302 != V_78 ) &&
( V_302 > V_301 ) ) {
F_21 ( V_2 ,
L_61 ) ;
V_304 = V_307 ;
goto V_309;
}
if ( ( V_302 == V_78 ) &&
( V_156 != V_47 ) ) {
F_21 ( V_2 ,
L_62 ) ;
V_304 = V_307 ;
goto V_309;
}
F_21 ( V_2 , L_63 ) ;
V_309:
if ( ( V_304 == V_307 ) && ( V_156 != V_47 ) ) {
if ( V_300 >= F_93 ( V_274 ) ) {
F_21 ( V_2 ,
L_64 ) ;
V_304 = V_305 ;
} else if ( V_301 > ( 100 * V_6 -> V_98 [ V_156 ] ) ) {
F_21 ( V_2 ,
L_65 ) ;
V_304 = V_305 ;
} else {
F_21 ( V_2 , L_66 ) ;
}
}
return V_304 ;
}
static bool F_94 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_87 * V_108 )
{
if ( ! V_108 -> V_310 )
return false ;
if ( ! F_6 ( V_2 , V_4 ) )
return false ;
return true ;
}
static void F_95 ( struct V_1 * V_2 , int V_68 ,
int * V_311 , int * V_312 )
{
* V_311 = V_68 + V_313 ;
if ( * V_311 > V_118 )
* V_311 = V_314 ;
* V_312 = V_68 - V_313 ;
if ( * V_312 < 0 )
* V_312 = V_314 ;
}
static bool F_96 ( struct V_1 * V_2 , struct V_315 * V_18 ,
struct V_22 * V_23 , enum V_133 V_134 )
{
int V_68 = V_23 -> V_68 ;
bool V_316 = ( V_317 . V_318 == V_319 ) ;
bool V_320 = ( V_18 -> type == V_321 &&
! V_18 -> V_322 . V_323 ) ;
F_21 ( V_2 , L_67 ,
V_316 , V_320 ) ;
if ( ( V_316 || V_320 ) &&
! F_97 ( V_2 , V_134 ) )
return false ;
F_21 ( V_2 , L_68 , V_23 -> type ) ;
if ( F_37 ( V_23 ) )
return V_68 == V_324 ;
if ( F_38 ( V_23 ) )
return V_68 == V_325 ;
if ( F_41 ( V_23 ) )
return V_68 == V_325 ||
V_68 == V_326 ||
V_68 == V_162 ;
F_35 ( 1 ) ;
return false ;
}
static enum V_327 F_98 ( struct V_1 * V_2 ,
T_3 V_300 , int V_328 , int V_329 ,
int V_301 ,
int V_330 , int V_331 )
{
if ( V_301 == V_78 ) {
F_21 ( V_2 , L_69 ) ;
return V_332 ;
}
if ( V_300 <= F_93 ( V_333 ) ||
V_301 == 0 ) {
F_21 ( V_2 , L_70 ) ;
return V_334 ;
}
if ( V_328 != V_314 ) {
if ( V_330 == V_78 &&
( V_331 == V_78 ||
V_301 >= V_331 ) ) {
F_21 ( V_2 ,
L_71 ) ;
return V_335 ;
}
if ( V_330 > V_301 ) {
F_21 ( V_2 ,
L_72 ) ;
return V_335 ;
}
}
if ( V_300 < F_93 ( V_336 ) &&
V_329 != V_314 ) {
if ( V_330 == V_78 &&
V_331 != V_78 &&
V_301 < V_331 ) {
F_21 ( V_2 ,
L_73 ) ;
return V_337 ;
}
if ( V_330 < V_301 &&
( V_331 == V_78 ||
V_331 > V_301 ) ) {
F_21 ( V_2 ,
L_74 ) ;
return V_337 ;
}
}
F_21 ( V_2 , L_75 ) ;
return V_332 ;
}
static bool F_99 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
struct V_5 * V_6 )
{
struct V_10 * V_338 = F_7 ( V_4 ) ;
struct V_315 * V_18 = V_338 -> V_18 ;
struct V_339 * V_340 ;
enum V_133 V_134 ;
struct V_73 * V_74 ;
struct V_22 * V_23 = & V_6 -> V_23 ;
enum V_327 V_304 ;
T_3 V_300 ;
T_1 V_341 = V_108 -> V_216 . V_342 ;
int V_301 ;
int V_328 , V_329 ;
int V_330 = V_78 , V_331 = V_78 ;
#ifdef F_67
if ( V_108 -> V_114 . V_343 <= V_118 ) {
F_21 ( V_2 , L_76 ,
V_108 -> V_114 . V_343 ) ;
V_108 -> V_216 . V_342 = V_108 -> V_114 . V_343 ;
return V_341 != V_108 -> V_114 . V_343 ;
}
#endif
F_100 () ;
V_340 = F_101 ( V_18 -> V_340 ) ;
if ( F_102 ( ! V_340 ) )
V_134 = V_344 ;
else
V_134 = V_340 -> V_345 . V_346 -> V_134 ;
F_103 () ;
if ( ! F_96 ( V_2 , V_18 , V_23 , V_134 ) ) {
F_21 ( V_2 ,
L_77 ) ;
V_108 -> V_216 . V_342 = V_347 ;
return V_341 != V_347 ;
}
F_95 ( V_2 , V_341 , & V_328 , & V_329 ) ;
V_74 = V_6 -> V_84 ;
V_300 = V_74 [ V_341 ] . V_77 ;
V_301 = V_74 [ V_341 ] . V_80 ;
if ( V_328 != V_314 )
V_330 = V_74 [ V_328 ] . V_80 ;
if ( V_329 != V_314 )
V_331 = V_74 [ V_329 ] . V_80 ;
F_21 ( V_2 ,
L_78 ,
V_341 , V_301 , V_300 , V_328 , V_329 ,
V_330 , V_331 ) ;
V_304 = F_98 ( V_2 , V_300 , V_328 , V_329 ,
V_301 , V_330 , V_331 ) ;
if ( V_328 == V_314 && V_304 == V_335 ) {
F_21 ( V_2 , L_79 ) ;
V_304 = V_332 ;
} else if ( V_329 == V_314 &&
( V_304 == V_337 ||
V_304 == V_334 ) ) {
F_21 ( V_2 , L_80 ) ;
V_304 = V_332 ;
}
switch ( V_304 ) {
case V_335 :
V_108 -> V_216 . V_342 = V_328 ;
return true ;
case V_337 :
V_108 -> V_216 . V_342 = V_329 ;
return true ;
case V_334 :
V_108 -> V_216 . V_342 = V_347 ;
return true ;
case V_332 :
break;
}
return false ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
int V_89 )
{
int V_156 = V_47 ;
int V_155 = V_47 ;
int V_68 ;
struct V_73 * V_74 = NULL ;
int V_301 = V_78 ;
int V_302 = V_78 ;
int V_303 = V_78 ;
T_2 V_104 ;
enum V_299 V_348 = V_305 ;
T_5 V_153 ;
T_1 V_349 = 0 ;
struct V_5 * V_6 , * V_350 ;
T_1 V_223 = 0 ;
T_1 V_351 = 0 ;
T_5 V_159 ;
T_3 V_300 ;
T_1 V_352 = V_108 -> V_268 ;
struct V_10 * V_353 = F_7 ( V_4 ) ;
struct V_354 * V_355 ;
struct V_22 * V_23 ;
V_108 -> V_268 = ! ! V_353 -> V_356 ;
if ( ! V_108 -> V_221 )
V_223 = V_108 -> V_223 ;
else
V_223 = 1 - V_108 -> V_223 ;
V_6 = & ( V_108 -> V_222 [ V_223 ] ) ;
V_23 = & V_6 -> V_23 ;
if ( V_352 != V_108 -> V_268 ) {
F_21 ( V_2 ,
L_81 ,
V_352 , V_108 -> V_268 ) ;
F_84 ( V_108 , V_6 ) ;
F_23 ( V_2 , V_6 ) ;
}
V_68 = V_108 -> V_357 ;
V_153 = F_48 ( V_108 , V_23 ) ;
if ( ! ( F_54 ( V_68 ) & V_153 ) ) {
F_28 ( V_2 , L_82 ) ;
if ( V_108 -> V_221 ) {
V_23 -> type = V_59 ;
V_108 -> V_221 = 0 ;
V_6 = & ( V_108 -> V_222 [ V_108 -> V_223 ] ) ;
F_88 ( V_2 , V_4 , V_108 , V_6 ) ;
}
return;
}
if ( ! V_6 -> V_98 ) {
F_28 ( V_2 , L_83 ) ;
return;
}
V_74 = & ( V_6 -> V_83 [ V_68 ] ) ;
V_104 = V_74 -> V_79 - V_74 -> V_76 ;
if ( ( V_104 < V_106 ) &&
( V_74 -> V_76 < V_107 ) ) {
F_21 ( V_2 ,
L_84 ,
F_19 ( V_23 -> type ) ,
V_68 , V_74 -> V_76 , V_74 -> V_79 ) ;
V_74 -> V_80 = V_78 ;
F_72 ( V_108 , false ) ;
goto V_309;
}
if ( V_74 -> V_80 != ( ( V_74 -> V_77 *
V_6 -> V_98 [ V_68 ] + 64 ) / 128 ) ) {
V_74 -> V_80 = ( ( V_74 -> V_77 *
V_6 -> V_98 [ V_68 ] + 64 ) / 128 ) ;
}
if ( V_108 -> V_221 ) {
if ( V_74 -> V_80 > V_108 -> V_275 ) {
F_21 ( V_2 ,
L_85
L_86 ,
V_74 -> V_77 ,
V_74 -> V_80 ,
V_108 -> V_275 ) ;
V_108 -> V_223 = V_223 ;
V_301 = V_74 -> V_80 ;
} else {
F_21 ( V_2 ,
L_87
L_86 ,
V_74 -> V_77 ,
V_74 -> V_80 ,
V_108 -> V_275 ) ;
V_23 -> type = V_59 ;
V_223 = V_108 -> V_223 ;
V_6 = & ( V_108 -> V_222 [ V_223 ] ) ;
V_68 = V_6 -> V_23 . V_68 ;
V_301 = V_108 -> V_275 ;
V_349 = 1 ;
}
V_108 -> V_221 = 0 ;
V_351 = 1 ;
goto V_358;
}
V_159 = F_50 ( V_2 , V_68 , V_153 , V_23 -> type ) ;
V_156 = V_159 & 0xff ;
V_155 = ( V_159 >> 8 ) & 0xff ;
V_300 = V_74 -> V_77 ;
V_301 = V_74 -> V_80 ;
if ( V_156 != V_47 )
V_302 = V_6 -> V_83 [ V_156 ] . V_80 ;
if ( V_155 != V_47 )
V_303 = V_6 -> V_83 [ V_155 ] . V_80 ;
F_21 ( V_2 ,
L_88 ,
F_19 ( V_23 -> type ) , V_68 , V_301 , V_300 ,
V_156 , V_155 , V_302 , V_303 ) ;
V_348 = F_92 ( V_2 , V_6 , V_300 , V_156 , V_155 ,
V_301 , V_302 , V_303 ) ;
if ( F_61 ( V_23 ) &&
! F_6 ( V_2 , V_4 ) ) {
F_21 ( V_2 ,
L_89 ) ;
F_72 ( V_108 , true ) ;
goto V_358;
}
switch ( V_348 ) {
case V_307 :
if ( V_156 != V_47 ) {
V_349 = 1 ;
V_68 = V_156 ;
} else {
F_21 ( V_2 ,
L_90 ) ;
}
break;
case V_308 :
if ( V_155 != V_47 ) {
V_349 = 1 ;
V_68 = V_155 ;
} else {
F_21 ( V_2 ,
L_91 ) ;
}
break;
case V_305 :
if ( V_108 -> V_220 == V_225 )
V_349 = F_99 ( V_2 , V_4 , V_108 , V_6 ) ;
break;
default:
break;
}
V_358:
if ( V_349 ) {
V_6 -> V_23 . V_68 = V_68 ;
F_88 ( V_2 , V_4 , V_108 , V_6 ) ;
}
F_72 ( V_108 , false ) ;
if ( ! V_349 && ! V_351 &&
V_108 -> V_220 == V_282
&& V_74 -> V_79 ) {
enum V_168 V_359 ;
V_108 -> V_275 = V_301 ;
F_21 ( V_2 ,
L_92 ,
V_349 , V_351 , V_108 -> V_220 ,
V_74 -> V_79 ) ;
V_359 = F_90 ( V_2 , V_108 , V_4 , V_6 ) ;
if ( V_359 != V_112 ) {
int V_90 = F_91 ( V_2 , V_108 , V_4 ,
V_359 ) ;
if ( ! V_90 )
V_108 -> V_221 = 1 ;
} else {
F_21 ( V_2 ,
L_93 ) ;
V_108 -> V_220 = V_360 ;
}
if ( V_108 -> V_221 ) {
V_6 = & ( V_108 -> V_222 [ ( 1 - V_108 -> V_223 ) ] ) ;
F_23 ( V_2 , V_6 ) ;
V_68 = V_6 -> V_23 . V_68 ;
F_20 ( V_2 , & V_6 -> V_23 ,
L_94 ) ;
F_88 ( V_2 , V_4 , V_108 , V_6 ) ;
} else {
V_351 = 1 ;
}
}
if ( V_351 && V_108 -> V_220 == V_360 ) {
V_350 = & ( V_108 -> V_222 [ V_108 -> V_223 ] ) ;
if ( F_37 ( & V_350 -> V_23 ) ) {
F_21 ( V_2 , L_95 ) ;
if ( V_89 != V_93 ) {
V_355 = & V_353 -> V_355 [ V_89 ] ;
if ( V_355 -> V_361 != V_362 ) {
F_21 ( V_2 ,
L_96 ,
V_89 ) ;
F_29 ( V_4 , V_89 ) ;
}
}
F_79 ( V_2 , 1 , V_108 ) ;
} else {
if ( ( V_108 -> V_275 > V_363 ) &&
( V_108 -> V_364 & ( 1 << V_89 ) ) &&
( V_89 != V_93 ) ) {
V_355 = & V_353 -> V_355 [ V_89 ] ;
if ( V_355 -> V_361 == V_362 ) {
F_21 ( V_2 ,
L_97 ,
V_89 ) ;
F_30 ( V_2 , V_89 ,
V_108 , V_4 ) ;
}
}
F_79 ( V_2 , 0 , V_108 ) ;
}
}
V_309:
V_108 -> V_357 = V_68 ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
enum V_133 V_134 ,
struct V_22 * V_23 )
{
int V_81 , V_365 ;
T_6 V_366 = V_367 ;
T_1 V_368 = V_49 ;
T_1 V_369 = F_5 ( V_2 ) ;
const struct V_370 * V_371 ;
for ( V_81 = 0 ; V_81 < F_17 ( V_108 -> V_114 . V_372 ) ; V_81 ++ ) {
if ( ! ( V_108 -> V_114 . V_373 & F_54 ( V_81 ) ) )
continue;
if ( V_108 -> V_114 . V_372 [ V_81 ] > V_366 ) {
V_366 = V_108 -> V_114 . V_372 [ V_81 ] ;
V_368 = F_54 ( V_81 ) ;
}
}
F_21 ( V_2 , L_98 ,
F_18 ( V_368 ) , V_366 ) ;
if ( V_368 != V_50 && V_368 != V_51 )
V_23 -> V_9 = F_57 ( V_369 ) ;
else
V_23 -> V_9 = V_368 ;
V_23 -> V_70 = false ;
V_23 -> V_71 = false ;
V_23 -> V_69 = V_161 ;
V_23 -> V_68 = F_86 ( & V_108 -> V_150 ,
V_251 ) ;
if ( V_134 == V_137 ) {
V_23 -> type = V_60 ;
V_371 = V_374 ;
V_365 = F_17 ( V_374 ) ;
} else {
V_23 -> type = V_61 ;
V_371 = V_375 ;
V_365 = F_17 ( V_375 ) ;
}
if ( V_376 ) {
for ( V_81 = 0 ; V_81 < V_365 ; V_81 ++ ) {
int V_273 = V_371 [ V_81 ] . V_273 ;
if ( ( V_366 >= V_371 [ V_81 ] . V_377 ) &&
( F_54 ( V_273 ) & V_108 -> V_150 ) ) {
V_23 -> V_68 = V_273 ;
break;
}
}
}
F_21 ( V_2 , L_99 , V_23 -> V_68 ,
F_18 ( V_23 -> V_9 ) ) ;
}
void F_105 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_378 * V_379 )
{
V_108 -> V_114 . V_373 = V_379 -> V_373 ;
V_108 -> V_114 . V_372 [ 0 ] = V_379 -> V_372 [ 0 ] ;
V_108 -> V_114 . V_372 [ 1 ] = V_379 -> V_372 [ 1 ] ;
V_108 -> V_114 . V_372 [ 2 ] = V_379 -> V_372 [ 2 ] ;
}
static void F_106 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
enum V_133 V_134 ,
bool V_380 )
{
struct V_5 * V_6 ;
struct V_22 * V_23 ;
T_1 V_223 = 0 ;
if ( ! V_4 || ! V_108 )
return;
if ( ! V_108 -> V_221 )
V_223 = V_108 -> V_223 ;
else
V_223 = 1 - V_108 -> V_223 ;
V_6 = & ( V_108 -> V_222 [ V_223 ] ) ;
V_23 = & V_6 -> V_23 ;
F_104 ( V_2 , V_108 , V_134 , V_23 ) ;
V_108 -> V_357 = V_23 -> V_68 ;
F_35 ( V_23 -> V_9 != V_50 && V_23 -> V_9 != V_51 ) ;
if ( V_23 -> V_9 == V_50 )
V_6 -> V_111 = V_169 ;
else
V_6 -> V_111 = V_170 ;
F_84 ( V_108 , V_6 ) ;
F_89 ( V_2 , V_4 , V_108 , V_23 ) ;
F_71 ( V_2 , & V_108 -> V_216 , V_380 ) ;
}
static void F_107 ( void * V_230 , struct V_3 * V_4 , void * V_338 ,
struct V_381 * V_382 )
{
struct V_234 * V_235 = V_382 -> V_235 ;
struct V_236 * V_237 V_383 =
(struct V_236 * ) V_230 ;
struct V_1 * V_2 V_383 = F_76 ( V_237 ) ;
struct V_182 * V_183 = F_77 ( V_235 ) ;
struct V_87 * V_108 = V_338 ;
if ( V_4 && ! F_7 ( V_4 ) -> V_18 ) {
V_4 = NULL ;
V_338 = NULL ;
}
if ( V_108 && ! V_108 -> V_114 . V_160 ) {
F_21 ( V_2 , L_28 ) ;
V_338 = NULL ;
}
if ( F_108 ( V_4 , V_338 , V_382 ) )
return;
F_109 ( V_108 -> V_228 ,
V_183 -> V_134 , & V_183 -> V_384 . V_208 [ 0 ] ) ;
V_183 -> V_384 . V_208 [ 0 ] . V_209 = 1 ;
}
static void * F_110 ( void * V_385 , struct V_3 * V_4 ,
T_8 V_386 )
{
struct V_10 * V_353 = F_7 ( V_4 ) ;
struct V_236 * V_237 = (struct V_236 * ) V_385 ;
struct V_1 * V_2 = F_76 ( V_237 ) ;
struct V_87 * V_108 = & V_353 -> V_108 ;
F_21 ( V_2 , L_100 ) ;
V_108 -> V_114 . V_160 = V_2 ;
#ifdef F_67
V_108 -> V_114 . V_205 = 0 ;
V_108 -> V_114 . V_343 = V_314 ;
V_108 -> V_114 . V_387 = V_388 ;
#endif
V_108 -> V_114 . V_373 = 0 ;
memset ( V_108 -> V_114 . V_372 , 0 , sizeof( V_108 -> V_114 . V_372 ) ) ;
return & V_353 -> V_108 ;
}
static int F_111 ( struct V_25 * V_26 ,
int V_136 )
{
T_5 V_389 = F_112 ( V_26 -> V_390 . V_391 ) &
( 0x3 << ( 2 * ( V_136 - 1 ) ) ) ;
V_389 >>= ( 2 * ( V_136 - 1 ) ) ;
if ( V_389 == V_392 )
return V_325 ;
else if ( V_389 == V_393 )
return V_326 ;
else if ( V_389 == V_394 )
return V_162 ;
F_35 ( V_389 != V_395 ) ;
return - 1 ;
}
static void F_113 ( struct V_3 * V_4 ,
struct V_25 * V_26 ,
struct V_87 * V_108 )
{
int V_81 ;
int V_396 = F_111 ( V_26 , 1 ) ;
if ( V_396 >= V_36 ) {
for ( V_81 = V_36 ; V_81 <= V_396 ; V_81 ++ ) {
if ( V_81 == V_37 )
continue;
if ( V_81 == V_162 &&
V_4 -> V_276 == V_397 )
continue;
V_108 -> V_151 |= F_54 ( V_81 ) ;
}
}
if ( V_4 -> V_398 < 2 )
return;
V_396 = F_111 ( V_26 , 2 ) ;
if ( V_396 >= V_36 ) {
for ( V_81 = V_36 ; V_81 <= V_396 ; V_81 ++ ) {
if ( V_81 == V_37 )
continue;
if ( V_81 == V_162 &&
V_4 -> V_276 == V_397 )
continue;
V_108 -> V_152 |= F_54 ( V_81 ) ;
}
}
}
static void F_114 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
struct V_24 * V_14 )
{
V_108 -> V_151 = V_14 -> V_399 . V_400 [ 0 ] << 1 ;
V_108 -> V_151 |= V_14 -> V_399 . V_400 [ 0 ] & 0x1 ;
V_108 -> V_151 &= ~ ( ( T_5 ) 0x2 ) ;
V_108 -> V_151 <<= V_401 ;
V_108 -> V_152 = V_14 -> V_399 . V_400 [ 1 ] << 1 ;
V_108 -> V_152 |= V_14 -> V_399 . V_400 [ 1 ] & 0x1 ;
V_108 -> V_152 &= ~ ( ( T_5 ) 0x2 ) ;
V_108 -> V_152 <<= V_401 ;
if ( V_2 -> V_402 -> V_403 -> V_71 &&
( V_14 -> V_27 & V_404 ) )
V_108 -> V_71 = true ;
if ( V_2 -> V_402 -> V_403 -> V_72 &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_14 -> V_27 & V_405 ) )
V_108 -> V_310 = true ;
V_108 -> F_41 = false ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
struct V_25 * V_26 )
{
F_113 ( V_4 , V_26 , V_108 ) ;
if ( V_2 -> V_402 -> V_403 -> V_71 &&
( V_26 -> V_27 & V_406 ) )
V_108 -> V_71 = true ;
if ( V_2 -> V_402 -> V_403 -> V_72 &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_26 -> V_27 & V_407 ) )
V_108 -> V_310 = true ;
if ( ( V_2 -> V_198 -> V_199 . V_408 [ 0 ] & V_409 ) &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_26 -> V_27 & V_410 ) )
V_108 -> V_411 = true ;
V_108 -> F_41 = true ;
}
static void F_116 ( struct V_1 * V_2 )
{
F_117 ( & V_2 -> V_412 ) ;
memset ( & V_2 -> V_413 , 0 , sizeof( V_2 -> V_413 ) ) ;
F_118 ( & V_2 -> V_412 ) ;
}
void F_119 ( struct V_1 * V_2 , T_2 V_23 , bool V_414 )
{
T_1 V_136 = 0 , V_399 = 0 ;
F_120 ( & V_2 -> V_412 ) ;
if ( V_414 )
V_2 -> V_413 . V_415 ++ ;
V_2 -> V_413 . V_416 ++ ;
switch ( V_23 & V_140 ) {
case V_161 :
V_2 -> V_413 . V_417 ++ ;
break;
case V_263 :
V_2 -> V_413 . V_418 ++ ;
break;
case V_146 :
V_2 -> V_413 . V_419 ++ ;
break;
default:
F_46 ( 1 , L_101 , V_23 ) ;
}
if ( V_23 & V_34 ) {
V_2 -> V_413 . V_420 ++ ;
V_399 = V_23 & V_35 ;
V_136 = ( ( V_23 & V_141 ) >> V_142 ) + 1 ;
} else if ( V_23 & V_40 ) {
V_2 -> V_413 . V_421 ++ ;
V_399 = V_23 & V_41 ;
V_136 = ( ( V_23 & V_143 ) >>
V_144 ) + 1 ;
} else {
V_2 -> V_413 . V_422 ++ ;
}
if ( V_136 == 1 )
V_2 -> V_413 . V_423 ++ ;
else if ( V_136 == 2 )
V_2 -> V_413 . V_424 ++ ;
if ( V_23 & V_131 )
V_2 -> V_413 . V_425 ++ ;
else
V_2 -> V_413 . V_426 ++ ;
V_2 -> V_413 . V_427 [ V_2 -> V_413 . V_428 ] = V_23 ;
V_2 -> V_413 . V_428 =
( V_2 -> V_413 . V_428 + 1 ) %
F_17 ( V_2 -> V_413 . V_427 ) ;
F_121 ( & V_2 -> V_412 ) ;
}
void F_69 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_133 V_134 , bool V_380 )
{
int V_81 , V_283 ;
struct V_429 * V_430 = V_2 -> V_430 ;
struct V_24 * V_14 = & V_4 -> V_14 ;
struct V_25 * V_26 = & V_4 -> V_26 ;
struct V_10 * V_353 = F_7 ( V_4 ) ;
struct V_87 * V_108 = & V_353 -> V_108 ;
struct V_231 * V_232 ;
unsigned long V_431 ;
memset ( V_108 , 0 , F_122 ( F_123 ( * V_108 ) , V_114 ) ) ;
V_232 = V_430 -> V_432 -> V_433 [ V_134 ] ;
V_108 -> V_216 . V_434 = V_353 -> V_434 ;
for ( V_283 = 0 ; V_283 < V_435 ; V_283 ++ )
F_23 ( V_2 , & V_108 -> V_222 [ V_283 ] ) ;
V_108 -> V_249 = 0 ;
V_108 -> V_212 = V_211 ;
F_21 ( V_2 ,
L_102 ,
V_353 -> V_434 ) ;
V_108 -> V_218 = V_219 ;
V_108 -> V_134 = V_232 -> V_134 ;
V_431 = V_4 -> V_229 [ V_232 -> V_134 ] ;
V_108 -> V_150 = 0 ;
F_124 (i, &supp, BITS_PER_LONG)
V_108 -> V_150 |= F_54 ( V_232 -> V_436 [ V_81 ] . V_437 ) ;
if ( ! V_26 || ! V_26 -> V_438 )
F_114 ( V_2 , V_4 , V_108 , V_14 ) ;
else
F_115 ( V_2 , V_4 , V_108 , V_26 ) ;
if ( V_439 && V_353 -> V_18 -> V_19 )
V_108 -> V_152 = 0 ;
V_108 -> V_254 =
F_80 ( V_108 -> V_150 ) ;
V_108 -> V_256 =
F_80 ( V_108 -> V_151 ) ;
V_108 -> V_258 =
F_80 ( V_108 -> V_152 ) ;
F_21 ( V_2 ,
L_103 ,
V_108 -> V_150 ,
V_108 -> V_151 ,
V_108 -> V_152 ,
V_108 -> F_41 , V_108 -> V_71 , V_108 -> V_310 ,
V_108 -> V_411 ) ;
F_21 ( V_2 , L_104 ,
V_108 -> V_254 ,
V_108 -> V_256 ,
V_108 -> V_258 ) ;
V_108 -> V_216 . V_440 =
F_57 ( F_5 ( V_2 ) ) ;
V_108 -> V_216 . V_441 = V_52 ;
V_108 -> V_364 = V_442 ;
V_108 -> V_268 = 0 ;
#ifdef F_125
F_116 ( V_2 ) ;
#endif
F_106 ( V_2 , V_4 , V_108 , V_134 , V_380 ) ;
}
static void F_126 ( void * V_230 ,
struct V_231 * V_232 ,
struct V_443 * V_444 ,
struct V_3 * V_4 , void * V_233 ,
T_2 V_445 )
{
T_1 V_89 ;
struct V_236 * V_237 =
(struct V_236 * ) V_230 ;
struct V_1 * V_2 = F_76 ( V_237 ) ;
if ( ! F_7 ( V_4 ) -> V_18 )
return;
for ( V_89 = 0 ; V_89 < V_93 ; V_89 ++ )
F_29 ( V_4 , V_89 ) ;
F_69 ( V_2 , V_4 , V_232 -> V_134 , false ) ;
}
static void F_127 ( struct V_1 * V_2 ,
struct V_186 * V_446 ,
enum V_133 V_134 ,
T_2 V_119 )
{
struct V_22 V_23 ;
int V_81 ;
int V_447 = F_17 ( V_446 -> V_217 ) ;
T_9 V_448 = F_128 ( V_119 ) ;
T_1 V_9 = ( V_119 & V_121 ) >> V_120 ;
for ( V_81 = 0 ; V_81 < V_447 ; V_81 ++ )
V_446 -> V_217 [ V_81 ] = V_448 ;
F_45 ( V_119 , V_134 , & V_23 ) ;
if ( F_61 ( & V_23 ) )
V_446 -> V_449 = V_447 - 1 ;
else
V_446 -> V_449 = 0 ;
V_446 -> V_342 = 0 ;
if ( F_4 ( V_9 ) == 1 )
V_446 -> V_440 = V_9 ;
V_446 -> V_450 = V_451 ;
}
static void F_129 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_22 * V_23 ,
T_9 * V_217 , int * V_452 ,
int V_447 , int V_453 ,
T_1 V_369 , bool V_454 )
{
int V_81 , V_283 ;
T_9 V_119 ;
bool V_455 = false ;
int V_456 = V_23 -> V_68 ;
int V_457 = V_458 ;
int V_68 = * V_452 ;
for ( V_81 = 0 ; V_81 < V_447 && V_68 < V_457 ; V_81 ++ ) {
for ( V_283 = 0 ; V_283 < V_453 && V_68 < V_457 ; V_283 ++ , V_68 ++ ) {
V_119 = F_128 ( F_36 ( V_2 ,
V_23 ) ) ;
V_217 [ V_68 ] = V_119 ;
if ( V_454 )
F_47 ( V_369 , V_23 ) ;
}
V_456 = V_23 -> V_68 ;
V_455 = F_55 ( V_108 , V_23 ) ;
if ( V_455 && ! F_37 ( V_23 ) )
break;
}
if ( ! V_455 && ! F_37 ( V_23 ) )
V_23 -> V_68 = V_456 ;
* V_452 = V_68 ;
}
static void F_130 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
const struct V_22 * V_459 )
{
struct V_22 V_23 ;
int V_447 , V_453 , V_68 = 0 ;
T_1 V_369 = 0 ;
struct V_186 * V_446 = & V_108 -> V_216 ;
bool V_454 = false ;
memcpy ( & V_23 , V_459 , sizeof( V_23 ) ) ;
V_369 = F_5 ( V_2 ) ;
if ( ! ( V_2 -> V_198 -> V_199 . V_200 [ 0 ] & V_201 ) &&
F_94 ( V_2 , V_4 , V_108 ) )
V_23 . V_72 = true ;
if ( F_44 ( & V_23 ) ) {
V_447 = V_460 ;
V_453 = V_461 ;
} else if ( F_61 ( & V_23 ) ) {
V_447 = V_462 ;
V_453 = V_461 ;
} else {
V_447 = V_463 ;
V_453 = V_464 ;
V_454 = true ;
}
F_129 ( V_2 , V_108 , & V_23 , V_446 -> V_217 , & V_68 ,
V_447 , V_453 , V_369 ,
V_454 ) ;
F_56 ( V_108 , & V_23 ) ;
if ( F_44 ( & V_23 ) ) {
V_447 = V_465 ;
V_453 = V_466 ;
V_446 -> V_449 = V_68 ;
} else if ( F_37 ( & V_23 ) ) {
V_447 = V_467 ;
V_453 = V_468 ;
} else {
F_35 ( 1 ) ;
}
V_454 = true ;
F_129 ( V_2 , V_108 , & V_23 , V_446 -> V_217 , & V_68 ,
V_447 , V_453 , V_369 ,
V_454 ) ;
F_56 ( V_108 , & V_23 ) ;
V_447 = V_467 ;
V_453 = V_468 ;
F_129 ( V_2 , V_108 , & V_23 , V_446 -> V_217 , & V_68 ,
V_447 , V_453 , V_369 ,
V_454 ) ;
}
static void F_131 ( void * V_469 ,
struct V_3 * V_4 )
{
struct V_470 * V_75 = V_469 ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_186 * V_446 = & V_11 -> V_108 . V_216 ;
T_2 V_471 = F_70 ( V_446 -> V_471 ) ;
if ( V_4 == V_75 -> V_472 )
return;
if ( V_471 & V_473 ) {
F_35 ( V_75 -> V_474 != NULL ) ;
V_75 -> V_474 = V_11 ;
}
}
static int F_132 ( struct V_10 * V_4 )
{
int V_475 = - 1 ;
enum V_476 V_477 = F_133 ( V_4 -> V_18 ) ;
switch ( V_477 ) {
case V_478 :
case V_479 :
V_475 = 3 ;
break;
case V_480 :
V_475 = 2 ;
break;
case V_321 :
V_475 = 1 ;
break;
default:
F_46 ( true , L_105 , V_477 , V_4 -> V_434 ) ;
V_475 = - 1 ;
}
return V_475 ;
}
static int F_134 ( struct V_10 * V_481 ,
struct V_10 * V_482 )
{
int V_483 = F_132 ( V_481 ) ;
int V_484 = F_132 ( V_482 ) ;
if ( V_483 > V_484 )
return 1 ;
if ( V_483 < V_484 )
return - 1 ;
return 0 ;
}
static void F_135 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
const struct V_22 * V_459 )
{
struct V_186 * V_446 = & V_108 -> V_216 ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_470 V_75 = {
. V_472 = V_4 ,
. V_474 = NULL ,
} ;
struct V_10 * V_474 = NULL ;
T_2 V_471 = V_485 ;
if ( ! F_6 ( V_2 , V_4 ) )
goto V_309;
#ifdef F_67
if ( V_108 -> V_114 . V_387 == V_486 )
V_471 |= ( V_487 | V_488 ) ;
else if ( V_108 -> V_114 . V_387 == V_489 )
V_471 |= ( V_473 | V_488 ) ;
if ( V_108 -> V_114 . V_387 != V_388 ) {
F_21 ( V_2 , L_106 ,
V_108 -> V_114 . V_387 ) ;
goto V_309;
}
#endif
if ( V_108 -> V_310 )
V_471 |= V_487 ;
if ( ! V_108 -> V_411 )
goto V_309;
F_136 ( V_2 -> V_430 ,
F_131 ,
& V_75 ) ;
V_474 = V_75 . V_474 ;
if ( ! V_474 ) {
F_21 ( V_2 , L_107 ) ;
V_471 |= V_473 ;
goto V_309;
}
F_21 ( V_2 , L_108 ,
V_474 -> V_434 ) ;
if ( F_134 ( V_11 , V_474 ) > 0 ) {
struct V_186 * V_490 = & V_474 -> V_108 . V_216 ;
T_2 V_491 = F_70 ( V_490 -> V_471 ) ;
V_491 &= ~ V_473 ;
V_490 -> V_471 = F_128 ( V_491 ) ;
F_71 ( V_2 , V_490 , false ) ;
V_471 |= V_473 ;
F_21 ( V_2 ,
L_109 ,
V_474 -> V_434 ) ;
}
V_309:
V_446 -> V_471 = F_128 ( V_471 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
const struct V_22 * V_459 )
{
struct V_186 * V_446 = & V_108 -> V_216 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_446 -> V_492 = V_493 ;
V_446 -> V_494 =
F_137 ( V_495 ) ;
#ifdef F_67
if ( V_108 -> V_114 . V_205 ) {
F_127 ( V_2 , V_446 ,
V_108 -> V_134 ,
V_108 -> V_114 . V_205 ) ;
return;
}
#endif
if ( F_35 ( ! V_4 || ! V_459 ) )
return;
F_130 ( V_2 , V_4 , V_108 , V_459 ) ;
if ( V_2 -> V_198 -> V_199 . V_200 [ 0 ] & V_201 )
F_135 ( V_2 , V_4 , V_108 , V_459 ) ;
if ( F_4 ( V_459 -> V_9 ) == 1 )
V_446 -> V_440 = V_459 -> V_9 ;
V_11 = F_7 ( V_4 ) ;
V_13 = F_8 ( V_11 -> V_18 ) ;
if ( F_4 ( V_459 -> V_9 ) == 1 )
V_446 -> V_440 = V_459 -> V_9 ;
V_446 -> V_450 = V_11 -> V_496 ;
if ( F_9 ( V_13 ) ) {
V_446 -> V_450 -- ;
if ( V_2 -> V_497 )
V_446 -> V_450 =
F_73 ( V_446 -> V_450 ,
V_2 -> V_497 ) ;
}
if ( V_11 -> V_18 -> V_19 )
V_446 -> V_202 |= V_498 ;
V_446 -> V_494 =
F_137 ( F_138 ( V_2 , V_4 ) ) ;
}
static void * F_139 ( struct V_429 * V_430 , struct V_499 * V_500 )
{
return V_430 -> V_501 ;
}
static void F_140 ( void * V_385 )
{
return;
}
static void F_141 ( void * V_230 , struct V_3 * V_4 ,
void * V_338 )
{
struct V_236 * V_237 V_383 = V_230 ;
struct V_1 * V_2 V_383 = F_76 ( V_237 ) ;
F_21 ( V_2 , L_110 ) ;
F_21 ( V_2 , L_111 ) ;
}
int F_142 ( char * V_502 , const T_2 V_23 )
{
char * type , * V_69 ;
T_1 V_399 = 0 , V_136 = 0 ;
T_1 V_9 = ( V_23 & V_121 ) >> V_120 ;
if ( ! ( V_23 & V_34 ) &&
! ( V_23 & V_40 ) ) {
int V_68 = F_16 ( V_23 ) ;
return sprintf ( V_502 , L_112 ,
F_18 ( V_9 ) ,
V_68 == V_47 ? L_113 :
V_503 [ V_68 ] . V_504 ) ;
}
if ( V_23 & V_40 ) {
type = L_114 ;
V_399 = V_23 & V_41 ;
V_136 = ( ( V_23 & V_143 )
>> V_144 ) + 1 ;
} else if ( V_23 & V_34 ) {
type = L_115 ;
V_399 = V_23 & V_505 ;
} else {
type = L_116 ;
}
switch ( V_23 & V_140 ) {
case V_161 :
V_69 = L_117 ;
break;
case V_263 :
V_69 = L_118 ;
break;
case V_146 :
V_69 = L_119 ;
break;
case V_145 :
V_69 = L_120 ;
break;
default:
V_69 = L_121 ;
}
return sprintf ( V_502 , L_122 ,
type , F_18 ( V_9 ) , V_69 , V_399 , V_136 ,
( V_23 & V_131 ) ? L_123 : L_124 ,
( V_23 & V_506 ) ? L_125 : L_126 ,
( V_23 & V_132 ) ? L_127 : L_126 ,
( V_23 & V_138 ) ? L_128 : L_126 ,
( V_23 & V_507 ) ? L_129 : L_126 ) ;
}
static void F_143 ( struct V_1 * V_2 ,
struct V_87 * V_108 )
{
V_108 -> V_150 = 0x0FFF ;
V_108 -> V_151 = 0x1FD0 ;
V_108 -> V_152 = 0x1FD0 ;
F_21 ( V_2 , L_130 ,
V_108 -> V_216 . V_434 , V_108 -> V_114 . V_205 ) ;
if ( V_108 -> V_114 . V_205 ) {
F_89 ( V_2 , NULL , V_108 , NULL ) ;
F_71 ( V_108 -> V_114 . V_160 , & V_108 -> V_216 , false ) ;
}
}
static T_10 F_144 ( struct V_508 * V_508 ,
const char T_11 * V_509 , T_12 V_209 , T_13 * V_510 )
{
struct V_87 * V_108 = V_508 -> V_511 ;
struct V_1 * V_2 ;
char V_502 [ 64 ] ;
T_12 V_512 ;
T_2 V_513 ;
V_2 = V_108 -> V_114 . V_160 ;
memset ( V_502 , 0 , sizeof( V_502 ) ) ;
V_512 = F_73 ( V_209 , sizeof( V_502 ) - 1 ) ;
if ( F_145 ( V_502 , V_509 , V_512 ) )
return - V_514 ;
if ( sscanf ( V_502 , L_131 , & V_513 ) == 1 )
V_108 -> V_114 . V_205 = V_513 ;
else
V_108 -> V_114 . V_205 = 0 ;
F_143 ( V_2 , V_108 ) ;
return V_209 ;
}
static T_10 F_146 ( struct V_508 * V_508 ,
char T_11 * V_509 , T_12 V_209 , T_13 * V_510 )
{
char * V_515 ;
int V_516 = 0 ;
int V_81 = 0 ;
T_10 V_90 ;
struct V_87 * V_108 = V_508 -> V_511 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = & ( V_108 -> V_222 [ V_108 -> V_223 ] ) ;
struct V_22 * V_23 = & V_6 -> V_23 ;
T_2 V_471 ;
V_2 = V_108 -> V_114 . V_160 ;
V_515 = F_147 ( 2048 , V_517 ) ;
if ( ! V_515 )
return - V_518 ;
V_516 += sprintf ( V_515 + V_516 , L_132 , V_108 -> V_216 . V_434 ) ;
V_516 += sprintf ( V_515 + V_516 , L_133 ,
V_108 -> V_227 , V_108 -> V_226 ,
V_108 -> V_150 ) ;
V_516 += sprintf ( V_515 + V_516 , L_134 ,
V_108 -> V_114 . V_205 ) ;
V_516 += sprintf ( V_515 + V_516 , L_135 ,
( F_5 ( V_2 ) & V_50 ) ? L_136 : L_126 ,
( F_5 ( V_2 ) & V_51 ) ? L_137 : L_126 ,
( F_5 ( V_2 ) & V_53 ) ? L_138 : L_126 ) ;
V_516 += sprintf ( V_515 + V_516 , L_139 ,
( F_37 ( V_23 ) ) ? L_140 :
F_41 ( V_23 ) ? L_114 : L_115 ) ;
if ( ! F_37 ( V_23 ) ) {
V_516 += sprintf ( V_515 + V_516 , L_141 ,
( F_44 ( V_23 ) ) ? L_142 : L_143 ) ;
V_516 += sprintf ( V_515 + V_516 , L_141 ,
( F_12 ( V_23 ) ) ? L_144 :
( F_13 ( V_23 ) ) ? L_145 :
( F_14 ( V_23 ) ) ? L_119 : L_121 ) ;
V_516 += sprintf ( V_515 + V_516 , L_146 ,
( V_23 -> V_70 ) ? L_147 : L_148 ,
( V_23 -> V_71 ) ? L_149 : L_150 ,
( V_108 -> V_268 ) ? L_151 : L_126 ) ;
}
V_516 += sprintf ( V_515 + V_516 , L_152 ,
V_108 -> V_228 ) ;
V_516 += sprintf ( V_515 + V_516 ,
L_153 ,
V_108 -> V_216 . V_202 ,
V_108 -> V_216 . V_449 ,
V_108 -> V_216 . V_440 ,
V_108 -> V_216 . V_441 ) ;
V_516 += sprintf ( V_515 + V_516 ,
L_154 ,
F_112 ( V_108 -> V_216 . V_494 ) ,
V_108 -> V_216 . V_492 ,
V_108 -> V_216 . V_450 ) ;
V_516 += sprintf ( V_515 + V_516 , L_155 , V_108 -> V_216 . V_342 ) ;
V_471 = F_70 ( V_108 -> V_216 . V_471 ) ;
V_516 += sprintf ( V_515 + V_516 , L_156 ,
( V_471 & V_485 ) ?
L_157 : L_158 ,
( V_471 & V_473 ) ?
L_159 : L_126 ,
( V_471 & V_487 ) ?
L_160 : L_126 ,
( V_471 & V_488 ) ?
L_161 : L_126 ) ;
V_516 += sprintf ( V_515 + V_516 ,
L_162 ,
V_108 -> V_216 . V_519 [ 0 ] ,
V_108 -> V_216 . V_519 [ 1 ] ,
V_108 -> V_216 . V_519 [ 2 ] ,
V_108 -> V_216 . V_519 [ 3 ] ) ;
for ( V_81 = 0 ; V_81 < V_458 ; V_81 ++ ) {
T_2 V_520 = F_70 ( V_108 -> V_216 . V_217 [ V_81 ] ) ;
V_516 += sprintf ( V_515 + V_516 , L_163 , V_81 , V_520 ) ;
V_516 += F_142 ( V_515 + V_516 , V_520 ) ;
}
V_90 = F_148 ( V_509 , V_209 , V_510 , V_515 , V_516 ) ;
F_149 ( V_515 ) ;
return V_90 ;
}
static T_10 F_150 ( struct V_508 * V_508 ,
char T_11 * V_509 , T_12 V_209 , T_13 * V_510 )
{
char * V_515 ;
int V_516 = 0 ;
int V_81 , V_283 ;
T_10 V_90 ;
struct V_5 * V_6 ;
struct V_22 * V_23 ;
struct V_87 * V_108 = V_508 -> V_511 ;
V_515 = F_147 ( 1024 , V_517 ) ;
if ( ! V_515 )
return - V_518 ;
for ( V_81 = 0 ; V_81 < V_435 ; V_81 ++ ) {
V_6 = & ( V_108 -> V_222 [ V_81 ] ) ;
V_23 = & V_6 -> V_23 ;
V_516 += sprintf ( V_515 + V_516 ,
L_164
L_165 ,
V_108 -> V_223 == V_81 ? L_166 : L_167 ,
V_23 -> type ,
V_23 -> V_70 ,
F_12 ( V_23 ) ? L_117 :
F_13 ( V_23 ) ? L_118 :
F_14 ( V_23 ) ? L_119 : L_168 ,
V_23 -> V_68 ) ;
for ( V_283 = 0 ; V_283 < V_82 ; V_283 ++ ) {
V_516 += sprintf ( V_515 + V_516 ,
L_169 ,
V_6 -> V_83 [ V_283 ] . V_79 ,
V_6 -> V_83 [ V_283 ] . V_76 ,
V_6 -> V_83 [ V_283 ] . V_77 ) ;
}
}
V_90 = F_148 ( V_509 , V_209 , V_510 , V_515 , V_516 ) ;
F_149 ( V_515 ) ;
return V_90 ;
}
static T_10 F_151 ( struct V_508 * V_508 ,
char T_11 * V_509 ,
T_12 V_209 , T_13 * V_510 )
{
static const char * const V_521 [] = {
[ V_169 ] = L_170 ,
[ V_170 ] = L_171 ,
[ V_173 ] = L_172 ,
[ V_175 ] = L_173 ,
[ V_172 ] = L_174 ,
[ V_174 ] = L_175 ,
[ V_177 ] = L_143 ,
[ V_176 ] = L_176 ,
} ;
static const char * const V_522 [] = {
[ V_523 ] = L_177 ,
[ V_524 ] = L_178 ,
[ V_525 ] = L_179 ,
[ V_526 ] = L_180 ,
[ V_527 ] = L_181 ,
[ V_37 ] = L_182 ,
[ V_528 ] = L_183 ,
[ V_529 ] = L_184 ,
[ V_530 ] = L_185 ,
[ V_531 ] = L_186 ,
[ V_532 ] = L_187 ,
[ V_324 ] = L_188 ,
[ V_325 ] = L_189 ,
[ V_326 ] = L_190 ,
[ V_162 ] = L_191 ,
} ;
char * V_515 , * V_533 , * V_534 ;
int V_535 , V_23 ;
T_10 V_90 ;
struct V_87 * V_108 = V_508 -> V_511 ;
struct V_536 * V_537 ;
static const T_12 V_538 = 1024 ;
V_515 = F_147 ( V_538 , V_517 ) ;
if ( ! V_515 )
return - V_518 ;
V_533 = V_515 ;
V_534 = V_533 + V_538 ;
V_533 += F_152 ( V_533 , V_534 - V_533 , L_192 ) ;
for ( V_23 = 0 ; V_23 < V_82 ; V_23 ++ )
V_533 += F_152 ( V_533 , V_534 - V_533 , L_193 , V_522 [ V_23 ] ) ;
V_533 += F_152 ( V_533 , V_534 - V_533 , L_194 ) ;
for ( V_535 = 0 ; V_535 < V_539 ; V_535 ++ ) {
V_533 += F_152 ( V_533 , V_534 - V_533 ,
L_193 , V_521 [ V_535 ] ) ;
for ( V_23 = 0 ; V_23 < V_82 ; V_23 ++ ) {
V_537 = & ( V_108 -> V_114 . V_115 [ V_535 ] [ V_23 ] ) ;
V_533 += F_152 ( V_533 , V_534 - V_533 ,
L_195 ,
V_537 -> V_117 ,
V_537 -> V_116 ) ;
}
V_533 += F_152 ( V_533 , V_534 - V_533 , L_194 ) ;
}
V_90 = F_148 ( V_509 , V_209 , V_510 , V_515 , V_533 - V_515 ) ;
F_149 ( V_515 ) ;
return V_90 ;
}
static T_10 F_153 ( struct V_508 * V_508 ,
const char T_11 * V_509 ,
T_12 V_209 , T_13 * V_510 )
{
struct V_87 * V_108 = V_508 -> V_511 ;
memset ( V_108 -> V_114 . V_115 , 0 , sizeof( V_108 -> V_114 . V_115 ) ) ;
return V_209 ;
}
static T_10 F_154 ( struct V_508 * V_508 ,
char T_11 * V_509 ,
T_12 V_209 , T_13 * V_510 )
{
struct V_87 * V_108 = V_508 -> V_511 ;
char V_502 [ 12 ] ;
int V_538 = sizeof( V_502 ) ;
int V_533 = 0 ;
static const char * const V_540 [] = {
[ V_388 ] = L_196 ,
[ V_486 ] = L_197 ,
[ V_489 ] = L_198 ,
[ V_541 ] = L_199 ,
} ;
V_533 += F_152 ( V_502 + V_533 , V_538 - V_533 , L_200 ,
V_540 [ V_108 -> V_114 . V_387 ] ) ;
return F_148 ( V_509 , V_209 , V_510 , V_502 , V_533 ) ;
}
static T_10 F_155 ( struct V_87 * V_108 , char * V_502 ,
T_12 V_209 , T_13 * V_510 )
{
struct V_1 * V_2 = V_108 -> V_114 . V_160 ;
int V_90 = 0 ;
if ( ! strncmp ( L_196 , V_502 , 4 ) ) {
V_108 -> V_114 . V_387 = V_388 ;
} else if ( ! strncmp ( L_199 , V_502 , 4 ) ) {
V_108 -> V_114 . V_387 = V_541 ;
} else if ( ! strncmp ( L_197 , V_502 , 4 ) ) {
if ( V_108 -> V_310 ) {
V_108 -> V_114 . V_387 = V_486 ;
} else {
F_28 ( V_2 ,
L_201 ) ;
V_90 = - V_110 ;
}
} else if ( ! strncmp ( L_198 , V_502 , 4 ) ) {
if ( V_108 -> V_411 ) {
V_108 -> V_114 . V_387 = V_489 ;
} else {
F_28 ( V_2 ,
L_202 ) ;
V_90 = - V_110 ;
}
} else {
F_28 ( V_2 , L_203 ) ;
V_90 = - V_110 ;
}
return V_90 ? : V_209 ;
}
static void F_156 ( void * V_2 , void * V_233 , struct V_499 * V_542 )
{
struct V_87 * V_108 = V_233 ;
struct V_10 * V_11 ;
V_11 = F_157 ( V_108 , struct V_10 , V_108 ) ;
if ( ! V_11 -> V_18 )
return;
F_158 ( L_204 , V_543 | V_544 , V_542 ,
V_108 , & V_545 ) ;
F_158 ( L_205 , V_543 , V_542 ,
V_108 , & V_546 ) ;
F_158 ( L_206 , V_543 | V_544 , V_542 ,
V_108 , & V_547 ) ;
F_159 ( L_207 , V_543 | V_544 , V_542 ,
& V_108 -> V_364 ) ;
F_159 ( L_208 , V_543 | V_544 , V_542 ,
& V_108 -> V_114 . V_343 ) ;
F_160 ( V_387 , V_542 , V_543 | V_544 ) ;
return;
V_171:
F_28 ( (struct V_1 * ) V_2 , L_209 ) ;
}
static void F_161 ( void * V_2 , void * V_338 )
{
}
static void F_162 ( void * V_230 ,
struct V_231 * V_232 ,
struct V_443 * V_444 ,
struct V_3 * V_4 , void * V_338 )
{
}
int F_163 ( void )
{
return F_164 ( & V_548 ) ;
}
void F_165 ( void )
{
F_166 ( & V_548 ) ;
}
int F_167 ( struct V_1 * V_2 , struct V_10 * V_11 ,
bool V_549 )
{
struct V_186 * V_216 = & V_11 -> V_108 . V_216 ;
F_168 ( & V_2 -> V_550 ) ;
if ( V_549 ) {
if ( V_11 -> V_551 == 0 )
V_216 -> V_202 |= V_498 ;
V_11 -> V_551 ++ ;
} else {
V_11 -> V_551 -- ;
if ( V_11 -> V_551 == 0 )
V_216 -> V_202 &= ~ V_498 ;
}
return F_71 ( V_2 , V_216 , false ) ;
}
