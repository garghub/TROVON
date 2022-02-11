long T_1 F_1 ( T_2 * V_1 , int V_2 , const char * V_3 ,
int V_4 , long V_5 , long V_6 )
{
T_2 * V_7 ;
T_3 char V_8 [ 256 ] ;
char * V_9 ;
long V_10 = 1 ;
if ( V_11 & V_2 )
V_10 = V_6 ;
sprintf ( V_8 , L_1 , ( unsigned long ) V_1 ) ;
V_9 = & ( V_8 [ 14 ] ) ;
switch ( V_2 )
{
case V_12 :
sprintf ( V_9 , L_2 , V_1 -> V_13 -> V_14 ) ;
break;
case V_15 :
if ( V_1 -> V_13 -> type & V_16 )
sprintf ( V_9 , L_3 , V_1 -> V_17 , V_4 , V_1 -> V_13 -> V_14 , V_1 -> V_17 ) ;
else
sprintf ( V_9 , L_4 , V_1 -> V_17 , V_4 , V_1 -> V_13 -> V_14 ) ;
break;
case V_18 :
if ( V_1 -> V_13 -> type & V_16 )
sprintf ( V_9 , L_5 , V_1 -> V_17 , V_4 , V_1 -> V_13 -> V_14 , V_1 -> V_17 ) ;
else
sprintf ( V_9 , L_6 , V_1 -> V_17 , V_4 , V_1 -> V_13 -> V_14 ) ;
break;
case V_19 :
sprintf ( V_9 , L_7 , V_1 -> V_13 -> V_14 ) ;
break;
case V_20 :
sprintf ( V_9 , L_8 , V_4 , V_1 -> V_13 -> V_14 ) ;
break;
case V_21 :
sprintf ( V_9 , L_9 , V_4 , V_1 -> V_13 -> V_14 ) ;
break;
case V_11 | V_15 :
sprintf ( V_9 , L_10 , V_6 ) ;
break;
case V_11 | V_18 :
sprintf ( V_9 , L_11 , V_6 ) ;
break;
case V_11 | V_20 :
sprintf ( V_9 , L_12 , V_6 ) ;
break;
case V_11 | V_19 :
sprintf ( V_9 , L_13 , V_6 ) ;
break;
case V_11 | V_21 :
sprintf ( V_9 , L_14 , V_6 ) ;
break;
default:
sprintf ( V_9 , L_15 , V_2 ) ;
break;
}
V_7 = ( T_2 * ) V_1 -> V_22 ;
if ( V_7 != NULL )
F_2 ( V_7 , V_8 , strlen ( V_8 ) ) ;
#if ! F_3 ( V_23 ) && ! F_3 ( V_24 )
else
fputs ( V_8 , V_25 ) ;
#endif
return ( V_10 ) ;
}
