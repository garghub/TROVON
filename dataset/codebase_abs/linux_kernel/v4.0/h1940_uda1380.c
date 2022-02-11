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
int div ;
int V_14 ;
unsigned int V_15 = F_4 ( V_8 ) ;
switch ( V_15 ) {
case 11025 :
case 22050 :
case 44100 :
div = F_5 () / ( 384 * V_15 ) ;
if ( F_5 () % ( 384 * V_15 ) > ( 192 * V_15 ) )
div ++ ;
break;
default:
F_6 ( V_10 -> V_16 , L_1 ,
V_17 , V_15 ) ;
return - V_18 ;
}
V_14 = F_7 ( V_13 , V_19 , V_15 ,
V_20 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_8 ( V_13 , V_21 ,
V_22 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_8 ( V_13 , V_23 ,
V_24 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_8 ( V_13 , V_25 ,
F_9 ( div , div ) ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_10 ( struct V_26 * V_27 ,
struct V_28 * V_29 , int V_30 )
{
if ( F_11 ( V_30 ) )
F_12 ( V_31 + 9 , 1 ) ;
else
F_12 ( V_31 + 9 , 0 ) ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 )
{
struct V_32 * V_33 = V_10 -> V_33 ;
F_14 ( V_33 , L_2 , V_34 ,
& V_35 ) ;
F_15 ( & V_35 , F_16 ( V_36 ) ,
V_36 ) ;
F_17 ( & V_35 , F_16 ( V_37 ) ,
V_37 ) ;
return 0 ;
}
static int F_18 ( struct V_38 * V_39 )
{
F_19 ( & V_35 , F_16 ( V_37 ) ,
V_37 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_14 ;
if ( ! F_21 () )
return - V_40 ;
V_14 = F_22 ( V_31 + 9 , L_3 ) ;
if ( V_14 )
goto V_41;
V_14 = F_23 ( V_31 + 9 , 0 ) ;
if ( V_14 )
goto V_42;
V_43 = F_24 ( L_4 , - 1 ) ;
if ( ! V_43 ) {
V_14 = - V_44 ;
goto V_42;
}
F_25 ( V_43 , & V_45 ) ;
V_14 = F_26 ( V_43 ) ;
if ( V_14 )
goto V_46;
return 0 ;
V_46:
F_27 ( V_43 ) ;
V_42:
F_28 ( V_31 + 9 ) ;
V_41:
return V_14 ;
}
static void T_2 F_29 ( void )
{
F_30 ( V_43 ) ;
F_28 ( V_31 + 9 ) ;
}
