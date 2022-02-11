static int F_1 ( const struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 & ~ V_4 )
return - V_5 ;
return 0 ;
}
static unsigned int
F_2 ( unsigned int V_6 , struct V_7 * V_8 , const struct V_9 * V_10 ,
const struct V_9 * V_11 , int (* F_3)( struct V_7 * ) )
{
return F_4 ( V_6 , V_8 , V_10 , V_11 , F_5 ( V_10 ) -> V_12 . V_13 ) ;
}
static unsigned int
F_6 ( unsigned int V_6 , struct V_7 * V_8 , const struct V_9 * V_10 ,
const struct V_9 * V_11 , int (* F_3)( struct V_7 * ) )
{
return F_4 ( V_6 , V_8 , V_10 , V_11 , F_5 ( V_11 ) -> V_12 . V_13 ) ;
}
static int T_1 F_7 ( struct V_14 * V_14 )
{
V_14 -> V_12 . V_13 = F_8 ( V_14 , & V_13 ) ;
if ( F_9 ( V_14 -> V_12 . V_13 ) )
return F_10 ( V_14 -> V_12 . V_13 ) ;
return 0 ;
}
static void T_2 F_11 ( struct V_14 * V_14 )
{
F_12 ( V_14 , V_14 -> V_12 . V_13 ) ;
}
static int T_3 F_13 ( void )
{
int V_15 ;
V_15 = F_14 ( & V_16 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_15 ( V_17 , F_16 ( V_17 ) ) ;
if ( V_15 < 0 )
F_17 ( & V_16 ) ;
return V_15 ;
}
static void T_4 F_18 ( void )
{
F_19 ( V_17 , F_16 ( V_17 ) ) ;
F_17 ( & V_16 ) ;
}
