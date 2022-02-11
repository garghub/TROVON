static int F_1 ( void )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_7 ( void )
{
}
static int F_8 ( void ) __acquires( T_1 )
{
F_9 ( & T_1 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
const unsigned long V_5 = 2 ;
const unsigned long V_3 = 100 ;
if ( ! ( F_3 ( V_2 ) %
( V_4 * 2000 * V_3 ) ) )
F_4 ( V_3 ) ;
if ( ! ( F_3 ( V_2 ) %
( V_4 * 2 * V_5 ) ) )
F_11 ( V_5 ) ;
#ifdef F_5
if ( ! ( F_3 ( V_2 ) % ( V_4 * 20000 ) ) )
F_6 () ;
#endif
}
static void F_12 ( void ) __releases( T_1 )
{
F_13 ( & T_1 ) ;
}
static int F_14 ( void )
__acquires( T_2 )
{
unsigned long V_6 ;
F_15 ( & T_1 , V_6 ) ;
V_7 -> V_6 = V_6 ;
return 0 ;
}
static void F_16 ( void )
__releases( T_1 )
{
F_17 ( & T_1 , V_7 -> V_6 ) ;
}
static int F_18 ( void * V_8 )
{
struct V_9 * V_10 = V_8 ;
static F_19 ( rand ) ;
F_20 ( L_1 ) ;
F_21 ( V_11 , 19 ) ;
do {
F_22 ( 1 ) ;
V_7 -> V_12 () ;
if ( F_23 ( V_13 ) )
V_10 -> V_14 ++ ;
V_13 = 1 ;
V_10 -> V_15 ++ ;
V_7 -> V_16 ( & rand ) ;
V_13 = 0 ;
V_7 -> V_17 () ;
F_24 ( L_2 ) ;
} while ( ! F_25 () );
F_26 ( L_2 ) ;
return 0 ;
}
static void F_27 ( char * V_18 )
{
bool V_19 = 0 ;
int V_20 ;
long V_21 = 0 ;
long V_22 = V_23 [ 0 ] . V_15 ;
long long V_24 = 0 ;
for ( V_20 = 0 ; V_20 < V_4 ; V_20 ++ ) {
if ( V_23 [ V_20 ] . V_14 )
V_19 = true ;
V_24 += V_23 [ V_20 ] . V_15 ;
if ( V_21 < V_23 [ V_20 ] . V_14 )
V_21 = V_23 [ V_20 ] . V_14 ;
if ( V_22 > V_23 [ V_20 ] . V_14 )
V_22 = V_23 [ V_20 ] . V_14 ;
}
V_18 += sprintf ( V_18 , L_3 , V_25 , V_26 ) ;
V_18 += sprintf ( V_18 ,
L_4 ,
V_24 , V_21 , V_22 , V_21 / 2 > V_22 ? L_5 : L_6 ,
V_19 , V_19 ? L_7 : L_6 ) ;
if ( V_19 )
F_28 ( & V_27 ) ;
}
static void F_29 ( void )
{
int V_28 = V_4 * 200 + 8192 ;
char * V_29 ;
V_29 = F_30 ( V_28 , V_30 ) ;
if ( ! V_29 ) {
F_31 ( L_8 ,
V_28 ) ;
return;
}
F_27 ( V_29 ) ;
F_32 ( L_9 , V_29 ) ;
F_33 ( V_29 ) ;
}
static int F_34 ( void * V_8 )
{
F_20 ( L_10 ) ;
do {
F_35 ( V_31 * V_32 ) ;
F_29 () ;
F_36 ( L_11 ) ;
} while ( ! F_25 () );
F_26 ( L_11 ) ;
return 0 ;
}
static inline void
F_37 ( struct V_33 * V_7 ,
const char * V_34 )
{
F_32 ( L_9 V_26
L_12 ,
V_25 , V_34 , V_4 , V_31 , V_35 ,
V_36 , V_37 , V_38 ,
V_39 , V_40 ) ;
}
static void F_38 ( void )
{
int V_20 ;
if ( F_39 () )
return;
if ( V_41 ) {
for ( V_20 = 0 ; V_20 < V_4 ; V_20 ++ )
F_40 ( F_18 ,
V_41 [ V_20 ] ) ;
F_33 ( V_41 ) ;
V_41 = NULL ;
}
F_40 ( F_34 , V_42 ) ;
F_29 () ;
if ( F_41 ( & V_27 ) )
F_37 ( V_7 ,
L_13 ) ;
else if ( F_42 () )
F_37 ( V_7 ,
L_14 ) ;
else
F_37 ( V_7 ,
L_15 ) ;
}
static int T_3 F_43 ( void )
{
int V_20 ;
int V_43 = 0 ;
static struct V_33 * V_44 [] = {
& V_45 , & V_46 , & V_47 ,
} ;
F_44 ( V_25 , V_35 , & V_48 ) ;
for ( V_20 = 0 ; V_20 < F_45 ( V_44 ) ; V_20 ++ ) {
V_7 = V_44 [ V_20 ] ;
if ( strcmp ( V_25 , V_7 -> V_49 ) == 0 )
break;
}
if ( V_20 == F_45 ( V_44 ) ) {
F_32 ( L_16 ,
V_25 ) ;
F_32 ( L_17 ) ;
for ( V_20 = 0 ; V_20 < F_45 ( V_44 ) ; V_20 ++ )
F_32 ( L_18 , V_44 [ V_20 ] -> V_49 ) ;
F_32 ( L_19 ) ;
F_46 () ;
return - V_50 ;
}
if ( V_7 -> V_51 )
V_7 -> V_51 () ;
if ( V_52 >= 0 )
V_4 = V_52 ;
else
V_4 = 2 * F_47 () ;
F_37 ( V_7 , L_20 ) ;
V_13 = 0 ;
V_23 = F_30 ( sizeof( * V_23 ) * V_4 , V_30 ) ;
if ( V_23 == NULL ) {
F_20 ( L_21 ) ;
V_43 = - V_53 ;
goto V_54;
}
for ( V_20 = 0 ; V_20 < V_4 ; V_20 ++ ) {
V_23 [ V_20 ] . V_14 = 0 ;
V_23 [ V_20 ] . V_15 = 0 ;
}
if ( V_39 > 0 ) {
V_43 = F_48 ( V_40 * V_32 ,
V_39 * V_32 ) ;
if ( V_43 )
goto V_54;
}
if ( V_36 > 0 ) {
V_43 = F_49 ( V_36 ) ;
if ( V_43 )
goto V_54;
}
if ( V_38 > 0 ) {
V_43 = F_50 ( V_38 ,
F_38 ) ;
if ( V_43 )
goto V_54;
}
if ( V_37 > 0 ) {
V_43 = F_51 ( V_37 ) ;
if ( V_43 )
goto V_54;
}
V_41 = F_52 ( V_4 * sizeof( V_41 [ 0 ] ) ,
V_30 ) ;
if ( V_41 == NULL ) {
F_53 ( L_22 ) ;
V_43 = - V_53 ;
goto V_54;
}
for ( V_20 = 0 ; V_20 < V_4 ; V_20 ++ ) {
V_43 = F_54 ( F_18 , & V_23 [ V_20 ] ,
V_41 [ V_20 ] ) ;
if ( V_43 )
goto V_54;
}
if ( V_31 > 0 ) {
V_43 = F_54 ( F_34 , NULL ,
V_42 ) ;
if ( V_43 )
goto V_54;
}
F_46 () ;
return 0 ;
V_54:
F_46 () ;
F_38 () ;
return V_43 ;
}
