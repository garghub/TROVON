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
F_23 (cpu)
F_19 ( V_10 -> V_18 , V_2 ) -> V_19
= V_11 ;
}
}
void F_24 ( struct V_10 * V_10 , enum V_24 V_25 ,
int V_26 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
long V_31 ;
long V_32 ;
V_31 = V_26 + F_25 ( * V_29 ) ;
V_32 = F_25 ( V_28 -> V_19 ) ;
if ( F_26 ( V_31 > V_32 || V_31 < - V_32 ) ) {
F_27 ( V_31 , V_10 , V_25 ) ;
V_31 = 0 ;
}
F_28 ( * V_29 , V_31 ) ;
}
void F_29 ( struct V_10 * V_10 , enum V_24 V_25 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
T_3 V_33 , V_32 ;
V_33 = F_30 ( * V_29 ) ;
V_32 = F_25 ( V_28 -> V_19 ) ;
if ( F_26 ( V_33 > V_32 ) ) {
T_3 V_34 = V_32 >> 1 ;
F_27 ( V_33 + V_34 , V_10 , V_25 ) ;
F_28 ( * V_29 , - V_34 ) ;
}
}
void F_31 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_29 ( F_32 ( V_35 ) , V_25 ) ;
}
void F_33 ( struct V_10 * V_10 , enum V_24 V_25 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
T_3 V_33 , V_32 ;
V_33 = F_34 ( * V_29 ) ;
V_32 = F_25 ( V_28 -> V_19 ) ;
if ( F_26 ( V_33 < - V_32 ) ) {
T_3 V_34 = V_32 >> 1 ;
F_27 ( V_33 - V_34 , V_10 , V_25 ) ;
F_28 ( * V_29 , V_34 ) ;
}
}
void F_35 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_33 ( F_32 ( V_35 ) , V_25 ) ;
}
static inline void F_36 ( struct V_10 * V_10 ,
enum V_24 V_25 , int V_26 , int V_36 )
{
struct V_27 T_2 * V_28 = V_10 -> V_18 ;
T_3 T_2 * V_29 = V_28 -> V_30 + V_25 ;
long V_37 , V_38 , V_32 , V_39 ;
do {
V_39 = 0 ;
V_32 = F_37 ( V_28 -> V_19 ) ;
V_37 = F_37 ( * V_29 ) ;
V_38 = V_26 + V_37 ;
if ( V_38 > V_32 || V_38 < - V_32 ) {
int V_40 = V_36 * ( V_32 >> 1 ) ;
V_39 = V_38 + V_40 ;
V_38 = - V_40 ;
}
} while ( F_38 ( * V_29 , V_37 , V_38 ) != V_37 );
if ( V_39 )
F_27 ( V_39 , V_10 , V_25 ) ;
}
void F_39 ( struct V_10 * V_10 , enum V_24 V_25 ,
int V_26 )
{
F_36 ( V_10 , V_25 , V_26 , 0 ) ;
}
void F_40 ( struct V_10 * V_10 , enum V_24 V_25 )
{
F_36 ( V_10 , V_25 , 1 , 1 ) ;
}
void F_41 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_36 ( F_32 ( V_35 ) , V_25 , 1 , 1 ) ;
}
void F_42 ( struct V_35 * V_35 , enum V_24 V_25 )
{
F_36 ( F_32 ( V_35 ) , V_25 , - 1 , - 1 ) ;
}
void F_39 ( struct V_10 * V_10 , enum V_24 V_25 ,
int V_26 )
{
unsigned long V_41 ;
F_43 ( V_41 ) ;
F_24 ( V_10 , V_25 , V_26 ) ;
F_44 ( V_41 ) ;
}
void F_40 ( struct V_10 * V_10 , enum V_24 V_25 )
{
unsigned long V_41 ;
F_43 ( V_41 ) ;
F_29 ( V_10 , V_25 ) ;
F_44 ( V_41 ) ;
}
void F_41 ( struct V_35 * V_35 , enum V_24 V_25 )
{
unsigned long V_41 ;
struct V_10 * V_10 ;
V_10 = F_32 ( V_35 ) ;
F_43 ( V_41 ) ;
F_29 ( V_10 , V_25 ) ;
F_44 ( V_41 ) ;
}
void F_42 ( struct V_35 * V_35 , enum V_24 V_25 )
{
unsigned long V_41 ;
F_43 ( V_41 ) ;
F_35 ( V_35 , V_25 ) ;
F_44 ( V_41 ) ;
}
static inline void F_45 ( int * V_42 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
if ( V_42 [ V_3 ] )
F_46 ( V_42 [ V_3 ] , & V_44 [ V_3 ] ) ;
}
static void F_47 ( void )
{
struct V_10 * V_10 ;
int V_3 ;
int V_45 [ V_43 ] = { 0 , } ;
F_18 (zone) {
struct V_27 T_2 * V_29 = V_10 -> V_18 ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ ) {
int V_33 ;
V_33 = F_48 ( V_29 -> V_30 [ V_3 ] , 0 ) ;
if ( V_33 ) {
F_46 ( V_33 , & V_10 -> V_44 [ V_3 ] ) ;
V_45 [ V_3 ] += V_33 ;
#ifdef F_49
F_28 ( V_29 -> V_46 , 3 ) ;
#endif
}
}
F_50 () ;
#ifdef F_49
if ( ! F_25 ( V_29 -> V_46 ) ||
! F_25 ( V_29 -> V_28 . V_47 ) )
continue;
if ( F_51 ( V_10 ) == F_52 () ) {
F_28 ( V_29 -> V_46 , 0 ) ;
continue;
}
if ( F_34 ( V_29 -> V_46 ) )
continue;
if ( F_25 ( V_29 -> V_28 . V_47 ) )
F_53 ( V_10 , F_54 ( & V_29 -> V_28 ) ) ;
#endif
}
F_45 ( V_45 ) ;
}
void F_55 ( int V_2 )
{
struct V_10 * V_10 ;
int V_3 ;
int V_45 [ V_43 ] = { 0 , } ;
F_18 (zone) {
struct V_27 * V_29 ;
V_29 = F_19 ( V_10 -> V_18 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
if ( V_29 -> V_30 [ V_3 ] ) {
int V_33 ;
V_33 = V_29 -> V_30 [ V_3 ] ;
V_29 -> V_30 [ V_3 ] = 0 ;
F_46 ( V_33 , & V_10 -> V_44 [ V_3 ] ) ;
V_45 [ V_3 ] += V_33 ;
}
}
F_45 ( V_45 ) ;
}
void F_56 ( struct V_10 * V_10 , struct V_27 * V_48 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
if ( V_48 -> V_30 [ V_3 ] ) {
int V_33 = V_48 -> V_30 [ V_3 ] ;
V_48 -> V_30 [ V_3 ] = 0 ;
F_46 ( V_33 , & V_10 -> V_44 [ V_3 ] ) ;
F_46 ( V_33 , & V_44 [ V_3 ] ) ;
}
}
void F_57 ( struct V_10 * V_49 , struct V_10 * V_39 , T_4 V_41 )
{
if ( V_39 -> V_50 == V_49 -> V_50 ) {
F_29 ( V_39 , V_51 ) ;
} else {
F_29 ( V_39 , V_52 ) ;
F_29 ( V_49 , V_53 ) ;
}
if ( V_39 -> V_54 == ( ( V_41 & V_55 ) ?
V_49 -> V_54 : F_52 () ) )
F_29 ( V_39 , V_56 ) ;
else
F_29 ( V_39 , V_57 ) ;
}
static void F_58 ( struct V_10 * V_10 ,
unsigned int V_58 ,
struct V_59 * V_60 )
{
unsigned int V_61 ;
V_60 -> V_62 = 0 ;
V_60 -> V_63 = 0 ;
V_60 -> V_64 = 0 ;
for ( V_61 = 0 ; V_61 < V_65 ; V_61 ++ ) {
unsigned long V_66 ;
V_66 = V_10 -> V_67 [ V_61 ] . V_68 ;
V_60 -> V_63 += V_66 ;
V_60 -> V_62 += V_66 << V_61 ;
if ( V_61 >= V_58 )
V_60 -> V_64 += V_66 <<
( V_61 - V_58 ) ;
}
}
static int F_59 ( unsigned int V_61 , struct V_59 * V_60 )
{
unsigned long V_69 = 1UL << V_61 ;
if ( ! V_60 -> V_63 )
return 0 ;
if ( V_60 -> V_64 )
return - 1000 ;
return 1000 - F_60 ( ( 1000 + ( F_60 ( V_60 -> V_62 * 1000ULL , V_69 ) ) ) , V_60 -> V_63 ) ;
}
int F_61 ( struct V_10 * V_10 , unsigned int V_61 )
{
struct V_59 V_60 ;
F_58 ( V_10 , V_61 , & V_60 ) ;
return F_59 ( V_61 , & V_60 ) ;
}
static void * F_62 ( struct V_70 * V_71 , T_5 * V_72 )
{
T_1 * V_21 ;
T_5 V_54 = * V_72 ;
for ( V_21 = F_63 () ;
V_21 && V_54 ;
V_21 = F_64 ( V_21 ) )
-- V_54 ;
return V_21 ;
}
static void * F_65 ( struct V_70 * V_71 , void * V_73 , T_5 * V_72 )
{
T_1 * V_21 = ( T_1 * ) V_73 ;
( * V_72 ) ++ ;
return F_64 ( V_21 ) ;
}
static void F_66 ( struct V_70 * V_71 , void * V_73 )
{
}
static void F_67 ( struct V_70 * V_71 , T_1 * V_21 ,
void (* F_68)( struct V_70 * V_71 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_23 = V_21 -> V_23 ;
unsigned long V_41 ;
for ( V_10 = V_23 ; V_10 - V_23 < V_74 ; ++ V_10 ) {
if ( ! F_69 ( V_10 ) )
continue;
F_70 ( & V_10 -> V_75 , V_41 ) ;
F_68 ( V_71 , V_21 , V_10 ) ;
F_71 ( & V_10 -> V_75 , V_41 ) ;
}
}
static void F_72 ( struct V_70 * V_71 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_61 ;
F_73 ( V_71 , L_1 , V_21 -> V_76 , V_10 -> V_77 ) ;
for ( V_61 = 0 ; V_61 < V_65 ; ++ V_61 )
F_73 ( V_71 , L_2 , V_10 -> V_67 [ V_61 ] . V_68 ) ;
F_74 ( V_71 , '\n' ) ;
}
static int F_75 ( struct V_70 * V_71 , void * V_73 )
{
T_1 * V_21 = ( T_1 * ) V_73 ;
F_67 ( V_71 , V_21 , F_72 ) ;
return 0 ;
}
static void F_76 ( struct V_70 * V_71 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_61 , V_78 ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
F_73 ( V_71 , L_3 ,
V_21 -> V_76 ,
V_10 -> V_77 ,
V_80 [ V_78 ] ) ;
for ( V_61 = 0 ; V_61 < V_65 ; ++ V_61 ) {
unsigned long V_81 = 0 ;
struct V_67 * V_82 ;
struct V_83 * V_84 ;
V_82 = & ( V_10 -> V_67 [ V_61 ] ) ;
F_77 (curr, &area->free_list[mtype])
V_81 ++ ;
F_73 ( V_71 , L_2 , V_81 ) ;
}
F_74 ( V_71 , '\n' ) ;
}
}
static int F_78 ( struct V_70 * V_71 , void * V_73 )
{
int V_61 ;
T_1 * V_21 = ( T_1 * ) V_73 ;
F_73 ( V_71 , L_4 , L_5 ) ;
for ( V_61 = 0 ; V_61 < V_65 ; ++ V_61 )
F_73 ( V_71 , L_6 , V_61 ) ;
F_74 ( V_71 , '\n' ) ;
F_67 ( V_71 , V_21 , F_76 ) ;
return 0 ;
}
static void F_79 ( struct V_70 * V_71 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_78 ;
unsigned long V_85 ;
unsigned long V_86 = V_10 -> V_87 ;
unsigned long V_88 = F_80 ( V_10 ) ;
unsigned long V_47 [ V_79 ] = { 0 , } ;
for ( V_85 = V_86 ; V_85 < V_88 ; V_85 += V_89 ) {
struct V_35 * V_35 ;
if ( ! F_81 ( V_85 ) )
continue;
V_35 = F_82 ( V_85 ) ;
if ( ! F_83 ( V_85 , V_35 , V_10 ) )
continue;
V_78 = F_84 ( V_35 ) ;
if ( V_78 < V_79 )
V_47 [ V_78 ] ++ ;
}
F_73 ( V_71 , L_1 , V_21 -> V_76 , V_10 -> V_77 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ )
F_73 ( V_71 , L_7 , V_47 [ V_78 ] ) ;
F_74 ( V_71 , '\n' ) ;
}
static int F_85 ( struct V_70 * V_71 , void * V_73 )
{
int V_78 ;
T_1 * V_21 = ( T_1 * ) V_73 ;
F_73 ( V_71 , L_8 , L_9 ) ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ )
F_73 ( V_71 , L_10 , V_80 [ V_78 ] ) ;
F_74 ( V_71 , '\n' ) ;
F_67 ( V_71 , V_21 , F_79 ) ;
return 0 ;
}
static int F_86 ( struct V_70 * V_71 , void * V_73 )
{
T_1 * V_21 = ( T_1 * ) V_73 ;
if ( ! F_87 ( V_21 -> V_76 , V_90 ) )
return 0 ;
F_73 ( V_71 , L_11 , V_91 ) ;
F_73 ( V_71 , L_12 , V_89 ) ;
F_74 ( V_71 , '\n' ) ;
F_78 ( V_71 , V_21 ) ;
F_85 ( V_71 , V_21 ) ;
return 0 ;
}
static int F_88 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_89 ( V_93 , & V_94 ) ;
}
static int F_90 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_89 ( V_93 , & V_95 ) ;
}
static void F_91 ( struct V_70 * V_71 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_3 ;
F_73 ( V_71 , L_13 , V_21 -> V_76 , V_10 -> V_77 ) ;
F_73 ( V_71 ,
L_14
L_15
L_16
L_17
L_18
L_19
L_20
L_21 ,
F_92 ( V_10 , V_96 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_20 ( V_10 ) ,
V_10 -> V_97 ,
V_10 -> V_98 ,
V_10 -> V_99 ,
V_10 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
F_73 ( V_71 , L_22 , V_100 [ V_3 ] ,
F_92 ( V_10 , V_3 ) ) ;
F_73 ( V_71 ,
L_23 ,
V_10 -> V_101 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_93 ( V_10 -> V_101 ) ; V_3 ++ )
F_73 ( V_71 , L_24 , V_10 -> V_101 [ V_3 ] ) ;
F_73 ( V_71 ,
L_25
L_26 ) ;
F_2 (i) {
struct V_27 * V_18 ;
V_18 = F_19 ( V_10 -> V_18 , V_3 ) ;
F_73 ( V_71 ,
L_27
L_28
L_29
L_30 ,
V_3 ,
V_18 -> V_28 . V_47 ,
V_18 -> V_28 . V_102 ,
V_18 -> V_28 . V_103 ) ;
#ifdef F_94
F_73 ( V_71 , L_31 ,
V_18 -> V_19 ) ;
#endif
}
F_73 ( V_71 ,
L_32
L_33
L_34 ,
! F_95 ( V_10 ) ,
V_10 -> V_87 ,
V_10 -> V_104 ) ;
F_74 ( V_71 , '\n' ) ;
}
static int F_96 ( struct V_70 * V_71 , void * V_73 )
{
T_1 * V_21 = ( T_1 * ) V_73 ;
F_67 ( V_71 , V_21 , F_91 ) ;
return 0 ;
}
static int F_97 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_89 ( V_93 , & V_105 ) ;
}
static void * F_98 ( struct V_70 * V_71 , T_5 * V_72 )
{
unsigned long * V_33 ;
int V_3 , V_106 ;
if ( * V_72 >= F_93 ( V_100 ) )
return NULL ;
V_106 = V_43 * sizeof( unsigned long ) +
V_107 * sizeof( unsigned long ) ;
#ifdef F_99
V_106 += sizeof( struct V_5 ) ;
#endif
V_33 = F_100 ( V_106 , V_108 ) ;
V_71 -> V_109 = V_33 ;
if ( ! V_33 )
return F_101 ( - V_110 ) ;
for ( V_3 = 0 ; V_3 < V_43 ; V_3 ++ )
V_33 [ V_3 ] = F_102 ( V_3 ) ;
V_33 += V_43 ;
F_103 ( V_33 + V_111 ,
V_33 + V_112 ) ;
V_33 += V_107 ;
#ifdef F_99
F_4 ( V_33 ) ;
V_33 [ V_113 ] /= 2 ;
V_33 [ V_114 ] /= 2 ;
#endif
return ( unsigned long * ) V_71 -> V_109 + * V_72 ;
}
static void * F_104 ( struct V_70 * V_71 , void * V_73 , T_5 * V_72 )
{
( * V_72 ) ++ ;
if ( * V_72 >= F_93 ( V_100 ) )
return NULL ;
return ( unsigned long * ) V_71 -> V_109 + * V_72 ;
}
static int F_105 ( struct V_70 * V_71 , void * V_73 )
{
unsigned long * V_115 = V_73 ;
unsigned long V_116 = V_115 - ( unsigned long * ) V_71 -> V_109 ;
F_73 ( V_71 , L_35 , V_100 [ V_116 ] , * V_115 ) ;
return 0 ;
}
static void F_106 ( struct V_70 * V_71 , void * V_73 )
{
F_107 ( V_71 -> V_109 ) ;
V_71 -> V_109 = NULL ;
}
static int F_108 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_89 ( V_93 , & V_117 ) ;
}
static void F_109 ( struct V_118 * V_119 )
{
F_47 () ;
F_110 ( & F_111 ( V_120 ) ,
F_112 ( V_121 ) ) ;
}
static void F_113 ( int V_2 )
{
struct V_122 * V_123 = & F_3 ( V_120 , V_2 ) ;
F_114 ( V_123 , F_109 ) ;
F_115 ( V_2 , V_123 , F_116 ( V_124 , V_2 ) ) ;
}
static void F_117 ( int V_54 )
{
int V_2 ;
F_5 () ;
F_2 (cpu)
if ( F_118 ( V_2 ) == V_54 )
goto V_125;
F_119 ( V_54 , V_126 ) ;
V_125:
F_6 () ;
}
static int F_120 ( struct V_127 * V_128 ,
unsigned long V_129 ,
void * V_130 )
{
long V_2 = ( long ) V_130 ;
switch ( V_129 ) {
case V_131 :
case V_132 :
F_17 () ;
F_113 ( V_2 ) ;
F_121 ( F_118 ( V_2 ) , V_126 ) ;
break;
case V_133 :
case V_134 :
F_122 ( & F_3 ( V_120 , V_2 ) ) ;
F_3 ( V_120 , V_2 ) . V_123 . V_135 = NULL ;
break;
case V_136 :
case V_137 :
F_113 ( V_2 ) ;
break;
case V_138 :
case V_139 :
F_17 () ;
F_117 ( F_118 ( V_2 ) ) ;
break;
default:
break;
}
return V_140 ;
}
static int T_6 F_123 ( void )
{
#ifdef F_94
int V_2 ;
F_124 ( & V_141 ) ;
F_5 () ;
F_2 (cpu) {
F_113 ( V_2 ) ;
F_121 ( F_118 ( V_2 ) , V_126 ) ;
}
F_6 () ;
#endif
#ifdef F_125
F_126 ( L_36 , V_142 , NULL , & V_143 ) ;
F_126 ( L_37 , V_142 , NULL , & V_144 ) ;
F_126 ( L_38 , V_142 , NULL , & V_145 ) ;
F_126 ( L_39 , V_142 , NULL , & V_146 ) ;
#endif
return 0 ;
}
static int F_127 ( unsigned int V_61 ,
struct V_59 * V_60 )
{
if ( V_60 -> V_62 == 0 )
return 1000 ;
return F_60 ( ( V_60 -> V_62 - ( V_60 -> V_64 << V_61 ) ) * 1000ULL , V_60 -> V_62 ) ;
}
static void F_128 ( struct V_70 * V_71 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_61 ;
int V_147 ;
struct V_59 V_60 ;
F_73 ( V_71 , L_1 ,
V_21 -> V_76 ,
V_10 -> V_77 ) ;
for ( V_61 = 0 ; V_61 < V_65 ; ++ V_61 ) {
F_58 ( V_10 , V_61 , & V_60 ) ;
V_147 = F_127 ( V_61 , & V_60 ) ;
F_73 ( V_71 , L_40 , V_147 / 1000 , V_147 % 1000 ) ;
}
F_74 ( V_71 , '\n' ) ;
}
static int F_129 ( struct V_70 * V_71 , void * V_73 )
{
T_1 * V_21 = ( T_1 * ) V_73 ;
if ( ! F_87 ( V_21 -> V_76 , V_90 ) )
return 0 ;
F_67 ( V_71 , V_21 , F_128 ) ;
return 0 ;
}
static int F_130 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_89 ( V_93 , & V_148 ) ;
}
static void F_131 ( struct V_70 * V_71 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_61 ;
int V_147 ;
struct V_59 V_60 ;
F_73 ( V_71 , L_1 ,
V_21 -> V_76 ,
V_10 -> V_77 ) ;
for ( V_61 = 0 ; V_61 < V_65 ; ++ V_61 ) {
F_58 ( V_10 , V_61 , & V_60 ) ;
V_147 = F_59 ( V_61 , & V_60 ) ;
F_73 ( V_71 , L_40 , V_147 / 1000 , V_147 % 1000 ) ;
}
F_74 ( V_71 , '\n' ) ;
}
static int F_132 ( struct V_70 * V_71 , void * V_73 )
{
T_1 * V_21 = ( T_1 * ) V_73 ;
F_67 ( V_71 , V_21 , F_131 ) ;
return 0 ;
}
static int F_133 ( struct V_92 * V_92 , struct V_93 * V_93 )
{
return F_89 ( V_93 , & V_149 ) ;
}
static int T_6 F_134 ( void )
{
struct V_150 * V_151 ;
V_151 = F_135 ( L_41 , NULL ) ;
if ( ! V_151 )
return - V_110 ;
if ( ! F_136 ( L_42 , 0444 ,
V_151 , NULL , & V_152 ) )
goto V_153;
if ( ! F_136 ( L_43 , 0444 ,
V_151 , NULL , & V_154 ) )
goto V_153;
return 0 ;
V_153:
F_137 ( V_151 ) ;
return - V_110 ;
}
