int F_1 ( void * V_1 , int V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_1 ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 = 0 ;
if ( V_8 -> V_10 != V_11 && V_8 -> V_10 != V_12 )
return 0 ;
if ( V_3 != V_13 && V_3 != V_14 )
return 0 ;
V_9 = F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
return V_9 ;
}
static inline void F_3 ( struct V_7 * V_8 )
{
V_8 -> V_15 = V_17 [ V_8 -> V_18 ] ;
if ( ! V_8 -> V_15 . V_19 )
V_8 -> V_15 . V_19 = V_20 |
V_21 ;
if ( ! V_8 -> V_15 . V_22 )
V_8 -> V_15 . V_22 = V_23 |
V_24 ;
V_8 -> V_25 = V_8 -> V_15 . V_25 ;
}
static void F_4 ( struct V_7 * V_8 )
{
F_5 ( V_8 , V_26 , V_8 -> V_15 . V_19 & 0x7f ) ;
if ( ! V_8 -> V_15 . V_27 )
F_5 ( V_8 , V_28 , V_8 -> V_15 . V_22 ) ;
F_6 ( 50 ) ;
switch ( V_8 -> V_18 ) {
case V_29 :
V_8 -> V_30 = 2048000 ;
break;
case V_31 :
case V_32 :
F_5 ( V_8 , V_33 , 0x6d ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0x7d ) ;
F_6 ( 10 ) ;
break;
case V_34 :
F_5 ( V_8 , V_35 , 0x00 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_35 , 0x01 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0xfd ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfc ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xdc ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfc ) ;
F_7 ( 70 ) ;
break;
case V_36 :
F_5 ( V_8 , V_33 , 0xfe ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xde ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfe ) ;
F_7 ( 70 ) ;
break;
case V_37 :
F_5 ( V_8 , V_33 , 0xfe ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xde ) ;
F_7 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfe ) ;
F_7 ( 70 ) ;
break;
case V_38 :
case V_39 :
F_5 ( V_8 , V_33 , 0xfd ) ;
break;
case V_40 :
F_5 ( V_8 , V_33 , 0xff ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0xfe ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_35 , 0x00 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_35 , 0x08 ) ;
F_6 ( 10 ) ;
break;
case V_41 :
F_8 ( V_8 , V_26 , L_1 , 1 ) ;
F_8 ( V_8 , V_28 , L_2 , 1 ) ;
F_8 ( V_8 , 0x0d , L_3 , 1 ) ;
F_8 ( V_8 , 0x08 , L_4 , 1 ) ;
F_6 ( 10 ) ;
F_8 ( V_8 , 0x08 , L_5 , 1 ) ;
F_6 ( 10 ) ;
F_8 ( V_8 , 0x08 , L_6 , 1 ) ;
F_6 ( 10 ) ;
F_8 ( V_8 , 0x08 , L_7 , 1 ) ;
break;
case V_42 :
F_8 ( V_8 , 0x08 , L_8 , 1 ) ;
break;
case V_43 :
F_5 ( V_8 , V_33 , 0xff ) ;
F_6 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xf7 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0xfe ) ;
F_6 ( 70 ) ;
F_5 ( V_8 , V_33 , 0xfd ) ;
F_6 ( 70 ) ;
break;
}
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_9 ( V_8 , V_44 ) ;
F_9 ( V_8 , V_45 ) ;
}
static void F_10 ( struct V_7 * V_8 , struct V_46 * V_47 )
{
memset ( V_47 , 0 , sizeof( * V_47 ) ) ;
V_47 -> V_48 = V_49 ;
V_47 -> V_50 = 64 ;
V_47 -> V_51 = V_17 [ V_8 -> V_18 ] . V_52 ;
switch ( V_8 -> V_18 ) {
case V_53 :
case V_54 :
case V_55 :
V_47 -> V_56 = V_57 ;
break;
case V_58 :
case V_59 :
case V_60 :
V_47 -> V_56 = V_57 ;
break;
case V_61 :
case V_62 :
V_47 -> V_56 = V_63 ;
break;
case V_64 :
V_47 -> V_56 = V_63 ;
V_47 -> V_48 = V_65 ;
break;
case V_66 :
case V_67 :
case V_68 :
V_47 -> V_56 = V_63 ;
break;
case V_69 :
case V_70 :
case V_71 :
V_47 -> V_56 = V_72 ;
V_47 -> V_48 = V_49 ;
break;
case V_73 :
V_47 -> V_56 = V_72 ;
V_47 -> V_48 = V_65 ;
break;
default:
V_47 -> V_56 = V_74 ;
}
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_75 V_76 ;
struct V_77 V_78 ;
if ( V_8 -> V_10 == V_79 )
return;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_80 = V_81 | V_82 ;
V_76 . V_83 = F_1 ;
if ( V_8 -> V_15 . V_84 . type ) {
V_76 . type = V_8 -> V_15 . V_84 . type ;
V_76 . V_85 = V_8 -> V_15 . V_86 ;
F_12 ( & V_8 -> V_87 , 0 , V_88 , V_89 , & V_76 ) ;
}
if ( ( V_8 -> V_10 != V_79 ) && ( V_8 -> V_10 ) ) {
V_76 . type = V_8 -> V_10 ;
V_76 . V_85 = V_8 -> V_90 ;
F_12 ( & V_8 -> V_87 , 0 , V_88 , V_89 , & V_76 ) ;
}
if ( V_8 -> V_91 ) {
struct V_92 V_93 ;
V_93 . V_88 = V_94 ;
V_93 . V_95 = & V_8 -> V_91 ;
F_12 ( & V_8 -> V_87 , 0 , V_88 , V_96 , & V_93 ) ;
}
if ( V_8 -> V_10 == V_11 ) {
struct V_92 V_97 ;
struct V_46 V_47 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
F_10 ( V_8 , & V_47 ) ;
V_97 . V_88 = V_11 ;
V_97 . V_95 = & V_47 ;
F_12 ( & V_8 -> V_87 , 0 , V_88 , V_96 , & V_97 ) ;
}
V_78 . V_88 = 0 ;
V_78 . type = V_98 ;
V_78 . V_99 = 9076 ;
V_8 -> V_100 = V_78 . V_99 ;
F_12 ( & V_8 -> V_87 , 0 , V_88 , V_101 , & V_78 ) ;
}
static int F_13 ( struct V_7 * V_8 )
{
int V_102 ;
if ( V_8 -> V_15 . V_103 ) {
if ( V_8 -> V_104 == V_105 ) {
V_8 -> V_18 = V_106 ;
} else if ( V_8 -> V_104 == V_107 ||
V_8 -> V_104 == V_108 ) {
V_8 -> V_18 = V_109 ;
}
return 0 ;
}
for ( V_102 = 0 ; V_102 < F_14 ( V_110 ) ; V_102 ++ ) {
if ( V_8 -> V_111 == V_110 [ V_102 ] . V_111 ) {
V_8 -> V_18 = V_110 [ V_102 ] . V_18 ;
V_8 -> V_10 = V_110 [ V_102 ] . V_88 ;
F_15 ( L_9 ) ;
F_15 ( L_10
L_11 ) ;
F_15 ( L_12 ) ;
F_15 ( L_13
L_14 ) ;
F_15 ( L_15
L_16 ) ;
F_15 ( L_17 ,
V_17 [ V_8 -> V_18 ] . V_112 ) ;
return 0 ;
}
}
if ( ! V_8 -> V_113 )
F_16 ( V_8 , V_8 -> V_25 ) ;
for ( V_102 = 0 ; V_102 < F_14 ( V_114 ) ; V_102 ++ ) {
if ( V_8 -> V_113 == V_114 [ V_102 ] . V_111 ) {
V_8 -> V_18 = V_114 [ V_102 ] . V_18 ;
V_8 -> V_10 = V_114 [ V_102 ] . V_88 ;
F_15 ( L_9 ) ;
F_15 ( L_10
L_18 ) ;
F_15 ( L_12 ) ;
F_15 ( L_13
L_14 ) ;
F_15 ( L_15
L_16 ) ;
F_15 ( L_17 ,
V_17 [ V_8 -> V_18 ] . V_112 ) ;
return 0 ;
}
}
F_15 ( L_19
L_20 ) ;
F_15 ( L_21
L_22 ) ;
F_15 ( L_23 ) ;
F_15 ( L_24 ) ;
F_15 ( L_25 , V_8 -> V_111 ) ;
F_15 ( L_26 , V_8 -> V_113 ) ;
F_15 ( L_27
L_28 ) ;
for ( V_102 = 0 ; V_102 < V_115 ; V_102 ++ ) {
F_15 ( L_29 ,
V_102 , V_17 [ V_102 ] . V_112 ) ;
}
return - 1 ;
}
static void F_17 ( struct V_7 * V_8 )
{
if ( V_8 -> V_15 . V_103 ) {
if ( F_18 ( V_8 ) < 0 )
V_8 -> V_15 . V_103 = 0 ;
else
V_8 -> V_116 = 1 ;
}
switch ( V_8 -> V_18 ) {
case V_109 :
case V_117 :
case V_118 :
if ( F_13 ( V_8 ) < 0 )
F_15 ( L_30 ) ;
else {
F_3 ( V_8 ) ;
F_4 ( V_8 ) ;
}
break;
default:
F_3 ( V_8 ) ;
}
F_19 ( L_31 ,
V_8 -> V_15 . V_112 , V_8 -> V_18 ) ;
V_8 -> V_10 = V_17 [ V_8 -> V_18 ] . V_10 ;
if ( V_17 [ V_8 -> V_18 ] . V_90 )
V_8 -> V_90 = V_17 [ V_8 -> V_18 ] . V_90 ;
if ( V_17 [ V_8 -> V_18 ] . V_91 )
V_8 -> V_91 = V_17 [ V_8 -> V_18 ] . V_91 ;
switch ( V_8 -> V_18 ) {
case V_119 :
case V_54 :
case V_61 :
case V_66 :
case V_67 :
case V_120 :
{
struct V_121 V_122 ;
if ( V_8 -> V_123 == NULL )
break;
#if F_20 ( V_124 ) && F_20 ( V_125 )
F_21 ( L_32 ) ;
#endif
V_8 -> V_126 [ V_8 -> V_25 ] . V_85 = 0xa0 >> 1 ;
F_22 ( & V_8 -> V_126 [ V_8 -> V_25 ] , & V_122 , V_8 -> V_123 ) ;
V_8 -> V_10 = V_122 . V_10 ;
if ( V_122 . V_127 == V_128 ) {
V_8 -> V_30 = 2048000 ;
V_8 -> V_15 . V_129 = 1 ;
}
break;
}
case V_40 :
F_5 ( V_8 , 0x0d , 0x42 ) ;
F_6 ( 10 ) ;
F_5 ( V_8 , V_33 , 0xfd ) ;
F_6 ( 10 ) ;
break;
case V_130 :
F_5 ( V_8 , V_33 , 0xf9 ) ;
break;
case V_117 :
case V_118 :
case V_131 :
if ( ! F_13 ( V_8 ) )
F_3 ( V_8 ) ;
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_9 ( V_8 , V_44 ) ;
break;
case V_71 :
if ( ! F_13 ( V_8 ) )
F_3 ( V_8 ) ;
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_9 ( V_8 , V_44 ) ;
break;
}
if ( V_8 -> V_15 . V_132 == V_133 ) {
F_15 ( L_33 ) ;
F_15 ( L_34
L_35 ) ;
F_15 ( L_36 ) ;
F_15 ( L_37
L_38 ) ;
}
F_23 ( V_8 -> V_123 ) ;
V_8 -> V_123 = NULL ;
if ( V_88 >= 0 )
V_8 -> V_10 = V_88 ;
if ( V_8 -> V_15 . V_129 )
F_24 ( & V_8 -> V_87 , & V_8 -> V_134 [ V_8 -> V_25 ] ,
L_39 , 0 , V_135 ) ;
if ( V_8 -> V_15 . V_136 == V_137 )
F_24 ( & V_8 -> V_87 , & V_8 -> V_134 [ V_8 -> V_25 ] ,
L_40 , 0 , V_138 ) ;
if ( V_8 -> V_15 . V_136 == V_139 )
F_24 ( & V_8 -> V_87 , & V_8 -> V_134 [ V_8 -> V_25 ] ,
L_41 , 0 , V_140 ) ;
if ( V_8 -> V_15 . V_141 == V_142 )
F_24 ( & V_8 -> V_87 , & V_8 -> V_134 [ V_8 -> V_25 ] ,
L_42 , V_8 -> V_15 . V_143 , NULL ) ;
if ( V_8 -> V_15 . V_10 != V_79 ) {
int V_144 = ( V_8 -> V_91 & V_145 ) ;
if ( V_8 -> V_15 . V_84 . type )
F_24 ( & V_8 -> V_87 , & V_8 -> V_134 [ V_8 -> V_25 ] ,
L_43 , V_8 -> V_15 . V_86 , NULL ) ;
if ( V_144 )
F_24 ( & V_8 -> V_87 ,
& V_8 -> V_134 [ V_8 -> V_25 ] , L_43 ,
0 , F_25 ( V_146 ) ) ;
if ( V_8 -> V_90 == 0 ) {
enum V_147 type =
V_144 ? V_148 : V_149 ;
struct V_150 * V_151 ;
V_151 = F_24 ( & V_8 -> V_87 ,
& V_8 -> V_134 [ V_8 -> V_25 ] , L_43 ,
0 , F_25 ( type ) ) ;
if ( V_151 )
V_8 -> V_90 = F_26 ( V_151 ) ;
} else {
F_24 ( & V_8 -> V_87 , & V_8 -> V_134 [ V_8 -> V_25 ] ,
L_43 , V_8 -> V_90 , NULL ) ;
}
}
F_11 ( V_8 ) ;
F_27 ( V_8 ) ;
}
static void F_28 ( struct V_152 * V_153 )
{
struct V_7 * V_8 = F_29 ( V_153 ,
struct V_7 , V_154 ) ;
F_30 ( V_8 ) ;
#if F_20 ( V_124 ) && F_20 ( V_125 )
if ( V_8 -> V_155 )
F_21 ( L_44 ) ;
else if ( V_8 -> V_156 )
F_21 ( L_45 ) ;
if ( V_8 -> V_15 . V_157 )
F_21 ( L_46 ) ;
if ( V_8 -> V_15 . V_158 ||
( ( V_8 -> V_15 . V_159 || V_8 -> V_15 . V_160 ) && ! V_161 ) )
F_21 ( L_47 ) ;
#endif
}
static void F_31 ( struct V_7 * V_8 )
{
F_32 ( & V_8 -> V_154 , F_28 ) ;
F_33 ( & V_8 -> V_154 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
F_35 ( & V_8 -> V_154 ) ;
}
void F_36 ( struct V_7 * V_8 )
{
F_37 ( V_8 ) ;
if ( V_8 -> V_25 )
F_38 ( V_8 , 1 ) ;
F_38 ( V_8 , 0 ) ;
F_39 ( & V_8 -> V_162 ) ;
F_40 ( & V_8 -> V_87 ) ;
F_41 ( V_8 -> V_163 ) ;
F_42 ( V_8 -> V_164 , & V_165 ) ;
}
static int F_43 ( struct V_7 * V_8 , struct V_166 * V_163 ,
struct V_167 * V_168 ,
int V_169 )
{
struct V_170 * V_171 = & V_8 -> V_162 ;
int V_172 ;
static const char * V_173 = L_48 ;
const char * V_174 = V_173 ;
V_8 -> V_163 = V_163 ;
F_44 ( & V_8 -> V_175 ) ;
F_44 ( & V_8 -> V_176 ) ;
F_44 ( & V_8 -> V_177 ) ;
F_45 ( & V_8 -> V_178 ) ;
V_8 -> F_8 = F_8 ;
V_8 -> V_179 = V_179 ;
V_8 -> V_180 = V_180 ;
V_8 -> V_181 = V_181 ;
V_8 -> V_182 = V_182 ;
V_8 -> V_15 . V_27 = V_17 [ V_8 -> V_18 ] . V_27 ;
F_3 ( V_8 ) ;
V_8 -> V_183 = 5 ;
V_172 = V_179 ( V_8 , V_184 ) ;
if ( V_172 > 0 ) {
V_8 -> V_185 = V_172 ;
switch ( V_8 -> V_185 ) {
case V_186 :
V_174 = L_49 ;
break;
case V_187 :
V_174 = L_50 ;
break;
case V_188 :
V_174 = L_51 ;
break;
case V_189 :
V_174 = L_52 ;
V_8 -> V_183 = 0 ;
V_8 -> V_190 = 1 ;
V_8 -> V_191 = 1 ;
break;
case V_192 :
V_174 = L_53 ;
if ( F_46 ( V_8 -> V_163 -> V_193 . V_194 )
== 0xeb1a ) {
T_1 V_195 = V_8 -> V_163 -> V_193 . V_196 ;
if ( F_46 ( V_195 ) == 0x2710 )
V_174 = L_50 ;
else if ( F_46 ( V_195 ) == 0x2820 )
V_174 = L_54 ;
}
break;
case V_197 :
V_174 = L_55 ;
break;
case V_198 :
V_174 = L_56 ;
break;
case V_199 :
V_174 = L_57 ;
V_8 -> V_183 = 0 ;
break;
case V_200 :
V_174 = L_58 ;
V_8 -> V_183 = 0 ;
V_8 -> V_191 = 1 ;
break;
case V_201 :
V_174 = L_59 ;
V_8 -> V_183 = 0 ;
V_8 -> V_191 = 1 ;
break;
case V_202 :
V_174 = L_60 ;
V_8 -> V_183 = 0 ;
break;
case V_203 :
V_174 = L_61 ;
V_8 -> V_183 = 0 ;
V_8 -> V_191 = 1 ;
break;
default:
F_47 (KERN_INFO DRIVER_NAME
L_62 , dev->chip_id) ;
}
}
if ( V_174 != V_173 )
F_47 (KERN_INFO DRIVER_NAME
L_63 , chip_name) ;
snprintf ( V_8 -> V_112 , sizeof( V_8 -> V_112 ) , L_64 , V_174 , V_8 -> V_164 ) ;
if ( V_8 -> V_204 ) {
V_172 = F_48 ( V_8 ) ;
if ( V_172 )
return - V_205 ;
F_30 ( V_8 ) ;
return 0 ;
}
F_4 ( V_8 ) ;
if ( ! V_8 -> V_15 . V_27 ) {
V_172 = F_5 ( V_8 , V_28 , V_8 -> V_15 . V_22 ) ;
if ( V_172 < 0 ) {
F_15 ( L_65
L_66 ,
V_206 , V_172 ) ;
return V_172 ;
}
}
V_172 = F_49 ( & V_168 -> V_8 , & V_8 -> V_87 ) ;
if ( V_172 < 0 ) {
F_15 ( L_67 ) ;
return V_172 ;
}
F_50 ( V_171 , 8 ) ;
V_8 -> V_87 . V_162 = V_171 ;
F_51 ( & V_8 -> V_207 ) ;
if ( V_8 -> V_15 . V_27 )
V_172 = F_52 ( V_8 , 0 , V_208 ) ;
else
V_172 = F_52 ( V_8 , 0 , V_209 ) ;
if ( V_172 < 0 ) {
F_15 ( L_68 ,
V_206 , V_172 ) ;
goto V_210;
}
if ( V_8 -> V_25 ) {
if ( V_8 -> V_190 )
V_172 = F_52 ( V_8 , 1 ,
V_211 ) ;
else
V_172 = F_52 ( V_8 , 1 ,
V_209 ) ;
if ( V_172 < 0 ) {
F_15 ( L_69 ,
V_206 , V_172 ) ;
goto V_210;
}
}
V_8 -> V_212 = 0x10 ;
V_8 -> V_213 = V_214 |
V_215 ;
F_17 ( V_8 ) ;
V_172 = F_48 ( V_8 ) ;
if ( V_172 < 0 ) {
F_15 ( L_70 ,
V_206 , V_172 ) ;
goto V_216;
}
if ( V_8 -> V_217 . V_218 != V_219 ) {
F_53 ( V_171 , & V_220 ,
V_221 , 0 , 1 , 1 , 1 ) ;
F_53 ( V_171 , & V_220 ,
V_222 , 0 , 0x1f , 1 , 0x1f ) ;
} else {
F_54 ( F_55 ( V_171 , V_221 ) ,
V_223 , V_8 ) ;
F_54 ( F_55 ( V_171 , V_222 ) ,
V_223 , V_8 ) ;
}
F_56 ( V_8 ) ;
F_57 ( & V_8 -> V_224 . V_225 ) ;
F_57 ( & V_8 -> V_226 . V_225 ) ;
if ( V_8 -> V_15 . V_129 ) {
V_172 = F_5 ( V_8 , V_33 , 0xf7 ) ;
if ( V_172 < 0 ) {
F_15 ( L_71
L_72 ,
V_206 , V_172 ) ;
goto V_216;
}
F_6 ( 3 ) ;
V_172 = F_5 ( V_8 , V_33 , 0xff ) ;
if ( V_172 < 0 ) {
F_15 ( L_71
L_73 ,
V_206 , V_172 ) ;
goto V_216;
}
F_6 ( 3 ) ;
}
V_172 = F_58 ( V_8 ) ;
if ( V_172 < 0 ) {
goto V_216;
}
F_12 ( & V_8 -> V_87 , 0 , V_227 , V_228 , 0 ) ;
return 0 ;
V_216:
if ( V_8 -> V_25 )
F_38 ( V_8 , 1 ) ;
F_38 ( V_8 , 0 ) ;
F_39 ( & V_8 -> V_162 ) ;
V_210:
F_40 ( & V_8 -> V_87 ) ;
return V_172 ;
}
static int F_59 ( struct V_167 * V_168 ,
const struct V_229 * V_230 )
{
struct V_166 * V_163 ;
struct V_7 * V_8 = NULL ;
int V_172 ;
bool V_231 = false , V_232 = false , V_157 = false ;
int V_102 , V_233 , V_234 ;
const int V_235 = V_168 -> V_236 [ 0 ] . V_237 . V_238 ;
char * V_239 ;
V_163 = F_60 ( F_61 ( V_168 ) ) ;
do {
V_233 = F_62 ( & V_165 , V_240 ) ;
if ( V_233 >= V_240 ) {
F_47 ( V_241 L_74 ,
V_240 ) ;
V_172 = - V_242 ;
goto V_243;
}
} while ( F_63 ( V_233 , & V_165 ) );
if ( V_168 -> V_236 [ 0 ] . V_237 . V_244 == V_245 ) {
F_64 ( V_241 L_75
L_76 ,
F_46 ( V_163 -> V_193 . V_194 ) ,
F_46 ( V_163 -> V_193 . V_196 ) ,
V_235 ,
V_168 -> V_236 [ 0 ] . V_237 . V_244 ) ;
V_172 = - V_205 ;
goto V_246;
}
V_8 = F_65 ( sizeof( * V_8 ) , V_247 ) ;
if ( V_8 == NULL ) {
F_64 ( V_241 L_77 ) ;
V_172 = - V_242 ;
goto V_246;
}
V_8 -> V_248 =
F_66 ( sizeof( V_8 -> V_248 [ 0 ] ) *
V_168 -> V_249 , V_247 ) ;
if ( V_8 -> V_248 == NULL ) {
F_15 ( L_78 ) ;
F_23 ( V_8 ) ;
V_172 = - V_242 ;
goto V_246;
}
for ( V_102 = 0 ; V_102 < V_168 -> V_249 ; V_102 ++ ) {
int V_250 ;
for ( V_250 = 0 ; V_250 < V_168 -> V_236 [ V_102 ] . V_237 . V_251 ; V_250 ++ ) {
const struct V_252 * V_253 ;
int V_254 , V_255 ;
V_253 = & V_168 -> V_236 [ V_102 ] . V_256 [ V_250 ] . V_237 ;
V_254 = F_46 ( V_253 -> V_257 ) ;
V_255 = V_254 & 0x7ff ;
if ( V_163 -> V_239 == V_258 )
V_255 = V_255 * F_67 ( V_254 ) ;
if ( F_68 ( V_253 ) ) {
switch ( V_253 -> V_259 ) {
case 0x82 :
V_232 = true ;
if ( F_69 ( V_253 ) ) {
V_8 -> V_260 =
V_253 -> V_259 ;
V_8 -> V_248 [ V_102 ] = V_255 ;
} else if ( F_70 ( V_253 ) ) {
V_8 -> V_261 =
V_253 -> V_259 ;
}
break;
case 0x83 :
if ( F_69 ( V_253 ) ) {
V_231 = true ;
} else {
F_47 (KERN_INFO DRIVER_NAME
L_79 ) ;
}
break;
case 0x84 :
if ( V_232 &&
( F_70 ( V_253 ) ) ) {
V_8 -> V_261 =
V_253 -> V_259 ;
} else {
if ( F_69 ( V_253 ) ) {
if ( V_255 > V_8 -> V_262 ) {
V_157 = true ;
V_8 -> V_263 = V_253 -> V_259 ;
V_8 -> V_262 = V_255 ;
V_8 -> V_264 = V_102 ;
}
} else {
V_157 = true ;
V_8 -> V_265 = V_253 -> V_259 ;
}
}
break;
}
}
}
}
if ( ! ( V_231 || V_232 || V_157 ) ) {
V_172 = - V_205 ;
goto V_266;
}
switch ( V_163 -> V_239 ) {
case V_267 :
V_239 = L_80 ;
break;
case V_268 :
case V_269 :
V_239 = L_81 ;
break;
case V_258 :
V_239 = L_82 ;
break;
default:
V_239 = L_83 ;
}
F_47 (KERN_INFO DRIVER_NAME
L_84
L_85 ,
udev->manufacturer ? udev->manufacturer : L_86 ,
udev->product ? udev->product : L_86 ,
speed,
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
ifnum,
interface->altsetting->desc.bInterfaceNumber) ;
if ( V_163 -> V_239 != V_258 && V_270 == 0 ) {
F_47 ( V_241 L_87 ) ;
F_47 ( V_241 L_88
L_89 ) ;
V_172 = - V_205 ;
goto V_266;
}
V_8 -> V_164 = V_233 ;
V_8 -> V_18 = V_230 -> V_271 ;
V_8 -> V_272 = - 1 ;
V_8 -> V_204 = V_231 && ! ( V_232 || V_157 ) ;
V_8 -> V_156 = V_231 ;
V_8 -> V_273 = V_235 ;
for ( V_102 = 0 ; V_102 < V_163 -> V_274 -> V_237 . V_275 ; V_102 ++ ) {
struct V_167 * V_276 = V_163 -> V_274 -> V_168 [ V_102 ] ;
if ( V_276 -> V_236 [ 0 ] . V_237 . V_244 == V_245 ) {
V_8 -> V_155 = 1 ;
break;
}
}
if ( V_231 )
F_47 (KERN_INFO DRIVER_NAME
L_90 ,
ifnum,
dev->has_audio_class ? L_91 : L_92 ) ;
if ( V_232 )
F_47 (KERN_INFO DRIVER_NAME
L_93 ,
ifnum,
dev->analog_ep_bulk ? L_94 : L_86 ,
dev->analog_ep_isoc ? L_95 : L_86 ) ;
if ( V_157 )
F_47 (KERN_INFO DRIVER_NAME
L_96 ,
ifnum,
dev->dvb_ep_bulk ? L_94 : L_86 ,
dev->dvb_ep_isoc ? L_95 : L_86 ) ;
V_8 -> V_277 = V_168 -> V_249 ;
if ( ( unsigned ) V_278 [ V_233 ] < V_115 )
V_8 -> V_18 = V_278 [ V_233 ] ;
F_71 ( V_168 , V_8 ) ;
F_72 ( V_8 ) ;
F_44 ( & V_8 -> V_279 ) ;
F_73 ( & V_8 -> V_279 ) ;
V_172 = F_43 ( V_8 , V_163 , V_168 , V_233 ) ;
if ( V_172 ) {
goto V_280;
}
if ( V_281 < 0 ) {
if ( V_8 -> V_15 . V_103 )
V_234 = 1 ;
else
V_234 = 0 ;
} else {
V_234 = V_281 > 0 ;
}
if ( V_232 ) {
if ( ! V_8 -> V_260 || ( V_234 && V_8 -> V_261 ) )
V_8 -> V_282 = 1 ;
F_19 ( L_97 ,
V_8 -> V_282 ? L_98 : L_99 ) ;
}
if ( V_157 ) {
if ( ! V_8 -> V_263 || ( V_234 && V_8 -> V_265 ) )
V_8 -> V_283 = 1 ;
F_19 ( L_100 ,
V_8 -> V_283 ? L_98 : L_99 ) ;
if ( V_8 -> V_283 ) {
V_172 = F_74 ( V_8 , V_284 ,
V_8 -> V_283 ,
V_285 ,
512 ,
V_286 ) ;
} else {
V_172 = F_74 ( V_8 , V_284 ,
V_8 -> V_283 ,
V_285 ,
V_8 -> V_262 ,
V_287 ) ;
}
if ( V_172 ) {
F_47 ( V_241
L_101 ) ;
goto V_280;
}
}
F_31 ( V_8 ) ;
F_75 ( & V_8 -> V_279 ) ;
return 0 ;
V_280:
F_75 ( & V_8 -> V_279 ) ;
V_266:
F_23 ( V_8 -> V_248 ) ;
F_23 ( V_8 ) ;
V_246:
F_42 ( V_233 , & V_165 ) ;
V_243:
F_41 ( V_163 ) ;
return V_172 ;
}
static void F_76 ( struct V_167 * V_168 )
{
struct V_7 * V_8 ;
V_8 = F_77 ( V_168 ) ;
F_71 ( V_168 , NULL ) ;
if ( ! V_8 )
return;
V_8 -> V_288 = 1 ;
if ( V_8 -> V_204 ) {
F_73 ( & V_8 -> V_279 ) ;
F_78 ( V_8 ) ;
F_75 ( & V_8 -> V_279 ) ;
return;
}
F_19 ( L_102 , V_8 -> V_289 -> V_112 ) ;
F_34 ( V_8 ) ;
F_73 ( & V_8 -> V_279 ) ;
F_79 ( & V_8 -> V_87 ) ;
if ( V_8 -> V_290 ) {
F_80 ( L_103 ,
F_81 ( V_8 -> V_289 ) ) ;
F_82 ( V_8 , V_44 ) ;
F_82 ( V_8 , V_284 ) ;
}
F_78 ( V_8 ) ;
if ( ! V_8 -> V_290 )
F_36 ( V_8 ) ;
F_75 ( & V_8 -> V_279 ) ;
if ( ! V_8 -> V_290 ) {
F_23 ( V_8 -> V_248 ) ;
F_23 ( V_8 ) ;
}
}
