static void F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
for ( V_3 = 0 ; V_3 < V_5 ; V_3 ++ ) {
snprintf ( V_2 [ V_3 ] . V_6 , sizeof( V_2 [ V_3 ] . V_6 ) , L_1 , 1 + V_3 ) ;
V_2 [ V_3 ] . V_4 = V_3 ;
}
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
if ( V_8 [ V_3 ] < 1 || V_8 [ V_3 ] > V_5 ) {
F_2 ( L_2 , V_3 , V_8 [ V_3 ] ) ;
return;
}
}
V_4 = V_8 [ V_9 ] - 1 ;
V_2 [ V_4 ] . V_10 = V_11 ;
V_2 [ V_4 ] . V_12 = 0 ;
V_4 = V_8 [ V_13 ] - 1 ;
V_2 [ V_4 ] . V_10 = V_14 ;
V_2 [ V_4 ] . V_12 = 0 ;
for ( V_3 = V_15 ; V_3 < V_7 ; V_3 ++ ) {
V_4 = V_8 [ V_3 ] - 1 ;
V_2 [ V_4 ] . V_10 = V_16 ;
V_2 [ V_4 ] . V_12 = V_3 - V_15 ;
}
}
static inline int F_3 ( struct V_17 * V_18 , T_1 V_19 , T_2 V_20 )
{
return F_4 ( V_18 , V_21 , V_19 , V_20 ) ;
}
static int F_5 ( struct V_22 * V_23 , int V_24 , T_1 V_19 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
int V_20 ;
if ( V_26 -> clock -> V_24 != V_24 ) {
F_3 ( V_23 -> V_18 , V_28 , V_24 ) ;
V_26 -> clock -> V_24 = V_24 ;
}
V_20 = F_6 ( V_23 , V_19 ) ;
return V_20 ;
}
static void F_7 ( int V_29 , struct V_22 * V_23 ,
int V_24 , T_1 V_19 , T_2 V_20 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
if ( V_26 -> clock -> V_24 != V_24 ) {
F_3 ( V_23 -> V_18 , V_28 , V_24 ) ;
V_26 -> clock -> V_24 = V_24 ;
}
if ( V_29 )
F_3 ( V_23 -> V_18 , V_19 , V_20 ) ;
else
F_8 ( V_23 , V_19 , V_20 ) ;
}
static int F_9 ( int V_30 , struct V_22 * V_31 ,
const struct V_32 * V_33 , T_2 V_34 )
{
F_7 ( V_30 , V_31 , V_35 , V_36 , V_33 -> V_37 & 0xffff ) ;
F_7 ( V_30 , V_31 , V_35 , V_36 , V_33 -> V_37 >> 16 ) ;
F_7 ( V_30 , V_31 , V_35 , V_36 , V_33 -> V_38 & 0xffff ) ;
F_7 ( V_30 , V_31 , V_35 , V_36 , V_33 -> V_38 >> 16 ) ;
F_7 ( V_30 , V_31 , V_35 , V_39 , V_34 ) ;
return 0 ;
}
static void F_10 ( struct V_40 * V_41 , struct V_42 * V_42 )
{
T_1 V_43 ;
V_43 = V_41 -> V_44 ;
V_43 |= V_41 -> V_45 << 16 ;
V_42 -> V_46 = V_41 -> V_47 ;
V_42 -> V_46 |= ( V_41 -> V_48 & 0x3fff ) << 16 ;
V_42 -> V_46 += ( ( V_49 ) V_43 ) * 1000000000ULL ;
V_42 -> V_50 = V_41 -> V_50 ;
V_42 -> V_51 = ( V_41 -> V_51 >> 12 ) & 0xf ;
V_42 -> V_52 = V_41 -> V_51 & 0x0fff ;
V_42 -> V_53 = V_54 + V_55 ;
}
static V_49 F_11 ( struct V_56 * V_41 )
{
V_49 V_46 ;
T_1 V_43 ;
V_43 = V_41 -> V_44 ;
V_43 |= V_41 -> V_45 << 16 ;
V_46 = V_41 -> V_47 ;
V_46 |= ( V_41 -> V_48 & 0x3fff ) << 16 ;
V_46 += ( ( V_49 ) V_43 ) * 1000000000ULL ;
return V_46 ;
}
static int F_12 ( struct V_57 * clock ,
struct V_58 * V_59 , bool V_60 ,
int V_61 )
{
struct V_25 * V_26 = clock -> V_62 ;
struct V_22 * V_23 = V_26 -> V_23 ;
T_1 V_43 , V_63 , V_64 ;
T_2 V_65 , V_66 , V_20 ;
if ( V_60 ) {
V_65 = 1 + F_13 ( clock -> V_67 , V_14 ,
V_61 ) ;
if ( V_65 < 1 )
return - V_68 ;
} else {
V_65 = 0 ;
}
V_66 = V_69 |
( V_61 & V_70 ) << V_71 |
( V_65 & V_72 ) << V_73 |
V_74 |
V_75 ;
V_20 = ( V_61 & V_76 ) << V_77 ;
if ( ! V_60 ) {
V_20 |= V_78 ;
F_14 ( & clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_80 , V_81 , V_66 ) ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_20 ) ;
F_15 ( & clock -> V_79 ) ;
return 0 ;
}
V_43 = V_59 -> V_82 . V_83 . V_43 ;
V_63 = V_59 -> V_82 . V_83 . V_63 ;
V_64 = V_59 -> V_82 . V_84 . V_43 * 1000000000UL ;
V_64 += V_59 -> V_82 . V_84 . V_63 ;
V_64 /= 2 ;
F_14 ( & clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_80 , V_81 , V_66 ) ;
V_20 |= V_85 ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_20 ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_63 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_63 >> 16 ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_43 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_43 >> 16 ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_64 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_64 >> 16 ) ;
if ( V_61 < 2 ) {
F_7 ( 0 , V_23 , V_35 , V_36 , V_64 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_64 >> 16 ) ;
}
V_20 &= ~ V_85 ;
V_20 |= V_86 ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_20 ) ;
F_15 ( & clock -> V_79 ) ;
return 0 ;
}
static int F_16 ( struct V_87 * V_88 , T_3 V_89 )
{
struct V_57 * clock =
F_17 ( V_88 , struct V_57 , V_90 ) ;
struct V_22 * V_23 = clock -> V_62 -> V_23 ;
V_49 V_91 ;
int V_92 = 0 ;
T_2 V_93 , V_94 ;
if ( V_89 < 0 ) {
V_92 = 1 ;
V_89 = - V_89 ;
}
V_91 = V_89 ;
V_91 <<= 26 ;
V_91 = F_18 ( V_91 , 1953125 ) ;
V_93 = ( V_91 >> 16 ) & V_95 ;
if ( V_92 )
V_93 |= V_96 ;
V_94 = V_91 & 0xffff ;
F_14 ( & clock -> V_79 ) ;
F_7 ( 1 , V_23 , V_35 , V_97 , V_93 ) ;
F_7 ( 1 , V_23 , V_35 , V_98 , V_94 ) ;
F_15 ( & clock -> V_79 ) ;
return 0 ;
}
static int F_19 ( struct V_87 * V_88 , T_4 V_99 )
{
struct V_57 * clock =
F_17 ( V_88 , struct V_57 , V_90 ) ;
struct V_22 * V_23 = clock -> V_62 -> V_23 ;
struct V_32 V_33 ;
int V_100 ;
V_99 += V_101 ;
V_33 = F_20 ( V_99 ) ;
F_14 ( & clock -> V_79 ) ;
V_100 = F_9 ( 1 , V_23 , & V_33 , V_102 ) ;
F_15 ( & clock -> V_79 ) ;
return V_100 ;
}
static int F_21 ( struct V_87 * V_88 ,
struct V_32 * V_33 )
{
struct V_57 * clock =
F_17 ( V_88 , struct V_57 , V_90 ) ;
struct V_22 * V_23 = clock -> V_62 -> V_23 ;
unsigned int V_20 [ 4 ] ;
F_14 ( & clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_103 ) ;
V_20 [ 0 ] = F_5 ( V_23 , V_35 , V_36 ) ;
V_20 [ 1 ] = F_5 ( V_23 , V_35 , V_36 ) ;
V_20 [ 2 ] = F_5 ( V_23 , V_35 , V_36 ) ;
V_20 [ 3 ] = F_5 ( V_23 , V_35 , V_36 ) ;
F_15 ( & clock -> V_79 ) ;
V_33 -> V_37 = V_20 [ 0 ] | ( V_20 [ 1 ] << 16 ) ;
V_33 -> V_38 = V_20 [ 2 ] | ( V_20 [ 3 ] << 16 ) ;
return 0 ;
}
static int F_22 ( struct V_87 * V_88 ,
const struct V_32 * V_33 )
{
struct V_57 * clock =
F_17 ( V_88 , struct V_57 , V_90 ) ;
struct V_22 * V_23 = clock -> V_62 -> V_23 ;
int V_100 ;
F_14 ( & clock -> V_79 ) ;
V_100 = F_9 ( 1 , V_23 , V_33 , V_104 ) ;
F_15 ( & clock -> V_79 ) ;
return V_100 ;
}
static int F_23 ( struct V_87 * V_88 ,
struct V_58 * V_105 , int V_60 )
{
struct V_57 * clock =
F_17 ( V_88 , struct V_57 , V_90 ) ;
struct V_22 * V_23 = clock -> V_62 -> V_23 ;
unsigned int V_4 ;
T_2 V_106 , V_107 , V_108 ;
switch ( V_105 -> type ) {
case V_109 :
V_4 = V_105 -> V_110 . V_4 ;
if ( V_4 >= V_111 )
return - V_68 ;
V_107 = V_112 + V_4 ;
V_106 = V_113 | ( V_107 & V_114 ) << V_115 ;
if ( V_60 ) {
V_108 = 1 + F_13 ( clock -> V_67 ,
V_16 , V_4 ) ;
if ( V_108 < 1 )
return - V_68 ;
V_106 |= ( V_108 & V_116 ) << V_117 ;
if ( V_105 -> V_110 . V_118 & V_119 )
V_106 |= V_120 ;
else
V_106 |= V_121 ;
}
F_14 ( & clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_80 , V_122 , V_106 ) ;
F_15 ( & clock -> V_79 ) ;
return 0 ;
case V_123 :
if ( V_105 -> V_82 . V_4 >= V_124 )
return - V_68 ;
return F_12 ( clock , V_105 , V_60 , V_105 -> V_82 . V_4 ) ;
default:
break;
}
return - V_125 ;
}
static int F_24 ( struct V_87 * V_88 , unsigned int V_126 ,
enum V_127 V_10 , unsigned int V_12 )
{
struct V_57 * clock =
F_17 ( V_88 , struct V_57 , V_90 ) ;
if ( clock -> V_90 . V_128 [ V_126 ] . V_10 == V_11 &&
! F_25 ( & clock -> V_129 ) )
return 1 ;
if ( V_10 == V_11 )
return 1 ;
return 0 ;
}
static void F_26 ( struct V_22 * V_23 , bool V_60 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_57 * clock = V_26 -> clock ;
T_2 V_130 = 0 , V_131 ;
if ( V_60 )
V_130 = V_132 | V_133 | V_134 | V_135 ;
V_131 = ( V_136 & V_137 ) << V_138 ;
F_14 ( & clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_80 , V_139 , V_130 ) ;
F_7 ( 0 , V_23 , V_140 , V_141 , V_131 ) ;
F_15 ( & clock -> V_79 ) ;
if ( ! V_23 -> V_142 ) {
F_27 ( L_3 ) ;
return;
}
if ( V_60 ) {
if ( F_28 ( V_23 -> V_142 , V_143 ) )
F_27 ( L_4 ) ;
} else {
if ( F_29 ( V_23 -> V_142 , V_143 ) )
F_27 ( L_5 ) ;
}
}
static bool F_30 ( struct V_144 * V_145 , int type )
{
struct V_146 * V_147 = F_31 ( V_145 ) ;
if ( V_148 == type &&
! memcmp ( V_147 -> V_149 , V_150 , sizeof( V_150 ) ) )
return true ;
else
return false ;
}
static int F_32 ( struct V_42 * V_42 )
{
return F_33 ( V_54 , V_42 -> V_53 ) ;
}
static void F_34 ( struct V_25 * V_26 )
{
struct V_151 * V_152 , * V_153 ;
struct V_42 * V_42 ;
F_35 (this, next, &dp83640->rxts) {
V_42 = F_36 ( V_152 , struct V_42 , V_154 ) ;
if ( F_32 ( V_42 ) ) {
F_37 ( & V_42 -> V_154 ) ;
F_38 ( & V_42 -> V_154 , & V_26 -> V_155 ) ;
}
}
}
static void F_39 ( struct V_22 * V_23 , int V_156 , int V_60 )
{
int V_20 ;
F_8 ( V_23 , V_28 , 0 ) ;
V_20 = F_6 ( V_23 , V_157 ) ;
if ( V_60 )
V_20 |= V_158 ;
else
V_20 &= ~ V_158 ;
F_8 ( V_23 , V_157 , V_20 ) ;
F_8 ( V_23 , V_28 , V_156 ) ;
}
static void F_40 ( struct V_57 * clock )
{
T_4 V_159 , V_160 ;
struct V_56 V_161 ;
struct V_32 V_33 ;
struct V_151 * V_152 ;
struct V_25 * V_162 ;
struct V_22 * V_163 = clock -> V_62 -> V_23 ;
T_2 V_164 , V_130 , V_106 , V_66 , V_61 , V_20 ;
V_61 = V_165 ;
V_164 = 1 + F_13 ( clock -> V_67 , V_11 , 0 ) ;
if ( V_164 < 1 ) {
F_2 ( L_6 ) ;
return;
}
F_14 ( & clock -> V_79 ) ;
F_41 (this, &clock->phylist) {
V_162 = F_36 ( V_152 , struct V_25 , V_154 ) ;
F_39 ( V_162 -> V_23 , clock -> V_24 , 1 ) ;
V_162 -> V_130 = F_5 ( V_162 -> V_23 , V_80 , V_139 ) ;
F_7 ( 0 , V_162 -> V_23 , V_80 , V_139 , 0 ) ;
F_7 ( 0 , V_162 -> V_23 , V_35 , V_39 , V_166 ) ;
}
F_39 ( V_163 , clock -> V_24 , 1 ) ;
V_130 = F_5 ( V_163 , V_80 , V_139 ) ;
F_7 ( 0 , V_163 , V_80 , V_139 , 0 ) ;
F_7 ( 0 , V_163 , V_35 , V_39 , V_166 ) ;
V_106 = V_113 | V_121 | V_167 ;
V_106 |= ( V_168 & V_114 ) << V_115 ;
V_106 |= ( V_164 & V_116 ) << V_117 ;
F_41 (this, &clock->phylist) {
V_162 = F_36 ( V_152 , struct V_25 , V_154 ) ;
F_7 ( 0 , V_162 -> V_23 , V_80 , V_122 , V_106 ) ;
}
F_7 ( 0 , V_163 , V_80 , V_122 , V_106 ) ;
V_66 = V_69 | V_169 | V_75 ;
V_66 |= ( V_61 & V_70 ) << V_71 ;
V_66 |= ( V_164 & V_72 ) << V_73 ;
F_7 ( 0 , V_163 , V_80 , V_81 , V_66 ) ;
V_20 = ( V_61 & V_76 ) << V_77 ;
V_20 |= V_85 ;
F_7 ( 0 , V_163 , V_35 , V_39 , V_20 ) ;
V_20 &= ~ V_85 ;
V_20 |= V_86 ;
F_7 ( 0 , V_163 , V_35 , V_39 , V_20 ) ;
V_20 = ( V_61 & V_76 ) << V_77 ;
V_20 |= V_78 ;
F_7 ( 0 , V_163 , V_35 , V_39 , V_20 ) ;
V_20 = F_5 ( V_163 , V_35 , V_170 ) ;
F_42 ( L_7 , V_20 ) ;
V_20 = F_5 ( V_163 , V_35 , V_171 ) ;
F_42 ( L_8 , V_20 ) ;
V_161 . V_47 = F_5 ( V_163 , V_35 , V_172 ) ;
V_161 . V_48 = F_5 ( V_163 , V_35 , V_172 ) ;
V_161 . V_44 = F_5 ( V_163 , V_35 , V_172 ) ;
V_161 . V_45 = F_5 ( V_163 , V_35 , V_172 ) ;
V_159 = F_11 ( & V_161 ) ;
F_41 (this, &clock->phylist) {
V_162 = F_36 ( V_152 , struct V_25 , V_154 ) ;
V_20 = F_5 ( V_162 -> V_23 , V_35 , V_170 ) ;
F_42 ( L_9 , V_20 ) ;
V_20 = F_5 ( V_162 -> V_23 , V_35 , V_171 ) ;
F_42 ( L_10 , V_20 ) ;
V_161 . V_47 = F_5 ( V_162 -> V_23 , V_35 , V_172 ) ;
V_161 . V_48 = F_5 ( V_162 -> V_23 , V_35 , V_172 ) ;
V_161 . V_44 = F_5 ( V_162 -> V_23 , V_35 , V_172 ) ;
V_161 . V_45 = F_5 ( V_162 -> V_23 , V_35 , V_172 ) ;
V_160 = V_159 - ( T_4 ) F_11 ( & V_161 ) ;
F_42 ( L_11 , V_160 ) ;
V_160 += V_101 ;
V_33 = F_20 ( V_160 ) ;
F_9 ( 0 , V_162 -> V_23 , & V_33 , V_102 ) ;
}
F_41 (this, &clock->phylist) {
V_162 = F_36 ( V_152 , struct V_25 , V_154 ) ;
F_7 ( 0 , V_162 -> V_23 , V_80 , V_139 , V_162 -> V_130 ) ;
}
F_7 ( 0 , V_163 , V_80 , V_139 , V_130 ) ;
F_15 ( & clock -> V_79 ) ;
}
static inline T_2 F_43 ( int V_173 )
{
return 1 << ( ( V_173 + V_112 ) * 2 ) ;
}
static int F_44 ( struct V_25 * V_26 ,
void * V_174 , int V_175 , T_2 V_176 )
{
struct V_56 * V_56 ;
struct V_177 V_178 ;
int V_3 , V_179 ;
int V_180 = ( V_176 >> V_181 ) & V_182 ;
T_2 V_183 = 0 ;
if ( V_176 & V_184 )
V_179 = ( V_180 + 2 ) * sizeof( T_2 ) ;
else
V_179 = ( V_180 + 1 ) * sizeof( T_2 ) ;
if ( V_175 < V_179 )
return V_175 ;
if ( V_176 & V_184 ) {
V_183 = * ( T_2 * ) V_174 ;
V_174 += sizeof( V_183 ) ;
}
V_56 = V_174 ;
switch ( V_180 ) {
case 3 :
V_26 -> V_185 . V_45 = V_56 -> V_45 ;
case 2 :
V_26 -> V_185 . V_44 = V_56 -> V_44 ;
case 1 :
V_26 -> V_185 . V_48 = V_56 -> V_48 ;
case 0 :
V_26 -> V_185 . V_47 = V_56 -> V_47 ;
}
if ( ! V_183 ) {
V_3 = ( ( V_176 >> V_186 ) & V_187 ) - V_112 ;
V_183 = F_43 ( V_3 ) ;
}
V_178 . type = V_188 ;
V_178 . V_189 = F_11 ( & V_26 -> V_185 ) ;
V_178 . V_189 -= 35 ;
for ( V_3 = 0 ; V_3 < V_111 ; V_3 ++ ) {
if ( V_183 & F_43 ( V_3 ) ) {
V_178 . V_4 = V_3 ;
V_177 ( V_26 -> clock -> V_67 , & V_178 ) ;
}
}
return V_179 ;
}
static int F_45 ( struct V_144 * V_145 , unsigned int type , struct V_42 * V_42 )
{
T_2 * V_50 , V_52 ;
unsigned int V_190 = 0 ;
T_5 * V_51 , * V_174 = F_46 ( V_145 ) ;
if ( type & V_191 )
V_190 += V_192 ;
switch ( type & V_193 ) {
case V_194 :
V_190 += V_195 + F_47 ( V_174 + V_190 ) + V_196 ;
break;
case V_197 :
V_190 += V_195 + V_198 + V_196 ;
break;
case V_199 :
V_190 += V_195 ;
break;
default:
return 0 ;
}
if ( V_145 -> V_175 + V_195 < V_190 + V_200 + sizeof( * V_50 ) )
return 0 ;
if ( F_48 ( type & V_201 ) )
V_51 = V_174 + V_190 + V_202 ;
else
V_51 = V_174 + V_190 ;
if ( V_42 -> V_51 != ( * V_51 & 0xf ) )
return 0 ;
V_50 = ( T_2 * ) ( V_174 + V_190 + V_200 ) ;
if ( V_42 -> V_50 != F_49 ( * V_50 ) )
return 0 ;
V_52 = F_50 ( V_203 ,
V_174 + V_190 + V_204 ) >> 20 ;
if ( V_42 -> V_52 != V_52 )
return 0 ;
return 1 ;
}
static void F_51 ( struct V_25 * V_26 ,
struct V_40 * V_40 )
{
struct V_42 * V_42 ;
struct V_205 * V_206 = NULL ;
struct V_144 * V_145 ;
unsigned long V_118 ;
F_52 ( & V_26 -> V_207 , V_118 ) ;
F_34 ( V_26 ) ;
if ( F_25 ( & V_26 -> V_155 ) ) {
F_53 ( L_12 ) ;
goto V_208;
}
V_42 = F_54 ( & V_26 -> V_155 , struct V_42 , V_154 ) ;
F_37 ( & V_42 -> V_154 ) ;
F_10 ( V_40 , V_42 ) ;
F_55 ( & V_26 -> V_209 . V_210 ) ;
F_56 (&dp83640->rx_queue, skb) {
struct V_211 * V_212 ;
V_212 = (struct V_211 * ) V_145 -> V_213 ;
if ( F_45 ( V_145 , V_212 -> V_214 , V_42 ) ) {
F_57 ( V_145 , & V_26 -> V_209 ) ;
V_206 = F_58 ( V_145 ) ;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
V_206 -> V_215 = F_59 ( V_42 -> V_46 ) ;
F_60 ( V_145 ) ;
F_38 ( & V_42 -> V_154 , & V_26 -> V_155 ) ;
break;
}
}
F_61 ( & V_26 -> V_209 . V_210 ) ;
if ( ! V_206 )
F_62 ( & V_42 -> V_154 , & V_26 -> V_42 ) ;
V_208:
F_63 ( & V_26 -> V_207 , V_118 ) ;
}
static void F_64 ( struct V_25 * V_26 ,
struct V_56 * V_56 )
{
struct V_205 V_206 ;
struct V_144 * V_145 ;
V_49 V_46 ;
V_145 = F_65 ( & V_26 -> V_216 ) ;
if ( ! V_145 ) {
F_53 ( L_13 ) ;
return;
}
V_46 = F_11 ( V_56 ) ;
memset ( & V_206 , 0 , sizeof( V_206 ) ) ;
V_206 . V_215 = F_59 ( V_46 ) ;
F_66 ( V_145 , & V_206 ) ;
}
static void F_67 ( struct V_25 * V_26 ,
struct V_144 * V_145 )
{
struct V_40 * V_40 ;
struct V_56 * V_56 ;
T_5 * V_217 ;
int V_175 , V_218 ;
T_2 V_176 , type ;
V_217 = V_145 -> V_174 + 2 ;
for ( V_175 = F_68 ( V_145 ) - 2 ; V_175 > sizeof( type ) ; V_175 -= V_218 ) {
type = * ( T_2 * ) V_217 ;
V_176 = type & 0x0fff ;
type = type & 0xf000 ;
V_175 -= sizeof( type ) ;
V_217 += sizeof( type ) ;
if ( V_219 == type && V_175 >= sizeof( * V_40 ) ) {
V_40 = (struct V_40 * ) V_217 ;
F_51 ( V_26 , V_40 ) ;
V_218 = sizeof( * V_40 ) ;
} else if ( V_220 == type && V_175 >= sizeof( * V_56 ) ) {
V_56 = (struct V_56 * ) V_217 ;
F_64 ( V_26 , V_56 ) ;
V_218 = sizeof( * V_56 ) ;
} else if ( V_221 == type ) {
V_218 = F_44 ( V_26 , V_217 , V_175 , V_176 ) ;
} else {
V_218 = 0 ;
break;
}
V_217 += V_218 ;
}
}
static int F_69 ( struct V_144 * V_145 , int type )
{
T_5 * V_174 = V_145 -> V_174 , * V_51 ;
unsigned int V_190 = 0 ;
if ( type & V_191 )
V_190 += V_192 ;
switch ( type & V_193 ) {
case V_194 :
V_190 += V_195 + F_47 ( V_174 + V_190 ) + V_196 ;
break;
case V_197 :
V_190 += V_195 + V_198 + V_196 ;
break;
case V_199 :
V_190 += V_195 ;
break;
default:
return 0 ;
}
if ( type & V_201 )
V_190 += V_202 ;
if ( V_145 -> V_175 < V_190 + 1 )
return 0 ;
V_51 = V_174 + V_190 ;
return ( * V_51 & 0xf ) == 0 ;
}
static void F_70 ( void )
{
struct V_57 * clock ;
struct V_151 * V_152 , * V_153 ;
F_14 ( & V_222 ) ;
F_35 (this, next, &phyter_clocks) {
clock = F_36 ( V_152 , struct V_57 , V_154 ) ;
if ( ! F_25 ( & clock -> V_129 ) ) {
F_27 ( L_14 ) ;
F_71 () ;
}
F_72 ( & clock -> V_154 ) ;
F_73 ( & clock -> V_79 ) ;
F_73 ( & clock -> V_223 ) ;
F_74 ( & clock -> V_18 -> V_31 ) ;
F_75 ( clock -> V_90 . V_128 ) ;
F_75 ( clock ) ;
}
F_15 ( & V_222 ) ;
}
static void F_76 ( struct V_57 * clock , struct V_17 * V_18 )
{
F_77 ( & clock -> V_154 ) ;
clock -> V_18 = V_18 ;
F_78 ( & clock -> V_79 ) ;
F_78 ( & clock -> V_223 ) ;
F_77 ( & clock -> V_129 ) ;
clock -> V_90 . V_224 = V_225 ;
sprintf ( clock -> V_90 . V_6 , L_15 ) ;
clock -> V_90 . V_226 = 1953124 ;
clock -> V_90 . V_227 = 0 ;
clock -> V_90 . V_228 = V_111 ;
clock -> V_90 . V_229 = V_124 ;
clock -> V_90 . V_230 = V_5 ;
clock -> V_90 . V_231 = 0 ;
clock -> V_90 . V_232 = F_16 ;
clock -> V_90 . V_233 = F_19 ;
clock -> V_90 . V_234 = F_21 ;
clock -> V_90 . V_235 = F_22 ;
clock -> V_90 . V_236 = F_23 ;
clock -> V_90 . V_237 = F_24 ;
F_1 ( clock -> V_90 . V_128 ) ;
F_79 ( & V_18 -> V_31 ) ;
}
static int F_80 ( struct V_57 * clock ,
struct V_22 * V_23 )
{
if ( V_238 == - 1 && ! clock -> V_62 )
return 1 ;
if ( V_238 == V_23 -> V_239 )
return 1 ;
return 0 ;
}
static struct V_57 * F_81 ( struct V_57 * clock )
{
if ( clock )
F_14 ( & clock -> V_223 ) ;
return clock ;
}
static struct V_57 * F_82 ( struct V_17 * V_18 )
{
struct V_57 * clock = NULL , * V_162 ;
struct V_151 * V_152 ;
F_14 ( & V_222 ) ;
F_41 (this, &phyter_clocks) {
V_162 = F_36 ( V_152 , struct V_57 , V_154 ) ;
if ( V_162 -> V_18 == V_18 ) {
clock = V_162 ;
break;
}
}
if ( clock )
goto V_208;
clock = F_83 ( sizeof( struct V_57 ) , V_240 ) ;
if ( ! clock )
goto V_208;
clock -> V_90 . V_128 = F_83 ( sizeof( struct V_1 ) *
V_5 , V_240 ) ;
if ( ! clock -> V_90 . V_128 ) {
F_75 ( clock ) ;
clock = NULL ;
goto V_208;
}
F_76 ( clock , V_18 ) ;
F_62 ( & V_241 , & clock -> V_154 ) ;
V_208:
F_15 ( & V_222 ) ;
return F_81 ( clock ) ;
}
static void F_84 ( struct V_57 * clock )
{
F_15 ( & clock -> V_223 ) ;
}
static int F_85 ( struct V_22 * V_23 )
{
struct V_57 * clock ;
struct V_25 * V_26 ;
int V_100 = - V_242 , V_3 ;
if ( V_23 -> V_239 == V_21 )
return 0 ;
clock = F_82 ( V_23 -> V_18 ) ;
if ( ! clock )
goto V_243;
V_26 = F_83 ( sizeof( struct V_25 ) , V_240 ) ;
if ( ! V_26 )
goto V_244;
V_26 -> V_23 = V_23 ;
F_86 ( & V_26 -> V_245 , V_246 ) ;
F_77 ( & V_26 -> V_42 ) ;
F_77 ( & V_26 -> V_155 ) ;
for ( V_3 = 0 ; V_3 < V_247 ; V_3 ++ )
F_38 ( & V_26 -> V_248 [ V_3 ] . V_154 , & V_26 -> V_155 ) ;
V_23 -> V_27 = V_26 ;
F_87 ( & V_26 -> V_207 ) ;
F_88 ( & V_26 -> V_209 ) ;
F_88 ( & V_26 -> V_216 ) ;
V_26 -> clock = clock ;
if ( F_80 ( clock , V_23 ) ) {
clock -> V_62 = V_26 ;
clock -> V_67 = F_89 ( & clock -> V_90 , & V_23 -> V_31 ) ;
if ( F_90 ( clock -> V_67 ) ) {
V_100 = F_91 ( clock -> V_67 ) ;
goto V_249;
}
} else
F_62 ( & V_26 -> V_154 , & clock -> V_129 ) ;
F_84 ( clock ) ;
return 0 ;
V_249:
clock -> V_62 = NULL ;
F_75 ( V_26 ) ;
V_244:
F_84 ( clock ) ;
V_243:
return V_100 ;
}
static void F_92 ( struct V_22 * V_23 )
{
struct V_57 * clock ;
struct V_151 * V_152 , * V_153 ;
struct V_25 * V_162 , * V_26 = V_23 -> V_27 ;
if ( V_23 -> V_239 == V_21 )
return;
F_26 ( V_23 , false ) ;
F_93 ( & V_26 -> V_245 ) ;
F_94 ( & V_26 -> V_209 ) ;
F_94 ( & V_26 -> V_216 ) ;
clock = F_81 ( V_26 -> clock ) ;
if ( V_26 == clock -> V_62 ) {
F_95 ( clock -> V_67 ) ;
clock -> V_62 = NULL ;
} else {
F_35 (this, next, &clock->phylist) {
V_162 = F_36 ( V_152 , struct V_25 , V_154 ) ;
if ( V_162 == V_26 ) {
F_37 ( & V_162 -> V_154 ) ;
break;
}
}
}
F_84 ( clock ) ;
F_75 ( V_26 ) ;
}
static int F_96 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_57 * clock = V_26 -> clock ;
if ( clock -> V_62 && ! F_25 ( & clock -> V_129 ) )
F_40 ( clock ) ;
else {
F_14 ( & clock -> V_79 ) ;
F_39 ( V_23 , clock -> V_24 , 1 ) ;
F_15 ( & clock -> V_79 ) ;
}
F_26 ( V_23 , true ) ;
F_14 ( & clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_166 ) ;
F_15 ( & clock -> V_79 ) ;
return 0 ;
}
static int F_97 ( struct V_22 * V_23 )
{
int V_100 = F_6 ( V_23 , V_250 ) ;
if ( V_100 < 0 )
return V_100 ;
return 0 ;
}
static int F_98 ( struct V_22 * V_23 )
{
int V_251 ;
int V_252 ;
int V_100 ;
if ( V_23 -> V_253 == V_254 ) {
V_252 = F_6 ( V_23 , V_250 ) ;
if ( V_252 < 0 )
return V_252 ;
V_252 |=
( V_255 |
V_256 |
V_257 |
V_258 ) ;
V_100 = F_8 ( V_23 , V_250 , V_252 ) ;
if ( V_100 < 0 )
return V_100 ;
V_251 = F_6 ( V_23 , V_259 ) ;
if ( V_251 < 0 )
return V_251 ;
V_251 |=
( V_260 |
V_261 ) ;
return F_8 ( V_23 , V_259 , V_251 ) ;
} else {
V_251 = F_6 ( V_23 , V_259 ) ;
if ( V_251 < 0 )
return V_251 ;
V_251 &=
~ ( V_260 |
V_261 ) ;
V_100 = F_8 ( V_23 , V_259 , V_251 ) ;
if ( V_100 < 0 )
return V_100 ;
V_252 = F_6 ( V_23 , V_250 ) ;
if ( V_252 < 0 )
return V_252 ;
V_252 &=
~ ( V_255 |
V_256 |
V_257 |
V_258 ) ;
return F_8 ( V_23 , V_250 , V_252 ) ;
}
}
static int F_99 ( struct V_22 * V_23 , struct V_262 * V_263 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_264 V_265 ;
T_2 V_266 , V_267 ;
if ( F_100 ( & V_265 , V_263 -> V_268 , sizeof( V_265 ) ) )
return - V_269 ;
if ( V_265 . V_118 )
return - V_68 ;
if ( V_265 . V_270 < 0 || V_265 . V_270 > V_271 )
return - V_272 ;
V_26 -> V_273 = V_265 . V_270 ;
switch ( V_265 . V_274 ) {
case V_275 :
V_26 -> V_276 = 0 ;
V_26 -> V_277 = 0 ;
V_26 -> V_278 = 0 ;
break;
case V_279 :
case V_280 :
case V_281 :
V_26 -> V_276 = 1 ;
V_26 -> V_277 = V_282 ;
V_26 -> V_278 = V_201 ;
break;
case V_283 :
case V_284 :
case V_285 :
V_26 -> V_276 = 1 ;
V_26 -> V_277 = V_282 ;
V_26 -> V_278 = V_286 ;
break;
case V_287 :
case V_288 :
case V_289 :
V_26 -> V_276 = 1 ;
V_26 -> V_277 = V_199 ;
V_26 -> V_278 = V_286 ;
break;
case V_290 :
case V_291 :
case V_292 :
V_26 -> V_276 = 1 ;
V_26 -> V_277 = V_282 | V_199 ;
V_26 -> V_278 = V_286 ;
break;
default:
return - V_272 ;
}
V_266 = ( V_26 -> V_278 & V_293 ) << V_294 ;
V_267 = ( V_26 -> V_278 & V_293 ) << V_294 ;
if ( V_26 -> V_277 & V_199 ) {
V_266 |= V_295 ;
V_267 |= V_296 ;
}
if ( V_26 -> V_277 & V_282 ) {
V_266 |= V_297 | V_298 ;
V_267 |= V_299 | V_300 ;
}
if ( V_26 -> V_273 )
V_266 |= V_301 ;
if ( V_26 -> V_273 == V_271 )
V_266 |= V_302 | V_303 ;
if ( V_26 -> V_276 )
V_267 |= V_304 ;
F_14 ( & V_26 -> clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_80 , V_305 , V_266 ) ;
F_7 ( 0 , V_23 , V_80 , V_306 , V_267 ) ;
F_15 ( & V_26 -> clock -> V_79 ) ;
return F_101 ( V_263 -> V_268 , & V_265 , sizeof( V_265 ) ) ? - V_269 : 0 ;
}
static void V_246 ( struct V_307 * V_308 )
{
struct V_25 * V_26 =
F_17 ( V_308 , struct V_25 , V_245 . V_308 ) ;
struct V_144 * V_145 ;
while ( ( V_145 = F_65 ( & V_26 -> V_209 ) ) ) {
struct V_211 * V_212 ;
V_212 = (struct V_211 * ) V_145 -> V_213 ;
if ( ! F_33 ( V_54 , V_212 -> V_53 ) ) {
F_102 ( & V_26 -> V_209 , V_145 ) ;
break;
}
F_60 ( V_145 ) ;
}
if ( ! F_103 ( & V_26 -> V_209 ) )
F_104 ( & V_26 -> V_245 , V_55 ) ;
}
static bool F_105 ( struct V_22 * V_23 ,
struct V_144 * V_145 , int type )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_211 * V_212 = (struct V_211 * ) V_145 -> V_213 ;
struct V_151 * V_152 , * V_153 ;
struct V_42 * V_42 ;
struct V_205 * V_206 = NULL ;
unsigned long V_118 ;
if ( F_30 ( V_145 , type ) ) {
F_67 ( V_26 , V_145 ) ;
F_106 ( V_145 ) ;
return true ;
}
if ( ! V_26 -> V_276 )
return false ;
if ( ( type & V_26 -> V_278 ) == 0 || ( type & V_26 -> V_277 ) == 0 )
return false ;
F_52 ( & V_26 -> V_207 , V_118 ) ;
F_34 ( V_26 ) ;
F_35 (this, next, &dp83640->rxts) {
V_42 = F_36 ( V_152 , struct V_42 , V_154 ) ;
if ( F_45 ( V_145 , type , V_42 ) ) {
V_206 = F_58 ( V_145 ) ;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
V_206 -> V_215 = F_59 ( V_42 -> V_46 ) ;
F_60 ( V_145 ) ;
F_37 ( & V_42 -> V_154 ) ;
F_38 ( & V_42 -> V_154 , & V_26 -> V_155 ) ;
break;
}
}
F_63 ( & V_26 -> V_207 , V_118 ) ;
if ( ! V_206 ) {
V_212 -> V_214 = type ;
V_212 -> V_53 = V_54 + V_55 ;
F_107 ( & V_26 -> V_209 , V_145 ) ;
F_104 ( & V_26 -> V_245 , V_55 ) ;
} else {
F_60 ( V_145 ) ;
}
return true ;
}
static void F_108 ( struct V_22 * V_23 ,
struct V_144 * V_145 , int type )
{
struct V_25 * V_26 = V_23 -> V_27 ;
switch ( V_26 -> V_273 ) {
case V_271 :
if ( F_69 ( V_145 , type ) ) {
F_106 ( V_145 ) ;
return;
}
case V_309 :
F_109 ( V_145 ) -> V_310 |= V_311 ;
F_107 ( & V_26 -> V_216 , V_145 ) ;
break;
case V_312 :
default:
F_106 ( V_145 ) ;
break;
}
}
static int F_110 ( struct V_22 * V_31 , struct V_313 * V_314 )
{
struct V_25 * V_26 = V_31 -> V_27 ;
V_314 -> V_315 =
V_316 |
V_317 |
V_318 ;
V_314 -> V_319 = F_111 ( V_26 -> clock -> V_67 ) ;
V_314 -> V_320 =
( 1 << V_312 ) |
( 1 << V_309 ) |
( 1 << V_271 ) ;
V_314 -> V_321 =
( 1 << V_275 ) |
( 1 << V_279 ) |
( 1 << V_283 ) |
( 1 << V_287 ) |
( 1 << V_290 ) ;
return 0 ;
}
static int T_6 F_112 ( void )
{
return F_113 ( & V_322 ) ;
}
static void T_7 F_114 ( void )
{
F_70 () ;
F_115 ( & V_322 ) ;
}
