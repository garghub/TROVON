int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL ;
F_2 ( V_7 ) * V_8 = NULL ;
F_2 ( V_9 ) * V_10 = NULL ;
F_2 ( V_11 ) * V_12 = NULL ;
V_11 * V_13 = NULL ;
char * V_14 = NULL , * V_15 = NULL , * V_16 , * V_17 ;
int V_18 = 0 , V_19 = V_20 , V_21 = V_20 , V_22 = 1 , V_23 =
0 ;
T_4 V_24 ;
V_16 = F_3 ( V_1 , V_2 , V_25 ) ;
while ( ( V_24 = F_4 () ) != V_26 ) {
switch ( V_24 ) {
case V_26 :
case V_27 :
V_28:
F_5 ( V_29 , L_1 , V_16 ) ;
goto V_30;
case V_31 :
F_6 ( V_25 ) ;
V_22 = 0 ;
goto V_30;
case V_32 :
if ( ! F_7 ( F_8 () , V_33 , & V_19 ) )
goto V_28;
break;
case V_34 :
if ( ! F_7 ( F_8 () , V_33 , & V_21 ) )
goto V_28;
break;
case V_35 :
V_14 = F_8 () ;
break;
case V_36 :
V_15 = F_8 () ;
break;
case V_37 :
V_23 = 1 ;
break;
case V_38 :
if ( ( V_8 == NULL )
&& ( V_8 = F_9 () ) == NULL )
goto V_30;
if ( ! F_10 ( V_8 , F_8 () ) )
goto V_30;
break;
}
}
V_1 = F_11 () ;
if ( V_1 != 0 )
goto V_28;
if ( ! V_23 ) {
V_3 = F_12 ( V_14 , 'r' , V_19 ) ;
if ( V_3 == NULL )
goto V_30;
if ( V_19 == V_39 )
V_13 = F_13 ( V_3 , NULL ) ;
else if ( V_19 == V_20 )
V_13 = F_14 ( V_3 , NULL , NULL , NULL ) ;
if ( V_13 == NULL ) {
F_5 ( V_29 , L_2 ) ;
F_15 ( V_29 ) ;
goto V_30;
}
}
if ( ( V_5 = F_16 () ) == NULL )
goto V_30;
if ( ( V_6 = F_17 () ) == NULL )
goto V_30;
V_5 -> type = F_18 ( V_40 ) ;
V_5 -> V_41 . V_42 = V_6 ;
V_6 -> V_43 -> type = F_18 ( V_44 ) ;
if ( ! F_19 ( V_6 -> V_45 , 1 ) )
goto V_30;
if ( ( V_12 = F_20 () ) == NULL )
goto V_30;
V_6 -> V_13 = V_12 ;
if ( V_13 != NULL ) {
F_21 ( V_12 , V_13 ) ;
V_13 = NULL ;
}
if ( ( V_10 = F_22 () ) == NULL )
goto V_30;
V_6 -> V_46 = V_10 ;
if ( V_8 )
for ( V_18 = 0 ; V_18 < F_23 ( V_8 ) ; V_18 ++ ) {
V_17 = F_24 ( V_8 , V_18 ) ;
if ( F_25 ( V_10 , V_17 ) < 0 ) {
F_5 ( V_29 , L_3 ) ;
F_15 ( V_29 ) ;
goto V_30;
}
}
V_4 = F_12 ( V_15 , 'w' , V_21 ) ;
if ( V_4 == NULL )
goto V_30;
if ( V_21 == V_39 )
V_18 = F_26 ( V_4 , V_5 ) ;
else if ( V_21 == V_20 )
V_18 = F_27 ( V_4 , V_5 ) ;
if ( ! V_18 ) {
F_5 ( V_29 , L_4 ) ;
F_15 ( V_29 ) ;
goto V_30;
}
V_22 = 0 ;
V_30:
F_28 ( V_8 ) ;
F_29 ( V_3 ) ;
F_30 ( V_4 ) ;
F_31 ( V_5 ) ;
F_32 ( V_13 ) ;
return ( V_22 ) ;
}
