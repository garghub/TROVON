static inline void F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( V_2 -> V_3 ) ;
}
static inline void F_3 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_4 ( V_2 -> V_3 ) ;
}
static inline void F_5 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_6 ( V_2 -> V_3 ) ;
}
static inline void F_7 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_8 ( V_2 -> V_3 ) ;
}
static inline void F_9 ( const struct V_1 * V_2 , bool V_4 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 ( V_2 , V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 , bool V_4 )
{
T_1 V_6 = V_2 -> V_7 ( V_2 , V_8 ) & ~ V_9 ;
if ( V_4 )
V_6 |= V_9 ;
V_2 -> V_10 ( V_2 , V_8 , V_6 ) ;
}
static void F_11 ( struct V_11 * V_12 , int V_13 , T_1 V_14 , T_1 V_15 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_16 , V_17 = F_13 ( V_18 , V_13 ) ;
V_2 -> V_19 ( V_2 , V_17 , ( V_14 << 16 ) | V_15 ) ;
for ( V_16 = V_20 ; V_16 ; V_16 -- ) {
if ( ! ( V_2 -> V_7 ( V_2 , V_17 ) & V_21 ) )
return;
F_14 ( 1 ) ;
}
F_15 ( V_12 , L_1 ) ;
}
static inline void F_16 ( struct V_11 * V_12 , int V_13 ,
T_1 V_15 , T_1 V_14 )
{
F_11 ( V_12 , V_13 , V_14 , V_15 ) ;
}
static inline void F_17 ( struct V_11 * V_12 , int V_13 ,
T_1 V_15 , T_1 V_14 )
{
F_11 ( V_12 , V_13 , V_14 | V_22 , V_15 ) ;
}
static void F_18 ( struct V_11 * V_12 , int V_13 , int V_15 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
V_2 -> V_10 ( V_2 , F_13 ( V_23 , V_13 ) , 0 ) ;
F_17 ( V_12 , V_13 , V_15 , V_24 ) ;
}
static void F_19 ( struct V_11 * V_12 , int V_13 , int V_15 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
V_2 -> V_10 ( V_2 , F_13 ( V_25 , V_13 ) , 0 ) ;
V_2 -> V_10 ( V_2 , F_13 ( V_26 , V_13 ) , 0 ) ;
F_18 ( V_12 , V_13 , V_15 ) ;
}
static void F_20 ( struct V_11 * V_12 , int V_13 ,
struct V_27 * V_28 , int V_29 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
T_2 V_6 = V_30 | V_28 -> V_31 ;
bool V_32 = V_28 -> V_33 & V_34 ;
T_1 V_35 = V_36 ;
int V_37 ;
if ( V_28 -> V_33 & V_38 ) {
V_35 |= V_28 -> V_33 & V_39 ;
V_35 |= V_40 ;
} else {
V_35 |= ( V_28 -> V_33 & V_41 ) << 18 ;
}
if ( ! V_32 )
V_35 |= V_42 ;
if ( V_32 != ( bool ) F_21 ( V_29 , & V_2 -> V_43 ) ) {
T_1 V_15 = V_29 + V_44 ;
F_19 ( V_12 , V_13 , V_15 ) ;
F_22 ( V_29 , & V_2 -> V_43 ) ;
}
V_2 -> V_19 ( V_2 , F_13 ( V_25 , V_13 ) , V_35 ) ;
V_2 -> V_10 ( V_2 , F_13 ( V_23 , V_13 ) , V_6 ) ;
for ( V_37 = 0 ; V_37 < V_28 -> V_31 ; V_37 += 2 ) {
V_2 -> V_10 ( V_2 , F_13 ( V_45 , V_13 ) + V_37 / 2 ,
V_28 -> V_46 [ V_37 ] | ( V_28 -> V_46 [ V_37 + 1 ] << 8 ) ) ;
}
}
static inline void F_23 ( struct V_11 * V_12 ,
int V_13 )
{
int V_37 ;
for ( V_37 = V_47 ; V_37 <= V_48 ; V_37 ++ )
F_16 ( V_12 , V_13 , V_37 , V_49 ) ;
}
static int F_24 ( struct V_11 * V_12 ,
int V_13 , int V_50 , T_1 V_6 )
{
struct V_51 * V_52 = & V_12 -> V_52 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
struct V_27 * V_28 ;
struct V_53 * V_54 ;
V_6 &= ~ ( V_55 | V_56 | V_57 ) ;
V_2 -> V_10 ( V_2 , F_13 ( V_23 , V_13 ) , V_6 ) ;
F_17 ( V_12 , V_13 , V_50 , V_58 ) ;
V_52 -> V_59 ++ ;
V_52 -> V_60 ++ ;
V_54 = F_25 ( V_12 , & V_28 ) ;
if ( F_26 ( ! V_54 ) )
return 0 ;
V_28 -> V_33 |= V_61 ;
V_28 -> V_46 [ 1 ] = V_62 ;
F_27 ( V_54 ) ;
return 1 ;
}
static int F_28 ( struct V_11 * V_12 , int V_13 , T_1 V_6 )
{
struct V_51 * V_52 = & V_12 -> V_52 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
struct V_27 * V_28 ;
struct V_53 * V_54 ;
T_1 V_35 , V_46 ;
V_54 = F_29 ( V_12 , & V_28 ) ;
if ( ! V_54 ) {
V_52 -> V_63 ++ ;
return - V_64 ;
}
V_28 -> V_31 = F_30 ( V_6 & 0x0F ) ;
V_35 = V_2 -> V_65 ( V_2 , F_13 ( V_25 , V_13 ) ) ;
if ( V_35 & V_40 )
V_28 -> V_33 = ( V_35 & V_39 ) | V_38 ;
else
V_28 -> V_33 = ( V_35 >> 18 ) & V_41 ;
if ( V_35 & V_42 ) {
V_28 -> V_33 |= V_34 ;
} else {
int V_37 , V_66 = F_13 ( V_45 , V_13 ) ;
for ( V_37 = 0 ; V_37 < V_28 -> V_31 ; V_37 += 2 , V_66 ++ ) {
V_46 = V_2 -> V_7 ( V_2 , V_66 ) ;
V_28 -> V_46 [ V_37 ] = V_46 ;
V_28 -> V_46 [ V_37 + 1 ] = V_46 >> 8 ;
}
}
V_52 -> V_67 ++ ;
V_52 -> V_68 += V_28 -> V_31 ;
F_27 ( V_54 ) ;
return 0 ;
}
static void F_31 ( struct V_11 * V_12 , int V_13 ,
T_1 V_15 , T_1 V_69 , T_1 V_70 , T_1 V_71 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
V_69 |= F_32 ( 29 ) ;
V_2 -> V_19 ( V_2 , F_13 ( V_72 , V_13 ) , V_69 ) ;
V_70 |= V_36 ;
V_2 -> V_19 ( V_2 , F_13 ( V_25 , V_13 ) , V_70 ) ;
V_2 -> V_10 ( V_2 , F_13 ( V_23 , V_13 ) , V_71 ) ;
F_17 ( V_12 , V_13 , V_15 , V_73 ) ;
}
static T_3 F_33 ( struct V_53 * V_54 ,
struct V_11 * V_12 )
{
struct V_27 * V_28 = (struct V_27 * ) V_54 -> V_46 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
T_1 V_29 , V_15 ;
if ( F_34 ( V_12 , V_54 ) )
return V_74 ;
V_29 = F_35 ( F_36 ( & V_2 -> V_75 ) ) ;
V_15 = V_29 + V_44 ;
if ( V_29 == V_76 - 1 )
F_37 ( V_12 ) ;
F_20 ( V_12 , V_77 , V_28 , V_29 ) ;
V_2 -> V_78 [ V_29 ] = V_28 -> V_31 ;
F_38 ( V_54 , V_12 , V_29 ) ;
F_39 ( ( 1 << V_29 ) , & V_2 -> V_75 ) ;
F_17 ( V_12 , V_77 , V_15 , V_79 ) ;
return V_74 ;
}
static int F_40 ( struct V_11 * V_12 ,
struct V_1 * V_2 , T_1 V_80 )
{
int V_81 = 0 ;
while ( V_80 != ( V_2 -> V_7 ( V_2 , V_8 ) & V_82 ) ) {
F_14 ( 10 ) ;
if ( V_81 ++ > 1000 ) {
F_15 ( V_12 , L_2 ) ;
return - V_83 ;
}
}
return 0 ;
}
static int F_41 ( struct V_11 * V_12 )
{
unsigned int V_84 , V_85 , V_86 ;
T_4 V_87 , V_88 , V_89 , V_90 , V_91 ;
T_1 V_92 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
const struct V_93 * V_94 = & V_2 -> V_95 . V_96 ;
int V_97 ;
V_92 = V_94 -> V_87 - 1 ;
V_87 = V_92 & V_98 ;
V_88 = V_92 >> 6 ;
V_89 = V_94 -> V_89 - 1 ;
V_90 = V_94 -> V_99 + V_94 -> V_100 - 1 ;
V_91 = V_94 -> V_101 - 1 ;
V_84 = V_87 | ( V_89 << V_102 ) | ( V_90 << V_103 ) |
( V_91 << V_104 ) ;
V_85 = V_88 & V_105 ;
F_42 ( V_12 ,
L_3 , V_84 , V_85 ) ;
V_86 = V_2 -> V_7 ( V_2 , V_8 ) ;
V_86 &= ~ V_82 ;
V_2 -> V_10 ( V_2 , V_8 , V_106 | V_82 ) ;
V_97 = F_40 ( V_12 , V_2 , V_82 ) ;
if ( V_97 )
return V_97 ;
V_2 -> V_10 ( V_2 , V_107 , V_84 ) ;
V_2 -> V_10 ( V_2 , V_108 , V_85 ) ;
V_2 -> V_10 ( V_2 , V_8 , V_86 ) ;
return F_40 ( V_12 , V_2 , 0 ) ;
}
static void F_43 ( struct V_11 * V_12 )
{
int V_37 ;
for ( V_37 = V_47 ; V_37 <= V_109 ; V_37 ++ )
F_19 ( V_12 , V_110 , V_37 ) ;
for ( V_37 = V_47 ; V_37 < V_111 ; V_37 ++ )
F_31 ( V_12 , V_110 , V_37 , 0 , 0 , V_112 ) ;
F_31 ( V_12 , V_110 , V_111 , 0 , 0 ,
V_113 ) ;
}
static int F_44 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
V_2 -> V_10 ( V_2 , V_8 , V_114 ) ;
if ( ( V_2 -> V_95 . V_115 & V_116 ) &&
( V_2 -> V_95 . V_115 & V_117 ) ) {
V_2 -> V_10 ( V_2 , V_8 , V_118 ) ;
V_2 -> V_10 ( V_2 , V_119 , V_120 | V_121 ) ;
} else if ( V_2 -> V_95 . V_115 & V_117 ) {
V_2 -> V_10 ( V_2 , V_8 , V_118 ) ;
V_2 -> V_10 ( V_2 , V_119 , V_120 ) ;
} else if ( V_2 -> V_95 . V_115 & V_116 ) {
V_2 -> V_10 ( V_2 , V_8 , V_118 ) ;
V_2 -> V_10 ( V_2 , V_119 , V_121 ) ;
}
F_43 ( V_12 ) ;
V_2 -> V_10 ( V_2 , V_122 , V_123 ) ;
F_45 ( & V_2 -> V_75 , 0 ) ;
V_2 -> V_124 = 0 ;
V_2 -> V_43 = 0 ;
return F_41 ( V_12 ) ;
}
static int F_46 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_125 ;
struct V_126 * V_127 ;
V_125 = F_44 ( V_12 ) ;
if ( V_125 )
return V_125 ;
V_2 -> V_128 = V_2 -> type != V_129 ?
V_130 : V_131 ;
V_2 -> V_95 . V_132 = V_133 ;
V_127 = F_47 ( V_2 -> V_3 , L_4 ) ;
if ( ! F_48 ( V_127 ) )
F_49 ( V_127 ) ;
else
F_50 ( V_2 -> V_3 ) ;
return 0 ;
}
static void F_51 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_10 ( V_2 , false ) ;
V_2 -> V_10 ( V_2 , V_8 , V_82 ) ;
F_52 ( V_12 -> V_12 . V_134 ) ;
V_2 -> V_95 . V_132 = V_135 ;
}
static int F_53 ( struct V_11 * V_12 , enum V_136 V_137 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_125 ;
switch ( V_137 ) {
case V_138 :
V_125 = F_46 ( V_12 ) ;
if ( V_125 )
return V_125 ;
F_54 ( V_12 ) ;
F_10 ( V_2 , true ) ;
break;
default:
return - V_139 ;
}
return 0 ;
}
static int F_55 ( const struct V_11 * V_12 ,
struct V_140 * V_141 )
{
unsigned int V_142 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
V_142 = V_2 -> V_7 ( V_2 , V_143 ) ;
V_141 -> V_144 = ( V_142 & V_145 ) >>
V_146 ;
V_141 -> V_147 = V_142 & V_148 ;
return 0 ;
}
static int F_56 ( const struct V_11 * V_12 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_125 ;
F_5 ( V_2 ) ;
V_125 = F_55 ( V_12 , V_141 ) ;
F_7 ( V_2 ) ;
return V_125 ;
}
static void F_57 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
struct V_51 * V_52 = & V_12 -> V_52 ;
T_1 V_29 , V_15 , V_149 = 0 , V_150 = 0 , V_151 , V_152 ;
V_152 = V_151 = V_2 -> V_7 ( V_2 , V_153 ) ;
while ( ( V_29 = F_58 ( V_151 ) ) ) {
V_29 -- ;
V_151 &= ~ ( 1 << V_29 ) ;
V_15 = V_29 + V_44 ;
F_18 ( V_12 , V_110 , V_15 ) ;
F_59 ( V_12 , V_29 ) ;
V_150 += V_2 -> V_78 [ V_29 ] ;
V_149 ++ ;
}
F_60 ( V_152 , & V_2 -> V_75 ) ;
if ( V_152 & ( 1 << ( V_76 - 1 ) ) )
F_54 ( V_12 ) ;
if ( V_149 ) {
V_52 -> V_154 += V_150 ;
V_52 -> V_155 += V_149 ;
F_61 ( V_12 , V_156 ) ;
}
}
static T_1 F_62 ( T_1 V_151 )
{
T_1 V_157 , V_158 ;
if ( V_151 == V_159 )
return V_151 ;
V_157 = F_63 ( V_151 ) ;
V_158 = F_35 ( V_151 ) ;
if ( V_158 == V_157 )
return V_151 ;
for ( V_158 -- ; V_151 & ( 1 << ( V_158 - 1 ) ) ; V_158 -- ) ;
return V_151 & ~ ( ( 1 << V_158 ) - 1 ) ;
}
static inline void F_64 ( struct V_11 * V_12 ,
struct V_1 * V_2 , T_1 V_15 )
{
F_16 ( V_12 , V_110 , V_15 , V_2 -> V_128 ) ;
}
static inline void F_65 ( struct V_11 * V_12 ,
struct V_1 * V_2 , T_1 V_15 )
{
if ( V_2 -> type != V_129 )
F_16 ( V_12 , V_110 , V_15 , V_49 ) ;
}
static int F_66 ( struct V_11 * V_12 , struct V_1 * V_2 ,
T_1 V_151 , int V_160 )
{
T_1 V_149 = 0 , V_6 , V_15 ;
while ( ( V_15 = F_58 ( V_151 ) ) && V_160 > 0 ) {
V_151 &= ~ F_32 ( V_15 - 1 ) ;
F_64 ( V_12 , V_2 , V_15 ) ;
V_6 = V_2 -> V_7 ( V_2 , F_13 ( V_23 , V_110 ) ) ;
if ( V_6 & V_55 ) {
int V_161 = F_24 ( V_12 , V_110 , V_15 , V_6 ) ;
V_149 += V_161 ;
V_160 -= V_161 ;
continue;
}
if ( ! ( V_6 & V_57 ) )
continue;
F_28 ( V_12 , V_110 , V_6 ) ;
F_65 ( V_12 , V_2 , V_15 ) ;
V_149 ++ ;
V_160 -- ;
}
return V_149 ;
}
static inline T_1 F_67 ( struct V_1 * V_2 )
{
T_1 V_151 = V_2 -> V_7 ( V_2 , V_162 ) ;
return V_151 ;
}
static int F_68 ( struct V_11 * V_12 , int V_160 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
T_1 V_149 = 0 , V_151 = 0 , V_163 , V_161 ;
F_69 ( V_111 > 16 ,
L_5 ) ;
while ( V_160 > 0 ) {
if ( ! V_151 ) {
V_151 = F_67 ( V_2 ) ;
if ( ! V_151 )
break;
V_163 = F_62 ( V_151 ) ;
} else {
V_163 = V_151 ;
}
V_151 &= ~ V_163 ;
V_161 = F_66 ( V_12 , V_2 , V_163 , V_160 ) ;
V_149 += V_161 ;
V_160 -= V_161 ;
}
if ( V_149 )
F_61 ( V_12 , V_164 ) ;
return V_149 ;
}
static int F_70 ( struct V_11 * V_12 ,
enum V_165 V_166 )
{
unsigned int V_142 ;
unsigned int V_167 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
struct V_51 * V_52 = & V_12 -> V_52 ;
struct V_27 * V_168 ;
struct V_53 * V_54 ;
struct V_140 V_141 ;
switch ( V_166 ) {
case V_169 :
V_2 -> V_95 . V_170 . V_171 ++ ;
V_2 -> V_95 . V_132 = V_172 ;
break;
case V_173 :
V_2 -> V_95 . V_170 . V_174 ++ ;
V_2 -> V_95 . V_132 = V_175 ;
break;
case V_176 :
V_2 -> V_95 . V_132 = V_177 ;
V_2 -> V_95 . V_170 . V_178 ++ ;
break;
default:
break;
}
V_54 = F_25 ( V_12 , & V_168 ) ;
if ( F_26 ( ! V_54 ) )
return 0 ;
F_55 ( V_12 , & V_141 ) ;
V_142 = V_2 -> V_7 ( V_2 , V_143 ) ;
V_167 = ( V_142 & V_179 ) >>
V_180 ;
switch ( V_166 ) {
case V_169 :
V_168 -> V_33 |= V_61 ;
V_168 -> V_46 [ 1 ] = ( V_141 . V_147 > V_141 . V_144 ) ?
V_181 :
V_182 ;
V_168 -> V_46 [ 6 ] = V_141 . V_147 ;
V_168 -> V_46 [ 7 ] = V_141 . V_144 ;
break;
case V_173 :
V_168 -> V_33 |= V_61 ;
if ( V_167 )
V_168 -> V_46 [ 1 ] |= V_183 ;
if ( V_141 . V_147 > 127 )
V_168 -> V_46 [ 1 ] |= V_184 ;
V_168 -> V_46 [ 6 ] = V_141 . V_147 ;
V_168 -> V_46 [ 7 ] = V_141 . V_144 ;
break;
case V_176 :
V_168 -> V_33 |= V_185 ;
F_71 ( V_12 ) ;
break;
default:
break;
}
V_52 -> V_67 ++ ;
V_52 -> V_68 += V_168 -> V_31 ;
F_27 ( V_54 ) ;
return 1 ;
}
static int F_72 ( struct V_11 * V_12 ,
enum V_186 V_187 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
struct V_51 * V_52 = & V_12 -> V_52 ;
struct V_27 * V_168 ;
struct V_53 * V_54 ;
if ( V_187 == V_123 || V_187 == V_188 )
return 0 ;
if ( ! ( V_2 -> V_95 . V_115 & V_189 ) )
return 0 ;
V_2 -> V_95 . V_170 . V_190 ++ ;
V_52 -> V_59 ++ ;
V_54 = F_25 ( V_12 , & V_168 ) ;
if ( F_26 ( ! V_54 ) )
return 0 ;
V_168 -> V_33 |= V_191 | V_192 ;
V_168 -> V_46 [ 2 ] |= V_193 ;
switch ( V_187 ) {
case V_194 :
F_73 ( V_12 , L_6 ) ;
V_168 -> V_46 [ 2 ] |= V_195 ;
break;
case V_196 :
F_73 ( V_12 , L_7 ) ;
V_168 -> V_46 [ 2 ] |= V_197 ;
break;
case V_198 :
F_73 ( V_12 , L_8 ) ;
V_168 -> V_46 [ 3 ] |= ( V_199 |
V_200 ) ;
break;
case V_201 :
F_73 ( V_12 , L_9 ) ;
V_168 -> V_46 [ 2 ] |= V_202 ;
break;
case V_203 :
F_73 ( V_12 , L_10 ) ;
V_168 -> V_46 [ 2 ] |= V_204 ;
break;
case V_205 :
F_73 ( V_12 , L_11 ) ;
V_168 -> V_46 [ 3 ] |= ( V_206 |
V_207 ) ;
break;
default:
break;
}
V_52 -> V_67 ++ ;
V_52 -> V_68 += V_168 -> V_31 ;
F_27 ( V_54 ) ;
return 1 ;
}
static int F_74 ( struct V_208 * V_209 , int V_160 )
{
struct V_11 * V_12 = V_209 -> V_12 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
T_2 V_210 , V_211 = V_2 -> V_212 ;
int V_213 = 0 ;
V_2 -> V_212 = V_210 = V_2 -> V_7 ( V_2 , V_122 ) ;
if ( V_2 -> type != V_129 )
V_2 -> V_10 ( V_2 , V_122 , V_123 ) ;
if ( ( V_210 & V_214 ) && ( ! ( V_211 & V_214 ) ) ) {
F_73 ( V_12 , L_12 ) ;
V_213 += F_70 ( V_12 , V_169 ) ;
}
if ( ( V_210 & V_215 ) && ( ! ( V_211 & V_215 ) ) ) {
F_73 ( V_12 , L_13 ) ;
V_213 += F_70 ( V_12 , V_173 ) ;
}
if ( ( V_210 & V_216 ) && ( ! ( V_211 & V_216 ) ) ) {
F_73 ( V_12 , L_14 ) ;
V_213 += F_70 ( V_12 , V_176 ) ;
goto V_217;
}
if ( ( ! ( V_210 & V_216 ) ) && ( V_211 & V_216 ) ) {
F_73 ( V_12 , L_15 ) ;
V_2 -> V_95 . V_132 = V_133 ;
}
if ( ( ! ( V_210 & V_215 ) ) && ( V_211 & V_215 ) ) {
F_73 ( V_12 , L_16 ) ;
V_2 -> V_95 . V_132 = V_133 ;
}
V_213 += F_72 ( V_12 , V_210 & V_218 ) ;
V_213 += F_68 ( V_12 , ( V_160 - V_213 ) ) ;
F_57 ( V_12 ) ;
V_217:
if ( V_213 < V_160 ) {
F_75 ( V_209 ) ;
if ( V_2 -> V_95 . V_132 != V_177 )
F_10 ( V_2 , true ) ;
}
return V_213 ;
}
static T_5 F_76 ( int V_219 , void * V_220 )
{
struct V_11 * V_12 = (struct V_11 * ) V_220 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( ! V_2 -> V_7 ( V_2 , V_221 ) )
return V_222 ;
F_10 ( V_2 , false ) ;
F_77 ( & V_2 -> V_209 ) ;
return V_223 ;
}
static int F_78 ( struct V_11 * V_12 )
{
int V_125 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 , true ) ;
V_125 = F_79 ( V_12 ) ;
if ( V_125 ) {
F_15 ( V_12 , L_17 ) ;
goto V_224;
}
V_125 = F_80 ( V_12 -> V_219 , & F_76 , V_225 , V_12 -> V_226 ,
V_12 ) ;
if ( V_125 < 0 ) {
F_15 ( V_12 , L_18 ) ;
goto V_227;
}
V_125 = F_46 ( V_12 ) ;
if ( V_125 )
goto V_228;
F_61 ( V_12 , V_229 ) ;
F_81 ( & V_2 -> V_209 ) ;
F_10 ( V_2 , true ) ;
F_82 ( V_12 ) ;
return 0 ;
V_228:
F_83 ( V_12 -> V_219 , V_12 ) ;
V_227:
F_84 ( V_12 ) ;
V_224:
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
return V_125 ;
}
static int F_85 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_37 ( V_12 ) ;
F_86 ( & V_2 -> V_209 ) ;
F_51 ( V_12 ) ;
F_83 ( V_12 -> V_219 , V_12 ) ;
F_84 ( V_12 ) ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
F_61 ( V_12 , V_230 ) ;
return 0 ;
}
struct V_11 * F_87 ( void )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_88 ( sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_12 )
return NULL ;
V_2 = F_12 ( V_12 ) ;
F_89 ( V_12 , & V_2 -> V_209 , F_74 , V_231 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_95 . V_232 = & V_233 ;
V_2 -> V_95 . V_234 = F_53 ;
V_2 -> V_95 . V_235 = F_56 ;
V_2 -> V_95 . V_236 = V_117 |
V_116 |
V_189 ;
return V_12 ;
}
int F_90 ( struct V_11 * V_12 )
{
T_1 V_237 ;
unsigned long V_238 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( ! ( V_12 -> V_239 & V_240 ) )
return 0 ;
F_91 ( V_2 -> type != V_129 ) ;
V_237 = V_2 -> V_7 ( V_2 , V_241 ) ;
V_237 |= V_242 ;
V_2 -> V_10 ( V_2 , V_241 , V_237 ) ;
V_238 = V_243 + F_92 ( V_244 ) ;
while ( ! ( V_2 -> V_7 ( V_2 , V_122 ) & V_245 ) &&
F_93 ( V_238 , V_243 ) )
F_94 () ;
if ( F_93 ( V_243 , V_238 ) )
return - V_246 ;
F_51 ( V_12 ) ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
return 0 ;
}
int F_95 ( struct V_11 * V_12 )
{
T_1 V_237 ;
unsigned long V_238 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_247 ;
if ( ! ( V_12 -> V_239 & V_240 ) )
return 0 ;
F_91 ( V_2 -> type != V_129 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 , true ) ;
V_237 = V_2 -> V_7 ( V_2 , V_241 ) ;
V_237 &= ~ V_242 ;
V_2 -> V_10 ( V_2 , V_241 , V_237 ) ;
V_237 = V_2 -> V_7 ( V_2 , V_8 ) ;
V_237 &= ~ V_82 ;
V_2 -> V_10 ( V_2 , V_8 , V_237 ) ;
V_238 = V_243 + F_92 ( V_244 ) ;
while ( ( V_2 -> V_7 ( V_2 , V_122 ) & V_245 ) &&
F_93 ( V_238 , V_243 ) )
F_94 () ;
if ( F_93 ( V_243 , V_238 ) )
return - V_246 ;
V_247 = F_46 ( V_12 ) ;
if ( ! V_247 )
F_10 ( V_2 , true ) ;
return V_247 ;
}
void F_96 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_97 ( & V_2 -> V_209 ) ;
F_98 ( V_12 ) ;
}
int F_99 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_125 ;
F_52 ( V_12 -> V_12 . V_134 ) ;
F_1 ( V_2 ) ;
V_12 -> V_239 |= V_248 ;
V_12 -> V_249 = & V_250 ;
V_125 = F_100 ( V_12 ) ;
if ( V_125 )
F_3 ( V_2 ) ;
else
F_101 ( V_12 ) ;
return V_125 ;
}
void F_102 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_103 ( V_12 ) ;
F_3 ( V_2 ) ;
}
