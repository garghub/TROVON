static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_10 = F_3 ( L_1 ) ;
if ( F_4 ( V_10 ) ) {
V_3 = F_5 ( V_10 ) ;
goto V_11;
}
V_12 = F_6 ( V_10 ) ;
if ( F_4 ( V_12 ) ) {
V_3 = F_5 ( V_12 ) ;
goto V_13;
}
V_3 = F_7 ( V_2 , V_12 ) ;
if ( V_3 )
goto V_14;
V_15 = F_3 ( L_2 ) ;
if ( F_4 ( V_15 ) ) {
V_3 = F_5 ( V_15 ) ;
goto V_16;
}
V_17 = F_6 ( V_15 ) ;
if ( F_4 ( V_17 ) ) {
V_3 = F_5 ( V_17 ) ;
goto V_18;
}
V_3 = F_7 ( V_2 , V_17 ) ;
if ( V_3 )
goto V_19;
return 0 ;
V_19:
F_8 ( V_17 ) ;
V_18:
F_9 ( V_15 ) ;
V_16:
F_10 ( V_2 , V_12 ) ;
V_14:
F_8 ( V_12 ) ;
V_13:
F_9 ( V_10 ) ;
V_11:
return V_3 ;
}
static int T_1 F_11 ( struct V_20 * V_4 )
{
struct V_21 * V_5 = V_4 -> V_5 ;
struct V_22 * V_23 ;
int V_3 ;
if ( ! F_12 ( V_4 -> V_5 ) ) {
F_13 ( & V_5 -> V_24 , L_3 ,
V_5 -> V_25 ) ;
return - V_26 ;
}
V_10 = F_3 ( L_1 ) ;
if ( F_4 ( V_10 ) )
return F_5 ( V_10 ) ;
V_23 = F_14 ( V_10 , struct V_22 , V_27 ) ;
F_15 ( V_23 -> V_28 , V_29 ) ;
if ( ! F_16 ( V_23 -> V_28 , V_30 ) )
F_17 ( L_4 , V_30 ) ;
if ( ! F_18 ( V_23 -> V_28 , V_31 ) )
F_17 ( L_5 , V_31 ) ;
V_15 = F_3 ( L_2 ) ;
if ( F_4 ( V_15 ) ) {
V_3 = F_5 ( V_15 ) ;
goto V_32;
}
V_3 = F_19 ( V_4 , V_33 ) ;
if ( V_3 < 0 )
goto V_34;
V_35 . V_36 = V_33 [ V_37 ] . V_38 ;
V_35 . V_39 = V_33 [ V_40 ] . V_38 ;
V_3 = F_20 ( V_4 , & V_41 , F_1 ) ;
if ( V_3 < 0 )
goto V_34;
F_21 ( V_4 , & V_42 ) ;
F_22 ( & V_5 -> V_24 , L_6 V_43 L_7 ,
V_44 ) ;
return 0 ;
V_34:
F_9 ( V_15 ) ;
V_32:
F_9 ( V_10 ) ;
return V_3 ;
}
static int T_2 F_23 ( struct V_20 * V_4 )
{
F_8 ( V_17 ) ;
F_9 ( V_15 ) ;
if ( ! F_24 ( V_12 ) )
F_8 ( V_12 ) ;
if ( ! F_24 ( V_10 ) )
F_9 ( V_10 ) ;
return 0 ;
}
static int T_1 F_25 ( void )
{
return F_26 ( & V_45 ) ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_45 ) ;
}
