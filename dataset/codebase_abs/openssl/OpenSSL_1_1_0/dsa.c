int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
T_3 * V_5 = NULL ;
const T_4 * V_6 = NULL ;
char * V_7 = NULL , * V_8 = NULL , * V_9 ;
char * V_10 = NULL , * V_11 = NULL , * V_12 = NULL , * V_13 = NULL ;
T_5 V_14 ;
int V_15 = V_16 , V_17 = V_16 , V_18 = 0 , V_19 = 0 ;
int V_20 , V_21 = 0 , V_22 = 0 , V_23 = 0 , V_24 = 1 ;
# ifndef F_2
int V_25 = 2 ;
# endif
int V_26 = 0 ;
V_9 = F_3 ( V_1 , V_2 , V_27 ) ;
while ( ( V_14 = F_4 () ) != V_28 ) {
switch ( V_14 ) {
case V_28 :
case V_29 :
V_30:
V_24 = 0 ;
F_5 ( V_31 , L_1 , V_9 ) ;
goto V_32;
case V_33 :
F_6 ( V_27 ) ;
V_24 = 0 ;
goto V_32;
case V_34 :
if ( ! F_7 ( F_8 () , V_35 , & V_15 ) )
goto V_30;
break;
case V_36 :
V_7 = F_8 () ;
break;
case V_37 :
if ( ! F_7
( F_8 () , V_38 | V_39 , & V_17 ) )
goto V_30;
break;
case V_40 :
V_8 = F_8 () ;
break;
case V_41 :
V_5 = F_9 ( F_8 () , 0 ) ;
break;
case V_42 :
V_12 = F_8 () ;
break;
case V_43 :
V_13 = F_8 () ;
break;
case V_44 :
case V_45 :
case V_46 :
#ifndef F_2
V_25 = ( V_14 - V_46 ) ;
#endif
break;
case V_47 :
V_19 = 1 ;
break;
case V_48 :
V_18 = 1 ;
break;
case V_49 :
V_21 = 1 ;
break;
case V_50 :
V_22 = 1 ;
break;
case V_51 :
V_23 = 1 ;
break;
case V_52 :
if ( ! F_10 ( F_11 () , & V_6 ) )
goto V_32;
break;
}
}
V_1 = F_12 () ;
if ( V_1 != 0 )
goto V_30;
V_26 = V_22 || V_23 ? 0 : 1 ;
if ( V_18 && ! V_22 )
V_26 = 1 ;
if ( ! F_13 ( V_12 , V_13 , & V_10 , & V_11 ) ) {
F_5 ( V_31 , L_2 ) ;
goto V_32;
}
F_5 ( V_31 , L_3 ) ;
{
T_6 * V_53 ;
if ( V_22 )
V_53 = F_14 ( V_7 , V_15 , 1 , V_10 , V_5 , L_4 ) ;
else
V_53 = F_15 ( V_7 , V_15 , 1 , V_10 , V_5 , L_5 ) ;
if ( V_53 ) {
V_4 = F_16 ( V_53 ) ;
F_17 ( V_53 ) ;
}
}
if ( V_4 == NULL ) {
F_5 ( V_31 , L_6 ) ;
F_18 ( V_31 ) ;
goto V_32;
}
V_3 = F_19 ( V_8 , V_17 , V_26 ) ;
if ( V_3 == NULL )
goto V_32;
if ( V_18 ) {
assert ( V_22 || V_26 ) ;
if ( ! F_20 ( V_3 , V_4 , 0 ) ) {
perror ( V_8 ) ;
F_18 ( V_31 ) ;
goto V_32;
}
}
if ( V_21 ) {
const T_7 * V_54 = NULL ;
F_21 ( V_4 , & V_54 , NULL ) ;
F_5 ( V_3 , L_7 ) ;
F_22 ( V_3 , V_54 ) ;
F_5 ( V_3 , L_8 ) ;
}
if ( V_19 ) {
V_24 = 0 ;
goto V_32;
}
F_5 ( V_31 , L_9 ) ;
if ( V_17 == V_55 ) {
if ( V_22 || V_23 )
V_20 = F_23 ( V_3 , V_4 ) ;
else {
assert ( V_26 ) ;
V_20 = F_24 ( V_3 , V_4 ) ;
}
} else if ( V_17 == V_16 ) {
if ( V_22 || V_23 )
V_20 = F_25 ( V_3 , V_4 ) ;
else {
assert ( V_26 ) ;
V_20 = F_26 ( V_3 , V_4 , V_6 ,
NULL , 0 , NULL , V_11 ) ;
}
# if ! F_27 ( V_56 ) && ! F_27 ( F_2 )
} else if ( V_17 == V_57 || V_17 == V_58 ) {
T_6 * V_59 ;
V_59 = F_28 () ;
F_29 ( V_59 , V_4 ) ;
if ( V_17 == V_58 ) {
if ( V_22 ) {
F_5 ( V_31 , L_10 ) ;
F_17 ( V_59 ) ;
goto V_32;
}
assert ( V_26 ) ;
V_20 = F_30 ( V_3 , V_59 , V_25 , 0 , V_11 ) ;
}
else if ( V_22 || V_23 )
V_20 = F_31 ( V_3 , V_59 ) ;
else {
assert ( V_26 ) ;
V_20 = F_32 ( V_3 , V_59 ) ;
}
F_17 ( V_59 ) ;
# endif
} else {
F_5 ( V_31 , L_11 ) ;
goto V_32;
}
if ( V_20 <= 0 ) {
F_5 ( V_31 , L_12 ) ;
F_18 ( V_31 ) ;
goto V_32;
}
V_24 = 0 ;
V_32:
F_33 ( V_3 ) ;
F_34 ( V_4 ) ;
F_35 ( V_10 ) ;
F_35 ( V_11 ) ;
return ( V_24 ) ;
}
