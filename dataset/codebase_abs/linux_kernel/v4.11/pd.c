struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_3 ) ;
struct V_10 * V_11 ;
struct V_1 * V_12 ;
V_11 = F_3 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 ) {
V_12 = F_4 ( - V_14 ) ;
goto V_15;
}
F_5 ( & V_9 -> V_16 ) ;
if ( V_9 -> V_17 == V_9 -> V_18 . V_19 . V_20 ) {
F_6 ( & V_9 -> V_16 ) ;
F_7 ( V_11 ) ;
V_12 = F_4 ( - V_14 ) ;
goto V_15;
}
V_9 -> V_17 ++ ;
F_6 ( & V_9 -> V_16 ) ;
V_11 -> V_21 = ! ! V_7 ;
V_12 = & V_11 -> V_22 ;
V_15:
return V_12 ;
}
int F_8 ( struct V_1 * V_22 )
{
struct V_10 * V_11 = F_9 ( V_22 ) ;
struct V_8 * V_9 = F_2 ( V_22 -> V_23 ) ;
F_5 ( & V_9 -> V_16 ) ;
V_9 -> V_17 -- ;
F_6 ( & V_9 -> V_16 ) ;
F_7 ( V_11 ) ;
return 0 ;
}
