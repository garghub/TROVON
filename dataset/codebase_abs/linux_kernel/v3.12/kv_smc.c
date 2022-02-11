int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
T_1 V_5 = 0 ;
F_2 ( V_6 , V_3 & V_7 ) ;
for ( V_4 = 0 ; V_4 < V_2 -> V_8 ; V_4 ++ ) {
if ( ( F_3 ( V_9 ) & V_10 ) != 0 )
break;
F_4 ( 1 ) ;
}
V_5 = F_3 ( V_9 ) & V_10 ;
if ( V_5 != 1 ) {
if ( V_5 == 0xFF )
return - V_11 ;
else if ( V_5 == 0xFE )
return - V_11 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 , T_1 * V_12 )
{
int V_13 ;
V_13 = F_1 ( V_2 , V_14 ) ;
if ( V_13 == 0 )
* V_12 = F_6 ( V_15 ) ;
return V_13 ;
}
int F_7 ( struct V_1 * V_2 ,
T_2 V_16 , T_1 V_17 )
{
F_2 ( V_18 , V_17 ) ;
return F_1 ( V_2 , V_16 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_19 , T_1 V_20 )
{
if ( V_19 & 3 )
return - V_11 ;
if ( ( V_19 + 3 ) > V_20 )
return - V_11 ;
F_2 ( V_21 , V_19 ) ;
F_9 ( V_22 , 0 , ~ V_23 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , T_1 V_19 ,
T_1 * V_24 , T_1 V_20 )
{
int V_13 ;
V_13 = F_8 ( V_2 , V_19 , V_20 ) ;
if ( V_13 )
return V_13 ;
* V_24 = F_3 ( V_25 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , bool V_26 )
{
if ( V_26 )
return F_1 ( V_2 , V_27 ) ;
else
return F_1 ( V_2 , V_28 ) ;
}
int F_12 ( struct V_1 * V_2 , bool V_26 )
{
if ( V_26 )
return F_1 ( V_2 , V_29 ) ;
else
return F_1 ( V_2 , V_30 ) ;
}
int F_13 ( struct V_1 * V_2 ,
T_1 V_31 ,
const T_3 * V_32 , T_1 V_33 , T_1 V_20 )
{
int V_13 ;
T_1 V_34 , V_35 , V_36 , V_37 , V_38 , V_39 , V_40 ;
if ( ( V_31 + V_33 ) > V_20 )
return - V_11 ;
V_36 = V_31 ;
V_38 = V_36 & 3 ;
if ( V_38 != 0 ) {
V_36 -= V_38 ;
V_13 = F_8 ( V_2 , V_36 , V_20 ) ;
if ( V_13 )
return V_13 ;
V_35 = F_3 ( V_25 ) ;
V_34 = 0 ;
V_40 = 0 ;
V_39 = 4 ;
while ( V_39 > 0 ) {
if ( V_38 > 0 ) {
V_40 = ( V_40 << 8 ) | 0xff ;
V_38 -- ;
} else if ( V_33 > 0 ) {
V_34 = ( V_34 << 8 ) + * V_32 ++ ;
V_33 -- ;
V_40 <<= 8 ;
} else {
V_34 <<= 8 ;
V_40 = ( V_40 << 8 ) | 0xff ;
}
V_39 -- ;
}
V_34 |= V_35 & V_40 ;
V_13 = F_8 ( V_2 , V_36 , V_20 ) ;
if ( V_13 )
return V_13 ;
F_2 ( V_25 , V_34 ) ;
V_36 += 4 ;
}
while ( V_33 >= 4 ) {
V_34 = ( V_32 [ 0 ] << 24 ) + ( V_32 [ 1 ] << 16 ) + ( V_32 [ 2 ] << 8 ) + V_32 [ 3 ] ;
V_13 = F_8 ( V_2 , V_36 , V_20 ) ;
if ( V_13 )
return V_13 ;
F_2 ( V_25 , V_34 ) ;
V_32 += 4 ;
V_33 -= 4 ;
V_36 += 4 ;
}
if ( V_33 > 0 ) {
V_34 = 0 ;
V_13 = F_8 ( V_2 , V_36 , V_20 ) ;
if ( V_13 )
return V_13 ;
V_35 = F_3 ( V_25 ) ;
V_37 = 8 * ( 4 - V_33 ) ;
while ( V_33 > 0 ) {
V_34 = ( V_34 << 8 ) + * V_32 ++ ;
V_33 -- ;
}
V_34 <<= V_37 ;
V_34 |= ( V_35 & ~ ( ( ~ 0UL ) << V_37 ) ) ;
V_13 = F_8 ( V_2 , V_36 , V_20 ) ;
if ( V_13 )
return V_13 ;
F_2 ( V_25 , V_34 ) ;
}
return 0 ;
}
