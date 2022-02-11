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
V_26 -> V_37 = V_38 + V_39 ;
}
static V_33 F_9 ( struct V_40 * V_25 )
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
static int F_10 ( struct V_41 * V_42 , T_3 V_43 )
{
struct V_44 * clock =
F_11 ( V_42 , struct V_44 , V_45 ) ;
struct V_6 * V_7 = clock -> V_46 -> V_7 ;
V_33 V_47 ;
int V_48 = 0 ;
T_2 V_49 , V_50 ;
if ( V_43 < 0 ) {
V_48 = 1 ;
V_43 = - V_43 ;
}
V_47 = V_43 ;
V_47 <<= 26 ;
V_47 = F_12 ( V_47 , 1953125 ) ;
V_49 = ( V_47 >> 16 ) & V_51 ;
if ( V_48 )
V_49 |= V_52 ;
V_50 = V_47 & 0xffff ;
F_13 ( & clock -> V_53 ) ;
F_5 ( 1 , V_7 , V_19 , V_54 , V_49 ) ;
F_5 ( 1 , V_7 , V_19 , V_55 , V_50 ) ;
F_14 ( & clock -> V_53 ) ;
return 0 ;
}
static int F_15 ( struct V_41 * V_42 , T_4 V_56 )
{
struct V_44 * clock =
F_11 ( V_42 , struct V_44 , V_45 ) ;
struct V_6 * V_7 = clock -> V_46 -> V_7 ;
struct V_16 V_17 ;
int V_57 ;
V_56 += V_58 ;
V_17 = F_16 ( V_56 ) ;
F_13 ( & clock -> V_53 ) ;
V_57 = F_7 ( 1 , V_7 , & V_17 , V_59 ) ;
F_14 ( & clock -> V_53 ) ;
return V_57 ;
}
static int F_17 ( struct V_41 * V_42 , struct V_16 * V_17 )
{
struct V_44 * clock =
F_11 ( V_42 , struct V_44 , V_45 ) ;
struct V_6 * V_7 = clock -> V_46 -> V_7 ;
unsigned int V_4 [ 4 ] ;
F_13 ( & clock -> V_53 ) ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_60 ) ;
V_4 [ 0 ] = F_3 ( V_7 , V_19 , V_20 ) ;
V_4 [ 1 ] = F_3 ( V_7 , V_19 , V_20 ) ;
V_4 [ 2 ] = F_3 ( V_7 , V_19 , V_20 ) ;
V_4 [ 3 ] = F_3 ( V_7 , V_19 , V_20 ) ;
F_14 ( & clock -> V_53 ) ;
V_17 -> V_21 = V_4 [ 0 ] | ( V_4 [ 1 ] << 16 ) ;
V_17 -> V_22 = V_4 [ 2 ] | ( V_4 [ 3 ] << 16 ) ;
return 0 ;
}
static int F_18 ( struct V_41 * V_42 ,
const struct V_16 * V_17 )
{
struct V_44 * clock =
F_11 ( V_42 , struct V_44 , V_45 ) ;
struct V_6 * V_7 = clock -> V_46 -> V_7 ;
int V_57 ;
F_13 ( & clock -> V_53 ) ;
V_57 = F_7 ( 1 , V_7 , V_17 , V_61 ) ;
F_14 ( & clock -> V_53 ) ;
return V_57 ;
}
static int F_19 ( struct V_41 * V_42 ,
struct V_62 * V_63 , int V_64 )
{
struct V_44 * clock =
F_11 ( V_42 , struct V_44 , V_45 ) ;
struct V_6 * V_7 = clock -> V_46 -> V_7 ;
T_2 V_65 ;
switch ( V_63 -> type ) {
case V_66 :
if ( V_63 -> V_67 . V_68 != 0 )
return - V_69 ;
V_65 = V_70 | ( V_71 & V_72 ) << V_73 ;
if ( V_64 ) {
V_65 |= ( V_74 & V_75 ) << V_76 ;
V_65 |= V_77 ;
}
F_5 ( 0 , V_7 , V_78 , V_79 , V_65 ) ;
return 0 ;
default:
break;
}
return - V_80 ;
}
static void F_20 ( struct V_6 * V_7 , bool V_64 )
{
T_2 V_81 = 0 , V_82 ;
if ( V_64 )
V_81 = V_83 | V_84 | V_85 | V_86 ;
V_82 = ( V_87 & V_88 ) << V_89 ;
F_5 ( 0 , V_7 , V_78 , V_90 , V_81 ) ;
F_5 ( 0 , V_7 , V_91 , V_92 , V_82 ) ;
if ( ! V_7 -> V_93 ) {
F_21 ( L_1 ) ;
return;
}
if ( V_64 ) {
if ( F_22 ( V_7 -> V_93 , V_94 ) )
F_21 ( L_2 ) ;
} else {
if ( F_23 ( V_7 -> V_93 , V_94 ) )
F_21 ( L_3 ) ;
}
}
static bool F_24 ( struct V_95 * V_96 , int type )
{
struct V_97 * V_98 = F_25 ( V_96 ) ;
if ( V_99 == type &&
! memcmp ( V_98 -> V_100 , V_101 , sizeof( V_101 ) ) )
return true ;
else
return false ;
}
static int F_26 ( struct V_26 * V_26 )
{
return F_27 ( V_38 , V_26 -> V_37 ) ;
}
static void F_28 ( struct V_9 * V_10 )
{
struct V_102 * V_103 , * V_104 ;
struct V_26 * V_26 ;
F_29 (this, next, &dp83640->rxts) {
V_26 = F_30 ( V_103 , struct V_26 , V_105 ) ;
if ( F_26 ( V_26 ) ) {
F_31 ( & V_26 -> V_105 ) ;
F_32 ( & V_26 -> V_105 , & V_10 -> V_106 ) ;
}
}
}
static void F_33 ( struct V_6 * V_7 , int V_107 , int V_64 )
{
int V_4 ;
F_6 ( V_7 , V_12 , 0 ) ;
V_4 = F_4 ( V_7 , V_108 ) ;
if ( V_64 )
V_4 |= V_109 ;
else
V_4 &= ~ V_109 ;
F_6 ( V_7 , V_108 , V_4 ) ;
F_6 ( V_7 , V_12 , V_107 ) ;
}
static void F_34 ( struct V_44 * clock )
{
T_4 V_110 , V_111 ;
struct V_40 V_112 ;
struct V_16 V_17 ;
struct V_102 * V_103 ;
struct V_9 * V_113 ;
struct V_6 * V_114 = clock -> V_46 -> V_7 ;
T_2 V_81 , V_65 , V_115 , V_116 , V_4 ;
V_116 = V_117 ;
F_13 ( & clock -> V_53 ) ;
F_35 (this, &clock->phylist) {
V_113 = F_30 ( V_103 , struct V_9 , V_105 ) ;
F_33 ( V_113 -> V_7 , clock -> V_8 , 1 ) ;
V_113 -> V_81 = F_3 ( V_113 -> V_7 , V_78 , V_90 ) ;
F_5 ( 0 , V_113 -> V_7 , V_78 , V_90 , 0 ) ;
F_5 ( 0 , V_113 -> V_7 , V_19 , V_23 , V_118 ) ;
}
F_33 ( V_114 , clock -> V_8 , 1 ) ;
V_81 = F_3 ( V_114 , V_78 , V_90 ) ;
F_5 ( 0 , V_114 , V_78 , V_90 , 0 ) ;
F_5 ( 0 , V_114 , V_19 , V_23 , V_118 ) ;
V_65 = V_70 | V_77 | V_119 ;
V_65 |= ( V_120 & V_72 ) << V_73 ;
V_65 |= ( V_121 & V_75 ) << V_76 ;
F_35 (this, &clock->phylist) {
V_113 = F_30 ( V_103 , struct V_9 , V_105 ) ;
F_5 ( 0 , V_113 -> V_7 , V_78 , V_79 , V_65 ) ;
}
F_5 ( 0 , V_114 , V_78 , V_79 , V_65 ) ;
V_115 = V_122 | V_123 | V_124 ;
V_115 |= ( V_116 & V_125 ) << V_126 ;
V_115 |= ( V_121 & V_127 ) << V_128 ;
F_5 ( 0 , V_114 , V_78 , V_129 , V_115 ) ;
V_4 = ( V_116 & V_130 ) << V_131 ;
V_4 |= V_132 ;
F_5 ( 0 , V_114 , V_19 , V_23 , V_4 ) ;
V_4 &= ~ V_132 ;
V_4 |= V_133 ;
F_5 ( 0 , V_114 , V_19 , V_23 , V_4 ) ;
V_4 = ( V_116 & V_130 ) << V_131 ;
V_4 |= V_134 ;
F_5 ( 0 , V_114 , V_19 , V_23 , V_4 ) ;
V_4 = F_3 ( V_114 , V_19 , V_135 ) ;
F_36 ( L_4 , V_4 ) ;
V_4 = F_3 ( V_114 , V_19 , V_136 ) ;
F_36 ( L_5 , V_4 ) ;
V_112 . V_31 = F_3 ( V_114 , V_19 , V_137 ) ;
V_112 . V_32 = F_3 ( V_114 , V_19 , V_137 ) ;
V_112 . V_28 = F_3 ( V_114 , V_19 , V_137 ) ;
V_112 . V_29 = F_3 ( V_114 , V_19 , V_137 ) ;
V_110 = F_9 ( & V_112 ) ;
F_35 (this, &clock->phylist) {
V_113 = F_30 ( V_103 , struct V_9 , V_105 ) ;
V_4 = F_3 ( V_113 -> V_7 , V_19 , V_135 ) ;
F_36 ( L_6 , V_4 ) ;
V_4 = F_3 ( V_113 -> V_7 , V_19 , V_136 ) ;
F_36 ( L_7 , V_4 ) ;
V_112 . V_31 = F_3 ( V_113 -> V_7 , V_19 , V_137 ) ;
V_112 . V_32 = F_3 ( V_113 -> V_7 , V_19 , V_137 ) ;
V_112 . V_28 = F_3 ( V_113 -> V_7 , V_19 , V_137 ) ;
V_112 . V_29 = F_3 ( V_113 -> V_7 , V_19 , V_137 ) ;
V_111 = V_110 - ( T_4 ) F_9 ( & V_112 ) ;
F_36 ( L_8 , V_111 ) ;
V_111 += V_58 ;
V_17 = F_16 ( V_111 ) ;
F_7 ( 0 , V_113 -> V_7 , & V_17 , V_59 ) ;
}
F_35 (this, &clock->phylist) {
V_113 = F_30 ( V_103 , struct V_9 , V_105 ) ;
F_5 ( 0 , V_113 -> V_7 , V_78 , V_90 , V_113 -> V_81 ) ;
}
F_5 ( 0 , V_114 , V_78 , V_90 , V_81 ) ;
F_14 ( & clock -> V_53 ) ;
}
static int F_37 ( struct V_9 * V_10 ,
void * V_138 , T_2 V_139 )
{
struct V_40 * V_40 ;
struct V_140 V_141 ;
int V_142 = ( V_139 >> V_143 ) & V_144 ;
T_2 V_145 = 0 ;
if ( V_139 & V_146 ) {
V_145 = * ( T_2 * ) V_138 ;
V_138 += sizeof( V_145 ) ;
}
V_40 = V_138 ;
switch ( V_142 ) {
case 3 :
V_10 -> V_147 . V_29 = V_40 -> V_29 ;
case 2 :
V_10 -> V_147 . V_28 = V_40 -> V_28 ;
case 1 :
V_10 -> V_147 . V_32 = V_40 -> V_32 ;
case 0 :
V_10 -> V_147 . V_31 = V_40 -> V_31 ;
}
V_141 . type = V_148 ;
V_141 . V_68 = 0 ;
V_141 . V_149 = F_9 ( & V_10 -> V_147 ) ;
V_140 ( V_10 -> clock -> V_150 , & V_141 ) ;
V_142 = V_145 ? V_142 + 2 : V_142 + 1 ;
return V_142 * sizeof( T_2 ) ;
}
static void F_38 ( struct V_9 * V_10 ,
struct V_24 * V_24 )
{
struct V_26 * V_26 ;
unsigned long V_151 ;
F_39 ( & V_10 -> V_152 , V_151 ) ;
F_28 ( V_10 ) ;
if ( F_40 ( & V_10 -> V_106 ) ) {
F_21 ( L_9 ) ;
goto V_153;
}
V_26 = F_41 ( & V_10 -> V_106 , struct V_26 , V_105 ) ;
F_31 ( & V_26 -> V_105 ) ;
F_8 ( V_24 , V_26 ) ;
F_42 ( & V_26 -> V_105 , & V_10 -> V_26 ) ;
V_153:
F_43 ( & V_10 -> V_152 , V_151 ) ;
}
static void F_44 ( struct V_9 * V_10 ,
struct V_40 * V_40 )
{
struct V_154 V_155 ;
struct V_95 * V_96 ;
V_33 V_30 ;
V_96 = F_45 ( & V_10 -> V_156 ) ;
if ( ! V_96 ) {
F_21 ( L_10 ) ;
return;
}
V_30 = F_9 ( V_40 ) ;
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
V_155 . V_157 = F_46 ( V_30 ) ;
F_47 ( V_96 , & V_155 ) ;
}
static void F_48 ( struct V_9 * V_10 ,
struct V_95 * V_96 )
{
struct V_24 * V_24 ;
struct V_40 * V_40 ;
T_5 * V_158 ;
int V_159 , V_160 ;
T_2 V_139 , type ;
V_158 = V_96 -> V_138 + 2 ;
for ( V_159 = F_49 ( V_96 ) - 2 ; V_159 > sizeof( type ) ; V_159 -= V_160 ) {
type = * ( T_2 * ) V_158 ;
V_139 = type & 0x0fff ;
type = type & 0xf000 ;
V_159 -= sizeof( type ) ;
V_158 += sizeof( type ) ;
if ( V_161 == type && V_159 >= sizeof( * V_24 ) ) {
V_24 = (struct V_24 * ) V_158 ;
F_38 ( V_10 , V_24 ) ;
V_160 = sizeof( * V_24 ) ;
} else if ( V_162 == type && V_159 >= sizeof( * V_40 ) ) {
V_40 = (struct V_40 * ) V_158 ;
F_44 ( V_10 , V_40 ) ;
V_160 = sizeof( * V_40 ) ;
} else if ( V_163 == type && V_159 >= sizeof( * V_40 ) ) {
V_160 = F_37 ( V_10 , V_158 , V_139 ) ;
} else {
V_160 = 0 ;
break;
}
V_158 += V_160 ;
}
}
static int F_50 ( struct V_95 * V_96 , unsigned int type , struct V_26 * V_26 )
{
T_2 * V_34 ;
unsigned int V_164 ;
T_5 * V_35 , * V_138 = F_51 ( V_96 ) ;
switch ( type ) {
case V_165 :
case V_166 :
V_164 = V_167 + F_52 ( V_138 ) + V_168 ;
break;
case V_169 :
case V_170 :
V_164 = V_171 ;
break;
case V_99 :
V_164 = V_167 ;
break;
case V_172 :
V_164 = V_167 + V_173 ;
break;
default:
return 0 ;
}
if ( V_96 -> V_159 + V_167 < V_164 + V_174 + sizeof( * V_34 ) )
return 0 ;
if ( F_53 ( type & V_175 ) )
V_35 = V_138 + V_164 + V_176 ;
else
V_35 = V_138 + V_164 ;
V_34 = ( T_2 * ) ( V_138 + V_164 + V_174 ) ;
return ( V_26 -> V_35 == ( * V_35 & 0xf ) &&
V_26 -> V_34 == F_54 ( * V_34 ) ) ;
}
static void F_55 ( void )
{
struct V_44 * clock ;
struct V_102 * V_103 , * V_104 ;
F_13 ( & V_177 ) ;
F_29 (this, next, &phyter_clocks) {
clock = F_30 ( V_103 , struct V_44 , V_105 ) ;
if ( ! F_40 ( & clock -> V_178 ) ) {
F_21 ( L_11 ) ;
F_56 () ;
}
F_57 ( & clock -> V_105 ) ;
F_58 ( & clock -> V_53 ) ;
F_58 ( & clock -> V_179 ) ;
F_59 ( & clock -> V_2 -> V_15 ) ;
F_60 ( clock ) ;
}
F_14 ( & V_177 ) ;
}
static void F_61 ( struct V_44 * clock , struct V_1 * V_2 )
{
F_62 ( & clock -> V_105 ) ;
clock -> V_2 = V_2 ;
F_63 ( & clock -> V_53 ) ;
F_63 ( & clock -> V_179 ) ;
F_62 ( & clock -> V_178 ) ;
clock -> V_45 . V_180 = V_181 ;
sprintf ( clock -> V_45 . V_182 , L_12 ) ;
clock -> V_45 . V_183 = 1953124 ;
clock -> V_45 . V_184 = 0 ;
clock -> V_45 . V_185 = V_186 ;
clock -> V_45 . V_187 = 0 ;
clock -> V_45 . V_188 = 0 ;
clock -> V_45 . V_189 = F_10 ;
clock -> V_45 . V_190 = F_15 ;
clock -> V_45 . V_191 = F_17 ;
clock -> V_45 . V_192 = F_18 ;
clock -> V_45 . V_193 = F_19 ;
F_64 ( & V_2 -> V_15 ) ;
}
static int F_65 ( struct V_44 * clock ,
struct V_6 * V_7 )
{
if ( V_194 == - 1 && ! clock -> V_46 )
return 1 ;
if ( V_194 == V_7 -> V_195 )
return 1 ;
return 0 ;
}
static struct V_44 * F_66 ( struct V_44 * clock )
{
if ( clock )
F_13 ( & clock -> V_179 ) ;
return clock ;
}
static struct V_44 * F_67 ( struct V_1 * V_2 )
{
struct V_44 * clock = NULL , * V_113 ;
struct V_102 * V_103 ;
F_13 ( & V_177 ) ;
F_35 (this, &phyter_clocks) {
V_113 = F_30 ( V_103 , struct V_44 , V_105 ) ;
if ( V_113 -> V_2 == V_2 ) {
clock = V_113 ;
break;
}
}
if ( clock )
goto V_153;
clock = F_68 ( sizeof( struct V_44 ) , V_196 ) ;
if ( ! clock )
goto V_153;
F_61 ( clock , V_2 ) ;
F_42 ( & V_197 , & clock -> V_105 ) ;
V_153:
F_14 ( & V_177 ) ;
return F_66 ( clock ) ;
}
static void F_69 ( struct V_44 * clock )
{
F_14 ( & clock -> V_179 ) ;
}
static int F_70 ( struct V_6 * V_7 )
{
struct V_44 * clock ;
struct V_9 * V_10 ;
int V_57 = - V_198 , V_199 ;
if ( V_7 -> V_195 == V_5 )
return 0 ;
clock = F_67 ( V_7 -> V_2 ) ;
if ( ! clock )
goto V_200;
V_10 = F_68 ( sizeof( struct V_9 ) , V_196 ) ;
if ( ! V_10 )
goto V_201;
V_10 -> V_7 = V_7 ;
F_71 ( & V_10 -> V_202 , V_203 ) ;
F_62 ( & V_10 -> V_26 ) ;
F_62 ( & V_10 -> V_106 ) ;
for ( V_199 = 0 ; V_199 < V_204 ; V_199 ++ )
F_32 ( & V_10 -> V_205 [ V_199 ] . V_105 , & V_10 -> V_106 ) ;
V_7 -> V_11 = V_10 ;
F_72 ( & V_10 -> V_152 ) ;
F_73 ( & V_10 -> V_206 ) ;
F_73 ( & V_10 -> V_156 ) ;
V_10 -> clock = clock ;
if ( F_65 ( clock , V_7 ) ) {
clock -> V_46 = V_10 ;
clock -> V_150 = F_74 ( & clock -> V_45 ) ;
if ( F_75 ( clock -> V_150 ) ) {
V_57 = F_76 ( clock -> V_150 ) ;
goto V_207;
}
} else
F_42 ( & V_10 -> V_105 , & clock -> V_178 ) ;
if ( clock -> V_46 && ! F_40 ( & clock -> V_178 ) )
F_34 ( clock ) ;
else
F_33 ( V_10 -> V_7 , clock -> V_8 , 1 ) ;
F_69 ( clock ) ;
return 0 ;
V_207:
clock -> V_46 = NULL ;
F_60 ( V_10 ) ;
V_201:
F_69 ( clock ) ;
V_200:
return V_57 ;
}
static void F_77 ( struct V_6 * V_7 )
{
struct V_44 * clock ;
struct V_102 * V_103 , * V_104 ;
struct V_9 * V_113 , * V_10 = V_7 -> V_11 ;
if ( V_7 -> V_195 == V_5 )
return;
F_20 ( V_7 , false ) ;
F_78 ( & V_10 -> V_202 ) ;
clock = F_66 ( V_10 -> clock ) ;
if ( V_10 == clock -> V_46 ) {
F_79 ( clock -> V_150 ) ;
clock -> V_46 = NULL ;
} else {
F_29 (this, next, &clock->phylist) {
V_113 = F_30 ( V_103 , struct V_9 , V_105 ) ;
if ( V_113 == V_10 ) {
F_31 ( & V_113 -> V_105 ) ;
break;
}
}
}
F_69 ( clock ) ;
F_60 ( V_10 ) ;
}
static int F_80 ( struct V_6 * V_7 , struct V_208 * V_209 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_210 V_211 ;
T_2 V_212 , V_213 ;
if ( F_81 ( & V_211 , V_209 -> V_214 , sizeof( V_211 ) ) )
return - V_215 ;
if ( V_211 . V_151 )
return - V_69 ;
switch ( V_211 . V_216 ) {
case V_217 :
V_10 -> V_218 = 0 ;
break;
case V_219 :
V_10 -> V_218 = 1 ;
break;
default:
return - V_220 ;
}
switch ( V_211 . V_221 ) {
case V_222 :
V_10 -> V_223 = 0 ;
V_10 -> V_224 = 0 ;
V_10 -> V_225 = 0 ;
break;
case V_226 :
case V_227 :
case V_228 :
V_10 -> V_223 = 1 ;
V_10 -> V_224 = V_229 ;
V_10 -> V_225 = 1 ;
break;
case V_230 :
case V_231 :
case V_232 :
V_10 -> V_223 = 1 ;
V_10 -> V_224 = V_229 ;
V_10 -> V_225 = 2 ;
break;
case V_233 :
case V_234 :
case V_235 :
V_10 -> V_223 = 1 ;
V_10 -> V_224 = V_236 ;
V_10 -> V_225 = 2 ;
break;
case V_237 :
case V_238 :
case V_239 :
V_10 -> V_223 = 1 ;
V_10 -> V_224 = V_229 | V_236 ;
V_10 -> V_225 = 2 ;
break;
default:
return - V_220 ;
}
V_212 = ( V_10 -> V_225 & V_240 ) << V_241 ;
V_213 = ( V_10 -> V_225 & V_240 ) << V_241 ;
if ( V_10 -> V_224 & V_236 ) {
V_212 |= V_242 ;
V_213 |= V_243 ;
}
if ( V_10 -> V_224 & V_229 ) {
V_212 |= V_244 | V_245 ;
V_213 |= V_246 | V_247 ;
}
if ( V_10 -> V_218 )
V_212 |= V_248 ;
if ( V_10 -> V_223 )
V_213 |= V_249 ;
F_13 ( & V_10 -> clock -> V_53 ) ;
if ( V_10 -> V_218 || V_10 -> V_223 ) {
F_20 ( V_7 , true ) ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_118 ) ;
}
F_5 ( 0 , V_7 , V_78 , V_250 , V_212 ) ;
F_5 ( 0 , V_7 , V_78 , V_251 , V_213 ) ;
F_14 ( & V_10 -> clock -> V_53 ) ;
return F_82 ( V_209 -> V_214 , & V_211 , sizeof( V_211 ) ) ? - V_215 : 0 ;
}
static void V_203 ( struct V_252 * V_253 )
{
struct V_9 * V_10 =
F_11 ( V_253 , struct V_9 , V_202 ) ;
struct V_102 * V_103 , * V_104 ;
struct V_26 * V_26 ;
struct V_154 * V_155 ;
struct V_95 * V_96 ;
unsigned int type ;
unsigned long V_151 ;
while ( ( V_96 = F_45 ( & V_10 -> V_206 ) ) != NULL ) {
type = F_83 ( V_96 ) ;
F_39 ( & V_10 -> V_152 , V_151 ) ;
F_29 (this, next, &dp83640->rxts) {
V_26 = F_30 ( V_103 , struct V_26 , V_105 ) ;
if ( F_50 ( V_96 , type , V_26 ) ) {
V_155 = F_84 ( V_96 ) ;
memset ( V_155 , 0 , sizeof( * V_155 ) ) ;
V_155 -> V_157 = F_46 ( V_26 -> V_30 ) ;
F_31 ( & V_26 -> V_105 ) ;
F_32 ( & V_26 -> V_105 , & V_10 -> V_106 ) ;
break;
}
}
F_43 ( & V_10 -> V_152 , V_151 ) ;
F_85 ( V_96 ) ;
}
F_39 ( & V_10 -> V_152 , V_151 ) ;
F_28 ( V_10 ) ;
F_43 ( & V_10 -> V_152 , V_151 ) ;
}
static bool F_86 ( struct V_6 * V_7 ,
struct V_95 * V_96 , int type )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! V_10 -> V_223 )
return false ;
if ( F_24 ( V_96 , type ) ) {
F_48 ( V_10 , V_96 ) ;
F_87 ( V_96 ) ;
return true ;
}
F_83 ( V_96 ) = type ;
F_88 ( & V_10 -> V_206 , V_96 ) ;
F_89 ( & V_10 -> V_202 ) ;
return true ;
}
static void F_90 ( struct V_6 * V_7 ,
struct V_95 * V_96 , int type )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! V_10 -> V_218 ) {
F_87 ( V_96 ) ;
return;
}
F_88 ( & V_10 -> V_156 , V_96 ) ;
F_89 ( & V_10 -> V_202 ) ;
}
static int T_6 F_91 ( void )
{
return F_92 ( & V_254 ) ;
}
static void T_7 F_93 ( void )
{
F_55 () ;
F_94 ( & V_254 ) ;
}
