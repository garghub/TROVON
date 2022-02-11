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
V_10 = & ( V_5 -> V_23 [ V_5 -> V_24 ] ) ;
V_10 -> V_25 = 0 ;
V_12 = & ( V_5 -> V_23 [ V_5 -> V_24 + 1 ] ) ;
V_13 = & ( V_5 -> V_23 [ V_5 -> V_24 + 2 ] ) ;
if ( V_1 == NULL )
V_14 = & ( V_5 -> V_23 [ V_5 -> V_24 + 3 ] ) ;
else V_14 = V_1 ;
V_6 = V_26 - ( ( F_8 ( V_4 ) ) % V_26 ) ;
F_9 ( V_13 , V_4 , V_6 ) ;
V_13 -> V_25 = 0 ;
V_6 += V_26 ;
F_9 ( V_12 , V_3 , V_6 ) ;
V_12 -> V_25 = 0 ;
V_20 = V_13 -> V_27 ;
V_19 = V_12 -> V_27 ;
V_9 = V_19 - V_20 ;
F_10 ( & V_11 ) ;
V_11 . V_28 = & ( V_12 -> V_28 [ V_9 ] ) ;
V_11 . V_27 = V_20 ;
V_11 . V_29 = V_12 -> V_29 + 1 ;
V_17 = V_13 -> V_28 [ V_20 - 1 ] ;
V_18 = ( V_20 == 1 ) ? 0 : V_13 -> V_28 [ V_20 - 2 ] ;
V_16 = & ( V_12 -> V_28 [ V_19 - 1 ] ) ;
V_14 -> V_25 = ( V_3 -> V_25 ^ V_4 -> V_25 ) ;
if ( ! F_11 ( V_14 , ( V_9 + 1 ) ) ) goto V_30;
V_14 -> V_27 = V_9 ;
V_15 = & ( V_14 -> V_28 [ V_9 - 1 ] ) ;
if ( ! F_11 ( V_10 , ( V_20 + 1 ) ) ) goto V_30;
if ( F_5 ( & V_11 , V_13 ) >= 0 )
{
if ( ! F_12 ( & V_11 , & V_11 , V_13 ) ) goto V_30;
* V_15 = 1 ;
V_14 -> V_28 [ V_14 -> V_27 - 1 ] = 1 ;
}
else
V_14 -> V_27 -- ;
V_15 -- ;
for ( V_7 = 0 ; V_7 < V_9 - 1 ; V_7 ++ )
{
T_3 V_31 , V_32 ;
#ifdef F_13
V_31 = F_14 ( V_16 , V_17 , V_18 ) ;
#else
#if ! F_15 ( V_33 ) && ! F_15 ( V_34 )
# if F_15 ( V_35 ) && V_35 >= 2
# if F_15 ( V_36 )
# define F_16 ( T_4 , T_5 , V_17 ) \
({ asm volatile ( \
"divl %4" \
: "=a"(q), "=d"(rem) \
: "a"(n1), "d"(n0), "g"(d0) \
: "cc"); \
q; \
})
# define F_17
# endif
# endif
#endif
T_3 T_4 , T_5 , V_37 = 0 ;
T_4 = V_16 [ 0 ] ;
T_5 = V_16 [ - 1 ] ;
if ( T_4 == V_17 )
V_31 = V_38 ;
else
#if F_15 ( V_39 ) && F_15 ( V_40 ) && ! F_15 ( F_16 )
V_31 = ( ( ( ( V_41 ) T_4 ) << V_26 ) | T_5 ) / V_17 ;
#else
V_31 = F_16 ( T_4 , T_5 , V_17 ) ;
#endif
{
#ifdef V_39
V_41 V_42 ;
#ifndef F_17
V_37 = ( T_5 - V_31 * V_17 ) & V_38 ;
#endif
V_42 = ( V_41 ) V_18 * V_31 ;
for (; ; )
{
if ( V_42 <= ( ( ( ( V_41 ) V_37 ) << V_26 ) | V_16 [ - 2 ] ) )
break;
V_31 -- ;
V_37 += V_17 ;
if ( V_37 < V_17 ) break;
V_42 -= V_18 ;
}
#else
T_3 V_43 , V_44 , V_45 , V_46 ;
#ifndef F_17
V_37 = ( T_5 - V_31 * V_17 ) & V_38 ;
#endif
V_43 = F_18 ( V_18 ) ; V_44 = F_19 ( V_18 ) ;
V_45 = F_18 ( V_31 ) ; V_46 = F_19 ( V_31 ) ;
F_20 ( V_43 , V_44 , V_45 , V_46 ) ;
for (; ; )
{
if ( ( V_44 < V_37 ) ||
( ( V_44 == V_37 ) && ( V_43 <= V_16 [ - 2 ] ) ) )
break;
V_31 -- ;
V_37 += V_17 ;
if ( V_37 < V_17 ) break;
if ( V_43 < V_18 ) V_44 -- ; V_43 -= V_18 ;
}
#endif
}
#endif
V_11 . V_28 -- ; V_11 . V_27 ++ ;
V_32 = F_21 ( V_10 -> V_28 , V_13 -> V_28 , V_20 , V_31 ) ;
V_10 -> V_28 [ V_20 ] = V_32 ;
for ( V_8 = V_20 + 1 ; V_8 > 0 ; V_8 -- )
if ( V_10 -> V_28 [ V_8 - 1 ] ) break;
V_10 -> V_27 = V_8 ;
V_8 = V_11 . V_27 ;
F_22 ( & V_11 , & V_11 , V_10 ) ;
V_12 -> V_27 = V_12 -> V_27 + V_11 . V_27 - V_8 ;
if ( V_11 . V_25 )
{
V_31 -- ;
V_8 = V_11 . V_27 ;
F_23 ( & V_11 , & V_11 , V_13 ) ;
V_12 -> V_27 += V_11 . V_27 - V_8 ;
}
* ( V_15 -- ) = V_31 ;
V_16 -- ;
}
if ( V_2 != NULL )
{
F_24 ( V_2 , V_12 , V_6 ) ;
V_2 -> V_25 = V_3 -> V_25 ;
}
return ( 1 ) ;
V_30:
return ( 0 ) ;
}
int F_25 ( T_1 * V_37 , const T_1 * V_47 , const T_1 * V_28 , T_2 * V_5 )
{
#if 0
int i,nm,nd;
BIGNUM *dv;
if (BN_ucmp(m,d) < 0)
return((BN_copy(rem,m) == NULL)?0:1);
dv= &(ctx->bn[ctx->tos]);
if (!BN_copy(rem,m)) return(0);
nm=BN_num_bits(rem);
nd=BN_num_bits(d);
if (!BN_lshift(dv,d,nm-nd)) return(0);
for (i=nm-nd; i>=0; i--)
{
if (BN_cmp(rem,dv) >= 0)
{
if (!BN_sub(rem,rem,dv)) return(0);
}
if (!BN_rshift1(dv,dv)) return(0);
}
return(1);
#else
return ( F_1 ( NULL , V_37 , V_47 , V_28 , V_5 ) ) ;
#endif
}
