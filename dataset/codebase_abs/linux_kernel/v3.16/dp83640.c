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
struct V_57 * V_58 , bool V_59 )
{
struct V_25 * V_26 = clock -> V_60 ;
struct V_22 * V_23 = V_26 -> V_23 ;
T_1 V_43 , V_61 , V_62 ;
T_2 V_63 , V_64 , V_65 , V_20 ;
if ( V_59 ) {
V_63 = 1 + F_13 ( clock -> V_66 , V_14 , 0 ) ;
if ( V_63 < 1 )
return - V_67 ;
} else {
V_63 = 0 ;
}
V_65 = V_68 ;
V_64 = V_69 |
( V_65 & V_70 ) << V_71 |
( V_63 & V_72 ) << V_73 |
V_74 |
V_75 ;
V_20 = ( V_65 & V_76 ) << V_77 ;
if ( ! V_59 ) {
V_20 |= V_78 ;
F_14 ( & clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_80 , V_81 , V_64 ) ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_20 ) ;
F_15 ( & clock -> V_79 ) ;
return 0 ;
}
V_43 = V_58 -> V_82 . V_83 . V_43 ;
V_61 = V_58 -> V_82 . V_83 . V_61 ;
V_62 = V_58 -> V_82 . V_84 . V_43 * 1000000000UL ;
V_62 += V_58 -> V_82 . V_84 . V_61 ;
V_62 /= 2 ;
F_14 ( & clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_80 , V_81 , V_64 ) ;
V_20 |= V_85 ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_20 ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_61 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_61 >> 16 ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_43 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_43 >> 16 ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_62 & 0xffff ) ;
F_7 ( 0 , V_23 , V_35 , V_36 , V_62 >> 16 ) ;
V_20 &= ~ V_85 ;
V_20 |= V_86 ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_20 ) ;
F_15 ( & clock -> V_79 ) ;
return 0 ;
}
static int F_16 ( struct V_87 * V_88 , T_3 V_89 )
{
struct V_56 * clock =
F_17 ( V_88 , struct V_56 , V_90 ) ;
struct V_22 * V_23 = clock -> V_60 -> V_23 ;
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
struct V_56 * clock =
F_17 ( V_88 , struct V_56 , V_90 ) ;
struct V_22 * V_23 = clock -> V_60 -> V_23 ;
struct V_32 V_33 ;
int V_100 ;
V_99 += V_101 ;
V_33 = F_20 ( V_99 ) ;
F_14 ( & clock -> V_79 ) ;
V_100 = F_9 ( 1 , V_23 , & V_33 , V_102 ) ;
F_15 ( & clock -> V_79 ) ;
return V_100 ;
}
static int F_21 ( struct V_87 * V_88 , struct V_32 * V_33 )
{
struct V_56 * clock =
F_17 ( V_88 , struct V_56 , V_90 ) ;
struct V_22 * V_23 = clock -> V_60 -> V_23 ;
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
struct V_56 * clock =
F_17 ( V_88 , struct V_56 , V_90 ) ;
struct V_22 * V_23 = clock -> V_60 -> V_23 ;
int V_100 ;
F_14 ( & clock -> V_79 ) ;
V_100 = F_9 ( 1 , V_23 , V_33 , V_104 ) ;
F_15 ( & clock -> V_79 ) ;
return V_100 ;
}
static int F_23 ( struct V_87 * V_88 ,
struct V_57 * V_105 , int V_59 )
{
struct V_56 * clock =
F_17 ( V_88 , struct V_56 , V_90 ) ;
struct V_22 * V_23 = clock -> V_60 -> V_23 ;
unsigned int V_4 ;
T_2 V_106 , V_107 , V_108 ;
switch ( V_105 -> type ) {
case V_109 :
V_4 = V_105 -> V_110 . V_4 ;
if ( V_4 >= V_111 )
return - V_67 ;
V_107 = V_112 + V_4 ;
V_106 = V_113 | ( V_107 & V_114 ) << V_115 ;
if ( V_59 ) {
V_108 = 1 + F_13 ( clock -> V_66 ,
V_16 , V_4 ) ;
if ( V_108 < 1 )
return - V_67 ;
V_106 |= ( V_108 & V_116 ) << V_117 ;
if ( V_105 -> V_110 . V_118 & V_119 )
V_106 |= V_120 ;
else
V_106 |= V_121 ;
}
F_7 ( 0 , V_23 , V_80 , V_122 , V_106 ) ;
return 0 ;
case V_123 :
if ( V_105 -> V_82 . V_4 != 0 )
return - V_67 ;
return F_12 ( clock , V_105 , V_59 ) ;
default:
break;
}
return - V_124 ;
}
static int F_24 ( struct V_87 * V_88 , unsigned int V_125 ,
enum V_126 V_10 , unsigned int V_12 )
{
return 0 ;
}
static void F_25 ( struct V_22 * V_23 , bool V_59 )
{
T_2 V_127 = 0 , V_128 ;
if ( V_59 )
V_127 = V_129 | V_130 | V_131 | V_132 ;
V_128 = ( V_133 & V_134 ) << V_135 ;
F_7 ( 0 , V_23 , V_80 , V_136 , V_127 ) ;
F_7 ( 0 , V_23 , V_137 , V_138 , V_128 ) ;
if ( ! V_23 -> V_139 ) {
F_26 ( L_3 ) ;
return;
}
if ( V_59 ) {
if ( F_27 ( V_23 -> V_139 , V_140 ) )
F_26 ( L_4 ) ;
} else {
if ( F_28 ( V_23 -> V_139 , V_140 ) )
F_26 ( L_5 ) ;
}
}
static bool F_29 ( struct V_141 * V_142 , int type )
{
struct V_143 * V_144 = F_30 ( V_142 ) ;
if ( V_145 == type &&
! memcmp ( V_144 -> V_146 , V_147 , sizeof( V_147 ) ) )
return true ;
else
return false ;
}
static int F_31 ( struct V_42 * V_42 )
{
return F_32 ( V_54 , V_42 -> V_53 ) ;
}
static void F_33 ( struct V_25 * V_26 )
{
struct V_148 * V_149 , * V_150 ;
struct V_42 * V_42 ;
F_34 (this, next, &dp83640->rxts) {
V_42 = F_35 ( V_149 , struct V_42 , V_151 ) ;
if ( F_31 ( V_42 ) ) {
F_36 ( & V_42 -> V_151 ) ;
F_37 ( & V_42 -> V_151 , & V_26 -> V_152 ) ;
}
}
}
static void F_38 ( struct V_22 * V_23 , int V_153 , int V_59 )
{
int V_20 ;
F_8 ( V_23 , V_28 , 0 ) ;
V_20 = F_6 ( V_23 , V_154 ) ;
if ( V_59 )
V_20 |= V_155 ;
else
V_20 &= ~ V_155 ;
F_8 ( V_23 , V_154 , V_20 ) ;
F_8 ( V_23 , V_28 , V_153 ) ;
}
static void F_39 ( struct V_56 * clock )
{
T_4 V_156 , V_157 ;
struct V_55 V_158 ;
struct V_32 V_33 ;
struct V_148 * V_149 ;
struct V_25 * V_159 ;
struct V_22 * V_160 = clock -> V_60 -> V_23 ;
T_2 V_161 , V_127 , V_106 , V_64 , V_65 , V_20 ;
V_65 = V_162 ;
V_161 = V_8 [ V_9 ] ;
F_14 ( & clock -> V_79 ) ;
F_40 (this, &clock->phylist) {
V_159 = F_35 ( V_149 , struct V_25 , V_151 ) ;
F_38 ( V_159 -> V_23 , clock -> V_24 , 1 ) ;
V_159 -> V_127 = F_5 ( V_159 -> V_23 , V_80 , V_136 ) ;
F_7 ( 0 , V_159 -> V_23 , V_80 , V_136 , 0 ) ;
F_7 ( 0 , V_159 -> V_23 , V_35 , V_39 , V_163 ) ;
}
F_38 ( V_160 , clock -> V_24 , 1 ) ;
V_127 = F_5 ( V_160 , V_80 , V_136 ) ;
F_7 ( 0 , V_160 , V_80 , V_136 , 0 ) ;
F_7 ( 0 , V_160 , V_35 , V_39 , V_163 ) ;
V_106 = V_113 | V_121 | V_164 ;
V_106 |= ( V_165 & V_114 ) << V_115 ;
V_106 |= ( V_161 & V_116 ) << V_117 ;
F_40 (this, &clock->phylist) {
V_159 = F_35 ( V_149 , struct V_25 , V_151 ) ;
F_7 ( 0 , V_159 -> V_23 , V_80 , V_122 , V_106 ) ;
}
F_7 ( 0 , V_160 , V_80 , V_122 , V_106 ) ;
V_64 = V_69 | V_166 | V_75 ;
V_64 |= ( V_65 & V_70 ) << V_71 ;
V_64 |= ( V_161 & V_72 ) << V_73 ;
F_7 ( 0 , V_160 , V_80 , V_81 , V_64 ) ;
V_20 = ( V_65 & V_76 ) << V_77 ;
V_20 |= V_85 ;
F_7 ( 0 , V_160 , V_35 , V_39 , V_20 ) ;
V_20 &= ~ V_85 ;
V_20 |= V_86 ;
F_7 ( 0 , V_160 , V_35 , V_39 , V_20 ) ;
V_20 = ( V_65 & V_76 ) << V_77 ;
V_20 |= V_78 ;
F_7 ( 0 , V_160 , V_35 , V_39 , V_20 ) ;
V_20 = F_5 ( V_160 , V_35 , V_167 ) ;
F_41 ( L_6 , V_20 ) ;
V_20 = F_5 ( V_160 , V_35 , V_168 ) ;
F_41 ( L_7 , V_20 ) ;
V_158 . V_47 = F_5 ( V_160 , V_35 , V_169 ) ;
V_158 . V_48 = F_5 ( V_160 , V_35 , V_169 ) ;
V_158 . V_44 = F_5 ( V_160 , V_35 , V_169 ) ;
V_158 . V_45 = F_5 ( V_160 , V_35 , V_169 ) ;
V_156 = F_11 ( & V_158 ) ;
F_40 (this, &clock->phylist) {
V_159 = F_35 ( V_149 , struct V_25 , V_151 ) ;
V_20 = F_5 ( V_159 -> V_23 , V_35 , V_167 ) ;
F_41 ( L_8 , V_20 ) ;
V_20 = F_5 ( V_159 -> V_23 , V_35 , V_168 ) ;
F_41 ( L_9 , V_20 ) ;
V_158 . V_47 = F_5 ( V_159 -> V_23 , V_35 , V_169 ) ;
V_158 . V_48 = F_5 ( V_159 -> V_23 , V_35 , V_169 ) ;
V_158 . V_44 = F_5 ( V_159 -> V_23 , V_35 , V_169 ) ;
V_158 . V_45 = F_5 ( V_159 -> V_23 , V_35 , V_169 ) ;
V_157 = V_156 - ( T_4 ) F_11 ( & V_158 ) ;
F_41 ( L_10 , V_157 ) ;
V_157 += V_101 ;
V_33 = F_20 ( V_157 ) ;
F_9 ( 0 , V_159 -> V_23 , & V_33 , V_102 ) ;
}
F_40 (this, &clock->phylist) {
V_159 = F_35 ( V_149 , struct V_25 , V_151 ) ;
F_7 ( 0 , V_159 -> V_23 , V_80 , V_136 , V_159 -> V_127 ) ;
}
F_7 ( 0 , V_160 , V_80 , V_136 , V_127 ) ;
F_15 ( & clock -> V_79 ) ;
}
static inline T_2 F_42 ( int V_170 )
{
return 1 << ( ( V_170 + V_112 ) * 2 ) ;
}
static int F_43 ( struct V_25 * V_26 ,
void * V_171 , T_2 V_172 )
{
struct V_55 * V_55 ;
struct V_173 V_174 ;
int V_3 , V_175 ;
int V_176 = ( V_172 >> V_177 ) & V_178 ;
T_2 V_179 = 0 ;
if ( V_172 & V_180 ) {
V_179 = * ( T_2 * ) V_171 ;
V_171 += sizeof( V_179 ) ;
}
V_55 = V_171 ;
switch ( V_176 ) {
case 3 :
V_26 -> V_181 . V_45 = V_55 -> V_45 ;
case 2 :
V_26 -> V_181 . V_44 = V_55 -> V_44 ;
case 1 :
V_26 -> V_181 . V_48 = V_55 -> V_48 ;
case 0 :
V_26 -> V_181 . V_47 = V_55 -> V_47 ;
}
if ( V_179 ) {
V_175 = V_176 + 2 ;
} else {
V_175 = V_176 + 1 ;
V_3 = ( ( V_172 >> V_182 ) & V_183 ) - V_112 ;
V_179 = F_42 ( V_3 ) ;
}
V_174 . type = V_184 ;
V_174 . V_185 = F_11 ( & V_26 -> V_181 ) ;
for ( V_3 = 0 ; V_3 < V_111 ; V_3 ++ ) {
if ( V_179 & F_42 ( V_3 ) ) {
V_174 . V_4 = V_3 ;
V_173 ( V_26 -> clock -> V_66 , & V_174 ) ;
}
}
return V_175 * sizeof( T_2 ) ;
}
static void F_44 ( struct V_25 * V_26 ,
struct V_40 * V_40 )
{
struct V_42 * V_42 ;
unsigned long V_118 ;
F_45 ( & V_26 -> V_186 , V_118 ) ;
F_33 ( V_26 ) ;
if ( F_46 ( & V_26 -> V_152 ) ) {
F_47 ( L_11 ) ;
goto V_187;
}
V_42 = F_48 ( & V_26 -> V_152 , struct V_42 , V_151 ) ;
F_36 ( & V_42 -> V_151 ) ;
F_10 ( V_40 , V_42 ) ;
F_49 ( & V_42 -> V_151 , & V_26 -> V_42 ) ;
V_187:
F_50 ( & V_26 -> V_186 , V_118 ) ;
}
static void F_51 ( struct V_25 * V_26 ,
struct V_55 * V_55 )
{
struct V_188 V_189 ;
struct V_141 * V_142 ;
V_49 V_46 ;
V_142 = F_52 ( & V_26 -> V_190 ) ;
if ( ! V_142 ) {
F_47 ( L_12 ) ;
return;
}
V_46 = F_11 ( V_55 ) ;
memset ( & V_189 , 0 , sizeof( V_189 ) ) ;
V_189 . V_191 = F_53 ( V_46 ) ;
F_54 ( V_142 , & V_189 ) ;
}
static void F_55 ( struct V_25 * V_26 ,
struct V_141 * V_142 )
{
struct V_40 * V_40 ;
struct V_55 * V_55 ;
T_5 * V_192 ;
int V_193 , V_194 ;
T_2 V_172 , type ;
V_192 = V_142 -> V_171 + 2 ;
for ( V_193 = F_56 ( V_142 ) - 2 ; V_193 > sizeof( type ) ; V_193 -= V_194 ) {
type = * ( T_2 * ) V_192 ;
V_172 = type & 0x0fff ;
type = type & 0xf000 ;
V_193 -= sizeof( type ) ;
V_192 += sizeof( type ) ;
if ( V_195 == type && V_193 >= sizeof( * V_40 ) ) {
V_40 = (struct V_40 * ) V_192 ;
F_44 ( V_26 , V_40 ) ;
V_194 = sizeof( * V_40 ) ;
} else if ( V_196 == type && V_193 >= sizeof( * V_55 ) ) {
V_55 = (struct V_55 * ) V_192 ;
F_51 ( V_26 , V_55 ) ;
V_194 = sizeof( * V_55 ) ;
} else if ( V_197 == type && V_193 >= sizeof( * V_55 ) ) {
V_194 = F_43 ( V_26 , V_192 , V_172 ) ;
} else {
V_194 = 0 ;
break;
}
V_192 += V_194 ;
}
}
static int F_57 ( struct V_141 * V_142 , int type )
{
T_5 * V_171 = V_142 -> V_171 , * V_51 ;
unsigned int V_198 = 0 ;
switch ( type ) {
case V_199 :
case V_200 :
V_198 = V_201 + F_58 ( V_171 ) + V_202 ;
break;
case V_203 :
case V_204 :
V_198 = V_205 ;
break;
case V_145 :
V_198 = V_201 ;
break;
case V_206 :
V_198 = V_201 + V_207 ;
break;
default:
return 0 ;
}
if ( type & V_208 )
V_198 += V_209 ;
if ( V_142 -> V_193 < V_198 + 1 )
return 0 ;
V_51 = V_171 + V_198 ;
return ( * V_51 & 0xf ) == 0 ;
}
static int F_59 ( struct V_141 * V_142 , unsigned int type , struct V_42 * V_42 )
{
T_2 * V_50 ;
unsigned int V_198 ;
T_5 * V_51 , * V_171 = F_60 ( V_142 ) ;
switch ( type ) {
case V_199 :
case V_200 :
V_198 = V_201 + F_58 ( V_171 ) + V_202 ;
break;
case V_203 :
case V_204 :
V_198 = V_205 ;
break;
case V_145 :
V_198 = V_201 ;
break;
case V_206 :
V_198 = V_201 + V_207 ;
break;
default:
return 0 ;
}
if ( V_142 -> V_193 + V_201 < V_198 + V_210 + sizeof( * V_50 ) )
return 0 ;
if ( F_61 ( type & V_208 ) )
V_51 = V_171 + V_198 + V_209 ;
else
V_51 = V_171 + V_198 ;
V_50 = ( T_2 * ) ( V_171 + V_198 + V_210 ) ;
return V_42 -> V_51 == ( * V_51 & 0xf ) &&
V_42 -> V_50 == F_62 ( * V_50 ) ;
}
static void F_63 ( void )
{
struct V_56 * clock ;
struct V_148 * V_149 , * V_150 ;
F_14 ( & V_211 ) ;
F_34 (this, next, &phyter_clocks) {
clock = F_35 ( V_149 , struct V_56 , V_151 ) ;
if ( ! F_46 ( & clock -> V_212 ) ) {
F_26 ( L_13 ) ;
F_64 () ;
}
F_65 ( & clock -> V_151 ) ;
F_66 ( & clock -> V_79 ) ;
F_66 ( & clock -> V_213 ) ;
F_67 ( & clock -> V_18 -> V_31 ) ;
F_68 ( clock -> V_90 . V_214 ) ;
F_68 ( clock ) ;
}
F_15 ( & V_211 ) ;
}
static void F_69 ( struct V_56 * clock , struct V_17 * V_18 )
{
F_70 ( & clock -> V_151 ) ;
clock -> V_18 = V_18 ;
F_71 ( & clock -> V_79 ) ;
F_71 ( & clock -> V_213 ) ;
F_70 ( & clock -> V_212 ) ;
clock -> V_90 . V_215 = V_216 ;
sprintf ( clock -> V_90 . V_6 , L_14 ) ;
clock -> V_90 . V_217 = 1953124 ;
clock -> V_90 . V_218 = 0 ;
clock -> V_90 . V_219 = V_111 ;
clock -> V_90 . V_220 = 1 ;
clock -> V_90 . V_221 = V_5 ;
clock -> V_90 . V_222 = 0 ;
clock -> V_90 . V_223 = F_16 ;
clock -> V_90 . V_224 = F_19 ;
clock -> V_90 . V_225 = F_21 ;
clock -> V_90 . V_226 = F_22 ;
clock -> V_90 . V_227 = F_23 ;
clock -> V_90 . V_228 = F_24 ;
F_1 ( clock -> V_90 . V_214 ) ;
F_72 ( & V_18 -> V_31 ) ;
}
static int F_73 ( struct V_56 * clock ,
struct V_22 * V_23 )
{
if ( V_229 == - 1 && ! clock -> V_60 )
return 1 ;
if ( V_229 == V_23 -> V_230 )
return 1 ;
return 0 ;
}
static struct V_56 * F_74 ( struct V_56 * clock )
{
if ( clock )
F_14 ( & clock -> V_213 ) ;
return clock ;
}
static struct V_56 * F_75 ( struct V_17 * V_18 )
{
struct V_56 * clock = NULL , * V_159 ;
struct V_148 * V_149 ;
F_14 ( & V_211 ) ;
F_40 (this, &phyter_clocks) {
V_159 = F_35 ( V_149 , struct V_56 , V_151 ) ;
if ( V_159 -> V_18 == V_18 ) {
clock = V_159 ;
break;
}
}
if ( clock )
goto V_187;
clock = F_76 ( sizeof( struct V_56 ) , V_231 ) ;
if ( ! clock )
goto V_187;
clock -> V_90 . V_214 = F_76 ( sizeof( struct V_1 ) *
V_5 , V_231 ) ;
if ( ! clock -> V_90 . V_214 ) {
F_68 ( clock ) ;
clock = NULL ;
goto V_187;
}
F_69 ( clock , V_18 ) ;
F_49 ( & V_232 , & clock -> V_151 ) ;
V_187:
F_15 ( & V_211 ) ;
return F_74 ( clock ) ;
}
static void F_77 ( struct V_56 * clock )
{
F_15 ( & clock -> V_213 ) ;
}
static int F_78 ( struct V_22 * V_23 )
{
struct V_56 * clock ;
struct V_25 * V_26 ;
int V_100 = - V_233 , V_3 ;
if ( V_23 -> V_230 == V_21 )
return 0 ;
clock = F_75 ( V_23 -> V_18 ) ;
if ( ! clock )
goto V_234;
V_26 = F_76 ( sizeof( struct V_25 ) , V_231 ) ;
if ( ! V_26 )
goto V_235;
V_26 -> V_23 = V_23 ;
F_79 ( & V_26 -> V_236 , V_237 ) ;
F_70 ( & V_26 -> V_42 ) ;
F_70 ( & V_26 -> V_152 ) ;
for ( V_3 = 0 ; V_3 < V_238 ; V_3 ++ )
F_37 ( & V_26 -> V_239 [ V_3 ] . V_151 , & V_26 -> V_152 ) ;
V_23 -> V_27 = V_26 ;
F_80 ( & V_26 -> V_186 ) ;
F_81 ( & V_26 -> V_240 ) ;
F_81 ( & V_26 -> V_190 ) ;
V_26 -> clock = clock ;
if ( F_73 ( clock , V_23 ) ) {
clock -> V_60 = V_26 ;
clock -> V_66 = F_82 ( & clock -> V_90 , & V_23 -> V_31 ) ;
if ( F_83 ( clock -> V_66 ) ) {
V_100 = F_84 ( clock -> V_66 ) ;
goto V_241;
}
} else
F_49 ( & V_26 -> V_151 , & clock -> V_212 ) ;
F_77 ( clock ) ;
return 0 ;
V_241:
clock -> V_60 = NULL ;
F_68 ( V_26 ) ;
V_235:
F_77 ( clock ) ;
V_234:
return V_100 ;
}
static void F_85 ( struct V_22 * V_23 )
{
struct V_56 * clock ;
struct V_148 * V_149 , * V_150 ;
struct V_25 * V_159 , * V_26 = V_23 -> V_27 ;
struct V_141 * V_142 ;
if ( V_23 -> V_230 == V_21 )
return;
F_25 ( V_23 , false ) ;
F_86 ( & V_26 -> V_236 ) ;
while ( ( V_142 = F_52 ( & V_26 -> V_240 ) ) != NULL )
F_87 ( V_142 ) ;
while ( ( V_142 = F_52 ( & V_26 -> V_190 ) ) != NULL )
F_54 ( V_142 , NULL ) ;
clock = F_74 ( V_26 -> clock ) ;
if ( V_26 == clock -> V_60 ) {
F_88 ( clock -> V_66 ) ;
clock -> V_60 = NULL ;
} else {
F_34 (this, next, &clock->phylist) {
V_159 = F_35 ( V_149 , struct V_25 , V_151 ) ;
if ( V_159 == V_26 ) {
F_36 ( & V_159 -> V_151 ) ;
break;
}
}
}
F_77 ( clock ) ;
F_68 ( V_26 ) ;
}
static int F_89 ( struct V_22 * V_23 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_56 * clock = V_26 -> clock ;
if ( clock -> V_60 && ! F_46 ( & clock -> V_212 ) )
F_39 ( clock ) ;
else
F_38 ( V_23 , clock -> V_24 , 1 ) ;
F_25 ( V_23 , true ) ;
F_7 ( 0 , V_23 , V_35 , V_39 , V_163 ) ;
return 0 ;
}
static int F_90 ( struct V_22 * V_23 )
{
int V_100 = F_6 ( V_23 , V_242 ) ;
if ( V_100 < 0 )
return V_100 ;
return 0 ;
}
static int F_91 ( struct V_22 * V_23 )
{
int V_243 ;
int V_244 ;
int V_100 ;
if ( V_23 -> V_245 == V_246 ) {
V_244 = F_6 ( V_23 , V_242 ) ;
if ( V_244 < 0 )
return V_244 ;
V_244 |=
( V_247 |
V_248 |
V_249 |
V_250 ) ;
V_100 = F_8 ( V_23 , V_242 , V_244 ) ;
if ( V_100 < 0 )
return V_100 ;
V_243 = F_6 ( V_23 , V_251 ) ;
if ( V_243 < 0 )
return V_243 ;
V_243 |=
( V_252 |
V_253 ) ;
return F_8 ( V_23 , V_251 , V_243 ) ;
} else {
V_243 = F_6 ( V_23 , V_251 ) ;
if ( V_243 < 0 )
return V_243 ;
V_243 &=
~ ( V_252 |
V_253 ) ;
V_100 = F_8 ( V_23 , V_251 , V_243 ) ;
if ( V_100 < 0 )
return V_100 ;
V_244 = F_6 ( V_23 , V_242 ) ;
if ( V_244 < 0 )
return V_244 ;
V_244 &=
~ ( V_247 |
V_248 |
V_249 |
V_250 ) ;
return F_8 ( V_23 , V_242 , V_244 ) ;
}
}
static int F_92 ( struct V_22 * V_23 , struct V_254 * V_255 )
{
struct V_25 * V_26 = V_23 -> V_27 ;
struct V_256 V_257 ;
T_2 V_258 , V_259 ;
if ( F_93 ( & V_257 , V_255 -> V_260 , sizeof( V_257 ) ) )
return - V_261 ;
if ( V_257 . V_118 )
return - V_67 ;
if ( V_257 . V_262 < 0 || V_257 . V_262 > V_263 )
return - V_264 ;
V_26 -> V_265 = V_257 . V_262 ;
switch ( V_257 . V_266 ) {
case V_267 :
V_26 -> V_268 = 0 ;
V_26 -> V_269 = 0 ;
V_26 -> V_270 = 0 ;
break;
case V_271 :
case V_272 :
case V_273 :
V_26 -> V_268 = 1 ;
V_26 -> V_269 = V_274 ;
V_26 -> V_270 = 1 ;
break;
case V_275 :
case V_276 :
case V_277 :
V_26 -> V_268 = 1 ;
V_26 -> V_269 = V_274 ;
V_26 -> V_270 = 2 ;
break;
case V_278 :
case V_279 :
case V_280 :
V_26 -> V_268 = 1 ;
V_26 -> V_269 = V_281 ;
V_26 -> V_270 = 2 ;
break;
case V_282 :
case V_283 :
case V_284 :
V_26 -> V_268 = 1 ;
V_26 -> V_269 = V_274 | V_281 ;
V_26 -> V_270 = 2 ;
break;
default:
return - V_264 ;
}
V_258 = ( V_26 -> V_270 & V_285 ) << V_286 ;
V_259 = ( V_26 -> V_270 & V_285 ) << V_286 ;
if ( V_26 -> V_269 & V_281 ) {
V_258 |= V_287 ;
V_259 |= V_288 ;
}
if ( V_26 -> V_269 & V_274 ) {
V_258 |= V_289 | V_290 ;
V_259 |= V_291 | V_292 ;
}
if ( V_26 -> V_265 )
V_258 |= V_293 ;
if ( V_26 -> V_265 == V_263 )
V_258 |= V_294 | V_295 ;
if ( V_26 -> V_268 )
V_259 |= V_296 ;
F_14 ( & V_26 -> clock -> V_79 ) ;
F_7 ( 0 , V_23 , V_80 , V_297 , V_258 ) ;
F_7 ( 0 , V_23 , V_80 , V_298 , V_259 ) ;
F_15 ( & V_26 -> clock -> V_79 ) ;
return F_94 ( V_255 -> V_260 , & V_257 , sizeof( V_257 ) ) ? - V_261 : 0 ;
}
static void V_237 ( struct V_299 * V_300 )
{
struct V_25 * V_26 =
F_17 ( V_300 , struct V_25 , V_236 ) ;
struct V_148 * V_149 , * V_150 ;
struct V_42 * V_42 ;
struct V_188 * V_189 ;
struct V_141 * V_142 ;
unsigned int type ;
unsigned long V_118 ;
while ( ( V_142 = F_52 ( & V_26 -> V_240 ) ) != NULL ) {
type = F_95 ( V_142 ) ;
F_45 ( & V_26 -> V_186 , V_118 ) ;
F_34 (this, next, &dp83640->rxts) {
V_42 = F_35 ( V_149 , struct V_42 , V_151 ) ;
if ( F_59 ( V_142 , type , V_42 ) ) {
V_189 = F_96 ( V_142 ) ;
memset ( V_189 , 0 , sizeof( * V_189 ) ) ;
V_189 -> V_191 = F_53 ( V_42 -> V_46 ) ;
F_36 ( & V_42 -> V_151 ) ;
F_37 ( & V_42 -> V_151 , & V_26 -> V_152 ) ;
break;
}
}
F_50 ( & V_26 -> V_186 , V_118 ) ;
F_97 ( V_142 ) ;
}
F_45 ( & V_26 -> V_186 , V_118 ) ;
F_33 ( V_26 ) ;
F_50 ( & V_26 -> V_186 , V_118 ) ;
}
static bool F_98 ( struct V_22 * V_23 ,
struct V_141 * V_142 , int type )
{
struct V_25 * V_26 = V_23 -> V_27 ;
if ( F_29 ( V_142 , type ) ) {
F_55 ( V_26 , V_142 ) ;
F_87 ( V_142 ) ;
return true ;
}
if ( ! V_26 -> V_268 )
return false ;
F_95 ( V_142 ) = type ;
F_99 ( & V_26 -> V_240 , V_142 ) ;
F_100 ( & V_26 -> V_236 ) ;
return true ;
}
static void F_101 ( struct V_22 * V_23 ,
struct V_141 * V_142 , int type )
{
struct V_25 * V_26 = V_23 -> V_27 ;
switch ( V_26 -> V_265 ) {
case V_263 :
if ( F_57 ( V_142 , type ) ) {
F_54 ( V_142 , NULL ) ;
return;
}
case V_301 :
F_102 ( V_142 ) -> V_302 |= V_303 ;
F_99 ( & V_26 -> V_190 , V_142 ) ;
F_100 ( & V_26 -> V_236 ) ;
break;
case V_304 :
default:
F_54 ( V_142 , NULL ) ;
break;
}
}
static int F_103 ( struct V_22 * V_31 , struct V_305 * V_306 )
{
struct V_25 * V_26 = V_31 -> V_27 ;
V_306 -> V_307 =
V_308 |
V_309 |
V_310 ;
V_306 -> V_311 = F_104 ( V_26 -> clock -> V_66 ) ;
V_306 -> V_312 =
( 1 << V_304 ) |
( 1 << V_301 ) |
( 1 << V_263 ) ;
V_306 -> V_313 =
( 1 << V_267 ) |
( 1 << V_271 ) |
( 1 << V_272 ) |
( 1 << V_273 ) |
( 1 << V_275 ) |
( 1 << V_276 ) |
( 1 << V_277 ) |
( 1 << V_278 ) |
( 1 << V_279 ) |
( 1 << V_280 ) |
( 1 << V_282 ) |
( 1 << V_283 ) |
( 1 << V_284 ) ;
return 0 ;
}
static int T_6 F_105 ( void )
{
return F_106 ( & V_314 ) ;
}
static void T_7 F_107 ( void )
{
F_63 () ;
F_108 ( & V_314 ) ;
}
