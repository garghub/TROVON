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
F_11 ( V_28 ) ;
}
static unsigned int F_12 ( struct V_29 * V_30 )
{
unsigned long V_42 ;
struct V_27 * V_28 ;
struct V_68 * V_69 ;
int V_70 = V_71 ;
unsigned int V_72 , V_73 = 0 ;
struct V_45 * V_46 = V_30 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_37 * V_38 = V_33 -> V_39 -> V_40 ;
struct V_75 * V_76 = V_38 -> V_77 . V_78 ;
struct V_79 * V_80 = F_13 ( V_76 -> V_81 ) ;
F_14 ( V_42 ) ;
F_15 ( V_46 -> V_52 ) ;
if ( F_5 ( V_82 , & V_33 -> V_49 ) )
goto V_83;
V_28 = F_16 ( V_84 ) ;
if ( ! V_28 )
goto V_83;
V_28 -> V_33 = V_33 ;
V_28 -> V_85 = V_86 ;
V_28 -> V_87 = F_3 ;
if ( V_30 -> V_88 . V_89 == V_90 ||
V_30 -> V_88 . V_89 == V_91 ||
V_30 -> V_88 . V_89 == V_92 ||
V_30 -> V_88 . V_89 == V_93 ||
V_30 -> V_88 . V_89 == V_94 ) {
V_30 -> V_88 . V_95 = 0 ;
}
F_17 ( & V_30 -> V_88 , V_30 -> V_33 -> V_44 -> V_96 , 1 , ( V_97 * ) & V_28 -> V_98 . V_59 ) ;
V_28 -> V_31 = V_30 ;
if ( F_18 ( V_30 -> V_88 . V_99 ) ) {
memcpy ( V_28 -> V_98 . V_100 , V_30 -> V_101 , V_30 -> V_33 -> V_102 ) ;
V_28 -> V_103 = V_30 -> V_104 ;
V_28 -> V_105 = V_30 -> V_106 ;
} else {
F_19 (qc->sg, sg, qc->n_elem, si)
V_73 += V_69 -> V_107 ;
V_28 -> V_103 = V_73 ;
V_28 -> V_105 = V_72 ;
}
V_28 -> V_108 = V_30 -> V_109 ;
V_28 -> V_110 = V_30 -> V_69 ;
V_28 -> V_98 . V_111 = 1 ;
V_28 -> V_112 = V_113 ;
V_30 -> V_67 = V_28 ;
switch ( V_30 -> V_88 . V_99 ) {
case V_114 :
V_28 -> V_98 . V_115 = 1 ;
case V_116 :
case V_117 :
V_28 -> V_98 . V_118 = 1 ;
break;
}
if ( V_30 -> V_50 )
F_6 ( V_30 -> V_50 , V_28 ) ;
V_70 = V_80 -> V_119 -> V_120 ( V_28 , V_84 ) ;
if ( V_70 ) {
F_2 ( L_3 , V_70 ) ;
if ( V_30 -> V_50 )
F_6 ( V_30 -> V_50 , NULL ) ;
F_11 ( V_28 ) ;
V_70 = V_71 ;
}
V_83:
F_20 ( V_46 -> V_52 ) ;
F_21 ( V_42 ) ;
return V_70 ;
}
static bool F_22 ( struct V_29 * V_30 )
{
struct V_32 * V_33 = V_30 -> V_46 -> V_74 ;
F_23 ( V_33 -> V_56 . V_59 , & V_30 -> V_121 ) ;
return true ;
}
static struct V_79 * F_24 ( struct V_32 * V_33 )
{
return F_13 ( V_33 -> V_39 -> V_40 -> V_77 . V_78 -> V_81 ) ;
}
int F_25 ( struct V_32 * V_33 , struct V_122 * V_123 )
{
if ( V_123 -> V_124 & V_86 )
V_33 -> V_125 = V_123 -> V_124 ;
if ( V_123 -> V_126 )
V_33 -> V_125 |= V_127 ;
if ( V_123 -> V_128 == V_129 )
V_33 -> V_130 = V_129 ;
else {
int V_131 ;
V_33 -> V_130 = V_127 ;
V_131 = F_26 ( V_33 -> V_132 , V_123 -> V_133 ,
& V_33 -> V_56 . V_134 ) ;
if ( V_131 ) {
F_2 ( L_4
L_5 , F_27 ( V_33 -> V_132 -> V_135 ) ,
V_123 -> V_133 , V_131 ) ;
return V_131 ;
}
memcpy ( V_33 -> V_136 , & V_33 -> V_56 . V_134 . V_137 . V_59 ,
sizeof( struct V_138 ) ) ;
V_33 -> V_56 . V_57 = F_28 ( V_33 ) ;
}
return 0 ;
}
static int F_29 ( struct V_32 * V_33 , struct V_122 * V_123 )
{
int V_131 ;
if ( V_33 -> V_130 != V_129 )
return 1 ;
V_131 = F_25 ( V_33 , V_123 ) ;
if ( V_131 )
return 0 ;
else
return 1 ;
}
static int F_30 ( struct V_43 * V_44 )
{
int V_131 ;
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_32 * V_139 = V_33 -> V_132 ;
struct V_140 * V_123 = F_31 ( V_33 ) ;
struct V_122 * V_122 = & V_139 -> V_139 . V_122 [ V_123 -> V_141 ] ;
V_131 = F_32 ( V_139 , V_123 -> V_141 ) ;
F_33 ( V_123 ) ;
if ( V_131 == - V_142 )
return V_131 ;
if ( V_131 != V_143 )
return 0 ;
switch ( V_122 -> V_128 ) {
case V_129 :
return 0 ;
case V_144 :
if ( V_122 -> V_126 )
return F_29 ( V_33 , V_122 ) ;
default:
return - V_145 ;
}
}
static int F_34 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_79 * V_80 = F_24 ( V_33 ) ;
if ( V_80 -> V_119 -> V_146 )
return V_80 -> V_119 -> V_146 ( V_33 ) ;
else {
return 1 ;
}
}
static int F_35 ( const char * V_147 , const struct V_32 * V_148 ,
const char * V_149 , ... )
{
struct V_45 * V_46 = V_148 -> V_56 . V_46 ;
struct V_150 * V_33 = & V_148 -> V_151 -> V_33 ;
struct V_152 V_153 ;
T_1 args ;
int V_154 ;
va_start ( args , V_149 ) ;
V_153 . V_149 = V_149 ;
V_153 . V_155 = & args ;
V_154 = F_36 ( L_6 ,
V_147 , V_46 -> V_156 , F_37 ( V_33 ) , & V_153 ) ;
va_end ( args ) ;
return V_154 ;
}
static int F_38 ( struct V_43 * V_44 , unsigned int * V_57 ,
unsigned long V_157 )
{
int V_70 = 0 , V_131 ;
struct V_140 * V_123 ;
struct V_45 * V_46 = V_44 -> V_46 ;
int (* F_39)( struct V_43 * V_44 );
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_79 * V_80 = F_24 ( V_33 ) ;
V_131 = V_80 -> V_119 -> V_158 ( V_33 ) ;
if ( V_131 == - V_145 )
return V_131 ;
if ( V_131 != V_159 )
F_35 ( V_160 , V_33 , L_7 ) ;
V_123 = F_31 ( V_33 ) ;
if ( F_40 ( V_123 ) )
F_39 = F_34 ;
else
F_39 = F_30 ;
F_33 ( V_123 ) ;
V_70 = F_41 ( V_44 , V_157 , F_39 ) ;
if ( V_70 && V_70 != - V_161 )
F_35 ( V_162 , V_33 , L_8 , V_70 ) ;
* V_57 = V_33 -> V_56 . V_57 ;
V_46 -> V_163 = V_164 ;
return V_70 ;
}
static void F_42 ( struct V_27 * V_28 )
{
struct V_79 * V_72 = F_24 ( V_28 -> V_33 ) ;
unsigned long V_42 ;
int V_131 ;
F_4 ( & V_28 -> V_165 , V_42 ) ;
if ( V_28 -> V_112 & V_166 ||
V_28 -> V_112 & V_167 ) {
F_7 ( & V_28 -> V_165 , V_42 ) ;
F_2 ( L_9 , V_21 ,
V_28 ) ;
goto V_83;
}
V_28 -> V_112 |= V_166 ;
F_7 ( & V_28 -> V_165 , V_42 ) ;
V_131 = V_72 -> V_119 -> V_168 ( V_28 ) ;
F_4 ( & V_28 -> V_165 , V_42 ) ;
if ( V_28 -> V_112 & V_167 ||
V_131 == V_159 ) {
F_7 ( & V_28 -> V_165 , V_42 ) ;
goto V_83;
}
F_2 ( L_10 , V_21 , V_28 ) ;
if ( ! ( V_28 -> V_112 & V_167 ) )
V_28 -> V_112 &= ~ V_166 ;
F_7 ( & V_28 -> V_165 , V_42 ) ;
return;
V_83:
F_11 ( V_28 ) ;
}
static void F_43 ( struct V_29 * V_30 )
{
if ( V_30 -> V_42 & V_65 )
V_30 -> V_63 |= V_22 ;
if ( V_30 -> V_63 ) {
struct V_27 * V_28 = V_30 -> V_67 ;
V_30 -> V_67 = NULL ;
if ( ! V_28 )
return;
V_28 -> V_31 = NULL ;
F_42 ( V_28 ) ;
}
}
static void F_44 ( struct V_45 * V_46 , struct V_169 * V_170 )
{
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_79 * V_80 = F_24 ( V_33 ) ;
if ( V_80 -> V_119 -> V_171 )
V_80 -> V_119 -> V_171 ( V_33 ) ;
}
static void F_45 ( struct V_45 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
unsigned long V_42 ;
F_4 ( & V_40 -> V_52 , V_42 ) ;
if ( ! F_46 ( V_172 , & V_33 -> V_49 ) )
V_40 -> V_173 ++ ;
F_47 ( V_46 ) ;
F_7 ( & V_40 -> V_52 , V_42 ) ;
}
void F_48 ( struct V_45 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
unsigned long V_42 ;
F_4 ( & V_40 -> V_52 , V_42 ) ;
if ( F_49 ( V_172 , & V_33 -> V_49 ) )
V_40 -> V_173 -- ;
F_7 ( & V_40 -> V_52 , V_42 ) ;
}
int F_50 ( struct V_32 * V_174 )
{
struct V_37 * V_40 = V_174 -> V_39 -> V_40 ;
struct V_75 * V_78 = V_40 -> V_77 . V_78 ;
struct V_45 * V_46 ;
int V_175 ;
F_51 ( & V_174 -> V_56 . V_176 , V_40 -> V_33 , & V_177 ) ;
V_46 = F_52 ( & V_174 -> V_56 . V_176 ,
& V_178 ,
V_78 ) ;
if ( ! V_46 ) {
F_2 ( L_11 ) ;
return - V_145 ;
}
V_46 -> V_74 = V_174 ;
V_46 -> V_163 = V_164 ;
V_46 -> V_179 = V_78 ;
V_175 = F_53 ( V_46 ) ;
if ( V_175 ) {
F_54 ( V_46 ) ;
return V_175 ;
}
V_174 -> V_56 . V_46 = V_46 ;
return 0 ;
}
void F_55 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_180 * V_181 ;
if ( V_30 -> V_50 ) {
struct V_182 * V_183 = V_30 -> V_50 -> V_150 -> V_182 ;
unsigned long V_42 ;
F_4 ( V_183 -> V_184 , V_42 ) ;
F_56 ( V_30 -> V_50 -> V_185 ) ;
F_7 ( V_183 -> V_184 , V_42 ) ;
return;
}
V_30 -> V_42 &= ~ V_186 ;
V_30 -> V_42 |= V_65 ;
V_30 -> V_63 |= V_9 ;
V_181 = V_30 -> V_74 ;
F_57 ( V_181 ) ;
}
static int F_28 ( struct V_32 * V_33 )
{
struct V_138 * V_59 =
(struct V_138 * ) V_33 -> V_136 ;
struct V_187 V_88 ;
if ( V_33 -> V_130 == V_129 )
return V_188 ;
F_23 ( ( const V_97 * ) V_59 , & V_88 ) ;
return F_58 ( & V_88 ) ;
}
void F_59 ( struct V_189 * V_39 )
{
struct V_32 * V_33 , * V_190 ;
F_60 ( & V_39 -> V_40 -> V_191 ) ;
F_61 (dev, &port->disco_list, disco_list_node) {
if ( ! F_62 ( V_33 ) )
continue;
F_63 ( V_33 -> V_56 . V_46 ) ;
}
F_64 ( & V_39 -> V_40 -> V_191 ) ;
F_65 (dev, n, &port->disco_list, disco_list_node) {
if ( ! F_62 ( V_33 ) )
continue;
F_66 ( V_33 ) ;
if ( F_67 ( F_68 ( V_33 ) ) )
F_69 ( V_33 , V_21 , - V_145 ) ;
}
}
static void F_70 ( struct V_189 * V_39 , const char * V_192 )
{
struct V_32 * V_33 , * V_190 ;
F_65 (dev, n, &port->dev_list, dev_list_node) {
if ( ! F_62 ( V_33 ) )
continue;
F_66 ( V_33 ) ;
if ( F_67 ( F_68 ( V_33 ) ) )
F_69 ( V_33 , V_192 , - V_145 ) ;
}
}
void F_71 ( struct V_189 * V_39 )
{
struct V_32 * V_33 ;
F_60 ( & V_39 -> V_40 -> V_191 ) ;
F_61 (dev, &port->dev_list, dev_list_node) {
struct V_193 * V_194 ;
if ( ! F_62 ( V_33 ) )
continue;
V_194 = & V_33 -> V_56 ;
if ( V_194 -> V_46 -> V_195 . V_196 == V_197 )
continue;
F_72 ( V_194 -> V_46 ) ;
}
F_64 ( & V_39 -> V_40 -> V_191 ) ;
F_70 ( V_39 , V_21 ) ;
}
void F_73 ( struct V_189 * V_39 )
{
struct V_32 * V_33 ;
F_60 ( & V_39 -> V_40 -> V_191 ) ;
F_61 (dev, &port->dev_list, dev_list_node) {
struct V_193 * V_194 ;
if ( ! F_62 ( V_33 ) )
continue;
V_194 = & V_33 -> V_56 ;
if ( V_194 -> V_46 -> V_195 . V_196 == V_198 )
continue;
F_74 ( V_194 -> V_46 ) ;
}
F_64 ( & V_39 -> V_40 -> V_191 ) ;
F_70 ( V_39 , V_21 ) ;
}
int F_75 ( struct V_32 * V_33 )
{
int V_131 ;
if ( V_33 -> V_130 == V_199 )
return - V_145 ;
V_33 -> V_56 . V_57 = F_28 ( V_33 ) ;
F_76 ( V_33 , V_33 -> V_151 ) ;
V_131 = F_77 ( V_33 ) ;
if ( V_131 )
return V_131 ;
F_78 ( V_33 -> V_39 , V_200 ) ;
return 0 ;
}
static void F_79 ( void * V_201 , T_2 V_202 )
{
struct V_32 * V_33 = V_201 ;
struct V_45 * V_46 = V_33 -> V_56 . V_46 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
F_35 ( V_160 , V_33 , L_12 ) ;
F_80 ( V_40 -> V_77 . V_78 , V_46 ) ;
F_81 ( V_33 ) ;
}
void F_82 ( struct V_75 * V_78 )
{
struct V_37 * V_38 = F_83 ( V_78 ) ;
F_84 ( V_203 ) ;
int V_80 ;
F_85 ( V_38 ) ;
F_86 ( & V_38 -> V_204 ) ;
for ( V_80 = 0 ; V_80 < V_38 -> V_205 ; V_80 ++ ) {
struct V_189 * V_39 = V_38 -> V_206 [ V_80 ] ;
struct V_32 * V_33 ;
F_20 ( & V_39 -> V_207 ) ;
F_61 (dev, &port->dev_list, dev_list_node) {
if ( ! F_62 ( V_33 ) )
continue;
F_87 ( & V_33 -> V_208 ) ;
F_88 ( F_79 , V_33 , & V_203 ) ;
}
F_15 ( & V_39 -> V_207 ) ;
}
F_89 ( & V_38 -> V_204 ) ;
F_90 ( & V_203 ) ;
F_91 ( V_38 ) ;
}
void F_92 ( struct V_75 * V_78 , struct V_209 * V_210 ,
struct V_209 * V_211 )
{
struct V_212 * V_213 , * V_190 ;
struct V_32 * V_214 ;
do {
F_93 ( V_215 ) ;
V_214 = NULL ;
F_65 (cmd, n, work_q, eh_entry) {
struct V_32 * V_148 = F_94 ( V_213 ) ;
if ( ! F_62 ( V_148 ) || F_95 ( V_213 ) )
continue;
if ( V_214 && V_214 != V_148 )
continue;
V_214 = V_148 ;
F_96 ( & V_213 -> V_216 , & V_215 ) ;
}
if ( ! F_97 ( & V_215 ) ) {
struct V_45 * V_46 = V_214 -> V_56 . V_46 ;
F_35 ( V_160 , V_214 , L_13 ) ;
F_98 ( V_78 , V_46 , & V_215 ) ;
while ( ! F_97 ( & V_215 ) )
F_99 ( V_215 . V_217 ) ;
}
} while ( V_214 );
}
void F_100 ( struct V_32 * V_33 )
{
struct V_218 * V_219 ;
struct V_45 * V_46 ;
unsigned long V_42 ;
if ( ! F_62 ( V_33 ) )
return;
V_46 = V_33 -> V_56 . V_46 ;
V_219 = & V_46 -> V_44 . V_64 ;
F_4 ( V_46 -> V_52 , V_42 ) ;
V_219 -> V_63 |= V_9 ;
V_219 -> V_220 |= V_221 ;
F_101 ( V_46 ) ;
F_7 ( V_46 -> V_52 , V_42 ) ;
}
void F_66 ( struct V_32 * V_33 )
{
struct V_45 * V_46 ;
if ( ! F_62 ( V_33 ) )
return;
V_46 = V_33 -> V_56 . V_46 ;
F_102 ( V_46 ) ;
}
