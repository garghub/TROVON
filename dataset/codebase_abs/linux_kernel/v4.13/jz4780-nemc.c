unsigned int F_1 ( struct V_1 * V_2 )
{
const T_1 * V_3 ;
unsigned int V_4 , V_5 = 0 ;
unsigned long V_6 = 0 ;
int V_7 = 0 ;
while ( ( V_3 = F_2 ( V_2 -> V_8 , V_7 ++ , NULL , NULL ) ) ) {
V_4 = F_3 ( V_3 , 1 ) ;
if ( ! ( V_6 & F_4 ( V_4 ) ) ) {
V_6 |= F_4 ( V_4 ) ;
V_5 ++ ;
}
}
return V_5 ;
}
void F_5 ( struct V_1 * V_2 , unsigned int V_4 ,
enum V_9 type )
{
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
T_2 V_13 ;
V_13 = F_7 ( V_11 -> V_14 + V_15 ) ;
switch ( type ) {
case V_16 :
V_13 &= ~ ( F_8 ( V_4 ) | F_9 ( V_4 ) ) ;
break;
case V_17 :
V_13 &= ~ F_8 ( V_4 ) ;
V_13 |= F_9 ( V_4 ) ;
break;
}
F_10 ( V_13 , V_11 -> V_14 + V_15 ) ;
}
void F_11 ( struct V_1 * V_2 , unsigned int V_4 , bool assert )
{
struct V_10 * V_11 = F_6 ( V_2 -> V_12 ) ;
T_2 V_13 ;
V_13 = F_7 ( V_11 -> V_14 + V_15 ) ;
if ( assert )
V_13 |= F_12 ( V_4 ) ;
else
V_13 &= ~ F_12 ( V_4 ) ;
F_10 ( V_13 , V_11 -> V_14 + V_15 ) ;
}
static T_2 F_13 ( struct V_10 * V_11 )
{
unsigned long V_18 ;
V_18 = F_14 ( V_11 -> V_19 ) ;
if ( ! V_18 )
return 0 ;
return F_15 ( 1000000000000ull , V_18 ) ;
}
static T_2 F_16 ( struct V_10 * V_11 , T_2 V_20 )
{
return ( ( V_20 * 1000 ) + V_11 -> V_21 - 1 ) / V_11 -> V_21 ;
}
static bool F_17 ( struct V_10 * V_11 ,
unsigned int V_4 ,
struct V_22 * V_23 )
{
T_2 V_24 , V_25 , V_26 ;
static const T_2 V_27 [] = {
0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 ,
11 , 11 ,
12 , 12 , 12 ,
13 , 13 , 13 , 13 , 13 ,
14 , 14 , 14 , 14 , 14 ,
15 , 15 , 15 , 15 , 15 , 15
} ;
V_24 = F_7 ( V_11 -> V_14 + F_18 ( V_4 ) ) ;
V_24 &= ~ V_28 ;
if ( ! F_19 ( V_23 , L_1 , & V_25 ) ) {
V_24 &= ~ V_29 ;
switch ( V_25 ) {
case 8 :
V_24 |= V_30 ;
break;
default:
F_20 ( V_11 -> V_2 , L_2 , V_25 ) ;
return false ;
}
}
if ( F_19 ( V_23 , L_3 , & V_25 ) == 0 ) {
V_24 &= ~ V_31 ;
V_26 = F_16 ( V_11 , V_25 ) ;
if ( V_26 > 15 ) {
F_20 ( V_11 -> V_2 , L_4 ,
V_25 , V_26 ) ;
return false ;
}
V_24 |= V_26 << V_32 ;
}
if ( F_19 ( V_23 , L_5 , & V_25 ) == 0 ) {
V_24 &= ~ V_33 ;
V_26 = F_16 ( V_11 , V_25 ) ;
if ( V_26 > 15 ) {
F_20 ( V_11 -> V_2 , L_6 ,
V_25 , V_26 ) ;
return false ;
}
V_24 |= V_26 << V_34 ;
}
if ( F_19 ( V_23 , L_7 , & V_25 ) == 0 ) {
V_24 &= ~ V_35 ;
V_26 = F_16 ( V_11 , V_25 ) ;
if ( V_26 > 31 ) {
F_20 ( V_11 -> V_2 , L_8 ,
V_25 , V_26 ) ;
return false ;
}
V_24 |= V_27 [ V_26 ] << V_36 ;
}
if ( F_19 ( V_23 , L_9 , & V_25 ) == 0 ) {
V_24 &= ~ V_37 ;
V_26 = F_16 ( V_11 , V_25 ) ;
if ( V_26 > 31 ) {
F_20 ( V_11 -> V_2 , L_10 ,
V_25 , V_26 ) ;
return false ;
}
V_24 |= V_27 [ V_26 ] << V_38 ;
}
if ( F_19 ( V_23 , L_11 , & V_25 ) == 0 ) {
V_24 &= ~ V_39 ;
V_26 = F_16 ( V_11 , V_25 ) ;
if ( V_26 > 63 ) {
F_20 ( V_11 -> V_2 , L_12 ,
V_25 , V_26 ) ;
return false ;
}
V_24 |= V_26 << V_40 ;
}
F_10 ( V_24 , V_11 -> V_14 + F_18 ( V_4 ) ) ;
return true ;
}
static int F_21 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = & V_42 -> V_2 ;
struct V_10 * V_11 ;
struct V_43 * V_44 ;
struct V_22 * V_45 ;
const T_1 * V_3 ;
unsigned int V_4 ;
unsigned long V_6 ;
int V_7 , V_46 ;
V_11 = F_22 ( V_2 , sizeof( * V_11 ) , V_47 ) ;
if ( ! V_11 )
return - V_48 ;
F_23 ( & V_11 -> V_49 ) ;
V_11 -> V_2 = V_2 ;
V_44 = F_24 ( V_42 , V_50 , 0 ) ;
V_11 -> V_14 = F_25 ( V_2 , V_44 ) ;
if ( F_26 ( V_11 -> V_14 ) ) {
F_20 ( V_2 , L_13 ) ;
return F_27 ( V_11 -> V_14 ) ;
}
F_10 ( 0 , V_11 -> V_14 + V_15 ) ;
V_11 -> V_19 = F_28 ( V_2 , NULL ) ;
if ( F_26 ( V_11 -> V_19 ) ) {
F_20 ( V_2 , L_14 ) ;
return F_27 ( V_11 -> V_19 ) ;
}
V_46 = F_29 ( V_11 -> V_19 ) ;
if ( V_46 ) {
F_20 ( V_2 , L_15 , V_46 ) ;
return V_46 ;
}
V_11 -> V_21 = F_13 ( V_11 ) ;
if ( ! V_11 -> V_21 ) {
F_20 ( V_2 , L_16 ) ;
F_30 ( V_11 -> V_19 ) ;
return - V_51 ;
}
F_31 (nemc->dev->of_node, child) {
V_6 = 0 ;
V_7 = 0 ;
while ( ( V_3 = F_2 ( V_45 , V_7 ++ , NULL , NULL ) ) ) {
V_4 = F_3 ( V_3 , 1 ) ;
if ( V_4 < 1 || V_4 >= V_52 ) {
F_20 ( V_11 -> V_2 ,
L_17 ,
V_45 -> V_53 , V_4 ) ;
V_6 = 0 ;
break;
}
V_6 |= F_4 ( V_4 ) ;
}
if ( ! V_6 ) {
F_20 ( V_11 -> V_2 , L_18 ,
V_45 -> V_53 ) ;
continue;
} else if ( V_11 -> V_54 & V_6 ) {
F_20 ( V_11 -> V_2 , L_19 ,
V_45 -> V_53 ) ;
continue;
}
F_32 (bank, &referenced, JZ4780_NEMC_NUM_BANKS) {
if ( ! F_17 ( V_11 , V_4 , V_45 ) ) {
V_6 = 0 ;
break;
}
}
if ( V_6 ) {
if ( F_33 ( V_45 , NULL , V_11 -> V_2 ) )
V_11 -> V_54 |= V_6 ;
}
}
F_34 ( V_42 , V_11 ) ;
F_35 ( V_2 , L_20 ) ;
return 0 ;
}
static int F_36 ( struct V_41 * V_42 )
{
struct V_10 * V_11 = F_37 ( V_42 ) ;
F_30 ( V_11 -> V_19 ) ;
return 0 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_55 ) ;
}
