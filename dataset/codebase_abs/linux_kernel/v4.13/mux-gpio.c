static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_4 -> V_7 -> V_8 ; V_6 ++ )
V_4 -> V_9 [ V_6 ] = ( V_3 >> V_6 ) & 1 ;
F_3 ( V_4 -> V_7 -> V_8 ,
V_4 -> V_7 -> V_10 ,
V_4 -> V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = & V_12 -> V_14 ;
struct V_15 * V_15 ;
struct V_4 * V_4 ;
int V_16 ;
T_1 V_17 ;
int V_18 ;
V_16 = F_5 ( V_14 , L_1 ) ;
if ( V_16 < 0 )
return V_16 ;
V_15 = F_6 ( V_14 , 1 , sizeof( * V_4 ) +
V_16 * sizeof( * V_4 -> V_9 ) ) ;
if ( F_7 ( V_15 ) )
return F_8 ( V_15 ) ;
V_4 = F_2 ( V_15 ) ;
V_4 -> V_9 = ( int * ) ( V_4 + 1 ) ;
V_15 -> V_19 = & V_20 ;
V_4 -> V_7 = F_9 ( V_14 , L_1 , V_21 ) ;
if ( F_7 ( V_4 -> V_7 ) ) {
V_18 = F_8 ( V_4 -> V_7 ) ;
if ( V_18 != - V_22 )
F_10 ( V_14 , L_2 ) ;
return V_18 ;
}
F_11 ( V_16 != V_4 -> V_7 -> V_8 ) ;
V_15 -> V_2 -> V_23 = 1 << V_16 ;
V_18 = F_12 ( V_14 , L_3 , ( V_24 * ) & V_17 ) ;
if ( V_18 >= 0 && V_17 != V_25 ) {
if ( V_17 < 0 || V_17 >= V_15 -> V_2 -> V_23 ) {
F_10 ( V_14 , L_4 , V_17 ) ;
return - V_26 ;
}
V_15 -> V_2 -> V_17 = V_17 ;
}
V_18 = F_13 ( V_14 , V_15 ) ;
if ( V_18 < 0 )
return V_18 ;
F_14 ( V_14 , L_5 ,
V_15 -> V_2 -> V_23 ) ;
return 0 ;
}
