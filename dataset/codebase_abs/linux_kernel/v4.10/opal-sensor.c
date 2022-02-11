int F_1 ( T_1 V_1 , T_1 * V_2 )
{
int V_3 , V_4 ;
struct V_5 V_6 ;
T_2 V_7 ;
V_4 = F_2 () ;
if ( V_4 < 0 ) {
F_3 ( L_1 , V_8 ) ;
V_3 = V_4 ;
goto V_9;
}
F_4 ( & V_10 ) ;
V_3 = F_5 ( V_1 , V_4 , & V_7 ) ;
switch ( V_3 ) {
case V_11 :
V_3 = F_6 ( V_4 , & V_6 ) ;
if ( V_3 ) {
F_3 ( L_2 ,
V_8 , V_3 ) ;
goto V_12;
}
V_3 = F_7 ( F_8 ( V_6 ) ) ;
* V_2 = F_9 ( V_7 ) ;
break;
case V_13 :
V_3 = 0 ;
* V_2 = F_9 ( V_7 ) ;
break;
default:
V_3 = F_7 ( V_3 ) ;
break;
}
V_12:
F_10 ( & V_10 ) ;
F_11 ( V_4 ) ;
V_9:
return V_3 ;
}
int T_3 F_12 ( void )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_17 = F_13 ( L_3 ) ;
if ( ! V_17 ) {
F_3 ( L_4 ) ;
return - V_18 ;
}
V_15 = F_14 ( V_17 , L_5 , NULL ) ;
F_15 ( V_17 ) ;
return F_16 ( V_15 ) ;
}
