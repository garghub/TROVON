long F_1 ( T_1 * V_1 , int V_2 , const char * V_3 ,
int V_4 , long V_5 , long V_6 )
{
T_1 * V_7 ;
char V_8 [ 256 ] ;
char * V_9 ;
long V_10 = 1 ;
int V_11 ;
T_2 V_12 ;
if ( V_13 & V_2 )
V_10 = V_6 ;
V_11 = F_2 ( V_8 , sizeof V_8 , L_1 , ( void * ) V_1 ) ;
if ( V_11 < 0 )
V_11 = 0 ;
V_9 = V_8 + V_11 ;
V_12 = sizeof( V_8 ) - V_11 ;
switch ( V_2 ) {
case V_14 :
F_2 ( V_9 , V_12 , L_2 , V_1 -> V_15 -> V_16 ) ;
break;
case V_17 :
if ( V_1 -> V_15 -> type & V_18 )
F_2 ( V_9 , V_12 , L_3 ,
V_1 -> V_19 , ( unsigned long ) V_4 ,
V_1 -> V_15 -> V_16 , V_1 -> V_19 ) ;
else
F_2 ( V_9 , V_12 , L_4 ,
V_1 -> V_19 , ( unsigned long ) V_4 , V_1 -> V_15 -> V_16 ) ;
break;
case V_20 :
if ( V_1 -> V_15 -> type & V_18 )
F_2 ( V_9 , V_12 , L_5 ,
V_1 -> V_19 , ( unsigned long ) V_4 ,
V_1 -> V_15 -> V_16 , V_1 -> V_19 ) ;
else
F_2 ( V_9 , V_12 , L_6 ,
V_1 -> V_19 , ( unsigned long ) V_4 , V_1 -> V_15 -> V_16 ) ;
break;
case V_21 :
F_2 ( V_9 , V_12 , L_7 , V_1 -> V_15 -> V_16 ) ;
break;
case V_22 :
F_2 ( V_9 , V_12 , L_8 , ( unsigned long ) V_4 ,
V_1 -> V_15 -> V_16 ) ;
break;
case V_23 :
F_2 ( V_9 , V_12 , L_9 , ( unsigned long ) V_4 ,
V_1 -> V_15 -> V_16 ) ;
break;
case V_13 | V_17 :
F_2 ( V_9 , V_12 , L_10 , V_6 ) ;
break;
case V_13 | V_20 :
F_2 ( V_9 , V_12 , L_11 , V_6 ) ;
break;
case V_13 | V_22 :
F_2 ( V_9 , V_12 , L_12 , V_6 ) ;
break;
case V_13 | V_21 :
F_2 ( V_9 , V_12 , L_13 , V_6 ) ;
break;
case V_13 | V_23 :
F_2 ( V_9 , V_12 , L_14 , V_6 ) ;
break;
default:
F_2 ( V_9 , V_12 , L_15 , V_2 ) ;
break;
}
V_7 = ( T_1 * ) V_1 -> V_24 ;
if ( V_7 != NULL )
F_3 ( V_7 , V_8 , strlen ( V_8 ) ) ;
#if ! F_4 ( V_25 )
else
fputs ( V_8 , V_26 ) ;
#endif
return ( V_10 ) ;
}
