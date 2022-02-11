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
V_5 = F_8 ( V_4 -> V_18 ) ;
if ( V_5 )
goto V_19;
V_5 = F_7 ( V_2 , V_15 ) ;
if ( V_5 )
goto V_19;
return 0 ;
V_19:
F_9 ( V_2 , V_13 ) ;
V_17:
F_10 ( V_15 ) ;
V_16:
F_10 ( V_13 ) ;
return V_5 ;
}
static int F_11 ( struct V_20 * V_6 )
{
struct V_21 * V_7 = V_6 -> V_7 ;
struct V_3 * V_4 ;
struct V_22 V_23 ;
int V_5 ;
V_14 = F_12 ( L_1 ) ;
if ( F_5 ( V_14 ) )
return F_6 ( V_14 ) ;
V_12 = F_12 ( L_2 ) ;
if ( F_5 ( V_12 ) ) {
V_5 = F_6 ( V_12 ) ;
goto V_24;
}
F_13 ( & V_23 , & V_25 , V_26 ) ;
V_4 = F_3 ( V_12 ) ;
V_4 -> V_27 = true ;
V_5 = F_14 ( V_4 -> V_18 , V_26 ) ;
if ( V_5 )
goto V_28;
V_5 = F_15 ( V_4 -> V_18 , V_6 , V_23 . V_29 ) ;
if ( V_5 )
goto V_30;
F_16 ( V_4 -> V_18 , true ) ;
V_5 = F_17 ( V_4 -> V_18 , & V_23 ) ;
if ( V_5 )
goto V_30;
F_18 ( V_4 -> V_18 , V_23 . V_31 ,
V_23 . V_32 ) ;
V_5 = F_19 ( V_6 , V_33 ) ;
if ( V_5 < 0 )
goto V_34;
V_35 . V_36 = V_33 [ V_37 ] . V_38 ;
V_35 . V_39 = V_33 [ V_40 ] . V_38 ;
if ( F_2 ( V_7 ) && ! V_9 [ 0 ] ) {
struct V_41 * V_42 ;
V_42 = F_20 ( V_7 ) ;
if ( ! V_42 )
goto V_34;
F_21 ( V_7 , V_42 ) ;
V_9 [ 0 ] = V_42 ;
V_9 [ 1 ] = NULL ;
}
V_5 = F_22 ( V_6 , & V_43 , F_1 ) ;
if ( V_5 < 0 )
goto V_44;
F_23 ( V_6 , & V_45 ) ;
F_24 ( & V_7 -> V_46 , L_3 V_47 L_4 ,
V_48 ) ;
return 0 ;
V_44:
F_25 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = NULL ;
V_34:
F_26 ( V_4 -> V_18 ) ;
V_30:
F_27 ( V_4 -> V_18 ) ;
V_28:
F_28 ( V_12 ) ;
V_24:
F_28 ( V_14 ) ;
return V_5 ;
}
static int F_29 ( struct V_20 * V_6 )
{
F_10 ( V_15 ) ;
F_28 ( V_12 ) ;
F_10 ( V_13 ) ;
F_28 ( V_14 ) ;
F_25 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = NULL ;
return 0 ;
}
