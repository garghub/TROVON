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
unsigned long F_57 ( int V_55 , enum V_24 V_25 )
{
struct V_10 * V_59 = F_58 ( V_55 ) -> V_23 ;
return
#ifdef F_59
F_60 ( & V_59 [ V_60 ] , V_25 ) +
#endif
#ifdef F_61
F_60 ( & V_59 [ V_61 ] , V_25 ) +
#endif
#ifdef F_62
F_60 ( & V_59 [ V_62 ] , V_25 ) +
#endif
F_60 ( & V_59 [ V_63 ] , V_25 ) +
F_60 ( & V_59 [ V_64 ] , V_25 ) ;
}
static void F_63 ( struct V_10 * V_10 ,
unsigned int V_65 ,
struct V_66 * V_67 )
{
unsigned int V_68 ;
V_67 -> V_69 = 0 ;
V_67 -> V_70 = 0 ;
V_67 -> V_71 = 0 ;
for ( V_68 = 0 ; V_68 < V_72 ; V_68 ++ ) {
unsigned long V_73 ;
V_73 = V_10 -> V_74 [ V_68 ] . V_75 ;
V_67 -> V_70 += V_73 ;
V_67 -> V_69 += V_73 << V_68 ;
if ( V_68 >= V_65 )
V_67 -> V_71 += V_73 <<
( V_68 - V_65 ) ;
}
}
static int F_64 ( unsigned int V_68 , struct V_66 * V_67 )
{
unsigned long V_76 = 1UL << V_68 ;
if ( ! V_67 -> V_70 )
return 0 ;
if ( V_67 -> V_71 )
return - 1000 ;
return 1000 - F_65 ( ( 1000 + ( F_65 ( V_67 -> V_69 * 1000ULL , V_76 ) ) ) , V_67 -> V_70 ) ;
}
int F_66 ( struct V_10 * V_10 , unsigned int V_68 )
{
struct V_66 V_67 ;
F_63 ( V_10 , V_68 , & V_67 ) ;
return F_64 ( V_68 , & V_67 ) ;
}
static void * F_67 ( struct V_77 * V_78 , T_5 * V_79 )
{
T_1 * V_21 ;
T_5 V_55 = * V_79 ;
for ( V_21 = F_68 () ;
V_21 && V_55 ;
V_21 = F_69 ( V_21 ) )
-- V_55 ;
return V_21 ;
}
static void * F_70 ( struct V_77 * V_78 , void * V_80 , T_5 * V_79 )
{
T_1 * V_21 = ( T_1 * ) V_80 ;
( * V_79 ) ++ ;
return F_69 ( V_21 ) ;
}
static void F_71 ( struct V_77 * V_78 , void * V_80 )
{
}
static void F_72 ( struct V_77 * V_78 , T_1 * V_21 ,
void (* F_73)( struct V_77 * V_78 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_23 = V_21 -> V_23 ;
unsigned long V_41 ;
for ( V_10 = V_23 ; V_10 - V_23 < V_81 ; ++ V_10 ) {
if ( ! F_74 ( V_10 ) )
continue;
F_75 ( & V_10 -> V_82 , V_41 ) ;
F_73 ( V_78 , V_21 , V_10 ) ;
F_76 ( & V_10 -> V_82 , V_41 ) ;
}
}
static void F_77 ( struct V_77 * V_78 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_68 ;
F_78 ( V_78 , L_1 , V_21 -> V_83 , V_10 -> V_84 ) ;
for ( V_68 = 0 ; V_68 < V_72 ; ++ V_68 )
F_78 ( V_78 , L_2 , V_10 -> V_74 [ V_68 ] . V_75 ) ;
F_79 ( V_78 , '\n' ) ;
}
static int F_80 ( struct V_77 * V_78 , void * V_80 )
{
T_1 * V_21 = ( T_1 * ) V_80 ;
F_72 ( V_78 , V_21 , F_77 ) ;
return 0 ;
}
static void F_81 ( struct V_77 * V_78 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_68 , V_85 ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ ) {
F_78 ( V_78 , L_3 ,
V_21 -> V_83 ,
V_10 -> V_84 ,
V_87 [ V_85 ] ) ;
for ( V_68 = 0 ; V_68 < V_72 ; ++ V_68 ) {
unsigned long V_88 = 0 ;
struct V_74 * V_89 ;
struct V_90 * V_91 ;
V_89 = & ( V_10 -> V_74 [ V_68 ] ) ;
F_82 (curr, &area->free_list[mtype])
V_88 ++ ;
F_78 ( V_78 , L_2 , V_88 ) ;
}
F_79 ( V_78 , '\n' ) ;
}
}
static int F_83 ( struct V_77 * V_78 , void * V_80 )
{
int V_68 ;
T_1 * V_21 = ( T_1 * ) V_80 ;
F_78 ( V_78 , L_4 , L_5 ) ;
for ( V_68 = 0 ; V_68 < V_72 ; ++ V_68 )
F_78 ( V_78 , L_6 , V_68 ) ;
F_79 ( V_78 , '\n' ) ;
F_72 ( V_78 , V_21 , F_81 ) ;
return 0 ;
}
static void F_84 ( struct V_77 * V_78 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_85 ;
unsigned long V_92 ;
unsigned long V_93 = V_10 -> V_94 ;
unsigned long V_95 = F_85 ( V_10 ) ;
unsigned long V_48 [ V_86 ] = { 0 , } ;
for ( V_92 = V_93 ; V_92 < V_95 ; V_92 += V_96 ) {
struct V_35 * V_35 ;
if ( ! F_86 ( V_92 ) )
continue;
V_35 = F_87 ( V_92 ) ;
if ( ! F_88 ( V_92 , V_35 , V_10 ) )
continue;
V_85 = F_89 ( V_35 ) ;
if ( V_85 < V_86 )
V_48 [ V_85 ] ++ ;
}
F_78 ( V_78 , L_1 , V_21 -> V_83 , V_10 -> V_84 ) ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
F_78 ( V_78 , L_7 , V_48 [ V_85 ] ) ;
F_79 ( V_78 , '\n' ) ;
}
static int F_90 ( struct V_77 * V_78 , void * V_80 )
{
int V_85 ;
T_1 * V_21 = ( T_1 * ) V_80 ;
F_78 ( V_78 , L_8 , L_9 ) ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
F_78 ( V_78 , L_10 , V_87 [ V_85 ] ) ;
F_79 ( V_78 , '\n' ) ;
F_72 ( V_78 , V_21 , F_84 ) ;
return 0 ;
}
static void F_91 ( struct V_77 * V_78 ,
T_1 * V_21 ,
struct V_10 * V_10 )
{
struct V_35 * V_35 ;
struct V_97 * V_97 ;
unsigned long V_92 = V_10 -> V_94 , V_98 ;
unsigned long V_95 = V_92 + V_10 -> V_99 ;
unsigned long V_48 [ V_86 ] = { 0 , } ;
int V_100 , V_101 ;
int V_3 ;
V_92 = V_10 -> V_94 ;
for (; V_92 < V_95 ; ) {
if ( ! F_86 ( V_92 ) ) {
V_92 = F_92 ( V_92 + 1 , V_102 ) ;
continue;
}
V_98 = F_92 ( V_92 + 1 , V_96 ) ;
V_98 = F_14 ( V_98 , V_95 ) ;
V_35 = F_87 ( V_92 ) ;
V_100 = F_93 ( V_35 , V_92 ) ;
for (; V_92 < V_98 ; V_92 ++ ) {
if ( ! F_94 ( V_92 ) )
continue;
V_35 = F_87 ( V_92 ) ;
if ( F_95 ( V_35 ) ) {
V_92 += ( 1UL << F_96 ( V_35 ) ) - 1 ;
continue;
}
if ( F_97 ( V_35 ) )
continue;
V_97 = F_98 ( V_35 ) ;
if ( ! F_99 ( V_103 , & V_97 -> V_41 ) )
continue;
V_101 = F_100 ( V_97 -> V_104 ) ;
if ( V_100 != V_101 ) {
if ( F_101 ( V_100 ) )
V_48 [ V_105 ] ++ ;
else
V_48 [ V_100 ] ++ ;
V_92 = V_98 ;
break;
}
V_92 += ( 1UL << V_97 -> V_68 ) - 1 ;
}
}
F_78 ( V_78 , L_1 , V_21 -> V_83 , V_10 -> V_84 ) ;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ )
F_78 ( V_78 , L_7 , V_48 [ V_3 ] ) ;
F_79 ( V_78 , '\n' ) ;
}
static void F_102 ( struct V_77 * V_78 , T_1 * V_21 )
{
#ifdef F_103
int V_85 ;
if ( ! V_106 )
return;
F_104 ( NULL ) ;
F_78 ( V_78 , L_8 , L_11 ) ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
F_78 ( V_78 , L_10 , V_87 [ V_85 ] ) ;
F_79 ( V_78 , '\n' ) ;
F_72 ( V_78 , V_21 , F_91 ) ;
#endif
}
static int F_105 ( struct V_77 * V_78 , void * V_80 )
{
T_1 * V_21 = ( T_1 * ) V_80 ;
if ( ! F_106 ( V_21 -> V_83 , V_107 ) )
return 0 ;
F_78 ( V_78 , L_12 , V_108 ) ;
F_78 ( V_78 , L_13 , V_96 ) ;
F_79 ( V_78 , '\n' ) ;
F_83 ( V_78 , V_21 ) ;
F_90 ( V_78 , V_21 ) ;
F_102 ( V_78 , V_21 ) ;
return 0 ;
}
static int F_107 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_108 ( V_110 , & V_111 ) ;
}
static int F_109 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_108 ( V_110 , & V_112 ) ;
}
static void F_110 ( struct V_77 * V_78 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_3 ;
F_78 ( V_78 , L_14 , V_21 -> V_83 , V_10 -> V_84 ) ;
F_78 ( V_78 ,
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22 ,
F_60 ( V_10 , V_113 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_20 ( V_10 ) ,
F_60 ( V_10 , V_114 ) ,
V_10 -> V_99 ,
V_10 -> V_115 ,
V_10 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
F_78 ( V_78 , L_23 , V_116 [ V_3 ] ,
F_60 ( V_10 , V_3 ) ) ;
F_78 ( V_78 ,
L_24 ,
V_10 -> V_117 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_111 ( V_10 -> V_117 ) ; V_3 ++ )
F_78 ( V_78 , L_25 , V_10 -> V_117 [ V_3 ] ) ;
F_78 ( V_78 ,
L_26
L_27 ) ;
F_2 (i) {
struct V_27 * V_18 ;
V_18 = F_19 ( V_10 -> V_18 , V_3 ) ;
F_78 ( V_78 ,
L_28
L_29
L_30
L_31 ,
V_3 ,
V_18 -> V_28 . V_48 ,
V_18 -> V_28 . V_118 ,
V_18 -> V_28 . V_119 ) ;
#ifdef F_112
F_78 ( V_78 , L_32 ,
V_18 -> V_19 ) ;
#endif
}
F_78 ( V_78 ,
L_33
L_34
L_35 ,
! F_113 ( V_10 ) ,
V_10 -> V_94 ,
V_10 -> V_120 ) ;
F_79 ( V_78 , '\n' ) ;
}
static int F_114 ( struct V_77 * V_78 , void * V_80 )
{
T_1 * V_21 = ( T_1 * ) V_80 ;
F_72 ( V_78 , V_21 , F_110 ) ;
return 0 ;
}
static int F_115 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_108 ( V_110 , & V_121 ) ;
}
static void * F_116 ( struct V_77 * V_78 , T_5 * V_79 )
{
unsigned long * V_33 ;
int V_3 , V_122 ;
if ( * V_79 >= F_111 ( V_116 ) )
return NULL ;
V_122 = V_44 * sizeof( unsigned long ) +
V_123 * sizeof( unsigned long ) ;
#ifdef F_117
V_122 += sizeof( struct V_5 ) ;
#endif
V_33 = F_118 ( V_122 , V_124 ) ;
V_78 -> V_125 = V_33 ;
if ( ! V_33 )
return F_119 ( - V_126 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
V_33 [ V_3 ] = F_120 ( V_3 ) ;
V_33 += V_44 ;
F_121 ( V_33 + V_127 ,
V_33 + V_128 ) ;
V_33 += V_123 ;
#ifdef F_117
F_4 ( V_33 ) ;
V_33 [ V_129 ] /= 2 ;
V_33 [ V_130 ] /= 2 ;
#endif
return ( unsigned long * ) V_78 -> V_125 + * V_79 ;
}
static void * F_122 ( struct V_77 * V_78 , void * V_80 , T_5 * V_79 )
{
( * V_79 ) ++ ;
if ( * V_79 >= F_111 ( V_116 ) )
return NULL ;
return ( unsigned long * ) V_78 -> V_125 + * V_79 ;
}
static int F_123 ( struct V_77 * V_78 , void * V_80 )
{
unsigned long * V_131 = V_80 ;
unsigned long V_132 = V_131 - ( unsigned long * ) V_78 -> V_125 ;
F_78 ( V_78 , L_36 , V_116 [ V_132 ] , * V_131 ) ;
return 0 ;
}
static void F_124 ( struct V_77 * V_78 , void * V_80 )
{
F_125 ( V_78 -> V_125 ) ;
V_78 -> V_125 = NULL ;
}
static int F_126 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_108 ( V_110 , & V_133 ) ;
}
static void F_127 ( struct V_134 * V_135 )
{
if ( F_46 () ) {
F_128 ( F_129 () , V_136 ,
F_53 ( & V_137 ) ,
F_130 ( V_138 ) ) ;
} else {
int V_139 ;
V_139 = F_131 ( F_129 () ,
V_140 ) ;
F_132 ( V_139 ) ;
}
}
static bool F_133 ( int V_2 )
{
struct V_10 * V_10 ;
F_18 (zone) {
struct V_27 * V_29 = F_19 ( V_10 -> V_18 , V_2 ) ;
F_134 ( sizeof( V_29 -> V_30 [ 0 ] ) != 1 ) ;
if ( F_135 ( V_29 -> V_30 , 0 , V_44 ) )
return true ;
}
return false ;
}
static void F_136 ( struct V_134 * V_135 )
{
int V_2 ;
F_5 () ;
F_137 (cpu, cpu_stat_off)
if ( F_133 ( V_2 ) &&
F_138 ( V_2 , V_140 ) )
F_128 ( V_2 , V_136 ,
& F_3 ( V_137 , V_2 ) , 0 ) ;
F_6 () ;
F_139 ( & V_141 ,
F_130 ( V_138 ) ) ;
}
static void T_6 F_140 ( void )
{
int V_2 ;
F_141 (cpu)
F_142 ( F_19 ( & V_137 , V_2 ) ,
F_127 ) ;
if ( ! F_143 ( & V_140 , V_124 ) )
F_144 () ;
F_145 ( V_140 , V_142 ) ;
V_136 = F_146 ( L_37 , V_143 | V_144 , 0 ) ;
F_139 ( & V_141 ,
F_130 ( V_138 ) ) ;
}
static void F_147 ( int V_55 )
{
int V_2 ;
F_5 () ;
F_2 (cpu)
if ( F_148 ( V_2 ) == V_55 )
goto V_145;
F_149 ( V_55 , V_146 ) ;
V_145:
F_6 () ;
}
static int F_150 ( struct V_147 * V_148 ,
unsigned long V_149 ,
void * V_150 )
{
long V_2 = ( long ) V_150 ;
switch ( V_149 ) {
case V_151 :
case V_152 :
F_17 () ;
F_151 ( F_148 ( V_2 ) , V_146 ) ;
F_152 ( V_2 , V_140 ) ;
break;
case V_153 :
case V_154 :
F_153 ( & F_3 ( V_137 , V_2 ) ) ;
F_154 ( V_2 , V_140 ) ;
break;
case V_155 :
case V_156 :
F_152 ( V_2 , V_140 ) ;
break;
case V_157 :
case V_158 :
F_17 () ;
F_147 ( F_148 ( V_2 ) ) ;
break;
default:
break;
}
return V_159 ;
}
static int T_6 F_155 ( void )
{
#ifdef F_112
F_156 () ;
F_157 ( & V_160 ) ;
F_140 () ;
F_158 () ;
#endif
#ifdef F_159
F_160 ( L_38 , V_161 , NULL , & V_162 ) ;
F_160 ( L_39 , V_161 , NULL , & V_163 ) ;
F_160 ( L_37 , V_161 , NULL , & V_164 ) ;
F_160 ( L_40 , V_161 , NULL , & V_165 ) ;
#endif
return 0 ;
}
static int F_161 ( unsigned int V_68 ,
struct V_66 * V_67 )
{
if ( V_67 -> V_69 == 0 )
return 1000 ;
return F_65 ( ( V_67 -> V_69 - ( V_67 -> V_71 << V_68 ) ) * 1000ULL , V_67 -> V_69 ) ;
}
static void F_162 ( struct V_77 * V_78 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_68 ;
int V_166 ;
struct V_66 V_67 ;
F_78 ( V_78 , L_1 ,
V_21 -> V_83 ,
V_10 -> V_84 ) ;
for ( V_68 = 0 ; V_68 < V_72 ; ++ V_68 ) {
F_63 ( V_10 , V_68 , & V_67 ) ;
V_166 = F_161 ( V_68 , & V_67 ) ;
F_78 ( V_78 , L_41 , V_166 / 1000 , V_166 % 1000 ) ;
}
F_79 ( V_78 , '\n' ) ;
}
static int F_163 ( struct V_77 * V_78 , void * V_80 )
{
T_1 * V_21 = ( T_1 * ) V_80 ;
if ( ! F_106 ( V_21 -> V_83 , V_107 ) )
return 0 ;
F_72 ( V_78 , V_21 , F_162 ) ;
return 0 ;
}
static int F_164 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_108 ( V_110 , & V_167 ) ;
}
static void F_165 ( struct V_77 * V_78 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_68 ;
int V_166 ;
struct V_66 V_67 ;
F_78 ( V_78 , L_1 ,
V_21 -> V_83 ,
V_10 -> V_84 ) ;
for ( V_68 = 0 ; V_68 < V_72 ; ++ V_68 ) {
F_63 ( V_10 , V_68 , & V_67 ) ;
V_166 = F_64 ( V_68 , & V_67 ) ;
F_78 ( V_78 , L_41 , V_166 / 1000 , V_166 % 1000 ) ;
}
F_79 ( V_78 , '\n' ) ;
}
static int F_166 ( struct V_77 * V_78 , void * V_80 )
{
T_1 * V_21 = ( T_1 * ) V_80 ;
F_72 ( V_78 , V_21 , F_165 ) ;
return 0 ;
}
static int F_167 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_108 ( V_110 , & V_168 ) ;
}
static int T_6 F_168 ( void )
{
struct V_169 * V_170 ;
V_170 = F_169 ( L_42 , NULL ) ;
if ( ! V_170 )
return - V_126 ;
if ( ! F_170 ( L_43 , 0444 ,
V_170 , NULL , & V_171 ) )
goto V_172;
if ( ! F_170 ( L_44 , 0444 ,
V_170 , NULL , & V_173 ) )
goto V_172;
return 0 ;
V_172:
F_171 ( V_170 ) ;
return - V_126 ;
}
