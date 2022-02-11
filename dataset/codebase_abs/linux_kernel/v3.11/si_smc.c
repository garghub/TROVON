int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
if ( V_3 & 3 )
return - V_5 ;
if ( ( V_3 + 3 ) > V_4 )
return - V_5 ;
F_2 ( V_6 , V_3 ) ;
F_3 ( V_7 , 0 , ~ V_8 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 ,
T_1 V_9 ,
const T_2 * V_10 , T_1 V_11 , T_1 V_4 )
{
int V_12 ;
T_1 V_13 , V_14 , V_15 , V_16 ;
if ( V_9 & 3 )
return - V_5 ;
if ( ( V_9 + V_11 ) > V_4 )
return - V_5 ;
V_15 = V_9 ;
while ( V_11 >= 4 ) {
V_13 = ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
V_12 = F_1 ( V_2 , V_15 , V_4 ) ;
if ( V_12 )
return V_12 ;
F_2 ( V_17 , V_13 ) ;
V_10 += 4 ;
V_11 -= 4 ;
V_15 += 4 ;
}
if ( V_11 > 0 ) {
V_13 = 0 ;
V_12 = F_1 ( V_2 , V_15 , V_4 ) ;
if ( V_12 )
return V_12 ;
V_14 = F_5 ( V_17 ) ;
V_16 = 8 * ( 4 - V_11 ) ;
while ( V_11 > 0 ) {
V_13 = ( V_13 << 8 ) + * V_10 ++ ;
V_11 -- ;
}
V_13 <<= V_16 ;
V_13 |= ( V_14 & ~ ( ( ~ 0UL ) << V_16 ) ) ;
V_12 = F_1 ( V_2 , V_15 , V_4 ) ;
if ( V_12 )
return V_12 ;
F_2 ( V_17 , V_13 ) ;
}
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_18 = F_7 ( V_19 ) ;
V_18 &= ~ V_20 ;
F_8 ( V_19 , V_18 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
T_1 V_18 ;
F_5 ( V_21 ) ;
F_5 ( V_21 ) ;
F_5 ( V_21 ) ;
F_5 ( V_21 ) ;
V_18 = F_7 ( V_19 ) ;
V_18 |= V_20 ;
F_8 ( V_19 , V_18 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
static T_2 V_13 [] = { 0x0E , 0x00 , 0x40 , 0x40 } ;
return F_4 ( V_2 , 0x0 , V_13 , 4 , sizeof( V_13 ) + 1 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_18 = F_7 ( V_22 ) ;
V_18 |= V_23 ;
F_8 ( V_22 , V_18 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
T_1 V_18 = F_7 ( V_22 ) ;
V_18 &= ~ V_23 ;
F_8 ( V_22 , V_18 ) ;
}
bool F_13 ( struct V_1 * V_2 )
{
T_1 V_24 = F_7 ( V_19 ) ;
T_1 V_25 = F_7 ( V_22 ) ;
if ( ! ( V_24 & V_20 ) && ! ( V_25 & V_23 ) )
return true ;
return false ;
}
T_3 F_14 ( struct V_1 * V_2 , T_4 V_26 )
{
T_1 V_18 ;
int V_27 ;
if ( ! F_13 ( V_2 ) )
return V_28 ;
F_2 ( V_29 , V_26 ) ;
for ( V_27 = 0 ; V_27 < V_2 -> V_30 ; V_27 ++ ) {
V_18 = F_5 ( V_31 ) ;
if ( V_18 != 0 )
break;
F_15 ( 1 ) ;
}
V_18 = F_5 ( V_31 ) ;
return ( T_3 ) V_18 ;
}
T_3 F_16 ( struct V_1 * V_2 )
{
T_1 V_18 ;
int V_27 ;
if ( ! F_13 ( V_2 ) )
return V_32 ;
for ( V_27 = 0 ; V_27 < V_2 -> V_30 ; V_27 ++ ) {
V_18 = F_7 ( V_22 ) ;
if ( ( V_18 & V_33 ) == 0 )
break;
F_15 ( 1 ) ;
}
return V_32 ;
}
int F_17 ( struct V_1 * V_2 , T_1 V_4 )
{
T_1 V_34 ;
T_1 V_35 ;
const T_2 * V_10 ;
T_1 V_13 ;
if ( ! V_2 -> V_36 )
return - V_5 ;
switch ( V_2 -> V_37 ) {
case V_38 :
V_34 = V_39 ;
V_35 = V_40 ;
break;
case V_41 :
V_34 = V_42 ;
V_35 = V_43 ;
break;
case V_44 :
V_34 = V_45 ;
V_35 = V_46 ;
break;
case V_47 :
V_34 = V_48 ;
V_35 = V_49 ;
break;
case V_50 :
V_34 = V_51 ;
V_35 = V_52 ;
break;
default:
F_18 ( L_1 ) ;
F_19 () ;
}
if ( V_35 & 3 )
return - V_5 ;
V_10 = ( const T_2 * ) V_2 -> V_36 -> V_13 ;
F_2 ( V_6 , V_34 ) ;
F_3 ( V_7 , V_8 , ~ V_8 ) ;
while ( V_35 >= 4 ) {
V_13 = ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
F_2 ( V_17 , V_13 ) ;
V_10 += 4 ;
V_35 -= 4 ;
}
F_3 ( V_7 , 0 , ~ V_8 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_53 , T_1 V_4 )
{
int V_12 ;
V_12 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_12 )
return V_12 ;
* V_53 = F_5 ( V_17 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_53 , T_1 V_4 )
{
int V_12 ;
V_12 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_12 )
return V_12 ;
F_2 ( V_17 , V_53 ) ;
return 0 ;
}
