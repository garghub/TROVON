T_1 * F_1 ( void )
{
return ( F_2 ( NULL ) ) ;
}
void F_3 ( const T_2 * V_1 )
{
V_2 = V_1 ;
}
const T_2 * F_4 ( void )
{
if ( V_2 == NULL )
{
#ifdef F_5
V_2 = F_6 () ;
#else
#if 0
default_RSA_meth=RSA_PKCS1_RSAref();
#else
V_2 = F_7 () ;
#endif
#endif
}
return V_2 ;
}
const T_2 * F_8 ( const T_1 * V_3 )
{
return V_3 -> V_1 ;
}
int F_9 ( T_1 * V_3 , const T_2 * V_1 )
{
const T_2 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 ) V_4 -> V_5 ( V_3 ) ;
if ( V_3 -> V_6 )
{
F_10 ( V_3 -> V_6 ) ;
V_3 -> V_6 = NULL ;
}
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_7 ) V_1 -> V_7 ( V_3 ) ;
return 1 ;
}
T_1 * F_2 ( T_3 * V_6 )
{
T_1 * V_8 ;
V_8 = ( T_1 * ) F_11 ( sizeof( T_1 ) ) ;
if ( V_8 == NULL )
{
F_12 ( V_9 , V_10 ) ;
return NULL ;
}
V_8 -> V_1 = F_4 () ;
if ( V_6 )
{
if ( ! F_13 ( V_6 ) )
{
F_12 ( V_9 , V_11 ) ;
F_14 ( V_8 ) ;
return NULL ;
}
V_8 -> V_6 = V_6 ;
}
else
V_8 -> V_6 = F_15 () ;
if( V_8 -> V_6 )
{
V_8 -> V_1 = F_16 ( V_8 -> V_6 ) ;
if( ! V_8 -> V_1 )
{
F_12 ( V_9 ,
V_11 ) ;
F_10 ( V_8 -> V_6 ) ;
F_14 ( V_8 ) ;
return NULL ;
}
}
V_8 -> V_12 = 0 ;
V_8 -> V_13 = 0 ;
V_8 -> V_14 = NULL ;
V_8 -> V_15 = NULL ;
V_8 -> V_16 = NULL ;
V_8 -> V_17 = NULL ;
V_8 -> V_18 = NULL ;
V_8 -> V_19 = NULL ;
V_8 -> V_20 = NULL ;
V_8 -> V_21 = NULL ;
V_8 -> V_22 = 1 ;
V_8 -> V_23 = NULL ;
V_8 -> V_24 = NULL ;
V_8 -> V_25 = NULL ;
V_8 -> V_26 = NULL ;
V_8 -> V_27 = NULL ;
V_8 -> V_28 = V_8 -> V_1 -> V_28 ;
F_17 ( V_29 , V_8 , & V_8 -> V_30 ) ;
if ( ( V_8 -> V_1 -> V_7 != NULL ) && ! V_8 -> V_1 -> V_7 ( V_8 ) )
{
if ( V_8 -> V_6 )
F_10 ( V_8 -> V_6 ) ;
F_18 ( V_29 , V_8 , & V_8 -> V_30 ) ;
F_14 ( V_8 ) ;
V_8 = NULL ;
}
return ( V_8 ) ;
}
void F_19 ( T_1 * V_31 )
{
int V_32 ;
if ( V_31 == NULL ) return;
V_32 = F_20 ( & V_31 -> V_22 , - 1 , V_33 ) ;
#ifdef F_21
F_21 ( L_1 , V_31 ) ;
#endif
if ( V_32 > 0 ) return;
#ifdef F_22
if ( V_32 < 0 )
{
fprintf ( V_34 , L_2 ) ;
abort () ;
}
#endif
if ( V_31 -> V_1 -> V_5 )
V_31 -> V_1 -> V_5 ( V_31 ) ;
if ( V_31 -> V_6 )
F_10 ( V_31 -> V_6 ) ;
F_18 ( V_29 , V_31 , & V_31 -> V_30 ) ;
if ( V_31 -> V_14 != NULL ) F_23 ( V_31 -> V_14 ) ;
if ( V_31 -> V_15 != NULL ) F_23 ( V_31 -> V_15 ) ;
if ( V_31 -> V_16 != NULL ) F_23 ( V_31 -> V_16 ) ;
if ( V_31 -> V_17 != NULL ) F_23 ( V_31 -> V_17 ) ;
if ( V_31 -> V_18 != NULL ) F_23 ( V_31 -> V_18 ) ;
if ( V_31 -> V_19 != NULL ) F_23 ( V_31 -> V_19 ) ;
if ( V_31 -> V_20 != NULL ) F_23 ( V_31 -> V_20 ) ;
if ( V_31 -> V_21 != NULL ) F_23 ( V_31 -> V_21 ) ;
if ( V_31 -> V_26 != NULL ) F_24 ( V_31 -> V_26 ) ;
if ( V_31 -> V_27 != NULL ) F_25 ( V_31 -> V_27 ) ;
F_14 ( V_31 ) ;
}
int F_26 ( T_1 * V_31 )
{
int V_32 = F_20 ( & V_31 -> V_22 , 1 , V_33 ) ;
#ifdef F_21
F_21 ( L_1 , V_31 ) ;
#endif
#ifdef F_22
if ( V_32 < 2 )
{
fprintf ( V_34 , L_3 ) ;
abort () ;
}
#endif
return ( ( V_32 > 1 ) ? 1 : 0 ) ;
}
int F_27 ( long V_35 , void * V_36 , T_4 * V_37 ,
T_5 * V_38 , T_6 * V_39 )
{
return F_28 ( V_29 , V_35 , V_36 ,
V_37 , V_38 , V_39 ) ;
}
int F_29 ( T_1 * V_31 , int V_40 , void * V_41 )
{
return ( F_30 ( & V_31 -> V_30 , V_40 , V_41 ) ) ;
}
void * F_31 ( const T_1 * V_31 , int V_40 )
{
return ( F_32 ( & V_31 -> V_30 , V_40 ) ) ;
}
int F_33 ( const T_1 * V_31 )
{
return ( F_34 ( V_31 -> V_14 ) ) ;
}
int F_35 ( int V_42 , const unsigned char * V_43 , unsigned char * V_44 ,
T_1 * V_3 , int V_45 )
{
return ( V_3 -> V_1 -> V_46 ( V_42 , V_43 , V_44 , V_3 , V_45 ) ) ;
}
int F_36 ( int V_42 , const unsigned char * V_43 , unsigned char * V_44 ,
T_1 * V_3 , int V_45 )
{
return ( V_3 -> V_1 -> V_47 ( V_42 , V_43 , V_44 , V_3 , V_45 ) ) ;
}
int F_37 ( int V_42 , const unsigned char * V_43 , unsigned char * V_44 ,
T_1 * V_3 , int V_45 )
{
return ( V_3 -> V_1 -> V_48 ( V_42 , V_43 , V_44 , V_3 , V_45 ) ) ;
}
int F_38 ( int V_42 , const unsigned char * V_43 , unsigned char * V_44 ,
T_1 * V_3 , int V_45 )
{
return ( V_3 -> V_1 -> V_49 ( V_42 , V_43 , V_44 , V_3 , V_45 ) ) ;
}
int F_39 ( const T_1 * V_31 )
{
return ( ( V_31 == NULL ) ? 0 : V_31 -> V_1 -> V_28 ) ;
}
void F_40 ( T_1 * V_3 )
{
if ( V_3 -> V_26 != NULL )
{
F_24 ( V_3 -> V_26 ) ;
V_3 -> V_26 = NULL ;
}
V_3 -> V_28 &= ~ V_50 ;
}
int F_41 ( T_1 * V_3 , T_7 * V_51 )
{
T_8 * V_52 , * V_53 ;
T_7 * V_54 ;
int V_8 = 0 ;
if ( V_51 == NULL )
{
if ( ( V_54 = F_42 () ) == NULL ) goto V_55;
}
else
V_54 = V_51 ;
if ( V_3 -> V_26 != NULL )
F_24 ( V_3 -> V_26 ) ;
F_43 ( V_54 ) ;
V_52 = F_44 ( V_54 ) ;
if ( ! F_45 ( V_52 , V_3 -> V_14 ) ) goto V_55;
if ( ( V_53 = F_46 ( NULL , V_52 , V_3 -> V_14 , V_54 ) ) == NULL ) goto V_55;
if ( ! V_3 -> V_1 -> V_56 ( V_52 , V_52 , V_3 -> V_15 , V_3 -> V_14 , V_54 , V_3 -> V_23 ) )
goto V_55;
V_3 -> V_26 = F_47 ( V_52 , V_53 , V_3 -> V_14 ) ;
V_3 -> V_28 |= V_50 ;
F_48 ( V_53 ) ;
V_8 = 1 ;
V_55:
F_49 ( V_54 ) ;
if ( V_54 != V_51 ) F_50 ( V_54 ) ;
return ( V_8 ) ;
}
int F_51 ( T_1 * V_31 )
{
int V_32 , V_57 , V_58 , V_59 ;
char * V_17 ;
T_8 * V_60 , * * V_61 [ 6 ] , * V_62 ;
T_9 * V_63 ;
if ( V_31 -> V_16 == NULL ) return ( 1 ) ;
V_61 [ 0 ] = & V_31 -> V_16 ;
V_61 [ 1 ] = & V_31 -> V_17 ;
V_61 [ 2 ] = & V_31 -> V_18 ;
V_61 [ 3 ] = & V_31 -> V_19 ;
V_61 [ 4 ] = & V_31 -> V_20 ;
V_61 [ 5 ] = & V_31 -> V_21 ;
V_58 = sizeof( T_8 ) * 6 ;
V_59 = V_58 / sizeof( T_9 ) + 1 ;
V_57 = 1 ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
V_57 += ( * V_61 [ V_32 ] ) -> V_64 ;
if ( ( V_17 = F_52 ( ( V_59 + V_57 ) * sizeof( T_9 ) ) ) == NULL )
{
F_12 ( V_65 , V_10 ) ;
return ( 0 ) ;
}
V_60 = ( T_8 * ) V_17 ;
V_63 = ( T_9 * ) & ( V_17 [ V_59 ] ) ;
for ( V_32 = 0 ; V_32 < 6 ; V_32 ++ )
{
V_62 = * ( V_61 [ V_32 ] ) ;
* ( V_61 [ V_32 ] ) = & ( V_60 [ V_32 ] ) ;
memcpy ( ( char * ) & ( V_60 [ V_32 ] ) , ( char * ) V_62 , sizeof( T_8 ) ) ;
V_60 [ V_32 ] . V_28 = V_66 ;
V_60 [ V_32 ] . V_16 = V_63 ;
memcpy ( ( char * ) V_63 , V_62 -> V_16 , sizeof( T_9 ) * V_62 -> V_64 ) ;
V_63 += V_62 -> V_64 ;
F_23 ( V_62 ) ;
}
V_31 -> V_28 &= ~ ( V_67 | V_68 ) ;
V_31 -> V_27 = V_17 ;
return ( 1 ) ;
}
