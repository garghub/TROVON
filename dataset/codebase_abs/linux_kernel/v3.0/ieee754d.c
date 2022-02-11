T_1 F_1 ( char * V_1 , T_1 V_2 )
{
int V_3 ;
F_2 ( L_1 , V_1 ) ;
F_2 ( L_2 , ( unsigned ) ( V_2 . V_4 >> 32 ) ,
( unsigned ) V_2 . V_4 ) ;
F_2 ( L_3 ) ;
switch ( F_3 ( V_2 ) ) {
case V_5 :
case V_6 :
F_2 ( L_4 , F_4 ( V_2 ) ? '-' : '+' ) ;
for ( V_3 = V_7 - 1 ; V_3 >= 0 ; V_3 -- )
F_2 ( L_5 , F_5 ( V_2 ) & F_6 ( V_3 ) ? '1' : '0' ) ;
break;
case V_8 :
F_2 ( L_6 , F_4 ( V_2 ) ? '-' : '+' ) ;
break;
case V_9 :
F_2 ( L_7 , F_4 ( V_2 ) ? '-' : '+' ) ;
break;
case V_10 :
F_2 ( L_8 , F_4 ( V_2 ) ? '-' : '+' ) ;
for ( V_3 = V_7 - 1 ; V_3 >= 0 ; V_3 -- )
F_2 ( L_5 , F_5 ( V_2 ) & F_6 ( V_3 ) ? '1' : '0' ) ;
F_2 ( L_9 , F_7 ( V_2 ) - V_11 ) ;
break;
case V_12 :
F_2 ( L_10 , F_4 ( V_2 ) ? '-' : '+' ) ;
for ( V_3 = V_7 - 1 ; V_3 >= 0 ; V_3 -- )
F_2 ( L_5 , F_5 ( V_2 ) & F_6 ( V_3 ) ? '1' : '0' ) ;
F_2 ( L_9 , F_7 ( V_2 ) - V_11 ) ;
break;
default:
F_2 ( L_11 ) ;
}
F_2 ( L_12 ) ;
return V_2 ;
}
T_2 F_8 ( char * V_1 , T_2 V_2 )
{
int V_3 ;
F_2 ( L_13 , V_1 ) ;
F_2 ( L_14 , ( unsigned ) V_2 . V_4 ) ;
F_2 ( L_3 ) ;
switch ( F_9 ( V_2 ) ) {
case V_5 :
case V_6 :
F_2 ( L_4 , F_10 ( V_2 ) ? '-' : '+' ) ;
for ( V_3 = V_13 - 1 ; V_3 >= 0 ; V_3 -- )
F_2 ( L_5 , F_11 ( V_2 ) & F_12 ( V_3 ) ? '1' : '0' ) ;
break;
case V_8 :
F_2 ( L_6 , F_10 ( V_2 ) ? '-' : '+' ) ;
break;
case V_9 :
F_2 ( L_7 , F_10 ( V_2 ) ? '-' : '+' ) ;
break;
case V_10 :
F_2 ( L_8 , F_10 ( V_2 ) ? '-' : '+' ) ;
for ( V_3 = V_13 - 1 ; V_3 >= 0 ; V_3 -- )
F_2 ( L_5 , F_11 ( V_2 ) & F_12 ( V_3 ) ? '1' : '0' ) ;
F_2 ( L_9 , F_13 ( V_2 ) - V_14 ) ;
break;
case V_12 :
F_2 ( L_10 , F_10 ( V_2 ) ? '-' : '+' ) ;
for ( V_3 = V_13 - 1 ; V_3 >= 0 ; V_3 -- )
F_2 ( L_5 , F_11 ( V_2 ) & F_12 ( V_3 ) ? '1' : '0' ) ;
F_2 ( L_9 , F_13 ( V_2 ) - V_14 ) ;
break;
default:
F_2 ( L_11 ) ;
}
F_2 ( L_12 ) ;
return V_2 ;
}
