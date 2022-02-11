int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_4 * V_7 = NULL ;
T_5 * V_8 ;
char * V_9 = NULL , * V_10 = NULL , * V_11 = NULL ;
char * V_12 = NULL , * V_13 = NULL , * V_14 ;
char V_15 = V_16 , V_17 = V_18 ;
unsigned char * V_19 = NULL , * V_20 = NULL , V_21 = V_22 ;
int V_23 , V_24 = V_25 , V_26 , V_27 = 1 ;
int V_28 = 0 , V_29 = 0 , V_30 = 0 , V_31 = 0 , V_32 = 0 ;
T_6 V_33 ;
V_14 = F_2 ( V_1 , V_2 , V_34 ) ;
while ( ( V_33 = F_3 () ) != V_35 ) {
switch ( V_33 ) {
case V_35 :
case V_36 :
V_37:
F_4 ( V_38 , L_1 , V_14 ) ;
goto V_39;
case V_40 :
F_5 ( V_34 ) ;
V_27 = 0 ;
goto V_39;
case V_41 :
if ( ! F_6 ( F_7 () , V_42 , & V_24 ) )
goto V_37;
break;
case V_43 :
V_9 = F_7 () ;
break;
case V_44 :
V_10 = F_7 () ;
break;
case V_45 :
V_5 = F_8 ( F_7 () , 0 ) ;
break;
case V_46 :
V_30 = 1 ;
break;
case V_47 :
V_29 = 1 ;
break;
case V_48 :
V_21 = V_49 ;
break;
case V_50 :
V_21 = V_51 ;
break;
case V_52 :
V_21 = V_53 ;
break;
case V_54 :
V_21 = V_22 ;
break;
case V_55 :
V_21 = V_56 ;
break;
case V_57 :
V_15 = V_58 ;
V_31 = 1 ;
break;
case V_59 :
V_15 = V_16 ;
break;
case V_60 :
V_32 = 1 ;
break;
case V_61 :
V_15 = V_62 ;
break;
case V_63 :
V_15 = V_64 ;
V_31 = 1 ;
break;
case V_65 :
V_17 = V_66 ;
break;
case V_67 :
V_17 = V_68 ;
break;
case V_69 :
V_11 = F_7 () ;
break;
case V_70 :
V_12 = F_7 () ;
break;
}
}
V_1 = F_9 () ;
if ( V_1 != 0 )
goto V_37;
if ( V_31 && ( V_17 != V_18 ) ) {
F_4 ( V_38 , L_2 ) ;
goto V_39;
}
if ( ! F_10 ( V_12 , NULL , & V_13 , NULL ) ) {
F_4 ( V_38 , L_3 ) ;
goto V_39;
}
F_11 ( NULL , 0 ) ;
switch ( V_17 ) {
case V_18 :
V_6 = F_12 ( V_11 , V_24 , 0 , V_13 , V_5 , L_4 ) ;
break;
case V_66 :
V_6 = F_13 ( V_11 , V_24 , 0 , NULL , V_5 , L_5 ) ;
break;
case V_68 :
V_8 = F_14 ( V_11 , V_24 , L_6 ) ;
if ( V_8 ) {
V_6 = F_15 ( V_8 ) ;
F_16 ( V_8 ) ;
}
break;
}
if ( ! V_6 ) {
return 1 ;
}
V_7 = F_17 ( V_6 ) ;
F_18 ( V_6 ) ;
if ( ! V_7 ) {
F_4 ( V_38 , L_7 ) ;
F_19 ( V_38 ) ;
goto V_39;
}
V_3 = F_20 ( V_9 , 'r' , V_71 ) ;
if ( V_3 == NULL )
goto V_39;
V_4 = F_20 ( V_10 , 'w' , V_71 ) ;
if ( V_4 == NULL )
goto V_39;
V_26 = F_21 ( V_7 ) ;
V_19 = F_22 ( V_26 * 2 , L_8 ) ;
V_20 = F_22 ( V_26 , L_9 ) ;
V_23 = F_23 ( V_3 , V_19 , V_26 * 2 ) ;
if ( V_23 < 0 ) {
F_4 ( V_38 , L_10 ) ;
goto V_39;
}
if ( V_32 ) {
int V_72 ;
unsigned char V_73 ;
for ( V_72 = 0 ; V_72 < V_23 / 2 ; V_72 ++ ) {
V_73 = V_19 [ V_72 ] ;
V_19 [ V_72 ] = V_19 [ V_23 - 1 - V_72 ] ;
V_19 [ V_23 - 1 - V_72 ] = V_73 ;
}
}
switch ( V_15 ) {
case V_16 :
V_28 = F_24 ( V_23 , V_19 , V_20 , V_7 , V_21 ) ;
break;
case V_58 :
V_28 =
F_25 ( V_23 , V_19 , V_20 , V_7 , V_21 ) ;
break;
case V_62 :
V_28 = F_26 ( V_23 , V_19 , V_20 , V_7 , V_21 ) ;
break;
case V_64 :
V_28 =
F_27 ( V_23 , V_19 , V_20 , V_7 , V_21 ) ;
break;
}
if ( V_28 < 0 ) {
F_4 ( V_38 , L_11 ) ;
F_19 ( V_38 ) ;
goto V_39;
}
V_27 = 0 ;
if ( V_30 ) {
if ( ! F_28 ( V_4 , V_20 , V_28 , 1 , - 1 ) ) {
F_19 ( V_38 ) ;
}
} else if ( V_29 )
F_29 ( V_4 , ( char * ) V_20 , V_28 ) ;
else
F_30 ( V_4 , V_20 , V_28 ) ;
V_39:
F_31 ( V_7 ) ;
F_32 ( V_3 ) ;
F_33 ( V_4 ) ;
F_34 ( V_19 ) ;
F_34 ( V_20 ) ;
F_34 ( V_13 ) ;
return V_27 ;
}
