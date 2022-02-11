static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_5 )
{
T_1 V_6 ;
F_2 ( & V_4 -> V_7 ) ;
if ( ! V_5 && V_2 -> V_8 >= 0 &&
V_4 -> V_9 [ V_2 -> V_8 ] . V_10 -> V_11 == 0 ) {
F_3 ( V_4 -> V_12 [ V_2 -> V_13 ] , V_2 -> V_14 ,
& V_6 ) ;
V_6 &= ~ V_2 -> V_15 ;
F_4 ( V_4 -> V_12 [ V_2 -> V_13 ] , V_2 -> V_14 ,
V_6 ) ;
}
F_3 ( V_4 -> V_12 [ V_2 -> V_16 ] , V_2 -> V_17 , & V_6 ) ;
V_6 = V_5 ? ( V_6 | V_2 -> V_18 ) : ( V_6 & ~ V_2 -> V_18 ) ;
F_4 ( V_4 -> V_12 [ V_2 -> V_16 ] , V_2 -> V_17 , V_6 ) ;
if ( V_5 ) {
F_3 ( V_4 -> V_12 [ V_2 -> V_13 ] , V_2 -> V_14 ,
& V_6 ) ;
V_6 |= V_2 -> V_15 ;
F_4 ( V_4 -> V_12 [ V_2 -> V_13 ] , V_2 -> V_14 ,
V_6 ) ;
}
F_5 ( & V_4 -> V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_10 )
{
struct V_19 * V_20 = F_7 ( V_10 ) ;
struct V_3 * V_4 = F_8 ( V_20 ) ;
return F_1 ( V_20 -> V_2 , V_4 , 1 ) ;
}
static int F_9 ( struct V_10 * V_10 )
{
struct V_19 * V_20 = F_7 ( V_10 ) ;
struct V_3 * V_4 = F_8 ( V_20 ) ;
return F_1 ( V_20 -> V_2 , V_4 , 0 ) ;
}
static struct V_10 * F_10 ( struct V_21 * V_22 ,
struct V_23 * args )
{
struct V_3 * V_4 = F_11 ( V_22 ) ;
if ( F_12 ( args -> args [ 0 ] >= V_4 -> V_24 ) )
return F_13 ( - V_25 ) ;
return V_4 -> V_9 [ args -> args [ 0 ] ] . V_10 ;
}
static int F_14 ( struct V_26 * V_27 )
{
const struct V_28 * V_29 ;
struct V_3 * V_4 ;
struct V_21 * V_22 = & V_27 -> V_22 ;
struct V_30 * V_31 = V_22 -> V_32 ;
struct V_33 * V_33 ;
unsigned int V_34 ;
V_29 = F_15 ( V_22 ) ;
if ( ! V_29 )
return - V_25 ;
V_4 = F_16 ( V_22 , sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 )
return - V_36 ;
for ( V_34 = 0 ; V_34 < V_29 -> V_37 ; V_34 ++ ) {
V_4 -> V_12 [ V_34 ] = F_17 ( V_31 ,
V_29 -> V_38 [ V_34 ] ) ;
if ( F_18 ( V_4 -> V_12 [ V_34 ] ) )
return F_19 ( V_4 -> V_12 [ V_34 ] ) ;
}
V_4 -> V_24 = V_29 -> V_24 ;
F_20 ( & V_4 -> V_7 ) ;
F_21 ( V_22 , V_4 ) ;
for ( V_34 = 0 ; V_34 < V_4 -> V_24 ; V_34 ++ ) {
struct V_10 * V_10 = F_22 ( V_22 , NULL ,
& V_39 ) ;
if ( F_18 ( V_10 ) ) {
F_23 ( V_22 , L_1 , V_34 ) ;
return F_19 ( V_10 ) ;
}
V_4 -> V_9 [ V_34 ] . V_10 = V_10 ;
V_4 -> V_9 [ V_34 ] . V_40 = V_34 ;
V_4 -> V_9 [ V_34 ] . V_2 = & V_29 -> V_9 [ V_34 ] ;
F_24 ( V_10 , & V_4 -> V_9 [ V_34 ] ) ;
}
V_33 = F_25 ( V_22 ,
F_10 ) ;
return F_26 ( V_33 ) ;
}
