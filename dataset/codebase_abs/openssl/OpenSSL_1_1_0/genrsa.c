int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = F_2 () ;
T_2 V_4 ;
T_3 * V_5 = NULL ;
T_4 * V_6 = F_3 () ;
T_5 * V_7 = NULL ;
const T_4 * V_8 ;
T_6 * V_9 = NULL ;
const T_7 * V_10 = NULL ;
int V_11 = 1 , V_12 = V_13 , V_14 = 0 ;
unsigned long V_15 = V_16 ;
char * V_17 = NULL , * V_18 = NULL , * V_19 = NULL ;
char * V_20 = NULL , * V_21 , * V_22 , * V_23 ;
T_8 V_24 ;
if ( V_6 == NULL || V_3 == NULL )
goto V_25;
F_4 ( V_3 , V_26 , V_27 ) ;
V_21 = F_5 ( V_1 , V_2 , V_28 ) ;
while ( ( V_24 = F_6 () ) != V_29 ) {
switch ( V_24 ) {
case V_29 :
case V_30 :
F_7 ( V_27 , L_1 , V_21 ) ;
goto V_25;
case V_31 :
V_11 = 0 ;
F_8 ( V_28 ) ;
goto V_25;
case V_32 :
V_15 = 3 ;
break;
case V_33 :
V_15 = V_16 ;
break;
case V_34 :
V_17 = F_9 () ;
break;
case V_35 :
V_5 = F_10 ( F_9 () , 0 ) ;
break;
case V_36 :
V_20 = F_9 () ;
break;
case V_37 :
V_18 = F_9 () ;
break;
case V_38 :
if ( ! F_11 ( F_12 () , & V_10 ) )
goto V_25;
break;
}
}
V_1 = F_13 () ;
V_2 = F_14 () ;
V_14 = 1 ;
if ( V_2 [ 0 ] && ( ! F_15 ( V_2 [ 0 ] , & V_12 ) || V_12 <= 0 ) )
goto V_25;
if ( ! F_16 ( NULL , V_18 , NULL , & V_19 ) ) {
F_7 ( V_27 , L_2 ) ;
goto V_25;
}
V_7 = F_17 ( V_17 , V_39 , V_14 ) ;
if ( V_7 == NULL )
goto V_25;
if ( ! F_18 ( NULL , 1 ) && V_20 == NULL
&& ! F_19 () ) {
F_7 ( V_27 ,
L_3 ) ;
}
if ( V_20 != NULL )
F_7 ( V_27 , L_4 ,
F_20 ( V_20 ) ) ;
F_7 ( V_27 , L_5 ,
V_12 ) ;
V_9 = V_5 ? F_21 ( V_5 ) : F_22 () ;
if ( V_9 == NULL )
goto V_25;
if ( ! F_23 ( V_6 , V_15 ) || ! F_24 ( V_9 , V_12 , V_6 , V_3 ) )
goto V_25;
F_25 ( NULL ) ;
F_26 ( V_9 , NULL , & V_8 , NULL ) ;
V_22 = F_27 ( V_8 ) ;
V_23 = F_28 ( V_8 ) ;
if ( V_22 && V_23 ) {
F_7 ( V_27 , L_6 , V_23 , V_22 ) ;
}
F_29 ( V_22 ) ;
F_29 ( V_23 ) ;
V_4 . V_40 = V_19 ;
V_4 . V_41 = V_17 ;
assert ( V_14 ) ;
if ( ! F_30 ( V_7 , V_9 , V_10 , NULL , 0 ,
( V_42 * ) V_43 ,
& V_4 ) )
goto V_25;
V_11 = 0 ;
V_25:
F_31 ( V_6 ) ;
F_32 ( V_3 ) ;
F_33 ( V_9 ) ;
F_34 ( V_7 ) ;
F_29 ( V_19 ) ;
if ( V_11 != 0 )
F_35 ( V_27 ) ;
return ( V_11 ) ;
}
static int V_26 ( int V_44 , int V_45 , T_1 * V_3 )
{
char V_46 = '*' ;
if ( V_44 == 0 )
V_46 = '.' ;
if ( V_44 == 1 )
V_46 = '+' ;
if ( V_44 == 2 )
V_46 = '*' ;
if ( V_44 == 3 )
V_46 = '\n' ;
F_36 ( F_37 ( V_3 ) , & V_46 , 1 ) ;
( void ) F_38 ( F_37 ( V_3 ) ) ;
return 1 ;
}
