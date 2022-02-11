static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 * V_5 )
{
T_1 V_6 ;
T_1 V_7 ;
void * V_8 = & V_7 ;
V_8 += ( V_3 & 0x3 ) ;
V_6 = V_3 & ~ 0x3 ;
V_7 = F_2 ( V_2 , V_6 ) ;
if ( V_4 == 1 )
* V_5 = * ( V_9 V_10 * ) V_8 ;
else if ( V_4 == 2 )
* V_5 = * ( V_11 V_10 * ) V_8 ;
else if ( V_4 == 4 )
* V_5 = V_7 ;
else
return V_12 ;
return V_13 ;
}
static int F_3 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_5 )
{
T_1 V_7 ;
T_1 V_6 ;
void * V_8 = & V_7 ;
V_8 += ( V_3 & 0x3 ) ;
V_6 = V_3 & ~ 0x3 ;
if ( V_4 == 4 )
F_4 ( V_2 , V_6 , V_5 ) ;
else if ( V_4 == 2 ) {
V_7 = F_2 ( V_2 , V_6 ) ;
* ( V_11 V_10 * ) V_8 = V_5 ;
F_4 ( V_2 , V_6 , V_7 ) ;
} else if ( V_4 == 1 ) {
V_7 = F_2 ( V_2 , V_6 ) ;
* ( V_9 V_10 * ) V_8 = V_5 ;
F_4 ( V_2 , V_6 , V_7 ) ;
} else
return V_12 ;
return V_13 ;
}
static int F_5 ( struct V_14 * V_14 )
{
T_1 V_5 ;
F_6 ( V_14 -> V_15 , V_16 +
0x100 * V_14 -> V_17 , & V_5 ) ;
return ( ( V_5 & V_18 ) == V_19 ) ;
}
static int F_7 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = & V_14 -> V_2 ;
T_1 V_5 ;
V_5 = F_2 ( V_2 , V_20 ) ;
return ( ( V_5 & V_18 ) == V_19 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_9 ( V_2 ) ;
return V_14 -> V_21 -> F_8 ( V_14 ) ;
}
static int F_10 ( struct V_14 * V_14 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = & V_14 -> V_2 ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_26 ;
T_1 V_17 ;
if ( F_11 ( V_25 -> V_27 , L_1 , & V_17 ) ) {
F_12 ( V_25 , L_2 ) ;
return - V_28 ;
}
if ( V_17 > 3 ) {
F_12 ( V_25 , L_3 , V_17 ) ;
return - V_28 ;
}
V_14 -> V_17 = V_17 ;
V_2 -> V_29 = & V_30 ;
V_26 = F_13 ( V_2 ) ;
if ( V_26 ) {
F_12 ( V_25 , L_4 ) ;
return V_26 ;
}
return 0 ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_25 ;
struct V_14 * V_14 ;
struct V_1 * V_2 ;
const struct V_31 * V_32 ;
struct V_33 * V_6 ;
struct V_34 * V_35 ;
int V_26 ;
V_14 = F_15 ( V_25 , sizeof( * V_14 ) , V_36 ) ;
if ( ! V_14 )
return - V_37 ;
V_2 = & V_14 -> V_2 ;
V_2 -> V_25 = V_25 ;
V_35 = V_25 -> V_35 ;
V_32 = F_16 ( V_35 -> V_38 , V_25 ) ;
V_14 -> V_21 = (struct V_39 * ) V_32 -> V_40 ;
V_14 -> V_15 =
F_17 ( L_5 ) ;
if ( F_18 ( V_14 -> V_15 ) ) {
F_12 ( V_25 , L_6 ) ;
return F_19 ( V_14 -> V_15 ) ;
}
V_6 = F_20 ( V_23 , V_41 , L_7 ) ;
V_2 -> V_42 = F_21 ( V_25 , V_6 ) ;
if ( F_18 ( V_2 -> V_42 ) ) {
F_12 ( V_25 , L_8 ) ;
return F_19 ( V_2 -> V_42 ) ;
}
V_26 = F_10 ( V_14 , V_23 ) ;
if ( V_26 )
return V_26 ;
F_22 ( V_25 , L_9 ) ;
return 0 ;
}
