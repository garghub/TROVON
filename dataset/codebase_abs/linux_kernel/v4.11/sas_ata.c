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
V_73 += F_20 ( V_69 ) ;
V_28 -> V_103 = V_73 ;
V_28 -> V_105 = V_72 ;
}
V_28 -> V_107 = V_30 -> V_108 ;
V_28 -> V_109 = V_30 -> V_69 ;
V_28 -> V_98 . V_110 = 1 ;
V_28 -> V_111 = V_112 ;
V_30 -> V_67 = V_28 ;
V_28 -> V_98 . V_113 = F_21 ( V_30 -> V_88 . V_99 ) ;
V_28 -> V_98 . V_114 = F_22 ( V_30 -> V_88 . V_99 ) ;
if ( V_30 -> V_50 )
F_6 ( V_30 -> V_50 , V_28 ) ;
V_70 = V_80 -> V_115 -> V_116 ( V_28 , V_84 ) ;
if ( V_70 ) {
F_2 ( L_3 , V_70 ) ;
if ( V_30 -> V_50 )
F_6 ( V_30 -> V_50 , NULL ) ;
F_11 ( V_28 ) ;
V_30 -> V_67 = NULL ;
V_70 = V_71 ;
}
V_83:
F_23 ( V_46 -> V_52 ) ;
F_24 ( V_42 ) ;
return V_70 ;
}
static bool F_25 ( struct V_29 * V_30 )
{
struct V_32 * V_33 = V_30 -> V_46 -> V_74 ;
F_26 ( V_33 -> V_56 . V_59 , & V_30 -> V_117 ) ;
return true ;
}
static struct V_79 * F_27 ( struct V_32 * V_33 )
{
return F_13 ( V_33 -> V_39 -> V_40 -> V_77 . V_78 -> V_81 ) ;
}
int F_28 ( struct V_32 * V_33 , struct V_118 * V_119 )
{
if ( V_119 -> V_120 & V_86 )
V_33 -> V_121 = V_119 -> V_120 ;
if ( V_119 -> V_122 )
V_33 -> V_121 |= V_123 ;
if ( V_119 -> V_124 == V_125 )
V_33 -> V_126 = V_125 ;
else {
int V_127 ;
V_33 -> V_126 = V_123 ;
V_127 = F_29 ( V_33 -> V_128 , V_119 -> V_129 ,
& V_33 -> V_56 . V_130 ) ;
if ( V_127 ) {
F_2 ( L_4
L_5 , F_30 ( V_33 -> V_128 -> V_131 ) ,
V_119 -> V_129 , V_127 ) ;
return V_127 ;
}
memcpy ( V_33 -> V_132 , & V_33 -> V_56 . V_130 . V_133 . V_59 ,
sizeof( struct V_134 ) ) ;
V_33 -> V_56 . V_57 = F_31 ( V_33 ) ;
}
return 0 ;
}
static int F_32 ( struct V_32 * V_33 , struct V_118 * V_119 )
{
int V_127 ;
if ( V_33 -> V_126 != V_125 )
return 1 ;
V_127 = F_28 ( V_33 , V_119 ) ;
if ( V_127 )
return 0 ;
else
return 1 ;
}
static int F_33 ( struct V_43 * V_44 )
{
int V_127 ;
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_32 * V_135 = V_33 -> V_128 ;
struct V_136 * V_119 = F_34 ( V_33 ) ;
struct V_118 * V_118 = & V_135 -> V_135 . V_118 [ V_119 -> V_137 ] ;
V_127 = F_35 ( V_135 , V_119 -> V_137 ) ;
F_36 ( V_119 ) ;
if ( V_127 == - V_138 )
return V_127 ;
if ( V_127 != V_139 )
return 0 ;
switch ( V_118 -> V_124 ) {
case V_125 :
return 0 ;
case V_140 :
if ( V_118 -> V_122 )
return F_32 ( V_33 , V_118 ) ;
default:
return - V_141 ;
}
}
static int F_37 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_79 * V_80 = F_27 ( V_33 ) ;
if ( V_80 -> V_115 -> V_142 )
return V_80 -> V_115 -> V_142 ( V_33 ) ;
else {
return 1 ;
}
}
static int F_38 ( const char * V_143 , const struct V_32 * V_144 ,
const char * V_145 , ... )
{
struct V_45 * V_46 = V_144 -> V_56 . V_46 ;
struct V_146 * V_33 = & V_144 -> V_147 -> V_33 ;
struct V_148 V_149 ;
T_1 args ;
int V_150 ;
va_start ( args , V_145 ) ;
V_149 . V_145 = V_145 ;
V_149 . V_151 = & args ;
V_150 = F_39 ( L_6 ,
V_143 , V_46 -> V_152 , F_40 ( V_33 ) , & V_149 ) ;
va_end ( args ) ;
return V_150 ;
}
static int F_41 ( struct V_43 * V_44 , unsigned int * V_57 ,
unsigned long V_153 )
{
int V_70 = 0 , V_127 ;
struct V_136 * V_119 ;
struct V_45 * V_46 = V_44 -> V_46 ;
int (* F_42)( struct V_43 * V_44 );
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_79 * V_80 = F_27 ( V_33 ) ;
V_127 = V_80 -> V_115 -> V_154 ( V_33 ) ;
if ( V_127 == - V_141 )
return V_127 ;
if ( V_127 != V_155 )
F_38 ( V_156 , V_33 , L_7 ) ;
V_119 = F_34 ( V_33 ) ;
if ( F_43 ( V_119 ) )
F_42 = F_37 ;
else
F_42 = F_33 ;
F_36 ( V_119 ) ;
V_70 = F_44 ( V_44 , V_153 , F_42 ) ;
if ( V_70 && V_70 != - V_157 )
F_38 ( V_158 , V_33 , L_8 , V_70 ) ;
* V_57 = V_33 -> V_56 . V_57 ;
V_46 -> V_159 = V_160 ;
return V_70 ;
}
static void F_45 ( struct V_27 * V_28 )
{
struct V_79 * V_72 = F_27 ( V_28 -> V_33 ) ;
unsigned long V_42 ;
int V_127 ;
F_4 ( & V_28 -> V_161 , V_42 ) ;
if ( V_28 -> V_111 & V_162 ||
V_28 -> V_111 & V_163 ) {
F_7 ( & V_28 -> V_161 , V_42 ) ;
F_2 ( L_9 , V_21 ,
V_28 ) ;
goto V_83;
}
V_28 -> V_111 |= V_162 ;
F_7 ( & V_28 -> V_161 , V_42 ) ;
V_127 = V_72 -> V_115 -> V_164 ( V_28 ) ;
F_4 ( & V_28 -> V_161 , V_42 ) ;
if ( V_28 -> V_111 & V_163 ||
V_127 == V_155 ) {
F_7 ( & V_28 -> V_161 , V_42 ) ;
goto V_83;
}
F_2 ( L_10 , V_21 , V_28 ) ;
if ( ! ( V_28 -> V_111 & V_163 ) )
V_28 -> V_111 &= ~ V_162 ;
F_7 ( & V_28 -> V_161 , V_42 ) ;
return;
V_83:
F_11 ( V_28 ) ;
}
static void F_46 ( struct V_29 * V_30 )
{
if ( V_30 -> V_42 & V_65 )
V_30 -> V_63 |= V_22 ;
if ( V_30 -> V_63 ) {
struct V_27 * V_28 = V_30 -> V_67 ;
V_30 -> V_67 = NULL ;
if ( ! V_28 )
return;
V_28 -> V_31 = NULL ;
F_45 ( V_28 ) ;
}
}
static void F_47 ( struct V_45 * V_46 , struct V_165 * V_166 )
{
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_79 * V_80 = F_27 ( V_33 ) ;
if ( V_80 -> V_115 -> V_167 )
V_80 -> V_115 -> V_167 ( V_33 ) ;
}
static void F_48 ( struct V_45 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
unsigned long V_42 ;
F_4 ( & V_40 -> V_52 , V_42 ) ;
if ( ! F_49 ( V_168 , & V_33 -> V_49 ) )
V_40 -> V_169 ++ ;
F_50 ( V_46 ) ;
F_7 ( & V_40 -> V_52 , V_42 ) ;
}
void F_51 ( struct V_45 * V_46 )
{
struct V_32 * V_33 = V_46 -> V_74 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
unsigned long V_42 ;
F_4 ( & V_40 -> V_52 , V_42 ) ;
if ( F_52 ( V_168 , & V_33 -> V_49 ) )
V_40 -> V_169 -- ;
F_7 ( & V_40 -> V_52 , V_42 ) ;
}
int F_53 ( struct V_32 * V_170 )
{
struct V_37 * V_40 = V_170 -> V_39 -> V_40 ;
struct V_75 * V_78 = V_40 -> V_77 . V_78 ;
struct V_45 * V_46 ;
int V_171 ;
F_54 ( & V_170 -> V_56 . V_172 , V_40 -> V_33 , & V_173 ) ;
V_46 = F_55 ( & V_170 -> V_56 . V_172 ,
& V_174 ,
V_78 ) ;
if ( ! V_46 ) {
F_2 ( L_11 ) ;
return - V_141 ;
}
V_46 -> V_74 = V_170 ;
V_46 -> V_159 = V_160 ;
V_46 -> V_175 = V_78 ;
V_171 = F_56 ( V_46 ) ;
if ( V_171 ) {
F_57 ( V_46 ) ;
return V_171 ;
}
V_170 -> V_56 . V_46 = V_46 ;
return 0 ;
}
void F_58 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_176 * V_177 ;
if ( V_30 -> V_50 ) {
struct V_178 * V_179 = V_30 -> V_50 -> V_146 -> V_178 ;
unsigned long V_42 ;
F_4 ( V_179 -> V_180 , V_42 ) ;
F_59 ( V_30 -> V_50 -> V_181 ) ;
F_7 ( V_179 -> V_180 , V_42 ) ;
return;
}
V_30 -> V_42 &= ~ V_182 ;
V_30 -> V_42 |= V_65 ;
V_30 -> V_63 |= V_9 ;
V_177 = V_30 -> V_74 ;
F_60 ( V_177 ) ;
}
static int F_31 ( struct V_32 * V_33 )
{
struct V_134 * V_59 =
(struct V_134 * ) V_33 -> V_132 ;
struct V_183 V_88 ;
if ( V_33 -> V_126 == V_125 )
return V_184 ;
F_26 ( ( const V_97 * ) V_59 , & V_88 ) ;
return F_61 ( & V_88 ) ;
}
void F_62 ( struct V_185 * V_39 )
{
struct V_32 * V_33 , * V_186 ;
F_63 ( & V_39 -> V_40 -> V_187 ) ;
F_64 (dev, &port->disco_list, disco_list_node) {
if ( ! F_65 ( V_33 ) )
continue;
F_66 ( V_33 -> V_56 . V_46 ) ;
}
F_67 ( & V_39 -> V_40 -> V_187 ) ;
F_68 (dev, n, &port->disco_list, disco_list_node) {
if ( ! F_65 ( V_33 ) )
continue;
F_69 ( V_33 ) ;
if ( F_70 ( F_71 ( V_33 ) ) )
F_72 ( V_33 , V_21 , - V_141 ) ;
}
}
static void F_73 ( struct V_185 * V_39 , const char * V_188 )
{
struct V_32 * V_33 , * V_186 ;
F_68 (dev, n, &port->dev_list, dev_list_node) {
if ( ! F_65 ( V_33 ) )
continue;
F_69 ( V_33 ) ;
if ( F_70 ( F_71 ( V_33 ) ) )
F_72 ( V_33 , V_188 , - V_141 ) ;
}
}
void F_74 ( struct V_185 * V_39 )
{
struct V_32 * V_33 ;
F_63 ( & V_39 -> V_40 -> V_187 ) ;
F_64 (dev, &port->dev_list, dev_list_node) {
struct V_189 * V_190 ;
if ( ! F_65 ( V_33 ) )
continue;
V_190 = & V_33 -> V_56 ;
if ( V_190 -> V_46 -> V_191 . V_192 == V_193 )
continue;
F_75 ( V_190 -> V_46 ) ;
}
F_67 ( & V_39 -> V_40 -> V_187 ) ;
F_73 ( V_39 , V_21 ) ;
}
void F_76 ( struct V_185 * V_39 )
{
struct V_32 * V_33 ;
F_63 ( & V_39 -> V_40 -> V_187 ) ;
F_64 (dev, &port->dev_list, dev_list_node) {
struct V_189 * V_190 ;
if ( ! F_65 ( V_33 ) )
continue;
V_190 = & V_33 -> V_56 ;
if ( V_190 -> V_46 -> V_191 . V_192 == V_194 )
continue;
F_77 ( V_190 -> V_46 ) ;
}
F_67 ( & V_39 -> V_40 -> V_187 ) ;
F_73 ( V_39 , V_21 ) ;
}
int F_78 ( struct V_32 * V_33 )
{
int V_127 ;
if ( V_33 -> V_126 == V_195 )
return - V_141 ;
V_33 -> V_56 . V_57 = F_31 ( V_33 ) ;
F_79 ( V_33 , V_33 -> V_147 ) ;
V_127 = F_80 ( V_33 ) ;
if ( V_127 )
return V_127 ;
F_81 ( V_33 -> V_39 , V_196 ) ;
return 0 ;
}
static void F_82 ( void * V_197 , T_2 V_198 )
{
struct V_32 * V_33 = V_197 ;
struct V_45 * V_46 = V_33 -> V_56 . V_46 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
F_38 ( V_156 , V_33 , L_12 ) ;
F_83 ( V_40 -> V_77 . V_78 , V_46 ) ;
F_84 ( V_33 ) ;
}
void F_85 ( struct V_75 * V_78 )
{
struct V_37 * V_38 = F_86 ( V_78 ) ;
F_87 ( V_199 ) ;
int V_80 ;
F_88 ( V_38 ) ;
F_89 ( & V_38 -> V_200 ) ;
for ( V_80 = 0 ; V_80 < V_38 -> V_201 ; V_80 ++ ) {
struct V_185 * V_39 = V_38 -> V_202 [ V_80 ] ;
struct V_32 * V_33 ;
F_23 ( & V_39 -> V_203 ) ;
F_64 (dev, &port->dev_list, dev_list_node) {
if ( ! F_65 ( V_33 ) )
continue;
F_90 ( & V_33 -> V_204 ) ;
F_91 ( F_82 , V_33 , & V_199 ) ;
}
F_15 ( & V_39 -> V_203 ) ;
}
F_92 ( & V_38 -> V_200 ) ;
F_93 ( & V_199 ) ;
F_94 ( V_38 ) ;
}
void F_95 ( struct V_75 * V_78 , struct V_205 * V_206 ,
struct V_205 * V_207 )
{
struct V_208 * V_209 , * V_186 ;
struct V_32 * V_210 ;
do {
F_96 ( V_211 ) ;
V_210 = NULL ;
F_68 (cmd, n, work_q, eh_entry) {
struct V_32 * V_144 = F_97 ( V_209 ) ;
if ( ! F_65 ( V_144 ) || F_98 ( V_209 ) )
continue;
if ( V_210 && V_210 != V_144 )
continue;
V_210 = V_144 ;
F_99 ( & V_209 -> V_212 , & V_211 ) ;
}
if ( ! F_100 ( & V_211 ) ) {
struct V_45 * V_46 = V_210 -> V_56 . V_46 ;
F_38 ( V_156 , V_210 , L_13 ) ;
F_101 ( V_78 , V_46 , & V_211 ) ;
while ( ! F_100 ( & V_211 ) )
F_102 ( V_211 . V_213 ) ;
}
} while ( V_210 );
}
void F_103 ( struct V_32 * V_33 )
{
struct V_214 * V_215 ;
struct V_45 * V_46 ;
unsigned long V_42 ;
if ( ! F_65 ( V_33 ) )
return;
V_46 = V_33 -> V_56 . V_46 ;
V_215 = & V_46 -> V_44 . V_64 ;
F_4 ( V_46 -> V_52 , V_42 ) ;
V_215 -> V_63 |= V_9 ;
V_215 -> V_216 |= V_217 ;
F_104 ( V_46 ) ;
F_7 ( V_46 -> V_52 , V_42 ) ;
}
void F_69 ( struct V_32 * V_33 )
{
struct V_45 * V_46 ;
if ( ! F_65 ( V_33 ) )
return;
V_46 = V_33 -> V_56 . V_46 ;
F_105 ( V_46 ) ;
}
