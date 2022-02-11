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
F_15 ( & V_10 -> V_31 ) ;
F_16 ( V_32 , L_1 ,
V_4 , V_10 -> V_26 , V_6 , V_6 -> V_30 ) ;
F_17 ( V_10 -> V_26 , & V_13 , 1 ) ;
return;
}
if ( ! F_18 ( V_33 , & V_8 -> V_34 ) )
F_19 ( V_10 -> V_26 , & V_13 , & V_8 -> V_19 ) ;
F_17 ( V_10 -> V_26 , & V_13 , 1 ) ;
F_8 ( V_2 , V_11 ) ;
}
void F_20 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 ;
V_8 = V_4 -> V_16 ;
F_21 ( V_35 , & V_8 -> V_34 ) ;
if ( ! F_18 ( V_33 , & V_8 -> V_34 ) ) {
struct V_9 * V_10 = V_4 -> V_17 -> V_18 ;
struct V_36 * V_37 = V_10 -> V_26 ;
struct V_12 V_13 ;
F_22 ( V_37 , & V_8 -> V_27 , & V_13 , 1 ) ;
if ( ! F_5 ( & V_8 -> V_22 ) ) {
struct V_5 * V_6 ;
F_23 ( & V_8 -> V_22 ) ;
V_6 = F_10 ( V_37 , & V_13 ) ;
V_6 -> V_30 -- ;
F_24 ( & V_10 -> V_31 ) ;
}
F_19 ( V_37 , & V_13 , & V_8 -> V_19 ) ;
F_17 ( V_37 , & V_13 , 1 ) ;
}
}
static struct V_3 * F_25 ( const struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_14 * V_40 ,
const struct V_41 * V_42 )
{
struct V_3 * V_43 ;
struct V_3 * V_8 ;
struct V_44 * V_45 ;
unsigned int V_46 = 0 ;
unsigned int V_47 ;
int V_48 ;
int V_49 ;
V_8 = V_39 -> V_50 -> V_51 ( V_2 , NULL , V_39 ) ;
if ( ! V_8 )
return F_26 ( - V_52 ) ;
if ( F_27 ( V_8 ) )
return V_8 ;
V_8 -> V_16 -> V_27 = * V_40 ;
V_45 = & V_8 -> V_16 -> V_53 ;
do {
V_48 = 1 ;
V_47 = 1 ;
F_28 (scan, layers, lo_linkage) {
if ( V_46 & V_47 )
goto V_20;
V_48 = 0 ;
V_43 -> V_16 = V_8 -> V_16 ;
V_49 = V_43 -> V_24 -> V_54 ( V_2 , V_43 , V_42 ) ;
if ( V_49 != 0 ) {
F_8 ( V_2 , V_8 ) ;
return F_26 ( V_49 ) ;
}
V_46 |= V_47 ;
V_20:
V_47 <<= 1 ;
}
} while ( ! V_48 );
F_7 (scan, layers, lo_linkage) {
if ( V_43 -> V_24 -> V_55 ) {
V_49 = V_43 -> V_24 -> V_55 ( V_2 , V_43 ) ;
if ( V_49 != 0 ) {
F_8 ( V_2 , V_8 ) ;
return F_26 ( V_49 ) ;
}
}
}
F_29 ( V_39 -> V_18 -> V_56 , V_57 ) ;
return V_8 ;
}
static void F_8 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_9 * V_10 ;
struct V_3 * V_43 ;
struct V_44 * V_45 ;
struct V_44 V_58 ;
V_10 = V_4 -> V_17 -> V_18 ;
V_45 = & V_4 -> V_16 -> V_53 ;
V_6 = F_30 ( V_10 , & V_4 -> V_16 -> V_27 ) ;
F_7 (scan, layers, lo_linkage) {
if ( V_43 -> V_24 -> V_59 )
V_43 -> V_24 -> V_59 ( V_2 , V_43 ) ;
}
F_31 ( & V_58 ) ;
F_32 ( V_45 , & V_58 ) ;
while ( ! F_5 ( & V_58 ) ) {
V_4 = F_33 ( V_58 . V_60 , struct V_3 , V_61 ) ;
F_23 ( & V_4 -> V_61 ) ;
V_4 -> V_24 -> V_62 ( V_2 , V_4 ) ;
}
if ( F_34 ( & V_6 -> V_28 ) )
F_13 ( & V_6 -> V_28 ) ;
}
int F_35 ( const struct V_1 * V_2 , struct V_9 * V_63 ,
int V_64 , bool V_65 )
{
struct V_7 * V_66 ;
struct V_7 * V_67 ;
struct V_5 * V_6 ;
struct V_12 V_13 ;
struct V_12 V_68 ;
struct V_44 V_69 ;
int V_70 ;
unsigned int V_71 = 0 ;
int V_72 ;
int V_73 ;
unsigned int V_74 ;
if ( F_36 ( V_75 ) )
return 0 ;
F_31 ( & V_69 ) ;
if ( V_64 != ~ 0 )
V_71 = V_63 -> V_76 ;
V_73 = ( V_64 == ~ 0 ) ? - 1 : V_64 / ( int ) F_37 ( V_63 -> V_26 ) + 1 ;
V_77:
if ( V_65 )
F_38 ( & V_63 -> V_78 ) ;
else if ( ! F_39 ( & V_63 -> V_78 ) )
goto V_79;
V_70 = 0 ;
F_40 (s->ls_obj_hash, &bd, i) {
if ( V_74 < V_71 )
continue;
V_72 = V_73 ;
F_41 ( V_63 -> V_26 , & V_13 , 1 ) ;
V_6 = F_10 ( V_63 -> V_26 , & V_13 ) ;
F_42 (h, temp, &bkt->lsb_lru, loh_lru) {
F_4 ( F_43 ( & V_66 -> V_23 ) == 0 ) ;
F_9 ( V_63 -> V_26 , & V_66 -> V_27 , & V_68 ) ;
F_4 ( V_13 . V_80 == V_68 . V_80 ) ;
F_19 ( V_63 -> V_26 ,
& V_68 , & V_66 -> V_19 ) ;
F_44 ( & V_66 -> V_22 , & V_69 ) ;
V_6 -> V_30 -- ;
F_24 ( & V_63 -> V_31 ) ;
if ( V_70 == 0 )
V_70 = 1 ;
if ( V_64 != ~ 0 && -- V_64 == 0 )
break;
if ( V_72 > 0 && -- V_72 == 0 )
break;
}
F_17 ( V_63 -> V_26 , & V_13 , 1 ) ;
F_45 () ;
while ( ! F_5 ( & V_69 ) ) {
V_66 = F_33 ( V_69 . V_20 ,
struct V_7 , V_22 ) ;
F_23 ( & V_66 -> V_22 ) ;
F_8 ( V_2 , F_46 ( V_66 ) ) ;
F_29 ( V_63 -> V_56 , V_81 ) ;
}
if ( V_64 == 0 )
break;
}
F_47 ( & V_63 -> V_78 ) ;
if ( V_64 != 0 && V_70 && V_71 != 0 ) {
V_71 = 0 ;
goto V_77;
}
V_63 -> V_76 = V_74 % F_37 ( V_63 -> V_26 ) ;
V_79:
return V_64 ;
}
int F_48 ( const struct V_1 * V_2 ,
void * V_82 , const char * V_83 , ... )
{
struct V_84 * V_85 = V_82 ;
struct V_86 * V_87 ;
int V_88 ;
int V_89 ;
T_1 args ;
va_start ( args , V_83 ) ;
V_87 = F_49 ( & V_2 -> V_90 , & V_91 ) ;
V_88 = strlen ( V_87 -> V_92 ) ;
V_89 = V_83 [ strlen ( V_83 ) - 1 ] == '\n' ;
vsnprintf ( V_87 -> V_92 + V_88 ,
F_50 ( V_87 -> V_92 ) - V_88 , V_83 , args ) ;
if ( V_89 ) {
if ( F_51 ( V_85 -> V_93 , V_85 -> V_94 ) )
F_52 ( V_85 , L_2 , V_87 -> V_92 ) ;
V_87 -> V_92 [ 0 ] = 0 ;
}
va_end ( args ) ;
return 0 ;
}
void F_53 ( const struct V_1 * V_2 , void * V_82 ,
T_2 V_95 ,
const struct V_7 * V_96 )
{
(* V_95)( V_2 , V_82 , L_3 V_97 L_4 ,
V_96 , V_96 -> V_34 , F_43 ( & V_96 -> V_23 ) ,
F_54 ( & V_96 -> V_27 ) ,
F_55 ( & V_96 -> V_19 ) ? L_5 : L_6 ,
F_5 ( (struct V_44 * ) & V_96 -> V_22 ) ? \
L_5 : L_7 ,
V_96 -> V_98 & V_99 ? L_8 : L_5 ) ;
}
void F_56 ( const struct V_1 * V_2 , void * V_82 ,
T_2 V_95 , const struct V_3 * V_4 )
{
static const char V_100 [] = L_9 ;
struct V_7 * V_8 ;
int V_101 = 4 ;
V_8 = V_4 -> V_16 ;
F_53 ( V_2 , V_82 , V_95 , V_8 ) ;
(* V_95)( V_2 , V_82 , L_10 ) ;
F_28 (o, &top->loh_layers, lo_linkage) {
(* V_95)( V_2 , V_82 , L_11 , V_101 , V_101 , V_100 ,
V_4 -> V_17 -> V_102 -> V_103 , V_4 ) ;
if ( V_4 -> V_24 -> V_104 )
(* V_4 -> V_24 -> V_104 )( V_2 , V_82 , V_95 , V_4 ) ;
(* V_95)( V_2 , V_82 , L_12 ) ;
}
(* V_95)( V_2 , V_82 , L_13 , V_8 ) ;
}
static struct V_3 * F_57 ( struct V_9 * V_63 ,
struct V_12 * V_13 ,
const struct V_14 * V_40 ,
T_3 * V_105 ,
T_4 * V_106 )
{
struct V_5 * V_6 ;
struct V_7 * V_66 ;
struct V_107 * V_108 ;
T_4 V_109 = F_58 ( V_13 ) ;
if ( * V_106 == V_109 )
return F_26 ( - V_110 ) ;
* V_106 = V_109 ;
V_6 = F_10 ( V_63 -> V_26 , V_13 ) ;
V_108 = F_59 ( V_63 -> V_26 , V_13 , ( void * ) V_40 ) ;
if ( ! V_108 ) {
F_29 ( V_63 -> V_56 , V_111 ) ;
return F_26 ( - V_110 ) ;
}
V_66 = F_33 ( V_108 , struct V_7 , V_19 ) ;
if ( F_60 ( ! F_12 ( V_66 ) ) ) {
F_61 ( V_63 -> V_26 , V_108 ) ;
F_29 ( V_63 -> V_56 , V_112 ) ;
if ( ! F_5 ( & V_66 -> V_22 ) ) {
F_23 ( & V_66 -> V_22 ) ;
V_6 -> V_30 -- ;
F_24 ( & V_63 -> V_31 ) ;
}
return F_46 ( V_66 ) ;
}
F_62 ( V_105 , V_113 ) ;
F_63 ( & V_6 -> V_28 , V_105 ) ;
F_64 ( V_114 ) ;
F_29 ( V_63 -> V_56 , V_115 ) ;
return F_26 ( - V_116 ) ;
}
static struct V_3 * F_65 ( const struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_14 * V_40 ,
const struct V_41 * V_42 )
{
return F_66 ( V_2 , V_39 -> V_18 -> V_117 , V_40 , V_42 ) ;
}
static void F_67 ( const struct V_1 * V_2 , struct V_38 * V_39 )
{
T_4 V_118 , V_64 ;
if ( V_119 == V_120 )
return;
V_118 = F_68 ( V_39 -> V_18 -> V_26 ) ;
V_64 = ( T_4 ) V_119 ;
if ( V_118 <= V_64 )
return;
F_35 ( V_2 , V_39 -> V_18 ,
F_69 ( T_4 , V_118 - V_64 , V_121 ) ,
false ) ;
}
static struct V_3 * F_70 ( const struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_14 * V_40 ,
const struct V_41 * V_42 )
{
struct V_3 * V_4 ;
struct V_36 * V_122 ;
struct V_12 V_13 ;
V_4 = F_25 ( V_2 , V_39 , V_40 , V_42 ) ;
if ( F_27 ( V_4 ) )
return V_4 ;
V_122 = V_39 -> V_18 -> V_26 ;
F_22 ( V_122 , ( void * ) V_40 , & V_13 , 1 ) ;
F_71 ( V_122 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
F_17 ( V_122 , & V_13 , 1 ) ;
F_67 ( V_2 , V_39 ) ;
return V_4 ;
}
static struct V_3 * F_72 ( const struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_14 * V_40 ,
const struct V_41 * V_42 ,
T_3 * V_105 )
{
struct V_3 * V_4 ;
struct V_3 * V_123 ;
struct V_9 * V_63 ;
struct V_36 * V_122 ;
struct V_12 V_13 ;
T_4 V_106 = 0 ;
if ( V_42 && V_42 -> V_124 & V_125 )
return F_70 ( V_2 , V_39 , V_40 , V_42 ) ;
V_63 = V_39 -> V_18 ;
V_122 = V_63 -> V_26 ;
F_22 ( V_122 , ( void * ) V_40 , & V_13 , 1 ) ;
V_4 = F_57 ( V_63 , & V_13 , V_40 , V_105 , & V_106 ) ;
F_17 ( V_122 , & V_13 , 1 ) ;
if ( ! F_27 ( V_4 ) || F_73 ( V_4 ) != - V_110 )
return V_4 ;
V_4 = F_25 ( V_2 , V_39 , V_40 , V_42 ) ;
if ( F_27 ( V_4 ) )
return V_4 ;
F_4 ( F_74 ( F_2 ( V_4 ) , V_40 ) ) ;
F_41 ( V_122 , & V_13 , 1 ) ;
V_123 = F_57 ( V_63 , & V_13 , V_40 , V_105 , & V_106 ) ;
if ( F_60 ( F_73 ( V_123 ) == - V_110 ) ) {
F_71 ( V_122 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
F_17 ( V_122 , & V_13 , 1 ) ;
F_67 ( V_2 , V_39 ) ;
return V_4 ;
}
F_29 ( V_63 -> V_56 , V_126 ) ;
F_17 ( V_122 , & V_13 , 1 ) ;
F_8 ( V_2 , V_4 ) ;
return V_123 ;
}
struct V_3 * F_66 ( const struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_14 * V_40 ,
const struct V_41 * V_42 )
{
struct V_5 * V_6 ;
struct V_3 * V_127 ;
T_3 V_128 ;
while ( 1 ) {
V_127 = F_72 ( V_2 , V_39 , V_40 , V_42 , & V_128 ) ;
if ( V_127 != F_26 ( - V_116 ) )
return V_127 ;
F_75 () ;
V_6 = F_30 ( V_39 -> V_18 , ( void * ) V_40 ) ;
F_76 ( & V_6 -> V_28 , & V_128 ) ;
}
}
struct V_3 * F_77 ( const struct V_1 * V_2 ,
struct V_38 * V_39 ,
const struct V_14 * V_40 ,
const struct V_41 * V_42 )
{
struct V_3 * V_8 ;
struct V_3 * V_127 ;
V_8 = F_65 ( V_2 , V_39 , V_40 , V_42 ) ;
if ( F_27 ( V_8 ) )
return V_8 ;
V_127 = F_78 ( V_8 -> V_16 , V_39 -> V_102 ) ;
if ( F_79 ( ! V_127 ) ) {
F_1 ( V_2 , V_8 ) ;
V_127 = F_26 ( - V_110 ) ;
}
return V_127 ;
}
int F_80 ( struct V_129 * V_130 )
{
int V_49 = 0 ;
F_81 ( & V_130 -> V_131 , 0 ) ;
F_31 ( & V_130 -> V_132 ) ;
if ( V_130 -> V_133 -> V_134 )
V_49 = V_130 -> V_133 -> V_134 ( V_130 ) ;
if ( ! V_49 ) {
F_82 ( & V_135 ) ;
F_83 ( & V_130 -> V_132 , & V_136 ) ;
F_84 ( & V_135 ) ;
}
return V_49 ;
}
void F_85 ( struct V_129 * V_130 )
{
F_82 ( & V_135 ) ;
F_23 ( & V_130 -> V_132 ) ;
F_84 ( & V_135 ) ;
if ( V_130 -> V_133 -> V_137 )
V_130 -> V_133 -> V_137 ( V_130 ) ;
}
static int
F_86 ( struct V_36 * V_122 , struct V_12 * V_13 ,
struct V_107 * V_108 , void * V_138 )
{
struct V_139 * V_140 = (struct V_139 * ) V_138 ;
struct V_7 * V_66 ;
V_66 = F_87 ( V_108 , struct V_7 , V_19 ) ;
if ( ! F_5 ( & V_66 -> V_53 ) ) {
const struct V_3 * V_4 ;
V_4 = F_46 ( V_66 ) ;
F_56 ( V_140 -> V_141 , V_140 -> V_142 ,
V_140 -> V_143 , V_4 ) ;
} else {
F_53 ( V_140 -> V_141 , V_140 -> V_142 ,
V_140 -> V_143 , V_66 ) ;
}
return 0 ;
}
void F_88 ( const struct V_1 * V_2 , struct V_9 * V_63 , void * V_82 ,
T_2 V_95 )
{
struct V_139 V_140 = {
. V_141 = (struct V_1 * ) V_2 ,
. V_142 = V_82 ,
. V_143 = V_95 ,
} ;
F_89 ( V_63 -> V_26 , F_86 , & V_140 ) ;
}
static unsigned long F_90 ( struct V_38 * V_8 )
{
unsigned long V_144 = V_145 ;
unsigned long V_146 ;
unsigned long V_147 ;
if ( ! strcmp ( V_8 -> V_102 -> V_103 , V_148 ) )
V_144 = V_149 ;
V_146 = V_150 ;
#if V_151 == 32
if ( V_146 > 1 << ( 30 - V_152 ) )
V_146 = 1 << ( 30 - V_152 ) * 3 / 4 ;
#endif
if ( V_153 == 0 || V_153 > V_154 ) {
F_91 ( L_14 ,
V_153 , V_154 ,
V_155 ) ;
V_153 = V_155 ;
}
V_146 = V_146 / 100 * V_153 *
( V_156 / 1024 ) ;
for ( V_147 = 1 ; ( 1 << V_147 ) < V_146 ; ++ V_147 ) {
;
}
return F_92 ( F_93 ( V_147 ) , V_147 , V_157 , V_144 ) ;
}
static unsigned int F_94 ( struct V_36 * V_122 ,
const void * V_87 , unsigned int V_158 )
{
struct V_14 * V_15 = (struct V_14 * ) V_87 ;
T_5 V_159 ;
V_159 = F_95 ( V_15 ) ;
V_159 += ( V_159 >> 4 ) + ( V_159 << 12 ) ;
V_159 = F_96 ( V_159 , V_122 -> V_160 ) ;
V_159 -= F_96 ( ( unsigned long ) V_122 , F_97 ( V_15 ) % 11 + 3 ) ;
V_159 <<= V_122 -> V_161 - V_122 -> V_160 ;
V_159 |= ( F_98 ( V_15 ) + F_97 ( V_15 ) ) & ( F_37 ( V_122 ) - 1 ) ;
return V_159 & V_158 ;
}
static void * F_99 ( struct V_107 * V_108 )
{
return F_87 ( V_108 , struct V_7 , V_19 ) ;
}
static void * F_100 ( struct V_107 * V_108 )
{
struct V_7 * V_66 ;
V_66 = F_87 ( V_108 , struct V_7 , V_19 ) ;
return & V_66 -> V_27 ;
}
static int F_101 ( const void * V_87 , struct V_107 * V_108 )
{
struct V_7 * V_66 ;
V_66 = F_87 ( V_108 , struct V_7 , V_19 ) ;
return F_74 ( & V_66 -> V_27 , (struct V_14 * ) V_87 ) ;
}
static void F_102 ( struct V_36 * V_122 , struct V_107 * V_108 )
{
struct V_7 * V_66 ;
V_66 = F_87 ( V_108 , struct V_7 , V_19 ) ;
F_103 ( & V_66 -> V_23 ) ;
}
static void F_104 ( struct V_36 * V_122 , struct V_107 * V_108 )
{
F_105 () ;
}
static void F_106 ( struct V_9 * V_63 , struct V_38 * V_162 )
{
F_82 ( & V_63 -> V_163 ) ;
if ( F_5 ( & V_162 -> V_164 ) )
F_83 ( & V_162 -> V_164 , & V_63 -> V_165 ) ;
F_84 ( & V_63 -> V_163 ) ;
}
int F_107 ( struct V_9 * V_63 , struct V_38 * V_8 )
{
struct V_5 * V_6 ;
struct V_12 V_13 ;
unsigned long V_147 ;
unsigned long V_74 ;
char V_166 [ 16 ] ;
int V_167 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
F_108 ( & V_63 -> V_78 ) ;
V_167 = F_109 ( & V_63 -> V_31 , 0 , V_168 ) ;
if ( V_167 )
return - V_52 ;
snprintf ( V_166 , sizeof( V_166 ) , L_15 , V_8 -> V_102 -> V_103 ) ;
for ( V_147 = F_90 ( V_8 ) ; V_147 >= V_157 ; V_147 -- ) {
V_63 -> V_26 = F_110 ( V_166 , V_147 , V_147 ,
V_147 - V_169 ,
sizeof( * V_6 ) , 0 , 0 ,
& V_170 ,
V_171 |
V_172 |
V_173 |
V_174 |
V_175 ) ;
if ( V_63 -> V_26 )
break;
}
if ( ! V_63 -> V_26 ) {
F_111 ( L_16 , V_147 ) ;
return - V_52 ;
}
F_40 (s->ls_obj_hash, &bd, i) {
V_6 = F_10 ( V_63 -> V_26 , & V_13 ) ;
F_31 ( & V_6 -> V_29 ) ;
F_112 ( & V_6 -> V_28 ) ;
}
V_63 -> V_56 = F_113 ( V_176 , 0 ) ;
if ( ! V_63 -> V_56 ) {
F_114 ( V_63 -> V_26 ) ;
V_63 -> V_26 = NULL ;
return - V_52 ;
}
F_115 ( V_63 -> V_56 , V_57 ,
0 , L_17 , L_17 ) ;
F_115 ( V_63 -> V_56 , V_112 ,
0 , L_18 , L_18 ) ;
F_115 ( V_63 -> V_56 , V_111 ,
0 , L_19 , L_19 ) ;
F_115 ( V_63 -> V_56 , V_126 ,
0 , L_20 , L_20 ) ;
F_115 ( V_63 -> V_56 , V_115 ,
0 , L_21 , L_21 ) ;
F_115 ( V_63 -> V_56 , V_81 ,
0 , L_22 , L_22 ) ;
F_31 ( & V_63 -> V_177 ) ;
V_63 -> V_117 = V_8 ;
V_8 -> V_18 = V_63 ;
F_116 ( V_8 ) ;
F_117 ( & V_8 -> V_178 , L_23 , V_63 ) ;
F_31 ( & V_63 -> V_165 ) ;
F_118 ( & V_63 -> V_163 ) ;
F_106 ( V_63 , V_8 ) ;
return 0 ;
}
void F_119 ( struct V_9 * V_63 )
{
F_120 ( & V_179 ) ;
F_23 ( & V_63 -> V_177 ) ;
F_121 ( & V_179 ) ;
F_122 ( & V_63 -> V_31 ) ;
if ( V_63 -> V_26 ) {
F_114 ( V_63 -> V_26 ) ;
V_63 -> V_26 = NULL ;
}
if ( V_63 -> V_117 ) {
V_63 -> V_117 -> V_18 = NULL ;
F_123 ( & V_63 -> V_117 -> V_178 , L_23 , V_63 ) ;
F_124 ( V_63 -> V_117 ) ;
V_63 -> V_117 = NULL ;
}
if ( V_63 -> V_56 )
F_125 ( & V_63 -> V_56 ) ;
}
int F_126 ( struct V_9 * V_63 )
{
int V_49 ;
F_120 ( & V_179 ) ;
V_49 = F_127 ( & V_180 . V_90 ) ;
if ( V_49 == 0 )
F_83 ( & V_63 -> V_177 , & V_181 ) ;
F_121 ( & V_179 ) ;
return V_49 ;
}
void F_116 ( struct V_38 * V_162 )
{
F_103 ( & V_162 -> V_182 ) ;
}
void F_124 ( struct V_38 * V_162 )
{
F_4 ( F_43 ( & V_162 -> V_182 ) > 0 ) ;
F_128 ( & V_162 -> V_182 ) ;
}
int F_129 ( struct V_38 * V_162 , struct V_129 * V_183 )
{
if ( F_130 ( & V_183 -> V_131 ) == 1 &&
V_183 -> V_133 -> V_184 )
V_183 -> V_133 -> V_184 ( V_183 ) ;
memset ( V_162 , 0 , sizeof( * V_162 ) ) ;
F_81 ( & V_162 -> V_182 , 0 ) ;
V_162 -> V_102 = V_183 ;
F_131 ( & V_162 -> V_178 ) ;
F_31 ( & V_162 -> V_164 ) ;
return 0 ;
}
void F_132 ( struct V_38 * V_162 )
{
struct V_129 * V_183 = V_162 -> V_102 ;
if ( V_162 -> V_185 ) {
V_162 -> V_185 -> V_186 = NULL ;
V_162 -> V_185 = NULL ;
}
F_133 ( & V_162 -> V_178 ) ;
F_134 ( F_43 ( & V_162 -> V_182 ) == 0 ,
L_24 , F_43 ( & V_162 -> V_182 ) ) ;
F_4 ( F_43 ( & V_183 -> V_131 ) > 0 ) ;
if ( F_6 ( & V_183 -> V_131 ) &&
V_183 -> V_133 -> V_187 )
V_183 -> V_133 -> V_187 ( V_183 ) ;
}
int F_135 ( struct V_3 * V_4 , struct V_7 * V_66 ,
struct V_38 * V_162 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_16 = V_66 ;
V_4 -> V_17 = V_162 ;
F_116 ( V_162 ) ;
F_136 ( & V_162 -> V_178 , & V_4 -> V_188 , L_25 , V_4 ) ;
F_31 ( & V_4 -> V_61 ) ;
return 0 ;
}
void F_137 ( struct V_3 * V_4 )
{
struct V_38 * V_39 = V_4 -> V_17 ;
F_4 ( F_5 ( & V_4 -> V_61 ) ) ;
if ( V_39 ) {
F_138 ( & V_39 -> V_178 , & V_4 -> V_188 ,
L_25 , V_4 ) ;
F_124 ( V_39 ) ;
V_4 -> V_17 = NULL ;
}
}
void F_139 ( struct V_7 * V_66 , struct V_3 * V_4 )
{
F_44 ( & V_4 -> V_61 , & V_66 -> V_53 ) ;
}
void F_140 ( struct V_3 * V_189 , struct V_3 * V_4 )
{
F_44 ( & V_4 -> V_61 , & V_189 -> V_61 ) ;
}
int F_141 ( struct V_7 * V_66 )
{
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
F_81 ( & V_66 -> V_23 , 1 ) ;
F_142 ( & V_66 -> V_19 ) ;
F_31 ( & V_66 -> V_22 ) ;
F_31 ( & V_66 -> V_53 ) ;
F_131 ( & V_66 -> V_190 ) ;
return 0 ;
}
void F_143 ( struct V_7 * V_66 )
{
F_4 ( F_5 ( & V_66 -> V_53 ) ) ;
F_4 ( F_5 ( & V_66 -> V_22 ) ) ;
F_4 ( F_55 ( & V_66 -> V_19 ) ) ;
F_133 ( & V_66 -> V_190 ) ;
}
struct V_3 * F_78 ( struct V_7 * V_66 ,
const struct V_129 * V_191 )
{
struct V_3 * V_4 ;
F_28 (o, &h->loh_layers, lo_linkage) {
if ( V_4 -> V_17 -> V_102 == V_191 )
return V_4 ;
}
return NULL ;
}
void F_144 ( const struct V_1 * V_2 , struct V_38 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_18 ;
struct V_38 * V_43 ;
struct V_38 * V_20 ;
F_145 ( V_2 , V_10 , ~ 0 ) ;
for ( V_43 = V_8 ; V_43 ; V_43 = V_20 ) {
V_20 = V_43 -> V_102 -> V_133 -> V_192 ( V_2 , V_43 ) ;
F_123 ( & V_43 -> V_178 , L_26 , & F_107 ) ;
F_124 ( V_43 ) ;
}
F_145 ( V_2 , V_10 , ~ 0 ) ;
for ( V_43 = V_8 ; V_43 ; V_43 = V_20 ) {
const struct V_129 * V_130 = V_43 -> V_102 ;
struct V_193 * type ;
V_20 = V_130 -> V_133 -> V_194 ( V_2 , V_43 ) ;
type = V_130 -> V_195 ;
if ( type ) {
type -> V_196 -- ;
F_146 ( type ) ;
}
}
}
int F_147 ( struct V_197 * V_87 )
{
int V_49 ;
unsigned int V_74 ;
F_4 ( V_87 -> V_198 ) ;
F_4 ( V_87 -> V_199 ) ;
F_4 ( V_87 -> V_200 != 0 ) ;
V_49 = - V_201 ;
F_82 ( & V_202 ) ;
for ( V_74 = 0 ; V_74 < F_50 ( V_203 ) ; ++ V_74 ) {
if ( ! V_203 [ V_74 ] ) {
V_87 -> V_204 = V_74 ;
F_81 ( & V_87 -> V_205 , 1 ) ;
V_203 [ V_74 ] = V_87 ;
F_131 ( & V_87 -> V_206 ) ;
V_49 = 0 ;
++ V_207 ;
break;
}
}
F_84 ( & V_202 ) ;
return V_49 ;
}
static void F_148 ( struct V_208 * V_209 , int V_210 )
{
if ( V_209 -> V_211 && V_209 -> V_211 [ V_210 ] ) {
struct V_197 * V_87 ;
V_87 = V_203 [ V_210 ] ;
F_4 ( F_43 ( & V_87 -> V_205 ) > 1 ) ;
V_87 -> V_199 ( V_209 , V_87 , V_209 -> V_211 [ V_210 ] ) ;
F_123 ( & V_87 -> V_206 , L_27 , V_209 ) ;
F_128 ( & V_87 -> V_205 ) ;
if ( ( V_209 -> V_212 & V_213 ) == 0 ) {
#ifdef F_149
F_150 ( F_151 ( V_87 -> V_214 ) > 0 ) ;
#endif
F_152 ( V_87 -> V_214 ) ;
}
V_209 -> V_211 [ V_210 ] = NULL ;
}
}
void F_153 ( struct V_197 * V_87 )
{
F_4 ( F_43 ( & V_87 -> V_205 ) >= 1 ) ;
F_150 ( 0 <= V_87 -> V_204 && V_87 -> V_204 < F_50 ( V_203 ) ) ;
F_154 ( V_87 ) ;
++ V_207 ;
F_82 ( & V_202 ) ;
F_148 ( & V_180 . V_90 , V_87 -> V_204 ) ;
while ( F_43 ( & V_87 -> V_205 ) > 1 ) {
F_84 ( & V_202 ) ;
F_16 ( V_215 , L_28 ,
V_87 -> V_214 ? V_87 -> V_214 -> V_166 : L_5 , V_87 ,
F_43 ( & V_87 -> V_205 ) ) ;
F_75 () ;
F_82 ( & V_202 ) ;
}
if ( V_203 [ V_87 -> V_204 ] ) {
V_203 [ V_87 -> V_204 ] = NULL ;
F_133 ( & V_87 -> V_206 ) ;
}
F_84 ( & V_202 ) ;
F_134 ( F_43 ( & V_87 -> V_205 ) == 1 ,
L_29 ,
F_43 ( & V_87 -> V_205 ) ) ;
}
int F_155 ( struct V_197 * V_216 , ... )
{
struct V_197 * V_87 = V_216 ;
T_1 args ;
int V_49 ;
va_start ( args , V_216 ) ;
do {
V_49 = F_147 ( V_87 ) ;
if ( V_49 )
break;
V_87 = va_arg ( args , struct V_197 * ) ;
} while ( V_87 );
va_end ( args ) ;
if ( V_49 != 0 ) {
va_start ( args , V_216 ) ;
while ( V_216 != V_87 ) {
F_153 ( V_216 ) ;
V_216 = va_arg ( args , struct V_197 * ) ;
}
va_end ( args ) ;
}
return V_49 ;
}
void F_156 ( struct V_197 * V_216 , ... )
{
T_1 args ;
va_start ( args , V_216 ) ;
do {
F_153 ( V_216 ) ;
V_216 = va_arg ( args , struct V_197 * ) ;
} while ( V_216 );
va_end ( args ) ;
}
void F_157 ( struct V_197 * V_216 , ... )
{
T_1 args ;
va_start ( args , V_216 ) ;
do {
F_158 ( V_216 ) ;
V_216 = va_arg ( args , struct V_197 * ) ;
} while ( V_216 );
va_end ( args ) ;
}
void F_159 ( struct V_197 * V_216 , ... )
{
T_1 args ;
va_start ( args , V_216 ) ;
do {
F_154 ( V_216 ) ;
V_216 = va_arg ( args , struct V_197 * ) ;
} while ( V_216 );
va_end ( args ) ;
}
void * F_49 ( const struct V_208 * V_209 ,
const struct V_197 * V_87 )
{
F_150 ( V_209 -> V_217 == V_218 ) ;
F_150 ( 0 <= V_87 -> V_204 && V_87 -> V_204 < F_50 ( V_203 ) ) ;
F_4 ( V_203 [ V_87 -> V_204 ] == V_87 ) ;
return V_209 -> V_211 [ V_87 -> V_204 ] ;
}
void F_154 ( struct V_197 * V_87 )
{
struct V_208 * V_209 ;
if ( ! ( V_87 -> V_200 & V_219 ) ) {
F_82 ( & V_202 ) ;
V_87 -> V_200 |= V_219 ;
while ( F_43 ( & V_220 ) > 0 ) {
F_84 ( & V_202 ) ;
F_16 ( V_215 , L_30 ,
V_87 -> V_214 ? V_87 -> V_214 -> V_166 : L_5 ,
V_87 , F_43 ( & V_87 -> V_205 ) ,
F_43 ( & V_220 ) ) ;
F_75 () ;
F_82 ( & V_202 ) ;
}
F_28 (ctx, &lu_context_remembered, lc_remember)
F_148 ( V_209 , V_87 -> V_204 ) ;
F_84 ( & V_202 ) ;
++ V_207 ;
}
}
void F_158 ( struct V_197 * V_87 )
{
V_87 -> V_200 &= ~ V_219 ;
++ V_207 ;
}
static void F_160 ( struct V_208 * V_209 )
{
unsigned int V_74 ;
if ( ! V_209 -> V_211 )
return;
for ( V_74 = 0 ; V_74 < F_50 ( V_203 ) ; ++ V_74 )
F_148 ( V_209 , V_74 ) ;
F_161 ( V_209 -> V_211 ) ;
V_209 -> V_211 = NULL ;
}
static int F_162 ( struct V_208 * V_209 )
{
unsigned int V_74 ;
F_82 ( & V_202 ) ;
F_103 ( & V_220 ) ;
F_84 ( & V_202 ) ;
F_150 ( V_209 -> V_211 ) ;
for ( V_74 = 0 ; V_74 < F_50 ( V_203 ) ; ++ V_74 ) {
struct V_197 * V_87 ;
V_87 = V_203 [ V_74 ] ;
if ( ! V_209 -> V_211 [ V_74 ] && V_87 &&
( V_87 -> V_200 & V_209 -> V_212 ) &&
! ( V_87 -> V_200 & V_219 ) ) {
void * V_221 ;
F_150 ( V_87 -> V_198 ) ;
F_150 ( V_87 -> V_204 == V_74 ) ;
F_4 ( V_87 -> V_214 ) ;
if ( ! ( V_209 -> V_212 & V_213 ) &&
! F_163 ( V_87 -> V_214 ) ) {
continue;
}
V_221 = V_87 -> V_198 ( V_209 , V_87 ) ;
if ( F_79 ( F_27 ( V_221 ) ) ) {
F_128 ( & V_220 ) ;
return F_73 ( V_221 ) ;
}
F_164 ( & V_87 -> V_206 , L_27 , V_209 ) ;
F_103 ( & V_87 -> V_205 ) ;
V_209 -> V_211 [ V_74 ] = V_221 ;
if ( V_87 -> V_222 )
V_209 -> V_212 |= V_223 ;
}
V_209 -> V_224 = V_207 ;
}
F_128 ( & V_220 ) ;
return 0 ;
}
static int F_165 ( struct V_208 * V_209 )
{
V_209 -> V_211 = F_166 ( F_50 ( V_203 ) , sizeof( V_209 -> V_211 [ 0 ] ) ,
V_168 ) ;
if ( F_60 ( V_209 -> V_211 ) )
return F_162 ( V_209 ) ;
return - V_52 ;
}
int F_167 ( struct V_208 * V_209 , T_5 V_225 )
{
int V_167 ;
memset ( V_209 , 0 , sizeof( * V_209 ) ) ;
V_209 -> V_217 = V_226 ;
V_209 -> V_212 = V_225 ;
if ( V_225 & V_227 ) {
F_82 ( & V_202 ) ;
F_83 ( & V_209 -> V_228 , & V_229 ) ;
F_84 ( & V_202 ) ;
} else {
F_31 ( & V_209 -> V_228 ) ;
}
V_167 = F_165 ( V_209 ) ;
if ( V_167 != 0 )
F_168 ( V_209 ) ;
return V_167 ;
}
void F_168 ( struct V_208 * V_209 )
{
F_150 ( V_209 -> V_217 == V_226 || V_209 -> V_217 == V_230 ) ;
V_209 -> V_217 = V_231 ;
if ( ( V_209 -> V_212 & V_227 ) == 0 ) {
F_4 ( F_5 ( & V_209 -> V_228 ) ) ;
F_160 ( V_209 ) ;
} else {
F_82 ( & V_202 ) ;
F_160 ( V_209 ) ;
F_23 ( & V_209 -> V_228 ) ;
F_84 ( & V_202 ) ;
}
}
void F_169 ( struct V_208 * V_209 )
{
F_150 ( V_209 -> V_217 == V_226 || V_209 -> V_217 == V_230 ) ;
V_209 -> V_217 = V_218 ;
}
void F_170 ( struct V_208 * V_209 )
{
unsigned int V_74 ;
F_150 ( V_209 -> V_217 == V_218 ) ;
V_209 -> V_217 = V_230 ;
if ( V_209 -> V_212 & V_223 && V_209 -> V_211 ) {
for ( V_74 = 0 ; V_74 < F_50 ( V_203 ) ; ++ V_74 ) {
if ( V_209 -> V_212 & V_227 )
F_82 ( & V_202 ) ;
if ( V_209 -> V_211 [ V_74 ] ) {
struct V_197 * V_87 ;
V_87 = V_203 [ V_74 ] ;
if ( V_87 -> V_222 )
V_87 -> V_222 ( V_209 ,
V_87 , V_209 -> V_211 [ V_74 ] ) ;
}
if ( V_209 -> V_212 & V_227 )
F_84 ( & V_202 ) ;
}
}
}
int F_127 ( struct V_208 * V_209 )
{
return F_60 ( V_209 -> V_224 == V_207 ) ? 0 : F_162 ( V_209 ) ;
}
int F_171 ( struct V_1 * V_2 , T_5 V_225 )
{
int V_49 ;
V_2 -> V_232 = NULL ;
V_49 = F_167 ( & V_2 -> V_90 , V_225 ) ;
if ( F_60 ( V_49 == 0 ) )
F_169 ( & V_2 -> V_90 ) ;
return V_49 ;
}
void F_172 ( struct V_1 * V_2 )
{
F_170 ( & V_2 -> V_90 ) ;
F_168 ( & V_2 -> V_90 ) ;
V_2 -> V_232 = NULL ;
}
int F_173 ( struct V_1 * V_2 )
{
int V_49 ;
V_49 = F_127 ( & V_2 -> V_90 ) ;
if ( V_49 == 0 && V_2 -> V_232 )
V_49 = F_127 ( V_2 -> V_232 ) ;
return V_49 ;
}
static void F_174 ( struct V_36 * V_122 ,
struct V_233 * V_234 , int V_235 )
{
struct V_12 V_13 ;
unsigned int V_74 ;
F_40 (hs, &bd, i) {
struct V_5 * V_6 = F_10 ( V_122 , & V_13 ) ;
struct V_236 * V_237 ;
F_41 ( V_122 , & V_13 , 1 ) ;
V_234 -> V_238 +=
F_175 ( & V_13 ) - V_6 -> V_30 ;
V_234 -> V_239 += F_175 ( & V_13 ) ;
V_234 -> V_240 = F_176 ( ( int ) V_234 -> V_240 ,
F_177 ( & V_13 ) ) ;
if ( ! V_235 ) {
F_17 ( V_122 , & V_13 , 1 ) ;
continue;
}
F_178 (hs, &bd, hhead) {
if ( ! F_179 ( V_237 ) )
V_234 -> V_241 ++ ;
}
F_17 ( V_122 , & V_13 , 1 ) ;
}
}
static unsigned long F_180 ( struct V_242 * V_243 ,
struct V_244 * V_245 )
{
struct V_9 * V_63 ;
struct V_9 * V_246 ;
unsigned long V_247 = 0 ;
if ( ! ( V_245 -> V_248 & V_249 ) )
return 0 ;
F_181 ( & V_179 ) ;
F_42 (s, tmp, &lu_sites, ls_linkage)
V_247 += F_182 ( & V_63 -> V_31 ) ;
F_183 ( & V_179 ) ;
V_247 = ( V_247 / 100 ) * V_250 ;
F_16 ( V_32 , L_31 ,
V_247 , V_250 ) ;
return V_247 ;
}
static unsigned long F_184 ( struct V_242 * V_243 ,
struct V_244 * V_245 )
{
struct V_9 * V_63 ;
struct V_9 * V_246 ;
unsigned long V_251 = V_245 -> V_252 , V_253 = 0 ;
F_185 ( V_58 ) ;
if ( ! ( V_245 -> V_248 & V_249 ) )
return V_254 ;
F_120 ( & V_179 ) ;
F_42 (s, tmp, &lu_sites, ls_linkage) {
V_253 = F_145 ( & V_180 , V_63 , V_251 ) ;
V_251 -= V_253 ;
F_186 ( & V_63 -> V_177 , & V_58 ) ;
}
F_187 ( & V_58 , V_181 . V_60 ) ;
F_121 ( & V_179 ) ;
return V_245 -> V_252 - V_251 ;
}
int F_188 ( void )
{
int V_49 ;
F_16 ( V_215 , L_32 , & V_203 ) ;
V_49 = F_189 () ;
if ( V_49 != 0 )
return V_49 ;
F_190 ( & V_91 ) ;
V_49 = F_147 ( & V_91 ) ;
if ( V_49 != 0 )
return V_49 ;
F_120 ( & V_179 ) ;
V_49 = F_171 ( & V_180 , V_255 ) ;
F_121 ( & V_179 ) ;
if ( V_49 != 0 )
return V_49 ;
F_191 ( & V_256 ) ;
return V_49 ;
}
void F_192 ( void )
{
F_193 ( & V_256 ) ;
F_153 ( & V_91 ) ;
F_120 ( & V_179 ) ;
F_172 ( & V_180 ) ;
F_121 ( & V_179 ) ;
F_194 () ;
}
static T_5 F_195 ( struct V_257 * V_234 , int V_258 )
{
struct V_259 V_260 ;
F_196 ( V_234 , V_258 , & V_260 ) ;
return ( T_5 ) V_260 . V_261 ;
}
int F_197 ( const struct V_9 * V_63 , struct V_262 * V_263 )
{
struct V_233 V_234 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
F_174 ( V_63 -> V_26 , & V_234 , 1 ) ;
F_198 ( V_263 , L_33 ,
V_234 . V_238 ,
V_234 . V_239 ,
V_234 . V_241 ,
F_199 ( V_63 -> V_26 ) ,
V_234 . V_240 ,
F_195 ( V_63 -> V_56 , V_57 ) ,
F_195 ( V_63 -> V_56 , V_112 ) ,
F_195 ( V_63 -> V_56 , V_111 ) ,
F_195 ( V_63 -> V_56 , V_126 ) ,
F_195 ( V_63 -> V_56 , V_115 ) ,
F_195 ( V_63 -> V_56 , V_81 ) ) ;
return 0 ;
}
int F_200 ( struct V_264 * V_265 )
{
int V_49 ;
struct V_264 * V_266 = V_265 ;
for ( V_49 = 0 ; V_266 -> V_267 ; ++ V_266 ) {
* V_266 -> V_267 = F_201 ( V_266 -> V_268 ,
V_266 -> V_269 ,
0 , 0 , NULL ) ;
if ( ! * V_266 -> V_267 ) {
V_49 = - V_52 ;
F_202 ( V_265 ) ;
break;
}
}
return V_49 ;
}
void F_202 ( struct V_264 * V_265 )
{
for (; V_265 -> V_267 ; ++ V_265 ) {
F_203 ( * V_265 -> V_267 ) ;
* V_265 -> V_267 = NULL ;
}
}
void F_204 ( struct V_270 * V_271 )
{
F_4 ( V_271 ) ;
if ( V_271 -> V_272 ) {
F_4 ( V_271 -> V_273 > 0 ) ;
F_205 ( V_271 -> V_272 ) ;
V_271 -> V_272 = NULL ;
V_271 -> V_273 = 0 ;
}
}
void F_206 ( struct V_270 * V_271 , T_6 V_118 )
{
F_4 ( V_271 ) ;
F_4 ( ! V_271 -> V_272 ) ;
F_4 ( ! V_271 -> V_273 ) ;
V_271 -> V_272 = F_207 ( V_118 , V_168 ) ;
if ( F_60 ( V_271 -> V_272 ) )
V_271 -> V_273 = V_118 ;
}
void F_208 ( struct V_270 * V_271 , T_6 V_118 )
{
F_204 ( V_271 ) ;
F_206 ( V_271 , V_118 ) ;
}
struct V_270 * F_209 ( struct V_270 * V_271 , T_6 V_274 )
{
if ( ! V_271 -> V_272 && ! V_271 -> V_273 )
F_206 ( V_271 , V_274 ) ;
if ( ( V_274 > V_271 -> V_273 ) && V_271 -> V_272 )
F_208 ( V_271 , V_274 ) ;
return V_271 ;
}
int F_210 ( struct V_270 * V_271 , T_6 V_274 )
{
char * V_275 ;
if ( V_274 <= V_271 -> V_273 )
return 0 ;
V_275 = F_207 ( V_274 , V_168 ) ;
if ( ! V_275 )
return - V_52 ;
if ( V_271 -> V_272 ) {
memcpy ( V_275 , V_271 -> V_272 , V_271 -> V_273 ) ;
F_205 ( V_271 -> V_272 ) ;
}
V_271 -> V_272 = V_275 ;
V_271 -> V_273 = V_274 ;
return 0 ;
}
