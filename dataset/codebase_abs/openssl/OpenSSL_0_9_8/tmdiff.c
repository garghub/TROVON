T_1 * F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL )
return ( NULL ) ;
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
#ifdef F_3
V_1 -> V_2 = F_4 () ;
#endif
return V_1 ;
}
void F_5 ( T_1 * V_3 )
{
if ( V_3 != NULL )
F_6 ( V_3 ) ;
}
void F_7 ( T_1 * V_4 )
{
#ifdef F_3
T_2 V_5 , V_6 , V_7 ;
#endif
#ifdef F_8
F_9 ( & V_4 -> V_8 ) ;
#else
# ifdef F_3
F_10 ( V_4 -> V_2 , & V_5 , & V_6 , & V_7 , & ( V_4 -> V_9 ) ) ;
# elif F_11 ( V_10 )
V_4 -> V_11 = clock () ;
# else
# ifdef F_12
V_4 -> V_12 = F_13 () ;
# else
F_14 ( & V_4 -> V_13 ) ;
# endif
# endif
#endif
}
double F_15 ( T_1 * V_3 , T_1 * V_14 )
{
double V_1 ;
#ifdef F_8
V_1 = V_15 ;
V_1 = ( V_14 -> V_8 . V_16 - V_3 -> V_8 . V_16 ) / V_1 ;
#else
# ifdef F_3
{
#ifdef F_16
signed long long V_17 , V_18 ;
#else
signed T_3 V_17 , V_18 ;
#endif
V_17 = V_3 -> V_9 . V_19 ;
V_18 = V_14 -> V_9 . V_19 ;
V_17 <<= 32 ;
V_18 <<= 32 ;
V_17 += V_3 -> V_9 . V_20 ;
V_18 += V_14 -> V_9 . V_20 ;
V_1 = ( ( double ) ( V_18 - V_17 ) ) / 1e7 ;
}
# elif F_11 ( V_10 )
V_1 = ( double ) ( V_14 -> V_11 - V_3 -> V_11 ) ;
# else
# ifdef F_12
V_1 = ( double ) ( V_14 -> V_12 - V_3 -> V_12 ) / ( double ) F_17 () ;
# else
V_1 = ( double ) ( V_14 -> V_13 . time - V_3 -> V_13 . time ) +
( ( ( double ) V_14 -> V_13 . V_21 ) -
( ( double ) V_3 -> V_13 . V_21 ) ) / 1000.0 ;
# endif
# endif
#endif
return ( ( V_1 < 0.0000001 ) ? 0.0000001 : V_1 ) ;
}
int F_18 ( const T_1 * V_3 , const T_1 * V_14 )
{
double V_22 ;
int V_1 ;
#ifdef F_8
V_22 = V_15 ;
V_22 = ( V_14 -> V_8 . V_16 - V_3 -> V_8 . V_16 ) / V_22 ;
#else
# ifdef F_3
V_22 = ( V_14 -> V_9 . V_19 & 0x000fffff ) * 10 + V_14 -> V_9 . V_20 / 1e7 ;
V_22 -= ( V_3 -> V_9 . V_19 & 0x000fffff ) * 10 + V_3 -> V_9 . V_20 / 1e7 ;
# elif F_11 ( V_10 )
V_22 = ( double ) ( V_14 -> V_11 - V_3 -> V_11 ) ;
# else
# ifdef F_12
V_22 = ( V_14 -> V_12 - V_3 -> V_12 ) ;
# else
V_22 = ( double ) ( V_14 -> V_13 . time - V_3 -> V_13 . time ) +
( ( ( double ) V_14 -> V_13 . V_21 ) - ( double ) V_3 -> V_13 . V_21 ) / 1000.0 ;
# endif
# endif
#endif
if ( V_22 == 0.0 )
V_1 = 0 ;
else if ( V_22 < 0 )
V_1 = - 1 ;
else
V_1 = 1 ;
return ( V_1 ) ;
}
