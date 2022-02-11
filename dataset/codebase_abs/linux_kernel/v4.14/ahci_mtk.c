static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
V_6 -> V_9 = F_2 ( V_4 , L_1 ) ;
if ( F_3 ( V_6 -> V_9 ) == - V_10 )
return F_3 ( V_6 -> V_9 ) ;
V_6 -> V_11 = F_2 ( V_4 , L_2 ) ;
if ( F_3 ( V_6 -> V_11 ) == - V_10 )
return F_3 ( V_6 -> V_11 ) ;
V_6 -> V_12 = F_2 ( V_4 , L_3 ) ;
if ( F_3 ( V_6 -> V_12 ) == - V_10 )
return F_3 ( V_6 -> V_12 ) ;
V_8 = F_4 ( V_6 -> V_9 ) ;
if ( V_8 ) {
F_5 ( V_4 , L_4 ) ;
return V_8 ;
}
V_8 = F_4 ( V_6 -> V_11 ) ;
if ( V_8 ) {
F_5 ( V_4 , L_5 ) ;
return V_8 ;
}
V_8 = F_4 ( V_6 -> V_12 ) ;
if ( V_8 ) {
F_5 ( V_4 , L_6 ) ;
return V_8 ;
}
V_8 = F_6 ( V_6 -> V_12 ) ;
if ( V_8 ) {
F_5 ( V_4 , L_7 ) ;
return V_8 ;
}
V_8 = F_6 ( V_6 -> V_11 ) ;
if ( V_8 ) {
F_5 ( V_4 , L_8 ) ;
return V_8 ;
}
V_8 = F_6 ( V_6 -> V_9 ) ;
if ( V_8 ) {
F_5 ( V_4 , L_9 ) ;
return V_8 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_13 * V_14 = V_4 -> V_15 ;
if ( F_8 ( V_14 , L_10 , NULL ) ) {
V_6 -> V_16 = F_9 (
V_14 , L_10 ) ;
if ( F_10 ( V_6 -> V_16 ) ) {
F_5 ( V_4 , L_11 ) ;
return F_3 ( V_6 -> V_16 ) ;
}
F_11 ( V_6 -> V_16 , V_17 , V_18 ,
V_19 ) ;
}
F_12 ( V_14 , L_12 , & V_2 -> V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = & V_22 -> V_4 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_8 ;
V_6 = F_14 ( V_4 , sizeof( * V_6 ) , V_23 ) ;
if ( ! V_6 )
return - V_24 ;
V_2 = F_15 ( V_22 ) ;
if ( F_10 ( V_2 ) )
return F_3 ( V_2 ) ;
V_2 -> V_7 = V_6 ;
V_8 = F_7 ( V_2 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_1 ( V_2 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_16 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_8 = F_17 ( V_22 , V_2 , & V_25 ,
& V_26 ) ;
if ( V_8 )
goto V_27;
return 0 ;
V_27:
F_18 ( V_2 ) ;
return V_8 ;
}
