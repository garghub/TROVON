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
}
int F_19 ( unsigned char * V_89 , T_2 V_90 )
{
struct V_13 * V_14 = & V_91 ;
if ( F_20 ( V_92 ) )
return 0 ;
if ( F_21 ( V_89 [ 0 ] , V_14 -> V_16 ) )
return 0 ;
if ( F_21 ( V_89 [ 0 ] , V_14 -> V_61 ) && V_90 )
return 0 ;
return - V_93 ;
}
static int F_22 ( struct V_3 * V_4 , struct V_94 * V_95 ,
struct V_96 * V_97 , T_2 V_98 )
{
if ( F_23 ( V_95 -> V_89 , V_97 -> V_99 , V_97 -> V_100 ) )
return - V_101 ;
if ( F_19 ( V_95 -> V_89 , V_98 & V_102 ) )
return - V_93 ;
V_95 -> V_100 = V_97 -> V_100 ;
V_95 -> V_6 = F_24 ( V_97 -> V_6 ) ;
if ( ! V_95 -> V_6 )
V_95 -> V_6 = V_4 -> V_5 ;
if ( ! V_95 -> V_6 )
V_95 -> V_6 = V_103 ;
if ( V_95 -> V_6 < V_104 )
V_95 -> V_6 = V_104 ;
return 0 ;
}
static int F_25 ( struct V_94 * V_95 , struct V_96 * V_97 ,
struct V_105 * V_105 )
{
int V_106 , V_107 = 0 ;
V_97 -> V_108 = V_95 -> V_109 & 0xff ;
V_97 -> V_110 = F_26 ( V_95 -> V_109 ) ;
V_97 -> V_111 = F_27 ( V_95 -> V_109 ) ;
V_97 -> V_112 = F_28 ( V_95 -> V_109 ) ;
V_97 -> V_113 = F_29 ( V_95 -> V_109 ) ;
V_97 -> V_114 = 0 ;
if ( V_97 -> V_110 || V_97 -> V_112 || V_97 -> V_113 )
V_97 -> V_114 |= V_115 ;
V_97 -> V_116 = V_95 -> V_117 ;
V_97 -> V_118 = 0 ;
if ( V_95 -> V_119 && V_97 -> V_120 ) {
int V_121 = F_15 ( ( unsigned int ) V_97 -> V_122 , V_95 -> V_119 ) ;
if ( ! F_30 ( V_97 -> V_120 , V_95 -> V_123 , V_121 ) )
V_97 -> V_118 = V_121 ;
else
V_107 = - V_101 ;
}
V_106 = F_31 ( V_105 ) ;
if ( ! V_107 )
V_107 = V_106 ;
return V_107 ;
}
static int F_32 ( struct V_3 * V_4 , struct V_124 * V_125 ,
struct V_96 * V_97 , T_2 V_98 )
{
unsigned long V_126 ;
T_3 V_107 = 0 ;
int V_127 = 0 ;
int V_128 = 0 ;
struct V_94 * V_95 ;
char V_123 [ V_129 ] ;
struct V_105 * V_105 ;
if ( V_97 -> V_130 != 'S' )
return - V_12 ;
if ( V_97 -> V_131 > ( F_33 ( V_4 ) << 9 ) )
return - V_132 ;
if ( V_97 -> V_131 )
switch ( V_97 -> V_133 ) {
default:
return - V_12 ;
case V_134 :
V_127 = 1 ;
break;
case V_135 :
case V_136 :
break;
}
if ( V_97 -> V_137 & V_138 )
V_128 = 1 ;
V_107 = - V_139 ;
V_95 = F_34 ( V_4 , V_127 ? V_140 : V_141 , V_142 ) ;
if ( F_35 ( V_95 ) )
return F_36 ( V_95 ) ;
F_37 ( V_95 ) ;
if ( V_97 -> V_100 > V_143 ) {
V_95 -> V_89 = F_38 ( V_97 -> V_100 , V_142 ) ;
if ( ! V_95 -> V_89 )
goto V_144;
}
V_107 = F_22 ( V_4 , V_95 , V_97 , V_98 ) ;
if ( V_107 < 0 )
goto V_145;
V_107 = 0 ;
if ( V_97 -> V_146 ) {
struct V_147 V_148 ;
struct V_149 * V_150 = NULL ;
V_107 = F_39 ( F_40 ( V_95 ) ,
V_97 -> V_151 , V_97 -> V_146 ,
0 , & V_150 , & V_148 ) ;
if ( V_107 < 0 )
goto V_145;
F_41 ( & V_148 , V_97 -> V_131 ) ;
V_107 = F_42 ( V_4 , V_95 , NULL , & V_148 , V_142 ) ;
F_43 ( V_150 ) ;
} else if ( V_97 -> V_131 )
V_107 = F_44 ( V_4 , V_95 , NULL , V_97 -> V_151 , V_97 -> V_131 ,
V_142 ) ;
if ( V_107 )
goto V_145;
V_105 = V_95 -> V_105 ;
memset ( V_123 , 0 , sizeof( V_123 ) ) ;
V_95 -> V_123 = V_123 ;
V_95 -> V_119 = 0 ;
V_95 -> V_152 = 0 ;
V_126 = V_153 ;
F_45 ( V_4 , V_125 , V_95 , V_128 ) ;
V_97 -> V_154 = F_46 ( V_153 - V_126 ) ;
V_107 = F_25 ( V_95 , V_97 , V_105 ) ;
V_145:
if ( V_95 -> V_89 != V_95 -> V_155 )
F_43 ( V_95 -> V_89 ) ;
V_144:
F_47 ( V_95 ) ;
return V_107 ;
}
int F_48 ( struct V_3 * V_4 , struct V_124 * V_156 , T_2 V_98 ,
struct V_157 T_1 * V_158 )
{
struct V_94 * V_95 ;
int V_7 ;
unsigned int V_159 , V_160 , V_161 , V_162 , V_163 ;
char * V_164 = NULL , V_123 [ V_129 ] ;
if ( ! V_158 )
return - V_12 ;
if ( F_8 ( V_159 , & V_158 -> V_165 ) )
return - V_101 ;
if ( F_8 ( V_160 , & V_158 -> V_166 ) )
return - V_101 ;
if ( V_159 > V_167 || V_160 > V_167 )
return - V_12 ;
if ( F_8 ( V_162 , V_158 -> V_168 ) )
return - V_101 ;
V_161 = F_49 ( V_159 , V_160 ) ;
if ( V_161 ) {
V_164 = F_38 ( V_161 , V_4 -> V_169 | V_170 | V_171 ) ;
if ( ! V_164 )
return - V_139 ;
}
V_95 = F_34 ( V_4 , V_159 ? V_140 : V_141 , V_172 ) ;
if ( F_35 ( V_95 ) ) {
V_7 = F_36 ( V_95 ) ;
goto V_173;
}
F_37 ( V_95 ) ;
V_163 = F_50 ( V_162 ) ;
V_7 = - V_101 ;
V_95 -> V_100 = V_163 ;
if ( F_23 ( V_95 -> V_89 , V_158 -> V_168 , V_163 ) )
goto error;
if ( V_159 && F_23 ( V_164 , V_158 -> V_168 + V_163 , V_159 ) )
goto error;
V_7 = F_19 ( V_95 -> V_89 , V_98 & V_102 ) ;
if ( V_7 )
goto error;
V_95 -> V_152 = 5 ;
switch ( V_162 ) {
case V_174 :
case V_175 :
V_95 -> V_6 = V_176 ;
V_95 -> V_152 = 1 ;
break;
case V_30 :
V_95 -> V_6 = V_177 ;
break;
case V_178 :
V_95 -> V_6 = V_179 ;
break;
case V_180 :
V_95 -> V_6 = V_181 ;
break;
case V_23 :
V_95 -> V_6 = V_182 ;
V_95 -> V_152 = 1 ;
break;
default:
V_95 -> V_6 = V_103 ;
break;
}
if ( V_161 && F_51 ( V_4 , V_95 , V_164 , V_161 , V_172 ) ) {
V_7 = V_183 << 24 ;
goto error;
}
memset ( V_123 , 0 , sizeof( V_123 ) ) ;
V_95 -> V_123 = V_123 ;
V_95 -> V_119 = 0 ;
F_45 ( V_4 , V_156 , V_95 , 0 ) ;
V_7 = V_95 -> V_109 & 0xff ;
if ( V_7 ) {
if ( V_95 -> V_119 && V_95 -> V_123 ) {
V_161 = ( V_184 > V_95 -> V_119 ) ?
V_95 -> V_119 : V_184 ;
if ( F_30 ( V_158 -> V_168 , V_95 -> V_123 , V_161 ) )
V_7 = - V_101 ;
}
} else {
if ( F_30 ( V_158 -> V_168 , V_164 , V_160 ) )
V_7 = - V_101 ;
}
error:
F_47 ( V_95 ) ;
V_173:
F_43 ( V_164 ) ;
return V_7 ;
}
static int F_52 ( struct V_3 * V_4 , struct V_124 * V_125 ,
int V_89 , int V_168 )
{
struct V_94 * V_95 ;
int V_7 ;
V_95 = F_34 ( V_4 , V_140 , V_172 ) ;
if ( F_35 ( V_95 ) )
return F_36 ( V_95 ) ;
F_37 ( V_95 ) ;
V_95 -> V_6 = V_103 ;
V_95 -> V_89 [ 0 ] = V_89 ;
V_95 -> V_89 [ 4 ] = V_168 ;
V_95 -> V_100 = 6 ;
V_7 = F_45 ( V_4 , V_125 , V_95 , 0 ) ;
F_47 ( V_95 ) ;
return V_7 ;
}
static inline int F_53 ( struct V_3 * V_4 ,
struct V_124 * V_125 , int V_168 )
{
return F_52 ( V_4 , V_125 , V_185 , V_168 ) ;
}
int F_54 ( struct V_3 * V_4 , struct V_124 * V_125 , T_2 V_98 ,
unsigned int V_89 , void T_1 * V_186 )
{
int V_7 ;
if ( ! V_4 )
return - V_187 ;
switch ( V_89 ) {
case V_188 :
V_7 = F_1 ( V_186 ) ;
break;
case V_189 :
V_7 = F_3 ( V_4 , V_186 ) ;
break;
case V_190 :
V_7 = F_4 ( V_4 , V_186 ) ;
break;
case V_191 :
V_7 = F_7 ( V_4 , V_186 ) ;
break;
case V_192 :
V_7 = F_5 ( V_4 ) ;
break;
case V_193 :
V_7 = F_13 ( V_4 , V_186 ) ;
break;
case V_194 :
V_7 = F_14 ( V_4 , V_186 ) ;
break;
case V_195 :
V_7 = F_16 ( V_4 , V_186 ) ;
break;
case V_196 : {
struct V_96 V_97 ;
V_7 = - V_101 ;
if ( F_23 ( & V_97 , V_186 , sizeof( V_97 ) ) )
break;
V_7 = F_32 ( V_4 , V_125 , & V_97 , V_98 ) ;
if ( V_7 == - V_101 )
break;
if ( F_30 ( V_186 , & V_97 , sizeof( V_97 ) ) )
V_7 = - V_101 ;
break;
}
case V_197 : {
struct V_198 V_199 ;
struct V_96 V_97 ;
V_7 = - V_101 ;
if ( F_23 ( & V_199 , V_186 , sizeof( V_199 ) ) )
break;
V_199 . V_6 = F_9 ( V_199 . V_6 ) ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_130 = 'S' ;
V_97 . V_100 = sizeof( V_199 . V_89 ) ;
V_97 . V_131 = V_199 . V_200 ;
V_7 = 0 ;
switch ( V_199 . V_201 ) {
case V_202 :
V_97 . V_133 = V_203 ;
break;
case V_204 :
V_97 . V_133 = V_134 ;
break;
case V_205 :
V_97 . V_133 = V_136 ;
break;
case V_206 :
V_97 . V_133 = V_207 ;
break;
default:
V_7 = - V_12 ;
}
if ( V_7 )
break;
V_97 . V_151 = V_199 . V_164 ;
V_97 . V_120 = V_199 . V_123 ;
if ( V_97 . V_120 )
V_97 . V_122 = sizeof( struct V_208 ) ;
V_97 . V_6 = F_46 ( V_199 . V_6 ) ;
V_97 . V_99 = ( (struct V_198 T_1 * ) V_186 ) -> V_89 ;
V_97 . V_100 = sizeof( V_199 . V_89 ) ;
V_7 = F_32 ( V_4 , V_125 , & V_97 , V_98 ) ;
if ( V_7 == - V_101 )
break;
if ( V_97 . V_108 )
V_7 = - V_132 ;
V_199 . V_209 = V_7 ;
V_199 . V_200 = V_97 . V_116 ;
if ( F_30 ( V_186 , & V_199 , sizeof( V_199 ) ) )
V_7 = - V_101 ;
break;
}
case V_210 :
F_55 ( V_211 L_1 , V_212 -> V_213 ) ;
V_7 = - V_12 ;
if ( ! V_186 )
break;
V_7 = F_48 ( V_4 , V_125 , V_98 , V_186 ) ;
break;
case V_214 :
V_7 = F_53 ( V_4 , V_125 , 0x03 ) ;
break;
case V_215 :
V_7 = F_53 ( V_4 , V_125 , 0x02 ) ;
break;
default:
V_7 = - V_216 ;
}
return V_7 ;
}
int F_56 ( struct V_217 * V_218 , unsigned int V_89 )
{
if ( V_218 && V_218 == V_218 -> V_219 )
return 0 ;
switch ( V_89 ) {
case V_189 :
case V_190 :
case V_220 :
case V_221 :
case V_188 :
case V_191 :
case V_192 :
case V_193 :
case V_194 :
case V_195 :
return 0 ;
case V_222 :
return - V_223 ;
default:
break;
}
if ( F_20 ( V_92 ) )
return 0 ;
F_57 ( V_211
L_2 , V_212 -> V_213 , V_89 ) ;
return - V_223 ;
}
int F_58 ( struct V_217 * V_218 , T_2 V_98 ,
unsigned int V_89 , void T_1 * V_186 )
{
int V_107 ;
V_107 = F_56 ( V_218 , V_89 ) ;
if ( V_107 < 0 )
return V_107 ;
return F_54 ( V_218 -> V_125 -> V_224 , V_218 -> V_125 , V_98 , V_89 , V_186 ) ;
}
static int T_4 F_59 ( void )
{
F_17 ( & V_91 ) ;
return 0 ;
}
