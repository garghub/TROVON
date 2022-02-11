T_1
F_1 ( struct V_1 * V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 , T_2 * V_7 , T_2 * V_8 )
{
struct V_9 V_10 ;
T_1 V_11 = 0x0000 ;
if ( ! V_9 ( V_2 , 'P' , & V_10 ) ) {
if ( V_10 . V_12 == 2 )
V_11 = F_2 ( V_2 , V_10 . V_13 + 0x34 ) ;
if ( V_11 ) {
* V_3 = F_3 ( V_2 , V_11 + 0 ) ;
switch ( * V_3 ) {
case 0x10 :
* V_4 = F_3 ( V_2 , V_11 + 1 ) ;
* V_5 = F_3 ( V_2 , V_11 + 3 ) ;
* V_6 = F_3 ( V_2 , V_11 + 2 ) ;
* V_7 = F_3 ( V_2 , V_11 + 5 ) ;
* V_8 = F_3 ( V_2 , V_11 + 4 ) ;
return V_11 ;
default:
break;
}
}
}
return 0x0000 ;
}
T_1
F_4 ( struct V_1 * V_2 , int V_14 , T_2 * V_3 , T_2 * V_4 )
{
T_2 V_5 , V_6 , V_7 , V_8 ;
T_1 V_15 = F_1 ( V_2 , V_3 , V_4 , & V_5 , & V_6 , & V_7 , & V_8 ) ;
if ( V_15 && V_14 < V_5 ) {
V_15 = V_15 + * V_4 + ( V_14 * V_6 ) ;
* V_4 = V_6 ;
return V_15 ;
}
return 0x0000 ;
}
T_1
F_5 ( struct V_1 * V_2 , int V_14 , T_2 * V_3 , T_2 * V_4 ,
struct V_16 * V_17 )
{
T_1 V_15 = F_4 ( V_2 , V_14 , V_3 , V_4 ) ;
memset ( V_17 , 0x00 , sizeof( * V_17 ) ) ;
if ( V_15 ) {
V_17 -> V_18 = ( F_2 ( V_2 , V_15 + 0x00 ) & 0x01e0 ) >> 5 ;
V_17 -> V_19 = F_3 ( V_2 , V_15 + 0x03 ) ;
}
return V_15 ;
}
T_1
F_6 ( struct V_1 * V_2 , T_2 V_18 , T_2 * V_3 , T_2 * V_4 ,
struct V_16 * V_17 )
{
T_3 V_15 , V_14 = 0 ;
while ( ( V_15 = F_5 ( V_2 , V_14 ++ , V_3 , V_4 , V_17 ) ) ) {
if ( V_17 -> V_18 == V_18 )
break;
}
return V_15 ;
}
T_1
F_7 ( struct V_1 * V_2 , int V_14 , T_2 * V_3 , T_2 * V_4 )
{
T_2 V_5 , V_6 , V_7 , V_8 ;
T_1 V_15 = F_1 ( V_2 , V_3 , V_4 , & V_5 , & V_6 , & V_7 , & V_8 ) ;
if ( V_15 && V_14 < V_7 ) {
V_15 = V_15 + * V_4 + ( V_5 * V_6 ) + ( V_14 * V_8 ) ;
* V_4 = V_8 ;
return V_15 ;
}
return 0x0000 ;
}
T_1
F_8 ( struct V_1 * V_2 , int V_14 , T_2 * V_3 , T_2 * V_4 ,
struct V_20 * V_17 )
{
T_1 V_15 = F_7 ( V_2 , V_14 , V_3 , V_4 ) ;
memset ( V_17 , 0x00 , sizeof( * V_17 ) ) ;
if ( V_15 ) {
V_17 -> V_21 = F_2 ( V_2 , V_15 + 0x00 ) * 1000 ;
V_17 -> V_22 [ 0 ] = F_3 ( V_2 , V_15 + 0x02 ) ;
V_17 -> V_22 [ 1 ] = F_3 ( V_2 , V_15 + 0x03 ) ;
V_17 -> V_23 = F_3 ( V_2 , V_15 + 0x04 ) ;
}
return V_15 ;
}
