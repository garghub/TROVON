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
unsigned long F_56 ( int V_51 , enum V_24 V_25 )
{
struct V_10 * V_52 = F_57 ( V_51 ) -> V_23 ;
int V_3 ;
unsigned long V_49 = 0 ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ )
V_49 += F_58 ( V_52 + V_3 , V_25 ) ;
return V_49 ;
}
static void F_59 ( struct V_10 * V_10 ,
unsigned int V_54 ,
struct V_55 * V_56 )
{
unsigned int V_57 ;
V_56 -> V_58 = 0 ;
V_56 -> V_59 = 0 ;
V_56 -> V_60 = 0 ;
for ( V_57 = 0 ; V_57 < V_61 ; V_57 ++ ) {
unsigned long V_62 ;
V_62 = V_10 -> V_63 [ V_57 ] . V_64 ;
V_56 -> V_59 += V_62 ;
V_56 -> V_58 += V_62 << V_57 ;
if ( V_57 >= V_54 )
V_56 -> V_60 += V_62 <<
( V_57 - V_54 ) ;
}
}
static int F_60 ( unsigned int V_57 , struct V_55 * V_56 )
{
unsigned long V_65 = 1UL << V_57 ;
if ( ! V_56 -> V_59 )
return 0 ;
if ( V_56 -> V_60 )
return - 1000 ;
return 1000 - F_61 ( ( 1000 + ( F_61 ( V_56 -> V_58 * 1000ULL , V_65 ) ) ) , V_56 -> V_59 ) ;
}
int F_62 ( struct V_10 * V_10 , unsigned int V_57 )
{
struct V_55 V_56 ;
F_59 ( V_10 , V_57 , & V_56 ) ;
return F_60 ( V_57 , & V_56 ) ;
}
static void * F_63 ( struct V_66 * V_67 , T_4 * V_68 )
{
T_1 * V_21 ;
T_4 V_51 = * V_68 ;
for ( V_21 = F_64 () ;
V_21 && V_51 ;
V_21 = F_65 ( V_21 ) )
-- V_51 ;
return V_21 ;
}
static void * F_66 ( struct V_66 * V_67 , void * V_69 , T_4 * V_68 )
{
T_1 * V_21 = ( T_1 * ) V_69 ;
( * V_68 ) ++ ;
return F_65 ( V_21 ) ;
}
static void F_67 ( struct V_66 * V_67 , void * V_69 )
{
}
static void F_68 ( struct V_66 * V_67 , T_1 * V_21 ,
void (* F_69)( struct V_66 * V_67 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_23 = V_21 -> V_23 ;
unsigned long V_41 ;
for ( V_10 = V_23 ; V_10 - V_23 < V_53 ; ++ V_10 ) {
if ( ! F_70 ( V_10 ) )
continue;
F_71 ( & V_10 -> V_70 , V_41 ) ;
F_69 ( V_67 , V_21 , V_10 ) ;
F_72 ( & V_10 -> V_70 , V_41 ) ;
}
}
static void F_73 ( struct V_66 * V_67 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_57 ;
F_74 ( V_67 , L_1 , V_21 -> V_71 , V_10 -> V_72 ) ;
for ( V_57 = 0 ; V_57 < V_61 ; ++ V_57 )
F_74 ( V_67 , L_2 , V_10 -> V_63 [ V_57 ] . V_64 ) ;
F_75 ( V_67 , '\n' ) ;
}
static int F_76 ( struct V_66 * V_67 , void * V_69 )
{
T_1 * V_21 = ( T_1 * ) V_69 ;
F_68 ( V_67 , V_21 , F_73 ) ;
return 0 ;
}
static void F_77 ( struct V_66 * V_67 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_57 , V_73 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ ) {
F_74 ( V_67 , L_3 ,
V_21 -> V_71 ,
V_10 -> V_72 ,
V_75 [ V_73 ] ) ;
for ( V_57 = 0 ; V_57 < V_61 ; ++ V_57 ) {
unsigned long V_76 = 0 ;
struct V_63 * V_77 ;
struct V_78 * V_79 ;
V_77 = & ( V_10 -> V_63 [ V_57 ] ) ;
F_78 (curr, &area->free_list[mtype])
V_76 ++ ;
F_74 ( V_67 , L_2 , V_76 ) ;
}
F_75 ( V_67 , '\n' ) ;
}
}
static int F_79 ( struct V_66 * V_67 , void * V_69 )
{
int V_57 ;
T_1 * V_21 = ( T_1 * ) V_69 ;
F_74 ( V_67 , L_4 , L_5 ) ;
for ( V_57 = 0 ; V_57 < V_61 ; ++ V_57 )
F_74 ( V_67 , L_6 , V_57 ) ;
F_75 ( V_67 , '\n' ) ;
F_68 ( V_67 , V_21 , F_77 ) ;
return 0 ;
}
static void F_80 ( struct V_66 * V_67 ,
T_1 * V_21 , struct V_10 * V_10 )
{
int V_73 ;
unsigned long V_80 ;
unsigned long V_81 = V_10 -> V_82 ;
unsigned long V_83 = F_81 ( V_10 ) ;
unsigned long V_49 [ V_74 ] = { 0 , } ;
for ( V_80 = V_81 ; V_80 < V_83 ; V_80 += V_84 ) {
struct V_35 * V_35 ;
if ( ! F_82 ( V_80 ) )
continue;
V_35 = F_83 ( V_80 ) ;
if ( ! F_84 ( V_80 , V_35 , V_10 ) )
continue;
if ( F_31 ( V_35 ) != V_10 )
continue;
V_73 = F_85 ( V_35 ) ;
if ( V_73 < V_74 )
V_49 [ V_73 ] ++ ;
}
F_74 ( V_67 , L_1 , V_21 -> V_71 , V_10 -> V_72 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
F_74 ( V_67 , L_7 , V_49 [ V_73 ] ) ;
F_75 ( V_67 , '\n' ) ;
}
static int F_86 ( struct V_66 * V_67 , void * V_69 )
{
int V_73 ;
T_1 * V_21 = ( T_1 * ) V_69 ;
F_74 ( V_67 , L_8 , L_9 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
F_74 ( V_67 , L_10 , V_75 [ V_73 ] ) ;
F_75 ( V_67 , '\n' ) ;
F_68 ( V_67 , V_21 , F_80 ) ;
return 0 ;
}
static void F_87 ( struct V_66 * V_67 ,
T_1 * V_21 ,
struct V_10 * V_10 )
{
struct V_35 * V_35 ;
struct V_85 * V_85 ;
unsigned long V_80 = V_10 -> V_82 , V_86 ;
unsigned long V_83 = V_80 + V_10 -> V_87 ;
unsigned long V_49 [ V_74 ] = { 0 , } ;
int V_88 , V_89 ;
int V_3 ;
V_80 = V_10 -> V_82 ;
for (; V_80 < V_83 ; ) {
if ( ! F_82 ( V_80 ) ) {
V_80 = F_88 ( V_80 + 1 , V_90 ) ;
continue;
}
V_86 = F_88 ( V_80 + 1 , V_84 ) ;
V_86 = F_14 ( V_86 , V_83 ) ;
V_35 = F_83 ( V_80 ) ;
V_88 = F_85 ( V_35 ) ;
for (; V_80 < V_86 ; V_80 ++ ) {
if ( ! F_89 ( V_80 ) )
continue;
V_35 = F_83 ( V_80 ) ;
if ( F_31 ( V_35 ) != V_10 )
continue;
if ( F_90 ( V_35 ) ) {
V_80 += ( 1UL << F_91 ( V_35 ) ) - 1 ;
continue;
}
if ( F_92 ( V_35 ) )
continue;
V_85 = F_93 ( V_35 ) ;
if ( F_25 ( ! V_85 ) )
continue;
if ( ! F_94 ( V_91 , & V_85 -> V_41 ) )
continue;
V_89 = F_95 ( V_85 -> V_92 ) ;
if ( V_88 != V_89 ) {
if ( F_96 ( V_88 ) )
V_49 [ V_93 ] ++ ;
else
V_49 [ V_88 ] ++ ;
V_80 = V_86 ;
break;
}
V_80 += ( 1UL << V_85 -> V_57 ) - 1 ;
}
}
F_74 ( V_67 , L_1 , V_21 -> V_71 , V_10 -> V_72 ) ;
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ )
F_74 ( V_67 , L_7 , V_49 [ V_3 ] ) ;
F_75 ( V_67 , '\n' ) ;
}
static void F_97 ( struct V_66 * V_67 , T_1 * V_21 )
{
#ifdef F_98
int V_73 ;
if ( ! F_99 ( & V_94 ) )
return;
F_100 ( NULL ) ;
F_74 ( V_67 , L_8 , L_11 ) ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
F_74 ( V_67 , L_10 , V_75 [ V_73 ] ) ;
F_75 ( V_67 , '\n' ) ;
F_68 ( V_67 , V_21 , F_87 ) ;
#endif
}
static int F_101 ( struct V_66 * V_67 , void * V_69 )
{
T_1 * V_21 = ( T_1 * ) V_69 ;
if ( ! F_102 ( V_21 -> V_71 , V_95 ) )
return 0 ;
F_74 ( V_67 , L_12 , V_96 ) ;
F_74 ( V_67 , L_13 , V_84 ) ;
F_75 ( V_67 , '\n' ) ;
F_79 ( V_67 , V_21 ) ;
F_86 ( V_67 , V_21 ) ;
F_97 ( V_67 , V_21 ) ;
return 0 ;
}
static int F_103 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_104 ( V_98 , & V_99 ) ;
}
static int F_105 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_104 ( V_98 , & V_100 ) ;
}
static void F_106 ( struct V_66 * V_67 , T_1 * V_21 ,
struct V_10 * V_10 )
{
int V_3 ;
F_74 ( V_67 , L_14 , V_21 -> V_71 , V_10 -> V_72 ) ;
F_74 ( V_67 ,
L_15
L_16
L_17
L_18
L_19
L_20
L_21
L_22 ,
F_58 ( V_10 , V_101 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_20 ( V_10 ) ,
F_58 ( V_10 , V_102 ) ,
V_10 -> V_87 ,
V_10 -> V_103 ,
V_10 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
F_74 ( V_67 , L_23 , V_104 [ V_3 ] ,
F_58 ( V_10 , V_3 ) ) ;
F_74 ( V_67 ,
L_24 ,
V_10 -> V_105 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_107 ( V_10 -> V_105 ) ; V_3 ++ )
F_74 ( V_67 , L_25 , V_10 -> V_105 [ V_3 ] ) ;
F_74 ( V_67 ,
L_26
L_27 ) ;
F_2 (i) {
struct V_27 * V_18 ;
V_18 = F_19 ( V_10 -> V_18 , V_3 ) ;
F_74 ( V_67 ,
L_28
L_29
L_30
L_31 ,
V_3 ,
V_18 -> V_28 . V_49 ,
V_18 -> V_28 . V_106 ,
V_18 -> V_28 . V_107 ) ;
#ifdef F_108
F_74 ( V_67 , L_32 ,
V_18 -> V_19 ) ;
#endif
}
F_74 ( V_67 ,
L_33
L_34
L_35 ,
! F_109 ( V_10 ) ,
V_10 -> V_82 ,
V_10 -> V_108 ) ;
F_75 ( V_67 , '\n' ) ;
}
static int F_110 ( struct V_66 * V_67 , void * V_69 )
{
T_1 * V_21 = ( T_1 * ) V_69 ;
F_68 ( V_67 , V_21 , F_106 ) ;
return 0 ;
}
static int F_111 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_104 ( V_98 , & V_109 ) ;
}
static void * F_112 ( struct V_66 * V_67 , T_4 * V_68 )
{
unsigned long * V_33 ;
int V_3 , V_110 ;
if ( * V_68 >= F_107 ( V_104 ) )
return NULL ;
V_110 = V_44 * sizeof( unsigned long ) +
V_111 * sizeof( unsigned long ) ;
#ifdef F_113
V_110 += sizeof( struct V_5 ) ;
#endif
V_33 = F_114 ( V_110 , V_112 ) ;
V_67 -> V_113 = V_33 ;
if ( ! V_33 )
return F_115 ( - V_114 ) ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ )
V_33 [ V_3 ] = F_116 ( V_3 ) ;
V_33 += V_44 ;
F_117 ( V_33 + V_115 ,
V_33 + V_116 ) ;
V_33 += V_111 ;
#ifdef F_113
F_4 ( V_33 ) ;
V_33 [ V_117 ] /= 2 ;
V_33 [ V_118 ] /= 2 ;
#endif
return ( unsigned long * ) V_67 -> V_113 + * V_68 ;
}
static void * F_118 ( struct V_66 * V_67 , void * V_69 , T_4 * V_68 )
{
( * V_68 ) ++ ;
if ( * V_68 >= F_107 ( V_104 ) )
return NULL ;
return ( unsigned long * ) V_67 -> V_113 + * V_68 ;
}
static int F_119 ( struct V_66 * V_67 , void * V_69 )
{
unsigned long * V_119 = V_69 ;
unsigned long V_120 = V_119 - ( unsigned long * ) V_67 -> V_113 ;
F_74 ( V_67 , L_36 , V_104 [ V_120 ] , * V_119 ) ;
return 0 ;
}
static void F_120 ( struct V_66 * V_67 , void * V_69 )
{
F_121 ( V_67 -> V_113 ) ;
V_67 -> V_113 = NULL ;
}
static int F_122 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_104 ( V_98 , & V_121 ) ;
}
static void F_123 ( struct V_122 * V_123 )
{
F_46 ( true ) ;
}
int F_124 ( struct V_124 * V_125 , int V_126 ,
void T_5 * V_127 , T_6 * V_128 , T_4 * V_129 )
{
long V_130 ;
int V_131 ;
int V_3 ;
V_131 = F_125 ( F_123 ) ;
if ( V_131 )
return V_131 ;
for ( V_3 = 0 ; V_3 < V_44 ; V_3 ++ ) {
V_130 = F_126 ( & V_45 [ V_3 ] ) ;
if ( V_130 < 0 ) {
switch ( V_3 ) {
case V_132 :
case V_102 :
break;
default:
F_127 ( L_37 ,
V_133 , V_104 [ V_3 ] , V_130 ) ;
V_131 = - V_134 ;
break;
}
}
}
if ( V_131 )
return V_131 ;
if ( V_126 )
* V_129 += * V_128 ;
else
* V_128 = 0 ;
return 0 ;
}
static void F_128 ( struct V_122 * V_135 )
{
if ( F_46 ( true ) ) {
F_129 ( F_130 () , V_136 ,
F_53 ( & V_137 ) ,
F_131 ( V_138 ) ) ;
}
}
static bool F_132 ( int V_2 )
{
struct V_10 * V_10 ;
F_18 (zone) {
struct V_27 * V_29 = F_19 ( V_10 -> V_18 , V_2 ) ;
F_133 ( sizeof( V_29 -> V_30 [ 0 ] ) != 1 ) ;
if ( F_134 ( V_29 -> V_30 , 0 , V_44 ) )
return true ;
}
return false ;
}
void F_135 ( void )
{
if ( V_139 != V_140 )
return;
if ( ! F_136 ( F_53 ( & V_137 ) ) )
return;
if ( ! F_132 ( F_130 () ) )
return;
F_46 ( false ) ;
}
static void F_137 ( struct V_122 * V_135 )
{
int V_2 ;
F_5 () ;
F_2 (cpu) {
struct V_141 * V_142 = & F_3 ( V_137 , V_2 ) ;
if ( ! F_136 ( V_142 ) && F_132 ( V_2 ) )
F_129 ( V_2 , V_136 , V_142 , 0 ) ;
}
F_6 () ;
F_138 ( & V_143 ,
F_131 ( V_138 ) ) ;
}
static void T_7 F_139 ( void )
{
int V_2 ;
F_140 (cpu)
F_141 ( F_19 ( & V_137 , V_2 ) ,
F_128 ) ;
V_136 = F_142 ( L_38 , V_144 | V_145 , 0 ) ;
F_138 ( & V_143 ,
F_131 ( V_138 ) ) ;
}
static void F_143 ( int V_51 )
{
int V_2 ;
F_5 () ;
F_2 (cpu)
if ( F_144 ( V_2 ) == V_51 )
goto V_146;
F_145 ( V_51 , V_147 ) ;
V_146:
F_6 () ;
}
static int F_146 ( struct V_148 * V_149 ,
unsigned long V_150 ,
void * V_151 )
{
long V_2 = ( long ) V_151 ;
switch ( V_150 ) {
case V_152 :
case V_153 :
F_17 () ;
F_147 ( F_144 ( V_2 ) , V_147 ) ;
break;
case V_154 :
case V_155 :
F_148 ( & F_3 ( V_137 , V_2 ) ) ;
break;
case V_156 :
case V_157 :
break;
case V_158 :
case V_159 :
F_17 () ;
F_143 ( F_144 ( V_2 ) ) ;
break;
default:
break;
}
return V_160 ;
}
static int T_7 F_149 ( void )
{
#ifdef F_108
F_150 () ;
F_151 ( & V_161 ) ;
F_139 () ;
F_152 () ;
#endif
#ifdef F_153
F_154 ( L_39 , V_162 , NULL , & V_163 ) ;
F_154 ( L_40 , V_162 , NULL , & V_164 ) ;
F_154 ( L_38 , V_162 , NULL , & V_165 ) ;
F_154 ( L_41 , V_162 , NULL , & V_166 ) ;
#endif
return 0 ;
}
static int F_155 ( unsigned int V_57 ,
struct V_55 * V_56 )
{
if ( V_56 -> V_58 == 0 )
return 1000 ;
return F_61 ( ( V_56 -> V_58 - ( V_56 -> V_60 << V_57 ) ) * 1000ULL , V_56 -> V_58 ) ;
}
static void F_156 ( struct V_66 * V_67 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_57 ;
int V_167 ;
struct V_55 V_56 ;
F_74 ( V_67 , L_1 ,
V_21 -> V_71 ,
V_10 -> V_72 ) ;
for ( V_57 = 0 ; V_57 < V_61 ; ++ V_57 ) {
F_59 ( V_10 , V_57 , & V_56 ) ;
V_167 = F_155 ( V_57 , & V_56 ) ;
F_74 ( V_67 , L_42 , V_167 / 1000 , V_167 % 1000 ) ;
}
F_75 ( V_67 , '\n' ) ;
}
static int F_157 ( struct V_66 * V_67 , void * V_69 )
{
T_1 * V_21 = ( T_1 * ) V_69 ;
if ( ! F_102 ( V_21 -> V_71 , V_95 ) )
return 0 ;
F_68 ( V_67 , V_21 , F_156 ) ;
return 0 ;
}
static int F_158 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_104 ( V_98 , & V_168 ) ;
}
static void F_159 ( struct V_66 * V_67 ,
T_1 * V_21 , struct V_10 * V_10 )
{
unsigned int V_57 ;
int V_167 ;
struct V_55 V_56 ;
F_74 ( V_67 , L_1 ,
V_21 -> V_71 ,
V_10 -> V_72 ) ;
for ( V_57 = 0 ; V_57 < V_61 ; ++ V_57 ) {
F_59 ( V_10 , V_57 , & V_56 ) ;
V_167 = F_60 ( V_57 , & V_56 ) ;
F_74 ( V_67 , L_42 , V_167 / 1000 , V_167 % 1000 ) ;
}
F_75 ( V_67 , '\n' ) ;
}
static int F_160 ( struct V_66 * V_67 , void * V_69 )
{
T_1 * V_21 = ( T_1 * ) V_69 ;
F_68 ( V_67 , V_21 , F_159 ) ;
return 0 ;
}
static int F_161 ( struct V_97 * V_97 , struct V_98 * V_98 )
{
return F_104 ( V_98 , & V_169 ) ;
}
static int T_7 F_162 ( void )
{
struct V_170 * V_171 ;
V_171 = F_163 ( L_43 , NULL ) ;
if ( ! V_171 )
return - V_114 ;
if ( ! F_164 ( L_44 , 0444 ,
V_171 , NULL , & V_172 ) )
goto V_173;
if ( ! F_164 ( L_45 , 0444 ,
V_171 , NULL , & V_174 ) )
goto V_173;
return 0 ;
V_173:
F_165 ( V_171 ) ;
return - V_114 ;
}
