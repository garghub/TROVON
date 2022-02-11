static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 , V_12 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_5 = & V_2 -> V_5 ;
struct V_17 * V_18 ;
F_2 ( & V_2 -> V_5 , L_1 ) ;
if ( ! V_4 ) {
F_3 ( V_5 , L_2 ) ;
return - V_19 ;
}
V_11 = F_4 ( V_2 , 0 ) ;
V_8 = F_5 ( & V_20 , V_5 , F_6 ( V_5 ) ) ;
if ( ! V_8 )
return - V_21 ;
V_10 = F_7 ( V_2 , V_22 , 0 ) ;
if ( ! V_10 ) {
F_3 ( V_5 , L_3 ) ;
V_12 = - V_23 ;
goto V_24;
}
V_8 -> V_25 = V_10 -> V_26 ;
V_8 -> V_27 = F_8 ( V_10 ) ;
V_8 -> V_28 = F_9 ( & V_2 -> V_5 , V_10 ) ;
if ( ! V_8 -> V_28 ) {
F_3 ( V_5 , L_4 ) ;
V_12 = - V_29 ;
goto V_24;
}
V_8 -> V_30 = 1 ;
V_18 = F_10 ( V_8 ) ;
V_15 = (struct V_14 * ) V_18 -> V_15 ;
V_15 -> V_31 = F_11 ( & V_2 -> V_5 , L_5 ) ;
if ( F_12 ( V_15 -> V_31 ) ) {
V_12 = F_13 ( V_15 -> V_31 ) ;
goto V_24;
}
F_14 ( V_15 -> V_31 ) ;
V_15 -> V_32 = F_11 ( & V_2 -> V_5 , L_6 ) ;
if ( F_12 ( V_15 -> V_32 ) ) {
V_12 = F_13 ( V_15 -> V_32 ) ;
goto V_33;
}
F_14 ( V_15 -> V_32 ) ;
V_15 -> V_34 = F_11 ( & V_2 -> V_5 , L_7 ) ;
if ( F_12 ( V_15 -> V_34 ) )
V_15 -> V_34 = NULL ;
if ( V_15 -> V_34 )
F_14 ( V_15 -> V_34 ) ;
if ( V_4 -> V_35 ) {
V_12 = V_4 -> V_35 ( V_2 ) ;
if ( V_12 ) {
F_3 ( V_5 , L_8 ) ;
goto V_36;
}
F_15 ( 10 ) ;
}
V_18 -> V_37 = V_8 -> V_28 + 0x100 ;
V_18 -> V_28 = V_8 -> V_28 + 0x100 +
F_16 ( V_18 , F_17 ( V_18 , & V_18 -> V_37 -> V_38 ) ) ;
F_18 ( V_18 , V_4 -> V_39 , & V_18 -> V_28 -> V_40 [ 0 ] ) ;
F_19 ( 10 ) ;
if ( V_4 -> V_41 ) {
V_4 -> V_41 -> V_42 = V_8 -> V_28 + V_43 ;
V_12 = F_20 ( V_4 -> V_41 ) ;
if ( V_12 ) {
F_3 ( V_5 , L_9 ) ;
V_12 = - V_23 ;
goto V_44;
}
V_12 = F_21 ( V_4 -> V_41 -> V_41 , 1 ) ;
if ( V_12 ) {
F_3 ( V_5 , L_10 ) ;
goto V_44;
}
}
F_22 ( V_2 , V_8 ) ;
V_12 = F_23 ( V_8 , V_11 , V_45 ) ;
if ( V_12 )
goto V_44;
if ( V_4 -> V_41 ) {
if ( F_24 () || F_25 () ) {
V_13 = F_26 ( V_4 -> V_41 ,
V_46 ) ;
V_13 |= V_47 ;
V_12 = F_27 ( V_4 -> V_41 , V_13 ,
V_46 ) ;
if ( V_12 ) {
F_3 ( V_5 , L_11 ) ;
goto V_44;
}
}
}
return 0 ;
V_44:
if ( V_4 && V_4 -> exit )
V_4 -> exit ( V_2 ) ;
V_36:
if ( V_15 -> V_34 )
F_28 ( V_15 -> V_34 ) ;
F_28 ( V_15 -> V_32 ) ;
V_33:
F_28 ( V_15 -> V_31 ) ;
V_24:
F_29 ( V_8 ) ;
return V_12 ;
}
static int T_1 F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 = F_31 ( V_2 ) ;
struct V_17 * V_18 = F_10 ( V_8 ) ;
struct V_14 * V_15 = (struct V_14 * ) V_18 -> V_15 ;
F_32 ( V_8 ) ;
if ( V_4 && V_4 -> exit )
V_4 -> exit ( V_2 ) ;
if ( V_4 -> V_41 )
F_33 ( V_4 -> V_41 ) ;
F_28 ( V_15 -> V_31 ) ;
F_28 ( V_15 -> V_32 ) ;
if ( V_15 -> V_34 )
F_28 ( V_15 -> V_34 ) ;
F_29 ( V_8 ) ;
F_22 ( V_2 , NULL ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_31 ( V_2 ) ;
if ( V_8 -> V_48 -> V_49 )
V_8 -> V_48 -> V_49 ( V_8 ) ;
}
static int T_2 F_35 ( void )
{
if ( F_36 () )
return - V_23 ;
F_37 ( L_12 V_50 L_13 , V_51 ) ;
F_38 ( & V_20 , & V_52 ) ;
return F_39 ( & V_53 ) ;
}
static void T_1 F_40 ( void )
{
F_41 ( & V_53 ) ;
}
