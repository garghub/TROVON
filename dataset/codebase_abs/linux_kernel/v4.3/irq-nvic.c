T_1 void T_2
F_1 ( T_3 V_1 , struct V_2 * V_3 )
{
unsigned int V_4 = F_2 ( V_5 , V_1 ) ;
F_3 ( V_4 , V_3 ) ;
}
static int F_4 ( struct V_6 * V_7 , unsigned int V_8 ,
unsigned int V_9 , void * V_10 )
{
int V_11 , V_12 ;
T_3 V_1 ;
unsigned int type = V_13 ;
struct V_14 * V_15 = V_10 ;
V_12 = F_5 ( V_7 , V_15 -> V_16 , V_15 -> args ,
V_15 -> V_17 , & V_1 , & type ) ;
if ( V_12 )
return V_12 ;
for ( V_11 = 0 ; V_11 < V_9 ; V_11 ++ )
F_6 ( V_7 , V_8 + V_11 , V_1 + V_11 ) ;
return 0 ;
}
static int T_4 F_7 ( struct V_18 * V_19 ,
struct V_18 * V_20 )
{
unsigned int V_21 = V_22 | V_23 | V_24 ;
unsigned int V_25 , V_11 , V_12 , V_26 ;
void T_5 * V_27 ;
V_26 = ( F_8 ( V_28 ) &
V_29 ) + 1 ;
V_27 = F_9 ( V_19 , 0 ) ;
if ( ! V_27 ) {
F_10 ( L_1 ) ;
return - V_30 ;
}
V_25 = V_26 * 32 ;
if ( V_25 > V_31 )
V_25 = V_31 ;
V_5 =
F_11 ( V_19 , V_25 , & V_32 , NULL ) ;
if ( ! V_5 ) {
F_10 ( L_2 ) ;
return - V_30 ;
}
V_12 = F_12 ( V_5 , 32 , 1 ,
L_3 , V_33 ,
V_21 , 0 , V_34 ) ;
if ( V_12 ) {
F_10 ( L_4 ) ;
F_13 ( V_5 ) ;
return V_12 ;
}
for ( V_11 = 0 ; V_11 < V_26 ; ++ V_11 ) {
struct V_35 * V_36 ;
V_36 = F_14 ( V_5 , 32 * V_11 ) ;
V_36 -> V_37 = V_27 + 4 * V_11 ;
V_36 -> V_38 [ 0 ] . V_3 . V_39 = V_40 ;
V_36 -> V_38 [ 0 ] . V_3 . V_41 = V_42 ;
V_36 -> V_38 [ 0 ] . V_43 . V_44 = V_45 ;
V_36 -> V_38 [ 0 ] . V_43 . V_46 = V_47 ;
V_36 -> V_38 [ 0 ] . V_43 . V_48 = V_49 ;
F_15 ( ~ 0 , V_36 -> V_37 + V_42 ) ;
}
for ( V_11 = 0 ; V_11 < V_25 ; V_11 += 4 )
F_15 ( 0 , V_27 + V_50 + V_11 ) ;
return 0 ;
}
