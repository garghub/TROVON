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
int V_13 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
if ( V_2 -> V_8 )
V_5 |= V_7 ;
else
V_5 &= ~ V_7 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_14 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 |= V_14 ;
if ( V_2 -> V_8 )
V_5 &= ~ V_7 ;
else
V_5 |= V_7 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
}
static int F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 |= V_15 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return 0 ;
}
static void F_11 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_15 ;
F_8 ( V_5 , V_2 -> V_6 ) ;
}
static unsigned long F_12 ( struct V_11 * V_12 ,
unsigned long V_16 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_17 ;
return ( div == 1 ) ? V_16 * 22 : V_16 * 20 ;
}
static long F_13 ( struct V_11 * V_12 , unsigned long V_18 ,
unsigned long * V_19 )
{
unsigned long V_16 = * V_19 ;
return ( V_18 >= V_16 * 22 ) ? V_16 * 22 :
V_16 * 20 ;
}
static int F_14 ( struct V_11 * V_12 , unsigned long V_18 ,
unsigned long V_16 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_5 , div ;
if ( V_18 == V_16 * 22 )
div = 1 ;
else if ( V_18 == V_16 * 20 )
div = 0 ;
else
return - V_20 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_17 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_15 ( struct V_11 * V_12 ,
unsigned long V_16 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_17 ;
return V_16 * div / 2 ;
}
static long F_16 ( struct V_11 * V_12 , unsigned long V_18 ,
unsigned long * V_19 )
{
unsigned long V_16 = * V_19 ;
unsigned long V_21 = V_16 * 54 / 2 ;
unsigned long V_22 = V_16 * 108 / 2 ;
T_1 div ;
if ( V_18 > V_22 )
V_18 = V_22 ;
else if ( V_18 < V_21 )
V_18 = V_21 ;
div = V_18 * 2 / V_16 ;
return V_16 * div / 2 ;
}
static int F_17 ( struct V_11 * V_12 , unsigned long V_18 ,
unsigned long V_16 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned long V_21 = V_16 * 54 / 2 ;
unsigned long V_22 = V_16 * 108 / 2 ;
T_1 V_5 , div ;
if ( V_18 < V_21 || V_18 > V_22 )
return - V_20 ;
div = V_18 * 2 / V_16 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_17 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_18 ( struct V_11 * V_12 ,
unsigned long V_16 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
T_1 V_23 = F_3 ( V_2 -> V_6 + V_24 ) ;
T_1 V_25 = F_3 ( V_2 -> V_6 + V_26 ) ;
T_1 div = F_3 ( V_2 -> V_6 ) & V_2 -> V_17 ;
return ( V_16 * div ) + ( ( V_16 / V_25 ) * V_23 ) ;
}
static long F_19 ( struct V_11 * V_12 , unsigned long V_18 ,
unsigned long * V_19 )
{
unsigned long V_16 = * V_19 ;
unsigned long V_21 = V_16 * 27 ;
unsigned long V_22 = V_16 * 54 ;
T_1 div ;
T_1 V_23 , V_25 = 1000000 ;
T_2 V_27 ;
if ( V_18 > V_22 )
V_18 = V_22 ;
else if ( V_18 < V_21 )
V_18 = V_21 ;
div = V_18 / V_16 ;
V_27 = ( V_28 ) ( V_18 - div * V_16 ) ;
V_27 *= V_25 ;
F_20 ( V_27 , V_16 ) ;
V_23 = V_27 ;
return V_16 * div + V_16 / V_25 * V_23 ;
}
static int F_21 ( struct V_11 * V_12 , unsigned long V_18 ,
unsigned long V_16 )
{
struct V_1 * V_2 = F_7 ( V_12 ) ;
unsigned long V_21 = V_16 * 27 ;
unsigned long V_22 = V_16 * 54 ;
T_1 V_5 , div ;
T_1 V_23 , V_25 = 1000000 ;
T_2 V_27 ;
if ( V_18 < V_21 || V_18 > V_22 )
return - V_20 ;
div = V_18 / V_16 ;
V_27 = ( V_28 ) ( V_18 - div * V_16 ) ;
V_27 *= V_25 ;
F_20 ( V_27 , V_16 ) ;
V_23 = V_27 ;
V_5 = F_3 ( V_2 -> V_6 ) ;
V_5 &= ~ V_2 -> V_17 ;
V_5 |= div ;
F_8 ( V_5 , V_2 -> V_6 ) ;
F_8 ( V_23 , V_2 -> V_6 + V_24 ) ;
F_8 ( V_25 , V_2 -> V_6 + V_26 ) ;
return F_1 ( V_2 ) ;
}
static unsigned long F_22 ( struct V_11 * V_12 ,
unsigned long V_16 )
{
return 500000000 ;
}
struct V_29 * F_23 ( enum V_30 type , const char * V_31 ,
const char * V_32 , void T_3 * V_6 ,
T_1 V_17 )
{
struct V_1 * V_2 ;
const struct V_33 * V_34 ;
struct V_29 * V_29 ;
struct V_35 V_36 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return F_25 ( - V_38 ) ;
switch ( type ) {
case V_39 :
V_34 = & V_40 ;
break;
case V_41 :
V_34 = & V_42 ;
V_2 -> V_8 = true ;
break;
case V_43 :
V_34 = & V_44 ;
break;
case V_45 :
V_34 = & V_46 ;
break;
default:
V_34 = & V_42 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_17 = V_17 ;
V_36 . V_31 = V_31 ;
V_36 . V_34 = V_34 ;
V_36 . V_47 = 0 ;
V_36 . V_48 = & V_32 ;
V_36 . V_49 = 1 ;
V_2 -> V_12 . V_36 = & V_36 ;
V_29 = F_26 ( NULL , & V_2 -> V_12 ) ;
if ( F_27 ( V_29 ) )
F_28 ( V_2 ) ;
return V_29 ;
}
