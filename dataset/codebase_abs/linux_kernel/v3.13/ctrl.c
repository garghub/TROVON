static int
F_1 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
struct V_8 * args = V_4 ;
if ( V_5 < sizeof( * args ) )
return - V_9 ;
if ( V_7 ) {
args -> V_10 = V_7 -> V_11 ;
args -> V_12 = V_7 -> V_12 ;
args -> V_13 = V_7 -> V_13 ;
} else {
args -> V_10 = 0 ;
args -> V_12 = V_14 ;
args -> V_13 = V_15 ;
}
return 0 ;
}
static int
F_2 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
struct V_16 * args = V_4 ;
struct V_17 * V_18 ;
struct V_19 * V_13 ;
struct V_20 * V_21 ;
int V_22 = 0 , V_23 = - 1 ;
T_1 V_24 , V_25 ;
if ( ( V_5 < sizeof( * args ) ) || ! V_7 ||
( args -> V_26 >= 0 && args -> V_26 >= V_7 -> V_11 ) )
return - V_9 ;
V_18 = V_7 -> V_27 ;
while ( V_18 -> V_28 != V_29 ) {
if ( V_18 -> V_30 && ++ V_23 == args -> V_31 )
break;
V_18 ++ ;
}
if ( V_18 -> V_28 == V_29 )
return - V_9 ;
if ( args -> V_26 != V_32 ) {
F_3 (pstate, &clk->states, head) {
if ( V_22 ++ == args -> V_26 )
break;
}
V_24 = V_13 -> V_33 . V_18 [ V_18 -> V_28 ] ;
V_25 = V_24 ;
F_3 (cstate, &pstate->list, head) {
V_24 = F_4 ( V_24 , V_21 -> V_18 [ V_18 -> V_28 ] ) ;
V_25 = F_5 ( V_25 , V_21 -> V_18 [ V_18 -> V_28 ] ) ;
}
args -> V_26 = V_13 -> V_13 ;
} else {
V_24 = F_5 ( V_7 -> V_34 ( V_7 , V_18 -> V_28 ) , 0 ) ;
V_25 = V_24 ;
}
snprintf ( args -> V_28 , sizeof( args -> V_28 ) , L_1 , V_18 -> V_30 ) ;
snprintf ( args -> V_35 , sizeof( args -> V_35 ) , L_2 ) ;
args -> F_4 = V_24 / V_18 -> V_36 ;
args -> F_5 = V_25 / V_18 -> V_36 ;
args -> V_31 = 0 ;
while ( ( ++ V_18 ) -> V_28 != V_29 ) {
if ( V_18 -> V_30 ) {
args -> V_31 = ++ V_23 ;
break;
}
}
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
struct V_37 * args = V_4 ;
if ( V_5 < sizeof( * args ) || ! V_7 )
return - V_9 ;
return F_7 ( V_7 , args -> V_26 ) ;
}
