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
V_14 -> V_61 , V_14 -> V_62 , V_14 -> V_63 ) ;
}
static void F_16 ( struct V_64 * V_65 )
{
V_65 -> V_66 = 0 ;
V_65 -> V_67 = 0 ;
V_65 -> V_68 = V_69 ;
V_65 -> V_70 = 0 ;
V_65 -> V_71 = V_69 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
int V_72 ;
F_15 ( V_2 , L_18 ) ;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ )
F_16 ( & V_6 -> V_74 [ V_72 ] ) ;
for ( V_72 = 0 ; V_72 < F_11 ( V_6 -> V_75 ) ; V_72 ++ )
F_16 ( & V_6 -> V_75 [ V_72 ] ) ;
}
static inline T_1 F_18 ( T_1 V_76 , T_1 V_77 )
{
return ( V_77 & V_76 ) == V_77 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_78 * V_79 , T_1 V_80 ,
struct V_3 * V_4 )
{
int V_81 = - V_82 ;
F_20 ( V_2 , L_19 ,
V_4 -> V_83 , V_80 ) ;
V_81 = F_21 ( V_4 , V_80 , 5000 ) ;
if ( V_81 == - V_82 ) {
F_22 ( V_2 , L_20 ,
V_80 ) ;
F_23 ( V_4 , V_80 ) ;
}
return V_81 ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_80 ,
struct V_78 * V_79 ,
struct V_3 * V_4 )
{
if ( V_80 < V_84 )
F_19 ( V_2 , V_79 , V_80 , V_4 ) ;
else
F_22 ( V_2 , L_21 ,
V_80 , V_84 ) ;
}
static inline int F_25 ( T_2 V_22 )
{
return ! ! ( V_22 & V_85 ) +
! ! ( V_22 & V_86 ) +
! ! ( V_22 & V_87 ) ;
}
static T_3 F_26 ( struct V_5 * V_6 , int V_88 )
{
if ( V_6 -> V_89 )
return V_6 -> V_89 [ V_88 ] ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
int V_90 , int V_91 , int V_92 ,
struct V_64 * V_65 )
{
static const T_4 V_93 = ( ( ( T_4 ) 1 ) << ( V_94 - 1 ) ) ;
T_3 V_95 , V_96 ;
V_96 = F_26 ( V_6 , V_90 ) ;
while ( V_91 > 0 ) {
if ( V_65 -> V_70 >= V_94 ) {
V_65 -> V_70 = V_94 - 1 ;
if ( V_65 -> V_66 & V_93 ) {
V_65 -> V_66 &= ~ V_93 ;
V_65 -> V_67 -- ;
}
}
V_65 -> V_70 ++ ;
V_65 -> V_66 <<= 1 ;
if ( V_92 > 0 ) {
V_65 -> V_67 ++ ;
V_65 -> V_66 |= 0x1 ;
V_92 -- ;
}
V_91 -- ;
}
if ( V_65 -> V_70 > 0 )
V_65 -> V_68 = 128 * ( 100 * V_65 -> V_67 )
/ V_65 -> V_70 ;
else
V_65 -> V_68 = V_69 ;
V_95 = V_65 -> V_70 - V_65 -> V_67 ;
if ( ( V_95 >= V_97 ) ||
( V_65 -> V_67 >= V_98 ) )
V_65 -> V_71 = ( V_65 -> V_68 * V_96 + 64 ) / 128 ;
else
V_65 -> V_71 = V_69 ;
return 0 ;
}
static int F_28 ( struct V_78 * V_99 ,
struct V_5 * V_6 ,
int V_90 , int V_91 , int V_92 ,
T_1 V_100 )
{
struct V_64 * V_65 = NULL ;
int V_81 ;
if ( V_90 < 0 || V_90 >= V_73 )
return - V_101 ;
if ( V_6 -> V_102 != V_103 ) {
struct V_104 * V_105 = & V_99 -> V_105 ;
V_105 -> V_106 [ V_6 -> V_102 ] [ V_90 ] . V_107 += V_91 ;
V_105 -> V_106 [ V_6 -> V_102 ] [ V_90 ] . V_108 += V_92 ;
}
V_65 = & ( V_6 -> V_74 [ V_90 ] ) ;
V_81 = F_27 ( V_6 , V_90 , V_91 , V_92 ,
V_65 ) ;
if ( V_81 )
return V_81 ;
if ( F_29 ( V_100 > V_109 ) )
return - V_101 ;
V_65 = & V_6 -> V_75 [ V_100 ] ;
return F_27 ( V_6 , V_90 , V_91 , V_92 ,
V_65 ) ;
}
static T_2 F_30 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
T_2 V_110 = 0 ;
int V_60 = V_14 -> V_60 ;
V_110 |= ( ( V_14 -> V_39 << V_111 ) &
V_112 ) ;
if ( F_31 ( V_14 ) ) {
V_110 |= V_36 [ V_60 ] . V_37 ;
if ( V_60 >= V_113 && V_60 <= V_114 )
V_110 |= V_115 ;
return V_110 ;
}
if ( F_32 ( V_14 ) ) {
if ( V_60 < V_29 || V_60 > V_30 ) {
F_22 ( V_2 , L_22 , V_60 ) ;
V_60 = V_30 ;
}
V_110 |= V_25 ;
if ( F_33 ( V_14 ) )
V_110 |= V_36 [ V_60 ] . V_116 ;
else if ( F_34 ( V_14 ) )
V_110 |= V_36 [ V_60 ] . V_117 ;
else
F_29 ( 1 ) ;
} else if ( F_35 ( V_14 ) ) {
if ( V_60 < V_33 || V_60 > V_34 ) {
F_22 ( V_2 , L_23 , V_60 ) ;
V_60 = V_34 ;
}
V_110 |= V_31 ;
if ( F_36 ( V_14 ) )
V_110 |= V_36 [ V_60 ] . V_118 ;
else if ( F_37 ( V_14 ) )
V_110 |= V_36 [ V_60 ] . V_119 ;
else
F_29 ( 1 ) ;
} else {
F_22 ( V_2 , L_24 , V_14 -> type ) ;
}
V_110 |= V_14 -> V_61 ;
if ( V_14 -> V_62 )
V_110 |= V_120 ;
if ( V_14 -> V_63 )
V_110 |= V_121 ;
return V_110 ;
}
static int F_38 ( const T_2 V_110 ,
enum V_122 V_123 ,
struct V_13 * V_14 )
{
T_2 V_124 = V_110 & V_112 ;
T_1 F_2 = F_25 ( V_110 ) ;
T_1 V_125 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_60 = F_10 ( V_110 ) ;
if ( V_14 -> V_60 == V_38 )
return - V_101 ;
V_14 -> V_39 = ( V_124 >> V_111 ) ;
if ( ! ( V_110 & V_25 ) &&
! ( V_110 & V_31 ) ) {
if ( F_2 == 1 ) {
if ( V_123 == V_126 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
}
return 0 ;
}
if ( V_110 & V_120 )
V_14 -> V_62 = true ;
if ( V_110 & V_121 )
V_14 -> V_63 = true ;
V_14 -> V_61 = V_110 & V_127 ;
if ( V_110 & V_25 ) {
V_125 = ( ( V_110 & V_128 ) >>
V_129 ) + 1 ;
if ( V_125 == 1 ) {
V_14 -> type = V_54 ;
F_29 ( F_2 != 1 ) ;
} else if ( V_125 == 2 ) {
V_14 -> type = V_55 ;
F_29 ( F_2 != 2 ) ;
} else {
F_29 ( 1 ) ;
}
} else if ( V_110 & V_31 ) {
V_125 = ( ( V_110 & V_130 ) >>
V_131 ) + 1 ;
if ( V_125 == 1 ) {
V_14 -> type = V_56 ;
F_29 ( F_2 != 1 ) ;
} else if ( V_125 == 2 ) {
V_14 -> type = V_57 ;
F_29 ( F_2 != 2 ) ;
} else {
F_29 ( 1 ) ;
}
}
F_29 ( V_14 -> V_61 == V_132 ) ;
F_29 ( V_14 -> V_61 == V_133 &&
! F_35 ( V_14 ) ) ;
return 0 ;
}
static int F_39 ( T_2 V_134 , struct V_13 * V_14 )
{
T_1 V_135 ;
if ( ! V_14 -> V_39 || V_14 -> V_39 > V_48 )
return 0 ;
if ( ! F_18 ( V_134 , V_14 -> V_39 ) )
return 0 ;
V_135 = V_136 [ V_14 -> V_39 ] ;
while ( ( V_135 != V_14 -> V_39 ) &&
! F_18 ( V_134 , V_135 ) )
V_135 = V_136 [ V_135 ] ;
if ( V_135 == V_14 -> V_39 )
return 0 ;
V_14 -> V_39 = V_135 ;
return 1 ;
}
static T_5 F_40 ( struct V_78 * V_99 ,
struct V_13 * V_14 )
{
if ( F_31 ( V_14 ) )
return V_99 -> V_137 ;
else if ( F_41 ( V_14 ) )
return V_99 -> V_138 ;
else if ( F_42 ( V_14 ) )
return V_99 -> V_139 ;
F_29 ( 1 ) ;
return 0 ;
}
static T_5 F_43 ( struct V_1 * V_2 , T_1 V_60 , T_5 V_140 ,
int V_141 )
{
T_1 V_142 = V_38 ;
T_1 V_143 = V_38 ;
if ( F_44 ( V_141 ) || ! F_45 ( V_141 ) ) {
int V_72 ;
T_2 V_93 ;
V_72 = V_60 - 1 ;
for ( V_93 = ( 1 << V_72 ) ; V_72 >= 0 ; V_72 -- , V_93 >>= 1 ) {
if ( V_140 & V_93 ) {
V_143 = V_72 ;
break;
}
}
V_72 = V_60 + 1 ;
for ( V_93 = ( 1 << V_72 ) ; V_72 < V_73 ; V_72 ++ , V_93 <<= 1 ) {
if ( V_140 & V_93 ) {
V_142 = V_72 ;
break;
}
}
return ( V_142 << 8 ) | V_143 ;
}
V_143 = V_60 ;
while ( V_143 != V_38 ) {
V_143 = V_36 [ V_143 ] . V_144 ;
if ( V_143 == V_38 )
break;
if ( V_140 & ( 1 << V_143 ) )
break;
F_15 ( V_2 , L_25 , V_143 ) ;
}
V_142 = V_60 ;
while ( V_142 != V_38 ) {
V_142 = V_36 [ V_142 ] . V_145 ;
if ( V_142 == V_38 )
break;
if ( V_140 & ( 1 << V_142 ) )
break;
F_15 ( V_2 , L_26 , V_142 ) ;
}
return ( V_142 << 8 ) | V_143 ;
}
static inline bool F_46 ( struct V_78 * V_99 ,
struct V_13 * V_14 )
{
return F_47 ( V_14 -> V_60 ) & F_40 ( V_99 , V_14 ) ;
}
static bool F_48 ( struct V_78 * V_99 ,
struct V_13 * V_14 )
{
T_1 V_143 ;
T_5 V_146 ;
T_5 V_140 ;
struct V_1 * V_2 = V_99 -> V_105 . V_147 ;
V_140 = F_40 ( V_99 , V_14 ) ;
V_146 = F_43 ( V_2 , V_14 -> V_60 , V_140 ,
V_14 -> type ) ;
V_143 = V_146 & 0xff ;
if ( V_143 == V_38 )
return true ;
V_14 -> V_60 = V_143 ;
return false ;
}
static void F_49 ( struct V_78 * V_99 ,
struct V_13 * V_14 )
{
struct V_1 * V_2 = V_99 -> V_105 . V_147 ;
if ( F_31 ( V_14 ) ) {
return;
} else if ( F_41 ( V_14 ) ) {
if ( V_99 -> V_123 == V_126 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
V_14 -> V_61 = V_148 ;
F_29 ( V_14 -> V_60 < V_27 ||
V_14 -> V_60 > V_149 ) ;
V_14 -> V_60 = V_150 [ V_14 -> V_60 ] ;
V_14 -> V_63 = false ;
} else {
V_14 -> type = F_37 ( V_14 ) ?
V_56 : V_54 ;
}
if ( F_2 ( V_14 -> V_39 ) > 1 )
V_14 -> V_39 = F_50 ( V_2 -> V_11 -> V_12 ) ;
V_14 -> V_62 = false ;
if ( ! F_46 ( V_99 , V_14 ) )
F_48 ( V_99 , V_14 ) ;
}
static inline bool F_51 ( struct V_13 * V_151 ,
struct V_13 * V_152 )
{
return ( V_151 -> type == V_152 -> type ) && ( V_151 -> V_39 == V_152 -> V_39 ) && ( V_151 -> V_62 == V_152 -> V_62 ) ;
}
static T_2 F_52 ( enum V_153 V_154 )
{
if ( V_154 & V_155 )
return V_156 ;
else if ( V_154 & V_157 )
return V_133 ;
else if ( V_154 & V_158 )
return V_132 ;
return V_148 ;
}
static T_1 F_53 ( struct V_159 * V_160 )
{
T_1 V_80 = V_84 ;
if ( F_54 ( V_160 -> V_161 ) ) {
T_1 * V_162 = F_55 ( V_160 ) ;
V_80 = V_162 [ 0 ] & 0xf ;
}
if ( F_56 ( V_80 > V_84 ) )
V_80 = V_84 ;
return V_80 ;
}
void F_57 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_80 , struct V_163 * V_164 )
{
int V_165 ;
int V_166 ;
int V_167 , V_72 ;
struct V_168 * V_169 ;
enum V_153 V_170 ;
T_2 V_110 ;
struct V_13 V_14 ;
struct V_5 * V_171 , * V_172 , * V_173 ;
T_1 V_100 = ( V_174 ) V_164 -> V_175 . V_176 [ 0 ] ;
struct V_177 * V_178 = F_58 ( V_4 ) ;
struct V_78 * V_99 = & V_178 -> V_99 ;
if ( ! V_99 ) {
F_15 ( V_2 , L_27 ) ;
return;
} else if ( ! V_99 -> V_105 . V_147 ) {
F_15 ( V_2 , L_28 ) ;
return;
}
#ifdef F_59
if ( V_99 -> V_105 . V_179 ) {
F_15 ( V_2 , L_29 ) ;
return;
}
#endif
if ( ( V_164 -> V_154 & V_180 ) &&
! ( V_164 -> V_154 & V_181 ) )
return;
V_169 = & V_99 -> V_182 ;
V_110 = F_60 ( V_169 -> V_183 [ 0 ] ) ;
F_38 ( V_110 , V_164 -> V_123 , & V_14 ) ;
if ( V_164 -> V_123 == V_126 )
V_14 . V_60 -= V_184 ;
V_170 = V_164 -> V_175 . V_185 [ 0 ] . V_154 ;
V_167 = V_164 -> V_175 . V_185 [ 0 ] . V_24 ;
if ( V_170 & V_186 ) {
V_167 &= V_26 ;
if ( V_167 >= ( V_28 - V_184 ) )
V_167 ++ ;
if ( V_164 -> V_123 == V_187 )
V_167 += V_184 ;
} else if ( V_170 & V_188 ) {
V_167 &= V_32 ;
if ( V_167 >= ( V_28 - V_184 ) )
V_167 ++ ;
}
if ( F_61 ( V_189 ,
( unsigned long ) ( V_99 -> V_190 + V_191 ) ) ) {
int V_80 ;
F_15 ( V_2 , L_30 ) ;
for ( V_80 = 0 ; V_80 < V_84 ; V_80 ++ )
F_23 ( V_4 , V_80 ) ;
F_62 ( V_2 , V_4 , V_164 -> V_123 , false ) ;
return;
}
V_99 -> V_190 = V_189 ;
if ( ( V_167 < 0 ) ||
( V_14 . V_62 != ! ! ( V_170 & V_192 ) ) ||
( V_14 . V_61 != F_52 ( V_170 ) ) ||
( V_14 . V_39 != V_164 -> V_175 . V_193 ) ||
( ! ! ( V_110 & V_25 ) !=
! ! ( V_170 & V_186 ) ) ||
( ! ! ( V_110 & V_31 ) !=
! ! ( V_170 & V_188 ) ) ||
( ! ! ( V_110 & V_194 ) !=
! ! ( V_170 & V_195 ) ) ||
( V_14 . V_60 != V_167 ) ) {
F_15 ( V_2 ,
L_31 ,
V_167 , V_14 . V_60 , V_110 ) ;
V_99 -> V_196 ++ ;
if ( V_99 -> V_196 > V_197 ) {
V_99 -> V_196 = 0 ;
F_15 ( V_2 ,
L_32 ,
V_99 -> V_198 ) ;
F_63 ( V_2 , & V_99 -> V_182 , false ) ;
}
return;
} else
V_99 -> V_196 = 0 ;
if ( F_51 ( & V_14 ,
& ( V_99 -> V_199 [ V_99 -> V_200 ] . V_14 ) ) ) {
V_171 = & ( V_99 -> V_199 [ V_99 -> V_200 ] ) ;
V_172 = & ( V_99 -> V_199 [ 1 - V_99 -> V_200 ] ) ;
} else if ( F_51 ( & V_14 ,
& V_99 -> V_199 [ 1 - V_99 -> V_200 ] . V_14 ) ) {
V_171 = & ( V_99 -> V_199 [ 1 - V_99 -> V_200 ] ) ;
V_172 = & ( V_99 -> V_199 [ V_99 -> V_200 ] ) ;
} else {
F_15 ( V_2 ,
L_33 ) ;
V_173 = & ( V_99 -> V_199 [ V_99 -> V_200 ] ) ;
F_14 ( V_2 , & V_173 -> V_14 , L_34 ) ;
V_173 = & ( V_99 -> V_199 [ 1 - V_99 -> V_200 ] ) ;
F_14 ( V_2 , & V_173 -> V_14 , L_35 ) ;
F_14 ( V_2 , & V_14 , L_36 ) ;
F_64 ( V_99 , true ) ;
goto V_201;
}
if ( V_164 -> V_154 & V_181 ) {
V_110 = F_60 ( V_169 -> V_183 [ 0 ] ) ;
F_38 ( V_110 , V_164 -> V_123 , & V_14 ) ;
F_28 ( V_99 , V_171 , V_14 . V_60 ,
V_164 -> V_175 . V_202 ,
V_164 -> V_175 . V_203 ,
V_100 ) ;
if ( V_99 -> V_198 == V_204 ) {
V_99 -> V_205 += V_164 -> V_175 . V_203 ;
V_99 -> V_206 += ( V_164 -> V_175 . V_202 -
V_164 -> V_175 . V_203 ) ;
}
} else {
V_166 = V_164 -> V_175 . V_185 [ 0 ] . V_207 - 1 ;
V_166 = F_65 ( V_166 , 15 ) ;
V_165 = ! ! ( V_164 -> V_154 & V_208 ) ;
for ( V_72 = 0 ; V_72 <= V_166 ; ++ V_72 ) {
V_110 = F_60 ( V_169 -> V_183 [ V_72 ] ) ;
F_38 ( V_110 , V_164 -> V_123 , & V_14 ) ;
if ( F_51 ( & V_14 , & V_171 -> V_14 ) )
V_173 = V_171 ;
else if ( F_51 ( & V_14 , & V_172 -> V_14 ) )
V_173 = V_172 ;
else
continue;
F_28 ( V_99 , V_173 , V_14 . V_60 , 1 ,
V_72 < V_166 ? 0 : V_165 ,
V_100 ) ;
}
if ( V_99 -> V_198 == V_204 ) {
V_99 -> V_205 += V_165 ;
V_99 -> V_206 += V_166 + ( 1 - V_165 ) ;
}
}
V_99 -> V_209 = V_110 ;
F_15 ( V_2 , L_37 , V_100 ) ;
V_201:
if ( V_4 && V_4 -> V_210 [ V_164 -> V_123 ] )
F_66 ( V_2 , V_4 , V_99 , V_80 ) ;
}
static void F_67 ( void * V_211 ,
struct V_212 * V_213 ,
struct V_3 * V_4 , void * V_214 ,
struct V_215 * V_216 )
{
struct V_159 * V_160 = (struct V_159 * ) V_216 -> V_66 ;
struct V_217 * V_218 = (struct V_217 * ) V_211 ;
struct V_1 * V_2 = F_68 ( V_218 ) ;
struct V_163 * V_164 = F_69 ( V_216 ) ;
if ( ! F_70 ( V_160 -> V_161 ) ||
V_164 -> V_154 & V_219 )
return;
F_57 ( V_2 , V_4 , F_53 ( V_160 ) , V_164 ) ;
}
static void F_71 ( struct V_1 * V_2 , T_1 F_31 ,
struct V_78 * V_99 )
{
F_15 ( V_2 , L_38 ) ;
V_99 -> V_198 = V_204 ;
if ( F_31 ) {
V_99 -> V_220 = V_221 ;
V_99 -> V_222 = V_223 ;
V_99 -> V_224 = V_225 ;
} else {
V_99 -> V_220 = V_226 ;
V_99 -> V_222 = V_227 ;
V_99 -> V_224 = V_228 ;
}
V_99 -> V_229 = 0 ;
V_99 -> V_206 = 0 ;
V_99 -> V_205 = 0 ;
V_99 -> V_230 = V_189 ;
V_99 -> V_231 = 0 ;
}
static int F_72 ( struct V_78 * V_99 ,
const struct V_232 * V_102 )
{
switch ( V_102 -> V_233 ) {
case V_234 :
return V_99 -> V_235 ;
case V_236 :
return V_99 -> V_237 ;
case V_238 :
return V_99 -> V_239 ;
default:
F_29 ( 1 ) ;
}
return V_99 -> V_235 ;
}
static const T_5 * F_73 ( struct V_78 * V_99 ,
const struct V_232 * V_102 ,
T_2 V_61 )
{
const T_5 ( * V_240 ) [ V_73 ] ;
if ( F_29 ( V_102 -> V_233 != V_234 &&
V_102 -> V_233 != V_236 &&
V_102 -> V_233 != V_238 ) )
return V_241 ;
if ( V_102 -> V_233 == V_234 )
return V_241 ;
V_240 = V_242 ;
if ( V_102 -> V_233 == V_236 ) {
switch ( V_61 ) {
case V_148 :
V_240 = V_243 ;
break;
case V_156 :
V_240 = V_244 ;
break;
case V_133 :
V_240 = V_245 ;
break;
default:
F_29 ( 1 ) ;
}
} else if ( V_102 -> V_233 == V_238 ) {
switch ( V_61 ) {
case V_148 :
V_240 = V_242 ;
break;
case V_156 :
V_240 = V_246 ;
break;
case V_133 :
V_240 = V_247 ;
break;
default:
F_29 ( 1 ) ;
}
} else {
F_29 ( 1 ) ;
}
if ( ! V_102 -> V_62 && ! V_99 -> V_248 )
return V_240 [ 0 ] ;
else if ( V_102 -> V_62 && ! V_99 -> V_248 )
return V_240 [ 1 ] ;
else if ( ! V_102 -> V_62 && V_99 -> V_248 )
return V_240 [ 2 ] ;
else
return V_240 [ 3 ] ;
}
static void F_74 ( struct V_78 * V_99 ,
struct V_5 * V_6 )
{
struct V_13 * V_14 = & V_6 -> V_14 ;
const struct V_232 * V_102 = & V_249 [ V_6 -> V_102 ] ;
V_6 -> V_89 = F_73 ( V_99 , V_102 , V_14 -> V_61 ) ;
}
static T_3 F_75 ( struct V_1 * V_2 ,
struct V_78 * V_99 ,
struct V_5 * V_6 ,
unsigned long V_140 , T_6 V_60 )
{
struct V_5 * V_200 =
& ( V_99 -> V_199 [ V_99 -> V_200 ] ) ;
T_3 V_68 = V_200 -> V_74 [ V_60 ] . V_68 ;
T_5 V_250 = V_200 -> V_89 [ V_60 ] ;
const T_5 * V_251 = V_6 -> V_89 ;
T_5 V_146 ;
T_2 V_252 ;
int V_253 ;
if ( V_68 > V_254 ) {
V_252 = 100 * V_250 ;
F_15 ( V_2 ,
L_39 ,
V_68 , V_252 ) ;
} else {
V_252 = V_99 -> V_255 ;
F_15 ( V_2 ,
L_40 ,
V_68 , V_252 ) ;
}
V_253 = F_76 ( & V_140 , V_256 ) ;
while ( V_253 != V_38 ) {
if ( V_252 < ( 100 * V_251 [ V_253 ] ) )
break;
V_146 = F_43 ( V_2 , V_253 , V_140 ,
V_6 -> V_14 . type ) ;
V_253 = ( V_146 >> 8 ) & 0xff ;
}
F_15 ( V_2 , L_41 ,
V_253 , V_252 ,
V_253 != V_38 ?
100 * V_251 [ V_253 ] : V_69 ) ;
return V_253 ;
}
static T_2 F_77 ( struct V_3 * V_4 )
{
if ( V_4 -> V_257 >= V_258 )
return V_133 ;
else if ( V_4 -> V_257 >= V_259 )
return V_156 ;
return V_148 ;
}
static void F_64 ( struct V_78 * V_99 , bool V_260 )
{
struct V_5 * V_6 ;
int V_200 ;
int V_261 = 0 ;
struct V_1 * V_2 ;
V_2 = V_99 -> V_105 . V_147 ;
V_200 = V_99 -> V_200 ;
V_6 = & ( V_99 -> V_199 [ V_200 ] ) ;
if ( V_99 -> V_198 == V_204 ) {
if ( V_99 -> V_230 )
V_261 =
F_61 ( V_189 ,
( unsigned long ) ( V_99 -> V_230 +
V_262 ) ) ;
if ( V_260 ||
( V_99 -> V_206 > V_99 -> V_222 ) ||
( V_99 -> V_205 > V_99 -> V_224 ) ||
( ( ! V_99 -> V_263 ) &&
( V_99 -> V_230 ) && ( V_261 ) ) ) {
F_15 ( V_2 ,
L_42 ,
V_99 -> V_206 ,
V_99 -> V_205 ,
V_261 ) ;
V_99 -> V_198 = V_264 ;
F_15 ( V_2 ,
L_43 ) ;
V_99 -> V_206 = 0 ;
V_99 -> V_205 = 0 ;
V_99 -> V_230 = 0 ;
V_99 -> V_231 = F_47 ( V_6 -> V_102 ) ;
} else {
V_99 -> V_229 ++ ;
if ( V_99 -> V_229 >=
V_99 -> V_220 ) {
V_99 -> V_229 = 0 ;
F_15 ( V_2 ,
L_44 ) ;
F_17 ( V_2 , V_6 ) ;
}
}
if ( V_99 -> V_198 == V_264 ) {
F_17 ( V_2 , V_6 ) ;
}
}
}
static void F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_78 * V_99 ,
struct V_13 * V_14 )
{
F_79 ( V_2 , V_4 , V_99 , V_14 ) ;
F_63 ( V_2 , & V_99 -> V_182 , false ) ;
}
static enum V_265 F_80 ( struct V_1 * V_2 ,
struct V_78 * V_99 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_72 , V_266 , V_267 ;
enum V_265 V_268 ;
const struct V_232 * V_269 = & V_249 [ V_6 -> V_102 ] ;
const struct V_232 * V_270 ;
T_7 V_271 ;
T_1 V_272 = V_2 -> V_11 -> V_12 ;
const T_5 * V_273 ;
T_5 V_96 , V_274 ;
for ( V_72 = 0 ; V_72 < V_275 ; V_72 ++ ) {
V_268 = V_269 -> V_276 [ V_72 ] ;
if ( V_268 == V_103 )
continue;
if ( V_99 -> V_231 & F_47 ( V_268 ) ) {
F_15 ( V_2 , L_45 ,
V_268 ) ;
continue;
}
V_270 = & V_249 [ V_268 ] ;
if ( ! F_18 ( V_272 , V_270 -> V_39 ) ) {
F_15 ( V_2 ,
L_46 ,
V_268 , V_272 , V_270 -> V_39 ) ;
continue;
}
for ( V_266 = 0 ; V_266 < V_277 ; V_266 ++ ) {
V_271 = V_270 -> V_278 [ V_266 ] ;
if ( V_271 && ! V_271 ( V_2 , V_4 , V_6 ) )
break;
}
if ( V_266 != V_277 ) {
F_15 ( V_2 ,
L_47 ,
V_268 , V_266 ) ;
continue;
}
V_96 = V_99 -> V_255 / 100 ;
V_273 = F_73 ( V_99 , V_270 ,
F_77 ( V_4 ) ) ;
if ( F_29 ( ! V_273 ) )
continue;
V_267 = F_72 ( V_99 , V_270 ) ;
if ( F_29 ( V_267 == V_38 ) )
continue;
V_274 = V_273 [ V_267 ] ;
if ( V_96 >= V_274 ) {
F_15 ( V_2 ,
L_48 ,
V_268 , V_274 , V_96 ) ;
continue;
}
F_15 ( V_2 ,
L_49 ,
V_268 , V_274 , V_96 ) ;
break;
}
if ( V_72 == V_275 )
return V_103 ;
return V_268 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_78 * V_99 ,
struct V_3 * V_4 ,
enum V_265 V_279 )
{
struct V_5 * V_6 = & ( V_99 -> V_199 [ V_99 -> V_200 ] ) ;
struct V_5 * V_280 =
& ( V_99 -> V_199 [ ( 1 - V_99 -> V_200 ) ] ) ;
struct V_13 * V_14 = & V_280 -> V_14 ;
const struct V_232 * V_102 = & V_249 [ V_279 ] ;
const struct V_232 * V_281 = & V_249 [ V_6 -> V_102 ] ;
T_2 V_282 = ( sizeof( struct V_5 ) -
( sizeof( struct V_64 ) * V_73 ) ) ;
unsigned long V_140 = 0 ;
T_2 V_253 = 0 ;
memcpy ( V_280 , V_6 , V_282 ) ;
V_14 -> V_62 = V_102 -> V_62 ;
V_14 -> V_39 = V_102 -> V_39 ;
if ( V_102 -> V_233 == V_234 ) {
if ( V_99 -> V_123 == V_126 )
V_14 -> type = V_52 ;
else
V_14 -> type = V_53 ;
V_140 = V_99 -> V_137 ;
} else if ( V_102 -> V_233 == V_236 ) {
V_14 -> type = V_99 -> F_35 ? V_56 : V_54 ;
V_140 = V_99 -> V_138 ;
} else if ( V_102 -> V_233 == V_238 ) {
V_14 -> type = V_99 -> F_35 ? V_57 : V_55 ;
V_140 = V_99 -> V_139 ;
} else {
F_29 ( L_50 ) ;
}
V_14 -> V_61 = F_77 ( V_4 ) ;
V_14 -> V_63 = V_99 -> V_63 ;
V_280 -> V_102 = V_279 ;
F_74 ( V_99 , V_280 ) ;
V_99 -> V_231 |= F_47 ( V_279 ) ;
if ( V_281 -> V_233 != V_102 -> V_233 ) {
V_253 = F_75 ( V_2 , V_99 , V_280 ,
V_140 , V_14 -> V_60 ) ;
if ( ( V_253 == V_38 ) ||
! ( F_47 ( V_253 ) & V_140 ) ) {
F_15 ( V_2 ,
L_51
L_52 ,
V_253 , V_140 ) ;
goto V_283;
}
V_14 -> V_60 = V_253 ;
}
F_15 ( V_2 , L_53 ,
V_279 , V_14 -> V_60 ) ;
return 0 ;
V_283:
V_14 -> type = V_51 ;
return - 1 ;
}
static enum V_284 F_82 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
T_3 V_285 , int V_143 , int V_142 ,
int V_286 ,
int V_287 , int V_288 )
{
enum V_284 V_289 = V_290 ;
if ( ( V_285 <= V_291 ) || ( V_286 == 0 ) ) {
F_15 ( V_2 ,
L_54 ) ;
return V_292 ;
}
if ( ( V_287 == V_69 ) &&
( V_288 == V_69 ) &&
( V_142 != V_38 ) ) {
F_15 ( V_2 ,
L_55 ) ;
return V_293 ;
}
if ( ( V_288 == V_69 ) &&
( V_142 != V_38 ) &&
( V_287 != V_69 ) &&
( V_287 < V_286 ) ) {
F_15 ( V_2 ,
L_56 ) ;
return V_293 ;
}
if ( ( V_288 != V_69 ) &&
( V_288 > V_286 ) ) {
F_15 ( V_2 ,
L_57 ) ;
return V_293 ;
}
if ( ( V_287 != V_69 ) &&
( V_288 != V_69 ) &&
( V_287 < V_286 ) &&
( V_288 < V_286 ) ) {
F_15 ( V_2 ,
L_58 ) ;
return V_290 ;
}
if ( ( V_287 != V_69 ) &&
( V_287 > V_286 ) ) {
F_15 ( V_2 ,
L_59 ) ;
V_289 = V_292 ;
goto V_294;
}
if ( ( V_287 == V_69 ) &&
( V_143 != V_38 ) ) {
F_15 ( V_2 ,
L_60 ) ;
V_289 = V_292 ;
goto V_294;
}
F_15 ( V_2 , L_61 ) ;
V_294:
if ( ( V_289 == V_292 ) && ( V_143 != V_38 ) ) {
if ( V_285 >= V_254 ) {
F_15 ( V_2 ,
L_62 ) ;
V_289 = V_290 ;
} else if ( V_286 > ( 100 * V_6 -> V_89 [ V_143 ] ) ) {
F_15 ( V_2 ,
L_63 ) ;
V_289 = V_290 ;
} else {
F_15 ( V_2 , L_64 ) ;
}
}
return V_289 ;
}
static void F_83 ( struct V_1 * V_2 , int V_60 ,
int * V_295 , int * V_296 )
{
* V_295 = V_60 + V_297 ;
if ( * V_295 > V_109 )
* V_295 = V_298 ;
* V_296 = V_60 - V_297 ;
if ( * V_296 < 0 )
* V_296 = V_298 ;
}
static bool F_84 ( struct V_1 * V_2 , struct V_299 * V_300 ,
struct V_13 * V_14 , enum V_122 V_123 )
{
int V_60 = V_14 -> V_60 ;
bool V_301 = ( V_302 . V_303 == V_304 ) ;
bool V_305 = ( V_300 -> type == V_306 &&
! V_300 -> V_307 . V_308 ) ;
F_15 ( V_2 , L_65 ,
V_301 , V_305 ) ;
if ( ( V_301 || V_305 ) &&
! F_85 ( V_2 , V_123 ) )
return false ;
F_15 ( V_2 , L_66 , V_14 -> type ) ;
if ( F_31 ( V_14 ) )
return V_60 == V_309 ;
if ( F_32 ( V_14 ) )
return V_60 == V_310 ;
if ( F_35 ( V_14 ) )
return V_60 == V_310 ||
V_60 == V_311 ||
V_60 == V_149 ;
F_29 ( 1 ) ;
return false ;
}
static enum V_312 F_86 ( struct V_1 * V_2 ,
T_3 V_285 , int V_313 , int V_314 ,
int V_286 ,
int V_315 , int V_316 )
{
if ( V_286 == V_69 ) {
F_15 ( V_2 , L_67 ) ;
return V_317 ;
}
if ( V_285 <= V_318 || V_286 == 0 ) {
F_15 ( V_2 , L_68 ) ;
return V_319 ;
}
if ( V_313 != V_298 ) {
if ( V_315 == V_69 &&
( V_316 == V_69 ||
V_286 >= V_316 ) ) {
F_15 ( V_2 ,
L_69 ) ;
return V_320 ;
}
if ( V_315 > V_286 ) {
F_15 ( V_2 ,
L_70 ) ;
return V_320 ;
}
}
if ( V_285 < V_321 && V_314 != V_298 ) {
if ( V_315 == V_69 &&
V_316 != V_69 &&
V_286 < V_316 ) {
F_15 ( V_2 ,
L_71 ) ;
return V_322 ;
}
if ( V_315 < V_286 &&
( V_316 == V_69 ||
V_316 > V_286 ) ) {
F_15 ( V_2 ,
L_72 ) ;
return V_322 ;
}
}
F_15 ( V_2 , L_73 ) ;
return V_317 ;
}
static bool F_87 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_78 * V_99 ,
struct V_5 * V_6 )
{
struct V_177 * V_323 = ( void * ) V_4 -> V_324 ;
struct V_299 * V_300 = V_323 -> V_300 ;
struct V_325 * V_326 ;
enum V_122 V_123 ;
struct V_64 * V_65 ;
struct V_13 * V_14 = & V_6 -> V_14 ;
enum V_312 V_289 ;
T_3 V_285 ;
T_1 V_327 = V_99 -> V_182 . V_328 ;
int V_286 ;
int V_313 , V_314 ;
int V_315 = V_69 , V_316 = V_69 ;
#ifdef F_59
if ( V_99 -> V_105 . V_329 <= V_109 ) {
F_15 ( V_2 , L_74 ,
V_99 -> V_105 . V_329 ) ;
V_99 -> V_182 . V_328 = V_99 -> V_105 . V_329 ;
return V_327 != V_99 -> V_105 . V_329 ;
}
#endif
F_88 () ;
V_326 = F_89 ( V_300 -> V_326 ) ;
if ( F_90 ( ! V_326 ) )
V_123 = V_330 ;
else
V_123 = V_326 -> V_331 . V_332 -> V_123 ;
F_91 () ;
if ( ! F_84 ( V_2 , V_300 , V_14 , V_123 ) ) {
F_15 ( V_2 ,
L_75 ) ;
V_99 -> V_182 . V_328 = V_333 ;
return V_327 != V_333 ;
}
F_83 ( V_2 , V_327 , & V_313 , & V_314 ) ;
V_65 = V_6 -> V_75 ;
V_285 = V_65 [ V_327 ] . V_68 ;
V_286 = V_65 [ V_327 ] . V_71 ;
if ( V_313 != V_298 )
V_315 = V_65 [ V_313 ] . V_71 ;
if ( V_314 != V_298 )
V_316 = V_65 [ V_314 ] . V_71 ;
F_15 ( V_2 ,
L_76 ,
V_327 , V_286 , V_285 , V_313 , V_314 ,
V_315 , V_316 ) ;
V_289 = F_86 ( V_2 , V_285 , V_313 , V_314 ,
V_286 , V_315 , V_316 ) ;
if ( V_313 == V_298 && V_289 == V_320 ) {
F_15 ( V_2 , L_77 ) ;
V_289 = V_317 ;
} else if ( V_314 == V_298 &&
( V_289 == V_322 ||
V_289 == V_319 ) ) {
F_15 ( V_2 , L_78 ) ;
V_289 = V_317 ;
}
switch ( V_289 ) {
case V_320 :
V_99 -> V_182 . V_328 = V_313 ;
return true ;
case V_322 :
V_99 -> V_182 . V_328 = V_314 ;
return true ;
case V_319 :
V_99 -> V_182 . V_328 = V_333 ;
return true ;
case V_317 :
break;
}
return false ;
}
static void F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_78 * V_99 ,
int V_80 )
{
int V_143 = V_38 ;
int V_142 = V_38 ;
int V_60 ;
struct V_64 * V_65 = NULL ;
int V_286 = V_69 ;
int V_287 = V_69 ;
int V_288 = V_69 ;
T_2 V_95 ;
enum V_284 V_334 = V_290 ;
T_5 V_140 ;
T_1 V_335 = 0 ;
struct V_5 * V_6 , * V_336 ;
T_1 V_200 = 0 ;
T_1 V_337 = 0 ;
T_5 V_146 ;
T_3 V_285 ;
T_1 V_338 = V_99 -> V_248 ;
struct V_177 * V_339 = ( void * ) V_4 -> V_324 ;
struct V_340 * V_341 ;
struct V_13 * V_14 ;
V_99 -> V_248 = ! ! V_339 -> V_342 ;
if ( ! V_99 -> V_263 )
V_200 = V_99 -> V_200 ;
else
V_200 = 1 - V_99 -> V_200 ;
V_6 = & ( V_99 -> V_199 [ V_200 ] ) ;
V_14 = & V_6 -> V_14 ;
if ( V_338 != V_99 -> V_248 ) {
F_15 ( V_2 ,
L_79 ,
V_338 , V_99 -> V_248 ) ;
F_74 ( V_99 , V_6 ) ;
F_17 ( V_2 , V_6 ) ;
}
V_60 = V_99 -> V_343 ;
V_140 = F_40 ( V_99 , V_14 ) ;
if ( ! ( F_47 ( V_60 ) & V_140 ) ) {
F_22 ( V_2 , L_80 ) ;
if ( V_99 -> V_263 ) {
V_14 -> type = V_51 ;
V_99 -> V_263 = 0 ;
V_6 = & ( V_99 -> V_199 [ V_99 -> V_200 ] ) ;
F_78 ( V_2 , V_4 , V_99 , & V_6 -> V_14 ) ;
}
return;
}
if ( ! V_6 -> V_89 ) {
F_22 ( V_2 , L_81 ) ;
return;
}
V_65 = & ( V_6 -> V_74 [ V_60 ] ) ;
V_95 = V_65 -> V_70 - V_65 -> V_67 ;
if ( ( V_95 < V_97 ) &&
( V_65 -> V_67 < V_98 ) ) {
F_15 ( V_2 ,
L_82 ,
F_13 ( V_14 -> type ) ,
V_60 , V_65 -> V_67 , V_65 -> V_70 ) ;
V_65 -> V_71 = V_69 ;
F_64 ( V_99 , false ) ;
goto V_294;
}
if ( V_65 -> V_71 != ( ( V_65 -> V_68 *
V_6 -> V_89 [ V_60 ] + 64 ) / 128 ) ) {
V_65 -> V_71 = ( ( V_65 -> V_68 *
V_6 -> V_89 [ V_60 ] + 64 ) / 128 ) ;
}
if ( V_99 -> V_263 ) {
if ( V_65 -> V_71 > V_99 -> V_255 ) {
F_15 ( V_2 ,
L_83
L_84 ,
V_65 -> V_68 ,
V_65 -> V_71 ,
V_99 -> V_255 ) ;
V_99 -> V_200 = V_200 ;
V_286 = V_65 -> V_71 ;
} else {
F_15 ( V_2 ,
L_85
L_84 ,
V_65 -> V_68 ,
V_65 -> V_71 ,
V_99 -> V_255 ) ;
V_14 -> type = V_51 ;
V_200 = V_99 -> V_200 ;
V_6 = & ( V_99 -> V_199 [ V_200 ] ) ;
V_60 = V_6 -> V_14 . V_60 ;
V_286 = V_99 -> V_255 ;
V_335 = 1 ;
}
V_99 -> V_263 = 0 ;
V_337 = 1 ;
goto V_344;
}
V_146 = F_43 ( V_2 , V_60 , V_140 , V_14 -> type ) ;
V_143 = V_146 & 0xff ;
V_142 = ( V_146 >> 8 ) & 0xff ;
V_285 = V_65 -> V_68 ;
V_286 = V_65 -> V_71 ;
if ( V_143 != V_38 )
V_287 = V_6 -> V_74 [ V_143 ] . V_71 ;
if ( V_142 != V_38 )
V_288 = V_6 -> V_74 [ V_142 ] . V_71 ;
F_15 ( V_2 ,
L_86 ,
F_13 ( V_14 -> type ) , V_60 , V_286 , V_285 ,
V_143 , V_142 , V_287 , V_288 ) ;
V_334 = F_82 ( V_2 , V_6 , V_285 , V_143 , V_142 ,
V_286 , V_287 , V_288 ) ;
if ( F_92 ( V_14 ) &&
! F_3 ( V_2 , V_4 ) ) {
F_15 ( V_2 ,
L_87 ) ;
F_64 ( V_99 , true ) ;
goto V_344;
}
switch ( V_334 ) {
case V_292 :
if ( V_143 != V_38 ) {
V_335 = 1 ;
V_60 = V_143 ;
} else {
F_15 ( V_2 ,
L_88 ) ;
}
break;
case V_293 :
if ( V_142 != V_38 ) {
V_335 = 1 ;
V_60 = V_142 ;
} else {
F_15 ( V_2 ,
L_89 ) ;
}
break;
case V_290 :
if ( V_99 -> V_198 == V_204 )
V_335 = F_87 ( V_2 , V_4 , V_99 , V_6 ) ;
break;
default:
break;
}
V_344:
if ( V_335 ) {
V_6 -> V_14 . V_60 = V_60 ;
F_78 ( V_2 , V_4 , V_99 , & V_6 -> V_14 ) ;
}
F_64 ( V_99 , false ) ;
if ( ! V_335 && ! V_337 &&
V_99 -> V_198 == V_264
&& V_65 -> V_70 ) {
enum V_265 V_345 ;
V_99 -> V_255 = V_286 ;
F_15 ( V_2 ,
L_90 ,
V_335 , V_337 , V_99 -> V_198 ,
V_65 -> V_70 ) ;
V_345 = F_80 ( V_2 , V_99 , V_4 , V_6 ) ;
if ( V_345 != V_103 ) {
int V_81 = F_81 ( V_2 , V_99 , V_4 ,
V_345 ) ;
if ( ! V_81 )
V_99 -> V_263 = 1 ;
} else {
F_15 ( V_2 ,
L_91 ) ;
V_99 -> V_198 = V_346 ;
}
if ( V_99 -> V_263 ) {
V_6 = & ( V_99 -> V_199 [ ( 1 - V_99 -> V_200 ) ] ) ;
F_17 ( V_2 , V_6 ) ;
V_60 = V_6 -> V_14 . V_60 ;
F_14 ( V_2 , & V_6 -> V_14 ,
L_92 ) ;
F_79 ( V_2 , V_4 , V_99 , & V_6 -> V_14 ) ;
F_63 ( V_2 , & V_99 -> V_182 , false ) ;
} else {
V_337 = 1 ;
}
}
if ( V_337 && V_99 -> V_198 == V_346 ) {
V_336 = & ( V_99 -> V_199 [ V_99 -> V_200 ] ) ;
if ( F_31 ( & V_336 -> V_14 ) ) {
F_15 ( V_2 , L_93 ) ;
if ( V_80 != V_84 ) {
V_341 = & V_339 -> V_341 [ V_80 ] ;
if ( V_341 -> V_347 != V_348 ) {
F_15 ( V_2 ,
L_94 ,
V_80 ) ;
F_23 ( V_4 , V_80 ) ;
}
}
F_71 ( V_2 , 1 , V_99 ) ;
} else {
if ( ( V_99 -> V_255 > V_349 ) &&
( V_99 -> V_350 & ( 1 << V_80 ) ) &&
( V_80 != V_84 ) ) {
V_341 = & V_339 -> V_341 [ V_80 ] ;
if ( V_341 -> V_347 == V_348 ) {
F_15 ( V_2 ,
L_95 ,
V_80 ) ;
F_24 ( V_2 , V_80 ,
V_99 , V_4 ) ;
}
}
F_71 ( V_2 , 0 , V_99 ) ;
}
}
V_294:
V_99 -> V_343 = V_60 ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_78 * V_99 ,
enum V_122 V_123 ,
struct V_13 * V_14 )
{
int V_72 , V_351 ;
T_6 V_352 = V_353 ;
T_1 V_354 = V_41 ;
T_1 V_12 = V_2 -> V_11 -> V_12 ;
const struct V_355 * V_356 ;
for ( V_72 = 0 ; V_72 < F_11 ( V_99 -> V_105 . V_357 ) ; V_72 ++ ) {
if ( ! ( V_99 -> V_105 . V_358 & F_47 ( V_72 ) ) )
continue;
if ( V_99 -> V_105 . V_357 [ V_72 ] > V_352 ) {
V_352 = V_99 -> V_105 . V_357 [ V_72 ] ;
V_354 = F_47 ( V_72 ) ;
}
}
F_15 ( V_2 , L_96 ,
F_12 ( V_354 ) , V_352 ) ;
if ( V_354 != V_42 && V_354 != V_43 )
V_14 -> V_39 = F_50 ( V_12 ) ;
else
V_14 -> V_39 = V_354 ;
V_14 -> V_62 = false ;
V_14 -> V_63 = false ;
V_14 -> V_61 = V_148 ;
V_14 -> V_60 = F_76 ( & V_99 -> V_137 ,
V_256 ) ;
if ( V_123 == V_126 ) {
V_14 -> type = V_52 ;
V_356 = V_359 ;
V_351 = F_11 ( V_359 ) ;
} else {
V_14 -> type = V_53 ;
V_356 = V_360 ;
V_351 = F_11 ( V_360 ) ;
}
if ( V_361 ) {
for ( V_72 = 0 ; V_72 < V_351 ; V_72 ++ ) {
int V_253 = V_356 [ V_72 ] . V_253 ;
if ( ( V_352 >= V_356 [ V_72 ] . V_362 ) &&
( F_47 ( V_253 ) & V_99 -> V_137 ) ) {
V_14 -> V_60 = V_253 ;
break;
}
}
}
F_15 ( V_2 , L_97 , V_14 -> V_60 ,
F_12 ( V_14 -> V_39 ) ) ;
}
void F_94 ( struct V_1 * V_2 ,
struct V_78 * V_99 ,
struct V_363 * V_364 )
{
V_99 -> V_105 . V_358 = V_364 -> V_358 ;
V_99 -> V_105 . V_357 [ 0 ] = V_364 -> V_357 [ 0 ] ;
V_99 -> V_105 . V_357 [ 1 ] = V_364 -> V_357 [ 1 ] ;
V_99 -> V_105 . V_357 [ 2 ] = V_364 -> V_357 [ 2 ] ;
}
static void F_95 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_78 * V_99 ,
enum V_122 V_123 ,
bool V_365 )
{
struct V_5 * V_6 ;
struct V_13 * V_14 ;
T_1 V_200 = 0 ;
if ( ! V_4 || ! V_99 )
return;
if ( ! V_99 -> V_263 )
V_200 = V_99 -> V_200 ;
else
V_200 = 1 - V_99 -> V_200 ;
V_6 = & ( V_99 -> V_199 [ V_200 ] ) ;
V_14 = & V_6 -> V_14 ;
F_93 ( V_2 , V_99 , V_123 , V_14 ) ;
V_99 -> V_343 = V_14 -> V_60 ;
F_29 ( V_14 -> V_39 != V_42 && V_14 -> V_39 != V_43 ) ;
if ( V_14 -> V_39 == V_42 )
V_6 -> V_102 = V_366 ;
else
V_6 -> V_102 = V_367 ;
F_74 ( V_99 , V_6 ) ;
F_79 ( V_2 , V_4 , V_99 , V_14 ) ;
F_63 ( V_2 , & V_99 -> V_182 , V_365 ) ;
}
static void F_96 ( void * V_211 , struct V_3 * V_4 , void * V_323 ,
struct V_368 * V_369 )
{
struct V_215 * V_216 = V_369 -> V_216 ;
struct V_217 * V_218 V_370 =
(struct V_217 * ) V_211 ;
struct V_1 * V_2 V_370 = F_68 ( V_218 ) ;
struct V_163 * V_164 = F_69 ( V_216 ) ;
struct V_78 * V_99 = V_323 ;
if ( V_99 && ! V_99 -> V_105 . V_147 ) {
F_15 ( V_2 , L_28 ) ;
V_323 = NULL ;
}
if ( F_97 ( V_4 , V_323 , V_369 ) )
return;
F_98 ( V_99 -> V_209 ,
V_164 -> V_123 , & V_164 -> V_371 . V_185 [ 0 ] ) ;
V_164 -> V_371 . V_185 [ 0 ] . V_207 = 1 ;
}
static void * F_99 ( void * V_372 , struct V_3 * V_4 ,
T_8 V_373 )
{
struct V_177 * V_339 = (struct V_177 * ) V_4 -> V_324 ;
struct V_217 * V_218 = (struct V_217 * ) V_372 ;
struct V_1 * V_2 = F_68 ( V_218 ) ;
struct V_78 * V_99 = & V_339 -> V_99 ;
F_15 ( V_2 , L_98 ) ;
V_99 -> V_105 . V_147 = V_2 ;
#ifdef F_59
V_99 -> V_105 . V_179 = 0 ;
V_99 -> V_105 . V_329 = V_298 ;
#endif
V_99 -> V_105 . V_358 = 0 ;
memset ( V_99 -> V_105 . V_357 , 0 , sizeof( V_99 -> V_105 . V_357 ) ) ;
return & V_339 -> V_99 ;
}
static int F_100 ( struct V_16 * V_17 ,
int V_125 )
{
T_5 V_374 = F_101 ( V_17 -> V_375 . V_376 ) &
( 0x3 << ( 2 * ( V_125 - 1 ) ) ) ;
V_374 >>= ( 2 * ( V_125 - 1 ) ) ;
if ( V_374 == V_377 )
return V_310 ;
else if ( V_374 == V_378 )
return V_311 ;
else if ( V_374 == V_379 )
return V_149 ;
F_29 ( V_374 != V_380 ) ;
return - 1 ;
}
static void F_102 ( struct V_3 * V_4 ,
struct V_16 * V_17 ,
struct V_78 * V_99 )
{
int V_72 ;
int V_381 = F_100 ( V_17 , 1 ) ;
if ( V_381 >= V_27 ) {
for ( V_72 = V_27 ; V_72 <= V_381 ; V_72 ++ ) {
if ( V_72 == V_28 )
continue;
if ( V_72 == V_149 &&
V_4 -> V_257 == V_382 )
continue;
V_99 -> V_138 |= F_47 ( V_72 ) ;
}
}
if ( V_4 -> V_383 < 2 )
return;
V_381 = F_100 ( V_17 , 2 ) ;
if ( V_381 >= V_27 ) {
for ( V_72 = V_27 ; V_72 <= V_381 ; V_72 ++ ) {
if ( V_72 == V_28 )
continue;
if ( V_72 == V_149 &&
V_4 -> V_257 == V_382 )
continue;
V_99 -> V_139 |= F_47 ( V_72 ) ;
}
}
}
static void F_103 ( struct V_1 * V_2 ,
struct V_384 * V_385 )
{
F_104 ( & V_2 -> V_386 ) ;
memset ( V_385 , 0 , sizeof( * V_385 ) ) ;
F_105 ( & V_2 -> V_386 ) ;
}
void F_106 ( struct V_1 * V_2 ,
struct V_384 * V_385 ,
T_2 V_14 , bool V_387 )
{
T_1 V_125 = 0 , V_388 = 0 ;
F_107 ( & V_2 -> V_386 ) ;
if ( V_387 )
V_385 -> V_389 ++ ;
V_385 -> V_390 ++ ;
switch ( V_14 & V_127 ) {
case V_148 :
V_385 -> V_391 ++ ;
break;
case V_156 :
V_385 -> V_392 ++ ;
break;
case V_133 :
V_385 -> V_393 ++ ;
break;
default:
F_108 ( 1 , L_99 , V_14 ) ;
}
if ( V_14 & V_25 ) {
V_385 -> V_394 ++ ;
V_388 = V_14 & V_26 ;
V_125 = ( ( V_14 & V_128 ) >> V_129 ) + 1 ;
} else if ( V_14 & V_31 ) {
V_385 -> V_395 ++ ;
V_388 = V_14 & V_32 ;
V_125 = ( ( V_14 & V_130 ) >>
V_131 ) + 1 ;
} else {
V_385 -> V_396 ++ ;
}
if ( V_125 == 1 )
V_385 -> V_397 ++ ;
else if ( V_125 == 2 )
V_385 -> V_398 ++ ;
if ( V_14 & V_120 )
V_385 -> V_399 ++ ;
else
V_385 -> V_400 ++ ;
V_385 -> V_401 [ V_385 -> V_402 ] = V_14 ;
V_385 -> V_402 = ( V_385 -> V_402 + 1 ) %
F_11 ( V_385 -> V_401 ) ;
F_109 ( & V_2 -> V_386 ) ;
}
void F_62 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_122 V_123 , bool V_365 )
{
int V_72 , V_266 ;
struct V_403 * V_404 = V_2 -> V_404 ;
struct V_15 * V_7 = & V_4 -> V_7 ;
struct V_16 * V_17 = & V_4 -> V_17 ;
struct V_177 * V_339 ;
struct V_78 * V_99 ;
struct V_212 * V_213 ;
unsigned long V_405 ;
V_339 = (struct V_177 * ) V_4 -> V_324 ;
V_99 = & V_339 -> V_99 ;
memset ( V_99 , 0 , F_110 ( F_111 ( * V_99 ) , V_105 ) ) ;
V_213 = V_404 -> V_406 -> V_407 [ V_123 ] ;
V_99 -> V_182 . V_408 = V_339 -> V_408 ;
for ( V_266 = 0 ; V_266 < V_409 ; V_266 ++ )
F_17 ( V_2 , & V_99 -> V_199 [ V_266 ] ) ;
V_99 -> V_230 = 0 ;
V_99 -> V_190 = V_189 ;
F_15 ( V_2 ,
L_100 ,
V_339 -> V_408 ) ;
V_99 -> V_196 = V_197 ;
V_99 -> V_123 = V_213 -> V_123 ;
V_405 = V_4 -> V_210 [ V_213 -> V_123 ] ;
V_99 -> V_137 = 0 ;
F_112 (i, &supp, BITS_PER_LONG)
V_99 -> V_137 |= F_47 ( V_213 -> V_410 [ V_72 ] . V_411 ) ;
if ( ! V_17 || ! V_17 -> V_412 ) {
V_99 -> V_138 = V_7 -> V_388 . V_413 [ 0 ] << 1 ;
V_99 -> V_138 |= V_7 -> V_388 . V_413 [ 0 ] & 0x1 ;
V_99 -> V_138 &= ~ ( ( T_5 ) 0x2 ) ;
V_99 -> V_138 <<= V_184 ;
V_99 -> V_139 = V_7 -> V_388 . V_413 [ 1 ] << 1 ;
V_99 -> V_139 |= V_7 -> V_388 . V_413 [ 1 ] & 0x1 ;
V_99 -> V_139 &= ~ ( ( T_5 ) 0x2 ) ;
V_99 -> V_139 <<= V_184 ;
V_99 -> F_35 = false ;
if ( V_2 -> V_414 -> V_415 -> V_63 &&
( V_7 -> V_18 & V_416 ) )
V_99 -> V_63 = true ;
} else {
F_102 ( V_4 , V_17 , V_99 ) ;
V_99 -> F_35 = true ;
if ( V_2 -> V_414 -> V_415 -> V_63 &&
( V_17 -> V_18 & V_417 ) )
V_99 -> V_63 = true ;
}
V_99 -> V_235 = F_113 ( & V_99 -> V_137 ,
V_256 ) ;
V_99 -> V_237 = F_113 ( & V_99 -> V_138 ,
V_256 ) ;
V_99 -> V_239 = F_113 ( & V_99 -> V_139 ,
V_256 ) ;
F_15 ( V_2 ,
L_101 ,
V_99 -> V_137 ,
V_99 -> V_138 ,
V_99 -> V_139 ,
V_99 -> F_35 , V_99 -> V_63 ) ;
F_15 ( V_2 , L_102 ,
V_99 -> V_235 ,
V_99 -> V_237 ,
V_99 -> V_239 ) ;
V_99 -> V_182 . V_418 =
F_50 ( V_2 -> V_11 -> V_12 ) ;
V_99 -> V_182 . V_419 = V_44 ;
V_99 -> V_350 = V_420 ;
V_99 -> V_248 = 0 ;
#ifdef F_114
F_103 ( V_2 , & V_2 -> V_421 ) ;
#endif
F_95 ( V_2 , V_4 , V_99 , V_123 , V_365 ) ;
}
static void F_115 ( void * V_211 ,
struct V_212 * V_213 ,
struct V_422 * V_423 ,
struct V_3 * V_4 , void * V_214 ,
T_2 V_424 )
{
T_1 V_80 ;
struct V_217 * V_218 =
(struct V_217 * ) V_211 ;
struct V_1 * V_2 = F_68 ( V_218 ) ;
for ( V_80 = 0 ; V_80 < V_84 ; V_80 ++ )
F_23 ( V_4 , V_80 ) ;
F_62 ( V_2 , V_4 , V_213 -> V_123 , false ) ;
}
static void F_116 ( struct V_1 * V_2 ,
struct V_168 * V_425 ,
enum V_122 V_123 ,
T_2 V_110 )
{
struct V_13 V_14 ;
int V_72 ;
int V_426 = F_11 ( V_425 -> V_183 ) ;
T_9 V_427 = F_117 ( V_110 ) ;
T_1 V_39 = ( V_110 & V_112 ) >> V_111 ;
for ( V_72 = 0 ; V_72 < V_426 ; V_72 ++ )
V_425 -> V_183 [ V_72 ] = V_427 ;
F_38 ( V_110 , V_123 , & V_14 ) ;
if ( F_92 ( & V_14 ) )
V_425 -> V_428 = V_426 - 1 ;
else
V_425 -> V_428 = 0 ;
V_425 -> V_328 = 0 ;
if ( F_2 ( V_39 ) == 1 )
V_425 -> V_418 = V_39 ;
V_425 -> V_429 = V_430 ;
}
static void F_118 ( struct V_1 * V_2 ,
struct V_78 * V_99 ,
struct V_13 * V_14 ,
T_9 * V_183 , int * V_431 ,
int V_426 , int V_432 ,
T_1 V_12 , bool V_433 )
{
int V_72 , V_266 ;
T_9 V_110 ;
bool V_434 = false ;
int V_435 = V_14 -> V_60 ;
int V_436 = V_437 ;
int V_60 = * V_431 ;
for ( V_72 = 0 ; V_72 < V_426 && V_60 < V_436 ; V_72 ++ ) {
V_110 = F_117 ( F_30 ( V_2 , V_14 ) ) ;
for ( V_266 = 0 ; V_266 < V_432 && V_60 < V_436 ; V_266 ++ , V_60 ++ )
V_183 [ V_60 ] = V_110 ;
if ( V_433 )
F_39 ( V_12 , V_14 ) ;
V_435 = V_14 -> V_60 ;
V_434 = F_48 ( V_99 , V_14 ) ;
if ( V_434 && ! F_31 ( V_14 ) )
break;
}
if ( ! V_434 )
V_14 -> V_60 = V_435 ;
* V_431 = V_60 ;
}
static void F_119 ( struct V_1 * V_2 ,
struct V_78 * V_99 ,
const struct V_13 * V_438 )
{
struct V_13 V_14 ;
int V_426 , V_432 , V_60 = 0 ;
T_1 V_12 = 0 ;
struct V_168 * V_425 = & V_99 -> V_182 ;
bool V_433 = false ;
memcpy ( & V_14 , V_438 , sizeof( V_14 ) ) ;
V_12 = V_2 -> V_11 -> V_12 ;
if ( F_41 ( & V_14 ) ) {
V_426 = V_439 ;
V_432 = V_440 ;
} else if ( F_92 ( & V_14 ) ) {
V_426 = V_441 ;
V_432 = V_440 ;
} else {
V_426 = V_442 ;
V_432 = V_443 ;
V_433 = true ;
}
F_118 ( V_2 , V_99 , & V_14 , V_425 -> V_183 , & V_60 ,
V_426 , V_432 , V_12 ,
V_433 ) ;
F_49 ( V_99 , & V_14 ) ;
if ( F_41 ( & V_14 ) ) {
V_426 = V_444 ;
V_432 = V_445 ;
V_425 -> V_428 = V_60 ;
} else if ( F_31 ( & V_14 ) ) {
V_426 = V_446 ;
V_432 = V_443 ;
} else {
F_29 ( 1 ) ;
}
V_433 = true ;
F_118 ( V_2 , V_99 , & V_14 , V_425 -> V_183 , & V_60 ,
V_426 , V_432 , V_12 ,
V_433 ) ;
F_49 ( V_99 , & V_14 ) ;
V_426 = V_446 ;
V_432 = V_443 ;
F_118 ( V_2 , V_99 , & V_14 , V_425 -> V_183 , & V_60 ,
V_426 , V_432 , V_12 ,
V_433 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_78 * V_99 ,
const struct V_13 * V_438 )
{
struct V_168 * V_425 = & V_99 -> V_182 ;
struct V_177 * V_178 ;
struct V_447 * V_448 ;
V_425 -> V_449 = V_450 ;
V_425 -> V_451 =
F_120 ( V_452 ) ;
#ifdef F_59
if ( V_99 -> V_105 . V_179 ) {
F_116 ( V_2 , V_425 ,
V_99 -> V_123 ,
V_99 -> V_105 . V_179 ) ;
return;
}
#endif
if ( F_29 ( ! V_4 || ! V_438 ) )
return;
F_119 ( V_2 , V_99 , V_438 ) ;
if ( F_2 ( V_438 -> V_39 ) == 1 )
V_425 -> V_418 = V_438 -> V_39 ;
V_178 = F_58 ( V_4 ) ;
V_448 = F_121 ( V_178 -> V_300 ) ;
if ( F_2 ( V_438 -> V_39 ) == 1 )
V_425 -> V_418 = V_438 -> V_39 ;
V_425 -> V_429 = V_178 -> V_453 ;
if ( F_122 ( V_448 ) ) {
V_425 -> V_429 -- ;
if ( V_2 -> V_454 )
V_425 -> V_429 =
F_65 ( V_425 -> V_429 ,
V_2 -> V_454 ) ;
}
if ( V_178 -> V_300 -> V_455 )
V_425 -> V_154 |= V_456 ;
V_425 -> V_451 =
F_120 ( F_123 ( V_2 , V_4 ) ) ;
}
static void * F_124 ( struct V_403 * V_404 , struct V_457 * V_458 )
{
return V_404 -> V_459 ;
}
static void F_125 ( void * V_372 )
{
return;
}
static void F_126 ( void * V_211 , struct V_3 * V_4 ,
void * V_323 )
{
struct V_217 * V_218 V_370 = V_211 ;
struct V_1 * V_2 V_370 = F_68 ( V_218 ) ;
F_15 ( V_2 , L_103 ) ;
F_15 ( V_2 , L_104 ) ;
}
int F_127 ( char * V_460 , const T_2 V_14 )
{
char * type , * V_61 ;
T_1 V_388 = 0 , V_125 = 0 ;
T_1 V_39 = ( V_14 & V_112 ) >> V_111 ;
if ( ! ( V_14 & V_25 ) &&
! ( V_14 & V_31 ) ) {
int V_60 = F_10 ( V_14 ) ;
return sprintf ( V_460 , L_105 ,
F_12 ( V_39 ) ,
V_60 == V_38 ? L_106 :
V_461 [ V_60 ] . V_462 ) ;
}
if ( V_14 & V_31 ) {
type = L_107 ;
V_388 = V_14 & V_32 ;
V_125 = ( ( V_14 & V_130 )
>> V_131 ) + 1 ;
} else if ( V_14 & V_25 ) {
type = L_108 ;
V_388 = V_14 & V_463 ;
} else {
type = L_109 ;
}
switch ( V_14 & V_127 ) {
case V_148 :
V_61 = L_110 ;
break;
case V_156 :
V_61 = L_111 ;
break;
case V_133 :
V_61 = L_112 ;
break;
case V_132 :
V_61 = L_113 ;
break;
default:
V_61 = L_114 ;
}
return sprintf ( V_460 , L_115 ,
type , F_12 ( V_39 ) , V_61 , V_388 , V_125 ,
( V_14 & V_120 ) ? L_116 : L_117 ,
( V_14 & V_464 ) ? L_118 : L_119 ,
( V_14 & V_121 ) ? L_120 : L_119 ,
( V_14 & V_465 ) ? L_121 : L_119 ,
( V_14 & V_466 ) ? L_122 : L_119 ) ;
}
static void F_128 ( struct V_1 * V_2 ,
struct V_78 * V_99 )
{
V_99 -> V_137 = 0x0FFF ;
V_99 -> V_138 = 0x1FD0 ;
V_99 -> V_139 = 0x1FD0 ;
F_15 ( V_2 , L_123 ,
V_99 -> V_182 . V_408 , V_99 -> V_105 . V_179 ) ;
if ( V_99 -> V_105 . V_179 ) {
F_79 ( V_2 , NULL , V_99 , NULL ) ;
F_63 ( V_99 -> V_105 . V_147 , & V_99 -> V_182 , false ) ;
}
}
static T_10 F_129 ( struct V_467 * V_467 ,
const char T_11 * V_468 , T_12 V_207 , T_13 * V_469 )
{
struct V_78 * V_99 = V_467 -> V_470 ;
struct V_1 * V_2 ;
char V_460 [ 64 ] ;
T_12 V_471 ;
T_2 V_472 ;
V_2 = V_99 -> V_105 . V_147 ;
memset ( V_460 , 0 , sizeof( V_460 ) ) ;
V_471 = F_65 ( V_207 , sizeof( V_460 ) - 1 ) ;
if ( F_130 ( V_460 , V_468 , V_471 ) )
return - V_473 ;
if ( sscanf ( V_460 , L_124 , & V_472 ) == 1 )
V_99 -> V_105 . V_179 = V_472 ;
else
V_99 -> V_105 . V_179 = 0 ;
F_128 ( V_2 , V_99 ) ;
return V_207 ;
}
static T_10 F_131 ( struct V_467 * V_467 ,
char T_11 * V_468 , T_12 V_207 , T_13 * V_469 )
{
char * V_474 ;
int V_475 = 0 ;
int V_72 = 0 ;
T_10 V_81 ;
struct V_78 * V_99 = V_467 -> V_470 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = & ( V_99 -> V_199 [ V_99 -> V_200 ] ) ;
struct V_13 * V_14 = & V_6 -> V_14 ;
V_2 = V_99 -> V_105 . V_147 ;
V_474 = F_132 ( 2048 , V_476 ) ;
if ( ! V_474 )
return - V_477 ;
V_475 += sprintf ( V_474 + V_475 , L_125 , V_99 -> V_182 . V_408 ) ;
V_475 += sprintf ( V_474 + V_475 , L_126 ,
V_99 -> V_206 , V_99 -> V_205 ,
V_99 -> V_137 ) ;
V_475 += sprintf ( V_474 + V_475 , L_127 ,
V_99 -> V_105 . V_179 ) ;
V_475 += sprintf ( V_474 + V_475 , L_128 ,
( V_2 -> V_11 -> V_12 & V_42 ) ? L_129 : L_119 ,
( V_2 -> V_11 -> V_12 & V_43 ) ? L_130 : L_119 ,
( V_2 -> V_11 -> V_12 & V_45 ) ? L_131 : L_119 ) ;
V_475 += sprintf ( V_474 + V_475 , L_132 ,
( F_31 ( V_14 ) ) ? L_133 :
F_35 ( V_14 ) ? L_107 : L_108 ) ;
if ( ! F_31 ( V_14 ) ) {
V_475 += sprintf ( V_474 + V_475 , L_134 ,
( F_41 ( V_14 ) ) ? L_135 : L_136 ) ;
V_475 += sprintf ( V_474 + V_475 , L_134 ,
( F_6 ( V_14 ) ) ? L_137 :
( F_7 ( V_14 ) ) ? L_138 :
( F_8 ( V_14 ) ) ? L_112 : L_114 ) ;
V_475 += sprintf ( V_474 + V_475 , L_139 ,
( V_14 -> V_62 ) ? L_140 : L_141 ,
( V_14 -> V_63 ) ? L_142 : L_143 ,
( V_99 -> V_248 ) ? L_144 : L_119 ) ;
}
V_475 += sprintf ( V_474 + V_475 , L_145 ,
V_99 -> V_209 ) ;
V_475 += sprintf ( V_474 + V_475 ,
L_146 ,
V_99 -> V_182 . V_154 ,
V_99 -> V_182 . V_428 ,
V_99 -> V_182 . V_418 ,
V_99 -> V_182 . V_419 ) ;
V_475 += sprintf ( V_474 + V_475 ,
L_147 ,
F_101 ( V_99 -> V_182 . V_451 ) ,
V_99 -> V_182 . V_449 ,
V_99 -> V_182 . V_429 ) ;
V_475 += sprintf ( V_474 + V_475 , L_148 , V_99 -> V_182 . V_328 ) ;
V_475 += sprintf ( V_474 + V_475 ,
L_149 ,
V_99 -> V_182 . V_478 [ 0 ] ,
V_99 -> V_182 . V_478 [ 1 ] ,
V_99 -> V_182 . V_478 [ 2 ] ,
V_99 -> V_182 . V_478 [ 3 ] ) ;
for ( V_72 = 0 ; V_72 < V_437 ; V_72 ++ ) {
T_2 V_479 = F_60 ( V_99 -> V_182 . V_183 [ V_72 ] ) ;
V_475 += sprintf ( V_474 + V_475 , L_150 , V_72 , V_479 ) ;
V_475 += F_127 ( V_474 + V_475 , V_479 ) ;
}
V_81 = F_133 ( V_468 , V_207 , V_469 , V_474 , V_475 ) ;
F_134 ( V_474 ) ;
return V_81 ;
}
static T_10 F_135 ( struct V_467 * V_467 ,
char T_11 * V_468 , T_12 V_207 , T_13 * V_469 )
{
char * V_474 ;
int V_475 = 0 ;
int V_72 , V_266 ;
T_10 V_81 ;
struct V_5 * V_6 ;
struct V_13 * V_14 ;
struct V_78 * V_99 = V_467 -> V_470 ;
V_474 = F_132 ( 1024 , V_476 ) ;
if ( ! V_474 )
return - V_477 ;
for ( V_72 = 0 ; V_72 < V_409 ; V_72 ++ ) {
V_6 = & ( V_99 -> V_199 [ V_72 ] ) ;
V_14 = & V_6 -> V_14 ;
V_475 += sprintf ( V_474 + V_475 ,
L_151
L_152 ,
V_99 -> V_200 == V_72 ? L_153 : L_154 ,
V_14 -> type ,
V_14 -> V_62 ,
F_6 ( V_14 ) ? L_110 :
F_7 ( V_14 ) ? L_111 :
F_8 ( V_14 ) ? L_112 : L_155 ,
V_14 -> V_60 ) ;
for ( V_266 = 0 ; V_266 < V_73 ; V_266 ++ ) {
V_475 += sprintf ( V_474 + V_475 ,
L_156 ,
V_6 -> V_74 [ V_266 ] . V_70 ,
V_6 -> V_74 [ V_266 ] . V_67 ,
V_6 -> V_74 [ V_266 ] . V_68 ) ;
}
}
V_81 = F_133 ( V_468 , V_207 , V_469 , V_474 , V_475 ) ;
F_134 ( V_474 ) ;
return V_81 ;
}
static T_10 F_136 ( struct V_467 * V_467 ,
char T_11 * V_468 ,
T_12 V_207 , T_13 * V_469 )
{
static const char * const V_480 [] = {
[ V_366 ] = L_157 ,
[ V_367 ] = L_158 ,
[ V_481 ] = L_159 ,
[ V_482 ] = L_160 ,
[ V_483 ] = L_161 ,
[ V_484 ] = L_162 ,
[ V_485 ] = L_136 ,
[ V_486 ] = L_163 ,
} ;
static const char * const V_487 [] = {
[ V_488 ] = L_164 ,
[ V_489 ] = L_165 ,
[ V_490 ] = L_166 ,
[ V_491 ] = L_167 ,
[ V_492 ] = L_168 ,
[ V_28 ] = L_169 ,
[ V_493 ] = L_170 ,
[ V_494 ] = L_171 ,
[ V_495 ] = L_172 ,
[ V_496 ] = L_173 ,
[ V_497 ] = L_174 ,
[ V_309 ] = L_175 ,
[ V_310 ] = L_176 ,
[ V_311 ] = L_177 ,
[ V_149 ] = L_178 ,
} ;
char * V_474 , * V_498 , * V_499 ;
int V_500 , V_14 ;
T_10 V_81 ;
struct V_78 * V_99 = V_467 -> V_470 ;
struct V_501 * V_385 ;
static const T_12 V_502 = 1024 ;
V_474 = F_132 ( V_502 , V_476 ) ;
if ( ! V_474 )
return - V_477 ;
V_498 = V_474 ;
V_499 = V_498 + V_502 ;
V_498 += F_137 ( V_498 , V_499 - V_498 , L_179 ) ;
for ( V_14 = 0 ; V_14 < V_73 ; V_14 ++ )
V_498 += F_137 ( V_498 , V_499 - V_498 , L_180 , V_487 [ V_14 ] ) ;
V_498 += F_137 ( V_498 , V_499 - V_498 , L_181 ) ;
for ( V_500 = 0 ; V_500 < V_503 ; V_500 ++ ) {
V_498 += F_137 ( V_498 , V_499 - V_498 ,
L_180 , V_480 [ V_500 ] ) ;
for ( V_14 = 0 ; V_14 < V_73 ; V_14 ++ ) {
V_385 = & ( V_99 -> V_105 . V_106 [ V_500 ] [ V_14 ] ) ;
V_498 += F_137 ( V_498 , V_499 - V_498 ,
L_182 ,
V_385 -> V_108 ,
V_385 -> V_107 ) ;
}
V_498 += F_137 ( V_498 , V_499 - V_498 , L_181 ) ;
}
V_81 = F_133 ( V_468 , V_207 , V_469 , V_474 , V_498 - V_474 ) ;
F_134 ( V_474 ) ;
return V_81 ;
}
static T_10 F_138 ( struct V_467 * V_467 ,
const char T_11 * V_468 ,
T_12 V_207 , T_13 * V_469 )
{
struct V_78 * V_99 = V_467 -> V_470 ;
memset ( V_99 -> V_105 . V_106 , 0 , sizeof( V_99 -> V_105 . V_106 ) ) ;
return V_207 ;
}
static void F_139 ( void * V_2 , void * V_323 , struct V_457 * V_504 )
{
struct V_78 * V_99 = V_323 ;
F_140 ( L_183 , V_505 | V_506 , V_504 ,
V_99 , & V_507 ) ;
F_140 ( L_184 , V_505 , V_504 ,
V_99 , & V_508 ) ;
F_140 ( L_185 , V_505 | V_506 , V_504 ,
V_99 , & V_509 ) ;
F_141 ( L_186 , V_505 | V_506 , V_504 ,
& V_99 -> V_350 ) ;
F_141 ( L_187 , V_505 | V_506 , V_504 ,
& V_99 -> V_105 . V_329 ) ;
}
static void F_142 ( void * V_2 , void * V_323 )
{
}
static void F_143 ( void * V_211 ,
struct V_212 * V_213 ,
struct V_422 * V_423 ,
struct V_3 * V_4 , void * V_323 )
{
}
int F_144 ( void )
{
return F_145 ( & V_510 ) ;
}
void F_146 ( void )
{
F_147 ( & V_510 ) ;
}
int F_148 ( struct V_1 * V_2 , struct V_177 * V_178 ,
bool V_511 )
{
struct V_168 * V_182 = & V_178 -> V_99 . V_182 ;
F_149 ( & V_2 -> V_512 ) ;
if ( V_511 ) {
if ( V_178 -> V_513 == 0 )
V_182 -> V_154 |= V_456 ;
V_178 -> V_513 ++ ;
} else {
V_178 -> V_513 -- ;
if ( V_178 -> V_513 == 0 )
V_182 -> V_154 &= ~ V_456 ;
}
return F_63 ( V_2 , V_182 , false ) ;
}
