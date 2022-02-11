static void F_1 ( T_1 V_1 , void * V_2 )
{
struct V_3 V_4 = { V_5 , NULL } ;
union V_6 * V_7 ;
T_2 V_8 ;
V_8 = F_2 ( V_1 , & V_4 ) ;
if ( F_3 ( V_8 ) ) {
F_4 ( L_1 , V_8 ) ;
return;
}
V_7 = (union V_6 * ) V_4 . V_9 ;
if ( ! V_7 )
return;
F_5 ( L_2 , V_7 -> type ) ;
F_6 ( V_4 . V_9 ) ;
}
static int T_3 F_7 ( void )
{
T_2 V_8 ;
int V_10 ;
V_11 = F_8 () ;
if ( ! V_11 )
return - V_12 ;
V_11 -> V_13 = L_3 ;
V_11 -> V_14 = L_4 ;
V_11 -> V_15 . V_16 = V_17 ;
V_10 = F_9 ( V_11 ,
V_18 , NULL ) ;
if ( V_10 )
goto V_19;
V_8 = F_10 ( V_20 ,
F_1 , NULL ) ;
if ( F_3 ( V_8 ) ) {
V_10 = - V_21 ;
goto V_19;
}
V_10 = F_11 ( V_11 ) ;
if ( V_10 )
goto V_22;
return 0 ;
V_22:
F_12 ( V_20 ) ;
V_19:
F_13 ( V_11 ) ;
return V_10 ;
}
static void F_14 ( void )
{
F_12 ( V_20 ) ;
F_15 ( V_11 ) ;
}
static int T_3 F_16 ( void )
{
int V_23 ;
if ( ! F_17 ( V_20 ) ||
! F_18 ( V_24 ) )
return - V_25 ;
V_23 = F_7 () ;
if ( V_23 ) {
F_4 ( L_5 ) ;
return V_23 ;
}
F_19 ( L_6 ) ;
return 0 ;
}
static void T_4 F_20 ( void )
{
if ( F_17 ( V_20 ) )
F_14 () ;
}
