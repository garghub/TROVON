char * F_1 ( void )
{
T_1 * V_1 ;
V_1 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_1 == NULL )
return ( NULL ) ;
memset ( V_1 , 0 , sizeof( T_1 ) ) ;
#ifdef F_3
V_1 -> V_2 = F_4 () ;
#endif
return ( ( char * ) V_1 ) ;
}
void F_5 ( char * V_3 )
{
if ( V_3 != NULL )
F_6 ( V_3 ) ;
}
void F_7 ( char * V_3 )
{
T_1 * V_4 = ( T_1 * ) V_3 ;
#ifdef F_3
T_2 V_5 , V_6 , V_7 ;
#endif
#ifdef F_8
F_9 ( & V_4 -> V_8 ) ;
#else
# ifdef F_3
F_10 ( V_4 -> V_2 , & V_5 , & V_6 , & V_7 , & ( V_4 -> V_9 ) ) ;
# else
F_11 ( & V_4 -> V_10 ) ;
# endif
#endif
}
double F_12 ( char * V_11 , char * V_12 )
{
T_1 * V_3 = ( T_1 * ) V_11 ;
T_1 * V_13 = ( T_1 * ) V_12 ;
double V_1 ;
#ifdef F_8
V_1 = ( V_13 -> V_8 . V_14 - V_3 -> V_8 . V_14 ) / V_15 ;
#else
# ifdef F_3
{
#ifdef F_13
signed long long V_16 , V_17 ;
#else
signed T_3 V_16 , V_17 ;
#endif
V_16 = V_3 -> V_9 . V_18 ;
V_17 = V_13 -> V_9 . V_18 ;
V_16 <<= 32 ;
V_17 <<= 32 ;
V_16 += V_3 -> V_9 . V_19 ;
V_17 += V_13 -> V_9 . V_19 ;
V_1 = ( ( double ) ( V_17 - V_16 ) ) / 1e7 ;
}
# else
V_1 = ( double ) ( V_13 -> V_10 . time - V_3 -> V_10 . time ) +
( ( ( double ) V_13 -> V_10 . V_20 ) -
( ( double ) V_3 -> V_10 . V_20 ) ) / 1000.0 ;
# endif
#endif
return ( ( V_1 < 0.0000001 ) ? 0.0000001 : V_1 ) ;
}
int F_14 ( char * V_11 , char * V_12 )
{
T_1 * V_3 = ( T_1 * ) V_11 , * V_13 = ( T_1 * ) V_12 ;
double V_21 ;
int V_1 ;
#ifdef F_8
V_21 = ( V_13 -> V_8 . V_14 - V_3 -> V_8 . V_14 ) / V_15 ;
#else
# ifdef F_3
V_21 = ( V_13 -> V_9 . V_18 & 0x000fffff ) * 10 + V_13 -> V_9 . V_19 / 1e7 ;
V_21 -= ( V_3 -> V_9 . V_18 & 0x000fffff ) * 10 + V_3 -> V_9 . V_19 / 1e7 ;
# else
V_21 = ( double ) ( V_13 -> V_10 . time - V_3 -> V_10 . time ) +
( ( ( double ) V_13 -> V_10 . V_20 ) - ( double ) V_3 -> V_10 . V_20 ) / 1000.0 ;
# endif
#endif
if ( V_21 == 0.0 )
V_1 = 0 ;
else if ( V_21 < 0 )
V_1 = - 1 ;
else
V_1 = 1 ;
return ( V_1 ) ;
}
