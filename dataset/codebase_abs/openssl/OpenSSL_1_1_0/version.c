int F_1 ( int V_1 , char * * V_2 )
{
int V_3 = 1 , V_4 = 0 ;
int V_5 = 0 , V_6 = 0 , V_7 = 0 , V_8 = 0 , V_9 = 0 , V_10 = 0 ;
int V_11 = 0 ;
char * V_12 ;
T_1 V_13 ;
V_12 = F_2 ( V_1 , V_2 , V_14 ) ;
while ( ( V_13 = F_3 () ) != V_15 ) {
switch ( V_13 ) {
case V_15 :
case V_16 :
F_4 ( V_17 , L_1 , V_12 ) ;
goto V_18;
case V_19 :
F_5 ( V_14 ) ;
V_3 = 0 ;
goto V_18;
case V_20 :
V_4 = V_7 = 1 ;
break;
case V_21 :
V_4 = V_10 = 1 ;
break;
case V_22 :
V_4 = V_11 = 1 ;
break;
case V_23 :
V_4 = V_5 = 1 ;
break;
case V_24 :
V_4 = V_8 = 1 ;
break;
case V_25 :
V_4 = V_9 = 1 ;
break;
case V_26 :
V_4 = V_6 = 1 ;
break;
case V_27 :
V_5 = V_6 = V_7 = V_9 = V_10 = V_11 = 1 ;
break;
}
}
if ( ! V_4 )
V_6 = 1 ;
if ( V_6 ) {
if ( F_6 () == V_28 ) {
printf ( L_2 , F_7 ( V_29 ) ) ;
} else {
printf ( L_3 ,
V_30 , F_7 ( V_29 ) ) ;
}
}
if ( V_7 )
printf ( L_2 , F_7 ( V_31 ) ) ;
if ( V_9 )
printf ( L_2 , F_7 ( V_32 ) ) ;
if ( V_8 ) {
printf ( L_4 ) ;
printf ( L_5 , F_8 () ) ;
#ifndef F_9
printf ( L_5 , F_10 () ) ;
#endif
#ifndef F_11
printf ( L_5 , F_12 () ) ;
#endif
#ifndef F_13
printf ( L_5 , F_14 () ) ;
#endif
#ifndef F_15
printf ( L_5 , F_16 () ) ;
#endif
#ifndef F_17
printf ( L_5 , F_18 () ) ;
#endif
printf ( L_6 ) ;
}
if ( V_5 )
printf ( L_2 , F_7 ( V_33 ) ) ;
if ( V_10 )
printf ( L_2 , F_7 ( V_34 ) ) ;
if ( V_11 )
printf ( L_2 , F_7 ( V_35 ) ) ;
V_3 = 0 ;
V_18:
return ( V_3 ) ;
}
