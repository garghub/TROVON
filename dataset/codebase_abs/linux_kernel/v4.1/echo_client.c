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
const struct V_31 * V_77 ;
struct V_30 * V_78 ;
if ( V_72 -> V_79 ) {
struct V_70 * V_80 ;
struct V_81 * V_82 ;
V_82 = V_72 -> V_79 ;
V_80 = V_82 -> V_83 -> V_84 ( V_26 , V_59 -> V_85 ,
V_82 ) ;
if ( V_80 == NULL )
return - V_68 ;
F_52 ( V_59 , V_80 ) ;
}
V_77 = F_53 ( V_69 ) ;
V_78 = F_15 ( V_77 ) ;
F_14 ( V_78 -> V_86 ) ;
V_11 -> V_87 = * V_78 -> V_86 ;
* V_78 -> V_86 = NULL ;
V_11 -> V_88 = V_72 ;
F_48 ( & V_11 -> V_51 , 0 ) ;
F_54 ( F_51 ( V_59 ) , sizeof( struct V_14 ) ) ;
F_55 ( & V_75 -> V_89 ) ;
F_56 ( & V_11 -> V_90 , & V_75 -> V_91 ) ;
F_57 ( & V_75 -> V_89 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_72 ,
struct V_92 * * V_93 )
{
int V_94 ;
if ( V_72 -> V_79 != NULL )
return F_59 ( V_72 -> V_76 -> V_95 , V_93 ) ;
V_94 = F_60 ( 1 ) ;
F_14 ( * V_93 == NULL ) ;
F_61 ( * V_93 , V_94 ) ;
if ( * V_93 == NULL )
return - V_68 ;
F_61 ( ( * V_93 ) -> V_96 [ 0 ] , sizeof( struct V_97 ) ) ;
if ( ( * V_93 ) -> V_96 [ 0 ] == NULL ) {
F_62 ( * V_93 , V_94 ) ;
return - V_68 ;
}
F_63 ( ( * V_93 ) -> V_96 [ 0 ] ) ;
( * V_93 ) -> V_98 = V_99 ;
F_64 ( & ( * V_93 ) -> V_100 ) ;
return V_94 ;
}
static int F_65 ( struct V_1 * V_72 , struct V_92 * * V_93 )
{
int V_94 ;
if ( V_72 -> V_79 != NULL )
return F_66 ( V_72 -> V_76 -> V_95 , V_93 ) ;
V_94 = F_60 ( 1 ) ;
F_14 ( * V_93 != NULL ) ;
F_62 ( ( * V_93 ) -> V_96 [ 0 ] , sizeof( struct V_97 ) ) ;
F_62 ( * V_93 , V_94 ) ;
* V_93 = NULL ;
return 0 ;
}
static void F_67 ( const struct V_25 * V_26 , struct V_70 * V_59 )
{
struct V_10 * V_11 = F_7 ( F_51 ( V_59 ) ) ;
struct V_74 * V_75 = V_11 -> V_88 -> V_76 ;
F_14 ( F_68 ( & V_11 -> V_51 ) == 0 ) ;
F_55 ( & V_75 -> V_89 ) ;
F_69 ( & V_11 -> V_90 ) ;
F_57 ( & V_75 -> V_89 ) ;
F_70 ( V_59 ) ;
F_71 ( V_59 -> V_85 ) ;
if ( V_11 -> V_87 )
F_65 ( V_11 -> V_88 , & V_11 -> V_87 ) ;
F_34 ( V_11 , V_101 ) ;
}
static int F_72 ( const struct V_25 * V_26 , void * V_52 ,
T_1 V_102 , const struct V_70 * V_13 )
{
struct V_10 * V_59 = F_7 ( F_51 ( V_13 ) ) ;
return (* V_102)( V_26 , V_52 , L_2 , V_59 ) ;
}
static struct V_70 * F_73 ( const struct V_25 * V_26 ,
const struct V_103 * V_104 ,
struct V_81 * V_3 )
{
struct V_10 * V_11 ;
struct V_70 * V_59 = NULL ;
F_14 ( V_104 == NULL ) ;
F_45 ( V_11 , V_101 , V_64 ) ;
if ( V_11 != NULL ) {
struct V_105 * V_104 = & V_11 -> V_106 ;
V_59 = & F_6 ( V_11 ) -> V_107 ;
F_74 ( V_104 ) ;
F_75 ( V_59 , & V_104 -> V_108 , V_3 ) ;
F_76 ( & V_104 -> V_108 , V_59 ) ;
V_11 -> V_12 . V_109 = & V_110 ;
V_59 -> V_111 = & V_112 ;
}
return V_59 ;
}
static int F_77 ( const struct V_25 * V_26 , struct V_1 * V_72 )
{
struct V_113 * V_114 = & V_72 -> V_115 ;
int V_116 ;
V_116 = F_78 ( V_114 , & V_72 -> V_4 ) ;
if ( V_116 ) {
F_79 ( L_3 , V_116 ) ;
return V_116 ;
}
V_116 = F_80 ( & V_114 -> V_117 ) ;
if ( V_116 )
return V_116 ;
V_72 -> V_118 = V_114 ;
return 0 ;
}
static void F_81 ( const struct V_25 * V_26 , struct V_1 * V_72 )
{
if ( V_72 -> V_118 ) {
F_82 ( V_72 -> V_118 ) ;
V_72 -> V_118 = NULL ;
}
}
static void * F_83 ( const struct V_119 * V_120 ,
struct V_121 * V_122 )
{
struct V_24 * V_27 ;
F_45 ( V_27 , V_123 , V_64 ) ;
if ( V_27 == NULL )
V_27 = F_84 ( - V_68 ) ;
return V_27 ;
}
static void F_85 ( const struct V_119 * V_120 ,
struct V_121 * V_122 , void * V_124 )
{
struct V_24 * V_27 = V_124 ;
F_34 ( V_27 , V_123 ) ;
}
static void F_86 ( const struct V_119 * V_120 ,
struct V_121 * V_122 , void * V_124 )
{
}
static void * F_87 ( const struct V_119 * V_120 ,
struct V_121 * V_122 )
{
struct V_125 * V_126 ;
F_45 ( V_126 , V_127 , V_64 ) ;
if ( V_126 == NULL )
V_126 = F_84 ( - V_68 ) ;
return V_126 ;
}
static void F_88 ( const struct V_119 * V_120 ,
struct V_121 * V_122 , void * V_124 )
{
struct V_125 * V_126 = V_124 ;
F_34 ( V_126 , V_127 ) ;
}
static void F_89 ( const struct V_119 * V_120 ,
struct V_121 * V_122 , void * V_124 )
{
}
static struct V_81 * F_90 ( const struct V_25 * V_26 ,
struct V_128 * V_129 ,
struct V_130 * V_131 )
{
struct V_81 * V_132 ;
struct V_1 * V_72 ;
struct V_2 * V_133 ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_134 ;
const char * V_135 ;
int V_116 ;
int V_136 = 0 ;
F_91 ( V_72 ) ;
if ( V_72 == NULL ) {
V_116 = - V_68 ;
goto V_137;
}
V_136 = 1 ;
V_133 = & V_72 -> V_4 ;
V_116 = F_92 ( V_133 , V_129 ) ;
if ( V_116 )
goto V_137;
V_133 -> V_138 . V_83 = & V_139 ;
V_133 -> V_140 = & V_141 ;
V_136 = 2 ;
V_7 = F_93 ( F_94 ( V_131 , 0 ) ) ;
F_14 ( V_7 != NULL ) ;
F_14 ( V_26 != NULL ) ;
V_134 = F_93 ( F_94 ( V_131 , 1 ) ) ;
if ( V_134 == NULL ) {
F_79 ( L_4 ,
F_94 ( V_131 , 1 ) ) ;
V_116 = - V_142 ;
goto V_137;
}
V_132 = V_134 -> V_8 ;
if ( ! strcmp ( V_134 -> V_143 -> V_144 , V_145 ) ) {
F_79 ( L_5 ) ;
V_116 = - V_146 ;
goto V_137;
}
V_116 = F_77 ( V_26 , V_72 ) ;
if ( V_116 )
goto V_137;
V_136 = 3 ;
V_116 = F_95 ( V_26 , V_7 , V_131 ) ;
if ( V_116 )
goto V_137;
V_72 -> V_76 = & V_7 -> V_147 . V_148 ;
V_136 = 4 ;
if ( V_132 != NULL && ! F_96 ( V_132 ) )
V_132 = NULL ;
V_135 = V_134 -> V_143 -> V_144 ;
if ( V_132 != NULL ) {
F_14 ( V_132 != NULL ) ;
if ( V_132 -> V_149 != NULL ) {
V_116 = - V_45 ;
goto V_137;
}
V_132 -> V_149 = & V_72 -> V_118 -> V_117 ;
V_116 = V_132 -> V_150 -> V_151 -> V_152 ( V_26 , V_132 ,
V_132 -> V_150 -> V_153 ,
NULL ) ;
if ( V_116 )
goto V_137;
if ( strcmp ( V_135 , V_154 ) == 0 )
V_72 -> V_155 = 1 ;
else
F_14 ( strcmp ( V_135 ,
V_156 ) == 0 ) ;
} else {
F_14 ( strcmp ( V_135 , V_157 ) == 0 ) ;
}
V_72 -> V_79 = V_132 ;
return & V_133 -> V_138 ;
V_137:
switch ( V_136 ) {
case 4 : {
int V_158 ;
V_158 = F_97 ( V_7 ) ;
if ( V_158 )
F_79 ( L_6 ,
V_7 -> V_159 , V_158 ) ;
}
case 3 :
F_81 ( V_26 , V_72 ) ;
case 2 :
F_98 ( & V_72 -> V_4 ) ;
case 1 :
F_99 ( V_72 ) ;
case 0 :
default:
break;
}
return F_84 ( V_116 ) ;
}
static int F_100 ( const struct V_25 * V_26 , struct V_81 * V_5 ,
const char * V_160 , struct V_81 * V_132 )
{
F_101 () ;
return 0 ;
}
static struct V_81 * F_102 ( const struct V_25 * V_26 ,
struct V_81 * V_5 )
{
struct V_1 * V_72 = F_1 ( F_5 ( V_5 ) ) ;
struct V_81 * V_132 = V_72 -> V_79 ;
while ( V_132 )
V_132 = V_132 -> V_150 -> V_151 -> V_161 ( V_26 , V_132 ) ;
return NULL ;
}
static void F_103 ( const struct V_25 * V_26 ,
struct V_18 * V_22 ,
int V_162 )
{
struct V_21 * V_163 = F_11 ( V_22 ) ;
F_104 ( V_163 ) ;
F_105 ( V_26 , V_163 ) ;
F_106 ( V_26 , V_163 , L_7 , V_22 -> V_66 ) ;
if ( ! V_162 ) {
F_107 ( V_26 , V_163 ) ;
F_108 ( V_26 , V_163 ) ;
F_109 ( V_26 , V_163 ) ;
F_110 ( V_26 , V_163 ) ;
}
F_111 ( V_26 , V_163 ) ;
}
static struct V_81 * F_112 ( const struct V_25 * V_26 ,
struct V_81 * V_5 )
{
struct V_1 * V_72 = F_1 ( F_5 ( V_5 ) ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_10 * V_11 ;
struct V_81 * V_132 = V_72 -> V_79 ;
F_113 ( V_164 , L_8 ,
V_72 , V_132 ) ;
F_114 ( V_26 , & V_72 -> V_118 -> V_117 , - 1 ) ;
F_55 ( & V_75 -> V_89 ) ;
F_115 (eco, &ec->ec_objects, eo_obj_chain)
V_11 -> V_165 = 1 ;
F_57 ( & V_75 -> V_89 ) ;
F_114 ( V_26 , & V_72 -> V_118 -> V_117 , - 1 ) ;
F_113 ( V_164 ,
L_9 ) ;
F_55 ( & V_75 -> V_89 ) ;
while ( ! F_33 ( & V_75 -> V_91 ) ) {
F_57 ( & V_75 -> V_89 ) ;
F_79 ( L_10 ) ;
F_116 ( V_166 ) ;
F_117 ( F_118 ( 1 ) ) ;
F_114 ( V_26 , & V_72 -> V_118 -> V_117 , - 1 ) ;
F_55 ( & V_75 -> V_89 ) ;
}
F_57 ( & V_75 -> V_89 ) ;
F_14 ( F_33 ( & V_75 -> V_167 ) ) ;
F_113 ( V_164 , L_11 ) ;
F_97 ( V_5 -> V_168 ) ;
while ( V_132 )
V_132 = V_132 -> V_150 -> V_151 -> V_169 ( V_26 , V_132 ) ;
F_14 ( V_72 -> V_118 == F_119 ( V_5 -> V_149 ) ) ;
F_81 ( V_26 , V_72 ) ;
F_98 ( & V_72 -> V_4 ) ;
F_99 ( V_72 ) ;
return NULL ;
}
static struct V_10 * F_120 ( struct V_1 * V_5 ,
struct V_92 * * V_93 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_30 * V_69 ;
struct V_92 * V_170 ;
struct V_10 * V_11 ;
struct V_9 * V_59 ;
struct V_171 * V_172 ;
int V_173 ;
int V_116 ;
F_14 ( V_93 ) ;
V_170 = * V_93 ;
F_14 ( V_170 ) ;
F_121 ( F_122 ( & V_170 -> V_100 ) != 0 , V_174 L_12 , F_123 ( & V_170 -> V_100 ) ) ;
F_121 ( F_124 ( & V_170 -> V_100 ) == V_175 , V_174 L_12 ,
F_123 ( & V_170 -> V_100 ) ) ;
if ( F_3 ( V_5 ) -> V_138 . V_168 -> V_176 )
return F_84 ( - V_142 ) ;
V_26 = F_125 ( & V_173 ) ;
if ( F_126 ( V_26 ) )
return ( void * ) V_26 ;
V_27 = F_12 ( V_26 ) ;
V_69 = & V_27 -> V_177 ;
if ( V_5 -> V_79 ) {
if ( ! V_5 -> V_155 ) {
struct V_97 * V_178 = V_170 -> V_96 [ 0 ] ;
F_14 ( V_178 != NULL ) ;
V_178 -> V_179 = V_170 -> V_100 ;
V_69 -> V_33 . V_147 . V_180 = V_178 ;
} else {
struct V_181 * V_182 ;
V_182 = & V_27 -> V_183 ;
memset ( V_182 , 0 , sizeof( * V_182 ) ) ;
V_182 -> V_170 = V_170 ;
V_69 -> V_33 . V_147 . V_184 = V_182 ;
}
}
V_69 -> V_86 = V_93 ;
V_172 = & V_27 -> V_185 ;
V_116 = F_127 ( V_172 , & V_170 -> V_100 , 0 ) ;
if ( V_116 != 0 ) {
V_11 = F_84 ( V_116 ) ;
goto V_137;
}
V_59 = F_128 ( V_26 , F_3 ( V_5 ) , V_172 , & V_69 -> V_33 ) ;
if ( F_126 ( V_59 ) ) {
V_11 = ( void * ) V_59 ;
goto V_137;
}
V_11 = F_7 ( V_59 ) ;
if ( V_11 -> V_165 ) {
F_129 ( V_26 , V_59 ) ;
V_11 = F_84 ( - V_42 ) ;
}
V_137:
F_130 ( V_26 , & V_173 ) ;
return V_11 ;
}
static int F_131 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
int V_173 ;
V_26 = F_125 ( & V_173 ) ;
if ( F_126 ( V_26 ) )
return F_132 ( V_26 ) ;
if ( V_11 -> V_165 ) {
struct V_103 * V_186 = V_59 -> V_107 . V_85 ;
F_14 ( & V_11 -> V_106 == F_133 ( V_186 ) ) ;
F_134 ( V_187 , & V_186 -> V_188 ) ;
}
F_129 ( V_26 , V_59 ) ;
F_130 ( V_26 , & V_173 ) ;
return 0 ;
}
static int F_135 ( struct V_25 * V_26 , struct V_10 * V_11 ,
T_2 V_189 , T_2 V_190 , int V_191 ,
T_3 * V_52 , T_4 V_192 )
{
struct V_37 * V_38 ;
struct V_21 * V_193 ;
struct V_9 * V_59 ;
struct V_57 * V_194 ;
struct V_24 * V_27 ;
int V_116 = - V_68 ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_195 ;
V_194 = & V_27 -> V_196 ;
V_59 = F_6 ( V_11 ) ;
V_194 -> V_197 = V_59 ;
V_194 -> V_198 = F_136 ( V_59 , V_189 ) ;
V_194 -> V_199 = F_136 ( V_59 , V_190 ) ;
V_194 -> V_200 = V_191 == V_201 ? V_202 : V_203 ;
V_194 -> V_204 = V_192 ;
V_38 -> V_205 = V_59 ;
V_193 = F_137 ( V_26 , V_38 , V_194 , L_7 , V_11 ) ;
if ( V_193 ) {
struct V_74 * V_75 = V_11 -> V_88 -> V_76 ;
struct V_18 * V_63 ;
V_116 = F_138 ( V_26 , V_193 ) ;
if ( V_116 == 0 ) {
V_63 = F_10 ( F_139 ( V_193 , & V_206 ) ) ;
F_55 ( & V_75 -> V_89 ) ;
if ( F_33 ( & V_63 -> V_55 ) ) {
F_140 ( & V_63 -> V_55 , & V_75 -> V_167 ) ;
V_63 -> V_207 = ++ V_75 -> V_208 ;
}
F_42 ( & V_63 -> V_67 ) ;
* V_52 = V_63 -> V_207 ;
F_57 ( & V_75 -> V_89 ) ;
} else {
F_106 ( V_26 , V_193 , L_7 , V_209 ) ;
}
}
return V_116 ;
}
static int F_141 ( struct V_10 * V_11 , T_2 V_189 , T_2 V_190 ,
int V_191 , T_3 * V_52 )
{
struct V_24 * V_27 ;
struct V_25 * V_26 ;
struct V_37 * V_38 ;
int V_173 ;
int V_210 ;
V_26 = F_125 ( & V_173 ) ;
if ( F_126 ( V_26 ) )
return F_132 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_195 ;
V_38 -> V_211 = 1 ;
V_210 = F_142 ( V_26 , V_38 , V_212 , F_6 ( V_11 ) ) ;
if ( V_210 < 0 )
goto V_137;
F_14 ( V_210 == 0 ) ;
V_210 = F_135 ( V_26 , V_11 , V_189 , V_190 , V_191 , V_52 , 0 ) ;
F_143 ( V_26 , V_38 ) ;
V_137:
F_130 ( V_26 , & V_173 ) ;
return V_210 ;
}
static int F_144 ( struct V_25 * V_26 , struct V_1 * V_72 ,
T_3 V_52 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_18 * V_22 = NULL ;
struct V_213 * V_63 ;
int V_214 = 0 , V_162 = 0 ;
F_14 ( V_75 != NULL ) ;
F_55 ( & V_75 -> V_89 ) ;
F_145 (el, &ec->ec_locks) {
V_22 = F_146 ( V_63 , struct V_18 , V_55 ) ;
F_113 ( V_164 , L_13 , V_22 , V_22 -> V_207 ) ;
V_214 = ( V_22 -> V_207 == V_52 ) ;
if ( V_214 ) {
if ( F_147 ( & V_22 -> V_67 ) )
F_69 ( & V_22 -> V_55 ) ;
else
V_162 = 1 ;
break;
}
}
F_57 ( & V_75 -> V_89 ) ;
if ( ! V_214 )
return - V_215 ;
F_103 ( V_26 , V_22 , V_162 ) ;
return 0 ;
}
static int F_148 ( struct V_1 * V_72 , T_3 V_52 )
{
struct V_25 * V_26 ;
int V_173 ;
int V_116 ;
V_26 = F_125 ( & V_173 ) ;
if ( F_126 ( V_26 ) )
return F_132 ( V_26 ) ;
V_116 = F_144 ( V_26 , V_72 , V_52 ) ;
F_130 ( V_26 , & V_173 ) ;
return V_116 ;
}
static int F_149 ( const struct V_25 * V_26 , struct V_37 * V_38 ,
enum V_216 V_43 , struct V_217 * V_218 )
{
struct V_60 * V_219 ;
struct V_60 * V_220 ;
int V_210 = 0 ;
F_150 (clp, temp, &queue->c2_qin) {
int V_116 ;
V_116 = F_151 ( V_26 , V_38 , V_219 , V_221 ) ;
if ( V_116 == 0 )
continue;
V_210 = V_210 ? : V_116 ;
}
return V_210 ;
}
static int F_152 ( struct V_10 * V_11 , int V_222 , T_2 V_223 ,
struct V_34 * * V_224 , int V_225 , int V_226 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
struct V_1 * V_72 = V_11 -> V_88 ;
struct V_217 * V_218 ;
struct V_37 * V_38 ;
struct V_60 * V_219 ;
struct V_227 V_228 = { 0 } ;
int V_229 = F_153 ( V_59 ) ;
int V_173 ;
int V_116 ;
int V_230 ;
F_14 ( ( V_223 & ~ V_231 ) == 0 ) ;
F_14 ( V_72 -> V_79 != NULL ) ;
V_26 = F_125 ( & V_173 ) ;
if ( F_126 ( V_26 ) )
return F_132 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_195 ;
V_218 = & V_27 -> V_232 ;
F_154 ( V_218 ) ;
V_38 -> V_211 = 1 ;
V_116 = F_142 ( V_26 , V_38 , V_212 , V_59 ) ;
if ( V_116 < 0 )
goto V_137;
F_14 ( V_116 == 0 ) ;
V_116 = F_135 ( V_26 , V_11 , V_223 ,
V_223 + V_225 * V_233 - 1 ,
V_222 == V_234 ? V_235 : V_201 , & V_228 . V_52 ,
V_236 ) ;
if ( V_116 < 0 )
goto V_237;
for ( V_230 = 0 ; V_230 < V_225 ; V_230 ++ ) {
F_14 ( V_224 [ V_230 ] ) ;
V_219 = F_155 ( V_26 , V_59 , F_136 ( V_59 , V_223 ) ,
V_224 [ V_230 ] , V_238 ) ;
if ( F_126 ( V_219 ) ) {
V_116 = F_132 ( V_219 ) ;
break;
}
F_14 ( V_219 -> V_239 == V_238 ) ;
V_116 = F_156 ( V_26 , V_38 , V_219 ) ;
if ( V_116 ) {
F_14 ( V_219 -> V_240 == V_241 ) ;
F_157 ( V_26 , V_219 ) ;
break;
}
F_158 ( V_218 , V_219 ) ;
F_157 ( V_26 , V_219 ) ;
F_159 ( V_26 , V_219 , 0 , V_229 ) ;
V_223 += V_229 ;
}
if ( V_116 == 0 ) {
enum V_216 V_242 = V_222 == V_234 ? V_243 : V_221 ;
V_226 = V_226 && ( V_242 == V_221 ) ;
if ( V_226 )
V_116 = F_149 ( V_26 , V_38 , V_242 , V_218 ) ;
else
V_116 = F_160 ( V_26 , V_38 , V_242 , V_218 , 0 ) ;
F_113 ( V_164 , L_14 ,
V_226 ? L_15 : L_16 , V_116 ) ;
}
F_144 ( V_26 , V_72 , V_228 . V_52 ) ;
V_237:
F_161 ( V_26 , V_38 , V_218 ) ;
F_162 ( V_26 , V_38 , V_218 ) ;
F_163 ( V_26 , V_218 ) ;
F_143 ( V_26 , V_38 ) ;
V_137:
F_130 ( V_26 , & V_173 ) ;
return V_116 ;
}
static int
F_164 ( struct V_92 * V_170 , void * V_244 , int V_245 )
{
struct V_92 * V_246 = V_244 ;
int V_247 , V_230 ;
V_247 = F_165 ( struct V_92 , V_96 [ V_170 -> V_248 ] ) ;
if ( V_247 > V_245 )
return - V_249 ;
if ( F_166 ( V_246 , V_170 , sizeof( * V_246 ) ) )
return - V_250 ;
for ( V_230 = 0 ; V_230 < V_170 -> V_248 ; V_230 ++ ) {
if ( F_166 ( V_246 -> V_96 [ V_230 ] , V_170 -> V_96 [ V_230 ] ,
sizeof( V_170 -> V_96 [ 0 ] ) ) )
return - V_250 ;
}
return 0 ;
}
static int
F_167 ( struct V_1 * V_72 , struct V_92 * V_170 ,
void * V_246 , int V_245 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
int V_230 ;
if ( V_245 < sizeof( * V_170 ) )
return - V_249 ;
if ( F_168 ( V_170 , V_246 , sizeof( * V_170 ) ) )
return - V_250 ;
if ( V_170 -> V_248 > V_75 -> V_251 ||
V_170 -> V_252 != V_253 ||
( V_170 -> V_254 & ( ~ V_231 ) ) != 0 ||
( ( T_3 ) V_170 -> V_254 * V_170 -> V_248 > ~ 0UL ) )
return - V_249 ;
for ( V_230 = 0 ; V_230 < V_170 -> V_248 ; V_230 ++ ) {
if ( F_168 ( V_170 -> V_96 [ V_230 ] ,
( (struct V_92 * ) V_246 ) -> \
V_96 [ V_230 ] ,
sizeof( V_170 -> V_96 [ 0 ] ) ) )
return - V_250 ;
}
return 0 ;
}
static int F_169 ( const struct V_25 * V_26 , struct V_1 * V_72 ,
int V_255 , struct V_256 * V_257 , void * V_246 ,
int V_245 , struct V_258 * V_259 )
{
struct V_10 * V_11 ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_92 * V_170 = NULL ;
int V_116 ;
int V_260 = 0 ;
if ( ( V_257 -> V_261 & V_262 ) == 0 &&
( V_255 ||
V_75 -> V_251 != 0 ) ) {
F_79 ( L_17 ) ;
return - V_249 ;
}
V_116 = F_58 ( V_72 , & V_170 ) ;
if ( V_116 < 0 ) {
F_79 ( L_18 , V_116 ) ;
goto V_263;
}
if ( V_246 != NULL ) {
int V_230 , V_264 ;
V_116 = F_167 ( V_72 , V_170 , V_246 , V_245 ) ;
if ( V_116 != 0 )
goto V_263;
if ( V_170 -> V_248 == 0 )
V_170 -> V_248 = V_75 -> V_251 ;
if ( V_170 -> V_254 == 0 )
V_170 -> V_254 = V_233 ;
V_264 = F_170 () ;
for ( V_230 = 0 ; V_230 < V_170 -> V_248 ; V_230 ++ ) {
if ( F_122 ( & V_170 -> V_96 [ V_230 ] -> V_179 ) == 0 )
V_170 -> V_96 [ V_230 ] -> V_179 = V_170 -> V_100 ;
V_170 -> V_96 [ V_230 ] -> V_265 =
( V_264 + V_230 ) % V_75 -> V_251 ;
}
}
if ( V_257 -> V_261 & V_262 ) {
F_14 ( V_257 -> V_261 & V_266 ) ;
V_170 -> V_100 = V_257 -> V_267 ;
}
if ( F_122 ( & V_170 -> V_100 ) == 0 )
F_171 ( & V_170 -> V_100 , ++ V_268 ) ;
V_116 = 0 ;
if ( V_255 ) {
F_14 ( ( V_257 -> V_261 & V_266 ) &&
( F_124 ( & V_257 -> V_267 ) == V_175 ) ) ;
V_116 = F_172 ( V_26 , V_75 -> V_95 , V_257 , & V_170 , V_259 ) ;
if ( V_116 != 0 ) {
F_79 ( L_19 , V_116 ) ;
goto V_263;
}
V_260 = 1 ;
}
V_257 -> V_267 = V_170 -> V_100 ;
V_257 -> V_261 |= V_262 ;
V_11 = F_120 ( V_72 , & V_170 ) ;
if ( F_126 ( V_11 ) ) {
V_116 = F_132 ( V_11 ) ;
goto V_263;
}
F_131 ( V_11 ) ;
F_113 ( V_164 , L_20 V_174 L_12 , F_123 ( & V_257 -> V_267 ) ) ;
V_263:
if ( V_260 && V_116 )
F_173 ( V_26 , V_75 -> V_95 , V_257 , V_170 , V_259 , NULL , NULL ) ;
if ( V_170 )
F_65 ( V_72 , & V_170 ) ;
if ( V_116 )
F_79 ( L_21 , V_116 ) ;
return V_116 ;
}
static int F_174 ( struct V_10 * * V_269 , struct V_1 * V_72 ,
struct V_256 * V_257 )
{
struct V_92 * V_170 = NULL ;
struct V_10 * V_11 ;
int V_116 ;
if ( ( V_257 -> V_261 & V_262 ) == 0 || F_122 ( & V_257 -> V_267 ) == 0 ) {
F_79 ( L_17 ) ;
return - V_249 ;
}
V_116 = F_58 ( V_72 , & V_170 ) ;
if ( V_116 < 0 )
return V_116 ;
V_170 -> V_100 = V_257 -> V_267 ;
if ( ! ( V_257 -> V_261 & V_266 ) )
F_64 ( & V_170 -> V_100 ) ;
V_116 = 0 ;
V_11 = F_120 ( V_72 , & V_170 ) ;
if ( ! F_126 ( V_11 ) )
* V_269 = V_11 ;
else
V_116 = F_132 ( V_11 ) ;
if ( V_170 )
F_65 ( V_72 , & V_170 ) ;
return V_116 ;
}
static void F_175 ( struct V_10 * V_11 )
{
if ( F_131 ( V_11 ) )
F_79 ( L_22 ) ;
}
static void
F_176 ( struct V_92 * V_170 , T_2 * V_270 , T_2 * V_271 )
{
unsigned long V_272 ;
unsigned long V_273 ;
unsigned long V_274 ;
unsigned long V_275 ;
int V_276 ;
T_2 V_223 ;
if ( V_170 -> V_248 <= 1 )
return;
V_223 = * V_270 ;
V_273 = V_170 -> V_254 ;
V_272 = V_170 -> V_248 ;
V_274 = V_273 * V_272 ;
V_275 = F_177 ( V_223 , V_274 ) ;
V_276 = V_275 / V_273 ;
* V_271 = F_122 ( & V_170 -> V_96 [ V_276 ] -> V_179 ) ;
* V_270 = V_223 * V_273 + V_275 % V_273 ;
}
static void
F_178 ( struct V_92 * V_170 ,
struct V_34 * V_34 , int V_222 , T_2 V_277 ,
T_2 V_223 , T_2 V_278 )
{
char * V_279 ;
T_2 V_280 ;
T_2 V_281 ;
int V_282 ;
F_14 ( V_278 == V_233 ) ;
V_279 = F_179 ( V_34 ) ;
for ( V_282 = 0 ; V_282 < V_233 ; V_282 += V_283 ) {
if ( V_222 == V_284 ) {
V_280 = V_223 + V_282 ;
V_281 = V_277 ;
F_176 ( V_170 , & V_280 , & V_281 ) ;
} else {
V_280 = 0xdeadbeef00c0ffeeULL ;
V_281 = 0xdeadbeef00c0ffeeULL ;
}
F_180 ( V_279 + V_282 , V_283 ,
V_280 , V_281 ) ;
}
F_181 ( V_34 ) ;
}
static int F_182 ( struct V_92 * V_170 ,
struct V_34 * V_34 , T_2 V_277 ,
T_2 V_223 , T_2 V_278 )
{
T_2 V_280 ;
T_2 V_281 ;
char * V_279 ;
int V_282 ;
int V_116 ;
int V_158 ;
F_14 ( V_278 == V_233 ) ;
V_279 = F_179 ( V_34 ) ;
for ( V_116 = V_282 = 0 ; V_282 < V_233 ; V_282 += V_283 ) {
V_280 = V_223 + V_282 ;
V_281 = V_277 ;
F_176 ( V_170 , & V_280 , & V_281 ) ;
V_158 = F_183 ( L_23 ,
V_279 + V_282 , V_283 ,
V_280 , V_281 ) ;
if ( V_158 != 0 ) {
F_79 ( L_24 , V_277 ) ;
V_116 = V_158 ;
}
}
F_181 ( V_34 ) ;
return V_116 ;
}
static int F_184 ( struct V_1 * V_72 , int V_222 , struct V_256 * V_257 ,
struct V_10 * V_11 , T_2 V_223 ,
T_2 V_278 , int V_226 ,
struct V_258 * V_259 )
{
struct V_92 * V_170 = V_11 -> V_87 ;
T_5 V_225 ;
struct V_285 * V_286 ;
struct V_285 * V_287 ;
struct V_34 * * V_224 ;
T_2 V_288 ;
int V_230 ;
int V_116 ;
int V_289 ;
T_6 V_290 ;
int V_291 = 0 ;
V_289 = ( F_122 ( & V_257 -> V_267 ) != V_292 &&
( V_257 -> V_261 & V_293 ) != 0 &&
( V_257 -> V_294 & V_295 ) != 0 ) ;
V_290 = ( ( F_122 ( & V_257 -> V_267 ) & 2 ) == 0 ) ? V_296 : V_297 ;
F_14 ( V_222 == V_284 || V_222 == V_298 ) ;
F_14 ( V_170 != NULL ) ;
F_14 ( F_122 ( & V_170 -> V_100 ) == F_122 ( & V_257 -> V_267 ) ) ;
if ( V_278 <= 0 ||
( V_278 & ( ~ V_231 ) ) != 0 )
return - V_249 ;
V_225 = V_278 >> V_299 ;
if ( V_222 == V_284 )
V_291 = V_300 ;
F_61 ( V_286 , V_225 * sizeof( * V_286 ) ) ;
if ( V_286 == NULL )
return - V_68 ;
F_61 ( V_224 , V_225 * sizeof( * V_224 ) ) ;
if ( V_224 == NULL ) {
F_62 ( V_286 , V_225 * sizeof( * V_286 ) ) ;
return - V_68 ;
}
for ( V_230 = 0 , V_287 = V_286 , V_288 = V_223 ;
V_230 < V_225 ;
V_230 ++ , V_287 ++ , V_288 += V_233 ) {
F_14 ( V_287 -> V_301 == NULL ) ;
V_116 = - V_68 ;
F_185 ( V_287 -> V_301 , V_290 ) ;
if ( V_287 -> V_301 == NULL )
goto V_137;
V_224 [ V_230 ] = V_287 -> V_301 ;
V_287 -> V_278 = V_233 ;
V_287 -> V_288 = V_288 ;
V_287 -> V_302 = V_291 ;
if ( V_289 )
F_178 ( V_170 , V_287 -> V_301 , V_222 ,
F_122 ( & V_257 -> V_267 ) , V_288 ,
V_287 -> V_278 ) ;
}
F_14 ( V_72 -> V_79 != NULL ) ;
V_116 = F_152 ( V_11 , V_222 , V_223 , V_224 , V_225 , V_226 ) ;
V_137:
if ( V_116 != 0 || V_222 != V_298 )
V_289 = 0 ;
for ( V_230 = 0 , V_287 = V_286 ; V_230 < V_225 ; V_230 ++ , V_287 ++ ) {
if ( V_287 -> V_301 == NULL )
continue;
if ( V_289 ) {
int V_303 ;
V_303 = F_182 ( V_170 , V_287 -> V_301 ,
F_122 ( & V_257 -> V_267 ) ,
V_287 -> V_288 , V_287 -> V_278 ) ;
if ( V_303 != 0 && V_116 == 0 )
V_116 = V_303 ;
}
F_186 ( V_287 -> V_301 ) ;
}
F_62 ( V_286 , V_225 * sizeof( * V_286 ) ) ;
F_62 ( V_224 , V_225 * sizeof( * V_224 ) ) ;
return V_116 ;
}
static int F_187 ( const struct V_25 * V_26 ,
struct V_304 * exp , int V_222 ,
struct V_256 * V_257 , struct V_10 * V_11 ,
T_2 V_223 , T_2 V_278 ,
T_2 V_305 , struct V_258 * V_259 ,
int V_226 )
{
struct V_92 * V_170 = V_11 -> V_87 ;
struct V_306 V_307 ;
struct V_308 * V_309 ;
struct V_310 * V_311 ;
T_2 V_288 ;
T_2 V_225 , V_312 ;
int V_230 , V_313 = 0 , V_291 = 0 ;
if ( V_278 <= 0 || ( V_278 & ( ~ V_231 ) ) != 0 ||
( V_170 != NULL && F_122 ( & V_170 -> V_100 ) != F_122 ( & V_257 -> V_267 ) ) )
return - V_249 ;
V_225 = V_305 >> V_299 ;
V_312 = V_278 >> V_299 ;
F_61 ( V_309 , V_225 * sizeof( struct V_308 ) ) ;
F_61 ( V_311 , V_225 * sizeof( struct V_310 ) ) ;
if ( V_309 == NULL || V_311 == NULL ) {
V_313 = - V_68 ;
goto V_137;
}
if ( V_222 == V_284 && V_226 )
V_291 |= V_300 ;
F_188 ( V_257 , & V_307 ) ;
V_288 = V_223 ;
for (; V_312 ; V_312 -= V_225 ) {
int V_314 ;
if ( V_312 < V_225 )
V_225 = V_312 ;
for ( V_230 = 0 ; V_230 < V_225 ; V_230 ++ , V_288 += V_233 ) {
V_311 [ V_230 ] . V_223 = V_288 ;
V_311 [ V_230 ] . V_315 = V_233 ;
V_311 [ V_230 ] . V_316 = V_291 ;
}
V_307 . V_317 = V_225 ;
V_259 -> V_318 = 0 ;
V_314 = V_225 ;
V_313 = F_189 ( V_26 , V_222 , exp , V_257 , 1 , & V_307 , V_311 , & V_314 ,
V_309 , V_259 , NULL ) ;
if ( V_313 != 0 )
goto V_137;
F_14 ( V_314 == V_225 ) ;
for ( V_230 = 0 ; V_230 < V_314 ; V_230 ++ ) {
struct V_34 * V_34 = V_309 [ V_230 ] . V_34 ;
if ( V_34 == NULL && V_309 [ V_230 ] . V_116 == 0 )
continue;
if ( V_226 )
V_309 [ V_230 ] . V_316 |= V_300 ;
if ( F_122 ( & V_257 -> V_267 ) == V_292 ||
( V_257 -> V_261 & V_293 ) == 0 ||
( V_257 -> V_294 & V_295 ) == 0 )
continue;
if ( V_222 == V_284 )
F_178 ( V_170 , V_34 , V_222 ,
F_122 ( & V_257 -> V_267 ) ,
V_311 [ V_230 ] . V_223 ,
V_311 [ V_230 ] . V_315 ) ;
else
F_182 ( V_170 , V_34 ,
F_122 ( & V_257 -> V_267 ) ,
V_311 [ V_230 ] . V_223 ,
V_311 [ V_230 ] . V_315 ) ;
}
V_313 = F_190 ( V_26 , V_222 , exp , V_257 , 1 , & V_307 ,
V_311 , V_225 , V_309 , V_259 , V_313 ) ;
if ( V_313 != 0 )
goto V_137;
memset ( V_259 , 0 , sizeof( * V_259 ) ) ;
F_191 ( (struct V_119 * ) & V_26 -> V_28 ) ;
F_192 ( (struct V_119 * ) & V_26 -> V_28 ) ;
}
V_137:
if ( V_309 )
F_62 ( V_309 , V_225 * sizeof( struct V_308 ) ) ;
if ( V_311 )
F_62 ( V_311 , V_225 * sizeof( struct V_310 ) ) ;
return V_313 ;
}
static int F_193 ( const struct V_25 * V_26 , int V_222 ,
struct V_304 * exp ,
struct V_319 * V_124 ,
struct V_258 * V_320 )
{
struct V_6 * V_7 = F_194 ( exp ) ;
struct V_1 * V_72 = F_4 ( V_7 ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_256 * V_257 = & V_124 -> V_321 ;
struct V_10 * V_11 ;
int V_116 ;
int V_226 = 1 ;
long V_322 ;
F_14 ( V_257 -> V_261 & V_266 ) ;
V_116 = F_174 ( & V_11 , V_72 , V_257 ) ;
if ( V_116 )
return V_116 ;
V_257 -> V_261 &= ~ V_323 ;
V_322 = ( long ) V_124 -> V_324 ;
if ( V_322 == 1 )
V_226 = 0 ;
if ( V_72 -> V_79 == NULL && V_322 != 3 ) {
V_322 = 3 ;
V_124 -> V_325 = V_124 -> V_326 ;
}
if ( V_124 -> V_325 > V_327 )
V_124 -> V_325 = V_327 ;
switch ( V_322 ) {
case 1 :
case 2 :
V_116 = F_184 ( V_72 , V_222 , V_257 ,
V_11 , V_124 -> V_328 ,
V_124 -> V_326 , V_226 , V_320 ) ;
break;
case 3 :
V_116 = F_187 ( V_26 , V_75 -> V_95 , V_222 , V_257 ,
V_11 , V_124 -> V_328 ,
V_124 -> V_326 , V_124 -> V_325 ,
V_320 , V_226 ) ;
break;
default:
V_116 = - V_249 ;
}
F_175 ( V_11 ) ;
return V_116 ;
}
static int
F_195 ( struct V_304 * exp , struct V_256 * V_257 ,
int V_191 , T_2 V_223 , T_2 V_247 )
{
struct V_1 * V_72 = F_4 ( exp -> V_329 ) ;
struct V_227 * V_330 = & V_257 -> V_331 ;
struct V_10 * V_11 ;
T_2 V_190 ;
int V_116 ;
if ( V_72 -> V_79 == NULL )
return - V_146 ;
if ( ! ( V_191 == V_235 || V_191 == V_201 ) )
return - V_249 ;
if ( ( V_223 & ( ~ V_231 ) ) != 0 ||
( V_247 & ( ~ V_231 ) ) != 0 )
return - V_249 ;
V_116 = F_174 ( & V_11 , V_72 , V_257 ) ;
if ( V_116 != 0 )
return V_116 ;
V_190 = ( V_247 == 0 ) ? ( ( T_2 ) - 1 ) : ( V_223 + V_247 - 1 ) ;
V_116 = F_141 ( V_11 , V_223 , V_190 , V_191 , & V_330 -> V_52 ) ;
if ( V_116 == 0 ) {
V_257 -> V_261 |= V_323 ;
F_113 ( V_164 , L_25 , V_330 -> V_52 ) ;
}
F_175 ( V_11 ) ;
return V_116 ;
}
static int
F_196 ( struct V_304 * exp , struct V_256 * V_257 )
{
struct V_1 * V_72 = F_4 ( exp -> V_329 ) ;
T_3 V_52 = V_257 -> V_331 . V_52 ;
if ( ( V_257 -> V_261 & V_323 ) == 0 )
return - V_249 ;
F_113 ( V_164 , L_25 , V_52 ) ;
return F_148 ( V_72 , V_52 ) ;
}
static int
F_197 ( unsigned int V_332 , struct V_304 * exp , int V_315 ,
void * V_333 , void * V_334 )
{
struct V_6 * V_7 = exp -> V_329 ;
struct V_1 * V_72 = F_4 ( V_7 ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_10 * V_11 ;
struct V_319 * V_124 = V_333 ;
struct V_258 V_320 ;
struct V_25 * V_26 ;
struct V_335 * V_336 ;
struct V_256 * V_257 ;
struct V_171 V_172 ;
int V_222 = V_298 ;
int V_116 = 0 ;
int V_230 ;
memset ( & V_320 , 0 , sizeof( V_320 ) ) ;
V_257 = & V_124 -> V_321 ;
if ( ! ( V_257 -> V_261 & V_266 ) ) {
V_257 -> V_261 |= V_266 ;
F_64 ( & V_257 -> V_267 ) ;
}
V_116 = F_127 ( & V_172 , & V_257 -> V_267 , 0 ) ;
if ( V_116 < 0 )
return V_116 ;
F_91 ( V_26 ) ;
if ( V_26 == NULL )
return - V_68 ;
V_116 = F_198 ( V_26 , V_337 ) ;
if ( V_116 ) {
V_116 = - V_68 ;
goto V_137;
}
switch ( V_332 ) {
case V_338 :
if ( ! F_199 ( V_339 ) ) {
V_116 = - V_340 ;
goto V_137;
}
V_116 = F_169 ( V_26 , V_72 , 1 , V_257 , V_124 -> V_324 ,
V_124 -> V_325 , & V_320 ) ;
goto V_137;
case V_341 :
if ( ! F_199 ( V_339 ) ) {
V_116 = - V_340 ;
goto V_137;
}
V_116 = F_174 ( & V_11 , V_72 , V_257 ) ;
if ( V_116 == 0 ) {
V_116 = F_173 ( V_26 , V_75 -> V_95 , V_257 , V_11 -> V_87 ,
& V_320 , NULL , NULL ) ;
if ( V_116 == 0 )
V_11 -> V_165 = 1 ;
F_175 ( V_11 ) ;
}
goto V_137;
case V_342 :
V_116 = F_174 ( & V_11 , V_72 , V_257 ) ;
if ( V_116 == 0 ) {
struct V_343 V_178 = { { { 0 } } } ;
V_178 . V_344 = V_11 -> V_87 ;
V_178 . V_345 = V_257 ;
V_116 = F_200 ( V_26 , V_75 -> V_95 , & V_178 ) ;
F_175 ( V_11 ) ;
}
goto V_137;
case V_346 :
if ( ! F_199 ( V_339 ) ) {
V_116 = - V_340 ;
goto V_137;
}
V_116 = F_174 ( & V_11 , V_72 , V_257 ) ;
if ( V_116 == 0 ) {
struct V_343 V_178 = { { { 0 } } } ;
V_178 . V_345 = V_257 ;
V_178 . V_344 = V_11 -> V_87 ;
V_116 = F_201 ( V_26 , V_75 -> V_95 , & V_178 , NULL ) ;
F_175 ( V_11 ) ;
}
goto V_137;
case V_347 :
if ( ! F_199 ( V_339 ) ) {
V_116 = - V_340 ;
goto V_137;
}
V_222 = V_284 ;
case V_348 :
V_116 = F_193 ( V_26 , V_222 , exp , V_124 , & V_320 ) ;
goto V_137;
case V_349 :
V_116 = F_174 ( & V_11 , V_72 , V_257 ) ;
if ( V_116 == 0 ) {
V_116 = F_164 ( V_11 -> V_87 , V_124 -> V_324 ,
V_124 -> V_325 ) ;
F_175 ( V_11 ) ;
}
goto V_137;
case V_350 :
if ( ! F_199 ( V_339 ) ) {
V_116 = - V_340 ;
goto V_137;
}
if ( V_124 -> V_324 == NULL ) {
V_116 = F_174 ( & V_11 , V_72 , V_257 ) ;
if ( V_116 == 0 ) {
V_11 -> V_165 = 1 ;
F_175 ( V_11 ) ;
}
} else {
V_116 = F_169 ( V_26 , V_72 , 0 , V_257 ,
V_124 -> V_324 ,
V_124 -> V_325 , & V_320 ) ;
}
goto V_137;
case V_351 :
if ( ! F_199 ( V_339 ) ) {
V_116 = - V_340 ;
goto V_137;
}
V_116 = F_195 ( exp , V_257 ,
V_124 -> V_352 ,
V_124 -> V_328 ,
V_124 -> V_326 ) ;
goto V_137;
case V_353 :
V_116 = F_196 ( exp , V_257 ) ;
goto V_137;
default:
F_79 ( L_26 , V_332 ) ;
V_116 = - V_354 ;
goto V_137;
}
V_137:
F_202 ( V_26 ) ;
F_99 ( V_26 ) ;
for ( V_336 = V_320 . V_355 , V_230 = 0 ; V_230 < 4 ;
V_230 ++ , V_336 ++ ) {
if ( ! V_336 -> V_191 )
break;
F_203 ( & V_336 -> V_62 , V_336 -> V_191 ) ;
}
return V_116 ;
}
static int F_95 ( const struct V_25 * V_26 ,
struct V_6 * V_356 , struct V_130 * V_357 )
{
struct V_74 * V_75 = & V_356 -> V_147 . V_148 ;
struct V_6 * V_134 ;
struct V_358 V_359 = { L_27 } ;
struct V_360 * V_361 = NULL ;
int V_116 ;
if ( V_357 -> V_362 < 2 || F_204 ( V_357 , 1 ) < 1 ) {
F_79 ( L_28 ) ;
return - V_249 ;
}
V_134 = F_93 ( F_94 ( V_357 , 1 ) ) ;
if ( ! V_134 || ! V_134 -> V_363 || ! V_134 -> V_364 ) {
F_79 ( L_29 ,
F_94 ( V_357 , 1 ) ) ;
return - V_249 ;
}
F_205 ( & V_75 -> V_89 ) ;
F_47 ( & V_75 -> V_91 ) ;
F_47 ( & V_75 -> V_167 ) ;
V_75 -> V_208 = 0 ;
V_75 -> V_251 = 0 ;
F_61 ( V_361 , sizeof( * V_361 ) ) ;
if ( V_361 == NULL ) {
F_79 ( L_30 ,
F_94 ( V_357 , 1 ) ) ;
return - V_68 ;
}
V_361 -> V_365 = V_366 | V_367 |
V_368 |
V_369 | V_370 |
V_371 | V_372 |
V_373 ;
V_361 -> V_374 = V_375 ;
V_361 -> V_376 = V_377 ;
V_361 -> V_378 = V_175 ;
V_116 = F_206 ( V_26 , & V_75 -> V_95 , V_134 , & V_359 , V_361 , NULL ) ;
if ( V_116 == 0 ) {
F_55 ( & V_134 -> V_379 ) ;
F_69 ( & V_75 -> V_95 -> V_380 ) ;
F_57 ( & V_134 -> V_379 ) ;
}
F_62 ( V_361 , sizeof( * V_361 ) ) ;
if ( V_116 != 0 ) {
F_79 ( L_31 ,
F_94 ( V_357 , 1 ) ) ;
return V_116 ;
}
return V_116 ;
}
static int F_97 ( struct V_6 * V_356 )
{
struct V_74 * V_75 = & V_356 -> V_147 . V_148 ;
int V_116 ;
if ( ! F_33 ( & V_356 -> V_381 ) ) {
F_79 ( L_32 ) ;
return - V_45 ;
}
F_14 ( F_68 ( & V_75 -> V_95 -> V_382 ) > 0 ) ;
V_116 = F_207 ( V_75 -> V_95 ) ;
if ( V_116 != 0 )
F_79 ( L_33 , V_116 ) ;
return V_116 ;
}
static int F_208 ( const struct V_25 * V_26 ,
struct V_304 * * exp ,
struct V_6 * V_383 , struct V_358 * V_384 ,
struct V_360 * V_124 , void * V_385 )
{
int V_116 ;
struct V_227 V_386 = { 0 } ;
V_116 = F_209 ( & V_386 , V_383 , V_384 ) ;
if ( V_116 == 0 ) {
* exp = F_210 ( & V_386 ) ;
}
return V_116 ;
}
static int F_211 ( struct V_304 * exp )
{
int V_116 ;
if ( exp == NULL ) {
V_116 = - V_249 ;
goto V_137;
}
V_116 = F_212 ( exp ) ;
goto V_137;
V_137:
return V_116 ;
}
int F_213 ( void )
{
struct V_387 V_388 = { NULL } ;
int V_116 ;
F_214 ( & V_388 ) ;
V_116 = F_215 ( V_389 ) ;
if ( V_116 == 0 ) {
V_116 = F_216 ( & V_390 , NULL ,
V_388 . V_391 ,
V_54 ,
& V_206 ) ;
if ( V_116 )
F_217 ( V_389 ) ;
}
return V_116 ;
}
void F_218 ( void )
{
F_219 ( V_54 ) ;
F_217 ( V_389 ) ;
}
static int T_7 F_220 ( void )
{
struct V_387 V_388 ;
F_221 ( L_34 ) ;
F_14 ( V_233 % V_283 == 0 ) ;
F_214 ( & V_388 ) ;
return F_213 () ;
}
static void F_222 ( void )
{
F_218 () ;
}
