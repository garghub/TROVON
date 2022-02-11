static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_5 = V_2 -> V_6 . V_5 ;
T_1 V_7 , V_8 , V_9 , V_10 , V_11 , V_12 , V_13 ;
T_2 V_14 = 0 , V_15 = 0 ;
F_2 ( V_4 , V_16 , 0x0 ) ;
F_3 ( V_4 ) ;
if ( ! ( V_2 -> V_17 & V_18 ) )
return;
V_7 = F_4 ( V_4 , V_19 ) ;
V_7 |= V_20 |
V_21 ;
V_8 = V_22 |
V_23 |
V_24 ;
V_9 = ( T_1 ) ( V_25 << V_5 ) ;
V_10 = ( T_1 ) ( ( V_25 << V_5 ) >> 32 ) ;
V_15 |= ( T_2 ) F_4 ( V_4 , V_26 ) ;
V_15 |= ( T_2 ) F_4 ( V_4 , V_27 ) << 32 ;
V_14 = F_5 ( & V_2 -> V_28 , V_15 ) ;
F_6 ( V_14 , V_25 , & V_13 ) ;
V_15 += ( ( V_25 - ( T_2 ) V_13 ) << V_5 ) ;
V_11 = ( T_1 ) V_15 ;
V_12 = ( T_1 ) ( V_15 >> 32 ) ;
F_2 ( V_4 , V_29 , V_9 ) ;
F_2 ( V_4 , V_30 , V_10 ) ;
F_2 ( V_4 , V_31 , V_11 ) ;
F_2 ( V_4 , V_32 , V_12 ) ;
F_2 ( V_4 , V_19 , V_7 ) ;
F_2 ( V_4 , V_16 , V_8 ) ;
F_3 ( V_4 ) ;
}
static T_3 F_7 ( const struct V_33 * V_6 )
{
struct V_1 * V_2 =
F_8 ( V_6 , struct V_1 , V_6 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_34 V_35 ;
F_4 ( V_4 , V_36 ) ;
V_35 . V_37 = F_4 ( V_4 , V_26 ) ;
V_35 . V_38 = F_4 ( V_4 , V_27 ) ;
return ( T_2 ) F_9 ( & V_35 ) ;
}
static T_3 F_10 ( const struct V_33 * V_39 )
{
struct V_1 * V_2 =
F_8 ( V_39 , struct V_1 , V_6 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_40 = 0 ;
V_40 |= ( T_2 ) F_4 ( V_4 , V_26 ) ;
V_40 |= ( T_2 ) F_4 ( V_4 , V_27 ) << 32 ;
return V_40 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_41 * V_42 ,
T_2 V_43 )
{
unsigned long V_44 ;
struct V_34 V_45 ;
T_2 V_14 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
switch ( V_2 -> V_4 . V_46 . type ) {
case V_47 :
case V_48 :
V_45 . V_38 = V_43 >> 32 ;
V_45 . V_37 = V_43 & 0xFFFFFFFF ;
V_43 = F_9 ( & V_45 ) ;
break;
default:
break;
}
F_12 ( & V_2 -> V_49 , V_44 ) ;
V_14 = F_5 ( & V_2 -> V_28 , V_43 ) ;
F_13 ( & V_2 -> V_49 , V_44 ) ;
V_42 -> V_42 = F_14 ( V_14 ) ;
}
static int F_15 ( struct V_50 * V_51 , T_4 V_52 )
{
struct V_1 * V_2 =
F_8 ( V_51 , struct V_1 , V_53 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_54 , V_55 ;
T_1 V_56 ;
int V_57 = 0 ;
if ( V_52 < 0 ) {
V_57 = 1 ;
V_52 = - V_52 ;
}
F_16 () ;
V_55 = F_17 ( V_2 -> V_58 ) ;
V_54 = V_55 ;
V_54 *= V_52 ;
V_56 = F_18 ( V_54 , 1000000000ULL ) ;
V_55 = V_57 ? ( V_55 - V_56 ) : ( V_55 + V_56 ) ;
switch ( V_4 -> V_46 . type ) {
case V_59 :
if ( V_55 > 0xFFFFFFFFULL )
F_19 ( L_1 ) ;
F_2 ( V_4 , V_60 , ( T_1 ) V_55 ) ;
break;
case V_61 :
if ( V_55 > 0x00FFFFFFULL )
F_19 ( L_1 ) ;
F_2 ( V_4 , V_60 ,
( 1 << V_62 ) |
( ( T_1 ) V_55 & 0x00FFFFFFUL ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_20 ( struct V_50 * V_51 , T_4 V_52 )
{
struct V_1 * V_2 =
F_8 ( V_51 , struct V_1 , V_53 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_57 = 0 ;
T_2 V_63 = V_64 ;
T_1 V_65 ;
if ( V_52 < 0 ) {
V_57 = 1 ;
V_52 = - V_52 ;
}
V_63 *= V_52 ;
V_63 = F_18 ( V_63 , 1000000000ULL ) ;
if ( V_63 >= V_66 )
F_19 ( L_1 ) ;
V_65 = V_63 & V_66 ;
if ( V_57 )
V_65 |= V_67 ;
F_2 ( V_4 , V_60 , V_65 ) ;
return 0 ;
}
static int F_21 ( struct V_50 * V_51 , T_5 V_68 )
{
struct V_1 * V_2 =
F_8 ( V_51 , struct V_1 , V_53 ) ;
unsigned long V_44 ;
F_12 ( & V_2 -> V_49 , V_44 ) ;
F_22 ( & V_2 -> V_28 , V_68 ) ;
F_13 ( & V_2 -> V_49 , V_44 ) ;
if ( V_2 -> V_69 )
V_2 -> V_69 ( V_2 ) ;
return 0 ;
}
static int F_23 ( struct V_50 * V_51 , struct V_34 * V_35 )
{
struct V_1 * V_2 =
F_8 ( V_51 , struct V_1 , V_53 ) ;
unsigned long V_44 ;
T_2 V_14 ;
F_12 ( & V_2 -> V_49 , V_44 ) ;
V_14 = F_24 ( & V_2 -> V_28 ) ;
F_13 ( & V_2 -> V_49 , V_44 ) ;
* V_35 = F_25 ( V_14 ) ;
return 0 ;
}
static int F_26 ( struct V_50 * V_51 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 =
F_8 ( V_51 , struct V_1 , V_53 ) ;
unsigned long V_44 ;
T_2 V_14 = F_9 ( V_35 ) ;
F_12 ( & V_2 -> V_49 , V_44 ) ;
F_27 ( & V_2 -> V_28 , & V_2 -> V_6 , V_14 ) ;
F_13 ( & V_2 -> V_49 , V_44 ) ;
if ( V_2 -> V_69 )
V_2 -> V_69 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_50 * V_51 ,
struct V_70 * V_71 , int V_72 )
{
struct V_1 * V_2 =
F_8 ( V_51 , struct V_1 , V_53 ) ;
if ( V_71 -> type != V_73 || ! V_2 -> V_69 )
return - V_74 ;
if ( V_72 )
V_2 -> V_17 |= V_18 ;
else
V_2 -> V_17 &= ~ V_18 ;
V_2 -> V_69 ( V_2 ) ;
return 0 ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_75 V_76 ;
V_76 . type = V_77 ;
if ( ! V_2 -> V_78 )
return;
switch ( V_4 -> V_46 . type ) {
case V_59 :
V_75 ( V_2 -> V_78 , & V_76 ) ;
break;
default:
break;
}
}
void F_30 ( struct V_1 * V_2 )
{
bool V_79 = F_31 ( V_2 -> V_80 +
V_81 ) ;
struct V_34 V_35 ;
if ( V_79 ) {
F_23 ( & V_2 -> V_53 , & V_35 ) ;
V_2 -> V_80 = V_82 ;
}
}
void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_83 = F_4 ( V_4 , V_84 ) ;
struct V_85 * V_86 ;
unsigned long V_87 ;
int V_88 ;
if ( ! ( V_83 & V_89 ) ) {
V_2 -> V_90 = V_82 ;
return;
}
V_87 = V_2 -> V_90 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_91 ; V_88 ++ ) {
V_86 = V_2 -> V_86 [ V_88 ] ;
if ( F_33 ( V_86 -> V_92 , V_87 ) )
V_87 = V_86 -> V_92 ;
}
if ( F_31 ( V_87 + 5 * V_93 ) ) {
F_4 ( V_4 , V_94 ) ;
V_2 -> V_90 = V_82 ;
V_2 -> V_95 ++ ;
F_34 ( V_96 , L_2 ) ;
}
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_4 ( V_4 , V_97 ) ;
if ( V_2 -> V_98 ) {
F_36 ( V_2 -> V_98 ) ;
V_2 -> V_98 = NULL ;
}
F_37 ( V_99 , & V_2 -> V_100 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_41 V_101 ;
T_2 V_102 = 0 ;
V_102 |= ( T_2 ) F_4 ( V_4 , V_103 ) ;
V_102 |= ( T_2 ) F_4 ( V_4 , V_97 ) << 32 ;
F_11 ( V_2 , & V_101 , V_102 ) ;
F_39 ( V_2 -> V_98 , & V_101 ) ;
F_35 ( V_2 ) ;
}
static void F_40 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_8 ( V_105 , struct V_1 ,
V_106 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
bool V_79 = F_31 ( V_2 -> V_107 +
V_108 ) ;
T_1 V_109 ;
if ( ! V_2 -> V_98 ) {
F_35 ( V_2 ) ;
return;
}
V_109 = F_4 ( V_4 , V_110 ) ;
if ( V_109 & V_111 ) {
F_38 ( V_2 ) ;
return;
}
if ( V_79 ) {
F_35 ( V_2 ) ;
V_2 -> V_112 ++ ;
F_34 ( V_96 , L_3 ) ;
} else {
F_41 ( & V_2 -> V_106 ) ;
}
}
void F_42 ( struct V_113 * V_114 ,
struct V_115 * V_116 )
{
T_6 V_102 ;
F_43 ( V_116 , V_116 -> V_117 - V_118 , & V_102 ,
V_118 ) ;
F_44 ( V_116 , V_116 -> V_117 - V_118 ) ;
F_11 ( V_114 -> V_2 , F_45 ( V_116 ) ,
F_46 ( V_102 ) ) ;
}
void F_47 ( struct V_113 * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_2 V_102 = 0 ;
T_1 V_83 ;
if ( ! V_114 || ! V_114 -> V_2 )
return;
V_2 = V_114 -> V_2 ;
V_4 = & V_2 -> V_4 ;
V_83 = F_4 ( V_4 , V_84 ) ;
if ( ! ( V_83 & V_89 ) )
return;
V_102 |= ( T_2 ) F_4 ( V_4 , V_119 ) ;
V_102 |= ( T_2 ) F_4 ( V_4 , V_94 ) << 32 ;
F_11 ( V_2 , F_45 ( V_116 ) , V_102 ) ;
}
int F_48 ( struct V_1 * V_2 , struct V_120 * V_121 )
{
struct V_122 * V_123 = & V_2 -> V_124 ;
return F_49 ( V_121 -> V_125 , V_123 ,
sizeof( * V_123 ) ) ? - V_126 : 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_122 * V_123 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_127 = V_128 ;
T_1 V_129 = V_130 ;
T_1 V_131 = V_132 << 16 ;
bool V_133 = false ;
T_1 V_102 ;
if ( V_123 -> V_44 )
return - V_134 ;
switch ( V_123 -> V_135 ) {
case V_136 :
V_127 = 0 ;
case V_137 :
break;
default:
return - V_138 ;
}
switch ( V_123 -> V_139 ) {
case V_140 :
V_129 = 0 ;
V_131 = 0 ;
V_2 -> V_44 &= ~ ( V_141 |
V_142 ) ;
break;
case V_143 :
V_129 |= V_144 ;
V_131 |= V_145 ;
V_2 -> V_44 &= ~ ( V_141 |
V_142 ) ;
break;
case V_146 :
V_129 |= V_144 ;
V_131 |= V_147 ;
V_2 -> V_44 &= ~ ( V_141 |
V_142 ) ;
break;
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
V_129 |= V_157 ;
V_133 = true ;
V_123 -> V_139 = V_148 ;
V_2 -> V_44 &= ~ ( V_141 |
V_142 ) ;
break;
case V_158 :
case V_159 :
if ( V_4 -> V_46 . type >= V_47 ) {
V_129 |= V_160 ;
V_123 -> V_139 = V_159 ;
V_2 -> V_44 |= V_141 ;
break;
}
default:
V_2 -> V_44 &= ~ ( V_141 |
V_142 ) ;
V_123 -> V_139 = V_140 ;
return - V_138 ;
}
if ( V_4 -> V_46 . type == V_161 ) {
V_2 -> V_44 &= ~ ( V_141 |
V_142 ) ;
if ( V_129 | V_127 )
return - V_138 ;
return 0 ;
}
switch ( V_4 -> V_46 . type ) {
case V_47 :
case V_48 :
if ( V_123 -> V_139 == V_140 )
break;
V_129 = V_130 |
V_160 |
V_162 ;
V_123 -> V_139 = V_159 ;
V_2 -> V_44 |= V_141 ;
V_2 -> V_44 &= ~ V_142 ;
V_133 = true ;
break;
default:
break;
}
if ( V_133 )
F_2 ( V_4 , F_51 ( V_163 ) ,
( V_164 |
V_165 |
V_166 ) ) ;
else
F_2 ( V_4 , F_51 ( V_163 ) , 0 ) ;
V_102 = F_4 ( V_4 , V_110 ) ;
V_102 &= ~ V_128 ;
V_102 |= V_127 ;
F_2 ( V_4 , V_110 , V_102 ) ;
V_102 = F_4 ( V_4 , V_84 ) ;
V_102 &= ~ ( V_130 | V_167 ) ;
V_102 |= V_129 ;
F_2 ( V_4 , V_84 , V_102 ) ;
F_2 ( V_4 , V_168 , V_131 ) ;
F_3 ( V_4 ) ;
F_35 ( V_2 ) ;
F_4 ( V_4 , V_94 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , struct V_120 * V_121 )
{
struct V_122 V_123 ;
int V_169 ;
if ( F_53 ( & V_123 , V_121 -> V_125 , sizeof( V_123 ) ) )
return - V_126 ;
V_169 = F_50 ( V_2 , & V_123 ) ;
if ( V_169 )
return V_169 ;
memcpy ( & V_2 -> V_124 , & V_123 ,
sizeof( V_2 -> V_124 ) ) ;
return F_49 ( V_121 -> V_125 , & V_123 , sizeof( V_123 ) ) ?
- V_126 : 0 ;
}
static void F_54 ( struct V_1 * V_2 ,
T_1 * V_5 , T_1 * V_55 )
{
switch ( V_2 -> V_170 ) {
case V_171 :
* V_5 = V_172 ;
* V_55 = V_173 ;
break;
case V_174 :
* V_5 = V_175 ;
* V_55 = V_176 ;
break;
case V_177 :
default:
* V_5 = V_178 ;
* V_55 = V_179 ;
break;
}
}
void F_55 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_33 V_39 ;
unsigned long V_44 ;
T_1 V_55 = 0 ;
T_1 V_8 = 0 ;
T_1 V_180 = 0 ;
V_39 . V_181 = F_56 ( 64 ) ;
V_39 . V_182 = 1 ;
V_39 . V_5 = 0 ;
switch ( V_4 -> V_46 . type ) {
case V_48 :
V_180 = F_4 ( V_4 , F_57 ( 0 ) ) ;
if ( ! ( V_180 & V_183 ) ) {
V_39 . V_182 = 3 ;
V_39 . V_5 = 2 ;
}
case V_47 :
V_39 . V_184 = F_7 ;
F_2 ( V_4 , V_36 , 0 ) ;
F_2 ( V_4 , V_26 , 0 ) ;
F_2 ( V_4 , V_27 , 0 ) ;
V_8 = F_4 ( V_4 , V_16 ) ;
F_2 ( V_4 , V_16 ,
V_8 & ~ V_185 ) ;
F_2 ( V_4 , V_186 , V_187 ) ;
F_2 ( V_4 , V_188 , V_189 ) ;
F_3 ( V_4 ) ;
break;
case V_59 :
V_39 . V_184 = F_10 ;
F_54 ( V_2 , & V_39 . V_5 , & V_55 ) ;
F_2 ( V_4 , V_60 , V_55 ) ;
break;
case V_61 :
V_39 . V_184 = F_10 ;
F_54 ( V_2 , & V_39 . V_5 , & V_55 ) ;
V_55 >>= V_190 ;
V_39 . V_5 -= V_190 ;
F_2 ( V_4 , V_60 ,
( 1 << V_62 ) | V_55 ) ;
break;
default:
return;
}
F_17 ( V_2 -> V_58 ) = V_55 ;
F_16 () ;
F_12 ( & V_2 -> V_49 , V_44 ) ;
memcpy ( & V_2 -> V_6 , & V_39 , sizeof( V_2 -> V_6 ) ) ;
F_13 ( & V_2 -> V_49 , V_44 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_44 ;
F_50 ( V_2 , & V_2 -> V_124 ) ;
if ( V_4 -> V_46 . type == V_161 )
return;
F_55 ( V_2 ) ;
F_12 ( & V_2 -> V_49 , V_44 ) ;
F_27 ( & V_2 -> V_28 , & V_2 -> V_6 ,
F_59 ( F_60 () ) ) ;
F_13 ( & V_2 -> V_49 , V_44 ) ;
V_2 -> V_80 = V_82 ;
if ( V_2 -> V_69 )
V_2 -> V_69 ( V_2 ) ;
}
static long F_61 ( struct V_1 * V_2 )
{
struct V_191 * V_192 = V_2 -> V_192 ;
long V_169 ;
if ( ! F_62 ( V_2 -> V_78 ) )
return 0 ;
switch ( V_2 -> V_4 . V_46 . type ) {
case V_59 :
snprintf ( V_2 -> V_53 . V_193 ,
sizeof( V_2 -> V_53 . V_193 ) ,
L_4 , V_192 -> V_193 ) ;
V_2 -> V_53 . V_194 = V_195 ;
V_2 -> V_53 . V_196 = 250000000 ;
V_2 -> V_53 . V_197 = 0 ;
V_2 -> V_53 . V_198 = 0 ;
V_2 -> V_53 . V_199 = 0 ;
V_2 -> V_53 . V_200 = 1 ;
V_2 -> V_53 . V_201 = F_15 ;
V_2 -> V_53 . V_202 = F_21 ;
V_2 -> V_53 . V_203 = F_23 ;
V_2 -> V_53 . V_204 = F_26 ;
V_2 -> V_53 . V_205 = F_28 ;
V_2 -> V_69 = F_1 ;
break;
case V_61 :
snprintf ( V_2 -> V_53 . V_193 ,
sizeof( V_2 -> V_53 . V_193 ) ,
L_4 , V_192 -> V_193 ) ;
V_2 -> V_53 . V_194 = V_195 ;
V_2 -> V_53 . V_196 = 250000000 ;
V_2 -> V_53 . V_197 = 0 ;
V_2 -> V_53 . V_198 = 0 ;
V_2 -> V_53 . V_199 = 0 ;
V_2 -> V_53 . V_200 = 0 ;
V_2 -> V_53 . V_201 = F_15 ;
V_2 -> V_53 . V_202 = F_21 ;
V_2 -> V_53 . V_203 = F_23 ;
V_2 -> V_53 . V_204 = F_26 ;
V_2 -> V_53 . V_205 = F_28 ;
break;
case V_47 :
case V_48 :
snprintf ( V_2 -> V_53 . V_193 , 16 , L_4 , V_192 -> V_193 ) ;
V_2 -> V_53 . V_194 = V_195 ;
V_2 -> V_53 . V_196 = 30000000 ;
V_2 -> V_53 . V_197 = 0 ;
V_2 -> V_53 . V_198 = 0 ;
V_2 -> V_53 . V_199 = 0 ;
V_2 -> V_53 . V_200 = 0 ;
V_2 -> V_53 . V_201 = F_20 ;
V_2 -> V_53 . V_202 = F_21 ;
V_2 -> V_53 . V_203 = F_23 ;
V_2 -> V_53 . V_204 = F_26 ;
V_2 -> V_53 . V_205 = F_28 ;
V_2 -> V_69 = NULL ;
break;
default:
V_2 -> V_78 = NULL ;
V_2 -> V_69 = NULL ;
return - V_206 ;
}
V_2 -> V_78 = F_63 ( & V_2 -> V_53 ,
& V_2 -> V_207 -> V_208 ) ;
if ( F_64 ( V_2 -> V_78 ) ) {
V_169 = F_65 ( V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
F_66 ( L_5 ) ;
return V_169 ;
} else
F_67 ( L_6 , V_192 -> V_193 ) ;
V_2 -> V_124 . V_139 = V_140 ;
V_2 -> V_124 . V_135 = V_136 ;
return 0 ;
}
void F_68 ( struct V_1 * V_2 )
{
F_69 ( & V_2 -> V_49 ) ;
if ( F_61 ( V_2 ) )
return;
F_70 ( & V_2 -> V_106 , F_40 ) ;
F_58 ( V_2 ) ;
F_71 ( V_209 , & V_2 -> V_100 ) ;
return;
}
void F_72 ( struct V_1 * V_2 )
{
if ( ! F_73 ( V_209 , & V_2 -> V_100 ) )
return;
V_2 -> V_17 &= ~ V_18 ;
if ( V_2 -> V_69 )
V_2 -> V_69 ( V_2 ) ;
F_74 ( & V_2 -> V_106 ) ;
F_35 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
F_72 ( V_2 ) ;
if ( V_2 -> V_78 ) {
F_76 ( V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
F_67 ( L_7 ,
V_2 -> V_192 -> V_193 ) ;
}
}
