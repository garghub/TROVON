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
static struct V_1 * F_14 ( void )
{
if ( F_11 ( & V_3 ) )
return NULL ;
return F_12 ( V_3 . V_9 , struct V_1 , V_2 ) ;
}
static struct V_1 * F_15 ( struct V_1 * V_1 )
{
struct V_10 * V_9 = V_1 -> V_2 . V_9 ;
if ( V_9 == & V_3 )
return NULL ;
return F_12 ( V_9 , struct V_1 , V_2 ) ;
}
static enum V_11 F_16 ( enum V_11 V_12 )
{
if ( V_12 == V_13 ) {
V_4 . V_14 = 1 ;
V_4 . V_15 = 1 ;
return V_13 ;
}
++ V_4 . V_15 ;
if ( V_4 . V_16 != V_17 &&
V_4 . V_15 > V_4 . V_16 ) {
V_4 . V_14 = 1 ;
V_4 . V_15 = 1 ;
return V_18 ;
}
V_4 . V_14 <<= 1 ;
if ( V_4 . V_14 > V_4 . V_19 )
V_4 . V_14 = V_4 . V_19 ;
return V_20 ;
}
static long F_17 ( void )
{
return V_4 . V_21 - V_4 . V_22 -
V_4 . V_23 ;
}
static bool F_18 ( void )
{
if ( V_4 . V_6 || V_4 . V_5 ||
V_4 . V_24 )
return true ;
else
return false ;
}
static enum V_11 F_19 ( long V_25 )
{
int V_26 , V_27 ;
T_1 V_28 ;
unsigned long V_24 = V_25 ;
V_28 = F_20 ( F_21 ( V_29 ) ) ;
V_24 = F_22 ( V_24 , V_30 ) ;
V_26 = F_23 ( V_28 ) ;
V_27 = F_24 ( V_26 , V_28 , V_24 << V_31 ) ;
if ( V_27 ) {
F_25 ( L_1 , V_32 , V_27 ) ;
return V_20 ;
}
V_24 -= V_25 ;
V_4 . V_23 += V_25 ;
V_4 . V_24 = V_24 ;
return V_13 ;
}
static void F_26 ( struct V_1 * V_1 )
{
F_27 ( V_1 ) ;
F_28 ( & V_33 ) ;
F_4 ( V_1 ) ;
if ( V_4 . V_23 )
-- V_4 . V_23 ;
else
-- V_4 . V_24 ;
F_29 ( & V_33 ) ;
}
static int F_30 ( struct V_34 * V_35 , unsigned long V_36 , void * V_37 )
{
if ( V_36 == V_38 )
F_31 ( & V_39 , 0 ) ;
return V_40 ;
}
static long F_17 ( void )
{
unsigned long V_41 = V_4 . V_21 ;
V_41 = F_32 ( V_41 ,
V_4 . V_22 +
V_4 . V_6 +
V_4 . V_5 ) ;
return V_41 - V_4 . V_22 ;
}
static bool F_18 ( void )
{
if ( V_4 . V_6 || V_4 . V_5 )
return true ;
else
return false ;
}
static enum V_11 F_19 ( long V_25 )
{
V_4 . V_21 = V_4 . V_22 ;
return V_13 ;
}
static enum V_11 F_33 ( unsigned long V_42 )
{
int V_27 ;
unsigned long V_43 , V_44 ;
struct V_1 * V_1 ;
struct V_45 V_46 = {
. V_47 = 0 ,
. V_48 = 0 ,
. V_49 = V_50
} ;
#ifdef F_34
if ( ! V_4 . V_6 && ! V_4 . V_5 ) {
V_42 = F_32 ( V_42 , V_4 . V_24 ) ;
V_4 . V_23 += V_42 ;
V_4 . V_24 -= V_42 ;
return V_13 ;
}
#endif
if ( V_42 > F_35 ( V_51 ) )
V_42 = F_35 ( V_51 ) ;
V_1 = F_14 () ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
if ( ! V_1 ) {
V_42 = V_44 ;
break;
}
V_51 [ V_44 ] = F_36 ( V_1 ) ;
V_1 = F_15 ( V_1 ) ;
}
F_37 ( V_46 . V_52 , V_51 ) ;
V_46 . V_53 = V_42 ;
V_27 = F_38 ( V_54 , & V_46 ) ;
if ( V_27 <= 0 )
return V_20 ;
for ( V_44 = 0 ; V_44 < V_27 ; V_44 ++ ) {
V_1 = F_10 ( false ) ;
F_39 ( V_1 == NULL ) ;
V_43 = F_36 ( V_1 ) ;
F_39 ( ! F_40 ( V_55 ) &&
F_41 ( V_43 ) ) ;
F_42 ( V_43 , V_51 [ V_44 ] ) ;
#ifdef F_43
if ( F_44 () && ! F_5 ( V_1 ) ) {
int V_56 ;
V_56 = F_45 (
( unsigned long ) F_46 ( V_43 << V_31 ) ,
F_47 ( V_51 [ V_44 ] , V_57 ) ,
0 ) ;
F_39 ( V_56 ) ;
}
#endif
F_48 ( V_1 ) ;
}
V_4 . V_22 += V_27 ;
return V_13 ;
}
static enum V_11 F_49 ( unsigned long V_42 , T_2 V_58 )
{
enum V_11 V_12 = V_13 ;
unsigned long V_43 , V_44 ;
struct V_1 * V_1 ;
int V_56 ;
struct V_45 V_46 = {
. V_47 = 0 ,
. V_48 = 0 ,
. V_49 = V_50
} ;
#ifdef F_34
if ( V_4 . V_23 ) {
V_42 = F_32 ( V_42 , V_4 . V_23 ) ;
V_4 . V_23 -= V_42 ;
V_4 . V_24 += V_42 ;
return V_13 ;
}
#endif
if ( V_42 > F_35 ( V_51 ) )
V_42 = F_35 ( V_51 ) ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
V_1 = F_50 ( V_58 ) ;
if ( V_1 == NULL ) {
V_42 = V_44 ;
V_12 = V_20 ;
break;
}
V_43 = F_36 ( V_1 ) ;
V_51 [ V_44 ] = F_51 ( V_43 ) ;
F_1 ( V_1 ) ;
#ifdef F_43
if ( F_44 () && ! F_5 ( V_1 ) ) {
V_56 = F_45 (
( unsigned long ) F_46 ( V_43 << V_31 ) ,
F_52 ( 0 ) , 0 ) ;
F_39 ( V_56 ) ;
}
#endif
}
F_53 () ;
F_54 () ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
V_43 = F_55 ( V_51 [ V_44 ] ) ;
F_56 ( V_43 , V_59 ) ;
F_8 ( F_57 ( V_43 ) ) ;
}
F_37 ( V_46 . V_52 , V_51 ) ;
V_46 . V_53 = V_42 ;
V_56 = F_38 ( V_60 , & V_46 ) ;
F_39 ( V_56 != V_42 ) ;
V_4 . V_22 -= V_42 ;
return V_12 ;
}
static void F_58 ( struct V_61 * V_62 )
{
enum V_11 V_12 = V_13 ;
long V_25 ;
F_28 ( & V_33 ) ;
do {
V_25 = F_17 () ;
if ( V_25 > 0 ) {
if ( F_18 () )
V_12 = F_33 ( V_25 ) ;
else
V_12 = F_19 ( V_25 ) ;
}
if ( V_25 < 0 )
V_12 = F_49 ( - V_25 , V_63 ) ;
V_12 = F_16 ( V_12 ) ;
#ifndef F_59
if ( F_60 () )
F_61 () ;
#endif
} while ( V_25 && V_12 == V_13 );
if ( V_12 == V_20 )
F_31 ( & V_39 , V_4 . V_14 * V_64 ) ;
F_29 ( & V_33 ) ;
}
void F_62 ( unsigned long V_41 )
{
V_4 . V_21 = V_41 ;
F_31 ( & V_39 , 0 ) ;
}
int F_63 ( int V_42 , struct V_1 * * V_65 , bool V_66 )
{
int V_67 = 0 ;
struct V_1 * V_1 ;
F_28 ( & V_33 ) ;
while ( V_67 < V_42 ) {
V_1 = F_10 ( V_66 ) ;
if ( V_1 && ( V_66 || ! F_5 ( V_1 ) ) ) {
V_65 [ V_67 ++ ] = V_1 ;
} else {
enum V_11 V_68 ;
if ( V_1 )
F_8 ( V_1 ) ;
V_68 = F_49 ( V_42 - V_67 ,
V_66 ? V_69 : V_70 ) ;
if ( V_68 != V_13 )
goto V_71;
}
}
F_29 ( & V_33 ) ;
return 0 ;
V_71:
while ( V_67 )
F_8 ( V_65 [ -- V_67 ] ) ;
F_31 ( & V_39 , 0 ) ;
F_29 ( & V_33 ) ;
return - V_72 ;
}
void F_64 ( int V_42 , struct V_1 * * V_65 )
{
int V_44 ;
F_28 ( & V_33 ) ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
if ( V_65 [ V_44 ] )
F_8 ( V_65 [ V_44 ] ) ;
}
if ( F_17 () )
F_31 ( & V_39 , 0 ) ;
F_29 ( & V_33 ) ;
}
static void T_3 F_65 ( unsigned long V_73 ,
unsigned long V_65 )
{
unsigned long V_43 , V_74 ;
struct V_1 * V_1 ;
V_74 = F_32 ( V_29 , V_73 + V_65 ) ;
for ( V_43 = V_73 ; V_43 < V_74 ; V_43 ++ ) {
V_1 = F_57 ( V_43 ) ;
F_4 ( V_1 ) ;
}
}
static int T_3 F_66 ( void )
{
int V_44 ;
if ( ! F_67 () )
return - V_75 ;
F_25 ( L_2 ) ;
V_4 . V_22 = F_44 ()
? F_32 ( V_76 -> V_42 - V_77 , V_29 )
: V_29 ;
V_4 . V_21 = V_4 . V_22 ;
V_4 . V_6 = 0 ;
V_4 . V_5 = 0 ;
V_4 . V_14 = 1 ;
V_4 . V_19 = 32 ;
V_4 . V_15 = 1 ;
V_4 . V_16 = V_17 ;
#ifdef F_34
V_4 . V_23 = 0 ;
V_4 . V_24 = 0 ;
F_68 ( & F_26 ) ;
F_69 ( & V_78 ) ;
#endif
for ( V_44 = 0 ; V_44 < V_79 ; V_44 ++ )
if ( V_80 [ V_44 ] . V_81 )
F_65 ( F_70 ( V_80 [ V_44 ] . V_82 ) ,
F_71 ( V_80 [ V_44 ] . V_81 ) ) ;
return 0 ;
}
