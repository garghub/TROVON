T_1 void T_2
F_1 ( T_3 V_1 , struct V_2 * V_3 )
{
unsigned int V_4 = F_2 ( V_5 , V_1 ) ;
F_3 ( V_4 , V_3 ) ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
unsigned long * V_1 , unsigned int * type )
{
if ( F_5 ( V_9 -> V_10 < 1 ) )
return - V_11 ;
* V_1 = V_9 -> V_12 [ 0 ] ;
* type = V_13 ;
return 0 ;
}
static int F_6 ( struct V_6 * V_14 , unsigned int V_15 ,
unsigned int V_16 , void * V_17 )
{
int V_18 , V_19 ;
T_3 V_1 ;
unsigned int type = V_13 ;
struct V_8 * V_9 = V_17 ;
V_19 = F_4 ( V_14 , V_9 , & V_1 , & type ) ;
if ( V_19 )
return V_19 ;
for ( V_18 = 0 ; V_18 < V_16 ; V_18 ++ )
F_7 ( V_14 , V_15 + V_18 , V_1 + V_18 ) ;
return 0 ;
}
static int T_4 F_8 ( struct V_20 * V_21 ,
struct V_20 * V_22 )
{
unsigned int V_23 = V_24 | V_25 | V_26 ;
unsigned int V_27 , V_18 , V_19 , V_28 ;
void T_5 * V_29 ;
V_28 = ( F_9 ( V_30 ) &
V_31 ) + 1 ;
V_29 = F_10 ( V_21 , 0 ) ;
if ( ! V_29 ) {
F_11 ( L_1 ) ;
return - V_32 ;
}
V_27 = V_28 * 32 ;
if ( V_27 > V_33 )
V_27 = V_33 ;
V_5 =
F_12 ( V_21 , V_27 , & V_34 , NULL ) ;
if ( ! V_5 ) {
F_11 ( L_2 ) ;
return - V_32 ;
}
V_19 = F_13 ( V_5 , 32 , 1 ,
L_3 , V_35 ,
V_23 , 0 , V_36 ) ;
if ( V_19 ) {
F_11 ( L_4 ) ;
F_14 ( V_5 ) ;
return V_19 ;
}
for ( V_18 = 0 ; V_18 < V_28 ; ++ V_18 ) {
struct V_37 * V_38 ;
V_38 = F_15 ( V_5 , 32 * V_18 ) ;
V_38 -> V_39 = V_29 + 4 * V_18 ;
V_38 -> V_40 [ 0 ] . V_3 . V_41 = V_42 ;
V_38 -> V_40 [ 0 ] . V_3 . V_43 = V_44 ;
V_38 -> V_40 [ 0 ] . V_45 . V_46 = V_47 ;
V_38 -> V_40 [ 0 ] . V_45 . V_48 = V_49 ;
V_38 -> V_40 [ 0 ] . V_45 . V_50 = V_51 ;
F_16 ( ~ 0 , V_38 -> V_39 + V_44 ) ;
}
for ( V_18 = 0 ; V_18 < V_27 ; V_18 += 4 )
F_16 ( 0 , V_29 + V_52 + V_18 ) ;
return 0 ;
}
