static int F_1 ( int V_1 , bool V_2 , T_1 V_3 )
{
static F_2 ( V_4 ) ;
void T_2 * V_5 ;
unsigned long V_6 ;
T_1 V_7 ;
V_1 = F_3 ( 0 , V_1 ) ;
if ( V_1 > 1 )
return - V_8 ;
V_5 = F_4 ( V_1 ) ;
F_5 ( & V_4 , V_6 ) ;
V_7 = F_6 ( V_5 ) ;
V_7 = V_2 ? ( V_7 | V_3 ) : ( V_7 & ~ V_3 ) ;
F_7 ( V_7 , V_5 ) ;
if ( V_2 ) {
V_7 |= V_9 ;
} else if ( ! ( V_7 & ( V_10 |
V_11 ) & ~ V_3 ) ) {
V_7 &= ~ V_9 ;
}
F_7 ( V_7 , V_5 ) ;
F_8 ( & V_4 , V_6 ) ;
return 0 ;
}
int F_9 ( int V_1 , bool V_2 )
{
return F_1 ( V_1 , V_2 , V_10 ) ;
}
int F_10 ( struct V_12 * V_13 , bool V_2 )
{
return F_1 ( V_13 -> V_1 , V_2 , V_11 ) ;
}
