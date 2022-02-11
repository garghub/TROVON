static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + F_2 ( 10 ) ;
T_1 V_5 = F_3 ( V_2 -> V_6 ) & V_7 ;
if ( ( V_2 -> V_8 && ! V_5 ) || ( ! V_2 -> V_8 && V_5 ) )
return 0 ;
do {
if ( F_3 ( V_2 -> V_6 ) & V_9 )
break;
if ( F_4 ( V_4 , V_3 ) )
break;
F_5 ( 50 , 500 ) ;
} while ( 1 );
return F_3 ( V_2 -> V_6 ) & V_9 ? 0 : - V_10 ;
}
static int F_6 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
if ( V_2 -> V_8 )
V_5 |= V_7 ;
else
V_5 &= ~ V_7 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
if ( V_2 -> V_8 )
V_5 &= ~ V_7 ;
else
V_5 |= V_7 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
}
static unsigned long F_10 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 div = ( F_3 ( V_2 -> V_6 ) >> V_2 -> V_14 ) & V_2 -> V_15 ;
return ( div == 1 ) ? V_13 * 22 : V_13 * 20 ;
}
static long F_11 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long * V_17 )
{
unsigned long V_13 = * V_17 ;
return ( V_16 >= V_13 * 22 ) ? V_13 * 22 :
V_13 * 20 ;
}
static int F_12 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 , div ;
if ( V_16 == V_13 * 22 )
div = 1 ;
else if ( V_16 == V_13 * 20 )
div = 0 ;
else
return - V_18 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ ( V_2 -> V_15 << V_2 -> V_14 ) ;
V_5 |= ( div << V_2 -> V_14 ) ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_13 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_15 ;
return V_13 * div / 2 ;
}
static long F_14 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long * V_17 )
{
unsigned long V_13 = * V_17 ;
unsigned long V_19 = V_13 * 54 / 2 ;
unsigned long V_20 = V_13 * 108 / 2 ;
T_1 div ;
if ( V_16 > V_20 )
V_16 = V_20 ;
else if ( V_16 < V_19 )
V_16 = V_19 ;
div = V_16 * 2 / V_13 ;
return V_13 * div / 2 ;
}
static int F_15 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned long V_19 = V_13 * 54 / 2 ;
unsigned long V_20 = V_13 * 108 / 2 ;
T_1 V_5 , div ;
if ( V_16 < V_19 || V_16 > V_20 )
return - V_18 ;
div = V_16 * 2 / V_13 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_15 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_16 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_21 = F_3 ( V_2 -> V_6 + V_22 ) ;
T_1 V_23 = F_3 ( V_2 -> V_6 + V_24 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_15 ;
return ( V_13 * div ) + ( ( V_13 / V_23 ) * V_21 ) ;
}
static long F_17 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long * V_17 )
{
unsigned long V_13 = * V_17 ;
unsigned long V_19 = V_13 * 27 ;
unsigned long V_20 = V_13 * 54 ;
T_1 div ;
T_1 V_21 , V_23 = 1000000 ;
T_2 V_25 ;
if ( V_16 > V_20 )
V_16 = V_20 ;
else if ( V_16 < V_19 )
V_16 = V_19 ;
div = V_16 / V_13 ;
V_25 = ( V_26 ) ( V_16 - div * V_13 ) ;
V_25 *= V_23 ;
F_18 ( V_25 , V_13 ) ;
V_21 = V_25 ;
return V_13 * div + V_13 / V_23 * V_21 ;
}
static int F_19 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned long V_19 = V_13 * 27 ;
unsigned long V_20 = V_13 * 54 ;
T_1 V_5 , div ;
T_1 V_21 , V_23 = 1000000 ;
T_2 V_25 ;
if ( V_16 < V_19 || V_16 > V_20 )
return - V_18 ;
div = V_16 / V_13 ;
V_25 = ( V_26 ) ( V_16 - div * V_13 ) ;
V_25 *= V_23 ;
F_18 ( V_25 , V_13 ) ;
V_21 = V_25 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_15 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
F_8 ( V_21 , V_2 -> V_6 + V_22 ) ;
F_8 ( V_23 , V_2 -> V_6 + V_24 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_20 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
return 500000000 ;
}
struct V_27 * F_21 ( enum V_28 type , const char * V_29 ,
const char * V_30 , void T_3 * V_6 ,
T_1 V_15 )
{
struct V_1 * V_2 ;
const struct V_31 * V_32 ;
struct V_27 * V_27 ;
struct V_33 V_34 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return F_23 ( - V_36 ) ;
switch ( type ) {
case V_37 :
V_32 = & V_38 ;
break;
case V_39 :
V_2 -> V_14 = 1 ;
case V_40 :
V_32 = & V_41 ;
V_2 -> V_8 = true ;
break;
case V_42 :
V_32 = & V_43 ;
break;
case V_44 :
V_32 = & V_45 ;
break;
default:
V_32 = & V_41 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_15 = V_15 ;
V_34 . V_29 = V_29 ;
V_34 . V_32 = V_32 ;
V_34 . V_46 = 0 ;
V_34 . V_47 = & V_30 ;
V_34 . V_48 = 1 ;
V_2 -> V_12 . V_34 = & V_34 ;
V_27 = F_24 ( NULL , & V_2 -> V_12 ) ;
if ( F_25 ( V_27 ) )
F_26 ( V_2 ) ;
return V_27 ;
}
