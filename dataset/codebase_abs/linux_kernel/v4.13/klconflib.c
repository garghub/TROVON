void
F_1 ( char * V_1 , T_1 V_2 , int V_3 )
{
int V_4 , V_5 ;
unsigned char V_6 ;
V_4 = F_2 ( V_2 ) ;
V_6 = F_3 ( V_2 ) ;
switch ( V_6 )
{
case V_7 :
case V_8 :
V_6 = V_9 ;
break;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
V_6 = V_14 ;
break;
case V_15 :
case V_16 :
V_6 = V_17 ;
break;
}
V_5 = F_4 ( V_2 ) ;
if ( ( V_3 == V_18 ) || ( V_3 == V_19 ) ) {
* V_1 ++ = '0' + F_5 ( V_4 ) ;
* V_1 ++ = '0' + F_6 ( V_4 ) ;
* V_1 ++ = '0' + F_7 ( V_4 ) ;
* V_1 ++ = V_6 ;
}
else if ( V_3 == V_20 ) {
strcpy ( V_1 , L_1 L_2 ) ; V_1 += strlen ( V_1 ) ;
* V_1 ++ = '0' + F_5 ( V_4 ) ;
* V_1 ++ = '0' + F_6 ( V_4 ) ;
* V_1 ++ = '0' + F_7 ( V_4 ) ;
strcpy ( V_1 , L_2 L_3 L_2 ) ; V_1 += strlen ( V_1 ) ;
}
if ( V_5 < 10 )
* V_1 ++ = '0' ;
sprintf ( V_1 , L_4 , V_5 ) ;
}
