int F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 * V_3 , const T_1 * V_4 , T_2 * V_5 )
{
T_1 * V_6 ;
int V_7 = 0 ;
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
F_2 ( V_4 ) ;
F_3 ( V_5 ) ;
if ( ( V_6 = F_4 ( V_5 ) ) == NULL ) goto V_8;
if ( V_2 == V_3 )
{ if ( ! F_5 ( V_6 , V_2 , V_5 ) ) goto V_8; }
else
{ if ( ! F_6 ( V_6 , V_2 , V_3 , V_5 ) ) goto V_8; }
if ( ! F_7 ( V_1 , V_6 , V_4 , V_5 ) ) goto V_8;
V_7 = 1 ;
V_8:
F_8 ( V_5 ) ;
return ( V_7 ) ;
}
int F_9 ( T_1 * V_7 , T_1 * V_2 , T_1 * V_9 , T_2 * V_5 )
{
int V_10 , V_11 , V_1 = 0 ;
T_1 * V_12 , * V_13 ;
F_3 ( V_5 ) ;
if ( ( V_7 == V_2 ) || ( V_7 == V_9 ) )
V_13 = F_4 ( V_5 ) ;
else
V_13 = V_7 ;
if ( ( V_12 = F_4 ( V_5 ) ) == NULL ) goto V_8;
if ( F_10 ( V_12 , V_2 ) == NULL ) goto V_8;
V_11 = F_11 ( V_9 ) ;
if ( F_12 ( V_9 ) )
{ if ( F_10 ( V_13 , V_2 ) == NULL ) goto V_8; }
else { if ( ! F_13 ( V_13 ) ) goto V_8; }
for ( V_10 = 1 ; V_10 < V_11 ; V_10 ++ )
{
if ( ! F_5 ( V_12 , V_12 , V_5 ) ) goto V_8;
if ( F_14 ( V_9 , V_10 ) )
{
if ( ! F_6 ( V_13 , V_13 , V_12 , V_5 ) ) goto V_8;
}
}
V_1 = 1 ;
V_8:
if ( V_7 != V_13 ) F_10 ( V_7 , V_13 ) ;
F_8 ( V_5 ) ;
return ( V_1 ) ;
}
void F_15 ( void )
{
void * V_14 ;
int V_15 ;
unsigned int V_16 [ 1024 ] ;
static int V_17 ;
if( V_17 )
return;
V_17 = 1 ;
F_16 ( ( void * ) V_16 , 1024 ) ;
V_14 = F_17 ( L_1 , V_18 ) ;
if ( V_14 == ( void * ) NULL )
{
return;
}
V_19 =
( V_20 * ) F_18 ( V_14 , L_2 ) ;
if ( V_19 )
{
V_15 = (* V_19)( 0L , V_16 ) ;
if ( V_15 != 0 )
{
printf ( L_3 ) ;
printf ( L_4 ) ;
return;
}
}
else
{
return ;
}
V_21 =
( V_22 * ) F_18 ( V_14 , L_5 ) ;
if ( V_21 == NULL )
{
return;
}
V_23 =
( V_24 * ) F_18 ( V_14 , L_6 ) ;
if ( V_23 == NULL )
{
return;
}
V_25 = 1 ;
return;
}
int F_19 ( T_1 * V_7 , T_1 * V_2 , const T_1 * V_9 , const T_1 * V_4 )
{
unsigned char * V_26 ;
unsigned char * V_27 ;
unsigned char * V_28 ;
unsigned char * V_29 ;
int V_30 , V_31 , V_32 , V_1 ;
T_3 V_33 ;
F_15 () ;
if( ! V_25 )
return 0 ;
# define F_20 128
V_30 = F_21 ( V_2 ) ;
V_31 = F_21 ( V_9 ) ;
V_32 = F_21 ( V_4 ) ;
if( V_30 <= F_20 && V_31 <= F_20 && V_32 <= F_20 )
{
int V_34 = V_32 ;
assert ( V_30 <= V_32 ) ;
V_26 = F_22 ( V_34 ) ;
memset ( V_26 , '\0' , V_32 ) ;
F_23 ( V_2 , V_26 + V_34 - V_30 ) ;
V_27 = F_22 ( V_31 ) ;
F_23 ( V_9 , V_27 ) ;
V_28 = F_22 ( V_34 ) ;
memset ( V_28 , '\0' , V_32 ) ;
F_23 ( V_4 , V_28 + V_34 - V_32 ) ;
V_29 = F_22 ( V_34 ) ;
memset ( & V_33 , '\0' , sizeof V_33 ) ;
V_33 . V_35 . V_36 = V_27 ;
V_33 . V_35 . V_37 = V_31 ;
V_33 . V_38 . V_36 = V_28 ;
V_33 . V_38 . V_37 = V_34 ;
V_1 = (* V_21)( & V_33 , V_29 , V_26 , V_33 . V_38 . V_37 ) ;
if( ! V_1 )
{
F_24 ( V_29 , V_33 . V_38 . V_37 , V_7 ) ;
return 1 ;
}
}
return 0 ;
}
int F_25 ( T_1 * V_7 , T_1 * V_2 , const T_1 * V_9 , const T_1 * V_4 ,
T_2 * V_5 )
{
int V_1 ;
F_2 ( V_2 ) ;
F_2 ( V_9 ) ;
F_2 ( V_4 ) ;
#ifdef F_26
if( F_19 ( V_7 , V_2 , V_9 , V_4 ) )
return 1 ;
V_39 = 1 ;
#endif
#ifdef F_27
if ( F_12 ( V_4 ) )
{
if ( V_2 -> V_40 == 1 )
{
T_4 V_41 = V_2 -> V_42 [ 0 ] ;
V_1 = F_28 ( V_7 , V_41 , V_9 , V_4 , V_5 , NULL ) ;
}
else
V_1 = F_29 ( V_7 , V_2 , V_9 , V_4 , V_5 , NULL ) ;
}
else
#endif
#ifdef F_30
{ V_1 = F_31 ( V_7 , V_2 , V_9 , V_4 , V_5 ) ; }
#else
{ V_1 = F_32 ( V_7 , V_2 , V_9 , V_4 , V_5 ) ; }
#endif
#ifdef F_26
V_39 = 0 ;
#endif
return ( V_1 ) ;
}
int F_31 ( T_1 * V_7 , const T_1 * V_2 , const T_1 * V_9 ,
const T_1 * V_4 , T_2 * V_5 )
{
int V_10 , V_43 , V_11 , V_1 = 0 , V_44 , V_45 , V_46 , V_47 ;
int V_48 = 1 , V_49 = 0 ;
T_1 * V_50 ;
T_1 V_51 [ V_52 ] ;
T_5 V_53 ;
V_11 = F_11 ( V_9 ) ;
if ( V_11 == 0 )
{
F_13 ( V_7 ) ;
return ( 1 ) ;
}
F_3 ( V_5 ) ;
if ( ( V_50 = F_4 ( V_5 ) ) == NULL ) goto V_8;
F_33 ( & V_53 ) ;
if ( F_34 ( & V_53 , V_4 , V_5 ) <= 0 ) goto V_8;
F_35 ( & ( V_51 [ 0 ] ) ) ;
V_49 = 1 ;
if ( ! F_7 ( & ( V_51 [ 0 ] ) , V_2 , V_4 , V_5 ) ) goto V_8;
V_46 = F_36 ( V_11 ) ;
if ( V_46 > 1 )
{
if ( ! F_37 ( V_50 , & ( V_51 [ 0 ] ) , & ( V_51 [ 0 ] ) , & V_53 , V_5 ) )
goto V_8;
V_43 = 1 << ( V_46 - 1 ) ;
for ( V_10 = 1 ; V_10 < V_43 ; V_10 ++ )
{
F_35 ( & V_51 [ V_10 ] ) ;
if ( ! F_37 ( & ( V_51 [ V_10 ] ) , & ( V_51 [ V_10 - 1 ] ) , V_50 , & V_53 , V_5 ) )
goto V_8;
}
V_49 = V_10 ;
}
V_48 = 1 ;
V_47 = 0 ;
V_44 = V_11 - 1 ;
V_45 = 0 ;
if ( ! F_13 ( V_7 ) ) goto V_8;
for (; ; )
{
if ( F_14 ( V_9 , V_44 ) == 0 )
{
if ( ! V_48 )
if ( ! F_37 ( V_7 , V_7 , V_7 , & V_53 , V_5 ) )
goto V_8;
if ( V_44 == 0 ) break;
V_44 -- ;
continue;
}
V_43 = V_44 ;
V_47 = 1 ;
V_45 = 0 ;
for ( V_10 = 1 ; V_10 < V_46 ; V_10 ++ )
{
if ( V_44 - V_10 < 0 ) break;
if ( F_14 ( V_9 , V_44 - V_10 ) )
{
V_47 <<= ( V_10 - V_45 ) ;
V_47 |= 1 ;
V_45 = V_10 ;
}
}
V_43 = V_45 + 1 ;
if ( ! V_48 )
for ( V_10 = 0 ; V_10 < V_43 ; V_10 ++ )
{
if ( ! F_37 ( V_7 , V_7 , V_7 , & V_53 , V_5 ) )
goto V_8;
}
if ( ! F_37 ( V_7 , V_7 , & ( V_51 [ V_47 >> 1 ] ) , & V_53 , V_5 ) )
goto V_8;
V_44 -= V_45 + 1 ;
V_47 = 0 ;
V_48 = 0 ;
if ( V_44 < 0 ) break;
}
V_1 = 1 ;
V_8:
F_8 ( V_5 ) ;
for ( V_10 = 0 ; V_10 < V_49 ; V_10 ++ )
F_38 ( & ( V_51 [ V_10 ] ) ) ;
F_39 ( & V_53 ) ;
return ( V_1 ) ;
}
int F_29 ( T_1 * V_13 , T_1 * V_2 , const T_1 * V_9 ,
const T_1 * V_4 , T_2 * V_5 , T_6 * V_54 )
{
int V_10 , V_43 , V_11 , V_1 = 0 , V_44 , V_45 , V_46 , V_47 ;
int V_48 = 1 , V_49 = 0 ;
T_1 * V_42 , * V_7 ;
T_1 * V_50 ;
T_1 V_51 [ V_52 ] ;
T_6 * V_55 = NULL ;
F_2 ( V_2 ) ;
F_2 ( V_9 ) ;
F_2 ( V_4 ) ;
#ifdef F_26
if( ! V_39 && F_19 ( V_13 , V_2 , V_9 , V_4 ) )
return 1 ;
#endif
if ( ! ( V_4 -> V_42 [ 0 ] & 1 ) )
{
F_40 ( V_56 , V_57 ) ;
return ( 0 ) ;
}
V_11 = F_11 ( V_9 ) ;
if ( V_11 == 0 )
{
F_13 ( V_13 ) ;
return ( 1 ) ;
}
F_3 ( V_5 ) ;
V_42 = F_4 ( V_5 ) ;
V_7 = F_4 ( V_5 ) ;
if ( V_42 == NULL || V_7 == NULL ) goto V_8;
if ( V_54 != NULL )
V_55 = V_54 ;
else
{
if ( ( V_55 = F_41 () ) == NULL ) goto V_8;
if ( ! F_42 ( V_55 , V_4 , V_5 ) ) goto V_8;
}
F_35 ( & V_51 [ 0 ] ) ;
V_49 = 1 ;
if ( F_43 ( V_2 , V_4 ) >= 0 )
{
if ( ! F_7 ( & ( V_51 [ 0 ] ) , V_2 , V_4 , V_5 ) )
goto V_8;
V_50 = & ( V_51 [ 0 ] ) ;
}
else
V_50 = V_2 ;
if ( ! F_44 ( & ( V_51 [ 0 ] ) , V_50 , V_55 , V_5 ) ) goto V_8;
V_46 = F_36 ( V_11 ) ;
if ( V_46 > 1 )
{
if ( ! F_45 ( V_42 , & ( V_51 [ 0 ] ) , & ( V_51 [ 0 ] ) , V_55 , V_5 ) ) goto V_8;
V_43 = 1 << ( V_46 - 1 ) ;
for ( V_10 = 1 ; V_10 < V_43 ; V_10 ++ )
{
F_35 ( & ( V_51 [ V_10 ] ) ) ;
if ( ! F_45 ( & ( V_51 [ V_10 ] ) , & ( V_51 [ V_10 - 1 ] ) , V_42 , V_55 , V_5 ) )
goto V_8;
}
V_49 = V_10 ;
}
V_48 = 1 ;
V_47 = 0 ;
V_44 = V_11 - 1 ;
V_45 = 0 ;
if ( ! F_44 ( V_7 , F_46 () , V_55 , V_5 ) ) goto V_8;
for (; ; )
{
if ( F_14 ( V_9 , V_44 ) == 0 )
{
if ( ! V_48 )
{
if ( ! F_45 ( V_7 , V_7 , V_7 , V_55 , V_5 ) )
goto V_8;
}
if ( V_44 == 0 ) break;
V_44 -- ;
continue;
}
V_43 = V_44 ;
V_47 = 1 ;
V_45 = 0 ;
for ( V_10 = 1 ; V_10 < V_46 ; V_10 ++ )
{
if ( V_44 - V_10 < 0 ) break;
if ( F_14 ( V_9 , V_44 - V_10 ) )
{
V_47 <<= ( V_10 - V_45 ) ;
V_47 |= 1 ;
V_45 = V_10 ;
}
}
V_43 = V_45 + 1 ;
if ( ! V_48 )
for ( V_10 = 0 ; V_10 < V_43 ; V_10 ++ )
{
if ( ! F_45 ( V_7 , V_7 , V_7 , V_55 , V_5 ) )
goto V_8;
}
if ( ! F_45 ( V_7 , V_7 , & ( V_51 [ V_47 >> 1 ] ) , V_55 , V_5 ) )
goto V_8;
V_44 -= V_45 + 1 ;
V_47 = 0 ;
V_48 = 0 ;
if ( V_44 < 0 ) break;
}
if ( ! F_47 ( V_13 , V_7 , V_55 , V_5 ) ) goto V_8;
V_1 = 1 ;
V_8:
if ( ( V_54 == NULL ) && ( V_55 != NULL ) ) F_48 ( V_55 ) ;
F_8 ( V_5 ) ;
for ( V_10 = 0 ; V_10 < V_49 ; V_10 ++ )
F_38 ( & ( V_51 [ V_10 ] ) ) ;
return ( V_1 ) ;
}
int F_28 ( T_1 * V_13 , T_4 V_2 , const T_1 * V_9 ,
const T_1 * V_4 , T_2 * V_5 , T_6 * V_54 )
{
T_6 * V_55 = NULL ;
int V_3 , V_11 , V_1 = 0 ;
int V_58 ;
T_4 V_59 , V_60 ;
T_1 * V_42 , * V_7 , * V_6 ;
T_1 * V_61 ;
#define F_49 ( V_7 , V_59 , V_4 ) \
(BN_mul_word(r, (w)) && \
( \
(BN_mod(t, r, m, ctx) && (swap_tmp = r, r = t, t = swap_tmp, 1))))
#define F_50 ( V_7 , V_59 , V_55 ) \
(BN_set_word(r, (w)) && BN_to_montgomery(r, r, (mont), ctx))
F_2 ( V_9 ) ;
F_2 ( V_4 ) ;
if ( ! ( V_4 -> V_42 [ 0 ] & 1 ) )
{
F_40 ( V_62 , V_57 ) ;
return ( 0 ) ;
}
V_11 = F_11 ( V_9 ) ;
if ( V_11 == 0 )
{
F_13 ( V_13 ) ;
return ( 1 ) ;
}
F_3 ( V_5 ) ;
V_42 = F_4 ( V_5 ) ;
V_7 = F_4 ( V_5 ) ;
V_6 = F_4 ( V_5 ) ;
if ( V_42 == NULL || V_7 == NULL || V_6 == NULL ) goto V_8;
#ifdef F_26
if ( ! V_39 )
{
F_51 ( V_6 , V_2 ) ;
if ( F_19 ( V_13 , V_6 , V_9 , V_4 ) )
{
F_8 ( V_5 ) ;
return 1 ;
}
}
#endif
if ( V_54 != NULL )
V_55 = V_54 ;
else
{
if ( ( V_55 = F_41 () ) == NULL ) goto V_8;
if ( ! F_42 ( V_55 , V_4 , V_5 ) ) goto V_8;
}
V_58 = 1 ;
V_59 = V_2 ;
for ( V_3 = V_11 - 2 ; V_3 >= 0 ; V_3 -- )
{
V_60 = V_59 * V_59 ;
if ( ( V_60 / V_59 ) != V_59 )
{
if ( V_58 )
{
if ( ! F_50 ( V_7 , V_59 , V_55 ) ) goto V_8;
V_58 = 0 ;
}
else
{
if ( ! F_49 ( V_7 , V_59 , V_4 ) ) goto V_8;
}
V_60 = 1 ;
}
V_59 = V_60 ;
if ( ! V_58 )
{
if ( ! F_45 ( V_7 , V_7 , V_7 , V_55 , V_5 ) ) goto V_8;
}
if ( F_14 ( V_9 , V_3 ) )
{
V_60 = V_59 * V_2 ;
if ( ( V_60 / V_2 ) != V_59 )
{
if ( V_58 )
{
if ( ! F_50 ( V_7 , V_59 , V_55 ) ) goto V_8;
V_58 = 0 ;
}
else
{
if ( ! F_49 ( V_7 , V_59 , V_4 ) ) goto V_8;
}
V_60 = V_2 ;
}
V_59 = V_60 ;
}
}
if ( V_59 != 1 )
{
if ( V_58 )
{
if ( ! F_50 ( V_7 , V_59 , V_55 ) ) goto V_8;
V_58 = 0 ;
}
else
{
if ( ! F_49 ( V_7 , V_59 , V_4 ) ) goto V_8;
}
}
if ( V_58 )
{
if ( ! F_13 ( V_13 ) ) goto V_8;
}
else
{
if ( ! F_47 ( V_13 , V_7 , V_55 , V_5 ) ) goto V_8;
}
V_1 = 1 ;
V_8:
if ( ( V_54 == NULL ) && ( V_55 != NULL ) ) F_48 ( V_55 ) ;
F_8 ( V_5 ) ;
return ( V_1 ) ;
}
int F_32 ( T_1 * V_7 , T_1 * V_2 , T_1 * V_9 , T_1 * V_4 ,
T_2 * V_5 )
{
int V_10 , V_43 , V_11 , V_1 = 0 , V_44 , V_45 , V_46 , V_47 , V_49 = 0 ;
int V_48 = 1 ;
T_1 * V_42 ;
T_1 V_51 [ V_52 ] ;
V_11 = F_11 ( V_9 ) ;
if ( V_11 == 0 )
{
F_13 ( V_7 ) ;
return ( 1 ) ;
}
F_3 ( V_5 ) ;
if ( ( V_42 = F_4 ( V_5 ) ) == NULL ) goto V_8;
F_35 ( & ( V_51 [ 0 ] ) ) ;
V_49 = 1 ;
if ( ! F_7 ( & ( V_51 [ 0 ] ) , V_2 , V_4 , V_5 ) ) goto V_8;
V_46 = F_36 ( V_11 ) ;
if ( V_46 > 1 )
{
if ( ! F_1 ( V_42 , & ( V_51 [ 0 ] ) , & ( V_51 [ 0 ] ) , V_4 , V_5 ) )
goto V_8;
V_43 = 1 << ( V_46 - 1 ) ;
for ( V_10 = 1 ; V_10 < V_43 ; V_10 ++ )
{
F_35 ( & ( V_51 [ V_10 ] ) ) ;
if ( ! F_1 ( & ( V_51 [ V_10 ] ) , & ( V_51 [ V_10 - 1 ] ) , V_42 , V_4 , V_5 ) )
goto V_8;
}
V_49 = V_10 ;
}
V_48 = 1 ;
V_47 = 0 ;
V_44 = V_11 - 1 ;
V_45 = 0 ;
if ( ! F_13 ( V_7 ) ) goto V_8;
for (; ; )
{
if ( F_14 ( V_9 , V_44 ) == 0 )
{
if ( ! V_48 )
if ( ! F_1 ( V_7 , V_7 , V_7 , V_4 , V_5 ) )
goto V_8;
if ( V_44 == 0 ) break;
V_44 -- ;
continue;
}
V_43 = V_44 ;
V_47 = 1 ;
V_45 = 0 ;
for ( V_10 = 1 ; V_10 < V_46 ; V_10 ++ )
{
if ( V_44 - V_10 < 0 ) break;
if ( F_14 ( V_9 , V_44 - V_10 ) )
{
V_47 <<= ( V_10 - V_45 ) ;
V_47 |= 1 ;
V_45 = V_10 ;
}
}
V_43 = V_45 + 1 ;
if ( ! V_48 )
for ( V_10 = 0 ; V_10 < V_43 ; V_10 ++ )
{
if ( ! F_1 ( V_7 , V_7 , V_7 , V_4 , V_5 ) )
goto V_8;
}
if ( ! F_1 ( V_7 , V_7 , & ( V_51 [ V_47 >> 1 ] ) , V_4 , V_5 ) )
goto V_8;
V_44 -= V_45 + 1 ;
V_47 = 0 ;
V_48 = 0 ;
if ( V_44 < 0 ) break;
}
V_1 = 1 ;
V_8:
F_8 ( V_5 ) ;
for ( V_10 = 0 ; V_10 < V_49 ; V_10 ++ )
F_38 ( & ( V_51 [ V_10 ] ) ) ;
return ( V_1 ) ;
}
