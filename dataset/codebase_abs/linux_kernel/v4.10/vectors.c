void T_1 F_1 ( void )
{
if ( V_1 ) {
extern T_2 * V_2 ;
__asm__ volatile ("movec %%vbr, %0" : "=r" (sun3x_prom_vbr));
}
__asm__ volatile ("movec %0,%%vbr" : : "r" ((void*)vectors));
if ( V_3 ) {
T_3 void V_4 ( void ) V_5 ( L_1 ) ;
V_6 [ V_7 ] = V_4 ;
}
V_6 [ V_8 ] = V_9 ;
V_6 [ V_10 ] = V_11 ;
V_6 [ V_12 ] = V_13 ;
}
void T_1 F_2 ( void )
{
int V_14 ;
for ( V_14 = V_15 ; V_14 <= V_16 ; V_14 ++ )
V_6 [ V_14 ] = V_17 ;
for ( V_14 = 0 ; V_14 < V_18 ; V_14 ++ )
if ( ! V_6 [ V_14 ] )
V_6 [ V_14 ] = V_11 ;
for ( V_14 = V_18 ; V_14 < 256 ; V_14 ++ )
V_6 [ V_14 ] = V_17 ;
#ifdef F_3
if ( V_19 )
V_6 [ V_20 ] = V_21 ;
#endif
if ( V_22 && ! V_19 ) {
T_3 void V_23 ( void ) V_5 ( L_2 ) ;
T_3 void V_24 ( void ) V_5 ( L_3 ) ;
T_3 void V_25 ( void ) V_5 ( L_4 ) ;
T_3 void V_26 ( void ) V_5 ( L_5 ) ;
T_3 void V_27 ( void ) V_5 ( L_6 ) ;
T_3 void V_28 ( void ) V_5 ( L_7 ) ;
T_3 void V_29 ( void ) V_5 ( L_8 ) ;
T_3 void V_30 ( void ) V_5 ( L_9 ) ;
T_3 void V_31 ( void ) V_5 ( L_10 ) ;
V_6 [ V_32 ] = V_23 ;
V_6 [ V_33 ] = V_24 ;
V_6 [ V_34 ] = V_25 ;
V_6 [ V_35 ] = V_26 ;
V_6 [ V_36 ] = V_27 ;
V_6 [ V_37 ] = V_28 ;
V_6 [ V_38 ] = V_29 ;
V_6 [ V_20 ] = V_30 ;
V_6 [ V_39 ] = V_31 ;
}
if ( V_3 && ! V_19 ) {
T_3 void V_40 ( void ) V_5 ( L_11 ) ;
T_3 void V_41 ( void ) V_5 ( L_12 ) ;
T_3 void V_42 ( void ) V_5 ( L_13 ) ;
T_3 void V_43 ( void ) V_5 ( L_14 ) ;
T_3 void V_44 ( void ) V_5 ( L_15 ) ;
T_3 void V_45 ( void ) V_5 ( L_16 ) ;
T_3 void V_46 ( void ) V_5 ( L_17 ) ;
T_3 void V_47 ( void ) V_5 ( L_18 ) ;
T_3 void V_48 ( void ) V_5 ( L_19 ) ;
V_6 [ V_36 ] = V_40 ;
V_6 [ V_37 ] = V_41 ;
V_6 [ V_34 ] = V_42 ;
V_6 [ V_35 ] = V_43 ;
V_6 [ V_32 ] = V_44 ;
V_6 [ V_33 ] = V_45 ;
V_6 [ V_20 ] = V_46 ;
V_6 [ V_39 ] = V_47 ;
V_6 [ V_49 ] = V_48 ;
}
if ( V_50 ) {
V_6 [ V_16 ] = V_51 ;
}
}
