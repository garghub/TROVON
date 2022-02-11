int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
unsigned char * V_4 , * V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , NULL , V_7 , V_8 ,
V_9 , V_10 ) ;
if( ! ( V_5 = ( unsigned char * ) Malloc ( V_6 ) ) ) {
F_3 ( V_11 , V_12 ) ;
return 0 ;
}
V_4 = V_5 ;
F_2 ( V_2 , & V_4 , V_7 , V_8 ,
V_9 , V_10 ) ;
if( ! ( V_3 = F_4 () ) ) {
F_3 ( V_11 , V_12 ) ;
return 0 ;
}
if( ! F_5 ( V_3 , V_5 , V_6 ) ) {
F_3 ( V_11 , V_12 ) ;
return 0 ;
}
Free ( V_5 ) ;
return F_6 ( V_1 , V_13 ,
V_8 , V_3 ) ;
}
T_2 * F_7 ( T_1 * V_1 )
{
T_4 * V_2 ;
unsigned char * V_4 ;
V_2 = F_8 ( V_1 , V_13 ) ;
if ( ! V_2 ) return NULL ;
V_4 = V_2 -> V_14 . V_15 -> V_16 ;
return F_9 ( NULL , & V_4 , V_2 -> V_14 . V_15 -> V_17 ,
( char * (*)() ) V_18 , V_19 , V_8 ,
V_9 ) ;
}
int F_10 ( T_2 * V_20 , int V_21 , int V_22 )
{
T_5 * V_23 ;
if( ! ( V_23 = F_11 () ) ) {
F_3 ( V_24 , V_12 ) ;
return 0 ;
}
F_12 ( V_23 -> V_25 ) ;
V_23 -> V_25 = F_13 ( V_21 ) ;
if ( V_22 > 0 ) {
T_6 * V_26 ;
if( ! ( V_23 -> V_27 = F_14 () ) ) {
F_3 ( V_24 , V_12 ) ;
return 0 ;
}
if( ! ( V_26 = F_15 () ) ) {
F_3 ( V_24 , V_12 ) ;
return 0 ;
}
if( ! F_16 ( V_26 , V_22 ) ) {
F_3 ( V_24 , V_12 ) ;
return 0 ;
}
V_23 -> V_27 -> V_14 . integer = V_26 ;
V_23 -> V_27 -> type = V_28 ;
}
F_17 ( V_20 , ( char * ) V_23 ) ;
return 1 ;
}
