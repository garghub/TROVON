T_1
F_1 ( struct V_1 * V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 , T_2 * V_7 , T_2 * V_8 )
{
struct V_9 V_10 ;
T_1 V_11 = 0x00000000 ;
if ( ! V_9 ( V_2 , 'M' , & V_10 ) ) {
if ( V_10 . V_12 == 2 && V_10 . V_13 > 0x0c )
V_11 = F_2 ( V_2 , V_10 . V_14 + 0x09 ) ;
if ( V_11 ) {
* V_3 = F_3 ( V_2 , V_11 + 0x00 ) ;
switch ( * V_3 ) {
case 0x10 :
* V_4 = F_3 ( V_2 , V_11 + 0x01 ) ;
* V_6 = F_3 ( V_2 , V_11 + 0x02 ) ;
* V_8 = F_3 ( V_2 , V_11 + 0x03 ) ;
* V_7 = 1 ;
* V_5 = F_3 ( V_2 , V_11 + 0x04 ) ;
return V_11 ;
default:
break;
}
}
}
return 0x00000000 ;
}
T_1
F_4 ( struct V_1 * V_2 , int V_15 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 V_7 , V_8 ;
T_1 V_11 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , & V_7 , & V_8 ) ;
if ( V_11 && V_15 < * V_5 ) {
V_11 = V_11 + * V_4 + V_15 * ( * V_6 + ( V_7 * V_8 ) ) ;
* V_4 = * V_6 ;
* V_5 = V_7 ;
* V_6 = V_8 ;
return V_11 ;
}
return 0x00000000 ;
}
T_1
F_5 ( struct V_1 * V_2 , int V_15 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_16 * V_17 )
{
T_1 V_11 = F_4 ( V_2 , V_15 , V_3 , V_4 , V_5 , V_6 ) ;
memset ( V_17 , 0x00 , sizeof( * V_17 ) ) ;
switch ( ! ! V_11 * * V_3 ) {
case 0x10 :
V_17 -> V_18 = ( F_3 ( V_2 , V_11 + 0x00 ) & 0x40 ) >> 6 ;
V_17 -> V_19 = F_3 ( V_2 , V_11 + 0x00 ) & 0x3f ;
V_17 -> V_20 = F_3 ( V_2 , V_11 + 0x01 ) ;
V_17 -> V_21 = ( F_3 ( V_2 , V_11 + 0x02 ) & 0x40 ) >> 6 ;
V_17 -> V_22 = F_3 ( V_2 , V_11 + 0x02 ) & 0x07 ;
V_17 -> V_23 = F_3 ( V_2 , V_11 + 0x03 ) ;
return V_11 ;
default:
break;
}
return 0x00000000 ;
}
T_1
F_6 ( struct V_1 * V_2 , int V_24 , int V_15 , T_2 * V_3 , T_2 * V_4 )
{
T_2 V_5 , V_6 ;
T_1 V_11 = F_4 ( V_2 , V_24 , V_3 , V_4 , & V_5 , & V_6 ) ;
if ( V_11 && V_15 < V_5 ) {
V_11 = V_11 + * V_4 + V_15 * V_6 ;
* V_4 = V_6 ;
return V_11 ;
}
return 0x00000000 ;
}
T_1
F_7 ( struct V_1 * V_2 , int V_24 , int V_15 , T_2 * V_3 , T_2 * V_4 ,
struct V_25 * V_17 )
{
struct V_16 V_26 ;
T_2 V_5 , V_6 ;
T_1 V_11 = F_5 ( V_2 , V_24 , V_3 , V_4 , & V_5 , & V_6 , & V_26 ) ;
if ( V_11 ) {
T_1 V_27 , V_11 = F_6 ( V_2 , V_24 , V_15 , V_3 , V_4 ) ;
memset ( V_17 , 0x00 , sizeof( * V_17 ) ) ;
switch ( ! ! V_11 * * V_3 ) {
case 0x10 :
for ( V_27 = 0 ; V_27 < F_8 ( V_17 -> V_11 ) ; V_27 ++ ) {
T_1 V_19 = ( V_27 % V_26 . V_20 ) * V_26 . V_19 ;
T_1 V_28 = ( 1ULL << V_26 . V_19 ) - 1 ;
T_3 V_29 = V_19 / 8 ;
T_2 V_30 = V_19 % 8 ;
V_17 -> V_11 [ V_27 ] = F_2 ( V_2 , V_11 + V_29 ) ;
V_17 -> V_11 [ V_27 ] = V_17 -> V_11 [ V_27 ] >> V_30 ;
V_17 -> V_11 [ V_27 ] = V_17 -> V_11 [ V_27 ] & V_28 ;
}
return V_11 ;
default:
break;
}
}
return 0x00000000 ;
}
