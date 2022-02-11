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
T_1 V_13 , V_14 ;
T_1 V_15 ;
T_1 V_16 ;
int V_17 = 0 ;
if ( V_9 & 3 )
return - V_5 ;
if ( ( V_9 + V_11 ) > V_4 )
return - V_5 ;
V_15 = V_9 ;
F_5 ( & V_2 -> V_18 , V_12 ) ;
while ( V_11 >= 4 ) {
V_13 = ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
V_17 = F_1 ( V_2 , V_15 , V_4 ) ;
if ( V_17 )
goto V_19;
F_2 ( V_20 , V_13 ) ;
V_10 += 4 ;
V_11 -= 4 ;
V_15 += 4 ;
}
if ( V_11 > 0 ) {
V_13 = 0 ;
V_17 = F_1 ( V_2 , V_15 , V_4 ) ;
if ( V_17 )
goto V_19;
V_14 = F_6 ( V_20 ) ;
V_16 = 8 * ( 4 - V_11 ) ;
while ( V_11 > 0 ) {
V_13 = ( V_13 << 8 ) + * V_10 ++ ;
V_11 -- ;
}
V_13 <<= V_16 ;
V_13 |= ( V_14 & ~ ( ( ~ 0UL ) << V_16 ) ) ;
V_17 = F_1 ( V_2 , V_15 , V_4 ) ;
if ( V_17 )
goto V_19;
F_2 ( V_20 , V_13 ) ;
}
V_19:
F_7 ( & V_2 -> V_18 , V_12 ) ;
return V_17 ;
}
void F_8 ( struct V_1 * V_2 )
{
T_1 V_21 = F_9 ( V_22 ) ;
V_21 &= ~ V_23 ;
F_10 ( V_22 , V_21 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_21 = F_9 ( V_22 ) ;
V_21 |= V_23 ;
F_10 ( V_22 , V_21 ) ;
}
int F_12 ( struct V_1 * V_2 )
{
static T_2 V_13 [] = { 0xE0 , 0x00 , 0x80 , 0x40 } ;
return F_4 ( V_2 , 0x0 , V_13 , 4 , sizeof( V_13 ) + 1 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
T_1 V_21 = F_9 ( V_24 ) ;
V_21 |= V_25 ;
F_10 ( V_24 , V_21 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_21 = F_9 ( V_24 ) ;
V_21 &= ~ V_25 ;
F_10 ( V_24 , V_21 ) ;
}
bool F_15 ( struct V_1 * V_2 )
{
T_1 V_26 = F_9 ( V_24 ) ;
T_1 V_27 = F_9 ( V_28 ) ;
if ( ! ( V_26 & V_25 ) && ( 0x20100 <= V_27 ) )
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
V_21 = F_9 ( V_24 ) ;
if ( ( V_21 & V_36 ) == 0 )
break;
F_17 ( 1 ) ;
}
return V_35 ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_4 )
{
const struct V_37 * V_38 ;
unsigned long V_12 ;
T_1 V_39 ;
T_1 V_40 ;
const T_2 * V_10 ;
T_1 V_13 ;
if ( ! V_2 -> V_41 . V_42 )
return - V_5 ;
V_38 = ( const struct V_37 * ) V_2 -> V_41 . V_42 -> V_13 ;
F_20 ( & V_38 -> V_43 ) ;
V_2 -> V_41 . V_44 = F_21 ( V_38 -> V_43 . V_45 ) ;
V_39 = F_21 ( V_38 -> V_46 ) ;
V_40 = F_21 ( V_38 -> V_43 . V_47 ) ;
V_10 = ( const T_2 * )
( V_2 -> V_41 . V_42 -> V_13 + F_21 ( V_38 -> V_43 . V_48 ) ) ;
if ( V_40 & 3 )
return - V_5 ;
F_5 ( & V_2 -> V_18 , V_12 ) ;
F_2 ( V_6 , V_39 ) ;
F_3 ( V_7 , V_8 ,
~ V_8 ) ;
while ( V_40 >= 4 ) {
V_13 = ( V_10 [ 0 ] << 24 ) | ( V_10 [ 1 ] << 16 ) | ( V_10 [ 2 ] << 8 ) | V_10 [ 3 ] ;
F_2 ( V_20 , V_13 ) ;
V_10 += 4 ;
V_40 -= 4 ;
}
F_3 ( V_7 , 0 , ~ V_8 ) ;
F_7 ( & V_2 -> V_18 , V_12 ) ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_49 , T_1 V_4 )
{
unsigned long V_12 ;
int V_17 ;
F_5 ( & V_2 -> V_18 , V_12 ) ;
V_17 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_17 == 0 )
* V_49 = F_6 ( V_20 ) ;
F_7 ( & V_2 -> V_18 , V_12 ) ;
return V_17 ;
}
int F_23 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_49 , T_1 V_4 )
{
unsigned long V_12 ;
int V_17 ;
F_5 ( & V_2 -> V_18 , V_12 ) ;
V_17 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_17 == 0 )
F_2 ( V_20 , V_49 ) ;
F_7 ( & V_2 -> V_18 , V_12 ) ;
return V_17 ;
}
