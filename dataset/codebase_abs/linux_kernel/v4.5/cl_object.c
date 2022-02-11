int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( & V_2 -> V_4 ) ;
if ( V_3 == 0 ) {
F_3 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_5 , & V_8 ) ;
F_4 ( & V_2 -> V_6 , & V_9 ) ;
F_4 ( & V_2 -> V_7 , & V_10 ) ;
V_2 -> V_11 = 0 ;
F_5 ( & V_2 -> V_12 , V_13 ) ;
F_6 ( & V_2 -> V_14 ) ;
V_2 -> V_15 = F_7 ( sizeof( struct V_16 ) , 8 ) ;
}
return V_3 ;
}
struct V_17 * F_8 ( const struct V_18 * V_19 ,
struct V_20 * V_21 , const struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
F_9 () ;
return F_10 ( F_11 ( V_19 , F_12 ( V_21 ) , V_23 , & V_25 -> V_26 ) ) ;
}
void F_13 ( const struct V_18 * V_19 , struct V_17 * V_27 )
{
F_14 ( V_19 , & V_27 -> V_28 ) ;
}
void F_15 ( struct V_17 * V_27 )
{
F_16 ( & V_27 -> V_28 ) ;
}
struct V_17 * F_17 ( struct V_17 * V_27 )
{
struct V_1 * V_29 = V_1 ( V_27 ) ;
struct V_17 * V_30 ;
while ( V_29 -> V_31 != NULL )
V_29 = V_29 -> V_31 ;
V_30 = F_10 ( F_18 ( & V_29 -> V_4 ) ) ;
F_19 ( V_32 , L_1 , V_27 , V_30 ) ;
return V_30 ;
}
static T_1 * F_20 ( struct V_17 * V_27 )
{
return & V_1 ( F_17 ( V_27 ) ) -> V_7 ;
}
void F_21 ( struct V_17 * V_27 )
__acquires( cl_object_attr_guard( V_27 )
void F_22 ( struct V_17 * V_27 )
__releases( cl_object_attr_guard( V_27 )
int F_23 ( const struct V_18 * V_19 , struct V_17 * V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_30 ;
int V_3 ;
F_24 ( F_20 ( V_33 ) ) ;
V_30 = V_33 -> V_28 . V_37 ;
V_3 = 0 ;
F_25 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_33 -> V_38 -> V_39 != NULL ) {
V_3 = V_33 -> V_38 -> V_39 ( V_19 , V_33 , V_35 ) ;
if ( V_3 != 0 ) {
if ( V_3 > 0 )
V_3 = 0 ;
break;
}
}
}
return V_3 ;
}
int F_26 ( const struct V_18 * V_19 , struct V_17 * V_33 ,
const struct V_34 * V_35 , unsigned V_40 )
{
struct V_36 * V_30 ;
int V_3 ;
F_24 ( F_20 ( V_33 ) ) ;
V_30 = V_33 -> V_28 . V_37 ;
V_3 = 0 ;
F_27 (obj, &top->loh_layers,
co_lu.lo_linkage) {
if ( V_33 -> V_38 -> V_41 != NULL ) {
V_3 = V_33 -> V_38 -> V_41 ( V_19 , V_33 , V_35 , V_40 ) ;
if ( V_3 != 0 ) {
if ( V_3 > 0 )
V_3 = 0 ;
break;
}
}
}
return V_3 ;
}
int F_28 ( const struct V_18 * V_19 , struct V_17 * V_33 ,
struct V_42 * V_43 )
{
struct V_36 * V_30 ;
int V_3 ;
V_30 = V_33 -> V_28 . V_37 ;
V_3 = 0 ;
F_27 (obj, &top->loh_layers,
co_lu.lo_linkage) {
if ( V_33 -> V_38 -> V_44 != NULL ) {
V_3 = V_33 -> V_38 -> V_44 ( V_19 , V_33 , V_43 ) ;
if ( V_3 != 0 )
break;
}
}
F_29 ( V_45 , V_19 , F_18 ( V_30 ) ,
L_2 ,
V_43 -> V_46 , V_43 -> V_47 , V_43 -> V_48 ,
V_43 -> V_49 , V_43 -> V_50 ) ;
return V_3 ;
}
int F_30 ( const struct V_18 * V_19 , struct V_17 * V_33 ,
const struct V_24 * V_51 )
{
struct V_36 * V_30 ;
int V_3 ;
V_30 = V_33 -> V_28 . V_37 ;
V_3 = 0 ;
F_25 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_33 -> V_38 -> V_52 != NULL ) {
V_3 = V_33 -> V_38 -> V_52 ( V_19 , V_33 , V_51 ) ;
if ( V_3 != 0 )
break;
}
}
return V_3 ;
}
void F_31 ( const struct V_18 * V_19 , struct V_17 * V_33 )
{
struct V_1 * V_29 ;
V_29 = V_1 ( V_33 ) ;
F_32 ( V_29 -> V_12 . V_53 == NULL ) ;
F_32 ( V_29 -> V_11 == 0 ) ;
F_33 ( V_54 , & V_29 -> V_4 . V_55 ) ;
F_34 ( V_19 , V_33 , 0 ) ;
}
void F_35 ( const struct V_18 * V_19 , struct V_17 * V_33 )
{
F_36 ( V_19 , V_33 ) ;
F_34 ( V_19 , V_33 , 1 ) ;
}
void F_37 ( struct V_56 * V_57 , const char * V_58 )
{
int V_59 ;
V_57 -> V_60 = V_58 ;
for ( V_59 = 0 ; V_59 < V_61 ; V_59 ++ )
F_38 ( & V_57 -> V_62 [ V_59 ] , 0 ) ;
}
int F_39 ( const struct V_56 * V_57 , struct V_63 * V_64 , int V_2 )
{
int V_59 ;
if ( V_2 ) {
const char * V_65 [ V_61 ] = V_66 ;
F_40 ( V_64 , L_3 , L_4 ) ;
for ( V_59 = 0 ; V_59 < V_61 ; V_59 ++ )
F_40 ( V_64 , L_5 , V_65 [ V_59 ] ) ;
F_40 ( V_64 , L_6 ) ;
}
F_40 ( V_64 , L_7 , V_57 -> V_60 ) ;
for ( V_59 = 0 ; V_59 < V_61 ; V_59 ++ )
F_40 ( V_64 , L_8 , F_41 ( & V_57 -> V_62 [ V_59 ] ) ) ;
return 0 ;
}
int F_42 ( struct V_67 * V_68 , struct V_20 * V_69 )
{
int V_59 ;
int V_3 ;
V_3 = F_43 ( & V_68 -> V_70 , & V_69 -> V_71 ) ;
if ( V_3 == 0 ) {
F_37 ( & V_68 -> V_72 , L_9 ) ;
F_37 ( & V_68 -> V_73 , L_10 ) ;
for ( V_59 = 0 ; V_59 < F_44 ( V_68 -> V_74 ) ; ++ V_59 )
F_38 ( & V_68 -> V_74 [ 0 ] , 0 ) ;
for ( V_59 = 0 ; V_59 < F_44 ( V_68 -> V_75 ) ; ++ V_59 )
F_38 ( & V_68 -> V_75 [ V_59 ] , 0 ) ;
}
return V_3 ;
}
void F_45 ( struct V_67 * V_68 )
{
F_46 ( & V_68 -> V_70 ) ;
}
int F_47 ( const struct V_67 * V_76 , struct V_63 * V_64 )
{
int V_59 ;
static const char * V_77 [] = {
[ V_78 ] = L_11 ,
[ V_79 ] = L_12 ,
[ V_80 ] = L_13 ,
[ V_81 ] = L_14 ,
[ V_82 ] = L_15
} ;
static const char * V_83 [] = {
[ V_84 ] = L_16 ,
[ V_85 ] = L_17 ,
[ V_86 ] = L_18 ,
[ V_87 ] = L_19 ,
[ V_88 ] = L_20 ,
[ V_89 ] = L_11 ,
[ V_90 ] = L_15
} ;
F_48 ( & V_76 -> V_70 , V_64 ) ;
F_39 ( & V_76 -> V_72 , V_64 , 1 ) ;
F_40 ( V_64 , L_21 ) ;
for ( V_59 = 0 ; V_59 < F_44 ( V_76 -> V_74 ) ; ++ V_59 )
F_40 ( V_64 , L_22 , V_77 [ V_59 ] ,
F_41 ( & V_76 -> V_74 [ V_59 ] ) ) ;
F_40 ( V_64 , L_23 ) ;
F_39 ( & V_76 -> V_73 , V_64 , 0 ) ;
F_40 ( V_64 , L_21 ) ;
for ( V_59 = 0 ; V_59 < F_44 ( V_76 -> V_75 ) ; ++ V_59 )
F_40 ( V_64 , L_22 , V_83 [ V_59 ] ,
F_41 ( & V_76 -> V_75 [ V_59 ] ) ) ;
F_40 ( V_64 , L_23 ) ;
F_39 ( & V_91 , V_64 , 0 ) ;
F_40 ( V_64 , L_6 ) ;
return 0 ;
}
static void F_49 ( struct V_92 * V_93 , void * V_94 )
{
F_32 ( V_93 -> V_95 == 0 ) ;
F_32 ( V_93 -> V_96 == & F_49 ) ;
F_32 ( V_93 -> V_97 == NULL && V_93 -> V_98 == NULL ) ;
V_93 -> V_95 = 1 ;
V_93 -> V_97 = V_94 ;
F_50 ( V_99 ) ;
}
static unsigned F_51 ( struct V_100 * V_101 ,
const void * V_102 , unsigned V_103 )
{
#if V_104 == 64
return F_52 ( ( V_105 ) V_102 , V_103 ) ;
#else
return F_53 ( ( V_106 ) V_102 , V_103 ) ;
#endif
}
static void * F_54 ( struct V_107 * V_108 )
{
struct V_92 * V_93 = F_55 ( V_108 , struct V_92 , V_109 ) ;
F_32 ( V_93 -> V_96 == & F_49 ) ;
return ( void * ) V_93 ;
}
static int F_56 ( const void * V_102 , struct V_107 * V_108 )
{
struct V_92 * V_93 = F_54 ( V_108 ) ;
F_32 ( V_93 -> V_98 != NULL ) ;
return ( V_102 == V_93 -> V_98 ) ;
}
static void F_57 ( struct V_100 * V_110 , struct V_107 * V_108 )
{
struct V_92 * V_93 = F_55 ( V_108 , struct V_92 , V_109 ) ;
F_32 ( V_93 -> V_96 == & F_49 ) ;
}
static inline struct V_92 * F_58 ( void )
{
struct V_92 * V_93 ;
V_93 = F_59 ( V_111 , ( void * ) ( long ) V_112 -> V_113 ) ;
F_32 ( F_60 ( V_93 , V_93 -> V_96 == & F_49 ) ) ;
return V_93 ;
}
static inline void F_61 ( struct V_92 * V_93 )
{
if ( V_93 ) {
int V_114 ;
F_32 ( V_93 -> V_98 == NULL ) ;
V_93 -> V_98 = ( void * ) ( long ) V_112 -> V_113 ;
V_114 = F_62 ( V_111 , V_93 -> V_98 ,
& V_93 -> V_109 ) ;
F_32 ( V_114 == 0 ) ;
}
}
static inline void F_63 ( struct V_92 * V_93 )
{
void * V_115 ;
F_32 ( V_93 -> V_98 == ( void * ) ( long ) V_112 -> V_113 ) ;
V_115 = F_64 ( V_111 , V_93 -> V_98 ,
& V_93 -> V_109 ) ;
F_32 ( V_115 == V_93 ) ;
V_93 -> V_98 = NULL ;
}
static int F_65 ( void )
{
V_111 = F_66 ( L_24 ,
V_116 , V_116 ,
V_117 , 0 ,
V_118 ,
V_119 ,
& V_120 ,
V_121 ) ;
return V_111 != NULL ? 0 : - V_122 ;
}
static void F_67 ( void )
{
F_68 ( V_111 ) ;
}
static inline struct V_92 * F_69 ( struct V_92 * V_93 )
{
if ( V_93 == NULL )
V_93 = F_58 () ;
if ( V_93 && V_93 -> V_98 )
F_63 ( V_93 ) ;
return V_93 ;
}
static struct V_18 * F_70 ( V_106 V_123 , V_106 V_124 , void * V_94 )
{
struct V_18 * V_19 ;
struct V_92 * V_93 ;
V_93 = F_71 ( V_125 , V_126 | V_127 ) ;
if ( V_93 != NULL ) {
int V_114 ;
F_6 ( & V_93 -> V_128 ) ;
V_93 -> V_96 = & F_49 ;
V_19 = & V_93 -> V_129 ;
V_114 = F_72 ( V_19 , V_123 | V_130 ) ;
if ( V_114 == 0 ) {
V_114 = F_73 ( & V_93 -> V_131 ,
V_124 | V_132 ) ;
if ( V_114 == 0 ) {
F_74 ( & V_93 -> V_131 ) ;
V_19 -> V_133 = & V_93 -> V_131 ;
F_49 ( V_93 , V_94 ) ;
} else
F_75 ( V_19 ) ;
}
if ( V_114 != 0 ) {
F_76 ( V_125 , V_93 ) ;
V_19 = F_77 ( V_114 ) ;
} else {
F_50 ( V_134 ) ;
F_50 ( V_135 ) ;
}
} else
V_19 = F_77 ( - V_122 ) ;
return V_19 ;
}
static void F_78 ( struct V_92 * V_93 )
{
F_79 ( V_135 ) ;
F_80 ( & V_93 -> V_129 . V_136 ) ;
F_80 ( & V_93 -> V_131 ) ;
F_76 ( V_125 , V_93 ) ;
}
static inline struct V_92 * F_81 ( struct V_18 * V_19 )
{
return F_82 ( V_19 , struct V_92 , V_129 ) ;
}
static struct V_18 * F_83 ( int * V_137 )
{
struct V_18 * V_19 ;
struct V_92 * V_93 ;
F_50 ( V_138 ) ;
F_84 ( F_85 ( struct V_92 , V_96 ) == 0 ) ;
V_19 = NULL ;
V_93 = F_58 () ;
if ( V_93 != NULL ) {
F_50 ( V_139 ) ;
V_19 = & V_93 -> V_129 ;
* V_137 = ++ V_93 -> V_95 ;
}
F_19 ( V_140 , L_25 , V_93 ? V_93 -> V_95 : 0 , V_93 ) ;
return V_19 ;
}
struct V_18 * F_86 ( int * V_137 )
{
struct V_18 * V_19 ;
V_19 = F_83 ( V_137 ) ;
if ( V_19 == NULL ) {
V_19 = F_70 ( V_141 ,
V_142 ,
F_87 ( 0 ) ) ;
if ( ! F_88 ( V_19 ) ) {
struct V_92 * V_93 ;
V_93 = F_81 ( V_19 ) ;
F_61 ( V_93 ) ;
* V_137 = V_93 -> V_95 ;
F_19 ( V_140 , L_25 , V_93 -> V_95 , V_93 ) ;
}
}
return V_19 ;
}
struct V_18 * F_89 ( int * V_137 , V_106 V_143 )
{
struct V_18 * V_19 ;
F_32 ( F_83 ( V_137 ) == NULL ) ;
V_19 = F_70 ( V_143 , V_143 , F_87 ( 0 ) ) ;
if ( ! F_88 ( V_19 ) ) {
struct V_92 * V_93 ;
V_93 = F_81 ( V_19 ) ;
* V_137 = V_93 -> V_95 ;
F_19 ( V_140 , L_25 , V_93 -> V_95 , V_93 ) ;
}
return V_19 ;
}
static void F_90 ( struct V_92 * V_93 )
{
F_32 ( V_93 -> V_98 == NULL ) ;
F_91 ( & V_93 -> V_129 . V_136 ) ;
F_91 ( & V_93 -> V_131 ) ;
}
void F_92 ( struct V_18 * V_19 , int * V_137 )
{
struct V_92 * V_93 ;
V_93 = F_81 ( V_19 ) ;
F_32 ( V_93 -> V_95 > 0 ) ;
F_32 ( F_60 ( V_137 != NULL , V_93 -> V_95 == * V_137 ) ) ;
F_19 ( V_140 , L_25 , V_93 -> V_95 , V_93 ) ;
if ( -- V_93 -> V_95 == 0 ) {
F_79 ( V_99 ) ;
F_69 ( V_93 ) ;
V_93 -> V_97 = NULL ;
F_90 ( V_93 ) ;
F_78 ( V_93 ) ;
}
}
void * F_93 ( void )
{
return F_69 ( NULL ) ;
}
void F_94 ( void * V_115 )
{
F_69 ( NULL ) ;
F_61 ( V_115 ) ;
}
void F_95 ( struct V_18 * V_19 , int * V_137 )
{
struct V_92 * V_93 = F_81 ( V_19 ) ;
F_32 ( V_93 -> V_95 > 0 ) ;
F_61 ( V_93 ) ;
F_86 ( V_137 ) ;
F_19 ( V_140 , L_25 , V_93 -> V_95 , V_93 ) ;
}
void F_96 ( struct V_18 * V_19 , int * V_137 )
{
struct V_92 * V_93 = F_81 ( V_19 ) ;
F_32 ( V_93 -> V_95 > 1 ) ;
F_19 ( V_140 , L_25 , V_93 -> V_95 , V_93 ) ;
F_69 ( V_93 ) ;
F_92 ( V_19 , V_137 ) ;
}
struct V_18 * F_97 ( struct V_144 * V_145 )
{
struct V_18 * V_19 ;
V_145 -> V_146 = NULL ;
V_19 = F_83 ( & V_145 -> V_147 ) ;
if ( V_19 != NULL ) {
if ( ! F_98 ( V_19 ) )
return V_19 ;
F_92 ( V_19 , & V_145 -> V_147 ) ;
V_145 -> V_146 = F_93 () ;
}
V_19 = F_86 ( & V_145 -> V_147 ) ;
if ( F_88 ( V_19 ) ) {
F_94 ( V_145 -> V_146 ) ;
return V_19 ;
}
F_32 ( ! F_98 ( V_19 ) ) ;
return V_19 ;
}
void F_99 ( struct V_144 * V_145 , struct V_18 * V_19 )
{
F_92 ( V_19 , & V_145 -> V_147 ) ;
F_94 ( V_145 -> V_146 ) ;
}
void F_100 ( struct V_34 * V_35 , const struct V_42 * V_43 )
{
V_35 -> V_148 = V_43 -> V_46 ;
V_35 -> V_149 = V_43 -> V_47 ;
V_35 -> V_150 = V_43 -> V_48 ;
V_35 -> V_151 = V_43 -> V_49 ;
V_35 -> V_152 = V_43 -> V_50 ;
}
struct V_20 * F_101 ( const struct V_18 * V_19 , struct V_153 * V_76 ,
struct V_154 * V_155 ,
struct V_156 * V_157 )
{
const char * V_158 ;
struct V_156 * V_69 ;
F_32 ( V_155 != NULL ) ;
V_158 = V_155 -> V_159 ;
V_69 = V_155 -> V_160 -> V_161 ( V_19 , V_155 , NULL ) ;
if ( ! F_88 ( V_69 ) ) {
int V_114 ;
if ( V_76 != NULL )
V_69 -> V_162 = V_76 ;
V_114 = V_155 -> V_160 -> V_163 ( V_19 , V_69 , V_158 , V_157 ) ;
if ( V_114 == 0 ) {
F_102 ( V_69 ) ;
F_103 ( & V_69 -> V_164 ,
L_26 , & F_43 ) ;
} else {
V_155 -> V_160 -> V_165 ( V_19 , V_69 ) ;
F_104 ( L_27 , V_158 , V_114 ) ;
V_69 = F_77 ( V_114 ) ;
}
} else
F_104 ( L_28 , V_158 ) ;
return F_105 ( V_69 ) ;
}
void F_106 ( const struct V_18 * V_19 , struct V_20 * V_166 )
{
F_107 ( V_19 , F_12 ( V_166 ) ) ;
}
struct V_167 * F_108 ( const struct V_18 * V_19 )
{
return F_109 ( & V_19 -> V_136 , & V_168 ) ;
}
static void * F_110 ( const struct V_169 * V_170 ,
struct V_171 * V_102 )
{
struct V_167 * V_172 ;
V_172 = F_111 ( V_170 , V_102 ) ;
if ( ! F_88 ( V_172 ) ) {
int V_59 ;
for ( V_59 = 0 ; V_59 < F_44 ( V_172 -> V_173 ) ; ++ V_59 )
F_112 ( & V_172 -> V_173 [ V_59 ] . V_174 ) ;
}
return V_172 ;
}
static void F_113 ( const struct V_169 * V_170 ,
struct V_171 * V_102 , void * V_175 )
{
struct V_167 * V_172 ;
int V_59 ;
V_172 = V_175 ;
for ( V_59 = 0 ; V_59 < F_44 ( V_172 -> V_173 ) ; ++ V_59 )
F_114 ( & V_172 -> V_173 [ V_59 ] . V_174 ) ;
F_115 ( V_170 , V_102 , V_175 ) ;
}
static void F_116 ( const struct V_169 * V_170 ,
struct V_171 * V_102 , void * V_175 )
{
struct V_167 * V_172 = V_175 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < F_44 ( V_172 -> V_173 ) ; ++ V_59 ) {
F_32 ( V_172 -> V_173 [ V_59 ] . V_176 == 0 ) ;
F_32 ( V_172 -> V_173 [ V_59 ] . V_177 == 0 ) ;
F_32 ( V_172 -> V_173 [ V_59 ] . V_178 == 0 ) ;
F_32 ( V_172 -> V_173 [ V_59 ] . V_179 == 0 ) ;
F_114 ( & V_172 -> V_173 [ V_59 ] . V_174 ) ;
F_112 ( & V_172 -> V_173 [ V_59 ] . V_174 ) ;
}
}
int F_117 ( void )
{
int V_3 ;
V_3 = F_65 () ;
if ( V_3 )
return V_3 ;
V_3 = F_118 ( V_180 ) ;
if ( V_3 )
goto V_181;
F_119 ( & V_168 ) ;
V_3 = F_120 ( & V_168 ) ;
if ( V_3 )
goto V_182;
V_3 = F_121 () ;
if ( V_3 )
goto V_183;
V_3 = F_122 () ;
if ( V_3 )
goto V_184;
return 0 ;
V_184:
F_123 () ;
V_183:
F_124 ( & V_168 ) ;
V_182:
F_125 ( V_180 ) ;
V_181:
F_67 () ;
return V_3 ;
}
void F_126 ( void )
{
F_123 () ;
F_127 () ;
F_124 ( & V_168 ) ;
F_125 ( V_180 ) ;
F_67 () ;
}
