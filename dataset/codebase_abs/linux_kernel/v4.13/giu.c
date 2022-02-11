static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned int V_5 ;
int V_6 ;
V_2 = F_2 ( L_1 , - 1 ) ;
if ( ! V_2 )
return - V_7 ;
switch ( F_3 () ) {
case V_8 :
case V_9 :
V_2 -> V_10 = V_11 ;
V_4 = V_12 ;
V_5 = F_4 ( V_12 ) ;
break;
case V_13 :
case V_14 :
V_2 -> V_10 = V_15 ;
V_4 = V_16 ;
V_5 = F_4 ( V_16 ) ;
break;
case V_17 :
V_2 -> V_10 = V_18 ;
V_4 = V_19 ;
V_5 = F_4 ( V_19 ) ;
break;
default:
V_6 = - V_20 ;
goto V_21;
}
V_6 = F_5 ( V_2 , V_4 , V_5 ) ;
if ( V_6 )
goto V_21;
V_6 = F_6 ( V_2 ) ;
if ( V_6 )
goto V_21;
return 0 ;
V_21:
F_7 ( V_2 ) ;
return V_6 ;
}
