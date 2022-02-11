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
V_125 = F_44 ( V_12 ) ;
if ( V_125 )
return V_125 ;
V_2 -> V_126 = V_2 -> type != V_127 ?
V_128 : V_129 ;
V_2 -> V_95 . V_130 = V_131 ;
return 0 ;
}
static void F_47 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_10 ( V_2 , false ) ;
V_2 -> V_95 . V_130 = V_132 ;
}
static int F_48 ( struct V_11 * V_12 , enum V_133 V_134 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_125 ;
switch ( V_134 ) {
case V_135 :
V_125 = F_46 ( V_12 ) ;
if ( V_125 )
return V_125 ;
F_49 ( V_12 ) ;
F_10 ( V_2 , true ) ;
break;
default:
return - V_136 ;
}
return 0 ;
}
static int F_50 ( const struct V_11 * V_12 ,
struct V_137 * V_138 )
{
unsigned int V_139 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
V_139 = V_2 -> V_7 ( V_2 , V_140 ) ;
V_138 -> V_141 = ( V_139 & V_142 ) >>
V_143 ;
V_138 -> V_144 = V_139 & V_145 ;
return 0 ;
}
static int F_51 ( const struct V_11 * V_12 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_125 ;
F_5 ( V_2 ) ;
V_125 = F_50 ( V_12 , V_138 ) ;
F_7 ( V_2 ) ;
return V_125 ;
}
static void F_52 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
struct V_51 * V_52 = & V_12 -> V_52 ;
T_1 V_29 , V_15 , V_146 = 0 , V_147 = 0 , V_148 , V_149 ;
V_149 = V_148 = V_2 -> V_7 ( V_2 , V_150 ) ;
while ( ( V_29 = F_53 ( V_148 ) ) ) {
V_29 -- ;
V_148 &= ~ ( 1 << V_29 ) ;
V_15 = V_29 + V_44 ;
F_18 ( V_12 , V_110 , V_15 ) ;
F_54 ( V_12 , V_29 ) ;
V_147 += V_2 -> V_78 [ V_29 ] ;
V_146 ++ ;
}
F_55 ( V_149 , & V_2 -> V_75 ) ;
if ( V_149 & ( 1 << ( V_76 - 1 ) ) )
F_49 ( V_12 ) ;
if ( V_146 ) {
V_52 -> V_151 += V_147 ;
V_52 -> V_152 += V_146 ;
F_56 ( V_12 , V_153 ) ;
}
}
static T_1 F_57 ( T_1 V_148 )
{
T_1 V_154 , V_155 ;
if ( V_148 == V_156 )
return V_148 ;
V_154 = F_58 ( V_148 ) ;
V_155 = F_35 ( V_148 ) ;
if ( V_155 == V_154 )
return V_148 ;
for ( V_155 -- ; V_148 & ( 1 << ( V_155 - 1 ) ) ; V_155 -- ) ;
return V_148 & ~ ( ( 1 << V_155 ) - 1 ) ;
}
static inline void F_59 ( struct V_11 * V_12 ,
struct V_1 * V_2 , T_1 V_15 )
{
F_16 ( V_12 , V_110 , V_15 , V_2 -> V_126 ) ;
}
static inline void F_60 ( struct V_11 * V_12 ,
struct V_1 * V_2 , T_1 V_15 )
{
if ( V_2 -> type != V_127 )
F_16 ( V_12 , V_110 , V_15 , V_49 ) ;
}
static int F_61 ( struct V_11 * V_12 , struct V_1 * V_2 ,
T_1 V_148 , int V_157 )
{
T_1 V_146 = 0 , V_6 , V_15 ;
while ( ( V_15 = F_53 ( V_148 ) ) && V_157 > 0 ) {
V_148 &= ~ F_32 ( V_15 - 1 ) ;
F_59 ( V_12 , V_2 , V_15 ) ;
V_6 = V_2 -> V_7 ( V_2 , F_13 ( V_23 , V_110 ) ) ;
if ( V_6 & V_55 ) {
int V_158 = F_24 ( V_12 , V_110 , V_15 , V_6 ) ;
V_146 += V_158 ;
V_157 -= V_158 ;
continue;
}
if ( ! ( V_6 & V_57 ) )
continue;
F_28 ( V_12 , V_110 , V_6 ) ;
F_60 ( V_12 , V_2 , V_15 ) ;
V_146 ++ ;
V_157 -- ;
}
return V_146 ;
}
static inline T_1 F_62 ( struct V_1 * V_2 )
{
T_1 V_148 = V_2 -> V_7 ( V_2 , V_159 ) ;
return V_148 ;
}
static int F_63 ( struct V_11 * V_12 , int V_157 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
T_1 V_146 = 0 , V_148 = 0 , V_160 , V_158 ;
F_64 ( V_111 > 16 ,
L_4 ) ;
while ( V_157 > 0 ) {
if ( ! V_148 ) {
V_148 = F_62 ( V_2 ) ;
if ( ! V_148 )
break;
V_160 = F_57 ( V_148 ) ;
} else {
V_160 = V_148 ;
}
V_148 &= ~ V_160 ;
V_158 = F_61 ( V_12 , V_2 , V_160 , V_157 ) ;
V_146 += V_158 ;
V_157 -= V_158 ;
}
if ( V_146 )
F_56 ( V_12 , V_161 ) ;
return V_146 ;
}
static int F_65 ( struct V_11 * V_12 ,
enum V_162 V_163 )
{
unsigned int V_139 ;
unsigned int V_164 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
struct V_51 * V_52 = & V_12 -> V_52 ;
struct V_27 * V_165 ;
struct V_53 * V_54 ;
struct V_137 V_138 ;
switch ( V_163 ) {
case V_166 :
V_2 -> V_95 . V_167 . V_168 ++ ;
V_2 -> V_95 . V_130 = V_169 ;
break;
case V_170 :
V_2 -> V_95 . V_167 . V_171 ++ ;
V_2 -> V_95 . V_130 = V_172 ;
break;
case V_173 :
V_2 -> V_95 . V_130 = V_174 ;
F_66 ( V_12 ) ;
break;
default:
break;
}
V_54 = F_25 ( V_12 , & V_165 ) ;
if ( F_26 ( ! V_54 ) )
return 0 ;
F_50 ( V_12 , & V_138 ) ;
V_139 = V_2 -> V_7 ( V_2 , V_140 ) ;
V_164 = ( V_139 & V_175 ) >>
V_176 ;
switch ( V_163 ) {
case V_166 :
V_165 -> V_33 |= V_61 ;
V_165 -> V_46 [ 1 ] = ( V_138 . V_144 > V_138 . V_141 ) ?
V_177 :
V_178 ;
V_165 -> V_46 [ 6 ] = V_138 . V_144 ;
V_165 -> V_46 [ 7 ] = V_138 . V_141 ;
break;
case V_170 :
V_165 -> V_33 |= V_61 ;
if ( V_164 )
V_165 -> V_46 [ 1 ] |= V_179 ;
if ( V_138 . V_144 > 127 )
V_165 -> V_46 [ 1 ] |= V_180 ;
V_165 -> V_46 [ 6 ] = V_138 . V_144 ;
V_165 -> V_46 [ 7 ] = V_138 . V_141 ;
break;
case V_173 :
V_165 -> V_33 |= V_181 ;
F_66 ( V_12 ) ;
break;
default:
break;
}
V_52 -> V_67 ++ ;
V_52 -> V_68 += V_165 -> V_31 ;
F_27 ( V_54 ) ;
return 1 ;
}
static int F_67 ( struct V_11 * V_12 ,
enum V_182 V_183 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
struct V_51 * V_52 = & V_12 -> V_52 ;
struct V_27 * V_165 ;
struct V_53 * V_54 ;
if ( V_183 == V_123 || V_183 == V_184 )
return 0 ;
if ( ! ( V_2 -> V_95 . V_115 & V_185 ) )
return 0 ;
V_2 -> V_95 . V_167 . V_186 ++ ;
V_52 -> V_59 ++ ;
V_54 = F_25 ( V_12 , & V_165 ) ;
if ( F_26 ( ! V_54 ) )
return 0 ;
V_165 -> V_33 |= V_187 | V_188 ;
V_165 -> V_46 [ 2 ] |= V_189 ;
switch ( V_183 ) {
case V_190 :
F_68 ( V_12 , L_5 ) ;
V_165 -> V_46 [ 2 ] |= V_191 ;
break;
case V_192 :
F_68 ( V_12 , L_6 ) ;
V_165 -> V_46 [ 2 ] |= V_193 ;
break;
case V_194 :
F_68 ( V_12 , L_7 ) ;
V_165 -> V_46 [ 3 ] |= ( V_195 |
V_196 ) ;
break;
case V_197 :
F_68 ( V_12 , L_8 ) ;
V_165 -> V_46 [ 2 ] |= V_198 ;
break;
case V_199 :
F_68 ( V_12 , L_9 ) ;
V_165 -> V_46 [ 2 ] |= V_200 ;
break;
case V_201 :
F_68 ( V_12 , L_10 ) ;
V_165 -> V_46 [ 3 ] |= ( V_202 |
V_203 ) ;
break;
default:
break;
}
V_52 -> V_67 ++ ;
V_52 -> V_68 += V_165 -> V_31 ;
F_27 ( V_54 ) ;
return 1 ;
}
static int F_69 ( struct V_204 * V_205 , int V_157 )
{
struct V_11 * V_12 = V_205 -> V_12 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
T_2 V_206 , V_207 = V_2 -> V_208 ;
int V_209 = 0 ;
V_2 -> V_208 = V_206 = V_2 -> V_7 ( V_2 , V_122 ) ;
if ( V_2 -> type != V_127 )
V_2 -> V_10 ( V_2 , V_122 , V_123 ) ;
if ( ( V_206 & V_210 ) && ( ! ( V_207 & V_210 ) ) ) {
F_68 ( V_12 , L_11 ) ;
V_209 += F_65 ( V_12 , V_166 ) ;
}
if ( ( V_206 & V_211 ) && ( ! ( V_207 & V_211 ) ) ) {
F_68 ( V_12 , L_12 ) ;
V_209 += F_65 ( V_12 , V_170 ) ;
}
if ( ( V_206 & V_212 ) && ( ! ( V_207 & V_212 ) ) ) {
F_68 ( V_12 , L_13 ) ;
V_209 += F_65 ( V_12 , V_173 ) ;
goto V_213;
}
if ( ( ! ( V_206 & V_212 ) ) && ( V_207 & V_212 ) ) {
F_68 ( V_12 , L_14 ) ;
V_2 -> V_95 . V_130 = V_131 ;
}
if ( ( ! ( V_206 & V_211 ) ) && ( V_207 & V_211 ) ) {
F_68 ( V_12 , L_15 ) ;
V_2 -> V_95 . V_130 = V_131 ;
}
V_209 += F_67 ( V_12 , V_206 & V_214 ) ;
V_209 += F_63 ( V_12 , ( V_157 - V_209 ) ) ;
F_52 ( V_12 ) ;
V_213:
if ( V_209 < V_157 ) {
F_70 ( V_205 ) ;
if ( V_2 -> V_95 . V_130 != V_174 )
F_10 ( V_2 , true ) ;
}
return V_209 ;
}
static T_5 F_71 ( int V_215 , void * V_216 )
{
struct V_11 * V_12 = (struct V_11 * ) V_216 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( ! V_2 -> V_7 ( V_2 , V_217 ) )
return V_218 ;
F_10 ( V_2 , false ) ;
F_72 ( & V_2 -> V_205 ) ;
return V_219 ;
}
static int F_73 ( struct V_11 * V_12 )
{
int V_125 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 , true ) ;
V_125 = F_74 ( V_12 ) ;
if ( V_125 ) {
F_15 ( V_12 , L_16 ) ;
goto V_220;
}
V_125 = F_75 ( V_12 -> V_215 , & F_71 , V_221 , V_12 -> V_222 ,
V_12 ) ;
if ( V_125 < 0 ) {
F_15 ( V_12 , L_17 ) ;
goto V_223;
}
V_125 = F_46 ( V_12 ) ;
if ( V_125 )
goto V_224;
F_56 ( V_12 , V_225 ) ;
F_76 ( & V_2 -> V_205 ) ;
F_10 ( V_2 , true ) ;
F_77 ( V_12 ) ;
return 0 ;
V_224:
F_78 ( V_12 -> V_215 , V_12 ) ;
V_223:
F_79 ( V_12 ) ;
V_220:
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
return V_125 ;
}
static int F_80 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_37 ( V_12 ) ;
F_81 ( & V_2 -> V_205 ) ;
F_47 ( V_12 ) ;
F_78 ( V_12 -> V_215 , V_12 ) ;
F_79 ( V_12 ) ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
F_56 ( V_12 , V_226 ) ;
return 0 ;
}
struct V_11 * F_82 ( void )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_83 ( sizeof( struct V_1 ) , V_76 ) ;
if ( ! V_12 )
return NULL ;
V_2 = F_12 ( V_12 ) ;
F_84 ( V_12 , & V_2 -> V_205 , F_69 , V_227 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_95 . V_228 = & V_229 ;
V_2 -> V_95 . V_230 = F_48 ;
V_2 -> V_95 . V_231 = F_51 ;
V_2 -> V_95 . V_232 = V_117 |
V_116 |
V_185 ;
return V_12 ;
}
int F_85 ( struct V_11 * V_12 )
{
T_1 V_233 ;
unsigned long V_234 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
if ( ! ( V_12 -> V_235 & V_236 ) )
return 0 ;
F_86 ( V_2 -> type != V_127 ) ;
V_233 = V_2 -> V_7 ( V_2 , V_237 ) ;
V_233 |= V_238 ;
V_2 -> V_10 ( V_2 , V_237 , V_233 ) ;
V_234 = V_239 + F_87 ( V_240 ) ;
while ( ! ( V_2 -> V_7 ( V_2 , V_122 ) & V_241 ) &&
F_88 ( V_234 , V_239 ) )
F_89 () ;
if ( F_88 ( V_239 , V_234 ) )
return - V_242 ;
F_47 ( V_12 ) ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
return 0 ;
}
int F_90 ( struct V_11 * V_12 )
{
T_1 V_233 ;
unsigned long V_234 ;
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_243 ;
if ( ! ( V_12 -> V_235 & V_236 ) )
return 0 ;
F_86 ( V_2 -> type != V_127 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 , true ) ;
V_233 = V_2 -> V_7 ( V_2 , V_237 ) ;
V_233 &= ~ V_238 ;
V_2 -> V_10 ( V_2 , V_237 , V_233 ) ;
V_233 = V_2 -> V_7 ( V_2 , V_8 ) ;
V_233 &= ~ V_82 ;
V_2 -> V_10 ( V_2 , V_8 , V_233 ) ;
V_234 = V_239 + F_87 ( V_240 ) ;
while ( ( V_2 -> V_7 ( V_2 , V_122 ) & V_241 ) &&
F_88 ( V_234 , V_239 ) )
F_89 () ;
if ( F_88 ( V_239 , V_234 ) )
return - V_242 ;
V_243 = F_46 ( V_12 ) ;
if ( ! V_243 )
F_10 ( V_2 , true ) ;
return V_243 ;
}
void F_91 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_92 ( & V_2 -> V_205 ) ;
F_93 ( V_12 ) ;
}
int F_94 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
int V_125 ;
F_1 ( V_2 ) ;
V_12 -> V_235 |= V_244 ;
V_12 -> V_245 = & V_246 ;
V_125 = F_95 ( V_12 ) ;
if ( V_125 )
F_3 ( V_2 ) ;
else
F_96 ( V_12 ) ;
return V_125 ;
}
void F_97 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_12 ( V_12 ) ;
F_98 ( V_12 ) ;
F_3 ( V_2 ) ;
}
