T_1 F_1 ( const T_2 * V_1 , const T_3 V_2 )
{
T_4 V_3 = 1024 ;
T_5 * V_4 ;
T_6 V_5 ;
T_1 V_6 = TRUE ;
int V_7 ;
V_4 = F_2 ( T_5 , V_3 ) ;
if ( ! V_4 )
return FALSE ;
F_3 ( & V_5 ) ;
V_7 = F_4 ( & V_5 , V_1 , V_2 , V_4 , V_3 ) ;
if ( V_7 < 0 ) {
switch ( V_7 ) {
case V_8 :
F_5 ( V_9 , V_10 , L_1 ) ;
break;
case V_11 :
F_5 ( V_9 , V_10 , L_2 ) ;
break;
case V_12 :
F_5 ( V_9 , V_10 , L_3
L_4 ) ;
break;
default:
F_5 ( V_9 , V_10 , L_5 ) ;
break;
}
V_6 = FALSE ;
}
F_6 ( V_4 ) ;
return V_6 ;
}
int F_7 ( const char * V_1 , T_5 * V_13 , unsigned int V_3 )
{
T_6 V_5 ;
F_3 ( & V_5 ) ;
return F_4 ( & V_5 , V_1 , strlen ( V_1 ) , V_13 , V_3 ) ;
}
