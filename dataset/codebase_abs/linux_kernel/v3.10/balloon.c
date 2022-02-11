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
if ( F_5 ( V_1 ) )
F_9 () ;
V_7 -- ;
}
static struct V_1 * F_10 ( bool V_8 )
{
struct V_1 * V_1 ;
if ( F_11 ( & V_3 ) )
return NULL ;
if ( V_8 )
V_1 = F_12 ( V_3 . V_9 , struct V_1 , V_2 ) ;
else
V_1 = F_12 ( V_3 . V_10 , struct V_1 , V_2 ) ;
F_13 ( & V_1 -> V_2 ) ;
if ( F_5 ( V_1 ) ) {
V_4 . V_5 -- ;
F_14 () ;
} else
V_4 . V_6 -- ;
V_7 ++ ;
return V_1 ;
}
static struct V_1 * F_15 ( void )
{
if ( F_11 ( & V_3 ) )
return NULL ;
return F_12 ( V_3 . V_10 , struct V_1 , V_2 ) ;
}
static struct V_1 * F_16 ( struct V_1 * V_1 )
{
struct V_11 * V_10 = V_1 -> V_2 . V_10 ;
if ( V_10 == & V_3 )
return NULL ;
return F_12 ( V_10 , struct V_1 , V_2 ) ;
}
static enum V_12 F_17 ( enum V_12 V_13 )
{
if ( V_13 == V_14 ) {
V_4 . V_15 = 1 ;
V_4 . V_16 = 1 ;
return V_14 ;
}
++ V_4 . V_16 ;
if ( V_4 . V_17 != V_18 &&
V_4 . V_16 > V_4 . V_17 ) {
V_4 . V_15 = 1 ;
V_4 . V_16 = 1 ;
return V_19 ;
}
V_4 . V_15 <<= 1 ;
if ( V_4 . V_15 > V_4 . V_20 )
V_4 . V_15 = V_4 . V_20 ;
return V_21 ;
}
static long F_18 ( void )
{
return V_4 . V_22 - V_4 . V_23 -
V_4 . V_24 ;
}
static bool F_19 ( void )
{
if ( V_4 . V_6 || V_4 . V_5 ||
V_4 . V_25 )
return true ;
else
return false ;
}
static enum V_12 F_20 ( long V_26 )
{
int V_27 , V_28 ;
T_1 V_29 ;
unsigned long V_25 = V_26 ;
V_29 = F_21 ( F_22 ( V_30 ) ) ;
V_25 = F_23 ( V_25 , V_31 ) ;
V_27 = F_24 ( V_29 ) ;
V_28 = F_25 ( V_27 , V_29 , V_25 << V_32 ) ;
if ( V_28 ) {
F_26 ( L_1 , V_33 , V_28 ) ;
return V_21 ;
}
V_25 -= V_26 ;
V_4 . V_24 += V_26 ;
V_4 . V_25 = V_25 ;
return V_14 ;
}
static void F_27 ( struct V_1 * V_1 )
{
F_28 ( V_1 ) ;
F_29 ( & V_34 ) ;
F_4 ( V_1 ) ;
if ( V_4 . V_24 )
-- V_4 . V_24 ;
else
-- V_4 . V_25 ;
F_30 ( & V_34 ) ;
}
static int F_31 ( struct V_35 * V_36 , unsigned long V_37 , void * V_38 )
{
if ( V_37 == V_39 )
F_32 ( & V_40 , 0 ) ;
return V_41 ;
}
static long F_18 ( void )
{
unsigned long V_42 = V_4 . V_22 ;
V_42 = F_33 ( V_42 ,
V_4 . V_23 +
V_4 . V_6 +
V_4 . V_5 ) ;
return V_42 - V_4 . V_23 ;
}
static bool F_19 ( void )
{
if ( V_4 . V_6 || V_4 . V_5 )
return true ;
else
return false ;
}
static enum V_12 F_20 ( long V_26 )
{
V_4 . V_22 = V_4 . V_23 ;
return V_14 ;
}
static enum V_12 F_34 ( unsigned long V_43 )
{
int V_28 ;
unsigned long V_44 , V_45 ;
struct V_1 * V_1 ;
struct V_46 V_47 = {
. V_48 = 0 ,
. V_49 = 0 ,
. V_50 = V_51
} ;
#ifdef F_35
if ( ! V_4 . V_6 && ! V_4 . V_5 ) {
V_43 = F_33 ( V_43 , V_4 . V_25 ) ;
V_4 . V_24 += V_43 ;
V_4 . V_25 -= V_43 ;
return V_14 ;
}
#endif
if ( V_43 > F_36 ( V_52 ) )
V_43 = F_36 ( V_52 ) ;
V_1 = F_15 () ;
for ( V_45 = 0 ; V_45 < V_43 ; V_45 ++ ) {
if ( ! V_1 ) {
V_43 = V_45 ;
break;
}
V_52 [ V_45 ] = F_37 ( V_1 ) ;
V_1 = F_16 ( V_1 ) ;
}
F_38 ( V_47 . V_53 , V_52 ) ;
V_47 . V_54 = V_43 ;
V_28 = F_39 ( V_55 , & V_47 ) ;
if ( V_28 <= 0 )
return V_21 ;
for ( V_45 = 0 ; V_45 < V_28 ; V_45 ++ ) {
V_1 = F_10 ( false ) ;
F_40 ( V_1 == NULL ) ;
V_44 = F_37 ( V_1 ) ;
F_40 ( ! F_41 ( V_56 ) &&
F_42 ( V_44 ) ) ;
F_43 ( V_44 , V_52 [ V_45 ] ) ;
#ifdef F_44
if ( F_45 () && ! F_5 ( V_1 ) ) {
int V_57 ;
V_57 = F_46 (
( unsigned long ) F_47 ( V_44 << V_32 ) ,
F_48 ( V_52 [ V_45 ] , V_58 ) ,
0 ) ;
F_40 ( V_57 ) ;
}
#endif
F_49 ( V_1 ) ;
F_50 ( V_1 ) ;
F_51 ( V_1 ) ;
}
V_4 . V_23 += V_28 ;
return V_14 ;
}
static enum V_12 F_52 ( unsigned long V_43 , T_2 V_59 )
{
enum V_12 V_13 = V_14 ;
unsigned long V_44 , V_45 ;
struct V_1 * V_1 ;
int V_57 ;
struct V_46 V_47 = {
. V_48 = 0 ,
. V_49 = 0 ,
. V_50 = V_51
} ;
#ifdef F_35
if ( V_4 . V_24 ) {
V_43 = F_33 ( V_43 , V_4 . V_24 ) ;
V_4 . V_24 -= V_43 ;
V_4 . V_25 += V_43 ;
return V_14 ;
}
#endif
if ( V_43 > F_36 ( V_52 ) )
V_43 = F_36 ( V_52 ) ;
for ( V_45 = 0 ; V_45 < V_43 ; V_45 ++ ) {
V_1 = F_53 ( V_59 ) ;
if ( V_1 == NULL ) {
V_43 = V_45 ;
V_13 = V_21 ;
break;
}
V_44 = F_37 ( V_1 ) ;
V_52 [ V_45 ] = F_54 ( V_44 ) ;
F_1 ( V_1 ) ;
#ifdef F_44
if ( F_45 () && ! F_5 ( V_1 ) ) {
V_57 = F_46 (
( unsigned long ) F_47 ( V_44 << V_32 ) ,
F_55 ( 0 ) , 0 ) ;
F_40 ( V_57 ) ;
}
#endif
}
F_56 () ;
F_57 () ;
for ( V_45 = 0 ; V_45 < V_43 ; V_45 ++ ) {
V_44 = F_58 ( V_52 [ V_45 ] ) ;
F_59 ( V_44 , V_60 ) ;
F_8 ( F_60 ( V_44 ) ) ;
}
F_38 ( V_47 . V_53 , V_52 ) ;
V_47 . V_54 = V_43 ;
V_57 = F_39 ( V_61 , & V_47 ) ;
F_40 ( V_57 != V_43 ) ;
V_4 . V_23 -= V_43 ;
return V_13 ;
}
static void F_61 ( struct V_62 * V_63 )
{
enum V_12 V_13 = V_14 ;
long V_26 ;
F_29 ( & V_34 ) ;
do {
V_26 = F_18 () ;
if ( V_26 > 0 ) {
if ( F_19 () )
V_13 = F_34 ( V_26 ) ;
else
V_13 = F_20 ( V_26 ) ;
}
if ( V_26 < 0 )
V_13 = F_52 ( - V_26 , V_64 ) ;
V_13 = F_17 ( V_13 ) ;
#ifndef F_62
if ( F_63 () )
F_64 () ;
#endif
} while ( V_26 && V_13 == V_14 );
if ( V_13 == V_21 )
F_32 ( & V_40 , V_4 . V_15 * V_65 ) ;
F_30 ( & V_34 ) ;
}
void F_65 ( unsigned long V_42 )
{
V_4 . V_22 = V_42 ;
F_32 ( & V_40 , 0 ) ;
}
int F_66 ( int V_43 , struct V_1 * * V_66 , bool V_67 )
{
int V_68 = 0 ;
struct V_1 * V_1 ;
F_29 ( & V_34 ) ;
while ( V_68 < V_43 ) {
V_1 = F_10 ( V_67 ) ;
if ( V_1 && ( V_67 || ! F_5 ( V_1 ) ) ) {
V_66 [ V_68 ++ ] = V_1 ;
} else {
enum V_12 V_69 ;
if ( V_1 )
F_8 ( V_1 ) ;
V_69 = F_52 ( V_43 - V_68 ,
V_67 ? V_70 : V_71 ) ;
if ( V_69 != V_14 )
goto V_72;
}
}
F_30 ( & V_34 ) ;
return 0 ;
V_72:
while ( V_68 )
F_8 ( V_66 [ -- V_68 ] ) ;
F_32 ( & V_40 , 0 ) ;
F_30 ( & V_34 ) ;
return - V_73 ;
}
void F_67 ( int V_43 , struct V_1 * * V_66 )
{
int V_45 ;
F_29 ( & V_34 ) ;
for ( V_45 = 0 ; V_45 < V_43 ; V_45 ++ ) {
if ( V_66 [ V_45 ] )
F_8 ( V_66 [ V_45 ] ) ;
}
if ( F_18 () )
F_32 ( & V_40 , 0 ) ;
F_30 ( & V_34 ) ;
}
static void T_3 F_68 ( unsigned long V_74 ,
unsigned long V_66 )
{
unsigned long V_44 , V_75 ;
struct V_1 * V_1 ;
V_75 = F_33 ( V_30 , V_74 + V_66 ) ;
for ( V_44 = V_74 ; V_44 < V_75 ; V_44 ++ ) {
V_1 = F_60 ( V_44 ) ;
F_4 ( V_1 ) ;
}
}
static int T_3 F_69 ( void )
{
int V_45 ;
if ( ! F_70 () )
return - V_76 ;
F_26 ( L_2 ) ;
V_4 . V_23 = F_45 ()
? F_33 ( V_77 -> V_43 - V_78 , V_30 )
: V_30 ;
V_4 . V_22 = V_4 . V_23 ;
V_4 . V_6 = 0 ;
V_4 . V_5 = 0 ;
V_4 . V_15 = 1 ;
V_4 . V_20 = 32 ;
V_4 . V_16 = 1 ;
V_4 . V_17 = V_18 ;
#ifdef F_35
V_4 . V_24 = 0 ;
V_4 . V_25 = 0 ;
F_71 ( & F_27 ) ;
F_72 ( & V_79 ) ;
#endif
for ( V_45 = 0 ; V_45 < V_80 ; V_45 ++ )
if ( V_81 [ V_45 ] . V_82 )
F_68 ( F_73 ( V_81 [ V_45 ] . V_83 ) ,
F_74 ( V_81 [ V_45 ] . V_82 ) ) ;
return 0 ;
}
