static T_1 F_1 ( int V_1 , void * V_2 )
{
return F_2 () ;
}
static void F_3 ( struct V_3 * V_4 , unsigned V_5 )
{
struct V_6 * V_7 = V_4 -> V_8 . V_7 . V_9 ;
int V_10 ;
switch ( V_5 ) {
case V_11 :
F_4 ( V_7 , L_1 ) ;
F_5 ( 0 , V_12 ) ;
F_5 ( 0 , V_13 ) ;
break;
case V_14 :
F_4 ( V_7 , L_2 ) ;
V_10 = F_6 ( V_4 -> V_15 , V_16 ) ;
V_10 &= ~ V_17 ;
V_10 |= V_18 ;
F_7 ( V_4 -> V_15 , V_10 , V_16 ) ;
break;
default:
F_4 ( V_7 , L_3 ) ;
break;
}
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
void T_2 * V_23 ;
int V_1 ;
int V_24 ;
F_4 ( & V_20 -> V_7 , L_4 ) ;
V_22 = F_9 ( V_20 , V_25 , 0 ) ;
if ( ! V_22 ) {
F_10 ( & V_20 -> V_7 , L_5 ) ;
return - V_26 ;
}
V_23 = F_11 ( V_22 -> V_27 , F_12 ( V_22 ) ) ;
if ( ! V_23 ) {
F_10 ( & V_20 -> V_7 , L_6 ) ;
return - V_28 ;
}
V_24 = F_13 ( & V_29 , & V_20 -> V_7 , V_23 ) ;
if ( V_24 < 0 ) {
F_10 ( & V_20 -> V_7 , L_7 ) ;
goto V_30;
}
V_1 = F_14 ( V_20 , 0 ) ;
if ( V_1 < 0 ) {
F_10 ( & V_20 -> V_7 , L_8 ) ;
V_24 = - V_26 ;
goto V_31;
}
V_24 = F_15 ( V_1 , F_1 , V_32 , V_20 -> V_33 , V_20 ) ;
if ( V_24 < 0 ) {
F_10 ( & V_20 -> V_7 , L_9 ) ;
goto V_31;
}
F_16 ( & V_20 -> V_7 ) ;
F_17 ( & V_20 -> V_7 ) ;
return 0 ;
V_31:
V_31 () ;
V_30:
V_30 ( V_23 ) ;
return V_24 ;
}
static int T_3 F_18 ( void )
{
return F_19 ( & V_34 ) ;
}
