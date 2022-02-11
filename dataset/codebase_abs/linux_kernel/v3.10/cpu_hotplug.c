static void F_1 ( int V_1 )
{
if ( ! F_2 ( V_1 ) )
F_3 ( V_1 ) ;
F_4 ( V_1 , true ) ;
}
static void F_5 ( int V_1 )
{
if ( F_2 ( V_1 ) )
F_6 ( V_1 ) ;
F_4 ( V_1 , false ) ;
}
static int F_7 ( unsigned int V_1 )
{
int V_2 ;
char V_3 [ 16 ] , V_4 [ 16 ] ;
sprintf ( V_3 , L_1 , V_1 ) ;
V_2 = F_8 ( V_5 , V_3 , L_2 , L_3 , V_4 ) ;
if ( V_2 != 1 ) {
if ( ! F_9 () )
F_10 ( V_6 L_4 ) ;
return V_2 ;
}
if ( strcmp ( V_4 , L_5 ) == 0 )
return 1 ;
else if ( strcmp ( V_4 , L_6 ) == 0 )
return 0 ;
F_10 ( V_6 L_7 , V_4 , V_1 ) ;
return - V_7 ;
}
static void F_11 ( unsigned int V_1 )
{
if ( ! F_12 ( V_1 ) )
return;
switch ( F_7 ( V_1 ) ) {
case 1 :
F_1 ( V_1 ) ;
break;
case 0 :
( void ) F_13 ( V_1 ) ;
F_5 ( V_1 ) ;
break;
default:
break;
}
}
static void F_14 ( struct V_8 * V_9 ,
const char * * V_10 , unsigned int V_11 )
{
unsigned int V_1 ;
char * V_12 ;
const char * V_13 = V_10 [ V_14 ] ;
V_12 = strstr ( V_13 , L_8 ) ;
if ( V_12 != NULL ) {
sscanf ( V_12 , L_1 , & V_1 ) ;
F_11 ( V_1 ) ;
}
}
static int F_15 ( struct V_15 * V_16 ,
unsigned long V_17 , void * V_18 )
{
int V_1 ;
static struct V_8 V_19 = {
. V_13 = L_9 ,
. V_20 = F_14 } ;
( void ) F_16 ( & V_19 ) ;
F_17 (cpu) {
if ( F_7 ( V_1 ) == 0 ) {
( void ) F_13 ( V_1 ) ;
F_4 ( V_1 , false ) ;
}
}
return V_21 ;
}
static int T_1 F_18 ( void )
{
static struct V_15 V_22 = {
. V_23 = F_15 } ;
if ( ! F_19 () )
return - V_24 ;
F_20 ( & V_22 ) ;
return 0 ;
}
