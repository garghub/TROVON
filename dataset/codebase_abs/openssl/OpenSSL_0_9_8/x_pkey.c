int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
return ( 0 ) ;
}
T_1 * F_2 ( T_1 * * V_1 , const unsigned char * * V_2 , long V_3 )
{
int V_4 ;
F_3 ( V_1 , T_1 * , V_5 ) ;
F_4 () ;
F_5 () ;
F_6 ( V_6 , V_7 -> V_8 , V_9 ) ;
F_6 ( V_10 , V_7 -> V_11 , V_12 ) ;
V_7 -> V_13 . V_13 = F_7 (
F_8 ( F_9 ( V_7 -> V_8 -> V_14 ) ) ) ;
if ( V_7 -> V_13 . V_13 == NULL )
{
V_15 . error = V_16 ;
V_15 . line = __LINE__ ;
goto V_17;
}
if ( V_7 -> V_8 -> V_18 -> type == V_19 )
{
V_4 = V_7 -> V_8 -> V_18 -> V_20 . V_21 -> V_3 ;
if ( V_4 > V_22 )
{
V_15 . error = V_23 ;
V_15 . line = __LINE__ ;
goto V_17;
}
memcpy ( V_7 -> V_13 . V_24 ,
V_7 -> V_8 -> V_18 -> V_20 . V_21 -> V_25 , V_4 ) ;
}
else
memset ( V_7 -> V_13 . V_24 , 0 , V_22 ) ;
F_10 ( V_1 , V_26 , V_27 ) ;
}
T_1 * V_5 ( void )
{
T_1 * V_7 = NULL ;
T_2 V_15 ;
F_11 ( V_7 , T_1 ) ;
V_7 -> V_28 = 0 ;
F_12 ( V_7 -> V_8 , V_29 ) ;
F_12 ( V_7 -> V_11 , V_30 ) ;
V_7 -> V_31 = NULL ;
V_7 -> V_32 = 0 ;
V_7 -> V_33 = NULL ;
V_7 -> V_34 = 0 ;
V_7 -> V_13 . V_13 = NULL ;
memset ( V_7 -> V_13 . V_24 , 0 , V_22 ) ;
V_7 -> V_35 = 1 ;
return ( V_7 ) ;
F_13 ( V_36 ) ;
}
void V_26 ( T_1 * V_37 )
{
int V_4 ;
if ( V_37 == NULL ) return;
V_4 = F_14 ( & V_37 -> V_35 , - 1 , V_38 ) ;
#ifdef F_15
F_15 ( L_1 , V_37 ) ;
#endif
if ( V_4 > 0 ) return;
#ifdef F_16
if ( V_4 < 0 )
{
fprintf ( V_39 , L_2 ) ;
abort () ;
}
#endif
if ( V_37 -> V_8 != NULL ) F_17 ( V_37 -> V_8 ) ;
if ( V_37 -> V_11 != NULL ) F_18 ( V_37 -> V_11 ) ;
if ( V_37 -> V_31 != NULL ) F_19 ( V_37 -> V_31 ) ;
if ( ( V_37 -> V_33 != NULL ) && ( V_37 -> V_34 ) ) F_20 ( V_37 -> V_33 ) ;
F_20 ( V_37 ) ;
}
