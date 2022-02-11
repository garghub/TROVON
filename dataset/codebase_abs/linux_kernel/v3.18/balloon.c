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
V_27 = F_23 ( V_26 , V_28 , V_24 << V_31 ) ;
if ( V_27 ) {
F_24 ( L_1 , V_27 ) ;
return V_13 ;
}
V_24 -= V_25 ;
V_4 . V_23 += V_25 ;
V_4 . V_24 = V_24 ;
return V_14 ;
}
static void F_25 ( struct V_1 * V_1 )
{
F_26 ( V_1 ) ;
F_27 ( & V_32 ) ;
F_4 ( V_1 ) ;
if ( V_4 . V_23 )
-- V_4 . V_23 ;
else
-- V_4 . V_24 ;
F_28 ( & V_32 ) ;
}
static int F_29 ( struct V_33 * V_34 , unsigned long V_35 , void * V_36 )
{
if ( V_35 == V_37 )
F_30 ( & V_38 , 0 ) ;
return V_39 ;
}
static long F_16 ( void )
{
unsigned long V_40 = V_4 . V_21 ;
V_40 = F_31 ( V_40 ,
V_4 . V_22 +
V_4 . V_6 +
V_4 . V_5 ) ;
return V_40 - V_4 . V_22 ;
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
static enum V_11 F_32 ( unsigned long V_41 )
{
int V_27 ;
unsigned long V_42 , V_43 ;
struct V_1 * V_1 ;
struct V_44 V_45 = {
. V_46 = 0 ,
. V_47 = 0 ,
. V_48 = V_49
} ;
#ifdef F_33
if ( ! V_4 . V_6 && ! V_4 . V_5 ) {
V_41 = F_31 ( V_41 , V_4 . V_24 ) ;
V_4 . V_23 += V_41 ;
V_4 . V_24 -= V_41 ;
return V_14 ;
}
#endif
if ( V_41 > F_34 ( V_50 ) )
V_41 = F_34 ( V_50 ) ;
V_1 = F_35 ( & V_3 , struct V_1 , V_2 ) ;
for ( V_43 = 0 ; V_43 < V_41 ; V_43 ++ ) {
if ( ! V_1 ) {
V_41 = V_43 ;
break;
}
V_50 [ V_43 ] = F_36 ( V_1 ) ;
V_1 = F_14 ( V_1 ) ;
}
F_37 ( V_45 . V_51 , V_50 ) ;
V_45 . V_52 = V_41 ;
V_27 = F_38 ( V_53 , & V_45 ) ;
if ( V_27 <= 0 )
return V_20 ;
for ( V_43 = 0 ; V_43 < V_27 ; V_43 ++ ) {
V_1 = F_10 ( false ) ;
F_39 ( V_1 == NULL ) ;
V_42 = F_36 ( V_1 ) ;
#ifdef F_40
if ( ! F_41 ( V_54 ) ) {
F_42 ( V_42 , V_50 [ V_43 ] ) ;
if ( ! F_5 ( V_1 ) ) {
int V_55 ;
V_55 = F_43 (
( unsigned long ) F_44 ( V_42 << V_31 ) ,
F_45 ( V_50 [ V_43 ] , V_56 ) ,
0 ) ;
F_39 ( V_55 ) ;
}
}
#endif
F_46 ( V_1 ) ;
}
V_4 . V_22 += V_27 ;
return V_14 ;
}
static enum V_11 F_47 ( unsigned long V_41 , T_2 V_57 )
{
enum V_11 V_12 = V_14 ;
unsigned long V_42 , V_43 ;
struct V_1 * V_1 ;
int V_55 ;
struct V_44 V_45 = {
. V_46 = 0 ,
. V_47 = 0 ,
. V_48 = V_49
} ;
#ifdef F_33
if ( V_4 . V_23 ) {
V_41 = F_31 ( V_41 , V_4 . V_23 ) ;
V_4 . V_23 -= V_41 ;
V_4 . V_24 += V_41 ;
return V_14 ;
}
#endif
if ( V_41 > F_34 ( V_50 ) )
V_41 = F_34 ( V_50 ) ;
for ( V_43 = 0 ; V_43 < V_41 ; V_43 ++ ) {
V_1 = F_48 ( V_57 ) ;
if ( V_1 == NULL ) {
V_41 = V_43 ;
V_12 = V_20 ;
break;
}
F_1 ( V_1 ) ;
V_50 [ V_43 ] = F_36 ( V_1 ) ;
}
F_49 () ;
for ( V_43 = 0 ; V_43 < V_41 ; V_43 ++ ) {
V_42 = V_50 [ V_43 ] ;
V_50 [ V_43 ] = F_50 ( V_42 ) ;
V_1 = F_51 ( V_42 ) ;
#ifdef F_40
if ( ! F_41 ( V_54 ) ) {
if ( ! F_5 ( V_1 ) ) {
struct V_1 * V_58 = F_52 () ;
V_55 = F_43 (
( unsigned long ) F_44 ( V_42 << V_31 ) ,
F_53 ( F_36 ( V_58 ) ,
V_59 ) , 0 ) ;
F_39 ( V_55 ) ;
F_54 () ;
}
F_55 ( V_42 , V_60 ) ;
}
#endif
F_8 ( V_1 ) ;
}
F_56 () ;
F_37 ( V_45 . V_51 , V_50 ) ;
V_45 . V_52 = V_41 ;
V_55 = F_38 ( V_61 , & V_45 ) ;
F_39 ( V_55 != V_41 ) ;
V_4 . V_22 -= V_41 ;
return V_12 ;
}
static void F_57 ( struct V_62 * V_63 )
{
enum V_11 V_12 = V_14 ;
long V_25 ;
F_27 ( & V_32 ) ;
do {
V_25 = F_16 () ;
if ( V_25 > 0 ) {
if ( F_17 () )
V_12 = F_32 ( V_25 ) ;
else
V_12 = F_18 ( V_25 ) ;
}
if ( V_25 < 0 )
V_12 = F_47 ( - V_25 , V_64 ) ;
V_12 = F_15 ( V_12 ) ;
#ifndef F_58
if ( F_59 () )
F_60 () ;
#endif
} while ( V_25 && V_12 == V_14 );
if ( V_12 == V_20 )
F_30 ( & V_38 , V_4 . V_15 * V_65 ) ;
F_28 ( & V_32 ) ;
}
struct V_1 * F_52 ( void )
{
struct V_1 * V_55 = F_61 ( V_66 ) ;
F_39 ( V_55 == NULL ) ;
return V_55 ;
}
void F_54 ( void )
{
F_62 ( V_66 ) ;
}
void F_63 ( unsigned long V_40 )
{
V_4 . V_21 = V_40 ;
F_30 ( & V_38 , 0 ) ;
}
int F_64 ( int V_41 , struct V_1 * * V_67 , bool V_68 )
{
int V_69 = 0 ;
struct V_1 * V_1 ;
F_27 ( & V_32 ) ;
while ( V_69 < V_41 ) {
V_1 = F_10 ( V_68 ) ;
if ( V_1 && ( V_68 || ! F_5 ( V_1 ) ) ) {
V_67 [ V_69 ++ ] = V_1 ;
} else {
enum V_11 V_70 ;
if ( V_1 )
F_8 ( V_1 ) ;
V_70 = F_47 ( V_41 - V_69 ,
V_68 ? V_71 : V_72 ) ;
if ( V_70 != V_14 )
goto V_73;
}
}
F_28 ( & V_32 ) ;
return 0 ;
V_73:
while ( V_69 )
F_8 ( V_67 [ -- V_69 ] ) ;
F_30 ( & V_38 , 0 ) ;
F_28 ( & V_32 ) ;
return - V_74 ;
}
void F_65 ( int V_41 , struct V_1 * * V_67 )
{
int V_43 ;
F_27 ( & V_32 ) ;
for ( V_43 = 0 ; V_43 < V_41 ; V_43 ++ ) {
if ( V_67 [ V_43 ] )
F_8 ( V_67 [ V_43 ] ) ;
}
if ( F_16 () )
F_30 ( & V_38 , 0 ) ;
F_28 ( & V_32 ) ;
}
static void T_3 F_66 ( unsigned long V_75 ,
unsigned long V_67 )
{
unsigned long V_42 , V_76 ;
struct V_1 * V_1 ;
V_76 = F_31 ( V_29 , V_75 + V_67 ) ;
for ( V_42 = V_75 ; V_42 < V_76 ; V_42 ++ ) {
V_1 = F_51 ( V_42 ) ;
F_4 ( V_1 ) ;
}
}
static int F_67 ( int V_77 )
{
if ( F_68 ( V_66 , V_77 ) != NULL )
return 0 ;
F_68 ( V_66 , V_77 ) = F_48 ( V_78 ) ;
if ( F_68 ( V_66 , V_77 ) == NULL ) {
F_24 ( L_2 , V_77 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_69 ( struct V_33 * V_79 ,
unsigned long V_80 , void * V_81 )
{
int V_77 = ( long ) V_81 ;
switch ( V_80 ) {
case V_82 :
if ( F_67 ( V_77 ) )
return V_83 ;
break;
default:
break;
}
return V_39 ;
}
static int T_3 F_70 ( void )
{
int V_43 , V_77 ;
if ( ! F_71 () )
return - V_84 ;
if ( ! F_41 ( V_54 ) ) {
F_72 ( & V_85 ) ;
F_73 () ;
F_74 (cpu) {
if ( F_67 ( V_77 ) ) {
F_75 () ;
F_76 ( & V_85 ) ;
return - V_74 ;
}
}
F_75 () ;
}
F_77 ( L_3 ) ;
V_4 . V_22 = F_78 ()
? F_31 ( V_86 -> V_41 - V_87 , V_29 )
: F_79 () ;
V_4 . V_21 = V_4 . V_22 ;
V_4 . V_6 = 0 ;
V_4 . V_5 = 0 ;
V_4 . V_15 = 1 ;
V_4 . V_19 = 32 ;
V_4 . V_16 = 1 ;
V_4 . V_17 = V_18 ;
#ifdef F_33
V_4 . V_23 = 0 ;
V_4 . V_24 = 0 ;
F_80 ( & F_25 ) ;
F_81 ( & V_88 ) ;
#endif
for ( V_43 = 0 ; V_43 < V_89 ; V_43 ++ )
if ( V_90 [ V_43 ] . V_91 )
F_66 ( F_82 ( V_90 [ V_43 ] . V_92 ) ,
F_83 ( V_90 [ V_43 ] . V_91 ) ) ;
return 0 ;
}
static int T_3 F_84 ( void )
{
int V_77 ;
F_85 (cpu)
F_68 ( V_66 , V_77 ) = NULL ;
return 0 ;
}
