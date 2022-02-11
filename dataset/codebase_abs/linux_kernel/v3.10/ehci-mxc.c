static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 , V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_5 = & V_2 -> V_5 ;
struct V_16 * V_17 ;
if ( ! V_4 ) {
F_2 ( V_5 , L_1 ) ;
return - V_18 ;
}
V_11 = F_3 ( V_2 , 0 ) ;
V_8 = F_4 ( & V_19 , V_5 , F_5 ( V_5 ) ) ;
if ( ! V_8 )
return - V_20 ;
V_10 = F_6 ( V_2 , V_21 , 0 ) ;
if ( ! V_10 ) {
F_2 ( V_5 , L_2 ) ;
V_12 = - V_22 ;
goto V_23;
}
V_8 -> V_24 = V_10 -> V_25 ;
V_8 -> V_26 = F_7 ( V_10 ) ;
V_8 -> V_27 = F_8 ( & V_2 -> V_5 , V_10 ) ;
if ( F_9 ( V_8 -> V_27 ) ) {
V_12 = F_10 ( V_8 -> V_27 ) ;
goto V_23;
}
V_8 -> V_28 = 1 ;
V_17 = F_11 ( V_8 ) ;
V_14 = (struct V_13 * ) V_17 -> V_14 ;
V_14 -> V_29 = F_12 ( & V_2 -> V_5 , L_3 ) ;
if ( F_9 ( V_14 -> V_29 ) ) {
V_12 = F_10 ( V_14 -> V_29 ) ;
goto V_23;
}
F_13 ( V_14 -> V_29 ) ;
V_14 -> V_30 = F_12 ( & V_2 -> V_5 , L_4 ) ;
if ( F_9 ( V_14 -> V_30 ) ) {
V_12 = F_10 ( V_14 -> V_30 ) ;
goto V_31;
}
F_13 ( V_14 -> V_30 ) ;
V_14 -> V_32 = F_12 ( & V_2 -> V_5 , L_5 ) ;
if ( F_9 ( V_14 -> V_32 ) )
V_14 -> V_32 = NULL ;
if ( V_14 -> V_32 )
F_13 ( V_14 -> V_32 ) ;
if ( V_4 -> V_33 ) {
V_12 = V_4 -> V_33 ( V_2 ) ;
if ( V_12 ) {
F_2 ( V_5 , L_6 ) ;
goto V_34;
}
F_14 ( 10 ) ;
}
V_17 -> V_35 = V_8 -> V_27 + 0x100 ;
V_17 -> V_27 = V_8 -> V_27 + 0x100 +
F_15 ( V_17 , F_16 ( V_17 , & V_17 -> V_35 -> V_36 ) ) ;
F_17 ( V_17 , V_4 -> V_37 , & V_17 -> V_27 -> V_38 [ 0 ] ) ;
F_18 ( 10 ) ;
if ( V_4 -> V_39 ) {
V_4 -> V_39 -> V_40 = V_8 -> V_27 + V_41 ;
V_12 = F_19 ( V_4 -> V_39 ) ;
if ( V_12 ) {
F_2 ( V_5 , L_7 ) ;
V_12 = - V_22 ;
goto V_42;
}
V_12 = F_20 ( V_4 -> V_39 -> V_39 , 1 ) ;
if ( V_12 ) {
F_2 ( V_5 , L_8 ) ;
goto V_42;
}
}
F_21 ( V_2 , V_8 ) ;
V_12 = F_22 ( V_8 , V_11 , V_43 ) ;
if ( V_12 )
goto V_42;
return 0 ;
V_42:
if ( V_4 && V_4 -> exit )
V_4 -> exit ( V_2 ) ;
V_34:
if ( V_14 -> V_32 )
F_23 ( V_14 -> V_32 ) ;
F_23 ( V_14 -> V_30 ) ;
V_31:
F_23 ( V_14 -> V_29 ) ;
V_23:
F_24 ( V_8 ) ;
return V_12 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 = F_26 ( V_2 ) ;
struct V_16 * V_17 = F_11 ( V_8 ) ;
struct V_13 * V_14 = (struct V_13 * ) V_17 -> V_14 ;
F_27 ( V_8 ) ;
if ( V_4 && V_4 -> exit )
V_4 -> exit ( V_2 ) ;
if ( V_4 -> V_39 )
F_28 ( V_4 -> V_39 ) ;
F_23 ( V_14 -> V_29 ) ;
F_23 ( V_14 -> V_30 ) ;
if ( V_14 -> V_32 )
F_23 ( V_14 -> V_32 ) ;
F_24 ( V_8 ) ;
F_21 ( V_2 , NULL ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_26 ( V_2 ) ;
if ( V_8 -> V_44 -> V_45 )
V_8 -> V_44 -> V_45 ( V_8 ) ;
}
static int T_1 F_30 ( void )
{
if ( F_31 () )
return - V_22 ;
F_32 ( L_9 V_46 L_10 , V_47 ) ;
F_33 ( & V_19 , & V_48 ) ;
return F_34 ( & V_49 ) ;
}
static void T_2 F_35 ( void )
{
F_36 ( & V_49 ) ;
}
