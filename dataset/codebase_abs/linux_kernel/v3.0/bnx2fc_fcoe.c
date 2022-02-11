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
struct V_26 * V_27 ;
int V_28 ;
F_14 ( L_1 , V_29 ) ;
F_15 ( & V_24 -> V_30 ) ;
F_2 ( & V_24 -> V_31 ) ;
for ( V_28 = 0 ; V_28 < V_32 ; V_28 ++ ) {
V_27 = V_24 -> V_33 [ V_28 ] ;
if ( V_27 ) {
if ( V_27 -> V_22 == V_22 ) {
F_6 ( & V_24 -> V_31 ) ;
F_16 ( V_27 , L_2 ) ;
F_17 ( V_27 ) ;
F_2 ( & V_24 -> V_31 ) ;
}
}
}
F_6 ( & V_24 -> V_31 ) ;
F_18 ( & V_24 -> V_30 ) ;
}
static int F_19 ( struct V_26 * V_27 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 = V_27 -> V_37 ;
struct V_38 * V_39 ;
int V_18 = 0 ;
V_39 = F_20 ( V_35 ) ;
F_16 ( V_27 , L_3
L_4 , V_37 -> V_40 . V_41 ,
F_21 ( V_39 -> V_42 ) , V_39 -> V_43 ) ;
if ( ( V_39 -> V_44 == V_45 ) &&
( V_39 -> V_43 == V_46 ) ) {
switch ( F_22 ( V_35 ) ) {
case V_47 :
V_18 = F_23 ( V_27 , V_35 ) ;
break;
case V_48 :
V_18 = F_24 ( V_27 , V_35 ) ;
break;
case V_49 :
V_18 = F_25 ( V_27 , V_35 ) ;
break;
default:
break;
}
} else if ( ( V_39 -> V_44 == V_50 ) &&
( V_39 -> V_43 == V_51 ) )
F_16 ( V_27 , L_5 ) ;
else {
F_16 ( V_27 , L_6
L_7 ,
V_39 -> V_44 , V_39 -> V_43 ) ;
return - V_52 ;
}
if ( V_18 )
return - V_53 ;
else
return 0 ;
}
static int F_26 ( struct V_1 * V_20 , struct V_34 * V_35 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_9 * V_10 ;
struct V_38 * V_39 ;
struct V_23 * V_24 ;
struct V_21 * V_22 ;
struct V_58 * V_59 ;
struct V_26 * V_27 ;
struct V_60 * V_61 ;
T_1 V_62 , V_63 ;
T_2 V_64 ;
unsigned int V_65 , V_17 , V_66 ;
int V_67 , V_18 = 0 ;
V_22 = (struct V_21 * ) F_13 ( V_20 ) ;
V_24 = V_22 -> V_25 ;
V_39 = F_20 ( V_35 ) ;
V_10 = F_27 ( V_35 ) ;
if ( ! V_20 -> V_68 ) {
F_28 ( V_20 , L_8 ) ;
F_5 ( V_10 ) ;
return 0 ;
}
if ( F_29 ( V_39 -> V_43 == V_46 ) ) {
if ( ! V_24 -> V_69 . V_70 ) {
F_28 ( V_20 , L_9 ) ;
F_5 ( V_10 ) ;
return - V_71 ;
}
if ( F_30 ( & V_24 -> V_69 , V_20 , V_10 ) )
return 0 ;
}
V_62 = F_31 ( V_35 ) ;
V_63 = F_32 ( V_35 ) ;
F_2 ( & V_24 -> V_31 ) ;
V_27 = F_33 ( V_22 , F_34 ( V_39 -> V_72 ) ) ;
if ( V_27 && ( F_35 ( V_73 , & V_27 -> V_74 ) ) ) {
F_28 ( V_20 , L_10
L_11 , F_34 ( V_39 -> V_72 ) ) ;
F_6 ( & V_24 -> V_31 ) ;
V_18 = F_19 ( V_27 , V_35 ) ;
if ( V_18 != - V_52 ) {
F_5 ( V_10 ) ;
return V_18 ;
}
} else {
F_6 ( & V_24 -> V_31 ) ;
}
V_66 = sizeof( struct V_54 ) ;
V_65 = sizeof( struct V_58 ) ;
V_17 = sizeof( struct V_56 ) ;
V_67 = ( V_10 -> V_75 - V_17 + sizeof( V_64 ) ) / V_76 ;
V_10 -> V_77 = V_78 ;
V_64 = F_36 ( V_35 ) ;
if ( F_37 ( V_10 ) ) {
T_3 * V_79 ;
if ( F_7 ( V_10 , V_17 ) ) {
F_5 ( V_10 ) ;
return - V_53 ;
}
V_79 = & F_38 ( V_10 ) -> V_80 [ F_38 ( V_10 ) -> V_81 - 1 ] ;
V_57 = F_39 ( V_79 -> V_82 , V_83 )
+ V_79 -> V_84 ;
} else {
V_57 = (struct V_56 * ) F_40 ( V_10 , V_17 ) ;
}
memset ( V_57 , 0 , sizeof( * V_57 ) ) ;
V_57 -> V_85 = V_63 ;
V_57 -> V_86 = F_41 ( ~ V_64 ) ;
if ( F_37 ( V_10 ) ) {
F_42 ( V_57 , V_83 ) ;
V_57 = NULL ;
}
F_43 ( V_10 , V_66 + V_65 ) ;
F_44 ( V_10 ) ;
F_45 ( V_10 ) ;
V_10 -> V_87 = V_66 ;
V_10 -> V_88 = F_46 ( V_89 ) ;
V_10 -> V_90 = V_24 -> V_91 ;
V_55 = F_47 ( V_10 ) ;
V_55 -> V_92 = F_46 ( V_89 ) ;
if ( V_24 -> V_69 . V_93 )
F_48 ( V_55 -> V_94 , V_39 -> V_72 ) ;
else
memcpy ( V_55 -> V_94 , V_24 -> V_69 . V_95 , V_96 ) ;
if ( F_29 ( V_24 -> V_69 . V_97 != V_98 ) )
memcpy ( V_55 -> V_99 , V_24 -> V_69 . V_100 , V_96 ) ;
else
memcpy ( V_55 -> V_99 , V_22 -> V_101 , V_96 ) ;
V_59 = (struct V_58 * ) ( V_55 + 1 ) ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
if ( V_102 )
F_49 ( V_59 , V_102 ) ;
V_59 -> V_103 = V_62 ;
if ( V_20 -> V_104 && F_50 ( V_35 ) ) {
F_38 ( V_10 ) -> V_105 = V_106 ;
F_38 ( V_10 ) -> V_107 = F_50 ( V_35 ) ;
} else {
F_38 ( V_10 ) -> V_105 = 0 ;
F_38 ( V_10 ) -> V_107 = 0 ;
}
V_61 = F_51 ( V_20 -> V_108 , F_52 () ) ;
V_61 -> V_109 ++ ;
V_61 -> V_110 += V_67 ;
F_53 () ;
V_16 ( V_35 ) = V_20 ;
if ( V_22 -> V_111 . V_112 )
F_54 ( V_20 , V_10 ) ;
else if ( F_55 ( V_10 ) )
F_54 ( V_20 , V_10 ) ;
return 0 ;
}
static int F_56 ( struct V_9 * V_10 , struct V_113 * V_90 ,
struct V_114 * V_115 , struct V_113 * V_116 )
{
struct V_1 * V_20 ;
struct V_23 * V_24 ;
struct V_38 * V_39 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
unsigned short V_117 ;
V_24 = F_57 ( V_115 , struct V_23 , V_118 ) ;
V_20 = V_24 -> V_69 . V_2 ;
if ( F_29 ( V_20 == NULL ) ) {
F_58 (KERN_ALERT PFX L_12 ) ;
goto V_119;
}
if ( F_29 ( F_47 ( V_10 ) -> V_92 != F_46 ( V_89 ) ) ) {
F_58 (KERN_ALERT PFX L_13 ) ;
goto V_119;
}
if ( F_29 ( ( V_10 -> V_75 < V_120 ) ||
! F_59 ( V_10 , V_121 ) ) )
goto V_119;
F_60 ( V_10 , sizeof( struct V_58 ) ) ;
V_39 = (struct V_38 * ) F_61 ( V_10 ) ;
V_117 = F_21 ( V_39 -> V_42 ) ;
V_6 = F_3 ( V_10 ) ;
V_6 -> V_16 = V_20 ;
V_6 -> V_115 = V_115 ;
V_4 = & V_13 ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
F_62 ( & V_4 -> V_14 , V_10 ) ;
if ( V_4 -> V_14 . V_112 == 1 )
F_63 ( V_4 -> V_122 ) ;
F_6 ( & V_4 -> V_14 . V_15 ) ;
return 0 ;
V_119:
F_5 ( V_10 ) ;
return - 1 ;
}
static int F_64 ( void * V_123 )
{
struct V_3 * V_4 = V_123 ;
struct V_9 * V_10 ;
F_65 ( V_124 , - 20 ) ;
F_66 ( V_125 ) ;
while ( ! F_67 () ) {
F_68 () ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
while ( ( V_10 = F_69 ( & V_4 -> V_14 ) ) != NULL ) {
F_6 ( & V_4 -> V_14 . V_15 ) ;
F_70 ( V_10 ) ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
}
F_71 ( V_125 ) ;
F_6 ( & V_4 -> V_14 . V_15 ) ;
}
F_71 ( V_126 ) ;
return 0 ;
}
static void F_70 ( struct V_9 * V_10 )
{
T_2 V_127 ;
struct V_1 * V_20 ;
struct V_5 * V_6 ;
struct V_60 * V_61 ;
struct V_38 * V_39 ;
struct V_56 V_128 ;
struct V_34 * V_35 ;
struct V_1 * V_129 ;
struct V_21 * V_22 ;
T_1 * V_130 = NULL ;
T_1 * V_131 = NULL ;
struct V_58 * V_59 ;
V_6 = F_3 ( V_10 ) ;
V_20 = V_6 -> V_16 ;
if ( F_29 ( V_20 == NULL ) ) {
F_58 (KERN_ALERT PFX L_14 ) ;
F_5 ( V_10 ) ;
return;
}
if ( F_37 ( V_10 ) )
F_72 ( V_10 ) ;
V_130 = F_47 ( V_10 ) -> V_99 ;
V_131 = F_47 ( V_10 ) -> V_94 ;
V_59 = (struct V_58 * ) F_73 ( V_10 ) ;
V_39 = (struct V_38 * ) F_61 ( V_10 ) ;
F_74 ( V_10 , sizeof( struct V_58 ) ) ;
V_127 = V_10 -> V_75 - sizeof( struct V_56 ) ;
V_61 = F_51 ( V_20 -> V_108 , F_52 () ) ;
V_61 -> V_132 ++ ;
V_61 -> V_133 += V_127 / V_76 ;
V_35 = (struct V_34 * ) V_10 ;
F_75 ( V_35 ) ;
V_16 ( V_35 ) = V_20 ;
F_31 ( V_35 ) = V_59 -> V_103 ;
if ( F_76 ( V_10 , V_127 , & V_128 , sizeof( V_128 ) ) ) {
F_53 () ;
F_5 ( V_10 ) ;
return;
}
F_32 ( V_35 ) = V_128 . V_85 ;
F_77 ( V_35 ) = V_128 . V_86 ;
if ( F_78 ( V_10 , V_127 ) ) {
F_53 () ;
F_5 ( V_10 ) ;
return;
}
V_39 = F_20 ( V_35 ) ;
V_129 = F_79 ( V_20 , F_34 ( V_39 -> V_72 ) ) ;
if ( V_129 ) {
V_22 = F_13 ( V_129 ) ;
if ( F_80 ( V_22 -> V_101 , V_131 )
!= 0 ) {
F_28 ( V_20 , L_15 ) ;
F_53 () ;
F_5 ( V_10 ) ;
return;
}
}
if ( V_39 -> V_43 == V_134 &&
V_39 -> V_44 == V_135 ) {
F_53 () ;
F_5 ( V_10 ) ;
return;
}
if ( V_39 -> V_43 == V_46 &&
V_39 -> V_44 == V_45 ) {
switch ( F_22 ( V_35 ) ) {
case V_48 :
if ( F_34 ( V_39 -> V_136 ) == V_137 ) {
F_53 () ;
F_5 ( V_10 ) ;
return;
}
break;
}
}
if ( F_81 ( F_77 ( V_35 ) ) !=
~ F_82 ( ~ 0 , V_10 -> V_138 , V_127 ) ) {
if ( V_61 -> V_139 < 5 )
F_58 (KERN_WARNING PFX L_16
L_17 ) ;
V_61 -> V_139 ++ ;
F_53 () ;
F_5 ( V_10 ) ;
return;
}
F_53 () ;
F_83 ( V_20 , V_35 ) ;
}
int F_84 ( void * V_123 )
{
struct V_140 * V_141 = V_123 ;
struct V_142 * V_143 , * V_144 ;
F_85 ( V_145 ) ;
F_65 ( V_124 , - 20 ) ;
F_66 ( V_125 ) ;
while ( ! F_67 () ) {
F_68 () ;
F_2 ( & V_141 -> V_146 ) ;
while ( ! F_86 ( & V_141 -> V_145 ) ) {
F_87 ( & V_141 -> V_145 , & V_145 ) ;
F_6 ( & V_141 -> V_146 ) ;
F_88 (work, tmp, &work_list, list) {
F_89 ( & V_143 -> V_8 ) ;
F_90 ( V_143 -> V_27 , V_143 -> V_147 ) ;
F_91 ( V_143 ) ;
}
F_2 ( & V_141 -> V_146 ) ;
}
F_71 ( V_125 ) ;
F_6 ( & V_141 -> V_146 ) ;
}
F_71 ( V_126 ) ;
return 0 ;
}
static struct V_148 * F_92 ( struct V_149 * V_150 )
{
struct V_148 * V_151 ;
struct V_1 * V_20 = F_93 ( V_150 ) ;
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_152 * V_153 ;
int V_18 = 0 ;
V_153 = (struct V_152 * ) V_24 -> V_154 ;
if ( ! V_153 )
return NULL ;
V_151 = F_94 ( V_150 ) ;
F_95 ( & V_24 -> V_155 ) ;
if ( F_96 ( V_24 ) )
return V_151 ;
V_18 = F_97 ( & V_24 -> V_155 , ( 2 * V_156 ) ) ;
if ( ! V_18 ) {
F_28 ( V_20 , L_18 ) ;
return V_151 ;
}
V_151 -> V_157 += V_153 -> V_158 . V_159 ;
V_151 -> V_160 += V_153 -> V_161 . V_162 ;
V_151 -> V_163 += ( V_153 -> V_161 . V_164 ) / 4 ;
V_151 -> V_165 += V_153 -> V_166 . V_167 ;
V_151 -> V_168 += ( V_153 -> V_166 . V_169 ) / 4 ;
V_151 -> V_170 = 0 ;
V_151 -> V_171 = 0 ;
V_151 -> V_172 = 0 ;
V_151 -> V_173 = 0 ;
V_151 -> V_174 = 0 ;
V_151 -> V_175 = 0 ;
return V_151 ;
}
static int F_98 ( struct V_1 * V_20 , struct V_176 * V_90 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_149 * V_150 = V_20 -> V_177 ;
int V_18 = 0 ;
V_150 -> V_178 = V_179 ;
V_150 -> V_180 = V_181 ;
V_150 -> V_182 = V_183 ;
V_150 -> V_184 = 0 ;
if ( V_20 -> V_185 )
V_150 -> V_186 = V_187 ;
else
V_150 -> V_186 = V_188 ;
V_18 = F_99 ( V_20 -> V_177 , V_90 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_19 ) ;
return V_18 ;
}
if ( ! V_20 -> V_185 )
F_100 ( V_20 -> V_177 ) = V_189 ;
sprintf ( F_101 ( V_20 -> V_177 ) , L_20 ,
V_190 , V_191 ,
V_24 -> V_91 -> V_192 ) ;
return 0 ;
}
static void F_102 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_113 * V_91 = V_24 -> V_91 ;
struct V_193 V_194 ;
if ( ! F_103 ( V_91 , & V_194 ) ) {
V_20 -> V_195 &=
~ ( V_196 | V_197 ) ;
if ( V_194 . V_198 & ( V_199 |
V_200 ) )
V_20 -> V_195 |= V_196 ;
if ( V_194 . V_198 & V_201 )
V_20 -> V_195 |= V_197 ;
switch ( F_104 ( & V_194 ) ) {
case V_202 :
V_20 -> V_203 = V_196 ;
break;
case V_204 :
V_20 -> V_203 = V_197 ;
break;
}
}
}
static int F_105 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_113 * V_90 = V_24 -> V_205 ;
int V_18 = 0 ;
if ( ( V_90 -> V_74 & V_206 ) && F_106 ( V_90 ) )
F_107 ( V_207 , & V_24 -> V_208 ) ;
else {
F_108 ( V_207 , & V_24 -> V_208 ) ;
V_18 = - 1 ;
}
return V_18 ;
}
void F_109 ( struct V_23 * V_24 )
{
if ( F_35 ( V_209 , & V_24 -> V_91 -> V_210 ) )
F_108 ( V_207 , & V_24 -> V_208 ) ;
else
F_107 ( V_207 , & V_24 -> V_208 ) ;
}
static int F_110 ( struct V_1 * V_20 )
{
struct V_23 * V_24 ;
struct V_21 * V_22 ;
T_4 V_211 , V_212 ;
V_22 = F_13 ( V_20 ) ;
V_24 = V_22 -> V_25 ;
if ( ! V_24 -> V_205 -> V_213 ||
! V_24 -> V_205 -> V_213 -> V_214 )
return - V_215 ;
if ( F_111 ( V_20 , V_216 ) )
return - V_71 ;
F_112 ( & V_22 -> V_111 ) ;
V_22 -> V_217 = 0 ;
F_113 ( & V_22 -> V_218 , V_219 , ( unsigned long ) V_20 ) ;
F_102 ( V_20 ) ;
if ( ! V_20 -> V_185 ) {
V_211 = F_114 ( V_24 -> V_69 . V_100 , 1 , 0 ) ;
F_28 ( V_20 , L_21 , V_211 ) ;
F_115 ( V_20 , V_211 ) ;
V_212 = F_114 ( V_24 -> V_69 . V_100 , 2 , 0 ) ;
F_28 ( V_20 , L_22 , V_212 ) ;
F_116 ( V_20 , V_212 ) ;
}
return 0 ;
}
static void F_117 ( unsigned long V_138 )
{
struct V_23 * V_24 = (struct V_23 * ) V_138 ;
F_28 ( V_24 -> V_69 . V_2 , L_23
L_24 ) ;
V_24 -> V_74 |= V_220 ;
F_118 ( & V_24 -> V_221 ) ;
}
static void F_119 ( void * V_222 , unsigned long V_223 )
{
struct V_23 * V_24 = (struct V_23 * ) V_222 ;
struct V_1 * V_20 = V_24 -> V_69 . V_2 ;
struct V_1 * V_185 ;
T_2 V_224 = 1 ;
if ( ! F_35 ( V_225 , & V_24 -> V_226 ) ) {
F_14 ( L_25 ,
V_24 -> V_91 -> V_192 , V_223 ) ;
return;
}
F_120 ( ! V_20 ) ;
F_28 ( V_20 , L_26 ,
V_24 -> V_91 -> V_192 , V_223 ) ;
switch ( V_223 ) {
case V_227 :
F_28 ( V_20 , L_27 ,
V_24 -> V_208 ) ;
if ( ! F_35 ( V_228 , & V_24 -> V_208 ) )
F_58 ( V_229 L_28\
L_29 ) ;
break;
case V_230 :
F_28 ( V_20 , L_30 ) ;
F_107 ( V_231 , & V_24 -> V_208 ) ;
F_107 ( V_228 , & V_24 -> V_208 ) ;
V_224 = 0 ;
break;
case V_232 :
F_28 ( V_20 , L_31 ) ;
F_108 ( V_231 , & V_24 -> V_208 ) ;
V_224 = 0 ;
break;
case V_233 :
F_28 ( V_20 , L_32 ) ;
break;
default:
F_58 (KERN_ERR PFX L_33 , event) ;
return;
}
F_102 ( V_20 ) ;
if ( V_224 && ! F_105 ( V_20 ) ) {
F_58 ( V_229 L_34 ) ;
F_121 ( & V_24 -> V_69 ) ;
} else {
F_58 ( V_229 L_35 ) ;
if ( F_122 ( & V_24 -> V_69 ) ) {
F_107 ( V_234 , & V_24 -> V_208 ) ;
F_15 ( & V_20 -> V_235 ) ;
F_123 (vport, &lport->vports, list)
F_124 ( V_185 -> V_177 ) =
V_236 ;
F_18 ( & V_20 -> V_235 ) ;
F_124 ( V_20 -> V_177 ) = V_236 ;
F_51 ( V_20 -> V_108 ,
F_52 () ) -> V_237 ++ ;
F_53 () ;
F_125 ( V_20 ) ;
F_126 ( & V_24 -> V_238 ) ;
F_28 ( V_20 , L_36
L_37 ,
V_24 -> V_239 ) ;
V_24 -> V_240 = 1 ;
F_28 ( V_20 , L_38
L_39 ,
V_124 -> V_241 ) ;
F_127 ( V_24 -> V_238 ,
( V_24 -> V_239 == 0 ) ) ;
F_28 ( V_20 , L_40 ,
V_24 -> V_239 ) ;
V_24 -> V_240 = 0 ;
if ( F_128 ( V_124 ) )
F_129 ( V_124 ) ;
}
}
}
static int F_130 ( struct V_1 * V_20 )
{
memcpy ( & V_20 -> V_242 , & V_243 ,
sizeof( struct V_244 ) ) ;
F_131 ( V_20 ) ;
F_132 ( V_20 ) ;
F_133 ( V_20 ) ;
F_134 ( V_20 ) ;
return 0 ;
}
static int F_135 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
if ( ! F_136 ( V_20 , V_245 , V_246 ,
V_247 , NULL ) ) {
F_58 (KERN_ERR PFX L_41 ) ;
return - V_53 ;
}
V_24 -> V_248 = F_137 ( V_24 , V_249 ,
V_250 ) ;
if ( ! V_24 -> V_248 ) {
F_58 (KERN_ERR PFX L_42 ) ;
F_138 ( V_20 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_139 ( struct V_1 * V_20 )
{
V_20 -> V_68 = 0 ;
V_20 -> V_251 = 0 ;
V_20 -> V_252 = 3 ;
V_20 -> V_253 = 3 ;
V_20 -> V_254 = 2 * 1000 ;
V_20 -> V_255 = 10 * 1000 ;
V_20 -> V_256 = ( V_257 | V_258 ) ;
V_20 -> V_259 = 1 ;
memset ( & V_20 -> V_260 , 0 , sizeof( struct V_261 ) ) ;
V_20 -> V_260 . V_262 = V_263 ;
if ( F_140 ( V_20 ) )
return - V_53 ;
F_141 ( V_20 ) ;
return 0 ;
}
static int F_142 ( struct V_9 * V_10 , struct V_113 * V_90 ,
struct V_114 * V_115 ,
struct V_113 * V_264 )
{
struct V_23 * V_24 ;
V_24 = F_57 ( V_115 , struct V_23 , V_265 ) ;
F_143 ( & V_24 -> V_69 , V_10 ) ;
return 0 ;
}
static void F_144 ( struct V_1 * V_20 , T_1 * V_266 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
memcpy ( V_22 -> V_101 , V_266 , V_96 ) ;
}
static T_1 * F_145 ( struct V_1 * V_20 )
{
struct V_21 * V_22 ;
V_22 = (struct V_21 * ) F_13 ( V_20 ) ;
return V_22 -> V_101 ;
}
static void F_146 ( struct V_267 * V_268 , struct V_9 * V_10 )
{
V_10 -> V_90 = F_147 ( V_268 ) -> V_91 ;
F_148 ( V_10 ) ;
}
static int F_149 ( struct V_269 * V_185 , bool V_270 )
{
struct V_149 * V_150 = F_150 ( V_185 ) ;
struct V_1 * V_271 = F_93 ( V_150 ) ;
struct V_21 * V_22 = F_13 ( V_271 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
struct V_113 * V_91 = V_24 -> V_91 ;
struct V_1 * V_129 ;
if ( ! F_35 ( V_272 , & V_24 -> V_226 ) ) {
F_58 (KERN_ERR PFX L_43
L_44 ) ;
return - V_273 ;
}
F_15 ( & V_274 ) ;
V_129 = F_151 ( V_24 , & V_185 -> V_90 , 1 ) ;
F_18 ( & V_274 ) ;
if ( F_152 ( V_129 ) ) {
F_58 (KERN_ERR PFX L_45 ,
netdev->name) ;
return - V_273 ;
}
if ( V_270 ) {
F_153 ( V_185 , V_275 ) ;
} else {
V_129 -> V_276 = V_277 ;
F_154 ( V_129 ) ;
F_155 ( V_129 ) ;
F_156 ( V_129 ) ;
}
return 0 ;
}
static int F_157 ( struct V_269 * V_185 )
{
struct V_149 * V_150 = F_150 ( V_185 ) ;
struct V_1 * V_271 = F_93 ( V_150 ) ;
struct V_1 * V_129 = V_185 -> V_278 ;
struct V_21 * V_22 = F_13 ( V_129 ) ;
F_15 ( & V_271 -> V_235 ) ;
F_158 ( & V_129 -> V_8 ) ;
F_18 ( & V_271 -> V_235 ) ;
F_159 ( V_279 , & V_22 -> V_280 ) ;
return 0 ;
}
static int F_160 ( struct V_269 * V_185 , bool V_281 )
{
struct V_1 * V_20 = V_185 -> V_278 ;
if ( V_281 ) {
F_153 ( V_185 , V_275 ) ;
F_161 ( V_20 ) ;
} else {
V_20 -> V_276 = V_277 ;
F_155 ( V_20 ) ;
F_156 ( V_20 ) ;
}
return 0 ;
}
static int F_162 ( struct V_23 * V_24 )
{
struct V_113 * V_91 = V_24 -> V_91 ;
struct V_113 * V_282 = V_24 -> V_205 ;
struct V_283 * V_284 ;
int V_285 = 0 ;
F_163 () ;
F_164 (physdev, ha) {
F_14 ( L_46 ,
V_284 -> type ) ;
F_58 ( V_286 L_47 , V_284 -> V_266 [ 0 ] ,
V_284 -> V_266 [ 1 ] , V_284 -> V_266 [ 2 ] , V_284 -> V_266 [ 3 ] ,
V_284 -> V_266 [ 4 ] , V_284 -> V_266 [ 5 ] ) ;
if ( ( V_284 -> type == V_287 ) &&
( F_165 ( V_284 -> V_266 ) ) ) {
memcpy ( V_24 -> V_69 . V_100 , V_284 -> V_266 , V_96 ) ;
V_285 = 1 ;
F_14 ( L_48 ) ;
}
}
F_166 () ;
if ( ! V_285 )
return - V_52 ;
V_24 -> V_265 . V_288 = F_142 ;
V_24 -> V_265 . type = F_46 ( V_289 ) ;
V_24 -> V_265 . V_90 = V_91 ;
F_167 ( & V_24 -> V_265 ) ;
V_24 -> V_118 . V_288 = F_56 ;
V_24 -> V_118 . type = F_168 ( V_89 ) ;
V_24 -> V_118 . V_90 = V_91 ;
F_167 ( & V_24 -> V_118 ) ;
return 0 ;
}
static int F_169 ( void )
{
V_188 =
F_170 ( & V_290 ) ;
if ( V_188 == NULL ) {
F_58 (KERN_ERR PFX L_49 ) ;
return - V_52 ;
}
V_187 =
F_170 ( & V_291 ) ;
if ( V_187 == NULL ) {
F_58 (KERN_ERR PFX
L_50 ) ;
F_171 ( V_188 ) ;
V_188 = NULL ;
return - V_52 ;
}
return 0 ;
}
static void F_172 ( void )
{
F_171 ( V_188 ) ;
F_171 ( V_187 ) ;
V_188 = NULL ;
V_187 = NULL ;
}
static void F_173 ( struct V_292 * V_292 )
{
struct V_23 * V_24 ;
struct V_113 * V_91 ;
struct V_113 * V_205 ;
V_24 = F_57 ( V_292 , struct V_23 , V_292 ) ;
F_14 ( L_51 ) ;
V_91 = V_24 -> V_91 ;
V_205 = V_24 -> V_205 ;
if ( F_174 ( V_293 , & V_24 -> V_226 ) )
F_175 ( & V_24 -> V_69 ) ;
if ( V_24 -> V_248 ) {
F_176 ( V_24 -> V_248 ) ;
V_24 -> V_248 = NULL ;
}
F_177 ( V_91 ) ;
F_178 ( V_294 ) ;
}
static inline void F_179 ( struct V_23 * V_24 )
{
F_180 ( & V_24 -> V_292 ) ;
}
static inline void F_181 ( struct V_23 * V_24 )
{
F_182 ( & V_24 -> V_292 , F_173 ) ;
}
static void F_183 ( struct V_23 * V_24 )
{
F_184 ( V_24 ) ;
F_91 ( V_24 ) ;
}
static struct V_23 * F_185 ( struct V_295 * V_296 )
{
struct V_23 * V_24 ;
int V_18 ;
V_24 = F_186 ( sizeof( * V_24 ) , V_297 ) ;
if ( ! V_24 ) {
F_58 (KERN_ERR PFX L_52 ) ;
return NULL ;
}
F_187 ( & V_24 -> V_31 ) ;
F_188 ( & V_24 -> V_30 ) ;
V_24 -> V_296 = V_296 ;
V_18 = F_189 ( V_24 ) ;
if ( V_18 )
goto V_298;
V_24 -> V_205 = V_296 -> V_91 ;
V_24 -> V_91 = V_24 -> V_205 ;
F_126 ( & V_24 -> V_238 ) ;
F_126 ( & V_24 -> V_221 ) ;
return V_24 ;
V_298:
F_58 (KERN_ERR PFX L_53 ) ;
F_91 ( V_24 ) ;
return NULL ;
}
static int F_190 ( struct V_23 * V_24 ,
enum V_299 V_300 )
{
int V_18 = 0 ;
struct V_113 * V_91 = V_24 -> V_91 ;
struct V_267 * V_268 = & V_24 -> V_69 ;
F_191 ( V_91 ) ;
F_192 ( & V_24 -> V_292 ) ;
V_24 -> V_74 = 0 ;
memset ( V_268 , 0 , sizeof( * V_268 ) ) ;
F_193 ( V_268 , V_300 ) ;
V_24 -> V_69 . V_301 = F_146 ;
V_24 -> V_69 . V_302 = F_144 ;
V_24 -> V_69 . V_303 = F_145 ;
F_108 ( V_293 , & V_24 -> V_226 ) ;
V_18 = F_162 ( V_24 ) ;
if ( V_18 )
goto V_304;
V_24 -> V_305 = 0 ;
memset ( V_24 -> V_33 , 0 , sizeof( V_24 -> V_33 ) ) ;
V_24 -> V_239 = 0 ;
return 0 ;
V_304:
F_175 ( & V_24 -> V_69 ) ;
F_177 ( V_91 ) ;
F_181 ( V_24 ) ;
return V_18 ;
}
static struct V_1 * F_151 ( struct V_23 * V_24 ,
struct V_176 * V_306 , int V_307 )
{
struct V_1 * V_20 , * V_271 ;
struct V_21 * V_22 ;
struct V_149 * V_150 ;
struct V_269 * V_185 = F_194 ( V_306 ) ;
int V_18 = 0 ;
if ( ! V_307 )
V_20 = F_195 ( & V_308 , sizeof( * V_22 ) ) ;
else
V_20 = F_196 ( V_185 , sizeof( * V_22 ) ) ;
if ( ! V_20 ) {
F_58 (KERN_ERR PFX L_54 ) ;
return NULL ;
}
V_150 = V_20 -> V_177 ;
V_22 = F_13 ( V_20 ) ;
V_22 -> V_20 = V_20 ;
V_22 -> V_25 = V_24 ;
F_197 ( & V_22 -> V_280 , V_309 ) ;
V_18 = F_139 ( V_20 ) ;
if ( V_18 )
goto V_310;
if ( V_307 ) {
F_58 (KERN_ERR PFX L_55 ,
vport->node_name, vport->port_name) ;
F_115 ( V_20 , V_185 -> V_311 ) ;
F_116 ( V_20 , V_185 -> V_312 ) ;
}
V_18 = F_110 ( V_20 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_56 ) ;
goto V_310;
}
V_18 = F_98 ( V_20 , V_306 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_57 ,
hba->netdev->name) ;
goto V_310;
}
V_18 = F_130 ( V_20 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_58 ) ;
goto V_313;
}
F_124 ( V_20 -> V_177 ) = V_236 ;
if ( ! V_307 )
V_18 = F_135 ( V_20 ) ;
else {
V_150 = F_150 ( V_185 ) ;
V_271 = F_93 ( V_150 ) ;
V_18 = F_198 ( V_271 , V_20 ) ;
}
if ( V_18 ) {
F_58 (KERN_ERR PFX L_59 ) ;
goto V_313;
}
F_179 ( V_24 ) ;
return V_20 ;
V_313:
F_199 ( V_150 ) ;
V_310:
F_200 ( V_20 -> V_177 ) ;
return NULL ;
}
static void F_201 ( struct V_23 * V_24 )
{
F_202 ( & V_24 -> V_118 ) ;
F_202 ( & V_24 -> V_265 ) ;
F_203 () ;
}
static void F_204 ( struct V_1 * V_20 )
{
struct V_21 * V_22 = F_13 ( V_20 ) ;
struct V_23 * V_24 = V_22 -> V_25 ;
F_28 ( V_24 -> V_69 . V_2 , L_60 ) ;
F_205 ( & V_22 -> V_218 ) ;
F_125 ( V_20 ) ;
F_1 ( V_20 ) ;
F_206 ( V_20 -> V_177 ) ;
F_199 ( V_20 -> V_177 ) ;
F_138 ( V_20 ) ;
F_207 ( V_20 ) ;
F_200 ( V_20 -> V_177 ) ;
F_181 ( V_24 ) ;
}
static int F_208 ( struct V_113 * V_91 )
{
struct V_23 * V_24 = NULL ;
struct V_113 * V_205 ;
int V_18 = 0 ;
F_209 () ;
F_15 ( & V_274 ) ;
if ( V_91 -> V_314 & V_315 )
V_205 = F_210 ( V_91 ) ;
else {
F_58 (KERN_ERR PFX L_61 ) ;
V_18 = - V_52 ;
goto V_316;
}
V_24 = F_211 ( V_205 ) ;
if ( ! V_24 || ! V_24 -> V_69 . V_2 ) {
V_18 = - V_52 ;
F_58 (KERN_ERR PFX L_62 ) ;
goto V_316;
}
if ( ! F_35 ( V_225 , & V_24 -> V_226 ) ) {
F_58 (KERN_ERR PFX L_63 ) ;
goto V_316;
}
F_201 ( V_24 ) ;
F_212 ( V_24 ) ;
F_204 ( V_24 -> V_69 . V_2 ) ;
F_213 ( V_24 -> V_317 ) ;
if ( F_35 ( V_272 , & V_24 -> V_226 ) )
F_214 ( V_24 ) ;
F_107 ( V_225 , & V_24 -> V_226 ) ;
V_316:
F_18 ( & V_274 ) ;
F_215 () ;
return V_18 ;
}
static void V_309 ( struct V_318 * V_143 )
{
struct V_21 * V_22 ;
struct V_1 * V_20 ;
V_22 = F_57 ( V_143 , struct V_21 , V_280 ) ;
V_20 = V_22 -> V_20 ;
F_28 ( V_20 , L_64 ) ;
F_216 ( V_20 ) ;
F_209 () ;
F_15 ( & V_274 ) ;
F_204 ( V_20 ) ;
F_18 ( & V_274 ) ;
F_215 () ;
}
static void F_217 ( struct V_23 * V_24 )
{
F_218 ( V_24 ) ;
F_219 ( V_24 ) ;
}
static int F_220 ( struct V_23 * V_24 )
{
if ( F_221 ( V_24 ) )
goto V_319;
if ( F_222 ( V_24 ) )
goto V_319;
return 0 ;
V_319:
F_217 ( V_24 ) ;
return - V_53 ;
}
static int F_189 ( struct V_23 * V_24 )
{
struct V_295 * V_296 ;
if ( ! V_24 -> V_296 ) {
F_58 (KERN_ERR PFX L_65 ) ;
return - V_52 ;
}
V_296 = V_24 -> V_296 ;
V_24 -> V_320 = V_296 -> V_320 ;
if ( V_24 -> V_320 )
F_223 ( V_24 -> V_320 ) ;
return 0 ;
}
static void F_184 ( struct V_23 * V_24 )
{
if ( V_24 -> V_320 )
F_224 ( V_24 -> V_320 ) ;
V_24 -> V_320 = NULL ;
}
static void F_225 ( void * V_321 )
{
struct V_23 * V_24 = V_321 ;
struct V_1 * V_20 = V_24 -> V_69 . V_2 ;
F_14 ( L_1 , V_29 ) ;
F_15 ( & V_274 ) ;
if ( F_35 ( V_272 , & V_24 -> V_226 ) )
goto V_322;
if ( F_35 ( V_225 , & V_24 -> V_226 ) )
F_226 ( V_24 ) ;
V_322:
F_18 ( & V_274 ) ;
F_14 ( L_66 ) ;
if ( F_35 ( V_225 , & V_24 -> V_226 ) ) {
F_58 (KERN_ERR PFX L_67 ) ;
V_20 -> V_242 . V_323 = F_26 ;
F_227 ( V_24 ) ;
}
}
static void F_216 ( struct V_1 * V_20 )
{
F_14 ( L_1 , V_29 ) ;
F_161 ( V_20 ) ;
F_228 ( V_20 ) ;
}
static void F_212 ( struct V_23 * V_24 )
{
struct V_1 * V_20 ;
struct V_1 * V_185 ;
F_14 ( L_68 , V_29 ,
V_24 -> V_226 ) ;
if ( F_35 ( V_272 , & V_24 -> V_226 ) &&
F_35 ( V_225 , & V_24 -> V_226 ) ) {
V_20 = V_24 -> V_69 . V_2 ;
F_216 ( V_20 ) ;
F_28 ( V_20 , L_69
L_70 ,
V_24 -> V_239 ) ;
F_127 ( V_24 -> V_238 ,
( V_24 -> V_239 == 0 ) ) ;
F_15 ( & V_20 -> V_235 ) ;
F_123 (vport, &lport->vports, list)
F_124 ( V_185 -> V_177 ) = V_236 ;
F_18 ( & V_20 -> V_235 ) ;
F_124 ( V_20 -> V_177 ) = V_236 ;
F_122 ( & V_24 -> V_69 ) ;
F_125 ( V_20 ) ;
F_15 ( & V_24 -> V_30 ) ;
F_107 ( V_228 , & V_24 -> V_208 ) ;
F_107 ( V_231 , & V_24 -> V_208 ) ;
F_107 ( V_234 , & V_24 -> V_208 ) ;
F_18 ( & V_24 -> V_30 ) ;
}
}
static int F_226 ( struct V_23 * V_24 )
{
#define F_229 (1000 / HZ)
int V_18 = - 1 ;
int V_28 = V_156 ;
V_18 = F_220 ( V_24 ) ;
if ( V_18 ) {
F_58 (KERN_ALERT PFX
L_71 , rc) ;
goto V_324;
}
V_18 = F_230 ( V_24 ) ;
if ( V_18 ) {
F_58 (KERN_ALERT PFX
L_72 , rc) ;
goto V_325;
}
while ( ! F_35 ( V_228 , & V_24 -> V_208 ) && V_28 -- )
F_231 ( F_229 ) ;
if ( ! F_35 ( V_228 , & V_24 -> V_208 ) ) {
F_58 (KERN_ERR PFX L_73
L_74 ,
hba->cnic->netdev->name) ;
V_18 = - 1 ;
goto V_325;
}
F_108 ( V_272 , & V_24 -> V_226 ) ;
return 0 ;
V_325:
F_217 ( V_24 ) ;
V_324:
return V_18 ;
}
static void F_214 ( struct V_23 * V_24 )
{
if ( F_174 ( V_272 , & V_24 -> V_226 ) ) {
if ( F_232 ( V_24 ) == 0 ) {
F_233 ( & V_24 -> V_326 ) ;
V_24 -> V_326 . V_327 = V_328 +
V_277 ;
V_24 -> V_326 . V_329 = F_117 ;
V_24 -> V_326 . V_138 = ( unsigned long ) V_24 ;
F_234 ( & V_24 -> V_326 ) ;
F_127 ( V_24 -> V_221 ,
( V_24 -> V_74 &
V_220 ) ) ;
if ( F_128 ( V_124 ) )
F_129 ( V_124 ) ;
F_205 ( & V_24 -> V_326 ) ;
}
F_217 ( V_24 ) ;
}
}
static void F_235 ( void * V_321 )
{
struct V_23 * V_24 = (struct V_23 * ) V_321 ;
F_58 ( V_229 L_75 ) ;
F_15 ( & V_274 ) ;
F_212 ( V_24 ) ;
F_214 ( V_24 ) ;
F_18 ( & V_274 ) ;
}
static void F_227 ( struct V_23 * V_24 )
{
struct V_1 * V_20 ;
int V_330 = 0 ;
F_14 ( L_1 , V_29 ) ;
if ( ! F_35 ( V_272 , & V_24 -> V_226 ) ) {
F_58 (KERN_ERR PFX L_76 ) ;
return;
}
V_20 = V_24 -> V_69 . V_2 ;
F_28 ( V_20 , L_77 ) ;
if ( ! F_105 ( V_20 ) ) {
F_28 ( V_20 , L_78 ) ;
F_121 ( & V_24 -> V_69 ) ;
F_124 ( V_20 -> V_177 ) = V_331 ;
F_108 ( V_234 , & V_24 -> V_208 ) ;
}
while ( ! V_24 -> V_69 . V_70 ) {
F_231 ( 250 ) ;
if ( ++ V_330 > 12 )
break;
}
F_154 ( V_20 ) ;
F_155 ( V_20 ) ;
}
static void F_236 ( struct V_295 * V_90 )
{
struct V_23 * V_24 ;
int V_18 = 0 ;
F_14 ( L_1 , V_29 ) ;
if ( ! F_35 ( V_332 , & V_90 -> V_74 ) ) {
F_58 (KERN_ERR PFX L_79
L_80 ,
dev->netdev->name, dev->flags) ;
return;
}
V_24 = F_185 ( V_90 ) ;
if ( ! V_24 ) {
F_58 (KERN_ERR PFX L_81 ) ;
return;
}
F_15 ( & V_274 ) ;
F_237 ( & V_24 -> V_333 , & V_334 ) ;
V_335 ++ ;
F_18 ( & V_274 ) ;
F_107 ( V_336 , & V_24 -> V_337 ) ;
V_18 = V_90 -> V_338 ( V_90 , V_339 ,
( void * ) V_24 ) ;
if ( V_18 )
F_58 (KERN_ALERT PFX L_82 , rc) ;
else
F_108 ( V_336 , & V_24 -> V_337 ) ;
}
static int F_238 ( struct V_113 * V_91 )
{
struct V_23 * V_24 ;
struct V_113 * V_205 ;
struct V_340 V_341 ;
int V_18 = 0 ;
F_209 () ;
F_15 ( & V_274 ) ;
if ( V_91 -> V_314 & V_315 )
V_205 = F_210 ( V_91 ) ;
else {
F_58 (KERN_ERR PFX L_61 ) ;
V_18 = - V_52 ;
goto V_342;
}
if ( V_205 -> V_213 && V_205 -> V_213 -> V_343 ) {
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_205 -> V_213 -> V_343 ( V_205 , & V_341 ) ;
if ( strcmp ( V_341 . V_344 , L_83 ) ) {
F_58 (KERN_ERR PFX L_84 ) ;
V_18 = - V_52 ;
goto V_342;
}
} else {
F_58 (KERN_ERR PFX L_85 ) ;
V_18 = - V_52 ;
goto V_342;
}
F_58 (KERN_ERR PFX L_86 ) ;
V_24 = F_211 ( V_205 ) ;
if ( ! V_24 || ! V_24 -> V_69 . V_2 ) {
V_18 = - V_52 ;
F_58 (KERN_ERR PFX L_87 ) ;
} else {
F_122 ( & V_24 -> V_69 ) ;
F_125 ( V_24 -> V_69 . V_2 ) ;
}
V_342:
F_18 ( & V_274 ) ;
F_215 () ;
return V_18 ;
}
static int F_239 ( struct V_113 * V_91 )
{
struct V_23 * V_24 ;
struct V_113 * V_205 ;
struct V_340 V_341 ;
int V_18 = 0 ;
F_209 () ;
F_14 ( L_1 , V_29 ) ;
F_15 ( & V_274 ) ;
if ( V_91 -> V_314 & V_315 )
V_205 = F_210 ( V_91 ) ;
else {
F_58 (KERN_ERR PFX L_61 ) ;
V_18 = - V_52 ;
goto V_342;
}
if ( V_205 -> V_213 && V_205 -> V_213 -> V_343 ) {
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_205 -> V_213 -> V_343 ( V_205 , & V_341 ) ;
if ( strcmp ( V_341 . V_344 , L_83 ) ) {
F_58 (KERN_ERR PFX L_84 ) ;
V_18 = - V_52 ;
goto V_342;
}
} else {
F_58 (KERN_ERR PFX L_85 ) ;
V_18 = - V_52 ;
goto V_342;
}
V_24 = F_211 ( V_205 ) ;
if ( ! V_24 || ! V_24 -> V_69 . V_2 ) {
V_18 = - V_52 ;
F_58 (KERN_ERR PFX L_88 ) ;
} else if ( ! F_105 ( V_24 -> V_69 . V_2 ) )
F_121 ( & V_24 -> V_69 ) ;
V_342:
F_18 ( & V_274 ) ;
F_215 () ;
return V_18 ;
}
static int F_240 ( struct V_113 * V_91 , enum V_299 V_300 )
{
struct V_23 * V_24 ;
struct V_113 * V_205 ;
struct V_1 * V_20 ;
struct V_340 V_341 ;
int V_18 = 0 ;
int V_345 ;
F_14 ( L_89 ) ;
if ( V_300 != V_346 ) {
F_58 ( V_229 L_90 ) ;
return - V_273 ;
}
F_209 () ;
F_15 ( & V_274 ) ;
if ( ! F_241 ( V_294 ) ) {
V_18 = - V_71 ;
goto V_347;
}
if ( V_91 -> V_314 & V_315 ) {
V_205 = F_210 ( V_91 ) ;
V_345 = F_242 ( V_91 ) ;
} else {
F_58 (KERN_ERR PFX L_61 ) ;
V_18 = - V_71 ;
goto V_316;
}
if ( V_205 -> V_213 && V_205 -> V_213 -> V_343 ) {
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_205 -> V_213 -> V_343 ( V_205 , & V_341 ) ;
if ( strcmp ( V_341 . V_344 , L_83 ) ) {
F_58 (KERN_ERR PFX L_84 ) ;
V_18 = - V_71 ;
goto V_316;
}
} else {
F_58 (KERN_ERR PFX L_85 ) ;
V_18 = - V_71 ;
goto V_316;
}
V_24 = F_211 ( V_205 ) ;
if ( ! V_24 ) {
V_18 = - V_52 ;
F_58 (KERN_ERR PFX L_91 ) ;
goto V_316;
}
if ( ! F_35 ( V_272 , & V_24 -> V_226 ) ) {
V_18 = F_226 ( V_24 ) ;
if ( V_18 )
goto V_316;
}
if ( F_35 ( V_225 , & V_24 -> V_226 ) ) {
V_18 = - V_348 ;
goto V_316;
}
V_24 -> V_91 = V_91 ;
V_24 -> V_345 = V_345 ;
V_24 -> V_349 = 1 ;
V_18 = F_190 ( V_24 , V_300 ) ;
if ( V_18 ) {
F_58 (KERN_ERR PFX L_92 ) ;
goto V_350;
}
V_24 -> V_317 =
F_243 ( L_93 ) ;
if ( ! V_24 -> V_317 ) {
F_58 (KERN_ERR PFX L_94 ) ;
V_18 = - V_71 ;
goto V_350;
}
V_20 = F_151 ( V_24 , & V_24 -> V_320 -> V_90 , 0 ) ;
if ( ! V_20 ) {
F_58 (KERN_ERR PFX L_95 ,
netdev->name) ;
F_201 ( V_24 ) ;
V_18 = - V_71 ;
goto V_351;
}
V_20 -> V_276 = V_277 ;
V_24 -> V_69 . V_2 = V_20 ;
F_108 ( V_225 , & V_24 -> V_226 ) ;
F_58 (KERN_ERR PFX L_96 ) ;
F_227 ( V_24 ) ;
F_181 ( V_24 ) ;
F_18 ( & V_274 ) ;
F_215 () ;
return 0 ;
V_351:
F_213 ( V_24 -> V_317 ) ;
V_350:
F_181 ( V_24 ) ;
V_316:
F_178 ( V_294 ) ;
V_347:
F_18 ( & V_274 ) ;
F_215 () ;
return V_18 ;
}
static struct V_23 * F_244 ( struct V_295 * V_296 )
{
struct V_352 * V_8 ;
struct V_352 * V_353 ;
struct V_23 * V_24 ;
F_245 (list, temp, &adapter_list) {
V_24 = (struct V_23 * ) V_8 ;
if ( V_24 -> V_296 == V_296 )
return V_24 ;
}
return NULL ;
}
static struct V_23 * F_211 ( struct V_113 * V_205 )
{
struct V_352 * V_8 ;
struct V_352 * V_353 ;
struct V_23 * V_24 ;
F_245 (list, temp, &adapter_list) {
V_24 = (struct V_23 * ) V_8 ;
if ( V_24 -> V_205 == V_205 )
return V_24 ;
}
F_58 (KERN_ERR PFX L_97 ) ;
return NULL ;
}
static void F_246 ( struct V_295 * V_90 )
{
struct V_23 * V_24 ;
F_14 ( L_98 ) ;
if ( ! F_35 ( V_332 , & V_90 -> V_74 ) ) {
F_58 (KERN_ERR PFX L_99 ,
dev->netdev->name, dev->flags) ;
return;
}
F_15 ( & V_274 ) ;
V_24 = F_244 ( V_90 ) ;
if ( ! V_24 ) {
F_58 (KERN_ERR PFX L_100 ,
dev) ;
F_18 ( & V_274 ) ;
return;
}
F_89 ( & V_24 -> V_333 ) ;
V_335 -- ;
if ( F_35 ( V_225 , & V_24 -> V_226 ) ) {
F_201 ( V_24 ) ;
F_204 ( V_24 -> V_69 . V_2 ) ;
}
F_18 ( & V_274 ) ;
F_235 ( V_24 ) ;
if ( F_174 ( V_336 , & V_24 -> V_337 ) )
V_24 -> V_296 -> V_354 ( V_24 -> V_296 , V_339 ) ;
F_183 ( V_24 ) ;
}
static int F_247 ( struct V_149 * V_150 )
{
struct V_1 * V_20 = F_93 ( V_150 ) ;
F_248 ( V_20 ) ;
return 0 ;
}
static bool F_249 ( struct V_113 * V_91 )
{
F_15 ( & V_274 ) ;
if ( V_91 -> V_314 & V_315 ) {
struct V_113 * V_205 = F_210 ( V_91 ) ;
if ( F_211 ( V_205 ) ) {
F_18 ( & V_274 ) ;
return true ;
}
}
F_18 ( & V_274 ) ;
return false ;
}
static void F_250 ( unsigned int V_355 )
{
struct V_140 * V_141 ;
struct V_356 * V_122 ;
V_141 = & F_251 ( V_357 , V_355 ) ;
V_122 = F_252 ( F_84 ,
( void * ) V_141 ,
L_101 , V_355 ) ;
if ( F_253 ( ! F_152 ( V_141 -> V_358 ) ) ) {
F_254 ( V_122 , V_355 ) ;
V_141 -> V_358 = V_122 ;
F_63 ( V_122 ) ;
}
}
static void F_255 ( unsigned int V_355 )
{
struct V_140 * V_141 ;
struct V_356 * V_122 ;
struct V_142 * V_143 , * V_144 ;
F_85 ( V_145 ) ;
F_14 ( L_102 , V_355 ) ;
V_141 = & F_251 ( V_357 , V_355 ) ;
F_2 ( & V_141 -> V_146 ) ;
V_122 = V_141 -> V_358 ;
V_141 -> V_358 = NULL ;
F_88 (work, tmp, &work_list, list) {
F_89 ( & V_143 -> V_8 ) ;
F_90 ( V_143 -> V_27 , V_143 -> V_147 ) ;
F_91 ( V_143 ) ;
}
F_6 ( & V_141 -> V_146 ) ;
if ( V_122 )
F_256 ( V_122 ) ;
}
static int F_257 ( struct V_359 * V_360 ,
unsigned long V_361 , void * V_362 )
{
unsigned V_355 = ( unsigned long ) V_362 ;
switch ( V_361 ) {
case V_363 :
case V_364 :
F_58 ( V_365 L_103 , V_355 ) ;
F_250 ( V_355 ) ;
break;
case V_366 :
case V_367 :
F_58 ( V_365 L_104 , V_355 ) ;
F_255 ( V_355 ) ;
break;
default:
break;
}
return V_368 ;
}
static int T_5 F_258 ( void )
{
struct V_3 * V_4 ;
struct V_356 * V_369 ;
int V_18 = 0 ;
unsigned int V_355 = 0 ;
struct V_140 * V_141 ;
F_58 (KERN_INFO PFX L_105 , version) ;
V_18 = F_259 ( & V_370 ) ;
if ( V_18 ) {
F_58 ( V_229 L_106
L_107 ) ;
goto V_371;
}
F_260 ( & V_334 ) ;
F_188 ( & V_274 ) ;
V_335 = 0 ;
V_18 = F_169 () ;
if ( V_18 )
goto V_372;
V_279 = F_261 ( L_108 , 0 , 0 ) ;
if ( ! V_279 ) {
V_18 = - V_53 ;
goto V_373;
}
V_4 = & V_13 ;
F_112 ( & V_4 -> V_14 ) ;
V_369 = F_252 ( F_64 ,
( void * ) V_4 ,
L_109 ) ;
if ( F_152 ( V_369 ) ) {
V_18 = F_262 ( V_369 ) ;
goto V_374;
}
F_63 ( V_369 ) ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
V_4 -> V_122 = V_369 ;
F_6 ( & V_4 -> V_14 . V_15 ) ;
F_263 (cpu) {
V_141 = & F_251 ( V_357 , V_355 ) ;
F_260 ( & V_141 -> V_145 ) ;
F_187 ( & V_141 -> V_146 ) ;
}
F_264 (cpu) {
F_250 ( V_355 ) ;
}
F_265 ( & V_375 ) ;
F_266 ( V_339 , & V_376 ) ;
return 0 ;
V_374:
F_213 ( V_279 ) ;
V_373:
F_172 () ;
V_372:
F_267 ( & V_370 ) ;
V_371:
return V_18 ;
}
static void T_6 F_268 ( void )
{
F_85 ( V_377 ) ;
struct V_23 * V_24 , * V_11 ;
struct V_3 * V_4 ;
struct V_356 * V_369 ;
struct V_9 * V_10 ;
unsigned int V_355 = 0 ;
F_15 ( & V_274 ) ;
F_269 ( & V_334 , & V_377 ) ;
F_260 ( & V_334 ) ;
V_335 = 0 ;
F_18 ( & V_274 ) ;
F_88 (hba, next, &to_be_deleted, link) {
F_89 ( & V_24 -> V_333 ) ;
F_58 (KERN_ERR PFX L_110 ,
hba, atomic_read(&hba->kref.refcount)) ;
F_235 ( V_24 ) ;
if ( F_174 ( V_336 ,
& V_24 -> V_337 ) )
V_24 -> V_296 -> V_354 ( V_24 -> V_296 , V_339 ) ;
F_183 ( V_24 ) ;
}
F_270 ( V_339 ) ;
V_4 = & V_13 ;
F_2 ( & V_4 -> V_14 . V_15 ) ;
V_369 = V_4 -> V_122 ;
V_4 -> V_122 = NULL ;
while ( ( V_10 = F_69 ( & V_4 -> V_14 ) ) != NULL )
F_5 ( V_10 ) ;
F_6 ( & V_4 -> V_14 . V_15 ) ;
if ( V_369 )
F_256 ( V_369 ) ;
F_271 ( & V_375 ) ;
F_264 (cpu) {
F_255 ( V_355 ) ;
}
F_213 ( V_279 ) ;
F_172 () ;
F_267 ( & V_370 ) ;
}
