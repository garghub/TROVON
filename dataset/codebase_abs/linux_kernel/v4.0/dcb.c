T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 = 0x0000 ;
if ( V_8 -> V_10 > V_11 )
V_9 = F_3 ( V_2 , 0x36 ) ;
if ( ! V_9 ) {
F_4 ( V_2 , L_1 ) ;
return V_9 ;
}
* V_3 = F_5 ( V_2 , V_9 ) ;
if ( * V_3 >= 0x42 ) {
F_4 ( V_2 , L_2 , * V_3 ) ;
return 0x0000 ;
} else
if ( * V_3 >= 0x30 ) {
if ( F_6 ( V_2 , V_9 + 6 ) == 0x4edcbdcb ) {
* V_4 = F_5 ( V_2 , V_9 + 1 ) ;
* V_5 = F_5 ( V_2 , V_9 + 2 ) ;
* V_6 = F_5 ( V_2 , V_9 + 3 ) ;
return V_9 ;
}
} else
if ( * V_3 >= 0x20 ) {
if ( F_6 ( V_2 , V_9 + 4 ) == 0x4edcbdcb ) {
T_1 V_12 = F_3 ( V_2 , V_9 + 2 ) ;
* V_4 = 8 ;
* V_5 = ( V_12 - V_9 ) / 8 ;
* V_6 = 8 ;
return V_9 ;
}
} else
if ( * V_3 >= 0x15 ) {
if ( ! F_7 ( V_2 , V_9 - 7 , L_3 , 7 ) ) {
T_1 V_12 = F_3 ( V_2 , V_9 + 2 ) ;
* V_4 = 4 ;
* V_5 = ( V_12 - V_9 ) / 10 ;
* V_6 = 10 ;
return V_9 ;
}
} else {
F_4 ( V_2 , L_4 ) ;
return 0x0000 ;
}
F_4 ( V_2 , L_5 ) ;
return 0x0000 ;
}
T_1
F_8 ( struct V_1 * V_2 , T_2 V_13 , T_2 * V_3 , T_2 * V_6 )
{
T_2 V_4 , V_5 ;
T_1 V_9 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , V_6 ) ;
if ( V_9 && V_13 < V_5 )
return V_9 + V_4 + ( V_13 * * V_6 ) ;
return 0x0000 ;
}
static inline T_1
F_9 ( struct V_14 * V_15 )
{
return ( V_15 -> V_16 << 8 ) | ( V_15 -> V_17 << 4 ) | V_15 -> type ;
}
static inline T_1
F_10 ( struct V_14 * V_15 )
{
return ( V_15 -> V_18 << 8 ) | ( V_15 -> V_19 << 6 ) | V_15 -> V_20 ;
}
T_1
F_11 ( struct V_1 * V_2 , T_2 V_13 , T_2 * V_3 , T_2 * V_6 ,
struct V_14 * V_15 )
{
T_1 V_9 = F_8 ( V_2 , V_13 , V_3 , V_6 ) ;
memset ( V_15 , 0x00 , sizeof( * V_15 ) ) ;
if ( V_9 ) {
if ( * V_3 >= 0x20 ) {
T_3 V_21 = F_6 ( V_2 , V_9 + 0x00 ) ;
V_15 -> V_20 = ( V_21 & 0x0f000000 ) >> 24 ;
V_15 -> V_17 = ( V_21 & 0x00300000 ) >> 20 ;
V_15 -> V_22 = ( V_21 & 0x000f0000 ) >> 16 ;
V_15 -> V_23 = ( V_21 & 0x0000f000 ) >> 12 ;
V_15 -> V_18 = ( V_21 & 0x00000f00 ) >> 8 ;
V_15 -> V_24 = ( V_21 & 0x000000f0 ) >> 4 ;
V_15 -> type = ( V_21 & 0x0000000f ) ;
V_15 -> V_19 = 0 ;
} else {
V_9 = 0x0000 ;
}
if ( * V_3 >= 0x40 ) {
T_3 V_25 = F_6 ( V_2 , V_9 + 0x04 ) ;
switch ( V_15 -> type ) {
case V_26 :
switch ( V_25 & 0x00e00000 ) {
case 0x00000000 :
V_15 -> V_27 . V_28 = 0x06 ;
break;
case 0x00200000 :
V_15 -> V_27 . V_28 = 0x0a ;
break;
case 0x00400000 :
default:
V_15 -> V_27 . V_28 = 0x14 ;
break;
}
V_15 -> V_27 . V_29 = ( V_25 & 0x0f000000 ) >> 24 ;
if ( * V_3 < 0x41 ) {
switch ( V_15 -> V_27 . V_29 ) {
case 0x0f :
V_15 -> V_27 . V_29 = 4 ;
break;
case 0x03 :
V_15 -> V_27 . V_29 = 2 ;
break;
case 0x01 :
default:
V_15 -> V_27 . V_29 = 1 ;
break;
}
}
case V_30 :
case V_31 :
V_15 -> V_19 = ( V_25 & 0x00000030 ) >> 4 ;
V_15 -> V_32 . V_19 = V_15 -> V_19 ;
V_15 -> V_16 = 0x00 ;
if ( V_15 -> V_17 != 0 )
V_15 -> V_16 = ( V_25 & 0x0000ff00 ) >> 8 ;
break;
default:
break;
}
}
V_15 -> V_33 = F_9 ( V_15 ) ;
V_15 -> V_34 = F_10 ( V_15 ) ;
}
return V_9 ;
}
T_1
F_12 ( struct V_1 * V_2 , T_1 type , T_1 V_35 ,
T_2 * V_3 , T_2 * V_6 , struct V_14 * V_15 )
{
T_1 V_9 , V_13 = 0 ;
while ( ( V_9 = F_11 ( V_2 , V_13 ++ , V_3 , V_6 , V_15 ) ) ) {
if ( ( F_9 ( V_15 ) & 0x00ff ) == ( type & 0x00ff ) ) {
if ( ( F_10 ( V_15 ) & V_35 ) == V_35 )
break;
}
}
return V_9 ;
}
int
F_13 ( struct V_1 * V_2 , void * V_36 ,
int (* F_14)( struct V_1 * , void * , int , T_1 ) )
{
int V_37 , V_13 = - 1 ;
T_2 V_3 , V_6 ;
T_1 V_15 ;
while ( ( V_15 = F_8 ( V_2 , ++ V_13 , & V_3 , & V_6 ) ) ) {
if ( F_6 ( V_2 , V_15 ) == 0x00000000 )
break;
if ( F_6 ( V_2 , V_15 ) == 0xffffffff )
break;
if ( F_5 ( V_2 , V_15 ) == V_38 )
continue;
if ( F_5 ( V_2 , V_15 ) == V_39 )
break;
V_37 = F_14 ( V_2 , V_36 , V_13 , V_15 ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
