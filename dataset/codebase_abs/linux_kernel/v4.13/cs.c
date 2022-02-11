static int F_1 ( unsigned int V_1 )
{
if ( V_1 > 6 )
return 0 ;
return 1 ;
}
int F_2 ( unsigned int V_1 , T_1 V_2 , unsigned int V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
if ( ! F_1 ( V_1 ) )
return - V_6 ;
if ( V_3 != F_3 ( V_3 ) )
return - V_6 ;
if ( V_3 < 8 * 1024 || V_3 > 256 * 1024 * 1024 )
return - V_6 ;
V_5 = ( V_2 & V_7 ) ;
V_5 |= ( F_4 ( V_3 ) - F_4 ( 8 * 1024 ) ) << V_8 ;
F_5 ( & V_9 , V_4 ) ;
F_6 ( V_5 , F_7 ( V_1 ) ) ;
F_8 ( & V_9 , V_4 ) ;
return 0 ;
}
int F_9 ( unsigned int V_1 , unsigned int V_10 ,
unsigned int V_11 , unsigned int V_12 )
{
unsigned long V_4 ;
T_1 V_5 ;
if ( ! F_1 ( V_1 ) )
return - V_6 ;
F_5 ( & V_9 , V_4 ) ;
V_5 = F_10 ( F_11 ( V_1 ) ) ;
V_5 &= ~ ( V_13 ) ;
V_5 &= ~ ( V_14 ) ;
V_5 &= ~ ( V_15 ) ;
V_5 |= V_10 << V_16 ;
V_5 |= V_11 << V_17 ;
V_5 |= V_12 << V_18 ;
F_6 ( V_5 , F_11 ( V_1 ) ) ;
F_8 ( & V_9 , V_4 ) ;
return 0 ;
}
int F_12 ( unsigned int V_1 , T_1 V_19 )
{
unsigned long V_4 ;
T_1 V_5 ;
if ( ! F_1 ( V_1 ) )
return - V_6 ;
if ( V_1 == V_20 ||
V_1 == V_21 ||
V_1 == V_22 )
return - V_6 ;
F_5 ( & V_9 , V_4 ) ;
V_5 = F_10 ( F_11 ( V_1 ) ) ;
V_5 &= ~ ( V_23 ) ;
V_5 &= ~ ( V_24 ) ;
V_5 &= ~ ( V_25 ) ;
V_5 &= ~ ( V_26 ) ;
V_5 |= V_19 ;
F_6 ( V_5 , F_11 ( V_1 ) ) ;
F_8 ( & V_9 , V_4 ) ;
return 0 ;
}
int F_13 ( unsigned int V_1 , int V_27 )
{
unsigned long V_4 ;
T_1 V_5 ;
if ( ! F_1 ( V_1 ) )
return - V_6 ;
F_5 ( & V_9 , V_4 ) ;
V_5 = F_10 ( F_11 ( V_1 ) ) ;
if ( V_27 )
V_5 |= V_28 ;
else
V_5 &= ~ V_28 ;
F_6 ( V_5 , F_11 ( V_1 ) ) ;
F_8 ( & V_9 , V_4 ) ;
return 0 ;
}
