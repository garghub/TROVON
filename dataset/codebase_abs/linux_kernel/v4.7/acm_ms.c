static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( F_2 ( V_2 -> V_6 -> V_7 ) ) {
V_2 -> V_8 = V_9 ;
V_2 -> V_10 |= V_11 ;
}
V_4 = F_3 ( V_12 ) ;
V_13 = F_4 ( V_14 ) ;
if ( F_5 ( V_13 ) )
return F_6 ( V_13 ) ;
V_15 = F_4 ( V_12 ) ;
if ( F_5 ( V_15 ) ) {
V_5 = F_6 ( V_15 ) ;
goto V_16;
}
V_5 = F_7 ( V_2 , V_13 ) ;
if ( V_5 < 0 )
goto V_17;
V_5 = F_7 ( V_2 , V_15 ) ;
if ( V_5 )
goto V_18;
return 0 ;
V_18:
F_8 ( V_2 , V_13 ) ;
V_17:
F_9 ( V_15 ) ;
V_16:
F_9 ( V_13 ) ;
return V_5 ;
}
static int F_10 ( struct V_19 * V_6 )
{
struct V_20 * V_7 = V_6 -> V_7 ;
struct V_3 * V_4 ;
struct V_21 V_22 ;
int V_5 ;
V_14 = F_11 ( L_1 ) ;
if ( F_5 ( V_14 ) )
return F_6 ( V_14 ) ;
V_12 = F_11 ( L_2 ) ;
if ( F_5 ( V_12 ) ) {
V_5 = F_6 ( V_12 ) ;
goto V_23;
}
F_12 ( & V_22 , & V_24 , V_25 ) ;
V_4 = F_3 ( V_12 ) ;
V_4 -> V_26 = true ;
V_5 = F_13 ( V_4 -> V_27 , V_25 ) ;
if ( V_5 )
goto V_28;
V_5 = F_14 ( V_4 -> V_27 , V_6 , V_22 . V_29 ) ;
if ( V_5 )
goto V_30;
F_15 ( V_4 -> V_27 , true ) ;
V_5 = F_16 ( V_4 -> V_27 , & V_22 ) ;
if ( V_5 )
goto V_30;
F_17 ( V_4 -> V_27 , V_22 . V_31 ,
V_22 . V_32 ) ;
V_5 = F_18 ( V_6 , V_33 ) ;
if ( V_5 < 0 )
goto V_34;
V_35 . V_36 = V_33 [ V_37 ] . V_38 ;
V_35 . V_39 = V_33 [ V_40 ] . V_38 ;
if ( F_2 ( V_7 ) && ! V_9 [ 0 ] ) {
struct V_41 * V_42 ;
V_42 = F_19 ( V_7 ) ;
if ( ! V_42 )
goto V_34;
F_20 ( V_7 , V_42 ) ;
V_9 [ 0 ] = V_42 ;
V_9 [ 1 ] = NULL ;
}
V_5 = F_21 ( V_6 , & V_43 , F_1 ) ;
if ( V_5 < 0 )
goto V_44;
F_22 ( V_6 , & V_45 ) ;
F_23 ( & V_7 -> V_46 , L_3 V_47 L_4 ,
V_48 ) ;
return 0 ;
V_44:
F_24 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = NULL ;
V_34:
F_25 ( V_4 -> V_27 ) ;
V_30:
F_26 ( V_4 -> V_27 ) ;
V_28:
F_27 ( V_12 ) ;
V_23:
F_27 ( V_14 ) ;
return V_5 ;
}
static int F_28 ( struct V_19 * V_6 )
{
F_9 ( V_15 ) ;
F_27 ( V_12 ) ;
F_9 ( V_13 ) ;
F_27 ( V_14 ) ;
F_24 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = NULL ;
return 0 ;
}
