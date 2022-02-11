int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
int V_5 , V_6 , V_7 = 0 ;
T_1 * V_8 , * V_9 ;
if ( F_2 ( V_3 , V_10 ) != 0 )
{
F_3 ( V_11 , V_12 ) ;
return - 1 ;
}
F_4 ( V_4 ) ;
if ( ( V_1 == V_2 ) || ( V_1 == V_3 ) )
V_9 = F_5 ( V_4 ) ;
else
V_9 = V_1 ;
if ( ( V_8 = F_5 ( V_4 ) ) == NULL ) goto V_13;
if ( F_6 ( V_8 , V_2 ) == NULL ) goto V_13;
V_6 = F_7 ( V_3 ) ;
if ( F_8 ( V_3 ) )
{ if ( F_6 ( V_9 , V_2 ) == NULL ) goto V_13; }
else { if ( ! F_9 ( V_9 ) ) goto V_13; }
for ( V_5 = 1 ; V_5 < V_6 ; V_5 ++ )
{
if ( ! F_10 ( V_8 , V_8 , V_4 ) ) goto V_13;
if ( F_11 ( V_3 , V_5 ) )
{
if ( ! F_12 ( V_9 , V_9 , V_8 , V_4 ) ) goto V_13;
}
}
V_7 = 1 ;
V_13:
if ( V_1 != V_9 ) F_6 ( V_1 , V_9 ) ;
F_13 ( V_4 ) ;
F_14 ( V_1 ) ;
return ( V_7 ) ;
}
int F_15 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_14 ,
T_2 * V_4 )
{
int V_7 ;
F_14 ( V_2 ) ;
F_14 ( V_3 ) ;
F_14 ( V_14 ) ;
#define F_16
#define F_17
#define F_18
#ifdef F_16
if ( F_8 ( V_14 ) )
{
# ifdef F_17
if ( V_2 -> V_15 == 1 && ! V_2 -> V_16 && ( F_2 ( V_3 , V_10 ) == 0 ) )
{
T_3 V_17 = V_2 -> V_18 [ 0 ] ;
V_7 = F_19 ( V_1 , V_17 , V_3 , V_14 , V_4 , NULL ) ;
}
else
# endif
V_7 = F_20 ( V_1 , V_2 , V_3 , V_14 , V_4 , NULL ) ;
}
else
#endif
#ifdef F_18
{ V_7 = F_21 ( V_1 , V_2 , V_3 , V_14 , V_4 ) ; }
#else
{ V_7 = F_22 ( V_1 , V_2 , V_3 , V_14 , V_4 ) ; }
#endif
F_14 ( V_1 ) ;
return ( V_7 ) ;
}
int F_21 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 )
{
int V_5 , V_19 , V_6 , V_7 = 0 , V_20 , V_21 , V_22 , V_23 ;
int V_24 = 1 ;
T_1 * V_25 ;
T_1 * V_26 [ V_27 ] ;
T_4 V_28 ;
if ( F_2 ( V_3 , V_10 ) != 0 )
{
F_3 ( V_29 , V_12 ) ;
return - 1 ;
}
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 )
{
V_7 = F_9 ( V_1 ) ;
return V_7 ;
}
F_4 ( V_4 ) ;
V_25 = F_5 ( V_4 ) ;
V_26 [ 0 ] = F_5 ( V_4 ) ;
if( ! V_25 || ! V_26 [ 0 ] ) goto V_13;
F_23 ( & V_28 ) ;
if ( V_14 -> V_16 )
{
if ( ! F_6 ( V_25 , V_14 ) ) goto V_13;
V_25 -> V_16 = 0 ;
if ( F_24 ( & V_28 , V_25 , V_4 ) <= 0 ) goto V_13;
}
else
{
if ( F_24 ( & V_28 , V_14 , V_4 ) <= 0 ) goto V_13;
}
if ( ! F_25 ( V_26 [ 0 ] , V_2 , V_14 , V_4 ) ) goto V_13;
if ( F_26 ( V_26 [ 0 ] ) )
{
F_27 ( V_1 ) ;
V_7 = 1 ;
goto V_13;
}
V_22 = F_28 ( V_6 ) ;
if ( V_22 > 1 )
{
if ( ! F_29 ( V_25 , V_26 [ 0 ] , V_26 [ 0 ] , & V_28 , V_4 ) )
goto V_13;
V_19 = 1 << ( V_22 - 1 ) ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ )
{
if( ( ( V_26 [ V_5 ] = F_5 ( V_4 ) ) == NULL ) ||
! F_29 ( V_26 [ V_5 ] , V_26 [ V_5 - 1 ] ,
V_25 , & V_28 , V_4 ) )
goto V_13;
}
}
V_24 = 1 ;
V_23 = 0 ;
V_20 = V_6 - 1 ;
V_21 = 0 ;
if ( ! F_9 ( V_1 ) ) goto V_13;
for (; ; )
{
if ( F_11 ( V_3 , V_20 ) == 0 )
{
if ( ! V_24 )
if ( ! F_29 ( V_1 , V_1 , V_1 , & V_28 , V_4 ) )
goto V_13;
if ( V_20 == 0 ) break;
V_20 -- ;
continue;
}
V_19 = V_20 ;
V_23 = 1 ;
V_21 = 0 ;
for ( V_5 = 1 ; V_5 < V_22 ; V_5 ++ )
{
if ( V_20 - V_5 < 0 ) break;
if ( F_11 ( V_3 , V_20 - V_5 ) )
{
V_23 <<= ( V_5 - V_21 ) ;
V_23 |= 1 ;
V_21 = V_5 ;
}
}
V_19 = V_21 + 1 ;
if ( ! V_24 )
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ )
{
if ( ! F_29 ( V_1 , V_1 , V_1 , & V_28 , V_4 ) )
goto V_13;
}
if ( ! F_29 ( V_1 , V_1 , V_26 [ V_23 >> 1 ] , & V_28 , V_4 ) )
goto V_13;
V_20 -= V_21 + 1 ;
V_23 = 0 ;
V_24 = 0 ;
if ( V_20 < 0 ) break;
}
V_7 = 1 ;
V_13:
F_13 ( V_4 ) ;
F_30 ( & V_28 ) ;
F_14 ( V_1 ) ;
return ( V_7 ) ;
}
int F_20 ( T_1 * V_9 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 , T_5 * V_30 )
{
int V_5 , V_19 , V_6 , V_7 = 0 , V_20 , V_21 , V_22 , V_23 ;
int V_24 = 1 ;
T_1 * V_18 , * V_1 ;
const T_1 * V_25 ;
T_1 * V_26 [ V_27 ] ;
T_5 * V_31 = NULL ;
if ( F_2 ( V_3 , V_10 ) != 0 )
{
return F_31 ( V_9 , V_2 , V_3 , V_14 , V_4 , V_30 ) ;
}
F_14 ( V_2 ) ;
F_14 ( V_3 ) ;
F_14 ( V_14 ) ;
if ( ! F_8 ( V_14 ) )
{
F_3 ( V_32 , V_33 ) ;
return ( 0 ) ;
}
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 )
{
V_7 = F_9 ( V_9 ) ;
return V_7 ;
}
F_4 ( V_4 ) ;
V_18 = F_5 ( V_4 ) ;
V_1 = F_5 ( V_4 ) ;
V_26 [ 0 ] = F_5 ( V_4 ) ;
if ( ! V_18 || ! V_1 || ! V_26 [ 0 ] ) goto V_13;
if ( V_30 != NULL )
V_31 = V_30 ;
else
{
if ( ( V_31 = F_32 () ) == NULL ) goto V_13;
if ( ! F_33 ( V_31 , V_14 , V_4 ) ) goto V_13;
}
if ( V_2 -> V_16 || F_34 ( V_2 , V_14 ) >= 0 )
{
if ( ! F_25 ( V_26 [ 0 ] , V_2 , V_14 , V_4 ) )
goto V_13;
V_25 = V_26 [ 0 ] ;
}
else
V_25 = V_2 ;
if ( F_26 ( V_25 ) )
{
F_27 ( V_9 ) ;
V_7 = 1 ;
goto V_13;
}
if ( ! F_35 ( V_26 [ 0 ] , V_25 , V_31 , V_4 ) ) goto V_13;
V_22 = F_28 ( V_6 ) ;
if ( V_22 > 1 )
{
if ( ! F_36 ( V_18 , V_26 [ 0 ] , V_26 [ 0 ] , V_31 , V_4 ) ) goto V_13;
V_19 = 1 << ( V_22 - 1 ) ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ )
{
if( ( ( V_26 [ V_5 ] = F_5 ( V_4 ) ) == NULL ) ||
! F_36 ( V_26 [ V_5 ] , V_26 [ V_5 - 1 ] ,
V_18 , V_31 , V_4 ) )
goto V_13;
}
}
V_24 = 1 ;
V_23 = 0 ;
V_20 = V_6 - 1 ;
V_21 = 0 ;
if ( ! F_35 ( V_1 , F_37 () , V_31 , V_4 ) ) goto V_13;
for (; ; )
{
if ( F_11 ( V_3 , V_20 ) == 0 )
{
if ( ! V_24 )
{
if ( ! F_36 ( V_1 , V_1 , V_1 , V_31 , V_4 ) )
goto V_13;
}
if ( V_20 == 0 ) break;
V_20 -- ;
continue;
}
V_19 = V_20 ;
V_23 = 1 ;
V_21 = 0 ;
for ( V_5 = 1 ; V_5 < V_22 ; V_5 ++ )
{
if ( V_20 - V_5 < 0 ) break;
if ( F_11 ( V_3 , V_20 - V_5 ) )
{
V_23 <<= ( V_5 - V_21 ) ;
V_23 |= 1 ;
V_21 = V_5 ;
}
}
V_19 = V_21 + 1 ;
if ( ! V_24 )
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ )
{
if ( ! F_36 ( V_1 , V_1 , V_1 , V_31 , V_4 ) )
goto V_13;
}
if ( ! F_36 ( V_1 , V_1 , V_26 [ V_23 >> 1 ] , V_31 , V_4 ) )
goto V_13;
V_20 -= V_21 + 1 ;
V_23 = 0 ;
V_24 = 0 ;
if ( V_20 < 0 ) break;
}
if ( ! F_38 ( V_9 , V_1 , V_31 , V_4 ) ) goto V_13;
V_7 = 1 ;
V_13:
if ( ( V_30 == NULL ) && ( V_31 != NULL ) ) F_39 ( V_31 ) ;
F_13 ( V_4 ) ;
F_14 ( V_9 ) ;
return ( V_7 ) ;
}
static int F_40 ( T_1 * V_34 , int V_15 , unsigned char * V_35 , int V_36 , int V_37 )
{
T_6 V_5 , V_19 ;
if ( F_41 ( V_34 , V_15 ) == NULL )
return 0 ;
while ( V_34 -> V_15 < V_15 )
{
V_34 -> V_18 [ V_34 -> V_15 ++ ] = 0 ;
}
for ( V_5 = 0 , V_19 = V_36 ; V_5 < V_15 * sizeof V_34 -> V_18 [ 0 ] ; V_5 ++ , V_19 += V_37 )
{
V_35 [ V_19 ] = ( ( unsigned char * ) V_34 -> V_18 ) [ V_5 ] ;
}
F_42 ( V_34 ) ;
return 1 ;
}
static int F_43 ( T_1 * V_34 , int V_15 , unsigned char * V_35 , int V_36 , int V_37 )
{
T_6 V_5 , V_19 ;
if ( F_41 ( V_34 , V_15 ) == NULL )
return 0 ;
for ( V_5 = 0 , V_19 = V_36 ; V_5 < V_15 * sizeof V_34 -> V_18 [ 0 ] ; V_5 ++ , V_19 += V_37 )
{
( ( unsigned char * ) V_34 -> V_18 ) [ V_5 ] = V_35 [ V_19 ] ;
}
V_34 -> V_15 = V_15 ;
F_42 ( V_34 ) ;
return 1 ;
}
int F_31 ( T_1 * V_9 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 , T_5 * V_30 )
{
int V_5 , V_6 , V_7 = 0 , V_36 , V_22 , V_23 ;
int V_15 ;
T_1 * V_1 ;
const T_1 * V_25 ;
T_5 * V_31 = NULL ;
int V_38 ;
unsigned char * V_39 = NULL ;
int V_40 = 0 ;
unsigned char * V_41 = NULL ;
T_1 * V_42 = NULL , * V_43 = NULL ;
F_14 ( V_2 ) ;
F_14 ( V_3 ) ;
F_14 ( V_14 ) ;
V_15 = V_14 -> V_15 ;
if ( ! ( V_14 -> V_18 [ 0 ] & 1 ) )
{
F_3 ( V_44 , V_33 ) ;
return ( 0 ) ;
}
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 )
{
V_7 = F_9 ( V_9 ) ;
return V_7 ;
}
F_4 ( V_4 ) ;
V_1 = F_5 ( V_4 ) ;
if ( V_1 == NULL ) goto V_13;
if ( V_30 != NULL )
V_31 = V_30 ;
else
{
if ( ( V_31 = F_32 () ) == NULL ) goto V_13;
if ( ! F_33 ( V_31 , V_14 , V_4 ) ) goto V_13;
}
V_22 = F_44 ( V_6 ) ;
V_38 = 1 << V_22 ;
V_40 = sizeof( V_14 -> V_18 [ 0 ] ) * V_15 * V_38 ;
if ( ( V_39 = ( unsigned char * ) F_45 ( V_40 + V_45 ) ) == NULL )
goto V_13;
V_41 = F_46 ( V_39 ) ;
memset ( V_41 , 0 , V_40 ) ;
if ( ! F_35 ( V_1 , F_37 () , V_31 , V_4 ) ) goto V_13;
if ( ! F_40 ( V_1 , V_15 , V_41 , 0 , V_38 ) ) goto V_13;
V_42 = F_5 ( V_4 ) ;
V_43 = F_5 ( V_4 ) ;
if ( V_42 == NULL || V_43 == NULL ) goto V_13;
if ( V_2 -> V_16 || F_34 ( V_2 , V_14 ) >= 0 )
{
if ( ! F_47 ( V_43 , V_2 , V_14 , V_4 ) )
goto V_13;
V_25 = V_43 ;
}
else
V_25 = V_2 ;
if ( ! F_35 ( V_43 , V_25 , V_31 , V_4 ) ) goto V_13;
if ( ! F_6 ( V_42 , V_43 ) ) goto V_13;
if ( ! F_40 ( V_43 , V_15 , V_41 , 1 , V_38 ) ) goto V_13;
if ( V_22 > 1 )
{
for ( V_5 = 2 ; V_5 < V_38 ; V_5 ++ )
{
if ( ! F_36 ( V_42 , V_43 , V_42 , V_31 , V_4 ) )
goto V_13;
if ( ! F_40 ( V_42 , V_15 , V_41 , V_5 , V_38 ) ) goto V_13;
}
}
V_6 = ( ( V_6 + V_22 - 1 ) / V_22 ) * V_22 ;
V_36 = V_6 - 1 ;
while ( V_36 >= 0 )
{
V_23 = 0 ;
for ( V_5 = 0 ; V_5 < V_22 ; V_5 ++ , V_36 -- )
{
if ( ! F_36 ( V_1 , V_1 , V_1 , V_31 , V_4 ) ) goto V_13;
V_23 = ( V_23 << 1 ) + F_11 ( V_3 , V_36 ) ;
}
if ( ! F_43 ( V_42 , V_15 , V_41 , V_23 , V_38 ) ) goto V_13;
if ( ! F_36 ( V_1 , V_1 , V_42 , V_31 , V_4 ) ) goto V_13;
}
if ( ! F_38 ( V_9 , V_1 , V_31 , V_4 ) ) goto V_13;
V_7 = 1 ;
V_13:
if ( ( V_30 == NULL ) && ( V_31 != NULL ) ) F_39 ( V_31 ) ;
if ( V_41 != NULL )
{
F_48 ( V_41 , V_40 ) ;
F_49 ( V_39 ) ;
}
if ( V_43 != NULL ) F_50 ( V_43 ) ;
if ( V_42 != NULL ) F_50 ( V_42 ) ;
F_13 ( V_4 ) ;
return ( V_7 ) ;
}
int F_19 ( T_1 * V_9 , T_3 V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 , T_5 * V_30 )
{
T_5 * V_31 = NULL ;
int V_34 , V_6 , V_7 = 0 ;
int V_46 ;
T_3 V_47 , V_48 ;
T_1 * V_18 , * V_1 , * V_49 ;
T_1 * V_50 ;
#define F_51 ( V_1 , V_47 , V_14 ) \
(BN_mul_word(r, (w)) && \
( \
(BN_mod(t, r, m, ctx) && (swap_tmp = r, r = t, t = swap_tmp, 1))))
#define F_52 ( V_1 , V_47 , V_31 ) \
(BN_set_word(r, (w)) && BN_to_montgomery(r, r, (mont), ctx))
if ( F_2 ( V_3 , V_10 ) != 0 )
{
F_3 ( V_51 , V_12 ) ;
return - 1 ;
}
F_14 ( V_3 ) ;
F_14 ( V_14 ) ;
if ( ! F_8 ( V_14 ) )
{
F_3 ( V_51 , V_33 ) ;
return ( 0 ) ;
}
if ( V_14 -> V_15 == 1 )
V_2 %= V_14 -> V_18 [ 0 ] ;
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 )
{
V_7 = F_9 ( V_9 ) ;
return V_7 ;
}
if ( V_2 == 0 )
{
F_27 ( V_9 ) ;
V_7 = 1 ;
return V_7 ;
}
F_4 ( V_4 ) ;
V_18 = F_5 ( V_4 ) ;
V_1 = F_5 ( V_4 ) ;
V_49 = F_5 ( V_4 ) ;
if ( V_18 == NULL || V_1 == NULL || V_49 == NULL ) goto V_13;
if ( V_30 != NULL )
V_31 = V_30 ;
else
{
if ( ( V_31 = F_32 () ) == NULL ) goto V_13;
if ( ! F_33 ( V_31 , V_14 , V_4 ) ) goto V_13;
}
V_46 = 1 ;
V_47 = V_2 ;
for ( V_34 = V_6 - 2 ; V_34 >= 0 ; V_34 -- )
{
V_48 = V_47 * V_47 ;
if ( ( V_48 / V_47 ) != V_47 )
{
if ( V_46 )
{
if ( ! F_52 ( V_1 , V_47 , V_31 ) ) goto V_13;
V_46 = 0 ;
}
else
{
if ( ! F_51 ( V_1 , V_47 , V_14 ) ) goto V_13;
}
V_48 = 1 ;
}
V_47 = V_48 ;
if ( ! V_46 )
{
if ( ! F_36 ( V_1 , V_1 , V_1 , V_31 , V_4 ) ) goto V_13;
}
if ( F_11 ( V_3 , V_34 ) )
{
V_48 = V_47 * V_2 ;
if ( ( V_48 / V_2 ) != V_47 )
{
if ( V_46 )
{
if ( ! F_52 ( V_1 , V_47 , V_31 ) ) goto V_13;
V_46 = 0 ;
}
else
{
if ( ! F_51 ( V_1 , V_47 , V_14 ) ) goto V_13;
}
V_48 = V_2 ;
}
V_47 = V_48 ;
}
}
if ( V_47 != 1 )
{
if ( V_46 )
{
if ( ! F_52 ( V_1 , V_47 , V_31 ) ) goto V_13;
V_46 = 0 ;
}
else
{
if ( ! F_51 ( V_1 , V_47 , V_14 ) ) goto V_13;
}
}
if ( V_46 )
{
if ( ! F_9 ( V_9 ) ) goto V_13;
}
else
{
if ( ! F_38 ( V_9 , V_1 , V_31 , V_4 ) ) goto V_13;
}
V_7 = 1 ;
V_13:
if ( ( V_30 == NULL ) && ( V_31 != NULL ) ) F_39 ( V_31 ) ;
F_13 ( V_4 ) ;
F_14 ( V_9 ) ;
return ( V_7 ) ;
}
int F_22 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_14 , T_2 * V_4 )
{
int V_5 , V_19 , V_6 , V_7 = 0 , V_20 , V_21 , V_22 , V_23 ;
int V_24 = 1 ;
T_1 * V_18 ;
T_1 * V_26 [ V_27 ] ;
if ( F_2 ( V_3 , V_10 ) != 0 )
{
F_3 ( V_52 , V_12 ) ;
return - 1 ;
}
V_6 = F_7 ( V_3 ) ;
if ( V_6 == 0 )
{
V_7 = F_9 ( V_1 ) ;
return V_7 ;
}
F_4 ( V_4 ) ;
V_18 = F_5 ( V_4 ) ;
V_26 [ 0 ] = F_5 ( V_4 ) ;
if( ! V_18 || ! V_26 [ 0 ] ) goto V_13;
if ( ! F_25 ( V_26 [ 0 ] , V_2 , V_14 , V_4 ) ) goto V_13;
if ( F_26 ( V_26 [ 0 ] ) )
{
F_27 ( V_1 ) ;
V_7 = 1 ;
goto V_13;
}
V_22 = F_28 ( V_6 ) ;
if ( V_22 > 1 )
{
if ( ! F_53 ( V_18 , V_26 [ 0 ] , V_26 [ 0 ] , V_14 , V_4 ) )
goto V_13;
V_19 = 1 << ( V_22 - 1 ) ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ )
{
if( ( ( V_26 [ V_5 ] = F_5 ( V_4 ) ) == NULL ) ||
! F_53 ( V_26 [ V_5 ] , V_26 [ V_5 - 1 ] , V_18 , V_14 , V_4 ) )
goto V_13;
}
}
V_24 = 1 ;
V_23 = 0 ;
V_20 = V_6 - 1 ;
V_21 = 0 ;
if ( ! F_9 ( V_1 ) ) goto V_13;
for (; ; )
{
if ( F_11 ( V_3 , V_20 ) == 0 )
{
if ( ! V_24 )
if ( ! F_53 ( V_1 , V_1 , V_1 , V_14 , V_4 ) )
goto V_13;
if ( V_20 == 0 ) break;
V_20 -- ;
continue;
}
V_19 = V_20 ;
V_23 = 1 ;
V_21 = 0 ;
for ( V_5 = 1 ; V_5 < V_22 ; V_5 ++ )
{
if ( V_20 - V_5 < 0 ) break;
if ( F_11 ( V_3 , V_20 - V_5 ) )
{
V_23 <<= ( V_5 - V_21 ) ;
V_23 |= 1 ;
V_21 = V_5 ;
}
}
V_19 = V_21 + 1 ;
if ( ! V_24 )
for ( V_5 = 0 ; V_5 < V_19 ; V_5 ++ )
{
if ( ! F_53 ( V_1 , V_1 , V_1 , V_14 , V_4 ) )
goto V_13;
}
if ( ! F_53 ( V_1 , V_1 , V_26 [ V_23 >> 1 ] , V_14 , V_4 ) )
goto V_13;
V_20 -= V_21 + 1 ;
V_23 = 0 ;
V_24 = 0 ;
if ( V_20 < 0 ) break;
}
V_7 = 1 ;
V_13:
F_13 ( V_4 ) ;
F_14 ( V_1 ) ;
return ( V_7 ) ;
}
