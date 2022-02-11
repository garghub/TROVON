static enum V_1 F_1 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 == V_5 )
return V_6 ;
switch ( V_3 -> V_7 ) {
case V_8 :
return V_9 ;
case V_10 :
case V_11 :
case V_12 :
return V_6 ;
case V_13 :
return 0 ;
case V_14 :
case V_15 :
case V_16 :
case V_17 :
return V_18 ;
case V_19 :
case V_20 :
F_2 ( L_1 ,
V_21 , V_3 -> V_7 ) ;
return V_22 ;
case V_23 :
case V_24 :
return V_25 ;
case V_26 :
return 0 ;
default:
return 0 ;
}
}
static void F_3 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_32 * V_33 = V_28 -> V_33 ;
struct V_2 * V_7 = & V_28 -> V_34 ;
struct V_35 * V_4 = (struct V_35 * ) V_7 -> V_36 ;
struct V_37 * V_38 = V_33 -> V_39 -> V_40 ;
enum V_1 V_41 ;
unsigned long V_42 ;
struct V_43 * V_44 ;
struct V_45 * V_46 ;
F_4 ( & V_33 -> V_47 , V_42 ) ;
if ( F_5 ( V_48 , & V_38 -> V_49 ) )
V_28 = NULL ;
else if ( V_30 && V_30 -> V_50 )
F_6 ( V_30 -> V_50 , NULL ) ;
F_7 ( & V_33 -> V_47 , V_42 ) ;
if ( F_8 ( ! V_28 ) )
return;
if ( ! V_30 )
goto V_51;
V_46 = V_30 -> V_46 ;
V_44 = & V_46 -> V_44 ;
F_4 ( V_46 -> V_52 , V_42 ) ;
if ( F_8 ( V_46 -> V_53 & V_54 ) ) {
F_7 ( V_46 -> V_52 , V_42 ) ;
if ( V_30 -> V_50 )
goto V_51;
else {
return;
}
}
if ( V_7 -> V_7 == V_26 || V_7 -> V_7 == V_55 ||
( ( V_7 -> V_7 == V_23 &&
V_33 -> V_56 . V_57 == V_58 ) ) ) {
memcpy ( V_33 -> V_56 . V_59 , V_4 -> V_60 , V_61 ) ;
if ( ! V_44 -> V_62 ) {
V_30 -> V_63 |= F_9 ( V_33 -> V_56 . V_59 [ 2 ] ) ;
} else {
V_44 -> V_64 . V_63 |= F_9 ( V_33 -> V_56 . V_59 [ 2 ] ) ;
if ( F_8 ( V_44 -> V_64 . V_63 ) )
V_30 -> V_42 |= V_65 ;
}
} else {
V_41 = F_1 ( V_7 ) ;
if ( V_41 ) {
F_2 ( L_2 , V_21 ,
V_7 -> V_7 ) ;
if ( ! V_44 -> V_62 ) {
V_30 -> V_63 = V_41 ;
} else {
V_44 -> V_64 . V_63 |= V_25 ;
V_30 -> V_42 |= V_65 ;
}
V_33 -> V_56 . V_59 [ 3 ] = 0x04 ;
V_33 -> V_56 . V_59 [ 2 ] = V_66 ;
}
}
V_30 -> V_67 = NULL ;
F_10 ( V_30 ) ;
F_7 ( V_46 -> V_52 , V_42 ) ;
V_51:
F_11 ( & V_28 -> V_68 ) ;
F_12 ( V_28 ) ;
}
static unsigned int F_13 ( struct V_29 * V_30 )
{
unsigned long V_42 ;
struct V_27 * V_28 ;
struct V_69 * V_70 ;
int V_71 = V_72 ;
unsigned int V_73 , V_74 = 0 ;
struct V_45 * V_46 = V_30 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_75 ;
struct V_37 * V_38 = V_33 -> V_39 -> V_40 ;
struct V_76 * V_77 = V_38 -> V_78 . V_79 ;
struct V_80 * V_81 = F_14 ( V_77 -> V_82 ) ;
F_15 ( V_42 ) ;
F_16 ( V_46 -> V_52 ) ;
if ( F_5 ( V_83 , & V_33 -> V_49 ) )
goto V_84;
V_28 = F_17 ( V_85 ) ;
if ( ! V_28 )
goto V_84;
V_28 -> V_33 = V_33 ;
V_28 -> V_86 = V_87 ;
V_28 -> V_88 = F_3 ;
if ( V_30 -> V_89 . V_90 == V_91 ||
V_30 -> V_89 . V_90 == V_92 ) {
V_30 -> V_89 . V_93 = 0 ;
}
F_18 ( & V_30 -> V_89 , V_30 -> V_33 -> V_44 -> V_94 , 1 , ( V_95 * ) & V_28 -> V_96 . V_59 ) ;
V_28 -> V_31 = V_30 ;
if ( F_19 ( V_30 -> V_89 . V_97 ) ) {
memcpy ( V_28 -> V_96 . V_98 , V_30 -> V_99 , V_30 -> V_33 -> V_100 ) ;
V_28 -> V_101 = V_30 -> V_102 ;
V_28 -> V_103 = V_30 -> V_104 ;
} else {
F_20 (qc->sg, sg, qc->n_elem, si)
V_74 += V_70 -> V_105 ;
V_28 -> V_101 = V_74 ;
V_28 -> V_103 = V_73 ;
}
V_28 -> V_106 = V_30 -> V_107 ;
V_28 -> V_108 = V_30 -> V_70 ;
V_28 -> V_96 . V_109 = 1 ;
V_28 -> V_110 = V_111 ;
V_30 -> V_67 = V_28 ;
switch ( V_30 -> V_89 . V_97 ) {
case V_112 :
V_28 -> V_96 . V_113 = 1 ;
case V_114 :
case V_115 :
V_28 -> V_96 . V_116 = 1 ;
break;
}
if ( V_30 -> V_50 )
F_6 ( V_30 -> V_50 , V_28 ) ;
if ( V_38 -> V_117 < 2 )
V_71 = V_81 -> V_118 -> V_119 ( V_28 , 1 , V_85 ) ;
else
V_71 = F_21 ( V_28 ) ;
if ( V_71 ) {
F_2 ( L_3 , V_71 ) ;
if ( V_30 -> V_50 )
F_6 ( V_30 -> V_50 , NULL ) ;
F_12 ( V_28 ) ;
V_71 = V_72 ;
}
V_84:
F_22 ( V_46 -> V_52 ) ;
F_23 ( V_42 ) ;
return V_71 ;
}
static bool F_24 ( struct V_29 * V_30 )
{
struct V_32 * V_33 = V_30 -> V_46 -> V_75 ;
F_25 ( V_33 -> V_56 . V_59 , & V_30 -> V_120 ) ;
return true ;
}
static struct V_80 * F_26 ( struct V_32 * V_33 )
{
return F_14 ( V_33 -> V_39 -> V_40 -> V_78 . V_79 -> V_82 ) ;
}
int F_27 ( struct V_32 * V_33 , struct V_121 * V_122 )
{
if ( V_122 -> V_123 & V_87 )
V_33 -> V_124 = V_122 -> V_123 ;
if ( V_122 -> V_125 )
V_33 -> V_124 |= V_126 ;
if ( V_122 -> V_127 == V_128 )
V_33 -> V_129 = V_128 ;
else {
int V_130 ;
V_33 -> V_129 = V_126 ;
V_130 = F_28 ( V_33 -> V_131 , V_122 -> V_132 ,
& V_33 -> V_56 . V_133 ) ;
if ( V_130 ) {
F_2 ( L_4
L_5 , F_29 ( V_33 -> V_131 -> V_134 ) ,
V_122 -> V_132 , V_130 ) ;
return V_130 ;
}
memcpy ( V_33 -> V_135 , & V_33 -> V_56 . V_133 . V_136 . V_59 ,
sizeof( struct V_137 ) ) ;
F_30 ( V_33 ) ;
}
return 0 ;
}
static int F_31 ( struct V_32 * V_33 , struct V_121 * V_122 )
{
int V_130 ;
if ( V_33 -> V_129 != V_128 )
return 1 ;
V_130 = F_27 ( V_33 , V_122 ) ;
if ( V_130 )
return 0 ;
else
return 1 ;
}
static int F_32 ( struct V_43 * V_44 )
{
int V_130 ;
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_75 ;
struct V_32 * V_138 = V_33 -> V_131 ;
struct V_139 * V_122 = F_33 ( V_33 ) ;
struct V_121 * V_121 = & V_138 -> V_138 . V_121 [ V_122 -> V_140 ] ;
V_130 = F_34 ( V_138 , V_122 -> V_140 ) ;
F_35 ( V_122 ) ;
if ( V_130 == - V_141 )
return V_130 ;
if ( V_130 != V_142 )
return 0 ;
switch ( V_121 -> V_127 ) {
case V_128 :
return 0 ;
case V_143 :
if ( V_121 -> V_125 )
return F_31 ( V_33 , V_121 ) ;
default:
return - V_144 ;
}
}
static int F_36 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_75 ;
struct V_80 * V_81 = F_26 ( V_33 ) ;
if ( V_81 -> V_118 -> V_145 )
return V_81 -> V_118 -> V_145 ( V_33 ) ;
else {
return 1 ;
}
}
static int F_37 ( const char * V_146 , const struct V_32 * V_147 ,
const char * V_148 , ... )
{
struct V_45 * V_46 = V_147 -> V_56 . V_46 ;
struct V_149 * V_33 = & V_147 -> V_150 -> V_33 ;
struct V_151 V_152 ;
T_1 args ;
int V_153 ;
va_start ( args , V_148 ) ;
V_152 . V_148 = V_148 ;
V_152 . V_154 = & args ;
V_153 = F_38 ( L_6 ,
V_146 , V_46 -> V_155 , F_39 ( V_33 ) , & V_152 ) ;
va_end ( args ) ;
return V_153 ;
}
static int F_40 ( struct V_43 * V_44 , unsigned int * V_156 ,
unsigned long V_157 )
{
int V_71 = 0 , V_130 ;
struct V_139 * V_122 ;
struct V_45 * V_46 = V_44 -> V_46 ;
int (* F_41)( struct V_43 * V_44 );
struct V_32 * V_33 = V_46 -> V_75 ;
struct V_80 * V_81 = F_26 ( V_33 ) ;
V_130 = V_81 -> V_118 -> V_158 ( V_33 ) ;
if ( V_130 == - V_144 )
return V_130 ;
if ( V_130 != V_159 )
F_37 ( V_160 , V_33 , L_7 ) ;
V_122 = F_33 ( V_33 ) ;
if ( F_42 ( V_122 ) )
F_41 = F_36 ;
else
F_41 = F_32 ;
F_35 ( V_122 ) ;
V_71 = F_43 ( V_44 , V_157 , F_41 ) ;
if ( V_71 && V_71 != - V_161 )
F_37 ( V_162 , V_33 , L_8 , V_71 ) ;
switch ( V_33 -> V_56 . V_57 ) {
case V_163 :
* V_156 = V_164 ;
break;
case V_58 :
* V_156 = V_165 ;
break;
}
V_46 -> V_166 = V_167 ;
return V_71 ;
}
static void F_44 ( struct V_27 * V_28 )
{
struct V_80 * V_73 = F_26 ( V_28 -> V_33 ) ;
unsigned long V_42 ;
int V_130 ;
F_4 ( & V_28 -> V_168 , V_42 ) ;
if ( V_28 -> V_110 & V_169 ||
V_28 -> V_110 & V_170 ) {
F_7 ( & V_28 -> V_168 , V_42 ) ;
F_2 ( L_9 , V_21 ,
V_28 ) ;
goto V_84;
}
V_28 -> V_110 |= V_169 ;
F_7 ( & V_28 -> V_168 , V_42 ) ;
V_130 = V_73 -> V_118 -> V_171 ( V_28 ) ;
F_4 ( & V_28 -> V_168 , V_42 ) ;
if ( V_28 -> V_110 & V_170 ||
V_130 == V_159 ) {
F_7 ( & V_28 -> V_168 , V_42 ) ;
goto V_84;
}
F_2 ( L_10 , V_21 , V_28 ) ;
if ( ! ( V_28 -> V_110 & V_170 ) )
V_28 -> V_110 &= ~ V_169 ;
F_7 ( & V_28 -> V_168 , V_42 ) ;
return;
V_84:
F_11 ( & V_28 -> V_68 ) ;
F_12 ( V_28 ) ;
}
static void F_45 ( struct V_29 * V_30 )
{
if ( V_30 -> V_42 & V_65 )
V_30 -> V_63 |= V_22 ;
if ( V_30 -> V_63 ) {
struct V_27 * V_28 = V_30 -> V_67 ;
V_30 -> V_67 = NULL ;
if ( ! V_28 )
return;
V_28 -> V_31 = NULL ;
F_44 ( V_28 ) ;
}
}
static void F_46 ( struct V_45 * V_46 , struct V_172 * V_173 )
{
struct V_32 * V_33 = V_46 -> V_75 ;
struct V_80 * V_81 = F_26 ( V_33 ) ;
if ( V_81 -> V_118 -> V_174 )
V_81 -> V_118 -> V_174 ( V_33 ) ;
}
static void F_47 ( struct V_45 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_75 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
unsigned long V_42 ;
F_4 ( & V_40 -> V_52 , V_42 ) ;
if ( ! F_48 ( V_175 , & V_33 -> V_49 ) )
V_40 -> V_176 ++ ;
F_49 ( V_46 ) ;
F_7 ( & V_40 -> V_52 , V_42 ) ;
}
void F_50 ( struct V_45 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_75 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
unsigned long V_42 ;
F_4 ( & V_40 -> V_52 , V_42 ) ;
if ( F_51 ( V_175 , & V_33 -> V_49 ) )
V_40 -> V_176 -- ;
F_7 ( & V_40 -> V_52 , V_42 ) ;
}
int F_52 ( struct V_32 * V_177 )
{
struct V_37 * V_40 = V_177 -> V_39 -> V_40 ;
struct V_76 * V_79 = V_40 -> V_78 . V_79 ;
struct V_45 * V_46 ;
int V_178 ;
F_53 ( & V_177 -> V_56 . V_179 , V_40 -> V_33 , & V_180 ) ;
V_46 = F_54 ( & V_177 -> V_56 . V_179 ,
& V_181 ,
V_79 ) ;
if ( ! V_46 ) {
F_2 ( L_11 ) ;
return - V_144 ;
}
V_46 -> V_75 = V_177 ;
V_46 -> V_166 = V_167 ;
V_46 -> V_182 = V_79 ;
V_178 = F_55 ( V_46 ) ;
if ( V_178 ) {
F_56 ( V_46 ) ;
return V_178 ;
}
V_177 -> V_56 . V_46 = V_46 ;
return 0 ;
}
void F_57 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_183 * V_184 ;
if ( V_30 -> V_50 ) {
struct V_185 * V_186 = V_30 -> V_50 -> V_149 -> V_185 ;
unsigned long V_42 ;
F_4 ( V_186 -> V_187 , V_42 ) ;
F_58 ( V_30 -> V_50 -> V_188 ) ;
F_7 ( V_186 -> V_187 , V_42 ) ;
return;
}
V_30 -> V_42 &= ~ V_189 ;
V_30 -> V_42 |= V_65 ;
V_30 -> V_63 |= V_9 ;
V_184 = V_30 -> V_75 ;
F_59 ( V_184 ) ;
}
static void F_30 ( struct V_32 * V_33 )
{
struct V_137 * V_59 =
(struct V_137 * ) V_33 -> V_135 ;
if ( V_33 -> V_129 == V_128 )
return;
if ( ( V_59 -> V_190 == 1 &&
V_59 -> V_191 == 1 &&
V_59 -> V_192 == 0 &&
V_59 -> V_193 == 0 &&
V_59 -> V_149 == 0 )
||
( V_59 -> V_190 == 0 &&
V_59 -> V_191 == 0 &&
V_59 -> V_192 == 0xCE &&
V_59 -> V_193 == 0xAA &&
( V_59 -> V_149 & ~ 0x10 ) == 0 ) )
V_33 -> V_56 . V_57 = V_163 ;
else if ( ( V_59 -> V_194 == 1 &&
V_59 -> V_191 == 1 &&
V_59 -> V_195 == 0x14 &&
V_59 -> V_196 == 0xEB &&
( V_59 -> V_149 & ~ 0x10 ) == 0 ) )
V_33 -> V_56 . V_57 = V_58 ;
else if ( ( V_59 -> V_190 == 1 &&
V_59 -> V_191 == 1 &&
V_59 -> V_192 == 0x3C &&
V_59 -> V_193 == 0xC3 &&
V_59 -> V_149 == 0 )
||
( V_59 -> V_194 == 1 &&
V_59 -> V_191 == 1 &&
V_59 -> V_195 == 0x69 &&
V_59 -> V_196 == 0x96 &&
( V_59 -> V_149 & ~ 0x10 ) == 0 ) )
V_33 -> V_56 . V_57 = V_58 ;
}
void F_60 ( struct V_197 * V_39 )
{
struct V_32 * V_33 , * V_198 ;
F_61 ( & V_39 -> V_40 -> V_199 ) ;
F_62 (dev, &port->disco_list, disco_list_node) {
if ( ! F_63 ( V_33 ) )
continue;
F_64 ( V_33 -> V_56 . V_46 ) ;
}
F_65 ( & V_39 -> V_40 -> V_199 ) ;
F_66 (dev, n, &port->disco_list, disco_list_node) {
if ( ! F_63 ( V_33 ) )
continue;
F_67 ( V_33 ) ;
if ( F_68 ( F_69 ( V_33 ) ) )
F_70 ( V_33 , V_21 , - V_144 ) ;
}
}
static bool F_71 ( struct V_197 * V_39 , const char * V_200 )
{
struct V_32 * V_33 , * V_198 ;
bool V_201 = false ;
F_66 (dev, n, &port->dev_list, dev_list_node) {
int V_178 ;
if ( ! F_63 ( V_33 ) )
continue;
F_67 ( V_33 ) ;
V_178 = V_33 -> V_56 . V_202 ;
if ( V_178 == - V_161 )
V_201 = true ;
else if ( V_178 ) {
F_72 ( 1 , L_12 , V_200 ,
F_39 ( & V_33 -> V_150 -> V_33 ) , V_178 ) ;
}
if ( F_68 ( F_69 ( V_33 ) ) )
F_70 ( V_33 , V_200 , - V_144 ) ;
}
return V_201 ;
}
void F_73 ( struct V_197 * V_39 )
{
struct V_32 * V_33 ;
V_201:
F_61 ( & V_39 -> V_40 -> V_199 ) ;
F_62 (dev, &port->dev_list, dev_list_node) {
struct V_203 * V_204 ;
if ( ! F_63 ( V_33 ) )
continue;
V_204 = & V_33 -> V_56 ;
if ( V_204 -> V_46 -> V_205 . V_206 == V_207 )
continue;
V_204 -> V_202 = - V_208 ;
F_74 ( V_204 -> V_46 , & V_204 -> V_202 ) ;
}
F_65 ( & V_39 -> V_40 -> V_199 ) ;
if ( F_71 ( V_39 , V_21 ) )
goto V_201;
}
void F_75 ( struct V_197 * V_39 )
{
struct V_32 * V_33 ;
V_201:
F_61 ( & V_39 -> V_40 -> V_199 ) ;
F_62 (dev, &port->dev_list, dev_list_node) {
struct V_203 * V_204 ;
if ( ! F_63 ( V_33 ) )
continue;
V_204 = & V_33 -> V_56 ;
if ( V_204 -> V_46 -> V_205 . V_206 == V_209 )
continue;
V_204 -> V_202 = - V_208 ;
F_76 ( V_204 -> V_46 , & V_204 -> V_202 ) ;
}
F_65 ( & V_39 -> V_40 -> V_199 ) ;
if ( F_71 ( V_39 , V_21 ) )
goto V_201;
}
int F_77 ( struct V_32 * V_33 )
{
int V_130 ;
if ( V_33 -> V_129 == V_210 )
return - V_144 ;
F_30 ( V_33 ) ;
F_78 ( V_33 , V_33 -> V_150 ) ;
V_130 = F_79 ( V_33 ) ;
if ( V_130 )
return V_130 ;
F_80 ( V_33 -> V_39 , V_211 ) ;
return 0 ;
}
static void F_81 ( void * V_212 , T_2 V_213 )
{
struct V_32 * V_33 = V_212 ;
struct V_45 * V_46 = V_33 -> V_56 . V_46 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
F_37 ( V_160 , V_33 , L_13 ) ;
F_82 ( V_40 -> V_78 . V_79 , V_46 ) ;
F_83 ( V_33 ) ;
}
void F_84 ( struct V_76 * V_79 )
{
struct V_37 * V_38 = F_85 ( V_79 ) ;
F_86 ( V_214 ) ;
int V_81 ;
F_87 ( V_38 ) ;
F_88 ( & V_38 -> V_215 ) ;
for ( V_81 = 0 ; V_81 < V_38 -> V_216 ; V_81 ++ ) {
struct V_197 * V_39 = V_38 -> V_217 [ V_81 ] ;
struct V_32 * V_33 ;
F_22 ( & V_39 -> V_218 ) ;
F_62 (dev, &port->dev_list, dev_list_node) {
if ( ! F_63 ( V_33 ) )
continue;
F_89 ( & V_33 -> V_219 ) ;
F_90 ( F_81 , V_33 , & V_214 ) ;
}
F_16 ( & V_39 -> V_218 ) ;
}
F_91 ( & V_38 -> V_215 ) ;
F_92 ( & V_214 ) ;
F_93 ( V_38 ) ;
}
void F_94 ( struct V_76 * V_79 , struct V_220 * V_221 ,
struct V_220 * V_222 )
{
struct V_223 * V_224 , * V_198 ;
struct V_32 * V_225 ;
do {
F_95 ( V_226 ) ;
V_225 = NULL ;
F_66 (cmd, n, work_q, eh_entry) {
struct V_32 * V_147 = F_96 ( V_224 ) ;
if ( ! F_63 ( V_147 ) || F_97 ( V_224 ) )
continue;
if ( V_225 && V_225 != V_147 )
continue;
V_225 = V_147 ;
F_98 ( & V_224 -> V_227 , & V_226 ) ;
}
if ( ! F_99 ( & V_226 ) ) {
struct V_45 * V_46 = V_225 -> V_56 . V_46 ;
F_37 ( V_160 , V_225 , L_14 ) ;
F_100 ( V_79 , V_46 , & V_226 ) ;
while ( ! F_99 ( & V_226 ) )
F_11 ( V_226 . V_228 ) ;
}
} while ( V_225 );
}
void F_101 ( struct V_32 * V_33 )
{
struct V_229 * V_230 ;
struct V_45 * V_46 ;
unsigned long V_42 ;
if ( ! F_63 ( V_33 ) )
return;
V_46 = V_33 -> V_56 . V_46 ;
V_230 = & V_46 -> V_44 . V_64 ;
F_4 ( V_46 -> V_52 , V_42 ) ;
V_230 -> V_63 |= V_9 ;
V_230 -> V_231 |= V_232 ;
F_102 ( V_46 ) ;
F_7 ( V_46 -> V_52 , V_42 ) ;
}
void F_67 ( struct V_32 * V_33 )
{
struct V_45 * V_46 ;
if ( ! F_63 ( V_33 ) )
return;
V_46 = V_33 -> V_56 . V_46 ;
F_103 ( V_46 ) ;
}
