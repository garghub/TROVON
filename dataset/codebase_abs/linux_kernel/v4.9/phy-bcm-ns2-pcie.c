static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_4 -> V_6 , V_4 -> V_7 ,
V_8 , V_9 ) ;
if ( V_5 )
goto V_10;
V_5 = F_3 ( V_4 -> V_6 , V_4 -> V_7 ,
V_11 , V_12 ) ;
if ( V_5 )
goto V_10;
return 0 ;
V_10:
F_4 ( & V_4 -> V_13 , L_1 , V_5 ) ;
return V_5 ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_14 * V_13 = & V_4 -> V_13 ;
struct V_15 * V_16 ;
struct V_1 * V_1 ;
V_1 = F_6 ( V_13 , V_13 -> V_17 , & V_18 ) ;
if ( F_7 ( V_1 ) ) {
F_4 ( V_13 , L_2 ) ;
return F_8 ( V_1 ) ;
}
F_9 ( V_1 , V_4 ) ;
V_16 = F_10 ( & V_1 -> V_13 ,
V_19 ) ;
if ( F_7 ( V_16 ) ) {
F_4 ( V_13 , L_3 ) ;
return F_8 ( V_16 ) ;
}
F_11 ( V_13 , L_4 , F_12 ( V_13 ) ) ;
return 0 ;
}
