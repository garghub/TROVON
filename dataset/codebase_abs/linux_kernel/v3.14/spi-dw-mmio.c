static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_4 = F_2 ( & V_2 -> V_10 , sizeof( struct V_3 ) ,
V_11 ) ;
if ( ! V_4 )
return - V_12 ;
V_6 = & V_4 -> V_6 ;
V_8 = F_3 ( V_2 , V_13 , 0 ) ;
if ( ! V_8 ) {
F_4 ( & V_2 -> V_10 , L_1 ) ;
return - V_14 ;
}
V_6 -> V_15 = F_5 ( & V_2 -> V_10 , V_8 ) ;
if ( F_6 ( V_6 -> V_15 ) ) {
F_4 ( & V_2 -> V_10 , L_2 ) ;
return F_7 ( V_6 -> V_15 ) ;
}
V_6 -> V_16 = F_8 ( V_2 , 0 ) ;
if ( V_6 -> V_16 < 0 ) {
F_4 ( & V_2 -> V_10 , L_3 ) ;
return V_6 -> V_16 ;
}
V_4 -> V_17 = F_9 ( & V_2 -> V_10 , NULL ) ;
if ( F_6 ( V_4 -> V_17 ) )
return F_7 ( V_4 -> V_17 ) ;
V_9 = F_10 ( V_4 -> V_17 ) ;
if ( V_9 )
return V_9 ;
V_6 -> V_18 = 0 ;
V_6 -> V_19 = 4 ;
V_6 -> V_20 = F_11 ( V_4 -> V_17 ) ;
V_9 = F_12 ( & V_2 -> V_10 , V_6 ) ;
if ( V_9 )
goto V_21;
F_13 ( V_2 , V_4 ) ;
return 0 ;
V_21:
F_14 ( V_4 -> V_17 ) ;
return V_9 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_16 ( V_2 ) ;
F_14 ( V_4 -> V_17 ) ;
F_17 ( & V_4 -> V_6 ) ;
return 0 ;
}
