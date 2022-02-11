static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_10 = F_3 ( V_11 ) ;
if ( F_4 ( V_10 ) ) {
V_3 = F_5 ( V_10 ) ;
goto V_12;
}
V_3 = F_6 ( V_2 , V_10 ) ;
if ( V_3 )
goto V_13;
V_14 = F_3 ( V_15 ) ;
if ( F_4 ( V_14 ) ) {
V_3 = F_5 ( V_14 ) ;
goto V_16;
}
V_3 = F_6 ( V_2 , V_14 ) ;
if ( V_3 )
goto V_17;
return 0 ;
V_17:
F_7 ( V_14 ) ;
V_16:
F_8 ( V_2 , V_10 ) ;
V_13:
F_7 ( V_10 ) ;
V_12:
return V_3 ;
}
static int F_9 ( struct V_18 * V_4 )
{
struct V_19 * V_5 = V_4 -> V_5 ;
struct V_20 * V_21 ;
int V_3 ;
if ( ! F_10 ( V_4 -> V_5 ) ) {
F_11 ( & V_5 -> V_22 , L_1 ,
V_5 -> V_23 ) ;
return - V_24 ;
}
V_11 = F_12 ( L_2 ) ;
if ( F_4 ( V_11 ) )
return F_5 ( V_11 ) ;
V_21 = F_13 ( V_11 , struct V_20 , V_25 ) ;
F_14 ( V_21 -> V_26 , V_27 ) ;
if ( ! F_15 ( V_21 -> V_26 , V_28 ) )
F_16 ( L_3 , V_28 ) ;
if ( ! F_17 ( V_21 -> V_26 , V_29 ) )
F_16 ( L_4 , V_29 ) ;
V_15 = F_12 ( L_5 ) ;
if ( F_4 ( V_15 ) ) {
V_3 = F_5 ( V_15 ) ;
goto V_30;
}
V_3 = F_18 ( V_4 , V_31 ) ;
if ( V_3 < 0 )
goto V_32;
V_33 . V_34 = V_31 [ V_35 ] . V_36 ;
V_33 . V_37 = V_31 [ V_38 ] . V_36 ;
if ( F_2 ( V_5 ) && ! V_7 [ 0 ] ) {
struct V_39 * V_40 ;
V_40 = F_19 ( V_5 ) ;
if ( ! V_40 )
goto V_32;
F_20 ( V_5 , V_40 ) ;
V_7 [ 0 ] = V_40 ;
V_7 [ 1 ] = NULL ;
}
V_3 = F_21 ( V_4 , & V_41 , F_1 ) ;
if ( V_3 < 0 )
goto V_42;
F_22 ( V_4 , & V_43 ) ;
F_23 ( & V_5 -> V_22 , L_6 V_44 L_7 ,
V_45 ) ;
return 0 ;
V_42:
F_24 ( V_7 [ 0 ] ) ;
V_7 [ 0 ] = NULL ;
V_32:
F_25 ( V_15 ) ;
V_30:
F_25 ( V_11 ) ;
return V_3 ;
}
static int F_26 ( struct V_18 * V_4 )
{
F_7 ( V_14 ) ;
F_25 ( V_15 ) ;
if ( ! F_27 ( V_10 ) )
F_7 ( V_10 ) ;
if ( ! F_27 ( V_11 ) )
F_25 ( V_11 ) ;
F_24 ( V_7 [ 0 ] ) ;
V_7 [ 0 ] = NULL ;
return 0 ;
}
