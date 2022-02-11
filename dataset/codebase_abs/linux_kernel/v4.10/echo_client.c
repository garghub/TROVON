static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_2 * F_3 ( struct V_1 * V_5 )
{
return & V_5 -> V_4 ;
}
static inline struct V_1 * F_4 ( const struct V_6 * V_7 )
{
return F_1 ( F_5 ( V_7 -> V_8 ) ) ;
}
static inline struct V_9 * F_6 ( struct V_10 * V_11 )
{
return & V_11 -> V_12 ;
}
static inline struct V_10 * F_7 ( const struct V_9 * V_13 )
{
return F_8 ( V_13 , struct V_10 , V_12 ) ;
}
static inline struct V_14 * F_9 ( const struct V_15 * V_16 )
{
return F_8 ( V_16 , struct V_14 , V_17 ) ;
}
static inline struct V_18 * F_10 ( const struct V_19 * V_16 )
{
return F_8 ( V_16 , struct V_18 , V_20 ) ;
}
static inline struct V_21 * F_11 ( const struct V_18 * V_22 )
{
return V_22 -> V_20 . V_23 ;
}
static inline struct V_24 * F_12 ( const struct V_25 * V_26 )
{
struct V_24 * V_27 ;
V_27 = F_13 ( & V_26 -> V_28 , & V_29 ) ;
F_14 ( V_27 ) ;
return V_27 ;
}
static inline
struct V_30 * F_15 ( const struct V_31 * V_32 )
{
return F_8 ( V_32 , struct V_30 , V_33 ) ;
}
static int F_16 ( const struct V_25 * V_26 ,
const struct V_15 * V_34 ,
struct V_35 * V_36 , int V_37 )
{
struct V_14 * V_38 = F_9 ( V_34 ) ;
if ( ! V_37 )
F_17 ( & V_38 -> V_39 ) ;
else if ( ! F_18 ( & V_38 -> V_39 ) )
return - V_40 ;
return 0 ;
}
static void F_19 ( const struct V_25 * V_26 ,
const struct V_15 * V_34 ,
struct V_35 * V_36 )
{
struct V_14 * V_38 = F_9 ( V_34 ) ;
F_14 ( F_20 ( & V_38 -> V_39 ) ) ;
F_21 ( & V_38 -> V_39 ) ;
}
static void F_22 ( const struct V_25 * V_26 ,
const struct V_15 * V_34 ,
struct V_35 * V_41 )
{
F_23 ( V_26 , V_34 -> V_42 ) ;
}
static int F_24 ( const struct V_25 * V_26 ,
const struct V_15 * V_34 )
{
if ( F_20 ( & F_9 ( V_34 ) -> V_39 ) )
return - V_43 ;
return - V_44 ;
}
static void F_25 ( const struct V_25 * V_26 ,
const struct V_15 * V_34 ,
int V_45 )
{
F_14 ( V_34 -> V_42 -> V_46 ) ;
}
static void F_26 ( const struct V_25 * V_26 ,
struct V_15 * V_34 )
{
struct V_10 * V_11 = F_7 ( V_34 -> V_47 ) ;
F_27 ( & V_11 -> V_48 ) ;
F_28 ( V_34 -> V_42 -> V_49 ) ;
}
static int F_29 ( const struct V_25 * V_26 ,
const struct V_15 * V_34 ,
struct V_35 * V_41 )
{
return 0 ;
}
static int F_30 ( const struct V_25 * V_26 ,
const struct V_15 * V_34 ,
void * V_50 , T_1 V_51 )
{
struct V_14 * V_38 = F_9 ( V_34 ) ;
(* V_51)( V_26 , V_50 , V_52 L_1 ,
V_38 , F_20 ( & V_38 -> V_39 ) ,
V_34 -> V_42 -> V_49 ) ;
return 0 ;
}
static void F_31 ( const struct V_25 * V_26 ,
struct V_19 * V_34 )
{
struct V_18 * V_22 = F_10 ( V_34 ) ;
F_14 ( F_32 ( & V_22 -> V_53 ) ) ;
F_33 ( V_54 , V_22 ) ;
}
static int F_34 ( const struct V_25 * V_26 , struct V_9 * V_55 ,
struct V_56 * V_57 , T_2 V_58 )
{
struct V_14 * V_38 = F_35 ( V_55 , V_57 ) ;
struct V_10 * V_11 = F_7 ( V_55 ) ;
F_36 ( V_57 -> V_49 ) ;
F_37 ( & V_38 -> V_39 ) ;
F_38 ( V_57 , & V_38 -> V_17 , V_55 , V_58 , & V_59 ) ;
F_39 ( & V_11 -> V_48 ) ;
return 0 ;
}
static int F_40 ( const struct V_25 * V_26 , struct V_9 * V_55 ,
struct V_35 * V_36 )
{
return 0 ;
}
static int F_41 ( const struct V_25 * V_26 ,
struct V_9 * V_55 , struct V_21 * V_60 ,
const struct V_35 * V_41 )
{
struct V_18 * V_61 ;
V_61 = F_42 ( V_54 , V_62 ) ;
if ( V_61 ) {
F_43 ( V_60 , & V_61 -> V_20 , V_55 , & V_63 ) ;
V_61 -> V_64 = F_7 ( V_55 ) ;
F_44 ( & V_61 -> V_53 ) ;
F_45 ( & V_61 -> V_65 , 0 ) ;
}
return ! V_61 ? - V_66 : 0 ;
}
static int F_46 ( const struct V_25 * V_26 , struct V_9 * V_55 ,
const struct V_31 * V_67 )
{
return 0 ;
}
static int F_47 ( const struct V_25 * V_26 , struct V_68 * V_55 ,
const struct V_69 * V_67 )
{
struct V_1 * V_70 = F_1 ( F_5 ( V_55 -> V_71 ) ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_10 * V_11 = F_7 ( F_48 ( V_55 ) ) ;
const struct V_31 * V_75 ;
struct V_30 * V_76 ;
if ( V_70 -> V_77 ) {
struct V_68 * V_78 ;
struct V_79 * V_80 ;
V_80 = V_70 -> V_77 ;
V_78 = V_80 -> V_81 -> V_82 ( V_26 , V_55 -> V_83 ,
V_80 ) ;
if ( ! V_78 )
return - V_66 ;
F_49 ( V_55 , V_78 ) ;
}
V_75 = F_50 ( V_67 ) ;
V_76 = F_15 ( V_75 ) ;
F_14 ( V_76 -> V_84 ) ;
V_11 -> V_85 = * V_76 -> V_84 ;
* V_76 -> V_84 = NULL ;
V_11 -> V_86 = V_70 ;
F_45 ( & V_11 -> V_48 , 0 ) ;
F_51 ( F_48 ( V_55 ) , sizeof( struct V_14 ) ) ;
F_52 ( & V_73 -> V_87 ) ;
F_53 ( & V_11 -> V_88 , & V_73 -> V_89 ) ;
F_54 ( & V_73 -> V_87 ) ;
return 0 ;
}
static void F_55 ( const struct V_25 * V_26 , struct V_68 * V_55 )
{
struct V_10 * V_11 = F_7 ( F_48 ( V_55 ) ) ;
struct V_72 * V_73 = V_11 -> V_86 -> V_74 ;
F_14 ( F_56 ( & V_11 -> V_48 ) == 0 ) ;
F_52 ( & V_73 -> V_87 ) ;
F_57 ( & V_11 -> V_88 ) ;
F_54 ( & V_73 -> V_87 ) ;
F_58 ( V_55 ) ;
F_59 ( V_55 -> V_83 ) ;
F_60 ( V_11 -> V_85 ) ;
F_33 ( V_90 , V_11 ) ;
}
static int F_61 ( const struct V_25 * V_26 , void * V_50 ,
T_1 V_91 , const struct V_68 * V_13 )
{
struct V_10 * V_55 = F_7 ( F_48 ( V_13 ) ) ;
return (* V_91)( V_26 , V_50 , L_2 , V_55 ) ;
}
static struct V_68 * F_62 ( const struct V_25 * V_26 ,
const struct V_92 * V_93 ,
struct V_79 * V_3 )
{
struct V_10 * V_11 ;
struct V_68 * V_55 = NULL ;
F_14 ( ! V_93 ) ;
V_11 = F_42 ( V_90 , V_62 ) ;
if ( V_11 ) {
struct V_94 * V_93 = & V_11 -> V_95 ;
V_55 = & F_6 ( V_11 ) -> V_96 ;
F_63 ( V_93 ) ;
V_93 -> V_97 = F_64 ( sizeof( struct V_56 ) ) ;
F_65 ( V_55 , & V_93 -> V_98 , V_3 ) ;
F_66 ( & V_93 -> V_98 , V_55 ) ;
V_11 -> V_12 . V_99 = & V_100 ;
V_55 -> V_101 = & V_102 ;
}
return V_55 ;
}
static int F_67 ( const struct V_25 * V_26 , struct V_1 * V_70 )
{
struct V_103 * V_104 = & V_70 -> V_105 ;
int V_106 ;
V_106 = F_68 ( V_104 , & V_70 -> V_4 ) ;
if ( V_106 ) {
F_69 ( L_3 , V_106 ) ;
return V_106 ;
}
V_106 = F_70 ( & V_104 -> V_107 ) ;
if ( V_106 ) {
F_71 ( V_104 ) ;
return V_106 ;
}
V_70 -> V_108 = & V_104 -> V_107 ;
return 0 ;
}
static void F_72 ( const struct V_25 * V_26 , struct V_1 * V_70 )
{
if ( V_70 -> V_108 ) {
F_73 ( V_70 -> V_108 ) ;
V_70 -> V_108 = NULL ;
}
}
static void * F_74 ( const struct V_109 * V_110 ,
struct V_111 * V_112 )
{
struct V_24 * V_27 ;
V_27 = F_42 ( V_113 , V_62 ) ;
if ( ! V_27 )
V_27 = F_75 ( - V_66 ) ;
return V_27 ;
}
static void F_76 ( const struct V_109 * V_110 ,
struct V_111 * V_112 , void * V_114 )
{
struct V_24 * V_27 = V_114 ;
F_33 ( V_113 , V_27 ) ;
}
static void * F_77 ( const struct V_109 * V_110 ,
struct V_111 * V_112 )
{
struct V_115 * V_116 ;
V_116 = F_42 ( V_117 , V_62 ) ;
if ( ! V_116 )
V_116 = F_75 ( - V_66 ) ;
return V_116 ;
}
static void F_78 ( const struct V_109 * V_110 ,
struct V_111 * V_112 , void * V_114 )
{
struct V_115 * V_116 = V_114 ;
F_33 ( V_117 , V_116 ) ;
}
static struct V_79 * F_79 ( const struct V_25 * V_26 ,
struct V_118 * V_119 ,
struct V_120 * V_121 )
{
struct V_79 * V_122 ;
struct V_1 * V_70 ;
struct V_2 * V_123 ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_124 ;
const char * V_125 ;
int V_106 , V_126 ;
V_70 = F_80 ( sizeof( * V_70 ) , V_62 ) ;
if ( ! V_70 ) {
V_106 = - V_66 ;
goto V_127;
}
V_123 = & V_70 -> V_4 ;
V_106 = F_81 ( V_123 , V_119 ) ;
if ( V_106 )
goto V_128;
V_123 -> V_129 . V_81 = & V_130 ;
V_7 = F_82 ( F_83 ( V_121 , 0 ) ) ;
F_14 ( V_7 ) ;
F_14 ( V_26 ) ;
V_124 = F_82 ( F_83 ( V_121 , 1 ) ) ;
if ( ! V_124 ) {
F_69 ( L_4 ,
F_83 ( V_121 , 1 ) ) ;
V_106 = - V_131 ;
goto V_132;
}
V_122 = V_124 -> V_8 ;
if ( ! strcmp ( V_124 -> V_133 -> V_134 , V_135 ) ) {
F_69 ( L_5 ) ;
V_106 = - V_136 ;
goto V_132;
}
V_106 = F_67 ( V_26 , V_70 ) ;
if ( V_106 )
goto V_132;
V_106 = F_84 ( V_26 , V_7 , V_121 ) ;
if ( V_106 )
goto V_137;
V_70 -> V_74 = & V_7 -> V_138 . V_139 ;
if ( V_122 && ! F_85 ( V_122 ) )
V_122 = NULL ;
V_125 = V_124 -> V_133 -> V_134 ;
if ( V_122 ) {
if ( V_122 -> V_140 ) {
V_106 = - V_43 ;
goto V_141;
}
V_122 -> V_140 = V_70 -> V_108 ;
V_106 = V_122 -> V_142 -> V_143 -> V_144 ( V_26 , V_122 ,
V_122 -> V_142 -> V_145 ,
NULL ) ;
if ( V_106 )
goto V_141;
} else {
F_14 ( strcmp ( V_125 , V_146 ) == 0 ) ;
}
V_70 -> V_77 = V_122 ;
return & V_123 -> V_129 ;
V_141:
V_126 = F_86 ( V_7 ) ;
if ( V_126 )
F_69 ( L_6 ,
V_7 -> V_147 , V_126 ) ;
V_137:
F_72 ( V_26 , V_70 ) ;
V_132:
F_87 ( & V_70 -> V_4 ) ;
V_128:
F_60 ( V_70 ) ;
V_127:
return F_75 ( V_106 ) ;
}
static int F_88 ( const struct V_25 * V_26 , struct V_79 * V_5 ,
const char * V_148 , struct V_79 * V_122 )
{
F_89 () ;
return 0 ;
}
static struct V_79 * F_90 ( const struct V_25 * V_26 ,
struct V_79 * V_5 )
{
struct V_1 * V_70 = F_1 ( F_5 ( V_5 ) ) ;
struct V_79 * V_122 = V_70 -> V_77 ;
while ( V_122 )
V_122 = V_122 -> V_142 -> V_143 -> V_149 ( V_26 , V_122 ) ;
return NULL ;
}
static void F_91 ( const struct V_25 * V_26 ,
struct V_18 * V_22 ,
int V_150 )
{
struct V_21 * V_151 = F_11 ( V_22 ) ;
F_92 ( V_26 , V_151 ) ;
}
static struct V_79 * F_93 ( const struct V_25 * V_26 ,
struct V_79 * V_5 )
{
struct V_1 * V_70 = F_1 ( F_5 ( V_5 ) ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_10 * V_11 ;
struct V_79 * V_122 = V_70 -> V_77 ;
F_94 ( V_152 , L_7 ,
V_70 , V_122 ) ;
F_95 ( V_26 , V_70 -> V_108 , - 1 ) ;
F_52 ( & V_73 -> V_87 ) ;
F_96 (eco, &ec->ec_objects, eo_obj_chain)
V_11 -> V_153 = 1 ;
F_54 ( & V_73 -> V_87 ) ;
F_95 ( V_26 , V_70 -> V_108 , - 1 ) ;
F_94 ( V_152 ,
L_8 ) ;
F_52 ( & V_73 -> V_87 ) ;
while ( ! F_32 ( & V_73 -> V_89 ) ) {
F_54 ( & V_73 -> V_87 ) ;
F_69 ( L_9 ) ;
F_97 ( V_154 ) ;
F_98 ( F_99 ( 1 ) ) ;
F_95 ( V_26 , V_70 -> V_108 , - 1 ) ;
F_52 ( & V_73 -> V_87 ) ;
}
F_54 ( & V_73 -> V_87 ) ;
F_14 ( F_32 ( & V_73 -> V_155 ) ) ;
F_94 ( V_152 , L_10 ) ;
F_86 ( V_5 -> V_156 ) ;
while ( V_122 )
V_122 = V_122 -> V_142 -> V_143 -> V_157 ( V_26 , V_122 ) ;
F_14 ( V_70 -> V_108 == V_5 -> V_140 ) ;
F_72 ( V_26 , V_70 ) ;
F_87 ( & V_70 -> V_4 ) ;
F_60 ( V_70 ) ;
F_100 ( ~ 0 ) ;
return NULL ;
}
static struct V_10 *
F_101 ( struct V_1 * V_5 , const struct V_158 * V_159 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_30 * V_67 ;
struct V_160 * V_161 = NULL ;
struct V_10 * V_11 ;
struct V_9 * V_55 ;
struct V_162 * V_163 ;
int V_164 ;
int V_106 ;
F_102 ( F_103 ( V_159 ) , V_165 L_11 , F_104 ( V_159 ) ) ;
F_102 ( F_105 ( V_159 ) == V_166 , V_165 L_11 , F_104 ( V_159 ) ) ;
if ( F_3 ( V_5 ) -> V_129 . V_156 -> V_167 )
return F_75 ( - V_131 ) ;
V_26 = F_106 ( & V_164 ) ;
if ( F_107 ( V_26 ) )
return ( void * ) V_26 ;
V_27 = F_12 ( V_26 ) ;
V_67 = & V_27 -> V_168 ;
if ( V_5 -> V_77 ) {
V_161 = F_80 ( sizeof( * V_161 ) , V_62 ) ;
if ( ! V_161 ) {
V_11 = F_75 ( - V_66 ) ;
goto V_127;
}
V_161 -> V_169 = * V_159 ;
V_67 -> V_33 . V_138 . V_170 = V_161 ;
}
V_67 -> V_84 = & V_161 ;
V_163 = & V_27 -> V_171 ;
V_106 = F_108 ( V_163 , (struct V_158 * ) V_159 , 0 ) ;
if ( V_106 != 0 ) {
V_11 = F_75 ( V_106 ) ;
goto V_127;
}
V_55 = F_109 ( V_26 , F_3 ( V_5 ) , V_163 , & V_67 -> V_33 ) ;
if ( F_107 ( V_55 ) ) {
V_11 = ( void * ) V_55 ;
goto V_127;
}
V_11 = F_7 ( V_55 ) ;
if ( V_11 -> V_153 ) {
F_110 ( V_26 , V_55 ) ;
V_11 = F_75 ( - V_40 ) ;
}
V_127:
F_60 ( V_161 ) ;
F_111 ( V_26 , & V_164 ) ;
return V_11 ;
}
static int F_112 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
struct V_9 * V_55 = F_6 ( V_11 ) ;
int V_164 ;
V_26 = F_106 ( & V_164 ) ;
if ( F_107 ( V_26 ) )
return F_113 ( V_26 ) ;
if ( V_11 -> V_153 ) {
struct V_92 * V_172 = V_55 -> V_96 . V_83 ;
F_14 ( & V_11 -> V_95 == F_114 ( V_172 ) ) ;
F_115 ( V_173 , & V_172 -> V_174 ) ;
}
F_110 ( V_26 , V_55 ) ;
F_111 ( V_26 , & V_164 ) ;
return 0 ;
}
static int F_116 ( struct V_25 * V_26 , struct V_10 * V_11 ,
T_3 V_175 , T_3 V_176 , int V_177 ,
T_4 * V_50 , T_5 V_178 )
{
struct V_35 * V_36 ;
struct V_21 * V_179 ;
struct V_9 * V_55 ;
struct V_180 * V_181 ;
struct V_24 * V_27 ;
int V_106 = - V_66 ;
V_27 = F_12 ( V_26 ) ;
V_36 = & V_27 -> V_182 ;
V_179 = & V_27 -> V_183 ;
V_55 = F_6 ( V_11 ) ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
V_181 = & V_179 -> V_184 ;
V_181 -> V_185 = V_55 ;
V_181 -> V_186 = F_117 ( V_55 , V_175 ) ;
V_181 -> V_187 = F_117 ( V_55 , V_176 ) ;
V_181 -> V_188 = V_177 == V_189 ? V_190 : V_191 ;
V_181 -> V_192 = V_178 ;
V_36 -> V_193 = V_55 ;
V_106 = F_118 ( V_26 , V_36 , V_179 ) ;
if ( V_106 == 0 ) {
struct V_72 * V_73 = V_11 -> V_86 -> V_74 ;
struct V_18 * V_61 ;
V_61 = F_10 ( F_119 ( V_179 , & V_194 ) ) ;
F_52 ( & V_73 -> V_87 ) ;
if ( F_32 ( & V_61 -> V_53 ) ) {
F_120 ( & V_61 -> V_53 , & V_73 -> V_155 ) ;
V_61 -> V_195 = ++ V_73 -> V_196 ;
}
F_39 ( & V_61 -> V_65 ) ;
* V_50 = V_61 -> V_195 ;
F_54 ( & V_73 -> V_87 ) ;
}
return V_106 ;
}
static int F_121 ( struct V_25 * V_26 , struct V_1 * V_70 ,
T_4 V_50 )
{
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_18 * V_22 = NULL ;
struct V_197 * V_61 ;
int V_198 = 0 , V_150 = 0 ;
F_52 ( & V_73 -> V_87 ) ;
F_122 (el, &ec->ec_locks) {
V_22 = F_123 ( V_61 , struct V_18 , V_53 ) ;
F_94 ( V_152 , L_12 , V_22 , V_22 -> V_195 ) ;
V_198 = ( V_22 -> V_195 == V_50 ) ;
if ( V_198 ) {
if ( F_124 ( & V_22 -> V_65 ) )
F_57 ( & V_22 -> V_53 ) ;
else
V_150 = 1 ;
break;
}
}
F_54 ( & V_73 -> V_87 ) ;
if ( ! V_198 )
return - V_199 ;
F_91 ( V_26 , V_22 , V_150 ) ;
return 0 ;
}
static void F_125 ( const struct V_25 * V_26 , struct V_35 * V_36 ,
struct V_56 * V_57 )
{
struct V_24 * V_27 ;
struct V_200 * V_201 ;
V_27 = F_12 ( V_26 ) ;
F_14 ( V_36 == & V_27 -> V_182 ) ;
V_201 = & V_27 -> V_202 ;
F_126 ( & V_201 -> V_203 , V_57 ) ;
}
static int F_127 ( struct V_10 * V_11 , int V_204 , T_3 V_205 ,
struct V_57 * * V_206 , int V_207 , int V_208 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_9 * V_55 = F_6 ( V_11 ) ;
struct V_1 * V_70 = V_11 -> V_86 ;
struct V_200 * V_201 ;
struct V_35 * V_36 ;
struct V_56 * V_209 ;
struct V_210 V_211 = { 0 } ;
T_6 V_212 = F_128 ( V_55 ) ;
int V_164 ;
int V_106 ;
int V_213 ;
F_14 ( ( V_205 & ~ V_214 ) == 0 ) ;
F_14 ( V_70 -> V_77 ) ;
V_26 = F_106 ( & V_164 ) ;
if ( F_107 ( V_26 ) )
return F_113 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_36 = & V_27 -> V_182 ;
V_201 = & V_27 -> V_202 ;
F_129 ( V_201 ) ;
V_36 -> V_215 = 1 ;
V_106 = F_130 ( V_26 , V_36 , V_216 , V_55 ) ;
if ( V_106 < 0 )
goto V_127;
F_14 ( V_106 == 0 ) ;
V_106 = F_116 ( V_26 , V_11 , V_205 ,
V_205 + V_207 * V_217 - 1 ,
V_204 == V_218 ? V_219 : V_189 , & V_211 . V_50 ,
V_220 ) ;
if ( V_106 < 0 )
goto V_221;
for ( V_213 = 0 ; V_213 < V_207 ; V_213 ++ ) {
F_14 ( V_206 [ V_213 ] ) ;
V_209 = F_131 ( V_26 , V_55 , F_117 ( V_55 , V_205 ) ,
V_206 [ V_213 ] , V_222 ) ;
if ( F_107 ( V_209 ) ) {
V_106 = F_113 ( V_209 ) ;
break;
}
F_14 ( V_209 -> V_223 == V_222 ) ;
V_106 = F_132 ( V_26 , V_36 , V_209 ) ;
if ( V_106 ) {
F_14 ( V_209 -> V_224 == V_225 ) ;
F_133 ( V_26 , V_209 ) ;
break;
}
F_126 ( & V_201 -> V_226 , V_209 ) ;
F_133 ( V_26 , V_209 ) ;
F_134 ( V_26 , V_209 , 0 , V_212 ) ;
V_205 += V_212 ;
}
if ( V_106 == 0 ) {
enum V_227 V_228 = V_204 == V_218 ? V_229 : V_230 ;
V_208 = V_208 && ( V_228 == V_230 ) ;
if ( V_208 )
V_106 = F_135 ( V_26 , V_36 , & V_201 -> V_226 ,
0 , V_217 ,
F_125 ) ;
else
V_106 = F_136 ( V_26 , V_36 , V_228 , V_201 , 0 ) ;
F_94 ( V_152 , L_13 ,
V_208 ? L_14 : L_15 , V_106 ) ;
}
F_121 ( V_26 , V_70 , V_211 . V_50 ) ;
V_221:
F_137 ( V_26 , V_36 , V_201 ) ;
F_138 ( V_26 , V_36 , V_201 ) ;
F_139 ( V_26 , V_201 ) ;
F_140 ( V_26 , V_36 ) ;
V_127:
F_111 ( V_26 , & V_164 ) ;
return V_106 ;
}
static int F_141 ( const struct V_25 * V_26 , struct V_1 * V_70 ,
struct V_231 * V_232 )
{
struct V_10 * V_11 ;
struct V_72 * V_73 = V_70 -> V_74 ;
int V_106 ;
int V_233 = 0 ;
if ( ! ( V_232 -> V_234 & V_235 ) ||
! ( V_232 -> V_234 & V_236 ) ||
! F_142 ( F_105 ( & V_232 -> V_237 ) ) ) {
F_69 ( L_16 V_165 L_11 , F_104 ( & V_232 -> V_237 ) ) ;
return - V_238 ;
}
if ( ! F_103 ( & V_232 -> V_237 ) )
F_143 ( & V_232 -> V_237 , ++ V_239 ) ;
V_106 = F_144 ( V_26 , V_73 -> V_240 , V_232 ) ;
if ( V_106 != 0 ) {
F_69 ( L_17 , V_106 ) ;
goto V_241;
}
V_233 = 1 ;
V_232 -> V_234 |= V_235 ;
V_11 = F_101 ( V_70 , & V_232 -> V_237 ) ;
if ( F_107 ( V_11 ) ) {
V_106 = F_113 ( V_11 ) ;
goto V_241;
}
F_112 ( V_11 ) ;
F_94 ( V_152 , L_18 V_165 L_11 , F_104 ( & V_232 -> V_237 ) ) ;
V_241:
if ( V_233 && V_106 )
F_145 ( V_26 , V_73 -> V_240 , V_232 ) ;
if ( V_106 )
F_69 ( L_19 , V_106 ) ;
return V_106 ;
}
static int F_146 ( struct V_10 * * V_242 , struct V_1 * V_70 ,
struct V_231 * V_232 )
{
struct V_10 * V_11 ;
int V_106 ;
if ( ! ( V_232 -> V_234 & V_235 ) || ! ( V_232 -> V_234 & V_236 ) ||
! F_103 ( & V_232 -> V_237 ) ) {
F_69 ( L_16 V_165 L_11 , F_104 ( & V_232 -> V_237 ) ) ;
return - V_238 ;
}
V_106 = 0 ;
V_11 = F_101 ( V_70 , & V_232 -> V_237 ) ;
if ( ! F_107 ( V_11 ) )
* V_242 = V_11 ;
else
V_106 = F_113 ( V_11 ) ;
return V_106 ;
}
static void F_147 ( struct V_10 * V_11 )
{
int V_106 ;
V_106 = F_112 ( V_11 ) ;
if ( V_106 )
F_69 ( L_20 ,
V_11 -> V_86 -> V_74 -> V_240 -> V_243 -> V_147 , V_106 ) ;
}
static void
F_148 ( struct V_57 * V_57 , int V_204 , T_3 V_244 ,
T_3 V_205 , T_3 V_245 )
{
char * V_246 ;
T_3 V_247 ;
T_3 V_248 ;
int V_249 ;
F_14 ( V_245 == V_217 ) ;
V_246 = F_149 ( V_57 ) ;
for ( V_249 = 0 ; V_249 < V_217 ; V_249 += V_250 ) {
if ( V_204 == V_251 ) {
V_247 = V_205 + V_249 ;
V_248 = V_244 ;
} else {
V_247 = 0xdeadbeef00c0ffeeULL ;
V_248 = 0xdeadbeef00c0ffeeULL ;
}
F_150 ( V_246 + V_249 , V_250 ,
V_247 , V_248 ) ;
}
F_151 ( V_57 ) ;
}
static int F_152 ( struct V_57 * V_57 , T_3 V_244 ,
T_3 V_205 , T_3 V_245 )
{
T_3 V_247 ;
T_3 V_248 ;
char * V_246 ;
int V_249 ;
int V_106 ;
int V_252 ;
F_14 ( V_245 == V_217 ) ;
V_246 = F_149 ( V_57 ) ;
for ( V_106 = V_249 = 0 ; V_249 < V_217 ; V_249 += V_250 ) {
V_247 = V_205 + V_249 ;
V_248 = V_244 ;
V_252 = F_153 ( L_21 ,
V_246 + V_249 , V_250 ,
V_247 , V_248 ) ;
if ( V_252 != 0 ) {
F_69 ( L_22 , V_244 ) ;
V_106 = V_252 ;
}
}
F_151 ( V_57 ) ;
return V_106 ;
}
static int F_154 ( struct V_1 * V_70 , int V_204 , struct V_231 * V_232 ,
struct V_10 * V_11 , T_3 V_205 ,
T_3 V_245 , int V_208 )
{
T_7 V_207 ;
struct V_253 * V_254 ;
struct V_253 * V_255 ;
struct V_57 * * V_206 ;
T_3 V_256 ;
int V_213 ;
int V_106 ;
int V_257 ;
T_8 V_258 ;
int V_259 = 0 ;
V_257 = ( F_103 ( & V_232 -> V_237 ) != V_260 &&
( V_232 -> V_234 & V_261 ) != 0 &&
( V_232 -> V_262 & V_263 ) != 0 ) ;
V_258 = ( ( F_103 ( & V_232 -> V_237 ) & 2 ) == 0 ) ? V_264 : V_265 ;
F_14 ( V_204 == V_251 || V_204 == V_266 ) ;
if ( V_245 <= 0 ||
( V_245 & ( ~ V_214 ) ) != 0 )
return - V_238 ;
V_207 = V_245 >> V_267 ;
if ( V_204 == V_251 )
V_259 = V_268 ;
V_254 = F_155 ( V_207 , sizeof( * V_254 ) , V_62 ) ;
if ( ! V_254 )
return - V_66 ;
V_206 = F_155 ( V_207 , sizeof( * V_206 ) , V_62 ) ;
if ( ! V_206 ) {
F_60 ( V_254 ) ;
return - V_66 ;
}
for ( V_213 = 0 , V_255 = V_254 , V_256 = V_205 ;
V_213 < V_207 ;
V_213 ++ , V_255 ++ , V_256 += V_217 ) {
F_14 ( ! V_255 -> V_269 ) ;
V_106 = - V_66 ;
V_255 -> V_269 = F_156 ( V_258 ) ;
if ( ! V_255 -> V_269 )
goto V_127;
V_206 [ V_213 ] = V_255 -> V_269 ;
V_255 -> V_245 = V_217 ;
V_255 -> V_256 = V_256 ;
V_255 -> V_270 = V_259 ;
if ( V_257 )
F_148 ( V_255 -> V_269 , V_204 ,
F_103 ( & V_232 -> V_237 ) , V_256 ,
V_255 -> V_245 ) ;
}
F_14 ( V_70 -> V_77 ) ;
V_106 = F_127 ( V_11 , V_204 , V_205 , V_206 , V_207 , V_208 ) ;
V_127:
if ( V_106 != 0 || V_204 != V_266 )
V_257 = 0 ;
for ( V_213 = 0 , V_255 = V_254 ; V_213 < V_207 ; V_213 ++ , V_255 ++ ) {
if ( ! V_255 -> V_269 )
continue;
if ( V_257 ) {
int V_271 ;
V_271 = F_152 ( V_255 -> V_269 ,
F_103 ( & V_232 -> V_237 ) ,
V_255 -> V_256 , V_255 -> V_245 ) ;
if ( V_271 != 0 && V_106 == 0 )
V_106 = V_271 ;
}
F_157 ( V_255 -> V_269 ) ;
}
F_60 ( V_254 ) ;
F_60 ( V_206 ) ;
return V_106 ;
}
static int F_158 ( const struct V_25 * V_26 ,
struct V_272 * exp , int V_204 ,
struct V_231 * V_232 , struct V_10 * V_11 ,
T_3 V_205 , T_3 V_245 ,
T_3 V_273 , int V_208 )
{
struct V_274 V_275 ;
struct V_276 * V_277 ;
struct V_278 V_279 ;
T_3 V_256 ;
T_3 V_207 , V_280 ;
int V_213 , V_281 = 0 , V_259 = 0 ;
if ( V_245 <= 0 || ( V_245 & ( ~ V_214 ) ) != 0 )
return - V_238 ;
V_207 = V_273 >> V_267 ;
V_280 = V_245 >> V_267 ;
V_277 = F_155 ( V_207 , sizeof( struct V_276 ) , V_62 ) ;
if ( ! V_277 ) {
V_281 = - V_66 ;
goto V_127;
}
if ( V_204 == V_251 && V_208 )
V_259 |= V_268 ;
F_159 ( V_232 , & V_275 ) ;
V_256 = V_205 ;
for (; V_280 > 0 ; V_280 -= V_207 ) {
int V_282 ;
if ( V_280 < V_207 )
V_207 = V_280 ;
V_279 . V_283 = V_256 ;
V_279 . V_284 = V_207 * V_217 ;
V_279 . V_285 = V_259 ;
V_275 . V_286 = 1 ;
V_256 += V_207 * V_217 ;
V_282 = V_207 ;
V_281 = F_160 ( V_26 , V_204 , exp , V_232 , 1 , & V_275 , & V_279 , & V_282 , V_277 ) ;
if ( V_281 != 0 )
goto V_127;
for ( V_213 = 0 ; V_213 < V_282 ; V_213 ++ ) {
struct V_57 * V_57 = V_277 [ V_213 ] . V_287 ;
if ( ! V_57 && V_277 [ V_213 ] . V_288 == 0 )
continue;
if ( V_208 )
V_277 [ V_213 ] . V_289 |= V_268 ;
if ( F_103 ( & V_232 -> V_237 ) == V_260 ||
( V_232 -> V_234 & V_261 ) == 0 ||
( V_232 -> V_262 & V_263 ) == 0 )
continue;
if ( V_204 == V_251 )
F_148 ( V_57 , V_204 ,
F_103 ( & V_232 -> V_237 ) ,
V_277 [ V_213 ] . V_290 ,
V_277 [ V_213 ] . V_291 ) ;
else
F_152 ( V_57 ,
F_103 ( & V_232 -> V_237 ) ,
V_277 [ V_213 ] . V_290 ,
V_277 [ V_213 ] . V_291 ) ;
}
V_281 = F_161 ( V_26 , V_204 , exp , V_232 , 1 , & V_275 , & V_279 , V_207 , V_277 ,
V_281 ) ;
if ( V_281 != 0 )
goto V_127;
F_162 ( (struct V_109 * ) & V_26 -> V_28 ) ;
F_163 ( (struct V_109 * ) & V_26 -> V_28 ) ;
}
V_127:
F_60 ( V_277 ) ;
return V_281 ;
}
static int F_164 ( const struct V_25 * V_26 , int V_204 ,
struct V_272 * exp ,
struct V_292 * V_114 )
{
struct V_6 * V_7 = F_165 ( exp ) ;
struct V_1 * V_70 = F_4 ( V_7 ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_231 * V_232 = & V_114 -> V_293 ;
struct V_10 * V_11 ;
int V_106 ;
int V_208 = 1 ;
long V_294 ;
F_14 ( V_232 -> V_234 & V_236 ) ;
V_106 = F_146 ( & V_11 , V_70 , V_232 ) ;
if ( V_106 )
return V_106 ;
V_232 -> V_234 &= ~ V_295 ;
V_294 = ( long ) V_114 -> V_296 ;
if ( V_294 == 1 )
V_208 = 0 ;
if ( ! V_70 -> V_77 && V_294 != 3 ) {
V_294 = 3 ;
V_114 -> V_297 = V_114 -> V_298 ;
}
if ( V_114 -> V_297 > V_299 )
V_114 -> V_297 = V_299 ;
switch ( V_294 ) {
case 1 :
case 2 :
V_106 = F_154 ( V_70 , V_204 , V_232 , V_11 , V_114 -> V_300 ,
V_114 -> V_298 , V_208 ) ;
break;
case 3 :
V_106 = F_158 ( V_26 , V_73 -> V_240 , V_204 , V_232 , V_11 ,
V_114 -> V_300 , V_114 -> V_298 ,
V_114 -> V_297 , V_208 ) ;
break;
default:
V_106 = - V_238 ;
}
F_147 ( V_11 ) ;
return V_106 ;
}
static int
F_166 ( unsigned int V_301 , struct V_272 * exp , int V_302 ,
void * V_303 , void T_9 * V_304 )
{
struct V_6 * V_7 = exp -> V_243 ;
struct V_1 * V_70 = F_4 ( V_7 ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_10 * V_11 ;
struct V_292 * V_114 = V_303 ;
struct V_25 * V_26 ;
struct V_231 * V_232 ;
struct V_162 V_163 ;
int V_204 = V_266 ;
int V_106 = 0 ;
V_232 = & V_114 -> V_293 ;
if ( ! ( V_232 -> V_234 & V_236 ) ) {
V_232 -> V_234 |= V_236 ;
F_167 ( & V_232 -> V_237 ) ;
}
V_106 = F_108 ( & V_163 , & V_232 -> V_237 , 0 ) ;
if ( V_106 < 0 )
return V_106 ;
V_26 = F_80 ( sizeof( * V_26 ) , V_62 ) ;
if ( ! V_26 )
return - V_66 ;
V_106 = F_168 ( V_26 , V_305 ) ;
if ( V_106 ) {
V_106 = - V_66 ;
goto V_127;
}
switch ( V_301 ) {
case V_306 :
if ( ! F_169 ( V_307 ) ) {
V_106 = - V_308 ;
goto V_127;
}
V_106 = F_141 ( V_26 , V_70 , V_232 ) ;
goto V_127;
case V_309 :
if ( ! F_169 ( V_307 ) ) {
V_106 = - V_308 ;
goto V_127;
}
V_106 = F_146 ( & V_11 , V_70 , V_232 ) ;
if ( V_106 == 0 ) {
V_106 = F_145 ( V_26 , V_73 -> V_240 , V_232 ) ;
if ( V_106 == 0 )
V_11 -> V_153 = 1 ;
F_147 ( V_11 ) ;
}
goto V_127;
case V_310 :
V_106 = F_146 ( & V_11 , V_70 , V_232 ) ;
if ( V_106 == 0 ) {
V_106 = F_170 ( V_26 , V_73 -> V_240 , V_232 ) ;
F_147 ( V_11 ) ;
}
goto V_127;
case V_311 :
if ( ! F_169 ( V_307 ) ) {
V_106 = - V_308 ;
goto V_127;
}
V_106 = F_146 ( & V_11 , V_70 , V_232 ) ;
if ( V_106 == 0 ) {
V_106 = F_171 ( V_26 , V_73 -> V_240 , V_232 ) ;
F_147 ( V_11 ) ;
}
goto V_127;
case V_312 :
if ( ! F_169 ( V_307 ) ) {
V_106 = - V_308 ;
goto V_127;
}
V_204 = V_251 ;
case V_313 :
V_106 = F_164 ( V_26 , V_204 , exp , V_114 ) ;
goto V_127;
default:
F_69 ( L_23 , V_301 ) ;
V_106 = - V_314 ;
goto V_127;
}
V_127:
F_172 ( V_26 ) ;
F_60 ( V_26 ) ;
return V_106 ;
}
static int F_84 ( const struct V_25 * V_26 ,
struct V_6 * V_315 , struct V_120 * V_316 )
{
struct V_72 * V_73 = & V_315 -> V_138 . V_139 ;
struct V_6 * V_124 ;
struct V_317 V_318 = { L_24 } ;
struct V_319 * V_320 = NULL ;
int V_106 ;
if ( V_316 -> V_321 < 2 || F_173 ( V_316 , 1 ) < 1 ) {
F_69 ( L_25 ) ;
return - V_238 ;
}
V_124 = F_82 ( F_83 ( V_316 , 1 ) ) ;
if ( ! V_124 || ! V_124 -> V_322 || ! V_124 -> V_323 ) {
F_69 ( L_26 ,
F_83 ( V_316 , 1 ) ) ;
return - V_238 ;
}
F_174 ( & V_73 -> V_87 ) ;
F_44 ( & V_73 -> V_89 ) ;
F_44 ( & V_73 -> V_155 ) ;
V_73 -> V_196 = 0 ;
V_320 = F_80 ( sizeof( * V_320 ) , V_62 ) ;
if ( ! V_320 )
return - V_66 ;
V_320 -> V_324 = V_325 | V_326 |
V_327 |
V_328 | V_329 |
V_330 | V_331 |
V_332 ;
V_320 -> V_333 = V_334 ;
V_320 -> V_335 = V_336 ;
V_320 -> V_337 = V_166 ;
V_106 = F_175 ( V_26 , & V_73 -> V_240 , V_124 , & V_318 , V_320 , NULL ) ;
F_60 ( V_320 ) ;
if ( V_106 != 0 ) {
F_69 ( L_27 ,
F_83 ( V_316 , 1 ) ) ;
return V_106 ;
}
return V_106 ;
}
static int F_86 ( struct V_6 * V_315 )
{
struct V_72 * V_73 = & V_315 -> V_138 . V_139 ;
int V_106 ;
if ( ! F_32 ( & V_315 -> V_338 ) ) {
F_69 ( L_28 ) ;
return - V_43 ;
}
F_14 ( F_56 ( & V_73 -> V_240 -> V_339 ) > 0 ) ;
V_106 = F_176 ( V_73 -> V_240 ) ;
if ( V_106 != 0 )
F_69 ( L_29 , V_106 ) ;
return V_106 ;
}
static int F_177 ( const struct V_25 * V_26 ,
struct V_272 * * exp ,
struct V_6 * V_340 , struct V_317 * V_341 ,
struct V_319 * V_114 , void * V_342 )
{
int V_106 ;
struct V_210 V_343 = { 0 } ;
V_106 = F_178 ( & V_343 , V_340 , V_341 ) ;
if ( V_106 == 0 ) {
* exp = F_179 ( & V_343 ) ;
}
return V_106 ;
}
static int F_180 ( struct V_272 * exp )
{
int V_106 ;
if ( ! exp ) {
V_106 = - V_238 ;
goto V_127;
}
V_106 = F_181 ( exp ) ;
goto V_127;
V_127:
return V_106 ;
}
static int F_182 ( void )
{
int V_106 ;
V_106 = F_183 ( V_344 ) ;
if ( V_106 == 0 ) {
V_106 = F_184 ( & V_345 , NULL ,
V_52 ,
& V_194 ) ;
if ( V_106 )
F_185 ( V_344 ) ;
}
return V_106 ;
}
static void F_186 ( void )
{
F_187 ( V_52 ) ;
F_185 ( V_344 ) ;
}
static int T_10 F_188 ( void )
{
F_189 ( L_30 ) ;
F_14 ( V_217 % V_250 == 0 ) ;
return F_182 () ;
}
static void F_190 ( void )
{
F_186 () ;
}
