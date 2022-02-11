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
static void F_102 ( struct V_78 * V_79 ,
T_1 * V_17 ,
struct V_10 * V_10 )
{
struct V_42 * V_42 ;
struct V_97 * V_97 ;
unsigned long V_92 = V_10 -> V_94 , V_98 ;
unsigned long V_95 = V_92 + V_10 -> V_99 ;
unsigned long V_61 [ V_86 ] = { 0 , } ;
int V_100 , V_101 ;
int V_3 ;
V_92 = V_10 -> V_94 ;
for (; V_92 < V_95 ; ) {
if ( ! F_97 ( V_92 ) ) {
V_92 = F_103 ( V_92 + 1 , V_102 ) ;
continue;
}
V_98 = F_103 ( V_92 + 1 , V_96 ) ;
V_98 = F_14 ( V_98 , V_95 ) ;
V_42 = F_98 ( V_92 ) ;
V_100 = F_100 ( V_42 ) ;
for (; V_92 < V_98 ; V_92 ++ ) {
if ( ! F_104 ( V_92 ) )
continue;
V_42 = F_98 ( V_92 ) ;
if ( F_35 ( V_42 ) != V_10 )
continue;
if ( F_105 ( V_42 ) ) {
V_92 += ( 1UL << F_106 ( V_42 ) ) - 1 ;
continue;
}
if ( F_107 ( V_42 ) )
continue;
V_97 = F_108 ( V_42 ) ;
if ( F_26 ( ! V_97 ) )
continue;
if ( ! F_109 ( V_103 , & V_97 -> V_48 ) )
continue;
V_101 = F_110 ( V_97 -> V_104 ) ;
if ( V_100 != V_101 ) {
if ( F_111 ( V_100 ) )
V_61 [ V_105 ] ++ ;
else
V_61 [ V_100 ] ++ ;
V_92 = V_98 ;
break;
}
V_92 += ( 1UL << V_97 -> V_69 ) - 1 ;
}
}
F_89 ( V_79 , L_1 , V_17 -> V_83 , V_10 -> V_84 ) ;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ )
F_89 ( V_79 , L_7 , V_61 [ V_3 ] ) ;
F_90 ( V_79 , '\n' ) ;
}
static void F_112 ( struct V_78 * V_79 , T_1 * V_17 )
{
#ifdef F_113
int V_85 ;
if ( ! F_114 ( & V_106 ) )
return;
F_115 ( NULL ) ;
F_89 ( V_79 , L_8 , L_11 ) ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
F_89 ( V_79 , L_10 , V_87 [ V_85 ] ) ;
F_90 ( V_79 , '\n' ) ;
F_83 ( V_79 , V_17 , F_102 ) ;
#endif
}
static int F_116 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
if ( ! F_117 ( V_17 -> V_83 , V_107 ) )
return 0 ;
F_89 ( V_79 , L_12 , V_108 ) ;
F_89 ( V_79 , L_13 , V_96 ) ;
F_90 ( V_79 , '\n' ) ;
F_94 ( V_79 , V_17 ) ;
F_101 ( V_79 , V_17 ) ;
F_112 ( V_79 , V_17 ) ;
return 0 ;
}
static int F_118 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_119 ( V_110 , & V_111 ) ;
}
static int F_120 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_119 ( V_110 , & V_112 ) ;
}
static bool F_121 ( T_1 * V_17 , struct V_10 * V_10 )
{
int V_113 ;
for ( V_113 = 0 ; V_113 < V_65 ; V_113 ++ ) {
struct V_10 * V_114 = & V_17 -> V_27 [ V_113 ] ;
if ( F_85 ( V_114 ) )
return V_10 == V_114 ;
}
F_122 ( 1 ) ;
return false ;
}
static void F_123 ( struct V_78 * V_79 , T_1 * V_17 ,
struct V_10 * V_10 )
{
int V_3 ;
F_89 ( V_79 , L_14 , V_17 -> V_83 , V_10 -> V_84 ) ;
if ( F_121 ( V_17 , V_10 ) ) {
F_89 ( V_79 , L_15 ) ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ ) {
F_89 ( V_79 , L_16 ,
V_115 [ V_3 + V_52 ] ,
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
F_70 ( V_10 , V_116 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_21 ( V_10 ) ,
F_71 ( V_10 -> V_20 , V_117 ) ,
V_10 -> V_99 ,
V_10 -> V_118 ,
V_10 -> V_14 ) ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
F_89 ( V_79 , L_16 , V_115 [ V_3 ] ,
F_70 ( V_10 , V_3 ) ) ;
F_89 ( V_79 ,
L_25 ,
V_10 -> V_119 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_124 ( V_10 -> V_119 ) ; V_3 ++ )
F_89 ( V_79 , L_26 , V_10 -> V_119 [ V_3 ] ) ;
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
V_24 -> V_32 . V_120 ,
V_24 -> V_32 . V_121 ) ;
#ifdef F_73
F_89 ( V_79 , L_33 ,
V_24 -> V_19 ) ;
#endif
}
F_89 ( V_79 ,
L_34
L_35
L_36 ,
! F_125 ( V_10 -> V_20 ) ,
V_10 -> V_94 ,
V_10 -> V_20 -> V_122 ) ;
F_90 ( V_79 , '\n' ) ;
}
static int F_126 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
F_83 ( V_79 , V_17 , F_123 ) ;
return 0 ;
}
static int F_127 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_119 ( V_110 , & V_123 ) ;
}
static void * F_128 ( struct V_78 * V_79 , T_4 * V_80 )
{
unsigned long * V_40 ;
int V_3 , V_124 ;
if ( * V_80 >= F_124 ( V_115 ) )
return NULL ;
V_124 = V_52 * sizeof( unsigned long ) +
V_54 * sizeof( unsigned long ) +
V_125 * sizeof( unsigned long ) ;
#ifdef F_129
V_124 += sizeof( struct V_5 ) ;
#endif
V_40 = F_130 ( V_124 , V_126 ) ;
V_79 -> V_127 = V_40 ;
if ( ! V_40 )
return F_131 ( - V_128 ) ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
V_40 [ V_3 ] = F_132 ( V_3 ) ;
V_40 += V_52 ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ )
V_40 [ V_3 ] = F_133 ( V_3 ) ;
V_40 += V_54 ;
F_134 ( V_40 + V_129 ,
V_40 + V_130 ) ;
V_40 += V_125 ;
#ifdef F_129
F_4 ( V_40 ) ;
V_40 [ V_131 ] /= 2 ;
V_40 [ V_132 ] /= 2 ;
#endif
return ( unsigned long * ) V_79 -> V_127 + * V_80 ;
}
static void * F_135 ( struct V_78 * V_79 , void * V_81 , T_4 * V_80 )
{
( * V_80 ) ++ ;
if ( * V_80 >= F_124 ( V_115 ) )
return NULL ;
return ( unsigned long * ) V_79 -> V_127 + * V_80 ;
}
static int F_136 ( struct V_78 * V_79 , void * V_81 )
{
unsigned long * V_133 = V_81 ;
unsigned long V_134 = V_133 - ( unsigned long * ) V_79 -> V_127 ;
F_89 ( V_79 , L_37 , V_115 [ V_134 ] , * V_133 ) ;
return 0 ;
}
static void F_137 ( struct V_78 * V_79 , void * V_81 )
{
F_138 ( V_79 -> V_127 ) ;
V_79 -> V_127 = NULL ;
}
static int F_139 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_119 ( V_110 , & V_135 ) ;
}
static void F_140 ( struct V_136 * V_137 )
{
F_58 ( true ) ;
}
int F_141 ( struct V_138 * V_139 , int V_140 ,
void T_5 * V_141 , T_6 * V_142 , T_4 * V_143 )
{
long V_144 ;
int V_145 ;
int V_3 ;
V_145 = F_142 ( F_140 ) ;
if ( V_145 )
return V_145 ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ ) {
V_144 = F_72 ( & V_53 [ V_3 ] ) ;
if ( V_144 < 0 ) {
switch ( V_3 ) {
case V_117 :
break;
default:
F_143 ( L_38 ,
V_146 , V_115 [ V_3 ] , V_144 ) ;
V_145 = - V_147 ;
break;
}
}
}
if ( V_145 )
return V_145 ;
if ( V_140 )
* V_143 += * V_142 ;
else
* V_142 = 0 ;
return 0 ;
}
static void F_144 ( struct V_136 * V_148 )
{
if ( F_58 ( true ) ) {
F_145 ( F_146 () , V_149 ,
F_65 ( & V_150 ) ,
F_147 ( V_151 ) ) ;
}
}
static bool F_148 ( int V_2 )
{
struct V_10 * V_10 ;
F_20 (zone) {
struct V_31 * V_33 = F_19 ( V_10 -> V_24 , V_2 ) ;
F_149 ( sizeof( V_33 -> V_34 [ 0 ] ) != 1 ) ;
if ( F_150 ( V_33 -> V_34 , 0 , V_52 ) )
return true ;
}
return false ;
}
void F_151 ( void )
{
if ( V_152 != V_153 )
return;
if ( ! F_152 ( F_65 ( & V_150 ) ) )
return;
if ( ! F_148 ( F_146 () ) )
return;
F_58 ( false ) ;
}
static void F_153 ( struct V_136 * V_148 )
{
int V_2 ;
F_5 () ;
F_2 (cpu) {
struct V_154 * V_155 = & F_3 ( V_150 , V_2 ) ;
if ( ! F_152 ( V_155 ) && F_148 ( V_2 ) )
F_145 ( V_2 , V_149 , V_155 , 0 ) ;
}
F_6 () ;
F_154 ( & V_156 ,
F_147 ( V_151 ) ) ;
}
static void T_7 F_155 ( void )
{
int V_2 ;
F_156 (cpu)
F_157 ( F_19 ( & V_150 , V_2 ) ,
F_144 ) ;
V_149 = F_158 ( L_39 , V_157 | V_158 , 0 ) ;
F_154 ( & V_156 ,
F_147 ( V_151 ) ) ;
}
static void F_159 ( int V_63 )
{
int V_2 ;
F_5 () ;
F_2 (cpu)
if ( F_160 ( V_2 ) == V_63 )
goto V_159;
F_161 ( V_63 , V_160 ) ;
V_159:
F_6 () ;
}
static int F_162 ( struct V_161 * V_162 ,
unsigned long V_163 ,
void * V_164 )
{
long V_2 = ( long ) V_164 ;
switch ( V_163 ) {
case V_165 :
case V_166 :
F_17 () ;
F_163 ( F_160 ( V_2 ) , V_160 ) ;
break;
case V_167 :
case V_168 :
F_164 ( & F_3 ( V_150 , V_2 ) ) ;
break;
case V_169 :
case V_170 :
break;
case V_171 :
case V_172 :
F_17 () ;
F_159 ( F_160 ( V_2 ) ) ;
break;
default:
break;
}
return V_173 ;
}
static int T_7 F_165 ( void )
{
#ifdef F_73
F_166 () ;
F_167 ( & V_174 ) ;
F_155 () ;
F_168 () ;
#endif
#ifdef F_169
F_170 ( L_40 , V_175 , NULL , & V_176 ) ;
F_170 ( L_41 , V_175 , NULL , & V_177 ) ;
F_170 ( L_39 , V_175 , NULL , & V_178 ) ;
F_170 ( L_42 , V_175 , NULL , & V_179 ) ;
#endif
return 0 ;
}
static int F_171 ( unsigned int V_69 ,
struct V_67 * V_68 )
{
if ( V_68 -> V_70 == 0 )
return 1000 ;
return F_76 ( ( V_68 -> V_70 - ( V_68 -> V_72 << V_69 ) ) * 1000ULL , V_68 -> V_70 ) ;
}
static void F_172 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
unsigned int V_69 ;
int V_180 ;
struct V_67 V_68 ;
F_89 ( V_79 , L_1 ,
V_17 -> V_83 ,
V_10 -> V_84 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
F_74 ( V_10 , V_69 , & V_68 ) ;
V_180 = F_171 ( V_69 , & V_68 ) ;
F_89 ( V_79 , L_43 , V_180 / 1000 , V_180 % 1000 ) ;
}
F_90 ( V_79 , '\n' ) ;
}
static int F_173 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
if ( ! F_117 ( V_17 -> V_83 , V_107 ) )
return 0 ;
F_83 ( V_79 , V_17 , F_172 ) ;
return 0 ;
}
static int F_174 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_119 ( V_110 , & V_181 ) ;
}
static void F_175 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
unsigned int V_69 ;
int V_180 ;
struct V_67 V_68 ;
F_89 ( V_79 , L_1 ,
V_17 -> V_83 ,
V_10 -> V_84 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
F_74 ( V_10 , V_69 , & V_68 ) ;
V_180 = F_75 ( V_69 , & V_68 ) ;
F_89 ( V_79 , L_43 , V_180 / 1000 , V_180 % 1000 ) ;
}
F_90 ( V_79 , '\n' ) ;
}
static int F_176 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
F_83 ( V_79 , V_17 , F_175 ) ;
return 0 ;
}
static int F_177 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
return F_119 ( V_110 , & V_182 ) ;
}
static int T_7 F_178 ( void )
{
struct V_183 * V_184 ;
V_184 = F_179 ( L_44 , NULL ) ;
if ( ! V_184 )
return - V_128 ;
if ( ! F_180 ( L_45 , 0444 ,
V_184 , NULL , & V_185 ) )
goto V_186;
if ( ! F_180 ( L_46 , 0444 ,
V_184 , NULL , & V_187 ) )
goto V_186;
return 0 ;
V_186:
F_181 ( V_184 ) ;
return - V_128 ;
}
