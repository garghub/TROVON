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
unsigned int V_70 = 0 ;
int V_71 ;
int V_72 ;
unsigned int V_73 ;
if ( F_35 ( V_74 ) )
return 0 ;
F_30 ( & V_68 ) ;
if ( V_64 != ~ 0 )
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
if ( ! strcmp ( V_8 -> V_100 -> V_101 , V_146 ) )
V_142 = V_147 ;
V_144 = V_148 ;
#if V_149 == 32
if ( V_144 > 1 << ( 30 - V_150 ) )
V_144 = 1 << ( 30 - V_150 ) * 3 / 4 ;
#endif
if ( V_151 == 0 || V_151 > V_152 ) {
F_89 ( L_14 ,
V_151 , V_152 ,
V_153 ) ;
V_151 = V_153 ;
}
V_144 = V_144 / 100 * V_151 *
( V_154 / 1024 ) ;
for ( V_145 = 1 ; ( 1 << V_145 ) < V_144 ; ++ V_145 ) {
;
}
return F_90 ( F_91 ( V_145 ) , V_145 , V_155 , V_142 ) ;
}
static unsigned int F_92 ( struct V_37 * V_120 ,
const void * V_85 , unsigned int V_156 )
{
struct V_14 * V_15 = (struct V_14 * ) V_85 ;
T_5 V_157 ;
V_157 = F_93 ( V_15 ) ;
V_157 += ( V_157 >> 4 ) + ( V_157 << 12 ) ;
V_157 = F_94 ( V_157 , V_120 -> V_158 ) ;
V_157 -= F_94 ( ( unsigned long ) V_120 , F_95 ( V_15 ) % 11 + 3 ) ;
V_157 <<= V_120 -> V_159 - V_120 -> V_158 ;
V_157 |= ( F_96 ( V_15 ) + F_95 ( V_15 ) ) & ( F_36 ( V_120 ) - 1 ) ;
return V_157 & V_156 ;
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
static void F_104 ( struct V_9 * V_63 , struct V_39 * V_160 )
{
F_80 ( & V_63 -> V_161 ) ;
if ( F_5 ( & V_160 -> V_162 ) )
F_81 ( & V_160 -> V_162 , & V_63 -> V_163 ) ;
F_82 ( & V_63 -> V_161 ) ;
}
int F_105 ( struct V_9 * V_63 , struct V_39 * V_8 )
{
struct V_5 * V_6 ;
struct V_12 V_13 ;
unsigned long V_145 ;
unsigned long V_73 ;
char V_164 [ 16 ] ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
F_106 ( & V_63 -> V_77 ) ;
snprintf ( V_164 , sizeof( V_164 ) , L_15 , V_8 -> V_100 -> V_101 ) ;
for ( V_145 = F_88 ( V_8 ) ; V_145 >= V_155 ; V_145 -- ) {
V_63 -> V_26 = F_107 ( V_164 , V_145 , V_145 ,
V_145 - V_165 ,
sizeof( * V_6 ) , 0 , 0 ,
& V_166 ,
V_167 |
V_168 |
V_169 |
V_170 |
V_171 ) ;
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
V_63 -> V_31 = F_110 ( V_172 , 0 ) ;
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
V_173 , L_23 , L_23 ) ;
F_30 ( & V_63 -> V_174 ) ;
V_63 -> V_115 = V_8 ;
V_8 -> V_18 = V_63 ;
F_113 ( V_8 ) ;
F_114 ( & V_8 -> V_175 , L_24 , V_63 ) ;
F_30 ( & V_63 -> V_163 ) ;
F_115 ( & V_63 -> V_161 ) ;
F_104 ( V_63 , V_8 ) ;
return 0 ;
}
void F_116 ( struct V_9 * V_63 )
{
F_37 ( & V_176 ) ;
F_23 ( & V_63 -> V_174 ) ;
F_45 ( & V_176 ) ;
if ( V_63 -> V_26 ) {
F_111 ( V_63 -> V_26 ) ;
V_63 -> V_26 = NULL ;
}
if ( V_63 -> V_115 ) {
V_63 -> V_115 -> V_18 = NULL ;
F_117 ( & V_63 -> V_115 -> V_175 , L_24 , V_63 ) ;
F_118 ( V_63 -> V_115 ) ;
V_63 -> V_115 = NULL ;
}
if ( V_63 -> V_31 )
F_119 ( & V_63 -> V_31 ) ;
}
int F_120 ( struct V_9 * V_63 )
{
int V_50 ;
F_37 ( & V_176 ) ;
V_50 = F_121 ( & V_177 . V_88 ) ;
if ( V_50 == 0 )
F_81 ( & V_63 -> V_174 , & V_178 ) ;
F_45 ( & V_176 ) ;
return V_50 ;
}
void F_113 ( struct V_39 * V_160 )
{
F_101 ( & V_160 -> V_179 ) ;
}
void F_118 ( struct V_39 * V_160 )
{
F_4 ( F_41 ( & V_160 -> V_179 ) > 0 ) ;
F_122 ( & V_160 -> V_179 ) ;
}
int F_123 ( struct V_39 * V_160 , struct V_127 * V_180 )
{
if ( F_124 ( & V_180 -> V_129 ) == 1 &&
V_180 -> V_131 -> V_181 )
V_180 -> V_131 -> V_181 ( V_180 ) ;
memset ( V_160 , 0 , sizeof( * V_160 ) ) ;
F_79 ( & V_160 -> V_179 , 0 ) ;
V_160 -> V_100 = V_180 ;
F_125 ( & V_160 -> V_175 ) ;
F_30 ( & V_160 -> V_162 ) ;
return 0 ;
}
void F_126 ( struct V_39 * V_160 )
{
struct V_127 * V_180 = V_160 -> V_100 ;
if ( V_160 -> V_182 ) {
V_160 -> V_182 -> V_183 = NULL ;
V_160 -> V_182 = NULL ;
}
F_127 ( & V_160 -> V_175 ) ;
F_128 ( F_41 ( & V_160 -> V_179 ) == 0 ,
L_25 , F_41 ( & V_160 -> V_179 ) ) ;
F_4 ( F_41 ( & V_180 -> V_129 ) > 0 ) ;
if ( F_6 ( & V_180 -> V_129 ) &&
V_180 -> V_131 -> V_184 )
V_180 -> V_131 -> V_184 ( V_180 ) ;
}
int F_129 ( struct V_3 * V_4 , struct V_7 * V_65 ,
struct V_39 * V_160 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_16 = V_65 ;
V_4 -> V_17 = V_160 ;
F_113 ( V_160 ) ;
F_130 ( & V_160 -> V_175 , & V_4 -> V_185 , L_26 , V_4 ) ;
F_30 ( & V_4 -> V_61 ) ;
return 0 ;
}
void F_131 ( struct V_3 * V_4 )
{
struct V_39 * V_40 = V_4 -> V_17 ;
F_4 ( F_5 ( & V_4 -> V_61 ) ) ;
if ( V_40 ) {
F_132 ( & V_40 -> V_175 , & V_4 -> V_185 ,
L_26 , V_4 ) ;
F_118 ( V_40 ) ;
V_4 -> V_17 = NULL ;
}
}
void F_133 ( struct V_7 * V_65 , struct V_3 * V_4 )
{
F_42 ( & V_4 -> V_61 , & V_65 -> V_54 ) ;
}
void F_134 ( struct V_3 * V_186 , struct V_3 * V_4 )
{
F_42 ( & V_4 -> V_61 , & V_186 -> V_61 ) ;
}
int F_135 ( struct V_7 * V_65 )
{
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
F_79 ( & V_65 -> V_23 , 1 ) ;
F_136 ( & V_65 -> V_19 ) ;
F_30 ( & V_65 -> V_22 ) ;
F_30 ( & V_65 -> V_54 ) ;
F_125 ( & V_65 -> V_187 ) ;
return 0 ;
}
void F_137 ( struct V_7 * V_65 )
{
F_4 ( F_5 ( & V_65 -> V_54 ) ) ;
F_4 ( F_5 ( & V_65 -> V_22 ) ) ;
F_4 ( F_53 ( & V_65 -> V_19 ) ) ;
F_127 ( & V_65 -> V_187 ) ;
}
struct V_3 * F_76 ( struct V_7 * V_65 ,
const struct V_127 * V_188 )
{
struct V_3 * V_4 ;
F_28 (o, &h->loh_layers, lo_linkage) {
if ( V_4 -> V_17 -> V_100 == V_188 )
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
V_20 = V_44 -> V_100 -> V_131 -> V_189 ( V_2 , V_44 ) ;
F_117 ( & V_44 -> V_175 , L_27 , & F_105 ) ;
F_118 ( V_44 ) ;
}
F_34 ( V_2 , V_10 , ~ 0 ) ;
for ( V_44 = V_8 ; V_44 ; V_44 = V_20 ) {
const struct V_127 * V_128 = V_44 -> V_100 ;
struct V_190 * type ;
V_20 = V_128 -> V_131 -> V_191 ( V_2 , V_44 ) ;
type = V_128 -> V_192 ;
if ( type ) {
type -> V_193 -- ;
F_139 ( type ) ;
}
}
}
int F_140 ( struct V_194 * V_85 )
{
int V_50 ;
unsigned int V_73 ;
F_4 ( V_85 -> V_195 ) ;
F_4 ( V_85 -> V_196 ) ;
F_4 ( V_85 -> V_197 != 0 ) ;
V_50 = - V_198 ;
F_80 ( & V_199 ) ;
for ( V_73 = 0 ; V_73 < F_48 ( V_200 ) ; ++ V_73 ) {
if ( ! V_200 [ V_73 ] ) {
V_85 -> V_201 = V_73 ;
F_79 ( & V_85 -> V_202 , 1 ) ;
V_200 [ V_73 ] = V_85 ;
F_125 ( & V_85 -> V_203 ) ;
V_50 = 0 ;
++ V_204 ;
break;
}
}
F_82 ( & V_199 ) ;
return V_50 ;
}
static void F_141 ( struct V_205 * V_206 , int V_207 )
{
if ( V_206 -> V_208 && V_206 -> V_208 [ V_207 ] ) {
struct V_194 * V_85 ;
V_85 = V_200 [ V_207 ] ;
F_4 ( F_41 ( & V_85 -> V_202 ) > 1 ) ;
V_85 -> V_196 ( V_206 , V_85 , V_206 -> V_208 [ V_207 ] ) ;
F_117 ( & V_85 -> V_203 , L_28 , V_206 ) ;
F_122 ( & V_85 -> V_202 ) ;
if ( ( V_206 -> V_209 & V_210 ) == 0 ) {
#ifdef F_142
F_143 ( F_144 ( V_85 -> V_211 ) > 0 ) ;
#endif
F_145 ( V_85 -> V_211 ) ;
}
V_206 -> V_208 [ V_207 ] = NULL ;
}
}
void F_146 ( struct V_194 * V_85 )
{
F_4 ( F_41 ( & V_85 -> V_202 ) >= 1 ) ;
F_143 ( 0 <= V_85 -> V_201 && V_85 -> V_201 < F_48 ( V_200 ) ) ;
F_147 ( V_85 ) ;
++ V_204 ;
F_80 ( & V_199 ) ;
F_141 ( & V_177 . V_88 , V_85 -> V_201 ) ;
while ( F_41 ( & V_85 -> V_202 ) > 1 ) {
F_82 ( & V_199 ) ;
F_16 ( V_212 , L_29 ,
V_85 -> V_211 ? V_85 -> V_211 -> V_164 : L_5 , V_85 ,
F_41 ( & V_85 -> V_202 ) ) ;
F_73 () ;
F_80 ( & V_199 ) ;
}
if ( V_200 [ V_85 -> V_201 ] ) {
V_200 [ V_85 -> V_201 ] = NULL ;
F_127 ( & V_85 -> V_203 ) ;
}
F_82 ( & V_199 ) ;
F_128 ( F_41 ( & V_85 -> V_202 ) == 1 ,
L_30 ,
F_41 ( & V_85 -> V_202 ) ) ;
}
int F_148 ( struct V_194 * V_213 , ... )
{
struct V_194 * V_85 = V_213 ;
T_1 args ;
int V_50 ;
va_start ( args , V_213 ) ;
do {
V_50 = F_140 ( V_85 ) ;
if ( V_50 )
break;
V_85 = va_arg ( args , struct V_194 * ) ;
} while ( V_85 );
va_end ( args ) ;
if ( V_50 != 0 ) {
va_start ( args , V_213 ) ;
while ( V_213 != V_85 ) {
F_146 ( V_213 ) ;
V_213 = va_arg ( args , struct V_194 * ) ;
}
va_end ( args ) ;
}
return V_50 ;
}
void F_149 ( struct V_194 * V_213 , ... )
{
T_1 args ;
va_start ( args , V_213 ) ;
do {
F_146 ( V_213 ) ;
V_213 = va_arg ( args , struct V_194 * ) ;
} while ( V_213 );
va_end ( args ) ;
}
void F_150 ( struct V_194 * V_213 , ... )
{
T_1 args ;
va_start ( args , V_213 ) ;
do {
F_151 ( V_213 ) ;
V_213 = va_arg ( args , struct V_194 * ) ;
} while ( V_213 );
va_end ( args ) ;
}
void F_152 ( struct V_194 * V_213 , ... )
{
T_1 args ;
va_start ( args , V_213 ) ;
do {
F_147 ( V_213 ) ;
V_213 = va_arg ( args , struct V_194 * ) ;
} while ( V_213 );
va_end ( args ) ;
}
void * F_47 ( const struct V_205 * V_206 ,
const struct V_194 * V_85 )
{
F_143 ( V_206 -> V_214 == V_215 ) ;
F_143 ( 0 <= V_85 -> V_201 && V_85 -> V_201 < F_48 ( V_200 ) ) ;
F_4 ( V_200 [ V_85 -> V_201 ] == V_85 ) ;
return V_206 -> V_208 [ V_85 -> V_201 ] ;
}
void F_147 ( struct V_194 * V_85 )
{
struct V_205 * V_206 ;
if ( ! ( V_85 -> V_197 & V_216 ) ) {
F_80 ( & V_199 ) ;
V_85 -> V_197 |= V_216 ;
while ( F_41 ( & V_217 ) > 0 ) {
F_82 ( & V_199 ) ;
F_16 ( V_212 , L_31 ,
V_85 -> V_211 ? V_85 -> V_211 -> V_164 : L_5 ,
V_85 , F_41 ( & V_85 -> V_202 ) ,
F_41 ( & V_217 ) ) ;
F_73 () ;
F_80 ( & V_199 ) ;
}
F_28 (ctx, &lu_context_remembered, lc_remember)
F_141 ( V_206 , V_85 -> V_201 ) ;
F_82 ( & V_199 ) ;
++ V_204 ;
}
}
void F_151 ( struct V_194 * V_85 )
{
V_85 -> V_197 &= ~ V_216 ;
++ V_204 ;
}
static void F_153 ( struct V_205 * V_206 )
{
unsigned int V_73 ;
if ( ! V_206 -> V_208 )
return;
for ( V_73 = 0 ; V_73 < F_48 ( V_200 ) ; ++ V_73 )
F_141 ( V_206 , V_73 ) ;
F_154 ( V_206 -> V_208 ) ;
V_206 -> V_208 = NULL ;
}
static int F_155 ( struct V_205 * V_206 )
{
unsigned int V_73 ;
F_80 ( & V_199 ) ;
F_101 ( & V_217 ) ;
F_82 ( & V_199 ) ;
F_143 ( V_206 -> V_208 ) ;
for ( V_73 = 0 ; V_73 < F_48 ( V_200 ) ; ++ V_73 ) {
struct V_194 * V_85 ;
V_85 = V_200 [ V_73 ] ;
if ( ! V_206 -> V_208 [ V_73 ] && V_85 &&
( V_85 -> V_197 & V_206 -> V_209 ) &&
! ( V_85 -> V_197 & V_216 ) ) {
void * V_218 ;
F_143 ( V_85 -> V_195 ) ;
F_143 ( V_85 -> V_201 == V_73 ) ;
F_4 ( V_85 -> V_211 ) ;
if ( ! ( V_206 -> V_209 & V_210 ) &&
! F_156 ( V_85 -> V_211 ) ) {
continue;
}
V_218 = V_85 -> V_195 ( V_206 , V_85 ) ;
if ( F_77 ( F_27 ( V_218 ) ) ) {
F_122 ( & V_217 ) ;
return F_71 ( V_218 ) ;
}
F_157 ( & V_85 -> V_203 , L_28 , V_206 ) ;
F_101 ( & V_85 -> V_202 ) ;
V_206 -> V_208 [ V_73 ] = V_218 ;
if ( V_85 -> V_219 )
V_206 -> V_209 |= V_220 ;
}
V_206 -> V_221 = V_204 ;
}
F_122 ( & V_217 ) ;
return 0 ;
}
static int F_158 ( struct V_205 * V_206 )
{
V_206 -> V_208 = F_159 ( F_48 ( V_200 ) , sizeof( V_206 -> V_208 [ 0 ] ) ,
V_222 ) ;
if ( F_58 ( V_206 -> V_208 ) )
return F_155 ( V_206 ) ;
return - V_53 ;
}
int F_160 ( struct V_205 * V_206 , T_5 V_223 )
{
int V_224 ;
memset ( V_206 , 0 , sizeof( * V_206 ) ) ;
V_206 -> V_214 = V_225 ;
V_206 -> V_209 = V_223 ;
if ( V_223 & V_226 ) {
F_80 ( & V_199 ) ;
F_81 ( & V_206 -> V_227 , & V_228 ) ;
F_82 ( & V_199 ) ;
} else {
F_30 ( & V_206 -> V_227 ) ;
}
V_224 = F_158 ( V_206 ) ;
if ( V_224 != 0 )
F_161 ( V_206 ) ;
return V_224 ;
}
void F_161 ( struct V_205 * V_206 )
{
F_143 ( V_206 -> V_214 == V_225 || V_206 -> V_214 == V_229 ) ;
V_206 -> V_214 = V_230 ;
if ( ( V_206 -> V_209 & V_226 ) == 0 ) {
F_4 ( F_5 ( & V_206 -> V_227 ) ) ;
F_153 ( V_206 ) ;
} else {
F_80 ( & V_199 ) ;
F_153 ( V_206 ) ;
F_23 ( & V_206 -> V_227 ) ;
F_82 ( & V_199 ) ;
}
}
void F_162 ( struct V_205 * V_206 )
{
F_143 ( V_206 -> V_214 == V_225 || V_206 -> V_214 == V_229 ) ;
V_206 -> V_214 = V_215 ;
}
void F_163 ( struct V_205 * V_206 )
{
unsigned int V_73 ;
F_143 ( V_206 -> V_214 == V_215 ) ;
V_206 -> V_214 = V_229 ;
if ( V_206 -> V_209 & V_220 && V_206 -> V_208 ) {
for ( V_73 = 0 ; V_73 < F_48 ( V_200 ) ; ++ V_73 ) {
if ( V_206 -> V_209 & V_226 )
F_80 ( & V_199 ) ;
if ( V_206 -> V_208 [ V_73 ] ) {
struct V_194 * V_85 ;
V_85 = V_200 [ V_73 ] ;
if ( V_85 -> V_219 )
V_85 -> V_219 ( V_206 ,
V_85 , V_206 -> V_208 [ V_73 ] ) ;
}
if ( V_206 -> V_209 & V_226 )
F_82 ( & V_199 ) ;
}
}
}
int F_121 ( struct V_205 * V_206 )
{
return F_58 ( V_206 -> V_221 == V_204 ) ? 0 : F_155 ( V_206 ) ;
}
int F_164 ( struct V_1 * V_2 , T_5 V_223 )
{
int V_50 ;
V_2 -> V_231 = NULL ;
V_50 = F_160 ( & V_2 -> V_88 , V_223 ) ;
if ( F_58 ( V_50 == 0 ) )
F_162 ( & V_2 -> V_88 ) ;
return V_50 ;
}
void F_165 ( struct V_1 * V_2 )
{
F_163 ( & V_2 -> V_88 ) ;
F_161 ( & V_2 -> V_88 ) ;
V_2 -> V_231 = NULL ;
}
int F_166 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_121 ( & V_2 -> V_88 ) ;
if ( V_50 == 0 && V_2 -> V_231 )
V_50 = F_121 ( V_2 -> V_231 ) ;
return V_50 ;
}
static void F_167 ( struct V_37 * V_120 ,
struct V_232 * V_233 , int V_234 )
{
struct V_12 V_13 ;
unsigned int V_73 ;
F_38 (hs, &bd, i) {
struct V_5 * V_6 = F_10 ( V_120 , & V_13 ) ;
struct V_235 * V_236 ;
F_39 ( V_120 , & V_13 , 1 ) ;
V_233 -> V_237 +=
F_168 ( & V_13 ) - V_6 -> V_30 ;
V_233 -> V_238 += F_168 ( & V_13 ) ;
V_233 -> V_239 = F_169 ( ( int ) V_233 -> V_239 ,
F_170 ( & V_13 ) ) ;
if ( ! V_234 ) {
F_17 ( V_120 , & V_13 , 1 ) ;
continue;
}
F_171 (hs, &bd, hhead) {
if ( ! F_172 ( V_236 ) )
V_233 -> V_240 ++ ;
}
F_17 ( V_120 , & V_13 , 1 ) ;
}
}
static unsigned long F_173 ( struct V_241 * V_242 ,
struct V_243 * V_244 )
{
struct V_9 * V_63 ;
struct V_9 * V_245 ;
unsigned long V_246 = 0 ;
if ( ! ( V_244 -> V_247 & V_248 ) )
return 0 ;
F_37 ( & V_176 ) ;
F_40 (s, tmp, &lu_sites, ls_linkage) {
V_246 += F_174 ( V_63 -> V_31 , V_32 ) ;
}
F_45 ( & V_176 ) ;
V_246 = ( V_246 / 100 ) * V_249 ;
F_16 ( V_33 , L_32 ,
V_246 , V_249 ) ;
return V_246 ;
}
static unsigned long F_175 ( struct V_241 * V_242 ,
struct V_243 * V_244 )
{
struct V_9 * V_63 ;
struct V_9 * V_245 ;
unsigned long V_250 = V_244 -> V_251 , V_252 = 0 ;
F_176 ( V_58 ) ;
if ( ! ( V_244 -> V_247 & V_248 ) )
return V_253 ;
F_37 ( & V_176 ) ;
F_40 (s, tmp, &lu_sites, ls_linkage) {
V_252 = F_34 ( & V_177 , V_63 , V_250 ) ;
V_250 -= V_252 ;
F_177 ( & V_63 -> V_174 , & V_58 ) ;
}
F_178 ( & V_58 , V_178 . V_60 ) ;
F_45 ( & V_176 ) ;
return V_244 -> V_251 - V_250 ;
}
int F_179 ( void )
{
int V_50 ;
F_16 ( V_212 , L_33 , & V_200 ) ;
V_50 = F_180 () ;
if ( V_50 != 0 )
return V_50 ;
F_181 ( & V_89 ) ;
V_50 = F_140 ( & V_89 ) ;
if ( V_50 != 0 )
return V_50 ;
F_37 ( & V_176 ) ;
V_50 = F_164 ( & V_177 , V_254 ) ;
F_45 ( & V_176 ) ;
if ( V_50 != 0 )
return V_50 ;
F_182 ( & V_255 ) ;
return V_50 ;
}
void F_183 ( void )
{
F_184 ( & V_255 ) ;
F_146 ( & V_89 ) ;
F_37 ( & V_176 ) ;
F_165 ( & V_177 ) ;
F_45 ( & V_176 ) ;
F_185 () ;
}
static T_5 F_174 ( struct V_256 * V_233 , int V_257 )
{
struct V_258 V_259 ;
F_186 ( V_233 , V_257 , & V_259 ) ;
if ( V_257 == V_32 )
return ( T_5 ) ( ( V_259 . V_260 > 0 ) ? V_259 . V_260 : 0 ) ;
return ( T_5 ) V_259 . V_261 ;
}
int F_187 ( const struct V_9 * V_63 , struct V_262 * V_263 )
{
struct V_232 V_233 ;
memset ( & V_233 , 0 , sizeof( V_233 ) ) ;
F_167 ( V_63 -> V_26 , & V_233 , 1 ) ;
F_188 ( V_263 , L_34 ,
V_233 . V_237 ,
V_233 . V_238 ,
V_233 . V_240 ,
F_189 ( V_63 -> V_26 ) ,
V_233 . V_239 ,
F_174 ( V_63 -> V_31 , V_57 ) ,
F_174 ( V_63 -> V_31 , V_110 ) ,
F_174 ( V_63 -> V_31 , V_109 ) ,
F_174 ( V_63 -> V_31 , V_124 ) ,
F_174 ( V_63 -> V_31 , V_113 ) ,
F_174 ( V_63 -> V_31 , V_79 ) ,
F_174 ( V_63 -> V_31 , V_32 ) ) ;
return 0 ;
}
int F_190 ( struct V_264 * V_265 )
{
int V_50 ;
struct V_264 * V_266 = V_265 ;
for ( V_50 = 0 ; V_266 -> V_267 ; ++ V_266 ) {
* V_266 -> V_267 = F_191 ( V_266 -> V_268 ,
V_266 -> V_269 ,
0 , 0 , NULL ) ;
if ( ! * V_266 -> V_267 ) {
V_50 = - V_53 ;
F_192 ( V_265 ) ;
break;
}
}
return V_50 ;
}
void F_192 ( struct V_264 * V_265 )
{
for (; V_265 -> V_267 ; ++ V_265 ) {
F_193 ( * V_265 -> V_267 ) ;
* V_265 -> V_267 = NULL ;
}
}
void F_194 ( struct V_270 * V_271 )
{
F_4 ( V_271 ) ;
if ( V_271 -> V_272 ) {
F_4 ( V_271 -> V_273 > 0 ) ;
F_195 ( V_271 -> V_272 ) ;
V_271 -> V_272 = NULL ;
V_271 -> V_273 = 0 ;
}
}
void F_196 ( struct V_270 * V_271 , T_6 V_116 )
{
F_4 ( V_271 ) ;
F_4 ( ! V_271 -> V_272 ) ;
F_4 ( ! V_271 -> V_273 ) ;
V_271 -> V_272 = F_197 ( V_116 , V_222 ) ;
if ( F_58 ( V_271 -> V_272 ) )
V_271 -> V_273 = V_116 ;
}
void F_198 ( struct V_270 * V_271 , T_6 V_116 )
{
F_194 ( V_271 ) ;
F_196 ( V_271 , V_116 ) ;
}
struct V_270 * F_199 ( struct V_270 * V_271 , T_6 V_274 )
{
if ( ! V_271 -> V_272 && ! V_271 -> V_273 )
F_196 ( V_271 , V_274 ) ;
if ( ( V_274 > V_271 -> V_273 ) && V_271 -> V_272 )
F_198 ( V_271 , V_274 ) ;
return V_271 ;
}
int F_200 ( struct V_270 * V_271 , T_6 V_274 )
{
char * V_275 ;
if ( V_274 <= V_271 -> V_273 )
return 0 ;
V_275 = F_197 ( V_274 , V_222 ) ;
if ( ! V_275 )
return - V_53 ;
if ( V_271 -> V_272 ) {
memcpy ( V_275 , V_271 -> V_272 , V_271 -> V_273 ) ;
F_195 ( V_271 -> V_272 ) ;
}
V_271 -> V_272 = V_275 ;
V_271 -> V_273 = V_274 ;
return 0 ;
}
