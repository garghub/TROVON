static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 , unsigned int V_5 )
{
const unsigned int V_6 = F_2 ( V_4 / 2 ) ;
void T_1 * V_7 ;
T_2 V_8 , V_9 ;
if ( F_3 ( V_4 ) )
V_9 = V_10 ;
else
V_9 = V_11 ;
F_4 ( & V_2 -> V_12 ) ;
if ( ! F_5 ( V_2 -> V_13 ) ) {
F_6 ( V_2 -> V_13 , V_6 , & V_8 ) ;
if ( V_5 )
V_8 |= V_9 ;
else
V_8 &= ~ V_9 ;
F_7 ( V_2 -> V_13 , V_6 , V_8 ) ;
if ( V_5 )
V_8 |= V_14 ;
else if ( ! ( V_8 & V_15 ) )
V_8 &= ~ V_14 ;
F_7 ( V_2 -> V_13 , V_6 , V_8 ) ;
} else {
V_7 = V_2 -> V_16 + F_8 ( V_4 / 2 ) ;
V_8 = F_9 ( V_7 ) ;
if ( V_5 )
V_8 |= V_9 ;
else
V_8 &= ~ V_9 ;
F_10 ( V_8 , V_7 ) ;
if ( V_5 )
V_8 |= V_14 ;
else if ( ! ( V_8 & V_15 ) )
V_8 &= ~ V_14 ;
F_10 ( V_8 , V_7 ) ;
}
F_11 ( & V_2 -> V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_17 * V_17 )
{
struct V_18 * V_19 = F_13 ( V_17 ) ;
struct V_1 * V_2 = F_14 ( V_19 ) ;
return F_1 ( V_2 , V_19 -> V_20 , 1 ) ;
}
static int F_15 ( struct V_17 * V_17 )
{
struct V_18 * V_19 = F_13 ( V_17 ) ;
struct V_1 * V_2 = F_14 ( V_19 ) ;
return F_1 ( V_2 , V_19 -> V_20 , 0 ) ;
}
static struct V_17 * F_16 ( struct V_21 * V_22 ,
struct V_23 * args )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
if ( F_18 ( args -> args [ 0 ] >= V_24 ) )
return F_19 ( - V_25 ) ;
return V_2 -> V_26 [ args -> args [ 0 ] ] . V_17 ;
}
static int F_20 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_21 * V_22 = & V_28 -> V_22 ;
struct V_29 * V_29 ;
unsigned int V_30 ;
V_2 = F_21 ( V_22 , sizeof( * V_2 ) , V_31 ) ;
if ( ! V_2 )
return - V_32 ;
V_2 -> V_13 = F_22 ( V_22 -> V_33 , L_1 ) ;
if ( F_5 ( V_2 -> V_13 ) ) {
struct V_34 * V_35 ;
F_23 ( V_22 , L_2 ,
F_24 ( V_2 -> V_13 ) ) ;
V_35 = F_25 ( V_28 , V_36 , 0 ) ;
V_2 -> V_16 = F_26 ( V_22 , V_35 ) ;
if ( F_5 ( V_2 -> V_16 ) )
return F_24 ( V_2 -> V_16 ) ;
}
F_27 ( V_22 , V_2 ) ;
F_28 ( & V_2 -> V_12 ) ;
for ( V_30 = 0 ; V_30 < V_24 ; V_30 ++ ) {
struct V_17 * V_17 = F_29 ( V_22 , NULL ,
& V_37 ) ;
if ( F_5 ( V_17 ) ) {
F_30 ( V_22 , L_3 , V_30 ) ;
return F_24 ( V_17 ) ;
}
V_2 -> V_26 [ V_30 ] . V_17 = V_17 ;
V_2 -> V_26 [ V_30 ] . V_20 = V_30 ;
F_31 ( V_17 , & V_2 -> V_26 [ V_30 ] ) ;
}
V_29 = F_32 ( V_22 ,
F_16 ) ;
return F_33 ( V_29 ) ;
}
