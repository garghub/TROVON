static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_6 = 0 ;
int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_9 ; V_7 ++ ) {
V_8 = F_2 ( V_4 -> V_10 [ V_7 ] ) ;
if ( V_8 < 0 ) {
F_3 ( V_2 -> V_11 ,
L_1 ,
F_4 ( V_4 -> V_10 [ V_7 ] ) , V_8 ) ;
return V_8 ;
}
V_8 = ! ! V_8 ;
V_6 = ( V_6 << 1 ) | V_8 ;
}
return V_6 ;
}
static void F_5 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_14 ;
int V_15 ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 >= 0 && V_15 != V_2 -> V_16 ) {
F_6 ( V_13 -> V_17 , V_2 -> V_18 , V_15 ) ;
F_7 ( V_13 -> V_17 ) ;
V_2 -> V_16 = V_15 ;
}
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_11 = & V_20 -> V_11 ;
struct V_1 * V_2 ;
struct V_12 * V_13 ;
T_1 V_22 ;
int V_23 ;
V_2 = F_9 ( V_11 , sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
F_10 ( V_11 , L_2 , & V_2 -> V_18 ) ;
V_2 -> V_5 = F_11 ( V_11 , NULL , V_26 ) ;
if ( F_12 ( V_2 -> V_5 ) ) {
F_3 ( V_11 , L_3 ) ;
return F_13 ( V_2 -> V_5 ) ;
}
if ( V_2 -> V_5 -> V_9 < 2 ) {
F_3 ( V_11 , L_4 ) ;
return - V_27 ;
}
if ( F_10 ( V_11 , L_5 , & V_22 ) )
V_22 = ( 1U << V_2 -> V_5 -> V_9 ) - 1 ;
V_2 -> V_11 = V_11 ;
V_13 = F_14 ( V_2 -> V_11 ) ;
if ( ! V_13 )
return - V_25 ;
V_13 -> V_14 = V_2 ;
V_13 -> V_28 = F_5 ;
V_2 -> V_13 = V_13 ;
V_13 -> V_17 -> V_29 = V_20 -> V_29 ;
V_13 -> V_17 -> V_30 . V_31 = V_32 ;
F_15 ( V_13 -> V_17 , V_2 -> V_18 , 0 , V_22 , 0 , 0 ) ;
V_23 = F_16 ( V_13 ) ;
if ( V_23 ) {
F_3 ( V_11 , L_6 ) ;
return V_23 ;
}
F_17 ( V_20 , V_2 ) ;
return 0 ;
}
