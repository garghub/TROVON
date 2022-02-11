int F_1 ( int V_1 , char * * V_2 )
{
T_1 * V_3 = NULL ;
int V_4 = 0 , V_5 = 20 , V_6 = 0 , V_7 = 0 , V_8 = 0 , V_9 = 1 ;
char * V_10 ;
T_2 V_11 ;
V_10 = F_2 ( V_1 , V_2 , V_12 ) ;
while ( ( V_11 = F_3 () ) != V_13 ) {
switch ( V_11 ) {
case V_13 :
case V_14 :
F_4 ( V_15 , L_1 , V_10 ) ;
goto V_16;
case V_17 :
F_5 ( V_12 ) ;
V_9 = 0 ;
goto V_16;
case V_18 :
V_4 = 1 ;
break;
case V_19 :
V_6 = 1 ;
break;
case V_20 :
V_7 = atoi ( F_6 () ) ;
break;
case V_21 :
V_8 = 1 ;
break;
case V_22 :
V_5 = atoi ( F_6 () ) ;
break;
}
}
V_1 = F_7 () ;
V_2 = F_8 () ;
if ( V_1 == 0 && ! V_6 ) {
F_4 ( V_15 , L_2 , V_10 ) ;
goto V_16;
}
if ( V_6 ) {
char * V_23 ;
if ( ! V_7 ) {
F_4 ( V_15 , L_3 ) ;
goto V_16;
}
V_3 = F_9 () ;
if ( V_3 == NULL ) {
F_4 ( V_15 , L_4 ) ;
goto V_16;
}
if ( ! F_10 ( V_3 , V_7 , V_8 , NULL , NULL , NULL ) ) {
F_4 ( V_15 , L_5 ) ;
goto V_16;
}
V_23 = V_4 ? F_11 ( V_3 ) : F_12 ( V_3 ) ;
if ( V_23 == NULL ) {
F_4 ( V_15 , L_4 ) ;
goto V_16;
}
F_4 ( V_24 , L_6 , V_23 ) ;
F_13 ( V_23 ) ;
} else {
for ( ; * V_2 ; V_2 ++ ) {
int V_25 ;
if ( V_4 )
V_25 = F_14 ( & V_3 , V_2 [ 0 ] ) ;
else
V_25 = F_15 ( & V_3 , V_2 [ 0 ] ) ;
if( ! V_25 ) {
F_4 ( V_15 , L_7 , V_2 [ 0 ] ) ;
goto V_16;
}
F_16 ( V_24 , V_3 ) ;
F_4 ( V_24 , L_8 ,
V_2 [ 0 ] ,
F_17 ( V_3 , V_5 , NULL , NULL )
? L_9 : L_10 ) ;
}
}
V_9 = 0 ;
V_16:
F_18 ( V_3 ) ;
return V_9 ;
}
