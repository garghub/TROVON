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
V_8 = V_35 -> V_44 -> V_45 ( V_2 , NULL , V_35 ) ;
if ( V_8 == NULL )
return F_24 ( - V_46 ) ;
if ( F_25 ( V_8 ) )
return V_8 ;
V_8 -> V_15 -> V_26 = * V_36 ;
V_41 = & V_8 -> V_15 -> V_47 ;
do {
V_42 = 1 ;
F_26 (scan, layers, lo_linkage) {
if ( V_39 -> V_48 & V_49 )
continue;
V_42 = 0 ;
V_39 -> V_15 = V_8 -> V_15 ;
V_43 = V_39 -> V_23 -> V_50 ( V_2 , V_39 , V_38 ) ;
if ( V_43 != 0 ) {
F_8 ( V_2 , V_8 ) ;
return F_24 ( V_43 ) ;
}
V_39 -> V_48 |= V_49 ;
}
} while ( ! V_42 );
F_7 (scan, layers, lo_linkage) {
if ( V_39 -> V_23 -> V_51 != NULL ) {
V_43 = V_39 -> V_23 -> V_51 ( V_2 , V_39 ) ;
if ( V_43 != 0 ) {
F_8 ( V_2 , V_8 ) ;
return F_24 ( V_43 ) ;
}
}
}
F_27 ( V_35 -> V_17 -> V_52 , V_53 ) ;
return V_8 ;
}
static void F_8 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_3 * V_39 ;
struct V_40 * V_41 ;
struct V_40 V_54 ;
V_10 = V_4 -> V_16 -> V_17 ;
V_41 = & V_4 -> V_15 -> V_47 ;
V_6 = F_28 ( V_10 , & V_4 -> V_15 -> V_26 ) ;
F_7 (scan, layers, lo_linkage) {
if ( V_39 -> V_23 -> V_55 != NULL )
V_39 -> V_23 -> V_55 ( V_2 , V_39 ) ;
}
F_29 ( & V_54 ) ;
F_30 ( V_41 , & V_54 ) ;
while ( ! F_5 ( & V_54 ) ) {
V_4 = F_31 ( V_54 . V_56 , struct V_3 , V_57 ) ;
F_22 ( & V_4 -> V_57 ) ;
F_4 ( V_4 -> V_23 -> V_58 != NULL ) ;
V_4 -> V_23 -> V_58 ( V_2 , V_4 ) ;
}
if ( F_32 ( & V_6 -> V_27 ) )
F_13 ( & V_6 -> V_27 ) ;
}
int F_33 ( const struct V_1 * V_2 , struct V_9 * V_59 , int V_60 )
{
struct V_7 * V_61 ;
struct V_7 * V_62 ;
struct V_5 * V_6 ;
T_1 V_12 ;
T_1 V_63 ;
struct V_40 V_64 ;
int V_65 ;
int V_66 ;
int V_67 ;
int V_68 ;
int V_69 ;
if ( F_34 ( V_70 ) )
return 0 ;
F_29 ( & V_64 ) ;
V_66 = V_59 -> V_71 ;
V_68 = ( V_60 == ~ 0 ) ? - 1 : V_60 / F_35 ( V_59 -> V_25 ) + 1 ;
V_72:
V_65 = 0 ;
F_36 (s->ls_obj_hash, &bd, i) {
if ( V_69 < V_66 )
continue;
V_67 = V_68 ;
F_37 ( V_59 -> V_25 , & V_12 , 1 ) ;
V_6 = F_10 ( V_59 -> V_25 , & V_12 ) ;
F_38 (h, temp, &bkt->lsb_lru, loh_lru) {
F_4 ( F_39 ( & V_61 -> V_22 ) == 0 ) ;
F_9 ( V_59 -> V_25 , & V_61 -> V_26 , & V_63 ) ;
F_4 ( V_12 . V_73 == V_63 . V_73 ) ;
F_17 ( V_59 -> V_25 ,
& V_63 , & V_61 -> V_18 ) ;
F_40 ( & V_61 -> V_21 , & V_64 ) ;
if ( V_65 == 0 )
V_65 = 1 ;
if ( V_60 != ~ 0 && -- V_60 == 0 )
break;
if ( V_67 > 0 && -- V_67 == 0 )
break;
}
F_15 ( V_59 -> V_25 , & V_12 , 1 ) ;
F_41 () ;
while ( ! F_5 ( & V_64 ) ) {
V_61 = F_31 ( V_64 . V_19 ,
struct V_7 , V_21 ) ;
F_22 ( & V_61 -> V_21 ) ;
F_8 ( V_2 , F_42 ( V_61 ) ) ;
F_27 ( V_59 -> V_52 , V_74 ) ;
}
if ( V_60 == 0 )
break;
}
if ( V_60 != 0 && V_65 && V_66 != 0 ) {
V_66 = 0 ;
goto V_72;
}
V_59 -> V_71 = V_69 % F_35 ( V_59 -> V_25 ) ;
return V_60 ;
}
int F_43 ( const struct V_1 * V_2 ,
void * V_75 , const char * V_76 , ... )
{
struct V_77 * V_78 = V_75 ;
struct V_79 * V_80 ;
int V_81 ;
int V_82 ;
T_3 args ;
va_start ( args , V_76 ) ;
V_80 = F_44 ( & V_2 -> V_83 , & V_84 ) ;
F_4 ( V_80 != NULL ) ;
V_81 = strlen ( V_80 -> V_85 ) ;
V_82 = V_76 [ strlen ( V_76 ) - 1 ] == '\n' ;
vsnprintf ( V_80 -> V_85 + V_81 ,
F_45 ( V_80 -> V_85 ) - V_81 , V_76 , args ) ;
if ( V_82 ) {
if ( F_46 ( V_78 -> V_86 , V_78 -> V_87 ) )
F_47 ( V_78 , L_1 , V_80 -> V_85 ) ;
V_80 -> V_85 [ 0 ] = 0 ;
}
va_end ( args ) ;
return 0 ;
}
void F_48 ( const struct V_1 * V_2 , void * V_75 ,
T_4 V_88 ,
const struct V_7 * V_89 )
{
(* V_88)( V_2 , V_75 , L_2 V_90 L_3 ,
V_89 , V_89 -> V_31 , F_39 ( & V_89 -> V_22 ) ,
F_49 ( & V_89 -> V_26 ) ,
F_50 ( & V_89 -> V_18 ) ? L_4 : L_5 ,
F_5 ( (struct V_40 * ) & V_89 -> V_21 ) ? \
L_4 : L_6 ,
V_89 -> V_91 & V_92 ? L_7 : L_4 ) ;
}
void F_51 ( const struct V_1 * V_2 , void * V_75 ,
T_4 V_88 , const struct V_3 * V_4 )
{
static const char V_93 [] = L_8 ;
struct V_7 * V_8 ;
int V_94 ;
V_8 = V_4 -> V_15 ;
F_48 ( V_2 , V_75 , V_88 , V_8 ) ;
(* V_88)( V_2 , V_75 , L_9 ) ;
F_26 (o, &top->loh_layers, lo_linkage) {
V_94 = V_4 -> V_95 + 4 ;
(* V_88)( V_2 , V_75 , L_10 , V_94 , V_94 , V_93 ,
V_4 -> V_16 -> V_96 -> V_97 , V_4 ) ;
if ( V_4 -> V_23 -> V_98 != NULL )
V_4 -> V_23 -> V_98 ( V_2 , V_75 , V_88 , V_4 ) ;
(* V_88)( V_2 , V_75 , L_11 ) ;
}
(* V_88)( V_2 , V_75 , L_12 , V_8 ) ;
}
int F_52 ( const struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = V_4 -> V_15 ;
F_26 (o, &top->loh_layers, lo_linkage) {
if ( V_4 -> V_23 -> V_99 != NULL &&
! V_4 -> V_23 -> V_99 ( V_4 ) )
return 0 ;
}
return 1 ;
}
static struct V_3 * F_53 ( struct V_9 * V_59 ,
T_1 * V_12 ,
const struct V_13 * V_36 ,
T_5 * V_100 ,
T_6 * V_101 )
{
struct V_5 * V_6 ;
struct V_7 * V_61 ;
struct V_102 * V_103 ;
T_6 V_104 = F_54 ( V_12 ) ;
if ( * V_101 == V_104 )
return F_24 ( - V_105 ) ;
* V_101 = V_104 ;
V_6 = F_10 ( V_59 -> V_25 , V_12 ) ;
V_103 = F_55 ( V_59 -> V_25 , V_12 , ( void * ) V_36 ) ;
if ( V_103 == NULL ) {
F_27 ( V_59 -> V_52 , V_106 ) ;
return F_24 ( - V_105 ) ;
}
V_61 = F_31 ( V_103 , struct V_7 , V_18 ) ;
if ( F_56 ( ! F_12 ( V_61 ) ) ) {
F_57 ( V_59 -> V_25 , V_103 ) ;
F_27 ( V_59 -> V_52 , V_107 ) ;
F_22 ( & V_61 -> V_21 ) ;
return F_42 ( V_61 ) ;
}
F_58 ( V_100 ) ;
F_59 ( & V_6 -> V_27 , V_100 ) ;
F_60 ( V_108 ) ;
F_27 ( V_59 -> V_52 , V_109 ) ;
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
T_5 * V_100 )
{
struct V_3 * V_4 ;
struct V_3 * V_113 ;
struct V_9 * V_59 ;
T_2 * V_112 ;
T_1 V_12 ;
T_6 V_101 = 0 ;
if ( V_38 != NULL && V_38 -> V_114 & V_115 )
return F_63 ( V_2 , V_35 , V_36 , V_38 ) ;
V_59 = V_35 -> V_17 ;
V_112 = V_59 -> V_25 ;
F_21 ( V_112 , ( void * ) V_36 , & V_12 , 1 ) ;
V_4 = F_53 ( V_59 , & V_12 , V_36 , V_100 , & V_101 ) ;
F_15 ( V_112 , & V_12 , 1 ) ;
if ( ! F_25 ( V_4 ) || F_67 ( V_4 ) != - V_105 )
return V_4 ;
V_4 = F_23 ( V_2 , V_35 , V_36 , V_38 ) ;
if ( F_64 ( F_25 ( V_4 ) ) )
return V_4 ;
F_4 ( F_68 ( F_2 ( V_4 ) , V_36 ) ) ;
F_37 ( V_112 , & V_12 , 1 ) ;
V_113 = F_53 ( V_59 , & V_12 , V_36 , V_100 , & V_101 ) ;
if ( F_56 ( F_25 ( V_113 ) && F_67 ( V_113 ) == - V_105 ) ) {
struct V_5 * V_6 ;
V_6 = F_10 ( V_112 , & V_12 ) ;
F_65 ( V_112 , & V_12 , & V_4 -> V_15 -> V_18 ) ;
V_6 -> V_28 ++ ;
F_15 ( V_112 , & V_12 , 1 ) ;
return V_4 ;
}
F_27 ( V_59 -> V_52 , V_116 ) ;
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
F_69 ( & V_118 , V_108 ) ;
V_6 = F_28 ( V_35 -> V_17 , ( void * ) V_36 ) ;
F_70 ( & V_6 -> V_27 , & V_118 ) ;
}
}
struct V_3 * F_71 ( const struct V_1 * V_2 ,
struct V_34 * V_35 ,
const struct V_13 * V_36 ,
const struct V_37 * V_38 )
{
struct V_3 * V_8 ;
struct V_3 * V_117 ;
V_8 = F_61 ( V_2 , V_35 , V_36 , V_38 ) ;
if ( ! F_25 ( V_8 ) ) {
V_117 = F_72 ( V_8 -> V_15 , V_35 -> V_96 ) ;
if ( V_117 == NULL )
F_1 ( V_2 , V_8 ) ;
} else
V_117 = V_8 ;
return V_117 ;
}
int F_73 ( struct V_119 * V_120 )
{
int V_43 = 0 ;
F_29 ( & V_120 -> V_121 ) ;
if ( V_120 -> V_122 -> V_123 )
V_43 = V_120 -> V_122 -> V_123 ( V_120 ) ;
if ( V_43 == 0 )
F_74 ( & V_120 -> V_121 , & V_124 ) ;
return V_43 ;
}
void F_75 ( struct V_119 * V_120 )
{
F_22 ( & V_120 -> V_121 ) ;
if ( V_120 -> V_122 -> V_125 )
V_120 -> V_122 -> V_125 ( V_120 ) ;
}
void F_76 ( void )
{
struct V_119 * V_120 ;
F_26 (ldt, &lu_device_types, ldt_linkage) {
if ( V_120 -> V_126 == 0 && V_120 -> V_122 -> V_127 )
V_120 -> V_122 -> V_127 ( V_120 ) ;
}
}
static int
F_77 ( T_2 * V_112 , T_1 * V_12 ,
struct V_102 * V_103 , void * V_128 )
{
struct V_129 * V_130 = (struct V_129 * ) V_128 ;
struct V_7 * V_61 ;
V_61 = F_78 ( V_103 , struct V_7 , V_18 ) ;
if ( ! F_5 ( & V_61 -> V_47 ) ) {
const struct V_3 * V_4 ;
V_4 = F_42 ( V_61 ) ;
F_51 ( V_130 -> V_131 , V_130 -> V_132 ,
V_130 -> V_133 , V_4 ) ;
} else {
F_48 ( V_130 -> V_131 , V_130 -> V_132 ,
V_130 -> V_133 , V_61 ) ;
}
return 0 ;
}
void F_79 ( const struct V_1 * V_2 , struct V_9 * V_59 , void * V_75 ,
T_4 V_88 )
{
struct V_129 V_130 = {
. V_131 = (struct V_1 * ) V_2 ,
. V_132 = V_75 ,
. V_133 = V_88 ,
} ;
F_80 ( V_59 -> V_25 , F_77 , & V_130 ) ;
}
static int F_81 ( void )
{
unsigned long V_134 ;
int V_135 ;
V_134 = V_136 ;
#if V_137 == 32
if ( V_134 > 1 << ( 30 - V_138 ) )
V_134 = 1 << ( 30 - V_138 ) * 3 / 4 ;
#endif
if ( V_139 == 0 || V_139 > V_140 ) {
F_82 ( L_13
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
static unsigned F_83 ( T_2 * V_112 ,
const void * V_80 , unsigned V_143 )
{
struct V_13 * V_14 = (struct V_13 * ) V_80 ;
T_7 V_144 ;
V_144 = F_84 ( V_14 ) ;
V_144 += ( V_144 >> 4 ) + ( V_144 << 12 ) ;
V_144 = F_85 ( V_144 , V_112 -> V_145 ) ;
V_144 -= F_85 ( ( unsigned long ) V_112 , F_86 ( V_14 ) % 11 + 3 ) ;
V_144 <<= V_112 -> V_146 - V_112 -> V_145 ;
V_144 |= ( F_87 ( V_14 ) + F_86 ( V_14 ) ) & ( F_35 ( V_112 ) - 1 ) ;
return V_144 & V_143 ;
}
static void * F_88 ( struct V_102 * V_103 )
{
return F_78 ( V_103 , struct V_7 , V_18 ) ;
}
static void * F_89 ( struct V_102 * V_103 )
{
struct V_7 * V_61 ;
V_61 = F_78 ( V_103 , struct V_7 , V_18 ) ;
return & V_61 -> V_26 ;
}
static int F_90 ( const void * V_80 , struct V_102 * V_103 )
{
struct V_7 * V_61 ;
V_61 = F_78 ( V_103 , struct V_7 , V_18 ) ;
return F_68 ( & V_61 -> V_26 , (struct V_13 * ) V_80 ) ;
}
static void F_91 ( T_2 * V_112 , struct V_102 * V_103 )
{
struct V_7 * V_61 ;
V_61 = F_78 ( V_103 , struct V_7 , V_18 ) ;
if ( F_92 ( 1 , & V_61 -> V_22 ) == 1 ) {
struct V_5 * V_6 ;
T_1 V_12 ;
F_9 ( V_112 , & V_61 -> V_26 , & V_12 ) ;
V_6 = F_10 ( V_112 , & V_12 ) ;
V_6 -> V_28 ++ ;
}
}
static void F_93 ( T_2 * V_112 , struct V_102 * V_103 )
{
F_94 () ;
}
void F_95 ( struct V_9 * V_59 , struct V_34 * V_147 )
{
F_96 ( & V_59 -> V_148 ) ;
if ( F_5 ( & V_147 -> V_149 ) )
F_74 ( & V_147 -> V_149 , & V_59 -> V_150 ) ;
F_97 ( & V_59 -> V_148 ) ;
}
void F_98 ( struct V_9 * V_59 , struct V_34 * V_147 )
{
F_96 ( & V_59 -> V_148 ) ;
F_22 ( & V_147 -> V_149 ) ;
F_97 ( & V_59 -> V_148 ) ;
}
int F_99 ( struct V_9 * V_59 , struct V_34 * V_8 )
{
struct V_5 * V_6 ;
T_1 V_12 ;
char V_151 [ 16 ] ;
int V_135 ;
int V_69 ;
memset ( V_59 , 0 , sizeof *V_59 ) ;
V_135 = F_81 () ;
snprintf ( V_151 , 16 , L_15 , V_8 -> V_96 -> V_97 ) ;
for ( V_135 = F_100 ( F_101 ( V_152 , V_135 ) , V_153 ) ;
V_135 >= V_152 ; V_135 -- ) {
V_59 -> V_25 = F_102 ( V_151 , V_135 , V_135 ,
V_135 - V_154 ,
sizeof( * V_6 ) , 0 , 0 ,
& V_155 ,
V_156 |
V_157 |
V_158 |
V_159 ) ;
if ( V_59 -> V_25 != NULL )
break;
}
if ( V_59 -> V_25 == NULL ) {
F_103 ( L_16 , V_135 ) ;
return - V_46 ;
}
F_36 (s->ls_obj_hash, &bd, i) {
V_6 = F_10 ( V_59 -> V_25 , & V_12 ) ;
F_29 ( & V_6 -> V_29 ) ;
F_104 ( & V_6 -> V_27 ) ;
}
V_59 -> V_52 = F_105 ( V_160 , 0 ) ;
if ( V_59 -> V_52 == NULL ) {
F_106 ( V_59 -> V_25 ) ;
V_59 -> V_25 = NULL ;
return - V_46 ;
}
F_107 ( V_59 -> V_52 , V_53 ,
0 , L_17 , L_17 ) ;
F_107 ( V_59 -> V_52 , V_107 ,
0 , L_18 , L_18 ) ;
F_107 ( V_59 -> V_52 , V_106 ,
0 , L_19 , L_19 ) ;
F_107 ( V_59 -> V_52 , V_116 ,
0 , L_20 , L_20 ) ;
F_107 ( V_59 -> V_52 , V_109 ,
0 , L_21 , L_21 ) ;
F_107 ( V_59 -> V_52 , V_74 ,
0 , L_22 , L_22 ) ;
F_29 ( & V_59 -> V_161 ) ;
V_59 -> V_111 = V_8 ;
V_8 -> V_17 = V_59 ;
F_108 ( V_8 ) ;
F_109 ( & V_8 -> V_162 , L_23 , V_59 ) ;
F_29 ( & V_59 -> V_150 ) ;
F_110 ( & V_59 -> V_148 ) ;
F_95 ( V_59 , V_8 ) ;
return 0 ;
}
void F_111 ( struct V_9 * V_59 )
{
F_112 ( & V_163 ) ;
F_22 ( & V_59 -> V_161 ) ;
F_113 ( & V_163 ) ;
if ( V_59 -> V_25 != NULL ) {
F_106 ( V_59 -> V_25 ) ;
V_59 -> V_25 = NULL ;
}
if ( V_59 -> V_111 != NULL ) {
V_59 -> V_111 -> V_17 = NULL ;
F_114 ( & V_59 -> V_111 -> V_162 , L_23 , V_59 ) ;
F_115 ( V_59 -> V_111 ) ;
V_59 -> V_111 = NULL ;
}
if ( V_59 -> V_52 != NULL )
F_116 ( & V_59 -> V_52 ) ;
}
int F_117 ( struct V_9 * V_59 )
{
int V_43 ;
F_112 ( & V_163 ) ;
V_43 = F_118 ( & V_164 . V_83 ) ;
if ( V_43 == 0 )
F_74 ( & V_59 -> V_161 , & V_165 ) ;
F_113 ( & V_163 ) ;
return V_43 ;
}
void F_108 ( struct V_34 * V_147 )
{
F_119 ( & V_147 -> V_166 ) ;
}
void F_115 ( struct V_34 * V_147 )
{
F_4 ( F_39 ( & V_147 -> V_166 ) > 0 ) ;
F_120 ( & V_147 -> V_166 ) ;
}
int F_121 ( struct V_34 * V_147 , struct V_119 * V_167 )
{
if ( V_167 -> V_126 ++ == 0 && V_167 -> V_122 -> V_168 != NULL )
V_167 -> V_122 -> V_168 ( V_167 ) ;
memset ( V_147 , 0 , sizeof *V_147 ) ;
F_122 ( & V_147 -> V_166 , 0 ) ;
V_147 -> V_96 = V_167 ;
F_123 ( & V_147 -> V_162 ) ;
F_29 ( & V_147 -> V_149 ) ;
return 0 ;
}
void F_124 ( struct V_34 * V_147 )
{
struct V_119 * V_167 ;
V_167 = V_147 -> V_96 ;
if ( V_147 -> V_169 != NULL ) {
V_147 -> V_169 -> V_170 = NULL ;
V_147 -> V_169 = NULL ;
}
F_125 ( & V_147 -> V_162 ) ;
F_126 ( F_39 ( & V_147 -> V_166 ) == 0 ,
L_24 , F_39 ( & V_147 -> V_166 ) ) ;
F_4 ( V_167 -> V_126 > 0 ) ;
if ( -- V_167 -> V_126 == 0 && V_167 -> V_122 -> V_127 != NULL )
V_167 -> V_122 -> V_127 ( V_167 ) ;
}
int F_127 ( struct V_3 * V_4 , struct V_7 * V_61 ,
struct V_34 * V_147 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_15 = V_61 ;
V_4 -> V_16 = V_147 ;
F_108 ( V_147 ) ;
F_128 ( & V_147 -> V_162 , & V_4 -> V_171 , L_25 , V_4 ) ;
F_29 ( & V_4 -> V_57 ) ;
return 0 ;
}
void F_129 ( struct V_3 * V_4 )
{
struct V_34 * V_35 = V_4 -> V_16 ;
F_4 ( F_5 ( & V_4 -> V_57 ) ) ;
if ( V_35 != NULL ) {
F_130 ( & V_35 -> V_162 , & V_4 -> V_171 ,
L_25 , V_4 ) ;
F_115 ( V_35 ) ;
V_4 -> V_16 = NULL ;
}
}
void F_131 ( struct V_7 * V_61 , struct V_3 * V_4 )
{
F_40 ( & V_4 -> V_57 , & V_61 -> V_47 ) ;
}
void F_132 ( struct V_3 * V_172 , struct V_3 * V_4 )
{
F_40 ( & V_4 -> V_57 , & V_172 -> V_57 ) ;
}
int F_133 ( struct V_7 * V_61 )
{
memset ( V_61 , 0 , sizeof *V_61 ) ;
F_122 ( & V_61 -> V_22 , 1 ) ;
F_134 ( & V_61 -> V_18 ) ;
F_29 ( & V_61 -> V_21 ) ;
F_29 ( & V_61 -> V_47 ) ;
F_123 ( & V_61 -> V_173 ) ;
return 0 ;
}
void F_135 ( struct V_7 * V_61 )
{
F_4 ( F_5 ( & V_61 -> V_47 ) ) ;
F_4 ( F_5 ( & V_61 -> V_21 ) ) ;
F_4 ( F_50 ( & V_61 -> V_18 ) ) ;
F_125 ( & V_61 -> V_173 ) ;
}
struct V_3 * F_72 ( struct V_7 * V_61 ,
const struct V_119 * V_174 )
{
struct V_3 * V_4 ;
F_26 (o, &h->loh_layers, lo_linkage) {
if ( V_4 -> V_16 -> V_96 == V_174 )
return V_4 ;
}
return NULL ;
}
void F_136 ( const struct V_1 * V_2 , struct V_34 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_17 ;
struct V_34 * V_39 ;
struct V_34 * V_19 ;
F_33 ( V_2 , V_10 , ~ 0 ) ;
for ( V_39 = V_8 ; V_39 != NULL ; V_39 = V_19 ) {
V_19 = V_39 -> V_96 -> V_122 -> V_175 ( V_2 , V_39 ) ;
F_114 ( & V_39 -> V_162 , L_26 , & F_99 ) ;
F_115 ( V_39 ) ;
}
F_33 ( V_2 , V_10 , ~ 0 ) ;
for ( V_39 = V_8 ; V_39 != NULL ; V_39 = V_19 ) {
const struct V_119 * V_120 = V_39 -> V_96 ;
struct V_176 * type ;
V_19 = V_120 -> V_122 -> V_177 ( V_2 , V_39 ) ;
type = V_120 -> V_178 ;
if ( type != NULL ) {
type -> V_179 -- ;
F_137 ( type ) ;
}
}
}
int F_138 ( struct V_180 * V_80 )
{
int V_43 ;
int V_69 ;
F_4 ( V_80 -> V_181 != NULL ) ;
F_4 ( V_80 -> V_182 != NULL ) ;
F_4 ( V_80 -> V_183 != 0 ) ;
V_43 = - V_184 ;
F_96 ( & V_185 ) ;
for ( V_69 = 0 ; V_69 < F_45 ( V_186 ) ; ++ V_69 ) {
if ( V_186 [ V_69 ] == NULL ) {
V_80 -> V_187 = V_69 ;
F_122 ( & V_80 -> V_188 , 1 ) ;
V_186 [ V_69 ] = V_80 ;
F_123 ( & V_80 -> V_189 ) ;
V_43 = 0 ;
++ V_190 ;
break;
}
}
F_97 ( & V_185 ) ;
return V_43 ;
}
static void F_139 ( struct V_191 * V_192 , int V_193 )
{
if ( V_192 -> V_194 != NULL && V_192 -> V_194 [ V_193 ] != NULL ) {
struct V_180 * V_80 ;
V_80 = V_186 [ V_193 ] ;
F_4 ( V_80 != NULL ) ;
F_4 ( V_80 -> V_182 != NULL ) ;
F_4 ( F_39 ( & V_80 -> V_188 ) > 1 ) ;
V_80 -> V_182 ( V_192 , V_80 , V_192 -> V_194 [ V_193 ] ) ;
F_114 ( & V_80 -> V_189 , L_27 , V_192 ) ;
F_120 ( & V_80 -> V_188 ) ;
if ( ( V_192 -> V_195 & V_196 ) == 0 ) {
#ifdef F_140
F_141 ( F_142 ( V_80 -> V_197 ) > 0 ) ;
#endif
F_143 ( V_80 -> V_197 ) ;
}
V_192 -> V_194 [ V_193 ] = NULL ;
}
}
void F_144 ( struct V_180 * V_80 )
{
F_4 ( F_39 ( & V_80 -> V_188 ) >= 1 ) ;
F_141 ( 0 <= V_80 -> V_187 && V_80 -> V_187 < F_45 ( V_186 ) ) ;
F_145 ( V_80 ) ;
++ V_190 ;
F_96 ( & V_185 ) ;
F_139 ( & V_164 . V_83 , V_80 -> V_187 ) ;
if ( V_186 [ V_80 -> V_187 ] ) {
V_186 [ V_80 -> V_187 ] = NULL ;
F_125 ( & V_80 -> V_189 ) ;
}
F_97 ( & V_185 ) ;
F_126 ( F_39 ( & V_80 -> V_188 ) == 1 ,
L_28 ,
F_39 ( & V_80 -> V_188 ) ) ;
}
int F_146 ( struct V_180 * V_198 , ... )
{
struct V_180 * V_80 = V_198 ;
T_3 args ;
int V_43 ;
va_start ( args , V_198 ) ;
do {
V_43 = F_138 ( V_80 ) ;
if ( V_43 )
break;
V_80 = va_arg ( args , struct V_180 * ) ;
} while ( V_80 != NULL );
va_end ( args ) ;
if ( V_43 != 0 ) {
va_start ( args , V_198 ) ;
while ( V_198 != V_80 ) {
F_144 ( V_198 ) ;
V_198 = va_arg ( args , struct V_180 * ) ;
}
va_end ( args ) ;
}
return V_43 ;
}
void F_147 ( struct V_180 * V_198 , ... )
{
T_3 args ;
va_start ( args , V_198 ) ;
do {
F_144 ( V_198 ) ;
V_198 = va_arg ( args , struct V_180 * ) ;
} while ( V_198 != NULL );
va_end ( args ) ;
}
void F_148 ( struct V_180 * V_198 , ... )
{
T_3 args ;
va_start ( args , V_198 ) ;
do {
F_149 ( V_198 ) ;
V_198 = va_arg ( args , struct V_180 * ) ;
} while ( V_198 != NULL );
va_end ( args ) ;
}
void F_150 ( struct V_180 * V_198 , ... )
{
T_3 args ;
va_start ( args , V_198 ) ;
do {
F_145 ( V_198 ) ;
V_198 = va_arg ( args , struct V_180 * ) ;
} while ( V_198 != NULL );
va_end ( args ) ;
}
void * F_44 ( const struct V_191 * V_192 ,
const struct V_180 * V_80 )
{
F_141 ( V_192 -> V_199 == V_200 ) ;
F_141 ( 0 <= V_80 -> V_187 && V_80 -> V_187 < F_45 ( V_186 ) ) ;
F_4 ( V_186 [ V_80 -> V_187 ] == V_80 ) ;
return V_192 -> V_194 [ V_80 -> V_187 ] ;
}
void F_145 ( struct V_180 * V_80 )
{
struct V_191 * V_192 ;
if ( ! ( V_80 -> V_183 & V_201 ) ) {
V_80 -> V_183 |= V_201 ;
F_96 ( & V_185 ) ;
F_26 (ctx, &lu_context_remembered,
lc_remember)
F_139 ( V_192 , V_80 -> V_187 ) ;
F_97 ( & V_185 ) ;
++ V_190 ;
}
}
void F_149 ( struct V_180 * V_80 )
{
V_80 -> V_183 &= ~ V_201 ;
++ V_190 ;
}
static void F_151 ( struct V_191 * V_192 )
{
int V_69 ;
if ( V_192 -> V_194 == NULL )
return;
for ( V_69 = 0 ; V_69 < F_45 ( V_186 ) ; ++ V_69 )
F_139 ( V_192 , V_69 ) ;
F_152 ( V_192 -> V_194 , F_45 ( V_186 ) * sizeof V_192 -> V_194 [ 0 ] ) ;
V_192 -> V_194 = NULL ;
}
static int F_153 ( struct V_191 * V_192 )
{
int V_69 ;
F_141 ( V_192 -> V_194 != NULL ) ;
for ( V_69 = 0 ; V_69 < F_45 ( V_186 ) ; ++ V_69 ) {
struct V_180 * V_80 ;
V_80 = V_186 [ V_69 ] ;
if ( V_192 -> V_194 [ V_69 ] == NULL && V_80 != NULL &&
( V_80 -> V_183 & V_192 -> V_195 ) &&
! ( V_80 -> V_183 & V_201 ) ) {
void * V_202 ;
F_141 ( V_80 -> V_181 != NULL ) ;
F_141 ( V_80 -> V_187 == V_69 ) ;
V_202 = V_80 -> V_181 ( V_192 , V_80 ) ;
if ( F_64 ( F_25 ( V_202 ) ) )
return F_67 ( V_202 ) ;
if ( ! ( V_192 -> V_195 & V_196 ) )
F_154 ( V_80 -> V_197 ) ;
F_155 ( & V_80 -> V_189 , L_27 , V_192 ) ;
F_119 ( & V_80 -> V_188 ) ;
V_192 -> V_194 [ V_69 ] = V_202 ;
if ( V_80 -> V_203 != NULL )
V_192 -> V_195 |= V_204 ;
}
V_192 -> V_205 = V_190 ;
}
return 0 ;
}
static int F_156 ( struct V_191 * V_192 )
{
F_157 ( V_192 -> V_194 , F_45 ( V_186 ) * sizeof V_192 -> V_194 [ 0 ] ) ;
if ( F_56 ( V_192 -> V_194 != NULL ) )
return F_153 ( V_192 ) ;
return - V_46 ;
}
int F_158 ( struct V_191 * V_192 , T_7 V_206 )
{
int V_207 ;
memset ( V_192 , 0 , sizeof *V_192 ) ;
V_192 -> V_199 = V_208 ;
V_192 -> V_195 = V_206 ;
if ( V_206 & V_209 ) {
F_96 ( & V_185 ) ;
F_74 ( & V_192 -> V_210 , & V_211 ) ;
F_97 ( & V_185 ) ;
} else {
F_29 ( & V_192 -> V_210 ) ;
}
V_207 = F_156 ( V_192 ) ;
if ( V_207 != 0 )
F_159 ( V_192 ) ;
return V_207 ;
}
void F_159 ( struct V_191 * V_192 )
{
F_141 ( V_192 -> V_199 == V_208 || V_192 -> V_199 == V_212 ) ;
V_192 -> V_199 = V_213 ;
if ( ( V_192 -> V_195 & V_209 ) == 0 ) {
F_4 ( F_5 ( & V_192 -> V_210 ) ) ;
F_151 ( V_192 ) ;
} else {
F_96 ( & V_185 ) ;
F_151 ( V_192 ) ;
F_22 ( & V_192 -> V_210 ) ;
F_97 ( & V_185 ) ;
}
}
void F_160 ( struct V_191 * V_192 )
{
F_141 ( V_192 -> V_199 == V_208 || V_192 -> V_199 == V_212 ) ;
V_192 -> V_199 = V_200 ;
}
void F_161 ( struct V_191 * V_192 )
{
int V_69 ;
F_141 ( V_192 -> V_199 == V_200 ) ;
V_192 -> V_199 = V_212 ;
if ( V_192 -> V_195 & V_204 && V_192 -> V_194 != NULL ) {
for ( V_69 = 0 ; V_69 < F_45 ( V_186 ) ; ++ V_69 ) {
if ( V_192 -> V_194 [ V_69 ] != NULL ) {
struct V_180 * V_80 ;
V_80 = V_186 [ V_69 ] ;
F_4 ( V_80 != NULL ) ;
if ( V_80 -> V_203 != NULL )
V_80 -> V_203 ( V_192 ,
V_80 , V_192 -> V_194 [ V_69 ] ) ;
}
}
}
}
int F_118 ( struct V_191 * V_192 )
{
return F_56 ( V_192 -> V_205 == V_190 ) ? 0 : F_153 ( V_192 ) ;
}
void F_162 ( T_7 V_206 )
{
F_96 ( & V_185 ) ;
V_214 |= V_206 ;
V_190 ++ ;
F_97 ( & V_185 ) ;
}
void F_163 ( T_7 V_206 )
{
F_96 ( & V_185 ) ;
V_214 &= ~ V_206 ;
V_190 ++ ;
F_97 ( & V_185 ) ;
}
void F_164 ( T_7 V_206 )
{
F_96 ( & V_185 ) ;
V_215 |= V_206 ;
V_190 ++ ;
F_97 ( & V_185 ) ;
}
void F_165 ( T_7 V_206 )
{
F_96 ( & V_185 ) ;
V_215 &= ~ V_206 ;
V_190 ++ ;
F_97 ( & V_185 ) ;
}
int F_166 ( struct V_1 * V_2 , T_7 V_206 )
{
int V_43 ;
V_2 -> V_216 = NULL ;
V_43 = F_158 ( & V_2 -> V_83 , V_206 ) ;
if ( F_56 ( V_43 == 0 ) )
F_160 ( & V_2 -> V_83 ) ;
return V_43 ;
}
void F_167 ( struct V_1 * V_2 )
{
F_161 ( & V_2 -> V_83 ) ;
F_159 ( & V_2 -> V_83 ) ;
V_2 -> V_216 = NULL ;
}
int F_168 ( struct V_1 * V_2 )
{
int V_43 ;
V_43 = F_118 ( & V_2 -> V_83 ) ;
if ( V_43 == 0 && V_2 -> V_216 != NULL )
V_43 = F_118 ( V_2 -> V_216 ) ;
return V_43 ;
}
int F_169 ( struct V_1 * V_2 , T_7 V_217 ,
T_7 V_218 )
{
int V_43 ;
if ( ( V_2 -> V_83 . V_195 & V_217 ) != V_217 ) {
V_2 -> V_83 . V_205 = 0 ;
V_2 -> V_83 . V_195 |= V_217 ;
}
if ( V_2 -> V_216 && ( V_2 -> V_216 -> V_195 & V_218 ) != V_218 ) {
V_2 -> V_216 -> V_205 = 0 ;
V_2 -> V_216 -> V_195 |= V_218 ;
}
V_43 = F_168 ( V_2 ) ;
return V_43 ;
}
static void F_170 ( T_2 * V_112 ,
T_8 * V_219 , int V_220 )
{
T_1 V_12 ;
int V_69 ;
F_36 (hs, &bd, i) {
struct V_5 * V_6 = F_10 ( V_112 , & V_12 ) ;
struct V_221 * V_222 ;
F_37 ( V_112 , & V_12 , 1 ) ;
V_219 -> V_223 += V_6 -> V_28 ;
V_219 -> V_224 += F_171 ( & V_12 ) ;
V_219 -> V_225 = F_101 ( ( int ) V_219 -> V_225 ,
F_172 ( & V_12 ) ) ;
if ( ! V_220 ) {
F_15 ( V_112 , & V_12 , 1 ) ;
continue;
}
F_173 (hs, &bd, hhead) {
if ( ! F_174 ( V_222 ) )
V_219 -> V_226 ++ ;
}
F_15 ( V_112 , & V_12 , 1 ) ;
}
}
static unsigned long F_175 ( struct V_227 * V_228 ,
struct V_229 * V_230 )
{
T_8 V_219 ;
struct V_9 * V_59 ;
struct V_9 * V_231 ;
unsigned long V_232 = 0 ;
if ( ! ( V_230 -> V_233 & V_234 ) )
return 0 ;
F_112 ( & V_163 ) ;
F_38 (s, tmp, &lu_sites, ls_linkage) {
memset ( & V_219 , 0 , sizeof( V_219 ) ) ;
F_170 ( V_59 -> V_25 , & V_219 , 0 ) ;
V_232 += V_219 . V_224 - V_219 . V_223 ;
}
F_113 ( & V_163 ) ;
V_232 = ( V_232 / 100 ) * V_235 ;
F_176 ( V_236 , L_29 , V_232 ) ;
return V_232 ;
}
static unsigned long F_177 ( struct V_227 * V_228 ,
struct V_229 * V_230 )
{
struct V_9 * V_59 ;
struct V_9 * V_231 ;
unsigned long V_237 = V_230 -> V_238 , V_239 = 0 ;
F_178 ( V_54 ) ;
if ( ! ( V_230 -> V_233 & V_234 ) )
return V_240 ;
F_112 ( & V_163 ) ;
F_38 (s, tmp, &lu_sites, ls_linkage) {
V_239 = F_33 ( & V_164 , V_59 , V_237 ) ;
V_237 -= V_239 ;
F_179 ( & V_59 -> V_161 , & V_54 ) ;
}
F_180 ( & V_54 , V_165 . V_56 ) ;
F_113 ( & V_163 ) ;
return V_230 -> V_238 - V_237 ;
}
int F_181 ( const struct V_1 * V_2 ,
void * V_241 , const char * V_76 , ... )
{
T_3 args ;
va_start ( args , V_76 ) ;
F_182 ( V_76 , args ) ;
va_end ( args ) ;
return 0 ;
}
int F_183 ( void )
{
int V_43 ;
F_176 ( V_242 , L_30 , & V_186 ) ;
V_43 = F_184 () ;
if ( V_43 != 0 )
return V_43 ;
F_185 ( & V_84 ) ;
V_43 = F_138 ( & V_84 ) ;
if ( V_43 != 0 )
return V_43 ;
F_112 ( & V_163 ) ;
V_43 = F_166 ( & V_164 , V_243 ) ;
F_113 ( & V_163 ) ;
if ( V_43 != 0 )
return V_43 ;
F_186 ( & V_244 ) ;
return V_43 ;
}
void F_187 ( void )
{
F_188 ( & V_244 ) ;
F_144 ( & V_84 ) ;
F_112 ( & V_163 ) ;
F_167 ( & V_164 ) ;
F_113 ( & V_163 ) ;
F_189 () ;
}
static T_7 F_190 ( struct V_245 * V_219 , int V_246 )
{
#ifdef F_191
struct V_247 V_248 ;
F_192 ( V_219 , V_246 , & V_248 ) ;
return ( T_7 ) V_248 . V_249 ;
#else
return 0 ;
#endif
}
int F_193 ( const struct V_9 * V_59 , struct V_250 * V_251 )
{
T_8 V_219 ;
memset ( & V_219 , 0 , sizeof( V_219 ) ) ;
F_170 ( V_59 -> V_25 , & V_219 , 1 ) ;
return F_194 ( V_251 , L_31 ,
V_219 . V_223 ,
V_219 . V_224 ,
V_219 . V_226 ,
F_195 ( V_59 -> V_25 ) ,
V_219 . V_225 ,
F_190 ( V_59 -> V_52 , V_53 ) ,
F_190 ( V_59 -> V_52 , V_107 ) ,
F_190 ( V_59 -> V_52 , V_106 ) ,
F_190 ( V_59 -> V_52 , V_116 ) ,
F_190 ( V_59 -> V_52 , V_109 ) ,
F_190 ( V_59 -> V_52 , V_74 ) ) ;
}
int F_196 ( struct V_252 * V_253 )
{
int V_43 ;
struct V_252 * V_254 = V_253 ;
for ( V_43 = 0 ; V_254 -> V_255 != NULL ; ++ V_254 ) {
* V_254 -> V_255 = F_197 ( V_254 -> V_256 ,
V_254 -> V_257 ,
0 , 0 , NULL ) ;
if ( * V_254 -> V_255 == NULL ) {
V_43 = - V_46 ;
F_198 ( V_253 ) ;
break;
}
}
return V_43 ;
}
void F_198 ( struct V_252 * V_253 )
{
for (; V_253 -> V_255 != NULL ; ++ V_253 ) {
if ( * V_253 -> V_255 != NULL ) {
F_199 ( * V_253 -> V_255 ) ;
* V_253 -> V_255 = NULL ;
}
}
}
void F_200 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_13 * V_14 )
{
struct V_9 * V_59 = V_4 -> V_16 -> V_17 ;
struct V_13 * V_258 = & V_4 -> V_15 -> V_26 ;
struct V_5 * V_6 ;
struct V_3 * V_113 ;
T_5 V_100 ;
T_2 * V_112 ;
T_1 V_12 ;
T_6 V_101 = 0 ;
F_4 ( F_3 ( V_258 ) ) ;
V_112 = V_59 -> V_25 ;
F_21 ( V_112 , ( void * ) V_14 , & V_12 , 1 ) ;
V_113 = F_53 ( V_59 , & V_12 , V_14 , & V_100 , & V_101 ) ;
F_4 ( F_25 ( V_113 ) && F_67 ( V_113 ) == - V_105 ) ;
* V_258 = * V_14 ;
V_6 = F_10 ( V_112 , & V_12 ) ;
F_65 ( V_112 , & V_12 , & V_4 -> V_15 -> V_18 ) ;
V_6 -> V_28 ++ ;
F_15 ( V_112 , & V_12 , 1 ) ;
}
struct V_3 * F_201 ( const struct V_1 * V_2 ,
struct V_34 * V_35 ,
const struct V_37 * V_38 )
{
struct V_13 V_14 ;
struct V_3 * V_4 ;
F_202 ( & V_14 ) ;
V_4 = F_23 ( V_2 , V_35 , & V_14 , V_38 ) ;
return V_4 ;
}
void F_203 ( struct V_259 * V_260 )
{
F_4 ( V_260 ) ;
if ( V_260 -> V_261 ) {
F_4 ( V_260 -> V_262 > 0 ) ;
F_204 ( V_260 -> V_261 , V_260 -> V_262 ) ;
V_260 -> V_261 = NULL ;
V_260 -> V_262 = 0 ;
}
}
void F_205 ( struct V_259 * V_260 , int V_263 )
{
F_4 ( V_260 ) ;
F_4 ( V_260 -> V_261 == NULL ) ;
F_4 ( V_260 -> V_262 == 0 ) ;
F_206 ( V_260 -> V_261 , V_263 ) ;
if ( F_56 ( V_260 -> V_261 ) )
V_260 -> V_262 = V_263 ;
}
void F_207 ( struct V_259 * V_260 , int V_263 )
{
F_203 ( V_260 ) ;
F_205 ( V_260 , V_263 ) ;
}
struct V_259 * F_208 ( struct V_259 * V_260 , int V_264 )
{
if ( V_260 -> V_261 == NULL && V_260 -> V_262 == 0 )
F_205 ( V_260 , V_264 ) ;
if ( ( V_264 > V_260 -> V_262 ) && ( V_260 -> V_261 != NULL ) )
F_207 ( V_260 , V_264 ) ;
return V_260 ;
}
int F_209 ( struct V_259 * V_260 , int V_264 )
{
char * V_265 ;
if ( V_264 <= V_260 -> V_262 )
return 0 ;
F_206 ( V_265 , V_264 ) ;
if ( V_265 == NULL )
return - V_46 ;
if ( V_260 -> V_261 != NULL ) {
memcpy ( V_265 , V_260 -> V_261 , V_260 -> V_262 ) ;
F_204 ( V_260 -> V_261 , V_260 -> V_262 ) ;
}
V_260 -> V_261 = V_265 ;
V_260 -> V_262 = V_264 ;
return 0 ;
}
