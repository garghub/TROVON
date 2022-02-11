static int F_1 ( struct V_1 * V_2 ,
void * V_3 , int V_4 , void * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
int V_10 ;
if ( ! V_8 )
return - V_11 ;
V_10 = F_3 ( & V_8 -> V_12 , V_3 , V_4 ) ;
if ( V_10 == - V_13 ) {
F_4 ( V_8 -> V_9 , L_1 ) ;
V_10 = 0 ;
}
return V_10 ;
}
static int F_5 ( struct V_14 * V_12 , struct V_15 * V_16 )
{
struct V_7 * V_8 = F_6 ( V_12 , struct V_7 , V_12 ) ;
int V_10 ;
V_10 = F_7 ( V_16 ) ;
if ( V_10 )
goto V_17;
V_10 = F_8 ( V_8 -> V_18 , V_16 -> V_3 , V_16 -> V_4 ) ;
V_17:
if ( V_10 )
F_9 ( V_16 ) ;
else
F_10 ( V_16 ) ;
return V_10 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
int V_10 ;
V_8 = F_12 ( & V_2 -> V_9 , sizeof( * V_8 ) , V_19 ) ;
if ( ! V_8 )
return - V_20 ;
V_8 -> V_18 = V_2 -> V_21 ;
V_8 -> V_9 = & V_2 -> V_9 ;
V_8 -> V_12 . V_22 = F_5 ;
V_10 = F_13 ( & V_8 -> V_12 , V_23 ) ;
if ( V_10 )
return V_10 ;
F_14 ( & V_2 -> V_9 , V_8 ) ;
F_15 ( & V_2 -> V_9 , L_2 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
F_17 ( & V_8 -> V_12 ) ;
F_14 ( & V_2 -> V_9 , NULL ) ;
}
