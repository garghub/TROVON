static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( F_2 ( V_2 -> V_6 -> V_7 ) ) {
V_2 -> V_8 = V_9 ;
V_2 -> V_10 |= V_11 ;
}
V_12 = F_3 ( L_1 ) ;
if ( F_4 ( V_12 ) )
return F_5 ( V_12 ) ;
V_4 = F_6 ( V_12 , struct V_3 , V_13 ) ;
V_4 -> V_14 = V_15 ;
V_16 = F_7 ( V_12 ) ;
if ( F_4 ( V_16 ) ) {
V_5 = F_5 ( V_16 ) ;
goto V_17;
}
V_5 = F_8 ( V_2 , V_16 ) ;
if ( V_5 < 0 )
goto V_18;
V_5 = F_9 ( V_2 -> V_6 , V_2 , & V_19 ) ;
if ( V_5 < 0 )
goto V_20;
return 0 ;
V_20:
F_10 ( V_2 , V_16 ) ;
V_18:
F_11 ( V_16 ) ;
V_17:
F_12 ( V_12 ) ;
return V_5 ;
}
static int T_1 F_13 ( struct V_21 * V_6 )
{
struct V_22 * V_7 = V_6 -> V_7 ;
int V_5 ;
void * V_23 ;
V_5 = F_14 ( & V_15 ) ;
if ( V_5 < 0 )
return V_5 ;
V_23 = F_15 ( & V_19 , V_6 , & V_24 ) ;
if ( F_4 ( V_23 ) ) {
V_5 = F_5 ( V_23 ) ;
goto V_25;
}
V_5 = F_16 ( V_6 , V_26 ) ;
if ( V_5 < 0 )
goto V_27;
V_28 . V_29 = V_26 [ V_30 ] . V_31 ;
V_28 . V_32 = V_26 [ V_33 ] . V_31 ;
V_5 = F_17 ( V_6 , & V_34 , F_1 ) ;
if ( V_5 < 0 )
goto V_27;
F_18 ( V_6 , & V_35 ) ;
F_19 ( & V_7 -> V_36 , L_2 V_37 L_3 ,
V_38 ) ;
F_20 ( & V_19 ) ;
return 0 ;
V_27:
F_20 ( & V_19 ) ;
V_25:
F_21 ( V_15 ) ;
return V_5 ;
}
static int T_2 F_22 ( struct V_21 * V_6 )
{
F_11 ( V_16 ) ;
F_12 ( V_12 ) ;
F_21 ( V_15 ) ;
return 0 ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_39 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_39 ) ;
}
