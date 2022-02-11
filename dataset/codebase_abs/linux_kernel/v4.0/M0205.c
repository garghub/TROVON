T_1
F_1 ( struct V_1 * V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 , T_2 * V_7 , T_2 * V_8 )
{
struct V_9 V_10 ;
T_1 V_11 = 0x00000000 ;
if ( ! V_9 ( V_2 , 'M' , & V_10 ) ) {
if ( V_10 . V_12 == 2 && V_10 . V_13 > 0x08 )
V_11 = F_2 ( V_2 , V_10 . V_14 + 0x05 ) ;
if ( V_11 ) {
* V_3 = F_3 ( V_2 , V_11 + 0x00 ) ;
switch ( * V_3 ) {
case 0x10 :
* V_4 = F_3 ( V_2 , V_11 + 0x01 ) ;
* V_6 = F_3 ( V_2 , V_11 + 0x02 ) ;
* V_8 = F_3 ( V_2 , V_11 + 0x03 ) ;
* V_7 = F_3 ( V_2 , V_11 + 0x04 ) ;
* V_5 = F_3 ( V_2 , V_11 + 0x05 ) ;
return V_11 ;
default:
break;
}
}
}
return 0x00000000 ;
}
T_1
F_4 ( struct V_1 * V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 , T_2 * V_7 , T_2 * V_8 ,
struct V_15 * V_16 )
{
T_1 V_11 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ) ;
memset ( V_16 , 0x00 , sizeof( * V_16 ) ) ;
switch ( ! ! V_11 * * V_3 ) {
case 0x10 :
V_16 -> V_17 = F_5 ( V_2 , V_11 + 0x06 ) ;
break;
default:
break;
}
return V_11 ;
}
T_1
F_6 ( struct V_1 * V_2 , int V_18 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 V_7 , V_8 ;
T_1 V_11 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , & V_7 , & V_8 ) ;
if ( V_11 && V_18 < * V_5 ) {
V_11 = V_11 + * V_4 + V_18 * ( * V_6 + ( V_7 * V_8 ) ) ;
* V_4 = * V_6 ;
* V_5 = V_7 ;
* V_6 = V_8 ;
return V_11 ;
}
return 0x00000000 ;
}
T_1
F_7 ( struct V_1 * V_2 , int V_18 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_19 * V_16 )
{
T_1 V_11 = F_6 ( V_2 , V_18 , V_3 , V_4 , V_5 , V_6 ) ;
memset ( V_16 , 0x00 , sizeof( * V_16 ) ) ;
switch ( ! ! V_11 * * V_3 ) {
case 0x10 :
V_16 -> type = F_3 ( V_2 , V_11 + 0x00 ) & 0x0f ;
return V_11 ;
default:
break;
}
return 0x00000000 ;
}
T_1
F_8 ( struct V_1 * V_2 , int V_20 , int V_18 , T_2 * V_3 , T_2 * V_4 )
{
T_2 V_5 , V_6 ;
T_1 V_11 = F_6 ( V_2 , V_20 , V_3 , V_4 , & V_5 , & V_6 ) ;
if ( V_11 && V_18 < V_5 ) {
V_11 = V_11 + * V_4 + V_18 * V_6 ;
* V_4 = V_6 ;
return V_11 ;
}
return 0x00000000 ;
}
T_1
F_9 ( struct V_1 * V_2 , int V_20 , int V_18 , T_2 * V_3 , T_2 * V_4 ,
struct V_21 * V_16 )
{
T_1 V_11 = F_8 ( V_2 , V_20 , V_18 , V_3 , V_4 ) ;
memset ( V_16 , 0x00 , sizeof( * V_16 ) ) ;
switch ( ! ! V_11 * * V_3 ) {
case 0x10 :
V_16 -> V_11 = F_3 ( V_2 , V_11 + 0x00 ) ;
return V_11 ;
default:
break;
}
return 0x00000000 ;
}
