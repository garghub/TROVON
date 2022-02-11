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
V_30 -> V_88 . V_89 == V_91 ) {
V_30 -> V_88 . V_92 = 0 ;
}
F_17 ( & V_30 -> V_88 , V_30 -> V_33 -> V_44 -> V_93 , 1 , ( V_94 * ) & V_28 -> V_95 . V_59 ) ;
V_28 -> V_31 = V_30 ;
if ( F_18 ( V_30 -> V_88 . V_96 ) ) {
memcpy ( V_28 -> V_95 . V_97 , V_30 -> V_98 , V_30 -> V_33 -> V_99 ) ;
V_28 -> V_100 = V_30 -> V_101 ;
V_28 -> V_102 = V_30 -> V_103 ;
} else {
F_19 (qc->sg, sg, qc->n_elem, si)
V_73 += V_69 -> V_104 ;
V_28 -> V_100 = V_73 ;
V_28 -> V_102 = V_72 ;
}
V_28 -> V_105 = V_30 -> V_106 ;
V_28 -> V_107 = V_30 -> V_69 ;
V_28 -> V_95 . V_108 = 1 ;
V_28 -> V_109 = V_110 ;
V_30 -> V_67 = V_28 ;
switch ( V_30 -> V_88 . V_96 ) {
case V_111 :
V_28 -> V_95 . V_112 = 1 ;
case V_113 :
case V_114 :
V_28 -> V_95 . V_115 = 1 ;
break;
}
if ( V_30 -> V_50 )
F_6 ( V_30 -> V_50 , V_28 ) ;
V_70 = V_80 -> V_116 -> V_117 ( V_28 , V_84 ) ;
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
F_23 ( V_33 -> V_56 . V_59 , & V_30 -> V_118 ) ;
return true ;
}
static struct V_79 * F_24 ( struct V_32 * V_33 )
{
return F_13 ( V_33 -> V_39 -> V_40 -> V_77 . V_78 -> V_81 ) ;
}
int F_25 ( struct V_32 * V_33 , struct V_119 * V_120 )
{
if ( V_120 -> V_121 & V_86 )
V_33 -> V_122 = V_120 -> V_121 ;
if ( V_120 -> V_123 )
V_33 -> V_122 |= V_124 ;
if ( V_120 -> V_125 == V_126 )
V_33 -> V_127 = V_126 ;
else {
int V_128 ;
V_33 -> V_127 = V_124 ;
V_128 = F_26 ( V_33 -> V_129 , V_120 -> V_130 ,
& V_33 -> V_56 . V_131 ) ;
if ( V_128 ) {
F_2 ( L_4
L_5 , F_27 ( V_33 -> V_129 -> V_132 ) ,
V_120 -> V_130 , V_128 ) ;
return V_128 ;
}
memcpy ( V_33 -> V_133 , & V_33 -> V_56 . V_131 . V_134 . V_59 ,
sizeof( struct V_135 ) ) ;
V_33 -> V_56 . V_57 = F_28 ( V_33 ) ;
}
return 0 ;
}
static int F_29 ( struct V_32 * V_33 , struct V_119 * V_120 )
{
int V_128 ;
if ( V_33 -> V_127 != V_126 )
return 1 ;
V_128 = F_25 ( V_33 , V_120 ) ;
if ( V_128 )
return 0 ;
else
return 1 ;
}
static int F_30 ( struct V_43 * V_44 )
{
int V_128 ;
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_32 * V_136 = V_33 -> V_129 ;
struct V_137 * V_120 = F_31 ( V_33 ) ;
struct V_119 * V_119 = & V_136 -> V_136 . V_119 [ V_120 -> V_138 ] ;
V_128 = F_32 ( V_136 , V_120 -> V_138 ) ;
F_33 ( V_120 ) ;
if ( V_128 == - V_139 )
return V_128 ;
if ( V_128 != V_140 )
return 0 ;
switch ( V_119 -> V_125 ) {
case V_126 :
return 0 ;
case V_141 :
if ( V_119 -> V_123 )
return F_29 ( V_33 , V_119 ) ;
default:
return - V_142 ;
}
}
static int F_34 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_79 * V_80 = F_24 ( V_33 ) ;
if ( V_80 -> V_116 -> V_143 )
return V_80 -> V_116 -> V_143 ( V_33 ) ;
else {
return 1 ;
}
}
static int F_35 ( const char * V_144 , const struct V_32 * V_145 ,
const char * V_146 , ... )
{
struct V_45 * V_46 = V_145 -> V_56 . V_46 ;
struct V_147 * V_33 = & V_145 -> V_148 -> V_33 ;
struct V_149 V_150 ;
T_1 args ;
int V_151 ;
va_start ( args , V_146 ) ;
V_150 . V_146 = V_146 ;
V_150 . V_152 = & args ;
V_151 = F_36 ( L_6 ,
V_144 , V_46 -> V_153 , F_37 ( V_33 ) , & V_150 ) ;
va_end ( args ) ;
return V_151 ;
}
static int F_38 ( struct V_43 * V_44 , unsigned int * V_57 ,
unsigned long V_154 )
{
int V_70 = 0 , V_128 ;
struct V_137 * V_120 ;
struct V_45 * V_46 = V_44 -> V_46 ;
int (* F_39)( struct V_43 * V_44 );
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_79 * V_80 = F_24 ( V_33 ) ;
V_128 = V_80 -> V_116 -> V_155 ( V_33 ) ;
if ( V_128 == - V_142 )
return V_128 ;
if ( V_128 != V_156 )
F_35 ( V_157 , V_33 , L_7 ) ;
V_120 = F_31 ( V_33 ) ;
if ( F_40 ( V_120 ) )
F_39 = F_34 ;
else
F_39 = F_30 ;
F_33 ( V_120 ) ;
V_70 = F_41 ( V_44 , V_154 , F_39 ) ;
if ( V_70 && V_70 != - V_158 )
F_35 ( V_159 , V_33 , L_8 , V_70 ) ;
* V_57 = V_33 -> V_56 . V_57 ;
V_46 -> V_160 = V_161 ;
return V_70 ;
}
static void F_42 ( struct V_27 * V_28 )
{
struct V_79 * V_72 = F_24 ( V_28 -> V_33 ) ;
unsigned long V_42 ;
int V_128 ;
F_4 ( & V_28 -> V_162 , V_42 ) ;
if ( V_28 -> V_109 & V_163 ||
V_28 -> V_109 & V_164 ) {
F_7 ( & V_28 -> V_162 , V_42 ) ;
F_2 ( L_9 , V_21 ,
V_28 ) ;
goto V_83;
}
V_28 -> V_109 |= V_163 ;
F_7 ( & V_28 -> V_162 , V_42 ) ;
V_128 = V_72 -> V_116 -> V_165 ( V_28 ) ;
F_4 ( & V_28 -> V_162 , V_42 ) ;
if ( V_28 -> V_109 & V_164 ||
V_128 == V_156 ) {
F_7 ( & V_28 -> V_162 , V_42 ) ;
goto V_83;
}
F_2 ( L_10 , V_21 , V_28 ) ;
if ( ! ( V_28 -> V_109 & V_164 ) )
V_28 -> V_109 &= ~ V_163 ;
F_7 ( & V_28 -> V_162 , V_42 ) ;
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
static void F_44 ( struct V_45 * V_46 , struct V_166 * V_167 )
{
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_79 * V_80 = F_24 ( V_33 ) ;
if ( V_80 -> V_116 -> V_168 )
V_80 -> V_116 -> V_168 ( V_33 ) ;
}
static void F_45 ( struct V_45 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
unsigned long V_42 ;
F_4 ( & V_40 -> V_52 , V_42 ) ;
if ( ! F_46 ( V_169 , & V_33 -> V_49 ) )
V_40 -> V_170 ++ ;
F_47 ( V_46 ) ;
F_7 ( & V_40 -> V_52 , V_42 ) ;
}
void F_48 ( struct V_45 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
unsigned long V_42 ;
F_4 ( & V_40 -> V_52 , V_42 ) ;
if ( F_49 ( V_169 , & V_33 -> V_49 ) )
V_40 -> V_170 -- ;
F_7 ( & V_40 -> V_52 , V_42 ) ;
}
int F_50 ( struct V_32 * V_171 )
{
struct V_37 * V_40 = V_171 -> V_39 -> V_40 ;
struct V_75 * V_78 = V_40 -> V_77 . V_78 ;
struct V_45 * V_46 ;
int V_172 ;
F_51 ( & V_171 -> V_56 . V_173 , V_40 -> V_33 , & V_174 ) ;
V_46 = F_52 ( & V_171 -> V_56 . V_173 ,
& V_175 ,
V_78 ) ;
if ( ! V_46 ) {
F_2 ( L_11 ) ;
return - V_142 ;
}
V_46 -> V_74 = V_171 ;
V_46 -> V_160 = V_161 ;
V_46 -> V_176 = V_78 ;
V_172 = F_53 ( V_46 ) ;
if ( V_172 ) {
F_54 ( V_46 ) ;
return V_172 ;
}
V_171 -> V_56 . V_46 = V_46 ;
return 0 ;
}
void F_55 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_177 * V_178 ;
if ( V_30 -> V_50 ) {
struct V_179 * V_180 = V_30 -> V_50 -> V_147 -> V_179 ;
unsigned long V_42 ;
F_4 ( V_180 -> V_181 , V_42 ) ;
F_56 ( V_30 -> V_50 -> V_182 ) ;
F_7 ( V_180 -> V_181 , V_42 ) ;
return;
}
V_30 -> V_42 &= ~ V_183 ;
V_30 -> V_42 |= V_65 ;
V_30 -> V_63 |= V_9 ;
V_178 = V_30 -> V_74 ;
F_57 ( V_178 ) ;
}
static int F_28 ( struct V_32 * V_33 )
{
struct V_135 * V_59 =
(struct V_135 * ) V_33 -> V_133 ;
struct V_184 V_88 ;
if ( V_33 -> V_127 == V_126 )
return V_185 ;
F_23 ( ( const V_94 * ) V_59 , & V_88 ) ;
return F_58 ( & V_88 ) ;
}
void F_59 ( struct V_186 * V_39 )
{
struct V_32 * V_33 , * V_187 ;
F_60 ( & V_39 -> V_40 -> V_188 ) ;
F_61 (dev, &port->disco_list, disco_list_node) {
if ( ! F_62 ( V_33 ) )
continue;
F_63 ( V_33 -> V_56 . V_46 ) ;
}
F_64 ( & V_39 -> V_40 -> V_188 ) ;
F_65 (dev, n, &port->disco_list, disco_list_node) {
if ( ! F_62 ( V_33 ) )
continue;
F_66 ( V_33 ) ;
if ( F_67 ( F_68 ( V_33 ) ) )
F_69 ( V_33 , V_21 , - V_142 ) ;
}
}
static void F_70 ( struct V_186 * V_39 , const char * V_189 )
{
struct V_32 * V_33 , * V_187 ;
F_65 (dev, n, &port->dev_list, dev_list_node) {
if ( ! F_62 ( V_33 ) )
continue;
F_66 ( V_33 ) ;
if ( F_67 ( F_68 ( V_33 ) ) )
F_69 ( V_33 , V_189 , - V_142 ) ;
}
}
void F_71 ( struct V_186 * V_39 )
{
struct V_32 * V_33 ;
F_60 ( & V_39 -> V_40 -> V_188 ) ;
F_61 (dev, &port->dev_list, dev_list_node) {
struct V_190 * V_191 ;
if ( ! F_62 ( V_33 ) )
continue;
V_191 = & V_33 -> V_56 ;
if ( V_191 -> V_46 -> V_192 . V_193 == V_194 )
continue;
F_72 ( V_191 -> V_46 ) ;
}
F_64 ( & V_39 -> V_40 -> V_188 ) ;
F_70 ( V_39 , V_21 ) ;
}
void F_73 ( struct V_186 * V_39 )
{
struct V_32 * V_33 ;
F_60 ( & V_39 -> V_40 -> V_188 ) ;
F_61 (dev, &port->dev_list, dev_list_node) {
struct V_190 * V_191 ;
if ( ! F_62 ( V_33 ) )
continue;
V_191 = & V_33 -> V_56 ;
if ( V_191 -> V_46 -> V_192 . V_193 == V_195 )
continue;
F_74 ( V_191 -> V_46 ) ;
}
F_64 ( & V_39 -> V_40 -> V_188 ) ;
F_70 ( V_39 , V_21 ) ;
}
int F_75 ( struct V_32 * V_33 )
{
int V_128 ;
if ( V_33 -> V_127 == V_196 )
return - V_142 ;
V_33 -> V_56 . V_57 = F_28 ( V_33 ) ;
F_76 ( V_33 , V_33 -> V_148 ) ;
V_128 = F_77 ( V_33 ) ;
if ( V_128 )
return V_128 ;
F_78 ( V_33 -> V_39 , V_197 ) ;
return 0 ;
}
static void F_79 ( void * V_198 , T_2 V_199 )
{
struct V_32 * V_33 = V_198 ;
struct V_45 * V_46 = V_33 -> V_56 . V_46 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
F_35 ( V_157 , V_33 , L_12 ) ;
F_80 ( V_40 -> V_77 . V_78 , V_46 ) ;
F_81 ( V_33 ) ;
}
void F_82 ( struct V_75 * V_78 )
{
struct V_37 * V_38 = F_83 ( V_78 ) ;
F_84 ( V_200 ) ;
int V_80 ;
F_85 ( V_38 ) ;
F_86 ( & V_38 -> V_201 ) ;
for ( V_80 = 0 ; V_80 < V_38 -> V_202 ; V_80 ++ ) {
struct V_186 * V_39 = V_38 -> V_203 [ V_80 ] ;
struct V_32 * V_33 ;
F_20 ( & V_39 -> V_204 ) ;
F_61 (dev, &port->dev_list, dev_list_node) {
if ( ! F_62 ( V_33 ) )
continue;
F_87 ( & V_33 -> V_205 ) ;
F_88 ( F_79 , V_33 , & V_200 ) ;
}
F_15 ( & V_39 -> V_204 ) ;
}
F_89 ( & V_38 -> V_201 ) ;
F_90 ( & V_200 ) ;
F_91 ( V_38 ) ;
}
void F_92 ( struct V_75 * V_78 , struct V_206 * V_207 ,
struct V_206 * V_208 )
{
struct V_209 * V_210 , * V_187 ;
struct V_32 * V_211 ;
do {
F_93 ( V_212 ) ;
V_211 = NULL ;
F_65 (cmd, n, work_q, eh_entry) {
struct V_32 * V_145 = F_94 ( V_210 ) ;
if ( ! F_62 ( V_145 ) || F_95 ( V_210 ) )
continue;
if ( V_211 && V_211 != V_145 )
continue;
V_211 = V_145 ;
F_96 ( & V_210 -> V_213 , & V_212 ) ;
}
if ( ! F_97 ( & V_212 ) ) {
struct V_45 * V_46 = V_211 -> V_56 . V_46 ;
F_35 ( V_157 , V_211 , L_13 ) ;
F_98 ( V_78 , V_46 , & V_212 ) ;
while ( ! F_97 ( & V_212 ) )
F_99 ( V_212 . V_214 ) ;
}
} while ( V_211 );
}
void F_100 ( struct V_32 * V_33 )
{
struct V_215 * V_216 ;
struct V_45 * V_46 ;
unsigned long V_42 ;
if ( ! F_62 ( V_33 ) )
return;
V_46 = V_33 -> V_56 . V_46 ;
V_216 = & V_46 -> V_44 . V_64 ;
F_4 ( V_46 -> V_52 , V_42 ) ;
V_216 -> V_63 |= V_9 ;
V_216 -> V_217 |= V_218 ;
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
