static void F_1 ( T_1 * V_1 , T_2 * V_2 , const T_2 * V_3 ,
unsigned int V_4 )
{
T_2 V_5 [ V_6 ] ;
#ifdef F_2
if ( V_7 ) {
while ( V_4 >= V_6 * 8 ) {
F_3 ( V_1 , V_2 , V_3 ) ;
V_4 -= V_6 * 8 ;
V_3 += V_6 * 8 ;
V_2 += V_6 * 8 ;
V_1 [ 12 ] += 8 ;
}
}
#endif
while ( V_4 >= V_6 * 4 ) {
F_4 ( V_1 , V_2 , V_3 ) ;
V_4 -= V_6 * 4 ;
V_3 += V_6 * 4 ;
V_2 += V_6 * 4 ;
V_1 [ 12 ] += 4 ;
}
while ( V_4 >= V_6 ) {
F_5 ( V_1 , V_2 , V_3 ) ;
V_4 -= V_6 ;
V_3 += V_6 ;
V_2 += V_6 ;
V_1 [ 12 ] ++ ;
}
if ( V_4 ) {
memcpy ( V_5 , V_3 , V_4 ) ;
F_5 ( V_1 , V_5 , V_5 ) ;
memcpy ( V_2 , V_5 , V_4 ) ;
}
}
static int F_6 ( struct V_8 * V_9 , struct V_10 * V_2 ,
struct V_10 * V_3 , unsigned int V_11 )
{
T_1 * V_1 , V_12 [ 16 + ( V_13 / sizeof( T_1 ) ) - 1 ] ;
struct V_14 V_15 ;
int V_16 ;
if ( ! F_7 () )
return F_8 ( V_9 , V_2 , V_3 , V_11 ) ;
V_1 = ( T_1 * ) F_9 ( ( V_17 ) V_12 , V_13 ) ;
F_10 ( & V_15 , V_2 , V_3 , V_11 ) ;
V_16 = F_11 ( V_9 , & V_15 , V_6 ) ;
F_12 ( V_1 , F_13 ( V_9 -> V_18 ) , V_15 . V_19 ) ;
F_14 () ;
while ( V_15 . V_11 >= V_6 ) {
F_1 ( V_1 , V_15 . V_2 . V_20 . V_21 , V_15 . V_3 . V_20 . V_21 ,
F_15 ( V_15 . V_11 , V_6 ) ) ;
V_16 = F_16 ( V_9 , & V_15 ,
V_15 . V_11 % V_6 ) ;
}
if ( V_15 . V_11 ) {
F_1 ( V_1 , V_15 . V_2 . V_20 . V_21 , V_15 . V_3 . V_20 . V_21 ,
V_15 . V_11 ) ;
V_16 = F_16 ( V_9 , & V_15 , 0 ) ;
}
F_17 () ;
return V_16 ;
}
static int T_3 F_18 ( void )
{
if ( ! F_19 ( V_22 ) )
return - V_23 ;
#ifdef F_2
V_7 = V_24 && V_25 &&
F_20 ( V_26 | V_27 , NULL ) ;
#endif
return F_21 ( & V_28 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_28 ) ;
}
