int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_4 ;
V_3 = F_2 ( & V_2 -> V_5 ) ;
if ( V_3 == 0 ) {
F_3 ( & V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_3 ( & V_2 -> V_8 ) ;
F_4 ( & V_2 -> V_6 , & V_9 ) ;
F_4 ( & V_2 -> V_7 , & V_10 ) ;
F_4 ( & V_2 -> V_8 , & V_11 ) ;
V_2 -> V_12 = 0 ;
F_5 ( & V_2 -> V_13 , V_14 ) ;
F_6 ( & V_2 -> V_15 ) ;
V_2 -> V_16 = F_7 ( sizeof( struct V_17 ) , 8 ) ;
}
RETURN ( V_3 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( F_10 ( & V_2 -> V_15 ) ) ;
F_11 ( & V_2 -> V_5 ) ;
}
struct V_18 * F_12 ( const struct V_19 * V_20 ,
struct V_21 * V_22 , const struct V_23 * V_24 ,
const struct V_25 * V_26 )
{
F_13 () ;
return F_14 ( F_15 ( V_20 , F_16 ( V_22 ) , V_24 , & V_26 -> V_27 ) ) ;
}
void F_17 ( const struct V_19 * V_20 , struct V_18 * V_28 )
{
F_18 ( V_20 , & V_28 -> V_29 ) ;
}
void F_19 ( struct V_18 * V_28 )
{
F_20 ( & V_28 -> V_29 ) ;
}
struct V_18 * F_21 ( struct V_18 * V_28 )
{
struct V_1 * V_30 = V_1 ( V_28 ) ;
struct V_18 * V_31 ;
while ( V_30 -> V_32 != NULL )
V_30 = V_30 -> V_32 ;
V_31 = F_14 ( F_22 ( & V_30 -> V_5 ) ) ;
F_23 ( V_33 , L_1 , V_28 , V_31 ) ;
return V_31 ;
}
static T_1 * F_24 ( struct V_18 * V_28 )
{
return & V_1 ( F_21 ( V_28 ) ) -> V_8 ;
}
void F_25 ( struct V_18 * V_28 )
{
F_26 ( F_24 ( V_28 ) ) ;
}
void F_27 ( struct V_18 * V_28 )
{
F_28 ( F_24 ( V_28 ) ) ;
}
int F_29 ( const struct V_19 * V_20 , struct V_18 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_31 ;
int V_3 ;
F_9 ( F_30 ( F_24 ( V_34 ) ) ) ;
V_4 ;
V_31 = V_34 -> V_29 . V_38 ;
V_3 = 0 ;
F_31 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_34 -> V_39 -> V_40 != NULL ) {
V_3 = V_34 -> V_39 -> V_40 ( V_20 , V_34 , V_36 ) ;
if ( V_3 != 0 ) {
if ( V_3 > 0 )
V_3 = 0 ;
break;
}
}
}
RETURN ( V_3 ) ;
}
int F_32 ( const struct V_19 * V_20 , struct V_18 * V_34 ,
const struct V_35 * V_36 , unsigned V_41 )
{
struct V_37 * V_31 ;
int V_3 ;
F_9 ( F_30 ( F_24 ( V_34 ) ) ) ;
V_4 ;
V_31 = V_34 -> V_29 . V_38 ;
V_3 = 0 ;
F_33 (obj, &top->loh_layers,
co_lu.lo_linkage) {
if ( V_34 -> V_39 -> V_42 != NULL ) {
V_3 = V_34 -> V_39 -> V_42 ( V_20 , V_34 , V_36 , V_41 ) ;
if ( V_3 != 0 ) {
if ( V_3 > 0 )
V_3 = 0 ;
break;
}
}
}
RETURN ( V_3 ) ;
}
int F_34 ( const struct V_19 * V_20 , struct V_18 * V_34 ,
struct V_43 * V_44 )
{
struct V_37 * V_31 ;
int V_3 ;
V_4 ;
V_31 = V_34 -> V_29 . V_38 ;
V_3 = 0 ;
F_33 (obj, &top->loh_layers,
co_lu.lo_linkage) {
if ( V_34 -> V_39 -> V_45 != NULL ) {
V_3 = V_34 -> V_39 -> V_45 ( V_20 , V_34 , V_44 ) ;
if ( V_3 != 0 )
break;
}
}
F_35 ( V_46 , V_20 , F_22 ( V_31 ) ,
L_2 V_47 L_3 V_47 L_4 V_47 L_5
L_6 V_47 L_7 V_47 L_8 ,
V_44 -> V_48 , V_44 -> V_49 , V_44 -> V_50 ,
V_44 -> V_51 , V_44 -> V_52 ) ;
RETURN ( V_3 ) ;
}
int F_36 ( const struct V_19 * V_20 , struct V_18 * V_34 ,
const struct V_25 * V_53 )
{
struct V_37 * V_31 ;
int V_3 ;
V_4 ;
V_31 = V_34 -> V_29 . V_38 ;
V_3 = 0 ;
F_31 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_34 -> V_39 -> V_54 != NULL ) {
V_3 = V_34 -> V_39 -> V_54 ( V_20 , V_34 , V_53 ) ;
if ( V_3 != 0 )
break;
}
}
RETURN ( V_3 ) ;
}
void F_37 ( const struct V_19 * V_20 , struct V_18 * V_34 )
{
struct V_1 * V_30 ;
V_30 = V_1 ( V_34 ) ;
F_9 ( V_30 -> V_13 . V_55 == NULL ) ;
F_9 ( V_30 -> V_12 == 0 ) ;
F_38 ( V_56 , & V_30 -> V_5 . V_57 ) ;
F_39 ( V_20 , V_34 , 0 ) ;
}
void F_40 ( const struct V_19 * V_20 , struct V_18 * V_34 )
{
V_4 ;
F_41 ( V_20 , V_34 ) ;
F_39 ( V_20 , V_34 , 1 ) ;
EXIT ;
}
int F_42 ( struct V_18 * V_34 )
{
struct V_1 * V_58 = V_1 ( V_34 ) ;
int V_59 ;
F_26 ( & V_58 -> V_7 ) ;
V_59 = F_10 ( & V_58 -> V_15 ) ;
F_28 ( & V_58 -> V_7 ) ;
return ( V_59 == 0 ) ;
}
void F_43 ( struct V_60 * V_61 , const char * V_62 )
{
int V_63 ;
V_61 -> V_64 = V_62 ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ )
F_44 ( & V_61 -> V_66 [ V_63 ] , 0 ) ;
}
int F_45 ( const struct V_60 * V_61 , struct V_67 * V_68 , int V_2 )
{
int V_63 ;
if ( V_2 ) {
const char * V_69 [ V_65 ] = V_70 ;
F_46 ( V_68 , L_9 , L_5 ) ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ )
F_46 ( V_68 , L_10 , V_69 [ V_63 ] ) ;
F_46 ( V_68 , L_8 ) ;
}
F_46 ( V_68 , L_11 , V_61 -> V_64 ) ;
for ( V_63 = 0 ; V_63 < V_65 ; V_63 ++ )
F_46 ( V_68 , L_12 , F_47 ( & V_61 -> V_66 [ V_63 ] ) ) ;
return 0 ;
}
int F_48 ( struct V_71 * V_72 , struct V_21 * V_73 )
{
int V_63 ;
int V_3 ;
V_3 = F_49 ( & V_72 -> V_74 , & V_73 -> V_75 ) ;
if ( V_3 == 0 ) {
F_43 ( & V_72 -> V_76 , L_13 ) ;
F_43 ( & V_72 -> V_77 , L_14 ) ;
for ( V_63 = 0 ; V_63 < F_50 ( V_72 -> V_78 ) ; ++ V_63 )
F_44 ( & V_72 -> V_78 [ 0 ] , 0 ) ;
for ( V_63 = 0 ; V_63 < F_50 ( V_72 -> V_79 ) ; ++ V_63 )
F_44 ( & V_72 -> V_79 [ V_63 ] , 0 ) ;
}
return V_3 ;
}
void F_51 ( struct V_71 * V_72 )
{
F_52 ( & V_72 -> V_74 ) ;
}
int F_53 ( const struct V_71 * V_80 , struct V_67 * V_68 )
{
int V_63 ;
static const char * V_81 [] = {
[ V_82 ] = L_15 ,
[ V_83 ] = L_16 ,
[ V_84 ] = L_17 ,
[ V_85 ] = L_18 ,
[ V_86 ] = L_19
} ;
static const char * V_87 [] = {
[ V_88 ] = L_20 ,
[ V_89 ] = L_21 ,
[ V_90 ] = L_22 ,
[ V_91 ] = L_23 ,
[ V_92 ] = L_24 ,
[ V_93 ] = L_15 ,
[ V_94 ] = L_19
} ;
F_54 ( & V_80 -> V_74 , V_68 ) ;
F_45 ( & V_80 -> V_76 , V_68 , 1 ) ;
F_46 ( V_68 , L_25 ) ;
for ( V_63 = 0 ; V_63 < F_50 ( V_80 -> V_78 ) ; ++ V_63 )
F_46 ( V_68 , L_26 , V_81 [ V_63 ] ,
F_47 ( & V_80 -> V_78 [ V_63 ] ) ) ;
F_46 ( V_68 , L_27 ) ;
F_45 ( & V_80 -> V_77 , V_68 , 0 ) ;
F_46 ( V_68 , L_25 ) ;
for ( V_63 = 0 ; V_63 < F_50 ( V_80 -> V_79 ) ; ++ V_63 )
F_46 ( V_68 , L_26 , V_87 [ V_63 ] ,
F_47 ( & V_80 -> V_79 [ V_63 ] ) ) ;
F_46 ( V_68 , L_27 ) ;
F_45 ( & V_95 , V_68 , 0 ) ;
F_46 ( V_68 , L_8 ) ;
return 0 ;
}
static void F_55 ( struct V_96 * V_97 , void * V_98 )
{
F_9 ( V_97 -> V_99 == 0 ) ;
F_9 ( V_97 -> V_100 == & F_55 ) ;
F_9 ( V_97 -> V_101 == NULL && V_97 -> V_102 == NULL ) ;
V_97 -> V_99 = 1 ;
V_97 -> V_101 = V_98 ;
F_56 ( V_103 ) ;
}
static unsigned F_57 ( T_2 * V_104 ,
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
struct V_96 * V_97 = F_61 ( V_111 , struct V_96 , V_112 ) ;
F_9 ( V_97 -> V_100 == & F_55 ) ;
return ( void * ) V_97 ;
}
static int F_62 ( const void * V_105 , struct V_110 * V_111 )
{
struct V_96 * V_97 = F_60 ( V_111 ) ;
F_9 ( V_97 -> V_102 != NULL ) ;
return ( V_105 == V_97 -> V_102 ) ;
}
static void F_63 ( T_2 * V_113 , struct V_110 * V_111 )
{
struct V_96 * V_97 = F_61 ( V_111 , struct V_96 , V_112 ) ;
F_9 ( V_97 -> V_100 == & F_55 ) ;
}
static inline struct V_96 * F_64 ( void )
{
struct V_96 * V_97 ;
V_97 = F_65 ( V_114 , ( void * ) ( long ) V_115 -> V_116 ) ;
F_9 ( F_66 ( V_97 , V_97 -> V_100 == & F_55 ) ) ;
return V_97 ;
}
static inline void F_67 ( struct V_96 * V_97 )
{
if ( V_97 ) {
int V_117 ;
F_9 ( V_97 -> V_102 == NULL ) ;
V_97 -> V_102 = ( void * ) ( long ) V_115 -> V_116 ;
V_117 = F_68 ( V_114 , V_97 -> V_102 ,
& V_97 -> V_112 ) ;
F_9 ( V_117 == 0 ) ;
}
}
static inline void F_69 ( struct V_96 * V_97 )
{
void * V_118 ;
F_9 ( V_97 -> V_102 == ( void * ) ( long ) V_115 -> V_116 ) ;
V_118 = F_70 ( V_114 , V_97 -> V_102 ,
& V_97 -> V_112 ) ;
F_9 ( V_118 == V_97 ) ;
V_97 -> V_102 = NULL ;
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
static inline struct V_96 * F_75 ( struct V_96 * V_97 )
{
if ( V_97 == NULL )
V_97 = F_64 () ;
if ( V_97 && V_97 -> V_102 )
F_69 ( V_97 ) ;
return V_97 ;
}
static struct V_19 * F_76 ( V_109 V_126 , V_109 V_127 , void * V_98 )
{
struct V_19 * V_20 ;
struct V_96 * V_97 ;
F_77 ( V_97 , V_128 , V_129 ) ;
if ( V_97 != NULL ) {
int V_117 ;
F_6 ( & V_97 -> V_130 ) ;
V_97 -> V_100 = & F_55 ;
V_20 = & V_97 -> V_131 ;
V_117 = F_78 ( V_20 , V_132 | V_126 ) ;
if ( V_117 == 0 ) {
V_117 = F_79 ( & V_97 -> V_133 ,
V_134 | V_127 ) ;
if ( V_117 == 0 ) {
F_80 ( & V_97 -> V_133 ) ;
V_20 -> V_135 = & V_97 -> V_133 ;
F_55 ( V_97 , V_98 ) ;
} else
F_81 ( V_20 ) ;
}
if ( V_117 != 0 ) {
F_82 ( V_97 , V_128 ) ;
V_20 = F_83 ( V_117 ) ;
} else {
F_56 ( V_136 ) ;
F_56 ( V_137 ) ;
}
} else
V_20 = F_83 ( - V_125 ) ;
return V_20 ;
}
static void F_84 ( struct V_96 * V_97 )
{
F_85 ( V_137 ) ;
F_86 ( & V_97 -> V_131 . V_138 ) ;
F_86 ( & V_97 -> V_133 ) ;
F_82 ( V_97 , V_128 ) ;
}
static inline struct V_96 * F_87 ( struct V_19 * V_20 )
{
return F_88 ( V_20 , struct V_96 , V_131 ) ;
}
struct V_19 * F_89 ( int * V_139 )
{
struct V_19 * V_20 ;
struct V_96 * V_97 ;
F_56 ( V_140 ) ;
F_90 ( F_91 ( struct V_96 , V_100 ) == 0 ) ;
V_20 = NULL ;
V_97 = F_64 () ;
if ( V_97 != NULL ) {
F_56 ( V_141 ) ;
V_20 = & V_97 -> V_131 ;
* V_139 = ++ V_97 -> V_99 ;
}
F_23 ( V_142 , L_29 , V_97 ? V_97 -> V_99 : 0 , V_97 ) ;
return V_20 ;
}
struct V_19 * F_92 ( int * V_139 )
{
struct V_19 * V_20 ;
V_20 = F_89 ( V_139 ) ;
if ( V_20 == NULL ) {
V_20 = F_76 ( V_143 ,
V_144 ,
F_93 ( 0 ) ) ;
if ( ! F_94 ( V_20 ) ) {
struct V_96 * V_97 ;
V_97 = F_87 ( V_20 ) ;
F_67 ( V_97 ) ;
* V_139 = V_97 -> V_99 ;
F_23 ( V_142 , L_29 , V_97 -> V_99 , V_97 ) ;
}
}
return V_20 ;
}
struct V_19 * F_95 ( int * V_139 , V_109 V_145 )
{
struct V_19 * V_20 ;
F_9 ( F_89 ( V_139 ) == NULL ) ;
V_20 = F_76 ( V_145 , V_145 , F_93 ( 0 ) ) ;
if ( ! F_94 ( V_20 ) ) {
struct V_96 * V_97 ;
V_97 = F_87 ( V_20 ) ;
* V_139 = V_97 -> V_99 ;
F_23 ( V_142 , L_29 , V_97 -> V_99 , V_97 ) ;
}
return V_20 ;
}
static void F_96 ( struct V_96 * V_97 )
{
F_9 ( V_97 -> V_102 == NULL ) ;
F_97 ( & V_97 -> V_131 . V_138 ) ;
F_97 ( & V_97 -> V_133 ) ;
}
void F_98 ( struct V_19 * V_20 , int * V_139 )
{
struct V_96 * V_97 ;
V_97 = F_87 ( V_20 ) ;
F_9 ( V_97 -> V_99 > 0 ) ;
F_9 ( F_66 ( V_139 != NULL , V_97 -> V_99 == * V_139 ) ) ;
F_23 ( V_142 , L_29 , V_97 -> V_99 , V_97 ) ;
if ( -- V_97 -> V_99 == 0 ) {
F_85 ( V_103 ) ;
F_75 ( V_97 ) ;
V_97 -> V_101 = NULL ;
F_96 ( V_97 ) ;
F_84 ( V_97 ) ;
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
void F_101 ( struct V_19 * V_20 , int * V_139 )
{
struct V_96 * V_97 = F_87 ( V_20 ) ;
F_9 ( V_97 -> V_99 > 0 ) ;
F_67 ( V_97 ) ;
F_92 ( V_139 ) ;
F_23 ( V_142 , L_29 , V_97 -> V_99 , V_97 ) ;
}
void F_102 ( struct V_19 * V_20 , int * V_139 )
{
struct V_96 * V_97 = F_87 ( V_20 ) ;
F_9 ( V_97 -> V_99 > 1 ) ;
F_23 ( V_142 , L_29 , V_97 -> V_99 , V_97 ) ;
F_75 ( V_97 ) ;
F_98 ( V_20 , V_139 ) ;
}
struct V_19 * F_103 ( struct V_146 * V_147 )
{
struct V_19 * V_20 ;
V_147 -> V_148 = NULL ;
V_20 = F_89 ( & V_147 -> V_149 ) ;
if ( V_20 != NULL ) {
if ( ! F_104 ( V_20 ) )
return V_20 ;
else {
F_98 ( V_20 , & V_147 -> V_149 ) ;
V_147 -> V_148 = F_99 () ;
}
}
V_20 = F_92 ( & V_147 -> V_149 ) ;
if ( F_94 ( V_20 ) ) {
F_100 ( V_147 -> V_148 ) ;
return V_20 ;
}
F_9 ( ! F_104 ( V_20 ) ) ;
return V_20 ;
}
void F_105 ( struct V_146 * V_147 , struct V_19 * V_20 )
{
F_98 ( V_20 , & V_147 -> V_149 ) ;
F_100 ( V_147 -> V_148 ) ;
}
void F_106 ( struct V_43 * V_44 , const struct V_35 * V_36 )
{
V_4 ;
V_44 -> V_48 = V_36 -> V_150 ;
V_44 -> V_49 = V_36 -> V_151 ;
V_44 -> V_50 = V_36 -> V_152 ;
V_44 -> V_51 = V_36 -> V_153 ;
V_44 -> V_52 = V_36 -> V_154 ;
EXIT ;
}
void F_107 ( struct V_35 * V_36 , const struct V_43 * V_44 )
{
V_4 ;
V_36 -> V_150 = V_44 -> V_48 ;
V_36 -> V_151 = V_44 -> V_49 ;
V_36 -> V_152 = V_44 -> V_50 ;
V_36 -> V_153 = V_44 -> V_51 ;
V_36 -> V_154 = V_44 -> V_52 ;
EXIT ;
}
struct V_21 * F_108 ( const struct V_19 * V_20 , struct V_155 * V_80 ,
struct V_156 * V_157 ,
struct V_158 * V_159 )
{
const char * V_160 ;
struct V_158 * V_73 ;
F_9 ( V_157 != NULL ) ;
V_160 = V_157 -> V_161 ;
V_73 = V_157 -> V_162 -> V_163 ( V_20 , V_157 , NULL ) ;
if ( ! F_94 ( V_73 ) ) {
int V_117 ;
if ( V_80 != NULL )
V_73 -> V_164 = V_80 ;
V_117 = V_157 -> V_162 -> V_165 ( V_20 , V_73 , V_160 , V_159 ) ;
if ( V_117 == 0 ) {
F_109 ( V_73 ) ;
F_110 ( & V_73 -> V_166 ,
L_30 , & F_49 ) ;
} else {
V_157 -> V_162 -> V_167 ( V_20 , V_73 ) ;
F_111 ( L_31 , V_160 , V_117 ) ;
V_73 = F_83 ( V_117 ) ;
}
} else
F_111 ( L_32 , V_160 ) ;
return F_112 ( V_73 ) ;
}
void F_113 ( const struct V_19 * V_20 , struct V_21 * V_168 )
{
F_114 ( V_20 , F_16 ( V_168 ) ) ;
}
struct V_169 * F_115 ( const struct V_19 * V_20 )
{
return F_116 ( & V_20 -> V_138 , & V_170 ) ;
}
static void * F_117 ( const struct V_171 * V_172 ,
struct V_173 * V_105 )
{
struct V_169 * V_174 ;
V_174 = F_118 ( V_172 , V_105 ) ;
if ( ! F_94 ( V_174 ) ) {
int V_63 ;
for ( V_63 = 0 ; V_63 < F_50 ( V_174 -> V_175 ) ; ++ V_63 )
F_119 ( & V_174 -> V_175 [ V_63 ] . V_176 ) ;
}
return V_174 ;
}
static void F_120 ( const struct V_171 * V_172 ,
struct V_173 * V_105 , void * V_177 )
{
struct V_169 * V_174 ;
int V_63 ;
V_174 = V_177 ;
for ( V_63 = 0 ; V_63 < F_50 ( V_174 -> V_175 ) ; ++ V_63 )
F_121 ( & V_174 -> V_175 [ V_63 ] . V_176 ) ;
F_122 ( V_172 , V_105 , V_177 ) ;
}
static void F_123 ( const struct V_171 * V_172 ,
struct V_173 * V_105 , void * V_177 )
{
struct V_169 * V_174 = V_177 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < F_50 ( V_174 -> V_175 ) ; ++ V_63 ) {
F_9 ( V_174 -> V_175 [ V_63 ] . V_178 == 0 ) ;
F_9 ( V_174 -> V_175 [ V_63 ] . V_179 == 0 ) ;
F_9 ( V_174 -> V_175 [ V_63 ] . V_180 == 0 ) ;
F_9 ( V_174 -> V_175 [ V_63 ] . V_181 == 0 ) ;
F_121 ( & V_174 -> V_175 [ V_63 ] . V_176 ) ;
F_119 ( & V_174 -> V_175 [ V_63 ] . V_176 ) ;
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
