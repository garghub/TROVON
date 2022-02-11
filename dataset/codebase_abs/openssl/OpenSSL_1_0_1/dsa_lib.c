void F_1 ( const T_1 * V_1 )
{
V_2 = V_1 ;
}
const T_1 * F_2 ( void )
{
if( ! V_2 )
{
#ifdef F_3
if ( F_4 () )
return F_5 () ;
else
return F_6 () ;
#else
V_2 = F_6 () ;
#endif
}
return V_2 ;
}
T_2 * F_7 ( void )
{
return F_8 ( NULL ) ;
}
int F_9 ( T_2 * V_3 , const T_1 * V_1 )
{
const T_1 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 ) V_4 -> V_5 ( V_3 ) ;
#ifndef F_10
if ( V_3 -> V_6 )
{
F_11 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
#endif
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_7 ) V_1 -> V_7 ( V_3 ) ;
return 1 ;
}
T_2 * F_8 ( T_3 * V_6 )
{
T_2 * V_8 ;
V_8 = ( T_2 * ) F_12 ( sizeof( T_2 ) ) ;
if ( V_8 == NULL )
{
F_13 ( V_9 , V_10 ) ;
return ( NULL ) ;
}
V_8 -> V_1 = F_2 () ;
#ifndef F_10
if ( V_6 )
{
if ( ! F_14 ( V_6 ) )
{
F_13 ( V_9 , V_11 ) ;
F_15 ( V_8 ) ;
return NULL ;
}
V_8 -> V_6 = V_6 ;
}
else
V_8 -> V_6 = F_16 () ;
if( V_8 -> V_6 )
{
V_8 -> V_1 = F_17 ( V_8 -> V_6 ) ;
if( ! V_8 -> V_1 )
{
F_13 ( V_9 ,
V_11 ) ;
F_11 ( V_8 -> V_6 ) ;
F_15 ( V_8 ) ;
return NULL ;
}
}
#endif
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = 1 ;
V_8 -> V_15 = NULL ;
V_8 -> V_16 = NULL ;
V_8 -> V_17 = NULL ;
V_8 -> V_18 = NULL ;
V_8 -> V_19 = NULL ;
V_8 -> V_20 = NULL ;
V_8 -> V_21 = NULL ;
V_8 -> V_22 = NULL ;
V_8 -> V_23 = 1 ;
V_8 -> V_24 = V_8 -> V_1 -> V_24 & ~ V_25 ;
F_18 ( V_26 , V_8 , & V_8 -> V_27 ) ;
if ( ( V_8 -> V_1 -> V_7 != NULL ) && ! V_8 -> V_1 -> V_7 ( V_8 ) )
{
#ifndef F_10
if ( V_8 -> V_6 )
F_11 ( V_8 -> V_6 ) ;
#endif
F_19 ( V_26 , V_8 , & V_8 -> V_27 ) ;
F_15 ( V_8 ) ;
V_8 = NULL ;
}
return ( V_8 ) ;
}
void F_20 ( T_2 * V_21 )
{
int V_28 ;
if ( V_21 == NULL ) return;
V_28 = F_21 ( & V_21 -> V_23 , - 1 , V_29 ) ;
#ifdef F_22
F_22 ( L_1 , V_21 ) ;
#endif
if ( V_28 > 0 ) return;
#ifdef F_23
if ( V_28 < 0 )
{
fprintf ( V_30 , L_2 ) ;
abort () ;
}
#endif
if( V_21 -> V_1 -> V_5 )
V_21 -> V_1 -> V_5 ( V_21 ) ;
#ifndef F_10
if( V_21 -> V_6 )
F_11 ( V_21 -> V_6 ) ;
#endif
F_19 ( V_26 , V_21 , & V_21 -> V_27 ) ;
if ( V_21 -> V_15 != NULL ) F_24 ( V_21 -> V_15 ) ;
if ( V_21 -> V_16 != NULL ) F_24 ( V_21 -> V_16 ) ;
if ( V_21 -> V_17 != NULL ) F_24 ( V_21 -> V_17 ) ;
if ( V_21 -> V_18 != NULL ) F_24 ( V_21 -> V_18 ) ;
if ( V_21 -> V_19 != NULL ) F_24 ( V_21 -> V_19 ) ;
if ( V_21 -> V_20 != NULL ) F_24 ( V_21 -> V_20 ) ;
if ( V_21 -> V_21 != NULL ) F_24 ( V_21 -> V_21 ) ;
F_15 ( V_21 ) ;
}
int F_25 ( T_2 * V_21 )
{
int V_28 = F_21 ( & V_21 -> V_23 , 1 , V_29 ) ;
#ifdef F_22
F_22 ( L_1 , V_21 ) ;
#endif
#ifdef F_23
if ( V_28 < 2 )
{
fprintf ( V_30 , L_3 ) ;
abort () ;
}
#endif
return ( ( V_28 > 1 ) ? 1 : 0 ) ;
}
int F_26 ( const T_2 * V_21 )
{
int V_8 , V_28 ;
T_4 V_31 ;
unsigned char V_32 [ 4 ] ;
V_28 = F_27 ( V_21 -> V_16 ) ;
V_31 . V_33 = ( V_28 + 7 ) / 8 ;
V_31 . V_34 = V_32 ;
V_31 . type = V_35 ;
V_32 [ 0 ] = 0xff ;
V_28 = F_28 ( & V_31 , NULL ) ;
V_28 += V_28 ;
V_8 = F_29 ( 1 , V_28 , V_36 ) ;
return ( V_8 ) ;
}
int F_30 ( long V_37 , void * V_38 , T_5 * V_39 ,
T_6 * V_40 , T_7 * V_41 )
{
return F_31 ( V_26 , V_37 , V_38 ,
V_39 , V_40 , V_41 ) ;
}
int F_32 ( T_2 * V_42 , int V_43 , void * V_44 )
{
return ( F_33 ( & V_42 -> V_27 , V_43 , V_44 ) ) ;
}
void * F_34 ( T_2 * V_42 , int V_43 )
{
return ( F_35 ( & V_42 -> V_27 , V_43 ) ) ;
}
T_8 * F_36 ( const T_2 * V_21 )
{
T_8 * V_8 = NULL ;
if ( V_21 == NULL )
goto V_45;
V_8 = F_37 () ;
if ( V_8 == NULL )
goto V_45;
if ( V_21 -> V_15 != NULL )
if ( ( V_8 -> V_15 = F_38 ( V_21 -> V_15 ) ) == NULL )
goto V_45;
if ( V_21 -> V_16 != NULL )
{
V_8 -> V_33 = F_27 ( V_21 -> V_16 ) ;
if ( ( V_8 -> V_16 = F_38 ( V_21 -> V_16 ) ) == NULL )
goto V_45;
}
if ( V_21 -> V_17 != NULL )
if ( ( V_8 -> V_17 = F_38 ( V_21 -> V_17 ) ) == NULL )
goto V_45;
if ( V_21 -> V_18 != NULL )
if ( ( V_8 -> V_18 = F_38 ( V_21 -> V_18 ) ) == NULL )
goto V_45;
if ( V_21 -> V_19 != NULL )
if ( ( V_8 -> V_19 = F_38 ( V_21 -> V_19 ) ) == NULL )
goto V_45;
return V_8 ;
V_45:
if ( V_8 != NULL )
F_39 ( V_8 ) ;
return NULL ;
}
