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
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_14 ;
return ( div == 1 ) ? V_13 * 22 : V_13 * 20 ;
}
static long F_11 ( struct V_11 * V_12 , unsigned long V_15 ,
unsigned long * V_16 )
{
unsigned long V_13 = * V_16 ;
return ( V_15 >= V_13 * 22 ) ? V_13 * 22 :
V_13 * 20 ;
}
static int F_12 ( struct V_11 * V_12 , unsigned long V_15 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 , div ;
if ( V_15 == V_13 * 22 )
div = 1 ;
else if ( V_15 == V_13 * 20 )
div = 0 ;
else
return - V_17 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_14 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_13 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_14 ;
return V_13 * div / 2 ;
}
static long F_14 ( struct V_11 * V_12 , unsigned long V_15 ,
unsigned long * V_16 )
{
unsigned long V_13 = * V_16 ;
unsigned long V_18 = V_13 * 54 / 2 ;
unsigned long V_19 = V_13 * 108 / 2 ;
T_1 div ;
if ( V_15 > V_19 )
V_15 = V_19 ;
else if ( V_15 < V_18 )
V_15 = V_18 ;
div = V_15 * 2 / V_13 ;
return V_13 * div / 2 ;
}
static int F_15 ( struct V_11 * V_12 , unsigned long V_15 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned long V_18 = V_13 * 54 / 2 ;
unsigned long V_19 = V_13 * 108 / 2 ;
T_1 V_5 , div ;
if ( V_15 < V_18 || V_15 > V_19 )
return - V_17 ;
div = V_15 * 2 / V_13 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_14 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_16 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_20 = F_3 ( V_2 -> V_6 + V_21 ) ;
T_1 V_22 = F_3 ( V_2 -> V_6 + V_23 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_14 ;
return ( V_13 * div ) + ( ( V_13 / V_22 ) * V_20 ) ;
}
static long F_17 ( struct V_11 * V_12 , unsigned long V_15 ,
unsigned long * V_16 )
{
unsigned long V_13 = * V_16 ;
unsigned long V_18 = V_13 * 27 ;
unsigned long V_19 = V_13 * 54 ;
T_1 div ;
T_1 V_20 , V_22 = 1000000 ;
T_2 V_24 ;
if ( V_15 > V_19 )
V_15 = V_19 ;
else if ( V_15 < V_18 )
V_15 = V_18 ;
div = V_15 / V_13 ;
V_24 = ( V_25 ) ( V_15 - div * V_13 ) ;
V_24 *= V_22 ;
F_18 ( V_24 , V_13 ) ;
V_20 = V_24 ;
return V_13 * div + V_13 / V_22 * V_20 ;
}
static int F_19 ( struct V_11 * V_12 , unsigned long V_15 ,
unsigned long V_13 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned long V_18 = V_13 * 27 ;
unsigned long V_19 = V_13 * 54 ;
T_1 V_5 , div ;
T_1 V_20 , V_22 = 1000000 ;
T_2 V_24 ;
if ( V_15 < V_18 || V_15 > V_19 )
return - V_17 ;
div = V_15 / V_13 ;
V_24 = ( V_25 ) ( V_15 - div * V_13 ) ;
V_24 *= V_22 ;
F_18 ( V_24 , V_13 ) ;
V_20 = V_24 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_14 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
F_8 ( V_20 , V_2 -> V_6 + V_21 ) ;
F_8 ( V_22 , V_2 -> V_6 + V_23 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_20 ( struct V_11 * V_12 ,
unsigned long V_13 )
{
return 500000000 ;
}
struct V_26 * F_21 ( enum V_27 type , const char * V_28 ,
const char * V_29 , void T_3 * V_6 ,
T_1 V_14 )
{
struct V_1 * V_2 ;
const struct V_30 * V_31 ;
struct V_26 * V_26 ;
struct V_32 V_33 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 )
return F_23 ( - V_35 ) ;
switch ( type ) {
case V_36 :
V_31 = & V_37 ;
break;
case V_38 :
V_31 = & V_39 ;
V_2 -> V_8 = true ;
break;
case V_40 :
V_31 = & V_41 ;
break;
case V_42 :
V_31 = & V_43 ;
break;
default:
V_31 = & V_39 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_14 = V_14 ;
V_33 . V_28 = V_28 ;
V_33 . V_31 = V_31 ;
V_33 . V_44 = 0 ;
V_33 . V_45 = & V_29 ;
V_33 . V_46 = 1 ;
V_2 -> V_12 . V_33 = & V_33 ;
V_26 = F_24 ( NULL , & V_2 -> V_12 ) ;
if ( F_25 ( V_26 ) )
F_26 ( V_2 ) ;
return V_26 ;
}
