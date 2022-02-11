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
struct V_1 * V_2 = V_98 -> V_143 ;
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
struct V_1 * V_2 = V_98 -> V_143 ;
if ( F_31 ( V_14 ) ) {
return;
} else if ( F_41 ( V_14 ) ) {
if ( V_98 -> V_119 == V_122 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
V_14 -> V_61 = V_144 ;
F_29 ( V_14 -> V_60 < V_27 ||
V_14 -> V_60 > V_145 ) ;
V_14 -> V_60 = V_146 [ V_14 -> V_60 ] ;
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
static inline bool F_51 ( struct V_13 * V_147 ,
struct V_13 * V_148 )
{
return ( V_147 -> type == V_148 -> type ) && ( V_147 -> V_39 == V_148 -> V_39 ) && ( V_147 -> V_62 == V_148 -> V_62 ) ;
}
static T_2 F_52 ( enum V_149 V_150 )
{
if ( V_150 & V_151 )
return V_152 ;
else if ( V_150 & V_153 )
return V_129 ;
else if ( V_150 & V_154 )
return V_128 ;
return V_144 ;
}
static void F_53 ( void * V_155 , struct V_156 * V_157 ,
struct V_3 * V_4 , void * V_158 ,
struct V_159 * V_160 )
{
int V_161 ;
int V_162 ;
int V_163 , V_71 ;
struct V_77 * V_98 = V_158 ;
struct V_164 * V_165 ;
struct V_166 * V_167 = (struct V_166 * ) V_160 -> V_65 ;
struct V_168 * V_169 = (struct V_168 * ) V_155 ;
struct V_1 * V_2 = F_54 ( V_169 ) ;
struct V_170 * V_171 = F_55 ( V_160 ) ;
enum V_149 V_172 ;
T_2 V_107 ;
struct V_13 V_14 ;
struct V_5 * V_173 , * V_174 , * V_175 ;
T_1 V_99 = ( V_176 ) V_171 -> V_177 . V_178 [ 0 ] ;
if ( ! V_98 ) {
F_15 ( V_2 , L_27 ) ;
return;
} else if ( ! V_98 -> V_143 ) {
F_15 ( V_2 , L_28 ) ;
return;
}
#ifdef F_56
if ( V_98 -> V_179 ) {
F_15 ( V_2 , L_29 ) ;
return;
}
#endif
if ( ! F_57 ( V_167 -> V_180 ) ||
V_171 -> V_150 & V_181 )
return;
if ( ( V_171 -> V_150 & V_182 ) &&
! ( V_171 -> V_150 & V_183 ) )
return;
V_165 = & V_98 -> V_184 ;
V_107 = F_58 ( V_165 -> V_185 [ 0 ] ) ;
F_38 ( V_107 , V_171 -> V_119 , & V_14 ) ;
if ( V_171 -> V_119 == V_122 )
V_14 . V_60 -= V_186 ;
V_172 = V_171 -> V_177 . V_187 [ 0 ] . V_150 ;
V_163 = V_171 -> V_177 . V_187 [ 0 ] . V_24 ;
if ( V_172 & V_188 ) {
V_163 &= V_26 ;
if ( V_163 >= ( V_28 - V_186 ) )
V_163 ++ ;
if ( V_171 -> V_119 == V_189 )
V_163 += V_186 ;
} else if ( V_172 & V_190 ) {
V_163 &= V_32 ;
if ( V_163 >= ( V_28 - V_186 ) )
V_163 ++ ;
}
if ( F_59 ( V_191 ,
( unsigned long ) ( V_98 -> V_192 + V_193 ) ) ) {
int V_79 ;
F_15 ( V_2 , L_30 ) ;
for ( V_79 = 0 ; V_79 < V_83 ; V_79 ++ )
F_23 ( V_4 , V_79 ) ;
F_60 ( V_2 , V_4 , V_157 -> V_119 , false ) ;
return;
}
V_98 -> V_192 = V_191 ;
if ( ( V_163 < 0 ) ||
( V_14 . V_62 != ! ! ( V_172 & V_194 ) ) ||
( V_14 . V_61 != F_52 ( V_172 ) ) ||
( V_14 . V_39 != V_171 -> V_177 . V_195 ) ||
( ! ! ( V_107 & V_25 ) !=
! ! ( V_172 & V_188 ) ) ||
( ! ! ( V_107 & V_31 ) !=
! ! ( V_172 & V_190 ) ) ||
( ! ! ( V_107 & V_196 ) !=
! ! ( V_172 & V_197 ) ) ||
( V_14 . V_60 != V_163 ) ) {
F_15 ( V_2 ,
L_31 ,
V_163 , V_14 . V_60 , V_107 ) ;
V_98 -> V_198 ++ ;
if ( V_98 -> V_198 > V_199 ) {
V_98 -> V_198 = 0 ;
F_15 ( V_2 ,
L_32 ,
V_98 -> V_200 ) ;
F_61 ( V_2 , & V_98 -> V_184 , false ) ;
}
return;
} else
V_98 -> V_198 = 0 ;
if ( F_51 ( & V_14 ,
& ( V_98 -> V_201 [ V_98 -> V_202 ] . V_14 ) ) ) {
V_173 = & ( V_98 -> V_201 [ V_98 -> V_202 ] ) ;
V_174 = & ( V_98 -> V_201 [ 1 - V_98 -> V_202 ] ) ;
} else if ( F_51 ( & V_14 ,
& V_98 -> V_201 [ 1 - V_98 -> V_202 ] . V_14 ) ) {
V_173 = & ( V_98 -> V_201 [ 1 - V_98 -> V_202 ] ) ;
V_174 = & ( V_98 -> V_201 [ V_98 -> V_202 ] ) ;
} else {
F_15 ( V_2 ,
L_33 ) ;
V_175 = & ( V_98 -> V_201 [ V_98 -> V_202 ] ) ;
F_14 ( V_2 , & V_175 -> V_14 , L_34 ) ;
V_175 = & ( V_98 -> V_201 [ 1 - V_98 -> V_202 ] ) ;
F_14 ( V_2 , & V_175 -> V_14 , L_35 ) ;
F_14 ( V_2 , & V_14 , L_36 ) ;
F_62 ( V_98 , true ) ;
goto V_203;
}
if ( V_171 -> V_150 & V_183 ) {
V_107 = F_58 ( V_165 -> V_185 [ 0 ] ) ;
F_38 ( V_107 , V_171 -> V_119 , & V_14 ) ;
F_28 ( V_98 , V_173 , V_14 . V_60 ,
V_171 -> V_177 . V_204 ,
V_171 -> V_177 . V_205 ,
V_99 ) ;
if ( V_98 -> V_200 == V_206 ) {
V_98 -> V_207 += V_171 -> V_177 . V_205 ;
V_98 -> V_208 += ( V_171 -> V_177 . V_204 -
V_171 -> V_177 . V_205 ) ;
}
} else {
V_162 = V_171 -> V_177 . V_187 [ 0 ] . V_209 - 1 ;
V_162 = F_63 ( V_162 , 15 ) ;
V_161 = ! ! ( V_171 -> V_150 & V_210 ) ;
for ( V_71 = 0 ; V_71 <= V_162 ; ++ V_71 ) {
V_107 = F_58 ( V_165 -> V_185 [ V_71 ] ) ;
F_38 ( V_107 , V_171 -> V_119 , & V_14 ) ;
if ( F_51 ( & V_14 , & V_173 -> V_14 ) )
V_175 = V_173 ;
else if ( F_51 ( & V_14 , & V_174 -> V_14 ) )
V_175 = V_174 ;
else
continue;
F_28 ( V_98 , V_175 , V_14 . V_60 , 1 ,
V_71 < V_162 ? 0 : V_161 ,
V_99 ) ;
}
if ( V_98 -> V_200 == V_206 ) {
V_98 -> V_207 += V_161 ;
V_98 -> V_208 += V_162 + ( 1 - V_161 ) ;
}
}
V_98 -> V_211 = V_107 ;
F_15 ( V_2 , L_37 , V_99 ) ;
V_203:
if ( V_4 && V_4 -> V_212 [ V_157 -> V_119 ] )
F_64 ( V_2 , V_160 , V_4 , V_98 ) ;
}
static void F_65 ( struct V_1 * V_2 , T_1 F_31 ,
struct V_77 * V_98 )
{
F_15 ( V_2 , L_38 ) ;
V_98 -> V_200 = V_206 ;
if ( F_31 ) {
V_98 -> V_213 = V_214 ;
V_98 -> V_215 = V_216 ;
V_98 -> V_217 = V_218 ;
} else {
V_98 -> V_213 = V_219 ;
V_98 -> V_215 = V_220 ;
V_98 -> V_217 = V_221 ;
}
V_98 -> V_222 = 0 ;
V_98 -> V_208 = 0 ;
V_98 -> V_207 = 0 ;
V_98 -> V_223 = V_191 ;
V_98 -> V_224 = 0 ;
}
static int F_66 ( struct V_77 * V_98 ,
const struct V_225 * V_101 )
{
switch ( V_101 -> V_226 ) {
case V_227 :
return V_98 -> V_228 ;
case V_229 :
return V_98 -> V_230 ;
case V_231 :
return V_98 -> V_232 ;
default:
F_29 ( 1 ) ;
}
return V_98 -> V_228 ;
}
static const T_5 * F_67 ( struct V_77 * V_98 ,
const struct V_225 * V_101 ,
T_2 V_61 )
{
const T_5 ( * V_233 ) [ V_72 ] ;
if ( F_29 ( V_101 -> V_226 != V_227 &&
V_101 -> V_226 != V_229 &&
V_101 -> V_226 != V_231 ) )
return V_234 ;
if ( V_101 -> V_226 == V_227 )
return V_234 ;
V_233 = V_235 ;
if ( V_101 -> V_226 == V_229 ) {
switch ( V_61 ) {
case V_144 :
V_233 = V_236 ;
break;
case V_152 :
V_233 = V_237 ;
break;
case V_129 :
V_233 = V_238 ;
break;
default:
F_29 ( 1 ) ;
}
} else if ( V_101 -> V_226 == V_231 ) {
switch ( V_61 ) {
case V_144 :
V_233 = V_235 ;
break;
case V_152 :
V_233 = V_239 ;
break;
case V_129 :
V_233 = V_240 ;
break;
default:
F_29 ( 1 ) ;
}
} else {
F_29 ( 1 ) ;
}
if ( ! V_101 -> V_62 && ! V_98 -> V_241 )
return V_233 [ 0 ] ;
else if ( V_101 -> V_62 && ! V_98 -> V_241 )
return V_233 [ 1 ] ;
else if ( ! V_101 -> V_62 && V_98 -> V_241 )
return V_233 [ 2 ] ;
else
return V_233 [ 3 ] ;
}
static void F_68 ( struct V_77 * V_98 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = & V_6 -> V_14 ;
const struct V_225 * V_101 = & V_242 [ V_6 -> V_101 ] ;
V_6 -> V_88 = F_67 ( V_98 , V_101 , V_14 -> V_61 ) ;
}
static T_3 F_69 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
struct V_5 * V_6 ,
unsigned long V_136 , T_6 V_60 )
{
struct V_5 * V_202 =
& ( V_98 -> V_201 [ V_98 -> V_202 ] ) ;
T_3 V_67 = V_202 -> V_73 [ V_60 ] . V_67 ;
T_5 V_243 = V_202 -> V_88 [ V_60 ] ;
const T_5 * V_244 = V_6 -> V_88 ;
T_5 V_142 ;
T_2 V_245 ;
int V_246 ;
if ( V_67 > V_247 ) {
V_245 = 100 * V_243 ;
F_15 ( V_2 ,
L_39 ,
V_67 , V_245 ) ;
} else {
V_245 = V_98 -> V_248 ;
F_15 ( V_2 ,
L_40 ,
V_67 , V_245 ) ;
}
V_246 = F_70 ( & V_136 , V_249 ) ;
while ( V_246 != V_38 ) {
if ( V_245 < ( 100 * V_244 [ V_246 ] ) )
break;
V_142 = F_43 ( V_2 , V_246 , V_136 ,
V_6 -> V_14 . type ) ;
V_246 = ( V_142 >> 8 ) & 0xff ;
}
F_15 ( V_2 , L_41 ,
V_246 , V_245 ,
V_246 != V_38 ?
100 * V_244 [ V_246 ] : V_68 ) ;
return V_246 ;
}
static T_2 F_71 ( struct V_3 * V_4 )
{
if ( V_4 -> V_250 >= V_251 )
return V_129 ;
else if ( V_4 -> V_250 >= V_252 )
return V_152 ;
return V_144 ;
}
static void F_62 ( struct V_77 * V_98 , bool V_253 )
{
struct V_5 * V_6 ;
int V_202 ;
int V_254 = 0 ;
struct V_1 * V_2 ;
V_2 = V_98 -> V_143 ;
V_202 = V_98 -> V_202 ;
V_6 = & ( V_98 -> V_201 [ V_202 ] ) ;
if ( V_98 -> V_200 == V_206 ) {
if ( V_98 -> V_223 )
V_254 =
F_59 ( V_191 ,
( unsigned long ) ( V_98 -> V_223 +
V_255 ) ) ;
if ( V_253 ||
( V_98 -> V_208 > V_98 -> V_215 ) ||
( V_98 -> V_207 > V_98 -> V_217 ) ||
( ( ! V_98 -> V_256 ) &&
( V_98 -> V_223 ) && ( V_254 ) ) ) {
F_15 ( V_2 ,
L_42 ,
V_98 -> V_208 ,
V_98 -> V_207 ,
V_254 ) ;
V_98 -> V_200 = V_257 ;
F_15 ( V_2 ,
L_43 ) ;
V_98 -> V_208 = 0 ;
V_98 -> V_207 = 0 ;
V_98 -> V_223 = 0 ;
V_98 -> V_224 = F_47 ( V_6 -> V_101 ) ;
} else {
V_98 -> V_222 ++ ;
if ( V_98 -> V_222 >=
V_98 -> V_213 ) {
V_98 -> V_222 = 0 ;
F_15 ( V_2 ,
L_44 ) ;
F_17 ( V_2 , V_6 ) ;
}
}
if ( V_98 -> V_200 == V_257 ) {
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
F_61 ( V_2 , & V_98 -> V_184 , false ) ;
}
static T_1 F_74 ( struct V_77 * V_78 ,
struct V_166 * V_167 )
{
T_1 V_79 = V_83 ;
if ( F_75 ( V_167 -> V_180 ) ) {
T_1 * V_258 = F_76 ( V_167 ) ;
V_79 = V_258 [ 0 ] & 0xf ;
}
if ( F_77 ( V_79 > V_83 ) )
V_79 = V_83 ;
return V_79 ;
}
static enum V_259 F_78 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_71 , V_260 , V_261 ;
enum V_259 V_262 ;
const struct V_225 * V_263 = & V_242 [ V_6 -> V_101 ] ;
const struct V_225 * V_264 ;
T_7 V_265 ;
T_1 V_266 = V_2 -> V_11 -> V_12 ;
const T_5 * V_267 ;
T_5 V_95 , V_268 ;
for ( V_71 = 0 ; V_71 < V_269 ; V_71 ++ ) {
V_262 = V_263 -> V_270 [ V_71 ] ;
if ( V_262 == V_102 )
continue;
if ( V_98 -> V_224 & F_47 ( V_262 ) ) {
F_15 ( V_2 , L_45 ,
V_262 ) ;
continue;
}
V_264 = & V_242 [ V_262 ] ;
if ( ! F_18 ( V_266 , V_264 -> V_39 ) ) {
F_15 ( V_2 ,
L_46 ,
V_262 , V_266 , V_264 -> V_39 ) ;
continue;
}
for ( V_260 = 0 ; V_260 < V_271 ; V_260 ++ ) {
V_265 = V_264 -> V_272 [ V_260 ] ;
if ( V_265 && ! V_265 ( V_2 , V_4 , V_6 ) )
break;
}
if ( V_260 != V_271 ) {
F_15 ( V_2 ,
L_47 ,
V_262 , V_260 ) ;
continue;
}
V_95 = V_98 -> V_248 / 100 ;
V_267 = F_67 ( V_98 , V_264 ,
F_71 ( V_4 ) ) ;
if ( F_29 ( ! V_267 ) )
continue;
V_261 = F_66 ( V_98 , V_264 ) ;
if ( F_29 ( V_261 == V_38 ) )
continue;
V_268 = V_267 [ V_261 ] ;
if ( V_95 >= V_268 ) {
F_15 ( V_2 ,
L_48 ,
V_262 , V_268 , V_95 ) ;
continue;
}
F_15 ( V_2 ,
L_49 ,
V_262 , V_268 , V_95 ) ;
break;
}
if ( V_71 == V_269 )
return V_102 ;
return V_262 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
struct V_3 * V_4 ,
enum V_259 V_273 )
{
struct V_5 * V_6 = & ( V_98 -> V_201 [ V_98 -> V_202 ] ) ;
struct V_5 * V_274 =
& ( V_98 -> V_201 [ ( 1 - V_98 -> V_202 ) ] ) ;
struct V_13 * V_14 = & V_274 -> V_14 ;
const struct V_225 * V_101 = & V_242 [ V_273 ] ;
const struct V_225 * V_275 = & V_242 [ V_6 -> V_101 ] ;
T_2 V_276 = ( sizeof( struct V_5 ) -
( sizeof( struct V_63 ) * V_72 ) ) ;
unsigned long V_136 = 0 ;
T_2 V_246 = 0 ;
memcpy ( V_274 , V_6 , V_276 ) ;
V_14 -> V_62 = V_101 -> V_62 ;
V_14 -> V_39 = V_101 -> V_39 ;
if ( V_101 -> V_226 == V_227 ) {
if ( V_98 -> V_119 == V_122 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
V_136 = V_98 -> V_133 ;
} else if ( V_101 -> V_226 == V_229 ) {
V_14 -> type = V_98 -> F_35 ? V_56 : V_54 ;
V_136 = V_98 -> V_134 ;
} else if ( V_101 -> V_226 == V_231 ) {
V_14 -> type = V_98 -> F_35 ? V_57 : V_55 ;
V_136 = V_98 -> V_135 ;
} else {
F_29 ( L_50 ) ;
}
V_14 -> V_61 = F_71 ( V_4 ) ;
V_274 -> V_101 = V_273 ;
F_68 ( V_98 , V_274 ) ;
V_98 -> V_224 |= F_47 ( V_273 ) ;
if ( V_275 -> V_226 != V_101 -> V_226 ) {
V_246 = F_69 ( V_2 , V_98 , V_274 ,
V_136 , V_14 -> V_60 ) ;
if ( ( V_246 == V_38 ) ||
! ( F_47 ( V_246 ) & V_136 ) ) {
F_15 ( V_2 ,
L_51
L_52 ,
V_246 , V_136 ) ;
goto V_277;
}
V_14 -> V_60 = V_246 ;
}
F_15 ( V_2 , L_53 ,
V_273 , V_14 -> V_60 ) ;
return 0 ;
V_277:
V_14 -> type = V_51 ;
return - 1 ;
}
static enum V_278 F_80 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_3 V_279 , int V_139 , int V_138 ,
int V_280 ,
int V_281 , int V_282 )
{
enum V_278 V_283 = V_284 ;
if ( ( V_279 <= V_285 ) || ( V_280 == 0 ) ) {
F_15 ( V_2 ,
L_54 ) ;
return V_286 ;
}
if ( ( V_281 == V_68 ) &&
( V_282 == V_68 ) &&
( V_138 != V_38 ) ) {
F_15 ( V_2 ,
L_55 ) ;
return V_287 ;
}
if ( ( V_282 == V_68 ) &&
( V_138 != V_38 ) &&
( V_281 != V_68 ) &&
( V_281 < V_280 ) ) {
F_15 ( V_2 ,
L_56 ) ;
return V_287 ;
}
if ( ( V_282 != V_68 ) &&
( V_282 > V_280 ) ) {
F_15 ( V_2 ,
L_57 ) ;
return V_287 ;
}
if ( ( V_281 != V_68 ) &&
( V_282 != V_68 ) &&
( V_281 < V_280 ) &&
( V_282 < V_280 ) ) {
F_15 ( V_2 ,
L_58 ) ;
return V_284 ;
}
if ( ( V_281 != V_68 ) &&
( V_281 > V_280 ) ) {
F_15 ( V_2 ,
L_59 ) ;
V_283 = V_286 ;
goto V_288;
}
if ( ( V_281 == V_68 ) &&
( V_139 != V_38 ) ) {
F_15 ( V_2 ,
L_60 ) ;
V_283 = V_286 ;
goto V_288;
}
F_15 ( V_2 , L_61 ) ;
V_288:
if ( ( V_283 == V_286 ) && ( V_139 != V_38 ) ) {
if ( V_279 >= V_247 ) {
F_15 ( V_2 ,
L_62 ) ;
V_283 = V_284 ;
} else if ( V_280 > ( 100 * V_6 -> V_88 [ V_139 ] ) ) {
F_15 ( V_2 ,
L_63 ) ;
V_283 = V_284 ;
} else {
F_15 ( V_2 , L_64 ) ;
}
}
return V_283 ;
}
static void F_81 ( struct V_1 * V_2 , int V_60 ,
int * V_289 , int * V_290 )
{
* V_289 = V_60 + V_291 ;
if ( * V_289 > V_106 )
* V_289 = V_292 ;
* V_290 = V_60 - V_291 ;
if ( * V_290 < 0 )
* V_290 = V_292 ;
}
static bool F_82 ( struct V_1 * V_2 , struct V_293 * V_294 ,
struct V_13 * V_14 , enum V_118 V_119 )
{
int V_60 = V_14 -> V_60 ;
bool V_295 = ( V_296 . V_297 == V_298 ) ;
bool V_299 = ( V_294 -> type == V_300 &&
! V_294 -> V_301 . V_302 ) ;
F_15 ( V_2 , L_65 ,
V_295 , V_299 ) ;
if ( ( V_295 || V_299 ) &&
! F_83 ( V_2 , V_119 ) )
return false ;
F_15 ( V_2 , L_66 , V_14 -> type ) ;
if ( F_31 ( V_14 ) )
return V_60 == V_303 ;
if ( F_32 ( V_14 ) )
return V_60 == V_304 ;
if ( F_35 ( V_14 ) )
return V_60 == V_304 ||
V_60 == V_305 ||
V_60 == V_145 ;
F_29 ( 1 ) ;
return false ;
}
static enum V_306 F_84 ( struct V_1 * V_2 ,
T_3 V_279 , int V_307 , int V_308 ,
int V_280 ,
int V_309 , int V_310 )
{
if ( V_280 == V_68 ) {
F_15 ( V_2 , L_67 ) ;
return V_311 ;
}
if ( V_279 <= V_312 || V_280 == 0 ) {
F_15 ( V_2 , L_68 ) ;
return V_313 ;
}
if ( V_307 != V_292 ) {
if ( V_309 == V_68 &&
( V_310 == V_68 ||
V_280 >= V_310 ) ) {
F_15 ( V_2 ,
L_69 ) ;
return V_314 ;
}
if ( V_309 > V_280 ) {
F_15 ( V_2 ,
L_70 ) ;
return V_314 ;
}
}
if ( V_279 < V_315 && V_308 != V_292 ) {
if ( V_309 == V_68 &&
V_310 != V_68 &&
V_280 < V_310 ) {
F_15 ( V_2 ,
L_71 ) ;
return V_316 ;
}
if ( V_309 < V_280 &&
( V_310 == V_68 ||
V_310 > V_280 ) ) {
F_15 ( V_2 ,
L_72 ) ;
return V_316 ;
}
}
F_15 ( V_2 , L_73 ) ;
return V_311 ;
}
static bool F_85 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_77 * V_98 ,
struct V_5 * V_6 )
{
struct V_317 * V_318 = ( void * ) V_4 -> V_319 ;
struct V_293 * V_294 = V_318 -> V_294 ;
struct V_320 * V_321 ;
enum V_118 V_119 ;
struct V_63 * V_64 ;
struct V_13 * V_14 = & V_6 -> V_14 ;
enum V_306 V_283 ;
T_3 V_279 ;
T_1 V_322 = V_98 -> V_184 . V_323 ;
int V_280 ;
int V_307 , V_308 ;
int V_309 = V_68 , V_310 = V_68 ;
#ifdef F_56
if ( V_98 -> V_324 <= V_106 ) {
F_15 ( V_2 , L_74 ,
V_98 -> V_324 ) ;
V_98 -> V_184 . V_323 = V_98 -> V_324 ;
return V_322 != V_98 -> V_324 ;
}
#endif
F_86 () ;
V_321 = F_87 ( V_294 -> V_321 ) ;
if ( F_88 ( ! V_321 ) )
V_119 = V_325 ;
else
V_119 = V_321 -> V_326 . V_327 -> V_119 ;
F_89 () ;
if ( ! F_82 ( V_2 , V_294 , V_14 , V_119 ) ) {
F_15 ( V_2 ,
L_75 ) ;
V_98 -> V_184 . V_323 = V_328 ;
return V_322 != V_328 ;
}
F_81 ( V_2 , V_322 , & V_307 , & V_308 ) ;
V_64 = V_6 -> V_74 ;
V_279 = V_64 [ V_322 ] . V_67 ;
V_280 = V_64 [ V_322 ] . V_70 ;
if ( V_307 != V_292 )
V_309 = V_64 [ V_307 ] . V_70 ;
if ( V_308 != V_292 )
V_310 = V_64 [ V_308 ] . V_70 ;
F_15 ( V_2 ,
L_76 ,
V_322 , V_280 , V_279 , V_307 , V_308 ,
V_309 , V_310 ) ;
V_283 = F_84 ( V_2 , V_279 , V_307 , V_308 ,
V_280 , V_309 , V_310 ) ;
if ( V_307 == V_292 && V_283 == V_314 ) {
F_15 ( V_2 , L_77 ) ;
V_283 = V_311 ;
} else if ( V_308 == V_292 &&
( V_283 == V_316 ||
V_283 == V_313 ) ) {
F_15 ( V_2 , L_78 ) ;
V_283 = V_311 ;
}
switch ( V_283 ) {
case V_314 :
V_98 -> V_184 . V_323 = V_307 ;
return true ;
case V_316 :
V_98 -> V_184 . V_323 = V_308 ;
return true ;
case V_313 :
V_98 -> V_184 . V_323 = V_328 ;
return true ;
case V_311 :
break;
}
return false ;
}
static void F_64 ( struct V_1 * V_2 ,
struct V_159 * V_160 ,
struct V_3 * V_4 ,
struct V_77 * V_98 )
{
struct V_170 * V_171 = F_55 ( V_160 ) ;
struct V_166 * V_167 = (struct V_166 * ) V_160 -> V_65 ;
int V_139 = V_38 ;
int V_138 = V_38 ;
int V_60 ;
struct V_63 * V_64 = NULL ;
int V_280 = V_68 ;
int V_281 = V_68 ;
int V_282 = V_68 ;
T_2 V_94 ;
enum V_278 V_329 = V_284 ;
T_5 V_136 ;
T_1 V_330 = 0 ;
struct V_5 * V_6 , * V_331 ;
T_1 V_202 = 0 ;
T_1 V_332 = 0 ;
T_5 V_142 ;
T_3 V_279 ;
T_1 V_79 = V_83 ;
T_1 V_333 = V_98 -> V_241 ;
struct V_317 * V_334 = ( void * ) V_4 -> V_319 ;
struct V_335 * V_336 ;
struct V_13 * V_14 ;
if ( ! F_57 ( V_167 -> V_180 ) ||
V_171 -> V_150 & V_181 )
return;
V_79 = F_74 ( V_98 , V_167 ) ;
if ( ( V_79 != V_83 ) &&
( V_98 -> V_337 & ( 1 << V_79 ) ) ) {
V_336 = & V_334 -> V_336 [ V_79 ] ;
if ( V_336 -> V_338 == V_339 )
V_98 -> V_241 = 0 ;
else
V_98 -> V_241 = 1 ;
} else {
V_98 -> V_241 = 0 ;
}
if ( ! V_98 -> V_256 )
V_202 = V_98 -> V_202 ;
else
V_202 = 1 - V_98 -> V_202 ;
V_6 = & ( V_98 -> V_201 [ V_202 ] ) ;
V_14 = & V_6 -> V_14 ;
if ( V_333 != V_98 -> V_241 ) {
F_15 ( V_2 ,
L_79 ,
V_333 , V_98 -> V_241 ) ;
F_68 ( V_98 , V_6 ) ;
F_17 ( V_2 , V_6 ) ;
}
V_60 = V_98 -> V_340 ;
V_136 = F_40 ( V_98 , V_14 ) ;
if ( ! ( F_47 ( V_60 ) & V_136 ) ) {
F_22 ( V_2 , L_80 ) ;
if ( V_98 -> V_256 ) {
V_14 -> type = V_51 ;
V_98 -> V_256 = 0 ;
V_6 = & ( V_98 -> V_201 [ V_98 -> V_202 ] ) ;
F_72 ( V_2 , V_4 , V_98 , & V_6 -> V_14 ) ;
}
return;
}
if ( ! V_6 -> V_88 ) {
F_22 ( V_2 , L_81 ) ;
return;
}
if ( ( V_98 -> V_341 != - 1 ) &&
( V_98 -> V_341 < V_60 ) ) {
V_60 = V_98 -> V_341 ;
V_330 = 1 ;
V_64 = & ( V_6 -> V_73 [ V_60 ] ) ;
F_15 ( V_2 ,
L_82 ,
V_60 ) ;
goto V_342;
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
goto V_288;
}
if ( V_64 -> V_70 != ( ( V_64 -> V_67 *
V_6 -> V_88 [ V_60 ] + 64 ) / 128 ) ) {
V_64 -> V_70 = ( ( V_64 -> V_67 *
V_6 -> V_88 [ V_60 ] + 64 ) / 128 ) ;
}
if ( V_98 -> V_256 ) {
if ( V_64 -> V_70 > V_98 -> V_248 ) {
F_15 ( V_2 ,
L_84
L_85 ,
V_64 -> V_67 ,
V_64 -> V_70 ,
V_98 -> V_248 ) ;
V_98 -> V_202 = V_202 ;
V_280 = V_64 -> V_70 ;
} else {
F_15 ( V_2 ,
L_86
L_85 ,
V_64 -> V_67 ,
V_64 -> V_70 ,
V_98 -> V_248 ) ;
V_14 -> type = V_51 ;
V_202 = V_98 -> V_202 ;
V_6 = & ( V_98 -> V_201 [ V_202 ] ) ;
V_60 = V_6 -> V_14 . V_60 ;
V_280 = V_98 -> V_248 ;
V_330 = 1 ;
}
V_98 -> V_256 = 0 ;
V_332 = 1 ;
goto V_342;
}
V_142 = F_43 ( V_2 , V_60 , V_136 , V_14 -> type ) ;
V_139 = V_142 & 0xff ;
V_138 = ( V_142 >> 8 ) & 0xff ;
if ( ( V_98 -> V_341 != - 1 ) &&
( V_98 -> V_341 < V_138 ) )
V_138 = V_38 ;
V_279 = V_64 -> V_67 ;
V_280 = V_64 -> V_70 ;
if ( V_139 != V_38 )
V_281 = V_6 -> V_73 [ V_139 ] . V_70 ;
if ( V_138 != V_38 )
V_282 = V_6 -> V_73 [ V_138 ] . V_70 ;
F_15 ( V_2 ,
L_87 ,
F_13 ( V_14 -> type ) , V_60 , V_280 , V_279 ,
V_139 , V_138 , V_281 , V_282 ) ;
V_329 = F_80 ( V_2 , V_6 , V_279 , V_139 , V_138 ,
V_280 , V_281 , V_282 ) ;
if ( F_90 ( V_14 ) &&
! F_3 ( V_2 , V_4 ) ) {
F_15 ( V_2 ,
L_88 ) ;
F_62 ( V_98 , true ) ;
goto V_342;
}
switch ( V_329 ) {
case V_286 :
if ( V_139 != V_38 ) {
V_330 = 1 ;
V_60 = V_139 ;
} else {
F_15 ( V_2 ,
L_89 ) ;
}
break;
case V_287 :
if ( V_138 != V_38 ) {
V_330 = 1 ;
V_60 = V_138 ;
} else {
F_15 ( V_2 ,
L_90 ) ;
}
break;
case V_284 :
if ( V_98 -> V_200 == V_206 )
V_330 = F_85 ( V_2 , V_4 , V_98 , V_6 ) ;
break;
default:
break;
}
V_342:
if ( V_330 ) {
V_6 -> V_14 . V_60 = V_60 ;
F_72 ( V_2 , V_4 , V_98 , & V_6 -> V_14 ) ;
}
F_62 ( V_98 , false ) ;
if ( ! V_330 && ! V_332 &&
V_98 -> V_200 == V_257
&& V_64 -> V_69 ) {
enum V_259 V_343 ;
V_98 -> V_248 = V_280 ;
F_15 ( V_2 ,
L_91 ,
V_330 , V_332 , V_98 -> V_200 ,
V_64 -> V_69 ) ;
V_343 = F_78 ( V_2 , V_98 , V_4 , V_6 ) ;
if ( V_343 != V_102 ) {
int V_80 = F_79 ( V_2 , V_98 , V_4 ,
V_343 ) ;
if ( ! V_80 )
V_98 -> V_256 = 1 ;
} else {
F_15 ( V_2 ,
L_92 ) ;
V_98 -> V_200 = V_344 ;
}
if ( V_98 -> V_256 ) {
V_6 = & ( V_98 -> V_201 [ ( 1 - V_98 -> V_202 ) ] ) ;
F_17 ( V_2 , V_6 ) ;
V_60 = V_6 -> V_14 . V_60 ;
F_14 ( V_2 , & V_6 -> V_14 ,
L_93 ) ;
F_73 ( V_2 , V_4 , V_98 , & V_6 -> V_14 ) ;
F_61 ( V_2 , & V_98 -> V_184 , false ) ;
} else {
V_332 = 1 ;
}
}
if ( V_332 && V_98 -> V_200 == V_344 ) {
V_331 = & ( V_98 -> V_201 [ V_98 -> V_202 ] ) ;
if ( F_31 ( & V_331 -> V_14 ) ) {
F_15 ( V_2 , L_94 ) ;
if ( V_79 != V_83 ) {
V_336 = & V_334 -> V_336 [ V_79 ] ;
if ( V_336 -> V_338 != V_339 ) {
F_15 ( V_2 ,
L_95 ,
V_79 ) ;
F_23 ( V_4 , V_79 ) ;
}
}
F_65 ( V_2 , 1 , V_98 ) ;
} else {
if ( ( V_98 -> V_248 > V_345 ) &&
( V_98 -> V_337 & ( 1 << V_79 ) ) &&
( V_79 != V_83 ) ) {
V_336 = & V_334 -> V_336 [ V_79 ] ;
if ( V_336 -> V_338 == V_339 ) {
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
V_288:
V_98 -> V_340 = V_60 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_77 * V_98 ,
enum V_118 V_119 ,
bool V_346 )
{
struct V_5 * V_6 ;
struct V_13 * V_14 ;
int V_71 ;
T_1 V_202 = 0 ;
T_1 V_12 ;
if ( ! V_4 || ! V_98 )
return;
V_71 = V_98 -> V_340 ;
V_12 = V_2 -> V_11 -> V_12 ;
if ( ! V_98 -> V_256 )
V_202 = V_98 -> V_202 ;
else
V_202 = 1 - V_98 -> V_202 ;
V_6 = & ( V_98 -> V_201 [ V_202 ] ) ;
V_14 = & V_6 -> V_14 ;
if ( ( V_71 < 0 ) || ( V_71 >= V_72 ) )
V_71 = 0 ;
V_14 -> V_60 = V_71 ;
V_14 -> V_39 = F_50 ( V_12 ) ;
V_14 -> V_62 = false ;
V_14 -> V_61 = V_144 ;
if ( V_119 == V_122 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
F_29 ( V_14 -> V_39 != V_42 && V_14 -> V_39 != V_43 ) ;
if ( V_14 -> V_39 == V_42 )
V_6 -> V_101 = V_347 ;
else
V_6 -> V_101 = V_348 ;
F_68 ( V_98 , V_6 ) ;
F_73 ( V_2 , V_4 , V_98 , V_14 ) ;
F_61 ( V_2 , & V_98 -> V_184 , V_346 ) ;
}
static void F_92 ( void * V_155 , struct V_3 * V_4 , void * V_318 ,
struct V_349 * V_350 )
{
struct V_159 * V_160 = V_350 -> V_160 ;
struct V_156 * V_157 = V_350 -> V_157 ;
struct V_168 * V_169 V_351 =
(struct V_168 * ) V_155 ;
struct V_1 * V_2 V_351 = F_54 ( V_169 ) ;
struct V_170 * V_171 = F_55 ( V_160 ) ;
struct V_77 * V_98 = V_318 ;
if ( V_98 ) {
V_98 -> V_341 = V_350 -> V_341 ;
if ( ( V_157 -> V_119 == V_122 ) &&
( V_98 -> V_341 != - 1 ) )
V_98 -> V_341 += V_186 ;
if ( ( V_98 -> V_341 < 0 ) ||
( V_98 -> V_341 >= V_72 ) )
V_98 -> V_341 = - 1 ;
}
if ( V_98 && ! V_98 -> V_143 ) {
F_15 ( V_2 , L_28 ) ;
V_318 = NULL ;
}
if ( F_93 ( V_4 , V_318 , V_350 ) )
return;
F_94 ( V_98 -> V_211 ,
V_171 -> V_119 , & V_171 -> V_352 . V_187 [ 0 ] ) ;
V_171 -> V_352 . V_187 [ 0 ] . V_209 = 1 ;
}
static void * F_95 ( void * V_353 , struct V_3 * V_4 ,
T_8 V_354 )
{
struct V_317 * V_334 = (struct V_317 * ) V_4 -> V_319 ;
struct V_168 * V_169 V_351 =
(struct V_168 * ) V_353 ;
struct V_1 * V_2 V_351 = F_54 ( V_169 ) ;
F_15 ( V_2 , L_97 ) ;
return & V_334 -> V_98 ;
}
static int F_96 ( struct V_16 * V_17 ,
int V_121 )
{
T_5 V_355 = F_97 ( V_17 -> V_356 . V_357 ) &
( 0x3 << ( 2 * ( V_121 - 1 ) ) ) ;
V_355 >>= ( 2 * ( V_121 - 1 ) ) ;
if ( V_355 == V_358 )
return V_304 ;
else if ( V_355 == V_359 )
return V_305 ;
else if ( V_355 == V_360 )
return V_145 ;
F_29 ( V_355 != V_361 ) ;
return - 1 ;
}
static void F_98 ( struct V_3 * V_4 ,
struct V_16 * V_17 ,
struct V_77 * V_98 )
{
int V_71 ;
int V_362 = F_96 ( V_17 , 1 ) ;
if ( V_362 >= V_27 ) {
for ( V_71 = V_27 ; V_71 <= V_362 ; V_71 ++ ) {
if ( V_71 == V_28 )
continue;
if ( V_71 == V_145 &&
V_4 -> V_250 == V_363 )
continue;
V_98 -> V_134 |= F_47 ( V_71 ) ;
}
}
if ( V_4 -> V_364 < 2 )
return;
V_362 = F_96 ( V_17 , 2 ) ;
if ( V_362 >= V_27 ) {
for ( V_71 = V_27 ; V_71 <= V_362 ; V_71 ++ ) {
if ( V_71 == V_28 )
continue;
if ( V_71 == V_145 &&
V_4 -> V_250 == V_363 )
continue;
V_98 -> V_135 |= F_47 ( V_71 ) ;
}
}
}
static void F_99 ( struct V_1 * V_2 ,
struct V_365 * V_366 )
{
F_100 ( & V_2 -> V_367 ) ;
memset ( V_366 , 0 , sizeof( * V_366 ) ) ;
F_101 ( & V_2 -> V_367 ) ;
}
void F_102 ( struct V_1 * V_2 ,
struct V_365 * V_366 ,
T_2 V_14 , bool V_368 )
{
T_1 V_121 = 0 , V_369 = 0 ;
F_103 ( & V_2 -> V_367 ) ;
if ( V_368 )
V_366 -> V_370 ++ ;
V_366 -> V_371 ++ ;
switch ( V_14 & V_123 ) {
case V_144 :
V_366 -> V_372 ++ ;
break;
case V_152 :
V_366 -> V_373 ++ ;
break;
case V_129 :
V_366 -> V_374 ++ ;
break;
default:
F_104 ( 1 , L_98 , V_14 ) ;
}
if ( V_14 & V_25 ) {
V_366 -> V_375 ++ ;
V_369 = V_14 & V_26 ;
V_121 = ( ( V_14 & V_124 ) >> V_125 ) + 1 ;
} else if ( V_14 & V_31 ) {
V_366 -> V_376 ++ ;
V_369 = V_14 & V_32 ;
V_121 = ( ( V_14 & V_126 ) >>
V_127 ) + 1 ;
} else {
V_366 -> V_377 ++ ;
}
if ( V_121 == 1 )
V_366 -> V_378 ++ ;
else if ( V_121 == 2 )
V_366 -> V_379 ++ ;
if ( V_14 & V_117 )
V_366 -> V_380 ++ ;
else
V_366 -> V_381 ++ ;
V_366 -> V_382 [ V_366 -> V_383 ] = V_14 ;
V_366 -> V_383 = ( V_366 -> V_383 + 1 ) %
F_11 ( V_366 -> V_382 ) ;
F_105 ( & V_2 -> V_367 ) ;
}
void F_60 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_118 V_119 , bool V_346 )
{
int V_71 , V_260 ;
struct V_384 * V_385 = V_2 -> V_385 ;
struct V_15 * V_7 = & V_4 -> V_7 ;
struct V_16 * V_17 = & V_4 -> V_17 ;
struct V_317 * V_334 ;
struct V_77 * V_98 ;
struct V_156 * V_157 ;
unsigned long V_386 ;
V_334 = (struct V_317 * ) V_4 -> V_319 ;
V_98 = & V_334 -> V_98 ;
memset ( V_98 , 0 , sizeof( * V_98 ) ) ;
V_157 = V_385 -> V_387 -> V_388 [ V_119 ] ;
V_98 -> V_184 . V_389 = V_334 -> V_389 ;
for ( V_260 = 0 ; V_260 < V_390 ; V_260 ++ )
F_17 ( V_2 , & V_98 -> V_201 [ V_260 ] ) ;
V_98 -> V_223 = 0 ;
V_98 -> V_192 = V_191 ;
F_15 ( V_2 ,
L_99 ,
V_334 -> V_389 ) ;
V_98 -> V_341 = - 1 ;
V_98 -> V_198 = V_199 ;
V_98 -> V_119 = V_157 -> V_119 ;
V_386 = V_4 -> V_212 [ V_157 -> V_119 ] ;
V_98 -> V_133 = 0 ;
F_106 (i, &supp, BITS_PER_LONG)
V_98 -> V_133 |= F_47 ( V_157 -> V_391 [ V_71 ] . V_392 ) ;
if ( ! V_17 || ! V_17 -> V_393 ) {
V_98 -> V_134 = V_7 -> V_369 . V_394 [ 0 ] << 1 ;
V_98 -> V_134 |= V_7 -> V_369 . V_394 [ 0 ] & 0x1 ;
V_98 -> V_134 &= ~ ( ( T_5 ) 0x2 ) ;
V_98 -> V_134 <<= V_186 ;
V_98 -> V_135 = V_7 -> V_369 . V_394 [ 1 ] << 1 ;
V_98 -> V_135 |= V_7 -> V_369 . V_394 [ 1 ] & 0x1 ;
V_98 -> V_135 &= ~ ( ( T_5 ) 0x2 ) ;
V_98 -> V_135 <<= V_186 ;
V_98 -> F_35 = false ;
} else {
F_98 ( V_4 , V_17 , V_98 ) ;
V_98 -> F_35 = true ;
}
V_98 -> V_228 = F_107 ( & V_98 -> V_133 ,
V_249 ) ;
V_98 -> V_230 = F_107 ( & V_98 -> V_134 ,
V_249 ) ;
V_98 -> V_232 = F_107 ( & V_98 -> V_135 ,
V_249 ) ;
F_15 ( V_2 , L_100 ,
V_98 -> V_133 ,
V_98 -> V_134 ,
V_98 -> V_135 ,
V_98 -> F_35 ) ;
F_15 ( V_2 , L_101 ,
V_98 -> V_228 ,
V_98 -> V_230 ,
V_98 -> V_232 ) ;
V_98 -> V_184 . V_395 =
F_50 ( V_2 -> V_11 -> V_12 ) ;
V_98 -> V_184 . V_396 = V_44 ;
V_98 -> V_337 = V_397 ;
V_98 -> V_143 = V_2 ;
V_98 -> V_340 = F_108 ( V_157 , V_4 ) ;
if ( V_157 -> V_119 == V_122 )
V_98 -> V_340 += V_186 ;
V_98 -> V_241 = 0 ;
#ifdef F_56
V_98 -> V_179 = 0 ;
V_98 -> V_324 = V_292 ;
#endif
#ifdef F_109
F_99 ( V_2 , & V_2 -> V_398 ) ;
#endif
F_91 ( V_2 , V_4 , V_98 , V_119 , V_346 ) ;
}
static void F_110 ( void * V_155 ,
struct V_156 * V_157 ,
struct V_399 * V_400 ,
struct V_3 * V_4 , void * V_158 ,
T_2 V_401 )
{
T_1 V_79 ;
struct V_168 * V_169 =
(struct V_168 * ) V_155 ;
struct V_1 * V_2 = F_54 ( V_169 ) ;
for ( V_79 = 0 ; V_79 < V_83 ; V_79 ++ )
F_23 ( V_4 , V_79 ) ;
F_60 ( V_2 , V_4 , V_157 -> V_119 , false ) ;
}
static void F_111 ( struct V_1 * V_2 ,
struct V_164 * V_402 ,
enum V_118 V_119 ,
T_2 V_107 )
{
struct V_13 V_14 ;
int V_71 ;
int V_403 = F_11 ( V_402 -> V_185 ) ;
T_9 V_404 = F_112 ( V_107 ) ;
for ( V_71 = 0 ; V_71 < V_403 ; V_71 ++ )
V_402 -> V_185 [ V_71 ] = V_404 ;
F_38 ( V_107 , V_119 , & V_14 ) ;
if ( F_90 ( & V_14 ) )
V_402 -> V_405 = V_403 - 1 ;
else
V_402 -> V_405 = 0 ;
}
static void F_113 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
struct V_13 * V_14 ,
T_9 * V_185 , int * V_406 ,
int V_403 , int V_407 ,
T_1 V_12 , bool V_408 )
{
int V_71 , V_260 ;
T_9 V_107 ;
bool V_409 = false ;
int V_410 = V_14 -> V_60 ;
int V_411 = V_412 ;
int V_60 = * V_406 ;
for ( V_71 = 0 ; V_71 < V_403 && V_60 < V_411 ; V_71 ++ ) {
V_107 = F_112 ( F_30 ( V_2 , V_14 ) ) ;
for ( V_260 = 0 ; V_260 < V_407 && V_60 < V_411 ; V_260 ++ , V_60 ++ )
V_185 [ V_60 ] = V_107 ;
if ( V_408 )
F_39 ( V_12 , V_14 ) ;
V_410 = V_14 -> V_60 ;
V_409 = F_48 ( V_98 , V_14 ) ;
if ( V_409 && ! F_31 ( V_14 ) )
break;
}
if ( ! V_409 )
V_14 -> V_60 = V_410 ;
* V_406 = V_60 ;
}
static void F_114 ( struct V_1 * V_2 ,
struct V_77 * V_98 ,
const struct V_13 * V_413 )
{
struct V_13 V_14 ;
int V_403 , V_407 , V_60 = 0 ;
T_1 V_12 = 0 ;
struct V_164 * V_402 = & V_98 -> V_184 ;
bool V_408 = false ;
memcpy ( & V_14 , V_413 , sizeof( V_14 ) ) ;
V_12 = V_2 -> V_11 -> V_12 ;
if ( F_41 ( & V_14 ) ) {
V_403 = V_414 ;
V_407 = V_415 ;
} else if ( F_90 ( & V_14 ) ) {
V_403 = V_416 ;
V_407 = V_415 ;
} else {
V_403 = V_417 ;
V_407 = V_418 ;
V_408 = true ;
}
F_113 ( V_2 , V_98 , & V_14 , V_402 -> V_185 , & V_60 ,
V_403 , V_407 , V_12 ,
V_408 ) ;
F_49 ( V_98 , & V_14 ) ;
if ( F_41 ( & V_14 ) ) {
V_403 = V_419 ;
V_407 = V_420 ;
V_402 -> V_405 = V_60 ;
} else if ( F_31 ( & V_14 ) ) {
V_403 = V_421 ;
V_407 = V_418 ;
} else {
F_29 ( 1 ) ;
}
V_408 = true ;
F_113 ( V_2 , V_98 , & V_14 , V_402 -> V_185 , & V_60 ,
V_403 , V_407 , V_12 ,
V_408 ) ;
F_49 ( V_98 , & V_14 ) ;
V_403 = V_421 ;
V_407 = V_418 ;
F_113 ( V_2 , V_98 , & V_14 , V_402 -> V_185 , & V_60 ,
V_403 , V_407 , V_12 ,
V_408 ) ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_77 * V_98 ,
const struct V_13 * V_413 )
{
struct V_164 * V_402 = & V_98 -> V_184 ;
T_1 V_39 = V_413 -> V_39 ;
#ifdef F_56
if ( V_98 -> V_179 ) {
F_111 ( V_2 , V_402 ,
V_98 -> V_119 ,
V_98 -> V_179 ) ;
V_402 -> V_323 = 0 ;
V_39 = ( V_98 -> V_179 & V_109 ) >>
V_108 ;
} else
#endif
F_114 ( V_2 , V_98 , V_413 ) ;
if ( F_2 ( V_39 ) == 1 )
V_402 -> V_395 = V_39 ;
V_402 -> V_422 = V_423 ;
V_402 -> V_424 = V_425 ;
V_402 -> V_426 =
F_115 ( V_427 ) ;
if ( V_4 )
V_402 -> V_426 =
F_115 ( F_116 ( V_2 , V_4 ) ) ;
}
static void * F_117 ( struct V_384 * V_385 , struct V_428 * V_429 )
{
return V_385 -> V_430 ;
}
static void F_118 ( void * V_353 )
{
return;
}
static void F_119 ( void * V_155 , struct V_3 * V_4 ,
void * V_318 )
{
struct V_168 * V_169 V_351 = V_155 ;
struct V_1 * V_2 V_351 = F_54 ( V_169 ) ;
F_15 ( V_2 , L_102 ) ;
F_15 ( V_2 , L_103 ) ;
}
int F_120 ( char * V_431 , const T_2 V_14 )
{
char * type , * V_61 ;
T_1 V_369 = 0 , V_121 = 0 ;
T_1 V_39 = ( V_14 & V_109 ) >> V_108 ;
if ( ! ( V_14 & V_25 ) &&
! ( V_14 & V_31 ) ) {
int V_60 = F_10 ( V_14 ) ;
return sprintf ( V_431 , L_104 ,
F_12 ( V_39 ) ,
V_60 == V_38 ? L_105 :
V_432 [ V_60 ] . V_433 ) ;
}
if ( V_14 & V_31 ) {
type = L_106 ;
V_369 = V_14 & V_32 ;
V_121 = ( ( V_14 & V_126 )
>> V_127 ) + 1 ;
} else if ( V_14 & V_25 ) {
type = L_107 ;
V_369 = V_14 & V_434 ;
} else {
type = L_108 ;
}
switch ( V_14 & V_123 ) {
case V_144 :
V_61 = L_109 ;
break;
case V_152 :
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
return sprintf ( V_431 , L_114 ,
type , F_12 ( V_39 ) , V_61 , V_369 , V_121 ,
( V_14 & V_117 ) ? L_115 : L_116 ,
( V_14 & V_435 ) ? L_117 : L_118 ,
( V_14 & V_436 ) ? L_119 : L_118 ,
( V_14 & V_437 ) ? L_120 : L_118 ,
( V_14 & V_438 ) ? L_121 : L_118 ) ;
}
static void F_121 ( struct V_1 * V_2 ,
struct V_77 * V_98 )
{
V_98 -> V_133 = 0x0FFF ;
V_98 -> V_134 = 0x1FD0 ;
V_98 -> V_135 = 0x1FD0 ;
F_15 ( V_2 , L_122 ,
V_98 -> V_184 . V_389 , V_98 -> V_179 ) ;
if ( V_98 -> V_179 ) {
struct V_13 V_14 ;
F_38 ( V_98 -> V_179 ,
V_98 -> V_119 , & V_14 ) ;
F_73 ( V_2 , NULL , V_98 , & V_14 ) ;
F_61 ( V_98 -> V_143 , & V_98 -> V_184 , false ) ;
}
}
static T_10 F_122 ( struct V_439 * V_439 ,
const char T_11 * V_440 , T_12 V_209 , T_13 * V_441 )
{
struct V_77 * V_98 = V_439 -> V_442 ;
struct V_1 * V_2 ;
char V_431 [ 64 ] ;
T_12 V_443 ;
T_2 V_444 ;
V_2 = V_98 -> V_143 ;
memset ( V_431 , 0 , sizeof( V_431 ) ) ;
V_443 = F_63 ( V_209 , sizeof( V_431 ) - 1 ) ;
if ( F_123 ( V_431 , V_440 , V_443 ) )
return - V_445 ;
if ( sscanf ( V_431 , L_123 , & V_444 ) == 1 )
V_98 -> V_179 = V_444 ;
else
V_98 -> V_179 = 0 ;
F_121 ( V_2 , V_98 ) ;
return V_209 ;
}
static T_10 F_124 ( struct V_439 * V_439 ,
char T_11 * V_440 , T_12 V_209 , T_13 * V_441 )
{
char * V_446 ;
int V_447 = 0 ;
int V_71 = 0 ;
T_10 V_80 ;
struct V_77 * V_98 = V_439 -> V_442 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = & ( V_98 -> V_201 [ V_98 -> V_202 ] ) ;
struct V_13 * V_14 = & V_6 -> V_14 ;
V_2 = V_98 -> V_143 ;
V_446 = F_125 ( 2048 , V_448 ) ;
if ( ! V_446 )
return - V_449 ;
V_447 += sprintf ( V_446 + V_447 , L_124 , V_98 -> V_184 . V_389 ) ;
V_447 += sprintf ( V_446 + V_447 , L_125 ,
V_98 -> V_208 , V_98 -> V_207 ,
V_98 -> V_133 ) ;
V_447 += sprintf ( V_446 + V_447 , L_126 ,
V_98 -> V_179 ) ;
V_447 += sprintf ( V_446 + V_447 , L_127 ,
( V_2 -> V_11 -> V_12 & V_42 ) ? L_128 : L_118 ,
( V_2 -> V_11 -> V_12 & V_43 ) ? L_129 : L_118 ,
( V_2 -> V_11 -> V_12 & V_45 ) ? L_130 : L_118 ) ;
V_447 += sprintf ( V_446 + V_447 , L_131 ,
( F_31 ( V_14 ) ) ? L_132 :
F_35 ( V_14 ) ? L_106 : L_107 ) ;
if ( ! F_31 ( V_14 ) ) {
V_447 += sprintf ( V_446 + V_447 , L_133 ,
( F_41 ( V_14 ) ) ? L_134 : L_135 ) ;
V_447 += sprintf ( V_446 + V_447 , L_133 ,
( F_6 ( V_14 ) ) ? L_136 :
( F_7 ( V_14 ) ) ? L_137 :
( F_8 ( V_14 ) ) ? L_111 : L_113 ) ;
V_447 += sprintf ( V_446 + V_447 , L_138 ,
( V_14 -> V_62 ) ? L_139 : L_140 ,
( V_98 -> V_241 ) ? L_141 : L_118 ) ;
}
V_447 += sprintf ( V_446 + V_447 , L_142 ,
V_98 -> V_211 ) ;
V_447 += sprintf ( V_446 + V_447 ,
L_143 ,
V_98 -> V_184 . V_150 ,
V_98 -> V_184 . V_405 ,
V_98 -> V_184 . V_395 ,
V_98 -> V_184 . V_396 ) ;
V_447 += sprintf ( V_446 + V_447 ,
L_144 ,
F_97 ( V_98 -> V_184 . V_426 ) ,
V_98 -> V_184 . V_424 ,
V_98 -> V_184 . V_422 ) ;
V_447 += sprintf ( V_446 + V_447 , L_145 , V_98 -> V_184 . V_323 ) ;
V_447 += sprintf ( V_446 + V_447 ,
L_146 ,
V_98 -> V_184 . V_450 [ 0 ] ,
V_98 -> V_184 . V_450 [ 1 ] ,
V_98 -> V_184 . V_450 [ 2 ] ,
V_98 -> V_184 . V_450 [ 3 ] ) ;
for ( V_71 = 0 ; V_71 < V_412 ; V_71 ++ ) {
T_2 V_451 = F_58 ( V_98 -> V_184 . V_185 [ V_71 ] ) ;
V_447 += sprintf ( V_446 + V_447 , L_147 , V_71 , V_451 ) ;
V_447 += F_120 ( V_446 + V_447 , V_451 ) ;
}
V_80 = F_126 ( V_440 , V_209 , V_441 , V_446 , V_447 ) ;
F_127 ( V_446 ) ;
return V_80 ;
}
static T_10 F_128 ( struct V_439 * V_439 ,
char T_11 * V_440 , T_12 V_209 , T_13 * V_441 )
{
char * V_446 ;
int V_447 = 0 ;
int V_71 , V_260 ;
T_10 V_80 ;
struct V_5 * V_6 ;
struct V_13 * V_14 ;
struct V_77 * V_98 = V_439 -> V_442 ;
V_446 = F_125 ( 1024 , V_448 ) ;
if ( ! V_446 )
return - V_449 ;
for ( V_71 = 0 ; V_71 < V_390 ; V_71 ++ ) {
V_6 = & ( V_98 -> V_201 [ V_71 ] ) ;
V_14 = & V_6 -> V_14 ;
V_447 += sprintf ( V_446 + V_447 ,
L_148
L_149 ,
V_98 -> V_202 == V_71 ? L_150 : L_151 ,
V_14 -> type ,
V_14 -> V_62 ,
F_6 ( V_14 ) ? L_109 :
F_7 ( V_14 ) ? L_110 :
F_8 ( V_14 ) ? L_111 : L_152 ,
V_14 -> V_60 ) ;
for ( V_260 = 0 ; V_260 < V_72 ; V_260 ++ ) {
V_447 += sprintf ( V_446 + V_447 ,
L_153 ,
V_6 -> V_73 [ V_260 ] . V_69 ,
V_6 -> V_73 [ V_260 ] . V_66 ,
V_6 -> V_73 [ V_260 ] . V_67 ) ;
}
}
V_80 = F_126 ( V_440 , V_209 , V_441 , V_446 , V_447 ) ;
F_127 ( V_446 ) ;
return V_80 ;
}
static T_10 F_129 ( struct V_439 * V_439 ,
char T_11 * V_440 ,
T_12 V_209 , T_13 * V_441 )
{
static const char * const V_452 [] = {
[ V_347 ] = L_154 ,
[ V_348 ] = L_155 ,
[ V_453 ] = L_156 ,
[ V_454 ] = L_157 ,
[ V_455 ] = L_158 ,
[ V_456 ] = L_159 ,
[ V_457 ] = L_135 ,
[ V_458 ] = L_160 ,
} ;
static const char * const V_459 [] = {
[ V_460 ] = L_161 ,
[ V_461 ] = L_162 ,
[ V_462 ] = L_163 ,
[ V_463 ] = L_164 ,
[ V_464 ] = L_165 ,
[ V_28 ] = L_166 ,
[ V_465 ] = L_167 ,
[ V_466 ] = L_168 ,
[ V_467 ] = L_169 ,
[ V_468 ] = L_170 ,
[ V_469 ] = L_171 ,
[ V_303 ] = L_172 ,
[ V_304 ] = L_173 ,
[ V_305 ] = L_174 ,
[ V_145 ] = L_175 ,
} ;
char * V_446 , * V_470 , * V_471 ;
int V_472 , V_14 ;
T_10 V_80 ;
struct V_77 * V_98 = V_439 -> V_442 ;
struct V_473 * V_366 ;
static const T_12 V_474 = 1024 ;
V_446 = F_125 ( V_474 , V_448 ) ;
if ( ! V_446 )
return - V_449 ;
V_470 = V_446 ;
V_471 = V_470 + V_474 ;
V_470 += F_130 ( V_470 , V_471 - V_470 , L_176 ) ;
for ( V_14 = 0 ; V_14 < V_72 ; V_14 ++ )
V_470 += F_130 ( V_470 , V_471 - V_470 , L_177 , V_459 [ V_14 ] ) ;
V_470 += F_130 ( V_470 , V_471 - V_470 , L_178 ) ;
for ( V_472 = 0 ; V_472 < V_475 ; V_472 ++ ) {
V_470 += F_130 ( V_470 , V_471 - V_470 ,
L_177 , V_452 [ V_472 ] ) ;
for ( V_14 = 0 ; V_14 < V_72 ; V_14 ++ ) {
V_366 = & ( V_98 -> V_103 [ V_472 ] [ V_14 ] ) ;
V_470 += F_130 ( V_470 , V_471 - V_470 ,
L_179 ,
V_366 -> V_105 ,
V_366 -> V_104 ) ;
}
V_470 += F_130 ( V_470 , V_471 - V_470 , L_178 ) ;
}
V_80 = F_126 ( V_440 , V_209 , V_441 , V_446 , V_470 - V_446 ) ;
F_127 ( V_446 ) ;
return V_80 ;
}
static T_10 F_131 ( struct V_439 * V_439 ,
const char T_11 * V_440 ,
T_12 V_209 , T_13 * V_441 )
{
struct V_77 * V_98 = V_439 -> V_442 ;
memset ( V_98 -> V_103 , 0 , sizeof( V_98 -> V_103 ) ) ;
return V_209 ;
}
static void F_132 ( void * V_2 , void * V_318 , struct V_428 * V_476 )
{
struct V_77 * V_98 = V_318 ;
V_98 -> V_477 =
F_133 ( L_180 , V_478 | V_479 , V_476 ,
V_98 , & V_480 ) ;
V_98 -> V_481 =
F_133 ( L_181 , V_478 , V_476 ,
V_98 , & V_482 ) ;
V_98 -> V_483 =
F_133 ( L_182 , V_478 | V_479 , V_476 ,
V_98 , & V_484 ) ;
V_98 -> V_485 =
F_134 ( L_183 , V_478 | V_479 , V_476 ,
& V_98 -> V_337 ) ;
V_98 -> V_486 =
F_134 ( L_184 , V_478 | V_479 , V_476 ,
& V_98 -> V_324 ) ;
}
static void F_135 ( void * V_2 , void * V_318 )
{
struct V_77 * V_98 = V_318 ;
F_136 ( V_98 -> V_477 ) ;
F_136 ( V_98 -> V_481 ) ;
F_136 ( V_98 -> V_483 ) ;
F_136 ( V_98 -> V_485 ) ;
F_136 ( V_98 -> V_486 ) ;
}
static void F_137 ( void * V_155 ,
struct V_156 * V_157 ,
struct V_399 * V_400 ,
struct V_3 * V_4 , void * V_318 )
{
}
int F_138 ( void )
{
return F_139 ( & V_487 ) ;
}
void F_140 ( void )
{
F_141 ( & V_487 ) ;
}
int F_142 ( struct V_1 * V_2 , struct V_317 * V_488 ,
bool V_489 )
{
struct V_164 * V_184 = & V_488 -> V_98 . V_184 ;
F_143 ( & V_2 -> V_490 ) ;
if ( V_489 ) {
if ( V_488 -> V_491 == 0 )
V_184 -> V_150 |= V_492 ;
V_488 -> V_491 ++ ;
} else {
V_488 -> V_491 -- ;
if ( V_488 -> V_491 == 0 )
V_184 -> V_150 &= ~ V_492 ;
}
return F_61 ( V_2 , V_184 , false ) ;
}
