int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
T_2 * V_4 , T_3 * V_5 )
{
T_1 * V_6 ;
int V_7 = 0 ;
F_2 ( V_5 ) ;
V_6 = F_3 ( V_5 ) ;
if ( V_6 == NULL ) goto V_8;
F_4 ( V_6 ) ;
if ( V_2 == V_3 )
{
if ( ! F_5 ( V_6 , V_2 , V_5 ) ) goto V_8;
}
else
{
if ( ! F_6 ( V_6 , V_2 , V_3 , V_5 ) ) goto V_8;
}
if ( ! F_7 ( V_1 , V_6 , V_4 , V_5 ) ) goto V_8;
V_7 = 1 ;
V_8:
F_8 ( V_5 ) ;
return ( V_7 ) ;
}
int F_7 ( T_1 * V_7 , const T_1 * V_2 , T_2 * V_4 ,
T_3 * V_5 )
{
int V_9 = 0 ;
#ifdef F_9
T_1 * V_10 , * V_1 ;
T_4 * V_11 , * V_12 , * V_13 , V_14 , V_15 , * V_16 ;
int V_17 , V_18 , V_19 , V_20 , V_21 , V_22 ;
F_2 ( V_5 ) ;
if ( ( V_1 = F_3 ( V_5 ) ) == NULL ) goto V_8;
if ( ! F_10 ( V_1 , V_2 ) ) goto V_8;
V_10 = & ( V_4 -> V_23 ) ;
V_11 = V_2 -> V_24 ;
V_17 = V_22 = V_4 -> V_22 / V_25 ;
V_18 = V_10 -> V_26 ;
if ( ( V_17 == 0 ) || ( V_18 == 0 ) ) { V_1 -> V_26 = 0 ; return ( 1 ) ; }
V_19 = ( V_18 + V_17 + 1 ) ;
if ( F_11 ( V_1 , V_19 ) == NULL ) goto V_8;
if ( F_11 ( V_7 , V_19 ) == NULL ) goto V_8;
V_1 -> V_27 = V_2 -> V_27 ^ V_10 -> V_27 ;
V_12 = V_10 -> V_24 ;
V_13 = V_1 -> V_24 ;
V_16 = & ( V_1 -> V_24 [ V_18 ] ) ;
#if 1
for ( V_20 = V_1 -> V_26 ; V_20 < V_19 ; V_20 ++ )
V_1 -> V_24 [ V_20 ] = 0 ;
#else
memset ( & ( V_1 -> V_24 [ V_1 -> V_26 ] ) , 0 , ( V_19 - V_1 -> V_26 ) * sizeof( T_4 ) ) ;
#endif
V_1 -> V_26 = V_19 ;
V_14 = V_4 -> V_14 ;
#ifdef F_12
fprintf ( V_28 , L_1 , V_18 , V_18 ) ;
#endif
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ )
{
#ifdef F_13
{
long long V_29 ;
long long V_30 ;
long long V_31 ;
V_29 = V_13 [ 0 ] * ( V_14 & 0177777 ) ;
V_30 = 037777600000l ;
V_30 = V_14 & V_30 ;
V_31 = V_13 [ 0 ] & 0177777 ;
V_30 = ( V_31 * V_30 ) & V_32 ;
V_29 = V_29 + V_30 ;
V_15 = F_14 ( V_13 , V_12 , V_18 , ( T_4 ) V_29 ) ;
}
#else
V_15 = F_14 ( V_13 , V_12 , V_18 , ( V_13 [ 0 ] * V_14 ) & V_32 ) ;
#endif
V_16 ++ ;
V_13 ++ ;
if ( ( ( V_16 [ - 1 ] += V_15 ) & V_32 ) >= V_15 )
continue;
else
{
if ( ( ( ++ V_16 [ 0 ] ) & V_32 ) != 0 ) continue;
if ( ( ( ++ V_16 [ 1 ] ) & V_32 ) != 0 ) continue;
for ( V_21 = 2 ; ( ( ( ++ V_16 [ V_21 ] ) & V_32 ) == 0 ) ; V_21 ++ ) ;
}
}
F_15 ( V_1 ) ;
#if 0
BN_rshift(ret,r,mont->ri);
#else
V_7 -> V_27 = V_1 -> V_27 ;
V_21 = V_22 ;
V_13 = V_7 -> V_24 ;
V_11 = & ( V_1 -> V_24 [ V_21 ] ) ;
if ( V_1 -> V_26 < V_21 )
V_17 = 0 ;
else
V_17 = V_1 -> V_26 - V_21 ;
V_7 -> V_26 = V_17 ;
V_17 -= 4 ;
for ( V_20 = 0 ; V_20 < V_17 ; V_20 += 4 )
{
T_4 V_29 , V_30 , V_31 , V_33 ;
V_29 = V_11 [ V_20 + 0 ] ;
V_30 = V_11 [ V_20 + 1 ] ;
V_31 = V_11 [ V_20 + 2 ] ;
V_33 = V_11 [ V_20 + 3 ] ;
V_13 [ V_20 + 0 ] = V_29 ;
V_13 [ V_20 + 1 ] = V_30 ;
V_13 [ V_20 + 2 ] = V_31 ;
V_13 [ V_20 + 3 ] = V_33 ;
}
V_17 += 4 ;
for (; V_20 < V_17 ; V_20 ++ )
V_13 [ V_20 ] = V_11 [ V_20 ] ;
#endif
#else
T_1 * V_29 , * V_30 ;
F_2 ( V_5 ) ;
V_29 = F_3 ( V_5 ) ;
V_30 = F_3 ( V_5 ) ;
if ( V_29 == NULL || V_30 == NULL ) goto V_8;
if ( ! F_10 ( V_29 , V_2 ) ) goto V_8;
F_16 ( V_29 , V_4 -> V_22 ) ;
if ( ! F_6 ( V_30 , V_29 , & V_4 -> V_34 , V_5 ) ) goto V_8;
F_16 ( V_30 , V_4 -> V_22 ) ;
if ( ! F_6 ( V_29 , V_30 , & V_4 -> V_23 , V_5 ) ) goto V_8;
if ( ! F_17 ( V_30 , V_2 , V_29 ) ) goto V_8;
if ( ! F_18 ( V_7 , V_30 , V_4 -> V_22 ) ) goto V_8;
#endif
if ( F_19 ( V_7 , & ( V_4 -> V_23 ) ) >= 0 )
{
if ( ! F_20 ( V_7 , V_7 , & ( V_4 -> V_23 ) ) ) goto V_8;
}
V_9 = 1 ;
V_8:
F_8 ( V_5 ) ;
return ( V_9 ) ;
}
T_2 * F_21 ( void )
{
T_2 * V_7 ;
if ( ( V_7 = ( T_2 * ) F_22 ( sizeof( T_2 ) ) ) == NULL )
return ( NULL ) ;
F_23 ( V_7 ) ;
V_7 -> V_35 = V_36 ;
return ( V_7 ) ;
}
void F_23 ( T_2 * V_5 )
{
V_5 -> V_22 = 0 ;
F_24 ( & ( V_5 -> V_37 ) ) ;
F_24 ( & ( V_5 -> V_23 ) ) ;
F_24 ( & ( V_5 -> V_34 ) ) ;
V_5 -> V_35 = 0 ;
}
void F_25 ( T_2 * V_4 )
{
if( V_4 == NULL )
return;
F_26 ( & ( V_4 -> V_37 ) ) ;
F_26 ( & ( V_4 -> V_23 ) ) ;
F_26 ( & ( V_4 -> V_34 ) ) ;
if ( V_4 -> V_35 & V_36 )
F_27 ( V_4 ) ;
}
int F_28 ( T_2 * V_4 , const T_1 * V_38 , T_3 * V_5 )
{
T_1 V_39 , * V_40 ;
F_24 ( & V_39 ) ;
V_40 = & ( V_4 -> V_37 ) ;
F_10 ( & ( V_4 -> V_23 ) , V_38 ) ;
V_4 -> V_23 . V_27 = 0 ;
#ifdef F_9
{
T_1 V_41 ;
T_4 V_42 [ 2 ] ;
V_4 -> V_22 = ( F_29 ( V_38 ) + ( V_25 - 1 ) ) / V_25 * V_25 ;
if ( ! ( F_30 ( V_40 ) ) ) goto V_8;
if ( ! ( F_31 ( V_40 , V_25 ) ) ) goto V_8;
V_42 [ 0 ] = V_38 -> V_24 [ 0 ] ;
V_42 [ 1 ] = 0 ;
V_41 . V_24 = V_42 ;
V_41 . V_26 = 1 ;
V_41 . V_43 = 2 ;
V_41 . V_27 = 0 ;
if ( ( F_32 ( & V_39 , V_40 , & V_41 , V_5 ) ) == NULL )
goto V_8;
if ( ! F_33 ( & V_39 , & V_39 , V_25 ) ) goto V_8;
if ( ! F_34 ( & V_39 ) )
{
if ( ! F_35 ( & V_39 , 1 ) ) goto V_8;
}
else
{
if ( ! F_36 ( & V_39 , V_32 ) ) goto V_8;
}
if ( ! F_37 ( & V_39 , NULL , & V_39 , & V_41 , V_5 ) ) goto V_8;
V_4 -> V_14 = ( V_39 . V_26 > 0 ) ? V_39 . V_24 [ 0 ] : 0 ;
F_26 ( & V_39 ) ;
}
#else
{
V_4 -> V_22 = F_29 ( & V_4 -> V_23 ) ;
if ( ! F_30 ( V_40 ) ) goto V_8;
if ( ! F_31 ( V_40 , V_4 -> V_22 ) ) goto V_8;
if ( ( F_32 ( & V_39 , V_40 , & V_4 -> V_23 , V_5 ) ) == NULL )
goto V_8;
if ( ! F_33 ( & V_39 , & V_39 , V_4 -> V_22 ) ) goto V_8;
if ( ! F_35 ( & V_39 , 1 ) ) goto V_8;
if ( ! F_37 ( & ( V_4 -> V_34 ) , NULL , & V_39 , & V_4 -> V_23 , V_5 ) ) goto V_8;
F_26 ( & V_39 ) ;
}
#endif
if ( ! F_30 ( & ( V_4 -> V_37 ) ) ) goto V_8;
if ( ! F_31 ( & ( V_4 -> V_37 ) , V_4 -> V_22 * 2 ) ) goto V_8;
if ( ! F_38 ( & ( V_4 -> V_37 ) , & ( V_4 -> V_37 ) , & ( V_4 -> V_23 ) , V_5 ) ) goto V_8;
return ( 1 ) ;
V_8:
return ( 0 ) ;
}
T_2 * F_39 ( T_2 * V_44 , T_2 * V_45 )
{
if ( V_44 == V_45 ) return ( V_44 ) ;
if ( ! F_10 ( & ( V_44 -> V_37 ) , & ( V_45 -> V_37 ) ) ) return NULL ;
if ( ! F_10 ( & ( V_44 -> V_23 ) , & ( V_45 -> V_23 ) ) ) return NULL ;
if ( ! F_10 ( & ( V_44 -> V_34 ) , & ( V_45 -> V_34 ) ) ) return NULL ;
V_44 -> V_22 = V_45 -> V_22 ;
V_44 -> V_14 = V_45 -> V_14 ;
return ( V_44 ) ;
}
