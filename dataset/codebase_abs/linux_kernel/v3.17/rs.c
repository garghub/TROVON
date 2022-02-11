static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_4 -> V_7 . V_8 )
return false ;
if ( V_4 -> V_9 == V_10 )
return false ;
if ( F_2 ( V_2 -> V_11 -> V_12 ) < 2 )
return false ;
if ( ! F_3 ( V_2 , V_4 ) )
return false ;
return true ;
}
static bool F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( ! V_4 -> V_7 . V_8 )
return false ;
return true ;
}
static bool F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = & V_6 -> V_14 ;
struct V_15 * V_7 = & V_4 -> V_7 ;
struct V_16 * V_17 = & V_4 -> V_17 ;
if ( F_6 ( V_14 ) && ( V_7 -> V_18 &
V_19 ) )
return true ;
if ( F_7 ( V_14 ) && ( V_7 -> V_18 &
V_20 ) )
return true ;
if ( F_8 ( V_14 ) && ( V_17 -> V_18 &
V_21 ) )
return true ;
return false ;
}
static inline T_1 F_9 ( T_2 V_22 )
{
return ( T_1 ) ( V_22 & V_23 ) ;
}
static int F_10 ( T_2 V_22 )
{
int V_24 = 0 ;
if ( V_22 & V_25 ) {
V_24 = V_22 & V_26 ;
V_24 += V_27 ;
if ( V_24 >= V_28 )
V_24 += 1 ;
if ( ( V_24 >= V_29 ) && ( V_24 <= V_30 ) )
return V_24 ;
} else if ( V_22 & V_31 ) {
V_24 = V_22 & V_32 ;
V_24 += V_27 ;
if ( V_24 >= V_28 )
V_24 ++ ;
if ( ( V_24 >= V_33 ) && ( V_24 <= V_34 ) )
return V_24 ;
} else {
T_1 V_35 = F_9 ( V_22 ) ;
for ( V_24 = 0 ; V_24 < F_11 ( V_36 ) ; V_24 ++ )
if ( V_36 [ V_24 ] . V_37 == V_35 )
return V_24 ;
}
return V_38 ;
}
static const char * F_12 ( T_1 V_39 )
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
if ( V_39 > V_48 )
return L_9 ;
return V_40 [ V_39 ] ;
}
static const char * F_13 ( enum V_49 type )
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
static inline void F_14 ( struct V_1 * V_2 , const struct V_13 * V_14 ,
const char * V_59 )
{
F_15 ( V_2 , L_17 ,
V_59 , F_13 ( V_14 -> type ) ,
V_14 -> V_60 , F_12 ( V_14 -> V_39 ) ,
V_14 -> V_61 , V_14 -> V_62 ) ;
}
static void F_16 ( struct V_63 * V_64 )
{
V_64 -> V_65 = 0 ;
V_64 -> V_66 = 0 ;
V_64 -> V_67 = V_68 ;
V_64 -> V_69 = 0 ;
V_64 -> V_70 = V_68 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_71 ;
F_15 ( V_2 , L_18 ) ;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ )
F_16 ( & V_6 -> V_73 [ V_71 ] ) ;
for ( V_71 = 0 ; V_71 < F_11 ( V_6 -> V_74 ) ; V_71 ++ )
F_16 ( & V_6 -> V_74 [ V_71 ] ) ;
}
static inline T_1 F_18 ( T_1 V_75 , T_1 V_76 )
{
return ( V_76 & V_75 ) == V_76 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_77 * V_78 , T_1 V_79 ,
struct V_3 * V_4 )
{
int V_80 = - V_81 ;
F_20 ( V_2 , L_19 ,
V_4 -> V_82 , V_79 ) ;
V_80 = F_21 ( V_4 , V_79 , 5000 ) ;
if ( V_80 == - V_81 ) {
F_22 ( V_2 , L_20 ,
V_79 ) ;
F_23 ( V_4 , V_79 ) ;
}
return V_80 ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_79 ,
struct V_77 * V_78 ,
struct V_3 * V_4 )
{
if ( V_79 < V_83 )
F_19 ( V_2 , V_78 , V_79 , V_4 ) ;
else
F_22 ( V_2 , L_21 ,
V_79 , V_83 ) ;
}
static inline int F_25 ( T_2 V_22 )
{
return ! ! ( V_22 & V_84 ) +
! ! ( V_22 & V_85 ) +
! ! ( V_22 & V_86 ) ;
}
static T_3 F_26 ( struct V_5 * V_6 , int V_87 )
{
if ( V_6 -> V_88 )
return V_6 -> V_88 [ V_87 ] ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
int V_89 , int V_90 , int V_91 ,
struct V_63 * V_64 )
{
static const T_4 V_92 = ( ( ( T_4 ) 1 ) << ( V_93 - 1 ) ) ;
T_3 V_94 , V_95 ;
V_95 = F_26 ( V_6 , V_89 ) ;
while ( V_90 > 0 ) {
if ( V_64 -> V_69 >= V_93 ) {
V_64 -> V_69 = V_93 - 1 ;
if ( V_64 -> V_65 & V_92 ) {
V_64 -> V_65 &= ~ V_92 ;
V_64 -> V_66 -- ;
}
}
V_64 -> V_69 ++ ;
V_64 -> V_65 <<= 1 ;
if ( V_91 > 0 ) {
V_64 -> V_66 ++ ;
V_64 -> V_65 |= 0x1 ;
V_91 -- ;
}
V_90 -- ;
}
if ( V_64 -> V_69 > 0 )
V_64 -> V_67 = 128 * ( 100 * V_64 -> V_66 )
/ V_64 -> V_69 ;
else
V_64 -> V_67 = V_68 ;
V_94 = V_64 -> V_69 - V_64 -> V_66 ;
if ( ( V_94 >= V_96 ) ||
( V_64 -> V_66 >= V_97 ) )
V_64 -> V_70 = ( V_64 -> V_67 * V_95 + 64 ) / 128 ;
else
V_64 -> V_70 = V_68 ;
return 0 ;
}
static int F_28 ( struct V_77 * V_98 ,
struct V_5 * V_6 ,
int V_89 , int V_90 , int V_91 ,
T_1 V_99 )
{
struct V_63 * V_64 = NULL ;
int V_80 ;
if ( V_89 < 0 || V_89 >= V_72 )
return - V_100 ;
if ( V_6 -> V_101 != V_102 ) {
V_98 -> V_103 [ V_6 -> V_101 ] [ V_89 ] . V_104 += V_90 ;
V_98 -> V_103 [ V_6 -> V_101 ] [ V_89 ] . V_105 += V_91 ;
}
V_64 = & ( V_6 -> V_73 [ V_89 ] ) ;
V_80 = F_27 ( V_6 , V_89 , V_90 , V_91 ,
V_64 ) ;
if ( V_80 )
return V_80 ;
if ( F_29 ( V_99 > V_106 ) )
return - V_100 ;
V_64 = & V_6 -> V_74 [ V_99 ] ;
return F_27 ( V_6 , V_89 , V_90 , V_91 ,
V_64 ) ;
}
static T_2 F_30 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_2 V_107 = 0 ;
int V_60 = V_14 -> V_60 ;
V_107 |= ( ( V_14 -> V_39 << V_108 ) &
V_109 ) ;
if ( F_31 ( V_14 ) ) {
V_107 |= V_36 [ V_60 ] . V_37 ;
if ( V_60 >= V_110 && V_60 <= V_111 )
V_107 |= V_112 ;
return V_107 ;
}
if ( F_32 ( V_14 ) ) {
if ( V_60 < V_29 || V_60 > V_30 ) {
F_22 ( V_2 , L_22 , V_60 ) ;
V_60 = V_30 ;
}
V_107 |= V_25 ;
if ( F_33 ( V_14 ) )
V_107 |= V_36 [ V_60 ] . V_113 ;
else if ( F_34 ( V_14 ) )
V_107 |= V_36 [ V_60 ] . V_114 ;
else
F_29 ( 1 ) ;
} else if ( F_35 ( V_14 ) ) {
if ( V_60 < V_33 || V_60 > V_34 ) {
F_22 ( V_2 , L_23 , V_60 ) ;
V_60 = V_34 ;
}
V_107 |= V_31 ;
if ( F_36 ( V_14 ) )
V_107 |= V_36 [ V_60 ] . V_115 ;
else if ( F_37 ( V_14 ) )
V_107 |= V_36 [ V_60 ] . V_116 ;
else
F_29 ( 1 ) ;
} else {
F_22 ( V_2 , L_24 , V_14 -> type ) ;
}
V_107 |= V_14 -> V_61 ;
if ( V_14 -> V_62 )
V_107 |= V_117 ;
return V_107 ;
}
static int F_38 ( const T_2 V_107 ,
enum V_118 V_119 ,
struct V_13 * V_14 )
{
T_2 V_120 = V_107 & V_109 ;
T_1 F_2 = F_25 ( V_107 ) ;
T_1 V_121 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_60 = F_10 ( V_107 ) ;
if ( V_14 -> V_60 == V_38 )
return - V_100 ;
V_14 -> V_39 = ( V_120 >> V_108 ) ;
if ( ! ( V_107 & V_25 ) &&
! ( V_107 & V_31 ) ) {
if ( F_2 == 1 ) {
if ( V_119 == V_122 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
}
return 0 ;
}
if ( V_107 & V_117 )
V_14 -> V_62 = true ;
V_14 -> V_61 = V_107 & V_123 ;
if ( V_107 & V_25 ) {
V_121 = ( ( V_107 & V_124 ) >>
V_125 ) + 1 ;
if ( V_121 == 1 ) {
V_14 -> type = V_54 ;
F_29 ( F_2 != 1 ) ;
} else if ( V_121 == 2 ) {
V_14 -> type = V_55 ;
F_29 ( F_2 != 2 ) ;
} else {
F_29 ( 1 ) ;
}
} else if ( V_107 & V_31 ) {
V_121 = ( ( V_107 & V_126 ) >>
V_127 ) + 1 ;
if ( V_121 == 1 ) {
V_14 -> type = V_56 ;
F_29 ( F_2 != 1 ) ;
} else if ( V_121 == 2 ) {
V_14 -> type = V_57 ;
F_29 ( F_2 != 2 ) ;
} else {
F_29 ( 1 ) ;
}
}
F_29 ( V_14 -> V_61 == V_128 ) ;
F_29 ( V_14 -> V_61 == V_129 &&
! F_35 ( V_14 ) ) ;
return 0 ;
}
static int F_39 ( T_2 V_130 , struct V_13 * V_14 )
{
T_1 V_131 ;
if ( ! V_14 -> V_39 || V_14 -> V_39 > V_48 )
return 0 ;
if ( ! F_18 ( V_130 , V_14 -> V_39 ) )
return 0 ;
V_131 = V_132 [ V_14 -> V_39 ] ;
while ( ( V_131 != V_14 -> V_39 ) &&
! F_18 ( V_130 , V_131 ) )
V_131 = V_132 [ V_131 ] ;
if ( V_131 == V_14 -> V_39 )
return 0 ;
V_14 -> V_39 = V_131 ;
return 1 ;
}
static T_5 F_40 ( struct V_77 * V_98 ,
struct V_13 * V_14 )
{
if ( F_31 ( V_14 ) )
return V_98 -> V_133 ;
else if ( F_41 ( V_14 ) )
return V_98 -> V_134 ;
else if ( F_42 ( V_14 ) )
return V_98 -> V_135 ;
F_29 ( 1 ) ;
return 0 ;
}
static T_5 F_43 ( struct V_1 * V_2 , T_1 V_60 , T_5 V_136 ,
int V_137 )
{
T_1 V_138 = V_38 ;
T_1 V_139 = V_38 ;
if ( F_44 ( V_137 ) || ! F_45 ( V_137 ) ) {
int V_71 ;
T_2 V_92 ;
V_71 = V_60 - 1 ;
for ( V_92 = ( 1 << V_71 ) ; V_71 >= 0 ; V_71 -- , V_92 >>= 1 ) {
if ( V_136 & V_92 ) {
V_139 = V_71 ;
break;
}
}
V_71 = V_60 + 1 ;
for ( V_92 = ( 1 << V_71 ) ; V_71 < V_72 ; V_71 ++ , V_92 <<= 1 ) {
if ( V_136 & V_92 ) {
V_138 = V_71 ;
break;
}
}
return ( V_138 << 8 ) | V_139 ;
}
V_139 = V_60 ;
while ( V_139 != V_38 ) {
V_139 = V_36 [ V_139 ] . V_140 ;
if ( V_139 == V_38 )
break;
if ( V_136 & ( 1 << V_139 ) )
break;
F_15 ( V_2 , L_25 , V_139 ) ;
}
V_138 = V_60 ;
while ( V_138 != V_38 ) {
V_138 = V_36 [ V_138 ] . V_141 ;
if ( V_138 == V_38 )
break;
if ( V_136 & ( 1 << V_138 ) )
break;
F_15 ( V_2 , L_26 , V_138 ) ;
}
return ( V_138 << 8 ) | V_139 ;
}
static inline bool F_46 ( struct V_77 * V_98 ,
struct V_13 * V_14 )
{
return F_47 ( V_14 -> V_60 ) & F_40 ( V_98 , V_14 ) ;
}
static bool F_48 ( struct V_77 * V_98 ,
struct V_13 * V_14 )
{
T_1 V_139 ;
T_5 V_142 ;
T_5 V_136 ;
struct V_1 * V_2 = V_98 -> V_143 . V_144 ;
V_136 = F_40 ( V_98 , V_14 ) ;
V_142 = F_43 ( V_2 , V_14 -> V_60 , V_136 ,
V_14 -> type ) ;
V_139 = V_142 & 0xff ;
if ( V_139 == V_38 )
return true ;
V_14 -> V_60 = V_139 ;
return false ;
}
static void F_49 ( struct V_77 * V_98 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = V_98 -> V_143 . V_144 ;
if ( F_31 ( V_14 ) ) {
return;
} else if ( F_41 ( V_14 ) ) {
if ( V_98 -> V_119 == V_122 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
V_14 -> V_61 = V_145 ;
F_29 ( V_14 -> V_60 < V_27 ||
V_14 -> V_60 > V_146 ) ;
V_14 -> V_60 = V_147 [ V_14 -> V_60 ] ;
} else {
V_14 -> type = F_37 ( V_14 ) ?
V_56 : V_54 ;
}
if ( F_2 ( V_14 -> V_39 ) > 1 )
V_14 -> V_39 = F_50 ( V_2 -> V_11 -> V_12 ) ;
V_14 -> V_62 = false ;
if ( ! F_46 ( V_98 , V_14 ) )
F_48 ( V_98 , V_14 ) ;
}
static inline bool F_51 ( struct V_13 * V_148 ,
struct V_13 * V_149 )
{
return ( V_148 -> type == V_149 -> type ) && ( V_148 -> V_39 == V_149 -> V_39 ) && ( V_148 -> V_62 == V_149 -> V_62 ) ;
}
static T_2 F_52 ( enum V_150 V_151 )
{
if ( V_151 & V_152 )
return V_153 ;
else if ( V_151 & V_154 )
return V_129 ;
else if ( V_151 & V_155 )
return V_128 ;
return V_145 ;
}
static void F_53 ( void * V_156 , struct V_157 * V_158 ,
struct V_3 * V_4 , void * V_159 ,
struct V_160 * V_161 )
{
int V_162 ;
int V_163 ;
int V_164 , V_71 ;
struct V_77 * V_98 = V_159 ;
struct V_165 * V_166 ;
struct V_167 * V_168 = (struct V_167 * ) V_161 -> V_65 ;
struct V_169 * V_170 = (struct V_169 * ) V_156 ;
struct V_1 * V_2 = F_54 ( V_170 ) ;
struct V_171 * V_172 = F_55 ( V_161 ) ;
enum V_150 V_173 ;
T_2 V_107 ;
struct V_13 V_14 ;
struct V_5 * V_174 , * V_175 , * V_176 ;
T_1 V_99 = ( V_177 ) V_172 -> V_178 . V_179 [ 0 ] ;
if ( ! V_98 ) {
F_15 ( V_2 , L_27 ) ;
return;
} else if ( ! V_98 -> V_143 . V_144 ) {
F_15 ( V_2 , L_28 ) ;
return;
}
#ifdef F_56
if ( V_98 -> V_143 . V_180 ) {
F_15 ( V_2 , L_29 ) ;
return;
}
#endif
if ( ! F_57 ( V_168 -> V_181 ) ||
V_172 -> V_151 & V_182 )
return;
if ( ( V_172 -> V_151 & V_183 ) &&
! ( V_172 -> V_151 & V_184 ) )
return;
V_166 = & V_98 -> V_185 ;
V_107 = F_58 ( V_166 -> V_186 [ 0 ] ) ;
F_38 ( V_107 , V_172 -> V_119 , & V_14 ) ;
if ( V_172 -> V_119 == V_122 )
V_14 . V_60 -= V_187 ;
V_173 = V_172 -> V_178 . V_188 [ 0 ] . V_151 ;
V_164 = V_172 -> V_178 . V_188 [ 0 ] . V_24 ;
if ( V_173 & V_189 ) {
V_164 &= V_26 ;
if ( V_164 >= ( V_28 - V_187 ) )
V_164 ++ ;
if ( V_172 -> V_119 == V_190 )
V_164 += V_187 ;
} else if ( V_173 & V_191 ) {
V_164 &= V_32 ;
if ( V_164 >= ( V_28 - V_187 ) )
V_164 ++ ;
}
if ( F_59 ( V_192 ,
( unsigned long ) ( V_98 -> V_193 + V_194 ) ) ) {
int V_79 ;
F_15 ( V_2 , L_30 ) ;
for ( V_79 = 0 ; V_79 < V_83 ; V_79 ++ )
F_23 ( V_4 , V_79 ) ;
F_60 ( V_2 , V_4 , V_158 -> V_119 , false ) ;
return;
}
V_98 -> V_193 = V_192 ;
if ( ( V_164 < 0 ) ||
( V_14 . V_62 != ! ! ( V_173 & V_195 ) ) ||
( V_14 . V_61 != F_52 ( V_173 ) ) ||
( V_14 . V_39 != V_172 -> V_178 . V_196 ) ||
( ! ! ( V_107 & V_25 ) !=
! ! ( V_173 & V_189 ) ) ||
( ! ! ( V_107 & V_31 ) !=
! ! ( V_173 & V_191 ) ) ||
( ! ! ( V_107 & V_197 ) !=
! ! ( V_173 & V_198 ) ) ||
( V_14 . V_60 != V_164 ) ) {
F_15 ( V_2 ,
L_31 ,
V_164 , V_14 . V_60 , V_107 ) ;
V_98 -> V_199 ++ ;
if ( V_98 -> V_199 > V_200 ) {
V_98 -> V_199 = 0 ;
F_15 ( V_2 ,
L_32 ,
V_98 -> V_201 ) ;
F_61 ( V_2 , & V_98 -> V_185 , false ) ;
}
return;
} else
V_98 -> V_199 = 0 ;
if ( F_51 ( & V_14 ,
& ( V_98 -> V_202 [ V_98 -> V_203 ] . V_14 ) ) ) {
V_174 = & ( V_98 -> V_202 [ V_98 -> V_203 ] ) ;
V_175 = & ( V_98 -> V_202 [ 1 - V_98 -> V_203 ] ) ;
} else if ( F_51 ( & V_14 ,
& V_98 -> V_202 [ 1 - V_98 -> V_203 ] . V_14 ) ) {
V_174 = & ( V_98 -> V_202 [ 1 - V_98 -> V_203 ] ) ;
V_175 = & ( V_98 -> V_202 [ V_98 -> V_203 ] ) ;
} else {
F_15 ( V_2 ,
L_33 ) ;
V_176 = & ( V_98 -> V_202 [ V_98 -> V_203 ] ) ;
F_14 ( V_2 , & V_176 -> V_14 , L_34 ) ;
V_176 = & ( V_98 -> V_202 [ 1 - V_98 -> V_203 ] ) ;
F_14 ( V_2 , & V_176 -> V_14 , L_35 ) ;
F_14 ( V_2 , & V_14 , L_36 ) ;
F_62 ( V_98 , true ) ;
goto V_204;
}
if ( V_172 -> V_151 & V_184 ) {
V_107 = F_58 ( V_166 -> V_186 [ 0 ] ) ;
F_38 ( V_107 , V_172 -> V_119 , & V_14 ) ;
F_28 ( V_98 , V_174 , V_14 . V_60 ,
V_172 -> V_178 . V_205 ,
V_172 -> V_178 . V_206 ,
V_99 ) ;
if ( V_98 -> V_201 == V_207 ) {
V_98 -> V_208 += V_172 -> V_178 . V_206 ;
V_98 -> V_209 += ( V_172 -> V_178 . V_205 -
V_172 -> V_178 . V_206 ) ;
}
} else {
V_163 = V_172 -> V_178 . V_188 [ 0 ] . V_210 - 1 ;
V_163 = F_63 ( V_163 , 15 ) ;
V_162 = ! ! ( V_172 -> V_151 & V_211 ) ;
for ( V_71 = 0 ; V_71 <= V_163 ; ++ V_71 ) {
V_107 = F_58 ( V_166 -> V_186 [ V_71 ] ) ;
F_38 ( V_107 , V_172 -> V_119 , & V_14 ) ;
if ( F_51 ( & V_14 , & V_174 -> V_14 ) )
V_176 = V_174 ;
else if ( F_51 ( & V_14 , & V_175 -> V_14 ) )
V_176 = V_175 ;
else
continue;
F_28 ( V_98 , V_176 , V_14 . V_60 , 1 ,
V_71 < V_163 ? 0 : V_162 ,
V_99 ) ;
}
if ( V_98 -> V_201 == V_207 ) {
V_98 -> V_208 += V_162 ;
V_98 -> V_209 += V_163 + ( 1 - V_162 ) ;
}
}
V_98 -> V_212 = V_107 ;
F_15 ( V_2 , L_37 , V_99 ) ;
V_204:
if ( V_4 && V_4 -> V_213 [ V_158 -> V_119 ] )
F_64 ( V_2 , V_161 , V_4 , V_98 ) ;
}
static void F_65 ( struct V_1 * V_2 , T_1 F_31 ,
struct V_77 * V_98 )
{
F_15 ( V_2 , L_38 ) ;
V_98 -> V_201 = V_207 ;
if ( F_31 ) {
V_98 -> V_214 = V_215 ;
V_98 -> V_216 = V_217 ;
V_98 -> V_218 = V_219 ;
} else {
V_98 -> V_214 = V_220 ;
V_98 -> V_216 = V_221 ;
V_98 -> V_218 = V_222 ;
}
V_98 -> V_223 = 0 ;
V_98 -> V_209 = 0 ;
V_98 -> V_208 = 0 ;
V_98 -> V_224 = V_192 ;
V_98 -> V_225 = 0 ;
}
static int F_66 ( struct V_77 * V_98 ,
const struct V_226 * V_101 )
{
switch ( V_101 -> V_227 ) {
case V_228 :
return V_98 -> V_229 ;
case V_230 :
return V_98 -> V_231 ;
case V_232 :
return V_98 -> V_233 ;
default:
F_29 ( 1 ) ;
}
return V_98 -> V_229 ;
}
static const T_5 * F_67 ( struct V_77 * V_98 ,
const struct V_226 * V_101 ,
T_2 V_61 )
{
const T_5 ( * V_234 ) [ V_72 ] ;
if ( F_29 ( V_101 -> V_227 != V_228 &&
V_101 -> V_227 != V_230 &&
V_101 -> V_227 != V_232 ) )
return V_235 ;
if ( V_101 -> V_227 == V_228 )
return V_235 ;
V_234 = V_236 ;
if ( V_101 -> V_227 == V_230 ) {
switch ( V_61 ) {
case V_145 :
V_234 = V_237 ;
break;
case V_153 :
V_234 = V_238 ;
break;
case V_129 :
V_234 = V_239 ;
break;
default:
F_29 ( 1 ) ;
}
} else if ( V_101 -> V_227 == V_232 ) {
switch ( V_61 ) {
case V_145 :
V_234 = V_236 ;
break;
case V_153 :
V_234 = V_240 ;
break;
case V_129 :
V_234 = V_241 ;
break;
default:
F_29 ( 1 ) ;
}
} else {
F_29 ( 1 ) ;
}
if ( ! V_101 -> V_62 && ! V_98 -> V_242 )
return V_234 [ 0 ] ;
else if ( V_101 -> V_62 && ! V_98 -> V_242 )
return V_234 [ 1 ] ;
else if ( ! V_101 -> V_62 && V_98 -> V_242 )
return V_234 [ 2 ] ;
else
return V_234 [ 3 ] ;
}
static void F_68 ( struct V_77 * V_98 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = & V_6 -> V_14 ;
const struct V_226 * V_101 = & V_243 [ V_6 -> V_101 ] ;
V_6 -> V_88 = F_67 ( V_98 , V_101 , V_14 -> V_61 ) ;
}
static T_3 F_69 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
struct V_5 * V_6 ,
unsigned long V_136 , T_6 V_60 )
{
struct V_5 * V_203 =
& ( V_98 -> V_202 [ V_98 -> V_203 ] ) ;
T_3 V_67 = V_203 -> V_73 [ V_60 ] . V_67 ;
T_5 V_244 = V_203 -> V_88 [ V_60 ] ;
const T_5 * V_245 = V_6 -> V_88 ;
T_5 V_142 ;
T_2 V_246 ;
int V_247 ;
if ( V_67 > V_248 ) {
V_246 = 100 * V_244 ;
F_15 ( V_2 ,
L_39 ,
V_67 , V_246 ) ;
} else {
V_246 = V_98 -> V_249 ;
F_15 ( V_2 ,
L_40 ,
V_67 , V_246 ) ;
}
V_247 = F_70 ( & V_136 , V_250 ) ;
while ( V_247 != V_38 ) {
if ( V_246 < ( 100 * V_245 [ V_247 ] ) )
break;
V_142 = F_43 ( V_2 , V_247 , V_136 ,
V_6 -> V_14 . type ) ;
V_247 = ( V_142 >> 8 ) & 0xff ;
}
F_15 ( V_2 , L_41 ,
V_247 , V_246 ,
V_247 != V_38 ?
100 * V_245 [ V_247 ] : V_68 ) ;
return V_247 ;
}
static T_2 F_71 ( struct V_3 * V_4 )
{
if ( V_4 -> V_251 >= V_252 )
return V_129 ;
else if ( V_4 -> V_251 >= V_253 )
return V_153 ;
return V_145 ;
}
static void F_62 ( struct V_77 * V_98 , bool V_254 )
{
struct V_5 * V_6 ;
int V_203 ;
int V_255 = 0 ;
struct V_1 * V_2 ;
V_2 = V_98 -> V_143 . V_144 ;
V_203 = V_98 -> V_203 ;
V_6 = & ( V_98 -> V_202 [ V_203 ] ) ;
if ( V_98 -> V_201 == V_207 ) {
if ( V_98 -> V_224 )
V_255 =
F_59 ( V_192 ,
( unsigned long ) ( V_98 -> V_224 +
V_256 ) ) ;
if ( V_254 ||
( V_98 -> V_209 > V_98 -> V_216 ) ||
( V_98 -> V_208 > V_98 -> V_218 ) ||
( ( ! V_98 -> V_257 ) &&
( V_98 -> V_224 ) && ( V_255 ) ) ) {
F_15 ( V_2 ,
L_42 ,
V_98 -> V_209 ,
V_98 -> V_208 ,
V_255 ) ;
V_98 -> V_201 = V_258 ;
F_15 ( V_2 ,
L_43 ) ;
V_98 -> V_209 = 0 ;
V_98 -> V_208 = 0 ;
V_98 -> V_224 = 0 ;
V_98 -> V_225 = F_47 ( V_6 -> V_101 ) ;
} else {
V_98 -> V_223 ++ ;
if ( V_98 -> V_223 >=
V_98 -> V_214 ) {
V_98 -> V_223 = 0 ;
F_15 ( V_2 ,
L_44 ) ;
F_17 ( V_2 , V_6 ) ;
}
}
if ( V_98 -> V_201 == V_258 ) {
F_17 ( V_2 , V_6 ) ;
}
}
}
static void F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_77 * V_98 ,
struct V_13 * V_14 )
{
F_73 ( V_2 , V_4 , V_98 , V_14 ) ;
F_61 ( V_2 , & V_98 -> V_185 , false ) ;
}
static T_1 F_74 ( struct V_77 * V_78 ,
struct V_167 * V_168 )
{
T_1 V_79 = V_83 ;
if ( F_75 ( V_168 -> V_181 ) ) {
T_1 * V_259 = F_76 ( V_168 ) ;
V_79 = V_259 [ 0 ] & 0xf ;
}
if ( F_77 ( V_79 > V_83 ) )
V_79 = V_83 ;
return V_79 ;
}
static enum V_260 F_78 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_71 , V_261 , V_262 ;
enum V_260 V_263 ;
const struct V_226 * V_264 = & V_243 [ V_6 -> V_101 ] ;
const struct V_226 * V_265 ;
T_7 V_266 ;
T_1 V_267 = V_2 -> V_11 -> V_12 ;
const T_5 * V_268 ;
T_5 V_95 , V_269 ;
for ( V_71 = 0 ; V_71 < V_270 ; V_71 ++ ) {
V_263 = V_264 -> V_271 [ V_71 ] ;
if ( V_263 == V_102 )
continue;
if ( V_98 -> V_225 & F_47 ( V_263 ) ) {
F_15 ( V_2 , L_45 ,
V_263 ) ;
continue;
}
V_265 = & V_243 [ V_263 ] ;
if ( ! F_18 ( V_267 , V_265 -> V_39 ) ) {
F_15 ( V_2 ,
L_46 ,
V_263 , V_267 , V_265 -> V_39 ) ;
continue;
}
for ( V_261 = 0 ; V_261 < V_272 ; V_261 ++ ) {
V_266 = V_265 -> V_273 [ V_261 ] ;
if ( V_266 && ! V_266 ( V_2 , V_4 , V_6 ) )
break;
}
if ( V_261 != V_272 ) {
F_15 ( V_2 ,
L_47 ,
V_263 , V_261 ) ;
continue;
}
V_95 = V_98 -> V_249 / 100 ;
V_268 = F_67 ( V_98 , V_265 ,
F_71 ( V_4 ) ) ;
if ( F_29 ( ! V_268 ) )
continue;
V_262 = F_66 ( V_98 , V_265 ) ;
if ( F_29 ( V_262 == V_38 ) )
continue;
V_269 = V_268 [ V_262 ] ;
if ( V_95 >= V_269 ) {
F_15 ( V_2 ,
L_48 ,
V_263 , V_269 , V_95 ) ;
continue;
}
F_15 ( V_2 ,
L_49 ,
V_263 , V_269 , V_95 ) ;
break;
}
if ( V_71 == V_270 )
return V_102 ;
return V_263 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
struct V_3 * V_4 ,
enum V_260 V_274 )
{
struct V_5 * V_6 = & ( V_98 -> V_202 [ V_98 -> V_203 ] ) ;
struct V_5 * V_275 =
& ( V_98 -> V_202 [ ( 1 - V_98 -> V_203 ) ] ) ;
struct V_13 * V_14 = & V_275 -> V_14 ;
const struct V_226 * V_101 = & V_243 [ V_274 ] ;
const struct V_226 * V_276 = & V_243 [ V_6 -> V_101 ] ;
T_2 V_277 = ( sizeof( struct V_5 ) -
( sizeof( struct V_63 ) * V_72 ) ) ;
unsigned long V_136 = 0 ;
T_2 V_247 = 0 ;
memcpy ( V_275 , V_6 , V_277 ) ;
V_14 -> V_62 = V_101 -> V_62 ;
V_14 -> V_39 = V_101 -> V_39 ;
if ( V_101 -> V_227 == V_228 ) {
if ( V_98 -> V_119 == V_122 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
V_136 = V_98 -> V_133 ;
} else if ( V_101 -> V_227 == V_230 ) {
V_14 -> type = V_98 -> F_35 ? V_56 : V_54 ;
V_136 = V_98 -> V_134 ;
} else if ( V_101 -> V_227 == V_232 ) {
V_14 -> type = V_98 -> F_35 ? V_57 : V_55 ;
V_136 = V_98 -> V_135 ;
} else {
F_29 ( L_50 ) ;
}
V_14 -> V_61 = F_71 ( V_4 ) ;
V_275 -> V_101 = V_274 ;
F_68 ( V_98 , V_275 ) ;
V_98 -> V_225 |= F_47 ( V_274 ) ;
if ( V_276 -> V_227 != V_101 -> V_227 ) {
V_247 = F_69 ( V_2 , V_98 , V_275 ,
V_136 , V_14 -> V_60 ) ;
if ( ( V_247 == V_38 ) ||
! ( F_47 ( V_247 ) & V_136 ) ) {
F_15 ( V_2 ,
L_51
L_52 ,
V_247 , V_136 ) ;
goto V_278;
}
V_14 -> V_60 = V_247 ;
}
F_15 ( V_2 , L_53 ,
V_274 , V_14 -> V_60 ) ;
return 0 ;
V_278:
V_14 -> type = V_51 ;
return - 1 ;
}
static enum V_279 F_80 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_3 V_280 , int V_139 , int V_138 ,
int V_281 ,
int V_282 , int V_283 )
{
enum V_279 V_284 = V_285 ;
if ( ( V_280 <= V_286 ) || ( V_281 == 0 ) ) {
F_15 ( V_2 ,
L_54 ) ;
return V_287 ;
}
if ( ( V_282 == V_68 ) &&
( V_283 == V_68 ) &&
( V_138 != V_38 ) ) {
F_15 ( V_2 ,
L_55 ) ;
return V_288 ;
}
if ( ( V_283 == V_68 ) &&
( V_138 != V_38 ) &&
( V_282 != V_68 ) &&
( V_282 < V_281 ) ) {
F_15 ( V_2 ,
L_56 ) ;
return V_288 ;
}
if ( ( V_283 != V_68 ) &&
( V_283 > V_281 ) ) {
F_15 ( V_2 ,
L_57 ) ;
return V_288 ;
}
if ( ( V_282 != V_68 ) &&
( V_283 != V_68 ) &&
( V_282 < V_281 ) &&
( V_283 < V_281 ) ) {
F_15 ( V_2 ,
L_58 ) ;
return V_285 ;
}
if ( ( V_282 != V_68 ) &&
( V_282 > V_281 ) ) {
F_15 ( V_2 ,
L_59 ) ;
V_284 = V_287 ;
goto V_289;
}
if ( ( V_282 == V_68 ) &&
( V_139 != V_38 ) ) {
F_15 ( V_2 ,
L_60 ) ;
V_284 = V_287 ;
goto V_289;
}
F_15 ( V_2 , L_61 ) ;
V_289:
if ( ( V_284 == V_287 ) && ( V_139 != V_38 ) ) {
if ( V_280 >= V_248 ) {
F_15 ( V_2 ,
L_62 ) ;
V_284 = V_285 ;
} else if ( V_281 > ( 100 * V_6 -> V_88 [ V_139 ] ) ) {
F_15 ( V_2 ,
L_63 ) ;
V_284 = V_285 ;
} else {
F_15 ( V_2 , L_64 ) ;
}
}
return V_284 ;
}
static void F_81 ( struct V_1 * V_2 , int V_60 ,
int * V_290 , int * V_291 )
{
* V_290 = V_60 + V_292 ;
if ( * V_290 > V_106 )
* V_290 = V_293 ;
* V_291 = V_60 - V_292 ;
if ( * V_291 < 0 )
* V_291 = V_293 ;
}
static bool F_82 ( struct V_1 * V_2 , struct V_294 * V_295 ,
struct V_13 * V_14 , enum V_118 V_119 )
{
int V_60 = V_14 -> V_60 ;
bool V_296 = ( V_297 . V_298 == V_299 ) ;
bool V_300 = ( V_295 -> type == V_301 &&
! V_295 -> V_302 . V_303 ) ;
F_15 ( V_2 , L_65 ,
V_296 , V_300 ) ;
if ( ( V_296 || V_300 ) &&
! F_83 ( V_2 , V_119 ) )
return false ;
F_15 ( V_2 , L_66 , V_14 -> type ) ;
if ( F_31 ( V_14 ) )
return V_60 == V_304 ;
if ( F_32 ( V_14 ) )
return V_60 == V_305 ;
if ( F_35 ( V_14 ) )
return V_60 == V_305 ||
V_60 == V_306 ||
V_60 == V_146 ;
F_29 ( 1 ) ;
return false ;
}
static enum V_307 F_84 ( struct V_1 * V_2 ,
T_3 V_280 , int V_308 , int V_309 ,
int V_281 ,
int V_310 , int V_311 )
{
if ( V_281 == V_68 ) {
F_15 ( V_2 , L_67 ) ;
return V_312 ;
}
if ( V_280 <= V_313 || V_281 == 0 ) {
F_15 ( V_2 , L_68 ) ;
return V_314 ;
}
if ( V_308 != V_293 ) {
if ( V_310 == V_68 &&
( V_311 == V_68 ||
V_281 >= V_311 ) ) {
F_15 ( V_2 ,
L_69 ) ;
return V_315 ;
}
if ( V_310 > V_281 ) {
F_15 ( V_2 ,
L_70 ) ;
return V_315 ;
}
}
if ( V_280 < V_316 && V_309 != V_293 ) {
if ( V_310 == V_68 &&
V_311 != V_68 &&
V_281 < V_311 ) {
F_15 ( V_2 ,
L_71 ) ;
return V_317 ;
}
if ( V_310 < V_281 &&
( V_311 == V_68 ||
V_311 > V_281 ) ) {
F_15 ( V_2 ,
L_72 ) ;
return V_317 ;
}
}
F_15 ( V_2 , L_73 ) ;
return V_312 ;
}
static bool F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_77 * V_98 ,
struct V_5 * V_6 )
{
struct V_318 * V_319 = ( void * ) V_4 -> V_320 ;
struct V_294 * V_295 = V_319 -> V_295 ;
struct V_321 * V_322 ;
enum V_118 V_119 ;
struct V_63 * V_64 ;
struct V_13 * V_14 = & V_6 -> V_14 ;
enum V_307 V_284 ;
T_3 V_280 ;
T_1 V_323 = V_98 -> V_185 . V_324 ;
int V_281 ;
int V_308 , V_309 ;
int V_310 = V_68 , V_311 = V_68 ;
#ifdef F_56
if ( V_98 -> V_143 . V_325 <= V_106 ) {
F_15 ( V_2 , L_74 ,
V_98 -> V_143 . V_325 ) ;
V_98 -> V_185 . V_324 = V_98 -> V_143 . V_325 ;
return V_323 != V_98 -> V_143 . V_325 ;
}
#endif
F_86 () ;
V_322 = F_87 ( V_295 -> V_322 ) ;
if ( F_88 ( ! V_322 ) )
V_119 = V_326 ;
else
V_119 = V_322 -> V_327 . V_328 -> V_119 ;
F_89 () ;
if ( ! F_82 ( V_2 , V_295 , V_14 , V_119 ) ) {
F_15 ( V_2 ,
L_75 ) ;
V_98 -> V_185 . V_324 = V_329 ;
return V_323 != V_329 ;
}
F_81 ( V_2 , V_323 , & V_308 , & V_309 ) ;
V_64 = V_6 -> V_74 ;
V_280 = V_64 [ V_323 ] . V_67 ;
V_281 = V_64 [ V_323 ] . V_70 ;
if ( V_308 != V_293 )
V_310 = V_64 [ V_308 ] . V_70 ;
if ( V_309 != V_293 )
V_311 = V_64 [ V_309 ] . V_70 ;
F_15 ( V_2 ,
L_76 ,
V_323 , V_281 , V_280 , V_308 , V_309 ,
V_310 , V_311 ) ;
V_284 = F_84 ( V_2 , V_280 , V_308 , V_309 ,
V_281 , V_310 , V_311 ) ;
if ( V_308 == V_293 && V_284 == V_315 ) {
F_15 ( V_2 , L_77 ) ;
V_284 = V_312 ;
} else if ( V_309 == V_293 &&
( V_284 == V_317 ||
V_284 == V_314 ) ) {
F_15 ( V_2 , L_78 ) ;
V_284 = V_312 ;
}
switch ( V_284 ) {
case V_315 :
V_98 -> V_185 . V_324 = V_308 ;
return true ;
case V_317 :
V_98 -> V_185 . V_324 = V_309 ;
return true ;
case V_314 :
V_98 -> V_185 . V_324 = V_329 ;
return true ;
case V_312 :
break;
}
return false ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_160 * V_161 ,
struct V_3 * V_4 ,
struct V_77 * V_98 )
{
struct V_171 * V_172 = F_55 ( V_161 ) ;
struct V_167 * V_168 = (struct V_167 * ) V_161 -> V_65 ;
int V_139 = V_38 ;
int V_138 = V_38 ;
int V_60 ;
struct V_63 * V_64 = NULL ;
int V_281 = V_68 ;
int V_282 = V_68 ;
int V_283 = V_68 ;
T_2 V_94 ;
enum V_279 V_330 = V_285 ;
T_5 V_136 ;
T_1 V_331 = 0 ;
struct V_5 * V_6 , * V_332 ;
T_1 V_203 = 0 ;
T_1 V_333 = 0 ;
T_5 V_142 ;
T_3 V_280 ;
T_1 V_79 = V_83 ;
T_1 V_334 = V_98 -> V_242 ;
struct V_318 * V_335 = ( void * ) V_4 -> V_320 ;
struct V_336 * V_337 ;
struct V_13 * V_14 ;
if ( ! F_57 ( V_168 -> V_181 ) ||
V_172 -> V_151 & V_182 )
return;
V_79 = F_74 ( V_98 , V_168 ) ;
if ( ( V_79 != V_83 ) &&
( V_98 -> V_338 & ( 1 << V_79 ) ) ) {
V_337 = & V_335 -> V_337 [ V_79 ] ;
if ( V_337 -> V_339 == V_340 )
V_98 -> V_242 = 0 ;
else
V_98 -> V_242 = 1 ;
} else {
V_98 -> V_242 = 0 ;
}
if ( ! V_98 -> V_257 )
V_203 = V_98 -> V_203 ;
else
V_203 = 1 - V_98 -> V_203 ;
V_6 = & ( V_98 -> V_202 [ V_203 ] ) ;
V_14 = & V_6 -> V_14 ;
if ( V_334 != V_98 -> V_242 ) {
F_15 ( V_2 ,
L_79 ,
V_334 , V_98 -> V_242 ) ;
F_68 ( V_98 , V_6 ) ;
F_17 ( V_2 , V_6 ) ;
}
V_60 = V_98 -> V_341 ;
V_136 = F_40 ( V_98 , V_14 ) ;
if ( ! ( F_47 ( V_60 ) & V_136 ) ) {
F_22 ( V_2 , L_80 ) ;
if ( V_98 -> V_257 ) {
V_14 -> type = V_51 ;
V_98 -> V_257 = 0 ;
V_6 = & ( V_98 -> V_202 [ V_98 -> V_203 ] ) ;
F_72 ( V_2 , V_4 , V_98 , & V_6 -> V_14 ) ;
}
return;
}
if ( ! V_6 -> V_88 ) {
F_22 ( V_2 , L_81 ) ;
return;
}
if ( ( V_98 -> V_342 != - 1 ) &&
( V_98 -> V_342 < V_60 ) ) {
V_60 = V_98 -> V_342 ;
V_331 = 1 ;
V_64 = & ( V_6 -> V_73 [ V_60 ] ) ;
F_15 ( V_2 ,
L_82 ,
V_60 ) ;
goto V_343;
}
V_64 = & ( V_6 -> V_73 [ V_60 ] ) ;
V_94 = V_64 -> V_69 - V_64 -> V_66 ;
if ( ( V_94 < V_96 ) &&
( V_64 -> V_66 < V_97 ) ) {
F_15 ( V_2 ,
L_83 ,
F_13 ( V_14 -> type ) ,
V_60 , V_64 -> V_66 , V_64 -> V_69 ) ;
V_64 -> V_70 = V_68 ;
F_62 ( V_98 , false ) ;
goto V_289;
}
if ( V_64 -> V_70 != ( ( V_64 -> V_67 *
V_6 -> V_88 [ V_60 ] + 64 ) / 128 ) ) {
V_64 -> V_70 = ( ( V_64 -> V_67 *
V_6 -> V_88 [ V_60 ] + 64 ) / 128 ) ;
}
if ( V_98 -> V_257 ) {
if ( V_64 -> V_70 > V_98 -> V_249 ) {
F_15 ( V_2 ,
L_84
L_85 ,
V_64 -> V_67 ,
V_64 -> V_70 ,
V_98 -> V_249 ) ;
V_98 -> V_203 = V_203 ;
V_281 = V_64 -> V_70 ;
} else {
F_15 ( V_2 ,
L_86
L_85 ,
V_64 -> V_67 ,
V_64 -> V_70 ,
V_98 -> V_249 ) ;
V_14 -> type = V_51 ;
V_203 = V_98 -> V_203 ;
V_6 = & ( V_98 -> V_202 [ V_203 ] ) ;
V_60 = V_6 -> V_14 . V_60 ;
V_281 = V_98 -> V_249 ;
V_331 = 1 ;
}
V_98 -> V_257 = 0 ;
V_333 = 1 ;
goto V_343;
}
V_142 = F_43 ( V_2 , V_60 , V_136 , V_14 -> type ) ;
V_139 = V_142 & 0xff ;
V_138 = ( V_142 >> 8 ) & 0xff ;
if ( ( V_98 -> V_342 != - 1 ) &&
( V_98 -> V_342 < V_138 ) )
V_138 = V_38 ;
V_280 = V_64 -> V_67 ;
V_281 = V_64 -> V_70 ;
if ( V_139 != V_38 )
V_282 = V_6 -> V_73 [ V_139 ] . V_70 ;
if ( V_138 != V_38 )
V_283 = V_6 -> V_73 [ V_138 ] . V_70 ;
F_15 ( V_2 ,
L_87 ,
F_13 ( V_14 -> type ) , V_60 , V_281 , V_280 ,
V_139 , V_138 , V_282 , V_283 ) ;
V_330 = F_80 ( V_2 , V_6 , V_280 , V_139 , V_138 ,
V_281 , V_282 , V_283 ) ;
if ( F_90 ( V_14 ) &&
! F_3 ( V_2 , V_4 ) ) {
F_15 ( V_2 ,
L_88 ) ;
F_62 ( V_98 , true ) ;
goto V_343;
}
switch ( V_330 ) {
case V_287 :
if ( V_139 != V_38 ) {
V_331 = 1 ;
V_60 = V_139 ;
} else {
F_15 ( V_2 ,
L_89 ) ;
}
break;
case V_288 :
if ( V_138 != V_38 ) {
V_331 = 1 ;
V_60 = V_138 ;
} else {
F_15 ( V_2 ,
L_90 ) ;
}
break;
case V_285 :
if ( V_98 -> V_201 == V_207 )
V_331 = F_85 ( V_2 , V_4 , V_98 , V_6 ) ;
break;
default:
break;
}
V_343:
if ( V_331 ) {
V_6 -> V_14 . V_60 = V_60 ;
F_72 ( V_2 , V_4 , V_98 , & V_6 -> V_14 ) ;
}
F_62 ( V_98 , false ) ;
if ( ! V_331 && ! V_333 &&
V_98 -> V_201 == V_258
&& V_64 -> V_69 ) {
enum V_260 V_344 ;
V_98 -> V_249 = V_281 ;
F_15 ( V_2 ,
L_91 ,
V_331 , V_333 , V_98 -> V_201 ,
V_64 -> V_69 ) ;
V_344 = F_78 ( V_2 , V_98 , V_4 , V_6 ) ;
if ( V_344 != V_102 ) {
int V_80 = F_79 ( V_2 , V_98 , V_4 ,
V_344 ) ;
if ( ! V_80 )
V_98 -> V_257 = 1 ;
} else {
F_15 ( V_2 ,
L_92 ) ;
V_98 -> V_201 = V_345 ;
}
if ( V_98 -> V_257 ) {
V_6 = & ( V_98 -> V_202 [ ( 1 - V_98 -> V_203 ) ] ) ;
F_17 ( V_2 , V_6 ) ;
V_60 = V_6 -> V_14 . V_60 ;
F_14 ( V_2 , & V_6 -> V_14 ,
L_93 ) ;
F_73 ( V_2 , V_4 , V_98 , & V_6 -> V_14 ) ;
F_61 ( V_2 , & V_98 -> V_185 , false ) ;
} else {
V_333 = 1 ;
}
}
if ( V_333 && V_98 -> V_201 == V_345 ) {
V_332 = & ( V_98 -> V_202 [ V_98 -> V_203 ] ) ;
if ( F_31 ( & V_332 -> V_14 ) ) {
F_15 ( V_2 , L_94 ) ;
if ( V_79 != V_83 ) {
V_337 = & V_335 -> V_337 [ V_79 ] ;
if ( V_337 -> V_339 != V_340 ) {
F_15 ( V_2 ,
L_95 ,
V_79 ) ;
F_23 ( V_4 , V_79 ) ;
}
}
F_65 ( V_2 , 1 , V_98 ) ;
} else {
if ( ( V_98 -> V_249 > V_346 ) &&
( V_98 -> V_338 & ( 1 << V_79 ) ) &&
( V_79 != V_83 ) ) {
V_337 = & V_335 -> V_337 [ V_79 ] ;
if ( V_337 -> V_339 == V_340 ) {
F_15 ( V_2 ,
L_96 ,
V_79 ) ;
F_24 ( V_2 , V_79 ,
V_98 , V_4 ) ;
}
}
F_65 ( V_2 , 0 , V_98 ) ;
}
}
V_289:
V_98 -> V_341 = V_60 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_77 * V_98 ,
enum V_118 V_119 ,
bool V_347 )
{
struct V_5 * V_6 ;
struct V_13 * V_14 ;
int V_71 ;
T_1 V_203 = 0 ;
T_1 V_12 ;
if ( ! V_4 || ! V_98 )
return;
V_71 = V_98 -> V_341 ;
V_12 = V_2 -> V_11 -> V_12 ;
if ( ! V_98 -> V_257 )
V_203 = V_98 -> V_203 ;
else
V_203 = 1 - V_98 -> V_203 ;
V_6 = & ( V_98 -> V_202 [ V_203 ] ) ;
V_14 = & V_6 -> V_14 ;
if ( ( V_71 < 0 ) || ( V_71 >= V_72 ) )
V_71 = 0 ;
V_14 -> V_60 = V_71 ;
V_14 -> V_39 = F_50 ( V_12 ) ;
V_14 -> V_62 = false ;
V_14 -> V_61 = V_145 ;
if ( V_119 == V_122 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
F_29 ( V_14 -> V_39 != V_42 && V_14 -> V_39 != V_43 ) ;
if ( V_14 -> V_39 == V_42 )
V_6 -> V_101 = V_348 ;
else
V_6 -> V_101 = V_349 ;
F_68 ( V_98 , V_6 ) ;
F_73 ( V_2 , V_4 , V_98 , V_14 ) ;
F_61 ( V_2 , & V_98 -> V_185 , V_347 ) ;
}
static void F_92 ( void * V_156 , struct V_3 * V_4 , void * V_319 ,
struct V_350 * V_351 )
{
struct V_160 * V_161 = V_351 -> V_161 ;
struct V_157 * V_158 = V_351 -> V_158 ;
struct V_169 * V_170 V_352 =
(struct V_169 * ) V_156 ;
struct V_1 * V_2 V_352 = F_54 ( V_170 ) ;
struct V_171 * V_172 = F_55 ( V_161 ) ;
struct V_77 * V_98 = V_319 ;
if ( V_98 ) {
V_98 -> V_342 = V_351 -> V_342 ;
if ( ( V_158 -> V_119 == V_122 ) &&
( V_98 -> V_342 != - 1 ) )
V_98 -> V_342 += V_187 ;
if ( ( V_98 -> V_342 < 0 ) ||
( V_98 -> V_342 >= V_72 ) )
V_98 -> V_342 = - 1 ;
}
if ( V_98 && ! V_98 -> V_143 . V_144 ) {
F_15 ( V_2 , L_28 ) ;
V_319 = NULL ;
}
if ( F_93 ( V_4 , V_319 , V_351 ) )
return;
F_94 ( V_98 -> V_212 ,
V_172 -> V_119 , & V_172 -> V_353 . V_188 [ 0 ] ) ;
V_172 -> V_353 . V_188 [ 0 ] . V_210 = 1 ;
}
static void * F_95 ( void * V_354 , struct V_3 * V_4 ,
T_8 V_355 )
{
struct V_318 * V_335 = (struct V_318 * ) V_4 -> V_320 ;
struct V_169 * V_170 = (struct V_169 * ) V_354 ;
struct V_1 * V_2 = F_54 ( V_170 ) ;
struct V_77 * V_98 = & V_335 -> V_98 ;
F_15 ( V_2 , L_97 ) ;
V_98 -> V_143 . V_144 = V_2 ;
#ifdef F_56
V_98 -> V_143 . V_180 = 0 ;
V_98 -> V_143 . V_325 = V_293 ;
#endif
return & V_335 -> V_98 ;
}
static int F_96 ( struct V_16 * V_17 ,
int V_121 )
{
T_5 V_356 = F_97 ( V_17 -> V_357 . V_358 ) &
( 0x3 << ( 2 * ( V_121 - 1 ) ) ) ;
V_356 >>= ( 2 * ( V_121 - 1 ) ) ;
if ( V_356 == V_359 )
return V_305 ;
else if ( V_356 == V_360 )
return V_306 ;
else if ( V_356 == V_361 )
return V_146 ;
F_29 ( V_356 != V_362 ) ;
return - 1 ;
}
static void F_98 ( struct V_3 * V_4 ,
struct V_16 * V_17 ,
struct V_77 * V_98 )
{
int V_71 ;
int V_363 = F_96 ( V_17 , 1 ) ;
if ( V_363 >= V_27 ) {
for ( V_71 = V_27 ; V_71 <= V_363 ; V_71 ++ ) {
if ( V_71 == V_28 )
continue;
if ( V_71 == V_146 &&
V_4 -> V_251 == V_364 )
continue;
V_98 -> V_134 |= F_47 ( V_71 ) ;
}
}
if ( V_4 -> V_365 < 2 )
return;
V_363 = F_96 ( V_17 , 2 ) ;
if ( V_363 >= V_27 ) {
for ( V_71 = V_27 ; V_71 <= V_363 ; V_71 ++ ) {
if ( V_71 == V_28 )
continue;
if ( V_71 == V_146 &&
V_4 -> V_251 == V_364 )
continue;
V_98 -> V_135 |= F_47 ( V_71 ) ;
}
}
}
static void F_99 ( struct V_1 * V_2 ,
struct V_366 * V_367 )
{
F_100 ( & V_2 -> V_368 ) ;
memset ( V_367 , 0 , sizeof( * V_367 ) ) ;
F_101 ( & V_2 -> V_368 ) ;
}
void F_102 ( struct V_1 * V_2 ,
struct V_366 * V_367 ,
T_2 V_14 , bool V_369 )
{
T_1 V_121 = 0 , V_370 = 0 ;
F_103 ( & V_2 -> V_368 ) ;
if ( V_369 )
V_367 -> V_371 ++ ;
V_367 -> V_372 ++ ;
switch ( V_14 & V_123 ) {
case V_145 :
V_367 -> V_373 ++ ;
break;
case V_153 :
V_367 -> V_374 ++ ;
break;
case V_129 :
V_367 -> V_375 ++ ;
break;
default:
F_104 ( 1 , L_98 , V_14 ) ;
}
if ( V_14 & V_25 ) {
V_367 -> V_376 ++ ;
V_370 = V_14 & V_26 ;
V_121 = ( ( V_14 & V_124 ) >> V_125 ) + 1 ;
} else if ( V_14 & V_31 ) {
V_367 -> V_377 ++ ;
V_370 = V_14 & V_32 ;
V_121 = ( ( V_14 & V_126 ) >>
V_127 ) + 1 ;
} else {
V_367 -> V_378 ++ ;
}
if ( V_121 == 1 )
V_367 -> V_379 ++ ;
else if ( V_121 == 2 )
V_367 -> V_380 ++ ;
if ( V_14 & V_117 )
V_367 -> V_381 ++ ;
else
V_367 -> V_382 ++ ;
V_367 -> V_383 [ V_367 -> V_384 ] = V_14 ;
V_367 -> V_384 = ( V_367 -> V_384 + 1 ) %
F_11 ( V_367 -> V_383 ) ;
F_105 ( & V_2 -> V_368 ) ;
}
void F_60 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_118 V_119 , bool V_347 )
{
int V_71 , V_261 ;
struct V_385 * V_386 = V_2 -> V_386 ;
struct V_15 * V_7 = & V_4 -> V_7 ;
struct V_16 * V_17 = & V_4 -> V_17 ;
struct V_318 * V_335 ;
struct V_77 * V_98 ;
struct V_157 * V_158 ;
unsigned long V_387 ;
V_335 = (struct V_318 * ) V_4 -> V_320 ;
V_98 = & V_335 -> V_98 ;
memset ( V_98 , 0 , F_106 ( F_107 ( * V_98 ) , V_143 ) ) ;
V_158 = V_386 -> V_388 -> V_389 [ V_119 ] ;
V_98 -> V_185 . V_390 = V_335 -> V_390 ;
for ( V_261 = 0 ; V_261 < V_391 ; V_261 ++ )
F_17 ( V_2 , & V_98 -> V_202 [ V_261 ] ) ;
V_98 -> V_224 = 0 ;
V_98 -> V_193 = V_192 ;
F_15 ( V_2 ,
L_99 ,
V_335 -> V_390 ) ;
V_98 -> V_342 = - 1 ;
V_98 -> V_199 = V_200 ;
V_98 -> V_119 = V_158 -> V_119 ;
V_387 = V_4 -> V_213 [ V_158 -> V_119 ] ;
V_98 -> V_133 = 0 ;
F_108 (i, &supp, BITS_PER_LONG)
V_98 -> V_133 |= F_47 ( V_158 -> V_392 [ V_71 ] . V_393 ) ;
if ( ! V_17 || ! V_17 -> V_394 ) {
V_98 -> V_134 = V_7 -> V_370 . V_395 [ 0 ] << 1 ;
V_98 -> V_134 |= V_7 -> V_370 . V_395 [ 0 ] & 0x1 ;
V_98 -> V_134 &= ~ ( ( T_5 ) 0x2 ) ;
V_98 -> V_134 <<= V_187 ;
V_98 -> V_135 = V_7 -> V_370 . V_395 [ 1 ] << 1 ;
V_98 -> V_135 |= V_7 -> V_370 . V_395 [ 1 ] & 0x1 ;
V_98 -> V_135 &= ~ ( ( T_5 ) 0x2 ) ;
V_98 -> V_135 <<= V_187 ;
V_98 -> F_35 = false ;
} else {
F_98 ( V_4 , V_17 , V_98 ) ;
V_98 -> F_35 = true ;
}
V_98 -> V_229 = F_109 ( & V_98 -> V_133 ,
V_250 ) ;
V_98 -> V_231 = F_109 ( & V_98 -> V_134 ,
V_250 ) ;
V_98 -> V_233 = F_109 ( & V_98 -> V_135 ,
V_250 ) ;
F_15 ( V_2 , L_100 ,
V_98 -> V_133 ,
V_98 -> V_134 ,
V_98 -> V_135 ,
V_98 -> F_35 ) ;
F_15 ( V_2 , L_101 ,
V_98 -> V_229 ,
V_98 -> V_231 ,
V_98 -> V_233 ) ;
V_98 -> V_185 . V_396 =
F_50 ( V_2 -> V_11 -> V_12 ) ;
V_98 -> V_185 . V_397 = V_44 ;
V_98 -> V_338 = V_398 ;
V_98 -> V_341 = F_110 ( V_158 , V_4 ) ;
if ( V_158 -> V_119 == V_122 )
V_98 -> V_341 += V_187 ;
V_98 -> V_242 = 0 ;
#ifdef F_111
F_99 ( V_2 , & V_2 -> V_399 ) ;
#endif
F_91 ( V_2 , V_4 , V_98 , V_119 , V_347 ) ;
}
static void F_112 ( void * V_156 ,
struct V_157 * V_158 ,
struct V_400 * V_401 ,
struct V_3 * V_4 , void * V_159 ,
T_2 V_402 )
{
T_1 V_79 ;
struct V_169 * V_170 =
(struct V_169 * ) V_156 ;
struct V_1 * V_2 = F_54 ( V_170 ) ;
for ( V_79 = 0 ; V_79 < V_83 ; V_79 ++ )
F_23 ( V_4 , V_79 ) ;
F_60 ( V_2 , V_4 , V_158 -> V_119 , false ) ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_165 * V_403 ,
enum V_118 V_119 ,
T_2 V_107 )
{
struct V_13 V_14 ;
int V_71 ;
int V_404 = F_11 ( V_403 -> V_186 ) ;
T_9 V_405 = F_114 ( V_107 ) ;
for ( V_71 = 0 ; V_71 < V_404 ; V_71 ++ )
V_403 -> V_186 [ V_71 ] = V_405 ;
F_38 ( V_107 , V_119 , & V_14 ) ;
if ( F_90 ( & V_14 ) )
V_403 -> V_406 = V_404 - 1 ;
else
V_403 -> V_406 = 0 ;
}
static void F_115 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
struct V_13 * V_14 ,
T_9 * V_186 , int * V_407 ,
int V_404 , int V_408 ,
T_1 V_12 , bool V_409 )
{
int V_71 , V_261 ;
T_9 V_107 ;
bool V_410 = false ;
int V_411 = V_14 -> V_60 ;
int V_412 = V_413 ;
int V_60 = * V_407 ;
for ( V_71 = 0 ; V_71 < V_404 && V_60 < V_412 ; V_71 ++ ) {
V_107 = F_114 ( F_30 ( V_2 , V_14 ) ) ;
for ( V_261 = 0 ; V_261 < V_408 && V_60 < V_412 ; V_261 ++ , V_60 ++ )
V_186 [ V_60 ] = V_107 ;
if ( V_409 )
F_39 ( V_12 , V_14 ) ;
V_411 = V_14 -> V_60 ;
V_410 = F_48 ( V_98 , V_14 ) ;
if ( V_410 && ! F_31 ( V_14 ) )
break;
}
if ( ! V_410 )
V_14 -> V_60 = V_411 ;
* V_407 = V_60 ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
const struct V_13 * V_414 )
{
struct V_13 V_14 ;
int V_404 , V_408 , V_60 = 0 ;
T_1 V_12 = 0 ;
struct V_165 * V_403 = & V_98 -> V_185 ;
bool V_409 = false ;
memcpy ( & V_14 , V_414 , sizeof( V_14 ) ) ;
V_12 = V_2 -> V_11 -> V_12 ;
if ( F_41 ( & V_14 ) ) {
V_404 = V_415 ;
V_408 = V_416 ;
} else if ( F_90 ( & V_14 ) ) {
V_404 = V_417 ;
V_408 = V_416 ;
} else {
V_404 = V_418 ;
V_408 = V_419 ;
V_409 = true ;
}
F_115 ( V_2 , V_98 , & V_14 , V_403 -> V_186 , & V_60 ,
V_404 , V_408 , V_12 ,
V_409 ) ;
F_49 ( V_98 , & V_14 ) ;
if ( F_41 ( & V_14 ) ) {
V_404 = V_420 ;
V_408 = V_421 ;
V_403 -> V_406 = V_60 ;
} else if ( F_31 ( & V_14 ) ) {
V_404 = V_422 ;
V_408 = V_419 ;
} else {
F_29 ( 1 ) ;
}
V_409 = true ;
F_115 ( V_2 , V_98 , & V_14 , V_403 -> V_186 , & V_60 ,
V_404 , V_408 , V_12 ,
V_409 ) ;
F_49 ( V_98 , & V_14 ) ;
V_404 = V_422 ;
V_408 = V_419 ;
F_115 ( V_2 , V_98 , & V_14 , V_403 -> V_186 , & V_60 ,
V_404 , V_408 , V_12 ,
V_409 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_77 * V_98 ,
const struct V_13 * V_414 )
{
struct V_165 * V_403 = & V_98 -> V_185 ;
T_1 V_39 = V_414 -> V_39 ;
#ifdef F_56
if ( V_98 -> V_143 . V_180 ) {
F_113 ( V_2 , V_403 ,
V_98 -> V_119 ,
V_98 -> V_143 . V_180 ) ;
V_403 -> V_324 = 0 ;
V_39 = ( V_98 -> V_143 . V_180 & V_109 ) >>
V_108 ;
} else
#endif
F_116 ( V_2 , V_98 , V_414 ) ;
if ( F_2 ( V_39 ) == 1 )
V_403 -> V_396 = V_39 ;
V_403 -> V_423 = V_424 ;
V_403 -> V_425 = V_426 ;
V_403 -> V_427 =
F_117 ( V_428 ) ;
if ( V_4 )
V_403 -> V_427 =
F_117 ( F_118 ( V_2 , V_4 ) ) ;
}
static void * F_119 ( struct V_385 * V_386 , struct V_429 * V_430 )
{
return V_386 -> V_431 ;
}
static void F_120 ( void * V_354 )
{
return;
}
static void F_121 ( void * V_156 , struct V_3 * V_4 ,
void * V_319 )
{
struct V_169 * V_170 V_352 = V_156 ;
struct V_1 * V_2 V_352 = F_54 ( V_170 ) ;
F_15 ( V_2 , L_102 ) ;
F_15 ( V_2 , L_103 ) ;
}
int F_122 ( char * V_432 , const T_2 V_14 )
{
char * type , * V_61 ;
T_1 V_370 = 0 , V_121 = 0 ;
T_1 V_39 = ( V_14 & V_109 ) >> V_108 ;
if ( ! ( V_14 & V_25 ) &&
! ( V_14 & V_31 ) ) {
int V_60 = F_10 ( V_14 ) ;
return sprintf ( V_432 , L_104 ,
F_12 ( V_39 ) ,
V_60 == V_38 ? L_105 :
V_433 [ V_60 ] . V_434 ) ;
}
if ( V_14 & V_31 ) {
type = L_106 ;
V_370 = V_14 & V_32 ;
V_121 = ( ( V_14 & V_126 )
>> V_127 ) + 1 ;
} else if ( V_14 & V_25 ) {
type = L_107 ;
V_370 = V_14 & V_435 ;
} else {
type = L_108 ;
}
switch ( V_14 & V_123 ) {
case V_145 :
V_61 = L_109 ;
break;
case V_153 :
V_61 = L_110 ;
break;
case V_129 :
V_61 = L_111 ;
break;
case V_128 :
V_61 = L_112 ;
break;
default:
V_61 = L_113 ;
}
return sprintf ( V_432 , L_114 ,
type , F_12 ( V_39 ) , V_61 , V_370 , V_121 ,
( V_14 & V_117 ) ? L_115 : L_116 ,
( V_14 & V_436 ) ? L_117 : L_118 ,
( V_14 & V_437 ) ? L_119 : L_118 ,
( V_14 & V_438 ) ? L_120 : L_118 ,
( V_14 & V_439 ) ? L_121 : L_118 ) ;
}
static void F_123 ( struct V_1 * V_2 ,
struct V_77 * V_98 )
{
V_98 -> V_133 = 0x0FFF ;
V_98 -> V_134 = 0x1FD0 ;
V_98 -> V_135 = 0x1FD0 ;
F_15 ( V_2 , L_122 ,
V_98 -> V_185 . V_390 , V_98 -> V_143 . V_180 ) ;
if ( V_98 -> V_143 . V_180 ) {
struct V_13 V_14 ;
F_38 ( V_98 -> V_143 . V_180 ,
V_98 -> V_119 , & V_14 ) ;
F_73 ( V_2 , NULL , V_98 , & V_14 ) ;
F_61 ( V_98 -> V_143 . V_144 , & V_98 -> V_185 , false ) ;
}
}
static T_10 F_124 ( struct V_440 * V_440 ,
const char T_11 * V_441 , T_12 V_210 , T_13 * V_442 )
{
struct V_77 * V_98 = V_440 -> V_443 ;
struct V_1 * V_2 ;
char V_432 [ 64 ] ;
T_12 V_444 ;
T_2 V_445 ;
V_2 = V_98 -> V_143 . V_144 ;
memset ( V_432 , 0 , sizeof( V_432 ) ) ;
V_444 = F_63 ( V_210 , sizeof( V_432 ) - 1 ) ;
if ( F_125 ( V_432 , V_441 , V_444 ) )
return - V_446 ;
if ( sscanf ( V_432 , L_123 , & V_445 ) == 1 )
V_98 -> V_143 . V_180 = V_445 ;
else
V_98 -> V_143 . V_180 = 0 ;
F_123 ( V_2 , V_98 ) ;
return V_210 ;
}
static T_10 F_126 ( struct V_440 * V_440 ,
char T_11 * V_441 , T_12 V_210 , T_13 * V_442 )
{
char * V_447 ;
int V_448 = 0 ;
int V_71 = 0 ;
T_10 V_80 ;
struct V_77 * V_98 = V_440 -> V_443 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = & ( V_98 -> V_202 [ V_98 -> V_203 ] ) ;
struct V_13 * V_14 = & V_6 -> V_14 ;
V_2 = V_98 -> V_143 . V_144 ;
V_447 = F_127 ( 2048 , V_449 ) ;
if ( ! V_447 )
return - V_450 ;
V_448 += sprintf ( V_447 + V_448 , L_124 , V_98 -> V_185 . V_390 ) ;
V_448 += sprintf ( V_447 + V_448 , L_125 ,
V_98 -> V_209 , V_98 -> V_208 ,
V_98 -> V_133 ) ;
V_448 += sprintf ( V_447 + V_448 , L_126 ,
V_98 -> V_143 . V_180 ) ;
V_448 += sprintf ( V_447 + V_448 , L_127 ,
( V_2 -> V_11 -> V_12 & V_42 ) ? L_128 : L_118 ,
( V_2 -> V_11 -> V_12 & V_43 ) ? L_129 : L_118 ,
( V_2 -> V_11 -> V_12 & V_45 ) ? L_130 : L_118 ) ;
V_448 += sprintf ( V_447 + V_448 , L_131 ,
( F_31 ( V_14 ) ) ? L_132 :
F_35 ( V_14 ) ? L_106 : L_107 ) ;
if ( ! F_31 ( V_14 ) ) {
V_448 += sprintf ( V_447 + V_448 , L_133 ,
( F_41 ( V_14 ) ) ? L_134 : L_135 ) ;
V_448 += sprintf ( V_447 + V_448 , L_133 ,
( F_6 ( V_14 ) ) ? L_136 :
( F_7 ( V_14 ) ) ? L_137 :
( F_8 ( V_14 ) ) ? L_111 : L_113 ) ;
V_448 += sprintf ( V_447 + V_448 , L_138 ,
( V_14 -> V_62 ) ? L_139 : L_140 ,
( V_98 -> V_242 ) ? L_141 : L_118 ) ;
}
V_448 += sprintf ( V_447 + V_448 , L_142 ,
V_98 -> V_212 ) ;
V_448 += sprintf ( V_447 + V_448 ,
L_143 ,
V_98 -> V_185 . V_151 ,
V_98 -> V_185 . V_406 ,
V_98 -> V_185 . V_396 ,
V_98 -> V_185 . V_397 ) ;
V_448 += sprintf ( V_447 + V_448 ,
L_144 ,
F_97 ( V_98 -> V_185 . V_427 ) ,
V_98 -> V_185 . V_425 ,
V_98 -> V_185 . V_423 ) ;
V_448 += sprintf ( V_447 + V_448 , L_145 , V_98 -> V_185 . V_324 ) ;
V_448 += sprintf ( V_447 + V_448 ,
L_146 ,
V_98 -> V_185 . V_451 [ 0 ] ,
V_98 -> V_185 . V_451 [ 1 ] ,
V_98 -> V_185 . V_451 [ 2 ] ,
V_98 -> V_185 . V_451 [ 3 ] ) ;
for ( V_71 = 0 ; V_71 < V_413 ; V_71 ++ ) {
T_2 V_452 = F_58 ( V_98 -> V_185 . V_186 [ V_71 ] ) ;
V_448 += sprintf ( V_447 + V_448 , L_147 , V_71 , V_452 ) ;
V_448 += F_122 ( V_447 + V_448 , V_452 ) ;
}
V_80 = F_128 ( V_441 , V_210 , V_442 , V_447 , V_448 ) ;
F_129 ( V_447 ) ;
return V_80 ;
}
static T_10 F_130 ( struct V_440 * V_440 ,
char T_11 * V_441 , T_12 V_210 , T_13 * V_442 )
{
char * V_447 ;
int V_448 = 0 ;
int V_71 , V_261 ;
T_10 V_80 ;
struct V_5 * V_6 ;
struct V_13 * V_14 ;
struct V_77 * V_98 = V_440 -> V_443 ;
V_447 = F_127 ( 1024 , V_449 ) ;
if ( ! V_447 )
return - V_450 ;
for ( V_71 = 0 ; V_71 < V_391 ; V_71 ++ ) {
V_6 = & ( V_98 -> V_202 [ V_71 ] ) ;
V_14 = & V_6 -> V_14 ;
V_448 += sprintf ( V_447 + V_448 ,
L_148
L_149 ,
V_98 -> V_203 == V_71 ? L_150 : L_151 ,
V_14 -> type ,
V_14 -> V_62 ,
F_6 ( V_14 ) ? L_109 :
F_7 ( V_14 ) ? L_110 :
F_8 ( V_14 ) ? L_111 : L_152 ,
V_14 -> V_60 ) ;
for ( V_261 = 0 ; V_261 < V_72 ; V_261 ++ ) {
V_448 += sprintf ( V_447 + V_448 ,
L_153 ,
V_6 -> V_73 [ V_261 ] . V_69 ,
V_6 -> V_73 [ V_261 ] . V_66 ,
V_6 -> V_73 [ V_261 ] . V_67 ) ;
}
}
V_80 = F_128 ( V_441 , V_210 , V_442 , V_447 , V_448 ) ;
F_129 ( V_447 ) ;
return V_80 ;
}
static T_10 F_131 ( struct V_440 * V_440 ,
char T_11 * V_441 ,
T_12 V_210 , T_13 * V_442 )
{
static const char * const V_453 [] = {
[ V_348 ] = L_154 ,
[ V_349 ] = L_155 ,
[ V_454 ] = L_156 ,
[ V_455 ] = L_157 ,
[ V_456 ] = L_158 ,
[ V_457 ] = L_159 ,
[ V_458 ] = L_135 ,
[ V_459 ] = L_160 ,
} ;
static const char * const V_460 [] = {
[ V_461 ] = L_161 ,
[ V_462 ] = L_162 ,
[ V_463 ] = L_163 ,
[ V_464 ] = L_164 ,
[ V_465 ] = L_165 ,
[ V_28 ] = L_166 ,
[ V_466 ] = L_167 ,
[ V_467 ] = L_168 ,
[ V_468 ] = L_169 ,
[ V_469 ] = L_170 ,
[ V_470 ] = L_171 ,
[ V_304 ] = L_172 ,
[ V_305 ] = L_173 ,
[ V_306 ] = L_174 ,
[ V_146 ] = L_175 ,
} ;
char * V_447 , * V_471 , * V_472 ;
int V_473 , V_14 ;
T_10 V_80 ;
struct V_77 * V_98 = V_440 -> V_443 ;
struct V_474 * V_367 ;
static const T_12 V_475 = 1024 ;
V_447 = F_127 ( V_475 , V_449 ) ;
if ( ! V_447 )
return - V_450 ;
V_471 = V_447 ;
V_472 = V_471 + V_475 ;
V_471 += F_132 ( V_471 , V_472 - V_471 , L_176 ) ;
for ( V_14 = 0 ; V_14 < V_72 ; V_14 ++ )
V_471 += F_132 ( V_471 , V_472 - V_471 , L_177 , V_460 [ V_14 ] ) ;
V_471 += F_132 ( V_471 , V_472 - V_471 , L_178 ) ;
for ( V_473 = 0 ; V_473 < V_476 ; V_473 ++ ) {
V_471 += F_132 ( V_471 , V_472 - V_471 ,
L_177 , V_453 [ V_473 ] ) ;
for ( V_14 = 0 ; V_14 < V_72 ; V_14 ++ ) {
V_367 = & ( V_98 -> V_103 [ V_473 ] [ V_14 ] ) ;
V_471 += F_132 ( V_471 , V_472 - V_471 ,
L_179 ,
V_367 -> V_105 ,
V_367 -> V_104 ) ;
}
V_471 += F_132 ( V_471 , V_472 - V_471 , L_178 ) ;
}
V_80 = F_128 ( V_441 , V_210 , V_442 , V_447 , V_471 - V_447 ) ;
F_129 ( V_447 ) ;
return V_80 ;
}
static T_10 F_133 ( struct V_440 * V_440 ,
const char T_11 * V_441 ,
T_12 V_210 , T_13 * V_442 )
{
struct V_77 * V_98 = V_440 -> V_443 ;
memset ( V_98 -> V_103 , 0 , sizeof( V_98 -> V_103 ) ) ;
return V_210 ;
}
static void F_134 ( void * V_2 , void * V_319 , struct V_429 * V_477 )
{
struct V_77 * V_98 = V_319 ;
F_135 ( L_180 , V_478 | V_479 , V_477 ,
V_98 , & V_480 ) ;
F_135 ( L_181 , V_478 , V_477 ,
V_98 , & V_481 ) ;
F_135 ( L_182 , V_478 | V_479 , V_477 ,
V_98 , & V_482 ) ;
F_136 ( L_183 , V_478 | V_479 , V_477 ,
& V_98 -> V_338 ) ;
F_136 ( L_184 , V_478 | V_479 , V_477 ,
& V_98 -> V_143 . V_325 ) ;
}
static void F_137 ( void * V_2 , void * V_319 )
{
}
static void F_138 ( void * V_156 ,
struct V_157 * V_158 ,
struct V_400 * V_401 ,
struct V_3 * V_4 , void * V_319 )
{
}
int F_139 ( void )
{
return F_140 ( & V_483 ) ;
}
void F_141 ( void )
{
F_142 ( & V_483 ) ;
}
int F_143 ( struct V_1 * V_2 , struct V_318 * V_484 ,
bool V_485 )
{
struct V_165 * V_185 = & V_484 -> V_98 . V_185 ;
F_144 ( & V_2 -> V_486 ) ;
if ( V_485 ) {
if ( V_484 -> V_487 == 0 )
V_185 -> V_151 |= V_488 ;
V_484 -> V_487 ++ ;
} else {
V_484 -> V_487 -- ;
if ( V_484 -> V_487 == 0 )
V_185 -> V_151 &= ~ V_488 ;
}
return F_61 ( V_2 , V_185 , false ) ;
}
