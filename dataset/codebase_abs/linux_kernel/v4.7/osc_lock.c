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
T_1 * V_31 )
{
const struct V_32 * V_33 = & V_9 -> V_34 ;
F_15 ( V_31 , V_33 -> V_35 , V_33 -> V_36 , V_33 -> V_37 ) ;
V_31 -> V_38 . V_39 = V_33 -> V_40 ;
}
static T_2 F_16 ( T_3 V_41 )
{
T_2 V_42 = 0 ;
F_12 ( ( V_41 & ~ V_43 ) == 0 ) ;
if ( V_41 & V_44 )
V_42 |= V_45 ;
if ( V_41 & V_46 )
V_42 |= V_47 ;
if ( V_41 & V_48 )
V_42 |= V_49 ;
if ( V_41 & V_50 )
V_42 |= V_51 ;
return V_42 ;
}
static void F_17 ( const struct V_25 * V_26 ,
struct V_52 * V_53 ,
struct V_6 * V_54 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 = F_18 ( V_53 ) ;
struct V_59 * V_60 = V_53 -> V_61 ;
struct V_62 * V_63 = & F_19 ( V_26 ) -> V_64 ;
unsigned V_65 ;
V_65 = V_66 | V_67 | V_68 | V_69 | V_70 ;
if ( ! V_56 )
V_56 = V_54 -> V_71 ;
F_20 ( V_63 , V_56 ) ;
F_21 ( V_58 ) ;
if ( V_54 ) {
T_2 V_72 ;
F_22 ( V_54 -> V_73 ) ;
F_12 ( V_56 == V_54 -> V_71 ) ;
V_72 = V_56 -> V_74 ;
if ( V_72 > V_54 -> V_75 . V_38 . V_76 )
V_72 = V_54 -> V_75 . V_38 . V_76 + 1 ;
if ( V_72 >= V_60 -> V_77 ) {
F_23 ( V_54 , L_1 ,
V_56 -> V_74 , V_72 ) ;
V_65 |= V_78 ;
V_63 -> V_79 = V_72 ;
} else {
F_23 ( V_54 , L_2 ,
V_56 -> V_74 , V_60 -> V_77 ,
V_54 -> V_75 . V_38 . V_76 ) ;
}
F_24 ( V_54 ) ;
}
F_25 ( V_26 , V_58 , V_63 , V_65 ) ;
F_26 ( V_58 ) ;
}
static void F_27 ( const struct V_25 * V_26 , struct V_1 * V_80 ,
struct V_7 * V_81 , bool V_82 )
{
struct V_6 * V_54 ;
V_54 = F_28 ( V_81 , 0 ) ;
F_12 ( V_54 ) ;
F_29 ( & V_54 -> V_83 , L_3 , V_80 ) ;
V_80 -> V_84 = 1 ;
F_12 ( ! V_80 -> V_13 ) ;
V_80 -> V_13 = V_54 ;
if ( ! V_80 -> V_85 ) {
F_30 ( & V_80 -> V_11 , V_81 ) ;
F_31 ( V_81 , V_80 -> V_86 . V_87 ) ;
V_80 -> V_24 = 1 ;
}
F_32 ( V_54 ) ;
if ( V_54 -> V_23 == V_54 -> V_22 ) {
struct V_88 * V_89 = & V_54 -> V_75 . V_38 ;
struct V_32 * V_90 = & V_80 -> V_3 . V_91 -> V_34 ;
V_90 -> V_92 = F_33 ( V_54 -> V_23 ) ;
V_90 -> V_36 = F_34 ( V_90 -> V_35 , V_89 -> V_93 ) ;
V_90 -> V_37 = F_34 ( V_90 -> V_35 , V_89 -> V_76 ) ;
V_90 -> V_40 = V_89 -> V_39 ;
if ( V_82 ) {
F_12 ( V_80 -> V_94 & V_95 ) ;
F_17 ( V_26 , F_35 ( V_80 -> V_3 . V_96 ) ,
V_54 , NULL ) ;
}
F_11 ( F_5 ( V_80 ) ) ;
}
F_36 ( V_54 ) ;
F_12 ( V_80 -> V_19 != V_21 ) ;
V_80 -> V_19 = V_21 ;
}
static int F_37 ( void * V_18 , struct V_7 * V_81 ,
int V_97 )
{
struct V_1 * V_80 = V_18 ;
struct V_27 * V_28 = & V_80 -> V_3 ;
struct V_25 * V_26 ;
struct V_98 V_99 ;
int V_100 ;
V_26 = F_38 ( & V_99 ) ;
F_12 ( ! F_39 ( V_26 ) ) ;
V_100 = F_40 ( V_97 ) ;
if ( V_80 -> V_19 == V_101 ) {
V_80 -> V_19 = V_102 ;
} else if ( V_80 -> V_19 == V_20 ) {
V_100 = - V_103 ;
} else {
F_41 ( L_4 , V_80 -> V_19 ) ;
F_42 () ;
}
if ( V_100 == 0 )
F_27 ( V_26 , V_80 , V_81 , V_97 == V_104 ) ;
if ( V_80 -> V_15 && V_100 == - V_105 ) {
F_43 ( F_35 ( V_28 -> V_96 ) ) ;
F_12 ( V_28 -> V_4 == & V_106 ) ;
F_44 ( V_26 , V_80 , 1 ) ;
V_80 -> V_19 = V_21 ;
V_100 = 0 ;
} else if ( V_80 -> V_85 && V_100 == - V_107 ) {
F_12 ( V_80 -> V_94 & V_95 ) ;
F_17 ( V_26 , F_35 ( V_28 -> V_96 ) ,
NULL , & V_80 -> V_108 ) ;
V_100 = 0 ;
}
if ( V_80 -> V_109 )
F_45 ( V_26 , V_80 -> V_109 , V_100 ) ;
F_46 ( & V_99 , V_26 ) ;
return V_100 ;
}
static int F_47 ( void * V_18 , struct V_7 * V_81 ,
int V_97 )
{
struct V_52 * V_53 = V_18 ;
struct V_6 * V_54 ;
struct V_25 * V_26 ;
struct V_98 V_99 ;
V_26 = F_38 ( & V_99 ) ;
F_12 ( ! F_39 ( V_26 ) ) ;
if ( V_97 == V_110 ) {
V_97 = V_104 ;
goto V_111;
}
if ( V_97 != V_104 )
goto V_111;
V_54 = F_3 ( V_81 ) ;
F_12 ( V_54 ) ;
F_32 ( V_54 ) ;
F_12 ( V_54 -> V_23 == V_54 -> V_22 ) ;
F_17 ( V_26 , V_53 , V_54 , NULL ) ;
F_36 ( V_54 ) ;
F_4 ( V_54 ) ;
V_111:
F_48 ( V_26 , F_18 ( V_53 ) ) ;
F_46 ( & V_99 , V_26 ) ;
return F_40 ( V_97 ) ;
}
static int F_49 ( struct V_52 * V_58 , T_4 V_93 , T_4 V_76 ,
enum V_112 V_113 , int V_114 )
{
struct V_25 * V_26 ;
struct V_98 V_99 ;
int V_100 = 0 ;
int V_115 = 0 ;
V_26 = F_38 ( & V_99 ) ;
if ( F_39 ( V_26 ) )
return F_50 ( V_26 ) ;
if ( V_113 == V_116 ) {
V_100 = F_51 ( V_26 , V_58 , V_93 , V_76 , 1 ,
V_114 ) ;
F_52 ( V_117 , L_5 ,
V_58 , V_93 , V_76 , V_100 ,
V_114 ? L_6 : L_7 ) ;
if ( V_100 > 0 )
V_100 = 0 ;
}
V_115 = F_53 ( V_26 , V_58 , V_93 , V_76 , V_113 ) ;
if ( V_100 == 0 && V_115 < 0 )
V_100 = V_115 ;
F_46 ( & V_99 , V_26 ) ;
return V_100 ;
}
static int F_54 ( const struct V_25 * V_26 ,
struct V_6 * V_54 ,
void * V_118 , int V_119 )
{
struct V_57 * V_58 = NULL ;
int V_42 = 0 ;
int V_114 ;
enum V_112 V_113 = V_120 ;
F_12 ( V_119 == V_121 ) ;
F_32 ( V_54 ) ;
if ( V_54 -> V_23 != V_54 -> V_22 ) {
V_54 -> V_122 = NULL ;
F_36 ( V_54 ) ;
return 0 ;
}
V_114 = F_55 ( V_54 ) ;
if ( V_54 -> V_23 & ( V_123 | V_124 ) )
V_113 = V_116 ;
if ( V_54 -> V_122 ) {
V_58 = F_18 ( V_54 -> V_122 ) ;
V_54 -> V_122 = NULL ;
F_56 ( V_58 ) ;
}
F_36 ( V_54 ) ;
if ( V_58 ) {
struct V_88 * V_125 = & V_54 -> V_75 . V_38 ;
struct V_62 * V_63 = & F_19 ( V_26 ) -> V_64 ;
T_2 V_126 ;
V_42 = F_49 ( F_35 ( V_58 ) ,
F_34 ( V_58 , V_125 -> V_93 ) ,
F_34 ( V_58 , V_125 -> V_76 ) ,
V_113 , V_114 ) ;
F_32 ( V_54 ) ;
F_21 ( V_58 ) ;
V_126 = F_35 ( V_58 ) -> V_61 -> V_77 ;
V_63 -> V_79 = F_57 ( V_54 , V_126 ) ;
F_25 ( V_26 , V_58 , V_63 , V_78 ) ;
F_26 ( V_58 ) ;
F_36 ( V_54 ) ;
F_48 ( V_26 , V_58 ) ;
}
return V_42 ;
}
static int F_58 ( struct V_6 * V_54 ,
struct V_127 * V_128 , void * V_118 ,
int V_119 )
{
int V_42 = 0 ;
switch ( V_119 ) {
case V_129 : {
struct V_7 V_81 ;
F_59 ( V_54 , & V_81 ) ;
V_42 = F_60 ( & V_81 , V_130 ) ;
if ( V_42 == - V_131 )
V_42 = 0 ;
break;
}
case V_121 : {
struct V_25 * V_26 ;
struct V_98 V_99 ;
V_26 = F_38 ( & V_99 ) ;
if ( F_39 ( V_26 ) ) {
V_42 = F_50 ( V_26 ) ;
break;
}
V_42 = F_54 ( V_26 , V_54 , V_118 , V_119 ) ;
F_46 ( & V_99 , V_26 ) ;
break;
}
default:
F_42 () ;
}
return V_42 ;
}
static int F_61 ( struct V_6 * V_54 , void * V_118 )
{
struct V_132 * V_133 = V_118 ;
struct V_98 V_99 ;
struct V_25 * V_26 ;
struct V_55 * V_56 ;
struct V_134 * V_135 ;
int V_42 ;
F_12 ( F_62 ( V_133 -> V_136 ) == V_137 ) ;
V_26 = F_38 ( & V_99 ) ;
if ( ! F_39 ( V_26 ) ) {
struct V_57 * V_58 = NULL ;
F_32 ( V_54 ) ;
if ( V_54 -> V_122 ) {
V_58 = F_18 ( V_54 -> V_122 ) ;
F_56 ( V_58 ) ;
}
F_36 ( V_54 ) ;
if ( V_58 ) {
V_135 = & V_133 -> V_138 ;
F_63 ( V_135 , & V_139 ) ;
F_64 ( V_135 , & V_140 , V_141 ,
sizeof( * V_56 ) ) ;
V_42 = F_65 ( V_135 ) ;
if ( V_42 == 0 ) {
V_56 = F_66 ( V_135 , & V_140 ) ;
V_42 = F_67 ( V_26 , V_58 , V_56 ) ;
}
if ( ! F_68 ( V_133 -> V_142 ) )
F_69 ( & V_133 -> V_138 ,
& V_140 ,
sizeof( struct V_143 ) ,
V_141 ) ;
F_48 ( V_26 , V_58 ) ;
} else {
F_70 ( V_133 , 1 , NULL , NULL ) ;
V_42 = - V_144 ;
}
F_46 ( & V_99 , V_26 ) ;
} else {
V_42 = F_50 ( V_26 ) ;
}
V_133 -> V_145 = V_42 ;
return V_42 ;
}
static int F_71 ( const struct V_25 * V_26 , struct V_146 * V_147 ,
struct V_148 * V_149 , void * V_150 )
{
struct V_151 * V_152 = V_149 -> V_153 . V_154 ;
if ( F_72 ( V_26 , V_152 ) ||
F_73 ( V_152 -> V_155 ) || F_74 ( V_152 -> V_155 )
) {
( * ( unsigned long * ) V_150 ) ++ ;
return V_156 ;
}
return V_157 ;
}
static unsigned long F_75 ( const struct V_25 * V_26 ,
struct V_52 * V_158 ,
struct V_88 * V_125 )
{
struct V_146 * V_147 = & F_19 ( V_26 ) -> V_159 ;
struct V_57 * V_58 = F_76 ( & V_158 -> V_160 ) ;
unsigned long V_161 = 0 ;
int V_42 ;
V_147 -> V_162 = V_58 ;
V_147 -> V_163 = 1 ;
V_42 = F_77 ( V_26 , V_147 , V_164 , V_147 -> V_162 ) ;
if ( V_42 != 0 )
return V_42 ;
do {
V_42 = F_78 ( V_26 , V_147 , V_158 ,
F_34 ( V_58 , V_125 -> V_93 ) ,
F_34 ( V_58 , V_125 -> V_76 ) ,
F_71 , ( void * ) & V_161 ) ;
if ( V_42 == V_156 )
break;
if ( V_42 == V_165 )
F_79 () ;
} while ( V_42 != V_157 );
F_80 ( V_26 , V_147 ) ;
return V_161 ;
}
unsigned long F_81 ( struct V_6 * V_54 )
{
struct V_98 V_99 ;
struct V_25 * V_26 ;
struct V_52 * V_58 ;
struct V_1 * V_80 ;
unsigned long V_166 ;
bool V_167 = false ;
F_82 () ;
V_26 = F_38 ( & V_99 ) ;
if ( F_39 ( V_26 ) )
return 1 ;
F_12 ( V_54 -> V_73 -> V_168 == V_169 ) ;
V_58 = V_54 -> V_122 ;
if ( V_58 ) {
V_166 = 1 ;
goto V_111;
}
F_83 ( & V_58 -> V_170 ) ;
F_84 (oscl, &obj->oo_ol_list, ols_nextlock_oscobj) {
if ( V_80 -> V_13 && V_80 -> V_13 != V_54 )
continue;
V_167 = true ;
}
F_85 ( & V_58 -> V_170 ) ;
if ( V_167 ) {
V_166 = 1 ;
goto V_111;
}
V_166 = F_75 ( V_26 , V_58 , & V_54 -> V_75 . V_38 ) ;
V_111:
F_46 ( & V_99 , V_26 ) ;
return V_166 ;
}
static void F_86 ( const struct V_25 * V_26 ,
const struct V_30 * V_9 ,
struct V_52 * V_53 ,
struct V_171 * V_172 )
{
V_172 -> V_173 = V_169 ;
V_172 -> V_87 = F_87 ( V_9 -> V_34 . V_92 ) ;
V_172 -> V_174 = F_58 ;
V_172 -> V_175 = V_176 ;
V_172 -> V_177 = F_61 ;
V_172 -> V_178 = V_53 ;
}
static void F_44 ( const struct V_25 * V_26 ,
struct V_1 * V_10 , int V_179 )
{
struct V_27 * V_28 = & V_10 -> V_3 ;
F_12 ( V_10 -> V_19 == V_180 ||
V_10 -> V_19 == V_102 ) ;
if ( V_179 ) {
V_10 -> V_15 = 1 ;
V_28 -> V_4 = & V_5 ;
} else {
struct V_181 * V_182 = F_88 ( V_26 ) ;
struct V_146 * V_147 = V_182 -> V_183 . V_184 ;
struct V_57 * V_58 = V_28 -> V_96 ;
struct V_52 * V_185 = F_35 ( V_58 ) ;
const struct V_186 * V_187 = F_89 ( V_58 -> V_188 . V_189 ) ;
struct V_190 * V_191 ;
F_12 ( V_147 -> V_192 == V_193 ||
V_147 -> V_192 == V_194 ||
V_147 -> V_192 == V_195 ) ;
V_191 = & F_90 ( F_91 ( V_185 ) ) -> V_196 ;
V_10 -> V_15 = ( V_147 -> V_197 != V_198 ) &&
( V_147 -> V_192 == V_194 ) &&
( V_191 -> V_199 & V_200 ) ;
if ( V_147 -> V_192 == V_195 ||
( V_10 -> V_15 && F_92 ( V_185 ) ) ||
( F_93 ( V_147 ) &&
( V_191 -> V_199 & V_201 ) &&
V_187 -> V_202 ) ) {
V_10 -> V_15 = 1 ;
V_28 -> V_4 = & V_5 ;
}
}
F_12 ( F_7 ( V_10 -> V_85 , ! F_1 ( V_10 ) ) ) ;
}
static bool F_94 ( const struct V_1 * V_203 ,
const struct V_1 * V_204 )
{
struct V_32 * V_205 = & V_204 -> V_3 . V_91 -> V_34 ;
struct V_32 * V_206 = & V_203 -> V_3 . V_91 -> V_34 ;
if ( V_204 -> V_85 )
return true ;
if ( V_206 -> V_92 == V_120 && V_205 -> V_92 == V_120 )
return true ;
if ( V_204 -> V_19 < V_21 )
return true ;
if ( V_205 -> V_92 >= V_206 -> V_92 &&
V_205 -> V_36 <= V_206 -> V_36 &&
V_205 -> V_37 >= V_206 -> V_37 )
return true ;
return false ;
}
static void F_95 ( const struct V_25 * V_26 ,
struct V_52 * V_53 ,
struct V_1 * V_80 )
{
F_83 ( & V_53 -> V_170 ) ;
F_96 ( & V_80 -> V_207 ) ;
F_85 ( & V_53 -> V_170 ) ;
F_83 ( & V_80 -> V_208 ) ;
while ( ! F_97 ( & V_80 -> V_209 ) ) {
struct V_1 * V_210 ;
V_210 = F_98 ( V_80 -> V_209 . V_211 , struct V_1 ,
V_212 ) ;
F_96 ( & V_210 -> V_212 ) ;
F_45 ( V_26 , V_210 -> V_109 , 0 ) ;
}
F_85 ( & V_80 -> V_208 ) ;
}
static void F_99 ( const struct V_25 * V_26 ,
struct V_52 * V_58 ,
struct V_1 * V_80 )
{
struct V_1 * V_213 ;
struct V_32 * V_214 = & V_80 -> V_3 . V_91 -> V_34 ;
struct V_215 * V_216 = & F_19 ( V_26 ) -> V_217 ;
F_83 ( & V_58 -> V_170 ) ;
F_100 ( & V_80 -> V_207 , & V_58 -> V_218 ) ;
V_219:
F_84 (tmp_oscl, &obj->oo_ol_list,
ols_nextlock_oscobj) {
struct V_32 * V_90 ;
if ( V_213 == V_80 )
break;
V_90 = & V_213 -> V_3 . V_91 -> V_34 ;
if ( V_90 -> V_36 > V_214 -> V_37 ||
V_90 -> V_37 < V_214 -> V_36 )
continue;
if ( V_90 -> V_92 == V_220 )
break;
if ( ! F_1 ( V_80 ) &&
F_94 ( V_80 , V_213 ) )
continue;
F_101 ( V_216 , 1 , V_221 ) ;
V_80 -> V_109 = V_216 ;
F_83 ( & V_213 -> V_208 ) ;
F_100 ( & V_80 -> V_212 ,
& V_213 -> V_209 ) ;
F_85 ( & V_213 -> V_208 ) ;
F_85 ( & V_58 -> V_170 ) ;
( void ) F_102 ( V_26 , V_216 , 0 ) ;
F_83 ( & V_58 -> V_170 ) ;
V_80 -> V_109 = NULL ;
goto V_219;
}
F_85 ( & V_58 -> V_170 ) ;
}
static int F_103 ( const struct V_25 * V_26 ,
const struct V_27 * V_28 ,
struct V_146 * V_222 , struct V_215 * V_223 )
{
struct V_224 * V_225 = F_19 ( V_26 ) ;
struct V_181 * V_182 = F_88 ( V_26 ) ;
struct V_52 * V_53 = F_35 ( V_28 -> V_96 ) ;
struct V_1 * V_80 = F_10 ( V_28 ) ;
struct V_30 * V_9 = V_28 -> V_91 ;
struct V_226 * V_227 = & V_225 -> V_228 ;
T_1 * V_31 = & V_225 -> V_229 ;
T_5 V_230 = F_37 ;
void * V_18 = V_80 ;
bool V_231 = false ;
int V_42 ;
F_104 ( F_7 ( V_80 -> V_85 , V_9 -> V_34 . V_92 <= V_120 ) ,
L_8 , V_9 , V_80 ) ;
if ( V_80 -> V_19 == V_21 )
return 0 ;
if ( V_80 -> V_94 & V_51 )
goto V_232;
if ( V_80 -> V_85 ) {
F_12 ( F_105 ( V_80 -> V_233 , ! V_223 ) ) ;
V_231 = true ;
goto V_232;
}
F_99 ( V_26 , V_53 , V_80 ) ;
if ( F_1 ( V_80 ) ) {
V_80 -> V_19 = V_21 ;
V_182 -> V_234 = 1 ;
return 0 ;
}
V_232:
V_80 -> V_19 = V_101 ;
if ( V_223 ) {
F_106 ( & V_223 -> V_235 ) ;
V_80 -> V_109 = V_223 ;
}
F_107 ( & V_53 -> V_61 -> V_236 , V_227 ) ;
F_86 ( V_26 , V_9 , V_53 , & V_80 -> V_86 ) ;
F_14 ( V_26 , V_9 , V_31 ) ;
if ( V_80 -> V_233 ) {
V_80 -> V_86 . V_178 = NULL ;
F_56 ( F_18 ( V_53 ) ) ;
V_230 = F_47 ;
V_18 = V_53 ;
}
V_42 = F_108 ( F_91 ( V_53 ) , V_227 , & V_80 -> V_94 ,
V_31 , & V_80 -> V_108 ,
V_53 -> V_61 -> V_237 ,
V_230 , V_18 ,
& V_80 -> V_86 , V_238 , V_231 ,
V_80 -> V_233 ) ;
if ( V_42 != 0 ) {
V_80 -> V_19 = V_20 ;
F_95 ( V_26 , V_53 , V_80 ) ;
if ( V_80 -> V_233 ) {
F_48 ( V_26 , F_18 ( V_53 ) ) ;
V_42 = 0 ;
}
if ( V_223 )
F_45 ( V_26 , V_223 , V_42 ) ;
} else {
if ( F_1 ( V_80 ) ) {
V_182 -> V_234 = 1 ;
} else if ( ! V_231 ) {
F_12 ( V_80 -> V_19 == V_21 ) ;
F_12 ( V_80 -> V_24 ) ;
F_12 ( V_80 -> V_13 ) ;
}
}
return V_42 ;
}
static void F_109 ( const struct V_25 * V_26 , struct V_1 * V_2 )
{
struct V_6 * V_54 ;
V_54 = V_2 -> V_13 ;
if ( ! V_54 )
return;
if ( V_2 -> V_24 ) {
V_2 -> V_24 = 0 ;
F_110 ( & V_2 -> V_11 , V_2 -> V_86 . V_87 ) ;
V_2 -> V_11 . V_18 = 0ULL ;
}
V_2 -> V_13 = NULL ;
F_12 ( V_2 -> V_84 ) ;
F_111 ( & V_54 -> V_83 , L_3 , V_2 ) ;
F_112 ( V_54 ) ;
V_2 -> V_84 = 0 ;
}
static void F_113 ( const struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
struct V_52 * V_58 = F_35 ( V_28 -> V_96 ) ;
struct V_1 * V_80 = F_10 ( V_28 ) ;
F_11 ( F_5 ( V_80 ) ) ;
F_109 ( V_26 , V_80 ) ;
V_80 -> V_19 = V_20 ;
V_80 -> V_94 &= ~ V_95 ;
F_95 ( V_26 , V_58 , V_80 ) ;
}
static int F_114 ( const struct V_25 * V_26 , void * V_18 ,
T_6 V_239 , const struct V_27 * V_28 )
{
struct V_1 * V_9 = F_10 ( V_28 ) ;
(* V_239)( V_26 , V_18 , L_9 ,
V_9 -> V_13 , V_9 -> V_94 , V_9 -> V_11 . V_18 ,
V_9 -> V_19 , V_9 -> V_109 ) ;
F_115 ( V_26 , V_18 , V_239 , & V_9 -> V_108 ) ;
return 0 ;
}
static void F_116 ( const struct V_25 * V_26 ,
const struct V_27 * V_28 )
{
struct V_1 * V_10 = F_10 ( V_28 ) ;
struct V_52 * V_53 = F_35 ( V_28 -> V_96 ) ;
struct V_32 * V_90 = & V_28 -> V_91 -> V_34 ;
int V_42 ;
F_12 ( ! V_10 -> V_13 ) ;
V_42 = F_49 ( V_53 , V_90 -> V_36 , V_90 -> V_37 ,
V_90 -> V_92 , 0 ) ;
if ( V_42 )
F_41 ( L_10 ,
V_10 , V_42 ) ;
F_95 ( V_26 , V_53 , V_10 ) ;
}
static void F_117 ( const struct V_25 * V_26 ,
const struct V_146 * V_147 ,
struct V_57 * V_58 , struct V_1 * V_80 )
{
struct V_32 * V_90 = & V_80 -> V_3 . V_91 -> V_34 ;
T_4 V_240 ;
T_4 V_241 ;
if ( ! F_118 ( V_147 -> V_162 , V_58 ) )
return;
if ( F_119 ( V_147 -> V_197 == V_242 ) ) {
V_240 = F_34 ( V_58 , V_147 -> V_243 . V_244 . V_245 ) ;
V_241 = F_34 ( V_58 , V_147 -> V_243 . V_244 . V_245 +
V_147 -> V_243 . V_244 . V_246 - 1 ) ;
if ( F_120 ( V_147 ) ) {
V_240 = 0 ;
V_241 = V_247 ;
}
} else {
F_12 ( F_121 ( V_147 ) ) ;
V_240 = V_241 = V_147 -> V_243 . V_248 . V_249 ;
}
if ( V_90 -> V_92 >= V_116 &&
V_90 -> V_36 <= V_240 && V_90 -> V_37 >= V_241 ) {
struct V_181 * V_182 = F_88 ( V_26 ) ;
F_12 ( ! V_182 -> V_250 ) ;
V_182 -> V_250 = V_80 ;
}
}
int F_122 ( const struct V_25 * V_26 ,
struct V_57 * V_58 , struct V_30 * V_9 ,
const struct V_146 * V_147 )
{
struct V_1 * V_80 ;
T_3 V_41 = V_9 -> V_34 . V_251 ;
V_80 = F_123 ( V_29 , V_252 ) ;
if ( ! V_80 )
return - V_253 ;
V_80 -> V_19 = V_180 ;
F_124 ( & V_80 -> V_208 ) ;
F_125 ( & V_80 -> V_209 ) ;
F_125 ( & V_80 -> V_212 ) ;
F_125 ( & V_80 -> V_207 ) ;
V_80 -> V_94 = F_16 ( V_41 ) ;
V_80 -> V_233 = ! ! ( V_41 & V_254 ) ;
if ( V_80 -> V_233 )
V_80 -> V_94 |= V_45 ;
if ( V_80 -> V_94 & V_47 ) {
V_80 -> V_94 |= V_255 ;
V_80 -> V_85 = 1 ;
}
F_126 ( V_9 , & V_80 -> V_3 , V_58 , & V_106 ) ;
if ( ! ( V_41 & V_256 ) )
F_44 ( V_26 , V_80 , ( V_41 & V_257 ) ) ;
if ( V_80 -> V_15 && ! ( V_41 & V_48 ) )
V_80 -> V_94 |= V_258 ;
if ( V_147 -> V_197 == V_242 || F_121 ( V_147 ) )
F_117 ( V_26 , V_147 , V_58 , V_80 ) ;
F_127 ( L_11 ,
V_9 , V_80 , V_80 -> V_94 ) ;
return 0 ;
}
struct V_6 * F_128 ( const struct V_25 * V_26 ,
struct V_52 * V_58 , T_4 V_259 ,
int V_260 , int V_261 )
{
struct V_224 * V_225 = F_19 ( V_26 ) ;
struct V_226 * V_227 = & V_225 -> V_228 ;
T_1 * V_31 = & V_225 -> V_229 ;
struct V_7 V_81 ;
struct V_6 * V_9 = NULL ;
enum V_262 V_113 ;
T_2 V_263 ;
F_107 ( & V_58 -> V_61 -> V_236 , V_227 ) ;
F_15 ( V_31 , F_18 ( V_58 ) , V_259 , V_259 ) ;
V_31 -> V_38 . V_39 = V_264 ;
V_263 = V_255 | V_51 ;
if ( V_260 )
V_263 |= V_265 ;
V_266:
V_113 = F_129 ( F_91 ( V_58 ) -> V_267 -> V_268 ,
V_263 , V_227 , V_169 , V_31 ,
V_269 | V_123 | V_124 , & V_81 , V_261 ) ;
if ( V_113 != 0 ) {
V_9 = F_3 ( & V_81 ) ;
if ( F_130 ( ! V_9 ) )
goto V_266;
}
return V_9 ;
}
