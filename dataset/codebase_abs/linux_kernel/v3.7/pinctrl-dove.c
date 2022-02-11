static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned V_4 = ( V_2 -> V_5 / V_6 ) * V_7 ;
unsigned V_8 = ( V_2 -> V_5 % V_6 ) * V_7 ;
unsigned long V_9 = F_2 ( V_10 ) ;
unsigned long V_11 = F_2 ( V_12 + V_4 ) ;
if ( V_9 & ( 1 << V_2 -> V_5 ) )
* V_3 = V_13 ;
else
* V_3 = ( V_11 >> V_8 ) & V_14 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned V_4 = ( V_2 -> V_5 / V_6 ) * V_7 ;
unsigned V_8 = ( V_2 -> V_5 % V_6 ) * V_7 ;
unsigned long V_9 = F_2 ( V_10 ) ;
unsigned long V_11 = F_2 ( V_12 + V_4 ) ;
if ( V_3 == V_13 )
F_4 ( V_9 | ( 1 << V_2 -> V_5 ) , V_10 ) ;
else {
F_4 ( V_9 & ~ ( 1 << V_2 -> V_5 ) , V_10 ) ;
V_11 &= ~ ( V_14 << V_8 ) ;
V_11 |= V_3 << V_8 ;
F_4 ( V_11 , V_12 + V_4 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_15 = F_2 ( V_16 ) ;
unsigned long V_17 ;
switch ( V_2 -> V_5 ) {
case 24 :
V_17 = V_18 ;
break;
case 40 :
V_17 = V_19 ;
break;
case 46 :
V_17 = V_20 ;
break;
case 58 :
V_17 = V_21 ;
break;
case 62 :
V_17 = V_22 ;
break;
default:
return - V_23 ;
}
* V_3 = ( ( V_15 & V_17 ) != 0 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_15 = F_2 ( V_16 ) ;
unsigned long V_17 ;
switch ( V_2 -> V_5 ) {
case 24 :
V_17 = V_18 ;
break;
case 40 :
V_17 = V_19 ;
break;
case 46 :
V_17 = V_20 ;
break;
case 58 :
V_17 = V_21 ;
break;
case 62 :
V_17 = V_22 ;
break;
default:
return - V_23 ;
}
V_15 &= ~ V_17 ;
if ( V_3 )
V_15 |= V_17 ;
F_4 ( V_15 , V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_24 = F_2 ( V_25 ) ;
* V_3 = ( ( V_24 & V_26 ) != 0 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_24 = F_2 ( V_25 ) ;
V_24 &= ~ V_26 ;
if ( V_3 )
V_24 |= V_26 ;
F_4 ( V_24 , V_25 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_9 = F_2 ( V_10 ) ;
* V_3 = ( ( V_9 & V_27 ) != 0 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_9 = F_2 ( V_10 ) ;
V_9 &= ~ V_27 ;
if ( V_3 )
V_9 |= V_27 ;
F_4 ( V_9 , V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_15 = F_2 ( V_16 ) ;
unsigned long V_28 = F_2 ( V_29 ) ;
unsigned long V_24 = F_2 ( V_25 ) ;
unsigned long V_30 = F_2 ( V_31 ) ;
* V_3 = 0 ;
if ( V_15 & V_32 )
* V_3 |= F_12 ( 3 ) ;
if ( V_28 & V_33 )
* V_3 |= F_12 ( 2 ) ;
if ( V_24 & V_34 )
* V_3 |= F_12 ( 1 ) ;
if ( V_30 & V_35 )
* V_3 |= F_12 ( 0 ) ;
if ( ( * V_3 & F_12 ( 3 ) ) == 0 )
* V_3 &= ~ ( F_12 ( 2 ) | F_12 ( 0 ) ) ;
if ( ( * V_3 & F_12 ( 1 ) ) == 0 )
* V_3 &= ~ F_12 ( 0 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_15 = F_2 ( V_16 ) ;
unsigned long V_28 = F_2 ( V_29 ) ;
unsigned long V_24 = F_2 ( V_25 ) ;
unsigned long V_30 = F_2 ( V_31 ) ;
if ( V_3 & F_12 ( 0 ) )
V_30 |= V_35 ;
if ( V_3 & F_12 ( 1 ) )
V_24 |= V_34 ;
if ( V_3 & F_12 ( 2 ) )
V_28 |= V_33 ;
if ( V_3 & F_12 ( 3 ) )
V_15 |= V_32 ;
F_4 ( V_15 , V_16 ) ;
F_4 ( V_28 , V_29 ) ;
F_4 ( V_24 , V_25 ) ;
F_4 ( V_30 , V_31 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_5 )
{
unsigned long V_3 ;
F_11 ( V_2 , & V_3 ) ;
switch ( V_3 ) {
case 0x02 :
case 0x0e :
if ( V_5 >= 56 )
return 0 ;
return - V_36 ;
case 0x08 :
case 0x0b :
if ( V_5 <= 55 )
return 0 ;
return - V_36 ;
case 0x0a :
return 0 ;
}
return - V_36 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_5 ,
bool V_37 )
{
if ( V_5 < 52 || V_5 > 57 )
return - V_36 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_38 = F_2 ( V_39 ) ;
unsigned long V_30 = F_2 ( V_31 ) ;
* V_3 = 0 ;
if ( V_38 & V_40 )
* V_3 = 1 ;
else if ( V_30 & V_41 )
* V_3 = 2 ;
else if ( V_30 & V_42 )
* V_3 = 3 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_38 = F_2 ( V_39 ) ;
unsigned long V_30 = F_2 ( V_31 ) ;
V_38 &= ~ V_40 ;
V_30 &= ~ ( V_41 | V_41 ) ;
switch ( V_3 ) {
case 1 :
V_38 |= V_40 ;
break;
case 2 :
V_30 |= V_41 ;
break;
case 3 :
V_30 |= V_42 ;
break;
}
F_4 ( V_38 , V_39 ) ;
F_4 ( V_30 , V_31 ) ;
return 0 ;
}
static int T_2 F_18 ( struct V_43 * V_44 )
{
const struct V_45 * V_46 =
F_19 ( V_47 , & V_44 -> V_48 ) ;
V_44 -> V_48 . V_49 = V_46 -> V_50 ;
V_51 = F_20 ( & V_44 -> V_48 , NULL ) ;
if ( ! F_21 ( V_51 ) )
F_22 ( V_51 ) ;
return F_23 ( V_44 ) ;
}
static int T_3 F_24 ( struct V_43 * V_44 )
{
int V_52 ;
V_52 = F_25 ( V_44 ) ;
if ( ! F_21 ( V_51 ) )
F_26 ( V_51 ) ;
return V_52 ;
}
