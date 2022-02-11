static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 ;
bool V_4 ;
V_3 = F_2 ( 1 ) ;
if ( ! V_3 )
return;
V_3 -> V_5 [ 0 ] . V_6 = F_3 ( V_1 , 0 ) ;
V_3 -> V_5 [ 0 ] . V_7 = F_4 ( V_1 , 0 ) ;
V_4 = V_1 -> V_8 [ V_9 ] . V_10
& V_11 ;
F_5 ( V_3 , L_1 , V_4 ) ;
F_6 ( V_3 ) ;
}
int F_7 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
struct V_16 * V_17 ;
int V_18 ;
V_17 = F_8 ( V_13 , & V_15 -> V_17 ) ;
if ( ! V_17 )
return - V_19 ;
V_17 -> V_20 = V_15 ;
V_15 -> V_21 = V_17 ;
if ( strcmp ( V_15 -> V_17 . V_22 -> V_23 -> V_24 , L_2 ) == 0 ) {
struct V_1 * V_25 = F_9 ( V_15 -> V_17 . V_22 ) ;
bool V_26 = ( V_25 -> V_27 >> 8 ) == V_28 ;
F_10 ( L_3 ,
V_26 ? L_4 : L_5 ) ;
V_17 -> V_25 = V_25 ;
if ( V_26 )
F_1 ( V_25 ) ;
}
V_18 = F_11 ( V_17 , 0 ) ;
if ( V_18 )
goto V_29;
F_10 ( L_6 , V_13 -> V_24 ,
V_13 -> V_30 , V_13 -> V_31 , V_13 -> V_32 ,
V_13 -> V_33 , V_17 -> V_4 -> V_34 ) ;
return 0 ;
V_29:
F_12 ( V_17 ) ;
return V_18 ;
}
