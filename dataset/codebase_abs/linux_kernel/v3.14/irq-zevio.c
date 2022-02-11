static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 =
& F_3 ( V_2 -> V_7 , struct V_8 , V_7 ) -> V_6 ;
F_4 ( V_4 -> V_9 + V_6 -> V_10 ) ;
}
static T_1 void T_2 F_5 ( struct V_11 * V_6 )
{
int V_12 ;
while ( F_4 ( V_13 + V_14 ) ) {
V_12 = F_4 ( V_13 + V_15 ) ;
V_12 = F_6 ( V_16 , V_12 ) ;
F_7 ( V_12 , V_6 ) ;
} ;
}
static void T_3 F_8 ( void T_4 * V_17 )
{
F_9 ( ~ 0 , V_17 + V_18 ) ;
F_9 ( 0xF , V_17 + V_19 ) ;
F_4 ( V_17 + V_20 ) ;
}
static int T_3 F_10 ( struct V_21 * V_22 ,
struct V_21 * V_23 )
{
unsigned int V_24 = V_25 | V_26 | V_27 ;
struct V_3 * V_4 ;
int V_28 ;
if ( F_11 ( V_13 || V_16 ) )
return - V_29 ;
V_13 = F_12 ( V_22 , 0 ) ;
F_13 ( ! V_13 ) ;
F_9 ( ~ 0 , V_13 + V_30 ) ;
F_9 ( 0 , V_13 + V_31 ) ;
F_14 ( V_13 + V_32 , 0 , V_33 * sizeof( V_34 ) ) ;
F_8 ( V_13 + V_35 ) ;
F_8 ( V_13 + V_36 ) ;
V_16 = F_15 ( V_22 , V_33 ,
& V_37 , NULL ) ;
F_13 ( ! V_16 ) ;
V_28 = F_16 ( V_16 , V_33 , 1 ,
L_1 , V_38 ,
V_24 , 0 , V_39 ) ;
F_13 ( V_28 ) ;
V_4 = F_17 ( V_16 , 0 ) ;
V_4 -> V_9 = V_13 ;
V_4 -> V_40 [ 0 ] . V_7 . V_41 = F_1 ;
V_4 -> V_40 [ 0 ] . V_7 . V_42 = V_43 ;
V_4 -> V_40 [ 0 ] . V_7 . V_44 = V_45 ;
V_4 -> V_40 [ 0 ] . V_6 . V_46 = V_35 + V_47 ;
V_4 -> V_40 [ 0 ] . V_6 . V_48 = V_35 + V_47 ;
V_4 -> V_40 [ 0 ] . V_6 . V_49 = V_35 + V_18 ;
V_4 -> V_40 [ 0 ] . V_6 . V_10 = V_35 + V_20 ;
F_18 ( F_5 ) ;
F_19 ( L_2 ) ;
return 0 ;
}
