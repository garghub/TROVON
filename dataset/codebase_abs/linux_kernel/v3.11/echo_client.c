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
V_51 ;
F_28 ( & V_11 -> V_52 ) ;
F_29 ( V_50 ) ;
EXIT ;
}
static int F_30 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 ,
struct V_37 * V_43 )
{
return 0 ;
}
static int F_31 ( const struct V_25 * V_26 ,
const struct V_15 * V_35 ,
void * V_53 , T_1 V_54 )
{
struct V_14 * V_40 = F_9 ( V_35 ) ;
(* V_54)( V_26 , V_53 , V_55 L_1 ,
V_40 , F_21 ( & V_40 -> V_41 ) , V_40 -> V_36 ) ;
return 0 ;
}
static void F_32 ( const struct V_25 * V_26 ,
struct V_19 * V_35 )
{
struct V_18 * V_22 = F_10 ( V_35 ) ;
F_14 ( F_33 ( & V_22 -> V_56 ) ) ;
F_34 ( V_22 , V_57 ) ;
}
static void F_35 ( const struct V_25 * V_26 ,
const struct V_19 * V_35 )
{
struct V_18 * V_22 = F_10 ( V_35 ) ;
F_14 ( F_33 ( & V_22 -> V_56 ) ) ;
}
static int F_36 ( const struct V_25 * V_26 ,
const struct V_19 * V_35 ,
const struct V_58 * V_59 ,
const struct V_37 * V_43 )
{
return 1 ;
}
static int F_37 ( const struct V_25 * V_26 , struct V_9 * V_60 ,
struct V_61 * V_34 , struct V_34 * V_50 )
{
struct V_14 * V_40 = F_38 ( V_60 , V_34 ) ;
struct V_10 * V_11 = F_7 ( V_60 ) ;
V_51 ;
V_40 -> V_36 = V_50 ;
F_39 ( V_50 ) ;
F_40 ( & V_40 -> V_41 ) ;
F_41 ( V_34 , & V_40 -> V_17 , V_60 , & V_62 ) ;
F_42 ( & V_11 -> V_52 ) ;
RETURN ( 0 ) ;
}
static int F_43 ( const struct V_25 * V_26 , struct V_9 * V_60 ,
struct V_37 * V_38 )
{
return 0 ;
}
static int F_44 ( const struct V_25 * V_26 ,
struct V_9 * V_60 , struct V_21 * V_63 ,
const struct V_37 * V_43 )
{
struct V_18 * V_64 ;
V_51 ;
F_45 ( V_64 , V_57 , V_65 ) ;
if ( V_64 != NULL ) {
F_46 ( V_63 , & V_64 -> V_20 , V_60 , & V_66 ) ;
V_64 -> V_67 = F_7 ( V_60 ) ;
F_47 ( & V_64 -> V_56 ) ;
F_48 ( & V_64 -> V_68 , 0 ) ;
}
RETURN ( V_64 == NULL ? - V_69 : 0 ) ;
}
static int F_49 ( const struct V_25 * V_26 , struct V_9 * V_60 ,
const struct V_31 * V_70 )
{
return 0 ;
}
static int F_50 ( const struct V_25 * V_26 , struct V_71 * V_60 ,
const struct V_72 * V_70 )
{
struct V_1 * V_73 = F_1 ( F_5 ( V_60 -> V_74 ) ) ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_10 * V_11 = F_7 ( F_51 ( V_60 ) ) ;
V_51 ;
if ( V_73 -> V_78 ) {
struct V_71 * V_79 ;
struct V_80 * V_81 ;
V_81 = V_73 -> V_78 ;
V_79 = V_81 -> V_82 -> V_83 ( V_26 , V_60 -> V_84 ,
V_81 ) ;
if ( V_79 == NULL )
RETURN ( - V_69 ) ;
F_52 ( V_60 , V_79 ) ;
}
if ( ! V_73 -> V_85 ) {
const struct V_31 * V_86 = F_53 ( V_70 ) ;
struct V_30 * V_87 = F_15 ( V_86 ) ;
F_14 ( V_87 -> V_88 ) ;
V_11 -> V_89 = * V_87 -> V_88 ;
* V_87 -> V_88 = NULL ;
} else {
V_11 -> V_89 = NULL ;
}
V_11 -> V_90 = V_73 ;
F_48 ( & V_11 -> V_52 , 0 ) ;
F_54 ( F_51 ( V_60 ) , sizeof( struct V_14 ) ) ;
F_55 ( & V_76 -> V_91 ) ;
F_56 ( & V_11 -> V_92 , & V_76 -> V_93 ) ;
F_57 ( & V_76 -> V_91 ) ;
RETURN ( 0 ) ;
}
static int F_58 ( struct V_1 * V_73 ,
struct V_94 * * V_95 )
{
int V_96 ;
V_51 ;
if ( V_73 -> V_78 != NULL )
return F_59 ( V_73 -> V_77 -> V_97 , V_95 ) ;
V_96 = F_60 ( 1 ) ;
F_14 ( * V_95 == NULL ) ;
F_61 ( * V_95 , V_96 ) ;
if ( * V_95 == NULL )
RETURN ( - V_69 ) ;
F_61 ( ( * V_95 ) -> V_98 [ 0 ] , sizeof( struct V_99 ) ) ;
if ( ( * V_95 ) -> V_98 [ 0 ] == NULL ) {
F_62 ( * V_95 , V_96 ) ;
RETURN ( - V_69 ) ;
}
F_63 ( ( * V_95 ) -> V_98 [ 0 ] ) ;
( * V_95 ) -> V_100 = V_101 ;
F_64 ( & ( * V_95 ) -> V_102 ) ;
RETURN ( V_96 ) ;
}
static int F_65 ( struct V_1 * V_73 , struct V_94 * * V_95 )
{
int V_96 ;
V_51 ;
if ( V_73 -> V_78 != NULL )
return F_66 ( V_73 -> V_77 -> V_97 , V_95 ) ;
V_96 = F_60 ( 1 ) ;
F_14 ( * V_95 != NULL ) ;
F_62 ( ( * V_95 ) -> V_98 [ 0 ] , sizeof( struct V_99 ) ) ;
F_62 ( * V_95 , V_96 ) ;
* V_95 = NULL ;
RETURN ( 0 ) ;
}
static void F_67 ( const struct V_25 * V_26 , struct V_71 * V_60 )
{
struct V_10 * V_11 = F_7 ( F_51 ( V_60 ) ) ;
struct V_75 * V_76 = V_11 -> V_90 -> V_77 ;
V_51 ;
F_14 ( F_68 ( & V_11 -> V_52 ) == 0 ) ;
F_55 ( & V_76 -> V_91 ) ;
F_69 ( & V_11 -> V_92 ) ;
F_57 ( & V_76 -> V_91 ) ;
F_70 ( V_60 ) ;
F_71 ( V_60 -> V_84 ) ;
if ( V_11 -> V_89 )
F_65 ( V_11 -> V_90 , & V_11 -> V_89 ) ;
F_34 ( V_11 , V_103 ) ;
EXIT ;
}
static int F_72 ( const struct V_25 * V_26 , void * V_53 ,
T_1 V_104 , const struct V_71 * V_13 )
{
struct V_10 * V_60 = F_7 ( F_51 ( V_13 ) ) ;
return (* V_104)( V_26 , V_53 , L_2 , V_60 ) ;
}
static struct V_71 * F_73 ( const struct V_25 * V_26 ,
const struct V_105 * V_106 ,
struct V_80 * V_3 )
{
struct V_10 * V_11 ;
struct V_71 * V_60 = NULL ;
V_51 ;
F_14 ( V_106 == NULL ) ;
F_45 ( V_11 , V_103 , V_65 ) ;
if ( V_11 != NULL ) {
struct V_107 * V_106 = & V_11 -> V_108 ;
V_60 = & F_6 ( V_11 ) -> V_109 ;
F_74 ( V_106 ) ;
F_75 ( V_60 , & V_106 -> V_110 , V_3 ) ;
F_76 ( & V_106 -> V_110 , V_60 ) ;
V_11 -> V_12 . V_111 = & V_112 ;
V_60 -> V_113 = & V_114 ;
}
RETURN ( V_60 ) ;
}
static int F_77 ( const struct V_25 * V_26 , struct V_1 * V_73 )
{
struct V_115 * V_116 = & V_73 -> V_117 ;
int V_118 ;
V_118 = F_78 ( V_116 , & V_73 -> V_4 ) ;
if ( V_118 ) {
F_79 ( L_3 , V_118 ) ;
return V_118 ;
}
V_118 = F_80 ( & V_116 -> V_119 ) ;
if ( V_118 )
return V_118 ;
V_73 -> V_120 = V_116 ;
return 0 ;
}
static void F_81 ( const struct V_25 * V_26 , struct V_1 * V_73 )
{
if ( V_73 -> V_120 ) {
if ( ! V_73 -> V_85 )
F_82 ( V_73 -> V_120 ) ;
V_73 -> V_120 = NULL ;
}
}
static void * F_83 ( const struct V_121 * V_122 ,
struct V_123 * V_124 )
{
struct V_24 * V_27 ;
F_45 ( V_27 , V_125 , V_65 ) ;
if ( V_27 == NULL )
V_27 = F_84 ( - V_69 ) ;
return V_27 ;
}
static void F_85 ( const struct V_121 * V_122 ,
struct V_123 * V_124 , void * V_126 )
{
struct V_24 * V_27 = V_126 ;
F_34 ( V_27 , V_125 ) ;
}
static void F_86 ( const struct V_121 * V_122 ,
struct V_123 * V_124 , void * V_126 )
{
}
static void * F_87 ( const struct V_121 * V_122 ,
struct V_123 * V_124 )
{
struct V_127 * V_128 ;
F_45 ( V_128 , V_129 , V_65 ) ;
if ( V_128 == NULL )
V_128 = F_84 ( - V_69 ) ;
return V_128 ;
}
static void F_88 ( const struct V_121 * V_122 ,
struct V_123 * V_124 , void * V_126 )
{
struct V_127 * V_128 = V_126 ;
F_34 ( V_128 , V_129 ) ;
}
static void F_89 ( const struct V_121 * V_122 ,
struct V_123 * V_124 , void * V_126 )
{
}
static int F_90 ( struct V_1 * V_73 , char * V_130 ,
struct V_131 * V_132 )
{
char * V_133 ;
int V_118 ;
V_51 ;
F_91 ( V_73 -> V_134 ) ;
if ( V_73 -> V_134 == NULL )
RETURN ( - V_69 ) ;
F_61 ( V_133 , V_135 + 5 ) ;
if ( V_133 == NULL )
GOTO ( V_136 , V_118 = - V_69 ) ;
snprintf ( V_133 , V_135 + 5 , L_4 , V_130 ) ;
V_118 = F_92 ( V_73 -> V_134 , NULL ,
V_137 ,
V_133 , V_132 -> V_138 ) ;
V_73 -> V_134 -> V_139 = V_140 ;
F_62 ( V_133 , V_135 + 5 ) ;
if ( V_118 )
GOTO ( V_136 , V_118 ) ;
RETURN ( 0 ) ;
V_136:
F_93 ( V_73 -> V_134 ) ;
V_73 -> V_134 = NULL ;
RETURN ( V_118 ) ;
}
static int F_94 ( struct V_6 * V_141 )
{
struct V_1 * V_73 = F_4 ( V_141 ) ;
V_51 ;
if ( V_73 -> V_134 != NULL ) {
F_95 ( V_73 -> V_134 ) ;
F_93 ( V_73 -> V_134 ) ;
V_73 -> V_134 = NULL ;
}
RETURN ( 0 ) ;
}
static struct V_80 * F_96 ( const struct V_25 * V_26 ,
struct V_142 * V_143 ,
struct V_144 * V_145 )
{
struct V_80 * V_146 ;
struct V_1 * V_73 ;
struct V_2 * V_147 ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_148 ;
const char * V_149 ;
int V_118 ;
int V_150 = 0 ;
V_51 ;
F_91 ( V_73 ) ;
if ( V_73 == NULL )
GOTO ( V_151 , V_118 = - V_69 ) ;
V_150 = 1 ;
V_147 = & V_73 -> V_4 ;
V_118 = F_97 ( V_147 , V_143 ) ;
if ( V_118 )
GOTO ( V_151 , V_118 ) ;
V_147 -> V_152 . V_82 = & V_153 ;
V_147 -> V_154 = & V_155 ;
V_150 = 2 ;
V_7 = F_98 ( F_99 ( V_145 , 0 ) ) ;
F_14 ( V_7 != NULL ) ;
F_14 ( V_26 != NULL ) ;
V_148 = F_98 ( F_99 ( V_145 , 1 ) ) ;
if ( V_148 == NULL ) {
F_79 ( L_5 ,
F_99 ( V_145 , 1 ) ) ;
GOTO ( V_151 , V_118 = - V_156 ) ;
}
V_146 = V_148 -> V_8 ;
if ( ! strcmp ( V_148 -> V_157 -> V_158 , V_159 ) ) {
V_73 -> V_85 = 1 ;
} else {
V_73 -> V_85 = 0 ;
V_118 = F_77 ( V_26 , V_73 ) ;
if ( V_118 )
GOTO ( V_151 , V_118 ) ;
}
V_150 = 3 ;
V_118 = F_100 ( V_26 , V_7 , V_145 ) ;
if ( V_118 )
GOTO ( V_151 , V_118 ) ;
V_73 -> V_77 = & V_7 -> V_160 . V_161 ;
V_150 = 4 ;
if ( V_73 -> V_85 ) {
struct V_162 * V_163 ;
struct V_80 * V_164 ;
int V_165 = 0 ;
if ( V_146 == NULL ) {
F_79 ( L_6 ,
F_99 ( V_145 , 1 ) ) ;
GOTO ( V_151 , V_118 = - V_166 ) ;
}
V_149 = F_99 ( V_145 , 2 ) ;
if ( ! V_149 ) {
F_79 ( L_7 ,
F_99 ( V_145 , 1 ) ,
V_148 -> V_157 -> V_158 ) ;
GOTO ( V_151 , V_118 = - V_166 ) ;
}
V_163 = V_146 -> V_167 ;
F_55 ( & V_163 -> V_168 ) ;
F_101 (ld, &ls->ls_ld_linkage, ld_linkage) {
if ( strcmp ( V_164 -> V_169 -> V_170 , V_149 ) == 0 ) {
V_165 = 1 ;
break;
}
}
F_57 ( & V_163 -> V_168 ) ;
if ( V_165 == 0 ) {
F_79 ( L_6 ,
F_99 ( V_145 , 1 ) ) ;
GOTO ( V_151 , V_118 = - V_166 ) ;
}
V_146 = V_164 ;
V_73 -> V_117 . V_119 = * V_163 ;
V_73 -> V_120 = & V_73 -> V_117 ;
V_73 -> V_4 . V_152 . V_167 = & V_73 -> V_117 . V_119 ;
V_118 = F_90 ( V_73 , V_7 -> V_130 , F_102 ( V_163 ) ) ;
if ( V_118 ) {
F_79 ( L_8 , V_118 ) ;
GOTO ( V_151 , V_118 ) ;
}
} else {
if ( V_146 != NULL && ! F_103 ( V_146 ) )
V_146 = NULL ;
V_149 = V_148 -> V_157 -> V_158 ;
if ( V_146 != NULL ) {
F_14 ( V_146 != NULL ) ;
if ( V_146 -> V_167 != NULL )
GOTO ( V_151 , V_118 = - V_45 ) ;
V_146 -> V_167 = & V_73 -> V_120 -> V_119 ;
V_118 = V_146 -> V_169 -> V_171 -> V_172 ( V_26 , V_146 ,
V_146 -> V_169 -> V_170 ,
NULL ) ;
if ( V_118 )
GOTO ( V_151 , V_118 ) ;
if ( strcmp ( V_149 , V_173 ) == 0 )
V_73 -> V_174 = 1 ;
else
F_14 ( strcmp ( V_149 ,
V_175 ) == 0 ) ;
} else
F_14 ( strcmp ( V_149 , V_176 ) == 0 ) ;
}
V_73 -> V_78 = V_146 ;
RETURN ( & V_147 -> V_152 ) ;
V_151:
switch( V_150 ) {
case 4 : {
int V_177 ;
V_177 = F_104 ( V_7 ) ;
if ( V_177 )
F_79 ( L_9 ,
V_7 -> V_130 , V_177 ) ;
}
case 3 :
F_81 ( V_26 , V_73 ) ;
case 2 :
F_105 ( & V_73 -> V_4 ) ;
case 1 :
F_93 ( V_73 ) ;
case 0 :
default:
break;
}
return ( F_84 ( V_118 ) ) ;
}
static int F_106 ( const struct V_25 * V_26 , struct V_80 * V_5 ,
const char * V_178 , struct V_80 * V_146 )
{
F_107 () ;
return 0 ;
}
static struct V_80 * F_108 ( const struct V_25 * V_26 ,
struct V_80 * V_5 )
{
struct V_1 * V_73 = F_1 ( F_5 ( V_5 ) ) ;
struct V_80 * V_146 = V_73 -> V_78 ;
while ( V_146 && ! V_73 -> V_85 )
V_146 = V_146 -> V_169 -> V_171 -> V_179 ( V_26 , V_146 ) ;
return NULL ;
}
static void F_109 ( const struct V_25 * V_26 ,
struct V_18 * V_22 ,
int V_180 )
{
struct V_21 * V_181 = F_11 ( V_22 ) ;
F_110 ( V_181 ) ;
F_111 ( V_26 , V_181 ) ;
F_112 ( V_26 , V_181 , L_10 , V_22 -> V_67 ) ;
if ( ! V_180 ) {
F_113 ( V_26 , V_181 ) ;
F_114 ( V_26 , V_181 ) ;
F_115 ( V_26 , V_181 ) ;
F_116 ( V_26 , V_181 ) ;
}
F_117 ( V_26 , V_181 ) ;
}
static struct V_80 * F_118 ( const struct V_25 * V_26 ,
struct V_80 * V_5 )
{
struct V_1 * V_73 = F_1 ( F_5 ( V_5 ) ) ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_10 * V_11 ;
struct V_80 * V_146 = V_73 -> V_78 ;
F_119 ( V_182 , L_11 ,
V_73 , V_146 ) ;
F_120 ( V_26 , & V_73 -> V_120 -> V_119 , - 1 ) ;
F_55 ( & V_76 -> V_91 ) ;
F_101 (eco, &ec->ec_objects, eo_obj_chain)
V_11 -> V_183 = 1 ;
F_57 ( & V_76 -> V_91 ) ;
F_120 ( V_26 , & V_73 -> V_120 -> V_119 , - 1 ) ;
F_119 ( V_182 ,
L_12 ) ;
F_55 ( & V_76 -> V_91 ) ;
while ( ! F_33 ( & V_76 -> V_93 ) ) {
F_57 ( & V_76 -> V_91 ) ;
F_79 ( L_13
L_14 ) ;
F_121 ( V_184 ,
F_122 ( 1 ) ) ;
F_120 ( V_26 , & V_73 -> V_120 -> V_119 , - 1 ) ;
F_55 ( & V_76 -> V_91 ) ;
}
F_57 ( & V_76 -> V_91 ) ;
F_14 ( F_33 ( & V_76 -> V_185 ) ) ;
F_119 ( V_182 , L_15 ) ;
F_104 ( V_5 -> V_186 ) ;
F_94 ( V_5 -> V_186 ) ;
while ( V_146 && ! V_73 -> V_85 )
V_146 = V_146 -> V_169 -> V_171 -> V_187 ( V_26 , V_146 ) ;
F_14 ( V_73 -> V_120 == F_123 ( V_5 -> V_167 ) ) ;
F_81 ( V_26 , V_73 ) ;
F_105 ( & V_73 -> V_4 ) ;
F_93 ( V_73 ) ;
return NULL ;
}
static struct V_10 * F_124 ( struct V_1 * V_5 ,
struct V_94 * * V_95 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_30 * V_70 ;
struct V_94 * V_188 ;
struct V_10 * V_11 ;
struct V_9 * V_60 ;
struct V_189 * V_190 ;
int V_191 ;
int V_118 ;
V_51 ;
F_14 ( V_95 ) ;
V_188 = * V_95 ;
F_14 ( V_188 ) ;
F_125 ( F_126 ( & V_188 -> V_102 ) != 0 , V_192 L_16 , F_127 ( & V_188 -> V_102 ) ) ;
F_125 ( F_128 ( & V_188 -> V_102 ) == V_193 , V_192 L_16 ,
F_127 ( & V_188 -> V_102 ) ) ;
if ( F_3 ( V_5 ) -> V_152 . V_186 -> V_194 )
RETURN ( F_84 ( - V_156 ) ) ;
V_26 = F_129 ( & V_191 ) ;
if ( F_130 ( V_26 ) )
RETURN ( ( void * ) V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_70 = & V_27 -> V_195 ;
if ( V_5 -> V_78 ) {
if ( ! V_5 -> V_174 ) {
struct V_99 * V_196 = V_188 -> V_98 [ 0 ] ;
F_14 ( V_196 != NULL ) ;
V_196 -> V_197 = V_188 -> V_102 ;
V_70 -> V_33 . V_160 . V_198 = V_196 ;
} else {
struct V_199 * V_200 ;
V_200 = & V_27 -> V_201 ;
memset ( V_200 , 0 , sizeof *V_200 ) ;
V_200 -> V_188 = V_188 ;
V_70 -> V_33 . V_160 . V_202 = V_200 ;
}
}
V_70 -> V_88 = V_95 ;
V_190 = & V_27 -> V_203 ;
V_118 = F_131 ( V_190 , & V_188 -> V_102 , 0 ) ;
if ( V_118 != 0 )
GOTO ( V_151 , V_11 = F_84 ( V_118 ) ) ;
V_60 = F_132 ( V_26 , F_3 ( V_5 ) , V_190 , & V_70 -> V_33 ) ;
if ( F_130 ( V_60 ) )
GOTO ( V_151 , V_11 = ( void * ) V_60 ) ;
V_11 = F_7 ( V_60 ) ;
if ( V_11 -> V_183 ) {
F_133 ( V_26 , V_60 ) ;
V_11 = F_84 ( - V_42 ) ;
}
V_151:
F_134 ( V_26 , & V_191 ) ;
RETURN ( V_11 ) ;
}
static int F_135 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
struct V_9 * V_60 = F_6 ( V_11 ) ;
int V_191 ;
V_51 ;
V_26 = F_129 ( & V_191 ) ;
if ( F_130 ( V_26 ) )
RETURN ( F_136 ( V_26 ) ) ;
if ( V_11 -> V_183 ) {
struct V_105 * V_204 = V_60 -> V_109 . V_84 ;
F_14 ( & V_11 -> V_108 == F_137 ( V_204 ) ) ;
F_138 ( V_205 , & V_204 -> V_206 ) ;
}
F_133 ( V_26 , V_60 ) ;
F_134 ( V_26 , & V_191 ) ;
RETURN ( 0 ) ;
}
static int F_139 ( struct V_25 * V_26 , struct V_10 * V_11 ,
T_2 V_207 , T_2 V_208 , int V_209 ,
T_3 * V_53 , T_4 V_210 )
{
struct V_37 * V_38 ;
struct V_21 * V_211 ;
struct V_9 * V_60 ;
struct V_58 * V_212 ;
struct V_24 * V_27 ;
int V_118 = - V_69 ;
V_51 ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_213 ;
V_212 = & V_27 -> V_214 ;
V_60 = F_6 ( V_11 ) ;
V_212 -> V_215 = V_60 ;
V_212 -> V_216 = F_140 ( V_60 , V_207 ) ;
V_212 -> V_217 = F_140 ( V_60 , V_208 ) ;
V_212 -> V_218 = V_209 == V_219 ? V_220 : V_221 ;
V_212 -> V_222 = V_210 ;
V_38 -> V_223 = V_60 ;
V_211 = F_141 ( V_26 , V_38 , V_212 , L_10 , V_11 ) ;
if ( V_211 ) {
struct V_75 * V_76 = V_11 -> V_90 -> V_77 ;
struct V_18 * V_64 ;
V_118 = F_142 ( V_26 , V_211 ) ;
if ( V_118 == 0 ) {
V_64 = F_10 ( F_143 ( V_211 , & V_224 ) ) ;
F_55 ( & V_76 -> V_91 ) ;
if ( F_33 ( & V_64 -> V_56 ) ) {
F_144 ( & V_64 -> V_56 , & V_76 -> V_185 ) ;
V_64 -> V_225 = ++ V_76 -> V_226 ;
}
F_42 ( & V_64 -> V_68 ) ;
* V_53 = V_64 -> V_225 ;
F_57 ( & V_76 -> V_91 ) ;
} else {
F_112 ( V_26 , V_211 , L_10 , V_227 ) ;
}
}
RETURN ( V_118 ) ;
}
static int F_145 ( struct V_10 * V_11 , T_2 V_207 , T_2 V_208 ,
int V_209 , T_3 * V_53 )
{
struct V_24 * V_27 ;
struct V_25 * V_26 ;
struct V_37 * V_38 ;
int V_191 ;
int V_228 ;
V_51 ;
V_26 = F_129 ( & V_191 ) ;
if ( F_130 ( V_26 ) )
RETURN ( F_136 ( V_26 ) ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_213 ;
V_38 -> V_229 = 1 ;
V_228 = F_146 ( V_26 , V_38 , V_230 , F_6 ( V_11 ) ) ;
if ( V_228 < 0 )
GOTO ( V_151 , V_228 ) ;
F_14 ( V_228 == 0 ) ;
V_228 = F_139 ( V_26 , V_11 , V_207 , V_208 , V_209 , V_53 , 0 ) ;
F_147 ( V_26 , V_38 ) ;
EXIT ;
V_151:
F_134 ( V_26 , & V_191 ) ;
return V_228 ;
}
static int F_148 ( struct V_25 * V_26 , struct V_1 * V_73 ,
T_3 V_53 )
{
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_18 * V_22 = NULL ;
struct V_231 * V_64 ;
int V_165 = 0 , V_180 = 0 ;
V_51 ;
F_14 ( V_76 != NULL ) ;
F_55 ( & V_76 -> V_91 ) ;
F_149 (el, &ec->ec_locks) {
V_22 = F_150 ( V_64 , struct V_18 , V_56 ) ;
F_119 ( V_182 , L_17 V_232 L_16 , V_22 , V_22 -> V_225 ) ;
V_165 = ( V_22 -> V_225 == V_53 ) ;
if ( V_165 ) {
if ( F_151 ( & V_22 -> V_68 ) )
F_69 ( & V_22 -> V_56 ) ;
else
V_180 = 1 ;
break;
}
}
F_57 ( & V_76 -> V_91 ) ;
if ( ! V_165 )
RETURN ( - V_233 ) ;
F_109 ( V_26 , V_22 , V_180 ) ;
RETURN ( 0 ) ;
}
static int F_152 ( struct V_1 * V_73 , T_3 V_53 )
{
struct V_25 * V_26 ;
int V_191 ;
int V_118 ;
V_51 ;
V_26 = F_129 ( & V_191 ) ;
if ( F_130 ( V_26 ) )
RETURN ( F_136 ( V_26 ) ) ;
V_118 = F_148 ( V_26 , V_73 , V_53 ) ;
F_134 ( V_26 , & V_191 ) ;
RETURN ( V_118 ) ;
}
static int F_153 ( const struct V_25 * V_26 , struct V_37 * V_38 ,
enum V_234 V_43 , struct V_235 * V_236 )
{
struct V_61 * V_237 ;
struct V_61 * V_238 ;
int V_228 = 0 ;
V_51 ;
F_154 (clp, temp, &queue->c2_qin) {
int V_118 ;
V_118 = F_155 ( V_26 , V_38 , V_237 , V_239 ) ;
if ( V_118 == 0 )
continue;
V_228 = V_228 ? : V_118 ;
}
RETURN ( V_228 ) ;
}
static int F_156 ( struct V_10 * V_11 , int V_240 , T_2 V_241 ,
struct V_34 * * V_242 , int V_243 , int V_244 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_9 * V_60 = F_6 ( V_11 ) ;
struct V_1 * V_73 = V_11 -> V_90 ;
struct V_235 * V_236 ;
struct V_37 * V_38 ;
struct V_61 * V_237 ;
struct V_245 V_246 = { 0 } ;
int V_247 = F_157 ( V_60 ) ;
int V_191 ;
int V_118 ;
int V_248 ;
V_51 ;
F_14 ( ( V_241 & ~ V_249 ) == 0 ) ;
F_14 ( V_73 -> V_78 != NULL ) ;
V_26 = F_129 ( & V_191 ) ;
if ( F_130 ( V_26 ) )
RETURN ( F_136 ( V_26 ) ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_213 ;
V_236 = & V_27 -> V_250 ;
F_158 ( V_236 ) ;
V_38 -> V_229 = 1 ;
V_118 = F_146 ( V_26 , V_38 , V_230 , V_60 ) ;
if ( V_118 < 0 )
GOTO ( V_151 , V_118 ) ;
F_14 ( V_118 == 0 ) ;
V_118 = F_139 ( V_26 , V_11 , V_241 ,
V_241 + V_243 * V_251 - 1 ,
V_240 == V_252 ? V_253 : V_219 , & V_246 . V_53 ,
V_254 ) ;
if ( V_118 < 0 )
GOTO ( V_255 , V_118 ) ;
for ( V_248 = 0 ; V_248 < V_243 ; V_248 ++ ) {
F_14 ( V_242 [ V_248 ] ) ;
V_237 = F_159 ( V_26 , V_60 , F_140 ( V_60 , V_241 ) ,
V_242 [ V_248 ] , V_256 ) ;
if ( F_130 ( V_237 ) ) {
V_118 = F_136 ( V_237 ) ;
break;
}
F_14 ( V_237 -> V_257 == V_256 ) ;
V_118 = F_160 ( V_26 , V_38 , V_237 ) ;
if ( V_118 ) {
F_14 ( V_237 -> V_258 == V_259 ) ;
F_161 ( V_26 , V_237 ) ;
break;
}
F_162 ( V_236 , V_237 ) ;
F_161 ( V_26 , V_237 ) ;
F_163 ( V_26 , V_237 , 0 , V_247 ) ;
V_241 += V_247 ;
}
if ( V_118 == 0 ) {
enum V_234 V_260 = V_240 == V_252 ? V_261 : V_239 ;
V_244 = V_244 && ( V_260 == V_239 ) ;
if ( V_244 )
V_118 = F_153 ( V_26 , V_38 , V_260 , V_236 ) ;
else
V_118 = F_164 ( V_26 , V_38 , V_260 , V_236 , 0 ) ;
F_119 ( V_182 , L_18 ,
V_244 ? L_19 : L_20 , V_118 ) ;
}
F_148 ( V_26 , V_73 , V_246 . V_53 ) ;
EXIT ;
V_255:
F_165 ( V_26 , V_38 , V_236 ) ;
F_166 ( V_26 , V_38 , V_236 ) ;
F_167 ( V_26 , V_236 ) ;
F_147 ( V_26 , V_38 ) ;
V_151:
F_134 ( V_26 , & V_191 ) ;
return V_118 ;
}
static int
F_168 ( struct V_94 * V_188 , void * V_262 , int V_263 )
{
struct V_94 * V_264 = V_262 ;
int V_265 , V_248 ;
V_265 = F_169 ( struct V_94 , V_98 [ V_188 -> V_266 ] ) ;
if ( V_265 > V_263 )
return ( - V_166 ) ;
if ( F_170 ( V_264 , V_188 , sizeof( V_264 ) ) )
return ( - V_267 ) ;
for ( V_248 = 0 ; V_248 < V_188 -> V_266 ; V_248 ++ ) {
if ( F_170 ( V_264 -> V_98 [ V_248 ] , V_188 -> V_98 [ V_248 ] ,
sizeof( V_188 -> V_98 [ 0 ] ) ) )
return ( - V_267 ) ;
}
return 0 ;
}
static int
F_171 ( struct V_1 * V_73 , struct V_94 * V_188 ,
void * V_264 , int V_263 )
{
struct V_75 * V_76 = V_73 -> V_77 ;
int V_248 ;
if ( V_263 < sizeof ( * V_188 ) )
return ( - V_166 ) ;
if ( F_172 ( V_188 , V_264 , sizeof ( * V_188 ) ) )
return ( - V_267 ) ;
if ( V_188 -> V_266 > V_76 -> V_268 ||
V_188 -> V_269 != V_270 ||
( V_188 -> V_271 & ( ~ V_249 ) ) != 0 ||
( ( T_3 ) V_188 -> V_271 * V_188 -> V_266 > ~ 0UL ) )
return ( - V_166 ) ;
for ( V_248 = 0 ; V_248 < V_188 -> V_266 ; V_248 ++ ) {
if ( F_172 ( V_188 -> V_98 [ V_248 ] ,
( (struct V_94 * ) V_264 ) -> \
V_98 [ V_248 ] ,
sizeof( V_188 -> V_98 [ 0 ] ) ) )
return ( - V_267 ) ;
}
return ( 0 ) ;
}
static inline void F_173 ( struct V_272 * V_273 , char * V_178 ,
T_3 V_274 )
{
sprintf ( V_178 , V_275 , V_274 ) ;
V_273 -> V_276 = V_178 ;
V_273 -> V_277 = strlen ( V_178 ) ;
}
static int F_174 ( const struct V_25 * V_26 , struct V_278 * V_13 ,
struct V_279 * V_280 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
int V_118 ;
V_51 ;
F_14 ( V_280 -> V_281 > 0 ) ;
V_118 = F_175 ( V_26 , V_13 , & V_282 , V_283 ) ;
if ( V_118 < 0 )
RETURN ( V_118 ) ;
if ( V_27 -> V_284 < V_118 ) {
int V_285 = F_176 ( V_118 ) ;
if ( V_27 -> V_284 > 0 ) {
F_14 ( V_27 -> V_286 ) ;
F_177 ( V_27 -> V_286 ,
V_27 -> V_284 ) ;
V_27 -> V_286 = NULL ;
V_27 -> V_284 = 0 ;
}
F_178 ( V_27 -> V_286 , V_285 ) ;
if ( V_27 -> V_286 == NULL )
RETURN ( - V_69 ) ;
V_27 -> V_284 = V_285 ;
}
F_14 ( V_27 -> V_284 >= V_118 ) ;
V_27 -> V_287 . V_288 = V_27 -> V_286 ;
V_27 -> V_287 . V_289 = V_27 -> V_284 ;
V_118 = F_175 ( V_26 , V_13 , & V_27 -> V_287 , V_283 ) ;
if ( V_118 < 0 )
RETURN ( V_118 ) ;
V_280 -> V_290 |= V_291 ;
V_280 -> V_292 = V_27 -> V_286 ;
V_280 -> V_281 = V_118 ;
RETURN ( 0 ) ;
}
int F_179 ( const struct V_25 * V_26 , struct V_278 * V_146 ,
struct V_279 * V_280 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_293 * V_294 = & V_27 -> V_287 ;
T_5 V_209 = F_180 ( & V_146 -> V_295 ) ;
int V_59 = V_280 -> V_296 ;
int V_118 = 0 , V_177 ;
V_51 ;
V_280 -> V_290 = 0 ;
if ( V_59 & V_297 ) {
V_280 -> V_296 = V_297 ;
V_118 = F_181 ( V_26 , V_146 , V_280 ) ;
if ( V_118 )
GOTO ( V_151 , V_118 ) ;
V_280 -> V_290 |= V_297 ;
}
if ( V_59 & V_291 ) {
if ( F_182 ( V_209 ) || F_183 ( V_209 ) ) {
F_14 ( V_280 -> V_281 > 0 ) ;
V_294 -> V_288 = V_280 -> V_292 ;
V_294 -> V_289 = V_280 -> V_281 ;
V_177 = F_175 ( V_26 , V_146 , V_294 , V_283 ) ;
if ( V_177 > 0 ) {
V_280 -> V_281 = V_177 ;
V_280 -> V_290 |= V_291 ;
} else if ( V_177 == - V_46 ) {
V_280 -> V_281 = 0 ;
} else if ( V_177 == - V_298 ) {
V_177 = F_174 ( V_26 , V_146 , V_280 ) ;
if ( V_177 < 0 )
GOTO ( V_151 , V_118 = V_177 ) ;
} else {
GOTO ( V_151 , V_118 = V_177 ) ;
}
}
}
#ifdef F_184
if ( V_59 & V_299 && F_183 ( V_209 ) ) {
V_294 -> V_288 = V_280 -> V_300 ;
V_294 -> V_289 = V_280 -> V_301 ;
V_177 = F_175 ( V_26 , V_146 , V_294 , V_302 ) ;
if ( V_177 > 0 ) {
V_280 -> V_301 = V_177 ;
V_280 -> V_290 |= V_299 ;
} else if ( V_177 == - V_46 ) {
V_280 -> V_301 = 0 ;
} else {
GOTO ( V_151 , V_118 = V_177 ) ;
}
}
#endif
V_151:
V_280 -> V_296 = V_59 ;
F_119 ( V_303 , L_21 V_232 L_22 ,
V_118 , V_280 -> V_290 , V_280 -> V_292 ) ;
RETURN ( V_118 ) ;
}
static int
F_185 ( const struct V_25 * V_26 , struct V_1 * V_73 ,
struct V_278 * V_304 , struct V_189 * V_190 ,
struct V_272 * V_273 , struct V_305 * V_306 ,
struct V_279 * V_280 )
{
struct V_71 * V_307 , * V_308 ;
struct V_80 * V_164 = V_73 -> V_78 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_189 * V_309 = & V_27 -> V_310 ;
struct V_72 V_70 = { . V_311 = V_312 } ;
int V_118 ;
V_51 ;
V_118 = F_186 ( V_26 , V_304 , V_273 , V_309 , V_306 ) ;
if ( V_118 == 0 )
return - V_313 ;
else if ( V_118 != - V_233 )
return V_118 ;
V_307 = F_187 ( V_26 , & V_73 -> V_4 . V_152 ,
V_190 , & V_70 ) ;
if ( F_130 ( V_307 ) ) {
F_79 ( L_23 V_314 L_24 , F_188 ( V_190 ) ,
F_136 ( V_307 ) ) ;
RETURN ( F_136 ( V_307 ) ) ;
}
V_308 = F_189 ( V_307 -> V_84 , V_164 -> V_169 ) ;
if ( V_308 == NULL ) {
F_79 ( L_25 V_314 L_16 , F_188 ( V_190 ) ) ;
GOTO ( V_315 , V_118 = - V_166 ) ;
}
F_119 ( V_316 , L_26 V_314 L_27 ,
F_188 ( F_190 ( & V_304 -> V_295 ) ) , V_273 -> V_276 , V_304 ) ;
V_306 -> V_317 = 0 ;
V_118 = F_191 ( V_26 , V_304 , V_273 , F_192 ( V_308 ) , V_306 , V_280 ) ;
if ( V_118 ) {
F_79 ( L_28 V_314 L_29 , F_188 ( V_190 ) , V_118 ) ;
GOTO ( V_315 , V_118 ) ;
}
F_119 ( V_316 , L_30 V_314 L_31 ,
F_188 ( F_190 ( & V_304 -> V_295 ) ) , V_273 -> V_276 , V_304 , V_118 ) ;
EXIT ;
V_315:
F_193 ( V_26 , V_307 ) ;
return V_118 ;
}
static int F_194 ( const struct V_25 * V_26 , struct V_80 * V_164 ,
struct V_279 * V_280 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
if ( strcmp ( V_164 -> V_169 -> V_170 , V_318 ) ) {
V_280 -> V_292 = ( void * ) & V_27 -> V_319 ;
V_280 -> V_281 = sizeof( V_27 -> V_319 ) ;
} else {
F_14 ( V_27 -> V_284 ) ;
V_280 -> V_292 = V_27 -> V_286 ;
V_280 -> V_281 = V_27 -> V_284 ;
}
return 0 ;
}
static int F_195 ( const struct V_25 * V_26 ,
struct V_1 * V_73 ,
struct V_71 * V_320 ,
struct V_189 * V_190 ,
char * V_178 , int V_321 ,
T_3 V_274 , T_4 V_209 , int V_322 ,
int V_323 , int V_324 )
{
struct V_71 * V_304 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_272 * V_273 = & V_27 -> V_325 ;
struct V_305 * V_306 = & V_27 -> V_326 ;
struct V_279 * V_280 = & V_27 -> V_327 ;
struct V_80 * V_164 = V_73 -> V_78 ;
int V_118 = 0 ;
int V_248 ;
V_51 ;
if ( V_320 == NULL )
return - 1 ;
V_304 = F_189 ( V_320 -> V_84 , V_164 -> V_169 ) ;
if ( V_304 == NULL )
RETURN ( - V_328 ) ;
memset ( V_280 , 0 , sizeof( * V_280 ) ) ;
memset ( V_306 , 0 , sizeof( * V_306 ) ) ;
if ( V_323 != 0 ) {
V_306 -> V_329 |= V_330 ;
F_194 ( V_26 , V_164 , V_280 ) ;
if ( V_323 != - 1 ) {
struct V_331 * V_332 = & V_27 -> V_333 ;
V_332 -> V_334 = V_335 ;
V_332 -> V_336 = V_323 ;
V_332 -> V_337 = V_324 ;
V_332 -> V_338 = 0 ;
V_306 -> V_160 . V_339 . V_340 = V_332 ;
V_306 -> V_160 . V_339 . V_341 = sizeof( * V_332 ) ;
V_306 -> V_329 |= V_342 ;
}
}
V_280 -> V_343 . V_344 = V_209 ;
V_280 -> V_343 . V_345 = V_346 | V_347 ;
V_280 -> V_343 . V_348 = F_196 () ;
if ( V_178 != NULL ) {
V_273 -> V_276 = V_178 ;
V_273 -> V_277 = V_321 ;
V_118 = F_185 ( V_26 , V_73 , F_192 ( V_304 ) , V_190 , V_273 ,
V_306 , V_280 ) ;
RETURN ( V_118 ) ;
}
for ( V_248 = 0 ; V_248 < V_322 ; V_248 ++ ) {
char * V_349 = V_27 -> V_350 ;
F_173 ( V_273 , V_349 , V_274 ) ;
V_118 = F_185 ( V_26 , V_73 , F_192 ( V_304 ) , V_190 , V_273 ,
V_306 , V_280 ) ;
if ( V_118 ) {
F_79 ( L_32 , V_349 ,
V_118 ) ;
break;
}
V_274 ++ ;
V_190 -> V_351 ++ ;
}
RETURN ( V_118 ) ;
}
static struct V_71 * F_197 ( const struct V_25 * V_26 ,
struct V_1 * V_73 ,
struct V_278 * V_304 ,
struct V_272 * V_273 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_189 * V_190 = & V_27 -> V_203 ;
struct V_71 * V_308 ;
int V_118 ;
V_51 ;
F_119 ( V_182 , L_33 V_314 L_34 , V_273 -> V_276 ,
F_188 ( V_190 ) , V_304 ) ;
V_118 = F_186 ( V_26 , V_304 , V_273 , V_190 , NULL ) ;
if ( V_118 ) {
F_79 ( L_35 , V_273 -> V_276 , V_118 ) ;
RETURN ( F_84 ( V_118 ) ) ;
}
V_308 = F_187 ( V_26 , & V_73 -> V_4 . V_152 , V_190 , NULL ) ;
RETURN ( V_308 ) ;
}
static int F_198 ( const struct V_25 * V_26 ,
struct V_1 * V_73 ,
struct V_71 * V_320 ,
T_3 V_274 , int V_322 )
{
struct V_71 * V_304 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_272 * V_273 = & V_27 -> V_325 ;
char * V_178 = V_27 -> V_350 ;
struct V_80 * V_164 = V_73 -> V_78 ;
struct V_293 * V_294 = & V_27 -> V_287 ;
int V_118 = 0 ;
int V_248 ;
V_51 ;
if ( V_320 == NULL )
return - 1 ;
V_304 = F_189 ( V_320 -> V_84 , V_164 -> V_169 ) ;
if ( V_304 == NULL )
RETURN ( - V_328 ) ;
for ( V_248 = 0 ; V_248 < V_322 ; V_248 ++ ) {
struct V_71 * V_307 , * V_308 ;
F_173 ( V_273 , V_178 , V_274 ) ;
V_307 = F_197 ( V_26 , V_73 , F_192 ( V_304 ) , V_273 ) ;
if ( F_130 ( V_307 ) ) {
F_79 ( L_36 ,
V_273 -> V_276 , F_136 ( V_307 ) ) ;
RETURN ( F_136 ( V_307 ) ) ;
}
V_308 = F_189 ( V_307 -> V_84 , V_164 -> V_169 ) ;
if ( V_308 == NULL ) {
F_79 ( L_37 , V_273 -> V_276 ) ;
F_193 ( V_26 , V_307 ) ;
V_118 = - V_166 ;
break;
}
F_119 ( V_316 , L_38 V_314 L_16 ,
F_188 ( F_190 ( V_308 ) ) ) ;
V_294 -> V_288 = V_27 -> V_352 ;
V_294 -> V_289 = sizeof( V_27 -> V_352 ) ;
sprintf ( V_178 , L_39 , V_353 ) ;
V_118 = F_199 ( V_26 , F_192 ( V_308 ) , V_294 , V_178 ,
V_354 ) ;
if ( V_118 < 0 ) {
F_79 ( L_40 V_314 L_29 ,
F_188 ( F_190 ( V_308 ) ) , V_118 ) ;
F_193 ( V_26 , V_307 ) ;
break;
}
F_119 ( V_316 , L_41 V_314 L_16 ,
F_188 ( F_190 ( V_308 ) ) ) ;
V_274 ++ ;
F_193 ( V_26 , V_307 ) ;
}
RETURN ( V_118 ) ;
}
static int F_200 ( const struct V_25 * V_26 ,
struct V_1 * V_73 ,
struct V_71 * V_320 ,
T_3 V_274 , int V_322 )
{
struct V_71 * V_304 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_272 * V_273 = & V_27 -> V_325 ;
char * V_178 = V_27 -> V_350 ;
struct V_279 * V_280 = & V_27 -> V_327 ;
struct V_80 * V_164 = V_73 -> V_78 ;
int V_118 = 0 ;
int V_248 ;
V_51 ;
if ( V_320 == NULL )
return - 1 ;
V_304 = F_189 ( V_320 -> V_84 , V_164 -> V_169 ) ;
if ( V_304 == NULL )
RETURN ( - V_328 ) ;
memset ( V_280 , 0 , sizeof( * V_280 ) ) ;
V_280 -> V_296 |= V_297 | V_291 | V_355 | V_356 | V_299 ;
V_280 -> V_300 = V_27 -> V_352 ;
V_280 -> V_301 = sizeof( V_27 -> V_352 ) ;
for ( V_248 = 0 ; V_248 < V_322 ; V_248 ++ ) {
struct V_71 * V_307 , * V_308 ;
V_280 -> V_290 = 0 ;
F_173 ( V_273 , V_178 , V_274 ) ;
F_194 ( V_26 , V_164 , V_280 ) ;
V_307 = F_197 ( V_26 , V_73 , F_192 ( V_304 ) , V_273 ) ;
if ( F_130 ( V_307 ) ) {
F_79 ( L_36 ,
V_273 -> V_276 , F_136 ( V_307 ) ) ;
RETURN ( F_136 ( V_307 ) ) ;
}
V_308 = F_189 ( V_307 -> V_84 , V_164 -> V_169 ) ;
if ( V_308 == NULL ) {
F_79 ( L_37 , V_273 -> V_276 ) ;
F_193 ( V_26 , V_307 ) ;
RETURN ( - V_166 ) ;
}
F_119 ( V_316 , L_42 V_314 L_16 ,
F_188 ( F_190 ( V_308 ) ) ) ;
V_118 = F_179 ( V_26 , F_192 ( V_308 ) , V_280 ) ;
if ( V_118 ) {
F_79 ( L_43 V_314 L_29 ,
F_188 ( F_190 ( V_308 ) ) , V_118 ) ;
F_193 ( V_26 , V_307 ) ;
break;
}
F_119 ( V_316 , L_44 V_314 L_16 ,
F_188 ( F_190 ( V_308 ) ) ) ;
V_274 ++ ;
F_193 ( V_26 , V_307 ) ;
}
RETURN ( V_118 ) ;
}
static int F_201 ( const struct V_25 * V_26 ,
struct V_1 * V_73 ,
struct V_71 * V_320 ,
T_3 V_274 , int V_322 )
{
struct V_71 * V_304 ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_272 * V_273 = & V_27 -> V_325 ;
char * V_178 = V_27 -> V_350 ;
struct V_189 * V_190 = & V_27 -> V_203 ;
struct V_80 * V_164 = V_73 -> V_78 ;
int V_118 = 0 ;
int V_248 ;
if ( V_320 == NULL )
return - 1 ;
V_304 = F_189 ( V_320 -> V_84 , V_164 -> V_169 ) ;
if ( V_304 == NULL )
return - V_328 ;
for ( V_248 = 0 ; V_248 < V_322 ; V_248 ++ ) {
F_173 ( V_273 , V_178 , V_274 ) ;
F_119 ( V_316 , L_45 V_314 L_27 ,
F_188 ( F_190 ( V_304 ) ) , V_273 -> V_276 , V_304 ) ;
V_118 = F_186 ( V_26 , F_192 ( V_304 ) , V_273 , V_190 , NULL ) ;
if ( V_118 ) {
F_79 ( L_46 , V_178 , V_118 ) ;
break;
}
F_119 ( V_316 , L_47 V_314 L_27 ,
F_188 ( F_190 ( V_304 ) ) , V_273 -> V_276 , V_304 ) ;
V_274 ++ ;
}
return V_118 ;
}
static int F_202 ( const struct V_25 * V_26 ,
struct V_1 * V_73 ,
struct V_278 * V_304 ,
struct V_272 * V_273 ,
struct V_279 * V_280 )
{
struct V_80 * V_164 = V_73 -> V_78 ;
struct V_71 * V_307 ;
struct V_71 * V_308 ;
int V_118 ;
V_51 ;
V_307 = F_197 ( V_26 , V_73 , V_304 , V_273 ) ;
if ( F_130 ( V_307 ) ) {
F_79 ( L_36 , V_273 -> V_276 ,
F_136 ( V_307 ) ) ;
RETURN ( F_136 ( V_307 ) ) ;
}
V_308 = F_189 ( V_307 -> V_84 , V_164 -> V_169 ) ;
if ( V_308 == NULL ) {
F_79 ( L_37 , V_273 -> V_276 ) ;
GOTO ( V_315 , V_118 = - V_166 ) ;
}
F_119 ( V_316 , L_48 V_314 L_27 ,
F_188 ( F_190 ( & V_304 -> V_295 ) ) , V_273 -> V_276 , V_304 ) ;
V_118 = F_203 ( V_26 , V_304 , F_192 ( V_308 ) , V_273 , V_280 , 0 ) ;
if ( V_118 ) {
F_79 ( L_49 ,
V_273 -> V_276 , V_118 ) ;
GOTO ( V_315 , V_118 ) ;
}
F_119 ( V_316 , L_50 V_314 L_27 ,
F_188 ( F_190 ( & V_304 -> V_295 ) ) , V_273 -> V_276 , V_304 ) ;
V_315:
F_193 ( V_26 , V_307 ) ;
return V_118 ;
}
static int F_204 ( const struct V_25 * V_26 ,
struct V_1 * V_73 ,
struct V_71 * V_320 ,
char * V_178 , int V_321 ,
T_3 V_274 , T_4 V_209 ,
int V_322 )
{
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_272 * V_273 = & V_27 -> V_325 ;
struct V_279 * V_280 = & V_27 -> V_327 ;
struct V_80 * V_164 = V_73 -> V_78 ;
struct V_71 * V_304 ;
int V_118 = 0 ;
int V_248 ;
V_51 ;
V_304 = F_189 ( V_320 -> V_84 , V_164 -> V_169 ) ;
if ( V_304 == NULL )
RETURN ( - V_166 ) ;
memset ( V_280 , 0 , sizeof( * V_280 ) ) ;
V_280 -> V_343 . V_344 = V_209 ;
V_280 -> V_343 . V_345 = V_346 ;
V_280 -> V_343 . V_348 = F_196 () ;
V_280 -> V_296 = V_297 ;
V_280 -> V_290 = 0 ;
if ( V_178 != NULL ) {
V_273 -> V_276 = V_178 ;
V_273 -> V_277 = V_321 ;
V_118 = F_202 ( V_26 , V_73 , F_192 ( V_304 ) , V_273 ,
V_280 ) ;
RETURN ( V_118 ) ;
}
for ( V_248 = 0 ; V_248 < V_322 ; V_248 ++ ) {
char * V_349 = V_27 -> V_350 ;
V_280 -> V_290 = 0 ;
F_173 ( V_273 , V_349 , V_274 ) ;
V_118 = F_202 ( V_26 , V_73 , F_192 ( V_304 ) , V_273 ,
V_280 ) ;
if ( V_118 ) {
F_79 ( L_49 , V_178 , V_118 ) ;
break;
}
V_274 ++ ;
}
RETURN ( V_118 ) ;
}
static struct V_71 * F_205 ( const struct V_25 * V_26 ,
struct V_1 * V_73 , char * V_357 ,
int V_358 )
{
struct V_80 * V_164 = V_73 -> V_78 ;
struct V_359 * V_200 = F_206 ( V_164 ) ;
struct V_24 * V_27 = F_12 ( V_26 ) ;
struct V_189 * V_190 = & V_27 -> V_203 ;
struct V_272 * V_273 = & V_27 -> V_325 ;
struct V_71 * V_304 = NULL ;
struct V_71 * V_308 = NULL ;
int V_118 = 0 ;
V_51 ;
V_118 = V_200 -> V_360 -> V_361 ( V_26 , V_200 , V_190 ) ;
if ( V_118 ) {
F_79 ( L_51 , V_118 ) ;
RETURN ( F_84 ( V_118 ) ) ;
}
V_304 = F_187 ( V_26 , & V_73 -> V_4 . V_152 , V_190 , NULL ) ;
if ( F_130 ( V_304 ) ) {
F_79 ( L_52 V_314 L_24 ,
F_188 ( V_190 ) , F_136 ( V_304 ) ) ;
RETURN ( V_304 ) ;
}
while ( 1 ) {
struct V_71 * V_362 ;
char * V_363 ;
V_363 = F_207 ( & V_357 , L_53 ) ;
if ( V_363 == NULL )
break;
if ( V_363 [ 0 ] == 0 ) {
if ( ! V_357 || V_357 [ 0 ] == '\0' )
break;
continue;
}
V_273 -> V_276 = V_363 ;
V_273 -> V_277 = strlen ( V_363 ) ;
V_362 = F_189 ( V_304 -> V_84 , V_164 -> V_169 ) ;
if ( V_362 == NULL ) {
F_193 ( V_26 , V_304 ) ;
V_118 = - V_166 ;
break;
}
V_308 = F_197 ( V_26 , V_73 , F_192 ( V_362 ) , V_273 ) ;
F_193 ( V_26 , V_304 ) ;
if ( F_130 ( V_308 ) ) {
V_118 = ( int ) F_136 ( V_308 ) ;
F_79 ( L_54 V_314 L_29 ,
V_273 -> V_276 , F_188 ( F_190 ( V_362 ) ) ,
V_118 ) ;
break;
}
V_304 = V_308 ;
}
if ( V_118 )
RETURN ( F_84 ( V_118 ) ) ;
RETURN ( V_304 ) ;
}
static void F_208 ( struct V_25 * V_26 )
{
struct V_364 * V_365 = V_364 ( V_26 ) ;
V_365 -> V_366 = V_367 ;
V_365 -> V_368 [ 0 ] = - 1 ;
V_365 -> V_368 [ 1 ] = - 1 ;
V_365 -> V_369 = V_365 -> V_370 = F_209 () ;
V_365 -> V_371 = V_365 -> V_372 = F_210 () ;
V_365 -> V_373 = V_365 -> V_374 = F_211 () ;
V_365 -> V_375 = V_365 -> V_376 = F_212 () ;
V_365 -> V_377 = F_213 () ;
if ( V_365 -> V_373 )
V_365 -> V_377 &= ~ V_378 ;
V_365 -> V_366 = V_379 ;
}
static void F_214 ( struct V_25 * V_26 )
{
struct V_364 * V_365 = V_364 ( V_26 ) ;
V_365 -> V_366 = V_380 ;
}
static int F_215 ( struct V_1 * V_73 , int V_381 ,
char * V_357 , int V_358 , T_3 V_274 , int V_322 ,
struct V_382 * V_126 )
{
struct V_24 * V_27 ;
struct V_80 * V_164 = V_73 -> V_78 ;
struct V_25 * V_26 ;
int V_191 ;
struct V_71 * V_304 ;
char * V_178 = NULL ;
int V_321 = V_126 -> V_383 ;
int V_118 = 0 ;
V_51 ;
if ( V_164 == NULL ) {
F_79 ( L_55 ) ;
RETURN ( - V_166 ) ;
}
if ( strcmp ( V_164 -> V_169 -> V_170 , V_318 ) ) {
F_79 ( L_56 ) ;
RETURN ( - V_166 ) ;
}
V_26 = F_129 ( & V_191 ) ;
if ( F_130 ( V_26 ) )
RETURN ( F_136 ( V_26 ) ) ;
V_118 = F_216 ( V_26 , V_384 , V_385 ) ;
if ( V_118 != 0 )
GOTO ( V_386 , V_118 ) ;
V_27 = F_12 ( V_26 ) ;
F_14 ( V_27 -> V_286 == NULL ) ;
F_178 ( V_27 -> V_286 , V_387 ) ;
if ( V_27 -> V_286 == NULL )
GOTO ( V_386 , V_118 = - V_69 ) ;
V_27 -> V_284 = V_387 ;
V_304 = F_205 ( V_26 , V_73 , V_357 , V_358 ) ;
if ( F_130 ( V_304 ) ) {
F_79 ( L_57 , V_357 ,
F_136 ( V_304 ) ) ;
GOTO ( V_388 , V_118 = F_136 ( V_304 ) ) ;
}
if ( V_321 > 0 ) {
F_61 ( V_178 , V_321 + 1 ) ;
if ( V_178 == NULL )
GOTO ( V_315 , V_118 = - V_69 ) ;
if ( F_172 ( V_178 , V_126 -> V_389 , V_321 ) )
GOTO ( V_390 , V_118 = - V_267 ) ;
}
F_208 ( V_26 ) ;
switch ( V_381 ) {
case V_391 :
case V_392 : {
struct V_24 * V_27 = F_12 ( V_26 ) ;
T_4 V_209 = V_126 -> V_393 . V_394 ;
struct V_189 * V_190 = & V_27 -> V_203 ;
int V_323 = ( int ) V_126 -> V_393 . V_395 ;
int V_396 = ( int ) V_126 -> V_393 . V_397 ;
V_118 = F_131 ( V_190 , & V_126 -> V_398 . V_399 , 0 ) ;
if ( V_118 != 0 )
break;
V_118 = F_195 ( V_26 , V_73 , V_304 , V_190 , V_178 , V_321 ,
V_274 , V_209 , V_322 , V_323 ,
V_396 ) ;
break;
}
case V_400 :
case V_401 : {
T_4 V_209 = V_126 -> V_393 . V_394 ;
V_118 = F_204 ( V_26 , V_73 , V_304 , V_178 , V_321 ,
V_274 , V_209 , V_322 ) ;
break;
}
case V_402 :
V_118 = F_201 ( V_26 , V_73 , V_304 , V_274 , V_322 ) ;
break;
case V_403 :
V_118 = F_200 ( V_26 , V_73 , V_304 , V_274 , V_322 ) ;
break;
case V_404 :
V_118 = F_198 ( V_26 , V_73 , V_304 , V_274 , V_322 ) ;
break;
default:
F_79 ( L_58 , V_381 ) ;
V_118 = - V_166 ;
break;
}
F_214 ( V_26 ) ;
V_390:
if ( V_178 != NULL )
F_62 ( V_178 , V_321 + 1 ) ;
V_315:
F_193 ( V_26 , V_304 ) ;
V_388:
F_14 ( V_27 -> V_286 ) ;
F_177 ( V_27 -> V_286 , V_27 -> V_284 ) ;
V_27 -> V_286 = NULL ;
V_27 -> V_284 = 0 ;
V_386:
F_134 ( V_26 , & V_191 ) ;
return V_118 ;
}
static int F_217 ( const struct V_25 * V_26 , struct V_1 * V_73 ,
int V_405 , struct V_406 * V_407 , void * V_264 ,
int V_263 , struct V_408 * V_409 )
{
struct V_10 * V_11 ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_94 * V_188 = NULL ;
int V_118 ;
int V_410 = 0 ;
V_51 ;
if ( ( V_407 -> V_411 & V_412 ) == 0 &&
( V_405 ||
V_76 -> V_268 != 0 ) ) {
F_79 ( L_59 ) ;
RETURN ( - V_166 ) ;
}
V_118 = F_58 ( V_73 , & V_188 ) ;
if ( V_118 < 0 ) {
F_79 ( L_60 , V_118 ) ;
GOTO ( V_413 , V_118 ) ;
}
if ( V_264 != NULL ) {
int V_248 , V_414 ;
V_118 = F_171 ( V_73 , V_188 , V_264 , V_263 ) ;
if ( V_118 != 0 )
GOTO ( V_413 , V_118 ) ;
if ( V_188 -> V_266 == 0 )
V_188 -> V_266 = V_76 -> V_268 ;
if ( V_188 -> V_271 == 0 )
V_188 -> V_271 = V_251 ;
V_414 = F_218 () ;
for ( V_248 = 0 ; V_248 < V_188 -> V_266 ; V_248 ++ ) {
if ( F_126 ( & V_188 -> V_98 [ V_248 ] -> V_197 ) == 0 )
V_188 -> V_98 [ V_248 ] -> V_197 = V_188 -> V_102 ;
V_188 -> V_98 [ V_248 ] -> V_415 =
( V_414 + V_248 ) % V_76 -> V_268 ;
}
}
if ( V_407 -> V_411 & V_412 ) {
F_14 ( V_407 -> V_411 & V_416 ) ;
V_188 -> V_102 = V_407 -> V_399 ;
}
if ( F_126 ( & V_188 -> V_102 ) == 0 )
F_219 ( & V_188 -> V_102 , ++ V_417 ) ;
V_118 = 0 ;
if ( V_405 ) {
F_14 ( ( V_407 -> V_411 & V_416 ) &&
( F_128 ( & V_407 -> V_399 ) == V_193 ) ) ;
V_118 = F_220 ( V_26 , V_76 -> V_97 , V_407 , & V_188 , V_409 ) ;
if ( V_118 != 0 ) {
F_79 ( L_61 , V_118 ) ;
GOTO ( V_413 , V_118 ) ;
}
V_410 = 1 ;
}
V_407 -> V_399 = V_188 -> V_102 ;
V_407 -> V_411 |= V_412 ;
V_11 = F_124 ( V_73 , & V_188 ) ;
if ( F_130 ( V_11 ) )
GOTO ( V_413 , V_118 = F_136 ( V_11 ) ) ;
F_135 ( V_11 ) ;
F_119 ( V_182 , L_62 V_192 L_16 , F_127 ( & V_407 -> V_399 ) ) ;
EXIT ;
V_413:
if ( V_410 && V_118 )
F_221 ( V_26 , V_76 -> V_97 , V_407 , V_188 , V_409 , NULL , NULL ) ;
if ( V_188 )
F_65 ( V_73 , & V_188 ) ;
if ( V_118 )
F_79 ( L_63 , V_118 ) ;
return ( V_118 ) ;
}
static int F_222 ( struct V_10 * * V_418 , struct V_1 * V_73 ,
struct V_406 * V_407 )
{
struct V_94 * V_188 = NULL ;
struct V_10 * V_11 ;
int V_118 ;
V_51 ;
if ( ( V_407 -> V_411 & V_412 ) == 0 || F_126 ( & V_407 -> V_399 ) == 0 ) {
F_79 ( L_59 ) ;
RETURN ( - V_166 ) ;
}
V_118 = F_58 ( V_73 , & V_188 ) ;
if ( V_118 < 0 )
RETURN ( V_118 ) ;
V_188 -> V_102 = V_407 -> V_399 ;
if ( ! ( V_407 -> V_411 & V_416 ) )
F_64 ( & V_188 -> V_102 ) ;
V_118 = 0 ;
V_11 = F_124 ( V_73 , & V_188 ) ;
if ( ! F_130 ( V_11 ) )
* V_418 = V_11 ;
else
V_118 = F_136 ( V_11 ) ;
if ( V_188 )
F_65 ( V_73 , & V_188 ) ;
RETURN ( V_118 ) ;
}
static void F_223 ( struct V_10 * V_11 )
{
if ( F_135 ( V_11 ) )
F_79 ( L_64 ) ;
}
static void
F_224 ( struct V_94 * V_188 , T_2 * V_419 , T_6 * V_420 )
{
unsigned long V_323 ;
unsigned long V_421 ;
unsigned long V_422 ;
unsigned long V_423 ;
int V_396 ;
T_2 V_241 ;
if ( V_188 -> V_266 <= 1 )
return;
V_241 = * V_419 ;
V_421 = V_188 -> V_271 ;
V_323 = V_188 -> V_266 ;
V_422 = V_421 * V_323 ;
V_423 = F_225 ( V_241 , V_422 ) ;
V_396 = V_423 / V_421 ;
* V_420 = F_126 ( & V_188 -> V_98 [ V_396 ] -> V_197 ) ;
* V_419 = V_241 * V_421 + V_423 % V_421 ;
}
static void
F_226 ( struct V_94 * V_188 ,
struct V_34 * V_34 , int V_240 , T_6 V_274 ,
T_2 V_241 , T_2 V_322 )
{
char * V_424 ;
T_2 V_425 ;
T_6 V_426 ;
int V_427 ;
F_14 ( V_322 == V_251 ) ;
V_424 = F_227 ( V_34 ) ;
for ( V_427 = 0 ; V_427 < V_251 ; V_427 += V_428 ) {
if ( V_240 == V_429 ) {
V_425 = V_241 + V_427 ;
V_426 = V_274 ;
F_224 ( V_188 , & V_425 , & V_426 ) ;
} else {
V_425 = 0xdeadbeef00c0ffeeULL ;
V_426 = 0xdeadbeef00c0ffeeULL ;
}
F_228 ( V_424 + V_427 , V_428 ,
V_425 , V_426 ) ;
}
F_229 ( V_34 ) ;
}
static int F_230 ( struct V_94 * V_188 ,
struct V_34 * V_34 , T_6 V_274 ,
T_2 V_241 , T_2 V_322 )
{
T_2 V_425 ;
T_6 V_426 ;
char * V_424 ;
int V_427 ;
int V_118 ;
int V_177 ;
F_14 ( V_322 == V_251 ) ;
V_424 = F_227 ( V_34 ) ;
for ( V_118 = V_427 = 0 ; V_427 < V_251 ; V_427 += V_428 ) {
V_425 = V_241 + V_427 ;
V_426 = V_274 ;
F_224 ( V_188 , & V_425 , & V_426 ) ;
V_177 = F_231 ( L_65 ,
V_424 + V_427 , V_428 ,
V_425 , V_426 ) ;
if ( V_177 != 0 ) {
F_79 ( L_66 V_232 L_16 , V_274 ) ;
V_118 = V_177 ;
}
}
F_229 ( V_34 ) ;
return V_118 ;
}
static int F_232 ( struct V_1 * V_73 , int V_240 , struct V_406 * V_407 ,
struct V_10 * V_11 , T_2 V_241 ,
T_7 V_322 , int V_244 ,
struct V_408 * V_409 )
{
struct V_94 * V_188 = V_11 -> V_89 ;
T_8 V_243 ;
struct V_430 * V_431 ;
struct V_430 * V_432 ;
struct V_34 * * V_242 ;
T_2 V_433 ;
int V_248 ;
int V_118 ;
int V_434 ;
int V_435 ;
int V_436 = 0 ;
V_51 ;
V_434 = ( F_126 ( & V_407 -> V_399 ) != V_437 &&
( V_407 -> V_411 & V_438 ) != 0 &&
( V_407 -> V_439 & V_440 ) != 0 ) ;
V_435 = ( ( F_126 ( & V_407 -> V_399 ) & 2 ) == 0 ) ? V_441 : V_442 ;
F_14 ( V_240 == V_429 || V_240 == V_443 ) ;
F_14 ( V_188 != NULL ) ;
F_14 ( F_126 ( & V_188 -> V_102 ) == F_126 ( & V_407 -> V_399 ) ) ;
if ( V_322 <= 0 ||
( V_322 & ( ~ V_249 ) ) != 0 )
RETURN ( - V_166 ) ;
V_243 = V_322 >> V_444 ;
if ( V_240 == V_429 )
V_436 = V_445 ;
F_61 ( V_431 , V_243 * sizeof( * V_431 ) ) ;
if ( V_431 == NULL )
RETURN ( - V_69 ) ;
F_61 ( V_242 , V_243 * sizeof( * V_242 ) ) ;
if ( V_242 == NULL ) {
F_62 ( V_431 , V_243 * sizeof( * V_431 ) ) ;
RETURN ( - V_69 ) ;
}
for ( V_248 = 0 , V_432 = V_431 , V_433 = V_241 ;
V_248 < V_243 ;
V_248 ++ , V_432 ++ , V_433 += V_251 ) {
F_14 ( V_432 -> V_446 == NULL ) ;
V_118 = - V_69 ;
F_233 ( V_432 -> V_446 , V_435 ) ;
if ( V_432 -> V_446 == NULL )
goto V_151;
V_242 [ V_248 ] = V_432 -> V_446 ;
V_432 -> V_322 = V_251 ;
V_432 -> V_433 = V_433 ;
V_432 -> V_447 = V_436 ;
if ( V_434 )
F_226 ( V_188 , V_432 -> V_446 , V_240 ,
F_126 ( & V_407 -> V_399 ) , V_433 ,
V_432 -> V_322 ) ;
}
F_14 ( V_73 -> V_78 != NULL ) ;
V_118 = F_156 ( V_11 , V_240 , V_241 , V_242 , V_243 , V_244 ) ;
V_151:
if ( V_118 != 0 || V_240 != V_443 )
V_434 = 0 ;
for ( V_248 = 0 , V_432 = V_431 ; V_248 < V_243 ; V_248 ++ , V_432 ++ ) {
if ( V_432 -> V_446 == NULL )
continue;
if ( V_434 ) {
int V_448 ;
V_448 = F_230 ( V_188 , V_432 -> V_446 ,
F_126 ( & V_407 -> V_399 ) ,
V_432 -> V_433 , V_432 -> V_322 ) ;
if ( V_448 != 0 && V_118 == 0 )
V_118 = V_448 ;
}
F_234 ( V_432 -> V_446 ) ;
}
F_62 ( V_431 , V_243 * sizeof( * V_431 ) ) ;
F_62 ( V_242 , V_243 * sizeof( * V_242 ) ) ;
RETURN ( V_118 ) ;
}
static int F_235 ( const struct V_25 * V_26 ,
struct V_449 * exp , int V_240 ,
struct V_406 * V_407 , struct V_10 * V_11 ,
T_2 V_241 , T_7 V_322 ,
T_7 V_450 , struct V_408 * V_409 ,
int V_244 )
{
struct V_94 * V_188 = V_11 -> V_89 ;
struct V_451 V_452 ;
struct V_453 * V_454 ;
struct V_455 * V_456 ;
T_2 V_433 ;
T_7 V_243 , V_457 ;
int V_248 , V_458 = 0 , V_436 = 0 ;
V_51 ;
if ( V_322 <= 0 || ( V_322 & ( ~ V_249 ) ) != 0 ||
( V_188 != NULL && F_126 ( & V_188 -> V_102 ) != F_126 ( & V_407 -> V_399 ) ) )
RETURN ( - V_166 ) ;
V_243 = V_450 >> V_444 ;
V_457 = V_322 >> V_444 ;
F_61 ( V_454 , V_243 * sizeof( struct V_453 ) ) ;
F_61 ( V_456 , V_243 * sizeof( struct V_455 ) ) ;
if ( V_454 == NULL || V_456 == NULL )
GOTO ( V_151 , V_458 = - V_69 ) ;
if ( V_240 == V_429 && V_244 )
V_436 |= V_445 ;
F_236 ( V_407 , & V_452 ) ;
V_433 = V_241 ;
for(; V_457 ; V_457 -= V_243 ) {
int V_459 ;
if ( V_457 < V_243 )
V_243 = V_457 ;
for ( V_248 = 0 ; V_248 < V_243 ; V_248 ++ , V_433 += V_251 ) {
V_456 [ V_248 ] . V_241 = V_433 ;
V_456 [ V_248 ] . V_460 = V_251 ;
V_456 [ V_248 ] . V_461 = V_436 ;
}
V_452 . V_462 = V_243 ;
V_409 -> V_463 = 0 ;
V_459 = V_243 ;
V_458 = F_237 ( V_26 , V_240 , exp , V_407 , 1 , & V_452 , V_456 , & V_459 ,
V_454 , V_409 , NULL ) ;
if ( V_458 != 0 )
GOTO ( V_151 , V_458 ) ;
F_14 ( V_459 == V_243 ) ;
for ( V_248 = 0 ; V_248 < V_459 ; V_248 ++ ) {
struct V_34 * V_34 = V_454 [ V_248 ] . V_34 ;
if ( V_34 == NULL && V_454 [ V_248 ] . V_118 == 0 )
continue;
if ( V_244 )
V_454 [ V_248 ] . V_461 |= V_445 ;
if ( F_126 ( & V_407 -> V_399 ) == V_437 ||
( V_407 -> V_411 & V_438 ) == 0 ||
( V_407 -> V_439 & V_440 ) == 0 )
continue;
if ( V_240 == V_429 )
F_226 ( V_188 , V_34 , V_240 ,
F_126 ( & V_407 -> V_399 ) ,
V_456 [ V_248 ] . V_241 ,
V_456 [ V_248 ] . V_460 ) ;
else
F_230 ( V_188 , V_34 ,
F_126 ( & V_407 -> V_399 ) ,
V_456 [ V_248 ] . V_241 ,
V_456 [ V_248 ] . V_460 ) ;
}
V_458 = F_238 ( V_26 , V_240 , exp , V_407 , 1 , & V_452 ,
V_456 , V_243 , V_454 , V_409 , V_458 ) ;
if ( V_458 != 0 )
GOTO ( V_151 , V_458 ) ;
memset ( V_409 , 0 , sizeof( * V_409 ) ) ;
F_239 ( (struct V_121 * ) & V_26 -> V_28 ) ;
F_240 ( (struct V_121 * ) & V_26 -> V_28 ) ;
}
V_151:
if ( V_454 )
F_62 ( V_454 , V_243 * sizeof( struct V_453 ) ) ;
if ( V_456 )
F_62 ( V_456 , V_243 * sizeof( struct V_455 ) ) ;
RETURN ( V_458 ) ;
}
static int F_241 ( const struct V_25 * V_26 , int V_240 ,
struct V_449 * exp ,
struct V_382 * V_126 ,
struct V_408 * V_464 )
{
struct V_6 * V_7 = F_242 ( exp ) ;
struct V_1 * V_73 = F_4 ( V_7 ) ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_406 * V_407 = & V_126 -> V_398 ;
struct V_10 * V_11 ;
int V_118 ;
int V_244 = 1 ;
long V_465 ;
V_51 ;
F_14 ( V_407 -> V_411 & V_416 ) ;
V_118 = F_222 ( & V_11 , V_73 , V_407 ) ;
if ( V_118 )
RETURN ( V_118 ) ;
V_407 -> V_411 &= ~ V_466 ;
V_465 = ( long ) V_126 -> V_467 ;
if ( V_465 == 1 )
V_244 = 0 ;
if ( V_73 -> V_78 == NULL && V_465 != 3 ) {
V_465 = 3 ;
V_126 -> V_468 = V_126 -> V_469 ;
}
if ( V_126 -> V_468 > V_470 )
V_126 -> V_468 = V_470 ;
switch ( V_465 ) {
case 1 :
case 2 :
V_118 = F_232 ( V_73 , V_240 , V_407 ,
V_11 , V_126 -> V_471 ,
V_126 -> V_469 , V_244 , V_464 ) ;
break;
case 3 :
V_118 = F_235 ( V_26 , V_76 -> V_97 , V_240 , V_407 ,
V_11 , V_126 -> V_471 ,
V_126 -> V_469 , V_126 -> V_468 ,
V_464 , V_244 ) ;
break;
default:
V_118 = - V_166 ;
}
F_223 ( V_11 ) ;
RETURN ( V_118 ) ;
}
static int
F_243 ( struct V_449 * exp , struct V_406 * V_407 ,
int V_209 , T_2 V_241 , T_7 V_265 )
{
struct V_1 * V_73 = F_4 ( exp -> V_472 ) ;
struct V_245 * V_473 = & V_407 -> V_474 ;
struct V_10 * V_11 ;
T_2 V_208 ;
int V_118 ;
V_51 ;
if ( V_73 -> V_78 == NULL )
RETURN ( - V_475 ) ;
if ( ! ( V_209 == V_253 || V_209 == V_219 ) )
RETURN ( - V_166 ) ;
if ( ( V_241 & ( ~ V_249 ) ) != 0 ||
( V_265 & ( ~ V_249 ) ) != 0 )
RETURN ( - V_166 ) ;
V_118 = F_222 ( & V_11 , V_73 , V_407 ) ;
if ( V_118 != 0 )
RETURN ( V_118 ) ;
V_208 = ( V_265 == 0 ) ? ( ( T_2 ) - 1 ) : ( V_241 + V_265 - 1 ) ;
V_118 = F_145 ( V_11 , V_241 , V_208 , V_209 , & V_473 -> V_53 ) ;
if ( V_118 == 0 ) {
V_407 -> V_411 |= V_466 ;
F_119 ( V_182 , L_67 V_232 L_16 , V_473 -> V_53 ) ;
}
F_223 ( V_11 ) ;
RETURN ( V_118 ) ;
}
static int
F_244 ( struct V_449 * exp , struct V_406 * V_407 )
{
struct V_1 * V_73 = F_4 ( exp -> V_472 ) ;
T_3 V_53 = V_407 -> V_474 . V_53 ;
if ( ( V_407 -> V_411 & V_466 ) == 0 )
return - V_166 ;
F_119 ( V_182 , L_67 V_232 L_16 , V_53 ) ;
return F_152 ( V_73 , V_53 ) ;
}
static int
F_245 ( unsigned int V_476 , struct V_449 * exp , int V_460 ,
void * V_477 , void * V_478 )
{
struct V_6 * V_7 = exp -> V_472 ;
struct V_1 * V_73 = F_4 ( V_7 ) ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_10 * V_11 ;
struct V_382 * V_126 = V_477 ;
struct V_408 V_464 ;
struct V_25 * V_26 ;
struct V_479 * V_480 ;
struct V_406 * V_407 ;
struct V_189 V_190 ;
int V_240 = V_443 ;
int V_118 = 0 ;
int V_248 ;
V_51 ;
memset ( & V_464 , 0 , sizeof( V_464 ) ) ;
V_407 = & V_126 -> V_398 ;
if ( ! ( V_407 -> V_411 & V_416 ) ) {
V_407 -> V_411 |= V_416 ;
F_64 ( & V_407 -> V_399 ) ;
}
V_118 = F_131 ( & V_190 , & V_407 -> V_399 , 0 ) ;
if ( V_118 < 0 )
RETURN ( V_118 ) ;
F_91 ( V_26 ) ;
if ( V_26 == NULL )
RETURN ( - V_69 ) ;
V_118 = F_246 ( V_26 , V_481 ) ;
if ( V_118 )
GOTO ( V_151 , V_118 = - V_69 ) ;
switch ( V_476 ) {
case V_482 :
if ( ! F_247 ( V_483 ) )
GOTO ( V_151 , V_118 = - V_484 ) ;
V_118 = F_217 ( V_26 , V_73 , 1 , V_407 , V_126 -> V_467 ,
V_126 -> V_468 , & V_464 ) ;
GOTO ( V_151 , V_118 ) ;
case V_485 : {
int V_322 ;
int V_476 ;
char * V_486 = NULL ;
int V_487 ;
T_3 V_274 ;
if ( ! F_247 ( V_483 ) )
GOTO ( V_151 , V_118 = - V_484 ) ;
V_322 = V_126 -> V_469 ;
V_476 = V_126 -> V_488 ;
V_274 = F_126 ( & V_126 -> V_393 . V_399 ) ;
V_487 = V_126 -> V_468 ;
F_61 ( V_486 , V_487 + 1 ) ;
if ( V_486 == NULL )
GOTO ( V_151 , V_118 = - V_69 ) ;
if ( F_172 ( V_486 , V_126 -> V_467 , V_487 ) ) {
F_62 ( V_486 , V_126 -> V_468 + 1 ) ;
GOTO ( V_151 , V_118 = - V_267 ) ;
}
V_118 = F_215 ( V_73 , V_476 , V_486 , V_487 , V_274 , V_322 , V_126 ) ;
F_62 ( V_486 , V_487 + 1 ) ;
GOTO ( V_151 , V_118 ) ;
}
case V_489 : {
struct V_25 * V_490 ;
int V_191 ;
T_3 V_491 ;
int V_492 ;
if ( ! F_247 ( V_483 ) )
GOTO ( V_151 , V_118 = - V_484 ) ;
V_490 = F_129 ( & V_191 ) ;
if ( F_130 ( V_490 ) )
GOTO ( V_151 , V_118 = F_136 ( V_490 ) ) ;
V_118 = F_216 ( V_490 , V_384 ,
V_385 ) ;
if ( V_118 != 0 ) {
F_134 ( V_490 , & V_191 ) ;
GOTO ( V_151 , V_118 ) ;
}
V_118 = F_248 ( V_490 , V_73 -> V_134 , & V_491 ) ;
F_134 ( V_490 , & V_191 ) ;
if ( V_118 < 0 ) {
F_79 ( L_68 ,
V_7 -> V_130 , V_118 ) ;
GOTO ( V_151 , V_118 ) ;
}
if ( F_170 ( V_126 -> V_467 , & V_491 , V_126 -> V_468 ) )
return - V_267 ;
V_492 = V_493 ;
if ( F_170 ( V_126 -> V_389 , & V_492 ,
V_126 -> V_383 ) )
return - V_267 ;
GOTO ( V_151 , V_118 ) ;
}
case V_494 :
if ( ! F_247 ( V_483 ) )
GOTO ( V_151 , V_118 = - V_484 ) ;
V_118 = F_222 ( & V_11 , V_73 , V_407 ) ;
if ( V_118 == 0 ) {
V_118 = F_221 ( V_26 , V_76 -> V_97 , V_407 , V_11 -> V_89 ,
& V_464 , NULL , NULL ) ;
if ( V_118 == 0 )
V_11 -> V_183 = 1 ;
F_223 ( V_11 ) ;
}
GOTO ( V_151 , V_118 ) ;
case V_495 :
V_118 = F_222 ( & V_11 , V_73 , V_407 ) ;
if ( V_118 == 0 ) {
struct V_496 V_196 = { { { 0 } } } ;
V_196 . V_497 = V_11 -> V_89 ;
V_196 . V_498 = V_407 ;
V_118 = F_249 ( V_26 , V_76 -> V_97 , & V_196 ) ;
F_223 ( V_11 ) ;
}
GOTO ( V_151 , V_118 ) ;
case V_499 :
if ( ! F_247 ( V_483 ) )
GOTO ( V_151 , V_118 = - V_484 ) ;
V_118 = F_222 ( & V_11 , V_73 , V_407 ) ;
if ( V_118 == 0 ) {
struct V_496 V_196 = { { { 0 } } } ;
V_196 . V_498 = V_407 ;
V_196 . V_497 = V_11 -> V_89 ;
V_118 = F_250 ( V_26 , V_76 -> V_97 , & V_196 , NULL ) ;
F_223 ( V_11 ) ;
}
GOTO ( V_151 , V_118 ) ;
case V_500 :
if ( ! F_247 ( V_483 ) )
GOTO ( V_151 , V_118 = - V_484 ) ;
V_240 = V_429 ;
case V_501 :
V_118 = F_241 ( V_26 , V_240 , exp , V_126 , & V_464 ) ;
GOTO ( V_151 , V_118 ) ;
case V_502 :
V_118 = F_222 ( & V_11 , V_73 , V_407 ) ;
if ( V_118 == 0 ) {
V_118 = F_168 ( V_11 -> V_89 , V_126 -> V_467 ,
V_126 -> V_468 ) ;
F_223 ( V_11 ) ;
}
GOTO ( V_151 , V_118 ) ;
case V_503 :
if ( ! F_247 ( V_483 ) )
GOTO ( V_151 , V_118 = - V_484 ) ;
if ( V_126 -> V_467 == NULL ) {
V_118 = F_222 ( & V_11 , V_73 , V_407 ) ;
if ( V_118 == 0 ) {
V_11 -> V_183 = 1 ;
F_223 ( V_11 ) ;
}
} else {
V_118 = F_217 ( V_26 , V_73 , 0 , V_407 ,
V_126 -> V_467 ,
V_126 -> V_468 , & V_464 ) ;
}
GOTO ( V_151 , V_118 ) ;
case V_504 :
if ( ! F_247 ( V_483 ) )
GOTO ( V_151 , V_118 = - V_484 ) ;
V_118 = F_243 ( exp , V_407 ,
V_126 -> V_505 ,
V_126 -> V_471 ,
V_126 -> V_469 ) ;
GOTO ( V_151 , V_118 ) ;
case V_506 :
V_118 = F_244 ( exp , V_407 ) ;
GOTO ( V_151 , V_118 ) ;
default:
F_79 ( L_69 , V_476 ) ;
GOTO ( V_151 , V_118 = - V_507 ) ;
}
EXIT ;
V_151:
F_251 ( V_26 ) ;
F_93 ( V_26 ) ;
for ( V_480 = V_464 . V_508 , V_248 = 0 ; V_248 < 4 ;
V_248 ++ , V_480 ++ ) {
if ( ! V_480 -> V_209 )
break;
F_252 ( & V_480 -> V_63 , V_480 -> V_209 ) ;
}
return V_118 ;
}
static int F_100 ( const struct V_25 * V_26 ,
struct V_6 * V_141 , struct V_144 * V_509 )
{
struct V_75 * V_76 = & V_141 -> V_160 . V_161 ;
struct V_6 * V_148 ;
struct V_510 V_511 = { L_70 } ;
struct V_512 * V_513 = NULL ;
int V_118 ;
V_51 ;
if ( V_509 -> V_514 < 2 || F_253 ( V_509 , 1 ) < 1 ) {
F_79 ( L_71 ) ;
RETURN ( - V_166 ) ;
}
V_148 = F_98 ( F_99 ( V_509 , 1 ) ) ;
if ( ! V_148 || ! V_148 -> V_515 || ! V_148 -> V_516 ) {
F_79 ( L_72 ,
F_99 ( V_509 , 1 ) ) ;
RETURN ( - V_166 ) ;
}
F_254 ( & V_76 -> V_91 ) ;
F_47 ( & V_76 -> V_93 ) ;
F_47 ( & V_76 -> V_185 ) ;
V_76 -> V_226 = 0 ;
V_76 -> V_268 = 0 ;
if ( ! strcmp ( V_148 -> V_157 -> V_158 , V_159 ) ) {
F_255 ( V_384 ) ;
F_256 ( V_385 ) ;
RETURN ( 0 ) ;
}
F_61 ( V_513 , sizeof( * V_513 ) ) ;
if ( V_513 == NULL ) {
F_79 ( L_73 ,
F_99 ( V_509 , 1 ) ) ;
return - V_69 ;
}
V_513 -> V_517 = V_518 | V_519 |
V_520 |
V_521 | V_522 |
V_523 | V_524 |
V_525 ;
V_513 -> V_526 = V_527 ;
V_513 -> V_528 = V_529 ;
V_513 -> V_530 = V_193 ;
V_118 = F_257 ( V_26 , & V_76 -> V_97 , V_148 , & V_511 , V_513 , NULL ) ;
if ( V_118 == 0 ) {
F_55 ( & V_148 -> V_531 ) ;
F_69 ( & V_76 -> V_97 -> V_532 ) ;
F_57 ( & V_148 -> V_531 ) ;
}
F_62 ( V_513 , sizeof( * V_513 ) ) ;
if ( V_118 != 0 ) {
F_79 ( L_74 ,
F_99 ( V_509 , 1 ) ) ;
return ( V_118 ) ;
}
RETURN ( V_118 ) ;
}
static int F_104 ( struct V_6 * V_141 )
{
struct V_1 * V_73 = F_4 ( V_141 ) ;
struct V_75 * V_76 = & V_141 -> V_160 . V_161 ;
int V_118 ;
V_51 ;
if ( V_73 == NULL )
RETURN ( 0 ) ;
if ( V_73 -> V_85 ) {
F_258 ( V_384 ) ;
F_259 ( V_385 ) ;
RETURN ( 0 ) ;
}
if ( ! F_33 ( & V_141 -> V_533 ) ) {
F_79 ( L_75 ) ;
RETURN ( - V_45 ) ;
}
F_14 ( F_68 ( & V_76 -> V_97 -> V_534 ) > 0 ) ;
V_118 = F_260 ( V_76 -> V_97 ) ;
if ( V_118 != 0 )
F_79 ( L_76 , V_118 ) ;
RETURN ( V_118 ) ;
}
static int F_261 ( const struct V_25 * V_26 ,
struct V_449 * * exp ,
struct V_6 * V_535 , struct V_510 * V_536 ,
struct V_512 * V_126 , void * V_537 )
{
int V_118 ;
struct V_245 V_538 = { 0 } ;
V_51 ;
V_118 = F_262 ( & V_538 , V_535 , V_536 ) ;
if ( V_118 == 0 ) {
* exp = F_263 ( & V_538 ) ;
}
RETURN ( V_118 ) ;
}
static int F_264 ( struct V_449 * exp )
{
#if 0
struct obd_device *obd;
struct echo_client_obd *ec;
struct ec_lock *ecl;
#endif
int V_118 ;
V_51 ;
if ( exp == NULL )
GOTO ( V_151 , V_118 = - V_166 ) ;
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
V_118 = F_265 ( exp ) ;
GOTO ( V_151 , V_118 ) ;
V_151:
return V_118 ;
}
int F_266 ( void )
{
struct V_539 V_540 = { 0 } ;
int V_118 ;
F_267 ( & V_540 ) ;
V_118 = F_268 ( V_541 ) ;
if ( V_118 == 0 ) {
V_118 = F_269 ( & V_542 , NULL ,
V_540 . V_543 ,
V_55 ,
& V_224 ) ;
if ( V_118 )
F_270 ( V_541 ) ;
}
return V_118 ;
}
void F_271 ( void )
{
F_272 ( V_55 ) ;
F_270 ( V_541 ) ;
}
static int T_9 F_273 ( void )
{
struct V_539 V_540 ;
int V_118 ;
V_51 ;
F_274 ( L_77 ) ;
F_14 ( V_251 % V_428 == 0 ) ;
F_267 ( & V_540 ) ;
V_118 = F_266 () ;
RETURN ( V_118 ) ;
}
static void F_275 ( void )
{
F_271 () ;
}
