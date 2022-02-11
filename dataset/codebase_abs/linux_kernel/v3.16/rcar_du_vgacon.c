static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
}
static enum V_3
F_5 ( struct V_1 * V_2 , bool V_4 )
{
return V_5 ;
}
int F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
int V_12 ;
V_11 = F_7 ( V_7 -> V_13 , sizeof( * V_11 ) , V_14 ) ;
if ( V_11 == NULL )
return - V_15 ;
V_2 = & V_11 -> V_2 ;
V_2 -> V_16 . V_17 = 0 ;
V_2 -> V_16 . V_18 = 0 ;
V_12 = F_8 ( V_7 -> V_19 , V_2 , & V_20 ,
V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
F_9 ( V_2 , & V_22 ) ;
V_12 = F_10 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
F_11 ( V_2 , V_23 ) ;
F_12 ( & V_2 -> V_24 ,
V_7 -> V_19 -> V_25 . V_26 , V_23 ) ;
V_12 = F_13 ( V_2 , & V_9 -> V_27 ) ;
if ( V_12 < 0 )
return V_12 ;
V_2 -> V_27 = & V_9 -> V_27 ;
V_11 -> V_27 = V_9 ;
return 0 ;
}
