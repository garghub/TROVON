static void F_1 ( unsigned long * V_1 )
{
int V_2 ;
int V_3 ;
memset ( V_1 , 0 , V_4 * sizeof( unsigned long ) ) ;
F_2 (cpu) {
struct V_5 * V_6 = & F_3 ( V_7 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ )
V_1 [ V_3 ] += V_6 -> V_8 [ V_3 ] ;
}
}
void F_4 ( unsigned long * V_1 )
{
F_5 () ;
F_1 ( V_1 ) ;
F_6 () ;
}
void F_7 ( int V_2 )
{
struct V_5 * V_9 = & F_3 ( V_7 , V_2 ) ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_8 ( V_3 , V_9 -> V_8 [ V_3 ] ) ;
V_9 -> V_8 [ V_3 ] = 0 ;
}
}
int F_9 ( struct V_10 * V_10 )
{
int V_11 ;
int V_12 ;
V_12 = F_10 ( V_10 ) - F_11 ( V_10 ) ;
V_11 = F_12 ( 1 , ( int ) ( V_12 / F_13 () ) ) ;
V_11 = F_14 ( 125 , V_11 ) ;
return V_11 ;
}
int F_15 ( struct V_10 * V_10 )
{
int V_11 ;
int V_13 ;
V_13 = V_10 -> V_14 >> ( 27 - V_15 ) ;
V_11 = 2 * F_16 ( F_13 () ) * ( 1 + F_16 ( V_13 ) ) ;
V_11 = F_14 ( 125 , V_11 ) ;
return V_11 ;
}
void F_17 ( void )
{
struct V_10 * V_10 ;
int V_2 ;
int V_11 ;
F_18 (zone) {
unsigned long V_16 , V_17 ;
V_11 = F_15 ( V_10 ) ;
F_2 (cpu)
F_19 ( V_10 -> V_18 , V_2 ) -> V_19
= V_11 ;
V_17 = F_10 ( V_10 ) - F_11 ( V_10 ) ;
V_16 = F_13 () * V_11 ;
if ( V_16 > V_17 )
V_10 -> V_20 = F_20 ( V_10 ) +
V_16 ;
}
}
void F_21 ( T_1 * V_21 ,
int (* F_22)( struct V_10 * ) )
{
struct V_10 * V_10 ;
int V_2 ;
int V_11 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_21 -> V_22 ; V_3 ++ ) {
V_10 = & V_21 -> V_23 [ V_3 ] ;
if ( ! V_10 -> V_20 )
continue;
V_11 = (* F_22)( V_10 ) ;
F_2 (cpu)
F_19 ( V_10 -> V_18 , V_2 ) -> V_19
= V_11 ;
}
}
void F_23 ( struct V_10 * V_10 , enum V_24 V_25 ,
int V_26 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
long V_31 ;
long V_32 ;
V_31 = V_26 + F_24 ( * V_29 ) ;
V_32 = F_24 ( V_28 -> V_19 ) ;
if ( F_25 ( V_31 > V_32 || V_31 < - V_32 ) ) {
F_26 ( V_31 , V_10 , V_25 ) ;
V_31 = 0 ;
}
F_27 ( * V_29 , V_31 ) ;
}
void F_28 ( struct V_10 * V_10 , enum V_24 V_25 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
T_3 V_33 , V_32 ;
V_33 = F_29 ( * V_29 ) ;
V_32 = F_24 ( V_28 -> V_19 ) ;
if ( F_25 ( V_33 > V_32 ) ) {
T_3 V_34 = V_32 >> 1 ;
F_26 ( V_33 + V_34 , V_10 , V_25 ) ;
F_27 ( * V_29 , - V_34 ) ;
}
}
void F_30 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_28 ( F_31 ( V_35 ) , V_25 ) ;
}
void F_32 ( struct V_10 * V_10 , enum V_24 V_25 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
T_3 V_33 , V_32 ;
V_33 = F_33 ( * V_29 ) ;
V_32 = F_24 ( V_28 -> V_19 ) ;
if ( F_25 ( V_33 < - V_32 ) ) {
T_3 V_34 = V_32 >> 1 ;
F_26 ( V_33 - V_34 , V_10 , V_25 ) ;
F_27 ( * V_29 , V_34 ) ;
}
}
void F_34 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_32 ( F_31 ( V_35 ) , V_25 ) ;
}
static inline void F_35 ( struct V_10 * V_10 ,
enum V_24 V_25 , int V_26 , int V_36 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
long V_37 , V_38 , V_32 , V_39 ;
do {
V_39 = 0 ;
V_32 = F_36 ( V_28 -> V_19 ) ;
V_37 = F_36 ( * V_29 ) ;
V_38 = V_26 + V_37 ;
if ( V_38 > V_32 || V_38 < - V_32 ) {
int V_40 = V_36 * ( V_32 >> 1 ) ;
V_39 = V_38 + V_40 ;
V_38 = - V_40 ;
}
} while ( F_37 ( * V_29 , V_37 , V_38 ) != V_37 );
if ( V_39 )
F_26 ( V_39 , V_10 , V_25 ) ;
}
void F_38 ( struct V_10 * V_10 , enum V_24 V_25 ,
int V_26 )
{
F_35 ( V_10 , V_25 , V_26 , 0 ) ;
}
void F_39 ( struct V_10 * V_10 , enum V_24 V_25 )
{
F_35 ( V_10 , V_25 , 1 , 1 ) ;
}
void F_40 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_35 ( F_31 ( V_35 ) , V_25 , 1 , 1 ) ;
}
void F_41 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_35 ( F_31 ( V_35 ) , V_25 , - 1 , - 1 ) ;
}
void F_38 ( struct V_10 * V_10 , enum V_24 V_25 ,
int V_26 )
{
unsigned long V_41 ;
F_42 ( V_41 ) ;
F_23 ( V_10 , V_25 , V_26 ) ;
F_43 ( V_41 ) ;
}
void F_39 ( struct V_10 * V_10 , enum V_24 V_25 )
{
unsigned long V_41 ;
F_42 ( V_41 ) ;
F_28 ( V_10 , V_25 ) ;
F_43 ( V_41 ) ;
}
void F_40 ( struct V_35 * V_35 , enum V_24 V_25 )
{
unsigned long V_41 ;
struct V_10 * V_10 ;
V_10 = F_31 ( V_35 ) ;
F_42 ( V_41 ) ;
F_28 ( V_10 , V_25 ) ;
F_43 ( V_41 ) ;
}
void F_41 ( struct V_35 * V_35 , enum V_24 V_25 )
{
unsigned long V_41 ;
F_42 ( V_41 ) ;
F_34 ( V_35 , V_25 ) ;
F_43 ( V_41 ) ;
}
static int F_44 ( int * V_42 )
{
int V_3 ;
int V_43 = 0 ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
if ( V_42 [ V_3 ] ) {
F_45 ( V_42 [ V_3 ] , & V_45 [ V_3 ] ) ;
V_43 ++ ;
}
return V_43 ;
}
static int F_46 ( void )
{
struct V_10 * V_10 ;
int V_3 ;
int V_46 [ V_44 ] = { 0 , } ;
int V_43 = 0 ;
F_18 (zone) {
struct V_27 T_2 * V_29 = V_10 -> V_18 ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ ) {
int V_33 ;
V_33 = F_47 ( V_29 -> V_30 [ V_3 ] , 0 ) ;
if ( V_33 ) {
F_45 ( V_33 , & V_10 -> V_45 [ V_3 ] ) ;
V_46 [ V_3 ] += V_33 ;
#ifdef F_48
F_27 ( V_29 -> V_47 , 3 ) ;
#endif
}
}
F_49 () ;
#ifdef F_48
if ( ! F_24 ( V_29 -> V_47 ) ||
! F_24 ( V_29 -> V_28 . V_48 ) )
continue;
if ( F_50 ( V_10 ) == F_51 () ) {
F_27 ( V_29 -> V_47 , 0 ) ;
continue;
}
if ( F_33 ( V_29 -> V_47 ) )
continue;
if ( F_24 ( V_29 -> V_28 . V_48 ) ) {
F_52 ( V_10 , F_53 ( & V_29 -> V_28 ) ) ;
V_43 ++ ;
}
#endif
}
V_43 += F_44 ( V_46 ) ;
return V_43 ;
}
void F_54 ( int V_2 )
{
struct V_10 * V_10 ;
int V_3 ;
int V_46 [ V_44 ] = { 0 , } ;
F_18 (zone) {
struct V_27 * V_29 ;
V_29 = F_19 ( V_10 -> V_18 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
if ( V_29 -> V_30 [ V_3 ] ) {
int V_33 ;
V_33 = V_29 -> V_30 [ V_3 ] ;
V_29 -> V_30 [ V_3 ] = 0 ;
F_45 ( V_33 , & V_10 -> V_45 [ V_3 ] ) ;
V_46 [ V_3 ] += V_33 ;
}
}
F_44 ( V_46 ) ;
}
void F_55 ( struct V_10 * V_10 , struct V_27 * V_49 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
if ( V_49 -> V_30 [ V_3 ] ) {
int V_33 = V_49 -> V_30 [ V_3 ] ;
V_49 -> V_30 [ V_3 ] = 0 ;
F_45 ( V_33 , & V_10 -> V_45 [ V_3 ] ) ;
F_45 ( V_33 , & V_45 [ V_3 ] ) ;
}
}
void F_56 ( struct V_10 * V_50 , struct V_10 * V_39 , T_4 V_41 )
{
if ( V_39 -> V_51 == V_50 -> V_51 ) {
F_28 ( V_39 , V_52 ) ;
} else {
F_28 ( V_39 , V_53 ) ;
F_28 ( V_50 , V_54 ) ;
}
if ( V_39 -> V_55 == ( ( V_41 & V_56 ) ?
V_50 -> V_55 : F_51 () ) )
F_28 ( V_39 , V_57 ) ;
else
F_28 ( V_39 , V_58 ) ;
}
static void F_57 ( struct V_10 * V_10 ,
unsigned int V_59 ,
struct V_60 * V_61 )
{
unsigned int V_62 ;
V_61 -> V_63 = 0 ;
V_61 -> V_64 = 0 ;
V_61 -> V_65 = 0 ;
for ( V_62 = 0 ; V_62 < V_66 ; V_62 ++ ) {
unsigned long V_67 ;
V_67 = V_10 -> V_68 [ V_62 ] . V_69 ;
V_61 -> V_64 += V_67 ;
V_61 -> V_63 += V_67 << V_62 ;
if ( V_62 >= V_59 )
V_61 -> V_65 += V_67 <<
( V_62 - V_59 ) ;
}
}
static int F_58 ( unsigned int V_62 , struct V_60 * V_61 )
{
unsigned long V_70 = 1UL << V_62 ;
if ( ! V_61 -> V_64 )
return 0 ;
if ( V_61 -> V_65 )
return - 1000 ;
return 1000 - F_59 ( ( 1000 + ( F_59 ( V_61 -> V_63 * 1000ULL , V_70 ) ) ) , V_61 -> V_64 ) ;
}
int F_60 ( struct V_10 * V_10 , unsigned int V_62 )
{
struct V_60 V_61 ;
F_57 ( V_10 , V_62 , & V_61 ) ;
return F_58 ( V_62 , & V_61 ) ;
}
static void * F_61 ( struct V_71 * V_72 , T_5 * V_73 )
{
T_1 * V_21 ;
T_5 V_55 = * V_73 ;
for ( V_21 = F_62 () ;
V_21 && V_55 ;
V_21 = F_63 ( V_21 ) )
-- V_55 ;
return V_21 ;
}
static void * F_64 ( struct V_71 * V_72 , void * V_74 , T_5 * V_73 )
{
T_1 * V_21 = ( T_1 * ) V_74 ;
( * V_73 ) ++ ;
return F_63 ( V_21 ) ;
}
static void F_65 ( struct V_71 * V_72 , void * V_74 )
{
}
static void F_66 ( struct V_71 * V_72 , T_1 * V_21 ,
void (* F_67)( struct V_71 * V_72 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_23 = V_21 -> V_23 ;
unsigned long V_41 ;
for ( V_10 = V_23 ; V_10 - V_23 < V_75 ; ++ V_10 ) {
if ( ! F_68 ( V_10 ) )
continue;
F_69 ( & V_10 -> V_76 , V_41 ) ;
F_67 ( V_72 , V_21 , V_10 ) ;
F_70 ( & V_10 -> V_76 , V_41 ) ;
}
}
static void F_71 ( struct V_71 * V_72 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_62 ;
F_72 ( V_72 , L_1 , V_21 -> V_77 , V_10 -> V_78 ) ;
for ( V_62 = 0 ; V_62 < V_66 ; ++ V_62 )
F_72 ( V_72 , L_2 , V_10 -> V_68 [ V_62 ] . V_69 ) ;
F_73 ( V_72 , '\n' ) ;
}
static int F_74 ( struct V_71 * V_72 , void * V_74 )
{
T_1 * V_21 = ( T_1 * ) V_74 ;
F_66 ( V_72 , V_21 , F_71 ) ;
return 0 ;
}
static void F_75 ( struct V_71 * V_72 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_62 , V_79 ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ ) {
F_72 ( V_72 , L_3 ,
V_21 -> V_77 ,
V_10 -> V_78 ,
V_81 [ V_79 ] ) ;
for ( V_62 = 0 ; V_62 < V_66 ; ++ V_62 ) {
unsigned long V_82 = 0 ;
struct V_68 * V_83 ;
struct V_84 * V_85 ;
V_83 = & ( V_10 -> V_68 [ V_62 ] ) ;
F_76 (curr, &area->free_list[mtype])
V_82 ++ ;
F_72 ( V_72 , L_2 , V_82 ) ;
}
F_73 ( V_72 , '\n' ) ;
}
}
static int F_77 ( struct V_71 * V_72 , void * V_74 )
{
int V_62 ;
T_1 * V_21 = ( T_1 * ) V_74 ;
F_72 ( V_72 , L_4 , L_5 ) ;
for ( V_62 = 0 ; V_62 < V_66 ; ++ V_62 )
F_72 ( V_72 , L_6 , V_62 ) ;
F_73 ( V_72 , '\n' ) ;
F_66 ( V_72 , V_21 , F_75 ) ;
return 0 ;
}
static void F_78 ( struct V_71 * V_72 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_79 ;
unsigned long V_86 ;
unsigned long V_87 = V_10 -> V_88 ;
unsigned long V_89 = F_79 ( V_10 ) ;
unsigned long V_48 [ V_80 ] = { 0 , } ;
for ( V_86 = V_87 ; V_86 < V_89 ; V_86 += V_90 ) {
struct V_35 * V_35 ;
if ( ! F_80 ( V_86 ) )
continue;
V_35 = F_81 ( V_86 ) ;
if ( ! F_82 ( V_86 , V_35 , V_10 ) )
continue;
V_79 = F_83 ( V_35 ) ;
if ( V_79 < V_80 )
V_48 [ V_79 ] ++ ;
}
F_72 ( V_72 , L_1 , V_21 -> V_77 , V_10 -> V_78 ) ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ )
F_72 ( V_72 , L_7 , V_48 [ V_79 ] ) ;
F_73 ( V_72 , '\n' ) ;
}
static int F_84 ( struct V_71 * V_72 , void * V_74 )
{
int V_79 ;
T_1 * V_21 = ( T_1 * ) V_74 ;
F_72 ( V_72 , L_8 , L_9 ) ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ )
F_72 ( V_72 , L_10 , V_81 [ V_79 ] ) ;
F_73 ( V_72 , '\n' ) ;
F_66 ( V_72 , V_21 , F_78 ) ;
return 0 ;
}
static int F_85 ( struct V_71 * V_72 , void * V_74 )
{
T_1 * V_21 = ( T_1 * ) V_74 ;
if ( ! F_86 ( V_21 -> V_77 , V_91 ) )
return 0 ;
F_72 ( V_72 , L_11 , V_92 ) ;
F_72 ( V_72 , L_12 , V_90 ) ;
F_73 ( V_72 , '\n' ) ;
F_77 ( V_72 , V_21 ) ;
F_84 ( V_72 , V_21 ) ;
return 0 ;
}
static int F_87 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
return F_88 ( V_94 , & V_95 ) ;
}
static int F_89 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
return F_88 ( V_94 , & V_96 ) ;
}
static void F_90 ( struct V_71 * V_72 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_3 ;
F_72 ( V_72 , L_13 , V_21 -> V_77 , V_10 -> V_78 ) ;
F_72 ( V_72 ,
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21 ,
F_91 ( V_10 , V_97 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_20 ( V_10 ) ,
F_91 ( V_10 , V_98 ) ,
V_10 -> V_99 ,
V_10 -> V_100 ,
V_10 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
F_72 ( V_72 , L_22 , V_101 [ V_3 ] ,
F_91 ( V_10 , V_3 ) ) ;
F_72 ( V_72 ,
L_23 ,
V_10 -> V_102 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_92 ( V_10 -> V_102 ) ; V_3 ++ )
F_72 ( V_72 , L_24 , V_10 -> V_102 [ V_3 ] ) ;
F_72 ( V_72 ,
L_25
L_26 ) ;
F_2 (i) {
struct V_27 * V_18 ;
V_18 = F_19 ( V_10 -> V_18 , V_3 ) ;
F_72 ( V_72 ,
L_27
L_28
L_29
L_30 ,
V_3 ,
V_18 -> V_28 . V_48 ,
V_18 -> V_28 . V_103 ,
V_18 -> V_28 . V_104 ) ;
#ifdef F_93
F_72 ( V_72 , L_31 ,
V_18 -> V_19 ) ;
#endif
}
F_72 ( V_72 ,
L_32
L_33
L_34 ,
! F_94 ( V_10 ) ,
V_10 -> V_88 ,
V_10 -> V_105 ) ;
F_73 ( V_72 , '\n' ) ;
}
static int F_95 ( struct V_71 * V_72 , void * V_74 )
{
T_1 * V_21 = ( T_1 * ) V_74 ;
F_66 ( V_72 , V_21 , F_90 ) ;
return 0 ;
}
static int F_96 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
return F_88 ( V_94 , & V_106 ) ;
}
static void * F_97 ( struct V_71 * V_72 , T_5 * V_73 )
{
unsigned long * V_33 ;
int V_3 , V_107 ;
if ( * V_73 >= F_92 ( V_101 ) )
return NULL ;
V_107 = V_44 * sizeof( unsigned long ) +
V_108 * sizeof( unsigned long ) ;
#ifdef F_98
V_107 += sizeof( struct V_5 ) ;
#endif
V_33 = F_99 ( V_107 , V_109 ) ;
V_72 -> V_110 = V_33 ;
if ( ! V_33 )
return F_100 ( - V_111 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
V_33 [ V_3 ] = F_101 ( V_3 ) ;
V_33 += V_44 ;
F_102 ( V_33 + V_112 ,
V_33 + V_113 ) ;
V_33 += V_108 ;
#ifdef F_98
F_4 ( V_33 ) ;
V_33 [ V_114 ] /= 2 ;
V_33 [ V_115 ] /= 2 ;
#endif
return ( unsigned long * ) V_72 -> V_110 + * V_73 ;
}
static void * F_103 ( struct V_71 * V_72 , void * V_74 , T_5 * V_73 )
{
( * V_73 ) ++ ;
if ( * V_73 >= F_92 ( V_101 ) )
return NULL ;
return ( unsigned long * ) V_72 -> V_110 + * V_73 ;
}
static int F_104 ( struct V_71 * V_72 , void * V_74 )
{
unsigned long * V_116 = V_74 ;
unsigned long V_117 = V_116 - ( unsigned long * ) V_72 -> V_110 ;
F_72 ( V_72 , L_35 , V_101 [ V_117 ] , * V_116 ) ;
return 0 ;
}
static void F_105 ( struct V_71 * V_72 , void * V_74 )
{
F_106 ( V_72 -> V_110 ) ;
V_72 -> V_110 = NULL ;
}
static int F_107 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
return F_88 ( V_94 , & V_118 ) ;
}
static void F_108 ( struct V_119 * V_120 )
{
if ( F_46 () )
F_109 ( F_53 ( & V_121 ) ,
F_110 ( V_122 ) ) ;
else {
int V_123 ;
V_123 = F_111 ( F_112 () ,
V_124 ) ;
F_113 ( V_123 ) ;
}
}
static bool F_114 ( int V_2 )
{
struct V_10 * V_10 ;
F_18 (zone) {
struct V_27 * V_29 = F_19 ( V_10 -> V_18 , V_2 ) ;
F_115 ( sizeof( V_29 -> V_30 [ 0 ] ) != 1 ) ;
if ( F_116 ( V_29 -> V_30 , 0 , V_44 ) )
return true ;
}
return false ;
}
static void F_117 ( struct V_119 * V_120 )
{
int V_2 ;
F_5 () ;
F_118 (cpu, cpu_stat_off)
if ( F_114 ( V_2 ) &&
F_119 ( V_2 , V_124 ) )
F_120 ( V_2 , & F_3 ( V_121 , V_2 ) ,
F_121 ( V_122 , V_2 ) ) ;
F_6 () ;
F_109 ( & V_125 ,
F_110 ( V_122 ) ) ;
}
static void T_6 F_122 ( void )
{
int V_2 ;
F_123 (cpu)
F_124 ( F_19 ( & V_121 , V_2 ) ,
F_108 ) ;
if ( ! F_125 ( & V_124 , V_109 ) )
F_126 () ;
F_127 ( V_124 , V_126 ) ;
F_109 ( & V_125 ,
F_110 ( V_122 ) ) ;
}
static void F_128 ( int V_55 )
{
int V_2 ;
F_5 () ;
F_2 (cpu)
if ( F_129 ( V_2 ) == V_55 )
goto V_127;
F_130 ( V_55 , V_128 ) ;
V_127:
F_6 () ;
}
static int F_131 ( struct V_129 * V_130 ,
unsigned long V_131 ,
void * V_132 )
{
long V_2 = ( long ) V_132 ;
switch ( V_131 ) {
case V_133 :
case V_134 :
F_17 () ;
F_132 ( F_129 ( V_2 ) , V_128 ) ;
F_133 ( V_2 , V_124 ) ;
break;
case V_135 :
case V_136 :
F_134 ( & F_3 ( V_121 , V_2 ) ) ;
F_135 ( V_2 , V_124 ) ;
break;
case V_137 :
case V_138 :
F_133 ( V_2 , V_124 ) ;
break;
case V_139 :
case V_140 :
F_17 () ;
F_128 ( F_129 ( V_2 ) ) ;
break;
default:
break;
}
return V_141 ;
}
static int T_6 F_136 ( void )
{
#ifdef F_93
F_137 () ;
F_138 ( & V_142 ) ;
F_122 () ;
F_139 () ;
#endif
#ifdef F_140
F_141 ( L_36 , V_143 , NULL , & V_144 ) ;
F_141 ( L_37 , V_143 , NULL , & V_145 ) ;
F_141 ( L_38 , V_143 , NULL , & V_146 ) ;
F_141 ( L_39 , V_143 , NULL , & V_147 ) ;
#endif
return 0 ;
}
static int F_142 ( unsigned int V_62 ,
struct V_60 * V_61 )
{
if ( V_61 -> V_63 == 0 )
return 1000 ;
return F_59 ( ( V_61 -> V_63 - ( V_61 -> V_65 << V_62 ) ) * 1000ULL , V_61 -> V_63 ) ;
}
static void F_143 ( struct V_71 * V_72 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_62 ;
int V_148 ;
struct V_60 V_61 ;
F_72 ( V_72 , L_1 ,
V_21 -> V_77 ,
V_10 -> V_78 ) ;
for ( V_62 = 0 ; V_62 < V_66 ; ++ V_62 ) {
F_57 ( V_10 , V_62 , & V_61 ) ;
V_148 = F_142 ( V_62 , & V_61 ) ;
F_72 ( V_72 , L_40 , V_148 / 1000 , V_148 % 1000 ) ;
}
F_73 ( V_72 , '\n' ) ;
}
static int F_144 ( struct V_71 * V_72 , void * V_74 )
{
T_1 * V_21 = ( T_1 * ) V_74 ;
if ( ! F_86 ( V_21 -> V_77 , V_91 ) )
return 0 ;
F_66 ( V_72 , V_21 , F_143 ) ;
return 0 ;
}
static int F_145 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
return F_88 ( V_94 , & V_149 ) ;
}
static void F_146 ( struct V_71 * V_72 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_62 ;
int V_148 ;
struct V_60 V_61 ;
F_72 ( V_72 , L_1 ,
V_21 -> V_77 ,
V_10 -> V_78 ) ;
for ( V_62 = 0 ; V_62 < V_66 ; ++ V_62 ) {
F_57 ( V_10 , V_62 , & V_61 ) ;
V_148 = F_58 ( V_62 , & V_61 ) ;
F_72 ( V_72 , L_40 , V_148 / 1000 , V_148 % 1000 ) ;
}
F_73 ( V_72 , '\n' ) ;
}
static int F_147 ( struct V_71 * V_72 , void * V_74 )
{
T_1 * V_21 = ( T_1 * ) V_74 ;
F_66 ( V_72 , V_21 , F_146 ) ;
return 0 ;
}
static int F_148 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
return F_88 ( V_94 , & V_150 ) ;
}
static int T_6 F_149 ( void )
{
struct V_151 * V_152 ;
V_152 = F_150 ( L_41 , NULL ) ;
if ( ! V_152 )
return - V_111 ;
if ( ! F_151 ( L_42 , 0444 ,
V_152 , NULL , & V_153 ) )
goto V_154;
if ( ! F_151 ( L_43 , 0444 ,
V_152 , NULL , & V_155 ) )
goto V_154;
return 0 ;
V_154:
F_152 ( V_152 ) ;
return - V_111 ;
}
