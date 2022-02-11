int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL ;
T_3 * V_5 = NULL ;
char * V_6 = NULL , * V_7 = NULL , * V_8 = NULL , * V_9 ;
int V_10 = V_11 , V_12 = V_11 ;
int V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 1 , V_17 , V_18 = 0 ;
T_4 V_19 ;
V_9 = F_2 ( V_1 , V_2 , V_20 ) ;
while ( ( V_19 = F_3 () ) != V_21 ) {
switch ( V_19 ) {
case V_21 :
case V_22 :
V_23:
F_4 ( V_24 , L_1 , V_9 ) ;
goto V_25;
case V_26 :
F_5 ( V_20 ) ;
V_16 = 0 ;
goto V_25;
case V_27 :
if ( ! F_6 ( F_7 () , V_28 , & V_10 ) )
goto V_23;
break;
case V_29 :
if ( ! F_6 ( F_7 () , V_28 | V_30 ,
& V_12 ) )
goto V_23;
break;
case V_31 :
V_6 = F_7 () ;
break;
case V_32 :
V_7 = F_7 () ;
break;
case V_33 :
V_15 = ++ V_18 ;
break;
case V_34 :
V_13 = ++ V_18 ;
break;
case V_35 :
V_14 = ++ V_18 ;
break;
case V_36 :
V_8 = F_7 () ;
break;
}
}
V_1 = F_8 () ;
if ( V_1 != 0 )
goto V_23;
V_3 = F_9 ( V_6 , V_10 ) ;
if ( V_3 == NULL ) {
goto V_25;
}
V_4 = F_10 ( V_3 ) ;
if ( V_8 ) {
T_5 V_37 = strlen ( V_8 ) ;
if ( V_37 > V_38 ) {
F_4 ( V_24 , L_2 ) ;
goto V_25;
}
if ( ! F_11 ( V_3 , ( unsigned char * ) V_8 ,
V_37 ) ) {
F_4 ( V_24 , L_3 ) ;
goto V_25;
}
}
if ( ! V_14 || V_15 ) {
V_5 = F_12 ( V_7 , 'w' , V_12 ) ;
if ( V_5 == NULL )
goto V_25;
}
if ( V_15 ) {
F_13 ( V_5 , V_3 ) ;
if ( V_13 ) {
if ( V_4 == NULL )
F_14 ( V_5 , L_4 ) ;
else
F_15 ( V_5 , V_4 ) ;
}
}
if ( ! V_14 && ! V_13 ) {
if ( V_12 == V_39 )
V_17 = F_16 ( V_5 , V_3 ) ;
else if ( V_12 == V_11 )
V_17 = F_17 ( V_5 , V_3 ) ;
else if ( V_12 == V_40 )
V_17 = F_18 ( V_5 , V_3 ) ;
else {
F_4 ( V_24 , L_5 ) ;
goto V_25;
}
if ( ! V_17 ) {
F_4 ( V_24 , L_6 ) ;
goto V_25;
}
} else if ( ! V_14 && ( V_4 != NULL ) ) {
if ( V_12 == V_39 )
V_17 = ( int ) F_19 ( V_5 , V_4 ) ;
else if ( V_12 == V_11 )
V_17 = F_20 ( V_5 , V_4 ) ;
else {
F_4 ( V_24 , L_5 ) ;
goto V_25;
}
if ( ! V_17 ) {
F_4 ( V_24 , L_7 ) ;
goto V_25;
}
}
V_16 = 0 ;
V_25:
F_21 ( V_5 ) ;
F_22 ( V_3 ) ;
return ( V_16 ) ;
}
static T_1 * F_9 ( char * V_6 , int V_41 )
{
T_1 * V_3 = NULL ;
T_3 * V_42 = NULL ;
V_42 = F_12 ( V_6 , 'r' , V_41 ) ;
if ( V_42 == NULL )
goto V_25;
if ( V_41 == V_39 )
V_3 = F_23 ( V_42 , NULL ) ;
else
V_3 = F_24 ( V_42 , NULL , NULL , NULL ) ;
if ( V_3 == NULL ) {
F_4 ( V_24 , L_8 ) ;
F_25 ( V_24 ) ;
goto V_25;
}
V_25:
F_26 ( V_42 ) ;
return ( V_3 ) ;
}
