int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL , * V_4 = NULL ;
T_2 * V_5 = NULL ;
T_3 * V_6 = NULL ;
T_4 V_7 ;
int V_8 = 0 , V_9 = 1 , V_10 ;
char * V_11 = NULL , * V_12 = NULL , * V_13 ;
V_13 = F_2 ( V_1 , V_2 , V_14 ) ;
while ( ( V_7 = F_3 () ) != V_15 ) {
switch ( V_7 ) {
case V_15 :
case V_16 :
V_17:
F_4 ( V_18 , L_1 , V_13 ) ;
goto V_19;
case V_20 :
V_9 = 0 ;
F_5 ( V_14 ) ;
goto V_19;
case V_21 :
V_8 = 1 ;
break;
case V_22 :
V_11 = F_6 () ;
break;
case V_23 :
V_12 = F_6 () ;
break;
}
}
V_1 = F_7 () ;
if ( V_1 != 0 )
goto V_17;
V_3 = F_8 ( V_11 , 'r' , V_24 ) ;
if ( V_3 == NULL )
goto V_19;
V_4 = F_8 ( V_12 , 'w' , V_24 ) ;
if ( V_4 == NULL )
goto V_19;
if ( V_8 ) {
V_6 = F_9 () ;
if ( V_6 == NULL )
goto V_19;
V_6 -> V_25 = F_10 () ;
if ( V_6 -> V_25 == NULL )
goto V_19;
while ( ( V_5 = F_11 ( V_3 , NULL , NULL , NULL ) ) )
F_12 ( V_6 -> V_25 , V_5 ) ;
if ( ! F_13 ( V_6 -> V_25 ) ) {
F_4 ( V_18 , L_2 ,
V_13 , V_11 ) ;
F_14 ( V_18 ) ;
goto V_19;
}
F_15 ( V_4 , V_6 ) ;
V_9 = 0 ;
goto V_19;
}
V_6 = F_16 ( V_3 , NULL , NULL , NULL ) ;
if ( V_6 == NULL ) {
F_4 ( V_18 , L_3 ,
V_13 , V_11 ) ;
F_14 ( V_18 ) ;
goto V_19;
}
for ( V_10 = 0 ; V_10 < F_13 ( V_6 -> V_25 ) ; V_10 ++ ) {
V_5 = F_17 ( V_6 -> V_25 , V_10 ) ;
F_18 ( V_4 , V_5 ) ;
F_19 ( V_4 , V_5 ) ;
}
V_9 = 0 ;
V_19:
F_20 ( V_3 ) ;
F_21 ( V_4 ) ;
F_22 ( V_6 ) ;
return ( V_9 ) ;
}
