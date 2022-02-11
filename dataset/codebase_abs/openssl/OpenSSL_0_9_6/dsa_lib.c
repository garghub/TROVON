void F_1 ( T_1 * V_1 )
{
V_2 = V_1 ;
}
T_1 * F_2 ( void )
{
if( ! V_2 ) V_2 = F_3 () ;
return V_2 ;
}
T_2 * F_4 ( void )
{
return F_5 ( NULL ) ;
}
T_1 * F_6 ( T_2 * V_3 , T_1 * V_1 )
{
T_1 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 ) V_4 -> V_5 ( V_3 ) ;
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_6 ) V_1 -> V_6 ( V_3 ) ;
return V_4 ;
}
T_2 * F_5 ( T_1 * V_1 )
{
T_2 * V_7 ;
V_7 = ( T_2 * ) F_7 ( sizeof( T_2 ) ) ;
if ( V_7 == NULL )
{
F_8 ( V_8 , V_9 ) ;
return ( NULL ) ;
}
if( V_1 ) V_7 -> V_1 = V_1 ;
else V_7 -> V_1 = F_2 () ;
V_7 -> V_10 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = 1 ;
V_7 -> V_13 = NULL ;
V_7 -> V_14 = NULL ;
V_7 -> V_15 = NULL ;
V_7 -> V_16 = NULL ;
V_7 -> V_17 = NULL ;
V_7 -> V_18 = NULL ;
V_7 -> V_19 = NULL ;
V_7 -> V_20 = NULL ;
V_7 -> V_21 = 1 ;
V_7 -> V_22 = V_7 -> V_1 -> V_22 ;
if ( ( V_7 -> V_1 -> V_6 != NULL ) && ! V_7 -> V_1 -> V_6 ( V_7 ) )
{
F_9 ( V_7 ) ;
V_7 = NULL ;
}
else
F_10 ( V_23 , V_7 , & V_7 -> V_24 ) ;
return ( V_7 ) ;
}
void F_11 ( T_2 * V_19 )
{
int V_25 ;
if ( V_19 == NULL ) return;
V_25 = F_12 ( & V_19 -> V_21 , - 1 , V_26 ) ;
#ifdef F_13
F_13 ( L_1 , V_19 ) ;
#endif
if ( V_25 > 0 ) return;
#ifdef F_14
if ( V_25 < 0 )
{
fprintf ( V_27 , L_2 ) ;
abort () ;
}
#endif
F_15 ( V_23 , V_19 , & V_19 -> V_24 ) ;
if( V_19 -> V_1 -> V_5 ) V_19 -> V_1 -> V_5 ( V_19 ) ;
if ( V_19 -> V_13 != NULL ) F_16 ( V_19 -> V_13 ) ;
if ( V_19 -> V_14 != NULL ) F_16 ( V_19 -> V_14 ) ;
if ( V_19 -> V_15 != NULL ) F_16 ( V_19 -> V_15 ) ;
if ( V_19 -> V_16 != NULL ) F_16 ( V_19 -> V_16 ) ;
if ( V_19 -> V_17 != NULL ) F_16 ( V_19 -> V_17 ) ;
if ( V_19 -> V_18 != NULL ) F_16 ( V_19 -> V_18 ) ;
if ( V_19 -> V_19 != NULL ) F_16 ( V_19 -> V_19 ) ;
F_9 ( V_19 ) ;
}
int F_17 ( T_2 * V_19 )
{
int V_7 , V_25 ;
T_3 V_28 ;
unsigned char V_29 [ 4 ] ;
V_25 = F_18 ( V_19 -> V_14 ) ;
V_28 . V_30 = ( V_25 + 7 ) / 8 ;
V_28 . V_31 = V_29 ;
V_28 . type = V_32 ;
V_29 [ 0 ] = 0xff ;
V_25 = F_19 ( & V_28 , NULL ) ;
V_25 += V_25 ;
V_7 = F_20 ( 1 , V_25 , V_33 ) ;
return ( V_7 ) ;
}
int F_21 ( long V_34 , void * V_35 , T_4 * V_36 ,
T_5 * V_37 , T_6 * V_38 )
{
V_39 ++ ;
return ( F_22 ( V_39 - 1 ,
& V_23 , V_34 , V_35 , V_36 , V_37 , V_38 ) ) ;
}
int F_23 ( T_2 * V_40 , int V_41 , void * V_42 )
{
return ( F_24 ( & V_40 -> V_24 , V_41 , V_42 ) ) ;
}
void * F_25 ( T_2 * V_40 , int V_41 )
{
return ( F_26 ( & V_40 -> V_24 , V_41 ) ) ;
}
T_7 * F_27 ( T_2 * V_19 )
{
T_7 * V_7 = NULL ;
if ( V_19 == NULL )
goto V_43;
V_7 = F_28 () ;
if ( V_7 == NULL )
goto V_43;
if ( V_19 -> V_13 != NULL )
if ( ( V_7 -> V_13 = F_29 ( V_19 -> V_13 ) ) == NULL )
goto V_43;
if ( V_19 -> V_14 != NULL )
V_7 -> V_30 = F_18 ( V_19 -> V_14 ) ;
if ( V_19 -> V_15 != NULL )
if ( ( V_7 -> V_15 = F_29 ( V_19 -> V_15 ) ) == NULL )
goto V_43;
if ( V_19 -> V_16 != NULL )
if ( ( V_7 -> V_16 = F_29 ( V_19 -> V_16 ) ) == NULL )
goto V_43;
if ( V_19 -> V_17 != NULL )
if ( ( V_7 -> V_17 = F_29 ( V_19 -> V_17 ) ) == NULL )
goto V_43;
return V_7 ;
V_43:
if ( V_7 != NULL )
F_30 ( V_7 ) ;
return NULL ;
}
