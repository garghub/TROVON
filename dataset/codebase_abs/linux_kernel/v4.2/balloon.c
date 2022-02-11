static void F_1 ( struct V_1 * V_1 )
{
#ifdef F_2
F_3 ( V_1 ) ;
#endif
}
static void F_4 ( struct V_1 * V_1 )
{
if ( F_5 ( V_1 ) ) {
F_6 ( & V_1 -> V_2 , & V_3 ) ;
V_4 . V_5 ++ ;
} else {
F_7 ( & V_1 -> V_2 , & V_3 ) ;
V_4 . V_6 ++ ;
}
}
static void F_8 ( struct V_1 * V_1 )
{
F_4 ( V_1 ) ;
F_9 ( V_1 , - 1 ) ;
}
static struct V_1 * F_10 ( bool V_7 )
{
struct V_1 * V_1 ;
if ( F_11 ( & V_3 ) )
return NULL ;
if ( V_7 )
V_1 = F_12 ( V_3 . V_8 , struct V_1 , V_2 ) ;
else
V_1 = F_12 ( V_3 . V_9 , struct V_1 , V_2 ) ;
F_13 ( & V_1 -> V_2 ) ;
if ( F_5 ( V_1 ) )
V_4 . V_5 -- ;
else
V_4 . V_6 -- ;
F_9 ( V_1 , 1 ) ;
return V_1 ;
}
static struct V_1 * F_14 ( struct V_1 * V_1 )
{
struct V_10 * V_9 = V_1 -> V_2 . V_9 ;
if ( V_9 == & V_3 )
return NULL ;
return F_12 ( V_9 , struct V_1 , V_2 ) ;
}
static enum V_11 F_15 ( enum V_11 V_12 )
{
if ( V_12 == V_13 )
return V_13 ;
if ( V_12 == V_14 ) {
V_4 . V_15 = 1 ;
V_4 . V_16 = 1 ;
return V_14 ;
}
++ V_4 . V_16 ;
if ( V_4 . V_17 != V_18 &&
V_4 . V_16 > V_4 . V_17 ) {
V_4 . V_15 = 1 ;
V_4 . V_16 = 1 ;
return V_13 ;
}
V_4 . V_15 <<= 1 ;
if ( V_4 . V_15 > V_4 . V_19 )
V_4 . V_15 = V_4 . V_19 ;
return V_20 ;
}
static long F_16 ( void )
{
return V_4 . V_21 - V_4 . V_22 -
V_4 . V_23 ;
}
static bool F_17 ( void )
{
if ( V_4 . V_6 || V_4 . V_5 ||
V_4 . V_24 )
return true ;
else
return false ;
}
static enum V_11 F_18 ( long V_25 )
{
int V_26 , V_27 ;
T_1 V_28 ;
unsigned long V_24 = V_25 ;
V_28 = F_19 ( F_20 ( V_29 ) ) ;
V_24 = F_21 ( V_24 , V_30 ) ;
V_26 = F_22 ( V_28 ) ;
#ifdef F_23
if ( ! F_24 ( V_31 ) ) {
unsigned long V_32 , V_33 ;
V_32 = F_25 ( V_28 ) ;
for ( V_33 = 0 ; V_33 < V_24 ; V_33 ++ ) {
if ( ! F_26 ( V_32 + V_33 , V_34 ) ) {
F_27 ( L_1 ) ;
return V_13 ;
}
}
}
#endif
V_27 = F_28 ( V_26 , V_28 , V_24 << V_35 ) ;
if ( V_27 ) {
F_27 ( L_2 , V_27 ) ;
return V_13 ;
}
V_24 -= V_25 ;
V_4 . V_23 += V_25 ;
V_4 . V_24 = V_24 ;
return V_14 ;
}
static void F_29 ( struct V_1 * V_1 )
{
F_30 ( V_1 ) ;
F_31 ( & V_36 ) ;
F_4 ( V_1 ) ;
if ( V_4 . V_23 )
-- V_4 . V_23 ;
else
-- V_4 . V_24 ;
F_32 ( & V_36 ) ;
}
static int F_33 ( struct V_37 * V_38 , unsigned long V_39 , void * V_40 )
{
if ( V_39 == V_41 )
F_34 ( & V_42 , 0 ) ;
return V_43 ;
}
static long F_16 ( void )
{
unsigned long V_44 = V_4 . V_21 ;
V_44 = F_35 ( V_44 ,
V_4 . V_22 +
V_4 . V_6 +
V_4 . V_5 ) ;
return V_44 - V_4 . V_22 ;
}
static bool F_17 ( void )
{
if ( V_4 . V_6 || V_4 . V_5 )
return true ;
else
return false ;
}
static enum V_11 F_18 ( long V_25 )
{
V_4 . V_21 = V_4 . V_22 ;
return V_14 ;
}
static enum V_11 F_36 ( unsigned long V_45 )
{
int V_27 ;
unsigned long V_32 , V_33 ;
struct V_1 * V_1 ;
struct V_46 V_47 = {
. V_48 = 0 ,
. V_49 = 0 ,
. V_50 = V_51
} ;
#ifdef F_37
if ( ! V_4 . V_6 && ! V_4 . V_5 ) {
V_45 = F_35 ( V_45 , V_4 . V_24 ) ;
V_4 . V_23 += V_45 ;
V_4 . V_24 -= V_45 ;
return V_14 ;
}
#endif
if ( V_45 > F_38 ( V_52 ) )
V_45 = F_38 ( V_52 ) ;
V_1 = F_39 ( & V_3 , struct V_1 , V_2 ) ;
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ ) {
if ( ! V_1 ) {
V_45 = V_33 ;
break;
}
V_52 [ V_33 ] = F_40 ( V_1 ) ;
V_1 = F_14 ( V_1 ) ;
}
F_41 ( V_47 . V_53 , V_52 ) ;
V_47 . V_54 = V_45 ;
V_27 = F_42 ( V_55 , & V_47 ) ;
if ( V_27 <= 0 )
return V_20 ;
for ( V_33 = 0 ; V_33 < V_27 ; V_33 ++ ) {
V_1 = F_10 ( false ) ;
F_43 ( V_1 == NULL ) ;
V_32 = F_40 ( V_1 ) ;
#ifdef F_23
if ( ! F_24 ( V_31 ) ) {
F_26 ( V_32 , V_52 [ V_33 ] ) ;
if ( ! F_5 ( V_1 ) ) {
int V_56 ;
V_56 = F_44 (
( unsigned long ) F_45 ( V_32 << V_35 ) ,
F_46 ( V_52 [ V_33 ] , V_57 ) ,
0 ) ;
F_43 ( V_56 ) ;
}
}
#endif
F_47 ( V_1 ) ;
}
V_4 . V_22 += V_27 ;
return V_14 ;
}
static enum V_11 F_48 ( unsigned long V_45 , T_2 V_58 )
{
enum V_11 V_12 = V_14 ;
unsigned long V_32 , V_33 ;
struct V_1 * V_1 ;
int V_56 ;
struct V_46 V_47 = {
. V_48 = 0 ,
. V_49 = 0 ,
. V_50 = V_51
} ;
#ifdef F_37
if ( V_4 . V_23 ) {
V_45 = F_35 ( V_45 , V_4 . V_23 ) ;
V_4 . V_23 -= V_45 ;
V_4 . V_24 += V_45 ;
return V_14 ;
}
#endif
if ( V_45 > F_38 ( V_52 ) )
V_45 = F_38 ( V_52 ) ;
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ ) {
V_1 = F_49 ( V_58 ) ;
if ( V_1 == NULL ) {
V_45 = V_33 ;
V_12 = V_20 ;
break;
}
F_1 ( V_1 ) ;
V_52 [ V_33 ] = F_40 ( V_1 ) ;
}
F_50 () ;
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ ) {
V_32 = V_52 [ V_33 ] ;
V_52 [ V_33 ] = F_51 ( V_32 ) ;
V_1 = F_52 ( V_32 ) ;
#ifdef F_23
if ( ! F_24 ( V_31 ) ) {
if ( ! F_5 ( V_1 ) ) {
V_56 = F_44 (
( unsigned long ) F_45 ( V_32 << V_35 ) ,
F_53 ( 0 ) , 0 ) ;
F_43 ( V_56 ) ;
}
F_54 ( V_32 , V_34 ) ;
}
#endif
F_8 ( V_1 ) ;
}
F_55 () ;
F_41 ( V_47 . V_53 , V_52 ) ;
V_47 . V_54 = V_45 ;
V_56 = F_42 ( V_59 , & V_47 ) ;
F_43 ( V_56 != V_45 ) ;
V_4 . V_22 -= V_45 ;
return V_12 ;
}
static void F_56 ( struct V_60 * V_61 )
{
enum V_11 V_12 = V_14 ;
long V_25 ;
do {
F_31 ( & V_36 ) ;
V_25 = F_16 () ;
if ( V_25 > 0 ) {
if ( F_17 () )
V_12 = F_36 ( V_25 ) ;
else
V_12 = F_18 ( V_25 ) ;
}
if ( V_25 < 0 )
V_12 = F_48 ( - V_25 , V_62 ) ;
V_12 = F_15 ( V_12 ) ;
F_32 ( & V_36 ) ;
F_57 () ;
} while ( V_25 && V_12 == V_14 );
if ( V_12 == V_20 )
F_34 ( & V_42 , V_4 . V_15 * V_63 ) ;
}
void F_58 ( unsigned long V_44 )
{
V_4 . V_21 = V_44 ;
F_34 ( & V_42 , 0 ) ;
}
int F_59 ( int V_45 , struct V_1 * * V_64 , bool V_65 )
{
int V_66 = 0 ;
struct V_1 * V_1 ;
F_31 ( & V_36 ) ;
while ( V_66 < V_45 ) {
V_1 = F_10 ( V_65 ) ;
if ( V_1 && ( V_65 || ! F_5 ( V_1 ) ) ) {
V_64 [ V_66 ++ ] = V_1 ;
} else {
enum V_11 V_67 ;
if ( V_1 )
F_8 ( V_1 ) ;
V_67 = F_48 ( V_45 - V_66 ,
V_65 ? V_68 : V_69 ) ;
if ( V_67 != V_14 )
goto V_70;
}
}
F_32 ( & V_36 ) ;
return 0 ;
V_70:
while ( V_66 )
F_8 ( V_64 [ -- V_66 ] ) ;
F_34 ( & V_42 , 0 ) ;
F_32 ( & V_36 ) ;
return - V_71 ;
}
void F_60 ( int V_45 , struct V_1 * * V_64 )
{
int V_33 ;
F_31 ( & V_36 ) ;
for ( V_33 = 0 ; V_33 < V_45 ; V_33 ++ ) {
if ( V_64 [ V_33 ] )
F_8 ( V_64 [ V_33 ] ) ;
}
if ( F_16 () )
F_34 ( & V_42 , 0 ) ;
F_32 ( & V_36 ) ;
}
static void T_3 F_61 ( unsigned long V_72 ,
unsigned long V_64 )
{
unsigned long V_32 , V_73 ;
struct V_1 * V_1 ;
V_73 = F_35 ( V_29 , V_72 + V_64 ) ;
for ( V_32 = V_72 ; V_32 < V_73 ; V_32 ++ ) {
V_1 = F_52 ( V_32 ) ;
F_4 ( V_1 ) ;
}
}
static int T_3 F_62 ( void )
{
int V_33 ;
if ( ! F_63 () )
return - V_74 ;
F_64 ( L_3 ) ;
V_4 . V_22 = F_65 ()
? F_35 ( V_75 -> V_45 - V_76 , V_29 )
: F_66 () ;
V_4 . V_21 = V_4 . V_22 ;
V_4 . V_6 = 0 ;
V_4 . V_5 = 0 ;
V_4 . V_15 = 1 ;
V_4 . V_19 = 32 ;
V_4 . V_16 = 1 ;
V_4 . V_17 = V_18 ;
#ifdef F_37
V_4 . V_23 = 0 ;
V_4 . V_24 = 0 ;
F_67 ( & F_29 ) ;
F_68 ( & V_77 ) ;
#endif
for ( V_33 = 0 ; V_33 < V_78 ; V_33 ++ )
if ( V_79 [ V_33 ] . V_80 )
F_61 ( F_69 ( V_79 [ V_33 ] . V_81 ) ,
F_25 ( V_79 [ V_33 ] . V_80 ) ) ;
return 0 ;
}
