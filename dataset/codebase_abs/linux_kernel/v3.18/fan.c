T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 V_8 ;
T_1 V_9 = 0x0000 ;
if ( ! V_7 ( V_2 , 'P' , & V_8 ) ) {
if ( V_8 . V_10 == 2 && V_8 . V_11 >= 0x5a )
V_9 = F_2 ( V_2 , V_8 . V_12 + 0x58 ) ;
if ( V_9 ) {
* V_3 = F_3 ( V_2 , V_9 + 0 ) ;
switch ( * V_3 ) {
case 0x10 :
* V_4 = F_3 ( V_2 , V_9 + 1 ) ;
* V_6 = F_3 ( V_2 , V_9 + 2 ) ;
* V_5 = F_3 ( V_2 , V_9 + 3 ) ;
return V_9 ;
default:
break;
}
}
}
return 0x0000 ;
}
T_1
F_4 ( struct V_1 * V_2 , int V_13 , T_2 * V_3 , T_2 * V_4 ,
T_2 * V_5 , T_2 * V_6 )
{
T_1 V_14 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_14 && V_13 < * V_5 )
return V_14 + * V_4 + ( V_13 * ( * V_6 ) ) ;
return 0x0000 ;
}
T_1
F_5 ( struct V_1 * V_2 , struct V_15 * V_9 )
{
T_2 V_3 , V_4 , V_5 , V_6 ;
T_1 V_14 = F_4 ( V_2 , 0 , & V_3 , & V_4 , & V_5 , & V_6 ) ;
if ( V_14 ) {
T_2 type = F_3 ( V_2 , V_14 + 0x00 ) ;
switch ( type ) {
case 0 :
V_9 -> type = V_16 ;
break;
case 1 :
case 2 :
V_9 -> type = V_17 ;
break;
default:
V_9 -> type = V_18 ;
}
V_9 -> V_19 = F_3 ( V_2 , V_14 + 0x02 ) ;
V_9 -> V_20 = F_3 ( V_2 , V_14 + 0x03 ) ;
V_9 -> V_21 = F_6 ( V_2 , V_14 + 0x0b ) & 0xffffff ;
}
return V_14 ;
}
