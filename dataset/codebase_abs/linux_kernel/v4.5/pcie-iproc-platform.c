static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = V_2 -> V_9 . V_10 ;
struct V_11 V_12 ;
T_1 V_13 = 0 ;
F_2 ( V_14 ) ;
int V_15 ;
V_4 = F_3 ( V_16 , & V_2 -> V_9 ) ;
if ( ! V_4 )
return - V_17 ;
V_6 = F_4 ( & V_2 -> V_9 , sizeof( struct V_5 ) , V_18 ) ;
if ( ! V_6 )
return - V_19 ;
V_6 -> V_9 = & V_2 -> V_9 ;
V_6 -> type = (enum V_20 ) V_4 -> V_21 ;
F_5 ( V_2 , V_6 ) ;
V_15 = F_6 ( V_8 , 0 , & V_12 ) ;
if ( V_15 < 0 ) {
F_7 ( V_6 -> V_9 , L_1 ) ;
return V_15 ;
}
V_6 -> V_22 = F_8 ( V_6 -> V_9 , V_12 . V_23 , F_9 ( & V_12 ) ) ;
if ( ! V_6 -> V_22 ) {
F_7 ( V_6 -> V_9 , L_2 ) ;
return - V_19 ;
}
V_6 -> V_24 = V_12 . V_23 ;
if ( F_10 ( V_8 , L_3 ) ) {
T_2 V_25 ;
V_15 = F_11 ( V_8 , L_4 ,
& V_25 ) ;
if ( V_15 ) {
F_7 ( V_6 -> V_9 ,
L_5 ) ;
return V_15 ;
}
V_6 -> V_26 . V_27 = V_25 ;
V_15 = F_11 ( V_8 , L_6 ,
& V_25 ) ;
if ( V_15 ) {
F_7 ( V_6 -> V_9 ,
L_7 ) ;
return V_15 ;
}
V_6 -> V_26 . V_28 = ( T_1 ) V_25 * V_29 ;
if ( F_10 ( V_8 , L_8 ) )
V_6 -> V_26 . V_30 = true ;
V_6 -> V_31 = true ;
}
V_6 -> V_32 = F_12 ( & V_2 -> V_9 , L_9 ) ;
if ( F_13 ( V_6 -> V_32 ) ) {
if ( F_14 ( V_6 -> V_32 ) == - V_33 )
return - V_33 ;
V_6 -> V_32 = NULL ;
}
V_15 = F_15 ( V_8 , 0 , 0xff , & V_14 , & V_13 ) ;
if ( V_15 ) {
F_7 ( V_6 -> V_9 ,
L_10 ) ;
return V_15 ;
}
V_6 -> V_34 = V_35 ;
V_15 = F_16 ( V_6 , & V_14 ) ;
if ( V_15 )
F_7 ( V_6 -> V_9 , L_11 ) ;
F_17 ( & V_14 ) ;
return V_15 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_19 ( V_2 ) ;
return F_20 ( V_6 ) ;
}
