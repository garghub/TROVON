int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_4 * V_7 = NULL ;
char * V_8 = NULL , * V_9 = NULL , * V_10 = NULL , * V_11 ;
const T_5 * V_12 = NULL ;
T_6 V_13 ;
int V_14 = V_15 , V_16 = 0 , V_17 = 1 , V_18 , V_19 = 0 ;
int V_20 = 0 ;
V_11 = F_2 ( V_1 , V_2 , V_21 ) ;
while ( ( V_13 = F_3 () ) != V_22 ) {
switch ( V_13 ) {
case V_22 :
case V_23 :
V_24:
F_4 ( V_25 , L_1 , V_11 ) ;
goto V_26;
case V_27 :
V_17 = 0 ;
F_5 ( V_21 ) ;
goto V_26;
case V_28 :
if ( ! F_6 ( F_7 () , V_29 , & V_14 ) )
goto V_24;
break;
case V_30 :
V_8 = F_7 () ;
break;
case V_31 :
V_9 = F_7 () ;
break;
case V_32 :
V_5 = F_8 ( F_7 () , 0 ) ;
break;
case V_33 :
if ( V_19 == 1 )
goto V_24;
if ( ! F_9 ( & V_7 , F_7 () , V_5 ) )
goto V_26;
break;
case V_34 :
if ( ! F_10 ( & V_7 , F_7 () , V_5 , V_19 ) )
goto V_26;
break;
case V_35 :
if ( V_7 == NULL ) {
F_4 ( V_25 , L_2 , V_11 ) ;
goto V_24;
}
if ( F_11 ( V_7 , F_7 () ) <= 0 ) {
F_4 ( V_25 ,
L_3 ,
V_11 , F_7 () ) ;
F_12 ( V_25 ) ;
goto V_26;
}
break;
case V_36 :
if ( V_7 != NULL )
goto V_24;
V_19 = 1 ;
break;
case V_37 :
V_16 = 1 ;
break;
case V_38 :
if ( ! F_13 ( F_14 () , & V_12 )
|| V_19 == 1 )
goto V_24;
}
}
V_1 = F_15 () ;
if ( V_1 != 0 )
goto V_24;
V_20 = V_19 ? 0 : 1 ;
if ( V_7 == NULL )
goto V_24;
if ( ! F_16 ( V_9 , NULL , & V_10 , NULL ) ) {
F_17 ( V_25 , L_4 ) ;
goto V_26;
}
V_4 = F_18 ( V_8 , V_14 , V_20 ) ;
if ( V_4 == NULL )
goto V_26;
F_19 ( V_7 , V_39 ) ;
F_20 ( V_7 , V_25 ) ;
if ( V_19 ) {
if ( F_21 ( V_7 , & V_6 ) <= 0 ) {
F_17 ( V_25 , L_5 ) ;
F_12 ( V_25 ) ;
goto V_26;
}
} else {
if ( F_22 ( V_7 , & V_6 ) <= 0 ) {
F_17 ( V_25 , L_6 ) ;
F_12 ( V_25 ) ;
goto V_26;
}
}
if ( V_19 )
V_18 = F_23 ( V_4 , V_6 ) ;
else if ( V_14 == V_15 ) {
assert ( V_20 ) ;
V_18 = F_24 ( V_4 , V_6 , V_12 , NULL , 0 , NULL , V_10 ) ;
} else if ( V_14 == V_40 ) {
assert ( V_20 ) ;
V_18 = F_25 ( V_4 , V_6 ) ;
} else {
F_4 ( V_25 , L_7 ) ;
goto V_26;
}
if ( V_18 <= 0 ) {
F_17 ( V_25 , L_8 ) ;
F_12 ( V_25 ) ;
}
if ( V_16 ) {
if ( V_19 )
V_18 = F_26 ( V_4 , V_6 , 0 , NULL ) ;
else
V_18 = F_27 ( V_4 , V_6 , 0 , NULL ) ;
if ( V_18 <= 0 ) {
F_17 ( V_25 , L_9 ) ;
F_12 ( V_25 ) ;
}
}
V_17 = 0 ;
V_26:
F_28 ( V_6 ) ;
F_29 ( V_7 ) ;
F_30 ( V_4 ) ;
F_31 ( V_3 ) ;
F_32 ( V_10 ) ;
return V_17 ;
}
static int F_9 ( T_4 * * V_41 , const char * V_42 , T_2 * V_5 )
{
T_1 * V_43 ;
T_3 * V_6 = NULL ;
T_4 * V_7 = NULL ;
if ( * V_41 ) {
F_17 ( V_25 , L_10 ) ;
return 0 ;
}
V_43 = F_33 ( V_42 , L_11 ) ;
if ( ! V_43 ) {
F_4 ( V_25 , L_12 , V_42 ) ;
return 0 ;
}
V_6 = F_34 ( V_43 , NULL ) ;
F_31 ( V_43 ) ;
if ( ! V_6 ) {
F_4 ( V_25 , L_13 , V_42 ) ;
return 0 ;
}
V_7 = F_35 ( V_6 , V_5 ) ;
if ( V_7 == NULL )
goto V_44;
if ( F_36 ( V_7 ) <= 0 )
goto V_44;
F_28 ( V_6 ) ;
* V_41 = V_7 ;
return 1 ;
V_44:
F_17 ( V_25 , L_14 ) ;
F_12 ( V_25 ) ;
F_29 ( V_7 ) ;
F_28 ( V_6 ) ;
return 0 ;
}
int F_10 ( T_4 * * V_41 ,
const char * V_45 , T_2 * V_5 , int V_19 )
{
T_4 * V_7 = NULL ;
const T_7 * V_46 ;
T_2 * V_47 = NULL ;
int V_48 ;
if ( * V_41 ) {
F_17 ( V_25 , L_15 ) ;
return 0 ;
}
V_46 = F_37 ( & V_47 , V_45 , - 1 ) ;
#ifndef F_38
if ( ! V_46 && V_5 )
V_46 = F_39 ( V_5 , V_45 , - 1 ) ;
#endif
if ( ! V_46 ) {
F_4 ( V_25 , L_16 , V_45 ) ;
return 0 ;
}
F_40 () ;
F_41 ( & V_48 , NULL , NULL , NULL , NULL , V_46 ) ;
#ifndef F_38
F_42 ( V_47 ) ;
#endif
V_7 = F_43 ( V_48 , V_5 ) ;
if ( ! V_7 )
goto V_44;
if ( V_19 ) {
if ( F_44 ( V_7 ) <= 0 )
goto V_44;
} else {
if ( F_36 ( V_7 ) <= 0 )
goto V_44;
}
* V_41 = V_7 ;
return 1 ;
V_44:
F_4 ( V_25 , L_17 , V_45 ) ;
F_12 ( V_25 ) ;
F_29 ( V_7 ) ;
return 0 ;
}
static int V_39 ( T_4 * V_7 )
{
char V_49 = '*' ;
T_1 * V_50 = F_45 ( V_7 ) ;
int V_51 ;
V_51 = F_46 ( V_7 , 0 ) ;
if ( V_51 == 0 )
V_49 = '.' ;
if ( V_51 == 1 )
V_49 = '+' ;
if ( V_51 == 2 )
V_49 = '*' ;
if ( V_51 == 3 )
V_49 = '\n' ;
F_47 ( V_50 , & V_49 , 1 ) ;
( void ) F_48 ( V_50 ) ;
return 1 ;
}
