static inline bool F_1 ( T_1 V_1 )
{
return V_1 == V_2 -> V_3 ;
}
void F_2 ( bool V_4 )
{
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_4 )
V_5 |= V_8 ;
else
V_5 &= ~ V_8 ;
F_4 ( V_5 , V_2 -> V_6 + V_7 ) ;
}
void F_5 ( T_1 V_1 , T_1 V_9 , bool V_4 )
{
T_1 V_10 , V_5 ;
if ( V_1 >= V_11 )
return;
V_10 = 1 << V_9 ;
if ( ! F_1 ( V_1 ) )
V_10 <<= 4 ;
V_5 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_4 )
V_5 |= V_10 ;
else
V_5 &= ~ V_10 ;
F_4 ( V_5 , V_2 -> V_6 + V_7 ) ;
}
void F_6 ( T_1 V_1 , T_1 V_9 , T_1 V_12 )
{
void T_2 * V_6 ;
if ( V_1 >= V_11 )
return;
if ( F_1 ( V_1 ) )
V_6 = V_2 -> V_6 + V_13 + ( V_9 << 2 ) ;
else
V_6 = V_2 -> V_6 + V_14 + ( V_9 << 2 ) ;
F_4 ( V_12 , V_6 ) ;
}
void F_7 ( T_1 V_1 , bool V_15 )
{
T_1 V_16 ;
if ( V_1 >= V_11 )
return;
V_16 = F_1 ( V_1 ) ? V_17 : V_18 ;
F_4 ( V_15 , V_2 -> V_6 + V_16 ) ;
}
int T_3 F_8 ( void T_2 * V_6 , T_1 V_3 )
{
V_2 = F_9 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 ) {
F_10 ( V_20 L_1 ) ;
return - V_21 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_3 = V_3 ;
F_11 ( V_2 ) ;
F_11 ( & V_2 ) ;
return 0 ;
}
