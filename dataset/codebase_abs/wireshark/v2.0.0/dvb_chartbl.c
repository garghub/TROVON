static T_1
F_1 ( T_2 V_1 )
{
switch ( V_1 ) {
case 0x01 :
return V_2 ;
case 0x02 :
return V_3 ;
case 0x03 :
return V_4 ;
case 0x04 :
return V_5 ;
case 0x05 :
return V_6 ;
case 0x06 :
return V_7 ;
case 0x07 :
return V_8 ;
case 0x08 :
return V_9 ;
case 0x09 :
return V_10 ;
case 0x0A :
return V_11 ;
case 0x0B :
return V_12 ;
case 0x11 :
return V_13 ;
case 0x12 :
return V_14 ;
case 0x13 :
return V_15 ;
case 0x14 :
return V_16 ;
case 0x15 :
return V_17 ;
default:
return V_18 ;
}
}
static T_1
F_2 ( T_3 V_19 )
{
switch ( V_19 ) {
case 0x0000 :
return V_9 ;
case 0x0001 :
return V_20 ;
case 0x0002 :
return V_21 ;
case 0x0003 :
return V_22 ;
case 0x0004 :
return V_23 ;
case 0x0005 :
return V_2 ;
case 0x0006 :
return V_3 ;
case 0x0007 :
return V_4 ;
case 0x0008 :
return V_5 ;
case 0x0009 :
return V_6 ;
case 0x000A :
return V_7 ;
case 0x000B :
return V_8 ;
case 0x000C :
return V_9 ;
case 0x000D :
return V_10 ;
case 0x000E :
return V_11 ;
case 0x000F :
return V_12 ;
default:
return V_18 ;
}
}
static T_1
F_3 ( T_2 V_24 )
{
switch ( V_24 ) {
case 0x00 :
return V_9 ;
case 0x01 :
case 0x02 :
case 0x03 :
case 0x04 :
return V_9 ;
case 0x05 :
case 0x06 :
return V_9 ;
default:
return V_9 ;
}
}
T_4
F_4 ( T_5 * V_25 , int V_26 , int V_27 , T_1 * V_28 )
{
if ( V_27 >= 1 ) {
T_2 V_1 = F_5 ( V_25 , V_26 + 0 ) ;
if ( V_1 >= 0x20 ) {
* V_28 = V_29 ;
return 0 ;
} else if ( V_1 == 0x1F ) {
if ( V_27 >= 2 ) {
* V_28 = F_3 ( F_5 ( V_25 , V_26 + 1 ) ) ;
return 2 ;
}
* V_28 = V_30 ;
return 1 ;
} else if ( V_1 >= 0x16 ) {
* V_28 = V_9 ;
return 1 ;
} else if ( V_1 == 0x10 ) {
if ( V_27 >= 3 ) {
* V_28 = F_2 ( F_6 ( V_25 , V_26 + 1 ) ) ;
return 3 ;
}
* V_28 = V_30 ;
return 1 ;
} else if ( ( V_1 >= 0x0C && V_1 <= 0x0F ) ) {
* V_28 = V_9 ;
return 1 ;
} else {
* V_28 = F_1 ( V_1 ) ;
return 1 ;
}
} else
* V_28 = V_29 ;
return 0 ;
}
T_4
F_7 ( T_1 V_28 )
{
switch ( V_28 ) {
case V_20 :
return V_31 | V_32 ;
case V_21 :
return V_33 | V_32 ;
case V_22 :
return V_34 | V_32 ;
case V_23 :
return V_35 | V_32 ;
case V_2 :
return V_36 | V_32 ;
case V_3 :
return V_37 | V_32 ;
case V_4 :
return V_38 | V_32 ;
case V_5 :
return V_39 | V_32 ;
case V_6 :
return V_40 | V_32 ;
case V_7 :
return V_41 | V_32 ;
case V_8 :
return V_42 | V_32 ;
case V_10 :
return V_43 | V_32 ;
case V_11 :
return V_44 | V_32 ;
case V_12 :
return V_45 | V_32 ;
case V_17 :
return V_46 | V_32 ;
default:
return V_47 | V_32 ;
}
}
void
F_8 ( T_6 * V_48 , int V_49 ,
T_5 * V_25 , T_7 V_26 , T_7 V_27 , T_1 V_28 )
{
if ( V_27 == 0 ) {
T_8 * V_50 ;
V_50 = F_9 ( V_48 , V_49 , V_25 , 0 , 0 , NULL ,
L_1 ) ;
F_10 ( V_50 ) ;
}
else {
F_11 ( V_48 , V_49 ,
V_25 , V_26 , V_27 , NULL , L_2 ,
F_12 ( V_28 , V_51 , L_3 ) ,
F_13 ( F_14 () , V_25 , V_26 , V_27 , ' ' ) ) ;
}
}
