static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
return F_2 ( V_4 , 0 ,
V_5 ,
& V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_12 * V_14 = V_10 -> V_14 ;
int div ;
int V_15 ;
unsigned int V_16 = F_4 ( V_8 ) ;
switch ( V_16 ) {
case 11025 :
case 22050 :
case 44100 :
div = F_5 () / ( 384 * V_16 ) ;
if ( F_5 () % ( 384 * V_16 ) > ( 192 * V_16 ) )
div ++ ;
break;
default:
F_6 ( V_10 -> V_17 , L_1 ,
V_18 , V_16 ) ;
return - V_19 ;
}
V_15 = F_7 ( V_14 , V_20 |
V_21 | V_22 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_7 ( V_13 , V_20 |
V_21 | V_22 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_8 ( V_13 , V_23 , V_16 ,
V_24 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_9 ( V_13 , V_25 ,
V_26 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_9 ( V_13 , V_27 ,
V_28 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_9 ( V_13 , V_29 ,
F_10 ( div , div ) ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_11 ( struct V_30 * V_31 ,
struct V_32 * V_33 , int V_34 )
{
if ( F_12 ( V_34 ) )
F_13 ( V_35 + 9 , 1 ) ;
else
F_13 ( V_35 + 9 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 )
{
struct V_36 * V_37 = V_10 -> V_37 ;
struct V_38 * V_39 = & V_37 -> V_39 ;
F_15 ( V_39 , L_2 ) ;
F_15 ( V_39 , L_3 ) ;
F_15 ( V_39 , L_4 ) ;
F_16 ( V_37 , L_2 , V_40 ,
& V_41 ) ;
F_17 ( & V_41 , F_18 ( V_42 ) ,
V_42 ) ;
F_19 ( & V_41 , F_18 ( V_43 ) ,
V_43 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_15 ;
if ( ! F_21 () )
return - V_44 ;
V_15 = F_22 ( V_35 + 9 , L_5 ) ;
if ( V_15 )
goto V_45;
V_15 = F_23 ( V_35 + 9 , 0 ) ;
if ( V_15 )
goto V_46;
V_47 = F_24 ( L_6 , - 1 ) ;
if ( ! V_47 ) {
V_15 = - V_48 ;
goto V_46;
}
F_25 ( V_47 , & V_49 ) ;
V_15 = F_26 ( V_47 ) ;
if ( V_15 )
goto V_50;
return 0 ;
V_50:
F_27 ( V_47 ) ;
V_46:
F_28 ( V_35 + 9 ) ;
V_45:
return V_15 ;
}
static void T_2 F_29 ( void )
{
F_30 ( V_47 ) ;
F_31 ( & V_41 , F_18 ( V_43 ) ,
V_43 ) ;
F_28 ( V_35 + 9 ) ;
}
