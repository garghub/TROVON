void F_1 ( void )
{
#ifndef F_2
F_3 ( V_1 , F_4 () , F_5 () ,
V_2 ) ;
F_3 ( V_3 , F_6 () , F_5 () ,
V_2 ) ;
#endif
F_3 ( V_4 ,
F_7 () , F_5 () , V_2 ) ;
F_3 ( V_5 ,
F_8 () , F_5 () , V_2 ) ;
#ifndef F_9
F_3 ( V_6 , F_10 () ,
F_5 () , V_2 ) ;
F_3 ( V_7 , F_11 () ,
F_5 () , V_2 ) ;
#endif
}
int V_2 ( T_1 * V_8 , const char * V_9 , int V_10 ,
T_2 * V_11 , T_3 * V_12 , T_4 * V_13 , int V_14 )
{
T_5 * V_15 ;
int V_16 , V_17 ;
unsigned char * V_18 , * V_19 ;
unsigned char V_20 [ V_21 ] , V_22 [ V_23 ] ;
V_19 = V_11 -> V_24 . V_25 -> V_26 ;
if ( ! V_11 || ( V_11 -> type != V_27 ) ||
! ( V_15 = F_12 ( NULL , & V_19 , V_11 -> V_24 . V_25 -> V_28 ) ) ) {
F_13 ( V_29 , V_30 ) ;
return 0 ;
}
if ( ! V_15 -> V_17 ) V_17 = 1 ;
else V_17 = F_14 ( V_15 -> V_17 ) ;
V_18 = V_15 -> V_18 -> V_26 ;
V_16 = V_15 -> V_18 -> V_28 ;
if ( ! F_15 ( V_9 , V_10 , V_18 , V_16 , V_31 ,
V_17 , F_16 ( V_12 ) , V_20 , V_13 ) ) {
F_17 ( V_29 , V_32 ) ;
F_18 ( V_15 ) ;
return 0 ;
}
if ( ! F_15 ( V_9 , V_10 , V_18 , V_16 , V_33 ,
V_17 , F_19 ( V_12 ) , V_22 , V_13 ) ) {
F_17 ( V_29 , V_34 ) ;
F_18 ( V_15 ) ;
return 0 ;
}
F_18 ( V_15 ) ;
F_20 ( V_8 , V_12 , V_20 , V_22 , V_14 ) ;
memset ( V_20 , 0 , V_21 ) ;
memset ( V_22 , 0 , V_23 ) ;
return 1 ;
}
