int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
T_3 * V_5 = NULL ;
T_4 * V_6 = NULL ;
T_5 * V_7 = NULL ;
char * V_8 = NULL , * V_9 = NULL ;
char * V_10 = NULL , * V_11 = NULL , * V_12 = NULL , * V_13 = NULL ;
char * V_14 = NULL , * V_15 ;
const char * V_16 = L_1 , * V_17 = L_2 ;
int V_18 , V_19 = 1 , V_20 = 0 , V_21 = 0 , V_22 = 0 ;
T_6 V_23 ;
V_15 = F_2 ( V_1 , V_2 , V_24 ) ;
while ( ( V_23 = F_3 () ) != V_25 ) {
switch ( V_23 ) {
case V_25 :
case V_26 :
V_27:
F_4 ( V_28 , L_3 , V_15 ) ;
goto V_29;
case V_30 :
F_5 ( V_24 ) ;
V_19 = 0 ;
goto V_29;
case V_31 :
V_10 = F_6 () ;
break;
case V_32 :
V_11 = F_6 () ;
break;
case V_33 :
V_21 = 1 ;
break;
case V_34 :
V_22 = 1 ;
break;
case V_35 :
V_20 = 1 ;
break;
case V_36 :
V_12 = F_6 () ;
break;
case V_37 :
V_9 = F_6 () ;
break;
case V_38 :
V_8 = F_6 () ;
break;
case V_39 :
V_16 = F_6 () ;
break;
case V_40 :
V_17 = F_6 () ;
break;
case V_41 :
V_5 = F_7 ( F_6 () , 0 ) ;
break;
}
}
V_1 = F_8 () ;
if ( V_1 != 0 )
goto V_27;
if ( ! F_9 ( V_12 , NULL , & V_13 , NULL ) ) {
F_4 ( V_28 , L_4 ) ;
goto V_29;
}
if ( V_9 ) {
V_6 = F_10 ( strcmp ( V_9 , L_5 ) ? V_9 : NULL ,
V_42 , 1 , V_13 , V_5 , L_6 ) ;
if ( ! V_6 ) {
goto V_29;
}
V_7 = F_11 () ;
if ( V_8 )
F_12 ( V_7 -> V_16 -> V_8 ,
V_8 , ( int ) strlen ( V_8 ) ) ;
F_13 ( V_7 , V_6 ) ;
F_14 ( V_7 , V_6 , F_15 () ) ;
V_14 = F_16 ( V_7 ) ;
V_3 = F_17 ( V_11 , 'w' , V_43 ) ;
if ( V_3 == NULL ) {
F_18 ( V_14 ) ;
goto V_29;
}
F_4 ( V_3 , L_7 , V_14 ) ;
F_18 ( V_14 ) ;
V_19 = 0 ;
goto V_29;
}
if ( ( V_4 = F_19 ( V_10 ) ) == NULL )
goto V_29;
V_14 = F_20 ( V_4 , V_17 , V_16 ) ;
if ( V_14 == NULL ) {
F_4 ( V_28 , L_8 , V_16 ) ;
F_21 ( V_28 ) ;
goto V_29;
}
V_7 = F_22 ( V_14 , - 1 ) ;
if ( ! V_7 ) {
F_4 ( V_28 , L_9 ) ;
F_21 ( V_28 ) ;
goto V_29;
}
V_3 = F_17 ( V_11 , 'w' , V_43 ) ;
if ( V_3 == NULL )
goto V_29;
if ( ! V_21 )
F_23 ( V_3 , V_7 ) ;
V_6 = F_24 ( V_7 ) ;
if ( V_20 ) {
V_18 = F_25 ( V_7 , V_6 ) ;
if ( V_18 > 0 )
F_4 ( V_28 , L_10 ) ;
else {
F_4 ( V_28 , L_11 ) ;
F_21 ( V_28 ) ;
goto V_29;
}
}
if ( V_22 )
F_26 ( V_3 , V_6 ) ;
V_19 = 0 ;
V_29:
F_27 ( V_4 ) ;
F_28 ( V_7 ) ;
F_29 ( V_3 ) ;
F_30 ( V_6 ) ;
F_18 ( V_13 ) ;
return ( V_19 ) ;
}
