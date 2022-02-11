static int F_1 ( const struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 & ~ V_4 )
return - V_5 ;
return 0 ;
}
static unsigned int
F_2 ( const struct V_6 * V_7 , struct V_8 * V_9 ,
const struct V_10 * V_11 , const struct V_10 * V_12 ,
int (* F_3)( struct V_8 * ) )
{
return F_4 ( V_7 -> V_13 , V_9 , V_11 , V_12 ,
F_5 ( V_11 ) -> V_14 . V_15 ) ;
}
static unsigned int
F_6 ( const struct V_6 * V_7 , struct V_8 * V_9 ,
const struct V_10 * V_11 , const struct V_10 * V_12 ,
int (* F_3)( struct V_8 * ) )
{
return F_4 ( V_7 -> V_13 , V_9 , V_11 , V_12 ,
F_5 ( V_12 ) -> V_14 . V_15 ) ;
}
static int T_1 F_7 ( struct V_16 * V_16 )
{
V_16 -> V_14 . V_15 = F_8 ( V_16 , & V_15 ) ;
return F_9 ( V_16 -> V_14 . V_15 ) ;
}
static void T_2 F_10 ( struct V_16 * V_16 )
{
F_11 ( V_16 , V_16 -> V_14 . V_15 ) ;
}
static int T_3 F_12 ( void )
{
int V_17 ;
V_17 = F_13 ( & V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_14 ( V_19 , F_15 ( V_19 ) ) ;
if ( V_17 < 0 )
F_16 ( & V_18 ) ;
return V_17 ;
}
static void T_4 F_17 ( void )
{
F_18 ( V_19 , F_15 ( V_19 ) ) ;
F_16 ( & V_18 ) ;
}
