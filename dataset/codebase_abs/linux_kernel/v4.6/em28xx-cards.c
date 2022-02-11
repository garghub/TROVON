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
{
struct V_78 V_79 ;
if ( V_8 -> V_80 == NULL )
break;
#if F_22 ( V_81 ) && F_22 ( V_82 )
F_23 ( L_33 ) ;
#endif
V_8 -> V_83 [ V_8 -> V_25 ] . V_84 = 0xa0 >> 1 ;
F_24 ( & V_8 -> V_83 [ V_8 -> V_25 ] , & V_79 , V_8 -> V_80 ) ;
V_8 -> V_10 = V_79 . V_10 ;
if ( V_79 . V_85 == V_86 ) {
V_8 -> V_38 = 2048000 ;
V_8 -> V_15 . V_87 = 1 ;
}
break;
}
case V_48 :
F_11 ( V_8 , 0x0d , 0x42 ) ;
F_8 ( 10 ) ;
F_11 ( V_8 , V_41 , 0xfd ) ;
F_8 ( 10 ) ;
break;
case V_88 :
F_11 ( V_8 , V_41 , 0xf9 ) ;
break;
case V_70 :
case V_71 :
case V_89 :
if ( ! F_15 ( V_8 ) )
F_3 ( V_8 ) ;
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_14 ( V_8 , V_53 ) ;
break;
case V_90 :
if ( ! F_15 ( V_8 ) )
F_3 ( V_8 ) ;
F_2 ( V_8 , V_8 -> V_15 . V_16 ) ;
F_14 ( V_8 , V_53 ) ;
break;
}
if ( V_8 -> V_15 . V_91 == V_92 ) {
F_17 ( L_34 ) ;
F_17 ( L_35
L_36 ) ;
F_17 ( L_37 ) ;
F_17 ( L_38
L_39 ) ;
}
F_25 ( V_8 -> V_80 ) ;
V_8 -> V_80 = NULL ;
if ( V_65 >= 0 )
V_8 -> V_10 = V_65 ;
}
void F_26 ( struct V_7 * V_8 , struct V_93 * V_94 )
{
memset ( V_94 , 0 , sizeof( * V_94 ) ) ;
V_94 -> V_95 = V_96 ;
V_94 -> V_97 = 64 ;
V_94 -> V_98 = V_17 [ V_8 -> V_18 ] . V_99 ;
switch ( V_8 -> V_18 ) {
case V_100 :
case V_73 :
case V_101 :
V_94 -> V_102 = V_103 ;
break;
case V_104 :
case V_105 :
case V_106 :
V_94 -> V_102 = V_103 ;
break;
case V_74 :
case V_107 :
V_94 -> V_102 = V_108 ;
break;
case V_109 :
V_94 -> V_102 = V_108 ;
V_94 -> V_95 = V_110 ;
break;
case V_75 :
case V_76 :
case V_111 :
V_94 -> V_102 = V_108 ;
break;
case V_112 :
case V_113 :
case V_90 :
V_94 -> V_102 = V_114 ;
V_94 -> V_95 = V_96 ;
break;
case V_115 :
V_94 -> V_102 = V_114 ;
V_94 -> V_95 = V_110 ;
break;
default:
V_94 -> V_102 = V_116 ;
}
}
static void F_27 ( struct V_117 * V_118 )
{
struct V_7 * V_8 = F_28 ( V_118 ,
struct V_7 , V_119 ) ;
if ( V_8 -> V_120 ) {
#if F_22 ( V_81 ) && F_22 ( V_82 )
F_23 ( L_40 ) ;
#endif
return;
}
F_29 ( V_8 ) ;
#if F_22 ( V_81 ) && F_22 ( V_82 )
if ( V_8 -> V_121 )
F_23 ( L_41 ) ;
if ( V_8 -> V_122 == V_123 )
F_23 ( L_42 ) ;
else if ( V_8 -> V_122 == V_124 )
F_23 ( L_40 ) ;
if ( V_8 -> V_15 . V_125 )
F_23 ( L_43 ) ;
if ( V_8 -> V_15 . V_126 ||
( ( V_8 -> V_15 . V_127 || V_8 -> V_15 . V_128 ) && ! V_129 ) )
F_23 ( L_44 ) ;
#endif
}
static void F_30 ( struct V_7 * V_8 )
{
F_31 ( & V_8 -> V_119 , F_27 ) ;
F_32 ( & V_8 -> V_119 ) ;
}
static void F_33 ( struct V_7 * V_8 )
{
F_34 ( & V_8 -> V_119 ) ;
}
static int F_35 ( struct V_7 * V_8 ,
struct V_130 * V_131 )
{
#ifdef F_36
struct V_132 * V_133 ;
V_133 = F_37 ( sizeof( * V_133 ) , V_134 ) ;
if ( ! V_133 )
return - V_135 ;
if ( V_131 -> V_136 )
F_38 ( V_133 , V_131 , V_131 -> V_136 ) ;
else if ( V_131 -> V_137 )
F_38 ( V_133 , V_131 , V_131 -> V_137 ) ;
else
F_38 ( V_133 , V_131 , V_8 -> V_66 ) ;
V_8 -> V_138 = V_133 ;
#endif
return 0 ;
}
static void F_39 ( struct V_7 * V_8 )
{
#ifdef F_36
if ( V_8 -> V_138 ) {
F_40 ( V_8 -> V_138 ) ;
F_41 ( V_8 -> V_138 ) ;
F_25 ( V_8 -> V_138 ) ;
V_8 -> V_138 = NULL ;
}
#endif
}
static void F_42 ( struct V_7 * V_8 )
{
F_43 ( & V_8 -> V_139 ) ;
F_39 ( V_8 ) ;
if ( V_8 -> V_25 )
F_44 ( V_8 , 1 ) ;
F_44 ( V_8 , 0 ) ;
F_45 ( V_8 -> V_131 ) ;
F_46 ( V_8 -> V_140 , V_141 ) ;
F_47 ( & V_8 -> V_139 ) ;
}
void F_48 ( struct V_142 * V_143 )
{
struct V_7 * V_8 = F_49 ( V_143 ) ;
F_21 ( L_45 ) ;
if ( ! V_8 -> V_144 )
F_42 ( V_8 ) ;
F_25 ( V_8 -> V_145 ) ;
F_25 ( V_8 ) ;
}
static int F_50 ( struct V_7 * V_8 , struct V_130 * V_131 ,
struct V_146 * V_147 ,
int V_148 )
{
int V_149 ;
static const char * V_150 = L_46 ;
const char * V_151 = V_150 ;
V_8 -> V_131 = V_131 ;
F_51 ( & V_8 -> V_152 ) ;
F_52 ( & V_8 -> V_153 ) ;
V_8 -> F_13 = F_13 ;
V_8 -> V_154 = V_154 ;
V_8 -> V_155 = V_155 ;
V_8 -> V_156 = V_156 ;
V_8 -> V_157 = V_157 ;
V_8 -> V_15 . V_35 = V_17 [ V_8 -> V_18 ] . V_35 ;
F_3 ( V_8 ) ;
V_8 -> V_158 = 5 ;
V_149 = V_154 ( V_8 , V_159 ) ;
if ( V_149 > 0 ) {
V_8 -> V_160 = V_149 ;
switch ( V_8 -> V_160 ) {
case V_161 :
V_151 = L_47 ;
break;
case V_162 :
V_151 = L_48 ;
break;
case V_163 :
V_151 = L_49 ;
break;
case V_164 :
V_151 = L_50 ;
V_8 -> V_158 = 0 ;
V_8 -> V_165 = 1 ;
V_8 -> V_166 = 1 ;
break;
case V_167 :
V_151 = L_51 ;
if ( F_53 ( V_8 -> V_131 -> V_168 . V_169 )
== 0xeb1a ) {
T_1 V_170 = V_8 -> V_131 -> V_168 . V_171 ;
if ( F_53 ( V_170 ) == 0x2710 )
V_151 = L_48 ;
else if ( F_53 ( V_170 ) == 0x2820 )
V_151 = L_52 ;
}
break;
case V_172 :
V_151 = L_53 ;
break;
case V_173 :
V_151 = L_54 ;
break;
case V_174 :
V_151 = L_55 ;
V_8 -> V_158 = 0 ;
break;
case V_175 :
V_151 = L_56 ;
V_8 -> V_158 = 0 ;
V_8 -> V_166 = 1 ;
break;
case V_176 :
V_151 = L_57 ;
V_8 -> V_158 = 0 ;
V_8 -> V_166 = 1 ;
break;
case V_177 :
V_151 = L_58 ;
V_8 -> V_158 = 0 ;
V_8 -> V_166 = 1 ;
break;
case V_178 :
V_151 = L_59 ;
V_8 -> V_158 = 0 ;
break;
case V_179 :
V_151 = L_60 ;
V_8 -> V_158 = 0 ;
V_8 -> V_166 = 1 ;
break;
default:
F_54 (KERN_INFO DRIVER_NAME
L_61 , dev->chip_id) ;
}
}
if ( V_151 != V_150 )
F_54 (KERN_INFO DRIVER_NAME
L_62 , chip_name) ;
snprintf ( V_8 -> V_66 , sizeof( V_8 -> V_66 ) , L_63 , V_151 , V_8 -> V_140 ) ;
F_35 ( V_8 , V_131 ) ;
if ( V_8 -> V_120 ) {
V_149 = F_55 ( V_8 ) ;
if ( V_149 )
return - V_180 ;
F_29 ( V_8 ) ;
return 0 ;
}
F_10 ( V_8 ) ;
if ( ! V_8 -> V_15 . V_35 ) {
V_149 = F_11 ( V_8 , V_36 , V_8 -> V_15 . V_22 ) ;
if ( V_149 < 0 ) {
F_17 ( L_64
L_65 ,
V_181 , V_149 ) ;
return V_149 ;
}
}
F_56 ( & V_8 -> V_182 ) ;
if ( V_8 -> V_15 . V_35 )
V_149 = F_57 ( V_8 , 0 , V_183 ) ;
else
V_149 = F_57 ( V_8 , 0 , V_184 ) ;
if ( V_149 < 0 ) {
F_17 ( L_66 ,
V_181 , V_149 ) ;
return V_149 ;
}
if ( V_8 -> V_25 ) {
if ( V_8 -> V_165 )
V_149 = F_57 ( V_8 , 1 ,
V_185 ) ;
else
V_149 = F_57 ( V_8 , 1 ,
V_184 ) ;
if ( V_149 < 0 ) {
F_17 ( L_67 ,
V_181 , V_149 ) ;
F_44 ( V_8 , 0 ) ;
return V_149 ;
}
}
F_19 ( V_8 ) ;
return 0 ;
}
static int F_58 ( struct V_146 * V_147 ,
const struct V_186 * V_187 )
{
struct V_130 * V_131 ;
struct V_7 * V_8 = NULL ;
int V_149 ;
bool V_188 = false , V_121 = false , V_125 = false ;
int V_55 , V_189 , V_190 ;
const int V_191 = V_147 -> V_192 [ 0 ] . V_193 . V_194 ;
char * V_195 ;
V_131 = F_59 ( F_60 ( V_147 ) ) ;
do {
V_189 = F_61 ( V_141 , V_196 ) ;
if ( V_189 >= V_196 ) {
F_54 ( V_197 L_68 ,
V_196 ) ;
V_149 = - V_135 ;
goto V_198;
}
} while ( F_62 ( V_189 , V_141 ) );
if ( V_147 -> V_192 [ 0 ] . V_193 . V_199 == V_200 ) {
F_63 ( V_197 L_69
L_70 ,
F_53 ( V_131 -> V_168 . V_169 ) ,
F_53 ( V_131 -> V_168 . V_171 ) ,
V_191 ,
V_147 -> V_192 [ 0 ] . V_193 . V_199 ) ;
V_149 = - V_180 ;
goto V_201;
}
V_8 = F_37 ( sizeof( * V_8 ) , V_134 ) ;
if ( V_8 == NULL ) {
F_63 ( V_197 L_71 ) ;
V_149 = - V_135 ;
goto V_201;
}
V_8 -> V_145 =
F_64 ( sizeof( V_8 -> V_145 [ 0 ] ) *
V_147 -> V_202 , V_134 ) ;
if ( V_8 -> V_145 == NULL ) {
F_17 ( L_72 ) ;
F_25 ( V_8 ) ;
V_149 = - V_135 ;
goto V_201;
}
for ( V_55 = 0 ; V_55 < V_147 -> V_202 ; V_55 ++ ) {
int V_203 ;
for ( V_203 = 0 ; V_203 < V_147 -> V_192 [ V_55 ] . V_193 . V_204 ; V_203 ++ ) {
const struct V_205 * V_206 ;
int V_207 , V_208 ;
V_206 = & V_147 -> V_192 [ V_55 ] . V_209 [ V_203 ] . V_193 ;
V_207 = F_53 ( V_206 -> V_210 ) ;
V_208 = V_207 & 0x7ff ;
if ( V_131 -> V_195 == V_211 )
V_208 = V_208 * F_65 ( V_207 ) ;
if ( F_66 ( V_206 ) ) {
switch ( V_206 -> V_212 ) {
case 0x82 :
V_121 = true ;
if ( F_67 ( V_206 ) ) {
V_8 -> V_213 =
V_206 -> V_212 ;
V_8 -> V_145 [ V_55 ] = V_208 ;
} else if ( F_68 ( V_206 ) ) {
V_8 -> V_214 =
V_206 -> V_212 ;
}
break;
case 0x83 :
if ( F_67 ( V_206 ) ) {
V_188 = true ;
} else {
F_54 (KERN_INFO DRIVER_NAME
L_73 ) ;
}
break;
case 0x84 :
if ( V_121 &&
( F_68 ( V_206 ) ) ) {
V_8 -> V_214 =
V_206 -> V_212 ;
} else {
if ( F_67 ( V_206 ) ) {
if ( V_208 > V_8 -> V_215 ) {
V_125 = true ;
V_8 -> V_216 = V_206 -> V_212 ;
V_8 -> V_215 = V_208 ;
V_8 -> V_217 = V_55 ;
}
} else {
V_125 = true ;
V_8 -> V_218 = V_206 -> V_212 ;
}
}
break;
}
}
}
}
if ( ! ( V_188 || V_121 || V_125 ) ) {
V_149 = - V_180 ;
goto V_219;
}
switch ( V_131 -> V_195 ) {
case V_220 :
V_195 = L_74 ;
break;
case V_221 :
case V_222 :
V_195 = L_75 ;
break;
case V_211 :
V_195 = L_76 ;
break;
default:
V_195 = L_77 ;
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
if ( V_131 -> V_195 != V_211 && V_223 == 0 ) {
F_54 ( V_197 L_81 ) ;
F_54 ( V_197 L_82
L_83 ) ;
V_149 = - V_180 ;
goto V_219;
}
V_8 -> V_140 = V_189 ;
V_8 -> V_18 = V_187 -> V_224 ;
V_8 -> V_225 = - 1 ;
V_8 -> V_120 = V_188 && ! ( V_121 || V_125 ) ;
V_8 -> V_121 = V_121 ;
V_8 -> V_191 = V_191 ;
if ( V_188 ) {
F_54 (KERN_INFO DRIVER_NAME L_84 ,
ifnum, L_85 ) ;
V_8 -> V_122 = V_124 ;
}
for ( V_55 = 0 ; V_55 < V_131 -> V_226 -> V_193 . V_227 ; V_55 ++ ) {
struct V_146 * V_228 = V_131 -> V_226 -> V_147 [ V_55 ] ;
if ( V_228 -> V_192 [ 0 ] . V_193 . V_199 == V_200 ) {
if ( V_188 )
F_63 ( L_86
L_87 ) ;
V_8 -> V_122 = V_123 ;
break;
}
}
if ( V_121 )
F_54 (KERN_INFO DRIVER_NAME
L_88 ,
ifnum,
dev->analog_ep_bulk ? L_89 : L_80 ,
dev->analog_ep_isoc ? L_90 : L_80 ) ;
if ( V_125 )
F_54 (KERN_INFO DRIVER_NAME
L_91 ,
ifnum,
dev->dvb_ep_bulk ? L_89 : L_80 ,
dev->dvb_ep_isoc ? L_90 : L_80 ) ;
V_8 -> V_229 = V_147 -> V_202 ;
if ( ( unsigned ) V_230 [ V_189 ] < V_69 )
V_8 -> V_18 = V_230 [ V_189 ] ;
F_69 ( V_147 , V_8 ) ;
F_51 ( & V_8 -> V_139 ) ;
V_149 = F_50 ( V_8 , V_131 , V_147 , V_189 ) ;
if ( V_149 ) {
goto V_219;
}
if ( V_231 < 0 ) {
if ( V_8 -> V_15 . V_56 )
V_190 = 1 ;
else
V_190 = 0 ;
} else {
V_190 = V_231 > 0 ;
}
if ( V_121 &&
V_8 -> V_15 . V_232 == V_233 && ! V_8 -> V_15 . V_56 ) {
F_54 ( V_197
L_92 ) ;
V_121 = false ;
V_8 -> V_121 = false ;
}
if ( V_121 ) {
if ( ! V_8 -> V_213 || ( V_190 && V_8 -> V_214 ) )
V_8 -> V_234 = 1 ;
F_21 ( L_93 ,
V_8 -> V_234 ? L_94 : L_95 ) ;
}
if ( V_125 ) {
if ( ! V_8 -> V_216 || ( V_190 && V_8 -> V_218 ) )
V_8 -> V_235 = 1 ;
F_21 ( L_96 ,
V_8 -> V_235 ? L_94 : L_95 ) ;
}
F_70 ( & V_8 -> V_143 ) ;
F_30 ( V_8 ) ;
#ifdef F_36
V_149 = F_71 ( V_8 -> V_138 ) ;
#endif
return 0 ;
V_219:
F_25 ( V_8 -> V_145 ) ;
F_25 ( V_8 ) ;
V_201:
F_46 ( V_189 , V_141 ) ;
V_198:
F_45 ( V_131 ) ;
return V_149 ;
}
static void F_72 ( struct V_146 * V_147 )
{
struct V_7 * V_8 ;
V_8 = F_73 ( V_147 ) ;
F_69 ( V_147 , NULL ) ;
if ( ! V_8 )
return;
V_8 -> V_144 = 1 ;
F_21 ( L_97 , V_8 -> V_66 ) ;
F_33 ( V_8 ) ;
F_74 ( V_8 ) ;
F_42 ( V_8 ) ;
F_75 ( & V_8 -> V_143 , F_48 ) ;
}
static int F_76 ( struct V_146 * V_147 ,
T_2 V_236 )
{
struct V_7 * V_8 ;
V_8 = F_73 ( V_147 ) ;
if ( ! V_8 )
return 0 ;
F_77 ( V_8 ) ;
return 0 ;
}
static int F_78 ( struct V_146 * V_147 )
{
struct V_7 * V_8 ;
V_8 = F_73 ( V_147 ) ;
if ( ! V_8 )
return 0 ;
F_79 ( V_8 ) ;
return 0 ;
}
