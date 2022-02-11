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
struct V_22 * V_14 = & V_4 -> V_14 ;
struct V_23 * V_24 = & V_4 -> V_24 ;
if ( F_12 ( V_6 ) && ( V_14 -> V_25 &
V_26 ) )
return true ;
if ( F_13 ( V_6 ) && ( V_14 -> V_25 &
V_27 ) )
return true ;
if ( F_14 ( V_6 ) && ( V_24 -> V_25 &
V_28 ) )
return true ;
return false ;
}
static inline T_1 F_15 ( T_2 V_29 )
{
return ( T_1 ) ( V_29 & V_30 ) ;
}
static int F_16 ( T_2 V_29 )
{
int V_31 = 0 ;
if ( V_29 & V_32 ) {
V_31 = V_29 & V_33 ;
V_31 += V_34 ;
if ( V_31 >= V_35 )
V_31 += 1 ;
if ( ( V_31 >= V_36 ) && ( V_31 <= V_37 ) )
return V_31 ;
} else if ( V_29 & V_38 ) {
V_31 = V_29 & V_39 ;
V_31 += V_34 ;
if ( V_31 >= V_35 )
V_31 ++ ;
if ( ( V_31 >= V_40 ) && ( V_31 <= V_41 ) )
return V_31 ;
} else {
T_1 V_42 = F_15 ( V_29 ) ;
for ( V_31 = 0 ; V_31 < F_17 ( V_43 ) ; V_31 ++ )
if ( V_43 [ V_31 ] . V_44 == V_42 )
return V_31 ;
}
return V_45 ;
}
static const char * F_18 ( T_1 V_9 )
{
static const char * const V_46 [] = {
[ V_47 ] = L_1 ,
[ V_48 ] = L_2 ,
[ V_49 ] = L_3 ,
[ V_50 ] = L_4 ,
[ V_51 ] = L_5 ,
[ V_52 ] = L_6 ,
[ V_53 ] = L_7 ,
[ V_54 ] = L_8 ,
} ;
if ( V_9 > V_54 )
return L_9 ;
return V_46 [ V_9 ] ;
}
static const char * F_19 ( enum V_55 type )
{
static const char * const V_56 [] = {
[ V_57 ] = L_10 ,
[ V_58 ] = L_11 ,
[ V_59 ] = L_12 ,
[ V_60 ] = L_13 ,
[ V_61 ] = L_14 ,
[ V_62 ] = L_15 ,
[ V_63 ] = L_16 ,
} ;
if ( type < V_57 || type >= V_64 )
return L_9 ;
return V_56 [ type ] ;
}
static inline void F_20 ( struct V_1 * V_2 , const struct V_5 * V_6 ,
const char * V_65 )
{
F_21 ( V_2 ,
L_17 ,
V_65 , F_19 ( V_6 -> type ) ,
V_6 -> V_66 , F_18 ( V_6 -> V_9 ) ,
V_6 -> V_67 , V_6 -> V_68 , V_6 -> V_69 , V_6 -> V_70 ) ;
}
static void F_22 ( struct V_71 * V_72 )
{
V_72 -> V_73 = 0 ;
V_72 -> V_74 = 0 ;
V_72 -> V_75 = V_76 ;
V_72 -> V_77 = 0 ;
V_72 -> V_78 = V_76 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
int V_81 ;
F_21 ( V_2 , L_18 ) ;
for ( V_81 = 0 ; V_81 < V_82 ; V_81 ++ )
F_22 ( & V_80 -> V_83 [ V_81 ] ) ;
for ( V_81 = 0 ; V_81 < F_17 ( V_80 -> V_84 ) ; V_81 ++ )
F_22 ( & V_80 -> V_84 [ V_81 ] ) ;
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
static inline int F_31 ( T_2 V_29 )
{
return ! ! ( V_29 & V_94 ) +
! ! ( V_29 & V_95 ) +
! ! ( V_29 & V_96 ) ;
}
static T_3 F_32 ( struct V_79 * V_80 , int V_97 )
{
if ( V_80 -> V_98 )
return V_80 -> V_98 [ V_97 ] ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
int V_99 , int V_100 , int V_101 ,
struct V_71 * V_72 )
{
static const T_4 V_102 = ( ( ( T_4 ) 1 ) << ( V_103 - 1 ) ) ;
T_3 V_104 , V_105 ;
V_105 = F_32 ( V_80 , V_99 ) ;
while ( V_100 > 0 ) {
if ( V_72 -> V_77 >= V_103 ) {
V_72 -> V_77 = V_103 - 1 ;
if ( V_72 -> V_73 & V_102 ) {
V_72 -> V_73 &= ~ V_102 ;
V_72 -> V_74 -- ;
}
}
V_72 -> V_77 ++ ;
V_72 -> V_73 <<= 1 ;
if ( V_101 > 0 ) {
V_72 -> V_74 ++ ;
V_72 -> V_73 |= 0x1 ;
V_101 -- ;
}
V_100 -- ;
}
if ( V_72 -> V_77 > 0 )
V_72 -> V_75 = 128 * ( 100 * V_72 -> V_74 )
/ V_72 -> V_77 ;
else
V_72 -> V_75 = V_76 ;
V_104 = V_72 -> V_77 - V_72 -> V_74 ;
if ( ( V_104 >= V_106 ) ||
( V_72 -> V_74 >= V_107 ) )
V_72 -> V_78 = ( V_72 -> V_75 * V_105 + 64 ) / 128 ;
else
V_72 -> V_78 = V_76 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_79 * V_80 ,
int V_99 , int V_100 , int V_101 ,
T_1 V_109 )
{
struct V_71 * V_72 = NULL ;
int V_90 ;
if ( V_99 < 0 || V_99 >= V_82 )
return - V_110 ;
if ( V_80 -> V_111 != V_112 ) {
struct V_113 * V_114 = & V_108 -> V_114 ;
V_114 -> V_115 [ V_80 -> V_111 ] [ V_99 ] . V_116 += V_100 ;
V_114 -> V_115 [ V_80 -> V_111 ] [ V_99 ] . V_117 += V_101 ;
}
V_72 = & ( V_80 -> V_83 [ V_99 ] ) ;
V_90 = F_33 ( V_2 , V_80 , V_99 , V_100 , V_101 ,
V_72 ) ;
if ( V_90 )
return V_90 ;
if ( F_35 ( V_109 > V_118 ) )
return - V_110 ;
V_72 = & V_80 -> V_84 [ V_109 ] ;
return F_33 ( V_2 , V_80 , V_99 , V_100 , V_101 ,
V_72 ) ;
}
static T_2 F_36 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
T_2 V_119 = 0 ;
int V_66 = V_6 -> V_66 ;
V_119 |= ( ( V_6 -> V_9 << V_120 ) &
V_121 ) ;
if ( F_37 ( V_6 ) ) {
V_119 |= V_43 [ V_66 ] . V_44 ;
if ( V_66 >= V_122 && V_66 <= V_123 )
V_119 |= V_124 ;
return V_119 ;
}
if ( F_38 ( V_6 ) ) {
if ( V_66 < V_36 || V_66 > V_37 ) {
F_28 ( V_2 , L_22 , V_66 ) ;
V_66 = V_37 ;
}
V_119 |= V_32 ;
if ( F_39 ( V_6 ) )
V_119 |= V_43 [ V_66 ] . V_125 ;
else if ( F_40 ( V_6 ) )
V_119 |= V_43 [ V_66 ] . V_126 ;
else
F_35 ( 1 ) ;
} else if ( F_41 ( V_6 ) ) {
if ( V_66 < V_40 || V_66 > V_41 ) {
F_28 ( V_2 , L_23 , V_66 ) ;
V_66 = V_41 ;
}
V_119 |= V_38 ;
if ( F_42 ( V_6 ) )
V_119 |= V_43 [ V_66 ] . V_127 ;
else if ( F_43 ( V_6 ) )
V_119 |= V_43 [ V_66 ] . V_128 ;
else
F_35 ( 1 ) ;
} else {
F_28 ( V_2 , L_24 , V_6 -> type ) ;
}
if ( F_44 ( V_6 ) && V_6 -> V_70 ) {
V_119 |= V_129 ;
V_119 |= V_130 ;
}
V_119 |= V_6 -> V_67 ;
if ( V_6 -> V_68 )
V_119 |= V_131 ;
if ( V_6 -> V_69 )
V_119 |= V_132 ;
return V_119 ;
}
static int F_45 ( const T_2 V_119 ,
enum V_133 V_134 ,
struct V_5 * V_6 )
{
T_2 V_135 = V_119 & V_121 ;
T_1 F_4 = F_31 ( V_119 ) ;
T_1 V_136 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_66 = F_16 ( V_119 ) ;
if ( V_6 -> V_66 == V_45 )
return - V_110 ;
V_6 -> V_9 = ( V_135 >> V_120 ) ;
if ( ! ( V_119 & V_32 ) &&
! ( V_119 & V_38 ) ) {
if ( F_4 == 1 ) {
if ( V_134 == V_137 )
V_6 -> type = V_58 ;
else
V_6 -> type = V_59 ;
}
return 0 ;
}
if ( V_119 & V_131 )
V_6 -> V_68 = true ;
if ( V_119 & V_132 )
V_6 -> V_69 = true ;
if ( V_119 & V_130 )
V_6 -> V_70 = true ;
if ( V_119 & V_138 )
V_6 -> V_139 = true ;
V_6 -> V_67 = V_119 & V_140 ;
if ( V_119 & V_32 ) {
V_136 = ( ( V_119 & V_141 ) >>
V_142 ) + 1 ;
if ( V_136 == 1 ) {
V_6 -> type = V_60 ;
F_46 ( ! V_6 -> V_70 && ! V_6 -> V_139 && F_4 != 1 ,
L_25 ,
V_6 -> V_70 , V_6 -> V_139 ) ;
} else if ( V_136 == 2 ) {
V_6 -> type = V_61 ;
F_35 ( F_4 != 2 ) ;
} else {
F_35 ( 1 ) ;
}
} else if ( V_119 & V_38 ) {
V_136 = ( ( V_119 & V_143 ) >>
V_144 ) + 1 ;
if ( V_136 == 1 ) {
V_6 -> type = V_62 ;
F_46 ( ! V_6 -> V_70 && ! V_6 -> V_139 && F_4 != 1 ,
L_25 ,
V_6 -> V_70 , V_6 -> V_139 ) ;
} else if ( V_136 == 2 ) {
V_6 -> type = V_63 ;
F_35 ( F_4 != 2 ) ;
} else {
F_35 ( 1 ) ;
}
}
F_35 ( V_6 -> V_67 == V_145 ) ;
F_35 ( V_6 -> V_67 == V_146 &&
! F_41 ( V_6 ) ) ;
return 0 ;
}
static int F_47 ( T_2 V_147 , struct V_5 * V_6 )
{
T_1 V_148 ;
if ( ! V_6 -> V_9 || V_6 -> V_9 > V_54 )
return 0 ;
if ( ! F_24 ( V_147 , V_6 -> V_9 ) )
return 0 ;
V_148 = V_149 [ V_6 -> V_9 ] ;
while ( ( V_148 != V_6 -> V_9 ) &&
! F_24 ( V_147 , V_148 ) )
V_148 = V_149 [ V_148 ] ;
if ( V_148 == V_6 -> V_9 )
return 0 ;
V_6 -> V_9 = V_148 ;
return 1 ;
}
static T_5 F_48 ( struct V_87 * V_108 ,
struct V_5 * V_6 )
{
if ( F_37 ( V_6 ) )
return V_108 -> V_150 ;
else if ( F_44 ( V_6 ) )
return V_108 -> V_151 ;
else if ( F_49 ( V_6 ) )
return V_108 -> V_152 ;
F_35 ( 1 ) ;
return 0 ;
}
static T_5 F_50 ( struct V_1 * V_2 , T_1 V_66 , T_5 V_153 ,
int V_154 )
{
T_1 V_155 = V_45 ;
T_1 V_156 = V_45 ;
if ( F_51 ( V_154 ) || ! F_52 ( V_154 ) ) {
int V_81 ;
T_2 V_102 ;
V_81 = V_66 - 1 ;
for ( V_102 = ( 1 << V_81 ) ; V_81 >= 0 ; V_81 -- , V_102 >>= 1 ) {
if ( V_153 & V_102 ) {
V_156 = V_81 ;
break;
}
}
V_81 = V_66 + 1 ;
for ( V_102 = ( 1 << V_81 ) ; V_81 < V_82 ; V_81 ++ , V_102 <<= 1 ) {
if ( V_153 & V_102 ) {
V_155 = V_81 ;
break;
}
}
return ( V_155 << 8 ) | V_156 ;
}
V_156 = V_66 ;
while ( V_156 != V_45 ) {
V_156 = V_43 [ V_156 ] . V_157 ;
if ( V_156 == V_45 )
break;
if ( V_153 & ( 1 << V_156 ) )
break;
}
V_155 = V_66 ;
while ( V_155 != V_45 ) {
V_155 = V_43 [ V_155 ] . V_158 ;
if ( V_155 == V_45 )
break;
if ( V_153 & ( 1 << V_155 ) )
break;
}
return ( V_155 << 8 ) | V_156 ;
}
static inline bool F_53 ( struct V_87 * V_108 ,
struct V_5 * V_6 )
{
return F_54 ( V_6 -> V_66 ) & F_48 ( V_108 , V_6 ) ;
}
static bool F_55 ( struct V_87 * V_108 ,
struct V_5 * V_6 )
{
T_1 V_156 ;
T_5 V_159 ;
T_5 V_153 ;
struct V_1 * V_2 = V_108 -> V_114 . V_160 ;
V_153 = F_48 ( V_108 , V_6 ) ;
V_159 = F_50 ( V_2 , V_6 -> V_66 , V_153 ,
V_6 -> type ) ;
V_156 = V_159 & 0xff ;
if ( V_156 == V_45 )
return true ;
V_6 -> V_66 = V_156 ;
return false ;
}
static void F_56 ( struct V_87 * V_108 ,
struct V_5 * V_6 )
{
struct V_1 * V_2 = V_108 -> V_114 . V_160 ;
if ( F_37 ( V_6 ) ) {
return;
} else if ( F_44 ( V_6 ) ) {
if ( V_108 -> V_134 == V_137 )
V_6 -> type = V_58 ;
else
V_6 -> type = V_59 ;
V_6 -> V_67 = V_161 ;
F_35 ( V_6 -> V_66 < V_34 ||
V_6 -> V_66 > V_162 ) ;
V_6 -> V_66 = V_163 [ V_6 -> V_66 ] ;
V_6 -> V_69 = false ;
} else {
V_6 -> type = F_43 ( V_6 ) ?
V_62 : V_60 ;
}
if ( F_4 ( V_6 -> V_9 ) > 1 )
V_6 -> V_9 = F_57 ( F_5 ( V_2 ) ) ;
V_6 -> V_68 = false ;
if ( ! F_53 ( V_108 , V_6 ) )
F_55 ( V_108 , V_6 ) ;
}
static inline bool F_58 ( struct V_5 * V_164 ,
struct V_5 * V_165 ,
bool V_166 )
{
bool V_167 = ( V_164 -> V_9 == V_165 -> V_9 ) && ( V_164 -> V_70 == V_165 -> V_70 ) &&
( V_164 -> V_139 == V_165 -> V_139 ) ;
if ( V_166 ) {
if ( V_164 -> V_70 || V_164 -> V_139 ) {
F_46 ( V_164 -> V_9 != V_50 , L_26 ,
V_164 -> V_70 , V_164 -> V_139 , V_164 -> V_9 ) ;
V_167 |= ( V_165 -> V_9 == V_48 || V_165 -> V_9 == V_49 ) ;
} else if ( V_165 -> V_70 || V_165 -> V_139 ) {
F_46 ( V_165 -> V_9 != V_50 , L_26 ,
V_165 -> V_70 , V_165 -> V_139 , V_165 -> V_9 ) ;
V_167 |= ( V_164 -> V_9 == V_48 || V_164 -> V_9 == V_49 ) ;
}
}
return ( V_164 -> type == V_165 -> type ) && ( V_164 -> V_67 == V_165 -> V_67 ) && ( V_164 -> V_68 == V_165 -> V_68 ) &&
( V_164 -> V_69 == V_165 -> V_69 ) && ( V_164 -> V_66 == V_165 -> V_66 ) && V_167 ;
}
static inline bool F_59 ( struct V_5 * V_164 ,
struct V_5 * V_165 )
{
bool V_167 ;
if ( V_164 -> V_70 || V_164 -> V_139 )
V_167 = ( V_165 -> V_9 == V_48 || V_165 -> V_9 == V_49 ) ;
else
V_167 = ( V_164 -> V_9 == V_165 -> V_9 ) ;
return ( V_164 -> type == V_165 -> type ) && ( V_164 -> V_67 == V_165 -> V_67 ) && ( V_164 -> V_68 == V_165 -> V_68 )
&& V_167 ;
}
static inline enum V_168 F_60 ( struct V_5 * V_6 )
{
if ( F_37 ( V_6 ) ) {
if ( V_6 -> V_9 == V_48 )
return V_169 ;
if ( V_6 -> V_9 == V_49 )
return V_170 ;
goto V_171;
}
if ( F_44 ( V_6 ) ) {
if ( V_6 -> V_9 == V_48 || V_6 -> V_70 || V_6 -> V_139 )
return V_6 -> V_68 ? V_172 :
V_173 ;
if ( V_6 -> V_9 == V_49 )
return V_6 -> V_68 ? V_174 :
V_175 ;
goto V_171;
}
if ( F_61 ( V_6 ) )
return V_6 -> V_68 ? V_176 : V_177 ;
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
struct V_5 V_189 , V_190 ;
struct V_79 * V_191 , * V_192 , * V_193 ;
T_1 V_109 = ( V_194 ) V_183 -> V_195 . V_196 [ 0 ] ;
T_2 V_197 = ( V_194 ) V_183 -> V_195 . V_196 [ 1 ] ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_87 * V_108 = & V_11 -> V_108 ;
bool V_166 = F_67 ( & V_2 -> V_198 -> V_199 ,
V_200 ) ;
if ( ! V_108 ) {
F_21 ( V_2 , L_27 ) ;
return;
} else if ( ! V_108 -> V_114 . V_160 ) {
F_21 ( V_2 , L_28 ) ;
return;
}
if ( ( V_183 -> V_201 & V_202 ) &&
! ( V_183 -> V_201 & V_203 ) )
return;
F_45 ( V_197 , V_183 -> V_134 , & V_190 ) ;
#ifdef F_68
if ( V_108 -> V_114 . V_204 ) {
int V_66 = V_190 . V_66 ;
enum V_168 V_111 ;
int V_100 , V_117 ;
V_111 = F_60 ( & V_190 ) ;
if ( F_46 ( V_111 == V_112 ,
L_29 ,
V_197 ) )
return;
if ( V_183 -> V_201 & V_203 ) {
V_100 = V_183 -> V_195 . V_205 ;
V_117 = V_183 -> V_195 . V_206 ;
} else {
V_100 = V_183 -> V_195 . V_207 [ 0 ] . V_208 ;
V_117 = ! ! ( V_183 -> V_201 & V_209 ) ;
}
V_108 -> V_114 . V_115 [ V_111 ] [ V_66 ] . V_116 += V_100 ;
V_108 -> V_114 . V_115 [ V_111 ] [ V_66 ] . V_117 += V_117 ;
F_21 ( V_2 , L_30 ,
V_197 , V_117 , V_100 ) ;
return;
}
#endif
if ( F_69 ( V_210 ,
( unsigned long ) ( V_108 -> V_211 +
( V_212 * V_213 ) ) ) ) {
int V_214 ;
F_21 ( V_2 , L_31 ) ;
for ( V_214 = 0 ; V_214 < V_93 ; V_214 ++ )
F_29 ( V_4 , V_214 ) ;
F_70 ( V_2 , V_4 , V_183 -> V_134 , false ) ;
return;
}
V_108 -> V_211 = V_210 ;
V_187 = & V_108 -> V_215 ;
V_188 = F_71 ( V_187 -> V_216 [ 0 ] ) ;
F_45 ( V_188 , V_183 -> V_134 , & V_189 ) ;
if ( ! F_58 ( & V_190 , & V_189 , V_166 ) ) {
F_21 ( V_2 ,
L_32 ,
V_197 , V_188 ) ;
V_108 -> V_217 ++ ;
if ( V_108 -> V_217 > V_218 ) {
V_108 -> V_217 = 0 ;
F_21 ( V_2 ,
L_33 ,
V_108 -> V_219 ) ;
F_72 ( V_2 , & V_108 -> V_215 , false ) ;
}
return;
} else
V_108 -> V_217 = 0 ;
if ( ! V_108 -> V_220 ) {
V_191 = & ( V_108 -> V_221 [ V_108 -> V_222 ] ) ;
V_192 = & ( V_108 -> V_221 [ 1 - V_108 -> V_222 ] ) ;
} else {
V_191 = & ( V_108 -> V_221 [ 1 - V_108 -> V_222 ] ) ;
V_192 = & ( V_108 -> V_221 [ V_108 -> V_222 ] ) ;
}
if ( F_35 ( ! F_59 ( & V_189 , & V_191 -> V_6 ) ) ) {
F_21 ( V_2 ,
L_34 ) ;
V_193 = & ( V_108 -> V_221 [ V_108 -> V_222 ] ) ;
F_20 ( V_2 , & V_193 -> V_6 , L_35 ) ;
V_193 = & ( V_108 -> V_221 [ 1 - V_108 -> V_222 ] ) ;
F_20 ( V_2 , & V_193 -> V_6 , L_36 ) ;
F_20 ( V_2 , & V_189 , L_37 ) ;
F_73 ( V_108 , true ) ;
goto V_223;
}
if ( V_183 -> V_201 & V_203 ) {
if ( V_183 -> V_195 . V_206 == 0 )
V_183 -> V_195 . V_205 = 1 ;
F_34 ( V_2 , V_108 , V_191 , V_189 . V_66 ,
V_183 -> V_195 . V_205 ,
V_183 -> V_195 . V_206 ,
V_109 ) ;
if ( V_108 -> V_219 == V_224 ) {
V_108 -> V_225 += V_183 -> V_195 . V_206 ;
V_108 -> V_226 += ( V_183 -> V_195 . V_205 -
V_183 -> V_195 . V_206 ) ;
}
} else {
V_185 = V_183 -> V_195 . V_207 [ 0 ] . V_208 - 1 ;
V_185 = F_74 ( V_185 , 15 ) ;
V_184 = ! ! ( V_183 -> V_201 & V_209 ) ;
for ( V_81 = 0 ; V_81 <= V_185 ; ++ V_81 ) {
V_188 = F_71 ( V_187 -> V_216 [ V_81 ] ) ;
F_45 ( V_188 , V_183 -> V_134 ,
& V_189 ) ;
if ( F_59 ( & V_189 , & V_191 -> V_6 ) )
V_193 = V_191 ;
else if ( F_59 ( & V_189 ,
& V_192 -> V_6 ) )
V_193 = V_192 ;
else
continue;
F_34 ( V_2 , V_108 , V_193 , V_189 . V_66 ,
1 , V_81 < V_185 ? 0 : V_184 ,
V_109 ) ;
}
if ( V_108 -> V_219 == V_224 ) {
V_108 -> V_225 += V_184 ;
V_108 -> V_226 += V_185 + ( 1 - V_184 ) ;
}
}
V_108 -> V_227 = V_188 ;
F_21 ( V_2 , L_38 , V_109 ) ;
V_223:
if ( V_4 -> V_228 [ V_183 -> V_134 ] )
F_75 ( V_2 , V_4 , V_108 , V_89 ) ;
}
static void F_76 ( void * V_229 ,
struct V_230 * V_231 ,
struct V_3 * V_4 , void * V_232 ,
struct V_233 * V_234 )
{
struct V_178 * V_179 = (struct V_178 * ) V_234 -> V_73 ;
struct V_235 * V_236 = (struct V_235 * ) V_229 ;
struct V_1 * V_2 = F_77 ( V_236 ) ;
struct V_182 * V_183 = F_78 ( V_234 ) ;
if ( ! F_7 ( V_4 ) -> V_18 )
return;
if ( ! F_79 ( V_179 -> V_180 ) ||
V_183 -> V_201 & V_237 )
return;
F_66 ( V_2 , V_4 , F_62 ( V_179 ) , V_183 ) ;
}
static void F_80 ( struct V_1 * V_2 , T_1 F_37 ,
struct V_87 * V_108 )
{
F_21 ( V_2 , L_39 ) ;
V_108 -> V_219 = V_224 ;
if ( F_37 ) {
V_108 -> V_238 = V_239 ;
V_108 -> V_240 = V_241 ;
V_108 -> V_242 = V_243 ;
} else {
V_108 -> V_238 = V_244 ;
V_108 -> V_240 = V_245 ;
V_108 -> V_242 = V_246 ;
}
V_108 -> V_247 = 0 ;
V_108 -> V_226 = 0 ;
V_108 -> V_225 = 0 ;
V_108 -> V_248 = V_210 ;
V_108 -> V_249 = 0 ;
}
static inline int F_81 ( unsigned long V_153 )
{
if ( V_153 )
return F_82 ( & V_153 , V_250 ) ;
return V_45 ;
}
static int F_83 ( struct V_87 * V_108 ,
const struct V_7 * V_111 )
{
switch ( V_111 -> V_251 ) {
case V_252 :
return V_108 -> V_253 ;
case V_254 :
return V_108 -> V_255 ;
case V_256 :
return V_108 -> V_257 ;
default:
F_35 ( 1 ) ;
}
return V_108 -> V_253 ;
}
static const T_5 * F_84 ( struct V_87 * V_108 ,
const struct V_7 * V_111 ,
T_2 V_67 )
{
const T_5 ( * V_258 ) [ V_82 ] ;
if ( F_35 ( V_111 -> V_251 != V_252 &&
V_111 -> V_251 != V_254 &&
V_111 -> V_251 != V_256 ) )
return V_259 ;
if ( V_111 -> V_251 == V_252 )
return V_259 ;
V_258 = V_260 ;
if ( V_111 -> V_251 == V_254 ) {
switch ( V_67 ) {
case V_161 :
V_258 = V_261 ;
break;
case V_262 :
V_258 = V_263 ;
break;
case V_146 :
V_258 = V_264 ;
break;
default:
F_35 ( 1 ) ;
}
} else if ( V_111 -> V_251 == V_256 ) {
switch ( V_67 ) {
case V_161 :
V_258 = V_260 ;
break;
case V_262 :
V_258 = V_265 ;
break;
case V_146 :
V_258 = V_266 ;
break;
default:
F_35 ( 1 ) ;
}
} else {
F_35 ( 1 ) ;
}
if ( ! V_111 -> V_68 && ! V_108 -> V_267 )
return V_258 [ 0 ] ;
else if ( V_111 -> V_68 && ! V_108 -> V_267 )
return V_258 [ 1 ] ;
else if ( ! V_111 -> V_68 && V_108 -> V_267 )
return V_258 [ 2 ] ;
else
return V_258 [ 3 ] ;
}
static void F_85 ( struct V_87 * V_108 ,
struct V_79 * V_80 )
{
struct V_5 * V_6 = & V_80 -> V_6 ;
const struct V_7 * V_111 = & V_268 [ V_80 -> V_111 ] ;
V_80 -> V_98 = F_84 ( V_108 , V_111 , V_6 -> V_67 ) ;
}
static T_3 F_86 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_79 * V_80 ,
unsigned long V_153 , T_6 V_66 )
{
struct V_79 * V_222 =
& ( V_108 -> V_221 [ V_108 -> V_222 ] ) ;
T_3 V_75 = V_222 -> V_83 [ V_66 ] . V_75 ;
T_5 V_269 = V_222 -> V_98 [ V_66 ] ;
const T_5 * V_270 = V_80 -> V_98 ;
T_5 V_159 ;
T_2 V_271 ;
int V_272 ;
if ( V_75 > V_273 ) {
V_271 = 100 * V_269 ;
F_21 ( V_2 ,
L_40 ,
V_75 , V_271 ) ;
} else {
V_271 = V_108 -> V_274 ;
F_21 ( V_2 ,
L_41 ,
V_75 , V_271 ) ;
}
V_272 = F_87 ( & V_153 , V_250 ) ;
while ( V_272 != V_45 ) {
if ( V_271 < ( 100 * V_270 [ V_272 ] ) )
break;
V_159 = F_50 ( V_2 , V_272 , V_153 ,
V_80 -> V_6 . type ) ;
V_272 = ( V_159 >> 8 ) & 0xff ;
}
F_21 ( V_2 , L_42 ,
V_272 , V_271 ,
V_272 != V_45 ?
100 * V_270 [ V_272 ] : V_76 ) ;
return V_272 ;
}
static T_2 F_88 ( struct V_3 * V_4 )
{
if ( V_4 -> V_275 >= V_276 )
return V_146 ;
else if ( V_4 -> V_275 >= V_277 )
return V_262 ;
return V_161 ;
}
static void F_73 ( struct V_87 * V_108 , bool V_278 )
{
struct V_79 * V_80 ;
int V_222 ;
int V_279 = 0 ;
struct V_1 * V_2 ;
V_2 = V_108 -> V_114 . V_160 ;
V_222 = V_108 -> V_222 ;
V_80 = & ( V_108 -> V_221 [ V_222 ] ) ;
if ( V_108 -> V_219 == V_224 ) {
if ( V_108 -> V_248 )
V_279 =
F_69 ( V_210 ,
( unsigned long ) ( V_108 -> V_248 +
( V_280 * V_213 ) ) ) ;
if ( V_278 ||
( V_108 -> V_226 > V_108 -> V_240 ) ||
( V_108 -> V_225 > V_108 -> V_242 ) ||
( ( ! V_108 -> V_220 ) &&
( V_108 -> V_248 ) && ( V_279 ) ) ) {
F_21 ( V_2 ,
L_43 ,
V_108 -> V_226 ,
V_108 -> V_225 ,
V_279 ) ;
V_108 -> V_219 = V_281 ;
F_21 ( V_2 ,
L_44 ) ;
V_108 -> V_226 = 0 ;
V_108 -> V_225 = 0 ;
V_108 -> V_248 = 0 ;
V_108 -> V_249 = F_54 ( V_80 -> V_111 ) ;
} else {
V_108 -> V_247 ++ ;
if ( V_108 -> V_247 >=
V_108 -> V_238 ) {
V_108 -> V_247 = 0 ;
F_21 ( V_2 ,
L_45 ) ;
F_23 ( V_2 , V_80 ) ;
}
}
if ( V_108 -> V_219 == V_281 ) {
F_23 ( V_2 , V_80 ) ;
}
}
}
static void F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
struct V_79 * V_80 )
{
F_90 ( V_2 , V_4 , V_108 , & V_80 -> V_6 ) ;
F_72 ( V_2 , & V_108 -> V_215 , false ) ;
}
static enum V_168 F_91 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_3 * V_4 ,
struct V_79 * V_80 )
{
int V_81 , V_282 , V_283 ;
enum V_168 V_284 ;
const struct V_7 * V_285 = & V_268 [ V_80 -> V_111 ] ;
const struct V_7 * V_8 ;
T_7 V_286 ;
T_1 V_287 = F_5 ( V_2 ) ;
const T_5 * V_288 ;
T_5 V_105 , V_289 ;
for ( V_81 = 0 ; V_81 < V_290 ; V_81 ++ ) {
V_284 = V_285 -> V_291 [ V_81 ] ;
if ( V_284 == V_112 )
continue;
if ( V_108 -> V_249 & F_54 ( V_284 ) ) {
F_21 ( V_2 , L_46 ,
V_284 ) ;
continue;
}
V_8 = & V_268 [ V_284 ] ;
if ( ! F_24 ( V_287 , V_8 -> V_9 ) ) {
F_21 ( V_2 ,
L_47 ,
V_284 , V_287 , V_8 -> V_9 ) ;
continue;
}
for ( V_282 = 0 ; V_282 < V_292 ; V_282 ++ ) {
V_286 = V_8 -> V_293 [ V_282 ] ;
if ( V_286 && ! V_286 ( V_2 , V_4 , & V_80 -> V_6 ,
V_8 ) )
break;
}
if ( V_282 != V_292 ) {
F_21 ( V_2 ,
L_48 ,
V_284 , V_282 ) ;
continue;
}
V_105 = V_108 -> V_274 / 100 ;
V_288 = F_84 ( V_108 , V_8 ,
F_88 ( V_4 ) ) ;
if ( F_35 ( ! V_288 ) )
continue;
V_283 = F_83 ( V_108 , V_8 ) ;
if ( V_283 == V_45 ) {
F_21 ( V_2 ,
L_49 ,
V_284 ) ;
continue;
}
V_289 = V_288 [ V_283 ] ;
if ( V_105 >= V_289 ) {
F_21 ( V_2 ,
L_50 ,
V_284 , V_289 , V_105 ) ;
continue;
}
F_21 ( V_2 ,
L_51 ,
V_284 , V_289 , V_105 ) ;
break;
}
if ( V_81 == V_290 )
return V_112 ;
return V_284 ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_3 * V_4 ,
enum V_168 V_294 )
{
struct V_79 * V_80 = & ( V_108 -> V_221 [ V_108 -> V_222 ] ) ;
struct V_79 * V_295 =
& ( V_108 -> V_221 [ ( 1 - V_108 -> V_222 ) ] ) ;
struct V_5 * V_6 = & V_295 -> V_6 ;
const struct V_7 * V_111 = & V_268 [ V_294 ] ;
const struct V_7 * V_296 = & V_268 [ V_80 -> V_111 ] ;
T_2 V_297 = ( sizeof( struct V_79 ) -
( sizeof( struct V_71 ) * V_82 ) ) ;
unsigned long V_153 = 0 ;
T_2 V_272 = 0 ;
memcpy ( V_295 , V_80 , V_297 ) ;
V_6 -> V_68 = V_111 -> V_68 ;
V_6 -> V_9 = V_111 -> V_9 ;
if ( V_111 -> V_251 == V_252 ) {
if ( V_108 -> V_134 == V_137 )
V_6 -> type = V_58 ;
else
V_6 -> type = V_59 ;
V_6 -> V_67 = V_161 ;
V_6 -> V_69 = false ;
V_153 = V_108 -> V_150 ;
} else if ( V_111 -> V_251 == V_254 ) {
V_6 -> type = V_108 -> F_41 ? V_62 : V_60 ;
V_153 = V_108 -> V_151 ;
} else if ( V_111 -> V_251 == V_256 ) {
V_6 -> type = V_108 -> F_41 ? V_63 : V_61 ;
V_153 = V_108 -> V_152 ;
} else {
F_35 ( L_52 ) ;
}
if ( V_111 -> V_251 != V_252 ) {
V_6 -> V_67 = F_88 ( V_4 ) ;
V_6 -> V_69 = V_108 -> V_69 ;
}
V_295 -> V_111 = V_294 ;
F_85 ( V_108 , V_295 ) ;
V_108 -> V_249 |= F_54 ( V_294 ) ;
if ( V_296 -> V_251 != V_111 -> V_251 ) {
V_272 = F_86 ( V_2 , V_108 , V_295 ,
V_153 , V_6 -> V_66 ) ;
if ( ( V_272 == V_45 ) ||
! ( F_54 ( V_272 ) & V_153 ) ) {
F_21 ( V_2 ,
L_53
L_54 ,
V_272 , V_153 ) ;
goto V_171;
}
V_6 -> V_66 = V_272 ;
}
F_21 ( V_2 , L_55 ,
V_294 , V_6 -> V_66 ) ;
return 0 ;
V_171:
V_6 -> type = V_57 ;
return - 1 ;
}
static enum V_298 F_93 ( struct V_1 * V_2 ,
struct V_79 * V_80 ,
T_3 V_299 , int V_156 , int V_155 ,
int V_300 ,
int V_301 , int V_302 )
{
enum V_298 V_303 = V_304 ;
if ( ( V_299 <= F_94 ( V_305 ) ) ||
( V_300 == 0 ) ) {
F_21 ( V_2 ,
L_56 ) ;
return V_306 ;
}
if ( ( V_301 == V_76 ) &&
( V_302 == V_76 ) &&
( V_155 != V_45 ) ) {
F_21 ( V_2 ,
L_57 ) ;
return V_307 ;
}
if ( ( V_302 == V_76 ) &&
( V_155 != V_45 ) &&
( V_301 != V_76 ) &&
( V_301 < V_300 ) ) {
F_21 ( V_2 ,
L_58 ) ;
return V_307 ;
}
if ( ( V_302 != V_76 ) &&
( V_302 > V_300 ) ) {
F_21 ( V_2 ,
L_59 ) ;
return V_307 ;
}
if ( ( V_301 != V_76 ) &&
( V_302 != V_76 ) &&
( V_301 < V_300 ) &&
( V_302 < V_300 ) ) {
F_21 ( V_2 ,
L_60 ) ;
return V_304 ;
}
if ( ( V_301 != V_76 ) &&
( V_301 > V_300 ) ) {
F_21 ( V_2 ,
L_61 ) ;
V_303 = V_306 ;
goto V_308;
}
if ( ( V_301 == V_76 ) &&
( V_156 != V_45 ) ) {
F_21 ( V_2 ,
L_62 ) ;
V_303 = V_306 ;
goto V_308;
}
F_21 ( V_2 , L_63 ) ;
V_308:
if ( ( V_303 == V_306 ) && ( V_156 != V_45 ) ) {
if ( V_299 >= F_94 ( V_273 ) ) {
F_21 ( V_2 ,
L_64 ) ;
V_303 = V_304 ;
} else if ( V_300 > ( 100 * V_80 -> V_98 [ V_156 ] ) ) {
F_21 ( V_2 ,
L_65 ) ;
V_303 = V_304 ;
} else {
F_21 ( V_2 , L_66 ) ;
}
}
return V_303 ;
}
static bool F_95 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_87 * V_108 )
{
if ( ! V_108 -> V_309 )
return false ;
if ( ! F_6 ( V_2 , V_4 ) )
return false ;
return true ;
}
static void F_96 ( struct V_1 * V_2 , int V_66 ,
int * V_310 , int * V_311 )
{
* V_310 = V_66 + V_312 ;
if ( * V_310 > V_118 )
* V_310 = V_313 ;
* V_311 = V_66 - V_312 ;
if ( * V_311 < 0 )
* V_311 = V_313 ;
}
static bool F_97 ( struct V_1 * V_2 , struct V_314 * V_18 ,
struct V_5 * V_6 , enum V_133 V_134 )
{
int V_66 = V_6 -> V_66 ;
bool V_315 = ( V_316 . V_317 == V_318 ) ;
bool V_319 = ( V_18 -> type == V_320 &&
! V_18 -> V_321 . V_322 ) ;
F_21 ( V_2 , L_67 ,
V_315 , V_319 ) ;
if ( ( V_315 || V_319 ) &&
! F_98 ( V_2 , V_134 ) )
return false ;
F_21 ( V_2 , L_68 , V_6 -> type ) ;
if ( F_37 ( V_6 ) )
return V_66 == V_323 ;
if ( F_38 ( V_6 ) )
return V_66 == V_324 ;
if ( F_41 ( V_6 ) )
return V_66 == V_324 ||
V_66 == V_325 ||
V_66 == V_162 ;
F_35 ( 1 ) ;
return false ;
}
static enum V_326 F_99 ( struct V_1 * V_2 ,
T_3 V_299 , int V_327 , int V_328 ,
int V_300 ,
int V_329 , int V_330 )
{
if ( V_300 == V_76 ) {
F_21 ( V_2 , L_69 ) ;
return V_331 ;
}
if ( V_299 <= F_94 ( V_332 ) ||
V_300 == 0 ) {
F_21 ( V_2 , L_70 ) ;
return V_333 ;
}
if ( V_327 != V_313 ) {
if ( V_329 == V_76 &&
( V_330 == V_76 ||
V_300 >= V_330 ) ) {
F_21 ( V_2 ,
L_71 ) ;
return V_334 ;
}
if ( V_329 > V_300 ) {
F_21 ( V_2 ,
L_72 ) ;
return V_334 ;
}
}
if ( V_299 < F_94 ( V_335 ) &&
V_328 != V_313 ) {
if ( V_329 == V_76 &&
V_330 != V_76 &&
V_300 < V_330 ) {
F_21 ( V_2 ,
L_73 ) ;
return V_336 ;
}
if ( V_329 < V_300 &&
( V_330 == V_76 ||
V_330 > V_300 ) ) {
F_21 ( V_2 ,
L_74 ) ;
return V_336 ;
}
}
F_21 ( V_2 , L_75 ) ;
return V_331 ;
}
static bool F_100 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
struct V_79 * V_80 )
{
struct V_10 * V_337 = F_7 ( V_4 ) ;
struct V_314 * V_18 = V_337 -> V_18 ;
struct V_338 * V_339 ;
enum V_133 V_134 ;
struct V_71 * V_72 ;
struct V_5 * V_6 = & V_80 -> V_6 ;
enum V_326 V_303 ;
T_3 V_299 ;
T_1 V_340 = V_108 -> V_215 . V_341 ;
int V_300 ;
int V_327 , V_328 ;
int V_329 = V_76 , V_330 = V_76 ;
#ifdef F_68
if ( V_108 -> V_114 . V_342 <= V_118 ) {
F_21 ( V_2 , L_76 ,
V_108 -> V_114 . V_342 ) ;
V_108 -> V_215 . V_341 = V_108 -> V_114 . V_342 ;
return V_340 != V_108 -> V_114 . V_342 ;
}
#endif
F_101 () ;
V_339 = F_102 ( V_18 -> V_339 ) ;
if ( F_103 ( ! V_339 ) )
V_134 = V_343 ;
else
V_134 = V_339 -> V_344 . V_345 -> V_134 ;
F_104 () ;
if ( ! F_97 ( V_2 , V_18 , V_6 , V_134 ) ) {
F_21 ( V_2 ,
L_77 ) ;
V_108 -> V_215 . V_341 = V_346 ;
return V_340 != V_346 ;
}
F_96 ( V_2 , V_340 , & V_327 , & V_328 ) ;
V_72 = V_80 -> V_84 ;
V_299 = V_72 [ V_340 ] . V_75 ;
V_300 = V_72 [ V_340 ] . V_78 ;
if ( V_327 != V_313 )
V_329 = V_72 [ V_327 ] . V_78 ;
if ( V_328 != V_313 )
V_330 = V_72 [ V_328 ] . V_78 ;
F_21 ( V_2 ,
L_78 ,
V_340 , V_300 , V_299 , V_327 , V_328 ,
V_329 , V_330 ) ;
V_303 = F_99 ( V_2 , V_299 , V_327 , V_328 ,
V_300 , V_329 , V_330 ) ;
if ( V_327 == V_313 && V_303 == V_334 ) {
F_21 ( V_2 , L_79 ) ;
V_303 = V_331 ;
} else if ( V_328 == V_313 &&
( V_303 == V_336 ||
V_303 == V_333 ) ) {
F_21 ( V_2 , L_80 ) ;
V_303 = V_331 ;
}
switch ( V_303 ) {
case V_334 :
V_108 -> V_215 . V_341 = V_327 ;
return true ;
case V_336 :
V_108 -> V_215 . V_341 = V_328 ;
return true ;
case V_333 :
V_108 -> V_215 . V_341 = V_346 ;
return true ;
case V_331 :
break;
}
return false ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
int V_89 )
{
int V_156 = V_45 ;
int V_155 = V_45 ;
int V_66 ;
struct V_71 * V_72 = NULL ;
int V_300 = V_76 ;
int V_301 = V_76 ;
int V_302 = V_76 ;
T_2 V_104 ;
enum V_298 V_347 = V_304 ;
T_5 V_153 ;
T_1 V_348 = 0 ;
struct V_79 * V_80 , * V_349 ;
T_1 V_222 = 0 ;
T_1 V_350 = 0 ;
T_5 V_159 ;
T_3 V_299 ;
T_1 V_351 = V_108 -> V_267 ;
struct V_10 * V_352 = F_7 ( V_4 ) ;
struct V_353 * V_354 ;
struct V_5 * V_6 ;
V_108 -> V_267 = ! ! V_352 -> V_355 ;
if ( ! V_108 -> V_220 )
V_222 = V_108 -> V_222 ;
else
V_222 = 1 - V_108 -> V_222 ;
V_80 = & ( V_108 -> V_221 [ V_222 ] ) ;
V_6 = & V_80 -> V_6 ;
if ( V_351 != V_108 -> V_267 ) {
F_21 ( V_2 ,
L_81 ,
V_351 , V_108 -> V_267 ) ;
F_85 ( V_108 , V_80 ) ;
F_23 ( V_2 , V_80 ) ;
}
V_66 = V_6 -> V_66 ;
V_153 = F_48 ( V_108 , V_6 ) ;
if ( ! ( F_54 ( V_66 ) & V_153 ) ) {
F_28 ( V_2 , L_82 ) ;
if ( V_108 -> V_220 ) {
V_6 -> type = V_57 ;
V_108 -> V_220 = 0 ;
V_80 = & ( V_108 -> V_221 [ V_108 -> V_222 ] ) ;
F_89 ( V_2 , V_4 , V_108 , V_80 ) ;
}
return;
}
if ( ! V_80 -> V_98 ) {
F_28 ( V_2 , L_83 ) ;
return;
}
V_72 = & ( V_80 -> V_83 [ V_66 ] ) ;
V_104 = V_72 -> V_77 - V_72 -> V_74 ;
if ( ( V_104 < V_106 ) &&
( V_72 -> V_74 < V_107 ) ) {
F_21 ( V_2 ,
L_84 ,
F_19 ( V_6 -> type ) ,
V_66 , V_72 -> V_74 , V_72 -> V_77 ) ;
V_72 -> V_78 = V_76 ;
F_73 ( V_108 , false ) ;
return;
}
if ( V_108 -> V_220 ) {
if ( V_72 -> V_78 > V_108 -> V_274 ) {
F_21 ( V_2 ,
L_85
L_86 ,
V_72 -> V_75 ,
V_72 -> V_78 ,
V_108 -> V_274 ) ;
V_108 -> V_222 = V_222 ;
V_300 = V_72 -> V_78 ;
} else {
F_21 ( V_2 ,
L_87
L_86 ,
V_72 -> V_75 ,
V_72 -> V_78 ,
V_108 -> V_274 ) ;
V_6 -> type = V_57 ;
V_222 = V_108 -> V_222 ;
V_80 = & ( V_108 -> V_221 [ V_222 ] ) ;
V_66 = V_80 -> V_6 . V_66 ;
V_300 = V_108 -> V_274 ;
V_348 = 1 ;
}
V_108 -> V_220 = 0 ;
V_350 = 1 ;
goto V_356;
}
V_159 = F_50 ( V_2 , V_66 , V_153 , V_6 -> type ) ;
V_156 = V_159 & 0xff ;
V_155 = ( V_159 >> 8 ) & 0xff ;
V_299 = V_72 -> V_75 ;
V_300 = V_72 -> V_78 ;
if ( V_156 != V_45 )
V_301 = V_80 -> V_83 [ V_156 ] . V_78 ;
if ( V_155 != V_45 )
V_302 = V_80 -> V_83 [ V_155 ] . V_78 ;
F_21 ( V_2 ,
L_88 ,
F_19 ( V_6 -> type ) , V_66 , V_300 , V_299 ,
V_156 , V_155 , V_301 , V_302 ) ;
V_347 = F_93 ( V_2 , V_80 , V_299 , V_156 , V_155 ,
V_300 , V_301 , V_302 ) ;
if ( F_61 ( V_6 ) &&
! F_6 ( V_2 , V_4 ) ) {
F_21 ( V_2 ,
L_89 ) ;
F_73 ( V_108 , true ) ;
goto V_356;
}
switch ( V_347 ) {
case V_306 :
if ( V_156 != V_45 ) {
V_348 = 1 ;
V_66 = V_156 ;
} else {
F_21 ( V_2 ,
L_90 ) ;
}
break;
case V_307 :
if ( V_155 != V_45 ) {
V_348 = 1 ;
V_66 = V_155 ;
} else {
F_21 ( V_2 ,
L_91 ) ;
}
break;
case V_304 :
if ( V_108 -> V_219 == V_224 )
V_348 = F_100 ( V_2 , V_4 , V_108 , V_80 ) ;
break;
default:
break;
}
V_356:
if ( V_348 ) {
V_80 -> V_6 . V_66 = V_66 ;
F_89 ( V_2 , V_4 , V_108 , V_80 ) ;
}
F_73 ( V_108 , false ) ;
if ( ! V_348 && ! V_350 &&
V_108 -> V_219 == V_281
&& V_72 -> V_77 ) {
enum V_168 V_357 ;
V_108 -> V_274 = V_300 ;
F_21 ( V_2 ,
L_92 ,
V_348 , V_350 , V_108 -> V_219 ,
V_72 -> V_77 ) ;
V_357 = F_91 ( V_2 , V_108 , V_4 , V_80 ) ;
if ( V_357 != V_112 ) {
int V_90 = F_92 ( V_2 , V_108 , V_4 ,
V_357 ) ;
if ( ! V_90 )
V_108 -> V_220 = 1 ;
} else {
F_21 ( V_2 ,
L_93 ) ;
V_108 -> V_219 = V_358 ;
}
if ( V_108 -> V_220 ) {
V_80 = & ( V_108 -> V_221 [ ( 1 - V_108 -> V_222 ) ] ) ;
F_23 ( V_2 , V_80 ) ;
V_66 = V_80 -> V_6 . V_66 ;
F_20 ( V_2 , & V_80 -> V_6 ,
L_94 ) ;
F_89 ( V_2 , V_4 , V_108 , V_80 ) ;
} else {
V_350 = 1 ;
}
}
if ( V_350 && V_108 -> V_219 == V_358 ) {
V_349 = & ( V_108 -> V_221 [ V_108 -> V_222 ] ) ;
if ( F_37 ( & V_349 -> V_6 ) ) {
F_21 ( V_2 , L_95 ) ;
if ( V_89 != V_93 ) {
V_354 = & V_352 -> V_354 [ V_89 ] ;
if ( V_354 -> V_359 != V_360 ) {
F_21 ( V_2 ,
L_96 ,
V_89 ) ;
F_29 ( V_4 , V_89 ) ;
}
}
F_80 ( V_2 , 1 , V_108 ) ;
} else {
if ( ( V_108 -> V_274 > V_361 ) &&
( V_108 -> V_362 & ( 1 << V_89 ) ) &&
( V_89 != V_93 ) ) {
V_354 = & V_352 -> V_354 [ V_89 ] ;
if ( V_354 -> V_359 == V_360 ) {
F_21 ( V_2 ,
L_97 ,
V_89 ) ;
F_30 ( V_2 , V_89 ,
V_108 , V_4 ) ;
}
}
F_80 ( V_2 , 0 , V_108 ) ;
}
}
}
static void F_105 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
enum V_133 V_134 ,
struct V_5 * V_6 )
{
int V_81 , V_363 ;
T_6 V_364 = V_365 ;
T_1 V_366 = V_47 ;
T_1 V_367 = F_5 ( V_2 ) ;
const struct V_368 * V_369 ;
for ( V_81 = 0 ; V_81 < F_17 ( V_108 -> V_114 . V_370 ) ; V_81 ++ ) {
if ( ! ( V_108 -> V_114 . V_371 & F_54 ( V_81 ) ) )
continue;
if ( V_108 -> V_114 . V_370 [ V_81 ] > V_364 ) {
V_364 = V_108 -> V_114 . V_370 [ V_81 ] ;
V_366 = F_54 ( V_81 ) ;
}
}
F_21 ( V_2 , L_98 ,
F_18 ( V_366 ) , V_364 ) ;
if ( V_366 != V_48 && V_366 != V_49 )
V_6 -> V_9 = F_57 ( V_367 ) ;
else
V_6 -> V_9 = V_366 ;
V_6 -> V_68 = false ;
V_6 -> V_69 = false ;
V_6 -> V_67 = V_161 ;
V_6 -> V_66 = F_87 ( & V_108 -> V_150 ,
V_250 ) ;
if ( V_134 == V_137 ) {
V_6 -> type = V_58 ;
V_369 = V_372 ;
V_363 = F_17 ( V_372 ) ;
} else {
V_6 -> type = V_59 ;
V_369 = V_373 ;
V_363 = F_17 ( V_373 ) ;
}
if ( V_374 ) {
for ( V_81 = 0 ; V_81 < V_363 ; V_81 ++ ) {
int V_272 = V_369 [ V_81 ] . V_272 ;
if ( ( V_364 >= V_369 [ V_81 ] . V_375 ) &&
( F_54 ( V_272 ) & V_108 -> V_150 ) ) {
V_6 -> V_66 = V_272 ;
break;
}
}
}
F_21 ( V_2 , L_99 , V_6 -> V_66 ,
F_18 ( V_6 -> V_9 ) ) ;
}
void F_106 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_376 * V_377 )
{
V_108 -> V_114 . V_371 = V_377 -> V_371 ;
V_108 -> V_114 . V_370 [ 0 ] = V_377 -> V_370 [ 0 ] ;
V_108 -> V_114 . V_370 [ 1 ] = V_377 -> V_370 [ 1 ] ;
V_108 -> V_114 . V_370 [ 2 ] = V_377 -> V_370 [ 2 ] ;
}
static void F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
enum V_133 V_134 ,
bool V_378 )
{
struct V_79 * V_80 ;
struct V_5 * V_6 ;
T_1 V_222 = 0 ;
if ( ! V_4 || ! V_108 )
return;
if ( ! V_108 -> V_220 )
V_222 = V_108 -> V_222 ;
else
V_222 = 1 - V_108 -> V_222 ;
V_80 = & ( V_108 -> V_221 [ V_222 ] ) ;
V_6 = & V_80 -> V_6 ;
F_105 ( V_2 , V_108 , V_134 , V_6 ) ;
F_35 ( V_6 -> V_9 != V_48 && V_6 -> V_9 != V_49 ) ;
if ( V_6 -> V_9 == V_48 )
V_80 -> V_111 = V_169 ;
else
V_80 -> V_111 = V_170 ;
F_85 ( V_108 , V_80 ) ;
F_90 ( V_2 , V_4 , V_108 , V_6 ) ;
F_72 ( V_2 , & V_108 -> V_215 , V_378 ) ;
}
static void F_108 ( void * V_229 , struct V_3 * V_4 , void * V_337 ,
struct V_379 * V_380 )
{
struct V_233 * V_234 = V_380 -> V_234 ;
struct V_235 * V_236 V_381 =
(struct V_235 * ) V_229 ;
struct V_1 * V_2 V_381 = F_77 ( V_236 ) ;
struct V_182 * V_183 = F_78 ( V_234 ) ;
struct V_87 * V_108 = V_337 ;
if ( V_4 && ! F_7 ( V_4 ) -> V_18 ) {
V_4 = NULL ;
V_337 = NULL ;
}
if ( V_108 && ! V_108 -> V_114 . V_160 ) {
F_21 ( V_2 , L_28 ) ;
V_337 = NULL ;
}
if ( F_109 ( V_4 , V_337 , V_380 ) )
return;
F_110 ( V_108 -> V_227 ,
V_183 -> V_134 , & V_183 -> V_382 . V_207 [ 0 ] ) ;
V_183 -> V_382 . V_207 [ 0 ] . V_208 = 1 ;
}
static void * F_111 ( void * V_383 , struct V_3 * V_4 ,
T_8 V_384 )
{
struct V_10 * V_352 = F_7 ( V_4 ) ;
struct V_235 * V_236 = (struct V_235 * ) V_383 ;
struct V_1 * V_2 = F_77 ( V_236 ) ;
struct V_87 * V_108 = & V_352 -> V_108 ;
F_21 ( V_2 , L_100 ) ;
V_108 -> V_114 . V_160 = V_2 ;
#ifdef F_68
V_108 -> V_114 . V_204 = 0 ;
V_108 -> V_114 . V_342 = V_313 ;
V_108 -> V_114 . V_385 = V_386 ;
#endif
V_108 -> V_114 . V_371 = 0 ;
memset ( V_108 -> V_114 . V_370 , 0 , sizeof( V_108 -> V_114 . V_370 ) ) ;
return & V_352 -> V_108 ;
}
static int F_112 ( struct V_23 * V_24 ,
int V_136 )
{
T_5 V_387 = F_113 ( V_24 -> V_388 . V_389 ) &
( 0x3 << ( 2 * ( V_136 - 1 ) ) ) ;
V_387 >>= ( 2 * ( V_136 - 1 ) ) ;
if ( V_387 == V_390 )
return V_324 ;
else if ( V_387 == V_391 )
return V_325 ;
else if ( V_387 == V_392 )
return V_162 ;
F_35 ( V_387 != V_393 ) ;
return - 1 ;
}
static void F_114 ( struct V_3 * V_4 ,
struct V_23 * V_24 ,
struct V_87 * V_108 )
{
int V_81 ;
int V_394 = F_112 ( V_24 , 1 ) ;
if ( V_394 >= V_34 ) {
for ( V_81 = V_34 ; V_81 <= V_394 ; V_81 ++ ) {
if ( V_81 == V_35 )
continue;
if ( V_81 == V_162 &&
V_4 -> V_275 == V_395 )
continue;
V_108 -> V_151 |= F_54 ( V_81 ) ;
}
}
if ( V_4 -> V_396 < 2 )
return;
V_394 = F_112 ( V_24 , 2 ) ;
if ( V_394 >= V_34 ) {
for ( V_81 = V_34 ; V_81 <= V_394 ; V_81 ++ ) {
if ( V_81 == V_35 )
continue;
if ( V_81 == V_162 &&
V_4 -> V_275 == V_395 )
continue;
V_108 -> V_152 |= F_54 ( V_81 ) ;
}
}
}
static void F_115 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
struct V_22 * V_14 )
{
V_108 -> V_151 = V_14 -> V_397 . V_398 [ 0 ] << 1 ;
V_108 -> V_151 |= V_14 -> V_397 . V_398 [ 0 ] & 0x1 ;
V_108 -> V_151 &= ~ ( ( T_5 ) 0x2 ) ;
V_108 -> V_151 <<= V_399 ;
V_108 -> V_152 = V_14 -> V_397 . V_398 [ 1 ] << 1 ;
V_108 -> V_152 |= V_14 -> V_397 . V_398 [ 1 ] & 0x1 ;
V_108 -> V_152 &= ~ ( ( T_5 ) 0x2 ) ;
V_108 -> V_152 <<= V_399 ;
if ( V_2 -> V_400 -> V_401 -> V_69 &&
( V_14 -> V_25 & V_402 ) )
V_108 -> V_69 = true ;
if ( V_2 -> V_400 -> V_401 -> V_70 &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_14 -> V_25 & V_403 ) )
V_108 -> V_309 = true ;
V_108 -> F_41 = false ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
struct V_23 * V_24 )
{
F_114 ( V_4 , V_24 , V_108 ) ;
if ( V_2 -> V_400 -> V_401 -> V_69 &&
( V_24 -> V_25 & V_404 ) )
V_108 -> V_69 = true ;
if ( V_2 -> V_400 -> V_401 -> V_70 &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_24 -> V_25 & V_405 ) )
V_108 -> V_309 = true ;
if ( F_117 ( & V_2 -> V_198 -> V_199 , V_406 ) &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_24 -> V_25 & V_407 ) )
V_108 -> V_408 = true ;
V_108 -> F_41 = true ;
}
static void F_118 ( struct V_1 * V_2 )
{
F_119 ( & V_2 -> V_409 ) ;
memset ( & V_2 -> V_410 , 0 , sizeof( V_2 -> V_410 ) ) ;
F_120 ( & V_2 -> V_409 ) ;
}
void F_121 ( struct V_1 * V_2 , T_2 V_6 , bool V_411 )
{
T_1 V_136 = 0 , V_397 = 0 ;
F_122 ( & V_2 -> V_409 ) ;
if ( V_411 )
V_2 -> V_410 . V_412 ++ ;
V_2 -> V_410 . V_413 ++ ;
switch ( V_6 & V_140 ) {
case V_161 :
V_2 -> V_410 . V_414 ++ ;
break;
case V_262 :
V_2 -> V_410 . V_415 ++ ;
break;
case V_146 :
V_2 -> V_410 . V_416 ++ ;
break;
default:
F_46 ( 1 , L_101 , V_6 ) ;
}
if ( V_6 & V_32 ) {
V_2 -> V_410 . V_417 ++ ;
V_397 = V_6 & V_33 ;
V_136 = ( ( V_6 & V_141 ) >> V_142 ) + 1 ;
} else if ( V_6 & V_38 ) {
V_2 -> V_410 . V_418 ++ ;
V_397 = V_6 & V_39 ;
V_136 = ( ( V_6 & V_143 ) >>
V_144 ) + 1 ;
} else {
V_2 -> V_410 . V_419 ++ ;
}
if ( V_136 == 1 )
V_2 -> V_410 . V_420 ++ ;
else if ( V_136 == 2 )
V_2 -> V_410 . V_421 ++ ;
if ( V_6 & V_131 )
V_2 -> V_410 . V_422 ++ ;
else
V_2 -> V_410 . V_423 ++ ;
V_2 -> V_410 . V_424 [ V_2 -> V_410 . V_425 ] = V_6 ;
V_2 -> V_410 . V_425 =
( V_2 -> V_410 . V_425 + 1 ) %
F_17 ( V_2 -> V_410 . V_424 ) ;
F_123 ( & V_2 -> V_409 ) ;
}
void F_70 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_133 V_134 , bool V_378 )
{
int V_81 , V_282 ;
struct V_426 * V_427 = V_2 -> V_427 ;
struct V_22 * V_14 = & V_4 -> V_14 ;
struct V_23 * V_24 = & V_4 -> V_24 ;
struct V_10 * V_352 = F_7 ( V_4 ) ;
struct V_87 * V_108 = & V_352 -> V_108 ;
struct V_230 * V_231 ;
unsigned long V_428 ;
memset ( V_108 , 0 , F_124 ( F_125 ( * V_108 ) , V_114 ) ) ;
V_231 = V_427 -> V_429 -> V_430 [ V_134 ] ;
V_108 -> V_215 . V_431 = V_352 -> V_431 ;
for ( V_282 = 0 ; V_282 < V_432 ; V_282 ++ )
F_23 ( V_2 , & V_108 -> V_221 [ V_282 ] ) ;
V_108 -> V_248 = 0 ;
V_108 -> V_211 = V_210 ;
F_21 ( V_2 ,
L_102 ,
V_352 -> V_431 ) ;
V_108 -> V_217 = V_218 ;
V_108 -> V_134 = V_231 -> V_134 ;
V_428 = V_4 -> V_228 [ V_231 -> V_134 ] ;
V_108 -> V_150 = 0 ;
F_126 (i, &supp, BITS_PER_LONG)
V_108 -> V_150 |= F_54 ( V_231 -> V_433 [ V_81 ] . V_434 ) ;
if ( ! V_24 || ! V_24 -> V_435 )
F_115 ( V_2 , V_4 , V_108 , V_14 ) ;
else
F_116 ( V_2 , V_4 , V_108 , V_24 ) ;
if ( V_436 && V_352 -> V_18 -> V_19 )
V_108 -> V_152 = 0 ;
V_108 -> V_253 =
F_81 ( V_108 -> V_150 ) ;
V_108 -> V_255 =
F_81 ( V_108 -> V_151 ) ;
V_108 -> V_257 =
F_81 ( V_108 -> V_152 ) ;
F_21 ( V_2 ,
L_103 ,
V_108 -> V_150 ,
V_108 -> V_151 ,
V_108 -> V_152 ,
V_108 -> F_41 , V_108 -> V_69 , V_108 -> V_309 ,
V_108 -> V_408 ) ;
F_21 ( V_2 , L_104 ,
V_108 -> V_253 ,
V_108 -> V_255 ,
V_108 -> V_257 ) ;
V_108 -> V_215 . V_437 =
F_57 ( F_5 ( V_2 ) ) ;
V_108 -> V_215 . V_438 = V_50 ;
V_108 -> V_362 = V_439 ;
V_108 -> V_267 = 0 ;
#ifdef F_127
F_118 ( V_2 ) ;
#endif
F_107 ( V_2 , V_4 , V_108 , V_134 , V_378 ) ;
}
static void F_128 ( void * V_229 ,
struct V_230 * V_231 ,
struct V_440 * V_441 ,
struct V_3 * V_4 , void * V_232 ,
T_2 V_442 )
{
T_1 V_89 ;
struct V_235 * V_236 =
(struct V_235 * ) V_229 ;
struct V_1 * V_2 = F_77 ( V_236 ) ;
if ( ! F_7 ( V_4 ) -> V_18 )
return;
for ( V_89 = 0 ; V_89 < V_93 ; V_89 ++ )
F_29 ( V_4 , V_89 ) ;
F_70 ( V_2 , V_4 , V_231 -> V_134 , false ) ;
}
static void F_129 ( struct V_1 * V_2 ,
struct V_186 * V_443 ,
enum V_133 V_134 ,
T_2 V_119 )
{
struct V_5 V_6 ;
int V_81 ;
int V_444 = F_17 ( V_443 -> V_216 ) ;
T_9 V_445 = F_130 ( V_119 ) ;
T_1 V_9 = ( V_119 & V_121 ) >> V_120 ;
for ( V_81 = 0 ; V_81 < V_444 ; V_81 ++ )
V_443 -> V_216 [ V_81 ] = V_445 ;
F_45 ( V_119 , V_134 , & V_6 ) ;
if ( F_61 ( & V_6 ) )
V_443 -> V_446 = V_444 - 1 ;
else
V_443 -> V_446 = 0 ;
V_443 -> V_341 = 0 ;
if ( F_4 ( V_9 ) == 1 )
V_443 -> V_437 = V_9 ;
V_443 -> V_447 = V_448 ;
}
static void F_131 ( struct V_1 * V_2 ,
struct V_87 * V_108 ,
struct V_5 * V_6 ,
T_9 * V_216 , int * V_449 ,
int V_444 , int V_450 ,
T_1 V_367 , bool V_451 )
{
int V_81 , V_282 ;
T_9 V_119 ;
bool V_452 = false ;
int V_453 = V_6 -> V_66 ;
int V_454 = V_455 ;
int V_66 = * V_449 ;
for ( V_81 = 0 ; V_81 < V_444 && V_66 < V_454 ; V_81 ++ ) {
for ( V_282 = 0 ; V_282 < V_450 && V_66 < V_454 ; V_282 ++ , V_66 ++ ) {
V_119 = F_130 ( F_36 ( V_2 ,
V_6 ) ) ;
V_216 [ V_66 ] = V_119 ;
if ( V_451 )
F_47 ( V_367 , V_6 ) ;
}
V_453 = V_6 -> V_66 ;
V_452 = F_55 ( V_108 , V_6 ) ;
if ( V_452 && ! F_37 ( V_6 ) )
break;
}
if ( ! V_452 && ! F_37 ( V_6 ) )
V_6 -> V_66 = V_453 ;
* V_449 = V_66 ;
}
static void F_132 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
const struct V_5 * V_456 )
{
struct V_5 V_6 ;
int V_444 , V_450 , V_66 = 0 ;
T_1 V_367 = 0 ;
struct V_186 * V_443 = & V_108 -> V_215 ;
bool V_451 = false ;
memcpy ( & V_6 , V_456 , sizeof( V_6 ) ) ;
V_367 = F_5 ( V_2 ) ;
if ( ! F_67 ( & V_2 -> V_198 -> V_199 , V_200 ) &&
F_95 ( V_2 , V_4 , V_108 ) )
V_6 . V_70 = true ;
if ( F_44 ( & V_6 ) ) {
V_444 = V_457 ;
V_450 = V_458 ;
} else if ( F_61 ( & V_6 ) ) {
V_444 = V_459 ;
V_450 = V_458 ;
} else {
V_444 = V_460 ;
V_450 = V_461 ;
V_451 = true ;
}
F_131 ( V_2 , V_108 , & V_6 , V_443 -> V_216 , & V_66 ,
V_444 , V_450 , V_367 ,
V_451 ) ;
F_56 ( V_108 , & V_6 ) ;
if ( F_44 ( & V_6 ) ) {
V_444 = V_462 ;
V_450 = V_463 ;
V_443 -> V_446 = V_66 ;
} else if ( F_37 ( & V_6 ) ) {
V_444 = V_464 ;
V_450 = V_465 ;
} else {
F_35 ( 1 ) ;
}
V_451 = true ;
F_131 ( V_2 , V_108 , & V_6 , V_443 -> V_216 , & V_66 ,
V_444 , V_450 , V_367 ,
V_451 ) ;
F_56 ( V_108 , & V_6 ) ;
V_444 = V_464 ;
V_450 = V_465 ;
F_131 ( V_2 , V_108 , & V_6 , V_443 -> V_216 , & V_66 ,
V_444 , V_450 , V_367 ,
V_451 ) ;
}
static void F_133 ( void * V_466 ,
struct V_3 * V_4 )
{
struct V_467 * V_73 = V_466 ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_186 * V_443 = & V_11 -> V_108 . V_215 ;
T_2 V_468 = F_71 ( V_443 -> V_468 ) ;
if ( V_4 == V_73 -> V_469 )
return;
if ( V_468 & V_470 ) {
F_35 ( V_73 -> V_471 != NULL ) ;
V_73 -> V_471 = V_11 ;
}
}
static int F_134 ( struct V_10 * V_4 )
{
int V_472 = - 1 ;
enum V_473 V_474 = F_135 ( V_4 -> V_18 ) ;
switch ( V_474 ) {
case V_475 :
case V_476 :
V_472 = 3 ;
break;
case V_477 :
V_472 = 2 ;
break;
case V_320 :
V_472 = 1 ;
break;
default:
F_46 ( true , L_105 , V_474 , V_4 -> V_431 ) ;
V_472 = - 1 ;
}
return V_472 ;
}
static int F_136 ( struct V_10 * V_478 ,
struct V_10 * V_479 )
{
int V_480 = F_134 ( V_478 ) ;
int V_481 = F_134 ( V_479 ) ;
if ( V_480 > V_481 )
return 1 ;
if ( V_480 < V_481 )
return - 1 ;
return 0 ;
}
static void F_137 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
const struct V_5 * V_456 )
{
struct V_186 * V_443 = & V_108 -> V_215 ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_467 V_73 = {
. V_469 = V_4 ,
. V_471 = NULL ,
} ;
struct V_10 * V_471 = NULL ;
T_2 V_468 = V_482 ;
if ( ! F_6 ( V_2 , V_4 ) )
goto V_308;
#ifdef F_68
if ( V_108 -> V_114 . V_385 == V_483 )
V_468 |= ( V_484 | V_485 ) ;
else if ( V_108 -> V_114 . V_385 == V_486 )
V_468 |= ( V_470 | V_485 ) ;
if ( V_108 -> V_114 . V_385 != V_386 ) {
F_21 ( V_2 , L_106 ,
V_108 -> V_114 . V_385 ) ;
goto V_308;
}
#endif
if ( V_108 -> V_309 )
V_468 |= V_484 ;
if ( ! V_108 -> V_408 )
goto V_308;
F_138 ( V_2 -> V_427 ,
F_133 ,
& V_73 ) ;
V_471 = V_73 . V_471 ;
if ( ! V_471 ) {
F_21 ( V_2 , L_107 ) ;
V_468 |= V_470 ;
goto V_308;
}
F_21 ( V_2 , L_108 ,
V_471 -> V_431 ) ;
if ( F_136 ( V_11 , V_471 ) > 0 ) {
struct V_186 * V_487 = & V_471 -> V_108 . V_215 ;
T_2 V_488 = F_71 ( V_487 -> V_468 ) ;
V_488 &= ~ V_470 ;
V_487 -> V_468 = F_130 ( V_488 ) ;
F_72 ( V_2 , V_487 , false ) ;
V_468 |= V_470 ;
F_21 ( V_2 ,
L_109 ,
V_471 -> V_431 ) ;
}
V_308:
V_443 -> V_468 = F_130 ( V_468 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_87 * V_108 ,
const struct V_5 * V_456 )
{
struct V_186 * V_443 = & V_108 -> V_215 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_443 -> V_489 = V_490 ;
V_443 -> V_491 =
F_139 ( V_492 ) ;
#ifdef F_68
if ( V_108 -> V_114 . V_204 ) {
F_129 ( V_2 , V_443 ,
V_108 -> V_134 ,
V_108 -> V_114 . V_204 ) ;
return;
}
#endif
if ( F_35 ( ! V_4 || ! V_456 ) )
return;
F_132 ( V_2 , V_4 , V_108 , V_456 ) ;
if ( F_67 ( & V_2 -> V_198 -> V_199 , V_200 ) )
F_137 ( V_2 , V_4 , V_108 , V_456 ) ;
V_11 = F_7 ( V_4 ) ;
V_13 = F_8 ( V_11 -> V_18 ) ;
if ( F_4 ( V_456 -> V_9 ) == 1 )
V_443 -> V_437 = V_456 -> V_9 ;
V_443 -> V_447 = V_11 -> V_493 ;
if ( F_9 ( V_13 ) ) {
V_443 -> V_447 -- ;
if ( V_2 -> V_494 )
V_443 -> V_447 =
F_74 ( V_443 -> V_447 ,
V_2 -> V_494 ) ;
}
if ( V_11 -> V_18 -> V_19 )
V_443 -> V_201 |= V_495 ;
V_443 -> V_491 =
F_139 ( F_140 ( V_2 , V_4 ) ) ;
}
static void * F_141 ( struct V_426 * V_427 , struct V_496 * V_497 )
{
return V_427 -> V_498 ;
}
static void F_142 ( void * V_383 )
{
return;
}
static void F_143 ( void * V_229 , struct V_3 * V_4 ,
void * V_337 )
{
struct V_235 * V_236 V_381 = V_229 ;
struct V_1 * V_2 V_381 = F_77 ( V_236 ) ;
F_21 ( V_2 , L_110 ) ;
F_21 ( V_2 , L_111 ) ;
}
int F_144 ( char * V_499 , const T_2 V_6 )
{
char * type , * V_67 ;
T_1 V_397 = 0 , V_136 = 0 ;
T_1 V_9 = ( V_6 & V_121 ) >> V_120 ;
if ( ! ( V_6 & V_32 ) &&
! ( V_6 & V_38 ) ) {
int V_66 = F_16 ( V_6 ) ;
return sprintf ( V_499 , L_112 ,
F_18 ( V_9 ) ,
V_66 == V_45 ? L_113 :
V_500 [ V_66 ] . V_501 ) ;
}
if ( V_6 & V_38 ) {
type = L_114 ;
V_397 = V_6 & V_39 ;
V_136 = ( ( V_6 & V_143 )
>> V_144 ) + 1 ;
} else if ( V_6 & V_32 ) {
type = L_115 ;
V_397 = V_6 & V_502 ;
} else {
type = L_116 ;
}
switch ( V_6 & V_140 ) {
case V_161 :
V_67 = L_117 ;
break;
case V_262 :
V_67 = L_118 ;
break;
case V_146 :
V_67 = L_119 ;
break;
case V_145 :
V_67 = L_120 ;
break;
default:
V_67 = L_121 ;
}
return sprintf ( V_499 , L_122 ,
type , F_18 ( V_9 ) , V_67 , V_397 , V_136 ,
( V_6 & V_131 ) ? L_123 : L_124 ,
( V_6 & V_503 ) ? L_125 : L_126 ,
( V_6 & V_132 ) ? L_127 : L_126 ,
( V_6 & V_138 ) ? L_128 : L_126 ,
( V_6 & V_504 ) ? L_129 : L_126 ) ;
}
static void F_145 ( struct V_1 * V_2 ,
struct V_87 * V_108 )
{
V_108 -> V_150 = 0x0FFF ;
V_108 -> V_151 = 0x1FD0 ;
V_108 -> V_152 = 0x1FD0 ;
F_21 ( V_2 , L_130 ,
V_108 -> V_215 . V_431 , V_108 -> V_114 . V_204 ) ;
if ( V_108 -> V_114 . V_204 ) {
F_90 ( V_2 , NULL , V_108 , NULL ) ;
F_72 ( V_108 -> V_114 . V_160 , & V_108 -> V_215 , false ) ;
}
}
static T_10 F_146 ( struct V_505 * V_505 ,
const char T_11 * V_506 , T_12 V_208 , T_13 * V_507 )
{
struct V_87 * V_108 = V_505 -> V_508 ;
struct V_1 * V_2 ;
char V_499 [ 64 ] ;
T_12 V_509 ;
T_2 V_510 ;
V_2 = V_108 -> V_114 . V_160 ;
memset ( V_499 , 0 , sizeof( V_499 ) ) ;
V_509 = F_74 ( V_208 , sizeof( V_499 ) - 1 ) ;
if ( F_147 ( V_499 , V_506 , V_509 ) )
return - V_511 ;
if ( sscanf ( V_499 , L_131 , & V_510 ) == 1 )
V_108 -> V_114 . V_204 = V_510 ;
else
V_108 -> V_114 . V_204 = 0 ;
F_145 ( V_2 , V_108 ) ;
return V_208 ;
}
static T_10 F_148 ( struct V_505 * V_505 ,
char T_11 * V_506 , T_12 V_208 , T_13 * V_507 )
{
char * V_512 ;
int V_513 = 0 ;
int V_81 = 0 ;
T_10 V_90 ;
struct V_87 * V_108 = V_505 -> V_508 ;
struct V_1 * V_2 ;
struct V_79 * V_80 = & ( V_108 -> V_221 [ V_108 -> V_222 ] ) ;
struct V_5 * V_6 = & V_80 -> V_6 ;
T_2 V_468 ;
V_2 = V_108 -> V_114 . V_160 ;
V_512 = F_149 ( 2048 , V_514 ) ;
if ( ! V_512 )
return - V_515 ;
V_513 += sprintf ( V_512 + V_513 , L_132 , V_108 -> V_215 . V_431 ) ;
V_513 += sprintf ( V_512 + V_513 , L_133 ,
V_108 -> V_226 , V_108 -> V_225 ,
V_108 -> V_150 ) ;
V_513 += sprintf ( V_512 + V_513 , L_134 ,
V_108 -> V_114 . V_204 ) ;
V_513 += sprintf ( V_512 + V_513 , L_135 ,
( F_5 ( V_2 ) & V_48 ) ? L_136 : L_126 ,
( F_5 ( V_2 ) & V_49 ) ? L_137 : L_126 ,
( F_5 ( V_2 ) & V_51 ) ? L_138 : L_126 ) ;
V_513 += sprintf ( V_512 + V_513 , L_139 ,
( F_37 ( V_6 ) ) ? L_140 :
F_41 ( V_6 ) ? L_114 : L_115 ) ;
if ( ! F_37 ( V_6 ) ) {
V_513 += sprintf ( V_512 + V_513 , L_141 ,
( F_44 ( V_6 ) ) ? L_142 : L_143 ) ;
V_513 += sprintf ( V_512 + V_513 , L_141 ,
( F_12 ( V_6 ) ) ? L_144 :
( F_13 ( V_6 ) ) ? L_145 :
( F_14 ( V_6 ) ) ? L_119 : L_121 ) ;
V_513 += sprintf ( V_512 + V_513 , L_146 ,
( V_6 -> V_68 ) ? L_147 : L_148 ,
( V_6 -> V_69 ) ? L_149 : L_150 ,
( V_108 -> V_267 ) ? L_151 : L_126 ) ;
}
V_513 += sprintf ( V_512 + V_513 , L_152 ,
V_108 -> V_227 ) ;
V_513 += sprintf ( V_512 + V_513 ,
L_153 ,
V_108 -> V_215 . V_201 ,
V_108 -> V_215 . V_446 ,
V_108 -> V_215 . V_437 ,
V_108 -> V_215 . V_438 ) ;
V_513 += sprintf ( V_512 + V_513 ,
L_154 ,
F_113 ( V_108 -> V_215 . V_491 ) ,
V_108 -> V_215 . V_489 ,
V_108 -> V_215 . V_447 ) ;
V_513 += sprintf ( V_512 + V_513 , L_155 , V_108 -> V_215 . V_341 ) ;
V_468 = F_71 ( V_108 -> V_215 . V_468 ) ;
V_513 += sprintf ( V_512 + V_513 , L_156 ,
( V_468 & V_482 ) ?
L_157 : L_158 ,
( V_468 & V_470 ) ?
L_159 : L_126 ,
( V_468 & V_484 ) ?
L_160 : L_126 ,
( V_468 & V_485 ) ?
L_161 : L_126 ) ;
V_513 += sprintf ( V_512 + V_513 ,
L_162 ,
V_108 -> V_215 . V_516 [ 0 ] ,
V_108 -> V_215 . V_516 [ 1 ] ,
V_108 -> V_215 . V_516 [ 2 ] ,
V_108 -> V_215 . V_516 [ 3 ] ) ;
for ( V_81 = 0 ; V_81 < V_455 ; V_81 ++ ) {
T_2 V_517 = F_71 ( V_108 -> V_215 . V_216 [ V_81 ] ) ;
V_513 += sprintf ( V_512 + V_513 , L_163 , V_81 , V_517 ) ;
V_513 += F_144 ( V_512 + V_513 , V_517 ) ;
}
V_90 = F_150 ( V_506 , V_208 , V_507 , V_512 , V_513 ) ;
F_151 ( V_512 ) ;
return V_90 ;
}
static T_10 F_152 ( struct V_505 * V_505 ,
char T_11 * V_506 , T_12 V_208 , T_13 * V_507 )
{
char * V_512 ;
int V_513 = 0 ;
int V_81 , V_282 ;
T_10 V_90 ;
struct V_79 * V_80 ;
struct V_5 * V_6 ;
struct V_87 * V_108 = V_505 -> V_508 ;
V_512 = F_149 ( 1024 , V_514 ) ;
if ( ! V_512 )
return - V_515 ;
for ( V_81 = 0 ; V_81 < V_432 ; V_81 ++ ) {
V_80 = & ( V_108 -> V_221 [ V_81 ] ) ;
V_6 = & V_80 -> V_6 ;
V_513 += sprintf ( V_512 + V_513 ,
L_164
L_165 ,
V_108 -> V_222 == V_81 ? L_166 : L_167 ,
V_6 -> type ,
V_6 -> V_68 ,
F_12 ( V_6 ) ? L_117 :
F_13 ( V_6 ) ? L_118 :
F_14 ( V_6 ) ? L_119 : L_168 ,
V_6 -> V_66 ) ;
for ( V_282 = 0 ; V_282 < V_82 ; V_282 ++ ) {
V_513 += sprintf ( V_512 + V_513 ,
L_169 ,
V_80 -> V_83 [ V_282 ] . V_77 ,
V_80 -> V_83 [ V_282 ] . V_74 ,
V_80 -> V_83 [ V_282 ] . V_75 ) ;
}
}
V_90 = F_150 ( V_506 , V_208 , V_507 , V_512 , V_513 ) ;
F_151 ( V_512 ) ;
return V_90 ;
}
static T_10 F_153 ( struct V_505 * V_505 ,
char T_11 * V_506 ,
T_12 V_208 , T_13 * V_507 )
{
static const char * const V_518 [] = {
[ V_169 ] = L_170 ,
[ V_170 ] = L_171 ,
[ V_173 ] = L_172 ,
[ V_175 ] = L_173 ,
[ V_172 ] = L_174 ,
[ V_174 ] = L_175 ,
[ V_177 ] = L_143 ,
[ V_176 ] = L_176 ,
} ;
static const char * const V_519 [] = {
[ V_520 ] = L_177 ,
[ V_521 ] = L_178 ,
[ V_522 ] = L_179 ,
[ V_523 ] = L_180 ,
[ V_524 ] = L_181 ,
[ V_35 ] = L_182 ,
[ V_525 ] = L_183 ,
[ V_526 ] = L_184 ,
[ V_527 ] = L_185 ,
[ V_528 ] = L_186 ,
[ V_529 ] = L_187 ,
[ V_323 ] = L_188 ,
[ V_324 ] = L_189 ,
[ V_325 ] = L_190 ,
[ V_162 ] = L_191 ,
} ;
char * V_512 , * V_530 , * V_531 ;
int V_532 , V_6 ;
T_10 V_90 ;
struct V_87 * V_108 = V_505 -> V_508 ;
struct V_533 * V_534 ;
static const T_12 V_535 = 1024 ;
V_512 = F_149 ( V_535 , V_514 ) ;
if ( ! V_512 )
return - V_515 ;
V_530 = V_512 ;
V_531 = V_530 + V_535 ;
V_530 += F_154 ( V_530 , V_531 - V_530 , L_192 ) ;
for ( V_6 = 0 ; V_6 < V_82 ; V_6 ++ )
V_530 += F_154 ( V_530 , V_531 - V_530 , L_193 , V_519 [ V_6 ] ) ;
V_530 += F_154 ( V_530 , V_531 - V_530 , L_194 ) ;
for ( V_532 = 0 ; V_532 < V_536 ; V_532 ++ ) {
V_530 += F_154 ( V_530 , V_531 - V_530 ,
L_193 , V_518 [ V_532 ] ) ;
for ( V_6 = 0 ; V_6 < V_82 ; V_6 ++ ) {
V_534 = & ( V_108 -> V_114 . V_115 [ V_532 ] [ V_6 ] ) ;
V_530 += F_154 ( V_530 , V_531 - V_530 ,
L_195 ,
V_534 -> V_117 ,
V_534 -> V_116 ) ;
}
V_530 += F_154 ( V_530 , V_531 - V_530 , L_194 ) ;
}
V_90 = F_150 ( V_506 , V_208 , V_507 , V_512 , V_530 - V_512 ) ;
F_151 ( V_512 ) ;
return V_90 ;
}
static T_10 F_155 ( struct V_505 * V_505 ,
const char T_11 * V_506 ,
T_12 V_208 , T_13 * V_507 )
{
struct V_87 * V_108 = V_505 -> V_508 ;
memset ( V_108 -> V_114 . V_115 , 0 , sizeof( V_108 -> V_114 . V_115 ) ) ;
return V_208 ;
}
static T_10 F_156 ( struct V_505 * V_505 ,
char T_11 * V_506 ,
T_12 V_208 , T_13 * V_507 )
{
struct V_87 * V_108 = V_505 -> V_508 ;
char V_499 [ 12 ] ;
int V_535 = sizeof( V_499 ) ;
int V_530 = 0 ;
static const char * const V_537 [] = {
[ V_386 ] = L_196 ,
[ V_483 ] = L_197 ,
[ V_486 ] = L_198 ,
[ V_538 ] = L_199 ,
} ;
V_530 += F_154 ( V_499 + V_530 , V_535 - V_530 , L_200 ,
V_537 [ V_108 -> V_114 . V_385 ] ) ;
return F_150 ( V_506 , V_208 , V_507 , V_499 , V_530 ) ;
}
static T_10 F_157 ( struct V_87 * V_108 , char * V_499 ,
T_12 V_208 , T_13 * V_507 )
{
struct V_1 * V_2 = V_108 -> V_114 . V_160 ;
int V_90 = 0 ;
if ( ! strncmp ( L_196 , V_499 , 4 ) ) {
V_108 -> V_114 . V_385 = V_386 ;
} else if ( ! strncmp ( L_199 , V_499 , 4 ) ) {
V_108 -> V_114 . V_385 = V_538 ;
} else if ( ! strncmp ( L_197 , V_499 , 4 ) ) {
if ( V_108 -> V_309 ) {
V_108 -> V_114 . V_385 = V_483 ;
} else {
F_28 ( V_2 ,
L_201 ) ;
V_90 = - V_110 ;
}
} else if ( ! strncmp ( L_198 , V_499 , 4 ) ) {
if ( V_108 -> V_408 ) {
V_108 -> V_114 . V_385 = V_486 ;
} else {
F_28 ( V_2 ,
L_202 ) ;
V_90 = - V_110 ;
}
} else {
F_28 ( V_2 , L_203 ) ;
V_90 = - V_110 ;
}
return V_90 ? : V_208 ;
}
static void F_158 ( void * V_2 , void * V_232 , struct V_496 * V_539 )
{
struct V_87 * V_108 = V_232 ;
struct V_10 * V_11 ;
V_11 = F_159 ( V_108 , struct V_10 , V_108 ) ;
if ( ! V_11 -> V_18 )
return;
F_160 ( L_204 , V_540 | V_541 , V_539 ,
V_108 , & V_542 ) ;
F_160 ( L_205 , V_540 , V_539 ,
V_108 , & V_543 ) ;
F_160 ( L_206 , V_540 | V_541 , V_539 ,
V_108 , & V_544 ) ;
F_161 ( L_207 , V_540 | V_541 , V_539 ,
& V_108 -> V_362 ) ;
F_161 ( L_208 , V_540 | V_541 , V_539 ,
& V_108 -> V_114 . V_342 ) ;
F_162 ( V_385 , V_539 , V_540 | V_541 ) ;
return;
V_171:
F_28 ( (struct V_1 * ) V_2 , L_209 ) ;
}
static void F_163 ( void * V_2 , void * V_337 )
{
}
static void F_164 ( void * V_229 ,
struct V_230 * V_231 ,
struct V_440 * V_441 ,
struct V_3 * V_4 , void * V_337 )
{
}
int F_165 ( void )
{
return F_166 ( & V_545 ) ;
}
void F_167 ( void )
{
F_168 ( & V_545 ) ;
}
int F_169 ( struct V_1 * V_2 , struct V_10 * V_11 ,
bool V_546 )
{
struct V_186 * V_215 = & V_11 -> V_108 . V_215 ;
F_170 ( & V_2 -> V_547 ) ;
if ( V_546 ) {
if ( V_11 -> V_548 == 0 )
V_215 -> V_201 |= V_495 ;
V_11 -> V_548 ++ ;
} else {
V_11 -> V_548 -- ;
if ( V_11 -> V_548 == 0 )
V_215 -> V_201 &= ~ V_495 ;
}
return F_72 ( V_2 , V_215 , false ) ;
}
