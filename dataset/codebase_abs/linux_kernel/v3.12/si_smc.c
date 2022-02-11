static int F_1 ( struct V_1 * V_2 ,
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
unsigned long V_12 ;
int V_13 = 0 ;
T_1 V_14 , V_15 , V_16 , V_17 ;
if ( V_9 & 3 )
return - V_5 ;
if ( ( V_9 + V_11 ) > V_4 )
return - V_5 ;
V_16 = V_9 ;
F_5 ( & V_2 -> V_18 , V_12 ) ;
while ( V_11 >= 4 ) {
V_14 = ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
V_13 = F_1 ( V_2 , V_16 , V_4 ) ;
if ( V_13 )
goto V_19;
F_2 ( V_20 , V_14 ) ;
V_10 += 4 ;
V_11 -= 4 ;
V_16 += 4 ;
}
if ( V_11 > 0 ) {
V_14 = 0 ;
V_13 = F_1 ( V_2 , V_16 , V_4 ) ;
if ( V_13 )
goto V_19;
V_15 = F_6 ( V_20 ) ;
V_17 = 8 * ( 4 - V_11 ) ;
while ( V_11 > 0 ) {
V_14 = ( V_14 << 8 ) + * V_10 ++ ;
V_11 -- ;
}
V_14 <<= V_17 ;
V_14 |= ( V_15 & ~ ( ( ~ 0UL ) << V_17 ) ) ;
V_13 = F_1 ( V_2 , V_16 , V_4 ) ;
if ( V_13 )
goto V_19;
F_2 ( V_20 , V_14 ) ;
}
V_19:
F_7 ( & V_2 -> V_18 , V_12 ) ;
return V_13 ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_21 = F_9 ( V_22 ) ;
V_21 &= ~ V_23 ;
F_10 ( V_22 , V_21 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_21 ;
F_6 ( V_24 ) ;
F_6 ( V_24 ) ;
F_6 ( V_24 ) ;
F_6 ( V_24 ) ;
V_21 = F_9 ( V_22 ) ;
V_21 |= V_23 ;
F_10 ( V_22 , V_21 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
static T_2 V_14 [] = { 0x0E , 0x00 , 0x40 , 0x40 } ;
return F_4 ( V_2 , 0x0 , V_14 , 4 , sizeof( V_14 ) + 1 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
T_1 V_21 = F_9 ( V_25 ) ;
V_21 |= V_26 ;
F_10 ( V_25 , V_21 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_21 = F_9 ( V_25 ) ;
V_21 &= ~ V_26 ;
F_10 ( V_25 , V_21 ) ;
}
bool F_15 ( struct V_1 * V_2 )
{
T_1 V_27 = F_9 ( V_22 ) ;
T_1 V_28 = F_9 ( V_25 ) ;
if ( ! ( V_27 & V_23 ) && ! ( V_28 & V_26 ) )
return true ;
return false ;
}
T_3 F_16 ( struct V_1 * V_2 , T_4 V_29 )
{
T_1 V_21 ;
int V_30 ;
if ( ! F_15 ( V_2 ) )
return V_31 ;
F_2 ( V_32 , V_29 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_33 ; V_30 ++ ) {
V_21 = F_6 ( V_34 ) ;
if ( V_21 != 0 )
break;
F_17 ( 1 ) ;
}
V_21 = F_6 ( V_34 ) ;
return ( T_3 ) V_21 ;
}
T_3 F_18 ( struct V_1 * V_2 )
{
T_1 V_21 ;
int V_30 ;
if ( ! F_15 ( V_2 ) )
return V_35 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_33 ; V_30 ++ ) {
V_21 = F_9 ( V_25 ) ;
if ( ( V_21 & V_36 ) == 0 )
break;
F_17 ( 1 ) ;
}
return V_35 ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_4 )
{
unsigned long V_12 ;
T_1 V_37 ;
T_1 V_38 ;
const T_2 * V_10 ;
T_1 V_14 ;
if ( ! V_2 -> V_39 )
return - V_5 ;
switch ( V_2 -> V_40 ) {
case V_41 :
V_37 = V_42 ;
V_38 = V_43 ;
break;
case V_44 :
V_37 = V_45 ;
V_38 = V_46 ;
break;
case V_47 :
V_37 = V_48 ;
V_38 = V_49 ;
break;
case V_50 :
V_37 = V_51 ;
V_38 = V_52 ;
break;
case V_53 :
V_37 = V_54 ;
V_38 = V_55 ;
break;
default:
F_20 ( L_1 ) ;
F_21 () ;
}
if ( V_38 & 3 )
return - V_5 ;
V_10 = ( const T_2 * ) V_2 -> V_39 -> V_14 ;
F_5 ( & V_2 -> V_18 , V_12 ) ;
F_2 ( V_6 , V_37 ) ;
F_3 ( V_7 , V_8 , ~ V_8 ) ;
while ( V_38 >= 4 ) {
V_14 = ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
F_2 ( V_20 , V_14 ) ;
V_10 += 4 ;
V_38 -= 4 ;
}
F_3 ( V_7 , 0 , ~ V_8 ) ;
F_7 ( & V_2 -> V_18 , V_12 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_56 , T_1 V_4 )
{
unsigned long V_12 ;
int V_13 ;
F_5 ( & V_2 -> V_18 , V_12 ) ;
V_13 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_13 == 0 )
* V_56 = F_6 ( V_20 ) ;
F_7 ( & V_2 -> V_18 , V_12 ) ;
return V_13 ;
}
int F_23 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_56 , T_1 V_4 )
{
unsigned long V_12 ;
int V_13 ;
F_5 ( & V_2 -> V_18 , V_12 ) ;
V_13 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_13 == 0 )
F_2 ( V_20 , V_56 ) ;
F_7 ( & V_2 -> V_18 , V_12 ) ;
return V_13 ;
}
