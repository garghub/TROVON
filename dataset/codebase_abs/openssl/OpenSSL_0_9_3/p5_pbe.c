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
Free ( ( char * ) V_1 ) ;
}
T_3 * F_19 ( int V_17 , int V_5 , unsigned char * V_3 ,
int V_18 )
{
unsigned char * V_19 , * V_20 ;
int V_21 ;
T_1 * V_22 ;
T_4 * V_23 ;
T_3 * V_24 ;
T_5 * V_25 ;
if ( ! ( V_22 = F_7 () ) ) {
F_20 ( V_26 , V_27 ) ;
return NULL ;
}
F_21 ( V_22 -> V_5 , V_5 ) ;
if ( ! V_18 ) V_18 = V_28 ;
if ( ! ( V_22 -> V_3 -> V_29 = Malloc ( V_18 ) ) ) {
F_20 ( V_26 , V_27 ) ;
return NULL ;
}
V_22 -> V_3 -> V_12 = V_18 ;
if ( V_3 ) memcpy ( V_22 -> V_3 -> V_29 , V_3 , V_18 ) ;
else F_22 ( V_22 -> V_3 -> V_29 , V_18 ) ;
if ( ! ( V_21 = F_1 ( V_22 , NULL ) ) ) {
F_20 ( V_26 , V_30 ) ;
return NULL ;
}
if ( ! ( V_19 = Malloc ( V_21 ) ) ) {
F_20 ( V_26 , V_27 ) ;
return NULL ;
}
V_20 = V_19 ;
F_1 ( V_22 , & V_20 ) ;
V_15 ( V_22 ) ;
if ( ! ( V_25 = F_23 () ) ) {
F_20 ( V_26 , V_27 ) ;
return NULL ;
}
V_25 -> type = V_31 ;
if ( ! ( V_25 -> V_32 . V_33 = F_24 () ) ) {
F_20 ( V_26 , V_27 ) ;
return NULL ;
}
F_25 ( V_25 -> V_32 . V_33 , V_19 , V_21 ) ;
Free ( V_19 ) ;
V_23 = F_26 ( V_17 ) ;
if ( ! ( V_24 = F_27 () ) ) {
F_20 ( V_26 , V_27 ) ;
return NULL ;
}
F_28 ( V_24 -> V_34 ) ;
V_24 -> V_34 = V_23 ;
V_24 -> V_35 = V_25 ;
return ( V_24 ) ;
}
