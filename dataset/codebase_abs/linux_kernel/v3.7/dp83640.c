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
V_90 |= V_104 ;
}
F_5 ( 0 , V_7 , V_64 , V_105 , V_90 ) ;
return 0 ;
case V_106 :
if ( V_88 -> V_66 . V_89 != 0 )
return - V_96 ;
F_10 ( clock , V_88 , V_43 ) ;
return 0 ;
default:
break;
}
return - V_107 ;
}
static void F_21 ( struct V_6 * V_7 , bool V_43 )
{
T_2 V_108 = 0 , V_109 ;
if ( V_43 )
V_108 = V_110 | V_111 | V_112 | V_113 ;
V_109 = ( V_114 & V_115 ) << V_116 ;
F_5 ( 0 , V_7 , V_64 , V_117 , V_108 ) ;
F_5 ( 0 , V_7 , V_118 , V_119 , V_109 ) ;
if ( ! V_7 -> V_120 ) {
F_22 ( L_1 ) ;
return;
}
if ( V_43 ) {
if ( F_23 ( V_7 -> V_120 , V_121 ) )
F_22 ( L_2 ) ;
} else {
if ( F_24 ( V_7 -> V_120 , V_121 ) )
F_22 ( L_3 ) ;
}
}
static bool F_25 ( struct V_122 * V_123 , int type )
{
struct V_124 * V_125 = F_26 ( V_123 ) ;
if ( V_126 == type &&
! memcmp ( V_125 -> V_127 , V_128 , sizeof( V_128 ) ) )
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
struct V_129 * V_130 , * V_131 ;
struct V_26 * V_26 ;
F_30 (this, next, &dp83640->rxts) {
V_26 = F_31 ( V_130 , struct V_26 , V_132 ) ;
if ( F_27 ( V_26 ) ) {
F_32 ( & V_26 -> V_132 ) ;
F_33 ( & V_26 -> V_132 , & V_10 -> V_133 ) ;
}
}
}
static void F_34 ( struct V_6 * V_7 , int V_134 , int V_43 )
{
int V_4 ;
F_6 ( V_7 , V_12 , 0 ) ;
V_4 = F_4 ( V_7 , V_135 ) ;
if ( V_43 )
V_4 |= V_136 ;
else
V_4 &= ~ V_136 ;
F_6 ( V_7 , V_135 , V_4 ) ;
F_6 ( V_7 , V_12 , V_134 ) ;
}
static void F_35 ( struct V_40 * clock )
{
T_4 V_137 , V_138 ;
struct V_39 V_139 ;
struct V_16 V_17 ;
struct V_129 * V_130 ;
struct V_9 * V_140 ;
struct V_6 * V_141 = clock -> V_44 -> V_7 ;
T_2 V_142 , V_108 , V_90 , V_48 , V_49 , V_4 ;
V_49 = V_143 ;
V_142 = V_50 [ V_144 ] ;
F_11 ( & clock -> V_63 ) ;
F_36 (this, &clock->phylist) {
V_140 = F_31 ( V_130 , struct V_9 , V_132 ) ;
F_34 ( V_140 -> V_7 , clock -> V_8 , 1 ) ;
V_140 -> V_108 = F_3 ( V_140 -> V_7 , V_64 , V_117 ) ;
F_5 ( 0 , V_140 -> V_7 , V_64 , V_117 , 0 ) ;
F_5 ( 0 , V_140 -> V_7 , V_19 , V_23 , V_145 ) ;
}
F_34 ( V_141 , clock -> V_8 , 1 ) ;
V_108 = F_3 ( V_141 , V_64 , V_117 ) ;
F_5 ( 0 , V_141 , V_64 , V_117 , 0 ) ;
F_5 ( 0 , V_141 , V_19 , V_23 , V_145 ) ;
V_90 = V_98 | V_104 | V_146 ;
V_90 |= ( V_147 & V_99 ) << V_100 ;
V_90 |= ( V_142 & V_102 ) << V_103 ;
F_36 (this, &clock->phylist) {
V_140 = F_31 ( V_130 , struct V_9 , V_132 ) ;
F_5 ( 0 , V_140 -> V_7 , V_64 , V_105 , V_90 ) ;
}
F_5 ( 0 , V_141 , V_64 , V_105 , V_90 ) ;
V_48 = V_53 | V_148 | V_59 ;
V_48 |= ( V_49 & V_54 ) << V_55 ;
V_48 |= ( V_142 & V_56 ) << V_57 ;
F_5 ( 0 , V_141 , V_64 , V_65 , V_48 ) ;
V_4 = ( V_49 & V_60 ) << V_61 ;
V_4 |= V_68 ;
F_5 ( 0 , V_141 , V_19 , V_23 , V_4 ) ;
V_4 &= ~ V_68 ;
V_4 |= V_69 ;
F_5 ( 0 , V_141 , V_19 , V_23 , V_4 ) ;
V_4 = ( V_49 & V_60 ) << V_61 ;
V_4 |= V_62 ;
F_5 ( 0 , V_141 , V_19 , V_23 , V_4 ) ;
V_4 = F_3 ( V_141 , V_19 , V_149 ) ;
F_37 ( L_4 , V_4 ) ;
V_4 = F_3 ( V_141 , V_19 , V_150 ) ;
F_37 ( L_5 , V_4 ) ;
V_139 . V_31 = F_3 ( V_141 , V_19 , V_151 ) ;
V_139 . V_32 = F_3 ( V_141 , V_19 , V_151 ) ;
V_139 . V_28 = F_3 ( V_141 , V_19 , V_151 ) ;
V_139 . V_29 = F_3 ( V_141 , V_19 , V_151 ) ;
V_137 = F_9 ( & V_139 ) ;
F_36 (this, &clock->phylist) {
V_140 = F_31 ( V_130 , struct V_9 , V_132 ) ;
V_4 = F_3 ( V_140 -> V_7 , V_19 , V_149 ) ;
F_37 ( L_6 , V_4 ) ;
V_4 = F_3 ( V_140 -> V_7 , V_19 , V_150 ) ;
F_37 ( L_7 , V_4 ) ;
V_139 . V_31 = F_3 ( V_140 -> V_7 , V_19 , V_151 ) ;
V_139 . V_32 = F_3 ( V_140 -> V_7 , V_19 , V_151 ) ;
V_139 . V_28 = F_3 ( V_140 -> V_7 , V_19 , V_151 ) ;
V_139 . V_29 = F_3 ( V_140 -> V_7 , V_19 , V_151 ) ;
V_138 = V_137 - ( T_4 ) F_9 ( & V_139 ) ;
F_37 ( L_8 , V_138 ) ;
V_138 += V_84 ;
V_17 = F_17 ( V_138 ) ;
F_7 ( 0 , V_140 -> V_7 , & V_17 , V_85 ) ;
}
F_36 (this, &clock->phylist) {
V_140 = F_31 ( V_130 , struct V_9 , V_132 ) ;
F_5 ( 0 , V_140 -> V_7 , V_64 , V_117 , V_140 -> V_108 ) ;
}
F_5 ( 0 , V_141 , V_64 , V_117 , V_108 ) ;
F_12 ( & clock -> V_63 ) ;
}
static inline T_2 F_38 ( int V_152 )
{
return 1 << ( ( V_152 + V_97 ) * 2 ) ;
}
static int F_39 ( struct V_9 * V_10 ,
void * V_153 , T_2 V_154 )
{
struct V_39 * V_39 ;
struct V_155 V_156 ;
int V_157 , V_158 ;
int V_159 = ( V_154 >> V_160 ) & V_161 ;
T_2 V_162 = 0 ;
if ( V_154 & V_163 ) {
V_162 = * ( T_2 * ) V_153 ;
V_153 += sizeof( V_162 ) ;
}
V_39 = V_153 ;
switch ( V_159 ) {
case 3 :
V_10 -> V_164 . V_29 = V_39 -> V_29 ;
case 2 :
V_10 -> V_164 . V_28 = V_39 -> V_28 ;
case 1 :
V_10 -> V_164 . V_32 = V_39 -> V_32 ;
case 0 :
V_10 -> V_164 . V_31 = V_39 -> V_31 ;
}
if ( V_162 ) {
V_158 = V_159 + 2 ;
} else {
V_158 = V_159 + 1 ;
V_157 = ( ( V_154 >> V_165 ) & V_166 ) - V_97 ;
V_162 = F_38 ( V_157 ) ;
}
V_156 . type = V_167 ;
V_156 . V_168 = F_9 ( & V_10 -> V_164 ) ;
for ( V_157 = 0 ; V_157 < V_95 ; V_157 ++ ) {
if ( V_162 & F_38 ( V_157 ) ) {
V_156 . V_89 = V_157 ;
V_155 ( V_10 -> clock -> V_169 , & V_156 ) ;
}
}
return V_158 * sizeof( T_2 ) ;
}
static void F_40 ( struct V_9 * V_10 ,
struct V_24 * V_24 )
{
struct V_26 * V_26 ;
unsigned long V_170 ;
F_41 ( & V_10 -> V_171 , V_170 ) ;
F_29 ( V_10 ) ;
if ( F_42 ( & V_10 -> V_133 ) ) {
F_43 ( L_9 ) ;
goto V_172;
}
V_26 = F_44 ( & V_10 -> V_133 , struct V_26 , V_132 ) ;
F_32 ( & V_26 -> V_132 ) ;
F_8 ( V_24 , V_26 ) ;
F_45 ( & V_26 -> V_132 , & V_10 -> V_26 ) ;
V_172:
F_46 ( & V_10 -> V_171 , V_170 ) ;
}
static void F_47 ( struct V_9 * V_10 ,
struct V_39 * V_39 )
{
struct V_173 V_174 ;
struct V_122 * V_123 ;
V_33 V_30 ;
V_123 = F_48 ( & V_10 -> V_175 ) ;
if ( ! V_123 ) {
F_43 ( L_10 ) ;
return;
}
V_30 = F_9 ( V_39 ) ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
V_174 . V_176 = F_49 ( V_30 ) ;
F_50 ( V_123 , & V_174 ) ;
}
static void F_51 ( struct V_9 * V_10 ,
struct V_122 * V_123 )
{
struct V_24 * V_24 ;
struct V_39 * V_39 ;
T_5 * V_177 ;
int V_178 , V_179 ;
T_2 V_154 , type ;
V_177 = V_123 -> V_153 + 2 ;
for ( V_178 = F_52 ( V_123 ) - 2 ; V_178 > sizeof( type ) ; V_178 -= V_179 ) {
type = * ( T_2 * ) V_177 ;
V_154 = type & 0x0fff ;
type = type & 0xf000 ;
V_178 -= sizeof( type ) ;
V_177 += sizeof( type ) ;
if ( V_180 == type && V_178 >= sizeof( * V_24 ) ) {
V_24 = (struct V_24 * ) V_177 ;
F_40 ( V_10 , V_24 ) ;
V_179 = sizeof( * V_24 ) ;
} else if ( V_181 == type && V_178 >= sizeof( * V_39 ) ) {
V_39 = (struct V_39 * ) V_177 ;
F_47 ( V_10 , V_39 ) ;
V_179 = sizeof( * V_39 ) ;
} else if ( V_182 == type && V_178 >= sizeof( * V_39 ) ) {
V_179 = F_39 ( V_10 , V_177 , V_154 ) ;
} else {
V_179 = 0 ;
break;
}
V_177 += V_179 ;
}
}
static int F_53 ( struct V_122 * V_123 , int type )
{
T_5 * V_153 = V_123 -> V_153 , * V_35 ;
unsigned int V_183 = 0 ;
switch ( type ) {
case V_184 :
case V_185 :
V_183 = V_186 + F_54 ( V_153 ) + V_187 ;
break;
case V_188 :
case V_189 :
V_183 = V_190 ;
break;
case V_126 :
V_183 = V_186 ;
break;
case V_191 :
V_183 = V_186 + V_192 ;
break;
default:
return 0 ;
}
if ( type & V_193 )
V_183 += V_194 ;
if ( V_123 -> V_178 < V_183 + 1 )
return 0 ;
V_35 = V_153 + V_183 ;
return ( * V_35 & 0xf ) == 0 ;
}
static int F_55 ( struct V_122 * V_123 , unsigned int type , struct V_26 * V_26 )
{
T_2 * V_34 ;
unsigned int V_183 ;
T_5 * V_35 , * V_153 = F_56 ( V_123 ) ;
switch ( type ) {
case V_184 :
case V_185 :
V_183 = V_186 + F_54 ( V_153 ) + V_187 ;
break;
case V_188 :
case V_189 :
V_183 = V_190 ;
break;
case V_126 :
V_183 = V_186 ;
break;
case V_191 :
V_183 = V_186 + V_192 ;
break;
default:
return 0 ;
}
if ( V_123 -> V_178 + V_186 < V_183 + V_195 + sizeof( * V_34 ) )
return 0 ;
if ( F_57 ( type & V_193 ) )
V_35 = V_153 + V_183 + V_194 ;
else
V_35 = V_153 + V_183 ;
V_34 = ( T_2 * ) ( V_153 + V_183 + V_195 ) ;
return ( V_26 -> V_35 == ( * V_35 & 0xf ) &&
V_26 -> V_34 == F_58 ( * V_34 ) ) ;
}
static void F_59 ( void )
{
struct V_40 * clock ;
struct V_129 * V_130 , * V_131 ;
F_11 ( & V_196 ) ;
F_30 (this, next, &phyter_clocks) {
clock = F_31 ( V_130 , struct V_40 , V_132 ) ;
if ( ! F_42 ( & clock -> V_197 ) ) {
F_22 ( L_11 ) ;
F_60 () ;
}
F_61 ( & clock -> V_132 ) ;
F_62 ( & clock -> V_63 ) ;
F_62 ( & clock -> V_198 ) ;
F_63 ( & clock -> V_2 -> V_15 ) ;
F_64 ( clock ) ;
}
F_12 ( & V_196 ) ;
}
static void F_65 ( struct V_40 * clock , struct V_1 * V_2 )
{
F_66 ( & clock -> V_132 ) ;
clock -> V_2 = V_2 ;
F_67 ( & clock -> V_63 ) ;
F_67 ( & clock -> V_198 ) ;
F_66 ( & clock -> V_197 ) ;
clock -> V_73 . V_199 = V_200 ;
sprintf ( clock -> V_73 . V_201 , L_12 ) ;
clock -> V_73 . V_202 = 1953124 ;
clock -> V_73 . V_203 = 0 ;
clock -> V_73 . V_204 = V_95 ;
clock -> V_73 . V_205 = 1 ;
clock -> V_73 . V_206 = 0 ;
clock -> V_73 . V_207 = F_13 ;
clock -> V_73 . V_208 = F_16 ;
clock -> V_73 . V_209 = F_18 ;
clock -> V_73 . V_210 = F_19 ;
clock -> V_73 . V_211 = F_20 ;
F_68 ( & V_2 -> V_15 ) ;
}
static int F_69 ( struct V_40 * clock ,
struct V_6 * V_7 )
{
if ( V_212 == - 1 && ! clock -> V_44 )
return 1 ;
if ( V_212 == V_7 -> V_213 )
return 1 ;
return 0 ;
}
static struct V_40 * F_70 ( struct V_40 * clock )
{
if ( clock )
F_11 ( & clock -> V_198 ) ;
return clock ;
}
static struct V_40 * F_71 ( struct V_1 * V_2 )
{
struct V_40 * clock = NULL , * V_140 ;
struct V_129 * V_130 ;
F_11 ( & V_196 ) ;
F_36 (this, &phyter_clocks) {
V_140 = F_31 ( V_130 , struct V_40 , V_132 ) ;
if ( V_140 -> V_2 == V_2 ) {
clock = V_140 ;
break;
}
}
if ( clock )
goto V_172;
clock = F_72 ( sizeof( struct V_40 ) , V_214 ) ;
if ( ! clock )
goto V_172;
F_65 ( clock , V_2 ) ;
F_45 ( & V_215 , & clock -> V_132 ) ;
V_172:
F_12 ( & V_196 ) ;
return F_70 ( clock ) ;
}
static void F_73 ( struct V_40 * clock )
{
F_12 ( & clock -> V_198 ) ;
}
static int F_74 ( struct V_6 * V_7 )
{
struct V_40 * clock ;
struct V_9 * V_10 ;
int V_83 = - V_216 , V_157 ;
if ( V_7 -> V_213 == V_5 )
return 0 ;
clock = F_71 ( V_7 -> V_2 ) ;
if ( ! clock )
goto V_217;
V_10 = F_72 ( sizeof( struct V_9 ) , V_214 ) ;
if ( ! V_10 )
goto V_218;
V_10 -> V_7 = V_7 ;
F_75 ( & V_10 -> V_219 , V_220 ) ;
F_66 ( & V_10 -> V_26 ) ;
F_66 ( & V_10 -> V_133 ) ;
for ( V_157 = 0 ; V_157 < V_221 ; V_157 ++ )
F_33 ( & V_10 -> V_222 [ V_157 ] . V_132 , & V_10 -> V_133 ) ;
V_7 -> V_11 = V_10 ;
F_76 ( & V_10 -> V_171 ) ;
F_77 ( & V_10 -> V_223 ) ;
F_77 ( & V_10 -> V_175 ) ;
V_10 -> clock = clock ;
if ( F_69 ( clock , V_7 ) ) {
clock -> V_44 = V_10 ;
clock -> V_169 = F_78 ( & clock -> V_73 , & V_7 -> V_15 ) ;
if ( F_79 ( clock -> V_169 ) ) {
V_83 = F_80 ( clock -> V_169 ) ;
goto V_224;
}
} else
F_45 ( & V_10 -> V_132 , & clock -> V_197 ) ;
if ( clock -> V_44 && ! F_42 ( & clock -> V_197 ) )
F_35 ( clock ) ;
else
F_34 ( V_10 -> V_7 , clock -> V_8 , 1 ) ;
F_73 ( clock ) ;
return 0 ;
V_224:
clock -> V_44 = NULL ;
F_64 ( V_10 ) ;
V_218:
F_73 ( clock ) ;
V_217:
return V_83 ;
}
static void F_81 ( struct V_6 * V_7 )
{
struct V_40 * clock ;
struct V_129 * V_130 , * V_131 ;
struct V_9 * V_140 , * V_10 = V_7 -> V_11 ;
struct V_122 * V_123 ;
if ( V_7 -> V_213 == V_5 )
return;
F_21 ( V_7 , false ) ;
F_82 ( & V_10 -> V_219 ) ;
while ( ( V_123 = F_48 ( & V_10 -> V_223 ) ) != NULL )
F_83 ( V_123 ) ;
while ( ( V_123 = F_48 ( & V_10 -> V_175 ) ) != NULL )
F_50 ( V_123 , NULL ) ;
clock = F_70 ( V_10 -> clock ) ;
if ( V_10 == clock -> V_44 ) {
F_84 ( clock -> V_169 ) ;
clock -> V_44 = NULL ;
} else {
F_30 (this, next, &clock->phylist) {
V_140 = F_31 ( V_130 , struct V_9 , V_132 ) ;
if ( V_140 == V_10 ) {
F_32 ( & V_140 -> V_132 ) ;
break;
}
}
}
F_73 ( clock ) ;
F_64 ( V_10 ) ;
}
static int F_85 ( struct V_6 * V_7 , struct V_225 * V_226 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_227 V_228 ;
T_2 V_229 , V_230 ;
if ( F_86 ( & V_228 , V_226 -> V_231 , sizeof( V_228 ) ) )
return - V_232 ;
if ( V_228 . V_170 )
return - V_96 ;
if ( V_228 . V_233 < 0 || V_228 . V_233 > V_234 )
return - V_235 ;
V_10 -> V_236 = V_228 . V_233 ;
switch ( V_228 . V_237 ) {
case V_238 :
V_10 -> V_239 = 0 ;
V_10 -> V_240 = 0 ;
V_10 -> V_241 = 0 ;
break;
case V_242 :
case V_243 :
case V_244 :
V_10 -> V_239 = 1 ;
V_10 -> V_240 = V_245 ;
V_10 -> V_241 = 1 ;
break;
case V_246 :
case V_247 :
case V_248 :
V_10 -> V_239 = 1 ;
V_10 -> V_240 = V_245 ;
V_10 -> V_241 = 2 ;
break;
case V_249 :
case V_250 :
case V_251 :
V_10 -> V_239 = 1 ;
V_10 -> V_240 = V_252 ;
V_10 -> V_241 = 2 ;
break;
case V_253 :
case V_254 :
case V_255 :
V_10 -> V_239 = 1 ;
V_10 -> V_240 = V_245 | V_252 ;
V_10 -> V_241 = 2 ;
break;
default:
return - V_235 ;
}
V_229 = ( V_10 -> V_241 & V_256 ) << V_257 ;
V_230 = ( V_10 -> V_241 & V_256 ) << V_257 ;
if ( V_10 -> V_240 & V_252 ) {
V_229 |= V_258 ;
V_230 |= V_259 ;
}
if ( V_10 -> V_240 & V_245 ) {
V_229 |= V_260 | V_261 ;
V_230 |= V_262 | V_263 ;
}
if ( V_10 -> V_236 )
V_229 |= V_264 ;
if ( V_10 -> V_236 == V_234 )
V_229 |= V_265 | V_266 ;
if ( V_10 -> V_239 )
V_230 |= V_267 ;
F_11 ( & V_10 -> clock -> V_63 ) ;
if ( V_10 -> V_236 || V_10 -> V_239 ) {
F_21 ( V_7 , true ) ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_145 ) ;
}
F_5 ( 0 , V_7 , V_64 , V_268 , V_229 ) ;
F_5 ( 0 , V_7 , V_64 , V_269 , V_230 ) ;
F_12 ( & V_10 -> clock -> V_63 ) ;
return F_87 ( V_226 -> V_231 , & V_228 , sizeof( V_228 ) ) ? - V_232 : 0 ;
}
static void V_220 ( struct V_270 * V_271 )
{
struct V_9 * V_10 =
F_14 ( V_271 , struct V_9 , V_219 ) ;
struct V_129 * V_130 , * V_131 ;
struct V_26 * V_26 ;
struct V_173 * V_174 ;
struct V_122 * V_123 ;
unsigned int type ;
unsigned long V_170 ;
while ( ( V_123 = F_48 ( & V_10 -> V_223 ) ) != NULL ) {
type = F_88 ( V_123 ) ;
F_41 ( & V_10 -> V_171 , V_170 ) ;
F_30 (this, next, &dp83640->rxts) {
V_26 = F_31 ( V_130 , struct V_26 , V_132 ) ;
if ( F_55 ( V_123 , type , V_26 ) ) {
V_174 = F_89 ( V_123 ) ;
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
V_174 -> V_176 = F_49 ( V_26 -> V_30 ) ;
F_32 ( & V_26 -> V_132 ) ;
F_33 ( & V_26 -> V_132 , & V_10 -> V_133 ) ;
break;
}
}
F_46 ( & V_10 -> V_171 , V_170 ) ;
F_90 ( V_123 ) ;
}
F_41 ( & V_10 -> V_171 , V_170 ) ;
F_29 ( V_10 ) ;
F_46 ( & V_10 -> V_171 , V_170 ) ;
}
static bool F_91 ( struct V_6 * V_7 ,
struct V_122 * V_123 , int type )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! V_10 -> V_239 )
return false ;
if ( F_25 ( V_123 , type ) ) {
F_51 ( V_10 , V_123 ) ;
F_83 ( V_123 ) ;
return true ;
}
F_88 ( V_123 ) = type ;
F_92 ( & V_10 -> V_223 , V_123 ) ;
F_93 ( & V_10 -> V_219 ) ;
return true ;
}
static void F_94 ( struct V_6 * V_7 ,
struct V_122 * V_123 , int type )
{
struct V_9 * V_10 = V_7 -> V_11 ;
switch ( V_10 -> V_236 ) {
case V_234 :
if ( F_53 ( V_123 , type ) ) {
F_50 ( V_123 , NULL ) ;
return;
}
case V_272 :
F_92 ( & V_10 -> V_175 , V_123 ) ;
F_93 ( & V_10 -> V_219 ) ;
break;
case V_273 :
default:
F_50 ( V_123 , NULL ) ;
break;
}
}
static int F_95 ( struct V_6 * V_15 , struct V_274 * V_275 )
{
struct V_9 * V_10 = V_15 -> V_11 ;
V_275 -> V_276 =
V_277 |
V_278 |
V_279 ;
V_275 -> V_280 = F_96 ( V_10 -> clock -> V_169 ) ;
V_275 -> V_281 =
( 1 << V_273 ) |
( 1 << V_272 ) |
( 1 << V_234 ) ;
V_275 -> V_282 =
( 1 << V_238 ) |
( 1 << V_242 ) |
( 1 << V_243 ) |
( 1 << V_244 ) |
( 1 << V_246 ) |
( 1 << V_247 ) |
( 1 << V_248 ) |
( 1 << V_249 ) |
( 1 << V_250 ) |
( 1 << V_251 ) |
( 1 << V_253 ) |
( 1 << V_254 ) |
( 1 << V_255 ) ;
return 0 ;
}
static int T_6 F_97 ( void )
{
return F_98 ( & V_283 ) ;
}
static void T_7 F_99 ( void )
{
F_59 () ;
F_100 ( & V_283 ) ;
}
