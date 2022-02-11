static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
return F_2 ( V_2 , V_5 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_6 * V_7 , int V_8 , T_1 V_3 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
int V_4 ;
if ( V_10 -> clock -> V_8 != V_8 ) {
F_1 ( V_7 -> V_2 , V_12 , V_8 ) ;
V_10 -> clock -> V_8 = V_8 ;
}
V_4 = F_4 ( V_7 , V_3 ) ;
return V_4 ;
}
static void F_5 ( int V_13 , struct V_6 * V_7 ,
int V_8 , T_1 V_3 , T_2 V_4 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( V_10 -> clock -> V_8 != V_8 ) {
F_1 ( V_7 -> V_2 , V_12 , V_8 ) ;
V_10 -> clock -> V_8 = V_8 ;
}
if ( V_13 )
F_1 ( V_7 -> V_2 , V_3 , V_4 ) ;
else
F_6 ( V_7 , V_3 , V_4 ) ;
}
static int F_7 ( int V_14 , struct V_6 * V_15 ,
const struct V_16 * V_17 , T_2 V_18 )
{
F_5 ( V_14 , V_15 , V_19 , V_20 , V_17 -> V_21 & 0xffff ) ;
F_5 ( V_14 , V_15 , V_19 , V_20 , V_17 -> V_21 >> 16 ) ;
F_5 ( V_14 , V_15 , V_19 , V_20 , V_17 -> V_22 & 0xffff ) ;
F_5 ( V_14 , V_15 , V_19 , V_20 , V_17 -> V_22 >> 16 ) ;
F_5 ( V_14 , V_15 , V_19 , V_23 , V_18 ) ;
return 0 ;
}
static void F_8 ( struct V_24 * V_25 , struct V_26 * V_26 )
{
T_1 V_27 ;
V_27 = V_25 -> V_28 ;
V_27 |= V_25 -> V_29 << 16 ;
V_26 -> V_30 = V_25 -> V_31 ;
V_26 -> V_30 |= ( V_25 -> V_32 & 0x3fff ) << 16 ;
V_26 -> V_30 += ( ( V_33 ) V_27 ) * 1000000000ULL ;
V_26 -> V_34 = V_25 -> V_34 ;
V_26 -> V_35 = ( V_25 -> V_35 >> 12 ) & 0xf ;
V_26 -> V_36 = V_25 -> V_35 & 0x0fff ;
V_26 -> V_37 = V_38 + 2 ;
}
static V_33 F_9 ( struct V_39 * V_25 )
{
V_33 V_30 ;
T_1 V_27 ;
V_27 = V_25 -> V_28 ;
V_27 |= V_25 -> V_29 << 16 ;
V_30 = V_25 -> V_31 ;
V_30 |= ( V_25 -> V_32 & 0x3fff ) << 16 ;
V_30 += ( ( V_33 ) V_27 ) * 1000000000ULL ;
return V_30 ;
}
static void F_10 ( struct V_40 * clock ,
struct V_41 * V_42 , bool V_43 )
{
struct V_9 * V_10 = clock -> V_44 ;
struct V_6 * V_7 = V_10 -> V_7 ;
T_1 V_27 , V_45 , V_46 ;
T_2 V_47 , V_48 , V_49 , V_4 ;
V_47 = V_43 ? V_50 [ V_51 ] : 0 ;
V_49 = V_52 ;
V_48 = V_53 |
( V_49 & V_54 ) << V_55 |
( V_47 & V_56 ) << V_57 |
V_58 |
V_59 ;
V_4 = ( V_49 & V_60 ) << V_61 ;
if ( ! V_43 ) {
V_4 |= V_62 ;
F_11 ( & clock -> V_63 ) ;
F_5 ( 0 , V_7 , V_64 , V_65 , V_48 ) ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_4 ) ;
F_12 ( & clock -> V_63 ) ;
return;
}
V_27 = V_42 -> V_66 . V_67 . V_27 ;
V_45 = V_42 -> V_66 . V_67 . V_45 ;
V_46 = V_42 -> V_66 . V_46 . V_27 * 1000000000UL ;
V_46 += V_42 -> V_66 . V_46 . V_45 ;
F_11 ( & clock -> V_63 ) ;
F_5 ( 0 , V_7 , V_64 , V_65 , V_48 ) ;
V_4 |= V_68 ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_4 ) ;
F_5 ( 0 , V_7 , V_19 , V_20 , V_45 & 0xffff ) ;
F_5 ( 0 , V_7 , V_19 , V_20 , V_45 >> 16 ) ;
F_5 ( 0 , V_7 , V_19 , V_20 , V_27 & 0xffff ) ;
F_5 ( 0 , V_7 , V_19 , V_20 , V_27 >> 16 ) ;
F_5 ( 0 , V_7 , V_19 , V_20 , V_46 & 0xffff ) ;
F_5 ( 0 , V_7 , V_19 , V_20 , V_46 >> 16 ) ;
V_4 &= ~ V_68 ;
V_4 |= V_69 ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_4 ) ;
F_12 ( & clock -> V_63 ) ;
}
static int F_13 ( struct V_70 * V_71 , T_3 V_72 )
{
struct V_40 * clock =
F_14 ( V_71 , struct V_40 , V_73 ) ;
struct V_6 * V_7 = clock -> V_44 -> V_7 ;
V_33 V_74 ;
int V_75 = 0 ;
T_2 V_76 , V_77 ;
if ( V_72 < 0 ) {
V_75 = 1 ;
V_72 = - V_72 ;
}
V_74 = V_72 ;
V_74 <<= 26 ;
V_74 = F_15 ( V_74 , 1953125 ) ;
V_76 = ( V_74 >> 16 ) & V_78 ;
if ( V_75 )
V_76 |= V_79 ;
V_77 = V_74 & 0xffff ;
F_11 ( & clock -> V_63 ) ;
F_5 ( 1 , V_7 , V_19 , V_80 , V_76 ) ;
F_5 ( 1 , V_7 , V_19 , V_81 , V_77 ) ;
F_12 ( & clock -> V_63 ) ;
return 0 ;
}
static int F_16 ( struct V_70 * V_71 , T_4 V_82 )
{
struct V_40 * clock =
F_14 ( V_71 , struct V_40 , V_73 ) ;
struct V_6 * V_7 = clock -> V_44 -> V_7 ;
struct V_16 V_17 ;
int V_83 ;
V_82 += V_84 ;
V_17 = F_17 ( V_82 ) ;
F_11 ( & clock -> V_63 ) ;
V_83 = F_7 ( 1 , V_7 , & V_17 , V_85 ) ;
F_12 ( & clock -> V_63 ) ;
return V_83 ;
}
static int F_18 ( struct V_70 * V_71 , struct V_16 * V_17 )
{
struct V_40 * clock =
F_14 ( V_71 , struct V_40 , V_73 ) ;
struct V_6 * V_7 = clock -> V_44 -> V_7 ;
unsigned int V_4 [ 4 ] ;
F_11 ( & clock -> V_63 ) ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_86 ) ;
V_4 [ 0 ] = F_3 ( V_7 , V_19 , V_20 ) ;
V_4 [ 1 ] = F_3 ( V_7 , V_19 , V_20 ) ;
V_4 [ 2 ] = F_3 ( V_7 , V_19 , V_20 ) ;
V_4 [ 3 ] = F_3 ( V_7 , V_19 , V_20 ) ;
F_12 ( & clock -> V_63 ) ;
V_17 -> V_21 = V_4 [ 0 ] | ( V_4 [ 1 ] << 16 ) ;
V_17 -> V_22 = V_4 [ 2 ] | ( V_4 [ 3 ] << 16 ) ;
return 0 ;
}
static int F_19 ( struct V_70 * V_71 ,
const struct V_16 * V_17 )
{
struct V_40 * clock =
F_14 ( V_71 , struct V_40 , V_73 ) ;
struct V_6 * V_7 = clock -> V_44 -> V_7 ;
int V_83 ;
F_11 ( & clock -> V_63 ) ;
V_83 = F_7 ( 1 , V_7 , V_17 , V_87 ) ;
F_12 ( & clock -> V_63 ) ;
return V_83 ;
}
static int F_20 ( struct V_70 * V_71 ,
struct V_41 * V_88 , int V_43 )
{
struct V_40 * clock =
F_14 ( V_71 , struct V_40 , V_73 ) ;
struct V_6 * V_7 = clock -> V_44 -> V_7 ;
int V_89 ;
T_2 V_90 , V_91 , V_92 ;
switch ( V_88 -> type ) {
case V_93 :
V_89 = V_88 -> V_94 . V_89 ;
if ( V_89 < 0 || V_89 >= V_95 )
return - V_96 ;
V_91 = V_97 + V_89 ;
V_90 = V_98 | ( V_91 & V_99 ) << V_100 ;
if ( V_43 ) {
V_92 = V_50 [ V_101 + V_89 ] ;
V_90 |= ( V_92 & V_102 ) << V_103 ;
if ( V_88 -> V_94 . V_104 & V_105 )
V_90 |= V_106 ;
else
V_90 |= V_107 ;
}
F_5 ( 0 , V_7 , V_64 , V_108 , V_90 ) ;
return 0 ;
case V_109 :
if ( V_88 -> V_66 . V_89 != 0 )
return - V_96 ;
F_10 ( clock , V_88 , V_43 ) ;
return 0 ;
default:
break;
}
return - V_110 ;
}
static void F_21 ( struct V_6 * V_7 , bool V_43 )
{
T_2 V_111 = 0 , V_112 ;
if ( V_43 )
V_111 = V_113 | V_114 | V_115 | V_116 ;
V_112 = ( V_117 & V_118 ) << V_119 ;
F_5 ( 0 , V_7 , V_64 , V_120 , V_111 ) ;
F_5 ( 0 , V_7 , V_121 , V_122 , V_112 ) ;
if ( ! V_7 -> V_123 ) {
F_22 ( L_1 ) ;
return;
}
if ( V_43 ) {
if ( F_23 ( V_7 -> V_123 , V_124 ) )
F_22 ( L_2 ) ;
} else {
if ( F_24 ( V_7 -> V_123 , V_124 ) )
F_22 ( L_3 ) ;
}
}
static bool F_25 ( struct V_125 * V_126 , int type )
{
struct V_127 * V_128 = F_26 ( V_126 ) ;
if ( V_129 == type &&
! memcmp ( V_128 -> V_130 , V_131 , sizeof( V_131 ) ) )
return true ;
else
return false ;
}
static int F_27 ( struct V_26 * V_26 )
{
return F_28 ( V_38 , V_26 -> V_37 ) ;
}
static void F_29 ( struct V_9 * V_10 )
{
struct V_132 * V_133 , * V_134 ;
struct V_26 * V_26 ;
F_30 (this, next, &dp83640->rxts) {
V_26 = F_31 ( V_133 , struct V_26 , V_135 ) ;
if ( F_27 ( V_26 ) ) {
F_32 ( & V_26 -> V_135 ) ;
F_33 ( & V_26 -> V_135 , & V_10 -> V_136 ) ;
}
}
}
static void F_34 ( struct V_6 * V_7 , int V_137 , int V_43 )
{
int V_4 ;
F_6 ( V_7 , V_12 , 0 ) ;
V_4 = F_4 ( V_7 , V_138 ) ;
if ( V_43 )
V_4 |= V_139 ;
else
V_4 &= ~ V_139 ;
F_6 ( V_7 , V_138 , V_4 ) ;
F_6 ( V_7 , V_12 , V_137 ) ;
}
static void F_35 ( struct V_40 * clock )
{
T_4 V_140 , V_141 ;
struct V_39 V_142 ;
struct V_16 V_17 ;
struct V_132 * V_133 ;
struct V_9 * V_143 ;
struct V_6 * V_144 = clock -> V_44 -> V_7 ;
T_2 V_145 , V_111 , V_90 , V_48 , V_49 , V_4 ;
V_49 = V_146 ;
V_145 = V_50 [ V_147 ] ;
F_11 ( & clock -> V_63 ) ;
F_36 (this, &clock->phylist) {
V_143 = F_31 ( V_133 , struct V_9 , V_135 ) ;
F_34 ( V_143 -> V_7 , clock -> V_8 , 1 ) ;
V_143 -> V_111 = F_3 ( V_143 -> V_7 , V_64 , V_120 ) ;
F_5 ( 0 , V_143 -> V_7 , V_64 , V_120 , 0 ) ;
F_5 ( 0 , V_143 -> V_7 , V_19 , V_23 , V_148 ) ;
}
F_34 ( V_144 , clock -> V_8 , 1 ) ;
V_111 = F_3 ( V_144 , V_64 , V_120 ) ;
F_5 ( 0 , V_144 , V_64 , V_120 , 0 ) ;
F_5 ( 0 , V_144 , V_19 , V_23 , V_148 ) ;
V_90 = V_98 | V_107 | V_149 ;
V_90 |= ( V_150 & V_99 ) << V_100 ;
V_90 |= ( V_145 & V_102 ) << V_103 ;
F_36 (this, &clock->phylist) {
V_143 = F_31 ( V_133 , struct V_9 , V_135 ) ;
F_5 ( 0 , V_143 -> V_7 , V_64 , V_108 , V_90 ) ;
}
F_5 ( 0 , V_144 , V_64 , V_108 , V_90 ) ;
V_48 = V_53 | V_151 | V_59 ;
V_48 |= ( V_49 & V_54 ) << V_55 ;
V_48 |= ( V_145 & V_56 ) << V_57 ;
F_5 ( 0 , V_144 , V_64 , V_65 , V_48 ) ;
V_4 = ( V_49 & V_60 ) << V_61 ;
V_4 |= V_68 ;
F_5 ( 0 , V_144 , V_19 , V_23 , V_4 ) ;
V_4 &= ~ V_68 ;
V_4 |= V_69 ;
F_5 ( 0 , V_144 , V_19 , V_23 , V_4 ) ;
V_4 = ( V_49 & V_60 ) << V_61 ;
V_4 |= V_62 ;
F_5 ( 0 , V_144 , V_19 , V_23 , V_4 ) ;
V_4 = F_3 ( V_144 , V_19 , V_152 ) ;
F_37 ( L_4 , V_4 ) ;
V_4 = F_3 ( V_144 , V_19 , V_153 ) ;
F_37 ( L_5 , V_4 ) ;
V_142 . V_31 = F_3 ( V_144 , V_19 , V_154 ) ;
V_142 . V_32 = F_3 ( V_144 , V_19 , V_154 ) ;
V_142 . V_28 = F_3 ( V_144 , V_19 , V_154 ) ;
V_142 . V_29 = F_3 ( V_144 , V_19 , V_154 ) ;
V_140 = F_9 ( & V_142 ) ;
F_36 (this, &clock->phylist) {
V_143 = F_31 ( V_133 , struct V_9 , V_135 ) ;
V_4 = F_3 ( V_143 -> V_7 , V_19 , V_152 ) ;
F_37 ( L_6 , V_4 ) ;
V_4 = F_3 ( V_143 -> V_7 , V_19 , V_153 ) ;
F_37 ( L_7 , V_4 ) ;
V_142 . V_31 = F_3 ( V_143 -> V_7 , V_19 , V_154 ) ;
V_142 . V_32 = F_3 ( V_143 -> V_7 , V_19 , V_154 ) ;
V_142 . V_28 = F_3 ( V_143 -> V_7 , V_19 , V_154 ) ;
V_142 . V_29 = F_3 ( V_143 -> V_7 , V_19 , V_154 ) ;
V_141 = V_140 - ( T_4 ) F_9 ( & V_142 ) ;
F_37 ( L_8 , V_141 ) ;
V_141 += V_84 ;
V_17 = F_17 ( V_141 ) ;
F_7 ( 0 , V_143 -> V_7 , & V_17 , V_85 ) ;
}
F_36 (this, &clock->phylist) {
V_143 = F_31 ( V_133 , struct V_9 , V_135 ) ;
F_5 ( 0 , V_143 -> V_7 , V_64 , V_120 , V_143 -> V_111 ) ;
}
F_5 ( 0 , V_144 , V_64 , V_120 , V_111 ) ;
F_12 ( & clock -> V_63 ) ;
}
static inline T_2 F_38 ( int V_155 )
{
return 1 << ( ( V_155 + V_97 ) * 2 ) ;
}
static int F_39 ( struct V_9 * V_10 ,
void * V_156 , T_2 V_157 )
{
struct V_39 * V_39 ;
struct V_158 V_159 ;
int V_160 , V_161 ;
int V_162 = ( V_157 >> V_163 ) & V_164 ;
T_2 V_165 = 0 ;
if ( V_157 & V_166 ) {
V_165 = * ( T_2 * ) V_156 ;
V_156 += sizeof( V_165 ) ;
}
V_39 = V_156 ;
switch ( V_162 ) {
case 3 :
V_10 -> V_167 . V_29 = V_39 -> V_29 ;
case 2 :
V_10 -> V_167 . V_28 = V_39 -> V_28 ;
case 1 :
V_10 -> V_167 . V_32 = V_39 -> V_32 ;
case 0 :
V_10 -> V_167 . V_31 = V_39 -> V_31 ;
}
if ( V_165 ) {
V_161 = V_162 + 2 ;
} else {
V_161 = V_162 + 1 ;
V_160 = ( ( V_157 >> V_168 ) & V_169 ) - V_97 ;
V_165 = F_38 ( V_160 ) ;
}
V_159 . type = V_170 ;
V_159 . V_171 = F_9 ( & V_10 -> V_167 ) ;
for ( V_160 = 0 ; V_160 < V_95 ; V_160 ++ ) {
if ( V_165 & F_38 ( V_160 ) ) {
V_159 . V_89 = V_160 ;
V_158 ( V_10 -> clock -> V_172 , & V_159 ) ;
}
}
return V_161 * sizeof( T_2 ) ;
}
static void F_40 ( struct V_9 * V_10 ,
struct V_24 * V_24 )
{
struct V_26 * V_26 ;
unsigned long V_104 ;
F_41 ( & V_10 -> V_173 , V_104 ) ;
F_29 ( V_10 ) ;
if ( F_42 ( & V_10 -> V_136 ) ) {
F_43 ( L_9 ) ;
goto V_174;
}
V_26 = F_44 ( & V_10 -> V_136 , struct V_26 , V_135 ) ;
F_32 ( & V_26 -> V_135 ) ;
F_8 ( V_24 , V_26 ) ;
F_45 ( & V_26 -> V_135 , & V_10 -> V_26 ) ;
V_174:
F_46 ( & V_10 -> V_173 , V_104 ) ;
}
static void F_47 ( struct V_9 * V_10 ,
struct V_39 * V_39 )
{
struct V_175 V_176 ;
struct V_125 * V_126 ;
V_33 V_30 ;
V_126 = F_48 ( & V_10 -> V_177 ) ;
if ( ! V_126 ) {
F_43 ( L_10 ) ;
return;
}
V_30 = F_9 ( V_39 ) ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_178 = F_49 ( V_30 ) ;
F_50 ( V_126 , & V_176 ) ;
}
static void F_51 ( struct V_9 * V_10 ,
struct V_125 * V_126 )
{
struct V_24 * V_24 ;
struct V_39 * V_39 ;
T_5 * V_179 ;
int V_180 , V_181 ;
T_2 V_157 , type ;
V_179 = V_126 -> V_156 + 2 ;
for ( V_180 = F_52 ( V_126 ) - 2 ; V_180 > sizeof( type ) ; V_180 -= V_181 ) {
type = * ( T_2 * ) V_179 ;
V_157 = type & 0x0fff ;
type = type & 0xf000 ;
V_180 -= sizeof( type ) ;
V_179 += sizeof( type ) ;
if ( V_182 == type && V_180 >= sizeof( * V_24 ) ) {
V_24 = (struct V_24 * ) V_179 ;
F_40 ( V_10 , V_24 ) ;
V_181 = sizeof( * V_24 ) ;
} else if ( V_183 == type && V_180 >= sizeof( * V_39 ) ) {
V_39 = (struct V_39 * ) V_179 ;
F_47 ( V_10 , V_39 ) ;
V_181 = sizeof( * V_39 ) ;
} else if ( V_184 == type && V_180 >= sizeof( * V_39 ) ) {
V_181 = F_39 ( V_10 , V_179 , V_157 ) ;
} else {
V_181 = 0 ;
break;
}
V_179 += V_181 ;
}
}
static int F_53 ( struct V_125 * V_126 , int type )
{
T_5 * V_156 = V_126 -> V_156 , * V_35 ;
unsigned int V_185 = 0 ;
switch ( type ) {
case V_186 :
case V_187 :
V_185 = V_188 + F_54 ( V_156 ) + V_189 ;
break;
case V_190 :
case V_191 :
V_185 = V_192 ;
break;
case V_129 :
V_185 = V_188 ;
break;
case V_193 :
V_185 = V_188 + V_194 ;
break;
default:
return 0 ;
}
if ( type & V_195 )
V_185 += V_196 ;
if ( V_126 -> V_180 < V_185 + 1 )
return 0 ;
V_35 = V_156 + V_185 ;
return ( * V_35 & 0xf ) == 0 ;
}
static int F_55 ( struct V_125 * V_126 , unsigned int type , struct V_26 * V_26 )
{
T_2 * V_34 ;
unsigned int V_185 ;
T_5 * V_35 , * V_156 = F_56 ( V_126 ) ;
switch ( type ) {
case V_186 :
case V_187 :
V_185 = V_188 + F_54 ( V_156 ) + V_189 ;
break;
case V_190 :
case V_191 :
V_185 = V_192 ;
break;
case V_129 :
V_185 = V_188 ;
break;
case V_193 :
V_185 = V_188 + V_194 ;
break;
default:
return 0 ;
}
if ( V_126 -> V_180 + V_188 < V_185 + V_197 + sizeof( * V_34 ) )
return 0 ;
if ( F_57 ( type & V_195 ) )
V_35 = V_156 + V_185 + V_196 ;
else
V_35 = V_156 + V_185 ;
V_34 = ( T_2 * ) ( V_156 + V_185 + V_197 ) ;
return V_26 -> V_35 == ( * V_35 & 0xf ) &&
V_26 -> V_34 == F_58 ( * V_34 ) ;
}
static void F_59 ( void )
{
struct V_40 * clock ;
struct V_132 * V_133 , * V_134 ;
F_11 ( & V_198 ) ;
F_30 (this, next, &phyter_clocks) {
clock = F_31 ( V_133 , struct V_40 , V_135 ) ;
if ( ! F_42 ( & clock -> V_199 ) ) {
F_22 ( L_11 ) ;
F_60 () ;
}
F_61 ( & clock -> V_135 ) ;
F_62 ( & clock -> V_63 ) ;
F_62 ( & clock -> V_200 ) ;
F_63 ( & clock -> V_2 -> V_15 ) ;
F_64 ( clock ) ;
}
F_12 ( & V_198 ) ;
}
static void F_65 ( struct V_40 * clock , struct V_1 * V_2 )
{
F_66 ( & clock -> V_135 ) ;
clock -> V_2 = V_2 ;
F_67 ( & clock -> V_63 ) ;
F_67 ( & clock -> V_200 ) ;
F_66 ( & clock -> V_199 ) ;
clock -> V_73 . V_201 = V_202 ;
sprintf ( clock -> V_73 . V_203 , L_12 ) ;
clock -> V_73 . V_204 = 1953124 ;
clock -> V_73 . V_205 = 0 ;
clock -> V_73 . V_206 = V_95 ;
clock -> V_73 . V_207 = 1 ;
clock -> V_73 . V_208 = 0 ;
clock -> V_73 . V_209 = F_13 ;
clock -> V_73 . V_210 = F_16 ;
clock -> V_73 . V_211 = F_18 ;
clock -> V_73 . V_212 = F_19 ;
clock -> V_73 . V_213 = F_20 ;
F_68 ( & V_2 -> V_15 ) ;
}
static int F_69 ( struct V_40 * clock ,
struct V_6 * V_7 )
{
if ( V_214 == - 1 && ! clock -> V_44 )
return 1 ;
if ( V_214 == V_7 -> V_215 )
return 1 ;
return 0 ;
}
static struct V_40 * F_70 ( struct V_40 * clock )
{
if ( clock )
F_11 ( & clock -> V_200 ) ;
return clock ;
}
static struct V_40 * F_71 ( struct V_1 * V_2 )
{
struct V_40 * clock = NULL , * V_143 ;
struct V_132 * V_133 ;
F_11 ( & V_198 ) ;
F_36 (this, &phyter_clocks) {
V_143 = F_31 ( V_133 , struct V_40 , V_135 ) ;
if ( V_143 -> V_2 == V_2 ) {
clock = V_143 ;
break;
}
}
if ( clock )
goto V_174;
clock = F_72 ( sizeof( struct V_40 ) , V_216 ) ;
if ( ! clock )
goto V_174;
F_65 ( clock , V_2 ) ;
F_45 ( & V_217 , & clock -> V_135 ) ;
V_174:
F_12 ( & V_198 ) ;
return F_70 ( clock ) ;
}
static void F_73 ( struct V_40 * clock )
{
F_12 ( & clock -> V_200 ) ;
}
static int F_74 ( struct V_6 * V_7 )
{
struct V_40 * clock ;
struct V_9 * V_10 ;
int V_83 = - V_218 , V_160 ;
if ( V_7 -> V_215 == V_5 )
return 0 ;
clock = F_71 ( V_7 -> V_2 ) ;
if ( ! clock )
goto V_219;
V_10 = F_72 ( sizeof( struct V_9 ) , V_216 ) ;
if ( ! V_10 )
goto V_220;
V_10 -> V_7 = V_7 ;
F_75 ( & V_10 -> V_221 , V_222 ) ;
F_66 ( & V_10 -> V_26 ) ;
F_66 ( & V_10 -> V_136 ) ;
for ( V_160 = 0 ; V_160 < V_223 ; V_160 ++ )
F_33 ( & V_10 -> V_224 [ V_160 ] . V_135 , & V_10 -> V_136 ) ;
V_7 -> V_11 = V_10 ;
F_76 ( & V_10 -> V_173 ) ;
F_77 ( & V_10 -> V_225 ) ;
F_77 ( & V_10 -> V_177 ) ;
V_10 -> clock = clock ;
if ( F_69 ( clock , V_7 ) ) {
clock -> V_44 = V_10 ;
clock -> V_172 = F_78 ( & clock -> V_73 , & V_7 -> V_15 ) ;
if ( F_79 ( clock -> V_172 ) ) {
V_83 = F_80 ( clock -> V_172 ) ;
goto V_226;
}
} else
F_45 ( & V_10 -> V_135 , & clock -> V_199 ) ;
F_73 ( clock ) ;
return 0 ;
V_226:
clock -> V_44 = NULL ;
F_64 ( V_10 ) ;
V_220:
F_73 ( clock ) ;
V_219:
return V_83 ;
}
static void F_81 ( struct V_6 * V_7 )
{
struct V_40 * clock ;
struct V_132 * V_133 , * V_134 ;
struct V_9 * V_143 , * V_10 = V_7 -> V_11 ;
struct V_125 * V_126 ;
if ( V_7 -> V_215 == V_5 )
return;
F_21 ( V_7 , false ) ;
F_82 ( & V_10 -> V_221 ) ;
while ( ( V_126 = F_48 ( & V_10 -> V_225 ) ) != NULL )
F_83 ( V_126 ) ;
while ( ( V_126 = F_48 ( & V_10 -> V_177 ) ) != NULL )
F_50 ( V_126 , NULL ) ;
clock = F_70 ( V_10 -> clock ) ;
if ( V_10 == clock -> V_44 ) {
F_84 ( clock -> V_172 ) ;
clock -> V_44 = NULL ;
} else {
F_30 (this, next, &clock->phylist) {
V_143 = F_31 ( V_133 , struct V_9 , V_135 ) ;
if ( V_143 == V_10 ) {
F_32 ( & V_143 -> V_135 ) ;
break;
}
}
}
F_73 ( clock ) ;
F_64 ( V_10 ) ;
}
static int F_85 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_40 * clock = V_10 -> clock ;
if ( clock -> V_44 && ! F_42 ( & clock -> V_199 ) )
F_35 ( clock ) ;
else
F_34 ( V_7 , clock -> V_8 , 1 ) ;
F_21 ( V_7 , true ) ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_148 ) ;
return 0 ;
}
static int F_86 ( struct V_6 * V_7 )
{
int V_83 = F_4 ( V_7 , V_227 ) ;
if ( V_83 < 0 )
return V_83 ;
return 0 ;
}
static int F_87 ( struct V_6 * V_7 )
{
int V_228 ;
int V_229 ;
int V_83 ;
if ( V_7 -> V_230 == V_231 ) {
V_229 = F_4 ( V_7 , V_227 ) ;
if ( V_229 < 0 )
return V_229 ;
V_229 |=
( V_232 |
V_233 |
V_234 |
V_235 ) ;
V_83 = F_6 ( V_7 , V_227 , V_229 ) ;
if ( V_83 < 0 )
return V_83 ;
V_228 = F_4 ( V_7 , V_236 ) ;
if ( V_228 < 0 )
return V_228 ;
V_228 |=
( V_237 |
V_238 ) ;
return F_6 ( V_7 , V_236 , V_228 ) ;
} else {
V_228 = F_4 ( V_7 , V_236 ) ;
if ( V_228 < 0 )
return V_228 ;
V_228 &=
~ ( V_237 |
V_238 ) ;
V_83 = F_6 ( V_7 , V_236 , V_228 ) ;
if ( V_83 < 0 )
return V_83 ;
V_229 = F_4 ( V_7 , V_227 ) ;
if ( V_229 < 0 )
return V_229 ;
V_229 &=
~ ( V_232 |
V_233 |
V_234 |
V_235 ) ;
return F_6 ( V_7 , V_227 , V_229 ) ;
}
}
static int F_88 ( struct V_6 * V_7 , struct V_239 * V_240 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_241 V_242 ;
T_2 V_243 , V_244 ;
if ( F_89 ( & V_242 , V_240 -> V_245 , sizeof( V_242 ) ) )
return - V_246 ;
if ( V_242 . V_104 )
return - V_96 ;
if ( V_242 . V_247 < 0 || V_242 . V_247 > V_248 )
return - V_249 ;
V_10 -> V_250 = V_242 . V_247 ;
switch ( V_242 . V_251 ) {
case V_252 :
V_10 -> V_253 = 0 ;
V_10 -> V_254 = 0 ;
V_10 -> V_255 = 0 ;
break;
case V_256 :
case V_257 :
case V_258 :
V_10 -> V_253 = 1 ;
V_10 -> V_254 = V_259 ;
V_10 -> V_255 = 1 ;
break;
case V_260 :
case V_261 :
case V_262 :
V_10 -> V_253 = 1 ;
V_10 -> V_254 = V_259 ;
V_10 -> V_255 = 2 ;
break;
case V_263 :
case V_264 :
case V_265 :
V_10 -> V_253 = 1 ;
V_10 -> V_254 = V_266 ;
V_10 -> V_255 = 2 ;
break;
case V_267 :
case V_268 :
case V_269 :
V_10 -> V_253 = 1 ;
V_10 -> V_254 = V_259 | V_266 ;
V_10 -> V_255 = 2 ;
break;
default:
return - V_249 ;
}
V_243 = ( V_10 -> V_255 & V_270 ) << V_271 ;
V_244 = ( V_10 -> V_255 & V_270 ) << V_271 ;
if ( V_10 -> V_254 & V_266 ) {
V_243 |= V_272 ;
V_244 |= V_273 ;
}
if ( V_10 -> V_254 & V_259 ) {
V_243 |= V_274 | V_275 ;
V_244 |= V_276 | V_277 ;
}
if ( V_10 -> V_250 )
V_243 |= V_278 ;
if ( V_10 -> V_250 == V_248 )
V_243 |= V_279 | V_280 ;
if ( V_10 -> V_253 )
V_244 |= V_281 ;
F_11 ( & V_10 -> clock -> V_63 ) ;
F_5 ( 0 , V_7 , V_64 , V_282 , V_243 ) ;
F_5 ( 0 , V_7 , V_64 , V_283 , V_244 ) ;
F_12 ( & V_10 -> clock -> V_63 ) ;
return F_90 ( V_240 -> V_245 , & V_242 , sizeof( V_242 ) ) ? - V_246 : 0 ;
}
static void V_222 ( struct V_284 * V_285 )
{
struct V_9 * V_10 =
F_14 ( V_285 , struct V_9 , V_221 ) ;
struct V_132 * V_133 , * V_134 ;
struct V_26 * V_26 ;
struct V_175 * V_176 ;
struct V_125 * V_126 ;
unsigned int type ;
unsigned long V_104 ;
while ( ( V_126 = F_48 ( & V_10 -> V_225 ) ) != NULL ) {
type = F_91 ( V_126 ) ;
F_41 ( & V_10 -> V_173 , V_104 ) ;
F_30 (this, next, &dp83640->rxts) {
V_26 = F_31 ( V_133 , struct V_26 , V_135 ) ;
if ( F_55 ( V_126 , type , V_26 ) ) {
V_176 = F_92 ( V_126 ) ;
memset ( V_176 , 0 , sizeof( * V_176 ) ) ;
V_176 -> V_178 = F_49 ( V_26 -> V_30 ) ;
F_32 ( & V_26 -> V_135 ) ;
F_33 ( & V_26 -> V_135 , & V_10 -> V_136 ) ;
break;
}
}
F_46 ( & V_10 -> V_173 , V_104 ) ;
F_93 ( V_126 ) ;
}
F_41 ( & V_10 -> V_173 , V_104 ) ;
F_29 ( V_10 ) ;
F_46 ( & V_10 -> V_173 , V_104 ) ;
}
static bool F_94 ( struct V_6 * V_7 ,
struct V_125 * V_126 , int type )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! V_10 -> V_253 )
return false ;
if ( F_25 ( V_126 , type ) ) {
F_51 ( V_10 , V_126 ) ;
F_83 ( V_126 ) ;
return true ;
}
F_91 ( V_126 ) = type ;
F_95 ( & V_10 -> V_225 , V_126 ) ;
F_96 ( & V_10 -> V_221 ) ;
return true ;
}
static void F_97 ( struct V_6 * V_7 ,
struct V_125 * V_126 , int type )
{
struct V_9 * V_10 = V_7 -> V_11 ;
switch ( V_10 -> V_250 ) {
case V_248 :
if ( F_53 ( V_126 , type ) ) {
F_50 ( V_126 , NULL ) ;
return;
}
case V_286 :
F_98 ( V_126 ) -> V_287 |= V_288 ;
F_95 ( & V_10 -> V_177 , V_126 ) ;
F_96 ( & V_10 -> V_221 ) ;
break;
case V_289 :
default:
F_50 ( V_126 , NULL ) ;
break;
}
}
static int F_99 ( struct V_6 * V_15 , struct V_290 * V_291 )
{
struct V_9 * V_10 = V_15 -> V_11 ;
V_291 -> V_292 =
V_293 |
V_294 |
V_295 ;
V_291 -> V_296 = F_100 ( V_10 -> clock -> V_172 ) ;
V_291 -> V_297 =
( 1 << V_289 ) |
( 1 << V_286 ) |
( 1 << V_248 ) ;
V_291 -> V_298 =
( 1 << V_252 ) |
( 1 << V_256 ) |
( 1 << V_257 ) |
( 1 << V_258 ) |
( 1 << V_260 ) |
( 1 << V_261 ) |
( 1 << V_262 ) |
( 1 << V_263 ) |
( 1 << V_264 ) |
( 1 << V_265 ) |
( 1 << V_267 ) |
( 1 << V_268 ) |
( 1 << V_269 ) ;
return 0 ;
}
static int T_6 F_101 ( void )
{
return F_102 ( & V_299 ) ;
}
static void T_7 F_103 ( void )
{
F_59 () ;
F_104 ( & V_299 ) ;
}
