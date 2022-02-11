static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_2 ( V_4 , 0 ,
V_5 ,
& V_6 ) ;
}
static int F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
if ( F_4 ( V_11 ) )
F_5 ( F_6 ( 1 ) , 1 ) ;
else
F_5 ( F_6 ( 1 ) , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
struct V_17 * V_18 = V_15 -> V_18 ;
struct V_17 * V_19 = V_15 -> V_19 ;
int div ;
int V_20 ;
unsigned int V_21 = F_8 ( V_13 ) ;
int V_22 , V_23 ;
switch ( V_21 ) {
case 16000 :
case 48000 :
V_22 = V_24 ;
V_23 = V_25 ;
div = F_9 () / ( 256 * V_21 ) ;
if ( F_9 () % ( 256 * V_21 ) > ( 128 * V_21 ) )
div ++ ;
break;
case 44100 :
case 88200 :
V_22 = V_26 ;
V_23 = V_27 ;
div = 1 ;
break;
default:
F_10 ( V_28 L_1 ,
V_29 , V_21 ) ;
return - V_30 ;
}
V_20 = F_11 ( V_19 , V_31 |
V_32 | V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_11 ( V_18 , V_31 |
V_32 | V_33 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_12 ( V_18 , V_22 , V_21 ,
V_34 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_13 ( V_18 , V_35 ,
V_23 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_13 ( V_18 , V_36 ,
V_37 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_13 ( V_18 , V_38 ,
F_14 ( div , div ) ) ;
if ( V_20 < 0 )
return V_20 ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_39 * V_40 = V_15 -> V_40 ;
struct V_41 * V_42 = & V_40 -> V_42 ;
F_16 ( V_42 , L_2 ) ;
F_16 ( V_42 , L_3 ) ;
F_16 ( V_42 , L_4 ) ;
F_17 ( V_40 , L_2 , V_43 ,
& V_44 ) ;
F_18 ( & V_44 , F_19 ( V_45 ) ,
V_45 ) ;
F_20 ( & V_44 , F_19 ( V_46 ) ,
V_46 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
int V_20 ;
if ( ! F_22 () )
return - V_47 ;
V_20 = F_23 ( F_6 ( 1 ) , L_5 ) ;
if ( V_20 )
goto V_48;
V_20 = F_24 ( F_6 ( 1 ) , 0 ) ;
if ( V_20 )
goto V_49;
V_50 = F_25 ( L_6 , - 1 ) ;
if ( ! V_50 ) {
V_20 = - V_51 ;
goto V_52;
}
F_26 ( V_50 , & V_53 ) ;
V_20 = F_27 ( V_50 ) ;
if ( V_20 ) {
F_28 ( V_50 ) ;
goto V_54;
}
return 0 ;
V_54:
V_52:
V_49:
F_29 ( F_6 ( 1 ) ) ;
V_48:
return V_20 ;
}
static void T_2 F_30 ( void )
{
F_31 ( V_50 ) ;
F_32 ( & V_44 , F_19 ( V_46 ) ,
V_46 ) ;
F_29 ( F_6 ( 1 ) ) ;
}
