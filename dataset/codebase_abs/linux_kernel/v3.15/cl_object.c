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
void F_8 ( struct V_1 * V_2 )
{
F_9 ( F_10 ( & V_2 -> V_14 ) ) ;
F_11 ( & V_2 -> V_4 ) ;
}
struct V_17 * F_12 ( const struct V_18 * V_19 ,
struct V_20 * V_21 , const struct V_22 * V_23 ,
const struct V_24 * V_25 )
{
F_13 () ;
return F_14 ( F_15 ( V_19 , F_16 ( V_21 ) , V_23 , & V_25 -> V_26 ) ) ;
}
void F_17 ( const struct V_18 * V_19 , struct V_17 * V_27 )
{
F_18 ( V_19 , & V_27 -> V_28 ) ;
}
void F_19 ( struct V_17 * V_27 )
{
F_20 ( & V_27 -> V_28 ) ;
}
struct V_17 * F_21 ( struct V_17 * V_27 )
{
struct V_1 * V_29 = V_1 ( V_27 ) ;
struct V_17 * V_30 ;
while ( V_29 -> V_31 != NULL )
V_29 = V_29 -> V_31 ;
V_30 = F_14 ( F_22 ( & V_29 -> V_4 ) ) ;
F_23 ( V_32 , L_1 , V_27 , V_30 ) ;
return V_30 ;
}
static T_1 * F_24 ( struct V_17 * V_27 )
{
return & V_1 ( F_21 ( V_27 ) ) -> V_7 ;
}
void F_25 ( struct V_17 * V_27 )
{
F_26 ( F_24 ( V_27 ) ) ;
}
void F_27 ( struct V_17 * V_27 )
{
F_28 ( F_24 ( V_27 ) ) ;
}
int F_29 ( const struct V_18 * V_19 , struct V_17 * V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_30 ;
int V_3 ;
F_9 ( F_30 ( F_24 ( V_33 ) ) ) ;
V_30 = V_33 -> V_28 . V_37 ;
V_3 = 0 ;
F_31 (obj, &top->loh_layers, co_lu.lo_linkage) {
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
int F_32 ( const struct V_18 * V_19 , struct V_17 * V_33 ,
const struct V_34 * V_35 , unsigned V_40 )
{
struct V_36 * V_30 ;
int V_3 ;
F_9 ( F_30 ( F_24 ( V_33 ) ) ) ;
V_30 = V_33 -> V_28 . V_37 ;
V_3 = 0 ;
F_33 (obj, &top->loh_layers,
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
int F_34 ( const struct V_18 * V_19 , struct V_17 * V_33 ,
struct V_42 * V_43 )
{
struct V_36 * V_30 ;
int V_3 ;
V_30 = V_33 -> V_28 . V_37 ;
V_3 = 0 ;
F_33 (obj, &top->loh_layers,
co_lu.lo_linkage) {
if ( V_33 -> V_38 -> V_44 != NULL ) {
V_3 = V_33 -> V_38 -> V_44 ( V_19 , V_33 , V_43 ) ;
if ( V_3 != 0 )
break;
}
}
F_35 ( V_45 , V_19 , F_22 ( V_30 ) ,
L_2 V_46 L_3 V_46 L_4 V_46 L_5
L_6 V_46 L_7 V_46 L_8 ,
V_43 -> V_47 , V_43 -> V_48 , V_43 -> V_49 ,
V_43 -> V_50 , V_43 -> V_51 ) ;
return V_3 ;
}
int F_36 ( const struct V_18 * V_19 , struct V_17 * V_33 ,
const struct V_24 * V_52 )
{
struct V_36 * V_30 ;
int V_3 ;
V_30 = V_33 -> V_28 . V_37 ;
V_3 = 0 ;
F_31 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_33 -> V_38 -> V_53 != NULL ) {
V_3 = V_33 -> V_38 -> V_53 ( V_19 , V_33 , V_52 ) ;
if ( V_3 != 0 )
break;
}
}
return V_3 ;
}
void F_37 ( const struct V_18 * V_19 , struct V_17 * V_33 )
{
struct V_1 * V_29 ;
V_29 = V_1 ( V_33 ) ;
F_9 ( V_29 -> V_12 . V_54 == NULL ) ;
F_9 ( V_29 -> V_11 == 0 ) ;
F_38 ( V_55 , & V_29 -> V_4 . V_56 ) ;
F_39 ( V_19 , V_33 , 0 ) ;
}
void F_40 ( const struct V_18 * V_19 , struct V_17 * V_33 )
{
F_41 ( V_19 , V_33 ) ;
F_39 ( V_19 , V_33 , 1 ) ;
}
int F_42 ( struct V_17 * V_33 )
{
struct V_1 * V_57 = V_1 ( V_33 ) ;
int V_58 ;
F_26 ( & V_57 -> V_6 ) ;
V_58 = F_10 ( & V_57 -> V_14 ) ;
F_28 ( & V_57 -> V_6 ) ;
return ( V_58 == 0 ) ;
}
void F_43 ( struct V_59 * V_60 , const char * V_61 )
{
int V_62 ;
V_60 -> V_63 = V_61 ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ )
F_44 ( & V_60 -> V_65 [ V_62 ] , 0 ) ;
}
int F_45 ( const struct V_59 * V_60 , struct V_66 * V_67 , int V_2 )
{
int V_62 ;
if ( V_2 ) {
const char * V_68 [ V_64 ] = V_69 ;
F_46 ( V_67 , L_9 , L_5 ) ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ )
F_46 ( V_67 , L_10 , V_68 [ V_62 ] ) ;
F_46 ( V_67 , L_8 ) ;
}
F_46 ( V_67 , L_11 , V_60 -> V_63 ) ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ )
F_46 ( V_67 , L_12 , F_47 ( & V_60 -> V_65 [ V_62 ] ) ) ;
return 0 ;
}
int F_48 ( struct V_70 * V_71 , struct V_20 * V_72 )
{
int V_62 ;
int V_3 ;
V_3 = F_49 ( & V_71 -> V_73 , & V_72 -> V_74 ) ;
if ( V_3 == 0 ) {
F_43 ( & V_71 -> V_75 , L_13 ) ;
F_43 ( & V_71 -> V_76 , L_14 ) ;
for ( V_62 = 0 ; V_62 < F_50 ( V_71 -> V_77 ) ; ++ V_62 )
F_44 ( & V_71 -> V_77 [ 0 ] , 0 ) ;
for ( V_62 = 0 ; V_62 < F_50 ( V_71 -> V_78 ) ; ++ V_62 )
F_44 ( & V_71 -> V_78 [ V_62 ] , 0 ) ;
}
return V_3 ;
}
void F_51 ( struct V_70 * V_71 )
{
F_52 ( & V_71 -> V_73 ) ;
}
int F_53 ( const struct V_70 * V_79 , struct V_66 * V_67 )
{
int V_62 ;
static const char * V_80 [] = {
[ V_81 ] = L_15 ,
[ V_82 ] = L_16 ,
[ V_83 ] = L_17 ,
[ V_84 ] = L_18 ,
[ V_85 ] = L_19
} ;
static const char * V_86 [] = {
[ V_87 ] = L_20 ,
[ V_88 ] = L_21 ,
[ V_89 ] = L_22 ,
[ V_90 ] = L_23 ,
[ V_91 ] = L_24 ,
[ V_92 ] = L_15 ,
[ V_93 ] = L_19
} ;
F_54 ( & V_79 -> V_73 , V_67 ) ;
F_45 ( & V_79 -> V_75 , V_67 , 1 ) ;
F_46 ( V_67 , L_25 ) ;
for ( V_62 = 0 ; V_62 < F_50 ( V_79 -> V_77 ) ; ++ V_62 )
F_46 ( V_67 , L_26 , V_80 [ V_62 ] ,
F_47 ( & V_79 -> V_77 [ V_62 ] ) ) ;
F_46 ( V_67 , L_27 ) ;
F_45 ( & V_79 -> V_76 , V_67 , 0 ) ;
F_46 ( V_67 , L_25 ) ;
for ( V_62 = 0 ; V_62 < F_50 ( V_79 -> V_78 ) ; ++ V_62 )
F_46 ( V_67 , L_26 , V_86 [ V_62 ] ,
F_47 ( & V_79 -> V_78 [ V_62 ] ) ) ;
F_46 ( V_67 , L_27 ) ;
F_45 ( & V_94 , V_67 , 0 ) ;
F_46 ( V_67 , L_8 ) ;
return 0 ;
}
static void F_55 ( struct V_95 * V_96 , void * V_97 )
{
F_9 ( V_96 -> V_98 == 0 ) ;
F_9 ( V_96 -> V_99 == & F_55 ) ;
F_9 ( V_96 -> V_100 == NULL && V_96 -> V_101 == NULL ) ;
V_96 -> V_98 = 1 ;
V_96 -> V_100 = V_97 ;
F_56 ( V_102 ) ;
}
static unsigned F_57 ( struct V_103 * V_104 ,
const void * V_105 , unsigned V_106 )
{
#if V_107 == 64
return F_58 ( ( V_108 ) V_105 , V_106 ) ;
#else
return F_59 ( ( V_109 ) V_105 , V_106 ) ;
#endif
}
static void * F_60 ( struct V_110 * V_111 )
{
struct V_95 * V_96 = F_61 ( V_111 , struct V_95 , V_112 ) ;
F_9 ( V_96 -> V_99 == & F_55 ) ;
return ( void * ) V_96 ;
}
static int F_62 ( const void * V_105 , struct V_110 * V_111 )
{
struct V_95 * V_96 = F_60 ( V_111 ) ;
F_9 ( V_96 -> V_101 != NULL ) ;
return ( V_105 == V_96 -> V_101 ) ;
}
static void F_63 ( struct V_103 * V_113 , struct V_110 * V_111 )
{
struct V_95 * V_96 = F_61 ( V_111 , struct V_95 , V_112 ) ;
F_9 ( V_96 -> V_99 == & F_55 ) ;
}
static inline struct V_95 * F_64 ( void )
{
struct V_95 * V_96 ;
V_96 = F_65 ( V_114 , ( void * ) ( long ) V_115 -> V_116 ) ;
F_9 ( F_66 ( V_96 , V_96 -> V_99 == & F_55 ) ) ;
return V_96 ;
}
static inline void F_67 ( struct V_95 * V_96 )
{
if ( V_96 ) {
int V_117 ;
F_9 ( V_96 -> V_101 == NULL ) ;
V_96 -> V_101 = ( void * ) ( long ) V_115 -> V_116 ;
V_117 = F_68 ( V_114 , V_96 -> V_101 ,
& V_96 -> V_112 ) ;
F_9 ( V_117 == 0 ) ;
}
}
static inline void F_69 ( struct V_95 * V_96 )
{
void * V_118 ;
F_9 ( V_96 -> V_101 == ( void * ) ( long ) V_115 -> V_116 ) ;
V_118 = F_70 ( V_114 , V_96 -> V_101 ,
& V_96 -> V_112 ) ;
F_9 ( V_118 == V_96 ) ;
V_96 -> V_101 = NULL ;
}
static int F_71 ( void ) {
V_114 = F_72 ( L_28 ,
V_119 , V_119 ,
V_120 , 0 ,
V_121 ,
V_122 ,
& V_123 ,
V_124 ) ;
return V_114 != NULL ? 0 : - V_125 ;
}
static void F_73 ( void ) {
F_74 ( V_114 ) ;
}
static inline struct V_95 * F_75 ( struct V_95 * V_96 )
{
if ( V_96 == NULL )
V_96 = F_64 () ;
if ( V_96 && V_96 -> V_101 )
F_69 ( V_96 ) ;
return V_96 ;
}
static struct V_18 * F_76 ( V_109 V_126 , V_109 V_127 , void * V_97 )
{
struct V_18 * V_19 ;
struct V_95 * V_96 ;
F_77 ( V_96 , V_128 , V_129 ) ;
if ( V_96 != NULL ) {
int V_117 ;
F_6 ( & V_96 -> V_130 ) ;
V_96 -> V_99 = & F_55 ;
V_19 = & V_96 -> V_131 ;
V_117 = F_78 ( V_19 , V_132 | V_126 ) ;
if ( V_117 == 0 ) {
V_117 = F_79 ( & V_96 -> V_133 ,
V_134 | V_127 ) ;
if ( V_117 == 0 ) {
F_80 ( & V_96 -> V_133 ) ;
V_19 -> V_135 = & V_96 -> V_133 ;
F_55 ( V_96 , V_97 ) ;
} else
F_81 ( V_19 ) ;
}
if ( V_117 != 0 ) {
F_82 ( V_96 , V_128 ) ;
V_19 = F_83 ( V_117 ) ;
} else {
F_56 ( V_136 ) ;
F_56 ( V_137 ) ;
}
} else
V_19 = F_83 ( - V_125 ) ;
return V_19 ;
}
static void F_84 ( struct V_95 * V_96 )
{
F_85 ( V_137 ) ;
F_86 ( & V_96 -> V_131 . V_138 ) ;
F_86 ( & V_96 -> V_133 ) ;
F_82 ( V_96 , V_128 ) ;
}
static inline struct V_95 * F_87 ( struct V_18 * V_19 )
{
return F_88 ( V_19 , struct V_95 , V_131 ) ;
}
struct V_18 * F_89 ( int * V_139 )
{
struct V_18 * V_19 ;
struct V_95 * V_96 ;
F_56 ( V_140 ) ;
F_90 ( F_91 ( struct V_95 , V_99 ) == 0 ) ;
V_19 = NULL ;
V_96 = F_64 () ;
if ( V_96 != NULL ) {
F_56 ( V_141 ) ;
V_19 = & V_96 -> V_131 ;
* V_139 = ++ V_96 -> V_98 ;
}
F_23 ( V_142 , L_29 , V_96 ? V_96 -> V_98 : 0 , V_96 ) ;
return V_19 ;
}
struct V_18 * F_92 ( int * V_139 )
{
struct V_18 * V_19 ;
V_19 = F_89 ( V_139 ) ;
if ( V_19 == NULL ) {
V_19 = F_76 ( V_143 ,
V_144 ,
F_93 ( 0 ) ) ;
if ( ! F_94 ( V_19 ) ) {
struct V_95 * V_96 ;
V_96 = F_87 ( V_19 ) ;
F_67 ( V_96 ) ;
* V_139 = V_96 -> V_98 ;
F_23 ( V_142 , L_29 , V_96 -> V_98 , V_96 ) ;
}
}
return V_19 ;
}
struct V_18 * F_95 ( int * V_139 , V_109 V_145 )
{
struct V_18 * V_19 ;
F_9 ( F_89 ( V_139 ) == NULL ) ;
V_19 = F_76 ( V_145 , V_145 , F_93 ( 0 ) ) ;
if ( ! F_94 ( V_19 ) ) {
struct V_95 * V_96 ;
V_96 = F_87 ( V_19 ) ;
* V_139 = V_96 -> V_98 ;
F_23 ( V_142 , L_29 , V_96 -> V_98 , V_96 ) ;
}
return V_19 ;
}
static void F_96 ( struct V_95 * V_96 )
{
F_9 ( V_96 -> V_101 == NULL ) ;
F_97 ( & V_96 -> V_131 . V_138 ) ;
F_97 ( & V_96 -> V_133 ) ;
}
void F_98 ( struct V_18 * V_19 , int * V_139 )
{
struct V_95 * V_96 ;
V_96 = F_87 ( V_19 ) ;
F_9 ( V_96 -> V_98 > 0 ) ;
F_9 ( F_66 ( V_139 != NULL , V_96 -> V_98 == * V_139 ) ) ;
F_23 ( V_142 , L_29 , V_96 -> V_98 , V_96 ) ;
if ( -- V_96 -> V_98 == 0 ) {
F_85 ( V_102 ) ;
F_75 ( V_96 ) ;
V_96 -> V_100 = NULL ;
F_96 ( V_96 ) ;
F_84 ( V_96 ) ;
}
}
void * F_99 ( void )
{
return F_75 ( NULL ) ;
}
void F_100 ( void * V_118 )
{
F_75 ( NULL ) ;
F_67 ( V_118 ) ;
}
void F_101 ( struct V_18 * V_19 , int * V_139 )
{
struct V_95 * V_96 = F_87 ( V_19 ) ;
F_9 ( V_96 -> V_98 > 0 ) ;
F_67 ( V_96 ) ;
F_92 ( V_139 ) ;
F_23 ( V_142 , L_29 , V_96 -> V_98 , V_96 ) ;
}
void F_102 ( struct V_18 * V_19 , int * V_139 )
{
struct V_95 * V_96 = F_87 ( V_19 ) ;
F_9 ( V_96 -> V_98 > 1 ) ;
F_23 ( V_142 , L_29 , V_96 -> V_98 , V_96 ) ;
F_75 ( V_96 ) ;
F_98 ( V_19 , V_139 ) ;
}
struct V_18 * F_103 ( struct V_146 * V_147 )
{
struct V_18 * V_19 ;
V_147 -> V_148 = NULL ;
V_19 = F_89 ( & V_147 -> V_149 ) ;
if ( V_19 != NULL ) {
if ( ! F_104 ( V_19 ) )
return V_19 ;
else {
F_98 ( V_19 , & V_147 -> V_149 ) ;
V_147 -> V_148 = F_99 () ;
}
}
V_19 = F_92 ( & V_147 -> V_149 ) ;
if ( F_94 ( V_19 ) ) {
F_100 ( V_147 -> V_148 ) ;
return V_19 ;
}
F_9 ( ! F_104 ( V_19 ) ) ;
return V_19 ;
}
void F_105 ( struct V_146 * V_147 , struct V_18 * V_19 )
{
F_98 ( V_19 , & V_147 -> V_149 ) ;
F_100 ( V_147 -> V_148 ) ;
}
void F_106 ( struct V_42 * V_43 , const struct V_34 * V_35 )
{
V_43 -> V_47 = V_35 -> V_150 ;
V_43 -> V_48 = V_35 -> V_151 ;
V_43 -> V_49 = V_35 -> V_152 ;
V_43 -> V_50 = V_35 -> V_153 ;
V_43 -> V_51 = V_35 -> V_154 ;
}
void F_107 ( struct V_34 * V_35 , const struct V_42 * V_43 )
{
V_35 -> V_150 = V_43 -> V_47 ;
V_35 -> V_151 = V_43 -> V_48 ;
V_35 -> V_152 = V_43 -> V_49 ;
V_35 -> V_153 = V_43 -> V_50 ;
V_35 -> V_154 = V_43 -> V_51 ;
}
struct V_20 * F_108 ( const struct V_18 * V_19 , struct V_155 * V_79 ,
struct V_156 * V_157 ,
struct V_158 * V_159 )
{
const char * V_160 ;
struct V_158 * V_72 ;
F_9 ( V_157 != NULL ) ;
V_160 = V_157 -> V_161 ;
V_72 = V_157 -> V_162 -> V_163 ( V_19 , V_157 , NULL ) ;
if ( ! F_94 ( V_72 ) ) {
int V_117 ;
if ( V_79 != NULL )
V_72 -> V_164 = V_79 ;
V_117 = V_157 -> V_162 -> V_165 ( V_19 , V_72 , V_160 , V_159 ) ;
if ( V_117 == 0 ) {
F_109 ( V_72 ) ;
F_110 ( & V_72 -> V_166 ,
L_30 , & F_49 ) ;
} else {
V_157 -> V_162 -> V_167 ( V_19 , V_72 ) ;
F_111 ( L_31 , V_160 , V_117 ) ;
V_72 = F_83 ( V_117 ) ;
}
} else
F_111 ( L_32 , V_160 ) ;
return F_112 ( V_72 ) ;
}
void F_113 ( const struct V_18 * V_19 , struct V_20 * V_168 )
{
F_114 ( V_19 , F_16 ( V_168 ) ) ;
}
struct V_169 * F_115 ( const struct V_18 * V_19 )
{
return F_116 ( & V_19 -> V_138 , & V_170 ) ;
}
static void * F_117 ( const struct V_171 * V_172 ,
struct V_173 * V_105 )
{
struct V_169 * V_174 ;
V_174 = F_118 ( V_172 , V_105 ) ;
if ( ! F_94 ( V_174 ) ) {
int V_62 ;
for ( V_62 = 0 ; V_62 < F_50 ( V_174 -> V_175 ) ; ++ V_62 )
F_119 ( & V_174 -> V_175 [ V_62 ] . V_176 ) ;
}
return V_174 ;
}
static void F_120 ( const struct V_171 * V_172 ,
struct V_173 * V_105 , void * V_177 )
{
struct V_169 * V_174 ;
int V_62 ;
V_174 = V_177 ;
for ( V_62 = 0 ; V_62 < F_50 ( V_174 -> V_175 ) ; ++ V_62 )
F_121 ( & V_174 -> V_175 [ V_62 ] . V_176 ) ;
F_122 ( V_172 , V_105 , V_177 ) ;
}
static void F_123 ( const struct V_171 * V_172 ,
struct V_173 * V_105 , void * V_177 )
{
struct V_169 * V_174 = V_177 ;
int V_62 ;
for ( V_62 = 0 ; V_62 < F_50 ( V_174 -> V_175 ) ; ++ V_62 ) {
F_9 ( V_174 -> V_175 [ V_62 ] . V_178 == 0 ) ;
F_9 ( V_174 -> V_175 [ V_62 ] . V_179 == 0 ) ;
F_9 ( V_174 -> V_175 [ V_62 ] . V_180 == 0 ) ;
F_9 ( V_174 -> V_175 [ V_62 ] . V_181 == 0 ) ;
F_121 ( & V_174 -> V_175 [ V_62 ] . V_176 ) ;
F_119 ( & V_174 -> V_175 [ V_62 ] . V_176 ) ;
}
}
int F_124 ( void )
{
int V_3 ;
V_3 = F_71 () ;
if ( V_3 )
return V_3 ;
V_3 = F_125 ( V_182 ) ;
if ( V_3 )
goto V_183;
F_126 ( & V_170 ) ;
V_3 = F_127 ( & V_170 ) ;
if ( V_3 )
goto V_184;
V_3 = F_128 () ;
if ( V_3 )
goto V_185;
V_3 = F_129 () ;
if ( V_3 )
goto V_186;
return 0 ;
V_186:
F_130 () ;
V_185:
F_131 ( & V_170 ) ;
V_184:
F_132 ( V_182 ) ;
V_183:
F_73 () ;
return V_3 ;
}
void F_133 ( void )
{
F_130 () ;
F_134 () ;
F_131 ( & V_170 ) ;
F_132 ( V_182 ) ;
F_73 () ;
}
