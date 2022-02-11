void F_1 ( struct V_1 * V_2 , unsigned long V_3 , T_1 V_4 )
{
unsigned long V_5 , V_6 ;
int V_7 ;
F_2 ( V_6 ) ;
V_5 = F_3 ( V_8 ) ;
V_7 = ( V_5 & V_9 ) >> V_10 ;
V_5 &= ~ V_11 ;
F_4 ( ! -- V_7 ) ;
V_7 = V_7 % V_12 ;
V_5 |= ( V_7 << V_13 ) ;
F_5 ( V_5 , V_8 ) ;
F_6 () ;
F_7 ( V_2 , V_3 , V_4 ) ;
V_5 = F_3 ( V_8 ) ;
V_5 &= ~ V_9 ;
V_5 |= ( V_7 << V_10 ) ;
F_5 ( V_5 , V_8 ) ;
F_6 () ;
F_8 ( V_6 ) ;
}
void F_9 ( void )
{
unsigned long V_5 , V_6 ;
int V_7 ;
F_2 ( V_6 ) ;
V_5 = F_3 ( V_8 ) ;
V_7 = ( V_5 & V_9 ) >> V_10 ;
V_5 &= ~ V_9 ;
F_4 ( V_7 ++ == V_12 ) ;
V_7 = V_7 % V_12 ;
V_5 |= ( V_7 << V_10 ) ;
F_5 ( V_5 , V_8 ) ;
F_6 () ;
F_8 ( V_6 ) ;
}
