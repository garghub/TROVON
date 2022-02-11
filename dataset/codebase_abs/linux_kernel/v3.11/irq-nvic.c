T_1 void T_2
F_1 ( T_3 V_1 , struct V_2 * V_3 )
{
unsigned int V_4 = F_2 ( V_5 , V_1 ) ;
F_3 ( V_4 , V_3 ) ;
}
static void F_4 ( struct V_6 * V_7 )
{
}
static int T_4 F_5 ( struct V_8 * V_9 ,
struct V_8 * V_10 )
{
unsigned int V_11 = V_12 | V_13 | V_14 ;
unsigned int V_15 , V_16 , V_17 , V_18 ;
void T_5 * V_19 ;
V_18 = ( F_6 ( V_20 ) &
V_21 ) + 1 ;
V_19 = F_7 ( V_9 , 0 ) ;
if ( ! V_19 ) {
F_8 ( L_1 ) ;
return - V_22 ;
}
V_15 = V_18 * 32 ;
if ( V_15 > V_23 )
V_15 = V_23 ;
V_5 =
F_9 ( V_9 , V_15 , & V_24 , NULL ) ;
if ( ! V_5 ) {
F_8 ( L_2 ) ;
return - V_22 ;
}
V_17 = F_10 ( V_5 , 32 , 1 ,
L_3 , V_25 ,
V_11 , 0 , V_26 ) ;
if ( V_17 ) {
F_8 ( L_4 ) ;
F_11 ( V_5 ) ;
return V_17 ;
}
for ( V_16 = 0 ; V_16 < V_18 ; ++ V_16 ) {
struct V_27 * V_28 ;
V_28 = F_12 ( V_5 , 32 * V_16 ) ;
V_28 -> V_29 = V_19 + 4 * V_16 ;
V_28 -> V_30 [ 0 ] . V_3 . V_31 = V_32 ;
V_28 -> V_30 [ 0 ] . V_3 . V_33 = V_34 ;
V_28 -> V_30 [ 0 ] . V_35 . V_36 = V_37 ;
V_28 -> V_30 [ 0 ] . V_35 . V_38 = V_39 ;
V_28 -> V_30 [ 0 ] . V_35 . V_40 = F_4 ;
F_13 ( ~ 0 , V_28 -> V_29 + V_34 ) ;
}
for ( V_16 = 0 ; V_16 < V_15 ; V_16 += 4 )
F_13 ( 0 , V_19 + V_41 + V_16 ) ;
return 0 ;
}
