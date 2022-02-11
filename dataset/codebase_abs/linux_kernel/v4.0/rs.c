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
if ( ! V_4 -> V_10 . V_11 )
return false ;
if ( V_4 -> V_12 == V_13 )
return false ;
if ( F_4 ( F_5 ( V_2 ) ) < 2 )
return false ;
if ( ! F_6 ( V_2 , V_4 ) )
return false ;
return true ;
}
static bool F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
if ( ! V_4 -> V_10 . V_11 )
return false ;
return true ;
}
static bool F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_14 * V_15 = & V_6 -> V_15 ;
struct V_16 * V_10 = & V_4 -> V_10 ;
struct V_17 * V_18 = & V_4 -> V_18 ;
if ( F_9 ( V_15 ) && ( V_10 -> V_19 &
V_20 ) )
return true ;
if ( F_10 ( V_15 ) && ( V_10 -> V_19 &
V_21 ) )
return true ;
if ( F_11 ( V_15 ) && ( V_18 -> V_19 &
V_22 ) )
return true ;
return false ;
}
static inline T_1 F_12 ( T_2 V_23 )
{
return ( T_1 ) ( V_23 & V_24 ) ;
}
static int F_13 ( T_2 V_23 )
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
T_1 V_36 = F_12 ( V_23 ) ;
for ( V_25 = 0 ; V_25 < F_14 ( V_37 ) ; V_25 ++ )
if ( V_37 [ V_25 ] . V_38 == V_36 )
return V_25 ;
}
return V_39 ;
}
static const char * F_15 ( T_1 V_9 )
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
if ( V_9 > V_48 )
return L_9 ;
return V_40 [ V_9 ] ;
}
static const char * F_16 ( enum V_49 type )
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
static inline void F_17 ( struct V_1 * V_2 , const struct V_14 * V_15 ,
const char * V_59 )
{
F_18 ( V_2 ,
L_17 ,
V_59 , F_16 ( V_15 -> type ) ,
V_15 -> V_60 , F_15 ( V_15 -> V_9 ) ,
V_15 -> V_61 , V_15 -> V_62 , V_15 -> V_63 , V_15 -> V_64 ) ;
}
static void F_19 ( struct V_65 * V_66 )
{
V_66 -> V_67 = 0 ;
V_66 -> V_68 = 0 ;
V_66 -> V_69 = V_70 ;
V_66 -> V_71 = 0 ;
V_66 -> V_72 = V_70 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_73 ;
F_18 ( V_2 , L_18 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
F_19 ( & V_6 -> V_75 [ V_73 ] ) ;
for ( V_73 = 0 ; V_73 < F_14 ( V_6 -> V_76 ) ; V_73 ++ )
F_19 ( & V_6 -> V_76 [ V_73 ] ) ;
}
static inline T_1 F_21 ( T_1 V_77 , T_1 V_78 )
{
return ( V_78 & V_77 ) == V_78 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_79 * V_80 , T_1 V_81 ,
struct V_3 * V_4 )
{
int V_82 = - V_83 ;
F_23 ( V_2 , L_19 ,
V_4 -> V_84 , V_81 ) ;
V_82 = F_24 ( V_4 , V_81 , 5000 ) ;
if ( V_82 == - V_83 ) {
F_25 ( V_2 , L_20 ,
V_81 ) ;
F_26 ( V_4 , V_81 ) ;
}
return V_82 ;
}
static void F_27 ( struct V_1 * V_2 , T_1 V_81 ,
struct V_79 * V_80 ,
struct V_3 * V_4 )
{
if ( V_81 < V_85 )
F_22 ( V_2 , V_80 , V_81 , V_4 ) ;
else
F_25 ( V_2 , L_21 ,
V_81 , V_85 ) ;
}
static inline int F_28 ( T_2 V_23 )
{
return ! ! ( V_23 & V_86 ) +
! ! ( V_23 & V_87 ) +
! ! ( V_23 & V_88 ) ;
}
static T_3 F_29 ( struct V_5 * V_6 , int V_89 )
{
if ( V_6 -> V_90 )
return V_6 -> V_90 [ V_89 ] ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
int V_91 , int V_92 , int V_93 ,
struct V_65 * V_66 )
{
static const T_4 V_94 = ( ( ( T_4 ) 1 ) << ( V_95 - 1 ) ) ;
T_3 V_96 , V_97 ;
V_97 = F_29 ( V_6 , V_91 ) ;
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
static int F_31 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
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
V_82 = F_30 ( V_2 , V_6 , V_91 , V_92 , V_93 ,
V_66 ) ;
if ( V_82 )
return V_82 ;
if ( F_32 ( V_101 > V_110 ) )
return - V_102 ;
V_66 = & V_6 -> V_76 [ V_101 ] ;
return F_30 ( V_2 , V_6 , V_91 , V_92 , V_93 ,
V_66 ) ;
}
static T_2 F_33 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
T_2 V_111 = 0 ;
int V_60 = V_15 -> V_60 ;
V_111 |= ( ( V_15 -> V_9 << V_112 ) &
V_113 ) ;
if ( F_34 ( V_15 ) ) {
V_111 |= V_37 [ V_60 ] . V_38 ;
if ( V_60 >= V_114 && V_60 <= V_115 )
V_111 |= V_116 ;
return V_111 ;
}
if ( F_35 ( V_15 ) ) {
if ( V_60 < V_30 || V_60 > V_31 ) {
F_25 ( V_2 , L_22 , V_60 ) ;
V_60 = V_31 ;
}
V_111 |= V_26 ;
if ( F_36 ( V_15 ) )
V_111 |= V_37 [ V_60 ] . V_117 ;
else if ( F_37 ( V_15 ) )
V_111 |= V_37 [ V_60 ] . V_118 ;
else
F_32 ( 1 ) ;
} else if ( F_38 ( V_15 ) ) {
if ( V_60 < V_34 || V_60 > V_35 ) {
F_25 ( V_2 , L_23 , V_60 ) ;
V_60 = V_35 ;
}
V_111 |= V_32 ;
if ( F_39 ( V_15 ) )
V_111 |= V_37 [ V_60 ] . V_119 ;
else if ( F_40 ( V_15 ) )
V_111 |= V_37 [ V_60 ] . V_120 ;
else
F_32 ( 1 ) ;
} else {
F_25 ( V_2 , L_24 , V_15 -> type ) ;
}
if ( F_41 ( V_15 ) && V_15 -> V_64 ) {
V_111 |= V_121 ;
V_111 |= V_122 ;
}
V_111 |= V_15 -> V_61 ;
if ( V_15 -> V_62 )
V_111 |= V_123 ;
if ( V_15 -> V_63 )
V_111 |= V_124 ;
return V_111 ;
}
static int F_42 ( const T_2 V_111 ,
enum V_125 V_126 ,
struct V_14 * V_15 )
{
T_2 V_127 = V_111 & V_113 ;
T_1 F_4 = F_28 ( V_111 ) ;
T_1 V_128 ;
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_60 = F_13 ( V_111 ) ;
if ( V_15 -> V_60 == V_39 )
return - V_102 ;
V_15 -> V_9 = ( V_127 >> V_112 ) ;
if ( ! ( V_111 & V_26 ) &&
! ( V_111 & V_32 ) ) {
if ( F_4 == 1 ) {
if ( V_126 == V_129 )
V_15 -> type = V_52 ;
else
V_15 -> type = V_53 ;
}
return 0 ;
}
if ( V_111 & V_123 )
V_15 -> V_62 = true ;
if ( V_111 & V_124 )
V_15 -> V_63 = true ;
if ( V_111 & V_122 )
V_15 -> V_64 = true ;
V_15 -> V_61 = V_111 & V_130 ;
if ( V_111 & V_26 ) {
V_128 = ( ( V_111 & V_131 ) >>
V_132 ) + 1 ;
if ( V_128 == 1 ) {
V_15 -> type = V_54 ;
F_32 ( ! V_15 -> V_64 && F_4 != 1 ) ;
} else if ( V_128 == 2 ) {
V_15 -> type = V_55 ;
F_32 ( F_4 != 2 ) ;
} else {
F_32 ( 1 ) ;
}
} else if ( V_111 & V_32 ) {
V_128 = ( ( V_111 & V_133 ) >>
V_134 ) + 1 ;
if ( V_128 == 1 ) {
V_15 -> type = V_56 ;
F_32 ( ! V_15 -> V_64 && F_4 != 1 ) ;
} else if ( V_128 == 2 ) {
V_15 -> type = V_57 ;
F_32 ( F_4 != 2 ) ;
} else {
F_32 ( 1 ) ;
}
}
F_32 ( V_15 -> V_61 == V_135 ) ;
F_32 ( V_15 -> V_61 == V_136 &&
! F_38 ( V_15 ) ) ;
return 0 ;
}
static int F_43 ( T_2 V_137 , struct V_14 * V_15 )
{
T_1 V_138 ;
if ( ! V_15 -> V_9 || V_15 -> V_9 > V_48 )
return 0 ;
if ( ! F_21 ( V_137 , V_15 -> V_9 ) )
return 0 ;
V_138 = V_139 [ V_15 -> V_9 ] ;
while ( ( V_138 != V_15 -> V_9 ) &&
! F_21 ( V_137 , V_138 ) )
V_138 = V_139 [ V_138 ] ;
if ( V_138 == V_15 -> V_9 )
return 0 ;
V_15 -> V_9 = V_138 ;
return 1 ;
}
static T_5 F_44 ( struct V_79 * V_100 ,
struct V_14 * V_15 )
{
if ( F_34 ( V_15 ) )
return V_100 -> V_140 ;
else if ( F_41 ( V_15 ) )
return V_100 -> V_141 ;
else if ( F_45 ( V_15 ) )
return V_100 -> V_142 ;
F_32 ( 1 ) ;
return 0 ;
}
static T_5 F_46 ( struct V_1 * V_2 , T_1 V_60 , T_5 V_143 ,
int V_144 )
{
T_1 V_145 = V_39 ;
T_1 V_146 = V_39 ;
if ( F_47 ( V_144 ) || ! F_48 ( V_144 ) ) {
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
}
V_145 = V_60 ;
while ( V_145 != V_39 ) {
V_145 = V_37 [ V_145 ] . V_148 ;
if ( V_145 == V_39 )
break;
if ( V_143 & ( 1 << V_145 ) )
break;
}
return ( V_145 << 8 ) | V_146 ;
}
static inline bool F_49 ( struct V_79 * V_100 ,
struct V_14 * V_15 )
{
return F_50 ( V_15 -> V_60 ) & F_44 ( V_100 , V_15 ) ;
}
static bool F_51 ( struct V_79 * V_100 ,
struct V_14 * V_15 )
{
T_1 V_146 ;
T_5 V_149 ;
T_5 V_143 ;
struct V_1 * V_2 = V_100 -> V_106 . V_150 ;
V_143 = F_44 ( V_100 , V_15 ) ;
V_149 = F_46 ( V_2 , V_15 -> V_60 , V_143 ,
V_15 -> type ) ;
V_146 = V_149 & 0xff ;
if ( V_146 == V_39 )
return true ;
V_15 -> V_60 = V_146 ;
return false ;
}
static void F_52 ( struct V_79 * V_100 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = V_100 -> V_106 . V_150 ;
if ( F_34 ( V_15 ) ) {
return;
} else if ( F_41 ( V_15 ) ) {
if ( V_100 -> V_126 == V_129 )
V_15 -> type = V_52 ;
else
V_15 -> type = V_53 ;
V_15 -> V_61 = V_151 ;
F_32 ( V_15 -> V_60 < V_28 ||
V_15 -> V_60 > V_152 ) ;
V_15 -> V_60 = V_153 [ V_15 -> V_60 ] ;
V_15 -> V_63 = false ;
} else {
V_15 -> type = F_40 ( V_15 ) ?
V_56 : V_54 ;
}
if ( F_4 ( V_15 -> V_9 ) > 1 )
V_15 -> V_9 = F_53 ( F_5 ( V_2 ) ) ;
V_15 -> V_62 = false ;
if ( ! F_49 ( V_100 , V_15 ) )
F_51 ( V_100 , V_15 ) ;
}
static inline bool F_54 ( struct V_14 * V_154 ,
struct V_14 * V_155 )
{
bool V_156 ;
if ( V_154 -> V_64 )
V_156 = ( V_155 -> V_9 == V_42 || V_155 -> V_9 == V_43 ) ;
else
V_156 = ( V_154 -> V_9 == V_155 -> V_9 ) ;
return ( V_154 -> type == V_155 -> type ) && ( V_154 -> V_61 == V_155 -> V_61 ) && ( V_154 -> V_62 == V_155 -> V_62 )
&& V_156 ;
}
static T_2 F_55 ( enum V_157 V_158 )
{
if ( V_158 & V_159 )
return V_160 ;
else if ( V_158 & V_161 )
return V_136 ;
else if ( V_158 & V_162 )
return V_135 ;
return V_151 ;
}
static T_1 F_56 ( struct V_163 * V_164 )
{
T_1 V_81 = V_85 ;
if ( F_57 ( V_164 -> V_165 ) ) {
T_1 * V_166 = F_58 ( V_164 ) ;
V_81 = V_166 [ 0 ] & 0xf ;
}
if ( F_59 ( V_81 > V_85 ) )
V_81 = V_85 ;
return V_81 ;
}
void F_60 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_81 , struct V_167 * V_168 )
{
int V_169 ;
int V_170 ;
int V_171 , V_73 ;
struct V_172 * V_173 ;
enum V_157 V_174 ;
T_2 V_111 ;
struct V_14 V_15 ;
struct V_5 * V_175 , * V_176 , * V_177 ;
T_1 V_101 = ( V_178 ) V_168 -> V_179 . V_180 [ 0 ] ;
struct V_181 * V_182 = F_61 ( V_4 ) ;
struct V_79 * V_100 = & V_182 -> V_100 ;
if ( ! V_100 ) {
F_18 ( V_2 , L_25 ) ;
return;
} else if ( ! V_100 -> V_106 . V_150 ) {
F_18 ( V_2 , L_26 ) ;
return;
}
#ifdef F_62
if ( V_100 -> V_106 . V_183 ) {
F_18 ( V_2 , L_27 ) ;
return;
}
#endif
if ( ( V_168 -> V_158 & V_184 ) &&
! ( V_168 -> V_158 & V_185 ) )
return;
V_173 = & V_100 -> V_186 ;
V_111 = F_63 ( V_173 -> V_187 [ 0 ] ) ;
F_42 ( V_111 , V_168 -> V_126 , & V_15 ) ;
if ( V_168 -> V_126 == V_129 )
V_15 . V_60 -= V_188 ;
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
if ( F_64 ( V_193 ,
( unsigned long ) ( V_100 -> V_194 +
( V_195 * V_196 ) ) ) ) {
int V_197 ;
F_18 ( V_2 , L_28 ) ;
for ( V_197 = 0 ; V_197 < V_85 ; V_197 ++ )
F_26 ( V_4 , V_197 ) ;
F_65 ( V_2 , V_4 , V_168 -> V_126 , false ) ;
return;
}
V_100 -> V_194 = V_193 ;
if ( ( V_171 < 0 ) ||
( V_15 . V_62 != ! ! ( V_174 & V_198 ) ) ||
( V_15 . V_61 != F_55 ( V_174 ) ) ||
( V_15 . V_9 != V_168 -> V_179 . V_199 ) ||
( ! ! ( V_111 & V_26 ) !=
! ! ( V_174 & V_190 ) ) ||
( ! ! ( V_111 & V_32 ) !=
! ! ( V_174 & V_192 ) ) ||
( ! ! ( V_111 & V_200 ) !=
! ! ( V_174 & V_201 ) ) ||
( V_15 . V_60 != V_171 ) ) {
F_18 ( V_2 ,
L_29 ,
V_171 , V_15 . V_60 , V_111 ) ;
V_100 -> V_202 ++ ;
if ( V_100 -> V_202 > V_203 ) {
V_100 -> V_202 = 0 ;
F_18 ( V_2 ,
L_30 ,
V_100 -> V_204 ) ;
F_66 ( V_2 , & V_100 -> V_186 , false ) ;
}
return;
} else
V_100 -> V_202 = 0 ;
if ( ! V_100 -> V_205 ) {
V_175 = & ( V_100 -> V_206 [ V_100 -> V_207 ] ) ;
V_176 = & ( V_100 -> V_206 [ 1 - V_100 -> V_207 ] ) ;
} else {
V_175 = & ( V_100 -> V_206 [ 1 - V_100 -> V_207 ] ) ;
V_176 = & ( V_100 -> V_206 [ V_100 -> V_207 ] ) ;
}
if ( F_32 ( ! F_54 ( & V_15 , & V_175 -> V_15 ) ) ) {
F_18 ( V_2 ,
L_31 ) ;
V_177 = & ( V_100 -> V_206 [ V_100 -> V_207 ] ) ;
F_17 ( V_2 , & V_177 -> V_15 , L_32 ) ;
V_177 = & ( V_100 -> V_206 [ 1 - V_100 -> V_207 ] ) ;
F_17 ( V_2 , & V_177 -> V_15 , L_33 ) ;
F_17 ( V_2 , & V_15 , L_34 ) ;
F_67 ( V_100 , true ) ;
goto V_208;
}
if ( V_168 -> V_158 & V_185 ) {
if ( V_168 -> V_179 . V_209 == 0 )
V_168 -> V_179 . V_210 = 1 ;
V_111 = F_63 ( V_173 -> V_187 [ 0 ] ) ;
F_42 ( V_111 , V_168 -> V_126 , & V_15 ) ;
F_31 ( V_2 , V_100 , V_175 , V_15 . V_60 ,
V_168 -> V_179 . V_210 ,
V_168 -> V_179 . V_209 ,
V_101 ) ;
if ( V_100 -> V_204 == V_211 ) {
V_100 -> V_212 += V_168 -> V_179 . V_209 ;
V_100 -> V_213 += ( V_168 -> V_179 . V_210 -
V_168 -> V_179 . V_209 ) ;
}
} else {
V_170 = V_168 -> V_179 . V_189 [ 0 ] . V_214 - 1 ;
V_170 = F_68 ( V_170 , 15 ) ;
V_169 = ! ! ( V_168 -> V_158 & V_215 ) ;
for ( V_73 = 0 ; V_73 <= V_170 ; ++ V_73 ) {
V_111 = F_63 ( V_173 -> V_187 [ V_73 ] ) ;
F_42 ( V_111 , V_168 -> V_126 , & V_15 ) ;
if ( F_54 ( & V_15 , & V_175 -> V_15 ) )
V_177 = V_175 ;
else if ( F_54 ( & V_15 , & V_176 -> V_15 ) )
V_177 = V_176 ;
else
continue;
F_31 ( V_2 , V_100 , V_177 , V_15 . V_60 , 1 ,
V_73 < V_170 ? 0 : V_169 ,
V_101 ) ;
}
if ( V_100 -> V_204 == V_211 ) {
V_100 -> V_212 += V_169 ;
V_100 -> V_213 += V_170 + ( 1 - V_169 ) ;
}
}
V_100 -> V_216 = V_111 ;
F_18 ( V_2 , L_35 , V_101 ) ;
V_208:
if ( V_4 -> V_217 [ V_168 -> V_126 ] )
F_69 ( V_2 , V_4 , V_100 , V_81 ) ;
}
static void F_70 ( void * V_218 ,
struct V_219 * V_220 ,
struct V_3 * V_4 , void * V_221 ,
struct V_222 * V_223 )
{
struct V_163 * V_164 = (struct V_163 * ) V_223 -> V_67 ;
struct V_224 * V_225 = (struct V_224 * ) V_218 ;
struct V_1 * V_2 = F_71 ( V_225 ) ;
struct V_167 * V_168 = F_72 ( V_223 ) ;
if ( ! F_61 ( V_4 ) -> V_226 )
return;
if ( ! F_73 ( V_164 -> V_165 ) ||
V_168 -> V_158 & V_227 )
return;
F_60 ( V_2 , V_4 , F_56 ( V_164 ) , V_168 ) ;
}
static void F_74 ( struct V_1 * V_2 , T_1 F_34 ,
struct V_79 * V_100 )
{
F_18 ( V_2 , L_36 ) ;
V_100 -> V_204 = V_211 ;
if ( F_34 ) {
V_100 -> V_228 = V_229 ;
V_100 -> V_230 = V_231 ;
V_100 -> V_232 = V_233 ;
} else {
V_100 -> V_228 = V_234 ;
V_100 -> V_230 = V_235 ;
V_100 -> V_232 = V_236 ;
}
V_100 -> V_237 = 0 ;
V_100 -> V_213 = 0 ;
V_100 -> V_212 = 0 ;
V_100 -> V_238 = V_193 ;
V_100 -> V_239 = 0 ;
}
static inline int F_75 ( unsigned long V_143 )
{
if ( V_143 )
return F_76 ( & V_143 , V_240 ) ;
return V_39 ;
}
static int F_77 ( struct V_79 * V_100 ,
const struct V_7 * V_103 )
{
switch ( V_103 -> V_241 ) {
case V_242 :
return V_100 -> V_243 ;
case V_244 :
return V_100 -> V_245 ;
case V_246 :
return V_100 -> V_247 ;
default:
F_32 ( 1 ) ;
}
return V_100 -> V_243 ;
}
static const T_5 * F_78 ( struct V_79 * V_100 ,
const struct V_7 * V_103 ,
T_2 V_61 )
{
const T_5 ( * V_248 ) [ V_74 ] ;
if ( F_32 ( V_103 -> V_241 != V_242 &&
V_103 -> V_241 != V_244 &&
V_103 -> V_241 != V_246 ) )
return V_249 ;
if ( V_103 -> V_241 == V_242 )
return V_249 ;
V_248 = V_250 ;
if ( V_103 -> V_241 == V_244 ) {
switch ( V_61 ) {
case V_151 :
V_248 = V_251 ;
break;
case V_160 :
V_248 = V_252 ;
break;
case V_136 :
V_248 = V_253 ;
break;
default:
F_32 ( 1 ) ;
}
} else if ( V_103 -> V_241 == V_246 ) {
switch ( V_61 ) {
case V_151 :
V_248 = V_250 ;
break;
case V_160 :
V_248 = V_254 ;
break;
case V_136 :
V_248 = V_255 ;
break;
default:
F_32 ( 1 ) ;
}
} else {
F_32 ( 1 ) ;
}
if ( ! V_103 -> V_62 && ! V_100 -> V_256 )
return V_248 [ 0 ] ;
else if ( V_103 -> V_62 && ! V_100 -> V_256 )
return V_248 [ 1 ] ;
else if ( ! V_103 -> V_62 && V_100 -> V_256 )
return V_248 [ 2 ] ;
else
return V_248 [ 3 ] ;
}
static void F_79 ( struct V_79 * V_100 ,
struct V_5 * V_6 )
{
struct V_14 * V_15 = & V_6 -> V_15 ;
const struct V_7 * V_103 = & V_257 [ V_6 -> V_103 ] ;
V_6 -> V_90 = F_78 ( V_100 , V_103 , V_15 -> V_61 ) ;
}
static T_3 F_80 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_5 * V_6 ,
unsigned long V_143 , T_6 V_60 )
{
struct V_5 * V_207 =
& ( V_100 -> V_206 [ V_100 -> V_207 ] ) ;
T_3 V_69 = V_207 -> V_75 [ V_60 ] . V_69 ;
T_5 V_258 = V_207 -> V_90 [ V_60 ] ;
const T_5 * V_259 = V_6 -> V_90 ;
T_5 V_149 ;
T_2 V_260 ;
int V_261 ;
if ( V_69 > V_262 ) {
V_260 = 100 * V_258 ;
F_18 ( V_2 ,
L_37 ,
V_69 , V_260 ) ;
} else {
V_260 = V_100 -> V_263 ;
F_18 ( V_2 ,
L_38 ,
V_69 , V_260 ) ;
}
V_261 = F_81 ( & V_143 , V_240 ) ;
while ( V_261 != V_39 ) {
if ( V_260 < ( 100 * V_259 [ V_261 ] ) )
break;
V_149 = F_46 ( V_2 , V_261 , V_143 ,
V_6 -> V_15 . type ) ;
V_261 = ( V_149 >> 8 ) & 0xff ;
}
F_18 ( V_2 , L_39 ,
V_261 , V_260 ,
V_261 != V_39 ?
100 * V_259 [ V_261 ] : V_70 ) ;
return V_261 ;
}
static T_2 F_82 ( struct V_3 * V_4 )
{
if ( V_4 -> V_264 >= V_265 )
return V_136 ;
else if ( V_4 -> V_264 >= V_266 )
return V_160 ;
return V_151 ;
}
static void F_67 ( struct V_79 * V_100 , bool V_267 )
{
struct V_5 * V_6 ;
int V_207 ;
int V_268 = 0 ;
struct V_1 * V_2 ;
V_2 = V_100 -> V_106 . V_150 ;
V_207 = V_100 -> V_207 ;
V_6 = & ( V_100 -> V_206 [ V_207 ] ) ;
if ( V_100 -> V_204 == V_211 ) {
if ( V_100 -> V_238 )
V_268 =
F_64 ( V_193 ,
( unsigned long ) ( V_100 -> V_238 +
( V_269 * V_196 ) ) ) ;
if ( V_267 ||
( V_100 -> V_213 > V_100 -> V_230 ) ||
( V_100 -> V_212 > V_100 -> V_232 ) ||
( ( ! V_100 -> V_205 ) &&
( V_100 -> V_238 ) && ( V_268 ) ) ) {
F_18 ( V_2 ,
L_40 ,
V_100 -> V_213 ,
V_100 -> V_212 ,
V_268 ) ;
V_100 -> V_204 = V_270 ;
F_18 ( V_2 ,
L_41 ) ;
V_100 -> V_213 = 0 ;
V_100 -> V_212 = 0 ;
V_100 -> V_238 = 0 ;
V_100 -> V_239 = F_50 ( V_6 -> V_103 ) ;
} else {
V_100 -> V_237 ++ ;
if ( V_100 -> V_237 >=
V_100 -> V_228 ) {
V_100 -> V_237 = 0 ;
F_18 ( V_2 ,
L_42 ) ;
F_20 ( V_2 , V_6 ) ;
}
}
if ( V_100 -> V_204 == V_270 ) {
F_20 ( V_2 , V_6 ) ;
}
}
}
static void F_83 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
struct V_14 * V_15 )
{
F_84 ( V_2 , V_4 , V_100 , V_15 ) ;
F_66 ( V_2 , & V_100 -> V_186 , false ) ;
}
static enum V_271 F_85 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_73 , V_272 , V_273 ;
enum V_271 V_274 ;
const struct V_7 * V_275 = & V_257 [ V_6 -> V_103 ] ;
const struct V_7 * V_8 ;
T_7 V_276 ;
T_1 V_277 = F_5 ( V_2 ) ;
const T_5 * V_278 ;
T_5 V_97 , V_279 ;
for ( V_73 = 0 ; V_73 < V_280 ; V_73 ++ ) {
V_274 = V_275 -> V_281 [ V_73 ] ;
if ( V_274 == V_104 )
continue;
if ( V_100 -> V_239 & F_50 ( V_274 ) ) {
F_18 ( V_2 , L_43 ,
V_274 ) ;
continue;
}
V_8 = & V_257 [ V_274 ] ;
if ( ! F_21 ( V_277 , V_8 -> V_9 ) ) {
F_18 ( V_2 ,
L_44 ,
V_274 , V_277 , V_8 -> V_9 ) ;
continue;
}
for ( V_272 = 0 ; V_272 < V_282 ; V_272 ++ ) {
V_276 = V_8 -> V_283 [ V_272 ] ;
if ( V_276 && ! V_276 ( V_2 , V_4 , V_6 , V_8 ) )
break;
}
if ( V_272 != V_282 ) {
F_18 ( V_2 ,
L_45 ,
V_274 , V_272 ) ;
continue;
}
V_97 = V_100 -> V_263 / 100 ;
V_278 = F_78 ( V_100 , V_8 ,
F_82 ( V_4 ) ) ;
if ( F_32 ( ! V_278 ) )
continue;
V_273 = F_77 ( V_100 , V_8 ) ;
if ( V_273 == V_39 ) {
F_18 ( V_2 ,
L_46 ,
V_274 ) ;
continue;
}
V_279 = V_278 [ V_273 ] ;
if ( V_97 >= V_279 ) {
F_18 ( V_2 ,
L_47 ,
V_274 , V_279 , V_97 ) ;
continue;
}
F_18 ( V_2 ,
L_48 ,
V_274 , V_279 , V_97 ) ;
break;
}
if ( V_73 == V_280 )
return V_104 ;
return V_274 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_3 * V_4 ,
enum V_271 V_284 )
{
struct V_5 * V_6 = & ( V_100 -> V_206 [ V_100 -> V_207 ] ) ;
struct V_5 * V_285 =
& ( V_100 -> V_206 [ ( 1 - V_100 -> V_207 ) ] ) ;
struct V_14 * V_15 = & V_285 -> V_15 ;
const struct V_7 * V_103 = & V_257 [ V_284 ] ;
const struct V_7 * V_286 = & V_257 [ V_6 -> V_103 ] ;
T_2 V_287 = ( sizeof( struct V_5 ) -
( sizeof( struct V_65 ) * V_74 ) ) ;
unsigned long V_143 = 0 ;
T_2 V_261 = 0 ;
memcpy ( V_285 , V_6 , V_287 ) ;
V_15 -> V_62 = V_103 -> V_62 ;
V_15 -> V_9 = V_103 -> V_9 ;
if ( V_103 -> V_241 == V_242 ) {
if ( V_100 -> V_126 == V_129 )
V_15 -> type = V_52 ;
else
V_15 -> type = V_53 ;
V_15 -> V_61 = V_151 ;
V_15 -> V_63 = false ;
V_143 = V_100 -> V_140 ;
} else if ( V_103 -> V_241 == V_244 ) {
V_15 -> type = V_100 -> F_38 ? V_56 : V_54 ;
V_143 = V_100 -> V_141 ;
} else if ( V_103 -> V_241 == V_246 ) {
V_15 -> type = V_100 -> F_38 ? V_57 : V_55 ;
V_143 = V_100 -> V_142 ;
} else {
F_32 ( L_49 ) ;
}
if ( V_103 -> V_241 != V_242 ) {
V_15 -> V_61 = F_82 ( V_4 ) ;
V_15 -> V_63 = V_100 -> V_63 ;
}
V_285 -> V_103 = V_284 ;
F_79 ( V_100 , V_285 ) ;
V_100 -> V_239 |= F_50 ( V_284 ) ;
if ( V_286 -> V_241 != V_103 -> V_241 ) {
V_261 = F_80 ( V_2 , V_100 , V_285 ,
V_143 , V_15 -> V_60 ) ;
if ( ( V_261 == V_39 ) ||
! ( F_50 ( V_261 ) & V_143 ) ) {
F_18 ( V_2 ,
L_50
L_51 ,
V_261 , V_143 ) ;
goto V_288;
}
V_15 -> V_60 = V_261 ;
}
F_18 ( V_2 , L_52 ,
V_284 , V_15 -> V_60 ) ;
return 0 ;
V_288:
V_15 -> type = V_51 ;
return - 1 ;
}
static enum V_289 F_87 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_3 V_290 , int V_146 , int V_145 ,
int V_291 ,
int V_292 , int V_293 )
{
enum V_289 V_294 = V_295 ;
if ( ( V_290 <= F_88 ( V_296 ) ) ||
( V_291 == 0 ) ) {
F_18 ( V_2 ,
L_53 ) ;
return V_297 ;
}
if ( ( V_292 == V_70 ) &&
( V_293 == V_70 ) &&
( V_145 != V_39 ) ) {
F_18 ( V_2 ,
L_54 ) ;
return V_298 ;
}
if ( ( V_293 == V_70 ) &&
( V_145 != V_39 ) &&
( V_292 != V_70 ) &&
( V_292 < V_291 ) ) {
F_18 ( V_2 ,
L_55 ) ;
return V_298 ;
}
if ( ( V_293 != V_70 ) &&
( V_293 > V_291 ) ) {
F_18 ( V_2 ,
L_56 ) ;
return V_298 ;
}
if ( ( V_292 != V_70 ) &&
( V_293 != V_70 ) &&
( V_292 < V_291 ) &&
( V_293 < V_291 ) ) {
F_18 ( V_2 ,
L_57 ) ;
return V_295 ;
}
if ( ( V_292 != V_70 ) &&
( V_292 > V_291 ) ) {
F_18 ( V_2 ,
L_58 ) ;
V_294 = V_297 ;
goto V_299;
}
if ( ( V_292 == V_70 ) &&
( V_146 != V_39 ) ) {
F_18 ( V_2 ,
L_59 ) ;
V_294 = V_297 ;
goto V_299;
}
F_18 ( V_2 , L_60 ) ;
V_299:
if ( ( V_294 == V_297 ) && ( V_146 != V_39 ) ) {
if ( V_290 >= F_88 ( V_262 ) ) {
F_18 ( V_2 ,
L_61 ) ;
V_294 = V_295 ;
} else if ( V_291 > ( 100 * V_6 -> V_90 [ V_146 ] ) ) {
F_18 ( V_2 ,
L_62 ) ;
V_294 = V_295 ;
} else {
F_18 ( V_2 , L_63 ) ;
}
}
return V_294 ;
}
static bool F_89 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_79 * V_100 )
{
if ( ! V_100 -> V_300 )
return false ;
if ( ! F_6 ( V_2 , V_4 ) )
return false ;
return true ;
}
static void F_90 ( struct V_1 * V_2 , int V_60 ,
int * V_301 , int * V_302 )
{
* V_301 = V_60 + V_303 ;
if ( * V_301 > V_110 )
* V_301 = V_304 ;
* V_302 = V_60 - V_303 ;
if ( * V_302 < 0 )
* V_302 = V_304 ;
}
static bool F_91 ( struct V_1 * V_2 , struct V_305 * V_226 ,
struct V_14 * V_15 , enum V_125 V_126 )
{
int V_60 = V_15 -> V_60 ;
bool V_306 = ( V_307 . V_308 == V_309 ) ;
bool V_310 = ( V_226 -> type == V_311 &&
! V_226 -> V_312 . V_313 ) ;
F_18 ( V_2 , L_64 ,
V_306 , V_310 ) ;
if ( ( V_306 || V_310 ) &&
! F_92 ( V_2 , V_126 ) )
return false ;
F_18 ( V_2 , L_65 , V_15 -> type ) ;
if ( F_34 ( V_15 ) )
return V_60 == V_314 ;
if ( F_35 ( V_15 ) )
return V_60 == V_315 ;
if ( F_38 ( V_15 ) )
return V_60 == V_315 ||
V_60 == V_316 ||
V_60 == V_152 ;
F_32 ( 1 ) ;
return false ;
}
static enum V_317 F_93 ( struct V_1 * V_2 ,
T_3 V_290 , int V_318 , int V_319 ,
int V_291 ,
int V_320 , int V_321 )
{
if ( V_291 == V_70 ) {
F_18 ( V_2 , L_66 ) ;
return V_322 ;
}
if ( V_290 <= F_88 ( V_323 ) ||
V_291 == 0 ) {
F_18 ( V_2 , L_67 ) ;
return V_324 ;
}
if ( V_318 != V_304 ) {
if ( V_320 == V_70 &&
( V_321 == V_70 ||
V_291 >= V_321 ) ) {
F_18 ( V_2 ,
L_68 ) ;
return V_325 ;
}
if ( V_320 > V_291 ) {
F_18 ( V_2 ,
L_69 ) ;
return V_325 ;
}
}
if ( V_290 < F_88 ( V_326 ) &&
V_319 != V_304 ) {
if ( V_320 == V_70 &&
V_321 != V_70 &&
V_291 < V_321 ) {
F_18 ( V_2 ,
L_70 ) ;
return V_327 ;
}
if ( V_320 < V_291 &&
( V_321 == V_70 ||
V_321 > V_291 ) ) {
F_18 ( V_2 ,
L_71 ) ;
return V_327 ;
}
}
F_18 ( V_2 , L_72 ) ;
return V_322 ;
}
static bool F_94 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
struct V_5 * V_6 )
{
struct V_181 * V_328 = F_61 ( V_4 ) ;
struct V_305 * V_226 = V_328 -> V_226 ;
struct V_329 * V_330 ;
enum V_125 V_126 ;
struct V_65 * V_66 ;
struct V_14 * V_15 = & V_6 -> V_15 ;
enum V_317 V_294 ;
T_3 V_290 ;
T_1 V_331 = V_100 -> V_186 . V_332 ;
int V_291 ;
int V_318 , V_319 ;
int V_320 = V_70 , V_321 = V_70 ;
#ifdef F_62
if ( V_100 -> V_106 . V_333 <= V_110 ) {
F_18 ( V_2 , L_73 ,
V_100 -> V_106 . V_333 ) ;
V_100 -> V_186 . V_332 = V_100 -> V_106 . V_333 ;
return V_331 != V_100 -> V_106 . V_333 ;
}
#endif
F_95 () ;
V_330 = F_96 ( V_226 -> V_330 ) ;
if ( F_97 ( ! V_330 ) )
V_126 = V_334 ;
else
V_126 = V_330 -> V_335 . V_336 -> V_126 ;
F_98 () ;
if ( ! F_91 ( V_2 , V_226 , V_15 , V_126 ) ) {
F_18 ( V_2 ,
L_74 ) ;
V_100 -> V_186 . V_332 = V_337 ;
return V_331 != V_337 ;
}
F_90 ( V_2 , V_331 , & V_318 , & V_319 ) ;
V_66 = V_6 -> V_76 ;
V_290 = V_66 [ V_331 ] . V_69 ;
V_291 = V_66 [ V_331 ] . V_72 ;
if ( V_318 != V_304 )
V_320 = V_66 [ V_318 ] . V_72 ;
if ( V_319 != V_304 )
V_321 = V_66 [ V_319 ] . V_72 ;
F_18 ( V_2 ,
L_75 ,
V_331 , V_291 , V_290 , V_318 , V_319 ,
V_320 , V_321 ) ;
V_294 = F_93 ( V_2 , V_290 , V_318 , V_319 ,
V_291 , V_320 , V_321 ) ;
if ( V_318 == V_304 && V_294 == V_325 ) {
F_18 ( V_2 , L_76 ) ;
V_294 = V_322 ;
} else if ( V_319 == V_304 &&
( V_294 == V_327 ||
V_294 == V_324 ) ) {
F_18 ( V_2 , L_77 ) ;
V_294 = V_322 ;
}
switch ( V_294 ) {
case V_325 :
V_100 -> V_186 . V_332 = V_318 ;
return true ;
case V_327 :
V_100 -> V_186 . V_332 = V_319 ;
return true ;
case V_324 :
V_100 -> V_186 . V_332 = V_337 ;
return true ;
case V_322 :
break;
}
return false ;
}
static void F_69 ( struct V_1 * V_2 ,
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
enum V_289 V_338 = V_295 ;
T_5 V_143 ;
T_1 V_339 = 0 ;
struct V_5 * V_6 , * V_340 ;
T_1 V_207 = 0 ;
T_1 V_341 = 0 ;
T_5 V_149 ;
T_3 V_290 ;
T_1 V_342 = V_100 -> V_256 ;
struct V_181 * V_343 = F_61 ( V_4 ) ;
struct V_344 * V_345 ;
struct V_14 * V_15 ;
V_100 -> V_256 = ! ! V_343 -> V_346 ;
if ( ! V_100 -> V_205 )
V_207 = V_100 -> V_207 ;
else
V_207 = 1 - V_100 -> V_207 ;
V_6 = & ( V_100 -> V_206 [ V_207 ] ) ;
V_15 = & V_6 -> V_15 ;
if ( V_342 != V_100 -> V_256 ) {
F_18 ( V_2 ,
L_78 ,
V_342 , V_100 -> V_256 ) ;
F_79 ( V_100 , V_6 ) ;
F_20 ( V_2 , V_6 ) ;
}
V_60 = V_100 -> V_347 ;
V_143 = F_44 ( V_100 , V_15 ) ;
if ( ! ( F_50 ( V_60 ) & V_143 ) ) {
F_25 ( V_2 , L_79 ) ;
if ( V_100 -> V_205 ) {
V_15 -> type = V_51 ;
V_100 -> V_205 = 0 ;
V_6 = & ( V_100 -> V_206 [ V_100 -> V_207 ] ) ;
F_83 ( V_2 , V_4 , V_100 , & V_6 -> V_15 ) ;
}
return;
}
if ( ! V_6 -> V_90 ) {
F_25 ( V_2 , L_80 ) ;
return;
}
V_66 = & ( V_6 -> V_75 [ V_60 ] ) ;
V_96 = V_66 -> V_71 - V_66 -> V_68 ;
if ( ( V_96 < V_98 ) &&
( V_66 -> V_68 < V_99 ) ) {
F_18 ( V_2 ,
L_81 ,
F_16 ( V_15 -> type ) ,
V_60 , V_66 -> V_68 , V_66 -> V_71 ) ;
V_66 -> V_72 = V_70 ;
F_67 ( V_100 , false ) ;
goto V_299;
}
if ( V_66 -> V_72 != ( ( V_66 -> V_69 *
V_6 -> V_90 [ V_60 ] + 64 ) / 128 ) ) {
V_66 -> V_72 = ( ( V_66 -> V_69 *
V_6 -> V_90 [ V_60 ] + 64 ) / 128 ) ;
}
if ( V_100 -> V_205 ) {
if ( V_66 -> V_72 > V_100 -> V_263 ) {
F_18 ( V_2 ,
L_82
L_83 ,
V_66 -> V_69 ,
V_66 -> V_72 ,
V_100 -> V_263 ) ;
V_100 -> V_207 = V_207 ;
V_291 = V_66 -> V_72 ;
} else {
F_18 ( V_2 ,
L_84
L_83 ,
V_66 -> V_69 ,
V_66 -> V_72 ,
V_100 -> V_263 ) ;
V_15 -> type = V_51 ;
V_207 = V_100 -> V_207 ;
V_6 = & ( V_100 -> V_206 [ V_207 ] ) ;
V_60 = V_6 -> V_15 . V_60 ;
V_291 = V_100 -> V_263 ;
V_339 = 1 ;
}
V_100 -> V_205 = 0 ;
V_341 = 1 ;
goto V_348;
}
V_149 = F_46 ( V_2 , V_60 , V_143 , V_15 -> type ) ;
V_146 = V_149 & 0xff ;
V_145 = ( V_149 >> 8 ) & 0xff ;
V_290 = V_66 -> V_69 ;
V_291 = V_66 -> V_72 ;
if ( V_146 != V_39 )
V_292 = V_6 -> V_75 [ V_146 ] . V_72 ;
if ( V_145 != V_39 )
V_293 = V_6 -> V_75 [ V_145 ] . V_72 ;
F_18 ( V_2 ,
L_85 ,
F_16 ( V_15 -> type ) , V_60 , V_291 , V_290 ,
V_146 , V_145 , V_292 , V_293 ) ;
V_338 = F_87 ( V_2 , V_6 , V_290 , V_146 , V_145 ,
V_291 , V_292 , V_293 ) ;
if ( F_99 ( V_15 ) &&
! F_6 ( V_2 , V_4 ) ) {
F_18 ( V_2 ,
L_86 ) ;
F_67 ( V_100 , true ) ;
goto V_348;
}
switch ( V_338 ) {
case V_297 :
if ( V_146 != V_39 ) {
V_339 = 1 ;
V_60 = V_146 ;
} else {
F_18 ( V_2 ,
L_87 ) ;
}
break;
case V_298 :
if ( V_145 != V_39 ) {
V_339 = 1 ;
V_60 = V_145 ;
} else {
F_18 ( V_2 ,
L_88 ) ;
}
break;
case V_295 :
if ( V_100 -> V_204 == V_211 )
V_339 = F_94 ( V_2 , V_4 , V_100 , V_6 ) ;
break;
default:
break;
}
V_348:
if ( V_339 ) {
V_6 -> V_15 . V_60 = V_60 ;
F_83 ( V_2 , V_4 , V_100 , & V_6 -> V_15 ) ;
}
F_67 ( V_100 , false ) ;
if ( ! V_339 && ! V_341 &&
V_100 -> V_204 == V_270
&& V_66 -> V_71 ) {
enum V_271 V_349 ;
V_100 -> V_263 = V_291 ;
F_18 ( V_2 ,
L_89 ,
V_339 , V_341 , V_100 -> V_204 ,
V_66 -> V_71 ) ;
V_349 = F_85 ( V_2 , V_100 , V_4 , V_6 ) ;
if ( V_349 != V_104 ) {
int V_82 = F_86 ( V_2 , V_100 , V_4 ,
V_349 ) ;
if ( ! V_82 )
V_100 -> V_205 = 1 ;
} else {
F_18 ( V_2 ,
L_90 ) ;
V_100 -> V_204 = V_350 ;
}
if ( V_100 -> V_205 ) {
V_6 = & ( V_100 -> V_206 [ ( 1 - V_100 -> V_207 ) ] ) ;
F_20 ( V_2 , V_6 ) ;
V_60 = V_6 -> V_15 . V_60 ;
F_17 ( V_2 , & V_6 -> V_15 ,
L_91 ) ;
F_84 ( V_2 , V_4 , V_100 , & V_6 -> V_15 ) ;
F_66 ( V_2 , & V_100 -> V_186 , false ) ;
} else {
V_341 = 1 ;
}
}
if ( V_341 && V_100 -> V_204 == V_350 ) {
V_340 = & ( V_100 -> V_206 [ V_100 -> V_207 ] ) ;
if ( F_34 ( & V_340 -> V_15 ) ) {
F_18 ( V_2 , L_92 ) ;
if ( V_81 != V_85 ) {
V_345 = & V_343 -> V_345 [ V_81 ] ;
if ( V_345 -> V_351 != V_352 ) {
F_18 ( V_2 ,
L_93 ,
V_81 ) ;
F_26 ( V_4 , V_81 ) ;
}
}
F_74 ( V_2 , 1 , V_100 ) ;
} else {
if ( ( V_100 -> V_263 > V_353 ) &&
( V_100 -> V_354 & ( 1 << V_81 ) ) &&
( V_81 != V_85 ) ) {
V_345 = & V_343 -> V_345 [ V_81 ] ;
if ( V_345 -> V_351 == V_352 ) {
F_18 ( V_2 ,
L_94 ,
V_81 ) ;
F_27 ( V_2 , V_81 ,
V_100 , V_4 ) ;
}
}
F_74 ( V_2 , 0 , V_100 ) ;
}
}
V_299:
V_100 -> V_347 = V_60 ;
}
static void F_100 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
enum V_125 V_126 ,
struct V_14 * V_15 )
{
int V_73 , V_355 ;
T_6 V_356 = V_357 ;
T_1 V_358 = V_41 ;
T_1 V_359 = F_5 ( V_2 ) ;
const struct V_360 * V_361 ;
for ( V_73 = 0 ; V_73 < F_14 ( V_100 -> V_106 . V_362 ) ; V_73 ++ ) {
if ( ! ( V_100 -> V_106 . V_363 & F_50 ( V_73 ) ) )
continue;
if ( V_100 -> V_106 . V_362 [ V_73 ] > V_356 ) {
V_356 = V_100 -> V_106 . V_362 [ V_73 ] ;
V_358 = F_50 ( V_73 ) ;
}
}
F_18 ( V_2 , L_95 ,
F_15 ( V_358 ) , V_356 ) ;
if ( V_358 != V_42 && V_358 != V_43 )
V_15 -> V_9 = F_53 ( V_359 ) ;
else
V_15 -> V_9 = V_358 ;
V_15 -> V_62 = false ;
V_15 -> V_63 = false ;
V_15 -> V_61 = V_151 ;
V_15 -> V_60 = F_81 ( & V_100 -> V_140 ,
V_240 ) ;
if ( V_126 == V_129 ) {
V_15 -> type = V_52 ;
V_361 = V_364 ;
V_355 = F_14 ( V_364 ) ;
} else {
V_15 -> type = V_53 ;
V_361 = V_365 ;
V_355 = F_14 ( V_365 ) ;
}
if ( V_366 ) {
for ( V_73 = 0 ; V_73 < V_355 ; V_73 ++ ) {
int V_261 = V_361 [ V_73 ] . V_261 ;
if ( ( V_356 >= V_361 [ V_73 ] . V_367 ) &&
( F_50 ( V_261 ) & V_100 -> V_140 ) ) {
V_15 -> V_60 = V_261 ;
break;
}
}
}
F_18 ( V_2 , L_96 , V_15 -> V_60 ,
F_15 ( V_15 -> V_9 ) ) ;
}
void F_101 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_368 * V_369 )
{
V_100 -> V_106 . V_363 = V_369 -> V_363 ;
V_100 -> V_106 . V_362 [ 0 ] = V_369 -> V_362 [ 0 ] ;
V_100 -> V_106 . V_362 [ 1 ] = V_369 -> V_362 [ 1 ] ;
V_100 -> V_106 . V_362 [ 2 ] = V_369 -> V_362 [ 2 ] ;
}
static void F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
enum V_125 V_126 ,
bool V_370 )
{
struct V_5 * V_6 ;
struct V_14 * V_15 ;
T_1 V_207 = 0 ;
if ( ! V_4 || ! V_100 )
return;
if ( ! V_100 -> V_205 )
V_207 = V_100 -> V_207 ;
else
V_207 = 1 - V_100 -> V_207 ;
V_6 = & ( V_100 -> V_206 [ V_207 ] ) ;
V_15 = & V_6 -> V_15 ;
F_100 ( V_2 , V_100 , V_126 , V_15 ) ;
V_100 -> V_347 = V_15 -> V_60 ;
F_32 ( V_15 -> V_9 != V_42 && V_15 -> V_9 != V_43 ) ;
if ( V_15 -> V_9 == V_42 )
V_6 -> V_103 = V_371 ;
else
V_6 -> V_103 = V_372 ;
F_79 ( V_100 , V_6 ) ;
F_84 ( V_2 , V_4 , V_100 , V_15 ) ;
F_66 ( V_2 , & V_100 -> V_186 , V_370 ) ;
}
static void F_103 ( void * V_218 , struct V_3 * V_4 , void * V_328 ,
struct V_373 * V_374 )
{
struct V_222 * V_223 = V_374 -> V_223 ;
struct V_224 * V_225 V_375 =
(struct V_224 * ) V_218 ;
struct V_1 * V_2 V_375 = F_71 ( V_225 ) ;
struct V_167 * V_168 = F_72 ( V_223 ) ;
struct V_79 * V_100 = V_328 ;
if ( V_4 && ! F_61 ( V_4 ) -> V_226 ) {
V_4 = NULL ;
V_328 = NULL ;
}
if ( V_100 && ! V_100 -> V_106 . V_150 ) {
F_18 ( V_2 , L_26 ) ;
V_328 = NULL ;
}
if ( F_104 ( V_4 , V_328 , V_374 ) )
return;
F_105 ( V_100 -> V_216 ,
V_168 -> V_126 , & V_168 -> V_376 . V_189 [ 0 ] ) ;
V_168 -> V_376 . V_189 [ 0 ] . V_214 = 1 ;
}
static void * F_106 ( void * V_377 , struct V_3 * V_4 ,
T_8 V_378 )
{
struct V_181 * V_343 = F_61 ( V_4 ) ;
struct V_224 * V_225 = (struct V_224 * ) V_377 ;
struct V_1 * V_2 = F_71 ( V_225 ) ;
struct V_79 * V_100 = & V_343 -> V_100 ;
F_18 ( V_2 , L_97 ) ;
V_100 -> V_106 . V_150 = V_2 ;
#ifdef F_62
V_100 -> V_106 . V_183 = 0 ;
V_100 -> V_106 . V_333 = V_304 ;
#endif
V_100 -> V_106 . V_363 = 0 ;
memset ( V_100 -> V_106 . V_362 , 0 , sizeof( V_100 -> V_106 . V_362 ) ) ;
return & V_343 -> V_100 ;
}
static int F_107 ( struct V_17 * V_18 ,
int V_128 )
{
T_5 V_379 = F_108 ( V_18 -> V_380 . V_381 ) &
( 0x3 << ( 2 * ( V_128 - 1 ) ) ) ;
V_379 >>= ( 2 * ( V_128 - 1 ) ) ;
if ( V_379 == V_382 )
return V_315 ;
else if ( V_379 == V_383 )
return V_316 ;
else if ( V_379 == V_384 )
return V_152 ;
F_32 ( V_379 != V_385 ) ;
return - 1 ;
}
static void F_109 ( struct V_3 * V_4 ,
struct V_17 * V_18 ,
struct V_79 * V_100 )
{
int V_73 ;
int V_386 = F_107 ( V_18 , 1 ) ;
if ( V_386 >= V_28 ) {
for ( V_73 = V_28 ; V_73 <= V_386 ; V_73 ++ ) {
if ( V_73 == V_29 )
continue;
if ( V_73 == V_152 &&
V_4 -> V_264 == V_387 )
continue;
V_100 -> V_141 |= F_50 ( V_73 ) ;
}
}
if ( V_4 -> V_388 < 2 )
return;
V_386 = F_107 ( V_18 , 2 ) ;
if ( V_386 >= V_28 ) {
for ( V_73 = V_28 ; V_73 <= V_386 ; V_73 ++ ) {
if ( V_73 == V_29 )
continue;
if ( V_73 == V_152 &&
V_4 -> V_264 == V_387 )
continue;
V_100 -> V_142 |= F_50 ( V_73 ) ;
}
}
}
static void F_110 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
struct V_16 * V_10 )
{
V_100 -> V_141 = V_10 -> V_389 . V_390 [ 0 ] << 1 ;
V_100 -> V_141 |= V_10 -> V_389 . V_390 [ 0 ] & 0x1 ;
V_100 -> V_141 &= ~ ( ( T_5 ) 0x2 ) ;
V_100 -> V_141 <<= V_188 ;
V_100 -> V_142 = V_10 -> V_389 . V_390 [ 1 ] << 1 ;
V_100 -> V_142 |= V_10 -> V_389 . V_390 [ 1 ] & 0x1 ;
V_100 -> V_142 &= ~ ( ( T_5 ) 0x2 ) ;
V_100 -> V_142 <<= V_188 ;
if ( V_2 -> V_391 -> V_392 -> V_63 &&
( V_10 -> V_19 & V_393 ) )
V_100 -> V_63 = true ;
if ( V_2 -> V_391 -> V_392 -> V_64 &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_10 -> V_19 & V_394 ) )
V_100 -> V_300 = true ;
V_100 -> F_38 = false ;
}
static void F_111 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
struct V_17 * V_18 )
{
F_109 ( V_4 , V_18 , V_100 ) ;
if ( V_2 -> V_391 -> V_392 -> V_63 &&
( V_18 -> V_19 & V_395 ) )
V_100 -> V_63 = true ;
if ( V_2 -> V_391 -> V_392 -> V_64 &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_18 -> V_19 & V_396 ) )
V_100 -> V_300 = true ;
if ( ( V_2 -> V_397 -> V_398 . V_399 [ 0 ] & V_400 ) &&
( F_4 ( F_5 ( V_2 ) ) > 1 ) &&
( V_18 -> V_19 & V_401 ) )
V_100 -> V_402 = true ;
V_100 -> F_38 = true ;
}
static void F_112 ( struct V_1 * V_2 )
{
F_113 ( & V_2 -> V_403 ) ;
memset ( & V_2 -> V_404 , 0 , sizeof( V_2 -> V_404 ) ) ;
F_114 ( & V_2 -> V_403 ) ;
}
void F_115 ( struct V_1 * V_2 , T_2 V_15 , bool V_405 )
{
T_1 V_128 = 0 , V_389 = 0 ;
F_116 ( & V_2 -> V_403 ) ;
if ( V_405 )
V_2 -> V_404 . V_406 ++ ;
V_2 -> V_404 . V_407 ++ ;
switch ( V_15 & V_130 ) {
case V_151 :
V_2 -> V_404 . V_408 ++ ;
break;
case V_160 :
V_2 -> V_404 . V_409 ++ ;
break;
case V_136 :
V_2 -> V_404 . V_410 ++ ;
break;
default:
F_117 ( 1 , L_98 , V_15 ) ;
}
if ( V_15 & V_26 ) {
V_2 -> V_404 . V_411 ++ ;
V_389 = V_15 & V_27 ;
V_128 = ( ( V_15 & V_131 ) >> V_132 ) + 1 ;
} else if ( V_15 & V_32 ) {
V_2 -> V_404 . V_412 ++ ;
V_389 = V_15 & V_33 ;
V_128 = ( ( V_15 & V_133 ) >>
V_134 ) + 1 ;
} else {
V_2 -> V_404 . V_413 ++ ;
}
if ( V_128 == 1 )
V_2 -> V_404 . V_414 ++ ;
else if ( V_128 == 2 )
V_2 -> V_404 . V_415 ++ ;
if ( V_15 & V_123 )
V_2 -> V_404 . V_416 ++ ;
else
V_2 -> V_404 . V_417 ++ ;
V_2 -> V_404 . V_418 [ V_2 -> V_404 . V_419 ] = V_15 ;
V_2 -> V_404 . V_419 =
( V_2 -> V_404 . V_419 + 1 ) %
F_14 ( V_2 -> V_404 . V_418 ) ;
F_118 ( & V_2 -> V_403 ) ;
}
void F_65 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_125 V_126 , bool V_370 )
{
int V_73 , V_272 ;
struct V_420 * V_421 = V_2 -> V_421 ;
struct V_16 * V_10 = & V_4 -> V_10 ;
struct V_17 * V_18 = & V_4 -> V_18 ;
struct V_181 * V_343 = F_61 ( V_4 ) ;
struct V_79 * V_100 = & V_343 -> V_100 ;
struct V_219 * V_220 ;
unsigned long V_422 ;
memset ( V_100 , 0 , F_119 ( F_120 ( * V_100 ) , V_106 ) ) ;
V_220 = V_421 -> V_423 -> V_424 [ V_126 ] ;
V_100 -> V_186 . V_425 = V_343 -> V_425 ;
for ( V_272 = 0 ; V_272 < V_426 ; V_272 ++ )
F_20 ( V_2 , & V_100 -> V_206 [ V_272 ] ) ;
V_100 -> V_238 = 0 ;
V_100 -> V_194 = V_193 ;
F_18 ( V_2 ,
L_99 ,
V_343 -> V_425 ) ;
V_100 -> V_202 = V_203 ;
V_100 -> V_126 = V_220 -> V_126 ;
V_422 = V_4 -> V_217 [ V_220 -> V_126 ] ;
V_100 -> V_140 = 0 ;
F_121 (i, &supp, BITS_PER_LONG)
V_100 -> V_140 |= F_50 ( V_220 -> V_427 [ V_73 ] . V_428 ) ;
if ( ! V_18 || ! V_18 -> V_429 )
F_110 ( V_2 , V_4 , V_100 , V_10 ) ;
else
F_111 ( V_2 , V_4 , V_100 , V_18 ) ;
if ( V_430 && V_343 -> V_226 -> V_431 )
V_100 -> V_142 = 0 ;
V_100 -> V_243 =
F_75 ( V_100 -> V_140 ) ;
V_100 -> V_245 =
F_75 ( V_100 -> V_141 ) ;
V_100 -> V_247 =
F_75 ( V_100 -> V_142 ) ;
F_18 ( V_2 ,
L_100 ,
V_100 -> V_140 ,
V_100 -> V_141 ,
V_100 -> V_142 ,
V_100 -> F_38 , V_100 -> V_63 , V_100 -> V_300 ,
V_100 -> V_402 ) ;
F_18 ( V_2 , L_101 ,
V_100 -> V_243 ,
V_100 -> V_245 ,
V_100 -> V_247 ) ;
V_100 -> V_186 . V_432 =
F_53 ( F_5 ( V_2 ) ) ;
V_100 -> V_186 . V_433 = V_44 ;
V_100 -> V_354 = V_434 ;
V_100 -> V_256 = 0 ;
#ifdef F_122
F_112 ( V_2 ) ;
#endif
F_102 ( V_2 , V_4 , V_100 , V_126 , V_370 ) ;
}
static void F_123 ( void * V_218 ,
struct V_219 * V_220 ,
struct V_435 * V_436 ,
struct V_3 * V_4 , void * V_221 ,
T_2 V_437 )
{
T_1 V_81 ;
struct V_224 * V_225 =
(struct V_224 * ) V_218 ;
struct V_1 * V_2 = F_71 ( V_225 ) ;
if ( ! F_61 ( V_4 ) -> V_226 )
return;
for ( V_81 = 0 ; V_81 < V_85 ; V_81 ++ )
F_26 ( V_4 , V_81 ) ;
F_65 ( V_2 , V_4 , V_220 -> V_126 , false ) ;
}
static void F_124 ( struct V_1 * V_2 ,
struct V_172 * V_438 ,
enum V_125 V_126 ,
T_2 V_111 )
{
struct V_14 V_15 ;
int V_73 ;
int V_439 = F_14 ( V_438 -> V_187 ) ;
T_9 V_440 = F_125 ( V_111 ) ;
T_1 V_9 = ( V_111 & V_113 ) >> V_112 ;
for ( V_73 = 0 ; V_73 < V_439 ; V_73 ++ )
V_438 -> V_187 [ V_73 ] = V_440 ;
F_42 ( V_111 , V_126 , & V_15 ) ;
if ( F_99 ( & V_15 ) )
V_438 -> V_441 = V_439 - 1 ;
else
V_438 -> V_441 = 0 ;
V_438 -> V_332 = 0 ;
if ( F_4 ( V_9 ) == 1 )
V_438 -> V_432 = V_9 ;
V_438 -> V_442 = V_443 ;
}
static void F_126 ( struct V_1 * V_2 ,
struct V_79 * V_100 ,
struct V_14 * V_15 ,
T_9 * V_187 , int * V_444 ,
int V_439 , int V_445 ,
T_1 V_359 , bool V_446 )
{
int V_73 , V_272 ;
T_9 V_111 ;
bool V_447 = false ;
int V_448 = V_15 -> V_60 ;
int V_449 = V_450 ;
int V_60 = * V_444 ;
for ( V_73 = 0 ; V_73 < V_439 && V_60 < V_449 ; V_73 ++ ) {
for ( V_272 = 0 ; V_272 < V_445 && V_60 < V_449 ; V_272 ++ , V_60 ++ ) {
V_111 = F_125 ( F_33 ( V_2 ,
V_15 ) ) ;
V_187 [ V_60 ] = V_111 ;
if ( V_446 )
F_43 ( V_359 , V_15 ) ;
}
V_448 = V_15 -> V_60 ;
V_447 = F_51 ( V_100 , V_15 ) ;
if ( V_447 && ! F_34 ( V_15 ) )
break;
}
if ( ! V_447 && ! F_34 ( V_15 ) )
V_15 -> V_60 = V_448 ;
* V_444 = V_60 ;
}
static void F_127 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
const struct V_14 * V_451 )
{
struct V_14 V_15 ;
int V_439 , V_445 , V_60 = 0 ;
T_1 V_359 = 0 ;
struct V_172 * V_438 = & V_100 -> V_186 ;
bool V_446 = false ;
memcpy ( & V_15 , V_451 , sizeof( V_15 ) ) ;
V_359 = F_5 ( V_2 ) ;
if ( ! ( V_2 -> V_397 -> V_398 . V_452 [ 0 ] & V_453 ) &&
F_89 ( V_2 , V_4 , V_100 ) )
V_15 . V_64 = true ;
if ( F_41 ( & V_15 ) ) {
V_439 = V_454 ;
V_445 = V_455 ;
} else if ( F_99 ( & V_15 ) ) {
V_439 = V_456 ;
V_445 = V_455 ;
} else {
V_439 = V_457 ;
V_445 = V_458 ;
V_446 = true ;
}
F_126 ( V_2 , V_100 , & V_15 , V_438 -> V_187 , & V_60 ,
V_439 , V_445 , V_359 ,
V_446 ) ;
F_52 ( V_100 , & V_15 ) ;
if ( F_41 ( & V_15 ) ) {
V_439 = V_459 ;
V_445 = V_460 ;
V_438 -> V_441 = V_60 ;
} else if ( F_34 ( & V_15 ) ) {
V_439 = V_461 ;
V_445 = V_462 ;
} else {
F_32 ( 1 ) ;
}
V_446 = true ;
F_126 ( V_2 , V_100 , & V_15 , V_438 -> V_187 , & V_60 ,
V_439 , V_445 , V_359 ,
V_446 ) ;
F_52 ( V_100 , & V_15 ) ;
V_439 = V_461 ;
V_445 = V_462 ;
F_126 ( V_2 , V_100 , & V_15 , V_438 -> V_187 , & V_60 ,
V_439 , V_445 , V_359 ,
V_446 ) ;
}
static void F_128 ( void * V_463 ,
struct V_3 * V_4 )
{
struct V_464 * V_67 = V_463 ;
struct V_181 * V_182 = F_61 ( V_4 ) ;
struct V_172 * V_438 = & V_182 -> V_100 . V_186 ;
T_2 V_465 = F_63 ( V_438 -> V_465 ) ;
if ( V_4 == V_67 -> V_466 )
return;
if ( V_465 & V_467 ) {
F_32 ( V_67 -> V_468 != NULL ) ;
V_67 -> V_468 = V_182 ;
}
}
static int F_129 ( struct V_181 * V_4 )
{
int V_469 = - 1 ;
enum V_470 V_471 = F_130 ( V_4 -> V_226 ) ;
switch ( V_471 ) {
case V_472 :
case V_473 :
V_469 = 3 ;
break;
case V_474 :
V_469 = 2 ;
break;
case V_311 :
V_469 = 1 ;
break;
default:
F_117 ( true , L_102 , V_471 , V_4 -> V_425 ) ;
V_469 = - 1 ;
}
return V_469 ;
}
static int F_131 ( struct V_181 * V_475 ,
struct V_181 * V_476 )
{
int V_477 = F_129 ( V_475 ) ;
int V_478 = F_129 ( V_476 ) ;
if ( V_477 > V_478 )
return 1 ;
if ( V_477 < V_478 )
return - 1 ;
return 0 ;
}
static void F_132 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
const struct V_14 * V_451 )
{
struct V_172 * V_438 = & V_100 -> V_186 ;
struct V_181 * V_182 = F_61 ( V_4 ) ;
struct V_464 V_67 = {
. V_466 = V_4 ,
. V_468 = NULL ,
} ;
struct V_181 * V_468 = NULL ;
T_2 V_465 = V_479 ;
if ( ! F_6 ( V_2 , V_4 ) )
goto V_299;
if ( V_100 -> V_480 == V_481 )
V_465 |= ( V_482 | V_483 ) ;
else if ( V_100 -> V_480 == V_484 )
V_465 |= ( V_467 | V_483 ) ;
if ( V_100 -> V_480 != V_485 ) {
F_18 ( V_2 , L_103 ,
V_100 -> V_480 ) ;
goto V_299;
}
if ( V_100 -> V_300 )
V_465 |= V_482 ;
if ( ! V_100 -> V_402 )
goto V_299;
F_133 ( V_2 -> V_421 ,
F_128 ,
& V_67 ) ;
V_468 = V_67 . V_468 ;
if ( ! V_468 ) {
F_18 ( V_2 , L_104 ) ;
V_465 |= V_467 ;
goto V_299;
}
F_18 ( V_2 , L_105 ,
V_468 -> V_425 ) ;
if ( F_131 ( V_182 , V_468 ) > 0 ) {
struct V_172 * V_486 = & V_468 -> V_100 . V_186 ;
T_2 V_487 = F_63 ( V_486 -> V_465 ) ;
V_487 &= ~ V_467 ;
V_486 -> V_465 = F_125 ( V_487 ) ;
F_66 ( V_2 , V_486 , false ) ;
V_465 |= V_467 ;
F_18 ( V_2 ,
L_106 ,
V_468 -> V_425 ) ;
}
V_299:
V_438 -> V_465 = F_125 ( V_465 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_79 * V_100 ,
const struct V_14 * V_451 )
{
struct V_172 * V_438 = & V_100 -> V_186 ;
struct V_181 * V_182 ;
struct V_488 * V_489 ;
V_438 -> V_490 = V_491 ;
V_438 -> V_492 =
F_134 ( V_493 ) ;
#ifdef F_62
if ( V_100 -> V_106 . V_183 ) {
F_124 ( V_2 , V_438 ,
V_100 -> V_126 ,
V_100 -> V_106 . V_183 ) ;
return;
}
#endif
if ( F_32 ( ! V_4 || ! V_451 ) )
return;
F_127 ( V_2 , V_4 , V_100 , V_451 ) ;
if ( V_2 -> V_397 -> V_398 . V_452 [ 0 ] & V_453 )
F_132 ( V_2 , V_4 , V_100 , V_451 ) ;
if ( F_4 ( V_451 -> V_9 ) == 1 )
V_438 -> V_432 = V_451 -> V_9 ;
V_182 = F_61 ( V_4 ) ;
V_489 = F_135 ( V_182 -> V_226 ) ;
if ( F_4 ( V_451 -> V_9 ) == 1 )
V_438 -> V_432 = V_451 -> V_9 ;
V_438 -> V_442 = V_182 -> V_494 ;
if ( F_136 ( V_489 ) ) {
V_438 -> V_442 -- ;
if ( V_2 -> V_495 )
V_438 -> V_442 =
F_68 ( V_438 -> V_442 ,
V_2 -> V_495 ) ;
}
if ( V_182 -> V_226 -> V_431 )
V_438 -> V_158 |= V_496 ;
V_438 -> V_492 =
F_134 ( F_137 ( V_2 , V_4 ) ) ;
}
static void * F_138 ( struct V_420 * V_421 , struct V_497 * V_498 )
{
return V_421 -> V_499 ;
}
static void F_139 ( void * V_377 )
{
return;
}
static void F_140 ( void * V_218 , struct V_3 * V_4 ,
void * V_328 )
{
struct V_224 * V_225 V_375 = V_218 ;
struct V_1 * V_2 V_375 = F_71 ( V_225 ) ;
F_18 ( V_2 , L_107 ) ;
F_18 ( V_2 , L_108 ) ;
}
int F_141 ( char * V_500 , const T_2 V_15 )
{
char * type , * V_61 ;
T_1 V_389 = 0 , V_128 = 0 ;
T_1 V_9 = ( V_15 & V_113 ) >> V_112 ;
if ( ! ( V_15 & V_26 ) &&
! ( V_15 & V_32 ) ) {
int V_60 = F_13 ( V_15 ) ;
return sprintf ( V_500 , L_109 ,
F_15 ( V_9 ) ,
V_60 == V_39 ? L_110 :
V_501 [ V_60 ] . V_502 ) ;
}
if ( V_15 & V_32 ) {
type = L_111 ;
V_389 = V_15 & V_33 ;
V_128 = ( ( V_15 & V_133 )
>> V_134 ) + 1 ;
} else if ( V_15 & V_26 ) {
type = L_112 ;
V_389 = V_15 & V_503 ;
} else {
type = L_113 ;
}
switch ( V_15 & V_130 ) {
case V_151 :
V_61 = L_114 ;
break;
case V_160 :
V_61 = L_115 ;
break;
case V_136 :
V_61 = L_116 ;
break;
case V_135 :
V_61 = L_117 ;
break;
default:
V_61 = L_118 ;
}
return sprintf ( V_500 , L_119 ,
type , F_15 ( V_9 ) , V_61 , V_389 , V_128 ,
( V_15 & V_123 ) ? L_120 : L_121 ,
( V_15 & V_504 ) ? L_122 : L_123 ,
( V_15 & V_124 ) ? L_124 : L_123 ,
( V_15 & V_505 ) ? L_125 : L_123 ,
( V_15 & V_506 ) ? L_126 : L_123 ) ;
}
static void F_142 ( struct V_1 * V_2 ,
struct V_79 * V_100 )
{
V_100 -> V_140 = 0x0FFF ;
V_100 -> V_141 = 0x1FD0 ;
V_100 -> V_142 = 0x1FD0 ;
F_18 ( V_2 , L_127 ,
V_100 -> V_186 . V_425 , V_100 -> V_106 . V_183 ) ;
if ( V_100 -> V_106 . V_183 ) {
F_84 ( V_2 , NULL , V_100 , NULL ) ;
F_66 ( V_100 -> V_106 . V_150 , & V_100 -> V_186 , false ) ;
}
}
static T_10 F_143 ( struct V_507 * V_507 ,
const char T_11 * V_508 , T_12 V_214 , T_13 * V_509 )
{
struct V_79 * V_100 = V_507 -> V_510 ;
struct V_1 * V_2 ;
char V_500 [ 64 ] ;
T_12 V_511 ;
T_2 V_512 ;
V_2 = V_100 -> V_106 . V_150 ;
memset ( V_500 , 0 , sizeof( V_500 ) ) ;
V_511 = F_68 ( V_214 , sizeof( V_500 ) - 1 ) ;
if ( F_144 ( V_500 , V_508 , V_511 ) )
return - V_513 ;
if ( sscanf ( V_500 , L_128 , & V_512 ) == 1 )
V_100 -> V_106 . V_183 = V_512 ;
else
V_100 -> V_106 . V_183 = 0 ;
F_142 ( V_2 , V_100 ) ;
return V_214 ;
}
static T_10 F_145 ( struct V_507 * V_507 ,
char T_11 * V_508 , T_12 V_214 , T_13 * V_509 )
{
char * V_514 ;
int V_515 = 0 ;
int V_73 = 0 ;
T_10 V_82 ;
struct V_79 * V_100 = V_507 -> V_510 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = & ( V_100 -> V_206 [ V_100 -> V_207 ] ) ;
struct V_14 * V_15 = & V_6 -> V_15 ;
V_2 = V_100 -> V_106 . V_150 ;
V_514 = F_146 ( 2048 , V_516 ) ;
if ( ! V_514 )
return - V_517 ;
V_515 += sprintf ( V_514 + V_515 , L_129 , V_100 -> V_186 . V_425 ) ;
V_515 += sprintf ( V_514 + V_515 , L_130 ,
V_100 -> V_213 , V_100 -> V_212 ,
V_100 -> V_140 ) ;
V_515 += sprintf ( V_514 + V_515 , L_131 ,
V_100 -> V_106 . V_183 ) ;
V_515 += sprintf ( V_514 + V_515 , L_132 ,
( F_5 ( V_2 ) & V_42 ) ? L_133 : L_123 ,
( F_5 ( V_2 ) & V_43 ) ? L_134 : L_123 ,
( F_5 ( V_2 ) & V_45 ) ? L_135 : L_123 ) ;
V_515 += sprintf ( V_514 + V_515 , L_136 ,
( F_34 ( V_15 ) ) ? L_137 :
F_38 ( V_15 ) ? L_111 : L_112 ) ;
if ( ! F_34 ( V_15 ) ) {
V_515 += sprintf ( V_514 + V_515 , L_138 ,
( F_41 ( V_15 ) ) ? L_139 : L_140 ) ;
V_515 += sprintf ( V_514 + V_515 , L_138 ,
( F_9 ( V_15 ) ) ? L_141 :
( F_10 ( V_15 ) ) ? L_142 :
( F_11 ( V_15 ) ) ? L_116 : L_118 ) ;
V_515 += sprintf ( V_514 + V_515 , L_143 ,
( V_15 -> V_62 ) ? L_144 : L_145 ,
( V_15 -> V_63 ) ? L_146 : L_147 ,
( V_100 -> V_256 ) ? L_148 : L_123 ) ;
}
V_515 += sprintf ( V_514 + V_515 , L_149 ,
V_100 -> V_216 ) ;
V_515 += sprintf ( V_514 + V_515 ,
L_150 ,
V_100 -> V_186 . V_158 ,
V_100 -> V_186 . V_441 ,
V_100 -> V_186 . V_432 ,
V_100 -> V_186 . V_433 ) ;
V_515 += sprintf ( V_514 + V_515 ,
L_151 ,
F_108 ( V_100 -> V_186 . V_492 ) ,
V_100 -> V_186 . V_490 ,
V_100 -> V_186 . V_442 ) ;
V_515 += sprintf ( V_514 + V_515 , L_152 , V_100 -> V_186 . V_332 ) ;
V_515 += sprintf ( V_514 + V_515 ,
L_153 ,
V_100 -> V_186 . V_518 [ 0 ] ,
V_100 -> V_186 . V_518 [ 1 ] ,
V_100 -> V_186 . V_518 [ 2 ] ,
V_100 -> V_186 . V_518 [ 3 ] ) ;
for ( V_73 = 0 ; V_73 < V_450 ; V_73 ++ ) {
T_2 V_519 = F_63 ( V_100 -> V_186 . V_187 [ V_73 ] ) ;
V_515 += sprintf ( V_514 + V_515 , L_154 , V_73 , V_519 ) ;
V_515 += F_141 ( V_514 + V_515 , V_519 ) ;
}
V_82 = F_147 ( V_508 , V_214 , V_509 , V_514 , V_515 ) ;
F_148 ( V_514 ) ;
return V_82 ;
}
static T_10 F_149 ( struct V_507 * V_507 ,
char T_11 * V_508 , T_12 V_214 , T_13 * V_509 )
{
char * V_514 ;
int V_515 = 0 ;
int V_73 , V_272 ;
T_10 V_82 ;
struct V_5 * V_6 ;
struct V_14 * V_15 ;
struct V_79 * V_100 = V_507 -> V_510 ;
V_514 = F_146 ( 1024 , V_516 ) ;
if ( ! V_514 )
return - V_517 ;
for ( V_73 = 0 ; V_73 < V_426 ; V_73 ++ ) {
V_6 = & ( V_100 -> V_206 [ V_73 ] ) ;
V_15 = & V_6 -> V_15 ;
V_515 += sprintf ( V_514 + V_515 ,
L_155
L_156 ,
V_100 -> V_207 == V_73 ? L_157 : L_158 ,
V_15 -> type ,
V_15 -> V_62 ,
F_9 ( V_15 ) ? L_114 :
F_10 ( V_15 ) ? L_115 :
F_11 ( V_15 ) ? L_116 : L_159 ,
V_15 -> V_60 ) ;
for ( V_272 = 0 ; V_272 < V_74 ; V_272 ++ ) {
V_515 += sprintf ( V_514 + V_515 ,
L_160 ,
V_6 -> V_75 [ V_272 ] . V_71 ,
V_6 -> V_75 [ V_272 ] . V_68 ,
V_6 -> V_75 [ V_272 ] . V_69 ) ;
}
}
V_82 = F_147 ( V_508 , V_214 , V_509 , V_514 , V_515 ) ;
F_148 ( V_514 ) ;
return V_82 ;
}
static T_10 F_150 ( struct V_507 * V_507 ,
char T_11 * V_508 ,
T_12 V_214 , T_13 * V_509 )
{
static const char * const V_520 [] = {
[ V_371 ] = L_161 ,
[ V_372 ] = L_162 ,
[ V_521 ] = L_163 ,
[ V_522 ] = L_164 ,
[ V_523 ] = L_165 ,
[ V_524 ] = L_166 ,
[ V_525 ] = L_140 ,
[ V_526 ] = L_167 ,
} ;
static const char * const V_527 [] = {
[ V_528 ] = L_168 ,
[ V_529 ] = L_169 ,
[ V_530 ] = L_170 ,
[ V_531 ] = L_171 ,
[ V_532 ] = L_172 ,
[ V_29 ] = L_173 ,
[ V_533 ] = L_174 ,
[ V_534 ] = L_175 ,
[ V_535 ] = L_176 ,
[ V_536 ] = L_177 ,
[ V_537 ] = L_178 ,
[ V_314 ] = L_179 ,
[ V_315 ] = L_180 ,
[ V_316 ] = L_181 ,
[ V_152 ] = L_182 ,
} ;
char * V_514 , * V_538 , * V_539 ;
int V_540 , V_15 ;
T_10 V_82 ;
struct V_79 * V_100 = V_507 -> V_510 ;
struct V_541 * V_542 ;
static const T_12 V_543 = 1024 ;
V_514 = F_146 ( V_543 , V_516 ) ;
if ( ! V_514 )
return - V_517 ;
V_538 = V_514 ;
V_539 = V_538 + V_543 ;
V_538 += F_151 ( V_538 , V_539 - V_538 , L_183 ) ;
for ( V_15 = 0 ; V_15 < V_74 ; V_15 ++ )
V_538 += F_151 ( V_538 , V_539 - V_538 , L_184 , V_527 [ V_15 ] ) ;
V_538 += F_151 ( V_538 , V_539 - V_538 , L_185 ) ;
for ( V_540 = 0 ; V_540 < V_544 ; V_540 ++ ) {
V_538 += F_151 ( V_538 , V_539 - V_538 ,
L_184 , V_520 [ V_540 ] ) ;
for ( V_15 = 0 ; V_15 < V_74 ; V_15 ++ ) {
V_542 = & ( V_100 -> V_106 . V_107 [ V_540 ] [ V_15 ] ) ;
V_538 += F_151 ( V_538 , V_539 - V_538 ,
L_186 ,
V_542 -> V_109 ,
V_542 -> V_108 ) ;
}
V_538 += F_151 ( V_538 , V_539 - V_538 , L_185 ) ;
}
V_82 = F_147 ( V_508 , V_214 , V_509 , V_514 , V_538 - V_514 ) ;
F_148 ( V_514 ) ;
return V_82 ;
}
static T_10 F_152 ( struct V_507 * V_507 ,
const char T_11 * V_508 ,
T_12 V_214 , T_13 * V_509 )
{
struct V_79 * V_100 = V_507 -> V_510 ;
memset ( V_100 -> V_106 . V_107 , 0 , sizeof( V_100 -> V_106 . V_107 ) ) ;
return V_214 ;
}
static T_10 F_153 ( struct V_507 * V_507 ,
char T_11 * V_508 ,
T_12 V_214 , T_13 * V_509 )
{
struct V_79 * V_100 = V_507 -> V_510 ;
char V_500 [ 12 ] ;
int V_543 = sizeof( V_500 ) ;
int V_538 = 0 ;
static const char * const V_545 [] = {
[ V_485 ] = L_187 ,
[ V_481 ] = L_188 ,
[ V_484 ] = L_189 ,
[ V_546 ] = L_190 ,
} ;
V_538 += F_151 ( V_500 + V_538 , V_543 - V_538 , L_191 ,
V_545 [ V_100 -> V_480 ] ) ;
return F_147 ( V_508 , V_214 , V_509 , V_500 , V_538 ) ;
}
static T_10 F_154 ( struct V_79 * V_100 , char * V_500 ,
T_12 V_214 , T_13 * V_509 )
{
struct V_1 * V_2 = V_100 -> V_106 . V_150 ;
int V_82 = 0 ;
if ( ! strncmp ( L_187 , V_500 , 4 ) ) {
V_100 -> V_480 = V_485 ;
} else if ( ! strncmp ( L_190 , V_500 , 4 ) ) {
V_100 -> V_480 = V_546 ;
} else if ( ! strncmp ( L_188 , V_500 , 4 ) ) {
if ( V_100 -> V_300 ) {
V_100 -> V_480 = V_481 ;
} else {
F_25 ( V_2 ,
L_192 ) ;
V_82 = - V_102 ;
}
} else if ( ! strncmp ( L_189 , V_500 , 4 ) ) {
if ( V_100 -> V_402 ) {
V_100 -> V_480 = V_484 ;
} else {
F_25 ( V_2 ,
L_193 ) ;
V_82 = - V_102 ;
}
} else {
F_25 ( V_2 , L_194 ) ;
V_82 = - V_102 ;
}
return V_82 ? : V_214 ;
}
static void F_155 ( void * V_2 , void * V_221 , struct V_497 * V_547 )
{
struct V_79 * V_100 = V_221 ;
struct V_181 * V_182 ;
V_182 = F_156 ( V_100 , struct V_181 , V_100 ) ;
if ( ! V_182 -> V_226 )
return;
F_157 ( L_195 , V_548 | V_549 , V_547 ,
V_100 , & V_550 ) ;
F_157 ( L_196 , V_548 , V_547 ,
V_100 , & V_551 ) ;
F_157 ( L_197 , V_548 | V_549 , V_547 ,
V_100 , & V_552 ) ;
F_158 ( L_198 , V_548 | V_549 , V_547 ,
& V_100 -> V_354 ) ;
F_158 ( L_199 , V_548 | V_549 , V_547 ,
& V_100 -> V_106 . V_333 ) ;
F_159 ( V_480 , V_547 , V_548 | V_549 ) ;
return;
V_288:
F_25 ( (struct V_1 * ) V_2 , L_200 ) ;
}
static void F_160 ( void * V_2 , void * V_328 )
{
}
static void F_161 ( void * V_218 ,
struct V_219 * V_220 ,
struct V_435 * V_436 ,
struct V_3 * V_4 , void * V_328 )
{
}
int F_162 ( void )
{
return F_163 ( & V_553 ) ;
}
void F_164 ( void )
{
F_165 ( & V_553 ) ;
}
int F_166 ( struct V_1 * V_2 , struct V_181 * V_182 ,
bool V_554 )
{
struct V_172 * V_186 = & V_182 -> V_100 . V_186 ;
F_167 ( & V_2 -> V_555 ) ;
if ( V_554 ) {
if ( V_182 -> V_556 == 0 )
V_186 -> V_158 |= V_496 ;
V_182 -> V_556 ++ ;
} else {
V_182 -> V_556 -- ;
if ( V_182 -> V_556 == 0 )
V_186 -> V_158 &= ~ V_496 ;
}
return F_66 ( V_2 , V_186 , false ) ;
}
