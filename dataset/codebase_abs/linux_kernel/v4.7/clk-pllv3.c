static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + F_2 ( 10 ) ;
T_1 V_5 = F_3 ( V_2 -> V_6 ) & V_2 -> V_7 ;
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
V_5 |= V_13 ;
else
V_5 &= ~ V_13 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
if ( V_2 -> V_8 )
V_5 &= ~ V_13 ;
else
V_5 |= V_13 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
if ( F_3 ( V_2 -> V_6 ) & V_9 )
return 1 ;
return 0 ;
}
static unsigned long F_11 ( struct V_11 * V_12 ,
unsigned long V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 div = ( F_3 ( V_2 -> V_6 ) >> V_2 -> V_15 ) & V_2 -> V_16 ;
return ( div == 1 ) ? V_14 * 22 : V_14 * 20 ;
}
static long F_12 ( struct V_11 * V_12 , unsigned long V_17 ,
unsigned long * V_18 )
{
unsigned long V_14 = * V_18 ;
return ( V_17 >= V_14 * 22 ) ? V_14 * 22 :
V_14 * 20 ;
}
static int F_13 ( struct V_11 * V_12 , unsigned long V_17 ,
unsigned long V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 , div ;
if ( V_17 == V_14 * 22 )
div = 1 ;
else if ( V_17 == V_14 * 20 )
div = 0 ;
else
return - V_19 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ ( V_2 -> V_16 << V_2 -> V_15 ) ;
V_5 |= ( div << V_2 -> V_15 ) ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_14 ( struct V_11 * V_12 ,
unsigned long V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_16 ;
return V_14 * div / 2 ;
}
static long F_15 ( struct V_11 * V_12 , unsigned long V_17 ,
unsigned long * V_18 )
{
unsigned long V_14 = * V_18 ;
unsigned long V_20 = V_14 * 54 / 2 ;
unsigned long V_21 = V_14 * 108 / 2 ;
T_1 div ;
if ( V_17 > V_21 )
V_17 = V_21 ;
else if ( V_17 < V_20 )
V_17 = V_20 ;
div = V_17 * 2 / V_14 ;
return V_14 * div / 2 ;
}
static int F_16 ( struct V_11 * V_12 , unsigned long V_17 ,
unsigned long V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned long V_20 = V_14 * 54 / 2 ;
unsigned long V_21 = V_14 * 108 / 2 ;
T_1 V_5 , div ;
if ( V_17 < V_20 || V_17 > V_21 )
return - V_19 ;
div = V_17 * 2 / V_14 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_16 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_17 ( struct V_11 * V_12 ,
unsigned long V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_22 = F_3 ( V_2 -> V_6 + V_23 ) ;
T_1 V_24 = F_3 ( V_2 -> V_6 + V_25 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_16 ;
return ( V_14 * div ) + ( ( V_14 / V_24 ) * V_22 ) ;
}
static long F_18 ( struct V_11 * V_12 , unsigned long V_17 ,
unsigned long * V_18 )
{
unsigned long V_14 = * V_18 ;
unsigned long V_20 = V_14 * 27 ;
unsigned long V_21 = V_14 * 54 ;
T_1 div ;
T_1 V_22 , V_24 = 1000000 ;
T_2 V_26 ;
if ( V_17 > V_21 )
V_17 = V_21 ;
else if ( V_17 < V_20 )
V_17 = V_20 ;
div = V_17 / V_14 ;
V_26 = ( T_2 ) ( V_17 - div * V_14 ) ;
V_26 *= V_24 ;
F_19 ( V_26 , V_14 ) ;
V_22 = V_26 ;
return V_14 * div + V_14 / V_24 * V_22 ;
}
static int F_20 ( struct V_11 * V_12 , unsigned long V_17 ,
unsigned long V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned long V_20 = V_14 * 27 ;
unsigned long V_21 = V_14 * 54 ;
T_1 V_5 , div ;
T_1 V_22 , V_24 = 1000000 ;
T_2 V_26 ;
if ( V_17 < V_20 || V_17 > V_21 )
return - V_19 ;
div = V_17 / V_14 ;
V_26 = ( T_2 ) ( V_17 - div * V_14 ) ;
V_26 *= V_24 ;
F_19 ( V_26 , V_14 ) ;
V_22 = V_26 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_16 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
F_8 ( V_22 , V_2 -> V_6 + V_23 ) ;
F_8 ( V_24 , V_2 -> V_6 + V_25 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_21 ( struct V_11 * V_12 ,
unsigned long V_14 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
return V_2 -> V_27 ;
}
struct V_28 * F_22 ( enum V_29 type , const char * V_30 ,
const char * V_31 , void T_3 * V_6 ,
T_1 V_16 )
{
struct V_1 * V_2 ;
const struct V_32 * V_33 ;
struct V_28 * V_28 ;
struct V_34 V_35 ;
V_2 = F_23 ( sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return F_24 ( - V_37 ) ;
V_2 -> V_7 = V_13 ;
switch ( type ) {
case V_38 :
V_33 = & V_39 ;
break;
case V_40 :
V_2 -> V_15 = 1 ;
case V_41 :
V_33 = & V_42 ;
V_2 -> V_8 = true ;
break;
case V_43 :
V_33 = & V_44 ;
break;
case V_45 :
V_2 -> V_7 = V_46 ;
V_2 -> V_27 = 1000000000 ;
V_33 = & V_47 ;
break;
case V_48 :
V_2 -> V_27 = 500000000 ;
V_33 = & V_47 ;
break;
default:
V_33 = & V_42 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_16 = V_16 ;
V_35 . V_30 = V_30 ;
V_35 . V_33 = V_33 ;
V_35 . V_49 = 0 ;
V_35 . V_50 = & V_31 ;
V_35 . V_51 = 1 ;
V_2 -> V_12 . V_35 = & V_35 ;
V_28 = F_25 ( NULL , & V_2 -> V_12 ) ;
if ( F_26 ( V_28 ) )
F_27 ( V_2 ) ;
return V_28 ;
}
