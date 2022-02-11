static void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
F_2 ( ( int ) V_3 -> V_4 . V_5 ) ;
}
static void F_3 ( struct V_4 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
T_1 V_9 = ( 1 << 5 ) << ( V_6 -> V_1 - V_8 -> V_10 ) ;
F_5 ( V_9 | V_8 -> V_11 , V_8 -> V_12 ) ;
}
void T_2 F_6 ( unsigned int V_13 , unsigned int V_14 )
{
unsigned int V_15 [ 5 ] = { V_16 , V_17 , V_18 ,
V_19 , V_20 } ;
struct V_7 * V_21 ;
struct V_22 * V_23 ;
unsigned int V_24 ;
V_21 = F_7 ( L_1 , 1 , V_14 ,
V_25 , V_26 ) ;
if ( ! V_21 ) {
F_8 ( L_2 ,
V_27 , V_14 ) ;
return;
}
V_23 = V_21 -> V_28 ;
V_23 -> V_29 . V_30 = V_31 ;
V_23 -> V_29 . V_32 = V_33 ;
V_23 -> V_29 . V_34 = F_3 ;
F_9 ( V_21 , F_10 ( V_13 ) , V_35 ,
V_36 | V_37 , 0 ) ;
V_21 -> V_11 &= 0x1f ;
for ( V_24 = 0 ; V_24 < V_13 ; V_24 ++ , V_14 ++ ) {
F_11 ( V_15 [ V_24 ] , F_1 ) ;
F_12 ( V_15 [ V_24 ] , ( void * ) V_14 ) ;
}
}
