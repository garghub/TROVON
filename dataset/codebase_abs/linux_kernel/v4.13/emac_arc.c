static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 , V_10 ;
if ( ! V_4 -> V_11 )
return - V_12 ;
V_6 = F_2 ( sizeof( struct V_7 ) ) ;
if ( ! V_6 )
return - V_13 ;
F_3 ( V_2 , V_6 ) ;
F_4 ( V_6 , V_4 ) ;
V_8 = F_5 ( V_6 ) ;
V_8 -> V_14 = V_15 ;
V_8 -> V_16 = V_17 ;
V_9 = F_6 ( V_4 -> V_11 ) ;
if ( V_9 < 0 )
V_9 = V_18 ;
V_8 -> V_19 = F_7 ( V_4 , L_1 ) ;
if ( F_8 ( V_8 -> V_19 ) ) {
F_9 ( V_4 , L_2 ) ;
V_10 = - V_20 ;
goto V_21;
}
V_10 = F_10 ( V_6 , V_9 ) ;
V_21:
if ( V_10 )
F_11 ( V_6 ) ;
return V_10 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_13 ( V_2 ) ;
int V_10 ;
V_10 = F_14 ( V_6 ) ;
F_11 ( V_6 ) ;
return V_10 ;
}
