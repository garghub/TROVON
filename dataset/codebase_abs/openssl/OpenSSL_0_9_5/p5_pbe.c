int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_6 ) ;
F_6 () ;
}
T_1 * F_7 ( void )
{
T_1 * V_7 = NULL ;
T_2 V_8 ;
F_8 ( V_7 , T_1 ) ;
F_9 ( V_7 -> V_5 , V_9 ) ;
F_9 ( V_7 -> V_3 , V_10 ) ;
return ( V_7 ) ;
F_10 ( V_11 ) ;
}
T_1 * F_11 ( T_1 * * V_1 , unsigned char * * V_2 , long V_12 )
{
F_12 ( V_1 , T_1 * , F_7 ) ;
F_13 () ;
F_14 () ;
F_15 ( V_7 -> V_3 , V_13 ) ;
F_15 ( V_7 -> V_5 , V_14 ) ;
F_16 ( V_1 , V_15 , V_16 ) ;
}
void V_15 ( T_1 * V_1 )
{
if( V_1 == NULL ) return;
F_17 ( V_1 -> V_3 ) ;
F_18 ( V_1 -> V_5 ) ;
Free ( V_1 ) ;
}
T_3 * F_19 ( int V_17 , int V_5 , unsigned char * V_3 ,
int V_18 )
{
T_1 * V_19 ;
T_4 * V_20 ;
T_3 * V_21 ;
T_5 * V_22 ;
if ( ! ( V_19 = F_7 () ) ) {
F_20 ( V_23 , V_24 ) ;
return NULL ;
}
if( V_5 <= 0 ) V_5 = V_25 ;
F_21 ( V_19 -> V_5 , V_5 ) ;
if ( ! V_18 ) V_18 = V_26 ;
if ( ! ( V_19 -> V_3 -> V_27 = Malloc ( V_18 ) ) ) {
F_20 ( V_23 , V_24 ) ;
return NULL ;
}
V_19 -> V_3 -> V_12 = V_18 ;
if ( V_3 ) memcpy ( V_19 -> V_3 -> V_27 , V_3 , V_18 ) ;
else if ( F_22 ( V_19 -> V_3 -> V_27 , V_18 ) <= 0 )
return NULL ;
if ( ! ( V_22 = F_23 () ) ) {
F_20 ( V_23 , V_24 ) ;
return NULL ;
}
V_22 -> type = V_28 ;
if( ! F_24 ( V_19 , F_1 , & V_22 -> V_29 . V_30 ) ) {
F_20 ( V_23 , V_24 ) ;
return NULL ;
}
V_15 ( V_19 ) ;
V_20 = F_25 ( V_17 ) ;
if ( ! ( V_21 = F_26 () ) ) {
F_20 ( V_23 , V_24 ) ;
return NULL ;
}
F_27 ( V_21 -> V_31 ) ;
V_21 -> V_31 = V_20 ;
V_21 -> V_32 = V_22 ;
return ( V_21 ) ;
}
