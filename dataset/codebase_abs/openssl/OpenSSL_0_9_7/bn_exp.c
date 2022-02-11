int F_1 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , T_2 * V_4 )
{
int V_5 , V_6 , V_7 = 0 ;
T_1 * V_8 , * V_9 ;
F_2 ( V_4 ) ;
if ( ( V_1 == V_2 ) || ( V_1 == V_3 ) )
V_9 = F_3 ( V_4 ) ;
else
V_9 = V_1 ;
if ( ( V_8 = F_3 ( V_4 ) ) == NULL ) goto V_10;
if ( F_4 ( V_8 , V_2 ) == NULL ) goto V_10;
V_6 = F_5 ( V_3 ) ;
if ( F_6 ( V_3 ) )
{ if ( F_4 ( V_9 , V_2 ) == NULL ) goto V_10; }
else { if ( ! F_7 ( V_9 ) ) goto V_10; }
for ( V_5 = 1 ; V_5 < V_6 ; V_5 ++ )
{
if ( ! F_8 ( V_8 , V_8 , V_4 ) ) goto V_10;
if ( F_9 ( V_3 , V_5 ) )
{
if ( ! F_10 ( V_9 , V_9 , V_8 , V_4 ) ) goto V_10;
}
}
V_7 = 1 ;
V_10:
if ( V_1 != V_9 ) F_4 ( V_1 , V_9 ) ;
F_11 ( V_4 ) ;
return ( V_7 ) ;
}
int F_12 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_11 ,
T_2 * V_4 )
{
int V_7 ;
F_13 ( V_2 ) ;
F_13 ( V_3 ) ;
F_13 ( V_11 ) ;
#define F_14
#define F_15
#define F_16
#ifdef F_14
if ( F_6 ( V_11 ) )
{
# ifdef F_15
if ( V_2 -> V_12 == 1 && ! V_2 -> V_13 )
{
T_3 V_14 = V_2 -> V_15 [ 0 ] ;
V_7 = F_17 ( V_1 , V_14 , V_3 , V_11 , V_4 , NULL ) ;
}
else
# endif
V_7 = F_18 ( V_1 , V_2 , V_3 , V_11 , V_4 , NULL ) ;
}
else
#endif
#ifdef F_16
{ V_7 = F_19 ( V_1 , V_2 , V_3 , V_11 , V_4 ) ; }
#else
{ V_7 = F_20 ( V_1 , V_2 , V_3 , V_11 , V_4 ) ; }
#endif
return ( V_7 ) ;
}
int F_19 ( T_1 * V_1 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_11 , T_2 * V_4 )
{
int V_5 , V_16 , V_6 , V_7 = 0 , V_17 , V_18 , V_19 , V_20 ;
int V_21 = 1 , V_22 = 0 ;
T_1 * V_23 ;
T_1 V_24 [ V_25 ] ;
T_4 V_26 ;
V_6 = F_5 ( V_3 ) ;
if ( V_6 == 0 )
{
V_7 = F_7 ( V_1 ) ;
return V_7 ;
}
F_2 ( V_4 ) ;
if ( ( V_23 = F_3 ( V_4 ) ) == NULL ) goto V_10;
F_21 ( & V_26 ) ;
if ( V_11 -> V_13 )
{
if ( ! F_4 ( V_23 , V_11 ) ) goto V_10;
V_23 -> V_13 = 0 ;
if ( F_22 ( & V_26 , V_23 , V_4 ) <= 0 ) goto V_10;
}
else
{
if ( F_22 ( & V_26 , V_11 , V_4 ) <= 0 ) goto V_10;
}
F_23 ( & ( V_24 [ 0 ] ) ) ;
V_22 = 1 ;
if ( ! F_24 ( & ( V_24 [ 0 ] ) , V_2 , V_11 , V_4 ) ) goto V_10;
if ( F_25 ( & ( V_24 [ 0 ] ) ) )
{
V_7 = F_26 ( V_1 ) ;
goto V_10;
}
V_19 = F_27 ( V_6 ) ;
if ( V_19 > 1 )
{
if ( ! F_28 ( V_23 , & ( V_24 [ 0 ] ) , & ( V_24 [ 0 ] ) , & V_26 , V_4 ) )
goto V_10;
V_16 = 1 << ( V_19 - 1 ) ;
for ( V_5 = 1 ; V_5 < V_16 ; V_5 ++ )
{
F_23 ( & V_24 [ V_5 ] ) ;
if ( ! F_28 ( & ( V_24 [ V_5 ] ) , & ( V_24 [ V_5 - 1 ] ) , V_23 , & V_26 , V_4 ) )
goto V_10;
}
V_22 = V_5 ;
}
V_21 = 1 ;
V_20 = 0 ;
V_17 = V_6 - 1 ;
V_18 = 0 ;
if ( ! F_7 ( V_1 ) ) goto V_10;
for (; ; )
{
if ( F_9 ( V_3 , V_17 ) == 0 )
{
if ( ! V_21 )
if ( ! F_28 ( V_1 , V_1 , V_1 , & V_26 , V_4 ) )
goto V_10;
if ( V_17 == 0 ) break;
V_17 -- ;
continue;
}
V_16 = V_17 ;
V_20 = 1 ;
V_18 = 0 ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ )
{
if ( V_17 - V_5 < 0 ) break;
if ( F_9 ( V_3 , V_17 - V_5 ) )
{
V_20 <<= ( V_5 - V_18 ) ;
V_20 |= 1 ;
V_18 = V_5 ;
}
}
V_16 = V_18 + 1 ;
if ( ! V_21 )
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ )
{
if ( ! F_28 ( V_1 , V_1 , V_1 , & V_26 , V_4 ) )
goto V_10;
}
if ( ! F_28 ( V_1 , V_1 , & ( V_24 [ V_20 >> 1 ] ) , & V_26 , V_4 ) )
goto V_10;
V_17 -= V_18 + 1 ;
V_20 = 0 ;
V_21 = 0 ;
if ( V_17 < 0 ) break;
}
V_7 = 1 ;
V_10:
F_11 ( V_4 ) ;
for ( V_5 = 0 ; V_5 < V_22 ; V_5 ++ )
F_29 ( & ( V_24 [ V_5 ] ) ) ;
F_30 ( & V_26 ) ;
return ( V_7 ) ;
}
int F_18 ( T_1 * V_9 , const T_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_11 , T_2 * V_4 , T_5 * V_27 )
{
int V_5 , V_16 , V_6 , V_7 = 0 , V_17 , V_18 , V_19 , V_20 ;
int V_21 = 1 , V_22 = 0 ;
T_1 * V_15 , * V_1 ;
const T_1 * V_23 ;
T_1 V_24 [ V_25 ] ;
T_5 * V_28 = NULL ;
F_13 ( V_2 ) ;
F_13 ( V_3 ) ;
F_13 ( V_11 ) ;
if ( ! ( V_11 -> V_15 [ 0 ] & 1 ) )
{
F_31 ( V_29 , V_30 ) ;
return ( 0 ) ;
}
V_6 = F_5 ( V_3 ) ;
if ( V_6 == 0 )
{
V_7 = F_7 ( V_9 ) ;
return V_7 ;
}
F_2 ( V_4 ) ;
V_15 = F_3 ( V_4 ) ;
V_1 = F_3 ( V_4 ) ;
if ( V_15 == NULL || V_1 == NULL ) goto V_10;
if ( V_27 != NULL )
V_28 = V_27 ;
else
{
if ( ( V_28 = F_32 () ) == NULL ) goto V_10;
if ( ! F_33 ( V_28 , V_11 , V_4 ) ) goto V_10;
}
F_23 ( & V_24 [ 0 ] ) ;
V_22 = 1 ;
if ( V_2 -> V_13 || F_34 ( V_2 , V_11 ) >= 0 )
{
if ( ! F_24 ( & ( V_24 [ 0 ] ) , V_2 , V_11 , V_4 ) )
goto V_10;
V_23 = & ( V_24 [ 0 ] ) ;
}
else
V_23 = V_2 ;
if ( F_25 ( V_23 ) )
{
V_7 = F_26 ( V_9 ) ;
goto V_10;
}
if ( ! F_35 ( & ( V_24 [ 0 ] ) , V_23 , V_28 , V_4 ) ) goto V_10;
V_19 = F_27 ( V_6 ) ;
if ( V_19 > 1 )
{
if ( ! F_36 ( V_15 , & ( V_24 [ 0 ] ) , & ( V_24 [ 0 ] ) , V_28 , V_4 ) ) goto V_10;
V_16 = 1 << ( V_19 - 1 ) ;
for ( V_5 = 1 ; V_5 < V_16 ; V_5 ++ )
{
F_23 ( & ( V_24 [ V_5 ] ) ) ;
if ( ! F_36 ( & ( V_24 [ V_5 ] ) , & ( V_24 [ V_5 - 1 ] ) , V_15 , V_28 , V_4 ) )
goto V_10;
}
V_22 = V_5 ;
}
V_21 = 1 ;
V_20 = 0 ;
V_17 = V_6 - 1 ;
V_18 = 0 ;
if ( ! F_35 ( V_1 , F_37 () , V_28 , V_4 ) ) goto V_10;
for (; ; )
{
if ( F_9 ( V_3 , V_17 ) == 0 )
{
if ( ! V_21 )
{
if ( ! F_36 ( V_1 , V_1 , V_1 , V_28 , V_4 ) )
goto V_10;
}
if ( V_17 == 0 ) break;
V_17 -- ;
continue;
}
V_16 = V_17 ;
V_20 = 1 ;
V_18 = 0 ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ )
{
if ( V_17 - V_5 < 0 ) break;
if ( F_9 ( V_3 , V_17 - V_5 ) )
{
V_20 <<= ( V_5 - V_18 ) ;
V_20 |= 1 ;
V_18 = V_5 ;
}
}
V_16 = V_18 + 1 ;
if ( ! V_21 )
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ )
{
if ( ! F_36 ( V_1 , V_1 , V_1 , V_28 , V_4 ) )
goto V_10;
}
if ( ! F_36 ( V_1 , V_1 , & ( V_24 [ V_20 >> 1 ] ) , V_28 , V_4 ) )
goto V_10;
V_17 -= V_18 + 1 ;
V_20 = 0 ;
V_21 = 0 ;
if ( V_17 < 0 ) break;
}
if ( ! F_38 ( V_9 , V_1 , V_28 , V_4 ) ) goto V_10;
V_7 = 1 ;
V_10:
if ( ( V_27 == NULL ) && ( V_28 != NULL ) ) F_39 ( V_28 ) ;
F_11 ( V_4 ) ;
for ( V_5 = 0 ; V_5 < V_22 ; V_5 ++ )
F_29 ( & ( V_24 [ V_5 ] ) ) ;
return ( V_7 ) ;
}
int F_17 ( T_1 * V_9 , T_3 V_2 , const T_1 * V_3 ,
const T_1 * V_11 , T_2 * V_4 , T_5 * V_27 )
{
T_5 * V_28 = NULL ;
int V_31 , V_6 , V_7 = 0 ;
int V_32 ;
T_3 V_33 , V_34 ;
T_1 * V_15 , * V_1 , * V_35 ;
T_1 * V_36 ;
#define F_40 ( V_1 , V_33 , V_11 ) \
(BN_mul_word(r, (w)) && \
( \
(BN_mod(t, r, m, ctx) && (swap_tmp = r, r = t, t = swap_tmp, 1))))
#define F_41 ( V_1 , V_33 , V_28 ) \
(BN_set_word(r, (w)) && BN_to_montgomery(r, r, (mont), ctx))
F_13 ( V_3 ) ;
F_13 ( V_11 ) ;
if ( V_11 -> V_12 == 0 || ! ( V_11 -> V_15 [ 0 ] & 1 ) )
{
F_31 ( V_37 , V_30 ) ;
return ( 0 ) ;
}
if ( V_11 -> V_12 == 1 )
V_2 %= V_11 -> V_15 [ 0 ] ;
V_6 = F_5 ( V_3 ) ;
if ( V_6 == 0 )
{
V_7 = F_7 ( V_9 ) ;
return V_7 ;
}
if ( V_2 == 0 )
{
V_7 = F_26 ( V_9 ) ;
return V_7 ;
}
F_2 ( V_4 ) ;
V_15 = F_3 ( V_4 ) ;
V_1 = F_3 ( V_4 ) ;
V_35 = F_3 ( V_4 ) ;
if ( V_15 == NULL || V_1 == NULL || V_35 == NULL ) goto V_10;
if ( V_27 != NULL )
V_28 = V_27 ;
else
{
if ( ( V_28 = F_32 () ) == NULL ) goto V_10;
if ( ! F_33 ( V_28 , V_11 , V_4 ) ) goto V_10;
}
V_32 = 1 ;
V_33 = V_2 ;
for ( V_31 = V_6 - 2 ; V_31 >= 0 ; V_31 -- )
{
V_34 = V_33 * V_33 ;
if ( ( V_34 / V_33 ) != V_33 )
{
if ( V_32 )
{
if ( ! F_41 ( V_1 , V_33 , V_28 ) ) goto V_10;
V_32 = 0 ;
}
else
{
if ( ! F_40 ( V_1 , V_33 , V_11 ) ) goto V_10;
}
V_34 = 1 ;
}
V_33 = V_34 ;
if ( ! V_32 )
{
if ( ! F_36 ( V_1 , V_1 , V_1 , V_28 , V_4 ) ) goto V_10;
}
if ( F_9 ( V_3 , V_31 ) )
{
V_34 = V_33 * V_2 ;
if ( ( V_34 / V_2 ) != V_33 )
{
if ( V_32 )
{
if ( ! F_41 ( V_1 , V_33 , V_28 ) ) goto V_10;
V_32 = 0 ;
}
else
{
if ( ! F_40 ( V_1 , V_33 , V_11 ) ) goto V_10;
}
V_34 = V_2 ;
}
V_33 = V_34 ;
}
}
if ( V_33 != 1 )
{
if ( V_32 )
{
if ( ! F_41 ( V_1 , V_33 , V_28 ) ) goto V_10;
V_32 = 0 ;
}
else
{
if ( ! F_40 ( V_1 , V_33 , V_11 ) ) goto V_10;
}
}
if ( V_32 )
{
if ( ! F_7 ( V_9 ) ) goto V_10;
}
else
{
if ( ! F_38 ( V_9 , V_1 , V_28 , V_4 ) ) goto V_10;
}
V_7 = 1 ;
V_10:
if ( ( V_27 == NULL ) && ( V_28 != NULL ) ) F_39 ( V_28 ) ;
F_11 ( V_4 ) ;
return ( V_7 ) ;
}
int F_20 ( T_1 * V_1 ,
const T_1 * V_2 , const T_1 * V_3 , const T_1 * V_11 ,
T_2 * V_4 )
{
int V_5 , V_16 , V_6 , V_7 = 0 , V_17 , V_18 , V_19 , V_20 , V_22 = 0 ;
int V_21 = 1 ;
T_1 * V_15 ;
T_1 V_24 [ V_25 ] ;
V_6 = F_5 ( V_3 ) ;
if ( V_6 == 0 )
{
V_7 = F_7 ( V_1 ) ;
return V_7 ;
}
F_2 ( V_4 ) ;
if ( ( V_15 = F_3 ( V_4 ) ) == NULL ) goto V_10;
F_23 ( & ( V_24 [ 0 ] ) ) ;
V_22 = 1 ;
if ( ! F_24 ( & ( V_24 [ 0 ] ) , V_2 , V_11 , V_4 ) ) goto V_10;
if ( F_25 ( & ( V_24 [ 0 ] ) ) )
{
V_7 = F_26 ( V_1 ) ;
goto V_10;
}
V_19 = F_27 ( V_6 ) ;
if ( V_19 > 1 )
{
if ( ! F_42 ( V_15 , & ( V_24 [ 0 ] ) , & ( V_24 [ 0 ] ) , V_11 , V_4 ) )
goto V_10;
V_16 = 1 << ( V_19 - 1 ) ;
for ( V_5 = 1 ; V_5 < V_16 ; V_5 ++ )
{
F_23 ( & ( V_24 [ V_5 ] ) ) ;
if ( ! F_42 ( & ( V_24 [ V_5 ] ) , & ( V_24 [ V_5 - 1 ] ) , V_15 , V_11 , V_4 ) )
goto V_10;
}
V_22 = V_5 ;
}
V_21 = 1 ;
V_20 = 0 ;
V_17 = V_6 - 1 ;
V_18 = 0 ;
if ( ! F_7 ( V_1 ) ) goto V_10;
for (; ; )
{
if ( F_9 ( V_3 , V_17 ) == 0 )
{
if ( ! V_21 )
if ( ! F_42 ( V_1 , V_1 , V_1 , V_11 , V_4 ) )
goto V_10;
if ( V_17 == 0 ) break;
V_17 -- ;
continue;
}
V_16 = V_17 ;
V_20 = 1 ;
V_18 = 0 ;
for ( V_5 = 1 ; V_5 < V_19 ; V_5 ++ )
{
if ( V_17 - V_5 < 0 ) break;
if ( F_9 ( V_3 , V_17 - V_5 ) )
{
V_20 <<= ( V_5 - V_18 ) ;
V_20 |= 1 ;
V_18 = V_5 ;
}
}
V_16 = V_18 + 1 ;
if ( ! V_21 )
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ )
{
if ( ! F_42 ( V_1 , V_1 , V_1 , V_11 , V_4 ) )
goto V_10;
}
if ( ! F_42 ( V_1 , V_1 , & ( V_24 [ V_20 >> 1 ] ) , V_11 , V_4 ) )
goto V_10;
V_17 -= V_18 + 1 ;
V_20 = 0 ;
V_21 = 0 ;
if ( V_17 < 0 ) break;
}
V_7 = 1 ;
V_10:
F_11 ( V_4 ) ;
for ( V_5 = 0 ; V_5 < V_22 ; V_5 ++ )
F_29 ( & ( V_24 [ V_5 ] ) ) ;
return ( V_7 ) ;
}
