void F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_3 * V_11 ;
T_1 V_12 ;
const struct V_13 * V_14 ;
V_8 = V_4 -> V_15 ;
V_10 = V_4 -> V_16 -> V_17 ;
V_11 = V_4 ;
V_14 = F_2 ( V_4 ) ;
if ( F_3 ( V_14 ) ) {
F_4 ( V_8 -> V_18 . V_19 == NULL
&& V_8 -> V_18 . V_20 == NULL ) ;
F_4 ( F_5 ( & V_8 -> V_21 ) ) ;
if ( ! F_6 ( & V_8 -> V_22 ) )
return;
F_7 (o, &top->loh_layers, lo_linkage) {
if ( V_4 -> V_23 -> V_24 != NULL )
V_4 -> V_23 -> V_24 ( V_2 , V_4 ) ;
}
F_8 ( V_2 , V_11 ) ;
return;
}
F_9 ( V_10 -> V_25 , & V_8 -> V_26 , & V_12 ) ;
V_6 = F_10 ( V_10 -> V_25 , & V_12 ) ;
if ( ! F_11 ( V_10 -> V_25 , & V_12 , & V_8 -> V_22 ) ) {
if ( F_12 ( V_8 ) ) {
F_13 ( & V_6 -> V_27 ) ;
}
return;
}
F_4 ( V_6 -> V_28 > 0 ) ;
V_6 -> V_28 -- ;
F_7 (o, &top->loh_layers, lo_linkage) {
if ( V_4 -> V_23 -> V_24 != NULL )
V_4 -> V_23 -> V_24 ( V_2 , V_4 ) ;
}
if ( ! F_12 ( V_8 ) ) {
F_4 ( F_5 ( & V_8 -> V_21 ) ) ;
F_14 ( & V_8 -> V_21 , & V_6 -> V_29 ) ;
F_15 ( V_10 -> V_25 , & V_12 , 1 ) ;
return;
}
if ( ! F_16 ( V_30 , & V_8 -> V_31 ) )
F_17 ( V_10 -> V_25 , & V_12 , & V_8 -> V_18 ) ;
F_15 ( V_10 -> V_25 , & V_12 , 1 ) ;
F_8 ( V_2 , V_11 ) ;
}
void F_18 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_19 ( V_32 , & V_4 -> V_15 -> V_31 ) ;
return F_1 ( V_2 , V_4 ) ;
}
void F_20 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = V_4 -> V_15 ;
F_19 ( V_32 , & V_8 -> V_31 ) ;
if ( ! F_16 ( V_30 , & V_8 -> V_31 ) ) {
T_2 * V_33 = V_4 -> V_16 -> V_17 -> V_25 ;
T_1 V_12 ;
F_21 ( V_33 , & V_8 -> V_26 , & V_12 , 1 ) ;
F_22 ( & V_8 -> V_21 ) ;
F_17 ( V_33 , & V_12 , & V_8 -> V_18 ) ;
F_15 ( V_33 , & V_12 , 1 ) ;
}
}
static struct V_3 * F_23 ( const struct V_1 * V_2 ,
struct V_34 * V_35 ,
const struct V_13 * V_36 ,
const struct V_37 * V_38 )
{
struct V_3 * V_39 ;
struct V_3 * V_8 ;
struct V_40 * V_41 ;
int V_42 ;
int V_43 ;
V_44 ;
V_8 = V_35 -> V_45 -> V_46 ( V_2 , NULL , V_35 ) ;
if ( V_8 == NULL )
RETURN ( F_24 ( - V_47 ) ) ;
if ( F_25 ( V_8 ) )
RETURN ( V_8 ) ;
V_8 -> V_15 -> V_26 = * V_36 ;
V_41 = & V_8 -> V_15 -> V_48 ;
do {
V_42 = 1 ;
F_26 (scan, layers, lo_linkage) {
if ( V_39 -> V_49 & V_50 )
continue;
V_42 = 0 ;
V_39 -> V_15 = V_8 -> V_15 ;
V_43 = V_39 -> V_23 -> V_51 ( V_2 , V_39 , V_38 ) ;
if ( V_43 != 0 ) {
F_8 ( V_2 , V_8 ) ;
RETURN ( F_24 ( V_43 ) ) ;
}
V_39 -> V_49 |= V_50 ;
}
} while ( ! V_42 );
F_7 (scan, layers, lo_linkage) {
if ( V_39 -> V_23 -> V_52 != NULL ) {
V_43 = V_39 -> V_23 -> V_52 ( V_2 , V_39 ) ;
if ( V_43 != 0 ) {
F_8 ( V_2 , V_8 ) ;
RETURN ( F_24 ( V_43 ) ) ;
}
}
}
F_27 ( V_35 -> V_17 -> V_53 , V_54 ) ;
RETURN ( V_8 ) ;
}
static void F_8 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_3 * V_39 ;
struct V_40 * V_41 ;
struct V_40 V_55 ;
V_10 = V_4 -> V_16 -> V_17 ;
V_41 = & V_4 -> V_15 -> V_48 ;
V_6 = F_28 ( V_10 , & V_4 -> V_15 -> V_26 ) ;
F_7 (scan, layers, lo_linkage) {
if ( V_39 -> V_23 -> V_56 != NULL )
V_39 -> V_23 -> V_56 ( V_2 , V_39 ) ;
}
F_29 ( & V_55 ) ;
F_30 ( V_41 , & V_55 ) ;
while ( ! F_5 ( & V_55 ) ) {
V_4 = F_31 ( V_55 . V_57 , struct V_3 , V_58 ) ;
F_22 ( & V_4 -> V_58 ) ;
F_4 ( V_4 -> V_23 -> V_59 != NULL ) ;
V_4 -> V_23 -> V_59 ( V_2 , V_4 ) ;
}
if ( F_32 ( & V_6 -> V_27 ) )
F_13 ( & V_6 -> V_27 ) ;
}
int F_33 ( const struct V_1 * V_2 , struct V_9 * V_60 , int V_61 )
{
struct V_7 * V_62 ;
struct V_7 * V_63 ;
struct V_5 * V_6 ;
T_1 V_12 ;
T_1 V_64 ;
struct V_40 V_65 ;
int V_66 ;
int V_67 ;
int V_68 ;
int V_69 ;
int V_70 ;
if ( F_34 ( V_71 ) )
RETURN ( 0 ) ;
F_29 ( & V_65 ) ;
V_67 = V_60 -> V_72 ;
V_69 = ( V_61 == ~ 0 ) ? - 1 : V_61 / F_35 ( V_60 -> V_25 ) + 1 ;
V_73:
V_66 = 0 ;
F_36 (s->ls_obj_hash, &bd, i) {
if ( V_70 < V_67 )
continue;
V_68 = V_69 ;
F_37 ( V_60 -> V_25 , & V_12 , 1 ) ;
V_6 = F_10 ( V_60 -> V_25 , & V_12 ) ;
F_38 (h, temp, &bkt->lsb_lru, loh_lru) {
F_4 ( F_39 ( & V_62 -> V_22 ) == 0 ) ;
F_9 ( V_60 -> V_25 , & V_62 -> V_26 , & V_64 ) ;
F_4 ( V_12 . V_74 == V_64 . V_74 ) ;
F_17 ( V_60 -> V_25 ,
& V_64 , & V_62 -> V_18 ) ;
F_40 ( & V_62 -> V_21 , & V_65 ) ;
if ( V_66 == 0 )
V_66 = 1 ;
if ( V_61 != ~ 0 && -- V_61 == 0 )
break;
if ( V_68 > 0 && -- V_68 == 0 )
break;
}
F_15 ( V_60 -> V_25 , & V_12 , 1 ) ;
F_41 () ;
while ( ! F_5 ( & V_65 ) ) {
V_62 = F_31 ( V_65 . V_19 ,
struct V_7 , V_21 ) ;
F_22 ( & V_62 -> V_21 ) ;
F_8 ( V_2 , F_42 ( V_62 ) ) ;
F_27 ( V_60 -> V_53 , V_75 ) ;
}
if ( V_61 == 0 )
break;
}
if ( V_61 != 0 && V_66 && V_67 != 0 ) {
V_67 = 0 ;
goto V_73;
}
V_60 -> V_72 = V_70 % F_35 ( V_60 -> V_25 ) ;
return V_61 ;
}
int F_43 ( const struct V_1 * V_2 ,
void * V_76 , const char * V_77 , ... )
{
struct V_78 * V_79 = V_76 ;
struct V_80 * V_81 ;
int V_82 ;
int V_83 ;
T_3 args ;
va_start ( args , V_77 ) ;
V_81 = F_44 ( & V_2 -> V_84 , & V_85 ) ;
F_4 ( V_81 != NULL ) ;
V_82 = strlen ( V_81 -> V_86 ) ;
V_83 = V_77 [ strlen ( V_77 ) - 1 ] == '\n' ;
vsnprintf ( V_81 -> V_86 + V_82 ,
F_45 ( V_81 -> V_86 ) - V_82 , V_77 , args ) ;
if ( V_83 ) {
if ( F_46 ( V_79 -> V_87 , V_79 -> V_88 ) )
F_47 ( V_79 , L_1 , V_81 -> V_86 ) ;
V_81 -> V_86 [ 0 ] = 0 ;
}
va_end ( args ) ;
return 0 ;
}
void F_48 ( const struct V_1 * V_2 , void * V_76 ,
T_4 V_89 ,
const struct V_7 * V_90 )
{
(* V_89)( V_2 , V_76 , L_2 V_91 L_3 ,
V_90 , V_90 -> V_31 , F_39 ( & V_90 -> V_22 ) ,
F_49 ( & V_90 -> V_26 ) ,
F_50 ( & V_90 -> V_18 ) ? L_4 : L_5 ,
F_5 ( (struct V_40 * ) & V_90 -> V_21 ) ? \
L_4 : L_6 ,
V_90 -> V_92 & V_93 ? L_7 : L_4 ) ;
}
void F_51 ( const struct V_1 * V_2 , void * V_76 ,
T_4 V_89 , const struct V_3 * V_4 )
{
static const char V_94 [] = L_8 ;
struct V_7 * V_8 ;
int V_95 ;
V_8 = V_4 -> V_15 ;
F_48 ( V_2 , V_76 , V_89 , V_8 ) ;
(* V_89)( V_2 , V_76 , L_9 ) ;
F_26 (o, &top->loh_layers, lo_linkage) {
V_95 = V_4 -> V_96 + 4 ;
(* V_89)( V_2 , V_76 , L_10 , V_95 , V_95 , V_94 ,
V_4 -> V_16 -> V_97 -> V_98 , V_4 ) ;
if ( V_4 -> V_23 -> V_99 != NULL )
V_4 -> V_23 -> V_99 ( V_2 , V_76 , V_89 , V_4 ) ;
(* V_89)( V_2 , V_76 , L_11 ) ;
}
(* V_89)( V_2 , V_76 , L_12 , V_8 ) ;
}
int F_52 ( const struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = V_4 -> V_15 ;
F_26 (o, &top->loh_layers, lo_linkage) {
if ( V_4 -> V_23 -> V_100 != NULL &&
! V_4 -> V_23 -> V_100 ( V_4 ) )
return 0 ;
}
return 1 ;
}
static struct V_3 * F_53 ( struct V_9 * V_60 ,
T_1 * V_12 ,
const struct V_13 * V_36 ,
T_5 * V_101 ,
T_6 * V_102 )
{
struct V_5 * V_6 ;
struct V_7 * V_62 ;
struct V_103 * V_104 ;
T_6 V_105 = F_54 ( V_12 ) ;
if ( * V_102 == V_105 )
return NULL ;
* V_102 = V_105 ;
V_6 = F_10 ( V_60 -> V_25 , V_12 ) ;
V_104 = F_55 ( V_60 -> V_25 , V_12 , ( void * ) V_36 ) ;
if ( V_104 == NULL ) {
F_27 ( V_60 -> V_53 , V_106 ) ;
return NULL ;
}
V_62 = F_31 ( V_104 , struct V_7 , V_18 ) ;
if ( F_56 ( ! F_12 ( V_62 ) ) ) {
F_57 ( V_60 -> V_25 , V_104 ) ;
F_27 ( V_60 -> V_53 , V_107 ) ;
F_22 ( & V_62 -> V_21 ) ;
return F_42 ( V_62 ) ;
}
F_58 ( V_101 ) ;
F_59 ( & V_6 -> V_27 , V_101 ) ;
F_60 ( V_108 ) ;
F_27 ( V_60 -> V_53 , V_109 ) ;
return F_24 ( - V_110 ) ;
}
struct V_3 * F_61 ( const struct V_1 * V_2 ,
struct V_34 * V_35 , const struct V_13 * V_36 ,
const struct V_37 * V_38 )
{
return F_62 ( V_2 , V_35 -> V_17 -> V_111 , V_36 , V_38 ) ;
}
static struct V_3 * F_63 ( const struct V_1 * V_2 ,
struct V_34 * V_35 ,
const struct V_13 * V_36 ,
const struct V_37 * V_38 )
{
struct V_3 * V_4 ;
T_2 * V_112 ;
T_1 V_12 ;
struct V_5 * V_6 ;
V_4 = F_23 ( V_2 , V_35 , V_36 , V_38 ) ;
if ( F_64 ( F_25 ( V_4 ) ) )
return V_4 ;
V_112 = V_35 -> V_17 -> V_25 ;
F_21 ( V_112 , ( void * ) V_36 , & V_12 , 1 ) ;
V_6 = F_10 ( V_112 , & V_12 ) ;
F_65 ( V_112 , & V_12 , & V_4 -> V_15 -> V_18 ) ;
V_6 -> V_28 ++ ;
F_15 ( V_112 , & V_12 , 1 ) ;
return V_4 ;
}
static struct V_3 * F_66 ( const struct V_1 * V_2 ,
struct V_34 * V_35 ,
const struct V_13 * V_36 ,
const struct V_37 * V_38 ,
T_5 * V_101 )
{
struct V_3 * V_4 ;
struct V_3 * V_113 ;
struct V_9 * V_60 ;
T_2 * V_112 ;
T_1 V_12 ;
T_6 V_102 = 0 ;
if ( V_38 != NULL && V_38 -> V_114 & V_115 )
return F_63 ( V_2 , V_35 , V_36 , V_38 ) ;
V_60 = V_35 -> V_17 ;
V_112 = V_60 -> V_25 ;
F_21 ( V_112 , ( void * ) V_36 , & V_12 , 1 ) ;
V_4 = F_53 ( V_60 , & V_12 , V_36 , V_101 , & V_102 ) ;
F_15 ( V_112 , & V_12 , 1 ) ;
if ( V_4 != NULL )
return V_4 ;
V_4 = F_23 ( V_2 , V_35 , V_36 , V_38 ) ;
if ( F_64 ( F_25 ( V_4 ) ) )
return V_4 ;
F_4 ( F_67 ( F_2 ( V_4 ) , V_36 ) ) ;
F_37 ( V_112 , & V_12 , 1 ) ;
V_113 = F_53 ( V_60 , & V_12 , V_36 , V_101 , & V_102 ) ;
if ( F_56 ( V_113 == NULL ) ) {
struct V_5 * V_6 ;
V_6 = F_10 ( V_112 , & V_12 ) ;
F_65 ( V_112 , & V_12 , & V_4 -> V_15 -> V_18 ) ;
V_6 -> V_28 ++ ;
F_15 ( V_112 , & V_12 , 1 ) ;
return V_4 ;
}
F_27 ( V_60 -> V_53 , V_116 ) ;
F_15 ( V_112 , & V_12 , 1 ) ;
F_8 ( V_2 , V_4 ) ;
return V_113 ;
}
struct V_3 * F_62 ( const struct V_1 * V_2 ,
struct V_34 * V_35 ,
const struct V_13 * V_36 ,
const struct V_37 * V_38 )
{
struct V_5 * V_6 ;
struct V_3 * V_117 ;
T_5 V_118 ;
while ( 1 ) {
V_117 = F_66 ( V_2 , V_35 , V_36 , V_38 , & V_118 ) ;
if ( V_117 != F_24 ( - V_110 ) )
return V_117 ;
F_68 ( & V_118 , V_108 ) ;
V_6 = F_28 ( V_35 -> V_17 , ( void * ) V_36 ) ;
F_69 ( & V_6 -> V_27 , & V_118 ) ;
}
}
struct V_3 * F_70 ( const struct V_1 * V_2 ,
struct V_34 * V_35 ,
const struct V_13 * V_36 ,
const struct V_37 * V_38 )
{
struct V_3 * V_8 ;
struct V_3 * V_117 ;
V_8 = F_61 ( V_2 , V_35 , V_36 , V_38 ) ;
if ( ! F_25 ( V_8 ) ) {
V_117 = F_71 ( V_8 -> V_15 , V_35 -> V_97 ) ;
if ( V_117 == NULL )
F_1 ( V_2 , V_8 ) ;
} else
V_117 = V_8 ;
return V_117 ;
}
int F_72 ( struct V_119 * V_120 )
{
int V_43 = 0 ;
F_29 ( & V_120 -> V_121 ) ;
if ( V_120 -> V_122 -> V_123 )
V_43 = V_120 -> V_122 -> V_123 ( V_120 ) ;
if ( V_43 == 0 )
F_73 ( & V_120 -> V_121 , & V_124 ) ;
return V_43 ;
}
void F_74 ( struct V_119 * V_120 )
{
F_22 ( & V_120 -> V_121 ) ;
if ( V_120 -> V_122 -> V_125 )
V_120 -> V_122 -> V_125 ( V_120 ) ;
}
void F_75 ( void )
{
struct V_119 * V_120 ;
F_26 (ldt, &lu_device_types, ldt_linkage) {
if ( V_120 -> V_126 == 0 && V_120 -> V_122 -> V_127 )
V_120 -> V_122 -> V_127 ( V_120 ) ;
}
}
static int
F_76 ( T_2 * V_112 , T_1 * V_12 ,
struct V_103 * V_104 , void * V_128 )
{
struct V_129 * V_130 = (struct V_129 * ) V_128 ;
struct V_7 * V_62 ;
V_62 = F_77 ( V_104 , struct V_7 , V_18 ) ;
if ( ! F_5 ( & V_62 -> V_48 ) ) {
const struct V_3 * V_4 ;
V_4 = F_42 ( V_62 ) ;
F_51 ( V_130 -> V_131 , V_130 -> V_132 ,
V_130 -> V_133 , V_4 ) ;
} else {
F_48 ( V_130 -> V_131 , V_130 -> V_132 ,
V_130 -> V_133 , V_62 ) ;
}
return 0 ;
}
void F_78 ( const struct V_1 * V_2 , struct V_9 * V_60 , void * V_76 ,
T_4 V_89 )
{
struct V_129 V_130 = {
. V_131 = (struct V_1 * ) V_2 ,
. V_132 = V_76 ,
. V_133 = V_89 ,
} ;
F_79 ( V_60 -> V_25 , F_76 , & V_130 ) ;
}
static int F_80 ( void )
{
unsigned long V_134 ;
int V_135 ;
V_134 = V_136 ;
#if V_137 == 32
if ( V_134 > 1 << ( 30 - V_138 ) )
V_134 = 1 << ( 30 - V_138 ) * 3 / 4 ;
#endif
if ( V_139 == 0 || V_139 > V_140 ) {
F_81 ( L_13
L_14 ,
V_139 , V_140 ,
V_141 ) ;
V_139 = V_141 ;
}
V_134 = V_134 / 100 * V_139 *
( V_142 / 1024 ) ;
for ( V_135 = 1 ; ( 1 << V_135 ) < V_134 ; ++ V_135 ) {
;
}
return V_135 ;
}
static unsigned F_82 ( T_2 * V_112 ,
const void * V_81 , unsigned V_143 )
{
struct V_13 * V_14 = (struct V_13 * ) V_81 ;
T_7 V_144 ;
V_144 = F_83 ( V_14 ) ;
V_144 += ( V_144 >> 4 ) + ( V_144 << 12 ) ;
V_144 = F_84 ( V_144 , V_112 -> V_145 ) ;
V_144 -= F_84 ( ( unsigned long ) V_112 , F_85 ( V_14 ) % 11 + 3 ) ;
V_144 <<= V_112 -> V_146 - V_112 -> V_145 ;
V_144 |= ( F_86 ( V_14 ) + F_85 ( V_14 ) ) & ( F_35 ( V_112 ) - 1 ) ;
return V_144 & V_143 ;
}
static void * F_87 ( struct V_103 * V_104 )
{
return F_77 ( V_104 , struct V_7 , V_18 ) ;
}
static void * F_88 ( struct V_103 * V_104 )
{
struct V_7 * V_62 ;
V_62 = F_77 ( V_104 , struct V_7 , V_18 ) ;
return & V_62 -> V_26 ;
}
static int F_89 ( const void * V_81 , struct V_103 * V_104 )
{
struct V_7 * V_62 ;
V_62 = F_77 ( V_104 , struct V_7 , V_18 ) ;
return F_67 ( & V_62 -> V_26 , (struct V_13 * ) V_81 ) ;
}
static void F_90 ( T_2 * V_112 , struct V_103 * V_104 )
{
struct V_7 * V_62 ;
V_62 = F_77 ( V_104 , struct V_7 , V_18 ) ;
if ( F_91 ( 1 , & V_62 -> V_22 ) == 1 ) {
struct V_5 * V_6 ;
T_1 V_12 ;
F_9 ( V_112 , & V_62 -> V_26 , & V_12 ) ;
V_6 = F_10 ( V_112 , & V_12 ) ;
V_6 -> V_28 ++ ;
}
}
static void F_92 ( T_2 * V_112 , struct V_103 * V_104 )
{
F_93 () ;
}
void F_94 ( struct V_9 * V_60 , struct V_34 * V_147 )
{
F_95 ( & V_60 -> V_148 ) ;
if ( F_5 ( & V_147 -> V_149 ) )
F_73 ( & V_147 -> V_149 , & V_60 -> V_150 ) ;
F_96 ( & V_60 -> V_148 ) ;
}
void F_97 ( struct V_9 * V_60 , struct V_34 * V_147 )
{
F_95 ( & V_60 -> V_148 ) ;
F_22 ( & V_147 -> V_149 ) ;
F_96 ( & V_60 -> V_148 ) ;
}
int F_98 ( struct V_9 * V_60 , struct V_34 * V_8 )
{
struct V_5 * V_6 ;
T_1 V_12 ;
char V_151 [ 16 ] ;
int V_135 ;
int V_70 ;
V_44 ;
memset ( V_60 , 0 , sizeof *V_60 ) ;
V_135 = F_80 () ;
snprintf ( V_151 , 16 , L_15 , V_8 -> V_97 -> V_98 ) ;
for ( V_135 = F_99 ( F_100 ( V_152 , V_135 ) , V_153 ) ;
V_135 >= V_152 ; V_135 -- ) {
V_60 -> V_25 = F_101 ( V_151 , V_135 , V_135 ,
V_135 - V_154 ,
sizeof( * V_6 ) , 0 , 0 ,
& V_155 ,
V_156 |
V_157 |
V_158 |
V_159 ) ;
if ( V_60 -> V_25 != NULL )
break;
}
if ( V_60 -> V_25 == NULL ) {
F_102 ( L_16 , V_135 ) ;
return - V_47 ;
}
F_36 (s->ls_obj_hash, &bd, i) {
V_6 = F_10 ( V_60 -> V_25 , & V_12 ) ;
F_29 ( & V_6 -> V_29 ) ;
F_103 ( & V_6 -> V_27 ) ;
}
V_60 -> V_53 = F_104 ( V_160 , 0 ) ;
if ( V_60 -> V_53 == NULL ) {
F_105 ( V_60 -> V_25 ) ;
V_60 -> V_25 = NULL ;
return - V_47 ;
}
F_106 ( V_60 -> V_53 , V_54 ,
0 , L_17 , L_17 ) ;
F_106 ( V_60 -> V_53 , V_107 ,
0 , L_18 , L_18 ) ;
F_106 ( V_60 -> V_53 , V_106 ,
0 , L_19 , L_19 ) ;
F_106 ( V_60 -> V_53 , V_116 ,
0 , L_20 , L_20 ) ;
F_106 ( V_60 -> V_53 , V_109 ,
0 , L_21 , L_21 ) ;
F_106 ( V_60 -> V_53 , V_75 ,
0 , L_22 , L_22 ) ;
F_29 ( & V_60 -> V_161 ) ;
V_60 -> V_111 = V_8 ;
V_8 -> V_17 = V_60 ;
F_107 ( V_8 ) ;
F_108 ( & V_8 -> V_162 , L_23 , V_60 ) ;
F_29 ( & V_60 -> V_150 ) ;
F_109 ( & V_60 -> V_148 ) ;
F_94 ( V_60 , V_8 ) ;
RETURN ( 0 ) ;
}
void F_110 ( struct V_9 * V_60 )
{
F_111 ( & V_163 ) ;
F_22 ( & V_60 -> V_161 ) ;
F_112 ( & V_163 ) ;
if ( V_60 -> V_25 != NULL ) {
F_105 ( V_60 -> V_25 ) ;
V_60 -> V_25 = NULL ;
}
if ( V_60 -> V_111 != NULL ) {
V_60 -> V_111 -> V_17 = NULL ;
F_113 ( & V_60 -> V_111 -> V_162 , L_23 , V_60 ) ;
F_114 ( V_60 -> V_111 ) ;
V_60 -> V_111 = NULL ;
}
if ( V_60 -> V_53 != NULL )
F_115 ( & V_60 -> V_53 ) ;
}
int F_116 ( struct V_9 * V_60 )
{
int V_43 ;
F_111 ( & V_163 ) ;
V_43 = F_117 ( & V_164 . V_84 ) ;
if ( V_43 == 0 )
F_73 ( & V_60 -> V_161 , & V_165 ) ;
F_112 ( & V_163 ) ;
return V_43 ;
}
void F_107 ( struct V_34 * V_147 )
{
F_118 ( & V_147 -> V_166 ) ;
}
void F_114 ( struct V_34 * V_147 )
{
F_4 ( F_39 ( & V_147 -> V_166 ) > 0 ) ;
F_119 ( & V_147 -> V_166 ) ;
}
int F_120 ( struct V_34 * V_147 , struct V_119 * V_167 )
{
if ( V_167 -> V_126 ++ == 0 && V_167 -> V_122 -> V_168 != NULL )
V_167 -> V_122 -> V_168 ( V_167 ) ;
memset ( V_147 , 0 , sizeof *V_147 ) ;
F_121 ( & V_147 -> V_166 , 0 ) ;
V_147 -> V_97 = V_167 ;
F_122 ( & V_147 -> V_162 ) ;
F_29 ( & V_147 -> V_149 ) ;
return 0 ;
}
void F_123 ( struct V_34 * V_147 )
{
struct V_119 * V_167 ;
V_167 = V_147 -> V_97 ;
if ( V_147 -> V_169 != NULL ) {
V_147 -> V_169 -> V_170 = NULL ;
V_147 -> V_169 = NULL ;
}
F_124 ( & V_147 -> V_162 ) ;
F_125 ( F_39 ( & V_147 -> V_166 ) == 0 ,
L_24 , F_39 ( & V_147 -> V_166 ) ) ;
F_4 ( V_167 -> V_126 > 0 ) ;
if ( -- V_167 -> V_126 == 0 && V_167 -> V_122 -> V_127 != NULL )
V_167 -> V_122 -> V_127 ( V_167 ) ;
}
int F_126 ( struct V_3 * V_4 ,
struct V_7 * V_62 , struct V_34 * V_147 )
{
memset ( V_4 , 0 , sizeof *V_4 ) ;
V_4 -> V_15 = V_62 ;
V_4 -> V_16 = V_147 ;
F_107 ( V_147 ) ;
V_4 -> V_171 = F_108 ( & V_147 -> V_162 , L_25 , V_4 ) ;
F_29 ( & V_4 -> V_58 ) ;
return 0 ;
}
void F_127 ( struct V_3 * V_4 )
{
struct V_34 * V_35 = V_4 -> V_16 ;
F_4 ( F_5 ( & V_4 -> V_58 ) ) ;
if ( V_35 != NULL ) {
F_128 ( & V_35 -> V_162 ,
V_4 -> V_171 , L_25 , V_4 ) ;
F_114 ( V_35 ) ;
V_4 -> V_16 = NULL ;
}
}
void F_129 ( struct V_7 * V_62 , struct V_3 * V_4 )
{
F_40 ( & V_4 -> V_58 , & V_62 -> V_48 ) ;
}
void F_130 ( struct V_3 * V_172 , struct V_3 * V_4 )
{
F_40 ( & V_4 -> V_58 , & V_172 -> V_58 ) ;
}
int F_131 ( struct V_7 * V_62 )
{
memset ( V_62 , 0 , sizeof *V_62 ) ;
F_121 ( & V_62 -> V_22 , 1 ) ;
F_132 ( & V_62 -> V_18 ) ;
F_29 ( & V_62 -> V_21 ) ;
F_29 ( & V_62 -> V_48 ) ;
F_122 ( & V_62 -> V_173 ) ;
return 0 ;
}
void F_133 ( struct V_7 * V_62 )
{
F_4 ( F_5 ( & V_62 -> V_48 ) ) ;
F_4 ( F_5 ( & V_62 -> V_21 ) ) ;
F_4 ( F_50 ( & V_62 -> V_18 ) ) ;
F_124 ( & V_62 -> V_173 ) ;
}
struct V_3 * F_71 ( struct V_7 * V_62 ,
const struct V_119 * V_174 )
{
struct V_3 * V_4 ;
F_26 (o, &h->loh_layers, lo_linkage) {
if ( V_4 -> V_16 -> V_97 == V_174 )
return V_4 ;
}
return NULL ;
}
void F_134 ( const struct V_1 * V_2 , struct V_34 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_17 ;
struct V_34 * V_39 ;
struct V_34 * V_19 ;
F_33 ( V_2 , V_10 , ~ 0 ) ;
for ( V_39 = V_8 ; V_39 != NULL ; V_39 = V_19 ) {
V_19 = V_39 -> V_97 -> V_122 -> V_175 ( V_2 , V_39 ) ;
F_113 ( & V_39 -> V_162 , L_26 , & F_98 ) ;
F_114 ( V_39 ) ;
}
F_33 ( V_2 , V_10 , ~ 0 ) ;
for ( V_39 = V_8 ; V_39 != NULL ; V_39 = V_19 ) {
const struct V_119 * V_120 = V_39 -> V_97 ;
struct V_176 * type ;
V_19 = V_120 -> V_122 -> V_177 ( V_2 , V_39 ) ;
type = V_120 -> V_178 ;
if ( type != NULL ) {
type -> V_179 -- ;
F_135 ( type ) ;
}
}
}
int F_136 ( struct V_180 * V_81 )
{
int V_43 ;
int V_70 ;
F_4 ( V_81 -> V_181 != NULL ) ;
F_4 ( V_81 -> V_182 != NULL ) ;
F_4 ( V_81 -> V_183 != 0 ) ;
F_4 ( V_81 -> V_184 != NULL ) ;
V_43 = - V_185 ;
F_95 ( & V_186 ) ;
for ( V_70 = 0 ; V_70 < F_45 ( V_187 ) ; ++ V_70 ) {
if ( V_187 [ V_70 ] == NULL ) {
V_81 -> V_188 = V_70 ;
F_121 ( & V_81 -> V_189 , 1 ) ;
V_187 [ V_70 ] = V_81 ;
F_122 ( & V_81 -> V_190 ) ;
V_43 = 0 ;
++ V_191 ;
break;
}
}
F_96 ( & V_186 ) ;
return V_43 ;
}
static void F_137 ( struct V_192 * V_193 , int V_194 )
{
if ( V_193 -> V_195 != NULL && V_193 -> V_195 [ V_194 ] != NULL ) {
struct V_180 * V_81 ;
V_81 = V_187 [ V_194 ] ;
F_4 ( V_81 != NULL ) ;
F_4 ( V_81 -> V_182 != NULL ) ;
F_4 ( F_39 ( & V_81 -> V_189 ) > 1 ) ;
V_81 -> V_182 ( V_193 , V_81 , V_193 -> V_195 [ V_194 ] ) ;
F_113 ( & V_81 -> V_190 , L_27 , V_193 ) ;
F_119 ( & V_81 -> V_189 ) ;
F_4 ( V_81 -> V_184 != NULL ) ;
if ( ( V_193 -> V_196 & V_197 ) == 0 ) {
#ifdef F_138
F_139 ( F_140 ( V_81 -> V_184 ) > 0 ) ;
#endif
F_141 ( V_81 -> V_184 ) ;
}
V_193 -> V_195 [ V_194 ] = NULL ;
}
}
void F_142 ( struct V_180 * V_81 )
{
F_4 ( F_39 ( & V_81 -> V_189 ) >= 1 ) ;
F_139 ( 0 <= V_81 -> V_188 && V_81 -> V_188 < F_45 ( V_187 ) ) ;
F_143 ( V_81 ) ;
++ V_191 ;
F_95 ( & V_186 ) ;
F_137 ( & V_164 . V_84 , V_81 -> V_188 ) ;
if ( V_187 [ V_81 -> V_188 ] ) {
V_187 [ V_81 -> V_188 ] = NULL ;
F_124 ( & V_81 -> V_190 ) ;
}
F_96 ( & V_186 ) ;
F_125 ( F_39 ( & V_81 -> V_189 ) == 1 ,
L_28 ,
F_39 ( & V_81 -> V_189 ) ) ;
}
int F_144 ( struct V_180 * V_198 , ... )
{
struct V_180 * V_81 = V_198 ;
T_3 args ;
int V_43 ;
va_start ( args , V_198 ) ;
do {
V_43 = F_136 ( V_81 ) ;
if ( V_43 )
break;
V_81 = va_arg ( args , struct V_180 * ) ;
} while ( V_81 != NULL );
va_end ( args ) ;
if ( V_43 != 0 ) {
va_start ( args , V_198 ) ;
while ( V_198 != V_81 ) {
F_142 ( V_198 ) ;
V_198 = va_arg ( args , struct V_180 * ) ;
}
va_end ( args ) ;
}
return V_43 ;
}
void F_145 ( struct V_180 * V_198 , ... )
{
T_3 args ;
va_start ( args , V_198 ) ;
do {
F_142 ( V_198 ) ;
V_198 = va_arg ( args , struct V_180 * ) ;
} while ( V_198 != NULL );
va_end ( args ) ;
}
void F_146 ( struct V_180 * V_198 , ... )
{
T_3 args ;
va_start ( args , V_198 ) ;
do {
F_147 ( V_198 ) ;
V_198 = va_arg ( args , struct V_180 * ) ;
} while ( V_198 != NULL );
va_end ( args ) ;
}
void F_148 ( struct V_180 * V_198 , ... )
{
T_3 args ;
va_start ( args , V_198 ) ;
do {
F_143 ( V_198 ) ;
V_198 = va_arg ( args , struct V_180 * ) ;
} while ( V_198 != NULL );
va_end ( args ) ;
}
void * F_44 ( const struct V_192 * V_193 ,
const struct V_180 * V_81 )
{
F_139 ( V_193 -> V_199 == V_200 ) ;
F_139 ( 0 <= V_81 -> V_188 && V_81 -> V_188 < F_45 ( V_187 ) ) ;
F_4 ( V_187 [ V_81 -> V_188 ] == V_81 ) ;
return V_193 -> V_195 [ V_81 -> V_188 ] ;
}
void F_143 ( struct V_180 * V_81 )
{
struct V_192 * V_193 ;
if ( ! ( V_81 -> V_183 & V_201 ) ) {
V_81 -> V_183 |= V_201 ;
F_95 ( & V_186 ) ;
F_26 (ctx, &lu_context_remembered,
lc_remember)
F_137 ( V_193 , V_81 -> V_188 ) ;
F_96 ( & V_186 ) ;
++ V_191 ;
}
}
void F_147 ( struct V_180 * V_81 )
{
V_81 -> V_183 &= ~ V_201 ;
++ V_191 ;
}
static void F_149 ( struct V_192 * V_193 )
{
int V_70 ;
if ( V_193 -> V_195 == NULL )
return;
for ( V_70 = 0 ; V_70 < F_45 ( V_187 ) ; ++ V_70 )
F_137 ( V_193 , V_70 ) ;
F_150 ( V_193 -> V_195 , F_45 ( V_187 ) * sizeof V_193 -> V_195 [ 0 ] ) ;
V_193 -> V_195 = NULL ;
}
static int F_151 ( struct V_192 * V_193 )
{
int V_70 ;
F_139 ( V_193 -> V_195 != NULL ) ;
for ( V_70 = 0 ; V_70 < F_45 ( V_187 ) ; ++ V_70 ) {
struct V_180 * V_81 ;
V_81 = V_187 [ V_70 ] ;
if ( V_193 -> V_195 [ V_70 ] == NULL && V_81 != NULL &&
( V_81 -> V_183 & V_193 -> V_196 ) &&
! ( V_81 -> V_183 & V_201 ) ) {
void * V_202 ;
F_139 ( V_81 -> V_181 != NULL ) ;
F_139 ( V_81 -> V_188 == V_70 ) ;
V_202 = V_81 -> V_181 ( V_193 , V_81 ) ;
if ( F_64 ( F_25 ( V_202 ) ) )
return F_152 ( V_202 ) ;
F_4 ( V_81 -> V_184 != NULL ) ;
if ( ! ( V_193 -> V_196 & V_197 ) )
F_153 ( V_81 -> V_184 ) ;
F_154 ( & V_81 -> V_190 , L_27 , V_193 ) ;
F_118 ( & V_81 -> V_189 ) ;
V_193 -> V_195 [ V_70 ] = V_202 ;
if ( V_81 -> V_203 != NULL )
V_193 -> V_196 |= V_204 ;
}
V_193 -> V_205 = V_191 ;
}
return 0 ;
}
static int F_155 ( struct V_192 * V_193 )
{
F_156 ( V_193 -> V_195 , F_45 ( V_187 ) * sizeof V_193 -> V_195 [ 0 ] ) ;
if ( F_56 ( V_193 -> V_195 != NULL ) )
return F_151 ( V_193 ) ;
return - V_47 ;
}
int F_157 ( struct V_192 * V_193 , T_7 V_206 )
{
int V_207 ;
memset ( V_193 , 0 , sizeof *V_193 ) ;
V_193 -> V_199 = V_208 ;
V_193 -> V_196 = V_206 ;
if ( V_206 & V_209 ) {
F_95 ( & V_186 ) ;
F_73 ( & V_193 -> V_210 , & V_211 ) ;
F_96 ( & V_186 ) ;
} else {
F_29 ( & V_193 -> V_210 ) ;
}
V_207 = F_155 ( V_193 ) ;
if ( V_207 != 0 )
F_158 ( V_193 ) ;
return V_207 ;
}
void F_158 ( struct V_192 * V_193 )
{
F_139 ( V_193 -> V_199 == V_208 || V_193 -> V_199 == V_212 ) ;
V_193 -> V_199 = V_213 ;
if ( ( V_193 -> V_196 & V_209 ) == 0 ) {
F_4 ( F_5 ( & V_193 -> V_210 ) ) ;
F_149 ( V_193 ) ;
} else {
F_95 ( & V_186 ) ;
F_149 ( V_193 ) ;
F_22 ( & V_193 -> V_210 ) ;
F_96 ( & V_186 ) ;
}
}
void F_159 ( struct V_192 * V_193 )
{
F_139 ( V_193 -> V_199 == V_208 || V_193 -> V_199 == V_212 ) ;
V_193 -> V_199 = V_200 ;
}
void F_160 ( struct V_192 * V_193 )
{
int V_70 ;
F_139 ( V_193 -> V_199 == V_200 ) ;
V_193 -> V_199 = V_212 ;
if ( V_193 -> V_196 & V_204 && V_193 -> V_195 != NULL ) {
for ( V_70 = 0 ; V_70 < F_45 ( V_187 ) ; ++ V_70 ) {
if ( V_193 -> V_195 [ V_70 ] != NULL ) {
struct V_180 * V_81 ;
V_81 = V_187 [ V_70 ] ;
F_4 ( V_81 != NULL ) ;
if ( V_81 -> V_203 != NULL )
V_81 -> V_203 ( V_193 ,
V_81 , V_193 -> V_195 [ V_70 ] ) ;
}
}
}
}
int F_117 ( struct V_192 * V_193 )
{
return F_56 ( V_193 -> V_205 == V_191 ) ? 0 : F_151 ( V_193 ) ;
}
void F_161 ( T_7 V_206 )
{
F_95 ( & V_186 ) ;
V_214 |= V_206 ;
V_191 ++ ;
F_96 ( & V_186 ) ;
}
void F_162 ( T_7 V_206 )
{
F_95 ( & V_186 ) ;
V_214 &= ~ V_206 ;
V_191 ++ ;
F_96 ( & V_186 ) ;
}
void F_163 ( T_7 V_206 )
{
F_95 ( & V_186 ) ;
V_215 |= V_206 ;
V_191 ++ ;
F_96 ( & V_186 ) ;
}
void F_164 ( T_7 V_206 )
{
F_95 ( & V_186 ) ;
V_215 &= ~ V_206 ;
V_191 ++ ;
F_96 ( & V_186 ) ;
}
int F_165 ( struct V_1 * V_2 , T_7 V_206 )
{
int V_43 ;
V_2 -> V_216 = NULL ;
V_43 = F_157 ( & V_2 -> V_84 , V_206 ) ;
if ( F_56 ( V_43 == 0 ) )
F_159 ( & V_2 -> V_84 ) ;
return V_43 ;
}
void F_166 ( struct V_1 * V_2 )
{
F_160 ( & V_2 -> V_84 ) ;
F_158 ( & V_2 -> V_84 ) ;
V_2 -> V_216 = NULL ;
}
int F_167 ( struct V_1 * V_2 )
{
int V_43 ;
V_43 = F_117 ( & V_2 -> V_84 ) ;
if ( V_43 == 0 && V_2 -> V_216 != NULL )
V_43 = F_117 ( V_2 -> V_216 ) ;
return V_43 ;
}
int F_168 ( struct V_1 * V_2 , T_7 V_217 ,
T_7 V_218 )
{
int V_43 ;
if ( ( V_2 -> V_84 . V_196 & V_217 ) != V_217 ) {
V_2 -> V_84 . V_205 = 0 ;
V_2 -> V_84 . V_196 |= V_217 ;
}
if ( V_2 -> V_216 && ( V_2 -> V_216 -> V_196 & V_218 ) != V_218 ) {
V_2 -> V_216 -> V_205 = 0 ;
V_2 -> V_216 -> V_196 |= V_218 ;
}
V_43 = F_167 ( V_2 ) ;
return V_43 ;
}
static void F_169 ( T_2 * V_112 ,
T_8 * V_219 , int V_220 )
{
T_1 V_12 ;
int V_70 ;
F_36 (hs, &bd, i) {
struct V_5 * V_6 = F_10 ( V_112 , & V_12 ) ;
struct V_221 * V_222 ;
F_37 ( V_112 , & V_12 , 1 ) ;
V_219 -> V_223 += V_6 -> V_28 ;
V_219 -> V_224 += F_170 ( & V_12 ) ;
V_219 -> V_225 = F_100 ( ( int ) V_219 -> V_225 ,
F_171 ( & V_12 ) ) ;
if ( ! V_220 ) {
F_15 ( V_112 , & V_12 , 1 ) ;
continue;
}
F_172 (hs, &bd, hhead) {
if ( ! F_173 ( V_222 ) )
V_219 -> V_226 ++ ;
}
F_15 ( V_112 , & V_12 , 1 ) ;
}
}
int F_174 ( const struct V_1 * V_2 ,
void * V_227 , const char * V_77 , ... )
{
T_3 args ;
va_start ( args , V_77 ) ;
F_175 ( V_77 , args ) ;
va_end ( args ) ;
return 0 ;
}
int F_176 ( void )
{
int V_43 ;
F_177 ( V_228 , L_29 , & V_187 ) ;
V_43 = F_178 () ;
if ( V_43 != 0 )
return V_43 ;
F_179 ( & V_85 ) ;
V_43 = F_136 ( & V_85 ) ;
if ( V_43 != 0 )
return V_43 ;
F_111 ( & V_163 ) ;
V_43 = F_165 ( & V_164 , V_229 ) ;
F_112 ( & V_163 ) ;
if ( V_43 != 0 )
return V_43 ;
V_230 = F_180 ( V_231 , V_232 ) ;
if ( V_230 == NULL )
return - V_47 ;
return V_43 ;
}
void F_181 ( void )
{
if ( V_230 != NULL ) {
F_182 ( V_230 ) ;
V_230 = NULL ;
}
F_142 ( & V_85 ) ;
F_111 ( & V_163 ) ;
F_166 ( & V_164 ) ;
F_112 ( & V_163 ) ;
F_183 () ;
}
static T_7 F_184 ( struct V_233 * V_219 , int V_234 )
{
#ifdef F_185
struct V_235 V_236 ;
F_186 ( V_219 , V_234 , & V_236 ) ;
return ( T_7 ) V_236 . V_237 ;
#else
return 0 ;
#endif
}
int F_187 ( const struct V_9 * V_60 , struct V_238 * V_239 )
{
T_8 V_219 ;
memset ( & V_219 , 0 , sizeof( V_219 ) ) ;
F_169 ( V_60 -> V_25 , & V_219 , 1 ) ;
return F_188 ( V_239 , L_30 ,
V_219 . V_223 ,
V_219 . V_224 ,
V_219 . V_226 ,
F_189 ( V_60 -> V_25 ) ,
V_219 . V_225 ,
F_184 ( V_60 -> V_53 , V_54 ) ,
F_184 ( V_60 -> V_53 , V_107 ) ,
F_184 ( V_60 -> V_53 , V_106 ) ,
F_184 ( V_60 -> V_53 , V_116 ) ,
F_184 ( V_60 -> V_53 , V_109 ) ,
F_184 ( V_60 -> V_53 , V_75 ) ) ;
}
int F_190 ( struct V_240 * V_241 )
{
int V_43 ;
struct V_240 * V_242 = V_241 ;
for ( V_43 = 0 ; V_242 -> V_243 != NULL ; ++ V_242 ) {
* V_242 -> V_243 = F_191 ( V_242 -> V_244 ,
V_242 -> V_245 ,
0 , 0 , NULL ) ;
if ( * V_242 -> V_243 == NULL ) {
V_43 = - V_47 ;
F_192 ( V_241 ) ;
break;
}
}
return V_43 ;
}
void F_192 ( struct V_240 * V_241 )
{
for (; V_241 -> V_243 != NULL ; ++ V_241 ) {
if ( * V_241 -> V_243 != NULL ) {
F_193 ( * V_241 -> V_243 ) ;
* V_241 -> V_243 = NULL ;
}
}
}
void F_194 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_13 * V_14 )
{
struct V_9 * V_60 = V_4 -> V_16 -> V_17 ;
struct V_13 * V_246 = & V_4 -> V_15 -> V_26 ;
struct V_5 * V_6 ;
struct V_3 * V_113 ;
T_5 V_101 ;
T_2 * V_112 ;
T_1 V_12 ;
T_6 V_102 = 0 ;
F_4 ( F_3 ( V_246 ) ) ;
V_112 = V_60 -> V_25 ;
F_21 ( V_112 , ( void * ) V_14 , & V_12 , 1 ) ;
V_113 = F_53 ( V_60 , & V_12 , V_14 , & V_101 , & V_102 ) ;
F_4 ( V_113 == NULL ) ;
* V_246 = * V_14 ;
V_6 = F_10 ( V_112 , & V_12 ) ;
F_65 ( V_112 , & V_12 , & V_4 -> V_15 -> V_18 ) ;
V_6 -> V_28 ++ ;
F_15 ( V_112 , & V_12 , 1 ) ;
}
struct V_3 * F_195 ( const struct V_1 * V_2 ,
struct V_34 * V_35 ,
const struct V_37 * V_38 )
{
struct V_13 V_14 ;
struct V_3 * V_4 ;
F_196 ( & V_14 ) ;
V_4 = F_23 ( V_2 , V_35 , & V_14 , V_38 ) ;
return V_4 ;
}
void F_197 ( struct V_247 * V_248 )
{
F_4 ( V_248 ) ;
if ( V_248 -> V_249 ) {
F_4 ( V_248 -> V_250 > 0 ) ;
F_198 ( V_248 -> V_249 , V_248 -> V_250 ) ;
V_248 -> V_249 = NULL ;
V_248 -> V_250 = 0 ;
}
}
void F_199 ( struct V_247 * V_248 , int V_251 )
{
F_4 ( V_248 ) ;
F_4 ( V_248 -> V_249 == NULL ) ;
F_4 ( V_248 -> V_250 == 0 ) ;
F_200 ( V_248 -> V_249 , V_251 ) ;
if ( F_56 ( V_248 -> V_249 ) )
V_248 -> V_250 = V_251 ;
}
void F_201 ( struct V_247 * V_248 , int V_251 )
{
F_197 ( V_248 ) ;
F_199 ( V_248 , V_251 ) ;
}
struct V_247 * F_202 ( struct V_247 * V_248 , int V_252 )
{
if ( V_248 -> V_249 == NULL && V_248 -> V_250 == 0 )
F_199 ( V_248 , V_252 ) ;
if ( ( V_252 > V_248 -> V_250 ) && ( V_248 -> V_249 != NULL ) )
F_201 ( V_248 , V_252 ) ;
return V_248 ;
}
int F_203 ( struct V_247 * V_248 , int V_252 )
{
char * V_253 ;
if ( V_252 <= V_248 -> V_250 )
return 0 ;
F_200 ( V_253 , V_252 ) ;
if ( V_253 == NULL )
return - V_47 ;
if ( V_248 -> V_249 != NULL ) {
memcpy ( V_253 , V_248 -> V_249 , V_248 -> V_250 ) ;
F_198 ( V_248 -> V_249 , V_248 -> V_250 ) ;
}
V_248 -> V_249 = V_253 ;
V_248 -> V_250 = V_252 ;
return 0 ;
}
