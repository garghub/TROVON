union V_1 F_1 ( char * V_2 , union V_1 V_3 )
{
int V_4 ;
F_2 ( L_1 , V_2 ) ;
F_2 ( L_2 , ( unsigned ) ( V_3 . V_5 >> 32 ) ,
( unsigned ) V_3 . V_5 ) ;
F_2 ( L_3 ) ;
switch ( F_3 ( V_3 ) ) {
case V_6 :
case V_7 :
F_2 ( L_4 , F_4 ( V_3 ) ? '-' : '+' ) ;
for ( V_4 = V_8 - 1 ; V_4 >= 0 ; V_4 -- )
F_2 ( L_5 , F_5 ( V_3 ) & F_6 ( V_4 ) ? '1' : '0' ) ;
break;
case V_9 :
F_2 ( L_6 , F_4 ( V_3 ) ? '-' : '+' ) ;
break;
case V_10 :
F_2 ( L_7 , F_4 ( V_3 ) ? '-' : '+' ) ;
break;
case V_11 :
F_2 ( L_8 , F_4 ( V_3 ) ? '-' : '+' ) ;
for ( V_4 = V_8 - 1 ; V_4 >= 0 ; V_4 -- )
F_2 ( L_5 , F_5 ( V_3 ) & F_6 ( V_4 ) ? '1' : '0' ) ;
F_2 ( L_9 , F_7 ( V_3 ) - V_12 ) ;
break;
case V_13 :
F_2 ( L_10 , F_4 ( V_3 ) ? '-' : '+' ) ;
for ( V_4 = V_8 - 1 ; V_4 >= 0 ; V_4 -- )
F_2 ( L_5 , F_5 ( V_3 ) & F_6 ( V_4 ) ? '1' : '0' ) ;
F_2 ( L_9 , F_7 ( V_3 ) - V_12 ) ;
break;
default:
F_2 ( L_11 ) ;
}
F_2 ( L_12 ) ;
return V_3 ;
}
union V_14 F_8 ( char * V_2 , union V_14 V_3 )
{
int V_4 ;
F_2 ( L_13 , V_2 ) ;
F_2 ( L_14 , ( unsigned ) V_3 . V_5 ) ;
F_2 ( L_3 ) ;
switch ( F_9 ( V_3 ) ) {
case V_6 :
case V_7 :
F_2 ( L_4 , F_10 ( V_3 ) ? '-' : '+' ) ;
for ( V_4 = V_15 - 1 ; V_4 >= 0 ; V_4 -- )
F_2 ( L_5 , F_11 ( V_3 ) & F_12 ( V_4 ) ? '1' : '0' ) ;
break;
case V_9 :
F_2 ( L_6 , F_10 ( V_3 ) ? '-' : '+' ) ;
break;
case V_10 :
F_2 ( L_7 , F_10 ( V_3 ) ? '-' : '+' ) ;
break;
case V_11 :
F_2 ( L_8 , F_10 ( V_3 ) ? '-' : '+' ) ;
for ( V_4 = V_15 - 1 ; V_4 >= 0 ; V_4 -- )
F_2 ( L_5 , F_11 ( V_3 ) & F_12 ( V_4 ) ? '1' : '0' ) ;
F_2 ( L_9 , F_13 ( V_3 ) - V_16 ) ;
break;
case V_13 :
F_2 ( L_10 , F_10 ( V_3 ) ? '-' : '+' ) ;
for ( V_4 = V_15 - 1 ; V_4 >= 0 ; V_4 -- )
F_2 ( L_5 , F_11 ( V_3 ) & F_12 ( V_4 ) ? '1' : '0' ) ;
F_2 ( L_9 , F_13 ( V_3 ) - V_16 ) ;
break;
default:
F_2 ( L_11 ) ;
}
F_2 ( L_12 ) ;
return V_3 ;
}
