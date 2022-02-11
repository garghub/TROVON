static T_1 F_1 ( T_2 * V_1 , T_3 * V_2 ,
T_3 V_3 ,
const T_4 * V_4 )
{
int V_5 ;
T_3 V_6 = V_4 -> V_6 ;
for(; ; ) {
if( V_3 > V_6 ) {
if( * V_2 ) {
F_2 ( V_1 , V_4 -> V_7 << ( V_3 - V_6 ) ) ;
} else {
V_5 = F_3 ( V_1 , V_4 -> V_7 << ( V_3 - V_6 ) ) ;
if( V_5 != 0 ) {
return V_5 ;
}
* V_2 = F_4 ( V_1 ) ;
}
V_3 -= V_6 ;
break;
}
if( * V_2 ) {
F_5 ( V_1 , V_4 -> V_7 >> ( V_6 - V_3 ) ) ;
-- * V_2 ;
} else {
V_5 = F_6 ( V_1 , V_4 -> V_7 >> ( V_6 - V_3 ) ) ;
if( V_5 != 0 ) {
return V_5 ;
}
* V_2 = F_4 ( V_1 ) ;
}
V_6 -= V_3 ;
V_3 = 8 ;
if( V_6 == 0 ) {
break;
}
if( * V_2 ) {
F_7 ( V_1 , 0 ) ;
} else {
V_5 = F_8 ( V_1 , 0 ) ;
if( V_5 != 0 ) {
return V_5 ;
}
* V_2 = F_4 ( V_1 ) ;
}
}
return ( T_1 ) V_3 ;
}
T_3 F_9 ( const T_5 * V_8 , T_3 V_9 )
{
T_3 V_10 ;
T_3 V_6 = 0 ;
for( V_10 = 0 ; V_10 < V_9 ; ++ V_10 ) {
V_6 += V_11 [ V_8 [ V_10 ] ] . V_6 ;
}
return ( V_6 + 7 ) / 8 ;
}
int F_10 ( T_2 * V_1 ,
const T_5 * V_8 , T_3 V_12 )
{
int V_5 ;
T_1 V_3 = 8 ;
T_3 V_10 ;
T_3 V_13 ;
V_13 = F_4 ( V_1 ) ;
for( V_10 = 0 ; V_10 < V_12 ; ++ V_10 ) {
const T_4 * V_4 = & V_11 [ V_8 [ V_10 ] ] ;
if( V_3 == 8 ) {
if( V_13 ) {
F_7 ( V_1 , 0 ) ;
} else {
V_5 = F_8 ( V_1 , 0 ) ;
if( V_5 != 0 ) {
return V_5 ;
}
V_13 = F_4 ( V_1 ) ;
}
}
V_3 = F_1 ( V_1 , & V_13 , V_3 , V_4 ) ;
if( V_3 < 0 ) {
return ( int ) V_3 ;
}
}
if( V_3 < 8 ) {
const T_4 * V_4 = & V_11 [ 256 ] ;
if( V_13 ) {
F_5 ( V_1 , V_4 -> V_7 >> ( V_4 -> V_6 - V_3 ) ) ;
} else {
V_5 = F_6 ( V_1 , V_4 -> V_7 >> ( V_4 -> V_6 - V_3 ) ) ;
if( V_5 != 0 ) {
return V_5 ;
}
}
}
return 0 ;
}
void F_11 ( T_6 * V_14 )
{
V_14 -> V_15 = 0 ;
V_14 -> V_16 = 1 ;
}
T_1 F_12 ( T_6 * V_14 ,
T_2 * V_1 ,
const T_5 * V_8 , T_3 V_12 , int V_17 )
{
T_3 V_10 , V_18 ;
int V_5 ;
T_3 V_13 ;
V_13 = F_4 ( V_1 ) ;
for( V_10 = 0 ; V_10 < V_12 ; ++ V_10 ) {
T_5 V_19 = V_8 [ V_10 ] >> 4 ;
for( V_18 = 0 ; V_18 < 2 ; ++ V_18 ) {
const T_7 * V_20 ;
V_20 = & V_21 [ V_14 -> V_15 ] [ V_19 ] ;
if( V_20 -> V_22 & V_23 ) {
return V_24 ;
}
if( V_20 -> V_22 & V_25 ) {
if( V_13 ) {
F_13 ( V_1 , V_20 -> V_4 ) ;
-- V_13 ;
} else {
V_5 = F_14 ( V_1 , V_20 -> V_4 ) ;
if( V_5 != 0 ) {
return V_5 ;
}
V_13 = F_4 ( V_1 ) ;
}
}
V_14 -> V_15 = V_20 -> V_15 ;
V_14 -> V_16 = ( V_20 -> V_22 & V_26 ) != 0 ;
V_19 = V_8 [ V_10 ] & 0xf ;
}
}
if( V_17 && ! V_14 -> V_16 ) {
return V_24 ;
}
return ( T_1 ) V_10 ;
}
