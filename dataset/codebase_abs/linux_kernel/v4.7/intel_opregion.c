static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * F_1 = V_7 -> V_10 . F_1 ;
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
if ( ( V_7 -> V_10 . V_22 &
( 1 << V_12 ) ) == 0 )
return - V_23 ;
} else if ( V_11 == V_24 ) {
if ( ( V_7 -> V_10 . V_25 &
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
F_4 ( V_2 -> V_29 , V_30 , & V_14 ) ;
if ( ! ( V_14 & V_31 ) || ( V_14 & V_32 ) ) {
V_14 |= V_31 ;
V_14 &= ~ V_32 ;
F_5 ( V_2 -> V_29 , V_30 , V_14 ) ;
}
V_14 |= V_32 ;
F_5 ( V_2 -> V_29 , V_30 , V_14 ) ;
#define F_6 (((scic = swsci->scic) & SWSCI_SCIC_INDICATOR) == 0)
if ( F_7 ( F_6 , V_15 ) ) {
F_3 ( L_4 ) ;
return - V_33 ;
}
V_13 = ( V_13 & V_34 ) >>
V_35 ;
if ( V_13 != V_36 ) {
F_3 ( L_5 , V_13 ) ;
return - V_37 ;
}
if ( V_5 )
* V_5 = F_1 -> V_4 ;
return 0 ;
#undef F_6
}
int F_8 ( struct V_38 * V_38 ,
bool V_39 )
{
struct V_1 * V_2 = V_38 -> V_40 . V_2 ;
T_1 V_4 = 0 ;
T_1 type = 0 ;
T_1 V_41 ;
if ( ! F_9 ( V_2 ) )
return 0 ;
if ( V_38 -> type == V_42 )
V_41 = 0 ;
else
V_41 = F_10 ( V_38 ) ;
if ( V_41 == V_43 ) {
V_41 = 0 ;
} else {
V_4 |= 1 << V_41 ;
V_41 ++ ;
}
if ( ! V_39 )
V_4 |= 4 << 8 ;
switch ( V_38 -> type ) {
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
F_11 ( 1 , L_6 ,
V_38 -> type ) ;
return - V_23 ;
}
V_4 |= type << ( 16 + V_41 * 3 ) ;
return F_1 ( V_2 , V_53 , V_4 , NULL ) ;
}
int F_12 ( struct V_1 * V_2 , T_3 V_54 )
{
int V_55 ;
if ( ! F_9 ( V_2 ) )
return 0 ;
for ( V_55 = 0 ; V_55 < F_13 ( V_56 ) ; V_55 ++ ) {
if ( V_54 == V_56 [ V_55 ] . V_57 )
return F_1 ( V_2 , V_58 ,
V_56 [ V_55 ] . V_4 , NULL ) ;
}
return - V_23 ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_1 V_59 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_60 * V_61 ;
struct V_62 * V_63 = V_7 -> V_10 . V_63 ;
F_3 ( L_7 , V_59 ) ;
if ( F_15 () == V_64 ) {
F_16 ( L_8 ) ;
return 0 ;
}
if ( ! ( V_59 & V_65 ) )
return V_66 ;
V_59 &= V_67 ;
if ( V_59 > 255 )
return V_66 ;
F_17 ( & V_2 -> V_68 . V_69 , NULL ) ;
F_16 ( L_9 , V_59 ) ;
F_18 (dev, connector)
F_19 ( V_61 , V_59 , 255 ) ;
V_63 -> V_70 = F_20 ( V_59 * 100 , 255 ) | V_71 ;
F_21 ( & V_2 -> V_68 . V_69 ) ;
return 0 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_1 V_72 )
{
F_3 ( L_10 ) ;
return V_73 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_1 V_74 )
{
F_3 ( L_11 ) ;
return V_75 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_76 )
{
F_3 ( L_12 ) ;
return V_77 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_1 V_78 )
{
F_3 ( L_13 ) ;
return V_79 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_1 V_80 )
{
if ( ! V_80 )
F_3 ( L_14 ) ;
if ( V_80 & V_81 )
F_3 ( L_15 ) ;
if ( V_80 & V_82 )
F_3 ( L_16 ) ;
if ( V_80 & V_83 )
F_3 ( L_17 ) ;
if ( V_80 & V_84 )
F_3 ( L_18 ) ;
if ( V_80 & V_85 )
F_3 ( L_19 ) ;
return V_86 ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_1 V_80 )
{
if ( V_80 & V_87 )
F_3 ( L_20 ) ;
else
F_3 ( L_21 ) ;
return V_88 ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_1 V_80 )
{
if ( V_80 & V_89 )
F_3 ( L_22 ) ;
else
F_3 ( L_23 ) ;
return V_90 ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
F_3 ( L_24 ) ;
return V_91 ;
}
static void F_30 ( struct V_92 * V_93 )
{
struct V_94 * V_10 =
F_31 ( V_93 , struct V_94 , F_30 ) ;
struct V_6 * V_7 =
F_31 ( V_10 , struct V_6 , V_10 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_62 * V_63 = V_7 -> V_10 . V_63 ;
T_1 V_95 = 0 ;
T_1 V_96 ;
if ( ! V_63 )
return;
V_96 = V_63 -> V_97 ;
if ( ! ( V_96 & V_98 ) ) {
F_3 ( L_25 ,
V_96 ) ;
return;
}
if ( V_96 & V_99 )
V_95 |= F_22 ( V_2 , V_63 -> V_72 ) ;
if ( V_96 & V_100 )
V_95 |= F_14 ( V_2 , V_63 -> V_59 ) ;
if ( V_96 & V_101 )
V_95 |= F_24 ( V_2 , V_63 -> V_76 ) ;
if ( V_96 & V_102 )
V_95 |= F_23 ( V_2 , V_63 -> V_74 ) ;
if ( V_96 & V_103 )
V_95 |= F_25 ( V_2 ,
V_63 -> V_78 ) ;
if ( V_96 & V_104 )
V_95 |= F_26 ( V_2 , V_63 -> V_80 ) ;
if ( V_96 & V_105 )
V_95 |= F_27 ( V_2 , V_63 -> V_80 ) ;
if ( V_96 & V_106 )
V_95 |= F_28 ( V_2 , V_63 -> V_80 ) ;
if ( V_96 & V_107 )
V_95 |= F_29 ( V_2 ) ;
V_63 -> V_97 = V_95 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( V_7 -> V_10 . V_63 )
F_33 ( & V_7 -> V_10 . F_30 ) ;
}
static int F_34 ( struct V_108 * V_109 ,
unsigned long V_110 , void * V_111 )
{
struct V_112 * V_113 = V_111 ;
struct V_114 * V_115 ;
int V_116 = V_117 ;
if ( strcmp ( V_113 -> V_118 , V_119 ) != 0 )
return V_120 ;
if ( ! V_121 )
return V_120 ;
V_115 = V_121 -> V_115 ;
if ( V_113 -> type == 0x80 && ( ( V_115 -> V_122 & 1 ) == 0 ) )
V_116 = V_123 ;
V_115 -> V_124 = 0 ;
return V_116 ;
}
static T_1 F_35 ( struct V_94 * V_10 , int V_55 )
{
T_1 V_125 ;
if ( V_55 < F_13 ( V_10 -> V_115 -> V_126 ) ) {
V_125 = V_10 -> V_115 -> V_126 [ V_55 ] ;
} else {
V_55 -= F_13 ( V_10 -> V_115 -> V_126 ) ;
if ( F_36 ( V_55 >= F_13 ( V_10 -> V_115 -> V_127 ) ) )
return 0 ;
V_125 = V_10 -> V_115 -> V_127 [ V_55 ] ;
}
return V_125 ;
}
static void F_37 ( struct V_94 * V_10 , int V_55 , T_1 V_110 )
{
if ( V_55 < F_13 ( V_10 -> V_115 -> V_126 ) ) {
V_10 -> V_115 -> V_126 [ V_55 ] = V_110 ;
} else {
V_55 -= F_13 ( V_10 -> V_115 -> V_126 ) ;
if ( F_36 ( V_55 >= F_13 ( V_10 -> V_115 -> V_127 ) ) )
return;
V_10 -> V_115 -> V_127 [ V_55 ] = V_110 ;
}
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_94 * V_10 = & V_7 -> V_10 ;
struct V_128 * V_61 ;
T_4 V_129 ;
struct V_130 * V_131 , * V_132 , * V_133 = NULL ;
unsigned long long V_134 ;
T_5 V_135 ;
T_1 V_136 , V_137 ;
int V_55 = 0 ;
V_129 = F_39 ( & V_2 -> V_29 -> V_2 ) ;
if ( ! V_129 || F_40 ( V_129 , & V_131 ) )
return;
if ( F_41 ( V_129 ) )
V_133 = V_131 ;
else {
F_42 (acpi_cdev, &acpi_dev->children, node) {
if ( F_41 ( V_132 -> V_129 ) ) {
V_133 = V_132 ;
break;
}
}
}
if ( ! V_133 ) {
F_16 ( L_26 ) ;
return;
}
V_137 = F_13 ( V_10 -> V_115 -> V_126 ) +
F_13 ( V_10 -> V_115 -> V_127 ) ;
F_42 (acpi_cdev, &acpi_video_bus->children, node) {
if ( V_55 >= V_137 ) {
F_16 ( L_27 ,
V_137 ) ;
return;
}
V_135 = F_43 ( V_132 -> V_129 , L_28 ,
NULL , & V_134 ) ;
if ( F_44 ( V_135 ) ) {
if ( ! V_134 )
goto V_138;
F_37 ( V_10 , V_55 ++ , ( T_1 ) ( V_134 & 0x0f0f ) ) ;
}
}
V_139:
F_16 ( L_29 , V_55 ) ;
if ( V_55 < V_137 )
F_37 ( V_10 , V_55 , 0 ) ;
return;
V_138:
V_55 = 0 ;
F_42 (connector, &dev->mode_config.connector_list, head) {
int V_140 = V_141 ;
if ( V_55 >= V_137 ) {
F_16 ( L_30 ,
V_137 ) ;
return;
}
switch ( V_61 -> V_142 ) {
case V_143 :
case V_144 :
V_140 = V_145 ;
break;
case V_146 :
case V_147 :
case V_148 :
case V_149 :
V_140 = V_150 ;
break;
case V_151 :
case V_152 :
case V_153 :
case V_154 :
case V_155 :
V_140 = V_156 ;
break;
case V_157 :
V_140 = V_158 ;
break;
}
V_136 = F_35 ( V_10 , V_55 ) ;
F_37 ( V_10 , V_55 , V_136 | ( 1 << 31 ) | V_140 | V_55 ) ;
V_55 ++ ;
}
goto V_139;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_94 * V_10 = & V_7 -> V_10 ;
int V_55 = 0 ;
T_1 V_159 ;
do {
V_159 = F_35 ( V_10 , V_55 ) ;
V_10 -> V_115 -> V_160 [ V_55 ] = V_159 ;
} while ( ++ V_55 < 8 && V_159 != 0 );
}
void F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_94 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_161 )
return;
if ( V_10 -> V_115 ) {
F_38 ( V_2 ) ;
F_45 ( V_2 ) ;
V_10 -> V_115 -> V_124 = 0 ;
V_10 -> V_115 -> V_162 = 1 ;
V_121 = V_10 ;
F_47 ( & V_163 ) ;
}
if ( V_10 -> V_63 ) {
V_10 -> V_63 -> V_164 = V_165 ;
V_10 -> V_63 -> V_166 = V_167 ;
}
}
void F_48 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_94 * V_10 = & V_7 -> V_10 ;
if ( ! V_10 -> V_161 )
return;
if ( V_10 -> V_63 )
V_10 -> V_63 -> V_166 = V_168 ;
F_49 ( & V_7 -> V_10 . F_30 ) ;
if ( V_10 -> V_115 ) {
V_10 -> V_115 -> V_162 = 0 ;
V_121 = NULL ;
F_50 ( & V_163 ) ;
}
F_51 ( V_10 -> V_161 ) ;
if ( V_10 -> V_169 ) {
F_51 ( V_10 -> V_169 ) ;
V_10 -> V_169 = NULL ;
}
V_10 -> V_161 = NULL ;
V_10 -> V_115 = NULL ;
V_10 -> F_1 = NULL ;
V_10 -> V_63 = NULL ;
V_10 -> V_170 = NULL ;
V_10 -> V_171 = NULL ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_94 * V_10 = & V_7 -> V_10 ;
bool V_172 = false ;
T_1 V_173 ;
V_10 -> V_25 = 1 ;
V_10 -> V_22 = 1 ;
if ( F_1 ( V_2 , V_174 , 0 , & V_173 ) == 0 ) {
V_173 <<= 1 ;
V_10 -> V_25 |= V_173 ;
}
if ( F_1 ( V_2 , V_175 , 0 , & V_173 ) == 0 ) {
V_10 -> V_22 |= V_173 ;
V_172 = true ;
}
if ( F_1 ( V_2 , V_176 , 0 , & V_173 ) == 0 ) {
T_1 V_177 = V_173 & 0x7ff ;
T_1 V_178 = V_173 & ~ 0xfff ;
V_173 = ( V_178 << 4 ) | ( V_177 << 1 ) | 1 ;
if ( V_172 ) {
T_1 V_179 = V_10 -> V_22 ;
if ( ( V_179 & V_173 ) != V_179 )
F_3 ( L_31 , V_179 , V_173 ) ;
} else {
V_10 -> V_22 |= V_173 ;
}
}
F_3 ( L_32 ,
V_10 -> V_25 ,
V_10 -> V_22 ) ;
}
static int F_53 ( const struct V_180 * V_181 )
{
F_16 ( L_33
L_34 , V_181 -> V_182 ) ;
return 1 ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_94 * V_10 = & V_7 -> V_10 ;
T_1 V_183 , V_184 ;
char V_185 [ sizeof( V_186 ) ] ;
int V_187 = 0 ;
void * V_40 ;
F_55 ( sizeof( struct V_188 ) != 0x100 ) ;
F_55 ( sizeof( struct V_114 ) != 0x100 ) ;
F_55 ( sizeof( struct V_9 ) != 0x100 ) ;
F_55 ( sizeof( struct V_62 ) != 0x100 ) ;
F_55 ( sizeof( struct V_189 ) != 0x400 ) ;
F_56 ( V_2 -> V_29 , V_190 , & V_183 ) ;
F_3 ( L_35 , V_183 ) ;
if ( V_183 == 0 ) {
F_3 ( L_36 ) ;
return - V_191 ;
}
F_57 ( & V_10 -> F_30 , F_30 ) ;
V_40 = F_58 ( V_183 , V_192 , V_193 ) ;
if ( ! V_40 )
return - V_194 ;
memcpy ( V_185 , V_40 , sizeof( V_185 ) ) ;
if ( memcmp ( V_185 , V_186 , 16 ) ) {
F_3 ( L_37 ) ;
V_187 = - V_23 ;
goto V_195;
}
V_10 -> V_161 = V_40 ;
V_10 -> V_171 = V_40 + V_196 ;
V_184 = V_10 -> V_161 -> V_184 ;
if ( V_184 & V_197 ) {
F_3 ( L_38 ) ;
V_10 -> V_115 = V_40 + V_198 ;
}
if ( V_184 & V_199 ) {
F_3 ( L_39 ) ;
V_10 -> F_1 = V_40 + V_200 ;
F_52 ( V_2 ) ;
}
if ( V_184 & V_201 ) {
F_3 ( L_40 ) ;
V_10 -> V_63 = V_40 + V_202 ;
V_10 -> V_63 -> V_166 = V_168 ;
}
if ( V_184 & V_203 )
F_3 ( L_41 ) ;
if ( ! F_59 ( V_204 ) ) {
const void * V_170 = NULL ;
T_1 V_205 = 0 ;
if ( V_10 -> V_161 -> V_206 >= 2 && V_10 -> V_63 &&
V_10 -> V_63 -> V_169 && V_10 -> V_63 -> V_207 ) {
V_10 -> V_169 = F_58 ( V_10 -> V_63 -> V_169 ,
V_10 -> V_63 -> V_207 ,
V_193 ) ;
V_170 = V_10 -> V_169 ;
V_205 = V_10 -> V_63 -> V_207 ;
}
if ( F_60 ( V_170 , V_205 ) ) {
F_16 ( L_42 ) ;
V_10 -> V_170 = V_170 ;
V_10 -> V_205 = V_205 ;
} else {
V_170 = V_40 + V_208 ;
V_205 = V_209 - V_208 ;
if ( F_60 ( V_170 , V_205 ) ) {
F_16 ( L_43 ) ;
V_10 -> V_170 = V_170 ;
V_10 -> V_205 = V_205 ;
}
}
}
return 0 ;
V_195:
F_51 ( V_40 ) ;
return V_187 ;
}
int
F_61 ( struct V_1 * V_2 )
{
T_1 V_210 ;
int V_116 ;
V_116 = F_1 ( V_2 , V_211 , 0x0 , & V_210 ) ;
if ( V_116 ) {
F_16 ( L_44 ,
V_116 ) ;
return V_116 ;
}
V_116 = ( V_210 >> 8 ) & 0xff ;
if ( V_116 > 0x10 ) {
F_16 ( L_45 , V_116 ) ;
return - V_23 ;
}
if ( V_116 == 0x0 ) {
F_16 ( L_46 ) ;
return - V_16 ;
}
if ( F_62 ( V_2 ) ) {
F_16 ( L_47 , V_116 - 1 ) ;
return - V_16 ;
}
return V_116 - 1 ;
}
