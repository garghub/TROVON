static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
int V_4 ;
V_4 = F_3 ( V_1 -> V_5 -> V_6 , V_1 -> V_5 -> V_7 ,
V_8 , V_9 ) ;
if ( V_4 )
goto V_10;
V_4 = F_3 ( V_1 -> V_5 -> V_6 , V_1 -> V_5 -> V_7 ,
V_11 , V_12 ) ;
if ( V_4 )
goto V_10;
return 0 ;
V_10:
F_4 ( & V_1 -> V_5 -> V_13 , L_1 , V_4 ) ;
return V_4 ;
}
static int F_5 ( struct V_14 * V_5 )
{
struct V_15 * V_13 = & V_5 -> V_13 ;
struct V_16 * V_17 ;
struct V_3 * V_2 ;
struct V_1 * V_1 ;
V_1 = F_6 ( V_13 , V_13 -> V_18 , & V_19 ) ;
if ( F_7 ( V_1 ) ) {
F_4 ( V_13 , L_2 ) ;
return F_8 ( V_1 ) ;
}
V_2 = F_9 ( V_13 , sizeof( struct V_3 ) ,
V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_5 = V_5 ;
F_10 ( V_13 , V_2 ) ;
V_2 -> V_1 = V_1 ;
F_11 ( V_1 , V_2 ) ;
V_17 = F_12 ( & V_1 -> V_13 ,
V_22 ) ;
if ( F_7 ( V_17 ) ) {
F_4 ( V_13 , L_3 ) ;
return F_8 ( V_17 ) ;
}
F_13 ( V_13 , L_4 , F_14 ( V_13 ) ) ;
return 0 ;
}
