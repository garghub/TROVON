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
F_4 ( V_1 , L_1 , V_4 , L_2 , V_6 ) ;
} else if( V_8 -> V_17 ) {
if( ! ( V_10 = V_8 -> V_17 ( V_8 , V_5 , NULL ) ) ) {
V_11 = 0 ;
goto V_16;
}
F_5 ( V_1 , V_10 , V_4 ,
V_8 -> V_18 & V_19 ) ;
} else if( V_8 -> V_20 ) {
if( ! V_8 -> V_20 ( V_8 , V_5 , V_1 , V_4 ) ) V_11 = 0 ;
} else V_11 = 0 ;
V_16:
F_6 ( V_10 , V_21 ) ;
if( V_6 ) Free ( V_6 ) ;
V_8 -> V_22 ( V_5 ) ;
return V_11 ;
}
int F_7 ( T_4 * V_23 , T_2 * V_2 , int V_3 , int V_4 )
{
T_1 * V_24 ;
int V_25 ;
if( ! ( V_24 = F_8 ( V_23 , V_26 ) ) ) return 0 ;
V_25 = F_1 ( V_24 , V_2 , V_3 , V_4 ) ;
F_9 ( V_24 ) ;
return V_25 ;
}
