static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_7 ;
int V_8 ;
V_7 = ( V_9 / 100 ) *
V_4 -> V_10 -> V_11 [ V_6 ] . V_7 ;
V_8 = F_4 ( V_4 -> V_12 , V_7 , V_9 ) ;
if ( V_8 ) {
F_5 ( & V_2 -> V_2 , L_1 ) ;
return V_8 ;
}
V_4 -> V_5 = V_6 ;
if ( ! V_4 -> V_13 ) {
V_8 = F_6 ( V_4 -> V_12 ) ;
if ( V_8 ) {
F_5 ( & V_2 -> V_2 , L_2 ) ;
return V_8 ;
}
V_4 -> V_13 = true ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_6 >= V_2 -> V_14 -> V_15 )
return - V_16 ;
return V_4 -> V_10 -> V_11 [ V_6 ] . V_17 ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_3 * V_4 ;
struct V_1 * V_20 ;
struct V_21 V_22 = { } ;
struct V_23 * V_24 = V_19 -> V_2 . V_25 ;
const struct V_26 * V_27 ;
if ( ! V_24 ) {
F_5 ( & V_19 -> V_2 , L_3 ) ;
return - V_16 ;
}
V_4 = F_9 ( & V_19 -> V_2 , sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 )
return - V_29 ;
V_27 = F_10 ( V_30 , & V_19 -> V_2 ) ;
if ( ! V_27 ) {
F_5 ( & V_19 -> V_2 , L_4 ) ;
return - V_31 ;
}
V_4 -> V_10 = V_27 -> V_32 ;
V_22 . V_33 = F_11 ( & V_19 -> V_2 , V_24 ) ;
if ( ! V_22 . V_33 )
return - V_29 ;
V_22 . V_25 = V_24 ;
V_22 . V_2 = & V_19 -> V_2 ;
V_22 . V_34 = V_4 ;
V_4 -> V_12 = F_12 ( & V_19 -> V_2 , NULL ) ;
if ( F_13 ( V_4 -> V_12 ) ) {
F_5 ( & V_19 -> V_2 , L_5 ) ;
return F_14 ( V_4 -> V_12 ) ;
}
V_20 = F_15 ( & V_19 -> V_2 ,
V_4 -> V_10 -> V_14 , & V_22 ) ;
if ( F_13 ( V_20 ) ) {
F_5 ( & V_19 -> V_2 , L_6 ,
V_4 -> V_10 -> V_14 -> V_35 ) ;
return F_14 ( V_20 ) ;
}
return 0 ;
}
