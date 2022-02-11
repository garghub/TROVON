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
F_14 ( V_35 -> V_44 -> V_48 ) ;
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
V_63 = F_45 ( V_56 , V_64 ) ;
if ( V_63 ) {
F_46 ( V_62 , & V_63 -> V_20 , V_59 , & V_65 ) ;
V_63 -> V_66 = F_7 ( V_59 ) ;
F_47 ( & V_63 -> V_55 ) ;
F_48 ( & V_63 -> V_67 , 0 ) ;
}
return ! V_63 ? - V_68 : 0 ;
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
if ( ! V_80 )
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
if ( V_72 -> V_79 )
return F_59 ( V_72 -> V_76 -> V_95 , V_93 ) ;
V_94 = F_60 ( 1 ) ;
F_14 ( ! * V_93 ) ;
* V_93 = F_61 ( V_94 , V_64 ) ;
if ( ! * V_93 )
return - V_68 ;
( * V_93 ) -> V_96 [ 0 ] = F_61 ( sizeof( struct V_97 ) , V_64 ) ;
if ( ! ( * V_93 ) -> V_96 [ 0 ] ) {
F_62 ( * V_93 ) ;
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
if ( V_72 -> V_79 )
return F_66 ( V_72 -> V_76 -> V_95 , V_93 ) ;
V_94 = F_60 ( 1 ) ;
F_62 ( ( * V_93 ) -> V_96 [ 0 ] ) ;
F_62 ( * V_93 ) ;
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
F_34 ( V_101 , V_11 ) ;
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
F_14 ( ! V_104 ) ;
V_11 = F_45 ( V_101 , V_64 ) ;
if ( V_11 ) {
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
V_27 = F_45 ( V_123 , V_64 ) ;
if ( ! V_27 )
V_27 = F_84 ( - V_68 ) ;
return V_27 ;
}
static void F_85 ( const struct V_119 * V_120 ,
struct V_121 * V_122 , void * V_124 )
{
struct V_24 * V_27 = V_124 ;
F_34 ( V_123 , V_27 ) ;
}
static void F_86 ( const struct V_119 * V_120 ,
struct V_121 * V_122 , void * V_124 )
{
}
static void * F_87 ( const struct V_119 * V_120 ,
struct V_121 * V_122 )
{
struct V_125 * V_126 ;
V_126 = F_45 ( V_127 , V_64 ) ;
if ( ! V_126 )
V_126 = F_84 ( - V_68 ) ;
return V_126 ;
}
static void F_88 ( const struct V_119 * V_120 ,
struct V_121 * V_122 , void * V_124 )
{
struct V_125 * V_126 = V_124 ;
F_34 ( V_127 , V_126 ) ;
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
V_72 = F_61 ( sizeof( * V_72 ) , V_64 ) ;
if ( ! V_72 ) {
V_116 = - V_68 ;
goto V_137;
}
V_136 = 1 ;
V_133 = & V_72 -> V_4 ;
V_116 = F_91 ( V_133 , V_129 ) ;
if ( V_116 )
goto V_137;
V_133 -> V_138 . V_83 = & V_139 ;
V_133 -> V_140 = & V_141 ;
V_136 = 2 ;
V_7 = F_92 ( F_93 ( V_131 , 0 ) ) ;
F_14 ( V_7 ) ;
F_14 ( V_26 ) ;
V_134 = F_92 ( F_93 ( V_131 , 1 ) ) ;
if ( ! V_134 ) {
F_79 ( L_4 ,
F_93 ( V_131 , 1 ) ) ;
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
V_116 = F_94 ( V_26 , V_7 , V_131 ) ;
if ( V_116 )
goto V_137;
V_72 -> V_76 = & V_7 -> V_147 . V_148 ;
V_136 = 4 ;
if ( V_132 && ! F_95 ( V_132 ) )
V_132 = NULL ;
V_135 = V_134 -> V_143 -> V_144 ;
if ( V_132 ) {
if ( V_132 -> V_149 ) {
V_116 = - V_45 ;
goto V_137;
}
V_132 -> V_149 = & V_72 -> V_118 -> V_117 ;
V_116 = V_132 -> V_150 -> V_151 -> V_152 ( V_26 , V_132 ,
V_132 -> V_150 -> V_153 ,
NULL ) ;
if ( V_116 )
goto V_137;
} else {
F_14 ( strcmp ( V_135 , V_154 ) == 0 ) ;
}
V_72 -> V_79 = V_132 ;
return & V_133 -> V_138 ;
V_137:
switch ( V_136 ) {
case 4 : {
int V_155 ;
V_155 = F_96 ( V_7 ) ;
if ( V_155 )
F_79 ( L_6 ,
V_7 -> V_156 , V_155 ) ;
}
case 3 :
F_81 ( V_26 , V_72 ) ;
case 2 :
F_97 ( & V_72 -> V_4 ) ;
case 1 :
F_62 ( V_72 ) ;
case 0 :
default:
break;
}
return F_84 ( V_116 ) ;
}
static int F_98 ( const struct V_25 * V_26 , struct V_81 * V_5 ,
const char * V_157 , struct V_81 * V_132 )
{
F_99 () ;
return 0 ;
}
static struct V_81 * F_100 ( const struct V_25 * V_26 ,
struct V_81 * V_5 )
{
struct V_1 * V_72 = F_1 ( F_5 ( V_5 ) ) ;
struct V_81 * V_132 = V_72 -> V_79 ;
while ( V_132 )
V_132 = V_132 -> V_150 -> V_151 -> V_158 ( V_26 , V_132 ) ;
return NULL ;
}
static void F_101 ( const struct V_25 * V_26 ,
struct V_18 * V_22 ,
int V_159 )
{
struct V_21 * V_160 = F_11 ( V_22 ) ;
F_102 ( V_160 ) ;
F_103 ( V_26 , V_160 ) ;
F_104 ( V_26 , V_160 , L_7 , V_22 -> V_66 ) ;
if ( ! V_159 ) {
F_105 ( V_26 , V_160 ) ;
F_106 ( V_26 , V_160 ) ;
F_107 ( V_26 , V_160 ) ;
F_108 ( V_26 , V_160 ) ;
}
F_109 ( V_26 , V_160 ) ;
}
static struct V_81 * F_110 ( const struct V_25 * V_26 ,
struct V_81 * V_5 )
{
struct V_1 * V_72 = F_1 ( F_5 ( V_5 ) ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_10 * V_11 ;
struct V_81 * V_132 = V_72 -> V_79 ;
F_111 ( V_161 , L_8 ,
V_72 , V_132 ) ;
F_112 ( V_26 , & V_72 -> V_118 -> V_117 , - 1 ) ;
F_55 ( & V_75 -> V_89 ) ;
F_113 (eco, &ec->ec_objects, eo_obj_chain)
V_11 -> V_162 = 1 ;
F_57 ( & V_75 -> V_89 ) ;
F_112 ( V_26 , & V_72 -> V_118 -> V_117 , - 1 ) ;
F_111 ( V_161 ,
L_9 ) ;
F_55 ( & V_75 -> V_89 ) ;
while ( ! F_33 ( & V_75 -> V_91 ) ) {
F_57 ( & V_75 -> V_89 ) ;
F_79 ( L_10 ) ;
F_114 ( V_163 ) ;
F_115 ( F_116 ( 1 ) ) ;
F_112 ( V_26 , & V_72 -> V_118 -> V_117 , - 1 ) ;
F_55 ( & V_75 -> V_89 ) ;
}
F_57 ( & V_75 -> V_89 ) ;
F_14 ( F_33 ( & V_75 -> V_164 ) ) ;
F_111 ( V_161 , L_11 ) ;
F_96 ( V_5 -> V_165 ) ;
while ( V_132 )
V_132 = V_132 -> V_150 -> V_151 -> V_166 ( V_26 , V_132 ) ;
F_14 ( V_72 -> V_118 == F_117 ( V_5 -> V_149 ) ) ;
F_81 ( V_26 , V_72 ) ;
F_97 ( & V_72 -> V_4 ) ;
F_62 ( V_72 ) ;
return NULL ;
}
static struct V_10 * F_118 ( struct V_1 * V_5 ,
struct V_92 * * V_93 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_30 * V_69 ;
struct V_92 * V_167 ;
struct V_10 * V_11 ;
struct V_9 * V_59 ;
struct V_168 * V_169 ;
int V_170 ;
int V_116 ;
F_14 ( V_93 ) ;
V_167 = * V_93 ;
F_14 ( V_167 ) ;
F_119 ( F_120 ( & V_167 -> V_100 ) != 0 , V_171 L_12 , F_121 ( & V_167 -> V_100 ) ) ;
F_119 ( F_122 ( & V_167 -> V_100 ) == V_172 , V_171 L_12 ,
F_121 ( & V_167 -> V_100 ) ) ;
if ( F_3 ( V_5 ) -> V_138 . V_165 -> V_173 )
return F_84 ( - V_142 ) ;
V_26 = F_123 ( & V_170 ) ;
if ( F_124 ( V_26 ) )
return ( void * ) V_26 ;
V_27 = F_12 ( V_26 ) ;
V_69 = & V_27 -> V_174 ;
if ( V_5 -> V_79 ) {
struct V_97 * V_175 = V_167 -> V_96 [ 0 ] ;
F_14 ( V_175 ) ;
V_175 -> V_176 = V_167 -> V_100 ;
V_69 -> V_33 . V_147 . V_177 = V_175 ;
}
V_69 -> V_86 = V_93 ;
V_169 = & V_27 -> V_178 ;
V_116 = F_125 ( V_169 , & V_167 -> V_100 , 0 ) ;
if ( V_116 != 0 ) {
V_11 = F_84 ( V_116 ) ;
goto V_137;
}
V_59 = F_126 ( V_26 , F_3 ( V_5 ) , V_169 , & V_69 -> V_33 ) ;
if ( F_124 ( V_59 ) ) {
V_11 = ( void * ) V_59 ;
goto V_137;
}
V_11 = F_7 ( V_59 ) ;
if ( V_11 -> V_162 ) {
F_127 ( V_26 , V_59 ) ;
V_11 = F_84 ( - V_42 ) ;
}
V_137:
F_128 ( V_26 , & V_170 ) ;
return V_11 ;
}
static int F_129 ( struct V_10 * V_11 )
{
struct V_25 * V_26 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
int V_170 ;
V_26 = F_123 ( & V_170 ) ;
if ( F_124 ( V_26 ) )
return F_130 ( V_26 ) ;
if ( V_11 -> V_162 ) {
struct V_103 * V_179 = V_59 -> V_107 . V_85 ;
F_14 ( & V_11 -> V_106 == F_131 ( V_179 ) ) ;
F_132 ( V_180 , & V_179 -> V_181 ) ;
}
F_127 ( V_26 , V_59 ) ;
F_128 ( V_26 , & V_170 ) ;
return 0 ;
}
static int F_133 ( struct V_25 * V_26 , struct V_10 * V_11 ,
T_2 V_182 , T_2 V_183 , int V_184 ,
T_3 * V_52 , T_4 V_185 )
{
struct V_37 * V_38 ;
struct V_21 * V_186 ;
struct V_9 * V_59 ;
struct V_57 * V_187 ;
struct V_24 * V_27 ;
int V_116 = - V_68 ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_188 ;
V_187 = & V_27 -> V_189 ;
V_59 = F_6 ( V_11 ) ;
V_187 -> V_190 = V_59 ;
V_187 -> V_191 = F_134 ( V_59 , V_182 ) ;
V_187 -> V_192 = F_134 ( V_59 , V_183 ) ;
V_187 -> V_193 = V_184 == V_194 ? V_195 : V_196 ;
V_187 -> V_197 = V_185 ;
V_38 -> V_198 = V_59 ;
V_186 = F_135 ( V_26 , V_38 , V_187 , L_7 , V_11 ) ;
if ( V_186 ) {
struct V_74 * V_75 = V_11 -> V_88 -> V_76 ;
struct V_18 * V_63 ;
V_116 = F_136 ( V_26 , V_186 ) ;
if ( V_116 == 0 ) {
V_63 = F_10 ( F_137 ( V_186 , & V_199 ) ) ;
F_55 ( & V_75 -> V_89 ) ;
if ( F_33 ( & V_63 -> V_55 ) ) {
F_138 ( & V_63 -> V_55 , & V_75 -> V_164 ) ;
V_63 -> V_200 = ++ V_75 -> V_201 ;
}
F_42 ( & V_63 -> V_67 ) ;
* V_52 = V_63 -> V_200 ;
F_57 ( & V_75 -> V_89 ) ;
} else {
F_104 ( V_26 , V_186 , L_7 , V_202 ) ;
}
}
return V_116 ;
}
static int F_139 ( struct V_25 * V_26 , struct V_1 * V_72 ,
T_3 V_52 )
{
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_18 * V_22 = NULL ;
struct V_203 * V_63 ;
int V_204 = 0 , V_159 = 0 ;
F_55 ( & V_75 -> V_89 ) ;
F_140 (el, &ec->ec_locks) {
V_22 = F_141 ( V_63 , struct V_18 , V_55 ) ;
F_111 ( V_161 , L_13 , V_22 , V_22 -> V_200 ) ;
V_204 = ( V_22 -> V_200 == V_52 ) ;
if ( V_204 ) {
if ( F_142 ( & V_22 -> V_67 ) )
F_69 ( & V_22 -> V_55 ) ;
else
V_159 = 1 ;
break;
}
}
F_57 ( & V_75 -> V_89 ) ;
if ( ! V_204 )
return - V_205 ;
F_101 ( V_26 , V_22 , V_159 ) ;
return 0 ;
}
static int F_143 ( const struct V_25 * V_26 , struct V_37 * V_38 ,
enum V_206 V_43 , struct V_207 * V_208 )
{
struct V_60 * V_209 ;
struct V_60 * V_210 ;
int V_211 = 0 ;
F_144 (clp, temp, &queue->c2_qin) {
int V_116 ;
V_116 = F_145 ( V_26 , V_38 , V_209 , V_212 ) ;
if ( V_116 == 0 )
continue;
V_211 = V_211 ? : V_116 ;
}
return V_211 ;
}
static int F_146 ( struct V_10 * V_11 , int V_213 , T_2 V_214 ,
struct V_34 * * V_215 , int V_216 , int V_217 )
{
struct V_25 * V_26 ;
struct V_24 * V_27 ;
struct V_9 * V_59 = F_6 ( V_11 ) ;
struct V_1 * V_72 = V_11 -> V_88 ;
struct V_207 * V_208 ;
struct V_37 * V_38 ;
struct V_60 * V_209 ;
struct V_218 V_219 = { 0 } ;
int V_220 = F_147 ( V_59 ) ;
int V_170 ;
int V_116 ;
int V_221 ;
F_14 ( ( V_214 & ~ V_222 ) == 0 ) ;
F_14 ( V_72 -> V_79 ) ;
V_26 = F_123 ( & V_170 ) ;
if ( F_124 ( V_26 ) )
return F_130 ( V_26 ) ;
V_27 = F_12 ( V_26 ) ;
V_38 = & V_27 -> V_188 ;
V_208 = & V_27 -> V_223 ;
F_148 ( V_208 ) ;
V_38 -> V_224 = 1 ;
V_116 = F_149 ( V_26 , V_38 , V_225 , V_59 ) ;
if ( V_116 < 0 )
goto V_137;
F_14 ( V_116 == 0 ) ;
V_116 = F_133 ( V_26 , V_11 , V_214 ,
V_214 + V_216 * V_226 - 1 ,
V_213 == V_227 ? V_228 : V_194 , & V_219 . V_52 ,
V_229 ) ;
if ( V_116 < 0 )
goto V_230;
for ( V_221 = 0 ; V_221 < V_216 ; V_221 ++ ) {
F_14 ( V_215 [ V_221 ] ) ;
V_209 = F_150 ( V_26 , V_59 , F_134 ( V_59 , V_214 ) ,
V_215 [ V_221 ] , V_231 ) ;
if ( F_124 ( V_209 ) ) {
V_116 = F_130 ( V_209 ) ;
break;
}
F_14 ( V_209 -> V_232 == V_231 ) ;
V_116 = F_151 ( V_26 , V_38 , V_209 ) ;
if ( V_116 ) {
F_14 ( V_209 -> V_233 == V_234 ) ;
F_152 ( V_26 , V_209 ) ;
break;
}
F_153 ( & V_208 -> V_235 , V_209 ) ;
F_152 ( V_26 , V_209 ) ;
F_154 ( V_26 , V_209 , 0 , V_220 ) ;
V_214 += V_220 ;
}
if ( V_116 == 0 ) {
enum V_206 V_236 = V_213 == V_227 ? V_237 : V_212 ;
V_217 = V_217 && ( V_236 == V_212 ) ;
if ( V_217 )
V_116 = F_143 ( V_26 , V_38 , V_236 , V_208 ) ;
else
V_116 = F_155 ( V_26 , V_38 , V_236 , V_208 , 0 ) ;
F_111 ( V_161 , L_14 ,
V_217 ? L_15 : L_16 , V_116 ) ;
}
F_139 ( V_26 , V_72 , V_219 . V_52 ) ;
V_230:
F_156 ( V_26 , V_38 , V_208 ) ;
F_157 ( V_26 , V_38 , V_208 ) ;
F_158 ( V_26 , V_208 ) ;
F_159 ( V_26 , V_38 ) ;
V_137:
F_128 ( V_26 , & V_170 ) ;
return V_116 ;
}
static int F_160 ( const struct V_25 * V_26 , struct V_1 * V_72 ,
struct V_238 * V_239 , struct V_240 * V_241 )
{
struct V_10 * V_11 ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_92 * V_167 = NULL ;
int V_116 ;
int V_242 = 0 ;
if ( ! ( V_239 -> V_243 & V_244 ) ||
! ( V_239 -> V_243 & V_245 ) ||
! F_161 ( F_122 ( & V_239 -> V_246 ) ) ) {
F_79 ( L_17 V_171 L_12 , F_121 ( & V_239 -> V_246 ) ) ;
return - V_247 ;
}
V_116 = F_58 ( V_72 , & V_167 ) ;
if ( V_116 < 0 ) {
F_79 ( L_18 , V_116 ) ;
goto V_248;
}
V_167 -> V_100 = V_239 -> V_246 ;
if ( F_120 ( & V_167 -> V_100 ) == 0 )
F_162 ( & V_167 -> V_100 , ++ V_249 ) ;
V_116 = F_163 ( V_26 , V_75 -> V_95 , V_239 , & V_167 , V_241 ) ;
if ( V_116 != 0 ) {
F_79 ( L_19 , V_116 ) ;
goto V_248;
}
V_242 = 1 ;
V_239 -> V_246 = V_167 -> V_100 ;
V_239 -> V_243 |= V_244 ;
V_11 = F_118 ( V_72 , & V_167 ) ;
if ( F_124 ( V_11 ) ) {
V_116 = F_130 ( V_11 ) ;
goto V_248;
}
F_129 ( V_11 ) ;
F_111 ( V_161 , L_20 V_171 L_12 , F_121 ( & V_239 -> V_246 ) ) ;
V_248:
if ( V_242 && V_116 )
F_164 ( V_26 , V_75 -> V_95 , V_239 , V_167 , V_241 , NULL ) ;
if ( V_167 )
F_65 ( V_72 , & V_167 ) ;
if ( V_116 )
F_79 ( L_21 , V_116 ) ;
return V_116 ;
}
static int F_165 ( struct V_10 * * V_250 , struct V_1 * V_72 ,
struct V_238 * V_239 )
{
struct V_92 * V_167 = NULL ;
struct V_10 * V_11 ;
int V_116 ;
if ( ( V_239 -> V_243 & V_244 ) == 0 || F_120 ( & V_239 -> V_246 ) == 0 ) {
F_79 ( L_22 ) ;
return - V_247 ;
}
V_116 = F_58 ( V_72 , & V_167 ) ;
if ( V_116 < 0 )
return V_116 ;
V_167 -> V_100 = V_239 -> V_246 ;
if ( ! ( V_239 -> V_243 & V_245 ) )
F_64 ( & V_167 -> V_100 ) ;
V_116 = 0 ;
V_11 = F_118 ( V_72 , & V_167 ) ;
if ( ! F_124 ( V_11 ) )
* V_250 = V_11 ;
else
V_116 = F_130 ( V_11 ) ;
if ( V_167 )
F_65 ( V_72 , & V_167 ) ;
return V_116 ;
}
static void F_166 ( struct V_10 * V_11 )
{
int V_116 ;
V_116 = F_129 ( V_11 ) ;
if ( V_116 )
F_79 ( L_23 ,
V_11 -> V_88 -> V_76 -> V_95 -> V_251 -> V_156 , V_116 ) ;
}
static void
F_167 ( struct V_34 * V_34 , int V_213 , T_2 V_252 ,
T_2 V_214 , T_2 V_253 )
{
char * V_254 ;
T_2 V_255 ;
T_2 V_256 ;
int V_257 ;
F_14 ( V_253 == V_226 ) ;
V_254 = F_168 ( V_34 ) ;
for ( V_257 = 0 ; V_257 < V_226 ; V_257 += V_258 ) {
if ( V_213 == V_259 ) {
V_255 = V_214 + V_257 ;
V_256 = V_252 ;
} else {
V_255 = 0xdeadbeef00c0ffeeULL ;
V_256 = 0xdeadbeef00c0ffeeULL ;
}
F_169 ( V_254 + V_257 , V_258 ,
V_255 , V_256 ) ;
}
F_170 ( V_34 ) ;
}
static int F_171 ( struct V_34 * V_34 , T_2 V_252 ,
T_2 V_214 , T_2 V_253 )
{
T_2 V_255 ;
T_2 V_256 ;
char * V_254 ;
int V_257 ;
int V_116 ;
int V_155 ;
F_14 ( V_253 == V_226 ) ;
V_254 = F_168 ( V_34 ) ;
for ( V_116 = V_257 = 0 ; V_257 < V_226 ; V_257 += V_258 ) {
V_255 = V_214 + V_257 ;
V_256 = V_252 ;
V_155 = F_172 ( L_24 ,
V_254 + V_257 , V_258 ,
V_255 , V_256 ) ;
if ( V_155 != 0 ) {
F_79 ( L_25 , V_252 ) ;
V_116 = V_155 ;
}
}
F_170 ( V_34 ) ;
return V_116 ;
}
static int F_173 ( struct V_1 * V_72 , int V_213 , struct V_238 * V_239 ,
struct V_10 * V_11 , T_2 V_214 ,
T_2 V_253 , int V_217 ,
struct V_240 * V_241 )
{
T_5 V_216 ;
struct V_260 * V_261 ;
struct V_260 * V_262 ;
struct V_34 * * V_215 ;
T_2 V_263 ;
int V_221 ;
int V_116 ;
int V_264 ;
T_6 V_265 ;
int V_266 = 0 ;
V_264 = ( F_120 ( & V_239 -> V_246 ) != V_267 &&
( V_239 -> V_243 & V_268 ) != 0 &&
( V_239 -> V_269 & V_270 ) != 0 ) ;
V_265 = ( ( F_120 ( & V_239 -> V_246 ) & 2 ) == 0 ) ? V_271 : V_272 ;
F_14 ( V_213 == V_259 || V_213 == V_273 ) ;
if ( V_253 <= 0 ||
( V_253 & ( ~ V_222 ) ) != 0 )
return - V_247 ;
V_216 = V_253 >> V_274 ;
if ( V_213 == V_259 )
V_266 = V_275 ;
V_261 = F_174 ( V_216 , sizeof( * V_261 ) , V_64 ) ;
if ( ! V_261 )
return - V_68 ;
V_215 = F_174 ( V_216 , sizeof( * V_215 ) , V_64 ) ;
if ( ! V_215 ) {
F_62 ( V_261 ) ;
return - V_68 ;
}
for ( V_221 = 0 , V_262 = V_261 , V_263 = V_214 ;
V_221 < V_216 ;
V_221 ++ , V_262 ++ , V_263 += V_226 ) {
F_14 ( ! V_262 -> V_276 ) ;
V_116 = - V_68 ;
V_262 -> V_276 = F_175 ( V_265 ) ;
if ( ! V_262 -> V_276 )
goto V_137;
V_215 [ V_221 ] = V_262 -> V_276 ;
V_262 -> V_253 = V_226 ;
V_262 -> V_263 = V_263 ;
V_262 -> V_277 = V_266 ;
if ( V_264 )
F_167 ( V_262 -> V_276 , V_213 ,
F_120 ( & V_239 -> V_246 ) , V_263 ,
V_262 -> V_253 ) ;
}
F_14 ( V_72 -> V_79 ) ;
V_116 = F_146 ( V_11 , V_213 , V_214 , V_215 , V_216 , V_217 ) ;
V_137:
if ( V_116 != 0 || V_213 != V_273 )
V_264 = 0 ;
for ( V_221 = 0 , V_262 = V_261 ; V_221 < V_216 ; V_221 ++ , V_262 ++ ) {
if ( ! V_262 -> V_276 )
continue;
if ( V_264 ) {
int V_278 ;
V_278 = F_171 ( V_262 -> V_276 ,
F_120 ( & V_239 -> V_246 ) ,
V_262 -> V_263 , V_262 -> V_253 ) ;
if ( V_278 != 0 && V_116 == 0 )
V_116 = V_278 ;
}
F_176 ( V_262 -> V_276 ) ;
}
F_62 ( V_261 ) ;
F_62 ( V_215 ) ;
return V_116 ;
}
static int F_177 ( const struct V_25 * V_26 ,
struct V_279 * exp , int V_213 ,
struct V_238 * V_239 , struct V_10 * V_11 ,
T_2 V_214 , T_2 V_253 ,
T_2 V_280 , struct V_240 * V_241 ,
int V_217 )
{
struct V_281 V_282 ;
struct V_283 * V_284 ;
struct V_285 * V_286 ;
T_2 V_263 ;
T_2 V_216 , V_287 ;
int V_221 , V_288 = 0 , V_266 = 0 ;
if ( V_253 <= 0 || ( V_253 & ( ~ V_222 ) ) != 0 )
return - V_247 ;
V_216 = V_280 >> V_274 ;
V_287 = V_253 >> V_274 ;
V_284 = F_174 ( V_216 , sizeof( struct V_283 ) , V_64 ) ;
V_286 = F_174 ( V_216 , sizeof( struct V_285 ) , V_64 ) ;
if ( ! V_284 || ! V_286 ) {
V_288 = - V_68 ;
goto V_137;
}
if ( V_213 == V_259 && V_217 )
V_266 |= V_275 ;
F_178 ( V_239 , & V_282 ) ;
V_263 = V_214 ;
for (; V_287 ; V_287 -= V_216 ) {
int V_289 ;
if ( V_287 < V_216 )
V_216 = V_287 ;
for ( V_221 = 0 ; V_221 < V_216 ; V_221 ++ , V_263 += V_226 ) {
V_286 [ V_221 ] . V_214 = V_263 ;
V_286 [ V_221 ] . V_290 = V_226 ;
V_286 [ V_221 ] . V_291 = V_266 ;
}
V_282 . V_292 = V_216 ;
V_241 -> V_293 = 0 ;
V_289 = V_216 ;
V_288 = F_179 ( V_26 , V_213 , exp , V_239 , 1 , & V_282 , V_286 , & V_289 ,
V_284 , V_241 ) ;
if ( V_288 != 0 )
goto V_137;
F_14 ( V_289 == V_216 ) ;
for ( V_221 = 0 ; V_221 < V_289 ; V_221 ++ ) {
struct V_34 * V_34 = V_284 [ V_221 ] . V_34 ;
if ( ! V_34 && V_284 [ V_221 ] . V_116 == 0 )
continue;
if ( V_217 )
V_284 [ V_221 ] . V_291 |= V_275 ;
if ( F_120 ( & V_239 -> V_246 ) == V_267 ||
( V_239 -> V_243 & V_268 ) == 0 ||
( V_239 -> V_269 & V_270 ) == 0 )
continue;
if ( V_213 == V_259 )
F_167 ( V_34 , V_213 ,
F_120 ( & V_239 -> V_246 ) ,
V_286 [ V_221 ] . V_214 ,
V_286 [ V_221 ] . V_290 ) ;
else
F_171 ( V_34 ,
F_120 ( & V_239 -> V_246 ) ,
V_286 [ V_221 ] . V_214 ,
V_286 [ V_221 ] . V_290 ) ;
}
V_288 = F_180 ( V_26 , V_213 , exp , V_239 , 1 , & V_282 ,
V_286 , V_216 , V_284 , V_241 , V_288 ) ;
if ( V_288 != 0 )
goto V_137;
memset ( V_241 , 0 , sizeof( * V_241 ) ) ;
F_181 ( (struct V_119 * ) & V_26 -> V_28 ) ;
F_182 ( (struct V_119 * ) & V_26 -> V_28 ) ;
}
V_137:
F_62 ( V_284 ) ;
F_62 ( V_286 ) ;
return V_288 ;
}
static int F_183 ( const struct V_25 * V_26 , int V_213 ,
struct V_279 * exp ,
struct V_294 * V_124 ,
struct V_240 * V_295 )
{
struct V_6 * V_7 = F_184 ( exp ) ;
struct V_1 * V_72 = F_4 ( V_7 ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_238 * V_239 = & V_124 -> V_296 ;
struct V_10 * V_11 ;
int V_116 ;
int V_217 = 1 ;
long V_297 ;
F_14 ( V_239 -> V_243 & V_245 ) ;
V_116 = F_165 ( & V_11 , V_72 , V_239 ) ;
if ( V_116 )
return V_116 ;
V_239 -> V_243 &= ~ V_298 ;
V_297 = ( long ) V_124 -> V_299 ;
if ( V_297 == 1 )
V_217 = 0 ;
if ( ! V_72 -> V_79 && V_297 != 3 ) {
V_297 = 3 ;
V_124 -> V_300 = V_124 -> V_301 ;
}
if ( V_124 -> V_300 > V_302 )
V_124 -> V_300 = V_302 ;
switch ( V_297 ) {
case 1 :
case 2 :
V_116 = F_173 ( V_72 , V_213 , V_239 ,
V_11 , V_124 -> V_303 ,
V_124 -> V_301 , V_217 , V_295 ) ;
break;
case 3 :
V_116 = F_177 ( V_26 , V_75 -> V_95 , V_213 , V_239 ,
V_11 , V_124 -> V_303 ,
V_124 -> V_301 , V_124 -> V_300 ,
V_295 , V_217 ) ;
break;
default:
V_116 = - V_247 ;
}
F_166 ( V_11 ) ;
return V_116 ;
}
static int
F_185 ( unsigned int V_304 , struct V_279 * exp , int V_290 ,
void * V_305 , void T_7 * V_306 )
{
struct V_6 * V_7 = exp -> V_251 ;
struct V_1 * V_72 = F_4 ( V_7 ) ;
struct V_74 * V_75 = V_72 -> V_76 ;
struct V_10 * V_11 ;
struct V_294 * V_124 = V_305 ;
struct V_240 V_295 ;
struct V_25 * V_26 ;
struct V_307 * V_308 ;
struct V_238 * V_239 ;
struct V_168 V_169 ;
int V_213 = V_273 ;
int V_116 = 0 ;
int V_221 ;
memset ( & V_295 , 0 , sizeof( V_295 ) ) ;
V_239 = & V_124 -> V_296 ;
if ( ! ( V_239 -> V_243 & V_245 ) ) {
V_239 -> V_243 |= V_245 ;
F_64 ( & V_239 -> V_246 ) ;
}
V_116 = F_125 ( & V_169 , & V_239 -> V_246 , 0 ) ;
if ( V_116 < 0 )
return V_116 ;
V_26 = F_61 ( sizeof( * V_26 ) , V_64 ) ;
if ( ! V_26 )
return - V_68 ;
V_116 = F_186 ( V_26 , V_309 ) ;
if ( V_116 ) {
V_116 = - V_68 ;
goto V_137;
}
switch ( V_304 ) {
case V_310 :
if ( ! F_187 ( V_311 ) ) {
V_116 = - V_312 ;
goto V_137;
}
V_116 = F_160 ( V_26 , V_72 , V_239 , & V_295 ) ;
goto V_137;
case V_313 :
if ( ! F_187 ( V_311 ) ) {
V_116 = - V_312 ;
goto V_137;
}
V_116 = F_165 ( & V_11 , V_72 , V_239 ) ;
if ( V_116 == 0 ) {
V_116 = F_164 ( V_26 , V_75 -> V_95 , V_239 , NULL ,
& V_295 , NULL ) ;
if ( V_116 == 0 )
V_11 -> V_162 = 1 ;
F_166 ( V_11 ) ;
}
goto V_137;
case V_314 :
V_116 = F_165 ( & V_11 , V_72 , V_239 ) ;
if ( V_116 == 0 ) {
struct V_315 V_175 = {
. V_316 = V_239 ,
} ;
V_116 = F_188 ( V_26 , V_75 -> V_95 , & V_175 ) ;
F_166 ( V_11 ) ;
}
goto V_137;
case V_317 :
if ( ! F_187 ( V_311 ) ) {
V_116 = - V_312 ;
goto V_137;
}
V_116 = F_165 ( & V_11 , V_72 , V_239 ) ;
if ( V_116 == 0 ) {
struct V_315 V_175 = {
. V_316 = V_239 ,
} ;
V_116 = F_189 ( V_26 , V_75 -> V_95 , & V_175 , NULL ) ;
F_166 ( V_11 ) ;
}
goto V_137;
case V_318 :
if ( ! F_187 ( V_311 ) ) {
V_116 = - V_312 ;
goto V_137;
}
V_213 = V_259 ;
case V_319 :
V_116 = F_183 ( V_26 , V_213 , exp , V_124 , & V_295 ) ;
goto V_137;
default:
F_79 ( L_26 , V_304 ) ;
V_116 = - V_320 ;
goto V_137;
}
V_137:
F_190 ( V_26 ) ;
F_62 ( V_26 ) ;
for ( V_308 = V_295 . V_321 , V_221 = 0 ; V_221 < 4 ;
V_221 ++ , V_308 ++ ) {
if ( ! V_308 -> V_184 )
break;
F_191 ( & V_308 -> V_62 , V_308 -> V_184 ) ;
}
return V_116 ;
}
static int F_94 ( const struct V_25 * V_26 ,
struct V_6 * V_322 , struct V_130 * V_323 )
{
struct V_74 * V_75 = & V_322 -> V_147 . V_148 ;
struct V_6 * V_134 ;
struct V_324 V_325 = { L_27 } ;
struct V_326 * V_327 = NULL ;
int V_116 ;
if ( V_323 -> V_328 < 2 || F_192 ( V_323 , 1 ) < 1 ) {
F_79 ( L_28 ) ;
return - V_247 ;
}
V_134 = F_92 ( F_93 ( V_323 , 1 ) ) ;
if ( ! V_134 || ! V_134 -> V_329 || ! V_134 -> V_330 ) {
F_79 ( L_29 ,
F_93 ( V_323 , 1 ) ) ;
return - V_247 ;
}
F_193 ( & V_75 -> V_89 ) ;
F_47 ( & V_75 -> V_91 ) ;
F_47 ( & V_75 -> V_164 ) ;
V_75 -> V_201 = 0 ;
V_327 = F_61 ( sizeof( * V_327 ) , V_64 ) ;
if ( ! V_327 )
return - V_68 ;
V_327 -> V_331 = V_332 | V_333 |
V_334 |
V_335 | V_336 |
V_337 | V_338 |
V_339 ;
V_327 -> V_340 = V_341 ;
V_327 -> V_342 = V_343 ;
V_327 -> V_344 = V_172 ;
V_116 = F_194 ( V_26 , & V_75 -> V_95 , V_134 , & V_325 , V_327 , NULL ) ;
F_62 ( V_327 ) ;
if ( V_116 != 0 ) {
F_79 ( L_30 ,
F_93 ( V_323 , 1 ) ) ;
return V_116 ;
}
return V_116 ;
}
static int F_96 ( struct V_6 * V_322 )
{
struct V_74 * V_75 = & V_322 -> V_147 . V_148 ;
int V_116 ;
if ( ! F_33 ( & V_322 -> V_345 ) ) {
F_79 ( L_31 ) ;
return - V_45 ;
}
F_14 ( F_68 ( & V_75 -> V_95 -> V_346 ) > 0 ) ;
V_116 = F_195 ( V_75 -> V_95 ) ;
if ( V_116 != 0 )
F_79 ( L_32 , V_116 ) ;
return V_116 ;
}
static int F_196 ( const struct V_25 * V_26 ,
struct V_279 * * exp ,
struct V_6 * V_347 , struct V_324 * V_348 ,
struct V_326 * V_124 , void * V_349 )
{
int V_116 ;
struct V_218 V_350 = { 0 } ;
V_116 = F_197 ( & V_350 , V_347 , V_348 ) ;
if ( V_116 == 0 ) {
* exp = F_198 ( & V_350 ) ;
}
return V_116 ;
}
static int F_199 ( struct V_279 * exp )
{
int V_116 ;
if ( ! exp ) {
V_116 = - V_247 ;
goto V_137;
}
V_116 = F_200 ( exp ) ;
goto V_137;
V_137:
return V_116 ;
}
static int F_201 ( void )
{
int V_116 ;
V_116 = F_202 ( V_351 ) ;
if ( V_116 == 0 ) {
V_116 = F_203 ( & V_352 , NULL ,
V_54 ,
& V_199 ) ;
if ( V_116 )
F_204 ( V_351 ) ;
}
return V_116 ;
}
static void F_205 ( void )
{
F_206 ( V_54 ) ;
F_204 ( V_351 ) ;
}
static int T_8 F_207 ( void )
{
F_208 ( L_33 ) ;
F_14 ( V_226 % V_258 == 0 ) ;
return F_201 () ;
}
static void F_209 ( void )
{
F_205 () ;
}
