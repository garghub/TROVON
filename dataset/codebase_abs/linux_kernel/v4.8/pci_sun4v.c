static inline void F_1 ( struct V_1 * V_2 , unsigned long V_3 , unsigned long V_4 )
{
struct V_5 * V_6 = F_2 ( & V_5 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_7 = 0 ;
}
static long F_3 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_2 -> V_10 . V_11 ;
unsigned long V_12 = V_9 -> V_12 ;
unsigned long V_3 = V_6 -> V_3 ;
unsigned long V_4 = V_6 -> V_4 ;
T_1 * V_13 = V_6 -> V_13 ;
unsigned long V_7 = V_6 -> V_7 ;
while ( V_7 != 0 ) {
long V_14 ;
V_14 = F_4 ( V_12 , F_5 ( 0 , V_4 ) ,
V_7 , V_3 , F_6 ( V_13 ) ) ;
if ( F_7 ( V_14 < 0 ) ) {
if ( F_8 () )
F_9 ( L_1
L_2
L_3 ,
V_12 , F_5 ( 0 , V_4 ) ,
V_7 , V_3 , F_6 ( V_13 ) , V_14 ) ;
return - 1 ;
}
V_4 += V_14 ;
V_7 -= V_14 ;
V_13 += V_14 ;
}
V_6 -> V_4 = V_4 ;
V_6 -> V_7 = 0 ;
return 0 ;
}
static inline void F_10 ( unsigned long V_4 )
{
struct V_5 * V_6 = F_2 ( & V_5 ) ;
if ( V_6 -> V_4 + V_6 -> V_7 == V_4 )
return;
if ( V_6 -> V_4 != ~ 0UL )
F_3 ( V_6 ) ;
V_6 -> V_4 = V_4 ;
}
static inline long F_11 ( T_1 V_15 )
{
struct V_5 * V_6 = F_2 ( & V_5 ) ;
F_12 ( V_6 -> V_7 >= V_16 ) ;
V_6 -> V_13 [ V_6 -> V_7 ++ ] = V_15 ;
if ( V_6 -> V_7 == V_16 )
return F_3 ( V_6 ) ;
return 0 ;
}
static inline long F_13 ( void )
{
struct V_5 * V_6 = F_2 ( & V_5 ) ;
F_12 ( V_6 -> V_7 >= V_16 ) ;
return F_3 ( V_6 ) ;
}
static void * F_14 ( struct V_1 * V_2 , T_2 V_17 ,
T_3 * V_18 , T_4 V_19 ,
unsigned long V_20 )
{
unsigned long V_21 , V_22 , V_23 , V_7 , V_24 ;
struct V_25 * V_25 ;
struct V_26 * V_26 ;
void * V_27 ;
long V_4 ;
int V_28 ;
V_17 = F_15 ( V_17 ) ;
V_22 = F_16 ( V_17 ) ;
if ( F_7 ( V_22 >= V_29 ) )
return NULL ;
V_7 = V_17 >> V_30 ;
V_28 = V_2 -> V_10 . V_31 ;
V_26 = F_17 ( V_28 , V_19 , V_22 ) ;
if ( F_7 ( ! V_26 ) )
return NULL ;
V_23 = ( unsigned long ) F_18 ( V_26 ) ;
memset ( ( char * ) V_23 , 0 , V_32 << V_22 ) ;
V_25 = V_2 -> V_10 . V_25 ;
V_4 = F_19 ( V_2 , & V_25 -> V_33 , V_7 , NULL ,
( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_7 ( V_4 == V_34 ) )
goto V_35;
* V_18 = ( V_25 -> V_33 . V_36 + ( V_4 << V_30 ) ) ;
V_27 = ( void * ) V_23 ;
V_23 = F_6 ( V_23 ) ;
F_20 ( V_21 ) ;
F_1 ( V_2 ,
( V_37 |
V_38 ) ,
V_4 ) ;
for ( V_24 = 0 ; V_24 < V_7 ; V_24 ++ ) {
long V_39 = F_11 ( V_23 + ( V_24 * V_32 ) ) ;
if ( F_7 ( V_39 < 0L ) )
goto V_40;
}
if ( F_7 ( F_13 () < 0L ) )
goto V_40;
F_21 ( V_21 ) ;
return V_27 ;
V_40:
F_22 ( & V_25 -> V_33 , * V_18 , V_7 , V_34 ) ;
V_35:
F_23 ( V_23 , V_22 ) ;
return NULL ;
}
static void F_24 ( void * V_41 , unsigned long V_4 ,
unsigned long V_7 )
{
T_5 V_12 = * ( T_5 * ) V_41 ;
unsigned long V_14 , V_21 ;
F_20 ( V_21 ) ;
do {
V_14 = F_25 ( V_12 ,
F_5 ( 0 , V_4 ) ,
V_7 ) ;
V_4 += V_14 ;
V_7 -= V_14 ;
} while ( V_7 != 0 );
F_21 ( V_21 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_2 V_17 , void * V_42 ,
T_3 V_43 , unsigned long V_20 )
{
struct V_8 * V_9 ;
struct V_25 * V_25 ;
unsigned long V_22 , V_7 , V_4 ;
T_5 V_12 ;
V_7 = F_15 ( V_17 ) >> V_30 ;
V_25 = V_2 -> V_10 . V_25 ;
V_9 = V_2 -> V_10 . V_11 ;
V_12 = V_9 -> V_12 ;
V_4 = ( ( V_43 - V_25 -> V_33 . V_36 ) >> V_30 ) ;
F_24 ( & V_12 , V_4 , V_7 ) ;
F_22 ( & V_25 -> V_33 , V_43 , V_7 , V_34 ) ;
V_22 = F_16 ( V_17 ) ;
if ( V_22 < 10 )
F_23 ( ( unsigned long ) V_42 , V_22 ) ;
}
static T_3 F_27 ( struct V_1 * V_2 , struct V_26 * V_26 ,
unsigned long V_44 , T_2 V_45 ,
enum V_46 V_47 ,
unsigned long V_20 )
{
struct V_25 * V_25 ;
unsigned long V_21 , V_7 , V_48 ;
unsigned long V_49 , V_50 ;
T_5 V_51 , V_27 ;
unsigned long V_3 ;
long V_4 ;
V_25 = V_2 -> V_10 . V_25 ;
if ( F_7 ( V_47 == V_52 ) )
goto V_53;
V_48 = ( unsigned long ) ( F_18 ( V_26 ) + V_44 ) ;
V_7 = F_15 ( V_48 + V_45 ) - ( V_48 & V_54 ) ;
V_7 >>= V_30 ;
V_4 = F_19 ( V_2 , & V_25 -> V_33 , V_7 , NULL ,
( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_7 ( V_4 == V_34 ) )
goto V_53;
V_51 = ( V_25 -> V_33 . V_36 + ( V_4 << V_30 ) ) ;
V_27 = V_51 | ( V_48 & ~ V_54 ) ;
V_50 = F_6 ( V_48 & V_54 ) ;
V_3 = V_37 ;
if ( V_47 != V_55 )
V_3 |= V_38 ;
F_20 ( V_21 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
for ( V_49 = 0 ; V_49 < V_7 ; V_49 ++ , V_50 += V_56 ) {
long V_39 = F_11 ( V_50 ) ;
if ( F_7 ( V_39 < 0L ) )
goto V_40;
}
if ( F_7 ( F_13 () < 0L ) )
goto V_40;
F_21 ( V_21 ) ;
return V_27 ;
V_53:
if ( F_8 () )
F_28 ( 1 ) ;
return V_57 ;
V_40:
F_22 ( & V_25 -> V_33 , V_51 , V_7 , V_34 ) ;
return V_57 ;
}
static void F_29 ( struct V_1 * V_2 , T_3 V_51 ,
T_2 V_45 , enum V_46 V_47 ,
unsigned long V_20 )
{
struct V_8 * V_9 ;
struct V_25 * V_25 ;
unsigned long V_7 ;
long V_4 ;
T_5 V_12 ;
if ( F_7 ( V_47 == V_52 ) ) {
if ( F_8 () )
F_28 ( 1 ) ;
return;
}
V_25 = V_2 -> V_10 . V_25 ;
V_9 = V_2 -> V_10 . V_11 ;
V_12 = V_9 -> V_12 ;
V_7 = F_15 ( V_51 + V_45 ) - ( V_51 & V_54 ) ;
V_7 >>= V_30 ;
V_51 &= V_54 ;
V_4 = ( V_51 - V_25 -> V_33 . V_36 ) >> V_30 ;
F_24 ( & V_12 , V_4 , V_7 ) ;
F_22 ( & V_25 -> V_33 , V_51 , V_7 , V_34 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_58 * V_59 ,
int V_60 , enum V_46 V_47 ,
unsigned long V_20 )
{
struct V_58 * V_61 , * V_62 , * V_63 ;
unsigned long V_21 , V_64 , V_3 ;
T_3 V_65 = 0 , V_66 ;
unsigned int V_67 ;
unsigned long V_68 ;
int V_69 , V_70 , V_49 ;
struct V_25 * V_25 ;
unsigned long V_71 ;
long V_39 ;
F_12 ( V_47 == V_52 ) ;
V_25 = V_2 -> V_10 . V_25 ;
if ( V_60 == 0 || ! V_25 )
return 0 ;
V_3 = V_37 ;
if ( V_47 != V_55 )
V_3 |= V_38 ;
V_62 = V_61 = V_63 = & V_59 [ 0 ] ;
V_69 = 1 ;
V_70 = V_60 ;
V_64 = 0 ;
V_62 -> V_72 = 0 ;
F_20 ( V_21 ) ;
F_1 ( V_2 , V_3 , ~ 0UL ) ;
V_67 = F_31 ( V_2 ) ;
V_68 = F_32 ( F_33 ( V_2 ) + 1 ,
V_56 ) >> V_30 ;
V_71 = V_25 -> V_33 . V_36 >> V_30 ;
F_34 (sglist, s, nelems, i) {
unsigned long V_73 , V_7 , V_4 , V_74 = 0 , V_75 ;
V_75 = V_61 -> V_76 ;
if ( V_75 == 0 ) {
V_65 = 0 ;
continue;
}
V_73 = ( unsigned long ) F_35 ( V_61 ) ;
V_7 = F_36 ( V_73 , V_75 , V_56 ) ;
V_4 = F_19 ( V_2 , & V_25 -> V_33 , V_7 ,
& V_64 , ( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_7 ( V_4 == V_34 ) ) {
if ( F_8 () )
F_9 ( V_77 L_4
L_5 , V_25 , V_73 , V_7 ) ;
goto V_78;
}
F_10 ( V_4 ) ;
V_66 = V_25 -> V_33 . V_36 + ( V_4 << V_30 ) ;
V_66 |= ( V_61 -> V_44 & ~ V_54 ) ;
V_73 &= V_54 ;
while ( V_7 -- ) {
V_39 = F_11 ( V_73 ) ;
if ( F_7 ( V_39 < 0L ) )
goto V_78;
V_73 += V_56 ;
}
if ( V_63 != V_61 ) {
if ( ( V_66 != V_65 ) ||
( V_62 -> V_72 + V_61 -> V_76 > V_67 ) ||
( F_37 ( V_74 , V_71 ,
V_68 , V_62 , V_61 ) ) ) {
V_63 = V_61 ;
V_69 ++ ;
V_62 = F_38 ( V_62 ) ;
} else {
V_62 -> V_72 += V_61 -> V_76 ;
}
}
if ( V_63 == V_61 ) {
V_62 -> V_79 = V_66 ;
V_62 -> V_72 = V_75 ;
V_74 = V_4 ;
}
V_65 = V_66 + V_75 ;
}
V_39 = F_13 () ;
if ( F_7 ( V_39 < 0L ) )
goto V_78;
F_21 ( V_21 ) ;
if ( V_69 < V_70 ) {
V_62 = F_38 ( V_62 ) ;
V_62 -> V_79 = V_57 ;
V_62 -> V_72 = 0 ;
}
return V_69 ;
V_78:
F_34 (sglist, s, nelems, i) {
if ( V_61 -> V_72 != 0 ) {
unsigned long V_80 , V_7 ;
V_80 = V_61 -> V_79 & V_54 ;
V_7 = F_36 ( V_61 -> V_79 , V_61 -> V_72 ,
V_56 ) ;
F_22 ( & V_25 -> V_33 , V_80 , V_7 ,
V_34 ) ;
V_61 -> V_79 = V_57 ;
V_61 -> V_72 = 0 ;
}
if ( V_61 == V_62 )
break;
}
F_21 ( V_21 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_58 * V_59 ,
int V_60 , enum V_46 V_47 ,
unsigned long V_20 )
{
struct V_8 * V_9 ;
struct V_58 * V_81 ;
struct V_25 * V_25 ;
unsigned long V_21 , V_4 ;
T_5 V_12 ;
F_12 ( V_47 == V_52 ) ;
V_25 = V_2 -> V_10 . V_25 ;
V_9 = V_2 -> V_10 . V_11 ;
V_12 = V_9 -> V_12 ;
F_20 ( V_21 ) ;
V_81 = V_59 ;
while ( V_60 -- ) {
T_3 V_82 = V_81 -> V_79 ;
unsigned int V_83 = V_81 -> V_72 ;
unsigned long V_7 ;
struct V_84 * V_33 = & V_25 -> V_33 ;
unsigned long V_85 = V_30 ;
if ( ! V_83 )
break;
V_7 = F_36 ( V_82 , V_83 , V_56 ) ;
V_4 = ( ( V_82 - V_33 -> V_36 ) >> V_85 ) ;
F_24 ( & V_12 , V_4 , V_7 ) ;
F_22 ( & V_25 -> V_33 , V_82 , V_7 ,
V_34 ) ;
V_81 = F_38 ( V_81 ) ;
}
F_21 ( V_21 ) ;
}
static void F_40 ( struct V_8 * V_9 , struct V_1 * V_86 )
{
struct V_87 * V_88 ;
struct V_89 * V_90 ;
V_90 = V_9 -> V_91 -> V_2 . V_92 ;
V_88 = F_41 ( V_90 , L_6 , NULL ) ;
V_9 -> V_93 = ( V_88 != NULL ) ;
V_9 -> V_94 = F_42 ( V_9 , V_86 ) ;
}
static unsigned long F_43 ( struct V_8 * V_9 ,
struct V_84 * V_25 )
{
struct V_95 * V_96 ;
unsigned long V_49 , V_97 , V_98 = 0 ;
T_5 V_12 ;
V_12 = V_9 -> V_12 ;
for ( V_97 = 0 ; V_97 < V_25 -> V_99 ; V_97 ++ ) {
V_96 = & ( V_25 -> V_100 [ V_97 ] ) ;
for ( V_49 = V_96 -> V_101 ; V_49 <= V_96 -> V_102 ; V_49 ++ ) {
unsigned long V_27 , V_103 , V_104 ;
V_27 = F_44 ( V_12 ,
F_5 ( 0 , V_49 ) ,
& V_103 , & V_104 ) ;
if ( V_27 == V_105 ) {
if ( F_45 ( V_104 ) ) {
F_25 ( V_12 ,
F_5 ( 0 ,
V_49 ) , 1 ) ;
} else {
V_98 ++ ;
F_46 ( V_49 , V_25 -> V_106 ) ;
}
}
}
}
return V_98 ;
}
static int F_47 ( struct V_8 * V_9 )
{
static const T_5 V_107 [] = { 0x80000000 , 0x80000000 } ;
struct V_25 * V_25 = V_9 -> V_25 ;
unsigned long V_108 , V_45 ;
T_5 V_109 , V_110 ;
const T_5 * V_111 ;
V_111 = F_48 ( V_9 -> V_91 -> V_2 . V_92 , L_7 , NULL ) ;
if ( ! V_111 )
V_111 = V_107 ;
if ( ( V_111 [ 0 ] | V_111 [ 1 ] ) & ~ V_54 ) {
F_9 (KERN_ERR PFX L_8 ,
vdma[0], vdma[1]) ;
return - V_112 ;
}
V_109 = ( F_49 ( V_111 [ 1 ] ) - 1UL ) ;
V_108 = V_111 [ 1 ] / V_56 ;
V_110 = V_111 [ 0 ] ;
F_50 ( & V_25 -> V_113 ) ;
V_25 -> V_114 = 1 ;
V_25 -> V_33 . V_36 = V_110 ;
V_25 -> V_115 = V_109 ;
V_45 = ( V_108 + 7 ) / 8 ;
V_45 = ( V_45 + 7UL ) & ~ 7UL ;
V_25 -> V_33 . V_106 = F_51 ( V_45 , V_116 ) ;
if ( ! V_25 -> V_33 . V_106 ) {
F_9 (KERN_ERR PFX L_9 ) ;
return - V_117 ;
}
F_52 ( & V_25 -> V_33 , V_108 , V_30 ,
NULL , false ,
0 ,
false ) ;
V_45 = F_43 ( V_9 , & V_25 -> V_33 ) ;
if ( V_45 )
F_9 ( L_10 ,
V_9 -> V_118 , V_45 ) ;
return 0 ;
}
static int F_53 ( struct V_8 * V_9 , unsigned long V_119 ,
unsigned long * V_120 )
{
unsigned long V_39 , V_121 ;
V_39 = F_54 ( V_9 -> V_12 , V_119 , V_120 ) ;
if ( F_7 ( V_39 ) )
return - V_122 ;
V_121 = V_9 -> V_123 * sizeof( struct V_124 ) ;
if ( F_7 ( * V_120 >= V_121 ) )
return - V_125 ;
return 0 ;
}
static int F_55 ( struct V_8 * V_9 ,
unsigned long V_119 , unsigned long * V_120 ,
unsigned long * V_126 )
{
struct V_124 * V_127 ;
unsigned long V_39 , type ;
V_127 = ( V_9 -> V_128 + ( ( V_119 - V_9 -> V_129 ) *
( V_9 -> V_123 *
sizeof( struct V_124 ) ) ) +
* V_120 ) ;
if ( ( V_127 -> V_130 & V_131 ) == 0 )
return 0 ;
type = ( V_127 -> V_130 & V_131 ) >> V_132 ;
if ( F_7 ( type != V_133 &&
type != V_134 ) )
return - V_112 ;
* V_126 = V_127 -> V_135 ;
V_39 = F_56 ( V_9 -> V_12 ,
V_127 -> V_135 ,
V_136 ) ;
if ( F_7 ( V_39 ) )
return - V_122 ;
V_127 -> V_130 &= ~ V_131 ;
( * V_120 ) += sizeof( struct V_124 ) ;
if ( * V_120 >=
( V_9 -> V_123 * sizeof( struct V_124 ) ) )
* V_120 = 0 ;
return 1 ;
}
static int F_57 ( struct V_8 * V_9 , unsigned long V_119 ,
unsigned long V_120 )
{
unsigned long V_39 ;
V_39 = F_58 ( V_9 -> V_12 , V_119 , V_120 ) ;
if ( F_7 ( V_39 ) )
return - V_112 ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 , unsigned long V_119 ,
unsigned long V_126 , int V_137 )
{
if ( F_60 ( V_9 -> V_12 , V_126 , V_119 ,
( V_137 ?
V_138 : V_139 ) ) )
return - V_122 ;
if ( F_56 ( V_9 -> V_12 , V_126 , V_136 ) )
return - V_122 ;
if ( F_61 ( V_9 -> V_12 , V_126 , V_140 ) )
return - V_122 ;
return 0 ;
}
static int F_62 ( struct V_8 * V_9 , unsigned long V_126 )
{
unsigned long V_39 , V_119 ;
V_39 = F_63 ( V_9 -> V_12 , V_126 , & V_119 ) ;
if ( V_39 )
return - V_122 ;
F_61 ( V_9 -> V_12 , V_126 , V_141 ) ;
return 0 ;
}
static int F_64 ( struct V_8 * V_9 )
{
unsigned long V_142 , V_143 , V_144 , V_22 ;
int V_49 ;
V_142 = V_9 -> V_123 * sizeof( struct V_124 ) ;
V_143 = ( V_9 -> V_145 * V_142 ) ;
V_22 = F_16 ( V_143 ) ;
V_144 = F_65 ( V_116 | V_146 , V_22 ) ;
if ( V_144 == 0UL ) {
F_9 ( V_147 L_11 ,
V_22 ) ;
return - V_117 ;
}
memset ( ( char * ) V_144 , 0 , V_32 << V_22 ) ;
V_9 -> V_128 = ( void * ) V_144 ;
for ( V_49 = 0 ; V_49 < V_9 -> V_145 ; V_49 ++ ) {
unsigned long V_39 , V_148 = F_6 ( V_144 + ( V_49 * V_142 ) ) ;
unsigned long V_149 , V_150 ;
V_39 = F_66 ( V_9 -> V_12 ,
V_9 -> V_129 + V_49 ,
V_148 , V_9 -> V_123 ) ;
if ( V_39 ) {
F_9 ( V_147 L_12 ,
V_39 ) ;
goto V_151;
}
V_39 = F_67 ( V_9 -> V_12 ,
V_9 -> V_129 + V_49 ,
& V_149 , & V_150 ) ;
if ( V_39 ) {
F_9 ( V_147 L_13 ,
V_39 ) ;
goto V_151;
}
if ( V_149 != V_148 || V_150 != V_9 -> V_123 ) {
F_9 ( V_147 L_14
L_15 ,
V_148 , V_9 -> V_123 ,
V_149 , V_150 ) ;
goto V_151;
}
}
return 0 ;
V_151:
F_23 ( V_144 , V_22 ) ;
return - V_112 ;
}
static void F_68 ( struct V_8 * V_9 )
{
unsigned long V_142 , V_143 , V_144 , V_22 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_9 -> V_145 ; V_49 ++ ) {
unsigned long V_119 = V_9 -> V_129 + V_49 ;
( void ) F_66 ( V_9 -> V_12 , V_119 , 0UL , 0 ) ;
}
V_142 = V_9 -> V_123 * sizeof( struct V_124 ) ;
V_143 = ( V_9 -> V_145 * V_142 ) ;
V_22 = F_16 ( V_143 ) ;
V_144 = ( unsigned long ) V_9 -> V_128 ;
F_23 ( V_144 , V_22 ) ;
V_9 -> V_128 = NULL ;
}
static int F_69 ( struct V_8 * V_9 ,
unsigned long V_119 ,
unsigned long V_152 )
{
unsigned int V_153 = F_70 ( V_9 -> V_12 , V_152 ) ;
if ( ! V_153 )
return - V_117 ;
if ( F_71 ( V_9 -> V_12 , V_119 , V_154 ) )
return - V_112 ;
if ( F_72 ( V_9 -> V_12 , V_119 , V_155 ) )
return - V_112 ;
return V_153 ;
}
static void F_73 ( struct V_8 * V_9 )
{
F_74 ( V_9 , & V_156 ) ;
}
static void F_73 ( struct V_8 * V_9 )
{
}
static int F_75 ( struct V_8 * V_9 ,
struct V_157 * V_91 , T_5 V_12 )
{
struct V_89 * V_90 = V_91 -> V_2 . V_92 ;
int V_39 ;
V_9 -> V_31 = F_76 ( V_90 ) ;
V_9 -> V_158 = & V_159 ;
V_9 -> V_160 = 12 ;
V_9 -> V_161 = V_162 ++ ;
V_9 -> V_91 = V_91 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_118 = V_90 -> V_163 ;
F_9 ( L_16 , V_9 -> V_118 ) ;
F_9 ( L_17 , V_9 -> V_118 , V_9 -> V_31 ) ;
F_77 ( V_9 ) ;
F_78 ( V_9 ) ;
V_39 = F_47 ( V_9 ) ;
if ( V_39 )
return V_39 ;
F_73 ( V_9 ) ;
F_40 ( V_9 , & V_91 -> V_2 ) ;
V_9 -> V_164 = V_165 ;
V_165 = V_9 ;
return 0 ;
}
static int F_79 ( struct V_157 * V_91 )
{
const struct V_166 * V_167 ;
static int V_168 = 0 ;
struct V_8 * V_9 ;
struct V_89 * V_90 ;
struct V_25 * V_25 ;
T_5 V_12 ;
int V_49 , V_39 ;
V_90 = V_91 -> V_2 . V_92 ;
if ( ! V_168 ++ ) {
V_39 = F_80 ( V_169 ,
V_170 ,
& V_171 ) ;
if ( V_39 ) {
F_9 (KERN_ERR PFX L_18
L_19 , err) ;
return V_39 ;
}
F_9 (KERN_INFO PFX L_20 ,
vpci_major, vpci_minor) ;
V_172 = & V_173 ;
}
V_167 = F_48 ( V_90 , L_21 , NULL ) ;
V_39 = - V_174 ;
if ( ! V_167 ) {
F_9 (KERN_ERR PFX L_22 ) ;
goto V_175;
}
V_12 = ( V_167 -> V_176 >> 32UL ) & 0x0fffffff ;
V_39 = - V_117 ;
if ( ! V_177 ) {
F_81 (i) {
unsigned long V_26 = F_82 ( V_116 ) ;
if ( ! V_26 )
goto V_175;
F_83 ( V_5 , V_49 ) . V_13 = ( T_1 * ) V_26 ;
}
V_177 = 1 ;
}
V_9 = F_51 ( sizeof( * V_9 ) , V_116 ) ;
if ( ! V_9 ) {
F_9 (KERN_ERR PFX L_23 ) ;
goto V_175;
}
V_25 = F_51 ( sizeof( struct V_25 ) , V_116 ) ;
if ( ! V_25 ) {
F_9 (KERN_ERR PFX L_24 ) ;
goto V_178;
}
V_9 -> V_25 = V_25 ;
V_39 = F_75 ( V_9 , V_91 , V_12 ) ;
if ( V_39 )
goto V_179;
F_84 ( & V_91 -> V_2 , V_9 ) ;
return 0 ;
V_179:
F_85 ( V_9 -> V_25 ) ;
V_178:
F_85 ( V_9 ) ;
V_175:
return V_39 ;
}
static int T_6 F_86 ( void )
{
return F_87 ( & V_180 ) ;
}
