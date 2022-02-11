static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
return F_2 ( V_2 , V_6 -> V_7 . V_8 ) ;
}
static bool F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_4 -> V_9 . V_10 )
return false ;
if ( V_4 -> V_11 == V_12 )
return false ;
if ( F_4 ( V_2 -> V_13 -> V_14 ) < 2 )
return false ;
if ( ! F_5 ( V_2 , V_4 ) )
return false ;
return true ;
}
static bool F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_4 -> V_9 . V_10 )
return false ;
return true ;
}
static bool F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_15 * V_7 = & V_6 -> V_7 ;
struct V_16 * V_9 = & V_4 -> V_9 ;
struct V_17 * V_18 = & V_4 -> V_18 ;
if ( F_8 ( V_7 ) && ( V_9 -> V_19 &
V_20 ) )
return true ;
if ( F_9 ( V_7 ) && ( V_9 -> V_19 &
V_21 ) )
return true ;
if ( F_10 ( V_7 ) && ( V_18 -> V_19 &
V_22 ) )
return true ;
return false ;
}
static inline T_1 F_11 ( T_2 V_23 )
{
return ( T_1 ) ( V_23 & V_24 ) ;
}
static int F_12 ( T_2 V_23 )
{
int V_25 = 0 ;
if ( V_23 & V_26 ) {
V_25 = V_23 & V_27 ;
V_25 += V_28 ;
if ( V_25 >= V_29 )
V_25 += 1 ;
if ( ( V_25 >= V_30 ) && ( V_25 <= V_31 ) )
return V_25 ;
} else if ( V_23 & V_32 ) {
V_25 = V_23 & V_33 ;
V_25 += V_28 ;
if ( V_25 >= V_29 )
V_25 ++ ;
if ( ( V_25 >= V_34 ) && ( V_25 <= V_35 ) )
return V_25 ;
} else {
T_1 V_36 = F_11 ( V_23 ) ;
for ( V_25 = 0 ; V_25 < F_13 ( V_37 ) ; V_25 ++ )
if ( V_37 [ V_25 ] . V_38 == V_36 )
return V_25 ;
}
return V_39 ;
}
static const char * F_14 ( T_1 V_8 )
{
static const char * const V_40 [] = {
[ V_41 ] = L_1 ,
[ V_42 ] = L_2 ,
[ V_43 ] = L_3 ,
[ V_44 ] = L_4 ,
[ V_45 ] = L_5 ,
[ V_46 ] = L_6 ,
[ V_47 ] = L_7 ,
[ V_48 ] = L_8 ,
} ;
if ( V_8 > V_48 )
return L_9 ;
return V_40 [ V_8 ] ;
}
static const char * F_15 ( enum V_49 type )
{
static const char * const V_50 [] = {
[ V_51 ] = L_10 ,
[ V_52 ] = L_11 ,
[ V_53 ] = L_12 ,
[ V_54 ] = L_13 ,
[ V_55 ] = L_14 ,
[ V_56 ] = L_15 ,
[ V_57 ] = L_16 ,
} ;
if ( type < V_51 || type >= V_58 )
return L_9 ;
return V_50 [ type ] ;
}
static inline void F_16 ( struct V_1 * V_2 , const struct V_15 * V_7 ,
const char * V_59 )
{
F_17 ( V_2 ,
L_17 ,
V_59 , F_15 ( V_7 -> type ) ,
V_7 -> V_60 , F_14 ( V_7 -> V_8 ) ,
V_7 -> V_61 , V_7 -> V_62 , V_7 -> V_63 , V_7 -> V_64 ) ;
}
static void F_18 ( struct V_65 * V_66 )
{
V_66 -> V_67 = 0 ;
V_66 -> V_68 = 0 ;
V_66 -> V_69 = V_70 ;
V_66 -> V_71 = 0 ;
V_66 -> V_72 = V_70 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_73 ;
F_17 ( V_2 , L_18 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
F_18 ( & V_6 -> V_75 [ V_73 ] ) ;
for ( V_73 = 0 ; V_73 < F_13 ( V_6 -> V_76 ) ; V_73 ++ )
F_18 ( & V_6 -> V_76 [ V_73 ] ) ;
}
static inline T_1 F_20 ( T_1 V_77 , T_1 V_78 )
{
return ( V_78 & V_77 ) == V_78 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_79 * V_80 , T_1 V_81 ,
struct V_3 * V_4 )
{
int V_82 = - V_83 ;
F_22 ( V_2 , L_19 ,
V_4 -> V_84 , V_81 ) ;
V_82 = F_23 ( V_4 , V_81 , 5000 ) ;
if ( V_82 == - V_83 ) {
F_24 ( V_2 , L_20 ,
V_81 ) ;
F_25 ( V_4 , V_81 ) ;
}
return V_82 ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_81 ,
struct V_79 * V_80 ,
struct V_3 * V_4 )
{
if ( V_81 < V_85 )
F_21 ( V_2 , V_80 , V_81 , V_4 ) ;
else
F_24 ( V_2 , L_21 ,
V_81 , V_85 ) ;
}
static inline int F_27 ( T_2 V_23 )
{
return ! ! ( V_23 & V_86 ) +
! ! ( V_23 & V_87 ) +
! ! ( V_23 & V_88 ) ;
}
static T_3 F_28 ( struct V_5 * V_6 , int V_89 )
{
if ( V_6 -> V_90 )
return V_6 -> V_90 [ V_89 ] ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 ,
int V_91 , int V_92 , int V_93 ,
struct V_65 * V_66 )
{
static const T_4 V_94 = ( ( ( T_4 ) 1 ) << ( V_95 - 1 ) ) ;
T_3 V_96 , V_97 ;
V_97 = F_28 ( V_6 , V_91 ) ;
while ( V_92 > 0 ) {
if ( V_66 -> V_71 >= V_95 ) {
V_66 -> V_71 = V_95 - 1 ;
if ( V_66 -> V_67 & V_94 ) {
V_66 -> V_67 &= ~ V_94 ;
V_66 -> V_68 -- ;
}
}
V_66 -> V_71 ++ ;
V_66 -> V_67 <<= 1 ;
if ( V_93 > 0 ) {
V_66 -> V_68 ++ ;
V_66 -> V_67 |= 0x1 ;
V_93 -- ;
}
V_92 -- ;
}
if ( V_66 -> V_71 > 0 )
V_66 -> V_69 = 128 * ( 100 * V_66 -> V_68 )
/ V_66 -> V_71 ;
else
V_66 -> V_69 = V_70 ;
V_96 = V_66 -> V_71 - V_66 -> V_68 ;
if ( ( V_96 >= V_98 ) ||
( V_66 -> V_68 >= V_99 ) )
V_66 -> V_72 = ( V_66 -> V_69 * V_97 + 64 ) / 128 ;
else
V_66 -> V_72 = V_70 ;
return 0 ;
}
static int F_30 ( struct V_79 * V_100 ,
struct V_5 * V_6 ,
int V_91 , int V_92 , int V_93 ,
T_1 V_101 )
{
struct V_65 * V_66 = NULL ;
int V_82 ;
if ( V_91 < 0 || V_91 >= V_74 )
return - V_102 ;
if ( V_6 -> V_103 != V_104 ) {
struct V_105 * V_106 = & V_100 -> V_106 ;
V_106 -> V_107 [ V_6 -> V_103 ] [ V_91 ] . V_108 += V_92 ;
V_106 -> V_107 [ V_6 -> V_103 ] [ V_91 ] . V_109 += V_93 ;
}
V_66 = & ( V_6 -> V_75 [ V_91 ] ) ;
V_82 = F_29 ( V_6 , V_91 , V_92 , V_93 ,
V_66 ) ;
if ( V_82 )
return V_82 ;
if ( F_31 ( V_101 > V_110 ) )
return - V_102 ;
V_66 = & V_6 -> V_76 [ V_101 ] ;
return F_29 ( V_6 , V_91 , V_92 , V_93 ,
V_66 ) ;
}
static T_2 F_32 ( struct V_1 * V_2 ,
struct V_15 * V_7 )
{
T_2 V_111 = 0 ;
int V_60 = V_7 -> V_60 ;
V_111 |= ( ( V_7 -> V_8 << V_112 ) &
V_113 ) ;
if ( F_33 ( V_7 ) ) {
V_111 |= V_37 [ V_60 ] . V_38 ;
if ( V_60 >= V_114 && V_60 <= V_115 )
V_111 |= V_116 ;
return V_111 ;
}
if ( F_34 ( V_7 ) ) {
if ( V_60 < V_30 || V_60 > V_31 ) {
F_24 ( V_2 , L_22 , V_60 ) ;
V_60 = V_31 ;
}
V_111 |= V_26 ;
if ( F_35 ( V_7 ) )
V_111 |= V_37 [ V_60 ] . V_117 ;
else if ( F_36 ( V_7 ) )
V_111 |= V_37 [ V_60 ] . V_118 ;
else
F_31 ( 1 ) ;
} else if ( F_37 ( V_7 ) ) {
if ( V_60 < V_34 || V_60 > V_35 ) {
F_24 ( V_2 , L_23 , V_60 ) ;
V_60 = V_35 ;
}
V_111 |= V_32 ;
if ( F_38 ( V_7 ) )
V_111 |= V_37 [ V_60 ] . V_119 ;
else if ( F_39 ( V_7 ) )
V_111 |= V_37 [ V_60 ] . V_120 ;
else
F_31 ( 1 ) ;
} else {
F_24 ( V_2 , L_24 , V_7 -> type ) ;
}
if ( F_40 ( V_7 ) && V_7 -> V_64 ) {
V_111 |= V_121 ;
V_111 |= V_122 ;
}
V_111 |= V_7 -> V_61 ;
if ( V_7 -> V_62 )
V_111 |= V_123 ;
if ( V_7 -> V_63 )
V_111 |= V_124 ;
return V_111 ;
}
static int F_41 ( const T_2 V_111 ,
enum V_125 V_126 ,
struct V_15 * V_7 )
{
T_2 V_127 = V_111 & V_113 ;
T_1 F_4 = F_27 ( V_111 ) ;
T_1 V_128 ;
memset ( V_7 , 0 , sizeof( * V_7 ) ) ;
V_7 -> V_60 = F_12 ( V_111 ) ;
if ( V_7 -> V_60 == V_39 )
return - V_102 ;
V_7 -> V_8 = ( V_127 >> V_112 ) ;
if ( ! ( V_111 & V_26 ) &&
! ( V_111 & V_32 ) ) {
if ( F_4 == 1 ) {
if ( V_126 == V_129 )
V_7 -> type = V_52 ;
else
V_7 -> type = V_53 ;
}
return 0 ;
}
if ( V_111 & V_123 )
V_7 -> V_62 = true ;
if ( V_111 & V_124 )
V_7 -> V_63 = true ;
if ( V_111 & V_122 )
V_7 -> V_64 = true ;
V_7 -> V_61 = V_111 & V_130 ;
if ( V_111 & V_26 ) {
V_128 = ( ( V_111 & V_131 ) >>
V_132 ) + 1 ;
if ( V_128 == 1 ) {
V_7 -> type = V_54 ;
F_31 ( ! V_7 -> V_64 && F_4 != 1 ) ;
} else if ( V_128 == 2 ) {
V_7 -> type = V_55 ;
F_31 ( F_4 != 2 ) ;
} else {
F_31 ( 1 ) ;
}
} else if ( V_111 & V_32 ) {
V_128 = ( ( V_111 & V_133 ) >>
V_134 ) + 1 ;
if ( V_128 == 1 ) {
V_7 -> type = V_56 ;
F_31 ( ! V_7 -> V_64 && F_4 != 1 ) ;
} else if ( V_128 == 2 ) {
V_7 -> type = V_57 ;
F_31 ( F_4 != 2 ) ;
} else {
F_31 ( 1 ) ;
}
}
F_31 ( V_7 -> V_61 == V_135 ) ;
F_31 ( V_7 -> V_61 == V_136 &&
! F_37 ( V_7 ) ) ;
return 0 ;
}
static int F_42 ( T_2 V_137 , struct V_15 * V_7 )
{
T_1 V_138 ;
if ( ! V_7 -> V_8 || V_7 -> V_8 > V_48 )
return 0 ;
if ( ! F_20 ( V_137 , V_7 -> V_8 ) )
return 0 ;
V_138 = V_139 [ V_7 -> V_8 ] ;
while ( ( V_138 != V_7 -> V_8 ) &&
! F_20 ( V_137 , V_138 ) )
V_138 = V_139 [ V_138 ] ;
if ( V_138 == V_7 -> V_8 )
return 0 ;
V_7 -> V_8 = V_138 ;
return 1 ;
}
static T_5 F_43 ( struct V_79 * V_100 ,
struct V_15 * V_7 )
{
if ( F_33 ( V_7 ) )
return V_100 -> V_140 ;
else if ( F_40 ( V_7 ) )
return V_100 -> V_141 ;
else if ( F_44 ( V_7 ) )
return V_100 -> V_142 ;
F_31 ( 1 ) ;
return 0 ;
}
static T_5 F_45 ( struct V_1 * V_2 , T_1 V_60 , T_5 V_143 ,
int V_144 )
{
T_1 V_145 = V_39 ;
T_1 V_146 = V_39 ;
if ( F_46 ( V_144 ) || ! F_47 ( V_144 ) ) {
int V_73 ;
T_2 V_94 ;
V_73 = V_60 - 1 ;
for ( V_94 = ( 1 << V_73 ) ; V_73 >= 0 ; V_73 -- , V_94 >>= 1 ) {
if ( V_143 & V_94 ) {
V_146 = V_73 ;
break;
}
}
V_73 = V_60 + 1 ;
for ( V_94 = ( 1 << V_73 ) ; V_73 < V_74 ; V_73 ++ , V_94 <<= 1 ) {
if ( V_143 & V_94 ) {
V_145 = V_73 ;
break;
}
}
return ( V_145 << 8 ) | V_146 ;
}
V_146 = V_60 ;
while ( V_146 != V_39 ) {
V_146 = V_37 [ V_146 ] . V_147 ;
if ( V_146 == V_39 )
break;
if ( V_143 & ( 1 << V_146 ) )
break;
F_17 ( V_2 , L_25 , V_146 ) ;
}
V_145 = V_60 ;
while ( V_145 != V_39 ) {
V_145 = V_37 [ V_145 ] . V_148 ;
if ( V_145 == V_39 )
break;
if ( V_143 & ( 1 << V_145 ) )
break;
F_17 ( V_2 , L_26 , V_145 ) ;
}
return ( V_145 << 8 ) | V_146 ;
}
static inline bool F_48 ( struct V_79 * V_100 ,
struct V_15 * V_7 )
{
return F_49 ( V_7 -> V_60 ) & F_43 ( V_100 , V_7 ) ;
}
static bool F_50 ( struct V_79 * V_100 ,
struct V_15 * V_7 )
{
T_1 V_146 ;
T_5 V_149 ;
T_5 V_143 ;
struct V_1 * V_2 = V_100 -> V_106 . V_150 ;
V_143 = F_43 ( V_100 , V_7 ) ;
V_149 = F_45 ( V_2 , V_7 -> V_60 , V_143 ,
V_7 -> type ) ;
V_146 = V_149 & 0xff ;
if ( V_146 == V_39 )
return true ;
V_7 -> V_60 = V_146 ;
return false ;
}
static void F_51 ( struct V_79 * V_100 ,
struct V_15 * V_7 )
{
struct V_1 * V_2 = V_100 -> V_106 . V_150 ;
if ( F_33 ( V_7 ) ) {
return;
} else if ( F_40 ( V_7 ) ) {
if ( V_100 -> V_126 == V_129 )
V_7 -> type = V_52 ;
else
V_7 -> type = V_53 ;
V_7 -> V_61 = V_151 ;
F_31 ( V_7 -> V_60 < V_28 ||
V_7 -> V_60 > V_152 ) ;
V_7 -> V_60 = V_153 [ V_7 -> V_60 ] ;
V_7 -> V_63 = false ;
} else {
V_7 -> type = F_39 ( V_7 ) ?
V_56 : V_54 ;
}
if ( F_4 ( V_7 -> V_8 ) > 1 )
V_7 -> V_8 = F_52 ( V_2 -> V_13 -> V_14 ) ;
V_7 -> V_62 = false ;
if ( ! F_48 ( V_100 , V_7 ) )
F_50 ( V_100 , V_7 ) ;
}
static inline bool F_53 ( struct V_15 * V_154 ,
struct V_15 * V_155 )
{
bool V_156 ;
if ( V_154 -> V_64 )
V_156 = ( V_155 -> V_8 == V_42 || V_155 -> V_8 == V_43 ) ;
else
V_156 = ( V_154 -> V_8 == V_155 -> V_8 ) ;
return ( V_154 -> type == V_155 -> type ) && ( V_154 -> V_61 == V_155 -> V_61 ) && ( V_154 -> V_62 == V_155 -> V_62 )
&& V_156 ;
}
static T_2 F_54 ( enum V_157 V_158 )
{
if ( V_158 & V_159 )
return V_160 ;
else if ( V_158 & V_161 )
return V_136 ;
else if ( V_158 & V_162 )
return V_135 ;
return V_151 ;
}
static T_1 F_55 ( struct V_163 * V_164 )
{
T_1 V_81 = V_85 ;
if ( F_56 ( V_164 -> V_165 ) ) {
T_1 * V_166 = F_57 ( V_164 ) ;
V_81 = V_166 [ 0 ] & 0xf ;
}
if ( F_58 ( V_81 > V_85 ) )
V_81 = V_85 ;
return V_81 ;
}
void F_59 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_81 , struct V_167 * V_168 )
{
int V_169 ;
int V_170 ;
int V_171 , V_73 ;
struct V_172 * V_173 ;
enum V_157 V_174 ;
T_2 V_111 ;
struct V_15 V_7 ;
struct V_5 * V_175 , * V_176 , * V_177 ;
T_1 V_101 = ( V_178 ) V_168 -> V_179 . V_180 [ 0 ] ;
struct V_181 * V_182 = F_60 ( V_4 ) ;
struct V_79 * V_100 = & V_182 -> V_100 ;
if ( ! V_100 ) {
F_17 ( V_2 , L_27 ) ;
return;
} else if ( ! V_100 -> V_106 . V_150 ) {
F_17 ( V_2 , L_28 ) ;
return;
}
#ifdef F_61
if ( V_100 -> V_106 . V_183 ) {
F_17 ( V_2 , L_29 ) ;
return;
}
#endif
if ( ( V_168 -> V_158 & V_184 ) &&
! ( V_168 -> V_158 & V_185 ) )
return;
V_173 = & V_100 -> V_186 ;
V_111 = F_62 ( V_173 -> V_187 [ 0 ] ) ;
F_41 ( V_111 , V_168 -> V_126 , & V_7 ) ;
if ( V_168 -> V_126 == V_129 )
V_7 . V_60 -= V_188 ;
V_174 = V_168 -> V_179 . V_189 [ 0 ] . V_158 ;
V_171 = V_168 -> V_179 . V_189 [ 0 ] . V_25 ;
if ( V_174 & V_190 ) {
V_171 &= V_27 ;
if ( V_171 >= ( V_29 - V_188 ) )
V_171 ++ ;
if ( V_168 -> V_126 == V_191 )
V_171 += V_188 ;
} else if ( V_174 & V_192 ) {
V_171 &= V_33 ;
if ( V_171 >= ( V_29 - V_188 ) )
V_171 ++ ;
}
if ( F_63 ( V_193 ,
( unsigned long ) ( V_100 -> V_194 + V_195 ) ) ) {
int V_196 ;
F_17 ( V_2 , L_30 ) ;
for ( V_196 = 0 ; V_196 < V_85 ; V_196 ++ )
F_25 ( V_4 , V_196 ) ;
F_64 ( V_2 , V_4 , V_168 -> V_126 , false ) ;
return;
}
V_100 -> V_194 = V_193 ;
if ( ( V_171 < 0 ) ||
( V_7 . V_62 != ! ! ( V_174 & V_197 ) ) ||
( V_7 . V_61 != F_54 ( V_174 ) ) ||
( V_7 . V_8 != V_168 -> V_179 . V_198 ) ||
( ! ! ( V_111 & V_26 ) !=
! ! ( V_174 & V_190 ) ) ||
( ! ! ( V_111 & V_32 ) !=
! ! ( V_174 & V_192 ) ) ||
( ! ! ( V_111 & V_199 ) !=
! ! ( V_174 & V_200 ) ) ||
( V_7 . V_60 != V_171 ) ) {
F_17 ( V_2 ,
L_31 ,
V_171 , V_7 . V_60 , V_111 ) ;
V_100 -> V_201 ++ ;
if ( V_100 -> V_201 > V_202 ) {
V_100 -> V_201 = 0 ;
F_17 ( V_2 ,
L_32 ,
V_100 -> V_203 ) ;
F_65 ( V_2 , & V_100 -> V_186 , false ) ;
}
return;
} else
V_100 -> V_201 = 0 ;
if ( ! V_100 -> V_204 ) {
V_175 = & ( V_100 -> V_205 [ V_100 -> V_206 ] ) ;
V_176 = & ( V_100 -> V_205 [ 1 - V_100 -> V_206 ] ) ;
} else {
V_175 = & ( V_100 -> V_205 [ 1 - V_100 -> V_206 ] ) ;
V_176 = & ( V_100 -> V_205 [ V_100 -> V_206 ] ) ;
}
if ( F_31 ( ! F_53 ( & V_7 , & V_175 -> V_7 ) ) ) {
F_17 ( V_2 ,
L_33 ) ;
V_177 = & ( V_100 -> V_205 [ V_100 -> V_206 ] ) ;
F_16 ( V_2 , & V_177 -> V_7 , L_34 ) ;
V_177 = & ( V_100 -> V_205 [ 1 - V_100 -> V_206 ] ) ;
F_16 ( V_2 , & V_177 -> V_7 , L_35 ) ;
F_16 ( V_2 , & V_7 , L_36 ) ;
F_66 ( V_100 , true ) ;
goto V_207;
}
if ( V_168 -> V_158 & V_185 ) {
if ( V_168 -> V_179 . V_208 == 0 )
V_168 -> V_179 . V_209 = 1 ;
V_111 = F_62 ( V_173 -> V_187 [ 0 ] ) ;
F_41 ( V_111 , V_168 -> V_126 , & V_7 ) ;
F_30 ( V_100 , V_175 , V_7 . V_60 ,
V_168 -> V_179 . V_209 ,
V_168 -> V_179 . V_208 ,
V_101 ) ;
if ( V_100 -> V_203 == V_210 ) {
V_100 -> V_211 += V_168 -> V_179 . V_208 ;
V_100 -> V_212 += ( V_168 -> V_179 . V_209 -
V_168 -> V_179 . V_208 ) ;
}
} else {
V_170 = V_168 -> V_179 . V_189 [ 0 ] . V_213 - 1 ;
V_170 = F_67 ( V_170 , 15 ) ;
V_169 = ! ! ( V_168 -> V_158 & V_214 ) ;
for ( V_73 = 0 ; V_73 <= V_170 ; ++ V_73 ) {
V_111 = F_62 ( V_173 -> V_187 [ V_73 ] ) ;
F_41 ( V_111 , V_168 -> V_126 , & V_7 ) ;
if ( F_53 ( & V_7 , & V_175 -> V_7 ) )
V_177 = V_175 ;
else if ( F_53 ( & V_7 , & V_176 -> V_7 ) )
V_177 = V_176 ;
else
continue;
F_30 ( V_100 , V_177 , V_7 . V_60 , 1 ,
V_73 < V_170 ? 0 : V_169 ,
V_101 ) ;
}
if ( V_100 -> V_203 == V_210 ) {
V_100 -> V_211 += V_169 ;
V_100 -> V_212 += V_170 + ( 1 - V_169 ) ;
}
}
V_100 -> V_215 = V_111 ;
F_17 ( V_2 , L_37 , V_101 ) ;
V_207:
if ( V_4 -> V_216 [ V_168 -> V_126 ] )
F_68 ( V_2 , V_4 , V_100 , V_81 ) ;
}
static void F_69 ( void * V_217 ,
struct V_218 * V_219 ,
struct V_3 * V_4 , void * V_220 ,
struct V_221 * V_222 )
{
struct V_163 * V_164 = (struct V_163 * ) V_222 -> V_67 ;
struct V_223 * V_224 = (struct V_223 * ) V_217 ;
struct V_1 * V_2 = F_70 ( V_224 ) ;
struct V_167 * V_168 = F_71 ( V_222 ) ;
if ( ! F_72 ( V_164 -> V_165 ) ||
V_168 -> V_158 & V_225 )
return;
F_59 ( V_2 , V_4 , F_55 ( V_164 ) , V_168 ) ;
}
static void F_73 ( struct V_1 * V_2 , T_1 F_33 ,
struct V_79 * V_100 )
{
F_17 ( V_2 , L_38 ) ;
V_100 -> V_203 = V_210 ;
if ( F_33 ) {
V_100 -> V_226 = V_227 ;
V_100 -> V_228 = V_229 ;
V_100 -> V_230 = V_231 ;
} else {
V_100 -> V_226 = V_232 ;
V_100 -> V_228 = V_233 ;
V_100 -> V_230 = V_234 ;
}
V_100 -> V_235 = 0 ;
V_100 -> V_212 = 0 ;
V_100 -> V_211 = 0 ;
V_100 -> V_236 = V_193 ;
V_100 -> V_237 = 0 ;
}
static int F_74 ( struct V_79 * V_100 ,
const struct V_238 * V_103 )
{
switch ( V_103 -> V_239 ) {
case V_240 :
return V_100 -> V_241 ;
case V_242 :
return V_100 -> V_243 ;
case V_244 :
return V_100 -> V_245 ;
default:
F_31 ( 1 ) ;
}
return V_100 -> V_241 ;
}
static const T_5 * F_75 ( struct V_79 * V_100 ,
const struct V_238 * V_103 ,
T_2 V_61 )
{
const T_5 ( * V_246 ) [ V_74 ] ;
if ( F_31 ( V_103 -> V_239 != V_240 &&
V_103 -> V_239 != V_242 &&
V_103 -> V_239 != V_244 ) )
return V_247 ;
if ( V_103 -> V_239 == V_240 )
return V_247 ;
V_246 = V_248 ;
if ( V_103 -> V_239 == V_242 ) {
switch ( V_61 ) {
case V_151 :
V_246 = V_249 ;
break;
case V_160 :
V_246 = V_250 ;
break;
case V_136 :
V_246 = V_251 ;
break;
default:
F_31 ( 1 ) ;
}
} else if ( V_103 -> V_239 == V_244 ) {
switch ( V_61 ) {
case V_151 :
V_246 = V_248 ;
break;
case V_160 :
V_246 = V_252 ;
break;
case V_136 :
V_246 = V_253 ;
break;
default:
F_31 ( 1 ) ;
}
} else {
F_31 ( 1 ) ;
}
if ( ! V_103 -> V_62 && ! V_100 -> V_254 )
return V_246 [ 0 ] ;
else if ( V_103 -> V_62 && ! V_100 -> V_254 )
return V_246 [ 1 ] ;
else if ( ! V_103 -> V_62 && V_100 -> V_254 )
return V_246 [ 2 ] ;
else
return V_246 [ 3 ] ;
}
static void F_76 ( struct V_79 * V_100 ,
struct V_5 * V_6 )
{
struct V_15 * V_7 = & V_6 -> V_7 ;
const struct V_238 * V_103 = & V_255 [ V_6 -> V_103 ] ;
V_6 -> V_90 = F_75 ( V_100 , V_103 , V_7 -> V_61 ) ;
}
static T_3 F_77 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_5 * V_6 ,
unsigned long V_143 , T_6 V_60 )
{
struct V_5 * V_206 =
& ( V_100 -> V_205 [ V_100 -> V_206 ] ) ;
T_3 V_69 = V_206 -> V_75 [ V_60 ] . V_69 ;
T_5 V_256 = V_206 -> V_90 [ V_60 ] ;
const T_5 * V_257 = V_6 -> V_90 ;
T_5 V_149 ;
T_2 V_258 ;
int V_259 ;
if ( V_69 > V_260 ) {
V_258 = 100 * V_256 ;
F_17 ( V_2 ,
L_39 ,
V_69 , V_258 ) ;
} else {
V_258 = V_100 -> V_261 ;
F_17 ( V_2 ,
L_40 ,
V_69 , V_258 ) ;
}
V_259 = F_78 ( & V_143 , V_262 ) ;
while ( V_259 != V_39 ) {
if ( V_258 < ( 100 * V_257 [ V_259 ] ) )
break;
V_149 = F_45 ( V_2 , V_259 , V_143 ,
V_6 -> V_7 . type ) ;
V_259 = ( V_149 >> 8 ) & 0xff ;
}
F_17 ( V_2 , L_41 ,
V_259 , V_258 ,
V_259 != V_39 ?
100 * V_257 [ V_259 ] : V_70 ) ;
return V_259 ;
}
static T_2 F_79 ( struct V_3 * V_4 )
{
if ( V_4 -> V_263 >= V_264 )
return V_136 ;
else if ( V_4 -> V_263 >= V_265 )
return V_160 ;
return V_151 ;
}
static void F_66 ( struct V_79 * V_100 , bool V_266 )
{
struct V_5 * V_6 ;
int V_206 ;
int V_267 = 0 ;
struct V_1 * V_2 ;
V_2 = V_100 -> V_106 . V_150 ;
V_206 = V_100 -> V_206 ;
V_6 = & ( V_100 -> V_205 [ V_206 ] ) ;
if ( V_100 -> V_203 == V_210 ) {
if ( V_100 -> V_236 )
V_267 =
F_63 ( V_193 ,
( unsigned long ) ( V_100 -> V_236 +
V_268 ) ) ;
if ( V_266 ||
( V_100 -> V_212 > V_100 -> V_228 ) ||
( V_100 -> V_211 > V_100 -> V_230 ) ||
( ( ! V_100 -> V_204 ) &&
( V_100 -> V_236 ) && ( V_267 ) ) ) {
F_17 ( V_2 ,
L_42 ,
V_100 -> V_212 ,
V_100 -> V_211 ,
V_267 ) ;
V_100 -> V_203 = V_269 ;
F_17 ( V_2 ,
L_43 ) ;
V_100 -> V_212 = 0 ;
V_100 -> V_211 = 0 ;
V_100 -> V_236 = 0 ;
V_100 -> V_237 = F_49 ( V_6 -> V_103 ) ;
} else {
V_100 -> V_235 ++ ;
if ( V_100 -> V_235 >=
V_100 -> V_226 ) {
V_100 -> V_235 = 0 ;
F_17 ( V_2 ,
L_44 ) ;
F_19 ( V_2 , V_6 ) ;
}
}
if ( V_100 -> V_203 == V_269 ) {
F_19 ( V_2 , V_6 ) ;
}
}
}
static void F_80 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
struct V_15 * V_7 )
{
F_81 ( V_2 , V_4 , V_100 , V_7 ) ;
F_65 ( V_2 , & V_100 -> V_186 , false ) ;
}
static enum V_270 F_82 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_73 , V_271 , V_272 ;
enum V_270 V_273 ;
const struct V_238 * V_274 = & V_255 [ V_6 -> V_103 ] ;
const struct V_238 * V_275 ;
T_7 V_276 ;
T_1 V_277 = V_2 -> V_13 -> V_14 ;
const T_5 * V_278 ;
T_5 V_97 , V_279 ;
for ( V_73 = 0 ; V_73 < V_280 ; V_73 ++ ) {
V_273 = V_274 -> V_281 [ V_73 ] ;
if ( V_273 == V_104 )
continue;
if ( V_100 -> V_237 & F_49 ( V_273 ) ) {
F_17 ( V_2 , L_45 ,
V_273 ) ;
continue;
}
V_275 = & V_255 [ V_273 ] ;
if ( ! F_20 ( V_277 , V_275 -> V_8 ) ) {
F_17 ( V_2 ,
L_46 ,
V_273 , V_277 , V_275 -> V_8 ) ;
continue;
}
for ( V_271 = 0 ; V_271 < V_282 ; V_271 ++ ) {
V_276 = V_275 -> V_283 [ V_271 ] ;
if ( V_276 && ! V_276 ( V_2 , V_4 , V_6 ) )
break;
}
if ( V_271 != V_282 ) {
F_17 ( V_2 ,
L_47 ,
V_273 , V_271 ) ;
continue;
}
V_97 = V_100 -> V_261 / 100 ;
V_278 = F_75 ( V_100 , V_275 ,
F_79 ( V_4 ) ) ;
if ( F_31 ( ! V_278 ) )
continue;
V_272 = F_74 ( V_100 , V_275 ) ;
if ( F_31 ( V_272 == V_39 ) )
continue;
V_279 = V_278 [ V_272 ] ;
if ( V_97 >= V_279 ) {
F_17 ( V_2 ,
L_48 ,
V_273 , V_279 , V_97 ) ;
continue;
}
F_17 ( V_2 ,
L_49 ,
V_273 , V_279 , V_97 ) ;
break;
}
if ( V_73 == V_280 )
return V_104 ;
return V_273 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_3 * V_4 ,
enum V_270 V_284 )
{
struct V_5 * V_6 = & ( V_100 -> V_205 [ V_100 -> V_206 ] ) ;
struct V_5 * V_285 =
& ( V_100 -> V_205 [ ( 1 - V_100 -> V_206 ) ] ) ;
struct V_15 * V_7 = & V_285 -> V_7 ;
const struct V_238 * V_103 = & V_255 [ V_284 ] ;
const struct V_238 * V_286 = & V_255 [ V_6 -> V_103 ] ;
T_2 V_287 = ( sizeof( struct V_5 ) -
( sizeof( struct V_65 ) * V_74 ) ) ;
unsigned long V_143 = 0 ;
T_2 V_259 = 0 ;
memcpy ( V_285 , V_6 , V_287 ) ;
V_7 -> V_62 = V_103 -> V_62 ;
V_7 -> V_8 = V_103 -> V_8 ;
if ( V_103 -> V_239 == V_240 ) {
if ( V_100 -> V_126 == V_129 )
V_7 -> type = V_52 ;
else
V_7 -> type = V_53 ;
V_7 -> V_61 = V_151 ;
V_7 -> V_63 = false ;
V_143 = V_100 -> V_140 ;
} else if ( V_103 -> V_239 == V_242 ) {
V_7 -> type = V_100 -> F_37 ? V_56 : V_54 ;
V_143 = V_100 -> V_141 ;
} else if ( V_103 -> V_239 == V_244 ) {
V_7 -> type = V_100 -> F_37 ? V_57 : V_55 ;
V_143 = V_100 -> V_142 ;
} else {
F_31 ( L_50 ) ;
}
if ( V_103 -> V_239 != V_240 ) {
V_7 -> V_61 = F_79 ( V_4 ) ;
V_7 -> V_63 = V_100 -> V_63 ;
}
V_285 -> V_103 = V_284 ;
F_76 ( V_100 , V_285 ) ;
V_100 -> V_237 |= F_49 ( V_284 ) ;
if ( V_286 -> V_239 != V_103 -> V_239 ) {
V_259 = F_77 ( V_2 , V_100 , V_285 ,
V_143 , V_7 -> V_60 ) ;
if ( ( V_259 == V_39 ) ||
! ( F_49 ( V_259 ) & V_143 ) ) {
F_17 ( V_2 ,
L_51
L_52 ,
V_259 , V_143 ) ;
goto V_288;
}
V_7 -> V_60 = V_259 ;
}
F_17 ( V_2 , L_53 ,
V_284 , V_7 -> V_60 ) ;
return 0 ;
V_288:
V_7 -> type = V_51 ;
return - 1 ;
}
static enum V_289 F_84 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_3 V_290 , int V_146 , int V_145 ,
int V_291 ,
int V_292 , int V_293 )
{
enum V_289 V_294 = V_295 ;
if ( ( V_290 <= V_296 ) || ( V_291 == 0 ) ) {
F_17 ( V_2 ,
L_54 ) ;
return V_297 ;
}
if ( ( V_292 == V_70 ) &&
( V_293 == V_70 ) &&
( V_145 != V_39 ) ) {
F_17 ( V_2 ,
L_55 ) ;
return V_298 ;
}
if ( ( V_293 == V_70 ) &&
( V_145 != V_39 ) &&
( V_292 != V_70 ) &&
( V_292 < V_291 ) ) {
F_17 ( V_2 ,
L_56 ) ;
return V_298 ;
}
if ( ( V_293 != V_70 ) &&
( V_293 > V_291 ) ) {
F_17 ( V_2 ,
L_57 ) ;
return V_298 ;
}
if ( ( V_292 != V_70 ) &&
( V_293 != V_70 ) &&
( V_292 < V_291 ) &&
( V_293 < V_291 ) ) {
F_17 ( V_2 ,
L_58 ) ;
return V_295 ;
}
if ( ( V_292 != V_70 ) &&
( V_292 > V_291 ) ) {
F_17 ( V_2 ,
L_59 ) ;
V_294 = V_297 ;
goto V_299;
}
if ( ( V_292 == V_70 ) &&
( V_146 != V_39 ) ) {
F_17 ( V_2 ,
L_60 ) ;
V_294 = V_297 ;
goto V_299;
}
F_17 ( V_2 , L_61 ) ;
V_299:
if ( ( V_294 == V_297 ) && ( V_146 != V_39 ) ) {
if ( V_290 >= V_260 ) {
F_17 ( V_2 ,
L_62 ) ;
V_294 = V_295 ;
} else if ( V_291 > ( 100 * V_6 -> V_90 [ V_146 ] ) ) {
F_17 ( V_2 ,
L_63 ) ;
V_294 = V_295 ;
} else {
F_17 ( V_2 , L_64 ) ;
}
}
return V_294 ;
}
static bool F_85 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_79 * V_100 )
{
struct V_181 * V_182 = F_60 ( V_4 ) ;
struct V_300 * V_301 = V_182 -> V_301 ;
bool V_302 = ( V_301 -> type == V_303 &&
! V_301 -> V_304 . V_305 ) ;
if ( ! V_100 -> V_64 )
return false ;
if ( ! V_2 -> V_306 && ! V_302 )
return false ;
if ( ! F_5 ( V_2 , V_4 ) )
return false ;
return true ;
}
static void F_86 ( struct V_1 * V_2 , int V_60 ,
int * V_307 , int * V_308 )
{
* V_307 = V_60 + V_309 ;
if ( * V_307 > V_110 )
* V_307 = V_310 ;
* V_308 = V_60 - V_309 ;
if ( * V_308 < 0 )
* V_308 = V_310 ;
}
static bool F_87 ( struct V_1 * V_2 , struct V_300 * V_301 ,
struct V_15 * V_7 , enum V_125 V_126 )
{
int V_60 = V_7 -> V_60 ;
bool V_311 = ( V_312 . V_313 == V_314 ) ;
bool V_302 = ( V_301 -> type == V_303 &&
! V_301 -> V_304 . V_305 ) ;
F_17 ( V_2 , L_65 ,
V_311 , V_302 ) ;
if ( ( V_311 || V_302 ) &&
! F_88 ( V_2 , V_126 ) )
return false ;
F_17 ( V_2 , L_66 , V_7 -> type ) ;
if ( F_33 ( V_7 ) )
return V_60 == V_315 ;
if ( F_34 ( V_7 ) )
return V_60 == V_316 ;
if ( F_37 ( V_7 ) )
return V_60 == V_316 ||
V_60 == V_317 ||
V_60 == V_152 ;
F_31 ( 1 ) ;
return false ;
}
static enum V_318 F_89 ( struct V_1 * V_2 ,
T_3 V_290 , int V_319 , int V_320 ,
int V_291 ,
int V_321 , int V_322 )
{
if ( V_291 == V_70 ) {
F_17 ( V_2 , L_67 ) ;
return V_323 ;
}
if ( V_290 <= V_324 || V_291 == 0 ) {
F_17 ( V_2 , L_68 ) ;
return V_325 ;
}
if ( V_319 != V_310 ) {
if ( V_321 == V_70 &&
( V_322 == V_70 ||
V_291 >= V_322 ) ) {
F_17 ( V_2 ,
L_69 ) ;
return V_326 ;
}
if ( V_321 > V_291 ) {
F_17 ( V_2 ,
L_70 ) ;
return V_326 ;
}
}
if ( V_290 < V_327 && V_320 != V_310 ) {
if ( V_321 == V_70 &&
V_322 != V_70 &&
V_291 < V_322 ) {
F_17 ( V_2 ,
L_71 ) ;
return V_328 ;
}
if ( V_321 < V_291 &&
( V_322 == V_70 ||
V_322 > V_291 ) ) {
F_17 ( V_2 ,
L_72 ) ;
return V_328 ;
}
}
F_17 ( V_2 , L_73 ) ;
return V_323 ;
}
static bool F_90 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
struct V_5 * V_6 )
{
struct V_181 * V_329 = ( void * ) V_4 -> V_330 ;
struct V_300 * V_301 = V_329 -> V_301 ;
struct V_331 * V_332 ;
enum V_125 V_126 ;
struct V_65 * V_66 ;
struct V_15 * V_7 = & V_6 -> V_7 ;
enum V_318 V_294 ;
T_3 V_290 ;
T_1 V_333 = V_100 -> V_186 . V_334 ;
int V_291 ;
int V_319 , V_320 ;
int V_321 = V_70 , V_322 = V_70 ;
#ifdef F_61
if ( V_100 -> V_106 . V_335 <= V_110 ) {
F_17 ( V_2 , L_74 ,
V_100 -> V_106 . V_335 ) ;
V_100 -> V_186 . V_334 = V_100 -> V_106 . V_335 ;
return V_333 != V_100 -> V_106 . V_335 ;
}
#endif
F_91 () ;
V_332 = F_92 ( V_301 -> V_332 ) ;
if ( F_93 ( ! V_332 ) )
V_126 = V_336 ;
else
V_126 = V_332 -> V_337 . V_338 -> V_126 ;
F_94 () ;
if ( ! F_87 ( V_2 , V_301 , V_7 , V_126 ) ) {
F_17 ( V_2 ,
L_75 ) ;
V_100 -> V_186 . V_334 = V_339 ;
return V_333 != V_339 ;
}
F_86 ( V_2 , V_333 , & V_319 , & V_320 ) ;
V_66 = V_6 -> V_76 ;
V_290 = V_66 [ V_333 ] . V_69 ;
V_291 = V_66 [ V_333 ] . V_72 ;
if ( V_319 != V_310 )
V_321 = V_66 [ V_319 ] . V_72 ;
if ( V_320 != V_310 )
V_322 = V_66 [ V_320 ] . V_72 ;
F_17 ( V_2 ,
L_76 ,
V_333 , V_291 , V_290 , V_319 , V_320 ,
V_321 , V_322 ) ;
V_294 = F_89 ( V_2 , V_290 , V_319 , V_320 ,
V_291 , V_321 , V_322 ) ;
if ( V_319 == V_310 && V_294 == V_326 ) {
F_17 ( V_2 , L_77 ) ;
V_294 = V_323 ;
} else if ( V_320 == V_310 &&
( V_294 == V_328 ||
V_294 == V_325 ) ) {
F_17 ( V_2 , L_78 ) ;
V_294 = V_323 ;
}
switch ( V_294 ) {
case V_326 :
V_100 -> V_186 . V_334 = V_319 ;
return true ;
case V_328 :
V_100 -> V_186 . V_334 = V_320 ;
return true ;
case V_325 :
V_100 -> V_186 . V_334 = V_339 ;
return true ;
case V_323 :
break;
}
return false ;
}
static void F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
int V_81 )
{
int V_146 = V_39 ;
int V_145 = V_39 ;
int V_60 ;
struct V_65 * V_66 = NULL ;
int V_291 = V_70 ;
int V_292 = V_70 ;
int V_293 = V_70 ;
T_2 V_96 ;
enum V_289 V_340 = V_295 ;
T_5 V_143 ;
T_1 V_341 = 0 ;
struct V_5 * V_6 , * V_342 ;
T_1 V_206 = 0 ;
T_1 V_343 = 0 ;
T_5 V_149 ;
T_3 V_290 ;
T_1 V_344 = V_100 -> V_254 ;
struct V_181 * V_345 = ( void * ) V_4 -> V_330 ;
struct V_346 * V_347 ;
struct V_15 * V_7 ;
V_100 -> V_254 = ! ! V_345 -> V_348 ;
if ( ! V_100 -> V_204 )
V_206 = V_100 -> V_206 ;
else
V_206 = 1 - V_100 -> V_206 ;
V_6 = & ( V_100 -> V_205 [ V_206 ] ) ;
V_7 = & V_6 -> V_7 ;
if ( V_344 != V_100 -> V_254 ) {
F_17 ( V_2 ,
L_79 ,
V_344 , V_100 -> V_254 ) ;
F_76 ( V_100 , V_6 ) ;
F_19 ( V_2 , V_6 ) ;
}
V_60 = V_100 -> V_349 ;
V_143 = F_43 ( V_100 , V_7 ) ;
if ( ! ( F_49 ( V_60 ) & V_143 ) ) {
F_24 ( V_2 , L_80 ) ;
if ( V_100 -> V_204 ) {
V_7 -> type = V_51 ;
V_100 -> V_204 = 0 ;
V_6 = & ( V_100 -> V_205 [ V_100 -> V_206 ] ) ;
F_80 ( V_2 , V_4 , V_100 , & V_6 -> V_7 ) ;
}
return;
}
if ( ! V_6 -> V_90 ) {
F_24 ( V_2 , L_81 ) ;
return;
}
V_66 = & ( V_6 -> V_75 [ V_60 ] ) ;
V_96 = V_66 -> V_71 - V_66 -> V_68 ;
if ( ( V_96 < V_98 ) &&
( V_66 -> V_68 < V_99 ) ) {
F_17 ( V_2 ,
L_82 ,
F_15 ( V_7 -> type ) ,
V_60 , V_66 -> V_68 , V_66 -> V_71 ) ;
V_66 -> V_72 = V_70 ;
F_66 ( V_100 , false ) ;
goto V_299;
}
if ( V_66 -> V_72 != ( ( V_66 -> V_69 *
V_6 -> V_90 [ V_60 ] + 64 ) / 128 ) ) {
V_66 -> V_72 = ( ( V_66 -> V_69 *
V_6 -> V_90 [ V_60 ] + 64 ) / 128 ) ;
}
if ( V_100 -> V_204 ) {
if ( V_66 -> V_72 > V_100 -> V_261 ) {
F_17 ( V_2 ,
L_83
L_84 ,
V_66 -> V_69 ,
V_66 -> V_72 ,
V_100 -> V_261 ) ;
V_100 -> V_206 = V_206 ;
V_291 = V_66 -> V_72 ;
} else {
F_17 ( V_2 ,
L_85
L_84 ,
V_66 -> V_69 ,
V_66 -> V_72 ,
V_100 -> V_261 ) ;
V_7 -> type = V_51 ;
V_206 = V_100 -> V_206 ;
V_6 = & ( V_100 -> V_205 [ V_206 ] ) ;
V_60 = V_6 -> V_7 . V_60 ;
V_291 = V_100 -> V_261 ;
V_341 = 1 ;
}
V_100 -> V_204 = 0 ;
V_343 = 1 ;
goto V_350;
}
V_149 = F_45 ( V_2 , V_60 , V_143 , V_7 -> type ) ;
V_146 = V_149 & 0xff ;
V_145 = ( V_149 >> 8 ) & 0xff ;
V_290 = V_66 -> V_69 ;
V_291 = V_66 -> V_72 ;
if ( V_146 != V_39 )
V_292 = V_6 -> V_75 [ V_146 ] . V_72 ;
if ( V_145 != V_39 )
V_293 = V_6 -> V_75 [ V_145 ] . V_72 ;
F_17 ( V_2 ,
L_86 ,
F_15 ( V_7 -> type ) , V_60 , V_291 , V_290 ,
V_146 , V_145 , V_292 , V_293 ) ;
V_340 = F_84 ( V_2 , V_6 , V_290 , V_146 , V_145 ,
V_291 , V_292 , V_293 ) ;
if ( F_95 ( V_7 ) &&
! F_5 ( V_2 , V_4 ) ) {
F_17 ( V_2 ,
L_87 ) ;
F_66 ( V_100 , true ) ;
goto V_350;
}
switch ( V_340 ) {
case V_297 :
if ( V_146 != V_39 ) {
V_341 = 1 ;
V_60 = V_146 ;
} else {
F_17 ( V_2 ,
L_88 ) ;
}
break;
case V_298 :
if ( V_145 != V_39 ) {
V_341 = 1 ;
V_60 = V_145 ;
} else {
F_17 ( V_2 ,
L_89 ) ;
}
break;
case V_295 :
if ( V_100 -> V_203 == V_210 )
V_341 = F_90 ( V_2 , V_4 , V_100 , V_6 ) ;
break;
default:
break;
}
V_350:
if ( V_341 ) {
V_6 -> V_7 . V_60 = V_60 ;
F_80 ( V_2 , V_4 , V_100 , & V_6 -> V_7 ) ;
}
F_66 ( V_100 , false ) ;
if ( ! V_341 && ! V_343 &&
V_100 -> V_203 == V_269
&& V_66 -> V_71 ) {
enum V_270 V_351 ;
V_100 -> V_261 = V_291 ;
F_17 ( V_2 ,
L_90 ,
V_341 , V_343 , V_100 -> V_203 ,
V_66 -> V_71 ) ;
V_351 = F_82 ( V_2 , V_100 , V_4 , V_6 ) ;
if ( V_351 != V_104 ) {
int V_82 = F_83 ( V_2 , V_100 , V_4 ,
V_351 ) ;
if ( ! V_82 )
V_100 -> V_204 = 1 ;
} else {
F_17 ( V_2 ,
L_91 ) ;
V_100 -> V_203 = V_352 ;
}
if ( V_100 -> V_204 ) {
V_6 = & ( V_100 -> V_205 [ ( 1 - V_100 -> V_206 ) ] ) ;
F_19 ( V_2 , V_6 ) ;
V_60 = V_6 -> V_7 . V_60 ;
F_16 ( V_2 , & V_6 -> V_7 ,
L_92 ) ;
F_81 ( V_2 , V_4 , V_100 , & V_6 -> V_7 ) ;
F_65 ( V_2 , & V_100 -> V_186 , false ) ;
} else {
V_343 = 1 ;
}
}
if ( V_343 && V_100 -> V_203 == V_352 ) {
V_342 = & ( V_100 -> V_205 [ V_100 -> V_206 ] ) ;
if ( F_33 ( & V_342 -> V_7 ) ) {
F_17 ( V_2 , L_93 ) ;
if ( V_81 != V_85 ) {
V_347 = & V_345 -> V_347 [ V_81 ] ;
if ( V_347 -> V_353 != V_354 ) {
F_17 ( V_2 ,
L_94 ,
V_81 ) ;
F_25 ( V_4 , V_81 ) ;
}
}
F_73 ( V_2 , 1 , V_100 ) ;
} else {
if ( ( V_100 -> V_261 > V_355 ) &&
( V_100 -> V_356 & ( 1 << V_81 ) ) &&
( V_81 != V_85 ) ) {
V_347 = & V_345 -> V_347 [ V_81 ] ;
if ( V_347 -> V_353 == V_354 ) {
F_17 ( V_2 ,
L_95 ,
V_81 ) ;
F_26 ( V_2 , V_81 ,
V_100 , V_4 ) ;
}
}
F_73 ( V_2 , 0 , V_100 ) ;
}
}
V_299:
V_100 -> V_349 = V_60 ;
}
static void F_96 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
enum V_125 V_126 ,
struct V_15 * V_7 )
{
int V_73 , V_357 ;
T_6 V_358 = V_359 ;
T_1 V_360 = V_41 ;
T_1 V_14 = V_2 -> V_13 -> V_14 ;
const struct V_361 * V_362 ;
for ( V_73 = 0 ; V_73 < F_13 ( V_100 -> V_106 . V_363 ) ; V_73 ++ ) {
if ( ! ( V_100 -> V_106 . V_364 & F_49 ( V_73 ) ) )
continue;
if ( V_100 -> V_106 . V_363 [ V_73 ] > V_358 ) {
V_358 = V_100 -> V_106 . V_363 [ V_73 ] ;
V_360 = F_49 ( V_73 ) ;
}
}
F_17 ( V_2 , L_96 ,
F_14 ( V_360 ) , V_358 ) ;
if ( V_360 != V_42 && V_360 != V_43 )
V_7 -> V_8 = F_52 ( V_14 ) ;
else
V_7 -> V_8 = V_360 ;
V_7 -> V_62 = false ;
V_7 -> V_63 = false ;
V_7 -> V_61 = V_151 ;
V_7 -> V_60 = F_78 ( & V_100 -> V_140 ,
V_262 ) ;
if ( V_126 == V_129 ) {
V_7 -> type = V_52 ;
V_362 = V_365 ;
V_357 = F_13 ( V_365 ) ;
} else {
V_7 -> type = V_53 ;
V_362 = V_366 ;
V_357 = F_13 ( V_366 ) ;
}
if ( V_367 ) {
for ( V_73 = 0 ; V_73 < V_357 ; V_73 ++ ) {
int V_259 = V_362 [ V_73 ] . V_259 ;
if ( ( V_358 >= V_362 [ V_73 ] . V_368 ) &&
( F_49 ( V_259 ) & V_100 -> V_140 ) ) {
V_7 -> V_60 = V_259 ;
break;
}
}
}
F_17 ( V_2 , L_97 , V_7 -> V_60 ,
F_14 ( V_7 -> V_8 ) ) ;
}
void F_97 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_369 * V_370 )
{
V_100 -> V_106 . V_364 = V_370 -> V_364 ;
V_100 -> V_106 . V_363 [ 0 ] = V_370 -> V_363 [ 0 ] ;
V_100 -> V_106 . V_363 [ 1 ] = V_370 -> V_363 [ 1 ] ;
V_100 -> V_106 . V_363 [ 2 ] = V_370 -> V_363 [ 2 ] ;
}
static void F_98 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
enum V_125 V_126 ,
bool V_371 )
{
struct V_5 * V_6 ;
struct V_15 * V_7 ;
T_1 V_206 = 0 ;
if ( ! V_4 || ! V_100 )
return;
if ( ! V_100 -> V_204 )
V_206 = V_100 -> V_206 ;
else
V_206 = 1 - V_100 -> V_206 ;
V_6 = & ( V_100 -> V_205 [ V_206 ] ) ;
V_7 = & V_6 -> V_7 ;
F_96 ( V_2 , V_100 , V_126 , V_7 ) ;
V_100 -> V_349 = V_7 -> V_60 ;
F_31 ( V_7 -> V_8 != V_42 && V_7 -> V_8 != V_43 ) ;
if ( V_7 -> V_8 == V_42 )
V_6 -> V_103 = V_372 ;
else
V_6 -> V_103 = V_373 ;
F_76 ( V_100 , V_6 ) ;
F_81 ( V_2 , V_4 , V_100 , V_7 ) ;
F_65 ( V_2 , & V_100 -> V_186 , V_371 ) ;
}
static void F_99 ( void * V_217 , struct V_3 * V_4 , void * V_329 ,
struct V_374 * V_375 )
{
struct V_221 * V_222 = V_375 -> V_222 ;
struct V_223 * V_224 V_376 =
(struct V_223 * ) V_217 ;
struct V_1 * V_2 V_376 = F_70 ( V_224 ) ;
struct V_167 * V_168 = F_71 ( V_222 ) ;
struct V_79 * V_100 = V_329 ;
if ( V_100 && ! V_100 -> V_106 . V_150 ) {
F_17 ( V_2 , L_28 ) ;
V_329 = NULL ;
}
if ( F_100 ( V_4 , V_329 , V_375 ) )
return;
F_101 ( V_100 -> V_215 ,
V_168 -> V_126 , & V_168 -> V_377 . V_189 [ 0 ] ) ;
V_168 -> V_377 . V_189 [ 0 ] . V_213 = 1 ;
}
static void * F_102 ( void * V_378 , struct V_3 * V_4 ,
T_8 V_379 )
{
struct V_181 * V_345 = (struct V_181 * ) V_4 -> V_330 ;
struct V_223 * V_224 = (struct V_223 * ) V_378 ;
struct V_1 * V_2 = F_70 ( V_224 ) ;
struct V_79 * V_100 = & V_345 -> V_100 ;
F_17 ( V_2 , L_98 ) ;
V_100 -> V_106 . V_150 = V_2 ;
#ifdef F_61
V_100 -> V_106 . V_183 = 0 ;
V_100 -> V_106 . V_335 = V_310 ;
#endif
V_100 -> V_106 . V_364 = 0 ;
memset ( V_100 -> V_106 . V_363 , 0 , sizeof( V_100 -> V_106 . V_363 ) ) ;
return & V_345 -> V_100 ;
}
static int F_103 ( struct V_17 * V_18 ,
int V_128 )
{
T_5 V_380 = F_104 ( V_18 -> V_381 . V_382 ) &
( 0x3 << ( 2 * ( V_128 - 1 ) ) ) ;
V_380 >>= ( 2 * ( V_128 - 1 ) ) ;
if ( V_380 == V_383 )
return V_316 ;
else if ( V_380 == V_384 )
return V_317 ;
else if ( V_380 == V_385 )
return V_152 ;
F_31 ( V_380 != V_386 ) ;
return - 1 ;
}
static void F_105 ( struct V_3 * V_4 ,
struct V_17 * V_18 ,
struct V_79 * V_100 )
{
int V_73 ;
int V_387 = F_103 ( V_18 , 1 ) ;
if ( V_387 >= V_28 ) {
for ( V_73 = V_28 ; V_73 <= V_387 ; V_73 ++ ) {
if ( V_73 == V_29 )
continue;
if ( V_73 == V_152 &&
V_4 -> V_263 == V_388 )
continue;
V_100 -> V_141 |= F_49 ( V_73 ) ;
}
}
if ( V_4 -> V_389 < 2 )
return;
V_387 = F_103 ( V_18 , 2 ) ;
if ( V_387 >= V_28 ) {
for ( V_73 = V_28 ; V_73 <= V_387 ; V_73 ++ ) {
if ( V_73 == V_29 )
continue;
if ( V_73 == V_152 &&
V_4 -> V_263 == V_388 )
continue;
V_100 -> V_142 |= F_49 ( V_73 ) ;
}
}
}
static void F_106 ( struct V_1 * V_2 ,
struct V_390 * V_391 )
{
F_107 ( & V_2 -> V_392 ) ;
memset ( V_391 , 0 , sizeof( * V_391 ) ) ;
F_108 ( & V_2 -> V_392 ) ;
}
void F_109 ( struct V_1 * V_2 ,
struct V_390 * V_391 ,
T_2 V_7 , bool V_393 )
{
T_1 V_128 = 0 , V_394 = 0 ;
F_110 ( & V_2 -> V_392 ) ;
if ( V_393 )
V_391 -> V_395 ++ ;
V_391 -> V_396 ++ ;
switch ( V_7 & V_130 ) {
case V_151 :
V_391 -> V_397 ++ ;
break;
case V_160 :
V_391 -> V_398 ++ ;
break;
case V_136 :
V_391 -> V_399 ++ ;
break;
default:
F_111 ( 1 , L_99 , V_7 ) ;
}
if ( V_7 & V_26 ) {
V_391 -> V_400 ++ ;
V_394 = V_7 & V_27 ;
V_128 = ( ( V_7 & V_131 ) >> V_132 ) + 1 ;
} else if ( V_7 & V_32 ) {
V_391 -> V_401 ++ ;
V_394 = V_7 & V_33 ;
V_128 = ( ( V_7 & V_133 ) >>
V_134 ) + 1 ;
} else {
V_391 -> V_402 ++ ;
}
if ( V_128 == 1 )
V_391 -> V_403 ++ ;
else if ( V_128 == 2 )
V_391 -> V_404 ++ ;
if ( V_7 & V_123 )
V_391 -> V_405 ++ ;
else
V_391 -> V_406 ++ ;
V_391 -> V_407 [ V_391 -> V_408 ] = V_7 ;
V_391 -> V_408 = ( V_391 -> V_408 + 1 ) %
F_13 ( V_391 -> V_407 ) ;
F_112 ( & V_2 -> V_392 ) ;
}
void F_64 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_125 V_126 , bool V_371 )
{
int V_73 , V_271 ;
struct V_409 * V_410 = V_2 -> V_410 ;
struct V_16 * V_9 = & V_4 -> V_9 ;
struct V_17 * V_18 = & V_4 -> V_18 ;
struct V_181 * V_345 ;
struct V_79 * V_100 ;
struct V_218 * V_219 ;
unsigned long V_411 ;
V_345 = (struct V_181 * ) V_4 -> V_330 ;
V_100 = & V_345 -> V_100 ;
memset ( V_100 , 0 , F_113 ( F_114 ( * V_100 ) , V_106 ) ) ;
V_219 = V_410 -> V_412 -> V_413 [ V_126 ] ;
V_100 -> V_186 . V_414 = V_345 -> V_414 ;
for ( V_271 = 0 ; V_271 < V_415 ; V_271 ++ )
F_19 ( V_2 , & V_100 -> V_205 [ V_271 ] ) ;
V_100 -> V_236 = 0 ;
V_100 -> V_194 = V_193 ;
F_17 ( V_2 ,
L_100 ,
V_345 -> V_414 ) ;
V_100 -> V_201 = V_202 ;
V_100 -> V_126 = V_219 -> V_126 ;
V_411 = V_4 -> V_216 [ V_219 -> V_126 ] ;
V_100 -> V_140 = 0 ;
F_115 (i, &supp, BITS_PER_LONG)
V_100 -> V_140 |= F_49 ( V_219 -> V_416 [ V_73 ] . V_417 ) ;
if ( ! V_18 || ! V_18 -> V_418 ) {
V_100 -> V_141 = V_9 -> V_394 . V_419 [ 0 ] << 1 ;
V_100 -> V_141 |= V_9 -> V_394 . V_419 [ 0 ] & 0x1 ;
V_100 -> V_141 &= ~ ( ( T_5 ) 0x2 ) ;
V_100 -> V_141 <<= V_188 ;
V_100 -> V_142 = V_9 -> V_394 . V_419 [ 1 ] << 1 ;
V_100 -> V_142 |= V_9 -> V_394 . V_419 [ 1 ] & 0x1 ;
V_100 -> V_142 &= ~ ( ( T_5 ) 0x2 ) ;
V_100 -> V_142 <<= V_188 ;
V_100 -> F_37 = false ;
if ( V_2 -> V_420 -> V_421 -> V_63 &&
( V_9 -> V_19 & V_422 ) )
V_100 -> V_63 = true ;
if ( V_2 -> V_420 -> V_421 -> V_64 &&
( F_4 ( V_2 -> V_13 -> V_14 ) > 1 ) &&
( V_9 -> V_19 & V_423 ) )
V_100 -> V_64 = true ;
} else {
F_105 ( V_4 , V_18 , V_100 ) ;
V_100 -> F_37 = true ;
if ( V_2 -> V_420 -> V_421 -> V_63 &&
( V_18 -> V_19 & V_424 ) )
V_100 -> V_63 = true ;
if ( V_2 -> V_420 -> V_421 -> V_64 &&
( F_4 ( V_2 -> V_13 -> V_14 ) > 1 ) &&
( V_18 -> V_19 & V_425 ) )
V_100 -> V_64 = true ;
}
if ( V_426 )
V_100 -> V_142 = 0 ;
V_100 -> V_241 = F_116 ( & V_100 -> V_140 ,
V_262 ) ;
V_100 -> V_243 = F_116 ( & V_100 -> V_141 ,
V_262 ) ;
V_100 -> V_245 = F_116 ( & V_100 -> V_142 ,
V_262 ) ;
F_17 ( V_2 ,
L_101 ,
V_100 -> V_140 ,
V_100 -> V_141 ,
V_100 -> V_142 ,
V_100 -> F_37 , V_100 -> V_63 , V_100 -> V_64 ) ;
F_17 ( V_2 , L_102 ,
V_100 -> V_241 ,
V_100 -> V_243 ,
V_100 -> V_245 ) ;
V_100 -> V_186 . V_427 =
F_52 ( V_2 -> V_13 -> V_14 ) ;
V_100 -> V_186 . V_428 = V_44 ;
V_100 -> V_356 = V_429 ;
V_100 -> V_254 = 0 ;
#ifdef F_117
F_106 ( V_2 , & V_2 -> V_430 ) ;
#endif
F_98 ( V_2 , V_4 , V_100 , V_126 , V_371 ) ;
}
static void F_118 ( void * V_217 ,
struct V_218 * V_219 ,
struct V_431 * V_432 ,
struct V_3 * V_4 , void * V_220 ,
T_2 V_433 )
{
T_1 V_81 ;
struct V_223 * V_224 =
(struct V_223 * ) V_217 ;
struct V_1 * V_2 = F_70 ( V_224 ) ;
for ( V_81 = 0 ; V_81 < V_85 ; V_81 ++ )
F_25 ( V_4 , V_81 ) ;
F_64 ( V_2 , V_4 , V_219 -> V_126 , false ) ;
}
static void F_119 ( struct V_1 * V_2 ,
struct V_172 * V_434 ,
enum V_125 V_126 ,
T_2 V_111 )
{
struct V_15 V_7 ;
int V_73 ;
int V_435 = F_13 ( V_434 -> V_187 ) ;
T_9 V_436 = F_120 ( V_111 ) ;
T_1 V_8 = ( V_111 & V_113 ) >> V_112 ;
for ( V_73 = 0 ; V_73 < V_435 ; V_73 ++ )
V_434 -> V_187 [ V_73 ] = V_436 ;
F_41 ( V_111 , V_126 , & V_7 ) ;
if ( F_95 ( & V_7 ) )
V_434 -> V_437 = V_435 - 1 ;
else
V_434 -> V_437 = 0 ;
V_434 -> V_334 = 0 ;
if ( F_4 ( V_8 ) == 1 )
V_434 -> V_427 = V_8 ;
V_434 -> V_438 = V_439 ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_15 * V_7 ,
T_9 * V_187 , int * V_440 ,
int V_435 , int V_441 ,
T_1 V_14 , bool V_442 )
{
int V_73 , V_271 ;
T_9 V_111 ;
bool V_443 = false ;
int V_444 = V_7 -> V_60 ;
int V_445 = V_446 ;
int V_60 = * V_440 ;
for ( V_73 = 0 ; V_73 < V_435 && V_60 < V_445 ; V_73 ++ ) {
V_111 = F_120 ( F_32 ( V_2 , V_7 ) ) ;
for ( V_271 = 0 ; V_271 < V_441 && V_60 < V_445 ; V_271 ++ , V_60 ++ )
V_187 [ V_60 ] = V_111 ;
if ( V_442 )
F_42 ( V_14 , V_7 ) ;
V_444 = V_7 -> V_60 ;
V_443 = F_50 ( V_100 , V_7 ) ;
if ( V_443 && ! F_33 ( V_7 ) )
break;
}
if ( ! V_443 )
V_7 -> V_60 = V_444 ;
* V_440 = V_60 ;
}
static void F_122 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
const struct V_15 * V_447 )
{
struct V_15 V_7 ;
int V_435 , V_441 , V_60 = 0 ;
T_1 V_14 = 0 ;
struct V_172 * V_434 = & V_100 -> V_186 ;
bool V_442 = false ;
memcpy ( & V_7 , V_447 , sizeof( V_7 ) ) ;
V_14 = V_2 -> V_13 -> V_14 ;
V_7 . V_64 = F_85 ( V_2 , V_4 , V_100 ) ;
if ( F_40 ( & V_7 ) ) {
V_435 = V_448 ;
V_441 = V_449 ;
} else if ( F_95 ( & V_7 ) ) {
V_435 = V_450 ;
V_441 = V_449 ;
} else {
V_435 = V_451 ;
V_441 = V_452 ;
V_442 = true ;
}
F_121 ( V_2 , V_100 , & V_7 , V_434 -> V_187 , & V_60 ,
V_435 , V_441 , V_14 ,
V_442 ) ;
F_51 ( V_100 , & V_7 ) ;
if ( F_40 ( & V_7 ) ) {
V_435 = V_453 ;
V_441 = V_454 ;
V_434 -> V_437 = V_60 ;
} else if ( F_33 ( & V_7 ) ) {
V_435 = V_455 ;
V_441 = V_452 ;
} else {
F_31 ( 1 ) ;
}
V_442 = true ;
F_121 ( V_2 , V_100 , & V_7 , V_434 -> V_187 , & V_60 ,
V_435 , V_441 , V_14 ,
V_442 ) ;
F_51 ( V_100 , & V_7 ) ;
V_435 = V_455 ;
V_441 = V_452 ;
F_121 ( V_2 , V_100 , & V_7 , V_434 -> V_187 , & V_60 ,
V_435 , V_441 , V_14 ,
V_442 ) ;
}
static void F_81 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
const struct V_15 * V_447 )
{
struct V_172 * V_434 = & V_100 -> V_186 ;
struct V_181 * V_182 ;
struct V_456 * V_457 ;
V_434 -> V_458 = V_459 ;
V_434 -> V_460 =
F_123 ( V_461 ) ;
#ifdef F_61
if ( V_100 -> V_106 . V_183 ) {
F_119 ( V_2 , V_434 ,
V_100 -> V_126 ,
V_100 -> V_106 . V_183 ) ;
return;
}
#endif
if ( F_31 ( ! V_4 || ! V_447 ) )
return;
F_122 ( V_2 , V_4 , V_100 , V_447 ) ;
if ( F_4 ( V_447 -> V_8 ) == 1 )
V_434 -> V_427 = V_447 -> V_8 ;
V_182 = F_60 ( V_4 ) ;
V_457 = F_124 ( V_182 -> V_301 ) ;
if ( F_4 ( V_447 -> V_8 ) == 1 )
V_434 -> V_427 = V_447 -> V_8 ;
V_434 -> V_438 = V_182 -> V_462 ;
if ( F_125 ( V_457 ) ) {
V_434 -> V_438 -- ;
if ( V_2 -> V_463 )
V_434 -> V_438 =
F_67 ( V_434 -> V_438 ,
V_2 -> V_463 ) ;
}
if ( V_182 -> V_301 -> V_464 )
V_434 -> V_158 |= V_465 ;
V_434 -> V_460 =
F_123 ( F_126 ( V_2 , V_4 ) ) ;
}
static void * F_127 ( struct V_409 * V_410 , struct V_466 * V_467 )
{
return V_410 -> V_468 ;
}
static void F_128 ( void * V_378 )
{
return;
}
static void F_129 ( void * V_217 , struct V_3 * V_4 ,
void * V_329 )
{
struct V_223 * V_224 V_376 = V_217 ;
struct V_1 * V_2 V_376 = F_70 ( V_224 ) ;
F_17 ( V_2 , L_103 ) ;
F_17 ( V_2 , L_104 ) ;
}
int F_130 ( char * V_469 , const T_2 V_7 )
{
char * type , * V_61 ;
T_1 V_394 = 0 , V_128 = 0 ;
T_1 V_8 = ( V_7 & V_113 ) >> V_112 ;
if ( ! ( V_7 & V_26 ) &&
! ( V_7 & V_32 ) ) {
int V_60 = F_12 ( V_7 ) ;
return sprintf ( V_469 , L_105 ,
F_14 ( V_8 ) ,
V_60 == V_39 ? L_106 :
V_470 [ V_60 ] . V_471 ) ;
}
if ( V_7 & V_32 ) {
type = L_107 ;
V_394 = V_7 & V_33 ;
V_128 = ( ( V_7 & V_133 )
>> V_134 ) + 1 ;
} else if ( V_7 & V_26 ) {
type = L_108 ;
V_394 = V_7 & V_472 ;
} else {
type = L_109 ;
}
switch ( V_7 & V_130 ) {
case V_151 :
V_61 = L_110 ;
break;
case V_160 :
V_61 = L_111 ;
break;
case V_136 :
V_61 = L_112 ;
break;
case V_135 :
V_61 = L_113 ;
break;
default:
V_61 = L_114 ;
}
return sprintf ( V_469 , L_115 ,
type , F_14 ( V_8 ) , V_61 , V_394 , V_128 ,
( V_7 & V_123 ) ? L_116 : L_117 ,
( V_7 & V_473 ) ? L_118 : L_119 ,
( V_7 & V_124 ) ? L_120 : L_119 ,
( V_7 & V_474 ) ? L_121 : L_119 ,
( V_7 & V_475 ) ? L_122 : L_119 ) ;
}
static void F_131 ( struct V_1 * V_2 ,
struct V_79 * V_100 )
{
V_100 -> V_140 = 0x0FFF ;
V_100 -> V_141 = 0x1FD0 ;
V_100 -> V_142 = 0x1FD0 ;
F_17 ( V_2 , L_123 ,
V_100 -> V_186 . V_414 , V_100 -> V_106 . V_183 ) ;
if ( V_100 -> V_106 . V_183 ) {
F_81 ( V_2 , NULL , V_100 , NULL ) ;
F_65 ( V_100 -> V_106 . V_150 , & V_100 -> V_186 , false ) ;
}
}
static T_10 F_132 ( struct V_476 * V_476 ,
const char T_11 * V_477 , T_12 V_213 , T_13 * V_478 )
{
struct V_79 * V_100 = V_476 -> V_479 ;
struct V_1 * V_2 ;
char V_469 [ 64 ] ;
T_12 V_480 ;
T_2 V_481 ;
V_2 = V_100 -> V_106 . V_150 ;
memset ( V_469 , 0 , sizeof( V_469 ) ) ;
V_480 = F_67 ( V_213 , sizeof( V_469 ) - 1 ) ;
if ( F_133 ( V_469 , V_477 , V_480 ) )
return - V_482 ;
if ( sscanf ( V_469 , L_124 , & V_481 ) == 1 )
V_100 -> V_106 . V_183 = V_481 ;
else
V_100 -> V_106 . V_183 = 0 ;
F_131 ( V_2 , V_100 ) ;
return V_213 ;
}
static T_10 F_134 ( struct V_476 * V_476 ,
char T_11 * V_477 , T_12 V_213 , T_13 * V_478 )
{
char * V_483 ;
int V_484 = 0 ;
int V_73 = 0 ;
T_10 V_82 ;
struct V_79 * V_100 = V_476 -> V_479 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = & ( V_100 -> V_205 [ V_100 -> V_206 ] ) ;
struct V_15 * V_7 = & V_6 -> V_7 ;
V_2 = V_100 -> V_106 . V_150 ;
V_483 = F_135 ( 2048 , V_485 ) ;
if ( ! V_483 )
return - V_486 ;
V_484 += sprintf ( V_483 + V_484 , L_125 , V_100 -> V_186 . V_414 ) ;
V_484 += sprintf ( V_483 + V_484 , L_126 ,
V_100 -> V_212 , V_100 -> V_211 ,
V_100 -> V_140 ) ;
V_484 += sprintf ( V_483 + V_484 , L_127 ,
V_100 -> V_106 . V_183 ) ;
V_484 += sprintf ( V_483 + V_484 , L_128 ,
( V_2 -> V_13 -> V_14 & V_42 ) ? L_129 : L_119 ,
( V_2 -> V_13 -> V_14 & V_43 ) ? L_130 : L_119 ,
( V_2 -> V_13 -> V_14 & V_45 ) ? L_131 : L_119 ) ;
V_484 += sprintf ( V_483 + V_484 , L_132 ,
( F_33 ( V_7 ) ) ? L_133 :
F_37 ( V_7 ) ? L_107 : L_108 ) ;
if ( ! F_33 ( V_7 ) ) {
V_484 += sprintf ( V_483 + V_484 , L_134 ,
( F_40 ( V_7 ) ) ? L_135 : L_136 ) ;
V_484 += sprintf ( V_483 + V_484 , L_134 ,
( F_8 ( V_7 ) ) ? L_137 :
( F_9 ( V_7 ) ) ? L_138 :
( F_10 ( V_7 ) ) ? L_112 : L_114 ) ;
V_484 += sprintf ( V_483 + V_484 , L_139 ,
( V_7 -> V_62 ) ? L_140 : L_141 ,
( V_7 -> V_63 ) ? L_142 : L_143 ,
( V_100 -> V_254 ) ? L_144 : L_119 ) ;
}
V_484 += sprintf ( V_483 + V_484 , L_145 ,
V_100 -> V_215 ) ;
V_484 += sprintf ( V_483 + V_484 ,
L_146 ,
V_100 -> V_186 . V_158 ,
V_100 -> V_186 . V_437 ,
V_100 -> V_186 . V_427 ,
V_100 -> V_186 . V_428 ) ;
V_484 += sprintf ( V_483 + V_484 ,
L_147 ,
F_104 ( V_100 -> V_186 . V_460 ) ,
V_100 -> V_186 . V_458 ,
V_100 -> V_186 . V_438 ) ;
V_484 += sprintf ( V_483 + V_484 , L_148 , V_100 -> V_186 . V_334 ) ;
V_484 += sprintf ( V_483 + V_484 ,
L_149 ,
V_100 -> V_186 . V_487 [ 0 ] ,
V_100 -> V_186 . V_487 [ 1 ] ,
V_100 -> V_186 . V_487 [ 2 ] ,
V_100 -> V_186 . V_487 [ 3 ] ) ;
for ( V_73 = 0 ; V_73 < V_446 ; V_73 ++ ) {
T_2 V_488 = F_62 ( V_100 -> V_186 . V_187 [ V_73 ] ) ;
V_484 += sprintf ( V_483 + V_484 , L_150 , V_73 , V_488 ) ;
V_484 += F_130 ( V_483 + V_484 , V_488 ) ;
}
V_82 = F_136 ( V_477 , V_213 , V_478 , V_483 , V_484 ) ;
F_137 ( V_483 ) ;
return V_82 ;
}
static T_10 F_138 ( struct V_476 * V_476 ,
char T_11 * V_477 , T_12 V_213 , T_13 * V_478 )
{
char * V_483 ;
int V_484 = 0 ;
int V_73 , V_271 ;
T_10 V_82 ;
struct V_5 * V_6 ;
struct V_15 * V_7 ;
struct V_79 * V_100 = V_476 -> V_479 ;
V_483 = F_135 ( 1024 , V_485 ) ;
if ( ! V_483 )
return - V_486 ;
for ( V_73 = 0 ; V_73 < V_415 ; V_73 ++ ) {
V_6 = & ( V_100 -> V_205 [ V_73 ] ) ;
V_7 = & V_6 -> V_7 ;
V_484 += sprintf ( V_483 + V_484 ,
L_151
L_152 ,
V_100 -> V_206 == V_73 ? L_153 : L_154 ,
V_7 -> type ,
V_7 -> V_62 ,
F_8 ( V_7 ) ? L_110 :
F_9 ( V_7 ) ? L_111 :
F_10 ( V_7 ) ? L_112 : L_155 ,
V_7 -> V_60 ) ;
for ( V_271 = 0 ; V_271 < V_74 ; V_271 ++ ) {
V_484 += sprintf ( V_483 + V_484 ,
L_156 ,
V_6 -> V_75 [ V_271 ] . V_71 ,
V_6 -> V_75 [ V_271 ] . V_68 ,
V_6 -> V_75 [ V_271 ] . V_69 ) ;
}
}
V_82 = F_136 ( V_477 , V_213 , V_478 , V_483 , V_484 ) ;
F_137 ( V_483 ) ;
return V_82 ;
}
static T_10 F_139 ( struct V_476 * V_476 ,
char T_11 * V_477 ,
T_12 V_213 , T_13 * V_478 )
{
static const char * const V_489 [] = {
[ V_372 ] = L_157 ,
[ V_373 ] = L_158 ,
[ V_490 ] = L_159 ,
[ V_491 ] = L_160 ,
[ V_492 ] = L_161 ,
[ V_493 ] = L_162 ,
[ V_494 ] = L_136 ,
[ V_495 ] = L_163 ,
} ;
static const char * const V_496 [] = {
[ V_497 ] = L_164 ,
[ V_498 ] = L_165 ,
[ V_499 ] = L_166 ,
[ V_500 ] = L_167 ,
[ V_501 ] = L_168 ,
[ V_29 ] = L_169 ,
[ V_502 ] = L_170 ,
[ V_503 ] = L_171 ,
[ V_504 ] = L_172 ,
[ V_505 ] = L_173 ,
[ V_506 ] = L_174 ,
[ V_315 ] = L_175 ,
[ V_316 ] = L_176 ,
[ V_317 ] = L_177 ,
[ V_152 ] = L_178 ,
} ;
char * V_483 , * V_507 , * V_508 ;
int V_509 , V_7 ;
T_10 V_82 ;
struct V_79 * V_100 = V_476 -> V_479 ;
struct V_510 * V_391 ;
static const T_12 V_511 = 1024 ;
V_483 = F_135 ( V_511 , V_485 ) ;
if ( ! V_483 )
return - V_486 ;
V_507 = V_483 ;
V_508 = V_507 + V_511 ;
V_507 += F_140 ( V_507 , V_508 - V_507 , L_179 ) ;
for ( V_7 = 0 ; V_7 < V_74 ; V_7 ++ )
V_507 += F_140 ( V_507 , V_508 - V_507 , L_180 , V_496 [ V_7 ] ) ;
V_507 += F_140 ( V_507 , V_508 - V_507 , L_181 ) ;
for ( V_509 = 0 ; V_509 < V_512 ; V_509 ++ ) {
V_507 += F_140 ( V_507 , V_508 - V_507 ,
L_180 , V_489 [ V_509 ] ) ;
for ( V_7 = 0 ; V_7 < V_74 ; V_7 ++ ) {
V_391 = & ( V_100 -> V_106 . V_107 [ V_509 ] [ V_7 ] ) ;
V_507 += F_140 ( V_507 , V_508 - V_507 ,
L_182 ,
V_391 -> V_109 ,
V_391 -> V_108 ) ;
}
V_507 += F_140 ( V_507 , V_508 - V_507 , L_181 ) ;
}
V_82 = F_136 ( V_477 , V_213 , V_478 , V_483 , V_507 - V_483 ) ;
F_137 ( V_483 ) ;
return V_82 ;
}
static T_10 F_141 ( struct V_476 * V_476 ,
const char T_11 * V_477 ,
T_12 V_213 , T_13 * V_478 )
{
struct V_79 * V_100 = V_476 -> V_479 ;
memset ( V_100 -> V_106 . V_107 , 0 , sizeof( V_100 -> V_106 . V_107 ) ) ;
return V_213 ;
}
static void F_142 ( void * V_2 , void * V_329 , struct V_466 * V_513 )
{
struct V_79 * V_100 = V_329 ;
F_143 ( L_183 , V_514 | V_515 , V_513 ,
V_100 , & V_516 ) ;
F_143 ( L_184 , V_514 , V_513 ,
V_100 , & V_517 ) ;
F_143 ( L_185 , V_514 | V_515 , V_513 ,
V_100 , & V_518 ) ;
F_144 ( L_186 , V_514 | V_515 , V_513 ,
& V_100 -> V_356 ) ;
F_144 ( L_187 , V_514 | V_515 , V_513 ,
& V_100 -> V_106 . V_335 ) ;
}
static void F_145 ( void * V_2 , void * V_329 )
{
}
static void F_146 ( void * V_217 ,
struct V_218 * V_219 ,
struct V_431 * V_432 ,
struct V_3 * V_4 , void * V_329 )
{
}
int F_147 ( void )
{
return F_148 ( & V_519 ) ;
}
void F_149 ( void )
{
F_150 ( & V_519 ) ;
}
int F_151 ( struct V_1 * V_2 , struct V_181 * V_182 ,
bool V_520 )
{
struct V_172 * V_186 = & V_182 -> V_100 . V_186 ;
F_152 ( & V_2 -> V_521 ) ;
if ( V_520 ) {
if ( V_182 -> V_522 == 0 )
V_186 -> V_158 |= V_465 ;
V_182 -> V_522 ++ ;
} else {
V_182 -> V_522 -- ;
if ( V_182 -> V_522 == 0 )
V_186 -> V_158 &= ~ V_465 ;
}
return F_65 ( V_2 , V_186 , false ) ;
}
