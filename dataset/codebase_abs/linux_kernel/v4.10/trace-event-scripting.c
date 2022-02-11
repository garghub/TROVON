static int F_1 ( void )
{
return 0 ;
}
static int F_2 ( void )
{
return 0 ;
}
static void F_3 ( union V_1 * T_1 V_2 ,
struct V_3 * T_2 V_2 ,
struct V_4 * T_3 V_2 ,
struct V_5 * T_4 V_2 )
{
}
static void F_4 ( void )
{
fprintf ( V_6 , L_1
L_2
L_3
L_4
L_5 ) ;
}
static int F_5 ( const char * T_5 V_2 ,
int T_6 V_2 ,
const char * * T_7 V_2 )
{
F_4 () ;
return - 1 ;
}
static int F_6 ( struct V_7 * V_7
V_2 ,
const char * T_8
V_2 )
{
F_4 () ;
return - 1 ;
}
static void F_7 ( struct V_8 * V_8 )
{
if ( V_9 == NULL )
V_9 = malloc ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ||
F_8 ( L_6 , V_8 ) ||
F_8 ( L_7 , V_8 ) ) {
F_9 ( L_8 ) ;
F_10 ( & V_9 ) ;
}
}
void F_11 ( void )
{
F_7 ( & V_10 ) ;
}
void F_11 ( void )
{
F_7 ( & V_11 ) ;
}
static void F_12 ( void )
{
fprintf ( V_6 , L_9
L_10
L_11
L_12
L_5 ) ;
}
static int F_13 ( const char * T_5 V_2 ,
int T_6 V_2 ,
const char * * T_7 V_2 )
{
F_12 () ;
return - 1 ;
}
static int F_14 ( struct V_7 * V_7
V_2 ,
const char * T_8 V_2 )
{
F_12 () ;
return - 1 ;
}
static void F_15 ( struct V_8 * V_8 )
{
if ( V_9 == NULL )
V_9 = malloc ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ||
F_8 ( L_13 , V_8 ) ||
F_8 ( L_14 , V_8 ) ) {
F_9 ( L_15 ) ;
F_10 ( & V_9 ) ;
}
}
void F_16 ( void )
{
F_15 ( & V_12 ) ;
}
void F_16 ( void )
{
F_15 ( & V_13 ) ;
}
