static void T_1 F_1 ( void )
{
struct V_1 * V_2 =
F_2 ( NULL , NULL , L_1 ) ;
if ( V_2 ) {
V_3 = F_3 ( V_2 , 0 ) ;
F_4 ( V_3 ) ;
F_5 ( V_2 ) ;
}
}
void T_2 * F_6 ( void )
{
return V_3 ;
}
static int T_1 F_7 ( unsigned long V_4 , const char * V_5 ,
int V_6 , void * V_7 )
{
const char * type = F_8 ( V_4 , L_2 , NULL ) ;
const T_3 * V_8 , * V_9 ;
int V_10 ;
if ( type == NULL || strcmp ( type , L_3 ) )
return 0 ;
V_8 = F_8 ( V_4 , L_4 , & V_10 ) ;
if ( V_8 == NULL )
V_8 = F_8 ( V_4 , L_5 , & V_10 ) ;
if ( V_8 == NULL )
return 0 ;
V_9 = V_8 + ( V_10 / sizeof( T_3 ) ) ;
while ( ( V_9 - V_8 ) >= ( V_11 + V_12 ) ) {
T_4 V_13 , V_14 ;
V_13 = F_9 ( V_11 , & V_8 ) ;
V_14 = F_9 ( V_12 , & V_8 ) ;
F_10 ( V_13 , V_15 ) ;
}
return 0 ;
}
static void T_1 F_11 ( void )
{
F_12 ( F_7 , NULL ) ;
}
static void T_1 F_11 ( void ) {}
static void T_1 F_13 ( void )
{
F_14 () ;
F_1 () ;
F_15 () ;
F_16 ( F_17 ( F_18 () ) ) ;
}
static void T_1 F_19 ( void )
{
struct V_1 * V_2 ;
T_5 V_16 , V_17 ;
if ( F_20 ( & V_16 , & V_17 ) == 0 && V_17 > V_18 )
return;
F_21 (np, NULL, L_6 ) {
struct V_19 * V_20 ;
V_20 = F_22 ( sizeof( * V_20 ) , V_21 ) ;
V_20 -> V_22 = F_23 ( L_7 , V_21 ) ;
V_20 -> V_23 = sizeof( L_8 ) ;
V_20 -> V_24 = F_23 ( L_8 ,
V_21 ) ;
F_24 ( V_2 , V_20 ) ;
}
return;
}
static void T_1 F_25 ( void )
{
if ( F_26 ( L_9 ) )
F_19 () ;
F_27 ( NULL , V_25 , NULL , NULL ) ;
}
