static int F_1 ( const struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 & ~ ( 1 << V_4 ) )
return - V_5 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 )
{
struct V_8 V_9 ;
int V_10 ;
F_3 ( & V_9 , V_4 ,
V_11 , V_7 -> V_12 , NULL , NULL ,
F_4 ( V_7 -> V_12 ) , NULL ) ;
V_10 = F_5 ( V_7 , & V_9 , V_9 . V_13 -> V_14 . V_15 ) ;
if ( V_10 == V_16 )
return 1 ;
return 0 ;
}
static int T_1 F_6 ( struct V_13 * V_13 )
{
V_13 -> V_14 . V_15 = F_7 ( V_13 , & V_15 ) ;
return F_8 ( V_13 -> V_14 . V_15 ) ;
}
static void T_2 F_9 ( struct V_13 * V_13 )
{
F_10 ( V_13 , V_13 -> V_14 . V_15 ) ;
}
static int T_3 F_11 ( void )
{
int V_10 ;
V_10 = F_12 ( & V_17 ) ;
if ( V_10 < 0 )
return V_10 ;
F_13 ( V_18 ,
( V_19 * ) F_2 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_13 ( V_18 , NULL ) ;
F_15 () ;
F_16 ( & V_17 ) ;
}
