void F_1 ( void T_1 * V_1 )
{
unsigned long V_2 ;
F_2 ( 1 , V_1 + V_3 ) ;
V_2 = F_3 ( V_1 + V_3 ) ;
while ( V_2 != 0 ) {
F_4 () ;
V_2 = F_3 ( V_1 + V_3 ) ;
}
}
void F_5 ( void T_1 * V_1 )
{
F_2 ( V_4 , V_1 + V_5 ) ;
}
void F_6 ( void T_1 * V_1 , unsigned long V_6 )
{
unsigned long V_2 , V_7 ;
V_7 = V_8 ;
if ( V_6 == V_9 )
V_7 = V_8 ;
else if ( V_6 == V_10 )
V_7 = V_11 ;
V_2 = F_3 ( V_1 + V_12 ) ;
V_2 &= ~ V_13 ;
V_2 |= V_7 ;
F_2 ( V_2 , V_1 + V_12 ) ;
}
void F_7 ( void T_1 * V_1 , unsigned long V_6 )
{
unsigned long V_2 , V_7 ;
V_7 = V_14 ;
if ( V_6 == V_15 )
V_7 = V_16 ;
else
V_7 = V_14 ;
V_2 = F_3 ( V_1 + V_17 ) ;
V_2 &= ~ V_18 ;
V_2 |= V_7 ;
F_2 ( V_2 , V_1 + V_17 ) ;
}
void F_8 ( void T_1 * V_1 , unsigned int V_6 )
{
unsigned long V_2 , V_7 ;
if ( V_6 == V_19 )
V_7 = V_20 ;
else
V_7 = V_21 ;
V_2 = F_3 ( V_1 + V_17 ) ;
V_2 &= ~ V_22 ;
V_2 |= V_7 ;
F_2 ( V_2 , V_1 + V_17 ) ;
}
unsigned int F_9 ( void T_1 * V_1 )
{
return F_3 ( V_1 + V_17 ) & V_22 ;
}
void F_10 ( void T_1 * V_1 , unsigned int V_23 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_24 ) ;
V_2 &= ~ 0xff ;
V_2 |= ( V_23 >> 8 ) & 0xff ;
F_2 ( V_2 , V_1 + V_24 ) ;
V_2 = F_3 ( V_1 + V_25 ) ;
V_2 &= ~ 0xff ;
V_2 |= V_23 & 0xff ;
F_2 ( V_2 , V_1 + V_25 ) ;
}
void F_11 ( void T_1 * V_1 , unsigned int V_26 , unsigned int V_27 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_28 ) ;
V_2 &= ~ F_12 ( V_26 ) ;
V_2 |= ( V_27 << F_13 ( V_26 ) ) & F_12 ( V_26 ) ;
F_2 ( V_2 , V_1 + V_28 ) ;
}
void F_14 ( void T_1 * V_1 , unsigned int V_26 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_29 ) ;
V_2 &= ~ F_15 ( V_26 ) ;
V_2 |= ( 0 << F_16 ( V_26 ) ) & F_15 ( V_26 ) ;
F_2 ( V_2 , V_1 + V_29 ) ;
}
void F_17 ( void T_1 * V_1 , unsigned int V_26 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_29 ) ;
V_2 &= ~ F_18 ( V_26 ) ;
V_2 |= ( 0 << F_19 ( V_26 ) ) & F_18 ( V_26 ) ;
F_2 ( V_2 , V_1 + V_29 ) ;
}
void F_20 ( void T_1 * V_1 , unsigned int V_30 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_31 ) ;
V_2 &= ~ 0xff ;
V_2 |= ( V_30 >> 8 ) & 0xff ;
F_2 ( V_2 , V_1 + V_31 ) ;
V_2 = F_3 ( V_1 + V_32 ) ;
V_2 &= ~ 0xff ;
V_2 |= V_30 & 0xff ;
F_2 ( V_2 , V_1 + V_32 ) ;
}
void F_21 ( void T_1 * V_1 , unsigned int V_33 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_34 ) ;
V_2 &= ~ 0xff ;
V_2 |= ( V_33 >> 8 ) & 0xff ;
F_2 ( V_2 , V_1 + V_34 ) ;
V_2 = F_3 ( V_1 + V_35 ) ;
V_2 &= ~ 0xff ;
V_2 |= V_33 & 0xff ;
F_2 ( V_2 , V_1 + V_35 ) ;
}
void F_22 ( void T_1 * V_1 , bool V_36 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_37 ) ;
V_2 &= ~ V_38 ;
if ( V_36 )
V_2 |= V_39 ;
F_2 ( V_2 , V_1 + V_37 ) ;
}
void F_23 ( void T_1 * V_1 , bool V_36 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_37 ) ;
V_2 &= ~ V_40 ;
if ( V_36 )
V_2 |= V_41 ;
F_2 ( V_2 , V_1 + V_37 ) ;
}
void F_24 ( void T_1 * V_1 , bool V_42 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_37 ) ;
V_2 &= ~ V_43 ;
if ( V_42 )
V_2 |= V_44 ;
F_2 ( V_2 , V_1 + V_37 ) ;
}
int F_25 ( void T_1 * V_1 )
{
return ( int ) ( ( F_3 ( V_1 + V_45 ) & V_46 )
>> V_47 ) ;
}
void F_26 ( void T_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_48 ) ;
V_2 &= ~ V_46 ;
F_2 ( V_2 , V_1 + V_48 ) ;
}
void F_27 ( void T_1 * V_1 , unsigned long V_49 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_50 ) ;
V_2 &= ~ V_51 ;
V_2 |= V_52 ;
V_2 |= V_49 & V_51 ;
F_2 ( V_2 , V_1 + V_50 ) ;
}
int F_28 ( void T_1 * V_1 )
{
return ( int ) ( F_3 ( V_1 + V_53 ) &
V_54 ) ;
}
void F_29 ( void T_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_50 ) ;
V_2 &= ~ V_55 ;
F_2 ( V_2 , V_1 + V_50 ) ;
}
void F_30 ( void T_1 * V_1 , unsigned long V_56 )
{
unsigned long V_2 , V_57 ;
V_57 = V_58 ;
if ( V_56 == V_59 )
V_57 = V_58 ;
else if ( V_56 == V_60 )
V_57 = V_61 ;
V_2 = F_3 ( V_1 + V_62 ) ;
V_2 &= ~ V_63 ;
V_2 |= V_57 ;
F_2 ( V_2 , V_1 + V_62 ) ;
}
void F_31 ( void T_1 * V_1 , unsigned long V_64 )
{
F_2 ( V_64 , V_1 + V_65 ) ;
}
void F_32 ( void T_1 * V_1 , unsigned long V_64 )
{
F_2 ( V_64 , V_1 + V_66 ) ;
}
void F_33 ( void T_1 * V_1 , unsigned int V_67 ,
unsigned int V_68 , unsigned int V_69 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + F_34 ( V_67 ) ) ;
V_2 &= ~ F_35 ( V_68 ) ;
V_2 |= ( V_69 << F_36 ( V_68 ) ) & F_35 ( V_68 ) ;
F_2 ( V_2 , V_1 + F_34 ( V_67 ) ) ;
}
void F_37 ( void T_1 * V_1 )
{
F_2 ( 1 , V_1 + V_70 ) ;
}
int F_38 ( void T_1 * V_1 )
{
return ( int ) ( ( F_3 ( V_1 + V_71 ) & V_72 )
>> V_73 ) ;
}
int F_39 ( void T_1 * V_1 )
{
return ! ( int ) ( ( F_3 ( V_1 + V_71 ) & V_74 )
>> V_75 ) ;
}
void F_40 ( void T_1 * V_1 )
{
F_3 ( V_1 + V_71 ) ;
F_2 ( V_76 , V_1 + V_77 ) ;
F_3 ( V_1 + V_78 ) ;
}
unsigned int F_41 ( void T_1 * V_1 )
{
unsigned long V_79 = 0 ;
V_79 |= ( F_3 ( V_1 + V_80 ) & 0xff ) << 16 ;
V_79 |= ( F_3 ( V_1 + V_81 ) & 0xff ) << 8 ;
V_79 |= ( F_3 ( V_1 + V_82 ) & 0xff ) ;
return ( unsigned int ) V_79 ;
}
