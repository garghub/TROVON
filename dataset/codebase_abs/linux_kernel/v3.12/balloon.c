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
F_40 ( V_43 , V_51 [ V_44 ] ) ;
#ifdef F_41
if ( F_42 () && ! F_5 ( V_1 ) ) {
int V_55 ;
V_55 = F_43 (
( unsigned long ) F_44 ( V_43 << V_31 ) ,
F_45 ( V_51 [ V_44 ] , V_56 ) ,
0 ) ;
F_39 ( V_55 ) ;
}
#endif
F_46 ( V_1 ) ;
}
V_4 . V_22 += V_27 ;
return V_13 ;
}
static enum V_11 F_47 ( unsigned long V_42 , T_2 V_57 )
{
enum V_11 V_12 = V_13 ;
unsigned long V_43 , V_44 ;
struct V_1 * V_1 ;
struct V_1 * V_58 ;
int V_55 ;
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
V_1 = F_48 ( V_57 ) ;
if ( V_1 == NULL ) {
V_42 = V_44 ;
V_12 = V_20 ;
break;
}
V_43 = F_36 ( V_1 ) ;
V_51 [ V_44 ] = F_49 ( V_43 ) ;
F_1 ( V_1 ) ;
V_58 = F_50 () ;
#ifdef F_41
if ( F_42 () && ! F_5 ( V_1 ) ) {
V_55 = F_43 (
( unsigned long ) F_44 ( V_43 << V_31 ) ,
F_51 ( F_36 ( V_58 ) ,
V_59 ) , 0 ) ;
F_39 ( V_55 ) ;
}
#endif
if ( ! F_52 ( V_60 ) ) {
unsigned long V_61 ;
V_61 = F_36 ( V_58 ) ;
F_53 ( V_43 , F_49 ( V_61 ) ) ;
}
F_54 () ;
F_8 ( F_55 ( V_43 ) ) ;
}
F_56 () ;
F_57 () ;
F_37 ( V_46 . V_52 , V_51 ) ;
V_46 . V_53 = V_42 ;
V_55 = F_38 ( V_62 , & V_46 ) ;
F_39 ( V_55 != V_42 ) ;
V_4 . V_22 -= V_42 ;
return V_12 ;
}
static void F_58 ( struct V_63 * V_64 )
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
V_12 = F_47 ( - V_25 , V_65 ) ;
V_12 = F_16 ( V_12 ) ;
#ifndef F_59
if ( F_60 () )
F_61 () ;
#endif
} while ( V_25 && V_12 == V_13 );
if ( V_12 == V_20 )
F_31 ( & V_39 , V_4 . V_14 * V_66 ) ;
F_29 ( & V_33 ) ;
}
struct V_1 * F_50 ( void )
{
struct V_1 * V_55 = F_62 ( V_67 ) ;
F_39 ( V_55 == NULL ) ;
return V_55 ;
}
void F_54 ( void )
{
F_63 ( V_67 ) ;
}
void F_64 ( unsigned long V_41 )
{
V_4 . V_21 = V_41 ;
F_31 ( & V_39 , 0 ) ;
}
int F_65 ( int V_42 , struct V_1 * * V_68 , bool V_69 )
{
int V_70 = 0 ;
struct V_1 * V_1 ;
F_28 ( & V_33 ) ;
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
F_29 ( & V_33 ) ;
return 0 ;
V_74:
while ( V_70 )
F_8 ( V_68 [ -- V_70 ] ) ;
F_31 ( & V_39 , 0 ) ;
F_29 ( & V_33 ) ;
return - V_75 ;
}
void F_66 ( int V_42 , struct V_1 * * V_68 )
{
int V_44 ;
F_28 ( & V_33 ) ;
for ( V_44 = 0 ; V_44 < V_42 ; V_44 ++ ) {
if ( V_68 [ V_44 ] )
F_8 ( V_68 [ V_44 ] ) ;
}
if ( F_17 () )
F_31 ( & V_39 , 0 ) ;
F_29 ( & V_33 ) ;
}
static void T_3 F_67 ( unsigned long V_76 ,
unsigned long V_68 )
{
unsigned long V_43 , V_77 ;
struct V_1 * V_1 ;
V_77 = F_32 ( V_29 , V_76 + V_68 ) ;
for ( V_43 = V_76 ; V_43 < V_77 ; V_43 ++ ) {
V_1 = F_55 ( V_43 ) ;
F_4 ( V_1 ) ;
}
}
static int T_4 F_68 ( struct V_34 * V_78 ,
unsigned long V_79 , void * V_80 )
{
int V_81 = ( long ) V_80 ;
switch ( V_79 ) {
case V_82 :
if ( F_69 ( V_67 , V_81 ) != NULL )
break;
F_69 ( V_67 , V_81 ) = F_48 ( V_83 ) ;
if ( F_69 ( V_67 , V_81 ) == NULL ) {
F_70 ( L_2 , V_81 ) ;
return V_84 ;
}
break;
default:
break;
}
return V_40 ;
}
static int T_3 F_71 ( void )
{
int V_44 , V_81 ;
if ( ! F_72 () )
return - V_85 ;
F_73 (cpu)
{
F_69 ( V_67 , V_81 ) = F_48 ( V_83 ) ;
if ( F_69 ( V_67 , V_81 ) == NULL ) {
F_70 ( L_2 , V_81 ) ;
return - V_75 ;
}
}
F_74 ( & V_86 ) ;
F_25 ( L_3 ) ;
V_4 . V_22 = F_42 ()
? F_32 ( V_87 -> V_42 - V_88 , V_29 )
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
F_75 ( & F_26 ) ;
F_76 ( & V_89 ) ;
#endif
for ( V_44 = 0 ; V_44 < V_90 ; V_44 ++ )
if ( V_91 [ V_44 ] . V_92 )
F_67 ( F_77 ( V_91 [ V_44 ] . V_93 ) ,
F_78 ( V_91 [ V_44 ] . V_92 ) ) ;
return 0 ;
}
static int T_3 F_79 ( void )
{
int V_81 ;
F_80 (cpu)
F_69 ( V_67 , V_81 ) = NULL ;
return 0 ;
}
