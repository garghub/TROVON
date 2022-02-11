void F_1 ( const T_1 * V_1 )
{
V_2 = V_1 ;
}
const T_1 * F_2 ( void )
{
if( ! V_2 )
V_2 = F_3 () ;
return V_2 ;
}
T_2 * F_4 ( void )
{
return F_5 ( NULL ) ;
}
int F_6 ( T_2 * V_3 , const T_1 * V_1 )
{
const T_1 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 ) V_4 -> V_5 ( V_3 ) ;
#ifndef F_7
if ( V_3 -> V_6 )
{
F_8 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
#endif
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_7 ) V_1 -> V_7 ( V_3 ) ;
return 1 ;
}
T_2 * F_5 ( T_3 * V_6 )
{
T_2 * V_8 ;
V_8 = ( T_2 * ) F_9 ( sizeof( T_2 ) ) ;
if ( V_8 == NULL )
{
F_10 ( V_9 , V_10 ) ;
return ( NULL ) ;
}
V_8 -> V_1 = F_2 () ;
#ifndef F_7
if ( V_6 )
{
if ( ! F_11 ( V_6 ) )
{
F_10 ( V_9 , V_11 ) ;
F_12 ( V_8 ) ;
return NULL ;
}
V_8 -> V_6 = V_6 ;
}
else
V_8 -> V_6 = F_13 () ;
if( V_8 -> V_6 )
{
V_8 -> V_1 = F_14 ( V_8 -> V_6 ) ;
if( ! V_8 -> V_1 )
{
F_10 ( V_9 ,
V_11 ) ;
F_8 ( V_8 -> V_6 ) ;
F_12 ( V_8 ) ;
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
V_8 -> V_24 = V_8 -> V_1 -> V_24 ;
F_15 ( V_25 , V_8 , & V_8 -> V_26 ) ;
if ( ( V_8 -> V_1 -> V_7 != NULL ) && ! V_8 -> V_1 -> V_7 ( V_8 ) )
{
#ifndef F_7
if ( V_8 -> V_6 )
F_8 ( V_8 -> V_6 ) ;
#endif
F_16 ( V_25 , V_8 , & V_8 -> V_26 ) ;
F_12 ( V_8 ) ;
V_8 = NULL ;
}
return ( V_8 ) ;
}
void F_17 ( T_2 * V_21 )
{
int V_27 ;
if ( V_21 == NULL ) return;
V_27 = F_18 ( & V_21 -> V_23 , - 1 , V_28 ) ;
#ifdef F_19
F_19 ( L_1 , V_21 ) ;
#endif
if ( V_27 > 0 ) return;
#ifdef F_20
if ( V_27 < 0 )
{
fprintf ( V_29 , L_2 ) ;
abort () ;
}
#endif
if( V_21 -> V_1 -> V_5 )
V_21 -> V_1 -> V_5 ( V_21 ) ;
#ifndef F_7
if( V_21 -> V_6 )
F_8 ( V_21 -> V_6 ) ;
#endif
F_16 ( V_25 , V_21 , & V_21 -> V_26 ) ;
if ( V_21 -> V_15 != NULL ) F_21 ( V_21 -> V_15 ) ;
if ( V_21 -> V_16 != NULL ) F_21 ( V_21 -> V_16 ) ;
if ( V_21 -> V_17 != NULL ) F_21 ( V_21 -> V_17 ) ;
if ( V_21 -> V_18 != NULL ) F_21 ( V_21 -> V_18 ) ;
if ( V_21 -> V_19 != NULL ) F_21 ( V_21 -> V_19 ) ;
if ( V_21 -> V_20 != NULL ) F_21 ( V_21 -> V_20 ) ;
if ( V_21 -> V_21 != NULL ) F_21 ( V_21 -> V_21 ) ;
F_12 ( V_21 ) ;
}
int F_22 ( T_2 * V_21 )
{
int V_27 = F_18 ( & V_21 -> V_23 , 1 , V_28 ) ;
#ifdef F_19
F_19 ( L_1 , V_21 ) ;
#endif
#ifdef F_20
if ( V_27 < 2 )
{
fprintf ( V_29 , L_3 ) ;
abort () ;
}
#endif
return ( ( V_27 > 1 ) ? 1 : 0 ) ;
}
int F_23 ( const T_2 * V_21 )
{
int V_8 , V_27 ;
T_4 V_30 ;
unsigned char V_31 [ 4 ] ;
V_27 = F_24 ( V_21 -> V_16 ) ;
V_30 . V_32 = ( V_27 + 7 ) / 8 ;
V_30 . V_33 = V_31 ;
V_30 . type = V_34 ;
V_31 [ 0 ] = 0xff ;
V_27 = F_25 ( & V_30 , NULL ) ;
V_27 += V_27 ;
V_8 = F_26 ( 1 , V_27 , V_35 ) ;
return ( V_8 ) ;
}
int F_27 ( long V_36 , void * V_37 , T_5 * V_38 ,
T_6 * V_39 , T_7 * V_40 )
{
return F_28 ( V_25 , V_36 , V_37 ,
V_38 , V_39 , V_40 ) ;
}
int F_29 ( T_2 * V_41 , int V_42 , void * V_43 )
{
return ( F_30 ( & V_41 -> V_26 , V_42 , V_43 ) ) ;
}
void * F_31 ( T_2 * V_41 , int V_42 )
{
return ( F_32 ( & V_41 -> V_26 , V_42 ) ) ;
}
T_8 * F_33 ( const T_2 * V_21 )
{
T_8 * V_8 = NULL ;
if ( V_21 == NULL )
goto V_44;
V_8 = F_34 () ;
if ( V_8 == NULL )
goto V_44;
if ( V_21 -> V_15 != NULL )
if ( ( V_8 -> V_15 = F_35 ( V_21 -> V_15 ) ) == NULL )
goto V_44;
if ( V_21 -> V_16 != NULL )
V_8 -> V_32 = F_24 ( V_21 -> V_16 ) ;
if ( V_21 -> V_17 != NULL )
if ( ( V_8 -> V_17 = F_35 ( V_21 -> V_17 ) ) == NULL )
goto V_44;
if ( V_21 -> V_18 != NULL )
if ( ( V_8 -> V_18 = F_35 ( V_21 -> V_18 ) ) == NULL )
goto V_44;
if ( V_21 -> V_19 != NULL )
if ( ( V_8 -> V_19 = F_35 ( V_21 -> V_19 ) ) == NULL )
goto V_44;
return V_8 ;
V_44:
if ( V_8 != NULL )
F_36 ( V_8 ) ;
return NULL ;
}
