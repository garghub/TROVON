static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = V_2 -> V_7 . V_8 ;
struct V_9 V_10 ;
T_1 V_11 = 0 ;
F_2 ( V_12 ) ;
int V_13 ;
V_4 = F_3 ( & V_2 -> V_7 , sizeof( struct V_3 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> V_7 = & V_2 -> V_7 ;
F_4 ( V_2 , V_4 ) ;
V_13 = F_5 ( V_6 , 0 , & V_10 ) ;
if ( V_13 < 0 ) {
F_6 ( V_4 -> V_7 , L_1 ) ;
return V_13 ;
}
V_4 -> V_16 = F_7 ( V_4 -> V_7 , V_10 . V_17 , F_8 ( & V_10 ) ) ;
if ( ! V_4 -> V_16 ) {
F_6 ( V_4 -> V_7 , L_2 ) ;
return - V_15 ;
}
V_4 -> V_18 = F_9 ( & V_2 -> V_7 , L_3 ) ;
if ( F_10 ( V_4 -> V_18 ) ) {
if ( F_11 ( V_4 -> V_18 ) == - V_19 )
return - V_19 ;
V_4 -> V_18 = NULL ;
}
V_13 = F_12 ( V_6 , 0 , 0xff , & V_12 , & V_11 ) ;
if ( V_13 ) {
F_6 ( V_4 -> V_7 ,
L_4 ) ;
return V_13 ;
}
V_4 -> V_20 = V_21 ;
V_13 = F_13 ( V_4 , & V_12 ) ;
if ( V_13 )
F_6 ( V_4 -> V_7 , L_5 ) ;
F_14 ( & V_12 ) ;
return V_13 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_16 ( V_2 ) ;
return F_17 ( V_4 ) ;
}
