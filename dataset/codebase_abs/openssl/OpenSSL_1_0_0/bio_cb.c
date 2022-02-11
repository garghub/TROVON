long T_1 F_1 ( T_2 * V_1 , int V_2 , const char * V_3 ,
int V_4 , long V_5 , long V_6 )
{
T_2 * V_7 ;
T_3 char V_8 [ 256 ] ;
char * V_9 ;
long V_10 = 1 ;
T_4 V_11 ;
if ( V_12 & V_2 )
V_10 = V_6 ;
F_2 ( V_8 , sizeof V_8 , L_1 , ( unsigned long ) V_1 ) ;
V_9 = & ( V_8 [ 14 ] ) ;
V_11 = sizeof V_8 - 14 ;
switch ( V_2 )
{
case V_13 :
F_2 ( V_9 , V_11 , L_2 , V_1 -> V_14 -> V_15 ) ;
break;
case V_16 :
if ( V_1 -> V_14 -> type & V_17 )
F_2 ( V_9 , V_11 , L_3 ,
V_1 -> V_18 , ( unsigned long ) V_4 ,
V_1 -> V_14 -> V_15 , V_1 -> V_18 ) ;
else
F_2 ( V_9 , V_11 , L_4 ,
V_1 -> V_18 , ( unsigned long ) V_4 ,
V_1 -> V_14 -> V_15 ) ;
break;
case V_19 :
if ( V_1 -> V_14 -> type & V_17 )
F_2 ( V_9 , V_11 , L_5 ,
V_1 -> V_18 , ( unsigned long ) V_4 ,
V_1 -> V_14 -> V_15 , V_1 -> V_18 ) ;
else
F_2 ( V_9 , V_11 , L_6 ,
V_1 -> V_18 , ( unsigned long ) V_4 ,
V_1 -> V_14 -> V_15 ) ;
break;
case V_20 :
F_2 ( V_9 , V_11 , L_7 , V_1 -> V_14 -> V_15 ) ;
break;
case V_21 :
F_2 ( V_9 , V_11 , L_8 , ( unsigned long ) V_4 , V_1 -> V_14 -> V_15 ) ;
break;
case V_22 :
F_2 ( V_9 , V_11 , L_9 , ( unsigned long ) V_4 , V_1 -> V_14 -> V_15 ) ;
break;
case V_12 | V_16 :
F_2 ( V_9 , V_11 , L_10 , V_6 ) ;
break;
case V_12 | V_19 :
F_2 ( V_9 , V_11 , L_11 , V_6 ) ;
break;
case V_12 | V_21 :
F_2 ( V_9 , V_11 , L_12 , V_6 ) ;
break;
case V_12 | V_20 :
F_2 ( V_9 , V_11 , L_13 , V_6 ) ;
break;
case V_12 | V_22 :
F_2 ( V_9 , V_11 , L_14 , V_6 ) ;
break;
default:
F_2 ( V_9 , V_11 , L_15 , V_2 ) ;
break;
}
V_7 = ( T_2 * ) V_1 -> V_23 ;
if ( V_7 != NULL )
F_3 ( V_7 , V_8 , strlen ( V_8 ) ) ;
#if ! F_4 ( V_24 ) && ! F_4 ( V_25 )
else
fputs ( V_8 , V_26 ) ;
#endif
return ( V_10 ) ;
}
