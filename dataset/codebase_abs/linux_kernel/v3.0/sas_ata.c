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
struct V_32 * V_33 ;
struct V_2 * V_7 = & V_28 -> V_34 ;
struct V_35 * V_4 = (struct V_35 * ) V_7 -> V_36 ;
struct V_37 * V_38 ;
enum V_1 V_39 ;
unsigned long V_40 ;
struct V_41 * V_42 ;
if ( ! V_30 )
goto V_43;
V_33 = V_30 -> V_44 -> V_45 ;
V_38 = V_33 -> V_46 -> V_47 ;
V_42 = & V_33 -> V_48 . V_44 -> V_42 ;
F_4 ( V_33 -> V_48 . V_44 -> V_49 , V_40 ) ;
if ( V_7 -> V_7 == V_26 || V_7 -> V_7 == V_50 ||
( ( V_7 -> V_7 == V_23 &&
V_33 -> V_48 . V_51 == V_52 ) ) ) {
F_5 ( V_4 -> V_53 , & V_33 -> V_48 . V_54 ) ;
if ( ! V_42 -> V_55 ) {
V_30 -> V_56 |= F_6 ( V_33 -> V_48 . V_54 . V_57 ) ;
} else {
V_42 -> V_58 . V_56 |= F_6 ( V_33 -> V_48 . V_54 . V_57 ) ;
if ( F_7 ( V_42 -> V_58 . V_56 ) )
V_30 -> V_40 |= V_59 ;
}
V_33 -> V_48 . V_60 = V_4 -> V_60 ;
V_33 -> V_48 . V_61 = V_4 -> V_61 ;
V_33 -> V_48 . V_62 = V_4 -> V_62 ;
} else {
V_39 = F_1 ( V_7 ) ;
if ( V_39 ) {
F_2 ( L_2 , V_21 ,
V_7 -> V_7 ) ;
if ( ! V_42 -> V_55 ) {
V_30 -> V_56 = V_39 ;
} else {
V_42 -> V_58 . V_56 |= V_25 ;
V_30 -> V_40 |= V_59 ;
}
V_33 -> V_48 . V_54 . V_63 = 0x04 ;
V_33 -> V_48 . V_54 . V_57 = V_64 ;
}
}
V_30 -> V_65 = NULL ;
if ( V_30 -> V_66 )
F_8 ( V_30 -> V_66 , NULL ) ;
F_9 ( V_30 ) ;
F_10 ( V_33 -> V_48 . V_44 -> V_49 , V_40 ) ;
F_4 ( & V_28 -> V_67 , V_40 ) ;
if ( V_30 -> V_66 && V_28 -> V_68 & V_69 )
F_11 ( V_30 -> V_66 , & V_38 -> V_70 ) ;
F_10 ( & V_28 -> V_67 , V_40 ) ;
V_43:
F_12 ( & V_28 -> V_71 ) ;
F_13 ( V_28 ) ;
}
static unsigned int F_14 ( struct V_29 * V_30 )
{
int V_72 ;
struct V_27 * V_28 ;
struct V_32 * V_33 = V_30 -> V_44 -> V_45 ;
struct V_37 * V_38 = V_33 -> V_46 -> V_47 ;
struct V_73 * V_74 = V_38 -> V_75 . V_76 ;
struct V_77 * V_78 = F_15 ( V_74 -> V_79 ) ;
struct V_80 * V_81 ;
unsigned int V_82 = 0 ;
unsigned int V_83 ;
if ( V_33 -> V_84 )
return V_85 ;
V_28 = F_16 ( V_86 ) ;
if ( ! V_28 )
return V_85 ;
V_28 -> V_33 = V_33 ;
V_28 -> V_87 = V_88 ;
V_28 -> V_89 = F_3 ;
if ( V_30 -> V_54 . V_57 == V_90 ||
V_30 -> V_54 . V_57 == V_91 ) {
V_30 -> V_54 . V_92 = 0 ;
}
F_17 ( & V_30 -> V_54 , 1 , 0 , ( V_93 * ) & V_28 -> V_94 . V_95 ) ;
V_28 -> V_31 = V_30 ;
if ( F_18 ( V_30 -> V_54 . V_96 ) ) {
memcpy ( V_28 -> V_94 . V_97 , V_30 -> V_98 , V_30 -> V_33 -> V_99 ) ;
V_28 -> V_100 = V_30 -> V_101 ;
V_28 -> V_102 = V_30 -> V_103 ;
} else {
F_19 (qc->sg, sg, qc->n_elem, si)
V_82 += V_81 -> V_104 ;
V_28 -> V_100 = V_82 ;
V_28 -> V_102 = V_83 ;
}
V_28 -> V_105 = V_30 -> V_106 ;
V_28 -> V_107 = V_30 -> V_81 ;
V_28 -> V_94 . V_108 = 1 ;
V_28 -> V_68 = V_109 ;
V_30 -> V_65 = V_28 ;
switch ( V_30 -> V_54 . V_96 ) {
case V_110 :
V_28 -> V_94 . V_111 = 1 ;
case V_112 :
case V_113 :
V_28 -> V_94 . V_114 = 1 ;
break;
}
if ( V_30 -> V_66 )
F_8 ( V_30 -> V_66 , V_28 ) ;
if ( V_38 -> V_115 < 2 )
V_72 = V_78 -> V_116 -> V_117 ( V_28 , 1 , V_86 ) ;
else
V_72 = F_20 ( V_28 ) ;
if ( V_72 ) {
F_2 ( L_3 , V_72 ) ;
if ( V_30 -> V_66 )
F_8 ( V_30 -> V_66 , NULL ) ;
F_13 ( V_28 ) ;
return V_85 ;
}
return 0 ;
}
static bool F_21 ( struct V_29 * V_30 )
{
struct V_32 * V_33 = V_30 -> V_44 -> V_45 ;
memcpy ( & V_30 -> V_118 , & V_33 -> V_48 . V_54 , sizeof( V_30 -> V_118 ) ) ;
return true ;
}
static int F_22 ( struct V_41 * V_42 , unsigned int * V_119 ,
unsigned long V_120 )
{
struct V_121 * V_44 = V_42 -> V_44 ;
struct V_32 * V_33 = V_44 -> V_45 ;
struct V_77 * V_78 =
F_15 ( V_33 -> V_46 -> V_47 -> V_75 . V_76 -> V_79 ) ;
int V_72 = V_122 ;
int V_123 = 0 ;
if ( V_78 -> V_116 -> V_124 )
V_72 = V_78 -> V_116 -> V_124 ( V_33 ) ;
if ( V_72 != V_125 ) {
F_2 ( L_4 , V_21 ) ;
V_123 = - V_126 ;
}
switch ( V_33 -> V_48 . V_51 ) {
case V_127 :
F_2 ( L_5 , V_21 ) ;
* V_119 = V_128 ;
break;
case V_52 :
F_2 ( L_6 , V_21 ) ;
* V_119 = V_129 ;
break;
default:
F_2 ( L_7 ,
V_21 ,
V_33 -> V_48 . V_51 ) ;
* V_119 = V_130 ;
break;
}
V_44 -> V_131 = V_132 ;
return V_123 ;
}
static int F_23 ( struct V_41 * V_42 , unsigned int * V_119 ,
unsigned long V_120 )
{
struct V_121 * V_44 = V_42 -> V_44 ;
struct V_32 * V_33 = V_44 -> V_45 ;
struct V_77 * V_78 =
F_15 ( V_33 -> V_46 -> V_47 -> V_75 . V_76 -> V_79 ) ;
int V_72 = V_122 ;
int V_123 = 0 ;
if ( V_78 -> V_116 -> V_133 )
V_72 = V_78 -> V_116 -> V_133 ( V_33 ) ;
if ( V_72 != V_125 ) {
F_2 ( L_8 , V_21 ) ;
V_123 = - V_126 ;
}
switch ( V_33 -> V_48 . V_51 ) {
case V_127 :
F_2 ( L_5 , V_21 ) ;
* V_119 = V_128 ;
break;
case V_52 :
F_2 ( L_6 , V_21 ) ;
* V_119 = V_129 ;
break;
default:
F_2 ( L_7 ,
V_21 , V_33 -> V_48 . V_51 ) ;
* V_119 = V_130 ;
break;
}
V_44 -> V_131 = V_132 ;
return V_123 ;
}
static void F_24 ( struct V_29 * V_30 )
{
if ( V_30 -> V_40 & V_59 )
V_30 -> V_56 |= V_22 ;
if ( V_30 -> V_56 ) {
struct V_27 * V_28 = V_30 -> V_65 ;
unsigned long V_40 ;
V_30 -> V_65 = NULL ;
if ( V_28 ) {
F_4 ( & V_28 -> V_67 , V_40 ) ;
V_28 -> V_68 |= V_134 ;
F_10 ( & V_28 -> V_67 , V_40 ) ;
V_28 -> V_31 = NULL ;
F_25 ( V_28 ) ;
}
}
}
int F_26 ( struct V_32 * V_135 ,
struct V_136 * V_137 )
{
struct V_73 * V_76 = F_27 ( & V_137 -> V_33 ) ;
struct V_37 * V_47 = F_28 ( V_76 ) ;
struct V_121 * V_44 ;
F_29 ( & V_135 -> V_48 . V_138 ,
V_47 -> V_33 ,
V_139 . V_40 ,
& V_140 ) ;
V_44 = F_30 ( & V_135 -> V_48 . V_138 ,
& V_139 ,
V_76 ) ;
if ( ! V_44 ) {
F_2 ( L_9 ) ;
return - V_141 ;
}
V_44 -> V_45 = V_135 ;
V_44 -> V_131 = V_132 ;
V_44 -> V_142 = V_76 ;
V_135 -> V_48 . V_44 = V_44 ;
return 0 ;
}
void F_31 ( struct V_27 * V_28 )
{
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_143 * V_144 ;
if ( V_30 -> V_66 ) {
struct V_145 * V_146 = V_30 -> V_66 -> V_147 -> V_145 ;
unsigned long V_40 ;
F_4 ( V_146 -> V_148 , V_40 ) ;
F_32 ( V_30 -> V_66 -> V_149 ) ;
F_10 ( V_146 -> V_148 , V_40 ) ;
F_33 ( V_30 -> V_66 -> V_147 -> V_74 ) ;
return;
}
V_30 -> V_40 &= ~ V_150 ;
V_30 -> V_40 |= V_59 ;
V_30 -> V_56 |= V_9 ;
V_144 = V_30 -> V_45 ;
F_34 ( V_144 ) ;
}
static void F_35 ( unsigned long V_151 )
{
struct V_27 * V_28 = ( void * ) V_151 ;
unsigned long V_40 ;
F_4 ( & V_28 -> V_67 , V_40 ) ;
if ( ! ( V_28 -> V_68 & V_152 ) )
V_28 -> V_68 |= V_69 ;
F_10 ( & V_28 -> V_67 , V_40 ) ;
F_34 ( & V_28 -> V_143 ) ;
}
static void F_36 ( struct V_27 * V_28 )
{
if ( ! F_37 ( & V_28 -> V_153 ) )
return;
F_34 ( & V_28 -> V_143 ) ;
}
static int F_38 ( struct V_27 * V_28 , void * V_154 , int V_155 ,
enum V_156 V_106 )
{
int V_72 = 0 ;
struct V_80 * V_107 = NULL ;
struct V_2 * V_3 = & V_28 -> V_34 ;
int V_102 = 0 ;
int V_157 = 0 ;
struct V_77 * V_78 =
F_15 ( V_28 -> V_33 -> V_46 -> V_47 -> V_75 . V_76 -> V_79 ) ;
if ( V_106 != V_158 ) {
V_107 = F_39 ( sizeof( * V_107 ) , V_159 ) ;
if ( ! V_107 )
goto V_160;
F_40 ( V_107 , V_154 , V_155 ) ;
V_102 = 1 ;
}
V_28 -> V_87 = V_28 -> V_33 -> V_161 ;
V_28 -> V_107 = V_107 ;
V_28 -> V_102 = V_102 ;
V_28 -> V_100 = V_155 ;
V_28 -> V_105 = V_106 ;
V_28 -> V_89 = F_36 ;
if ( V_106 != V_158 &&
F_41 ( V_28 -> V_87 ) ) {
V_28 -> V_102 = F_42 ( V_28 -> V_33 -> V_46 -> V_47 -> V_33 ,
V_28 -> V_107 ,
V_28 -> V_102 ,
V_28 -> V_105 ) ;
}
for ( V_157 = 0 ; V_157 < 5 ; V_157 ++ ) {
V_28 -> V_68 = V_109 ;
F_43 ( & V_28 -> V_143 ) ;
V_28 -> V_153 . V_162 = ( unsigned long ) V_28 ;
V_28 -> V_153 . V_163 = F_35 ;
V_28 -> V_153 . V_164 = V_165 + V_166 * V_167 ;
F_44 ( & V_28 -> V_153 ) ;
V_72 = V_78 -> V_116 -> V_117 ( V_28 , 1 , V_159 ) ;
if ( V_72 ) {
F_37 ( & V_28 -> V_153 ) ;
F_2 ( L_10 ,
V_72 ) ;
goto V_168;
}
F_45 ( & V_28 -> V_143 ) ;
V_72 = - V_169 ;
if ( V_28 -> V_68 & V_69 ) {
int V_170 ;
F_2 ( L_11 ,
V_28 -> V_68 ) ;
V_170 = V_78 -> V_116 -> V_171 ( V_28 ) ;
F_2 ( L_12 ) ;
if ( ! ( V_28 -> V_68 & V_152 ) ) {
if ( V_170 == V_125 )
continue;
else
goto V_168;
}
}
if ( V_28 -> V_34 . V_7 == V_172 ||
V_28 -> V_34 . V_7 == V_173 ||
V_28 -> V_34 . V_7 == V_15 ) {
F_2 ( L_13 ) ;
F_46 ( V_167 ) ;
} else if ( V_28 -> V_34 . V_7 == V_23 ) {
struct V_174 V_175 ;
if ( ! F_47 ( V_3 -> V_36 , V_3 -> V_176 ,
& V_175 ) ) {
F_2 ( L_14 ) ;
continue;
}
if ( ( V_175 . V_177 == 6 && V_175 . V_178 == 0x29 ) ||
( V_175 . V_177 == 2 && V_175 . V_178 == 4 &&
V_175 . V_179 == 1 ) ) {
F_2 ( L_15
L_16
L_17 ,
F_48 ( V_28 -> V_33 -> V_180 ) ,
F_48 ( V_28 -> V_181 . V_182 ) ) ;
F_46 ( 5 * V_167 ) ;
} else if ( V_175 . V_177 == 1 ) {
V_72 = 0 ;
break;
} else if ( V_175 . V_177 == 5 ) {
break;
} else {
F_2 ( L_18
L_19
L_20 ,
F_48 ( V_28 -> V_33 -> V_180 ) ,
F_48 ( V_28 -> V_181 . V_182 ) ,
V_175 . V_177 ,
V_175 . V_178 , V_175 . V_179 ) ;
}
} else if ( V_28 -> V_34 . V_4 != V_183 ||
V_28 -> V_34 . V_7 != V_50 ) {
F_2 ( L_21
L_22 ,
V_28 -> V_34 . V_4 ,
V_28 -> V_34 . V_7 ) ;
goto V_168;
} else {
V_72 = 0 ;
break;
}
}
V_168:
if ( V_106 != V_158 ) {
if ( F_41 ( V_28 -> V_87 ) )
F_49 ( V_28 -> V_33 -> V_46 -> V_47 -> V_33 ,
V_28 -> V_107 , V_28 -> V_102 ,
V_28 -> V_105 ) ;
F_50 ( V_107 ) ;
}
V_160:
return V_72 ;
}
static void F_51 ( struct V_32 * V_33 )
{
struct V_184 * V_95 =
(struct V_184 * ) V_33 -> V_185 ;
if ( ( V_95 -> V_186 == 1 &&
V_95 -> V_187 == 1 &&
V_95 -> V_188 == 0 &&
V_95 -> V_189 == 0 &&
V_95 -> V_147 == 0 )
||
( V_95 -> V_186 == 0 &&
V_95 -> V_187 == 0 &&
V_95 -> V_188 == 0xCE &&
V_95 -> V_189 == 0xAA &&
( V_95 -> V_147 & ~ 0x10 ) == 0 ) )
V_33 -> V_48 . V_51 = V_127 ;
else if ( ( V_95 -> V_190 == 1 &&
V_95 -> V_187 == 1 &&
V_95 -> V_191 == 0x14 &&
V_95 -> V_192 == 0xEB &&
( V_95 -> V_147 & ~ 0x10 ) == 0 ) )
V_33 -> V_48 . V_51 = V_52 ;
else if ( ( V_95 -> V_186 == 1 &&
V_95 -> V_187 == 1 &&
V_95 -> V_188 == 0x3C &&
V_95 -> V_189 == 0xC3 &&
V_95 -> V_147 == 0 )
||
( V_95 -> V_190 == 1 &&
V_95 -> V_187 == 1 &&
V_95 -> V_191 == 0x69 &&
V_95 -> V_192 == 0x96 &&
( V_95 -> V_147 & ~ 0x10 ) == 0 ) )
V_33 -> V_48 . V_51 = V_52 ;
}
static int F_52 ( struct V_32 * V_33 , V_93 V_57 ,
V_93 V_193 , void * V_154 , int V_155 ,
enum V_156 V_106 )
{
int V_72 = 0 ;
struct V_27 * V_28 ;
struct V_184 * V_194 = (struct V_184 * )
& V_33 -> V_185 [ 0 ] ;
V_72 = - V_195 ;
V_28 = F_16 ( V_159 ) ;
if ( ! V_28 )
goto V_160;
V_28 -> V_33 = V_33 ;
V_28 -> V_94 . V_95 . V_196 = 0x27 ;
V_28 -> V_94 . V_95 . V_57 = V_57 ;
V_28 -> V_94 . V_95 . V_193 = V_193 ;
V_28 -> V_94 . V_95 . V_147 = V_194 -> V_147 ;
V_28 -> V_94 . V_108 = 1 ;
V_72 = F_38 ( V_28 , V_154 , V_155 , V_106 ) ;
F_13 ( V_28 ) ;
V_160:
return V_72 ;
}
static int F_53 ( struct V_32 * V_33 )
{
int V_72 ;
T_1 * V_197 ;
V_93 V_57 ;
V_197 = F_39 ( 512 , V_159 ) ;
if ( ! V_197 )
return - V_195 ;
if ( V_33 -> V_48 . V_51 == V_127 ) {
V_33 -> V_48 . V_198 = V_197 ;
V_57 = V_199 ;
} else {
V_33 -> V_48 . V_200 = V_197 ;
V_57 = V_201 ;
}
V_72 = F_52 ( V_33 , V_57 , 0 , V_197 , 512 ,
V_202 ) ;
if ( V_72 )
goto V_203;
if ( F_54 ( V_197 [ 0 ] ) & 4 ) {
F_2 ( L_23
L_24 , F_48 ( V_33 -> V_180 ) ) ;
if ( ! ( V_197 [ 83 ] & F_55 ( 1 << 6 ) ) )
goto V_204;
V_72 = F_52 ( V_33 , V_205 ,
V_206 ,
NULL , 0 , V_158 ) ;
if ( V_72 )
goto V_204;
F_46 ( 5 * V_167 ) ;
V_72 = F_52 ( V_33 , V_57 , 0 , V_197 , 512 ,
V_202 ) ;
if ( V_72 )
goto V_203;
}
V_204:
F_56 ( V_33 , V_33 -> V_207 ) ;
return 0 ;
V_203:
V_33 -> V_48 . V_200 = NULL ;
V_33 -> V_48 . V_198 = NULL ;
F_50 ( V_197 ) ;
return V_72 ;
}
static int F_57 ( struct V_32 * V_33 )
{
return - V_141 ;
}
int F_58 ( struct V_32 * V_33 )
{
int V_72 ;
F_51 ( V_33 ) ;
V_72 = F_59 ( V_33 ) ;
if ( V_72 )
return V_72 ;
switch ( V_33 -> V_208 ) {
case V_209 :
V_72 = F_53 ( V_33 ) ;
break;
case V_210 :
V_72 = F_57 ( V_33 ) ;
break;
default:
break;
}
F_60 ( V_33 ) ;
if ( ! V_72 ) {
F_59 ( V_33 ) ;
V_72 = F_61 ( V_33 -> V_207 ) ;
}
return V_72 ;
}
void F_62 ( struct V_73 * V_76 )
{
struct V_211 * V_212 ;
F_63 (sdev, shost) {
struct V_32 * V_213 = F_64 ( V_212 ) ;
struct V_121 * V_44 = V_213 -> V_48 . V_44 ;
if ( ! F_65 ( V_213 ) )
continue;
F_66 ( V_44 , V_214 , L_25 ) ;
F_67 ( V_76 , V_44 ) ;
}
}
int F_68 ( struct V_215 * V_216 , struct V_27 * V_28 ,
enum V_217 * V_218 )
{
struct V_32 * V_213 = F_69 ( V_216 ) ;
if ( ! F_65 ( V_213 ) || V_28 )
return 0 ;
* V_218 = V_219 ;
return 1 ;
}
int F_70 ( struct V_73 * V_76 , struct V_220 * V_221 ,
struct V_220 * V_222 )
{
int V_218 = 0 ;
struct V_215 * V_216 , * V_223 ;
struct V_121 * V_44 ;
do {
F_71 ( V_224 ) ;
V_44 = NULL ;
F_72 (cmd, n, work_q, eh_entry) {
struct V_32 * V_213 = F_69 ( V_216 ) ;
if ( ! F_65 ( V_213 ) || F_73 ( V_216 ) )
continue;
if ( V_44 && V_44 != V_213 -> V_48 . V_44 )
continue;
V_44 = V_213 -> V_48 . V_44 ;
V_218 = 1 ;
F_74 ( & V_216 -> V_225 , & V_224 ) ;
}
if ( ! F_75 ( & V_224 ) ) {
F_66 ( V_44 , V_214 , L_26 ) ;
F_76 ( V_76 , V_44 , & V_224 ) ;
while ( ! F_75 ( & V_224 ) )
F_12 ( V_224 . V_226 ) ;
}
} while ( V_44 );
return V_218 ;
}
