static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & F_3 ( V_2 ) -> V_6 ;
F_4 ( V_4 -> V_7 + V_6 -> V_8 ) ;
}
static void T_1 F_5 ( struct V_9 * V_6 )
{
int V_10 ;
while ( F_4 ( V_11 + V_12 ) ) {
V_10 = F_4 ( V_11 + V_13 ) ;
F_6 ( V_14 , V_10 , V_6 ) ;
} ;
}
static void T_2 F_7 ( void T_3 * V_15 )
{
F_8 ( ~ 0 , V_15 + V_16 ) ;
F_8 ( 0xF , V_15 + V_17 ) ;
F_4 ( V_15 + V_18 ) ;
}
static int T_2 F_9 ( struct V_19 * V_20 ,
struct V_19 * V_21 )
{
unsigned int V_22 = V_23 | V_24 | V_25 ;
struct V_3 * V_4 ;
int V_26 ;
if ( F_10 ( V_11 || V_14 ) )
return - V_27 ;
V_11 = F_11 ( V_20 , 0 ) ;
F_12 ( ! V_11 ) ;
F_8 ( ~ 0 , V_11 + V_28 ) ;
F_8 ( 0 , V_11 + V_29 ) ;
F_13 ( V_11 + V_30 , 0 , V_31 * sizeof( V_32 ) ) ;
F_7 ( V_11 + V_33 ) ;
F_7 ( V_11 + V_34 ) ;
V_14 = F_14 ( V_20 , V_31 ,
& V_35 , NULL ) ;
F_12 ( ! V_14 ) ;
V_26 = F_15 ( V_14 , V_31 , 1 ,
L_1 , V_36 ,
V_22 , 0 , V_37 ) ;
F_12 ( V_26 ) ;
V_4 = F_16 ( V_14 , 0 ) ;
V_4 -> V_7 = V_11 ;
V_4 -> V_38 [ 0 ] . V_39 . V_40 = F_1 ;
V_4 -> V_38 [ 0 ] . V_39 . V_41 = V_42 ;
V_4 -> V_38 [ 0 ] . V_39 . V_43 = V_44 ;
V_4 -> V_38 [ 0 ] . V_6 . V_45 = V_33 + V_46 ;
V_4 -> V_38 [ 0 ] . V_6 . V_47 = V_33 + V_46 ;
V_4 -> V_38 [ 0 ] . V_6 . V_48 = V_33 + V_16 ;
V_4 -> V_38 [ 0 ] . V_6 . V_8 = V_33 + V_18 ;
F_17 ( F_5 ) ;
F_18 ( L_2 ) ;
return 0 ;
}
