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
static int F_10 ( struct V_40 * V_41 , T_3 V_42 )
{
struct V_43 * clock =
F_11 ( V_41 , struct V_43 , V_44 ) ;
struct V_6 * V_7 = clock -> V_45 -> V_7 ;
V_33 V_46 ;
int V_47 = 0 ;
T_2 V_48 , V_49 ;
if ( V_42 < 0 ) {
V_47 = 1 ;
V_42 = - V_42 ;
}
V_46 = V_42 ;
V_46 <<= 26 ;
V_46 = F_12 ( V_46 , 1953125 ) ;
V_48 = ( V_46 >> 16 ) & V_50 ;
if ( V_47 )
V_48 |= V_51 ;
V_49 = V_46 & 0xffff ;
F_13 ( & clock -> V_52 ) ;
F_5 ( 1 , V_7 , V_19 , V_53 , V_48 ) ;
F_5 ( 1 , V_7 , V_19 , V_54 , V_49 ) ;
F_14 ( & clock -> V_52 ) ;
return 0 ;
}
static int F_15 ( struct V_40 * V_41 , T_4 V_55 )
{
struct V_43 * clock =
F_11 ( V_41 , struct V_43 , V_44 ) ;
struct V_6 * V_7 = clock -> V_45 -> V_7 ;
struct V_16 V_17 ;
int V_56 ;
V_55 += V_57 ;
V_17 = F_16 ( V_55 ) ;
F_13 ( & clock -> V_52 ) ;
V_56 = F_7 ( 1 , V_7 , & V_17 , V_58 ) ;
F_14 ( & clock -> V_52 ) ;
return V_56 ;
}
static int F_17 ( struct V_40 * V_41 , struct V_16 * V_17 )
{
struct V_43 * clock =
F_11 ( V_41 , struct V_43 , V_44 ) ;
struct V_6 * V_7 = clock -> V_45 -> V_7 ;
unsigned int V_4 [ 4 ] ;
F_13 ( & clock -> V_52 ) ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_59 ) ;
V_4 [ 0 ] = F_3 ( V_7 , V_19 , V_20 ) ;
V_4 [ 1 ] = F_3 ( V_7 , V_19 , V_20 ) ;
V_4 [ 2 ] = F_3 ( V_7 , V_19 , V_20 ) ;
V_4 [ 3 ] = F_3 ( V_7 , V_19 , V_20 ) ;
F_14 ( & clock -> V_52 ) ;
V_17 -> V_21 = V_4 [ 0 ] | ( V_4 [ 1 ] << 16 ) ;
V_17 -> V_22 = V_4 [ 2 ] | ( V_4 [ 3 ] << 16 ) ;
return 0 ;
}
static int F_18 ( struct V_40 * V_41 ,
const struct V_16 * V_17 )
{
struct V_43 * clock =
F_11 ( V_41 , struct V_43 , V_44 ) ;
struct V_6 * V_7 = clock -> V_45 -> V_7 ;
int V_56 ;
F_13 ( & clock -> V_52 ) ;
V_56 = F_7 ( 1 , V_7 , V_17 , V_60 ) ;
F_14 ( & clock -> V_52 ) ;
return V_56 ;
}
static int F_19 ( struct V_40 * V_41 ,
struct V_61 * V_62 , int V_63 )
{
struct V_43 * clock =
F_11 ( V_41 , struct V_43 , V_44 ) ;
struct V_6 * V_7 = clock -> V_45 -> V_7 ;
T_2 V_64 ;
switch ( V_62 -> type ) {
case V_65 :
if ( V_62 -> V_66 . V_67 != 0 )
return - V_68 ;
V_64 = V_69 | ( V_70 & V_71 ) << V_72 ;
if ( V_63 ) {
V_64 |= ( V_73 & V_74 ) << V_75 ;
V_64 |= V_76 ;
}
F_5 ( 0 , V_7 , V_77 , V_78 , V_64 ) ;
return 0 ;
default:
break;
}
return - V_79 ;
}
static void F_20 ( struct V_6 * V_7 , bool V_63 )
{
T_2 V_80 = 0 , V_81 ;
if ( V_63 )
V_80 = V_82 | V_83 | V_84 | V_85 ;
V_81 = ( V_86 & V_87 ) << V_88 ;
F_5 ( 0 , V_7 , V_77 , V_89 , V_80 ) ;
F_5 ( 0 , V_7 , V_90 , V_91 , V_81 ) ;
if ( ! V_7 -> V_92 ) {
F_21 ( L_1 ) ;
return;
}
if ( V_63 ) {
if ( F_22 ( V_7 -> V_92 , V_93 ) )
F_21 ( L_2 ) ;
} else {
if ( F_23 ( V_7 -> V_92 , V_93 ) )
F_21 ( L_3 ) ;
}
}
static bool F_24 ( struct V_94 * V_95 , int type )
{
struct V_96 * V_97 = F_25 ( V_95 ) ;
if ( V_98 == type &&
! memcmp ( V_97 -> V_99 , V_100 , sizeof( V_100 ) ) )
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
struct V_101 * V_102 , * V_103 ;
struct V_26 * V_26 ;
F_29 (this, next, &dp83640->rxts) {
V_26 = F_30 ( V_102 , struct V_26 , V_104 ) ;
if ( F_26 ( V_26 ) ) {
F_31 ( & V_26 -> V_104 ) ;
F_32 ( & V_26 -> V_104 , & V_10 -> V_105 ) ;
}
}
}
static void F_33 ( struct V_6 * V_7 , int V_106 , int V_63 )
{
int V_4 ;
F_6 ( V_7 , V_12 , 0 ) ;
V_4 = F_4 ( V_7 , V_107 ) ;
if ( V_63 )
V_4 |= V_108 ;
else
V_4 &= ~ V_108 ;
F_6 ( V_7 , V_107 , V_4 ) ;
F_6 ( V_7 , V_12 , V_106 ) ;
}
static void F_34 ( struct V_43 * clock )
{
T_4 V_109 , V_110 ;
struct V_39 V_111 ;
struct V_16 V_17 ;
struct V_101 * V_102 ;
struct V_9 * V_112 ;
struct V_6 * V_113 = clock -> V_45 -> V_7 ;
T_2 V_80 , V_64 , V_114 , V_115 , V_4 ;
V_115 = V_116 ;
F_13 ( & clock -> V_52 ) ;
F_35 (this, &clock->phylist) {
V_112 = F_30 ( V_102 , struct V_9 , V_104 ) ;
F_33 ( V_112 -> V_7 , clock -> V_8 , 1 ) ;
V_112 -> V_80 = F_3 ( V_112 -> V_7 , V_77 , V_89 ) ;
F_5 ( 0 , V_112 -> V_7 , V_77 , V_89 , 0 ) ;
F_5 ( 0 , V_112 -> V_7 , V_19 , V_23 , V_117 ) ;
}
F_33 ( V_113 , clock -> V_8 , 1 ) ;
V_80 = F_3 ( V_113 , V_77 , V_89 ) ;
F_5 ( 0 , V_113 , V_77 , V_89 , 0 ) ;
F_5 ( 0 , V_113 , V_19 , V_23 , V_117 ) ;
V_64 = V_69 | V_76 | V_118 ;
V_64 |= ( V_119 & V_71 ) << V_72 ;
V_64 |= ( V_120 & V_74 ) << V_75 ;
F_35 (this, &clock->phylist) {
V_112 = F_30 ( V_102 , struct V_9 , V_104 ) ;
F_5 ( 0 , V_112 -> V_7 , V_77 , V_78 , V_64 ) ;
}
F_5 ( 0 , V_113 , V_77 , V_78 , V_64 ) ;
V_114 = V_121 | V_122 | V_123 ;
V_114 |= ( V_115 & V_124 ) << V_125 ;
V_114 |= ( V_120 & V_126 ) << V_127 ;
F_5 ( 0 , V_113 , V_77 , V_128 , V_114 ) ;
V_4 = ( V_115 & V_129 ) << V_130 ;
V_4 |= V_131 ;
F_5 ( 0 , V_113 , V_19 , V_23 , V_4 ) ;
V_4 &= ~ V_131 ;
V_4 |= V_132 ;
F_5 ( 0 , V_113 , V_19 , V_23 , V_4 ) ;
V_4 = ( V_115 & V_129 ) << V_130 ;
V_4 |= V_133 ;
F_5 ( 0 , V_113 , V_19 , V_23 , V_4 ) ;
V_4 = F_3 ( V_113 , V_19 , V_134 ) ;
F_36 ( L_4 , V_4 ) ;
V_4 = F_3 ( V_113 , V_19 , V_135 ) ;
F_36 ( L_5 , V_4 ) ;
V_111 . V_31 = F_3 ( V_113 , V_19 , V_136 ) ;
V_111 . V_32 = F_3 ( V_113 , V_19 , V_136 ) ;
V_111 . V_28 = F_3 ( V_113 , V_19 , V_136 ) ;
V_111 . V_29 = F_3 ( V_113 , V_19 , V_136 ) ;
V_109 = F_9 ( & V_111 ) ;
F_35 (this, &clock->phylist) {
V_112 = F_30 ( V_102 , struct V_9 , V_104 ) ;
V_4 = F_3 ( V_112 -> V_7 , V_19 , V_134 ) ;
F_36 ( L_6 , V_4 ) ;
V_4 = F_3 ( V_112 -> V_7 , V_19 , V_135 ) ;
F_36 ( L_7 , V_4 ) ;
V_111 . V_31 = F_3 ( V_112 -> V_7 , V_19 , V_136 ) ;
V_111 . V_32 = F_3 ( V_112 -> V_7 , V_19 , V_136 ) ;
V_111 . V_28 = F_3 ( V_112 -> V_7 , V_19 , V_136 ) ;
V_111 . V_29 = F_3 ( V_112 -> V_7 , V_19 , V_136 ) ;
V_110 = V_109 - ( T_4 ) F_9 ( & V_111 ) ;
F_36 ( L_8 , V_110 ) ;
V_110 += V_57 ;
V_17 = F_16 ( V_110 ) ;
F_7 ( 0 , V_112 -> V_7 , & V_17 , V_58 ) ;
}
F_35 (this, &clock->phylist) {
V_112 = F_30 ( V_102 , struct V_9 , V_104 ) ;
F_5 ( 0 , V_112 -> V_7 , V_77 , V_89 , V_112 -> V_80 ) ;
}
F_5 ( 0 , V_113 , V_77 , V_89 , V_80 ) ;
F_14 ( & clock -> V_52 ) ;
}
static int F_37 ( struct V_9 * V_10 ,
void * V_137 , T_2 V_138 )
{
struct V_39 * V_39 ;
struct V_139 V_140 ;
int V_141 = ( V_138 >> V_142 ) & V_143 ;
T_2 V_144 = 0 ;
if ( V_138 & V_145 ) {
V_144 = * ( T_2 * ) V_137 ;
V_137 += sizeof( V_144 ) ;
}
V_39 = V_137 ;
switch ( V_141 ) {
case 3 :
V_10 -> V_146 . V_29 = V_39 -> V_29 ;
case 2 :
V_10 -> V_146 . V_28 = V_39 -> V_28 ;
case 1 :
V_10 -> V_146 . V_32 = V_39 -> V_32 ;
case 0 :
V_10 -> V_146 . V_31 = V_39 -> V_31 ;
}
V_140 . type = V_147 ;
V_140 . V_67 = 0 ;
V_140 . V_148 = F_9 ( & V_10 -> V_146 ) ;
V_139 ( V_10 -> clock -> V_149 , & V_140 ) ;
V_141 = V_144 ? V_141 + 2 : V_141 + 1 ;
return V_141 * sizeof( T_2 ) ;
}
static void F_38 ( struct V_9 * V_10 ,
struct V_24 * V_24 )
{
struct V_26 * V_26 ;
unsigned long V_150 ;
F_39 ( & V_10 -> V_151 , V_150 ) ;
F_28 ( V_10 ) ;
if ( F_40 ( & V_10 -> V_105 ) ) {
F_41 ( L_9 ) ;
goto V_152;
}
V_26 = F_42 ( & V_10 -> V_105 , struct V_26 , V_104 ) ;
F_31 ( & V_26 -> V_104 ) ;
F_8 ( V_24 , V_26 ) ;
F_43 ( & V_26 -> V_104 , & V_10 -> V_26 ) ;
V_152:
F_44 ( & V_10 -> V_151 , V_150 ) ;
}
static void F_45 ( struct V_9 * V_10 ,
struct V_39 * V_39 )
{
struct V_153 V_154 ;
struct V_94 * V_95 ;
V_33 V_30 ;
V_95 = F_46 ( & V_10 -> V_155 ) ;
if ( ! V_95 ) {
F_41 ( L_10 ) ;
return;
}
V_30 = F_9 ( V_39 ) ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_156 = F_47 ( V_30 ) ;
F_48 ( V_95 , & V_154 ) ;
}
static void F_49 ( struct V_9 * V_10 ,
struct V_94 * V_95 )
{
struct V_24 * V_24 ;
struct V_39 * V_39 ;
T_5 * V_157 ;
int V_158 , V_159 ;
T_2 V_138 , type ;
V_157 = V_95 -> V_137 + 2 ;
for ( V_158 = F_50 ( V_95 ) - 2 ; V_158 > sizeof( type ) ; V_158 -= V_159 ) {
type = * ( T_2 * ) V_157 ;
V_138 = type & 0x0fff ;
type = type & 0xf000 ;
V_158 -= sizeof( type ) ;
V_157 += sizeof( type ) ;
if ( V_160 == type && V_158 >= sizeof( * V_24 ) ) {
V_24 = (struct V_24 * ) V_157 ;
F_38 ( V_10 , V_24 ) ;
V_159 = sizeof( * V_24 ) ;
} else if ( V_161 == type && V_158 >= sizeof( * V_39 ) ) {
V_39 = (struct V_39 * ) V_157 ;
F_45 ( V_10 , V_39 ) ;
V_159 = sizeof( * V_39 ) ;
} else if ( V_162 == type && V_158 >= sizeof( * V_39 ) ) {
V_159 = F_37 ( V_10 , V_157 , V_138 ) ;
} else {
V_159 = 0 ;
break;
}
V_157 += V_159 ;
}
}
static int F_51 ( struct V_94 * V_95 , unsigned int type , struct V_26 * V_26 )
{
T_2 * V_34 ;
unsigned int V_163 ;
T_5 * V_35 , * V_137 = F_52 ( V_95 ) ;
switch ( type ) {
case V_164 :
case V_165 :
V_163 = V_166 + F_53 ( V_137 ) + V_167 ;
break;
case V_168 :
case V_169 :
V_163 = V_170 ;
break;
case V_98 :
V_163 = V_166 ;
break;
case V_171 :
V_163 = V_166 + V_172 ;
break;
default:
return 0 ;
}
if ( V_95 -> V_158 + V_166 < V_163 + V_173 + sizeof( * V_34 ) )
return 0 ;
if ( F_54 ( type & V_174 ) )
V_35 = V_137 + V_163 + V_175 ;
else
V_35 = V_137 + V_163 ;
V_34 = ( T_2 * ) ( V_137 + V_163 + V_173 ) ;
return ( V_26 -> V_35 == ( * V_35 & 0xf ) &&
V_26 -> V_34 == F_55 ( * V_34 ) ) ;
}
static void F_56 ( void )
{
struct V_43 * clock ;
struct V_101 * V_102 , * V_103 ;
F_13 ( & V_176 ) ;
F_29 (this, next, &phyter_clocks) {
clock = F_30 ( V_102 , struct V_43 , V_104 ) ;
if ( ! F_40 ( & clock -> V_177 ) ) {
F_21 ( L_11 ) ;
F_57 () ;
}
F_58 ( & clock -> V_104 ) ;
F_59 ( & clock -> V_52 ) ;
F_59 ( & clock -> V_178 ) ;
F_60 ( & clock -> V_2 -> V_15 ) ;
F_61 ( clock ) ;
}
F_14 ( & V_176 ) ;
}
static void F_62 ( struct V_43 * clock , struct V_1 * V_2 )
{
F_63 ( & clock -> V_104 ) ;
clock -> V_2 = V_2 ;
F_64 ( & clock -> V_52 ) ;
F_64 ( & clock -> V_178 ) ;
F_63 ( & clock -> V_177 ) ;
clock -> V_44 . V_179 = V_180 ;
sprintf ( clock -> V_44 . V_181 , L_12 ) ;
clock -> V_44 . V_182 = 1953124 ;
clock -> V_44 . V_183 = 0 ;
clock -> V_44 . V_184 = V_185 ;
clock -> V_44 . V_186 = 0 ;
clock -> V_44 . V_187 = 0 ;
clock -> V_44 . V_188 = F_10 ;
clock -> V_44 . V_189 = F_15 ;
clock -> V_44 . V_190 = F_17 ;
clock -> V_44 . V_191 = F_18 ;
clock -> V_44 . V_192 = F_19 ;
F_65 ( & V_2 -> V_15 ) ;
}
static int F_66 ( struct V_43 * clock ,
struct V_6 * V_7 )
{
if ( V_193 == - 1 && ! clock -> V_45 )
return 1 ;
if ( V_193 == V_7 -> V_194 )
return 1 ;
return 0 ;
}
static struct V_43 * F_67 ( struct V_43 * clock )
{
if ( clock )
F_13 ( & clock -> V_178 ) ;
return clock ;
}
static struct V_43 * F_68 ( struct V_1 * V_2 )
{
struct V_43 * clock = NULL , * V_112 ;
struct V_101 * V_102 ;
F_13 ( & V_176 ) ;
F_35 (this, &phyter_clocks) {
V_112 = F_30 ( V_102 , struct V_43 , V_104 ) ;
if ( V_112 -> V_2 == V_2 ) {
clock = V_112 ;
break;
}
}
if ( clock )
goto V_152;
clock = F_69 ( sizeof( struct V_43 ) , V_195 ) ;
if ( ! clock )
goto V_152;
F_62 ( clock , V_2 ) ;
F_43 ( & V_196 , & clock -> V_104 ) ;
V_152:
F_14 ( & V_176 ) ;
return F_67 ( clock ) ;
}
static void F_70 ( struct V_43 * clock )
{
F_14 ( & clock -> V_178 ) ;
}
static int F_71 ( struct V_6 * V_7 )
{
struct V_43 * clock ;
struct V_9 * V_10 ;
int V_56 = - V_197 , V_198 ;
if ( V_7 -> V_194 == V_5 )
return 0 ;
clock = F_68 ( V_7 -> V_2 ) ;
if ( ! clock )
goto V_199;
V_10 = F_69 ( sizeof( struct V_9 ) , V_195 ) ;
if ( ! V_10 )
goto V_200;
V_10 -> V_7 = V_7 ;
F_72 ( & V_10 -> V_201 , V_202 ) ;
F_63 ( & V_10 -> V_26 ) ;
F_63 ( & V_10 -> V_105 ) ;
for ( V_198 = 0 ; V_198 < V_203 ; V_198 ++ )
F_32 ( & V_10 -> V_204 [ V_198 ] . V_104 , & V_10 -> V_105 ) ;
V_7 -> V_11 = V_10 ;
F_73 ( & V_10 -> V_151 ) ;
F_74 ( & V_10 -> V_205 ) ;
F_74 ( & V_10 -> V_155 ) ;
V_10 -> clock = clock ;
if ( F_66 ( clock , V_7 ) ) {
clock -> V_45 = V_10 ;
clock -> V_149 = F_75 ( & clock -> V_44 ) ;
if ( F_76 ( clock -> V_149 ) ) {
V_56 = F_77 ( clock -> V_149 ) ;
goto V_206;
}
} else
F_43 ( & V_10 -> V_104 , & clock -> V_177 ) ;
if ( clock -> V_45 && ! F_40 ( & clock -> V_177 ) )
F_34 ( clock ) ;
else
F_33 ( V_10 -> V_7 , clock -> V_8 , 1 ) ;
F_70 ( clock ) ;
return 0 ;
V_206:
clock -> V_45 = NULL ;
F_61 ( V_10 ) ;
V_200:
F_70 ( clock ) ;
V_199:
return V_56 ;
}
static void F_78 ( struct V_6 * V_7 )
{
struct V_43 * clock ;
struct V_101 * V_102 , * V_103 ;
struct V_9 * V_112 , * V_10 = V_7 -> V_11 ;
if ( V_7 -> V_194 == V_5 )
return;
F_20 ( V_7 , false ) ;
F_79 ( & V_10 -> V_201 ) ;
clock = F_67 ( V_10 -> clock ) ;
if ( V_10 == clock -> V_45 ) {
F_80 ( clock -> V_149 ) ;
clock -> V_45 = NULL ;
} else {
F_29 (this, next, &clock->phylist) {
V_112 = F_30 ( V_102 , struct V_9 , V_104 ) ;
if ( V_112 == V_10 ) {
F_31 ( & V_112 -> V_104 ) ;
break;
}
}
}
F_70 ( clock ) ;
F_61 ( V_10 ) ;
}
static int F_81 ( struct V_6 * V_7 , struct V_207 * V_208 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_209 V_210 ;
T_2 V_211 , V_212 ;
if ( F_82 ( & V_210 , V_208 -> V_213 , sizeof( V_210 ) ) )
return - V_214 ;
if ( V_210 . V_150 )
return - V_68 ;
switch ( V_210 . V_215 ) {
case V_216 :
V_10 -> V_217 = 0 ;
break;
case V_218 :
V_10 -> V_217 = 1 ;
break;
default:
return - V_219 ;
}
switch ( V_210 . V_220 ) {
case V_221 :
V_10 -> V_222 = 0 ;
V_10 -> V_223 = 0 ;
V_10 -> V_224 = 0 ;
break;
case V_225 :
case V_226 :
case V_227 :
V_10 -> V_222 = 1 ;
V_10 -> V_223 = V_228 ;
V_10 -> V_224 = 1 ;
break;
case V_229 :
case V_230 :
case V_231 :
V_10 -> V_222 = 1 ;
V_10 -> V_223 = V_228 ;
V_10 -> V_224 = 2 ;
break;
case V_232 :
case V_233 :
case V_234 :
V_10 -> V_222 = 1 ;
V_10 -> V_223 = V_235 ;
V_10 -> V_224 = 2 ;
break;
case V_236 :
case V_237 :
case V_238 :
V_10 -> V_222 = 1 ;
V_10 -> V_223 = V_228 | V_235 ;
V_10 -> V_224 = 2 ;
break;
default:
return - V_219 ;
}
V_211 = ( V_10 -> V_224 & V_239 ) << V_240 ;
V_212 = ( V_10 -> V_224 & V_239 ) << V_240 ;
if ( V_10 -> V_223 & V_235 ) {
V_211 |= V_241 ;
V_212 |= V_242 ;
}
if ( V_10 -> V_223 & V_228 ) {
V_211 |= V_243 | V_244 ;
V_212 |= V_245 | V_246 ;
}
if ( V_10 -> V_217 )
V_211 |= V_247 ;
if ( V_10 -> V_222 )
V_212 |= V_248 ;
F_13 ( & V_10 -> clock -> V_52 ) ;
if ( V_10 -> V_217 || V_10 -> V_222 ) {
F_20 ( V_7 , true ) ;
F_5 ( 0 , V_7 , V_19 , V_23 , V_117 ) ;
}
F_5 ( 0 , V_7 , V_77 , V_249 , V_211 ) ;
F_5 ( 0 , V_7 , V_77 , V_250 , V_212 ) ;
F_14 ( & V_10 -> clock -> V_52 ) ;
return F_83 ( V_208 -> V_213 , & V_210 , sizeof( V_210 ) ) ? - V_214 : 0 ;
}
static void V_202 ( struct V_251 * V_252 )
{
struct V_9 * V_10 =
F_11 ( V_252 , struct V_9 , V_201 ) ;
struct V_101 * V_102 , * V_103 ;
struct V_26 * V_26 ;
struct V_153 * V_154 ;
struct V_94 * V_95 ;
unsigned int type ;
unsigned long V_150 ;
while ( ( V_95 = F_46 ( & V_10 -> V_205 ) ) != NULL ) {
type = F_84 ( V_95 ) ;
F_39 ( & V_10 -> V_151 , V_150 ) ;
F_29 (this, next, &dp83640->rxts) {
V_26 = F_30 ( V_102 , struct V_26 , V_104 ) ;
if ( F_51 ( V_95 , type , V_26 ) ) {
V_154 = F_85 ( V_95 ) ;
memset ( V_154 , 0 , sizeof( * V_154 ) ) ;
V_154 -> V_156 = F_47 ( V_26 -> V_30 ) ;
F_31 ( & V_26 -> V_104 ) ;
F_32 ( & V_26 -> V_104 , & V_10 -> V_105 ) ;
break;
}
}
F_44 ( & V_10 -> V_151 , V_150 ) ;
F_86 ( V_95 ) ;
}
F_39 ( & V_10 -> V_151 , V_150 ) ;
F_28 ( V_10 ) ;
F_44 ( & V_10 -> V_151 , V_150 ) ;
}
static bool F_87 ( struct V_6 * V_7 ,
struct V_94 * V_95 , int type )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! V_10 -> V_222 )
return false ;
if ( F_24 ( V_95 , type ) ) {
F_49 ( V_10 , V_95 ) ;
F_88 ( V_95 ) ;
return true ;
}
F_84 ( V_95 ) = type ;
F_89 ( & V_10 -> V_205 , V_95 ) ;
F_90 ( & V_10 -> V_201 ) ;
return true ;
}
static void F_91 ( struct V_6 * V_7 ,
struct V_94 * V_95 , int type )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! V_10 -> V_217 ) {
F_88 ( V_95 ) ;
return;
}
F_89 ( & V_10 -> V_155 , V_95 ) ;
F_90 ( & V_10 -> V_201 ) ;
}
static int T_6 F_92 ( void )
{
return F_93 ( & V_253 ) ;
}
static void T_7 F_94 ( void )
{
F_56 () ;
F_95 ( & V_253 ) ;
}
