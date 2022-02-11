static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 , V_14 , V_15 ;
struct V_16 * V_17 ;
if ( F_2 ( V_2 ) )
return - V_18 ;
V_12 = F_3 ( & V_2 -> V_8 , sizeof( struct V_11 ) ,
V_19 ) ;
V_6 = (struct V_5 * ) V_4 -> V_20 ;
V_12 -> V_6 = V_6 ;
F_4 ( & V_12 -> V_21 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_22 ; V_13 ++ ) {
struct V_23 * V_24 = & V_6 -> V_25 [ V_13 ] ;
struct V_26 * V_27 ;
V_8 = F_5 ( V_28 ) ;
if ( ! V_8 ) {
V_15 = - V_29 ;
goto V_30;
}
V_8 -> V_31 = & V_32 ;
V_10 = F_6 ( V_8 ) ;
F_7 ( V_33 , L_1 , V_6 -> V_34 ) ;
V_14 = F_8 ( V_2 , V_24 -> V_35 ) + V_24 -> V_36 ;
V_17 = F_9 ( & V_2 -> V_8 , V_14 , V_24 -> V_37 ,
L_2 ) ;
if ( ! V_17 ) {
F_10 ( L_3 ,
V_14 , V_14 + V_24 -> V_37 - 1 ) ;
V_15 = - V_38 ;
goto V_30;
}
F_11 ( 0x00 , V_14 + 1 ) ;
F_12 ( V_14 + 1 ) ;
V_8 -> V_39 = V_14 ;
V_8 -> V_40 [ 0 ] = V_41 ;
V_8 -> V_42 = V_2 -> V_42 ;
V_10 -> V_43 = L_4 ;
V_10 -> V_44 = V_6 -> V_45 ;
V_10 -> V_46 = V_46 ;
V_10 -> V_47 = V_47 & 7 ;
V_10 -> V_48 = V_48 & 3 ;
V_10 -> V_49 = V_49 ;
V_10 -> V_50 . V_51 = V_52 ;
if ( F_13 () == 0xFF ) {
F_10 ( L_5 , V_14 ) ;
V_15 = - V_18 ;
goto V_30;
}
if ( F_14 ( V_8 ) ) {
V_15 = - V_18 ;
goto V_30;
}
V_27 = F_3 ( & V_2 -> V_8 , sizeof( struct V_26 ) ,
V_19 ) ;
if ( ! V_27 ) {
F_10 ( L_6 , V_53 ) ;
return - V_29 ;
}
V_27 -> V_54 = V_13 ;
V_27 -> V_55 = V_12 ;
V_27 -> V_8 = V_8 ;
F_15 ( & V_8 -> V_8 , V_27 ) ;
V_15 = F_16 ( V_8 , V_56 ) ;
if ( V_15 )
goto V_30;
F_17 ( & V_27 -> V_57 , & V_12 -> V_21 ) ;
}
F_18 ( V_2 , V_12 ) ;
return 0 ;
V_30:
F_19 ( V_2 ) ;
return V_15 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_26 * V_27 , * V_58 ;
struct V_11 * V_12 ;
V_12 = F_20 ( V_2 ) ;
F_21 (card, tmpcard, &priv->list_dev, list) {
struct V_7 * V_8 = V_27 -> V_8 ;
F_22 ( V_8 ) ;
F_23 ( V_8 -> V_42 , V_8 ) ;
F_24 ( V_8 ) ;
}
}
static int T_1 F_25 ( void )
{
F_26 (D_NORMAL) F_27 ( V_59 ) ;
return F_28 ( & V_60 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_60 ) ;
}
