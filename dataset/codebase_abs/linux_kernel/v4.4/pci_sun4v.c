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
struct V_20 * V_21 )
{
unsigned long V_22 , V_23 , V_24 , V_7 , V_25 ;
struct V_26 * V_26 ;
struct V_27 * V_27 ;
void * V_28 ;
long V_4 ;
int V_29 ;
V_17 = F_15 ( V_17 ) ;
V_23 = F_16 ( V_17 ) ;
if ( F_7 ( V_23 >= V_30 ) )
return NULL ;
V_7 = V_17 >> V_31 ;
V_29 = V_2 -> V_10 . V_32 ;
V_27 = F_17 ( V_29 , V_19 , V_23 ) ;
if ( F_7 ( ! V_27 ) )
return NULL ;
V_24 = ( unsigned long ) F_18 ( V_27 ) ;
memset ( ( char * ) V_24 , 0 , V_33 << V_23 ) ;
V_26 = V_2 -> V_10 . V_26 ;
V_4 = F_19 ( V_2 , & V_26 -> V_34 , V_7 , NULL ,
( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_7 ( V_4 == V_35 ) )
goto V_36;
* V_18 = ( V_26 -> V_34 . V_37 + ( V_4 << V_31 ) ) ;
V_28 = ( void * ) V_24 ;
V_24 = F_6 ( V_24 ) ;
F_20 ( V_22 ) ;
F_1 ( V_2 ,
( V_38 |
V_39 ) ,
V_4 ) ;
for ( V_25 = 0 ; V_25 < V_7 ; V_25 ++ ) {
long V_40 = F_11 ( V_24 + ( V_25 * V_33 ) ) ;
if ( F_7 ( V_40 < 0L ) )
goto V_41;
}
if ( F_7 ( F_13 () < 0L ) )
goto V_41;
F_21 ( V_22 ) ;
return V_28 ;
V_41:
F_22 ( & V_26 -> V_34 , * V_18 , V_7 , V_35 ) ;
V_36:
F_23 ( V_24 , V_23 ) ;
return NULL ;
}
static void F_24 ( void * V_42 , unsigned long V_4 ,
unsigned long V_7 )
{
T_5 V_12 = * ( T_5 * ) V_42 ;
unsigned long V_14 , V_22 ;
F_20 ( V_22 ) ;
do {
V_14 = F_25 ( V_12 ,
F_5 ( 0 , V_4 ) ,
V_7 ) ;
V_4 += V_14 ;
V_7 -= V_14 ;
} while ( V_7 != 0 );
F_21 ( V_22 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_2 V_17 , void * V_43 ,
T_3 V_44 , struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_26 * V_26 ;
unsigned long V_23 , V_7 , V_4 ;
T_5 V_12 ;
V_7 = F_15 ( V_17 ) >> V_31 ;
V_26 = V_2 -> V_10 . V_26 ;
V_9 = V_2 -> V_10 . V_11 ;
V_12 = V_9 -> V_12 ;
V_4 = ( ( V_44 - V_26 -> V_34 . V_37 ) >> V_31 ) ;
F_24 ( & V_12 , V_4 , V_7 ) ;
F_22 ( & V_26 -> V_34 , V_44 , V_7 , V_35 ) ;
V_23 = F_16 ( V_17 ) ;
if ( V_23 < 10 )
F_23 ( ( unsigned long ) V_43 , V_23 ) ;
}
static T_3 F_27 ( struct V_1 * V_2 , struct V_27 * V_27 ,
unsigned long V_45 , T_2 V_46 ,
enum V_47 V_48 ,
struct V_20 * V_21 )
{
struct V_26 * V_26 ;
unsigned long V_22 , V_7 , V_49 ;
unsigned long V_50 , V_51 ;
T_5 V_52 , V_28 ;
unsigned long V_3 ;
long V_4 ;
V_26 = V_2 -> V_10 . V_26 ;
if ( F_7 ( V_48 == V_53 ) )
goto V_54;
V_49 = ( unsigned long ) ( F_18 ( V_27 ) + V_45 ) ;
V_7 = F_15 ( V_49 + V_46 ) - ( V_49 & V_55 ) ;
V_7 >>= V_31 ;
V_4 = F_19 ( V_2 , & V_26 -> V_34 , V_7 , NULL ,
( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_7 ( V_4 == V_35 ) )
goto V_54;
V_52 = ( V_26 -> V_34 . V_37 + ( V_4 << V_31 ) ) ;
V_28 = V_52 | ( V_49 & ~ V_55 ) ;
V_51 = F_6 ( V_49 & V_55 ) ;
V_3 = V_38 ;
if ( V_48 != V_56 )
V_3 |= V_39 ;
F_20 ( V_22 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
for ( V_50 = 0 ; V_50 < V_7 ; V_50 ++ , V_51 += V_57 ) {
long V_40 = F_11 ( V_51 ) ;
if ( F_7 ( V_40 < 0L ) )
goto V_41;
}
if ( F_7 ( F_13 () < 0L ) )
goto V_41;
F_21 ( V_22 ) ;
return V_28 ;
V_54:
if ( F_8 () )
F_28 ( 1 ) ;
return V_58 ;
V_41:
F_22 ( & V_26 -> V_34 , V_52 , V_7 , V_35 ) ;
return V_58 ;
}
static void F_29 ( struct V_1 * V_2 , T_3 V_52 ,
T_2 V_46 , enum V_47 V_48 ,
struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_26 * V_26 ;
unsigned long V_7 ;
long V_4 ;
T_5 V_12 ;
if ( F_7 ( V_48 == V_53 ) ) {
if ( F_8 () )
F_28 ( 1 ) ;
return;
}
V_26 = V_2 -> V_10 . V_26 ;
V_9 = V_2 -> V_10 . V_11 ;
V_12 = V_9 -> V_12 ;
V_7 = F_15 ( V_52 + V_46 ) - ( V_52 & V_55 ) ;
V_7 >>= V_31 ;
V_52 &= V_55 ;
V_4 = ( V_52 - V_26 -> V_34 . V_37 ) >> V_31 ;
F_24 ( & V_12 , V_4 , V_7 ) ;
F_22 ( & V_26 -> V_34 , V_52 , V_7 , V_35 ) ;
}
static int F_30 ( struct V_1 * V_2 , struct V_59 * V_60 ,
int V_61 , enum V_47 V_48 ,
struct V_20 * V_21 )
{
struct V_59 * V_62 , * V_63 , * V_64 ;
unsigned long V_22 , V_65 , V_3 ;
T_3 V_66 = 0 , V_67 ;
unsigned int V_68 ;
unsigned long V_69 ;
int V_70 , V_71 , V_50 ;
struct V_26 * V_26 ;
unsigned long V_72 ;
long V_40 ;
F_12 ( V_48 == V_53 ) ;
V_26 = V_2 -> V_10 . V_26 ;
if ( V_61 == 0 || ! V_26 )
return 0 ;
V_3 = V_38 ;
if ( V_48 != V_56 )
V_3 |= V_39 ;
V_63 = V_62 = V_64 = & V_60 [ 0 ] ;
V_70 = 1 ;
V_71 = V_61 ;
V_65 = 0 ;
V_63 -> V_73 = 0 ;
F_20 ( V_22 ) ;
F_1 ( V_2 , V_3 , ~ 0UL ) ;
V_68 = F_31 ( V_2 ) ;
V_69 = F_32 ( F_33 ( V_2 ) + 1 ,
V_57 ) >> V_31 ;
V_72 = V_26 -> V_34 . V_37 >> V_31 ;
F_34 (sglist, s, nelems, i) {
unsigned long V_74 , V_7 , V_4 , V_75 = 0 , V_76 ;
V_76 = V_62 -> V_77 ;
if ( V_76 == 0 ) {
V_66 = 0 ;
continue;
}
V_74 = ( unsigned long ) F_35 ( V_62 ) ;
V_7 = F_36 ( V_74 , V_76 , V_57 ) ;
V_4 = F_19 ( V_2 , & V_26 -> V_34 , V_7 ,
& V_65 , ( unsigned long ) ( - 1 ) , 0 ) ;
if ( F_7 ( V_4 == V_35 ) ) {
if ( F_8 () )
F_9 ( V_78 L_4
L_5 , V_26 , V_74 , V_7 ) ;
goto V_79;
}
F_10 ( V_4 ) ;
V_67 = V_26 -> V_34 . V_37 + ( V_4 << V_31 ) ;
V_67 |= ( V_62 -> V_45 & ~ V_55 ) ;
V_74 &= V_55 ;
while ( V_7 -- ) {
V_40 = F_11 ( V_74 ) ;
if ( F_7 ( V_40 < 0L ) )
goto V_79;
V_74 += V_57 ;
}
if ( V_64 != V_62 ) {
if ( ( V_67 != V_66 ) ||
( V_63 -> V_73 + V_62 -> V_77 > V_68 ) ||
( F_37 ( V_75 , V_72 ,
V_69 , V_63 , V_62 ) ) ) {
V_64 = V_62 ;
V_70 ++ ;
V_63 = F_38 ( V_63 ) ;
} else {
V_63 -> V_73 += V_62 -> V_77 ;
}
}
if ( V_64 == V_62 ) {
V_63 -> V_80 = V_67 ;
V_63 -> V_73 = V_76 ;
V_75 = V_4 ;
}
V_66 = V_67 + V_76 ;
}
V_40 = F_13 () ;
if ( F_7 ( V_40 < 0L ) )
goto V_79;
F_21 ( V_22 ) ;
if ( V_70 < V_71 ) {
V_63 = F_38 ( V_63 ) ;
V_63 -> V_80 = V_58 ;
V_63 -> V_73 = 0 ;
}
return V_70 ;
V_79:
F_34 (sglist, s, nelems, i) {
if ( V_62 -> V_73 != 0 ) {
unsigned long V_81 , V_7 ;
V_81 = V_62 -> V_80 & V_55 ;
V_7 = F_36 ( V_62 -> V_80 , V_62 -> V_73 ,
V_57 ) ;
F_22 ( & V_26 -> V_34 , V_81 , V_7 ,
V_35 ) ;
V_62 -> V_80 = V_58 ;
V_62 -> V_73 = 0 ;
}
if ( V_62 == V_63 )
break;
}
F_21 ( V_22 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 , struct V_59 * V_60 ,
int V_61 , enum V_47 V_48 ,
struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_59 * V_82 ;
struct V_26 * V_26 ;
unsigned long V_22 , V_4 ;
T_5 V_12 ;
F_12 ( V_48 == V_53 ) ;
V_26 = V_2 -> V_10 . V_26 ;
V_9 = V_2 -> V_10 . V_11 ;
V_12 = V_9 -> V_12 ;
F_20 ( V_22 ) ;
V_82 = V_60 ;
while ( V_61 -- ) {
T_3 V_83 = V_82 -> V_80 ;
unsigned int V_84 = V_82 -> V_73 ;
unsigned long V_7 ;
struct V_85 * V_34 = & V_26 -> V_34 ;
unsigned long V_86 = V_31 ;
if ( ! V_84 )
break;
V_7 = F_36 ( V_83 , V_84 , V_57 ) ;
V_4 = ( ( V_83 - V_34 -> V_37 ) >> V_86 ) ;
F_24 ( & V_12 , V_4 , V_7 ) ;
F_22 ( & V_26 -> V_34 , V_83 , V_7 ,
V_35 ) ;
V_82 = F_38 ( V_82 ) ;
}
F_21 ( V_22 ) ;
}
static void F_40 ( struct V_8 * V_9 , struct V_1 * V_87 )
{
struct V_88 * V_89 ;
struct V_90 * V_91 ;
V_91 = V_9 -> V_92 -> V_2 . V_93 ;
V_89 = F_41 ( V_91 , L_6 , NULL ) ;
V_9 -> V_94 = ( V_89 != NULL ) ;
V_9 -> V_95 = F_42 ( V_9 , V_87 ) ;
}
static unsigned long F_43 ( struct V_8 * V_9 ,
struct V_85 * V_26 )
{
struct V_96 * V_97 ;
unsigned long V_50 , V_98 , V_99 = 0 ;
T_5 V_12 ;
V_12 = V_9 -> V_12 ;
for ( V_98 = 0 ; V_98 < V_26 -> V_100 ; V_98 ++ ) {
V_97 = & ( V_26 -> V_101 [ V_98 ] ) ;
for ( V_50 = V_97 -> V_102 ; V_50 <= V_97 -> V_103 ; V_50 ++ ) {
unsigned long V_28 , V_104 , V_105 ;
V_28 = F_44 ( V_12 ,
F_5 ( 0 , V_50 ) ,
& V_104 , & V_105 ) ;
if ( V_28 == V_106 ) {
if ( F_45 ( V_105 ) ) {
F_25 ( V_12 ,
F_5 ( 0 ,
V_50 ) , 1 ) ;
} else {
V_99 ++ ;
F_46 ( V_50 , V_26 -> V_107 ) ;
}
}
}
}
return V_99 ;
}
static int F_47 ( struct V_8 * V_9 )
{
static const T_5 V_108 [] = { 0x80000000 , 0x80000000 } ;
struct V_26 * V_26 = V_9 -> V_26 ;
unsigned long V_109 , V_46 ;
T_5 V_110 , V_111 ;
const T_5 * V_112 ;
V_112 = F_48 ( V_9 -> V_92 -> V_2 . V_93 , L_7 , NULL ) ;
if ( ! V_112 )
V_112 = V_108 ;
if ( ( V_112 [ 0 ] | V_112 [ 1 ] ) & ~ V_55 ) {
F_9 (KERN_ERR PFX L_8 ,
vdma[0], vdma[1]) ;
return - V_113 ;
}
V_110 = ( F_49 ( V_112 [ 1 ] ) - 1UL ) ;
V_109 = V_112 [ 1 ] / V_57 ;
V_111 = V_112 [ 0 ] ;
F_50 ( & V_26 -> V_114 ) ;
V_26 -> V_115 = 1 ;
V_26 -> V_34 . V_37 = V_111 ;
V_26 -> V_116 = V_110 ;
V_46 = ( V_109 + 7 ) / 8 ;
V_46 = ( V_46 + 7UL ) & ~ 7UL ;
V_26 -> V_34 . V_107 = F_51 ( V_46 , V_117 ) ;
if ( ! V_26 -> V_34 . V_107 ) {
F_9 (KERN_ERR PFX L_9 ) ;
return - V_118 ;
}
F_52 ( & V_26 -> V_34 , V_109 , V_31 ,
NULL , false ,
0 ,
false ) ;
V_46 = F_43 ( V_9 , & V_26 -> V_34 ) ;
if ( V_46 )
F_9 ( L_10 ,
V_9 -> V_119 , V_46 ) ;
return 0 ;
}
static int F_53 ( struct V_8 * V_9 , unsigned long V_120 ,
unsigned long * V_121 )
{
unsigned long V_40 , V_122 ;
V_40 = F_54 ( V_9 -> V_12 , V_120 , V_121 ) ;
if ( F_7 ( V_40 ) )
return - V_123 ;
V_122 = V_9 -> V_124 * sizeof( struct V_125 ) ;
if ( F_7 ( * V_121 >= V_122 ) )
return - V_126 ;
return 0 ;
}
static int F_55 ( struct V_8 * V_9 ,
unsigned long V_120 , unsigned long * V_121 ,
unsigned long * V_127 )
{
struct V_125 * V_128 ;
unsigned long V_40 , type ;
V_128 = ( V_9 -> V_129 + ( ( V_120 - V_9 -> V_130 ) *
( V_9 -> V_124 *
sizeof( struct V_125 ) ) ) +
* V_121 ) ;
if ( ( V_128 -> V_131 & V_132 ) == 0 )
return 0 ;
type = ( V_128 -> V_131 & V_132 ) >> V_133 ;
if ( F_7 ( type != V_134 &&
type != V_135 ) )
return - V_113 ;
* V_127 = V_128 -> V_136 ;
V_40 = F_56 ( V_9 -> V_12 ,
V_128 -> V_136 ,
V_137 ) ;
if ( F_7 ( V_40 ) )
return - V_123 ;
V_128 -> V_131 &= ~ V_132 ;
( * V_121 ) += sizeof( struct V_125 ) ;
if ( * V_121 >=
( V_9 -> V_124 * sizeof( struct V_125 ) ) )
* V_121 = 0 ;
return 1 ;
}
static int F_57 ( struct V_8 * V_9 , unsigned long V_120 ,
unsigned long V_121 )
{
unsigned long V_40 ;
V_40 = F_58 ( V_9 -> V_12 , V_120 , V_121 ) ;
if ( F_7 ( V_40 ) )
return - V_113 ;
return 0 ;
}
static int F_59 ( struct V_8 * V_9 , unsigned long V_120 ,
unsigned long V_127 , int V_138 )
{
if ( F_60 ( V_9 -> V_12 , V_127 , V_120 ,
( V_138 ?
V_139 : V_140 ) ) )
return - V_123 ;
if ( F_56 ( V_9 -> V_12 , V_127 , V_137 ) )
return - V_123 ;
if ( F_61 ( V_9 -> V_12 , V_127 , V_141 ) )
return - V_123 ;
return 0 ;
}
static int F_62 ( struct V_8 * V_9 , unsigned long V_127 )
{
unsigned long V_40 , V_120 ;
V_40 = F_63 ( V_9 -> V_12 , V_127 , & V_120 ) ;
if ( V_40 )
return - V_123 ;
F_61 ( V_9 -> V_12 , V_127 , V_142 ) ;
return 0 ;
}
static int F_64 ( struct V_8 * V_9 )
{
unsigned long V_143 , V_144 , V_145 , V_23 ;
int V_50 ;
V_143 = V_9 -> V_124 * sizeof( struct V_125 ) ;
V_144 = ( V_9 -> V_146 * V_143 ) ;
V_23 = F_16 ( V_144 ) ;
V_145 = F_65 ( V_117 | V_147 , V_23 ) ;
if ( V_145 == 0UL ) {
F_9 ( V_148 L_11 ,
V_23 ) ;
return - V_118 ;
}
memset ( ( char * ) V_145 , 0 , V_33 << V_23 ) ;
V_9 -> V_129 = ( void * ) V_145 ;
for ( V_50 = 0 ; V_50 < V_9 -> V_146 ; V_50 ++ ) {
unsigned long V_40 , V_149 = F_6 ( V_145 + ( V_50 * V_143 ) ) ;
unsigned long V_150 , V_151 ;
V_40 = F_66 ( V_9 -> V_12 ,
V_9 -> V_130 + V_50 ,
V_149 , V_9 -> V_124 ) ;
if ( V_40 ) {
F_9 ( V_148 L_12 ,
V_40 ) ;
goto V_152;
}
V_40 = F_67 ( V_9 -> V_12 ,
V_9 -> V_130 + V_50 ,
& V_150 , & V_151 ) ;
if ( V_40 ) {
F_9 ( V_148 L_13 ,
V_40 ) ;
goto V_152;
}
if ( V_150 != V_149 || V_151 != V_9 -> V_124 ) {
F_9 ( V_148 L_14
L_15 ,
V_149 , V_9 -> V_124 ,
V_150 , V_151 ) ;
goto V_152;
}
}
return 0 ;
V_152:
F_23 ( V_145 , V_23 ) ;
return - V_113 ;
}
static void F_68 ( struct V_8 * V_9 )
{
unsigned long V_143 , V_144 , V_145 , V_23 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_9 -> V_146 ; V_50 ++ ) {
unsigned long V_120 = V_9 -> V_130 + V_50 ;
( void ) F_66 ( V_9 -> V_12 , V_120 , 0UL , 0 ) ;
}
V_143 = V_9 -> V_124 * sizeof( struct V_125 ) ;
V_144 = ( V_9 -> V_146 * V_143 ) ;
V_23 = F_16 ( V_144 ) ;
V_145 = ( unsigned long ) V_9 -> V_129 ;
F_23 ( V_145 , V_23 ) ;
V_9 -> V_129 = NULL ;
}
static int F_69 ( struct V_8 * V_9 ,
unsigned long V_120 ,
unsigned long V_153 )
{
unsigned int V_154 = F_70 ( V_9 -> V_12 , V_153 ) ;
if ( ! V_154 )
return - V_118 ;
if ( F_71 ( V_9 -> V_12 , V_120 , V_155 ) )
return - V_113 ;
if ( F_72 ( V_9 -> V_12 , V_120 , V_156 ) )
return - V_113 ;
return V_154 ;
}
static void F_73 ( struct V_8 * V_9 )
{
F_74 ( V_9 , & V_157 ) ;
}
static void F_73 ( struct V_8 * V_9 )
{
}
static int F_75 ( struct V_8 * V_9 ,
struct V_158 * V_92 , T_5 V_12 )
{
struct V_90 * V_91 = V_92 -> V_2 . V_93 ;
int V_40 ;
V_9 -> V_32 = F_76 ( V_91 ) ;
V_9 -> V_159 = & V_160 ;
V_9 -> V_161 = 12 ;
V_9 -> V_162 = V_163 ++ ;
V_9 -> V_92 = V_92 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_119 = V_91 -> V_164 ;
F_9 ( L_16 , V_9 -> V_119 ) ;
F_9 ( L_17 , V_9 -> V_119 , V_9 -> V_32 ) ;
F_77 ( V_9 ) ;
F_78 ( V_9 ) ;
V_40 = F_47 ( V_9 ) ;
if ( V_40 )
return V_40 ;
F_73 ( V_9 ) ;
F_40 ( V_9 , & V_92 -> V_2 ) ;
V_9 -> V_165 = V_166 ;
V_166 = V_9 ;
return 0 ;
}
static int F_79 ( struct V_158 * V_92 )
{
const struct V_167 * V_168 ;
static int V_169 = 0 ;
struct V_8 * V_9 ;
struct V_90 * V_91 ;
struct V_26 * V_26 ;
T_5 V_12 ;
int V_50 , V_40 ;
V_91 = V_92 -> V_2 . V_93 ;
if ( ! V_169 ++ ) {
V_40 = F_80 ( V_170 ,
V_171 ,
& V_172 ) ;
if ( V_40 ) {
F_9 (KERN_ERR PFX L_18
L_19 , err) ;
return V_40 ;
}
F_9 (KERN_INFO PFX L_20 ,
vpci_major, vpci_minor) ;
V_173 = & V_174 ;
}
V_168 = F_48 ( V_91 , L_21 , NULL ) ;
V_40 = - V_175 ;
if ( ! V_168 ) {
F_9 (KERN_ERR PFX L_22 ) ;
goto V_176;
}
V_12 = ( V_168 -> V_177 >> 32UL ) & 0x0fffffff ;
V_40 = - V_118 ;
if ( ! V_178 ) {
F_81 (i) {
unsigned long V_27 = F_82 ( V_117 ) ;
if ( ! V_27 )
goto V_176;
F_83 ( V_5 , V_50 ) . V_13 = ( T_1 * ) V_27 ;
}
V_178 = 1 ;
}
V_9 = F_51 ( sizeof( * V_9 ) , V_117 ) ;
if ( ! V_9 ) {
F_9 (KERN_ERR PFX L_23 ) ;
goto V_176;
}
V_26 = F_51 ( sizeof( struct V_26 ) , V_117 ) ;
if ( ! V_26 ) {
F_9 (KERN_ERR PFX L_24 ) ;
goto V_179;
}
V_9 -> V_26 = V_26 ;
V_40 = F_75 ( V_9 , V_92 , V_12 ) ;
if ( V_40 )
goto V_180;
F_84 ( & V_92 -> V_2 , V_9 ) ;
return 0 ;
V_180:
F_85 ( V_9 -> V_26 ) ;
V_179:
F_85 ( V_9 ) ;
V_176:
return V_40 ;
}
static int T_6 F_86 ( void )
{
return F_87 ( & V_181 ) ;
}
