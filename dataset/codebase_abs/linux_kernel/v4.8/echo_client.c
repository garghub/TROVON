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
static int F_55 ( struct V_1 * V_70 ,
struct V_90 * * V_91 )
{
int V_92 ;
if ( V_70 -> V_77 )
return F_56 ( V_70 -> V_74 -> V_93 , V_91 ) ;
V_92 = F_57 ( 1 ) ;
F_14 ( ! * V_91 ) ;
* V_91 = F_58 ( V_92 , V_62 ) ;
if ( ! * V_91 )
return - V_66 ;
( * V_91 ) -> V_94 [ 0 ] = F_58 ( sizeof( struct V_95 ) , V_62 ) ;
if ( ! ( * V_91 ) -> V_94 [ 0 ] ) {
F_59 ( * V_91 ) ;
return - V_66 ;
}
F_60 ( ( * V_91 ) -> V_94 [ 0 ] ) ;
( * V_91 ) -> V_96 = V_97 ;
F_61 ( & ( * V_91 ) -> V_98 ) ;
return V_92 ;
}
static int F_62 ( struct V_1 * V_70 , struct V_90 * * V_91 )
{
int V_92 ;
if ( V_70 -> V_77 )
return F_63 ( V_70 -> V_74 -> V_93 , V_91 ) ;
V_92 = F_57 ( 1 ) ;
F_59 ( ( * V_91 ) -> V_94 [ 0 ] ) ;
F_59 ( * V_91 ) ;
* V_91 = NULL ;
return 0 ;
}
static void F_64 ( const struct V_25 * V_26 , struct V_68 * V_55 )
{
struct V_10 * V_11 = F_7 ( F_48 ( V_55 ) ) ;
struct V_72 * V_73 = V_11 -> V_86 -> V_74 ;
F_14 ( F_65 ( & V_11 -> V_48 ) == 0 ) ;
F_52 ( & V_73 -> V_87 ) ;
F_66 ( & V_11 -> V_88 ) ;
F_54 ( & V_73 -> V_87 ) ;
F_67 ( V_55 ) ;
F_68 ( V_55 -> V_83 ) ;
if ( V_11 -> V_85 )
F_62 ( V_11 -> V_86 , & V_11 -> V_85 ) ;
F_33 ( V_99 , V_11 ) ;
}
static int F_69 ( const struct V_25 * V_26 , void * V_50 ,
T_1 V_100 , const struct V_68 * V_13 )
{
struct V_10 * V_55 = F_7 ( F_48 ( V_13 ) ) ;
return (* V_100)( V_26 , V_50 , L_2 , V_55 ) ;
}
static struct V_68 * F_70 ( const struct V_25 * V_26 ,
const struct V_101 * V_102 ,
struct V_79 * V_3 )
{
struct V_10 * V_11 ;
struct V_68 * V_55 = NULL ;
F_14 ( ! V_102 ) ;
V_11 = F_42 ( V_99 , V_62 ) ;
if ( V_11 ) {
struct V_103 * V_102 = & V_11 -> V_104 ;
V_55 = & F_6 ( V_11 ) -> V_105 ;
F_71 ( V_102 ) ;
V_102 -> V_106 = F_72 ( sizeof( struct V_56 ) ) ;
F_73 ( V_55 , & V_102 -> V_107 , V_3 ) ;
F_74 ( & V_102 -> V_107 , V_55 ) ;
V_11 -> V_12 . V_108 = & V_109 ;
V_55 -> V_110 = & V_111 ;
}
return V_55 ;
}
static int F_75 ( const struct V_25 * V_26 , struct V_1 * V_70 )
{
struct V_112 * V_113 = & V_70 -> V_114 ;
int V_115 ;
V_115 = F_76 ( V_113 , & V_70 -> V_4 ) ;
if ( V_115 ) {
F_77 ( L_3 , V_115 ) ;
return V_115 ;
}
V_115 = F_78 ( & V_113 -> V_116 ) ;
if ( V_115 )
return V_115 ;
V_70 -> V_117 = V_113 ;
return 0 ;
}
static void F_79 ( const struct V_25 * V_26 , struct V_1 * V_70 )
{
if ( V_70 -> V_117 ) {
F_80 ( V_70 -> V_117 ) ;
V_70 -> V_117 = NULL ;
}
}
static void * F_81 ( const struct V_118 * V_119 ,
struct V_120 * V_121 )
{
struct V_24 * V_27 ;
V_27 = F_42 ( V_122 , V_62 ) ;
if ( ! V_27 )
V_27 = F_82 ( - V_66 ) ;
return V_27 ;
}
static void F_83 ( const struct V_118 * V_119 ,
struct V_120 * V_121 , void * V_123 )
{
struct V_24 * V_27 = V_123 ;
F_33 ( V_122 , V_27 ) ;
}
static void F_84 ( const struct V_118 * V_119 ,
struct V_120 * V_121 , void * V_123 )
{
}
static void * F_85 ( const struct V_118 * V_119 ,
struct V_120 * V_121 )
{
struct V_124 * V_125 ;
V_125 = F_42 ( V_126 , V_62 ) ;
if ( ! V_125 )
V_125 = F_82 ( - V_66 ) ;
return V_125 ;
}
static void F_86 ( const struct V_118 * V_119 ,
struct V_120 * V_121 , void * V_123 )
{
struct V_124 * V_125 = V_123 ;
F_33 ( V_126 , V_125 ) ;
}
static void F_87 ( const struct V_118 * V_119 ,
struct V_120 * V_121 , void * V_123 )
{
}
static struct V_79 * F_88 ( const struct V_25 * V_26 ,
struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_79 * V_131 ;
struct V_1 * V_70 ;
struct V_2 * V_132 ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_133 ;
const char * V_134 ;
int V_115 , V_135 ;
V_70 = F_58 ( sizeof( * V_70 ) , V_62 ) ;
if ( ! V_70 ) {
V_115 = - V_66 ;
goto V_136;
}
V_132 = & V_70 -> V_4 ;
V_115 = F_89 ( V_132 , V_128 ) ;
if ( V_115 )
goto V_137;
V_132 -> V_138 . V_81 = & V_139 ;
V_132 -> V_140 = & V_141 ;
V_7 = F_90 ( F_91 ( V_130 , 0 ) ) ;
F_14 ( V_7 ) ;
F_14 ( V_26 ) ;
V_133 = F_90 ( F_91 ( V_130 , 1 ) ) ;
if ( ! V_133 ) {
F_77 ( L_4 ,
F_91 ( V_130 , 1 ) ) ;
V_115 = - V_142 ;
goto V_143;
}
V_131 = V_133 -> V_8 ;
if ( ! strcmp ( V_133 -> V_144 -> V_145 , V_146 ) ) {
F_77 ( L_5 ) ;
V_115 = - V_147 ;
goto V_143;
}
V_115 = F_75 ( V_26 , V_70 ) ;
if ( V_115 )
goto V_143;
V_115 = F_92 ( V_26 , V_7 , V_130 ) ;
if ( V_115 )
goto V_148;
V_70 -> V_74 = & V_7 -> V_149 . V_150 ;
if ( V_131 && ! F_93 ( V_131 ) )
V_131 = NULL ;
V_134 = V_133 -> V_144 -> V_145 ;
if ( V_131 ) {
if ( V_131 -> V_151 ) {
V_115 = - V_43 ;
goto V_152;
}
V_131 -> V_151 = & V_70 -> V_117 -> V_116 ;
V_115 = V_131 -> V_153 -> V_154 -> V_155 ( V_26 , V_131 ,
V_131 -> V_153 -> V_156 ,
NULL ) ;
if ( V_115 )
goto V_152;
} else {
F_14 ( strcmp ( V_134 , V_157 ) == 0 ) ;
}
V_70 -> V_77 = V_131 ;
return & V_132 -> V_138 ;
V_152:
V_135 = F_94 ( V_7 ) ;
if ( V_135 )
F_77 ( L_6 ,
V_7 -> V_158 , V_135 ) ;
V_148:
F_79 ( V_26 , V_70 ) ;
V_143:
F_95 ( & V_70 -> V_4 ) ;
V_137:
F_59 ( V_70 ) ;
V_136:
return F_82 ( V_115 ) ;
}
static int F_96 ( const struct V_25 * V_26 , struct V_79 * V_5 ,
const char * V_159 , struct V_79 * V_131 )
{
F_97 () ;
return 0 ;
}
static struct V_79 * F_98 ( const struct V_25 * V_26 ,
struct V_79 * V_5 )
{
struct V_1 * V_70 = F_1 ( F_5 ( V_5 ) ) ;
struct V_79 * V_131 = V_70 -> V_77 ;
while ( V_131 )
V_131 = V_131 -> V_153 -> V_154 -> V_160 ( V_26 , V_131 ) ;
return NULL ;
}
static void F_99 ( const struct V_25 * V_26 ,
struct V_18 * V_22 ,
int V_161 )
{
struct V_21 * V_162 = F_11 ( V_22 ) ;
F_100 ( V_26 , V_162 ) ;
}
static struct V_79 * F_101 ( const struct V_25 * V_26 ,
struct V_79 * V_5 )
{
struct V_1 * V_70 = F_1 ( F_5 ( V_5 ) ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_10 * V_11 ;
struct V_79 * V_131 = V_70 -> V_77 ;
F_102 ( V_163 , L_7 ,
V_70 , V_131 ) ;
F_103 ( V_26 , & V_70 -> V_117 -> V_116 , - 1 ) ;
F_52 ( & V_73 -> V_87 ) ;
F_104 (eco, &ec->ec_objects, eo_obj_chain)
V_11 -> V_164 = 1 ;
F_54 ( & V_73 -> V_87 ) ;
F_103 ( V_26 , & V_70 -> V_117 -> V_116 , - 1 ) ;
F_102 ( V_163 ,
L_8 ) ;
F_52 ( & V_73 -> V_87 ) ;
while ( ! F_32 ( & V_73 -> V_89 ) ) {
F_54 ( & V_73 -> V_87 ) ;
F_77 ( L_9 ) ;
F_105 ( V_165 ) ;
F_106 ( F_107 ( 1 ) ) ;
F_103 ( V_26 , & V_70 -> V_117 -> V_116 , - 1 ) ;
F_52 ( & V_73 -> V_87 ) ;
}
F_54 ( & V_73 -> V_87 ) ;
F_14 ( F_32 ( & V_73 -> V_166 ) ) ;
F_102 ( V_163 , L_10 ) ;
F_94 ( V_5 -> V_167 ) ;
while ( V_131 )
V_131 = V_131 -> V_153 -> V_154 -> V_168 ( V_26 , V_131 ) ;
F_14 ( V_70 -> V_117 == F_108 ( V_5 -> V_151 ) ) ;
F_79 ( V_26 , V_70 ) ;
F_95 ( & V_70 -> V_4 ) ;
F_59 ( V_70 ) ;
return NULL ;
}
static struct V_10 * F_109 ( struct V_1 * V_5 ,
struct V_90 * * V_91 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_30 * V_67 ;
struct V_90 * V_169 ;
struct V_10 * V_11 ;
struct V_9 * V_55 ;
struct V_170 * V_171 ;
int V_172 ;
int V_115 ;
F_14 ( V_91 ) ;
V_169 = * V_91 ;
F_14 ( V_169 ) ;
F_110 ( F_111 ( & V_169 -> V_98 ) != 0 , V_173 L_11 , F_112 ( & V_169 -> V_98 ) ) ;
F_110 ( F_113 ( & V_169 -> V_98 ) == V_174 , V_173 L_11 ,
F_112 ( & V_169 -> V_98 ) ) ;
if ( F_3 ( V_5 ) -> V_138 . V_167 -> V_175 )
return F_82 ( - V_142 ) ;
V_26 = F_114 ( & V_172 ) ;
if ( F_115 ( V_26 ) )
return ( void * ) V_26 ;
V_27 = F_12 ( V_26 ) ;
V_67 = & V_27 -> V_176 ;
if ( V_5 -> V_77 ) {
struct V_95 * V_177 = V_169 -> V_94 [ 0 ] ;
F_14 ( V_177 ) ;
V_177 -> V_178 = V_169 -> V_98 ;
V_67 -> V_33 . V_149 . V_179 = V_177 ;
}
V_67 -> V_84 = V_91 ;
V_171 = & V_27 -> V_180 ;
V_115 = F_116 ( V_171 , & V_169 -> V_98 , 0 ) ;
if ( V_115 != 0 ) {
V_11 = F_82 ( V_115 ) ;
goto V_136;
}
V_55 = F_117 ( V_26 , F_3 ( V_5 ) , V_171 , & V_67 -> V_33 ) ;
if ( F_115 ( V_55 ) ) {
V_11 = ( void * ) V_55 ;
goto V_136;
}
V_11 = F_7 ( V_55 ) ;
if ( V_11 -> V_164 ) {
F_118 ( V_26 , V_55 ) ;
V_11 = F_82 ( - V_40 ) ;
}
V_136:
F_119 ( V_26 , & V_172 ) ;
return V_11 ;
}
static int F_120 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
struct V_9 * V_55 = F_6 ( V_11 ) ;
int V_172 ;
V_26 = F_114 ( & V_172 ) ;
if ( F_115 ( V_26 ) )
return F_121 ( V_26 ) ;
if ( V_11 -> V_164 ) {
struct V_101 * V_181 = V_55 -> V_105 . V_83 ;
F_14 ( & V_11 -> V_104 == F_122 ( V_181 ) ) ;
F_123 ( V_182 , & V_181 -> V_183 ) ;
}
F_118 ( V_26 , V_55 ) ;
F_119 ( V_26 , & V_172 ) ;
return 0 ;
}
static int F_124 ( struct V_25 * V_26 , struct V_10 * V_11 ,
T_3 V_184 , T_3 V_185 , int V_186 ,
T_4 * V_50 , T_5 V_187 )
{
struct V_35 * V_36 ;
struct V_21 * V_188 ;
struct V_9 * V_55 ;
struct V_189 * V_190 ;
struct V_24 * V_27 ;
int V_115 = - V_66 ;
V_27 = F_12 ( V_26 ) ;
V_36 = & V_27 -> V_191 ;
V_188 = & V_27 -> V_192 ;
V_55 = F_6 ( V_11 ) ;
memset ( V_188 , 0 , sizeof( * V_188 ) ) ;
V_190 = & V_188 -> V_193 ;
V_190 -> V_194 = V_55 ;
V_190 -> V_195 = F_125 ( V_55 , V_184 ) ;
V_190 -> V_196 = F_125 ( V_55 , V_185 ) ;
V_190 -> V_197 = V_186 == V_198 ? V_199 : V_200 ;
V_190 -> V_201 = V_187 ;
V_36 -> V_202 = V_55 ;
V_115 = F_126 ( V_26 , V_36 , V_188 ) ;
if ( V_115 == 0 ) {
struct V_72 * V_73 = V_11 -> V_86 -> V_74 ;
struct V_18 * V_61 ;
V_61 = F_10 ( F_127 ( V_188 , & V_203 ) ) ;
F_52 ( & V_73 -> V_87 ) ;
if ( F_32 ( & V_61 -> V_53 ) ) {
F_128 ( & V_61 -> V_53 , & V_73 -> V_166 ) ;
V_61 -> V_204 = ++ V_73 -> V_205 ;
}
F_39 ( & V_61 -> V_65 ) ;
* V_50 = V_61 -> V_204 ;
F_54 ( & V_73 -> V_87 ) ;
}
return V_115 ;
}
static int F_129 ( struct V_25 * V_26 , struct V_1 * V_70 ,
T_4 V_50 )
{
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_18 * V_22 = NULL ;
struct V_206 * V_61 ;
int V_207 = 0 , V_161 = 0 ;
F_52 ( & V_73 -> V_87 ) ;
F_130 (el, &ec->ec_locks) {
V_22 = F_131 ( V_61 , struct V_18 , V_53 ) ;
F_102 ( V_163 , L_12 , V_22 , V_22 -> V_204 ) ;
V_207 = ( V_22 -> V_204 == V_50 ) ;
if ( V_207 ) {
if ( F_132 ( & V_22 -> V_65 ) )
F_66 ( & V_22 -> V_53 ) ;
else
V_161 = 1 ;
break;
}
}
F_54 ( & V_73 -> V_87 ) ;
if ( ! V_207 )
return - V_208 ;
F_99 ( V_26 , V_22 , V_161 ) ;
return 0 ;
}
static void F_133 ( const struct V_25 * V_26 , struct V_35 * V_36 ,
struct V_56 * V_57 )
{
struct V_24 * V_27 ;
struct V_209 * V_210 ;
V_27 = F_12 ( V_26 ) ;
F_14 ( V_36 == & V_27 -> V_191 ) ;
V_210 = & V_27 -> V_211 ;
F_134 ( & V_210 -> V_212 , V_57 ) ;
}
static int F_135 ( struct V_10 * V_11 , int V_213 , T_3 V_214 ,
struct V_57 * * V_215 , int V_216 , int V_217 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_9 * V_55 = F_6 ( V_11 ) ;
struct V_1 * V_70 = V_11 -> V_86 ;
struct V_209 * V_210 ;
struct V_35 * V_36 ;
struct V_56 * V_218 ;
struct V_219 V_220 = { 0 } ;
int V_221 = F_136 ( V_55 ) ;
int V_172 ;
int V_115 ;
int V_222 ;
F_14 ( ( V_214 & ~ V_223 ) == 0 ) ;
F_14 ( V_70 -> V_77 ) ;
V_26 = F_114 ( & V_172 ) ;
if ( F_115 ( V_26 ) )
return F_121 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_36 = & V_27 -> V_191 ;
V_210 = & V_27 -> V_211 ;
F_137 ( V_210 ) ;
V_36 -> V_224 = 1 ;
V_115 = F_138 ( V_26 , V_36 , V_225 , V_55 ) ;
if ( V_115 < 0 )
goto V_136;
F_14 ( V_115 == 0 ) ;
V_115 = F_124 ( V_26 , V_11 , V_214 ,
V_214 + V_216 * V_226 - 1 ,
V_213 == V_227 ? V_228 : V_198 , & V_220 . V_50 ,
V_229 ) ;
if ( V_115 < 0 )
goto V_230;
for ( V_222 = 0 ; V_222 < V_216 ; V_222 ++ ) {
F_14 ( V_215 [ V_222 ] ) ;
V_218 = F_139 ( V_26 , V_55 , F_125 ( V_55 , V_214 ) ,
V_215 [ V_222 ] , V_231 ) ;
if ( F_115 ( V_218 ) ) {
V_115 = F_121 ( V_218 ) ;
break;
}
F_14 ( V_218 -> V_232 == V_231 ) ;
V_115 = F_140 ( V_26 , V_36 , V_218 ) ;
if ( V_115 ) {
F_14 ( V_218 -> V_233 == V_234 ) ;
F_141 ( V_26 , V_218 ) ;
break;
}
F_134 ( & V_210 -> V_235 , V_218 ) ;
F_141 ( V_26 , V_218 ) ;
F_142 ( V_26 , V_218 , 0 , V_221 ) ;
V_214 += V_221 ;
}
if ( V_115 == 0 ) {
enum V_236 V_237 = V_213 == V_227 ? V_238 : V_239 ;
V_217 = V_217 && ( V_237 == V_239 ) ;
if ( V_217 )
V_115 = F_143 ( V_26 , V_36 , & V_210 -> V_235 ,
0 , V_226 ,
F_133 ) ;
else
V_115 = F_144 ( V_26 , V_36 , V_237 , V_210 , 0 ) ;
F_102 ( V_163 , L_13 ,
V_217 ? L_14 : L_15 , V_115 ) ;
}
F_129 ( V_26 , V_70 , V_220 . V_50 ) ;
V_230:
F_145 ( V_26 , V_36 , V_210 ) ;
F_146 ( V_26 , V_36 , V_210 ) ;
F_147 ( V_26 , V_210 ) ;
F_148 ( V_26 , V_36 ) ;
V_136:
F_119 ( V_26 , & V_172 ) ;
return V_115 ;
}
static int F_149 ( const struct V_25 * V_26 , struct V_1 * V_70 ,
struct V_240 * V_241 , struct V_242 * V_243 )
{
struct V_10 * V_11 ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_90 * V_169 = NULL ;
int V_115 ;
int V_244 = 0 ;
if ( ! ( V_241 -> V_245 & V_246 ) ||
! ( V_241 -> V_245 & V_247 ) ||
! F_150 ( F_113 ( & V_241 -> V_248 ) ) ) {
F_77 ( L_16 V_173 L_11 , F_112 ( & V_241 -> V_248 ) ) ;
return - V_249 ;
}
V_115 = F_55 ( V_70 , & V_169 ) ;
if ( V_115 < 0 ) {
F_77 ( L_17 , V_115 ) ;
goto V_250;
}
V_169 -> V_98 = V_241 -> V_248 ;
if ( F_111 ( & V_169 -> V_98 ) == 0 )
F_151 ( & V_169 -> V_98 , ++ V_251 ) ;
V_115 = F_152 ( V_26 , V_73 -> V_93 , V_241 , & V_169 , V_243 ) ;
if ( V_115 != 0 ) {
F_77 ( L_18 , V_115 ) ;
goto V_250;
}
V_244 = 1 ;
V_241 -> V_248 = V_169 -> V_98 ;
V_241 -> V_245 |= V_246 ;
V_11 = F_109 ( V_70 , & V_169 ) ;
if ( F_115 ( V_11 ) ) {
V_115 = F_121 ( V_11 ) ;
goto V_250;
}
F_120 ( V_11 ) ;
F_102 ( V_163 , L_19 V_173 L_11 , F_112 ( & V_241 -> V_248 ) ) ;
V_250:
if ( V_244 && V_115 )
F_153 ( V_26 , V_73 -> V_93 , V_241 , V_169 , V_243 , NULL ) ;
if ( V_169 )
F_62 ( V_70 , & V_169 ) ;
if ( V_115 )
F_77 ( L_20 , V_115 ) ;
return V_115 ;
}
static int F_154 ( struct V_10 * * V_252 , struct V_1 * V_70 ,
struct V_240 * V_241 )
{
struct V_90 * V_169 = NULL ;
struct V_10 * V_11 ;
int V_115 ;
if ( ( V_241 -> V_245 & V_246 ) == 0 || F_111 ( & V_241 -> V_248 ) == 0 ) {
F_77 ( L_21 ) ;
return - V_249 ;
}
V_115 = F_55 ( V_70 , & V_169 ) ;
if ( V_115 < 0 )
return V_115 ;
V_169 -> V_98 = V_241 -> V_248 ;
if ( ! ( V_241 -> V_245 & V_247 ) )
F_61 ( & V_169 -> V_98 ) ;
V_115 = 0 ;
V_11 = F_109 ( V_70 , & V_169 ) ;
if ( ! F_115 ( V_11 ) )
* V_252 = V_11 ;
else
V_115 = F_121 ( V_11 ) ;
if ( V_169 )
F_62 ( V_70 , & V_169 ) ;
return V_115 ;
}
static void F_155 ( struct V_10 * V_11 )
{
int V_115 ;
V_115 = F_120 ( V_11 ) ;
if ( V_115 )
F_77 ( L_22 ,
V_11 -> V_86 -> V_74 -> V_93 -> V_253 -> V_158 , V_115 ) ;
}
static void
F_156 ( struct V_57 * V_57 , int V_213 , T_3 V_254 ,
T_3 V_214 , T_3 V_255 )
{
char * V_256 ;
T_3 V_257 ;
T_3 V_258 ;
int V_259 ;
F_14 ( V_255 == V_226 ) ;
V_256 = F_157 ( V_57 ) ;
for ( V_259 = 0 ; V_259 < V_226 ; V_259 += V_260 ) {
if ( V_213 == V_261 ) {
V_257 = V_214 + V_259 ;
V_258 = V_254 ;
} else {
V_257 = 0xdeadbeef00c0ffeeULL ;
V_258 = 0xdeadbeef00c0ffeeULL ;
}
F_158 ( V_256 + V_259 , V_260 ,
V_257 , V_258 ) ;
}
F_159 ( V_57 ) ;
}
static int F_160 ( struct V_57 * V_57 , T_3 V_254 ,
T_3 V_214 , T_3 V_255 )
{
T_3 V_257 ;
T_3 V_258 ;
char * V_256 ;
int V_259 ;
int V_115 ;
int V_262 ;
F_14 ( V_255 == V_226 ) ;
V_256 = F_157 ( V_57 ) ;
for ( V_115 = V_259 = 0 ; V_259 < V_226 ; V_259 += V_260 ) {
V_257 = V_214 + V_259 ;
V_258 = V_254 ;
V_262 = F_161 ( L_23 ,
V_256 + V_259 , V_260 ,
V_257 , V_258 ) ;
if ( V_262 != 0 ) {
F_77 ( L_24 , V_254 ) ;
V_115 = V_262 ;
}
}
F_159 ( V_57 ) ;
return V_115 ;
}
static int F_162 ( struct V_1 * V_70 , int V_213 , struct V_240 * V_241 ,
struct V_10 * V_11 , T_3 V_214 ,
T_3 V_255 , int V_217 ,
struct V_242 * V_243 )
{
T_6 V_216 ;
struct V_263 * V_264 ;
struct V_263 * V_265 ;
struct V_57 * * V_215 ;
T_3 V_266 ;
int V_222 ;
int V_115 ;
int V_267 ;
T_7 V_268 ;
int V_269 = 0 ;
V_267 = ( F_111 ( & V_241 -> V_248 ) != V_270 &&
( V_241 -> V_245 & V_271 ) != 0 &&
( V_241 -> V_272 & V_273 ) != 0 ) ;
V_268 = ( ( F_111 ( & V_241 -> V_248 ) & 2 ) == 0 ) ? V_274 : V_275 ;
F_14 ( V_213 == V_261 || V_213 == V_276 ) ;
if ( V_255 <= 0 ||
( V_255 & ( ~ V_223 ) ) != 0 )
return - V_249 ;
V_216 = V_255 >> V_277 ;
if ( V_213 == V_261 )
V_269 = V_278 ;
V_264 = F_163 ( V_216 , sizeof( * V_264 ) , V_62 ) ;
if ( ! V_264 )
return - V_66 ;
V_215 = F_163 ( V_216 , sizeof( * V_215 ) , V_62 ) ;
if ( ! V_215 ) {
F_59 ( V_264 ) ;
return - V_66 ;
}
for ( V_222 = 0 , V_265 = V_264 , V_266 = V_214 ;
V_222 < V_216 ;
V_222 ++ , V_265 ++ , V_266 += V_226 ) {
F_14 ( ! V_265 -> V_279 ) ;
V_115 = - V_66 ;
V_265 -> V_279 = F_164 ( V_268 ) ;
if ( ! V_265 -> V_279 )
goto V_136;
V_215 [ V_222 ] = V_265 -> V_279 ;
V_265 -> V_255 = V_226 ;
V_265 -> V_266 = V_266 ;
V_265 -> V_280 = V_269 ;
if ( V_267 )
F_156 ( V_265 -> V_279 , V_213 ,
F_111 ( & V_241 -> V_248 ) , V_266 ,
V_265 -> V_255 ) ;
}
F_14 ( V_70 -> V_77 ) ;
V_115 = F_135 ( V_11 , V_213 , V_214 , V_215 , V_216 , V_217 ) ;
V_136:
if ( V_115 != 0 || V_213 != V_276 )
V_267 = 0 ;
for ( V_222 = 0 , V_265 = V_264 ; V_222 < V_216 ; V_222 ++ , V_265 ++ ) {
if ( ! V_265 -> V_279 )
continue;
if ( V_267 ) {
int V_281 ;
V_281 = F_160 ( V_265 -> V_279 ,
F_111 ( & V_241 -> V_248 ) ,
V_265 -> V_266 , V_265 -> V_255 ) ;
if ( V_281 != 0 && V_115 == 0 )
V_115 = V_281 ;
}
F_165 ( V_265 -> V_279 ) ;
}
F_59 ( V_264 ) ;
F_59 ( V_215 ) ;
return V_115 ;
}
static int F_166 ( const struct V_25 * V_26 ,
struct V_282 * exp , int V_213 ,
struct V_240 * V_241 , struct V_10 * V_11 ,
T_3 V_214 , T_3 V_255 ,
T_3 V_283 , struct V_242 * V_243 ,
int V_217 )
{
struct V_284 V_285 ;
struct V_286 * V_287 ;
struct V_288 * V_289 ;
T_3 V_266 ;
T_3 V_216 , V_290 ;
int V_222 , V_291 = 0 , V_269 = 0 ;
if ( V_255 <= 0 || ( V_255 & ( ~ V_223 ) ) != 0 )
return - V_249 ;
V_216 = V_283 >> V_277 ;
V_290 = V_255 >> V_277 ;
V_287 = F_163 ( V_216 , sizeof( struct V_286 ) , V_62 ) ;
V_289 = F_163 ( V_216 , sizeof( struct V_288 ) , V_62 ) ;
if ( ! V_287 || ! V_289 ) {
V_291 = - V_66 ;
goto V_136;
}
if ( V_213 == V_261 && V_217 )
V_269 |= V_278 ;
F_167 ( V_241 , & V_285 ) ;
V_266 = V_214 ;
for (; V_290 ; V_290 -= V_216 ) {
int V_292 ;
if ( V_290 < V_216 )
V_216 = V_290 ;
for ( V_222 = 0 ; V_222 < V_216 ; V_222 ++ , V_266 += V_226 ) {
V_289 [ V_222 ] . V_214 = V_266 ;
V_289 [ V_222 ] . V_293 = V_226 ;
V_289 [ V_222 ] . V_294 = V_269 ;
}
V_285 . V_295 = V_216 ;
V_243 -> V_296 = 0 ;
V_292 = V_216 ;
V_291 = F_168 ( V_26 , V_213 , exp , V_241 , 1 , & V_285 , V_289 , & V_292 ,
V_287 , V_243 ) ;
if ( V_291 != 0 )
goto V_136;
F_14 ( V_292 == V_216 ) ;
for ( V_222 = 0 ; V_222 < V_292 ; V_222 ++ ) {
struct V_57 * V_57 = V_287 [ V_222 ] . V_57 ;
if ( ! V_57 && V_287 [ V_222 ] . V_115 == 0 )
continue;
if ( V_217 )
V_287 [ V_222 ] . V_294 |= V_278 ;
if ( F_111 ( & V_241 -> V_248 ) == V_270 ||
( V_241 -> V_245 & V_271 ) == 0 ||
( V_241 -> V_272 & V_273 ) == 0 )
continue;
if ( V_213 == V_261 )
F_156 ( V_57 , V_213 ,
F_111 ( & V_241 -> V_248 ) ,
V_289 [ V_222 ] . V_214 ,
V_289 [ V_222 ] . V_293 ) ;
else
F_160 ( V_57 ,
F_111 ( & V_241 -> V_248 ) ,
V_289 [ V_222 ] . V_214 ,
V_289 [ V_222 ] . V_293 ) ;
}
V_291 = F_169 ( V_26 , V_213 , exp , V_241 , 1 , & V_285 ,
V_289 , V_216 , V_287 , V_243 , V_291 ) ;
if ( V_291 != 0 )
goto V_136;
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
F_170 ( (struct V_118 * ) & V_26 -> V_28 ) ;
F_171 ( (struct V_118 * ) & V_26 -> V_28 ) ;
}
V_136:
F_59 ( V_287 ) ;
F_59 ( V_289 ) ;
return V_291 ;
}
static int F_172 ( const struct V_25 * V_26 , int V_213 ,
struct V_282 * exp ,
struct V_297 * V_123 ,
struct V_242 * V_298 )
{
struct V_6 * V_7 = F_173 ( exp ) ;
struct V_1 * V_70 = F_4 ( V_7 ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_240 * V_241 = & V_123 -> V_299 ;
struct V_10 * V_11 ;
int V_115 ;
int V_217 = 1 ;
long V_300 ;
F_14 ( V_241 -> V_245 & V_247 ) ;
V_115 = F_154 ( & V_11 , V_70 , V_241 ) ;
if ( V_115 )
return V_115 ;
V_241 -> V_245 &= ~ V_301 ;
V_300 = ( long ) V_123 -> V_302 ;
if ( V_300 == 1 )
V_217 = 0 ;
if ( ! V_70 -> V_77 && V_300 != 3 ) {
V_300 = 3 ;
V_123 -> V_303 = V_123 -> V_304 ;
}
if ( V_123 -> V_303 > V_305 )
V_123 -> V_303 = V_305 ;
switch ( V_300 ) {
case 1 :
case 2 :
V_115 = F_162 ( V_70 , V_213 , V_241 ,
V_11 , V_123 -> V_306 ,
V_123 -> V_304 , V_217 , V_298 ) ;
break;
case 3 :
V_115 = F_166 ( V_26 , V_73 -> V_93 , V_213 , V_241 ,
V_11 , V_123 -> V_306 ,
V_123 -> V_304 , V_123 -> V_303 ,
V_298 , V_217 ) ;
break;
default:
V_115 = - V_249 ;
}
F_155 ( V_11 ) ;
return V_115 ;
}
static int
F_174 ( unsigned int V_307 , struct V_282 * exp , int V_293 ,
void * V_308 , void T_8 * V_309 )
{
struct V_6 * V_7 = exp -> V_253 ;
struct V_1 * V_70 = F_4 ( V_7 ) ;
struct V_72 * V_73 = V_70 -> V_74 ;
struct V_10 * V_11 ;
struct V_297 * V_123 = V_308 ;
struct V_242 V_298 ;
struct V_25 * V_26 ;
struct V_310 * V_311 ;
struct V_240 * V_241 ;
struct V_170 V_171 ;
int V_213 = V_276 ;
int V_115 = 0 ;
int V_222 ;
memset ( & V_298 , 0 , sizeof( V_298 ) ) ;
V_241 = & V_123 -> V_299 ;
if ( ! ( V_241 -> V_245 & V_247 ) ) {
V_241 -> V_245 |= V_247 ;
F_61 ( & V_241 -> V_248 ) ;
}
V_115 = F_116 ( & V_171 , & V_241 -> V_248 , 0 ) ;
if ( V_115 < 0 )
return V_115 ;
V_26 = F_58 ( sizeof( * V_26 ) , V_62 ) ;
if ( ! V_26 )
return - V_66 ;
V_115 = F_175 ( V_26 , V_312 ) ;
if ( V_115 ) {
V_115 = - V_66 ;
goto V_136;
}
switch ( V_307 ) {
case V_313 :
if ( ! F_176 ( V_314 ) ) {
V_115 = - V_315 ;
goto V_136;
}
V_115 = F_149 ( V_26 , V_70 , V_241 , & V_298 ) ;
goto V_136;
case V_316 :
if ( ! F_176 ( V_314 ) ) {
V_115 = - V_315 ;
goto V_136;
}
V_115 = F_154 ( & V_11 , V_70 , V_241 ) ;
if ( V_115 == 0 ) {
V_115 = F_153 ( V_26 , V_73 -> V_93 , V_241 , NULL ,
& V_298 , NULL ) ;
if ( V_115 == 0 )
V_11 -> V_164 = 1 ;
F_155 ( V_11 ) ;
}
goto V_136;
case V_317 :
V_115 = F_154 ( & V_11 , V_70 , V_241 ) ;
if ( V_115 == 0 ) {
struct V_318 V_177 = {
. V_319 = V_241 ,
} ;
V_115 = F_177 ( V_26 , V_73 -> V_93 , & V_177 ) ;
F_155 ( V_11 ) ;
}
goto V_136;
case V_320 :
if ( ! F_176 ( V_314 ) ) {
V_115 = - V_315 ;
goto V_136;
}
V_115 = F_154 ( & V_11 , V_70 , V_241 ) ;
if ( V_115 == 0 ) {
struct V_318 V_177 = {
. V_319 = V_241 ,
} ;
V_115 = F_178 ( V_26 , V_73 -> V_93 , & V_177 , NULL ) ;
F_155 ( V_11 ) ;
}
goto V_136;
case V_321 :
if ( ! F_176 ( V_314 ) ) {
V_115 = - V_315 ;
goto V_136;
}
V_213 = V_261 ;
case V_322 :
V_115 = F_172 ( V_26 , V_213 , exp , V_123 , & V_298 ) ;
goto V_136;
default:
F_77 ( L_25 , V_307 ) ;
V_115 = - V_323 ;
goto V_136;
}
V_136:
F_179 ( V_26 ) ;
F_59 ( V_26 ) ;
for ( V_311 = V_298 . V_324 , V_222 = 0 ; V_222 < 4 ;
V_222 ++ , V_311 ++ ) {
if ( ! V_311 -> V_186 )
break;
F_180 ( & V_311 -> V_60 , V_311 -> V_186 ) ;
}
return V_115 ;
}
static int F_92 ( const struct V_25 * V_26 ,
struct V_6 * V_325 , struct V_129 * V_326 )
{
struct V_72 * V_73 = & V_325 -> V_149 . V_150 ;
struct V_6 * V_133 ;
struct V_327 V_328 = { L_26 } ;
struct V_329 * V_330 = NULL ;
int V_115 ;
if ( V_326 -> V_331 < 2 || F_181 ( V_326 , 1 ) < 1 ) {
F_77 ( L_27 ) ;
return - V_249 ;
}
V_133 = F_90 ( F_91 ( V_326 , 1 ) ) ;
if ( ! V_133 || ! V_133 -> V_332 || ! V_133 -> V_333 ) {
F_77 ( L_28 ,
F_91 ( V_326 , 1 ) ) ;
return - V_249 ;
}
F_182 ( & V_73 -> V_87 ) ;
F_44 ( & V_73 -> V_89 ) ;
F_44 ( & V_73 -> V_166 ) ;
V_73 -> V_205 = 0 ;
V_330 = F_58 ( sizeof( * V_330 ) , V_62 ) ;
if ( ! V_330 )
return - V_66 ;
V_330 -> V_334 = V_335 | V_336 |
V_337 |
V_338 | V_339 |
V_340 | V_341 |
V_342 ;
V_330 -> V_343 = V_344 ;
V_330 -> V_345 = V_346 ;
V_330 -> V_347 = V_174 ;
V_115 = F_183 ( V_26 , & V_73 -> V_93 , V_133 , & V_328 , V_330 , NULL ) ;
F_59 ( V_330 ) ;
if ( V_115 != 0 ) {
F_77 ( L_29 ,
F_91 ( V_326 , 1 ) ) ;
return V_115 ;
}
return V_115 ;
}
static int F_94 ( struct V_6 * V_325 )
{
struct V_72 * V_73 = & V_325 -> V_149 . V_150 ;
int V_115 ;
if ( ! F_32 ( & V_325 -> V_348 ) ) {
F_77 ( L_30 ) ;
return - V_43 ;
}
F_14 ( F_65 ( & V_73 -> V_93 -> V_349 ) > 0 ) ;
V_115 = F_184 ( V_73 -> V_93 ) ;
if ( V_115 != 0 )
F_77 ( L_31 , V_115 ) ;
return V_115 ;
}
static int F_185 ( const struct V_25 * V_26 ,
struct V_282 * * exp ,
struct V_6 * V_350 , struct V_327 * V_351 ,
struct V_329 * V_123 , void * V_352 )
{
int V_115 ;
struct V_219 V_353 = { 0 } ;
V_115 = F_186 ( & V_353 , V_350 , V_351 ) ;
if ( V_115 == 0 ) {
* exp = F_187 ( & V_353 ) ;
}
return V_115 ;
}
static int F_188 ( struct V_282 * exp )
{
int V_115 ;
if ( ! exp ) {
V_115 = - V_249 ;
goto V_136;
}
V_115 = F_189 ( exp ) ;
goto V_136;
V_136:
return V_115 ;
}
static int F_190 ( void )
{
int V_115 ;
V_115 = F_191 ( V_354 ) ;
if ( V_115 == 0 ) {
V_115 = F_192 ( & V_355 , NULL ,
V_52 ,
& V_203 ) ;
if ( V_115 )
F_193 ( V_354 ) ;
}
return V_115 ;
}
static void F_194 ( void )
{
F_195 ( V_52 ) ;
F_193 ( V_354 ) ;
}
static int T_9 F_196 ( void )
{
F_197 ( L_32 ) ;
F_14 ( V_226 % V_260 == 0 ) ;
return F_190 () ;
}
static void F_198 ( void )
{
F_194 () ;
}
