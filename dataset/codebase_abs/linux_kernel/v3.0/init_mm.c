void T_1 F_1 ( int V_1 )
{
#ifndef F_2
struct V_2 * V_3 = V_4 + V_1 ;
int V_5 , V_6 ;
V_5 = ( unsigned long ) F_3 ( V_3 -> V_7 ) >> F_4 () ;
V_6 = ( unsigned long ) F_3 ( V_3 -> V_7 + V_3 -> V_8 - 1 ) >> F_4 () ;
for (; V_5 <= V_6 ; V_5 ++ ) {
if ( V_9 [ V_5 ] )
F_5 ( L_1 , V_5 , V_1 ) ;
V_9 [ V_5 ] = V_10 + V_1 ;
}
#endif
V_10 [ V_1 ] . V_11 = V_12 + V_1 ;
F_6 ( V_1 ) ;
}
void T_1 F_7 ( void )
{
T_2 * V_13 ;
int V_14 = 0 ;
int V_15 = 0 ;
int V_16 = 0 ;
int V_5 ;
#ifdef F_8
if ( V_17 )
F_9 () ;
#endif
V_18 = V_19 = 0 ;
F_10 (pgdat) {
V_19 += V_13 -> V_20 ;
V_18 += F_11 ( V_13 ) ;
for ( V_5 = 0 ; V_5 < V_13 -> V_21 ; V_5 ++ ) {
struct V_22 * V_22 = V_13 -> V_23 + V_5 ;
char * V_7 = F_12 ( V_22 ) ;
if ( ! F_13 ( V_22 ) )
continue;
if ( V_7 >= V_24 &&
V_7 < V_25 )
V_14 ++ ;
else if ( V_7 >= V_26 &&
V_7 < V_27 )
V_16 ++ ;
else
V_15 ++ ;
}
}
#ifndef F_14
F_15 ( ( unsigned long ) V_28 ) ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
if ( F_16 ( V_28 [ V_5 ] ) )
F_15 ( F_17 ( V_28 [ V_5 ] ) ) ;
}
if ( V_30 )
F_15 ( ( unsigned long ) V_30 ) ;
#endif
F_5 ( L_2 ,
F_18 () << ( V_31 - 10 ) ,
V_18 << ( V_31 - 10 ) ,
V_14 << ( V_31 - 10 ) ,
V_15 << ( V_31 - 10 ) ,
V_16 << ( V_31 - 10 ) ) ;
}
void F_19 ( unsigned long V_32 , unsigned long V_6 )
{
int V_33 = 0 ;
for (; V_32 < V_6 ; V_32 += V_34 ) {
F_20 ( F_21 ( V_32 ) ) ;
F_22 ( F_21 ( V_32 ) ) ;
F_23 ( V_32 ) ;
V_18 ++ ;
V_33 ++ ;
}
F_5 ( L_3 , V_33 ) ;
}
