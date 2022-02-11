static T_1 int F_1 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < 32 ; V_1 ++ ) {
T_2 V_2 ;
V_2 = F_2 ( 0 , V_1 , 0 , 0x00 ) ;
if ( V_2 != ( V_3 | ( 0x1100 << 16 ) ) &&
V_2 != ( V_3 | ( 0x1200 << 16 ) ) &&
V_2 != ( V_3 | ( 0x1300 << 16 ) ) )
continue;
V_2 = F_2 ( 0 , V_1 , 1 , 0x00 ) ;
if ( V_2 != ( V_3 | ( 0x1101 << 16 ) ) &&
V_2 != ( V_3 | ( 0x1201 << 16 ) ) &&
V_2 != ( V_3 | ( 0x1301 << 16 ) ) )
continue;
return V_1 ;
}
return - V_4 ;
}
static T_1 void F_3 ( void )
{
#ifdef F_4
if ( V_5 )
F_5 () ;
#endif
}
int T_1 F_6 ( void )
{
T_3 V_6 = F_7 ( 0 ) ;
T_3 V_7 = F_7 ( V_8 ) ;
unsigned V_9 ;
T_3 V_10 ;
int V_11 , V_12 , V_13 ;
T_2 V_14 , V_15 ;
unsigned int V_16 , V_17 , V_18 ;
if ( ! F_8 () )
return - V_19 ;
V_13 = F_1 () ;
if ( V_13 < 0 )
return V_13 ;
F_9 ( L_1 , V_13 ) ;
V_15 = F_2 ( 0 , V_13 , 0 , 0x60 ) ;
V_9 = ( ( V_15 >> 4 ) & 0xF ) + 1 ;
if ( V_9 <= 1 )
return - V_4 ;
F_9 ( L_2 , V_9 ) ;
V_10 = 0 ;
for ( V_11 = 0 ; V_11 < 8 ; V_11 ++ ) {
T_3 V_20 , V_21 ;
V_20 = F_2 ( 0 , V_13 , 1 , 0x40 + V_11 * 8 ) ;
V_21 = F_2 ( 0 , V_13 , 1 , 0x44 + V_11 * 8 ) ;
V_22 [ V_11 ] = V_14 = V_21 & 7 ;
if ( ( V_20 & 3 ) == 0 ) {
if ( V_11 < V_9 )
F_9 ( L_3 , V_11 ) ;
continue;
}
if ( V_14 >= V_9 ) {
F_9 ( L_4 , V_14 ,
V_20 , V_21 ) ;
continue;
}
if ( ! V_21 ) {
F_9 ( L_5 ,
V_11 , V_20 ) ;
continue;
}
if ( ( V_20 >> 8 ) & 3 || ( V_21 >> 8 ) & 3 ) {
F_10 ( L_6 ,
V_14 , ( V_20 >> 8 ) & 3 , ( V_21 >> 8 ) & 3 ) ;
return - V_19 ;
}
if ( F_11 ( V_14 , V_23 ) ) {
F_9 ( L_7 ,
V_14 ) ;
continue;
}
V_21 >>= 16 ;
V_21 ++ ;
V_21 <<= 24 ;
if ( V_21 > V_7 )
V_21 = V_7 ;
if ( V_21 <= V_20 )
continue;
V_20 >>= 16 ;
V_20 <<= 24 ;
if ( V_20 < V_6 )
V_20 = V_6 ;
if ( V_21 > V_7 )
V_21 = V_7 ;
if ( V_21 == V_20 ) {
F_10 ( L_8 , V_14 ) ;
continue;
}
if ( V_21 < V_20 ) {
F_10 ( L_9 ,
V_14 , V_20 , V_21 ) ;
continue;
}
if ( V_10 > V_20 ) {
F_10 ( L_10 ,
V_10 , V_20 ) ;
return - V_19 ;
}
F_9 ( L_11 ,
V_14 , V_20 , V_21 ) ;
V_10 = V_20 ;
F_12 ( V_14 , V_20 , V_21 ) ;
F_13 ( V_14 , V_23 ) ;
}
if ( ! F_14 ( V_23 ) )
return - V_4 ;
V_16 = V_24 . V_25 ;
V_17 = 1 << V_16 ;
V_18 = 0 ;
F_3 () ;
if ( V_26 > 0 ) {
F_9 ( L_12 , V_26 ) ;
V_18 = V_26 ;
}
F_15 (i, numa_nodes_parsed)
for ( V_12 = V_18 ; V_12 < V_17 + V_18 ; V_12 ++ )
F_16 ( ( V_11 << V_16 ) + V_12 , V_11 ) ;
return 0 ;
}
