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
struct V_62 V_63 ;
struct V_64 * V_65 = V_2 -> V_7 . V_65 ;
struct V_66 * V_40 = & V_2 -> V_10 ;
F_3 ( L_7 , V_59 ) ;
if ( F_16 () == V_67 ) {
F_17 ( L_8 ) ;
return 0 ;
}
if ( ! ( V_59 & V_68 ) )
return V_69 ;
V_59 &= V_70 ;
if ( V_59 > 255 )
return V_69 ;
F_18 ( & V_40 -> V_71 . V_72 , NULL ) ;
F_17 ( L_9 , V_59 ) ;
F_19 ( V_40 , & V_63 ) ;
F_20 (connector, &conn_iter)
F_21 ( V_61 , V_59 , 255 ) ;
F_22 ( & V_63 ) ;
V_65 -> V_73 = F_23 ( V_59 * 100 , 255 ) | V_74 ;
F_24 ( & V_40 -> V_71 . V_72 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_1 V_75 )
{
F_3 ( L_10 ) ;
return V_76 ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_1 V_77 )
{
F_3 ( L_11 ) ;
return V_78 ;
}
static T_1 F_27 ( struct V_1 * V_2 , T_1 V_79 )
{
F_3 ( L_12 ) ;
return V_80 ;
}
static T_1 F_28 ( struct V_1 * V_2 , T_1 V_81 )
{
F_3 ( L_13 ) ;
return V_82 ;
}
static T_1 F_29 ( struct V_1 * V_2 , T_1 V_83 )
{
if ( ! V_83 )
F_3 ( L_14 ) ;
if ( V_83 & V_84 )
F_3 ( L_15 ) ;
if ( V_83 & V_85 )
F_3 ( L_16 ) ;
if ( V_83 & V_86 )
F_3 ( L_17 ) ;
if ( V_83 & V_87 )
F_3 ( L_18 ) ;
if ( V_83 & V_88 )
F_3 ( L_19 ) ;
return V_89 ;
}
static T_1 F_30 ( struct V_1 * V_2 , T_1 V_83 )
{
if ( V_83 & V_90 )
F_3 ( L_20 ) ;
else
F_3 ( L_21 ) ;
return V_91 ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_1 V_83 )
{
if ( V_83 & V_92 )
F_3 ( L_22 ) ;
else
F_3 ( L_23 ) ;
return V_93 ;
}
static T_1 F_32 ( struct V_1 * V_2 )
{
F_3 ( L_24 ) ;
return V_94 ;
}
static void F_33 ( struct V_95 * V_96 )
{
struct V_97 * V_7 =
F_34 ( V_96 , struct V_97 , F_33 ) ;
struct V_1 * V_2 =
F_34 ( V_7 , struct V_1 , V_7 ) ;
struct V_64 * V_65 = V_2 -> V_7 . V_65 ;
T_1 V_98 = 0 ;
T_1 V_99 ;
if ( ! V_65 )
return;
V_99 = V_65 -> V_100 ;
if ( ! ( V_99 & V_101 ) ) {
F_3 ( L_25 ,
V_99 ) ;
return;
}
if ( V_99 & V_102 )
V_98 |= F_25 ( V_2 , V_65 -> V_75 ) ;
if ( V_99 & V_103 )
V_98 |= F_15 ( V_2 , V_65 -> V_59 ) ;
if ( V_99 & V_104 )
V_98 |= F_27 ( V_2 , V_65 -> V_79 ) ;
if ( V_99 & V_105 )
V_98 |= F_26 ( V_2 , V_65 -> V_77 ) ;
if ( V_99 & V_106 )
V_98 |= F_28 ( V_2 ,
V_65 -> V_81 ) ;
if ( V_99 & V_107 )
V_98 |= F_29 ( V_2 , V_65 -> V_83 ) ;
if ( V_99 & V_108 )
V_98 |= F_30 ( V_2 , V_65 -> V_83 ) ;
if ( V_99 & V_109 )
V_98 |= F_31 ( V_2 , V_65 -> V_83 ) ;
if ( V_99 & V_110 )
V_98 |= F_32 ( V_2 ) ;
V_65 -> V_100 = V_98 ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 . V_65 )
F_36 ( & V_2 -> V_7 . F_33 ) ;
}
static int F_37 ( struct V_111 * V_112 ,
unsigned long V_113 , void * V_114 )
{
struct V_115 * V_116 = V_114 ;
struct V_117 * V_118 ;
int V_119 = V_120 ;
if ( strcmp ( V_116 -> V_121 , V_122 ) != 0 )
return V_123 ;
if ( ! V_124 )
return V_123 ;
V_118 = V_124 -> V_118 ;
if ( V_116 -> type == 0x80 && ( ( V_118 -> V_125 & 1 ) == 0 ) )
V_119 = V_126 ;
V_118 -> V_127 = 0 ;
return V_119 ;
}
static void F_38 ( struct V_97 * V_7 , int V_55 , T_1 V_113 )
{
if ( V_55 < F_14 ( V_7 -> V_118 -> V_128 ) ) {
V_7 -> V_118 -> V_128 [ V_55 ] = V_113 ;
} else {
V_55 -= F_14 ( V_7 -> V_118 -> V_128 ) ;
if ( F_39 ( V_55 >= F_14 ( V_7 -> V_118 -> V_129 ) ) )
return;
V_7 -> V_118 -> V_129 [ V_55 ] = V_113 ;
}
}
static T_1 F_40 ( struct V_60 * V_61 )
{
T_1 V_130 ;
switch ( V_61 -> V_39 . V_131 ) {
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
F_41 ( V_61 -> V_39 . V_131 ) ;
V_130 = V_153 ;
break;
}
return V_130 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_97 * V_7 = & V_2 -> V_7 ;
struct V_60 * V_61 ;
struct V_62 V_63 ;
int V_55 = 0 , V_154 ;
int V_155 [ 16 ] = {} ;
V_154 = F_14 ( V_7 -> V_118 -> V_128 ) +
F_14 ( V_7 -> V_118 -> V_129 ) ;
F_19 ( & V_2 -> V_10 , & V_63 ) ;
F_20 (connector, &conn_iter) {
T_1 V_156 , type ;
V_156 = F_40 ( V_61 ) ;
type = ( V_156 & V_157 )
>> V_158 ;
V_156 |= V_155 [ type ] ++ << V_159 ;
V_61 -> V_160 = V_156 ;
if ( V_55 < V_154 )
F_38 ( V_7 , V_55 , V_156 ) ;
V_55 ++ ;
}
F_22 ( & V_63 ) ;
F_17 ( L_26 , V_55 ) ;
if ( V_55 > V_154 )
F_43 ( L_27 ,
V_154 ) ;
if ( V_55 < V_154 )
F_38 ( V_7 , V_55 , 0 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_97 * V_7 = & V_2 -> V_7 ;
struct V_60 * V_61 ;
struct V_62 V_63 ;
int V_55 = 0 ;
F_19 ( & V_2 -> V_10 , & V_63 ) ;
F_20 (connector, &conn_iter) {
if ( V_55 >= F_14 ( V_7 -> V_118 -> V_161 ) )
break;
V_7 -> V_118 -> V_161 [ V_55 ++ ] = V_61 -> V_160 ;
}
F_22 ( & V_63 ) ;
if ( V_55 < F_14 ( V_7 -> V_118 -> V_161 ) )
V_7 -> V_118 -> V_161 [ V_55 ] = 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_97 * V_7 = & V_2 -> V_7 ;
if ( ! V_7 -> V_162 )
return;
if ( V_7 -> V_118 ) {
F_42 ( V_2 ) ;
F_44 ( V_2 ) ;
V_7 -> V_118 -> V_127 = 0 ;
V_7 -> V_118 -> V_163 = 1 ;
V_124 = V_7 ;
F_46 ( & V_164 ) ;
}
if ( V_7 -> V_65 ) {
V_7 -> V_65 -> V_165 = V_166 ;
V_7 -> V_65 -> V_167 = V_168 ;
}
}
void F_47 ( struct V_1 * V_2 )
{
struct V_97 * V_7 = & V_2 -> V_7 ;
if ( ! V_7 -> V_162 )
return;
if ( V_7 -> V_65 )
V_7 -> V_65 -> V_167 = V_169 ;
F_48 ( & V_2 -> V_7 . F_33 ) ;
if ( V_7 -> V_118 ) {
V_7 -> V_118 -> V_163 = 0 ;
V_124 = NULL ;
F_49 ( & V_164 ) ;
}
F_50 ( V_7 -> V_162 ) ;
if ( V_7 -> V_170 ) {
F_50 ( V_7 -> V_170 ) ;
V_7 -> V_170 = NULL ;
}
V_7 -> V_162 = NULL ;
V_7 -> V_118 = NULL ;
V_7 -> F_1 = NULL ;
V_7 -> V_65 = NULL ;
V_7 -> V_171 = NULL ;
V_7 -> V_172 = NULL ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_97 * V_7 = & V_2 -> V_7 ;
bool V_173 = false ;
T_1 V_174 ;
V_7 -> V_25 = 1 ;
V_7 -> V_22 = 1 ;
if ( F_1 ( V_2 , V_175 , 0 , & V_174 ) == 0 ) {
V_174 <<= 1 ;
V_7 -> V_25 |= V_174 ;
}
if ( F_1 ( V_2 , V_176 , 0 , & V_174 ) == 0 ) {
V_7 -> V_22 |= V_174 ;
V_173 = true ;
}
if ( F_1 ( V_2 , V_177 , 0 , & V_174 ) == 0 ) {
T_1 V_178 = V_174 & 0x7ff ;
T_1 V_179 = V_174 & ~ 0xfff ;
V_174 = ( V_179 << 4 ) | ( V_178 << 1 ) | 1 ;
if ( V_173 ) {
T_1 V_180 = V_7 -> V_22 ;
if ( ( V_180 & V_174 ) != V_180 )
F_3 ( L_28 , V_180 , V_174 ) ;
} else {
V_7 -> V_22 |= V_174 ;
}
}
F_3 ( L_29 ,
V_7 -> V_25 ,
V_7 -> V_22 ) ;
}
static int F_52 ( const struct V_181 * V_182 )
{
F_17 ( L_30
L_31 , V_182 -> V_183 ) ;
return 1 ;
}
int F_53 ( struct V_1 * V_2 )
{
struct V_97 * V_7 = & V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 . V_9 ;
T_1 V_184 , V_185 ;
char V_186 [ sizeof( V_187 ) ] ;
int V_188 = 0 ;
void * V_39 ;
const void * V_171 ;
T_1 V_189 ;
F_54 ( sizeof( struct V_190 ) != 0x100 ) ;
F_54 ( sizeof( struct V_117 ) != 0x100 ) ;
F_54 ( sizeof( struct V_6 ) != 0x100 ) ;
F_54 ( sizeof( struct V_64 ) != 0x100 ) ;
F_54 ( sizeof( struct V_191 ) != 0x400 ) ;
F_55 ( V_9 , V_192 , & V_184 ) ;
F_3 ( L_32 , V_184 ) ;
if ( V_184 == 0 ) {
F_3 ( L_33 ) ;
return - V_193 ;
}
F_56 ( & V_7 -> F_33 , F_33 ) ;
V_39 = F_57 ( V_184 , V_194 , V_195 ) ;
if ( ! V_39 )
return - V_196 ;
memcpy ( V_186 , V_39 , sizeof( V_186 ) ) ;
if ( memcmp ( V_186 , V_187 , 16 ) ) {
F_3 ( L_34 ) ;
V_188 = - V_23 ;
goto V_197;
}
V_7 -> V_162 = V_39 ;
V_7 -> V_172 = V_39 + V_198 ;
V_185 = V_7 -> V_162 -> V_185 ;
if ( V_185 & V_199 ) {
F_3 ( L_35 ) ;
V_7 -> V_118 = V_39 + V_200 ;
}
if ( V_185 & V_201 ) {
F_3 ( L_36 ) ;
V_7 -> F_1 = V_39 + V_202 ;
F_51 ( V_2 ) ;
}
if ( V_185 & V_203 ) {
F_3 ( L_37 ) ;
V_7 -> V_65 = V_39 + V_204 ;
V_7 -> V_65 -> V_167 = V_169 ;
}
if ( V_185 & V_205 )
F_3 ( L_38 ) ;
if ( F_58 ( V_206 ) )
goto V_207;
if ( V_7 -> V_162 -> V_208 >= 2 && V_7 -> V_65 &&
V_7 -> V_65 -> V_170 && V_7 -> V_65 -> V_209 ) {
V_7 -> V_170 = F_57 ( V_7 -> V_65 -> V_170 ,
V_7 -> V_65 -> V_209 ,
V_195 ) ;
V_171 = V_7 -> V_170 ;
V_189 = V_7 -> V_65 -> V_209 ;
if ( F_59 ( V_171 , V_189 ) ) {
F_17 ( L_39 ) ;
V_7 -> V_171 = V_171 ;
V_7 -> V_189 = V_189 ;
goto V_207;
} else {
F_17 ( L_40 ) ;
}
}
V_171 = V_39 + V_210 ;
V_189 = ( V_185 & V_205 ) ?
V_211 : V_194 ;
V_189 -= V_210 ;
if ( F_59 ( V_171 , V_189 ) ) {
F_17 ( L_41 ) ;
V_7 -> V_171 = V_171 ;
V_7 -> V_189 = V_189 ;
} else {
F_17 ( L_42 ) ;
}
V_207:
return 0 ;
V_197:
F_50 ( V_39 ) ;
return V_188 ;
}
static int F_60 ( const struct V_181 * V_182 )
{
F_61 ( L_43 , V_182 -> V_183 ) ;
return 1 ;
}
int
F_62 ( struct V_1 * V_2 )
{
T_1 V_212 ;
int V_119 ;
V_119 = F_1 ( V_2 , V_213 , 0x0 , & V_212 ) ;
if ( V_119 ) {
F_17 ( L_44 ,
V_119 ) ;
return V_119 ;
}
V_119 = ( V_212 >> 8 ) & 0xff ;
if ( V_119 > 0x10 ) {
F_17 ( L_45 , V_119 ) ;
return - V_23 ;
}
if ( V_119 == 0x0 ) {
F_17 ( L_46 ) ;
return - V_16 ;
}
if ( ! F_58 ( V_214 ) ) {
F_17 ( L_47 , V_119 - 1 ) ;
return - V_16 ;
}
return V_119 - 1 ;
}
