T_1
F_1 ( struct V_1 * V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 , T_2 * V_7 , T_2 * V_8 )
{
struct V_9 V_10 ;
T_1 V_11 = 0 ;
if ( ! V_9 ( V_2 , 'P' , & V_10 ) ) {
if ( V_10 . V_12 == 2 && V_10 . V_13 >= 0x38 )
V_11 = F_2 ( V_2 , V_10 . V_14 + 0x34 ) ;
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
return 0 ;
}
T_1
F_4 ( struct V_1 * V_2 , int V_15 , T_2 * V_3 , T_2 * V_4 )
{
T_2 V_5 , V_6 , V_7 , V_8 ;
T_1 V_16 = F_1 ( V_2 , V_3 , V_4 , & V_5 , & V_6 , & V_7 , & V_8 ) ;
if ( V_16 && V_15 < V_5 ) {
V_16 = V_16 + * V_4 + ( V_15 * V_6 ) ;
* V_4 = V_6 ;
return V_16 ;
}
return 0 ;
}
T_1
F_5 ( struct V_1 * V_2 , int V_15 , T_2 * V_3 , T_2 * V_4 ,
struct V_17 * V_18 )
{
T_1 V_16 = F_4 ( V_2 , V_15 , V_3 , V_4 ) ;
memset ( V_18 , 0x00 , sizeof( * V_18 ) ) ;
if ( V_16 ) {
V_18 -> V_19 = ( F_6 ( V_2 , V_16 + 0x00 ) & 0x01e0 ) >> 5 ;
V_18 -> V_20 = F_3 ( V_2 , V_16 + 0x03 ) ;
}
return V_16 ;
}
T_1
F_7 ( struct V_1 * V_2 , T_2 V_19 , T_2 * V_3 , T_2 * V_4 ,
struct V_17 * V_18 )
{
T_1 V_16 , V_15 = 0 ;
while ( ( V_16 = F_5 ( V_2 , V_15 ++ , V_3 , V_4 , V_18 ) ) ) {
if ( V_18 -> V_19 == V_19 )
break;
}
return V_16 ;
}
T_1
F_8 ( struct V_1 * V_2 , int V_15 , T_2 * V_3 , T_2 * V_4 )
{
T_2 V_5 , V_6 , V_7 , V_8 ;
T_1 V_16 = F_1 ( V_2 , V_3 , V_4 , & V_5 , & V_6 , & V_7 , & V_8 ) ;
if ( V_16 && V_15 < V_7 ) {
V_16 = V_16 + * V_4 + ( V_5 * V_6 ) + ( V_15 * V_8 ) ;
* V_4 = V_8 ;
return V_16 ;
}
return 0 ;
}
T_1
F_9 ( struct V_1 * V_2 , int V_15 , T_2 * V_3 , T_2 * V_4 ,
struct V_21 * V_18 )
{
T_1 V_16 = F_8 ( V_2 , V_15 , V_3 , V_4 ) ;
memset ( V_18 , 0x00 , sizeof( * V_18 ) ) ;
if ( V_16 ) {
V_18 -> V_22 = F_6 ( V_2 , V_16 + 0x00 ) * 1000 ;
V_18 -> V_23 [ 0 ] = F_3 ( V_2 , V_16 + 0x02 ) ;
V_18 -> V_23 [ 1 ] = F_3 ( V_2 , V_16 + 0x03 ) ;
V_18 -> V_24 = F_3 ( V_2 , V_16 + 0x04 ) ;
}
return V_16 ;
}
