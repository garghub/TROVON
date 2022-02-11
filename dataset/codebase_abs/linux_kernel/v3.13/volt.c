T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 V_8 ;
T_1 V_9 = 0x0000 ;
if ( ! V_7 ( V_2 , 'P' , & V_8 ) ) {
if ( V_8 . V_10 == 2 )
V_9 = F_2 ( V_2 , V_8 . V_11 + 0x0c ) ;
else
if ( V_8 . V_10 == 1 )
V_9 = F_2 ( V_2 , V_8 . V_11 + 0x10 ) ;
if ( V_9 ) {
* V_3 = F_3 ( V_2 , V_9 + 0 ) ;
switch ( * V_3 ) {
case 0x12 :
* V_4 = 5 ;
* V_5 = F_3 ( V_2 , V_9 + 2 ) ;
* V_6 = F_3 ( V_2 , V_9 + 1 ) ;
return V_9 ;
case 0x20 :
* V_4 = F_3 ( V_2 , V_9 + 1 ) ;
* V_5 = F_3 ( V_2 , V_9 + 2 ) ;
* V_6 = F_3 ( V_2 , V_9 + 3 ) ;
return V_9 ;
case 0x30 :
case 0x40 :
case 0x50 :
* V_4 = F_3 ( V_2 , V_9 + 1 ) ;
* V_5 = F_3 ( V_2 , V_9 + 3 ) ;
* V_6 = F_3 ( V_2 , V_9 + 2 ) ;
return V_9 ;
}
}
}
return 0x0000 ;
}
T_1
F_4 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 ,
struct V_12 * V_13 )
{
T_1 V_9 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
memset ( V_13 , 0x00 , sizeof( * V_13 ) ) ;
switch ( ! ! V_9 * * V_3 ) {
case 0x12 :
V_13 -> V_14 = F_3 ( V_2 , V_9 + 0x04 ) ;
break;
case 0x20 :
V_13 -> V_14 = F_3 ( V_2 , V_9 + 0x05 ) ;
break;
case 0x30 :
V_13 -> V_14 = F_3 ( V_2 , V_9 + 0x04 ) ;
break;
case 0x40 :
V_13 -> V_15 = F_5 ( V_2 , V_9 + 0x04 ) ;
V_13 -> V_16 = F_2 ( V_2 , V_9 + 0x08 ) ;
V_13 -> V_14 = F_3 ( V_2 , V_9 + 0x0b ) ;
V_13 -> V_17 = 0 ;
V_13 -> V_18 = V_13 -> V_15 ;
break;
case 0x50 :
V_13 -> V_14 = F_3 ( V_2 , V_9 + 0x06 ) ;
V_13 -> V_17 = F_5 ( V_2 , V_9 + 0x0a ) ;
V_13 -> V_18 = F_5 ( V_2 , V_9 + 0x0e ) ;
V_13 -> V_15 = F_5 ( V_2 , V_9 + 0x12 ) & 0x00ffffff ;
V_13 -> V_16 = F_2 ( V_2 , V_9 + 0x16 ) ;
break;
}
return V_9 ;
}
T_1
F_6 ( struct V_1 * V_2 , int V_19 , T_2 * V_3 , T_2 * V_6 )
{
T_2 V_4 , V_5 ;
T_1 V_9 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , V_6 ) ;
if ( V_9 && V_19 < V_5 ) {
V_9 = V_9 + V_4 + ( V_19 * * V_6 ) ;
return V_9 ;
}
return 0x0000 ;
}
T_1
F_7 ( struct V_1 * V_2 , int V_19 , T_2 * V_3 , T_2 * V_6 ,
struct F_6 * V_13 )
{
T_1 V_9 = F_6 ( V_2 , V_19 , V_3 , V_6 ) ;
memset ( V_13 , 0x00 , sizeof( * V_13 ) ) ;
switch ( ! ! V_9 * * V_3 ) {
case 0x12 :
case 0x20 :
V_13 -> V_20 = F_3 ( V_2 , V_9 + 0x00 ) * 10000 ;
V_13 -> V_21 = F_3 ( V_2 , V_9 + 0x01 ) ;
break;
case 0x30 :
V_13 -> V_20 = F_3 ( V_2 , V_9 + 0x00 ) * 10000 ;
V_13 -> V_21 = F_3 ( V_2 , V_9 + 0x01 ) >> 2 ;
break;
case 0x40 :
case 0x50 :
break;
}
return V_9 ;
}
