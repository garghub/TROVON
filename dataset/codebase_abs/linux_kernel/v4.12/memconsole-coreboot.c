static int F_1 ( T_1 V_1 )
{
struct V_2 T_2 * V_3 ;
V_3 = F_2 ( V_1 , sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return - V_5 ;
V_6 = F_2 ( V_1 ,
V_3 -> V_7 + sizeof( * V_6 ) ,
V_4 ) ;
F_3 ( V_3 ) ;
if ( ! V_6 )
return - V_5 ;
F_4 ( V_6 -> V_8 ,
F_5 ( V_6 -> V_9 , V_6 -> V_7 ) ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 )
{
int V_12 ;
struct V_13 V_14 ;
V_12 = F_7 ( V_15 , & V_14 , sizeof( V_14 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = F_1 ( V_14 . V_16 ) ;
if ( V_12 )
return V_12 ;
return F_8 () ;
}
static int F_9 ( struct V_10 * V_11 )
{
F_10 () ;
if ( V_6 )
F_3 ( V_6 ) ;
return 0 ;
}
static int T_3 F_11 ( void )
{
struct V_10 * V_11 ;
V_11 = F_12 ( L_1 , - 1 , NULL , 0 ) ;
if ( F_13 ( V_11 ) )
return F_14 ( V_11 ) ;
F_15 ( & V_17 ) ;
return 0 ;
}
