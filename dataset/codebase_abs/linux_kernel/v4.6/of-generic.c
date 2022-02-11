static void F_1 ( void )
{
}
static void F_2 ( unsigned int V_1 )
{
}
static void F_3 ( unsigned int V_2 , unsigned long V_3 )
{
}
static unsigned int F_4 ( void )
{
return 0 ;
}
static void F_5 ( unsigned int V_2 , unsigned int V_4 )
{
}
static void F_6 ( void )
{
struct V_5 * V_6 = 0 ;
const char * V_7 = 0 ;
const struct V_8 * V_9 = V_10 ;
F_7 ( L_1 ) ;
F_8 ( F_9 ( 0 ) ) ;
while ( ( V_6 = F_10 ( V_6 , L_2 ) ) ) {
const T_1 * V_11 = F_11 ( V_6 , L_3 , NULL ) ;
T_2 V_12 = - 1 ;
if ( V_11 ) V_12 = F_12 ( V_11 , F_13 ( V_6 ) ) ;
if ( V_12 < V_13 ) {
if ( ! V_7 )
F_14 ( V_6 , L_4 , & V_7 ) ;
F_15 ( V_12 , true ) ;
F_16 ( V_12 , true ) ;
V_14 [ V_12 ] = V_12 ;
V_15 [ V_12 ] = V_12 ;
}
}
if ( ! V_7 ) {
V_6 = F_17 ( NULL , L_5 ) ;
F_14 ( V_6 , L_4 , & V_7 ) ;
}
F_7 ( L_6 , V_7 ) ;
if ( V_7 )
for (; V_9 -> V_7 ; V_9 ++ )
if ( ! strcmp ( V_9 -> V_7 , V_7 ) ) {
F_18 ( V_9 -> V_16 ) ;
return;
}
F_18 ( & V_17 ) ;
}
static void F_6 ( void )
{
}
static void F_19 ( void )
{
}
static int F_20 ( void )
{
return 0 ;
}
static void T_3 F_21 ( void )
{
F_22 () ;
F_23 () ;
}
static void T_3 F_24 ( void )
{
F_7 ( L_7 ) ;
F_25 () ;
}
static void T_3 F_26 ( char * * V_18 )
{
F_27 () ;
V_19 = F_24 ;
V_20 . V_21 = F_28 () ;
if ( ! V_20 . V_21 )
V_20 . V_21 = L_8 ;
F_6 () ;
}
static int F_29 ( int V_22 )
{
return V_22 ;
}
static void T_3 F_30 ( void )
{
F_7 ( L_9 ) ;
F_31 () ;
}
static int T_3 F_32 ( void )
{
#ifdef F_33
F_7 ( L_10 ) ;
F_34 ( NULL ) ;
#endif
return 0 ;
}
void T_3 F_35 ( struct V_23 * * V_16 , int V_24 )
{
}
void T_3 F_36 ( void )
{
}
static int T_3 F_37 ( void )
{
F_7 ( L_11 ) ;
if ( F_38 () ) {
F_39 () ;
F_40 ( NULL , V_25 ,
NULL , NULL ) ;
} else {
F_41 ( L_12 ) ;
}
return 0 ;
}
