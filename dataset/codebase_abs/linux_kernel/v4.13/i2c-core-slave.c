int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
if ( ! V_2 || ! V_3 ) {
F_2 ( 1 , L_1 ) ;
return - V_5 ;
}
if ( ! ( V_2 -> V_6 & V_7 ) )
F_3 ( & V_2 -> V_8 , L_2 ,
V_9 ) ;
if ( ! ( V_2 -> V_6 & V_10 ) ) {
V_4 = F_4 ( V_2 -> V_11 ) ;
if ( V_4 ) {
F_5 ( & V_2 -> V_8 , L_3 , V_9 ) ;
return V_4 ;
}
}
if ( ! V_2 -> V_12 -> V_13 -> V_14 ) {
F_5 ( & V_2 -> V_8 , L_4 , V_9 ) ;
return - V_15 ;
}
V_2 -> V_3 = V_3 ;
F_6 ( V_2 -> V_12 ) ;
V_4 = V_2 -> V_12 -> V_13 -> V_14 ( V_2 ) ;
F_7 ( V_2 -> V_12 ) ;
if ( V_4 ) {
V_2 -> V_3 = NULL ;
F_5 ( & V_2 -> V_8 , L_5 , V_9 , V_4 ) ;
}
return V_4 ;
}
int F_8 ( struct V_1 * V_2 )
{
int V_4 ;
if ( ! V_2 -> V_12 -> V_13 -> V_16 ) {
F_5 ( & V_2 -> V_8 , L_4 , V_9 ) ;
return - V_15 ;
}
F_6 ( V_2 -> V_12 ) ;
V_4 = V_2 -> V_12 -> V_13 -> V_16 ( V_2 ) ;
F_7 ( V_2 -> V_12 ) ;
if ( V_4 == 0 )
V_2 -> V_3 = NULL ;
else
F_5 ( & V_2 -> V_8 , L_5 , V_9 , V_4 ) ;
return V_4 ;
}
bool F_9 ( struct V_17 * V_8 )
{
if ( F_10 ( V_18 ) && V_8 -> V_19 ) {
struct V_20 * V_21 ;
T_2 V_22 ;
F_11 (dev->of_node, child) {
F_12 ( V_21 , L_6 , & V_22 ) ;
if ( V_22 & V_23 ) {
F_13 ( V_21 ) ;
return true ;
}
}
} else if ( F_10 ( V_24 ) && F_14 ( V_8 ) ) {
F_15 ( V_8 , L_7 ) ;
}
return false ;
}
