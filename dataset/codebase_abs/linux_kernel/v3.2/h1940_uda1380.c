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
static int F_3 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_2 -> V_18 ;
struct V_19 * V_20 = V_17 -> V_20 ;
struct V_19 * V_21 = V_17 -> V_21 ;
int div ;
int V_22 ;
unsigned int V_23 = F_4 ( V_15 ) ;
switch ( V_23 ) {
case 11025 :
case 22050 :
case 44100 :
div = F_5 () / ( 384 * V_23 ) ;
if ( F_5 () % ( 384 * V_23 ) > ( 192 * V_23 ) )
div ++ ;
break;
default:
F_6 ( & V_17 -> V_24 , L_1 ,
V_25 , V_23 ) ;
return - V_26 ;
}
V_22 = F_7 ( V_21 , V_27 |
V_28 | V_29 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_7 ( V_20 , V_27 |
V_28 | V_29 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_8 ( V_20 , V_30 , V_23 ,
V_31 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_9 ( V_20 , V_32 ,
V_33 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_9 ( V_20 , V_34 ,
V_35 ) ;
if ( V_22 < 0 )
return V_22 ;
V_22 = F_9 ( V_20 , V_36 ,
F_10 ( div , div ) ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
}
static int F_11 ( struct V_37 * V_38 ,
struct V_39 * V_40 , int V_41 )
{
if ( F_12 ( V_41 ) )
F_13 ( V_42 , 1 ) ;
else
F_13 ( V_42 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_43 * V_44 = V_17 -> V_44 ;
struct V_45 * V_46 = & V_44 -> V_46 ;
int V_47 ;
F_15 ( V_46 , L_2 ) ;
F_15 ( V_46 , L_3 ) ;
F_15 ( V_46 , L_4 ) ;
F_16 ( V_44 , L_2 , V_48 ,
& V_49 ) ;
F_17 ( & V_49 , F_18 ( V_50 ) ,
V_50 ) ;
F_19 ( & V_49 , F_18 ( V_51 ) ,
V_51 ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
int V_22 ;
if ( ! F_21 () )
return - V_52 ;
V_22 = F_22 ( V_42 , L_5 ) ;
if ( V_22 )
goto V_53;
V_22 = F_23 ( V_42 , 0 ) ;
if ( V_22 )
goto V_54;
V_55 = F_24 ( L_6 , - 1 ) ;
if ( ! V_55 ) {
V_22 = - V_56 ;
goto V_54;
}
F_25 ( V_55 , & V_57 ) ;
V_22 = F_26 ( V_55 ) ;
if ( V_22 )
goto V_58;
return 0 ;
V_58:
F_27 ( V_55 ) ;
V_54:
F_28 ( V_42 ) ;
V_53:
return V_22 ;
}
static void T_2 F_29 ( void )
{
F_30 ( V_55 ) ;
F_31 ( & V_49 , F_18 ( V_51 ) ,
V_51 ) ;
F_28 ( V_42 ) ;
}
