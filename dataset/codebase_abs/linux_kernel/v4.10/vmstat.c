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
struct V_16 * V_17 ;
struct V_10 * V_10 ;
int V_2 ;
int V_11 ;
F_18 (pgdat) {
F_2 (cpu) {
F_19 ( V_17 -> V_18 , V_2 ) -> V_19 = 0 ;
}
}
F_20 (zone) {
struct V_16 * V_17 = V_10 -> V_20 ;
unsigned long V_21 , V_22 ;
V_11 = F_15 ( V_10 ) ;
F_2 (cpu) {
int V_23 ;
F_19 ( V_10 -> V_24 , V_2 ) -> V_19
= V_11 ;
V_23 = F_19 ( V_17 -> V_18 , V_2 ) -> V_19 ;
F_19 ( V_17 -> V_18 , V_2 ) -> V_19
= F_12 ( V_11 , V_23 ) ;
}
V_22 = F_10 ( V_10 ) - F_11 ( V_10 ) ;
V_21 = F_13 () * V_11 ;
if ( V_21 > V_22 )
V_10 -> V_25 = F_21 ( V_10 ) +
V_21 ;
}
}
void F_22 ( T_1 * V_17 ,
int (* F_23)( struct V_10 * ) )
{
struct V_10 * V_10 ;
int V_2 ;
int V_11 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_17 -> V_26 ; V_3 ++ ) {
V_10 = & V_17 -> V_27 [ V_3 ] ;
if ( ! V_10 -> V_25 )
continue;
V_11 = (* F_23)( V_10 ) ;
F_2 (cpu)
F_19 ( V_10 -> V_24 , V_2 ) -> V_19
= V_11 ;
}
}
void F_24 ( struct V_10 * V_10 , enum V_28 V_29 ,
long V_30 )
{
struct V_31 T_2 * V_32 = V_10 -> V_24 ;
T_3 T_2 * V_33 = V_32 -> V_34 + V_29 ;
long V_35 ;
long V_36 ;
V_35 = V_30 + F_25 ( * V_33 ) ;
V_36 = F_25 ( V_32 -> V_19 ) ;
if ( F_26 ( V_35 > V_36 || V_35 < - V_36 ) ) {
F_27 ( V_35 , V_10 , V_29 ) ;
V_35 = 0 ;
}
F_28 ( * V_33 , V_35 ) ;
}
void F_29 ( struct V_16 * V_17 , enum V_37 V_29 ,
long V_30 )
{
struct V_38 T_2 * V_32 = V_17 -> V_18 ;
T_3 T_2 * V_33 = V_32 -> V_39 + V_29 ;
long V_35 ;
long V_36 ;
V_35 = V_30 + F_25 ( * V_33 ) ;
V_36 = F_25 ( V_32 -> V_19 ) ;
if ( F_26 ( V_35 > V_36 || V_35 < - V_36 ) ) {
F_30 ( V_35 , V_17 , V_29 ) ;
V_35 = 0 ;
}
F_28 ( * V_33 , V_35 ) ;
}
void F_31 ( struct V_10 * V_10 , enum V_28 V_29 )
{
struct V_31 T_2 * V_32 = V_10 -> V_24 ;
T_3 T_2 * V_33 = V_32 -> V_34 + V_29 ;
T_3 V_40 , V_36 ;
V_40 = F_32 ( * V_33 ) ;
V_36 = F_25 ( V_32 -> V_19 ) ;
if ( F_26 ( V_40 > V_36 ) ) {
T_3 V_41 = V_36 >> 1 ;
F_27 ( V_40 + V_41 , V_10 , V_29 ) ;
F_28 ( * V_33 , - V_41 ) ;
}
}
void F_33 ( struct V_16 * V_17 , enum V_37 V_29 )
{
struct V_38 T_2 * V_32 = V_17 -> V_18 ;
T_3 T_2 * V_33 = V_32 -> V_39 + V_29 ;
T_3 V_40 , V_36 ;
V_40 = F_32 ( * V_33 ) ;
V_36 = F_25 ( V_32 -> V_19 ) ;
if ( F_26 ( V_40 > V_36 ) ) {
T_3 V_41 = V_36 >> 1 ;
F_30 ( V_40 + V_41 , V_17 , V_29 ) ;
F_28 ( * V_33 , - V_41 ) ;
}
}
void F_34 ( struct V_42 * V_42 , enum V_28 V_29 )
{
F_31 ( F_35 ( V_42 ) , V_29 ) ;
}
void F_36 ( struct V_42 * V_42 , enum V_37 V_29 )
{
F_33 ( F_37 ( V_42 ) , V_29 ) ;
}
void F_38 ( struct V_10 * V_10 , enum V_28 V_29 )
{
struct V_31 T_2 * V_32 = V_10 -> V_24 ;
T_3 T_2 * V_33 = V_32 -> V_34 + V_29 ;
T_3 V_40 , V_36 ;
V_40 = F_39 ( * V_33 ) ;
V_36 = F_25 ( V_32 -> V_19 ) ;
if ( F_26 ( V_40 < - V_36 ) ) {
T_3 V_41 = V_36 >> 1 ;
F_27 ( V_40 - V_41 , V_10 , V_29 ) ;
F_28 ( * V_33 , V_41 ) ;
}
}
void F_40 ( struct V_16 * V_17 , enum V_37 V_29 )
{
struct V_38 T_2 * V_32 = V_17 -> V_18 ;
T_3 T_2 * V_33 = V_32 -> V_39 + V_29 ;
T_3 V_40 , V_36 ;
V_40 = F_39 ( * V_33 ) ;
V_36 = F_25 ( V_32 -> V_19 ) ;
if ( F_26 ( V_40 < - V_36 ) ) {
T_3 V_41 = V_36 >> 1 ;
F_30 ( V_40 - V_41 , V_17 , V_29 ) ;
F_28 ( * V_33 , V_41 ) ;
}
}
void F_41 ( struct V_42 * V_42 , enum V_28 V_29 )
{
F_38 ( F_35 ( V_42 ) , V_29 ) ;
}
void F_42 ( struct V_42 * V_42 , enum V_37 V_29 )
{
F_40 ( F_37 ( V_42 ) , V_29 ) ;
}
static inline void F_43 ( struct V_10 * V_10 ,
enum V_28 V_29 , long V_30 , int V_43 )
{
struct V_31 T_2 * V_32 = V_10 -> V_24 ;
T_3 T_2 * V_33 = V_32 -> V_34 + V_29 ;
long V_44 , V_45 , V_36 , V_46 ;
do {
V_46 = 0 ;
V_36 = F_44 ( V_32 -> V_19 ) ;
V_44 = F_44 ( * V_33 ) ;
V_45 = V_30 + V_44 ;
if ( V_45 > V_36 || V_45 < - V_36 ) {
int V_47 = V_43 * ( V_36 >> 1 ) ;
V_46 = V_45 + V_47 ;
V_45 = - V_47 ;
}
} while ( F_45 ( * V_33 , V_44 , V_45 ) != V_44 );
if ( V_46 )
F_27 ( V_46 , V_10 , V_29 ) ;
}
void F_46 ( struct V_10 * V_10 , enum V_28 V_29 ,
long V_30 )
{
F_43 ( V_10 , V_29 , V_30 , 0 ) ;
}
void F_47 ( struct V_42 * V_42 , enum V_28 V_29 )
{
F_43 ( F_35 ( V_42 ) , V_29 , 1 , 1 ) ;
}
void F_48 ( struct V_42 * V_42 , enum V_28 V_29 )
{
F_43 ( F_35 ( V_42 ) , V_29 , - 1 , - 1 ) ;
}
static inline void F_49 ( struct V_16 * V_17 ,
enum V_37 V_29 , int V_30 , int V_43 )
{
struct V_38 T_2 * V_32 = V_17 -> V_18 ;
T_3 T_2 * V_33 = V_32 -> V_39 + V_29 ;
long V_44 , V_45 , V_36 , V_46 ;
do {
V_46 = 0 ;
V_36 = F_44 ( V_32 -> V_19 ) ;
V_44 = F_44 ( * V_33 ) ;
V_45 = V_30 + V_44 ;
if ( V_45 > V_36 || V_45 < - V_36 ) {
int V_47 = V_43 * ( V_36 >> 1 ) ;
V_46 = V_45 + V_47 ;
V_45 = - V_47 ;
}
} while ( F_45 ( * V_33 , V_44 , V_45 ) != V_44 );
if ( V_46 )
F_30 ( V_46 , V_17 , V_29 ) ;
}
void F_50 ( struct V_16 * V_17 , enum V_37 V_29 ,
long V_30 )
{
F_49 ( V_17 , V_29 , V_30 , 0 ) ;
}
void F_51 ( struct V_16 * V_17 , enum V_37 V_29 )
{
F_49 ( V_17 , V_29 , 1 , 1 ) ;
}
void F_52 ( struct V_42 * V_42 , enum V_37 V_29 )
{
F_49 ( F_37 ( V_42 ) , V_29 , 1 , 1 ) ;
}
void F_53 ( struct V_42 * V_42 , enum V_37 V_29 )
{
F_49 ( F_37 ( V_42 ) , V_29 , - 1 , - 1 ) ;
}
void F_46 ( struct V_10 * V_10 , enum V_28 V_29 ,
long V_30 )
{
unsigned long V_48 ;
F_54 ( V_48 ) ;
F_24 ( V_10 , V_29 , V_30 ) ;
F_55 ( V_48 ) ;
}
void F_47 ( struct V_42 * V_42 , enum V_28 V_29 )
{
unsigned long V_48 ;
struct V_10 * V_10 ;
V_10 = F_35 ( V_42 ) ;
F_54 ( V_48 ) ;
F_31 ( V_10 , V_29 ) ;
F_55 ( V_48 ) ;
}
void F_48 ( struct V_42 * V_42 , enum V_28 V_29 )
{
unsigned long V_48 ;
F_54 ( V_48 ) ;
F_41 ( V_42 , V_29 ) ;
F_55 ( V_48 ) ;
}
void F_51 ( struct V_16 * V_17 , enum V_37 V_29 )
{
unsigned long V_48 ;
F_54 ( V_48 ) ;
F_33 ( V_17 , V_29 ) ;
F_55 ( V_48 ) ;
}
void F_50 ( struct V_16 * V_17 , enum V_37 V_29 ,
long V_30 )
{
unsigned long V_48 ;
F_54 ( V_48 ) ;
F_29 ( V_17 , V_29 , V_30 ) ;
F_55 ( V_48 ) ;
}
void F_52 ( struct V_42 * V_42 , enum V_37 V_29 )
{
unsigned long V_48 ;
struct V_16 * V_17 ;
V_17 = F_37 ( V_42 ) ;
F_54 ( V_48 ) ;
F_33 ( V_17 , V_29 ) ;
F_55 ( V_48 ) ;
}
void F_53 ( struct V_42 * V_42 , enum V_37 V_29 )
{
unsigned long V_48 ;
F_54 ( V_48 ) ;
F_42 ( V_42 , V_29 ) ;
F_55 ( V_48 ) ;
}
static int F_56 ( int * V_49 , int * V_50 )
{
int V_3 ;
int V_51 = 0 ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
if ( V_49 [ V_3 ] ) {
F_57 ( V_49 [ V_3 ] , & V_53 [ V_3 ] ) ;
V_51 ++ ;
}
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ )
if ( V_50 [ V_3 ] ) {
F_57 ( V_50 [ V_3 ] , & V_55 [ V_3 ] ) ;
V_51 ++ ;
}
return V_51 ;
}
static int F_58 ( bool V_56 )
{
struct V_16 * V_17 ;
struct V_10 * V_10 ;
int V_3 ;
int V_57 [ V_52 ] = { 0 , } ;
int V_58 [ V_54 ] = { 0 , } ;
int V_51 = 0 ;
F_20 (zone) {
struct V_31 T_2 * V_33 = V_10 -> V_24 ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ ) {
int V_40 ;
V_40 = F_59 ( V_33 -> V_34 [ V_3 ] , 0 ) ;
if ( V_40 ) {
F_57 ( V_40 , & V_10 -> V_59 [ V_3 ] ) ;
V_57 [ V_3 ] += V_40 ;
#ifdef F_60
F_28 ( V_33 -> V_60 , 3 ) ;
#endif
}
}
#ifdef F_60
if ( V_56 ) {
F_61 () ;
if ( ! F_25 ( V_33 -> V_60 ) ||
! F_25 ( V_33 -> V_32 . V_61 ) )
continue;
if ( F_62 ( V_10 ) == F_63 () ) {
F_28 ( V_33 -> V_60 , 0 ) ;
continue;
}
if ( F_39 ( V_33 -> V_60 ) )
continue;
if ( F_25 ( V_33 -> V_32 . V_61 ) ) {
F_64 ( V_10 , F_65 ( & V_33 -> V_32 ) ) ;
V_51 ++ ;
}
}
#endif
}
F_18 (pgdat) {
struct V_38 T_2 * V_33 = V_17 -> V_18 ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ ) {
int V_40 ;
V_40 = F_59 ( V_33 -> V_39 [ V_3 ] , 0 ) ;
if ( V_40 ) {
F_57 ( V_40 , & V_17 -> V_59 [ V_3 ] ) ;
V_58 [ V_3 ] += V_40 ;
}
}
}
V_51 += F_56 ( V_57 , V_58 ) ;
return V_51 ;
}
void F_66 ( int V_2 )
{
struct V_16 * V_17 ;
struct V_10 * V_10 ;
int V_3 ;
int V_57 [ V_52 ] = { 0 , } ;
int V_58 [ V_54 ] = { 0 , } ;
F_20 (zone) {
struct V_31 * V_33 ;
V_33 = F_19 ( V_10 -> V_24 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
if ( V_33 -> V_34 [ V_3 ] ) {
int V_40 ;
V_40 = V_33 -> V_34 [ V_3 ] ;
V_33 -> V_34 [ V_3 ] = 0 ;
F_57 ( V_40 , & V_10 -> V_59 [ V_3 ] ) ;
V_57 [ V_3 ] += V_40 ;
}
}
F_18 (pgdat) {
struct V_38 * V_33 ;
V_33 = F_19 ( V_17 -> V_18 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ )
if ( V_33 -> V_39 [ V_3 ] ) {
int V_40 ;
V_40 = V_33 -> V_39 [ V_3 ] ;
V_33 -> V_39 [ V_3 ] = 0 ;
F_57 ( V_40 , & V_17 -> V_59 [ V_3 ] ) ;
V_58 [ V_3 ] += V_40 ;
}
}
F_56 ( V_57 , V_58 ) ;
}
void F_67 ( struct V_10 * V_10 , struct V_31 * V_62 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
if ( V_62 -> V_34 [ V_3 ] ) {
int V_40 = V_62 -> V_34 [ V_3 ] ;
V_62 -> V_34 [ V_3 ] = 0 ;
F_57 ( V_40 , & V_10 -> V_59 [ V_3 ] ) ;
F_57 ( V_40 , & V_53 [ V_3 ] ) ;
}
}
unsigned long F_68 ( int V_63 ,
enum V_28 V_29 )
{
struct V_10 * V_64 = F_69 ( V_63 ) -> V_27 ;
int V_3 ;
unsigned long V_61 = 0 ;
for ( V_3 = 0 ; V_3 < V_65 ; V_3 ++ )
V_61 += F_70 ( V_64 + V_3 , V_29 ) ;
return V_61 ;
}
unsigned long F_71 ( struct V_16 * V_17 ,
enum V_37 V_29 )
{
long V_35 = F_72 ( & V_17 -> V_59 [ V_29 ] ) ;
#ifdef F_73
if ( V_35 < 0 )
V_35 = 0 ;
#endif
return V_35 ;
}
static void F_74 ( struct V_10 * V_10 ,
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
static int F_75 ( unsigned int V_69 , struct V_67 * V_68 )
{
unsigned long V_77 = 1UL << V_69 ;
if ( ! V_68 -> V_71 )
return 0 ;
if ( V_68 -> V_72 )
return - 1000 ;
return 1000 - F_76 ( ( 1000 + ( F_76 ( V_68 -> V_70 * 1000ULL , V_77 ) ) ) , V_68 -> V_71 ) ;
}
int F_77 ( struct V_10 * V_10 , unsigned int V_69 )
{
struct V_67 V_68 ;
F_74 ( V_10 , V_69 , & V_68 ) ;
return F_75 ( V_69 , & V_68 ) ;
}
static void * F_78 ( struct V_78 * V_79 , T_4 * V_80 )
{
T_1 * V_17 ;
T_4 V_63 = * V_80 ;
for ( V_17 = F_79 () ;
V_17 && V_63 ;
V_17 = F_80 ( V_17 ) )
-- V_63 ;
return V_17 ;
}
static void * F_81 ( struct V_78 * V_79 , void * V_81 , T_4 * V_80 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
( * V_80 ) ++ ;
return F_80 ( V_17 ) ;
}
static void F_82 ( struct V_78 * V_79 , void * V_81 )
{
}
static void F_83 ( struct V_78 * V_79 , T_1 * V_17 ,
void (* F_84)( struct V_78 * V_79 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_27 = V_17 -> V_27 ;
unsigned long V_48 ;
for ( V_10 = V_27 ; V_10 - V_27 < V_65 ; ++ V_10 ) {
if ( ! F_85 ( V_10 ) )
continue;
F_86 ( & V_10 -> V_82 , V_48 ) ;
F_84 ( V_79 , V_17 , V_10 ) ;
F_87 ( & V_10 -> V_82 , V_48 ) ;
}
}
static void F_88 ( struct V_78 * V_79 , T_1 * V_17 ,
struct V_10 * V_10 )
{
int V_69 ;
F_89 ( V_79 , L_1 , V_17 -> V_83 , V_10 -> V_84 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 )
F_89 ( V_79 , L_2 , V_10 -> V_75 [ V_69 ] . V_76 ) ;
F_90 ( V_79 , '\n' ) ;
}
static int F_91 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
F_83 ( V_79 , V_17 , F_88 ) ;
return 0 ;
}
static void F_92 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
int V_69 , V_85 ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ ) {
F_89 ( V_79 , L_3 ,
V_17 -> V_83 ,
V_10 -> V_84 ,
V_87 [ V_85 ] ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
unsigned long V_88 = 0 ;
struct V_75 * V_89 ;
struct V_90 * V_91 ;
V_89 = & ( V_10 -> V_75 [ V_69 ] ) ;
F_93 (curr, &area->free_list[mtype])
V_88 ++ ;
F_89 ( V_79 , L_2 , V_88 ) ;
}
F_90 ( V_79 , '\n' ) ;
}
}
static int F_94 ( struct V_78 * V_79 , void * V_81 )
{
int V_69 ;
T_1 * V_17 = ( T_1 * ) V_81 ;
F_89 ( V_79 , L_4 , L_5 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 )
F_89 ( V_79 , L_6 , V_69 ) ;
F_90 ( V_79 , '\n' ) ;
F_83 ( V_79 , V_17 , F_92 ) ;
return 0 ;
}
static void F_95 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
int V_85 ;
unsigned long V_92 ;
unsigned long V_93 = V_10 -> V_94 ;
unsigned long V_95 = F_96 ( V_10 ) ;
unsigned long V_61 [ V_86 ] = { 0 , } ;
for ( V_92 = V_93 ; V_92 < V_95 ; V_92 += V_96 ) {
struct V_42 * V_42 ;
if ( ! F_97 ( V_92 ) )
continue;
V_42 = F_98 ( V_92 ) ;
if ( ! F_99 ( V_92 , V_42 , V_10 ) )
continue;
if ( F_35 ( V_42 ) != V_10 )
continue;
V_85 = F_100 ( V_42 ) ;
if ( V_85 < V_86 )
V_61 [ V_85 ] ++ ;
}
F_89 ( V_79 , L_1 , V_17 -> V_83 , V_10 -> V_84 ) ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
F_89 ( V_79 , L_7 , V_61 [ V_85 ] ) ;
F_90 ( V_79 , '\n' ) ;
}
static int F_101 ( struct V_78 * V_79 , void * V_81 )
{
int V_85 ;
T_1 * V_17 = ( T_1 * ) V_81 ;
F_89 ( V_79 , L_8 , L_9 ) ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
F_89 ( V_79 , L_10 , V_87 [ V_85 ] ) ;
F_90 ( V_79 , '\n' ) ;
F_83 ( V_79 , V_17 , F_95 ) ;
return 0 ;
}
static void F_102 ( struct V_78 * V_79 , T_1 * V_17 )
{
#ifdef F_103
int V_85 ;
if ( ! F_104 ( & V_97 ) )
return;
F_105 ( NULL ) ;
F_89 ( V_79 , L_8 , L_11 ) ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
F_89 ( V_79 , L_10 , V_87 [ V_85 ] ) ;
F_90 ( V_79 , '\n' ) ;
F_83 ( V_79 , V_17 , V_98 ) ;
#endif
}
static int F_106 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
if ( ! F_107 ( V_17 -> V_83 , V_99 ) )
return 0 ;
F_89 ( V_79 , L_12 , V_100 ) ;
F_89 ( V_79 , L_13 , V_96 ) ;
F_90 ( V_79 , '\n' ) ;
F_94 ( V_79 , V_17 ) ;
F_101 ( V_79 , V_17 ) ;
F_102 ( V_79 , V_17 ) ;
return 0 ;
}
static int F_108 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
return F_109 ( V_102 , & V_103 ) ;
}
static int F_110 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
return F_109 ( V_102 , & V_104 ) ;
}
static bool F_111 ( T_1 * V_17 , struct V_10 * V_10 )
{
int V_105 ;
for ( V_105 = 0 ; V_105 < V_65 ; V_105 ++ ) {
struct V_10 * V_106 = & V_17 -> V_27 [ V_105 ] ;
if ( F_85 ( V_106 ) )
return V_10 == V_106 ;
}
F_112 ( 1 ) ;
return false ;
}
static void F_113 ( struct V_78 * V_79 , T_1 * V_17 ,
struct V_10 * V_10 )
{
int V_3 ;
F_89 ( V_79 , L_14 , V_17 -> V_83 , V_10 -> V_84 ) ;
if ( F_111 ( V_17 , V_10 ) ) {
F_89 ( V_79 , L_15 ) ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ ) {
F_89 ( V_79 , L_16 ,
V_107 [ V_3 + V_52 ] ,
F_71 ( V_17 , V_3 ) ) ;
}
}
F_89 ( V_79 ,
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24 ,
F_70 ( V_10 , V_108 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_21 ( V_10 ) ,
F_71 ( V_10 -> V_20 , V_109 ) ,
V_10 -> V_110 ,
V_10 -> V_111 ,
V_10 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
F_89 ( V_79 , L_16 , V_107 [ V_3 ] ,
F_70 ( V_10 , V_3 ) ) ;
F_89 ( V_79 ,
L_25 ,
V_10 -> V_112 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_114 ( V_10 -> V_112 ) ; V_3 ++ )
F_89 ( V_79 , L_26 , V_10 -> V_112 [ V_3 ] ) ;
F_89 ( V_79 ,
L_27
L_28 ) ;
F_2 (i) {
struct V_31 * V_24 ;
V_24 = F_19 ( V_10 -> V_24 , V_3 ) ;
F_89 ( V_79 ,
L_29
L_30
L_31
L_32 ,
V_3 ,
V_24 -> V_32 . V_61 ,
V_24 -> V_32 . V_113 ,
V_24 -> V_32 . V_114 ) ;
#ifdef F_73
F_89 ( V_79 , L_33 ,
V_24 -> V_19 ) ;
#endif
}
F_89 ( V_79 ,
L_34
L_35
L_36 ,
! F_115 ( V_10 -> V_20 ) ,
V_10 -> V_94 ,
V_10 -> V_20 -> V_115 ) ;
F_90 ( V_79 , '\n' ) ;
}
static int F_116 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
F_83 ( V_79 , V_17 , F_113 ) ;
return 0 ;
}
static int F_117 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
return F_109 ( V_102 , & V_116 ) ;
}
static void * F_118 ( struct V_78 * V_79 , T_4 * V_80 )
{
unsigned long * V_40 ;
int V_3 , V_117 ;
if ( * V_80 >= F_114 ( V_107 ) )
return NULL ;
V_117 = V_52 * sizeof( unsigned long ) +
V_54 * sizeof( unsigned long ) +
V_118 * sizeof( unsigned long ) ;
#ifdef F_119
V_117 += sizeof( struct V_5 ) ;
#endif
V_40 = F_120 ( V_117 , V_119 ) ;
V_79 -> V_120 = V_40 ;
if ( ! V_40 )
return F_121 ( - V_121 ) ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
V_40 [ V_3 ] = F_122 ( V_3 ) ;
V_40 += V_52 ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ )
V_40 [ V_3 ] = F_123 ( V_3 ) ;
V_40 += V_54 ;
F_124 ( V_40 + V_122 ,
V_40 + V_123 ) ;
V_40 += V_118 ;
#ifdef F_119
F_4 ( V_40 ) ;
V_40 [ V_124 ] /= 2 ;
V_40 [ V_125 ] /= 2 ;
#endif
return ( unsigned long * ) V_79 -> V_120 + * V_80 ;
}
static void * F_125 ( struct V_78 * V_79 , void * V_81 , T_4 * V_80 )
{
( * V_80 ) ++ ;
if ( * V_80 >= F_114 ( V_107 ) )
return NULL ;
return ( unsigned long * ) V_79 -> V_120 + * V_80 ;
}
static int F_126 ( struct V_78 * V_79 , void * V_81 )
{
unsigned long * V_126 = V_81 ;
unsigned long V_127 = V_126 - ( unsigned long * ) V_79 -> V_120 ;
F_127 ( V_79 , V_107 [ V_127 ] ) ;
F_128 ( V_79 , L_37 , * V_126 ) ;
F_90 ( V_79 , '\n' ) ;
return 0 ;
}
static void F_129 ( struct V_78 * V_79 , void * V_81 )
{
F_130 ( V_79 -> V_120 ) ;
V_79 -> V_120 = NULL ;
}
static int F_131 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
return F_109 ( V_102 , & V_128 ) ;
}
static void F_132 ( struct V_129 * V_130 )
{
F_58 ( true ) ;
}
int F_133 ( struct V_131 * V_132 , int V_133 ,
void T_5 * V_134 , T_6 * V_135 , T_4 * V_136 )
{
long V_137 ;
int V_138 ;
int V_3 ;
V_138 = F_134 ( F_132 ) ;
if ( V_138 )
return V_138 ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ ) {
V_137 = F_72 ( & V_53 [ V_3 ] ) ;
if ( V_137 < 0 ) {
switch ( V_3 ) {
case V_109 :
break;
default:
F_135 ( L_38 ,
V_139 , V_107 [ V_3 ] , V_137 ) ;
V_138 = - V_140 ;
break;
}
}
}
if ( V_138 )
return V_138 ;
if ( V_133 )
* V_136 += * V_135 ;
else
* V_135 = 0 ;
return 0 ;
}
static void F_136 ( struct V_129 * V_141 )
{
if ( F_58 ( true ) ) {
F_137 ( F_138 () , V_142 ,
F_65 ( & V_143 ) ,
F_139 ( V_144 ) ) ;
}
}
static bool F_140 ( int V_2 )
{
struct V_10 * V_10 ;
F_20 (zone) {
struct V_31 * V_33 = F_19 ( V_10 -> V_24 , V_2 ) ;
F_141 ( sizeof( V_33 -> V_34 [ 0 ] ) != 1 ) ;
if ( F_142 ( V_33 -> V_34 , 0 , V_52 ) )
return true ;
}
return false ;
}
void F_143 ( void )
{
if ( V_145 != V_146 )
return;
if ( ! F_144 ( F_65 ( & V_143 ) ) )
return;
if ( ! F_140 ( F_138 () ) )
return;
F_58 ( false ) ;
}
static void F_145 ( struct V_129 * V_141 )
{
int V_2 ;
F_5 () ;
F_2 (cpu) {
struct V_147 * V_148 = & F_3 ( V_143 , V_2 ) ;
if ( ! F_144 ( V_148 ) && F_140 ( V_2 ) )
F_137 ( V_2 , V_142 , V_148 , 0 ) ;
}
F_6 () ;
F_146 ( & V_149 ,
F_139 ( V_144 ) ) ;
}
static void T_7 F_147 ( void )
{
int V_2 ;
F_148 (cpu)
F_149 ( F_19 ( & V_143 , V_2 ) ,
F_136 ) ;
V_142 = F_150 ( L_39 , V_150 | V_151 , 0 ) ;
F_146 ( & V_149 ,
F_139 ( V_144 ) ) ;
}
static void T_7 F_151 ( void )
{
int V_63 ;
F_152 (node) {
if ( F_153 ( F_154 ( V_63 ) ) > 0 )
F_155 ( V_63 , V_152 ) ;
}
}
static int F_156 ( unsigned int V_2 )
{
F_17 () ;
F_155 ( F_157 ( V_2 ) , V_152 ) ;
return 0 ;
}
static int F_158 ( unsigned int V_2 )
{
F_159 ( & F_3 ( V_143 , V_2 ) ) ;
return 0 ;
}
static int F_160 ( unsigned int V_2 )
{
const struct V_153 * V_154 ;
int V_63 ;
V_63 = F_157 ( V_2 ) ;
F_17 () ;
V_154 = F_154 ( V_63 ) ;
if ( F_153 ( V_154 ) > 0 )
return 0 ;
F_161 ( V_63 , V_152 ) ;
return 0 ;
}
static int T_7 F_162 ( void )
{
#ifdef F_73
int V_1 ;
V_1 = F_163 ( V_155 , L_40 ,
NULL , F_160 ) ;
if ( V_1 < 0 )
F_164 ( L_41 ) ;
V_1 = F_163 ( V_156 , L_42 ,
F_156 ,
F_158 ) ;
if ( V_1 < 0 )
F_164 ( L_43 ) ;
F_5 () ;
F_151 () ;
F_6 () ;
F_147 () ;
#endif
#ifdef F_165
F_166 ( L_44 , V_157 , NULL , & V_158 ) ;
F_166 ( L_45 , V_157 , NULL , & V_159 ) ;
F_166 ( L_39 , V_157 , NULL , & V_160 ) ;
F_166 ( L_46 , V_157 , NULL , & V_161 ) ;
#endif
return 0 ;
}
static int F_167 ( unsigned int V_69 ,
struct V_67 * V_68 )
{
if ( V_68 -> V_70 == 0 )
return 1000 ;
return F_76 ( ( V_68 -> V_70 - ( V_68 -> V_72 << V_69 ) ) * 1000ULL , V_68 -> V_70 ) ;
}
static void F_168 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
unsigned int V_69 ;
int V_162 ;
struct V_67 V_68 ;
F_89 ( V_79 , L_1 ,
V_17 -> V_83 ,
V_10 -> V_84 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
F_74 ( V_10 , V_69 , & V_68 ) ;
V_162 = F_167 ( V_69 , & V_68 ) ;
F_89 ( V_79 , L_47 , V_162 / 1000 , V_162 % 1000 ) ;
}
F_90 ( V_79 , '\n' ) ;
}
static int F_169 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
if ( ! F_107 ( V_17 -> V_83 , V_99 ) )
return 0 ;
F_83 ( V_79 , V_17 , F_168 ) ;
return 0 ;
}
static int F_170 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
return F_109 ( V_102 , & V_163 ) ;
}
static void F_171 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
unsigned int V_69 ;
int V_162 ;
struct V_67 V_68 ;
F_89 ( V_79 , L_1 ,
V_17 -> V_83 ,
V_10 -> V_84 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
F_74 ( V_10 , V_69 , & V_68 ) ;
V_162 = F_75 ( V_69 , & V_68 ) ;
F_89 ( V_79 , L_47 , V_162 / 1000 , V_162 % 1000 ) ;
}
F_90 ( V_79 , '\n' ) ;
}
static int F_172 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
F_83 ( V_79 , V_17 , F_171 ) ;
return 0 ;
}
static int F_173 ( struct V_101 * V_101 , struct V_102 * V_102 )
{
return F_109 ( V_102 , & V_164 ) ;
}
static int T_7 F_174 ( void )
{
struct V_165 * V_166 ;
V_166 = F_175 ( L_48 , NULL ) ;
if ( ! V_166 )
return - V_121 ;
if ( ! F_176 ( L_49 , 0444 ,
V_166 , NULL , & V_167 ) )
goto V_168;
if ( ! F_176 ( L_50 , 0444 ,
V_166 , NULL , & V_169 ) )
goto V_168;
return 0 ;
V_168:
F_177 ( V_166 ) ;
return - V_121 ;
}
