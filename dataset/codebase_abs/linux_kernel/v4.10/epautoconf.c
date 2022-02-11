struct V_1 * F_1 (
struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7
)
{
struct V_1 * V_8 ;
T_1 type ;
type = V_5 -> V_9 & V_10 ;
if ( V_3 -> V_11 -> V_12 ) {
V_8 = V_3 -> V_11 -> V_12 ( V_3 , V_5 , V_7 ) ;
if ( V_8 )
goto V_13;
}
F_2 (ep, &gadget->ep_list, ep_list) {
if ( F_3 ( V_3 , V_8 , V_5 , V_7 ) )
goto V_13;
}
return NULL ;
V_13:
if ( V_5 -> V_14 == 0 )
V_5 -> V_14 = F_4 ( V_8 -> V_15 ) ;
V_5 -> V_16 &= V_17 ;
if ( isdigit ( V_8 -> V_18 [ 2 ] ) ) {
T_1 V_19 = F_5 ( & V_8 -> V_18 [ 2 ] , NULL , 10 ) ;
V_5 -> V_16 |= V_19 ;
} else if ( V_5 -> V_16 & V_17 ) {
if ( ++ V_3 -> V_20 > 15 )
return NULL ;
V_5 -> V_16 = V_17 | V_3 -> V_20 ;
} else {
if ( ++ V_3 -> V_21 > 15 )
return NULL ;
V_5 -> V_16 |= V_3 -> V_21 ;
}
if ( ( type == V_22 ) && ! V_7 ) {
int V_23 = V_8 -> V_15 ;
if ( V_23 > 64 )
V_23 = 64 ;
V_5 -> V_14 = F_4 ( V_23 ) ;
}
V_8 -> V_24 = V_5 -> V_16 ;
V_8 -> V_5 = NULL ;
V_8 -> V_25 = NULL ;
V_8 -> V_26 = true ;
return V_8 ;
}
struct V_1 * F_6 (
struct V_2 * V_3 ,
struct V_4 * V_5
)
{
return F_1 ( V_3 , V_5 , NULL ) ;
}
void F_7 ( struct V_1 * V_8 )
{
V_8 -> V_26 = false ;
V_8 -> V_27 = NULL ;
}
void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
F_2 (ep, &gadget->ep_list, ep_list) {
V_8 -> V_26 = false ;
V_8 -> V_27 = NULL ;
}
V_3 -> V_20 = 0 ;
V_3 -> V_21 = 0 ;
}
