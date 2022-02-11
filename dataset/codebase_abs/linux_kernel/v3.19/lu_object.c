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
F_58 ( V_101 , V_109 ) ;
F_59 ( & V_6 -> V_28 , V_101 ) ;
F_60 ( V_110 ) ;
F_27 ( V_61 -> V_54 , V_111 ) ;
return F_24 ( - V_112 ) ;
}
struct V_3 * F_61 ( const struct V_1 * V_2 ,
struct V_36 * V_37 , const struct V_14 * V_38 ,
const struct V_39 * V_40 )
{
return F_62 ( V_2 , V_37 -> V_18 -> V_113 , V_38 , V_40 ) ;
}
static struct V_3 * F_63 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_14 * V_38 ,
const struct V_39 * V_40 )
{
struct V_3 * V_4 ;
struct V_34 * V_114 ;
struct V_12 V_13 ;
struct V_5 * V_6 ;
V_4 = F_23 ( V_2 , V_37 , V_38 , V_40 ) ;
if ( F_64 ( F_25 ( V_4 ) ) )
return V_4 ;
V_114 = V_37 -> V_18 -> V_26 ;
F_21 ( V_114 , ( void * ) V_38 , & V_13 , 1 ) ;
V_6 = F_10 ( V_114 , & V_13 ) ;
F_65 ( V_114 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
V_6 -> V_29 ++ ;
F_15 ( V_114 , & V_13 , 1 ) ;
return V_4 ;
}
static struct V_3 * F_66 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_14 * V_38 ,
const struct V_39 * V_40 ,
T_3 * V_101 )
{
struct V_3 * V_4 ;
struct V_3 * V_115 ;
struct V_9 * V_61 ;
struct V_34 * V_114 ;
struct V_12 V_13 ;
T_4 V_102 = 0 ;
if ( V_40 != NULL && V_40 -> V_116 & V_117 )
return F_63 ( V_2 , V_37 , V_38 , V_40 ) ;
V_61 = V_37 -> V_18 ;
V_114 = V_61 -> V_26 ;
F_21 ( V_114 , ( void * ) V_38 , & V_13 , 1 ) ;
V_4 = F_53 ( V_61 , & V_13 , V_38 , V_101 , & V_102 ) ;
F_15 ( V_114 , & V_13 , 1 ) ;
if ( ! F_25 ( V_4 ) || F_67 ( V_4 ) != - V_106 )
return V_4 ;
V_4 = F_23 ( V_2 , V_37 , V_38 , V_40 ) ;
if ( F_64 ( F_25 ( V_4 ) ) )
return V_4 ;
F_4 ( F_68 ( F_2 ( V_4 ) , V_38 ) ) ;
F_37 ( V_114 , & V_13 , 1 ) ;
V_115 = F_53 ( V_61 , & V_13 , V_38 , V_101 , & V_102 ) ;
if ( F_56 ( F_25 ( V_115 ) && F_67 ( V_115 ) == - V_106 ) ) {
struct V_5 * V_6 ;
V_6 = F_10 ( V_114 , & V_13 ) ;
F_65 ( V_114 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
V_6 -> V_29 ++ ;
F_15 ( V_114 , & V_13 , 1 ) ;
return V_4 ;
}
F_27 ( V_61 -> V_54 , V_118 ) ;
F_15 ( V_114 , & V_13 , 1 ) ;
F_8 ( V_2 , V_4 ) ;
return V_115 ;
}
struct V_3 * F_62 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_14 * V_38 ,
const struct V_39 * V_40 )
{
struct V_5 * V_6 ;
struct V_3 * V_119 ;
T_3 V_120 ;
while ( 1 ) {
V_119 = F_66 ( V_2 , V_37 , V_38 , V_40 , & V_120 ) ;
if ( V_119 != F_24 ( - V_112 ) )
return V_119 ;
F_69 () ;
V_6 = F_28 ( V_37 -> V_18 , ( void * ) V_38 ) ;
F_70 ( & V_6 -> V_28 , & V_120 ) ;
}
}
struct V_3 * F_71 ( const struct V_1 * V_2 ,
struct V_36 * V_37 ,
const struct V_14 * V_38 ,
const struct V_39 * V_40 )
{
struct V_3 * V_8 ;
struct V_3 * V_119 ;
V_8 = F_61 ( V_2 , V_37 , V_38 , V_40 ) ;
if ( ! F_25 ( V_8 ) ) {
V_119 = F_72 ( V_8 -> V_16 , V_37 -> V_97 ) ;
if ( V_119 == NULL )
F_1 ( V_2 , V_8 ) ;
} else
V_119 = V_8 ;
return V_119 ;
}
int F_73 ( struct V_121 * V_122 )
{
int V_47 = 0 ;
F_29 ( & V_122 -> V_123 ) ;
if ( V_122 -> V_124 -> V_125 )
V_47 = V_122 -> V_124 -> V_125 ( V_122 ) ;
if ( V_47 == 0 )
F_74 ( & V_122 -> V_123 , & V_126 ) ;
return V_47 ;
}
void F_75 ( struct V_121 * V_122 )
{
F_22 ( & V_122 -> V_123 ) ;
if ( V_122 -> V_124 -> V_127 )
V_122 -> V_124 -> V_127 ( V_122 ) ;
}
void F_76 ( void )
{
struct V_121 * V_122 ;
F_26 (ldt, &lu_device_types, ldt_linkage) {
if ( V_122 -> V_128 == 0 && V_122 -> V_124 -> V_129 )
V_122 -> V_124 -> V_129 ( V_122 ) ;
}
}
static int
F_77 ( struct V_34 * V_114 , struct V_12 * V_13 ,
struct V_103 * V_104 , void * V_130 )
{
struct V_131 * V_132 = (struct V_131 * ) V_130 ;
struct V_7 * V_63 ;
V_63 = F_78 ( V_104 , struct V_7 , V_19 ) ;
if ( ! F_5 ( & V_63 -> V_51 ) ) {
const struct V_3 * V_4 ;
V_4 = F_42 ( V_63 ) ;
F_51 ( V_132 -> V_133 , V_132 -> V_134 ,
V_132 -> V_135 , V_4 ) ;
} else {
F_48 ( V_132 -> V_133 , V_132 -> V_134 ,
V_132 -> V_135 , V_63 ) ;
}
return 0 ;
}
void F_79 ( const struct V_1 * V_2 , struct V_9 * V_61 , void * V_77 ,
T_2 V_90 )
{
struct V_131 V_132 = {
. V_133 = (struct V_1 * ) V_2 ,
. V_134 = V_77 ,
. V_135 = V_90 ,
} ;
F_80 ( V_61 -> V_26 , F_77 , & V_132 ) ;
}
static int F_81 ( void )
{
unsigned long V_136 ;
int V_137 ;
V_136 = V_138 ;
#if V_139 == 32
if ( V_136 > 1 << ( 30 - V_140 ) )
V_136 = 1 << ( 30 - V_140 ) * 3 / 4 ;
#endif
if ( V_141 == 0 || V_141 > V_142 ) {
F_82 ( L_13 ,
V_141 , V_142 ,
V_143 ) ;
V_141 = V_143 ;
}
V_136 = V_136 / 100 * V_141 *
( V_144 / 1024 ) ;
for ( V_137 = 1 ; ( 1 << V_137 ) < V_136 ; ++ V_137 ) {
;
}
return V_137 ;
}
static unsigned F_83 ( struct V_34 * V_114 ,
const void * V_82 , unsigned V_145 )
{
struct V_14 * V_15 = (struct V_14 * ) V_82 ;
T_5 V_146 ;
V_146 = F_84 ( V_15 ) ;
V_146 += ( V_146 >> 4 ) + ( V_146 << 12 ) ;
V_146 = F_85 ( V_146 , V_114 -> V_147 ) ;
V_146 -= F_85 ( ( unsigned long ) V_114 , F_86 ( V_15 ) % 11 + 3 ) ;
V_146 <<= V_114 -> V_148 - V_114 -> V_147 ;
V_146 |= ( F_87 ( V_15 ) + F_86 ( V_15 ) ) & ( F_35 ( V_114 ) - 1 ) ;
return V_146 & V_145 ;
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
static void F_91 ( struct V_34 * V_114 , struct V_103 * V_104 )
{
struct V_7 * V_63 ;
V_63 = F_78 ( V_104 , struct V_7 , V_19 ) ;
if ( F_92 ( 1 , & V_63 -> V_23 ) == 1 ) {
struct V_5 * V_6 ;
struct V_12 V_13 ;
F_9 ( V_114 , & V_63 -> V_27 , & V_13 ) ;
V_6 = F_10 ( V_114 , & V_13 ) ;
V_6 -> V_29 ++ ;
}
}
static void F_93 ( struct V_34 * V_114 , struct V_103 * V_104 )
{
F_94 () ;
}
void F_95 ( struct V_9 * V_61 , struct V_36 * V_149 )
{
F_96 ( & V_61 -> V_150 ) ;
if ( F_5 ( & V_149 -> V_151 ) )
F_74 ( & V_149 -> V_151 , & V_61 -> V_152 ) ;
F_97 ( & V_61 -> V_150 ) ;
}
void F_98 ( struct V_9 * V_61 , struct V_36 * V_149 )
{
F_96 ( & V_61 -> V_150 ) ;
F_22 ( & V_149 -> V_151 ) ;
F_97 ( & V_61 -> V_150 ) ;
}
int F_99 ( struct V_9 * V_61 , struct V_36 * V_8 )
{
struct V_5 * V_6 ;
struct V_12 V_13 ;
char V_153 [ 16 ] ;
int V_137 ;
int V_71 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_137 = F_81 () ;
snprintf ( V_153 , 16 , L_14 , V_8 -> V_97 -> V_98 ) ;
for ( V_137 = F_100 ( F_101 ( V_154 , V_137 ) , V_155 ) ;
V_137 >= V_154 ; V_137 -- ) {
V_61 -> V_26 = F_102 ( V_153 , V_137 , V_137 ,
V_137 - V_156 ,
sizeof( * V_6 ) , 0 , 0 ,
& V_157 ,
V_158 |
V_159 |
V_160 |
V_161 ) ;
if ( V_61 -> V_26 != NULL )
break;
}
if ( V_61 -> V_26 == NULL ) {
F_103 ( L_15 , V_137 ) ;
return - V_50 ;
}
F_36 (s->ls_obj_hash, &bd, i) {
V_6 = F_10 ( V_61 -> V_26 , & V_13 ) ;
F_29 ( & V_6 -> V_30 ) ;
F_104 ( & V_6 -> V_28 ) ;
}
V_61 -> V_54 = F_105 ( V_162 , 0 ) ;
if ( V_61 -> V_54 == NULL ) {
F_106 ( V_61 -> V_26 ) ;
V_61 -> V_26 = NULL ;
return - V_50 ;
}
F_107 ( V_61 -> V_54 , V_55 ,
0 , L_16 , L_16 ) ;
F_107 ( V_61 -> V_54 , V_108 ,
0 , L_17 , L_17 ) ;
F_107 ( V_61 -> V_54 , V_107 ,
0 , L_18 , L_18 ) ;
F_107 ( V_61 -> V_54 , V_118 ,
0 , L_19 , L_19 ) ;
F_107 ( V_61 -> V_54 , V_111 ,
0 , L_20 , L_20 ) ;
F_107 ( V_61 -> V_54 , V_76 ,
0 , L_21 , L_21 ) ;
F_29 ( & V_61 -> V_163 ) ;
V_61 -> V_113 = V_8 ;
V_8 -> V_18 = V_61 ;
F_108 ( V_8 ) ;
F_109 ( & V_8 -> V_164 , L_22 , V_61 ) ;
F_29 ( & V_61 -> V_152 ) ;
F_110 ( & V_61 -> V_150 ) ;
F_95 ( V_61 , V_8 ) ;
return 0 ;
}
void F_111 ( struct V_9 * V_61 )
{
F_112 ( & V_165 ) ;
F_22 ( & V_61 -> V_163 ) ;
F_113 ( & V_165 ) ;
if ( V_61 -> V_26 != NULL ) {
F_106 ( V_61 -> V_26 ) ;
V_61 -> V_26 = NULL ;
}
if ( V_61 -> V_113 != NULL ) {
V_61 -> V_113 -> V_18 = NULL ;
F_114 ( & V_61 -> V_113 -> V_164 , L_22 , V_61 ) ;
F_115 ( V_61 -> V_113 ) ;
V_61 -> V_113 = NULL ;
}
if ( V_61 -> V_54 != NULL )
F_116 ( & V_61 -> V_54 ) ;
}
int F_117 ( struct V_9 * V_61 )
{
int V_47 ;
F_112 ( & V_165 ) ;
V_47 = F_118 ( & V_166 . V_85 ) ;
if ( V_47 == 0 )
F_74 ( & V_61 -> V_163 , & V_167 ) ;
F_113 ( & V_165 ) ;
return V_47 ;
}
void F_108 ( struct V_36 * V_149 )
{
F_119 ( & V_149 -> V_168 ) ;
}
void F_115 ( struct V_36 * V_149 )
{
F_4 ( F_39 ( & V_149 -> V_168 ) > 0 ) ;
F_120 ( & V_149 -> V_168 ) ;
}
int F_121 ( struct V_36 * V_149 , struct V_121 * V_169 )
{
if ( V_169 -> V_128 ++ == 0 && V_169 -> V_124 -> V_170 != NULL )
V_169 -> V_124 -> V_170 ( V_169 ) ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
F_122 ( & V_149 -> V_168 , 0 ) ;
V_149 -> V_97 = V_169 ;
F_123 ( & V_149 -> V_164 ) ;
F_29 ( & V_149 -> V_151 ) ;
return 0 ;
}
void F_124 ( struct V_36 * V_149 )
{
struct V_121 * V_169 ;
V_169 = V_149 -> V_97 ;
if ( V_149 -> V_171 != NULL ) {
V_149 -> V_171 -> V_172 = NULL ;
V_149 -> V_171 = NULL ;
}
F_125 ( & V_149 -> V_164 ) ;
F_126 ( F_39 ( & V_149 -> V_168 ) == 0 ,
L_23 , F_39 ( & V_149 -> V_168 ) ) ;
F_4 ( V_169 -> V_128 > 0 ) ;
if ( -- V_169 -> V_128 == 0 && V_169 -> V_124 -> V_129 != NULL )
V_169 -> V_124 -> V_129 ( V_169 ) ;
}
int F_127 ( struct V_3 * V_4 , struct V_7 * V_63 ,
struct V_36 * V_149 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_16 = V_63 ;
V_4 -> V_17 = V_149 ;
F_108 ( V_149 ) ;
F_128 ( & V_149 -> V_164 , & V_4 -> V_173 , L_24 , V_4 ) ;
F_29 ( & V_4 -> V_59 ) ;
return 0 ;
}
void F_129 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_17 ;
F_4 ( F_5 ( & V_4 -> V_59 ) ) ;
if ( V_37 != NULL ) {
F_130 ( & V_37 -> V_164 , & V_4 -> V_173 ,
L_24 , V_4 ) ;
F_115 ( V_37 ) ;
V_4 -> V_17 = NULL ;
}
}
void F_131 ( struct V_7 * V_63 , struct V_3 * V_4 )
{
F_40 ( & V_4 -> V_59 , & V_63 -> V_51 ) ;
}
void F_132 ( struct V_3 * V_174 , struct V_3 * V_4 )
{
F_40 ( & V_4 -> V_59 , & V_174 -> V_59 ) ;
}
int F_133 ( struct V_7 * V_63 )
{
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
F_122 ( & V_63 -> V_23 , 1 ) ;
F_134 ( & V_63 -> V_19 ) ;
F_29 ( & V_63 -> V_22 ) ;
F_29 ( & V_63 -> V_51 ) ;
F_123 ( & V_63 -> V_175 ) ;
return 0 ;
}
void F_135 ( struct V_7 * V_63 )
{
F_4 ( F_5 ( & V_63 -> V_51 ) ) ;
F_4 ( F_5 ( & V_63 -> V_22 ) ) ;
F_4 ( F_50 ( & V_63 -> V_19 ) ) ;
F_125 ( & V_63 -> V_175 ) ;
}
struct V_3 * F_72 ( struct V_7 * V_63 ,
const struct V_121 * V_176 )
{
struct V_3 * V_4 ;
F_26 (o, &h->loh_layers, lo_linkage) {
if ( V_4 -> V_17 -> V_97 == V_176 )
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
V_20 = V_41 -> V_97 -> V_124 -> V_177 ( V_2 , V_41 ) ;
F_114 ( & V_41 -> V_164 , L_25 , & F_99 ) ;
F_115 ( V_41 ) ;
}
F_33 ( V_2 , V_10 , ~ 0 ) ;
for ( V_41 = V_8 ; V_41 != NULL ; V_41 = V_20 ) {
const struct V_121 * V_122 = V_41 -> V_97 ;
struct V_178 * type ;
V_20 = V_122 -> V_124 -> V_179 ( V_2 , V_41 ) ;
type = V_122 -> V_180 ;
if ( type != NULL ) {
type -> V_181 -- ;
F_137 ( type ) ;
}
}
}
int F_138 ( struct V_182 * V_82 )
{
int V_47 ;
int V_71 ;
F_4 ( V_82 -> V_183 != NULL ) ;
F_4 ( V_82 -> V_184 != NULL ) ;
F_4 ( V_82 -> V_185 != 0 ) ;
V_47 = - V_186 ;
F_96 ( & V_187 ) ;
for ( V_71 = 0 ; V_71 < F_45 ( V_188 ) ; ++ V_71 ) {
if ( V_188 [ V_71 ] == NULL ) {
V_82 -> V_189 = V_71 ;
F_122 ( & V_82 -> V_190 , 1 ) ;
V_188 [ V_71 ] = V_82 ;
F_123 ( & V_82 -> V_191 ) ;
V_47 = 0 ;
++ V_192 ;
break;
}
}
F_97 ( & V_187 ) ;
return V_47 ;
}
static void F_139 ( struct V_193 * V_194 , int V_195 )
{
if ( V_194 -> V_196 != NULL && V_194 -> V_196 [ V_195 ] != NULL ) {
struct V_182 * V_82 ;
V_82 = V_188 [ V_195 ] ;
F_4 ( V_82 != NULL ) ;
F_4 ( V_82 -> V_184 != NULL ) ;
F_4 ( F_39 ( & V_82 -> V_190 ) > 1 ) ;
V_82 -> V_184 ( V_194 , V_82 , V_194 -> V_196 [ V_195 ] ) ;
F_114 ( & V_82 -> V_191 , L_26 , V_194 ) ;
F_120 ( & V_82 -> V_190 ) ;
if ( ( V_194 -> V_197 & V_198 ) == 0 ) {
#ifdef F_140
F_141 ( F_142 ( V_82 -> V_199 ) > 0 ) ;
#endif
F_143 ( V_82 -> V_199 ) ;
}
V_194 -> V_196 [ V_195 ] = NULL ;
}
}
void F_144 ( struct V_182 * V_82 )
{
F_4 ( F_39 ( & V_82 -> V_190 ) >= 1 ) ;
F_141 ( 0 <= V_82 -> V_189 && V_82 -> V_189 < F_45 ( V_188 ) ) ;
F_145 ( V_82 ) ;
++ V_192 ;
F_96 ( & V_187 ) ;
F_139 ( & V_166 . V_85 , V_82 -> V_189 ) ;
if ( V_188 [ V_82 -> V_189 ] ) {
V_188 [ V_82 -> V_189 ] = NULL ;
F_125 ( & V_82 -> V_191 ) ;
}
F_97 ( & V_187 ) ;
F_126 ( F_39 ( & V_82 -> V_190 ) == 1 ,
L_27 ,
F_39 ( & V_82 -> V_190 ) ) ;
}
int F_146 ( struct V_182 * V_200 , ... )
{
struct V_182 * V_82 = V_200 ;
T_1 args ;
int V_47 ;
va_start ( args , V_200 ) ;
do {
V_47 = F_138 ( V_82 ) ;
if ( V_47 )
break;
V_82 = va_arg ( args , struct V_182 * ) ;
} while ( V_82 != NULL );
va_end ( args ) ;
if ( V_47 != 0 ) {
va_start ( args , V_200 ) ;
while ( V_200 != V_82 ) {
F_144 ( V_200 ) ;
V_200 = va_arg ( args , struct V_182 * ) ;
}
va_end ( args ) ;
}
return V_47 ;
}
void F_147 ( struct V_182 * V_200 , ... )
{
T_1 args ;
va_start ( args , V_200 ) ;
do {
F_144 ( V_200 ) ;
V_200 = va_arg ( args , struct V_182 * ) ;
} while ( V_200 != NULL );
va_end ( args ) ;
}
void F_148 ( struct V_182 * V_200 , ... )
{
T_1 args ;
va_start ( args , V_200 ) ;
do {
F_149 ( V_200 ) ;
V_200 = va_arg ( args , struct V_182 * ) ;
} while ( V_200 != NULL );
va_end ( args ) ;
}
void F_150 ( struct V_182 * V_200 , ... )
{
T_1 args ;
va_start ( args , V_200 ) ;
do {
F_145 ( V_200 ) ;
V_200 = va_arg ( args , struct V_182 * ) ;
} while ( V_200 != NULL );
va_end ( args ) ;
}
void * F_44 ( const struct V_193 * V_194 ,
const struct V_182 * V_82 )
{
F_141 ( V_194 -> V_201 == V_202 ) ;
F_141 ( 0 <= V_82 -> V_189 && V_82 -> V_189 < F_45 ( V_188 ) ) ;
F_4 ( V_188 [ V_82 -> V_189 ] == V_82 ) ;
return V_194 -> V_196 [ V_82 -> V_189 ] ;
}
void F_145 ( struct V_182 * V_82 )
{
struct V_193 * V_194 ;
if ( ! ( V_82 -> V_185 & V_203 ) ) {
V_82 -> V_185 |= V_203 ;
F_96 ( & V_187 ) ;
F_26 (ctx, &lu_context_remembered,
lc_remember)
F_139 ( V_194 , V_82 -> V_189 ) ;
F_97 ( & V_187 ) ;
++ V_192 ;
}
}
void F_149 ( struct V_182 * V_82 )
{
V_82 -> V_185 &= ~ V_203 ;
++ V_192 ;
}
static void F_151 ( struct V_193 * V_194 )
{
int V_71 ;
if ( V_194 -> V_196 == NULL )
return;
for ( V_71 = 0 ; V_71 < F_45 ( V_188 ) ; ++ V_71 )
F_139 ( V_194 , V_71 ) ;
F_152 ( V_194 -> V_196 , F_45 ( V_188 ) * sizeof( V_194 -> V_196 [ 0 ] ) ) ;
V_194 -> V_196 = NULL ;
}
static int F_153 ( struct V_193 * V_194 )
{
int V_71 ;
F_141 ( V_194 -> V_196 != NULL ) ;
for ( V_71 = 0 ; V_71 < F_45 ( V_188 ) ; ++ V_71 ) {
struct V_182 * V_82 ;
V_82 = V_188 [ V_71 ] ;
if ( V_194 -> V_196 [ V_71 ] == NULL && V_82 != NULL &&
( V_82 -> V_185 & V_194 -> V_197 ) &&
! ( V_82 -> V_185 & V_203 ) ) {
void * V_204 ;
F_141 ( V_82 -> V_183 != NULL ) ;
F_141 ( V_82 -> V_189 == V_71 ) ;
V_204 = V_82 -> V_183 ( V_194 , V_82 ) ;
if ( F_64 ( F_25 ( V_204 ) ) )
return F_67 ( V_204 ) ;
if ( ! ( V_194 -> V_197 & V_198 ) )
F_154 ( V_82 -> V_199 ) ;
F_155 ( & V_82 -> V_191 , L_26 , V_194 ) ;
F_119 ( & V_82 -> V_190 ) ;
V_194 -> V_196 [ V_71 ] = V_204 ;
if ( V_82 -> V_205 != NULL )
V_194 -> V_197 |= V_206 ;
}
V_194 -> V_207 = V_192 ;
}
return 0 ;
}
static int F_156 ( struct V_193 * V_194 )
{
F_157 ( V_194 -> V_196 ,
F_45 ( V_188 ) * sizeof( V_194 -> V_196 [ 0 ] ) ) ;
if ( F_56 ( V_194 -> V_196 != NULL ) )
return F_153 ( V_194 ) ;
return - V_50 ;
}
int F_158 ( struct V_193 * V_194 , T_5 V_208 )
{
int V_209 ;
memset ( V_194 , 0 , sizeof( * V_194 ) ) ;
V_194 -> V_201 = V_210 ;
V_194 -> V_197 = V_208 ;
if ( V_208 & V_211 ) {
F_96 ( & V_187 ) ;
F_74 ( & V_194 -> V_212 , & V_213 ) ;
F_97 ( & V_187 ) ;
} else {
F_29 ( & V_194 -> V_212 ) ;
}
V_209 = F_156 ( V_194 ) ;
if ( V_209 != 0 )
F_159 ( V_194 ) ;
return V_209 ;
}
void F_159 ( struct V_193 * V_194 )
{
F_141 ( V_194 -> V_201 == V_210 || V_194 -> V_201 == V_214 ) ;
V_194 -> V_201 = V_215 ;
if ( ( V_194 -> V_197 & V_211 ) == 0 ) {
F_4 ( F_5 ( & V_194 -> V_212 ) ) ;
F_151 ( V_194 ) ;
} else {
F_96 ( & V_187 ) ;
F_151 ( V_194 ) ;
F_22 ( & V_194 -> V_212 ) ;
F_97 ( & V_187 ) ;
}
}
void F_160 ( struct V_193 * V_194 )
{
F_141 ( V_194 -> V_201 == V_210 || V_194 -> V_201 == V_214 ) ;
V_194 -> V_201 = V_202 ;
}
void F_161 ( struct V_193 * V_194 )
{
int V_71 ;
F_141 ( V_194 -> V_201 == V_202 ) ;
V_194 -> V_201 = V_214 ;
if ( V_194 -> V_197 & V_206 && V_194 -> V_196 != NULL ) {
for ( V_71 = 0 ; V_71 < F_45 ( V_188 ) ; ++ V_71 ) {
if ( V_194 -> V_196 [ V_71 ] != NULL ) {
struct V_182 * V_82 ;
V_82 = V_188 [ V_71 ] ;
F_4 ( V_82 != NULL ) ;
if ( V_82 -> V_205 != NULL )
V_82 -> V_205 ( V_194 ,
V_82 , V_194 -> V_196 [ V_71 ] ) ;
}
}
}
}
int F_118 ( struct V_193 * V_194 )
{
return F_56 ( V_194 -> V_207 == V_192 ) ? 0 : F_153 ( V_194 ) ;
}
void F_162 ( T_5 V_208 )
{
F_96 ( & V_187 ) ;
V_216 |= V_208 ;
V_192 ++ ;
F_97 ( & V_187 ) ;
}
void F_163 ( T_5 V_208 )
{
F_96 ( & V_187 ) ;
V_216 &= ~ V_208 ;
V_192 ++ ;
F_97 ( & V_187 ) ;
}
void F_164 ( T_5 V_208 )
{
F_96 ( & V_187 ) ;
V_217 |= V_208 ;
V_192 ++ ;
F_97 ( & V_187 ) ;
}
void F_165 ( T_5 V_208 )
{
F_96 ( & V_187 ) ;
V_217 &= ~ V_208 ;
V_192 ++ ;
F_97 ( & V_187 ) ;
}
int F_166 ( struct V_1 * V_2 , T_5 V_208 )
{
int V_47 ;
V_2 -> V_218 = NULL ;
V_47 = F_158 ( & V_2 -> V_85 , V_208 ) ;
if ( F_56 ( V_47 == 0 ) )
F_160 ( & V_2 -> V_85 ) ;
return V_47 ;
}
void F_167 ( struct V_1 * V_2 )
{
F_161 ( & V_2 -> V_85 ) ;
F_159 ( & V_2 -> V_85 ) ;
V_2 -> V_218 = NULL ;
}
int F_168 ( struct V_1 * V_2 )
{
int V_47 ;
V_47 = F_118 ( & V_2 -> V_85 ) ;
if ( V_47 == 0 && V_2 -> V_218 != NULL )
V_47 = F_118 ( V_2 -> V_218 ) ;
return V_47 ;
}
int F_169 ( struct V_1 * V_2 , T_5 V_219 ,
T_5 V_220 )
{
int V_47 ;
if ( ( V_2 -> V_85 . V_197 & V_219 ) != V_219 ) {
V_2 -> V_85 . V_207 = 0 ;
V_2 -> V_85 . V_197 |= V_219 ;
}
if ( V_2 -> V_218 && ( V_2 -> V_218 -> V_197 & V_220 ) != V_220 ) {
V_2 -> V_218 -> V_207 = 0 ;
V_2 -> V_218 -> V_197 |= V_220 ;
}
V_47 = F_168 ( V_2 ) ;
return V_47 ;
}
static void F_170 ( struct V_34 * V_114 ,
T_6 * V_221 , int V_222 )
{
struct V_12 V_13 ;
int V_71 ;
F_36 (hs, &bd, i) {
struct V_5 * V_6 = F_10 ( V_114 , & V_13 ) ;
struct V_223 * V_224 ;
F_37 ( V_114 , & V_13 , 1 ) ;
V_221 -> V_225 += V_6 -> V_29 ;
V_221 -> V_226 += F_171 ( & V_13 ) ;
V_221 -> V_227 = F_101 ( ( int ) V_221 -> V_227 ,
F_172 ( & V_13 ) ) ;
if ( ! V_222 ) {
F_15 ( V_114 , & V_13 , 1 ) ;
continue;
}
F_173 (hs, &bd, hhead) {
if ( ! F_174 ( V_224 ) )
V_221 -> V_228 ++ ;
}
F_15 ( V_114 , & V_13 , 1 ) ;
}
}
static unsigned long F_175 ( struct V_229 * V_230 ,
struct V_231 * V_232 )
{
T_6 V_221 ;
struct V_9 * V_61 ;
struct V_9 * V_233 ;
unsigned long V_234 = 0 ;
if ( ! ( V_232 -> V_235 & V_236 ) )
return 0 ;
F_112 ( & V_165 ) ;
F_38 (s, tmp, &lu_sites, ls_linkage) {
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
F_170 ( V_61 -> V_26 , & V_221 , 0 ) ;
V_234 += V_221 . V_226 - V_221 . V_225 ;
}
F_113 ( & V_165 ) ;
V_234 = ( V_234 / 100 ) * V_237 ;
F_176 ( V_238 , L_28 , V_234 ) ;
return V_234 ;
}
static unsigned long F_177 ( struct V_229 * V_230 ,
struct V_231 * V_232 )
{
struct V_9 * V_61 ;
struct V_9 * V_233 ;
unsigned long V_239 = V_232 -> V_240 , V_241 = 0 ;
F_178 ( V_56 ) ;
if ( ! ( V_232 -> V_235 & V_236 ) )
return V_242 ;
F_112 ( & V_165 ) ;
F_38 (s, tmp, &lu_sites, ls_linkage) {
V_241 = F_33 ( & V_166 , V_61 , V_239 ) ;
V_239 -= V_241 ;
F_179 ( & V_61 -> V_163 , & V_56 ) ;
}
F_180 ( & V_56 , V_167 . V_58 ) ;
F_113 ( & V_165 ) ;
return V_232 -> V_240 - V_239 ;
}
int F_181 ( const struct V_1 * V_2 ,
void * V_243 , const char * V_78 , ... )
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
F_176 ( V_244 , L_29 , & V_188 ) ;
V_47 = F_184 () ;
if ( V_47 != 0 )
return V_47 ;
F_185 ( & V_86 ) ;
V_47 = F_138 ( & V_86 ) ;
if ( V_47 != 0 )
return V_47 ;
F_112 ( & V_165 ) ;
V_47 = F_166 ( & V_166 , V_245 ) ;
F_113 ( & V_165 ) ;
if ( V_47 != 0 )
return V_47 ;
F_186 ( & V_246 ) ;
return V_47 ;
}
void F_187 ( void )
{
F_188 ( & V_246 ) ;
F_144 ( & V_86 ) ;
F_112 ( & V_165 ) ;
F_167 ( & V_166 ) ;
F_113 ( & V_165 ) ;
F_189 () ;
}
static T_5 F_190 ( struct V_247 * V_221 , int V_248 )
{
#if F_191 ( V_249 )
struct V_250 V_251 ;
F_192 ( V_221 , V_248 , & V_251 ) ;
return ( T_5 ) V_251 . V_252 ;
#else
return 0 ;
#endif
}
int F_193 ( const struct V_9 * V_61 , struct V_253 * V_254 )
{
T_6 V_221 ;
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
F_170 ( V_61 -> V_26 , & V_221 , 1 ) ;
return F_194 ( V_254 , L_30 ,
V_221 . V_225 ,
V_221 . V_226 ,
V_221 . V_228 ,
F_195 ( V_61 -> V_26 ) ,
V_221 . V_227 ,
F_190 ( V_61 -> V_54 , V_55 ) ,
F_190 ( V_61 -> V_54 , V_108 ) ,
F_190 ( V_61 -> V_54 , V_107 ) ,
F_190 ( V_61 -> V_54 , V_118 ) ,
F_190 ( V_61 -> V_54 , V_111 ) ,
F_190 ( V_61 -> V_54 , V_76 ) ) ;
}
int F_196 ( struct V_255 * V_256 )
{
int V_47 ;
struct V_255 * V_257 = V_256 ;
for ( V_47 = 0 ; V_257 -> V_258 != NULL ; ++ V_257 ) {
* V_257 -> V_258 = F_197 ( V_257 -> V_259 ,
V_257 -> V_260 ,
0 , 0 , NULL ) ;
if ( * V_257 -> V_258 == NULL ) {
V_47 = - V_50 ;
F_198 ( V_256 ) ;
break;
}
}
return V_47 ;
}
void F_198 ( struct V_255 * V_256 )
{
for (; V_256 -> V_258 != NULL ; ++ V_256 ) {
if ( * V_256 -> V_258 != NULL ) {
F_199 ( * V_256 -> V_258 ) ;
* V_256 -> V_258 = NULL ;
}
}
}
void F_200 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_14 * V_15 )
{
struct V_9 * V_61 = V_4 -> V_17 -> V_18 ;
struct V_14 * V_261 = & V_4 -> V_16 -> V_27 ;
struct V_5 * V_6 ;
struct V_3 * V_115 ;
T_3 V_101 ;
struct V_34 * V_114 ;
struct V_12 V_13 ;
T_4 V_102 = 0 ;
F_4 ( F_3 ( V_261 ) ) ;
V_114 = V_61 -> V_26 ;
F_21 ( V_114 , ( void * ) V_15 , & V_13 , 1 ) ;
V_115 = F_53 ( V_61 , & V_13 , V_15 , & V_101 , & V_102 ) ;
F_4 ( F_25 ( V_115 ) && F_67 ( V_115 ) == - V_106 ) ;
* V_261 = * V_15 ;
V_6 = F_10 ( V_114 , & V_13 ) ;
F_65 ( V_114 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
V_6 -> V_29 ++ ;
F_15 ( V_114 , & V_13 , 1 ) ;
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
void F_203 ( struct V_262 * V_263 )
{
F_4 ( V_263 ) ;
if ( V_263 -> V_264 ) {
F_4 ( V_263 -> V_265 > 0 ) ;
F_204 ( V_263 -> V_264 , V_263 -> V_265 ) ;
V_263 -> V_264 = NULL ;
V_263 -> V_265 = 0 ;
}
}
void F_205 ( struct V_262 * V_263 , int V_266 )
{
F_4 ( V_263 ) ;
F_4 ( V_263 -> V_264 == NULL ) ;
F_4 ( V_263 -> V_265 == 0 ) ;
F_206 ( V_263 -> V_264 , V_266 ) ;
if ( F_56 ( V_263 -> V_264 ) )
V_263 -> V_265 = V_266 ;
}
void F_207 ( struct V_262 * V_263 , int V_266 )
{
F_203 ( V_263 ) ;
F_205 ( V_263 , V_266 ) ;
}
struct V_262 * F_208 ( struct V_262 * V_263 , int V_267 )
{
if ( V_263 -> V_264 == NULL && V_263 -> V_265 == 0 )
F_205 ( V_263 , V_267 ) ;
if ( ( V_267 > V_263 -> V_265 ) && ( V_263 -> V_264 != NULL ) )
F_207 ( V_263 , V_267 ) ;
return V_263 ;
}
int F_209 ( struct V_262 * V_263 , int V_267 )
{
char * V_268 ;
if ( V_267 <= V_263 -> V_265 )
return 0 ;
F_206 ( V_268 , V_267 ) ;
if ( V_268 == NULL )
return - V_50 ;
if ( V_263 -> V_264 != NULL ) {
memcpy ( V_268 , V_263 -> V_264 , V_263 -> V_265 ) ;
F_204 ( V_263 -> V_264 , V_263 -> V_265 ) ;
}
V_263 -> V_264 = V_268 ;
V_263 -> V_265 = V_267 ;
return 0 ;
}
