int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
char * V_6 = NULL , * V_7 = NULL , * V_8 , * V_9 = NULL ;
#ifndef F_2
int V_10 = 0 ;
#endif
int V_11 , V_12 = 0 , V_13 = 0 , V_14 = 1 , V_15 = 0 , V_16 = 0 ;
int V_17 = V_18 , V_19 = V_18 , V_20 = 0 , V_21 = 0 ;
T_3 V_22 ;
V_8 = F_3 ( V_1 , V_2 , V_23 ) ;
while ( ( V_22 = F_4 () ) != V_24 ) {
switch ( V_22 ) {
case V_24 :
case V_25 :
V_26:
F_5 ( V_27 , L_1 , V_8 ) ;
goto V_28;
case V_29 :
F_6 ( V_23 ) ;
V_14 = 0 ;
goto V_28;
case V_30 :
if ( ! F_7 ( F_8 () , V_31 , & V_17 ) )
goto V_26;
break;
case V_32 :
if ( ! F_7 ( F_8 () , V_31 , & V_19 ) )
goto V_26;
break;
case V_33 :
V_6 = F_8 () ;
break;
case V_34 :
V_7 = F_8 () ;
break;
case V_35 :
( void ) F_9 ( F_8 () , 0 ) ;
break;
case V_36 :
V_20 = 1 ;
break;
case V_37 :
V_12 = 1 ;
break;
case V_38 :
#ifndef F_2
V_10 = 1 ;
#endif
break;
case V_39 :
V_13 = 1 ;
break;
case V_40 :
V_16 = 2 ;
break;
case V_41 :
V_16 = 5 ;
break;
case V_42 :
V_21 = 1 ;
break;
case V_43 :
V_9 = F_8 () ;
break;
}
}
V_1 = F_10 () ;
V_2 = F_11 () ;
if ( V_2 [ 0 ] && ( ! F_12 ( V_2 [ 0 ] , & V_15 ) || V_15 <= 0 ) )
goto V_28;
if ( V_16 && ! V_15 )
V_15 = V_44 ;
# ifndef F_2
if ( V_10 && V_16 ) {
F_5 ( V_27 ,
L_2 ) ;
goto V_28;
}
# endif
if ( V_15 && ! V_16 )
V_16 = 2 ;
if ( V_15 ) {
T_4 * V_45 ;
V_45 = F_13 () ;
if ( V_45 == NULL ) {
F_14 ( V_27 ) ;
goto V_28;
}
F_15 ( V_45 , V_46 , V_27 ) ;
if ( ! F_16 ( NULL , 1 ) && V_9 == NULL ) {
F_5 ( V_27 ,
L_3 ) ;
}
if ( V_9 != NULL )
F_5 ( V_27 , L_4 ,
F_17 ( V_9 ) ) ;
# ifndef F_2
if ( V_10 ) {
T_5 * V_47 = F_18 () ;
F_5 ( V_27 ,
L_5 , V_15 ) ;
if ( V_47 == NULL
|| ! F_19 ( V_47 , V_15 , NULL , 0 , NULL , NULL ,
V_45 ) ) {
F_20 ( V_47 ) ;
F_21 ( V_45 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
V_5 = F_22 ( V_47 ) ;
F_20 ( V_47 ) ;
if ( V_5 == NULL ) {
F_21 ( V_45 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
} else
# endif
{
V_5 = F_23 () ;
F_5 ( V_27 ,
L_6 ,
V_15 , V_16 ) ;
F_5 ( V_27 , L_7 ) ;
if ( V_5 == NULL || ! F_24 ( V_5 , V_15 , V_16 , V_45 ) ) {
F_21 ( V_45 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
}
F_21 ( V_45 ) ;
F_25 ( NULL ) ;
} else {
V_3 = F_26 ( V_6 , 'r' , V_17 ) ;
if ( V_3 == NULL )
goto V_28;
# ifndef F_2
if ( V_10 ) {
T_5 * V_47 ;
if ( V_17 == V_48 )
V_47 = F_27 ( V_3 , NULL ) ;
else
V_47 = F_28 ( V_3 , NULL , NULL , NULL ) ;
if ( V_47 == NULL ) {
F_5 ( V_27 , L_8 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
V_5 = F_22 ( V_47 ) ;
F_20 ( V_47 ) ;
if ( V_5 == NULL ) {
F_14 ( V_27 ) ;
goto V_28;
}
} else
# endif
{
if ( V_17 == V_48 )
V_5 = F_29 ( V_3 , NULL ) ;
else
V_5 = F_30 ( V_3 , NULL , NULL , NULL ) ;
if ( V_5 == NULL ) {
F_5 ( V_27 , L_9 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
}
}
V_4 = F_26 ( V_7 , 'w' , V_19 ) ;
if ( V_4 == NULL )
goto V_28;
if ( V_12 ) {
F_31 ( V_4 , V_5 ) ;
}
if ( V_20 ) {
if ( ! F_32 ( V_5 , & V_11 ) ) {
F_14 ( V_27 ) ;
goto V_28;
}
if ( V_11 & V_49 )
F_5 ( V_27 , L_10 ) ;
if ( V_11 & V_50 )
F_5 ( V_27 , L_11 ) ;
if ( V_11 & V_51 )
F_5 ( V_27 , L_12 ) ;
if ( V_11 & V_52 )
F_5 ( V_27 , L_13 ) ;
if ( V_11 & V_53 )
F_5 ( V_27 , L_14 ) ;
if ( V_11 & V_54 )
F_5 ( V_27 ,
L_15 ) ;
if ( V_11 & V_55 )
F_5 ( V_27 , L_16 ) ;
if ( V_11 == 0 )
F_5 ( V_27 , L_17 ) ;
if ( V_15 != 0 && V_11 != 0 ) {
F_5 ( V_27 , L_18 ) ;
goto V_28;
}
}
if ( V_13 ) {
unsigned char * V_56 ;
int V_57 , V_58 ;
const T_6 * V_59 , * V_60 ;
V_57 = F_33 ( V_5 ) ;
V_58 = F_34 ( V_5 ) ;
F_35 ( V_5 , & V_59 , NULL , & V_60 ) ;
V_56 = F_36 ( V_57 , L_19 ) ;
F_5 ( V_4 , L_20
L_21
L_22
L_23 ) ;
F_5 ( V_4 , L_24 , V_58 ) ;
F_37 ( V_4 , V_59 , L_25 , V_58 , V_56 ) ;
F_37 ( V_4 , V_60 , L_26 , V_58 , V_56 ) ;
F_5 ( V_4 , L_27
L_28
L_23
L_29
L_30 ) ;
F_5 ( V_4 , L_31 ,
V_58 , V_58 ) ;
F_5 ( V_4 , L_32 ,
V_58 , V_58 ) ;
F_5 ( V_4 , L_33
L_34
L_35
L_36
L_37
L_30
L_38 ) ;
if ( F_38 ( V_5 ) > 0 )
F_5 ( V_4 ,
L_39
L_35
L_38 , F_38 ( V_5 ) ) ;
F_5 ( V_4 , L_40 ) ;
F_39 ( V_56 ) ;
}
if ( ! V_21 ) {
const T_6 * V_61 ;
F_35 ( V_5 , NULL , & V_61 , NULL ) ;
if ( V_19 == V_48 )
V_11 = F_40 ( V_4 , V_5 ) ;
else if ( V_61 != NULL )
V_11 = F_41 ( V_4 , V_5 ) ;
else
V_11 = F_42 ( V_4 , V_5 ) ;
if ( ! V_11 ) {
F_5 ( V_27 , L_41 ) ;
F_14 ( V_27 ) ;
goto V_28;
}
}
V_14 = 0 ;
V_28:
F_43 ( V_3 ) ;
F_44 ( V_4 ) ;
F_45 ( V_5 ) ;
return ( V_14 ) ;
}
static int V_46 ( int V_62 , int V_63 , T_4 * V_45 )
{
char V_64 = '*' ;
if ( V_62 == 0 )
V_64 = '.' ;
if ( V_62 == 1 )
V_64 = '+' ;
if ( V_62 == 2 )
V_64 = '*' ;
if ( V_62 == 3 )
V_64 = '\n' ;
F_46 ( F_47 ( V_45 ) , & V_64 , 1 ) ;
( void ) F_48 ( F_47 ( V_45 ) ) ;
return 1 ;
}
