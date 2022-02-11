static int F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
if ( ! V_1 -> V_3 )
return 0 ;
V_2 = F_2 ( V_1 -> V_3 ) ;
V_2 |= 1 << V_1 -> V_4 ;
F_3 ( V_2 , V_1 -> V_3 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
if ( ! V_1 -> V_3 )
return;
V_2 = F_2 ( V_1 -> V_3 ) ;
V_2 &= ~ ( 1 << V_1 -> V_4 ) ;
F_3 ( V_2 , V_1 -> V_3 ) ;
}
static int F_5 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_2 ( V_5 ) ;
V_2 |= V_6 ;
F_3 ( V_2 , V_5 ) ;
while ( ! ( F_2 ( V_7 ) & V_8 ) ) ;
return 0 ;
}
static void F_6 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
V_2 = F_2 ( V_5 ) ;
V_2 &= ~ V_6 ;
F_3 ( V_2 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_1 , struct V_1 * V_9 )
{
int V_10 = F_2 ( V_5 ) ;
if ( V_1 -> V_9 == V_9 )
return 0 ;
if ( F_8 () >= V_11 ) {
if ( V_9 == & V_12 ) {
V_10 |= V_13 ;
} else {
if ( V_9 == & V_14 )
V_10 &= ~ V_13 ;
else
return - V_15 ;
}
F_3 ( V_10 , V_5 ) ;
V_1 -> V_9 = V_9 ;
return 0 ;
}
return - V_16 ;
}
static unsigned long F_9 ( struct V_1 * V_1 , unsigned long V_17 )
{
int div ;
unsigned long V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
div = V_18 / V_17 ;
if ( V_18 % V_17 )
div ++ ;
if ( div > 4 )
div = 4 ;
return V_18 / div ;
}
static int F_11 ( struct V_1 * V_1 , unsigned long V_17 )
{
unsigned int div ;
T_1 V_2 ;
unsigned long V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
div = V_18 / V_17 ;
if ( div > 4 || div < 1 || ( ( V_18 / div ) != V_17 ) )
return - V_15 ;
div -- ;
V_2 = F_2 ( V_5 ) ;
if ( F_8 () >= V_11 ) {
V_2 &= ~ ( 3 << 12 ) ;
V_2 |= div << 12 ;
V_2 &= ~ ( V_19 | V_6 ) ;
F_3 ( V_2 | V_20 , V_5 ) ;
} else {
F_12 ( V_21 L_1 ) ;
}
return 0 ;
}
static unsigned long F_13 ( struct V_1 * V_1 , unsigned long V_17 )
{
T_2 div ;
unsigned long V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
div = V_18 / V_17 ;
if ( V_18 % V_17 )
div ++ ;
if ( div > 64 )
div = 64 ;
return V_18 / div ;
}
static int F_14 ( struct V_1 * V_1 , unsigned long V_17 )
{
T_2 V_2 ;
T_2 div ;
unsigned long V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
if ( V_1 -> V_22 < 0 || V_1 -> V_22 > 3 )
return - V_15 ;
div = V_18 / V_17 ;
if ( div > 64 || div < 1 || ( ( V_18 / div ) != V_17 ) )
return - V_15 ;
div -- ;
V_2 = F_2 ( V_23 ) & ~ ( 0x3f << ( V_1 -> V_22 << 3 ) ) ;
V_2 |= div << ( V_1 -> V_22 << 3 ) ;
F_3 ( V_2 , V_23 ) ;
return 0 ;
}
static unsigned long F_15 ( struct V_1 * V_1 )
{
unsigned long V_24 ;
unsigned long V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
V_24 = ( F_2 ( V_5 ) >> 28 ) & 0x7 ;
return V_18 / ( V_24 + 1U ) ;
}
static unsigned long F_16 ( struct V_1 * V_1 , unsigned long V_25 )
{
unsigned long V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
if ( F_8 () >= V_11 )
V_25 += 4 ;
else
V_25 = ( V_25 < 2 ) ? 124UL : V_25 ;
return 2UL * V_18 / V_25 ;
}
static unsigned long F_17 ( struct V_1 * V_1 )
{
return F_16 ( V_1 , ( F_2 ( V_26 ) >> 16 ) & 0x3f ) ;
}
static unsigned long F_18 ( struct V_1 * V_1 )
{
return F_16 ( V_1 , ( F_2 ( V_26 ) >> 26 ) & 0x3f ) ;
}
static unsigned long F_19 ( struct V_1 * V_1 )
{
unsigned long V_27 ;
unsigned long V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
if ( F_8 () >= V_11 )
V_27 = ( F_2 ( V_26 ) >> 6 ) & 0xf ;
else
V_27 = ( F_2 ( V_26 ) >> 12 ) & 0xf ;
return V_18 / ( V_27 + 1 ) ;
}
static unsigned long F_20 ( struct V_1 * V_1 )
{
unsigned long V_28 ;
unsigned long V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
if ( F_8 () >= V_11 ) {
V_28 = ( F_2 ( V_26 ) >> 10 ) & 0x3f ;
V_28 += 4 ;
} else {
V_28 = ( F_2 ( V_26 ) >> 8 ) & 0xf ;
V_28 = ( V_28 < 2 ) ? 124 : V_28 ;
}
return 2UL * V_18 / V_28 ;
}
static unsigned long F_21 ( struct V_1 * V_1 , unsigned long V_17 )
{
return V_1 -> V_9 -> V_29 ( V_1 -> V_9 , V_17 ) ;
}
static unsigned long F_22 ( struct V_1 * V_1 )
{
return F_10 ( V_1 -> V_9 ) ;
}
static int F_23 ( struct V_1 * V_1 , unsigned long V_17 )
{
return V_1 -> V_9 -> V_30 ( V_1 -> V_9 , V_17 ) ;
}
static unsigned long F_24 ( struct V_1 * V_1 )
{
return V_31 ;
}
static unsigned long F_25 ( struct V_1 * V_1 )
{
return V_32 ;
}
static unsigned long F_26 ( struct V_1 * V_1 )
{
return F_10 ( V_1 -> V_9 ) * 1024 ;
}
static unsigned long F_27 ( struct V_1 * V_1 )
{
return F_28 ( F_2 ( V_33 ) ,
F_10 ( V_1 -> V_9 ) ) ;
}
static unsigned long F_29 ( struct V_1 * V_1 )
{
unsigned long V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
if ( F_8 () >= V_11 && V_1 -> V_22 == 1 )
return 2UL * V_18 / 3UL ;
return V_18 ;
}
static unsigned long F_30 ( struct V_1 * V_1 )
{
T_1 V_2 ;
unsigned long V_17 ;
V_17 = F_10 ( V_1 -> V_9 ) ;
V_2 = F_2 ( V_34 ) ;
if ( F_8 () >= V_11 )
F_3 ( V_2 , V_34 ) ;
return F_28 ( V_2 , V_17 ) ;
}
static unsigned long F_31 ( struct V_1 * V_1 )
{
T_2 div ;
unsigned long V_17 ;
if ( F_8 () >= V_11 )
div = ( F_2 ( V_5 ) >> 12 ) & 0x3 ;
else
div = ( F_2 ( V_5 ) >> 13 ) & 0x7 ;
V_17 = F_10 ( V_1 -> V_9 ) ;
return V_17 / ( div + 1 ) ;
}
static unsigned long F_32 ( struct V_1 * V_1 )
{
unsigned long V_17 , V_35 ;
if ( F_8 () >= V_11 )
V_35 = ( F_2 ( V_5 ) >> 8 ) & 0x3 ;
else
V_35 = ( F_2 ( V_5 ) >> 9 ) & 0xf ;
V_17 = F_10 ( V_1 -> V_9 ) ;
return V_17 / ( V_35 + 1 ) ;
}
static unsigned long F_33 ( struct V_1 * V_1 )
{
unsigned long V_17 , V_36 ;
if ( F_8 () >= V_11 )
return F_10 ( V_1 -> V_9 ) ;
else
V_36 = ( F_2 ( V_5 ) >> 8 ) & 1 ;
V_17 = F_10 ( V_1 -> V_9 ) ;
return V_17 / ( V_36 + 1 ) ;
}
static unsigned long F_34 ( struct V_1 * V_1 )
{
unsigned long V_37 , V_18 ;
V_18 = F_10 ( V_1 -> V_9 ) ;
if ( V_1 -> V_22 < 0 || V_1 -> V_22 > 3 )
return 0 ;
V_37 = ( F_2 ( V_23 ) >> ( V_1 -> V_22 << 3 ) ) & 0x3f ;
return V_18 / ( V_37 + 1 ) ;
}
static void T_3 F_35 ( void )
{
unsigned long V_10 = F_2 ( V_5 ) ;
if ( F_8 () >= V_11 ) {
if ( V_10 & V_13 )
V_38 . V_9 = & V_12 ;
if ( ! ( V_10 & V_39 ) )
V_40 . V_9 = & V_41 ;
if ( ! ( V_10 & V_42 ) )
V_40 . V_9 = & V_41 ;
if ( ! ( V_10 & V_43 ) )
V_44 . V_9 = & V_41 ;
} else {
V_38 . V_9 = & V_45 ;
V_38 . V_46 = NULL ;
V_38 . V_29 = NULL ;
V_38 . V_30 = NULL ;
V_47 . V_9 = & V_45 ;
V_48 . V_9 = & V_45 ;
V_49 . V_9 = & V_45 ;
V_50 . V_9 = & V_45 ;
V_51 . V_9 = & V_45 ;
V_40 . V_9 = & V_45 ;
V_52 . V_9 = & V_45 ;
V_44 . V_9 = & V_45 ;
}
}
int T_3 F_36 ( unsigned long V_53 )
{
T_2 V_10 = F_2 ( V_5 ) ;
V_31 = V_53 ;
if ( V_10 & V_54 )
V_45 . V_9 = & V_55 ;
else
V_45 . V_9 = & V_56 ;
if ( V_10 & V_57 )
V_41 . V_9 = & V_55 ;
else
V_41 . V_9 = & V_56 ;
F_35 () ;
F_37 ( V_58 , F_38 ( V_58 ) ) ;
F_3 ( 0 , V_59 ) ;
F_3 ( ( 1 << 10 ) | ( 1 << 19 ) , V_60 ) ;
V_41 . V_61 ( & V_41 ) ;
F_39 ( & V_48 ) ;
F_39 ( & V_62 ) ;
F_39 ( & V_63 ) ;
F_39 ( & V_64 ) ;
#if F_40 ( V_65 ) && ! F_40 ( V_66 )
F_39 ( & V_67 ) ;
#endif
F_41 ( & V_68 , F_42 ( V_69 ) ,
V_70 ) ;
return 0 ;
}
