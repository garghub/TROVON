static int F_1 ( T_1 V_1 , int V_2 , int V_3 , int V_4 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 0 , 0 , 0 , V_2 ) ;
F_3 ( 1 , 0 , V_2 , 0 ) ;
F_3 ( V_5 , 0 , V_2 , V_2 ) ;
default:
return - V_6 ;
}
}
static int F_4 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 0 , 0 , 0 , V_7 ) ;
F_3 ( 1 , 0 , V_7 , 0 ) ;
F_3 ( V_5 , 0 , V_7 , V_7 ) ;
default:
return - V_6 ;
}
}
static int F_5 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 0 , 0 , 0 , V_8 ) ;
F_3 ( 1 , 0 , V_8 , 0 ) ;
F_3 ( V_5 , 0 , V_8 , V_8 ) ;
default:
return - V_6 ;
}
}
static int F_6 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 0 , 0 , 0 , V_7 ) ;
F_3 ( 1 , 0 , V_7 , 0 ) ;
F_3 ( V_5 , 0 , V_7 , V_7 ) ;
default:
return - V_6 ;
}
}
static int F_7 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 0 , 0 , 0 , V_7 ) ;
F_3 ( 1 , 0 , V_7 , 0 ) ;
F_3 ( V_5 , 0 , V_7 , V_7 ) ;
default:
return - V_6 ;
}
}
static int F_8 ( T_1 V_1 , T_2 V_9 )
{
T_2 V_10 = V_9 & 0x3fFFFF ;
if ( V_10 < ( 1 << 20 ) )
return F_4 ( V_1 ) ;
if ( V_10 < ( 2 << 20 ) )
return F_5 ( V_1 ) ;
if ( V_10 < ( 3 << 20 ) )
return F_6 ( V_1 ) ;
return F_7 ( V_1 ) ;
}
static int F_9 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( V_5 , 0 , V_7 , V_7 ) ;
F_3 ( V_5 , 1 , V_7 , V_7 ) ;
F_3 ( V_5 , 2 , V_7 , V_7 ) ;
F_3 ( V_5 , 3 , V_7 , V_7 ) ;
F_3 ( 0 , 0 , 0 , V_7 ) ;
F_3 ( 0 , 1 , 0 , V_7 ) ;
F_3 ( 0 , 2 , 0 , V_7 ) ;
F_3 ( 0 , 3 , 0 , V_7 ) ;
F_3 ( 1 , 0 , V_7 , 0 ) ;
F_3 ( 1 , 1 , V_7 , 0 ) ;
F_3 ( 1 , 2 , V_7 , 0 ) ;
F_3 ( 1 , 3 , V_7 , 0 ) ;
F_3 ( 3 , 0 , 0 , V_8 ) ;
F_3 ( 3 , 2 , V_8 , 0 ) ;
F_3 ( 4 , 0 , V_8 , 0 ) ;
F_3 ( 4 , 2 , 0 , 0 ) ;
F_3 ( 4 , 3 , 0 , V_8 ) ;
F_3 ( 5 , 0 , V_8 , 0 ) ;
F_3 ( 5 , 3 , 0 , V_8 ) ;
F_3 ( 6 , 0 , V_8 , 0 ) ;
F_3 ( 6 , 3 , 0 , V_8 ) ;
F_3 ( 7 , 0 , V_8 , 0 ) ;
F_3 ( 7 , 3 , 0 , V_8 ) ;
F_3 ( 8 , 0 , V_8 , 0 ) ;
F_3 ( 8 , 3 , 0 , V_8 ) ;
F_3 ( 9 , 0 , V_8 , 0 ) ;
F_3 ( 9 , 3 , 0 , V_8 ) ;
F_3 ( 10 , 0 , V_8 , 0 ) ;
F_3 ( 10 , 3 , 0 , V_8 ) ;
F_3 ( 13 , 0 , 0 , V_8 ) ;
F_3 ( 13 , 1 , 0 , V_8 ) ;
F_3 ( 13 , 2 , V_8 , 0 ) ;
F_3 ( 15 , 0 , V_8 , 0 ) ;
F_3 ( 15 , 3 , 0 , V_8 ) ;
F_3 ( 28 , 0 , 0 , V_8 ) ;
F_3 ( 28 , 1 , 0 , V_8 ) ;
F_3 ( 28 , 2 , 0 , V_8 ) ;
F_3 ( 28 , 3 , 0 , V_8 ) ;
F_3 ( 31 , 0 , V_8 , 0 ) ;
F_3 ( 31 , 1 , V_8 , 0 ) ;
F_3 ( 31 , 2 , V_8 , 0 ) ;
F_3 ( 31 , 3 , V_8 , 0 ) ;
default:
return - V_6 ;
}
}
static int F_10 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 16 , 1 , 0 , V_8 ) ;
F_3 ( 17 , 1 , 0 , V_8 ) ;
F_3 ( 17 , 3 , 0 , V_7 ) ;
F_3 ( 18 , 2 , 0 , V_7 ) ;
F_3 ( 18 , 3 , 0 , V_7 ) ;
F_3 ( 21 , 0 , 0 , V_7 ) ;
F_3 ( 21 , 1 , 0 , V_7 ) ;
F_3 ( 21 , 2 , 0 , V_7 ) ;
F_3 ( 21 , 3 , 0 , V_7 ) ;
default:
return F_9 ( V_1 ) ;
}
}
static int F_11 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 18 , 0 , 0 , V_8 ) ;
F_3 ( 18 , 1 , 0 , V_8 ) ;
F_3 ( 18 , 2 , V_8 , 0 ) ;
F_3 ( 18 , 3 , V_8 , 0 ) ;
F_3 ( 20 , 2 , V_8 , 0 ) ;
F_3 ( 21 , 0 , 0 , V_8 ) ;
F_3 ( 21 , 1 , 0 , V_8 ) ;
F_3 ( 21 , 2 , 0 , V_8 ) ;
F_3 ( 22 , 0 , 0 , V_8 ) ;
F_3 ( 22 , 1 , 0 , V_8 ) ;
F_3 ( 22 , 2 , 0 , V_8 ) ;
default:
return F_9 ( V_1 ) ;
}
}
static int F_12 ( T_1 V_1 )
{
return F_9 ( V_1 ) ;
}
static int F_13 ( T_1 V_1 , T_2 V_9 )
{
int V_2 ;
if ( V_9 < 0x2000000000ULL )
V_2 = F_10 ( V_1 ) ;
else if ( V_9 < 0x8000000000ULL )
V_2 = F_11 ( V_1 ) ;
else if ( V_9 < 0x9800000000ULL )
V_2 = F_10 ( V_1 ) ;
else if ( V_9 < 0x9C00000000ULL )
V_2 = F_11 ( V_1 ) ;
else if ( V_9 < 0xA000000000ULL )
V_2 = F_12 ( V_1 ) ;
else
V_2 = F_10 ( V_1 ) ;
return V_2 ;
}
static int F_14 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 0 , 1 , 0 , V_8 ) ;
F_3 ( 2 , 0 , 0 , V_8 ) ;
F_3 ( 3 , 0 , V_8 , 0 ) ;
default:
return F_1 ( V_1 , V_8 , 48 , 4 ) ;
}
}
static int F_15 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 2 , 0 , 0 , V_8 ) ;
F_3 ( 3 , 0 , V_8 , 0 ) ;
default:
return F_1 ( V_1 , V_8 , 4 , 4 ) ;
}
}
static int F_16 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 2 , 0 , V_7 , 0 ) ;
default:
return F_1 ( V_1 , V_7 , 12 , 4 ) ;
}
}
static int F_17 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 0 , 1 , 0 , V_8 ) ;
F_3 ( 0 , 2 , V_8 , 0 ) ;
F_3 ( 1 , 1 , V_8 , 0 ) ;
F_3 ( 1 , 2 , V_8 , 0 ) ;
F_3 ( 2 , 0 , 0 , V_8 ) ;
F_3 ( 2 , 1 , 0 , V_8 ) ;
F_3 ( 2 , 2 , 0 , V_8 ) ;
F_3 ( 2 , 3 , 0 , V_8 ) ;
F_3 ( 3 , 0 , V_8 , 0 ) ;
F_3 ( 3 , 1 , V_8 , 0 ) ;
F_3 ( 3 , 2 , V_8 , 0 ) ;
F_3 ( 3 , 3 , V_8 , 0 ) ;
F_3 ( V_5 , 1 , V_8 , V_8 ) ;
default:
return F_1 ( V_1 , V_8 , 1 , 63 ) ;
}
}
static int F_18 ( T_1 V_1 )
{
switch ( V_1 & F_2 ( 0 , ~ 0 , ~ 0 ) ) {
F_3 ( 0 , 3 , V_8 , 0 ) ;
F_3 ( 2 , 0 , V_8 , 0 ) ;
F_3 ( 2 , 1 , V_8 , 0 ) ;
F_3 ( 4 , 0 , V_8 , 0 ) ;
F_3 ( 4 , 1 , V_8 , 0 ) ;
F_3 ( 6 , 0 , V_8 , 0 ) ;
F_3 ( 6 , 1 , V_8 , 0 ) ;
F_3 ( 6 , 2 , V_8 , 0 ) ;
F_3 ( 8 , 2 , V_8 , 0 ) ;
F_3 ( 8 , 3 , V_8 , 0 ) ;
F_3 ( 9 , 0 , 0 , V_8 ) ;
F_3 ( 9 , 1 , 0 , V_8 ) ;
F_3 ( 9 , 2 , 0 , V_8 ) ;
F_3 ( 9 , 3 , 0 , V_8 ) ;
F_3 ( 10 , 0 , V_8 , 0 ) ;
F_3 ( 10 , 2 , V_8 , 0 ) ;
F_3 ( 14 , 0 , V_8 , 0 ) ;
F_3 ( 15 , 1 , 0 , V_8 ) ;
F_3 ( 17 , 2 , V_8 , 0 ) ;
F_3 ( 24 , 0 , 0 , V_8 ) ;
F_3 ( 24 , 1 , V_8 , 0 ) ;
F_3 ( 25 , 0 , 0 , V_8 ) ;
F_3 ( 25 , 1 , V_8 , 0 ) ;
default:
return F_1 ( V_1 , V_8 , 0 , 64 ) ;
}
}
int F_19 ( T_1 V_1 , T_2 V_9 )
{
switch ( F_20 ( V_1 ) ) {
case V_11 :
return F_8 ( V_1 , V_9 ) ;
case V_12 :
return F_1 ( V_1 , V_8 , 24 , 4 ) ;
case V_13 :
return F_14 ( V_1 ) ;
case V_14 :
return F_13 ( V_1 , V_9 ) ;
case V_15 :
return F_15 ( V_1 ) ;
case V_16 :
if ( V_9 < 0x10000 )
return F_1 ( V_1 , V_7 , 1 , 1 ) ;
else
return F_1 ( V_1 , V_8 , 1 , 1 ) ;
case V_17 :
return F_16 ( V_1 ) ;
case V_18 :
return F_17 ( V_1 ) ;
case V_19 :
return F_18 ( V_1 ) ;
case 0 :
return F_1 ( V_1 , V_8 , 4 , 4 ) ;
default:
return - V_6 ;
}
}
static int F_21 ( T_2 V_20 , int * V_21 , int V_22 ,
int V_23 , bool V_24 , int V_25 , int V_26 )
{
int V_27 , V_28 ;
if ( V_22 == V_14 || V_22 == V_18 )
return - V_6 ;
switch ( V_23 ) {
case 0 :
V_27 = V_24 ? 34 : 26 ;
* V_21 = ( V_20 >> V_27 ) & 0x3F ;
return 0 ;
case 1 :
V_28 = V_24 ? 39 : 31 ;
if ( V_20 & F_22 ( V_28 ) )
* V_21 = V_25 ;
else
* V_21 = V_26 ;
return 0 ;
case 2 :
V_26 &= ~ 1 ;
V_25 &= ~ 1 ;
V_28 = V_24 ? 39 : 31 ;
V_27 = V_28 - 1 ;
if ( V_20 & F_22 ( V_28 ) )
* V_21 = V_25 | ( int ) ( ( V_20 >> V_27 ) & 1 ) ;
else
* V_21 = V_26 | ( int ) ( ( V_20 >> V_27 ) & 1 ) ;
return 0 ;
case 3 :
V_26 &= ~ 3 ;
V_25 &= ~ 3 ;
V_28 = V_24 ? 39 : 31 ;
V_27 = V_28 - 2 ;
if ( V_20 & F_22 ( V_28 ) )
* V_21 = V_25 | ( int ) ( ( V_20 >> V_27 ) & 3 ) ;
else
* V_21 = V_26 | ( int ) ( ( V_20 >> V_27 ) & 3 ) ;
return 0 ;
default:
return - V_6 ;
}
}
static int F_23 ( T_2 V_20 , int V_21 , int V_22 ,
int V_23 , bool V_24 , int V_25 , int V_26 )
{
int V_29 , V_30 ;
V_30 = F_21 ( V_20 , & V_29 , V_22 , V_23 , V_24 , V_25 , V_26 ) ;
if ( V_30 )
return V_30 ;
if ( V_21 != - 1 && V_21 != V_29 )
return - V_6 ;
return 0 ;
}
static int F_24 ( T_2 * V_20 , int V_21 , int * V_31 ,
int V_27 , int V_28 , int V_32 )
{
int V_33 , V_29 ;
for ( V_33 = 0 ; V_33 < 2 ; V_33 ++ )
for ( V_29 = 0 ; V_29 < V_32 ; V_29 ++ ) {
if ( V_21 != ( V_31 [ V_33 ] | V_29 ) )
continue;
* V_20 &= ~ F_25 ( V_28 , V_27 ) ;
* V_20 |= ( ( T_2 ) V_33 << V_28 ) ;
* V_20 |= ( ( T_2 ) V_29 << V_27 ) ;
return 0 ;
}
return - V_34 ;
}
static int F_26 ( T_2 * V_20 , int V_21 , int V_22 ,
int V_23 , bool V_24 , int V_25 , int V_26 )
{
int V_27 , V_28 ;
int V_31 [ 2 ] ;
T_2 V_35 ;
V_31 [ 0 ] = V_26 ;
V_31 [ 1 ] = V_25 ;
if ( V_22 == V_14 || V_22 == V_18 )
return - V_6 ;
switch ( V_23 ) {
case 0 :
if ( V_22 == V_12 && ! V_24 )
return F_23 ( * V_20 , V_22 , V_21 ,
V_23 , V_24 , V_25 , V_26 ) ;
V_27 = V_24 ? 34 : 26 ;
V_35 = F_25 ( V_27 + 5 , V_27 ) ;
* V_20 &= ~ V_35 ;
* V_20 |= ( ( T_2 ) V_21 << V_27 ) & V_35 ;
return 0 ;
case 1 :
if ( V_22 == V_12 && ! V_24 )
return F_23 ( * V_20 , V_22 , V_21 ,
V_23 , V_24 , V_25 , V_26 ) ;
V_28 = V_24 ? 39 : 31 ;
if ( V_21 == V_26 ) {
* V_20 &= ~ F_22 ( V_28 ) ;
return 0 ;
}
if ( V_21 == V_25 ) {
* V_20 |= F_22 ( V_28 ) ;
return 0 ;
}
return - V_34 ;
case 2 :
if ( V_22 == V_12 && ! V_24 )
return F_23 ( * V_20 , V_22 , V_21 ,
V_23 , V_24 , V_25 , V_26 ) ;
V_31 [ 0 ] &= ~ 1 ;
V_31 [ 1 ] &= ~ 1 ;
V_28 = V_24 ? 39 : 31 ;
V_27 = V_28 - 1 ;
return F_24 ( V_20 , V_21 , V_31 ,
V_27 , V_28 , 2 ) ;
case 3 :
if ( V_22 == V_12 && ! V_24 )
return F_23 ( * V_20 , V_22 , V_21 ,
V_23 , V_24 , V_25 , V_26 ) ;
V_31 [ 0 ] &= ~ 3 ;
V_31 [ 1 ] &= ~ 3 ;
V_28 = V_24 ? 39 : 31 ;
V_27 = V_28 - 2 ;
return F_24 ( V_20 , V_21 , V_31 ,
V_27 , V_28 , 4 ) ;
default:
return - V_6 ;
}
}
static int F_27 ( T_2 * V_20 , int V_21 , int V_23 ,
bool V_24 , int V_25 , int V_26 )
{
int V_27 , V_28 , V_36 ;
int V_31 [ 2 ] ;
T_2 V_35 ;
int V_37 ;
V_31 [ 0 ] = V_26 ;
V_31 [ 1 ] = V_25 ;
V_36 = F_28 ( V_23 , V_24 ) ;
if ( ( ( * V_20 >> V_36 ) & 3 ) == V_38 )
V_37 = 1 ;
else
V_37 = 0 ;
switch ( V_23 ) {
case 0 :
V_27 = V_24 ? 32 : 24 ;
V_35 = F_25 ( V_27 + 5 , V_27 ) ;
* V_20 &= ~ V_35 ;
* V_20 |= ( ( ( T_2 ) V_21 ) << V_27 ) & V_35 ;
return 0 ;
case 1 :
if ( V_37 ) {
V_27 = V_24 ? 32 : 24 ;
V_35 = F_25 ( V_27 + 5 , V_27 ) ;
* V_20 &= ~ V_35 ;
* V_20 |= ( ( ( T_2 ) V_21 ) << V_27 ) & V_35 ;
return 0 ;
}
V_28 = V_24 ? 37 : 29 ;
if ( V_21 == V_26 ) {
* V_20 &= ~ F_22 ( V_28 ) ;
return 0 ;
}
if ( V_21 == V_25 ) {
* V_20 |= F_22 ( V_28 ) ;
return 0 ;
}
return - V_34 ;
case 2 :
if ( V_37 ) {
V_27 = V_24 ? 32 : 24 ;
V_35 = F_25 ( V_27 + 5 , V_27 ) ;
* V_20 &= ~ V_35 ;
* V_20 |= ( ( ( T_2 ) V_21 ) << V_27 ) & V_35 ;
return 0 ;
}
V_31 [ 0 ] &= ~ 1 ;
V_31 [ 1 ] &= ~ 1 ;
V_28 = V_24 ? 37 : 29 ;
V_27 = V_28 - 1 ;
return F_24 ( V_20 , V_21 , V_31 ,
V_27 , V_28 , 2 ) ;
case 3 :
if ( V_21 > 0 && ( V_21 < 24 || V_21 > 26 ) ) {
* V_20 |= ( ( T_2 ) V_38 )
<< V_36 ;
V_37 = 1 ;
}
if ( V_37 ) {
V_27 = V_24 ? 32 : 24 ;
V_35 = F_25 ( V_27 + 5 , V_27 ) ;
* V_20 &= ~ V_35 ;
* V_20 |= ( ( ( T_2 ) V_21 ) << V_27 ) & V_35 ;
return 0 ;
}
V_31 [ 0 ] &= ~ 3 ;
V_31 [ 1 ] &= ~ 3 ;
V_28 = V_24 ? 37 : 29 ;
V_27 = V_28 - 2 ;
return F_24 ( V_20 , V_21 , V_31 ,
V_27 , V_28 , 4 ) ;
default:
return - V_6 ;
}
}
static int F_29 ( T_2 * V_20 , int V_21 , int V_22 ,
int V_23 , bool V_24 , int V_25 , int V_26 )
{
switch ( V_22 ) {
case V_11 :
case V_12 :
case V_13 :
case V_15 :
case V_16 :
case V_17 :
case V_19 :
return F_26 ( V_20 , V_21 , V_22 , V_23 ,
V_24 , V_25 , V_26 ) ;
case V_14 :
return F_27 ( V_20 , V_21 , V_23 ,
V_24 , V_25 , V_26 ) ;
case V_18 :
if ( V_23 != 1 || V_24 )
return - V_6 ;
* V_20 &= ~ F_25 ( 29 , 24 ) ;
* V_20 |= ( ( T_2 ) V_21 << 24 ) & F_25 ( 29 , 24 ) ;
return 0 ;
default:
return - V_6 ;
}
}
int F_30 ( T_1 V_39 , T_2 V_40 ,
T_1 * V_41 , T_2 * V_42 ,
const T_1 * V_43 )
{
const int V_44 = F_31 ( V_39 ) ;
const int V_45 = F_20 ( V_39 ) ;
T_1 V_46 ;
int V_47 ;
if ( V_45 < 0 || V_45 >= 16 )
return - V_6 ;
if ( V_44 == 0 ) {
* V_41 = V_39 ;
* V_42 = V_40 ;
return 0 ;
}
if ( ! V_43 )
return - V_6 ;
V_46 = V_43 [ V_45 ] ;
* V_42 = V_40 ;
V_47 = F_29 ( V_42 , V_44 , V_45 ,
( ( V_46 >> 13 ) & 7 ) , ( ( V_46 >> 12 ) & 1 ) ,
( ( V_46 >> 6 ) & 0x3f ) , ( ( V_46 >> 0 ) & 0x3f ) ) ;
if ( V_47 )
return V_47 ;
* V_41 = F_2 ( V_45 ,
F_32 ( V_39 ) ,
F_33 ( V_39 ) ) ;
return 0 ;
}
