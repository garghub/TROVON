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
static int F_4 ( struct V_7 * V_8 ,
int V_26 )
{
unsigned long V_27 = V_28 + F_5 ( 2000 ) ;
int V_29 , V_30 ;
while ( F_6 ( V_27 ) ) {
V_29 = F_7 ( V_8 , V_31 ) ;
if ( V_29 < 0 )
return V_29 ;
V_30 = F_7 ( V_8 , V_32 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( V_29 == V_26 && V_29 != V_30 )
return 0 ;
F_8 ( 50 ) ;
}
F_9 ( L_1 ) ;
return - V_33 ;
}
static void F_10 ( struct V_7 * V_8 )
{
F_11 ( V_8 , V_34 , V_8 -> V_15 . V_19 & 0x7f ) ;
if ( ! V_8 -> V_15 . V_35 )
F_11 ( V_8 , V_36 , V_8 -> V_15 . V_22 ) ;
F_8 ( 50 ) ;
switch ( V_8 -> V_18 ) {
case V_37 :
V_8 -> V_38 = 2048000 ;
break;
case V_39 :
case V_40 :
F_11 ( V_8 , V_41 , 0x6d ) ;
F_8 ( 10 ) ;
F_11 ( V_8 , V_41 , 0x7d ) ;
F_8 ( 10 ) ;
break;
case V_42 :
F_11 ( V_8 , V_43 , 0x00 ) ;
F_8 ( 10 ) ;
F_11 ( V_8 , V_43 , 0x01 ) ;
F_8 ( 10 ) ;
F_11 ( V_8 , V_41 , 0xfd ) ;
F_12 ( 70 ) ;
F_11 ( V_8 , V_41 , 0xfc ) ;
F_12 ( 70 ) ;
F_11 ( V_8 , V_41 , 0xdc ) ;
F_12 ( 70 ) ;
F_11 ( V_8 , V_41 , 0xfc ) ;
F_12 ( 70 ) ;
break;
case V_44 :
F_11 ( V_8 , V_41 , 0xfe ) ;
F_12 ( 70 ) ;
F_11 ( V_8 , V_41 , 0xde ) ;
F_12 ( 70 ) ;
F_11 ( V_8 , V_41 , 0xfe ) ;
F_12 ( 70 ) ;
break;
case V_45 :
F_11 ( V_8 , V_41 , 0xfe ) ;
F_12 ( 70 ) ;
F_11 ( V_8 , V_41 , 0xde ) ;
F_12 ( 70 ) ;
F_11 ( V_8 , V_41 , 0xfe ) ;
F_12 ( 70 ) ;
break;
case V_46 :
case V_47 :
F_11 ( V_8 , V_41 , 0xfd ) ;
break;
case V_48 :
F_11 ( V_8 , V_41 , 0xff ) ;
F_8 ( 10 ) ;
F_11 ( V_8 , V_41 , 0xfe ) ;
F_8 ( 10 ) ;
F_11 ( V_8 , V_43 , 0x00 ) ;
F_8 ( 10 ) ;
F_11 ( V_8 , V_43 , 0x08 ) ;
F_8 ( 10 ) ;
break;
case V_49 :
F_13 ( V_8 , V_34 , L_2 , 1 ) ;
F_13 ( V_8 , V_36 , L_3 , 1 ) ;
F_13 ( V_8 , 0x0d , L_4 , 1 ) ;
F_13 ( V_8 , 0x08 , L_5 , 1 ) ;
F_8 ( 10 ) ;
F_13 ( V_8 , 0x08 , L_6 , 1 ) ;
F_8 ( 10 ) ;
F_13 ( V_8 , 0x08 , L_7 , 1 ) ;
F_8 ( 10 ) ;
F_13 ( V_8 , 0x08 , L_8 , 1 ) ;
break;
case V_50 :
F_13 ( V_8 , 0x08 , L_9 , 1 ) ;
break;
case V_51 :
F_11 ( V_8 , V_41 , 0xff ) ;
F_8 ( 70 ) ;
F_11 ( V_8 , V_41 , 0xf7 ) ;
F_8 ( 10 ) ;
F_11 ( V_8 , V_41 , 0xfe ) ;
F_8 ( 70 ) ;
F_11 ( V_8 , V_41 , 0xfd ) ;
F_8 ( 70 ) ;
break;
case V_52 :
F_4 ( V_8 , 0x6a90 ) ;
break;
}
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_14 ( V_8 , V_53 ) ;
F_14 ( V_8 , V_54 ) ;
}
static int F_15 ( struct V_7 * V_8 )
{
int V_55 ;
if ( V_8 -> V_15 . V_56 ) {
if ( V_8 -> V_57 == V_58 ) {
V_8 -> V_18 = V_59 ;
} else if ( V_8 -> V_57 == V_60 ||
V_8 -> V_57 == V_61 ) {
V_8 -> V_18 = V_62 ;
}
return 0 ;
}
for ( V_55 = 0 ; V_55 < F_16 ( V_63 ) ; V_55 ++ ) {
if ( V_8 -> V_64 == V_63 [ V_55 ] . V_64 ) {
V_8 -> V_18 = V_63 [ V_55 ] . V_18 ;
V_8 -> V_10 = V_63 [ V_55 ] . V_65 ;
F_17 ( L_10 ) ;
F_17 ( L_11
L_12 ) ;
F_17 ( L_13 ) ;
F_17 ( L_14
L_15 ) ;
F_17 ( L_16
L_17 ) ;
F_17 ( L_18 ,
V_17 [ V_8 -> V_18 ] . V_66 ) ;
return 0 ;
}
}
if ( ! V_8 -> V_67 )
F_18 ( V_8 , V_8 -> V_25 ) ;
for ( V_55 = 0 ; V_55 < F_16 ( V_68 ) ; V_55 ++ ) {
if ( V_8 -> V_67 == V_68 [ V_55 ] . V_64 ) {
V_8 -> V_18 = V_68 [ V_55 ] . V_18 ;
V_8 -> V_10 = V_68 [ V_55 ] . V_65 ;
F_17 ( L_10 ) ;
F_17 ( L_11
L_19 ) ;
F_17 ( L_13 ) ;
F_17 ( L_14
L_15 ) ;
F_17 ( L_16
L_17 ) ;
F_17 ( L_18 ,
V_17 [ V_8 -> V_18 ] . V_66 ) ;
return 0 ;
}
}
F_17 ( L_20
L_21 ) ;
F_17 ( L_22
L_23 ) ;
F_17 ( L_24 ) ;
F_17 ( L_25 ) ;
F_17 ( L_26 , V_8 -> V_64 ) ;
F_17 ( L_27 , V_8 -> V_67 ) ;
F_17 ( L_28
L_29 ) ;
for ( V_55 = 0 ; V_55 < V_69 ; V_55 ++ ) {
F_17 ( L_30 ,
V_55 , V_17 [ V_55 ] . V_66 ) ;
}
return - 1 ;
}
static void F_19 ( struct V_7 * V_8 )
{
if ( V_8 -> V_15 . V_56 ) {
if ( F_20 ( V_8 ) < 0 )
V_8 -> V_15 . V_56 = 0 ;
}
switch ( V_8 -> V_18 ) {
case V_62 :
case V_70 :
case V_71 :
if ( F_15 ( V_8 ) < 0 )
F_17 ( L_31 ) ;
else {
F_3 ( V_8 ) ;
F_10 ( V_8 ) ;
}
break;
default:
F_3 ( V_8 ) ;
}
F_21 ( L_32 ,
V_8 -> V_15 . V_66 , V_8 -> V_18 ) ;
V_8 -> V_10 = V_17 [ V_8 -> V_18 ] . V_10 ;
switch ( V_8 -> V_18 ) {
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
{
struct V_79 V_80 ;
if ( V_8 -> V_81 == NULL )
break;
#if F_22 ( V_82 ) && F_22 ( V_83 )
F_23 ( L_33 ) ;
#endif
V_8 -> V_84 [ V_8 -> V_25 ] . V_85 = 0xa0 >> 1 ;
F_24 ( & V_8 -> V_84 [ V_8 -> V_25 ] , & V_80 , V_8 -> V_81 ) ;
V_8 -> V_10 = V_80 . V_10 ;
if ( V_80 . V_86 == V_87 ) {
V_8 -> V_38 = 2048000 ;
V_8 -> V_15 . V_88 = 1 ;
}
break;
}
case V_48 :
F_11 ( V_8 , 0x0d , 0x42 ) ;
F_8 ( 10 ) ;
F_11 ( V_8 , V_41 , 0xfd ) ;
F_8 ( 10 ) ;
break;
case V_89 :
F_11 ( V_8 , V_41 , 0xf9 ) ;
break;
case V_70 :
case V_71 :
case V_90 :
if ( ! F_15 ( V_8 ) )
F_3 ( V_8 ) ;
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_14 ( V_8 , V_53 ) ;
break;
case V_91 :
if ( ! F_15 ( V_8 ) )
F_3 ( V_8 ) ;
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_14 ( V_8 , V_53 ) ;
break;
}
if ( V_8 -> V_15 . V_92 == V_93 ) {
F_17 ( L_34 ) ;
F_17 ( L_35
L_36 ) ;
F_17 ( L_37 ) ;
F_17 ( L_38
L_39 ) ;
}
F_25 ( V_8 -> V_81 ) ;
V_8 -> V_81 = NULL ;
if ( V_65 >= 0 )
V_8 -> V_10 = V_65 ;
}
void F_26 ( struct V_7 * V_8 , struct V_94 * V_95 )
{
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_96 = V_97 ;
V_95 -> V_98 = 64 ;
V_95 -> V_99 = V_17 [ V_8 -> V_18 ] . V_100 ;
switch ( V_8 -> V_18 ) {
case V_101 :
case V_73 :
case V_102 :
V_95 -> V_103 = V_104 ;
break;
case V_105 :
case V_106 :
case V_107 :
V_95 -> V_103 = V_104 ;
break;
case V_74 :
case V_108 :
V_95 -> V_103 = V_109 ;
break;
case V_110 :
V_95 -> V_103 = V_109 ;
V_95 -> V_96 = V_111 ;
break;
case V_75 :
case V_76 :
case V_112 :
V_95 -> V_103 = V_109 ;
break;
case V_113 :
case V_114 :
case V_91 :
V_95 -> V_103 = V_115 ;
V_95 -> V_96 = V_97 ;
break;
case V_116 :
V_95 -> V_103 = V_115 ;
V_95 -> V_96 = V_111 ;
break;
default:
V_95 -> V_103 = V_117 ;
}
}
static void F_27 ( struct V_118 * V_119 )
{
struct V_7 * V_8 = F_28 ( V_119 ,
struct V_7 , V_120 ) ;
if ( V_8 -> V_121 ) {
#if F_22 ( V_82 ) && F_22 ( V_83 )
F_23 ( L_40 ) ;
#endif
return;
}
F_29 ( V_8 ) ;
#if F_22 ( V_82 ) && F_22 ( V_83 )
if ( V_8 -> V_122 )
F_23 ( L_41 ) ;
if ( V_8 -> V_123 == V_124 )
F_23 ( L_42 ) ;
else if ( V_8 -> V_123 == V_125 )
F_23 ( L_40 ) ;
if ( V_8 -> V_15 . V_126 )
F_23 ( L_43 ) ;
if ( V_8 -> V_15 . V_127 ||
( ( V_8 -> V_15 . V_128 || V_8 -> V_15 . V_129 ) && ! V_130 ) )
F_23 ( L_44 ) ;
#endif
}
static void F_30 ( struct V_7 * V_8 )
{
F_31 ( & V_8 -> V_120 , F_27 ) ;
F_32 ( & V_8 -> V_120 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
F_34 ( & V_8 -> V_120 ) ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_131 * V_132 )
{
#ifdef F_36
struct V_133 * V_134 ;
V_134 = F_37 ( sizeof( * V_134 ) , V_135 ) ;
if ( ! V_134 )
return - V_136 ;
if ( V_132 -> V_137 )
F_38 ( V_134 , V_132 , V_132 -> V_137 ) ;
else if ( V_132 -> V_138 )
F_38 ( V_134 , V_132 , V_132 -> V_138 ) ;
else
F_38 ( V_134 , V_132 , V_8 -> V_66 ) ;
V_8 -> V_139 = V_134 ;
#endif
return 0 ;
}
static void F_39 ( struct V_7 * V_8 )
{
#ifdef F_36
if ( V_8 -> V_139 ) {
F_40 ( V_8 -> V_139 ) ;
F_41 ( V_8 -> V_139 ) ;
F_25 ( V_8 -> V_139 ) ;
V_8 -> V_139 = NULL ;
}
#endif
}
static void F_42 ( struct V_7 * V_8 )
{
F_43 ( & V_8 -> V_140 ) ;
F_39 ( V_8 ) ;
if ( V_8 -> V_25 )
F_44 ( V_8 , 1 ) ;
F_44 ( V_8 , 0 ) ;
F_45 ( V_8 -> V_132 ) ;
F_46 ( V_8 -> V_141 , V_142 ) ;
F_47 ( & V_8 -> V_140 ) ;
}
void F_48 ( struct V_143 * V_144 )
{
struct V_7 * V_8 = F_49 ( V_144 ) ;
F_21 ( L_45 ) ;
if ( ! V_8 -> V_145 )
F_42 ( V_8 ) ;
F_25 ( V_8 -> V_146 ) ;
F_25 ( V_8 ) ;
}
static int F_50 ( struct V_7 * V_8 , struct V_131 * V_132 ,
struct V_147 * V_148 ,
int V_149 )
{
int V_150 ;
static const char * V_151 = L_46 ;
const char * V_152 = V_151 ;
V_8 -> V_132 = V_132 ;
F_51 ( & V_8 -> V_153 ) ;
F_52 ( & V_8 -> V_154 ) ;
V_8 -> F_13 = F_13 ;
V_8 -> V_155 = V_155 ;
V_8 -> V_156 = V_156 ;
V_8 -> V_157 = V_157 ;
V_8 -> V_158 = V_158 ;
V_8 -> V_15 . V_35 = V_17 [ V_8 -> V_18 ] . V_35 ;
F_3 ( V_8 ) ;
V_8 -> V_159 = 5 ;
V_150 = V_155 ( V_8 , V_160 ) ;
if ( V_150 > 0 ) {
V_8 -> V_161 = V_150 ;
switch ( V_8 -> V_161 ) {
case V_162 :
V_152 = L_47 ;
break;
case V_163 :
V_152 = L_48 ;
break;
case V_164 :
V_152 = L_49 ;
break;
case V_165 :
V_152 = L_50 ;
V_8 -> V_159 = 0 ;
V_8 -> V_166 = 1 ;
V_8 -> V_167 = 1 ;
break;
case V_168 :
V_152 = L_51 ;
if ( F_53 ( V_8 -> V_132 -> V_169 . V_170 )
== 0xeb1a ) {
T_1 V_171 = V_8 -> V_132 -> V_169 . V_172 ;
if ( F_53 ( V_171 ) == 0x2710 )
V_152 = L_48 ;
else if ( F_53 ( V_171 ) == 0x2820 )
V_152 = L_52 ;
}
break;
case V_173 :
V_152 = L_53 ;
break;
case V_174 :
V_152 = L_54 ;
break;
case V_175 :
V_152 = L_55 ;
V_8 -> V_159 = 0 ;
break;
case V_176 :
V_152 = L_56 ;
V_8 -> V_159 = 0 ;
V_8 -> V_167 = 1 ;
break;
case V_177 :
V_152 = L_57 ;
V_8 -> V_159 = 0 ;
V_8 -> V_167 = 1 ;
break;
case V_178 :
V_152 = L_58 ;
V_8 -> V_159 = 0 ;
V_8 -> V_167 = 1 ;
break;
case V_179 :
V_152 = L_59 ;
V_8 -> V_159 = 0 ;
break;
case V_180 :
V_152 = L_60 ;
V_8 -> V_159 = 0 ;
V_8 -> V_167 = 1 ;
break;
default:
F_54 (KERN_INFO DRIVER_NAME
L_61 , dev->chip_id) ;
}
}
if ( V_152 != V_151 )
F_54 (KERN_INFO DRIVER_NAME
L_62 , chip_name) ;
snprintf ( V_8 -> V_66 , sizeof( V_8 -> V_66 ) , L_63 , V_152 , V_8 -> V_141 ) ;
F_35 ( V_8 , V_132 ) ;
if ( V_8 -> V_121 ) {
V_150 = F_55 ( V_8 ) ;
if ( V_150 )
return - V_181 ;
F_29 ( V_8 ) ;
return 0 ;
}
F_10 ( V_8 ) ;
if ( ! V_8 -> V_15 . V_35 ) {
V_150 = F_11 ( V_8 , V_36 , V_8 -> V_15 . V_22 ) ;
if ( V_150 < 0 ) {
F_17 ( L_64
L_65 ,
V_182 , V_150 ) ;
return V_150 ;
}
}
F_56 ( & V_8 -> V_183 ) ;
if ( V_8 -> V_15 . V_35 )
V_150 = F_57 ( V_8 , 0 , V_184 ) ;
else
V_150 = F_57 ( V_8 , 0 , V_185 ) ;
if ( V_150 < 0 ) {
F_17 ( L_66 ,
V_182 , V_150 ) ;
return V_150 ;
}
if ( V_8 -> V_25 ) {
if ( V_8 -> V_166 )
V_150 = F_57 ( V_8 , 1 ,
V_186 ) ;
else
V_150 = F_57 ( V_8 , 1 ,
V_185 ) ;
if ( V_150 < 0 ) {
F_17 ( L_67 ,
V_182 , V_150 ) ;
F_44 ( V_8 , 0 ) ;
return V_150 ;
}
}
F_19 ( V_8 ) ;
return 0 ;
}
static int F_58 ( struct V_147 * V_148 ,
const struct V_187 * V_188 )
{
struct V_131 * V_132 ;
struct V_7 * V_8 = NULL ;
int V_150 ;
bool V_189 = false , V_122 = false , V_126 = false ;
int V_55 , V_190 , V_191 ;
const int V_192 = V_148 -> V_193 [ 0 ] . V_194 . V_195 ;
char * V_196 ;
V_132 = F_59 ( F_60 ( V_148 ) ) ;
do {
V_190 = F_61 ( V_142 , V_197 ) ;
if ( V_190 >= V_197 ) {
F_54 ( V_198 L_68 ,
V_197 ) ;
V_150 = - V_136 ;
goto V_199;
}
} while ( F_62 ( V_190 , V_142 ) );
if ( V_148 -> V_193 [ 0 ] . V_194 . V_200 == V_201 ) {
F_63 ( V_198 L_69
L_70 ,
F_53 ( V_132 -> V_169 . V_170 ) ,
F_53 ( V_132 -> V_169 . V_172 ) ,
V_192 ,
V_148 -> V_193 [ 0 ] . V_194 . V_200 ) ;
V_150 = - V_181 ;
goto V_202;
}
V_8 = F_37 ( sizeof( * V_8 ) , V_135 ) ;
if ( V_8 == NULL ) {
F_63 ( V_198 L_71 ) ;
V_150 = - V_136 ;
goto V_202;
}
V_8 -> V_146 =
F_64 ( sizeof( V_8 -> V_146 [ 0 ] ) *
V_148 -> V_203 , V_135 ) ;
if ( V_8 -> V_146 == NULL ) {
F_17 ( L_72 ) ;
F_25 ( V_8 ) ;
V_150 = - V_136 ;
goto V_202;
}
for ( V_55 = 0 ; V_55 < V_148 -> V_203 ; V_55 ++ ) {
int V_204 ;
for ( V_204 = 0 ; V_204 < V_148 -> V_193 [ V_55 ] . V_194 . V_205 ; V_204 ++ ) {
const struct V_206 * V_207 ;
int V_208 , V_209 ;
V_207 = & V_148 -> V_193 [ V_55 ] . V_210 [ V_204 ] . V_194 ;
V_208 = F_53 ( V_207 -> V_211 ) ;
V_209 = V_208 & 0x7ff ;
if ( V_132 -> V_196 == V_212 )
V_209 = V_209 * F_65 ( V_208 ) ;
if ( F_66 ( V_207 ) ) {
switch ( V_207 -> V_213 ) {
case 0x82 :
V_122 = true ;
if ( F_67 ( V_207 ) ) {
V_8 -> V_214 =
V_207 -> V_213 ;
V_8 -> V_146 [ V_55 ] = V_209 ;
} else if ( F_68 ( V_207 ) ) {
V_8 -> V_215 =
V_207 -> V_213 ;
}
break;
case 0x83 :
if ( F_67 ( V_207 ) ) {
V_189 = true ;
} else {
F_54 (KERN_INFO DRIVER_NAME
L_73 ) ;
}
break;
case 0x84 :
if ( V_122 &&
( F_68 ( V_207 ) ) ) {
V_8 -> V_215 =
V_207 -> V_213 ;
} else {
if ( F_67 ( V_207 ) ) {
if ( V_209 > V_8 -> V_216 ) {
V_126 = true ;
V_8 -> V_217 = V_207 -> V_213 ;
V_8 -> V_216 = V_209 ;
V_8 -> V_218 = V_55 ;
}
} else {
V_126 = true ;
V_8 -> V_219 = V_207 -> V_213 ;
}
}
break;
}
}
}
}
if ( ! ( V_189 || V_122 || V_126 ) ) {
V_150 = - V_181 ;
goto V_220;
}
switch ( V_132 -> V_196 ) {
case V_221 :
V_196 = L_74 ;
break;
case V_222 :
case V_223 :
V_196 = L_75 ;
break;
case V_212 :
V_196 = L_76 ;
break;
default:
V_196 = L_77 ;
}
F_54 (KERN_INFO DRIVER_NAME
L_78
L_79 ,
udev->manufacturer ? udev->manufacturer : L_80 ,
udev->product ? udev->product : L_80 ,
speed,
le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct),
ifnum,
interface->altsetting->desc.bInterfaceNumber) ;
if ( V_132 -> V_196 != V_212 && V_224 == 0 ) {
F_54 ( V_198 L_81 ) ;
F_54 ( V_198 L_82
L_83 ) ;
V_150 = - V_181 ;
goto V_220;
}
V_8 -> V_141 = V_190 ;
V_8 -> V_18 = V_188 -> V_225 ;
V_8 -> V_226 = - 1 ;
V_8 -> V_121 = V_189 && ! ( V_122 || V_126 ) ;
V_8 -> V_122 = V_122 ;
V_8 -> V_192 = V_192 ;
if ( V_189 ) {
F_54 (KERN_INFO DRIVER_NAME L_84 ,
ifnum, L_85 ) ;
V_8 -> V_123 = V_125 ;
}
for ( V_55 = 0 ; V_55 < V_132 -> V_227 -> V_194 . V_228 ; V_55 ++ ) {
struct V_147 * V_229 = V_132 -> V_227 -> V_148 [ V_55 ] ;
if ( V_229 -> V_193 [ 0 ] . V_194 . V_200 == V_201 ) {
if ( V_189 )
F_63 ( L_86
L_87 ) ;
V_8 -> V_123 = V_124 ;
break;
}
}
if ( V_122 )
F_54 (KERN_INFO DRIVER_NAME
L_88 ,
ifnum,
dev->analog_ep_bulk ? L_89 : L_80 ,
dev->analog_ep_isoc ? L_90 : L_80 ) ;
if ( V_126 )
F_54 (KERN_INFO DRIVER_NAME
L_91 ,
ifnum,
dev->dvb_ep_bulk ? L_89 : L_80 ,
dev->dvb_ep_isoc ? L_90 : L_80 ) ;
V_8 -> V_230 = V_148 -> V_203 ;
if ( ( unsigned ) V_231 [ V_190 ] < V_69 )
V_8 -> V_18 = V_231 [ V_190 ] ;
F_69 ( V_148 , V_8 ) ;
F_51 ( & V_8 -> V_140 ) ;
V_150 = F_50 ( V_8 , V_132 , V_148 , V_190 ) ;
if ( V_150 ) {
goto V_220;
}
if ( V_232 < 0 ) {
if ( V_8 -> V_15 . V_56 )
V_191 = 1 ;
else
V_191 = 0 ;
} else {
V_191 = V_232 > 0 ;
}
if ( V_122 &&
V_8 -> V_15 . V_233 == V_234 && ! V_8 -> V_15 . V_56 ) {
F_54 ( V_198
L_92 ) ;
V_122 = false ;
V_8 -> V_122 = false ;
}
if ( V_122 ) {
if ( ! V_8 -> V_214 || ( V_191 && V_8 -> V_215 ) )
V_8 -> V_235 = 1 ;
F_21 ( L_93 ,
V_8 -> V_235 ? L_94 : L_95 ) ;
}
if ( V_126 ) {
if ( ! V_8 -> V_217 || ( V_191 && V_8 -> V_219 ) )
V_8 -> V_236 = 1 ;
F_21 ( L_96 ,
V_8 -> V_236 ? L_94 : L_95 ) ;
}
F_70 ( & V_8 -> V_144 ) ;
F_30 ( V_8 ) ;
#ifdef F_36
V_150 = F_71 ( V_8 -> V_139 ) ;
#endif
return 0 ;
V_220:
F_25 ( V_8 -> V_146 ) ;
F_25 ( V_8 ) ;
V_202:
F_46 ( V_190 , V_142 ) ;
V_199:
F_45 ( V_132 ) ;
return V_150 ;
}
static void F_72 ( struct V_147 * V_148 )
{
struct V_7 * V_8 ;
V_8 = F_73 ( V_148 ) ;
F_69 ( V_148 , NULL ) ;
if ( ! V_8 )
return;
V_8 -> V_145 = 1 ;
F_21 ( L_97 , V_8 -> V_66 ) ;
F_33 ( V_8 ) ;
F_74 ( V_8 ) ;
F_42 ( V_8 ) ;
F_75 ( & V_8 -> V_144 , F_48 ) ;
}
static int F_76 ( struct V_147 * V_148 ,
T_2 V_237 )
{
struct V_7 * V_8 ;
V_8 = F_73 ( V_148 ) ;
if ( ! V_8 )
return 0 ;
F_77 ( V_8 ) ;
return 0 ;
}
static int F_78 ( struct V_147 * V_148 )
{
struct V_7 * V_8 ;
V_8 = F_73 ( V_148 ) ;
if ( ! V_8 )
return 0 ;
F_79 ( V_8 ) ;
return 0 ;
}
