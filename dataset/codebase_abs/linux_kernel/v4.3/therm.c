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
F_3 ( & V_2 -> V_12 ,
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
static T_1
F_5 ( struct V_1 * V_2 , int V_13 , T_2 * V_3 , T_2 * V_5 )
{
T_2 V_4 , V_6 ;
T_1 V_9 = F_1 ( V_2 , V_3 , & V_4 , V_5 , & V_6 ) ;
if ( V_9 && V_13 < V_6 )
return V_9 + V_13 * * V_5 ;
return 0x0000 ;
}
int
F_6 ( struct V_1 * V_2 ,
enum V_14 V_15 ,
struct V_16 * V_17 )
{
T_3 V_18 , V_19 , V_11 ;
T_2 V_3 , V_5 , V_20 ;
T_1 V_21 ;
if ( V_15 != V_22 )
return - V_23 ;
V_18 = 0 ;
V_19 = - 1 ;
V_20 = 0 ;
while ( ( V_21 = F_5 ( V_2 , V_20 ++ , & V_3 , & V_5 ) ) ) {
T_4 V_24 = F_2 ( V_2 , V_21 + 1 ) ;
switch ( F_4 ( V_2 , V_21 + 0 ) ) {
case 0x0 :
V_18 = V_24 ;
if ( V_24 > 0 )
return 0 ;
break;
case 0x01 :
V_19 ++ ;
if ( V_19 == 0 ) {
V_11 = ( ( T_3 ) F_4 ( V_2 , V_21 + 2 ) ) / 2 ;
V_17 -> V_25 = V_11 ;
}
break;
case 0x04 :
if ( V_18 == 0 ) {
V_17 -> V_26 . V_27 = ( V_24 & 0xff0 ) >> 4 ;
V_17 -> V_26 . V_28 = V_24 & 0xf ;
}
break;
case 0x07 :
if ( V_18 == 0 ) {
V_17 -> V_29 . V_27 = ( V_24 & 0xff0 ) >> 4 ;
V_17 -> V_29 . V_28 = V_24 & 0xf ;
}
break;
case 0x08 :
if ( V_18 == 0 ) {
V_17 -> V_30 . V_27 = ( V_24 & 0xff0 ) >> 4 ;
V_17 -> V_30 . V_28 = V_24 & 0xf ;
}
break;
case 0x10 :
if ( V_19 == 0 )
V_17 -> V_31 = V_24 ;
break;
case 0x11 :
if ( V_19 == 0 )
V_17 -> V_32 = V_24 ;
break;
case 0x12 :
if ( V_19 == 0 )
V_17 -> V_33 = V_24 ;
break;
case 0x13 :
if ( V_19 == 0 )
V_17 -> V_34 = V_24 ;
break;
case 0x32 :
if ( V_18 == 0 ) {
V_17 -> V_35 . V_27 = ( V_24 & 0xff0 ) >> 4 ;
V_17 -> V_35 . V_28 = V_24 & 0xf ;
}
break;
}
}
return 0 ;
}
int
F_7 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_38 * V_39 = NULL ;
T_2 V_3 , V_5 , V_20 ;
T_1 V_21 ;
T_5 V_40 [] = { 0 , 0 , 25 , 0 , 40 , 0 , 50 , 0 ,
75 , 0 , 85 , 0 , 100 , 0 , 100 , 0 } ;
V_20 = 0 ;
V_37 -> V_41 = 0 ;
V_37 -> V_42 = V_43 ;
while ( ( V_21 = F_5 ( V_2 , V_20 ++ , & V_3 , & V_5 ) ) ) {
T_4 V_24 = F_2 ( V_2 , V_21 + 1 ) ;
switch ( F_4 ( V_2 , V_21 + 0 ) ) {
case 0x22 :
V_37 -> V_44 = V_24 & 0xff ;
V_37 -> V_45 = ( V_24 & 0xff00 ) >> 8 ;
break;
case 0x24 :
V_37 -> V_41 ++ ;
if ( V_37 -> V_42 > V_46 )
V_37 -> V_42 = V_46 ;
V_39 = & V_37 -> V_47 [ V_37 -> V_41 - 1 ] ;
V_39 -> V_28 = V_24 & 0xf ;
V_39 -> V_27 = ( V_24 & 0xff0 ) >> 4 ;
V_39 -> V_48 = V_40 [ ( V_24 & 0xf000 ) >> 12 ] ;
break;
case 0x25 :
V_39 = & V_37 -> V_47 [ V_37 -> V_41 - 1 ] ;
V_39 -> V_48 = V_24 ;
break;
case 0x26 :
if ( ! V_37 -> V_49 )
V_37 -> V_49 = V_24 ;
break;
case 0x3b :
V_37 -> V_50 = V_24 ;
break;
case 0x3c :
V_37 -> V_51 = V_24 ;
break;
case 0x46 :
if ( V_37 -> V_42 > V_52 )
V_37 -> V_42 = V_52 ;
V_37 -> V_53 = F_4 ( V_2 , V_21 + 1 ) ;
V_37 -> V_54 = F_4 ( V_2 , V_21 + 2 ) ;
break;
}
}
if ( V_2 -> V_12 . V_55 -> V_56 >= V_57 &&
V_37 -> V_42 == V_43 ) {
V_37 -> V_42 = V_52 ;
}
return 0 ;
}
