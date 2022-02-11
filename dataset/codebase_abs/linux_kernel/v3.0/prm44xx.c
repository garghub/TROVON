T_1 F_1 ( T_2 V_1 , T_3 V_2 )
{
return F_2 ( F_3 ( V_1 , V_2 ) ) ;
}
void F_4 ( T_1 V_3 , T_2 V_1 , T_3 V_2 )
{
F_5 ( V_3 , F_3 ( V_1 , V_2 ) ) ;
}
T_1 F_6 ( T_1 V_4 , T_1 V_5 , T_2 V_1 , T_2 V_2 )
{
T_1 V_6 ;
V_6 = F_1 ( V_1 , V_2 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 ;
F_4 ( V_6 , V_1 , V_2 ) ;
return V_6 ;
}
T_1 F_7 ( void T_4 * V_2 , T_1 V_4 )
{
T_1 V_6 ;
V_6 = F_2 ( V_2 ) ;
V_6 &= V_4 ;
V_6 >>= F_8 ( V_4 ) ;
return V_6 ;
}
T_1 F_9 ( T_1 V_4 , T_1 V_5 , void T_4 * V_2 )
{
T_1 V_6 ;
V_6 = F_2 ( V_2 ) ;
V_6 &= ~ V_4 ;
V_6 |= V_5 ;
F_5 ( V_6 , V_2 ) ;
return V_6 ;
}
T_1 F_10 ( T_1 V_5 , T_2 V_1 , T_2 V_2 )
{
return F_6 ( V_5 , V_5 , V_1 , V_2 ) ;
}
T_1 F_11 ( T_1 V_5 , T_2 V_1 , T_2 V_2 )
{
return F_6 ( V_5 , 0x0 , V_1 , V_2 ) ;
}
int F_12 ( void T_4 * V_7 , T_5 V_8 )
{
if ( ! F_13 () || ! V_7 )
return - V_9 ;
return F_7 ( V_7 , ( 1 << V_8 ) ) ;
}
int F_14 ( void T_4 * V_7 , T_5 V_8 )
{
T_1 V_4 ;
if ( ! F_13 () || ! V_7 )
return - V_9 ;
V_4 = 1 << V_8 ;
F_9 ( V_4 , V_4 , V_7 ) ;
return 0 ;
}
int F_15 ( void T_4 * V_7 , T_5 V_8 )
{
T_1 V_4 ;
void T_4 * V_10 ;
int V_11 ;
if ( ! F_13 () || ! V_7 )
return - V_9 ;
V_10 = V_7 + V_12 ;
V_4 = 1 << V_8 ;
if ( F_7 ( V_7 , V_4 ) == 0 )
return - V_13 ;
F_9 ( 0xffffffff , V_4 , V_10 ) ;
F_9 ( V_4 , 0 , V_7 ) ;
F_16 ( F_7 ( V_10 , V_4 ) ,
V_14 , V_11 ) ;
return ( V_11 == V_14 ) ? - V_15 : 0 ;
}
void F_17 ( void )
{
T_1 V_6 ;
V_6 = F_1 ( V_16 ,
V_17 ) ;
V_6 |= V_18 ;
F_4 ( V_6 , V_16 ,
V_17 ) ;
V_6 = F_1 ( V_16 ,
V_17 ) ;
}
