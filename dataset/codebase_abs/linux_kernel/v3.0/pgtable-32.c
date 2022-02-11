void F_1 ( unsigned long V_1 )
{
unsigned long * V_2 = ( unsigned long * ) V_1 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 += 8 ) {
V_2 [ V_3 + 0 ] = ( unsigned long ) V_5 ;
V_2 [ V_3 + 1 ] = ( unsigned long ) V_5 ;
V_2 [ V_3 + 2 ] = ( unsigned long ) V_5 ;
V_2 [ V_3 + 3 ] = ( unsigned long ) V_5 ;
V_2 [ V_3 + 4 ] = ( unsigned long ) V_5 ;
V_2 [ V_3 + 5 ] = ( unsigned long ) V_5 ;
V_2 [ V_3 + 6 ] = ( unsigned long ) V_5 ;
V_2 [ V_3 + 7 ] = ( unsigned long ) V_5 ;
}
}
void T_1 F_2 ( void )
{
unsigned long V_6 ;
T_2 * V_7 ;
#ifdef F_3
T_2 * V_8 ;
T_3 * V_9 ;
T_4 * V_10 ;
T_5 * V_11 ;
#endif
F_1 ( ( unsigned long ) V_12 ) ;
F_1 ( ( unsigned long ) V_12
+ sizeof( T_2 ) * V_4 ) ;
V_7 = V_12 ;
V_6 = F_4 ( V_13 - 1 ) & V_14 ;
F_5 ( V_6 , 0 , V_7 ) ;
#ifdef F_3
V_6 = V_15 ;
F_5 ( V_6 , V_6 + V_16 * V_17 , V_7 ) ;
V_8 = V_12 + F_6 ( V_6 ) ;
V_9 = F_7 ( V_8 , V_6 ) ;
V_10 = F_8 ( V_9 , V_6 ) ;
V_11 = F_9 ( V_10 , V_6 ) ;
V_18 = V_11 ;
#endif
}
