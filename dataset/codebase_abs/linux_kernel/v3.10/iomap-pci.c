void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
unsigned long V_9 = V_6 -> V_10 ;
if ( F_2 ( ! V_6 -> V_10 ) ) {
struct V_11 * V_7 = V_2 -> V_7 ;
char V_12 [ 8 ] ;
while ( V_7 -> V_13 )
V_7 = V_7 -> V_13 ;
V_6 -> V_10 = V_9 = V_14 ;
sprintf ( V_12 , L_1 , F_3 ( V_7 ) , V_7 -> V_15 ) ;
F_4 ( V_16 L_2
L_3
L_4
L_5 , V_12 ) ;
#ifdef F_5
F_6 ( L_6
L_7 ) ;
#endif
}
return ( void T_1 * ) ( V_6 -> V_10 + V_3 ) ;
}
void F_7 ( struct V_1 * V_2 , void T_1 * V_17 )
{
F_8 ( V_17 ) ;
}
