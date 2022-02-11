T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 V_8 ;
T_1 V_9 = 0 ;
if ( ! V_7 ( V_2 , 'P' , & V_8 ) ) {
if ( V_8 . V_10 == 2 ) {
V_9 = F_2 ( V_2 , V_8 . V_11 + 0x20 ) ;
if ( V_9 ) {
* V_3 = F_3 ( V_2 , V_9 + 0 ) ;
switch ( * V_3 ) {
case 0x10 :
case 0x20 :
* V_4 = F_3 ( V_2 , V_9 + 1 ) ;
* V_5 = F_3 ( V_2 , V_9 + 3 ) ;
* V_6 = F_3 ( V_2 , V_9 + 2 ) ;
return V_9 ;
default:
break;
}
}
}
}
return 0 ;
}
T_1
F_4 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_12 * V_13 )
{
T_1 V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
memset ( V_13 , 0x00 , sizeof( * V_13 ) ) ;
switch ( ! ! V_9 * * V_3 ) {
case 0x10 :
V_13 -> V_14 = 0xff ;
V_13 -> V_15 = 0xff ;
V_13 -> V_16 = 0xff ;
break;
case 0x20 :
V_13 -> V_14 = F_3 ( V_2 , V_9 + 0x7 ) ;
V_13 -> V_15 = F_3 ( V_2 , V_9 + 0x8 ) ;
if ( * V_6 >= 0xc )
V_13 -> V_16 = F_3 ( V_2 , V_9 + 0xc ) ;
else
V_13 -> V_16 = 0xff ;
break;
}
return V_9 ;
}
T_1
F_5 ( struct V_1 * V_2 , int V_17 , T_2 * V_3 , T_2 * V_6 )
{
T_2 V_4 , V_5 ;
T_1 V_9 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , V_6 ) ;
if ( V_9 && V_17 < V_5 ) {
V_9 = V_9 + V_4 + ( V_17 * * V_6 ) ;
return V_9 ;
}
return 0 ;
}
T_1
F_6 ( struct V_1 * V_2 , int V_17 , T_2 * V_3 , T_2 * V_6 ,
struct F_5 * V_13 )
{
T_1 V_9 = F_5 ( V_2 , V_17 , V_3 , V_6 ) ;
memset ( V_13 , 0x00 , sizeof( * V_13 ) ) ;
switch ( ! ! V_9 * * V_3 ) {
case 0x10 :
V_13 -> V_18 = 0xff ;
V_13 -> V_19 = F_2 ( V_2 , V_9 + 0x00 ) ;
V_13 -> V_20 = F_2 ( V_2 , V_9 + 0x04 ) ;
V_13 -> V_21 [ 0 ] = F_2 ( V_2 , V_9 + 0x08 ) ;
V_13 -> V_21 [ 1 ] = F_2 ( V_2 , V_9 + 0x0c ) ;
V_13 -> V_21 [ 2 ] = F_2 ( V_2 , V_9 + 0x10 ) ;
break;
case 0x20 :
V_13 -> V_22 = F_3 ( V_2 , V_9 + 0x00 ) ;
V_13 -> V_18 = F_3 ( V_2 , V_9 + 0x01 ) ;
V_13 -> V_19 = F_2 ( V_2 , V_9 + 0x02 ) ;
V_13 -> V_20 = F_2 ( V_2 , V_9 + 0x06 ) ;
V_13 -> V_21 [ 0 ] = F_2 ( V_2 , V_9 + 0x0a ) ;
V_13 -> V_21 [ 1 ] = F_2 ( V_2 , V_9 + 0x0e ) ;
V_13 -> V_21 [ 2 ] = F_2 ( V_2 , V_9 + 0x12 ) ;
V_13 -> V_21 [ 3 ] = F_2 ( V_2 , V_9 + 0x16 ) ;
V_13 -> V_21 [ 4 ] = F_2 ( V_2 , V_9 + 0x1a ) ;
V_13 -> V_21 [ 5 ] = F_2 ( V_2 , V_9 + 0x1e ) ;
break;
}
return V_9 ;
}
