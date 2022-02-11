static int F_1 ( const struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 & ~ ( 1 << V_4 ) )
return - V_5 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_3 ( V_4 , V_7 , V_7 -> V_9 , NULL ,
F_4 ( V_7 -> V_9 ) -> V_10 . V_11 ) ;
if ( V_8 == V_12 )
return 1 ;
return 0 ;
}
static int T_1 F_5 ( struct V_13 * V_13 )
{
V_13 -> V_10 . V_11 = F_6 ( V_13 , & V_11 ) ;
return F_7 ( V_13 -> V_10 . V_11 ) ;
}
static void T_2 F_8 ( struct V_13 * V_13 )
{
F_9 ( V_13 , V_13 -> V_10 . V_11 ) ;
}
static int T_3 F_10 ( void )
{
int V_8 ;
V_8 = F_11 ( & V_14 ) ;
if ( V_8 < 0 )
return V_8 ;
F_12 ( V_15 ,
( V_16 * ) F_2 ) ;
return 0 ;
}
static void T_4 F_13 ( void )
{
F_12 ( V_15 , NULL ) ;
F_14 () ;
F_15 ( & V_14 ) ;
}
