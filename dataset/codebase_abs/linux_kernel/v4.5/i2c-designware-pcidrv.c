static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( F_4 ( V_4 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_6 ( F_4 ( V_4 ) ) ;
}
static T_1 F_7 ( struct V_5 * V_2 )
{
return V_2 -> V_6 -> V_7 ;
}
static int F_8 ( struct V_3 * V_4 ,
const struct V_8 * V_9 )
{
struct V_5 * V_2 ;
struct V_10 * V_11 ;
int V_12 ;
struct V_13 * V_6 ;
struct V_14 * V_15 ;
if ( V_9 -> V_16 >= F_9 ( V_17 ) ) {
F_10 ( & V_4 -> V_2 , L_1 , V_18 ,
V_9 -> V_16 ) ;
return - V_19 ;
}
V_6 = & V_17 [ V_9 -> V_16 ] ;
V_12 = F_11 ( V_4 ) ;
if ( V_12 ) {
F_10 ( & V_4 -> V_2 , L_2 ,
V_12 ) ;
return V_12 ;
}
V_12 = F_12 ( V_4 , 1 << 0 , F_13 ( V_4 ) ) ;
if ( V_12 ) {
F_10 ( & V_4 -> V_2 , L_3 ) ;
return V_12 ;
}
V_2 = F_14 ( & V_4 -> V_2 , sizeof( struct V_5 ) , V_20 ) ;
if ( ! V_2 )
return - V_21 ;
V_2 -> V_22 = NULL ;
V_2 -> V_6 = V_6 ;
V_2 -> V_23 = F_7 ;
V_2 -> V_24 = F_15 ( V_4 ) [ 0 ] ;
V_2 -> V_2 = & V_4 -> V_2 ;
V_2 -> V_25 = V_4 -> V_25 ;
V_2 -> V_26 = V_6 -> V_26 |
V_27 ;
V_2 -> V_28 = V_6 -> V_29 ;
if ( V_6 -> V_30 ) {
V_15 = V_6 -> V_30 ;
V_2 -> V_31 = V_15 -> V_31 ;
V_2 -> V_32 = V_15 -> V_32 ;
V_2 -> V_33 = V_15 -> V_33 ;
V_2 -> V_34 = V_15 -> V_34 ;
V_2 -> V_35 = V_15 -> V_36 ;
}
F_16 ( V_4 , V_2 ) ;
V_2 -> V_37 = V_6 -> V_37 ;
V_2 -> V_38 = V_6 -> V_38 ;
V_11 = & V_2 -> V_39 ;
V_11 -> V_40 = V_41 ;
V_11 -> V_42 = 0 ;
F_17 ( & V_11 -> V_2 , F_18 ( & V_4 -> V_2 ) ) ;
V_11 -> V_43 = V_6 -> V_44 ;
V_12 = F_19 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_20 ( & V_4 -> V_2 , 1000 ) ;
F_21 ( & V_4 -> V_2 ) ;
F_22 ( & V_4 -> V_2 ) ;
F_23 ( & V_4 -> V_2 ) ;
return 0 ;
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_5 * V_2 = F_4 ( V_4 ) ;
F_3 ( V_2 ) ;
F_25 ( & V_4 -> V_2 ) ;
F_26 ( & V_4 -> V_2 ) ;
F_27 ( & V_2 -> V_39 ) ;
}
