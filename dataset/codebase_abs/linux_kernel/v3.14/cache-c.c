void F_1 ( void )
{
T_1 V_1 = F_2 () ;
F_3 ( V_1 & ~ 0xc ) ;
F_4 () ;
F_3 ( V_1 ) ;
F_4 () ;
}
void F_5 ( void )
{
T_1 V_2 = F_6 () ;
F_7 ( V_2 & ~ 0x4 ) ;
F_4 () ;
F_7 ( V_2 ) ;
F_4 () ;
}
static void
F_8 ( struct V_3 * V_4 , unsigned long V_5 ,
unsigned long V_6 , unsigned long V_7 ,
unsigned long V_8 )
{
int V_9 ;
#ifdef F_9
T_1 V_10 ;
if ( V_5 == V_11 ) {
V_10 = F_10 ( V_7 ) | ( 1 << V_12 ) ;
F_11 () ;
F_12 ( V_7 , V_10 ) ;
F_4 () ;
}
#endif
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
F_12 ( V_5 + V_9 * 4 , V_4 [ V_9 ] . V_14 ) ;
F_12 ( V_6 + V_9 * 4 , V_4 [ V_9 ] . V_15 ) ;
}
F_13 ( V_7 , V_8 ) ;
}
void F_14 ( struct V_3 * V_16 )
{
F_8 ( V_16 , V_17 , V_18 , V_19 ,
( V_20 | V_21 ) ) ;
}
void F_15 ( struct V_3 * V_22 )
{
F_8 ( V_22 , V_11 , V_23 , V_24 ,
( V_25 | V_26 | ( V_27 ? V_28 : 0 ) ) ) ;
}
