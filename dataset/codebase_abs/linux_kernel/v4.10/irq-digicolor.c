static void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 -> V_6 ;
struct V_7 * V_6 = V_4 -> V_6 [ 0 ] ;
T_2 V_8 , V_9 ;
do {
V_8 = F_2 ( V_6 , V_10 ) ;
if ( V_8 ) {
V_9 = F_3 ( V_8 ) - 1 ;
} else {
V_8 = F_2 ( V_6 , V_11 ) ;
if ( V_8 )
V_9 = F_3 ( V_8 ) - 1 + 32 ;
else
return;
}
F_4 ( V_5 , V_9 , V_2 ) ;
} while ( 1 );
}
static void T_3 F_5 ( void T_4 * V_12 , unsigned V_13 ,
unsigned V_14 , unsigned V_15 )
{
struct V_7 * V_6 ;
V_6 = F_6 ( V_5 , V_13 ) ;
V_6 -> V_12 = V_12 ;
V_6 -> V_16 [ 0 ] . V_2 . V_17 = V_15 ;
V_6 -> V_16 [ 0 ] . V_2 . V_18 = V_14 ;
V_6 -> V_16 [ 0 ] . V_19 . V_20 = V_21 ;
V_6 -> V_16 [ 0 ] . V_19 . V_22 = V_23 ;
V_6 -> V_16 [ 0 ] . V_19 . V_24 = V_25 ;
}
static int T_3 F_7 ( struct V_26 * V_27 ,
struct V_26 * V_28 )
{
static void T_4 * V_12 ;
unsigned int V_29 = V_30 | V_31 | V_32 ;
struct V_33 * V_34 ;
int V_35 ;
V_12 = F_8 ( V_27 , 0 ) ;
if ( ! V_12 ) {
F_9 ( L_1 , V_27 -> V_36 ) ;
return - V_37 ;
}
F_10 ( 0 , V_12 + V_38 ) ;
F_10 ( 0 , V_12 + V_39 ) ;
V_34 = F_11 ( V_27 , L_2 ) ;
if ( F_12 ( V_34 ) ) {
F_9 ( L_3 , V_27 -> V_36 ) ;
return F_13 ( V_34 ) ;
}
F_14 ( V_34 , V_40 , 1 ) ;
V_5 =
F_15 ( V_27 , 64 , & V_41 , NULL ) ;
if ( ! V_5 ) {
F_9 ( L_4 , V_27 -> V_36 ) ;
return - V_42 ;
}
V_35 = F_16 ( V_5 , 32 , 1 ,
L_5 , V_43 ,
V_29 , 0 , 0 ) ;
if ( V_35 ) {
F_9 ( L_6 , V_27 -> V_36 ) ;
return V_35 ;
}
F_5 ( V_12 , 0 , V_38 , V_44 ) ;
F_5 ( V_12 , 32 , V_39 , V_45 ) ;
F_17 ( F_1 ) ;
return 0 ;
}
