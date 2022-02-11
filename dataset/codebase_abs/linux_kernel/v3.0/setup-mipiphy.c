static int F_1 ( struct V_1 * V_2 ,
bool V_3 , T_1 V_4 )
{
static F_2 ( V_5 ) ;
void T_2 * V_6 ;
unsigned long V_7 ;
int V_8 ;
T_1 V_9 ;
if ( ! V_2 )
return - V_10 ;
V_8 = ( V_2 -> V_11 == - 1 ) ? 0 : V_2 -> V_11 ;
if ( V_8 != 0 && V_8 != 1 )
return - V_10 ;
V_6 = F_3 ( V_8 ) ;
F_4 ( & V_5 , V_7 ) ;
V_9 = F_5 ( V_6 ) ;
V_9 = V_3 ? ( V_9 | V_4 ) : ( V_9 & ~ V_4 ) ;
F_6 ( V_9 , V_6 ) ;
if ( V_3 ) {
V_9 |= V_12 ;
} else if ( ! ( V_9 & ( V_13 |
V_14 ) & ~ V_4 ) ) {
V_9 &= ~ V_12 ;
}
F_6 ( V_9 , V_6 ) ;
F_7 ( & V_5 , V_7 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 , bool V_3 )
{
return F_1 ( V_2 , V_3 , V_13 ) ;
}
int F_9 ( struct V_1 * V_2 , bool V_3 )
{
return F_1 ( V_2 , V_3 , V_14 ) ;
}
