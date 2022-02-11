static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 , * V_11 ;
struct V_9 * V_12 ;
V_4 = & V_13 ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
V_8 = & V_4 -> V_14 ;
V_12 = V_8 -> V_11 ;
for ( V_10 = V_12 ; V_10 != (struct V_9 * ) V_8 ;
V_10 = V_11 ) {
V_11 = V_10 -> V_11 ;
V_6 = F_3 ( V_10 ) ;
if ( V_6 -> V_16 == V_2 ) {
F_4 ( V_10 , V_8 ) ;
F_5 ( V_10 ) ;
}
}
F_6 ( & V_4 -> V_14 . V_15 ) ;
}
int F_7 ( struct V_9 * V_10 , int V_17 )
{
int V_18 ;
F_8 ( & V_19 ) ;
V_18 = F_9 ( V_10 , V_17 , & V_13 ) ;
F_10 ( & V_19 ) ;
return V_18 ;
}
static void F_11 ( struct V_1 * V_20 )
{
}
static void F_12 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_28 * V_29 ;
int V_30 ;
F_14 ( L_1 , V_31 ) ;
F_15 ( & V_27 -> V_32 ) ;
F_2 ( & V_27 -> V_33 ) ;
for ( V_30 = 0 ; V_30 < V_34 ; V_30 ++ ) {
V_29 = V_27 -> V_35 [ V_30 ] ;
if ( V_29 ) {
if ( V_29 -> V_22 == V_22 ) {
F_6 ( & V_27 -> V_33 ) ;
F_16 ( V_29 , L_2 ) ;
F_17 ( V_29 ) ;
F_2 ( & V_27 -> V_33 ) ;
}
}
}
F_6 ( & V_27 -> V_33 ) ;
F_18 ( & V_27 -> V_32 ) ;
}
static int F_19 ( struct V_28 * V_29 ,
struct V_36 * V_37 )
{
struct V_38 * V_39 = V_29 -> V_39 ;
struct V_40 * V_41 ;
int V_18 = 0 ;
V_41 = F_20 ( V_37 ) ;
F_16 ( V_29 , L_3
L_4 , V_39 -> V_42 . V_43 ,
F_21 ( V_41 -> V_44 ) , V_41 -> V_45 ) ;
if ( ( V_41 -> V_46 == V_47 ) &&
( V_41 -> V_45 == V_48 ) ) {
switch ( F_22 ( V_37 ) ) {
case V_49 :
V_18 = F_23 ( V_29 , V_37 ) ;
break;
case V_50 :
V_18 = F_24 ( V_29 , V_37 ) ;
break;
case V_51 :
V_18 = F_25 ( V_29 , V_37 ) ;
break;
default:
break;
}
} else if ( ( V_41 -> V_46 == V_52 ) &&
( V_41 -> V_45 == V_53 ) )
F_16 ( V_29 , L_5 ) ;
else {
F_16 ( V_29 , L_6
L_7 ,
V_41 -> V_46 , V_41 -> V_45 ) ;
return - V_54 ;
}
if ( V_18 )
return - V_55 ;
else
return 0 ;
}
static int F_26 ( struct V_1 * V_20 , struct V_36 * V_37 )
{
struct V_56 * V_57 ;
struct V_58 * V_59 ;
struct V_9 * V_10 ;
struct V_40 * V_41 ;
struct V_23 * V_24 ;
struct V_26 * V_27 ;
struct V_21 * V_22 ;
struct V_60 * V_61 ;
struct V_28 * V_29 ;
struct V_62 * V_63 ;
T_1 V_64 , V_65 ;
T_2 V_66 ;
unsigned int V_67 , V_17 , V_68 ;
int V_69 , V_18 = 0 ;
V_22 = (struct V_21 * ) F_13 ( V_20 ) ;
V_24 = V_22 -> V_25 ;
V_27 = V_24 -> V_27 ;
V_41 = F_20 ( V_37 ) ;
V_10 = F_27 ( V_37 ) ;
if ( ! V_20 -> V_70 ) {
F_28 ( V_20 , L_8 ) ;
F_5 ( V_10 ) ;
return 0 ;
}
if ( F_29 ( V_41 -> V_45 == V_48 ) ) {
if ( ! V_24 -> V_71 . V_72 ) {
F_28 ( V_20 , L_9 ) ;
F_5 ( V_10 ) ;
return - V_73 ;
}
if ( F_30 ( & V_24 -> V_71 , V_20 , V_10 ) )
return 0 ;
}
V_64 = F_31 ( V_37 ) ;
V_65 = F_32 ( V_37 ) ;
F_2 ( & V_27 -> V_33 ) ;
V_29 = F_33 ( V_22 , F_34 ( V_41 -> V_74 ) ) ;
if ( V_29 && ( F_35 ( V_75 , & V_29 -> V_76 ) ) ) {
F_28 ( V_20 , L_10
L_11 , F_34 ( V_41 -> V_74 ) ) ;
F_6 ( & V_27 -> V_33 ) ;
V_18 = F_19 ( V_29 , V_37 ) ;
if ( V_18 != - V_54 ) {
F_5 ( V_10 ) ;
return V_18 ;
}
} else {
F_6 ( & V_27 -> V_33 ) ;
}
V_68 = sizeof( struct V_56 ) ;
V_67 = sizeof( struct V_60 ) ;
V_17 = sizeof( struct V_58 ) ;
V_69 = ( V_10 -> V_77 - V_17 + sizeof( V_66 ) ) / V_78 ;
V_10 -> V_79 = V_80 ;
V_66 = F_36 ( V_37 ) ;
if ( F_37 ( V_10 ) ) {
T_3 * V_81 ;
if ( F_7 ( V_10 , V_17 ) ) {
F_5 ( V_10 ) ;
return - V_55 ;
}
V_81 = & F_38 ( V_10 ) -> V_82 [ F_38 ( V_10 ) -> V_83 - 1 ] ;
V_59 = F_39 ( V_81 -> V_84 , V_85 )
+ V_81 -> V_86 ;
} else {
V_59 = (struct V_58 * ) F_40 ( V_10 , V_17 ) ;
}
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
V_59 -> V_87 = V_65 ;
V_59 -> V_88 = F_41 ( ~ V_66 ) ;
if ( F_37 ( V_10 ) ) {
F_42 ( V_59 , V_85 ) ;
V_59 = NULL ;
}
F_43 ( V_10 , V_68 + V_67 ) ;
F_44 ( V_10 ) ;
F_45 ( V_10 ) ;
V_10 -> V_89 = V_68 ;
V_10 -> V_90 = F_46 ( V_91 ) ;
V_10 -> V_92 = V_24 -> V_93 ;
V_57 = F_47 ( V_10 ) ;
V_57 -> V_94 = F_46 ( V_91 ) ;
if ( V_24 -> V_71 . V_95 )
F_48 ( V_57 -> V_96 , V_41 -> V_74 ) ;
else
memcpy ( V_57 -> V_96 , V_24 -> V_71 . V_97 , V_98 ) ;
if ( F_29 ( V_24 -> V_71 . V_99 != V_100 ) )
memcpy ( V_57 -> V_101 , V_24 -> V_71 . V_102 , V_98 ) ;
else
memcpy ( V_57 -> V_101 , V_22 -> V_103 , V_98 ) ;
V_61 = (struct V_60 * ) ( V_57 + 1 ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
if ( V_104 )
F_49 ( V_61 , V_104 ) ;
V_61 -> V_105 = V_64 ;
if ( V_20 -> V_106 && F_50 ( V_37 ) ) {
F_38 ( V_10 ) -> V_107 = V_108 ;
F_38 ( V_10 ) -> V_109 = F_50 ( V_37 ) ;
} else {
F_38 ( V_10 ) -> V_107 = 0 ;
F_38 ( V_10 ) -> V_109 = 0 ;
}
V_63 = F_51 ( V_20 -> V_110 , F_52 () ) ;
V_63 -> V_111 ++ ;
V_63 -> V_112 += V_69 ;
F_53 () ;
V_16 ( V_37 ) = V_20 ;
if ( V_22 -> V_113 . V_114 )
F_54 ( V_20 , V_10 ) ;
else if ( F_55 ( V_10 ) )
F_54 ( V_20 , V_10 ) ;
return 0 ;
}
static int F_56 ( struct V_9 * V_10 , struct V_115 * V_92 ,
struct V_116 * V_117 , struct V_115 * V_118 )
{
struct V_1 * V_20 ;
struct V_23 * V_24 ;
struct V_40 * V_41 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
unsigned short V_119 ;
V_24 = F_57 ( V_117 , struct V_23 ,
V_120 ) ;
V_20 = V_24 -> V_71 . V_2 ;
if ( F_29 ( V_20 == NULL ) ) {
F_58 (KERN_ERR PFX L_12 ) ;
goto V_121;
}
if ( F_29 ( F_47 ( V_10 ) -> V_94 != F_46 ( V_91 ) ) ) {
F_58 (KERN_ERR PFX L_13 ) ;
goto V_121;
}
if ( F_29 ( ( V_10 -> V_77 < V_122 ) ||
! F_59 ( V_10 , V_123 ) ) )
goto V_121;
F_60 ( V_10 , sizeof( struct V_60 ) ) ;
V_41 = (struct V_40 * ) F_61 ( V_10 ) ;
V_119 = F_21 ( V_41 -> V_44 ) ;
V_6 = F_3 ( V_10 ) ;
V_6 -> V_16 = V_20 ;
V_4 = & V_13 ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
F_62 ( & V_4 -> V_14 , V_10 ) ;
if ( V_4 -> V_14 . V_114 == 1 )
F_63 ( V_4 -> V_124 ) ;
F_6 ( & V_4 -> V_14 . V_15 ) ;
return 0 ;
V_121:
F_5 ( V_10 ) ;
return - 1 ;
}
static int F_64 ( void * V_125 )
{
struct V_3 * V_4 = V_125 ;
struct V_9 * V_10 ;
F_65 ( V_126 , - 20 ) ;
F_66 ( V_127 ) ;
while ( ! F_67 () ) {
F_68 () ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
while ( ( V_10 = F_69 ( & V_4 -> V_14 ) ) != NULL ) {
F_6 ( & V_4 -> V_14 . V_15 ) ;
F_70 ( V_10 ) ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
}
F_71 ( V_127 ) ;
F_6 ( & V_4 -> V_14 . V_15 ) ;
}
F_71 ( V_128 ) ;
return 0 ;
}
static void F_70 ( struct V_9 * V_10 )
{
T_2 V_129 ;
struct V_1 * V_20 ;
struct V_5 * V_6 ;
struct V_62 * V_63 ;
struct V_40 * V_41 ;
struct V_58 V_130 ;
struct V_36 * V_37 ;
struct V_1 * V_131 ;
struct V_21 * V_22 ;
T_1 * V_132 = NULL ;
T_1 * V_133 = NULL ;
struct V_60 * V_61 ;
V_6 = F_3 ( V_10 ) ;
V_20 = V_6 -> V_16 ;
if ( F_29 ( V_20 == NULL ) ) {
F_58 (KERN_ERR PFX L_14 ) ;
F_5 ( V_10 ) ;
return;
}
if ( F_37 ( V_10 ) )
F_72 ( V_10 ) ;
V_132 = F_47 ( V_10 ) -> V_101 ;
V_133 = F_47 ( V_10 ) -> V_96 ;
V_61 = (struct V_60 * ) F_73 ( V_10 ) ;
V_41 = (struct V_40 * ) F_61 ( V_10 ) ;
F_74 ( V_10 , sizeof( struct V_60 ) ) ;
V_129 = V_10 -> V_77 - sizeof( struct V_58 ) ;
V_63 = F_51 ( V_20 -> V_110 , F_52 () ) ;
V_63 -> V_134 ++ ;
V_63 -> V_135 += V_129 / V_78 ;
V_37 = (struct V_36 * ) V_10 ;
F_75 ( V_37 ) ;
V_16 ( V_37 ) = V_20 ;
F_31 ( V_37 ) = V_61 -> V_105 ;
if ( F_76 ( V_10 , V_129 , & V_130 , sizeof( V_130 ) ) ) {
F_53 () ;
F_5 ( V_10 ) ;
return;
}
F_32 ( V_37 ) = V_130 . V_87 ;
F_77 ( V_37 ) = V_130 . V_88 ;
if ( F_78 ( V_10 , V_129 ) ) {
F_53 () ;
F_5 ( V_10 ) ;
return;
}
V_41 = F_20 ( V_37 ) ;
V_131 = F_79 ( V_20 , F_34 ( V_41 -> V_74 ) ) ;
if ( V_131 ) {
V_22 = F_13 ( V_131 ) ;
if ( F_80 ( V_22 -> V_103 , V_133 )
!= 0 ) {
F_28 ( V_20 , L_15 ) ;
F_53 () ;
F_5 ( V_10 ) ;
return;
}
}
if ( V_41 -> V_45 == V_136 &&
V_41 -> V_46 == V_137 ) {
F_53 () ;
F_5 ( V_10 ) ;
return;
}
if ( V_41 -> V_45 == V_48 &&
V_41 -> V_46 == V_47 ) {
switch ( F_22 ( V_37 ) ) {
case V_50 :
if ( F_34 ( V_41 -> V_138 ) == V_139 ) {
F_53 () ;
F_5 ( V_10 ) ;
return;
}
break;
}
}
if ( F_81 ( F_77 ( V_37 ) ) !=
~ F_82 ( ~ 0 , V_10 -> V_140 , V_129 ) ) {
if ( V_63 -> V_141 < 5 )
F_58 (KERN_WARNING PFX L_16
L_17 ) ;
V_63 -> V_141 ++ ;
F_53 () ;
F_5 ( V_10 ) ;
return;
}
F_53 () ;
F_83 ( V_20 , V_37 ) ;
}
int F_84 ( void * V_125 )
{
struct V_142 * V_143 = V_125 ;
struct V_144 * V_145 , * V_146 ;
F_85 ( V_147 ) ;
F_65 ( V_126 , - 20 ) ;
F_66 ( V_127 ) ;
while ( ! F_67 () ) {
F_68 () ;
F_2 ( & V_143 -> V_148 ) ;
while ( ! F_86 ( & V_143 -> V_147 ) ) {
F_87 ( & V_143 -> V_147 , & V_147 ) ;
F_6 ( & V_143 -> V_148 ) ;
F_88 (work, tmp, &work_list, list) {
F_89 ( & V_145 -> V_8 ) ;
F_90 ( V_145 -> V_29 , V_145 -> V_149 ) ;
F_91 ( V_145 ) ;
}
F_2 ( & V_143 -> V_148 ) ;
}
F_71 ( V_127 ) ;
F_6 ( & V_143 -> V_148 ) ;
}
F_71 ( V_128 ) ;
return 0 ;
}
static struct V_150 * F_92 ( struct V_151 * V_152 )
{
struct V_150 * V_153 ;
struct V_1 * V_20 = F_93 ( V_152 ) ;
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_154 * V_155 ;
int V_18 = 0 ;
V_155 = (struct V_154 * ) V_27 -> V_156 ;
if ( ! V_155 )
return NULL ;
V_153 = F_94 ( V_152 ) ;
F_95 ( & V_27 -> V_157 ) ;
if ( F_96 ( V_27 ) )
return V_153 ;
V_18 = F_97 ( & V_27 -> V_157 , ( 2 * V_158 ) ) ;
if ( ! V_18 ) {
F_28 ( V_20 , L_18 ) ;
return V_153 ;
}
V_153 -> V_159 += V_155 -> V_160 . V_161 ;
V_153 -> V_162 += V_155 -> V_163 . V_164 ;
V_153 -> V_165 += ( V_155 -> V_163 . V_166 ) / 4 ;
V_153 -> V_167 += V_155 -> V_168 . V_169 ;
V_153 -> V_170 += ( V_155 -> V_168 . V_171 ) / 4 ;
V_153 -> V_172 = 0 ;
V_153 -> V_173 = 0 ;
V_153 -> V_174 = 0 ;
V_153 -> V_175 = 0 ;
V_153 -> V_176 = 0 ;
V_153 -> V_177 = 0 ;
return V_153 ;
}
static int F_98 ( struct V_1 * V_20 , struct V_178 * V_92 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_151 * V_152 = V_20 -> V_179 ;
int V_18 = 0 ;
V_152 -> V_180 = V_181 ;
V_152 -> V_182 = V_183 ;
V_152 -> V_184 = V_185 ;
V_152 -> V_186 = 0 ;
if ( V_20 -> V_187 )
V_152 -> V_188 = V_189 ;
else
V_152 -> V_188 = V_190 ;
V_18 = F_99 ( V_20 -> V_179 , V_92 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_19 ) ;
return V_18 ;
}
if ( ! V_20 -> V_187 )
F_100 ( V_20 -> V_179 ) = V_191 ;
sprintf ( F_101 ( V_20 -> V_179 ) , L_20 ,
V_192 , V_193 ,
V_24 -> V_93 -> V_194 ) ;
return 0 ;
}
static void F_102 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_115 * V_93 = V_24 -> V_93 ;
struct V_195 V_196 ;
if ( ! F_103 ( V_93 , & V_196 ) ) {
V_20 -> V_197 &=
~ ( V_198 | V_199 ) ;
if ( V_196 . V_200 & ( V_201 |
V_202 ) )
V_20 -> V_197 |= V_198 ;
if ( V_196 . V_200 & V_203 )
V_20 -> V_197 |= V_199 ;
switch ( F_104 ( & V_196 ) ) {
case V_204 :
V_20 -> V_205 = V_198 ;
break;
case V_206 :
V_20 -> V_205 = V_207 ;
break;
case V_208 :
V_20 -> V_205 = V_199 ;
break;
}
}
}
static int F_105 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_26 * V_27 = V_24 -> V_27 ;
struct V_115 * V_92 = V_27 -> V_209 ;
int V_18 = 0 ;
if ( ( V_92 -> V_76 & V_210 ) && F_106 ( V_92 ) )
F_107 ( V_211 , & V_27 -> V_212 ) ;
else {
F_108 ( V_211 , & V_27 -> V_212 ) ;
V_18 = - 1 ;
}
return V_18 ;
}
void F_109 ( struct V_26 * V_27 )
{
if ( F_35 ( V_213 , & V_27 -> V_209 -> V_214 ) )
F_108 ( V_211 , & V_27 -> V_212 ) ;
else
F_107 ( V_211 , & V_27 -> V_212 ) ;
}
static int F_110 ( struct V_1 * V_20 )
{
struct V_26 * V_27 ;
struct V_23 * V_24 ;
struct V_21 * V_22 ;
T_4 V_215 , V_216 ;
V_22 = F_13 ( V_20 ) ;
V_24 = V_22 -> V_25 ;
V_27 = V_24 -> V_27 ;
if ( ! V_27 -> V_209 -> V_217 ||
! V_27 -> V_209 -> V_217 -> V_218 )
return - V_219 ;
if ( F_111 ( V_20 , V_220 ) )
return - V_73 ;
F_112 ( & V_22 -> V_113 ) ;
V_22 -> V_221 = 0 ;
F_113 ( & V_22 -> V_222 , V_223 , ( unsigned long ) V_20 ) ;
F_102 ( V_20 ) ;
if ( ! V_20 -> V_187 ) {
V_215 = F_114 ( V_24 -> V_71 . V_102 , 1 , 0 ) ;
F_28 ( V_20 , L_21 , V_215 ) ;
F_115 ( V_20 , V_215 ) ;
V_216 = F_114 ( V_24 -> V_71 . V_102 , 2 , 0 ) ;
F_28 ( V_20 , L_22 , V_216 ) ;
F_116 ( V_20 , V_216 ) ;
}
return 0 ;
}
static void F_117 ( unsigned long V_140 )
{
struct V_26 * V_27 = (struct V_26 * ) V_140 ;
F_14 ( L_23
L_24 ) ;
F_108 ( V_224 , & V_27 -> V_76 ) ;
F_118 ( & V_27 -> V_225 ) ;
}
static void F_119 ( void * V_226 , unsigned long V_227 ,
T_5 V_228 )
{
struct V_26 * V_27 = (struct V_26 * ) V_226 ;
struct V_1 * V_20 ;
struct V_1 * V_187 ;
struct V_23 * V_24 ;
int V_229 = 0 ;
T_2 V_230 = 1 ;
if ( V_228 != 0 )
return;
switch ( V_227 ) {
case V_231 :
if ( ! F_35 ( V_232 , & V_27 -> V_212 ) )
F_58 ( V_233 L_25\
L_26 ) ;
break;
case V_234 :
F_107 ( V_235 , & V_27 -> V_212 ) ;
F_107 ( V_232 , & V_27 -> V_212 ) ;
V_230 = 0 ;
break;
case V_236 :
F_108 ( V_235 , & V_27 -> V_212 ) ;
V_230 = 0 ;
break;
case V_237 :
break;
default:
F_58 (KERN_ERR PFX L_27 , event) ;
return;
}
F_15 ( & V_238 ) ;
F_120 (interface, &if_list, list) {
if ( V_24 -> V_27 != V_27 )
continue;
V_20 = V_24 -> V_71 . V_2 ;
F_28 ( V_20 , L_28 ,
V_24 -> V_93 -> V_194 , V_227 ) ;
F_102 ( V_20 ) ;
if ( V_230 && ! F_105 ( V_20 ) ) {
F_58 ( V_233 L_29 ) ;
F_121 ( & V_24 -> V_71 ) ;
} else if ( F_122 ( & V_24 -> V_71 ) ) {
F_15 ( & V_20 -> V_239 ) ;
F_120 (vport, &lport->vports, list)
F_123 ( V_187 -> V_179 ) =
V_240 ;
F_18 ( & V_20 -> V_239 ) ;
F_123 ( V_20 -> V_179 ) = V_240 ;
F_51 ( V_20 -> V_110 ,
F_52 () ) -> V_241 ++ ;
F_53 () ;
F_124 ( V_20 ) ;
V_229 = 1 ;
}
}
F_18 ( & V_238 ) ;
if ( V_229 ) {
F_107 ( V_242 , & V_27 -> V_212 ) ;
F_125 ( & V_27 -> V_243 ) ;
F_14 ( L_30
L_31 ,
V_27 -> V_244 ) ;
V_27 -> V_245 = 1 ;
F_126 ( V_27 -> V_243 ,
( V_27 -> V_244 == 0 ) ) ;
F_14 ( L_32 ,
V_27 -> V_244 ) ;
V_27 -> V_245 = 0 ;
if ( F_127 ( V_126 ) )
F_128 ( V_126 ) ;
}
}
static int F_129 ( struct V_1 * V_20 )
{
memcpy ( & V_20 -> V_246 , & V_247 ,
sizeof( struct V_248 ) ) ;
F_130 ( V_20 ) ;
F_131 ( V_20 ) ;
F_132 ( V_20 ) ;
F_133 ( V_20 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_20 )
{
if ( ! F_135 ( V_20 , V_249 , V_250 ,
V_251 , NULL ) ) {
F_58 (KERN_ERR PFX L_33 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_136 ( struct V_1 * V_20 )
{
V_20 -> V_70 = 0 ;
V_20 -> V_252 = 0 ;
V_20 -> V_253 = 3 ;
V_20 -> V_254 = 3 ;
V_20 -> V_255 = 2 * 1000 ;
V_20 -> V_256 = 10 * 1000 ;
V_20 -> V_257 = ( V_258 | V_259 |
V_260 | V_261 ) ;
V_20 -> V_262 = 1 ;
memset ( & V_20 -> V_263 , 0 , sizeof( struct V_264 ) ) ;
V_20 -> V_263 . V_265 = V_266 ;
if ( F_137 ( V_20 ) )
return - V_55 ;
F_138 ( V_20 ) ;
return 0 ;
}
static int F_139 ( struct V_9 * V_10 , struct V_115 * V_92 ,
struct V_116 * V_117 ,
struct V_115 * V_267 )
{
struct V_23 * V_24 ;
V_24 = F_57 ( V_117 , struct V_23 ,
V_268 ) ;
F_140 ( & V_24 -> V_71 , V_10 ) ;
return 0 ;
}
static void F_141 ( struct V_1 * V_20 , T_1 * V_269 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
memcpy ( V_22 -> V_103 , V_269 , V_98 ) ;
}
static T_1 * F_142 ( struct V_1 * V_20 )
{
struct V_21 * V_22 ;
V_22 = (struct V_21 * ) F_13 ( V_20 ) ;
return V_22 -> V_103 ;
}
static void F_143 ( struct V_270 * V_271 , struct V_9 * V_10 )
{
V_10 -> V_92 = F_144 ( V_271 ) -> V_93 ;
F_145 ( V_10 ) ;
}
static int F_146 ( struct V_272 * V_187 , bool V_273 )
{
struct V_151 * V_152 = F_147 ( V_187 ) ;
struct V_1 * V_274 = F_93 ( V_152 ) ;
struct V_21 * V_22 = F_13 ( V_274 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_115 * V_93 = V_24 -> V_93 ;
struct V_1 * V_131 ;
if ( ! F_35 ( V_275 , & V_24 -> V_27 -> V_76 ) ) {
F_58 (KERN_ERR PFX L_34
L_35 ) ;
return - V_276 ;
}
F_15 ( & V_238 ) ;
V_131 = F_148 ( V_24 , & V_187 -> V_92 , 1 ) ;
F_18 ( & V_238 ) ;
if ( F_149 ( V_131 ) ) {
F_58 (KERN_ERR PFX L_36 ,
netdev->name) ;
return - V_276 ;
}
if ( V_273 ) {
F_150 ( V_187 , V_277 ) ;
} else {
V_131 -> V_278 = V_279 ;
F_151 ( V_131 ) ;
F_152 ( V_131 ) ;
F_153 ( V_131 ) ;
}
return 0 ;
}
static int F_154 ( struct V_272 * V_187 )
{
struct V_151 * V_152 = F_147 ( V_187 ) ;
struct V_1 * V_274 = F_93 ( V_152 ) ;
struct V_1 * V_131 = V_187 -> V_280 ;
struct V_21 * V_22 = F_13 ( V_131 ) ;
F_15 ( & V_274 -> V_239 ) ;
F_155 ( & V_131 -> V_8 ) ;
F_18 ( & V_274 -> V_239 ) ;
F_156 ( V_281 , & V_22 -> V_282 ) ;
return 0 ;
}
static int F_157 ( struct V_272 * V_187 , bool V_283 )
{
struct V_1 * V_20 = V_187 -> V_280 ;
if ( V_283 ) {
F_150 ( V_187 , V_277 ) ;
F_158 ( V_20 ) ;
} else {
V_20 -> V_278 = V_279 ;
F_152 ( V_20 ) ;
F_153 ( V_20 ) ;
}
return 0 ;
}
static int F_159 ( struct V_23 * V_24 )
{
struct V_115 * V_93 = V_24 -> V_93 ;
struct V_115 * V_284 = V_24 -> V_27 -> V_209 ;
struct V_285 * V_286 ;
int V_287 = 0 ;
F_160 () ;
F_161 (physdev, ha) {
F_14 ( L_37 ,
V_286 -> type ) ;
F_58 ( V_288 L_38 , V_286 -> V_269 [ 0 ] ,
V_286 -> V_269 [ 1 ] , V_286 -> V_269 [ 2 ] , V_286 -> V_269 [ 3 ] ,
V_286 -> V_269 [ 4 ] , V_286 -> V_269 [ 5 ] ) ;
if ( ( V_286 -> type == V_289 ) &&
( F_162 ( V_286 -> V_269 ) ) ) {
memcpy ( V_24 -> V_71 . V_102 , V_286 -> V_269 ,
V_98 ) ;
V_287 = 1 ;
F_14 ( L_39 ) ;
}
}
F_163 () ;
if ( ! V_287 )
return - V_54 ;
V_24 -> V_268 . V_290 = F_139 ;
V_24 -> V_268 . type = F_46 ( V_291 ) ;
V_24 -> V_268 . V_92 = V_93 ;
F_164 ( & V_24 -> V_268 ) ;
V_24 -> V_120 . V_290 = F_56 ;
V_24 -> V_120 . type = F_165 ( V_91 ) ;
V_24 -> V_120 . V_92 = V_93 ;
F_164 ( & V_24 -> V_120 ) ;
return 0 ;
}
static int F_166 ( void )
{
V_190 =
F_167 ( & V_292 ) ;
if ( V_190 == NULL ) {
F_58 (KERN_ERR PFX L_40 ) ;
return - V_54 ;
}
V_189 =
F_167 ( & V_293 ) ;
if ( V_189 == NULL ) {
F_58 (KERN_ERR PFX
L_41 ) ;
F_168 ( V_190 ) ;
V_190 = NULL ;
return - V_54 ;
}
return 0 ;
}
static void F_169 ( void )
{
F_168 ( V_190 ) ;
F_168 ( V_189 ) ;
V_190 = NULL ;
V_189 = NULL ;
}
static void F_170 ( struct V_294 * V_294 )
{
struct V_23 * V_24 ;
struct V_115 * V_93 ;
V_24 = F_57 ( V_294 , struct V_23 , V_294 ) ;
F_14 ( L_42 ) ;
V_93 = V_24 -> V_93 ;
if ( F_171 ( V_295 , & V_24 -> V_296 ) )
F_172 ( & V_24 -> V_71 ) ;
F_91 ( V_24 ) ;
F_173 ( V_93 ) ;
F_174 ( V_297 ) ;
}
static inline void F_175 ( struct V_23 * V_24 )
{
F_176 ( & V_24 -> V_294 ) ;
}
static inline void F_177 ( struct V_23 * V_24 )
{
F_178 ( & V_24 -> V_294 , F_170 ) ;
}
static void F_179 ( struct V_26 * V_27 )
{
if ( V_27 -> V_298 ) {
F_180 ( V_27 -> V_298 ) ;
V_27 -> V_298 = NULL ;
}
F_91 ( V_27 -> V_35 ) ;
F_181 ( V_27 ) ;
F_91 ( V_27 ) ;
}
static struct V_26 * F_182 ( struct V_299 * V_300 )
{
struct V_26 * V_27 ;
int V_18 ;
V_27 = F_183 ( sizeof( * V_27 ) , V_301 ) ;
if ( ! V_27 ) {
F_58 (KERN_ERR PFX L_43 ) ;
return NULL ;
}
F_184 ( & V_27 -> V_33 ) ;
F_185 ( & V_27 -> V_32 ) ;
V_27 -> V_300 = V_300 ;
V_18 = F_186 ( V_27 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_44 ) ;
goto V_302;
}
V_27 -> V_209 = V_300 -> V_93 ;
V_27 -> V_303 = 0 ;
V_27 -> V_35 =
F_183 ( sizeof( struct V_28 * ) * V_34 ,
V_301 ) ;
if ( ! V_27 -> V_35 ) {
F_58 (KERN_ERR PFX L_45 ) ;
goto V_304;
}
V_27 -> V_244 = 0 ;
V_27 -> V_298 = F_187 ( V_27 , V_305 ,
V_306 ) ;
if ( ! V_27 -> V_298 ) {
F_58 (KERN_ERR PFX L_46 ) ;
goto V_307;
}
F_125 ( & V_27 -> V_243 ) ;
F_125 ( & V_27 -> V_225 ) ;
F_188 ( & V_27 -> V_308 ) ;
return V_27 ;
V_307:
F_91 ( V_27 -> V_35 ) ;
V_304:
F_181 ( V_27 ) ;
V_302:
F_91 ( V_27 ) ;
return NULL ;
}
struct V_23 * F_189 ( struct V_26 * V_27 ,
struct V_115 * V_93 ,
enum V_309 V_310 )
{
struct V_23 * V_24 ;
int V_18 = 0 ;
V_24 = F_183 ( sizeof( * V_24 ) , V_301 ) ;
if ( ! V_24 ) {
F_58 (KERN_ERR PFX L_47 ) ;
return NULL ;
}
F_190 ( V_93 ) ;
F_191 ( & V_24 -> V_294 ) ;
V_24 -> V_27 = V_27 ;
V_24 -> V_93 = V_93 ;
F_192 ( & V_24 -> V_71 , V_310 ) ;
V_24 -> V_71 . V_311 = F_143 ;
V_24 -> V_71 . V_312 = F_141 ;
V_24 -> V_71 . V_313 = F_142 ;
F_108 ( V_295 , & V_24 -> V_296 ) ;
V_18 = F_159 ( V_24 ) ;
if ( ! V_18 )
return V_24 ;
F_172 ( & V_24 -> V_71 ) ;
F_173 ( V_93 ) ;
F_91 ( V_24 ) ;
return NULL ;
}
static struct V_1 * F_148 ( struct V_23 * V_24 ,
struct V_178 * V_314 , int V_315 )
{
struct V_1 * V_20 , * V_274 ;
struct V_21 * V_22 ;
struct V_151 * V_152 ;
struct V_272 * V_187 = F_193 ( V_314 ) ;
struct V_316 * V_317 ;
struct V_26 * V_27 ;
int V_18 = 0 ;
V_317 = F_183 ( sizeof( struct V_316 ) , V_301 ) ;
if ( ! V_317 ) {
F_28 ( V_24 -> V_71 . V_2 , L_48 ) ;
return NULL ;
}
if ( ! V_315 )
V_20 = F_194 ( & V_318 , sizeof( * V_22 ) ) ;
else
V_20 = F_195 ( V_187 , sizeof( * V_22 ) ) ;
if ( ! V_20 ) {
F_58 (KERN_ERR PFX L_49 ) ;
goto V_319;
}
V_152 = V_20 -> V_179 ;
V_22 = F_13 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
V_22 -> V_25 = V_24 ;
F_196 ( & V_22 -> V_282 , V_320 ) ;
V_18 = F_136 ( V_20 ) ;
if ( V_18 )
goto V_321;
if ( V_315 ) {
F_58 (KERN_ERR PFX L_50 ,
vport->node_name, vport->port_name) ;
F_115 ( V_20 , V_187 -> V_322 ) ;
F_116 ( V_20 , V_187 -> V_323 ) ;
}
V_18 = F_110 ( V_20 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_51 ) ;
goto V_321;
}
V_18 = F_98 ( V_20 , V_314 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_52 ,
interface->netdev->name) ;
goto V_321;
}
V_18 = F_129 ( V_20 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_53 ) ;
goto V_324;
}
F_123 ( V_20 -> V_179 ) = V_240 ;
if ( ! V_315 )
V_18 = F_134 ( V_20 ) ;
else {
V_152 = F_147 ( V_187 ) ;
V_274 = F_93 ( V_152 ) ;
V_18 = F_197 ( V_274 , V_20 ) ;
}
if ( V_18 ) {
F_58 (KERN_ERR PFX L_54 ) ;
goto V_324;
}
F_175 ( V_24 ) ;
V_27 = V_24 -> V_27 ;
F_2 ( & V_27 -> V_33 ) ;
V_317 -> V_20 = V_20 ;
F_198 ( & V_317 -> V_8 , & V_27 -> V_308 ) ;
F_6 ( & V_27 -> V_33 ) ;
return V_20 ;
V_324:
F_199 ( V_152 ) ;
V_321:
F_200 ( V_20 -> V_179 ) ;
V_319:
F_91 ( V_317 ) ;
return NULL ;
}
static void F_201 ( struct V_23 * V_24 )
{
F_202 ( & V_24 -> V_120 ) ;
F_202 ( & V_24 -> V_268 ) ;
F_203 () ;
}
static void F_204 ( struct V_1 * V_20 , struct V_26 * V_27 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_316 * V_317 , * V_146 ;
F_205 ( & V_22 -> V_222 ) ;
F_124 ( V_20 ) ;
F_1 ( V_20 ) ;
F_206 ( V_20 -> V_179 ) ;
F_199 ( V_20 -> V_179 ) ;
F_207 ( V_20 ) ;
F_208 ( V_20 ) ;
F_2 ( & V_27 -> V_33 ) ;
F_88 (blport, tmp, &hba->vports, list) {
if ( V_317 -> V_20 == V_20 ) {
F_155 ( & V_317 -> V_8 ) ;
F_91 ( V_317 ) ;
}
}
F_6 ( & V_27 -> V_33 ) ;
F_200 ( V_20 -> V_179 ) ;
}
static int F_209 ( struct V_115 * V_93 )
{
struct V_23 * V_24 = NULL ;
struct V_26 * V_27 ;
struct V_1 * V_20 ;
int V_18 = 0 ;
F_210 () ;
F_15 ( & V_238 ) ;
V_24 = F_211 ( V_93 ) ;
if ( ! V_24 || ! V_24 -> V_71 . V_2 ) {
V_18 = - V_54 ;
F_58 (KERN_ERR PFX L_55 ) ;
goto V_325;
}
V_27 = V_24 -> V_27 ;
F_201 ( V_24 ) ;
V_20 = V_24 -> V_71 . V_2 ;
F_212 ( V_24 ) ;
F_155 ( & V_24 -> V_8 ) ;
F_213 ( V_24 -> V_326 ) ;
F_177 ( V_24 ) ;
F_204 ( V_20 , V_27 ) ;
V_325:
F_18 ( & V_238 ) ;
F_214 () ;
return V_18 ;
}
static void V_320 ( struct V_327 * V_145 )
{
struct V_21 * V_22 ;
struct V_1 * V_20 ;
struct V_23 * V_24 ;
struct V_26 * V_27 ;
V_22 = F_57 ( V_145 , struct V_21 , V_282 ) ;
V_20 = V_22 -> V_20 ;
V_24 = V_22 -> V_25 ;
V_27 = V_24 -> V_27 ;
F_28 ( V_20 , L_56 ) ;
F_215 ( V_20 ) ;
F_210 () ;
F_15 ( & V_238 ) ;
F_204 ( V_20 , V_27 ) ;
F_18 ( & V_238 ) ;
F_214 () ;
}
static void F_216 ( struct V_26 * V_27 )
{
F_217 ( V_27 ) ;
F_218 ( V_27 ) ;
}
static int F_219 ( struct V_26 * V_27 )
{
if ( F_220 ( V_27 ) )
goto V_328;
if ( F_221 ( V_27 ) )
goto V_328;
return 0 ;
V_328:
F_216 ( V_27 ) ;
return - V_55 ;
}
static int F_186 ( struct V_26 * V_27 )
{
struct V_299 * V_300 ;
if ( ! V_27 -> V_300 ) {
F_58 (KERN_ERR PFX L_57 ) ;
return - V_54 ;
}
V_300 = V_27 -> V_300 ;
V_27 -> V_329 = V_300 -> V_329 ;
if ( V_27 -> V_329 )
F_222 ( V_27 -> V_329 ) ;
return 0 ;
}
static void F_181 ( struct V_26 * V_27 )
{
if ( V_27 -> V_329 )
F_223 ( V_27 -> V_329 ) ;
V_27 -> V_329 = NULL ;
}
static void F_224 ( void * V_330 )
{
struct V_26 * V_27 = V_330 ;
struct V_23 * V_24 ;
struct V_1 * V_20 ;
F_15 ( & V_238 ) ;
if ( ! F_35 ( V_275 , & V_27 -> V_76 ) )
F_225 ( V_27 ) ;
F_14 ( L_58 ) ;
F_120 (interface, &if_list, list) {
if ( V_24 -> V_27 == V_27 ) {
V_20 = V_24 -> V_71 . V_2 ;
F_58 (KERN_ERR PFX L_59 ) ;
V_20 -> V_246 . V_331 = F_26 ;
F_226 ( V_24 ) ;
}
}
F_18 ( & V_238 ) ;
}
static void F_215 ( struct V_1 * V_20 )
{
F_14 ( L_1 , V_31 ) ;
F_158 ( V_20 ) ;
F_227 ( V_20 ) ;
}
static void F_212 ( struct V_23 * V_24 )
{
struct V_1 * V_20 ;
struct V_1 * V_187 ;
if ( ! F_35 ( V_275 , & V_24 -> V_27 -> V_76 ) )
return;
V_20 = V_24 -> V_71 . V_2 ;
F_215 ( V_20 ) ;
F_15 ( & V_20 -> V_239 ) ;
F_120 (vport, &lport->vports, list)
F_123 ( V_187 -> V_179 ) =
V_240 ;
F_18 ( & V_20 -> V_239 ) ;
F_123 ( V_20 -> V_179 ) = V_240 ;
F_122 ( & V_24 -> V_71 ) ;
F_124 ( V_20 ) ;
}
static int F_225 ( struct V_26 * V_27 )
{
#define F_228 (1000 / HZ)
int V_18 = - 1 ;
int V_30 = V_158 ;
V_18 = F_219 ( V_27 ) ;
if ( V_18 ) {
F_58 (KERN_ALERT PFX
L_60 , rc) ;
goto V_332;
}
V_18 = F_229 ( V_27 ) ;
if ( V_18 ) {
F_58 (KERN_ALERT PFX
L_61 , rc) ;
goto V_333;
}
while ( ! F_35 ( V_232 , & V_27 -> V_212 ) && V_30 -- )
F_230 ( F_228 ) ;
if ( ! F_35 ( V_232 , & V_27 -> V_212 ) ) {
F_58 (KERN_ERR PFX L_62
L_63 ,
hba->cnic->netdev->name) ;
V_18 = - 1 ;
goto V_333;
}
F_108 ( V_275 , & V_27 -> V_76 ) ;
return 0 ;
V_333:
F_216 ( V_27 ) ;
V_332:
return V_18 ;
}
static void F_231 ( struct V_26 * V_27 )
{
if ( F_171 ( V_275 , & V_27 -> V_76 ) ) {
if ( F_232 ( V_27 ) == 0 ) {
F_233 ( & V_27 -> V_334 ) ;
V_27 -> V_334 . V_335 = V_336 +
V_279 ;
V_27 -> V_334 . V_337 = F_117 ;
V_27 -> V_334 . V_140 = ( unsigned long ) V_27 ;
F_234 ( & V_27 -> V_334 ) ;
F_126 ( V_27 -> V_225 ,
F_35 ( V_224 ,
& V_27 -> V_76 ) ) ;
if ( F_127 ( V_126 ) )
F_128 ( V_126 ) ;
F_205 ( & V_27 -> V_334 ) ;
}
F_216 ( V_27 ) ;
}
}
static void F_235 ( void * V_330 )
{
struct V_26 * V_27 = V_330 ;
struct V_23 * V_24 ;
F_58 ( V_233 L_64 ) ;
F_15 ( & V_238 ) ;
if ( ! F_35 ( V_275 , & V_27 -> V_76 ) )
goto exit;
F_120 (interface, &if_list, list) {
if ( V_24 -> V_27 == V_27 )
F_212 ( V_24 ) ;
}
F_236 ( V_27 -> V_244 != 0 ) ;
F_15 ( & V_27 -> V_32 ) ;
F_107 ( V_232 , & V_27 -> V_212 ) ;
F_107 ( V_235 ,
& V_27 -> V_212 ) ;
F_107 ( V_242 , & V_27 -> V_212 ) ;
F_18 ( & V_27 -> V_32 ) ;
F_231 ( V_27 ) ;
exit:
F_18 ( & V_238 ) ;
}
static void F_226 ( struct V_23 * V_24 )
{
struct V_1 * V_20 ;
int V_338 = 0 ;
F_14 ( L_1 , V_31 ) ;
if ( ! F_35 ( V_275 , & V_24 -> V_27 -> V_76 ) ) {
F_58 (KERN_ERR PFX L_65 ) ;
return;
}
V_20 = V_24 -> V_71 . V_2 ;
F_28 ( V_20 , L_66 ) ;
if ( ! F_105 ( V_20 ) ) {
F_28 ( V_20 , L_67 ) ;
F_121 ( & V_24 -> V_71 ) ;
F_123 ( V_20 -> V_179 ) = V_339 ;
F_108 ( V_242 , & V_24 -> V_27 -> V_212 ) ;
}
while ( ! V_24 -> V_71 . V_72 ) {
F_230 ( 250 ) ;
if ( ++ V_338 > 12 )
break;
}
F_151 ( V_20 ) ;
F_152 ( V_20 ) ;
}
static void F_237 ( struct V_299 * V_92 )
{
struct V_26 * V_27 ;
int V_18 = 0 ;
F_14 ( L_1 , V_31 ) ;
if ( ! F_35 ( V_340 , & V_92 -> V_76 ) ||
( V_92 -> V_341 == 0 ) ) {
F_58 (KERN_ERR PFX L_68
L_69 ,
dev->netdev->name, dev->flags, dev->max_fcoe_conn) ;
return;
}
V_27 = F_182 ( V_92 ) ;
if ( ! V_27 ) {
F_58 (KERN_ERR PFX L_70 ) ;
return;
}
F_15 ( & V_238 ) ;
F_198 ( & V_27 -> V_8 , & V_342 ) ;
V_343 ++ ;
F_18 ( & V_238 ) ;
F_107 ( V_344 , & V_27 -> V_345 ) ;
V_18 = V_92 -> V_346 ( V_92 , V_347 ,
( void * ) V_27 ) ;
if ( V_18 )
F_58 (KERN_ERR PFX L_71 , rc) ;
else
F_108 ( V_344 , & V_27 -> V_345 ) ;
}
static int F_238 ( struct V_115 * V_93 )
{
struct V_23 * V_24 ;
int V_18 = 0 ;
F_210 () ;
F_15 ( & V_238 ) ;
V_24 = F_211 ( V_93 ) ;
if ( ! V_24 || ! V_24 -> V_71 . V_2 ) {
V_18 = - V_54 ;
F_58 (KERN_ERR PFX L_72 ) ;
} else {
F_122 ( & V_24 -> V_71 ) ;
F_124 ( V_24 -> V_71 . V_2 ) ;
}
F_18 ( & V_238 ) ;
F_214 () ;
return V_18 ;
}
static int F_239 ( struct V_115 * V_93 )
{
struct V_23 * V_24 ;
int V_18 = 0 ;
F_210 () ;
F_15 ( & V_238 ) ;
V_24 = F_211 ( V_93 ) ;
if ( ! V_24 || ! V_24 -> V_71 . V_2 ) {
V_18 = - V_54 ;
F_58 (KERN_ERR PFX L_73 ) ;
} else if ( ! F_105 ( V_24 -> V_71 . V_2 ) )
F_121 ( & V_24 -> V_71 ) ;
F_18 ( & V_238 ) ;
F_214 () ;
return V_18 ;
}
static int F_240 ( struct V_115 * V_93 , enum V_309 V_310 )
{
struct V_23 * V_24 ;
struct V_26 * V_27 ;
struct V_115 * V_209 ;
struct V_1 * V_20 ;
struct V_348 V_349 ;
int V_18 = 0 ;
int V_228 ;
F_14 ( L_74 ) ;
if ( V_310 != V_350 ) {
F_58 ( V_233 L_75 ) ;
return - V_276 ;
}
F_210 () ;
F_15 ( & V_238 ) ;
if ( ! F_241 ( V_297 ) ) {
V_18 = - V_73 ;
goto V_351;
}
if ( V_93 -> V_352 & V_353 ) {
V_209 = F_242 ( V_93 ) ;
V_228 = F_243 ( V_93 ) ;
} else {
F_58 (KERN_ERR PFX L_76 ) ;
V_18 = - V_73 ;
goto V_325;
}
if ( V_209 -> V_217 && V_209 -> V_217 -> V_354 ) {
memset ( & V_349 , 0 , sizeof( V_349 ) ) ;
V_209 -> V_217 -> V_354 ( V_209 , & V_349 ) ;
if ( strncmp ( V_349 . V_355 , L_77 , strlen ( L_77 ) ) ) {
F_58 (KERN_ERR PFX L_78 ) ;
V_18 = - V_73 ;
goto V_325;
}
} else {
F_58 (KERN_ERR PFX L_79 ) ;
V_18 = - V_73 ;
goto V_325;
}
V_27 = F_244 ( V_209 ) ;
if ( ! V_27 ) {
V_18 = - V_54 ;
F_58 (KERN_ERR PFX L_80 ) ;
goto V_325;
}
if ( F_211 ( V_93 ) ) {
V_18 = - V_356 ;
goto V_325;
}
V_24 = F_189 ( V_27 , V_93 , V_310 ) ;
if ( ! V_24 ) {
F_58 (KERN_ERR PFX L_81 ) ;
goto V_357;
}
V_24 -> V_228 = V_228 ;
V_24 -> V_358 = 1 ;
V_24 -> V_326 =
F_245 ( L_82 ) ;
if ( ! V_24 -> V_326 ) {
F_58 (KERN_ERR PFX L_83 ) ;
V_18 = - V_73 ;
goto V_357;
}
V_20 = F_148 ( V_24 , & V_24 -> V_27 -> V_329 -> V_92 , 0 ) ;
if ( ! V_20 ) {
F_58 (KERN_ERR PFX L_84 ,
netdev->name) ;
F_201 ( V_24 ) ;
V_18 = - V_73 ;
goto V_359;
}
F_198 ( & V_24 -> V_8 , & V_360 ) ;
V_20 -> V_278 = V_279 ;
V_24 -> V_71 . V_2 = V_20 ;
F_28 ( V_20 , L_85 ) ;
F_226 ( V_24 ) ;
F_177 ( V_24 ) ;
F_18 ( & V_238 ) ;
F_214 () ;
return 0 ;
V_359:
F_213 ( V_24 -> V_326 ) ;
V_357:
F_177 ( V_24 ) ;
V_325:
F_174 ( V_297 ) ;
V_351:
F_18 ( & V_238 ) ;
F_214 () ;
return V_18 ;
}
static struct V_26 * F_246 ( struct V_299 * V_300 )
{
struct V_361 * V_8 ;
struct V_361 * V_362 ;
struct V_26 * V_27 ;
F_247 (list, temp, &adapter_list) {
V_27 = (struct V_26 * ) V_8 ;
if ( V_27 -> V_300 == V_300 )
return V_27 ;
}
return NULL ;
}
static struct V_23 * F_211 ( struct V_115
* V_93 )
{
struct V_23 * V_24 ;
F_120 (interface, &if_list, list) {
if ( V_24 -> V_93 == V_93 )
return V_24 ;
}
return NULL ;
}
static struct V_26 * F_244 ( struct V_115
* V_209 )
{
struct V_26 * V_27 ;
F_120 (hba, &adapter_list, list) {
if ( V_27 -> V_209 == V_209 )
return V_27 ;
}
F_58 (KERN_ERR PFX L_86 ) ;
return NULL ;
}
static void F_248 ( struct V_299 * V_92 )
{
struct V_26 * V_27 ;
struct V_23 * V_24 , * V_146 ;
struct V_1 * V_20 ;
F_14 ( L_87 ) ;
if ( ! F_35 ( V_340 , & V_92 -> V_76 ) ) {
F_58 (KERN_ERR PFX L_88 ,
dev->netdev->name, dev->flags) ;
return;
}
F_15 ( & V_238 ) ;
V_27 = F_246 ( V_92 ) ;
if ( ! V_27 ) {
F_58 (KERN_ERR PFX L_89 ,
dev) ;
F_18 ( & V_238 ) ;
return;
}
F_89 ( & V_27 -> V_8 ) ;
V_343 -- ;
F_88 (interface, tmp, &if_list, list) {
if ( V_24 -> V_27 == V_27 ) {
F_201 ( V_24 ) ;
F_212 ( V_24 ) ;
F_155 ( & V_24 -> V_8 ) ;
V_20 = V_24 -> V_71 . V_2 ;
F_177 ( V_24 ) ;
F_204 ( V_20 , V_27 ) ;
}
}
F_18 ( & V_238 ) ;
F_235 ( V_27 ) ;
if ( F_171 ( V_344 , & V_27 -> V_345 ) )
V_27 -> V_300 -> V_363 ( V_27 -> V_300 , V_347 ) ;
F_179 ( V_27 ) ;
}
static int F_249 ( struct V_151 * V_152 )
{
struct V_1 * V_20 = F_93 ( V_152 ) ;
F_250 ( V_20 ) ;
return 0 ;
}
static bool F_251 ( struct V_115 * V_93 )
{
F_15 ( & V_238 ) ;
if ( V_93 -> V_352 & V_353 ) {
struct V_115 * V_209 = F_242 ( V_93 ) ;
if ( F_244 ( V_209 ) ) {
F_18 ( & V_238 ) ;
return true ;
}
}
F_18 ( & V_238 ) ;
return false ;
}
static void F_252 ( unsigned int V_364 )
{
struct V_142 * V_143 ;
struct V_365 * V_124 ;
V_143 = & F_253 ( V_366 , V_364 ) ;
V_124 = F_254 ( F_84 ,
( void * ) V_143 ,
L_90 , V_364 ) ;
if ( F_255 ( ! F_149 ( V_143 -> V_367 ) ) ) {
F_256 ( V_124 , V_364 ) ;
V_143 -> V_367 = V_124 ;
F_63 ( V_124 ) ;
}
}
static void F_257 ( unsigned int V_364 )
{
struct V_142 * V_143 ;
struct V_365 * V_124 ;
struct V_144 * V_145 , * V_146 ;
F_85 ( V_147 ) ;
F_14 ( L_91 , V_364 ) ;
V_143 = & F_253 ( V_366 , V_364 ) ;
F_2 ( & V_143 -> V_148 ) ;
V_124 = V_143 -> V_367 ;
V_143 -> V_367 = NULL ;
F_88 (work, tmp, &work_list, list) {
F_89 ( & V_145 -> V_8 ) ;
F_90 ( V_145 -> V_29 , V_145 -> V_149 ) ;
F_91 ( V_145 ) ;
}
F_6 ( & V_143 -> V_148 ) ;
if ( V_124 )
F_258 ( V_124 ) ;
}
static int F_259 ( struct V_368 * V_369 ,
unsigned long V_370 , void * V_371 )
{
unsigned V_364 = ( unsigned long ) V_371 ;
switch ( V_370 ) {
case V_372 :
case V_373 :
F_58 ( V_374 L_92 , V_364 ) ;
F_252 ( V_364 ) ;
break;
case V_375 :
case V_376 :
F_58 ( V_374 L_93 , V_364 ) ;
F_257 ( V_364 ) ;
break;
default:
break;
}
return V_377 ;
}
static int T_6 F_260 ( void )
{
struct V_3 * V_4 ;
struct V_365 * V_378 ;
int V_18 = 0 ;
unsigned int V_364 = 0 ;
struct V_142 * V_143 ;
F_58 (KERN_INFO PFX L_94 , version) ;
V_18 = F_261 ( & V_379 ) ;
if ( V_18 ) {
F_58 ( V_233 L_95
L_96 ) ;
goto V_380;
}
F_188 ( & V_342 ) ;
F_188 ( & V_360 ) ;
F_185 ( & V_238 ) ;
V_343 = 0 ;
V_18 = F_166 () ;
if ( V_18 )
goto V_381;
V_281 = F_262 ( L_97 , 0 , 0 ) ;
if ( ! V_281 ) {
V_18 = - V_55 ;
goto V_382;
}
V_4 = & V_13 ;
F_112 ( & V_4 -> V_14 ) ;
V_378 = F_254 ( F_64 ,
( void * ) V_4 ,
L_98 ) ;
if ( F_149 ( V_378 ) ) {
V_18 = F_263 ( V_378 ) ;
goto V_383;
}
F_63 ( V_378 ) ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
V_4 -> V_124 = V_378 ;
F_6 ( & V_4 -> V_14 . V_15 ) ;
F_264 (cpu) {
V_143 = & F_253 ( V_366 , V_364 ) ;
F_188 ( & V_143 -> V_147 ) ;
F_184 ( & V_143 -> V_148 ) ;
}
F_265 (cpu) {
F_252 ( V_364 ) ;
}
F_266 ( & V_384 ) ;
F_267 ( V_347 , & V_385 ) ;
return 0 ;
V_383:
F_213 ( V_281 ) ;
V_382:
F_169 () ;
V_381:
F_268 ( & V_379 ) ;
V_380:
return V_18 ;
}
static void T_7 F_269 ( void )
{
F_85 ( V_386 ) ;
struct V_26 * V_27 , * V_11 ;
struct V_3 * V_4 ;
struct V_365 * V_378 ;
struct V_9 * V_10 ;
unsigned int V_364 = 0 ;
F_15 ( & V_238 ) ;
F_270 ( & V_342 , & V_386 ) ;
F_188 ( & V_342 ) ;
V_343 = 0 ;
F_18 ( & V_238 ) ;
F_88 (hba, next, &to_be_deleted, list) {
F_89 ( & V_27 -> V_8 ) ;
F_58 (KERN_ERR PFX L_99 ,
hba) ;
F_235 ( V_27 ) ;
if ( F_171 ( V_344 ,
& V_27 -> V_345 ) )
V_27 -> V_300 -> V_363 ( V_27 -> V_300 ,
V_347 ) ;
F_179 ( V_27 ) ;
}
F_271 ( V_347 ) ;
V_4 = & V_13 ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
V_378 = V_4 -> V_124 ;
V_4 -> V_124 = NULL ;
while ( ( V_10 = F_69 ( & V_4 -> V_14 ) ) != NULL )
F_5 ( V_10 ) ;
F_6 ( & V_4 -> V_14 . V_15 ) ;
if ( V_378 )
F_258 ( V_378 ) ;
F_272 ( & V_384 ) ;
F_265 (cpu) {
F_257 ( V_364 ) ;
}
F_213 ( V_281 ) ;
F_169 () ;
F_268 ( & V_379 ) ;
}
