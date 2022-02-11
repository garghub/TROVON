static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 , V_7 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_3 ( V_2 -> V_5 , V_6 , & V_3 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 ,
V_7 , 0 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_8 = ! ! ( V_3 & V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = & V_10 -> V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
void T_2 * V_15 ;
int V_4 ;
V_2 = F_5 ( V_12 , sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
return - V_17 ;
V_14 = F_6 ( V_10 , V_18 , 0 ) ;
V_15 = F_7 ( V_12 , V_14 ) ;
if ( F_8 ( V_15 ) )
return F_9 ( V_15 ) ;
V_2 -> V_5 = F_10 ( V_12 , L_1 , V_15 ,
& V_19 ) ;
if ( F_8 ( V_2 -> V_5 ) )
return F_9 ( V_2 -> V_5 ) ;
V_2 -> V_20 = F_11 ( V_12 , NULL ) ;
if ( F_8 ( V_2 -> V_20 ) )
return F_9 ( V_2 -> V_20 ) ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 )
return V_4 ;
F_12 ( V_10 , V_2 ) ;
return F_13 ( & V_10 -> V_12 ) ;
}
