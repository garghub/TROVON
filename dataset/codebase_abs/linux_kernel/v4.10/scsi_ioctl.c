static int F_1 ( int T_1 * V_1 )
{
static const int V_2 = 30527 ;
return F_2 ( V_2 , V_1 ) ;
}
static int F_3 ( struct V_3 * V_4 , int T_1 * V_1 )
{
return F_2 ( 0 , V_1 ) ;
}
static int F_4 ( struct V_3 * V_4 , int T_1 * V_1 )
{
return F_2 ( 0 , V_1 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
return F_6 ( V_4 -> V_5 ) ;
}
static int F_7 ( struct V_3 * V_4 , int T_1 * V_1 )
{
int V_6 , V_7 = F_8 ( V_6 , V_1 ) ;
if ( ! V_7 )
V_4 -> V_5 = F_9 ( V_6 ) ;
return V_7 ;
}
static int F_10 ( struct V_3 * V_4 )
{
unsigned int V_8 = F_11 ( V_4 ) ;
V_8 = F_12 (unsigned int, max_sectors, INT_MAX >> 9 ) ;
return V_8 << 9 ;
}
static int F_13 ( struct V_3 * V_4 , int T_1 * V_1 )
{
int V_9 = F_12 ( int , V_4 -> V_10 , F_10 ( V_4 ) ) ;
return F_2 ( V_9 , V_1 ) ;
}
static int F_14 ( struct V_3 * V_4 , int T_1 * V_1 )
{
int V_11 , V_7 = F_8 ( V_11 , V_1 ) ;
if ( V_7 )
return V_7 ;
if ( V_11 < 0 )
return - V_12 ;
V_4 -> V_10 = F_15 ( V_11 , F_10 ( V_4 ) ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , int T_1 * V_1 )
{
return F_2 ( 1 , V_1 ) ;
}
static void F_17 ( struct V_13 * V_14 )
{
F_18 ( V_15 , V_14 -> V_16 ) ;
F_18 ( V_17 , V_14 -> V_16 ) ;
F_18 ( V_18 , V_14 -> V_16 ) ;
F_18 ( V_19 , V_14 -> V_16 ) ;
F_18 ( V_20 , V_14 -> V_16 ) ;
F_18 ( V_21 , V_14 -> V_16 ) ;
F_18 ( V_22 , V_14 -> V_16 ) ;
F_18 ( V_23 , V_14 -> V_16 ) ;
F_18 ( V_24 , V_14 -> V_16 ) ;
F_18 ( V_25 , V_14 -> V_16 ) ;
F_18 ( V_26 , V_14 -> V_16 ) ;
F_18 ( V_27 , V_14 -> V_16 ) ;
F_18 ( V_28 , V_14 -> V_16 ) ;
F_18 ( V_29 , V_14 -> V_16 ) ;
F_18 ( V_30 , V_14 -> V_16 ) ;
F_18 ( V_31 , V_14 -> V_16 ) ;
F_18 ( V_32 , V_14 -> V_16 ) ;
F_18 ( V_33 , V_14 -> V_16 ) ;
F_18 ( V_34 , V_14 -> V_16 ) ;
F_18 ( V_35 , V_14 -> V_16 ) ;
F_18 ( V_36 , V_14 -> V_16 ) ;
F_18 ( V_37 , V_14 -> V_16 ) ;
F_18 ( V_38 , V_14 -> V_16 ) ;
F_18 ( V_39 , V_14 -> V_16 ) ;
F_18 ( V_40 , V_14 -> V_16 ) ;
F_18 ( V_41 , V_14 -> V_16 ) ;
F_18 ( V_42 , V_14 -> V_16 ) ;
F_18 ( V_43 , V_14 -> V_16 ) ;
F_18 ( V_44 , V_14 -> V_16 ) ;
F_18 ( V_45 , V_14 -> V_16 ) ;
F_18 ( V_46 , V_14 -> V_16 ) ;
F_18 ( V_47 , V_14 -> V_16 ) ;
F_18 ( V_48 , V_14 -> V_16 ) ;
F_18 ( V_49 , V_14 -> V_16 ) ;
F_18 ( V_50 , V_14 -> V_16 ) ;
F_18 ( V_51 , V_14 -> V_16 ) ;
F_18 ( V_52 , V_14 -> V_16 ) ;
F_18 ( V_53 , V_14 -> V_16 ) ;
F_18 ( V_54 , V_14 -> V_16 ) ;
F_18 ( V_55 , V_14 -> V_16 ) ;
F_18 ( V_56 , V_14 -> V_16 ) ;
F_18 ( V_57 , V_14 -> V_16 ) ;
F_18 ( V_58 , V_14 -> V_16 ) ;
F_18 ( V_59 , V_14 -> V_16 ) ;
F_18 ( V_60 , V_14 -> V_61 ) ;
F_18 ( V_62 , V_14 -> V_61 ) ;
F_18 ( V_63 , V_14 -> V_61 ) ;
F_18 ( V_64 , V_14 -> V_61 ) ;
F_18 ( V_65 , V_14 -> V_61 ) ;
F_18 ( V_66 , V_14 -> V_61 ) ;
F_18 ( V_67 , V_14 -> V_61 ) ;
F_18 ( V_68 , V_14 -> V_61 ) ;
F_18 ( V_69 , V_14 -> V_61 ) ;
F_18 ( V_70 , V_14 -> V_61 ) ;
F_18 ( V_71 , V_14 -> V_61 ) ;
F_18 ( V_72 , V_14 -> V_61 ) ;
F_18 ( V_73 , V_14 -> V_61 ) ;
F_18 ( V_74 , V_14 -> V_61 ) ;
F_18 ( V_75 , V_14 -> V_61 ) ;
F_18 ( V_76 , V_14 -> V_61 ) ;
F_18 ( V_77 , V_14 -> V_61 ) ;
F_18 ( V_78 , V_14 -> V_61 ) ;
F_18 ( V_79 , V_14 -> V_61 ) ;
F_18 ( V_80 , V_14 -> V_61 ) ;
F_18 ( V_81 , V_14 -> V_61 ) ;
F_18 ( V_82 , V_14 -> V_61 ) ;
F_18 ( V_83 , V_14 -> V_61 ) ;
F_18 ( V_84 , V_14 -> V_61 ) ;
F_18 ( V_85 , V_14 -> V_61 ) ;
F_18 ( V_86 , V_14 -> V_61 ) ;
F_18 ( V_87 , V_14 -> V_61 ) ;
F_18 ( V_88 , V_14 -> V_61 ) ;
F_18 ( V_89 , V_14 -> V_61 ) ;
F_18 ( V_90 , V_14 -> V_61 ) ;
F_18 ( V_91 , V_14 -> V_61 ) ;
}
int F_19 ( unsigned char * V_92 , T_2 V_93 )
{
struct V_13 * V_14 = & V_94 ;
if ( F_20 ( V_95 ) )
return 0 ;
if ( F_21 ( V_92 [ 0 ] , V_14 -> V_16 ) )
return 0 ;
if ( F_21 ( V_92 [ 0 ] , V_14 -> V_61 ) && V_93 )
return 0 ;
return - V_96 ;
}
static int F_22 ( struct V_3 * V_4 , struct V_97 * V_98 ,
struct V_99 * V_100 , T_2 V_101 )
{
if ( F_23 ( V_98 -> V_92 , V_100 -> V_102 , V_100 -> V_103 ) )
return - V_104 ;
if ( F_19 ( V_98 -> V_92 , V_101 & V_105 ) )
return - V_96 ;
V_98 -> V_103 = V_100 -> V_103 ;
V_98 -> V_6 = F_24 ( V_100 -> V_6 ) ;
if ( ! V_98 -> V_6 )
V_98 -> V_6 = V_4 -> V_5 ;
if ( ! V_98 -> V_6 )
V_98 -> V_6 = V_106 ;
if ( V_98 -> V_6 < V_107 )
V_98 -> V_6 = V_107 ;
return 0 ;
}
static int F_25 ( struct V_97 * V_98 , struct V_99 * V_100 ,
struct V_108 * V_108 )
{
int V_109 , V_110 = 0 ;
V_100 -> V_111 = V_98 -> V_112 & 0xff ;
V_100 -> V_113 = F_26 ( V_98 -> V_112 ) ;
V_100 -> V_114 = F_27 ( V_98 -> V_112 ) ;
V_100 -> V_115 = F_28 ( V_98 -> V_112 ) ;
V_100 -> V_116 = F_29 ( V_98 -> V_112 ) ;
V_100 -> V_117 = 0 ;
if ( V_100 -> V_113 || V_100 -> V_115 || V_100 -> V_116 )
V_100 -> V_117 |= V_118 ;
V_100 -> V_119 = V_98 -> V_120 ;
V_100 -> V_121 = 0 ;
if ( V_98 -> V_122 && V_100 -> V_123 ) {
int V_124 = F_15 ( ( unsigned int ) V_100 -> V_125 , V_98 -> V_122 ) ;
if ( ! F_30 ( V_100 -> V_123 , V_98 -> V_126 , V_124 ) )
V_100 -> V_121 = V_124 ;
else
V_110 = - V_104 ;
}
V_109 = F_31 ( V_108 ) ;
if ( ! V_110 )
V_110 = V_109 ;
return V_110 ;
}
static int F_32 ( struct V_3 * V_4 , struct V_127 * V_128 ,
struct V_99 * V_100 , T_2 V_101 )
{
unsigned long V_129 ;
T_3 V_110 = 0 ;
int V_130 = 0 ;
int V_131 = 0 ;
struct V_97 * V_98 ;
char V_126 [ V_132 ] ;
struct V_108 * V_108 ;
if ( V_100 -> V_133 != 'S' )
return - V_12 ;
if ( V_100 -> V_134 > ( F_33 ( V_4 ) << 9 ) )
return - V_135 ;
if ( V_100 -> V_134 )
switch ( V_100 -> V_136 ) {
default:
return - V_12 ;
case V_137 :
V_130 = 1 ;
break;
case V_138 :
case V_139 :
break;
}
if ( V_100 -> V_140 & V_141 )
V_131 = 1 ;
V_110 = - V_142 ;
V_98 = F_34 ( V_4 , V_130 ? V_143 : V_144 , V_145 ) ;
if ( F_35 ( V_98 ) )
return F_36 ( V_98 ) ;
F_37 ( V_98 ) ;
if ( V_100 -> V_103 > V_146 ) {
V_98 -> V_92 = F_38 ( V_100 -> V_103 , V_145 ) ;
if ( ! V_98 -> V_92 )
goto V_147;
}
V_110 = F_22 ( V_4 , V_98 , V_100 , V_101 ) ;
if ( V_110 < 0 )
goto V_148;
V_110 = 0 ;
if ( V_100 -> V_149 ) {
struct V_150 V_151 ;
struct V_152 * V_153 = NULL ;
V_110 = F_39 ( F_40 ( V_98 ) ,
V_100 -> V_154 , V_100 -> V_149 ,
0 , & V_153 , & V_151 ) ;
if ( V_110 < 0 )
goto V_148;
F_41 ( & V_151 , V_100 -> V_134 ) ;
V_110 = F_42 ( V_4 , V_98 , NULL , & V_151 , V_145 ) ;
F_43 ( V_153 ) ;
} else if ( V_100 -> V_134 )
V_110 = F_44 ( V_4 , V_98 , NULL , V_100 -> V_154 , V_100 -> V_134 ,
V_145 ) ;
if ( V_110 )
goto V_148;
V_108 = V_98 -> V_108 ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
V_98 -> V_126 = V_126 ;
V_98 -> V_122 = 0 ;
V_98 -> V_155 = 0 ;
V_129 = V_156 ;
F_45 ( V_4 , V_128 , V_98 , V_131 ) ;
V_100 -> V_157 = F_46 ( V_156 - V_129 ) ;
V_110 = F_25 ( V_98 , V_100 , V_108 ) ;
V_148:
if ( V_98 -> V_92 != V_98 -> V_158 )
F_43 ( V_98 -> V_92 ) ;
V_147:
F_47 ( V_98 ) ;
return V_110 ;
}
int F_48 ( struct V_3 * V_4 , struct V_127 * V_159 , T_2 V_101 ,
struct V_160 T_1 * V_161 )
{
struct V_97 * V_98 ;
int V_7 ;
unsigned int V_162 , V_163 , V_164 , V_165 , V_166 ;
char * V_167 = NULL , V_126 [ V_132 ] ;
if ( ! V_161 )
return - V_12 ;
if ( F_8 ( V_162 , & V_161 -> V_168 ) )
return - V_104 ;
if ( F_8 ( V_163 , & V_161 -> V_169 ) )
return - V_104 ;
if ( V_162 > V_170 || V_163 > V_170 )
return - V_12 ;
if ( F_8 ( V_165 , V_161 -> V_171 ) )
return - V_104 ;
V_164 = F_49 ( V_162 , V_163 ) ;
if ( V_164 ) {
V_167 = F_38 ( V_164 , V_4 -> V_172 | V_173 | V_174 ) ;
if ( ! V_167 )
return - V_142 ;
}
V_98 = F_34 ( V_4 , V_162 ? V_143 : V_144 , V_175 ) ;
if ( F_35 ( V_98 ) ) {
V_7 = F_36 ( V_98 ) ;
goto V_176;
}
F_37 ( V_98 ) ;
V_166 = F_50 ( V_165 ) ;
V_7 = - V_104 ;
V_98 -> V_103 = V_166 ;
if ( F_23 ( V_98 -> V_92 , V_161 -> V_171 , V_166 ) )
goto error;
if ( V_162 && F_23 ( V_167 , V_161 -> V_171 + V_166 , V_162 ) )
goto error;
V_7 = F_19 ( V_98 -> V_92 , V_101 & V_105 ) ;
if ( V_7 )
goto error;
V_98 -> V_155 = 5 ;
switch ( V_165 ) {
case V_177 :
case V_178 :
V_98 -> V_6 = V_179 ;
V_98 -> V_155 = 1 ;
break;
case V_30 :
V_98 -> V_6 = V_180 ;
break;
case V_181 :
V_98 -> V_6 = V_182 ;
break;
case V_183 :
V_98 -> V_6 = V_184 ;
break;
case V_23 :
V_98 -> V_6 = V_185 ;
V_98 -> V_155 = 1 ;
break;
default:
V_98 -> V_6 = V_106 ;
break;
}
if ( V_164 && F_51 ( V_4 , V_98 , V_167 , V_164 , V_175 ) ) {
V_7 = V_186 << 24 ;
goto error;
}
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
V_98 -> V_126 = V_126 ;
V_98 -> V_122 = 0 ;
F_45 ( V_4 , V_159 , V_98 , 0 ) ;
V_7 = V_98 -> V_112 & 0xff ;
if ( V_7 ) {
if ( V_98 -> V_122 && V_98 -> V_126 ) {
V_164 = ( V_187 > V_98 -> V_122 ) ?
V_98 -> V_122 : V_187 ;
if ( F_30 ( V_161 -> V_171 , V_98 -> V_126 , V_164 ) )
V_7 = - V_104 ;
}
} else {
if ( F_30 ( V_161 -> V_171 , V_167 , V_163 ) )
V_7 = - V_104 ;
}
error:
F_47 ( V_98 ) ;
V_176:
F_43 ( V_167 ) ;
return V_7 ;
}
static int F_52 ( struct V_3 * V_4 , struct V_127 * V_128 ,
int V_92 , int V_171 )
{
struct V_97 * V_98 ;
int V_7 ;
V_98 = F_34 ( V_4 , V_143 , V_175 ) ;
if ( F_35 ( V_98 ) )
return F_36 ( V_98 ) ;
F_37 ( V_98 ) ;
V_98 -> V_6 = V_106 ;
V_98 -> V_92 [ 0 ] = V_92 ;
V_98 -> V_92 [ 4 ] = V_171 ;
V_98 -> V_103 = 6 ;
V_7 = F_45 ( V_4 , V_128 , V_98 , 0 ) ;
F_47 ( V_98 ) ;
return V_7 ;
}
static inline int F_53 ( struct V_3 * V_4 ,
struct V_127 * V_128 , int V_171 )
{
return F_52 ( V_4 , V_128 , V_188 , V_171 ) ;
}
int F_54 ( struct V_3 * V_4 , struct V_127 * V_128 , T_2 V_101 ,
unsigned int V_92 , void T_1 * V_189 )
{
int V_7 ;
if ( ! V_4 )
return - V_190 ;
switch ( V_92 ) {
case V_191 :
V_7 = F_1 ( V_189 ) ;
break;
case V_192 :
V_7 = F_3 ( V_4 , V_189 ) ;
break;
case V_193 :
V_7 = F_4 ( V_4 , V_189 ) ;
break;
case V_194 :
V_7 = F_7 ( V_4 , V_189 ) ;
break;
case V_195 :
V_7 = F_5 ( V_4 ) ;
break;
case V_196 :
V_7 = F_13 ( V_4 , V_189 ) ;
break;
case V_197 :
V_7 = F_14 ( V_4 , V_189 ) ;
break;
case V_198 :
V_7 = F_16 ( V_4 , V_189 ) ;
break;
case V_199 : {
struct V_99 V_100 ;
V_7 = - V_104 ;
if ( F_23 ( & V_100 , V_189 , sizeof( V_100 ) ) )
break;
V_7 = F_32 ( V_4 , V_128 , & V_100 , V_101 ) ;
if ( V_7 == - V_104 )
break;
if ( F_30 ( V_189 , & V_100 , sizeof( V_100 ) ) )
V_7 = - V_104 ;
break;
}
case V_200 : {
struct V_201 V_202 ;
struct V_99 V_100 ;
V_7 = - V_104 ;
if ( F_23 ( & V_202 , V_189 , sizeof( V_202 ) ) )
break;
V_202 . V_6 = F_9 ( V_202 . V_6 ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_133 = 'S' ;
V_100 . V_103 = sizeof( V_202 . V_92 ) ;
V_100 . V_134 = V_202 . V_203 ;
V_7 = 0 ;
switch ( V_202 . V_204 ) {
case V_205 :
V_100 . V_136 = V_206 ;
break;
case V_207 :
V_100 . V_136 = V_137 ;
break;
case V_208 :
V_100 . V_136 = V_139 ;
break;
case V_209 :
V_100 . V_136 = V_210 ;
break;
default:
V_7 = - V_12 ;
}
if ( V_7 )
break;
V_100 . V_154 = V_202 . V_167 ;
V_100 . V_123 = V_202 . V_126 ;
if ( V_100 . V_123 )
V_100 . V_125 = sizeof( struct V_211 ) ;
V_100 . V_6 = F_46 ( V_202 . V_6 ) ;
V_100 . V_102 = ( (struct V_201 T_1 * ) V_189 ) -> V_92 ;
V_100 . V_103 = sizeof( V_202 . V_92 ) ;
V_7 = F_32 ( V_4 , V_128 , & V_100 , V_101 ) ;
if ( V_7 == - V_104 )
break;
if ( V_100 . V_111 )
V_7 = - V_135 ;
V_202 . V_212 = V_7 ;
V_202 . V_203 = V_100 . V_119 ;
if ( F_30 ( V_189 , & V_202 , sizeof( V_202 ) ) )
V_7 = - V_104 ;
break;
}
case V_213 :
F_55 ( V_214 L_1 , V_215 -> V_216 ) ;
V_7 = - V_12 ;
if ( ! V_189 )
break;
V_7 = F_48 ( V_4 , V_128 , V_101 , V_189 ) ;
break;
case V_217 :
V_7 = F_53 ( V_4 , V_128 , 0x03 ) ;
break;
case V_218 :
V_7 = F_53 ( V_4 , V_128 , 0x02 ) ;
break;
default:
V_7 = - V_219 ;
}
return V_7 ;
}
int F_56 ( struct V_220 * V_221 , unsigned int V_92 )
{
if ( V_221 && V_221 == V_221 -> V_222 )
return 0 ;
switch ( V_92 ) {
case V_192 :
case V_193 :
case V_223 :
case V_224 :
case V_191 :
case V_194 :
case V_195 :
case V_196 :
case V_197 :
case V_198 :
return 0 ;
case V_225 :
return - V_226 ;
default:
break;
}
if ( F_20 ( V_95 ) )
return 0 ;
F_57 ( V_214
L_2 , V_215 -> V_216 , V_92 ) ;
return - V_226 ;
}
int F_58 ( struct V_220 * V_221 , T_2 V_101 ,
unsigned int V_92 , void T_1 * V_189 )
{
int V_110 ;
V_110 = F_56 ( V_221 , V_92 ) ;
if ( V_110 < 0 )
return V_110 ;
return F_54 ( V_221 -> V_128 -> V_227 , V_221 -> V_128 , V_101 , V_92 , V_189 ) ;
}
static int T_4 F_59 ( void )
{
F_17 ( & V_94 ) ;
return 0 ;
}
