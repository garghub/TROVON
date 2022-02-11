int F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_4 )
{
char * V_5 = NULL , * V_6 = NULL ;
unsigned char * V_7 ;
T_3 * V_8 ;
F_2 ( V_9 ) * V_10 = NULL ;
int V_11 = 1 ;
if( ! ( V_8 = F_3 ( V_2 ) ) ) return 0 ;
V_7 = V_2 -> V_6 -> V_12 ;
if( ! ( V_5 = V_8 -> V_13 ( NULL , & V_7 , V_2 -> V_6 -> V_14 ) ) ) return 0 ;
if( V_8 -> V_15 ) {
if( ! ( V_6 = V_8 -> V_15 ( V_8 , V_5 ) ) ) {
V_11 = 0 ;
goto V_16;
}
#ifndef F_4
F_5 ( V_1 , L_1 , V_4 , L_2 , V_6 ) ;
#else
{
char V_17 [ 10240 ] ;
F_6 ( V_17 , V_6 , strlen ( V_6 ) + 1 ) ;
F_5 ( V_1 , L_1 , V_4 , L_2 , V_17 ) ;
}
#endif
} else if( V_8 -> V_18 ) {
if( ! ( V_10 = V_8 -> V_18 ( V_8 , V_5 , NULL ) ) ) {
V_11 = 0 ;
goto V_16;
}
F_7 ( V_1 , V_10 , V_4 ,
V_8 -> V_19 & V_20 ) ;
} else if( V_8 -> V_21 ) {
if( ! V_8 -> V_21 ( V_8 , V_5 , V_1 , V_4 ) ) V_11 = 0 ;
} else V_11 = 0 ;
V_16:
F_8 ( V_10 , V_22 ) ;
if( V_6 ) Free ( V_6 ) ;
V_8 -> V_23 ( V_5 ) ;
return V_11 ;
}
int F_9 ( T_4 * V_24 , T_2 * V_2 , int V_3 , int V_4 )
{
T_1 * V_25 ;
int V_26 ;
if( ! ( V_25 = F_10 ( V_24 , V_27 ) ) ) return 0 ;
V_26 = F_1 ( V_25 , V_2 , V_3 , V_4 ) ;
F_11 ( V_25 ) ;
return V_26 ;
}
