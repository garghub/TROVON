int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
int V_3 = 0 ;
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_4 , V_5 , 0 , V_3 ) ;
F_4 ( V_1 -> V_6 , V_7 ) ;
F_4 ( V_1 -> V_8 , V_9 ) ;
F_5 () ;
F_6 ( V_1 -> V_4 , V_5 , 0 , V_3 ) ;
F_7 ( V_1 -> V_6 , V_7 , 1 ) ;
F_7 ( V_1 -> V_8 , V_9 , 2 ) ;
F_8 () ;
}
T_1 * F_9 ( void )
{
T_1 * V_10 = NULL ;
T_2 V_11 ;
F_10 ( V_10 , T_1 ) ;
V_10 -> V_4 = NULL ;
V_10 -> V_6 = NULL ;
V_10 -> V_8 = NULL ;
return ( V_10 ) ;
F_11 ( V_12 ) ;
}
T_1 * F_12 ( T_1 * * V_1 , unsigned char * * V_2 , long V_13 )
{
F_13 ( V_1 , T_1 * , F_9 ) ;
F_14 () ;
F_15 () ;
F_16 ( V_10 -> V_4 , V_14 , 0 ) ;
F_17 ( V_10 -> V_6 , V_15 , 1 ,
V_16 ) ;
F_17 ( V_10 -> V_8 , V_17 , 2 ,
V_18 ) ;
F_18 ( V_1 , V_19 , V_20 ) ;
}
void V_19 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_19 ( V_1 -> V_4 ) ;
F_20 ( V_1 -> V_6 ) ;
F_21 ( V_1 -> V_8 , V_21 ) ;
Free ( V_1 ) ;
}
int V_5 ( T_3 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
if( V_1 -> V_22 ) {
F_4 ( V_1 -> V_22 , V_9 ) ;
} else {
F_22 ( V_23 ,
V_1 -> V_24 , V_25 , 1 ) ;
}
if( V_2 == NULL ) return V_10 ;
V_26 = * V_2 ;
if( V_1 -> V_22 ) {
F_7 ( V_1 -> V_22 , V_9 , 0 ) ;
} else {
F_23 ( V_23 ,
V_1 -> V_24 , V_25 , 1 ) ;
}
F_8 () ;
}
T_3 * F_24 ( void )
{
T_3 * V_10 = NULL ;
T_2 V_11 ;
F_10 ( V_10 , T_3 ) ;
V_10 -> V_22 = NULL ;
V_10 -> V_24 = NULL ;
return ( V_10 ) ;
F_11 ( V_27 ) ;
}
void F_19 ( T_3 * V_1 )
{
if ( V_1 == NULL ) return;
F_25 ( V_1 -> V_24 , V_28 ) ;
F_21 ( V_1 -> V_22 , V_21 ) ;
Free ( V_1 ) ;
}
T_3 * V_14 ( T_3 * * V_1 , unsigned char * * V_2 ,
long V_13 )
{
unsigned char V_29 , V_30 ;
F_13 ( V_1 , T_3 * , F_24 ) ;
F_14 () ;
V_11 . V_31 = V_13 ;
V_29 = V_32 ;
V_30 = V_29 & ~ V_33 ;
if( V_30 == ( 0 | V_34 ) ) {
F_26 ( V_10 -> V_22 , V_17 ,
V_18 ) ;
} else if ( V_30 == ( 1 | V_34 ) ) {
F_27 ( V_23 ,
V_10 -> V_24 , V_35 , V_28 , 1 ) ;
} else {
V_11 . error = V_36 ;
goto V_37;
}
F_18 ( V_1 , F_19 , V_38 ) ;
}
