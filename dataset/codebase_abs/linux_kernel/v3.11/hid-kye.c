static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
switch ( V_2 -> V_5 ) {
case V_6 :
if ( * V_4 >= 74 &&
V_3 [ 61 ] == 0x05 && V_3 [ 62 ] == 0x08 &&
V_3 [ 63 ] == 0x19 && V_3 [ 64 ] == 0x08 &&
V_3 [ 65 ] == 0x29 && V_3 [ 66 ] == 0x0f &&
V_3 [ 71 ] == 0x75 && V_3 [ 72 ] == 0x08 &&
V_3 [ 73 ] == 0x95 && V_3 [ 74 ] == 0x01 ) {
F_2 ( V_2 ,
L_1
L_2 ) ;
V_3 [ 62 ] = 0x09 ;
V_3 [ 64 ] = 0x04 ;
V_3 [ 66 ] = 0x07 ;
V_3 [ 72 ] = 0x01 ;
V_3 [ 74 ] = 0x08 ;
}
break;
case V_7 :
if ( * V_4 == V_8 ) {
V_3 = V_9 ;
* V_4 = sizeof( V_9 ) ;
}
break;
case V_10 :
if ( * V_4 == V_11 ) {
V_3 = V_12 ;
* V_4 = sizeof( V_12 ) ;
}
break;
case V_13 :
if ( * V_4 == V_14 ) {
V_3 = V_15 ;
* V_4 = sizeof( V_15 ) ;
}
break;
case V_16 :
if ( * V_4 >= 135 &&
V_3 [ 104 ] == 0x05 && V_3 [ 105 ] == 0x0c &&
V_3 [ 106 ] == 0x09 && V_3 [ 107 ] == 0x01 &&
V_3 [ 114 ] == 0x2a && V_3 [ 116 ] > 0x2f ) {
F_2 ( V_2 ,
L_3
L_2 ) ;
V_3 [ 116 ] = 0x2f ;
}
break;
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_17 * V_19 ;
struct V_20 * V_21 ;
T_2 * V_22 ;
V_18 = & V_2 -> V_23 [ V_24 ] . V_25 ;
F_4 (head, list) {
V_21 = F_5 ( V_19 , struct V_20 , V_18 ) ;
if ( V_21 -> V_26 == 5 )
break;
}
if ( V_19 == V_18 ) {
F_6 ( V_2 , L_4 ) ;
return - V_27 ;
}
if ( V_21 -> V_28 < 1 || V_21 -> V_29 [ 0 ] -> V_30 < 7 ) {
F_6 ( V_2 , L_5 ) ;
return - V_27 ;
}
V_22 = V_21 -> V_29 [ 0 ] -> V_22 ;
V_22 [ 0 ] = 0x12 ;
V_22 [ 1 ] = 0x10 ;
V_22 [ 2 ] = 0x11 ;
V_22 [ 3 ] = 0x12 ;
V_22 [ 4 ] = 0x00 ;
V_22 [ 5 ] = 0x00 ;
V_22 [ 6 ] = 0x00 ;
F_7 ( V_2 , V_21 , V_31 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , const struct V_32 * V_26 )
{
int V_33 ;
V_33 = F_9 ( V_2 ) ;
if ( V_33 ) {
F_6 ( V_2 , L_6 ) ;
goto V_34;
}
V_33 = F_10 ( V_2 , V_35 ) ;
if ( V_33 ) {
F_6 ( V_2 , L_7 ) ;
goto V_34;
}
switch ( V_26 -> V_5 ) {
case V_7 :
case V_10 :
case V_13 :
V_33 = F_3 ( V_2 ) ;
if ( V_33 ) {
F_6 ( V_2 , L_8 ) ;
goto V_36;
}
break;
}
return 0 ;
V_36:
F_11 ( V_2 ) ;
V_34:
return V_33 ;
}
