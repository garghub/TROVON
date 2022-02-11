T_1 * F_1 ( char * V_1 , char * V_2 , T_2 * V_3 , T_3 * V_4 ,
T_4 * V_5 , int V_6 , int V_7 , int V_8 , int V_9 ,
int V_10 )
{
T_1 * V_11 ;
T_4 * V_12 , * V_13 ;
T_5 * V_14 ;
T_6 * V_15 ;
T_7 * V_16 ;
T_3 * V_17 ;
int V_18 ;
unsigned char V_19 [ V_20 ] ;
unsigned int V_21 ;
if( ! V_7 ) V_7 = V_22 ;
if( ! V_6 ) V_6 = V_23 ;
if( ! V_8 ) V_8 = V_24 ;
if( ! V_9 ) V_9 = 1 ;
if( ! V_3 || ! V_4 ) {
F_2 ( V_25 , V_26 ) ;
return NULL ;
}
if( ! ( V_12 = F_3 ( NULL ) ) ) {
F_2 ( V_25 , V_27 ) ;
return NULL ;
}
if( ! ( V_14 = F_4 ( V_4 ) ) ) return NULL ;
if( V_2 && ! F_5 ( V_14 , V_2 , - 1 ) ) return NULL ;
F_6 ( V_4 , F_7 () , V_19 , & V_21 ) ;
if( ! F_8 ( V_14 , V_19 , V_21 ) ) return NULL ;
if( ! F_9 ( V_12 , ( char * ) V_14 ) ) {
F_2 ( V_25 , V_27 ) ;
return NULL ;
}
if( V_5 ) {
for( V_18 = 0 ; V_18 < F_10 ( V_5 ) ; V_18 ++ ) {
V_17 = ( T_3 * ) F_11 ( V_5 , V_18 ) ;
if( ! ( V_14 = F_4 ( V_17 ) ) ) return NULL ;
if( ! F_9 ( V_12 , ( char * ) V_14 ) ) {
F_2 ( V_25 , V_27 ) ;
return NULL ;
}
}
}
V_16 = F_12 ( V_7 , V_1 , - 1 , NULL , 0 ,
V_8 , V_12 ) ;
F_13 ( V_12 , V_28 ) ;
if ( ! V_16 ) return NULL ;
if( ! ( V_13 = F_3 ( NULL ) ) || ! F_9 ( V_13 , ( char * ) V_16 ) ) {
F_2 ( V_25 , V_27 ) ;
return NULL ;
}
if( ! ( V_15 = F_14 ( V_3 ) ) ) return NULL ;
if( V_10 && ! F_15 ( V_15 , V_10 ) ) return NULL ;
V_14 = F_16 ( V_6 , V_1 , - 1 , NULL , 0 , V_8 , V_15 ) ;
if( ! V_14 ) return NULL ;
F_17 ( V_15 ) ;
if ( V_2 && ! F_5 ( V_14 , V_2 , - 1 ) ) return NULL ;
if( ! F_8 ( V_14 , V_19 , V_21 ) ) return NULL ;
if( ! ( V_12 = F_3 ( NULL ) ) || ! F_9 ( V_12 , ( char * ) V_14 ) ) {
F_2 ( V_25 , V_27 ) ;
return NULL ;
}
if( ! ( V_16 = F_18 ( V_12 ) ) ) return NULL ;
F_13 ( V_12 , V_28 ) ;
if( ! F_9 ( V_13 , ( char * ) V_16 ) ) {
F_2 ( V_25 , V_27 ) ;
return NULL ;
}
if( ! ( V_11 = F_19 ( V_29 ) ) ) return NULL ;
if( ! F_20 ( V_11 , V_13 ) ) return NULL ;
F_13 ( V_13 , V_30 ) ;
if( ! F_21 ( V_11 , V_1 , - 1 , NULL , 0 , V_9 , NULL ) )
return NULL ;
return V_11 ;
}
