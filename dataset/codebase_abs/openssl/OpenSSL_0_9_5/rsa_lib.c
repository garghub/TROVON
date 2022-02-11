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
return V_2 ;
}
T_2 * F_5 ( T_1 * V_3 )
{
return V_3 -> V_1 ;
}
T_2 * F_6 ( T_1 * V_3 , T_2 * V_1 )
{
T_2 * V_4 ;
V_4 = V_3 -> V_1 ;
if ( V_4 -> V_5 ) V_4 -> V_5 ( V_3 ) ;
V_3 -> V_1 = V_1 ;
if ( V_1 -> V_6 ) V_1 -> V_6 ( V_3 ) ;
return V_4 ;
}
T_1 * F_2 ( T_2 * V_1 )
{
T_1 * V_7 ;
if ( V_2 == NULL )
{
#ifdef F_7
V_2 = F_8 () ;
#else
#ifdef F_9
V_2 = F_10 () ;
#else
V_2 = F_11 () ;
#endif
#endif
}
V_7 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_7 == NULL )
{
F_12 ( V_8 , V_9 ) ;
return ( NULL ) ;
}
if ( V_1 == NULL )
V_7 -> V_1 = V_2 ;
else
V_7 -> V_1 = V_1 ;
V_7 -> V_10 = 0 ;
V_7 -> V_11 = 0 ;
V_7 -> V_12 = NULL ;
V_7 -> V_13 = NULL ;
V_7 -> V_14 = NULL ;
V_7 -> V_15 = NULL ;
V_7 -> V_16 = NULL ;
V_7 -> V_17 = NULL ;
V_7 -> V_18 = NULL ;
V_7 -> V_19 = NULL ;
V_7 -> V_20 = 1 ;
V_7 -> V_21 = NULL ;
V_7 -> V_22 = NULL ;
V_7 -> V_23 = NULL ;
V_7 -> V_24 = NULL ;
V_7 -> V_25 = NULL ;
V_7 -> V_26 = V_7 -> V_1 -> V_26 ;
if ( ( V_7 -> V_1 -> V_6 != NULL ) && ! V_7 -> V_1 -> V_6 ( V_7 ) )
{
Free ( V_7 ) ;
V_7 = NULL ;
}
else
F_13 ( V_27 , V_7 , & V_7 -> V_28 ) ;
return ( V_7 ) ;
}
void F_14 ( T_1 * V_29 )
{
int V_30 ;
if ( V_29 == NULL ) return;
V_30 = F_15 ( & V_29 -> V_20 , - 1 , V_31 ) ;
#ifdef F_16
F_16 ( L_1 , V_29 ) ;
#endif
if ( V_30 > 0 ) return;
#ifdef F_17
if ( V_30 < 0 )
{
fprintf ( V_32 , L_2 ) ;
abort () ;
}
#endif
F_18 ( V_27 , V_29 , & V_29 -> V_28 ) ;
if ( V_29 -> V_1 -> V_5 != NULL )
V_29 -> V_1 -> V_5 ( V_29 ) ;
if ( V_29 -> V_12 != NULL ) F_19 ( V_29 -> V_12 ) ;
if ( V_29 -> V_13 != NULL ) F_19 ( V_29 -> V_13 ) ;
if ( V_29 -> V_14 != NULL ) F_19 ( V_29 -> V_14 ) ;
if ( V_29 -> V_15 != NULL ) F_19 ( V_29 -> V_15 ) ;
if ( V_29 -> V_16 != NULL ) F_19 ( V_29 -> V_16 ) ;
if ( V_29 -> V_17 != NULL ) F_19 ( V_29 -> V_17 ) ;
if ( V_29 -> V_18 != NULL ) F_19 ( V_29 -> V_18 ) ;
if ( V_29 -> V_19 != NULL ) F_19 ( V_29 -> V_19 ) ;
if ( V_29 -> V_24 != NULL ) F_20 ( V_29 -> V_24 ) ;
if ( V_29 -> V_25 != NULL ) F_21 ( V_29 -> V_25 ) ;
Free ( V_29 ) ;
}
int F_22 ( long V_33 , void * V_34 , T_3 * V_35 ,
T_4 * V_36 , T_5 * V_37 )
{
V_38 ++ ;
return ( F_23 ( V_38 - 1 ,
& V_27 , V_33 , V_34 , V_35 , V_36 , V_37 ) ) ;
}
int F_24 ( T_1 * V_29 , int V_39 , void * V_40 )
{
return ( F_25 ( & V_29 -> V_28 , V_39 , V_40 ) ) ;
}
void * F_26 ( T_1 * V_29 , int V_39 )
{
return ( F_27 ( & V_29 -> V_28 , V_39 ) ) ;
}
int F_28 ( T_1 * V_29 )
{
return ( F_29 ( V_29 -> V_12 ) ) ;
}
int F_30 ( int V_41 , unsigned char * V_42 , unsigned char * V_43 ,
T_1 * V_3 , int V_44 )
{
return ( V_3 -> V_1 -> V_45 ( V_41 , V_42 , V_43 , V_3 , V_44 ) ) ;
}
int F_31 ( int V_41 , unsigned char * V_42 , unsigned char * V_43 ,
T_1 * V_3 , int V_44 )
{
return ( V_3 -> V_1 -> V_46 ( V_41 , V_42 , V_43 , V_3 , V_44 ) ) ;
}
int F_32 ( int V_41 , unsigned char * V_42 , unsigned char * V_43 ,
T_1 * V_3 , int V_44 )
{
return ( V_3 -> V_1 -> V_47 ( V_41 , V_42 , V_43 , V_3 , V_44 ) ) ;
}
int F_33 ( int V_41 , unsigned char * V_42 , unsigned char * V_43 ,
T_1 * V_3 , int V_44 )
{
return ( V_3 -> V_1 -> V_48 ( V_41 , V_42 , V_43 , V_3 , V_44 ) ) ;
}
int F_34 ( T_1 * V_29 )
{
return ( ( V_29 == NULL ) ? 0 : V_29 -> V_1 -> V_26 ) ;
}
void F_35 ( T_1 * V_3 )
{
if ( V_3 -> V_24 != NULL )
{
F_20 ( V_3 -> V_24 ) ;
V_3 -> V_24 = NULL ;
}
V_3 -> V_26 &= ~ V_49 ;
}
int F_36 ( T_1 * V_3 , T_6 * V_50 )
{
T_7 * V_51 , * V_52 ;
T_6 * V_53 ;
int V_7 = 0 ;
if ( V_50 == NULL )
{
if ( ( V_53 = F_37 () ) == NULL ) goto V_54;
}
else
V_53 = V_50 ;
if ( V_3 -> V_24 != NULL )
F_20 ( V_3 -> V_24 ) ;
F_38 ( V_53 ) ;
V_51 = F_39 ( V_53 ) ;
if ( ! F_40 ( V_51 , F_41 ( V_3 -> V_12 ) - 1 , 1 , 0 ) ) goto V_54;
if ( ( V_52 = F_42 ( NULL , V_51 , V_3 -> V_12 , V_53 ) ) == NULL ) goto V_54;
if ( ! V_3 -> V_1 -> V_55 ( V_51 , V_51 , V_3 -> V_13 , V_3 -> V_12 , V_53 , V_3 -> V_21 ) )
goto V_54;
V_3 -> V_24 = F_43 ( V_51 , V_52 , V_3 -> V_12 ) ;
V_3 -> V_26 |= V_49 ;
F_44 ( V_52 ) ;
V_7 = 1 ;
V_54:
F_45 ( V_53 ) ;
if ( V_53 != V_50 ) F_46 ( V_53 ) ;
return ( V_7 ) ;
}
int F_47 ( T_1 * V_29 )
{
int V_30 , V_56 , V_57 , V_58 ;
char * V_15 ;
T_7 * V_59 , * * V_60 [ 6 ] , * V_61 ;
T_8 * V_62 ;
if ( V_29 -> V_14 == NULL ) return ( 1 ) ;
V_60 [ 0 ] = & V_29 -> V_14 ;
V_60 [ 1 ] = & V_29 -> V_15 ;
V_60 [ 2 ] = & V_29 -> V_16 ;
V_60 [ 3 ] = & V_29 -> V_17 ;
V_60 [ 4 ] = & V_29 -> V_18 ;
V_60 [ 5 ] = & V_29 -> V_19 ;
V_57 = sizeof( T_7 ) * 6 ;
V_58 = V_57 / sizeof( T_8 ) + 1 ;
V_56 = 1 ;
for ( V_30 = 0 ; V_30 < 6 ; V_30 ++ )
V_56 += ( * V_60 [ V_30 ] ) -> V_63 ;
if ( ( V_15 = F_48 ( ( V_58 + V_56 ) * sizeof( T_8 ) ) ) == NULL )
{
F_12 ( V_64 , V_9 ) ;
return ( 0 ) ;
}
V_59 = ( T_7 * ) V_15 ;
V_62 = ( T_8 * ) & ( V_15 [ V_58 ] ) ;
for ( V_30 = 0 ; V_30 < 6 ; V_30 ++ )
{
V_61 = * ( V_60 [ V_30 ] ) ;
* ( V_60 [ V_30 ] ) = & ( V_59 [ V_30 ] ) ;
memcpy ( ( char * ) & ( V_59 [ V_30 ] ) , ( char * ) V_61 , sizeof( T_7 ) ) ;
V_59 [ V_30 ] . V_26 = V_65 ;
V_59 [ V_30 ] . V_14 = V_62 ;
memcpy ( ( char * ) V_62 , V_61 -> V_14 , sizeof( T_8 ) * V_61 -> V_63 ) ;
V_62 += V_61 -> V_63 ;
F_19 ( V_61 ) ;
}
V_29 -> V_26 &= ~ ( V_66 | V_67 ) ;
V_29 -> V_25 = V_15 ;
return ( 1 ) ;
}
