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
V_42 -> V_53 = V_54 + 2 ;
}
static V_49 F_11 ( struct V_55 * V_41 )
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
static int F_12 ( struct V_56 * clock ,
struct V_57 * V_58 , bool V_59 ,
int V_60 )
{
struct V_25 * V_26 = clock -> V_61 ;
struct V_22 * V_23 = V_26 -> V_23 ;
T_1 V_43 , V_62 , V_63 ;
T_2 V_64 , V_65 , V_20 ;
if ( V_59 ) {
V_64 = 1 + F_13 ( clock -> V_66 , V_14 ,
V_60 ) ;
if ( V_64 < 1 )
return - V_67 ;
} else {
V_64 = 0 ;
}
V_65 = V_68 |
( V_60 & V_69 ) << V_70 |
( V_64 & V_71 ) << V_72 |
V_73 |
V_74 ;
V_20 = ( V_60 & V_75 ) << V_76 ;
if ( ! V_59 ) {
V_20 |= V_77 ;
F_14 ( & clock -> V_78 ) ;
F_7 ( 0 , V_23 , V_79 , V_80 , V_65 ) ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_20 ) ;
F_15 ( & clock -> V_78 ) ;
return 0 ;
}
V_43 = V_58 -> V_81 . V_82 . V_43 ;
V_62 = V_58 -> V_81 . V_82 . V_62 ;
V_63 = V_58 -> V_81 . V_83 . V_43 * 1000000000UL ;
V_63 += V_58 -> V_81 . V_83 . V_62 ;
V_63 /= 2 ;
F_14 ( & clock -> V_78 ) ;
F_7 ( 0 , V_23 , V_79 , V_80 , V_65 ) ;
V_20 |= V_84 ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_20 ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_62 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_62 >> 16 ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_43 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_43 >> 16 ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_63 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_63 >> 16 ) ;
if ( V_60 < 2 ) {
F_7 ( 0 , V_23 , V_35 , V_36 , V_63 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_63 >> 16 ) ;
}
V_20 &= ~ V_84 ;
V_20 |= V_85 ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_20 ) ;
F_15 ( & clock -> V_78 ) ;
return 0 ;
}
static int F_16 ( struct V_86 * V_87 , T_3 V_88 )
{
struct V_56 * clock =
F_17 ( V_87 , struct V_56 , V_89 ) ;
struct V_22 * V_23 = clock -> V_61 -> V_23 ;
V_49 V_90 ;
int V_91 = 0 ;
T_2 V_92 , V_93 ;
if ( V_88 < 0 ) {
V_91 = 1 ;
V_88 = - V_88 ;
}
V_90 = V_88 ;
V_90 <<= 26 ;
V_90 = F_18 ( V_90 , 1953125 ) ;
V_92 = ( V_90 >> 16 ) & V_94 ;
if ( V_91 )
V_92 |= V_95 ;
V_93 = V_90 & 0xffff ;
F_14 ( & clock -> V_78 ) ;
F_7 ( 1 , V_23 , V_35 , V_96 , V_92 ) ;
F_7 ( 1 , V_23 , V_35 , V_97 , V_93 ) ;
F_15 ( & clock -> V_78 ) ;
return 0 ;
}
static int F_19 ( struct V_86 * V_87 , T_4 V_98 )
{
struct V_56 * clock =
F_17 ( V_87 , struct V_56 , V_89 ) ;
struct V_22 * V_23 = clock -> V_61 -> V_23 ;
struct V_32 V_33 ;
int V_99 ;
V_98 += V_100 ;
V_33 = F_20 ( V_98 ) ;
F_14 ( & clock -> V_78 ) ;
V_99 = F_9 ( 1 , V_23 , & V_33 , V_101 ) ;
F_15 ( & clock -> V_78 ) ;
return V_99 ;
}
static int F_21 ( struct V_86 * V_87 , struct V_32 * V_33 )
{
struct V_56 * clock =
F_17 ( V_87 , struct V_56 , V_89 ) ;
struct V_22 * V_23 = clock -> V_61 -> V_23 ;
unsigned int V_20 [ 4 ] ;
F_14 ( & clock -> V_78 ) ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_102 ) ;
V_20 [ 0 ] = F_5 ( V_23 , V_35 , V_36 ) ;
V_20 [ 1 ] = F_5 ( V_23 , V_35 , V_36 ) ;
V_20 [ 2 ] = F_5 ( V_23 , V_35 , V_36 ) ;
V_20 [ 3 ] = F_5 ( V_23 , V_35 , V_36 ) ;
F_15 ( & clock -> V_78 ) ;
V_33 -> V_37 = V_20 [ 0 ] | ( V_20 [ 1 ] << 16 ) ;
V_33 -> V_38 = V_20 [ 2 ] | ( V_20 [ 3 ] << 16 ) ;
return 0 ;
}
static int F_22 ( struct V_86 * V_87 ,
const struct V_32 * V_33 )
{
struct V_56 * clock =
F_17 ( V_87 , struct V_56 , V_89 ) ;
struct V_22 * V_23 = clock -> V_61 -> V_23 ;
int V_99 ;
F_14 ( & clock -> V_78 ) ;
V_99 = F_9 ( 1 , V_23 , V_33 , V_103 ) ;
F_15 ( & clock -> V_78 ) ;
return V_99 ;
}
static int F_23 ( struct V_86 * V_87 ,
struct V_57 * V_104 , int V_59 )
{
struct V_56 * clock =
F_17 ( V_87 , struct V_56 , V_89 ) ;
struct V_22 * V_23 = clock -> V_61 -> V_23 ;
unsigned int V_4 ;
T_2 V_105 , V_106 , V_107 ;
switch ( V_104 -> type ) {
case V_108 :
V_4 = V_104 -> V_109 . V_4 ;
if ( V_4 >= V_110 )
return - V_67 ;
V_106 = V_111 + V_4 ;
V_105 = V_112 | ( V_106 & V_113 ) << V_114 ;
if ( V_59 ) {
V_107 = 1 + F_13 ( clock -> V_66 ,
V_16 , V_4 ) ;
if ( V_107 < 1 )
return - V_67 ;
V_105 |= ( V_107 & V_115 ) << V_116 ;
if ( V_104 -> V_109 . V_117 & V_118 )
V_105 |= V_119 ;
else
V_105 |= V_120 ;
}
F_7 ( 0 , V_23 , V_79 , V_121 , V_105 ) ;
return 0 ;
case V_122 :
if ( V_104 -> V_81 . V_4 >= V_123 )
return - V_67 ;
return F_12 ( clock , V_104 , V_59 , V_104 -> V_81 . V_4 ) ;
default:
break;
}
return - V_124 ;
}
static int F_24 ( struct V_86 * V_87 , unsigned int V_125 ,
enum V_126 V_10 , unsigned int V_12 )
{
struct V_56 * clock =
F_17 ( V_87 , struct V_56 , V_89 ) ;
if ( clock -> V_89 . V_127 [ V_125 ] . V_10 == V_11 &&
! F_25 ( & clock -> V_128 ) )
return 1 ;
if ( V_10 == V_11 )
return 1 ;
return 0 ;
}
static void F_26 ( struct V_22 * V_23 , bool V_59 )
{
T_2 V_129 = 0 , V_130 ;
if ( V_59 )
V_129 = V_131 | V_132 | V_133 | V_134 ;
V_130 = ( V_135 & V_136 ) << V_137 ;
F_7 ( 0 , V_23 , V_79 , V_138 , V_129 ) ;
F_7 ( 0 , V_23 , V_139 , V_140 , V_130 ) ;
if ( ! V_23 -> V_141 ) {
F_27 ( L_3 ) ;
return;
}
if ( V_59 ) {
if ( F_28 ( V_23 -> V_141 , V_142 ) )
F_27 ( L_4 ) ;
} else {
if ( F_29 ( V_23 -> V_141 , V_142 ) )
F_27 ( L_5 ) ;
}
}
static bool F_30 ( struct V_143 * V_144 , int type )
{
struct V_145 * V_146 = F_31 ( V_144 ) ;
if ( V_147 == type &&
! memcmp ( V_146 -> V_148 , V_149 , sizeof( V_149 ) ) )
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
struct V_150 * V_151 , * V_152 ;
struct V_42 * V_42 ;
F_35 (this, next, &dp83640->rxts) {
V_42 = F_36 ( V_151 , struct V_42 , V_153 ) ;
if ( F_32 ( V_42 ) ) {
F_37 ( & V_42 -> V_153 ) ;
F_38 ( & V_42 -> V_153 , & V_26 -> V_154 ) ;
}
}
}
static void F_39 ( struct V_22 * V_23 , int V_155 , int V_59 )
{
int V_20 ;
F_8 ( V_23 , V_28 , 0 ) ;
V_20 = F_6 ( V_23 , V_156 ) ;
if ( V_59 )
V_20 |= V_157 ;
else
V_20 &= ~ V_157 ;
F_8 ( V_23 , V_156 , V_20 ) ;
F_8 ( V_23 , V_28 , V_155 ) ;
}
static void F_40 ( struct V_56 * clock )
{
T_4 V_158 , V_159 ;
struct V_55 V_160 ;
struct V_32 V_33 ;
struct V_150 * V_151 ;
struct V_25 * V_161 ;
struct V_22 * V_162 = clock -> V_61 -> V_23 ;
T_2 V_163 , V_129 , V_105 , V_65 , V_60 , V_20 ;
V_60 = V_164 ;
V_163 = 1 + F_13 ( clock -> V_66 , V_11 , 0 ) ;
if ( V_163 < 1 ) {
F_2 ( L_6 ) ;
return;
}
F_14 ( & clock -> V_78 ) ;
F_41 (this, &clock->phylist) {
V_161 = F_36 ( V_151 , struct V_25 , V_153 ) ;
F_39 ( V_161 -> V_23 , clock -> V_24 , 1 ) ;
V_161 -> V_129 = F_5 ( V_161 -> V_23 , V_79 , V_138 ) ;
F_7 ( 0 , V_161 -> V_23 , V_79 , V_138 , 0 ) ;
F_7 ( 0 , V_161 -> V_23 , V_35 , V_39 , V_165 ) ;
}
F_39 ( V_162 , clock -> V_24 , 1 ) ;
V_129 = F_5 ( V_162 , V_79 , V_138 ) ;
F_7 ( 0 , V_162 , V_79 , V_138 , 0 ) ;
F_7 ( 0 , V_162 , V_35 , V_39 , V_165 ) ;
V_105 = V_112 | V_120 | V_166 ;
V_105 |= ( V_167 & V_113 ) << V_114 ;
V_105 |= ( V_163 & V_115 ) << V_116 ;
F_41 (this, &clock->phylist) {
V_161 = F_36 ( V_151 , struct V_25 , V_153 ) ;
F_7 ( 0 , V_161 -> V_23 , V_79 , V_121 , V_105 ) ;
}
F_7 ( 0 , V_162 , V_79 , V_121 , V_105 ) ;
V_65 = V_68 | V_168 | V_74 ;
V_65 |= ( V_60 & V_69 ) << V_70 ;
V_65 |= ( V_163 & V_71 ) << V_72 ;
F_7 ( 0 , V_162 , V_79 , V_80 , V_65 ) ;
V_20 = ( V_60 & V_75 ) << V_76 ;
V_20 |= V_84 ;
F_7 ( 0 , V_162 , V_35 , V_39 , V_20 ) ;
V_20 &= ~ V_84 ;
V_20 |= V_85 ;
F_7 ( 0 , V_162 , V_35 , V_39 , V_20 ) ;
V_20 = ( V_60 & V_75 ) << V_76 ;
V_20 |= V_77 ;
F_7 ( 0 , V_162 , V_35 , V_39 , V_20 ) ;
V_20 = F_5 ( V_162 , V_35 , V_169 ) ;
F_42 ( L_7 , V_20 ) ;
V_20 = F_5 ( V_162 , V_35 , V_170 ) ;
F_42 ( L_8 , V_20 ) ;
V_160 . V_47 = F_5 ( V_162 , V_35 , V_171 ) ;
V_160 . V_48 = F_5 ( V_162 , V_35 , V_171 ) ;
V_160 . V_44 = F_5 ( V_162 , V_35 , V_171 ) ;
V_160 . V_45 = F_5 ( V_162 , V_35 , V_171 ) ;
V_158 = F_11 ( & V_160 ) ;
F_41 (this, &clock->phylist) {
V_161 = F_36 ( V_151 , struct V_25 , V_153 ) ;
V_20 = F_5 ( V_161 -> V_23 , V_35 , V_169 ) ;
F_42 ( L_9 , V_20 ) ;
V_20 = F_5 ( V_161 -> V_23 , V_35 , V_170 ) ;
F_42 ( L_10 , V_20 ) ;
V_160 . V_47 = F_5 ( V_161 -> V_23 , V_35 , V_171 ) ;
V_160 . V_48 = F_5 ( V_161 -> V_23 , V_35 , V_171 ) ;
V_160 . V_44 = F_5 ( V_161 -> V_23 , V_35 , V_171 ) ;
V_160 . V_45 = F_5 ( V_161 -> V_23 , V_35 , V_171 ) ;
V_159 = V_158 - ( T_4 ) F_11 ( & V_160 ) ;
F_42 ( L_11 , V_159 ) ;
V_159 += V_100 ;
V_33 = F_20 ( V_159 ) ;
F_9 ( 0 , V_161 -> V_23 , & V_33 , V_101 ) ;
}
F_41 (this, &clock->phylist) {
V_161 = F_36 ( V_151 , struct V_25 , V_153 ) ;
F_7 ( 0 , V_161 -> V_23 , V_79 , V_138 , V_161 -> V_129 ) ;
}
F_7 ( 0 , V_162 , V_79 , V_138 , V_129 ) ;
F_15 ( & clock -> V_78 ) ;
}
static inline T_2 F_43 ( int V_172 )
{
return 1 << ( ( V_172 + V_111 ) * 2 ) ;
}
static int F_44 ( struct V_25 * V_26 ,
void * V_173 , T_2 V_174 )
{
struct V_55 * V_55 ;
struct V_175 V_176 ;
int V_3 , V_177 ;
int V_178 = ( V_174 >> V_179 ) & V_180 ;
T_2 V_181 = 0 ;
if ( V_174 & V_182 ) {
V_181 = * ( T_2 * ) V_173 ;
V_173 += sizeof( V_181 ) ;
}
V_55 = V_173 ;
switch ( V_178 ) {
case 3 :
V_26 -> V_183 . V_45 = V_55 -> V_45 ;
case 2 :
V_26 -> V_183 . V_44 = V_55 -> V_44 ;
case 1 :
V_26 -> V_183 . V_48 = V_55 -> V_48 ;
case 0 :
V_26 -> V_183 . V_47 = V_55 -> V_47 ;
}
if ( V_181 ) {
V_177 = V_178 + 2 ;
} else {
V_177 = V_178 + 1 ;
V_3 = ( ( V_174 >> V_184 ) & V_185 ) - V_111 ;
V_181 = F_43 ( V_3 ) ;
}
V_176 . type = V_186 ;
V_176 . V_187 = F_11 ( & V_26 -> V_183 ) ;
V_176 . V_187 -= 35 ;
for ( V_3 = 0 ; V_3 < V_110 ; V_3 ++ ) {
if ( V_181 & F_43 ( V_3 ) ) {
V_176 . V_4 = V_3 ;
V_175 ( V_26 -> clock -> V_66 , & V_176 ) ;
}
}
return V_177 * sizeof( T_2 ) ;
}
static int F_45 ( struct V_143 * V_144 , unsigned int type , struct V_42 * V_42 )
{
T_2 * V_50 ;
unsigned int V_188 = 0 ;
T_5 * V_51 , * V_173 = F_46 ( V_144 ) ;
if ( type & V_189 )
V_188 += V_190 ;
switch ( type & V_191 ) {
case V_192 :
V_188 += V_193 + F_47 ( V_173 ) + V_194 ;
break;
case V_195 :
V_188 += V_193 + V_196 + V_194 ;
break;
case V_197 :
V_188 += V_193 ;
break;
default:
return 0 ;
}
if ( V_144 -> V_198 + V_193 < V_188 + V_199 + sizeof( * V_50 ) )
return 0 ;
if ( F_48 ( type & V_200 ) )
V_51 = V_173 + V_188 + V_201 ;
else
V_51 = V_173 + V_188 ;
V_50 = ( T_2 * ) ( V_173 + V_188 + V_199 ) ;
return V_42 -> V_51 == ( * V_51 & 0xf ) &&
V_42 -> V_50 == F_49 ( * V_50 ) ;
}
static void F_50 ( struct V_25 * V_26 ,
struct V_40 * V_40 )
{
struct V_42 * V_42 ;
struct V_202 * V_203 = NULL ;
struct V_143 * V_144 ;
unsigned long V_117 ;
F_51 ( & V_26 -> V_204 , V_117 ) ;
F_34 ( V_26 ) ;
if ( F_25 ( & V_26 -> V_154 ) ) {
F_52 ( L_12 ) ;
goto V_205;
}
V_42 = F_53 ( & V_26 -> V_154 , struct V_42 , V_153 ) ;
F_37 ( & V_42 -> V_153 ) ;
F_10 ( V_40 , V_42 ) ;
F_51 ( & V_26 -> V_206 . V_207 , V_117 ) ;
F_54 (&dp83640->rx_queue, skb) {
struct V_208 * V_209 ;
V_209 = (struct V_208 * ) V_144 -> V_210 ;
if ( F_45 ( V_144 , V_209 -> V_211 , V_42 ) ) {
F_55 ( V_144 , & V_26 -> V_206 ) ;
V_203 = F_56 ( V_144 ) ;
memset ( V_203 , 0 , sizeof( * V_203 ) ) ;
V_203 -> V_212 = F_57 ( V_42 -> V_46 ) ;
F_58 ( V_144 ) ;
F_38 ( & V_42 -> V_153 , & V_26 -> V_154 ) ;
break;
}
}
F_59 ( & V_26 -> V_206 . V_207 , V_117 ) ;
if ( ! V_203 )
F_60 ( & V_42 -> V_153 , & V_26 -> V_42 ) ;
V_205:
F_59 ( & V_26 -> V_204 , V_117 ) ;
}
static void F_61 ( struct V_25 * V_26 ,
struct V_55 * V_55 )
{
struct V_202 V_203 ;
struct V_143 * V_144 ;
V_49 V_46 ;
V_144 = F_62 ( & V_26 -> V_213 ) ;
if ( ! V_144 ) {
F_52 ( L_13 ) ;
return;
}
V_46 = F_11 ( V_55 ) ;
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
V_203 . V_212 = F_57 ( V_46 ) ;
F_63 ( V_144 , & V_203 ) ;
}
static void F_64 ( struct V_25 * V_26 ,
struct V_143 * V_144 )
{
struct V_40 * V_40 ;
struct V_55 * V_55 ;
T_5 * V_214 ;
int V_198 , V_215 ;
T_2 V_174 , type ;
V_214 = V_144 -> V_173 + 2 ;
for ( V_198 = F_65 ( V_144 ) - 2 ; V_198 > sizeof( type ) ; V_198 -= V_215 ) {
type = * ( T_2 * ) V_214 ;
V_174 = type & 0x0fff ;
type = type & 0xf000 ;
V_198 -= sizeof( type ) ;
V_214 += sizeof( type ) ;
if ( V_216 == type && V_198 >= sizeof( * V_40 ) ) {
V_40 = (struct V_40 * ) V_214 ;
F_50 ( V_26 , V_40 ) ;
V_215 = sizeof( * V_40 ) ;
} else if ( V_217 == type && V_198 >= sizeof( * V_55 ) ) {
V_55 = (struct V_55 * ) V_214 ;
F_61 ( V_26 , V_55 ) ;
V_215 = sizeof( * V_55 ) ;
} else if ( V_218 == type && V_198 >= sizeof( * V_55 ) ) {
V_215 = F_44 ( V_26 , V_214 , V_174 ) ;
} else {
V_215 = 0 ;
break;
}
V_214 += V_215 ;
}
}
static int F_66 ( struct V_143 * V_144 , int type )
{
T_5 * V_173 = V_144 -> V_173 , * V_51 ;
unsigned int V_188 = 0 ;
if ( type & V_189 )
V_188 += V_190 ;
switch ( type & V_191 ) {
case V_192 :
V_188 += V_193 + F_47 ( V_173 ) + V_194 ;
break;
case V_195 :
V_188 += V_193 + V_196 + V_194 ;
break;
case V_197 :
V_188 += V_193 ;
break;
default:
return 0 ;
}
if ( type & V_200 )
V_188 += V_201 ;
if ( V_144 -> V_198 < V_188 + 1 )
return 0 ;
V_51 = V_173 + V_188 ;
return ( * V_51 & 0xf ) == 0 ;
}
static void F_67 ( void )
{
struct V_56 * clock ;
struct V_150 * V_151 , * V_152 ;
F_14 ( & V_219 ) ;
F_35 (this, next, &phyter_clocks) {
clock = F_36 ( V_151 , struct V_56 , V_153 ) ;
if ( ! F_25 ( & clock -> V_128 ) ) {
F_27 ( L_14 ) ;
F_68 () ;
}
F_69 ( & clock -> V_153 ) ;
F_70 ( & clock -> V_78 ) ;
F_70 ( & clock -> V_220 ) ;
F_71 ( & clock -> V_18 -> V_31 ) ;
F_72 ( clock -> V_89 . V_127 ) ;
F_72 ( clock ) ;
}
F_15 ( & V_219 ) ;
}
static void F_73 ( struct V_56 * clock , struct V_17 * V_18 )
{
F_74 ( & clock -> V_153 ) ;
clock -> V_18 = V_18 ;
F_75 ( & clock -> V_78 ) ;
F_75 ( & clock -> V_220 ) ;
F_74 ( & clock -> V_128 ) ;
clock -> V_89 . V_221 = V_222 ;
sprintf ( clock -> V_89 . V_6 , L_15 ) ;
clock -> V_89 . V_223 = 1953124 ;
clock -> V_89 . V_224 = 0 ;
clock -> V_89 . V_225 = V_110 ;
clock -> V_89 . V_226 = V_123 ;
clock -> V_89 . V_227 = V_5 ;
clock -> V_89 . V_228 = 0 ;
clock -> V_89 . V_229 = F_16 ;
clock -> V_89 . V_230 = F_19 ;
clock -> V_89 . V_231 = F_21 ;
clock -> V_89 . V_232 = F_22 ;
clock -> V_89 . V_233 = F_23 ;
clock -> V_89 . V_234 = F_24 ;
F_1 ( clock -> V_89 . V_127 ) ;
F_76 ( & V_18 -> V_31 ) ;
}
static int F_77 ( struct V_56 * clock ,
struct V_22 * V_23 )
{
if ( V_235 == - 1 && ! clock -> V_61 )
return 1 ;
if ( V_235 == V_23 -> V_236 )
return 1 ;
return 0 ;
}
static struct V_56 * F_78 ( struct V_56 * clock )
{
if ( clock )
F_14 ( & clock -> V_220 ) ;
return clock ;
}
static struct V_56 * F_79 ( struct V_17 * V_18 )
{
struct V_56 * clock = NULL , * V_161 ;
struct V_150 * V_151 ;
F_14 ( & V_219 ) ;
F_41 (this, &phyter_clocks) {
V_161 = F_36 ( V_151 , struct V_56 , V_153 ) ;
if ( V_161 -> V_18 == V_18 ) {
clock = V_161 ;
break;
}
}
if ( clock )
goto V_205;
clock = F_80 ( sizeof( struct V_56 ) , V_237 ) ;
if ( ! clock )
goto V_205;
clock -> V_89 . V_127 = F_80 ( sizeof( struct V_1 ) *
V_5 , V_237 ) ;
if ( ! clock -> V_89 . V_127 ) {
F_72 ( clock ) ;
clock = NULL ;
goto V_205;
}
F_73 ( clock , V_18 ) ;
F_60 ( & V_238 , & clock -> V_153 ) ;
V_205:
F_15 ( & V_219 ) ;
return F_78 ( clock ) ;
}
static void F_81 ( struct V_56 * clock )
{
F_15 ( & clock -> V_220 ) ;
}
static int F_82 ( struct V_22 * V_23 )
{
struct V_56 * clock ;
struct V_25 * V_26 ;
int V_99 = - V_239 , V_3 ;
if ( V_23 -> V_236 == V_21 )
return 0 ;
clock = F_79 ( V_23 -> V_18 ) ;
if ( ! clock )
goto V_240;
V_26 = F_80 ( sizeof( struct V_25 ) , V_237 ) ;
if ( ! V_26 )
goto V_241;
V_26 -> V_23 = V_23 ;
F_83 ( & V_26 -> V_242 , V_243 ) ;
F_74 ( & V_26 -> V_42 ) ;
F_74 ( & V_26 -> V_154 ) ;
for ( V_3 = 0 ; V_3 < V_244 ; V_3 ++ )
F_38 ( & V_26 -> V_245 [ V_3 ] . V_153 , & V_26 -> V_154 ) ;
V_23 -> V_27 = V_26 ;
F_84 ( & V_26 -> V_204 ) ;
F_85 ( & V_26 -> V_206 ) ;
F_85 ( & V_26 -> V_213 ) ;
V_26 -> clock = clock ;
if ( F_77 ( clock , V_23 ) ) {
clock -> V_61 = V_26 ;
clock -> V_66 = F_86 ( & clock -> V_89 , & V_23 -> V_31 ) ;
if ( F_87 ( clock -> V_66 ) ) {
V_99 = F_88 ( clock -> V_66 ) ;
goto V_246;
}
} else
F_60 ( & V_26 -> V_153 , & clock -> V_128 ) ;
F_81 ( clock ) ;
return 0 ;
V_246:
clock -> V_61 = NULL ;
F_72 ( V_26 ) ;
V_241:
F_81 ( clock ) ;
V_240:
return V_99 ;
}
static void F_89 ( struct V_22 * V_23 )
{
struct V_56 * clock ;
struct V_150 * V_151 , * V_152 ;
struct V_25 * V_161 , * V_26 = V_23 -> V_27 ;
struct V_143 * V_144 ;
if ( V_23 -> V_236 == V_21 )
return;
F_26 ( V_23 , false ) ;
F_90 ( & V_26 -> V_242 ) ;
while ( ( V_144 = F_62 ( & V_26 -> V_206 ) ) != NULL )
F_91 ( V_144 ) ;
while ( ( V_144 = F_62 ( & V_26 -> V_213 ) ) != NULL )
F_63 ( V_144 , NULL ) ;
clock = F_78 ( V_26 -> clock ) ;
if ( V_26 == clock -> V_61 ) {
F_92 ( clock -> V_66 ) ;
clock -> V_61 = NULL ;
} else {
F_35 (this, next, &clock->phylist) {
V_161 = F_36 ( V_151 , struct V_25 , V_153 ) ;
if ( V_161 == V_26 ) {
F_37 ( & V_161 -> V_153 ) ;
break;
}
}
}
F_81 ( clock ) ;
F_72 ( V_26 ) ;
}
static int F_93 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_56 * clock = V_26 -> clock ;
if ( clock -> V_61 && ! F_25 ( & clock -> V_128 ) )
F_40 ( clock ) ;
else
F_39 ( V_23 , clock -> V_24 , 1 ) ;
F_26 ( V_23 , true ) ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_165 ) ;
return 0 ;
}
static int F_94 ( struct V_22 * V_23 )
{
int V_99 = F_6 ( V_23 , V_247 ) ;
if ( V_99 < 0 )
return V_99 ;
return 0 ;
}
static int F_95 ( struct V_22 * V_23 )
{
int V_248 ;
int V_249 ;
int V_99 ;
if ( V_23 -> V_250 == V_251 ) {
V_249 = F_6 ( V_23 , V_247 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 |=
( V_252 |
V_253 |
V_254 |
V_255 ) ;
V_99 = F_8 ( V_23 , V_247 , V_249 ) ;
if ( V_99 < 0 )
return V_99 ;
V_248 = F_6 ( V_23 , V_256 ) ;
if ( V_248 < 0 )
return V_248 ;
V_248 |=
( V_257 |
V_258 ) ;
return F_8 ( V_23 , V_256 , V_248 ) ;
} else {
V_248 = F_6 ( V_23 , V_256 ) ;
if ( V_248 < 0 )
return V_248 ;
V_248 &=
~ ( V_257 |
V_258 ) ;
V_99 = F_8 ( V_23 , V_256 , V_248 ) ;
if ( V_99 < 0 )
return V_99 ;
V_249 = F_6 ( V_23 , V_247 ) ;
if ( V_249 < 0 )
return V_249 ;
V_249 &=
~ ( V_252 |
V_253 |
V_254 |
V_255 ) ;
return F_8 ( V_23 , V_247 , V_249 ) ;
}
}
static int F_96 ( struct V_22 * V_23 , struct V_259 * V_260 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_261 V_262 ;
T_2 V_263 , V_264 ;
if ( F_97 ( & V_262 , V_260 -> V_265 , sizeof( V_262 ) ) )
return - V_266 ;
if ( V_262 . V_117 )
return - V_67 ;
if ( V_262 . V_267 < 0 || V_262 . V_267 > V_268 )
return - V_269 ;
V_26 -> V_270 = V_262 . V_267 ;
switch ( V_262 . V_271 ) {
case V_272 :
V_26 -> V_273 = 0 ;
V_26 -> V_274 = 0 ;
V_26 -> V_275 = 0 ;
break;
case V_276 :
case V_277 :
case V_278 :
V_26 -> V_273 = 1 ;
V_26 -> V_274 = V_279 ;
V_26 -> V_275 = 1 ;
break;
case V_280 :
case V_281 :
case V_282 :
V_26 -> V_273 = 1 ;
V_26 -> V_274 = V_279 ;
V_26 -> V_275 = 2 ;
break;
case V_283 :
case V_284 :
case V_285 :
V_26 -> V_273 = 1 ;
V_26 -> V_274 = V_286 ;
V_26 -> V_275 = 2 ;
break;
case V_287 :
case V_288 :
case V_289 :
V_26 -> V_273 = 1 ;
V_26 -> V_274 = V_279 | V_286 ;
V_26 -> V_275 = 2 ;
break;
default:
return - V_269 ;
}
V_263 = ( V_26 -> V_275 & V_290 ) << V_291 ;
V_264 = ( V_26 -> V_275 & V_290 ) << V_291 ;
if ( V_26 -> V_274 & V_286 ) {
V_263 |= V_292 ;
V_264 |= V_293 ;
}
if ( V_26 -> V_274 & V_279 ) {
V_263 |= V_294 | V_295 ;
V_264 |= V_296 | V_297 ;
}
if ( V_26 -> V_270 )
V_263 |= V_298 ;
if ( V_26 -> V_270 == V_268 )
V_263 |= V_299 | V_300 ;
if ( V_26 -> V_273 )
V_264 |= V_301 ;
F_14 ( & V_26 -> clock -> V_78 ) ;
F_7 ( 0 , V_23 , V_79 , V_302 , V_263 ) ;
F_7 ( 0 , V_23 , V_79 , V_303 , V_264 ) ;
F_15 ( & V_26 -> clock -> V_78 ) ;
return F_98 ( V_260 -> V_265 , & V_262 , sizeof( V_262 ) ) ? - V_266 : 0 ;
}
static void V_243 ( struct V_304 * V_305 )
{
struct V_25 * V_26 =
F_17 ( V_305 , struct V_25 , V_242 ) ;
struct V_143 * V_144 ;
while ( ( V_144 = F_62 ( & V_26 -> V_206 ) ) ) {
struct V_208 * V_209 ;
V_209 = (struct V_208 * ) V_144 -> V_210 ;
if ( ! F_33 ( V_54 , V_209 -> V_53 ) ) {
F_99 ( & V_26 -> V_206 , V_144 ) ;
break;
}
F_58 ( V_144 ) ;
}
if ( ! F_100 ( & V_26 -> V_206 ) )
F_101 ( & V_26 -> V_242 ) ;
}
static bool F_102 ( struct V_22 * V_23 ,
struct V_143 * V_144 , int type )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_208 * V_209 = (struct V_208 * ) V_144 -> V_210 ;
struct V_150 * V_151 , * V_152 ;
struct V_42 * V_42 ;
struct V_202 * V_203 = NULL ;
unsigned long V_117 ;
if ( F_30 ( V_144 , type ) ) {
F_64 ( V_26 , V_144 ) ;
F_91 ( V_144 ) ;
return true ;
}
if ( ! V_26 -> V_273 )
return false ;
F_51 ( & V_26 -> V_204 , V_117 ) ;
F_35 (this, next, &dp83640->rxts) {
V_42 = F_36 ( V_151 , struct V_42 , V_153 ) ;
if ( F_45 ( V_144 , type , V_42 ) ) {
V_203 = F_56 ( V_144 ) ;
memset ( V_203 , 0 , sizeof( * V_203 ) ) ;
V_203 -> V_212 = F_57 ( V_42 -> V_46 ) ;
F_58 ( V_144 ) ;
F_37 ( & V_42 -> V_153 ) ;
F_38 ( & V_42 -> V_153 , & V_26 -> V_154 ) ;
break;
}
}
F_59 ( & V_26 -> V_204 , V_117 ) ;
if ( ! V_203 ) {
V_209 -> V_211 = type ;
V_209 -> V_53 = V_54 + 2 ;
F_103 ( & V_26 -> V_206 , V_144 ) ;
F_101 ( & V_26 -> V_242 ) ;
}
return true ;
}
static void F_104 ( struct V_22 * V_23 ,
struct V_143 * V_144 , int type )
{
struct V_25 * V_26 = V_23 -> V_27 ;
switch ( V_26 -> V_270 ) {
case V_268 :
if ( F_66 ( V_144 , type ) ) {
F_63 ( V_144 , NULL ) ;
return;
}
case V_306 :
F_105 ( V_144 ) -> V_307 |= V_308 ;
F_103 ( & V_26 -> V_213 , V_144 ) ;
break;
case V_309 :
default:
F_63 ( V_144 , NULL ) ;
break;
}
}
static int F_106 ( struct V_22 * V_31 , struct V_310 * V_311 )
{
struct V_25 * V_26 = V_31 -> V_27 ;
V_311 -> V_312 =
V_313 |
V_314 |
V_315 ;
V_311 -> V_316 = F_107 ( V_26 -> clock -> V_66 ) ;
V_311 -> V_317 =
( 1 << V_309 ) |
( 1 << V_306 ) |
( 1 << V_268 ) ;
V_311 -> V_318 =
( 1 << V_272 ) |
( 1 << V_276 ) |
( 1 << V_277 ) |
( 1 << V_278 ) |
( 1 << V_280 ) |
( 1 << V_281 ) |
( 1 << V_282 ) |
( 1 << V_283 ) |
( 1 << V_284 ) |
( 1 << V_285 ) |
( 1 << V_287 ) |
( 1 << V_288 ) |
( 1 << V_289 ) ;
return 0 ;
}
static int T_6 F_108 ( void )
{
return F_109 ( & V_319 ) ;
}
static void T_7 F_110 ( void )
{
F_67 () ;
F_111 ( & V_319 ) ;
}
