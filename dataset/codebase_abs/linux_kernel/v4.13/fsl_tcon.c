void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 , 0 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
V_5 ,
V_5 ) ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_10 V_11 ;
void T_1 * V_3 ;
if ( F_5 ( V_9 , 0 , & V_11 ) )
return - V_12 ;
V_3 = F_6 ( V_7 , & V_11 ) ;
if ( F_7 ( V_3 ) )
return F_8 ( V_3 ) ;
V_2 -> V_3 = F_9 ( V_7 , V_3 ,
& V_13 ) ;
return F_10 ( V_2 -> V_3 ) ;
}
struct V_1 * F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
int V_14 ;
V_9 = F_12 ( V_7 -> V_15 , L_1 , 0 ) ;
if ( ! V_9 )
return NULL ;
V_2 = F_13 ( V_7 , sizeof( * V_2 ) , V_16 ) ;
if ( ! V_2 )
goto V_17;
V_14 = F_4 ( V_7 , V_2 , V_9 ) ;
if ( V_14 ) {
F_14 ( V_7 , L_2 ) ;
goto V_17;
}
V_2 -> V_18 = F_15 ( V_9 , L_3 ) ;
if ( F_7 ( V_2 -> V_18 ) ) {
F_14 ( V_7 , L_4 ) ;
goto V_17;
}
V_14 = F_16 ( V_2 -> V_18 ) ;
if ( V_14 ) {
F_14 ( V_7 , L_5 ) ;
goto V_17;
}
F_17 ( V_9 ) ;
F_18 ( V_7 , L_6 ) ;
return V_2 ;
V_17:
F_17 ( V_9 ) ;
return NULL ;
}
void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_18 ) ;
F_21 ( V_2 -> V_18 ) ;
}
