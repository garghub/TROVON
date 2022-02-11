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
F_34 ( V_56 , V_22 ) ;
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
V_63 = F_45 ( V_56 , V_64 | V_65 ) ;
if ( V_63 != NULL ) {
F_46 ( V_62 , & V_63 -> V_20 , V_59 , & V_66 ) ;
V_63 -> V_67 = F_7 ( V_59 ) ;
F_47 ( & V_63 -> V_55 ) ;
F_48 ( & V_63 -> V_68 , 0 ) ;
}
return V_63 == NULL ? - V_69 : 0 ;
}
static int F_49 ( const struct V_25 * V_26 , struct V_9 * V_59 ,
const struct V_31 * V_70 )
{
return 0 ;
}
static int F_50 ( const struct V_25 * V_26 , struct V_71 * V_59 ,
const struct V_72 * V_70 )
{
struct V_1 * V_73 = F_1 ( F_5 ( V_59 -> V_74 ) ) ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_10 * V_11 = F_7 ( F_51 ( V_59 ) ) ;
const struct V_31 * V_78 ;
struct V_30 * V_79 ;
if ( V_73 -> V_80 ) {
struct V_71 * V_81 ;
struct V_82 * V_83 ;
V_83 = V_73 -> V_80 ;
V_81 = V_83 -> V_84 -> V_85 ( V_26 , V_59 -> V_86 ,
V_83 ) ;
if ( V_81 == NULL )
return - V_69 ;
F_52 ( V_59 , V_81 ) ;
}
V_78 = F_53 ( V_70 ) ;
V_79 = F_15 ( V_78 ) ;
F_14 ( V_79 -> V_87 ) ;
V_11 -> V_88 = * V_79 -> V_87 ;
* V_79 -> V_87 = NULL ;
V_11 -> V_89 = V_73 ;
F_48 ( & V_11 -> V_51 , 0 ) ;
F_54 ( F_51 ( V_59 ) , sizeof( struct V_14 ) ) ;
F_55 ( & V_76 -> V_90 ) ;
F_56 ( & V_11 -> V_91 , & V_76 -> V_92 ) ;
F_57 ( & V_76 -> V_90 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_73 ,
struct V_93 * * V_94 )
{
int V_95 ;
if ( V_73 -> V_80 != NULL )
return F_59 ( V_73 -> V_77 -> V_96 , V_94 ) ;
V_95 = F_60 ( 1 ) ;
F_14 ( * V_94 == NULL ) ;
* V_94 = F_61 ( V_95 , V_64 ) ;
if ( ! * V_94 )
return - V_69 ;
( * V_94 ) -> V_97 [ 0 ] = F_61 ( sizeof( struct V_98 ) , V_64 ) ;
if ( ! ( * V_94 ) -> V_97 [ 0 ] ) {
F_62 ( * V_94 ) ;
return - V_69 ;
}
F_63 ( ( * V_94 ) -> V_97 [ 0 ] ) ;
( * V_94 ) -> V_99 = V_100 ;
F_64 ( & ( * V_94 ) -> V_101 ) ;
return V_95 ;
}
static int F_65 ( struct V_1 * V_73 , struct V_93 * * V_94 )
{
int V_95 ;
if ( V_73 -> V_80 != NULL )
return F_66 ( V_73 -> V_77 -> V_96 , V_94 ) ;
V_95 = F_60 ( 1 ) ;
F_14 ( * V_94 != NULL ) ;
F_62 ( ( * V_94 ) -> V_97 [ 0 ] ) ;
F_62 ( * V_94 ) ;
* V_94 = NULL ;
return 0 ;
}
static void F_67 ( const struct V_25 * V_26 , struct V_71 * V_59 )
{
struct V_10 * V_11 = F_7 ( F_51 ( V_59 ) ) ;
struct V_75 * V_76 = V_11 -> V_89 -> V_77 ;
F_14 ( F_68 ( & V_11 -> V_51 ) == 0 ) ;
F_55 ( & V_76 -> V_90 ) ;
F_69 ( & V_11 -> V_91 ) ;
F_57 ( & V_76 -> V_90 ) ;
F_70 ( V_59 ) ;
F_71 ( V_59 -> V_86 ) ;
if ( V_11 -> V_88 )
F_65 ( V_11 -> V_89 , & V_11 -> V_88 ) ;
F_34 ( V_102 , V_11 ) ;
}
static int F_72 ( const struct V_25 * V_26 , void * V_52 ,
T_1 V_103 , const struct V_71 * V_13 )
{
struct V_10 * V_59 = F_7 ( F_51 ( V_13 ) ) ;
return (* V_103)( V_26 , V_52 , L_2 , V_59 ) ;
}
static struct V_71 * F_73 ( const struct V_25 * V_26 ,
const struct V_104 * V_105 ,
struct V_82 * V_3 )
{
struct V_10 * V_11 ;
struct V_71 * V_59 = NULL ;
F_14 ( V_105 == NULL ) ;
V_11 = F_45 ( V_102 , V_64 | V_65 ) ;
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
static int F_77 ( const struct V_25 * V_26 , struct V_1 * V_73 )
{
struct V_114 * V_115 = & V_73 -> V_116 ;
int V_117 ;
V_117 = F_78 ( V_115 , & V_73 -> V_4 ) ;
if ( V_117 ) {
F_79 ( L_3 , V_117 ) ;
return V_117 ;
}
V_117 = F_80 ( & V_115 -> V_118 ) ;
if ( V_117 )
return V_117 ;
V_73 -> V_119 = V_115 ;
return 0 ;
}
static void F_81 ( const struct V_25 * V_26 , struct V_1 * V_73 )
{
if ( V_73 -> V_119 ) {
F_82 ( V_73 -> V_119 ) ;
V_73 -> V_119 = NULL ;
}
}
static void * F_83 ( const struct V_120 * V_121 ,
struct V_122 * V_123 )
{
struct V_24 * V_27 ;
V_27 = F_45 ( V_124 , V_64 | V_65 ) ;
if ( V_27 == NULL )
V_27 = F_84 ( - V_69 ) ;
return V_27 ;
}
static void F_85 ( const struct V_120 * V_121 ,
struct V_122 * V_123 , void * V_125 )
{
struct V_24 * V_27 = V_125 ;
F_34 ( V_124 , V_27 ) ;
}
static void F_86 ( const struct V_120 * V_121 ,
struct V_122 * V_123 , void * V_125 )
{
}
static void * F_87 ( const struct V_120 * V_121 ,
struct V_122 * V_123 )
{
struct V_126 * V_127 ;
V_127 = F_45 ( V_128 , V_64 | V_65 ) ;
if ( V_127 == NULL )
V_127 = F_84 ( - V_69 ) ;
return V_127 ;
}
static void F_88 ( const struct V_120 * V_121 ,
struct V_122 * V_123 , void * V_125 )
{
struct V_126 * V_127 = V_125 ;
F_34 ( V_128 , V_127 ) ;
}
static void F_89 ( const struct V_120 * V_121 ,
struct V_122 * V_123 , void * V_125 )
{
}
static struct V_82 * F_90 ( const struct V_25 * V_26 ,
struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_82 * V_133 ;
struct V_1 * V_73 ;
struct V_2 * V_134 ;
struct V_6 * V_7 = NULL ;
struct V_6 * V_135 ;
const char * V_136 ;
int V_117 ;
int V_137 = 0 ;
V_73 = F_61 ( sizeof( * V_73 ) , V_64 ) ;
if ( ! V_73 ) {
V_117 = - V_69 ;
goto V_138;
}
V_137 = 1 ;
V_134 = & V_73 -> V_4 ;
V_117 = F_91 ( V_134 , V_130 ) ;
if ( V_117 )
goto V_138;
V_134 -> V_139 . V_84 = & V_140 ;
V_134 -> V_141 = & V_142 ;
V_137 = 2 ;
V_7 = F_92 ( F_93 ( V_132 , 0 ) ) ;
F_14 ( V_7 != NULL ) ;
F_14 ( V_26 != NULL ) ;
V_135 = F_92 ( F_93 ( V_132 , 1 ) ) ;
if ( V_135 == NULL ) {
F_79 ( L_4 ,
F_93 ( V_132 , 1 ) ) ;
V_117 = - V_143 ;
goto V_138;
}
V_133 = V_135 -> V_8 ;
if ( ! strcmp ( V_135 -> V_144 -> V_145 , V_146 ) ) {
F_79 ( L_5 ) ;
V_117 = - V_147 ;
goto V_138;
}
V_117 = F_77 ( V_26 , V_73 ) ;
if ( V_117 )
goto V_138;
V_137 = 3 ;
V_117 = F_94 ( V_26 , V_7 , V_132 ) ;
if ( V_117 )
goto V_138;
V_73 -> V_77 = & V_7 -> V_148 . V_149 ;
V_137 = 4 ;
if ( V_133 != NULL && ! F_95 ( V_133 ) )
V_133 = NULL ;
V_136 = V_135 -> V_144 -> V_145 ;
if ( V_133 != NULL ) {
F_14 ( V_133 != NULL ) ;
if ( V_133 -> V_150 != NULL ) {
V_117 = - V_45 ;
goto V_138;
}
V_133 -> V_150 = & V_73 -> V_119 -> V_118 ;
V_117 = V_133 -> V_151 -> V_152 -> V_153 ( V_26 , V_133 ,
V_133 -> V_151 -> V_154 ,
NULL ) ;
if ( V_117 )
goto V_138;
if ( strcmp ( V_136 , V_155 ) == 0 )
V_73 -> V_156 = 1 ;
else
F_14 ( strcmp ( V_136 ,
V_157 ) == 0 ) ;
} else {
F_14 ( strcmp ( V_136 , V_158 ) == 0 ) ;
}
V_73 -> V_80 = V_133 ;
return & V_134 -> V_139 ;
V_138:
switch ( V_137 ) {
case 4 : {
int V_159 ;
V_159 = F_96 ( V_7 ) ;
if ( V_159 )
F_79 ( L_6 ,
V_7 -> V_160 , V_159 ) ;
}
case 3 :
F_81 ( V_26 , V_73 ) ;
case 2 :
F_97 ( & V_73 -> V_4 ) ;
case 1 :
F_62 ( V_73 ) ;
case 0 :
default:
break;
}
return F_84 ( V_117 ) ;
}
static int F_98 ( const struct V_25 * V_26 , struct V_82 * V_5 ,
const char * V_161 , struct V_82 * V_133 )
{
F_99 () ;
return 0 ;
}
static struct V_82 * F_100 ( const struct V_25 * V_26 ,
struct V_82 * V_5 )
{
struct V_1 * V_73 = F_1 ( F_5 ( V_5 ) ) ;
struct V_82 * V_133 = V_73 -> V_80 ;
while ( V_133 )
V_133 = V_133 -> V_151 -> V_152 -> V_162 ( V_26 , V_133 ) ;
return NULL ;
}
static void F_101 ( const struct V_25 * V_26 ,
struct V_18 * V_22 ,
int V_163 )
{
struct V_21 * V_164 = F_11 ( V_22 ) ;
F_102 ( V_164 ) ;
F_103 ( V_26 , V_164 ) ;
F_104 ( V_26 , V_164 , L_7 , V_22 -> V_67 ) ;
if ( ! V_163 ) {
F_105 ( V_26 , V_164 ) ;
F_106 ( V_26 , V_164 ) ;
F_107 ( V_26 , V_164 ) ;
F_108 ( V_26 , V_164 ) ;
}
F_109 ( V_26 , V_164 ) ;
}
static struct V_82 * F_110 ( const struct V_25 * V_26 ,
struct V_82 * V_5 )
{
struct V_1 * V_73 = F_1 ( F_5 ( V_5 ) ) ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_10 * V_11 ;
struct V_82 * V_133 = V_73 -> V_80 ;
F_111 ( V_165 , L_8 ,
V_73 , V_133 ) ;
F_112 ( V_26 , & V_73 -> V_119 -> V_118 , - 1 ) ;
F_55 ( & V_76 -> V_90 ) ;
F_113 (eco, &ec->ec_objects, eo_obj_chain)
V_11 -> V_166 = 1 ;
F_57 ( & V_76 -> V_90 ) ;
F_112 ( V_26 , & V_73 -> V_119 -> V_118 , - 1 ) ;
F_111 ( V_165 ,
L_9 ) ;
F_55 ( & V_76 -> V_90 ) ;
while ( ! F_33 ( & V_76 -> V_92 ) ) {
F_57 ( & V_76 -> V_90 ) ;
F_79 ( L_10 ) ;
F_114 ( V_167 ) ;
F_115 ( F_116 ( 1 ) ) ;
F_112 ( V_26 , & V_73 -> V_119 -> V_118 , - 1 ) ;
F_55 ( & V_76 -> V_90 ) ;
}
F_57 ( & V_76 -> V_90 ) ;
F_14 ( F_33 ( & V_76 -> V_168 ) ) ;
F_111 ( V_165 , L_11 ) ;
F_96 ( V_5 -> V_169 ) ;
while ( V_133 )
V_133 = V_133 -> V_151 -> V_152 -> V_170 ( V_26 , V_133 ) ;
F_14 ( V_73 -> V_119 == F_117 ( V_5 -> V_150 ) ) ;
F_81 ( V_26 , V_73 ) ;
F_97 ( & V_73 -> V_4 ) ;
F_62 ( V_73 ) ;
return NULL ;
}
static struct V_10 * F_118 ( struct V_1 * V_5 ,
struct V_93 * * V_94 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_30 * V_70 ;
struct V_93 * V_171 ;
struct V_10 * V_11 ;
struct V_9 * V_59 ;
struct V_172 * V_173 ;
int V_174 ;
int V_117 ;
F_14 ( V_94 ) ;
V_171 = * V_94 ;
F_14 ( V_171 ) ;
F_119 ( F_120 ( & V_171 -> V_101 ) != 0 , V_175 L_12 , F_121 ( & V_171 -> V_101 ) ) ;
F_119 ( F_122 ( & V_171 -> V_101 ) == V_176 , V_175 L_12 ,
F_121 ( & V_171 -> V_101 ) ) ;
if ( F_3 ( V_5 ) -> V_139 . V_169 -> V_177 )
return F_84 ( - V_143 ) ;
V_26 = F_123 ( & V_174 ) ;
if ( F_124 ( V_26 ) )
return ( void * ) V_26 ;
V_27 = F_12 ( V_26 ) ;
V_70 = & V_27 -> V_178 ;
if ( V_5 -> V_80 ) {
if ( ! V_5 -> V_156 ) {
struct V_98 * V_179 = V_171 -> V_97 [ 0 ] ;
F_14 ( V_179 != NULL ) ;
V_179 -> V_180 = V_171 -> V_101 ;
V_70 -> V_33 . V_148 . V_181 = V_179 ;
} else {
struct V_182 * V_183 ;
V_183 = & V_27 -> V_184 ;
memset ( V_183 , 0 , sizeof( * V_183 ) ) ;
V_183 -> V_171 = V_171 ;
V_70 -> V_33 . V_148 . V_185 = V_183 ;
}
}
V_70 -> V_87 = V_94 ;
V_173 = & V_27 -> V_186 ;
V_117 = F_125 ( V_173 , & V_171 -> V_101 , 0 ) ;
if ( V_117 != 0 ) {
V_11 = F_84 ( V_117 ) ;
goto V_138;
}
V_59 = F_126 ( V_26 , F_3 ( V_5 ) , V_173 , & V_70 -> V_33 ) ;
if ( F_124 ( V_59 ) ) {
V_11 = ( void * ) V_59 ;
goto V_138;
}
V_11 = F_7 ( V_59 ) ;
if ( V_11 -> V_166 ) {
F_127 ( V_26 , V_59 ) ;
V_11 = F_84 ( - V_42 ) ;
}
V_138:
F_128 ( V_26 , & V_174 ) ;
return V_11 ;
}
static int F_129 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
int V_174 ;
V_26 = F_123 ( & V_174 ) ;
if ( F_124 ( V_26 ) )
return F_130 ( V_26 ) ;
if ( V_11 -> V_166 ) {
struct V_104 * V_187 = V_59 -> V_108 . V_86 ;
F_14 ( & V_11 -> V_107 == F_131 ( V_187 ) ) ;
F_132 ( V_188 , & V_187 -> V_189 ) ;
}
F_127 ( V_26 , V_59 ) ;
F_128 ( V_26 , & V_174 ) ;
return 0 ;
}
static int F_133 ( struct V_25 * V_26 , struct V_10 * V_11 ,
T_2 V_190 , T_2 V_191 , int V_192 ,
T_3 * V_52 , T_4 V_193 )
{
struct V_37 * V_38 ;
struct V_21 * V_194 ;
struct V_9 * V_59 ;
struct V_57 * V_195 ;
struct V_24 * V_27 ;
int V_117 = - V_69 ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_196 ;
V_195 = & V_27 -> V_197 ;
V_59 = F_6 ( V_11 ) ;
V_195 -> V_198 = V_59 ;
V_195 -> V_199 = F_134 ( V_59 , V_190 ) ;
V_195 -> V_200 = F_134 ( V_59 , V_191 ) ;
V_195 -> V_201 = V_192 == V_202 ? V_203 : V_204 ;
V_195 -> V_205 = V_193 ;
V_38 -> V_206 = V_59 ;
V_194 = F_135 ( V_26 , V_38 , V_195 , L_7 , V_11 ) ;
if ( V_194 ) {
struct V_75 * V_76 = V_11 -> V_89 -> V_77 ;
struct V_18 * V_63 ;
V_117 = F_136 ( V_26 , V_194 ) ;
if ( V_117 == 0 ) {
V_63 = F_10 ( F_137 ( V_194 , & V_207 ) ) ;
F_55 ( & V_76 -> V_90 ) ;
if ( F_33 ( & V_63 -> V_55 ) ) {
F_138 ( & V_63 -> V_55 , & V_76 -> V_168 ) ;
V_63 -> V_208 = ++ V_76 -> V_209 ;
}
F_42 ( & V_63 -> V_68 ) ;
* V_52 = V_63 -> V_208 ;
F_57 ( & V_76 -> V_90 ) ;
} else {
F_104 ( V_26 , V_194 , L_7 , V_210 ) ;
}
}
return V_117 ;
}
static int F_139 ( struct V_10 * V_11 , T_2 V_190 , T_2 V_191 ,
int V_192 , T_3 * V_52 )
{
struct V_24 * V_27 ;
struct V_25 * V_26 ;
struct V_37 * V_38 ;
int V_174 ;
int V_211 ;
V_26 = F_123 ( & V_174 ) ;
if ( F_124 ( V_26 ) )
return F_130 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_196 ;
V_38 -> V_212 = 1 ;
V_211 = F_140 ( V_26 , V_38 , V_213 , F_6 ( V_11 ) ) ;
if ( V_211 < 0 )
goto V_138;
F_14 ( V_211 == 0 ) ;
V_211 = F_133 ( V_26 , V_11 , V_190 , V_191 , V_192 , V_52 , 0 ) ;
F_141 ( V_26 , V_38 ) ;
V_138:
F_128 ( V_26 , & V_174 ) ;
return V_211 ;
}
static int F_142 ( struct V_25 * V_26 , struct V_1 * V_73 ,
T_3 V_52 )
{
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_18 * V_22 = NULL ;
struct V_214 * V_63 ;
int V_215 = 0 , V_163 = 0 ;
F_14 ( V_76 != NULL ) ;
F_55 ( & V_76 -> V_90 ) ;
F_143 (el, &ec->ec_locks) {
V_22 = F_144 ( V_63 , struct V_18 , V_55 ) ;
F_111 ( V_165 , L_13 , V_22 , V_22 -> V_208 ) ;
V_215 = ( V_22 -> V_208 == V_52 ) ;
if ( V_215 ) {
if ( F_145 ( & V_22 -> V_68 ) )
F_69 ( & V_22 -> V_55 ) ;
else
V_163 = 1 ;
break;
}
}
F_57 ( & V_76 -> V_90 ) ;
if ( ! V_215 )
return - V_216 ;
F_101 ( V_26 , V_22 , V_163 ) ;
return 0 ;
}
static int F_146 ( struct V_1 * V_73 , T_3 V_52 )
{
struct V_25 * V_26 ;
int V_174 ;
int V_117 ;
V_26 = F_123 ( & V_174 ) ;
if ( F_124 ( V_26 ) )
return F_130 ( V_26 ) ;
V_117 = F_142 ( V_26 , V_73 , V_52 ) ;
F_128 ( V_26 , & V_174 ) ;
return V_117 ;
}
static int F_147 ( const struct V_25 * V_26 , struct V_37 * V_38 ,
enum V_217 V_43 , struct V_218 * V_219 )
{
struct V_60 * V_220 ;
struct V_60 * V_221 ;
int V_211 = 0 ;
F_148 (clp, temp, &queue->c2_qin) {
int V_117 ;
V_117 = F_149 ( V_26 , V_38 , V_220 , V_222 ) ;
if ( V_117 == 0 )
continue;
V_211 = V_211 ? : V_117 ;
}
return V_211 ;
}
static int F_150 ( struct V_10 * V_11 , int V_223 , T_2 V_224 ,
struct V_34 * * V_225 , int V_226 , int V_227 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
struct V_1 * V_73 = V_11 -> V_89 ;
struct V_218 * V_219 ;
struct V_37 * V_38 ;
struct V_60 * V_220 ;
struct V_228 V_229 = { 0 } ;
int V_230 = F_151 ( V_59 ) ;
int V_174 ;
int V_117 ;
int V_231 ;
F_14 ( ( V_224 & ~ V_232 ) == 0 ) ;
F_14 ( V_73 -> V_80 != NULL ) ;
V_26 = F_123 ( & V_174 ) ;
if ( F_124 ( V_26 ) )
return F_130 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_196 ;
V_219 = & V_27 -> V_233 ;
F_152 ( V_219 ) ;
V_38 -> V_212 = 1 ;
V_117 = F_140 ( V_26 , V_38 , V_213 , V_59 ) ;
if ( V_117 < 0 )
goto V_138;
F_14 ( V_117 == 0 ) ;
V_117 = F_133 ( V_26 , V_11 , V_224 ,
V_224 + V_226 * V_234 - 1 ,
V_223 == V_235 ? V_236 : V_202 , & V_229 . V_52 ,
V_237 ) ;
if ( V_117 < 0 )
goto V_238;
for ( V_231 = 0 ; V_231 < V_226 ; V_231 ++ ) {
F_14 ( V_225 [ V_231 ] ) ;
V_220 = F_153 ( V_26 , V_59 , F_134 ( V_59 , V_224 ) ,
V_225 [ V_231 ] , V_239 ) ;
if ( F_124 ( V_220 ) ) {
V_117 = F_130 ( V_220 ) ;
break;
}
F_14 ( V_220 -> V_240 == V_239 ) ;
V_117 = F_154 ( V_26 , V_38 , V_220 ) ;
if ( V_117 ) {
F_14 ( V_220 -> V_241 == V_242 ) ;
F_155 ( V_26 , V_220 ) ;
break;
}
F_156 ( & V_219 -> V_243 , V_220 ) ;
F_155 ( V_26 , V_220 ) ;
F_157 ( V_26 , V_220 , 0 , V_230 ) ;
V_224 += V_230 ;
}
if ( V_117 == 0 ) {
enum V_217 V_244 = V_223 == V_235 ? V_245 : V_222 ;
V_227 = V_227 && ( V_244 == V_222 ) ;
if ( V_227 )
V_117 = F_147 ( V_26 , V_38 , V_244 , V_219 ) ;
else
V_117 = F_158 ( V_26 , V_38 , V_244 , V_219 , 0 ) ;
F_111 ( V_165 , L_14 ,
V_227 ? L_15 : L_16 , V_117 ) ;
}
F_142 ( V_26 , V_73 , V_229 . V_52 ) ;
V_238:
F_159 ( V_26 , V_38 , V_219 ) ;
F_160 ( V_26 , V_38 , V_219 ) ;
F_161 ( V_26 , V_219 ) ;
F_141 ( V_26 , V_38 ) ;
V_138:
F_128 ( V_26 , & V_174 ) ;
return V_117 ;
}
static int
F_162 ( struct V_93 * V_171 , void * V_246 , int V_247 )
{
struct V_93 * V_248 = V_246 ;
struct V_98 * * V_103 ;
int V_249 , V_231 ;
V_249 = F_163 ( struct V_93 , V_97 [ V_171 -> V_250 ] ) ;
if ( V_249 > V_247 )
return - V_251 ;
if ( F_164 ( V_248 , V_171 , sizeof( * V_248 ) ) )
return - V_252 ;
for ( V_231 = 0 , V_103 = V_171 -> V_97 ; V_231 < V_171 -> V_250 ; V_231 ++ , V_103 ++ ) {
struct V_98 T_5 * V_253 ;
if ( F_165 ( V_253 , V_248 -> V_97 + V_231 ) ||
F_164 ( V_253 , * V_103 , sizeof( struct V_98 ) ) )
return - V_252 ;
}
return 0 ;
}
static int
F_166 ( struct V_1 * V_73 , struct V_93 * V_171 ,
struct V_93 T_5 * V_248 , int V_247 )
{
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_98 * * V_103 ;
int V_231 ;
if ( V_247 < sizeof( * V_171 ) )
return - V_251 ;
if ( F_167 ( V_171 , V_248 , sizeof( * V_171 ) ) )
return - V_252 ;
if ( V_171 -> V_250 > V_76 -> V_254 ||
V_171 -> V_255 != V_256 ||
( V_171 -> V_257 & ( ~ V_232 ) ) != 0 ||
( ( T_3 ) V_171 -> V_257 * V_171 -> V_250 > ~ 0UL ) )
return - V_251 ;
for ( V_231 = 0 , V_103 = V_171 -> V_97 ; V_231 < V_171 -> V_250 ; V_231 ++ , V_103 ++ ) {
struct V_98 T_5 * V_253 ;
if ( F_165 ( V_253 , V_248 -> V_97 + V_231 ) ||
F_167 ( * V_103 , V_253 , sizeof( struct V_98 ) ) )
return - V_252 ;
}
return 0 ;
}
static int F_168 ( const struct V_25 * V_26 , struct V_1 * V_73 ,
int V_258 , struct V_259 * V_260 , void * V_248 ,
int V_247 , struct V_261 * V_262 )
{
struct V_10 * V_11 ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_93 * V_171 = NULL ;
int V_117 ;
int V_263 = 0 ;
if ( ( V_260 -> V_264 & V_265 ) == 0 &&
( V_258 ||
V_76 -> V_254 != 0 ) ) {
F_79 ( L_17 ) ;
return - V_251 ;
}
V_117 = F_58 ( V_73 , & V_171 ) ;
if ( V_117 < 0 ) {
F_79 ( L_18 , V_117 ) ;
goto V_266;
}
if ( V_248 != NULL ) {
int V_231 , V_267 ;
V_117 = F_166 ( V_73 , V_171 , V_248 , V_247 ) ;
if ( V_117 != 0 )
goto V_266;
if ( V_171 -> V_250 == 0 )
V_171 -> V_250 = V_76 -> V_254 ;
if ( V_171 -> V_257 == 0 )
V_171 -> V_257 = V_234 ;
V_267 = F_169 () ;
for ( V_231 = 0 ; V_231 < V_171 -> V_250 ; V_231 ++ ) {
if ( F_120 ( & V_171 -> V_97 [ V_231 ] -> V_180 ) == 0 )
V_171 -> V_97 [ V_231 ] -> V_180 = V_171 -> V_101 ;
V_171 -> V_97 [ V_231 ] -> V_268 =
( V_267 + V_231 ) % V_76 -> V_254 ;
}
}
if ( V_260 -> V_264 & V_265 ) {
F_14 ( V_260 -> V_264 & V_269 ) ;
V_171 -> V_101 = V_260 -> V_270 ;
}
if ( F_120 ( & V_171 -> V_101 ) == 0 )
F_170 ( & V_171 -> V_101 , ++ V_271 ) ;
V_117 = 0 ;
if ( V_258 ) {
F_14 ( ( V_260 -> V_264 & V_269 ) &&
( F_122 ( & V_260 -> V_270 ) == V_176 ) ) ;
V_117 = F_171 ( V_26 , V_76 -> V_96 , V_260 , & V_171 , V_262 ) ;
if ( V_117 != 0 ) {
F_79 ( L_19 , V_117 ) ;
goto V_266;
}
V_263 = 1 ;
}
V_260 -> V_270 = V_171 -> V_101 ;
V_260 -> V_264 |= V_265 ;
V_11 = F_118 ( V_73 , & V_171 ) ;
if ( F_124 ( V_11 ) ) {
V_117 = F_130 ( V_11 ) ;
goto V_266;
}
F_129 ( V_11 ) ;
F_111 ( V_165 , L_20 V_175 L_12 , F_121 ( & V_260 -> V_270 ) ) ;
V_266:
if ( V_263 && V_117 )
F_172 ( V_26 , V_76 -> V_96 , V_260 , V_171 , V_262 , NULL ) ;
if ( V_171 )
F_65 ( V_73 , & V_171 ) ;
if ( V_117 )
F_79 ( L_21 , V_117 ) ;
return V_117 ;
}
static int F_173 ( struct V_10 * * V_272 , struct V_1 * V_73 ,
struct V_259 * V_260 )
{
struct V_93 * V_171 = NULL ;
struct V_10 * V_11 ;
int V_117 ;
if ( ( V_260 -> V_264 & V_265 ) == 0 || F_120 ( & V_260 -> V_270 ) == 0 ) {
F_79 ( L_17 ) ;
return - V_251 ;
}
V_117 = F_58 ( V_73 , & V_171 ) ;
if ( V_117 < 0 )
return V_117 ;
V_171 -> V_101 = V_260 -> V_270 ;
if ( ! ( V_260 -> V_264 & V_269 ) )
F_64 ( & V_171 -> V_101 ) ;
V_117 = 0 ;
V_11 = F_118 ( V_73 , & V_171 ) ;
if ( ! F_124 ( V_11 ) )
* V_272 = V_11 ;
else
V_117 = F_130 ( V_11 ) ;
if ( V_171 )
F_65 ( V_73 , & V_171 ) ;
return V_117 ;
}
static void F_174 ( struct V_10 * V_11 )
{
if ( F_129 ( V_11 ) )
F_79 ( L_22 ) ;
}
static void
F_175 ( struct V_93 * V_171 , T_2 * V_273 , T_2 * V_274 )
{
unsigned long V_275 ;
unsigned long V_276 ;
unsigned long V_277 ;
unsigned long V_278 ;
int V_279 ;
T_2 V_224 ;
if ( V_171 -> V_250 <= 1 )
return;
V_224 = * V_273 ;
V_276 = V_171 -> V_257 ;
V_275 = V_171 -> V_250 ;
V_277 = V_276 * V_275 ;
V_278 = F_176 ( V_224 , V_277 ) ;
V_279 = V_278 / V_276 ;
* V_274 = F_120 ( & V_171 -> V_97 [ V_279 ] -> V_180 ) ;
* V_273 = V_224 * V_276 + V_278 % V_276 ;
}
static void
F_177 ( struct V_93 * V_171 ,
struct V_34 * V_34 , int V_223 , T_2 V_280 ,
T_2 V_224 , T_2 V_281 )
{
char * V_282 ;
T_2 V_283 ;
T_2 V_284 ;
int V_285 ;
F_14 ( V_281 == V_234 ) ;
V_282 = F_178 ( V_34 ) ;
for ( V_285 = 0 ; V_285 < V_234 ; V_285 += V_286 ) {
if ( V_223 == V_287 ) {
V_283 = V_224 + V_285 ;
V_284 = V_280 ;
F_175 ( V_171 , & V_283 , & V_284 ) ;
} else {
V_283 = 0xdeadbeef00c0ffeeULL ;
V_284 = 0xdeadbeef00c0ffeeULL ;
}
F_179 ( V_282 + V_285 , V_286 ,
V_283 , V_284 ) ;
}
F_180 ( V_34 ) ;
}
static int F_181 ( struct V_93 * V_171 ,
struct V_34 * V_34 , T_2 V_280 ,
T_2 V_224 , T_2 V_281 )
{
T_2 V_283 ;
T_2 V_284 ;
char * V_282 ;
int V_285 ;
int V_117 ;
int V_159 ;
F_14 ( V_281 == V_234 ) ;
V_282 = F_178 ( V_34 ) ;
for ( V_117 = V_285 = 0 ; V_285 < V_234 ; V_285 += V_286 ) {
V_283 = V_224 + V_285 ;
V_284 = V_280 ;
F_175 ( V_171 , & V_283 , & V_284 ) ;
V_159 = F_182 ( L_23 ,
V_282 + V_285 , V_286 ,
V_283 , V_284 ) ;
if ( V_159 != 0 ) {
F_79 ( L_24 , V_280 ) ;
V_117 = V_159 ;
}
}
F_180 ( V_34 ) ;
return V_117 ;
}
static int F_183 ( struct V_1 * V_73 , int V_223 , struct V_259 * V_260 ,
struct V_10 * V_11 , T_2 V_224 ,
T_2 V_281 , int V_227 ,
struct V_261 * V_262 )
{
struct V_93 * V_171 = V_11 -> V_88 ;
T_6 V_226 ;
struct V_288 * V_289 ;
struct V_288 * V_290 ;
struct V_34 * * V_225 ;
T_2 V_291 ;
int V_231 ;
int V_117 ;
int V_292 ;
T_7 V_293 ;
int V_294 = 0 ;
V_292 = ( F_120 ( & V_260 -> V_270 ) != V_295 &&
( V_260 -> V_264 & V_296 ) != 0 &&
( V_260 -> V_297 & V_298 ) != 0 ) ;
V_293 = ( ( F_120 ( & V_260 -> V_270 ) & 2 ) == 0 ) ? V_299 : V_300 ;
F_14 ( V_223 == V_287 || V_223 == V_301 ) ;
F_14 ( V_171 != NULL ) ;
F_14 ( F_120 ( & V_171 -> V_101 ) == F_120 ( & V_260 -> V_270 ) ) ;
if ( V_281 <= 0 ||
( V_281 & ( ~ V_232 ) ) != 0 )
return - V_251 ;
V_226 = V_281 >> V_302 ;
if ( V_223 == V_287 )
V_294 = V_303 ;
V_289 = F_184 ( V_226 , sizeof( * V_289 ) , V_64 ) ;
if ( V_289 == NULL )
return - V_69 ;
V_225 = F_184 ( V_226 , sizeof( * V_225 ) , V_64 ) ;
if ( V_225 == NULL ) {
F_62 ( V_289 ) ;
return - V_69 ;
}
for ( V_231 = 0 , V_290 = V_289 , V_291 = V_224 ;
V_231 < V_226 ;
V_231 ++ , V_290 ++ , V_291 += V_234 ) {
F_14 ( V_290 -> V_304 == NULL ) ;
V_117 = - V_69 ;
V_290 -> V_304 = F_185 ( V_293 ) ;
if ( V_290 -> V_304 == NULL )
goto V_138;
V_225 [ V_231 ] = V_290 -> V_304 ;
V_290 -> V_281 = V_234 ;
V_290 -> V_291 = V_291 ;
V_290 -> V_305 = V_294 ;
if ( V_292 )
F_177 ( V_171 , V_290 -> V_304 , V_223 ,
F_120 ( & V_260 -> V_270 ) , V_291 ,
V_290 -> V_281 ) ;
}
F_14 ( V_73 -> V_80 != NULL ) ;
V_117 = F_150 ( V_11 , V_223 , V_224 , V_225 , V_226 , V_227 ) ;
V_138:
if ( V_117 != 0 || V_223 != V_301 )
V_292 = 0 ;
for ( V_231 = 0 , V_290 = V_289 ; V_231 < V_226 ; V_231 ++ , V_290 ++ ) {
if ( V_290 -> V_304 == NULL )
continue;
if ( V_292 ) {
int V_306 ;
V_306 = F_181 ( V_171 , V_290 -> V_304 ,
F_120 ( & V_260 -> V_270 ) ,
V_290 -> V_291 , V_290 -> V_281 ) ;
if ( V_306 != 0 && V_117 == 0 )
V_117 = V_306 ;
}
F_186 ( V_290 -> V_304 ) ;
}
F_62 ( V_289 ) ;
F_62 ( V_225 ) ;
return V_117 ;
}
static int F_187 ( const struct V_25 * V_26 ,
struct V_307 * exp , int V_223 ,
struct V_259 * V_260 , struct V_10 * V_11 ,
T_2 V_224 , T_2 V_281 ,
T_2 V_308 , struct V_261 * V_262 ,
int V_227 )
{
struct V_93 * V_171 = V_11 -> V_88 ;
struct V_309 V_310 ;
struct V_311 * V_312 ;
struct V_313 * V_314 ;
T_2 V_291 ;
T_2 V_226 , V_315 ;
int V_231 , V_316 = 0 , V_294 = 0 ;
if ( V_281 <= 0 || ( V_281 & ( ~ V_232 ) ) != 0 ||
( V_171 != NULL && F_120 ( & V_171 -> V_101 ) != F_120 ( & V_260 -> V_270 ) ) )
return - V_251 ;
V_226 = V_308 >> V_302 ;
V_315 = V_281 >> V_302 ;
V_312 = F_184 ( V_226 , sizeof( struct V_311 ) , V_64 ) ;
V_314 = F_184 ( V_226 , sizeof( struct V_313 ) , V_64 ) ;
if ( V_312 == NULL || V_314 == NULL ) {
V_316 = - V_69 ;
goto V_138;
}
if ( V_223 == V_287 && V_227 )
V_294 |= V_303 ;
F_188 ( V_260 , & V_310 ) ;
V_291 = V_224 ;
for (; V_315 ; V_315 -= V_226 ) {
int V_317 ;
if ( V_315 < V_226 )
V_226 = V_315 ;
for ( V_231 = 0 ; V_231 < V_226 ; V_231 ++ , V_291 += V_234 ) {
V_314 [ V_231 ] . V_224 = V_291 ;
V_314 [ V_231 ] . V_318 = V_234 ;
V_314 [ V_231 ] . V_319 = V_294 ;
}
V_310 . V_320 = V_226 ;
V_262 -> V_321 = 0 ;
V_317 = V_226 ;
V_316 = F_189 ( V_26 , V_223 , exp , V_260 , 1 , & V_310 , V_314 , & V_317 ,
V_312 , V_262 ) ;
if ( V_316 != 0 )
goto V_138;
F_14 ( V_317 == V_226 ) ;
for ( V_231 = 0 ; V_231 < V_317 ; V_231 ++ ) {
struct V_34 * V_34 = V_312 [ V_231 ] . V_34 ;
if ( V_34 == NULL && V_312 [ V_231 ] . V_117 == 0 )
continue;
if ( V_227 )
V_312 [ V_231 ] . V_319 |= V_303 ;
if ( F_120 ( & V_260 -> V_270 ) == V_295 ||
( V_260 -> V_264 & V_296 ) == 0 ||
( V_260 -> V_297 & V_298 ) == 0 )
continue;
if ( V_223 == V_287 )
F_177 ( V_171 , V_34 , V_223 ,
F_120 ( & V_260 -> V_270 ) ,
V_314 [ V_231 ] . V_224 ,
V_314 [ V_231 ] . V_318 ) ;
else
F_181 ( V_171 , V_34 ,
F_120 ( & V_260 -> V_270 ) ,
V_314 [ V_231 ] . V_224 ,
V_314 [ V_231 ] . V_318 ) ;
}
V_316 = F_190 ( V_26 , V_223 , exp , V_260 , 1 , & V_310 ,
V_314 , V_226 , V_312 , V_262 , V_316 ) ;
if ( V_316 != 0 )
goto V_138;
memset ( V_262 , 0 , sizeof( * V_262 ) ) ;
F_191 ( (struct V_120 * ) & V_26 -> V_28 ) ;
F_192 ( (struct V_120 * ) & V_26 -> V_28 ) ;
}
V_138:
F_62 ( V_312 ) ;
F_62 ( V_314 ) ;
return V_316 ;
}
static int F_193 ( const struct V_25 * V_26 , int V_223 ,
struct V_307 * exp ,
struct V_322 * V_125 ,
struct V_261 * V_323 )
{
struct V_6 * V_7 = F_194 ( exp ) ;
struct V_1 * V_73 = F_4 ( V_7 ) ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_259 * V_260 = & V_125 -> V_324 ;
struct V_10 * V_11 ;
int V_117 ;
int V_227 = 1 ;
long V_325 ;
F_14 ( V_260 -> V_264 & V_269 ) ;
V_117 = F_173 ( & V_11 , V_73 , V_260 ) ;
if ( V_117 )
return V_117 ;
V_260 -> V_264 &= ~ V_326 ;
V_325 = ( long ) V_125 -> V_327 ;
if ( V_325 == 1 )
V_227 = 0 ;
if ( V_73 -> V_80 == NULL && V_325 != 3 ) {
V_325 = 3 ;
V_125 -> V_328 = V_125 -> V_329 ;
}
if ( V_125 -> V_328 > V_330 )
V_125 -> V_328 = V_330 ;
switch ( V_325 ) {
case 1 :
case 2 :
V_117 = F_183 ( V_73 , V_223 , V_260 ,
V_11 , V_125 -> V_331 ,
V_125 -> V_329 , V_227 , V_323 ) ;
break;
case 3 :
V_117 = F_187 ( V_26 , V_76 -> V_96 , V_223 , V_260 ,
V_11 , V_125 -> V_331 ,
V_125 -> V_329 , V_125 -> V_328 ,
V_323 , V_227 ) ;
break;
default:
V_117 = - V_251 ;
}
F_174 ( V_11 ) ;
return V_117 ;
}
static int
F_195 ( struct V_307 * exp , struct V_259 * V_260 ,
int V_192 , T_2 V_224 , T_2 V_249 )
{
struct V_1 * V_73 = F_4 ( exp -> V_332 ) ;
struct V_228 * V_333 = & V_260 -> V_334 ;
struct V_10 * V_11 ;
T_2 V_191 ;
int V_117 ;
if ( V_73 -> V_80 == NULL )
return - V_147 ;
if ( ! ( V_192 == V_236 || V_192 == V_202 ) )
return - V_251 ;
if ( ( V_224 & ( ~ V_232 ) ) != 0 ||
( V_249 & ( ~ V_232 ) ) != 0 )
return - V_251 ;
V_117 = F_173 ( & V_11 , V_73 , V_260 ) ;
if ( V_117 != 0 )
return V_117 ;
V_191 = ( V_249 == 0 ) ? ( ( T_2 ) - 1 ) : ( V_224 + V_249 - 1 ) ;
V_117 = F_139 ( V_11 , V_224 , V_191 , V_192 , & V_333 -> V_52 ) ;
if ( V_117 == 0 ) {
V_260 -> V_264 |= V_326 ;
F_111 ( V_165 , L_25 , V_333 -> V_52 ) ;
}
F_174 ( V_11 ) ;
return V_117 ;
}
static int
F_196 ( struct V_307 * exp , struct V_259 * V_260 )
{
struct V_1 * V_73 = F_4 ( exp -> V_332 ) ;
T_3 V_52 = V_260 -> V_334 . V_52 ;
if ( ( V_260 -> V_264 & V_326 ) == 0 )
return - V_251 ;
F_111 ( V_165 , L_25 , V_52 ) ;
return F_146 ( V_73 , V_52 ) ;
}
static int
F_197 ( unsigned int V_335 , struct V_307 * exp , int V_318 ,
void * V_336 , void * V_337 )
{
struct V_6 * V_7 = exp -> V_332 ;
struct V_1 * V_73 = F_4 ( V_7 ) ;
struct V_75 * V_76 = V_73 -> V_77 ;
struct V_10 * V_11 ;
struct V_322 * V_125 = V_336 ;
struct V_261 V_323 ;
struct V_25 * V_26 ;
struct V_338 * V_339 ;
struct V_259 * V_260 ;
struct V_172 V_173 ;
int V_223 = V_301 ;
int V_117 = 0 ;
int V_231 ;
memset ( & V_323 , 0 , sizeof( V_323 ) ) ;
V_260 = & V_125 -> V_324 ;
if ( ! ( V_260 -> V_264 & V_269 ) ) {
V_260 -> V_264 |= V_269 ;
F_64 ( & V_260 -> V_270 ) ;
}
V_117 = F_125 ( & V_173 , & V_260 -> V_270 , 0 ) ;
if ( V_117 < 0 )
return V_117 ;
V_26 = F_61 ( sizeof( * V_26 ) , V_64 ) ;
if ( ! V_26 )
return - V_69 ;
V_117 = F_198 ( V_26 , V_340 ) ;
if ( V_117 ) {
V_117 = - V_69 ;
goto V_138;
}
switch ( V_335 ) {
case V_341 :
if ( ! F_199 ( V_342 ) ) {
V_117 = - V_343 ;
goto V_138;
}
V_117 = F_168 ( V_26 , V_73 , 1 , V_260 , V_125 -> V_327 ,
V_125 -> V_328 , & V_323 ) ;
goto V_138;
case V_344 :
if ( ! F_199 ( V_342 ) ) {
V_117 = - V_343 ;
goto V_138;
}
V_117 = F_173 ( & V_11 , V_73 , V_260 ) ;
if ( V_117 == 0 ) {
V_117 = F_172 ( V_26 , V_76 -> V_96 , V_260 , V_11 -> V_88 ,
& V_323 , NULL ) ;
if ( V_117 == 0 )
V_11 -> V_166 = 1 ;
F_174 ( V_11 ) ;
}
goto V_138;
case V_345 :
V_117 = F_173 ( & V_11 , V_73 , V_260 ) ;
if ( V_117 == 0 ) {
struct V_346 V_179 = { } ;
V_179 . V_347 = V_11 -> V_88 ;
V_179 . V_348 = V_260 ;
V_117 = F_200 ( V_26 , V_76 -> V_96 , & V_179 ) ;
F_174 ( V_11 ) ;
}
goto V_138;
case V_349 :
if ( ! F_199 ( V_342 ) ) {
V_117 = - V_343 ;
goto V_138;
}
V_117 = F_173 ( & V_11 , V_73 , V_260 ) ;
if ( V_117 == 0 ) {
struct V_346 V_179 = { } ;
V_179 . V_348 = V_260 ;
V_179 . V_347 = V_11 -> V_88 ;
V_117 = F_201 ( V_26 , V_76 -> V_96 , & V_179 , NULL ) ;
F_174 ( V_11 ) ;
}
goto V_138;
case V_350 :
if ( ! F_199 ( V_342 ) ) {
V_117 = - V_343 ;
goto V_138;
}
V_223 = V_287 ;
case V_351 :
V_117 = F_193 ( V_26 , V_223 , exp , V_125 , & V_323 ) ;
goto V_138;
case V_352 :
V_117 = F_173 ( & V_11 , V_73 , V_260 ) ;
if ( V_117 == 0 ) {
V_117 = F_162 ( V_11 -> V_88 , V_125 -> V_327 ,
V_125 -> V_328 ) ;
F_174 ( V_11 ) ;
}
goto V_138;
case V_353 :
if ( ! F_199 ( V_342 ) ) {
V_117 = - V_343 ;
goto V_138;
}
if ( V_125 -> V_327 == NULL ) {
V_117 = F_173 ( & V_11 , V_73 , V_260 ) ;
if ( V_117 == 0 ) {
V_11 -> V_166 = 1 ;
F_174 ( V_11 ) ;
}
} else {
V_117 = F_168 ( V_26 , V_73 , 0 , V_260 ,
V_125 -> V_327 ,
V_125 -> V_328 , & V_323 ) ;
}
goto V_138;
case V_354 :
if ( ! F_199 ( V_342 ) ) {
V_117 = - V_343 ;
goto V_138;
}
V_117 = F_195 ( exp , V_260 ,
V_125 -> V_355 ,
V_125 -> V_331 ,
V_125 -> V_329 ) ;
goto V_138;
case V_356 :
V_117 = F_196 ( exp , V_260 ) ;
goto V_138;
default:
F_79 ( L_26 , V_335 ) ;
V_117 = - V_357 ;
goto V_138;
}
V_138:
F_202 ( V_26 ) ;
F_62 ( V_26 ) ;
for ( V_339 = V_323 . V_358 , V_231 = 0 ; V_231 < 4 ;
V_231 ++ , V_339 ++ ) {
if ( ! V_339 -> V_192 )
break;
F_203 ( & V_339 -> V_62 , V_339 -> V_192 ) ;
}
return V_117 ;
}
static int F_94 ( const struct V_25 * V_26 ,
struct V_6 * V_359 , struct V_131 * V_360 )
{
struct V_75 * V_76 = & V_359 -> V_148 . V_149 ;
struct V_6 * V_135 ;
struct V_361 V_362 = { L_27 } ;
struct V_363 * V_364 = NULL ;
int V_117 ;
if ( V_360 -> V_365 < 2 || F_204 ( V_360 , 1 ) < 1 ) {
F_79 ( L_28 ) ;
return - V_251 ;
}
V_135 = F_92 ( F_93 ( V_360 , 1 ) ) ;
if ( ! V_135 || ! V_135 -> V_366 || ! V_135 -> V_367 ) {
F_79 ( L_29 ,
F_93 ( V_360 , 1 ) ) ;
return - V_251 ;
}
F_205 ( & V_76 -> V_90 ) ;
F_47 ( & V_76 -> V_92 ) ;
F_47 ( & V_76 -> V_168 ) ;
V_76 -> V_209 = 0 ;
V_76 -> V_254 = 0 ;
V_364 = F_61 ( sizeof( * V_364 ) , V_64 ) ;
if ( ! V_364 ) {
F_79 ( L_30 ,
F_93 ( V_360 , 1 ) ) ;
return - V_69 ;
}
V_364 -> V_368 = V_369 | V_370 |
V_371 |
V_372 | V_373 |
V_374 | V_375 |
V_376 ;
V_364 -> V_377 = V_378 ;
V_364 -> V_379 = V_380 ;
V_364 -> V_381 = V_176 ;
V_117 = F_206 ( V_26 , & V_76 -> V_96 , V_135 , & V_362 , V_364 , NULL ) ;
F_62 ( V_364 ) ;
if ( V_117 != 0 ) {
F_79 ( L_31 ,
F_93 ( V_360 , 1 ) ) ;
return V_117 ;
}
return V_117 ;
}
static int F_96 ( struct V_6 * V_359 )
{
struct V_75 * V_76 = & V_359 -> V_148 . V_149 ;
int V_117 ;
if ( ! F_33 ( & V_359 -> V_382 ) ) {
F_79 ( L_32 ) ;
return - V_45 ;
}
F_14 ( F_68 ( & V_76 -> V_96 -> V_383 ) > 0 ) ;
V_117 = F_207 ( V_76 -> V_96 ) ;
if ( V_117 != 0 )
F_79 ( L_33 , V_117 ) ;
return V_117 ;
}
static int F_208 ( const struct V_25 * V_26 ,
struct V_307 * * exp ,
struct V_6 * V_384 , struct V_361 * V_385 ,
struct V_363 * V_125 , void * V_386 )
{
int V_117 ;
struct V_228 V_387 = { 0 } ;
V_117 = F_209 ( & V_387 , V_384 , V_385 ) ;
if ( V_117 == 0 ) {
* exp = F_210 ( & V_387 ) ;
}
return V_117 ;
}
static int F_211 ( struct V_307 * exp )
{
int V_117 ;
if ( exp == NULL ) {
V_117 = - V_251 ;
goto V_138;
}
V_117 = F_212 ( exp ) ;
goto V_138;
V_138:
return V_117 ;
}
static int F_213 ( void )
{
int V_117 ;
V_117 = F_214 ( V_388 ) ;
if ( V_117 == 0 ) {
V_117 = F_215 ( & V_389 , NULL ,
V_54 ,
& V_207 ) ;
if ( V_117 )
F_216 ( V_388 ) ;
}
return V_117 ;
}
static void F_217 ( void )
{
F_218 ( V_54 ) ;
F_216 ( V_388 ) ;
}
static int T_8 F_219 ( void )
{
F_220 ( L_34 ) ;
F_14 ( V_234 % V_286 == 0 ) ;
return F_213 () ;
}
static void F_221 ( void )
{
F_217 () ;
}
