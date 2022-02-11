static T_1
F_1 ( struct V_1 * V_2 , T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
struct V_7 V_8 ;
T_1 V_9 = 0 ;
if ( ! V_7 ( V_2 , 'P' , & V_8 ) ) {
if ( V_8 . V_10 == 1 )
V_9 = F_2 ( V_2 , V_8 . V_11 + 12 ) ;
else if ( V_8 . V_10 == 2 )
V_9 = F_2 ( V_2 , V_8 . V_11 + 16 ) ;
else
F_3 ( V_2 ,
L_1 ,
V_8 . V_10 ) ;
}
if ( ! V_9 )
return 0x0000 ;
* V_3 = F_4 ( V_2 , V_9 + 0 ) ;
* V_4 = F_4 ( V_2 , V_9 + 1 ) ;
* V_5 = F_4 ( V_2 , V_9 + 2 ) ;
* V_6 = F_4 ( V_2 , V_9 + 3 ) ;
return V_9 + F_4 ( V_2 , V_9 + 1 ) ;
}
T_1
F_5 ( struct V_1 * V_2 , int V_12 , T_2 * V_3 , T_2 * V_5 )
{
T_2 V_4 , V_6 ;
T_1 V_9 = F_1 ( V_2 , V_3 , & V_4 , V_5 , & V_6 ) ;
if ( V_9 && V_12 < V_6 )
return V_9 + V_12 * * V_5 ;
return 0x0000 ;
}
int
F_6 ( struct V_1 * V_2 ,
enum V_13 V_14 ,
struct V_15 * V_16 )
{
T_3 V_17 , V_18 , V_11 ;
T_2 V_3 , V_5 , V_19 ;
T_1 V_20 ;
if ( V_14 != V_21 )
return - V_22 ;
V_17 = 0 ;
V_18 = - 1 ;
V_19 = 0 ;
while ( ( V_20 = F_5 ( V_2 , V_19 ++ , & V_3 , & V_5 ) ) ) {
T_4 V_23 = F_2 ( V_2 , V_20 + 1 ) ;
switch ( F_4 ( V_2 , V_20 + 0 ) ) {
case 0x0 :
V_17 = V_23 ;
if ( V_23 > 0 )
return 0 ;
break;
case 0x01 :
V_18 ++ ;
if ( V_18 == 0 ) {
V_11 = ( ( T_3 ) F_4 ( V_2 , V_20 + 2 ) ) / 2 ;
V_16 -> V_24 = V_11 ;
}
break;
case 0x04 :
if ( V_17 == 0 ) {
V_16 -> V_25 . V_26 = ( V_23 & 0xff0 ) >> 4 ;
V_16 -> V_25 . V_27 = V_23 & 0xf ;
}
break;
case 0x07 :
if ( V_17 == 0 ) {
V_16 -> V_28 . V_26 = ( V_23 & 0xff0 ) >> 4 ;
V_16 -> V_28 . V_27 = V_23 & 0xf ;
}
break;
case 0x08 :
if ( V_17 == 0 ) {
V_16 -> V_29 . V_26 = ( V_23 & 0xff0 ) >> 4 ;
V_16 -> V_29 . V_27 = V_23 & 0xf ;
}
break;
case 0x10 :
if ( V_18 == 0 )
V_16 -> V_30 = V_23 ;
break;
case 0x11 :
if ( V_18 == 0 )
V_16 -> V_31 = V_23 ;
break;
case 0x12 :
if ( V_18 == 0 )
V_16 -> V_32 = V_23 ;
break;
case 0x13 :
if ( V_18 == 0 )
V_16 -> V_33 = V_23 ;
break;
case 0x32 :
if ( V_17 == 0 ) {
V_16 -> V_34 . V_26 = ( V_23 & 0xff0 ) >> 4 ;
V_16 -> V_34 . V_27 = V_23 & 0xf ;
}
break;
}
}
return 0 ;
}
int
F_7 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
T_2 V_3 , V_5 , V_19 ;
T_1 V_20 ;
V_19 = 0 ;
while ( ( V_20 = F_5 ( V_2 , V_19 ++ , & V_3 , & V_5 ) ) ) {
T_4 V_23 = F_2 ( V_2 , V_20 + 1 ) ;
switch ( F_4 ( V_2 , V_20 + 0 ) ) {
case 0x22 :
V_36 -> V_37 = V_23 & 0xff ;
V_36 -> V_38 = ( V_23 & 0xff00 ) >> 8 ;
break;
case 0x26 :
V_36 -> V_39 = V_23 ;
break;
}
}
return 0 ;
}
