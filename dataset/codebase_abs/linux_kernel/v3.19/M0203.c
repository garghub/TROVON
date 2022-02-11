T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 V_8 ;
T_1 V_9 = 0x00000000 ;
if ( ! V_7 ( V_2 , 'M' , & V_8 ) ) {
if ( V_8 . V_10 == 2 && V_8 . V_11 > 0x04 )
V_9 = F_2 ( V_2 , V_8 . V_12 + 0x03 ) ;
if ( V_9 ) {
* V_3 = F_3 ( V_2 , V_9 + 0x00 ) ;
switch ( * V_3 ) {
case 0x10 :
* V_4 = F_3 ( V_2 , V_9 + 0x01 ) ;
* V_6 = F_3 ( V_2 , V_9 + 0x02 ) ;
* V_5 = F_3 ( V_2 , V_9 + 0x03 ) ;
return V_9 ;
default:
break;
}
}
}
return 0x00000000 ;
}
T_1
F_4 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_13 * V_14 )
{
T_1 V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
memset ( V_14 , 0x00 , sizeof( * V_14 ) ) ;
switch ( ! ! V_9 * * V_3 ) {
case 0x10 :
V_14 -> type = F_3 ( V_2 , V_9 + 0x04 ) ;
V_14 -> V_15 = F_2 ( V_2 , V_9 + 0x05 ) ;
break;
default:
break;
}
return V_9 ;
}
T_1
F_5 ( struct V_1 * V_2 , int V_16 , T_2 * V_3 , T_2 * V_4 )
{
T_2 V_5 , V_6 ;
T_1 V_9 = F_1 ( V_2 , V_3 , V_4 , & V_5 , & V_6 ) ;
if ( V_9 && V_16 < V_5 ) {
V_9 = V_9 + * V_4 + V_16 * V_6 ;
* V_4 = V_6 ;
return V_9 ;
}
return 0x00000000 ;
}
T_1
F_6 ( struct V_1 * V_2 , int V_16 , T_2 * V_3 , T_2 * V_4 ,
struct V_17 * V_14 )
{
T_1 V_9 = F_5 ( V_2 , V_16 , V_3 , V_4 ) ;
memset ( V_14 , 0x00 , sizeof( * V_14 ) ) ;
switch ( ! ! V_9 * * V_3 ) {
case 0x10 :
V_14 -> type = ( F_3 ( V_2 , V_9 + 0x00 ) & 0x0f ) >> 0 ;
V_14 -> V_18 = ( F_3 ( V_2 , V_9 + 0x00 ) & 0xf0 ) >> 4 ;
V_14 -> V_19 = ( F_3 ( V_2 , V_9 + 0x01 ) & 0x0f ) >> 0 ;
return V_9 ;
default:
break;
}
return 0x00000000 ;
}
T_1
F_7 ( struct V_1 * V_2 , T_2 V_20 , T_2 * V_3 , T_2 * V_4 ,
struct V_17 * V_14 )
{
struct V_13 V_21 ;
T_2 V_5 , V_6 , V_16 = 0xff ;
T_1 V_9 ;
if ( ! F_4 ( V_2 , V_3 , V_4 , & V_5 , & V_6 , & V_21 ) ) {
F_8 ( V_2 , L_1 ) ;
return 0x00000000 ;
}
while ( ( V_9 = F_6 ( V_2 , ++ V_16 , V_3 , V_4 , V_14 ) ) ) {
switch ( V_21 . type ) {
case V_22 :
if ( V_14 -> V_18 != V_20 )
continue;
return V_9 ;
default:
F_8 ( V_2 , L_2 , V_21 . type ) ;
return 0x00000000 ;
}
}
return V_9 ;
}
