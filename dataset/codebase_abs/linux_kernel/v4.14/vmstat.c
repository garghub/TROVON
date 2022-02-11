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
static int F_56 ( int * V_49 , int * V_50 , int * V_51 )
{
int V_3 ;
int V_52 = 0 ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ )
if ( V_49 [ V_3 ] ) {
F_57 ( V_49 [ V_3 ] , & V_54 [ V_3 ] ) ;
V_52 ++ ;
}
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ )
if ( V_50 [ V_3 ] ) {
F_57 ( V_50 [ V_3 ] , & V_56 [ V_3 ] ) ;
V_52 ++ ;
}
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ )
if ( V_51 [ V_3 ] ) {
F_57 ( V_51 [ V_3 ] , & V_58 [ V_3 ] ) ;
V_52 ++ ;
}
return V_52 ;
}
static int F_56 ( int * V_49 , int * V_51 )
{
int V_3 ;
int V_52 = 0 ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ )
if ( V_49 [ V_3 ] ) {
F_57 ( V_49 [ V_3 ] , & V_54 [ V_3 ] ) ;
V_52 ++ ;
}
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ )
if ( V_51 [ V_3 ] ) {
F_57 ( V_51 [ V_3 ] , & V_58 [ V_3 ] ) ;
V_52 ++ ;
}
return V_52 ;
}
static int F_58 ( bool V_59 )
{
struct V_16 * V_17 ;
struct V_10 * V_10 ;
int V_3 ;
int V_60 [ V_53 ] = { 0 , } ;
#ifdef F_59
int V_61 [ V_55 ] = { 0 , } ;
#endif
int V_62 [ V_57 ] = { 0 , } ;
int V_52 = 0 ;
F_20 (zone) {
struct V_31 T_2 * V_33 = V_10 -> V_24 ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ ) {
int V_40 ;
V_40 = F_60 ( V_33 -> V_34 [ V_3 ] , 0 ) ;
if ( V_40 ) {
F_57 ( V_40 , & V_10 -> V_63 [ V_3 ] ) ;
V_60 [ V_3 ] += V_40 ;
#ifdef F_59
F_28 ( V_33 -> V_64 , 3 ) ;
#endif
}
}
#ifdef F_59
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ ) {
int V_40 ;
V_40 = F_60 ( V_33 -> V_65 [ V_3 ] , 0 ) ;
if ( V_40 ) {
F_57 ( V_40 , & V_10 -> V_56 [ V_3 ] ) ;
V_61 [ V_3 ] += V_40 ;
F_28 ( V_33 -> V_64 , 3 ) ;
}
}
if ( V_59 ) {
F_61 () ;
if ( ! F_25 ( V_33 -> V_64 ) ||
! F_25 ( V_33 -> V_32 . V_66 ) )
continue;
if ( F_62 ( V_10 ) == F_63 () ) {
F_28 ( V_33 -> V_64 , 0 ) ;
continue;
}
if ( F_39 ( V_33 -> V_64 ) )
continue;
if ( F_25 ( V_33 -> V_32 . V_66 ) ) {
F_64 ( V_10 , F_65 ( & V_33 -> V_32 ) ) ;
V_52 ++ ;
}
}
#endif
}
F_18 (pgdat) {
struct V_38 T_2 * V_33 = V_17 -> V_18 ;
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ ) {
int V_40 ;
V_40 = F_60 ( V_33 -> V_39 [ V_3 ] , 0 ) ;
if ( V_40 ) {
F_57 ( V_40 , & V_17 -> V_63 [ V_3 ] ) ;
V_62 [ V_3 ] += V_40 ;
}
}
}
#ifdef F_59
V_52 += F_56 ( V_60 , V_61 ,
V_62 ) ;
#else
V_52 += F_56 ( V_60 , V_62 ) ;
#endif
return V_52 ;
}
void F_66 ( int V_2 )
{
struct V_16 * V_17 ;
struct V_10 * V_10 ;
int V_3 ;
int V_60 [ V_53 ] = { 0 , } ;
#ifdef F_59
int V_61 [ V_55 ] = { 0 , } ;
#endif
int V_62 [ V_57 ] = { 0 , } ;
F_20 (zone) {
struct V_31 * V_33 ;
V_33 = F_19 ( V_10 -> V_24 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ )
if ( V_33 -> V_34 [ V_3 ] ) {
int V_40 ;
V_40 = V_33 -> V_34 [ V_3 ] ;
V_33 -> V_34 [ V_3 ] = 0 ;
F_57 ( V_40 , & V_10 -> V_63 [ V_3 ] ) ;
V_60 [ V_3 ] += V_40 ;
}
#ifdef F_59
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ )
if ( V_33 -> V_65 [ V_3 ] ) {
int V_40 ;
V_40 = V_33 -> V_65 [ V_3 ] ;
V_33 -> V_65 [ V_3 ] = 0 ;
F_57 ( V_40 , & V_10 -> V_56 [ V_3 ] ) ;
V_61 [ V_3 ] += V_40 ;
}
#endif
}
F_18 (pgdat) {
struct V_38 * V_33 ;
V_33 = F_19 ( V_17 -> V_18 , V_2 ) ;
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ )
if ( V_33 -> V_39 [ V_3 ] ) {
int V_40 ;
V_40 = V_33 -> V_39 [ V_3 ] ;
V_33 -> V_39 [ V_3 ] = 0 ;
F_57 ( V_40 , & V_17 -> V_63 [ V_3 ] ) ;
V_62 [ V_3 ] += V_40 ;
}
}
#ifdef F_59
F_56 ( V_60 , V_61 , V_62 ) ;
#else
F_56 ( V_60 , V_62 ) ;
#endif
}
void F_67 ( struct V_10 * V_10 , struct V_31 * V_67 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ )
if ( V_67 -> V_34 [ V_3 ] ) {
int V_40 = V_67 -> V_34 [ V_3 ] ;
V_67 -> V_34 [ V_3 ] = 0 ;
F_57 ( V_40 , & V_10 -> V_63 [ V_3 ] ) ;
F_57 ( V_40 , & V_54 [ V_3 ] ) ;
}
#ifdef F_59
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ )
if ( V_67 -> V_65 [ V_3 ] ) {
int V_40 = V_67 -> V_65 [ V_3 ] ;
V_67 -> V_65 [ V_3 ] = 0 ;
F_57 ( V_40 , & V_10 -> V_56 [ V_3 ] ) ;
F_57 ( V_40 , & V_56 [ V_3 ] ) ;
}
#endif
}
void F_68 ( struct V_10 * V_10 ,
enum V_68 V_29 )
{
struct V_31 T_2 * V_32 = V_10 -> V_24 ;
T_4 T_2 * V_33 = V_32 -> V_65 + V_29 ;
T_4 V_40 ;
V_40 = F_32 ( * V_33 ) ;
if ( F_26 ( V_40 > V_69 ) ) {
F_69 ( V_40 , V_10 , V_29 ) ;
F_28 ( * V_33 , 0 ) ;
}
}
unsigned long F_70 ( int V_70 ,
enum V_28 V_29 )
{
struct V_10 * V_71 = F_71 ( V_70 ) -> V_27 ;
int V_3 ;
unsigned long V_66 = 0 ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ )
V_66 += F_72 ( V_71 + V_3 , V_29 ) ;
return V_66 ;
}
unsigned long F_73 ( int V_70 ,
enum V_68 V_29 )
{
struct V_10 * V_71 = F_71 ( V_70 ) -> V_27 ;
int V_3 ;
unsigned long V_66 = 0 ;
for ( V_3 = 0 ; V_3 < V_72 ; V_3 ++ )
V_66 += F_74 ( V_71 + V_3 , V_29 ) ;
return V_66 ;
}
unsigned long F_75 ( struct V_16 * V_17 ,
enum V_37 V_29 )
{
long V_35 = F_76 ( & V_17 -> V_63 [ V_29 ] ) ;
#ifdef F_77
if ( V_35 < 0 )
V_35 = 0 ;
#endif
return V_35 ;
}
static void F_78 ( struct V_10 * V_10 ,
unsigned int V_73 ,
struct V_74 * V_75 )
{
unsigned int V_76 ;
V_75 -> V_77 = 0 ;
V_75 -> V_78 = 0 ;
V_75 -> V_79 = 0 ;
for ( V_76 = 0 ; V_76 < V_80 ; V_76 ++ ) {
unsigned long V_81 ;
V_81 = V_10 -> V_82 [ V_76 ] . V_83 ;
V_75 -> V_78 += V_81 ;
V_75 -> V_77 += V_81 << V_76 ;
if ( V_76 >= V_73 )
V_75 -> V_79 += V_81 <<
( V_76 - V_73 ) ;
}
}
static int F_79 ( unsigned int V_76 , struct V_74 * V_75 )
{
unsigned long V_84 = 1UL << V_76 ;
if ( F_80 ( V_76 >= V_80 ) )
return 0 ;
if ( ! V_75 -> V_78 )
return 0 ;
if ( V_75 -> V_79 )
return - 1000 ;
return 1000 - F_81 ( ( 1000 + ( F_81 ( V_75 -> V_77 * 1000ULL , V_84 ) ) ) , V_75 -> V_78 ) ;
}
int F_82 ( struct V_10 * V_10 , unsigned int V_76 )
{
struct V_74 V_75 ;
F_78 ( V_10 , V_76 , & V_75 ) ;
return F_79 ( V_76 , & V_75 ) ;
}
static void * F_83 ( struct V_85 * V_86 , T_5 * V_87 )
{
T_1 * V_17 ;
T_5 V_70 = * V_87 ;
for ( V_17 = F_84 () ;
V_17 && V_70 ;
V_17 = F_85 ( V_17 ) )
-- V_70 ;
return V_17 ;
}
static void * F_86 ( struct V_85 * V_86 , void * V_88 , T_5 * V_87 )
{
T_1 * V_17 = ( T_1 * ) V_88 ;
( * V_87 ) ++ ;
return F_85 ( V_17 ) ;
}
static void F_87 ( struct V_85 * V_86 , void * V_88 )
{
}
static void F_88 ( struct V_85 * V_86 , T_1 * V_17 ,
bool V_89 , bool V_90 ,
void (* F_89)( struct V_85 * V_86 , T_1 * , struct V_10 * ) )
{
struct V_10 * V_10 ;
struct V_10 * V_27 = V_17 -> V_27 ;
unsigned long V_48 ;
for ( V_10 = V_27 ; V_10 - V_27 < V_72 ; ++ V_10 ) {
if ( V_89 && ! F_90 ( V_10 ) )
continue;
if ( ! V_90 )
F_91 ( & V_10 -> V_91 , V_48 ) ;
F_89 ( V_86 , V_17 , V_10 ) ;
if ( ! V_90 )
F_92 ( & V_10 -> V_91 , V_48 ) ;
}
}
static void F_93 ( struct V_85 * V_86 , T_1 * V_17 ,
struct V_10 * V_10 )
{
int V_76 ;
F_94 ( V_86 , L_1 , V_17 -> V_92 , V_10 -> V_93 ) ;
for ( V_76 = 0 ; V_76 < V_80 ; ++ V_76 )
F_94 ( V_86 , L_2 , V_10 -> V_82 [ V_76 ] . V_83 ) ;
F_95 ( V_86 , '\n' ) ;
}
static int F_96 ( struct V_85 * V_86 , void * V_88 )
{
T_1 * V_17 = ( T_1 * ) V_88 ;
F_88 ( V_86 , V_17 , true , false , F_93 ) ;
return 0 ;
}
static void F_97 ( struct V_85 * V_86 ,
T_1 * V_17 , struct V_10 * V_10 )
{
int V_76 , V_94 ;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ ) {
F_94 ( V_86 , L_3 ,
V_17 -> V_92 ,
V_10 -> V_93 ,
V_96 [ V_94 ] ) ;
for ( V_76 = 0 ; V_76 < V_80 ; ++ V_76 ) {
unsigned long V_97 = 0 ;
struct V_82 * V_98 ;
struct V_99 * V_100 ;
V_98 = & ( V_10 -> V_82 [ V_76 ] ) ;
F_98 (curr, &area->free_list[mtype])
V_97 ++ ;
F_94 ( V_86 , L_2 , V_97 ) ;
}
F_95 ( V_86 , '\n' ) ;
}
}
static int F_99 ( struct V_85 * V_86 , void * V_88 )
{
int V_76 ;
T_1 * V_17 = ( T_1 * ) V_88 ;
F_94 ( V_86 , L_4 , L_5 ) ;
for ( V_76 = 0 ; V_76 < V_80 ; ++ V_76 )
F_94 ( V_86 , L_6 , V_76 ) ;
F_95 ( V_86 , '\n' ) ;
F_88 ( V_86 , V_17 , true , false , F_97 ) ;
return 0 ;
}
static void F_100 ( struct V_85 * V_86 ,
T_1 * V_17 , struct V_10 * V_10 )
{
int V_94 ;
unsigned long V_101 ;
unsigned long V_102 = V_10 -> V_103 ;
unsigned long V_104 = F_101 ( V_10 ) ;
unsigned long V_66 [ V_95 ] = { 0 , } ;
for ( V_101 = V_102 ; V_101 < V_104 ; V_101 += V_105 ) {
struct V_42 * V_42 ;
V_42 = F_102 ( V_101 ) ;
if ( ! V_42 )
continue;
if ( ! F_103 ( V_101 , V_42 , V_10 ) )
continue;
if ( F_35 ( V_42 ) != V_10 )
continue;
V_94 = F_104 ( V_42 ) ;
if ( V_94 < V_95 )
V_66 [ V_94 ] ++ ;
}
F_94 ( V_86 , L_1 , V_17 -> V_92 , V_10 -> V_93 ) ;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ )
F_94 ( V_86 , L_7 , V_66 [ V_94 ] ) ;
F_95 ( V_86 , '\n' ) ;
}
static int F_105 ( struct V_85 * V_86 , void * V_88 )
{
int V_94 ;
T_1 * V_17 = ( T_1 * ) V_88 ;
F_94 ( V_86 , L_8 , L_9 ) ;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ )
F_94 ( V_86 , L_10 , V_96 [ V_94 ] ) ;
F_95 ( V_86 , '\n' ) ;
F_88 ( V_86 , V_17 , true , false ,
F_100 ) ;
return 0 ;
}
static void F_106 ( struct V_85 * V_86 , T_1 * V_17 )
{
#ifdef F_107
int V_94 ;
if ( ! F_108 ( & V_106 ) )
return;
F_109 ( NULL ) ;
F_94 ( V_86 , L_8 , L_11 ) ;
for ( V_94 = 0 ; V_94 < V_95 ; V_94 ++ )
F_94 ( V_86 , L_10 , V_96 [ V_94 ] ) ;
F_95 ( V_86 , '\n' ) ;
F_88 ( V_86 , V_17 , true , true ,
V_107 ) ;
#endif
}
static int F_110 ( struct V_85 * V_86 , void * V_88 )
{
T_1 * V_17 = ( T_1 * ) V_88 ;
if ( ! F_111 ( V_17 -> V_92 , V_108 ) )
return 0 ;
F_94 ( V_86 , L_12 , V_109 ) ;
F_94 ( V_86 , L_13 , V_105 ) ;
F_95 ( V_86 , '\n' ) ;
F_99 ( V_86 , V_17 ) ;
F_105 ( V_86 , V_17 ) ;
F_106 ( V_86 , V_17 ) ;
return 0 ;
}
static int F_112 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_113 ( V_111 , & V_112 ) ;
}
static int F_114 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_113 ( V_111 , & V_113 ) ;
}
static bool F_115 ( T_1 * V_17 , struct V_10 * V_10 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < V_72 ; V_114 ++ ) {
struct V_10 * V_115 = & V_17 -> V_27 [ V_114 ] ;
if ( F_90 ( V_115 ) )
return V_10 == V_115 ;
}
return false ;
}
static void F_116 ( struct V_85 * V_86 , T_1 * V_17 ,
struct V_10 * V_10 )
{
int V_3 ;
F_94 ( V_86 , L_14 , V_17 -> V_92 , V_10 -> V_93 ) ;
if ( F_115 ( V_17 , V_10 ) ) {
F_94 ( V_86 , L_15 ) ;
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ ) {
F_94 ( V_86 , L_16 ,
V_116 [ V_3 + V_53 +
V_55 ] ,
F_75 ( V_17 , V_3 ) ) ;
}
}
F_94 ( V_86 ,
L_17
L_18
L_19
L_20
L_21
L_22
L_23 ,
F_72 ( V_10 , V_117 ) ,
F_11 ( V_10 ) ,
F_10 ( V_10 ) ,
F_21 ( V_10 ) ,
V_10 -> V_118 ,
V_10 -> V_119 ,
V_10 -> V_14 ) ;
F_94 ( V_86 ,
L_24 ,
V_10 -> V_120 [ 0 ] ) ;
for ( V_3 = 1 ; V_3 < F_117 ( V_10 -> V_120 ) ; V_3 ++ )
F_94 ( V_86 , L_25 , V_10 -> V_120 [ V_3 ] ) ;
F_95 ( V_86 , ')' ) ;
if ( ! F_90 ( V_10 ) ) {
F_95 ( V_86 , '\n' ) ;
return;
}
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ )
F_94 ( V_86 , L_16 , V_116 [ V_3 ] ,
F_72 ( V_10 , V_3 ) ) ;
#ifdef F_59
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ )
F_94 ( V_86 , L_16 ,
V_116 [ V_3 + V_53 ] ,
F_74 ( V_10 , V_3 ) ) ;
#endif
F_94 ( V_86 , L_26 ) ;
F_2 (i) {
struct V_31 * V_24 ;
V_24 = F_19 ( V_10 -> V_24 , V_3 ) ;
F_94 ( V_86 ,
L_27
L_28
L_29
L_30 ,
V_3 ,
V_24 -> V_32 . V_66 ,
V_24 -> V_32 . V_121 ,
V_24 -> V_32 . V_122 ) ;
#ifdef F_77
F_94 ( V_86 , L_31 ,
V_24 -> V_19 ) ;
#endif
}
F_94 ( V_86 ,
L_32
L_33
L_34 ,
V_17 -> V_123 >= V_124 ,
V_10 -> V_103 ,
V_10 -> V_20 -> V_125 ) ;
F_95 ( V_86 , '\n' ) ;
}
static int F_118 ( struct V_85 * V_86 , void * V_88 )
{
T_1 * V_17 = ( T_1 * ) V_88 ;
F_88 ( V_86 , V_17 , false , false , F_116 ) ;
return 0 ;
}
static int F_119 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_113 ( V_111 , & V_126 ) ;
}
static void * F_120 ( struct V_85 * V_86 , T_5 * V_87 )
{
unsigned long * V_40 ;
int V_3 , V_127 ;
if ( * V_87 >= F_117 ( V_116 ) )
return NULL ;
V_127 = V_53 * sizeof( unsigned long ) +
V_55 * sizeof( unsigned long ) +
V_57 * sizeof( unsigned long ) +
V_128 * sizeof( unsigned long ) ;
#ifdef F_121
V_127 += sizeof( struct V_5 ) ;
#endif
V_40 = F_122 ( V_127 , V_129 ) ;
V_86 -> V_130 = V_40 ;
if ( ! V_40 )
return F_123 ( - V_131 ) ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ )
V_40 [ V_3 ] = F_124 ( V_3 ) ;
V_40 += V_53 ;
#ifdef F_59
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ )
V_40 [ V_3 ] = F_125 ( V_3 ) ;
V_40 += V_55 ;
#endif
for ( V_3 = 0 ; V_3 < V_57 ; V_3 ++ )
V_40 [ V_3 ] = F_126 ( V_3 ) ;
V_40 += V_57 ;
F_127 ( V_40 + V_132 ,
V_40 + V_133 ) ;
V_40 += V_128 ;
#ifdef F_121
F_4 ( V_40 ) ;
V_40 [ V_134 ] /= 2 ;
V_40 [ V_135 ] /= 2 ;
#endif
return ( unsigned long * ) V_86 -> V_130 + * V_87 ;
}
static void * F_128 ( struct V_85 * V_86 , void * V_88 , T_5 * V_87 )
{
( * V_87 ) ++ ;
if ( * V_87 >= F_117 ( V_116 ) )
return NULL ;
return ( unsigned long * ) V_86 -> V_130 + * V_87 ;
}
static int F_129 ( struct V_85 * V_86 , void * V_88 )
{
unsigned long * V_136 = V_88 ;
unsigned long V_137 = V_136 - ( unsigned long * ) V_86 -> V_130 ;
F_130 ( V_86 , V_116 [ V_137 ] ) ;
F_131 ( V_86 , L_35 , * V_136 ) ;
F_95 ( V_86 , '\n' ) ;
return 0 ;
}
static void F_132 ( struct V_85 * V_86 , void * V_88 )
{
F_133 ( V_86 -> V_130 ) ;
V_86 -> V_130 = NULL ;
}
static int F_134 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_113 ( V_111 , & V_138 ) ;
}
static void F_135 ( struct V_139 * V_140 )
{
F_58 ( true ) ;
}
int F_136 ( struct V_141 * V_142 , int V_143 ,
void T_6 * V_144 , T_7 * V_145 , T_5 * V_146 )
{
long V_147 ;
int V_148 ;
int V_3 ;
V_148 = F_137 ( F_135 ) ;
if ( V_148 )
return V_148 ;
for ( V_3 = 0 ; V_3 < V_53 ; V_3 ++ ) {
V_147 = F_76 ( & V_54 [ V_3 ] ) ;
if ( V_147 < 0 ) {
F_138 ( L_36 ,
V_149 , V_116 [ V_3 ] , V_147 ) ;
V_148 = - V_150 ;
}
}
#ifdef F_59
for ( V_3 = 0 ; V_3 < V_55 ; V_3 ++ ) {
V_147 = F_76 ( & V_56 [ V_3 ] ) ;
if ( V_147 < 0 ) {
F_138 ( L_36 ,
V_149 , V_116 [ V_3 + V_53 ] , V_147 ) ;
V_148 = - V_150 ;
}
}
#endif
if ( V_148 )
return V_148 ;
if ( V_143 )
* V_146 += * V_145 ;
else
* V_145 = 0 ;
return 0 ;
}
static void F_139 ( struct V_139 * V_151 )
{
if ( F_58 ( true ) ) {
F_140 ( F_141 () , V_152 ,
F_65 ( & V_153 ) ,
F_142 ( V_154 ) ) ;
}
}
static bool F_143 ( int V_2 )
{
struct V_10 * V_10 ;
F_20 (zone) {
struct V_31 * V_33 = F_19 ( V_10 -> V_24 , V_2 ) ;
F_144 ( sizeof( V_33 -> V_34 [ 0 ] ) != 1 ) ;
#ifdef F_59
F_144 ( sizeof( V_33 -> V_65 [ 0 ] ) != 2 ) ;
#endif
if ( F_145 ( V_33 -> V_34 , 0 , V_53 ) )
return true ;
#ifdef F_59
if ( F_145 ( V_33 -> V_65 , 0 , V_55 ) )
return true ;
#endif
}
return false ;
}
void F_146 ( void )
{
if ( V_155 != V_156 )
return;
if ( ! F_147 ( F_65 ( & V_153 ) ) )
return;
if ( ! F_143 ( F_141 () ) )
return;
F_58 ( false ) ;
}
static void F_148 ( struct V_139 * V_151 )
{
int V_2 ;
F_5 () ;
F_2 (cpu) {
struct V_157 * V_158 = & F_3 ( V_153 , V_2 ) ;
if ( ! F_147 ( V_158 ) && F_143 ( V_2 ) )
F_140 ( V_2 , V_152 , V_158 , 0 ) ;
}
F_6 () ;
F_149 ( & V_159 ,
F_142 ( V_154 ) ) ;
}
static void T_8 F_150 ( void )
{
int V_2 ;
F_151 (cpu)
F_152 ( F_19 ( & V_153 , V_2 ) ,
F_139 ) ;
F_149 ( & V_159 ,
F_142 ( V_154 ) ) ;
}
static void T_8 F_153 ( void )
{
int V_70 ;
F_154 (node) {
if ( F_155 ( F_156 ( V_70 ) ) > 0 )
F_157 ( V_70 , V_160 ) ;
}
}
static int F_158 ( unsigned int V_2 )
{
F_17 () ;
F_157 ( F_159 ( V_2 ) , V_160 ) ;
return 0 ;
}
static int F_160 ( unsigned int V_2 )
{
F_161 ( & F_3 ( V_153 , V_2 ) ) ;
return 0 ;
}
static int F_162 ( unsigned int V_2 )
{
const struct V_161 * V_162 ;
int V_70 ;
V_70 = F_159 ( V_2 ) ;
F_17 () ;
V_162 = F_156 ( V_70 ) ;
if ( F_155 ( V_162 ) > 0 )
return 0 ;
F_163 ( V_70 , V_160 ) ;
return 0 ;
}
void T_8 F_164 ( void )
{
int V_1 V_163 ;
V_152 = F_165 ( L_37 , V_164 , 0 ) ;
#ifdef F_77
V_1 = F_166 ( V_165 , L_38 ,
NULL , F_162 ) ;
if ( V_1 < 0 )
F_167 ( L_39 ) ;
V_1 = F_166 ( V_166 , L_40 ,
F_158 ,
F_160 ) ;
if ( V_1 < 0 )
F_167 ( L_41 ) ;
F_5 () ;
F_153 () ;
F_6 () ;
F_150 () ;
#endif
#ifdef F_168
F_169 ( L_42 , 0444 , NULL , & V_167 ) ;
F_169 ( L_43 , 0444 , NULL , & V_168 ) ;
F_169 ( L_44 , 0444 , NULL , & V_169 ) ;
F_169 ( L_45 , 0444 , NULL , & V_170 ) ;
#endif
}
static int F_170 ( unsigned int V_76 ,
struct V_74 * V_75 )
{
if ( V_75 -> V_77 == 0 )
return 1000 ;
return F_81 ( ( V_75 -> V_77 - ( V_75 -> V_79 << V_76 ) ) * 1000ULL , V_75 -> V_77 ) ;
}
static void F_171 ( struct V_85 * V_86 ,
T_1 * V_17 , struct V_10 * V_10 )
{
unsigned int V_76 ;
int V_171 ;
struct V_74 V_75 ;
F_94 ( V_86 , L_1 ,
V_17 -> V_92 ,
V_10 -> V_93 ) ;
for ( V_76 = 0 ; V_76 < V_80 ; ++ V_76 ) {
F_78 ( V_10 , V_76 , & V_75 ) ;
V_171 = F_170 ( V_76 , & V_75 ) ;
F_94 ( V_86 , L_46 , V_171 / 1000 , V_171 % 1000 ) ;
}
F_95 ( V_86 , '\n' ) ;
}
static int F_172 ( struct V_85 * V_86 , void * V_88 )
{
T_1 * V_17 = ( T_1 * ) V_88 ;
if ( ! F_111 ( V_17 -> V_92 , V_108 ) )
return 0 ;
F_88 ( V_86 , V_17 , true , false , F_171 ) ;
return 0 ;
}
static int F_173 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_113 ( V_111 , & V_172 ) ;
}
static void F_174 ( struct V_85 * V_86 ,
T_1 * V_17 , struct V_10 * V_10 )
{
unsigned int V_76 ;
int V_171 ;
struct V_74 V_75 ;
F_94 ( V_86 , L_1 ,
V_17 -> V_92 ,
V_10 -> V_93 ) ;
for ( V_76 = 0 ; V_76 < V_80 ; ++ V_76 ) {
F_78 ( V_10 , V_76 , & V_75 ) ;
V_171 = F_79 ( V_76 , & V_75 ) ;
F_94 ( V_86 , L_46 , V_171 / 1000 , V_171 % 1000 ) ;
}
F_95 ( V_86 , '\n' ) ;
}
static int F_175 ( struct V_85 * V_86 , void * V_88 )
{
T_1 * V_17 = ( T_1 * ) V_88 ;
F_88 ( V_86 , V_17 , true , false , F_174 ) ;
return 0 ;
}
static int F_176 ( struct V_110 * V_110 , struct V_111 * V_111 )
{
return F_113 ( V_111 , & V_173 ) ;
}
static int T_8 F_177 ( void )
{
struct V_174 * V_175 ;
V_175 = F_178 ( L_47 , NULL ) ;
if ( ! V_175 )
return - V_131 ;
if ( ! F_179 ( L_48 , 0444 ,
V_175 , NULL , & V_176 ) )
goto V_177;
if ( ! F_179 ( L_49 , 0444 ,
V_175 , NULL , & V_178 ) )
goto V_177;
return 0 ;
V_177:
F_180 ( V_175 ) ;
return - V_131 ;
}
