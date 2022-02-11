T_1 * F_1 ( void )
{
return ( F_2 ( NULL ) ) ;
}
void F_3 ( T_2 * V_1 )
{
V_2 = V_1 ;
}
T_2 * F_4 ( void )
{
return ( V_2 ) ;
}
T_2 * F_5 ( T_1 * V_3 )
{
return ( V_3 -> V_1 ) ;
}
T_2 * F_6 ( T_1 * V_3 , T_2 * V_1 )
{
T_2 * V_4 ;
V_4 = V_3 -> V_1 ;
V_3 -> V_1 = V_1 ;
return ( V_4 ) ;
}
T_1 * F_2 ( T_2 * V_1 )
{
T_1 * V_5 ;
if( V_2 == NULL )
V_2 = F_7 () ;
V_5 = ( T_1 * ) F_8 ( sizeof( T_1 ) ) ;
if( V_5 == NULL )
{
F_9 ( V_6 , V_7 ) ;
return ( NULL ) ;
}
memset ( V_5 , 0 , sizeof( T_1 ) ) ;
V_5 -> V_8 = F_10 () ;
if( ( V_5 -> V_8 = F_10 () ) == NULL )
{
F_9 ( V_6 , V_7 ) ;
F_11 ( V_5 ) ;
return ( NULL ) ;
}
if( V_1 == NULL )
V_5 -> V_1 = V_2 ;
else
V_5 -> V_1 = V_1 ;
V_5 -> V_9 = 1 ;
if( ( V_5 -> V_1 -> V_10 != NULL ) && ! V_5 -> V_1 -> V_10 ( V_5 ) )
{
F_11 ( V_5 ) ;
V_5 = NULL ;
}
return ( V_5 ) ;
}
int F_12 ( T_1 * V_3 )
{
int V_11 ;
if( V_3 == NULL )
{
F_9 ( V_12 , V_13 ) ;
return ( 0 ) ;
}
V_11 = F_13 ( & V_3 -> V_9 , - 1 , V_14 ) ;
#ifdef F_14
F_14 ( L_1 , V_3 ) ;
#endif
if( V_11 > 0 ) return ( 1 ) ;
#ifdef F_15
if( V_11 < 0 )
{
fprintf ( V_15 , L_2 ) ;
abort () ;
}
#endif
if( ( V_3 -> V_1 -> V_16 != NULL ) && ! V_3 -> V_1 -> V_16 ( V_3 ) )
{
F_9 ( V_12 , V_17 ) ;
return ( 0 ) ;
}
if( ( V_3 -> V_1 -> V_18 != NULL ) && ! V_3 -> V_1 -> V_18 ( V_3 ) )
{
F_9 ( V_12 , V_19 ) ;
return ( 0 ) ;
}
F_16 ( V_3 -> V_8 ) ;
F_11 ( V_3 ) ;
return ( 1 ) ;
}
int F_17 ( T_1 * V_3 )
{
return ( ( V_3 == NULL ) ? 0 : V_3 -> V_20 ) ;
}
int F_18 ( T_1 * V_3 )
{
if ( V_3 == NULL )
{
F_9 ( V_21 , V_13 ) ;
return ( 0 ) ;
}
F_13 ( & V_3 -> V_9 , 1 , V_14 ) ;
return ( 1 ) ;
}
T_1 * F_19 ( T_1 * V_3 , const char * V_22 , T_2 * V_1 , int V_20 )
{
T_1 * V_5 ;
int V_23 = 0 ;
if( V_22 == NULL )
{
F_9 ( V_24 , V_13 ) ;
return ( NULL ) ;
}
if( V_3 == NULL )
{
V_5 = F_2 ( V_1 ) ;
if( V_5 == NULL )
{
F_9 ( V_24 , V_7 ) ;
return ( NULL ) ;
}
V_23 = 1 ;
}
else
V_5 = V_3 ;
if( F_20 ( V_5 , V_25 , V_20 , NULL ) < 0 )
{
F_9 ( V_24 , V_26 ) ;
if( V_23 )
F_12 ( V_5 ) ;
return ( NULL ) ;
}
if( V_5 -> V_1 -> V_27 == NULL )
{
F_9 ( V_24 , V_28 ) ;
if( V_23 )
F_12 ( V_5 ) ;
return ( NULL ) ;
}
if( ! V_5 -> V_1 -> V_27 ( V_5 , V_22 ) )
{
F_9 ( V_24 , V_29 ) ;
if( V_23 )
F_12 ( V_5 ) ;
return ( NULL ) ;
}
return ( V_5 ) ;
}
void * F_21 ( T_1 * V_3 , const char * V_30 )
{
void * V_5 = NULL ;
if( ( V_3 == NULL ) || ( V_30 == NULL ) )
{
F_9 ( V_31 , V_13 ) ;
return ( NULL ) ;
}
if( V_3 -> V_1 -> V_32 == NULL )
{
F_9 ( V_31 , V_28 ) ;
return ( NULL ) ;
}
if( ( V_5 = V_3 -> V_1 -> V_32 ( V_3 , V_30 ) ) == NULL )
{
F_9 ( V_31 , V_33 ) ;
return ( NULL ) ;
}
return ( V_5 ) ;
}
T_3 F_22 ( T_1 * V_3 , const char * V_30 )
{
T_3 V_5 = NULL ;
if( ( V_3 == NULL ) || ( V_30 == NULL ) )
{
F_9 ( V_34 , V_13 ) ;
return ( NULL ) ;
}
if( V_3 -> V_1 -> V_35 == NULL )
{
F_9 ( V_34 , V_28 ) ;
return ( NULL ) ;
}
if( ( V_5 = V_3 -> V_1 -> V_35 ( V_3 , V_30 ) ) == NULL )
{
F_9 ( V_34 , V_33 ) ;
return ( NULL ) ;
}
return ( V_5 ) ;
}
long F_20 ( T_1 * V_3 , int V_36 , long V_37 , void * V_38 )
{
if( V_3 == NULL )
{
F_9 ( V_39 , V_13 ) ;
return ( - 1 ) ;
}
if( ( V_3 -> V_1 == NULL ) || ( V_3 -> V_1 -> V_40 == NULL ) )
{
F_9 ( V_39 , V_28 ) ;
return ( - 1 ) ;
}
return ( V_3 -> V_1 -> V_40 ( V_3 , V_36 , V_37 , V_38 ) ) ;
}
