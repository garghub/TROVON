static void F_1 ( T_1 * V_1 , T_2 * V_2 , const T_2 * V_3 ,
unsigned int V_4 )
{
T_2 V_5 [ V_6 ] ;
while ( V_4 >= V_6 * 4 ) {
F_2 ( V_1 , V_2 , V_3 ) ;
V_4 -= V_6 * 4 ;
V_3 += V_6 * 4 ;
V_2 += V_6 * 4 ;
V_1 [ 12 ] += 4 ;
}
while ( V_4 >= V_6 ) {
F_3 ( V_1 , V_2 , V_3 ) ;
V_4 -= V_6 ;
V_3 += V_6 ;
V_2 += V_6 ;
V_1 [ 12 ] ++ ;
}
if ( V_4 ) {
memcpy ( V_5 , V_3 , V_4 ) ;
F_3 ( V_1 , V_5 , V_5 ) ;
memcpy ( V_2 , V_5 , V_4 ) ;
}
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_5 ( V_8 ) ;
struct V_11 * V_12 = F_6 ( V_10 ) ;
struct V_13 V_14 ;
T_1 V_1 [ 16 ] ;
int V_15 ;
if ( V_8 -> V_16 <= V_6 || ! F_7 () )
return F_8 ( V_8 ) ;
V_15 = F_9 ( & V_14 , V_8 , true ) ;
F_10 ( V_1 , V_12 , V_14 . V_17 ) ;
F_11 () ;
while ( V_14 . V_18 > 0 ) {
unsigned int V_18 = V_14 . V_18 ;
if ( V_18 < V_14 . V_19 )
V_18 = F_12 ( V_18 , V_14 . V_20 ) ;
F_1 ( V_1 , V_14 . V_2 . V_21 . V_22 , V_14 . V_3 . V_21 . V_22 ,
V_18 ) ;
V_15 = F_13 ( & V_14 , V_14 . V_18 - V_18 ) ;
}
F_14 () ;
return V_15 ;
}
static int T_3 F_15 ( void )
{
if ( ! ( V_23 & V_24 ) )
return - V_25 ;
return F_16 ( & V_26 ) ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_26 ) ;
}
