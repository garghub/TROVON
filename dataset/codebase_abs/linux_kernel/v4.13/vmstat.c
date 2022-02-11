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
bool V_82 , bool V_83 ,
void (* F_84)( struct V_78 * V_79 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_27 = V_17 -> V_27 ;
unsigned long V_48 ;
for ( V_10 = V_27 ; V_10 - V_27 < V_65 ; ++ V_10 ) {
if ( V_82 && ! F_85 ( V_10 ) )
continue;
if ( ! V_83 )
F_86 ( & V_10 -> V_84 , V_48 ) ;
F_84 ( V_79 , V_17 , V_10 ) ;
if ( ! V_83 )
F_87 ( & V_10 -> V_84 , V_48 ) ;
}
}
static void F_88 ( struct V_78 * V_79 , T_1 * V_17 ,
struct V_10 * V_10 )
{
int V_69 ;
F_89 ( V_79 , L_1 , V_17 -> V_85 , V_10 -> V_86 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 )
F_89 ( V_79 , L_2 , V_10 -> V_75 [ V_69 ] . V_76 ) ;
F_90 ( V_79 , '\n' ) ;
}
static int F_91 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
F_83 ( V_79 , V_17 , true , false , F_88 ) ;
return 0 ;
}
static void F_92 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
int V_69 , V_87 ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ ) {
F_89 ( V_79 , L_3 ,
V_17 -> V_85 ,
V_10 -> V_86 ,
V_89 [ V_87 ] ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
unsigned long V_90 = 0 ;
struct V_75 * V_91 ;
struct V_92 * V_93 ;
V_91 = & ( V_10 -> V_75 [ V_69 ] ) ;
F_93 (curr, &area->free_list[mtype])
V_90 ++ ;
F_89 ( V_79 , L_2 , V_90 ) ;
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
F_83 ( V_79 , V_17 , true , false , F_92 ) ;
return 0 ;
}
static void F_95 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
int V_87 ;
unsigned long V_94 ;
unsigned long V_95 = V_10 -> V_96 ;
unsigned long V_97 = F_96 ( V_10 ) ;
unsigned long V_61 [ V_88 ] = { 0 , } ;
for ( V_94 = V_95 ; V_94 < V_97 ; V_94 += V_98 ) {
struct V_42 * V_42 ;
V_42 = F_97 ( V_94 ) ;
if ( ! V_42 )
continue;
if ( ! F_98 ( V_94 , V_42 , V_10 ) )
continue;
if ( F_35 ( V_42 ) != V_10 )
continue;
V_87 = F_99 ( V_42 ) ;
if ( V_87 < V_88 )
V_61 [ V_87 ] ++ ;
}
F_89 ( V_79 , L_1 , V_17 -> V_85 , V_10 -> V_86 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
F_89 ( V_79 , L_7 , V_61 [ V_87 ] ) ;
F_90 ( V_79 , '\n' ) ;
}
static int F_100 ( struct V_78 * V_79 , void * V_81 )
{
int V_87 ;
T_1 * V_17 = ( T_1 * ) V_81 ;
F_89 ( V_79 , L_8 , L_9 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
F_89 ( V_79 , L_10 , V_89 [ V_87 ] ) ;
F_90 ( V_79 , '\n' ) ;
F_83 ( V_79 , V_17 , true , false ,
F_95 ) ;
return 0 ;
}
static void F_101 ( struct V_78 * V_79 , T_1 * V_17 )
{
#ifdef F_102
int V_87 ;
if ( ! F_103 ( & V_99 ) )
return;
F_104 ( NULL ) ;
F_89 ( V_79 , L_8 , L_11 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
F_89 ( V_79 , L_10 , V_89 [ V_87 ] ) ;
F_90 ( V_79 , '\n' ) ;
F_83 ( V_79 , V_17 , true , true ,
V_100 ) ;
#endif
}
static int F_105 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
if ( ! F_106 ( V_17 -> V_85 , V_101 ) )
return 0 ;
F_89 ( V_79 , L_12 , V_102 ) ;
F_89 ( V_79 , L_13 , V_98 ) ;
F_90 ( V_79 , '\n' ) ;
F_94 ( V_79 , V_17 ) ;
F_100 ( V_79 , V_17 ) ;
F_101 ( V_79 , V_17 ) ;
return 0 ;
}
static int F_107 ( struct V_103 * V_103 , struct V_104 * V_104 )
{
return F_108 ( V_104 , & V_105 ) ;
}
static int F_109 ( struct V_103 * V_103 , struct V_104 * V_104 )
{
return F_108 ( V_104 , & V_106 ) ;
}
static bool F_110 ( T_1 * V_17 , struct V_10 * V_10 )
{
int V_107 ;
for ( V_107 = 0 ; V_107 < V_65 ; V_107 ++ ) {
struct V_10 * V_108 = & V_17 -> V_27 [ V_107 ] ;
if ( F_85 ( V_108 ) )
return V_10 == V_108 ;
}
return false ;
}
static void F_111 ( struct V_78 * V_79 , T_1 * V_17 ,
struct V_10 * V_10 )
{
int V_3 ;
F_89 ( V_79 , L_14 , V_17 -> V_85 , V_10 -> V_86 ) ;
if ( F_110 ( V_17 , V_10 ) ) {
F_89 ( V_79 , L_15 ) ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ ) {
F_89 ( V_79 , L_16 ,
V_109 [ V_3 + V_52 ] ,
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
L_23 ,
F_70 ( V_10 , V_110 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_21 ( V_10 ) ,
V_10 -> V_111 ,
V_10 -> V_112 ,
V_10 -> V_14 ) ;
F_89 ( V_79 ,
L_24 ,
V_10 -> V_113 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_112 ( V_10 -> V_113 ) ; V_3 ++ )
F_89 ( V_79 , L_25 , V_10 -> V_113 [ V_3 ] ) ;
F_90 ( V_79 , ')' ) ;
if ( ! F_85 ( V_10 ) ) {
F_90 ( V_79 , '\n' ) ;
return;
}
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
F_89 ( V_79 , L_16 , V_109 [ V_3 ] ,
F_70 ( V_10 , V_3 ) ) ;
F_89 ( V_79 , L_26 ) ;
F_2 (i) {
struct V_31 * V_24 ;
V_24 = F_19 ( V_10 -> V_24 , V_3 ) ;
F_89 ( V_79 ,
L_27
L_28
L_29
L_30 ,
V_3 ,
V_24 -> V_32 . V_61 ,
V_24 -> V_32 . V_114 ,
V_24 -> V_32 . V_115 ) ;
#ifdef F_73
F_89 ( V_79 , L_31 ,
V_24 -> V_19 ) ;
#endif
}
F_89 ( V_79 ,
L_32
L_33
L_34 ,
V_17 -> V_116 >= V_117 ,
V_10 -> V_96 ,
V_10 -> V_20 -> V_118 ) ;
F_90 ( V_79 , '\n' ) ;
}
static int F_113 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
F_83 ( V_79 , V_17 , false , false , F_111 ) ;
return 0 ;
}
static int F_114 ( struct V_103 * V_103 , struct V_104 * V_104 )
{
return F_108 ( V_104 , & V_119 ) ;
}
static void * F_115 ( struct V_78 * V_79 , T_4 * V_80 )
{
unsigned long * V_40 ;
int V_3 , V_120 ;
if ( * V_80 >= F_112 ( V_109 ) )
return NULL ;
V_120 = V_52 * sizeof( unsigned long ) +
V_54 * sizeof( unsigned long ) +
V_121 * sizeof( unsigned long ) ;
#ifdef F_116
V_120 += sizeof( struct V_5 ) ;
#endif
V_40 = F_117 ( V_120 , V_122 ) ;
V_79 -> V_123 = V_40 ;
if ( ! V_40 )
return F_118 ( - V_124 ) ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ )
V_40 [ V_3 ] = F_119 ( V_3 ) ;
V_40 += V_52 ;
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ )
V_40 [ V_3 ] = F_120 ( V_3 ) ;
V_40 += V_54 ;
F_121 ( V_40 + V_125 ,
V_40 + V_126 ) ;
V_40 += V_121 ;
#ifdef F_116
F_4 ( V_40 ) ;
V_40 [ V_127 ] /= 2 ;
V_40 [ V_128 ] /= 2 ;
#endif
return ( unsigned long * ) V_79 -> V_123 + * V_80 ;
}
static void * F_122 ( struct V_78 * V_79 , void * V_81 , T_4 * V_80 )
{
( * V_80 ) ++ ;
if ( * V_80 >= F_112 ( V_109 ) )
return NULL ;
return ( unsigned long * ) V_79 -> V_123 + * V_80 ;
}
static int F_123 ( struct V_78 * V_79 , void * V_81 )
{
unsigned long * V_129 = V_81 ;
unsigned long V_130 = V_129 - ( unsigned long * ) V_79 -> V_123 ;
F_124 ( V_79 , V_109 [ V_130 ] ) ;
F_125 ( V_79 , L_35 , * V_129 ) ;
F_90 ( V_79 , '\n' ) ;
return 0 ;
}
static void F_126 ( struct V_78 * V_79 , void * V_81 )
{
F_127 ( V_79 -> V_123 ) ;
V_79 -> V_123 = NULL ;
}
static int F_128 ( struct V_103 * V_103 , struct V_104 * V_104 )
{
return F_108 ( V_104 , & V_131 ) ;
}
static void F_129 ( struct V_132 * V_133 )
{
F_58 ( true ) ;
}
int F_130 ( struct V_134 * V_135 , int V_136 ,
void T_5 * V_137 , T_6 * V_138 , T_4 * V_139 )
{
long V_140 ;
int V_141 ;
int V_3 ;
V_141 = F_131 ( F_129 ) ;
if ( V_141 )
return V_141 ;
for ( V_3 = 0 ; V_3 < V_52 ; V_3 ++ ) {
V_140 = F_72 ( & V_53 [ V_3 ] ) ;
if ( V_140 < 0 ) {
F_132 ( L_36 ,
V_142 , V_109 [ V_3 ] , V_140 ) ;
V_141 = - V_143 ;
}
}
if ( V_141 )
return V_141 ;
if ( V_136 )
* V_139 += * V_138 ;
else
* V_138 = 0 ;
return 0 ;
}
static void F_133 ( struct V_132 * V_144 )
{
if ( F_58 ( true ) ) {
F_134 ( F_135 () , V_145 ,
F_65 ( & V_146 ) ,
F_136 ( V_147 ) ) ;
}
}
static bool F_137 ( int V_2 )
{
struct V_10 * V_10 ;
F_20 (zone) {
struct V_31 * V_33 = F_19 ( V_10 -> V_24 , V_2 ) ;
F_138 ( sizeof( V_33 -> V_34 [ 0 ] ) != 1 ) ;
if ( F_139 ( V_33 -> V_34 , 0 , V_52 ) )
return true ;
}
return false ;
}
void F_140 ( void )
{
if ( V_148 != V_149 )
return;
if ( ! F_141 ( F_65 ( & V_146 ) ) )
return;
if ( ! F_137 ( F_135 () ) )
return;
F_58 ( false ) ;
}
static void F_142 ( struct V_132 * V_144 )
{
int V_2 ;
F_5 () ;
F_2 (cpu) {
struct V_150 * V_151 = & F_3 ( V_146 , V_2 ) ;
if ( ! F_141 ( V_151 ) && F_137 ( V_2 ) )
F_134 ( V_2 , V_145 , V_151 , 0 ) ;
}
F_6 () ;
F_143 ( & V_152 ,
F_136 ( V_147 ) ) ;
}
static void T_7 F_144 ( void )
{
int V_2 ;
F_145 (cpu)
F_146 ( F_19 ( & V_146 , V_2 ) ,
F_133 ) ;
F_143 ( & V_152 ,
F_136 ( V_147 ) ) ;
}
static void T_7 F_147 ( void )
{
int V_63 ;
F_148 (node) {
if ( F_149 ( F_150 ( V_63 ) ) > 0 )
F_151 ( V_63 , V_153 ) ;
}
}
static int F_152 ( unsigned int V_2 )
{
F_17 () ;
F_151 ( F_153 ( V_2 ) , V_153 ) ;
return 0 ;
}
static int F_154 ( unsigned int V_2 )
{
F_155 ( & F_3 ( V_146 , V_2 ) ) ;
return 0 ;
}
static int F_156 ( unsigned int V_2 )
{
const struct V_154 * V_155 ;
int V_63 ;
V_63 = F_153 ( V_2 ) ;
F_17 () ;
V_155 = F_150 ( V_63 ) ;
if ( F_149 ( V_155 ) > 0 )
return 0 ;
F_157 ( V_63 , V_153 ) ;
return 0 ;
}
void T_7 F_158 ( void )
{
int V_1 V_156 ;
V_145 = F_159 ( L_37 , V_157 , 0 ) ;
#ifdef F_73
V_1 = F_160 ( V_158 , L_38 ,
NULL , F_156 ) ;
if ( V_1 < 0 )
F_161 ( L_39 ) ;
V_1 = F_160 ( V_159 , L_40 ,
F_152 ,
F_154 ) ;
if ( V_1 < 0 )
F_161 ( L_41 ) ;
F_5 () ;
F_147 () ;
F_6 () ;
F_144 () ;
#endif
#ifdef F_162
F_163 ( L_42 , 0444 , NULL , & V_160 ) ;
F_163 ( L_43 , 0444 , NULL , & V_161 ) ;
F_163 ( L_44 , 0444 , NULL , & V_162 ) ;
F_163 ( L_45 , 0444 , NULL , & V_163 ) ;
#endif
}
static int F_164 ( unsigned int V_69 ,
struct V_67 * V_68 )
{
if ( V_68 -> V_70 == 0 )
return 1000 ;
return F_76 ( ( V_68 -> V_70 - ( V_68 -> V_72 << V_69 ) ) * 1000ULL , V_68 -> V_70 ) ;
}
static void F_165 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
unsigned int V_69 ;
int V_164 ;
struct V_67 V_68 ;
F_89 ( V_79 , L_1 ,
V_17 -> V_85 ,
V_10 -> V_86 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
F_74 ( V_10 , V_69 , & V_68 ) ;
V_164 = F_164 ( V_69 , & V_68 ) ;
F_89 ( V_79 , L_46 , V_164 / 1000 , V_164 % 1000 ) ;
}
F_90 ( V_79 , '\n' ) ;
}
static int F_166 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
if ( ! F_106 ( V_17 -> V_85 , V_101 ) )
return 0 ;
F_83 ( V_79 , V_17 , true , false , F_165 ) ;
return 0 ;
}
static int F_167 ( struct V_103 * V_103 , struct V_104 * V_104 )
{
return F_108 ( V_104 , & V_165 ) ;
}
static void F_168 ( struct V_78 * V_79 ,
T_1 * V_17 , struct V_10 * V_10 )
{
unsigned int V_69 ;
int V_164 ;
struct V_67 V_68 ;
F_89 ( V_79 , L_1 ,
V_17 -> V_85 ,
V_10 -> V_86 ) ;
for ( V_69 = 0 ; V_69 < V_73 ; ++ V_69 ) {
F_74 ( V_10 , V_69 , & V_68 ) ;
V_164 = F_75 ( V_69 , & V_68 ) ;
F_89 ( V_79 , L_46 , V_164 / 1000 , V_164 % 1000 ) ;
}
F_90 ( V_79 , '\n' ) ;
}
static int F_169 ( struct V_78 * V_79 , void * V_81 )
{
T_1 * V_17 = ( T_1 * ) V_81 ;
F_83 ( V_79 , V_17 , true , false , F_168 ) ;
return 0 ;
}
static int F_170 ( struct V_103 * V_103 , struct V_104 * V_104 )
{
return F_108 ( V_104 , & V_166 ) ;
}
static int T_7 F_171 ( void )
{
struct V_167 * V_168 ;
V_168 = F_172 ( L_47 , NULL ) ;
if ( ! V_168 )
return - V_124 ;
if ( ! F_173 ( L_48 , 0444 ,
V_168 , NULL , & V_169 ) )
goto V_170;
if ( ! F_173 ( L_49 , 0444 ,
V_168 , NULL , & V_171 ) )
goto V_170;
return 0 ;
V_170:
F_174 ( V_168 ) ;
return - V_124 ;
}
