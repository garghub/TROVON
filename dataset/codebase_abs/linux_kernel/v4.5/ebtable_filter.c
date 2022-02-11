static int F_1 ( const struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 & ~ V_4 )
return - V_5 ;
return 0 ;
}
static unsigned int
F_2 ( void * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
return F_3 ( V_8 , V_10 , V_10 -> V_11 -> V_12 . V_13 ) ;
}
static unsigned int
F_4 ( void * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
return F_3 ( V_8 , V_10 , V_10 -> V_11 -> V_12 . V_13 ) ;
}
static int T_1 F_5 ( struct V_11 * V_11 )
{
V_11 -> V_12 . V_13 = F_6 ( V_11 , & V_13 ) ;
return F_7 ( V_11 -> V_12 . V_13 ) ;
}
static void T_2 F_8 ( struct V_11 * V_11 )
{
F_9 ( V_11 , V_11 -> V_12 . V_13 ) ;
}
static int T_3 F_10 ( void )
{
int V_14 ;
V_14 = F_11 ( & V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_12 ( V_16 , F_13 ( V_16 ) ) ;
if ( V_14 < 0 )
F_14 ( & V_15 ) ;
return V_14 ;
}
static void T_4 F_15 ( void )
{
F_16 ( V_16 , F_13 ( V_16 ) ) ;
F_14 ( & V_15 ) ;
}
