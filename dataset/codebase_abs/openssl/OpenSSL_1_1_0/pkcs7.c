int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
T_2 * V_4 = NULL , * V_5 = NULL ;
int V_6 = V_7 , V_8 = V_7 ;
char * V_9 = NULL , * V_10 = NULL , * V_11 ;
int V_12 , V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 0 , V_17 = 1 ;
T_3 V_18 ;
V_11 = F_2 ( V_1 , V_2 , V_19 ) ;
while ( ( V_18 = F_3 () ) != V_20 ) {
switch ( V_18 ) {
case V_20 :
case V_21 :
V_22:
F_4 ( V_23 , L_1 , V_11 ) ;
goto V_24;
case V_25 :
F_5 ( V_19 ) ;
V_17 = 0 ;
goto V_24;
case V_26 :
if ( ! F_6 ( F_7 () , V_27 , & V_6 ) )
goto V_22;
break;
case V_28 :
if ( ! F_6 ( F_7 () , V_27 , & V_8 ) )
goto V_22;
break;
case V_29 :
V_9 = F_7 () ;
break;
case V_30 :
V_10 = F_7 () ;
break;
case V_31 :
V_15 = 1 ;
break;
case V_32 :
V_14 = 1 ;
break;
case V_33 :
V_16 = 1 ;
break;
case V_34 :
V_13 = 1 ;
break;
case V_35 :
( void ) F_8 ( F_7 () , 0 ) ;
break;
}
}
V_1 = F_9 () ;
if ( V_1 != 0 )
goto V_22;
V_4 = F_10 ( V_9 , 'r' , V_6 ) ;
if ( V_4 == NULL )
goto V_24;
if ( V_6 == V_36 )
V_3 = F_11 ( V_4 , NULL ) ;
else
V_3 = F_12 ( V_4 , NULL , NULL , NULL ) ;
if ( V_3 == NULL ) {
F_4 ( V_23 , L_2 ) ;
F_13 ( V_23 ) ;
goto V_24;
}
V_5 = F_10 ( V_10 , 'w' , V_8 ) ;
if ( V_5 == NULL )
goto V_24;
if ( V_16 )
F_14 ( V_5 , V_3 , 0 , NULL ) ;
if ( V_13 ) {
F_15 ( V_37 ) * V_38 = NULL ;
F_15 ( V_39 ) * V_40 = NULL ;
V_12 = F_16 ( V_3 -> type ) ;
switch ( V_12 ) {
case V_41 :
if ( V_3 -> V_42 . V_43 != NULL ) {
V_38 = V_3 -> V_42 . V_43 -> V_44 ;
V_40 = V_3 -> V_42 . V_43 -> V_45 ;
}
break;
case V_46 :
if ( V_3 -> V_42 . V_47 != NULL ) {
V_38 = V_3 -> V_42 . V_47 -> V_44 ;
V_40 = V_3 -> V_42 . V_47 -> V_45 ;
}
break;
default:
break;
}
if ( V_38 != NULL ) {
V_37 * V_48 ;
for ( V_12 = 0 ; V_12 < F_17 ( V_38 ) ; V_12 ++ ) {
V_48 = F_18 ( V_38 , V_12 ) ;
if ( V_14 )
F_19 ( V_5 , V_48 ) ;
else
F_20 ( V_5 , V_48 ) ;
if ( ! V_15 )
F_21 ( V_5 , V_48 ) ;
F_22 ( V_5 , L_3 ) ;
}
}
if ( V_40 != NULL ) {
V_39 * V_45 ;
for ( V_12 = 0 ; V_12 < F_23 ( V_40 ) ; V_12 ++ ) {
V_45 = F_24 ( V_40 , V_12 ) ;
F_25 ( V_5 , V_45 ) ;
if ( ! V_15 )
F_26 ( V_5 , V_45 ) ;
F_22 ( V_5 , L_3 ) ;
}
}
V_17 = 0 ;
goto V_24;
}
if ( ! V_15 ) {
if ( V_8 == V_36 )
V_12 = F_27 ( V_5 , V_3 ) ;
else
V_12 = F_28 ( V_5 , V_3 ) ;
if ( ! V_12 ) {
F_4 ( V_23 , L_4 ) ;
F_13 ( V_23 ) ;
goto V_24;
}
}
V_17 = 0 ;
V_24:
F_29 ( V_3 ) ;
F_30 ( V_4 ) ;
F_31 ( V_5 ) ;
return ( V_17 ) ;
}
