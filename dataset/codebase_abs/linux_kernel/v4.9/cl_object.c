int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( & V_2 -> V_4 ) ;
if ( V_3 == 0 ) {
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_5 , & V_6 ) ;
V_2 -> V_7 = 0 ;
}
return V_3 ;
}
struct V_8 * F_5 ( const struct V_9 * V_10 ,
struct V_11 * V_12 , const struct V_13 * V_14 ,
const struct V_15 * V_16 )
{
F_6 () ;
return F_7 ( F_8 ( V_10 , F_9 ( V_12 ) , V_14 , & V_16 -> V_17 ) ) ;
}
void F_10 ( const struct V_9 * V_10 , struct V_8 * V_18 )
{
F_11 ( V_10 , & V_18 -> V_19 ) ;
}
void F_12 ( struct V_8 * V_18 )
{
F_13 ( & V_18 -> V_19 ) ;
}
struct V_8 * F_14 ( struct V_8 * V_18 )
{
struct V_1 * V_20 = V_1 ( V_18 ) ;
struct V_8 * V_21 ;
while ( V_20 -> V_22 )
V_20 = V_20 -> V_22 ;
V_21 = F_7 ( F_15 ( & V_20 -> V_4 ) ) ;
F_16 ( V_23 , L_1 , V_18 , V_21 ) ;
return V_21 ;
}
static T_1 * F_17 ( struct V_8 * V_18 )
{
return & V_1 ( F_14 ( V_18 ) ) -> V_5 ;
}
void F_18 ( struct V_8 * V_18 )
__acquires( cl_object_attr_guard( V_18 )
void F_19 ( struct V_8 * V_18 )
__releases( cl_object_attr_guard( V_18 )
int F_20 ( const struct V_9 * V_10 , struct V_8 * V_24 ,
struct V_25 * V_26 )
{
struct V_27 * V_21 ;
int V_3 ;
F_21 ( F_17 ( V_24 ) ) ;
V_21 = V_24 -> V_19 . V_28 ;
V_3 = 0 ;
F_22 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_24 -> V_29 -> V_30 ) {
V_3 = V_24 -> V_29 -> V_30 ( V_10 , V_24 , V_26 ) ;
if ( V_3 != 0 ) {
if ( V_3 > 0 )
V_3 = 0 ;
break;
}
}
}
return V_3 ;
}
int F_23 ( const struct V_9 * V_10 , struct V_8 * V_24 ,
const struct V_25 * V_26 , unsigned int V_31 )
{
struct V_27 * V_21 ;
int V_3 ;
F_21 ( F_17 ( V_24 ) ) ;
V_21 = V_24 -> V_19 . V_28 ;
V_3 = 0 ;
F_24 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_24 -> V_29 -> V_32 ) {
V_3 = V_24 -> V_29 -> V_32 ( V_10 , V_24 , V_26 ,
V_31 ) ;
if ( V_3 != 0 ) {
if ( V_3 > 0 )
V_3 = 0 ;
break;
}
}
}
return V_3 ;
}
int F_25 ( const struct V_9 * V_10 , struct V_8 * V_24 ,
struct V_33 * V_34 )
{
struct V_27 * V_21 ;
int V_3 ;
V_21 = V_24 -> V_19 . V_28 ;
V_3 = 0 ;
F_24 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_24 -> V_29 -> V_35 ) {
V_3 = V_24 -> V_29 -> V_35 ( V_10 , V_24 , V_34 ) ;
if ( V_3 != 0 )
break;
}
}
F_26 ( V_36 , V_10 , F_15 ( V_21 ) ,
L_2 ,
V_34 -> V_37 , V_34 -> V_38 , V_34 -> V_39 ,
V_34 -> V_40 , V_34 -> V_41 ) ;
return V_3 ;
}
int F_27 ( const struct V_9 * V_10 , struct V_8 * V_24 ,
const struct V_15 * V_42 )
{
struct V_27 * V_21 ;
int V_3 ;
V_21 = V_24 -> V_19 . V_28 ;
V_3 = 0 ;
F_22 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_24 -> V_29 -> V_43 ) {
V_3 = V_24 -> V_29 -> V_43 ( V_10 , V_24 , V_42 ) ;
if ( V_3 != 0 )
break;
}
}
return V_3 ;
}
int F_28 ( const struct V_9 * V_10 , struct V_8 * V_24 )
{
struct V_27 * V_21 ;
struct V_8 * V_18 ;
int V_3 ;
V_21 = V_24 -> V_19 . V_28 ;
V_3 = 0 ;
F_22 (o, &top->loh_layers, co_lu.lo_linkage) {
if ( V_18 -> V_29 -> V_44 ) {
V_3 = V_18 -> V_29 -> V_44 ( V_10 , V_18 ) ;
if ( V_3 != 0 )
break;
}
}
return V_3 ;
}
int F_29 ( const struct V_9 * V_10 , struct V_8 * V_24 ,
struct V_45 T_2 * V_46 )
{
struct V_27 * V_21 ;
int V_3 = 0 ;
V_21 = V_24 -> V_19 . V_28 ;
F_22 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_24 -> V_29 -> V_47 ) {
V_3 = V_24 -> V_29 -> V_47 ( V_10 , V_24 , V_46 ) ;
if ( V_3 )
break;
}
}
return V_3 ;
}
void F_30 ( const struct V_9 * V_10 , struct V_8 * V_24 )
{
struct V_1 * V_20 = V_1 ( V_24 ) ;
F_31 ( V_48 , & V_20 -> V_4 . V_49 ) ;
}
void F_32 ( struct V_50 * V_51 , const char * V_52 )
{
int V_53 ;
V_51 -> V_54 = V_52 ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_33 ( & V_51 -> V_56 [ V_53 ] , 0 ) ;
}
static int F_34 ( const struct V_50 * V_51 ,
struct V_57 * V_58 , int V_2 )
{
int V_53 ;
if ( V_2 ) {
const char * V_59 [ V_55 ] = V_60 ;
F_35 ( V_58 , L_3 , L_4 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_35 ( V_58 , L_5 , V_59 [ V_53 ] ) ;
F_35 ( V_58 , L_6 ) ;
}
F_35 ( V_58 , L_7 , V_51 -> V_54 ) ;
for ( V_53 = 0 ; V_53 < V_55 ; V_53 ++ )
F_35 ( V_58 , L_8 , F_36 ( & V_51 -> V_56 [ V_53 ] ) ) ;
return 0 ;
}
int F_37 ( struct V_61 * V_62 , struct V_11 * V_63 )
{
T_3 V_53 ;
int V_3 ;
V_3 = F_38 ( & V_62 -> V_64 , & V_63 -> V_65 ) ;
if ( V_3 == 0 ) {
F_32 ( & V_62 -> V_66 , L_9 ) ;
for ( V_53 = 0 ; V_53 < F_39 ( V_62 -> V_67 ) ; ++ V_53 )
F_33 ( & V_62 -> V_67 [ 0 ] , 0 ) ;
F_40 () ;
}
return V_3 ;
}
void F_41 ( struct V_61 * V_62 )
{
F_42 ( & V_62 -> V_64 ) ;
}
int F_43 ( const struct V_61 * V_68 , struct V_57 * V_58 )
{
T_3 V_53 ;
static const char * V_69 [] = {
[ V_70 ] = L_10 ,
[ V_71 ] = L_11 ,
[ V_72 ] = L_12 ,
[ V_73 ] = L_13 ,
[ V_74 ] = L_14
} ;
F_44 ( & V_68 -> V_64 , V_58 ) ;
F_34 ( & V_68 -> V_66 , V_58 , 1 ) ;
F_35 ( V_58 , L_15 ) ;
for ( V_53 = 0 ; V_53 < F_39 ( V_68 -> V_67 ) ; ++ V_53 )
F_35 ( V_58 , L_16 , V_69 [ V_53 ] ,
F_36 ( & V_68 -> V_67 [ V_53 ] ) ) ;
F_35 ( V_58 , L_17 ) ;
F_34 ( & V_75 , V_58 , 0 ) ;
F_35 ( V_58 , L_6 ) ;
return 0 ;
}
static void F_45 ( struct V_76 * V_77 , void * V_78 )
{
F_46 ( V_77 -> V_79 == 0 ) ;
F_46 ( V_77 -> V_80 == & F_45 ) ;
F_46 ( ! V_77 -> V_81 && ! V_77 -> V_82 ) ;
V_77 -> V_79 = 1 ;
V_77 -> V_81 = V_78 ;
F_47 ( V_83 ) ;
}
static unsigned F_48 ( struct V_84 * V_85 ,
const void * V_86 , unsigned V_87 )
{
#if V_88 == 64
return F_49 ( ( V_89 ) V_86 , V_87 ) ;
#else
return F_50 ( ( V_90 ) V_86 , V_87 ) ;
#endif
}
static void * F_51 ( struct V_91 * V_92 )
{
struct V_76 * V_77 = F_52 ( V_92 , struct V_76 , V_93 ) ;
F_46 ( V_77 -> V_80 == & F_45 ) ;
return ( void * ) V_77 ;
}
static int F_53 ( const void * V_86 , struct V_91 * V_92 )
{
struct V_76 * V_77 = F_51 ( V_92 ) ;
F_46 ( V_77 -> V_82 ) ;
return ( V_86 == V_77 -> V_82 ) ;
}
static void F_54 ( struct V_84 * V_94 , struct V_91 * V_92 )
{
struct V_76 * V_77 = F_52 ( V_92 , struct V_76 , V_93 ) ;
F_46 ( V_77 -> V_80 == & F_45 ) ;
}
static inline struct V_76 * F_55 ( void )
{
struct V_76 * V_77 ;
V_77 = F_56 ( V_95 , ( void * ) ( long ) V_96 -> V_97 ) ;
F_46 ( F_57 ( V_77 , V_77 -> V_80 == & F_45 ) ) ;
return V_77 ;
}
static inline void F_58 ( struct V_76 * V_77 )
{
if ( V_77 ) {
int V_98 ;
F_46 ( ! V_77 -> V_82 ) ;
V_77 -> V_82 = ( void * ) ( long ) V_96 -> V_97 ;
V_98 = F_59 ( V_95 , V_77 -> V_82 ,
& V_77 -> V_93 ) ;
F_46 ( V_98 == 0 ) ;
}
}
static inline void F_60 ( struct V_76 * V_77 )
{
void * V_99 ;
F_46 ( V_77 -> V_82 == ( void * ) ( long ) V_96 -> V_97 ) ;
V_99 = F_61 ( V_95 , V_77 -> V_82 ,
& V_77 -> V_93 ) ;
F_46 ( V_99 == V_77 ) ;
V_77 -> V_82 = NULL ;
}
static int F_62 ( void )
{
V_95 = F_63 ( L_18 ,
V_100 , V_100 ,
V_101 , 0 ,
V_102 ,
V_103 ,
& V_104 ,
V_105 ) ;
return V_95 ? 0 : - V_106 ;
}
static void F_64 ( void )
{
F_65 ( V_95 ) ;
}
static inline struct V_76 * F_66 ( struct V_76 * V_77 )
{
if ( ! V_77 )
V_77 = F_55 () ;
if ( V_77 && V_77 -> V_82 )
F_60 ( V_77 ) ;
return V_77 ;
}
static struct V_9 * F_67 ( V_90 V_107 , V_90 V_108 , void * V_78 )
{
struct V_9 * V_10 ;
struct V_76 * V_77 ;
V_77 = F_68 ( V_109 , V_110 ) ;
if ( V_77 ) {
int V_98 ;
F_69 ( & V_77 -> V_111 ) ;
V_77 -> V_80 = & F_45 ;
V_10 = & V_77 -> V_112 ;
V_98 = F_70 ( V_10 , V_107 | V_113 ) ;
if ( V_98 == 0 ) {
V_98 = F_71 ( & V_77 -> V_114 ,
V_108 | V_115 ) ;
if ( V_98 == 0 ) {
F_72 ( & V_77 -> V_114 ) ;
V_10 -> V_116 = & V_77 -> V_114 ;
F_45 ( V_77 , V_78 ) ;
} else {
F_73 ( V_10 ) ;
}
}
if ( V_98 != 0 ) {
F_74 ( V_109 , V_77 ) ;
V_10 = F_75 ( V_98 ) ;
} else {
F_47 ( V_117 ) ;
F_47 ( V_118 ) ;
}
} else {
V_10 = F_75 ( - V_106 ) ;
}
return V_10 ;
}
static void F_76 ( struct V_76 * V_77 )
{
F_77 ( V_118 ) ;
F_78 ( & V_77 -> V_112 . V_119 ) ;
F_78 ( & V_77 -> V_114 ) ;
F_74 ( V_109 , V_77 ) ;
}
static struct V_9 * F_79 ( void * V_78 )
{
struct V_76 * V_77 ;
struct V_9 * V_10 ;
F_80 ( & V_120 ) ;
F_46 ( F_81 ( V_121 == 0 , F_82 ( & V_122 ) ) ) ;
if ( V_121 > 0 ) {
int V_98 ;
V_77 = F_83 ( V_122 . V_123 , struct V_76 , V_111 ) ;
F_84 ( & V_77 -> V_111 ) ;
V_121 -- ;
F_85 ( & V_120 ) ;
V_10 = & V_77 -> V_112 ;
V_98 = F_86 ( V_10 ) ;
if ( V_98 == 0 ) {
F_45 ( V_77 , V_78 ) ;
F_72 ( & V_10 -> V_119 ) ;
F_72 ( & V_77 -> V_114 ) ;
} else {
F_76 ( V_77 ) ;
V_10 = F_75 ( V_98 ) ;
}
} else {
F_85 ( & V_120 ) ;
V_10 = F_67 ( V_124 ,
V_125 , V_78 ) ;
}
return V_10 ;
}
static inline struct V_76 * F_87 ( struct V_9 * V_10 )
{
return F_83 ( V_10 , struct V_76 , V_112 ) ;
}
static struct V_9 * F_88 ( int * V_126 )
{
struct V_9 * V_10 ;
struct V_76 * V_77 ;
F_47 ( V_127 ) ;
F_89 ( F_90 ( struct V_76 , V_80 ) == 0 ) ;
V_10 = NULL ;
V_77 = F_55 () ;
if ( V_77 ) {
F_47 ( V_128 ) ;
V_10 = & V_77 -> V_112 ;
* V_126 = ++ V_77 -> V_79 ;
}
F_16 ( V_129 , L_19 , V_77 ? V_77 -> V_79 : 0 , V_77 ) ;
return V_10 ;
}
struct V_9 * F_91 ( int * V_126 )
{
struct V_9 * V_10 ;
V_10 = F_88 ( V_126 ) ;
if ( ! V_10 ) {
V_10 = F_79 ( F_92 ( 0 ) ) ;
if ( ! F_93 ( V_10 ) ) {
struct V_76 * V_77 ;
V_77 = F_87 ( V_10 ) ;
F_58 ( V_77 ) ;
* V_126 = V_77 -> V_79 ;
F_16 ( V_129 , L_19 , V_77 -> V_79 , V_77 ) ;
}
}
return V_10 ;
}
struct V_9 * F_94 ( int * V_126 , V_90 V_130 )
{
struct V_9 * V_10 ;
F_46 ( ! F_88 ( V_126 ) ) ;
V_10 = F_67 ( V_130 , V_130 , F_92 ( 0 ) ) ;
if ( ! F_93 ( V_10 ) ) {
struct V_76 * V_77 ;
V_77 = F_87 ( V_10 ) ;
* V_126 = V_77 -> V_79 ;
F_16 ( V_129 , L_19 , V_77 -> V_79 , V_77 ) ;
}
return V_10 ;
}
static void F_95 ( struct V_76 * V_77 )
{
F_46 ( ! V_77 -> V_82 ) ;
F_96 ( & V_77 -> V_112 . V_119 ) ;
F_96 ( & V_77 -> V_114 ) ;
}
unsigned int F_97 ( unsigned int V_131 )
{
struct V_76 * V_77 ;
F_80 ( & V_120 ) ;
for (; ! F_82 ( & V_122 ) && V_131 > 0 ; -- V_131 ) {
V_77 = F_83 ( V_122 . V_123 , struct V_76 , V_111 ) ;
F_84 ( & V_77 -> V_111 ) ;
F_46 ( V_121 > 0 ) ;
V_121 -- ;
F_85 ( & V_120 ) ;
F_76 ( V_77 ) ;
F_80 ( & V_120 ) ;
}
F_46 ( F_81 ( V_121 == 0 , F_82 ( & V_122 ) ) ) ;
F_85 ( & V_120 ) ;
return V_131 ;
}
void F_98 ( struct V_9 * V_10 , int * V_126 )
{
struct V_76 * V_77 ;
V_77 = F_87 ( V_10 ) ;
F_46 ( V_77 -> V_79 > 0 ) ;
F_46 ( F_57 ( V_126 , V_77 -> V_79 == * V_126 ) ) ;
F_16 ( V_129 , L_19 , V_77 -> V_79 , V_77 ) ;
if ( -- V_77 -> V_79 == 0 ) {
F_77 ( V_83 ) ;
F_66 ( V_77 ) ;
V_77 -> V_81 = NULL ;
F_95 ( V_77 ) ;
if ( V_121 < V_132 &&
( V_10 -> V_119 . V_133 & ~ V_134 ) == V_113 &&
( V_10 -> V_116 -> V_133 & ~ V_134 ) == V_115 ) {
F_80 ( & V_120 ) ;
F_99 ( & V_77 -> V_111 , & V_122 ) ;
V_121 ++ ;
F_85 ( & V_120 ) ;
} else {
F_76 ( V_77 ) ;
}
}
}
void * F_100 ( void )
{
return F_66 ( NULL ) ;
}
void F_101 ( void * V_99 )
{
F_66 ( NULL ) ;
F_58 ( V_99 ) ;
}
void F_102 ( struct V_9 * V_10 , int * V_126 )
{
struct V_76 * V_77 = F_87 ( V_10 ) ;
F_46 ( V_77 -> V_79 > 0 ) ;
F_58 ( V_77 ) ;
F_91 ( V_126 ) ;
F_16 ( V_129 , L_19 , V_77 -> V_79 , V_77 ) ;
}
void F_103 ( struct V_9 * V_10 , int * V_126 )
{
struct V_76 * V_77 = F_87 ( V_10 ) ;
F_46 ( V_77 -> V_79 > 1 ) ;
F_16 ( V_129 , L_19 , V_77 -> V_79 , V_77 ) ;
F_66 ( V_77 ) ;
F_98 ( V_10 , V_126 ) ;
}
struct V_9 * F_104 ( struct V_135 * V_136 )
{
struct V_9 * V_10 ;
V_136 -> V_137 = NULL ;
V_10 = F_88 ( & V_136 -> V_138 ) ;
if ( V_10 ) {
if ( ! F_105 ( V_10 ) )
return V_10 ;
F_98 ( V_10 , & V_136 -> V_138 ) ;
V_136 -> V_137 = F_100 () ;
}
V_10 = F_91 ( & V_136 -> V_138 ) ;
if ( F_93 ( V_10 ) ) {
F_101 ( V_136 -> V_137 ) ;
return V_10 ;
}
F_46 ( ! F_105 ( V_10 ) ) ;
return V_10 ;
}
void F_106 ( struct V_135 * V_136 , struct V_9 * V_10 )
{
F_98 ( V_10 , & V_136 -> V_138 ) ;
F_101 ( V_136 -> V_137 ) ;
}
void F_107 ( struct V_25 * V_26 , const struct V_33 * V_34 )
{
V_26 -> V_139 = V_34 -> V_37 ;
V_26 -> V_140 = V_34 -> V_38 ;
V_26 -> V_141 = V_34 -> V_39 ;
V_26 -> V_142 = V_34 -> V_40 ;
V_26 -> V_143 = V_34 -> V_41 ;
}
static int F_108 ( void )
{
struct V_76 * V_77 ;
int V_130 = V_144 | V_145 ;
int V_53 , V_146 ;
int V_98 = 0 ;
F_109 (i) {
struct V_9 * V_10 ;
V_77 = & V_147 [ V_53 ] ;
V_10 = & V_77 -> V_112 ;
F_69 ( & V_77 -> V_111 ) ;
V_77 -> V_80 = & F_45 ;
V_98 = F_70 ( V_10 , V_113 | V_130 ) ;
if ( V_98 == 0 ) {
V_98 = F_71 ( & V_77 -> V_114 , V_115 | V_130 ) ;
if ( V_98 == 0 ) {
F_72 ( & V_77 -> V_114 ) ;
V_10 -> V_116 = & V_77 -> V_114 ;
} else {
F_73 ( V_10 ) ;
}
}
if ( V_98 != 0 )
break;
}
if ( V_98 != 0 ) {
for ( V_146 = 0 ; V_146 < V_53 ; V_146 ++ ) {
V_77 = & V_147 [ V_146 ] ;
F_96 ( & V_77 -> V_114 ) ;
F_78 ( & V_77 -> V_114 ) ;
F_73 ( & V_77 -> V_112 ) ;
}
}
return V_98 ;
}
static void F_110 ( void )
{
int V_53 ;
F_109 (i) {
struct V_76 * V_77 = & V_147 [ V_53 ] ;
F_96 ( & V_77 -> V_114 ) ;
F_78 ( & V_77 -> V_114 ) ;
F_73 ( & V_77 -> V_112 ) ;
}
}
static void F_40 ( void )
{
int V_53 ;
F_109 (i)
F_86 ( & V_147 [ V_53 ] . V_112 ) ;
}
void F_111 ( struct V_9 * V_10 )
{
struct V_76 * V_77 ;
int V_148 ;
V_148 = F_112 () ;
V_77 = F_87 ( V_10 ) ;
F_46 ( V_77 == & V_147 [ V_148 ] ) ;
V_77 -> V_79 -- ;
F_46 ( V_77 -> V_79 == 0 ) ;
F_77 ( V_83 ) ;
F_66 ( V_77 ) ;
V_77 -> V_81 = NULL ;
F_113 () ;
}
struct V_9 * F_114 ( void )
{
struct V_76 * V_77 ;
V_77 = & V_147 [ F_115 () ] ;
F_45 ( V_77 , F_92 ( 0 ) ) ;
F_58 ( V_77 ) ;
return & V_77 -> V_112 ;
}
struct V_11 * F_116 ( const struct V_9 * V_10 , struct V_149 * V_68 ,
struct V_150 * V_151 ,
struct V_152 * V_123 )
{
const char * V_153 ;
struct V_152 * V_63 ;
V_153 = V_151 -> V_154 ;
V_63 = V_151 -> V_155 -> V_156 ( V_10 , V_151 , NULL ) ;
if ( ! F_93 ( V_63 ) ) {
int V_98 ;
if ( V_68 )
V_63 -> V_157 = V_68 ;
V_98 = V_151 -> V_155 -> V_158 ( V_10 , V_63 , V_153 , V_123 ) ;
if ( V_98 == 0 ) {
F_117 ( V_63 ) ;
F_118 ( & V_63 -> V_159 ,
L_20 , & F_38 ) ;
} else {
V_151 -> V_155 -> V_160 ( V_10 , V_63 ) ;
F_119 ( L_21 , V_153 , V_98 ) ;
V_63 = F_75 ( V_98 ) ;
}
} else {
F_119 ( L_22 , V_153 ) ;
}
return F_120 ( V_63 ) ;
}
void F_121 ( const struct V_9 * V_10 , struct V_11 * V_161 )
{
F_122 ( V_10 , F_9 ( V_161 ) ) ;
}
struct V_162 * F_123 ( const struct V_9 * V_10 )
{
return F_124 ( & V_10 -> V_119 , & V_163 ) ;
}
static void * F_125 ( const struct V_164 * V_165 ,
struct V_166 * V_86 )
{
struct V_162 * V_167 ;
V_167 = F_126 ( V_165 , V_86 ) ;
if ( ! F_93 ( V_167 ) ) {
T_3 V_53 ;
for ( V_53 = 0 ; V_53 < F_39 ( V_167 -> V_168 ) ; ++ V_53 )
F_127 ( & V_167 -> V_168 [ V_53 ] . V_169 ) ;
}
return V_167 ;
}
static void F_128 ( const struct V_164 * V_165 ,
struct V_166 * V_86 , void * V_170 )
{
struct V_162 * V_167 ;
T_3 V_53 ;
V_167 = V_170 ;
for ( V_53 = 0 ; V_53 < F_39 ( V_167 -> V_168 ) ; ++ V_53 )
F_129 ( & V_167 -> V_168 [ V_53 ] . V_169 ) ;
F_130 ( V_165 , V_86 , V_170 ) ;
}
static void F_131 ( const struct V_164 * V_165 ,
struct V_166 * V_86 , void * V_170 )
{
struct V_162 * V_167 = V_170 ;
T_3 V_53 ;
for ( V_53 = 0 ; V_53 < F_39 ( V_167 -> V_168 ) ; ++ V_53 ) {
F_46 ( V_167 -> V_168 [ V_53 ] . V_171 == 0 ) ;
F_46 ( V_167 -> V_168 [ V_53 ] . V_172 == 0 ) ;
F_46 ( V_167 -> V_168 [ V_53 ] . V_173 == 0 ) ;
F_46 ( V_167 -> V_168 [ V_53 ] . V_174 == 0 ) ;
F_129 ( & V_167 -> V_168 [ V_53 ] . V_169 ) ;
F_127 ( & V_167 -> V_168 [ V_53 ] . V_169 ) ;
}
}
int F_132 ( void )
{
int V_3 ;
V_3 = F_62 () ;
if ( V_3 )
return V_3 ;
V_3 = F_133 ( V_175 ) ;
if ( V_3 )
goto V_176;
F_134 ( & V_163 ) ;
V_3 = F_135 ( & V_163 ) ;
if ( V_3 )
goto V_177;
V_3 = F_108 () ;
if ( V_3 )
goto V_178;
return 0 ;
V_178:
F_136 ( & V_163 ) ;
V_177:
F_137 ( V_175 ) ;
V_176:
F_64 () ;
return V_3 ;
}
void F_138 ( void )
{
F_110 () ;
F_136 ( & V_163 ) ;
F_137 ( V_175 ) ;
F_64 () ;
}
