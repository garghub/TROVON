T_1 * F_1 ( int V_1 , const T_2 * V_2 ,
const char * V_3 , int V_4 ,
unsigned char * V_5 , int V_6 , int V_7 ,
T_3 * V_8 )
{
T_1 * V_9 = NULL ;
T_4 * V_10 ;
if ( V_1 == - 1 )
V_10 = F_2 ( V_2 , V_7 , V_5 , V_6 ) ;
else if ( F_3 ( V_11 , V_1 , NULL , NULL , 0 ) )
V_10 = F_4 ( V_2 , V_7 , V_5 , V_6 , NULL , V_1 ) ;
else {
F_5 () ;
V_10 = F_6 ( V_1 , V_7 , V_5 , V_6 ) ;
}
if ( ! V_10 ) {
F_7 ( V_12 , V_13 ) ;
return NULL ;
}
V_9 = F_8 ( V_3 , V_4 , V_8 , V_10 ) ;
if ( V_9 == NULL ) {
F_9 ( V_10 ) ;
return NULL ;
}
return V_9 ;
}
T_1 * F_8 ( const char * V_3 , int V_4 ,
T_3 * V_8 , T_4 * V_10 )
{
T_1 * V_9 ;
T_5 * V_14 ;
V_14 =
F_10 ( V_10 , F_11 ( T_3 ) ,
V_3 , V_4 , V_8 , 1 ) ;
if ( ! V_14 ) {
F_7 ( V_15 , V_16 ) ;
return NULL ;
}
V_9 = F_12 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ) {
F_7 ( V_15 , V_17 ) ;
F_13 ( V_14 ) ;
return NULL ;
}
V_9 -> V_18 = V_10 ;
V_9 -> V_19 = V_14 ;
return V_9 ;
}
