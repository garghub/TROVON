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
F_121 ( V_183 ,
F_122 ( 1 ) ) ;
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
F_14 ( V_72 -> V_119 == F_123 ( V_5 -> V_166 ) ) ;
F_81 ( V_26 , V_72 ) ;
F_105 ( & V_72 -> V_4 ) ;
F_93 ( V_72 ) ;
return NULL ;
}
static struct V_10 * F_124 ( struct V_1 * V_5 ,
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
F_125 ( F_126 ( & V_187 -> V_101 ) != 0 , V_191 L_16 , F_127 ( & V_187 -> V_101 ) ) ;
F_125 ( F_128 ( & V_187 -> V_101 ) == V_192 , V_191 L_16 ,
F_127 ( & V_187 -> V_101 ) ) ;
if ( F_3 ( V_5 ) -> V_151 . V_185 -> V_193 )
return F_84 ( - V_155 ) ;
V_26 = F_129 ( & V_190 ) ;
if ( F_130 ( V_26 ) )
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
memset ( V_199 , 0 , sizeof *V_199 ) ;
V_199 -> V_187 = V_187 ;
V_69 -> V_33 . V_159 . V_201 = V_199 ;
}
}
V_69 -> V_87 = V_94 ;
V_189 = & V_27 -> V_202 ;
V_117 = F_131 ( V_189 , & V_187 -> V_101 , 0 ) ;
if ( V_117 != 0 )
GOTO ( V_150 , V_11 = F_84 ( V_117 ) ) ;
V_59 = F_132 ( V_26 , F_3 ( V_5 ) , V_189 , & V_69 -> V_33 ) ;
if ( F_130 ( V_59 ) )
GOTO ( V_150 , V_11 = ( void * ) V_59 ) ;
V_11 = F_7 ( V_59 ) ;
if ( V_11 -> V_182 ) {
F_133 ( V_26 , V_59 ) ;
V_11 = F_84 ( - V_42 ) ;
}
V_150:
F_134 ( V_26 , & V_190 ) ;
return V_11 ;
}
static int F_135 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
int V_190 ;
V_26 = F_129 ( & V_190 ) ;
if ( F_130 ( V_26 ) )
return F_136 ( V_26 ) ;
if ( V_11 -> V_182 ) {
struct V_104 * V_203 = V_59 -> V_108 . V_83 ;
F_14 ( & V_11 -> V_107 == F_137 ( V_203 ) ) ;
F_138 ( V_204 , & V_203 -> V_205 ) ;
}
F_133 ( V_26 , V_59 ) ;
F_134 ( V_26 , & V_190 ) ;
return 0 ;
}
static int F_139 ( struct V_25 * V_26 , struct V_10 * V_11 ,
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
V_211 -> V_215 = F_140 ( V_59 , V_206 ) ;
V_211 -> V_216 = F_140 ( V_59 , V_207 ) ;
V_211 -> V_217 = V_208 == V_218 ? V_219 : V_220 ;
V_211 -> V_221 = V_209 ;
V_38 -> V_222 = V_59 ;
V_210 = F_141 ( V_26 , V_38 , V_211 , L_10 , V_11 ) ;
if ( V_210 ) {
struct V_74 * V_75 = V_11 -> V_89 -> V_76 ;
struct V_18 * V_63 ;
V_117 = F_142 ( V_26 , V_210 ) ;
if ( V_117 == 0 ) {
V_63 = F_10 ( F_143 ( V_210 , & V_223 ) ) ;
F_55 ( & V_75 -> V_90 ) ;
if ( F_33 ( & V_63 -> V_55 ) ) {
F_144 ( & V_63 -> V_55 , & V_75 -> V_184 ) ;
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
static int F_145 ( struct V_10 * V_11 , T_2 V_206 , T_2 V_207 ,
int V_208 , T_3 * V_52 )
{
struct V_24 * V_27 ;
struct V_25 * V_26 ;
struct V_37 * V_38 ;
int V_190 ;
int V_227 ;
V_26 = F_129 ( & V_190 ) ;
if ( F_130 ( V_26 ) )
return F_136 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_212 ;
V_38 -> V_228 = 1 ;
V_227 = F_146 ( V_26 , V_38 , V_229 , F_6 ( V_11 ) ) ;
if ( V_227 < 0 )
GOTO ( V_150 , V_227 ) ;
F_14 ( V_227 == 0 ) ;
V_227 = F_139 ( V_26 , V_11 , V_206 , V_207 , V_208 , V_52 , 0 ) ;
F_147 ( V_26 , V_38 ) ;
V_150:
F_134 ( V_26 , & V_190 ) ;
return V_227 ;
}
static int F_148 ( struct V_25 * V_26 , struct V_1 * V_72 ,
T_3 V_52 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_18 * V_22 = NULL ;
struct V_230 * V_63 ;
int V_164 = 0 , V_179 = 0 ;
F_14 ( V_75 != NULL ) ;
F_55 ( & V_75 -> V_90 ) ;
F_149 (el, &ec->ec_locks) {
V_22 = F_150 ( V_63 , struct V_18 , V_55 ) ;
F_119 ( V_181 , L_17 V_231 L_16 , V_22 , V_22 -> V_224 ) ;
V_164 = ( V_22 -> V_224 == V_52 ) ;
if ( V_164 ) {
if ( F_151 ( & V_22 -> V_67 ) )
F_69 ( & V_22 -> V_55 ) ;
else
V_179 = 1 ;
break;
}
}
F_57 ( & V_75 -> V_90 ) ;
if ( ! V_164 )
return - V_232 ;
F_109 ( V_26 , V_22 , V_179 ) ;
return 0 ;
}
static int F_152 ( struct V_1 * V_72 , T_3 V_52 )
{
struct V_25 * V_26 ;
int V_190 ;
int V_117 ;
V_26 = F_129 ( & V_190 ) ;
if ( F_130 ( V_26 ) )
return F_136 ( V_26 ) ;
V_117 = F_148 ( V_26 , V_72 , V_52 ) ;
F_134 ( V_26 , & V_190 ) ;
return V_117 ;
}
static int F_153 ( const struct V_25 * V_26 , struct V_37 * V_38 ,
enum V_233 V_43 , struct V_234 * V_235 )
{
struct V_60 * V_236 ;
struct V_60 * V_237 ;
int V_227 = 0 ;
F_154 (clp, temp, &queue->c2_qin) {
int V_117 ;
V_117 = F_155 ( V_26 , V_38 , V_236 , V_238 ) ;
if ( V_117 == 0 )
continue;
V_227 = V_227 ? : V_117 ;
}
return V_227 ;
}
static int F_156 ( struct V_10 * V_11 , int V_239 , T_2 V_240 ,
struct V_34 * * V_241 , int V_242 , int V_243 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
struct V_1 * V_72 = V_11 -> V_89 ;
struct V_234 * V_235 ;
struct V_37 * V_38 ;
struct V_60 * V_236 ;
struct V_244 V_245 = { 0 } ;
int V_246 = F_157 ( V_59 ) ;
int V_190 ;
int V_117 ;
int V_247 ;
F_14 ( ( V_240 & ~ V_248 ) == 0 ) ;
F_14 ( V_72 -> V_77 != NULL ) ;
V_26 = F_129 ( & V_190 ) ;
if ( F_130 ( V_26 ) )
return F_136 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_212 ;
V_235 = & V_27 -> V_249 ;
F_158 ( V_235 ) ;
V_38 -> V_228 = 1 ;
V_117 = F_146 ( V_26 , V_38 , V_229 , V_59 ) ;
if ( V_117 < 0 )
GOTO ( V_150 , V_117 ) ;
F_14 ( V_117 == 0 ) ;
V_117 = F_139 ( V_26 , V_11 , V_240 ,
V_240 + V_242 * V_250 - 1 ,
V_239 == V_251 ? V_252 : V_218 , & V_245 . V_52 ,
V_253 ) ;
if ( V_117 < 0 )
GOTO ( V_254 , V_117 ) ;
for ( V_247 = 0 ; V_247 < V_242 ; V_247 ++ ) {
F_14 ( V_241 [ V_247 ] ) ;
V_236 = F_159 ( V_26 , V_59 , F_140 ( V_59 , V_240 ) ,
V_241 [ V_247 ] , V_255 ) ;
if ( F_130 ( V_236 ) ) {
V_117 = F_136 ( V_236 ) ;
break;
}
F_14 ( V_236 -> V_256 == V_255 ) ;
V_117 = F_160 ( V_26 , V_38 , V_236 ) ;
if ( V_117 ) {
F_14 ( V_236 -> V_257 == V_258 ) ;
F_161 ( V_26 , V_236 ) ;
break;
}
F_162 ( V_235 , V_236 ) ;
F_161 ( V_26 , V_236 ) ;
F_163 ( V_26 , V_236 , 0 , V_246 ) ;
V_240 += V_246 ;
}
if ( V_117 == 0 ) {
enum V_233 V_259 = V_239 == V_251 ? V_260 : V_238 ;
V_243 = V_243 && ( V_259 == V_238 ) ;
if ( V_243 )
V_117 = F_153 ( V_26 , V_38 , V_259 , V_235 ) ;
else
V_117 = F_164 ( V_26 , V_38 , V_259 , V_235 , 0 ) ;
F_119 ( V_181 , L_18 ,
V_243 ? L_19 : L_20 , V_117 ) ;
}
F_148 ( V_26 , V_72 , V_245 . V_52 ) ;
V_254:
F_165 ( V_26 , V_38 , V_235 ) ;
F_166 ( V_26 , V_38 , V_235 ) ;
F_167 ( V_26 , V_235 ) ;
F_147 ( V_26 , V_38 ) ;
V_150:
F_134 ( V_26 , & V_190 ) ;
return V_117 ;
}
static int
F_168 ( struct V_93 * V_187 , void * V_261 , int V_262 )
{
struct V_93 * V_263 = V_261 ;
int V_264 , V_247 ;
V_264 = F_169 ( struct V_93 , V_97 [ V_187 -> V_265 ] ) ;
if ( V_264 > V_262 )
return ( - V_165 ) ;
if ( F_170 ( V_263 , V_187 , sizeof( * V_263 ) ) )
return ( - V_266 ) ;
for ( V_247 = 0 ; V_247 < V_187 -> V_265 ; V_247 ++ ) {
if ( F_170 ( V_263 -> V_97 [ V_247 ] , V_187 -> V_97 [ V_247 ] ,
sizeof( V_187 -> V_97 [ 0 ] ) ) )
return ( - V_266 ) ;
}
return 0 ;
}
static int
F_171 ( struct V_1 * V_72 , struct V_93 * V_187 ,
void * V_263 , int V_262 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
int V_247 ;
if ( V_262 < sizeof ( * V_187 ) )
return ( - V_165 ) ;
if ( F_172 ( V_187 , V_263 , sizeof ( * V_187 ) ) )
return ( - V_266 ) ;
if ( V_187 -> V_265 > V_75 -> V_267 ||
V_187 -> V_268 != V_269 ||
( V_187 -> V_270 & ( ~ V_248 ) ) != 0 ||
( ( T_3 ) V_187 -> V_270 * V_187 -> V_265 > ~ 0UL ) )
return ( - V_165 ) ;
for ( V_247 = 0 ; V_247 < V_187 -> V_265 ; V_247 ++ ) {
if ( F_172 ( V_187 -> V_97 [ V_247 ] ,
( (struct V_93 * ) V_263 ) -> \
V_97 [ V_247 ] ,
sizeof( V_187 -> V_97 [ 0 ] ) ) )
return ( - V_266 ) ;
}
return ( 0 ) ;
}
static inline void F_173 ( struct V_271 * V_272 , char * V_177 ,
T_3 V_273 )
{
sprintf ( V_177 , V_274 , V_273 ) ;
V_272 -> V_275 = V_177 ;
V_272 -> V_276 = strlen ( V_177 ) ;
}
static int F_174 ( const struct V_25 * V_26 , struct V_277 * V_13 ,
struct V_278 * V_279 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
int V_117 ;
F_14 ( V_279 -> V_280 > 0 ) ;
V_117 = F_175 ( V_26 , V_13 , & V_281 , V_282 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( V_27 -> V_283 < V_117 ) {
int V_284 = F_176 ( V_117 ) ;
if ( V_27 -> V_283 > 0 ) {
F_14 ( V_27 -> V_285 ) ;
F_177 ( V_27 -> V_285 ,
V_27 -> V_283 ) ;
V_27 -> V_285 = NULL ;
V_27 -> V_283 = 0 ;
}
F_178 ( V_27 -> V_285 , V_284 ) ;
if ( V_27 -> V_285 == NULL )
return - V_68 ;
V_27 -> V_283 = V_284 ;
}
F_14 ( V_27 -> V_283 >= V_117 ) ;
V_27 -> V_286 . V_287 = V_27 -> V_285 ;
V_27 -> V_286 . V_288 = V_27 -> V_283 ;
V_117 = F_175 ( V_26 , V_13 , & V_27 -> V_286 , V_282 ) ;
if ( V_117 < 0 )
return V_117 ;
V_279 -> V_289 |= V_290 ;
V_279 -> V_291 = V_27 -> V_285 ;
V_279 -> V_280 = V_117 ;
return 0 ;
}
int F_179 ( const struct V_25 * V_26 , struct V_277 * V_145 ,
struct V_278 * V_279 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_292 * V_293 = & V_27 -> V_286 ;
T_5 V_208 = F_180 ( & V_145 -> V_294 ) ;
int V_58 = V_279 -> V_295 ;
int V_117 = 0 , V_176 ;
V_279 -> V_289 = 0 ;
if ( V_58 & V_296 ) {
V_279 -> V_295 = V_296 ;
V_117 = F_181 ( V_26 , V_145 , V_279 ) ;
if ( V_117 )
GOTO ( V_150 , V_117 ) ;
V_279 -> V_289 |= V_296 ;
}
if ( V_58 & V_290 ) {
if ( F_182 ( V_208 ) || F_183 ( V_208 ) ) {
F_14 ( V_279 -> V_280 > 0 ) ;
V_293 -> V_287 = V_279 -> V_291 ;
V_293 -> V_288 = V_279 -> V_280 ;
V_176 = F_175 ( V_26 , V_145 , V_293 , V_282 ) ;
if ( V_176 > 0 ) {
V_279 -> V_280 = V_176 ;
V_279 -> V_289 |= V_290 ;
} else if ( V_176 == - V_46 ) {
V_279 -> V_280 = 0 ;
} else if ( V_176 == - V_297 ) {
V_176 = F_174 ( V_26 , V_145 , V_279 ) ;
if ( V_176 < 0 )
GOTO ( V_150 , V_117 = V_176 ) ;
} else {
GOTO ( V_150 , V_117 = V_176 ) ;
}
}
}
#ifdef F_184
if ( V_58 & V_298 && F_183 ( V_208 ) ) {
V_293 -> V_287 = V_279 -> V_299 ;
V_293 -> V_288 = V_279 -> V_300 ;
V_176 = F_175 ( V_26 , V_145 , V_293 , V_301 ) ;
if ( V_176 > 0 ) {
V_279 -> V_300 = V_176 ;
V_279 -> V_289 |= V_298 ;
} else if ( V_176 == - V_46 ) {
V_279 -> V_300 = 0 ;
} else {
GOTO ( V_150 , V_117 = V_176 ) ;
}
}
#endif
V_150:
V_279 -> V_295 = V_58 ;
F_119 ( V_302 , L_21 V_231 L_22 ,
V_117 , V_279 -> V_289 , V_279 -> V_291 ) ;
return V_117 ;
}
static int
F_185 ( const struct V_25 * V_26 , struct V_1 * V_72 ,
struct V_277 * V_303 , struct V_188 * V_189 ,
struct V_271 * V_272 , struct V_304 * V_305 ,
struct V_278 * V_279 )
{
struct V_70 * V_306 , * V_307 ;
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_188 * V_308 = & V_27 -> V_309 ;
struct V_71 V_69 = { . V_310 = V_311 } ;
int V_117 ;
V_117 = F_186 ( V_26 , V_303 , V_272 , V_308 , V_305 ) ;
if ( V_117 == 0 )
return - V_312 ;
else if ( V_117 != - V_232 )
return V_117 ;
V_306 = F_187 ( V_26 , & V_72 -> V_4 . V_151 ,
V_189 , & V_69 ) ;
if ( F_130 ( V_306 ) ) {
F_79 ( L_23 V_313 L_24 , F_188 ( V_189 ) ,
F_136 ( V_306 ) ) ;
return F_136 ( V_306 ) ;
}
V_307 = F_189 ( V_306 -> V_83 , V_163 -> V_168 ) ;
if ( V_307 == NULL ) {
F_79 ( L_25 V_313 L_16 , F_188 ( V_189 ) ) ;
GOTO ( V_314 , V_117 = - V_165 ) ;
}
F_119 ( V_315 , L_26 V_313 L_27 ,
F_188 ( F_190 ( & V_303 -> V_294 ) ) , V_272 -> V_275 , V_303 ) ;
V_305 -> V_316 = 0 ;
V_117 = F_191 ( V_26 , V_303 , V_272 , F_192 ( V_307 ) , V_305 , V_279 ) ;
if ( V_117 ) {
F_79 ( L_28 V_313 L_29 , F_188 ( V_189 ) , V_117 ) ;
GOTO ( V_314 , V_117 ) ;
}
F_119 ( V_315 , L_30 V_313 L_31 ,
F_188 ( F_190 ( & V_303 -> V_294 ) ) , V_272 -> V_275 , V_303 , V_117 ) ;
V_314:
F_193 ( V_26 , V_306 ) ;
return V_117 ;
}
static int F_194 ( const struct V_25 * V_26 , struct V_79 * V_163 ,
struct V_278 * V_279 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
if ( strcmp ( V_163 -> V_168 -> V_169 , V_317 ) ) {
V_279 -> V_291 = ( void * ) & V_27 -> V_318 ;
V_279 -> V_280 = sizeof( V_27 -> V_318 ) ;
} else {
F_14 ( V_27 -> V_283 ) ;
V_279 -> V_291 = V_27 -> V_285 ;
V_279 -> V_280 = V_27 -> V_283 ;
}
return 0 ;
}
static int F_195 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_319 ,
struct V_188 * V_189 ,
char * V_177 , int V_320 ,
T_3 V_273 , T_4 V_208 , int V_321 ,
int V_322 , int V_323 )
{
struct V_70 * V_303 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_271 * V_272 = & V_27 -> V_324 ;
struct V_304 * V_305 = & V_27 -> V_325 ;
struct V_278 * V_279 = & V_27 -> V_326 ;
struct V_79 * V_163 = V_72 -> V_77 ;
int V_117 = 0 ;
int V_247 ;
if ( V_319 == NULL )
return - 1 ;
V_303 = F_189 ( V_319 -> V_83 , V_163 -> V_168 ) ;
if ( V_303 == NULL )
return - V_327 ;
memset ( V_279 , 0 , sizeof( * V_279 ) ) ;
memset ( V_305 , 0 , sizeof( * V_305 ) ) ;
if ( V_322 != 0 ) {
V_305 -> V_328 |= V_329 ;
F_194 ( V_26 , V_163 , V_279 ) ;
if ( V_322 != - 1 ) {
struct V_330 * V_331 = & V_27 -> V_332 ;
V_331 -> V_333 = V_334 ;
V_331 -> V_335 = V_322 ;
V_331 -> V_336 = V_323 ;
V_331 -> V_337 = 0 ;
V_305 -> V_159 . V_338 . V_339 = V_331 ;
V_305 -> V_159 . V_338 . V_340 = sizeof( * V_331 ) ;
V_305 -> V_328 |= V_341 ;
}
}
V_279 -> V_342 . V_343 = V_208 ;
V_279 -> V_342 . V_344 = V_345 | V_346 ;
V_279 -> V_342 . V_347 = F_196 () ;
if ( V_177 != NULL ) {
V_272 -> V_275 = V_177 ;
V_272 -> V_276 = V_320 ;
V_117 = F_185 ( V_26 , V_72 , F_192 ( V_303 ) , V_189 , V_272 ,
V_305 , V_279 ) ;
return V_117 ;
}
for ( V_247 = 0 ; V_247 < V_321 ; V_247 ++ ) {
char * V_348 = V_27 -> V_349 ;
F_173 ( V_272 , V_348 , V_273 ) ;
V_117 = F_185 ( V_26 , V_72 , F_192 ( V_303 ) , V_189 , V_272 ,
V_305 , V_279 ) ;
if ( V_117 ) {
F_79 ( L_32 , V_348 ,
V_117 ) ;
break;
}
V_273 ++ ;
V_189 -> V_350 ++ ;
}
return V_117 ;
}
static struct V_70 * F_197 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_277 * V_303 ,
struct V_271 * V_272 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_188 * V_189 = & V_27 -> V_202 ;
struct V_70 * V_307 ;
int V_117 ;
F_119 ( V_181 , L_33 V_313 L_34 , V_272 -> V_275 ,
F_188 ( V_189 ) , V_303 ) ;
V_117 = F_186 ( V_26 , V_303 , V_272 , V_189 , NULL ) ;
if ( V_117 ) {
F_79 ( L_35 , V_272 -> V_275 , V_117 ) ;
return F_84 ( V_117 ) ;
}
V_307 = F_187 ( V_26 , & V_72 -> V_4 . V_151 , V_189 , NULL ) ;
return V_307 ;
}
static int F_198 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_319 ,
T_3 V_273 , int V_321 )
{
struct V_70 * V_303 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_271 * V_272 = & V_27 -> V_324 ;
char * V_177 = V_27 -> V_349 ;
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_292 * V_293 = & V_27 -> V_286 ;
int V_117 = 0 ;
int V_247 ;
if ( V_319 == NULL )
return - 1 ;
V_303 = F_189 ( V_319 -> V_83 , V_163 -> V_168 ) ;
if ( V_303 == NULL )
return - V_327 ;
for ( V_247 = 0 ; V_247 < V_321 ; V_247 ++ ) {
struct V_70 * V_306 , * V_307 ;
F_173 ( V_272 , V_177 , V_273 ) ;
V_306 = F_197 ( V_26 , V_72 , F_192 ( V_303 ) , V_272 ) ;
if ( F_130 ( V_306 ) ) {
F_79 ( L_36 ,
V_272 -> V_275 , F_136 ( V_306 ) ) ;
return F_136 ( V_306 ) ;
}
V_307 = F_189 ( V_306 -> V_83 , V_163 -> V_168 ) ;
if ( V_307 == NULL ) {
F_79 ( L_37 , V_272 -> V_275 ) ;
F_193 ( V_26 , V_306 ) ;
V_117 = - V_165 ;
break;
}
F_119 ( V_315 , L_38 V_313 L_16 ,
F_188 ( F_190 ( V_307 ) ) ) ;
V_293 -> V_287 = V_27 -> V_351 ;
V_293 -> V_288 = sizeof( V_27 -> V_351 ) ;
sprintf ( V_177 , L_39 , V_352 ) ;
V_117 = F_199 ( V_26 , F_192 ( V_307 ) , V_293 , V_177 ,
V_353 ) ;
if ( V_117 < 0 ) {
F_79 ( L_40 V_313 L_29 ,
F_188 ( F_190 ( V_307 ) ) , V_117 ) ;
F_193 ( V_26 , V_306 ) ;
break;
}
F_119 ( V_315 , L_41 V_313 L_16 ,
F_188 ( F_190 ( V_307 ) ) ) ;
V_273 ++ ;
F_193 ( V_26 , V_306 ) ;
}
return V_117 ;
}
static int F_200 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_319 ,
T_3 V_273 , int V_321 )
{
struct V_70 * V_303 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_271 * V_272 = & V_27 -> V_324 ;
char * V_177 = V_27 -> V_349 ;
struct V_278 * V_279 = & V_27 -> V_326 ;
struct V_79 * V_163 = V_72 -> V_77 ;
int V_117 = 0 ;
int V_247 ;
if ( V_319 == NULL )
return - 1 ;
V_303 = F_189 ( V_319 -> V_83 , V_163 -> V_168 ) ;
if ( V_303 == NULL )
return - V_327 ;
memset ( V_279 , 0 , sizeof( * V_279 ) ) ;
V_279 -> V_295 |= V_296 | V_290 | V_354 | V_355 | V_298 ;
V_279 -> V_299 = V_27 -> V_351 ;
V_279 -> V_300 = sizeof( V_27 -> V_351 ) ;
for ( V_247 = 0 ; V_247 < V_321 ; V_247 ++ ) {
struct V_70 * V_306 , * V_307 ;
V_279 -> V_289 = 0 ;
F_173 ( V_272 , V_177 , V_273 ) ;
F_194 ( V_26 , V_163 , V_279 ) ;
V_306 = F_197 ( V_26 , V_72 , F_192 ( V_303 ) , V_272 ) ;
if ( F_130 ( V_306 ) ) {
F_79 ( L_36 ,
V_272 -> V_275 , F_136 ( V_306 ) ) ;
return F_136 ( V_306 ) ;
}
V_307 = F_189 ( V_306 -> V_83 , V_163 -> V_168 ) ;
if ( V_307 == NULL ) {
F_79 ( L_37 , V_272 -> V_275 ) ;
F_193 ( V_26 , V_306 ) ;
return - V_165 ;
}
F_119 ( V_315 , L_42 V_313 L_16 ,
F_188 ( F_190 ( V_307 ) ) ) ;
V_117 = F_179 ( V_26 , F_192 ( V_307 ) , V_279 ) ;
if ( V_117 ) {
F_79 ( L_43 V_313 L_29 ,
F_188 ( F_190 ( V_307 ) ) , V_117 ) ;
F_193 ( V_26 , V_306 ) ;
break;
}
F_119 ( V_315 , L_44 V_313 L_16 ,
F_188 ( F_190 ( V_307 ) ) ) ;
V_273 ++ ;
F_193 ( V_26 , V_306 ) ;
}
return V_117 ;
}
static int F_201 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_319 ,
T_3 V_273 , int V_321 )
{
struct V_70 * V_303 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_271 * V_272 = & V_27 -> V_324 ;
char * V_177 = V_27 -> V_349 ;
struct V_188 * V_189 = & V_27 -> V_202 ;
struct V_79 * V_163 = V_72 -> V_77 ;
int V_117 = 0 ;
int V_247 ;
if ( V_319 == NULL )
return - 1 ;
V_303 = F_189 ( V_319 -> V_83 , V_163 -> V_168 ) ;
if ( V_303 == NULL )
return - V_327 ;
for ( V_247 = 0 ; V_247 < V_321 ; V_247 ++ ) {
F_173 ( V_272 , V_177 , V_273 ) ;
F_119 ( V_315 , L_45 V_313 L_27 ,
F_188 ( F_190 ( V_303 ) ) , V_272 -> V_275 , V_303 ) ;
V_117 = F_186 ( V_26 , F_192 ( V_303 ) , V_272 , V_189 , NULL ) ;
if ( V_117 ) {
F_79 ( L_46 , V_177 , V_117 ) ;
break;
}
F_119 ( V_315 , L_47 V_313 L_27 ,
F_188 ( F_190 ( V_303 ) ) , V_272 -> V_275 , V_303 ) ;
V_273 ++ ;
}
return V_117 ;
}
static int F_202 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_277 * V_303 ,
struct V_271 * V_272 ,
struct V_278 * V_279 )
{
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_70 * V_306 ;
struct V_70 * V_307 ;
int V_117 ;
V_306 = F_197 ( V_26 , V_72 , V_303 , V_272 ) ;
if ( F_130 ( V_306 ) ) {
F_79 ( L_36 , V_272 -> V_275 ,
F_136 ( V_306 ) ) ;
return F_136 ( V_306 ) ;
}
V_307 = F_189 ( V_306 -> V_83 , V_163 -> V_168 ) ;
if ( V_307 == NULL ) {
F_79 ( L_37 , V_272 -> V_275 ) ;
GOTO ( V_314 , V_117 = - V_165 ) ;
}
F_119 ( V_315 , L_48 V_313 L_27 ,
F_188 ( F_190 ( & V_303 -> V_294 ) ) , V_272 -> V_275 , V_303 ) ;
V_117 = F_203 ( V_26 , V_303 , F_192 ( V_307 ) , V_272 , V_279 , 0 ) ;
if ( V_117 ) {
F_79 ( L_49 ,
V_272 -> V_275 , V_117 ) ;
GOTO ( V_314 , V_117 ) ;
}
F_119 ( V_315 , L_50 V_313 L_27 ,
F_188 ( F_190 ( & V_303 -> V_294 ) ) , V_272 -> V_275 , V_303 ) ;
V_314:
F_193 ( V_26 , V_306 ) ;
return V_117 ;
}
static int F_204 ( const struct V_25 * V_26 ,
struct V_1 * V_72 ,
struct V_70 * V_319 ,
char * V_177 , int V_320 ,
T_3 V_273 , T_4 V_208 ,
int V_321 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_271 * V_272 = & V_27 -> V_324 ;
struct V_278 * V_279 = & V_27 -> V_326 ;
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_70 * V_303 ;
int V_117 = 0 ;
int V_247 ;
V_303 = F_189 ( V_319 -> V_83 , V_163 -> V_168 ) ;
if ( V_303 == NULL )
return - V_165 ;
memset ( V_279 , 0 , sizeof( * V_279 ) ) ;
V_279 -> V_342 . V_343 = V_208 ;
V_279 -> V_342 . V_344 = V_345 ;
V_279 -> V_342 . V_347 = F_196 () ;
V_279 -> V_295 = V_296 ;
V_279 -> V_289 = 0 ;
if ( V_177 != NULL ) {
V_272 -> V_275 = V_177 ;
V_272 -> V_276 = V_320 ;
V_117 = F_202 ( V_26 , V_72 , F_192 ( V_303 ) , V_272 ,
V_279 ) ;
return V_117 ;
}
for ( V_247 = 0 ; V_247 < V_321 ; V_247 ++ ) {
char * V_348 = V_27 -> V_349 ;
V_279 -> V_289 = 0 ;
F_173 ( V_272 , V_348 , V_273 ) ;
V_117 = F_202 ( V_26 , V_72 , F_192 ( V_303 ) , V_272 ,
V_279 ) ;
if ( V_117 ) {
F_79 ( L_49 , V_177 , V_117 ) ;
break;
}
V_273 ++ ;
}
return V_117 ;
}
static struct V_70 * F_205 ( const struct V_25 * V_26 ,
struct V_1 * V_72 , char * V_356 ,
int V_357 )
{
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_358 * V_199 = F_206 ( V_163 ) ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_188 * V_189 = & V_27 -> V_202 ;
struct V_271 * V_272 = & V_27 -> V_324 ;
struct V_70 * V_303 = NULL ;
struct V_70 * V_307 = NULL ;
int V_117 = 0 ;
V_117 = V_199 -> V_359 -> V_360 ( V_26 , V_199 , V_189 ) ;
if ( V_117 ) {
F_79 ( L_51 , V_117 ) ;
return F_84 ( V_117 ) ;
}
V_303 = F_187 ( V_26 , & V_72 -> V_4 . V_151 , V_189 , NULL ) ;
if ( F_130 ( V_303 ) ) {
F_79 ( L_52 V_313 L_24 ,
F_188 ( V_189 ) , F_136 ( V_303 ) ) ;
return V_303 ;
}
while ( 1 ) {
struct V_70 * V_361 ;
char * V_362 ;
V_362 = F_207 ( & V_356 , L_53 ) ;
if ( V_362 == NULL )
break;
if ( V_362 [ 0 ] == 0 ) {
if ( ! V_356 || V_356 [ 0 ] == '\0' )
break;
continue;
}
V_272 -> V_275 = V_362 ;
V_272 -> V_276 = strlen ( V_362 ) ;
V_361 = F_189 ( V_303 -> V_83 , V_163 -> V_168 ) ;
if ( V_361 == NULL ) {
F_193 ( V_26 , V_303 ) ;
V_117 = - V_165 ;
break;
}
V_307 = F_197 ( V_26 , V_72 , F_192 ( V_361 ) , V_272 ) ;
F_193 ( V_26 , V_303 ) ;
if ( F_130 ( V_307 ) ) {
V_117 = ( int ) F_136 ( V_307 ) ;
F_79 ( L_54 V_313 L_29 ,
V_272 -> V_275 , F_188 ( F_190 ( V_361 ) ) ,
V_117 ) ;
break;
}
V_303 = V_307 ;
}
if ( V_117 )
return F_84 ( V_117 ) ;
return V_303 ;
}
static void F_208 ( struct V_25 * V_26 )
{
struct V_363 * V_364 = V_363 ( V_26 ) ;
V_364 -> V_365 = V_366 ;
V_364 -> V_367 [ 0 ] = - 1 ;
V_364 -> V_367 [ 1 ] = - 1 ;
V_364 -> V_368 = V_364 -> V_369 =
F_209 ( & V_370 , F_210 () ) ;
V_364 -> V_371 = V_364 -> V_372 =
F_211 ( & V_370 , F_212 () ) ;
V_364 -> V_373 = V_364 -> V_374 =
F_209 ( & V_370 , F_213 () ) ;
V_364 -> V_375 = V_364 -> V_376 =
F_211 ( & V_370 , F_214 () ) ;
V_364 -> V_377 = F_215 () ;
if ( V_364 -> V_373 )
V_364 -> V_377 &= ~ V_378 ;
V_364 -> V_365 = V_379 ;
}
static void F_216 ( struct V_25 * V_26 )
{
struct V_363 * V_364 = V_363 ( V_26 ) ;
V_364 -> V_365 = V_380 ;
}
static int F_217 ( struct V_1 * V_72 , int V_381 ,
char * V_356 , int V_357 , T_3 V_273 , int V_321 ,
struct V_382 * V_125 )
{
struct V_24 * V_27 ;
struct V_79 * V_163 = V_72 -> V_77 ;
struct V_25 * V_26 ;
int V_190 ;
struct V_70 * V_303 ;
char * V_177 = NULL ;
int V_320 = V_125 -> V_383 ;
int V_117 = 0 ;
if ( V_163 == NULL ) {
F_79 ( L_55 ) ;
return - V_165 ;
}
if ( strcmp ( V_163 -> V_168 -> V_169 , V_317 ) ) {
F_79 ( L_56 ) ;
return - V_165 ;
}
V_26 = F_129 ( & V_190 ) ;
if ( F_130 ( V_26 ) )
return F_136 ( V_26 ) ;
V_117 = F_218 ( V_26 , V_384 , V_385 ) ;
if ( V_117 != 0 )
GOTO ( V_386 , V_117 ) ;
V_27 = F_12 ( V_26 ) ;
F_14 ( V_27 -> V_285 == NULL ) ;
F_178 ( V_27 -> V_285 , V_387 ) ;
if ( V_27 -> V_285 == NULL )
GOTO ( V_386 , V_117 = - V_68 ) ;
V_27 -> V_283 = V_387 ;
V_303 = F_205 ( V_26 , V_72 , V_356 , V_357 ) ;
if ( F_130 ( V_303 ) ) {
F_79 ( L_57 , V_356 ,
F_136 ( V_303 ) ) ;
GOTO ( V_388 , V_117 = F_136 ( V_303 ) ) ;
}
if ( V_320 > 0 ) {
F_61 ( V_177 , V_320 + 1 ) ;
if ( V_177 == NULL )
GOTO ( V_314 , V_117 = - V_68 ) ;
if ( F_172 ( V_177 , V_125 -> V_389 , V_320 ) )
GOTO ( V_390 , V_117 = - V_266 ) ;
}
F_208 ( V_26 ) ;
switch ( V_381 ) {
case V_391 :
case V_392 : {
struct V_24 * V_27 = F_12 ( V_26 ) ;
T_4 V_208 = V_125 -> V_393 . V_394 ;
struct V_188 * V_189 = & V_27 -> V_202 ;
int V_322 = ( int ) V_125 -> V_393 . V_395 ;
int V_396 = ( int ) V_125 -> V_393 . V_397 ;
V_117 = F_131 ( V_189 , & V_125 -> V_398 . V_399 , 0 ) ;
if ( V_117 != 0 )
break;
V_117 = F_195 ( V_26 , V_72 , V_303 , V_189 , V_177 , V_320 ,
V_273 , V_208 , V_321 , V_322 ,
V_396 ) ;
break;
}
case V_400 :
case V_401 : {
T_4 V_208 = V_125 -> V_393 . V_394 ;
V_117 = F_204 ( V_26 , V_72 , V_303 , V_177 , V_320 ,
V_273 , V_208 , V_321 ) ;
break;
}
case V_402 :
V_117 = F_201 ( V_26 , V_72 , V_303 , V_273 , V_321 ) ;
break;
case V_403 :
V_117 = F_200 ( V_26 , V_72 , V_303 , V_273 , V_321 ) ;
break;
case V_404 :
V_117 = F_198 ( V_26 , V_72 , V_303 , V_273 , V_321 ) ;
break;
default:
F_79 ( L_58 , V_381 ) ;
V_117 = - V_165 ;
break;
}
F_216 ( V_26 ) ;
V_390:
if ( V_177 != NULL )
F_62 ( V_177 , V_320 + 1 ) ;
V_314:
F_193 ( V_26 , V_303 ) ;
V_388:
F_14 ( V_27 -> V_285 ) ;
F_177 ( V_27 -> V_285 , V_27 -> V_283 ) ;
V_27 -> V_285 = NULL ;
V_27 -> V_283 = 0 ;
V_386:
F_134 ( V_26 , & V_190 ) ;
return V_117 ;
}
static int F_219 ( const struct V_25 * V_26 , struct V_1 * V_72 ,
int V_405 , struct V_406 * V_407 , void * V_263 ,
int V_262 , struct V_408 * V_409 )
{
struct V_10 * V_11 ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_93 * V_187 = NULL ;
int V_117 ;
int V_410 = 0 ;
if ( ( V_407 -> V_411 & V_412 ) == 0 &&
( V_405 ||
V_75 -> V_267 != 0 ) ) {
F_79 ( L_59 ) ;
return - V_165 ;
}
V_117 = F_58 ( V_72 , & V_187 ) ;
if ( V_117 < 0 ) {
F_79 ( L_60 , V_117 ) ;
GOTO ( V_413 , V_117 ) ;
}
if ( V_263 != NULL ) {
int V_247 , V_414 ;
V_117 = F_171 ( V_72 , V_187 , V_263 , V_262 ) ;
if ( V_117 != 0 )
GOTO ( V_413 , V_117 ) ;
if ( V_187 -> V_265 == 0 )
V_187 -> V_265 = V_75 -> V_267 ;
if ( V_187 -> V_270 == 0 )
V_187 -> V_270 = V_250 ;
V_414 = F_220 () ;
for ( V_247 = 0 ; V_247 < V_187 -> V_265 ; V_247 ++ ) {
if ( F_126 ( & V_187 -> V_97 [ V_247 ] -> V_196 ) == 0 )
V_187 -> V_97 [ V_247 ] -> V_196 = V_187 -> V_101 ;
V_187 -> V_97 [ V_247 ] -> V_415 =
( V_414 + V_247 ) % V_75 -> V_267 ;
}
}
if ( V_407 -> V_411 & V_412 ) {
F_14 ( V_407 -> V_411 & V_416 ) ;
V_187 -> V_101 = V_407 -> V_399 ;
}
if ( F_126 ( & V_187 -> V_101 ) == 0 )
F_221 ( & V_187 -> V_101 , ++ V_417 ) ;
V_117 = 0 ;
if ( V_405 ) {
F_14 ( ( V_407 -> V_411 & V_416 ) &&
( F_128 ( & V_407 -> V_399 ) == V_192 ) ) ;
V_117 = F_222 ( V_26 , V_75 -> V_96 , V_407 , & V_187 , V_409 ) ;
if ( V_117 != 0 ) {
F_79 ( L_61 , V_117 ) ;
GOTO ( V_413 , V_117 ) ;
}
V_410 = 1 ;
}
V_407 -> V_399 = V_187 -> V_101 ;
V_407 -> V_411 |= V_412 ;
V_11 = F_124 ( V_72 , & V_187 ) ;
if ( F_130 ( V_11 ) )
GOTO ( V_413 , V_117 = F_136 ( V_11 ) ) ;
F_135 ( V_11 ) ;
F_119 ( V_181 , L_62 V_191 L_16 , F_127 ( & V_407 -> V_399 ) ) ;
V_413:
if ( V_410 && V_117 )
F_223 ( V_26 , V_75 -> V_96 , V_407 , V_187 , V_409 , NULL , NULL ) ;
if ( V_187 )
F_65 ( V_72 , & V_187 ) ;
if ( V_117 )
F_79 ( L_63 , V_117 ) ;
return ( V_117 ) ;
}
static int F_224 ( struct V_10 * * V_418 , struct V_1 * V_72 ,
struct V_406 * V_407 )
{
struct V_93 * V_187 = NULL ;
struct V_10 * V_11 ;
int V_117 ;
if ( ( V_407 -> V_411 & V_412 ) == 0 || F_126 ( & V_407 -> V_399 ) == 0 ) {
F_79 ( L_59 ) ;
return - V_165 ;
}
V_117 = F_58 ( V_72 , & V_187 ) ;
if ( V_117 < 0 )
return V_117 ;
V_187 -> V_101 = V_407 -> V_399 ;
if ( ! ( V_407 -> V_411 & V_416 ) )
F_64 ( & V_187 -> V_101 ) ;
V_117 = 0 ;
V_11 = F_124 ( V_72 , & V_187 ) ;
if ( ! F_130 ( V_11 ) )
* V_418 = V_11 ;
else
V_117 = F_136 ( V_11 ) ;
if ( V_187 )
F_65 ( V_72 , & V_187 ) ;
return V_117 ;
}
static void F_225 ( struct V_10 * V_11 )
{
if ( F_135 ( V_11 ) )
F_79 ( L_64 ) ;
}
static void
F_226 ( struct V_93 * V_187 , T_2 * V_419 , T_6 * V_420 )
{
unsigned long V_322 ;
unsigned long V_421 ;
unsigned long V_422 ;
unsigned long V_423 ;
int V_396 ;
T_2 V_240 ;
if ( V_187 -> V_265 <= 1 )
return;
V_240 = * V_419 ;
V_421 = V_187 -> V_270 ;
V_322 = V_187 -> V_265 ;
V_422 = V_421 * V_322 ;
V_423 = F_227 ( V_240 , V_422 ) ;
V_396 = V_423 / V_421 ;
* V_420 = F_126 ( & V_187 -> V_97 [ V_396 ] -> V_196 ) ;
* V_419 = V_240 * V_421 + V_423 % V_421 ;
}
static void
F_228 ( struct V_93 * V_187 ,
struct V_34 * V_34 , int V_239 , T_6 V_273 ,
T_2 V_240 , T_2 V_321 )
{
char * V_424 ;
T_2 V_425 ;
T_6 V_426 ;
int V_427 ;
F_14 ( V_321 == V_250 ) ;
V_424 = F_229 ( V_34 ) ;
for ( V_427 = 0 ; V_427 < V_250 ; V_427 += V_428 ) {
if ( V_239 == V_429 ) {
V_425 = V_240 + V_427 ;
V_426 = V_273 ;
F_226 ( V_187 , & V_425 , & V_426 ) ;
} else {
V_425 = 0xdeadbeef00c0ffeeULL ;
V_426 = 0xdeadbeef00c0ffeeULL ;
}
F_230 ( V_424 + V_427 , V_428 ,
V_425 , V_426 ) ;
}
F_231 ( V_34 ) ;
}
static int F_232 ( struct V_93 * V_187 ,
struct V_34 * V_34 , T_6 V_273 ,
T_2 V_240 , T_2 V_321 )
{
T_2 V_425 ;
T_6 V_426 ;
char * V_424 ;
int V_427 ;
int V_117 ;
int V_176 ;
F_14 ( V_321 == V_250 ) ;
V_424 = F_229 ( V_34 ) ;
for ( V_117 = V_427 = 0 ; V_427 < V_250 ; V_427 += V_428 ) {
V_425 = V_240 + V_427 ;
V_426 = V_273 ;
F_226 ( V_187 , & V_425 , & V_426 ) ;
V_176 = F_233 ( L_65 ,
V_424 + V_427 , V_428 ,
V_425 , V_426 ) ;
if ( V_176 != 0 ) {
F_79 ( L_66 V_231 L_16 , V_273 ) ;
V_117 = V_176 ;
}
}
F_231 ( V_34 ) ;
return V_117 ;
}
static int F_234 ( struct V_1 * V_72 , int V_239 , struct V_406 * V_407 ,
struct V_10 * V_11 , T_2 V_240 ,
T_7 V_321 , int V_243 ,
struct V_408 * V_409 )
{
struct V_93 * V_187 = V_11 -> V_88 ;
T_8 V_242 ;
struct V_430 * V_431 ;
struct V_430 * V_432 ;
struct V_34 * * V_241 ;
T_2 V_433 ;
int V_247 ;
int V_117 ;
int V_434 ;
int V_435 ;
int V_436 = 0 ;
V_434 = ( F_126 ( & V_407 -> V_399 ) != V_437 &&
( V_407 -> V_411 & V_438 ) != 0 &&
( V_407 -> V_439 & V_440 ) != 0 ) ;
V_435 = ( ( F_126 ( & V_407 -> V_399 ) & 2 ) == 0 ) ? V_441 : V_442 ;
F_14 ( V_239 == V_429 || V_239 == V_443 ) ;
F_14 ( V_187 != NULL ) ;
F_14 ( F_126 ( & V_187 -> V_101 ) == F_126 ( & V_407 -> V_399 ) ) ;
if ( V_321 <= 0 ||
( V_321 & ( ~ V_248 ) ) != 0 )
return - V_165 ;
V_242 = V_321 >> V_444 ;
if ( V_239 == V_429 )
V_436 = V_445 ;
F_61 ( V_431 , V_242 * sizeof( * V_431 ) ) ;
if ( V_431 == NULL )
return - V_68 ;
F_61 ( V_241 , V_242 * sizeof( * V_241 ) ) ;
if ( V_241 == NULL ) {
F_62 ( V_431 , V_242 * sizeof( * V_431 ) ) ;
return - V_68 ;
}
for ( V_247 = 0 , V_432 = V_431 , V_433 = V_240 ;
V_247 < V_242 ;
V_247 ++ , V_432 ++ , V_433 += V_250 ) {
F_14 ( V_432 -> V_446 == NULL ) ;
V_117 = - V_68 ;
F_235 ( V_432 -> V_446 , V_435 ) ;
if ( V_432 -> V_446 == NULL )
goto V_150;
V_241 [ V_247 ] = V_432 -> V_446 ;
V_432 -> V_321 = V_250 ;
V_432 -> V_433 = V_433 ;
V_432 -> V_447 = V_436 ;
if ( V_434 )
F_228 ( V_187 , V_432 -> V_446 , V_239 ,
F_126 ( & V_407 -> V_399 ) , V_433 ,
V_432 -> V_321 ) ;
}
F_14 ( V_72 -> V_77 != NULL ) ;
V_117 = F_156 ( V_11 , V_239 , V_240 , V_241 , V_242 , V_243 ) ;
V_150:
if ( V_117 != 0 || V_239 != V_443 )
V_434 = 0 ;
for ( V_247 = 0 , V_432 = V_431 ; V_247 < V_242 ; V_247 ++ , V_432 ++ ) {
if ( V_432 -> V_446 == NULL )
continue;
if ( V_434 ) {
int V_448 ;
V_448 = F_232 ( V_187 , V_432 -> V_446 ,
F_126 ( & V_407 -> V_399 ) ,
V_432 -> V_433 , V_432 -> V_321 ) ;
if ( V_448 != 0 && V_117 == 0 )
V_117 = V_448 ;
}
F_236 ( V_432 -> V_446 ) ;
}
F_62 ( V_431 , V_242 * sizeof( * V_431 ) ) ;
F_62 ( V_241 , V_242 * sizeof( * V_241 ) ) ;
return V_117 ;
}
static int F_237 ( const struct V_25 * V_26 ,
struct V_449 * exp , int V_239 ,
struct V_406 * V_407 , struct V_10 * V_11 ,
T_2 V_240 , T_7 V_321 ,
T_7 V_450 , struct V_408 * V_409 ,
int V_243 )
{
struct V_93 * V_187 = V_11 -> V_88 ;
struct V_451 V_452 ;
struct V_453 * V_454 ;
struct V_455 * V_456 ;
T_2 V_433 ;
T_7 V_242 , V_457 ;
int V_247 , V_458 = 0 , V_436 = 0 ;
if ( V_321 <= 0 || ( V_321 & ( ~ V_248 ) ) != 0 ||
( V_187 != NULL && F_126 ( & V_187 -> V_101 ) != F_126 ( & V_407 -> V_399 ) ) )
return - V_165 ;
V_242 = V_450 >> V_444 ;
V_457 = V_321 >> V_444 ;
F_61 ( V_454 , V_242 * sizeof( struct V_453 ) ) ;
F_61 ( V_456 , V_242 * sizeof( struct V_455 ) ) ;
if ( V_454 == NULL || V_456 == NULL )
GOTO ( V_150 , V_458 = - V_68 ) ;
if ( V_239 == V_429 && V_243 )
V_436 |= V_445 ;
F_238 ( V_407 , & V_452 ) ;
V_433 = V_240 ;
for(; V_457 ; V_457 -= V_242 ) {
int V_459 ;
if ( V_457 < V_242 )
V_242 = V_457 ;
for ( V_247 = 0 ; V_247 < V_242 ; V_247 ++ , V_433 += V_250 ) {
V_456 [ V_247 ] . V_240 = V_433 ;
V_456 [ V_247 ] . V_460 = V_250 ;
V_456 [ V_247 ] . V_461 = V_436 ;
}
V_452 . V_462 = V_242 ;
V_409 -> V_463 = 0 ;
V_459 = V_242 ;
V_458 = F_239 ( V_26 , V_239 , exp , V_407 , 1 , & V_452 , V_456 , & V_459 ,
V_454 , V_409 , NULL ) ;
if ( V_458 != 0 )
GOTO ( V_150 , V_458 ) ;
F_14 ( V_459 == V_242 ) ;
for ( V_247 = 0 ; V_247 < V_459 ; V_247 ++ ) {
struct V_34 * V_34 = V_454 [ V_247 ] . V_34 ;
if ( V_34 == NULL && V_454 [ V_247 ] . V_117 == 0 )
continue;
if ( V_243 )
V_454 [ V_247 ] . V_461 |= V_445 ;
if ( F_126 ( & V_407 -> V_399 ) == V_437 ||
( V_407 -> V_411 & V_438 ) == 0 ||
( V_407 -> V_439 & V_440 ) == 0 )
continue;
if ( V_239 == V_429 )
F_228 ( V_187 , V_34 , V_239 ,
F_126 ( & V_407 -> V_399 ) ,
V_456 [ V_247 ] . V_240 ,
V_456 [ V_247 ] . V_460 ) ;
else
F_232 ( V_187 , V_34 ,
F_126 ( & V_407 -> V_399 ) ,
V_456 [ V_247 ] . V_240 ,
V_456 [ V_247 ] . V_460 ) ;
}
V_458 = F_240 ( V_26 , V_239 , exp , V_407 , 1 , & V_452 ,
V_456 , V_242 , V_454 , V_409 , V_458 ) ;
if ( V_458 != 0 )
GOTO ( V_150 , V_458 ) ;
memset ( V_409 , 0 , sizeof( * V_409 ) ) ;
F_241 ( (struct V_120 * ) & V_26 -> V_28 ) ;
F_242 ( (struct V_120 * ) & V_26 -> V_28 ) ;
}
V_150:
if ( V_454 )
F_62 ( V_454 , V_242 * sizeof( struct V_453 ) ) ;
if ( V_456 )
F_62 ( V_456 , V_242 * sizeof( struct V_455 ) ) ;
return V_458 ;
}
static int F_243 ( const struct V_25 * V_26 , int V_239 ,
struct V_449 * exp ,
struct V_382 * V_125 ,
struct V_408 * V_464 )
{
struct V_6 * V_7 = F_244 ( exp ) ;
struct V_1 * V_72 = F_4 ( V_7 ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_406 * V_407 = & V_125 -> V_398 ;
struct V_10 * V_11 ;
int V_117 ;
int V_243 = 1 ;
long V_465 ;
F_14 ( V_407 -> V_411 & V_416 ) ;
V_117 = F_224 ( & V_11 , V_72 , V_407 ) ;
if ( V_117 )
return V_117 ;
V_407 -> V_411 &= ~ V_466 ;
V_465 = ( long ) V_125 -> V_467 ;
if ( V_465 == 1 )
V_243 = 0 ;
if ( V_72 -> V_77 == NULL && V_465 != 3 ) {
V_465 = 3 ;
V_125 -> V_468 = V_125 -> V_469 ;
}
if ( V_125 -> V_468 > V_470 )
V_125 -> V_468 = V_470 ;
switch ( V_465 ) {
case 1 :
case 2 :
V_117 = F_234 ( V_72 , V_239 , V_407 ,
V_11 , V_125 -> V_471 ,
V_125 -> V_469 , V_243 , V_464 ) ;
break;
case 3 :
V_117 = F_237 ( V_26 , V_75 -> V_96 , V_239 , V_407 ,
V_11 , V_125 -> V_471 ,
V_125 -> V_469 , V_125 -> V_468 ,
V_464 , V_243 ) ;
break;
default:
V_117 = - V_165 ;
}
F_225 ( V_11 ) ;
return V_117 ;
}
static int
F_245 ( struct V_449 * exp , struct V_406 * V_407 ,
int V_208 , T_2 V_240 , T_7 V_264 )
{
struct V_1 * V_72 = F_4 ( exp -> V_472 ) ;
struct V_244 * V_473 = & V_407 -> V_474 ;
struct V_10 * V_11 ;
T_2 V_207 ;
int V_117 ;
if ( V_72 -> V_77 == NULL )
return - V_475 ;
if ( ! ( V_208 == V_252 || V_208 == V_218 ) )
return - V_165 ;
if ( ( V_240 & ( ~ V_248 ) ) != 0 ||
( V_264 & ( ~ V_248 ) ) != 0 )
return - V_165 ;
V_117 = F_224 ( & V_11 , V_72 , V_407 ) ;
if ( V_117 != 0 )
return V_117 ;
V_207 = ( V_264 == 0 ) ? ( ( T_2 ) - 1 ) : ( V_240 + V_264 - 1 ) ;
V_117 = F_145 ( V_11 , V_240 , V_207 , V_208 , & V_473 -> V_52 ) ;
if ( V_117 == 0 ) {
V_407 -> V_411 |= V_466 ;
F_119 ( V_181 , L_67 V_231 L_16 , V_473 -> V_52 ) ;
}
F_225 ( V_11 ) ;
return V_117 ;
}
static int
F_246 ( struct V_449 * exp , struct V_406 * V_407 )
{
struct V_1 * V_72 = F_4 ( exp -> V_472 ) ;
T_3 V_52 = V_407 -> V_474 . V_52 ;
if ( ( V_407 -> V_411 & V_466 ) == 0 )
return - V_165 ;
F_119 ( V_181 , L_67 V_231 L_16 , V_52 ) ;
return F_152 ( V_72 , V_52 ) ;
}
static int
F_247 ( unsigned int V_476 , struct V_449 * exp , int V_460 ,
void * V_477 , void * V_478 )
{
struct V_6 * V_7 = exp -> V_472 ;
struct V_1 * V_72 = F_4 ( V_7 ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_10 * V_11 ;
struct V_382 * V_125 = V_477 ;
struct V_408 V_464 ;
struct V_25 * V_26 ;
struct V_479 * V_480 ;
struct V_406 * V_407 ;
struct V_188 V_189 ;
int V_239 = V_443 ;
int V_117 = 0 ;
int V_247 ;
memset ( & V_464 , 0 , sizeof( V_464 ) ) ;
V_407 = & V_125 -> V_398 ;
if ( ! ( V_407 -> V_411 & V_416 ) ) {
V_407 -> V_411 |= V_416 ;
F_64 ( & V_407 -> V_399 ) ;
}
V_117 = F_131 ( & V_189 , & V_407 -> V_399 , 0 ) ;
if ( V_117 < 0 )
return V_117 ;
F_91 ( V_26 ) ;
if ( V_26 == NULL )
return - V_68 ;
V_117 = F_248 ( V_26 , V_481 ) ;
if ( V_117 )
GOTO ( V_150 , V_117 = - V_68 ) ;
switch ( V_476 ) {
case V_482 :
if ( ! F_249 ( V_483 ) )
GOTO ( V_150 , V_117 = - V_484 ) ;
V_117 = F_219 ( V_26 , V_72 , 1 , V_407 , V_125 -> V_467 ,
V_125 -> V_468 , & V_464 ) ;
GOTO ( V_150 , V_117 ) ;
case V_485 : {
int V_321 ;
int V_476 ;
char * V_486 = NULL ;
int V_487 ;
T_3 V_273 ;
if ( ! F_249 ( V_483 ) )
GOTO ( V_150 , V_117 = - V_484 ) ;
V_321 = V_125 -> V_469 ;
V_476 = V_125 -> V_488 ;
V_273 = F_126 ( & V_125 -> V_393 . V_399 ) ;
V_487 = V_125 -> V_468 ;
F_61 ( V_486 , V_487 + 1 ) ;
if ( V_486 == NULL )
GOTO ( V_150 , V_117 = - V_68 ) ;
if ( F_172 ( V_486 , V_125 -> V_467 , V_487 ) ) {
F_62 ( V_486 , V_125 -> V_468 + 1 ) ;
GOTO ( V_150 , V_117 = - V_266 ) ;
}
V_117 = F_217 ( V_72 , V_476 , V_486 , V_487 , V_273 , V_321 , V_125 ) ;
F_62 ( V_486 , V_487 + 1 ) ;
GOTO ( V_150 , V_117 ) ;
}
case V_489 : {
struct V_25 * V_490 ;
int V_190 ;
T_3 V_491 ;
int V_492 ;
if ( ! F_249 ( V_483 ) )
GOTO ( V_150 , V_117 = - V_484 ) ;
V_490 = F_129 ( & V_190 ) ;
if ( F_130 ( V_490 ) )
GOTO ( V_150 , V_117 = F_136 ( V_490 ) ) ;
V_117 = F_218 ( V_490 , V_384 ,
V_385 ) ;
if ( V_117 != 0 ) {
F_134 ( V_490 , & V_190 ) ;
GOTO ( V_150 , V_117 ) ;
}
V_117 = F_250 ( V_490 , V_72 -> V_133 , & V_491 ) ;
F_134 ( V_490 , & V_190 ) ;
if ( V_117 < 0 ) {
F_79 ( L_68 ,
V_7 -> V_129 , V_117 ) ;
GOTO ( V_150 , V_117 ) ;
}
if ( F_170 ( V_125 -> V_467 , & V_491 , V_125 -> V_468 ) )
return - V_266 ;
V_492 = V_493 ;
if ( F_170 ( V_125 -> V_389 , & V_492 ,
V_125 -> V_383 ) )
return - V_266 ;
GOTO ( V_150 , V_117 ) ;
}
case V_494 :
if ( ! F_249 ( V_483 ) )
GOTO ( V_150 , V_117 = - V_484 ) ;
V_117 = F_224 ( & V_11 , V_72 , V_407 ) ;
if ( V_117 == 0 ) {
V_117 = F_223 ( V_26 , V_75 -> V_96 , V_407 , V_11 -> V_88 ,
& V_464 , NULL , NULL ) ;
if ( V_117 == 0 )
V_11 -> V_182 = 1 ;
F_225 ( V_11 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_495 :
V_117 = F_224 ( & V_11 , V_72 , V_407 ) ;
if ( V_117 == 0 ) {
struct V_496 V_195 = { { { 0 } } } ;
V_195 . V_497 = V_11 -> V_88 ;
V_195 . V_498 = V_407 ;
V_117 = F_251 ( V_26 , V_75 -> V_96 , & V_195 ) ;
F_225 ( V_11 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_499 :
if ( ! F_249 ( V_483 ) )
GOTO ( V_150 , V_117 = - V_484 ) ;
V_117 = F_224 ( & V_11 , V_72 , V_407 ) ;
if ( V_117 == 0 ) {
struct V_496 V_195 = { { { 0 } } } ;
V_195 . V_498 = V_407 ;
V_195 . V_497 = V_11 -> V_88 ;
V_117 = F_252 ( V_26 , V_75 -> V_96 , & V_195 , NULL ) ;
F_225 ( V_11 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_500 :
if ( ! F_249 ( V_483 ) )
GOTO ( V_150 , V_117 = - V_484 ) ;
V_239 = V_429 ;
case V_501 :
V_117 = F_243 ( V_26 , V_239 , exp , V_125 , & V_464 ) ;
GOTO ( V_150 , V_117 ) ;
case V_502 :
V_117 = F_224 ( & V_11 , V_72 , V_407 ) ;
if ( V_117 == 0 ) {
V_117 = F_168 ( V_11 -> V_88 , V_125 -> V_467 ,
V_125 -> V_468 ) ;
F_225 ( V_11 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_503 :
if ( ! F_249 ( V_483 ) )
GOTO ( V_150 , V_117 = - V_484 ) ;
if ( V_125 -> V_467 == NULL ) {
V_117 = F_224 ( & V_11 , V_72 , V_407 ) ;
if ( V_117 == 0 ) {
V_11 -> V_182 = 1 ;
F_225 ( V_11 ) ;
}
} else {
V_117 = F_219 ( V_26 , V_72 , 0 , V_407 ,
V_125 -> V_467 ,
V_125 -> V_468 , & V_464 ) ;
}
GOTO ( V_150 , V_117 ) ;
case V_504 :
if ( ! F_249 ( V_483 ) )
GOTO ( V_150 , V_117 = - V_484 ) ;
V_117 = F_245 ( exp , V_407 ,
V_125 -> V_505 ,
V_125 -> V_471 ,
V_125 -> V_469 ) ;
GOTO ( V_150 , V_117 ) ;
case V_506 :
V_117 = F_246 ( exp , V_407 ) ;
GOTO ( V_150 , V_117 ) ;
default:
F_79 ( L_69 , V_476 ) ;
GOTO ( V_150 , V_117 = - V_507 ) ;
}
V_150:
F_253 ( V_26 ) ;
F_93 ( V_26 ) ;
for ( V_480 = V_464 . V_508 , V_247 = 0 ; V_247 < 4 ;
V_247 ++ , V_480 ++ ) {
if ( ! V_480 -> V_208 )
break;
F_254 ( & V_480 -> V_62 , V_480 -> V_208 ) ;
}
return V_117 ;
}
static int F_100 ( const struct V_25 * V_26 ,
struct V_6 * V_140 , struct V_143 * V_509 )
{
struct V_74 * V_75 = & V_140 -> V_159 . V_160 ;
struct V_6 * V_147 ;
struct V_510 V_511 = { L_70 } ;
struct V_512 * V_513 = NULL ;
int V_117 ;
if ( V_509 -> V_514 < 2 || F_255 ( V_509 , 1 ) < 1 ) {
F_79 ( L_71 ) ;
return - V_165 ;
}
V_147 = F_98 ( F_99 ( V_509 , 1 ) ) ;
if ( ! V_147 || ! V_147 -> V_515 || ! V_147 -> V_516 ) {
F_79 ( L_72 ,
F_99 ( V_509 , 1 ) ) ;
return - V_165 ;
}
F_256 ( & V_75 -> V_90 ) ;
F_47 ( & V_75 -> V_92 ) ;
F_47 ( & V_75 -> V_184 ) ;
V_75 -> V_225 = 0 ;
V_75 -> V_267 = 0 ;
if ( ! strcmp ( V_147 -> V_156 -> V_157 , V_158 ) ) {
F_257 ( V_384 ) ;
F_258 ( V_385 ) ;
return 0 ;
}
F_61 ( V_513 , sizeof( * V_513 ) ) ;
if ( V_513 == NULL ) {
F_79 ( L_73 ,
F_99 ( V_509 , 1 ) ) ;
return - V_68 ;
}
V_513 -> V_517 = V_518 | V_519 |
V_520 |
V_521 | V_522 |
V_523 | V_524 |
V_525 ;
V_513 -> V_526 = V_527 ;
V_513 -> V_528 = V_529 ;
V_513 -> V_530 = V_192 ;
V_117 = F_259 ( V_26 , & V_75 -> V_96 , V_147 , & V_511 , V_513 , NULL ) ;
if ( V_117 == 0 ) {
F_55 ( & V_147 -> V_531 ) ;
F_69 ( & V_75 -> V_96 -> V_532 ) ;
F_57 ( & V_147 -> V_531 ) ;
}
F_62 ( V_513 , sizeof( * V_513 ) ) ;
if ( V_117 != 0 ) {
F_79 ( L_74 ,
F_99 ( V_509 , 1 ) ) ;
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
F_260 ( V_384 ) ;
F_261 ( V_385 ) ;
return 0 ;
}
if ( ! F_33 ( & V_140 -> V_533 ) ) {
F_79 ( L_75 ) ;
return - V_45 ;
}
F_14 ( F_68 ( & V_75 -> V_96 -> V_534 ) > 0 ) ;
V_117 = F_262 ( V_75 -> V_96 ) ;
if ( V_117 != 0 )
F_79 ( L_76 , V_117 ) ;
return V_117 ;
}
static int F_263 ( const struct V_25 * V_26 ,
struct V_449 * * exp ,
struct V_6 * V_535 , struct V_510 * V_536 ,
struct V_512 * V_125 , void * V_537 )
{
int V_117 ;
struct V_244 V_538 = { 0 } ;
V_117 = F_264 ( & V_538 , V_535 , V_536 ) ;
if ( V_117 == 0 ) {
* exp = F_265 ( & V_538 ) ;
}
return V_117 ;
}
static int F_266 ( struct V_449 * exp )
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
CDEBUG (D_INFO, "Cancel lock on object "LPX64" on disconnect "
"(%d)\n", ecl->ecl_object->eco_id, rc);
echo_put_object (ecl->ecl_object);
OBD_FREE (ecl, sizeof (*ecl));
}
#endif
V_117 = F_267 ( exp ) ;
GOTO ( V_150 , V_117 ) ;
V_150:
return V_117 ;
}
int F_268 ( void )
{
struct V_539 V_540 = { 0 } ;
int V_117 ;
F_269 ( & V_540 ) ;
V_117 = F_270 ( V_541 ) ;
if ( V_117 == 0 ) {
V_117 = F_271 ( & V_542 , NULL ,
V_540 . V_543 ,
V_54 ,
& V_223 ) ;
if ( V_117 )
F_272 ( V_541 ) ;
}
return V_117 ;
}
void F_273 ( void )
{
F_274 ( V_54 ) ;
F_272 ( V_541 ) ;
}
static int T_9 F_275 ( void )
{
struct V_539 V_540 ;
int V_117 ;
F_276 ( L_77 ) ;
F_14 ( V_250 % V_428 == 0 ) ;
F_269 ( & V_540 ) ;
V_117 = F_268 () ;
return V_117 ;
}
static void F_277 ( void )
{
F_273 () ;
}
