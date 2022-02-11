static struct V_1 * F_1 ( struct V_2 * V_2 , char * V_3 ,
enum V_4 type ,
T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_1 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
V_13 = F_3 ( V_9 , V_3 , & V_10 , type , V_7 ) ;
if ( V_13 )
return F_4 ( V_13 ) ;
if ( type == V_14 && V_5 ) {
V_12 = F_5 ( V_10 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
}
return V_10 ;
}
static int F_6 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
F_7 ( F_5 ( V_10 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
enum V_4 type , T_1 * V_5 ,
struct V_6 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
int V_17 ;
V_17 = F_9 ( V_12 , type ) ;
if ( V_17 )
return V_17 ;
if ( type == V_18 &&
V_7 && V_7 -> V_19 == 0 )
F_10 ( V_12 -> V_15 . V_20 . V_21 , NULL ) ;
else if ( type == V_22 &&
V_7 && V_7 -> V_19 >= 0 )
V_12 -> V_15 . V_23 . V_19 = V_7 -> V_19 ;
if ( V_12 -> V_24 . type == V_14 && V_5 ) {
struct V_8 * V_9 = V_12 -> V_9 ;
if ( F_11 ( V_12 ) ) {
if ( ( * V_5 & V_25 ) !=
( V_12 -> V_15 . V_16 & V_25 ) )
return - V_26 ;
F_12 ( V_12 , - 1 ) ;
V_12 -> V_15 . V_16 = * V_5 ;
F_12 ( V_12 , 1 ) ;
F_13 ( V_9 ) ;
} else {
V_12 -> V_15 . V_16 = * V_5 ;
}
}
return 0 ;
}
static int F_14 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 V_27 , bool V_28 , const T_2 * V_29 ,
struct V_30 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_31 * V_21 = NULL ;
struct V_32 * V_33 ;
int V_13 ;
if ( ! F_11 ( V_12 ) )
return - V_34 ;
switch ( V_7 -> V_35 ) {
case V_36 :
case V_37 :
case V_38 :
if ( F_15 ( V_12 -> V_9 -> V_39 ) )
return - V_40 ;
break;
default:
break;
}
V_33 = F_16 ( V_7 -> V_35 , V_27 , V_7 -> V_41 ,
V_7 -> V_33 , V_7 -> V_42 , V_7 -> V_43 ) ;
if ( F_15 ( V_33 ) )
return F_17 ( V_33 ) ;
if ( V_28 )
V_33 -> V_44 . V_5 |= V_45 ;
F_18 ( & V_12 -> V_9 -> V_46 ) ;
if ( V_29 ) {
if ( F_19 ( & V_12 -> V_24 ) )
V_21 = F_20 ( V_12 , V_29 ) ;
else
V_21 = F_21 ( V_12 , V_29 ) ;
if ( ! V_21 ) {
F_22 ( V_12 -> V_9 , V_33 ) ;
V_13 = - V_47 ;
goto V_48;
}
}
V_13 = F_23 ( V_33 , V_12 , V_21 ) ;
if ( V_13 )
F_22 ( V_12 -> V_9 , V_33 ) ;
V_48:
F_24 ( & V_12 -> V_9 -> V_46 ) ;
return V_13 ;
}
static int F_25 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 V_27 , bool V_28 , const T_2 * V_29 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_31 * V_21 ;
struct V_32 * V_33 = NULL ;
int V_17 ;
F_18 ( & V_9 -> V_46 ) ;
F_18 ( & V_9 -> V_49 ) ;
if ( V_29 ) {
V_17 = - V_47 ;
V_21 = F_21 ( V_12 , V_29 ) ;
if ( ! V_21 )
goto V_48;
if ( V_28 )
V_33 = F_26 ( V_9 , V_21 -> V_50 ) ;
else
V_33 = F_26 ( V_9 , V_21 -> V_51 [ V_27 ] ) ;
} else
V_33 = F_26 ( V_9 , V_12 -> V_52 [ V_27 ] ) ;
if ( ! V_33 ) {
V_17 = - V_47 ;
goto V_48;
}
F_27 ( V_33 ) ;
V_17 = 0 ;
V_48:
F_24 ( & V_9 -> V_49 ) ;
F_24 ( & V_9 -> V_46 ) ;
return V_17 ;
}
static int F_28 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 V_27 , bool V_28 , const T_2 * V_29 ,
void * V_53 ,
void (* F_29)( void * V_53 ,
struct V_30 * V_7 ) )
{
struct V_11 * V_12 ;
struct V_31 * V_21 = NULL ;
T_2 V_43 [ 6 ] = { 0 } ;
struct V_30 V_7 ;
struct V_32 * V_33 = NULL ;
T_3 V_54 ;
T_1 V_55 ;
T_4 V_56 ;
int V_13 = - V_47 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
if ( V_29 ) {
V_21 = F_21 ( V_12 , V_29 ) ;
if ( ! V_21 )
goto V_57;
if ( V_28 )
V_33 = F_31 ( V_21 -> V_50 ) ;
else if ( V_27 < V_58 )
V_33 = F_31 ( V_21 -> V_51 [ V_27 ] ) ;
} else
V_33 = F_31 ( V_12 -> V_52 [ V_27 ] ) ;
if ( ! V_33 )
goto V_57;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_35 = V_33 -> V_44 . V_35 ;
switch ( V_33 -> V_44 . V_35 ) {
case V_37 :
V_55 = V_33 -> V_15 . V_59 . V_60 . V_55 ;
V_56 = V_33 -> V_15 . V_59 . V_60 . V_56 ;
if ( V_33 -> V_5 & V_61 )
F_32 ( V_12 -> V_9 ,
V_33 -> V_44 . V_62 ,
& V_55 , & V_56 ) ;
V_43 [ 0 ] = V_56 & 0xff ;
V_43 [ 1 ] = ( V_56 >> 8 ) & 0xff ;
V_43 [ 2 ] = V_55 & 0xff ;
V_43 [ 3 ] = ( V_55 >> 8 ) & 0xff ;
V_43 [ 4 ] = ( V_55 >> 16 ) & 0xff ;
V_43 [ 5 ] = ( V_55 >> 24 ) & 0xff ;
V_7 . V_43 = V_43 ;
V_7 . V_42 = 6 ;
break;
case V_63 :
V_54 = F_33 ( & V_33 -> V_15 . V_64 . V_65 ) ;
V_43 [ 0 ] = V_54 ;
V_43 [ 1 ] = V_54 >> 8 ;
V_43 [ 2 ] = V_54 >> 16 ;
V_43 [ 3 ] = V_54 >> 24 ;
V_43 [ 4 ] = V_54 >> 32 ;
V_43 [ 5 ] = V_54 >> 40 ;
V_7 . V_43 = V_43 ;
V_7 . V_42 = 6 ;
break;
case V_66 :
V_54 = F_33 ( & V_33 -> V_15 . V_67 . V_65 ) ;
V_43 [ 0 ] = V_54 ;
V_43 [ 1 ] = V_54 >> 8 ;
V_43 [ 2 ] = V_54 >> 16 ;
V_43 [ 3 ] = V_54 >> 24 ;
V_43 [ 4 ] = V_54 >> 32 ;
V_43 [ 5 ] = V_54 >> 40 ;
V_7 . V_43 = V_43 ;
V_7 . V_42 = 6 ;
break;
}
V_7 . V_33 = V_33 -> V_44 . V_33 ;
V_7 . V_41 = V_33 -> V_44 . V_68 ;
F_29 ( V_53 , & V_7 ) ;
V_13 = 0 ;
V_57:
F_34 () ;
return V_13 ;
}
static int F_35 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_27 , bool V_69 ,
bool V_70 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_36 ( V_12 , V_27 , V_69 , V_70 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_27 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_38 ( V_12 , V_27 ) ;
return 0 ;
}
static void F_39 ( struct V_71 * V_72 , struct V_31 * V_21 , int V_73 )
{
if ( ! ( V_72 -> V_5 & V_74 ) ) {
struct V_75 * V_76 ;
V_76 = V_21 -> V_9 -> V_77 . V_2 -> V_78 [
V_21 -> V_9 -> V_77 . V_44 . V_79 -> V_80 ] ;
V_72 -> V_81 = V_76 -> V_82 [ V_73 ] . V_83 ;
} else
V_72 -> V_84 = V_73 ;
}
static void F_40 ( struct V_31 * V_21 , struct V_85 * V_86 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_87 V_88 ;
V_86 -> V_89 = V_12 -> V_9 -> V_90 ;
V_86 -> V_91 = V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 |
V_100 |
V_101 |
V_102 |
V_103 |
V_104 ;
F_41 ( & V_88 ) ;
V_86 -> V_105 = V_88 . V_106 - V_21 -> V_107 ;
V_86 -> V_108 = F_42 ( V_109 - V_21 -> V_110 ) ;
V_86 -> V_111 = V_21 -> V_111 ;
V_86 -> V_112 = V_21 -> V_112 ;
V_86 -> V_113 = V_21 -> V_113 ;
V_86 -> V_114 = V_21 -> V_114 ;
V_86 -> V_115 = V_21 -> V_116 ;
V_86 -> V_117 = V_21 -> V_118 ;
V_86 -> V_119 = V_21 -> V_120 ;
if ( ( V_21 -> V_9 -> V_77 . V_5 & V_121 ) ||
( V_21 -> V_9 -> V_77 . V_5 & V_122 ) ) {
V_86 -> V_91 |= V_123 | V_124 ;
V_86 -> signal = ( V_125 ) V_21 -> V_126 ;
V_86 -> V_127 = ( V_125 ) - F_43 ( & V_21 -> V_128 ) ;
}
V_86 -> V_129 . V_5 = 0 ;
if ( V_21 -> V_130 . V_5 & V_131 )
V_86 -> V_129 . V_5 |= V_74 ;
if ( V_21 -> V_130 . V_5 & V_132 )
V_86 -> V_129 . V_5 |= V_133 ;
if ( V_21 -> V_130 . V_5 & V_134 )
V_86 -> V_129 . V_5 |= V_135 ;
F_39 ( & V_86 -> V_129 , V_21 , V_21 -> V_130 . V_73 ) ;
V_86 -> V_136 . V_5 = 0 ;
if ( V_21 -> V_137 & V_138 )
V_86 -> V_136 . V_5 |= V_74 ;
if ( V_21 -> V_137 & V_139 )
V_86 -> V_136 . V_5 |= V_133 ;
if ( V_21 -> V_137 & V_140 )
V_86 -> V_136 . V_5 |= V_135 ;
F_39 ( & V_86 -> V_136 , V_21 , V_21 -> V_141 ) ;
if ( F_19 ( & V_12 -> V_24 ) ) {
#ifdef F_44
V_86 -> V_91 |= V_142 |
V_143 |
V_144 ;
V_86 -> V_145 = F_45 ( V_21 -> V_145 ) ;
V_86 -> V_146 = F_45 ( V_21 -> V_146 ) ;
V_86 -> V_147 = V_21 -> V_147 ;
#endif
}
V_86 -> V_148 . V_5 = 0 ;
if ( V_12 -> V_24 . V_149 . V_150 )
V_86 -> V_148 . V_5 |= V_151 ;
if ( V_12 -> V_24 . V_149 . V_152 )
V_86 -> V_148 . V_5 |= V_153 ;
if ( V_12 -> V_24 . V_149 . V_154 )
V_86 -> V_148 . V_5 |= V_155 ;
V_86 -> V_148 . V_156 = V_12 -> V_9 -> V_77 . V_44 . V_157 ;
V_86 -> V_148 . V_158 = V_12 -> V_24 . V_149 . V_159 ;
V_86 -> V_160 . V_161 = 0 ;
V_86 -> V_160 . V_162 = F_46 ( V_163 ) |
F_46 ( V_164 ) |
F_46 ( V_165 ) |
F_46 ( V_166 ) |
F_46 ( V_167 ) ;
if ( F_47 ( V_21 , V_168 ) )
V_86 -> V_160 . V_161 |= F_46 ( V_163 ) ;
if ( F_47 ( V_21 , V_169 ) )
V_86 -> V_160 . V_161 |= F_46 ( V_164 ) ;
if ( F_47 ( V_21 , V_170 ) )
V_86 -> V_160 . V_161 |= F_46 ( V_165 ) ;
if ( F_47 ( V_21 , V_171 ) )
V_86 -> V_160 . V_161 |= F_46 ( V_166 ) ;
if ( F_47 ( V_21 , V_172 ) )
V_86 -> V_160 . V_161 |= F_46 ( V_167 ) ;
}
static int F_48 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_73 , T_2 * V_173 , struct V_85 * V_86 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_31 * V_21 ;
int V_17 = - V_47 ;
F_30 () ;
V_21 = F_49 ( V_12 , V_73 ) ;
if ( V_21 ) {
V_17 = 0 ;
memcpy ( V_173 , V_21 -> V_21 . V_174 , V_175 ) ;
F_40 ( V_21 , V_86 ) ;
}
F_34 () ;
return V_17 ;
}
static int F_50 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_73 , struct V_176 * V_177 )
{
struct V_8 * V_9 = F_51 ( V_10 -> V_178 ) ;
return F_52 ( V_9 , V_73 , V_177 ) ;
}
static int F_53 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_173 , struct V_85 * V_86 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_31 * V_21 ;
int V_17 = - V_47 ;
F_30 () ;
V_21 = F_21 ( V_12 , V_173 ) ;
if ( V_21 ) {
V_17 = 0 ;
F_40 ( V_21 , V_86 ) ;
}
F_34 () ;
return V_17 ;
}
static void F_54 ( struct V_11 * V_12 ,
struct V_179 * V_7 )
{
struct V_180 * V_149 = & V_12 -> V_24 . V_149 ;
V_149 -> V_181 = V_7 -> V_181 ;
if ( V_7 -> V_181 )
memcpy ( V_149 -> V_182 , V_7 -> V_182 , V_7 -> V_181 ) ;
V_149 -> V_183 =
( V_7 -> V_183 != V_184 ) ;
}
static int F_55 ( struct V_11 * V_12 ,
struct V_179 * V_7 )
{
struct V_185 * V_186 , * V_187 ;
int V_188 , V_189 ;
int V_190 ;
int V_13 = - V_40 ;
V_187 = F_56 ( V_12 -> V_15 . V_191 . V_192 ) ;
if ( V_7 -> V_193 && ! V_7 -> V_194 )
return - V_40 ;
if ( V_7 -> V_195 &&
( V_12 -> V_24 . V_149 . V_159 != V_7 -> V_195 ) ) {
V_12 -> V_24 . V_149 . V_159 = V_7 -> V_195 ;
F_57 ( V_12 ,
V_196 ) ;
}
if ( ! V_7 -> V_193 && ! V_187 )
return V_13 ;
if ( ! V_7 -> V_156 && ! V_187 )
return V_13 ;
if ( V_7 -> V_193 )
V_188 = V_7 -> V_194 ;
else
V_188 = V_187 -> V_194 ;
if ( V_7 -> V_197 || ! V_187 )
V_189 = V_7 -> V_198 ;
else
V_189 = V_187 -> V_198 ;
V_190 = sizeof( * V_186 ) + V_188 + V_189 ;
V_186 = F_58 ( V_190 , V_199 ) ;
if ( ! V_186 )
return - V_200 ;
if ( V_7 -> V_156 )
V_186 -> V_156 = V_7 -> V_156 ;
else
V_186 -> V_156 = V_187 -> V_156 ;
V_186 -> V_193 = ( ( T_2 * ) V_186 ) + sizeof( * V_186 ) ;
V_186 -> V_197 = V_186 -> V_193 + V_188 ;
V_186 -> V_194 = V_188 ;
V_186 -> V_198 = V_189 ;
if ( V_7 -> V_193 )
memcpy ( V_186 -> V_193 , V_7 -> V_193 , V_188 ) ;
else
memcpy ( V_186 -> V_193 , V_187 -> V_193 , V_188 ) ;
if ( V_7 -> V_197 )
memcpy ( V_186 -> V_197 , V_7 -> V_197 , V_189 ) ;
else
if ( V_187 )
memcpy ( V_186 -> V_197 , V_187 -> V_197 , V_189 ) ;
V_12 -> V_24 . V_149 . V_156 = V_186 -> V_156 ;
F_10 ( V_12 -> V_15 . V_191 . V_192 , V_186 ) ;
F_59 () ;
F_60 ( V_187 ) ;
F_54 ( V_12 , V_7 ) ;
F_57 ( V_12 , V_201 |
V_202 |
V_203 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_179 * V_7 )
{
struct V_11 * V_12 ;
struct V_185 * V_187 ;
V_12 = F_5 ( V_10 ) ;
V_187 = F_56 ( V_12 -> V_15 . V_191 . V_192 ) ;
if ( V_187 )
return - V_204 ;
return F_55 ( V_12 , V_7 ) ;
}
static int F_62 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_179 * V_7 )
{
struct V_11 * V_12 ;
struct V_185 * V_187 ;
V_12 = F_5 ( V_10 ) ;
V_187 = F_56 ( V_12 -> V_15 . V_191 . V_192 ) ;
if ( ! V_187 )
return - V_47 ;
return F_55 ( V_12 , V_7 ) ;
}
static int F_63 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 ;
struct V_185 * V_187 ;
V_12 = F_5 ( V_10 ) ;
V_187 = F_56 ( V_12 -> V_15 . V_191 . V_192 ) ;
if ( ! V_187 )
return - V_47 ;
F_10 ( V_12 -> V_15 . V_191 . V_192 , NULL ) ;
F_59 () ;
F_60 ( V_187 ) ;
F_57 ( V_12 , V_201 ) ;
return 0 ;
}
static void F_64 ( struct V_31 * V_21 )
{
struct V_205 * V_206 ;
struct V_207 * V_208 ;
V_208 = F_65 ( sizeof( * V_206 ) ) ;
if ( ! V_208 )
return;
V_206 = (struct V_205 * ) F_66 ( V_208 , sizeof( * V_206 ) ) ;
memset ( V_206 -> V_209 , 0xff , V_175 ) ;
memcpy ( V_206 -> V_210 , V_21 -> V_21 . V_174 , V_175 ) ;
V_206 -> V_211 = F_67 ( 6 ) ;
V_206 -> V_212 = 0 ;
V_206 -> V_213 = 0x01 ;
V_206 -> V_214 = 0xaf ;
V_206 -> V_215 [ 0 ] = 0x81 ;
V_206 -> V_215 [ 1 ] = 1 ;
V_206 -> V_215 [ 2 ] = 0 ;
V_208 -> V_10 = V_21 -> V_12 -> V_10 ;
V_208 -> V_216 = F_68 ( V_208 , V_21 -> V_12 -> V_10 ) ;
memset ( V_208 -> V_217 , 0 , sizeof( V_208 -> V_217 ) ) ;
F_69 ( V_208 ) ;
}
static void F_70 ( struct V_8 * V_9 ,
struct V_31 * V_21 ,
struct V_218 * V_7 )
{
T_1 V_219 ;
int V_220 , V_221 ;
struct V_75 * V_76 ;
struct V_11 * V_12 = V_21 -> V_12 ;
T_1 V_162 , V_161 ;
V_76 = V_9 -> V_77 . V_2 -> V_78 [ V_9 -> V_222 -> V_80 ] ;
V_162 = V_7 -> V_223 ;
V_161 = V_7 -> V_224 ;
if ( V_162 & F_46 ( V_163 ) ) {
if ( V_161 & F_46 ( V_163 ) )
F_71 ( V_21 , V_168 ) ;
else
F_72 ( V_21 , V_168 ) ;
}
if ( V_162 & F_46 ( V_164 ) ) {
if ( V_161 & F_46 ( V_164 ) )
F_71 ( V_21 , V_169 ) ;
else
F_72 ( V_21 , V_169 ) ;
}
if ( V_162 & F_46 ( V_165 ) ) {
if ( V_161 & F_46 ( V_165 ) ) {
F_71 ( V_21 , V_170 ) ;
V_21 -> V_21 . V_225 = true ;
} else {
F_72 ( V_21 , V_170 ) ;
V_21 -> V_21 . V_225 = false ;
}
}
if ( V_162 & F_46 ( V_166 ) ) {
if ( V_161 & F_46 ( V_166 ) )
F_71 ( V_21 , V_171 ) ;
else
F_72 ( V_21 , V_171 ) ;
}
if ( V_162 & F_46 ( V_167 ) ) {
if ( V_161 & F_46 ( V_167 ) )
F_71 ( V_21 , V_172 ) ;
else
F_72 ( V_21 , V_172 ) ;
}
if ( V_162 & F_46 ( V_226 ) ) {
if ( V_161 & F_46 ( V_226 ) )
F_71 ( V_21 , V_227 ) ;
else
F_72 ( V_21 , V_227 ) ;
}
if ( V_7 -> V_228 & V_229 ) {
V_21 -> V_21 . V_230 = V_7 -> V_230 ;
V_21 -> V_21 . V_231 = V_7 -> V_231 ;
}
if ( V_7 -> V_232 )
V_21 -> V_21 . V_232 = V_7 -> V_232 ;
if ( V_7 -> V_233 >= 0 )
V_21 -> V_233 = V_7 -> V_233 ;
if ( V_7 -> V_234 ) {
V_219 = 0 ;
for ( V_220 = 0 ; V_220 < V_7 -> V_235 ; V_220 ++ ) {
int V_72 = ( V_7 -> V_234 [ V_220 ] & 0x7f ) * 5 ;
for ( V_221 = 0 ; V_221 < V_76 -> V_236 ; V_221 ++ ) {
if ( V_76 -> V_82 [ V_221 ] . V_83 == V_72 )
V_219 |= F_46 ( V_221 ) ;
}
}
V_21 -> V_21 . V_237 [ V_9 -> V_222 -> V_80 ] = V_219 ;
}
if ( V_7 -> V_238 )
F_73 ( V_76 ,
V_7 -> V_238 ,
& V_21 -> V_21 . V_239 ) ;
if ( F_19 ( & V_12 -> V_24 ) ) {
#ifdef F_44
if ( V_12 -> V_15 . V_240 . V_241 & V_242 )
switch ( V_7 -> V_147 ) {
case V_243 :
case V_244 :
case V_245 :
V_21 -> V_147 = V_7 -> V_147 ;
break;
default:
break;
}
else
switch ( V_7 -> V_246 ) {
case V_247 :
F_74 ( V_21 ) ;
break;
case V_248 :
F_75 ( V_21 ) ;
break;
}
#endif
}
}
static int F_76 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_173 , struct V_218 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_31 * V_21 ;
struct V_11 * V_12 ;
int V_13 ;
int V_249 ;
if ( V_7 -> V_20 ) {
V_12 = F_5 ( V_7 -> V_20 ) ;
if ( V_12 -> V_24 . type != V_18 &&
V_12 -> V_24 . type != V_250 )
return - V_40 ;
} else
V_12 = F_5 ( V_10 ) ;
if ( F_77 ( V_173 , V_12 -> V_24 . V_174 ) == 0 )
return - V_40 ;
if ( F_78 ( V_173 ) )
return - V_40 ;
if ( ( V_7 -> V_224 & F_46 ( V_226 ) ) &&
! ( ( V_2 -> V_5 & V_251 ) &&
V_12 -> V_24 . type == V_22 ) )
return - V_252 ;
V_21 = F_79 ( V_12 , V_173 , V_199 ) ;
if ( ! V_21 )
return - V_200 ;
F_71 ( V_21 , V_172 ) ;
F_71 ( V_21 , V_253 ) ;
F_70 ( V_9 , V_21 , V_7 ) ;
F_80 ( V_21 ) ;
V_249 = V_12 -> V_24 . type == V_18 ||
V_12 -> V_24 . type == V_250 ;
V_13 = F_81 ( V_21 ) ;
if ( V_13 ) {
F_34 () ;
return V_13 ;
}
if ( V_249 )
F_64 ( V_21 ) ;
F_34 () ;
return 0 ;
}
static int F_82 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_173 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_173 )
return F_83 ( V_12 , V_173 ) ;
F_84 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 * V_173 ,
struct V_218 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_31 * V_21 ;
struct V_11 * V_254 ;
F_30 () ;
V_21 = F_21 ( V_12 , V_173 ) ;
if ( ! V_21 ) {
F_34 () ;
return - V_47 ;
}
if ( ( V_7 -> V_223 & F_46 ( V_226 ) ) &&
! ! ( V_7 -> V_224 & F_46 ( V_226 ) ) !=
! ! F_47 ( V_21 , V_227 ) ) {
F_34 () ;
return - V_40 ;
}
if ( V_7 -> V_20 && V_7 -> V_20 != V_21 -> V_12 -> V_10 ) {
V_254 = F_5 ( V_7 -> V_20 ) ;
if ( V_254 -> V_24 . type != V_18 &&
V_254 -> V_24 . type != V_250 ) {
F_34 () ;
return - V_40 ;
}
if ( V_7 -> V_20 -> V_178 -> V_19 ) {
if ( V_254 -> V_15 . V_20 . V_21 ) {
F_34 () ;
return - V_26 ;
}
F_10 ( V_254 -> V_15 . V_20 . V_21 , V_21 ) ;
}
V_21 -> V_12 = V_254 ;
F_64 ( V_21 ) ;
}
F_70 ( V_9 , V_21 , V_7 ) ;
F_34 () ;
if ( V_12 -> V_24 . type == V_22 &&
V_7 -> V_223 & F_46 ( V_163 ) )
F_86 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_87 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_255 , T_2 * V_256 )
{
struct V_11 * V_12 ;
struct V_257 * V_258 ;
struct V_31 * V_21 ;
int V_13 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_21 = F_20 ( V_12 , V_256 ) ;
if ( ! V_21 ) {
F_34 () ;
return - V_47 ;
}
V_13 = F_88 ( V_255 , V_12 ) ;
if ( V_13 ) {
F_34 () ;
return V_13 ;
}
V_258 = F_89 ( V_255 , V_12 ) ;
if ( ! V_258 ) {
F_34 () ;
return - V_259 ;
}
F_90 ( V_258 , V_21 ) ;
F_34 () ;
return 0 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_255 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( V_255 )
return F_92 ( V_255 , V_12 ) ;
F_93 ( V_12 ) ;
return 0 ;
}
static int F_94 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 * V_255 , T_2 * V_256 )
{
struct V_11 * V_12 ;
struct V_257 * V_258 ;
struct V_31 * V_21 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_21 = F_20 ( V_12 , V_256 ) ;
if ( ! V_21 ) {
F_34 () ;
return - V_47 ;
}
V_258 = F_89 ( V_255 , V_12 ) ;
if ( ! V_258 ) {
F_34 () ;
return - V_47 ;
}
F_90 ( V_258 , V_21 ) ;
F_34 () ;
return 0 ;
}
static void F_95 ( struct V_257 * V_258 , T_2 * V_256 ,
struct V_260 * V_261 )
{
struct V_31 * V_262 = F_31 ( V_258 -> V_256 ) ;
if ( V_262 )
memcpy ( V_256 , V_262 -> V_21 . V_174 , V_175 ) ;
else
memset ( V_256 , 0 , V_175 ) ;
V_261 -> V_89 = V_263 ;
V_261 -> V_91 = V_264 |
V_265 |
V_266 |
V_267 |
V_268 |
V_269 |
V_270 ;
V_261 -> V_271 = V_258 -> V_272 . V_273 ;
V_261 -> V_274 = V_258 -> V_274 ;
V_261 -> V_275 = V_258 -> V_275 ;
if ( F_96 ( V_109 , V_258 -> V_276 ) )
V_261 -> V_277 = F_42 ( V_258 -> V_276 - V_109 ) ;
V_261 -> V_278 =
F_42 ( V_258 -> V_278 ) ;
V_261 -> V_279 = V_258 -> V_279 ;
V_261 -> V_5 = 0 ;
if ( V_258 -> V_5 & V_280 )
V_261 -> V_5 |= V_281 ;
if ( V_258 -> V_5 & V_282 )
V_261 -> V_5 |= V_283 ;
if ( V_258 -> V_5 & V_284 )
V_261 -> V_5 |= V_285 ;
if ( V_258 -> V_5 & V_286 )
V_261 -> V_5 |= V_287 ;
if ( V_258 -> V_5 & V_282 )
V_261 -> V_5 |= V_283 ;
V_261 -> V_5 = V_258 -> V_5 ;
}
static int F_97 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_255 , T_2 * V_256 , struct V_260 * V_261 )
{
struct V_11 * V_12 ;
struct V_257 * V_258 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_258 = F_89 ( V_255 , V_12 ) ;
if ( ! V_258 ) {
F_34 () ;
return - V_47 ;
}
memcpy ( V_255 , V_258 -> V_255 , V_175 ) ;
F_95 ( V_258 , V_256 , V_261 ) ;
F_34 () ;
return 0 ;
}
static int F_98 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_73 , T_2 * V_255 , T_2 * V_256 ,
struct V_260 * V_261 )
{
struct V_11 * V_12 ;
struct V_257 * V_258 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_258 = F_99 ( V_73 , V_12 ) ;
if ( ! V_258 ) {
F_34 () ;
return - V_47 ;
}
memcpy ( V_255 , V_258 -> V_255 , V_175 ) ;
F_95 ( V_258 , V_256 , V_261 ) ;
F_34 () ;
return 0 ;
}
static int F_100 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_288 * V_44 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
memcpy ( V_44 , & ( V_12 -> V_15 . V_240 . V_289 ) , sizeof( struct V_288 ) ) ;
return 0 ;
}
static inline bool F_101 ( enum V_290 V_291 , T_1 V_162 )
{
return ( V_162 >> ( V_291 - 1 ) ) & 0x1 ;
}
static int F_102 ( struct V_292 * V_293 ,
const struct V_294 * V_295 )
{
T_2 * V_296 ;
const T_2 * V_297 ;
V_296 = NULL ;
V_297 = V_293 -> V_298 ;
if ( V_295 -> V_299 ) {
V_296 = F_103 ( V_295 -> V_298 , V_295 -> V_299 ,
V_199 ) ;
if ( ! V_296 )
return - V_200 ;
}
V_293 -> V_299 = V_295 -> V_299 ;
V_293 -> V_298 = V_296 ;
F_60 ( V_297 ) ;
V_293 -> V_300 = V_295 -> V_300 ;
memcpy ( V_293 -> V_301 , V_295 -> V_301 , V_293 -> V_300 ) ;
V_293 -> V_302 = V_295 -> V_303 ;
V_293 -> V_304 = V_295 -> V_305 ;
V_293 -> V_241 = V_306 ;
if ( V_295 -> V_307 )
V_293 -> V_241 |= V_308 ;
if ( V_295 -> V_309 )
V_293 -> V_241 |= V_242 ;
return 0 ;
}
static int F_104 ( struct V_2 * V_2 ,
struct V_1 * V_10 , T_1 V_162 ,
const struct V_288 * V_310 )
{
struct V_288 * V_44 ;
struct V_11 * V_12 ;
struct V_292 * V_293 ;
V_12 = F_5 ( V_10 ) ;
V_293 = & V_12 -> V_15 . V_240 ;
V_44 = & ( V_12 -> V_15 . V_240 . V_289 ) ;
if ( F_101 ( V_311 , V_162 ) )
V_44 -> V_312 = V_310 -> V_312 ;
if ( F_101 ( V_313 , V_162 ) )
V_44 -> V_314 = V_310 -> V_314 ;
if ( F_101 ( V_315 , V_162 ) )
V_44 -> V_316 = V_310 -> V_316 ;
if ( F_101 ( V_317 , V_162 ) )
V_44 -> V_318 = V_310 -> V_318 ;
if ( F_101 ( V_319 , V_162 ) )
V_44 -> V_320 = V_310 -> V_320 ;
if ( F_101 ( V_321 , V_162 ) )
V_44 -> V_322 = V_310 -> V_322 ;
if ( F_101 ( V_323 , V_162 ) )
V_44 -> V_322 = V_310 -> V_324 ;
if ( F_101 ( V_325 , V_162 ) )
V_44 -> V_326 = V_310 -> V_326 ;
if ( F_101 ( V_327 , V_162 ) )
V_44 -> V_328 =
V_310 -> V_328 ;
if ( F_101 ( V_329 , V_162 ) )
V_44 -> V_330 = V_310 -> V_330 ;
if ( F_101 ( V_331 , V_162 ) )
V_44 -> V_332 = V_310 -> V_332 ;
if ( F_101 ( V_333 , V_162 ) )
V_44 -> V_334 =
V_310 -> V_334 ;
if ( F_101 ( V_335 , V_162 ) )
V_44 -> V_336 =
V_310 -> V_336 ;
if ( F_101 ( V_337 ,
V_162 ) )
V_44 -> V_338 =
V_310 -> V_338 ;
if ( F_101 ( V_339 , V_162 ) ) {
V_44 -> V_340 = V_310 -> V_340 ;
F_105 ( V_293 ) ;
}
if ( F_101 ( V_341 , V_162 ) ) {
if ( V_310 -> V_342 &&
! V_44 -> V_340 ) {
V_44 -> V_340 = 1 ;
F_105 ( V_293 ) ;
}
V_44 -> V_342 =
V_310 -> V_342 ;
}
if ( F_101 ( V_343 , V_162 ) ) {
V_44 -> V_344 =
V_310 -> V_344 ;
}
return 0 ;
}
static int F_106 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const struct V_288 * V_44 ,
const struct V_294 * V_295 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_292 * V_293 = & V_12 -> V_15 . V_240 ;
int V_13 ;
memcpy ( & V_293 -> V_289 , V_44 , sizeof( struct V_288 ) ) ;
V_13 = F_102 ( V_293 , V_295 ) ;
if ( V_13 )
return V_13 ;
F_107 ( V_12 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_109 ( V_12 ) ;
return 0 ;
}
static int F_110 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_345 * V_7 )
{
struct V_11 * V_12 ;
T_1 V_346 = 0 ;
V_12 = F_5 ( V_10 ) ;
if ( V_7 -> V_150 >= 0 ) {
V_12 -> V_24 . V_149 . V_150 = V_7 -> V_150 ;
V_346 |= V_347 ;
}
if ( V_7 -> V_152 >= 0 ) {
V_12 -> V_24 . V_149 . V_152 =
V_7 -> V_152 ;
V_346 |= V_348 ;
}
if ( ! V_12 -> V_24 . V_149 . V_154 &&
V_12 -> V_9 -> V_77 . V_44 . V_79 -> V_80 == V_349 ) {
V_12 -> V_24 . V_149 . V_154 = true ;
V_346 |= V_350 ;
}
if ( V_7 -> V_351 >= 0 ) {
V_12 -> V_24 . V_149 . V_154 =
V_7 -> V_351 ;
V_346 |= V_350 ;
}
if ( V_7 -> V_352 ) {
int V_220 , V_221 ;
T_1 V_219 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_75 * V_76 =
V_2 -> V_78 [ V_9 -> V_222 -> V_80 ] ;
for ( V_220 = 0 ; V_220 < V_7 -> V_353 ; V_220 ++ ) {
int V_72 = ( V_7 -> V_352 [ V_220 ] & 0x7f ) * 5 ;
for ( V_221 = 0 ; V_221 < V_76 -> V_236 ; V_221 ++ ) {
if ( V_76 -> V_82 [ V_221 ] . V_83 == V_72 )
V_219 |= F_46 ( V_221 ) ;
}
}
V_12 -> V_24 . V_149 . V_352 = V_219 ;
V_346 |= V_354 ;
}
if ( V_7 -> V_355 >= 0 ) {
if ( V_7 -> V_355 )
V_12 -> V_5 |= V_356 ;
else
V_12 -> V_5 &= ~ V_356 ;
}
if ( V_7 -> V_357 >= 0 ) {
V_12 -> V_24 . V_149 . V_358 =
( T_4 ) V_7 -> V_357 ;
V_346 |= V_359 ;
}
F_57 ( V_12 , V_346 ) ;
return 0 ;
}
static int F_111 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_360 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_361 V_362 ;
if ( ! V_9 -> V_363 -> V_364 )
return - V_365 ;
memset ( & V_362 , 0 , sizeof( V_362 ) ) ;
V_362 . V_366 = V_7 -> V_366 ;
V_362 . V_367 = V_7 -> V_368 ;
V_362 . V_369 = V_7 -> V_370 ;
V_362 . V_371 = V_7 -> V_371 ;
V_362 . V_372 = false ;
if ( V_7 -> V_373 >= V_9 -> V_77 . V_374 )
return - V_40 ;
V_12 -> V_375 [ V_7 -> V_373 ] = V_362 ;
if ( F_112 ( V_9 , V_12 , V_7 -> V_373 , & V_362 ) ) {
F_113 ( V_9 -> V_77 . V_2 ,
L_1 ,
V_7 -> V_373 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_114 ( struct V_2 * V_2 ,
struct V_1 * V_376 ,
struct V_377 * V_378 ,
enum V_379 V_380 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = NULL ;
struct V_377 * V_381 ;
enum V_379 V_382 ;
enum V_379 V_383 = V_384 ;
if ( V_376 )
V_12 = F_5 ( V_376 ) ;
switch ( F_115 ( V_9 , NULL ) ) {
case V_385 :
return - V_26 ;
case V_386 :
if ( V_9 -> V_222 != V_378 )
return - V_26 ;
if ( ! V_12 && V_9 -> V_387 == V_380 )
return 0 ;
break;
case V_388 :
break;
}
if ( V_12 )
V_383 = V_12 -> V_24 . V_149 . V_380 ;
V_382 = V_9 -> V_387 ;
if ( ! F_116 ( V_9 , V_12 , V_380 ) )
return - V_26 ;
V_381 = V_9 -> V_222 ;
V_9 -> V_222 = V_378 ;
if ( ( V_381 != V_9 -> V_222 ) ||
( V_382 != V_9 -> V_387 ) )
F_117 ( V_9 , V_389 ) ;
if ( ( V_12 && V_12 -> V_24 . type != V_14 ) &&
V_383 != V_12 -> V_24 . V_149 . V_380 )
F_57 ( V_12 , V_359 ) ;
return 0 ;
}
static int F_118 ( struct V_2 * V_2 ,
struct V_390 * V_391 )
{
return F_119 ( F_2 ( V_2 ) , V_391 ) ;
}
static int F_120 ( struct V_2 * V_2 )
{
return F_121 ( F_2 ( V_2 ) ) ;
}
static int F_122 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_392 * V_393 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_123 ( & V_12 -> V_24 ) ) {
case V_22 :
case V_394 :
case V_395 :
case V_396 :
break;
case V_397 :
if ( V_12 -> V_9 -> V_363 -> V_398 )
break;
case V_250 :
if ( V_12 -> V_15 . V_191 . V_192 )
return - V_365 ;
break;
default:
return - V_365 ;
}
return F_124 ( V_12 , V_393 ) ;
}
static int
F_125 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_399 * V_393 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_363 -> V_400 )
return - V_365 ;
return F_126 ( V_12 , V_393 ) ;
}
static int
F_127 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_363 -> V_401 )
return - V_365 ;
return F_128 ( V_12 ) ;
}
static int F_129 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_402 * V_393 )
{
return F_130 ( F_5 ( V_10 ) , V_393 ) ;
}
static int F_131 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_403 * V_393 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_115 ( V_9 , V_12 ) ) {
case V_385 :
return - V_26 ;
case V_386 :
if ( V_9 -> V_222 == V_393 -> V_404 -> V_79 )
break;
return - V_26 ;
case V_388 :
break;
}
return F_132 ( F_5 ( V_10 ) , V_393 ) ;
}
static int F_133 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_405 * V_393 ,
void * V_53 )
{
return F_134 ( F_5 ( V_10 ) ,
V_393 , V_53 ) ;
}
static int F_135 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_406 * V_393 ,
void * V_53 )
{
return F_136 ( F_5 ( V_10 ) ,
V_393 , V_53 ) ;
}
static int F_137 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_407 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_115 ( V_9 , V_12 ) ) {
case V_385 :
return - V_26 ;
case V_386 :
if ( ! V_7 -> V_408 )
return - V_26 ;
if ( V_9 -> V_222 == V_7 -> V_79 )
break;
return - V_26 ;
case V_388 :
break;
}
return F_138 ( V_12 , V_7 ) ;
}
static int F_139 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
return F_140 ( V_12 ) ;
}
static int F_141 ( struct V_2 * V_2 , T_1 V_346 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_346 & V_409 ) {
V_13 = F_142 ( V_9 , V_2 -> V_410 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_346 & V_411 ) {
V_13 = F_143 ( V_9 , V_2 -> V_412 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_346 & V_413 ) {
V_13 = F_144 ( V_9 , V_2 -> V_414 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_346 & V_415 )
V_9 -> V_77 . V_44 . V_416 = V_2 -> V_417 ;
if ( V_346 & V_418 )
V_9 -> V_77 . V_44 . V_419 = V_2 -> V_420 ;
if ( V_346 &
( V_415 | V_418 ) )
F_117 ( V_9 , V_421 ) ;
return 0 ;
}
static int F_145 ( struct V_2 * V_2 ,
enum V_422 type , int V_423 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_377 * V_378 = V_9 -> V_77 . V_44 . V_79 ;
T_1 V_424 = 0 ;
switch ( type ) {
case V_425 :
V_9 -> V_426 = - 1 ;
break;
case V_427 :
if ( V_423 < 0 || ( V_423 % 100 ) )
return - V_365 ;
V_9 -> V_426 = F_146 ( V_423 ) ;
break;
case V_428 :
if ( V_423 < 0 || ( V_423 % 100 ) )
return - V_365 ;
if ( F_146 ( V_423 ) > V_378 -> V_429 )
return - V_40 ;
V_9 -> V_426 = F_146 ( V_423 ) ;
break;
}
F_117 ( V_9 , V_424 ) ;
return 0 ;
}
static int F_147 ( struct V_2 * V_2 , int * V_430 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_430 = V_9 -> V_77 . V_44 . V_431 ;
return 0 ;
}
static int F_148 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const T_2 * V_174 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
memcpy ( & V_12 -> V_15 . V_432 . V_433 , V_174 , V_175 ) ;
return 0 ;
}
static void F_149 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_150 ( V_9 ) ;
}
static int F_151 ( struct V_2 * V_2 , void * V_434 , int V_211 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_363 -> V_435 )
return - V_365 ;
return V_9 -> V_363 -> V_435 ( & V_9 -> V_77 , V_434 , V_211 ) ;
}
static int F_152 ( struct V_2 * V_2 ,
struct V_207 * V_208 ,
struct V_436 * V_217 ,
void * V_434 , int V_211 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_363 -> V_437 )
return - V_365 ;
return V_9 -> V_363 -> V_437 ( & V_9 -> V_77 , V_208 , V_217 , V_434 , V_211 ) ;
}
int F_153 ( struct V_11 * V_12 ,
enum V_438 V_439 )
{
const T_2 * V_191 ;
enum V_438 V_440 ;
int V_13 ;
F_154 ( & V_12 -> V_15 . V_23 . V_441 ) ;
V_440 = V_12 -> V_15 . V_23 . V_442 ;
V_12 -> V_15 . V_23 . V_442 = V_439 ;
if ( V_440 == V_439 &&
V_439 != V_443 )
return 0 ;
if ( ! V_12 -> V_15 . V_23 . V_444 ||
V_12 -> V_24 . V_149 . V_380 == V_384 ) {
F_18 ( & V_12 -> V_9 -> V_445 ) ;
F_155 ( V_12 -> V_9 ) ;
F_24 ( & V_12 -> V_9 -> V_445 ) ;
return 0 ;
}
V_191 = V_12 -> V_15 . V_23 . V_444 -> V_446 ;
if ( V_439 == V_443 ) {
if ( V_12 -> V_15 . V_23 . V_447 )
V_439 = V_448 ;
else
V_439 = V_449 ;
}
V_13 = F_156 ( V_12 , V_439 ,
V_191 , V_191 ) ;
if ( V_13 )
V_12 -> V_15 . V_23 . V_442 = V_440 ;
return V_13 ;
}
static int F_157 ( struct V_2 * V_2 , struct V_1 * V_10 ,
bool V_450 , int V_451 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_51 ( V_10 -> V_178 ) ;
if ( V_12 -> V_24 . type != V_22 )
return - V_365 ;
if ( ! ( V_9 -> V_77 . V_5 & V_452 ) )
return - V_365 ;
if ( V_450 == V_12 -> V_15 . V_23 . V_447 &&
V_451 == V_9 -> V_453 )
return 0 ;
V_12 -> V_15 . V_23 . V_447 = V_450 ;
V_9 -> V_453 = V_451 ;
F_18 ( & V_12 -> V_15 . V_23 . V_441 ) ;
F_153 ( V_12 , V_12 -> V_15 . V_23 . V_442 ) ;
F_24 ( & V_12 -> V_15 . V_23 . V_441 ) ;
if ( V_9 -> V_77 . V_5 & V_454 )
F_117 ( V_9 , V_455 ) ;
F_86 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_158 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_5 V_456 , T_1 V_457 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_51 ( V_10 -> V_178 ) ;
struct V_458 * V_24 = & V_12 -> V_24 ;
struct V_180 * V_149 = & V_24 -> V_149 ;
if ( V_456 == V_149 -> V_459 &&
V_457 == V_149 -> V_460 )
return 0 ;
V_149 -> V_459 = V_456 ;
V_149 -> V_460 = V_457 ;
if ( ! ( V_9 -> V_77 . V_5 & V_461 ) ) {
if ( V_12 -> V_24 . type != V_22 )
return - V_365 ;
return 0 ;
}
if ( V_12 -> V_15 . V_23 . V_444 )
F_57 ( V_12 , V_462 ) ;
return 0 ;
}
static int F_159 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
const T_2 * V_174 ,
const struct V_463 * V_162 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_51 ( V_10 -> V_178 ) ;
int V_220 , V_17 ;
if ( V_9 -> V_77 . V_5 & V_464 ) {
V_17 = F_160 ( V_9 , V_12 , V_162 ) ;
if ( V_17 )
return V_17 ;
}
for ( V_220 = 0 ; V_220 < V_465 ; V_220 ++ )
V_12 -> V_466 [ V_220 ] = V_162 -> V_214 [ V_220 ] . V_81 ;
return 0 ;
}
static int F_161 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
struct V_377 * V_378 ,
enum V_379 V_467 ,
unsigned int V_468 , T_3 * V_53 )
{
int V_17 ;
T_1 V_469 ;
F_154 ( & V_9 -> V_441 ) ;
if ( V_9 -> V_470 )
return - V_26 ;
V_469 = F_162 () | 1 ;
* V_53 = V_469 ;
V_9 -> V_471 = V_10 ;
V_9 -> V_470 = V_469 ;
V_9 -> V_472 = V_378 ;
V_9 -> V_473 = V_467 ;
V_9 -> V_474 = V_468 ;
V_17 = F_163 ( V_9 , V_378 , V_467 , V_468 ) ;
if ( V_17 ) {
V_9 -> V_472 = NULL ;
V_9 -> V_470 = 0 ;
}
return V_17 ;
}
static int F_164 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_377 * V_378 ,
enum V_379 V_380 ,
unsigned int V_468 ,
T_3 * V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_363 -> V_475 ) {
int V_17 ;
F_18 ( & V_9 -> V_441 ) ;
V_17 = F_161 ( V_9 , V_10 ,
V_378 , V_380 ,
V_468 , V_53 ) ;
V_9 -> V_476 = false ;
F_24 ( & V_9 -> V_441 ) ;
return V_17 ;
}
return F_165 ( V_12 , V_378 , V_380 ,
V_468 , V_53 ) ;
}
static int F_166 ( struct V_8 * V_9 ,
T_3 V_53 )
{
int V_17 ;
F_154 ( & V_9 -> V_441 ) ;
if ( V_9 -> V_470 != V_53 )
return - V_47 ;
V_17 = F_167 ( V_9 ) ;
if ( V_17 )
return V_17 ;
V_9 -> V_470 = 0 ;
V_9 -> V_472 = NULL ;
F_168 ( V_9 ) ;
return 0 ;
}
static int F_169 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_363 -> V_477 ) {
int V_17 ;
F_18 ( & V_9 -> V_441 ) ;
V_17 = F_166 ( V_9 , V_53 ) ;
F_24 ( & V_9 -> V_441 ) ;
return V_17 ;
}
return F_170 ( V_12 , V_53 ) ;
}
static enum V_478
F_171 ( struct V_479 * V_480 , struct V_207 * V_208 )
{
if ( V_480 -> V_481 . V_482 && ! V_480 -> V_481 . V_483 )
F_172 ( V_480 -> V_12 -> V_10 ,
( unsigned long ) V_480 -> V_481 . V_484 ,
V_480 -> V_298 , V_480 -> V_299 , false , V_199 ) ;
return V_485 ;
}
static int F_173 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_377 * V_378 , bool V_486 ,
enum V_379 V_380 ,
bool V_487 , unsigned int V_482 ,
const T_2 * V_488 , T_6 V_211 , bool V_489 ,
T_3 * V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_207 * V_208 ;
struct V_31 * V_21 ;
struct V_479 * V_480 ;
const struct V_490 * V_491 = ( void * ) V_488 ;
T_1 V_5 = V_492 |
V_493 ;
bool V_494 = false ;
if ( V_378 != V_9 -> V_495 &&
V_378 != V_9 -> V_222 )
V_494 = true ;
if ( V_487 &&
( V_380 != V_9 -> V_496 &&
V_380 != V_9 -> V_387 ) )
V_494 = true ;
if ( V_378 == V_9 -> V_472 ) {
V_494 = false ;
V_5 |= V_497 ;
}
if ( V_489 )
V_5 |= V_498 ;
if ( V_494 && ! V_486 )
return - V_26 ;
switch ( V_12 -> V_24 . type ) {
case V_394 :
case V_250 :
case V_18 :
case V_397 :
case V_395 :
if ( ! F_174 ( V_491 -> V_499 ) ||
V_491 -> V_15 . V_500 . V_501 == V_502 )
break;
F_30 () ;
V_21 = F_20 ( V_12 , V_491 -> V_209 ) ;
F_34 () ;
if ( ! V_21 )
return - V_503 ;
break;
case V_22 :
case V_396 :
break;
default:
return - V_365 ;
}
V_208 = F_65 ( V_9 -> V_77 . V_504 + V_211 ) ;
if ( ! V_208 )
return - V_200 ;
F_175 ( V_208 , V_9 -> V_77 . V_504 ) ;
memcpy ( F_66 ( V_208 , V_211 ) , V_488 , V_211 ) ;
F_176 ( V_208 ) -> V_5 = V_5 ;
V_208 -> V_10 = V_12 -> V_10 ;
* V_53 = ( unsigned long ) V_208 ;
if ( V_494 && V_9 -> V_363 -> V_475 ) {
unsigned int V_468 ;
int V_17 ;
F_18 ( & V_9 -> V_441 ) ;
V_468 = 100 ;
if ( V_482 )
V_468 = V_482 ;
V_17 = F_161 ( V_9 , V_10 , V_378 ,
V_380 ,
V_468 , V_53 ) ;
if ( V_17 ) {
F_177 ( V_208 ) ;
F_24 ( & V_9 -> V_441 ) ;
return V_17 ;
}
V_9 -> V_476 = true ;
V_9 -> V_474 = V_482 ;
* V_53 ^= 2 ;
F_176 ( V_208 ) -> V_5 |= V_497 ;
V_9 -> V_505 = V_208 ;
V_9 -> V_506 = V_208 ;
F_24 ( & V_9 -> V_441 ) ;
return 0 ;
}
if ( ! V_494 && ! V_482 && ! V_12 -> V_24 . V_149 . V_507 ) {
F_178 ( V_12 , V_208 ) ;
return 0 ;
}
V_480 = F_58 ( sizeof( * V_480 ) + V_211 , V_199 ) ;
if ( ! V_480 ) {
F_177 ( V_208 ) ;
return - V_200 ;
}
V_480 -> type = V_508 ;
V_480 -> V_378 = V_378 ;
V_480 -> V_509 = V_380 ;
V_480 -> V_12 = V_12 ;
V_480 -> V_510 = F_171 ;
V_480 -> V_481 . V_484 = V_208 ;
V_480 -> V_481 . V_482 = V_482 ;
V_480 -> V_299 = V_211 ;
memcpy ( V_480 -> V_298 , V_488 , V_211 ) ;
F_179 ( V_480 ) ;
return 0 ;
}
static int F_180 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_479 * V_480 ;
int V_17 = - V_47 ;
F_18 ( & V_9 -> V_441 ) ;
if ( V_9 -> V_363 -> V_477 ) {
V_53 ^= 2 ;
V_17 = F_166 ( V_9 , V_53 ) ;
if ( V_17 == 0 ) {
F_177 ( V_9 -> V_505 ) ;
V_9 -> V_505 = NULL ;
V_9 -> V_506 = NULL ;
}
F_24 ( & V_9 -> V_441 ) ;
return V_17 ;
}
F_181 (wk, &local->work_list, list) {
if ( V_480 -> V_12 != V_12 )
continue;
if ( V_480 -> type != V_508 )
continue;
if ( V_53 != ( unsigned long ) V_480 -> V_481 . V_484 )
continue;
V_480 -> V_451 = V_109 ;
F_182 ( & V_9 -> V_77 , & V_9 -> V_511 ) ;
V_17 = 0 ;
break;
}
F_24 ( & V_9 -> V_441 ) ;
return V_17 ;
}
static void F_183 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_512 , bool V_513 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_512 != ( V_514 | V_515 ) )
return;
if ( V_513 )
V_9 -> V_516 ++ ;
else
V_9 -> V_516 -- ;
F_182 ( & V_9 -> V_77 , & V_9 -> V_517 ) ;
}
static int F_184 ( struct V_2 * V_2 , T_1 V_518 , T_1 V_519 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_520 )
return - V_365 ;
return F_185 ( V_9 , V_518 , V_519 ) ;
}
static int F_186 ( struct V_2 * V_2 , T_1 * V_518 , T_1 * V_519 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_187 ( V_9 , V_518 , V_519 ) ;
}
static int F_188 ( struct V_2 * V_2 , T_1 V_60 , T_1 V_521 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_189 ( V_9 , V_60 , V_521 ) ;
}
static void F_190 ( struct V_2 * V_2 ,
T_1 * V_60 , T_1 * V_522 , T_1 * V_521 , T_1 * V_523 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_191 ( V_9 , V_60 , V_522 , V_521 , V_523 ) ;
}
static int F_192 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_524 * V_434 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_9 -> V_363 -> V_525 )
return - V_365 ;
F_193 ( V_9 , V_12 , V_434 ) ;
return 0 ;
}
static void F_194 ( struct V_207 * V_208 )
{
T_2 * V_526 = ( void * ) F_66 ( V_208 , 7 ) ;
* V_526 ++ = V_527 ;
* V_526 ++ = 5 ;
* V_526 ++ = 0x0 ;
* V_526 ++ = 0x0 ;
* V_526 ++ = 0x0 ;
* V_526 ++ = 0x0 ;
* V_526 ++ = V_528 ;
}
static T_4 F_195 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
T_4 V_529 ;
V_529 = 0 ;
if ( V_9 -> V_222 -> V_80 != V_530 )
return V_529 ;
if ( ! ( V_9 -> V_77 . V_5 & V_531 ) )
V_529 |= V_532 ;
if ( ! ( V_9 -> V_77 . V_5 & V_533 ) )
V_529 |= V_534 ;
return V_529 ;
}
static void F_196 ( struct V_207 * V_208 , T_2 * V_535 ,
T_2 * V_536 , T_2 * V_446 )
{
struct V_537 * V_538 ;
V_538 = ( void * ) F_66 ( V_208 , sizeof( struct V_537 ) ) ;
V_538 -> V_539 = V_540 ;
V_538 -> V_299 = sizeof( struct V_537 ) - 2 ;
memcpy ( V_538 -> V_446 , V_446 , V_175 ) ;
memcpy ( V_538 -> V_541 , V_535 , V_175 ) ;
memcpy ( V_538 -> V_542 , V_536 , V_175 ) ;
}
static int
F_197 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_536 , T_2 V_543 , T_2 V_544 ,
T_4 V_545 , struct V_207 * V_208 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_546 * V_547 ;
V_547 = ( void * ) F_66 ( V_208 , F_198 ( struct V_546 , V_15 ) ) ;
memcpy ( V_547 -> V_209 , V_536 , V_175 ) ;
memcpy ( V_547 -> V_210 , V_12 -> V_24 . V_174 , V_175 ) ;
V_547 -> V_548 = F_199 ( V_549 ) ;
V_547 -> V_550 = V_551 ;
switch ( V_543 ) {
case V_552 :
V_547 -> V_501 = V_553 ;
V_547 -> V_543 = V_552 ;
F_66 ( V_208 , sizeof( V_547 -> V_15 . V_554 ) ) ;
V_547 -> V_15 . V_554 . V_544 = V_544 ;
V_547 -> V_15 . V_554 . V_555 =
F_200 ( F_195 ( V_12 ) ) ;
F_201 ( & V_12 -> V_24 , V_208 ) ;
F_202 ( & V_12 -> V_24 , V_208 ) ;
F_194 ( V_208 ) ;
break;
case V_556 :
V_547 -> V_501 = V_553 ;
V_547 -> V_543 = V_556 ;
F_66 ( V_208 , sizeof( V_547 -> V_15 . V_557 ) ) ;
V_547 -> V_15 . V_557 . V_545 = F_200 ( V_545 ) ;
V_547 -> V_15 . V_557 . V_544 = V_544 ;
V_547 -> V_15 . V_557 . V_555 =
F_200 ( F_195 ( V_12 ) ) ;
F_201 ( & V_12 -> V_24 , V_208 ) ;
F_202 ( & V_12 -> V_24 , V_208 ) ;
F_194 ( V_208 ) ;
break;
case V_558 :
V_547 -> V_501 = V_553 ;
V_547 -> V_543 = V_558 ;
F_66 ( V_208 , sizeof( V_547 -> V_15 . V_559 ) ) ;
V_547 -> V_15 . V_559 . V_545 = F_200 ( V_545 ) ;
V_547 -> V_15 . V_559 . V_544 = V_544 ;
break;
case V_560 :
V_547 -> V_501 = V_553 ;
V_547 -> V_543 = V_560 ;
F_66 ( V_208 , sizeof( V_547 -> V_15 . V_561 ) ) ;
V_547 -> V_15 . V_561 . V_562 = F_200 ( V_545 ) ;
break;
case V_563 :
V_547 -> V_501 = V_553 ;
V_547 -> V_543 = V_563 ;
F_66 ( V_208 , sizeof( V_547 -> V_15 . V_564 ) ) ;
V_547 -> V_15 . V_564 . V_544 = V_544 ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static int
F_203 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_536 , T_2 V_543 , T_2 V_544 ,
T_4 V_545 , struct V_207 * V_208 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_490 * V_491 ;
V_491 = ( void * ) F_66 ( V_208 , 24 ) ;
memset ( V_491 , 0 , 24 ) ;
memcpy ( V_491 -> V_209 , V_536 , V_175 ) ;
memcpy ( V_491 -> V_210 , V_12 -> V_24 . V_174 , V_175 ) ;
memcpy ( V_491 -> V_446 , V_12 -> V_15 . V_23 . V_446 , V_175 ) ;
V_491 -> V_499 = F_200 ( V_514 |
V_565 ) ;
switch ( V_543 ) {
case V_566 :
F_66 ( V_208 , 1 + sizeof( V_491 -> V_15 . V_500 . V_15 . V_567 ) ) ;
V_491 -> V_15 . V_500 . V_501 = V_502 ;
V_491 -> V_15 . V_500 . V_15 . V_567 . V_543 =
V_566 ;
V_491 -> V_15 . V_500 . V_15 . V_567 . V_544 =
V_544 ;
V_491 -> V_15 . V_500 . V_15 . V_567 . V_555 =
F_200 ( F_195 ( V_12 ) ) ;
F_201 ( & V_12 -> V_24 , V_208 ) ;
F_202 ( & V_12 -> V_24 , V_208 ) ;
F_194 ( V_208 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static int F_204 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_536 , T_2 V_543 , T_2 V_544 ,
T_4 V_545 , const T_2 * V_568 ,
T_6 V_569 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_570 * V_571 ;
struct V_207 * V_208 = NULL ;
bool V_572 ;
int V_17 ;
if ( ! ( V_2 -> V_5 & V_251 ) )
return - V_252 ;
if ( V_12 -> V_24 . type != V_22 ||
! V_12 -> V_15 . V_23 . V_444 )
return - V_40 ;
#ifdef F_205
F_206 ( V_573 L_2 , V_543 , V_536 ) ;
#endif
V_208 = F_65 ( V_9 -> V_77 . V_504 +
F_207 ( sizeof( struct V_490 ) ,
sizeof( struct V_546 ) ) +
50 +
7 +
V_569 +
sizeof( struct V_537 ) ) ;
if ( ! V_208 )
return - V_200 ;
V_571 = F_176 ( V_208 ) ;
F_175 ( V_208 , V_9 -> V_77 . V_504 ) ;
switch ( V_543 ) {
case V_552 :
case V_556 :
case V_558 :
case V_560 :
case V_563 :
V_17 = F_197 ( V_2 , V_10 , V_536 ,
V_543 , V_544 ,
V_545 , V_208 ) ;
V_572 = false ;
break;
case V_566 :
V_17 = F_203 ( V_2 , V_10 , V_536 , V_543 ,
V_544 , V_545 ,
V_208 ) ;
V_572 = true ;
break;
default:
V_17 = - V_252 ;
break;
}
if ( V_17 < 0 )
goto V_574;
if ( V_569 )
memcpy ( F_66 ( V_208 , V_569 ) , V_568 , V_569 ) ;
switch ( V_543 ) {
case V_552 :
case V_558 :
case V_560 :
case V_563 :
F_196 ( V_208 , V_12 -> V_24 . V_174 , V_536 ,
V_12 -> V_15 . V_23 . V_446 ) ;
break;
case V_556 :
case V_566 :
F_196 ( V_208 , V_536 , V_12 -> V_24 . V_174 ,
V_12 -> V_15 . V_23 . V_446 ) ;
break;
default:
V_17 = - V_252 ;
goto V_574;
}
if ( V_572 ) {
F_178 ( V_12 , V_208 ) ;
return 0 ;
}
switch ( V_543 ) {
case V_552 :
case V_556 :
F_208 ( V_208 , V_575 ) ;
V_208 -> V_576 = 2 ;
break;
default:
F_208 ( V_208 , V_577 ) ;
V_208 -> V_576 = 5 ;
break;
}
F_209 () ;
V_17 = F_210 ( V_208 , V_10 ) ;
F_211 () ;
return V_17 ;
V_574:
F_212 ( V_208 ) ;
return V_17 ;
}
static int F_213 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_536 , enum V_578 V_579 )
{
struct V_31 * V_21 ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! ( V_2 -> V_5 & V_251 ) )
return - V_252 ;
if ( V_12 -> V_24 . type != V_22 )
return - V_40 ;
#ifdef F_205
F_206 ( V_573 L_3 , V_579 , V_536 ) ;
#endif
switch ( V_579 ) {
case V_580 :
F_30 () ;
V_21 = F_20 ( V_12 , V_536 ) ;
if ( ! V_21 ) {
F_34 () ;
return - V_503 ;
}
F_71 ( V_21 , V_581 ) ;
F_34 () ;
break;
case V_582 :
return F_214 ( V_12 , V_536 ) ;
case V_583 :
case V_584 :
case V_585 :
return - V_252 ;
default:
return - V_252 ;
}
return 0 ;
}
