static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_4 -> V_5 . V_6 = V_7 . V_8 [ 0 ] ;
V_4 -> V_5 . V_9 = V_7 . V_8 [ V_7 . V_10 - 1 ] ;
V_4 -> V_5 . V_11 = V_12 ;
return F_2 ( V_4 , 0 ,
V_13 ,
& V_7 ) ;
}
static int F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 , int V_18 )
{
if ( F_4 ( V_18 ) )
F_5 ( F_6 ( 1 ) , 1 ) ;
else
F_5 ( F_6 ( 1 ) , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = V_2 -> V_23 ;
struct V_24 * V_25 = V_22 -> V_25 ;
struct V_24 * V_26 = V_22 -> V_26 ;
int div ;
int V_27 ;
unsigned int V_28 = F_8 ( V_20 ) ;
int V_29 , V_30 ;
switch ( V_28 ) {
case 16000 :
case 48000 :
V_29 = V_31 ;
V_30 = V_32 ;
div = F_9 () / ( 256 * V_28 ) ;
if ( F_9 () % ( 256 * V_28 ) > ( 128 * V_28 ) )
div ++ ;
break;
case 44100 :
case 88200 :
V_29 = V_33 ;
V_30 = V_34 ;
div = 1 ;
break;
default:
F_10 ( V_35 L_1 ,
V_36 , V_28 ) ;
return - V_37 ;
}
V_27 = F_11 ( V_26 , V_38 |
V_39 | V_40 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_11 ( V_25 , V_38 |
V_39 | V_40 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_12 ( V_25 , V_29 , V_28 ,
V_41 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_13 ( V_25 , V_42 ,
V_30 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_13 ( V_25 , V_43 ,
V_44 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_13 ( V_25 , V_45 ,
F_14 ( div , div ) ) ;
if ( V_27 < 0 )
return V_27 ;
return 0 ;
}
static int F_15 ( struct V_21 * V_22 )
{
struct V_46 * V_47 = V_22 -> V_47 ;
struct V_48 * V_49 = & V_47 -> V_49 ;
int V_50 ;
F_16 ( V_49 , L_2 ) ;
F_16 ( V_49 , L_3 ) ;
F_16 ( V_49 , L_4 ) ;
F_17 ( V_47 , L_2 , V_51 ,
& V_52 ) ;
F_18 ( & V_52 , F_19 ( V_53 ) ,
V_53 ) ;
F_20 ( & V_52 , F_19 ( V_54 ) ,
V_54 ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
int V_27 ;
if ( ! F_22 () )
return - V_55 ;
V_27 = F_23 ( F_6 ( 1 ) , L_5 ) ;
if ( V_27 )
goto V_56;
V_27 = F_24 ( F_6 ( 1 ) , 0 ) ;
if ( V_27 )
goto V_57;
V_58 = F_25 ( L_6 , - 1 ) ;
if ( ! V_58 ) {
V_27 = - V_59 ;
goto V_60;
}
F_26 ( V_58 , & V_61 ) ;
V_27 = F_27 ( V_58 ) ;
if ( V_27 ) {
F_28 ( V_58 ) ;
goto V_62;
}
return 0 ;
V_62:
V_60:
V_57:
F_29 ( F_6 ( 1 ) ) ;
V_56:
return V_27 ;
}
static void T_2 F_30 ( void )
{
F_31 ( V_58 ) ;
F_32 ( & V_52 , F_19 ( V_54 ) ,
V_54 ) ;
F_29 ( F_6 ( 1 ) ) ;
}
