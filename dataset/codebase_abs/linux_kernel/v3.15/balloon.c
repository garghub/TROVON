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
F_24 ( L_1 , V_32 , V_27 ) ;
return V_20 ;
}
V_24 -= V_25 ;
V_4 . V_23 += V_25 ;
V_4 . V_24 = V_24 ;
return V_13 ;
}
static void F_25 ( struct V_1 * V_1 )
{
F_26 ( V_1 ) ;
F_27 ( & V_33 ) ;
F_4 ( V_1 ) ;
if ( V_4 . V_23 )
-- V_4 . V_23 ;
else
-- V_4 . V_24 ;
F_28 ( & V_33 ) ;
}
static int F_29 ( struct V_34 * V_35 , unsigned long V_36 , void * V_37 )
{
if ( V_36 == V_38 )
F_30 ( & V_39 , 0 ) ;
return V_40 ;
}
static long F_16 ( void )
{
unsigned long V_41 = V_4 . V_21 ;
V_41 = F_31 ( V_41 ,
V_4 . V_22 +
V_4 . V_6 +
V_4 . V_5 ) ;
return V_41 - V_4 . V_22 ;
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
return V_13 ;
}
static enum V_11 F_32 ( unsigned long V_42 )
{
int V_27 ;
unsigned long V_43 , V_44 ;
struct V_1 * V_1 ;
struct V_45 V_46 = {
. V_47 = 0 ,
. V_48 = 0 ,
. V_49 = V_50
} ;
#ifdef F_33
if ( ! V_4 . V_6 && ! V_4 . V_5 ) {
V_42 = F_31 ( V_42 , V_4 . V_24 ) ;
V_4 . V_23 += V_42 ;
V_4 . V_24 -= V_42 ;
return V_13 ;
}
#endif
if ( V_42 > F_34 ( V_51 ) )
V_42 = F_34 ( V_51 ) ;
V_1 = F_35 ( & V_3 , struct V_1 , V_2 ) ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
if ( ! V_1 ) {
V_42 = V_44 ;
break;
}
V_51 [ V_44 ] = F_36 ( V_1 ) ;
V_1 = F_14 ( V_1 ) ;
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
#ifdef F_40
if ( ! F_41 ( V_55 ) ) {
F_42 ( V_43 , V_51 [ V_44 ] ) ;
if ( ! F_5 ( V_1 ) ) {
int V_56 ;
V_56 = F_43 (
( unsigned long ) F_44 ( V_43 << V_31 ) ,
F_45 ( V_51 [ V_44 ] , V_57 ) ,
0 ) ;
F_39 ( V_56 ) ;
}
}
#endif
F_46 ( V_1 ) ;
}
V_4 . V_22 += V_27 ;
return V_13 ;
}
static enum V_11 F_47 ( unsigned long V_42 , T_2 V_58 )
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
#ifdef F_33
if ( V_4 . V_23 ) {
V_42 = F_31 ( V_42 , V_4 . V_23 ) ;
V_4 . V_23 -= V_42 ;
V_4 . V_24 += V_42 ;
return V_13 ;
}
#endif
if ( V_42 > F_34 ( V_51 ) )
V_42 = F_34 ( V_51 ) ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
V_1 = F_48 ( V_58 ) ;
if ( V_1 == NULL ) {
V_42 = V_44 ;
V_12 = V_20 ;
break;
}
F_1 ( V_1 ) ;
V_51 [ V_44 ] = F_36 ( V_1 ) ;
}
F_49 () ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
V_43 = V_51 [ V_44 ] ;
V_51 [ V_44 ] = F_50 ( V_43 ) ;
V_1 = F_51 ( V_43 ) ;
#ifdef F_40
if ( ! F_41 ( V_55 ) ) {
unsigned long V_59 ;
struct V_1 * V_60 = F_52 () ;
if ( ! F_5 ( V_1 ) ) {
V_56 = F_43 (
( unsigned long ) F_44 ( V_43 << V_31 ) ,
F_53 ( F_36 ( V_60 ) ,
V_61 ) , 0 ) ;
F_39 ( V_56 ) ;
}
V_59 = F_36 ( V_60 ) ;
F_54 ( V_43 , F_50 ( V_59 ) ) ;
F_55 () ;
}
#endif
F_8 ( V_1 ) ;
}
F_56 () ;
F_37 ( V_46 . V_52 , V_51 ) ;
V_46 . V_53 = V_42 ;
V_56 = F_38 ( V_62 , & V_46 ) ;
F_39 ( V_56 != V_42 ) ;
V_4 . V_22 -= V_42 ;
return V_12 ;
}
static void F_57 ( struct V_63 * V_64 )
{
enum V_11 V_12 = V_13 ;
long V_25 ;
F_27 ( & V_33 ) ;
do {
V_25 = F_16 () ;
if ( V_25 > 0 ) {
if ( F_17 () )
V_12 = F_32 ( V_25 ) ;
else
V_12 = F_18 ( V_25 ) ;
}
if ( V_25 < 0 )
V_12 = F_47 ( - V_25 , V_65 ) ;
V_12 = F_15 ( V_12 ) ;
#ifndef F_58
if ( F_59 () )
F_60 () ;
#endif
} while ( V_25 && V_12 == V_13 );
if ( V_12 == V_20 )
F_30 ( & V_39 , V_4 . V_14 * V_66 ) ;
F_28 ( & V_33 ) ;
}
struct V_1 * F_52 ( void )
{
struct V_1 * V_56 = F_61 ( V_67 ) ;
F_39 ( V_56 == NULL ) ;
return V_56 ;
}
void F_55 ( void )
{
F_62 ( V_67 ) ;
}
void F_63 ( unsigned long V_41 )
{
V_4 . V_21 = V_41 ;
F_30 ( & V_39 , 0 ) ;
}
int F_64 ( int V_42 , struct V_1 * * V_68 , bool V_69 )
{
int V_70 = 0 ;
struct V_1 * V_1 ;
F_27 ( & V_33 ) ;
while ( V_70 < V_42 ) {
V_1 = F_10 ( V_69 ) ;
if ( V_1 && ( V_69 || ! F_5 ( V_1 ) ) ) {
V_68 [ V_70 ++ ] = V_1 ;
} else {
enum V_11 V_71 ;
if ( V_1 )
F_8 ( V_1 ) ;
V_71 = F_47 ( V_42 - V_70 ,
V_69 ? V_72 : V_73 ) ;
if ( V_71 != V_13 )
goto V_74;
}
}
F_28 ( & V_33 ) ;
return 0 ;
V_74:
while ( V_70 )
F_8 ( V_68 [ -- V_70 ] ) ;
F_30 ( & V_39 , 0 ) ;
F_28 ( & V_33 ) ;
return - V_75 ;
}
void F_65 ( int V_42 , struct V_1 * * V_68 )
{
int V_44 ;
F_27 ( & V_33 ) ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
if ( V_68 [ V_44 ] )
F_8 ( V_68 [ V_44 ] ) ;
}
if ( F_16 () )
F_30 ( & V_39 , 0 ) ;
F_28 ( & V_33 ) ;
}
static void T_3 F_66 ( unsigned long V_76 ,
unsigned long V_68 )
{
unsigned long V_43 , V_77 ;
struct V_1 * V_1 ;
V_77 = F_31 ( V_29 , V_76 + V_68 ) ;
for ( V_43 = V_76 ; V_43 < V_77 ; V_43 ++ ) {
V_1 = F_51 ( V_43 ) ;
F_4 ( V_1 ) ;
}
}
static int F_67 ( int V_78 )
{
if ( F_68 ( V_67 , V_78 ) != NULL )
return 0 ;
F_68 ( V_67 , V_78 ) = F_48 ( V_79 ) ;
if ( F_68 ( V_67 , V_78 ) == NULL ) {
F_69 ( L_2 , V_78 ) ;
return - V_75 ;
}
return 0 ;
}
static int F_70 ( struct V_34 * V_80 ,
unsigned long V_81 , void * V_82 )
{
int V_78 = ( long ) V_82 ;
switch ( V_81 ) {
case V_83 :
if ( F_67 ( V_78 ) )
return V_84 ;
break;
default:
break;
}
return V_40 ;
}
static int T_3 F_71 ( void )
{
int V_44 , V_78 ;
if ( ! F_72 () )
return - V_85 ;
if ( ! F_41 ( V_55 ) ) {
F_73 ( & V_86 ) ;
F_74 () ;
F_75 (cpu) {
if ( F_67 ( V_78 ) ) {
F_76 () ;
F_77 ( & V_86 ) ;
return - V_75 ;
}
}
F_76 () ;
}
F_24 ( L_3 ) ;
V_4 . V_22 = F_78 ()
? F_31 ( V_87 -> V_42 - V_88 , V_29 )
: F_79 () ;
V_4 . V_21 = V_4 . V_22 ;
V_4 . V_6 = 0 ;
V_4 . V_5 = 0 ;
V_4 . V_14 = 1 ;
V_4 . V_19 = 32 ;
V_4 . V_15 = 1 ;
V_4 . V_16 = V_17 ;
#ifdef F_33
V_4 . V_23 = 0 ;
V_4 . V_24 = 0 ;
F_80 ( & F_25 ) ;
F_81 ( & V_89 ) ;
#endif
for ( V_44 = 0 ; V_44 < V_90 ; V_44 ++ )
if ( V_91 [ V_44 ] . V_92 )
F_66 ( F_82 ( V_91 [ V_44 ] . V_93 ) ,
F_83 ( V_91 [ V_44 ] . V_92 ) ) ;
return 0 ;
}
static int T_3 F_84 ( void )
{
int V_78 ;
F_85 (cpu)
F_68 ( V_67 , V_78 ) = NULL ;
return 0 ;
}
