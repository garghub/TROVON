static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_4 ;
unsigned long V_5 ;
int V_6 ;
T_1 V_7 ;
if ( ! V_8 )
return - V_9 ;
if ( V_3 >= F_2 ( V_10 ) )
return - V_11 ;
V_6 = 1 << V_10 [ V_3 ] ;
F_3 ( & V_12 , V_5 ) ;
V_7 = F_4 ( V_8 + V_13 ) ;
V_7 |= V_6 ;
F_5 ( V_7 , V_8 + V_13 ) ;
F_6 ( & V_12 , V_5 ) ;
V_4 = V_14 + F_7 ( 1000 ) ;
while ( F_8 ( V_8 + V_13 ) & V_6 ) {
if ( F_9 ( V_14 , V_4 ) )
return - V_15 ;
F_10 () ;
}
return 0 ;
}
void F_11 ( int V_16 , bool V_17 )
{
T_1 V_18 , V_7 ;
V_16 = F_12 ( V_16 ) ;
V_18 = 1 << ( V_19 + V_16 - 1 ) ;
F_13 ( & V_12 ) ;
V_7 = F_4 ( V_8 + V_13 ) ;
V_7 = V_17 ? V_7 | V_18 : V_7 & ~ V_18 ;
V_7 |= 1 << ( V_20 + V_16 - 1 ) ;
F_5 ( V_7 , V_8 + V_13 ) ;
F_14 ( & V_12 ) ;
}
void F_15 ( int V_16 , void * V_21 )
{
V_16 = F_12 ( V_16 ) ;
F_5 ( F_16 ( V_21 ) ,
V_8 + V_22 + V_16 * 8 ) ;
}
T_1 F_17 ( int V_16 )
{
V_16 = F_12 ( V_16 ) ;
return F_4 ( V_8 + V_22 + V_16 * 8 + 4 ) ;
}
void F_18 ( int V_16 , T_1 V_23 )
{
V_16 = F_12 ( V_16 ) ;
F_5 ( V_23 , V_8 + V_22 + V_16 * 8 + 4 ) ;
}
void T_2 F_19 ( void )
{
struct V_24 * V_25 ;
T_1 V_7 ;
V_25 = F_20 ( NULL , NULL , L_1 ) ;
if ( ! V_25 )
return;
V_8 = F_21 ( V_25 , 0 ) ;
F_22 ( ! V_8 ) ;
V_26 . V_27 = V_25 ;
if ( F_23 ( V_28 ) )
F_24 ( & V_26 ) ;
F_13 ( & V_12 ) ;
V_7 = F_4 ( V_8 + V_13 ) ;
V_7 &= ~ ( 1 << V_29 ) ;
F_5 ( V_7 , V_8 + V_13 ) ;
F_14 ( & V_12 ) ;
}
