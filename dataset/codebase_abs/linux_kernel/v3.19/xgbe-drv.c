static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 , * V_8 ;
unsigned int V_9 , V_10 ;
int V_11 = - V_12 ;
V_9 = F_2 (unsigned int, pdata->tx_ring_count, pdata->rx_ring_count) ;
V_4 = F_3 ( V_9 , sizeof( struct V_3 ) , V_13 ) ;
if ( ! V_4 )
goto V_14;
V_7 = F_3 ( V_2 -> V_15 , sizeof( struct V_6 ) ,
V_13 ) ;
if ( ! V_7 )
goto V_16;
V_8 = F_3 ( V_2 -> V_17 , sizeof( struct V_6 ) ,
V_13 ) ;
if ( ! V_8 )
goto V_18;
for ( V_10 = 0 , V_5 = V_4 ; V_10 < V_9 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_19 , sizeof( V_5 -> V_19 ) , L_1 , V_10 ) ;
V_5 -> V_2 = V_2 ;
V_5 -> V_20 = V_10 ;
V_5 -> V_21 = V_2 -> V_22 + V_23 +
( V_24 * V_10 ) ;
if ( V_2 -> V_25 ) {
V_11 = F_4 ( V_2 -> V_26 , V_10 + 1 ) ;
if ( V_11 < 0 ) {
F_5 ( V_2 -> V_27 ,
L_2 ,
V_10 + 1 ) ;
goto V_28;
}
V_5 -> V_29 = V_11 ;
}
if ( V_10 < V_2 -> V_15 ) {
F_6 ( & V_7 -> V_30 ) ;
V_5 -> V_7 = V_7 ++ ;
}
if ( V_10 < V_2 -> V_17 ) {
F_6 ( & V_8 -> V_30 ) ;
V_5 -> V_8 = V_8 ++ ;
}
F_7 ( L_3 ,
V_5 -> V_19 , V_5 -> V_20 , V_5 -> V_21 ,
V_5 -> V_29 , V_5 -> V_7 , V_5 -> V_8 ) ;
}
V_2 -> V_5 = V_4 ;
V_2 -> V_31 = V_9 ;
return 0 ;
V_28:
F_8 ( V_8 ) ;
V_18:
F_8 ( V_7 ) ;
V_16:
F_8 ( V_4 ) ;
V_14:
return V_11 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_5 )
return;
F_8 ( V_2 -> V_5 -> V_8 ) ;
F_8 ( V_2 -> V_5 -> V_7 ) ;
F_8 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
V_2 -> V_31 = 0 ;
}
static inline unsigned int F_10 ( struct V_6 * V_32 )
{
return ( V_32 -> V_33 - ( V_32 -> V_34 - V_32 -> V_35 ) ) ;
}
static int F_11 ( struct V_3 * V_5 ,
struct V_6 * V_32 , unsigned int V_9 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_9 > F_10 ( V_32 ) ) {
F_7 ( L_4 ) ;
F_12 ( V_2 -> V_27 , V_5 -> V_20 ) ;
V_32 -> V_36 . V_37 = 1 ;
if ( V_32 -> V_36 . V_38 )
V_2 -> V_39 . V_40 ( V_5 , V_32 ) ;
return V_41 ;
}
return 0 ;
}
static int F_13 ( struct V_42 * V_27 , unsigned int V_43 )
{
unsigned int V_44 ;
if ( V_43 > V_45 ) {
F_14 ( V_27 , L_5 ) ;
return - V_46 ;
}
V_44 = V_43 + V_47 + V_48 + V_49 ;
V_44 = F_15 ( V_44 , V_50 , V_51 ) ;
V_44 = ( V_44 + V_52 - 1 ) &
~ ( V_52 - 1 ) ;
return V_44 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
enum V_54 V_55 ;
unsigned int V_10 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( V_5 -> V_7 && V_5 -> V_8 )
V_55 = V_56 ;
else if ( V_5 -> V_7 )
V_55 = V_57 ;
else if ( V_5 -> V_8 )
V_55 = V_58 ;
else
continue;
V_39 -> V_59 ( V_5 , V_55 ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
enum V_54 V_55 ;
unsigned int V_10 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( V_5 -> V_7 && V_5 -> V_8 )
V_55 = V_56 ;
else if ( V_5 -> V_7 )
V_55 = V_57 ;
else if ( V_5 -> V_8 )
V_55 = V_58 ;
else
continue;
V_39 -> V_60 ( V_5 , V_55 ) ;
}
}
static T_1 F_18 ( int V_61 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
unsigned int V_63 , V_64 ;
unsigned int V_65 , V_66 ;
unsigned int V_10 ;
V_63 = F_19 ( V_2 , V_67 ) ;
if ( ! V_63 )
goto V_68;
F_7 ( L_6 , V_63 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ ) {
if ( ! ( V_63 & ( 1 << V_10 ) ) )
continue;
V_5 = V_2 -> V_5 + V_10 ;
V_64 = F_20 ( V_5 , V_69 ) ;
F_7 ( L_7 , V_10 , V_64 ) ;
if ( F_21 ( V_64 , V_69 , V_70 ) ||
F_21 ( V_64 , V_69 , V_71 ) ) {
if ( F_22 ( & V_2 -> V_72 ) ) {
F_17 ( V_2 ) ;
F_23 ( & V_2 -> V_72 ) ;
}
}
if ( F_21 ( V_64 , V_69 , V_73 ) )
F_24 ( & V_2 -> V_74 ) ;
F_25 ( V_5 , V_69 , V_64 ) ;
}
if ( F_21 ( V_63 , V_67 , V_75 ) ) {
V_65 = F_19 ( V_2 , V_76 ) ;
if ( F_21 ( V_65 , V_76 , V_77 ) )
V_39 -> V_78 ( V_2 ) ;
if ( F_21 ( V_65 , V_76 , V_79 ) )
V_39 -> V_80 ( V_2 ) ;
if ( F_21 ( V_65 , V_76 , V_81 ) ) {
V_66 = F_19 ( V_2 , V_82 ) ;
if ( F_21 ( V_66 , V_82 , V_83 ) ) {
V_2 -> V_84 =
V_39 -> V_85 ( V_2 ) ;
F_24 ( & V_2 -> V_86 ) ;
}
}
}
F_7 ( L_6 , F_19 ( V_2 , V_67 ) ) ;
V_68:
return V_87 ;
}
static T_1 F_26 ( int V_61 , void * V_62 )
{
struct V_3 * V_5 = V_62 ;
if ( F_22 ( & V_5 -> V_72 ) ) {
F_27 ( V_5 -> V_29 ) ;
F_23 ( & V_5 -> V_72 ) ;
}
return V_87 ;
}
static enum V_88 F_28 ( struct V_89 * V_90 )
{
struct V_3 * V_5 = F_29 ( V_90 ,
struct V_3 ,
V_91 ) ;
struct V_6 * V_32 = V_5 -> V_7 ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_92 * V_72 ;
unsigned long V_93 ;
F_7 ( L_8 ) ;
V_72 = ( V_2 -> V_25 ) ? & V_5 -> V_72 : & V_2 -> V_72 ;
F_30 ( & V_32 -> V_30 , V_93 ) ;
if ( F_22 ( V_72 ) ) {
if ( V_2 -> V_25 )
F_31 ( V_5 -> V_29 ) ;
else
F_17 ( V_2 ) ;
F_23 ( V_72 ) ;
}
V_5 -> V_94 = 0 ;
F_32 ( & V_32 -> V_30 , V_93 ) ;
F_7 ( L_9 ) ;
return V_95 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_10 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_7 ( L_11 , V_5 -> V_19 ) ;
F_34 ( & V_5 -> V_91 , V_96 ,
V_97 ) ;
V_5 -> V_91 . V_98 = F_28 ;
}
F_7 ( L_12 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_13 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_7 ( L_14 , V_5 -> V_19 ) ;
V_5 -> V_94 = 0 ;
F_36 ( & V_5 -> V_91 ) ;
}
F_7 ( L_15 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
unsigned int V_99 , V_100 , V_101 ;
struct V_102 * V_103 = & V_2 -> V_103 ;
F_7 ( L_16 ) ;
V_99 = F_19 ( V_2 , V_104 ) ;
V_100 = F_19 ( V_2 , V_105 ) ;
V_101 = F_19 ( V_2 , V_106 ) ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
V_103 -> V_107 = F_19 ( V_2 , V_108 ) ;
V_103 -> V_109 = F_21 ( V_99 , V_104 , V_110 ) ;
V_103 -> V_111 = F_21 ( V_99 , V_104 , V_112 ) ;
V_103 -> V_113 = F_21 ( V_99 , V_104 , V_114 ) ;
V_103 -> V_115 = F_21 ( V_99 , V_104 , V_116 ) ;
V_103 -> V_117 = F_21 ( V_99 , V_104 , V_118 ) ;
V_103 -> V_119 = F_21 ( V_99 , V_104 , V_120 ) ;
V_103 -> V_121 = F_21 ( V_99 , V_104 , V_122 ) ;
V_103 -> V_123 = F_21 ( V_99 , V_104 , V_124 ) ;
V_103 -> V_125 = F_21 ( V_99 , V_104 , V_126 ) ;
V_103 -> V_127 = F_21 ( V_99 , V_104 , V_128 ) ;
V_103 -> V_129 = F_21 ( V_99 , V_104 , V_130 ) ;
V_103 -> V_131 = F_21 ( V_99 , V_104 ,
V_132 ) ;
V_103 -> V_133 = F_21 ( V_99 , V_104 , V_134 ) ;
V_103 -> V_135 = F_21 ( V_99 , V_104 , V_136 ) ;
V_103 -> V_137 = F_21 ( V_100 , V_105 ,
V_138 ) ;
V_103 -> V_139 = F_21 ( V_100 , V_105 ,
V_140 ) ;
V_103 -> V_141 = F_21 ( V_100 , V_105 , V_142 ) ;
V_103 -> V_143 = F_21 ( V_100 , V_105 , V_144 ) ;
V_103 -> V_145 = F_21 ( V_100 , V_105 , V_146 ) ;
V_103 -> V_147 = F_21 ( V_100 , V_105 , V_148 ) ;
V_103 -> V_149 = F_21 ( V_100 , V_105 , V_150 ) ;
V_103 -> V_151 = F_21 ( V_100 , V_105 , V_152 ) ;
V_103 -> V_153 = F_21 ( V_100 , V_105 ,
V_154 ) ;
V_103 -> V_155 = F_21 ( V_100 , V_105 ,
V_156 ) ;
V_103 -> V_157 = F_21 ( V_101 , V_106 , V_158 ) ;
V_103 -> V_159 = F_21 ( V_101 , V_106 , V_160 ) ;
V_103 -> V_161 = F_21 ( V_101 , V_106 , V_162 ) ;
V_103 -> V_163 = F_21 ( V_101 , V_106 , V_164 ) ;
V_103 -> V_165 = F_21 ( V_101 , V_106 , V_166 ) ;
V_103 -> V_167 = F_21 ( V_101 , V_106 , V_168 ) ;
switch ( V_103 -> V_153 ) {
case 0 :
break;
case 1 :
V_103 -> V_153 = 64 ;
break;
case 2 :
V_103 -> V_153 = 128 ;
break;
case 3 :
V_103 -> V_153 = 256 ;
break;
}
V_103 -> V_157 ++ ;
V_103 -> V_159 ++ ;
V_103 -> V_161 ++ ;
V_103 -> V_163 ++ ;
V_103 -> V_151 ++ ;
F_7 ( L_17 ) ;
}
static void F_38 ( struct V_1 * V_2 , unsigned int V_169 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( V_169 )
F_39 ( V_2 -> V_27 , & V_5 -> V_72 ,
V_170 , V_171 ) ;
F_40 ( & V_5 -> V_72 ) ;
}
} else {
if ( V_169 )
F_39 ( V_2 -> V_27 , & V_2 -> V_72 ,
V_172 , V_171 ) ;
F_40 ( & V_2 -> V_72 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , unsigned int V_173 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
F_42 ( & V_5 -> V_72 ) ;
if ( V_173 )
F_43 ( & V_5 -> V_72 ) ;
}
} else {
F_42 ( & V_2 -> V_72 ) ;
if ( V_173 )
F_43 ( & V_2 -> V_72 ) ;
}
}
void F_44 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_18 ) ;
V_2 -> V_174 = V_175 ;
V_2 -> V_176 = V_177 ;
V_39 -> V_178 ( V_2 ) ;
F_7 ( L_19 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_20 ) ;
V_2 -> V_179 = V_39 -> V_180 ( V_2 , V_181 ) ;
V_2 -> V_182 = V_183 ;
V_39 -> V_184 ( V_2 ) ;
F_7 ( L_21 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_185 * V_186 = & V_2 -> V_186 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_187 * V_188 ;
unsigned int V_10 , V_189 ;
F_7 ( L_22 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
V_32 = V_5 -> V_7 ;
if ( ! V_32 )
break;
for ( V_189 = 0 ; V_189 < V_32 -> V_33 ; V_189 ++ ) {
V_188 = F_47 ( V_32 , V_189 ) ;
V_186 -> V_190 ( V_2 , V_188 ) ;
}
}
F_7 ( L_23 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_185 * V_186 = & V_2 -> V_186 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_187 * V_188 ;
unsigned int V_10 , V_189 ;
F_7 ( L_24 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
V_32 = V_5 -> V_8 ;
if ( ! V_32 )
break;
for ( V_189 = 0 ; V_189 < V_32 -> V_33 ; V_189 ++ ) {
V_188 = F_47 ( V_32 , V_189 ) ;
V_186 -> V_190 ( V_2 , V_188 ) ;
}
}
F_7 ( L_25 ) ;
}
static void F_49 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_191 * V_192 = V_2 -> V_192 ;
int V_193 = 0 ;
if ( V_192 == NULL )
return;
if ( V_192 -> V_194 ) {
if ( V_2 -> V_195 ) {
if ( V_192 -> V_196 || V_192 -> V_197 ) {
V_2 -> V_198 = 1 ;
V_2 -> V_199 = 1 ;
} else {
V_2 -> V_198 = 0 ;
V_2 -> V_199 = 0 ;
}
}
if ( V_2 -> V_198 != V_2 -> V_200 ) {
V_39 -> V_201 ( V_2 ) ;
V_2 -> V_200 = V_2 -> V_198 ;
}
if ( V_2 -> V_199 != V_2 -> V_202 ) {
V_39 -> V_203 ( V_2 ) ;
V_2 -> V_202 = V_2 -> V_199 ;
}
if ( V_192 -> V_204 != V_2 -> V_205 ) {
V_193 = 1 ;
switch ( V_192 -> V_204 ) {
case V_206 :
V_39 -> V_207 ( V_2 ) ;
break;
case V_208 :
V_39 -> V_209 ( V_2 ) ;
break;
case V_210 :
V_39 -> V_211 ( V_2 ) ;
break;
}
V_2 -> V_205 = V_192 -> V_204 ;
}
if ( V_192 -> V_194 != V_2 -> V_212 ) {
V_193 = 1 ;
V_2 -> V_212 = 1 ;
}
} else if ( V_2 -> V_212 ) {
V_193 = 1 ;
V_2 -> V_212 = 0 ;
V_2 -> V_205 = V_213 ;
}
if ( V_193 )
F_51 ( V_192 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_191 * V_192 = V_2 -> V_192 ;
int V_11 ;
V_2 -> V_212 = - 1 ;
V_2 -> V_205 = V_213 ;
V_2 -> V_200 = V_2 -> V_198 ;
V_2 -> V_202 = V_2 -> V_199 ;
V_11 = F_53 ( V_27 , V_192 , & F_49 ,
V_2 -> V_214 ) ;
if ( V_11 ) {
F_5 ( V_27 , L_26 ) ;
return V_11 ;
}
if ( ! V_192 -> V_215 || ( V_192 -> V_215 -> V_216 == 0 ) ) {
F_5 ( V_27 , L_27 ) ;
V_11 = - V_217 ;
goto V_218;
}
F_7 ( L_28 ,
F_54 ( & V_192 -> V_219 ) , V_192 -> V_194 ) ;
return 0 ;
V_218:
F_55 ( V_192 ) ;
return V_11 ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_192 )
return;
F_55 ( V_2 -> V_192 ) ;
}
int F_57 ( struct V_42 * V_27 , unsigned int V_220 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
unsigned long V_93 ;
F_7 ( L_29 ) ;
if ( ! F_58 ( V_27 ) ||
( V_220 == V_221 && V_2 -> V_222 ) ) {
F_14 ( V_27 , L_30 ) ;
F_7 ( L_31 ) ;
return - V_46 ;
}
F_59 ( V_2 -> V_192 ) ;
F_30 ( & V_2 -> V_30 , V_93 ) ;
if ( V_220 == V_223 )
F_60 ( V_27 ) ;
F_61 ( V_27 ) ;
F_41 ( V_2 , 0 ) ;
V_39 -> V_224 ( V_2 ) ;
V_39 -> V_225 ( V_2 ) ;
V_2 -> V_222 = 1 ;
F_32 ( & V_2 -> V_30 , V_93 ) ;
F_7 ( L_31 ) ;
return 0 ;
}
int F_62 ( struct V_42 * V_27 , unsigned int V_220 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
unsigned long V_93 ;
F_7 ( L_32 ) ;
if ( ! F_58 ( V_27 ) ||
( V_220 == V_221 && ! V_2 -> V_222 ) ) {
F_14 ( V_27 , L_33 ) ;
F_7 ( L_34 ) ;
return - V_46 ;
}
F_30 ( & V_2 -> V_30 , V_93 ) ;
V_2 -> V_222 = 0 ;
F_63 ( V_2 -> V_192 ) ;
V_39 -> V_226 ( V_2 ) ;
V_39 -> V_227 ( V_2 ) ;
if ( V_220 == V_223 )
F_64 ( V_27 ) ;
F_38 ( V_2 , 0 ) ;
F_65 ( V_27 ) ;
F_32 ( & V_2 -> V_30 , V_93 ) ;
F_7 ( L_34 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_42 * V_27 = V_2 -> V_27 ;
F_7 ( L_35 ) ;
F_67 ( V_27 ) ;
V_39 -> V_228 ( V_2 ) ;
F_63 ( V_2 -> V_192 ) ;
V_39 -> V_229 ( V_2 ) ;
V_39 -> V_230 ( V_2 ) ;
F_33 ( V_2 ) ;
F_38 ( V_2 , 1 ) ;
F_65 ( V_27 ) ;
F_7 ( L_36 ) ;
return 0 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_231 * V_232 ;
unsigned int V_10 ;
F_7 ( L_37 ) ;
F_59 ( V_2 -> V_192 ) ;
F_61 ( V_27 ) ;
F_41 ( V_2 , 1 ) ;
F_35 ( V_2 ) ;
V_39 -> V_233 ( V_2 ) ;
V_39 -> V_234 ( V_2 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
continue;
V_232 = F_69 ( V_27 , V_5 -> V_20 ) ;
F_70 ( V_232 ) ;
}
F_7 ( L_38 ) ;
}
static void F_71 ( struct V_1 * V_2 , unsigned int V_235 )
{
struct V_3 * V_5 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
unsigned int V_10 ;
F_7 ( L_39 ) ;
if ( ! F_58 ( V_2 -> V_27 ) )
return;
F_68 ( V_2 ) ;
F_72 ( V_2 -> V_236 ) ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_72 ( V_5 -> V_29 ) ;
}
F_46 ( V_2 ) ;
F_48 ( V_2 ) ;
if ( V_235 )
V_39 -> exit ( V_2 ) ;
F_66 ( V_2 ) ;
F_7 ( L_40 ) ;
}
static void F_73 ( struct V_237 * V_238 )
{
struct V_1 * V_2 = F_29 ( V_238 ,
struct V_1 ,
V_74 ) ;
F_74 () ;
F_71 ( V_2 , 1 ) ;
F_75 () ;
}
static void F_76 ( struct V_237 * V_238 )
{
struct V_1 * V_2 = F_29 ( V_238 ,
struct V_1 ,
V_86 ) ;
struct V_239 V_240 ;
T_2 V_241 ;
unsigned long V_93 ;
if ( V_2 -> V_84 ) {
V_241 = F_77 ( & V_2 -> V_242 ,
V_2 -> V_84 ) ;
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
V_240 . V_243 = F_78 ( V_241 ) ;
F_79 ( V_2 -> V_244 , & V_240 ) ;
}
F_80 ( V_2 -> V_244 ) ;
F_30 ( & V_2 -> V_245 , V_93 ) ;
V_2 -> V_244 = NULL ;
F_32 ( & V_2 -> V_245 , V_93 ) ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_246 * V_246 )
{
if ( F_82 ( V_246 -> V_247 , & V_2 -> V_248 ,
sizeof( V_2 -> V_248 ) ) )
return - V_249 ;
return 0 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_246 * V_246 )
{
struct V_250 V_251 ;
unsigned int V_252 ;
if ( F_84 ( & V_251 , V_246 -> V_247 , sizeof( V_251 ) ) )
return - V_249 ;
if ( V_251 . V_93 )
return - V_46 ;
V_252 = 0 ;
switch ( V_251 . V_253 ) {
case V_254 :
break;
case V_255 :
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
default:
return - V_258 ;
}
switch ( V_251 . V_259 ) {
case V_260 :
break;
case V_261 :
F_85 ( V_252 , V_256 , V_262 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
case V_263 :
F_85 ( V_252 , V_256 , V_264 , 1 ) ;
case V_265 :
F_85 ( V_252 , V_256 , V_266 , 1 ) ;
F_85 ( V_252 , V_256 , V_267 , 1 ) ;
F_85 ( V_252 , V_256 , V_268 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
case V_269 :
F_85 ( V_252 , V_256 , V_264 , 1 ) ;
case V_270 :
F_85 ( V_252 , V_256 , V_266 , 1 ) ;
F_85 ( V_252 , V_256 , V_267 , 1 ) ;
F_85 ( V_252 , V_256 , V_271 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
case V_272 :
F_85 ( V_252 , V_256 , V_264 , 1 ) ;
case V_273 :
F_85 ( V_252 , V_256 , V_266 , 1 ) ;
F_85 ( V_252 , V_256 , V_267 , 1 ) ;
F_85 ( V_252 , V_256 , V_271 , 1 ) ;
F_85 ( V_252 , V_256 , V_274 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
case V_275 :
F_85 ( V_252 , V_256 , V_276 , 1 ) ;
F_85 ( V_252 , V_256 , V_268 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
case V_277 :
F_85 ( V_252 , V_256 , V_276 , 1 ) ;
F_85 ( V_252 , V_256 , V_271 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
case V_278 :
F_85 ( V_252 , V_256 , V_276 , 1 ) ;
F_85 ( V_252 , V_256 , V_274 , 1 ) ;
F_85 ( V_252 , V_256 , V_271 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
case V_279 :
F_85 ( V_252 , V_256 , V_264 , 1 ) ;
F_85 ( V_252 , V_256 , V_280 , 1 ) ;
F_85 ( V_252 , V_256 , V_266 , 1 ) ;
F_85 ( V_252 , V_256 , V_267 , 1 ) ;
F_85 ( V_252 , V_256 , V_268 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
case V_281 :
F_85 ( V_252 , V_256 , V_264 , 1 ) ;
F_85 ( V_252 , V_256 , V_280 , 1 ) ;
F_85 ( V_252 , V_256 , V_266 , 1 ) ;
F_85 ( V_252 , V_256 , V_267 , 1 ) ;
F_85 ( V_252 , V_256 , V_271 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
case V_282 :
F_85 ( V_252 , V_256 , V_264 , 1 ) ;
F_85 ( V_252 , V_256 , V_280 , 1 ) ;
F_85 ( V_252 , V_256 , V_266 , 1 ) ;
F_85 ( V_252 , V_256 , V_267 , 1 ) ;
F_85 ( V_252 , V_256 , V_274 , 1 ) ;
F_85 ( V_252 , V_256 , V_271 , 1 ) ;
F_85 ( V_252 , V_256 , V_257 , 1 ) ;
break;
default:
return - V_258 ;
}
V_2 -> V_39 . V_283 ( V_2 , V_252 ) ;
memcpy ( & V_2 -> V_248 , & V_251 , sizeof( V_251 ) ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_284 * V_285 ,
struct V_286 * V_287 )
{
unsigned long V_93 ;
if ( F_21 ( V_287 -> V_288 , V_289 , V_290 ) ) {
F_30 ( & V_2 -> V_245 , V_93 ) ;
if ( V_2 -> V_244 ) {
F_85 ( V_287 -> V_288 ,
V_289 , V_290 , 0 ) ;
} else {
V_2 -> V_244 = F_87 ( V_285 ) ;
F_88 ( V_285 ) -> V_291 |= V_292 ;
}
F_32 ( & V_2 -> V_245 , V_93 ) ;
}
if ( ! F_21 ( V_287 -> V_288 , V_289 , V_290 ) )
F_89 ( V_285 ) ;
}
static void F_90 ( struct V_284 * V_285 , struct V_286 * V_287 )
{
if ( F_91 ( V_285 ) )
V_287 -> V_293 = F_92 ( V_285 ) ;
}
static int F_93 ( struct V_284 * V_285 , struct V_286 * V_287 )
{
int V_11 ;
if ( ! F_21 ( V_287 -> V_288 , V_289 ,
V_294 ) )
return 0 ;
V_11 = F_94 ( V_285 , 0 ) ;
if ( V_11 )
return V_11 ;
V_287 -> V_295 = F_95 ( V_285 ) + F_96 ( V_285 ) ;
V_287 -> V_296 = F_96 ( V_285 ) ;
V_287 -> V_297 = V_285 -> V_298 - V_287 -> V_295 ;
V_287 -> V_299 = F_88 ( V_285 ) -> V_300 ;
F_7 ( L_41 , V_287 -> V_295 ) ;
F_7 ( L_42 ,
V_287 -> V_296 , V_287 -> V_297 ) ;
F_7 ( L_43 , V_287 -> V_299 ) ;
V_287 -> V_301 = F_88 ( V_285 ) -> V_302 ;
V_287 -> V_303 += ( V_287 -> V_301 - 1 ) * V_287 -> V_295 ;
return 0 ;
}
static int F_97 ( struct V_284 * V_285 )
{
if ( V_285 -> V_304 != V_305 )
return 0 ;
if ( ! F_98 ( V_285 ) )
return 0 ;
F_7 ( L_44 ) ;
return 1 ;
}
static void F_99 ( struct V_1 * V_2 ,
struct V_6 * V_32 , struct V_284 * V_285 ,
struct V_286 * V_287 )
{
struct V_306 * V_307 ;
unsigned int V_308 ;
unsigned int V_298 ;
unsigned int V_10 ;
V_287 -> V_285 = V_285 ;
V_308 = 0 ;
V_287 -> V_33 = 0 ;
V_287 -> V_301 = 1 ;
V_287 -> V_303 = V_285 -> V_298 ;
if ( F_97 ( V_285 ) ) {
if ( F_88 ( V_285 ) -> V_300 != V_32 -> V_36 . V_309 ) {
V_308 = 1 ;
V_287 -> V_33 ++ ;
}
V_287 -> V_33 ++ ;
F_85 ( V_287 -> V_288 , V_289 ,
V_294 , 1 ) ;
F_85 ( V_287 -> V_288 , V_289 ,
V_310 , 1 ) ;
} else if ( V_285 -> V_304 == V_305 )
F_85 ( V_287 -> V_288 , V_289 ,
V_310 , 1 ) ;
if ( F_91 ( V_285 ) ) {
if ( F_92 ( V_285 ) != V_32 -> V_36 . V_311 )
if ( ! V_308 ) {
V_308 = 1 ;
V_287 -> V_33 ++ ;
}
F_85 ( V_287 -> V_288 , V_289 ,
V_312 , 1 ) ;
}
if ( ( F_88 ( V_285 ) -> V_291 & V_313 ) &&
( V_2 -> V_248 . V_253 == V_255 ) )
F_85 ( V_287 -> V_288 , V_289 ,
V_290 , 1 ) ;
for ( V_298 = F_100 ( V_285 ) ; V_298 ; ) {
V_287 -> V_33 ++ ;
V_298 -= F_101 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
for ( V_10 = 0 ; V_10 < F_88 ( V_285 ) -> V_314 ; V_10 ++ ) {
V_307 = & F_88 ( V_285 ) -> V_315 [ V_10 ] ;
for ( V_298 = F_102 ( V_307 ) ; V_298 ; ) {
V_287 -> V_33 ++ ;
V_298 -= F_101 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
}
}
static int F_103 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_185 * V_186 = & V_2 -> V_186 ;
struct V_3 * V_5 = NULL ;
unsigned int V_10 = 0 ;
int V_11 ;
F_7 ( L_45 ) ;
V_11 = F_52 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_104 ( V_2 -> V_316 ) ;
if ( V_11 ) {
F_14 ( V_27 , L_46 ) ;
goto V_317;
}
V_11 = F_104 ( V_2 -> V_318 ) ;
if ( V_11 ) {
F_14 ( V_27 , L_47 ) ;
goto V_319;
}
V_11 = F_13 ( V_27 , V_27 -> V_43 ) ;
if ( V_11 < 0 )
goto V_320;
V_2 -> V_44 = V_11 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
goto V_320;
V_11 = V_186 -> V_321 ( V_2 ) ;
if ( V_11 )
goto V_322;
F_105 ( & V_2 -> V_74 , F_73 ) ;
F_105 ( & V_2 -> V_86 , F_76 ) ;
V_11 = F_106 ( V_2 -> V_219 , V_2 -> V_236 , F_18 , 0 ,
V_27 -> V_19 , V_2 ) ;
if ( V_11 ) {
F_14 ( V_27 , L_48 ,
V_2 -> V_236 ) ;
goto V_323;
}
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_324 ,
sizeof( V_5 -> V_324 ) - 1 ,
L_49 , F_107 ( V_27 ) ,
V_5 -> V_20 ) ;
V_11 = F_106 ( V_2 -> V_219 , V_5 -> V_29 ,
F_26 , 0 ,
V_5 -> V_324 , V_5 ) ;
if ( V_11 ) {
F_14 ( V_27 ,
L_48 ,
V_5 -> V_29 ) ;
goto V_28;
}
}
}
V_11 = F_66 ( V_2 ) ;
if ( V_11 )
goto V_325;
F_7 ( L_50 ) ;
return 0 ;
V_325:
V_39 -> exit ( V_2 ) ;
V_28:
if ( V_2 -> V_25 ) {
for ( V_10 -- , V_5 -- ; V_10 < V_2 -> V_31 ; V_10 -- , V_5 -- )
F_108 ( V_2 -> V_219 , V_5 -> V_29 , V_5 ) ;
}
F_108 ( V_2 -> V_219 , V_2 -> V_236 , V_2 ) ;
V_323:
V_186 -> V_326 ( V_2 ) ;
V_322:
F_9 ( V_2 ) ;
V_320:
F_109 ( V_2 -> V_318 ) ;
V_319:
F_109 ( V_2 -> V_316 ) ;
V_317:
F_56 ( V_2 ) ;
return V_11 ;
}
static int F_110 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_185 * V_186 = & V_2 -> V_186 ;
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_51 ) ;
F_68 ( V_2 ) ;
V_39 -> exit ( V_2 ) ;
V_186 -> V_326 ( V_2 ) ;
F_108 ( V_2 -> V_219 , V_2 -> V_236 , V_2 ) ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_108 ( V_2 -> V_219 , V_5 -> V_29 , V_5 ) ;
}
F_9 ( V_2 ) ;
F_109 ( V_2 -> V_318 ) ;
F_109 ( V_2 -> V_316 ) ;
F_56 ( V_2 ) ;
F_7 ( L_52 ) ;
return 0 ;
}
static int F_111 ( struct V_284 * V_285 , struct V_42 * V_27 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_185 * V_186 = & V_2 -> V_186 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_286 * V_287 ;
struct V_231 * V_232 ;
unsigned long V_93 ;
int V_11 ;
F_7 ( L_53 , V_285 -> V_298 ) ;
V_5 = V_2 -> V_5 + V_285 -> V_327 ;
V_232 = F_69 ( V_27 , V_5 -> V_20 ) ;
V_32 = V_5 -> V_7 ;
V_287 = & V_32 -> V_328 ;
V_11 = V_329 ;
F_30 ( & V_32 -> V_30 , V_93 ) ;
if ( V_285 -> V_298 == 0 ) {
F_5 ( V_27 , L_54 ) ;
F_80 ( V_285 ) ;
goto V_330;
}
memset ( V_287 , 0 , sizeof( * V_287 ) ) ;
F_99 ( V_2 , V_32 , V_285 , V_287 ) ;
V_11 = F_11 ( V_5 , V_32 , V_287 -> V_33 ) ;
if ( V_11 )
goto V_330;
V_11 = F_93 ( V_285 , V_287 ) ;
if ( V_11 ) {
F_5 ( V_27 , L_55 ) ;
F_80 ( V_285 ) ;
goto V_330;
}
F_90 ( V_285 , V_287 ) ;
if ( ! V_186 -> V_331 ( V_5 , V_285 ) ) {
F_80 ( V_285 ) ;
goto V_330;
}
F_86 ( V_2 , V_285 , V_287 ) ;
F_112 ( V_232 , V_287 -> V_303 ) ;
V_39 -> V_332 ( V_5 ) ;
#ifdef F_113
F_114 ( V_27 , V_285 , true ) ;
#endif
F_11 ( V_5 , V_32 , V_333 ) ;
V_11 = V_329 ;
V_330:
F_32 ( & V_32 -> V_30 , V_93 ) ;
F_7 ( L_56 ) ;
return V_11 ;
}
static void F_67 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
unsigned int V_334 , V_335 ;
F_7 ( L_57 ) ;
V_334 = ( ( V_27 -> V_93 & V_336 ) != 0 ) ;
V_335 = ( ( V_27 -> V_93 & V_337 ) != 0 ) ;
V_39 -> V_338 ( V_2 , V_334 ) ;
V_39 -> V_339 ( V_2 , V_335 ) ;
V_39 -> V_340 ( V_2 ) ;
F_7 ( L_58 ) ;
}
static int F_115 ( struct V_42 * V_27 , void * V_341 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_342 * V_343 = V_341 ;
F_7 ( L_59 ) ;
if ( ! F_116 ( V_343 -> V_344 ) )
return - V_345 ;
memcpy ( V_27 -> V_346 , V_343 -> V_344 , V_27 -> V_347 ) ;
V_39 -> V_348 ( V_2 , V_27 -> V_346 ) ;
F_7 ( L_60 ) ;
return 0 ;
}
static int F_117 ( struct V_42 * V_27 , struct V_246 * V_246 , int V_349 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
int V_11 ;
switch ( V_349 ) {
case V_350 :
V_11 = F_81 ( V_2 , V_246 ) ;
break;
case V_351 :
V_11 = F_83 ( V_2 , V_246 ) ;
break;
default:
V_11 = - V_352 ;
}
return V_11 ;
}
static int F_118 ( struct V_42 * V_27 , int V_43 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
int V_11 ;
F_7 ( L_61 ) ;
V_11 = F_13 ( V_27 , V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_44 = V_11 ;
V_27 -> V_43 = V_43 ;
F_71 ( V_2 , 0 ) ;
F_7 ( L_62 ) ;
return 0 ;
}
static struct V_353 * F_119 ( struct V_42 * V_27 ,
struct V_353 * V_354 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_355 * V_356 = & V_2 -> V_357 ;
F_7 ( L_63 , V_358 ) ;
V_2 -> V_39 . V_359 ( V_2 ) ;
V_354 -> V_360 = V_356 -> V_361 ;
V_354 -> V_362 = V_356 -> V_363 ;
V_354 -> V_364 = V_356 -> V_361 -
V_356 -> V_365 -
V_356 -> V_366 -
V_356 -> V_367 ;
V_354 -> V_368 = V_356 -> V_366 ;
V_354 -> V_369 = V_356 -> V_370 ;
V_354 -> V_371 = V_356 -> V_372 ;
V_354 -> V_373 = V_356 -> V_374 ;
V_354 -> V_301 = V_356 -> V_375 ;
V_354 -> V_303 = V_356 -> V_376 ;
V_354 -> V_377 = V_356 -> V_375 - V_356 -> V_378 ;
V_354 -> V_379 = V_27 -> V_380 . V_379 ;
F_7 ( L_64 , V_358 ) ;
return V_354 ;
}
static int F_120 ( struct V_42 * V_27 , T_3 V_381 ,
T_4 V_382 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_63 , V_358 ) ;
F_121 ( V_382 , V_2 -> V_383 ) ;
V_39 -> V_384 ( V_2 ) ;
F_7 ( L_64 , V_358 ) ;
return 0 ;
}
static int F_122 ( struct V_42 * V_27 , T_3 V_381 ,
T_4 V_382 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_63 , V_358 ) ;
F_123 ( V_382 , V_2 -> V_383 ) ;
V_39 -> V_384 ( V_2 ) ;
F_7 ( L_64 , V_358 ) ;
return 0 ;
}
static void F_124 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_65 ) ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_26 ( V_5 -> V_29 , V_5 ) ;
} else {
F_31 ( V_2 -> V_236 ) ;
F_18 ( V_2 -> V_236 , V_2 ) ;
F_125 ( V_2 -> V_236 ) ;
}
F_7 ( L_66 ) ;
}
static int F_126 ( struct V_42 * V_27 , T_5 V_385 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
unsigned int V_386 , V_387 ;
T_5 V_10 ;
if ( V_385 && ( V_385 != V_2 -> V_103 . V_151 ) )
return - V_46 ;
if ( V_385 ) {
F_127 ( V_27 , V_385 ) ;
for ( V_10 = 0 , V_387 = 0 , V_386 = 0 ; V_10 < V_385 ; V_10 ++ ) {
while ( ( V_387 < V_2 -> V_388 ) &&
( V_2 -> V_389 [ V_387 ] == V_10 ) )
V_387 ++ ;
F_7 ( L_67 , V_10 , V_386 , V_387 - 1 ) ;
F_128 ( V_27 , V_10 , V_387 - V_386 , V_386 ) ;
V_386 = V_387 ;
}
} else {
F_129 ( V_27 ) ;
}
return 0 ;
}
static int F_130 ( struct V_42 * V_27 ,
T_6 V_390 )
{
struct V_1 * V_2 = F_50 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
T_6 V_391 , V_392 , V_393 , V_394 ;
int V_11 = 0 ;
V_391 = V_2 -> V_395 & V_396 ;
V_392 = V_2 -> V_395 & V_397 ;
V_393 = V_2 -> V_395 & V_398 ;
V_394 = V_2 -> V_395 & V_399 ;
if ( ( V_390 & V_396 ) && ! V_391 )
V_11 = V_39 -> V_400 ( V_2 ) ;
else if ( ! ( V_390 & V_396 ) && V_391 )
V_11 = V_39 -> V_401 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_390 & V_397 ) && ! V_392 )
V_39 -> V_402 ( V_2 ) ;
else if ( ! ( V_390 & V_397 ) && V_392 )
V_39 -> V_403 ( V_2 ) ;
if ( ( V_390 & V_398 ) && ! V_393 )
V_39 -> V_404 ( V_2 ) ;
else if ( ! ( V_390 & V_398 ) && V_393 )
V_39 -> V_405 ( V_2 ) ;
if ( ( V_390 & V_399 ) && ! V_394 )
V_39 -> V_406 ( V_2 ) ;
else if ( ! ( V_390 & V_399 ) && V_394 )
V_39 -> V_407 ( V_2 ) ;
V_2 -> V_395 = V_390 ;
F_7 ( L_68 ) ;
return 0 ;
}
struct V_408 * F_131 ( void )
{
return (struct V_408 * ) & V_409 ;
}
static void F_132 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_185 * V_186 = & V_2 -> V_186 ;
struct V_6 * V_32 = V_5 -> V_8 ;
struct V_187 * V_188 ;
V_186 -> V_410 ( V_5 ) ;
V_188 = F_47 ( V_32 , V_32 -> V_411 . V_412 - 1 ) ;
F_25 ( V_5 , V_413 ,
F_133 ( V_188 -> V_414 ) ) ;
}
static struct V_284 * F_134 ( struct V_1 * V_2 ,
struct V_187 * V_188 ,
unsigned int * V_298 )
{
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_284 * V_285 ;
T_5 * V_287 ;
unsigned int V_415 ;
V_285 = F_135 ( V_27 , V_188 -> V_411 . V_416 . V_417 ) ;
if ( ! V_285 )
return NULL ;
V_287 = F_136 ( V_188 -> V_411 . V_416 . V_418 . V_419 ) +
V_188 -> V_411 . V_416 . V_418 . V_420 ;
V_415 = ( V_188 -> V_411 . V_421 ) ? V_188 -> V_411 . V_421 : * V_298 ;
V_415 = F_137 ( V_188 -> V_411 . V_416 . V_417 , V_415 ) ;
F_138 ( V_285 , V_287 , V_415 ) ;
F_139 ( V_285 , V_415 ) ;
* V_298 -= V_415 ;
return V_285 ;
}
static int F_140 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_185 * V_186 = & V_2 -> V_186 ;
struct V_6 * V_32 = V_5 -> V_7 ;
struct V_187 * V_188 ;
struct V_422 * V_423 ;
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_231 * V_232 ;
unsigned long V_93 ;
int V_424 = 0 ;
unsigned int V_301 = 0 , V_303 = 0 ;
F_7 ( L_69 ) ;
if ( ! V_32 )
return 0 ;
V_232 = F_69 ( V_27 , V_5 -> V_20 ) ;
F_30 ( & V_32 -> V_30 , V_93 ) ;
while ( ( V_424 < V_425 ) &&
( V_32 -> V_35 != V_32 -> V_34 ) ) {
V_188 = F_47 ( V_32 , V_32 -> V_35 ) ;
V_423 = V_188 -> V_423 ;
if ( ! V_39 -> V_426 ( V_423 ) )
break;
F_141 () ;
#ifdef F_142
F_143 ( V_32 , V_32 -> V_35 , 1 , 0 ) ;
#endif
if ( V_39 -> V_427 ( V_423 ) ) {
V_301 += V_188 -> V_36 . V_428 ;
V_303 += V_188 -> V_36 . V_429 ;
}
V_186 -> V_190 ( V_2 , V_188 ) ;
V_39 -> V_430 ( V_188 ) ;
V_424 ++ ;
V_32 -> V_35 ++ ;
}
if ( ! V_424 )
goto V_431;
F_144 ( V_232 , V_301 , V_303 ) ;
if ( ( V_32 -> V_36 . V_37 == 1 ) &&
( F_10 ( V_32 ) > V_432 ) ) {
V_32 -> V_36 . V_37 = 0 ;
F_145 ( V_232 ) ;
}
F_7 ( L_70 , V_424 ) ;
V_431:
F_32 ( & V_32 -> V_30 , V_93 ) ;
return V_424 ;
}
static int F_146 ( struct V_3 * V_5 , int V_433 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_6 * V_32 = V_5 -> V_8 ;
struct V_187 * V_188 ;
struct V_286 * V_287 ;
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_92 * V_72 ;
struct V_284 * V_285 ;
struct V_239 * V_240 ;
unsigned int V_434 , error , V_435 , V_436 ;
unsigned int V_298 , V_437 , V_438 ;
unsigned int V_439 = 0 ;
int V_440 = 0 ;
F_7 ( L_71 , V_433 ) ;
if ( ! V_32 )
return 0 ;
V_72 = ( V_2 -> V_25 ) ? & V_5 -> V_72 : & V_2 -> V_72 ;
V_188 = F_47 ( V_32 , V_32 -> V_34 ) ;
V_287 = & V_32 -> V_328 ;
while ( V_440 < V_433 ) {
F_7 ( L_72 , V_32 -> V_34 ) ;
if ( ! V_439 && V_188 -> V_441 ) {
V_434 = V_188 -> V_442 . V_434 ;
V_435 = V_188 -> V_442 . V_435 ;
V_285 = V_188 -> V_442 . V_285 ;
error = V_188 -> V_442 . error ;
V_298 = V_188 -> V_442 . V_298 ;
} else {
memset ( V_287 , 0 , sizeof( * V_287 ) ) ;
V_434 = 0 ;
V_435 = 0 ;
V_285 = NULL ;
error = 0 ;
V_298 = 0 ;
}
V_443:
V_188 = F_47 ( V_32 , V_32 -> V_34 ) ;
if ( V_32 -> V_35 > ( V_444 >> 3 ) )
F_132 ( V_5 ) ;
if ( V_39 -> V_445 ( V_5 ) )
break;
V_439 ++ ;
V_32 -> V_34 ++ ;
V_32 -> V_35 ++ ;
V_434 = F_21 ( V_287 -> V_288 ,
V_446 ,
V_447 ) ;
V_435 = F_21 ( V_287 -> V_288 ,
V_446 ,
V_448 ) ;
V_436 = F_21 ( V_287 -> V_288 ,
V_446 ,
V_449 ) ;
if ( ( V_434 || V_435 ) && error )
goto V_443;
if ( error || V_287 -> V_450 ) {
if ( V_287 -> V_450 )
F_7 ( L_73 ) ;
F_147 ( V_285 ) ;
goto V_451;
}
if ( ! V_436 ) {
V_437 = V_188 -> V_411 . V_298 - V_298 ;
V_298 += V_437 ;
if ( ! V_285 ) {
F_148 ( V_2 -> V_219 ,
V_188 -> V_411 . V_416 . V_452 ,
V_188 -> V_411 . V_416 . V_417 ,
V_453 ) ;
V_285 = F_134 ( V_2 , V_188 , & V_437 ) ;
if ( ! V_285 ) {
error = 1 ;
goto V_454;
}
}
if ( V_437 ) {
F_148 ( V_2 -> V_219 ,
V_188 -> V_411 . V_455 . V_452 ,
V_188 -> V_411 . V_455 . V_417 ,
V_453 ) ;
F_149 ( V_285 , F_88 ( V_285 ) -> V_314 ,
V_188 -> V_411 . V_455 . V_418 . V_419 ,
V_188 -> V_411 . V_455 . V_418 . V_420 ,
V_437 , V_188 -> V_411 . V_455 . V_417 ) ;
V_188 -> V_411 . V_455 . V_418 . V_419 = NULL ;
}
}
V_454:
if ( V_434 || V_435 )
goto V_443;
if ( ! V_285 )
goto V_451;
V_438 = V_27 -> V_43 + V_47 ;
if ( ! ( V_27 -> V_390 & V_398 ) &&
( V_285 -> V_456 == F_150 ( V_457 ) ) )
V_438 += V_49 ;
if ( V_285 -> V_298 > V_438 ) {
F_7 ( L_74 ) ;
F_147 ( V_285 ) ;
goto V_451;
}
#ifdef F_151
F_114 ( V_27 , V_285 , false ) ;
#endif
F_152 ( V_285 ) ;
if ( F_21 ( V_287 -> V_288 ,
V_446 , V_458 ) )
V_285 -> V_304 = V_459 ;
if ( F_21 ( V_287 -> V_288 ,
V_446 , V_312 ) )
F_153 ( V_285 , F_150 ( V_457 ) ,
V_287 -> V_293 ) ;
if ( F_21 ( V_287 -> V_288 ,
V_446 , V_460 ) ) {
T_2 V_241 ;
V_241 = F_77 ( & V_2 -> V_242 ,
V_287 -> V_461 ) ;
V_240 = F_154 ( V_285 ) ;
V_240 -> V_243 = F_78 ( V_241 ) ;
}
if ( F_21 ( V_287 -> V_288 ,
V_446 , V_462 ) )
F_155 ( V_285 , V_287 -> V_463 ,
V_287 -> V_464 ) ;
V_285 -> V_219 = V_27 ;
V_285 -> V_456 = F_156 ( V_285 , V_27 ) ;
F_157 ( V_285 , V_5 -> V_20 ) ;
F_158 ( V_285 , V_72 ) ;
V_27 -> V_465 = V_466 ;
F_159 ( V_72 , V_285 ) ;
V_451:
V_440 ++ ;
}
if ( V_439 && ( V_434 || V_435 ) ) {
V_188 = F_47 ( V_32 , V_32 -> V_34 ) ;
V_188 -> V_441 = 1 ;
V_188 -> V_442 . V_434 = V_434 ;
V_188 -> V_442 . V_435 = V_435 ;
V_188 -> V_442 . V_285 = V_285 ;
V_188 -> V_442 . V_298 = V_298 ;
V_188 -> V_442 . error = error ;
}
F_7 ( L_75 , V_440 ) ;
return V_440 ;
}
static int V_170 ( struct V_92 * V_72 , int V_433 )
{
struct V_3 * V_5 = F_29 ( V_72 , struct V_3 ,
V_72 ) ;
int V_424 = 0 ;
F_7 ( L_76 , V_433 ) ;
F_140 ( V_5 ) ;
V_424 = F_146 ( V_5 , V_433 ) ;
if ( V_424 < V_433 ) {
F_160 ( V_72 ) ;
F_125 ( V_5 -> V_29 ) ;
}
F_7 ( L_77 , V_424 ) ;
return V_424 ;
}
static int V_172 ( struct V_92 * V_72 , int V_433 )
{
struct V_1 * V_2 = F_29 ( V_72 , struct V_1 ,
V_72 ) ;
struct V_3 * V_5 ;
int V_467 ;
int V_424 , V_468 ;
unsigned int V_10 ;
F_7 ( L_78 , V_433 ) ;
V_424 = 0 ;
V_467 = V_433 / V_2 -> V_17 ;
do {
V_468 = V_424 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
F_140 ( V_5 ) ;
if ( V_467 > ( V_433 - V_424 ) )
V_467 = V_433 - V_424 ;
V_424 += F_146 ( V_5 , V_467 ) ;
}
} while ( ( V_424 < V_433 ) && ( V_424 != V_468 ) );
if ( V_424 < V_433 ) {
F_160 ( V_72 ) ;
F_16 ( V_2 ) ;
}
F_7 ( L_79 , V_424 ) ;
return V_424 ;
}
void F_143 ( struct V_6 * V_32 , unsigned int V_469 ,
unsigned int V_9 , unsigned int V_470 )
{
struct V_187 * V_188 ;
struct V_422 * V_423 ;
while ( V_9 -- ) {
V_188 = F_47 ( V_32 , V_469 ) ;
V_423 = V_188 -> V_423 ;
F_161 ( L_80 , V_469 ,
( V_470 == 1 ) ? L_81 : L_82 ,
F_162 ( V_423 -> V_471 ) , F_162 ( V_423 -> V_472 ) ,
F_162 ( V_423 -> V_473 ) , F_162 ( V_423 -> V_474 ) ) ;
V_469 ++ ;
}
}
void F_163 ( struct V_6 * V_32 , struct V_422 * V_475 ,
unsigned int V_469 )
{
F_161 ( L_83 , V_469 ,
F_162 ( V_475 -> V_471 ) , F_162 ( V_475 -> V_472 ) ,
F_162 ( V_475 -> V_473 ) , F_162 ( V_475 -> V_474 ) ) ;
}
void F_114 ( struct V_42 * V_27 , struct V_284 * V_285 , bool V_476 )
{
struct V_477 * V_478 = (struct V_477 * ) V_285 -> V_62 ;
unsigned char * V_455 = V_285 -> V_62 ;
unsigned char V_479 [ 128 ] ;
unsigned int V_10 , V_189 ;
F_14 ( V_27 , L_84 ) ;
F_14 ( V_27 , L_85 ,
( V_476 ? L_86 : L_87 ) , V_285 -> V_298 ) ;
F_14 ( V_27 , L_88 , V_478 -> V_480 ) ;
F_14 ( V_27 , L_89 , V_478 -> V_481 ) ;
F_14 ( V_27 , L_90 , F_164 ( V_478 -> V_482 ) ) ;
for ( V_10 = 0 , V_189 = 0 ; V_10 < V_285 -> V_298 ; ) {
V_189 += snprintf ( V_479 + V_189 , sizeof( V_479 ) - V_189 , L_91 ,
V_455 [ V_10 ++ ] ) ;
if ( ( V_10 % 32 ) == 0 ) {
F_14 ( V_27 , L_92 , V_10 - 32 , V_479 ) ;
V_189 = 0 ;
} else if ( ( V_10 % 16 ) == 0 ) {
V_479 [ V_189 ++ ] = ' ' ;
V_479 [ V_189 ++ ] = ' ' ;
} else if ( ( V_10 % 4 ) == 0 ) {
V_479 [ V_189 ++ ] = ' ' ;
}
}
if ( V_10 % 32 )
F_14 ( V_27 , L_92 , V_10 - ( V_10 % 32 ) , V_479 ) ;
F_14 ( V_27 , L_84 ) ;
}
