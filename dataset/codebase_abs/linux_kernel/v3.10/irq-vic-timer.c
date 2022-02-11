static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_1 ) ;
F_3 ( V_5 , V_3 ) ;
F_4 ( ( int ) V_3 -> V_6 . V_7 ) ;
F_5 ( V_5 , V_3 ) ;
}
static void F_6 ( struct V_6 * V_8 )
{
struct V_9 * V_10 = F_7 ( V_8 ) ;
T_1 V_11 = ( 1 << 5 ) << ( V_8 -> V_1 - V_10 -> V_12 ) ;
F_8 ( V_11 | V_10 -> V_13 , V_10 -> V_14 ) ;
}
void T_2 F_9 ( unsigned int V_15 , unsigned int V_16 )
{
unsigned int V_17 [ 5 ] = { V_18 , V_19 , V_20 ,
V_21 , V_22 } ;
struct V_9 * V_23 ;
struct V_24 * V_25 ;
unsigned int V_26 ;
#ifdef F_10
if ( F_11 () ) {
V_17 [ 0 ] = V_27 ;
V_17 [ 1 ] = V_28 ;
V_17 [ 2 ] = V_29 ;
V_17 [ 3 ] = V_30 ;
V_17 [ 4 ] = V_31 ;
} else {
V_17 [ 0 ] = V_32 ;
V_17 [ 1 ] = V_33 ;
V_17 [ 2 ] = V_34 ;
V_17 [ 3 ] = V_35 ;
V_17 [ 4 ] = V_36 ;
}
#endif
V_23 = F_12 ( L_1 , 1 , V_16 ,
V_37 , V_38 ) ;
if ( ! V_23 ) {
F_13 ( L_2 ,
V_39 , V_16 ) ;
return;
}
V_25 = V_23 -> V_40 ;
V_25 -> V_5 . V_41 = V_42 ;
V_25 -> V_5 . V_43 = V_44 ;
V_25 -> V_5 . V_45 = F_6 ;
F_14 ( V_23 , F_15 ( V_15 ) , V_46 ,
V_47 | V_48 , 0 ) ;
V_23 -> V_13 &= 0x1f ;
for ( V_26 = 0 ; V_26 < V_15 ; V_26 ++ , V_16 ++ ) {
F_16 ( V_17 [ V_26 ] , F_1 ) ;
F_17 ( V_17 [ V_26 ] , ( void * ) V_16 ) ;
}
}
