void F_1 ( void )
{
}
int F_2 ( T_1 * V_1 , const char * V_2 , int V_3 ,
T_2 * V_4 , const T_3 * V_5 ,
const T_4 * V_6 , int V_7 )
{
T_5 * V_8 ;
int V_9 , V_10 , V_11 ;
unsigned char * V_12 ;
unsigned char V_13 [ V_14 ] , V_15 [ V_16 ] ;
int (* F_3)( const char * V_2 , int V_3 ,
unsigned char * V_12 , int V_17 ,
int V_18 , int V_10 , int V_19 ,
unsigned char * V_20 ,
const T_4 * V_21 );
F_3 = V_22 ;
if ( V_5 == NULL )
return 0 ;
V_8 = F_4 ( F_5 ( T_5 ) , V_4 ) ;
if ( V_8 == NULL ) {
F_6 ( V_23 , V_24 ) ;
return 0 ;
}
if ( ! V_8 -> V_10 )
V_10 = 1 ;
else
V_10 = F_7 ( V_8 -> V_10 ) ;
V_12 = V_8 -> V_12 -> V_25 ;
V_9 = V_8 -> V_12 -> V_26 ;
if ( ! (* F_3)( V_2 , V_3 , V_12 , V_9 , V_27 ,
V_10 , F_8 ( V_5 ) , V_13 , V_6 ) ) {
F_6 ( V_23 , V_28 ) ;
F_9 ( V_8 ) ;
return 0 ;
}
if ( ! (* F_3)( V_2 , V_3 , V_12 , V_9 , V_29 ,
V_10 , F_10 ( V_5 ) , V_15 , V_6 ) ) {
F_6 ( V_23 , V_30 ) ;
F_9 ( V_8 ) ;
return 0 ;
}
F_9 ( V_8 ) ;
V_11 = F_11 ( V_1 , V_5 , NULL , V_13 , V_15 , V_7 ) ;
F_12 ( V_13 , V_14 ) ;
F_12 ( V_15 , V_16 ) ;
return V_11 ;
}
