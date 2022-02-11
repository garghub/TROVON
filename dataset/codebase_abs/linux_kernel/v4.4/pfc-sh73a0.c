static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 [ 1 ] . V_9 + 4 ;
unsigned long V_10 ;
T_2 V_11 ;
F_2 ( & V_5 -> V_12 , V_10 ) ;
V_11 = F_3 ( V_7 ) ;
if ( V_3 )
V_11 |= F_4 ( 28 ) ;
else
V_11 &= ~ F_4 ( 28 ) ;
F_5 ( V_11 , V_7 ) ;
F_6 ( & V_5 -> V_12 , V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , true ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , false ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
void T_1 * V_7 = V_5 -> V_8 [ 1 ] . V_9 + 4 ;
unsigned long V_10 ;
T_2 V_11 ;
F_2 ( & V_5 -> V_12 , V_10 ) ;
V_11 = F_3 ( V_7 ) ;
F_6 ( & V_5 -> V_12 , V_10 ) ;
return ! ! ( V_11 & F_4 ( 28 ) ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
return 3300000 ;
}
static unsigned int F_11 ( struct V_4 * V_5 , unsigned int V_13 )
{
void T_1 * V_7 = V_5 -> V_8 -> V_9
+ V_14 [ V_13 >> 5 ] + V_13 ;
T_2 V_11 = F_12 ( V_7 ) & V_15 ;
switch ( V_11 ) {
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
default:
return V_21 ;
}
}
static void F_13 ( struct V_4 * V_5 , unsigned int V_13 ,
unsigned int V_22 )
{
void T_1 * V_7 = V_5 -> V_8 -> V_9
+ V_14 [ V_13 >> 5 ] + V_13 ;
T_2 V_11 = F_12 ( V_7 ) & ~ V_15 ;
switch ( V_22 ) {
case V_17 :
V_11 |= V_16 ;
break;
case V_19 :
V_11 |= V_18 ;
break;
}
F_14 ( V_11 , V_7 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
struct V_23 V_24 = { } ;
struct V_1 * V_25 ;
int V_26 ;
V_24 . V_27 = V_5 -> V_27 ;
V_24 . V_28 = & V_29 ;
V_24 . V_30 = V_5 ;
V_25 = F_16 ( V_5 -> V_27 , & V_31 , & V_24 ) ;
if ( F_17 ( V_25 ) ) {
V_26 = F_18 ( V_25 ) ;
F_19 ( V_5 -> V_27 , L_1 ,
V_26 ) ;
return V_26 ;
}
return 0 ;
}
