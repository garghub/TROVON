static void T_1 F_1 ( void )
{
void T_2 * V_1 ;
struct V_2 * V_3 =
F_2 ( NULL , NULL , L_1 ) ;
if ( V_3 ) {
V_1 = F_3 ( V_3 , 0 ) ;
F_4 ( V_1 ) ;
F_5 ( V_3 ) ;
}
}
static int F_6 ( unsigned long V_4 , unsigned int V_5 ,
struct V_6 * V_7 )
{
static int V_8 ;
if ( ! V_8 && V_5 == 0x1406 ) {
V_8 = 1 ;
return 0 ;
}
return 1 ;
}
static void T_1 F_7 ( void )
{
F_8 () ;
F_1 () ;
F_9 () ;
F_10 ( F_11 ( F_12 () ) ) ;
}
static void T_1 F_13 ( void )
{
T_3 V_9 , V_10 ;
if ( F_14 ( & V_9 , & V_10 ) == 0 && V_10 > V_11 )
return;
F_15 ( 16 + 6 , F_6 , V_12 , 0 ,
L_2 ) ;
}
static void T_1 F_16 ( void )
{
struct V_2 * V_3 ;
T_3 V_9 , V_10 ;
if ( F_14 ( & V_9 , & V_10 ) == 0 && V_10 > V_13 )
return;
F_17 (np, NULL, L_3 ) {
struct V_14 * V_15 ;
V_15 = F_18 ( sizeof( * V_15 ) , V_16 ) ;
V_15 -> V_17 = F_19 ( L_4 , V_16 ) ;
V_15 -> V_18 = sizeof( L_5 ) ;
V_15 -> V_19 = F_19 ( L_5 ,
V_16 ) ;
F_20 ( V_3 , V_15 ) ;
}
return;
}
static void T_1 F_21 ( void )
{
struct V_2 * V_3 ;
T_3 V_9 , V_10 ;
if ( F_14 ( & V_9 , & V_10 ) == 0 && V_10 > V_11 )
return;
F_17 (np, NULL, L_6 ) {
struct V_14 * V_20 ;
T_4 V_21 , * V_22 , * V_23 ;
int V_24 ;
V_23 = ( T_4 * ) F_22 ( V_3 , L_7 , & V_24 ) ;
if ( ! V_23 )
continue;
V_20 = F_18 ( sizeof( * V_20 ) , V_16 ) ;
V_20 -> V_18 = V_24 ;
V_20 -> V_17 = F_19 ( L_7 , V_16 ) ;
V_20 -> V_19 = F_18 ( V_24 , V_16 ) ;
memcpy ( V_20 -> V_19 , V_23 , V_24 ) ;
V_23 += 2 ;
V_22 = ( T_4 * ) V_20 -> V_19 + 2 ;
V_21 = F_23 ( F_24 ( * V_23 ) -
V_25 ) ;
* V_22 = V_21 ;
F_20 ( V_3 , V_20 ) ;
V_20 = F_18 ( sizeof( * V_20 ) , V_16 ) ;
V_20 -> V_17 = F_19 ( L_4 , V_16 ) ;
V_20 -> V_18 = sizeof( L_8 ) ;
V_20 -> V_19 = F_19 ( L_8 ,
V_16 ) ;
F_20 ( V_3 , V_20 ) ;
}
return;
}
static void T_1 F_25 ( void )
{
if ( F_26 ( L_9 ) )
F_16 () ;
if ( F_26 ( L_10 ) ) {
F_13 () ;
F_21 () ;
}
F_27 ( NULL , V_26 , NULL , NULL ) ;
}
