int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
return ( 0 ) ;
}
T_1 * F_2 ( T_1 * * V_1 , unsigned char * * V_2 , long V_3 )
{
int V_4 ;
F_3 ( V_1 , T_1 * , V_5 ) ;
F_4 () ;
F_5 () ;
F_6 ( V_6 -> V_7 , V_8 ) ;
F_6 ( V_6 -> V_9 , V_10 ) ;
V_6 -> V_11 . V_11 = F_7 (
F_8 ( F_9 ( V_6 -> V_7 -> V_12 ) ) ) ;
if ( V_6 -> V_11 . V_11 == NULL )
{
V_13 . error = V_14 ;
V_13 . line = __LINE__ ;
goto V_15;
}
if ( V_6 -> V_7 -> V_16 -> type == V_17 )
{
V_4 = V_6 -> V_7 -> V_16 -> V_18 . V_19 -> V_3 ;
if ( V_4 > V_20 )
{
V_13 . error = V_21 ;
V_13 . line = __LINE__ ;
goto V_15;
}
memcpy ( V_6 -> V_11 . V_22 ,
V_6 -> V_7 -> V_16 -> V_18 . V_19 -> V_23 , V_4 ) ;
}
else
memset ( V_6 -> V_11 . V_22 , 0 , V_20 ) ;
F_10 ( V_1 , V_24 , V_25 ) ;
}
T_1 * V_5 ( void )
{
T_1 * V_6 = NULL ;
T_2 V_13 ;
F_11 ( V_6 , T_1 ) ;
V_6 -> V_26 = 0 ;
F_12 ( V_6 -> V_7 , V_27 ) ;
F_12 ( V_6 -> V_9 , V_28 ) ;
V_6 -> V_29 = NULL ;
V_6 -> V_30 = 0 ;
V_6 -> V_31 = NULL ;
V_6 -> V_32 = 0 ;
V_6 -> V_11 . V_11 = NULL ;
memset ( V_6 -> V_11 . V_22 , 0 , V_20 ) ;
V_6 -> V_33 = 1 ;
return ( V_6 ) ;
F_13 ( V_34 ) ;
}
void V_24 ( T_1 * V_35 )
{
int V_4 ;
if ( V_35 == NULL ) return;
V_4 = F_14 ( & V_35 -> V_33 , - 1 , V_36 ) ;
#ifdef F_15
F_15 ( L_1 , V_35 ) ;
#endif
if ( V_4 > 0 ) return;
#ifdef F_16
if ( V_4 < 0 )
{
fprintf ( V_37 , L_2 ) ;
abort () ;
}
#endif
if ( V_35 -> V_7 != NULL ) F_17 ( V_35 -> V_7 ) ;
if ( V_35 -> V_9 != NULL ) F_18 ( V_35 -> V_9 ) ;
if ( V_35 -> V_29 != NULL ) F_19 ( V_35 -> V_29 ) ;
if ( ( V_35 -> V_31 != NULL ) && ( V_35 -> V_32 ) ) Free ( ( char * ) V_35 -> V_31 ) ;
Free ( ( char * ) ( char * ) V_35 ) ;
}
