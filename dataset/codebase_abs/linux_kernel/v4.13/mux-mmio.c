static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * * V_5 = F_2 ( V_2 -> V_6 ) ;
return F_3 ( V_5 [ F_4 ( V_2 ) ] , V_3 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_4 * * V_5 ;
struct V_14 * V_14 ;
struct V_15 * V_15 ;
int V_16 ;
int V_17 ;
int V_18 ;
V_15 = F_6 ( V_12 -> V_19 ) ;
if ( F_7 ( V_15 ) ) {
V_17 = F_8 ( V_15 ) ;
F_9 ( V_10 , L_1 , V_17 ) ;
return V_17 ;
}
V_17 = F_10 ( V_12 , L_2 ) ;
if ( V_17 == 0 || V_17 % 2 )
V_17 = - V_20 ;
if ( V_17 < 0 ) {
F_9 ( V_10 , L_3 ,
V_17 ) ;
return V_17 ;
}
V_16 = V_17 / 2 ;
V_14 = F_11 ( V_10 , V_16 , V_16 *
sizeof( * V_5 ) ) ;
if ( F_7 ( V_14 ) )
return F_8 ( V_14 ) ;
V_5 = F_2 ( V_14 ) ;
for ( V_18 = 0 ; V_18 < V_16 ; V_18 ++ ) {
struct V_1 * V_2 = & V_14 -> V_2 [ V_18 ] ;
struct V_21 V_22 ;
T_1 V_23 = V_24 ;
T_2 V_25 , V_26 ;
int V_27 ;
V_17 = F_12 ( V_12 , L_2 ,
2 * V_18 , & V_25 ) ;
if ( ! V_17 )
V_17 = F_12 ( V_12 , L_2 ,
2 * V_18 + 1 , & V_26 ) ;
if ( V_17 < 0 ) {
F_9 ( V_10 , L_4 ,
V_18 , V_17 ) ;
return V_17 ;
}
V_22 . V_25 = V_25 ;
V_22 . V_28 = F_13 ( V_26 ) - 1 ;
V_22 . V_29 = F_14 ( V_26 ) - 1 ;
if ( V_26 != F_15 ( V_22 . V_28 , V_22 . V_29 ) ) {
F_9 ( V_10 , L_5 ,
V_18 , V_26 ) ;
return - V_20 ;
}
V_5 [ V_18 ] = F_16 ( V_10 , V_15 , V_22 ) ;
if ( F_7 ( V_5 [ V_18 ] ) ) {
V_17 = F_8 ( V_5 [ V_18 ] ) ;
F_9 ( V_10 , L_6 ,
V_18 , V_17 ) ;
return V_17 ;
}
V_27 = 1 + V_22 . V_28 - V_22 . V_29 ;
V_2 -> V_30 = 1 << V_27 ;
F_12 ( V_12 , L_7 , V_18 ,
( T_2 * ) & V_23 ) ;
if ( V_23 != V_24 ) {
if ( V_23 < 0 || V_23 >= V_2 -> V_30 ) {
F_9 ( V_10 , L_8 ,
V_18 , V_23 ) ;
return - V_20 ;
}
V_2 -> V_23 = V_23 ;
}
}
V_14 -> V_31 = & V_32 ;
return F_17 ( V_10 , V_14 ) ;
}
