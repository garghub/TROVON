static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_5 = V_6 + F_3 ( 10 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_4 -> V_8 ) ;
V_7 &= ~ V_9 ;
if ( V_4 -> V_10 )
V_7 |= V_11 ;
else
V_7 &= ~ V_11 ;
F_5 ( V_7 , V_4 -> V_8 ) ;
while ( ! ( F_4 ( V_4 -> V_8 ) & V_12 ) )
if ( F_6 ( V_6 , V_5 ) )
return - V_13 ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_4 -> V_8 ) ;
V_7 |= V_9 ;
if ( V_4 -> V_10 )
V_7 &= ~ V_11 ;
else
V_7 |= V_11 ;
F_5 ( V_7 , V_4 -> V_8 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_4 -> V_8 ) ;
V_7 |= V_14 ;
F_5 ( V_7 , V_4 -> V_8 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_7 = F_4 ( V_4 -> V_8 ) ;
V_7 &= ~ V_14 ;
F_5 ( V_7 , V_4 -> V_8 ) ;
}
static unsigned long F_10 ( struct V_1 * V_2 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 div = F_4 ( V_4 -> V_8 ) & V_4 -> V_16 ;
return ( div == 1 ) ? V_15 * 22 : V_15 * 20 ;
}
static long F_11 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long * V_18 )
{
unsigned long V_15 = * V_18 ;
return ( V_17 >= V_15 * 22 ) ? V_15 * 22 :
V_15 * 20 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_7 , div ;
if ( V_17 == V_15 * 22 )
div = 1 ;
else if ( V_17 == V_15 * 20 )
div = 0 ;
else
return - V_19 ;
V_7 = F_4 ( V_4 -> V_8 ) ;
V_7 &= ~ V_4 -> V_16 ;
V_7 |= div ;
F_5 ( V_7 , V_4 -> V_8 ) ;
return 0 ;
}
static unsigned long F_13 ( struct V_1 * V_2 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 div = F_4 ( V_4 -> V_8 ) & V_4 -> V_16 ;
return V_15 * div / 2 ;
}
static long F_14 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long * V_18 )
{
unsigned long V_15 = * V_18 ;
unsigned long V_20 = V_15 * 54 / 2 ;
unsigned long V_21 = V_15 * 108 / 2 ;
T_1 div ;
if ( V_17 > V_21 )
V_17 = V_21 ;
else if ( V_17 < V_20 )
V_17 = V_20 ;
div = V_17 * 2 / V_15 ;
return V_15 * div / 2 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_20 = V_15 * 54 / 2 ;
unsigned long V_21 = V_15 * 108 / 2 ;
T_1 V_7 , div ;
if ( V_17 < V_20 || V_17 > V_21 )
return - V_19 ;
div = V_17 * 2 / V_15 ;
V_7 = F_4 ( V_4 -> V_8 ) ;
V_7 &= ~ V_4 -> V_16 ;
V_7 |= div ;
F_5 ( V_7 , V_4 -> V_8 ) ;
return 0 ;
}
static unsigned long F_16 ( struct V_1 * V_2 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_22 = F_4 ( V_4 -> V_8 + V_23 ) ;
T_1 V_24 = F_4 ( V_4 -> V_8 + V_25 ) ;
T_1 div = F_4 ( V_4 -> V_8 ) & V_4 -> V_16 ;
return ( V_15 * div ) + ( ( V_15 / V_24 ) * V_22 ) ;
}
static long F_17 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long * V_18 )
{
unsigned long V_15 = * V_18 ;
unsigned long V_20 = V_15 * 27 ;
unsigned long V_21 = V_15 * 54 ;
T_1 div ;
T_1 V_22 , V_24 = 1000000 ;
T_2 V_26 ;
if ( V_17 > V_21 )
V_17 = V_21 ;
else if ( V_17 < V_20 )
V_17 = V_20 ;
div = V_17 / V_15 ;
V_26 = ( V_27 ) ( V_17 - div * V_15 ) ;
V_26 *= V_24 ;
F_18 ( V_26 , V_15 ) ;
V_22 = V_26 ;
return V_15 * div + V_15 / V_24 * V_22 ;
}
static int F_19 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_20 = V_15 * 27 ;
unsigned long V_21 = V_15 * 54 ;
T_1 V_7 , div ;
T_1 V_22 , V_24 = 1000000 ;
T_2 V_26 ;
if ( V_17 < V_20 || V_17 > V_21 )
return - V_19 ;
div = V_17 / V_15 ;
V_26 = ( V_27 ) ( V_17 - div * V_15 ) ;
V_26 *= V_24 ;
F_18 ( V_26 , V_15 ) ;
V_22 = V_26 ;
V_7 = F_4 ( V_4 -> V_8 ) ;
V_7 &= ~ V_4 -> V_16 ;
V_7 |= div ;
F_5 ( V_7 , V_4 -> V_8 ) ;
F_5 ( V_22 , V_4 -> V_8 + V_23 ) ;
F_5 ( V_24 , V_4 -> V_8 + V_25 ) ;
return 0 ;
}
static unsigned long F_20 ( struct V_1 * V_2 ,
unsigned long V_15 )
{
return 500000000 ;
}
struct V_28 * F_21 ( enum V_29 type , const char * V_30 ,
const char * V_31 , void T_3 * V_8 ,
T_1 V_16 )
{
struct V_3 * V_4 ;
const struct V_32 * V_33 ;
struct V_28 * V_28 ;
struct V_34 V_35 ;
V_4 = F_22 ( sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 )
return F_23 ( - V_37 ) ;
switch ( type ) {
case V_38 :
V_33 = & V_39 ;
break;
case V_40 :
V_33 = & V_41 ;
V_4 -> V_10 = true ;
break;
case V_42 :
V_33 = & V_43 ;
break;
case V_44 :
V_33 = & V_45 ;
break;
default:
V_33 = & V_41 ;
}
V_4 -> V_8 = V_8 ;
V_4 -> V_16 = V_16 ;
V_35 . V_30 = V_30 ;
V_35 . V_33 = V_33 ;
V_35 . V_46 = 0 ;
V_35 . V_47 = & V_31 ;
V_35 . V_48 = 1 ;
V_4 -> V_2 . V_35 = & V_35 ;
V_28 = F_24 ( NULL , & V_4 -> V_2 ) ;
if ( F_25 ( V_28 ) )
F_26 ( V_4 ) ;
return V_28 ;
}
