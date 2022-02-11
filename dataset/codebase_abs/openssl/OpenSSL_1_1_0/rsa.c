int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
T_3 * V_5 = NULL ;
const T_4 * V_6 = NULL ;
char * V_7 = NULL , * V_8 = NULL , * V_9 ;
char * V_10 = NULL , * V_11 = NULL , * V_12 = NULL , * V_13 = NULL ;
int V_14 , V_15 = 0 ;
int V_16 = V_17 , V_18 = V_17 , V_19 = 0 , V_20 = 0 ;
int V_21 = 0 , V_22 = 0 , V_23 = 0 , V_24 = 0 , V_25 = 1 ;
# if ! F_2 ( V_26 ) && ! F_2 ( V_27 )
int V_28 = 2 ;
# endif
T_5 V_29 ;
V_9 = F_3 ( V_1 , V_2 , V_30 ) ;
while ( ( V_29 = F_4 () ) != V_31 ) {
switch ( V_29 ) {
case V_31 :
case V_32 :
V_33:
F_5 ( V_34 , L_1 , V_9 ) ;
goto V_35;
case V_36 :
F_6 ( V_30 ) ;
V_25 = 0 ;
goto V_35;
case V_37 :
if ( ! F_7 ( F_8 () , V_38 , & V_16 ) )
goto V_33;
break;
case V_39 :
V_7 = F_8 () ;
break;
case V_40 :
if ( ! F_7 ( F_8 () , V_38 , & V_18 ) )
goto V_33;
break;
case V_41 :
V_8 = F_8 () ;
break;
case V_42 :
V_12 = F_8 () ;
break;
case V_43 :
V_13 = F_8 () ;
break;
case V_44 :
V_3 = F_9 ( F_8 () , 0 ) ;
break;
case V_45 :
V_23 = 1 ;
break;
case V_46 :
V_24 = 1 ;
break;
case V_47 :
V_23 = 2 ;
break;
case V_48 :
V_24 = 2 ;
break;
case V_49 :
case V_50 :
case V_51 :
# if ! F_2 ( V_26 ) && ! F_2 ( V_27 )
V_28 = ( V_29 - V_51 ) ;
# endif
break;
case V_52 :
V_21 = 1 ;
break;
case V_53 :
V_19 = 1 ;
break;
case V_54 :
V_22 = 1 ;
break;
case V_55 :
V_20 = 1 ;
break;
case V_56 :
if ( ! F_10 ( F_11 () , & V_6 ) )
goto V_33;
break;
}
}
V_1 = F_12 () ;
if ( V_1 != 0 )
goto V_33;
V_15 = ( V_19 && ! V_23 ) || ( ! V_24 && ! V_21 ) ? 1 : 0 ;
if ( ! F_13 ( V_12 , V_13 , & V_10 , & V_11 ) ) {
F_5 ( V_34 , L_2 ) ;
goto V_35;
}
if ( V_20 && V_23 ) {
F_5 ( V_34 , L_3 ) ;
goto V_35;
}
{
T_6 * V_57 ;
if ( V_23 ) {
int V_58 = - 1 ;
if ( V_23 == 2 ) {
if ( V_16 == V_17 )
V_58 = V_59 ;
else if ( V_16 == V_60 )
V_58 = V_61 ;
} else
V_58 = V_16 ;
V_57 = F_14 ( V_7 , V_58 , 1 , V_10 , V_3 , L_4 ) ;
} else
V_57 = F_15 ( V_7 , V_16 , 1 , V_10 , V_3 , L_5 ) ;
if ( V_57 != NULL )
V_5 = F_16 ( V_57 ) ;
F_17 ( V_57 ) ;
}
if ( V_5 == NULL ) {
F_18 ( V_34 ) ;
goto V_35;
}
V_4 = F_19 ( V_8 , V_18 , V_15 ) ;
if ( V_4 == NULL )
goto V_35;
if ( V_19 ) {
assert ( V_23 || V_15 ) ;
if ( ! F_20 ( V_4 , V_5 , 0 ) ) {
perror ( V_8 ) ;
F_18 ( V_34 ) ;
goto V_35;
}
}
if ( V_22 ) {
const T_7 * V_62 ;
F_21 ( V_5 , & V_62 , NULL , NULL ) ;
F_5 ( V_4 , L_6 ) ;
F_22 ( V_4 , V_62 ) ;
F_5 ( V_4 , L_7 ) ;
}
if ( V_20 ) {
int V_63 = F_23 ( V_5 ) ;
if ( V_63 == 1 )
F_5 ( V_4 , L_8 ) ;
else if ( V_63 == 0 ) {
unsigned long V_64 ;
while ( ( V_64 = F_24 () ) != 0 &&
F_25 ( V_64 ) == V_65 &&
F_26 ( V_64 ) == V_66 &&
F_27 ( V_64 ) != V_67 ) {
F_5 ( V_4 , L_9 ,
F_28 ( V_64 ) ) ;
F_29 () ;
}
} else if ( V_63 == - 1 ) {
F_18 ( V_34 ) ;
goto V_35;
}
}
if ( V_21 ) {
V_25 = 0 ;
goto V_35;
}
F_5 ( V_34 , L_10 ) ;
if ( V_18 == V_60 ) {
if ( V_24 || V_23 ) {
if ( V_24 == 2 )
V_14 = F_30 ( V_4 , V_5 ) ;
else
V_14 = F_31 ( V_4 , V_5 ) ;
} else {
assert ( V_15 ) ;
V_14 = F_32 ( V_4 , V_5 ) ;
}
}
else if ( V_18 == V_17 ) {
if ( V_24 || V_23 ) {
if ( V_24 == 2 )
V_14 = F_33 ( V_4 , V_5 ) ;
else
V_14 = F_34 ( V_4 , V_5 ) ;
} else {
assert ( V_15 ) ;
V_14 = F_35 ( V_4 , V_5 ,
V_6 , NULL , 0 , NULL , V_11 ) ;
}
# if ! F_2 ( V_26 ) && ! F_2 ( V_27 )
} else if ( V_18 == V_68 || V_18 == V_69 ) {
T_6 * V_70 ;
V_70 = F_36 () ;
F_37 ( V_70 , V_5 ) ;
if ( V_18 == V_69 ) {
if ( V_23 ) {
F_5 ( V_34 , L_11 ) ;
F_17 ( V_70 ) ;
goto V_35;
}
assert ( V_15 ) ;
V_14 = F_38 ( V_4 , V_70 , V_28 , 0 , V_11 ) ;
} else if ( V_23 || V_24 ) {
V_14 = F_39 ( V_4 , V_70 ) ;
} else {
assert ( V_15 ) ;
V_14 = F_40 ( V_4 , V_70 ) ;
}
F_17 ( V_70 ) ;
# endif
} else {
F_5 ( V_34 , L_12 ) ;
goto V_35;
}
if ( V_14 <= 0 ) {
F_5 ( V_34 , L_13 ) ;
F_18 ( V_34 ) ;
} else
V_25 = 0 ;
V_35:
F_41 ( V_4 ) ;
F_42 ( V_5 ) ;
F_43 ( V_10 ) ;
F_43 ( V_11 ) ;
return ( V_25 ) ;
}
