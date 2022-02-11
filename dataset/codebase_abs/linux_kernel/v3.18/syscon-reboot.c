static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 ,
V_7 ) ;
F_3 ( V_6 -> V_8 , V_6 -> V_9 , V_6 -> V_10 ) ;
F_4 ( 1000 ) ;
F_5 ( L_1 ) ;
return V_11 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_5 * V_6 ;
struct V_14 * V_15 = & V_13 -> V_15 ;
int V_16 ;
V_6 = F_7 ( & V_13 -> V_15 , sizeof( * V_6 ) , V_17 ) ;
if ( ! V_6 )
return - V_18 ;
V_6 -> V_8 = F_8 ( V_15 -> V_19 , L_2 ) ;
if ( F_9 ( V_6 -> V_8 ) )
return F_10 ( V_6 -> V_8 ) ;
if ( F_11 ( V_13 -> V_15 . V_19 , L_3 , & V_6 -> V_9 ) )
return - V_20 ;
if ( F_11 ( V_13 -> V_15 . V_19 , L_4 , & V_6 -> V_10 ) )
return - V_20 ;
V_6 -> V_7 . V_21 = F_1 ;
V_6 -> V_7 . V_22 = 128 ;
V_16 = F_12 ( & V_6 -> V_7 ) ;
if ( V_16 )
F_13 ( V_15 , L_5 , V_16 ) ;
return V_16 ;
}
