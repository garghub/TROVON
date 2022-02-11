static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 * V_7 ;
const struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_12 ;
V_7 = F_2 ( & V_2 -> V_13 , sizeof( * V_7 ) , V_14 ) ;
if ( ! V_7 )
return - V_15 ;
V_11 = & V_7 -> V_11 ;
V_9 = F_3 ( & V_2 -> V_13 ) ;
if ( V_9 ) {
V_11 -> V_16 = V_9 -> V_16 ;
V_11 -> V_17 = V_9 -> V_17 ;
}
V_11 -> V_18 = V_19 ;
V_11 -> V_13 = & V_2 -> V_13 ;
V_11 -> V_20 = F_4 ( V_2 , 0 ) ;
if ( V_11 -> V_20 < 0 ) {
F_5 ( & V_2 -> V_13 , L_1 ) ;
return V_11 -> V_20 ;
}
V_4 = F_6 ( V_2 , V_21 ,
L_2 ) ;
V_11 -> V_22 = F_7 ( & V_2 -> V_13 , V_4 ) ;
if ( F_8 ( V_11 -> V_22 ) )
return F_9 ( V_11 -> V_22 ) ;
V_5 = F_6 ( V_2 , V_21 ,
L_3 ) ;
V_11 -> V_23 = F_7 ( & V_2 -> V_13 , V_5 ) ;
if ( F_8 ( V_11 -> V_23 ) )
return F_9 ( V_11 -> V_23 ) ;
V_7 -> V_24 = F_10 ( & V_2 -> V_13 , NULL ) ;
if ( F_8 ( V_7 -> V_24 ) ) {
F_5 ( & V_2 -> V_13 , L_4 ) ;
return F_9 ( V_7 -> V_24 ) ;
}
F_11 ( V_7 -> V_24 ) ;
V_12 = F_12 ( V_11 ) ;
if ( V_12 )
goto V_25;
F_13 ( V_2 , V_7 ) ;
return 0 ;
V_25:
F_14 ( V_7 -> V_24 ) ;
return V_12 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_16 ( V_2 ) ;
F_17 ( & V_7 -> V_11 ) ;
F_14 ( V_7 -> V_24 ) ;
return 0 ;
}
