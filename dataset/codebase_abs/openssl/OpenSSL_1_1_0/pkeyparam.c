int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
int V_6 = 0 , V_7 = 0 , V_8 = 1 ;
T_3 V_9 ;
char * V_10 = NULL , * V_11 = NULL , * V_12 ;
V_12 = F_2 ( V_1 , V_2 , V_13 ) ;
while ( ( V_9 = F_3 () ) != V_14 ) {
switch ( V_9 ) {
case V_14 :
case V_15 :
V_16:
F_4 ( V_17 , L_1 , V_12 ) ;
goto V_18;
case V_19 :
F_5 ( V_13 ) ;
V_8 = 0 ;
goto V_18;
case V_20 :
V_10 = F_6 () ;
break;
case V_21 :
V_11 = F_6 () ;
break;
case V_22 :
( void ) F_7 ( F_6 () , 0 ) ;
break;
case V_23 :
V_6 = 1 ;
break;
case V_24 :
V_7 = 1 ;
break;
}
}
V_1 = F_8 () ;
if ( V_1 != 0 )
goto V_16;
V_3 = F_9 ( V_10 , 'r' , V_25 ) ;
if ( V_3 == NULL )
goto V_18;
V_4 = F_9 ( V_11 , 'w' , V_25 ) ;
if ( V_4 == NULL )
goto V_18;
V_5 = F_10 ( V_3 , NULL ) ;
if ( ! V_5 ) {
F_4 ( V_17 , L_2 ) ;
F_11 ( V_17 ) ;
goto V_18;
}
if ( ! V_7 )
F_12 ( V_4 , V_5 ) ;
if ( V_6 )
F_13 ( V_4 , V_5 , 0 , NULL ) ;
V_8 = 0 ;
V_18:
F_14 ( V_5 ) ;
F_15 ( V_4 ) ;
F_16 ( V_3 ) ;
return V_8 ;
}
