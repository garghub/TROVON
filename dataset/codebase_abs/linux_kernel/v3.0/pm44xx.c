static int F_1 ( void )
{
F_2 () ;
return 0 ;
}
static int F_3 ( T_1 V_1 )
{
int V_2 = 0 ;
switch ( V_1 ) {
case V_3 :
case V_4 :
V_2 = F_1 () ;
break;
default:
V_2 = - V_5 ;
}
return V_2 ;
}
static int F_4 ( T_1 V_6 )
{
F_5 () ;
return 0 ;
}
static void F_6 ( void )
{
F_7 () ;
return;
}
static int T_2 F_8 ( struct V_7 * V_8 , void * V_9 )
{
struct V_10 * V_11 ;
if ( ! V_8 -> V_12 )
return 0 ;
V_11 = F_9 ( sizeof( struct V_10 ) , V_13 ) ;
if ( ! V_11 )
return - V_14 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_15 = V_16 ;
F_10 ( & V_11 -> V_17 , & V_18 ) ;
return F_11 ( V_11 -> V_8 , V_11 -> V_15 ) ;
}
static int T_2 F_12 ( void )
{
int V_2 ;
if ( ! F_13 () )
return - V_19 ;
F_14 ( L_1 ) ;
V_2 = F_15 ( F_8 , NULL ) ;
if ( V_2 ) {
F_14 ( L_2 ) ;
goto V_20;
}
#ifdef F_16
F_17 ( & V_21 ) ;
#endif
V_20:
return V_2 ;
}
