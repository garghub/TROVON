static int F_1 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_1 -> V_3 ) ;
V_2 |= 1 << V_1 -> V_4 ;
F_3 ( V_2 , V_1 -> V_3 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_1 -> V_3 ) ;
V_2 &= ~ ( 1 << V_1 -> V_4 ) ;
F_3 ( V_2 , V_1 -> V_3 ) ;
}
static unsigned long F_5 ( struct V_1 * V_1 ,
unsigned long V_5 ,
T_1 V_6 )
{
T_1 div ;
unsigned long V_7 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
div = V_7 / V_5 ;
if ( V_7 % V_5 )
div ++ ;
if ( div > V_6 )
div = V_6 ;
return V_7 / div ;
}
static int F_7 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_9 ) ;
V_2 |= V_10 ;
F_3 ( V_2 , V_9 ) ;
while ( ( F_2 ( V_11 ) & V_12 ) == 0 )
;
return 0 ;
}
static void F_8 ( struct V_1 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_9 ) ;
V_2 &= ~ V_10 ;
F_3 ( V_2 , V_9 ) ;
}
static unsigned long F_9 ( struct V_1 * V_1 ,
unsigned long V_5 )
{
return F_5 ( V_1 , V_5 , 64 ) ;
}
static int F_10 ( struct V_1 * V_1 , unsigned long V_5 )
{
T_1 V_2 ;
T_1 div ;
unsigned long V_7 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
if ( V_1 -> V_13 < 0 || V_1 -> V_13 > 3 )
return - V_14 ;
div = V_7 / V_5 ;
if ( div > 64 || div < 1 || ( ( V_7 / div ) != V_5 ) )
return - V_14 ;
div -- ;
V_2 =
F_2 ( V_15 ) & ~ ( V_16 <<
( V_1 -> V_13 << 3 ) ) ;
V_2 |= div << ( V_1 -> V_13 << 3 ) ;
F_3 ( V_2 , V_15 ) ;
return 0 ;
}
static unsigned long F_11 ( struct V_1 * V_1 )
{
unsigned long V_17 ;
unsigned long V_7 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
V_17 = ( F_12 () & V_18 ) >> V_19 ;
return V_7 / ( V_17 + 1U ) ;
}
static unsigned long F_13 ( struct V_1 * V_1 ,
unsigned long V_5 )
{
return F_5 ( V_1 , V_5 , 8 ) ;
}
static int F_14 ( struct V_1 * V_1 , unsigned long V_5 )
{
T_1 V_2 ;
T_1 div ;
unsigned long V_7 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
div = V_7 / V_5 ;
if ( div > 8 || div < 1 || ( ( V_7 / div ) != V_5 ) )
return - V_14 ;
div -- ;
V_2 = F_12 () & ~ V_18 ;
V_2 |= div << V_19 ;
F_3 ( V_2 , V_9 ) ;
return 0 ;
}
static unsigned long F_15 ( struct V_1 * V_1 , unsigned long V_20 )
{
unsigned long V_7 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
V_20 = ( V_20 < 2 ) ? 124UL : V_20 ;
return 2UL * V_7 / V_20 ;
}
static unsigned long F_16 ( struct V_1 * V_1 )
{
return F_15 ( V_1 ,
( F_17 () & V_21 )
>> V_22 ) ;
}
static unsigned long F_18 ( struct V_1 * V_1 )
{
return F_15 ( V_1 ,
( F_17 () & V_23 ) >>
V_24 ) ;
}
static unsigned long F_19 ( struct V_1 * V_1 )
{
unsigned long V_25 ;
unsigned long V_7 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
V_25 = ( F_17 () & V_26 )
>> V_27 ;
return V_7 / ( V_25 + 1 ) ;
}
static unsigned long F_20 ( struct V_1 * V_1 , unsigned long V_5 )
{
return V_1 -> V_8 -> V_28 ( V_1 -> V_8 , V_5 ) ;
}
static int F_21 ( struct V_1 * V_1 , unsigned long V_5 )
{
return V_1 -> V_8 -> V_29 ( V_1 -> V_8 , V_5 ) ;
}
static unsigned long F_22 ( struct V_1 * V_1 )
{
return V_30 ;
}
static unsigned long F_23 ( struct V_1 * V_1 )
{
return V_31 ;
}
static unsigned long F_24 ( struct V_1 * V_1 )
{
return F_6 ( V_1 -> V_8 ) * 512 ;
}
static unsigned long F_25 ( struct V_1 * V_1 )
{
T_2 V_2 ;
unsigned long V_32 ;
unsigned long V_33 = 0 , V_34 = 0 , V_35 = 0 , V_20 = 0 ;
unsigned long long V_36 ;
V_32 = F_6 ( V_1 -> V_8 ) ;
V_2 = F_2 ( V_37 ) ;
V_20 = ( V_2 & V_38 ) >> V_39 ;
V_35 = ( V_2 & V_40 ) >> V_41 ;
V_33 = ( V_2 & V_42 ) >> V_43 ;
V_34 = ( V_2 & V_44 ) >> V_45 ;
V_33 = ( V_33 <= 5 ) ? 5 : V_33 ;
V_36 = 2LL * V_32 * V_34 ;
F_26 ( V_36 , V_35 + 1 ) ;
V_36 = 2LL * V_32 * V_33 + V_36 ;
F_26 ( V_36 , V_20 + 1 ) ;
return ( unsigned long ) V_36 ;
}
static unsigned long F_27 ( struct V_1 * V_1 )
{
unsigned long V_7 ;
T_1 div ;
div = ( F_12 () & V_46 ) >> V_47 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
return V_7 / ( div + 1 ) ;
}
static unsigned long F_28 ( struct V_1 * V_1 )
{
T_2 V_2 ;
unsigned long V_32 ;
unsigned long V_33 = 0 , V_34 = 0 , V_35 = 0 , V_20 = 0 ;
unsigned long long V_36 ;
V_32 = F_6 ( V_1 -> V_8 ) ;
V_2 = F_2 ( V_48 ) ;
V_20 = ( V_2 & V_49 ) >> V_50 ;
V_35 = ( V_2 & V_51 ) >> V_52 ;
V_33 = ( V_2 & V_53 ) >> V_54 ;
V_34 = ( V_2 & V_55 ) >> V_56 ;
V_33 = ( V_33 <= 5 ) ? 5 : V_33 ;
V_36 = 2LL * V_32 * V_34 ;
F_26 ( V_36 , V_35 + 1 ) ;
V_36 = 2LL * V_32 * V_33 + V_36 ;
F_26 ( V_36 , V_20 + 1 ) ;
return ( unsigned long ) V_36 ;
}
static unsigned long F_29 ( struct V_1 * V_1 )
{
unsigned long V_5 ;
unsigned long V_57 ;
V_57 = ( F_12 () & V_58 )
>> V_59 ;
V_5 = F_6 ( V_1 -> V_8 ) ;
return V_5 / ( V_57 + 1 ) ;
}
static unsigned long F_30 ( struct V_1 * V_1 )
{
unsigned long V_5 ;
unsigned long V_60 ;
V_60 = ( F_12 () & V_61 ) >> V_62 ;
V_5 = F_6 ( V_1 -> V_8 ) ;
return V_5 / ( V_60 + 1 ) ;
}
static unsigned long F_31 ( struct V_1 * V_1 )
{
unsigned long V_63 ;
unsigned long V_7 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
if ( V_1 -> V_13 < 0 || V_1 -> V_13 > 3 )
return 0 ;
V_63 = ( F_32 () >> ( V_1 -> V_13 << 3 ) ) & V_16 ;
return V_7 / ( V_63 + 1 ) ;
}
static unsigned long F_33 ( struct V_1 * V_1 , unsigned long V_5 )
{
return F_5 ( V_1 , V_5 , 8 ) ;
}
static int F_34 ( struct V_1 * V_1 , unsigned long V_5 )
{
T_1 V_2 ;
T_1 div ;
unsigned long V_7 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
div = V_7 / V_5 ;
if ( div > 8 || div < 1 || ( ( V_7 / div ) != V_5 ) )
return - V_14 ;
div -- ;
V_2 = F_2 ( V_64 ) ;
if ( V_1 -> V_8 == & V_65 [ 0 ] ) {
V_2 &= ~ V_66 ;
V_2 |= div << V_67 ;
}
F_3 ( V_2 , V_64 ) ;
return 0 ;
}
static unsigned long F_35 ( struct V_1 * V_1 )
{
T_1 div = 0 ;
unsigned long V_7 ;
V_7 = F_6 ( V_1 -> V_8 ) ;
if ( V_1 -> V_8 == & V_65 [ 0 ] )
div = F_2 ( V_64 ) & V_66
>> V_67 ;
div ++ ;
return V_7 / div ;
}
static int F_36 ( struct V_1 * V_1 , struct V_1 * V_8 )
{
T_1 V_2 ;
V_2 = F_2 ( V_68 ) & ~ V_69 ;
if ( V_8 == & V_70 )
V_2 |= 0 << V_71 ;
else if ( V_8 == & V_72 )
V_2 |= 1 << V_71 ;
else if ( V_8 == & V_73 )
V_2 |= 2 << V_71 ;
else if ( V_8 == V_74 . V_8 )
V_2 |= 3 << V_71 ;
else if ( V_8 == V_75 . V_8 )
V_2 |= 4 << V_71 ;
else if ( V_8 == & V_74 )
V_2 |= 5 << V_71 ;
else if ( V_8 == & V_75 )
V_2 |= 6 << V_71 ;
else if ( V_8 == & V_76 )
V_2 |= 7 << V_71 ;
else if ( V_8 == & V_77 )
V_2 |= 8 << V_71 ;
else if ( V_8 == & V_78 )
V_2 |= 9 << V_71 ;
else if ( V_8 == & V_79 [ 0 ] )
V_2 |= 0xA << V_71 ;
else if ( V_8 == & V_79 [ 1 ] )
V_2 |= 0xB << V_71 ;
else if ( V_8 == & V_79 [ 2 ] )
V_2 |= 0xC << V_71 ;
else if ( V_8 == & V_79 [ 3 ] )
V_2 |= 0xD << V_71 ;
else if ( V_8 == & V_80 [ 0 ] )
V_2 |= 0xE << V_71 ;
else if ( V_8 == & V_80 [ 1 ] )
V_2 |= 0xF << V_71 ;
else if ( V_8 == & V_81 )
V_2 |= 0x10 << V_71 ;
else if ( V_8 == & V_65 [ 0 ] )
V_2 |= 0x14 << V_71 ;
else if ( V_8 == & V_82 )
V_2 |= 0x15 << V_71 ;
else
return - V_14 ;
F_3 ( V_2 , V_68 ) ;
return 0 ;
}
int T_3 F_37 ( unsigned long V_83 , unsigned long V_84 )
{
T_1 V_85 ;
V_31 = V_83 ;
V_30 = V_84 ;
V_85 = F_12 () ;
if ( V_85 & V_86 )
V_74 . V_8 = & V_73 ;
else
V_74 . V_8 = & V_72 ;
if ( V_85 & V_87 )
V_75 . V_8 = & V_73 ;
else
V_75 . V_8 = & V_72 ;
F_38 ( V_88 , F_39 ( V_88 ) ) ;
F_3 ( 0 , V_89 ) ;
F_3 ( V_90 , V_91 ) ;
V_75 . V_92 ( & V_75 ) ;
F_40 ( & V_79 [ 0 ] ) ;
F_40 ( & V_93 ) ;
#if F_41 ( V_94 ) && ! F_41 ( V_95 )
F_40 ( & V_96 [ 0 ] ) ;
#endif
F_42 ( & V_97 [ 0 ] , F_43 ( V_98 ) ,
V_99 ) ;
return 0 ;
}
