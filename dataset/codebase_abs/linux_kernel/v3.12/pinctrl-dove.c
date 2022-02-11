static int F_1 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned V_4 = ( V_2 -> V_5 / V_6 ) * V_7 ;
unsigned V_8 = ( V_2 -> V_5 % V_6 ) * V_7 ;
unsigned long V_9 = F_2 ( V_10 ) ;
unsigned long V_11 ;
if ( V_9 & ( 1 << V_2 -> V_5 ) ) {
V_11 = F_2 ( V_12 + V_4 ) ;
* V_3 = ( V_11 >> V_8 ) & V_13 ;
* V_3 |= V_14 ;
} else {
V_11 = F_2 ( V_15 + V_4 ) ;
* V_3 = ( V_11 >> V_8 ) & V_13 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned V_4 = ( V_2 -> V_5 / V_6 ) * V_7 ;
unsigned V_8 = ( V_2 -> V_5 % V_6 ) * V_7 ;
unsigned long V_9 = F_2 ( V_10 ) ;
unsigned long V_11 ;
if ( V_3 & V_14 ) {
F_4 ( V_9 | ( 1 << V_2 -> V_5 ) , V_10 ) ;
V_11 = F_2 ( V_12 + V_4 ) ;
V_11 &= ~ ( V_13 << V_8 ) ;
V_11 |= ( V_3 & V_13 ) << V_8 ;
F_4 ( V_11 , V_12 + V_4 ) ;
} else {
F_4 ( V_9 & ~ ( 1 << V_2 -> V_5 ) , V_10 ) ;
V_11 = F_2 ( V_15 + V_4 ) ;
V_11 &= ~ ( V_13 << V_8 ) ;
V_11 |= ( V_3 & V_13 ) << V_8 ;
F_4 ( V_11 , V_15 + V_4 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_16 = F_2 ( V_17 ) ;
unsigned long V_18 ;
switch ( V_2 -> V_5 ) {
case 24 :
V_18 = V_19 ;
break;
case 40 :
V_18 = V_20 ;
break;
case 46 :
V_18 = V_21 ;
break;
case 58 :
V_18 = V_22 ;
break;
case 62 :
V_18 = V_23 ;
break;
default:
return - V_24 ;
}
* V_3 = ( ( V_16 & V_18 ) != 0 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_16 = F_2 ( V_17 ) ;
unsigned long V_18 ;
switch ( V_2 -> V_5 ) {
case 24 :
V_18 = V_19 ;
break;
case 40 :
V_18 = V_20 ;
break;
case 46 :
V_18 = V_21 ;
break;
case 58 :
V_18 = V_22 ;
break;
case 62 :
V_18 = V_23 ;
break;
default:
return - V_24 ;
}
V_16 &= ~ V_18 ;
if ( V_3 )
V_16 |= V_18 ;
F_4 ( V_16 , V_17 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_25 = F_2 ( V_26 ) ;
* V_3 = ( ( V_25 & V_27 ) != 0 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_25 = F_2 ( V_26 ) ;
V_25 &= ~ V_27 ;
if ( V_3 )
V_25 |= V_27 ;
F_4 ( V_25 , V_26 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_9 = F_2 ( V_10 ) ;
* V_3 = ( ( V_9 & V_28 ) != 0 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_9 = F_2 ( V_10 ) ;
V_9 &= ~ V_28 ;
if ( V_3 )
V_9 |= V_28 ;
F_4 ( V_9 , V_10 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_16 = F_2 ( V_17 ) ;
unsigned long V_29 = F_2 ( V_30 ) ;
unsigned long V_25 = F_2 ( V_26 ) ;
unsigned long V_31 = F_2 ( V_32 ) ;
* V_3 = 0 ;
if ( V_16 & V_33 )
* V_3 |= F_12 ( 3 ) ;
if ( V_29 & V_34 )
* V_3 |= F_12 ( 2 ) ;
if ( V_25 & V_35 )
* V_3 |= F_12 ( 1 ) ;
if ( V_31 & V_36 )
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
unsigned long V_16 = F_2 ( V_17 ) ;
unsigned long V_29 = F_2 ( V_30 ) ;
unsigned long V_25 = F_2 ( V_26 ) ;
unsigned long V_31 = F_2 ( V_32 ) ;
V_31 &= ~ V_36 ;
V_25 &= ~ V_35 ;
V_29 &= ~ V_34 ;
V_16 &= ~ V_33 ;
if ( V_3 & F_12 ( 0 ) )
V_31 |= V_36 ;
if ( V_3 & F_12 ( 1 ) )
V_25 |= V_35 ;
if ( V_3 & F_12 ( 2 ) )
V_29 |= V_34 ;
if ( V_3 & F_12 ( 3 ) )
V_16 |= V_33 ;
F_4 ( V_16 , V_17 ) ;
F_4 ( V_29 , V_30 ) ;
F_4 ( V_25 , V_26 ) ;
F_4 ( V_31 , V_32 ) ;
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
return - V_37 ;
case 0x08 :
case 0x0b :
if ( V_5 <= 55 )
return 0 ;
return - V_37 ;
case 0x0a :
return 0 ;
}
return - V_37 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_5 ,
bool V_38 )
{
if ( V_5 < 52 || V_5 > 57 )
return - V_37 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned long * V_3 )
{
unsigned long V_39 = F_2 ( V_40 ) ;
unsigned long V_31 = F_2 ( V_32 ) ;
* V_3 = 0 ;
if ( V_39 & V_41 )
* V_3 = 1 ;
else if ( V_31 & V_42 )
* V_3 = 2 ;
else if ( V_31 & V_43 )
* V_3 = 3 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned long V_39 = F_2 ( V_40 ) ;
unsigned long V_31 = F_2 ( V_32 ) ;
V_39 &= ~ V_41 ;
V_31 &= ~ ( V_42 | V_42 ) ;
switch ( V_3 ) {
case 1 :
V_39 |= V_41 ;
break;
case 2 :
V_31 |= V_42 ;
break;
case 3 :
V_31 |= V_43 ;
break;
}
F_4 ( V_39 , V_40 ) ;
F_4 ( V_31 , V_32 ) ;
return 0 ;
}
static int F_18 ( struct V_44 * V_45 )
{
const struct V_46 * V_47 =
F_19 ( V_48 , & V_45 -> V_49 ) ;
V_45 -> V_49 . V_50 = ( void * ) V_47 -> V_51 ;
V_52 = F_20 ( & V_45 -> V_49 , NULL ) ;
if ( F_21 ( V_52 ) ) {
F_22 ( & V_45 -> V_49 , L_1 ) ;
return F_23 ( V_52 ) ;
}
F_24 ( V_52 ) ;
return F_25 ( V_45 ) ;
}
static int F_26 ( struct V_44 * V_45 )
{
int V_53 ;
V_53 = F_27 ( V_45 ) ;
if ( ! F_21 ( V_52 ) )
F_28 ( V_52 ) ;
return V_53 ;
}
