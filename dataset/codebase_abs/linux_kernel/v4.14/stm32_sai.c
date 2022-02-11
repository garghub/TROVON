static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
void T_1 * V_13 ;
const struct V_14 * V_15 ;
V_8 = F_2 ( & V_2 -> V_5 , sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 )
return - V_17 ;
V_12 = F_3 ( V_2 , V_18 , 0 ) ;
V_13 = F_4 ( & V_2 -> V_5 , V_12 ) ;
if ( F_5 ( V_13 ) )
return F_6 ( V_13 ) ;
V_15 = F_7 ( V_19 , & V_2 -> V_5 ) ;
if ( V_15 )
V_8 -> V_20 = (struct V_21 * ) V_15 -> V_22 ;
else
return - V_23 ;
V_8 -> V_24 = F_8 ( & V_2 -> V_5 , L_1 ) ;
if ( F_5 ( V_8 -> V_24 ) ) {
F_9 ( & V_2 -> V_5 , L_2 ) ;
return F_6 ( V_8 -> V_24 ) ;
}
V_8 -> V_25 = F_8 ( & V_2 -> V_5 , L_3 ) ;
if ( F_5 ( V_8 -> V_25 ) ) {
F_9 ( & V_2 -> V_5 , L_4 ) ;
return F_6 ( V_8 -> V_25 ) ;
}
V_8 -> V_26 = F_10 ( V_2 , 0 ) ;
if ( V_8 -> V_26 < 0 ) {
F_9 ( & V_2 -> V_5 , L_5 , V_2 -> V_27 ) ;
return V_8 -> V_26 ;
}
V_10 = F_11 ( & V_2 -> V_5 , NULL ) ;
if ( ! F_5 ( V_10 ) ) {
F_12 ( V_10 ) ;
F_13 ( 2 ) ;
F_14 ( V_10 ) ;
}
V_8 -> V_2 = V_2 ;
F_15 ( V_2 , V_8 ) ;
return F_16 ( V_4 , NULL , NULL , & V_2 -> V_5 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_5 ) ;
return 0 ;
}
