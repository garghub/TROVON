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
int V_70 ;
int V_71 ;
int V_72 ;
int V_73 ;
if ( F_35 ( V_74 ) )
return 0 ;
F_30 ( & V_68 ) ;
V_70 = V_63 -> V_75 ;
V_72 = ( V_64 == ~ 0 ) ? - 1 : V_64 / F_36 ( V_63 -> V_26 ) + 1 ;
V_76:
V_69 = 0 ;
F_37 (s->ls_obj_hash, &bd, i) {
if ( V_73 < V_70 )
continue;
V_71 = V_72 ;
F_38 ( V_63 -> V_26 , & V_13 , 1 ) ;
V_6 = F_10 ( V_63 -> V_26 , & V_13 ) ;
F_39 (h, temp, &bkt->lsb_lru, loh_lru) {
F_4 ( F_40 ( & V_65 -> V_23 ) == 0 ) ;
F_9 ( V_63 -> V_26 , & V_65 -> V_27 , & V_67 ) ;
F_4 ( V_13 . V_77 == V_67 . V_77 ) ;
F_19 ( V_63 -> V_26 ,
& V_67 , & V_65 -> V_19 ) ;
F_41 ( & V_65 -> V_22 , & V_68 ) ;
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
F_42 () ;
while ( ! F_5 ( & V_68 ) ) {
V_65 = F_32 ( V_68 . V_20 ,
struct V_7 , V_22 ) ;
F_23 ( & V_65 -> V_22 ) ;
F_8 ( V_2 , F_43 ( V_65 ) ) ;
F_15 ( V_63 -> V_31 , V_78 ) ;
}
if ( V_64 == 0 )
break;
}
if ( V_64 != 0 && V_69 && V_70 != 0 ) {
V_70 = 0 ;
goto V_76;
}
V_63 -> V_75 = V_73 % F_36 ( V_63 -> V_26 ) ;
return V_64 ;
}
int F_44 ( const struct V_1 * V_2 ,
void * V_79 , const char * V_80 , ... )
{
struct V_81 * V_82 = V_79 ;
struct V_83 * V_84 ;
int V_85 ;
int V_86 ;
T_1 args ;
va_start ( args , V_80 ) ;
V_84 = F_45 ( & V_2 -> V_87 , & V_88 ) ;
V_85 = strlen ( V_84 -> V_89 ) ;
V_86 = V_80 [ strlen ( V_80 ) - 1 ] == '\n' ;
vsnprintf ( V_84 -> V_89 + V_85 ,
F_46 ( V_84 -> V_89 ) - V_85 , V_80 , args ) ;
if ( V_86 ) {
if ( F_47 ( V_82 -> V_90 , V_82 -> V_91 ) )
F_48 ( V_82 , L_2 , V_84 -> V_89 ) ;
V_84 -> V_89 [ 0 ] = 0 ;
}
va_end ( args ) ;
return 0 ;
}
void F_49 ( const struct V_1 * V_2 , void * V_79 ,
T_2 V_92 ,
const struct V_7 * V_93 )
{
(* V_92)( V_2 , V_79 , L_3 V_94 L_4 ,
V_93 , V_93 -> V_35 , F_40 ( & V_93 -> V_23 ) ,
F_50 ( & V_93 -> V_27 ) ,
F_51 ( & V_93 -> V_19 ) ? L_5 : L_6 ,
F_5 ( (struct V_45 * ) & V_93 -> V_22 ) ? \
L_5 : L_7 ,
V_93 -> V_95 & V_96 ? L_8 : L_5 ) ;
}
void F_52 ( const struct V_1 * V_2 , void * V_79 ,
T_2 V_92 , const struct V_3 * V_4 )
{
static const char V_97 [] = L_9 ;
struct V_7 * V_8 ;
int V_98 = 4 ;
V_8 = V_4 -> V_16 ;
F_49 ( V_2 , V_79 , V_92 , V_8 ) ;
(* V_92)( V_2 , V_79 , L_10 ) ;
F_28 (o, &top->loh_layers, lo_linkage) {
(* V_92)( V_2 , V_79 , L_11 , V_98 , V_98 , V_97 ,
V_4 -> V_17 -> V_99 -> V_100 , V_4 ) ;
if ( V_4 -> V_24 -> V_101 )
(* V_4 -> V_24 -> V_101 )( V_2 , V_79 , V_92 , V_4 ) ;
(* V_92)( V_2 , V_79 , L_12 ) ;
}
(* V_92)( V_2 , V_79 , L_13 , V_8 ) ;
}
static struct V_3 * F_53 ( struct V_9 * V_63 ,
struct V_12 * V_13 ,
const struct V_14 * V_41 ,
T_3 * V_102 ,
T_4 * V_103 )
{
struct V_5 * V_6 ;
struct V_7 * V_65 ;
struct V_104 * V_105 ;
T_4 V_106 = F_54 ( V_13 ) ;
if ( * V_103 == V_106 )
return F_26 ( - V_107 ) ;
* V_103 = V_106 ;
V_6 = F_10 ( V_63 -> V_26 , V_13 ) ;
V_105 = F_55 ( V_63 -> V_26 , V_13 , ( void * ) V_41 ) ;
if ( ! V_105 ) {
F_15 ( V_63 -> V_31 , V_108 ) ;
return F_26 ( - V_107 ) ;
}
V_65 = F_32 ( V_105 , struct V_7 , V_19 ) ;
if ( F_56 ( ! F_12 ( V_65 ) ) ) {
F_57 ( V_63 -> V_26 , V_105 ) ;
F_15 ( V_63 -> V_31 , V_109 ) ;
if ( ! F_5 ( & V_65 -> V_22 ) ) {
F_23 ( & V_65 -> V_22 ) ;
V_6 -> V_30 -- ;
F_24 ( V_63 -> V_31 , V_32 ) ;
}
return F_43 ( V_65 ) ;
}
F_58 ( V_102 , V_110 ) ;
F_59 ( & V_6 -> V_28 , V_102 ) ;
F_60 ( V_111 ) ;
F_15 ( V_63 -> V_31 , V_112 ) ;
return F_26 ( - V_113 ) ;
}
static struct V_3 * F_61 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 )
{
return F_62 ( V_2 , V_40 -> V_18 -> V_114 , V_41 , V_43 ) ;
}
static struct V_3 * F_63 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 )
{
struct V_3 * V_4 ;
struct V_37 * V_115 ;
struct V_12 V_13 ;
V_4 = F_25 ( V_2 , V_40 , V_41 , V_43 ) ;
if ( F_27 ( V_4 ) )
return V_4 ;
V_115 = V_40 -> V_18 -> V_26 ;
F_22 ( V_115 , ( void * ) V_41 , & V_13 , 1 ) ;
F_64 ( V_115 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
F_17 ( V_115 , & V_13 , 1 ) ;
return V_4 ;
}
static struct V_3 * F_65 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 ,
T_3 * V_102 )
{
struct V_3 * V_4 ;
struct V_3 * V_116 ;
struct V_9 * V_63 ;
struct V_37 * V_115 ;
struct V_12 V_13 ;
T_4 V_103 = 0 ;
if ( V_43 && V_43 -> V_117 & V_118 )
return F_63 ( V_2 , V_40 , V_41 , V_43 ) ;
V_63 = V_40 -> V_18 ;
V_115 = V_63 -> V_26 ;
F_22 ( V_115 , ( void * ) V_41 , & V_13 , 1 ) ;
V_4 = F_53 ( V_63 , & V_13 , V_41 , V_102 , & V_103 ) ;
F_17 ( V_115 , & V_13 , 1 ) ;
if ( ! F_27 ( V_4 ) || F_66 ( V_4 ) != - V_107 )
return V_4 ;
V_4 = F_25 ( V_2 , V_40 , V_41 , V_43 ) ;
if ( F_27 ( V_4 ) )
return V_4 ;
F_4 ( F_67 ( F_2 ( V_4 ) , V_41 ) ) ;
F_38 ( V_115 , & V_13 , 1 ) ;
V_116 = F_53 ( V_63 , & V_13 , V_41 , V_102 , & V_103 ) ;
if ( F_56 ( F_66 ( V_116 ) == - V_107 ) ) {
F_64 ( V_115 , & V_13 , & V_4 -> V_16 -> V_19 ) ;
F_17 ( V_115 , & V_13 , 1 ) ;
return V_4 ;
}
F_15 ( V_63 -> V_31 , V_119 ) ;
F_17 ( V_115 , & V_13 , 1 ) ;
F_8 ( V_2 , V_4 ) ;
return V_116 ;
}
struct V_3 * F_62 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 )
{
struct V_5 * V_6 ;
struct V_3 * V_120 ;
T_3 V_121 ;
while ( 1 ) {
V_120 = F_65 ( V_2 , V_40 , V_41 , V_43 , & V_121 ) ;
if ( V_120 != F_26 ( - V_113 ) )
return V_120 ;
F_68 () ;
V_6 = F_29 ( V_40 -> V_18 , ( void * ) V_41 ) ;
F_69 ( & V_6 -> V_28 , & V_121 ) ;
}
}
struct V_3 * F_70 ( const struct V_1 * V_2 ,
struct V_39 * V_40 ,
const struct V_14 * V_41 ,
const struct V_42 * V_43 )
{
struct V_3 * V_8 ;
struct V_3 * V_120 ;
V_8 = F_61 ( V_2 , V_40 , V_41 , V_43 ) ;
if ( ! F_27 ( V_8 ) ) {
V_120 = F_71 ( V_8 -> V_16 , V_40 -> V_99 ) ;
if ( ! V_120 )
F_1 ( V_2 , V_8 ) ;
} else
V_120 = V_8 ;
return V_120 ;
}
int F_72 ( struct V_122 * V_123 )
{
int V_50 = 0 ;
F_30 ( & V_123 -> V_124 ) ;
if ( V_123 -> V_125 -> V_126 )
V_50 = V_123 -> V_125 -> V_126 ( V_123 ) ;
if ( V_50 == 0 )
F_73 ( & V_123 -> V_124 , & V_127 ) ;
return V_50 ;
}
void F_74 ( struct V_122 * V_123 )
{
F_23 ( & V_123 -> V_124 ) ;
if ( V_123 -> V_125 -> V_128 )
V_123 -> V_125 -> V_128 ( V_123 ) ;
}
void F_75 ( void )
{
struct V_122 * V_123 ;
F_28 (ldt, &lu_device_types, ldt_linkage) {
if ( V_123 -> V_129 == 0 && V_123 -> V_125 -> V_130 )
V_123 -> V_125 -> V_130 ( V_123 ) ;
}
}
static int
F_76 ( struct V_37 * V_115 , struct V_12 * V_13 ,
struct V_104 * V_105 , void * V_131 )
{
struct V_132 * V_133 = (struct V_132 * ) V_131 ;
struct V_7 * V_65 ;
V_65 = F_77 ( V_105 , struct V_7 , V_19 ) ;
if ( ! F_5 ( & V_65 -> V_54 ) ) {
const struct V_3 * V_4 ;
V_4 = F_43 ( V_65 ) ;
F_52 ( V_133 -> V_134 , V_133 -> V_135 ,
V_133 -> V_136 , V_4 ) ;
} else {
F_49 ( V_133 -> V_134 , V_133 -> V_135 ,
V_133 -> V_136 , V_65 ) ;
}
return 0 ;
}
void F_78 ( const struct V_1 * V_2 , struct V_9 * V_63 , void * V_79 ,
T_2 V_92 )
{
struct V_132 V_133 = {
. V_134 = (struct V_1 * ) V_2 ,
. V_135 = V_79 ,
. V_136 = V_92 ,
} ;
F_79 ( V_63 -> V_26 , F_76 , & V_133 ) ;
}
static int F_80 ( void )
{
unsigned long V_137 ;
int V_138 ;
V_137 = V_139 ;
#if V_140 == 32
if ( V_137 > 1 << ( 30 - V_141 ) )
V_137 = 1 << ( 30 - V_141 ) * 3 / 4 ;
#endif
if ( V_142 == 0 || V_142 > V_143 ) {
F_81 ( L_14 ,
V_142 , V_143 ,
V_144 ) ;
V_142 = V_144 ;
}
V_137 = V_137 / 100 * V_142 *
( V_145 / 1024 ) ;
for ( V_138 = 1 ; ( 1 << V_138 ) < V_137 ; ++ V_138 ) {
;
}
return V_138 ;
}
static unsigned F_82 ( struct V_37 * V_115 ,
const void * V_84 , unsigned V_146 )
{
struct V_14 * V_15 = (struct V_14 * ) V_84 ;
T_5 V_147 ;
V_147 = F_83 ( V_15 ) ;
V_147 += ( V_147 >> 4 ) + ( V_147 << 12 ) ;
V_147 = F_84 ( V_147 , V_115 -> V_148 ) ;
V_147 -= F_84 ( ( unsigned long ) V_115 , F_85 ( V_15 ) % 11 + 3 ) ;
V_147 <<= V_115 -> V_149 - V_115 -> V_148 ;
V_147 |= ( F_86 ( V_15 ) + F_85 ( V_15 ) ) & ( F_36 ( V_115 ) - 1 ) ;
return V_147 & V_146 ;
}
static void * F_87 ( struct V_104 * V_105 )
{
return F_77 ( V_105 , struct V_7 , V_19 ) ;
}
static void * F_88 ( struct V_104 * V_105 )
{
struct V_7 * V_65 ;
V_65 = F_77 ( V_105 , struct V_7 , V_19 ) ;
return & V_65 -> V_27 ;
}
static int F_89 ( const void * V_84 , struct V_104 * V_105 )
{
struct V_7 * V_65 ;
V_65 = F_77 ( V_105 , struct V_7 , V_19 ) ;
return F_67 ( & V_65 -> V_27 , (struct V_14 * ) V_84 ) ;
}
static void F_90 ( struct V_37 * V_115 , struct V_104 * V_105 )
{
struct V_7 * V_65 ;
V_65 = F_77 ( V_105 , struct V_7 , V_19 ) ;
F_91 ( & V_65 -> V_23 ) ;
}
static void F_92 ( struct V_37 * V_115 , struct V_104 * V_105 )
{
F_93 () ;
}
static void F_94 ( struct V_9 * V_63 , struct V_39 * V_150 )
{
F_95 ( & V_63 -> V_151 ) ;
if ( F_5 ( & V_150 -> V_152 ) )
F_73 ( & V_150 -> V_152 , & V_63 -> V_153 ) ;
F_96 ( & V_63 -> V_151 ) ;
}
int F_97 ( struct V_9 * V_63 , struct V_39 * V_8 )
{
struct V_5 * V_6 ;
struct V_12 V_13 ;
char V_154 [ 16 ] ;
int V_138 ;
int V_73 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
V_138 = F_80 () ;
snprintf ( V_154 , 16 , L_15 , V_8 -> V_99 -> V_100 ) ;
for ( V_138 = F_98 ( F_99 ( V_155 , V_138 ) , V_156 ) ;
V_138 >= V_155 ; V_138 -- ) {
V_63 -> V_26 = F_100 ( V_154 , V_138 , V_138 ,
V_138 - V_157 ,
sizeof( * V_6 ) , 0 , 0 ,
& V_158 ,
V_159 |
V_160 |
V_161 |
V_162 ) ;
if ( V_63 -> V_26 )
break;
}
if ( ! V_63 -> V_26 ) {
F_101 ( L_16 , V_138 ) ;
return - V_53 ;
}
F_37 (s->ls_obj_hash, &bd, i) {
V_6 = F_10 ( V_63 -> V_26 , & V_13 ) ;
F_30 ( & V_6 -> V_29 ) ;
F_102 ( & V_6 -> V_28 ) ;
}
V_63 -> V_31 = F_103 ( V_163 , 0 ) ;
if ( ! V_63 -> V_31 ) {
F_104 ( V_63 -> V_26 ) ;
V_63 -> V_26 = NULL ;
return - V_53 ;
}
F_105 ( V_63 -> V_31 , V_57 ,
0 , L_17 , L_17 ) ;
F_105 ( V_63 -> V_31 , V_109 ,
0 , L_18 , L_18 ) ;
F_105 ( V_63 -> V_31 , V_108 ,
0 , L_19 , L_19 ) ;
F_105 ( V_63 -> V_31 , V_119 ,
0 , L_20 , L_20 ) ;
F_105 ( V_63 -> V_31 , V_112 ,
0 , L_21 , L_21 ) ;
F_105 ( V_63 -> V_31 , V_78 ,
0 , L_22 , L_22 ) ;
F_105 ( V_63 -> V_31 , V_32 ,
V_164 , L_23 , L_23 ) ;
F_30 ( & V_63 -> V_165 ) ;
V_63 -> V_114 = V_8 ;
V_8 -> V_18 = V_63 ;
F_106 ( V_8 ) ;
F_107 ( & V_8 -> V_166 , L_24 , V_63 ) ;
F_30 ( & V_63 -> V_153 ) ;
F_108 ( & V_63 -> V_151 ) ;
F_94 ( V_63 , V_8 ) ;
return 0 ;
}
void F_109 ( struct V_9 * V_63 )
{
F_110 ( & V_167 ) ;
F_23 ( & V_63 -> V_165 ) ;
F_111 ( & V_167 ) ;
if ( V_63 -> V_26 ) {
F_104 ( V_63 -> V_26 ) ;
V_63 -> V_26 = NULL ;
}
if ( V_63 -> V_114 ) {
V_63 -> V_114 -> V_18 = NULL ;
F_112 ( & V_63 -> V_114 -> V_166 , L_24 , V_63 ) ;
F_113 ( V_63 -> V_114 ) ;
V_63 -> V_114 = NULL ;
}
if ( V_63 -> V_31 )
F_114 ( & V_63 -> V_31 ) ;
}
int F_115 ( struct V_9 * V_63 )
{
int V_50 ;
F_110 ( & V_167 ) ;
V_50 = F_116 ( & V_168 . V_87 ) ;
if ( V_50 == 0 )
F_73 ( & V_63 -> V_165 , & V_169 ) ;
F_111 ( & V_167 ) ;
return V_50 ;
}
void F_106 ( struct V_39 * V_150 )
{
F_91 ( & V_150 -> V_170 ) ;
}
void F_113 ( struct V_39 * V_150 )
{
F_4 ( F_40 ( & V_150 -> V_170 ) > 0 ) ;
F_117 ( & V_150 -> V_170 ) ;
}
int F_118 ( struct V_39 * V_150 , struct V_122 * V_171 )
{
if ( V_171 -> V_129 ++ == 0 && V_171 -> V_125 -> V_172 )
V_171 -> V_125 -> V_172 ( V_171 ) ;
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
F_119 ( & V_150 -> V_170 , 0 ) ;
V_150 -> V_99 = V_171 ;
F_120 ( & V_150 -> V_166 ) ;
F_30 ( & V_150 -> V_152 ) ;
return 0 ;
}
void F_121 ( struct V_39 * V_150 )
{
struct V_122 * V_171 ;
V_171 = V_150 -> V_99 ;
if ( V_150 -> V_173 ) {
V_150 -> V_173 -> V_174 = NULL ;
V_150 -> V_173 = NULL ;
}
F_122 ( & V_150 -> V_166 ) ;
F_123 ( F_40 ( & V_150 -> V_170 ) == 0 ,
L_25 , F_40 ( & V_150 -> V_170 ) ) ;
F_4 ( V_171 -> V_129 > 0 ) ;
if ( -- V_171 -> V_129 == 0 && V_171 -> V_125 -> V_130 )
V_171 -> V_125 -> V_130 ( V_171 ) ;
}
int F_124 ( struct V_3 * V_4 , struct V_7 * V_65 ,
struct V_39 * V_150 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_16 = V_65 ;
V_4 -> V_17 = V_150 ;
F_106 ( V_150 ) ;
F_125 ( & V_150 -> V_166 , & V_4 -> V_175 , L_26 , V_4 ) ;
F_30 ( & V_4 -> V_61 ) ;
return 0 ;
}
void F_126 ( struct V_3 * V_4 )
{
struct V_39 * V_40 = V_4 -> V_17 ;
F_4 ( F_5 ( & V_4 -> V_61 ) ) ;
if ( V_40 ) {
F_127 ( & V_40 -> V_166 , & V_4 -> V_175 ,
L_26 , V_4 ) ;
F_113 ( V_40 ) ;
V_4 -> V_17 = NULL ;
}
}
void F_128 ( struct V_7 * V_65 , struct V_3 * V_4 )
{
F_41 ( & V_4 -> V_61 , & V_65 -> V_54 ) ;
}
void F_129 ( struct V_3 * V_176 , struct V_3 * V_4 )
{
F_41 ( & V_4 -> V_61 , & V_176 -> V_61 ) ;
}
int F_130 ( struct V_7 * V_65 )
{
memset ( V_65 , 0 , sizeof( * V_65 ) ) ;
F_119 ( & V_65 -> V_23 , 1 ) ;
F_131 ( & V_65 -> V_19 ) ;
F_30 ( & V_65 -> V_22 ) ;
F_30 ( & V_65 -> V_54 ) ;
F_120 ( & V_65 -> V_177 ) ;
return 0 ;
}
void F_132 ( struct V_7 * V_65 )
{
F_4 ( F_5 ( & V_65 -> V_54 ) ) ;
F_4 ( F_5 ( & V_65 -> V_22 ) ) ;
F_4 ( F_51 ( & V_65 -> V_19 ) ) ;
F_122 ( & V_65 -> V_177 ) ;
}
struct V_3 * F_71 ( struct V_7 * V_65 ,
const struct V_122 * V_178 )
{
struct V_3 * V_4 ;
F_28 (o, &h->loh_layers, lo_linkage) {
if ( V_4 -> V_17 -> V_99 == V_178 )
return V_4 ;
}
return NULL ;
}
void F_133 ( const struct V_1 * V_2 , struct V_39 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_18 ;
struct V_39 * V_44 ;
struct V_39 * V_20 ;
F_34 ( V_2 , V_10 , ~ 0 ) ;
for ( V_44 = V_8 ; V_44 ; V_44 = V_20 ) {
V_20 = V_44 -> V_99 -> V_125 -> V_179 ( V_2 , V_44 ) ;
F_112 ( & V_44 -> V_166 , L_27 , & F_97 ) ;
F_113 ( V_44 ) ;
}
F_34 ( V_2 , V_10 , ~ 0 ) ;
for ( V_44 = V_8 ; V_44 ; V_44 = V_20 ) {
const struct V_122 * V_123 = V_44 -> V_99 ;
struct V_180 * type ;
V_20 = V_123 -> V_125 -> V_181 ( V_2 , V_44 ) ;
type = V_123 -> V_182 ;
if ( type ) {
type -> V_183 -- ;
F_134 ( type ) ;
}
}
}
int F_135 ( struct V_184 * V_84 )
{
int V_50 ;
int V_73 ;
F_4 ( V_84 -> V_185 ) ;
F_4 ( V_84 -> V_186 ) ;
F_4 ( V_84 -> V_187 != 0 ) ;
V_50 = - V_188 ;
F_95 ( & V_189 ) ;
for ( V_73 = 0 ; V_73 < F_46 ( V_190 ) ; ++ V_73 ) {
if ( ! V_190 [ V_73 ] ) {
V_84 -> V_191 = V_73 ;
F_119 ( & V_84 -> V_192 , 1 ) ;
V_190 [ V_73 ] = V_84 ;
F_120 ( & V_84 -> V_193 ) ;
V_50 = 0 ;
++ V_194 ;
break;
}
}
F_96 ( & V_189 ) ;
return V_50 ;
}
static void F_136 ( struct V_195 * V_196 , int V_197 )
{
if ( V_196 -> V_198 && V_196 -> V_198 [ V_197 ] ) {
struct V_184 * V_84 ;
V_84 = V_190 [ V_197 ] ;
F_4 ( F_40 ( & V_84 -> V_192 ) > 1 ) ;
V_84 -> V_186 ( V_196 , V_84 , V_196 -> V_198 [ V_197 ] ) ;
F_112 ( & V_84 -> V_193 , L_28 , V_196 ) ;
F_117 ( & V_84 -> V_192 ) ;
if ( ( V_196 -> V_199 & V_200 ) == 0 ) {
#ifdef F_137
F_138 ( F_139 ( V_84 -> V_201 ) > 0 ) ;
#endif
F_140 ( V_84 -> V_201 ) ;
}
V_196 -> V_198 [ V_197 ] = NULL ;
}
}
void F_141 ( struct V_184 * V_84 )
{
F_4 ( F_40 ( & V_84 -> V_192 ) >= 1 ) ;
F_138 ( 0 <= V_84 -> V_191 && V_84 -> V_191 < F_46 ( V_190 ) ) ;
F_142 ( V_84 ) ;
++ V_194 ;
F_95 ( & V_189 ) ;
F_136 ( & V_168 . V_87 , V_84 -> V_191 ) ;
if ( V_190 [ V_84 -> V_191 ] ) {
V_190 [ V_84 -> V_191 ] = NULL ;
F_122 ( & V_84 -> V_193 ) ;
}
F_96 ( & V_189 ) ;
F_123 ( F_40 ( & V_84 -> V_192 ) == 1 ,
L_29 ,
F_40 ( & V_84 -> V_192 ) ) ;
}
int F_143 ( struct V_184 * V_202 , ... )
{
struct V_184 * V_84 = V_202 ;
T_1 args ;
int V_50 ;
va_start ( args , V_202 ) ;
do {
V_50 = F_135 ( V_84 ) ;
if ( V_50 )
break;
V_84 = va_arg ( args , struct V_184 * ) ;
} while ( V_84 );
va_end ( args ) ;
if ( V_50 != 0 ) {
va_start ( args , V_202 ) ;
while ( V_202 != V_84 ) {
F_141 ( V_202 ) ;
V_202 = va_arg ( args , struct V_184 * ) ;
}
va_end ( args ) ;
}
return V_50 ;
}
void F_144 ( struct V_184 * V_202 , ... )
{
T_1 args ;
va_start ( args , V_202 ) ;
do {
F_141 ( V_202 ) ;
V_202 = va_arg ( args , struct V_184 * ) ;
} while ( V_202 );
va_end ( args ) ;
}
void F_145 ( struct V_184 * V_202 , ... )
{
T_1 args ;
va_start ( args , V_202 ) ;
do {
F_146 ( V_202 ) ;
V_202 = va_arg ( args , struct V_184 * ) ;
} while ( V_202 );
va_end ( args ) ;
}
void F_147 ( struct V_184 * V_202 , ... )
{
T_1 args ;
va_start ( args , V_202 ) ;
do {
F_142 ( V_202 ) ;
V_202 = va_arg ( args , struct V_184 * ) ;
} while ( V_202 );
va_end ( args ) ;
}
void * F_45 ( const struct V_195 * V_196 ,
const struct V_184 * V_84 )
{
F_138 ( V_196 -> V_203 == V_204 ) ;
F_138 ( 0 <= V_84 -> V_191 && V_84 -> V_191 < F_46 ( V_190 ) ) ;
F_4 ( V_190 [ V_84 -> V_191 ] == V_84 ) ;
return V_196 -> V_198 [ V_84 -> V_191 ] ;
}
void F_142 ( struct V_184 * V_84 )
{
struct V_195 * V_196 ;
if ( ! ( V_84 -> V_187 & V_205 ) ) {
V_84 -> V_187 |= V_205 ;
F_95 ( & V_189 ) ;
F_28 (ctx, &lu_context_remembered, lc_remember)
F_136 ( V_196 , V_84 -> V_191 ) ;
F_96 ( & V_189 ) ;
++ V_194 ;
}
}
void F_146 ( struct V_184 * V_84 )
{
V_84 -> V_187 &= ~ V_205 ;
++ V_194 ;
}
static void F_148 ( struct V_195 * V_196 )
{
int V_73 ;
if ( ! V_196 -> V_198 )
return;
for ( V_73 = 0 ; V_73 < F_46 ( V_190 ) ; ++ V_73 )
F_136 ( V_196 , V_73 ) ;
F_149 ( V_196 -> V_198 ) ;
V_196 -> V_198 = NULL ;
}
static int F_150 ( struct V_195 * V_196 )
{
int V_73 ;
F_138 ( V_196 -> V_198 ) ;
for ( V_73 = 0 ; V_73 < F_46 ( V_190 ) ; ++ V_73 ) {
struct V_184 * V_84 ;
V_84 = V_190 [ V_73 ] ;
if ( ! V_196 -> V_198 [ V_73 ] && V_84 &&
( V_84 -> V_187 & V_196 -> V_199 ) &&
! ( V_84 -> V_187 & V_205 ) ) {
void * V_206 ;
F_138 ( V_84 -> V_185 ) ;
F_138 ( V_84 -> V_191 == V_73 ) ;
V_206 = V_84 -> V_185 ( V_196 , V_84 ) ;
if ( F_27 ( V_206 ) )
return F_66 ( V_206 ) ;
if ( ! ( V_196 -> V_199 & V_200 ) )
F_151 ( V_84 -> V_201 ) ;
F_152 ( & V_84 -> V_193 , L_28 , V_196 ) ;
F_91 ( & V_84 -> V_192 ) ;
V_196 -> V_198 [ V_73 ] = V_206 ;
if ( V_84 -> V_207 )
V_196 -> V_199 |= V_208 ;
}
V_196 -> V_209 = V_194 ;
}
return 0 ;
}
static int F_153 ( struct V_195 * V_196 )
{
V_196 -> V_198 = F_154 ( F_46 ( V_190 ) , sizeof( V_196 -> V_198 [ 0 ] ) ,
V_210 ) ;
if ( F_56 ( V_196 -> V_198 ) )
return F_150 ( V_196 ) ;
return - V_53 ;
}
int F_155 ( struct V_195 * V_196 , T_5 V_211 )
{
int V_212 ;
memset ( V_196 , 0 , sizeof( * V_196 ) ) ;
V_196 -> V_203 = V_213 ;
V_196 -> V_199 = V_211 ;
if ( V_211 & V_214 ) {
F_95 ( & V_189 ) ;
F_73 ( & V_196 -> V_215 , & V_216 ) ;
F_96 ( & V_189 ) ;
} else {
F_30 ( & V_196 -> V_215 ) ;
}
V_212 = F_153 ( V_196 ) ;
if ( V_212 != 0 )
F_156 ( V_196 ) ;
return V_212 ;
}
void F_156 ( struct V_195 * V_196 )
{
F_138 ( V_196 -> V_203 == V_213 || V_196 -> V_203 == V_217 ) ;
V_196 -> V_203 = V_218 ;
if ( ( V_196 -> V_199 & V_214 ) == 0 ) {
F_4 ( F_5 ( & V_196 -> V_215 ) ) ;
F_148 ( V_196 ) ;
} else {
F_95 ( & V_189 ) ;
F_148 ( V_196 ) ;
F_23 ( & V_196 -> V_215 ) ;
F_96 ( & V_189 ) ;
}
}
void F_157 ( struct V_195 * V_196 )
{
F_138 ( V_196 -> V_203 == V_213 || V_196 -> V_203 == V_217 ) ;
V_196 -> V_203 = V_204 ;
}
void F_158 ( struct V_195 * V_196 )
{
int V_73 ;
F_138 ( V_196 -> V_203 == V_204 ) ;
V_196 -> V_203 = V_217 ;
if ( V_196 -> V_199 & V_208 && V_196 -> V_198 ) {
for ( V_73 = 0 ; V_73 < F_46 ( V_190 ) ; ++ V_73 ) {
if ( V_196 -> V_198 [ V_73 ] ) {
struct V_184 * V_84 ;
V_84 = V_190 [ V_73 ] ;
if ( V_84 -> V_207 )
V_84 -> V_207 ( V_196 ,
V_84 , V_196 -> V_198 [ V_73 ] ) ;
}
}
}
}
int F_116 ( struct V_195 * V_196 )
{
return F_56 ( V_196 -> V_209 == V_194 ) ? 0 : F_150 ( V_196 ) ;
}
int F_159 ( struct V_1 * V_2 , T_5 V_211 )
{
int V_50 ;
V_2 -> V_219 = NULL ;
V_50 = F_155 ( & V_2 -> V_87 , V_211 ) ;
if ( F_56 ( V_50 == 0 ) )
F_157 ( & V_2 -> V_87 ) ;
return V_50 ;
}
void F_160 ( struct V_1 * V_2 )
{
F_158 ( & V_2 -> V_87 ) ;
F_156 ( & V_2 -> V_87 ) ;
V_2 -> V_219 = NULL ;
}
int F_161 ( struct V_1 * V_2 )
{
int V_50 ;
V_50 = F_116 ( & V_2 -> V_87 ) ;
if ( V_50 == 0 && V_2 -> V_219 )
V_50 = F_116 ( V_2 -> V_219 ) ;
return V_50 ;
}
static void F_162 ( struct V_37 * V_115 ,
struct V_220 * V_221 , int V_222 )
{
struct V_12 V_13 ;
int V_73 ;
F_37 (hs, &bd, i) {
struct V_5 * V_6 = F_10 ( V_115 , & V_13 ) ;
struct V_223 * V_224 ;
F_38 ( V_115 , & V_13 , 1 ) ;
V_221 -> V_225 +=
F_163 ( & V_13 ) - V_6 -> V_30 ;
V_221 -> V_226 += F_163 ( & V_13 ) ;
V_221 -> V_227 = F_99 ( ( int ) V_221 -> V_227 ,
F_164 ( & V_13 ) ) ;
if ( ! V_222 ) {
F_17 ( V_115 , & V_13 , 1 ) ;
continue;
}
F_165 (hs, &bd, hhead) {
if ( ! F_166 ( V_224 ) )
V_221 -> V_228 ++ ;
}
F_17 ( V_115 , & V_13 , 1 ) ;
}
}
static unsigned long F_167 ( struct V_229 * V_230 ,
struct V_231 * V_232 )
{
struct V_9 * V_63 ;
struct V_9 * V_233 ;
unsigned long V_234 = 0 ;
if ( ! ( V_232 -> V_235 & V_236 ) )
return 0 ;
F_110 ( & V_167 ) ;
F_39 (s, tmp, &lu_sites, ls_linkage) {
V_234 += F_168 ( V_63 -> V_31 , V_32 ) ;
}
F_111 ( & V_167 ) ;
V_234 = ( V_234 / 100 ) * V_237 ;
F_16 ( V_33 , L_30 ,
V_234 , V_237 ) ;
return V_234 ;
}
static unsigned long F_169 ( struct V_229 * V_230 ,
struct V_231 * V_232 )
{
struct V_9 * V_63 ;
struct V_9 * V_233 ;
unsigned long V_238 = V_232 -> V_239 , V_240 = 0 ;
F_170 ( V_58 ) ;
if ( ! ( V_232 -> V_235 & V_236 ) )
return V_241 ;
F_110 ( & V_167 ) ;
F_39 (s, tmp, &lu_sites, ls_linkage) {
V_240 = F_34 ( & V_168 , V_63 , V_238 ) ;
V_238 -= V_240 ;
F_171 ( & V_63 -> V_165 , & V_58 ) ;
}
F_172 ( & V_58 , V_169 . V_60 ) ;
F_111 ( & V_167 ) ;
return V_232 -> V_239 - V_238 ;
}
int F_173 ( void )
{
int V_50 ;
F_16 ( V_242 , L_31 , & V_190 ) ;
V_50 = F_174 () ;
if ( V_50 != 0 )
return V_50 ;
F_175 ( & V_88 ) ;
V_50 = F_135 ( & V_88 ) ;
if ( V_50 != 0 )
return V_50 ;
F_110 ( & V_167 ) ;
V_50 = F_159 ( & V_168 , V_243 ) ;
F_111 ( & V_167 ) ;
if ( V_50 != 0 )
return V_50 ;
F_176 ( & V_244 ) ;
return V_50 ;
}
void F_177 ( void )
{
F_178 ( & V_244 ) ;
F_141 ( & V_88 ) ;
F_110 ( & V_167 ) ;
F_160 ( & V_168 ) ;
F_111 ( & V_167 ) ;
F_179 () ;
}
static T_5 F_168 ( struct V_245 * V_221 , int V_246 )
{
struct V_247 V_248 ;
F_180 ( V_221 , V_246 , & V_248 ) ;
if ( V_246 == V_32 )
return ( T_5 ) ( ( V_248 . V_249 > 0 ) ? V_248 . V_249 : 0 ) ;
return ( T_5 ) V_248 . V_250 ;
}
int F_181 ( const struct V_9 * V_63 , struct V_251 * V_252 )
{
struct V_220 V_221 ;
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
F_162 ( V_63 -> V_26 , & V_221 , 1 ) ;
F_182 ( V_252 , L_32 ,
V_221 . V_225 ,
V_221 . V_226 ,
V_221 . V_228 ,
F_183 ( V_63 -> V_26 ) ,
V_221 . V_227 ,
F_168 ( V_63 -> V_31 , V_57 ) ,
F_168 ( V_63 -> V_31 , V_109 ) ,
F_168 ( V_63 -> V_31 , V_108 ) ,
F_168 ( V_63 -> V_31 , V_119 ) ,
F_168 ( V_63 -> V_31 , V_112 ) ,
F_168 ( V_63 -> V_31 , V_78 ) ,
F_168 ( V_63 -> V_31 , V_32 ) ) ;
return 0 ;
}
int F_184 ( struct V_253 * V_254 )
{
int V_50 ;
struct V_253 * V_255 = V_254 ;
for ( V_50 = 0 ; V_255 -> V_256 ; ++ V_255 ) {
* V_255 -> V_256 = F_185 ( V_255 -> V_257 ,
V_255 -> V_258 ,
0 , 0 , NULL ) ;
if ( ! * V_255 -> V_256 ) {
V_50 = - V_53 ;
F_186 ( V_254 ) ;
break;
}
}
return V_50 ;
}
void F_186 ( struct V_253 * V_254 )
{
for (; V_254 -> V_256 ; ++ V_254 ) {
F_187 ( * V_254 -> V_256 ) ;
* V_254 -> V_256 = NULL ;
}
}
