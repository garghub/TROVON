static int F_1 ( struct V_1 * V_1 , int V_2 )
{
unsigned long V_3 = F_2 ( V_4 ) ;
if ( V_2 )
V_3 |= V_1 -> V_5 ;
else
V_3 &= ~ V_1 -> V_5 ;
F_3 ( V_3 , V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , struct V_1 * V_6 )
{
unsigned long V_3 ;
unsigned int V_7 ;
if ( V_6 == & V_8 )
V_7 = 1 ;
else if ( V_6 == & V_9 )
V_7 = 0 ;
else
return - V_10 ;
V_1 -> V_6 = V_6 ;
V_3 = F_2 ( V_4 ) ;
if ( V_1 -> V_5 == V_11 ) {
if ( V_7 )
V_3 |= V_12 ;
else
V_3 &= ~ V_12 ;
} else {
if ( V_7 )
V_3 |= V_13 ;
else
V_3 &= ~ V_13 ;
}
F_3 ( V_3 , V_4 ) ;
return 0 ;
}
static unsigned long F_5 ( struct V_1 * V_1 , unsigned long V_14 )
{
unsigned long div ;
if ( ( V_14 == 0 ) || ! V_1 -> V_6 )
return 0 ;
div = F_6 ( V_1 -> V_6 ) / V_14 ;
if ( div < 2 )
div = 2 ;
else if ( div > 16 )
div = 16 ;
return div ;
}
static unsigned long F_7 ( struct V_1 * V_1 ,
unsigned long V_14 )
{
unsigned long div = F_5 ( V_1 , V_14 ) ;
if ( div == 0 )
return 0 ;
return F_6 ( V_1 -> V_6 ) / div ;
}
static int F_8 ( struct V_1 * V_1 , unsigned long V_14 )
{
unsigned long V_15 , V_16 , div = F_5 ( V_1 , V_14 ) ;
if ( div == 0 )
return - V_10 ;
if ( V_1 == & V_17 ) {
V_15 = V_18 |
V_19 ;
V_16 = F_9 ( div ) |
F_10 ( ( div + 1 ) / 2 ) ;
} else if ( V_1 == & V_20 ) {
V_15 = V_21 |
V_22 ;
V_16 = F_11 ( div ) |
F_12 ( ( div + 1 ) / 2 ) ;
} else
return - V_10 ;
V_1 -> V_14 = F_6 ( V_1 -> V_6 ) / div ;
F_3 ( ( ( F_2 ( V_4 ) & ~ V_15 ) | V_16 ) ,
V_4 ) ;
return V_1 -> V_14 ;
}
static int F_13 ( struct V_1 * V_1 , struct V_1 * V_6 )
{
unsigned long V_15 ;
unsigned long V_23 ;
if ( V_6 == & V_24 )
V_23 = V_25 ;
else if ( V_6 == & V_8 )
V_23 = V_26 ;
else if ( V_6 == & V_27 )
V_23 = V_28 ;
else if ( V_6 == & V_29 )
V_23 = V_30 ;
else if ( V_6 == & V_9 )
V_23 = V_31 ;
else if ( V_1 == & V_32 && V_6 == & V_17 )
V_23 = V_33 ;
else if ( V_1 == & V_34 && V_6 == & V_20 )
V_23 = V_33 ;
else
return - V_10 ;
V_1 -> V_6 = V_6 ;
if ( V_1 == & V_32 )
V_15 = V_35 ;
else {
V_23 <<= 4 ;
V_15 = V_36 ;
}
F_14 ( V_15 , V_23 ) ;
return 0 ;
}
