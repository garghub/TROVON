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
int F_4 ( T_2 * V_3 , const T_1 * V_1 )
{
const T_1 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 ) V_4 -> V_5 ( V_3 ) ;
if ( V_3 -> V_6 )
{
F_5 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_7 ) V_1 -> V_7 ( V_3 ) ;
return 1 ;
}
T_2 * F_6 ( void )
{
return F_7 ( NULL ) ;
}
T_2 * F_7 ( T_3 * V_6 )
{
T_2 * V_8 ;
V_8 = ( T_2 * ) F_8 ( sizeof( T_2 ) ) ;
if ( V_8 == NULL )
{
F_9 ( V_9 , V_10 ) ;
return ( NULL ) ;
}
V_8 -> V_1 = F_2 () ;
if ( V_6 )
{
if ( ! F_10 ( V_6 ) )
{
F_9 ( V_9 , V_11 ) ;
F_11 ( V_8 ) ;
return NULL ;
}
V_8 -> V_6 = V_6 ;
}
else
V_8 -> V_6 = F_12 () ;
if( V_8 -> V_6 )
{
V_8 -> V_1 = F_13 ( V_8 -> V_6 ) ;
if( ! V_8 -> V_1 )
{
F_9 ( V_9 , V_11 ) ;
F_5 ( V_8 -> V_6 ) ;
F_11 ( V_8 ) ;
return NULL ;
}
}
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = NULL ;
V_8 -> V_15 = NULL ;
V_8 -> V_16 = 0 ;
V_8 -> V_17 = NULL ;
V_8 -> V_18 = NULL ;
V_8 -> V_19 = NULL ;
V_8 -> V_20 = NULL ;
V_8 -> V_21 = NULL ;
V_8 -> V_22 = 0 ;
V_8 -> V_23 = NULL ;
V_8 -> V_24 = NULL ;
V_8 -> V_25 = 1 ;
V_8 -> V_26 = V_8 -> V_1 -> V_26 ;
F_14 ( V_27 , V_8 , & V_8 -> V_28 ) ;
if ( ( V_8 -> V_1 -> V_7 != NULL ) && ! V_8 -> V_1 -> V_7 ( V_8 ) )
{
if ( V_8 -> V_6 )
F_5 ( V_8 -> V_6 ) ;
F_15 ( V_27 , V_8 , & V_8 -> V_28 ) ;
F_11 ( V_8 ) ;
V_8 = NULL ;
}
return ( V_8 ) ;
}
void F_16 ( T_2 * V_29 )
{
int V_30 ;
if( V_29 == NULL ) return;
V_30 = F_17 ( & V_29 -> V_25 , - 1 , V_31 ) ;
#ifdef F_18
F_18 ( L_1 , V_29 ) ;
#endif
if ( V_30 > 0 ) return;
#ifdef F_19
if ( V_30 < 0 )
{
fprintf ( V_32 , L_2 ) ;
abort () ;
}
#endif
if ( V_29 -> V_1 -> V_5 )
V_29 -> V_1 -> V_5 ( V_29 ) ;
if ( V_29 -> V_6 )
F_5 ( V_29 -> V_6 ) ;
F_15 ( V_27 , V_29 , & V_29 -> V_28 ) ;
if ( V_29 -> V_14 != NULL ) F_20 ( V_29 -> V_14 ) ;
if ( V_29 -> V_15 != NULL ) F_20 ( V_29 -> V_15 ) ;
if ( V_29 -> V_19 != NULL ) F_20 ( V_29 -> V_19 ) ;
if ( V_29 -> V_20 != NULL ) F_20 ( V_29 -> V_20 ) ;
if ( V_29 -> V_21 ) F_11 ( V_29 -> V_21 ) ;
if ( V_29 -> V_23 != NULL ) F_20 ( V_29 -> V_23 ) ;
if ( V_29 -> V_17 != NULL ) F_20 ( V_29 -> V_17 ) ;
if ( V_29 -> V_18 != NULL ) F_20 ( V_29 -> V_18 ) ;
F_11 ( V_29 ) ;
}
int F_21 ( T_2 * V_29 )
{
int V_30 = F_17 ( & V_29 -> V_25 , 1 , V_31 ) ;
#ifdef F_18
F_18 ( L_1 , V_29 ) ;
#endif
#ifdef F_19
if ( V_30 < 2 )
{
fprintf ( V_32 , L_3 ) ;
abort () ;
}
#endif
return ( ( V_30 > 1 ) ? 1 : 0 ) ;
}
int F_22 ( long V_33 , void * V_34 , T_4 * V_35 ,
T_5 * V_36 , T_6 * V_37 )
{
return F_23 ( V_27 , V_33 , V_34 ,
V_35 , V_36 , V_37 ) ;
}
int F_24 ( T_2 * V_38 , int V_39 , void * V_40 )
{
return ( F_25 ( & V_38 -> V_28 , V_39 , V_40 ) ) ;
}
void * F_26 ( T_2 * V_38 , int V_39 )
{
return ( F_27 ( & V_38 -> V_28 , V_39 ) ) ;
}
int F_28 ( const T_2 * V_3 )
{
return ( F_29 ( V_3 -> V_14 ) ) ;
}
