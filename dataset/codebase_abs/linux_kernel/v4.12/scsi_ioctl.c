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
struct V_102 * V_103 = F_23 ( V_98 ) ;
if ( F_24 ( V_103 -> V_92 , V_100 -> V_104 , V_100 -> V_105 ) )
return - V_106 ;
if ( F_19 ( V_103 -> V_92 , V_101 & V_107 ) )
return - V_96 ;
V_103 -> V_105 = V_100 -> V_105 ;
V_98 -> V_6 = F_25 ( V_100 -> V_6 ) ;
if ( ! V_98 -> V_6 )
V_98 -> V_6 = V_4 -> V_5 ;
if ( ! V_98 -> V_6 )
V_98 -> V_6 = V_108 ;
if ( V_98 -> V_6 < V_109 )
V_98 -> V_6 = V_109 ;
return 0 ;
}
static int F_26 ( struct V_97 * V_98 , struct V_99 * V_100 ,
struct V_110 * V_110 )
{
struct V_102 * V_103 = F_23 ( V_98 ) ;
int V_111 , V_112 = 0 ;
V_100 -> V_113 = V_103 -> V_114 & 0xff ;
V_100 -> V_115 = F_27 ( V_103 -> V_114 ) ;
V_100 -> V_116 = F_28 ( V_103 -> V_114 ) ;
V_100 -> V_117 = F_29 ( V_103 -> V_114 ) ;
V_100 -> V_118 = F_30 ( V_103 -> V_114 ) ;
V_100 -> V_119 = 0 ;
if ( V_100 -> V_115 || V_100 -> V_117 || V_100 -> V_118 )
V_100 -> V_119 |= V_120 ;
V_100 -> V_121 = V_103 -> V_122 ;
V_100 -> V_123 = 0 ;
if ( V_103 -> V_124 && V_100 -> V_125 ) {
int V_126 = F_15 ( ( unsigned int ) V_100 -> V_127 , V_103 -> V_124 ) ;
if ( ! F_31 ( V_100 -> V_125 , V_103 -> V_128 , V_126 ) )
V_100 -> V_123 = V_126 ;
else
V_112 = - V_106 ;
}
V_111 = F_32 ( V_110 ) ;
if ( ! V_112 )
V_112 = V_111 ;
return V_112 ;
}
static int F_33 ( struct V_3 * V_4 , struct V_129 * V_130 ,
struct V_99 * V_100 , T_2 V_101 )
{
unsigned long V_131 ;
T_3 V_112 = 0 ;
int V_132 = 0 ;
int V_133 = 0 ;
struct V_97 * V_98 ;
struct V_102 * V_103 ;
struct V_110 * V_110 ;
if ( V_100 -> V_134 != 'S' )
return - V_12 ;
if ( V_100 -> V_135 > ( F_34 ( V_4 ) << 9 ) )
return - V_136 ;
if ( V_100 -> V_135 )
switch ( V_100 -> V_137 ) {
default:
return - V_12 ;
case V_138 :
V_132 = 1 ;
break;
case V_139 :
case V_140 :
break;
}
if ( V_100 -> V_141 & V_142 )
V_133 = 1 ;
V_112 = - V_143 ;
V_98 = F_35 ( V_4 , V_132 ? V_144 : V_145 ,
V_146 ) ;
if ( F_36 ( V_98 ) )
return F_37 ( V_98 ) ;
V_103 = F_23 ( V_98 ) ;
F_38 ( V_98 ) ;
if ( V_100 -> V_105 > V_147 ) {
V_103 -> V_92 = F_39 ( V_100 -> V_105 , V_146 ) ;
if ( ! V_103 -> V_92 )
goto V_148;
}
V_112 = F_22 ( V_4 , V_98 , V_100 , V_101 ) ;
if ( V_112 < 0 )
goto V_149;
V_112 = 0 ;
if ( V_100 -> V_150 ) {
struct V_151 V_152 ;
struct V_153 * V_154 = NULL ;
V_112 = F_40 ( F_41 ( V_98 ) ,
V_100 -> V_155 , V_100 -> V_150 ,
0 , & V_154 , & V_152 ) ;
if ( V_112 < 0 )
goto V_149;
F_42 ( & V_152 , V_100 -> V_135 ) ;
V_112 = F_43 ( V_4 , V_98 , NULL , & V_152 , V_146 ) ;
F_44 ( V_154 ) ;
} else if ( V_100 -> V_135 )
V_112 = F_45 ( V_4 , V_98 , NULL , V_100 -> V_155 , V_100 -> V_135 ,
V_146 ) ;
if ( V_112 )
goto V_149;
V_110 = V_98 -> V_110 ;
V_103 -> V_156 = 0 ;
V_131 = V_157 ;
F_46 ( V_4 , V_130 , V_98 , V_133 ) ;
V_100 -> V_158 = F_47 ( V_157 - V_131 ) ;
V_112 = F_26 ( V_98 , V_100 , V_110 ) ;
V_149:
F_48 ( V_103 ) ;
V_148:
F_49 ( V_98 ) ;
return V_112 ;
}
int F_50 ( struct V_3 * V_4 , struct V_129 * V_159 , T_2 V_101 ,
struct V_160 T_1 * V_161 )
{
struct V_97 * V_98 ;
struct V_102 * V_103 ;
int V_7 ;
unsigned int V_162 , V_163 , V_164 , V_165 , V_166 ;
char * V_167 = NULL ;
if ( ! V_161 )
return - V_12 ;
if ( F_8 ( V_162 , & V_161 -> V_168 ) )
return - V_106 ;
if ( F_8 ( V_163 , & V_161 -> V_169 ) )
return - V_106 ;
if ( V_162 > V_170 || V_163 > V_170 )
return - V_12 ;
if ( F_8 ( V_165 , V_161 -> V_171 ) )
return - V_106 ;
V_164 = F_51 ( V_162 , V_163 ) ;
if ( V_164 ) {
V_167 = F_39 ( V_164 , V_4 -> V_172 | V_173 | V_174 ) ;
if ( ! V_167 )
return - V_143 ;
}
V_98 = F_35 ( V_4 , V_162 ? V_144 : V_145 ,
V_175 ) ;
if ( F_36 ( V_98 ) ) {
V_7 = F_37 ( V_98 ) ;
goto V_176;
}
V_103 = F_23 ( V_98 ) ;
F_38 ( V_98 ) ;
V_166 = F_52 ( V_165 ) ;
V_7 = - V_106 ;
V_103 -> V_105 = V_166 ;
if ( F_24 ( V_103 -> V_92 , V_161 -> V_171 , V_166 ) )
goto error;
if ( V_162 && F_24 ( V_167 , V_161 -> V_171 + V_166 , V_162 ) )
goto error;
V_7 = F_19 ( V_103 -> V_92 , V_101 & V_107 ) ;
if ( V_7 )
goto error;
V_103 -> V_156 = 5 ;
switch ( V_165 ) {
case V_177 :
case V_178 :
V_98 -> V_6 = V_179 ;
V_103 -> V_156 = 1 ;
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
V_103 -> V_156 = 1 ;
break;
default:
V_98 -> V_6 = V_108 ;
break;
}
if ( V_164 && F_53 ( V_4 , V_98 , V_167 , V_164 , V_175 ) ) {
V_7 = V_186 << 24 ;
goto error;
}
F_46 ( V_4 , V_159 , V_98 , 0 ) ;
V_7 = V_103 -> V_114 & 0xff ;
if ( V_7 ) {
if ( V_103 -> V_124 && V_103 -> V_128 ) {
V_164 = ( V_187 > V_103 -> V_124 ) ?
V_103 -> V_124 : V_187 ;
if ( F_31 ( V_161 -> V_171 , V_103 -> V_128 , V_164 ) )
V_7 = - V_106 ;
}
} else {
if ( F_31 ( V_161 -> V_171 , V_167 , V_163 ) )
V_7 = - V_106 ;
}
error:
F_49 ( V_98 ) ;
V_176:
F_44 ( V_167 ) ;
return V_7 ;
}
static int F_54 ( struct V_3 * V_4 , struct V_129 * V_130 ,
int V_92 , int V_171 )
{
struct V_97 * V_98 ;
int V_7 ;
V_98 = F_35 ( V_4 , V_144 , V_175 ) ;
if ( F_36 ( V_98 ) )
return F_37 ( V_98 ) ;
F_38 ( V_98 ) ;
V_98 -> V_6 = V_108 ;
F_23 ( V_98 ) -> V_92 [ 0 ] = V_92 ;
F_23 ( V_98 ) -> V_92 [ 4 ] = V_171 ;
F_23 ( V_98 ) -> V_105 = 6 ;
F_46 ( V_4 , V_130 , V_98 , 0 ) ;
V_7 = F_23 ( V_98 ) -> V_114 ? - V_136 : 0 ;
F_49 ( V_98 ) ;
return V_7 ;
}
static inline int F_55 ( struct V_3 * V_4 ,
struct V_129 * V_130 , int V_171 )
{
return F_54 ( V_4 , V_130 , V_188 , V_171 ) ;
}
int F_56 ( struct V_3 * V_4 , struct V_129 * V_130 , T_2 V_101 ,
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
V_7 = - V_106 ;
if ( F_24 ( & V_100 , V_189 , sizeof( V_100 ) ) )
break;
V_7 = F_33 ( V_4 , V_130 , & V_100 , V_101 ) ;
if ( V_7 == - V_106 )
break;
if ( F_31 ( V_189 , & V_100 , sizeof( V_100 ) ) )
V_7 = - V_106 ;
break;
}
case V_200 : {
struct V_201 V_202 ;
struct V_99 V_100 ;
V_7 = - V_106 ;
if ( F_24 ( & V_202 , V_189 , sizeof( V_202 ) ) )
break;
V_202 . V_6 = F_9 ( V_202 . V_6 ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_134 = 'S' ;
V_100 . V_105 = sizeof( V_202 . V_92 ) ;
V_100 . V_135 = V_202 . V_203 ;
V_7 = 0 ;
switch ( V_202 . V_204 ) {
case V_205 :
V_100 . V_137 = V_206 ;
break;
case V_207 :
V_100 . V_137 = V_138 ;
break;
case V_208 :
V_100 . V_137 = V_140 ;
break;
case V_209 :
V_100 . V_137 = V_210 ;
break;
default:
V_7 = - V_12 ;
}
if ( V_7 )
break;
V_100 . V_155 = V_202 . V_167 ;
V_100 . V_125 = V_202 . V_128 ;
if ( V_100 . V_125 )
V_100 . V_127 = sizeof( struct V_211 ) ;
V_100 . V_6 = F_47 ( V_202 . V_6 ) ;
V_100 . V_104 = ( (struct V_201 T_1 * ) V_189 ) -> V_92 ;
V_100 . V_105 = sizeof( V_202 . V_92 ) ;
V_7 = F_33 ( V_4 , V_130 , & V_100 , V_101 ) ;
if ( V_7 == - V_106 )
break;
if ( V_100 . V_113 )
V_7 = - V_136 ;
V_202 . V_212 = V_7 ;
V_202 . V_203 = V_100 . V_121 ;
if ( F_31 ( V_189 , & V_202 , sizeof( V_202 ) ) )
V_7 = - V_106 ;
break;
}
case V_213 :
F_57 ( V_214 L_1 , V_215 -> V_216 ) ;
V_7 = - V_12 ;
if ( ! V_189 )
break;
V_7 = F_50 ( V_4 , V_130 , V_101 , V_189 ) ;
break;
case V_217 :
V_7 = F_55 ( V_4 , V_130 , 0x03 ) ;
break;
case V_218 :
V_7 = F_55 ( V_4 , V_130 , 0x02 ) ;
break;
default:
V_7 = - V_219 ;
}
return V_7 ;
}
int F_58 ( struct V_220 * V_221 , unsigned int V_92 )
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
F_59 ( V_214
L_2 , V_215 -> V_216 , V_92 ) ;
return - V_226 ;
}
int F_60 ( struct V_220 * V_221 , T_2 V_101 ,
unsigned int V_92 , void T_1 * V_189 )
{
int V_112 ;
V_112 = F_58 ( V_221 , V_92 ) ;
if ( V_112 < 0 )
return V_112 ;
return F_56 ( V_221 -> V_130 -> V_227 , V_221 -> V_130 , V_101 , V_92 , V_189 ) ;
}
void F_38 ( struct V_97 * V_98 )
{
struct V_102 * V_103 = F_23 ( V_98 ) ;
memset ( V_103 -> V_228 , 0 , sizeof( V_103 -> V_228 ) ) ;
V_103 -> V_92 = V_103 -> V_228 ;
V_103 -> V_105 = V_147 ;
V_103 -> V_124 = 0 ;
}
static int T_4 F_61 ( void )
{
F_17 ( & V_94 ) ;
return 0 ;
}
