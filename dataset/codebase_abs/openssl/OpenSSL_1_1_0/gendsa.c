int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
const T_3 * V_6 = NULL ;
char * V_7 = NULL , * V_8 = NULL ;
char * V_9 = NULL , * V_10 = NULL , * V_11 = NULL , * V_12 ;
T_4 V_13 ;
int V_14 = 1 , V_15 = 0 ;
const T_5 * V_16 = NULL ;
V_12 = F_2 ( V_1 , V_2 , V_17 ) ;
while ( ( V_13 = F_3 () ) != V_18 ) {
switch ( V_13 ) {
case V_18 :
case V_19 :
V_20:
F_4 ( V_21 , L_1 , V_12 ) ;
goto V_22;
case V_23 :
V_14 = 0 ;
F_5 ( V_17 ) ;
goto V_22;
case V_24 :
V_9 = F_6 () ;
break;
case V_25 :
V_10 = F_6 () ;
break;
case V_26 :
( void ) F_7 ( F_6 () , 0 ) ;
break;
case V_27 :
V_7 = F_6 () ;
break;
case V_28 :
if ( ! F_8 ( F_9 () , & V_6 ) )
goto V_22;
break;
}
}
V_1 = F_10 () ;
V_2 = F_11 () ;
V_15 = 1 ;
if ( V_1 != 1 )
goto V_20;
V_8 = * V_2 ;
if ( ! F_12 ( NULL , V_10 , NULL , & V_11 ) ) {
F_4 ( V_21 , L_2 ) ;
goto V_22;
}
V_4 = F_13 ( V_8 , 'r' , V_29 ) ;
if ( V_4 == NULL )
goto V_30;
if ( ( V_5 = F_14 ( V_4 , NULL , NULL , NULL ) ) == NULL ) {
F_4 ( V_21 , L_3 ) ;
goto V_22;
}
F_15 ( V_4 ) ;
V_4 = NULL ;
V_3 = F_16 ( V_9 , V_29 , V_15 ) ;
if ( V_3 == NULL )
goto V_30;
if ( ! F_17 ( NULL , 1 ) && V_7 == NULL ) {
F_4 ( V_21 ,
L_4 ) ;
}
if ( V_7 != NULL )
F_4 ( V_21 , L_5 ,
F_18 ( V_7 ) ) ;
F_19 ( V_5 , & V_16 , NULL , NULL ) ;
F_4 ( V_21 , L_6 , F_20 ( V_16 ) ) ;
if ( ! F_21 ( V_5 ) )
goto V_22;
F_22 ( NULL ) ;
assert ( V_15 ) ;
if ( ! F_23 ( V_3 , V_5 , V_6 , NULL , 0 , NULL , V_11 ) )
goto V_22;
V_14 = 0 ;
V_22:
if ( V_14 != 0 )
F_24 ( V_21 ) ;
V_30:
F_15 ( V_4 ) ;
F_25 ( V_3 ) ;
F_26 ( V_5 ) ;
F_27 ( V_11 ) ;
return ( V_14 ) ;
}
