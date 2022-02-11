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
void F_7 ( void T_1 * V_1 , bool V_14 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_12 ) ;
if ( V_14 )
V_2 |= V_15 ;
else
V_2 &= ~ V_16 ;
F_2 ( V_2 , V_1 + V_12 ) ;
}
void F_8 ( void T_1 * V_1 , unsigned long V_6 )
{
unsigned long V_2 , V_7 ;
V_7 = V_17 ;
if ( V_6 == V_18 )
V_7 = V_19 ;
else
V_7 = V_17 ;
V_2 = F_3 ( V_1 + V_20 ) ;
V_2 &= ~ V_21 ;
V_2 |= V_7 ;
F_2 ( V_2 , V_1 + V_20 ) ;
}
void F_9 ( void T_1 * V_1 , unsigned int V_6 )
{
unsigned long V_2 , V_7 ;
if ( V_6 == V_22 )
V_7 = V_23 ;
else
V_7 = V_24 ;
V_2 = F_3 ( V_1 + V_20 ) ;
V_2 &= ~ V_25 ;
V_2 |= V_7 ;
F_2 ( V_2 , V_1 + V_20 ) ;
}
unsigned int F_10 ( void T_1 * V_1 )
{
return F_3 ( V_1 + V_20 ) & V_25 ;
}
void F_11 ( void T_1 * V_1 , unsigned int V_26 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_27 ) ;
V_2 &= ~ 0xff ;
V_2 |= ( V_26 >> 8 ) & 0xff ;
F_2 ( V_2 , V_1 + V_27 ) ;
V_2 = F_3 ( V_1 + V_28 ) ;
V_2 &= ~ 0xff ;
V_2 |= V_26 & 0xff ;
F_2 ( V_2 , V_1 + V_28 ) ;
}
void F_12 ( void T_1 * V_1 , unsigned int V_29 , unsigned int V_30 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_31 ) ;
V_2 &= ~ F_13 ( V_29 ) ;
V_2 |= ( V_30 << F_14 ( V_29 ) ) & F_13 ( V_29 ) ;
F_2 ( V_2 , V_1 + V_31 ) ;
}
void F_15 ( void T_1 * V_1 , unsigned int V_29 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_32 ) ;
V_2 &= ~ F_16 ( V_29 ) ;
V_2 |= ( 0 << F_17 ( V_29 ) ) & F_16 ( V_29 ) ;
F_2 ( V_2 , V_1 + V_32 ) ;
}
void F_18 ( void T_1 * V_1 , unsigned int V_29 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_32 ) ;
V_2 &= ~ F_19 ( V_29 ) ;
V_2 |= ( 0 << F_20 ( V_29 ) ) & F_19 ( V_29 ) ;
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
void F_22 ( void T_1 * V_1 , unsigned int V_36 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_37 ) ;
V_2 &= ~ 0xff ;
V_2 |= ( V_36 >> 8 ) & 0xff ;
F_2 ( V_2 , V_1 + V_37 ) ;
V_2 = F_3 ( V_1 + V_38 ) ;
V_2 &= ~ 0xff ;
V_2 |= V_36 & 0xff ;
F_2 ( V_2 , V_1 + V_38 ) ;
}
void F_23 ( void T_1 * V_1 , bool V_39 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_40 ) ;
V_2 &= ~ V_41 ;
if ( V_39 )
V_2 |= V_42 ;
F_2 ( V_2 , V_1 + V_40 ) ;
}
void F_24 ( void T_1 * V_1 , bool V_39 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_40 ) ;
V_2 &= ~ V_43 ;
if ( V_39 )
V_2 |= V_44 ;
F_2 ( V_2 , V_1 + V_40 ) ;
}
void F_25 ( void T_1 * V_1 , bool V_45 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_40 ) ;
V_2 &= ~ V_46 ;
if ( V_45 )
V_2 |= V_47 ;
F_2 ( V_2 , V_1 + V_40 ) ;
}
void F_26 ( void T_1 * V_1 , unsigned long V_48 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_49 ) ;
V_2 |= V_50 ;
V_2 &= ~ V_51 ;
V_2 |= V_48 & V_51 ;
F_2 ( V_2 , V_1 + V_49 ) ;
}
void F_27 ( void T_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_49 ) ;
V_2 &= ~ V_52 ;
F_2 ( V_2 , V_1 + V_49 ) ;
}
int F_28 ( void T_1 * V_1 )
{
return ( int ) ( ( F_3 ( V_1 + V_53 ) & V_54 )
>> V_55 ) ;
}
void F_29 ( void T_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_49 ) ;
V_2 &= ~ V_54 ;
F_2 ( V_2 , V_1 + V_49 ) ;
}
void F_30 ( void T_1 * V_1 , unsigned long V_56 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_57 ) ;
V_2 &= ~ V_58 ;
V_2 |= V_59 ;
V_2 |= V_56 & V_58 ;
F_2 ( V_2 , V_1 + V_57 ) ;
}
int F_31 ( void T_1 * V_1 )
{
return ( int ) ( F_3 ( V_1 + V_60 ) &
V_61 ) ;
}
void F_32 ( void T_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_57 ) ;
V_2 &= ~ V_62 ;
F_2 ( V_2 , V_1 + V_57 ) ;
}
void F_33 ( void T_1 * V_1 , unsigned long V_63 )
{
unsigned long V_2 , V_64 ;
V_64 = V_65 ;
if ( V_63 == V_66 )
V_64 = V_65 ;
else if ( V_63 == V_67 )
V_64 = V_68 ;
V_2 = F_3 ( V_1 + V_69 ) ;
V_2 &= ~ V_70 ;
V_2 |= V_64 ;
F_2 ( V_2 , V_1 + V_69 ) ;
}
void F_34 ( void T_1 * V_1 , unsigned long V_71 )
{
F_2 ( V_71 , V_1 + V_72 ) ;
}
void F_35 ( void T_1 * V_1 , unsigned long V_71 )
{
F_2 ( V_71 , V_1 + V_73 ) ;
}
void F_36 ( void T_1 * V_1 , unsigned int V_74 ,
unsigned int V_75 , unsigned int V_76 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + F_37 ( V_74 ) ) ;
V_2 &= ~ F_38 ( V_75 ) ;
V_2 |= ( V_76 << F_39 ( V_75 ) ) & F_38 ( V_75 ) ;
F_2 ( V_2 , V_1 + F_37 ( V_74 ) ) ;
}
void F_40 ( void T_1 * V_1 )
{
F_2 ( 1 , V_1 + V_77 ) ;
}
int F_41 ( void T_1 * V_1 )
{
return ( int ) ( ( F_3 ( V_1 + V_78 ) & V_79 )
>> V_80 ) ;
}
int F_42 ( void T_1 * V_1 )
{
return ! ( int ) ( ( F_3 ( V_1 + V_78 ) & V_81 )
>> V_82 ) ;
}
void F_43 ( void T_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_3 ( V_1 + V_78 ) ;
F_2 ( V_83 , V_1 + V_84 ) ;
V_2 = F_3 ( V_1 + V_85 ) ;
}
unsigned int F_44 ( void T_1 * V_1 )
{
unsigned long V_86 = 0 ;
V_86 |= ( F_3 ( V_1 + V_87 ) & 0xff ) << 16 ;
V_86 |= ( F_3 ( V_1 + V_88 ) & 0xff ) << 8 ;
V_86 |= ( F_3 ( V_1 + V_89 ) & 0xff ) ;
return ( unsigned int ) V_86 ;
}
