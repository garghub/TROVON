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
static int F_6 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_7 ( V_9 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
T_1 * V_1 , V_14 [ 16 + 2 ] V_15 ( 8 ) ;
struct V_16 V_17 ;
int V_18 ;
F_9 ( V_19 != 16 ) ;
V_1 = F_10 ( V_14 + 0 , V_19 ) ;
if ( V_9 -> V_20 <= V_6 || ! F_11 () )
return F_12 ( V_9 ) ;
V_18 = F_13 ( & V_17 , V_9 , true ) ;
F_14 ( V_1 , V_13 , V_17 . V_21 ) ;
F_15 () ;
while ( V_17 . V_22 >= V_6 ) {
F_1 ( V_1 , V_17 . V_2 . V_23 . V_24 , V_17 . V_3 . V_23 . V_24 ,
F_16 ( V_17 . V_22 , V_6 ) ) ;
V_18 = F_17 ( & V_17 ,
V_17 . V_22 % V_6 ) ;
}
if ( V_17 . V_22 ) {
F_1 ( V_1 , V_17 . V_2 . V_23 . V_24 , V_17 . V_3 . V_23 . V_24 ,
V_17 . V_22 ) ;
V_18 = F_17 ( & V_17 , 0 ) ;
}
F_18 () ;
return V_18 ;
}
static int T_3 F_19 ( void )
{
if ( ! F_20 ( V_25 ) )
return - V_26 ;
#ifdef F_2
V_7 = F_20 ( V_27 ) &&
F_20 ( V_28 ) &&
F_21 ( V_29 | V_30 , NULL ) ;
#endif
return F_22 ( & V_31 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_31 ) ;
}
