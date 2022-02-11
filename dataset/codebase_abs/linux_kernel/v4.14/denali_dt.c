static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
const struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_6 = F_2 ( & V_2 -> V_12 , sizeof( * V_6 ) , V_13 ) ;
if ( ! V_6 )
return - V_14 ;
V_10 = & V_6 -> V_10 ;
V_8 = F_3 ( & V_2 -> V_12 ) ;
if ( V_8 ) {
V_10 -> V_15 = V_8 -> V_15 ;
V_10 -> V_16 = V_8 -> V_16 ;
V_10 -> V_17 = V_8 -> V_17 ;
}
V_10 -> V_12 = & V_2 -> V_12 ;
V_10 -> V_18 = F_4 ( V_2 , 0 ) ;
if ( V_10 -> V_18 < 0 ) {
F_5 ( & V_2 -> V_12 , L_1 ) ;
return V_10 -> V_18 ;
}
V_4 = F_6 ( V_2 , V_19 , L_2 ) ;
V_10 -> V_20 = F_7 ( & V_2 -> V_12 , V_4 ) ;
if ( F_8 ( V_10 -> V_20 ) )
return F_9 ( V_10 -> V_20 ) ;
V_4 = F_6 ( V_2 , V_19 , L_3 ) ;
V_10 -> V_21 = F_7 ( & V_2 -> V_12 , V_4 ) ;
if ( F_8 ( V_10 -> V_21 ) )
return F_9 ( V_10 -> V_21 ) ;
V_6 -> V_22 = F_10 ( & V_2 -> V_12 , NULL ) ;
if ( F_8 ( V_6 -> V_22 ) ) {
F_5 ( & V_2 -> V_12 , L_4 ) ;
return F_9 ( V_6 -> V_22 ) ;
}
V_11 = F_11 ( V_6 -> V_22 ) ;
if ( V_11 )
return V_11 ;
V_10 -> V_23 = F_12 ( V_6 -> V_22 ) ;
V_11 = F_13 ( V_10 ) ;
if ( V_11 )
goto V_24;
F_14 ( V_2 , V_6 ) ;
return 0 ;
V_24:
F_15 ( V_6 -> V_22 ) ;
return V_11 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_17 ( V_2 ) ;
F_18 ( & V_6 -> V_10 ) ;
F_15 ( V_6 -> V_22 ) ;
return 0 ;
}
