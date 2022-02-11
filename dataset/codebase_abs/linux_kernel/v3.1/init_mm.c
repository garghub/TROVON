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
V_17 = V_18 = 0 ;
F_8 (pgdat) {
V_18 += V_13 -> V_19 ;
V_17 += F_9 ( V_13 ) ;
for ( V_5 = 0 ; V_5 < V_13 -> V_20 ; V_5 ++ ) {
struct V_21 * V_21 = V_13 -> V_22 + V_5 ;
char * V_7 = F_10 ( V_21 ) ;
if ( ! F_11 ( V_21 ) )
continue;
if ( V_7 >= V_23 &&
V_7 < V_24 )
V_14 ++ ;
else if ( V_7 >= V_25 &&
V_7 < V_26 )
V_16 ++ ;
else
V_15 ++ ;
}
}
#ifndef F_12
F_13 ( ( unsigned long ) V_27 ) ;
for ( V_5 = 0 ; V_5 < V_28 ; V_5 ++ ) {
if ( F_14 ( V_27 [ V_5 ] ) )
F_13 ( F_15 ( V_27 [ V_5 ] ) ) ;
}
if ( V_29 )
F_13 ( ( unsigned long ) V_29 ) ;
#endif
F_5 ( L_2 ,
F_16 () << ( V_30 - 10 ) ,
V_17 << ( V_30 - 10 ) ,
V_14 << ( V_30 - 10 ) ,
V_15 << ( V_30 - 10 ) ,
V_16 << ( V_30 - 10 ) ) ;
}
void F_17 ( unsigned long V_31 , unsigned long V_6 )
{
int V_32 = 0 ;
for (; V_31 < V_6 ; V_31 += V_33 ) {
F_18 ( F_19 ( V_31 ) ) ;
F_20 ( F_19 ( V_31 ) ) ;
F_21 ( V_31 ) ;
V_17 ++ ;
V_32 ++ ;
}
F_5 ( L_3 , V_32 ) ;
}
