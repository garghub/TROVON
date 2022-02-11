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
static int F_7 ( unsigned long V_4 , unsigned int V_5 ,
struct V_6 * V_7 )
{
static int V_8 ;
if ( ! V_8 && V_5 == 0x1406 ) {
V_8 = 1 ;
return 0 ;
}
return 1 ;
}
static void T_1 F_8 ( void )
{
F_9 () ;
F_1 () ;
F_10 () ;
F_11 ( F_12 ( F_13 () ) ) ;
}
static void T_1 F_14 ( void )
{
T_3 V_9 , V_10 ;
if ( F_15 ( & V_9 , & V_10 ) == 0 && V_10 > V_11 )
return;
F_16 ( 16 + 6 , F_7 , V_12 , 0 ,
L_2 ) ;
}
static void T_1 F_17 ( void )
{
struct V_1 * V_2 ;
T_3 V_9 , V_10 ;
if ( F_15 ( & V_9 , & V_10 ) == 0 && V_10 > V_13 )
return;
F_18 (np, NULL, L_3 ) {
struct V_14 * V_15 ;
V_15 = F_19 ( sizeof( * V_15 ) , V_16 ) ;
V_15 -> V_17 = F_20 ( L_4 , V_16 ) ;
V_15 -> V_18 = sizeof( L_5 ) ;
V_15 -> V_19 = F_20 ( L_5 ,
V_16 ) ;
F_21 ( V_2 , V_15 ) ;
}
return;
}
static void T_1 F_22 ( void )
{
struct V_1 * V_2 ;
T_3 V_9 , V_10 ;
int V_20 ;
V_20 = F_15 ( & V_9 , & V_10 ) ;
if ( V_20 < 0 || ( V_20 == 0 && V_10 > V_11 ) )
return;
F_18 (np, NULL, L_6 ) {
struct V_14 * V_21 ;
T_4 V_22 , * V_23 , * V_24 ;
int V_25 ;
V_24 = ( T_4 * ) F_23 ( V_2 , L_7 , & V_25 ) ;
if ( ! V_24 )
continue;
V_21 = F_19 ( sizeof( * V_21 ) , V_16 ) ;
V_21 -> V_18 = V_25 ;
V_21 -> V_17 = F_20 ( L_7 , V_16 ) ;
V_21 -> V_19 = F_19 ( V_25 , V_16 ) ;
memcpy ( V_21 -> V_19 , V_24 , V_25 ) ;
V_24 += 2 ;
V_23 = ( T_4 * ) V_21 -> V_19 + 2 ;
V_22 = F_24 ( F_25 ( * V_24 ) -
V_26 ) ;
* V_23 = V_22 ;
F_21 ( V_2 , V_21 ) ;
V_21 = F_19 ( sizeof( * V_21 ) , V_16 ) ;
V_21 -> V_17 = F_20 ( L_4 , V_16 ) ;
V_21 -> V_18 = sizeof( L_8 ) ;
V_21 -> V_19 = F_20 ( L_8 ,
V_16 ) ;
F_21 ( V_2 , V_21 ) ;
}
return;
}
static void T_1 F_26 ( void )
{
if ( F_27 ( L_9 ) )
F_17 () ;
if ( F_27 ( L_10 ) ) {
F_14 () ;
F_22 () ;
}
F_28 ( NULL , V_27 , NULL , NULL ) ;
}
