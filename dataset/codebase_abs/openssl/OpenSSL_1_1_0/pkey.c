int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL ;
const T_4 * V_7 = NULL ;
char * V_8 = NULL , * V_9 = NULL , * V_10 = NULL , * V_11 = NULL ;
char * V_12 = NULL , * V_13 = NULL , * V_14 ;
T_5 V_15 ;
int V_16 = V_17 , V_18 = V_17 ;
int V_19 = 0 , V_20 = 0 , V_21 = 0 , V_22 = 0 , V_23 = 0 , V_24 = 1 ;
int V_25 = 0 , V_26 = 0 ;
V_14 = F_2 ( V_1 , V_2 , V_27 ) ;
while ( ( V_15 = F_3 () ) != V_28 ) {
switch ( V_15 ) {
case V_28 :
case V_29 :
V_30:
F_4 ( V_31 , L_1 , V_14 ) ;
goto V_32;
case V_33 :
F_5 ( V_27 ) ;
V_24 = 0 ;
goto V_32;
case V_34 :
if ( ! F_6 ( F_7 () , V_35 , & V_16 ) )
goto V_30;
break;
case V_36 :
if ( ! F_6 ( F_7 () , V_37 , & V_18 ) )
goto V_30;
break;
case V_38 :
V_12 = F_7 () ;
break;
case V_39 :
V_13 = F_7 () ;
break;
case V_40 :
V_5 = F_8 ( F_7 () , 0 ) ;
break;
case V_41 :
V_8 = F_7 () ;
break;
case V_42 :
V_9 = F_7 () ;
break;
case V_43 :
V_19 = V_20 = V_21 = 1 ;
break;
case V_44 :
V_20 = 1 ;
break;
case V_45 :
V_21 = V_22 = 1 ;
break;
case V_46 :
V_22 = 1 ;
break;
case V_47 :
V_23 = 1 ;
break;
case V_48 :
V_26 = 1 ;
break;
case V_49 :
if ( ! F_9 ( F_10 () , & V_7 ) )
goto V_30;
}
}
V_1 = F_11 () ;
if ( V_1 != 0 )
goto V_30;
V_25 = ! V_23 && ! V_20 ? 1 : 0 ;
if ( V_22 && ! V_21 )
V_25 = 1 ;
if ( ! F_12 ( V_12 , V_13 , & V_10 , & V_11 ) ) {
F_4 ( V_31 , L_2 ) ;
goto V_32;
}
V_4 = F_13 ( V_9 , V_18 , V_25 ) ;
if ( V_4 == NULL )
goto V_32;
if ( V_19 )
V_6 = F_14 ( V_8 , V_16 , 1 , V_10 , V_5 , L_3 ) ;
else
V_6 = F_15 ( V_8 , V_16 , 1 , V_10 , V_5 , L_4 ) ;
if ( ! V_6 )
goto V_32;
if ( ! V_23 ) {
if ( V_18 == V_17 ) {
if ( V_20 )
F_16 ( V_4 , V_6 ) ;
else {
assert ( V_25 ) ;
if ( V_26 )
F_17 ( V_4 , V_6 , V_7 ,
NULL , 0 , NULL ,
V_11 ) ;
else
F_18 ( V_4 , V_6 , V_7 ,
NULL , 0 , NULL , V_11 ) ;
}
} else if ( V_18 == V_50 ) {
if ( V_20 )
F_19 ( V_4 , V_6 ) ;
else {
assert ( V_25 ) ;
F_20 ( V_4 , V_6 ) ;
}
} else {
F_4 ( V_31 , L_5 ) ;
goto V_32;
}
}
if ( V_22 ) {
if ( V_21 )
F_21 ( V_4 , V_6 , 0 , NULL ) ;
else {
assert ( V_25 ) ;
F_22 ( V_4 , V_6 , 0 , NULL ) ;
}
}
V_24 = 0 ;
V_32:
F_23 ( V_6 ) ;
F_24 ( V_4 ) ;
F_25 ( V_3 ) ;
F_26 ( V_10 ) ;
F_26 ( V_11 ) ;
return V_24 ;
}
