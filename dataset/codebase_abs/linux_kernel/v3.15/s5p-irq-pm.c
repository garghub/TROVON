int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 ;
unsigned int V_5 , V_6 ;
V_5 = V_7 ;
V_6 = V_8 ;
if ( V_2 -> V_9 == V_5 || V_2 -> V_9 == V_6 ) {
V_4 = 1 << ( V_2 -> V_9 + 1 - V_6 ) ;
if ( ! V_3 )
V_10 |= V_4 ;
else
V_10 &= ~ V_4 ;
} else {
return - V_11 ;
}
return 0 ;
}
int F_2 ( void )
{
F_3 ( V_12 , F_4 ( V_12 ) ) ;
return 0 ;
}
void F_5 ( void )
{
F_6 ( V_12 , F_4 ( V_12 ) ) ;
}
