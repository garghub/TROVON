void T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_2 V_4 = ( ( T_2 ) V_5 << 32 ) | V_6 ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
V_8 [ V_3 ] = V_4 & 0xff ;
V_4 >>= 8 ;
}
if ( F_2 ( V_8 ) ) {
V_2 -> V_9 |= V_10 ;
V_2 -> V_11 = V_8 ;
F_3 ( V_12 L_1 ,
V_13 ) ;
} else {
V_2 -> V_9 |= V_14 ;
F_3 ( V_12 L_2
L_3 , V_13 ) ;
}
}
static void F_4 ( int V_15 )
{
F_5 ( V_16 , ! ! V_15 ) ;
}
void T_1 F_6 ( int V_17 )
{
V_16 = V_17 ;
F_7 ( V_17 , L_4 ) ;
F_8 ( V_17 , 0 ) ;
F_9 ( NULL , & V_18 ) ;
}
void T_1 F_10 ( void )
{
F_11 ( & V_19 ) ;
}
