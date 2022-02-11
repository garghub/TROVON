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
F_3 ( & V_9 , NULL , V_4 , V_11 ,
V_12 , V_7 -> V_13 , NULL , NULL ,
F_4 ( V_7 -> V_13 ) , NULL ) ;
V_10 = F_5 ( V_7 , & V_9 , V_9 . V_14 -> V_15 . V_16 ) ;
if ( V_10 == V_17 )
return 1 ;
return 0 ;
}
static int T_1 F_6 ( struct V_14 * V_14 )
{
V_14 -> V_15 . V_16 = F_7 ( V_14 , & V_16 ) ;
return F_8 ( V_14 -> V_15 . V_16 ) ;
}
static void T_2 F_9 ( struct V_14 * V_14 )
{
F_10 ( V_14 , V_14 -> V_15 . V_16 ) ;
}
static int T_3 F_11 ( void )
{
int V_10 ;
V_10 = F_12 ( & V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
F_13 ( V_19 ,
( V_20 * ) F_2 ) ;
return 0 ;
}
static void T_4 F_14 ( void )
{
F_13 ( V_19 , NULL ) ;
F_15 () ;
F_16 ( & V_18 ) ;
}
