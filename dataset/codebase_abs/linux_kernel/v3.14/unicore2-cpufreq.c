static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
return - V_4 ;
F_2 ( V_2 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_5 ,
unsigned int V_6 )
{
struct V_7 V_8 ;
int V_9 ;
V_8 . V_10 = V_2 -> V_11 ;
V_8 . V_12 = V_5 ;
F_4 ( V_2 , & V_8 , V_13 ) ;
V_9 = F_5 ( V_2 -> V_14 , V_5 * 1000 ) ;
F_6 ( V_2 , & V_8 , V_9 ) ;
return V_9 ;
}
static int T_1 F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != 0 )
return - V_4 ;
V_2 -> V_15 = V_2 -> V_16 . V_17 = 250000 ;
V_2 -> V_18 = V_2 -> V_16 . V_19 = 1000000 ;
V_2 -> V_16 . V_20 = V_21 ;
V_2 -> V_22 = F_8 ( NULL , L_1 ) ;
if ( F_9 ( V_2 -> V_22 ) )
return F_10 ( V_2 -> V_22 ) ;
return 0 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_23 ) ;
}
