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
static inline unsigned int F_11 ( struct V_6 * V_32 )
{
return ( V_32 -> V_34 - V_32 -> V_35 ) ;
}
static int F_12 ( struct V_3 * V_5 ,
struct V_6 * V_32 , unsigned int V_9 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
if ( V_9 > F_10 ( V_32 ) ) {
F_7 ( L_4 ) ;
F_13 ( V_2 -> V_27 , V_5 -> V_20 ) ;
V_32 -> V_36 . V_37 = 1 ;
if ( V_32 -> V_36 . V_38 )
V_2 -> V_39 . V_40 ( V_5 , V_32 ) ;
return V_41 ;
}
return 0 ;
}
static int F_14 ( struct V_42 * V_27 , unsigned int V_43 )
{
unsigned int V_44 ;
if ( V_43 > V_45 ) {
F_15 ( V_27 , L_5 ) ;
return - V_46 ;
}
V_44 = V_43 + V_47 + V_48 + V_49 ;
V_44 = F_16 ( V_44 , V_50 , V_51 ) ;
V_44 = ( V_44 + V_52 - 1 ) &
~ ( V_52 - 1 ) ;
return V_44 ;
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
V_39 -> V_59 ( V_5 , V_55 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
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
static T_1 F_19 ( int V_61 , void * V_62 )
{
struct V_1 * V_2 = V_62 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
unsigned int V_63 , V_64 ;
unsigned int V_65 , V_66 ;
unsigned int V_10 ;
V_63 = F_20 ( V_2 , V_67 ) ;
if ( ! V_63 )
goto V_68;
F_7 ( L_6 , V_63 ) ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ ) {
if ( ! ( V_63 & ( 1 << V_10 ) ) )
continue;
V_5 = V_2 -> V_5 + V_10 ;
V_64 = F_21 ( V_5 , V_69 ) ;
F_7 ( L_7 , V_10 , V_64 ) ;
if ( ! V_2 -> V_25 &&
( F_22 ( V_64 , V_69 , V_70 ) ||
F_22 ( V_64 , V_69 , V_71 ) ) ) {
if ( F_23 ( & V_2 -> V_72 ) ) {
F_18 ( V_2 ) ;
F_24 ( & V_2 -> V_72 ) ;
}
}
if ( F_22 ( V_64 , V_69 , V_73 ) )
F_25 ( & V_2 -> V_74 ) ;
F_26 ( V_5 , V_69 , V_64 ) ;
}
if ( F_22 ( V_63 , V_67 , V_75 ) ) {
V_65 = F_20 ( V_2 , V_76 ) ;
if ( F_22 ( V_65 , V_76 , V_77 ) )
V_39 -> V_78 ( V_2 ) ;
if ( F_22 ( V_65 , V_76 , V_79 ) )
V_39 -> V_80 ( V_2 ) ;
if ( F_22 ( V_65 , V_76 , V_81 ) ) {
V_66 = F_20 ( V_2 , V_82 ) ;
if ( F_22 ( V_66 , V_82 , V_83 ) ) {
V_2 -> V_84 =
V_39 -> V_85 ( V_2 ) ;
F_25 ( & V_2 -> V_86 ) ;
}
}
}
F_7 ( L_6 , F_20 ( V_2 , V_67 ) ) ;
V_68:
return V_87 ;
}
static T_1 F_27 ( int V_61 , void * V_62 )
{
struct V_3 * V_5 = V_62 ;
if ( F_23 ( & V_5 -> V_72 ) ) {
F_28 ( V_5 -> V_29 ) ;
F_24 ( & V_5 -> V_72 ) ;
}
return V_87 ;
}
static enum V_88 F_29 ( struct V_89 * V_90 )
{
struct V_3 * V_5 = F_30 ( V_90 ,
struct V_3 ,
V_91 ) ;
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_92 * V_72 ;
F_7 ( L_8 ) ;
V_72 = ( V_2 -> V_25 ) ? & V_5 -> V_72 : & V_2 -> V_72 ;
if ( F_23 ( V_72 ) ) {
if ( V_2 -> V_25 )
F_31 ( V_5 -> V_29 ) ;
else
F_18 ( V_2 ) ;
F_24 ( V_72 ) ;
}
V_5 -> V_93 = 0 ;
F_7 ( L_9 ) ;
return V_94 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_10 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_7 ( L_11 , V_5 -> V_19 ) ;
F_33 ( & V_5 -> V_91 , V_95 ,
V_96 ) ;
V_5 -> V_91 . V_97 = F_29 ;
}
F_7 ( L_12 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_13 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
break;
F_7 ( L_14 , V_5 -> V_19 ) ;
V_5 -> V_93 = 0 ;
F_35 ( & V_5 -> V_91 ) ;
}
F_7 ( L_15 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
unsigned int V_98 , V_99 , V_100 ;
struct V_101 * V_102 = & V_2 -> V_102 ;
F_7 ( L_16 ) ;
V_98 = F_20 ( V_2 , V_103 ) ;
V_99 = F_20 ( V_2 , V_104 ) ;
V_100 = F_20 ( V_2 , V_105 ) ;
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
V_102 -> V_106 = F_20 ( V_2 , V_107 ) ;
V_102 -> V_108 = F_22 ( V_98 , V_103 , V_109 ) ;
V_102 -> V_110 = F_22 ( V_98 , V_103 , V_111 ) ;
V_102 -> V_112 = F_22 ( V_98 , V_103 , V_113 ) ;
V_102 -> V_114 = F_22 ( V_98 , V_103 , V_115 ) ;
V_102 -> V_116 = F_22 ( V_98 , V_103 , V_117 ) ;
V_102 -> V_118 = F_22 ( V_98 , V_103 , V_119 ) ;
V_102 -> V_120 = F_22 ( V_98 , V_103 , V_121 ) ;
V_102 -> V_122 = F_22 ( V_98 , V_103 , V_123 ) ;
V_102 -> V_124 = F_22 ( V_98 , V_103 , V_125 ) ;
V_102 -> V_126 = F_22 ( V_98 , V_103 , V_127 ) ;
V_102 -> V_128 = F_22 ( V_98 , V_103 , V_129 ) ;
V_102 -> V_130 = F_22 ( V_98 , V_103 ,
V_131 ) ;
V_102 -> V_132 = F_22 ( V_98 , V_103 , V_133 ) ;
V_102 -> V_134 = F_22 ( V_98 , V_103 , V_135 ) ;
V_102 -> V_136 = F_22 ( V_99 , V_104 ,
V_137 ) ;
V_102 -> V_138 = F_22 ( V_99 , V_104 ,
V_139 ) ;
V_102 -> V_140 = F_22 ( V_99 , V_104 , V_141 ) ;
V_102 -> V_142 = F_22 ( V_99 , V_104 , V_143 ) ;
V_102 -> V_144 = F_22 ( V_99 , V_104 , V_145 ) ;
V_102 -> V_146 = F_22 ( V_99 , V_104 , V_147 ) ;
V_102 -> V_148 = F_22 ( V_99 , V_104 , V_149 ) ;
V_102 -> V_150 = F_22 ( V_99 , V_104 , V_151 ) ;
V_102 -> V_152 = F_22 ( V_99 , V_104 ,
V_153 ) ;
V_102 -> V_154 = F_22 ( V_99 , V_104 ,
V_155 ) ;
V_102 -> V_156 = F_22 ( V_100 , V_105 , V_157 ) ;
V_102 -> V_158 = F_22 ( V_100 , V_105 , V_159 ) ;
V_102 -> V_160 = F_22 ( V_100 , V_105 , V_161 ) ;
V_102 -> V_162 = F_22 ( V_100 , V_105 , V_163 ) ;
V_102 -> V_164 = F_22 ( V_100 , V_105 , V_165 ) ;
V_102 -> V_166 = F_22 ( V_100 , V_105 , V_167 ) ;
switch ( V_102 -> V_152 ) {
case 0 :
break;
case 1 :
V_102 -> V_152 = 64 ;
break;
case 2 :
V_102 -> V_152 = 128 ;
break;
case 3 :
V_102 -> V_152 = 256 ;
break;
}
V_102 -> V_156 ++ ;
V_102 -> V_158 ++ ;
V_102 -> V_160 ++ ;
V_102 -> V_162 ++ ;
V_102 -> V_150 ++ ;
F_7 ( L_17 ) ;
}
static void F_37 ( struct V_1 * V_2 , unsigned int V_168 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( V_168 )
F_38 ( V_2 -> V_27 , & V_5 -> V_72 ,
V_169 , V_170 ) ;
F_39 ( & V_5 -> V_72 ) ;
}
} else {
if ( V_168 )
F_38 ( V_2 -> V_27 , & V_2 -> V_72 ,
V_171 , V_170 ) ;
F_39 ( & V_2 -> V_72 ) ;
}
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_172 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
F_41 ( & V_5 -> V_72 ) ;
if ( V_172 )
F_42 ( & V_5 -> V_72 ) ;
}
} else {
F_41 ( & V_2 -> V_72 ) ;
if ( V_172 )
F_42 ( & V_2 -> V_72 ) ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
struct V_42 * V_27 = V_2 -> V_27 ;
unsigned int V_10 ;
int V_11 ;
V_11 = F_44 ( V_2 -> V_173 , V_2 -> V_174 , F_19 , 0 ,
V_27 -> V_19 , V_2 ) ;
if ( V_11 ) {
F_15 ( V_27 , L_18 ,
V_2 -> V_174 ) ;
return V_11 ;
}
if ( ! V_2 -> V_25 )
return 0 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
snprintf ( V_5 -> V_175 ,
sizeof( V_5 -> V_175 ) - 1 ,
L_19 , F_45 ( V_27 ) ,
V_5 -> V_20 ) ;
V_11 = F_44 ( V_2 -> V_173 , V_5 -> V_29 ,
F_27 , 0 ,
V_5 -> V_175 , V_5 ) ;
if ( V_11 ) {
F_15 ( V_27 , L_18 ,
V_5 -> V_29 ) ;
goto V_28;
}
}
return 0 ;
V_28:
for ( V_10 -- , V_5 -- ; V_10 < V_2 -> V_31 ; V_10 -- , V_5 -- )
F_46 ( V_2 -> V_173 , V_5 -> V_29 , V_5 ) ;
F_46 ( V_2 -> V_173 , V_2 -> V_174 , V_2 ) ;
return V_11 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_5 ;
unsigned int V_10 ;
F_46 ( V_2 -> V_173 , V_2 -> V_174 , V_2 ) ;
if ( ! V_2 -> V_25 )
return;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_46 ( V_2 -> V_173 , V_5 -> V_29 , V_5 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_20 ) ;
V_2 -> V_176 = V_177 ;
V_2 -> V_178 = V_179 ;
V_39 -> V_180 ( V_2 ) ;
F_7 ( L_21 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_22 ) ;
V_2 -> V_181 = V_39 -> V_182 ( V_2 , V_183 ) ;
V_2 -> V_184 = V_185 ;
V_39 -> V_186 ( V_2 ) ;
F_7 ( L_23 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_189 * V_190 ;
unsigned int V_10 , V_191 ;
F_7 ( L_24 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
V_32 = V_5 -> V_7 ;
if ( ! V_32 )
break;
for ( V_191 = 0 ; V_191 < V_32 -> V_33 ; V_191 ++ ) {
V_190 = F_51 ( V_32 , V_191 ) ;
V_188 -> V_192 ( V_2 , V_190 ) ;
}
}
F_7 ( L_25 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_189 * V_190 ;
unsigned int V_10 , V_191 ;
F_7 ( L_26 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
V_32 = V_5 -> V_8 ;
if ( ! V_32 )
break;
for ( V_191 = 0 ; V_191 < V_32 -> V_33 ; V_191 ++ ) {
V_190 = F_51 ( V_32 , V_191 ) ;
V_188 -> V_192 ( V_2 , V_190 ) ;
}
}
F_7 ( L_27 ) ;
}
static void F_53 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_193 * V_194 = V_2 -> V_194 ;
int V_195 = 0 ;
if ( ! V_194 )
return;
if ( V_194 -> V_196 ) {
if ( V_2 -> V_197 ) {
if ( V_194 -> V_198 || V_194 -> V_199 ) {
V_2 -> V_200 = 1 ;
V_2 -> V_201 = 1 ;
} else {
V_2 -> V_200 = 0 ;
V_2 -> V_201 = 0 ;
}
}
if ( V_2 -> V_200 != V_2 -> V_202 ) {
V_39 -> V_203 ( V_2 ) ;
V_2 -> V_202 = V_2 -> V_200 ;
}
if ( V_2 -> V_201 != V_2 -> V_204 ) {
V_39 -> V_205 ( V_2 ) ;
V_2 -> V_204 = V_2 -> V_201 ;
}
if ( V_194 -> V_206 != V_2 -> V_207 ) {
V_195 = 1 ;
switch ( V_194 -> V_206 ) {
case V_208 :
V_39 -> V_209 ( V_2 ) ;
break;
case V_210 :
V_39 -> V_211 ( V_2 ) ;
break;
case V_212 :
V_39 -> V_213 ( V_2 ) ;
break;
}
V_2 -> V_207 = V_194 -> V_206 ;
}
if ( V_194 -> V_196 != V_2 -> V_214 ) {
V_195 = 1 ;
V_2 -> V_214 = 1 ;
}
} else if ( V_2 -> V_214 ) {
V_195 = 1 ;
V_2 -> V_214 = 0 ;
V_2 -> V_207 = V_215 ;
}
if ( V_195 )
F_55 ( V_194 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_193 * V_194 = V_2 -> V_194 ;
int V_11 ;
V_2 -> V_214 = - 1 ;
V_2 -> V_207 = V_215 ;
V_2 -> V_202 = V_2 -> V_200 ;
V_2 -> V_204 = V_2 -> V_201 ;
V_11 = F_57 ( V_27 , V_194 , & F_53 ,
V_2 -> V_216 ) ;
if ( V_11 ) {
F_5 ( V_27 , L_28 ) ;
return V_11 ;
}
if ( ! V_194 -> V_217 || ( V_194 -> V_217 -> V_218 == 0 ) ) {
F_5 ( V_27 , L_29 ) ;
V_11 = - V_219 ;
goto V_220;
}
F_7 ( L_30 ,
F_58 ( & V_194 -> V_173 ) , V_194 -> V_196 ) ;
return 0 ;
V_220:
F_59 ( V_194 ) ;
return V_11 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_194 )
return;
F_59 ( V_2 -> V_194 ) ;
}
int F_61 ( struct V_42 * V_27 , unsigned int V_221 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
unsigned long V_222 ;
F_7 ( L_31 ) ;
if ( ! F_62 ( V_27 ) ||
( V_221 == V_223 && V_2 -> V_224 ) ) {
F_15 ( V_27 , L_32 ) ;
F_7 ( L_33 ) ;
return - V_46 ;
}
F_63 ( & V_2 -> V_30 , V_222 ) ;
if ( V_221 == V_225 )
F_64 ( V_27 ) ;
F_65 ( V_27 ) ;
V_39 -> V_226 ( V_2 ) ;
V_39 -> V_227 ( V_2 ) ;
F_40 ( V_2 , 0 ) ;
F_66 ( V_2 -> V_194 ) ;
V_2 -> V_224 = 1 ;
F_67 ( & V_2 -> V_30 , V_222 ) ;
F_7 ( L_33 ) ;
return 0 ;
}
int F_68 ( struct V_42 * V_27 , unsigned int V_221 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
unsigned long V_222 ;
F_7 ( L_34 ) ;
if ( ! F_62 ( V_27 ) ||
( V_221 == V_223 && ! V_2 -> V_224 ) ) {
F_15 ( V_27 , L_35 ) ;
F_7 ( L_36 ) ;
return - V_46 ;
}
F_63 ( & V_2 -> V_30 , V_222 ) ;
V_2 -> V_224 = 0 ;
F_69 ( V_2 -> V_194 ) ;
F_37 ( V_2 , 0 ) ;
V_39 -> V_228 ( V_2 ) ;
V_39 -> V_229 ( V_2 ) ;
if ( V_221 == V_225 )
F_70 ( V_27 ) ;
F_71 ( V_27 ) ;
F_67 ( & V_2 -> V_30 , V_222 ) ;
F_7 ( L_36 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_42 * V_27 = V_2 -> V_27 ;
int V_11 ;
F_7 ( L_37 ) ;
F_73 ( V_27 ) ;
V_39 -> V_230 ( V_2 ) ;
F_69 ( V_2 -> V_194 ) ;
F_37 ( V_2 , 1 ) ;
V_11 = F_43 ( V_2 ) ;
if ( V_11 )
goto V_231;
V_39 -> V_232 ( V_2 ) ;
V_39 -> V_233 ( V_2 ) ;
F_32 ( V_2 ) ;
F_71 ( V_27 ) ;
F_7 ( L_38 ) ;
return 0 ;
V_231:
F_40 ( V_2 , 1 ) ;
F_66 ( V_2 -> V_194 ) ;
V_39 -> exit ( V_2 ) ;
return V_11 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_3 * V_5 ;
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_234 * V_235 ;
unsigned int V_10 ;
F_7 ( L_39 ) ;
F_65 ( V_27 ) ;
F_34 ( V_2 ) ;
V_39 -> V_236 ( V_2 ) ;
V_39 -> V_237 ( V_2 ) ;
F_47 ( V_2 ) ;
F_40 ( V_2 , 1 ) ;
F_66 ( V_2 -> V_194 ) ;
V_39 -> exit ( V_2 ) ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
if ( ! V_5 -> V_7 )
continue;
V_235 = F_75 ( V_27 , V_5 -> V_20 ) ;
F_76 ( V_235 ) ;
}
F_7 ( L_40 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
F_7 ( L_41 ) ;
if ( ! F_62 ( V_2 -> V_27 ) )
return;
F_74 ( V_2 ) ;
F_50 ( V_2 ) ;
F_52 ( V_2 ) ;
F_72 ( V_2 ) ;
F_7 ( L_42 ) ;
}
static void F_78 ( struct V_238 * V_239 )
{
struct V_1 * V_2 = F_30 ( V_239 ,
struct V_1 ,
V_74 ) ;
F_79 () ;
F_77 ( V_2 ) ;
F_80 () ;
}
static void F_81 ( struct V_238 * V_239 )
{
struct V_1 * V_2 = F_30 ( V_239 ,
struct V_1 ,
V_86 ) ;
struct V_240 V_241 ;
T_2 V_242 ;
unsigned long V_222 ;
if ( V_2 -> V_84 ) {
V_242 = F_82 ( & V_2 -> V_243 ,
V_2 -> V_84 ) ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_244 = F_83 ( V_242 ) ;
F_84 ( V_2 -> V_245 , & V_241 ) ;
}
F_85 ( V_2 -> V_245 ) ;
F_63 ( & V_2 -> V_246 , V_222 ) ;
V_2 -> V_245 = NULL ;
F_67 ( & V_2 -> V_246 , V_222 ) ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_247 * V_247 )
{
if ( F_87 ( V_247 -> V_248 , & V_2 -> V_249 ,
sizeof( V_2 -> V_249 ) ) )
return - V_250 ;
return 0 ;
}
static int F_88 ( struct V_1 * V_2 ,
struct V_247 * V_247 )
{
struct V_251 V_252 ;
unsigned int V_253 ;
if ( F_89 ( & V_252 , V_247 -> V_248 , sizeof( V_252 ) ) )
return - V_250 ;
if ( V_252 . V_222 )
return - V_46 ;
V_253 = 0 ;
switch ( V_252 . V_254 ) {
case V_255 :
break;
case V_256 :
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
default:
return - V_259 ;
}
switch ( V_252 . V_260 ) {
case V_261 :
break;
case V_262 :
F_90 ( V_253 , V_257 , V_263 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
case V_264 :
F_90 ( V_253 , V_257 , V_265 , 1 ) ;
case V_266 :
F_90 ( V_253 , V_257 , V_267 , 1 ) ;
F_90 ( V_253 , V_257 , V_268 , 1 ) ;
F_90 ( V_253 , V_257 , V_269 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
case V_270 :
F_90 ( V_253 , V_257 , V_265 , 1 ) ;
case V_271 :
F_90 ( V_253 , V_257 , V_267 , 1 ) ;
F_90 ( V_253 , V_257 , V_268 , 1 ) ;
F_90 ( V_253 , V_257 , V_272 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
case V_273 :
F_90 ( V_253 , V_257 , V_265 , 1 ) ;
case V_274 :
F_90 ( V_253 , V_257 , V_267 , 1 ) ;
F_90 ( V_253 , V_257 , V_268 , 1 ) ;
F_90 ( V_253 , V_257 , V_272 , 1 ) ;
F_90 ( V_253 , V_257 , V_275 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
case V_276 :
F_90 ( V_253 , V_257 , V_277 , 1 ) ;
F_90 ( V_253 , V_257 , V_269 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
case V_278 :
F_90 ( V_253 , V_257 , V_277 , 1 ) ;
F_90 ( V_253 , V_257 , V_272 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
case V_279 :
F_90 ( V_253 , V_257 , V_277 , 1 ) ;
F_90 ( V_253 , V_257 , V_275 , 1 ) ;
F_90 ( V_253 , V_257 , V_272 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
case V_280 :
F_90 ( V_253 , V_257 , V_265 , 1 ) ;
F_90 ( V_253 , V_257 , V_281 , 1 ) ;
F_90 ( V_253 , V_257 , V_267 , 1 ) ;
F_90 ( V_253 , V_257 , V_268 , 1 ) ;
F_90 ( V_253 , V_257 , V_269 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
case V_282 :
F_90 ( V_253 , V_257 , V_265 , 1 ) ;
F_90 ( V_253 , V_257 , V_281 , 1 ) ;
F_90 ( V_253 , V_257 , V_267 , 1 ) ;
F_90 ( V_253 , V_257 , V_268 , 1 ) ;
F_90 ( V_253 , V_257 , V_272 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
case V_283 :
F_90 ( V_253 , V_257 , V_265 , 1 ) ;
F_90 ( V_253 , V_257 , V_281 , 1 ) ;
F_90 ( V_253 , V_257 , V_267 , 1 ) ;
F_90 ( V_253 , V_257 , V_268 , 1 ) ;
F_90 ( V_253 , V_257 , V_275 , 1 ) ;
F_90 ( V_253 , V_257 , V_272 , 1 ) ;
F_90 ( V_253 , V_257 , V_258 , 1 ) ;
break;
default:
return - V_259 ;
}
V_2 -> V_39 . V_284 ( V_2 , V_253 ) ;
memcpy ( & V_2 -> V_249 , & V_252 , sizeof( V_252 ) ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 ,
struct V_285 * V_286 ,
struct V_287 * V_288 )
{
unsigned long V_222 ;
if ( F_22 ( V_288 -> V_289 , V_290 , V_291 ) ) {
F_63 ( & V_2 -> V_246 , V_222 ) ;
if ( V_2 -> V_245 ) {
F_90 ( V_288 -> V_289 ,
V_290 , V_291 , 0 ) ;
} else {
V_2 -> V_245 = F_92 ( V_286 ) ;
F_93 ( V_286 ) -> V_292 |= V_293 ;
}
F_67 ( & V_2 -> V_246 , V_222 ) ;
}
if ( ! F_22 ( V_288 -> V_289 , V_290 , V_291 ) )
F_94 ( V_286 ) ;
}
static void F_95 ( struct V_285 * V_286 , struct V_287 * V_288 )
{
if ( F_96 ( V_286 ) )
V_288 -> V_294 = F_97 ( V_286 ) ;
}
static int F_98 ( struct V_285 * V_286 , struct V_287 * V_288 )
{
int V_11 ;
if ( ! F_22 ( V_288 -> V_289 , V_290 ,
V_295 ) )
return 0 ;
V_11 = F_99 ( V_286 , 0 ) ;
if ( V_11 )
return V_11 ;
V_288 -> V_296 = F_100 ( V_286 ) + F_101 ( V_286 ) ;
V_288 -> V_297 = F_101 ( V_286 ) ;
V_288 -> V_298 = V_286 -> V_299 - V_288 -> V_296 ;
V_288 -> V_300 = F_93 ( V_286 ) -> V_301 ;
F_7 ( L_43 , V_288 -> V_296 ) ;
F_7 ( L_44 ,
V_288 -> V_297 , V_288 -> V_298 ) ;
F_7 ( L_45 , V_288 -> V_300 ) ;
V_288 -> V_302 = F_93 ( V_286 ) -> V_303 ;
V_288 -> V_304 += ( V_288 -> V_302 - 1 ) * V_288 -> V_296 ;
return 0 ;
}
static int F_102 ( struct V_285 * V_286 )
{
if ( V_286 -> V_305 != V_306 )
return 0 ;
if ( ! F_103 ( V_286 ) )
return 0 ;
F_7 ( L_46 ) ;
return 1 ;
}
static void F_104 ( struct V_1 * V_2 ,
struct V_6 * V_32 , struct V_285 * V_286 ,
struct V_287 * V_288 )
{
struct V_307 * V_308 ;
unsigned int V_309 ;
unsigned int V_299 ;
unsigned int V_10 ;
V_288 -> V_286 = V_286 ;
V_309 = 0 ;
V_288 -> V_33 = 0 ;
V_288 -> V_302 = 1 ;
V_288 -> V_304 = V_286 -> V_299 ;
if ( F_102 ( V_286 ) ) {
if ( F_93 ( V_286 ) -> V_301 != V_32 -> V_36 . V_310 ) {
V_309 = 1 ;
V_288 -> V_33 ++ ;
}
V_288 -> V_33 ++ ;
F_90 ( V_288 -> V_289 , V_290 ,
V_295 , 1 ) ;
F_90 ( V_288 -> V_289 , V_290 ,
V_311 , 1 ) ;
} else if ( V_286 -> V_305 == V_306 )
F_90 ( V_288 -> V_289 , V_290 ,
V_311 , 1 ) ;
if ( F_96 ( V_286 ) ) {
if ( F_97 ( V_286 ) != V_32 -> V_36 . V_312 )
if ( ! V_309 ) {
V_309 = 1 ;
V_288 -> V_33 ++ ;
}
F_90 ( V_288 -> V_289 , V_290 ,
V_313 , 1 ) ;
}
if ( ( F_93 ( V_286 ) -> V_292 & V_314 ) &&
( V_2 -> V_249 . V_254 == V_256 ) )
F_90 ( V_288 -> V_289 , V_290 ,
V_291 , 1 ) ;
for ( V_299 = F_105 ( V_286 ) ; V_299 ; ) {
V_288 -> V_33 ++ ;
V_299 -= F_106 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
for ( V_10 = 0 ; V_10 < F_93 ( V_286 ) -> V_315 ; V_10 ++ ) {
V_308 = & F_93 ( V_286 ) -> V_316 [ V_10 ] ;
for ( V_299 = F_107 ( V_308 ) ; V_299 ; ) {
V_288 -> V_33 ++ ;
V_299 -= F_106 (unsigned int, len, XGBE_TX_MAX_BUF_SIZE) ;
}
}
}
static int F_108 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_187 * V_188 = & V_2 -> V_188 ;
int V_11 ;
F_7 ( L_47 ) ;
V_11 = F_56 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_109 ( V_2 -> V_317 ) ;
if ( V_11 ) {
F_15 ( V_27 , L_48 ) ;
goto V_318;
}
V_11 = F_109 ( V_2 -> V_319 ) ;
if ( V_11 ) {
F_15 ( V_27 , L_49 ) ;
goto V_320;
}
V_11 = F_14 ( V_27 , V_27 -> V_43 ) ;
if ( V_11 < 0 )
goto V_321;
V_2 -> V_44 = V_11 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
goto V_321;
V_11 = V_188 -> V_322 ( V_2 ) ;
if ( V_11 )
goto V_323;
F_110 ( & V_2 -> V_74 , F_78 ) ;
F_110 ( & V_2 -> V_86 , F_81 ) ;
V_11 = F_72 ( V_2 ) ;
if ( V_11 )
goto V_324;
F_7 ( L_50 ) ;
return 0 ;
V_324:
V_188 -> V_325 ( V_2 ) ;
V_323:
F_9 ( V_2 ) ;
V_321:
F_111 ( V_2 -> V_319 ) ;
V_320:
F_111 ( V_2 -> V_317 ) ;
V_318:
F_60 ( V_2 ) ;
return V_11 ;
}
static int F_112 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_187 * V_188 = & V_2 -> V_188 ;
F_7 ( L_51 ) ;
F_74 ( V_2 ) ;
V_188 -> V_325 ( V_2 ) ;
F_9 ( V_2 ) ;
F_111 ( V_2 -> V_319 ) ;
F_111 ( V_2 -> V_317 ) ;
F_60 ( V_2 ) ;
F_7 ( L_52 ) ;
return 0 ;
}
static int F_113 ( struct V_285 * V_286 , struct V_42 * V_27 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_3 * V_5 ;
struct V_6 * V_32 ;
struct V_287 * V_288 ;
struct V_234 * V_235 ;
int V_11 ;
F_7 ( L_53 , V_286 -> V_299 ) ;
V_5 = V_2 -> V_5 + V_286 -> V_326 ;
V_235 = F_75 ( V_27 , V_5 -> V_20 ) ;
V_32 = V_5 -> V_7 ;
V_288 = & V_32 -> V_327 ;
V_11 = V_328 ;
if ( V_286 -> V_299 == 0 ) {
F_5 ( V_27 , L_54 ) ;
F_85 ( V_286 ) ;
goto V_329;
}
memset ( V_288 , 0 , sizeof( * V_288 ) ) ;
F_104 ( V_2 , V_32 , V_286 , V_288 ) ;
V_11 = F_12 ( V_5 , V_32 , V_288 -> V_33 ) ;
if ( V_11 )
goto V_329;
V_11 = F_98 ( V_286 , V_288 ) ;
if ( V_11 ) {
F_5 ( V_27 , L_55 ) ;
F_85 ( V_286 ) ;
goto V_329;
}
F_95 ( V_286 , V_288 ) ;
if ( ! V_188 -> V_330 ( V_5 , V_286 ) ) {
F_85 ( V_286 ) ;
goto V_329;
}
F_91 ( V_2 , V_286 , V_288 ) ;
F_114 ( V_235 , V_288 -> V_304 ) ;
V_39 -> V_331 ( V_5 ) ;
#ifdef F_115
F_116 ( V_27 , V_286 , true ) ;
#endif
F_12 ( V_5 , V_32 , V_332 ) ;
V_11 = V_328 ;
V_329:
return V_11 ;
}
static void F_73 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
unsigned int V_333 , V_334 ;
F_7 ( L_56 ) ;
V_333 = ( ( V_27 -> V_222 & V_335 ) != 0 ) ;
V_334 = ( ( V_27 -> V_222 & V_336 ) != 0 ) ;
V_39 -> V_337 ( V_2 , V_333 ) ;
V_39 -> V_338 ( V_2 , V_334 ) ;
V_39 -> V_339 ( V_2 ) ;
F_7 ( L_57 ) ;
}
static int F_117 ( struct V_42 * V_27 , void * V_340 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_341 * V_342 = V_340 ;
F_7 ( L_58 ) ;
if ( ! F_118 ( V_342 -> V_343 ) )
return - V_344 ;
memcpy ( V_27 -> V_345 , V_342 -> V_343 , V_27 -> V_346 ) ;
V_39 -> V_347 ( V_2 , V_27 -> V_345 ) ;
F_7 ( L_59 ) ;
return 0 ;
}
static int F_119 ( struct V_42 * V_27 , struct V_247 * V_247 , int V_348 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
int V_11 ;
switch ( V_348 ) {
case V_349 :
V_11 = F_86 ( V_2 , V_247 ) ;
break;
case V_350 :
V_11 = F_88 ( V_2 , V_247 ) ;
break;
default:
V_11 = - V_351 ;
}
return V_11 ;
}
static int F_120 ( struct V_42 * V_27 , int V_43 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
int V_11 ;
F_7 ( L_60 ) ;
V_11 = F_14 ( V_27 , V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
V_2 -> V_44 = V_11 ;
V_27 -> V_43 = V_43 ;
F_77 ( V_2 ) ;
F_7 ( L_61 ) ;
return 0 ;
}
static struct V_352 * F_121 ( struct V_42 * V_27 ,
struct V_352 * V_353 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_354 * V_355 = & V_2 -> V_356 ;
F_7 ( L_62 , V_357 ) ;
V_2 -> V_39 . V_358 ( V_2 ) ;
V_353 -> V_359 = V_355 -> V_360 ;
V_353 -> V_361 = V_355 -> V_362 ;
V_353 -> V_363 = V_355 -> V_360 -
V_355 -> V_364 -
V_355 -> V_365 -
V_355 -> V_366 ;
V_353 -> V_367 = V_355 -> V_365 ;
V_353 -> V_368 = V_355 -> V_369 ;
V_353 -> V_370 = V_355 -> V_371 ;
V_353 -> V_372 = V_355 -> V_373 ;
V_353 -> V_302 = V_355 -> V_374 ;
V_353 -> V_304 = V_355 -> V_375 ;
V_353 -> V_376 = V_355 -> V_374 - V_355 -> V_377 ;
V_353 -> V_378 = V_27 -> V_379 . V_378 ;
F_7 ( L_63 , V_357 ) ;
return V_353 ;
}
static int F_122 ( struct V_42 * V_27 , T_3 V_380 ,
T_4 V_381 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_62 , V_357 ) ;
F_123 ( V_381 , V_2 -> V_382 ) ;
V_39 -> V_383 ( V_2 ) ;
F_7 ( L_63 , V_357 ) ;
return 0 ;
}
static int F_124 ( struct V_42 * V_27 , T_3 V_380 ,
T_4 V_381 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
F_7 ( L_62 , V_357 ) ;
F_125 ( V_381 , V_2 -> V_382 ) ;
V_39 -> V_383 ( V_2 ) ;
F_7 ( L_63 , V_357 ) ;
return 0 ;
}
static void F_126 ( struct V_42 * V_27 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_3 * V_5 ;
unsigned int V_10 ;
F_7 ( L_64 ) ;
if ( V_2 -> V_25 ) {
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ )
F_27 ( V_5 -> V_29 , V_5 ) ;
} else {
F_31 ( V_2 -> V_174 ) ;
F_19 ( V_2 -> V_174 , V_2 ) ;
F_127 ( V_2 -> V_174 ) ;
}
F_7 ( L_65 ) ;
}
static int F_128 ( struct V_42 * V_27 , T_5 V_384 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
unsigned int V_385 , V_386 ;
T_5 V_10 ;
if ( V_384 && ( V_384 != V_2 -> V_102 . V_150 ) )
return - V_46 ;
if ( V_384 ) {
F_129 ( V_27 , V_384 ) ;
for ( V_10 = 0 , V_386 = 0 , V_385 = 0 ; V_10 < V_384 ; V_10 ++ ) {
while ( ( V_386 < V_2 -> V_387 ) &&
( V_2 -> V_388 [ V_386 ] == V_10 ) )
V_386 ++ ;
F_7 ( L_66 , V_10 , V_385 , V_386 - 1 ) ;
F_130 ( V_27 , V_10 , V_386 - V_385 , V_385 ) ;
V_385 = V_386 ;
}
} else {
F_131 ( V_27 ) ;
}
return 0 ;
}
static int F_132 ( struct V_42 * V_27 ,
T_6 V_389 )
{
struct V_1 * V_2 = F_54 ( V_27 ) ;
struct V_53 * V_39 = & V_2 -> V_39 ;
T_6 V_390 , V_391 , V_392 , V_393 ;
int V_11 = 0 ;
V_390 = V_2 -> V_394 & V_395 ;
V_391 = V_2 -> V_394 & V_396 ;
V_392 = V_2 -> V_394 & V_397 ;
V_393 = V_2 -> V_394 & V_398 ;
if ( ( V_389 & V_395 ) && ! V_390 )
V_11 = V_39 -> V_399 ( V_2 ) ;
else if ( ! ( V_389 & V_395 ) && V_390 )
V_11 = V_39 -> V_400 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( ( V_389 & V_396 ) && ! V_391 )
V_39 -> V_401 ( V_2 ) ;
else if ( ! ( V_389 & V_396 ) && V_391 )
V_39 -> V_402 ( V_2 ) ;
if ( ( V_389 & V_397 ) && ! V_392 )
V_39 -> V_403 ( V_2 ) ;
else if ( ! ( V_389 & V_397 ) && V_392 )
V_39 -> V_404 ( V_2 ) ;
if ( ( V_389 & V_398 ) && ! V_393 )
V_39 -> V_405 ( V_2 ) ;
else if ( ! ( V_389 & V_398 ) && V_393 )
V_39 -> V_406 ( V_2 ) ;
V_2 -> V_394 = V_389 ;
F_7 ( L_67 ) ;
return 0 ;
}
struct V_407 * F_133 ( void )
{
return (struct V_407 * ) & V_408 ;
}
static void F_134 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_6 * V_32 = V_5 -> V_8 ;
struct V_189 * V_190 ;
while ( V_32 -> V_35 != V_32 -> V_34 ) {
V_190 = F_51 ( V_32 , V_32 -> V_35 ) ;
V_188 -> V_192 ( V_2 , V_190 ) ;
if ( V_188 -> V_409 ( V_2 , V_32 , V_190 ) )
break;
V_39 -> V_410 ( V_190 ) ;
V_32 -> V_35 ++ ;
}
V_190 = F_51 ( V_32 , V_32 -> V_35 - 1 ) ;
F_26 ( V_5 , V_411 ,
F_135 ( V_190 -> V_412 ) ) ;
}
static struct V_285 * F_136 ( struct V_1 * V_2 ,
struct V_189 * V_190 ,
unsigned int * V_299 )
{
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_285 * V_286 ;
T_5 * V_288 ;
unsigned int V_413 ;
V_286 = F_137 ( V_27 , V_190 -> V_414 . V_415 . V_416 ) ;
if ( ! V_286 )
return NULL ;
V_288 = F_138 ( V_190 -> V_414 . V_415 . V_417 . V_418 ) +
V_190 -> V_414 . V_415 . V_417 . V_419 ;
V_413 = ( V_190 -> V_414 . V_420 ) ? V_190 -> V_414 . V_420 : * V_299 ;
V_413 = F_139 ( V_190 -> V_414 . V_415 . V_416 , V_413 ) ;
F_140 ( V_286 , V_288 , V_413 ) ;
F_141 ( V_286 , V_413 ) ;
* V_299 -= V_413 ;
return V_286 ;
}
static int F_142 ( struct V_3 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_187 * V_188 = & V_2 -> V_188 ;
struct V_6 * V_32 = V_5 -> V_7 ;
struct V_189 * V_190 ;
struct V_421 * V_422 ;
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_234 * V_235 ;
int V_423 = 0 ;
unsigned int V_302 = 0 , V_304 = 0 ;
F_7 ( L_68 ) ;
if ( ! V_32 )
return 0 ;
V_235 = F_75 ( V_27 , V_5 -> V_20 ) ;
while ( ( V_423 < V_424 ) &&
( V_32 -> V_35 != V_32 -> V_34 ) ) {
V_190 = F_51 ( V_32 , V_32 -> V_35 ) ;
V_422 = V_190 -> V_422 ;
if ( ! V_39 -> V_425 ( V_422 ) )
break;
F_143 () ;
#ifdef F_144
F_145 ( V_32 , V_32 -> V_35 , 1 , 0 ) ;
#endif
if ( V_39 -> V_426 ( V_422 ) ) {
V_302 += V_190 -> V_36 . V_427 ;
V_304 += V_190 -> V_36 . V_428 ;
}
V_188 -> V_192 ( V_2 , V_190 ) ;
V_39 -> V_429 ( V_190 ) ;
V_423 ++ ;
V_32 -> V_35 ++ ;
}
if ( ! V_423 )
return 0 ;
F_146 ( V_235 , V_302 , V_304 ) ;
if ( ( V_32 -> V_36 . V_37 == 1 ) &&
( F_10 ( V_32 ) > V_430 ) ) {
V_32 -> V_36 . V_37 = 0 ;
F_147 ( V_235 ) ;
}
F_7 ( L_69 , V_423 ) ;
return V_423 ;
}
static int F_148 ( struct V_3 * V_5 , int V_431 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_53 * V_39 = & V_2 -> V_39 ;
struct V_6 * V_32 = V_5 -> V_8 ;
struct V_189 * V_190 ;
struct V_287 * V_288 ;
struct V_42 * V_27 = V_2 -> V_27 ;
struct V_92 * V_72 ;
struct V_285 * V_286 ;
struct V_240 * V_241 ;
unsigned int V_432 , error , V_433 , V_434 ;
unsigned int V_299 , V_435 , V_436 ;
unsigned int V_437 = 0 ;
int V_438 = 0 ;
F_7 ( L_70 , V_431 ) ;
if ( ! V_32 )
return 0 ;
V_72 = ( V_2 -> V_25 ) ? & V_5 -> V_72 : & V_2 -> V_72 ;
V_190 = F_51 ( V_32 , V_32 -> V_34 ) ;
V_288 = & V_32 -> V_327 ;
while ( V_438 < V_431 ) {
F_7 ( L_71 , V_32 -> V_34 ) ;
if ( ! V_437 && V_190 -> V_439 ) {
V_432 = V_190 -> V_440 . V_432 ;
V_433 = V_190 -> V_440 . V_433 ;
V_286 = V_190 -> V_440 . V_286 ;
error = V_190 -> V_440 . error ;
V_299 = V_190 -> V_440 . V_299 ;
} else {
memset ( V_288 , 0 , sizeof( * V_288 ) ) ;
V_432 = 0 ;
V_433 = 0 ;
V_286 = NULL ;
error = 0 ;
V_299 = 0 ;
}
V_441:
V_190 = F_51 ( V_32 , V_32 -> V_34 ) ;
if ( F_11 ( V_32 ) > ( V_442 >> 3 ) )
F_134 ( V_5 ) ;
if ( V_39 -> V_443 ( V_5 ) )
break;
V_437 ++ ;
V_32 -> V_34 ++ ;
V_432 = F_22 ( V_288 -> V_289 ,
V_444 ,
V_445 ) ;
V_433 = F_22 ( V_288 -> V_289 ,
V_444 ,
V_446 ) ;
V_434 = F_22 ( V_288 -> V_289 ,
V_444 ,
V_447 ) ;
if ( ( V_432 || V_433 ) && error )
goto V_441;
if ( error || V_288 -> V_448 ) {
if ( V_288 -> V_448 )
F_7 ( L_72 ) ;
F_149 ( V_286 ) ;
goto V_449;
}
if ( ! V_434 ) {
V_435 = V_190 -> V_414 . V_299 - V_299 ;
V_299 += V_435 ;
if ( ! V_286 ) {
F_150 ( V_2 -> V_173 ,
V_190 -> V_414 . V_415 . V_450 ,
V_190 -> V_414 . V_415 . V_416 ,
V_451 ) ;
V_286 = F_136 ( V_2 , V_190 , & V_435 ) ;
if ( ! V_286 ) {
error = 1 ;
goto V_452;
}
}
if ( V_435 ) {
F_150 ( V_2 -> V_173 ,
V_190 -> V_414 . V_453 . V_450 ,
V_190 -> V_414 . V_453 . V_416 ,
V_451 ) ;
F_151 ( V_286 , F_93 ( V_286 ) -> V_315 ,
V_190 -> V_414 . V_453 . V_417 . V_418 ,
V_190 -> V_414 . V_453 . V_417 . V_419 ,
V_435 , V_190 -> V_414 . V_453 . V_416 ) ;
V_190 -> V_414 . V_453 . V_417 . V_418 = NULL ;
}
}
V_452:
if ( V_432 || V_433 )
goto V_441;
if ( ! V_286 )
goto V_449;
V_436 = V_27 -> V_43 + V_47 ;
if ( ! ( V_27 -> V_389 & V_397 ) &&
( V_286 -> V_454 == F_152 ( V_455 ) ) )
V_436 += V_49 ;
if ( V_286 -> V_299 > V_436 ) {
F_7 ( L_73 ) ;
F_149 ( V_286 ) ;
goto V_449;
}
#ifdef F_153
F_116 ( V_27 , V_286 , false ) ;
#endif
F_154 ( V_286 ) ;
if ( F_22 ( V_288 -> V_289 ,
V_444 , V_456 ) )
V_286 -> V_305 = V_457 ;
if ( F_22 ( V_288 -> V_289 ,
V_444 , V_313 ) )
F_155 ( V_286 , F_152 ( V_455 ) ,
V_288 -> V_294 ) ;
if ( F_22 ( V_288 -> V_289 ,
V_444 , V_458 ) ) {
T_2 V_242 ;
V_242 = F_82 ( & V_2 -> V_243 ,
V_288 -> V_459 ) ;
V_241 = F_156 ( V_286 ) ;
V_241 -> V_244 = F_83 ( V_242 ) ;
}
if ( F_22 ( V_288 -> V_289 ,
V_444 , V_460 ) )
F_157 ( V_286 , V_288 -> V_461 ,
V_288 -> V_462 ) ;
V_286 -> V_173 = V_27 ;
V_286 -> V_454 = F_158 ( V_286 , V_27 ) ;
F_159 ( V_286 , V_5 -> V_20 ) ;
F_160 ( V_286 , V_72 ) ;
V_27 -> V_463 = V_464 ;
F_161 ( V_72 , V_286 ) ;
V_449:
V_438 ++ ;
}
if ( V_437 && ( V_432 || V_433 ) ) {
V_190 = F_51 ( V_32 , V_32 -> V_34 ) ;
V_190 -> V_439 = 1 ;
V_190 -> V_440 . V_432 = V_432 ;
V_190 -> V_440 . V_433 = V_433 ;
V_190 -> V_440 . V_286 = V_286 ;
V_190 -> V_440 . V_299 = V_299 ;
V_190 -> V_440 . error = error ;
}
F_7 ( L_74 , V_438 ) ;
return V_438 ;
}
static int V_169 ( struct V_92 * V_72 , int V_431 )
{
struct V_3 * V_5 = F_30 ( V_72 , struct V_3 ,
V_72 ) ;
int V_423 = 0 ;
F_7 ( L_75 , V_431 ) ;
F_142 ( V_5 ) ;
V_423 = F_148 ( V_5 , V_431 ) ;
if ( V_423 < V_431 ) {
F_162 ( V_72 ) ;
F_127 ( V_5 -> V_29 ) ;
}
F_7 ( L_76 , V_423 ) ;
return V_423 ;
}
static int V_171 ( struct V_92 * V_72 , int V_431 )
{
struct V_1 * V_2 = F_30 ( V_72 , struct V_1 ,
V_72 ) ;
struct V_3 * V_5 ;
int V_465 ;
int V_423 , V_466 ;
unsigned int V_10 ;
F_7 ( L_77 , V_431 ) ;
V_423 = 0 ;
V_465 = V_431 / V_2 -> V_17 ;
do {
V_466 = V_423 ;
V_5 = V_2 -> V_5 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_31 ; V_10 ++ , V_5 ++ ) {
F_142 ( V_5 ) ;
if ( V_465 > ( V_431 - V_423 ) )
V_465 = V_431 - V_423 ;
V_423 += F_148 ( V_5 , V_465 ) ;
}
} while ( ( V_423 < V_431 ) && ( V_423 != V_466 ) );
if ( V_423 < V_431 ) {
F_162 ( V_72 ) ;
F_17 ( V_2 ) ;
}
F_7 ( L_78 , V_423 ) ;
return V_423 ;
}
void F_145 ( struct V_6 * V_32 , unsigned int V_467 ,
unsigned int V_9 , unsigned int V_468 )
{
struct V_189 * V_190 ;
struct V_421 * V_422 ;
while ( V_9 -- ) {
V_190 = F_51 ( V_32 , V_467 ) ;
V_422 = V_190 -> V_422 ;
F_163 ( L_79 , V_467 ,
( V_468 == 1 ) ? L_80 : L_81 ,
F_164 ( V_422 -> V_469 ) , F_164 ( V_422 -> V_470 ) ,
F_164 ( V_422 -> V_471 ) , F_164 ( V_422 -> V_472 ) ) ;
V_467 ++ ;
}
}
void F_165 ( struct V_6 * V_32 , struct V_421 * V_473 ,
unsigned int V_467 )
{
F_163 ( L_82 , V_467 ,
F_164 ( V_473 -> V_469 ) , F_164 ( V_473 -> V_470 ) ,
F_164 ( V_473 -> V_471 ) , F_164 ( V_473 -> V_472 ) ) ;
}
void F_116 ( struct V_42 * V_27 , struct V_285 * V_286 , bool V_474 )
{
struct V_475 * V_476 = (struct V_475 * ) V_286 -> V_62 ;
unsigned char * V_453 = V_286 -> V_62 ;
unsigned char V_477 [ 128 ] ;
unsigned int V_10 , V_191 ;
F_15 ( V_27 , L_83 ) ;
F_15 ( V_27 , L_84 ,
( V_474 ? L_85 : L_86 ) , V_286 -> V_299 ) ;
F_15 ( V_27 , L_87 , V_476 -> V_478 ) ;
F_15 ( V_27 , L_88 , V_476 -> V_479 ) ;
F_15 ( V_27 , L_89 , F_166 ( V_476 -> V_480 ) ) ;
for ( V_10 = 0 , V_191 = 0 ; V_10 < V_286 -> V_299 ; ) {
V_191 += snprintf ( V_477 + V_191 , sizeof( V_477 ) - V_191 , L_90 ,
V_453 [ V_10 ++ ] ) ;
if ( ( V_10 % 32 ) == 0 ) {
F_15 ( V_27 , L_91 , V_10 - 32 , V_477 ) ;
V_191 = 0 ;
} else if ( ( V_10 % 16 ) == 0 ) {
V_477 [ V_191 ++ ] = ' ' ;
V_477 [ V_191 ++ ] = ' ' ;
} else if ( ( V_10 % 4 ) == 0 ) {
V_477 [ V_191 ++ ] = ' ' ;
}
}
if ( V_10 % 32 )
F_15 ( V_27 , L_91 , V_10 - ( V_10 % 32 ) , V_477 ) ;
F_15 ( V_27 , L_83 ) ;
}
