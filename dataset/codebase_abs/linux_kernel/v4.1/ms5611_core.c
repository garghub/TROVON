static bool F_1 ( T_1 * V_1 , T_2 V_2 )
{
int V_3 , V_4 ;
T_3 V_5 = 0 , V_6 = V_1 [ 7 ] & 0x000F ;
V_1 [ 7 ] &= 0xFF00 ;
for ( V_3 = 0 ; V_3 < V_2 * 2 ; V_3 ++ ) {
if ( V_3 % 2 == 1 )
V_5 ^= V_1 [ V_3 >> 1 ] & 0x00FF ;
else
V_5 ^= V_1 [ V_3 >> 1 ] >> 8 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
if ( V_5 & 0x8000 )
V_5 = ( V_5 << 1 ) ^ 0x3000 ;
else
V_5 <<= 1 ;
}
}
V_5 = ( V_5 >> 12 ) & 0x000F ;
return V_6 != 0x0000 && V_5 == V_6 ;
}
static int F_2 ( struct V_7 * V_8 )
{
int V_9 , V_3 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
for ( V_3 = 0 ; V_3 < V_12 ; V_3 ++ ) {
V_9 = V_11 -> V_13 ( & V_8 -> V_14 , V_3 , & V_11 -> V_1 [ V_3 ] ) ;
if ( V_9 < 0 ) {
F_4 ( & V_8 -> V_14 ,
L_1 , V_3 ) ;
return V_9 ;
}
}
if ( ! F_1 ( V_11 -> V_1 , V_12 ) ) {
F_4 ( & V_8 -> V_14 , L_2 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_5 ( struct V_7 * V_8 ,
T_4 * V_16 , T_4 * V_17 )
{
int V_9 ;
T_4 V_18 , V_19 ;
T_5 V_20 , V_21 , V_22 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
V_9 = V_11 -> V_23 ( & V_8 -> V_14 , & V_18 , & V_19 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_8 -> V_14 ,
L_3 ) ;
return V_9 ;
}
V_22 = V_18 - ( V_11 -> V_1 [ 5 ] << 8 ) ;
V_20 = ( ( T_5 ) V_11 -> V_1 [ 2 ] << 16 ) + ( ( V_11 -> V_1 [ 4 ] * V_22 ) >> 7 ) ;
V_21 = ( ( T_5 ) V_11 -> V_1 [ 1 ] << 15 ) + ( ( V_11 -> V_1 [ 3 ] * V_22 ) >> 8 ) ;
V_18 = 2000 + ( ( V_11 -> V_1 [ 6 ] * V_22 ) >> 23 ) ;
if ( V_18 < 2000 ) {
T_5 V_24 , V_25 , V_26 ;
V_26 = ( V_22 * V_22 ) >> 31 ;
V_24 = ( 5 * ( V_18 - 2000 ) * ( V_18 - 2000 ) ) >> 1 ;
V_25 = V_24 >> 1 ;
if ( V_18 < - 1500 ) {
T_5 V_27 = ( V_18 + 1500 ) * ( V_18 + 1500 ) ;
V_24 += 7 * V_27 ;
V_25 += ( 11 * V_27 ) >> 1 ;
}
V_18 -= V_26 ;
V_20 -= V_24 ;
V_21 -= V_25 ;
}
* V_16 = V_18 ;
* V_17 = ( ( ( V_19 * V_21 ) >> 21 ) - V_20 ) >> 15 ;
return 0 ;
}
static int F_6 ( struct V_7 * V_8 )
{
int V_9 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
V_9 = V_11 -> V_28 ( & V_8 -> V_14 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_8 -> V_14 , L_4 ) ;
return V_9 ;
}
F_7 ( 3000 , 4000 ) ;
return 0 ;
}
static int F_8 ( struct V_7 * V_8 ,
struct V_29 const * V_30 ,
int * V_31 , int * V_32 , long V_33 )
{
int V_9 ;
T_4 V_16 , V_17 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
switch ( V_33 ) {
case V_34 :
F_9 ( & V_11 -> V_35 ) ;
V_9 = F_5 ( V_8 ,
& V_16 , & V_17 ) ;
F_10 ( & V_11 -> V_35 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_30 -> type ) {
case V_36 :
* V_31 = V_16 * 10 ;
return V_37 ;
case V_38 :
* V_31 = V_17 / 1000 ;
* V_32 = ( V_17 % 1000 ) * 1000 ;
return V_39 ;
default:
return - V_40 ;
}
}
return - V_40 ;
}
static int F_11 ( struct V_7 * V_8 )
{
int V_9 ;
V_9 = F_6 ( V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_2 ( V_8 ) ;
}
int F_12 ( struct V_7 * V_8 , struct V_41 * V_14 )
{
int V_9 ;
struct V_10 * V_11 = F_3 ( V_8 ) ;
F_13 ( & V_11 -> V_35 ) ;
V_8 -> V_14 . V_42 = V_14 ;
V_8 -> V_43 = V_14 -> V_44 -> V_43 ;
V_8 -> V_45 = & V_46 ;
V_8 -> V_47 = V_48 ;
V_8 -> V_49 = F_14 ( V_48 ) ;
V_8 -> V_50 = V_51 ;
V_9 = F_11 ( V_8 ) ;
if ( V_9 < 0 )
return V_9 ;
return F_15 ( V_14 , V_8 ) ;
}
