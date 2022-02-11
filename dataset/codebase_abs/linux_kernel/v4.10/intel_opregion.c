static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
struct V_6 * F_1 = V_2 -> V_7 . F_1 ;
struct V_8 * V_9 = V_2 -> V_10 . V_9 ;
T_1 V_11 , V_12 , V_13 ;
T_2 V_14 ;
T_1 V_15 ;
if ( ! F_1 )
return - V_16 ;
V_11 = ( V_3 & V_17 ) >>
V_18 ;
V_12 = ( V_3 & V_19 ) >>
V_20 ;
if ( V_11 == V_21 ) {
if ( ( V_2 -> V_7 . V_22 &
( 1 << V_12 ) ) == 0 )
return - V_23 ;
} else if ( V_11 == V_24 ) {
if ( ( V_2 -> V_7 . V_25 &
( 1 << V_12 ) ) == 0 )
return - V_23 ;
}
V_15 = F_1 -> V_15 ;
if ( ! V_15 ) {
V_15 = 50 ;
} else if ( V_15 > V_26 ) {
F_2 ( L_1
L_2 , V_15 , V_26 ) ;
V_15 = V_26 ;
}
V_13 = F_1 -> V_13 ;
if ( V_13 & V_27 ) {
F_3 ( L_3 ) ;
return - V_28 ;
}
V_13 = V_3 | V_27 ;
F_1 -> V_4 = V_4 ;
F_1 -> V_13 = V_13 ;
F_4 ( V_9 , V_29 , & V_14 ) ;
if ( ! ( V_14 & V_30 ) || ( V_14 & V_31 ) ) {
V_14 |= V_30 ;
V_14 &= ~ V_31 ;
F_5 ( V_9 , V_29 , V_14 ) ;
}
V_14 |= V_31 ;
F_5 ( V_9 , V_29 , V_14 ) ;
#define F_6 (((scic = swsci->scic) & SWSCI_SCIC_INDICATOR) == 0)
if ( F_7 ( F_6 , V_15 ) ) {
F_3 ( L_4 ) ;
return - V_32 ;
}
V_13 = ( V_13 & V_33 ) >>
V_34 ;
if ( V_13 != V_35 ) {
F_3 ( L_5 , V_13 ) ;
return - V_36 ;
}
if ( V_5 )
* V_5 = F_1 -> V_4 ;
return 0 ;
#undef F_6
}
int F_8 ( struct V_37 * V_37 ,
bool V_38 )
{
struct V_1 * V_2 = F_9 ( V_37 -> V_39 . V_40 ) ;
T_1 V_4 = 0 ;
T_1 type = 0 ;
T_1 V_41 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
if ( V_37 -> type == V_42 )
V_41 = 0 ;
else
V_41 = F_11 ( V_37 ) ;
if ( V_41 == V_43 ) {
V_41 = 0 ;
} else {
V_4 |= 1 << V_41 ;
V_41 ++ ;
}
if ( ! V_38 )
V_4 |= 4 << 8 ;
switch ( V_37 -> type ) {
case V_44 :
type = V_45 ;
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
type = V_50 ;
break;
case V_51 :
case V_42 :
type = V_52 ;
break;
default:
F_12 ( 1 , L_6 ,
V_37 -> type ) ;
return - V_23 ;
}
V_4 |= type << ( 16 + V_41 * 3 ) ;
return F_1 ( V_2 , V_53 , V_4 , NULL ) ;
}
int F_13 ( struct V_1 * V_2 ,
T_3 V_54 )
{
int V_55 ;
if ( ! F_10 ( V_2 ) )
return 0 ;
for ( V_55 = 0 ; V_55 < F_14 ( V_56 ) ; V_55 ++ ) {
if ( V_54 == V_56 [ V_55 ] . V_57 )
return F_1 ( V_2 , V_58 ,
V_56 [ V_55 ] . V_4 , NULL ) ;
}
return - V_23 ;
}
static T_1 F_15 ( struct V_1 * V_2 , T_1 V_59 )
{
struct V_60 * V_61 ;
struct V_62 * V_63 = V_2 -> V_7 . V_63 ;
struct V_64 * V_40 = & V_2 -> V_10 ;
F_3 ( L_7 , V_59 ) ;
if ( F_16 () == V_65 ) {
F_17 ( L_8 ) ;
return 0 ;
}
if ( ! ( V_59 & V_66 ) )
return V_67 ;
V_59 &= V_68 ;
if ( V_59 > 255 )
return V_67 ;
F_18 ( & V_40 -> V_69 . V_70 , NULL ) ;
F_17 ( L_9 , V_59 ) ;
F_19 (dev, connector)
F_20 ( V_61 , V_59 , 255 ) ;
V_63 -> V_71 = F_21 ( V_59 * 100 , 255 ) | V_72 ;
F_22 ( & V_40 -> V_69 . V_70 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_1 V_73 )
{
F_3 ( L_10 ) ;
return V_74 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_75 )
{
F_3 ( L_11 ) ;
return V_76 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_1 V_77 )
{
F_3 ( L_12 ) ;
return V_78 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_1 V_79 )
{
F_3 ( L_13 ) ;
return V_80 ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_1 V_81 )
{
if ( ! V_81 )
F_3 ( L_14 ) ;
if ( V_81 & V_82 )
F_3 ( L_15 ) ;
if ( V_81 & V_83 )
F_3 ( L_16 ) ;
if ( V_81 & V_84 )
F_3 ( L_17 ) ;
if ( V_81 & V_85 )
F_3 ( L_18 ) ;
if ( V_81 & V_86 )
F_3 ( L_19 ) ;
return V_87 ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_1 V_81 )
{
if ( V_81 & V_88 )
F_3 ( L_20 ) ;
else
F_3 ( L_21 ) ;
return V_89 ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_1 V_81 )
{
if ( V_81 & V_90 )
F_3 ( L_22 ) ;
else
F_3 ( L_23 ) ;
return V_91 ;
}
static T_1 F_30 ( struct V_1 * V_2 )
{
F_3 ( L_24 ) ;
return V_92 ;
}
static void F_31 ( struct V_93 * V_94 )
{
struct V_95 * V_7 =
F_32 ( V_94 , struct V_95 , F_31 ) ;
struct V_1 * V_2 =
F_32 ( V_7 , struct V_1 , V_7 ) ;
struct V_62 * V_63 = V_2 -> V_7 . V_63 ;
T_1 V_96 = 0 ;
T_1 V_97 ;
if ( ! V_63 )
return;
V_97 = V_63 -> V_98 ;
if ( ! ( V_97 & V_99 ) ) {
F_3 ( L_25 ,
V_97 ) ;
return;
}
if ( V_97 & V_100 )
V_96 |= F_23 ( V_2 , V_63 -> V_73 ) ;
if ( V_97 & V_101 )
V_96 |= F_15 ( V_2 , V_63 -> V_59 ) ;
if ( V_97 & V_102 )
V_96 |= F_25 ( V_2 , V_63 -> V_77 ) ;
if ( V_97 & V_103 )
V_96 |= F_24 ( V_2 , V_63 -> V_75 ) ;
if ( V_97 & V_104 )
V_96 |= F_26 ( V_2 ,
V_63 -> V_79 ) ;
if ( V_97 & V_105 )
V_96 |= F_27 ( V_2 , V_63 -> V_81 ) ;
if ( V_97 & V_106 )
V_96 |= F_28 ( V_2 , V_63 -> V_81 ) ;
if ( V_97 & V_107 )
V_96 |= F_29 ( V_2 , V_63 -> V_81 ) ;
if ( V_97 & V_108 )
V_96 |= F_30 ( V_2 ) ;
V_63 -> V_98 = V_96 ;
}
void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 . V_63 )
F_34 ( & V_2 -> V_7 . F_31 ) ;
}
static int F_35 ( struct V_109 * V_110 ,
unsigned long V_111 , void * V_112 )
{
struct V_113 * V_114 = V_112 ;
struct V_115 * V_116 ;
int V_117 = V_118 ;
if ( strcmp ( V_114 -> V_119 , V_120 ) != 0 )
return V_121 ;
if ( ! V_122 )
return V_121 ;
V_116 = V_122 -> V_116 ;
if ( V_114 -> type == 0x80 && ( ( V_116 -> V_123 & 1 ) == 0 ) )
V_117 = V_124 ;
V_116 -> V_125 = 0 ;
return V_117 ;
}
static void F_36 ( struct V_95 * V_7 , int V_55 , T_1 V_111 )
{
if ( V_55 < F_14 ( V_7 -> V_116 -> V_126 ) ) {
V_7 -> V_116 -> V_126 [ V_55 ] = V_111 ;
} else {
V_55 -= F_14 ( V_7 -> V_116 -> V_126 ) ;
if ( F_37 ( V_55 >= F_14 ( V_7 -> V_116 -> V_127 ) ) )
return;
V_7 -> V_116 -> V_127 [ V_55 ] = V_111 ;
}
}
static T_1 F_38 ( struct V_60 * V_61 )
{
T_1 V_128 ;
switch ( V_61 -> V_39 . V_129 ) {
case V_130 :
case V_131 :
V_128 = V_132 ;
break;
case V_133 :
case V_134 :
case V_135 :
case V_136 :
case V_137 :
V_128 = V_138 ;
break;
case V_139 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
V_128 = V_144 ;
break;
case V_145 :
case V_146 :
case V_147 :
V_128 = V_148 ;
break;
case V_149 :
case V_150 :
V_128 = V_151 ;
break;
default:
F_39 ( V_61 -> V_39 . V_129 ) ;
V_128 = V_151 ;
break;
}
return V_128 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
struct V_60 * V_61 ;
int V_55 = 0 , V_152 ;
int V_153 [ 16 ] = {} ;
V_152 = F_14 ( V_7 -> V_116 -> V_126 ) +
F_14 ( V_7 -> V_116 -> V_127 ) ;
F_19 (&dev_priv->drm, connector) {
T_1 V_154 , type ;
V_154 = F_38 ( V_61 ) ;
type = ( V_154 & V_155 )
>> V_156 ;
V_154 |= V_153 [ type ] ++ << V_157 ;
V_61 -> V_158 = V_154 ;
if ( V_55 < V_152 )
F_36 ( V_7 , V_55 , V_154 ) ;
V_55 ++ ;
}
F_17 ( L_26 , V_55 ) ;
if ( V_55 > V_152 )
F_41 ( L_27 ,
V_152 ) ;
if ( V_55 < V_152 )
F_36 ( V_7 , V_55 , 0 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
struct V_60 * V_61 ;
int V_55 = 0 ;
F_19 (&dev_priv->drm, connector) {
if ( V_55 >= F_14 ( V_7 -> V_116 -> V_159 ) )
break;
V_7 -> V_116 -> V_159 [ V_55 ++ ] = V_61 -> V_158 ;
}
if ( V_55 < F_14 ( V_7 -> V_116 -> V_159 ) )
V_7 -> V_116 -> V_159 [ V_55 ] = 0 ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
if ( ! V_7 -> V_160 )
return;
if ( V_7 -> V_116 ) {
F_40 ( V_2 ) ;
F_42 ( V_2 ) ;
V_7 -> V_116 -> V_125 = 0 ;
V_7 -> V_116 -> V_161 = 1 ;
V_122 = V_7 ;
F_44 ( & V_162 ) ;
}
if ( V_7 -> V_63 ) {
V_7 -> V_63 -> V_163 = V_164 ;
V_7 -> V_63 -> V_165 = V_166 ;
}
}
void F_45 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
if ( ! V_7 -> V_160 )
return;
if ( V_7 -> V_63 )
V_7 -> V_63 -> V_165 = V_167 ;
F_46 ( & V_2 -> V_7 . F_31 ) ;
if ( V_7 -> V_116 ) {
V_7 -> V_116 -> V_161 = 0 ;
V_122 = NULL ;
F_47 ( & V_162 ) ;
}
F_48 ( V_7 -> V_160 ) ;
if ( V_7 -> V_168 ) {
F_48 ( V_7 -> V_168 ) ;
V_7 -> V_168 = NULL ;
}
V_7 -> V_160 = NULL ;
V_7 -> V_116 = NULL ;
V_7 -> F_1 = NULL ;
V_7 -> V_63 = NULL ;
V_7 -> V_169 = NULL ;
V_7 -> V_170 = NULL ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
bool V_171 = false ;
T_1 V_172 ;
V_7 -> V_25 = 1 ;
V_7 -> V_22 = 1 ;
if ( F_1 ( V_2 , V_173 , 0 , & V_172 ) == 0 ) {
V_172 <<= 1 ;
V_7 -> V_25 |= V_172 ;
}
if ( F_1 ( V_2 , V_174 , 0 , & V_172 ) == 0 ) {
V_7 -> V_22 |= V_172 ;
V_171 = true ;
}
if ( F_1 ( V_2 , V_175 , 0 , & V_172 ) == 0 ) {
T_1 V_176 = V_172 & 0x7ff ;
T_1 V_177 = V_172 & ~ 0xfff ;
V_172 = ( V_177 << 4 ) | ( V_176 << 1 ) | 1 ;
if ( V_171 ) {
T_1 V_178 = V_7 -> V_22 ;
if ( ( V_178 & V_172 ) != V_178 )
F_3 ( L_28 , V_178 , V_172 ) ;
} else {
V_7 -> V_22 |= V_172 ;
}
}
F_3 ( L_29 ,
V_7 -> V_25 ,
V_7 -> V_22 ) ;
}
static int F_50 ( const struct V_179 * V_180 )
{
F_17 ( L_30
L_31 , V_180 -> V_181 ) ;
return 1 ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 . V_9 ;
T_1 V_182 , V_183 ;
char V_184 [ sizeof( V_185 ) ] ;
int V_186 = 0 ;
void * V_39 ;
F_52 ( sizeof( struct V_187 ) != 0x100 ) ;
F_52 ( sizeof( struct V_115 ) != 0x100 ) ;
F_52 ( sizeof( struct V_6 ) != 0x100 ) ;
F_52 ( sizeof( struct V_62 ) != 0x100 ) ;
F_52 ( sizeof( struct V_188 ) != 0x400 ) ;
F_53 ( V_9 , V_189 , & V_182 ) ;
F_3 ( L_32 , V_182 ) ;
if ( V_182 == 0 ) {
F_3 ( L_33 ) ;
return - V_190 ;
}
F_54 ( & V_7 -> F_31 , F_31 ) ;
V_39 = F_55 ( V_182 , V_191 , V_192 ) ;
if ( ! V_39 )
return - V_193 ;
memcpy ( V_184 , V_39 , sizeof( V_184 ) ) ;
if ( memcmp ( V_184 , V_185 , 16 ) ) {
F_3 ( L_34 ) ;
V_186 = - V_23 ;
goto V_194;
}
V_7 -> V_160 = V_39 ;
V_7 -> V_170 = V_39 + V_195 ;
V_183 = V_7 -> V_160 -> V_183 ;
if ( V_183 & V_196 ) {
F_3 ( L_35 ) ;
V_7 -> V_116 = V_39 + V_197 ;
}
if ( V_183 & V_198 ) {
F_3 ( L_36 ) ;
V_7 -> F_1 = V_39 + V_199 ;
F_49 ( V_2 ) ;
}
if ( V_183 & V_200 ) {
F_3 ( L_37 ) ;
V_7 -> V_63 = V_39 + V_201 ;
V_7 -> V_63 -> V_165 = V_167 ;
}
if ( V_183 & V_202 )
F_3 ( L_38 ) ;
if ( ! F_56 ( V_203 ) ) {
const void * V_169 = NULL ;
T_1 V_204 = 0 ;
if ( V_7 -> V_160 -> V_205 >= 2 && V_7 -> V_63 &&
V_7 -> V_63 -> V_168 && V_7 -> V_63 -> V_206 ) {
V_7 -> V_168 = F_55 ( V_7 -> V_63 -> V_168 ,
V_7 -> V_63 -> V_206 ,
V_192 ) ;
V_169 = V_7 -> V_168 ;
V_204 = V_7 -> V_63 -> V_206 ;
}
if ( F_57 ( V_169 , V_204 ) ) {
F_17 ( L_39 ) ;
V_7 -> V_169 = V_169 ;
V_7 -> V_204 = V_204 ;
} else {
V_169 = V_39 + V_207 ;
V_204 = V_208 - V_207 ;
if ( F_57 ( V_169 , V_204 ) ) {
F_17 ( L_40 ) ;
V_7 -> V_169 = V_169 ;
V_7 -> V_204 = V_204 ;
}
}
}
return 0 ;
V_194:
F_48 ( V_39 ) ;
return V_186 ;
}
static int F_58 ( const struct V_179 * V_180 )
{
F_59 ( L_41 , V_180 -> V_181 ) ;
return 1 ;
}
int
F_60 ( struct V_1 * V_2 )
{
T_1 V_209 ;
int V_117 ;
V_117 = F_1 ( V_2 , V_210 , 0x0 , & V_209 ) ;
if ( V_117 ) {
F_17 ( L_42 ,
V_117 ) ;
return V_117 ;
}
V_117 = ( V_209 >> 8 ) & 0xff ;
if ( V_117 > 0x10 ) {
F_17 ( L_43 , V_117 ) ;
return - V_23 ;
}
if ( V_117 == 0x0 ) {
F_17 ( L_44 ) ;
return - V_16 ;
}
if ( ! F_56 ( V_211 ) ) {
F_17 ( L_45 , V_117 - 1 ) ;
return - V_16 ;
}
if ( F_61 ( V_2 ) ) {
F_17 ( L_45 , V_117 - 1 ) ;
return - V_16 ;
}
return V_117 - 1 ;
}
