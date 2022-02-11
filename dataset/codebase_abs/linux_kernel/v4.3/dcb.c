T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_11 = 0x0000 ;
if ( V_10 -> V_12 > V_13 )
V_11 = F_2 ( V_2 , 0x36 ) ;
if ( ! V_11 ) {
F_3 ( V_8 , L_1 ) ;
return V_11 ;
}
* V_3 = F_4 ( V_2 , V_11 ) ;
if ( * V_3 >= 0x42 ) {
F_3 ( V_8 , L_2 , * V_3 ) ;
return 0x0000 ;
} else
if ( * V_3 >= 0x30 ) {
if ( F_5 ( V_2 , V_11 + 6 ) == 0x4edcbdcb ) {
* V_4 = F_4 ( V_2 , V_11 + 1 ) ;
* V_5 = F_4 ( V_2 , V_11 + 2 ) ;
* V_6 = F_4 ( V_2 , V_11 + 3 ) ;
return V_11 ;
}
} else
if ( * V_3 >= 0x20 ) {
if ( F_5 ( V_2 , V_11 + 4 ) == 0x4edcbdcb ) {
T_1 V_14 = F_2 ( V_2 , V_11 + 2 ) ;
* V_4 = 8 ;
* V_5 = ( V_14 - V_11 ) / 8 ;
* V_6 = 8 ;
return V_11 ;
}
} else
if ( * V_3 >= 0x15 ) {
if ( ! F_6 ( V_2 , V_11 - 7 , L_3 , 7 ) ) {
T_1 V_14 = F_2 ( V_2 , V_11 + 2 ) ;
* V_4 = 4 ;
* V_5 = ( V_14 - V_11 ) / 10 ;
* V_6 = 10 ;
return V_11 ;
}
} else {
F_7 ( V_8 , L_4 ) ;
return 0x0000 ;
}
F_3 ( V_8 , L_5 ) ;
return 0x0000 ;
}
T_1
F_8 ( struct V_1 * V_2 , T_2 V_15 , T_2 * V_3 , T_2 * V_6 )
{
T_2 V_4 , V_5 ;
T_1 V_11 = F_1 ( V_2 , V_3 , & V_4 , & V_5 , V_6 ) ;
if ( V_11 && V_15 < V_5 )
return V_11 + V_4 + ( V_15 * * V_6 ) ;
return 0x0000 ;
}
static inline T_1
F_9 ( struct V_16 * V_17 )
{
return ( V_17 -> V_18 << 8 ) | ( V_17 -> V_19 << 4 ) | V_17 -> type ;
}
static inline T_1
F_10 ( struct V_16 * V_17 )
{
return ( V_17 -> V_20 << 8 ) | ( V_17 -> V_21 << 6 ) | V_17 -> V_22 ;
}
T_1
F_11 ( struct V_1 * V_2 , T_2 V_15 , T_2 * V_3 , T_2 * V_6 ,
struct V_16 * V_17 )
{
T_1 V_11 = F_8 ( V_2 , V_15 , V_3 , V_6 ) ;
memset ( V_17 , 0x00 , sizeof( * V_17 ) ) ;
if ( V_11 ) {
if ( * V_3 >= 0x20 ) {
T_3 V_23 = F_5 ( V_2 , V_11 + 0x00 ) ;
V_17 -> V_22 = ( V_23 & 0x0f000000 ) >> 24 ;
V_17 -> V_19 = ( V_23 & 0x00300000 ) >> 20 ;
V_17 -> V_24 = ( V_23 & 0x000f0000 ) >> 16 ;
V_17 -> V_25 = ( V_23 & 0x0000f000 ) >> 12 ;
V_17 -> V_20 = ( V_23 & 0x00000f00 ) >> 8 ;
V_17 -> V_26 = ( V_23 & 0x000000f0 ) >> 4 ;
V_17 -> type = ( V_23 & 0x0000000f ) ;
V_17 -> V_21 = 0 ;
} else {
V_11 = 0x0000 ;
}
if ( * V_3 >= 0x40 ) {
T_3 V_27 = F_5 ( V_2 , V_11 + 0x04 ) ;
switch ( V_17 -> type ) {
case V_28 :
switch ( V_27 & 0x00e00000 ) {
case 0x00000000 :
V_17 -> V_29 . V_30 = 0x06 ;
break;
case 0x00200000 :
V_17 -> V_29 . V_30 = 0x0a ;
break;
case 0x00400000 :
default:
V_17 -> V_29 . V_30 = 0x14 ;
break;
}
switch ( ( V_27 & 0x0f000000 ) >> 24 ) {
case 0xf :
case 0x4 :
V_17 -> V_29 . V_31 = 4 ;
break;
case 0x3 :
case 0x2 :
V_17 -> V_29 . V_31 = 2 ;
break;
case 0x1 :
default:
V_17 -> V_29 . V_31 = 1 ;
break;
}
case V_32 :
case V_33 :
V_17 -> V_21 = ( V_27 & 0x00000030 ) >> 4 ;
V_17 -> V_34 . V_21 = V_17 -> V_21 ;
V_17 -> V_18 = 0x00 ;
if ( V_17 -> V_19 != 0 )
V_17 -> V_18 = ( V_27 & 0x0000ff00 ) >> 8 ;
break;
default:
break;
}
}
V_17 -> V_35 = F_9 ( V_17 ) ;
V_17 -> V_36 = F_10 ( V_17 ) ;
}
return V_11 ;
}
T_1
F_12 ( struct V_1 * V_2 , T_1 type , T_1 V_37 ,
T_2 * V_3 , T_2 * V_6 , struct V_16 * V_17 )
{
T_1 V_11 , V_15 = 0 ;
while ( ( V_11 = F_11 ( V_2 , V_15 ++ , V_3 , V_6 , V_17 ) ) ) {
if ( ( F_9 ( V_17 ) & 0x00ff ) == ( type & 0x00ff ) ) {
if ( ( F_10 ( V_17 ) & V_37 ) == V_37 )
break;
}
}
return V_11 ;
}
int
F_13 ( struct V_1 * V_2 , void * V_38 ,
int (* F_14)( struct V_1 * , void * , int , T_1 ) )
{
int V_39 , V_15 = - 1 ;
T_2 V_3 , V_6 ;
T_1 V_17 ;
while ( ( V_17 = F_8 ( V_2 , ++ V_15 , & V_3 , & V_6 ) ) ) {
if ( F_5 ( V_2 , V_17 ) == 0x00000000 )
break;
if ( F_5 ( V_2 , V_17 ) == 0xffffffff )
break;
if ( F_4 ( V_2 , V_17 ) == V_40 )
continue;
if ( F_4 ( V_2 , V_17 ) == V_41 )
break;
V_39 = F_14 ( V_2 , V_38 , V_15 , V_17 ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
