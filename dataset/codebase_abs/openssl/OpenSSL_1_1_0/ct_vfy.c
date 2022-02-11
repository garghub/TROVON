static int F_1 ( T_1 * V_1 , const T_2 * V_2 , const T_3 * V_3 )
{
unsigned char V_4 [ 12 ] ;
unsigned char * V_5 , * V_6 ;
T_4 V_7 ;
if ( V_3 -> V_8 == V_9 )
return 0 ;
if ( V_3 -> V_8 == V_10 && V_2 -> V_11 == NULL )
return 0 ;
V_5 = V_4 ;
* V_5 ++ = V_3 -> V_12 ;
* V_5 ++ = V_13 ;
F_2 ( V_3 -> V_14 , V_5 ) ;
F_3 ( V_3 -> V_8 , V_5 ) ;
if ( ! F_4 ( V_1 , V_4 , V_5 - V_4 ) )
return 0 ;
if ( V_3 -> V_8 == V_15 ) {
V_6 = V_2 -> V_16 ;
V_7 = V_2 -> V_17 ;
} else {
if ( ! F_4 ( V_1 , V_2 -> V_11 , V_2 -> V_18 ) )
return 0 ;
V_6 = V_2 -> V_19 ;
V_7 = V_2 -> V_20 ;
}
if ( V_6 == NULL )
return 0 ;
V_5 = V_4 ;
F_5 ( V_7 , V_5 ) ;
if ( ! F_4 ( V_1 , V_4 , 3 ) )
return 0 ;
if ( ! F_4 ( V_1 , V_6 , V_7 ) )
return 0 ;
V_5 = V_4 ;
F_3 ( V_3 -> V_21 , V_5 ) ;
if ( ! F_4 ( V_1 , V_4 , 2 ) )
return 0 ;
if ( V_3 -> V_21 && ! F_4 ( V_1 , V_3 -> V_22 , V_3 -> V_21 ) )
return 0 ;
return 1 ;
}
int F_6 ( const T_2 * V_2 , const T_3 * V_3 )
{
T_1 * V_1 = NULL ;
int V_23 = 0 ;
if ( ! F_7 ( V_3 ) || V_2 -> V_24 == NULL ||
V_3 -> V_8 == V_9 ||
( V_3 -> V_8 == V_10 && V_2 -> V_11 == NULL ) ) {
F_8 ( V_25 , V_26 ) ;
return 0 ;
}
if ( V_3 -> V_12 != V_27 ) {
F_8 ( V_25 , V_28 ) ;
return 0 ;
}
if ( V_3 -> V_29 != V_2 -> V_30 ||
memcmp ( V_3 -> V_31 , V_2 -> V_32 , V_2 -> V_30 ) != 0 ) {
F_8 ( V_25 , V_33 ) ;
return 0 ;
}
V_1 = F_9 () ;
if ( V_1 == NULL )
goto V_34;
if ( ! F_10 ( V_1 , NULL , F_11 () , NULL , V_2 -> V_24 ) )
goto V_34;
if ( ! F_1 ( V_1 , V_2 , V_3 ) )
goto V_34;
V_23 = F_12 ( V_1 , V_3 -> V_35 , V_3 -> V_36 ) ;
if ( V_23 == 0 )
F_8 ( V_25 , V_37 ) ;
V_34:
F_13 ( V_1 ) ;
return V_23 ;
}
