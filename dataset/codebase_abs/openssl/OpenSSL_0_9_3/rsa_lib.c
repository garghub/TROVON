T_1 * F_1 ( void )
{
return ( F_2 ( NULL ) ) ;
}
void F_3 ( T_2 * V_1 )
{
V_2 = V_1 ;
}
T_1 * F_2 ( T_2 * V_1 )
{
T_1 * V_3 ;
if ( V_2 == NULL )
{
#ifdef F_4
V_2 = F_5 () ;
#else
V_2 = F_6 () ;
#endif
}
V_3 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
if ( V_3 == NULL )
{
F_7 ( V_4 , V_5 ) ;
return ( NULL ) ;
}
if ( V_1 == NULL )
V_3 -> V_1 = V_2 ;
else
V_3 -> V_1 = V_1 ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_8 = NULL ;
V_3 -> V_9 = NULL ;
V_3 -> V_10 = NULL ;
V_3 -> V_11 = NULL ;
V_3 -> V_12 = NULL ;
V_3 -> V_13 = NULL ;
V_3 -> V_14 = NULL ;
V_3 -> V_15 = NULL ;
V_3 -> V_16 = 1 ;
V_3 -> V_17 = NULL ;
V_3 -> V_18 = NULL ;
V_3 -> V_19 = NULL ;
V_3 -> V_20 = NULL ;
V_3 -> V_21 = NULL ;
V_3 -> V_22 = V_3 -> V_1 -> V_22 ;
if ( ( V_3 -> V_1 -> V_23 != NULL ) && ! V_3 -> V_1 -> V_23 ( V_3 ) )
{
Free ( V_3 ) ;
V_3 = NULL ;
}
else
F_8 ( V_24 , ( char * ) V_3 , & V_3 -> V_25 ) ;
return ( V_3 ) ;
}
void F_9 ( T_1 * V_26 )
{
int V_27 ;
if ( V_26 == NULL ) return;
V_27 = F_10 ( & V_26 -> V_16 , - 1 , V_28 ) ;
#ifdef F_11
F_11 ( L_1 , V_26 ) ;
#endif
if ( V_27 > 0 ) return;
#ifdef F_12
if ( V_27 < 0 )
{
fprintf ( V_29 , L_2 ) ;
abort () ;
}
#endif
F_13 ( V_24 , ( char * ) V_26 , & V_26 -> V_25 ) ;
if ( V_26 -> V_1 -> V_30 != NULL )
V_26 -> V_1 -> V_30 ( V_26 ) ;
if ( V_26 -> V_8 != NULL ) F_14 ( V_26 -> V_8 ) ;
if ( V_26 -> V_9 != NULL ) F_14 ( V_26 -> V_9 ) ;
if ( V_26 -> V_10 != NULL ) F_14 ( V_26 -> V_10 ) ;
if ( V_26 -> V_11 != NULL ) F_14 ( V_26 -> V_11 ) ;
if ( V_26 -> V_12 != NULL ) F_14 ( V_26 -> V_12 ) ;
if ( V_26 -> V_13 != NULL ) F_14 ( V_26 -> V_13 ) ;
if ( V_26 -> V_14 != NULL ) F_14 ( V_26 -> V_14 ) ;
if ( V_26 -> V_15 != NULL ) F_14 ( V_26 -> V_15 ) ;
if ( V_26 -> V_20 != NULL ) F_15 ( V_26 -> V_20 ) ;
if ( V_26 -> V_21 != NULL ) F_16 ( V_26 -> V_21 ) ;
Free ( V_26 ) ;
}
int F_17 ( long V_31 , char * V_32 , int (* F_18)() ,
int (* F_19)() , void (* F_20)() )
{
V_33 ++ ;
return ( F_21 ( V_33 - 1 ,
& V_24 , V_31 , V_32 , F_18 , F_19 , F_20 ) ) ;
}
int F_22 ( T_1 * V_26 , int V_34 , char * V_35 )
{
return ( F_23 ( & V_26 -> V_25 , V_34 , V_35 ) ) ;
}
char * F_24 ( T_1 * V_26 , int V_34 )
{
return ( F_25 ( & V_26 -> V_25 , V_34 ) ) ;
}
int F_26 ( T_1 * V_26 )
{
return ( F_27 ( V_26 -> V_8 ) ) ;
}
int F_28 ( int V_36 , unsigned char * V_37 , unsigned char * V_38 ,
T_1 * V_39 , int V_40 )
{
return ( V_39 -> V_1 -> V_41 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ) ;
}
int F_29 ( int V_36 , unsigned char * V_37 , unsigned char * V_38 ,
T_1 * V_39 , int V_40 )
{
return ( V_39 -> V_1 -> V_42 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ) ;
}
int F_30 ( int V_36 , unsigned char * V_37 , unsigned char * V_38 ,
T_1 * V_39 , int V_40 )
{
return ( V_39 -> V_1 -> V_43 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ) ;
}
int F_31 ( int V_36 , unsigned char * V_37 , unsigned char * V_38 ,
T_1 * V_39 , int V_40 )
{
return ( V_39 -> V_1 -> V_44 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ) ;
}
int F_32 ( T_1 * V_26 )
{
return ( ( V_26 == NULL ) ? 0 : V_26 -> V_1 -> V_22 ) ;
}
void F_33 ( T_1 * V_39 )
{
if ( V_39 -> V_20 != NULL )
{
F_15 ( V_39 -> V_20 ) ;
V_39 -> V_20 = NULL ;
}
V_39 -> V_22 &= ~ V_45 ;
}
int F_34 ( T_1 * V_39 , T_3 * V_46 )
{
T_4 * V_47 , * V_48 ;
T_3 * V_49 ;
int V_3 = 0 ;
if ( V_46 == NULL )
{
if ( ( V_49 = F_35 () ) == NULL ) goto V_50;
}
else
V_49 = V_46 ;
if ( V_39 -> V_20 != NULL )
F_15 ( V_39 -> V_20 ) ;
V_47 = & ( V_49 -> V_51 [ 0 ] ) ;
V_49 -> V_52 ++ ;
if ( ! F_36 ( V_47 , F_37 ( V_39 -> V_8 ) - 1 , 1 , 0 ) ) goto V_50;
if ( ( V_48 = F_38 ( NULL , V_47 , V_39 -> V_8 , V_49 ) ) == NULL ) goto V_50;
if ( ! V_39 -> V_1 -> V_53 ( V_47 , V_47 , V_39 -> V_9 , V_39 -> V_8 , V_49 , V_39 -> V_17 ) )
goto V_50;
V_39 -> V_20 = F_39 ( V_47 , V_48 , V_39 -> V_8 ) ;
V_49 -> V_52 -- ;
V_39 -> V_22 |= V_45 ;
F_40 ( V_48 ) ;
V_3 = 1 ;
V_50:
if ( V_49 != V_46 ) F_41 ( V_49 ) ;
return ( V_3 ) ;
}
int F_42 ( T_1 * V_26 )
{
int V_27 , V_54 , V_55 , V_56 ;
char * V_11 ;
T_4 * V_51 , * * V_57 [ 6 ] , * V_58 ;
T_5 * V_59 ;
if ( V_26 -> V_10 == NULL ) return ( 1 ) ;
V_57 [ 0 ] = & V_26 -> V_10 ;
V_57 [ 1 ] = & V_26 -> V_11 ;
V_57 [ 2 ] = & V_26 -> V_12 ;
V_57 [ 3 ] = & V_26 -> V_13 ;
V_57 [ 4 ] = & V_26 -> V_14 ;
V_57 [ 5 ] = & V_26 -> V_15 ;
V_55 = sizeof( T_4 ) * 6 ;
V_56 = V_55 / sizeof( T_5 ) + 1 ;
V_54 = 1 ;
for ( V_27 = 0 ; V_27 < 6 ; V_27 ++ )
V_54 += ( * V_57 [ V_27 ] ) -> V_60 ;
if ( ( V_11 = F_43 ( ( V_56 + V_54 ) * sizeof( T_5 ) ) ) == NULL )
{
F_7 ( V_61 , V_5 ) ;
return ( 0 ) ;
}
V_51 = ( T_4 * ) V_11 ;
V_59 = ( T_5 * ) & ( V_11 [ V_56 ] ) ;
for ( V_27 = 0 ; V_27 < 6 ; V_27 ++ )
{
V_58 = * ( V_57 [ V_27 ] ) ;
* ( V_57 [ V_27 ] ) = & ( V_51 [ V_27 ] ) ;
memcpy ( ( char * ) & ( V_51 [ V_27 ] ) , ( char * ) V_58 , sizeof( T_4 ) ) ;
V_51 [ V_27 ] . V_22 = V_62 ;
V_51 [ V_27 ] . V_10 = V_59 ;
memcpy ( ( char * ) V_59 , V_58 -> V_10 , sizeof( T_5 ) * V_58 -> V_60 ) ;
V_59 += V_58 -> V_60 ;
F_14 ( V_58 ) ;
}
V_26 -> V_22 &= ~ ( V_63 | V_64 ) ;
V_26 -> V_21 = V_11 ;
return ( 1 ) ;
}
