static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
T_2 V_12 ;
T_2 V_13 ;
T_3 V_14 ;
T_1 V_15 ;
int V_16 ;
V_15 = F_2 ( V_2 ) ;
V_7 = F_3 ( V_2 ) ;
if ( V_15 >= V_17 ) {
F_4 ( V_2 ) ;
return V_18 ;
}
V_9 = & V_4 -> V_19 [ V_15 ] ;
V_11 = V_9 -> V_20 ;
V_12 = V_7 -> V_21 . V_12 ;
V_13 = F_5 ( V_7 -> V_21 . V_22 ) ;
V_14 = F_6 ( V_7 -> V_21 . V_14 ) ;
V_16 = F_7 ( V_11 , V_5 ) ;
if ( V_16 ) {
F_4 ( V_2 ) ;
return V_23 ;
} else {
return V_24 ;
}
}
static void F_8 ( struct V_1 * V_2 ,
unsigned char type )
{
struct V_6 * V_7 ;
int V_25 ;
V_2 -> V_26 = F_9 ( V_27 ) ;
V_7 = F_3 ( V_2 ) ;
V_7 -> V_28 = type & 0x03 ;
F_10 ( V_2 -> V_29 ) ;
V_25 = V_2 -> V_29 -> V_30 -> V_31 ( V_2 , V_2 -> V_29 ) ;
F_11 ( V_2 -> V_29 ) ;
}
T_4 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_32 )
{
struct V_6 * V_7 ;
unsigned char V_33 ;
unsigned char V_34 = 0 ;
V_7 = F_3 ( V_2 ) ;
V_33 = V_7 -> V_33 ;
switch ( V_33 ) {
case V_35 :
V_34 = F_1 ( V_2 , V_32 , 1 ) ;
break;
case V_36 :
V_34 = F_1 ( V_2 , V_32 , 0 ) ;
break;
default:
V_34 = V_23 ;
F_4 ( V_2 ) ;
break;
}
if ( V_34 == V_24 )
F_8 ( V_2 , V_34 ) ;
return V_18 ;
}
