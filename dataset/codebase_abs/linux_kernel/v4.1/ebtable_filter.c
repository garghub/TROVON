static int F_1 ( const struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 & ~ V_4 )
return - V_5 ;
return 0 ;
}
static unsigned int
F_2 ( const struct V_6 * V_7 , struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
return F_3 ( V_7 -> V_12 , V_9 , V_11 -> V_13 , V_11 -> V_14 ,
F_4 ( V_11 -> V_13 ) -> V_15 . V_16 ) ;
}
static unsigned int
F_5 ( const struct V_6 * V_7 , struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
return F_3 ( V_7 -> V_12 , V_9 , V_11 -> V_13 , V_11 -> V_14 ,
F_4 ( V_11 -> V_14 ) -> V_15 . V_16 ) ;
}
static int T_1 F_6 ( struct V_17 * V_17 )
{
V_17 -> V_15 . V_16 = F_7 ( V_17 , & V_16 ) ;
return F_8 ( V_17 -> V_15 . V_16 ) ;
}
static void T_2 F_9 ( struct V_17 * V_17 )
{
F_10 ( V_17 , V_17 -> V_15 . V_16 ) ;
}
static int T_3 F_11 ( void )
{
int V_18 ;
V_18 = F_12 ( & V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_20 , F_14 ( V_20 ) ) ;
if ( V_18 < 0 )
F_15 ( & V_19 ) ;
return V_18 ;
}
static void T_4 F_16 ( void )
{
F_17 ( V_20 , F_14 ( V_20 ) ) ;
F_15 ( & V_19 ) ;
}
