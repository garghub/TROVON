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
if ( V_106 )
return V_106 ;
V_70 -> V_108 = V_104 ;
return 0 ;
}
static void F_71 ( const struct V_25 * V_26 , struct V_1 * V_70 )
{
if ( V_70 -> V_108 ) {
F_72 ( V_70 -> V_108 ) ;
V_70 -> V_108 = NULL ;
}
}
static void * F_73 ( const struct V_109 * V_110 ,
struct V_111 * V_112 )
{
struct V_24 * V_27 ;
V_27 = F_42 ( V_113 , V_62 ) ;
if ( ! V_27 )
V_27 = F_74 ( - V_66 ) ;
return V_27 ;
}
static void F_75 ( const struct V_109 * V_110 ,
struct V_111 * V_112 , void * V_114 )
{
struct V_24 * V_27 = V_114 ;
F_33 ( V_113 , V_27 ) ;
}
static void F_76 ( const struct V_109 * V_110 ,
struct V_111 * V_112 , void * V_114 )
{
}
static void * F_77 ( const struct V_109 * V_110 ,
struct V_111 * V_112 )
{
struct V_115 * V_116 ;
V_116 = F_42 ( V_117 , V_62 ) ;
if ( ! V_116 )
V_116 = F_74 ( - V_66 ) ;
return V_116 ;
}
static void F_78 ( const struct V_109 * V_110 ,
struct V_111 * V_112 , void * V_114 )
{
struct V_115 * V_116 = V_114 ;
F_33 ( V_117 , V_116 ) ;
}
static void F_79 ( const struct V_109 * V_110 ,
struct V_111 * V_112 , void * V_114 )
{
}
static struct V_79 * F_80 ( const struct V_25 * V_26 ,
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
V_70 = F_81 ( sizeof( * V_70 ) , V_62 ) ;
if ( ! V_70 ) {
V_106 = - V_66 ;
goto V_127;
}
V_123 = & V_70 -> V_4 ;
V_106 = F_82 ( V_123 , V_119 ) ;
if ( V_106 )
goto V_128;
V_123 -> V_129 . V_81 = & V_130 ;
V_123 -> V_131 = & V_132 ;
V_7 = F_83 ( F_84 ( V_121 , 0 ) ) ;
F_14 ( V_7 ) ;
F_14 ( V_26 ) ;
V_124 = F_83 ( F_84 ( V_121 , 1 ) ) ;
if ( ! V_124 ) {
F_69 ( L_4 ,
F_84 ( V_121 , 1 ) ) ;
V_106 = - V_133 ;
goto V_134;
}
V_122 = V_124 -> V_8 ;
if ( ! strcmp ( V_124 -> V_135 -> V_136 , V_137 ) ) {
F_69 ( L_5 ) ;
V_106 = - V_138 ;
goto V_134;
}
V_106 = F_67 ( V_26 , V_70 ) ;
if ( V_106 )
goto V_134;
V_106 = F_85 ( V_26 , V_7 , V_121 ) ;
if ( V_106 )
goto V_139;
V_70 -> V_74 = & V_7 -> V_140 . V_141 ;
if ( V_122 && ! F_86 ( V_122 ) )
V_122 = NULL ;
V_125 = V_124 -> V_135 -> V_136 ;
if ( V_122 ) {
if ( V_122 -> V_142 ) {
V_106 = - V_43 ;
goto V_143;
}
V_122 -> V_142 = & V_70 -> V_108 -> V_107 ;
V_106 = V_122 -> V_144 -> V_145 -> V_146 ( V_26 , V_122 ,
V_122 -> V_144 -> V_147 ,
NULL ) ;
if ( V_106 )
goto V_143;
} else {
F_14 ( strcmp ( V_125 , V_148 ) == 0 ) ;
}
V_70 -> V_77 = V_122 ;
return & V_123 -> V_129 ;
V_143:
V_126 = F_87 ( V_7 ) ;
if ( V_126 )
F_69 ( L_6 ,
V_7 -> V_149 , V_126 ) ;
V_139:
F_71 ( V_26 , V_70 ) ;
V_134:
F_88 ( & V_70 -> V_4 ) ;
V_128:
F_60 ( V_70 ) ;
V_127:
return F_74 ( V_106 ) ;
}
static int F_89 ( const struct V_25 * V_26 , struct V_79 * V_5 ,
const char * V_150 , struct V_79 * V_122 )
{
F_90 () ;
return 0 ;
}
static struct V_79 * F_91 ( const struct V_25 * V_26 ,
struct V_79 * V_5 )
{
struct V_1 * V_70 = F_1 ( F_5 ( V_5 ) ) ;
struct V_79 * V_122 = V_70 -> V_77 ;
while ( V_122 )
V_122 = V_122 -> V_144 -> V_145 -> V_151 ( V_26 , V_122 ) ;
return NULL ;
}
static void F_92 ( const struct V_25 * V_26 ,
struct V_18 * V_22 ,
int V_152 )
{
struct V_21 * V_153 = F_11 ( V_22 ) ;
F_93 ( V_26 , V_153 ) ;
}
static struct V_79 * F_94 ( const struct V_25 * V_26 ,
struct V_79 * V_5 )
{
struct V_1 * V_70 = F_1 ( F_5 ( V_5 ) ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_10 * V_11 ;
struct V_79 * V_122 = V_70 -> V_77 ;
F_95 ( V_154 , L_7 ,
V_70 , V_122 ) ;
F_96 ( V_26 , & V_70 -> V_108 -> V_107 , - 1 ) ;
F_52 ( & V_73 -> V_87 ) ;
F_97 (eco, &ec->ec_objects, eo_obj_chain)
V_11 -> V_155 = 1 ;
F_54 ( & V_73 -> V_87 ) ;
F_96 ( V_26 , & V_70 -> V_108 -> V_107 , - 1 ) ;
F_95 ( V_154 ,
L_8 ) ;
F_52 ( & V_73 -> V_87 ) ;
while ( ! F_32 ( & V_73 -> V_89 ) ) {
F_54 ( & V_73 -> V_87 ) ;
F_69 ( L_9 ) ;
F_98 ( V_156 ) ;
F_99 ( F_100 ( 1 ) ) ;
F_96 ( V_26 , & V_70 -> V_108 -> V_107 , - 1 ) ;
F_52 ( & V_73 -> V_87 ) ;
}
F_54 ( & V_73 -> V_87 ) ;
F_14 ( F_32 ( & V_73 -> V_157 ) ) ;
F_95 ( V_154 , L_10 ) ;
F_87 ( V_5 -> V_158 ) ;
while ( V_122 )
V_122 = V_122 -> V_144 -> V_145 -> V_159 ( V_26 , V_122 ) ;
F_14 ( V_70 -> V_108 == F_101 ( V_5 -> V_142 ) ) ;
F_71 ( V_26 , V_70 ) ;
F_88 ( & V_70 -> V_4 ) ;
F_60 ( V_70 ) ;
return NULL ;
}
static struct V_10 *
F_102 ( struct V_1 * V_5 , const struct V_160 * V_161 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_30 * V_67 ;
struct V_162 * V_163 = NULL ;
struct V_10 * V_11 ;
struct V_9 * V_55 ;
struct V_164 * V_165 ;
int V_166 ;
int V_106 ;
F_103 ( F_104 ( V_161 ) , V_167 L_11 , F_105 ( V_161 ) ) ;
F_103 ( F_106 ( V_161 ) == V_168 , V_167 L_11 , F_105 ( V_161 ) ) ;
if ( F_3 ( V_5 ) -> V_129 . V_158 -> V_169 )
return F_74 ( - V_133 ) ;
V_26 = F_107 ( & V_166 ) ;
if ( F_108 ( V_26 ) )
return ( void * ) V_26 ;
V_27 = F_12 ( V_26 ) ;
V_67 = & V_27 -> V_170 ;
if ( V_5 -> V_77 ) {
V_163 = F_81 ( sizeof( * V_163 ) , V_62 ) ;
if ( ! V_163 ) {
V_11 = F_74 ( - V_66 ) ;
goto V_127;
}
V_163 -> V_171 = * V_161 ;
V_67 -> V_33 . V_140 . V_172 = V_163 ;
}
V_67 -> V_84 = & V_163 ;
V_165 = & V_27 -> V_173 ;
V_106 = F_109 ( V_165 , (struct V_160 * ) V_161 , 0 ) ;
if ( V_106 != 0 ) {
V_11 = F_74 ( V_106 ) ;
goto V_127;
}
V_55 = F_110 ( V_26 , F_3 ( V_5 ) , V_165 , & V_67 -> V_33 ) ;
if ( F_108 ( V_55 ) ) {
V_11 = ( void * ) V_55 ;
goto V_127;
}
V_11 = F_7 ( V_55 ) ;
if ( V_11 -> V_155 ) {
F_111 ( V_26 , V_55 ) ;
V_11 = F_74 ( - V_40 ) ;
}
V_127:
F_60 ( V_163 ) ;
F_112 ( V_26 , & V_166 ) ;
return V_11 ;
}
static int F_113 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
struct V_9 * V_55 = F_6 ( V_11 ) ;
int V_166 ;
V_26 = F_107 ( & V_166 ) ;
if ( F_108 ( V_26 ) )
return F_114 ( V_26 ) ;
if ( V_11 -> V_155 ) {
struct V_92 * V_174 = V_55 -> V_96 . V_83 ;
F_14 ( & V_11 -> V_95 == F_115 ( V_174 ) ) ;
F_116 ( V_175 , & V_174 -> V_176 ) ;
}
F_111 ( V_26 , V_55 ) ;
F_112 ( V_26 , & V_166 ) ;
return 0 ;
}
static int F_117 ( struct V_25 * V_26 , struct V_10 * V_11 ,
T_3 V_177 , T_3 V_178 , int V_179 ,
T_4 * V_50 , T_5 V_180 )
{
struct V_35 * V_36 ;
struct V_21 * V_181 ;
struct V_9 * V_55 ;
struct V_182 * V_183 ;
struct V_24 * V_27 ;
int V_106 = - V_66 ;
V_27 = F_12 ( V_26 ) ;
V_36 = & V_27 -> V_184 ;
V_181 = & V_27 -> V_185 ;
V_55 = F_6 ( V_11 ) ;
memset ( V_181 , 0 , sizeof( * V_181 ) ) ;
V_183 = & V_181 -> V_186 ;
V_183 -> V_187 = V_55 ;
V_183 -> V_188 = F_118 ( V_55 , V_177 ) ;
V_183 -> V_189 = F_118 ( V_55 , V_178 ) ;
V_183 -> V_190 = V_179 == V_191 ? V_192 : V_193 ;
V_183 -> V_194 = V_180 ;
V_36 -> V_195 = V_55 ;
V_106 = F_119 ( V_26 , V_36 , V_181 ) ;
if ( V_106 == 0 ) {
struct V_72 * V_73 = V_11 -> V_86 -> V_74 ;
struct V_18 * V_61 ;
V_61 = F_10 ( F_120 ( V_181 , & V_196 ) ) ;
F_52 ( & V_73 -> V_87 ) ;
if ( F_32 ( & V_61 -> V_53 ) ) {
F_121 ( & V_61 -> V_53 , & V_73 -> V_157 ) ;
V_61 -> V_197 = ++ V_73 -> V_198 ;
}
F_39 ( & V_61 -> V_65 ) ;
* V_50 = V_61 -> V_197 ;
F_54 ( & V_73 -> V_87 ) ;
}
return V_106 ;
}
static int F_122 ( struct V_25 * V_26 , struct V_1 * V_70 ,
T_4 V_50 )
{
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_18 * V_22 = NULL ;
struct V_199 * V_61 ;
int V_200 = 0 , V_152 = 0 ;
F_52 ( & V_73 -> V_87 ) ;
F_123 (el, &ec->ec_locks) {
V_22 = F_124 ( V_61 , struct V_18 , V_53 ) ;
F_95 ( V_154 , L_12 , V_22 , V_22 -> V_197 ) ;
V_200 = ( V_22 -> V_197 == V_50 ) ;
if ( V_200 ) {
if ( F_125 ( & V_22 -> V_65 ) )
F_57 ( & V_22 -> V_53 ) ;
else
V_152 = 1 ;
break;
}
}
F_54 ( & V_73 -> V_87 ) ;
if ( ! V_200 )
return - V_201 ;
F_92 ( V_26 , V_22 , V_152 ) ;
return 0 ;
}
static void F_126 ( const struct V_25 * V_26 , struct V_35 * V_36 ,
struct V_56 * V_57 )
{
struct V_24 * V_27 ;
struct V_202 * V_203 ;
V_27 = F_12 ( V_26 ) ;
F_14 ( V_36 == & V_27 -> V_184 ) ;
V_203 = & V_27 -> V_204 ;
F_127 ( & V_203 -> V_205 , V_57 ) ;
}
static int F_128 ( struct V_10 * V_11 , int V_206 , T_3 V_207 ,
struct V_57 * * V_208 , int V_209 , int V_210 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_9 * V_55 = F_6 ( V_11 ) ;
struct V_1 * V_70 = V_11 -> V_86 ;
struct V_202 * V_203 ;
struct V_35 * V_36 ;
struct V_56 * V_211 ;
struct V_212 V_213 = { 0 } ;
T_6 V_214 = F_129 ( V_55 ) ;
int V_166 ;
int V_106 ;
int V_215 ;
F_14 ( ( V_207 & ~ V_216 ) == 0 ) ;
F_14 ( V_70 -> V_77 ) ;
V_26 = F_107 ( & V_166 ) ;
if ( F_108 ( V_26 ) )
return F_114 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_36 = & V_27 -> V_184 ;
V_203 = & V_27 -> V_204 ;
F_130 ( V_203 ) ;
V_36 -> V_217 = 1 ;
V_106 = F_131 ( V_26 , V_36 , V_218 , V_55 ) ;
if ( V_106 < 0 )
goto V_127;
F_14 ( V_106 == 0 ) ;
V_106 = F_117 ( V_26 , V_11 , V_207 ,
V_207 + V_209 * V_219 - 1 ,
V_206 == V_220 ? V_221 : V_191 , & V_213 . V_50 ,
V_222 ) ;
if ( V_106 < 0 )
goto V_223;
for ( V_215 = 0 ; V_215 < V_209 ; V_215 ++ ) {
F_14 ( V_208 [ V_215 ] ) ;
V_211 = F_132 ( V_26 , V_55 , F_118 ( V_55 , V_207 ) ,
V_208 [ V_215 ] , V_224 ) ;
if ( F_108 ( V_211 ) ) {
V_106 = F_114 ( V_211 ) ;
break;
}
F_14 ( V_211 -> V_225 == V_224 ) ;
V_106 = F_133 ( V_26 , V_36 , V_211 ) ;
if ( V_106 ) {
F_14 ( V_211 -> V_226 == V_227 ) ;
F_134 ( V_26 , V_211 ) ;
break;
}
F_127 ( & V_203 -> V_228 , V_211 ) ;
F_134 ( V_26 , V_211 ) ;
F_135 ( V_26 , V_211 , 0 , V_214 ) ;
V_207 += V_214 ;
}
if ( V_106 == 0 ) {
enum V_229 V_230 = V_206 == V_220 ? V_231 : V_232 ;
V_210 = V_210 && ( V_230 == V_232 ) ;
if ( V_210 )
V_106 = F_136 ( V_26 , V_36 , & V_203 -> V_228 ,
0 , V_219 ,
F_126 ) ;
else
V_106 = F_137 ( V_26 , V_36 , V_230 , V_203 , 0 ) ;
F_95 ( V_154 , L_13 ,
V_210 ? L_14 : L_15 , V_106 ) ;
}
F_122 ( V_26 , V_70 , V_213 . V_50 ) ;
V_223:
F_138 ( V_26 , V_36 , V_203 ) ;
F_139 ( V_26 , V_36 , V_203 ) ;
F_140 ( V_26 , V_203 ) ;
F_141 ( V_26 , V_36 ) ;
V_127:
F_112 ( V_26 , & V_166 ) ;
return V_106 ;
}
static int F_142 ( const struct V_25 * V_26 , struct V_1 * V_70 ,
struct V_233 * V_234 , struct V_235 * V_236 )
{
struct V_10 * V_11 ;
struct V_72 * V_73 = V_70 -> V_74 ;
int V_106 ;
int V_237 = 0 ;
if ( ! ( V_234 -> V_238 & V_239 ) ||
! ( V_234 -> V_238 & V_240 ) ||
! F_143 ( F_106 ( & V_234 -> V_241 ) ) ) {
F_69 ( L_16 V_167 L_11 , F_105 ( & V_234 -> V_241 ) ) ;
return - V_242 ;
}
if ( ! F_104 ( & V_234 -> V_241 ) )
F_144 ( & V_234 -> V_241 , ++ V_243 ) ;
V_106 = F_145 ( V_26 , V_73 -> V_244 , V_234 , V_236 ) ;
if ( V_106 != 0 ) {
F_69 ( L_17 , V_106 ) ;
goto V_245;
}
V_237 = 1 ;
V_234 -> V_238 |= V_239 ;
V_11 = F_102 ( V_70 , & V_234 -> V_241 ) ;
if ( F_108 ( V_11 ) ) {
V_106 = F_114 ( V_11 ) ;
goto V_245;
}
F_113 ( V_11 ) ;
F_95 ( V_154 , L_18 V_167 L_11 , F_105 ( & V_234 -> V_241 ) ) ;
V_245:
if ( V_237 && V_106 )
F_146 ( V_26 , V_73 -> V_244 , V_234 , V_236 ) ;
if ( V_106 )
F_69 ( L_19 , V_106 ) ;
return V_106 ;
}
static int F_147 ( struct V_10 * * V_246 , struct V_1 * V_70 ,
struct V_233 * V_234 )
{
struct V_10 * V_11 ;
int V_106 ;
if ( ! ( V_234 -> V_238 & V_239 ) || ! ( V_234 -> V_238 & V_240 ) ||
! F_104 ( & V_234 -> V_241 ) ) {
F_69 ( L_16 V_167 L_11 , F_105 ( & V_234 -> V_241 ) ) ;
return - V_242 ;
}
V_106 = 0 ;
V_11 = F_102 ( V_70 , & V_234 -> V_241 ) ;
if ( ! F_108 ( V_11 ) )
* V_246 = V_11 ;
else
V_106 = F_114 ( V_11 ) ;
return V_106 ;
}
static void F_148 ( struct V_10 * V_11 )
{
int V_106 ;
V_106 = F_113 ( V_11 ) ;
if ( V_106 )
F_69 ( L_20 ,
V_11 -> V_86 -> V_74 -> V_244 -> V_247 -> V_149 , V_106 ) ;
}
static void
F_149 ( struct V_57 * V_57 , int V_206 , T_3 V_248 ,
T_3 V_207 , T_3 V_249 )
{
char * V_250 ;
T_3 V_251 ;
T_3 V_252 ;
int V_253 ;
F_14 ( V_249 == V_219 ) ;
V_250 = F_150 ( V_57 ) ;
for ( V_253 = 0 ; V_253 < V_219 ; V_253 += V_254 ) {
if ( V_206 == V_255 ) {
V_251 = V_207 + V_253 ;
V_252 = V_248 ;
} else {
V_251 = 0xdeadbeef00c0ffeeULL ;
V_252 = 0xdeadbeef00c0ffeeULL ;
}
F_151 ( V_250 + V_253 , V_254 ,
V_251 , V_252 ) ;
}
F_152 ( V_57 ) ;
}
static int F_153 ( struct V_57 * V_57 , T_3 V_248 ,
T_3 V_207 , T_3 V_249 )
{
T_3 V_251 ;
T_3 V_252 ;
char * V_250 ;
int V_253 ;
int V_106 ;
int V_256 ;
F_14 ( V_249 == V_219 ) ;
V_250 = F_150 ( V_57 ) ;
for ( V_106 = V_253 = 0 ; V_253 < V_219 ; V_253 += V_254 ) {
V_251 = V_207 + V_253 ;
V_252 = V_248 ;
V_256 = F_154 ( L_21 ,
V_250 + V_253 , V_254 ,
V_251 , V_252 ) ;
if ( V_256 != 0 ) {
F_69 ( L_22 , V_248 ) ;
V_106 = V_256 ;
}
}
F_152 ( V_57 ) ;
return V_106 ;
}
static int F_155 ( struct V_1 * V_70 , int V_206 , struct V_233 * V_234 ,
struct V_10 * V_11 , T_3 V_207 ,
T_3 V_249 , int V_210 ,
struct V_235 * V_236 )
{
T_7 V_209 ;
struct V_257 * V_258 ;
struct V_257 * V_259 ;
struct V_57 * * V_208 ;
T_3 V_260 ;
int V_215 ;
int V_106 ;
int V_261 ;
T_8 V_262 ;
int V_263 = 0 ;
V_261 = ( F_104 ( & V_234 -> V_241 ) != V_264 &&
( V_234 -> V_238 & V_265 ) != 0 &&
( V_234 -> V_266 & V_267 ) != 0 ) ;
V_262 = ( ( F_104 ( & V_234 -> V_241 ) & 2 ) == 0 ) ? V_268 : V_269 ;
F_14 ( V_206 == V_255 || V_206 == V_270 ) ;
if ( V_249 <= 0 ||
( V_249 & ( ~ V_216 ) ) != 0 )
return - V_242 ;
V_209 = V_249 >> V_271 ;
if ( V_206 == V_255 )
V_263 = V_272 ;
V_258 = F_156 ( V_209 , sizeof( * V_258 ) , V_62 ) ;
if ( ! V_258 )
return - V_66 ;
V_208 = F_156 ( V_209 , sizeof( * V_208 ) , V_62 ) ;
if ( ! V_208 ) {
F_60 ( V_258 ) ;
return - V_66 ;
}
for ( V_215 = 0 , V_259 = V_258 , V_260 = V_207 ;
V_215 < V_209 ;
V_215 ++ , V_259 ++ , V_260 += V_219 ) {
F_14 ( ! V_259 -> V_273 ) ;
V_106 = - V_66 ;
V_259 -> V_273 = F_157 ( V_262 ) ;
if ( ! V_259 -> V_273 )
goto V_127;
V_208 [ V_215 ] = V_259 -> V_273 ;
V_259 -> V_249 = V_219 ;
V_259 -> V_260 = V_260 ;
V_259 -> V_274 = V_263 ;
if ( V_261 )
F_149 ( V_259 -> V_273 , V_206 ,
F_104 ( & V_234 -> V_241 ) , V_260 ,
V_259 -> V_249 ) ;
}
F_14 ( V_70 -> V_77 ) ;
V_106 = F_128 ( V_11 , V_206 , V_207 , V_208 , V_209 , V_210 ) ;
V_127:
if ( V_106 != 0 || V_206 != V_270 )
V_261 = 0 ;
for ( V_215 = 0 , V_259 = V_258 ; V_215 < V_209 ; V_215 ++ , V_259 ++ ) {
if ( ! V_259 -> V_273 )
continue;
if ( V_261 ) {
int V_275 ;
V_275 = F_153 ( V_259 -> V_273 ,
F_104 ( & V_234 -> V_241 ) ,
V_259 -> V_260 , V_259 -> V_249 ) ;
if ( V_275 != 0 && V_106 == 0 )
V_106 = V_275 ;
}
F_158 ( V_259 -> V_273 ) ;
}
F_60 ( V_258 ) ;
F_60 ( V_208 ) ;
return V_106 ;
}
static int F_159 ( const struct V_25 * V_26 ,
struct V_276 * exp , int V_206 ,
struct V_233 * V_234 , struct V_10 * V_11 ,
T_3 V_207 , T_3 V_249 ,
T_3 V_277 , struct V_235 * V_236 ,
int V_210 )
{
struct V_278 V_279 ;
struct V_280 * V_281 ;
struct V_282 * V_283 ;
T_3 V_260 ;
T_3 V_209 , V_284 ;
int V_215 , V_285 = 0 , V_263 = 0 ;
if ( V_249 <= 0 || ( V_249 & ( ~ V_216 ) ) != 0 )
return - V_242 ;
V_209 = V_277 >> V_271 ;
V_284 = V_249 >> V_271 ;
V_281 = F_156 ( V_209 , sizeof( struct V_280 ) , V_62 ) ;
V_283 = F_156 ( V_209 , sizeof( struct V_282 ) , V_62 ) ;
if ( ! V_281 || ! V_283 ) {
V_285 = - V_66 ;
goto V_127;
}
if ( V_206 == V_255 && V_210 )
V_263 |= V_272 ;
F_160 ( V_234 , & V_279 ) ;
V_260 = V_207 ;
for (; V_284 ; V_284 -= V_209 ) {
int V_286 ;
if ( V_284 < V_209 )
V_209 = V_284 ;
for ( V_215 = 0 ; V_215 < V_209 ; V_215 ++ , V_260 += V_219 ) {
V_283 [ V_215 ] . V_287 = V_260 ;
V_283 [ V_215 ] . V_288 = V_219 ;
V_283 [ V_215 ] . V_289 = V_263 ;
}
V_279 . V_290 = V_209 ;
V_286 = V_209 ;
V_285 = F_161 ( V_26 , V_206 , exp , V_234 , 1 , & V_279 , V_283 , & V_286 ,
V_281 , V_236 ) ;
if ( V_285 != 0 )
goto V_127;
F_14 ( V_286 == V_209 ) ;
for ( V_215 = 0 ; V_215 < V_286 ; V_215 ++ ) {
struct V_57 * V_57 = V_281 [ V_215 ] . V_291 ;
if ( ! V_57 && V_281 [ V_215 ] . V_292 == 0 )
continue;
if ( V_210 )
V_281 [ V_215 ] . V_293 |= V_272 ;
if ( F_104 ( & V_234 -> V_241 ) == V_264 ||
( V_234 -> V_238 & V_265 ) == 0 ||
( V_234 -> V_266 & V_267 ) == 0 )
continue;
if ( V_206 == V_255 )
F_149 ( V_57 , V_206 ,
F_104 ( & V_234 -> V_241 ) ,
V_283 [ V_215 ] . V_287 ,
V_283 [ V_215 ] . V_288 ) ;
else
F_153 ( V_57 ,
F_104 ( & V_234 -> V_241 ) ,
V_283 [ V_215 ] . V_287 ,
V_283 [ V_215 ] . V_288 ) ;
}
V_285 = F_162 ( V_26 , V_206 , exp , V_234 , 1 , & V_279 ,
V_283 , V_209 , V_281 , V_236 , V_285 ) ;
if ( V_285 != 0 )
goto V_127;
memset ( V_236 , 0 , sizeof( * V_236 ) ) ;
F_163 ( (struct V_109 * ) & V_26 -> V_28 ) ;
F_164 ( (struct V_109 * ) & V_26 -> V_28 ) ;
}
V_127:
F_60 ( V_281 ) ;
F_60 ( V_283 ) ;
return V_285 ;
}
static int F_165 ( const struct V_25 * V_26 , int V_206 ,
struct V_276 * exp ,
struct V_294 * V_114 ,
struct V_235 * V_295 )
{
struct V_6 * V_7 = F_166 ( exp ) ;
struct V_1 * V_70 = F_4 ( V_7 ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_233 * V_234 = & V_114 -> V_296 ;
struct V_10 * V_11 ;
int V_106 ;
int V_210 = 1 ;
long V_297 ;
F_14 ( V_234 -> V_238 & V_240 ) ;
V_106 = F_147 ( & V_11 , V_70 , V_234 ) ;
if ( V_106 )
return V_106 ;
V_234 -> V_238 &= ~ V_298 ;
V_297 = ( long ) V_114 -> V_299 ;
if ( V_297 == 1 )
V_210 = 0 ;
if ( ! V_70 -> V_77 && V_297 != 3 ) {
V_297 = 3 ;
V_114 -> V_300 = V_114 -> V_301 ;
}
if ( V_114 -> V_300 > V_302 )
V_114 -> V_300 = V_302 ;
switch ( V_297 ) {
case 1 :
case 2 :
V_106 = F_155 ( V_70 , V_206 , V_234 ,
V_11 , V_114 -> V_303 ,
V_114 -> V_301 , V_210 , V_295 ) ;
break;
case 3 :
V_106 = F_159 ( V_26 , V_73 -> V_244 , V_206 , V_234 ,
V_11 , V_114 -> V_303 ,
V_114 -> V_301 , V_114 -> V_300 ,
V_295 , V_210 ) ;
break;
default:
V_106 = - V_242 ;
}
F_148 ( V_11 ) ;
return V_106 ;
}
static int
F_167 ( unsigned int V_304 , struct V_276 * exp , int V_305 ,
void * V_306 , void T_9 * V_307 )
{
struct V_6 * V_7 = exp -> V_247 ;
struct V_1 * V_70 = F_4 ( V_7 ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_10 * V_11 ;
struct V_294 * V_114 = V_306 ;
struct V_235 V_295 ;
struct V_25 * V_26 ;
struct V_308 * V_309 ;
struct V_233 * V_234 ;
struct V_164 V_165 ;
int V_206 = V_270 ;
int V_106 = 0 ;
int V_215 ;
memset ( & V_295 , 0 , sizeof( V_295 ) ) ;
V_234 = & V_114 -> V_296 ;
if ( ! ( V_234 -> V_238 & V_240 ) ) {
V_234 -> V_238 |= V_240 ;
F_168 ( & V_234 -> V_241 ) ;
}
V_106 = F_109 ( & V_165 , & V_234 -> V_241 , 0 ) ;
if ( V_106 < 0 )
return V_106 ;
V_26 = F_81 ( sizeof( * V_26 ) , V_62 ) ;
if ( ! V_26 )
return - V_66 ;
V_106 = F_169 ( V_26 , V_310 ) ;
if ( V_106 ) {
V_106 = - V_66 ;
goto V_127;
}
switch ( V_304 ) {
case V_311 :
if ( ! F_170 ( V_312 ) ) {
V_106 = - V_313 ;
goto V_127;
}
V_106 = F_142 ( V_26 , V_70 , V_234 , & V_295 ) ;
goto V_127;
case V_314 :
if ( ! F_170 ( V_312 ) ) {
V_106 = - V_313 ;
goto V_127;
}
V_106 = F_147 ( & V_11 , V_70 , V_234 ) ;
if ( V_106 == 0 ) {
V_106 = F_146 ( V_26 , V_73 -> V_244 , V_234 , & V_295 ) ;
if ( V_106 == 0 )
V_11 -> V_155 = 1 ;
F_148 ( V_11 ) ;
}
goto V_127;
case V_315 :
V_106 = F_147 ( & V_11 , V_70 , V_234 ) ;
if ( V_106 == 0 ) {
struct V_316 V_163 = {
. V_317 = V_234 ,
} ;
V_106 = F_171 ( V_26 , V_73 -> V_244 , & V_163 ) ;
F_148 ( V_11 ) ;
}
goto V_127;
case V_318 :
if ( ! F_170 ( V_312 ) ) {
V_106 = - V_313 ;
goto V_127;
}
V_106 = F_147 ( & V_11 , V_70 , V_234 ) ;
if ( V_106 == 0 ) {
struct V_316 V_163 = {
. V_317 = V_234 ,
} ;
V_106 = F_172 ( V_26 , V_73 -> V_244 , & V_163 , NULL ) ;
F_148 ( V_11 ) ;
}
goto V_127;
case V_319 :
if ( ! F_170 ( V_312 ) ) {
V_106 = - V_313 ;
goto V_127;
}
V_206 = V_255 ;
case V_320 :
V_106 = F_165 ( V_26 , V_206 , exp , V_114 , & V_295 ) ;
goto V_127;
default:
F_69 ( L_23 , V_304 ) ;
V_106 = - V_321 ;
goto V_127;
}
V_127:
F_173 ( V_26 ) ;
F_60 ( V_26 ) ;
for ( V_309 = V_295 . V_322 , V_215 = 0 ; V_215 < 4 ;
V_215 ++ , V_309 ++ ) {
if ( ! V_309 -> V_179 )
break;
F_174 ( & V_309 -> V_60 , V_309 -> V_179 ) ;
}
return V_106 ;
}
static int F_85 ( const struct V_25 * V_26 ,
struct V_6 * V_323 , struct V_120 * V_324 )
{
struct V_72 * V_73 = & V_323 -> V_140 . V_141 ;
struct V_6 * V_124 ;
struct V_325 V_326 = { L_24 } ;
struct V_327 * V_328 = NULL ;
int V_106 ;
if ( V_324 -> V_329 < 2 || F_175 ( V_324 , 1 ) < 1 ) {
F_69 ( L_25 ) ;
return - V_242 ;
}
V_124 = F_83 ( F_84 ( V_324 , 1 ) ) ;
if ( ! V_124 || ! V_124 -> V_330 || ! V_124 -> V_331 ) {
F_69 ( L_26 ,
F_84 ( V_324 , 1 ) ) ;
return - V_242 ;
}
F_176 ( & V_73 -> V_87 ) ;
F_44 ( & V_73 -> V_89 ) ;
F_44 ( & V_73 -> V_157 ) ;
V_73 -> V_198 = 0 ;
V_328 = F_81 ( sizeof( * V_328 ) , V_62 ) ;
if ( ! V_328 )
return - V_66 ;
V_328 -> V_332 = V_333 | V_334 |
V_335 |
V_336 | V_337 |
V_338 | V_339 |
V_340 ;
V_328 -> V_341 = V_342 ;
V_328 -> V_343 = V_344 ;
V_328 -> V_345 = V_168 ;
V_106 = F_177 ( V_26 , & V_73 -> V_244 , V_124 , & V_326 , V_328 , NULL ) ;
F_60 ( V_328 ) ;
if ( V_106 != 0 ) {
F_69 ( L_27 ,
F_84 ( V_324 , 1 ) ) ;
return V_106 ;
}
return V_106 ;
}
static int F_87 ( struct V_6 * V_323 )
{
struct V_72 * V_73 = & V_323 -> V_140 . V_141 ;
int V_106 ;
if ( ! F_32 ( & V_323 -> V_346 ) ) {
F_69 ( L_28 ) ;
return - V_43 ;
}
F_14 ( F_56 ( & V_73 -> V_244 -> V_347 ) > 0 ) ;
V_106 = F_178 ( V_73 -> V_244 ) ;
if ( V_106 != 0 )
F_69 ( L_29 , V_106 ) ;
return V_106 ;
}
static int F_179 ( const struct V_25 * V_26 ,
struct V_276 * * exp ,
struct V_6 * V_348 , struct V_325 * V_349 ,
struct V_327 * V_114 , void * V_350 )
{
int V_106 ;
struct V_212 V_351 = { 0 } ;
V_106 = F_180 ( & V_351 , V_348 , V_349 ) ;
if ( V_106 == 0 ) {
* exp = F_181 ( & V_351 ) ;
}
return V_106 ;
}
static int F_182 ( struct V_276 * exp )
{
int V_106 ;
if ( ! exp ) {
V_106 = - V_242 ;
goto V_127;
}
V_106 = F_183 ( exp ) ;
goto V_127;
V_127:
return V_106 ;
}
static int F_184 ( void )
{
int V_106 ;
V_106 = F_185 ( V_352 ) ;
if ( V_106 == 0 ) {
V_106 = F_186 ( & V_353 , NULL ,
V_52 ,
& V_196 ) ;
if ( V_106 )
F_187 ( V_352 ) ;
}
return V_106 ;
}
static void F_188 ( void )
{
F_189 ( V_52 ) ;
F_187 ( V_352 ) ;
}
static int T_10 F_190 ( void )
{
F_191 ( L_30 ) ;
F_14 ( V_219 % V_254 == 0 ) ;
return F_184 () ;
}
static void F_192 ( void )
{
F_188 () ;
}
