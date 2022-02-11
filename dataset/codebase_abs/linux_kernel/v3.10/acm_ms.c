static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_10 = F_3 ( L_1 ) ;
if ( F_4 ( V_10 ) )
return F_5 ( V_10 ) ;
V_11 = F_6 ( V_10 ) ;
if ( F_4 ( V_11 ) ) {
V_3 = F_5 ( V_11 ) ;
goto V_12;
}
V_3 = F_7 ( V_2 , V_11 ) ;
if ( V_3 < 0 )
goto V_13;
V_3 = F_8 ( V_2 -> V_4 , V_2 , & V_14 ) ;
if ( V_3 < 0 )
goto V_15;
return 0 ;
V_15:
F_9 ( V_2 , V_11 ) ;
V_13:
F_10 ( V_11 ) ;
V_12:
F_11 ( V_10 ) ;
return V_3 ;
}
static int T_1 F_12 ( struct V_16 * V_4 )
{
struct V_17 * V_5 = V_4 -> V_5 ;
int V_3 ;
void * V_18 ;
V_18 = F_13 ( & V_14 , V_4 , & V_19 ) ;
if ( F_4 ( V_18 ) ) {
V_3 = F_5 ( V_18 ) ;
return F_5 ( V_18 ) ;
}
V_3 = F_14 ( V_4 , V_20 ) ;
if ( V_3 < 0 )
goto V_21;
V_22 . V_23 = V_20 [ V_24 ] . V_25 ;
V_22 . V_26 = V_20 [ V_27 ] . V_25 ;
V_3 = F_15 ( V_4 , & V_28 , F_1 ) ;
if ( V_3 < 0 )
goto V_21;
F_16 ( V_4 , & V_29 ) ;
F_17 ( & V_5 -> V_30 , L_2 V_31 L_3 ,
V_32 ) ;
F_18 ( & V_14 ) ;
return 0 ;
V_21:
F_18 ( & V_14 ) ;
return V_3 ;
}
static int T_2 F_19 ( struct V_16 * V_4 )
{
F_10 ( V_11 ) ;
F_11 ( V_10 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_33 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_33 ) ;
}
