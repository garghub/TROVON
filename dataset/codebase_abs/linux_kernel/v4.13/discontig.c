static void T_1 F_1 ( void )
{
unsigned long V_1 , V_2 , V_3 ;
const unsigned long V_4 = 1UL << ( V_5 - 1 ) ;
unsigned long V_6 ;
T_2 * V_7 ;
V_7 = & V_8 [ 0 ] ;
V_7 -> V_1 = F_2 ( V_9 ) ;
V_7 -> V_10 = F_3 ( V_11 - V_12 ) ;
V_7 -> V_2 = 0 ;
V_7 -> V_3 = F_2 ( F_4 ( V_13 ) ) ;
V_7 = & V_8 [ 1 ] ;
V_1 = V_3 = F_2 ( V_14 ) ;
V_2 = 0 ;
if ( V_1 & ( V_4 - 1 ) ) {
V_6 = V_4 ;
while ( V_1 >= V_6 )
V_6 += V_4 ;
V_1 = V_6 - V_4 ;
V_2 = V_3 - V_1 ;
}
V_7 -> V_1 = V_1 ;
V_7 -> V_10 = F_3 ( V_15 ) + V_2 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_3 = F_2 ( V_14 ) ;
}
unsigned long T_1 F_5 ( void )
{
unsigned long V_16 ;
unsigned long V_17 ;
int V_18 ;
T_2 * V_7 ;
V_19 = 0 ;
V_20 = - 1 ;
F_1 () ;
F_6 (nid) {
V_7 = & V_8 [ V_18 ] ;
F_7 ( V_18 ) = ( V_21 * ) & V_22 [ V_18 ] ;
F_7 ( V_18 ) -> V_23 = & V_24 [ V_18 ] ;
V_17 = V_7 -> V_1 ;
V_25 = V_7 -> V_1 + V_7 -> V_10 ;
V_16 = F_8 ( F_7 ( V_18 ) , V_7 -> V_3 ,
V_7 -> V_1 , V_25 ) ;
F_9 ( F_7 ( V_18 ) , F_10 ( V_7 -> V_1 ) ,
F_10 ( V_7 -> V_10 ) ) ;
F_11 ( F_7 ( V_18 ) , F_10 ( V_7 -> V_1 ) ,
F_10 ( V_7 -> V_3 - V_7 -> V_1 ) + V_16 ,
V_26 ) ;
if ( V_19 < V_25 )
V_19 = V_25 ;
if ( V_20 > V_17 )
V_20 = V_17 ;
}
#ifdef F_12
if ( V_27 && V_28 ) {
if ( V_28 + V_29 <= F_10 ( V_19 ) ) {
F_11 ( F_7 ( 0 ) , V_28 ,
V_29 , V_26 ) ;
V_30 = V_28 + V_31 ;
V_32 = V_30 + V_29 ;
F_13 ( L_1 ,
V_30 , V_29 ) ;
} else {
F_13 ( L_2
L_3 ,
V_28 + V_29 ,
( unsigned long long ) F_10 ( V_19 ) ) ;
V_30 = 0 ;
}
}
#endif
return V_19 ;
}
void T_1 F_14 ( void )
{
unsigned long V_33 [ V_34 ] , V_35 [ V_34 ] ;
unsigned long V_36 , V_1 ;
int V_18 , V_37 ;
T_2 * V_7 ;
F_6 (nid) {
V_7 = & V_8 [ V_18 ] ;
for ( V_37 = 0 ; V_37 < V_34 ; V_37 ++ ) {
V_33 [ V_37 ] = 0 ;
V_35 [ V_37 ] = 0 ;
}
V_1 = F_15 ( V_18 ) ;
V_36 = F_16 ( V_18 ) ;
V_33 [ V_38 ] = V_36 - V_1 ;
V_35 [ V_38 ] = V_7 -> V_2 ;
F_17 ( V_18 , V_39 ) ;
F_18 ( V_18 , V_33 , V_1 , V_35 ) ;
}
F_7 ( 1 ) -> V_40 -> V_41 [ V_42 ] = 0 ;
F_7 ( 1 ) -> V_40 -> V_41 [ V_43 ] = 0 ;
F_7 ( 1 ) -> V_40 -> V_41 [ V_44 ] = 0 ;
}
