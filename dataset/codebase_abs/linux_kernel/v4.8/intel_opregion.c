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
static T_1 F_36 ( struct V_95 * V_7 , int V_55 )
{
T_1 V_126 ;
if ( V_55 < F_14 ( V_7 -> V_116 -> V_127 ) ) {
V_126 = V_7 -> V_116 -> V_127 [ V_55 ] ;
} else {
V_55 -= F_14 ( V_7 -> V_116 -> V_127 ) ;
if ( F_37 ( V_55 >= F_14 ( V_7 -> V_116 -> V_128 ) ) )
return 0 ;
V_126 = V_7 -> V_116 -> V_128 [ V_55 ] ;
}
return V_126 ;
}
static void F_38 ( struct V_95 * V_7 , int V_55 , T_1 V_111 )
{
if ( V_55 < F_14 ( V_7 -> V_116 -> V_127 ) ) {
V_7 -> V_116 -> V_127 [ V_55 ] = V_111 ;
} else {
V_55 -= F_14 ( V_7 -> V_116 -> V_127 ) ;
if ( F_37 ( V_55 >= F_14 ( V_7 -> V_116 -> V_128 ) ) )
return;
V_7 -> V_116 -> V_128 [ V_55 ] = V_111 ;
}
}
static T_1 F_39 ( struct V_129 * V_61 )
{
T_1 V_130 ;
switch ( V_61 -> V_131 ) {
case V_132 :
case V_133 :
V_130 = V_134 ;
break;
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
V_130 = V_140 ;
break;
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
V_130 = V_146 ;
break;
case V_147 :
case V_148 :
case V_149 :
V_130 = V_150 ;
break;
case V_151 :
case V_152 :
V_130 = V_153 ;
break;
default:
F_40 ( V_61 -> V_131 ) ;
V_130 = V_153 ;
break;
}
return V_130 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 . V_9 ;
struct V_129 * V_61 ;
T_4 V_154 ;
struct V_155 * V_156 , * V_157 , * V_158 = NULL ;
unsigned long long V_159 ;
T_5 V_160 ;
T_1 V_161 , V_162 ;
int V_55 = 0 ;
V_154 = F_42 ( & V_9 -> V_40 ) ;
if ( ! V_154 || F_43 ( V_154 , & V_156 ) )
return;
if ( F_44 ( V_154 ) )
V_158 = V_156 ;
else {
F_45 (acpi_cdev, &acpi_dev->children, node) {
if ( F_44 ( V_157 -> V_154 ) ) {
V_158 = V_157 ;
break;
}
}
}
if ( ! V_158 ) {
F_17 ( L_26 ) ;
return;
}
V_162 = F_14 ( V_7 -> V_116 -> V_127 ) +
F_14 ( V_7 -> V_116 -> V_128 ) ;
F_45 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_55 >= V_162 ) {
F_17 ( L_27 ,
V_162 ) ;
return;
}
V_160 = F_46 ( V_157 -> V_154 , L_28 ,
NULL , & V_159 ) ;
if ( F_47 ( V_160 ) ) {
if ( ! V_159 )
goto V_163;
F_38 ( V_7 , V_55 ++ , ( T_1 ) ( V_159 & 0x0f0f ) ) ;
}
}
V_164:
F_17 ( L_29 , V_55 ) ;
if ( V_55 < V_162 )
F_38 ( V_7 , V_55 , 0 ) ;
return;
V_163:
V_55 = 0 ;
F_45 (connector,
&dev_priv->drm.mode_config.connector_list, head) {
int V_130 = F_39 ( V_61 ) ;
if ( V_55 >= V_162 ) {
F_17 ( L_30 ,
V_162 ) ;
return;
}
V_161 = F_36 ( V_7 , V_55 ) ;
F_38 ( V_7 , V_55 , V_161 | ( 1 << 31 ) | V_130 | V_55 ) ;
V_55 ++ ;
}
goto V_164;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
int V_55 = 0 ;
T_1 V_165 ;
do {
V_165 = F_36 ( V_7 , V_55 ) ;
V_7 -> V_116 -> V_166 [ V_55 ] = V_165 ;
} while ( ++ V_55 < 8 && V_165 != 0 );
}
void F_49 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
if ( ! V_7 -> V_167 )
return;
if ( V_7 -> V_116 ) {
F_41 ( V_2 ) ;
F_48 ( V_2 ) ;
V_7 -> V_116 -> V_125 = 0 ;
V_7 -> V_116 -> V_168 = 1 ;
V_122 = V_7 ;
F_50 ( & V_169 ) ;
}
if ( V_7 -> V_63 ) {
V_7 -> V_63 -> V_170 = V_171 ;
V_7 -> V_63 -> V_172 = V_173 ;
}
}
void F_51 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
if ( ! V_7 -> V_167 )
return;
if ( V_7 -> V_63 )
V_7 -> V_63 -> V_172 = V_174 ;
F_52 ( & V_2 -> V_7 . F_31 ) ;
if ( V_7 -> V_116 ) {
V_7 -> V_116 -> V_168 = 0 ;
V_122 = NULL ;
F_53 ( & V_169 ) ;
}
F_54 ( V_7 -> V_167 ) ;
if ( V_7 -> V_175 ) {
F_54 ( V_7 -> V_175 ) ;
V_7 -> V_175 = NULL ;
}
V_7 -> V_167 = NULL ;
V_7 -> V_116 = NULL ;
V_7 -> F_1 = NULL ;
V_7 -> V_63 = NULL ;
V_7 -> V_176 = NULL ;
V_7 -> V_177 = NULL ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
bool V_178 = false ;
T_1 V_179 ;
V_7 -> V_25 = 1 ;
V_7 -> V_22 = 1 ;
if ( F_1 ( V_2 , V_180 , 0 , & V_179 ) == 0 ) {
V_179 <<= 1 ;
V_7 -> V_25 |= V_179 ;
}
if ( F_1 ( V_2 , V_181 , 0 , & V_179 ) == 0 ) {
V_7 -> V_22 |= V_179 ;
V_178 = true ;
}
if ( F_1 ( V_2 , V_182 , 0 , & V_179 ) == 0 ) {
T_1 V_183 = V_179 & 0x7ff ;
T_1 V_184 = V_179 & ~ 0xfff ;
V_179 = ( V_184 << 4 ) | ( V_183 << 1 ) | 1 ;
if ( V_178 ) {
T_1 V_185 = V_7 -> V_22 ;
if ( ( V_185 & V_179 ) != V_185 )
F_3 ( L_31 , V_185 , V_179 ) ;
} else {
V_7 -> V_22 |= V_179 ;
}
}
F_3 ( L_32 ,
V_7 -> V_25 ,
V_7 -> V_22 ) ;
}
static int F_56 ( const struct V_186 * V_187 )
{
F_17 ( L_33
L_34 , V_187 -> V_188 ) ;
return 1 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 . V_9 ;
T_1 V_189 , V_190 ;
char V_191 [ sizeof( V_192 ) ] ;
int V_193 = 0 ;
void * V_39 ;
F_58 ( sizeof( struct V_194 ) != 0x100 ) ;
F_58 ( sizeof( struct V_115 ) != 0x100 ) ;
F_58 ( sizeof( struct V_6 ) != 0x100 ) ;
F_58 ( sizeof( struct V_62 ) != 0x100 ) ;
F_58 ( sizeof( struct V_195 ) != 0x400 ) ;
F_59 ( V_9 , V_196 , & V_189 ) ;
F_3 ( L_35 , V_189 ) ;
if ( V_189 == 0 ) {
F_3 ( L_36 ) ;
return - V_197 ;
}
F_60 ( & V_7 -> F_31 , F_31 ) ;
V_39 = F_61 ( V_189 , V_198 , V_199 ) ;
if ( ! V_39 )
return - V_200 ;
memcpy ( V_191 , V_39 , sizeof( V_191 ) ) ;
if ( memcmp ( V_191 , V_192 , 16 ) ) {
F_3 ( L_37 ) ;
V_193 = - V_23 ;
goto V_201;
}
V_7 -> V_167 = V_39 ;
V_7 -> V_177 = V_39 + V_202 ;
V_190 = V_7 -> V_167 -> V_190 ;
if ( V_190 & V_203 ) {
F_3 ( L_38 ) ;
V_7 -> V_116 = V_39 + V_204 ;
}
if ( V_190 & V_205 ) {
F_3 ( L_39 ) ;
V_7 -> F_1 = V_39 + V_206 ;
F_55 ( V_2 ) ;
}
if ( V_190 & V_207 ) {
F_3 ( L_40 ) ;
V_7 -> V_63 = V_39 + V_208 ;
V_7 -> V_63 -> V_172 = V_174 ;
}
if ( V_190 & V_209 )
F_3 ( L_41 ) ;
if ( ! F_62 ( V_210 ) ) {
const void * V_176 = NULL ;
T_1 V_211 = 0 ;
if ( V_7 -> V_167 -> V_212 >= 2 && V_7 -> V_63 &&
V_7 -> V_63 -> V_175 && V_7 -> V_63 -> V_213 ) {
V_7 -> V_175 = F_61 ( V_7 -> V_63 -> V_175 ,
V_7 -> V_63 -> V_213 ,
V_199 ) ;
V_176 = V_7 -> V_175 ;
V_211 = V_7 -> V_63 -> V_213 ;
}
if ( F_63 ( V_176 , V_211 ) ) {
F_17 ( L_42 ) ;
V_7 -> V_176 = V_176 ;
V_7 -> V_211 = V_211 ;
} else {
V_176 = V_39 + V_214 ;
V_211 = V_215 - V_214 ;
if ( F_63 ( V_176 , V_211 ) ) {
F_17 ( L_43 ) ;
V_7 -> V_176 = V_176 ;
V_7 -> V_211 = V_211 ;
}
}
}
return 0 ;
V_201:
F_54 ( V_39 ) ;
return V_193 ;
}
static int F_64 ( const struct V_186 * V_187 )
{
F_65 ( L_44 , V_187 -> V_188 ) ;
return 1 ;
}
int
F_66 ( struct V_1 * V_2 )
{
T_1 V_216 ;
int V_117 ;
V_117 = F_1 ( V_2 , V_217 , 0x0 , & V_216 ) ;
if ( V_117 ) {
F_17 ( L_45 ,
V_117 ) ;
return V_117 ;
}
V_117 = ( V_216 >> 8 ) & 0xff ;
if ( V_117 > 0x10 ) {
F_17 ( L_46 , V_117 ) ;
return - V_23 ;
}
if ( V_117 == 0x0 ) {
F_17 ( L_47 ) ;
return - V_16 ;
}
if ( ! F_62 ( V_218 ) ) {
F_17 ( L_48 , V_117 - 1 ) ;
return - V_16 ;
}
if ( F_67 ( V_2 ) ) {
F_17 ( L_48 , V_117 - 1 ) ;
return - V_16 ;
}
return V_117 - 1 ;
}
