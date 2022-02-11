static inline void F_1 ( struct V_1 * V_2 , unsigned long V_3 , unsigned long V_4 )
{
struct V_5 * V_6 = & F_2 ( V_5 ) ;
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
struct V_5 * V_6 = & F_2 ( V_5 ) ;
if ( V_6 -> V_4 + V_6 -> V_7 == V_4 )
return;
if ( V_6 -> V_4 != ~ 0UL )
F_3 ( V_6 ) ;
V_6 -> V_4 = V_4 ;
}
static inline long F_11 ( T_1 V_15 )
{
struct V_5 * V_6 = & F_2 ( V_5 ) ;
F_12 ( V_6 -> V_7 >= V_16 ) ;
V_6 -> V_13 [ V_6 -> V_7 ++ ] = V_15 ;
if ( V_6 -> V_7 == V_16 )
return F_3 ( V_6 ) ;
return 0 ;
}
static inline long F_13 ( void )
{
struct V_5 * V_6 = & F_2 ( V_5 ) ;
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
F_19 ( & V_26 -> V_34 , V_22 ) ;
V_4 = F_20 ( V_2 , V_26 , V_7 , NULL ) ;
F_21 ( & V_26 -> V_34 , V_22 ) ;
if ( F_7 ( V_4 == V_35 ) )
goto V_36;
* V_18 = ( V_26 -> V_37 +
( V_4 << V_31 ) ) ;
V_28 = ( void * ) V_24 ;
V_24 = F_6 ( V_24 ) ;
F_22 ( V_22 ) ;
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
F_23 ( V_22 ) ;
return V_28 ;
V_41:
F_24 ( & V_26 -> V_34 ) ;
F_25 ( V_26 , * V_18 , V_7 ) ;
F_21 ( & V_26 -> V_34 , V_22 ) ;
V_36:
F_26 ( V_24 , V_23 ) ;
return NULL ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_17 , void * V_42 ,
T_3 V_43 , struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_26 * V_26 ;
unsigned long V_22 , V_23 , V_7 , V_4 ;
T_5 V_12 ;
V_7 = F_15 ( V_17 ) >> V_31 ;
V_26 = V_2 -> V_10 . V_26 ;
V_9 = V_2 -> V_10 . V_11 ;
V_12 = V_9 -> V_12 ;
V_4 = ( ( V_43 - V_26 -> V_37 ) >> V_31 ) ;
F_19 ( & V_26 -> V_34 , V_22 ) ;
F_25 ( V_26 , V_43 , V_7 ) ;
do {
unsigned long V_14 ;
V_14 = F_28 ( V_12 , F_5 ( 0 , V_4 ) ,
V_7 ) ;
V_4 += V_14 ;
V_7 -= V_14 ;
} while ( V_7 != 0 );
F_21 ( & V_26 -> V_34 , V_22 ) ;
V_23 = F_16 ( V_17 ) ;
if ( V_23 < 10 )
F_26 ( ( unsigned long ) V_42 , V_23 ) ;
}
static T_3 F_29 ( struct V_1 * V_2 , struct V_27 * V_27 ,
unsigned long V_44 , T_2 V_45 ,
enum V_46 V_47 ,
struct V_20 * V_21 )
{
struct V_26 * V_26 ;
unsigned long V_22 , V_7 , V_48 ;
unsigned long V_49 , V_50 ;
T_5 V_51 , V_28 ;
unsigned long V_3 ;
long V_4 ;
V_26 = V_2 -> V_10 . V_26 ;
if ( F_7 ( V_47 == V_52 ) )
goto V_53;
V_48 = ( unsigned long ) ( F_18 ( V_27 ) + V_44 ) ;
V_7 = F_15 ( V_48 + V_45 ) - ( V_48 & V_54 ) ;
V_7 >>= V_31 ;
F_19 ( & V_26 -> V_34 , V_22 ) ;
V_4 = F_20 ( V_2 , V_26 , V_7 , NULL ) ;
F_21 ( & V_26 -> V_34 , V_22 ) ;
if ( F_7 ( V_4 == V_35 ) )
goto V_53;
V_51 = ( V_26 -> V_37 +
( V_4 << V_31 ) ) ;
V_28 = V_51 | ( V_48 & ~ V_54 ) ;
V_50 = F_6 ( V_48 & V_54 ) ;
V_3 = V_38 ;
if ( V_47 != V_55 )
V_3 |= V_39 ;
F_22 ( V_22 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
for ( V_49 = 0 ; V_49 < V_7 ; V_49 ++ , V_50 += V_56 ) {
long V_40 = F_11 ( V_50 ) ;
if ( F_7 ( V_40 < 0L ) )
goto V_41;
}
if ( F_7 ( F_13 () < 0L ) )
goto V_41;
F_23 ( V_22 ) ;
return V_28 ;
V_53:
if ( F_8 () )
F_30 ( 1 ) ;
return V_35 ;
V_41:
F_24 ( & V_26 -> V_34 ) ;
F_25 ( V_26 , V_51 , V_7 ) ;
F_21 ( & V_26 -> V_34 , V_22 ) ;
return V_35 ;
}
static void F_31 ( struct V_1 * V_2 , T_3 V_51 ,
T_2 V_45 , enum V_46 V_47 ,
struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_26 * V_26 ;
unsigned long V_22 , V_7 ;
long V_4 ;
T_5 V_12 ;
if ( F_7 ( V_47 == V_52 ) ) {
if ( F_8 () )
F_30 ( 1 ) ;
return;
}
V_26 = V_2 -> V_10 . V_26 ;
V_9 = V_2 -> V_10 . V_11 ;
V_12 = V_9 -> V_12 ;
V_7 = F_15 ( V_51 + V_45 ) - ( V_51 & V_54 ) ;
V_7 >>= V_31 ;
V_51 &= V_54 ;
F_19 ( & V_26 -> V_34 , V_22 ) ;
F_25 ( V_26 , V_51 , V_7 ) ;
V_4 = ( V_51 - V_26 -> V_37 ) >> V_31 ;
do {
unsigned long V_14 ;
V_14 = F_28 ( V_12 , F_5 ( 0 , V_4 ) ,
V_7 ) ;
V_4 += V_14 ;
V_7 -= V_14 ;
} while ( V_7 != 0 );
F_21 ( & V_26 -> V_34 , V_22 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_57 * V_58 ,
int V_59 , enum V_46 V_47 ,
struct V_20 * V_21 )
{
struct V_57 * V_60 , * V_61 , * V_62 ;
unsigned long V_22 , V_63 , V_3 ;
T_3 V_64 = 0 , V_65 ;
unsigned int V_66 ;
unsigned long V_67 ;
int V_68 , V_69 , V_49 ;
struct V_26 * V_26 ;
unsigned long V_70 ;
long V_40 ;
F_12 ( V_47 == V_52 ) ;
V_26 = V_2 -> V_10 . V_26 ;
if ( V_59 == 0 || ! V_26 )
return 0 ;
V_3 = V_38 ;
if ( V_47 != V_55 )
V_3 |= V_39 ;
V_61 = V_60 = V_62 = & V_58 [ 0 ] ;
V_68 = 1 ;
V_69 = V_59 ;
V_63 = 0 ;
V_61 -> V_71 = 0 ;
F_19 ( & V_26 -> V_34 , V_22 ) ;
F_1 ( V_2 , V_3 , ~ 0UL ) ;
V_66 = F_33 ( V_2 ) ;
V_67 = F_34 ( F_35 ( V_2 ) + 1 ,
V_56 ) >> V_31 ;
V_70 = V_26 -> V_37 >> V_31 ;
F_36 (sglist, s, nelems, i) {
unsigned long V_72 , V_7 , V_4 , V_73 = 0 , V_74 ;
V_74 = V_60 -> V_75 ;
if ( V_74 == 0 ) {
V_64 = 0 ;
continue;
}
V_72 = ( unsigned long ) F_37 ( V_60 ) ;
V_7 = F_38 ( V_72 , V_74 , V_56 ) ;
V_4 = F_20 ( V_2 , V_26 , V_7 , & V_63 ) ;
if ( F_7 ( V_4 == V_35 ) ) {
if ( F_8 () )
F_9 ( V_76 L_4
L_5 , V_26 , V_72 , V_7 ) ;
goto V_77;
}
F_10 ( V_4 ) ;
V_65 = V_26 -> V_37 +
( V_4 << V_31 ) ;
V_65 |= ( V_60 -> V_44 & ~ V_54 ) ;
V_72 &= V_54 ;
while ( V_7 -- ) {
V_40 = F_11 ( V_72 ) ;
if ( F_7 ( V_40 < 0L ) )
goto V_77;
V_72 += V_56 ;
}
if ( V_62 != V_60 ) {
if ( ( V_65 != V_64 ) ||
( V_61 -> V_71 + V_60 -> V_75 > V_66 ) ||
( F_39 ( V_73 , V_70 ,
V_67 , V_61 , V_60 ) ) ) {
V_62 = V_60 ;
V_68 ++ ;
V_61 = F_40 ( V_61 ) ;
} else {
V_61 -> V_71 += V_60 -> V_75 ;
}
}
if ( V_62 == V_60 ) {
V_61 -> V_78 = V_65 ;
V_61 -> V_71 = V_74 ;
V_73 = V_4 ;
}
V_64 = V_65 + V_74 ;
}
V_40 = F_13 () ;
if ( F_7 ( V_40 < 0L ) )
goto V_77;
F_21 ( & V_26 -> V_34 , V_22 ) ;
if ( V_68 < V_69 ) {
V_61 = F_40 ( V_61 ) ;
V_61 -> V_78 = V_35 ;
V_61 -> V_71 = 0 ;
}
return V_68 ;
V_77:
F_36 (sglist, s, nelems, i) {
if ( V_60 -> V_71 != 0 ) {
unsigned long V_79 , V_7 ;
V_79 = V_60 -> V_78 & V_54 ;
V_7 = F_38 ( V_60 -> V_78 , V_60 -> V_71 ,
V_56 ) ;
F_25 ( V_26 , V_79 , V_7 ) ;
V_60 -> V_78 = V_35 ;
V_60 -> V_71 = 0 ;
}
if ( V_60 == V_61 )
break;
}
F_21 ( & V_26 -> V_34 , V_22 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 , struct V_57 * V_58 ,
int V_59 , enum V_46 V_47 ,
struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_57 * V_80 ;
struct V_26 * V_26 ;
unsigned long V_22 ;
T_5 V_12 ;
F_12 ( V_47 == V_52 ) ;
V_26 = V_2 -> V_10 . V_26 ;
V_9 = V_2 -> V_10 . V_11 ;
V_12 = V_9 -> V_12 ;
F_19 ( & V_26 -> V_34 , V_22 ) ;
V_80 = V_58 ;
while ( V_59 -- ) {
T_3 V_81 = V_80 -> V_78 ;
unsigned int V_82 = V_80 -> V_71 ;
unsigned long V_7 , V_4 ;
if ( ! V_82 )
break;
V_7 = F_38 ( V_81 , V_82 , V_56 ) ;
F_25 ( V_26 , V_81 , V_7 ) ;
V_4 = ( ( V_81 - V_26 -> V_37 ) >> V_31 ) ;
while ( V_7 ) {
unsigned long V_14 ;
V_14 = F_28 ( V_12 , F_5 ( 0 , V_4 ) ,
V_7 ) ;
V_4 += V_14 ;
V_7 -= V_14 ;
}
V_80 = F_40 ( V_80 ) ;
}
F_21 ( & V_26 -> V_34 , V_22 ) ;
}
static void T_6 F_42 ( struct V_8 * V_9 ,
struct V_1 * V_83 )
{
struct V_84 * V_85 ;
struct V_86 * V_87 ;
V_87 = V_9 -> V_88 -> V_2 . V_89 ;
V_85 = F_43 ( V_87 , L_6 , NULL ) ;
V_9 -> V_90 = ( V_85 != NULL ) ;
V_9 -> V_91 = F_44 ( V_9 , V_83 ) ;
}
static unsigned long T_6 F_45 ( struct V_8 * V_9 ,
struct V_26 * V_26 )
{
struct V_92 * V_93 = & V_26 -> V_93 ;
unsigned long V_49 , V_94 = 0 ;
T_5 V_12 ;
V_12 = V_9 -> V_12 ;
for ( V_49 = 0 ; V_49 < V_93 -> V_95 ; V_49 ++ ) {
unsigned long V_28 , V_96 , V_97 ;
V_28 = F_46 ( V_12 ,
F_5 ( 0 , V_49 ) ,
& V_96 , & V_97 ) ;
if ( V_28 == V_98 ) {
if ( F_47 ( V_97 ) ) {
F_28 ( V_12 ,
F_5 ( 0 , V_49 ) , 1 ) ;
} else {
V_94 ++ ;
F_48 ( V_49 , V_93 -> V_99 ) ;
}
}
}
return V_94 ;
}
static int T_6 F_49 ( struct V_8 * V_9 )
{
static const T_5 V_100 [] = { 0x80000000 , 0x80000000 } ;
struct V_26 * V_26 = V_9 -> V_26 ;
unsigned long V_101 , V_45 ;
T_5 V_102 , V_103 ;
const T_5 * V_104 ;
V_104 = F_50 ( V_9 -> V_88 -> V_2 . V_89 , L_7 , NULL ) ;
if ( ! V_104 )
V_104 = V_100 ;
if ( ( V_104 [ 0 ] | V_104 [ 1 ] ) & ~ V_54 ) {
F_9 (KERN_ERR PFX L_8 ,
vdma[0], vdma[1]) ;
return - V_105 ;
} ;
V_102 = ( F_51 ( V_104 [ 1 ] ) - 1UL ) ;
V_101 = V_104 [ 1 ] / V_56 ;
V_103 = V_104 [ 0 ] ;
F_52 ( & V_26 -> V_34 ) ;
V_26 -> V_106 = 1 ;
V_26 -> V_37 = V_103 ;
V_26 -> V_107 = V_102 ;
V_45 = ( V_101 + 7 ) / 8 ;
V_45 = ( V_45 + 7UL ) & ~ 7UL ;
V_26 -> V_93 . V_99 = F_53 ( V_45 , V_108 ) ;
if ( ! V_26 -> V_93 . V_99 ) {
F_9 (KERN_ERR PFX L_9 ) ;
return - V_109 ;
}
V_26 -> V_93 . V_95 = V_101 ;
V_45 = F_45 ( V_9 , V_26 ) ;
if ( V_45 )
F_9 ( L_10 ,
V_9 -> V_110 , V_45 ) ;
return 0 ;
}
static int F_54 ( struct V_8 * V_9 , unsigned long V_111 ,
unsigned long * V_112 )
{
unsigned long V_40 , V_95 ;
V_40 = F_55 ( V_9 -> V_12 , V_111 , V_112 ) ;
if ( F_7 ( V_40 ) )
return - V_113 ;
V_95 = V_9 -> V_114 * sizeof( struct V_115 ) ;
if ( F_7 ( * V_112 >= V_95 ) )
return - V_116 ;
return 0 ;
}
static int F_56 ( struct V_8 * V_9 ,
unsigned long V_111 , unsigned long * V_112 ,
unsigned long * V_117 )
{
struct V_115 * V_118 ;
unsigned long V_40 , type ;
V_118 = ( V_9 -> V_119 + ( ( V_111 - V_9 -> V_120 ) *
( V_9 -> V_114 *
sizeof( struct V_115 ) ) ) +
* V_112 ) ;
if ( ( V_118 -> V_121 & V_122 ) == 0 )
return 0 ;
type = ( V_118 -> V_121 & V_122 ) >> V_123 ;
if ( F_7 ( type != V_124 &&
type != V_125 ) )
return - V_105 ;
* V_117 = V_118 -> V_126 ;
V_40 = F_57 ( V_9 -> V_12 ,
V_118 -> V_126 ,
V_127 ) ;
if ( F_7 ( V_40 ) )
return - V_113 ;
V_118 -> V_121 &= ~ V_122 ;
( * V_112 ) += sizeof( struct V_115 ) ;
if ( * V_112 >=
( V_9 -> V_114 * sizeof( struct V_115 ) ) )
* V_112 = 0 ;
return 1 ;
}
static int F_58 ( struct V_8 * V_9 , unsigned long V_111 ,
unsigned long V_112 )
{
unsigned long V_40 ;
V_40 = F_59 ( V_9 -> V_12 , V_111 , V_112 ) ;
if ( F_7 ( V_40 ) )
return - V_105 ;
return 0 ;
}
static int F_60 ( struct V_8 * V_9 , unsigned long V_111 ,
unsigned long V_117 , int V_128 )
{
if ( F_61 ( V_9 -> V_12 , V_117 , V_111 ,
( V_128 ?
V_129 : V_130 ) ) )
return - V_113 ;
if ( F_57 ( V_9 -> V_12 , V_117 , V_127 ) )
return - V_113 ;
if ( F_62 ( V_9 -> V_12 , V_117 , V_131 ) )
return - V_113 ;
return 0 ;
}
static int F_63 ( struct V_8 * V_9 , unsigned long V_117 )
{
unsigned long V_40 , V_111 ;
V_40 = F_64 ( V_9 -> V_12 , V_117 , & V_111 ) ;
if ( V_40 )
return - V_113 ;
F_62 ( V_9 -> V_12 , V_117 , V_132 ) ;
return 0 ;
}
static int F_65 ( struct V_8 * V_9 )
{
unsigned long V_133 , V_134 , V_135 , V_23 ;
int V_49 ;
V_133 = V_9 -> V_114 * sizeof( struct V_115 ) ;
V_134 = ( V_9 -> V_136 * V_133 ) ;
V_23 = F_16 ( V_134 ) ;
V_135 = F_66 ( V_108 | V_137 , V_23 ) ;
if ( V_135 == 0UL ) {
F_9 ( V_138 L_11 ,
V_23 ) ;
return - V_109 ;
}
memset ( ( char * ) V_135 , 0 , V_33 << V_23 ) ;
V_9 -> V_119 = ( void * ) V_135 ;
for ( V_49 = 0 ; V_49 < V_9 -> V_136 ; V_49 ++ ) {
unsigned long V_40 , V_139 = F_6 ( V_135 + ( V_49 * V_133 ) ) ;
unsigned long V_140 , V_141 ;
V_40 = F_67 ( V_9 -> V_12 ,
V_9 -> V_120 + V_49 ,
V_139 , V_9 -> V_114 ) ;
if ( V_40 ) {
F_9 ( V_138 L_12 ,
V_40 ) ;
goto V_142;
}
V_40 = F_68 ( V_9 -> V_12 ,
V_9 -> V_120 + V_49 ,
& V_140 , & V_141 ) ;
if ( V_40 ) {
F_9 ( V_138 L_13 ,
V_40 ) ;
goto V_142;
}
if ( V_140 != V_139 || V_141 != V_9 -> V_114 ) {
F_9 ( V_138 L_14
L_15 ,
V_139 , V_9 -> V_114 ,
V_140 , V_141 ) ;
goto V_142;
}
}
return 0 ;
V_142:
F_26 ( V_135 , V_23 ) ;
return - V_105 ;
}
static void F_69 ( struct V_8 * V_9 )
{
unsigned long V_133 , V_134 , V_135 , V_23 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_9 -> V_136 ; V_49 ++ ) {
unsigned long V_111 = V_9 -> V_120 + V_49 ;
( void ) F_67 ( V_9 -> V_12 , V_111 , 0UL , 0 ) ;
}
V_133 = V_9 -> V_114 * sizeof( struct V_115 ) ;
V_134 = ( V_9 -> V_136 * V_133 ) ;
V_23 = F_16 ( V_134 ) ;
V_135 = ( unsigned long ) V_9 -> V_119 ;
F_26 ( V_135 , V_23 ) ;
V_9 -> V_119 = NULL ;
}
static int F_70 ( struct V_8 * V_9 ,
unsigned long V_111 ,
unsigned long V_143 )
{
unsigned int V_144 = F_71 ( V_9 -> V_12 , V_143 ) ;
if ( ! V_144 )
return - V_109 ;
if ( F_72 ( V_9 -> V_12 , V_111 , V_145 ) )
return - V_105 ;
if ( F_73 ( V_9 -> V_12 , V_111 , V_146 ) )
return - V_105 ;
return V_144 ;
}
static void F_74 ( struct V_8 * V_9 )
{
F_75 ( V_9 , & V_147 ) ;
}
static void F_74 ( struct V_8 * V_9 )
{
}
static int T_6 F_76 ( struct V_8 * V_9 ,
struct V_148 * V_88 , T_5 V_12 )
{
struct V_86 * V_87 = V_88 -> V_2 . V_89 ;
int V_40 ;
V_9 -> V_32 = F_77 ( V_87 ) ;
V_9 -> V_149 = & V_150 ;
V_9 -> V_151 = 12 ;
V_9 -> V_152 = V_153 ++ ;
V_9 -> V_88 = V_88 ;
V_9 -> V_12 = V_12 ;
V_9 -> V_110 = V_87 -> V_154 ;
F_9 ( L_16 , V_9 -> V_110 ) ;
F_9 ( L_17 , V_9 -> V_110 , V_9 -> V_32 ) ;
F_78 ( V_9 ) ;
F_79 ( V_9 ) ;
V_40 = F_49 ( V_9 ) ;
if ( V_40 )
return V_40 ;
F_74 ( V_9 ) ;
F_42 ( V_9 , & V_88 -> V_2 ) ;
V_9 -> V_155 = V_156 ;
V_156 = V_9 ;
return 0 ;
}
static int T_6 F_80 ( struct V_148 * V_88 )
{
const struct V_157 * V_158 ;
static int V_159 = 0 ;
struct V_8 * V_9 ;
struct V_86 * V_87 ;
struct V_26 * V_26 ;
T_5 V_12 ;
int V_49 , V_40 ;
V_87 = V_88 -> V_2 . V_89 ;
if ( ! V_159 ++ ) {
V_40 = F_81 ( V_160 ,
V_161 ,
& V_162 ) ;
if ( V_40 ) {
F_9 (KERN_ERR PFX L_18
L_19 , err) ;
return V_40 ;
}
F_9 (KERN_INFO PFX L_20 ,
vpci_major, vpci_minor) ;
V_163 = & V_164 ;
}
V_158 = F_50 ( V_87 , L_21 , NULL ) ;
V_40 = - V_165 ;
if ( ! V_158 ) {
F_9 (KERN_ERR PFX L_22 ) ;
goto V_166;
}
V_12 = ( V_158 -> V_167 >> 32UL ) & 0x0fffffff ;
V_40 = - V_109 ;
if ( ! V_168 ) {
F_82 (i) {
unsigned long V_27 = F_83 ( V_108 ) ;
if ( ! V_27 )
goto V_166;
F_84 ( V_5 , V_49 ) . V_13 = ( T_1 * ) V_27 ;
}
V_168 = 1 ;
}
V_9 = F_53 ( sizeof( * V_9 ) , V_108 ) ;
if ( ! V_9 ) {
F_9 (KERN_ERR PFX L_23 ) ;
goto V_166;
}
V_26 = F_53 ( sizeof( struct V_26 ) , V_108 ) ;
if ( ! V_26 ) {
F_9 (KERN_ERR PFX L_24 ) ;
goto V_169;
}
V_9 -> V_26 = V_26 ;
V_40 = F_76 ( V_9 , V_88 , V_12 ) ;
if ( V_40 )
goto V_170;
F_85 ( & V_88 -> V_2 , V_9 ) ;
return 0 ;
V_170:
F_86 ( V_9 -> V_26 ) ;
V_169:
F_86 ( V_9 ) ;
V_166:
return V_40 ;
}
static int T_7 F_87 ( void )
{
return F_88 ( & V_171 ) ;
}
