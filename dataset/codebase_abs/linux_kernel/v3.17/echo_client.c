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
F_14 ( V_27 != NULL ) ;
return V_27 ;
}
static inline
struct V_30 * F_15 ( const struct V_31 * V_32 )
{
return F_8 ( V_32 , struct V_30 , V_33 ) ;
}
static struct V_34 * F_16 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 )
{
return F_9 ( V_35 ) -> V_36 ;
}
static int F_17 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 ,
struct V_37 * V_38 , int V_39 )
{
struct V_14 * V_40 = F_9 ( V_35 ) ;
if ( ! V_39 )
F_18 ( & V_40 -> V_41 ) ;
else if ( ! F_19 ( & V_40 -> V_41 ) )
return - V_42 ;
return 0 ;
}
static void F_20 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 ,
struct V_37 * V_38 )
{
struct V_14 * V_40 = F_9 ( V_35 ) ;
F_14 ( F_21 ( & V_40 -> V_41 ) ) ;
F_22 ( & V_40 -> V_41 ) ;
}
static void F_23 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 ,
struct V_37 * V_43 )
{
F_24 ( V_26 , V_35 -> V_44 ) ;
}
static int F_25 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 )
{
if ( F_21 ( & F_9 ( V_35 ) -> V_41 ) )
return - V_45 ;
return - V_46 ;
}
static void F_26 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 ,
int V_47 )
{
F_14 ( V_35 -> V_44 -> V_48 != NULL ) ;
}
static void F_27 ( const struct V_25 * V_26 ,
struct V_15 * V_35 )
{
struct V_14 * V_40 = F_9 ( V_35 ) ;
struct V_10 * V_11 = F_7 ( V_35 -> V_49 ) ;
struct V_34 * V_50 = V_40 -> V_36 ;
F_28 ( & V_11 -> V_51 ) ;
F_29 ( V_50 ) ;
}
static int F_30 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 ,
struct V_37 * V_43 )
{
return 0 ;
}
static int F_31 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 ,
void * V_52 , T_1 V_53 )
{
struct V_14 * V_40 = F_9 ( V_35 ) ;
(* V_53)( V_26 , V_52 , V_54 L_1 ,
V_40 , F_21 ( & V_40 -> V_41 ) , V_40 -> V_36 ) ;
return 0 ;
}
static void F_32 ( const struct V_25 * V_26 ,
struct V_19 * V_35 )
{
struct V_18 * V_22 = F_10 ( V_35 ) ;
F_14 ( F_33 ( & V_22 -> V_55 ) ) ;
F_34 ( V_22 , V_56 ) ;
}
static void F_35 ( const struct V_25 * V_26 ,
const struct V_19 * V_35 )
{
struct V_18 * V_22 = F_10 ( V_35 ) ;
F_14 ( F_33 ( & V_22 -> V_55 ) ) ;
}
static int F_36 ( const struct V_25 * V_26 ,
const struct V_19 * V_35 ,
const struct V_57 * V_58 ,
const struct V_37 * V_43 )
{
return 1 ;
}
static int F_37 ( const struct V_25 * V_26 , struct V_9 * V_59 ,
struct V_60 * V_34 , struct V_34 * V_50 )
{
struct V_14 * V_40 = F_38 ( V_59 , V_34 ) ;
struct V_10 * V_11 = F_7 ( V_59 ) ;
V_40 -> V_36 = V_50 ;
F_39 ( V_50 ) ;
F_40 ( & V_40 -> V_41 ) ;
F_41 ( V_34 , & V_40 -> V_17 , V_59 , & V_61 ) ;
F_42 ( & V_11 -> V_51 ) ;
return 0 ;
}
static int F_43 ( const struct V_25 * V_26 , struct V_9 * V_59 ,
struct V_37 * V_38 )
{
return 0 ;
}
static int F_44 ( const struct V_25 * V_26 ,
struct V_9 * V_59 , struct V_21 * V_62 ,
const struct V_37 * V_43 )
{
struct V_18 * V_63 ;
F_45 ( V_63 , V_56 , V_64 ) ;
if ( V_63 != NULL ) {
F_46 ( V_62 , & V_63 -> V_20 , V_59 , & V_65 ) ;
V_63 -> V_66 = F_7 ( V_59 ) ;
F_47 ( & V_63 -> V_55 ) ;
F_48 ( & V_63 -> V_67 , 0 ) ;
}
return V_63 == NULL ? - V_68 : 0 ;
}
static int F_49 ( const struct V_25 * V_26 , struct V_9 * V_59 ,
const struct V_31 * V_69 )
{
return 0 ;
}
static int F_50 ( const struct V_25 * V_26 , struct V_70 * V_59 ,
const struct V_71 * V_69 )
{
struct V_1 * V_72 = F_1 ( F_5 ( V_59 -> V_73 ) ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_10 * V_11 = F_7 ( F_51 ( V_59 ) ) ;
if ( V_72 -> V_77 ) {
struct V_70 * V_78 ;
struct V_79 * V_80 ;
V_80 = V_72 -> V_77 ;
V_78 = V_80 -> V_81 -> V_82 ( V_26 , V_59 -> V_83 ,
V_80 ) ;
if ( V_78 == NULL )
return - V_68 ;
F_52 ( V_59 , V_78 ) ;
}
if ( ! V_72 -> V_84 ) {
const struct V_31 * V_85 = F_53 ( V_69 ) ;
struct V_30 * V_86 = F_15 ( V_85 ) ;
F_14 ( V_86 -> V_87 ) ;
V_11 -> V_88 = * V_86 -> V_87 ;
* V_86 -> V_87 = NULL ;
} else {
V_11 -> V_88 = NULL ;
}
V_11 -> V_89 = V_72 ;
F_48 ( & V_11 -> V_51 , 0 ) ;
F_54 ( F_51 ( V_59 ) , sizeof( struct V_14 ) ) ;
F_55 ( & V_75 -> V_90 ) ;
F_56 ( & V_11 -> V_91 , & V_75 -> V_92 ) ;
F_57 ( & V_75 -> V_90 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_72 ,
struct V_93 * * V_94 )
{
int V_95 ;
if ( V_72 -> V_77 != NULL )
return F_59 ( V_72 -> V_76 -> V_96 , V_94 ) ;
V_95 = F_60 ( 1 ) ;
F_14 ( * V_94 == NULL ) ;
F_61 ( * V_94 , V_95 ) ;
if ( * V_94 == NULL )
return - V_68 ;
F_61 ( ( * V_94 ) -> V_97 [ 0 ] , sizeof( struct V_98 ) ) ;
if ( ( * V_94 ) -> V_97 [ 0 ] == NULL ) {
F_62 ( * V_94 , V_95 ) ;
return - V_68 ;
}
F_63 ( ( * V_94 ) -> V_97 [ 0 ] ) ;
( * V_94 ) -> V_99 = V_100 ;
F_64 ( & ( * V_94 ) -> V_101 ) ;
return V_95 ;
}
static int F_65 ( struct V_1 * V_72 , struct V_93 * * V_94 )
{
int V_95 ;
if ( V_72 -> V_77 != NULL )
return F_66 ( V_72 -> V_76 -> V_96 , V_94 ) ;
V_95 = F_60 ( 1 ) ;
F_14 ( * V_94 != NULL ) ;
F_62 ( ( * V_94 ) -> V_97 [ 0 ] , sizeof( struct V_98 ) ) ;
F_62 ( * V_94 , V_95 ) ;
* V_94 = NULL ;
return 0 ;
}
static void F_67 ( const struct V_25 * V_26 , struct V_70 * V_59 )
{
struct V_10 * V_11 = F_7 ( F_51 ( V_59 ) ) ;
struct V_74 * V_75 = V_11 -> V_89 -> V_76 ;
F_14 ( F_68 ( & V_11 -> V_51 ) == 0 ) ;
F_55 ( & V_75 -> V_90 ) ;
F_69 ( & V_11 -> V_91 ) ;
F_57 ( & V_75 -> V_90 ) ;
F_70 ( V_59 ) ;
F_71 ( V_59 -> V_83 ) ;
if ( V_11 -> V_88 )
F_65 ( V_11 -> V_89 , & V_11 -> V_88 ) ;
F_34 ( V_11 , V_102 ) ;
}
static int F_72 ( const struct V_25 * V_26 , void * V_52 ,
T_1 V_103 , const struct V_70 * V_13 )
{
struct V_10 * V_59 = F_7 ( F_51 ( V_13 ) ) ;
return (* V_103)( V_26 , V_52 , L_2 , V_59 ) ;
}
static struct V_70 * F_73 ( const struct V_25 * V_26 ,
const struct V_104 * V_105 ,
struct V_79 * V_3 )
{
struct V_10 * V_11 ;
struct V_70 * V_59 = NULL ;
F_14 ( V_105 == NULL ) ;
F_45 ( V_11 , V_102 , V_64 ) ;
if ( V_11 != NULL ) {
struct V_106 * V_105 = & V_11 -> V_107 ;
V_59 = & F_6 ( V_11 ) -> V_108 ;
F_74 ( V_105 ) ;
F_75 ( V_59 , & V_105 -> V_109 , V_3 ) ;
F_76 ( & V_105 -> V_109 , V_59 ) ;
V_11 -> V_12 . V_110 = & V_111 ;
V_59 -> V_112 = & V_113 ;
}
return V_59 ;
}
static int F_77 ( const struct V_25 * V_26 , struct V_1 * V_72 )
{
struct V_114 * V_115 = & V_72 -> V_116 ;
int V_117 ;
V_117 = F_78 ( V_115 , & V_72 -> V_4 ) ;
if ( V_117 ) {
F_79 ( L_3 , V_117 ) ;
return V_117 ;
}
V_117 = F_80 ( & V_115 -> V_118 ) ;
if ( V_117 )
return V_117 ;
V_72 -> V_119 = V_115 ;
return 0 ;
}
static void F_81 ( const struct V_25 * V_26 , struct V_1 * V_72 )
{
if ( V_72 -> V_119 ) {
if ( ! V_72 -> V_84 )
F_82 ( V_72 -> V_119 ) ;
V_72 -> V_119 = NULL ;
}
}
static void * F_83 ( const struct V_120 * V_121 ,
struct V_122 * V_123 )
{
struct V_24 * V_27 ;
F_45 ( V_27 , V_124 , V_64 ) ;
if ( V_27 == NULL )
V_27 = F_84 ( - V_68 ) ;
return V_27 ;
}
static void F_85 ( const struct V_120 * V_121 ,
struct V_122 * V_123 , void * V_125 )
{
struct V_24 * V_27 = V_125 ;
F_34 ( V_27 , V_124 ) ;
}
static void F_86 ( const struct V_120 * V_121 ,
struct V_122 * V_123 , void * V_125 )
{
}
static void * F_87 ( const struct V_120 * V_121 ,
struct V_122 * V_123 )
{
struct V_126 * V_127 ;
F_45 ( V_127 , V_128 , V_64 ) ;
if ( V_127 == NULL )
V_127 = F_84 ( - V_68 ) ;
return V_127 ;
}
static void F_88 ( const struct V_120 * V_121 ,
struct V_122 * V_123 , void * V_125 )
{
struct V_126 * V_127 = V_125 ;
F_34 ( V_127 , V_128 ) ;
}
static void F_89 ( const struct V_120 * V_121 ,
struct V_122 * V_123 , void * V_125 )
{
}
static int F_90 ( struct V_1 * V_72 , char * V_129 ,
struct V_130 * V_131 )
{
char * V_132 ;
int V_117 ;
F_91 ( V_72 -> V_133 ) ;
if ( V_72 -> V_133 == NULL )
return - V_68 ;
F_61 ( V_132 , V_134 + 5 ) ;
if ( V_132 == NULL )
GOTO ( V_135 , V_117 = - V_68 ) ;
snprintf ( V_132 , V_134 + 5 , L_4 , V_129 ) ;
V_117 = F_92 ( V_72 -> V_133 , NULL ,
V_136 ,
V_132 , V_131 -> V_137 ) ;
V_72 -> V_133 -> V_138 = V_139 ;
F_62 ( V_132 , V_134 + 5 ) ;
if ( V_117 )
GOTO ( V_135 , V_117 ) ;
return 0 ;
V_135:
F_93 ( V_72 -> V_133 ) ;
V_72 -> V_133 = NULL ;
return V_117 ;
}
static int F_94 ( struct V_6 * V_140 )
{
struct V_1 * V_72 = F_4 ( V_140 ) ;
if ( V_72 -> V_133 != NULL ) {
F_95 ( V_72 -> V_133 ) ;
F_93 ( V_72 -> V_133 ) ;
V_72 -> V_133 = NULL ;
}
return 0 ;
}
static struct V_79 * F_96 ( const struct V_25 * V_26 ,
struct V_141 * V_142 ,
struct V_143 * V_144 )
{
struct V_79 * V_145 ;
struct V_1 * V_72 ;
struct V_2 * V_146 ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_147 ;
const char * V_148 ;
int V_117 ;
int V_149 = 0 ;
F_91 ( V_72 ) ;
if ( V_72 == NULL )
GOTO ( V_150 , V_117 = - V_68 ) ;
V_149 = 1 ;
V_146 = & V_72 -> V_4 ;
V_117 = F_97 ( V_146 , V_142 ) ;
if ( V_117 )
GOTO ( V_150 , V_117 ) ;
V_146 -> V_151 . V_81 = & V_152 ;
V_146 -> V_153 = & V_154 ;
V_149 = 2 ;
V_7 = F_98 ( F_99 ( V_144 , 0 ) ) ;
F_14 ( V_7 != NULL ) ;
F_14 ( V_26 != NULL ) ;
V_147 = F_98 ( F_99 ( V_144 , 1 ) ) ;
if ( V_147 == NULL ) {
F_79 ( L_5 ,
F_99 ( V_144 , 1 ) ) ;
GOTO ( V_150 , V_117 = - V_155 ) ;
}
V_145 = V_147 -> V_8 ;
if ( ! strcmp ( V_147 -> V_156 -> V_157 , V_158 ) ) {
V_72 -> V_84 = 1 ;
} else {
V_72 -> V_84 = 0 ;
V_117 = F_77 ( V_26 , V_72 ) ;
if ( V_117 )
GOTO ( V_150 , V_117 ) ;
}
V_149 = 3 ;
V_117 = F_100 ( V_26 , V_7 , V_144 ) ;
if ( V_117 )
GOTO ( V_150 , V_117 ) ;
V_72 -> V_76 = & V_7 -> V_159 . V_160 ;
V_149 = 4 ;
if ( V_72 -> V_84 ) {
struct V_161 * V_162 ;
struct V_79 * V_163 ;
int V_164 = 0 ;
if ( V_145 == NULL ) {
F_79 ( L_6 ,
F_99 ( V_144 , 1 ) ) ;
GOTO ( V_150 , V_117 = - V_165 ) ;
}
V_148 = F_99 ( V_144 , 2 ) ;
if ( ! V_148 ) {
F_79 ( L_7 ,
F_99 ( V_144 , 1 ) ,
V_147 -> V_156 -> V_157 ) ;
GOTO ( V_150 , V_117 = - V_165 ) ;
}
V_162 = V_145 -> V_166 ;
F_55 ( & V_162 -> V_167 ) ;
F_101 (ld, &ls->ls_ld_linkage, ld_linkage) {
if ( strcmp ( V_163 -> V_168 -> V_169 , V_148 ) == 0 ) {
V_164 = 1 ;
break;
}
}
F_57 ( & V_162 -> V_167 ) ;
if ( V_164 == 0 ) {
F_79 ( L_6 ,
F_99 ( V_144 , 1 ) ) ;
GOTO ( V_150 , V_117 = - V_165 ) ;
}
V_145 = V_163 ;
V_72 -> V_116 . V_118 = * V_162 ;
V_72 -> V_119 = & V_72 -> V_116 ;
V_72 -> V_4 . V_151 . V_166 = & V_72 -> V_116 . V_118 ;
V_117 = F_90 ( V_72 , V_7 -> V_129 , F_102 ( V_162 ) ) ;
if ( V_117 ) {
F_79 ( L_8 , V_117 ) ;
GOTO ( V_150 , V_117 ) ;
}
} else {
if ( V_145 != NULL && ! F_103 ( V_145 ) )
V_145 = NULL ;
V_148 = V_147 -> V_156 -> V_157 ;
if ( V_145 != NULL ) {
F_14 ( V_145 != NULL ) ;
if ( V_145 -> V_166 != NULL )
GOTO ( V_150 , V_117 = - V_45 ) ;
V_145 -> V_166 = & V_72 -> V_119 -> V_118 ;
V_117 = V_145 -> V_168 -> V_170 -> V_171 ( V_26 , V_145 ,
V_145 -> V_168 -> V_169 ,
NULL ) ;
if ( V_117 )
GOTO ( V_150 , V_117 ) ;
if ( strcmp ( V_148 , V_172 ) == 0 )
V_72 -> V_173 = 1 ;
else
F_14 ( strcmp ( V_148 ,
V_174 ) == 0 ) ;
} else
F_14 ( strcmp ( V_148 , V_175 ) == 0 ) ;
}
V_72 -> V_77 = V_145 ;
return & V_146 -> V_151 ;
V_150:
switch( V_149 ) {
case 4 : {
int V_176 ;
V_176 = F_104 ( V_7 ) ;
if ( V_176 )
F_79 ( L_9 ,
V_7 -> V_129 , V_176 ) ;
}
case 3 :
F_81 ( V_26 , V_72 ) ;
case 2 :
F_105 ( & V_72 -> V_4 ) ;
case 1 :
F_93 ( V_72 ) ;
case 0 :
default:
break;
}
return ( F_84 ( V_117 ) ) ;
}
static int F_106 ( const struct V_25 * V_26 , struct V_79 * V_5 ,
const char * V_177 , struct V_79 * V_145 )
{
F_107 () ;
return 0 ;
}
static struct V_79 * F_108 ( const struct V_25 * V_26 ,
struct V_79 * V_5 )
{
struct V_1 * V_72 = F_1 ( F_5 ( V_5 ) ) ;
struct V_79 * V_145 = V_72 -> V_77 ;
while ( V_145 && ! V_72 -> V_84 )
V_145 = V_145 -> V_168 -> V_170 -> V_178 ( V_26 , V_145 ) ;
return NULL ;
}
static void F_109 ( const struct V_25 * V_26 ,
struct V_18 * V_22 ,
int V_179 )
{
struct V_21 * V_180 = F_11 ( V_22 ) ;
F_110 ( V_180 ) ;
F_111 ( V_26 , V_180 ) ;
F_112 ( V_26 , V_180 , L_10 , V_22 -> V_66 ) ;
if ( ! V_179 ) {
F_113 ( V_26 , V_180 ) ;
F_114 ( V_26 , V_180 ) ;
F_115 ( V_26 , V_180 ) ;
F_116 ( V_26 , V_180 ) ;
}
F_117 ( V_26 , V_180 ) ;
}
static struct V_79 * F_118 ( const struct V_25 * V_26 ,
struct V_79 * V_5 )
{
struct V_1 * V_72 = F_1 ( F_5 ( V_5 ) ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_10 * V_11 ;
struct V_79 * V_145 = V_72 -> V_77 ;
F_119 ( V_181 , L_11 ,
V_72 , V_145 ) ;
F_120 ( V_26 , & V_72 -> V_119 -> V_118 , - 1 ) ;
F_55 ( & V_75 -> V_90 ) ;
F_101 (eco, &ec->ec_objects, eo_obj_chain)
V_11 -> V_182 = 1 ;
F_57 ( & V_75 -> V_90 ) ;
F_120 ( V_26 , & V_72 -> V_119 -> V_118 , - 1 ) ;
F_119 ( V_181 ,
L_12 ) ;
F_55 ( & V_75 -> V_90 ) ;
while ( ! F_33 ( & V_75 -> V_92 ) ) {
F_57 ( & V_75 -> V_90 ) ;
F_79 ( L_13
L_14 ) ;
F_121 ( V_183 ) ;
F_122 ( F_123 ( 1 ) ) ;
F_120 ( V_26 , & V_72 -> V_119 -> V_118 , - 1 ) ;
F_55 ( & V_75 -> V_90 ) ;
}
F_57 ( & V_75 -> V_90 ) ;
F_14 ( F_33 ( & V_75 -> V_184 ) ) ;
F_119 ( V_181 , L_15 ) ;
F_104 ( V_5 -> V_185 ) ;
F_94 ( V_5 -> V_185 ) ;
while ( V_145 && ! V_72 -> V_84 )
V_145 = V_145 -> V_168 -> V_170 -> V_186 ( V_26 , V_145 ) ;
F_14 ( V_72 -> V_119 == F_124 ( V_5 -> V_166 ) ) ;
F_81 ( V_26 , V_72 ) ;
F_105 ( & V_72 -> V_4 ) ;
F_93 ( V_72 ) ;
return NULL ;
}
static struct V_10 * F_125 ( struct V_1 * V_5 ,
struct V_93 * * V_94 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_30 * V_69 ;
struct V_93 * V_187 ;
struct V_10 * V_11 ;
struct V_9 * V_59 ;
struct V_188 * V_189 ;
int V_190 ;
int V_117 ;
F_14 ( V_94 ) ;
V_187 = * V_94 ;
F_14 ( V_187 ) ;
F_126 ( F_127 ( & V_187 -> V_101 ) != 0 , V_191 L_16 , F_128 ( & V_187 -> V_101 ) ) ;
F_126 ( F_129 ( & V_187 -> V_101 ) == V_192 , V_191 L_16 ,
F_128 ( & V_187 -> V_101 ) ) ;
if ( F_3 ( V_5 ) -> V_151 . V_185 -> V_193 )
return F_84 ( - V_155 ) ;
V_26 = F_130 ( & V_190 ) ;
if ( F_131 ( V_26 ) )
return ( void * ) V_26 ;
V_27 = F_12 ( V_26 ) ;
V_69 = & V_27 -> V_194 ;
if ( V_5 -> V_77 ) {
if ( ! V_5 -> V_173 ) {
struct V_98 * V_195 = V_187 -> V_97 [ 0 ] ;
F_14 ( V_195 != NULL ) ;
V_195 -> V_196 = V_187 -> V_101 ;
V_69 -> V_33 . V_159 . V_197 = V_195 ;
} else {
struct V_198 * V_199 ;
V_199 = & V_27 -> V_200 ;
memset ( V_199 , 0 , sizeof( * V_199 ) ) ;
V_199 -> V_187 = V_187 ;
V_69 -> V_33 . V_159 . V_201 = V_199 ;
}
}
V_69 -> V_87 = V_94 ;
V_189 = & V_27 -> V_202 ;
V_117 = F_132 ( V_189 , & V_187 -> V_101 , 0 ) ;
if ( V_117 != 0 )
GOTO ( V_150 , V_11 = F_84 ( V_117 ) ) ;
V_59 = F_133 ( V_26 , F_3 ( V_5 ) , V_189 , & V_69 -> V_33 ) ;
if ( F_131 ( V_59 ) )
GOTO ( V_150 , V_11 = ( void * ) V_59 ) ;
V_11 = F_7 ( V_59 ) ;
if ( V_11 -> V_182 ) {
F_134 ( V_26 , V_59 ) ;
V_11 = F_84 ( - V_42 ) ;
}
V_150:
F_135 ( V_26 , & V_190 ) ;
return V_11 ;
}
static int F_136 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
int V_190 ;
V_26 = F_130 ( & V_190 ) ;
if ( F_131 ( V_26 ) )
return F_137 ( V_26 ) ;
if ( V_11 -> V_182 ) {
struct V_104 * V_203 = V_59 -> V_108 . V_83 ;
F_14 ( & V_11 -> V_107 == F_138 ( V_203 ) ) ;
F_139 ( V_204 , & V_203 -> V_205 ) ;
}
F_134 ( V_26 , V_59 ) ;
F_135 ( V_26 , & V_190 ) ;
return 0 ;
}
static int F_140 ( struct V_25 * V_26 , struct V_10 * V_11 ,
T_2 V_206 , T_2 V_207 , int V_208 ,
T_3 * V_52 , T_4 V_209 )
{
struct V_37 * V_38 ;
struct V_21 * V_210 ;
struct V_9 * V_59 ;
struct V_57 * V_211 ;
struct V_24 * V_27 ;
int V_117 = - V_68 ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_212 ;
V_211 = & V_27 -> V_213 ;
V_59 = F_6 ( V_11 ) ;
V_211 -> V_214 = V_59 ;
V_211 -> V_215 = F_141 ( V_59 , V_206 ) ;
V_211 -> V_216 = F_141 ( V_59 , V_207 ) ;
V_211 -> V_217 = V_208 == V_218 ? V_219 : V_220 ;
V_211 -> V_221 = V_209 ;
V_38 -> V_222 = V_59 ;
V_210 = F_142 ( V_26 , V_38 , V_211 , L_10 , V_11 ) ;
if ( V_210 ) {
struct V_74 * V_75 = V_11 -> V_89 -> V_76 ;
struct V_18 * V_63 ;
V_117 = F_143 ( V_26 , V_210 ) ;
if ( V_117 == 0 ) {
V_63 = F_10 ( F_144 ( V_210 , & V_223 ) ) ;
F_55 ( & V_75 -> V_90 ) ;
if ( F_33 ( & V_63 -> V_55 ) ) {
F_145 ( & V_63 -> V_55 , & V_75 -> V_184 ) ;
V_63 -> V_224 = ++ V_75 -> V_225 ;
}
F_42 ( & V_63 -> V_67 ) ;
* V_52 = V_63 -> V_224 ;
F_57 ( & V_75 -> V_90 ) ;
} else {
F_112 ( V_26 , V_210 , L_10 , V_226 ) ;
}
}
return V_117 ;
}
static int F_146 ( struct V_10 * V_11 , T_2 V_206 , T_2 V_207 ,
int V_208 , T_3 * V_52 )
{
struct V_24 * V_27 ;
struct V_25 * V_26 ;
struct V_37 * V_38 ;
int V_190 ;
int V_227 ;
V_26 = F_130 ( & V_190 ) ;
if ( F_131 ( V_26 ) )
return F_137 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_212 ;
V_38 -> V_228 = 1 ;
V_227 = F_147 ( V_26 , V_38 , V_229 , F_6 ( V_11 ) ) ;
if ( V_227 < 0 )
GOTO ( V_150 , V_227 ) ;
F_14 ( V_227 == 0 ) ;
V_227 = F_140 ( V_26 , V_11 , V_206 , V_207 , V_208 , V_52 , 0 ) ;
F_148 ( V_26 , V_38 ) ;
V_150:
F_135 ( V_26 , & V_190 ) ;
return V_227 ;
}
static int F_149 ( struct V_25 * V_26 , struct V_1 * V_72 ,
T_3 V_52 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_18 * V_22 = NULL ;
struct V_230 * V_63 ;
int V_164 = 0 , V_179 = 0 ;
F_14 ( V_75 != NULL ) ;
F_55 ( & V_75 -> V_90 ) ;
F_150 (el, &ec->ec_locks) {
V_22 = F_151 ( V_63 , struct V_18 , V_55 ) ;
F_119 ( V_181 , L_17 , V_22 , V_22 -> V_224 ) ;
V_164 = ( V_22 -> V_224 == V_52 ) ;
if ( V_164 ) {
if ( F_152 ( & V_22 -> V_67 ) )
F_69 ( & V_22 -> V_55 ) ;
else
V_179 = 1 ;
break;
}
}
F_57 ( & V_75 -> V_90 ) ;
if ( ! V_164 )
return - V_231 ;
F_109 ( V_26 , V_22 , V_179 ) ;
return 0 ;
}
static int F_153 ( struct V_1 * V_72 , T_3 V_52 )
{
struct V_25 * V_26 ;
int V_190 ;
int V_117 ;
V_26 = F_130 ( & V_190 ) ;
if ( F_131 ( V_26 ) )
return F_137 ( V_26 ) ;
V_117 = F_149 ( V_26 , V_72 , V_52 ) ;
F_135 ( V_26 , & V_190 ) ;
return V_117 ;
}
static int F_154 ( const struct V_25 * V_26 , struct V_37 * V_38 ,
enum V_232 V_43 , struct V_233 * V_234 )
{
struct V_60 * V_235 ;
struct V_60 * V_236 ;
int V_227 = 0 ;
F_155 (clp, temp, &queue->c2_qin) {
int V_117 ;
V_117 = F_156 ( V_26 , V_38 , V_235 , V_237 ) ;
if ( V_117 == 0 )
continue;
V_227 = V_227 ? : V_117 ;
}
return V_227 ;
}
static int F_157 ( struct V_10 * V_11 , int V_238 , T_2 V_239 ,
struct V_34 * * V_240 , int V_241 , int V_242 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
struct V_1 * V_72 = V_11 -> V_89 ;
struct V_233 * V_234 ;
struct V_37 * V_38 ;
struct V_60 * V_235 ;
struct V_243 V_244 = { 0 } ;
int V_245 = F_158 ( V_59 ) ;
int V_190 ;
int V_117 ;
int V_246 ;
F_14 ( ( V_239 & ~ V_247 ) == 0 ) ;
F_14 ( V_72 -> V_77 != NULL ) ;
V_26 = F_130 ( & V_190 ) ;
if ( F_131 ( V_26 ) )
return F_137 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_212 ;
V_234 = & V_27 -> V_248 ;
F_159 ( V_234 ) ;
V_38 -> V_228 = 1 ;
V_117 = F_147 ( V_26 , V_38 , V_229 , V_59 ) ;
if ( V_117 < 0 )
GOTO ( V_150 , V_117 ) ;
F_14 ( V_117 == 0 ) ;
V_117 = F_140 ( V_26 , V_11 , V_239 ,
V_239 + V_241 * V_249 - 1 ,
V_238 == V_250 ? V_251 : V_218 , & V_244 . V_52 ,
V_252 ) ;
if ( V_117 < 0 )
GOTO ( V_253 , V_117 ) ;
for ( V_246 = 0 ; V_246 < V_241 ; V_246 ++ ) {
F_14 ( V_240 [ V_246 ] ) ;
V_235 = F_160 ( V_26 , V_59 , F_141 ( V_59 , V_239 ) ,
V_240 [ V_246 ] , V_254 ) ;
if ( F_131 ( V_235 ) ) {
V_117 = F_137 ( V_235 ) ;
break;
}
F_14 ( V_235 -> V_255 == V_254 ) ;
V_117 = F_161 ( V_26 , V_38 , V_235 ) ;
if ( V_117 ) {
F_14 ( V_235 -> V_256 == V_257 ) ;
F_162 ( V_26 , V_235 ) ;
break;
}
F_163 ( V_234 , V_235 ) ;
F_162 ( V_26 , V_235 ) ;
F_164 ( V_26 , V_235 , 0 , V_245 ) ;
V_239 += V_245 ;
}
if ( V_117 == 0 ) {
enum V_232 V_258 = V_238 == V_250 ? V_259 : V_237 ;
V_242 = V_242 && ( V_258 == V_237 ) ;
if ( V_242 )
V_117 = F_154 ( V_26 , V_38 , V_258 , V_234 ) ;
else
V_117 = F_165 ( V_26 , V_38 , V_258 , V_234 , 0 ) ;
F_119 ( V_181 , L_18 ,
V_242 ? L_19 : L_20 , V_117 ) ;
}
F_149 ( V_26 , V_72 , V_244 . V_52 ) ;
V_253:
F_166 ( V_26 , V_38 , V_234 ) ;
F_167 ( V_26 , V_38 , V_234 ) ;
F_168 ( V_26 , V_234 ) ;
F_148 ( V_26 , V_38 ) ;
V_150:
F_135 ( V_26 , & V_190 ) ;
return V_117 ;
}
static int
F_169 ( struct V_93 * V_187 , void * V_260 , int V_261 )
{
struct V_93 * V_262 = V_260 ;
int V_263 , V_246 ;
V_263 = F_170 ( struct V_93 , V_97 [ V_187 -> V_264 ] ) ;
if ( V_263 > V_261 )
return ( - V_165 ) ;
if ( F_171 ( V_262 , V_187 , sizeof( * V_262 ) ) )
return ( - V_265 ) ;
for ( V_246 = 0 ; V_246 < V_187 -> V_264 ; V_246 ++ ) {
if ( F_171 ( V_262 -> V_97 [ V_246 ] , V_187 -> V_97 [ V_246 ] ,
sizeof( V_187 -> V_97 [ 0 ] ) ) )
return ( - V_265 ) ;
}
return 0 ;
}
static int
F_172 ( struct V_1 * V_72 , struct V_93 * V_187 ,
void * V_262 , int V_261 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
int V_246 ;
if ( V_261 < sizeof ( * V_187 ) )
return ( - V_165 ) ;
if ( F_173 ( V_187 , V_262 , sizeof ( * V_187 ) ) )
return ( - V_265 ) ;
if ( V_187 -> V_264 > V_75 -> V_266 ||
V_187 -> V_267 != V_268 ||
( V_187 -> V_269 & ( ~ V_247 ) ) != 0 ||
( ( T_3 ) V_187 -> V_269 * V_187 -> V_264 > ~ 0UL ) )
return ( - V_165 ) ;
for ( V_246 = 0 ; V_246 < V_187 -> V_264 ; V_246 ++ ) {
if ( F_173 ( V_187 -> V_97 [ V_246 ] ,
( (struct V_93 * ) V_262 ) -> \
V_97 [ V_246 ] ,
sizeof( V_187 -> V_97 [ 0 ] ) ) )
return ( - V_265 ) ;
}
return ( 0 ) ;
}
static inline void F_174 ( struct V_270 * V_271 , char * V_177 ,
T_3 V_272 )
{
sprintf ( V_177 , L_21 , V_272 ) ;
V_271 -> V_273 = V_177 ;
V_271 -> V_274 = strlen ( V_177 ) ;
}
static int F_175 ( const struct V_25 * V_26 , struct V_275 * V_13 ,
struct V_276 * V_277 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
int V_117 ;
F_14 ( V_277 -> V_278 > 0 ) ;
V_117 = F_176 ( V_26 , V_13 , & V_279 , V_280 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( V_27 -> V_281 < V_117 ) {
int V_282 = F_177 ( V_117 ) ;
if ( V_27 -> V_281 > 0 ) {
F_14 ( V_27 -> V_283 ) ;
F_178 ( V_27 -> V_283 ,
V_27 -> V_281 ) ;
V_27 -> V_283 = NULL ;
V_27 -> V_281 = 0 ;
}
F_179 ( V_27 -> V_283 , V_282 ) ;
if ( V_27 -> V_283 == NULL )
return - V_68 ;
V_27 -> V_281 = V_282 ;
}
F_14 ( V_27 -> V_281 >= V_117 ) ;
V_27 -> V_284 . V_285 = V_27 -> V_283 ;
V_27 -> V_284 . V_286 = V_27 -> V_281 ;
V_117 = F_176 ( V_26 , V_13 , & V_27 -> V_284 , V_280 ) ;
if ( V_117 < 0 )
return V_117 ;
V_277 -> V_287 |= V_288 ;
V_277 -> V_289 = V_27 -> V_283 ;
V_277 -> V_278 = V_117 ;
return 0 ;
}
int F_180 ( const struct V_25 * V_26 , struct V_275 * V_145 ,
struct V_276 * V_277 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_290 * V_291 = & V_27 -> V_284 ;
T_5 V_208 = F_181 ( & V_145 -> V_292 ) ;
int V_58 = V_277 -> V_293 ;
int V_117 = 0 , V_176 ;
V_277 -> V_287 = 0 ;
if ( V_58 & V_294 ) {
V_277 -> V_293 = V_294 ;
V_117 = F_182 ( V_26 , V_145 , V_277 ) ;
if ( V_117 )
GOTO ( V_150 , V_117 ) ;
V_277 -> V_287 |= V_294 ;
}
if ( V_58 & V_288 ) {
if ( F_183 ( V_208 ) || F_184 ( V_208 ) ) {
F_14 ( V_277 -> V_278 > 0 ) ;
V_291 -> V_285 = V_277 -> V_289 ;
V_291 -> V_286 = V_277 -> V_278 ;
V_176 = F_176 ( V_26 , V_145 , V_291 , V_280 ) ;
if ( V_176 > 0 ) {
V_277 -> V_278 = V_176 ;
V_277 -> V_287 |= V_288 ;
} else if ( V_176 == - V_46 ) {
V_277 -> V_278 = 0 ;
} else if ( V_176 == - V_295 ) {
V_176 = F_175 ( V_26 , V_145 , V_277 ) ;
if ( V_176 < 0 )
GOTO ( V_150 , V_117 = V_176 ) ;
} else {
GOTO ( V_150 , V_117 = V_176 ) ;
}
}
}
#ifdef F_185
if ( V_58 & V_296 && F_184 ( V_208 ) ) {
V_291 -> V_285 = V_277 -> V_297 ;
V_291 -> V_286 = V_277 -> V_298 ;
V_176 = F_176 ( V_26 , V_145 , V_291 , V_299 ) ;
if ( V_176 > 0 ) {
V_277 -> V_298 = V_176 ;
V_277 -> V_287 |= V_296 ;
} else if ( V_176 == - V_46 ) {
V_277 -> V_298 = 0 ;
} else {
GOTO ( V_150 , V_117 = V_176 ) ;
}
}
#endif
V_150:
V_277 -> V_293 = V_58 ;
F_119 ( V_300 , L_22 ,
V_117 , V_277 -> V_287 , V_277 -> V_289 ) ;
return V_117 ;
}
static int
F_186 ( const struct V_25 * V_26 , struct V_1 * V_72 ,
struct V_275 * V_301 , struct V_188 * V_189 ,
struct V_270 * V_271 , struct V_302 * V_303 ,
struct V_276 * V_277 )
{
struct V_70 * V_304 , * V_305 ;
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_188 * V_306 = & V_27 -> V_307 ;
struct V_71 V_69 = { . V_308 = V_309 } ;
int V_117 ;
V_117 = F_187 ( V_26 , V_301 , V_271 , V_306 , V_303 ) ;
if ( V_117 == 0 )
return - V_310 ;
else if ( V_117 != - V_231 )
return V_117 ;
V_304 = F_188 ( V_26 , & V_72 -> V_4 . V_151 ,
V_189 , & V_69 ) ;
if ( F_131 ( V_304 ) ) {
F_79 ( L_23 V_311 L_24 , F_189 ( V_189 ) ,
F_137 ( V_304 ) ) ;
return F_137 ( V_304 ) ;
}
V_305 = F_190 ( V_304 -> V_83 , V_163 -> V_168 ) ;
if ( V_305 == NULL ) {
F_79 ( L_25 V_311 L_16 , F_189 ( V_189 ) ) ;
GOTO ( V_312 , V_117 = - V_165 ) ;
}
F_119 ( V_313 , L_26 V_311 L_27 ,
F_189 ( F_191 ( & V_301 -> V_292 ) ) , V_271 -> V_273 , V_301 ) ;
V_303 -> V_314 = 0 ;
V_117 = F_192 ( V_26 , V_301 , V_271 , F_193 ( V_305 ) , V_303 , V_277 ) ;
if ( V_117 ) {
F_79 ( L_28 V_311 L_29 , F_189 ( V_189 ) , V_117 ) ;
GOTO ( V_312 , V_117 ) ;
}
F_119 ( V_313 , L_30 V_311 L_31 ,
F_189 ( F_191 ( & V_301 -> V_292 ) ) , V_271 -> V_273 , V_301 , V_117 ) ;
V_312:
F_194 ( V_26 , V_304 ) ;
return V_117 ;
}
static int F_195 ( const struct V_25 * V_26 , struct V_79 * V_163 ,
struct V_276 * V_277 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
if ( strcmp ( V_163 -> V_168 -> V_169 , V_315 ) ) {
V_277 -> V_289 = ( void * ) & V_27 -> V_316 ;
V_277 -> V_278 = sizeof( V_27 -> V_316 ) ;
} else {
F_14 ( V_27 -> V_281 ) ;
V_277 -> V_289 = V_27 -> V_283 ;
V_277 -> V_278 = V_27 -> V_281 ;
}
return 0 ;
}
static int F_196 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_317 ,
struct V_188 * V_189 ,
char * V_177 , int V_318 ,
T_3 V_272 , T_4 V_208 , int V_319 ,
int V_320 , int V_321 )
{
struct V_70 * V_301 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_270 * V_271 = & V_27 -> V_322 ;
struct V_302 * V_303 = & V_27 -> V_323 ;
struct V_276 * V_277 = & V_27 -> V_324 ;
struct V_79 * V_163 = V_72 -> V_77 ;
int V_117 = 0 ;
int V_246 ;
if ( V_317 == NULL )
return - 1 ;
V_301 = F_190 ( V_317 -> V_83 , V_163 -> V_168 ) ;
if ( V_301 == NULL )
return - V_325 ;
memset ( V_277 , 0 , sizeof( * V_277 ) ) ;
memset ( V_303 , 0 , sizeof( * V_303 ) ) ;
if ( V_320 != 0 ) {
V_303 -> V_326 |= V_327 ;
F_195 ( V_26 , V_163 , V_277 ) ;
if ( V_320 != - 1 ) {
struct V_328 * V_329 = & V_27 -> V_330 ;
V_329 -> V_331 = V_332 ;
V_329 -> V_333 = V_320 ;
V_329 -> V_334 = V_321 ;
V_329 -> V_335 = 0 ;
V_303 -> V_159 . V_336 . V_337 = V_329 ;
V_303 -> V_159 . V_336 . V_338 = sizeof( * V_329 ) ;
V_303 -> V_326 |= V_339 ;
}
}
V_277 -> V_340 . V_341 = V_208 ;
V_277 -> V_340 . V_342 = V_343 | V_344 ;
V_277 -> V_340 . V_345 = F_197 () ;
if ( V_177 != NULL ) {
V_271 -> V_273 = V_177 ;
V_271 -> V_274 = V_318 ;
V_117 = F_186 ( V_26 , V_72 , F_193 ( V_301 ) , V_189 , V_271 ,
V_303 , V_277 ) ;
return V_117 ;
}
for ( V_246 = 0 ; V_246 < V_319 ; V_246 ++ ) {
char * V_346 = V_27 -> V_347 ;
F_174 ( V_271 , V_346 , V_272 ) ;
V_117 = F_186 ( V_26 , V_72 , F_193 ( V_301 ) , V_189 , V_271 ,
V_303 , V_277 ) ;
if ( V_117 ) {
F_79 ( L_32 , V_346 ,
V_117 ) ;
break;
}
V_272 ++ ;
V_189 -> V_348 ++ ;
}
return V_117 ;
}
static struct V_70 * F_198 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_275 * V_301 ,
struct V_270 * V_271 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_188 * V_189 = & V_27 -> V_202 ;
struct V_70 * V_305 ;
int V_117 ;
F_119 ( V_181 , L_33 V_311 L_34 , V_271 -> V_273 ,
F_189 ( V_189 ) , V_301 ) ;
V_117 = F_187 ( V_26 , V_301 , V_271 , V_189 , NULL ) ;
if ( V_117 ) {
F_79 ( L_35 , V_271 -> V_273 , V_117 ) ;
return F_84 ( V_117 ) ;
}
V_305 = F_188 ( V_26 , & V_72 -> V_4 . V_151 , V_189 , NULL ) ;
return V_305 ;
}
static int F_199 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_317 ,
T_3 V_272 , int V_319 )
{
struct V_70 * V_301 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_270 * V_271 = & V_27 -> V_322 ;
char * V_177 = V_27 -> V_347 ;
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_290 * V_291 = & V_27 -> V_284 ;
int V_117 = 0 ;
int V_246 ;
if ( V_317 == NULL )
return - 1 ;
V_301 = F_190 ( V_317 -> V_83 , V_163 -> V_168 ) ;
if ( V_301 == NULL )
return - V_325 ;
for ( V_246 = 0 ; V_246 < V_319 ; V_246 ++ ) {
struct V_70 * V_304 , * V_305 ;
F_174 ( V_271 , V_177 , V_272 ) ;
V_304 = F_198 ( V_26 , V_72 , F_193 ( V_301 ) , V_271 ) ;
if ( F_131 ( V_304 ) ) {
F_79 ( L_36 ,
V_271 -> V_273 , F_137 ( V_304 ) ) ;
return F_137 ( V_304 ) ;
}
V_305 = F_190 ( V_304 -> V_83 , V_163 -> V_168 ) ;
if ( V_305 == NULL ) {
F_79 ( L_37 , V_271 -> V_273 ) ;
F_194 ( V_26 , V_304 ) ;
V_117 = - V_165 ;
break;
}
F_119 ( V_313 , L_38 V_311 L_16 ,
F_189 ( F_191 ( V_305 ) ) ) ;
V_291 -> V_285 = V_27 -> V_349 ;
V_291 -> V_286 = sizeof( V_27 -> V_349 ) ;
sprintf ( V_177 , L_39 , V_350 ) ;
V_117 = F_200 ( V_26 , F_193 ( V_305 ) , V_291 , V_177 ,
V_351 ) ;
if ( V_117 < 0 ) {
F_79 ( L_40 V_311 L_29 ,
F_189 ( F_191 ( V_305 ) ) , V_117 ) ;
F_194 ( V_26 , V_304 ) ;
break;
}
F_119 ( V_313 , L_41 V_311 L_16 ,
F_189 ( F_191 ( V_305 ) ) ) ;
V_272 ++ ;
F_194 ( V_26 , V_304 ) ;
}
return V_117 ;
}
static int F_201 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_317 ,
T_3 V_272 , int V_319 )
{
struct V_70 * V_301 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_270 * V_271 = & V_27 -> V_322 ;
char * V_177 = V_27 -> V_347 ;
struct V_276 * V_277 = & V_27 -> V_324 ;
struct V_79 * V_163 = V_72 -> V_77 ;
int V_117 = 0 ;
int V_246 ;
if ( V_317 == NULL )
return - 1 ;
V_301 = F_190 ( V_317 -> V_83 , V_163 -> V_168 ) ;
if ( V_301 == NULL )
return - V_325 ;
memset ( V_277 , 0 , sizeof( * V_277 ) ) ;
V_277 -> V_293 |= V_294 | V_288 | V_352 | V_353 | V_296 ;
V_277 -> V_297 = V_27 -> V_349 ;
V_277 -> V_298 = sizeof( V_27 -> V_349 ) ;
for ( V_246 = 0 ; V_246 < V_319 ; V_246 ++ ) {
struct V_70 * V_304 , * V_305 ;
V_277 -> V_287 = 0 ;
F_174 ( V_271 , V_177 , V_272 ) ;
F_195 ( V_26 , V_163 , V_277 ) ;
V_304 = F_198 ( V_26 , V_72 , F_193 ( V_301 ) , V_271 ) ;
if ( F_131 ( V_304 ) ) {
F_79 ( L_36 ,
V_271 -> V_273 , F_137 ( V_304 ) ) ;
return F_137 ( V_304 ) ;
}
V_305 = F_190 ( V_304 -> V_83 , V_163 -> V_168 ) ;
if ( V_305 == NULL ) {
F_79 ( L_37 , V_271 -> V_273 ) ;
F_194 ( V_26 , V_304 ) ;
return - V_165 ;
}
F_119 ( V_313 , L_42 V_311 L_16 ,
F_189 ( F_191 ( V_305 ) ) ) ;
V_117 = F_180 ( V_26 , F_193 ( V_305 ) , V_277 ) ;
if ( V_117 ) {
F_79 ( L_43 V_311 L_29 ,
F_189 ( F_191 ( V_305 ) ) , V_117 ) ;
F_194 ( V_26 , V_304 ) ;
break;
}
F_119 ( V_313 , L_44 V_311 L_16 ,
F_189 ( F_191 ( V_305 ) ) ) ;
V_272 ++ ;
F_194 ( V_26 , V_304 ) ;
}
return V_117 ;
}
static int F_202 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_317 ,
T_3 V_272 , int V_319 )
{
struct V_70 * V_301 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_270 * V_271 = & V_27 -> V_322 ;
char * V_177 = V_27 -> V_347 ;
struct V_188 * V_189 = & V_27 -> V_202 ;
struct V_79 * V_163 = V_72 -> V_77 ;
int V_117 = 0 ;
int V_246 ;
if ( V_317 == NULL )
return - 1 ;
V_301 = F_190 ( V_317 -> V_83 , V_163 -> V_168 ) ;
if ( V_301 == NULL )
return - V_325 ;
for ( V_246 = 0 ; V_246 < V_319 ; V_246 ++ ) {
F_174 ( V_271 , V_177 , V_272 ) ;
F_119 ( V_313 , L_45 V_311 L_27 ,
F_189 ( F_191 ( V_301 ) ) , V_271 -> V_273 , V_301 ) ;
V_117 = F_187 ( V_26 , F_193 ( V_301 ) , V_271 , V_189 , NULL ) ;
if ( V_117 ) {
F_79 ( L_46 , V_177 , V_117 ) ;
break;
}
F_119 ( V_313 , L_47 V_311 L_27 ,
F_189 ( F_191 ( V_301 ) ) , V_271 -> V_273 , V_301 ) ;
V_272 ++ ;
}
return V_117 ;
}
static int F_203 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_275 * V_301 ,
struct V_270 * V_271 ,
struct V_276 * V_277 )
{
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_70 * V_304 ;
struct V_70 * V_305 ;
int V_117 ;
V_304 = F_198 ( V_26 , V_72 , V_301 , V_271 ) ;
if ( F_131 ( V_304 ) ) {
F_79 ( L_36 , V_271 -> V_273 ,
F_137 ( V_304 ) ) ;
return F_137 ( V_304 ) ;
}
V_305 = F_190 ( V_304 -> V_83 , V_163 -> V_168 ) ;
if ( V_305 == NULL ) {
F_79 ( L_37 , V_271 -> V_273 ) ;
GOTO ( V_312 , V_117 = - V_165 ) ;
}
F_119 ( V_313 , L_48 V_311 L_27 ,
F_189 ( F_191 ( & V_301 -> V_292 ) ) , V_271 -> V_273 , V_301 ) ;
V_117 = F_204 ( V_26 , V_301 , F_193 ( V_305 ) , V_271 , V_277 , 0 ) ;
if ( V_117 ) {
F_79 ( L_49 ,
V_271 -> V_273 , V_117 ) ;
GOTO ( V_312 , V_117 ) ;
}
F_119 ( V_313 , L_50 V_311 L_27 ,
F_189 ( F_191 ( & V_301 -> V_292 ) ) , V_271 -> V_273 , V_301 ) ;
V_312:
F_194 ( V_26 , V_304 ) ;
return V_117 ;
}
static int F_205 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_317 ,
char * V_177 , int V_318 ,
T_3 V_272 , T_4 V_208 ,
int V_319 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_270 * V_271 = & V_27 -> V_322 ;
struct V_276 * V_277 = & V_27 -> V_324 ;
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_70 * V_301 ;
int V_117 = 0 ;
int V_246 ;
V_301 = F_190 ( V_317 -> V_83 , V_163 -> V_168 ) ;
if ( V_301 == NULL )
return - V_165 ;
memset ( V_277 , 0 , sizeof( * V_277 ) ) ;
V_277 -> V_340 . V_341 = V_208 ;
V_277 -> V_340 . V_342 = V_343 ;
V_277 -> V_340 . V_345 = F_197 () ;
V_277 -> V_293 = V_294 ;
V_277 -> V_287 = 0 ;
if ( V_177 != NULL ) {
V_271 -> V_273 = V_177 ;
V_271 -> V_274 = V_318 ;
V_117 = F_203 ( V_26 , V_72 , F_193 ( V_301 ) , V_271 ,
V_277 ) ;
return V_117 ;
}
for ( V_246 = 0 ; V_246 < V_319 ; V_246 ++ ) {
char * V_346 = V_27 -> V_347 ;
V_277 -> V_287 = 0 ;
F_174 ( V_271 , V_346 , V_272 ) ;
V_117 = F_203 ( V_26 , V_72 , F_193 ( V_301 ) , V_271 ,
V_277 ) ;
if ( V_117 ) {
F_79 ( L_49 , V_177 , V_117 ) ;
break;
}
V_272 ++ ;
}
return V_117 ;
}
static struct V_70 * F_206 ( const struct V_25 * V_26 ,
struct V_1 * V_72 , char * V_354 ,
int V_355 )
{
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_356 * V_199 = F_207 ( V_163 ) ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_188 * V_189 = & V_27 -> V_202 ;
struct V_270 * V_271 = & V_27 -> V_322 ;
struct V_70 * V_301 = NULL ;
struct V_70 * V_305 = NULL ;
int V_117 = 0 ;
V_117 = V_199 -> V_357 -> V_358 ( V_26 , V_199 , V_189 ) ;
if ( V_117 ) {
F_79 ( L_51 , V_117 ) ;
return F_84 ( V_117 ) ;
}
V_301 = F_188 ( V_26 , & V_72 -> V_4 . V_151 , V_189 , NULL ) ;
if ( F_131 ( V_301 ) ) {
F_79 ( L_52 V_311 L_24 ,
F_189 ( V_189 ) , F_137 ( V_301 ) ) ;
return V_301 ;
}
while ( 1 ) {
struct V_70 * V_359 ;
char * V_360 ;
V_360 = F_208 ( & V_354 , L_53 ) ;
if ( V_360 == NULL )
break;
if ( V_360 [ 0 ] == 0 ) {
if ( ! V_354 || V_354 [ 0 ] == '\0' )
break;
continue;
}
V_271 -> V_273 = V_360 ;
V_271 -> V_274 = strlen ( V_360 ) ;
V_359 = F_190 ( V_301 -> V_83 , V_163 -> V_168 ) ;
if ( V_359 == NULL ) {
F_194 ( V_26 , V_301 ) ;
V_117 = - V_165 ;
break;
}
V_305 = F_198 ( V_26 , V_72 , F_193 ( V_359 ) , V_271 ) ;
F_194 ( V_26 , V_301 ) ;
if ( F_131 ( V_305 ) ) {
V_117 = ( int ) F_137 ( V_305 ) ;
F_79 ( L_54 V_311 L_29 ,
V_271 -> V_273 , F_189 ( F_191 ( V_359 ) ) ,
V_117 ) ;
break;
}
V_301 = V_305 ;
}
if ( V_117 )
return F_84 ( V_117 ) ;
return V_301 ;
}
static void F_209 ( struct V_25 * V_26 )
{
struct V_361 * V_362 = V_361 ( V_26 ) ;
V_362 -> V_363 = V_364 ;
V_362 -> V_365 [ 0 ] = - 1 ;
V_362 -> V_365 [ 1 ] = - 1 ;
V_362 -> V_366 = V_362 -> V_367 =
F_210 ( & V_368 , F_211 () ) ;
V_362 -> V_369 = V_362 -> V_370 =
F_212 ( & V_368 , F_213 () ) ;
V_362 -> V_371 = V_362 -> V_372 =
F_210 ( & V_368 , F_214 () ) ;
V_362 -> V_373 = V_362 -> V_374 =
F_212 ( & V_368 , F_215 () ) ;
V_362 -> V_375 = F_216 () ;
if ( V_362 -> V_371 )
V_362 -> V_375 &= ~ V_376 ;
V_362 -> V_363 = V_377 ;
}
static void F_217 ( struct V_25 * V_26 )
{
struct V_361 * V_362 = V_361 ( V_26 ) ;
V_362 -> V_363 = V_378 ;
}
static int F_218 ( struct V_1 * V_72 , int V_379 ,
char * V_354 , int V_355 , T_3 V_272 , int V_319 ,
struct V_380 * V_125 )
{
struct V_24 * V_27 ;
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_25 * V_26 ;
int V_190 ;
struct V_70 * V_301 ;
char * V_177 = NULL ;
int V_318 = V_125 -> V_381 ;
int V_117 = 0 ;
if ( V_163 == NULL ) {
F_79 ( L_55 ) ;
return - V_165 ;
}
if ( strcmp ( V_163 -> V_168 -> V_169 , V_315 ) ) {
F_79 ( L_56 ) ;
return - V_165 ;
}
V_26 = F_130 ( & V_190 ) ;
if ( F_131 ( V_26 ) )
return F_137 ( V_26 ) ;
V_117 = F_219 ( V_26 , V_382 , V_383 ) ;
if ( V_117 != 0 )
GOTO ( V_384 , V_117 ) ;
V_27 = F_12 ( V_26 ) ;
F_14 ( V_27 -> V_283 == NULL ) ;
F_179 ( V_27 -> V_283 , V_385 ) ;
if ( V_27 -> V_283 == NULL )
GOTO ( V_384 , V_117 = - V_68 ) ;
V_27 -> V_281 = V_385 ;
V_301 = F_206 ( V_26 , V_72 , V_354 , V_355 ) ;
if ( F_131 ( V_301 ) ) {
F_79 ( L_57 , V_354 ,
F_137 ( V_301 ) ) ;
GOTO ( V_386 , V_117 = F_137 ( V_301 ) ) ;
}
if ( V_318 > 0 ) {
F_61 ( V_177 , V_318 + 1 ) ;
if ( V_177 == NULL )
GOTO ( V_312 , V_117 = - V_68 ) ;
if ( F_173 ( V_177 , V_125 -> V_387 , V_318 ) )
GOTO ( V_388 , V_117 = - V_265 ) ;
}
F_209 ( V_26 ) ;
switch ( V_379 ) {
case V_389 :
case V_390 : {
struct V_24 * V_27 = F_12 ( V_26 ) ;
T_4 V_208 = V_125 -> V_391 . V_392 ;
struct V_188 * V_189 = & V_27 -> V_202 ;
int V_320 = ( int ) V_125 -> V_391 . V_393 ;
int V_394 = ( int ) V_125 -> V_391 . V_395 ;
V_117 = F_132 ( V_189 , & V_125 -> V_396 . V_397 , 0 ) ;
if ( V_117 != 0 )
break;
V_117 = F_196 ( V_26 , V_72 , V_301 , V_189 , V_177 , V_318 ,
V_272 , V_208 , V_319 , V_320 ,
V_394 ) ;
break;
}
case V_398 :
case V_399 : {
T_4 V_208 = V_125 -> V_391 . V_392 ;
V_117 = F_205 ( V_26 , V_72 , V_301 , V_177 , V_318 ,
V_272 , V_208 , V_319 ) ;
break;
}
case V_400 :
V_117 = F_202 ( V_26 , V_72 , V_301 , V_272 , V_319 ) ;
break;
case V_401 :
V_117 = F_201 ( V_26 , V_72 , V_301 , V_272 , V_319 ) ;
break;
case V_402 :
V_117 = F_199 ( V_26 , V_72 , V_301 , V_272 , V_319 ) ;
break;
default:
F_79 ( L_58 , V_379 ) ;
V_117 = - V_165 ;
break;
}
F_217 ( V_26 ) ;
V_388:
if ( V_177 != NULL )
F_62 ( V_177 , V_318 + 1 ) ;
V_312:
F_194 ( V_26 , V_301 ) ;
V_386:
F_14 ( V_27 -> V_283 ) ;
F_178 ( V_27 -> V_283 , V_27 -> V_281 ) ;
V_27 -> V_283 = NULL ;
V_27 -> V_281 = 0 ;
V_384:
F_135 ( V_26 , & V_190 ) ;
return V_117 ;
}
static int F_220 ( const struct V_25 * V_26 , struct V_1 * V_72 ,
int V_403 , struct V_404 * V_405 , void * V_262 ,
int V_261 , struct V_406 * V_407 )
{
struct V_10 * V_11 ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_93 * V_187 = NULL ;
int V_117 ;
int V_408 = 0 ;
if ( ( V_405 -> V_409 & V_410 ) == 0 &&
( V_403 ||
V_75 -> V_266 != 0 ) ) {
F_79 ( L_59 ) ;
return - V_165 ;
}
V_117 = F_58 ( V_72 , & V_187 ) ;
if ( V_117 < 0 ) {
F_79 ( L_60 , V_117 ) ;
GOTO ( V_411 , V_117 ) ;
}
if ( V_262 != NULL ) {
int V_246 , V_412 ;
V_117 = F_172 ( V_72 , V_187 , V_262 , V_261 ) ;
if ( V_117 != 0 )
GOTO ( V_411 , V_117 ) ;
if ( V_187 -> V_264 == 0 )
V_187 -> V_264 = V_75 -> V_266 ;
if ( V_187 -> V_269 == 0 )
V_187 -> V_269 = V_249 ;
V_412 = F_221 () ;
for ( V_246 = 0 ; V_246 < V_187 -> V_264 ; V_246 ++ ) {
if ( F_127 ( & V_187 -> V_97 [ V_246 ] -> V_196 ) == 0 )
V_187 -> V_97 [ V_246 ] -> V_196 = V_187 -> V_101 ;
V_187 -> V_97 [ V_246 ] -> V_413 =
( V_412 + V_246 ) % V_75 -> V_266 ;
}
}
if ( V_405 -> V_409 & V_410 ) {
F_14 ( V_405 -> V_409 & V_414 ) ;
V_187 -> V_101 = V_405 -> V_397 ;
}
if ( F_127 ( & V_187 -> V_101 ) == 0 )
F_222 ( & V_187 -> V_101 , ++ V_415 ) ;
V_117 = 0 ;
if ( V_403 ) {
F_14 ( ( V_405 -> V_409 & V_414 ) &&
( F_129 ( & V_405 -> V_397 ) == V_192 ) ) ;
V_117 = F_223 ( V_26 , V_75 -> V_96 , V_405 , & V_187 , V_407 ) ;
if ( V_117 != 0 ) {
F_79 ( L_61 , V_117 ) ;
GOTO ( V_411 , V_117 ) ;
}
V_408 = 1 ;
}
V_405 -> V_397 = V_187 -> V_101 ;
V_405 -> V_409 |= V_410 ;
V_11 = F_125 ( V_72 , & V_187 ) ;
if ( F_131 ( V_11 ) )
GOTO ( V_411 , V_117 = F_137 ( V_11 ) ) ;
F_136 ( V_11 ) ;
F_119 ( V_181 , L_62 V_191 L_16 , F_128 ( & V_405 -> V_397 ) ) ;
V_411:
if ( V_408 && V_117 )
F_224 ( V_26 , V_75 -> V_96 , V_405 , V_187 , V_407 , NULL , NULL ) ;
if ( V_187 )
F_65 ( V_72 , & V_187 ) ;
if ( V_117 )
F_79 ( L_63 , V_117 ) ;
return ( V_117 ) ;
}
static int F_225 ( struct V_10 * * V_416 , struct V_1 * V_72 ,
struct V_404 * V_405 )
{
struct V_93 * V_187 = NULL ;
struct V_10 * V_11 ;
int V_117 ;
if ( ( V_405 -> V_409 & V_410 ) == 0 || F_127 ( & V_405 -> V_397 ) == 0 ) {
F_79 ( L_59 ) ;
return - V_165 ;
}
V_117 = F_58 ( V_72 , & V_187 ) ;
if ( V_117 < 0 )
return V_117 ;
V_187 -> V_101 = V_405 -> V_397 ;
if ( ! ( V_405 -> V_409 & V_414 ) )
F_64 ( & V_187 -> V_101 ) ;
V_117 = 0 ;
V_11 = F_125 ( V_72 , & V_187 ) ;
if ( ! F_131 ( V_11 ) )
* V_416 = V_11 ;
else
V_117 = F_137 ( V_11 ) ;
if ( V_187 )
F_65 ( V_72 , & V_187 ) ;
return V_117 ;
}
static void F_226 ( struct V_10 * V_11 )
{
if ( F_136 ( V_11 ) )
F_79 ( L_64 ) ;
}
static void
F_227 ( struct V_93 * V_187 , T_2 * V_417 , T_6 * V_418 )
{
unsigned long V_320 ;
unsigned long V_419 ;
unsigned long V_420 ;
unsigned long V_421 ;
int V_394 ;
T_2 V_239 ;
if ( V_187 -> V_264 <= 1 )
return;
V_239 = * V_417 ;
V_419 = V_187 -> V_269 ;
V_320 = V_187 -> V_264 ;
V_420 = V_419 * V_320 ;
V_421 = F_228 ( V_239 , V_420 ) ;
V_394 = V_421 / V_419 ;
* V_418 = F_127 ( & V_187 -> V_97 [ V_394 ] -> V_196 ) ;
* V_417 = V_239 * V_419 + V_421 % V_419 ;
}
static void
F_229 ( struct V_93 * V_187 ,
struct V_34 * V_34 , int V_238 , T_6 V_272 ,
T_2 V_239 , T_2 V_319 )
{
char * V_422 ;
T_2 V_423 ;
T_6 V_424 ;
int V_425 ;
F_14 ( V_319 == V_249 ) ;
V_422 = F_230 ( V_34 ) ;
for ( V_425 = 0 ; V_425 < V_249 ; V_425 += V_426 ) {
if ( V_238 == V_427 ) {
V_423 = V_239 + V_425 ;
V_424 = V_272 ;
F_227 ( V_187 , & V_423 , & V_424 ) ;
} else {
V_423 = 0xdeadbeef00c0ffeeULL ;
V_424 = 0xdeadbeef00c0ffeeULL ;
}
F_231 ( V_422 + V_425 , V_426 ,
V_423 , V_424 ) ;
}
F_232 ( V_34 ) ;
}
static int F_233 ( struct V_93 * V_187 ,
struct V_34 * V_34 , T_6 V_272 ,
T_2 V_239 , T_2 V_319 )
{
T_2 V_423 ;
T_6 V_424 ;
char * V_422 ;
int V_425 ;
int V_117 ;
int V_176 ;
F_14 ( V_319 == V_249 ) ;
V_422 = F_230 ( V_34 ) ;
for ( V_117 = V_425 = 0 ; V_425 < V_249 ; V_425 += V_426 ) {
V_423 = V_239 + V_425 ;
V_424 = V_272 ;
F_227 ( V_187 , & V_423 , & V_424 ) ;
V_176 = F_234 ( L_65 ,
V_422 + V_425 , V_426 ,
V_423 , V_424 ) ;
if ( V_176 != 0 ) {
F_79 ( L_66 , V_272 ) ;
V_117 = V_176 ;
}
}
F_232 ( V_34 ) ;
return V_117 ;
}
static int F_235 ( struct V_1 * V_72 , int V_238 , struct V_404 * V_405 ,
struct V_10 * V_11 , T_2 V_239 ,
T_7 V_319 , int V_242 ,
struct V_406 * V_407 )
{
struct V_93 * V_187 = V_11 -> V_88 ;
T_8 V_241 ;
struct V_428 * V_429 ;
struct V_428 * V_430 ;
struct V_34 * * V_240 ;
T_2 V_431 ;
int V_246 ;
int V_117 ;
int V_432 ;
T_9 V_433 ;
int V_434 = 0 ;
V_432 = ( F_127 ( & V_405 -> V_397 ) != V_435 &&
( V_405 -> V_409 & V_436 ) != 0 &&
( V_405 -> V_437 & V_438 ) != 0 ) ;
V_433 = ( ( F_127 ( & V_405 -> V_397 ) & 2 ) == 0 ) ? V_439 : V_440 ;
F_14 ( V_238 == V_427 || V_238 == V_441 ) ;
F_14 ( V_187 != NULL ) ;
F_14 ( F_127 ( & V_187 -> V_101 ) == F_127 ( & V_405 -> V_397 ) ) ;
if ( V_319 <= 0 ||
( V_319 & ( ~ V_247 ) ) != 0 )
return - V_165 ;
V_241 = V_319 >> V_442 ;
if ( V_238 == V_427 )
V_434 = V_443 ;
F_61 ( V_429 , V_241 * sizeof( * V_429 ) ) ;
if ( V_429 == NULL )
return - V_68 ;
F_61 ( V_240 , V_241 * sizeof( * V_240 ) ) ;
if ( V_240 == NULL ) {
F_62 ( V_429 , V_241 * sizeof( * V_429 ) ) ;
return - V_68 ;
}
for ( V_246 = 0 , V_430 = V_429 , V_431 = V_239 ;
V_246 < V_241 ;
V_246 ++ , V_430 ++ , V_431 += V_249 ) {
F_14 ( V_430 -> V_444 == NULL ) ;
V_117 = - V_68 ;
F_236 ( V_430 -> V_444 , V_433 ) ;
if ( V_430 -> V_444 == NULL )
goto V_150;
V_240 [ V_246 ] = V_430 -> V_444 ;
V_430 -> V_319 = V_249 ;
V_430 -> V_431 = V_431 ;
V_430 -> V_445 = V_434 ;
if ( V_432 )
F_229 ( V_187 , V_430 -> V_444 , V_238 ,
F_127 ( & V_405 -> V_397 ) , V_431 ,
V_430 -> V_319 ) ;
}
F_14 ( V_72 -> V_77 != NULL ) ;
V_117 = F_157 ( V_11 , V_238 , V_239 , V_240 , V_241 , V_242 ) ;
V_150:
if ( V_117 != 0 || V_238 != V_441 )
V_432 = 0 ;
for ( V_246 = 0 , V_430 = V_429 ; V_246 < V_241 ; V_246 ++ , V_430 ++ ) {
if ( V_430 -> V_444 == NULL )
continue;
if ( V_432 ) {
int V_446 ;
V_446 = F_233 ( V_187 , V_430 -> V_444 ,
F_127 ( & V_405 -> V_397 ) ,
V_430 -> V_431 , V_430 -> V_319 ) ;
if ( V_446 != 0 && V_117 == 0 )
V_117 = V_446 ;
}
F_237 ( V_430 -> V_444 ) ;
}
F_62 ( V_429 , V_241 * sizeof( * V_429 ) ) ;
F_62 ( V_240 , V_241 * sizeof( * V_240 ) ) ;
return V_117 ;
}
static int F_238 ( const struct V_25 * V_26 ,
struct V_447 * exp , int V_238 ,
struct V_404 * V_405 , struct V_10 * V_11 ,
T_2 V_239 , T_7 V_319 ,
T_7 V_448 , struct V_406 * V_407 ,
int V_242 )
{
struct V_93 * V_187 = V_11 -> V_88 ;
struct V_449 V_450 ;
struct V_451 * V_452 ;
struct V_453 * V_454 ;
T_2 V_431 ;
T_7 V_241 , V_455 ;
int V_246 , V_456 = 0 , V_434 = 0 ;
if ( V_319 <= 0 || ( V_319 & ( ~ V_247 ) ) != 0 ||
( V_187 != NULL && F_127 ( & V_187 -> V_101 ) != F_127 ( & V_405 -> V_397 ) ) )
return - V_165 ;
V_241 = V_448 >> V_442 ;
V_455 = V_319 >> V_442 ;
F_61 ( V_452 , V_241 * sizeof( struct V_451 ) ) ;
F_61 ( V_454 , V_241 * sizeof( struct V_453 ) ) ;
if ( V_452 == NULL || V_454 == NULL )
GOTO ( V_150 , V_456 = - V_68 ) ;
if ( V_238 == V_427 && V_242 )
V_434 |= V_443 ;
F_239 ( V_405 , & V_450 ) ;
V_431 = V_239 ;
for(; V_455 ; V_455 -= V_241 ) {
int V_457 ;
if ( V_455 < V_241 )
V_241 = V_455 ;
for ( V_246 = 0 ; V_246 < V_241 ; V_246 ++ , V_431 += V_249 ) {
V_454 [ V_246 ] . V_239 = V_431 ;
V_454 [ V_246 ] . V_458 = V_249 ;
V_454 [ V_246 ] . V_459 = V_434 ;
}
V_450 . V_460 = V_241 ;
V_407 -> V_461 = 0 ;
V_457 = V_241 ;
V_456 = F_240 ( V_26 , V_238 , exp , V_405 , 1 , & V_450 , V_454 , & V_457 ,
V_452 , V_407 , NULL ) ;
if ( V_456 != 0 )
GOTO ( V_150 , V_456 ) ;
F_14 ( V_457 == V_241 ) ;
for ( V_246 = 0 ; V_246 < V_457 ; V_246 ++ ) {
struct V_34 * V_34 = V_452 [ V_246 ] . V_34 ;
if ( V_34 == NULL && V_452 [ V_246 ] . V_117 == 0 )
continue;
if ( V_242 )
V_452 [ V_246 ] . V_459 |= V_443 ;
if ( F_127 ( & V_405 -> V_397 ) == V_435 ||
( V_405 -> V_409 & V_436 ) == 0 ||
( V_405 -> V_437 & V_438 ) == 0 )
continue;
if ( V_238 == V_427 )
F_229 ( V_187 , V_34 , V_238 ,
F_127 ( & V_405 -> V_397 ) ,
V_454 [ V_246 ] . V_239 ,
V_454 [ V_246 ] . V_458 ) ;
else
F_233 ( V_187 , V_34 ,
F_127 ( & V_405 -> V_397 ) ,
V_454 [ V_246 ] . V_239 ,
V_454 [ V_246 ] . V_458 ) ;
}
V_456 = F_241 ( V_26 , V_238 , exp , V_405 , 1 , & V_450 ,
V_454 , V_241 , V_452 , V_407 , V_456 ) ;
if ( V_456 != 0 )
GOTO ( V_150 , V_456 ) ;
memset ( V_407 , 0 , sizeof( * V_407 ) ) ;
F_242 ( (struct V_120 * ) & V_26 -> V_28 ) ;
F_243 ( (struct V_120 * ) & V_26 -> V_28 ) ;
}
V_150:
if ( V_452 )
F_62 ( V_452 , V_241 * sizeof( struct V_451 ) ) ;
if ( V_454 )
F_62 ( V_454 , V_241 * sizeof( struct V_453 ) ) ;
return V_456 ;
}
static int F_244 ( const struct V_25 * V_26 , int V_238 ,
struct V_447 * exp ,
struct V_380 * V_125 ,
struct V_406 * V_462 )
{
struct V_6 * V_7 = F_245 ( exp ) ;
struct V_1 * V_72 = F_4 ( V_7 ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_404 * V_405 = & V_125 -> V_396 ;
struct V_10 * V_11 ;
int V_117 ;
int V_242 = 1 ;
long V_463 ;
F_14 ( V_405 -> V_409 & V_414 ) ;
V_117 = F_225 ( & V_11 , V_72 , V_405 ) ;
if ( V_117 )
return V_117 ;
V_405 -> V_409 &= ~ V_464 ;
V_463 = ( long ) V_125 -> V_465 ;
if ( V_463 == 1 )
V_242 = 0 ;
if ( V_72 -> V_77 == NULL && V_463 != 3 ) {
V_463 = 3 ;
V_125 -> V_466 = V_125 -> V_467 ;
}
if ( V_125 -> V_466 > V_468 )
V_125 -> V_466 = V_468 ;
switch ( V_463 ) {
case 1 :
case 2 :
V_117 = F_235 ( V_72 , V_238 , V_405 ,
V_11 , V_125 -> V_469 ,
V_125 -> V_467 , V_242 , V_462 ) ;
break;
case 3 :
V_117 = F_238 ( V_26 , V_75 -> V_96 , V_238 , V_405 ,
V_11 , V_125 -> V_469 ,
V_125 -> V_467 , V_125 -> V_466 ,
V_462 , V_242 ) ;
break;
default:
V_117 = - V_165 ;
}
F_226 ( V_11 ) ;
return V_117 ;
}
static int
F_246 ( struct V_447 * exp , struct V_404 * V_405 ,
int V_208 , T_2 V_239 , T_7 V_263 )
{
struct V_1 * V_72 = F_4 ( exp -> V_470 ) ;
struct V_243 * V_471 = & V_405 -> V_472 ;
struct V_10 * V_11 ;
T_2 V_207 ;
int V_117 ;
if ( V_72 -> V_77 == NULL )
return - V_473 ;
if ( ! ( V_208 == V_251 || V_208 == V_218 ) )
return - V_165 ;
if ( ( V_239 & ( ~ V_247 ) ) != 0 ||
( V_263 & ( ~ V_247 ) ) != 0 )
return - V_165 ;
V_117 = F_225 ( & V_11 , V_72 , V_405 ) ;
if ( V_117 != 0 )
return V_117 ;
V_207 = ( V_263 == 0 ) ? ( ( T_2 ) - 1 ) : ( V_239 + V_263 - 1 ) ;
V_117 = F_146 ( V_11 , V_239 , V_207 , V_208 , & V_471 -> V_52 ) ;
if ( V_117 == 0 ) {
V_405 -> V_409 |= V_464 ;
F_119 ( V_181 , L_67 , V_471 -> V_52 ) ;
}
F_226 ( V_11 ) ;
return V_117 ;
}
static int
F_247 ( struct V_447 * exp , struct V_404 * V_405 )
{
struct V_1 * V_72 = F_4 ( exp -> V_470 ) ;
T_3 V_52 = V_405 -> V_472 . V_52 ;
if ( ( V_405 -> V_409 & V_464 ) == 0 )
return - V_165 ;
F_119 ( V_181 , L_67 , V_52 ) ;
return F_153 ( V_72 , V_52 ) ;
}
static int
F_248 ( unsigned int V_474 , struct V_447 * exp , int V_458 ,
void * V_475 , void * V_476 )
{
struct V_6 * V_7 = exp -> V_470 ;
struct V_1 * V_72 = F_4 ( V_7 ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_10 * V_11 ;
struct V_380 * V_125 = V_475 ;
struct V_406 V_462 ;
struct V_25 * V_26 ;
struct V_477 * V_478 ;
struct V_404 * V_405 ;
struct V_188 V_189 ;
int V_238 = V_441 ;
int V_117 = 0 ;
int V_246 ;
memset ( & V_462 , 0 , sizeof( V_462 ) ) ;
V_405 = & V_125 -> V_396 ;
if ( ! ( V_405 -> V_409 & V_414 ) ) {
V_405 -> V_409 |= V_414 ;
F_64 ( & V_405 -> V_397 ) ;
}
V_117 = F_132 ( & V_189 , & V_405 -> V_397 , 0 ) ;
if ( V_117 < 0 )
return V_117 ;
F_91 ( V_26 ) ;
if ( V_26 == NULL )
return - V_68 ;
V_117 = F_249 ( V_26 , V_479 ) ;
if ( V_117 )
GOTO ( V_150 , V_117 = - V_68 ) ;
switch ( V_474 ) {
case V_480 :
if ( ! F_250 ( V_481 ) )
GOTO ( V_150 , V_117 = - V_482 ) ;
V_117 = F_220 ( V_26 , V_72 , 1 , V_405 , V_125 -> V_465 ,
V_125 -> V_466 , & V_462 ) ;
GOTO ( V_150 , V_117 ) ;
case V_483 : {
int V_319 ;
int V_474 ;
char * V_484 = NULL ;
int V_485 ;
T_3 V_272 ;
if ( ! F_250 ( V_481 ) )
GOTO ( V_150 , V_117 = - V_482 ) ;
V_319 = V_125 -> V_467 ;
V_474 = V_125 -> V_486 ;
V_272 = F_127 ( & V_125 -> V_391 . V_397 ) ;
V_485 = V_125 -> V_466 ;
F_61 ( V_484 , V_485 + 1 ) ;
if ( V_484 == NULL )
GOTO ( V_150 , V_117 = - V_68 ) ;
if ( F_173 ( V_484 , V_125 -> V_465 , V_485 ) ) {
F_62 ( V_484 , V_125 -> V_466 + 1 ) ;
GOTO ( V_150 , V_117 = - V_265 ) ;
}
V_117 = F_218 ( V_72 , V_474 , V_484 , V_485 , V_272 , V_319 , V_125 ) ;
F_62 ( V_484 , V_485 + 1 ) ;
GOTO ( V_150 , V_117 ) ;
}
case V_487 : {
struct V_25 * V_488 ;
int V_190 ;
T_3 V_489 ;
int V_490 ;
if ( ! F_250 ( V_481 ) )
GOTO ( V_150 , V_117 = - V_482 ) ;
V_488 = F_130 ( & V_190 ) ;
if ( F_131 ( V_488 ) )
GOTO ( V_150 , V_117 = F_137 ( V_488 ) ) ;
V_117 = F_219 ( V_488 , V_382 ,
V_383 ) ;
if ( V_117 != 0 ) {
F_135 ( V_488 , & V_190 ) ;
GOTO ( V_150 , V_117 ) ;
}
V_117 = F_251 ( V_488 , V_72 -> V_133 , & V_489 ) ;
F_135 ( V_488 , & V_190 ) ;
if ( V_117 < 0 ) {
F_79 ( L_68 ,
V_7 -> V_129 , V_117 ) ;
GOTO ( V_150 , V_117 ) ;
}
if ( F_171 ( V_125 -> V_465 , & V_489 , V_125 -> V_466 ) )
return - V_265 ;
V_490 = V_491 ;
if ( F_171 ( V_125 -> V_387 , & V_490 ,
V_125 -> V_381 ) )
return - V_265 ;
GOTO ( V_150 , V_117 ) ;
}
case V_492 :
if ( ! F_250 ( V_481 ) )
GOTO ( V_150 , V_117 = - V_482 ) ;
V_117 = F_225 ( & V_11 , V_72 , V_405 ) ;
if ( V_117 == 0 ) {
V_117 = F_224 ( V_26 , V_75 -> V_96 , V_405 , V_11 -> V_88 ,
& V_462 , NULL , NULL ) ;
if ( V_117 == 0 )
V_11 -> V_182 = 1 ;
F_226 ( V_11 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_493 :
V_117 = F_225 ( & V_11 , V_72 , V_405 ) ;
if ( V_117 == 0 ) {
struct V_494 V_195 = { { { 0 } } } ;
V_195 . V_495 = V_11 -> V_88 ;
V_195 . V_496 = V_405 ;
V_117 = F_252 ( V_26 , V_75 -> V_96 , & V_195 ) ;
F_226 ( V_11 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_497 :
if ( ! F_250 ( V_481 ) )
GOTO ( V_150 , V_117 = - V_482 ) ;
V_117 = F_225 ( & V_11 , V_72 , V_405 ) ;
if ( V_117 == 0 ) {
struct V_494 V_195 = { { { 0 } } } ;
V_195 . V_496 = V_405 ;
V_195 . V_495 = V_11 -> V_88 ;
V_117 = F_253 ( V_26 , V_75 -> V_96 , & V_195 , NULL ) ;
F_226 ( V_11 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_498 :
if ( ! F_250 ( V_481 ) )
GOTO ( V_150 , V_117 = - V_482 ) ;
V_238 = V_427 ;
case V_499 :
V_117 = F_244 ( V_26 , V_238 , exp , V_125 , & V_462 ) ;
GOTO ( V_150 , V_117 ) ;
case V_500 :
V_117 = F_225 ( & V_11 , V_72 , V_405 ) ;
if ( V_117 == 0 ) {
V_117 = F_169 ( V_11 -> V_88 , V_125 -> V_465 ,
V_125 -> V_466 ) ;
F_226 ( V_11 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_501 :
if ( ! F_250 ( V_481 ) )
GOTO ( V_150 , V_117 = - V_482 ) ;
if ( V_125 -> V_465 == NULL ) {
V_117 = F_225 ( & V_11 , V_72 , V_405 ) ;
if ( V_117 == 0 ) {
V_11 -> V_182 = 1 ;
F_226 ( V_11 ) ;
}
} else {
V_117 = F_220 ( V_26 , V_72 , 0 , V_405 ,
V_125 -> V_465 ,
V_125 -> V_466 , & V_462 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_502 :
if ( ! F_250 ( V_481 ) )
GOTO ( V_150 , V_117 = - V_482 ) ;
V_117 = F_246 ( exp , V_405 ,
V_125 -> V_503 ,
V_125 -> V_469 ,
V_125 -> V_467 ) ;
GOTO ( V_150 , V_117 ) ;
case V_504 :
V_117 = F_247 ( exp , V_405 ) ;
GOTO ( V_150 , V_117 ) ;
default:
F_79 ( L_69 , V_474 ) ;
GOTO ( V_150 , V_117 = - V_505 ) ;
}
V_150:
F_254 ( V_26 ) ;
F_93 ( V_26 ) ;
for ( V_478 = V_462 . V_506 , V_246 = 0 ; V_246 < 4 ;
V_246 ++ , V_478 ++ ) {
if ( ! V_478 -> V_208 )
break;
F_255 ( & V_478 -> V_62 , V_478 -> V_208 ) ;
}
return V_117 ;
}
static int F_100 ( const struct V_25 * V_26 ,
struct V_6 * V_140 , struct V_143 * V_507 )
{
struct V_74 * V_75 = & V_140 -> V_159 . V_160 ;
struct V_6 * V_147 ;
struct V_508 V_509 = { L_70 } ;
struct V_510 * V_511 = NULL ;
int V_117 ;
if ( V_507 -> V_512 < 2 || F_256 ( V_507 , 1 ) < 1 ) {
F_79 ( L_71 ) ;
return - V_165 ;
}
V_147 = F_98 ( F_99 ( V_507 , 1 ) ) ;
if ( ! V_147 || ! V_147 -> V_513 || ! V_147 -> V_514 ) {
F_79 ( L_72 ,
F_99 ( V_507 , 1 ) ) ;
return - V_165 ;
}
F_257 ( & V_75 -> V_90 ) ;
F_47 ( & V_75 -> V_92 ) ;
F_47 ( & V_75 -> V_184 ) ;
V_75 -> V_225 = 0 ;
V_75 -> V_266 = 0 ;
if ( ! strcmp ( V_147 -> V_156 -> V_157 , V_158 ) ) {
F_258 ( V_382 ) ;
F_259 ( V_383 ) ;
return 0 ;
}
F_61 ( V_511 , sizeof( * V_511 ) ) ;
if ( V_511 == NULL ) {
F_79 ( L_73 ,
F_99 ( V_507 , 1 ) ) ;
return - V_68 ;
}
V_511 -> V_515 = V_516 | V_517 |
V_518 |
V_519 | V_520 |
V_521 | V_522 |
V_523 ;
V_511 -> V_524 = V_525 ;
V_511 -> V_526 = V_527 ;
V_511 -> V_528 = V_192 ;
V_117 = F_260 ( V_26 , & V_75 -> V_96 , V_147 , & V_509 , V_511 , NULL ) ;
if ( V_117 == 0 ) {
F_55 ( & V_147 -> V_529 ) ;
F_69 ( & V_75 -> V_96 -> V_530 ) ;
F_57 ( & V_147 -> V_529 ) ;
}
F_62 ( V_511 , sizeof( * V_511 ) ) ;
if ( V_117 != 0 ) {
F_79 ( L_74 ,
F_99 ( V_507 , 1 ) ) ;
return ( V_117 ) ;
}
return V_117 ;
}
static int F_104 ( struct V_6 * V_140 )
{
struct V_1 * V_72 = F_4 ( V_140 ) ;
struct V_74 * V_75 = & V_140 -> V_159 . V_160 ;
int V_117 ;
if ( V_72 == NULL )
return 0 ;
if ( V_72 -> V_84 ) {
F_261 ( V_382 ) ;
F_262 ( V_383 ) ;
return 0 ;
}
if ( ! F_33 ( & V_140 -> V_531 ) ) {
F_79 ( L_75 ) ;
return - V_45 ;
}
F_14 ( F_68 ( & V_75 -> V_96 -> V_532 ) > 0 ) ;
V_117 = F_263 ( V_75 -> V_96 ) ;
if ( V_117 != 0 )
F_79 ( L_76 , V_117 ) ;
return V_117 ;
}
static int F_264 ( const struct V_25 * V_26 ,
struct V_447 * * exp ,
struct V_6 * V_533 , struct V_508 * V_534 ,
struct V_510 * V_125 , void * V_535 )
{
int V_117 ;
struct V_243 V_536 = { 0 } ;
V_117 = F_265 ( & V_536 , V_533 , V_534 ) ;
if ( V_117 == 0 ) {
* exp = F_266 ( & V_536 ) ;
}
return V_117 ;
}
static int F_267 ( struct V_447 * exp )
{
#if 0
struct obd_device *obd;
struct echo_client_obd *ec;
struct ec_lock *ecl;
#endif
int V_117 ;
if ( exp == NULL )
GOTO ( V_150 , V_117 = - V_165 ) ;
#if 0
obd = exp->exp_obd;
ec = &obd->u.echo_client;
while (!list_empty (&exp->exp_ec_data.eced_locks)) {
ecl = list_entry (exp->exp_ec_data.eced_locks.next,
struct ec_lock, ecl_exp_chain);
list_del (&ecl->ecl_exp_chain);
rc = obd_cancel(ec->ec_exp, ecl->ecl_object->eco_lsm,
ecl->ecl_mode, &ecl->ecl_lock_handle);
CDEBUG (D_INFO, "Cancel lock on object %#llx on disconnect "
"(%d)\n", ecl->ecl_object->eco_id, rc);
echo_put_object (ecl->ecl_object);
OBD_FREE (ecl, sizeof (*ecl));
}
#endif
V_117 = F_268 ( exp ) ;
GOTO ( V_150 , V_117 ) ;
V_150:
return V_117 ;
}
int F_269 ( void )
{
struct V_537 V_538 = { NULL } ;
int V_117 ;
F_270 ( & V_538 ) ;
V_117 = F_271 ( V_539 ) ;
if ( V_117 == 0 ) {
V_117 = F_272 ( & V_540 , NULL ,
V_538 . V_541 ,
V_54 ,
& V_223 ) ;
if ( V_117 )
F_273 ( V_539 ) ;
}
return V_117 ;
}
void F_274 ( void )
{
F_275 ( V_54 ) ;
F_273 ( V_539 ) ;
}
static int T_10 F_276 ( void )
{
struct V_537 V_538 ;
int V_117 ;
F_277 ( L_77 ) ;
F_14 ( V_249 % V_426 == 0 ) ;
F_270 ( & V_538 ) ;
V_117 = F_269 () ;
return V_117 ;
}
static void F_278 ( void )
{
F_274 () ;
}
