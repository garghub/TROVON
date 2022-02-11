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
int F_30 ( const struct V_9 * V_10 , struct V_8 * V_24 ,
struct V_48 * V_49 ,
struct V_50 * V_50 , T_3 * V_51 )
{
struct V_27 * V_21 ;
int V_3 = 0 ;
V_21 = V_24 -> V_19 . V_28 ;
F_22 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_24 -> V_29 -> V_52 ) {
V_3 = V_24 -> V_29 -> V_52 ( V_10 , V_24 , V_49 , V_50 ,
V_51 ) ;
if ( V_3 )
break;
}
}
return V_3 ;
}
int F_31 ( const struct V_9 * V_10 , struct V_8 * V_24 ,
struct V_53 * V_54 )
{
struct V_27 * V_21 = V_24 -> V_19 . V_28 ;
F_22 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_24 -> V_29 -> V_55 )
return V_24 -> V_29 -> V_55 ( V_10 , V_24 , V_54 ) ;
}
return - V_56 ;
}
T_4 F_32 ( struct V_8 * V_24 )
{
struct V_27 * V_21 = V_24 -> V_19 . V_28 ;
T_4 V_57 = V_58 ;
F_22 (obj, &top->loh_layers, co_lu.lo_linkage) {
if ( V_24 -> V_29 -> V_59 )
V_57 = F_33 ( T_4 , V_24 -> V_29 -> V_59 ( V_24 ) ,
V_57 ) ;
}
return V_57 ;
}
void F_34 ( const struct V_9 * V_10 , struct V_8 * V_24 )
{
struct V_1 * V_20 = V_1 ( V_24 ) ;
F_35 ( V_60 , & V_20 -> V_4 . V_61 ) ;
}
void F_36 ( struct V_62 * V_63 , const char * V_64 )
{
int V_65 ;
V_63 -> V_66 = V_64 ;
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ )
F_37 ( & V_63 -> V_68 [ V_65 ] , 0 ) ;
}
static int F_38 ( const struct V_62 * V_63 ,
struct V_69 * V_70 , int V_2 )
{
int V_65 ;
if ( V_2 ) {
const char * V_71 [ V_67 ] = V_72 ;
F_39 ( V_70 , L_3 , L_4 ) ;
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ )
F_39 ( V_70 , L_5 , V_71 [ V_65 ] ) ;
F_39 ( V_70 , L_6 ) ;
}
F_39 ( V_70 , L_7 , V_63 -> V_66 ) ;
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ )
F_39 ( V_70 , L_8 , F_40 ( & V_63 -> V_68 [ V_65 ] ) ) ;
return 0 ;
}
int F_41 ( struct V_73 * V_74 , struct V_11 * V_75 )
{
T_3 V_65 ;
int V_3 ;
V_3 = F_42 ( & V_74 -> V_76 , & V_75 -> V_77 ) ;
if ( V_3 == 0 ) {
F_36 ( & V_74 -> V_78 , L_9 ) ;
for ( V_65 = 0 ; V_65 < F_43 ( V_74 -> V_79 ) ; ++ V_65 )
F_37 ( & V_74 -> V_79 [ 0 ] , 0 ) ;
F_44 () ;
}
return V_3 ;
}
void F_45 ( struct V_73 * V_74 )
{
F_46 ( & V_74 -> V_76 ) ;
}
int F_47 ( const struct V_73 * V_80 , struct V_69 * V_70 )
{
T_3 V_65 ;
static const char * V_81 [] = {
[ V_82 ] = L_10 ,
[ V_83 ] = L_11 ,
[ V_84 ] = L_12 ,
[ V_85 ] = L_13 ,
[ V_86 ] = L_14
} ;
F_48 ( & V_80 -> V_76 , V_70 ) ;
F_38 ( & V_80 -> V_78 , V_70 , 1 ) ;
F_39 ( V_70 , L_15 ) ;
for ( V_65 = 0 ; V_65 < F_43 ( V_80 -> V_79 ) ; ++ V_65 )
F_39 ( V_70 , L_16 , V_81 [ V_65 ] ,
F_40 ( & V_80 -> V_79 [ V_65 ] ) ) ;
F_39 ( V_70 , L_17 ) ;
F_38 ( & V_87 , V_70 , 0 ) ;
F_39 ( V_70 , L_6 ) ;
return 0 ;
}
static void F_49 ( struct V_88 * V_89 , void * V_90 )
{
F_50 ( V_89 -> V_91 == 0 ) ;
F_50 ( V_89 -> V_92 == & F_49 ) ;
F_50 ( ! V_89 -> V_93 ) ;
V_89 -> V_91 = 1 ;
V_89 -> V_93 = V_90 ;
F_51 ( V_94 ) ;
}
static struct V_9 * F_52 ( T_5 V_95 , T_5 V_96 , void * V_90 )
{
struct V_9 * V_10 ;
struct V_88 * V_89 ;
V_89 = F_53 ( V_97 , V_98 ) ;
if ( V_89 ) {
int V_99 ;
F_54 ( & V_89 -> V_100 ) ;
V_89 -> V_92 = & F_49 ;
V_10 = & V_89 -> V_101 ;
V_99 = F_55 ( V_10 , V_95 | V_102 ) ;
if ( V_99 == 0 ) {
V_99 = F_56 ( & V_89 -> V_103 ,
V_96 | V_104 ) ;
if ( V_99 == 0 ) {
F_57 ( & V_89 -> V_103 ) ;
V_10 -> V_105 = & V_89 -> V_103 ;
F_49 ( V_89 , V_90 ) ;
} else {
F_58 ( V_10 ) ;
}
}
if ( V_99 != 0 ) {
F_59 ( V_97 , V_89 ) ;
V_10 = F_60 ( V_99 ) ;
} else {
F_51 ( V_106 ) ;
F_51 ( V_107 ) ;
}
} else {
V_10 = F_60 ( - V_108 ) ;
}
return V_10 ;
}
static void F_61 ( struct V_88 * V_89 )
{
F_62 ( V_107 ) ;
F_63 ( & V_89 -> V_101 . V_109 ) ;
F_63 ( & V_89 -> V_103 ) ;
F_59 ( V_97 , V_89 ) ;
}
static struct V_9 * F_64 ( void * V_90 )
{
struct V_88 * V_89 ;
struct V_9 * V_10 ;
int V_110 = F_65 () ;
F_66 ( & V_111 [ V_110 ] . V_112 ) ;
F_50 ( F_67 ( V_111 [ V_110 ] . V_113 == 0 ,
F_68 ( & V_111 [ V_110 ] . V_114 ) ) ) ;
if ( V_111 [ V_110 ] . V_113 > 0 ) {
int V_99 ;
V_89 = F_69 ( V_111 [ V_110 ] . V_114 . V_115 , struct V_88 ,
V_100 ) ;
F_70 ( & V_89 -> V_100 ) ;
V_111 [ V_110 ] . V_113 -- ;
F_71 ( & V_111 [ V_110 ] . V_112 ) ;
F_72 () ;
V_10 = & V_89 -> V_101 ;
V_99 = F_73 ( V_10 ) ;
if ( V_99 == 0 ) {
F_49 ( V_89 , V_90 ) ;
F_57 ( & V_10 -> V_109 ) ;
F_57 ( & V_89 -> V_103 ) ;
} else {
F_61 ( V_89 ) ;
V_10 = F_60 ( V_99 ) ;
}
} else {
F_71 ( & V_111 [ V_110 ] . V_112 ) ;
F_72 () ;
V_10 = F_52 ( V_116 ,
V_117 , V_90 ) ;
}
return V_10 ;
}
static inline struct V_88 * F_74 ( struct V_9 * V_10 )
{
return F_69 ( V_10 , struct V_88 , V_101 ) ;
}
struct V_9 * F_75 ( T_6 * V_118 )
{
struct V_9 * V_10 ;
V_10 = F_64 ( F_76 ( 0 ) ) ;
if ( ! F_77 ( V_10 ) ) {
struct V_88 * V_89 ;
V_89 = F_74 ( V_10 ) ;
* V_118 = V_89 -> V_91 ;
F_16 ( V_119 , L_18 , V_89 -> V_91 , V_89 ) ;
}
return V_10 ;
}
struct V_9 * F_78 ( T_6 * V_118 , T_7 V_120 )
{
struct V_9 * V_10 ;
V_10 = F_52 ( V_120 , V_120 , F_76 ( 0 ) ) ;
if ( ! F_77 ( V_10 ) ) {
struct V_88 * V_89 ;
V_89 = F_74 ( V_10 ) ;
* V_118 = V_89 -> V_91 ;
F_16 ( V_119 , L_18 , V_89 -> V_91 , V_89 ) ;
}
return V_10 ;
}
static void F_79 ( struct V_88 * V_89 )
{
F_80 ( & V_89 -> V_101 . V_109 ) ;
F_80 ( & V_89 -> V_103 ) ;
}
unsigned int F_81 ( unsigned int V_121 )
{
struct V_88 * V_89 ;
unsigned int V_65 ;
F_82 (i) {
F_83 ( & V_111 [ V_65 ] . V_112 ) ;
for (; ! F_68 ( & V_111 [ V_65 ] . V_114 ) && V_121 > 0 ; -- V_121 ) {
V_89 = F_69 ( V_111 [ V_65 ] . V_114 . V_115 ,
struct V_88 , V_100 ) ;
F_70 ( & V_89 -> V_100 ) ;
F_50 ( V_111 [ V_65 ] . V_113 > 0 ) ;
V_111 [ V_65 ] . V_113 -- ;
F_84 ( & V_111 [ V_65 ] . V_112 ) ;
F_61 ( V_89 ) ;
F_83 ( & V_111 [ V_65 ] . V_112 ) ;
}
F_50 ( F_67 ( V_111 [ V_65 ] . V_113 == 0 ,
F_68 ( & V_111 [ V_65 ] . V_114 ) ) ) ;
F_84 ( & V_111 [ V_65 ] . V_112 ) ;
}
return V_121 ;
}
void F_85 ( struct V_9 * V_10 , T_6 * V_118 )
{
struct V_88 * V_89 ;
V_89 = F_74 ( V_10 ) ;
F_50 ( V_89 -> V_91 > 0 ) ;
F_50 ( F_86 ( V_118 , V_89 -> V_91 == * V_118 ) ) ;
F_16 ( V_119 , L_18 , V_89 -> V_91 , V_89 ) ;
if ( -- V_89 -> V_91 == 0 ) {
int V_110 = F_65 () ;
F_62 ( V_94 ) ;
V_89 -> V_93 = NULL ;
F_79 ( V_89 ) ;
if ( V_111 [ V_110 ] . V_113 < V_122 &&
( V_10 -> V_109 . V_123 & ~ V_124 ) == V_102 &&
( V_10 -> V_105 -> V_123 & ~ V_124 ) == V_104 ) {
F_66 ( & V_111 [ V_110 ] . V_112 ) ;
F_87 ( & V_89 -> V_100 , & V_111 [ V_110 ] . V_114 ) ;
V_111 [ V_110 ] . V_113 ++ ;
F_71 ( & V_111 [ V_110 ] . V_112 ) ;
} else {
F_61 ( V_89 ) ;
}
F_72 () ;
}
}
void F_88 ( struct V_25 * V_26 , const struct V_33 * V_34 )
{
V_26 -> V_125 = V_34 -> V_37 ;
V_26 -> V_126 = V_34 -> V_38 ;
V_26 -> V_127 = V_34 -> V_39 ;
V_26 -> V_128 = V_34 -> V_40 ;
V_26 -> V_129 = V_34 -> V_41 ;
}
static int F_89 ( void )
{
struct V_88 * V_89 ;
int V_120 = V_130 | V_131 ;
int V_65 , V_132 ;
int V_99 = 0 ;
F_82 (i) {
struct V_9 * V_10 ;
F_90 ( & V_111 [ V_65 ] . V_112 ) ;
F_54 ( & V_111 [ V_65 ] . V_114 ) ;
V_111 [ V_65 ] . V_113 = 0 ;
V_89 = & V_133 [ V_65 ] ;
V_10 = & V_89 -> V_101 ;
F_54 ( & V_89 -> V_100 ) ;
V_89 -> V_92 = & F_49 ;
V_99 = F_55 ( V_10 , V_102 | V_120 ) ;
if ( V_99 == 0 ) {
V_99 = F_56 ( & V_89 -> V_103 , V_104 | V_120 ) ;
if ( V_99 == 0 ) {
F_57 ( & V_89 -> V_103 ) ;
V_10 -> V_105 = & V_89 -> V_103 ;
} else {
F_58 ( V_10 ) ;
}
}
if ( V_99 != 0 )
break;
}
if ( V_99 != 0 ) {
for ( V_132 = 0 ; V_132 < V_65 ; V_132 ++ ) {
V_89 = & V_133 [ V_132 ] ;
F_80 ( & V_89 -> V_103 ) ;
F_63 ( & V_89 -> V_103 ) ;
F_58 ( & V_89 -> V_101 ) ;
}
}
return V_99 ;
}
static void F_91 ( void )
{
int V_65 ;
F_82 (i) {
struct V_88 * V_89 = & V_133 [ V_65 ] ;
F_80 ( & V_89 -> V_103 ) ;
F_63 ( & V_89 -> V_103 ) ;
F_58 ( & V_89 -> V_101 ) ;
}
}
static void F_44 ( void )
{
int V_65 ;
F_82 (i)
F_73 ( & V_133 [ V_65 ] . V_101 ) ;
}
void F_92 ( struct V_9 * V_10 )
{
struct V_88 * V_89 ;
int V_110 ;
V_110 = F_93 () ;
V_89 = F_74 ( V_10 ) ;
F_50 ( V_89 == & V_133 [ V_110 ] ) ;
V_89 -> V_91 -- ;
F_50 ( V_89 -> V_91 == 0 ) ;
F_62 ( V_94 ) ;
V_89 -> V_93 = NULL ;
F_72 () ;
}
struct V_9 * F_94 ( void )
{
struct V_88 * V_89 ;
V_89 = & V_133 [ F_65 () ] ;
F_49 ( V_89 , F_76 ( 0 ) ) ;
return & V_89 -> V_101 ;
}
struct V_11 * F_95 ( const struct V_9 * V_10 , struct V_134 * V_80 ,
struct V_135 * V_136 ,
struct V_137 * V_115 )
{
const char * V_138 ;
struct V_137 * V_75 ;
V_138 = V_136 -> V_139 ;
V_75 = V_136 -> V_140 -> V_141 ( V_10 , V_136 , NULL ) ;
if ( ! F_77 ( V_75 ) ) {
int V_99 ;
if ( V_80 )
V_75 -> V_142 = V_80 ;
V_99 = V_136 -> V_140 -> V_143 ( V_10 , V_75 , V_138 , V_115 ) ;
if ( V_99 == 0 ) {
F_96 ( V_75 ) ;
F_97 ( & V_75 -> V_144 ,
L_19 , & F_42 ) ;
} else {
V_136 -> V_140 -> V_145 ( V_10 , V_75 ) ;
F_98 ( L_20 , V_138 , V_99 ) ;
V_75 = F_60 ( V_99 ) ;
}
} else {
F_98 ( L_21 , V_138 ) ;
}
return F_99 ( V_75 ) ;
}
void F_100 ( const struct V_9 * V_10 , struct V_11 * V_54 )
{
F_101 ( V_10 , F_9 ( V_54 ) ) ;
}
struct V_146 * F_102 ( const struct V_9 * V_10 )
{
return F_103 ( & V_10 -> V_109 , & V_147 ) ;
}
static void * F_104 ( const struct V_148 * V_149 ,
struct V_150 * V_49 )
{
return F_105 ( V_149 , V_49 ) ;
}
static void F_106 ( const struct V_148 * V_149 ,
struct V_150 * V_49 , void * V_151 )
{
F_107 ( V_149 , V_49 , V_151 ) ;
}
int F_108 ( void )
{
int V_3 ;
V_111 = F_109 ( sizeof( * V_111 ) * F_110 () , V_152 ) ;
if ( ! V_111 ) {
V_3 = - V_108 ;
goto V_153;
}
V_3 = F_111 ( V_154 ) ;
if ( V_3 )
goto V_155;
F_112 ( & V_147 ) ;
V_3 = F_113 ( & V_147 ) ;
if ( V_3 )
goto V_156;
V_3 = F_89 () ;
if ( V_3 )
goto V_157;
return 0 ;
V_157:
F_114 ( & V_147 ) ;
V_156:
F_115 ( V_154 ) ;
V_155:
F_116 ( V_111 ) ;
V_153:
return V_3 ;
}
void F_117 ( void )
{
F_91 () ;
F_114 ( & V_147 ) ;
F_115 ( V_154 ) ;
F_116 ( V_111 ) ;
}
