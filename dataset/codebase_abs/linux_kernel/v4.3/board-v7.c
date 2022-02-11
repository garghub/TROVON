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
static int F_13 ( unsigned long V_16 , unsigned int V_17 ,
struct V_18 * V_19 )
{
static int V_20 ;
if ( ! V_20 && V_17 == 0x1406 ) {
V_20 = 1 ;
return 0 ;
}
return 1 ;
}
static void T_1 F_14 ( void )
{
F_15 () ;
F_1 () ;
F_16 () ;
F_17 ( F_18 ( F_19 () ) ) ;
}
static void T_1 F_20 ( void )
{
T_5 V_21 , V_22 ;
if ( F_21 ( & V_21 , & V_22 ) == 0 && V_22 > V_23 )
return;
F_22 ( 16 + 6 , F_13 , V_24 , 0 ,
L_6 ) ;
}
static void T_1 F_23 ( void )
{
struct V_1 * V_2 ;
T_5 V_21 , V_22 ;
if ( F_21 ( & V_21 , & V_22 ) == 0 && V_22 > V_25 )
return;
F_24 (np, NULL, L_7 ) {
struct V_26 * V_27 ;
V_27 = F_25 ( sizeof( * V_27 ) , V_28 ) ;
V_27 -> V_29 = F_26 ( L_8 , V_28 ) ;
V_27 -> V_30 = sizeof( L_9 ) ;
V_27 -> V_31 = F_26 ( L_9 ,
V_28 ) ;
F_27 ( V_2 , V_27 ) ;
}
return;
}
static void T_1 F_28 ( void )
{
if ( F_29 ( L_10 ) )
F_23 () ;
if ( F_29 ( L_11 ) )
F_20 () ;
F_30 ( NULL , V_32 , NULL , NULL ) ;
}
