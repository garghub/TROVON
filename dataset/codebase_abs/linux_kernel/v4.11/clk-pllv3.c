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
V_5 |= V_2 -> V_7 ;
else
V_5 &= ~ V_2 -> V_7 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
if ( V_2 -> V_8 )
V_5 &= ~ V_2 -> V_7 ;
else
V_5 |= V_2 -> V_7 ;
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
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 div = ( F_3 ( V_2 -> V_6 ) >> V_2 -> V_14 ) & V_2 -> V_15 ;
return ( div == 1 ) ? V_13 * 22 : V_13 * 20 ;
}
static long F_12 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long * V_17 )
{
unsigned long V_13 = * V_17 ;
return ( V_16 >= V_13 * 22 ) ? V_13 * 22 :
V_13 * 20 ;
}
static int F_13 ( struct V_11 * V_12 , unsigned long V_16 ,
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
static unsigned long F_14 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_15 ;
return V_13 * div / 2 ;
}
static long F_15 ( struct V_11 * V_12 , unsigned long V_16 ,
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
static int F_16 ( struct V_11 * V_12 , unsigned long V_16 ,
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
static unsigned long F_17 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_21 = F_3 ( V_2 -> V_6 + V_22 ) ;
T_1 V_23 = F_3 ( V_2 -> V_6 + V_24 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_15 ;
T_2 V_25 = ( T_2 ) V_13 ;
V_25 *= V_21 ;
F_18 ( V_25 , V_23 ) ;
return V_13 * div + ( unsigned long ) V_25 ;
}
static long F_19 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long * V_17 )
{
unsigned long V_13 = * V_17 ;
unsigned long V_19 = V_13 * 27 ;
unsigned long V_20 = V_13 * 54 ;
T_1 div ;
T_1 V_21 , V_23 = 1000000 ;
T_1 V_26 = 0x3FFFFFFF ;
T_2 V_25 ;
if ( V_16 > V_20 )
V_16 = V_20 ;
else if ( V_16 < V_19 )
V_16 = V_19 ;
if ( V_13 <= V_26 )
V_23 = V_13 ;
div = V_16 / V_13 ;
V_25 = ( T_2 ) ( V_16 - div * V_13 ) ;
V_25 *= V_23 ;
F_18 ( V_25 , V_13 ) ;
V_21 = V_25 ;
V_25 = ( T_2 ) V_13 ;
V_25 *= V_21 ;
F_18 ( V_25 , V_23 ) ;
return V_13 * div + ( unsigned long ) V_25 ;
}
static int F_20 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned long V_19 = V_13 * 27 ;
unsigned long V_20 = V_13 * 54 ;
T_1 V_5 , div ;
T_1 V_21 , V_23 = 1000000 ;
T_1 V_26 = 0x3FFFFFFF ;
T_2 V_25 ;
if ( V_16 < V_19 || V_16 > V_20 )
return - V_18 ;
if ( V_13 <= V_26 )
V_23 = V_13 ;
div = V_16 / V_13 ;
V_25 = ( T_2 ) ( V_16 - div * V_13 ) ;
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
static unsigned long F_21 ( unsigned long V_13 ,
struct V_27 V_28 )
{
T_2 V_25 ;
V_25 = V_13 ;
V_25 *= V_28 . V_21 ;
F_18 ( V_25 , V_28 . V_23 ) ;
return ( V_13 * V_28 . V_29 ) + V_25 ;
}
static struct V_27 F_22 (
unsigned long V_13 , unsigned long V_16 )
{
struct V_27 V_28 ;
T_2 V_25 ;
V_28 . V_29 = ( V_16 >= 22 * V_13 ) ? 22 : 20 ;
V_28 . V_23 = 0x3fffffff ;
if ( V_16 <= V_13 * V_28 . V_29 )
V_28 . V_21 = 0 ;
else if ( V_16 >= V_13 * ( V_28 . V_29 + 1 ) )
V_28 . V_21 = V_28 . V_23 - 1 ;
else {
V_25 = V_16 - V_13 * V_28 . V_29 ;
V_25 *= V_28 . V_23 ;
F_18 ( V_25 , V_13 ) ;
V_28 . V_21 = V_25 ;
}
return V_28 ;
}
static unsigned long F_23 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_27 V_28 ;
V_28 . V_21 = F_3 ( V_2 -> V_6 + V_30 ) ;
V_28 . V_23 = F_3 ( V_2 -> V_6 + V_31 ) ;
V_28 . V_29 = ( F_3 ( V_2 -> V_6 ) & V_2 -> V_15 ) ? 22 : 20 ;
return F_21 ( V_13 , V_28 ) ;
}
static long F_24 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long * V_17 )
{
struct V_27 V_28 = F_22 ( * V_17 , V_16 ) ;
return F_21 ( * V_17 , V_28 ) ;
}
static int F_25 ( struct V_11 * V_12 , unsigned long V_16 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
struct V_27 V_28 =
F_22 ( V_13 , V_16 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
if ( V_28 . V_29 == 20 )
V_5 &= ~ V_2 -> V_15 ;
else
V_5 |= V_2 -> V_15 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
F_8 ( V_28 . V_21 , V_2 -> V_6 + V_30 ) ;
F_8 ( V_28 . V_23 , V_2 -> V_6 + V_31 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_26 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
return V_2 -> V_32 ;
}
struct V_33 * F_27 ( enum V_34 type , const char * V_35 ,
const char * V_36 , void T_3 * V_6 ,
T_1 V_15 )
{
struct V_1 * V_2 ;
const struct V_37 * V_38 ;
struct V_33 * V_33 ;
struct V_39 V_40 ;
V_2 = F_28 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return F_29 ( - V_42 ) ;
V_2 -> V_7 = V_43 ;
switch ( type ) {
case V_44 :
V_38 = & V_45 ;
break;
case V_46 :
V_38 = & V_47 ;
break;
case V_48 :
V_2 -> V_14 = 1 ;
case V_49 :
V_38 = & V_50 ;
V_2 -> V_8 = true ;
break;
case V_51 :
V_38 = & V_52 ;
break;
case V_53 :
V_2 -> V_7 = V_54 ;
V_2 -> V_32 = 1000000000 ;
V_38 = & V_55 ;
break;
case V_56 :
V_2 -> V_32 = 500000000 ;
V_38 = & V_55 ;
break;
default:
V_38 = & V_50 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_15 = V_15 ;
V_40 . V_35 = V_35 ;
V_40 . V_38 = V_38 ;
V_40 . V_57 = 0 ;
V_40 . V_58 = & V_36 ;
V_40 . V_59 = 1 ;
V_2 -> V_12 . V_40 = & V_40 ;
V_33 = F_30 ( NULL , & V_2 -> V_12 ) ;
if ( F_31 ( V_33 ) )
F_32 ( V_2 ) ;
return V_33 ;
}
