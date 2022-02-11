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
static T_2 F_7 ( const struct V_33 * V_6 )
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
static T_2 F_10 ( const struct V_33 * V_39 )
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
case V_49 :
V_45 . V_38 = V_43 >> 32 ;
V_45 . V_37 = V_43 & 0xFFFFFFFF ;
V_43 = F_9 ( & V_45 ) ;
break;
default:
break;
}
F_12 ( & V_2 -> V_50 , V_44 ) ;
V_14 = F_5 ( & V_2 -> V_28 , V_43 ) ;
F_13 ( & V_2 -> V_50 , V_44 ) ;
V_42 -> V_42 = F_14 ( V_14 ) ;
}
static int F_15 ( struct V_51 * V_52 , T_3 V_53 )
{
struct V_1 * V_2 =
F_8 ( V_52 , struct V_1 , V_54 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
T_2 V_55 , V_56 ;
T_1 V_57 ;
int V_58 = 0 ;
if ( V_53 < 0 ) {
V_58 = 1 ;
V_53 = - V_53 ;
}
F_16 () ;
V_56 = F_17 ( V_2 -> V_59 ) ;
V_55 = V_56 ;
V_55 *= V_53 ;
V_57 = F_18 ( V_55 , 1000000000ULL ) ;
V_56 = V_58 ? ( V_56 - V_57 ) : ( V_56 + V_57 ) ;
switch ( V_4 -> V_46 . type ) {
case V_60 :
if ( V_56 > 0xFFFFFFFFULL )
F_19 ( L_1 ) ;
F_2 ( V_4 , V_61 , ( T_1 ) V_56 ) ;
break;
case V_62 :
if ( V_56 > 0x00FFFFFFULL )
F_19 ( L_1 ) ;
F_2 ( V_4 , V_61 ,
F_20 ( V_63 ) |
( ( T_1 ) V_56 & 0x00FFFFFFUL ) ) ;
break;
default:
break;
}
return 0 ;
}
static int F_21 ( struct V_51 * V_52 , T_3 V_53 )
{
struct V_1 * V_2 =
F_8 ( V_52 , struct V_1 , V_54 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
int V_58 = 0 ;
T_2 V_64 = V_65 ;
T_1 V_66 ;
if ( V_53 < 0 ) {
V_58 = 1 ;
V_53 = - V_53 ;
}
V_64 *= V_53 ;
V_64 = F_18 ( V_64 , 1000000000ULL ) ;
if ( V_64 >= V_67 )
F_19 ( L_1 ) ;
V_66 = V_64 & V_67 ;
if ( V_58 )
V_66 |= V_68 ;
F_2 ( V_4 , V_61 , V_66 ) ;
return 0 ;
}
static int F_22 ( struct V_51 * V_52 , T_4 V_69 )
{
struct V_1 * V_2 =
F_8 ( V_52 , struct V_1 , V_54 ) ;
unsigned long V_44 ;
F_12 ( & V_2 -> V_50 , V_44 ) ;
F_23 ( & V_2 -> V_28 , V_69 ) ;
F_13 ( & V_2 -> V_50 , V_44 ) ;
if ( V_2 -> V_70 )
V_2 -> V_70 ( V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_51 * V_52 , struct V_34 * V_35 )
{
struct V_1 * V_2 =
F_8 ( V_52 , struct V_1 , V_54 ) ;
unsigned long V_44 ;
T_2 V_14 ;
F_12 ( & V_2 -> V_50 , V_44 ) ;
V_14 = F_25 ( & V_2 -> V_28 ) ;
F_13 ( & V_2 -> V_50 , V_44 ) ;
* V_35 = F_26 ( V_14 ) ;
return 0 ;
}
static int F_27 ( struct V_51 * V_52 ,
const struct V_34 * V_35 )
{
struct V_1 * V_2 =
F_8 ( V_52 , struct V_1 , V_54 ) ;
unsigned long V_44 ;
T_2 V_14 = F_9 ( V_35 ) ;
F_12 ( & V_2 -> V_50 , V_44 ) ;
F_28 ( & V_2 -> V_28 , & V_2 -> V_6 , V_14 ) ;
F_13 ( & V_2 -> V_50 , V_44 ) ;
if ( V_2 -> V_70 )
V_2 -> V_70 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_51 * V_52 ,
struct V_71 * V_72 , int V_73 )
{
struct V_1 * V_2 =
F_8 ( V_52 , struct V_1 , V_54 ) ;
if ( V_72 -> type != V_74 || ! V_2 -> V_70 )
return - V_75 ;
if ( V_73 )
V_2 -> V_17 |= V_18 ;
else
V_2 -> V_17 &= ~ V_18 ;
V_2 -> V_70 ( V_2 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_76 V_77 ;
V_77 . type = V_78 ;
if ( ! V_2 -> V_79 )
return;
switch ( V_4 -> V_46 . type ) {
case V_60 :
V_76 ( V_2 -> V_79 , & V_77 ) ;
break;
default:
break;
}
}
void F_31 ( struct V_1 * V_2 )
{
bool V_80 = F_32 ( V_2 -> V_81 +
V_82 ) ;
struct V_34 V_35 ;
if ( V_80 ) {
F_24 ( & V_2 -> V_54 , & V_35 ) ;
V_2 -> V_81 = V_83 ;
}
}
void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_84 = F_4 ( V_4 , V_85 ) ;
struct V_86 * V_87 ;
unsigned long V_88 ;
int V_89 ;
if ( ! ( V_84 & V_90 ) ) {
V_2 -> V_91 = V_83 ;
return;
}
V_88 = V_2 -> V_91 ;
for ( V_89 = 0 ; V_89 < V_2 -> V_92 ; V_89 ++ ) {
V_87 = V_2 -> V_87 [ V_89 ] ;
if ( F_34 ( V_87 -> V_93 , V_88 ) )
V_88 = V_87 -> V_93 ;
}
if ( F_32 ( V_88 + 5 * V_94 ) ) {
F_4 ( V_4 , V_95 ) ;
V_2 -> V_91 = V_83 ;
V_2 -> V_96 ++ ;
F_35 ( V_97 , L_2 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
F_4 ( V_4 , V_98 ) ;
if ( V_2 -> V_99 ) {
F_37 ( V_2 -> V_99 ) ;
V_2 -> V_99 = NULL ;
}
F_38 ( V_100 , & V_2 -> V_101 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
bool V_80 = F_32 ( V_2 -> V_102 +
V_103 ) ;
if ( ! V_2 -> V_99 )
return;
if ( ! F_40 ( V_100 , & V_2 -> V_101 ) )
return;
if ( V_80 ) {
F_41 ( & V_2 -> V_104 ) ;
F_36 ( V_2 ) ;
V_2 -> V_105 ++ ;
F_35 ( V_97 , L_3 ) ;
}
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_106 * V_107 = V_2 -> V_99 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_41 V_108 ;
T_2 V_109 = 0 ;
V_109 |= ( T_2 ) F_4 ( V_4 , V_110 ) ;
V_109 |= ( T_2 ) F_4 ( V_4 , V_98 ) << 32 ;
F_11 ( V_2 , & V_108 , V_109 ) ;
V_2 -> V_99 = NULL ;
F_38 ( V_100 , & V_2 -> V_101 ) ;
F_43 ( V_107 , & V_108 ) ;
F_37 ( V_107 ) ;
}
static void F_44 ( struct V_111 * V_112 )
{
struct V_1 * V_2 = F_8 ( V_112 , struct V_1 ,
V_104 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
bool V_80 = F_32 ( V_2 -> V_102 +
V_103 ) ;
T_1 V_113 ;
if ( ! V_2 -> V_99 ) {
F_36 ( V_2 ) ;
return;
}
V_113 = F_4 ( V_4 , V_114 ) ;
if ( V_113 & V_115 ) {
F_42 ( V_2 ) ;
return;
}
if ( V_80 ) {
F_36 ( V_2 ) ;
V_2 -> V_105 ++ ;
F_35 ( V_97 , L_4 ) ;
} else {
F_45 ( & V_2 -> V_104 ) ;
}
}
void F_46 ( struct V_116 * V_117 ,
struct V_106 * V_107 )
{
T_5 V_109 ;
F_47 ( V_107 , V_107 -> V_118 - V_119 , & V_109 ,
V_119 ) ;
F_48 ( V_107 , V_107 -> V_118 - V_119 ) ;
F_11 ( V_117 -> V_2 , F_49 ( V_107 ) ,
F_50 ( V_109 ) ) ;
}
void F_51 ( struct V_116 * V_117 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_2 V_109 = 0 ;
T_1 V_84 ;
if ( ! V_117 || ! V_117 -> V_2 )
return;
V_2 = V_117 -> V_2 ;
V_4 = & V_2 -> V_4 ;
V_84 = F_4 ( V_4 , V_85 ) ;
if ( ! ( V_84 & V_90 ) )
return;
V_109 |= ( T_2 ) F_4 ( V_4 , V_120 ) ;
V_109 |= ( T_2 ) F_4 ( V_4 , V_95 ) << 32 ;
F_11 ( V_2 , F_49 ( V_107 ) , V_109 ) ;
}
int F_52 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
struct V_123 * V_124 = & V_2 -> V_125 ;
return F_53 ( V_122 -> V_126 , V_124 ,
sizeof( * V_124 ) ) ? - V_127 : 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_123 * V_124 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
T_1 V_128 = V_129 ;
T_1 V_130 = V_131 ;
T_1 V_132 = V_133 << 16 ;
bool V_134 = false ;
T_1 V_109 ;
if ( V_124 -> V_44 )
return - V_135 ;
switch ( V_124 -> V_136 ) {
case V_137 :
V_128 = 0 ;
case V_138 :
break;
default:
return - V_139 ;
}
switch ( V_124 -> V_140 ) {
case V_141 :
V_130 = 0 ;
V_132 = 0 ;
V_2 -> V_44 &= ~ ( V_142 |
V_143 ) ;
break;
case V_144 :
V_130 |= V_145 ;
V_132 |= V_146 ;
V_2 -> V_44 |= ( V_142 |
V_143 ) ;
break;
case V_147 :
V_130 |= V_145 ;
V_132 |= V_148 ;
V_2 -> V_44 |= ( V_142 |
V_143 ) ;
break;
case V_149 :
case V_150 :
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_156 :
case V_157 :
V_130 |= V_158 ;
V_134 = true ;
V_124 -> V_140 = V_149 ;
V_2 -> V_44 |= ( V_142 |
V_143 ) ;
break;
case V_159 :
case V_160 :
case V_161 :
if ( V_4 -> V_46 . type >= V_47 ) {
V_130 |= V_162 ;
V_124 -> V_140 = V_161 ;
V_2 -> V_44 |= V_142 ;
break;
}
default:
V_2 -> V_44 &= ~ ( V_142 |
V_143 ) ;
V_124 -> V_140 = V_141 ;
return - V_139 ;
}
if ( V_4 -> V_46 . type == V_163 ) {
V_2 -> V_44 &= ~ ( V_142 |
V_143 ) ;
if ( V_130 | V_128 )
return - V_139 ;
return 0 ;
}
switch ( V_4 -> V_46 . type ) {
case V_47 :
case V_48 :
case V_49 :
if ( V_124 -> V_140 == V_141 )
break;
V_130 = V_131 |
V_162 |
V_164 ;
V_124 -> V_140 = V_161 ;
V_2 -> V_44 |= V_142 ;
V_2 -> V_44 &= ~ V_143 ;
V_134 = true ;
break;
default:
break;
}
if ( V_134 )
F_2 ( V_4 , F_55 ( V_165 ) ,
( V_166 |
V_167 |
V_168 ) ) ;
else
F_2 ( V_4 , F_55 ( V_165 ) , 0 ) ;
V_109 = F_4 ( V_4 , V_114 ) ;
V_109 &= ~ V_129 ;
V_109 |= V_128 ;
F_2 ( V_4 , V_114 , V_109 ) ;
V_109 = F_4 ( V_4 , V_85 ) ;
V_109 &= ~ ( V_131 | V_169 ) ;
V_109 |= V_130 ;
F_2 ( V_4 , V_85 , V_109 ) ;
F_2 ( V_4 , V_170 , V_132 ) ;
F_3 ( V_4 ) ;
F_36 ( V_2 ) ;
F_4 ( V_4 , V_95 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 , struct V_121 * V_122 )
{
struct V_123 V_124 ;
int V_171 ;
if ( F_57 ( & V_124 , V_122 -> V_126 , sizeof( V_124 ) ) )
return - V_127 ;
V_171 = F_54 ( V_2 , & V_124 ) ;
if ( V_171 )
return V_171 ;
memcpy ( & V_2 -> V_125 , & V_124 ,
sizeof( V_2 -> V_125 ) ) ;
return F_53 ( V_122 -> V_126 , & V_124 , sizeof( V_124 ) ) ?
- V_127 : 0 ;
}
static void F_58 ( struct V_1 * V_2 ,
T_1 * V_5 , T_1 * V_56 )
{
switch ( V_2 -> V_172 ) {
case V_173 :
* V_5 = V_174 ;
* V_56 = V_175 ;
break;
case V_176 :
* V_5 = V_177 ;
* V_56 = V_178 ;
break;
case V_179 :
default:
* V_5 = V_180 ;
* V_56 = V_181 ;
break;
}
}
void F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_33 V_39 ;
unsigned long V_44 ;
T_1 V_56 = 0 ;
T_1 V_8 = 0 ;
T_1 V_182 = 0 ;
V_39 . V_183 = F_60 ( 64 ) ;
V_39 . V_184 = 1 ;
V_39 . V_5 = 0 ;
switch ( V_4 -> V_46 . type ) {
case V_48 :
V_182 = F_4 ( V_4 , F_61 ( 0 ) ) ;
if ( ! ( V_182 & V_185 ) ) {
V_39 . V_184 = 3 ;
V_39 . V_5 = 2 ;
}
case V_49 :
case V_47 :
V_39 . V_186 = F_7 ;
F_2 ( V_4 , V_36 , 0 ) ;
F_2 ( V_4 , V_26 , 0 ) ;
F_2 ( V_4 , V_27 , 0 ) ;
V_8 = F_4 ( V_4 , V_16 ) ;
F_2 ( V_4 , V_16 ,
V_8 & ~ V_187 ) ;
F_2 ( V_4 , V_188 , V_189 ) ;
F_2 ( V_4 , V_190 , V_191 ) ;
F_3 ( V_4 ) ;
break;
case V_60 :
V_39 . V_186 = F_10 ;
F_58 ( V_2 , & V_39 . V_5 , & V_56 ) ;
F_2 ( V_4 , V_61 , V_56 ) ;
break;
case V_62 :
V_39 . V_186 = F_10 ;
F_58 ( V_2 , & V_39 . V_5 , & V_56 ) ;
V_56 >>= V_192 ;
V_39 . V_5 -= V_192 ;
F_2 ( V_4 , V_61 ,
F_20 ( V_63 ) | V_56 ) ;
break;
default:
return;
}
F_17 ( V_2 -> V_59 ) = V_56 ;
F_16 () ;
F_12 ( & V_2 -> V_50 , V_44 ) ;
memcpy ( & V_2 -> V_6 , & V_39 , sizeof( V_2 -> V_6 ) ) ;
F_13 ( & V_2 -> V_50 , V_44 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
unsigned long V_44 ;
F_54 ( V_2 , & V_2 -> V_125 ) ;
if ( V_4 -> V_46 . type == V_163 )
return;
F_59 ( V_2 ) ;
F_12 ( & V_2 -> V_50 , V_44 ) ;
F_28 ( & V_2 -> V_28 , & V_2 -> V_6 ,
F_63 ( F_64 () ) ) ;
F_13 ( & V_2 -> V_50 , V_44 ) ;
V_2 -> V_81 = V_83 ;
if ( V_2 -> V_70 )
V_2 -> V_70 ( V_2 ) ;
}
static long F_65 ( struct V_1 * V_2 )
{
struct V_193 * V_194 = V_2 -> V_194 ;
long V_171 ;
if ( ! F_66 ( V_2 -> V_79 ) )
return 0 ;
switch ( V_2 -> V_4 . V_46 . type ) {
case V_60 :
snprintf ( V_2 -> V_54 . V_195 ,
sizeof( V_2 -> V_54 . V_195 ) ,
L_5 , V_194 -> V_195 ) ;
V_2 -> V_54 . V_196 = V_197 ;
V_2 -> V_54 . V_198 = 250000000 ;
V_2 -> V_54 . V_199 = 0 ;
V_2 -> V_54 . V_200 = 0 ;
V_2 -> V_54 . V_201 = 0 ;
V_2 -> V_54 . V_202 = 1 ;
V_2 -> V_54 . V_203 = F_15 ;
V_2 -> V_54 . V_204 = F_22 ;
V_2 -> V_54 . V_205 = F_24 ;
V_2 -> V_54 . V_206 = F_27 ;
V_2 -> V_54 . V_207 = F_29 ;
V_2 -> V_70 = F_1 ;
break;
case V_62 :
snprintf ( V_2 -> V_54 . V_195 ,
sizeof( V_2 -> V_54 . V_195 ) ,
L_5 , V_194 -> V_195 ) ;
V_2 -> V_54 . V_196 = V_197 ;
V_2 -> V_54 . V_198 = 250000000 ;
V_2 -> V_54 . V_199 = 0 ;
V_2 -> V_54 . V_200 = 0 ;
V_2 -> V_54 . V_201 = 0 ;
V_2 -> V_54 . V_202 = 0 ;
V_2 -> V_54 . V_203 = F_15 ;
V_2 -> V_54 . V_204 = F_22 ;
V_2 -> V_54 . V_205 = F_24 ;
V_2 -> V_54 . V_206 = F_27 ;
V_2 -> V_54 . V_207 = F_29 ;
break;
case V_47 :
case V_48 :
case V_49 :
snprintf ( V_2 -> V_54 . V_195 , 16 , L_5 , V_194 -> V_195 ) ;
V_2 -> V_54 . V_196 = V_197 ;
V_2 -> V_54 . V_198 = 30000000 ;
V_2 -> V_54 . V_199 = 0 ;
V_2 -> V_54 . V_200 = 0 ;
V_2 -> V_54 . V_201 = 0 ;
V_2 -> V_54 . V_202 = 0 ;
V_2 -> V_54 . V_203 = F_21 ;
V_2 -> V_54 . V_204 = F_22 ;
V_2 -> V_54 . V_205 = F_24 ;
V_2 -> V_54 . V_206 = F_27 ;
V_2 -> V_54 . V_207 = F_29 ;
V_2 -> V_70 = NULL ;
break;
default:
V_2 -> V_79 = NULL ;
V_2 -> V_70 = NULL ;
return - V_208 ;
}
V_2 -> V_79 = F_67 ( & V_2 -> V_54 ,
& V_2 -> V_209 -> V_210 ) ;
if ( F_68 ( V_2 -> V_79 ) ) {
V_171 = F_69 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
F_70 ( L_6 ) ;
return V_171 ;
} else if ( V_2 -> V_79 )
F_71 ( L_7 , V_194 -> V_195 ) ;
V_2 -> V_125 . V_140 = V_141 ;
V_2 -> V_125 . V_136 = V_137 ;
return 0 ;
}
void F_72 ( struct V_1 * V_2 )
{
F_73 ( & V_2 -> V_50 ) ;
if ( F_65 ( V_2 ) )
return;
F_74 ( & V_2 -> V_104 , F_44 ) ;
F_62 ( V_2 ) ;
F_75 ( V_211 , & V_2 -> V_101 ) ;
return;
}
void F_76 ( struct V_1 * V_2 )
{
if ( ! F_77 ( V_211 , & V_2 -> V_101 ) )
return;
V_2 -> V_17 &= ~ V_18 ;
if ( V_2 -> V_70 )
V_2 -> V_70 ( V_2 ) ;
F_41 ( & V_2 -> V_104 ) ;
F_36 ( V_2 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
F_76 ( V_2 ) ;
if ( V_2 -> V_79 ) {
F_79 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
F_71 ( L_8 ,
V_2 -> V_194 -> V_195 ) ;
}
}
