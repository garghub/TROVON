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
if ( F_9 ( V_6 , L_3 ) ) {
T_2 V_18 ;
V_13 = F_10 ( V_6 , L_4 ,
& V_18 ) ;
if ( V_13 ) {
F_6 ( V_4 -> V_7 ,
L_5 ) ;
return V_13 ;
}
V_4 -> V_19 . V_20 = V_18 ;
V_13 = F_10 ( V_6 , L_6 ,
& V_18 ) ;
if ( V_13 ) {
F_6 ( V_4 -> V_7 ,
L_7 ) ;
return V_13 ;
}
V_4 -> V_19 . V_21 = ( T_1 ) V_18 * V_22 ;
if ( F_9 ( V_6 , L_8 ) )
V_4 -> V_19 . V_23 = true ;
V_4 -> V_24 = true ;
}
V_4 -> V_25 = F_11 ( & V_2 -> V_7 , L_9 ) ;
if ( F_12 ( V_4 -> V_25 ) ) {
if ( F_13 ( V_4 -> V_25 ) == - V_26 )
return - V_26 ;
V_4 -> V_25 = NULL ;
}
V_13 = F_14 ( V_6 , 0 , 0xff , & V_12 , & V_11 ) ;
if ( V_13 ) {
F_6 ( V_4 -> V_7 ,
L_10 ) ;
return V_13 ;
}
V_4 -> V_27 = V_28 ;
V_13 = F_15 ( V_4 , & V_12 ) ;
if ( V_13 )
F_6 ( V_4 -> V_7 , L_11 ) ;
F_16 ( & V_12 ) ;
return V_13 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_18 ( V_2 ) ;
return F_19 ( V_4 ) ;
}
