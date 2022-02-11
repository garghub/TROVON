void F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_3 * V_11 ;
struct V_12 V_13 ;
const struct V_14 * V_15 ;
V_8 = V_4 -> V_16 ;
V_10 = V_4 -> V_17 -> V_18 ;
V_11 = V_4 ;
V_15 = F_2 ( V_4 ) ;
if ( F_3 ( V_15 ) ) {
F_4 ( V_8 -> V_19 . V_20 == NULL
&& V_8 -> V_19 . V_21 == NULL ) ;
F_4 ( F_5 ( & V_8 -> V_22 ) ) ;
if ( ! F_6 ( & V_8 -> V_23 ) )
return;
F_7 (o, &top->loh_layers, lo_linkage) {
if ( V_4 -> V_24 -> V_25 != NULL )
V_4 -> V_24 -> V_25 ( V_2 , V_4 ) ;
}
F_8 ( V_2 , V_11 ) ;
return;
}
F_9 ( V_10 -> V_26 , & V_8 -> V_27 , & V_13 ) ;
V_6 = F_10 ( V_10 -> V_26 , & V_13 ) ;
if ( ! F_11 ( V_10 -> V_26 , & V_13 , & V_8 -> V_23 ) ) {
if ( F_12 ( V_8 ) ) {
F_13 ( & V_6 -> V_28 ) ;
}
return;
}
F_4 ( V_6 -> V_29 > 0 ) ;
V_6 -> V_29 -- ;
F_7 (o, &top->loh_layers, lo_linkage) {
if ( V_4 -> V_24 -> V_25 != NULL )
V_4 -> V_24 -> V_25 ( V_2 , V_4 ) ;
}
if ( ! F_12 ( V_8 ) ) {
F_4 ( F_5 ( & V_8 -> V_22 ) ) ;
F_14 ( & V_8 -> V_22 , & V_6 -> V_30 ) ;
F_15 ( V_10 -> V_26 , & V_13 , 1 ) ;
return;
}
if ( ! F_16 ( V_31 , & V_8 -> V_32 ) )
F_17 ( V_10 -> V_26 , & V_13 , & V_8 -> V_19 ) ;
F_15 ( V_10 -> V_26 , & V_13 , 1 ) ;
F_8 ( V_2 , V_11 ) ;
}
void F_18 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
F_19 ( V_33 , & V_4 -> V_16 -> V_32 ) ;
return F_1 ( V_2 , V_4 ) ;
}
void F_20 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = V_4 -> V_16 ;
F_19 ( V_33 , & V_8 -> V_32 ) ;
if ( ! F_16 ( V_31 , & V_8 -> V_32 ) ) {
struct V_34 * V_35 = V_4 -> V_17 -> V_18 -> V_26 ;
struct V_12 V_13 ;
F_21 ( V_35 , & V_8 -> V_27 , & V_13 , 1 ) ;
F_22 ( & V_8 -> V_22 ) ;
F_17 ( V_35 , & V_13 , & V_8 -> V_19 ) ;
F_15 ( V_35 , & V_13 , 1 ) ;
}
}
static struct V_3 * F_23 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_14 * V_38 ,
const struct V_39 * V_40 )
{
struct V_3 * V_41 ;
struct V_3 * V_8 ;
struct V_42 * V_43 ;
unsigned int V_44 = 0 ;
unsigned int V_45 ;
int V_46 ;
int V_47 ;
V_8 = V_37 -> V_48 -> V_49 ( V_2 , NULL , V_37 ) ;
if ( V_8 == NULL )
return F_24 ( - V_50 ) ;
if ( F_25 ( V_8 ) )
return V_8 ;
V_8 -> V_16 -> V_27 = * V_38 ;
V_43 = & V_8 -> V_16 -> V_51 ;
do {
V_46 = 1 ;
V_45 = 1 ;
F_26 (scan, layers, lo_linkage) {
if ( V_44 & V_45 )
goto V_20;
V_46 = 0 ;
V_41 -> V_16 = V_8 -> V_16 ;
V_47 = V_41 -> V_24 -> V_52 ( V_2 , V_41 , V_40 ) ;
if ( V_47 != 0 ) {
F_8 ( V_2 , V_8 ) ;
return F_24 ( V_47 ) ;
}
V_44 |= V_45 ;
V_20:
V_45 <<= 1 ;
}
} while ( ! V_46 );
F_7 (scan, layers, lo_linkage) {
if ( V_41 -> V_24 -> V_53 != NULL ) {
V_47 = V_41 -> V_24 -> V_53 ( V_2 , V_41 ) ;
if ( V_47 != 0 ) {
F_8 ( V_2 , V_8 ) ;
return F_24 ( V_47 ) ;
}
}
}
F_27 ( V_37 -> V_18 -> V_54 , V_55 ) ;
return V_8 ;
}
static void F_8 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_3 * V_41 ;
struct V_42 * V_43 ;
struct V_42 V_56 ;
V_10 = V_4 -> V_17 -> V_18 ;
V_43 = & V_4 -> V_16 -> V_51 ;
V_6 = F_28 ( V_10 , & V_4 -> V_16 -> V_27 ) ;
F_7 (scan, layers, lo_linkage) {
if ( V_41 -> V_24 -> V_57 != NULL )
V_41 -> V_24 -> V_57 ( V_2 , V_41 ) ;
}
F_29 ( & V_56 ) ;
F_30 ( V_43 , & V_56 ) ;
while ( ! F_5 ( & V_56 ) ) {
V_4 = F_31 ( V_56 . V_58 , struct V_3 , V_59 ) ;
F_22 ( & V_4 -> V_59 ) ;
F_4 ( V_4 -> V_24 -> V_60 != NULL ) ;
V_4 -> V_24 -> V_60 ( V_2 , V_4 ) ;
}
if ( F_32 ( & V_6 -> V_28 ) )
F_13 ( & V_6 -> V_28 ) ;
}
int F_33 ( const struct V_1 * V_2 , struct V_9 * V_61 , int V_62 )
{
struct V_7 * V_63 ;
struct V_7 * V_64 ;
struct V_5 * V_6 ;
struct V_12 V_13 ;
struct V_12 V_65 ;
struct V_42 V_66 ;
int V_67 ;
int V_68 ;
int V_69 ;
int V_70 ;
int V_71 ;
if ( F_34 ( V_72 ) )
return 0 ;
F_29 ( & V_66 ) ;
V_68 = V_61 -> V_73 ;
V_70 = ( V_62 == ~ 0 ) ? - 1 : V_62 / F_35 ( V_61 -> V_26 ) + 1 ;
V_74:
V_67 = 0 ;
F_36 (s->ls_obj_hash, &bd, i) {
if ( V_71 < V_68 )
continue;
V_69 = V_70 ;
F_37 ( V_61 -> V_26 , & V_13 , 1 ) ;
V_6 = F_10 ( V_61 -> V_26 , & V_13 ) ;
F_38 (h, temp, &bkt->lsb_lru, loh_lru) {
F_4 ( F_39 ( & V_63 -> V_23 ) == 0 ) ;
F_9 ( V_61 -> V_26 , & V_63 -> V_27 , & V_65 ) ;
F_4 ( V_13 . V_75 == V_65 . V_75 ) ;
F_17 ( V_61 -> V_26 ,
& V_65 , & V_63 -> V_19 ) ;
F_40 ( & V_63 -> V_22 , & V_66 ) ;
if ( V_67 == 0 )
V_67 = 1 ;
if ( V_62 != ~ 0 && -- V_62 == 0 )
break;
if ( V_69 > 0 && -- V_69 == 0 )
break;
}
F_15 ( V_61 -> V_26 , & V_13 , 1 ) ;
F_41 () ;
while ( ! F_5 ( & V_66 ) ) {
V_63 = F_31 ( V_66 . V_20 ,
struct V_7 , V_22 ) ;
F_22 ( & V_63 -> V_22 ) ;
F_8 ( V_2 , F_42 ( V_63 ) ) ;
F_27 ( V_61 -> V_54 , V_76 ) ;
}
if ( V_62 == 0 )
break;
}
if ( V_62 != 0 && V_67 && V_68 != 0 ) {
V_68 = 0 ;
goto V_74;
}
V_61 -> V_73 = V_71 % F_35 ( V_61 -> V_26 ) ;
return V_62 ;
}
int F_43 ( const struct V_1 * V_2 ,
void * V_77 , const char * V_78 , ... )
{
struct V_79 * V_80 = V_77 ;
struct V_81 * V_82 ;
int V_83 ;
int V_84 ;
T_1 args ;
va_start ( args , V_78 ) ;
V_82 = F_44 ( & V_2 -> V_85 , & V_86 ) ;
F_4 ( V_82 != NULL ) ;
V_83 = strlen ( V_82 -> V_87 ) ;
V_84 = V_78 [ strlen ( V_78 ) - 1 ] == '\n' ;
vsnprintf ( V_82 -> V_87 + V_83 ,
F_45 ( V_82 -> V_87 ) - V_83 , V_78 , args ) ;
if ( V_84 ) {
if ( F_46 ( V_80 -> V_88 , V_80 -> V_89 ) )
F_47 ( V_80 , L_1 , V_82 -> V_87 ) ;
V_82 -> V_87 [ 0 ] = 0 ;
}
va_end ( args ) ;
return 0 ;
}
void F_48 ( const struct V_1 * V_2 , void * V_77 ,
T_2 V_90 ,
const struct V_7 * V_91 )
{
(* V_90)( V_2 , V_77 , L_2 V_92 L_3 ,
V_91 , V_91 -> V_32 , F_39 ( & V_91 -> V_23 ) ,
F_49 ( & V_91 -> V_27 ) ,
F_50 ( & V_91 -> V_19 ) ? L_4 : L_5 ,
F_5 ( (struct V_42 * ) & V_91 -> V_22 ) ? \
L_4 : L_6 ,
V_91 -> V_93 & V_94 ? L_7 : L_4 ) ;
}
void F_51 ( const struct V_1 * V_2 , void * V_77 ,
T_2 V_90 , const struct V_3 * V_4 )
{
static const char V_95 [] = L_8 ;
struct V_7 * V_8 ;
int V_96 = 4 ;
V_8 = V_4 -> V_16 ;
F_48 ( V_2 , V_77 , V_90 , V_8 ) ;
(* V_90)( V_2 , V_77 , L_9 ) ;
F_26 (o, &top->loh_layers, lo_linkage) {
(* V_90)( V_2 , V_77 , L_10 , V_96 , V_96 , V_95 ,
V_4 -> V_17 -> V_97 -> V_98 , V_4 ) ;
if ( V_4 -> V_24 -> V_99 != NULL )
(* V_4 -> V_24 -> V_99 )( V_2 , V_77 , V_90 , V_4 ) ;
(* V_90)( V_2 , V_77 , L_11 ) ;
}
(* V_90)( V_2 , V_77 , L_12 , V_8 ) ;
}
int F_52 ( const struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = V_4 -> V_16 ;
F_26 (o, &top->loh_layers, lo_linkage) {
if ( V_4 -> V_24 -> V_100 != NULL &&
! V_4 -> V_24 -> V_100 ( V_4 ) )
return 0 ;
}
return 1 ;
}
static struct V_3 * F_53 ( struct V_9 * V_61 ,
struct V_12 * V_13 ,
const struct V_14 * V_38 ,
T_3 * V_101 ,
T_4 * V_102 )
{
struct V_5 * V_6 ;
struct V_7 * V_63 ;
struct V_103 * V_104 ;
T_4 V_105 = F_54 ( V_13 ) ;
if ( * V_102 == V_105 )
return F_24 ( - V_106 ) ;
* V_102 = V_105 ;
V_6 = F_10 ( V_61 -> V_26 , V_13 ) ;
V_104 = F_55 ( V_61 -> V_26 , V_13 , ( void * ) V_38 ) ;
if ( V_104 == NULL ) {
F_27 ( V_61 -> V_54 , V_107 ) ;
return F_24 ( - V_106 ) ;
}
V_63 = F_31 ( V_104 , struct V_7 , V_19 ) ;
if ( F_56 ( ! F_12 ( V_63 ) ) ) {
F_57 ( V_61 -> V_26 , V_104 ) ;
F_27 ( V_61 -> V_54 , V_108 ) ;
F_22 ( & V_63 -> V_22 ) ;
return F_42 ( V_63 ) ;
}
F_58 ( V_101 ) ;
F_59 ( & V_6 -> V_28 , V_101 ) ;
F_60 ( V_109 ) ;
F_27 ( V_61 -> V_54 , V_110 ) ;
return F_24 ( - V_111 ) ;
}
struct V_3 * F_61 ( const struct V_1 * V_2 ,
struct V_36 * V_37 , const struct V_14 * V_38 ,
const struct V_39 * V_40 )
{
return F_62 ( V_2 , V_37 -> V_18 -> V_112 , V_38 , V_40 ) ;
}
static struct V_3 * F_63 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_14 * V_38 ,
const struct V_39 * V_40 )
{
struct V_3 * V_4 ;
struct V_34 * V_113 ;
struct V_12 V_13 ;
struct V_5 * V_6 ;
V_4 = F_23 ( V_2 , V_37 , V_38 , V_40 ) ;
if ( F_64 ( F_25 ( V_4 ) ) )
return V_4 ;
V_113 = V_37 -> V_18 -> V_26 ;
F_21 ( V_113 , ( void * ) V_38 , & V_13 , 1 ) ;
V_6 = F_10 ( V_113 , & V_13 ) ;
F_65 ( V_113 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
V_6 -> V_29 ++ ;
F_15 ( V_113 , & V_13 , 1 ) ;
return V_4 ;
}
static struct V_3 * F_66 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_14 * V_38 ,
const struct V_39 * V_40 ,
T_3 * V_101 )
{
struct V_3 * V_4 ;
struct V_3 * V_114 ;
struct V_9 * V_61 ;
struct V_34 * V_113 ;
struct V_12 V_13 ;
T_4 V_102 = 0 ;
if ( V_40 != NULL && V_40 -> V_115 & V_116 )
return F_63 ( V_2 , V_37 , V_38 , V_40 ) ;
V_61 = V_37 -> V_18 ;
V_113 = V_61 -> V_26 ;
F_21 ( V_113 , ( void * ) V_38 , & V_13 , 1 ) ;
V_4 = F_53 ( V_61 , & V_13 , V_38 , V_101 , & V_102 ) ;
F_15 ( V_113 , & V_13 , 1 ) ;
if ( ! F_25 ( V_4 ) || F_67 ( V_4 ) != - V_106 )
return V_4 ;
V_4 = F_23 ( V_2 , V_37 , V_38 , V_40 ) ;
if ( F_64 ( F_25 ( V_4 ) ) )
return V_4 ;
F_4 ( F_68 ( F_2 ( V_4 ) , V_38 ) ) ;
F_37 ( V_113 , & V_13 , 1 ) ;
V_114 = F_53 ( V_61 , & V_13 , V_38 , V_101 , & V_102 ) ;
if ( F_56 ( F_25 ( V_114 ) && F_67 ( V_114 ) == - V_106 ) ) {
struct V_5 * V_6 ;
V_6 = F_10 ( V_113 , & V_13 ) ;
F_65 ( V_113 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
V_6 -> V_29 ++ ;
F_15 ( V_113 , & V_13 , 1 ) ;
return V_4 ;
}
F_27 ( V_61 -> V_54 , V_117 ) ;
F_15 ( V_113 , & V_13 , 1 ) ;
F_8 ( V_2 , V_4 ) ;
return V_114 ;
}
struct V_3 * F_62 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_14 * V_38 ,
const struct V_39 * V_40 )
{
struct V_5 * V_6 ;
struct V_3 * V_118 ;
T_3 V_119 ;
while ( 1 ) {
V_118 = F_66 ( V_2 , V_37 , V_38 , V_40 , & V_119 ) ;
if ( V_118 != F_24 ( - V_111 ) )
return V_118 ;
F_69 ( & V_119 , V_109 ) ;
V_6 = F_28 ( V_37 -> V_18 , ( void * ) V_38 ) ;
F_70 ( & V_6 -> V_28 , & V_119 ) ;
}
}
struct V_3 * F_71 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_14 * V_38 ,
const struct V_39 * V_40 )
{
struct V_3 * V_8 ;
struct V_3 * V_118 ;
V_8 = F_61 ( V_2 , V_37 , V_38 , V_40 ) ;
if ( ! F_25 ( V_8 ) ) {
V_118 = F_72 ( V_8 -> V_16 , V_37 -> V_97 ) ;
if ( V_118 == NULL )
F_1 ( V_2 , V_8 ) ;
} else
V_118 = V_8 ;
return V_118 ;
}
int F_73 ( struct V_120 * V_121 )
{
int V_47 = 0 ;
F_29 ( & V_121 -> V_122 ) ;
if ( V_121 -> V_123 -> V_124 )
V_47 = V_121 -> V_123 -> V_124 ( V_121 ) ;
if ( V_47 == 0 )
F_74 ( & V_121 -> V_122 , & V_125 ) ;
return V_47 ;
}
void F_75 ( struct V_120 * V_121 )
{
F_22 ( & V_121 -> V_122 ) ;
if ( V_121 -> V_123 -> V_126 )
V_121 -> V_123 -> V_126 ( V_121 ) ;
}
void F_76 ( void )
{
struct V_120 * V_121 ;
F_26 (ldt, &lu_device_types, ldt_linkage) {
if ( V_121 -> V_127 == 0 && V_121 -> V_123 -> V_128 )
V_121 -> V_123 -> V_128 ( V_121 ) ;
}
}
static int
F_77 ( struct V_34 * V_113 , struct V_12 * V_13 ,
struct V_103 * V_104 , void * V_129 )
{
struct V_130 * V_131 = (struct V_130 * ) V_129 ;
struct V_7 * V_63 ;
V_63 = F_78 ( V_104 , struct V_7 , V_19 ) ;
if ( ! F_5 ( & V_63 -> V_51 ) ) {
const struct V_3 * V_4 ;
V_4 = F_42 ( V_63 ) ;
F_51 ( V_131 -> V_132 , V_131 -> V_133 ,
V_131 -> V_134 , V_4 ) ;
} else {
F_48 ( V_131 -> V_132 , V_131 -> V_133 ,
V_131 -> V_134 , V_63 ) ;
}
return 0 ;
}
void F_79 ( const struct V_1 * V_2 , struct V_9 * V_61 , void * V_77 ,
T_2 V_90 )
{
struct V_130 V_131 = {
. V_132 = (struct V_1 * ) V_2 ,
. V_133 = V_77 ,
. V_134 = V_90 ,
} ;
F_80 ( V_61 -> V_26 , F_77 , & V_131 ) ;
}
static int F_81 ( void )
{
unsigned long V_135 ;
int V_136 ;
V_135 = V_137 ;
#if V_138 == 32
if ( V_135 > 1 << ( 30 - V_139 ) )
V_135 = 1 << ( 30 - V_139 ) * 3 / 4 ;
#endif
if ( V_140 == 0 || V_140 > V_141 ) {
F_82 ( L_13
L_14 ,
V_140 , V_141 ,
V_142 ) ;
V_140 = V_142 ;
}
V_135 = V_135 / 100 * V_140 *
( V_143 / 1024 ) ;
for ( V_136 = 1 ; ( 1 << V_136 ) < V_135 ; ++ V_136 ) {
;
}
return V_136 ;
}
static unsigned F_83 ( struct V_34 * V_113 ,
const void * V_82 , unsigned V_144 )
{
struct V_14 * V_15 = (struct V_14 * ) V_82 ;
T_5 V_145 ;
V_145 = F_84 ( V_15 ) ;
V_145 += ( V_145 >> 4 ) + ( V_145 << 12 ) ;
V_145 = F_85 ( V_145 , V_113 -> V_146 ) ;
V_145 -= F_85 ( ( unsigned long ) V_113 , F_86 ( V_15 ) % 11 + 3 ) ;
V_145 <<= V_113 -> V_147 - V_113 -> V_146 ;
V_145 |= ( F_87 ( V_15 ) + F_86 ( V_15 ) ) & ( F_35 ( V_113 ) - 1 ) ;
return V_145 & V_144 ;
}
static void * F_88 ( struct V_103 * V_104 )
{
return F_78 ( V_104 , struct V_7 , V_19 ) ;
}
static void * F_89 ( struct V_103 * V_104 )
{
struct V_7 * V_63 ;
V_63 = F_78 ( V_104 , struct V_7 , V_19 ) ;
return & V_63 -> V_27 ;
}
static int F_90 ( const void * V_82 , struct V_103 * V_104 )
{
struct V_7 * V_63 ;
V_63 = F_78 ( V_104 , struct V_7 , V_19 ) ;
return F_68 ( & V_63 -> V_27 , (struct V_14 * ) V_82 ) ;
}
static void F_91 ( struct V_34 * V_113 , struct V_103 * V_104 )
{
struct V_7 * V_63 ;
V_63 = F_78 ( V_104 , struct V_7 , V_19 ) ;
if ( F_92 ( 1 , & V_63 -> V_23 ) == 1 ) {
struct V_5 * V_6 ;
struct V_12 V_13 ;
F_9 ( V_113 , & V_63 -> V_27 , & V_13 ) ;
V_6 = F_10 ( V_113 , & V_13 ) ;
V_6 -> V_29 ++ ;
}
}
static void F_93 ( struct V_34 * V_113 , struct V_103 * V_104 )
{
F_94 () ;
}
void F_95 ( struct V_9 * V_61 , struct V_36 * V_148 )
{
F_96 ( & V_61 -> V_149 ) ;
if ( F_5 ( & V_148 -> V_150 ) )
F_74 ( & V_148 -> V_150 , & V_61 -> V_151 ) ;
F_97 ( & V_61 -> V_149 ) ;
}
void F_98 ( struct V_9 * V_61 , struct V_36 * V_148 )
{
F_96 ( & V_61 -> V_149 ) ;
F_22 ( & V_148 -> V_150 ) ;
F_97 ( & V_61 -> V_149 ) ;
}
int F_99 ( struct V_9 * V_61 , struct V_36 * V_8 )
{
struct V_5 * V_6 ;
struct V_12 V_13 ;
char V_152 [ 16 ] ;
int V_136 ;
int V_71 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_136 = F_81 () ;
snprintf ( V_152 , 16 , L_15 , V_8 -> V_97 -> V_98 ) ;
for ( V_136 = F_100 ( F_101 ( V_153 , V_136 ) , V_154 ) ;
V_136 >= V_153 ; V_136 -- ) {
V_61 -> V_26 = F_102 ( V_152 , V_136 , V_136 ,
V_136 - V_155 ,
sizeof( * V_6 ) , 0 , 0 ,
& V_156 ,
V_157 |
V_158 |
V_159 |
V_160 ) ;
if ( V_61 -> V_26 != NULL )
break;
}
if ( V_61 -> V_26 == NULL ) {
F_103 ( L_16 , V_136 ) ;
return - V_50 ;
}
F_36 (s->ls_obj_hash, &bd, i) {
V_6 = F_10 ( V_61 -> V_26 , & V_13 ) ;
F_29 ( & V_6 -> V_30 ) ;
F_104 ( & V_6 -> V_28 ) ;
}
V_61 -> V_54 = F_105 ( V_161 , 0 ) ;
if ( V_61 -> V_54 == NULL ) {
F_106 ( V_61 -> V_26 ) ;
V_61 -> V_26 = NULL ;
return - V_50 ;
}
F_107 ( V_61 -> V_54 , V_55 ,
0 , L_17 , L_17 ) ;
F_107 ( V_61 -> V_54 , V_108 ,
0 , L_18 , L_18 ) ;
F_107 ( V_61 -> V_54 , V_107 ,
0 , L_19 , L_19 ) ;
F_107 ( V_61 -> V_54 , V_117 ,
0 , L_20 , L_20 ) ;
F_107 ( V_61 -> V_54 , V_110 ,
0 , L_21 , L_21 ) ;
F_107 ( V_61 -> V_54 , V_76 ,
0 , L_22 , L_22 ) ;
F_29 ( & V_61 -> V_162 ) ;
V_61 -> V_112 = V_8 ;
V_8 -> V_18 = V_61 ;
F_108 ( V_8 ) ;
F_109 ( & V_8 -> V_163 , L_23 , V_61 ) ;
F_29 ( & V_61 -> V_151 ) ;
F_110 ( & V_61 -> V_149 ) ;
F_95 ( V_61 , V_8 ) ;
return 0 ;
}
void F_111 ( struct V_9 * V_61 )
{
F_112 ( & V_164 ) ;
F_22 ( & V_61 -> V_162 ) ;
F_113 ( & V_164 ) ;
if ( V_61 -> V_26 != NULL ) {
F_106 ( V_61 -> V_26 ) ;
V_61 -> V_26 = NULL ;
}
if ( V_61 -> V_112 != NULL ) {
V_61 -> V_112 -> V_18 = NULL ;
F_114 ( & V_61 -> V_112 -> V_163 , L_23 , V_61 ) ;
F_115 ( V_61 -> V_112 ) ;
V_61 -> V_112 = NULL ;
}
if ( V_61 -> V_54 != NULL )
F_116 ( & V_61 -> V_54 ) ;
}
int F_117 ( struct V_9 * V_61 )
{
int V_47 ;
F_112 ( & V_164 ) ;
V_47 = F_118 ( & V_165 . V_85 ) ;
if ( V_47 == 0 )
F_74 ( & V_61 -> V_162 , & V_166 ) ;
F_113 ( & V_164 ) ;
return V_47 ;
}
void F_108 ( struct V_36 * V_148 )
{
F_119 ( & V_148 -> V_167 ) ;
}
void F_115 ( struct V_36 * V_148 )
{
F_4 ( F_39 ( & V_148 -> V_167 ) > 0 ) ;
F_120 ( & V_148 -> V_167 ) ;
}
int F_121 ( struct V_36 * V_148 , struct V_120 * V_168 )
{
if ( V_168 -> V_127 ++ == 0 && V_168 -> V_123 -> V_169 != NULL )
V_168 -> V_123 -> V_169 ( V_168 ) ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
F_122 ( & V_148 -> V_167 , 0 ) ;
V_148 -> V_97 = V_168 ;
F_123 ( & V_148 -> V_163 ) ;
F_29 ( & V_148 -> V_150 ) ;
return 0 ;
}
void F_124 ( struct V_36 * V_148 )
{
struct V_120 * V_168 ;
V_168 = V_148 -> V_97 ;
if ( V_148 -> V_170 != NULL ) {
V_148 -> V_170 -> V_171 = NULL ;
V_148 -> V_170 = NULL ;
}
F_125 ( & V_148 -> V_163 ) ;
F_126 ( F_39 ( & V_148 -> V_167 ) == 0 ,
L_24 , F_39 ( & V_148 -> V_167 ) ) ;
F_4 ( V_168 -> V_127 > 0 ) ;
if ( -- V_168 -> V_127 == 0 && V_168 -> V_123 -> V_128 != NULL )
V_168 -> V_123 -> V_128 ( V_168 ) ;
}
int F_127 ( struct V_3 * V_4 , struct V_7 * V_63 ,
struct V_36 * V_148 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_16 = V_63 ;
V_4 -> V_17 = V_148 ;
F_108 ( V_148 ) ;
F_128 ( & V_148 -> V_163 , & V_4 -> V_172 , L_25 , V_4 ) ;
F_29 ( & V_4 -> V_59 ) ;
return 0 ;
}
void F_129 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_17 ;
F_4 ( F_5 ( & V_4 -> V_59 ) ) ;
if ( V_37 != NULL ) {
F_130 ( & V_37 -> V_163 , & V_4 -> V_172 ,
L_25 , V_4 ) ;
F_115 ( V_37 ) ;
V_4 -> V_17 = NULL ;
}
}
void F_131 ( struct V_7 * V_63 , struct V_3 * V_4 )
{
F_40 ( & V_4 -> V_59 , & V_63 -> V_51 ) ;
}
void F_132 ( struct V_3 * V_173 , struct V_3 * V_4 )
{
F_40 ( & V_4 -> V_59 , & V_173 -> V_59 ) ;
}
int F_133 ( struct V_7 * V_63 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
F_122 ( & V_63 -> V_23 , 1 ) ;
F_134 ( & V_63 -> V_19 ) ;
F_29 ( & V_63 -> V_22 ) ;
F_29 ( & V_63 -> V_51 ) ;
F_123 ( & V_63 -> V_174 ) ;
return 0 ;
}
void F_135 ( struct V_7 * V_63 )
{
F_4 ( F_5 ( & V_63 -> V_51 ) ) ;
F_4 ( F_5 ( & V_63 -> V_22 ) ) ;
F_4 ( F_50 ( & V_63 -> V_19 ) ) ;
F_125 ( & V_63 -> V_174 ) ;
}
struct V_3 * F_72 ( struct V_7 * V_63 ,
const struct V_120 * V_175 )
{
struct V_3 * V_4 ;
F_26 (o, &h->loh_layers, lo_linkage) {
if ( V_4 -> V_17 -> V_97 == V_175 )
return V_4 ;
}
return NULL ;
}
void F_136 ( const struct V_1 * V_2 , struct V_36 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_18 ;
struct V_36 * V_41 ;
struct V_36 * V_20 ;
F_33 ( V_2 , V_10 , ~ 0 ) ;
for ( V_41 = V_8 ; V_41 != NULL ; V_41 = V_20 ) {
V_20 = V_41 -> V_97 -> V_123 -> V_176 ( V_2 , V_41 ) ;
F_114 ( & V_41 -> V_163 , L_26 , & F_99 ) ;
F_115 ( V_41 ) ;
}
F_33 ( V_2 , V_10 , ~ 0 ) ;
for ( V_41 = V_8 ; V_41 != NULL ; V_41 = V_20 ) {
const struct V_120 * V_121 = V_41 -> V_97 ;
struct V_177 * type ;
V_20 = V_121 -> V_123 -> V_178 ( V_2 , V_41 ) ;
type = V_121 -> V_179 ;
if ( type != NULL ) {
type -> V_180 -- ;
F_137 ( type ) ;
}
}
}
int F_138 ( struct V_181 * V_82 )
{
int V_47 ;
int V_71 ;
F_4 ( V_82 -> V_182 != NULL ) ;
F_4 ( V_82 -> V_183 != NULL ) ;
F_4 ( V_82 -> V_184 != 0 ) ;
V_47 = - V_185 ;
F_96 ( & V_186 ) ;
for ( V_71 = 0 ; V_71 < F_45 ( V_187 ) ; ++ V_71 ) {
if ( V_187 [ V_71 ] == NULL ) {
V_82 -> V_188 = V_71 ;
F_122 ( & V_82 -> V_189 , 1 ) ;
V_187 [ V_71 ] = V_82 ;
F_123 ( & V_82 -> V_190 ) ;
V_47 = 0 ;
++ V_191 ;
break;
}
}
F_97 ( & V_186 ) ;
return V_47 ;
}
static void F_139 ( struct V_192 * V_193 , int V_194 )
{
if ( V_193 -> V_195 != NULL && V_193 -> V_195 [ V_194 ] != NULL ) {
struct V_181 * V_82 ;
V_82 = V_187 [ V_194 ] ;
F_4 ( V_82 != NULL ) ;
F_4 ( V_82 -> V_183 != NULL ) ;
F_4 ( F_39 ( & V_82 -> V_189 ) > 1 ) ;
V_82 -> V_183 ( V_193 , V_82 , V_193 -> V_195 [ V_194 ] ) ;
F_114 ( & V_82 -> V_190 , L_27 , V_193 ) ;
F_120 ( & V_82 -> V_189 ) ;
if ( ( V_193 -> V_196 & V_197 ) == 0 ) {
#ifdef F_140
F_141 ( F_142 ( V_82 -> V_198 ) > 0 ) ;
#endif
F_143 ( V_82 -> V_198 ) ;
}
V_193 -> V_195 [ V_194 ] = NULL ;
}
}
void F_144 ( struct V_181 * V_82 )
{
F_4 ( F_39 ( & V_82 -> V_189 ) >= 1 ) ;
F_141 ( 0 <= V_82 -> V_188 && V_82 -> V_188 < F_45 ( V_187 ) ) ;
F_145 ( V_82 ) ;
++ V_191 ;
F_96 ( & V_186 ) ;
F_139 ( & V_165 . V_85 , V_82 -> V_188 ) ;
if ( V_187 [ V_82 -> V_188 ] ) {
V_187 [ V_82 -> V_188 ] = NULL ;
F_125 ( & V_82 -> V_190 ) ;
}
F_97 ( & V_186 ) ;
F_126 ( F_39 ( & V_82 -> V_189 ) == 1 ,
L_28 ,
F_39 ( & V_82 -> V_189 ) ) ;
}
int F_146 ( struct V_181 * V_199 , ... )
{
struct V_181 * V_82 = V_199 ;
T_1 args ;
int V_47 ;
va_start ( args , V_199 ) ;
do {
V_47 = F_138 ( V_82 ) ;
if ( V_47 )
break;
V_82 = va_arg ( args , struct V_181 * ) ;
} while ( V_82 != NULL );
va_end ( args ) ;
if ( V_47 != 0 ) {
va_start ( args , V_199 ) ;
while ( V_199 != V_82 ) {
F_144 ( V_199 ) ;
V_199 = va_arg ( args , struct V_181 * ) ;
}
va_end ( args ) ;
}
return V_47 ;
}
void F_147 ( struct V_181 * V_199 , ... )
{
T_1 args ;
va_start ( args , V_199 ) ;
do {
F_144 ( V_199 ) ;
V_199 = va_arg ( args , struct V_181 * ) ;
} while ( V_199 != NULL );
va_end ( args ) ;
}
void F_148 ( struct V_181 * V_199 , ... )
{
T_1 args ;
va_start ( args , V_199 ) ;
do {
F_149 ( V_199 ) ;
V_199 = va_arg ( args , struct V_181 * ) ;
} while ( V_199 != NULL );
va_end ( args ) ;
}
void F_150 ( struct V_181 * V_199 , ... )
{
T_1 args ;
va_start ( args , V_199 ) ;
do {
F_145 ( V_199 ) ;
V_199 = va_arg ( args , struct V_181 * ) ;
} while ( V_199 != NULL );
va_end ( args ) ;
}
void * F_44 ( const struct V_192 * V_193 ,
const struct V_181 * V_82 )
{
F_141 ( V_193 -> V_200 == V_201 ) ;
F_141 ( 0 <= V_82 -> V_188 && V_82 -> V_188 < F_45 ( V_187 ) ) ;
F_4 ( V_187 [ V_82 -> V_188 ] == V_82 ) ;
return V_193 -> V_195 [ V_82 -> V_188 ] ;
}
void F_145 ( struct V_181 * V_82 )
{
struct V_192 * V_193 ;
if ( ! ( V_82 -> V_184 & V_202 ) ) {
V_82 -> V_184 |= V_202 ;
F_96 ( & V_186 ) ;
F_26 (ctx, &lu_context_remembered,
lc_remember)
F_139 ( V_193 , V_82 -> V_188 ) ;
F_97 ( & V_186 ) ;
++ V_191 ;
}
}
void F_149 ( struct V_181 * V_82 )
{
V_82 -> V_184 &= ~ V_202 ;
++ V_191 ;
}
static void F_151 ( struct V_192 * V_193 )
{
int V_71 ;
if ( V_193 -> V_195 == NULL )
return;
for ( V_71 = 0 ; V_71 < F_45 ( V_187 ) ; ++ V_71 )
F_139 ( V_193 , V_71 ) ;
F_152 ( V_193 -> V_195 , F_45 ( V_187 ) * sizeof( V_193 -> V_195 [ 0 ] ) ) ;
V_193 -> V_195 = NULL ;
}
static int F_153 ( struct V_192 * V_193 )
{
int V_71 ;
F_141 ( V_193 -> V_195 != NULL ) ;
for ( V_71 = 0 ; V_71 < F_45 ( V_187 ) ; ++ V_71 ) {
struct V_181 * V_82 ;
V_82 = V_187 [ V_71 ] ;
if ( V_193 -> V_195 [ V_71 ] == NULL && V_82 != NULL &&
( V_82 -> V_184 & V_193 -> V_196 ) &&
! ( V_82 -> V_184 & V_202 ) ) {
void * V_203 ;
F_141 ( V_82 -> V_182 != NULL ) ;
F_141 ( V_82 -> V_188 == V_71 ) ;
V_203 = V_82 -> V_182 ( V_193 , V_82 ) ;
if ( F_64 ( F_25 ( V_203 ) ) )
return F_67 ( V_203 ) ;
if ( ! ( V_193 -> V_196 & V_197 ) )
F_154 ( V_82 -> V_198 ) ;
F_155 ( & V_82 -> V_190 , L_27 , V_193 ) ;
F_119 ( & V_82 -> V_189 ) ;
V_193 -> V_195 [ V_71 ] = V_203 ;
if ( V_82 -> V_204 != NULL )
V_193 -> V_196 |= V_205 ;
}
V_193 -> V_206 = V_191 ;
}
return 0 ;
}
static int F_156 ( struct V_192 * V_193 )
{
F_157 ( V_193 -> V_195 ,
F_45 ( V_187 ) * sizeof( V_193 -> V_195 [ 0 ] ) ) ;
if ( F_56 ( V_193 -> V_195 != NULL ) )
return F_153 ( V_193 ) ;
return - V_50 ;
}
int F_158 ( struct V_192 * V_193 , T_5 V_207 )
{
int V_208 ;
memset ( V_193 , 0 , sizeof( * V_193 ) ) ;
V_193 -> V_200 = V_209 ;
V_193 -> V_196 = V_207 ;
if ( V_207 & V_210 ) {
F_96 ( & V_186 ) ;
F_74 ( & V_193 -> V_211 , & V_212 ) ;
F_97 ( & V_186 ) ;
} else {
F_29 ( & V_193 -> V_211 ) ;
}
V_208 = F_156 ( V_193 ) ;
if ( V_208 != 0 )
F_159 ( V_193 ) ;
return V_208 ;
}
void F_159 ( struct V_192 * V_193 )
{
F_141 ( V_193 -> V_200 == V_209 || V_193 -> V_200 == V_213 ) ;
V_193 -> V_200 = V_214 ;
if ( ( V_193 -> V_196 & V_210 ) == 0 ) {
F_4 ( F_5 ( & V_193 -> V_211 ) ) ;
F_151 ( V_193 ) ;
} else {
F_96 ( & V_186 ) ;
F_151 ( V_193 ) ;
F_22 ( & V_193 -> V_211 ) ;
F_97 ( & V_186 ) ;
}
}
void F_160 ( struct V_192 * V_193 )
{
F_141 ( V_193 -> V_200 == V_209 || V_193 -> V_200 == V_213 ) ;
V_193 -> V_200 = V_201 ;
}
void F_161 ( struct V_192 * V_193 )
{
int V_71 ;
F_141 ( V_193 -> V_200 == V_201 ) ;
V_193 -> V_200 = V_213 ;
if ( V_193 -> V_196 & V_205 && V_193 -> V_195 != NULL ) {
for ( V_71 = 0 ; V_71 < F_45 ( V_187 ) ; ++ V_71 ) {
if ( V_193 -> V_195 [ V_71 ] != NULL ) {
struct V_181 * V_82 ;
V_82 = V_187 [ V_71 ] ;
F_4 ( V_82 != NULL ) ;
if ( V_82 -> V_204 != NULL )
V_82 -> V_204 ( V_193 ,
V_82 , V_193 -> V_195 [ V_71 ] ) ;
}
}
}
}
int F_118 ( struct V_192 * V_193 )
{
return F_56 ( V_193 -> V_206 == V_191 ) ? 0 : F_153 ( V_193 ) ;
}
void F_162 ( T_5 V_207 )
{
F_96 ( & V_186 ) ;
V_215 |= V_207 ;
V_191 ++ ;
F_97 ( & V_186 ) ;
}
void F_163 ( T_5 V_207 )
{
F_96 ( & V_186 ) ;
V_215 &= ~ V_207 ;
V_191 ++ ;
F_97 ( & V_186 ) ;
}
void F_164 ( T_5 V_207 )
{
F_96 ( & V_186 ) ;
V_216 |= V_207 ;
V_191 ++ ;
F_97 ( & V_186 ) ;
}
void F_165 ( T_5 V_207 )
{
F_96 ( & V_186 ) ;
V_216 &= ~ V_207 ;
V_191 ++ ;
F_97 ( & V_186 ) ;
}
int F_166 ( struct V_1 * V_2 , T_5 V_207 )
{
int V_47 ;
V_2 -> V_217 = NULL ;
V_47 = F_158 ( & V_2 -> V_85 , V_207 ) ;
if ( F_56 ( V_47 == 0 ) )
F_160 ( & V_2 -> V_85 ) ;
return V_47 ;
}
void F_167 ( struct V_1 * V_2 )
{
F_161 ( & V_2 -> V_85 ) ;
F_159 ( & V_2 -> V_85 ) ;
V_2 -> V_217 = NULL ;
}
int F_168 ( struct V_1 * V_2 )
{
int V_47 ;
V_47 = F_118 ( & V_2 -> V_85 ) ;
if ( V_47 == 0 && V_2 -> V_217 != NULL )
V_47 = F_118 ( V_2 -> V_217 ) ;
return V_47 ;
}
int F_169 ( struct V_1 * V_2 , T_5 V_218 ,
T_5 V_219 )
{
int V_47 ;
if ( ( V_2 -> V_85 . V_196 & V_218 ) != V_218 ) {
V_2 -> V_85 . V_206 = 0 ;
V_2 -> V_85 . V_196 |= V_218 ;
}
if ( V_2 -> V_217 && ( V_2 -> V_217 -> V_196 & V_219 ) != V_219 ) {
V_2 -> V_217 -> V_206 = 0 ;
V_2 -> V_217 -> V_196 |= V_219 ;
}
V_47 = F_168 ( V_2 ) ;
return V_47 ;
}
static void F_170 ( struct V_34 * V_113 ,
T_6 * V_220 , int V_221 )
{
struct V_12 V_13 ;
int V_71 ;
F_36 (hs, &bd, i) {
struct V_5 * V_6 = F_10 ( V_113 , & V_13 ) ;
struct V_222 * V_223 ;
F_37 ( V_113 , & V_13 , 1 ) ;
V_220 -> V_224 += V_6 -> V_29 ;
V_220 -> V_225 += F_171 ( & V_13 ) ;
V_220 -> V_226 = F_101 ( ( int ) V_220 -> V_226 ,
F_172 ( & V_13 ) ) ;
if ( ! V_221 ) {
F_15 ( V_113 , & V_13 , 1 ) ;
continue;
}
F_173 (hs, &bd, hhead) {
if ( ! F_174 ( V_223 ) )
V_220 -> V_227 ++ ;
}
F_15 ( V_113 , & V_13 , 1 ) ;
}
}
static unsigned long F_175 ( struct V_228 * V_229 ,
struct V_230 * V_231 )
{
T_6 V_220 ;
struct V_9 * V_61 ;
struct V_9 * V_232 ;
unsigned long V_233 = 0 ;
if ( ! ( V_231 -> V_234 & V_235 ) )
return 0 ;
F_112 ( & V_164 ) ;
F_38 (s, tmp, &lu_sites, ls_linkage) {
memset ( & V_220 , 0 , sizeof( V_220 ) ) ;
F_170 ( V_61 -> V_26 , & V_220 , 0 ) ;
V_233 += V_220 . V_225 - V_220 . V_224 ;
}
F_113 ( & V_164 ) ;
V_233 = ( V_233 / 100 ) * V_236 ;
F_176 ( V_237 , L_29 , V_233 ) ;
return V_233 ;
}
static unsigned long F_177 ( struct V_228 * V_229 ,
struct V_230 * V_231 )
{
struct V_9 * V_61 ;
struct V_9 * V_232 ;
unsigned long V_238 = V_231 -> V_239 , V_240 = 0 ;
F_178 ( V_56 ) ;
if ( ! ( V_231 -> V_234 & V_235 ) )
return V_241 ;
F_112 ( & V_164 ) ;
F_38 (s, tmp, &lu_sites, ls_linkage) {
V_240 = F_33 ( & V_165 , V_61 , V_238 ) ;
V_238 -= V_240 ;
F_179 ( & V_61 -> V_162 , & V_56 ) ;
}
F_180 ( & V_56 , V_166 . V_58 ) ;
F_113 ( & V_164 ) ;
return V_231 -> V_239 - V_238 ;
}
int F_181 ( const struct V_1 * V_2 ,
void * V_242 , const char * V_78 , ... )
{
T_1 args ;
va_start ( args , V_78 ) ;
F_182 ( V_78 , args ) ;
va_end ( args ) ;
return 0 ;
}
int F_183 ( void )
{
int V_47 ;
F_176 ( V_243 , L_30 , & V_187 ) ;
V_47 = F_184 () ;
if ( V_47 != 0 )
return V_47 ;
F_185 ( & V_86 ) ;
V_47 = F_138 ( & V_86 ) ;
if ( V_47 != 0 )
return V_47 ;
F_112 ( & V_164 ) ;
V_47 = F_166 ( & V_165 , V_244 ) ;
F_113 ( & V_164 ) ;
if ( V_47 != 0 )
return V_47 ;
F_186 ( & V_245 ) ;
return V_47 ;
}
void F_187 ( void )
{
F_188 ( & V_245 ) ;
F_144 ( & V_86 ) ;
F_112 ( & V_164 ) ;
F_167 ( & V_165 ) ;
F_113 ( & V_164 ) ;
F_189 () ;
}
static T_5 F_190 ( struct V_246 * V_220 , int V_247 )
{
#ifdef F_191
struct V_248 V_249 ;
F_192 ( V_220 , V_247 , & V_249 ) ;
return ( T_5 ) V_249 . V_250 ;
#else
return 0 ;
#endif
}
int F_193 ( const struct V_9 * V_61 , struct V_251 * V_252 )
{
T_6 V_220 ;
memset ( & V_220 , 0 , sizeof( V_220 ) ) ;
F_170 ( V_61 -> V_26 , & V_220 , 1 ) ;
return F_194 ( V_252 , L_31 ,
V_220 . V_224 ,
V_220 . V_225 ,
V_220 . V_227 ,
F_195 ( V_61 -> V_26 ) ,
V_220 . V_226 ,
F_190 ( V_61 -> V_54 , V_55 ) ,
F_190 ( V_61 -> V_54 , V_108 ) ,
F_190 ( V_61 -> V_54 , V_107 ) ,
F_190 ( V_61 -> V_54 , V_117 ) ,
F_190 ( V_61 -> V_54 , V_110 ) ,
F_190 ( V_61 -> V_54 , V_76 ) ) ;
}
int F_196 ( struct V_253 * V_254 )
{
int V_47 ;
struct V_253 * V_255 = V_254 ;
for ( V_47 = 0 ; V_255 -> V_256 != NULL ; ++ V_255 ) {
* V_255 -> V_256 = F_197 ( V_255 -> V_257 ,
V_255 -> V_258 ,
0 , 0 , NULL ) ;
if ( * V_255 -> V_256 == NULL ) {
V_47 = - V_50 ;
F_198 ( V_254 ) ;
break;
}
}
return V_47 ;
}
void F_198 ( struct V_253 * V_254 )
{
for (; V_254 -> V_256 != NULL ; ++ V_254 ) {
if ( * V_254 -> V_256 != NULL ) {
F_199 ( * V_254 -> V_256 ) ;
* V_254 -> V_256 = NULL ;
}
}
}
void F_200 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_14 * V_15 )
{
struct V_9 * V_61 = V_4 -> V_17 -> V_18 ;
struct V_14 * V_259 = & V_4 -> V_16 -> V_27 ;
struct V_5 * V_6 ;
struct V_3 * V_114 ;
T_3 V_101 ;
struct V_34 * V_113 ;
struct V_12 V_13 ;
T_4 V_102 = 0 ;
F_4 ( F_3 ( V_259 ) ) ;
V_113 = V_61 -> V_26 ;
F_21 ( V_113 , ( void * ) V_15 , & V_13 , 1 ) ;
V_114 = F_53 ( V_61 , & V_13 , V_15 , & V_101 , & V_102 ) ;
F_4 ( F_25 ( V_114 ) && F_67 ( V_114 ) == - V_106 ) ;
* V_259 = * V_15 ;
V_6 = F_10 ( V_113 , & V_13 ) ;
F_65 ( V_113 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
V_6 -> V_29 ++ ;
F_15 ( V_113 , & V_13 , 1 ) ;
}
struct V_3 * F_201 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_39 * V_40 )
{
struct V_14 V_15 ;
struct V_3 * V_4 ;
F_202 ( & V_15 ) ;
V_4 = F_23 ( V_2 , V_37 , & V_15 , V_40 ) ;
return V_4 ;
}
void F_203 ( struct V_260 * V_261 )
{
F_4 ( V_261 ) ;
if ( V_261 -> V_262 ) {
F_4 ( V_261 -> V_263 > 0 ) ;
F_204 ( V_261 -> V_262 , V_261 -> V_263 ) ;
V_261 -> V_262 = NULL ;
V_261 -> V_263 = 0 ;
}
}
void F_205 ( struct V_260 * V_261 , int V_264 )
{
F_4 ( V_261 ) ;
F_4 ( V_261 -> V_262 == NULL ) ;
F_4 ( V_261 -> V_263 == 0 ) ;
F_206 ( V_261 -> V_262 , V_264 ) ;
if ( F_56 ( V_261 -> V_262 ) )
V_261 -> V_263 = V_264 ;
}
void F_207 ( struct V_260 * V_261 , int V_264 )
{
F_203 ( V_261 ) ;
F_205 ( V_261 , V_264 ) ;
}
struct V_260 * F_208 ( struct V_260 * V_261 , int V_265 )
{
if ( V_261 -> V_262 == NULL && V_261 -> V_263 == 0 )
F_205 ( V_261 , V_265 ) ;
if ( ( V_265 > V_261 -> V_263 ) && ( V_261 -> V_262 != NULL ) )
F_207 ( V_261 , V_265 ) ;
return V_261 ;
}
int F_209 ( struct V_260 * V_261 , int V_265 )
{
char * V_266 ;
if ( V_265 <= V_261 -> V_263 )
return 0 ;
F_206 ( V_266 , V_265 ) ;
if ( V_266 == NULL )
return - V_50 ;
if ( V_261 -> V_262 != NULL ) {
memcpy ( V_266 , V_261 -> V_262 , V_261 -> V_263 ) ;
F_204 ( V_261 -> V_262 , V_261 -> V_263 ) ;
}
V_261 -> V_262 = V_266 ;
V_261 -> V_263 = V_265 ;
return 0 ;
}
