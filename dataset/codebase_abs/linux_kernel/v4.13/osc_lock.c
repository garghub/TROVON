int F_1 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 == & V_5 ) ;
}
static struct V_6 * F_2 ( struct V_7 * V_8 )
{
struct V_6 * V_9 ;
V_9 = F_3 ( V_8 ) ;
if ( V_9 )
F_4 ( V_9 ) ;
return V_9 ;
}
static int F_5 ( struct V_1 * V_10 )
{
struct V_6 * V_9 = F_2 ( & V_10 -> V_11 ) ;
struct V_6 * V_12 = V_10 -> V_13 ;
int V_14 = F_6 ( & V_10 -> V_11 ) ;
if ( F_7 ( F_1 ( V_10 ) ,
V_10 -> V_15 && ! V_10 -> V_13 ) )
return 1 ;
if ( ! F_7 ( V_12 , V_14 ) )
return 0 ;
if ( ! F_7 ( V_12 , V_12 -> V_16 . V_17 == V_10 -> V_11 . V_18 ) )
return 0 ;
if ( ! F_7 ( V_14 ,
F_7 ( V_9 && V_12 , V_9 == V_12 ) &&
F_7 ( ! V_9 , ! V_12 ) ) )
return 0 ;
if ( ! F_7 ( V_10 -> V_19 == V_20 ,
! V_12 && ! V_14 ) )
return 0 ;
if ( ! F_7 ( V_12 && V_10 -> V_19 < V_20 ,
! F_8 ( V_12 ) ) )
return 0 ;
if ( ! F_7 ( V_10 -> V_19 == V_21 ,
V_12 && V_12 -> V_22 == V_12 -> V_23 &&
V_10 -> V_24 ) )
return 0 ;
return 1 ;
}
static void F_9 ( const struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_10 = F_10 ( V_28 ) ;
F_11 ( F_5 ( V_10 ) ) ;
F_12 ( ! V_10 -> V_13 ) ;
F_13 ( V_29 , V_10 ) ;
}
static void F_14 ( const struct V_25 * V_26 ,
const struct V_30 * V_9 ,
union V_31 * V_32 )
{
const struct V_33 * V_34 = & V_9 -> V_35 ;
F_15 ( V_32 , V_34 -> V_36 , V_34 -> V_37 , V_34 -> V_38 ) ;
V_32 -> V_39 . V_40 = V_34 -> V_41 ;
}
static T_1 F_16 ( T_2 V_42 )
{
T_1 V_43 = 0 ;
F_12 ( ( V_42 & ~ V_44 ) == 0 ) ;
if ( V_42 & V_45 )
V_43 |= V_46 ;
if ( V_42 & V_47 )
V_43 |= V_48 ;
if ( V_42 & V_49 )
V_43 |= V_50 ;
if ( V_42 & V_51 )
V_43 |= V_52 ;
if ( V_42 & V_53 )
V_43 |= V_54 ;
return V_43 ;
}
static void F_17 ( const struct V_25 * V_26 ,
struct V_55 * V_56 ,
struct V_6 * V_57 ,
struct V_58 * V_59 )
{
struct V_60 * V_61 = F_18 ( V_56 ) ;
struct V_62 * V_63 = V_56 -> V_64 ;
struct V_65 * V_66 = & F_19 ( V_26 ) -> V_67 ;
unsigned int V_68 ;
V_68 = V_69 | V_70 | V_71 | V_72 | V_73 ;
if ( ! V_59 )
V_59 = V_57 -> V_74 ;
F_20 ( V_66 , V_59 ) ;
F_21 ( V_61 ) ;
if ( V_57 ) {
T_1 V_75 ;
F_22 ( V_57 -> V_76 ) ;
F_12 ( V_59 == V_57 -> V_74 ) ;
V_75 = V_59 -> V_77 ;
if ( V_75 > V_57 -> V_78 . V_39 . V_79 )
V_75 = V_57 -> V_78 . V_39 . V_79 + 1 ;
if ( V_75 >= V_63 -> V_80 ) {
F_23 ( V_57 , L_1 ,
V_59 -> V_77 , V_75 ) ;
V_68 |= V_81 ;
V_66 -> V_82 = V_75 ;
} else {
F_23 ( V_57 , L_2 ,
V_59 -> V_77 , V_63 -> V_80 ,
V_57 -> V_78 . V_39 . V_79 ) ;
}
F_24 ( V_57 ) ;
}
F_25 ( V_26 , V_61 , V_66 , V_68 ) ;
F_26 ( V_61 ) ;
}
static void F_27 ( const struct V_25 * V_26 , struct V_1 * V_83 ,
struct V_7 * V_84 , bool V_85 )
{
struct V_6 * V_57 ;
V_57 = F_28 ( V_84 , 0 ) ;
F_12 ( V_57 ) ;
F_29 ( & V_57 -> V_86 , L_3 , V_83 ) ;
V_83 -> V_87 = 1 ;
F_12 ( ! V_83 -> V_13 ) ;
V_83 -> V_13 = V_57 ;
if ( ! V_83 -> V_88 ) {
F_30 ( & V_83 -> V_11 , V_84 ) ;
F_31 ( V_84 , V_83 -> V_89 . V_90 ) ;
V_83 -> V_24 = 1 ;
}
F_32 ( V_57 ) ;
if ( V_57 -> V_23 == V_57 -> V_22 ) {
struct V_91 * V_92 = & V_57 -> V_78 . V_39 ;
struct V_33 * V_93 = & V_83 -> V_3 . V_94 -> V_35 ;
V_93 -> V_95 = F_33 ( V_57 -> V_23 ) ;
V_93 -> V_37 = F_34 ( V_93 -> V_36 , V_92 -> V_96 ) ;
V_93 -> V_38 = F_34 ( V_93 -> V_36 , V_92 -> V_79 ) ;
V_93 -> V_41 = V_92 -> V_40 ;
if ( V_85 ) {
F_12 ( V_83 -> V_97 & V_98 ) ;
F_17 ( V_26 , F_35 ( V_83 -> V_3 . V_99 ) ,
V_57 , NULL ) ;
}
F_11 ( F_5 ( V_83 ) ) ;
}
F_36 ( V_57 ) ;
F_12 ( V_83 -> V_19 != V_21 ) ;
V_83 -> V_19 = V_21 ;
}
static int F_37 ( void * V_18 , struct V_7 * V_84 ,
int V_100 )
{
struct V_1 * V_83 = V_18 ;
struct V_27 * V_28 = & V_83 -> V_3 ;
struct V_25 * V_26 ;
int V_101 ;
T_3 V_102 ;
V_26 = F_38 ( & V_102 ) ;
F_12 ( ! F_39 ( V_26 ) ) ;
V_101 = F_40 ( V_100 ) ;
if ( V_83 -> V_19 == V_103 ) {
V_83 -> V_19 = V_104 ;
} else if ( V_83 -> V_19 == V_20 ) {
V_101 = - V_105 ;
} else {
F_41 ( L_4 , V_83 -> V_19 ) ;
F_42 () ;
}
if ( V_101 == 0 )
F_27 ( V_26 , V_83 , V_84 , V_100 == V_106 ) ;
if ( V_83 -> V_15 && V_101 == - V_107 ) {
F_43 ( F_35 ( V_28 -> V_99 ) ) ;
F_12 ( V_28 -> V_4 == & V_108 ) ;
F_44 ( V_26 , V_83 , 1 ) ;
V_83 -> V_19 = V_21 ;
V_101 = 0 ;
} else if ( V_83 -> V_88 && V_101 == - V_109 ) {
F_12 ( V_83 -> V_97 & V_98 ) ;
F_17 ( V_26 , F_35 ( V_28 -> V_99 ) ,
NULL , & V_83 -> V_110 ) ;
V_101 = 0 ;
}
if ( V_83 -> V_111 )
F_45 ( V_26 , V_83 -> V_111 , V_101 ) ;
F_46 ( V_26 , & V_102 ) ;
return V_101 ;
}
static int F_47 ( void * V_18 , struct V_7 * V_84 ,
int V_100 )
{
struct V_55 * V_56 = V_18 ;
struct V_6 * V_57 ;
struct V_25 * V_26 ;
T_3 V_102 ;
V_26 = F_38 ( & V_102 ) ;
F_12 ( ! F_39 ( V_26 ) ) ;
if ( V_100 == V_112 ) {
V_100 = V_106 ;
goto V_113;
}
if ( V_100 != V_106 )
goto V_113;
V_57 = F_3 ( V_84 ) ;
F_12 ( V_57 ) ;
F_32 ( V_57 ) ;
F_12 ( V_57 -> V_23 == V_57 -> V_22 ) ;
F_17 ( V_26 , V_56 , V_57 , NULL ) ;
F_36 ( V_57 ) ;
F_4 ( V_57 ) ;
V_113:
F_48 ( V_26 , F_18 ( V_56 ) ) ;
F_46 ( V_26 , & V_102 ) ;
return F_40 ( V_100 ) ;
}
static int F_49 ( struct V_55 * V_61 , T_4 V_96 , T_4 V_79 ,
enum V_114 V_115 , int V_116 )
{
struct V_25 * V_26 ;
T_3 V_102 ;
int V_101 = 0 ;
int V_117 = 0 ;
V_26 = F_38 ( & V_102 ) ;
if ( F_39 ( V_26 ) )
return F_50 ( V_26 ) ;
if ( V_115 == V_118 ) {
V_101 = F_51 ( V_26 , V_61 , V_96 , V_79 , 1 ,
V_116 ) ;
F_52 ( V_119 , L_5 ,
V_61 , V_96 , V_79 , V_101 ,
V_116 ? L_6 : L_7 ) ;
if ( V_101 > 0 )
V_101 = 0 ;
}
V_117 = F_53 ( V_26 , V_61 , V_96 , V_79 , V_115 ) ;
if ( V_101 == 0 && V_117 < 0 )
V_101 = V_117 ;
F_46 ( V_26 , & V_102 ) ;
return V_101 ;
}
static int F_54 ( const struct V_25 * V_26 ,
struct V_6 * V_57 ,
void * V_120 , int V_121 )
{
struct V_60 * V_61 = NULL ;
int V_43 = 0 ;
int V_116 ;
enum V_114 V_115 = V_122 ;
F_12 ( V_121 == V_123 ) ;
F_32 ( V_57 ) ;
if ( V_57 -> V_23 != V_57 -> V_22 ) {
V_57 -> V_124 = NULL ;
F_36 ( V_57 ) ;
return 0 ;
}
V_116 = F_55 ( V_57 ) ;
if ( V_57 -> V_23 & ( V_125 | V_126 ) )
V_115 = V_118 ;
if ( V_57 -> V_124 ) {
V_61 = F_18 ( V_57 -> V_124 ) ;
V_57 -> V_124 = NULL ;
F_56 ( V_61 ) ;
}
F_36 ( V_57 ) ;
if ( V_61 ) {
struct V_91 * V_127 = & V_57 -> V_78 . V_39 ;
struct V_65 * V_66 = & F_19 ( V_26 ) -> V_67 ;
T_1 V_128 ;
V_43 = F_49 ( F_35 ( V_61 ) ,
F_34 ( V_61 , V_127 -> V_96 ) ,
F_34 ( V_61 , V_127 -> V_79 ) ,
V_115 , V_116 ) ;
F_32 ( V_57 ) ;
F_21 ( V_61 ) ;
V_128 = F_35 ( V_61 ) -> V_64 -> V_80 ;
V_66 -> V_82 = F_57 ( V_57 , V_128 ) ;
F_25 ( V_26 , V_61 , V_66 , V_81 ) ;
F_26 ( V_61 ) ;
F_36 ( V_57 ) ;
F_48 ( V_26 , V_61 ) ;
}
return V_43 ;
}
static int F_58 ( struct V_6 * V_57 ,
struct V_129 * V_130 , void * V_120 ,
int V_121 )
{
int V_43 = 0 ;
switch ( V_121 ) {
case V_131 : {
struct V_7 V_84 ;
F_59 ( V_57 , & V_84 ) ;
V_43 = F_60 ( & V_84 , V_132 ) ;
if ( V_43 == - V_133 )
V_43 = 0 ;
break;
}
case V_123 : {
struct V_25 * V_26 ;
T_3 V_102 ;
V_26 = F_38 ( & V_102 ) ;
if ( F_39 ( V_26 ) ) {
V_43 = F_50 ( V_26 ) ;
break;
}
V_43 = F_54 ( V_26 , V_57 , V_120 , V_121 ) ;
F_46 ( V_26 , & V_102 ) ;
break;
}
default:
F_42 () ;
}
return V_43 ;
}
static int F_61 ( struct V_6 * V_57 , void * V_120 )
{
struct V_134 * V_135 = V_120 ;
struct V_25 * V_26 ;
struct V_58 * V_59 ;
struct V_136 * V_137 ;
struct V_60 * V_61 = NULL ;
int V_43 ;
T_3 V_102 ;
F_12 ( F_62 ( V_135 -> V_138 ) == V_139 ) ;
V_26 = F_38 ( & V_102 ) ;
if ( F_39 ( V_26 ) ) {
V_43 = F_50 ( V_26 ) ;
goto V_113;
}
F_32 ( V_57 ) ;
if ( V_57 -> V_124 ) {
V_61 = F_18 ( V_57 -> V_124 ) ;
F_56 ( V_61 ) ;
}
F_36 ( V_57 ) ;
if ( V_61 ) {
V_137 = & V_135 -> V_140 ;
F_63 ( V_137 , & V_141 ) ;
F_64 ( V_137 , & V_142 , V_143 ,
sizeof( * V_59 ) ) ;
V_43 = F_65 ( V_137 ) ;
if ( V_43 == 0 ) {
V_59 = F_66 ( V_137 , & V_142 ) ;
V_43 = F_67 ( V_26 , V_61 , V_59 ) ;
}
if ( ! F_68 ( V_135 -> V_144 ) ) {
F_69 ( & V_135 -> V_140 , & V_142 ,
sizeof( struct V_145 ) ,
V_143 ) ;
}
F_48 ( V_26 , V_61 ) ;
} else {
F_70 ( V_135 , 1 , NULL , NULL ) ;
V_43 = - V_146 ;
}
F_46 ( V_26 , & V_102 ) ;
V_113:
V_135 -> V_147 = V_43 ;
return V_43 ;
}
static int F_71 ( const struct V_25 * V_26 , struct V_148 * V_149 ,
struct V_150 * V_151 , void * V_152 )
{
struct V_153 * V_154 = V_151 -> V_155 . V_156 ;
if ( F_72 ( V_26 , V_154 ) ||
F_73 ( V_154 -> V_157 ) || F_74 ( V_154 -> V_157 )
)
return V_158 ;
* ( T_4 * ) V_152 = F_75 ( V_151 ) + 1 ;
return V_159 ;
}
static unsigned long F_76 ( const struct V_25 * V_26 ,
struct V_55 * V_160 ,
struct V_91 * V_127 )
{
struct V_148 * V_149 = & F_19 ( V_26 ) -> V_161 ;
struct V_60 * V_61 = F_77 ( & V_160 -> V_162 ) ;
T_4 V_163 ;
int V_43 ;
V_149 -> V_164 = V_61 ;
V_149 -> V_165 = 1 ;
V_43 = F_78 ( V_26 , V_149 , V_166 , V_149 -> V_164 ) ;
if ( V_43 != 0 )
return V_43 ;
V_163 = F_34 ( V_61 , V_127 -> V_96 ) ;
do {
V_43 = F_79 ( V_26 , V_149 , V_160 ,
V_163 ,
F_34 ( V_61 , V_127 -> V_79 ) ,
F_71 , ( void * ) & V_163 ) ;
if ( V_43 == V_158 )
break;
if ( V_43 == V_167 )
F_80 () ;
} while ( V_43 != V_159 );
F_81 ( V_26 , V_149 ) ;
return V_43 == V_158 ? 1 : 0 ;
}
unsigned long F_82 ( struct V_6 * V_57 )
{
struct V_25 * V_26 ;
struct V_55 * V_61 ;
struct V_1 * V_83 ;
unsigned long V_168 ;
bool V_169 = false ;
T_3 V_102 ;
F_83 () ;
V_26 = F_38 ( & V_102 ) ;
if ( F_39 ( V_26 ) )
return 1 ;
F_12 ( V_57 -> V_76 -> V_170 == V_171 ) ;
V_61 = V_57 -> V_124 ;
if ( ! V_61 ) {
V_168 = 1 ;
goto V_113;
}
F_84 ( & V_61 -> V_172 ) ;
F_85 (oscl, &obj->oo_ol_list, ols_nextlock_oscobj) {
if ( V_83 -> V_13 && V_83 -> V_13 != V_57 )
continue;
V_169 = true ;
}
F_86 ( & V_61 -> V_172 ) ;
if ( V_169 ) {
V_168 = 1 ;
goto V_113;
}
V_168 = F_76 ( V_26 , V_61 , & V_57 -> V_78 . V_39 ) ;
V_113:
F_46 ( V_26 , & V_102 ) ;
return V_168 ;
}
static void F_87 ( const struct V_25 * V_26 ,
const struct V_30 * V_9 ,
struct V_55 * V_56 ,
struct V_173 * V_174 )
{
V_174 -> V_175 = V_171 ;
V_174 -> V_90 = F_88 ( V_9 -> V_35 . V_95 ) ;
V_174 -> V_176 = F_58 ;
V_174 -> V_177 = V_178 ;
V_174 -> V_179 = F_61 ;
V_174 -> V_180 = V_56 ;
}
static void F_44 ( const struct V_25 * V_26 ,
struct V_1 * V_10 , int V_181 )
{
struct V_27 * V_28 = & V_10 -> V_3 ;
F_12 ( V_10 -> V_19 == V_182 ||
V_10 -> V_19 == V_104 ) ;
if ( V_181 ) {
V_10 -> V_15 = 1 ;
V_28 -> V_4 = & V_5 ;
} else {
struct V_183 * V_184 = F_89 ( V_26 ) ;
struct V_148 * V_149 = V_184 -> V_185 . V_186 ;
struct V_60 * V_61 = V_28 -> V_99 ;
struct V_55 * V_187 = F_35 ( V_61 ) ;
const struct V_188 * V_189 = F_90 ( V_61 -> V_190 . V_191 ) ;
struct V_192 * V_193 ;
F_12 ( V_149 -> V_194 == V_195 ||
V_149 -> V_194 == V_196 ||
V_149 -> V_194 == V_197 ) ;
V_193 = & F_91 ( F_92 ( V_187 ) ) -> V_198 ;
V_10 -> V_15 = ( V_149 -> V_199 != V_200 ) &&
( V_149 -> V_194 == V_196 ) &&
( V_193 -> V_201 & V_202 ) ;
if ( V_149 -> V_194 == V_197 ||
( V_10 -> V_15 && F_93 ( V_187 ) ) ||
( F_94 ( V_149 ) &&
( V_193 -> V_201 & V_203 ) &&
V_189 -> V_204 ) ) {
V_10 -> V_15 = 1 ;
V_28 -> V_4 = & V_5 ;
}
}
F_12 ( F_7 ( V_10 -> V_88 , ! F_1 ( V_10 ) ) ) ;
}
static bool F_95 ( const struct V_1 * V_205 ,
const struct V_1 * V_206 )
{
struct V_33 * V_207 = & V_206 -> V_3 . V_94 -> V_35 ;
struct V_33 * V_208 = & V_205 -> V_3 . V_94 -> V_35 ;
if ( V_206 -> V_88 )
return true ;
if ( V_208 -> V_95 == V_122 && V_207 -> V_95 == V_122 )
return true ;
if ( V_206 -> V_19 < V_21 )
return true ;
if ( V_207 -> V_95 >= V_208 -> V_95 &&
V_207 -> V_37 <= V_208 -> V_37 &&
V_207 -> V_38 >= V_208 -> V_38 )
return true ;
return false ;
}
static void F_96 ( const struct V_25 * V_26 ,
struct V_55 * V_56 ,
struct V_1 * V_83 )
{
F_84 ( & V_56 -> V_172 ) ;
F_97 ( & V_83 -> V_209 ) ;
F_86 ( & V_56 -> V_172 ) ;
F_84 ( & V_83 -> V_210 ) ;
while ( ! F_98 ( & V_83 -> V_211 ) ) {
struct V_1 * V_212 ;
V_212 = F_99 ( V_83 -> V_211 . V_213 , struct V_1 ,
V_214 ) ;
F_97 ( & V_212 -> V_214 ) ;
F_45 ( V_26 , V_212 -> V_111 , 0 ) ;
}
F_86 ( & V_83 -> V_210 ) ;
}
static int F_100 ( const struct V_25 * V_26 ,
struct V_55 * V_61 ,
struct V_1 * V_83 )
{
struct V_1 * V_215 ;
struct V_33 * V_216 = & V_83 -> V_3 . V_94 -> V_35 ;
struct V_217 * V_218 = & F_19 ( V_26 ) -> V_219 ;
int V_101 = 0 ;
F_84 ( & V_61 -> V_172 ) ;
F_101 ( & V_83 -> V_209 , & V_61 -> V_220 ) ;
V_221:
F_85 (tmp_oscl, &obj->oo_ol_list,
ols_nextlock_oscobj) {
struct V_33 * V_93 ;
if ( V_215 == V_83 )
break;
V_93 = & V_215 -> V_3 . V_94 -> V_35 ;
if ( V_93 -> V_37 > V_216 -> V_38 ||
V_93 -> V_38 < V_216 -> V_37 )
continue;
if ( V_93 -> V_95 == V_222 )
break;
if ( ! F_1 ( V_83 ) &&
F_95 ( V_83 , V_215 ) )
continue;
F_102 ( V_218 , 1 , V_223 ) ;
V_83 -> V_111 = V_218 ;
F_84 ( & V_215 -> V_210 ) ;
F_101 ( & V_83 -> V_214 ,
& V_215 -> V_211 ) ;
F_86 ( & V_215 -> V_210 ) ;
F_86 ( & V_61 -> V_172 ) ;
V_101 = F_103 ( V_26 , V_218 , 0 ) ;
F_84 ( & V_61 -> V_172 ) ;
if ( V_101 < 0 )
break;
V_83 -> V_111 = NULL ;
goto V_221;
}
F_86 ( & V_61 -> V_172 ) ;
return V_101 ;
}
static int F_104 ( const struct V_25 * V_26 ,
const struct V_27 * V_28 ,
struct V_148 * V_224 , struct V_217 * V_225 )
{
struct V_226 * V_227 = F_19 ( V_26 ) ;
struct V_183 * V_184 = F_89 ( V_26 ) ;
struct V_55 * V_56 = F_35 ( V_28 -> V_99 ) ;
struct V_1 * V_83 = F_10 ( V_28 ) ;
struct V_30 * V_9 = V_28 -> V_94 ;
struct V_228 * V_229 = & V_227 -> V_230 ;
union V_31 * V_32 = & V_227 -> V_231 ;
T_5 V_232 = F_37 ;
void * V_18 = V_83 ;
bool V_233 = false ;
int V_43 ;
F_105 ( F_7 ( V_83 -> V_88 , V_9 -> V_35 . V_95 <= V_122 ) ,
L_8 , V_9 , V_83 ) ;
if ( V_83 -> V_19 == V_21 )
return 0 ;
if ( V_83 -> V_97 & V_52 )
goto V_234;
if ( V_83 -> V_88 ) {
F_12 ( F_106 ( V_83 -> V_235 , ! V_225 ) ) ;
V_233 = true ;
goto V_234;
}
V_43 = F_100 ( V_26 , V_56 , V_83 ) ;
if ( V_43 < 0 )
goto V_113;
if ( F_1 ( V_83 ) ) {
V_83 -> V_19 = V_21 ;
V_184 -> V_236 = 1 ;
return 0 ;
}
V_234:
V_83 -> V_19 = V_103 ;
if ( V_225 ) {
F_107 ( & V_225 -> V_237 ) ;
V_83 -> V_111 = V_225 ;
}
F_108 ( & V_56 -> V_64 -> V_238 , V_229 ) ;
F_14 ( V_26 , V_9 , V_32 ) ;
if ( V_83 -> V_235 ) {
V_83 -> V_89 . V_180 = NULL ;
F_56 ( F_18 ( V_56 ) ) ;
V_232 = F_47 ;
V_18 = V_56 ;
}
V_43 = F_109 ( F_92 ( V_56 ) , V_229 , & V_83 -> V_97 ,
V_32 , & V_83 -> V_110 ,
V_56 -> V_64 -> V_239 ,
V_232 , V_18 ,
& V_83 -> V_89 , V_240 , V_233 ,
V_83 -> V_235 ) ;
if ( ! V_43 ) {
if ( F_1 ( V_83 ) ) {
V_184 -> V_236 = 1 ;
} else if ( ! V_233 ) {
F_12 ( V_83 -> V_19 == V_21 ) ;
F_12 ( V_83 -> V_24 ) ;
F_12 ( V_83 -> V_13 ) ;
}
} else if ( V_83 -> V_235 ) {
F_48 ( V_26 , F_18 ( V_56 ) ) ;
V_43 = 0 ;
}
V_113:
if ( V_43 < 0 ) {
V_83 -> V_19 = V_20 ;
F_96 ( V_26 , V_56 , V_83 ) ;
if ( V_225 )
F_45 ( V_26 , V_225 , V_43 ) ;
}
return V_43 ;
}
static void F_110 ( const struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_6 * V_57 ;
V_57 = V_2 -> V_13 ;
if ( ! V_57 )
return;
if ( V_2 -> V_24 ) {
V_2 -> V_24 = 0 ;
F_111 ( & V_2 -> V_11 , V_2 -> V_89 . V_90 ) ;
V_2 -> V_11 . V_18 = 0ULL ;
}
V_2 -> V_13 = NULL ;
F_12 ( V_2 -> V_87 ) ;
F_112 ( & V_57 -> V_86 , L_3 , V_2 ) ;
F_113 ( V_57 ) ;
V_2 -> V_87 = 0 ;
}
static void F_114 ( const struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
struct V_55 * V_61 = F_35 ( V_28 -> V_99 ) ;
struct V_1 * V_83 = F_10 ( V_28 ) ;
F_11 ( F_5 ( V_83 ) ) ;
F_110 ( V_26 , V_83 ) ;
V_83 -> V_19 = V_20 ;
V_83 -> V_97 &= ~ V_98 ;
F_96 ( V_26 , V_61 , V_83 ) ;
}
static int F_115 ( const struct V_25 * V_26 , void * V_18 ,
T_6 V_241 , const struct V_27 * V_28 )
{
struct V_1 * V_9 = F_10 ( V_28 ) ;
(* V_241)( V_26 , V_18 , L_9 ,
V_9 -> V_13 , V_9 -> V_97 , V_9 -> V_11 . V_18 ,
V_9 -> V_19 , V_9 -> V_111 ) ;
F_116 ( V_26 , V_18 , V_241 , & V_9 -> V_110 ) ;
return 0 ;
}
static void F_117 ( const struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
struct V_1 * V_10 = F_10 ( V_28 ) ;
struct V_55 * V_56 = F_35 ( V_28 -> V_99 ) ;
struct V_33 * V_93 = & V_28 -> V_94 -> V_35 ;
int V_43 ;
F_12 ( ! V_10 -> V_13 ) ;
V_43 = F_49 ( V_56 , V_93 -> V_37 , V_93 -> V_38 ,
V_93 -> V_95 , 0 ) ;
if ( V_43 )
F_41 ( L_10 ,
V_10 , V_43 ) ;
F_96 ( V_26 , V_56 , V_10 ) ;
}
static void F_118 ( const struct V_25 * V_26 ,
const struct V_148 * V_149 ,
struct V_60 * V_61 , struct V_1 * V_83 )
{
struct V_33 * V_93 = & V_83 -> V_3 . V_94 -> V_35 ;
T_4 V_242 ;
T_4 V_243 ;
if ( ! F_119 ( V_149 -> V_164 , V_61 ) )
return;
if ( F_120 ( V_149 -> V_199 == V_244 ) ) {
V_242 = F_34 ( V_61 , V_149 -> V_245 . V_246 . V_247 ) ;
V_243 = F_34 ( V_61 , V_149 -> V_245 . V_246 . V_247 +
V_149 -> V_245 . V_246 . V_248 - 1 ) ;
if ( F_121 ( V_149 ) ) {
V_242 = 0 ;
V_243 = V_249 ;
}
} else {
F_12 ( F_122 ( V_149 ) ) ;
V_242 = V_149 -> V_245 . V_250 . V_251 ;
V_243 = V_149 -> V_245 . V_250 . V_251 ;
}
if ( V_93 -> V_95 >= V_118 &&
V_93 -> V_37 <= V_242 && V_93 -> V_38 >= V_243 ) {
struct V_183 * V_184 = F_89 ( V_26 ) ;
F_12 ( ! V_184 -> V_252 ) ;
V_184 -> V_252 = V_83 ;
}
}
int F_123 ( const struct V_25 * V_26 ,
struct V_60 * V_61 , struct V_30 * V_9 ,
const struct V_148 * V_149 )
{
struct V_1 * V_83 ;
T_2 V_42 = V_9 -> V_35 . V_253 ;
V_83 = F_124 ( V_29 , V_254 ) ;
if ( ! V_83 )
return - V_255 ;
V_83 -> V_19 = V_182 ;
F_125 ( & V_83 -> V_210 ) ;
F_126 ( & V_83 -> V_211 ) ;
F_126 ( & V_83 -> V_214 ) ;
F_126 ( & V_83 -> V_209 ) ;
V_83 -> V_97 = F_16 ( V_42 ) ;
V_83 -> V_235 = ! ! ( V_42 & V_256 ) ;
if ( V_83 -> V_235 )
V_83 -> V_97 |= V_46 ;
if ( V_83 -> V_97 & V_48 ) {
V_83 -> V_97 |= V_257 ;
V_83 -> V_88 = 1 ;
}
F_87 ( V_26 , V_9 , F_35 ( V_61 ) , & V_83 -> V_89 ) ;
F_127 ( V_9 , & V_83 -> V_3 , V_61 , & V_108 ) ;
if ( ! ( V_42 & V_258 ) )
F_44 ( V_26 , V_83 , ( V_42 & V_259 ) ) ;
if ( V_83 -> V_15 && ! ( V_42 & V_49 ) )
V_83 -> V_97 |= V_260 ;
if ( V_149 -> V_199 == V_244 || F_122 ( V_149 ) )
F_118 ( V_26 , V_149 , V_61 , V_83 ) ;
F_128 ( L_11 ,
V_9 , V_83 , V_83 -> V_97 ) ;
return 0 ;
}
struct V_6 * F_129 ( const struct V_25 * V_26 ,
struct V_55 * V_61 , T_4 V_261 ,
enum V_262 V_263 )
{
struct V_226 * V_227 = F_19 ( V_26 ) ;
struct V_228 * V_229 = & V_227 -> V_230 ;
union V_31 * V_32 = & V_227 -> V_231 ;
struct V_7 V_84 ;
struct V_6 * V_9 = NULL ;
enum V_264 V_115 ;
T_1 V_265 ;
F_108 ( & V_61 -> V_64 -> V_238 , V_229 ) ;
F_15 ( V_32 , F_18 ( V_61 ) , V_261 , V_261 ) ;
V_32 -> V_39 . V_40 = V_266 ;
V_265 = V_257 | V_267 ;
if ( V_263 & V_268 )
V_265 |= V_52 ;
V_269:
V_115 = F_130 ( F_92 ( V_61 ) , V_229 , V_171 , V_32 ,
V_270 | V_125 | V_126 , & V_265 , V_61 , & V_84 ,
V_263 & V_271 ) ;
if ( V_115 != 0 ) {
V_9 = F_3 ( & V_84 ) ;
if ( F_131 ( ! V_9 ) )
goto V_269;
}
return V_9 ;
}
