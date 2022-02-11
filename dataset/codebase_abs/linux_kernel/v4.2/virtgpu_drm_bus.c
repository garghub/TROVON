int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 ) {
return F_2 ( V_2 , V_4 ) ;
}
return 0 ;
}
static void F_3 ( struct V_5 * V_5 )
{
struct V_7 * V_8 ;
bool V_9 ;
V_8 = F_4 ( 1 ) ;
if ( ! V_8 )
return;
V_8 -> V_10 [ 0 ] . V_11 = F_5 ( V_5 , 0 ) ;
V_8 -> V_10 [ 0 ] . V_12 = F_6 ( V_5 , 0 ) ;
V_9 = V_5 -> V_13 [ V_14 ] . V_15
& V_16 ;
F_7 ( V_8 , L_1 , V_9 ) ;
F_8 ( V_8 ) ;
}
int F_9 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_1 * V_2 ;
int V_21 ;
V_2 = F_10 ( V_18 , & V_20 -> V_2 ) ;
if ( ! V_2 )
return - V_22 ;
V_2 -> V_23 = V_20 ;
V_20 -> V_24 = V_2 ;
if ( strcmp ( V_20 -> V_2 . V_25 -> V_26 -> V_27 , L_2 ) == 0 ) {
struct V_5 * V_6 = F_11 ( V_20 -> V_2 . V_25 ) ;
bool V_28 = ( V_6 -> V_29 >> 8 ) == V_30 ;
F_12 ( L_3 ,
V_28 ? L_4 : L_5 ) ;
V_2 -> V_6 = V_6 ;
if ( V_28 )
F_3 ( V_6 ) ;
}
V_21 = F_13 ( V_2 , 0 ) ;
if ( V_21 )
goto V_31;
F_12 ( L_6 , V_18 -> V_27 ,
V_18 -> V_32 , V_18 -> V_33 , V_18 -> V_34 ,
V_18 -> V_35 , V_2 -> V_9 -> V_36 ) ;
return 0 ;
V_31:
F_14 ( V_2 ) ;
return V_21 ;
}
