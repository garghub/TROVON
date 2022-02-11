T_1 void T_2
F_1 ( T_3 V_1 , struct V_2 * V_3 )
{
unsigned int V_4 = F_2 ( V_5 , V_1 ) ;
F_3 ( V_4 , V_3 ) ;
}
static int T_4 F_4 ( struct V_6 * V_7 ,
struct V_6 * V_8 )
{
unsigned int V_9 = V_10 | V_11 | V_12 ;
unsigned int V_13 , V_14 , V_15 , V_16 ;
void T_5 * V_17 ;
V_16 = ( F_5 ( V_18 ) &
V_19 ) + 1 ;
V_17 = F_6 ( V_7 , 0 ) ;
if ( ! V_17 ) {
F_7 ( L_1 ) ;
return - V_20 ;
}
V_13 = V_16 * 32 ;
if ( V_13 > V_21 )
V_13 = V_21 ;
V_5 =
F_8 ( V_7 , V_13 , & V_22 , NULL ) ;
if ( ! V_5 ) {
F_7 ( L_2 ) ;
return - V_20 ;
}
V_15 = F_9 ( V_5 , 32 , 1 ,
L_3 , V_23 ,
V_9 , 0 , V_24 ) ;
if ( V_15 ) {
F_7 ( L_4 ) ;
F_10 ( V_5 ) ;
return V_15 ;
}
for ( V_14 = 0 ; V_14 < V_16 ; ++ V_14 ) {
struct V_25 * V_26 ;
V_26 = F_11 ( V_5 , 32 * V_14 ) ;
V_26 -> V_27 = V_17 + 4 * V_14 ;
V_26 -> V_28 [ 0 ] . V_3 . V_29 = V_30 ;
V_26 -> V_28 [ 0 ] . V_3 . V_31 = V_32 ;
V_26 -> V_28 [ 0 ] . V_33 . V_34 = V_35 ;
V_26 -> V_28 [ 0 ] . V_33 . V_36 = V_37 ;
V_26 -> V_28 [ 0 ] . V_33 . V_38 = V_39 ;
F_12 ( ~ 0 , V_26 -> V_27 + V_32 ) ;
}
for ( V_14 = 0 ; V_14 < V_13 ; V_14 += 4 )
F_12 ( 0 , V_17 + V_40 + V_14 ) ;
return 0 ;
}
