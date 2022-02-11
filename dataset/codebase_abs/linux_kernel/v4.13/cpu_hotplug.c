static void F_1 ( int V_1 )
{
if ( ! F_2 ( V_1 ) )
F_3 ( V_1 ) ;
F_4 ( V_1 , true ) ;
}
static void F_5 ( int V_1 )
{
if ( F_6 ( V_1 ) ) {
F_7 () ;
F_8 ( F_9 ( V_1 ) ) ;
F_10 () ;
}
if ( F_2 ( V_1 ) )
F_11 ( V_1 ) ;
F_4 ( V_1 , false ) ;
}
static int F_12 ( unsigned int V_1 )
{
int V_2 ;
char V_3 [ 16 ] , V_4 [ 16 ] ;
sprintf ( V_3 , L_1 , V_1 ) ;
V_2 = F_13 ( V_5 , V_3 , L_2 , L_3 , V_4 ) ;
if ( V_2 != 1 ) {
if ( ! F_14 () )
F_15 ( L_4 ) ;
return V_2 ;
}
if ( strcmp ( V_4 , L_5 ) == 0 )
return 1 ;
else if ( strcmp ( V_4 , L_6 ) == 0 )
return 0 ;
F_15 ( L_7 , V_4 , V_1 ) ;
return - V_6 ;
}
static void F_16 ( unsigned int V_1 )
{
if ( ! F_17 ( V_1 ) )
return;
switch ( F_12 ( V_1 ) ) {
case 1 :
F_1 ( V_1 ) ;
break;
case 0 :
F_5 ( V_1 ) ;
break;
default:
break;
}
}
static void F_18 ( struct V_7 * V_8 ,
const char * V_9 , const char * V_10 )
{
unsigned int V_1 ;
char * V_11 ;
V_11 = strstr ( V_9 , L_8 ) ;
if ( V_11 != NULL ) {
sscanf ( V_11 , L_1 , & V_1 ) ;
F_16 ( V_1 ) ;
}
}
static int F_19 ( struct V_12 * V_13 ,
unsigned long V_14 , void * V_15 )
{
int V_1 ;
static struct V_7 V_16 = {
. V_17 = L_9 ,
. V_18 = F_18 } ;
( void ) F_20 ( & V_16 ) ;
F_21 (cpu) {
if ( F_12 ( V_1 ) == 0 ) {
( void ) F_22 ( V_1 ) ;
F_4 ( V_1 , false ) ;
}
}
return V_19 ;
}
static int T_1 F_23 ( void )
{
static struct V_12 V_20 = {
. V_21 = F_19 } ;
#ifdef F_24
if ( ! F_25 () && ! F_26 () )
#else
if ( ! F_27 () )
#endif
return - V_22 ;
F_28 ( & V_20 ) ;
return 0 ;
}
