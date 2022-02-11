T_1 * F_1 ( int V_1 , const T_2 * V_2 ,
const char * V_3 , int V_4 ,
unsigned char * V_5 , int V_6 , int V_7 ,
T_3 * V_8 )
{
T_1 * V_9 = NULL ;
T_4 * V_10 ;
if ( ! ( V_9 = F_2 () ) ) {
F_3 ( V_11 , V_12 ) ;
goto V_13;
}
if( V_1 == - 1 ) V_10 = F_4 ( V_2 , V_7 , V_5 , V_6 ) ;
else V_10 = F_5 ( V_1 , V_7 , V_5 , V_6 ) ;
if( ! V_10 ) {
F_3 ( V_11 , V_14 ) ;
goto V_13;
}
F_6 ( V_9 -> V_15 ) ;
V_9 -> V_15 = V_10 ;
F_7 ( V_9 -> V_16 ) ;
V_9 -> V_16 = F_8 ( V_10 , F_9 ( T_3 ) ,
V_3 , V_4 , V_8 , 1 ) ;
if( ! V_9 -> V_16 ) {
F_3 ( V_11 , V_17 ) ;
goto V_13;
}
return V_9 ;
V_13:
F_10 ( V_9 ) ;
return NULL ;
}
