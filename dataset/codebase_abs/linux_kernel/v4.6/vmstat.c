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
long V_26 )
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
static inline void F_35 ( struct V_10 * V_10 , enum V_24 V_25 ,
long V_26 , int V_36 )
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
long V_26 )
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
long V_26 )
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
static int F_46 ( bool V_46 )
{
struct V_10 * V_10 ;
int V_3 ;
int V_47 [ V_44 ] = { 0 , } ;
int V_43 = 0 ;
F_18 (zone) {
struct V_27 T_2 * V_29 = V_10 -> V_18 ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ ) {
int V_33 ;
V_33 = F_47 ( V_29 -> V_30 [ V_3 ] , 0 ) ;
if ( V_33 ) {
F_45 ( V_33 , & V_10 -> V_45 [ V_3 ] ) ;
V_47 [ V_3 ] += V_33 ;
#ifdef F_48
F_27 ( V_29 -> V_48 , 3 ) ;
#endif
}
}
#ifdef F_48
if ( V_46 ) {
F_49 () ;
if ( ! F_24 ( V_29 -> V_48 ) ||
! F_24 ( V_29 -> V_28 . V_49 ) )
continue;
if ( F_50 ( V_10 ) == F_51 () ) {
F_27 ( V_29 -> V_48 , 0 ) ;
continue;
}
if ( F_33 ( V_29 -> V_48 ) )
continue;
if ( F_24 ( V_29 -> V_28 . V_49 ) ) {
F_52 ( V_10 , F_53 ( & V_29 -> V_28 ) ) ;
V_43 ++ ;
}
}
#endif
}
V_43 += F_44 ( V_47 ) ;
return V_43 ;
}
void F_54 ( int V_2 )
{
struct V_10 * V_10 ;
int V_3 ;
int V_47 [ V_44 ] = { 0 , } ;
F_18 (zone) {
struct V_27 * V_29 ;
V_29 = F_19 ( V_10 -> V_18 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
if ( V_29 -> V_30 [ V_3 ] ) {
int V_33 ;
V_33 = V_29 -> V_30 [ V_3 ] ;
V_29 -> V_30 [ V_3 ] = 0 ;
F_45 ( V_33 , & V_10 -> V_45 [ V_3 ] ) ;
V_47 [ V_3 ] += V_33 ;
}
}
F_44 ( V_47 ) ;
}
void F_55 ( struct V_10 * V_10 , struct V_27 * V_50 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
if ( V_50 -> V_30 [ V_3 ] ) {
int V_33 = V_50 -> V_30 [ V_3 ] ;
V_50 -> V_30 [ V_3 ] = 0 ;
F_45 ( V_33 , & V_10 -> V_45 [ V_3 ] ) ;
F_45 ( V_33 , & V_45 [ V_3 ] ) ;
}
}
void F_56 ( struct V_10 * V_51 , struct V_10 * V_39 , T_4 V_41 )
{
if ( V_39 -> V_52 == V_51 -> V_52 ) {
F_28 ( V_39 , V_53 ) ;
} else {
F_28 ( V_39 , V_54 ) ;
F_28 ( V_51 , V_55 ) ;
}
if ( V_39 -> V_56 == ( ( V_41 & V_57 ) ?
V_51 -> V_56 : F_51 () ) )
F_28 ( V_39 , V_58 ) ;
else
F_28 ( V_39 , V_59 ) ;
}
unsigned long F_57 ( int V_56 , enum V_24 V_25 )
{
struct V_10 * V_60 = F_58 ( V_56 ) -> V_23 ;
return
#ifdef F_59
F_60 ( & V_60 [ V_61 ] , V_25 ) +
#endif
#ifdef F_61
F_60 ( & V_60 [ V_62 ] , V_25 ) +
#endif
#ifdef F_62
F_60 ( & V_60 [ V_63 ] , V_25 ) +
#endif
F_60 ( & V_60 [ V_64 ] , V_25 ) +
F_60 ( & V_60 [ V_65 ] , V_25 ) ;
}
static void F_63 ( struct V_10 * V_10 ,
unsigned int V_66 ,
struct V_67 * V_68 )
{
unsigned int V_69 ;
V_68 -> V_70 = 0 ;
V_68 -> V_71 = 0 ;
V_68 -> V_72 = 0 ;
for ( V_69 = 0 ; V_69 < V_73 ; V_69 ++ ) {
unsigned long V_74 ;
V_74 = V_10 -> V_75 [ V_69 ] . V_76 ;
V_68 -> V_71 += V_74 ;
V_68 -> V_70 += V_74 << V_69 ;
if ( V_69 >= V_66 )
V_68 -> V_72 += V_74 <<
( V_69 - V_66 ) ;
}
}
static int F_64 ( unsigned int V_69 , struct V_67 * V_68 )
{
unsigned long V_77 = 1UL << V_69 ;
if ( ! V_68 -> V_71 )
return 0 ;
if ( V_68 -> V_72 )
return - 1000 ;
return 1000 - F_65 ( ( 1000 + ( F_65 ( V_68 -> V_70 * 1000ULL , V_77 ) ) ) , V_68 -> V_71 ) ;
}
int F_66 ( struct V_10 * V_10 , unsigned int V_69 )
{
struct V_67 V_68 ;
F_63 ( V_10 , V_69 , & V_68 ) ;
return F_64 ( V_69 , & V_68 ) ;
}
static void * F_67 ( struct V_78 * V_79 , T_5 * V_80 )
{
T_1 * V_21 ;
T_5 V_56 = * V_80 ;
for ( V_21 = F_68 () ;
V_21 && V_56 ;
V_21 = F_69 ( V_21 ) )
-- V_56 ;
return V_21 ;
}
static void * F_70 ( struct V_78 * V_79 , void * V_81 , T_5 * V_80 )
{
T_1 * V_21 = ( T_1 * ) V_81 ;
( * V_80 ) ++ ;
return F_69 ( V_21 ) ;
}
static void F_71 ( struct V_78 * V_79 , void * V_81 )
{
}
static void F_72 ( struct V_78 * V_79 , T_1 * V_21 ,
void (* F_73)( struct V_78 * V_79 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_23 = V_21 -> V_23 ;
unsigned long V_41 ;
for ( V_10 = V_23 ; V_10 - V_23 < V_82 ; ++ V_10 ) {
if ( ! F_74 ( V_10 ) )
continue;
F_75 ( & V_10 -> V_83 , V_41 ) ;
F_73 ( V_79 , V_21 , V_10 ) ;
F_76 ( & V_10 -> V_83 , V_41 ) ;
}
}
static void F_77 ( struct V_78 * V_79 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_69 ;
F_78 ( V_79 , L_1 , V_21 -> V_84 , V_10 -> V_85 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 )
F_78 ( V_79 , L_2 , V_10 -> V_75 [ V_69 ] . V_76 ) ;
F_79 ( V_79 , '\n' ) ;
}
static int F_80 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_21 = ( T_1 * ) V_81 ;
F_72 ( V_79 , V_21 , F_77 ) ;
return 0 ;
}
static void F_81 ( struct V_78 * V_79 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_69 , V_86 ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
F_78 ( V_79 , L_3 ,
V_21 -> V_84 ,
V_10 -> V_85 ,
V_88 [ V_86 ] ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
unsigned long V_89 = 0 ;
struct V_75 * V_90 ;
struct V_91 * V_92 ;
V_90 = & ( V_10 -> V_75 [ V_69 ] ) ;
F_82 (curr, &area->free_list[mtype])
V_89 ++ ;
F_78 ( V_79 , L_2 , V_89 ) ;
}
F_79 ( V_79 , '\n' ) ;
}
}
static int F_83 ( struct V_78 * V_79 , void * V_81 )
{
int V_69 ;
T_1 * V_21 = ( T_1 * ) V_81 ;
F_78 ( V_79 , L_4 , L_5 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 )
F_78 ( V_79 , L_6 , V_69 ) ;
F_79 ( V_79 , '\n' ) ;
F_72 ( V_79 , V_21 , F_81 ) ;
return 0 ;
}
static void F_84 ( struct V_78 * V_79 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_86 ;
unsigned long V_93 ;
unsigned long V_94 = V_10 -> V_95 ;
unsigned long V_96 = F_85 ( V_10 ) ;
unsigned long V_49 [ V_87 ] = { 0 , } ;
for ( V_93 = V_94 ; V_93 < V_96 ; V_93 += V_97 ) {
struct V_35 * V_35 ;
if ( ! F_86 ( V_93 ) )
continue;
V_35 = F_87 ( V_93 ) ;
if ( ! F_88 ( V_93 , V_35 , V_10 ) )
continue;
V_86 = F_89 ( V_35 ) ;
if ( V_86 < V_87 )
V_49 [ V_86 ] ++ ;
}
F_78 ( V_79 , L_1 , V_21 -> V_84 , V_10 -> V_85 ) ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
F_78 ( V_79 , L_7 , V_49 [ V_86 ] ) ;
F_79 ( V_79 , '\n' ) ;
}
static int F_90 ( struct V_78 * V_79 , void * V_81 )
{
int V_86 ;
T_1 * V_21 = ( T_1 * ) V_81 ;
F_78 ( V_79 , L_8 , L_9 ) ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
F_78 ( V_79 , L_10 , V_88 [ V_86 ] ) ;
F_79 ( V_79 , '\n' ) ;
F_72 ( V_79 , V_21 , F_84 ) ;
return 0 ;
}
static void F_91 ( struct V_78 * V_79 ,
T_1 * V_21 ,
struct V_10 * V_10 )
{
struct V_35 * V_35 ;
struct V_98 * V_98 ;
unsigned long V_93 = V_10 -> V_95 , V_99 ;
unsigned long V_96 = V_93 + V_10 -> V_100 ;
unsigned long V_49 [ V_87 ] = { 0 , } ;
int V_101 , V_102 ;
int V_3 ;
V_93 = V_10 -> V_95 ;
for (; V_93 < V_96 ; ) {
if ( ! F_86 ( V_93 ) ) {
V_93 = F_92 ( V_93 + 1 , V_103 ) ;
continue;
}
V_99 = F_92 ( V_93 + 1 , V_97 ) ;
V_99 = F_14 ( V_99 , V_96 ) ;
V_35 = F_87 ( V_93 ) ;
V_101 = F_93 ( V_35 , V_93 ) ;
for (; V_93 < V_99 ; V_93 ++ ) {
if ( ! F_94 ( V_93 ) )
continue;
V_35 = F_87 ( V_93 ) ;
if ( F_95 ( V_35 ) ) {
V_93 += ( 1UL << F_96 ( V_35 ) ) - 1 ;
continue;
}
if ( F_97 ( V_35 ) )
continue;
V_98 = F_98 ( V_35 ) ;
if ( ! F_99 ( V_104 , & V_98 -> V_41 ) )
continue;
V_102 = F_100 ( V_98 -> V_105 ) ;
if ( V_101 != V_102 ) {
if ( F_101 ( V_101 ) )
V_49 [ V_106 ] ++ ;
else
V_49 [ V_101 ] ++ ;
V_93 = V_99 ;
break;
}
V_93 += ( 1UL << V_98 -> V_69 ) - 1 ;
}
}
F_78 ( V_79 , L_1 , V_21 -> V_84 , V_10 -> V_85 ) ;
for ( V_3 = 0 ; V_3 < V_87 ; V_3 ++ )
F_78 ( V_79 , L_7 , V_49 [ V_3 ] ) ;
F_79 ( V_79 , '\n' ) ;
}
static void F_102 ( struct V_78 * V_79 , T_1 * V_21 )
{
#ifdef F_103
int V_86 ;
if ( ! F_104 ( & V_107 ) )
return;
F_105 ( NULL ) ;
F_78 ( V_79 , L_8 , L_11 ) ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
F_78 ( V_79 , L_10 , V_88 [ V_86 ] ) ;
F_79 ( V_79 , '\n' ) ;
F_72 ( V_79 , V_21 , F_91 ) ;
#endif
}
static int F_106 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_21 = ( T_1 * ) V_81 ;
if ( ! F_107 ( V_21 -> V_84 , V_108 ) )
return 0 ;
F_78 ( V_79 , L_12 , V_109 ) ;
F_78 ( V_79 , L_13 , V_97 ) ;
F_79 ( V_79 , '\n' ) ;
F_83 ( V_79 , V_21 ) ;
F_90 ( V_79 , V_21 ) ;
F_102 ( V_79 , V_21 ) ;
return 0 ;
}
static int F_108 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_109 ( V_111 , & V_112 ) ;
}
static int F_110 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_109 ( V_111 , & V_113 ) ;
}
static void F_111 ( struct V_78 * V_79 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_3 ;
F_78 ( V_79 , L_14 , V_21 -> V_84 , V_10 -> V_85 ) ;
F_78 ( V_79 ,
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22 ,
F_60 ( V_10 , V_114 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_20 ( V_10 ) ,
F_60 ( V_10 , V_115 ) ,
V_10 -> V_100 ,
V_10 -> V_116 ,
V_10 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
F_78 ( V_79 , L_23 , V_117 [ V_3 ] ,
F_60 ( V_10 , V_3 ) ) ;
F_78 ( V_79 ,
L_24 ,
V_10 -> V_118 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_112 ( V_10 -> V_118 ) ; V_3 ++ )
F_78 ( V_79 , L_25 , V_10 -> V_118 [ V_3 ] ) ;
F_78 ( V_79 ,
L_26
L_27 ) ;
F_2 (i) {
struct V_27 * V_18 ;
V_18 = F_19 ( V_10 -> V_18 , V_3 ) ;
F_78 ( V_79 ,
L_28
L_29
L_30
L_31 ,
V_3 ,
V_18 -> V_28 . V_49 ,
V_18 -> V_28 . V_119 ,
V_18 -> V_28 . V_120 ) ;
#ifdef F_113
F_78 ( V_79 , L_32 ,
V_18 -> V_19 ) ;
#endif
}
F_78 ( V_79 ,
L_33
L_34
L_35 ,
! F_114 ( V_10 ) ,
V_10 -> V_95 ,
V_10 -> V_121 ) ;
F_79 ( V_79 , '\n' ) ;
}
static int F_115 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_21 = ( T_1 * ) V_81 ;
F_72 ( V_79 , V_21 , F_111 ) ;
return 0 ;
}
static int F_116 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_109 ( V_111 , & V_122 ) ;
}
static void * F_117 ( struct V_78 * V_79 , T_5 * V_80 )
{
unsigned long * V_33 ;
int V_3 , V_123 ;
if ( * V_80 >= F_112 ( V_117 ) )
return NULL ;
V_123 = V_44 * sizeof( unsigned long ) +
V_124 * sizeof( unsigned long ) ;
#ifdef F_118
V_123 += sizeof( struct V_5 ) ;
#endif
V_33 = F_119 ( V_123 , V_125 ) ;
V_79 -> V_126 = V_33 ;
if ( ! V_33 )
return F_120 ( - V_127 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
V_33 [ V_3 ] = F_121 ( V_3 ) ;
V_33 += V_44 ;
F_122 ( V_33 + V_128 ,
V_33 + V_129 ) ;
V_33 += V_124 ;
#ifdef F_118
F_4 ( V_33 ) ;
V_33 [ V_130 ] /= 2 ;
V_33 [ V_131 ] /= 2 ;
#endif
return ( unsigned long * ) V_79 -> V_126 + * V_80 ;
}
static void * F_123 ( struct V_78 * V_79 , void * V_81 , T_5 * V_80 )
{
( * V_80 ) ++ ;
if ( * V_80 >= F_112 ( V_117 ) )
return NULL ;
return ( unsigned long * ) V_79 -> V_126 + * V_80 ;
}
static int F_124 ( struct V_78 * V_79 , void * V_81 )
{
unsigned long * V_132 = V_81 ;
unsigned long V_133 = V_132 - ( unsigned long * ) V_79 -> V_126 ;
F_78 ( V_79 , L_36 , V_117 [ V_133 ] , * V_132 ) ;
return 0 ;
}
static void F_125 ( struct V_78 * V_79 , void * V_81 )
{
F_126 ( V_79 -> V_126 ) ;
V_79 -> V_126 = NULL ;
}
static int F_127 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_109 ( V_111 , & V_134 ) ;
}
static void F_128 ( struct V_135 * V_136 )
{
if ( F_46 ( true ) ) {
if ( ! F_129 ( F_130 () ,
V_137 ) ) {
F_131 ( F_130 () , V_138 ,
F_53 ( & V_139 ) ,
F_132 ( V_140 ) ) ;
}
} else {
F_133 ( F_130 () , V_137 ) ;
}
}
static bool F_134 ( int V_2 )
{
struct V_10 * V_10 ;
F_18 (zone) {
struct V_27 * V_29 = F_19 ( V_10 -> V_18 , V_2 ) ;
F_135 ( sizeof( V_29 -> V_30 [ 0 ] ) != 1 ) ;
if ( F_136 ( V_29 -> V_30 , 0 , V_44 ) )
return true ;
}
return false ;
}
void F_137 ( void )
{
if ( V_141 != V_142 )
return;
if ( F_138 ( F_130 () , V_137 ) )
return;
if ( ! F_134 ( F_130 () ) )
return;
F_46 ( false ) ;
}
static void F_139 ( struct V_135 * V_136 )
{
int V_2 ;
F_5 () ;
F_140 (cpu, cpu_stat_off) {
struct V_143 * V_144 = & F_3 ( V_139 , V_2 ) ;
if ( F_134 ( V_2 ) ) {
if ( F_129 ( V_2 , V_137 ) )
F_131 ( V_2 , V_138 , V_144 , 0 ) ;
} else {
F_141 ( V_144 ) ;
}
}
F_6 () ;
F_142 ( & V_145 ,
F_132 ( V_140 ) ) ;
}
static void T_6 F_143 ( void )
{
int V_2 ;
F_144 (cpu)
F_145 ( F_19 ( & V_139 , V_2 ) ,
F_128 ) ;
if ( ! F_146 ( & V_137 , V_125 ) )
F_147 () ;
F_148 ( V_137 , V_146 ) ;
V_138 = F_149 ( L_37 , V_147 | V_148 , 0 ) ;
F_142 ( & V_145 ,
F_132 ( V_140 ) ) ;
}
static void F_150 ( int V_56 )
{
int V_2 ;
F_5 () ;
F_2 (cpu)
if ( F_151 ( V_2 ) == V_56 )
goto V_149;
F_152 ( V_56 , V_150 ) ;
V_149:
F_6 () ;
}
static int F_153 ( struct V_151 * V_152 ,
unsigned long V_153 ,
void * V_154 )
{
long V_2 = ( long ) V_154 ;
switch ( V_153 ) {
case V_155 :
case V_156 :
F_17 () ;
F_154 ( F_151 ( V_2 ) , V_150 ) ;
F_133 ( V_2 , V_137 ) ;
break;
case V_157 :
case V_158 :
F_155 ( & F_3 ( V_139 , V_2 ) ) ;
F_156 ( V_2 , V_137 ) ;
break;
case V_159 :
case V_160 :
F_133 ( V_2 , V_137 ) ;
break;
case V_161 :
case V_162 :
F_17 () ;
F_150 ( F_151 ( V_2 ) ) ;
break;
default:
break;
}
return V_163 ;
}
static int T_6 F_157 ( void )
{
#ifdef F_113
F_158 () ;
F_159 ( & V_164 ) ;
F_143 () ;
F_160 () ;
#endif
#ifdef F_161
F_162 ( L_38 , V_165 , NULL , & V_166 ) ;
F_162 ( L_39 , V_165 , NULL , & V_167 ) ;
F_162 ( L_37 , V_165 , NULL , & V_168 ) ;
F_162 ( L_40 , V_165 , NULL , & V_169 ) ;
#endif
return 0 ;
}
static int F_163 ( unsigned int V_69 ,
struct V_67 * V_68 )
{
if ( V_68 -> V_70 == 0 )
return 1000 ;
return F_65 ( ( V_68 -> V_70 - ( V_68 -> V_72 << V_69 ) ) * 1000ULL , V_68 -> V_70 ) ;
}
static void F_164 ( struct V_78 * V_79 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_69 ;
int V_170 ;
struct V_67 V_68 ;
F_78 ( V_79 , L_1 ,
V_21 -> V_84 ,
V_10 -> V_85 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
F_63 ( V_10 , V_69 , & V_68 ) ;
V_170 = F_163 ( V_69 , & V_68 ) ;
F_78 ( V_79 , L_41 , V_170 / 1000 , V_170 % 1000 ) ;
}
F_79 ( V_79 , '\n' ) ;
}
static int F_165 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_21 = ( T_1 * ) V_81 ;
if ( ! F_107 ( V_21 -> V_84 , V_108 ) )
return 0 ;
F_72 ( V_79 , V_21 , F_164 ) ;
return 0 ;
}
static int F_166 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_109 ( V_111 , & V_171 ) ;
}
static void F_167 ( struct V_78 * V_79 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_69 ;
int V_170 ;
struct V_67 V_68 ;
F_78 ( V_79 , L_1 ,
V_21 -> V_84 ,
V_10 -> V_85 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
F_63 ( V_10 , V_69 , & V_68 ) ;
V_170 = F_64 ( V_69 , & V_68 ) ;
F_78 ( V_79 , L_41 , V_170 / 1000 , V_170 % 1000 ) ;
}
F_79 ( V_79 , '\n' ) ;
}
static int F_168 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_21 = ( T_1 * ) V_81 ;
F_72 ( V_79 , V_21 , F_167 ) ;
return 0 ;
}
static int F_169 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_109 ( V_111 , & V_172 ) ;
}
static int T_6 F_170 ( void )
{
struct V_173 * V_174 ;
V_174 = F_171 ( L_42 , NULL ) ;
if ( ! V_174 )
return - V_127 ;
if ( ! F_172 ( L_43 , 0444 ,
V_174 , NULL , & V_175 ) )
goto V_176;
if ( ! F_172 ( L_44 , 0444 ,
V_174 , NULL , & V_177 ) )
goto V_176;
return 0 ;
V_176:
F_173 ( V_174 ) ;
return - V_127 ;
}
