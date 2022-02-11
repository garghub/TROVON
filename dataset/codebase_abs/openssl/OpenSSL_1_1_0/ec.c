int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL ;
const T_4 * V_7 ;
const T_5 * V_8 = NULL ;
T_6 V_9 = V_10 ;
char * V_11 = NULL , * V_12 = NULL , * V_13 ;
char * V_14 = NULL , * V_15 = NULL , * V_16 = NULL , * V_17 = NULL ;
T_7 V_18 ;
int V_19 = V_20 , V_21 = 0 , V_22 = 0 ;
int V_23 = V_24 , V_25 = V_24 , V_26 = 0 , V_27 = 0 ;
int V_28 = 0 , V_29 = 0 , V_30 = 0 , V_31 , V_32 = 1 , V_33 = 0 ;
int V_34 = 0 , V_35 = 0 ;
V_13 = F_2 ( V_1 , V_2 , V_36 ) ;
while ( ( V_18 = F_3 () ) != V_37 ) {
switch ( V_18 ) {
case V_37 :
case V_38 :
V_39:
F_4 ( V_40 , L_1 , V_13 ) ;
goto V_41;
case V_42 :
F_5 ( V_36 ) ;
V_32 = 0 ;
goto V_41;
case V_43 :
if ( ! F_6 ( F_7 () , V_44 , & V_23 ) )
goto V_39;
break;
case V_45 :
V_11 = F_7 () ;
break;
case V_46 :
if ( ! F_6 ( F_7 () , V_47 , & V_25 ) )
goto V_39;
break;
case V_48 :
V_12 = F_7 () ;
break;
case V_49 :
V_27 = 1 ;
break;
case V_50 :
V_26 = 1 ;
break;
case V_51 :
V_30 = 1 ;
break;
case V_52 :
V_28 = 1 ;
break;
case V_53 :
V_29 = 1 ;
break;
case V_54 :
V_16 = F_7 () ;
break;
case V_55 :
V_17 = F_7 () ;
break;
case V_56 :
V_5 = F_8 ( F_7 () , 0 ) ;
break;
case V_57 :
if ( ! F_9 ( F_10 () , & V_8 ) )
goto V_39;
break;
case V_58 :
if ( ! F_11 ( F_7 () , V_59 , & V_31 ) )
goto V_39;
V_21 = 1 ;
V_9 = V_31 ;
break;
case V_60 :
if ( ! F_11 ( F_7 () , V_61 , & V_31 ) )
goto V_39;
V_22 = 1 ;
V_19 = V_31 ;
break;
case V_62 :
V_34 = 1 ;
break;
case V_63 :
V_35 = 1 ;
break;
}
}
V_1 = F_12 () ;
if ( V_1 != 0 )
goto V_39;
V_33 = V_30 || V_28 || V_29 ? 0 : 1 ;
if ( V_26 && ! V_28 )
V_33 = 1 ;
if ( ! F_13 ( V_16 , V_17 , & V_14 , & V_15 ) ) {
F_4 ( V_40 , L_2 ) ;
goto V_41;
}
if ( V_23 != V_64 ) {
V_3 = F_14 ( V_11 , 'r' , V_23 ) ;
if ( V_3 == NULL )
goto V_41;
}
F_4 ( V_40 , L_3 ) ;
if ( V_23 == V_65 ) {
if ( V_28 )
V_6 = F_15 ( V_3 , NULL ) ;
else
V_6 = F_16 ( V_3 , NULL ) ;
} else if ( V_23 == V_64 ) {
T_8 * V_66 ;
if ( V_28 )
V_66 = F_17 ( V_11 , V_23 , 1 , V_14 , V_5 , L_4 ) ;
else
V_66 = F_18 ( V_11 , V_23 , 1 , V_14 , V_5 , L_5 ) ;
if ( V_66 != NULL ) {
V_6 = F_19 ( V_66 ) ;
F_20 ( V_66 ) ;
}
} else {
if ( V_28 )
V_6 = F_21 ( V_3 , NULL , NULL , NULL ) ;
else
V_6 = F_22 ( V_3 , NULL , NULL , V_14 ) ;
}
if ( V_6 == NULL ) {
F_4 ( V_40 , L_6 ) ;
F_23 ( V_40 ) ;
goto V_41;
}
V_4 = F_24 ( V_12 , V_25 , V_33 ) ;
if ( V_4 == NULL )
goto V_41;
V_7 = F_25 ( V_6 ) ;
if ( V_21 )
F_26 ( V_6 , V_9 ) ;
if ( V_22 )
F_27 ( V_6 , V_19 ) ;
if ( V_34 )
F_28 ( V_6 , V_67 ) ;
if ( V_26 ) {
assert ( V_28 || V_33 ) ;
if ( ! F_29 ( V_4 , V_6 , 0 ) ) {
perror ( V_12 ) ;
F_23 ( V_40 ) ;
goto V_41;
}
}
if ( V_35 ) {
if ( F_30 ( V_6 ) == 1 ) {
F_4 ( V_40 , L_7 ) ;
} else {
F_4 ( V_40 , L_8 ) ;
F_23 ( V_40 ) ;
}
}
if ( V_27 ) {
V_32 = 0 ;
goto V_41;
}
F_4 ( V_40 , L_9 ) ;
if ( V_25 == V_65 ) {
if ( V_30 )
V_31 = F_31 ( V_4 , V_7 ) ;
else if ( V_28 || V_29 )
V_31 = F_32 ( V_4 , V_6 ) ;
else {
assert ( V_33 ) ;
V_31 = F_33 ( V_4 , V_6 ) ;
}
} else {
if ( V_30 )
V_31 = F_34 ( V_4 , V_7 ) ;
else if ( V_28 || V_29 )
V_31 = F_35 ( V_4 , V_6 ) ;
else {
assert ( V_33 ) ;
V_31 = F_36 ( V_4 , V_6 , V_8 ,
NULL , 0 , NULL , V_15 ) ;
}
}
if ( ! V_31 ) {
F_4 ( V_40 , L_10 ) ;
F_23 ( V_40 ) ;
} else
V_32 = 0 ;
V_41:
F_37 ( V_3 ) ;
F_38 ( V_4 ) ;
F_39 ( V_6 ) ;
F_40 ( V_14 ) ;
F_40 ( V_15 ) ;
return ( V_32 ) ;
}
