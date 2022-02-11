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
F_4 ( ! V_8 -> V_19 . V_20 && ! V_8 -> V_19 . V_21 ) ;
F_4 ( F_5 ( & V_8 -> V_22 ) ) ;
if ( ! F_6 ( & V_8 -> V_23 ) )
return;
F_7 (o, &top->loh_layers, lo_linkage) {
if ( V_4 -> V_24 -> V_25 )
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
F_7 (o, &top->loh_layers, lo_linkage) {
if ( V_4 -> V_24 -> V_25 )
V_4 -> V_24 -> V_25 ( V_2 , V_4 ) ;
}
if ( ! F_12 ( V_8 ) ) {
F_4 ( F_5 ( & V_8 -> V_22 ) ) ;
F_14 ( & V_8 -> V_22 , & V_6 -> V_29 ) ;
V_6 -> V_30 ++ ;
F_15 ( V_10 -> V_31 , V_32 ) ;
F_16 ( V_33 , L_1 ,
V_4 , V_10 -> V_26 , V_6 , V_6 -> V_30 ) ;
F_17 ( V_10 -> V_26 , & V_13 , 1 ) ;
return;
}
if ( ! F_18 ( V_34 , & V_8 -> V_35 ) )
F_19 ( V_10 -> V_26 , & V_13 , & V_8 -> V_19 ) ;
F_17 ( V_10 -> V_26 , & V_13 , 1 ) ;
F_8 ( V_2 , V_11 ) ;
}
void F_20 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = V_4 -> V_16 ;
F_21 ( V_36 , & V_8 -> V_35 ) ;
if ( ! F_18 ( V_34 , & V_8 -> V_35 ) ) {
struct V_9 * V_10 = V_4 -> V_17 -> V_18 ;
struct V_37 * V_38 = V_10 -> V_26 ;
struct V_12 V_13 ;
F_22 ( V_38 , & V_8 -> V_27 , & V_13 , 1 ) ;
if ( ! F_5 ( & V_8 -> V_22 ) ) {
struct V_5 * V_6 ;
F_23 ( & V_8 -> V_22 ) ;
V_6 = F_10 ( V_38 , & V_13 ) ;
V_6 -> V_30 -- ;
F_24 ( V_10 -> V_31 , V_32 ) ;
}
F_19 ( V_38 , & V_13 , & V_8 -> V_19 ) ;
F_17 ( V_38 , & V_13 , 1 ) ;
}
}
static struct V_3 * F_25 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 )
{
struct V_3 * V_44 ;
struct V_3 * V_8 ;
struct V_45 * V_46 ;
unsigned int V_47 = 0 ;
unsigned int V_48 ;
int V_49 ;
int V_50 ;
V_8 = V_40 -> V_51 -> V_52 ( V_2 , NULL , V_40 ) ;
if ( ! V_8 )
return F_26 ( - V_53 ) ;
if ( F_27 ( V_8 ) )
return V_8 ;
V_8 -> V_16 -> V_27 = * V_41 ;
V_46 = & V_8 -> V_16 -> V_54 ;
do {
V_49 = 1 ;
V_48 = 1 ;
F_28 (scan, layers, lo_linkage) {
if ( V_47 & V_48 )
goto V_20;
V_49 = 0 ;
V_44 -> V_16 = V_8 -> V_16 ;
V_50 = V_44 -> V_24 -> V_55 ( V_2 , V_44 , V_43 ) ;
if ( V_50 != 0 ) {
F_8 ( V_2 , V_8 ) ;
return F_26 ( V_50 ) ;
}
V_47 |= V_48 ;
V_20:
V_48 <<= 1 ;
}
} while ( ! V_49 );
F_7 (scan, layers, lo_linkage) {
if ( V_44 -> V_24 -> V_56 ) {
V_50 = V_44 -> V_24 -> V_56 ( V_2 , V_44 ) ;
if ( V_50 != 0 ) {
F_8 ( V_2 , V_8 ) ;
return F_26 ( V_50 ) ;
}
}
}
F_15 ( V_40 -> V_18 -> V_31 , V_57 ) ;
return V_8 ;
}
static void F_8 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_3 * V_44 ;
struct V_45 * V_46 ;
struct V_45 V_58 ;
V_10 = V_4 -> V_17 -> V_18 ;
V_46 = & V_4 -> V_16 -> V_54 ;
V_6 = F_29 ( V_10 , & V_4 -> V_16 -> V_27 ) ;
F_7 (scan, layers, lo_linkage) {
if ( V_44 -> V_24 -> V_59 )
V_44 -> V_24 -> V_59 ( V_2 , V_44 ) ;
}
F_30 ( & V_58 ) ;
F_31 ( V_46 , & V_58 ) ;
while ( ! F_5 ( & V_58 ) ) {
V_4 = F_32 ( V_58 . V_60 , struct V_3 , V_61 ) ;
F_23 ( & V_4 -> V_61 ) ;
V_4 -> V_24 -> V_62 ( V_2 , V_4 ) ;
}
if ( F_33 ( & V_6 -> V_28 ) )
F_13 ( & V_6 -> V_28 ) ;
}
int F_34 ( const struct V_1 * V_2 , struct V_9 * V_63 , int V_64 )
{
struct V_7 * V_65 ;
struct V_7 * V_66 ;
struct V_5 * V_6 ;
struct V_12 V_13 ;
struct V_12 V_67 ;
struct V_45 V_68 ;
int V_69 ;
unsigned int V_70 ;
int V_71 ;
int V_72 ;
unsigned int V_73 ;
if ( F_35 ( V_74 ) )
return 0 ;
F_30 ( & V_68 ) ;
V_70 = V_63 -> V_75 ;
V_72 = ( V_64 == ~ 0 ) ? - 1 : V_64 / ( int ) F_36 ( V_63 -> V_26 ) + 1 ;
V_76:
F_37 ( & V_63 -> V_77 ) ;
V_69 = 0 ;
F_38 (s->ls_obj_hash, &bd, i) {
if ( V_73 < V_70 )
continue;
V_71 = V_72 ;
F_39 ( V_63 -> V_26 , & V_13 , 1 ) ;
V_6 = F_10 ( V_63 -> V_26 , & V_13 ) ;
F_40 (h, temp, &bkt->lsb_lru, loh_lru) {
F_4 ( F_41 ( & V_65 -> V_23 ) == 0 ) ;
F_9 ( V_63 -> V_26 , & V_65 -> V_27 , & V_67 ) ;
F_4 ( V_13 . V_78 == V_67 . V_78 ) ;
F_19 ( V_63 -> V_26 ,
& V_67 , & V_65 -> V_19 ) ;
F_42 ( & V_65 -> V_22 , & V_68 ) ;
V_6 -> V_30 -- ;
F_24 ( V_63 -> V_31 , V_32 ) ;
if ( V_69 == 0 )
V_69 = 1 ;
if ( V_64 != ~ 0 && -- V_64 == 0 )
break;
if ( V_71 > 0 && -- V_71 == 0 )
break;
}
F_17 ( V_63 -> V_26 , & V_13 , 1 ) ;
F_43 () ;
while ( ! F_5 ( & V_68 ) ) {
V_65 = F_32 ( V_68 . V_20 ,
struct V_7 , V_22 ) ;
F_23 ( & V_65 -> V_22 ) ;
F_8 ( V_2 , F_44 ( V_65 ) ) ;
F_15 ( V_63 -> V_31 , V_79 ) ;
}
if ( V_64 == 0 )
break;
}
F_45 ( & V_63 -> V_77 ) ;
if ( V_64 != 0 && V_69 && V_70 != 0 ) {
V_70 = 0 ;
goto V_76;
}
V_63 -> V_75 = V_73 % F_36 ( V_63 -> V_26 ) ;
return V_64 ;
}
int F_46 ( const struct V_1 * V_2 ,
void * V_80 , const char * V_81 , ... )
{
struct V_82 * V_83 = V_80 ;
struct V_84 * V_85 ;
int V_86 ;
int V_87 ;
T_1 args ;
va_start ( args , V_81 ) ;
V_85 = F_47 ( & V_2 -> V_88 , & V_89 ) ;
V_86 = strlen ( V_85 -> V_90 ) ;
V_87 = V_81 [ strlen ( V_81 ) - 1 ] == '\n' ;
vsnprintf ( V_85 -> V_90 + V_86 ,
F_48 ( V_85 -> V_90 ) - V_86 , V_81 , args ) ;
if ( V_87 ) {
if ( F_49 ( V_83 -> V_91 , V_83 -> V_92 ) )
F_50 ( V_83 , L_2 , V_85 -> V_90 ) ;
V_85 -> V_90 [ 0 ] = 0 ;
}
va_end ( args ) ;
return 0 ;
}
void F_51 ( const struct V_1 * V_2 , void * V_80 ,
T_2 V_93 ,
const struct V_7 * V_94 )
{
(* V_93)( V_2 , V_80 , L_3 V_95 L_4 ,
V_94 , V_94 -> V_35 , F_41 ( & V_94 -> V_23 ) ,
F_52 ( & V_94 -> V_27 ) ,
F_53 ( & V_94 -> V_19 ) ? L_5 : L_6 ,
F_5 ( (struct V_45 * ) & V_94 -> V_22 ) ? \
L_5 : L_7 ,
V_94 -> V_96 & V_97 ? L_8 : L_5 ) ;
}
void F_54 ( const struct V_1 * V_2 , void * V_80 ,
T_2 V_93 , const struct V_3 * V_4 )
{
static const char V_98 [] = L_9 ;
struct V_7 * V_8 ;
int V_99 = 4 ;
V_8 = V_4 -> V_16 ;
F_51 ( V_2 , V_80 , V_93 , V_8 ) ;
(* V_93)( V_2 , V_80 , L_10 ) ;
F_28 (o, &top->loh_layers, lo_linkage) {
(* V_93)( V_2 , V_80 , L_11 , V_99 , V_99 , V_98 ,
V_4 -> V_17 -> V_100 -> V_101 , V_4 ) ;
if ( V_4 -> V_24 -> V_102 )
(* V_4 -> V_24 -> V_102 )( V_2 , V_80 , V_93 , V_4 ) ;
(* V_93)( V_2 , V_80 , L_12 ) ;
}
(* V_93)( V_2 , V_80 , L_13 , V_8 ) ;
}
static struct V_3 * F_55 ( struct V_9 * V_63 ,
struct V_12 * V_13 ,
const struct V_14 * V_41 ,
T_3 * V_103 ,
T_4 * V_104 )
{
struct V_5 * V_6 ;
struct V_7 * V_65 ;
struct V_105 * V_106 ;
T_4 V_107 = F_56 ( V_13 ) ;
if ( * V_104 == V_107 )
return F_26 ( - V_108 ) ;
* V_104 = V_107 ;
V_6 = F_10 ( V_63 -> V_26 , V_13 ) ;
V_106 = F_57 ( V_63 -> V_26 , V_13 , ( void * ) V_41 ) ;
if ( ! V_106 ) {
F_15 ( V_63 -> V_31 , V_109 ) ;
return F_26 ( - V_108 ) ;
}
V_65 = F_32 ( V_106 , struct V_7 , V_19 ) ;
if ( F_58 ( ! F_12 ( V_65 ) ) ) {
F_59 ( V_63 -> V_26 , V_106 ) ;
F_15 ( V_63 -> V_31 , V_110 ) ;
if ( ! F_5 ( & V_65 -> V_22 ) ) {
F_23 ( & V_65 -> V_22 ) ;
V_6 -> V_30 -- ;
F_24 ( V_63 -> V_31 , V_32 ) ;
}
return F_44 ( V_65 ) ;
}
F_60 ( V_103 , V_111 ) ;
F_61 ( & V_6 -> V_28 , V_103 ) ;
F_62 ( V_112 ) ;
F_15 ( V_63 -> V_31 , V_113 ) ;
return F_26 ( - V_114 ) ;
}
static struct V_3 * F_63 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 )
{
return F_64 ( V_2 , V_40 -> V_18 -> V_115 , V_41 , V_43 ) ;
}
static void F_65 ( const struct V_1 * V_2 , struct V_39 * V_40 )
{
T_4 V_116 , V_64 ;
if ( V_117 == V_118 )
return;
V_116 = F_66 ( V_40 -> V_18 -> V_26 ) ;
V_64 = ( T_4 ) V_117 ;
if ( V_116 > V_64 )
F_34 ( V_2 , V_40 -> V_18 ,
F_67 ( T_4 , V_116 - V_64 , V_119 ) ) ;
}
static struct V_3 * F_68 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 )
{
struct V_3 * V_4 ;
struct V_37 * V_120 ;
struct V_12 V_13 ;
V_4 = F_25 ( V_2 , V_40 , V_41 , V_43 ) ;
if ( F_27 ( V_4 ) )
return V_4 ;
V_120 = V_40 -> V_18 -> V_26 ;
F_22 ( V_120 , ( void * ) V_41 , & V_13 , 1 ) ;
F_69 ( V_120 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
F_17 ( V_120 , & V_13 , 1 ) ;
F_65 ( V_2 , V_40 ) ;
return V_4 ;
}
static struct V_3 * F_70 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 ,
T_3 * V_103 )
{
struct V_3 * V_4 ;
struct V_3 * V_121 ;
struct V_9 * V_63 ;
struct V_37 * V_120 ;
struct V_12 V_13 ;
T_4 V_104 = 0 ;
if ( V_43 && V_43 -> V_122 & V_123 )
return F_68 ( V_2 , V_40 , V_41 , V_43 ) ;
V_63 = V_40 -> V_18 ;
V_120 = V_63 -> V_26 ;
F_22 ( V_120 , ( void * ) V_41 , & V_13 , 1 ) ;
V_4 = F_55 ( V_63 , & V_13 , V_41 , V_103 , & V_104 ) ;
F_17 ( V_120 , & V_13 , 1 ) ;
if ( ! F_27 ( V_4 ) || F_71 ( V_4 ) != - V_108 )
return V_4 ;
V_4 = F_25 ( V_2 , V_40 , V_41 , V_43 ) ;
if ( F_27 ( V_4 ) )
return V_4 ;
F_4 ( F_72 ( F_2 ( V_4 ) , V_41 ) ) ;
F_39 ( V_120 , & V_13 , 1 ) ;
V_121 = F_55 ( V_63 , & V_13 , V_41 , V_103 , & V_104 ) ;
if ( F_58 ( F_71 ( V_121 ) == - V_108 ) ) {
F_69 ( V_120 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
F_17 ( V_120 , & V_13 , 1 ) ;
F_65 ( V_2 , V_40 ) ;
return V_4 ;
}
F_15 ( V_63 -> V_31 , V_124 ) ;
F_17 ( V_120 , & V_13 , 1 ) ;
F_8 ( V_2 , V_4 ) ;
return V_121 ;
}
struct V_3 * F_64 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 )
{
struct V_5 * V_6 ;
struct V_3 * V_125 ;
T_3 V_126 ;
while ( 1 ) {
V_125 = F_70 ( V_2 , V_40 , V_41 , V_43 , & V_126 ) ;
if ( V_125 != F_26 ( - V_114 ) )
return V_125 ;
F_73 () ;
V_6 = F_29 ( V_40 -> V_18 , ( void * ) V_41 ) ;
F_74 ( & V_6 -> V_28 , & V_126 ) ;
}
}
struct V_3 * F_75 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 )
{
struct V_3 * V_8 ;
struct V_3 * V_125 ;
V_8 = F_63 ( V_2 , V_40 , V_41 , V_43 ) ;
if ( F_27 ( V_8 ) )
return V_8 ;
V_125 = F_76 ( V_8 -> V_16 , V_40 -> V_100 ) ;
if ( F_77 ( ! V_125 ) ) {
F_1 ( V_2 , V_8 ) ;
V_125 = F_26 ( - V_108 ) ;
}
return V_125 ;
}
int F_78 ( struct V_127 * V_128 )
{
int V_50 = 0 ;
F_79 ( & V_128 -> V_129 , 0 ) ;
F_30 ( & V_128 -> V_130 ) ;
if ( V_128 -> V_131 -> V_132 )
V_50 = V_128 -> V_131 -> V_132 ( V_128 ) ;
if ( ! V_50 ) {
F_80 ( & V_133 ) ;
F_81 ( & V_128 -> V_130 , & V_134 ) ;
F_82 ( & V_133 ) ;
}
return V_50 ;
}
void F_83 ( struct V_127 * V_128 )
{
F_80 ( & V_133 ) ;
F_23 ( & V_128 -> V_130 ) ;
F_82 ( & V_133 ) ;
if ( V_128 -> V_131 -> V_135 )
V_128 -> V_131 -> V_135 ( V_128 ) ;
}
static int
F_84 ( struct V_37 * V_120 , struct V_12 * V_13 ,
struct V_105 * V_106 , void * V_136 )
{
struct V_137 * V_138 = (struct V_137 * ) V_136 ;
struct V_7 * V_65 ;
V_65 = F_85 ( V_106 , struct V_7 , V_19 ) ;
if ( ! F_5 ( & V_65 -> V_54 ) ) {
const struct V_3 * V_4 ;
V_4 = F_44 ( V_65 ) ;
F_54 ( V_138 -> V_139 , V_138 -> V_140 ,
V_138 -> V_141 , V_4 ) ;
} else {
F_51 ( V_138 -> V_139 , V_138 -> V_140 ,
V_138 -> V_141 , V_65 ) ;
}
return 0 ;
}
void F_86 ( const struct V_1 * V_2 , struct V_9 * V_63 , void * V_80 ,
T_2 V_93 )
{
struct V_137 V_138 = {
. V_139 = (struct V_1 * ) V_2 ,
. V_140 = V_80 ,
. V_141 = V_93 ,
} ;
F_87 ( V_63 -> V_26 , F_84 , & V_138 ) ;
}
static unsigned long F_88 ( struct V_39 * V_8 )
{
unsigned long V_142 = V_143 ;
unsigned long V_144 ;
unsigned long V_145 ;
V_144 = V_146 ;
#if V_147 == 32
if ( V_144 > 1 << ( 30 - V_148 ) )
V_144 = 1 << ( 30 - V_148 ) * 3 / 4 ;
#endif
if ( V_149 == 0 || V_149 > V_150 ) {
F_89 ( L_14 ,
V_149 , V_150 ,
V_151 ) ;
V_149 = V_151 ;
}
V_144 = V_144 / 100 * V_149 *
( V_152 / 1024 ) ;
for ( V_145 = 1 ; ( 1 << V_145 ) < V_144 ; ++ V_145 ) {
;
}
return F_90 ( F_91 ( V_145 ) , V_145 , V_153 , V_142 ) ;
}
static unsigned F_92 ( struct V_37 * V_120 ,
const void * V_85 , unsigned V_154 )
{
struct V_14 * V_15 = (struct V_14 * ) V_85 ;
T_5 V_155 ;
V_155 = F_93 ( V_15 ) ;
V_155 += ( V_155 >> 4 ) + ( V_155 << 12 ) ;
V_155 = F_94 ( V_155 , V_120 -> V_156 ) ;
V_155 -= F_94 ( ( unsigned long ) V_120 , F_95 ( V_15 ) % 11 + 3 ) ;
V_155 <<= V_120 -> V_157 - V_120 -> V_156 ;
V_155 |= ( F_96 ( V_15 ) + F_95 ( V_15 ) ) & ( F_36 ( V_120 ) - 1 ) ;
return V_155 & V_154 ;
}
static void * F_97 ( struct V_105 * V_106 )
{
return F_85 ( V_106 , struct V_7 , V_19 ) ;
}
static void * F_98 ( struct V_105 * V_106 )
{
struct V_7 * V_65 ;
V_65 = F_85 ( V_106 , struct V_7 , V_19 ) ;
return & V_65 -> V_27 ;
}
static int F_99 ( const void * V_85 , struct V_105 * V_106 )
{
struct V_7 * V_65 ;
V_65 = F_85 ( V_106 , struct V_7 , V_19 ) ;
return F_72 ( & V_65 -> V_27 , (struct V_14 * ) V_85 ) ;
}
static void F_100 ( struct V_37 * V_120 , struct V_105 * V_106 )
{
struct V_7 * V_65 ;
V_65 = F_85 ( V_106 , struct V_7 , V_19 ) ;
F_101 ( & V_65 -> V_23 ) ;
}
static void F_102 ( struct V_37 * V_120 , struct V_105 * V_106 )
{
F_103 () ;
}
static void F_104 ( struct V_9 * V_63 , struct V_39 * V_158 )
{
F_80 ( & V_63 -> V_159 ) ;
if ( F_5 ( & V_158 -> V_160 ) )
F_81 ( & V_158 -> V_160 , & V_63 -> V_161 ) ;
F_82 ( & V_63 -> V_159 ) ;
}
int F_105 ( struct V_9 * V_63 , struct V_39 * V_8 )
{
struct V_5 * V_6 ;
struct V_12 V_13 ;
unsigned long V_145 ;
unsigned long V_73 ;
char V_162 [ 16 ] ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
F_106 ( & V_63 -> V_77 ) ;
snprintf ( V_162 , sizeof( V_162 ) , L_15 , V_8 -> V_100 -> V_101 ) ;
for ( V_145 = F_88 ( V_8 ) ; V_145 >= V_153 ; V_145 -- ) {
V_63 -> V_26 = F_107 ( V_162 , V_145 , V_145 ,
V_145 - V_163 ,
sizeof( * V_6 ) , 0 , 0 ,
& V_164 ,
V_165 |
V_166 |
V_167 |
V_168 |
V_169 ) ;
if ( V_63 -> V_26 )
break;
}
if ( ! V_63 -> V_26 ) {
F_108 ( L_16 , V_145 ) ;
return - V_53 ;
}
F_38 (s->ls_obj_hash, &bd, i) {
V_6 = F_10 ( V_63 -> V_26 , & V_13 ) ;
F_30 ( & V_6 -> V_29 ) ;
F_109 ( & V_6 -> V_28 ) ;
}
V_63 -> V_31 = F_110 ( V_170 , 0 ) ;
if ( ! V_63 -> V_31 ) {
F_111 ( V_63 -> V_26 ) ;
V_63 -> V_26 = NULL ;
return - V_53 ;
}
F_112 ( V_63 -> V_31 , V_57 ,
0 , L_17 , L_17 ) ;
F_112 ( V_63 -> V_31 , V_110 ,
0 , L_18 , L_18 ) ;
F_112 ( V_63 -> V_31 , V_109 ,
0 , L_19 , L_19 ) ;
F_112 ( V_63 -> V_31 , V_124 ,
0 , L_20 , L_20 ) ;
F_112 ( V_63 -> V_31 , V_113 ,
0 , L_21 , L_21 ) ;
F_112 ( V_63 -> V_31 , V_79 ,
0 , L_22 , L_22 ) ;
F_112 ( V_63 -> V_31 , V_32 ,
V_171 , L_23 , L_23 ) ;
F_30 ( & V_63 -> V_172 ) ;
V_63 -> V_115 = V_8 ;
V_8 -> V_18 = V_63 ;
F_113 ( V_8 ) ;
F_114 ( & V_8 -> V_173 , L_24 , V_63 ) ;
F_30 ( & V_63 -> V_161 ) ;
F_115 ( & V_63 -> V_159 ) ;
F_104 ( V_63 , V_8 ) ;
return 0 ;
}
void F_116 ( struct V_9 * V_63 )
{
F_37 ( & V_174 ) ;
F_23 ( & V_63 -> V_172 ) ;
F_45 ( & V_174 ) ;
if ( V_63 -> V_26 ) {
F_111 ( V_63 -> V_26 ) ;
V_63 -> V_26 = NULL ;
}
if ( V_63 -> V_115 ) {
V_63 -> V_115 -> V_18 = NULL ;
F_117 ( & V_63 -> V_115 -> V_173 , L_24 , V_63 ) ;
F_118 ( V_63 -> V_115 ) ;
V_63 -> V_115 = NULL ;
}
if ( V_63 -> V_31 )
F_119 ( & V_63 -> V_31 ) ;
}
int F_120 ( struct V_9 * V_63 )
{
int V_50 ;
F_37 ( & V_174 ) ;
V_50 = F_121 ( & V_175 . V_88 ) ;
if ( V_50 == 0 )
F_81 ( & V_63 -> V_172 , & V_176 ) ;
F_45 ( & V_174 ) ;
return V_50 ;
}
void F_113 ( struct V_39 * V_158 )
{
F_101 ( & V_158 -> V_177 ) ;
}
void F_118 ( struct V_39 * V_158 )
{
F_4 ( F_41 ( & V_158 -> V_177 ) > 0 ) ;
F_122 ( & V_158 -> V_177 ) ;
}
int F_123 ( struct V_39 * V_158 , struct V_127 * V_178 )
{
if ( F_124 ( & V_178 -> V_129 ) == 1 &&
V_178 -> V_131 -> V_179 )
V_178 -> V_131 -> V_179 ( V_178 ) ;
memset ( V_158 , 0 , sizeof( * V_158 ) ) ;
F_79 ( & V_158 -> V_177 , 0 ) ;
V_158 -> V_100 = V_178 ;
F_125 ( & V_158 -> V_173 ) ;
F_30 ( & V_158 -> V_160 ) ;
return 0 ;
}
void F_126 ( struct V_39 * V_158 )
{
struct V_127 * V_178 = V_158 -> V_100 ;
if ( V_158 -> V_180 ) {
V_158 -> V_180 -> V_181 = NULL ;
V_158 -> V_180 = NULL ;
}
F_127 ( & V_158 -> V_173 ) ;
F_128 ( F_41 ( & V_158 -> V_177 ) == 0 ,
L_25 , F_41 ( & V_158 -> V_177 ) ) ;
F_4 ( F_41 ( & V_178 -> V_129 ) > 0 ) ;
if ( F_6 ( & V_178 -> V_129 ) &&
V_178 -> V_131 -> V_182 )
V_178 -> V_131 -> V_182 ( V_178 ) ;
}
int F_129 ( struct V_3 * V_4 , struct V_7 * V_65 ,
struct V_39 * V_158 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_16 = V_65 ;
V_4 -> V_17 = V_158 ;
F_113 ( V_158 ) ;
F_130 ( & V_158 -> V_173 , & V_4 -> V_183 , L_26 , V_4 ) ;
F_30 ( & V_4 -> V_61 ) ;
return 0 ;
}
void F_131 ( struct V_3 * V_4 )
{
struct V_39 * V_40 = V_4 -> V_17 ;
F_4 ( F_5 ( & V_4 -> V_61 ) ) ;
if ( V_40 ) {
F_132 ( & V_40 -> V_173 , & V_4 -> V_183 ,
L_26 , V_4 ) ;
F_118 ( V_40 ) ;
V_4 -> V_17 = NULL ;
}
}
void F_133 ( struct V_7 * V_65 , struct V_3 * V_4 )
{
F_42 ( & V_4 -> V_61 , & V_65 -> V_54 ) ;
}
void F_134 ( struct V_3 * V_184 , struct V_3 * V_4 )
{
F_42 ( & V_4 -> V_61 , & V_184 -> V_61 ) ;
}
int F_135 ( struct V_7 * V_65 )
{
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
F_79 ( & V_65 -> V_23 , 1 ) ;
F_136 ( & V_65 -> V_19 ) ;
F_30 ( & V_65 -> V_22 ) ;
F_30 ( & V_65 -> V_54 ) ;
F_125 ( & V_65 -> V_185 ) ;
return 0 ;
}
void F_137 ( struct V_7 * V_65 )
{
F_4 ( F_5 ( & V_65 -> V_54 ) ) ;
F_4 ( F_5 ( & V_65 -> V_22 ) ) ;
F_4 ( F_53 ( & V_65 -> V_19 ) ) ;
F_127 ( & V_65 -> V_185 ) ;
}
struct V_3 * F_76 ( struct V_7 * V_65 ,
const struct V_127 * V_186 )
{
struct V_3 * V_4 ;
F_28 (o, &h->loh_layers, lo_linkage) {
if ( V_4 -> V_17 -> V_100 == V_186 )
return V_4 ;
}
return NULL ;
}
void F_138 ( const struct V_1 * V_2 , struct V_39 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_18 ;
struct V_39 * V_44 ;
struct V_39 * V_20 ;
F_34 ( V_2 , V_10 , ~ 0 ) ;
for ( V_44 = V_8 ; V_44 ; V_44 = V_20 ) {
V_20 = V_44 -> V_100 -> V_131 -> V_187 ( V_2 , V_44 ) ;
F_117 ( & V_44 -> V_173 , L_27 , & F_105 ) ;
F_118 ( V_44 ) ;
}
F_34 ( V_2 , V_10 , ~ 0 ) ;
for ( V_44 = V_8 ; V_44 ; V_44 = V_20 ) {
const struct V_127 * V_128 = V_44 -> V_100 ;
struct V_188 * type ;
V_20 = V_128 -> V_131 -> V_189 ( V_2 , V_44 ) ;
type = V_128 -> V_190 ;
if ( type ) {
type -> V_191 -- ;
F_139 ( type ) ;
}
}
}
int F_140 ( struct V_192 * V_85 )
{
int V_50 ;
unsigned int V_73 ;
F_4 ( V_85 -> V_193 ) ;
F_4 ( V_85 -> V_194 ) ;
F_4 ( V_85 -> V_195 != 0 ) ;
V_50 = - V_196 ;
F_80 ( & V_197 ) ;
for ( V_73 = 0 ; V_73 < F_48 ( V_198 ) ; ++ V_73 ) {
if ( ! V_198 [ V_73 ] ) {
V_85 -> V_199 = V_73 ;
F_79 ( & V_85 -> V_200 , 1 ) ;
V_198 [ V_73 ] = V_85 ;
F_125 ( & V_85 -> V_201 ) ;
V_50 = 0 ;
++ V_202 ;
break;
}
}
F_82 ( & V_197 ) ;
return V_50 ;
}
static void F_141 ( struct V_203 * V_204 , int V_205 )
{
if ( V_204 -> V_206 && V_204 -> V_206 [ V_205 ] ) {
struct V_192 * V_85 ;
V_85 = V_198 [ V_205 ] ;
F_4 ( F_41 ( & V_85 -> V_200 ) > 1 ) ;
V_85 -> V_194 ( V_204 , V_85 , V_204 -> V_206 [ V_205 ] ) ;
F_117 ( & V_85 -> V_201 , L_28 , V_204 ) ;
F_122 ( & V_85 -> V_200 ) ;
if ( ( V_204 -> V_207 & V_208 ) == 0 ) {
#ifdef F_142
F_143 ( F_144 ( V_85 -> V_209 ) > 0 ) ;
#endif
F_145 ( V_85 -> V_209 ) ;
}
V_204 -> V_206 [ V_205 ] = NULL ;
}
}
void F_146 ( struct V_192 * V_85 )
{
F_4 ( F_41 ( & V_85 -> V_200 ) >= 1 ) ;
F_143 ( 0 <= V_85 -> V_199 && V_85 -> V_199 < F_48 ( V_198 ) ) ;
F_147 ( V_85 ) ;
++ V_202 ;
F_80 ( & V_197 ) ;
F_141 ( & V_175 . V_88 , V_85 -> V_199 ) ;
if ( V_198 [ V_85 -> V_199 ] ) {
V_198 [ V_85 -> V_199 ] = NULL ;
F_127 ( & V_85 -> V_201 ) ;
}
F_82 ( & V_197 ) ;
F_128 ( F_41 ( & V_85 -> V_200 ) == 1 ,
L_29 ,
F_41 ( & V_85 -> V_200 ) ) ;
}
int F_148 ( struct V_192 * V_210 , ... )
{
struct V_192 * V_85 = V_210 ;
T_1 args ;
int V_50 ;
va_start ( args , V_210 ) ;
do {
V_50 = F_140 ( V_85 ) ;
if ( V_50 )
break;
V_85 = va_arg ( args , struct V_192 * ) ;
} while ( V_85 );
va_end ( args ) ;
if ( V_50 != 0 ) {
va_start ( args , V_210 ) ;
while ( V_210 != V_85 ) {
F_146 ( V_210 ) ;
V_210 = va_arg ( args , struct V_192 * ) ;
}
va_end ( args ) ;
}
return V_50 ;
}
void F_149 ( struct V_192 * V_210 , ... )
{
T_1 args ;
va_start ( args , V_210 ) ;
do {
F_146 ( V_210 ) ;
V_210 = va_arg ( args , struct V_192 * ) ;
} while ( V_210 );
va_end ( args ) ;
}
void F_150 ( struct V_192 * V_210 , ... )
{
T_1 args ;
va_start ( args , V_210 ) ;
do {
F_151 ( V_210 ) ;
V_210 = va_arg ( args , struct V_192 * ) ;
} while ( V_210 );
va_end ( args ) ;
}
void F_152 ( struct V_192 * V_210 , ... )
{
T_1 args ;
va_start ( args , V_210 ) ;
do {
F_147 ( V_210 ) ;
V_210 = va_arg ( args , struct V_192 * ) ;
} while ( V_210 );
va_end ( args ) ;
}
void * F_47 ( const struct V_203 * V_204 ,
const struct V_192 * V_85 )
{
F_143 ( V_204 -> V_211 == V_212 ) ;
F_143 ( 0 <= V_85 -> V_199 && V_85 -> V_199 < F_48 ( V_198 ) ) ;
F_4 ( V_198 [ V_85 -> V_199 ] == V_85 ) ;
return V_204 -> V_206 [ V_85 -> V_199 ] ;
}
void F_147 ( struct V_192 * V_85 )
{
struct V_203 * V_204 ;
if ( ! ( V_85 -> V_195 & V_213 ) ) {
F_153 ( ~ 0 ) ;
V_85 -> V_195 |= V_213 ;
F_80 ( & V_197 ) ;
F_28 (ctx, &lu_context_remembered, lc_remember)
F_141 ( V_204 , V_85 -> V_199 ) ;
F_82 ( & V_197 ) ;
++ V_202 ;
}
}
void F_151 ( struct V_192 * V_85 )
{
V_85 -> V_195 &= ~ V_213 ;
++ V_202 ;
}
static void F_154 ( struct V_203 * V_204 )
{
unsigned int V_73 ;
if ( ! V_204 -> V_206 )
return;
for ( V_73 = 0 ; V_73 < F_48 ( V_198 ) ; ++ V_73 )
F_141 ( V_204 , V_73 ) ;
F_155 ( V_204 -> V_206 ) ;
V_204 -> V_206 = NULL ;
}
static int F_156 ( struct V_203 * V_204 )
{
unsigned int V_73 ;
F_143 ( V_204 -> V_206 ) ;
for ( V_73 = 0 ; V_73 < F_48 ( V_198 ) ; ++ V_73 ) {
struct V_192 * V_85 ;
V_85 = V_198 [ V_73 ] ;
if ( ! V_204 -> V_206 [ V_73 ] && V_85 &&
( V_85 -> V_195 & V_204 -> V_207 ) &&
! ( V_85 -> V_195 & V_213 ) ) {
void * V_214 ;
F_143 ( V_85 -> V_193 ) ;
F_143 ( V_85 -> V_199 == V_73 ) ;
V_214 = V_85 -> V_193 ( V_204 , V_85 ) ;
if ( F_27 ( V_214 ) )
return F_71 ( V_214 ) ;
if ( ! ( V_204 -> V_207 & V_208 ) )
F_157 ( V_85 -> V_209 ) ;
F_158 ( & V_85 -> V_201 , L_28 , V_204 ) ;
F_101 ( & V_85 -> V_200 ) ;
V_204 -> V_206 [ V_73 ] = V_214 ;
if ( V_85 -> V_215 )
V_204 -> V_207 |= V_216 ;
}
V_204 -> V_217 = V_202 ;
}
return 0 ;
}
static int F_159 ( struct V_203 * V_204 )
{
V_204 -> V_206 = F_160 ( F_48 ( V_198 ) , sizeof( V_204 -> V_206 [ 0 ] ) ,
V_218 ) ;
if ( F_58 ( V_204 -> V_206 ) )
return F_156 ( V_204 ) ;
return - V_53 ;
}
int F_161 ( struct V_203 * V_204 , T_5 V_219 )
{
int V_220 ;
memset ( V_204 , 0 , sizeof( * V_204 ) ) ;
V_204 -> V_211 = V_221 ;
V_204 -> V_207 = V_219 ;
if ( V_219 & V_222 ) {
F_80 ( & V_197 ) ;
F_81 ( & V_204 -> V_223 , & V_224 ) ;
F_82 ( & V_197 ) ;
} else {
F_30 ( & V_204 -> V_223 ) ;
}
V_220 = F_159 ( V_204 ) ;
if ( V_220 != 0 )
F_162 ( V_204 ) ;
return V_220 ;
}
void F_162 ( struct V_203 * V_204 )
{
F_143 ( V_204 -> V_211 == V_221 || V_204 -> V_211 == V_225 ) ;
V_204 -> V_211 = V_226 ;
if ( ( V_204 -> V_207 & V_222 ) == 0 ) {
F_4 ( F_5 ( & V_204 -> V_223 ) ) ;
F_154 ( V_204 ) ;
} else {
F_80 ( & V_197 ) ;
F_154 ( V_204 ) ;
F_23 ( & V_204 -> V_223 ) ;
F_82 ( & V_197 ) ;
}
}
void F_163 ( struct V_203 * V_204 )
{
F_143 ( V_204 -> V_211 == V_221 || V_204 -> V_211 == V_225 ) ;
V_204 -> V_211 = V_212 ;
}
void F_164 ( struct V_203 * V_204 )
{
unsigned int V_73 ;
F_143 ( V_204 -> V_211 == V_212 ) ;
V_204 -> V_211 = V_225 ;
if ( V_204 -> V_207 & V_216 && V_204 -> V_206 ) {
for ( V_73 = 0 ; V_73 < F_48 ( V_198 ) ; ++ V_73 ) {
if ( V_204 -> V_206 [ V_73 ] ) {
struct V_192 * V_85 ;
V_85 = V_198 [ V_73 ] ;
if ( V_85 -> V_215 )
V_85 -> V_215 ( V_204 ,
V_85 , V_204 -> V_206 [ V_73 ] ) ;
}
}
}
}
int F_121 ( struct V_203 * V_204 )
{
return F_58 ( V_204 -> V_217 == V_202 ) ? 0 : F_156 ( V_204 ) ;
}
int F_165 ( struct V_1 * V_2 , T_5 V_219 )
{
int V_50 ;
V_2 -> V_227 = NULL ;
V_50 = F_161 ( & V_2 -> V_88 , V_219 ) ;
if ( F_58 ( V_50 == 0 ) )
F_163 ( & V_2 -> V_88 ) ;
return V_50 ;
}
void F_166 ( struct V_1 * V_2 )
{
F_164 ( & V_2 -> V_88 ) ;
F_162 ( & V_2 -> V_88 ) ;
V_2 -> V_227 = NULL ;
}
int F_167 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_121 ( & V_2 -> V_88 ) ;
if ( V_50 == 0 && V_2 -> V_227 )
V_50 = F_121 ( V_2 -> V_227 ) ;
return V_50 ;
}
static void F_168 ( struct V_37 * V_120 ,
struct V_228 * V_229 , int V_230 )
{
struct V_12 V_13 ;
unsigned int V_73 ;
F_38 (hs, &bd, i) {
struct V_5 * V_6 = F_10 ( V_120 , & V_13 ) ;
struct V_231 * V_232 ;
F_39 ( V_120 , & V_13 , 1 ) ;
V_229 -> V_233 +=
F_169 ( & V_13 ) - V_6 -> V_30 ;
V_229 -> V_234 += F_169 ( & V_13 ) ;
V_229 -> V_235 = F_170 ( ( int ) V_229 -> V_235 ,
F_171 ( & V_13 ) ) ;
if ( ! V_230 ) {
F_17 ( V_120 , & V_13 , 1 ) ;
continue;
}
F_172 (hs, &bd, hhead) {
if ( ! F_173 ( V_232 ) )
V_229 -> V_236 ++ ;
}
F_17 ( V_120 , & V_13 , 1 ) ;
}
}
static unsigned long F_174 ( struct V_237 * V_238 ,
struct V_239 * V_240 )
{
struct V_9 * V_63 ;
struct V_9 * V_241 ;
unsigned long V_242 = 0 ;
if ( ! ( V_240 -> V_243 & V_244 ) )
return 0 ;
F_37 ( & V_174 ) ;
F_40 (s, tmp, &lu_sites, ls_linkage) {
V_242 += F_175 ( V_63 -> V_31 , V_32 ) ;
}
F_45 ( & V_174 ) ;
V_242 = ( V_242 / 100 ) * V_245 ;
F_16 ( V_33 , L_30 ,
V_242 , V_245 ) ;
return V_242 ;
}
static unsigned long F_176 ( struct V_237 * V_238 ,
struct V_239 * V_240 )
{
struct V_9 * V_63 ;
struct V_9 * V_241 ;
unsigned long V_246 = V_240 -> V_247 , V_248 = 0 ;
F_177 ( V_58 ) ;
if ( ! ( V_240 -> V_243 & V_244 ) )
return V_249 ;
F_37 ( & V_174 ) ;
F_40 (s, tmp, &lu_sites, ls_linkage) {
V_248 = F_34 ( & V_175 , V_63 , V_246 ) ;
V_246 -= V_248 ;
F_178 ( & V_63 -> V_172 , & V_58 ) ;
}
F_179 ( & V_58 , V_176 . V_60 ) ;
F_45 ( & V_174 ) ;
return V_240 -> V_247 - V_246 ;
}
int F_180 ( void )
{
int V_50 ;
F_16 ( V_250 , L_31 , & V_198 ) ;
V_50 = F_181 () ;
if ( V_50 != 0 )
return V_50 ;
F_182 ( & V_89 ) ;
V_50 = F_140 ( & V_89 ) ;
if ( V_50 != 0 )
return V_50 ;
F_37 ( & V_174 ) ;
V_50 = F_165 ( & V_175 , V_251 ) ;
F_45 ( & V_174 ) ;
if ( V_50 != 0 )
return V_50 ;
F_183 ( & V_252 ) ;
return V_50 ;
}
void F_184 ( void )
{
F_185 ( & V_252 ) ;
F_146 ( & V_89 ) ;
F_37 ( & V_174 ) ;
F_166 ( & V_175 ) ;
F_45 ( & V_174 ) ;
F_186 () ;
}
static T_5 F_175 ( struct V_253 * V_229 , int V_254 )
{
struct V_255 V_256 ;
F_187 ( V_229 , V_254 , & V_256 ) ;
if ( V_254 == V_32 )
return ( T_5 ) ( ( V_256 . V_257 > 0 ) ? V_256 . V_257 : 0 ) ;
return ( T_5 ) V_256 . V_258 ;
}
int F_188 ( const struct V_9 * V_63 , struct V_259 * V_260 )
{
struct V_228 V_229 ;
memset ( & V_229 , 0 , sizeof( V_229 ) ) ;
F_168 ( V_63 -> V_26 , & V_229 , 1 ) ;
F_189 ( V_260 , L_32 ,
V_229 . V_233 ,
V_229 . V_234 ,
V_229 . V_236 ,
F_190 ( V_63 -> V_26 ) ,
V_229 . V_235 ,
F_175 ( V_63 -> V_31 , V_57 ) ,
F_175 ( V_63 -> V_31 , V_110 ) ,
F_175 ( V_63 -> V_31 , V_109 ) ,
F_175 ( V_63 -> V_31 , V_124 ) ,
F_175 ( V_63 -> V_31 , V_113 ) ,
F_175 ( V_63 -> V_31 , V_79 ) ,
F_175 ( V_63 -> V_31 , V_32 ) ) ;
return 0 ;
}
int F_191 ( struct V_261 * V_262 )
{
int V_50 ;
struct V_261 * V_263 = V_262 ;
for ( V_50 = 0 ; V_263 -> V_264 ; ++ V_263 ) {
* V_263 -> V_264 = F_192 ( V_263 -> V_265 ,
V_263 -> V_266 ,
0 , 0 , NULL ) ;
if ( ! * V_263 -> V_264 ) {
V_50 = - V_53 ;
F_193 ( V_262 ) ;
break;
}
}
return V_50 ;
}
void F_193 ( struct V_261 * V_262 )
{
for (; V_262 -> V_264 ; ++ V_262 ) {
F_194 ( * V_262 -> V_264 ) ;
* V_262 -> V_264 = NULL ;
}
}
void F_195 ( struct V_267 * V_268 )
{
F_4 ( V_268 ) ;
if ( V_268 -> V_269 ) {
F_4 ( V_268 -> V_270 > 0 ) ;
F_196 ( V_268 -> V_269 ) ;
V_268 -> V_269 = NULL ;
V_268 -> V_270 = 0 ;
}
}
void F_197 ( struct V_267 * V_268 , T_6 V_116 )
{
F_4 ( V_268 ) ;
F_4 ( ! V_268 -> V_269 ) ;
F_4 ( ! V_268 -> V_270 ) ;
V_268 -> V_269 = F_198 ( V_116 , V_218 ) ;
if ( F_58 ( V_268 -> V_269 ) )
V_268 -> V_270 = V_116 ;
}
void F_199 ( struct V_267 * V_268 , T_6 V_116 )
{
F_195 ( V_268 ) ;
F_197 ( V_268 , V_116 ) ;
}
struct V_267 * F_200 ( struct V_267 * V_268 , T_6 V_271 )
{
if ( ! V_268 -> V_269 && ! V_268 -> V_270 )
F_197 ( V_268 , V_271 ) ;
if ( ( V_271 > V_268 -> V_270 ) && V_268 -> V_269 )
F_199 ( V_268 , V_271 ) ;
return V_268 ;
}
int F_201 ( struct V_267 * V_268 , T_6 V_271 )
{
char * V_272 ;
if ( V_271 <= V_268 -> V_270 )
return 0 ;
V_272 = F_198 ( V_271 , V_218 ) ;
if ( ! V_272 )
return - V_53 ;
if ( V_268 -> V_269 ) {
memcpy ( V_272 , V_268 -> V_269 , V_268 -> V_270 ) ;
F_196 ( V_268 -> V_269 ) ;
}
V_268 -> V_269 = V_272 ;
V_268 -> V_270 = V_271 ;
return 0 ;
}
