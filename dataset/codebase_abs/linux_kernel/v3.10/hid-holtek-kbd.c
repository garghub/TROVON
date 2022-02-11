static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
if ( V_6 -> V_9 -> V_10 . V_11 == 1 ) {
V_3 = V_12 ;
* V_4 = sizeof( V_12 ) ;
}
return V_3 ;
}
static int F_3 ( struct V_13 * V_7 , unsigned int type ,
unsigned int V_14 ,
int V_15 )
{
struct V_1 * V_16 = F_4 ( V_7 ) ;
struct V_17 * V_18 = F_5 ( V_16 ) ;
struct V_5 * V_19 = F_6 ( V_18 , 0 ) ;
struct V_1 * V_20 = F_7 ( V_19 ) ;
struct V_21 * V_22 = F_8 ( & V_20 -> V_23 ,
struct V_21 , V_24 ) ;
return V_22 -> V_25 -> V_26 ( V_22 -> V_25 , type , V_14 ,
V_15 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_27 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 -> V_7 . V_8 ) ;
int V_29 = F_10 ( V_2 ) ;
if ( ! V_29 )
V_29 = F_11 ( V_2 , V_30 ) ;
if ( ! V_29 && V_6 -> V_9 -> V_10 . V_11 == 1 ) {
struct V_21 * V_31 ;
F_12 (hidinput, &hdev->inputs, list) {
V_31 -> V_25 -> V_26 = F_3 ;
}
}
return V_29 ;
}
