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
F_9 ( V_4 -> V_59 , & V_33 -> V_56 . V_60 ) ;
if ( ! V_44 -> V_61 ) {
V_30 -> V_62 |= F_10 ( V_33 -> V_56 . V_60 . V_63 ) ;
} else {
V_44 -> V_64 . V_62 |= F_10 ( V_33 -> V_56 . V_60 . V_63 ) ;
if ( F_8 ( V_44 -> V_64 . V_62 ) )
V_30 -> V_42 |= V_65 ;
}
} else {
V_41 = F_1 ( V_7 ) ;
if ( V_41 ) {
F_2 ( L_2 , V_21 ,
V_7 -> V_7 ) ;
if ( ! V_44 -> V_61 ) {
V_30 -> V_62 = V_41 ;
} else {
V_44 -> V_64 . V_62 |= V_25 ;
V_30 -> V_42 |= V_65 ;
}
V_33 -> V_56 . V_60 . V_66 = 0x04 ;
V_33 -> V_56 . V_60 . V_63 = V_67 ;
}
}
V_30 -> V_68 = NULL ;
F_11 ( V_30 ) ;
F_7 ( V_46 -> V_52 , V_42 ) ;
V_51:
F_12 ( & V_28 -> V_69 ) ;
F_13 ( V_28 ) ;
}
static unsigned int F_14 ( struct V_29 * V_30 )
{
unsigned long V_42 ;
struct V_27 * V_28 ;
struct V_70 * V_71 ;
int V_72 = V_73 ;
unsigned int V_74 , V_75 = 0 ;
struct V_45 * V_46 = V_30 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_76 ;
struct V_37 * V_38 = V_33 -> V_39 -> V_40 ;
struct V_77 * V_78 = V_38 -> V_79 . V_80 ;
struct V_81 * V_82 = F_15 ( V_78 -> V_83 ) ;
F_16 ( V_42 ) ;
F_17 ( V_46 -> V_52 ) ;
if ( F_5 ( V_84 , & V_33 -> V_49 ) )
goto V_85;
V_28 = F_18 ( V_86 ) ;
if ( ! V_28 )
goto V_85;
V_28 -> V_33 = V_33 ;
V_28 -> V_87 = V_88 ;
V_28 -> V_89 = F_3 ;
if ( V_30 -> V_60 . V_63 == V_90 ||
V_30 -> V_60 . V_63 == V_91 ) {
V_30 -> V_60 . V_92 = 0 ;
}
F_19 ( & V_30 -> V_60 , 1 , 0 , ( V_93 * ) & V_28 -> V_94 . V_95 ) ;
V_28 -> V_31 = V_30 ;
if ( F_20 ( V_30 -> V_60 . V_96 ) ) {
memcpy ( V_28 -> V_94 . V_97 , V_30 -> V_98 , V_30 -> V_33 -> V_99 ) ;
V_28 -> V_100 = V_30 -> V_101 ;
V_28 -> V_102 = V_30 -> V_103 ;
} else {
F_21 (qc->sg, sg, qc->n_elem, si)
V_75 += V_71 -> V_104 ;
V_28 -> V_100 = V_75 ;
V_28 -> V_102 = V_74 ;
}
V_28 -> V_105 = V_30 -> V_106 ;
V_28 -> V_107 = V_30 -> V_71 ;
V_28 -> V_94 . V_108 = 1 ;
V_28 -> V_109 = V_110 ;
V_30 -> V_68 = V_28 ;
switch ( V_30 -> V_60 . V_96 ) {
case V_111 :
V_28 -> V_94 . V_112 = 1 ;
case V_113 :
case V_114 :
V_28 -> V_94 . V_115 = 1 ;
break;
}
if ( V_30 -> V_50 )
F_6 ( V_30 -> V_50 , V_28 ) ;
if ( V_38 -> V_116 < 2 )
V_72 = V_82 -> V_117 -> V_118 ( V_28 , 1 , V_86 ) ;
else
V_72 = F_22 ( V_28 ) ;
if ( V_72 ) {
F_2 ( L_3 , V_72 ) ;
if ( V_30 -> V_50 )
F_6 ( V_30 -> V_50 , NULL ) ;
F_13 ( V_28 ) ;
V_72 = V_73 ;
}
V_85:
F_23 ( V_46 -> V_52 ) ;
F_24 ( V_42 ) ;
return V_72 ;
}
static bool F_25 ( struct V_29 * V_30 )
{
struct V_32 * V_33 = V_30 -> V_46 -> V_76 ;
memcpy ( & V_30 -> V_119 , & V_33 -> V_56 . V_60 , sizeof( V_30 -> V_119 ) ) ;
return true ;
}
static struct V_81 * F_26 ( struct V_32 * V_33 )
{
return F_15 ( V_33 -> V_39 -> V_40 -> V_79 . V_80 -> V_83 ) ;
}
int F_27 ( struct V_32 * V_33 , struct V_120 * V_121 )
{
if ( V_121 -> V_122 & V_88 )
V_33 -> V_123 = V_121 -> V_122 ;
if ( V_121 -> V_124 )
V_33 -> V_123 |= V_125 ;
if ( V_121 -> V_126 == V_127 )
V_33 -> V_128 = V_127 ;
else {
int V_129 ;
V_33 -> V_128 = V_125 ;
V_129 = F_28 ( V_33 -> V_130 , V_121 -> V_131 ,
& V_33 -> V_56 . V_132 ) ;
if ( V_129 ) {
F_2 ( L_4
L_5 , F_29 ( V_33 -> V_130 -> V_133 ) ,
V_121 -> V_131 , V_129 ) ;
return V_129 ;
}
memcpy ( V_33 -> V_134 , & V_33 -> V_56 . V_132 . V_135 . V_95 ,
sizeof( struct V_136 ) ) ;
F_30 ( V_33 ) ;
}
return 0 ;
}
static int F_31 ( struct V_32 * V_33 , struct V_120 * V_121 )
{
int V_129 ;
if ( V_33 -> V_128 != V_127 )
return 1 ;
V_129 = F_27 ( V_33 , V_121 ) ;
if ( V_129 )
return 0 ;
else
return 1 ;
}
static int F_32 ( struct V_43 * V_44 )
{
int V_129 ;
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_76 ;
struct V_32 * V_137 = V_33 -> V_130 ;
struct V_138 * V_121 = F_33 ( V_33 ) ;
struct V_120 * V_120 = & V_137 -> V_137 . V_120 [ V_121 -> V_139 ] ;
V_129 = F_34 ( V_137 , V_121 -> V_139 ) ;
F_35 ( V_121 ) ;
if ( V_129 == - V_140 )
return V_129 ;
if ( V_129 != V_141 )
return 0 ;
switch ( V_120 -> V_126 ) {
case V_127 :
return 0 ;
case V_142 :
if ( V_120 -> V_124 )
return F_31 ( V_33 , V_120 ) ;
default:
return - V_143 ;
}
}
static int F_36 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_46 ;
struct V_32 * V_33 = V_46 -> V_76 ;
struct V_81 * V_82 = F_26 ( V_33 ) ;
if ( V_82 -> V_117 -> V_144 )
return V_82 -> V_117 -> V_144 ( V_33 ) ;
else {
return 1 ;
}
}
static int F_37 ( const char * V_145 , const struct V_32 * V_146 ,
const char * V_147 , ... )
{
struct V_45 * V_46 = V_146 -> V_56 . V_46 ;
struct V_148 * V_33 = & V_146 -> V_149 -> V_33 ;
struct V_150 V_151 ;
T_1 args ;
int V_152 ;
va_start ( args , V_147 ) ;
V_151 . V_147 = V_147 ;
V_151 . V_153 = & args ;
V_152 = F_38 ( L_6 ,
V_145 , V_46 -> V_154 , F_39 ( V_33 ) , & V_151 ) ;
va_end ( args ) ;
return V_152 ;
}
static int F_40 ( struct V_43 * V_44 , unsigned int * V_155 ,
unsigned long V_156 )
{
int V_72 = 0 , V_129 ;
struct V_138 * V_121 ;
struct V_45 * V_46 = V_44 -> V_46 ;
int (* F_41)( struct V_43 * V_44 );
struct V_32 * V_33 = V_46 -> V_76 ;
struct V_81 * V_82 = F_26 ( V_33 ) ;
V_129 = V_82 -> V_117 -> V_157 ( V_33 ) ;
if ( V_129 == - V_143 )
return V_129 ;
if ( V_129 != V_158 )
F_37 ( V_159 , V_33 , L_7 ) ;
V_121 = F_33 ( V_33 ) ;
if ( F_42 ( V_121 ) )
F_41 = F_36 ;
else
F_41 = F_32 ;
F_35 ( V_121 ) ;
V_72 = F_43 ( V_44 , V_156 , F_41 ) ;
if ( V_72 && V_72 != - V_160 )
F_37 ( V_161 , V_33 , L_8 , V_72 ) ;
switch ( V_33 -> V_56 . V_57 ) {
case V_162 :
* V_155 = V_163 ;
break;
case V_58 :
* V_155 = V_164 ;
break;
}
V_46 -> V_165 = V_166 ;
return V_72 ;
}
static void F_44 ( struct V_27 * V_28 )
{
struct V_81 * V_74 = F_26 ( V_28 -> V_33 ) ;
unsigned long V_42 ;
int V_129 ;
F_4 ( & V_28 -> V_167 , V_42 ) ;
if ( V_28 -> V_109 & V_168 ||
V_28 -> V_109 & V_169 ) {
F_7 ( & V_28 -> V_167 , V_42 ) ;
F_2 ( L_9 , V_21 ,
V_28 ) ;
goto V_85;
}
V_28 -> V_109 |= V_168 ;
F_7 ( & V_28 -> V_167 , V_42 ) ;
V_129 = V_74 -> V_117 -> V_170 ( V_28 ) ;
F_4 ( & V_28 -> V_167 , V_42 ) ;
if ( V_28 -> V_109 & V_169 ||
V_129 == V_158 ) {
F_7 ( & V_28 -> V_167 , V_42 ) ;
goto V_85;
}
F_2 ( L_10 , V_21 , V_28 ) ;
if ( ! ( V_28 -> V_109 & V_169 ) )
V_28 -> V_109 &= ~ V_168 ;
F_7 ( & V_28 -> V_167 , V_42 ) ;
return;
V_85:
F_12 ( & V_28 -> V_69 ) ;
F_13 ( V_28 ) ;
}
static void F_45 ( struct V_29 * V_30 )
{
if ( V_30 -> V_42 & V_65 )
V_30 -> V_62 |= V_22 ;
if ( V_30 -> V_62 ) {
struct V_27 * V_28 = V_30 -> V_68 ;
V_30 -> V_68 = NULL ;
if ( ! V_28 )
return;
V_28 -> V_31 = NULL ;
F_44 ( V_28 ) ;
}
}
static void F_46 ( struct V_45 * V_46 , struct V_171 * V_172 )
{
struct V_32 * V_33 = V_46 -> V_76 ;
struct V_81 * V_82 = F_26 ( V_33 ) ;
if ( V_82 -> V_117 -> V_173 )
V_82 -> V_117 -> V_173 ( V_33 ) ;
}
int F_47 ( struct V_32 * V_174 )
{
struct V_37 * V_40 = V_174 -> V_39 -> V_40 ;
struct V_77 * V_80 = V_40 -> V_79 . V_80 ;
struct V_45 * V_46 ;
int V_175 ;
F_48 ( & V_174 -> V_56 . V_176 ,
V_40 -> V_33 ,
V_177 . V_42 ,
& V_178 ) ;
V_46 = F_49 ( & V_174 -> V_56 . V_176 ,
& V_177 ,
V_80 ) ;
if ( ! V_46 ) {
F_2 ( L_11 ) ;
return - V_143 ;
}
V_46 -> V_76 = V_174 ;
V_46 -> V_165 = V_166 ;
V_46 -> V_179 = V_80 ;
V_175 = F_50 ( V_46 ) ;
if ( V_175 ) {
F_51 ( V_46 ) ;
return V_175 ;
}
V_174 -> V_56 . V_46 = V_46 ;
return 0 ;
}
void F_52 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_180 * V_181 ;
if ( V_30 -> V_50 ) {
struct V_182 * V_183 = V_30 -> V_50 -> V_148 -> V_182 ;
unsigned long V_42 ;
F_4 ( V_183 -> V_184 , V_42 ) ;
F_53 ( V_30 -> V_50 -> V_185 ) ;
F_7 ( V_183 -> V_184 , V_42 ) ;
F_54 ( V_30 -> V_50 -> V_148 -> V_78 ) ;
return;
}
V_30 -> V_42 &= ~ V_186 ;
V_30 -> V_42 |= V_65 ;
V_30 -> V_62 |= V_9 ;
V_181 = V_30 -> V_76 ;
F_55 ( V_181 ) ;
}
static void F_30 ( struct V_32 * V_33 )
{
struct V_136 * V_95 =
(struct V_136 * ) V_33 -> V_134 ;
if ( V_33 -> V_128 == V_127 )
return;
if ( ( V_95 -> V_187 == 1 &&
V_95 -> V_188 == 1 &&
V_95 -> V_189 == 0 &&
V_95 -> V_190 == 0 &&
V_95 -> V_148 == 0 )
||
( V_95 -> V_187 == 0 &&
V_95 -> V_188 == 0 &&
V_95 -> V_189 == 0xCE &&
V_95 -> V_190 == 0xAA &&
( V_95 -> V_148 & ~ 0x10 ) == 0 ) )
V_33 -> V_56 . V_57 = V_162 ;
else if ( ( V_95 -> V_191 == 1 &&
V_95 -> V_188 == 1 &&
V_95 -> V_192 == 0x14 &&
V_95 -> V_193 == 0xEB &&
( V_95 -> V_148 & ~ 0x10 ) == 0 ) )
V_33 -> V_56 . V_57 = V_58 ;
else if ( ( V_95 -> V_187 == 1 &&
V_95 -> V_188 == 1 &&
V_95 -> V_189 == 0x3C &&
V_95 -> V_190 == 0xC3 &&
V_95 -> V_148 == 0 )
||
( V_95 -> V_191 == 1 &&
V_95 -> V_188 == 1 &&
V_95 -> V_192 == 0x69 &&
V_95 -> V_193 == 0x96 &&
( V_95 -> V_148 & ~ 0x10 ) == 0 ) )
V_33 -> V_56 . V_57 = V_58 ;
}
void F_56 ( struct V_194 * V_39 )
{
struct V_32 * V_33 , * V_195 ;
F_57 ( & V_39 -> V_40 -> V_196 ) ;
F_58 (dev, &port->disco_list, disco_list_node) {
if ( ! F_59 ( V_33 ) )
continue;
F_60 ( V_33 -> V_56 . V_46 ) ;
}
F_61 ( & V_39 -> V_40 -> V_196 ) ;
F_62 (dev, n, &port->disco_list, disco_list_node) {
if ( ! F_59 ( V_33 ) )
continue;
F_63 ( V_33 ) ;
if ( F_64 ( F_65 ( V_33 ) ) )
F_66 ( V_33 , V_21 , - V_143 ) ;
}
}
int F_67 ( struct V_32 * V_33 )
{
int V_129 ;
if ( V_33 -> V_128 == V_197 )
return - V_143 ;
F_30 ( V_33 ) ;
F_68 ( V_33 , V_33 -> V_149 ) ;
V_129 = F_69 ( V_33 ) ;
if ( V_129 )
return V_129 ;
F_70 ( V_33 -> V_39 , V_198 ) ;
return 0 ;
}
static void F_71 ( void * V_199 , T_2 V_200 )
{
struct V_32 * V_33 = V_199 ;
struct V_45 * V_46 = V_33 -> V_56 . V_46 ;
struct V_37 * V_40 = V_33 -> V_39 -> V_40 ;
F_72 ( & V_33 -> V_201 ) ;
F_37 ( V_159 , V_33 , L_12 ) ;
F_73 ( V_40 -> V_79 . V_80 , V_46 ) ;
F_74 ( V_33 ) ;
}
void F_75 ( struct V_77 * V_80 )
{
struct V_37 * V_38 = F_76 ( V_80 ) ;
F_77 ( V_202 ) ;
int V_82 ;
F_78 ( V_38 ) ;
F_79 ( & V_38 -> V_203 ) ;
for ( V_82 = 0 ; V_82 < V_38 -> V_204 ; V_82 ++ ) {
struct V_194 * V_39 = V_38 -> V_205 [ V_82 ] ;
struct V_32 * V_33 ;
F_23 ( & V_39 -> V_206 ) ;
F_58 (dev, &port->dev_list, dev_list_node) {
if ( ! F_59 ( V_33 ) )
continue;
F_80 ( F_71 , V_33 , & V_202 ) ;
}
F_17 ( & V_39 -> V_206 ) ;
}
F_81 ( & V_38 -> V_203 ) ;
F_82 ( & V_202 ) ;
F_83 ( V_38 ) ;
}
void F_84 ( struct V_77 * V_80 , struct V_207 * V_208 ,
struct V_207 * V_209 )
{
struct V_210 * V_211 , * V_195 ;
struct V_32 * V_212 ;
do {
F_77 ( V_213 ) ;
V_212 = NULL ;
F_62 (cmd, n, work_q, eh_entry) {
struct V_32 * V_146 = F_85 ( V_211 ) ;
if ( ! F_59 ( V_146 ) || F_86 ( V_211 ) )
continue;
if ( V_212 && V_212 != V_146 )
continue;
V_212 = V_146 ;
F_87 ( & V_211 -> V_214 , & V_213 ) ;
}
if ( ! F_88 ( & V_213 ) ) {
struct V_45 * V_46 = V_212 -> V_56 . V_46 ;
F_37 ( V_159 , V_212 , L_13 ) ;
F_89 ( V_80 , V_46 , & V_213 ) ;
while ( ! F_88 ( & V_213 ) )
F_12 ( V_213 . V_215 ) ;
}
} while ( V_212 );
}
void F_90 ( struct V_32 * V_33 )
{
struct V_216 * V_217 ;
struct V_45 * V_46 ;
unsigned long V_42 ;
if ( ! F_59 ( V_33 ) )
return;
V_46 = V_33 -> V_56 . V_46 ;
V_217 = & V_46 -> V_44 . V_64 ;
F_4 ( V_46 -> V_52 , V_42 ) ;
V_217 -> V_62 |= V_9 ;
V_217 -> V_218 |= V_219 ;
F_91 ( V_46 ) ;
F_7 ( V_46 -> V_52 , V_42 ) ;
}
void F_63 ( struct V_32 * V_33 )
{
struct V_45 * V_46 ;
if ( ! F_59 ( V_33 ) )
return;
V_46 = V_33 -> V_56 . V_46 ;
F_92 ( V_46 ) ;
}
