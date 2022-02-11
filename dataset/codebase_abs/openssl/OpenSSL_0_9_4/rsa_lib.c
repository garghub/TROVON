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
V_2 = F_9 () ;
#endif
}
V_7 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_7 == NULL )
{
F_10 ( V_8 , V_9 ) ;
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
F_11 ( V_27 , ( char * ) V_7 , & V_7 -> V_28 ) ;
return ( V_7 ) ;
}
void F_12 ( T_1 * V_29 )
{
int V_30 ;
if ( V_29 == NULL ) return;
V_30 = F_13 ( & V_29 -> V_20 , - 1 , V_31 ) ;
#ifdef F_14
F_14 ( L_1 , V_29 ) ;
#endif
if ( V_30 > 0 ) return;
#ifdef F_15
if ( V_30 < 0 )
{
fprintf ( V_32 , L_2 ) ;
abort () ;
}
#endif
F_16 ( V_27 , ( char * ) V_29 , & V_29 -> V_28 ) ;
if ( V_29 -> V_1 -> V_5 != NULL )
V_29 -> V_1 -> V_5 ( V_29 ) ;
if ( V_29 -> V_12 != NULL ) F_17 ( V_29 -> V_12 ) ;
if ( V_29 -> V_13 != NULL ) F_17 ( V_29 -> V_13 ) ;
if ( V_29 -> V_14 != NULL ) F_17 ( V_29 -> V_14 ) ;
if ( V_29 -> V_15 != NULL ) F_17 ( V_29 -> V_15 ) ;
if ( V_29 -> V_16 != NULL ) F_17 ( V_29 -> V_16 ) ;
if ( V_29 -> V_17 != NULL ) F_17 ( V_29 -> V_17 ) ;
if ( V_29 -> V_18 != NULL ) F_17 ( V_29 -> V_18 ) ;
if ( V_29 -> V_19 != NULL ) F_17 ( V_29 -> V_19 ) ;
if ( V_29 -> V_24 != NULL ) F_18 ( V_29 -> V_24 ) ;
if ( V_29 -> V_25 != NULL ) F_19 ( V_29 -> V_25 ) ;
Free ( V_29 ) ;
}
int F_20 ( long V_33 , char * V_34 , int (* F_21)() ,
int (* F_22)() , void (* F_23)() )
{
V_35 ++ ;
return ( F_24 ( V_35 - 1 ,
& V_27 , V_33 , V_34 , F_21 , F_22 , F_23 ) ) ;
}
int F_25 ( T_1 * V_29 , int V_36 , char * V_37 )
{
return ( F_26 ( & V_29 -> V_28 , V_36 , V_37 ) ) ;
}
char * F_27 ( T_1 * V_29 , int V_36 )
{
return ( F_28 ( & V_29 -> V_28 , V_36 ) ) ;
}
int F_29 ( T_1 * V_29 )
{
return ( F_30 ( V_29 -> V_12 ) ) ;
}
int F_31 ( int V_38 , unsigned char * V_39 , unsigned char * V_40 ,
T_1 * V_3 , int V_41 )
{
return ( V_3 -> V_1 -> V_42 ( V_38 , V_39 , V_40 , V_3 , V_41 ) ) ;
}
int F_32 ( int V_38 , unsigned char * V_39 , unsigned char * V_40 ,
T_1 * V_3 , int V_41 )
{
return ( V_3 -> V_1 -> V_43 ( V_38 , V_39 , V_40 , V_3 , V_41 ) ) ;
}
int F_33 ( int V_38 , unsigned char * V_39 , unsigned char * V_40 ,
T_1 * V_3 , int V_41 )
{
return ( V_3 -> V_1 -> V_44 ( V_38 , V_39 , V_40 , V_3 , V_41 ) ) ;
}
int F_34 ( int V_38 , unsigned char * V_39 , unsigned char * V_40 ,
T_1 * V_3 , int V_41 )
{
return ( V_3 -> V_1 -> V_45 ( V_38 , V_39 , V_40 , V_3 , V_41 ) ) ;
}
int F_35 ( T_1 * V_29 )
{
return ( ( V_29 == NULL ) ? 0 : V_29 -> V_1 -> V_26 ) ;
}
void F_36 ( T_1 * V_3 )
{
if ( V_3 -> V_24 != NULL )
{
F_18 ( V_3 -> V_24 ) ;
V_3 -> V_24 = NULL ;
}
V_3 -> V_26 &= ~ V_46 ;
}
int F_37 ( T_1 * V_3 , T_3 * V_47 )
{
T_4 * V_48 , * V_49 ;
T_3 * V_50 ;
int V_7 = 0 ;
if ( V_47 == NULL )
{
if ( ( V_50 = F_38 () ) == NULL ) goto V_51;
}
else
V_50 = V_47 ;
if ( V_3 -> V_24 != NULL )
F_18 ( V_3 -> V_24 ) ;
V_48 = & ( V_50 -> V_52 [ 0 ] ) ;
V_50 -> V_53 ++ ;
if ( ! F_39 ( V_48 , F_40 ( V_3 -> V_12 ) - 1 , 1 , 0 ) ) goto V_51;
if ( ( V_49 = F_41 ( NULL , V_48 , V_3 -> V_12 , V_50 ) ) == NULL ) goto V_51;
if ( ! V_3 -> V_1 -> V_54 ( V_48 , V_48 , V_3 -> V_13 , V_3 -> V_12 , V_50 , V_3 -> V_21 ) )
goto V_51;
V_3 -> V_24 = F_42 ( V_48 , V_49 , V_3 -> V_12 ) ;
V_50 -> V_53 -- ;
V_3 -> V_26 |= V_46 ;
F_43 ( V_49 ) ;
V_7 = 1 ;
V_51:
if ( V_50 != V_47 ) F_44 ( V_50 ) ;
return ( V_7 ) ;
}
int F_45 ( T_1 * V_29 )
{
int V_30 , V_55 , V_56 , V_57 ;
char * V_15 ;
T_4 * V_52 , * * V_58 [ 6 ] , * V_59 ;
T_5 * V_60 ;
if ( V_29 -> V_14 == NULL ) return ( 1 ) ;
V_58 [ 0 ] = & V_29 -> V_14 ;
V_58 [ 1 ] = & V_29 -> V_15 ;
V_58 [ 2 ] = & V_29 -> V_16 ;
V_58 [ 3 ] = & V_29 -> V_17 ;
V_58 [ 4 ] = & V_29 -> V_18 ;
V_58 [ 5 ] = & V_29 -> V_19 ;
V_56 = sizeof( T_4 ) * 6 ;
V_57 = V_56 / sizeof( T_5 ) + 1 ;
V_55 = 1 ;
for ( V_30 = 0 ; V_30 < 6 ; V_30 ++ )
V_55 += ( * V_58 [ V_30 ] ) -> V_61 ;
if ( ( V_15 = F_46 ( ( V_57 + V_55 ) * sizeof( T_5 ) ) ) == NULL )
{
F_10 ( V_62 , V_9 ) ;
return ( 0 ) ;
}
V_52 = ( T_4 * ) V_15 ;
V_60 = ( T_5 * ) & ( V_15 [ V_57 ] ) ;
for ( V_30 = 0 ; V_30 < 6 ; V_30 ++ )
{
V_59 = * ( V_58 [ V_30 ] ) ;
* ( V_58 [ V_30 ] ) = & ( V_52 [ V_30 ] ) ;
memcpy ( ( char * ) & ( V_52 [ V_30 ] ) , ( char * ) V_59 , sizeof( T_4 ) ) ;
V_52 [ V_30 ] . V_26 = V_63 ;
V_52 [ V_30 ] . V_14 = V_60 ;
memcpy ( ( char * ) V_60 , V_59 -> V_14 , sizeof( T_5 ) * V_59 -> V_61 ) ;
V_60 += V_59 -> V_61 ;
F_17 ( V_59 ) ;
}
V_29 -> V_26 &= ~ ( V_64 | V_65 ) ;
V_29 -> V_25 = V_15 ;
return ( 1 ) ;
}
