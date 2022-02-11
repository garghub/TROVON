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
int div ;
int V_19 ;
unsigned int V_20 = F_8 ( V_13 ) ;
int V_21 , V_22 ;
switch ( V_20 ) {
case 16000 :
case 48000 :
V_21 = V_23 ;
V_22 = V_24 ;
div = F_9 () / ( 256 * V_20 ) ;
if ( F_9 () % ( 256 * V_20 ) > ( 128 * V_20 ) )
div ++ ;
break;
case 44100 :
case 88200 :
V_21 = V_25 ;
V_22 = V_26 ;
div = 1 ;
break;
default:
F_10 ( V_27 L_1 ,
V_28 , V_20 ) ;
return - V_29 ;
}
V_19 = F_11 ( V_18 , V_21 , V_20 ,
V_30 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_12 ( V_18 , V_31 ,
V_22 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_12 ( V_18 , V_32 ,
V_33 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_12 ( V_18 , V_34 ,
F_13 ( div , div ) ) ;
if ( V_19 < 0 )
return V_19 ;
return 0 ;
}
static int F_14 ( struct V_14 * V_15 )
{
F_15 ( V_15 -> V_35 , L_2 , V_36 ,
& V_37 , V_38 , F_16 ( V_38 ) ) ;
F_17 ( & V_37 , F_16 ( V_39 ) ,
V_39 ) ;
return 0 ;
}
static int F_18 ( struct V_40 * V_35 )
{
F_19 ( & V_37 , F_16 ( V_39 ) ,
V_39 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_19 ;
if ( ! F_21 () )
return - V_41 ;
V_19 = F_22 ( F_6 ( 1 ) , L_3 ) ;
if ( V_19 )
goto V_42;
V_19 = F_23 ( F_6 ( 1 ) , 0 ) ;
if ( V_19 )
goto V_43;
V_44 = F_24 ( L_4 , - 1 ) ;
if ( ! V_44 ) {
V_19 = - V_45 ;
goto V_46;
}
F_25 ( V_44 , & V_47 ) ;
V_19 = F_26 ( V_44 ) ;
if ( V_19 ) {
F_27 ( V_44 ) ;
goto V_48;
}
return 0 ;
V_48:
V_46:
V_43:
F_28 ( F_6 ( 1 ) ) ;
V_42:
return V_19 ;
}
static void T_2 F_29 ( void )
{
F_30 ( V_44 ) ;
F_28 ( F_6 ( 1 ) ) ;
}
