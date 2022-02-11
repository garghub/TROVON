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
}
else
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
unsigned long V_22 = V_4 . V_23 ;
V_22 = F_19 ( V_22 ,
V_4 . V_24 +
V_4 . V_6 +
V_4 . V_5 ) ;
return V_22 - V_4 . V_24 ;
}
static enum V_12 F_20 ( unsigned long V_25 )
{
int V_26 ;
unsigned long V_27 , V_28 ;
struct V_1 * V_1 ;
struct V_29 V_30 = {
. V_31 = 0 ,
. V_32 = 0 ,
. V_33 = V_34
} ;
if ( V_25 > F_21 ( V_35 ) )
V_25 = F_21 ( V_35 ) ;
V_1 = F_15 () ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ ) {
if ( ! V_1 ) {
V_25 = V_28 ;
break;
}
V_35 [ V_28 ] = F_22 ( V_1 ) ;
V_1 = F_16 ( V_1 ) ;
}
F_23 ( V_30 . V_36 , V_35 ) ;
V_30 . V_37 = V_25 ;
V_26 = F_24 ( V_38 , & V_30 ) ;
if ( V_26 <= 0 )
return V_21 ;
for ( V_28 = 0 ; V_28 < V_26 ; V_28 ++ ) {
V_1 = F_10 ( false ) ;
F_25 ( V_1 == NULL ) ;
V_27 = F_22 ( V_1 ) ;
F_25 ( ! F_26 ( V_39 ) &&
F_27 ( V_27 ) ) ;
F_28 ( V_27 , V_35 [ V_28 ] ) ;
if ( F_29 () && ! F_5 ( V_1 ) ) {
int V_40 ;
V_40 = F_30 (
( unsigned long ) F_31 ( V_27 << V_41 ) ,
F_32 ( V_35 [ V_28 ] , V_42 ) ,
0 ) ;
F_25 ( V_40 ) ;
}
F_33 ( V_1 ) ;
F_34 ( V_1 ) ;
F_35 ( V_1 ) ;
}
V_4 . V_24 += V_26 ;
return V_14 ;
}
static enum V_12 F_36 ( unsigned long V_25 , T_1 V_43 )
{
enum V_12 V_13 = V_14 ;
unsigned long V_27 , V_28 ;
struct V_1 * V_1 ;
int V_40 ;
struct V_29 V_30 = {
. V_31 = 0 ,
. V_32 = 0 ,
. V_33 = V_34
} ;
if ( V_25 > F_21 ( V_35 ) )
V_25 = F_21 ( V_35 ) ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ ) {
if ( ( V_1 = F_37 ( V_43 ) ) == NULL ) {
V_25 = V_28 ;
V_13 = V_21 ;
break;
}
V_27 = F_22 ( V_1 ) ;
V_35 [ V_28 ] = F_38 ( V_27 ) ;
F_1 ( V_1 ) ;
if ( F_29 () && ! F_5 ( V_1 ) ) {
V_40 = F_30 (
( unsigned long ) F_31 ( V_27 << V_41 ) ,
F_39 ( 0 ) , 0 ) ;
F_25 ( V_40 ) ;
}
}
F_40 () ;
F_41 () ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ ) {
V_27 = F_42 ( V_35 [ V_28 ] ) ;
F_43 ( V_27 , V_44 ) ;
F_8 ( F_44 ( V_27 ) ) ;
}
F_23 ( V_30 . V_36 , V_35 ) ;
V_30 . V_37 = V_25 ;
V_40 = F_24 ( V_45 , & V_30 ) ;
F_25 ( V_40 != V_25 ) ;
V_4 . V_24 -= V_25 ;
return V_13 ;
}
static void F_45 ( struct V_46 * V_47 )
{
enum V_12 V_13 = V_14 ;
long V_48 ;
F_46 ( & V_49 ) ;
do {
V_48 = F_18 () ;
if ( V_48 > 0 )
V_13 = F_20 ( V_48 ) ;
if ( V_48 < 0 )
V_13 = F_36 ( - V_48 , V_50 ) ;
V_13 = F_17 ( V_13 ) ;
#ifndef F_47
if ( F_48 () )
F_49 () ;
#endif
} while ( V_48 && V_13 == V_14 );
if ( V_13 == V_21 )
F_50 ( & V_51 , V_4 . V_15 * V_52 ) ;
F_51 ( & V_49 ) ;
}
void F_52 ( unsigned long V_22 )
{
V_4 . V_23 = V_22 ;
F_50 ( & V_51 , 0 ) ;
}
int F_53 ( int V_25 , struct V_1 * * V_53 )
{
int V_54 = 0 ;
struct V_1 * V_1 ;
F_46 ( & V_49 ) ;
while ( V_54 < V_25 ) {
V_1 = F_10 ( true ) ;
if ( V_1 ) {
V_53 [ V_54 ++ ] = V_1 ;
} else {
enum V_12 V_55 ;
V_55 = F_36 ( V_25 - V_54 , V_56 ) ;
if ( V_55 != V_14 )
goto V_57;
}
}
F_51 ( & V_49 ) ;
return 0 ;
V_57:
while ( V_54 )
F_8 ( V_53 [ -- V_54 ] ) ;
F_50 ( & V_51 , 0 ) ;
F_51 ( & V_49 ) ;
return - V_58 ;
}
void F_54 ( int V_25 , struct V_1 * * V_53 )
{
int V_28 ;
F_46 ( & V_49 ) ;
for ( V_28 = 0 ; V_28 < V_25 ; V_28 ++ ) {
if ( V_53 [ V_28 ] )
F_8 ( V_53 [ V_28 ] ) ;
}
if ( F_18 () )
F_50 ( & V_51 , 0 ) ;
F_51 ( & V_49 ) ;
}
static int T_2 F_55 ( void )
{
unsigned long V_27 , V_59 ;
struct V_1 * V_1 ;
if ( ! F_56 () )
return - V_60 ;
F_57 ( L_1 ) ;
V_4 . V_24 = F_29 () ? F_19 ( V_61 -> V_25 , V_62 ) : V_62 ;
V_4 . V_23 = V_4 . V_24 ;
V_4 . V_6 = 0 ;
V_4 . V_5 = 0 ;
V_4 . V_15 = 1 ;
V_4 . V_20 = 32 ;
V_4 . V_16 = 1 ;
V_4 . V_17 = V_18 ;
V_59 = F_19 ( F_19 ( V_62 , F_58 () ) ,
( unsigned long ) F_59 ( V_63 + V_64 ) ) ;
for ( V_27 = F_60 ( V_63 ) ;
V_27 < V_59 ;
V_27 ++ ) {
V_1 = F_44 ( V_27 ) ;
F_4 ( V_1 ) ;
}
return 0 ;
}
