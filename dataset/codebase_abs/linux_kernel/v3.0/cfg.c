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
T_1 V_54 ;
T_3 V_55 ;
int V_13 = - V_47 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
if ( V_29 ) {
V_21 = F_21 ( V_12 , V_29 ) ;
if ( ! V_21 )
goto V_56;
if ( V_28 )
V_33 = F_31 ( V_21 -> V_50 ) ;
else if ( V_27 < V_57 )
V_33 = F_31 ( V_21 -> V_51 [ V_27 ] ) ;
} else
V_33 = F_31 ( V_12 -> V_52 [ V_27 ] ) ;
if ( ! V_33 )
goto V_56;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
V_7 . V_35 = V_33 -> V_44 . V_35 ;
switch ( V_33 -> V_44 . V_35 ) {
case V_37 :
V_54 = V_33 -> V_15 . V_58 . V_59 . V_54 ;
V_55 = V_33 -> V_15 . V_58 . V_59 . V_55 ;
if ( V_33 -> V_5 & V_60 )
F_32 ( V_12 -> V_9 ,
V_33 -> V_44 . V_61 ,
& V_54 , & V_55 ) ;
V_43 [ 0 ] = V_55 & 0xff ;
V_43 [ 1 ] = ( V_55 >> 8 ) & 0xff ;
V_43 [ 2 ] = V_54 & 0xff ;
V_43 [ 3 ] = ( V_54 >> 8 ) & 0xff ;
V_43 [ 4 ] = ( V_54 >> 16 ) & 0xff ;
V_43 [ 5 ] = ( V_54 >> 24 ) & 0xff ;
V_7 . V_43 = V_43 ;
V_7 . V_42 = 6 ;
break;
case V_62 :
V_43 [ 0 ] = V_33 -> V_15 . V_63 . V_64 [ 5 ] ;
V_43 [ 1 ] = V_33 -> V_15 . V_63 . V_64 [ 4 ] ;
V_43 [ 2 ] = V_33 -> V_15 . V_63 . V_64 [ 3 ] ;
V_43 [ 3 ] = V_33 -> V_15 . V_63 . V_64 [ 2 ] ;
V_43 [ 4 ] = V_33 -> V_15 . V_63 . V_64 [ 1 ] ;
V_43 [ 5 ] = V_33 -> V_15 . V_63 . V_64 [ 0 ] ;
V_7 . V_43 = V_43 ;
V_7 . V_42 = 6 ;
break;
case V_65 :
V_43 [ 0 ] = V_33 -> V_15 . V_66 . V_64 [ 5 ] ;
V_43 [ 1 ] = V_33 -> V_15 . V_66 . V_64 [ 4 ] ;
V_43 [ 2 ] = V_33 -> V_15 . V_66 . V_64 [ 3 ] ;
V_43 [ 3 ] = V_33 -> V_15 . V_66 . V_64 [ 2 ] ;
V_43 [ 4 ] = V_33 -> V_15 . V_66 . V_64 [ 1 ] ;
V_43 [ 5 ] = V_33 -> V_15 . V_66 . V_64 [ 0 ] ;
V_7 . V_43 = V_43 ;
V_7 . V_42 = 6 ;
break;
}
V_7 . V_33 = V_33 -> V_44 . V_33 ;
V_7 . V_41 = V_33 -> V_44 . V_67 ;
F_29 ( V_53 , & V_7 ) ;
V_13 = 0 ;
V_56:
F_33 () ;
return V_13 ;
}
static int F_34 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_27 , bool V_68 ,
bool V_69 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_35 ( V_12 , V_27 , V_68 , V_69 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 V_27 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_37 ( V_12 , V_27 ) ;
return 0 ;
}
static void F_38 ( struct V_70 * V_71 , struct V_31 * V_21 , int V_72 )
{
if ( ! ( V_71 -> V_5 & V_73 ) ) {
struct V_74 * V_75 ;
V_75 = V_21 -> V_9 -> V_76 . V_2 -> V_77 [
V_21 -> V_9 -> V_76 . V_44 . V_78 -> V_79 ] ;
V_71 -> V_80 = V_75 -> V_81 [ V_72 ] . V_82 ;
} else
V_71 -> V_83 = V_72 ;
}
static void F_39 ( struct V_31 * V_21 , struct V_84 * V_85 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_86 V_87 ;
V_85 -> V_88 = V_12 -> V_9 -> V_89 ;
V_85 -> V_90 = V_91 |
V_92 |
V_93 |
V_94 |
V_95 |
V_96 |
V_97 |
V_98 |
V_99 |
V_100 |
V_101 |
V_102 ;
F_40 ( & V_87 ) ;
V_85 -> V_103 = V_87 . V_104 - V_21 -> V_105 ;
V_85 -> V_106 = F_41 ( V_107 - V_21 -> V_108 ) ;
V_85 -> V_109 = V_21 -> V_109 ;
V_85 -> V_110 = V_21 -> V_110 ;
V_85 -> V_111 = V_21 -> V_111 ;
V_85 -> V_112 = V_21 -> V_112 ;
V_85 -> V_113 = V_21 -> V_114 ;
V_85 -> V_115 = V_21 -> V_116 ;
V_85 -> V_117 = V_21 -> V_118 ;
if ( ( V_21 -> V_9 -> V_76 . V_5 & V_119 ) ||
( V_21 -> V_9 -> V_76 . V_5 & V_120 ) ) {
V_85 -> V_90 |= V_121 | V_122 ;
V_85 -> signal = ( V_123 ) V_21 -> V_124 ;
V_85 -> V_125 = ( V_123 ) - F_42 ( & V_21 -> V_126 ) ;
}
V_85 -> V_127 . V_5 = 0 ;
if ( V_21 -> V_128 . V_5 & V_129 )
V_85 -> V_127 . V_5 |= V_73 ;
if ( V_21 -> V_128 . V_5 & V_130 )
V_85 -> V_127 . V_5 |= V_131 ;
if ( V_21 -> V_128 . V_5 & V_132 )
V_85 -> V_127 . V_5 |= V_133 ;
F_38 ( & V_85 -> V_127 , V_21 , V_21 -> V_128 . V_72 ) ;
V_85 -> V_134 . V_5 = 0 ;
if ( V_21 -> V_135 & V_136 )
V_85 -> V_134 . V_5 |= V_73 ;
if ( V_21 -> V_135 & V_137 )
V_85 -> V_134 . V_5 |= V_131 ;
if ( V_21 -> V_135 & V_138 )
V_85 -> V_134 . V_5 |= V_133 ;
F_38 ( & V_85 -> V_134 , V_21 , V_21 -> V_139 ) ;
if ( F_19 ( & V_12 -> V_24 ) ) {
#ifdef F_43
V_85 -> V_90 |= V_140 |
V_141 |
V_142 ;
V_85 -> V_143 = F_44 ( V_21 -> V_143 ) ;
V_85 -> V_144 = F_44 ( V_21 -> V_144 ) ;
V_85 -> V_145 = V_21 -> V_145 ;
#endif
}
V_85 -> V_146 . V_5 = 0 ;
if ( V_12 -> V_24 . V_147 . V_148 )
V_85 -> V_146 . V_5 |= V_149 ;
if ( V_12 -> V_24 . V_147 . V_150 )
V_85 -> V_146 . V_5 |= V_151 ;
if ( V_12 -> V_24 . V_147 . V_152 )
V_85 -> V_146 . V_5 |= V_153 ;
V_85 -> V_146 . V_154 = V_12 -> V_9 -> V_76 . V_44 . V_155 ;
V_85 -> V_146 . V_156 = V_12 -> V_24 . V_147 . V_157 ;
}
static int F_45 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_72 , T_2 * V_158 , struct V_84 * V_85 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_31 * V_21 ;
int V_17 = - V_47 ;
F_30 () ;
V_21 = F_46 ( V_12 , V_72 ) ;
if ( V_21 ) {
V_17 = 0 ;
memcpy ( V_158 , V_21 -> V_21 . V_159 , V_160 ) ;
F_39 ( V_21 , V_85 ) ;
}
F_33 () ;
return V_17 ;
}
static int F_47 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_72 , struct V_161 * V_162 )
{
struct V_8 * V_9 = F_48 ( V_10 -> V_163 ) ;
return F_49 ( V_9 , V_72 , V_162 ) ;
}
static int F_50 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_158 , struct V_84 * V_85 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_31 * V_21 ;
int V_17 = - V_47 ;
F_30 () ;
V_21 = F_21 ( V_12 , V_158 ) ;
if ( V_21 ) {
V_17 = 0 ;
F_39 ( V_21 , V_85 ) ;
}
F_33 () ;
return V_17 ;
}
static int F_51 ( struct V_11 * V_12 ,
struct V_164 * V_7 )
{
struct V_165 * V_166 , * V_167 ;
int V_168 , V_169 ;
int V_170 ;
int V_13 = - V_40 ;
V_167 = F_52 ( V_12 -> V_15 . V_171 . V_172 ) ;
if ( V_7 -> V_173 && ! V_7 -> V_174 )
return - V_40 ;
if ( V_7 -> V_175 &&
( V_12 -> V_24 . V_147 . V_157 != V_7 -> V_175 ) ) {
V_12 -> V_24 . V_147 . V_157 = V_7 -> V_175 ;
F_53 ( V_12 ,
V_176 ) ;
}
if ( ! V_7 -> V_173 && ! V_167 )
return V_13 ;
if ( ! V_7 -> V_154 && ! V_167 )
return V_13 ;
if ( V_7 -> V_173 )
V_168 = V_7 -> V_174 ;
else
V_168 = V_167 -> V_174 ;
if ( V_7 -> V_177 || ! V_167 )
V_169 = V_7 -> V_178 ;
else
V_169 = V_167 -> V_178 ;
V_170 = sizeof( * V_166 ) + V_168 + V_169 ;
V_166 = F_54 ( V_170 , V_179 ) ;
if ( ! V_166 )
return - V_180 ;
if ( V_7 -> V_154 )
V_166 -> V_154 = V_7 -> V_154 ;
else
V_166 -> V_154 = V_167 -> V_154 ;
V_166 -> V_173 = ( ( T_2 * ) V_166 ) + sizeof( * V_166 ) ;
V_166 -> V_177 = V_166 -> V_173 + V_168 ;
V_166 -> V_174 = V_168 ;
V_166 -> V_178 = V_169 ;
if ( V_7 -> V_173 )
memcpy ( V_166 -> V_173 , V_7 -> V_173 , V_168 ) ;
else
memcpy ( V_166 -> V_173 , V_167 -> V_173 , V_168 ) ;
if ( V_7 -> V_177 )
memcpy ( V_166 -> V_177 , V_7 -> V_177 , V_169 ) ;
else
if ( V_167 )
memcpy ( V_166 -> V_177 , V_167 -> V_177 , V_169 ) ;
V_12 -> V_24 . V_147 . V_154 = V_166 -> V_154 ;
F_10 ( V_12 -> V_15 . V_171 . V_172 , V_166 ) ;
F_55 () ;
F_56 ( V_167 ) ;
F_53 ( V_12 , V_181 |
V_182 ) ;
return 0 ;
}
static int F_57 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_164 * V_7 )
{
struct V_11 * V_12 ;
struct V_165 * V_167 ;
V_12 = F_5 ( V_10 ) ;
V_167 = F_52 ( V_12 -> V_15 . V_171 . V_172 ) ;
if ( V_167 )
return - V_183 ;
return F_51 ( V_12 , V_7 ) ;
}
static int F_58 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_164 * V_7 )
{
struct V_11 * V_12 ;
struct V_165 * V_167 ;
V_12 = F_5 ( V_10 ) ;
V_167 = F_52 ( V_12 -> V_15 . V_171 . V_172 ) ;
if ( ! V_167 )
return - V_47 ;
return F_51 ( V_12 , V_7 ) ;
}
static int F_59 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 ;
struct V_165 * V_167 ;
V_12 = F_5 ( V_10 ) ;
V_167 = F_52 ( V_12 -> V_15 . V_171 . V_172 ) ;
if ( ! V_167 )
return - V_47 ;
F_10 ( V_12 -> V_15 . V_171 . V_172 , NULL ) ;
F_55 () ;
F_56 ( V_167 ) ;
F_53 ( V_12 , V_181 ) ;
return 0 ;
}
static void F_60 ( struct V_31 * V_21 )
{
struct V_184 * V_185 ;
struct V_186 * V_187 ;
V_187 = F_61 ( sizeof( * V_185 ) ) ;
if ( ! V_187 )
return;
V_185 = (struct V_184 * ) F_62 ( V_187 , sizeof( * V_185 ) ) ;
memset ( V_185 -> V_188 , 0xff , V_160 ) ;
memcpy ( V_185 -> V_189 , V_21 -> V_21 . V_159 , V_160 ) ;
V_185 -> V_190 = F_63 ( 6 ) ;
V_185 -> V_191 = 0 ;
V_185 -> V_192 = 0x01 ;
V_185 -> V_193 = 0xaf ;
V_185 -> V_194 [ 0 ] = 0x81 ;
V_185 -> V_194 [ 1 ] = 1 ;
V_185 -> V_194 [ 2 ] = 0 ;
V_187 -> V_10 = V_21 -> V_12 -> V_10 ;
V_187 -> V_195 = F_64 ( V_187 , V_21 -> V_12 -> V_10 ) ;
memset ( V_187 -> V_196 , 0 , sizeof( V_187 -> V_196 ) ) ;
F_65 ( V_187 ) ;
}
static void F_66 ( struct V_8 * V_9 ,
struct V_31 * V_21 ,
struct V_197 * V_7 )
{
unsigned long V_5 ;
T_1 V_198 ;
int V_199 , V_200 ;
struct V_74 * V_75 ;
struct V_11 * V_12 = V_21 -> V_12 ;
T_1 V_201 , V_202 ;
V_75 = V_9 -> V_76 . V_2 -> V_77 [ V_9 -> V_203 -> V_79 ] ;
F_67 ( & V_21 -> V_204 , V_5 ) ;
V_201 = V_7 -> V_205 ;
V_202 = V_7 -> V_206 ;
if ( V_201 & F_68 ( V_207 ) ) {
V_21 -> V_5 &= ~ V_208 ;
if ( V_202 & F_68 ( V_207 ) )
V_21 -> V_5 |= V_208 ;
}
if ( V_201 & F_68 ( V_209 ) ) {
V_21 -> V_5 &= ~ V_210 ;
if ( V_202 & F_68 ( V_209 ) )
V_21 -> V_5 |= V_210 ;
}
if ( V_201 & F_68 ( V_211 ) ) {
V_21 -> V_5 &= ~ V_212 ;
if ( V_202 & F_68 ( V_211 ) )
V_21 -> V_5 |= V_212 ;
}
if ( V_201 & F_68 ( V_213 ) ) {
V_21 -> V_5 &= ~ V_214 ;
if ( V_202 & F_68 ( V_213 ) )
V_21 -> V_5 |= V_214 ;
}
if ( V_201 & F_68 ( V_215 ) ) {
V_21 -> V_5 &= ~ V_216 ;
if ( V_202 & F_68 ( V_215 ) )
V_21 -> V_5 |= V_216 ;
}
F_69 ( & V_21 -> V_204 , V_5 ) ;
if ( V_7 -> V_217 )
V_21 -> V_21 . V_217 = V_7 -> V_217 ;
if ( V_7 -> V_218 >= 0 )
V_21 -> V_218 = V_7 -> V_218 ;
if ( V_7 -> V_219 ) {
V_198 = 0 ;
for ( V_199 = 0 ; V_199 < V_7 -> V_220 ; V_199 ++ ) {
int V_71 = ( V_7 -> V_219 [ V_199 ] & 0x7f ) * 5 ;
for ( V_200 = 0 ; V_200 < V_75 -> V_221 ; V_200 ++ ) {
if ( V_75 -> V_81 [ V_200 ] . V_82 == V_71 )
V_198 |= F_68 ( V_200 ) ;
}
}
V_21 -> V_21 . V_222 [ V_9 -> V_203 -> V_79 ] = V_198 ;
}
if ( V_7 -> V_223 )
F_70 ( V_75 ,
V_7 -> V_223 ,
& V_21 -> V_21 . V_224 ) ;
if ( F_19 ( & V_12 -> V_24 ) ) {
#ifdef F_43
if ( V_12 -> V_15 . V_225 . V_226 & V_227 )
switch ( V_7 -> V_145 ) {
case V_228 :
case V_229 :
case V_230 :
V_21 -> V_145 = V_7 -> V_145 ;
break;
default:
break;
}
else
switch ( V_7 -> V_231 ) {
case V_232 :
F_71 ( V_21 ) ;
break;
case V_233 :
F_72 ( V_21 ) ;
break;
}
#endif
}
}
static int F_73 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_158 , struct V_197 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_31 * V_21 ;
struct V_11 * V_12 ;
int V_13 ;
int V_234 ;
if ( V_7 -> V_20 ) {
V_12 = F_5 ( V_7 -> V_20 ) ;
if ( V_12 -> V_24 . type != V_18 &&
V_12 -> V_24 . type != V_235 )
return - V_40 ;
} else
V_12 = F_5 ( V_10 ) ;
if ( F_74 ( V_158 , V_12 -> V_24 . V_159 ) == 0 )
return - V_40 ;
if ( F_75 ( V_158 ) )
return - V_40 ;
V_21 = F_76 ( V_12 , V_158 , V_179 ) ;
if ( ! V_21 )
return - V_180 ;
V_21 -> V_5 = V_216 | V_236 ;
F_66 ( V_9 , V_21 , V_7 ) ;
F_77 ( V_21 ) ;
V_234 = V_12 -> V_24 . type == V_18 ||
V_12 -> V_24 . type == V_235 ;
V_13 = F_78 ( V_21 ) ;
if ( V_13 ) {
F_33 () ;
return V_13 ;
}
if ( V_234 )
F_60 ( V_21 ) ;
F_33 () ;
return 0 ;
}
static int F_79 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_158 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
if ( V_158 )
return F_80 ( V_12 , V_158 ) ;
F_81 ( V_9 , V_12 ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 * V_158 ,
struct V_197 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_31 * V_21 ;
struct V_11 * V_237 ;
F_30 () ;
V_21 = F_21 ( V_12 , V_158 ) ;
if ( ! V_21 ) {
F_33 () ;
return - V_47 ;
}
if ( V_7 -> V_20 && V_7 -> V_20 != V_21 -> V_12 -> V_10 ) {
V_237 = F_5 ( V_7 -> V_20 ) ;
if ( V_237 -> V_24 . type != V_18 &&
V_237 -> V_24 . type != V_235 ) {
F_33 () ;
return - V_40 ;
}
if ( V_7 -> V_20 -> V_163 -> V_19 ) {
if ( V_237 -> V_15 . V_20 . V_21 ) {
F_33 () ;
return - V_26 ;
}
F_10 ( V_237 -> V_15 . V_20 . V_21 , V_21 ) ;
}
V_21 -> V_12 = V_237 ;
F_60 ( V_21 ) ;
}
F_66 ( V_9 , V_21 , V_7 ) ;
F_33 () ;
if ( V_12 -> V_24 . type == V_22 &&
V_7 -> V_205 & F_68 ( V_207 ) )
F_83 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_84 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_238 , T_2 * V_239 )
{
struct V_11 * V_12 ;
struct V_240 * V_241 ;
struct V_31 * V_21 ;
int V_13 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_21 = F_20 ( V_12 , V_239 ) ;
if ( ! V_21 ) {
F_33 () ;
return - V_47 ;
}
V_13 = F_85 ( V_238 , V_12 ) ;
if ( V_13 ) {
F_33 () ;
return V_13 ;
}
V_241 = F_86 ( V_238 , V_12 ) ;
if ( ! V_241 ) {
F_33 () ;
return - V_242 ;
}
F_87 ( V_241 , V_21 ) ;
F_33 () ;
return 0 ;
}
static int F_88 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_238 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( V_238 )
return F_89 ( V_238 , V_12 ) ;
F_90 ( V_12 ) ;
return 0 ;
}
static int F_91 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_2 * V_238 , T_2 * V_239 )
{
struct V_11 * V_12 ;
struct V_240 * V_241 ;
struct V_31 * V_21 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_21 = F_20 ( V_12 , V_239 ) ;
if ( ! V_21 ) {
F_33 () ;
return - V_47 ;
}
V_241 = F_86 ( V_238 , V_12 ) ;
if ( ! V_241 ) {
F_33 () ;
return - V_47 ;
}
F_87 ( V_241 , V_21 ) ;
F_33 () ;
return 0 ;
}
static void F_92 ( struct V_240 * V_241 , T_2 * V_239 ,
struct V_243 * V_244 )
{
struct V_31 * V_245 = F_31 ( V_241 -> V_239 ) ;
if ( V_245 )
memcpy ( V_239 , V_245 -> V_21 . V_159 , V_160 ) ;
else
memset ( V_239 , 0 , V_160 ) ;
V_244 -> V_88 = V_246 ;
V_244 -> V_90 = V_247 |
V_248 |
V_249 |
V_250 |
V_251 |
V_252 |
V_253 ;
V_244 -> V_254 = V_241 -> V_255 . V_256 ;
V_244 -> V_257 = V_241 -> V_257 ;
V_244 -> V_258 = V_241 -> V_258 ;
if ( F_93 ( V_107 , V_241 -> V_259 ) )
V_244 -> V_260 = F_41 ( V_241 -> V_259 - V_107 ) ;
V_244 -> V_261 =
F_41 ( V_241 -> V_261 ) ;
V_244 -> V_262 = V_241 -> V_262 ;
V_244 -> V_5 = 0 ;
if ( V_241 -> V_5 & V_263 )
V_244 -> V_5 |= V_264 ;
if ( V_241 -> V_5 & V_265 )
V_244 -> V_5 |= V_266 ;
if ( V_241 -> V_5 & V_267 )
V_244 -> V_5 |= V_268 ;
if ( V_241 -> V_5 & V_269 )
V_244 -> V_5 |= V_270 ;
if ( V_241 -> V_5 & V_265 )
V_244 -> V_5 |= V_266 ;
V_244 -> V_5 = V_241 -> V_5 ;
}
static int F_94 ( struct V_2 * V_2 , struct V_1 * V_10 ,
T_2 * V_238 , T_2 * V_239 , struct V_243 * V_244 )
{
struct V_11 * V_12 ;
struct V_240 * V_241 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_241 = F_86 ( V_238 , V_12 ) ;
if ( ! V_241 ) {
F_33 () ;
return - V_47 ;
}
memcpy ( V_238 , V_241 -> V_238 , V_160 ) ;
F_92 ( V_241 , V_239 , V_244 ) ;
F_33 () ;
return 0 ;
}
static int F_95 ( struct V_2 * V_2 , struct V_1 * V_10 ,
int V_72 , T_2 * V_238 , T_2 * V_239 ,
struct V_243 * V_244 )
{
struct V_11 * V_12 ;
struct V_240 * V_241 ;
V_12 = F_5 ( V_10 ) ;
F_30 () ;
V_241 = F_96 ( V_72 , V_12 ) ;
if ( ! V_241 ) {
F_33 () ;
return - V_47 ;
}
memcpy ( V_238 , V_241 -> V_238 , V_160 ) ;
F_92 ( V_241 , V_239 , V_244 ) ;
F_33 () ;
return 0 ;
}
static int F_97 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_271 * V_44 )
{
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 ) ;
memcpy ( V_44 , & ( V_12 -> V_15 . V_225 . V_272 ) , sizeof( struct V_271 ) ) ;
return 0 ;
}
static inline bool F_98 ( enum V_273 V_274 , T_1 V_201 )
{
return ( V_201 >> ( V_274 - 1 ) ) & 0x1 ;
}
static int F_99 ( struct V_275 * V_276 ,
const struct V_277 * V_278 )
{
T_2 * V_279 ;
const T_2 * V_280 ;
V_279 = NULL ;
V_280 = V_276 -> V_281 ;
if ( V_278 -> V_282 ) {
V_279 = F_100 ( V_278 -> V_281 , V_278 -> V_282 ,
V_179 ) ;
if ( ! V_279 )
return - V_180 ;
}
V_276 -> V_282 = V_278 -> V_282 ;
V_276 -> V_281 = V_279 ;
F_56 ( V_280 ) ;
V_276 -> V_283 = V_278 -> V_283 ;
memcpy ( V_276 -> V_284 , V_278 -> V_284 , V_276 -> V_283 ) ;
V_276 -> V_285 = V_278 -> V_286 ;
V_276 -> V_287 = V_278 -> V_288 ;
V_276 -> V_226 = V_289 ;
if ( V_278 -> V_290 )
V_276 -> V_226 |= V_291 ;
if ( V_278 -> V_292 )
V_276 -> V_226 |= V_227 ;
return 0 ;
}
static int F_101 ( struct V_2 * V_2 ,
struct V_1 * V_10 , T_1 V_201 ,
const struct V_271 * V_293 )
{
struct V_271 * V_44 ;
struct V_11 * V_12 ;
struct V_275 * V_276 ;
V_12 = F_5 ( V_10 ) ;
V_276 = & V_12 -> V_15 . V_225 ;
V_44 = & ( V_12 -> V_15 . V_225 . V_272 ) ;
if ( F_98 ( V_294 , V_201 ) )
V_44 -> V_295 = V_293 -> V_295 ;
if ( F_98 ( V_296 , V_201 ) )
V_44 -> V_297 = V_293 -> V_297 ;
if ( F_98 ( V_298 , V_201 ) )
V_44 -> V_299 = V_293 -> V_299 ;
if ( F_98 ( V_300 , V_201 ) )
V_44 -> V_301 = V_293 -> V_301 ;
if ( F_98 ( V_302 , V_201 ) )
V_44 -> V_303 = V_293 -> V_303 ;
if ( F_98 ( V_304 , V_201 ) )
V_44 -> V_305 = V_293 -> V_305 ;
if ( F_98 ( V_306 , V_201 ) )
V_44 -> V_305 = V_293 -> V_307 ;
if ( F_98 ( V_308 , V_201 ) )
V_44 -> V_309 = V_293 -> V_309 ;
if ( F_98 ( V_310 , V_201 ) )
V_44 -> V_311 =
V_293 -> V_311 ;
if ( F_98 ( V_312 , V_201 ) )
V_44 -> V_313 = V_293 -> V_313 ;
if ( F_98 ( V_314 , V_201 ) )
V_44 -> V_315 = V_293 -> V_315 ;
if ( F_98 ( V_316 , V_201 ) )
V_44 -> V_317 =
V_293 -> V_317 ;
if ( F_98 ( V_318 , V_201 ) )
V_44 -> V_319 =
V_293 -> V_319 ;
if ( F_98 ( V_320 ,
V_201 ) )
V_44 -> V_321 =
V_293 -> V_321 ;
if ( F_98 ( V_322 , V_201 ) ) {
V_44 -> V_323 = V_293 -> V_323 ;
F_102 ( V_276 ) ;
}
return 0 ;
}
static int F_103 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const struct V_271 * V_44 ,
const struct V_277 * V_278 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_275 * V_276 = & V_12 -> V_15 . V_225 ;
int V_13 ;
memcpy ( & V_276 -> V_272 , V_44 , sizeof( struct V_271 ) ) ;
V_13 = F_99 ( V_276 , V_278 ) ;
if ( V_13 )
return V_13 ;
F_104 ( V_12 ) ;
return 0 ;
}
static int F_105 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
F_106 ( V_12 ) ;
return 0 ;
}
static int F_107 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_324 * V_7 )
{
struct V_11 * V_12 ;
T_1 V_325 = 0 ;
V_12 = F_5 ( V_10 ) ;
if ( V_7 -> V_148 >= 0 ) {
V_12 -> V_24 . V_147 . V_148 = V_7 -> V_148 ;
V_325 |= V_326 ;
}
if ( V_7 -> V_150 >= 0 ) {
V_12 -> V_24 . V_147 . V_150 =
V_7 -> V_150 ;
V_325 |= V_327 ;
}
if ( ! V_12 -> V_24 . V_147 . V_152 &&
V_12 -> V_9 -> V_76 . V_44 . V_78 -> V_79 == V_328 ) {
V_12 -> V_24 . V_147 . V_152 = true ;
V_325 |= V_329 ;
}
if ( V_7 -> V_330 >= 0 ) {
V_12 -> V_24 . V_147 . V_152 =
V_7 -> V_330 ;
V_325 |= V_329 ;
}
if ( V_7 -> V_331 ) {
int V_199 , V_200 ;
T_1 V_198 = 0 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_74 * V_75 =
V_2 -> V_77 [ V_9 -> V_203 -> V_79 ] ;
for ( V_199 = 0 ; V_199 < V_7 -> V_332 ; V_199 ++ ) {
int V_71 = ( V_7 -> V_331 [ V_199 ] & 0x7f ) * 5 ;
for ( V_200 = 0 ; V_200 < V_75 -> V_221 ; V_200 ++ ) {
if ( V_75 -> V_81 [ V_200 ] . V_82 == V_71 )
V_198 |= F_68 ( V_200 ) ;
}
}
V_12 -> V_24 . V_147 . V_331 = V_198 ;
V_325 |= V_333 ;
}
if ( V_7 -> V_334 >= 0 ) {
if ( V_7 -> V_334 )
V_12 -> V_5 |= V_335 ;
else
V_12 -> V_5 &= ~ V_335 ;
}
if ( V_7 -> V_336 >= 0 ) {
V_12 -> V_24 . V_147 . V_337 =
( T_3 ) V_7 -> V_336 ;
V_325 |= V_338 ;
}
F_53 ( V_12 , V_325 ) ;
return 0 ;
}
static int F_108 ( struct V_2 * V_2 ,
struct V_339 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_340 V_341 ;
if ( ! V_9 -> V_342 -> V_343 )
return - V_344 ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_341 . V_345 = V_7 -> V_345 ;
V_341 . V_346 = V_7 -> V_347 ;
V_341 . V_348 = V_7 -> V_349 ;
V_341 . V_350 = V_7 -> V_350 ;
V_341 . V_351 = false ;
if ( F_109 ( V_9 , V_7 -> V_352 , & V_341 ) ) {
F_110 ( V_9 -> V_76 . V_2 ,
L_1 ,
V_7 -> V_352 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_111 ( struct V_2 * V_2 ,
struct V_1 * V_353 ,
struct V_354 * V_355 ,
enum V_356 V_357 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = NULL ;
struct V_354 * V_358 ;
enum V_356 V_359 ;
enum V_356 V_360 = V_361 ;
if ( V_353 )
V_12 = F_5 ( V_353 ) ;
switch ( F_112 ( V_9 , NULL ) ) {
case V_362 :
return - V_26 ;
case V_363 :
if ( V_9 -> V_203 != V_355 )
return - V_26 ;
if ( ! V_12 && V_9 -> V_364 == V_357 )
return 0 ;
break;
case V_365 :
break;
}
if ( V_12 )
V_360 = V_12 -> V_24 . V_147 . V_357 ;
V_359 = V_9 -> V_364 ;
if ( ! F_113 ( V_9 , V_12 , V_357 ) )
return - V_26 ;
V_358 = V_9 -> V_203 ;
V_9 -> V_203 = V_355 ;
if ( ( V_358 != V_9 -> V_203 ) ||
( V_359 != V_9 -> V_364 ) )
F_114 ( V_9 , V_366 ) ;
if ( ( V_12 && V_12 -> V_24 . type != V_14 ) &&
V_360 != V_12 -> V_24 . V_147 . V_357 )
F_53 ( V_12 , V_338 ) ;
return 0 ;
}
static int F_115 ( struct V_2 * V_2 ,
struct V_367 * V_368 )
{
return F_116 ( F_2 ( V_2 ) , V_368 ) ;
}
static int F_117 ( struct V_2 * V_2 )
{
return F_118 ( F_2 ( V_2 ) ) ;
}
static int F_119 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_369 * V_370 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_120 ( & V_12 -> V_24 ) ) {
case V_22 :
case V_371 :
case V_372 :
case V_373 :
break;
case V_374 :
if ( V_12 -> V_9 -> V_342 -> V_375 )
break;
case V_235 :
if ( V_12 -> V_15 . V_171 . V_172 )
return - V_344 ;
break;
default:
return - V_344 ;
}
return F_121 ( V_12 , V_370 ) ;
}
static int
F_122 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_376 * V_370 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_342 -> V_377 )
return - V_344 ;
return F_123 ( V_12 , V_370 ) ;
}
static int
F_124 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
if ( ! V_12 -> V_9 -> V_342 -> V_378 )
return - V_344 ;
return F_125 ( V_12 ) ;
}
static int F_126 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_379 * V_370 )
{
return F_127 ( F_5 ( V_10 ) , V_370 ) ;
}
static int F_128 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_380 * V_370 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_112 ( V_9 , V_12 ) ) {
case V_362 :
return - V_26 ;
case V_363 :
if ( V_9 -> V_203 == V_370 -> V_381 -> V_78 )
break;
return - V_26 ;
case V_365 :
break;
}
return F_129 ( F_5 ( V_10 ) , V_370 ) ;
}
static int F_130 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_382 * V_370 ,
void * V_53 )
{
return F_131 ( F_5 ( V_10 ) ,
V_370 , V_53 ) ;
}
static int F_132 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_383 * V_370 ,
void * V_53 )
{
return F_133 ( F_5 ( V_10 ) ,
V_370 , V_53 ) ;
}
static int F_134 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_384 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_5 ( V_10 ) ;
switch ( F_112 ( V_9 , V_12 ) ) {
case V_362 :
return - V_26 ;
case V_363 :
if ( ! V_7 -> V_385 )
return - V_26 ;
if ( V_9 -> V_203 == V_7 -> V_78 )
break;
return - V_26 ;
case V_365 :
break;
}
return F_135 ( V_12 , V_7 ) ;
}
static int F_136 ( struct V_2 * V_2 , struct V_1 * V_10 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
return F_137 ( V_12 ) ;
}
static int F_138 ( struct V_2 * V_2 , T_1 V_325 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_13 ;
if ( V_325 & V_386 ) {
V_13 = F_139 ( V_9 , V_2 -> V_387 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_325 & V_388 ) {
V_13 = F_140 ( V_9 , V_2 -> V_389 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_325 & V_390 ) {
V_13 = F_141 ( V_9 , V_2 -> V_391 ) ;
if ( V_13 )
return V_13 ;
}
if ( V_325 & V_392 )
V_9 -> V_76 . V_44 . V_393 = V_2 -> V_394 ;
if ( V_325 & V_395 )
V_9 -> V_76 . V_44 . V_396 = V_2 -> V_397 ;
if ( V_325 &
( V_392 | V_395 ) )
F_114 ( V_9 , V_398 ) ;
return 0 ;
}
static int F_142 ( struct V_2 * V_2 ,
enum V_399 type , int V_400 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_354 * V_355 = V_9 -> V_76 . V_44 . V_78 ;
T_1 V_401 = 0 ;
switch ( type ) {
case V_402 :
V_9 -> V_403 = - 1 ;
break;
case V_404 :
if ( V_400 < 0 || ( V_400 % 100 ) )
return - V_344 ;
V_9 -> V_403 = F_143 ( V_400 ) ;
break;
case V_405 :
if ( V_400 < 0 || ( V_400 % 100 ) )
return - V_344 ;
if ( F_143 ( V_400 ) > V_355 -> V_406 )
return - V_40 ;
V_9 -> V_403 = F_143 ( V_400 ) ;
break;
}
F_114 ( V_9 , V_401 ) ;
return 0 ;
}
static int F_144 ( struct V_2 * V_2 , int * V_407 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
* V_407 = V_9 -> V_76 . V_44 . V_408 ;
return 0 ;
}
static int F_145 ( struct V_2 * V_2 , struct V_1 * V_10 ,
const T_2 * V_159 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
memcpy ( & V_12 -> V_15 . V_409 . V_410 , V_159 , V_160 ) ;
return 0 ;
}
static void F_146 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_147 ( V_9 ) ;
}
static int F_148 ( struct V_2 * V_2 , void * V_411 , int V_190 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( ! V_9 -> V_342 -> V_412 )
return - V_344 ;
return V_9 -> V_342 -> V_412 ( & V_9 -> V_76 , V_411 , V_190 ) ;
}
int F_149 ( struct V_11 * V_12 ,
enum V_413 V_414 )
{
const T_2 * V_171 ;
enum V_413 V_415 ;
int V_13 ;
F_150 ( & V_12 -> V_15 . V_23 . V_416 ) ;
V_415 = V_12 -> V_15 . V_23 . V_417 ;
V_12 -> V_15 . V_23 . V_417 = V_414 ;
if ( V_415 == V_414 &&
V_414 != V_418 )
return 0 ;
if ( ! V_12 -> V_15 . V_23 . V_419 ||
V_12 -> V_24 . V_147 . V_357 == V_361 ) {
F_18 ( & V_12 -> V_9 -> V_420 ) ;
F_151 ( V_12 -> V_9 ) ;
F_24 ( & V_12 -> V_9 -> V_420 ) ;
return 0 ;
}
V_171 = V_12 -> V_15 . V_23 . V_419 -> V_421 ;
if ( V_414 == V_418 ) {
if ( V_12 -> V_15 . V_23 . V_422 )
V_414 = V_423 ;
else
V_414 = V_424 ;
}
V_13 = F_152 ( V_12 , V_414 ,
V_171 , V_171 ) ;
if ( V_13 )
V_12 -> V_15 . V_23 . V_417 = V_415 ;
return V_13 ;
}
static int F_153 ( struct V_2 * V_2 , struct V_1 * V_10 ,
bool V_425 , int V_426 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_48 ( V_10 -> V_163 ) ;
if ( V_12 -> V_24 . type != V_22 )
return - V_344 ;
if ( ! ( V_9 -> V_76 . V_5 & V_427 ) )
return - V_344 ;
if ( V_425 == V_12 -> V_15 . V_23 . V_422 &&
V_426 == V_9 -> V_428 )
return 0 ;
V_12 -> V_15 . V_23 . V_422 = V_425 ;
V_9 -> V_428 = V_426 ;
F_18 ( & V_12 -> V_15 . V_23 . V_416 ) ;
F_149 ( V_12 , V_12 -> V_15 . V_23 . V_417 ) ;
F_24 ( & V_12 -> V_15 . V_23 . V_416 ) ;
if ( V_9 -> V_76 . V_5 & V_429 )
F_114 ( V_9 , V_430 ) ;
F_83 ( V_9 , - 1 ) ;
return 0 ;
}
static int F_154 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_4 V_431 , T_1 V_432 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_48 ( V_10 -> V_163 ) ;
struct V_433 * V_24 = & V_12 -> V_24 ;
struct V_434 * V_147 = & V_24 -> V_147 ;
if ( V_431 == V_147 -> V_435 &&
V_432 == V_147 -> V_436 )
return 0 ;
V_147 -> V_435 = V_431 ;
V_147 -> V_436 = V_432 ;
if ( ! ( V_9 -> V_76 . V_5 & V_437 ) ) {
if ( V_12 -> V_24 . type != V_22 )
return - V_344 ;
return 0 ;
}
if ( V_12 -> V_15 . V_23 . V_419 )
F_53 ( V_12 , V_438 ) ;
return 0 ;
}
static int F_155 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
const T_2 * V_159 ,
const struct V_439 * V_201 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = F_48 ( V_10 -> V_163 ) ;
int V_199 , V_17 ;
if ( V_9 -> V_76 . V_5 & V_440 ) {
V_17 = F_156 ( V_9 , V_12 , V_201 ) ;
if ( V_17 )
return V_17 ;
}
for ( V_199 = 0 ; V_199 < V_441 ; V_199 ++ )
V_12 -> V_442 [ V_199 ] = V_201 -> V_193 [ V_199 ] . V_80 ;
return 0 ;
}
static int F_157 ( struct V_8 * V_9 ,
struct V_1 * V_10 ,
struct V_354 * V_355 ,
enum V_356 V_443 ,
unsigned int V_444 , T_5 * V_53 )
{
int V_17 ;
T_1 V_445 ;
F_150 ( & V_9 -> V_416 ) ;
if ( V_9 -> V_446 )
return - V_26 ;
V_445 = F_158 () | 1 ;
* V_53 = V_445 ;
V_9 -> V_447 = V_10 ;
V_9 -> V_446 = V_445 ;
V_9 -> V_448 = V_355 ;
V_9 -> V_449 = V_443 ;
V_9 -> V_450 = V_444 ;
V_17 = F_159 ( V_9 , V_355 , V_443 , V_444 ) ;
if ( V_17 ) {
V_9 -> V_448 = NULL ;
V_9 -> V_446 = 0 ;
}
return V_17 ;
}
static int F_160 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
struct V_354 * V_355 ,
enum V_356 V_357 ,
unsigned int V_444 ,
T_5 * V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_342 -> V_451 ) {
int V_17 ;
F_18 ( & V_9 -> V_416 ) ;
V_17 = F_157 ( V_9 , V_10 ,
V_355 , V_357 ,
V_444 , V_53 ) ;
V_9 -> V_452 = false ;
F_24 ( & V_9 -> V_416 ) ;
return V_17 ;
}
return F_161 ( V_12 , V_355 , V_357 ,
V_444 , V_53 ) ;
}
static int F_162 ( struct V_8 * V_9 ,
T_5 V_53 )
{
int V_17 ;
F_150 ( & V_9 -> V_416 ) ;
if ( V_9 -> V_446 != V_53 )
return - V_47 ;
V_17 = F_163 ( V_9 ) ;
if ( V_17 )
return V_17 ;
V_9 -> V_446 = 0 ;
V_9 -> V_448 = NULL ;
F_164 ( V_9 ) ;
return 0 ;
}
static int F_165 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_5 V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
if ( V_9 -> V_342 -> V_453 ) {
int V_17 ;
F_18 ( & V_9 -> V_416 ) ;
V_17 = F_162 ( V_9 , V_53 ) ;
F_24 ( & V_9 -> V_416 ) ;
return V_17 ;
}
return F_166 ( V_12 , V_53 ) ;
}
static enum V_454
F_167 ( struct V_455 * V_456 , struct V_186 * V_187 )
{
if ( V_456 -> V_457 . V_458 && V_456 -> V_457 . V_459 )
F_168 ( V_456 -> V_12 -> V_10 ,
( unsigned long ) V_456 -> V_457 . V_459 ,
V_456 -> V_281 , V_456 -> V_282 , false , V_179 ) ;
return V_460 ;
}
static int F_169 ( struct V_2 * V_2 , struct V_1 * V_10 ,
struct V_354 * V_355 , bool V_461 ,
enum V_356 V_357 ,
bool V_462 , unsigned int V_458 ,
const T_2 * V_463 , T_6 V_190 , T_5 * V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_186 * V_187 ;
struct V_31 * V_21 ;
struct V_455 * V_456 ;
const struct V_464 * V_465 = ( void * ) V_463 ;
T_1 V_5 = V_466 |
V_467 ;
bool V_468 = false ;
if ( V_355 != V_9 -> V_469 &&
V_355 != V_9 -> V_203 )
V_468 = true ;
if ( V_462 &&
( V_357 != V_9 -> V_470 &&
V_357 != V_9 -> V_364 ) )
V_468 = true ;
if ( V_355 == V_9 -> V_448 ) {
V_468 = false ;
V_5 |= V_471 ;
}
if ( V_468 && ! V_461 )
return - V_26 ;
switch ( V_12 -> V_24 . type ) {
case V_371 :
case V_235 :
case V_18 :
case V_374 :
case V_372 :
if ( ! F_170 ( V_465 -> V_472 ) ||
V_465 -> V_15 . V_473 . V_474 == V_475 )
break;
F_30 () ;
V_21 = F_20 ( V_12 , V_465 -> V_188 ) ;
F_33 () ;
if ( ! V_21 )
return - V_476 ;
break;
case V_22 :
case V_373 :
break;
default:
return - V_344 ;
}
V_187 = F_61 ( V_9 -> V_76 . V_477 + V_190 ) ;
if ( ! V_187 )
return - V_180 ;
F_171 ( V_187 , V_9 -> V_76 . V_477 ) ;
memcpy ( F_62 ( V_187 , V_190 ) , V_463 , V_190 ) ;
F_172 ( V_187 ) -> V_5 = V_5 ;
V_187 -> V_10 = V_12 -> V_10 ;
* V_53 = ( unsigned long ) V_187 ;
if ( V_468 && V_9 -> V_342 -> V_478 ) {
int V_17 ;
F_172 ( V_187 ) -> V_79 = V_355 -> V_79 ;
F_18 ( & V_9 -> V_416 ) ;
if ( V_9 -> V_479 ) {
F_24 ( & V_9 -> V_416 ) ;
return - V_26 ;
}
V_17 = F_173 ( V_9 , V_187 , V_355 , V_357 , V_458 ) ;
if ( V_17 == 0 )
V_9 -> V_479 = * V_53 ;
F_24 ( & V_9 -> V_416 ) ;
if ( V_17 != 1 )
return V_17 ;
}
if ( V_468 && V_9 -> V_342 -> V_451 ) {
unsigned int V_444 ;
int V_17 ;
F_18 ( & V_9 -> V_416 ) ;
V_444 = 100 ;
if ( V_458 )
V_444 = V_458 ;
V_17 = F_157 ( V_9 , V_10 , V_355 ,
V_357 ,
V_444 , V_53 ) ;
if ( V_17 ) {
F_174 ( V_187 ) ;
F_24 ( & V_9 -> V_416 ) ;
return V_17 ;
}
V_9 -> V_452 = true ;
V_9 -> V_450 = V_458 ;
* V_53 ^= 2 ;
F_172 ( V_187 ) -> V_5 |= V_471 ;
V_9 -> V_480 = V_187 ;
V_9 -> V_481 = V_187 ;
F_24 ( & V_9 -> V_416 ) ;
return 0 ;
}
if ( ! V_468 && ! V_458 && ! V_12 -> V_24 . V_147 . V_482 ) {
F_175 ( V_12 , V_187 ) ;
return 0 ;
}
V_456 = F_54 ( sizeof( * V_456 ) + V_190 , V_179 ) ;
if ( ! V_456 ) {
F_174 ( V_187 ) ;
return - V_180 ;
}
V_456 -> type = V_483 ;
V_456 -> V_355 = V_355 ;
V_456 -> V_484 = V_357 ;
V_456 -> V_12 = V_12 ;
V_456 -> V_485 = F_167 ;
V_456 -> V_457 . V_459 = V_187 ;
V_456 -> V_457 . V_458 = V_458 ;
V_456 -> V_282 = V_190 ;
memcpy ( V_456 -> V_281 , V_463 , V_190 ) ;
F_176 ( V_456 ) ;
return 0 ;
}
static int F_177 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_5 V_53 )
{
struct V_11 * V_12 = F_5 ( V_10 ) ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_455 * V_456 ;
int V_17 = - V_47 ;
F_18 ( & V_9 -> V_416 ) ;
if ( V_9 -> V_342 -> V_486 &&
V_9 -> V_479 == V_53 ) {
V_17 = F_178 ( V_9 ) ;
if ( ! V_17 )
V_9 -> V_479 = 0 ;
F_24 ( & V_9 -> V_416 ) ;
return V_17 ;
}
if ( V_9 -> V_342 -> V_453 ) {
V_53 ^= 2 ;
V_17 = F_162 ( V_9 , V_53 ) ;
if ( V_17 == 0 ) {
F_174 ( V_9 -> V_480 ) ;
V_9 -> V_480 = NULL ;
V_9 -> V_481 = NULL ;
}
F_24 ( & V_9 -> V_416 ) ;
return V_17 ;
}
F_179 (wk, &local->work_list, list) {
if ( V_456 -> V_12 != V_12 )
continue;
if ( V_456 -> type != V_483 )
continue;
if ( V_53 != ( unsigned long ) V_456 -> V_457 . V_459 )
continue;
V_456 -> V_426 = V_107 ;
F_180 ( & V_9 -> V_76 , & V_9 -> V_487 ) ;
V_17 = 0 ;
break;
}
F_24 ( & V_9 -> V_416 ) ;
return V_17 ;
}
static void F_181 ( struct V_2 * V_2 ,
struct V_1 * V_10 ,
T_3 V_488 , bool V_489 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_488 != ( V_490 | V_491 ) )
return;
if ( V_489 )
V_9 -> V_492 ++ ;
else
V_9 -> V_492 -- ;
F_180 ( & V_9 -> V_76 , & V_9 -> V_493 ) ;
}
static int F_182 ( struct V_2 * V_2 , T_1 V_494 , T_1 V_495 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_496 )
return - V_344 ;
return F_183 ( V_9 , V_494 , V_495 ) ;
}
static int F_184 ( struct V_2 * V_2 , T_1 * V_494 , T_1 * V_495 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_185 ( V_9 , V_494 , V_495 ) ;
}
static int F_186 ( struct V_2 * V_2 , T_1 V_59 , T_1 V_497 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_187 ( V_9 , V_59 , V_497 ) ;
}
static void F_188 ( struct V_2 * V_2 ,
T_1 * V_59 , T_1 * V_498 , T_1 * V_497 , T_1 * V_499 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
F_189 ( V_9 , V_59 , V_498 , V_497 , V_499 ) ;
}
