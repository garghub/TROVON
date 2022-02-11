int F_1 ( T_1 * V_1 , T_1 * V_2 , const T_1 * V_3 , const T_1 * V_4 ,
T_2 * V_5 )
{
int V_6 , V_7 , V_8 , V_9 ;
T_1 * V_10 , V_11 , * V_12 , * V_13 , * V_14 ;
T_3 * V_15 , * V_16 ;
T_3 V_17 , V_18 ;
int V_19 , V_20 ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
if ( F_3 ( V_4 ) )
{
F_4 ( V_21 , V_22 ) ;
return ( 0 ) ;
}
if ( F_5 ( V_3 , V_4 ) < 0 )
{
if ( V_2 != NULL )
{ if ( F_6 ( V_2 , V_3 ) == NULL ) return ( 0 ) ; }
if ( V_1 != NULL ) F_7 ( V_1 ) ;
return ( 1 ) ;
}
F_8 ( V_5 ) ;
V_10 = F_9 ( V_5 ) ;
V_10 -> V_23 = 0 ;
V_12 = F_9 ( V_5 ) ;
V_13 = F_9 ( V_5 ) ;
if ( V_1 == NULL )
V_14 = F_9 ( V_5 ) ;
else V_14 = V_1 ;
if ( V_14 == NULL ) goto V_24;
V_6 = V_25 - ( ( F_10 ( V_4 ) ) % V_25 ) ;
F_11 ( V_13 , V_4 , V_6 ) ;
V_13 -> V_23 = 0 ;
V_6 += V_25 ;
F_11 ( V_12 , V_3 , V_6 ) ;
V_12 -> V_23 = 0 ;
V_20 = V_13 -> V_26 ;
V_19 = V_12 -> V_26 ;
V_9 = V_19 - V_20 ;
F_12 ( & V_11 ) ;
V_11 . V_27 = & ( V_12 -> V_27 [ V_9 ] ) ;
V_11 . V_26 = V_20 ;
V_11 . V_28 = V_12 -> V_28 + 1 ;
V_17 = V_13 -> V_27 [ V_20 - 1 ] ;
V_18 = ( V_20 == 1 ) ? 0 : V_13 -> V_27 [ V_20 - 2 ] ;
V_16 = & ( V_12 -> V_27 [ V_19 - 1 ] ) ;
V_14 -> V_23 = ( V_3 -> V_23 ^ V_4 -> V_23 ) ;
if ( ! F_13 ( V_14 , ( V_9 + 1 ) ) ) goto V_24;
V_14 -> V_26 = V_9 ;
V_15 = & ( V_14 -> V_27 [ V_9 - 1 ] ) ;
if ( ! F_13 ( V_10 , ( V_20 + 1 ) ) ) goto V_24;
if ( F_5 ( & V_11 , V_13 ) >= 0 )
{
if ( ! F_14 ( & V_11 , & V_11 , V_13 ) ) goto V_24;
* V_15 = 1 ;
V_14 -> V_27 [ V_14 -> V_26 - 1 ] = 1 ;
}
else
V_14 -> V_26 -- ;
V_15 -- ;
for ( V_7 = 0 ; V_7 < V_9 - 1 ; V_7 ++ )
{
T_3 V_29 , V_30 ;
#ifdef F_15
V_29 = F_16 ( V_16 , V_18 , V_17 ) ;
#else
T_3 V_31 , V_32 , V_33 = 0 ;
V_31 = V_16 [ 0 ] ;
V_32 = V_16 [ - 1 ] ;
if ( V_31 == V_17 )
V_29 = V_34 ;
else
{
#ifdef F_17
T_4 V_35 ;
#if F_18 ( F_17 ) && F_18 ( V_36 ) && ! F_18 ( V_37 )
V_29 = ( T_3 ) ( ( ( ( ( T_4 ) V_31 ) << V_25 ) | V_32 ) / V_17 ) ;
#else
V_29 = V_37 ( V_31 , V_32 , V_17 ) ;
#endif
#ifndef F_19
V_33 = ( V_32 - V_29 * V_17 ) & V_34 ;
#endif
V_35 = ( T_4 ) V_18 * V_29 ;
for (; ; )
{
if ( V_35 <= ( ( ( ( T_4 ) V_33 ) << V_25 ) | V_16 [ - 2 ] ) )
break;
V_29 -- ;
V_33 += V_17 ;
if ( V_33 < V_17 ) break;
V_35 -= V_18 ;
}
#else
T_3 V_38 , V_39 , V_40 , V_41 ;
V_29 = V_37 ( V_31 , V_32 , V_17 ) ;
#ifndef F_19
V_33 = ( V_32 - V_29 * V_17 ) & V_34 ;
#endif
#ifdef F_20
V_38 = V_18 * V_29 ;
V_39 = F_20 ( V_18 , V_29 ) ;
#else
V_38 = F_21 ( V_18 ) ; V_39 = F_22 ( V_18 ) ;
V_40 = F_21 ( V_29 ) ; V_41 = F_22 ( V_29 ) ;
F_23 ( V_38 , V_39 , V_40 , V_41 ) ;
#endif
for (; ; )
{
if ( ( V_39 < V_33 ) ||
( ( V_39 == V_33 ) && ( V_38 <= V_16 [ - 2 ] ) ) )
break;
V_29 -- ;
V_33 += V_17 ;
if ( V_33 < V_17 ) break;
if ( V_38 < V_18 ) V_39 -- ; V_38 -= V_18 ;
}
#endif
}
#endif
V_30 = F_24 ( V_10 -> V_27 , V_13 -> V_27 , V_20 , V_29 ) ;
V_11 . V_27 -- ; V_11 . V_26 ++ ;
V_10 -> V_27 [ V_20 ] = V_30 ;
for ( V_8 = V_20 + 1 ; V_8 > 0 ; V_8 -- )
if ( V_10 -> V_27 [ V_8 - 1 ] ) break;
V_10 -> V_26 = V_8 ;
V_8 = V_11 . V_26 ;
F_25 ( & V_11 , & V_11 , V_10 ) ;
V_12 -> V_26 = V_12 -> V_26 + V_11 . V_26 - V_8 ;
if ( V_11 . V_23 )
{
V_29 -- ;
V_8 = V_11 . V_26 ;
F_26 ( & V_11 , & V_11 , V_13 ) ;
V_12 -> V_26 += V_11 . V_26 - V_8 ;
}
* ( V_15 -- ) = V_29 ;
V_16 -- ;
}
if ( V_2 != NULL )
{
F_27 ( V_2 , V_12 , V_6 ) ;
V_2 -> V_23 = V_3 -> V_23 ;
}
F_28 ( V_5 ) ;
return ( 1 ) ;
V_24:
F_28 ( V_5 ) ;
return ( 0 ) ;
}
int F_29 ( T_1 * V_33 , const T_1 * V_42 , const T_1 * V_27 , T_2 * V_5 )
{
#if 0
int i,nm,nd;
BIGNUM *dv;
if (BN_ucmp(m,d) < 0)
return((BN_copy(rem,m) == NULL)?0:1);
BN_CTX_start(ctx);
dv=BN_CTX_get(ctx);
if (!BN_copy(rem,m)) goto err;
nm=BN_num_bits(rem);
nd=BN_num_bits(d);
if (!BN_lshift(dv,d,nm-nd)) goto err;
for (i=nm-nd; i>=0; i--)
{
if (BN_cmp(rem,dv) >= 0)
{
if (!BN_sub(rem,rem,dv)) goto err;
}
if (!BN_rshift1(dv,dv)) goto err;
}
BN_CTX_end(ctx);
return(1);
err:
BN_CTX_end(ctx);
return(0);
#else
return ( F_1 ( NULL , V_33 , V_42 , V_27 , V_5 ) ) ;
#endif
}
