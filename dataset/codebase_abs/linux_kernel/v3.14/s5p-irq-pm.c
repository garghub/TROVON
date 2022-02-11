int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 ;
unsigned int V_5 , V_6 ;
#ifdef F_2
if ( F_3 () ) {
V_5 = V_7 ;
V_6 = V_8 ;
} else {
V_5 = V_9 ;
V_6 = V_10 ;
}
#else
V_5 = V_11 ;
V_6 = V_12 ;
#endif
if ( V_2 -> V_13 == V_5 || V_2 -> V_13 == V_6 ) {
V_4 = 1 << ( V_2 -> V_13 + 1 - V_6 ) ;
if ( ! V_3 )
V_14 |= V_4 ;
else
V_14 &= ~ V_4 ;
} else {
return - V_15 ;
}
return 0 ;
}
int F_4 ( void )
{
F_5 ( V_16 , F_6 ( V_16 ) ) ;
return 0 ;
}
void F_7 ( void )
{
F_8 ( V_16 , F_6 ( V_16 ) ) ;
}
