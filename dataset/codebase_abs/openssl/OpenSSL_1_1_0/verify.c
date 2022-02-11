int F_1 ( int V_1 , char * * V_2 )
{
F_2 ( V_3 ) * V_4 = NULL , * V_5 = NULL ;
F_2 ( V_6 ) * V_7 = NULL ;
T_1 * V_8 = NULL ;
T_2 * V_9 = NULL ;
const char * V_10 , * V_11 = NULL , * V_12 = NULL ;
int V_13 = 0 , V_14 = 0 ;
int V_15 = 0 , V_16 = 0 , V_17 = 0 , V_18 = 0 , V_19 = 1 ;
T_3 V_20 ;
if ( ( V_9 = F_3 () ) == NULL )
goto V_21;
V_10 = F_4 ( V_1 , V_2 , V_22 ) ;
while ( ( V_20 = F_5 () ) != V_23 ) {
switch ( V_20 ) {
case V_23 :
case V_24 :
F_6 ( V_25 , L_1 , V_10 ) ;
goto V_21;
case V_26 :
F_7 ( V_22 ) ;
F_6 ( V_25 , L_2 ) ;
for ( V_18 = 0 ; V_18 < F_8 () ; V_18 ++ ) {
T_4 * V_27 ;
V_27 = F_9 ( V_18 ) ;
F_6 ( V_25 , L_3 ,
F_10 ( V_27 ) ,
F_11 ( V_27 ) ) ;
}
F_6 ( V_25 , L_4 ) ;
for ( V_18 = 0 ; V_18 < F_12 () ; V_18 ++ ) {
const T_2 * V_28 ;
V_28 = F_13 ( V_18 ) ;
F_6 ( V_25 , L_5 ,
F_14 ( V_28 ) ) ;
}
V_19 = 0 ;
goto V_21;
case V_29 :
if ( ! F_15 ( V_20 , V_9 ) )
goto V_21;
V_15 ++ ;
break;
case V_30 :
V_11 = F_16 () ;
break;
case V_31 :
V_12 = F_16 () ;
break;
case V_32 :
V_13 = 1 ;
break;
case V_33 :
V_14 = 1 ;
break;
case V_34 :
if ( ! F_17 ( F_16 () , & V_4 , V_35 , NULL ,
L_6 ) )
goto V_21;
break;
case V_36 :
V_14 = 1 ;
V_13 = 1 ;
if ( ! F_17 ( F_16 () , & V_5 , V_35 , NULL ,
L_7 ) )
goto V_21;
break;
case V_37 :
if ( ! F_18 ( F_16 () , & V_7 , V_35 , NULL ,
L_8 ) )
goto V_21;
break;
case V_38 :
V_16 = 1 ;
break;
case V_39 :
if ( F_19 ( F_16 () , 0 ) == NULL ) {
goto V_21;
}
break;
case V_40 :
V_17 = 1 ;
break;
case V_41 :
V_42 = 1 ;
break;
}
}
V_1 = F_20 () ;
V_2 = F_21 () ;
if ( V_5 != NULL && ( V_12 || V_11 ) ) {
F_6 ( V_25 ,
L_9 ,
V_10 ) ;
goto V_21;
}
if ( ( V_8 = F_22 ( V_12 , V_11 , V_14 , V_13 ) ) == NULL )
goto V_21;
F_23 ( V_8 , V_43 ) ;
if ( V_15 )
F_24 ( V_8 , V_9 ) ;
F_25 () ;
if ( V_16 )
F_26 ( V_8 ) ;
V_19 = 0 ;
if ( V_1 < 1 ) {
if ( F_27 ( V_8 , NULL , V_4 , V_5 , V_7 , V_17 ) != 1 )
V_19 = - 1 ;
} else {
for ( V_18 = 0 ; V_18 < V_1 ; V_18 ++ )
if ( F_27 ( V_8 , V_2 [ V_18 ] , V_4 , V_5 , V_7 ,
V_17 ) != 1 )
V_19 = - 1 ;
}
V_21:
F_28 ( V_9 ) ;
F_29 ( V_8 ) ;
F_30 ( V_4 , V_44 ) ;
F_30 ( V_5 , V_44 ) ;
F_31 ( V_7 , V_45 ) ;
return ( V_19 < 0 ? 2 : V_19 ) ;
}
static int V_43 ( int V_46 , T_5 * V_47 )
{
int V_48 = F_32 ( V_47 ) ;
V_3 * V_49 = F_33 ( V_47 ) ;
if ( ! V_46 ) {
if ( V_49 ) {
F_34 ( V_25 ,
F_35 ( V_49 ) ,
0 , V_50 ) ;
F_6 ( V_25 , L_10 ) ;
}
F_6 ( V_25 , L_11 ,
F_36 ( V_47 ) ? L_12 : L_13 ,
V_48 ,
F_37 ( V_47 ) ,
F_38 ( V_48 ) ) ;
switch ( V_48 ) {
case V_51 :
F_39 ( V_47 ) ;
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_46 = 1 ;
}
return V_46 ;
}
if ( V_48 == V_61 && V_46 == 2 )
F_39 ( V_47 ) ;
if ( ! V_42 )
F_25 () ;
return ( V_46 ) ;
}
