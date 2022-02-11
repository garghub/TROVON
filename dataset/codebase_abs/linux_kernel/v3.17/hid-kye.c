static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 , int V_5 , const char * V_6 ) {
if ( * V_4 >= V_5 + 31 &&
V_3 [ V_5 ] == 0x05 && V_3 [ V_5 + 1 ] == 0x0c &&
V_3 [ V_5 + 2 ] == 0x09 && V_3 [ V_5 + 3 ] == 0x01 &&
V_3 [ V_5 + 10 ] == 0x2a && V_3 [ V_5 + 12 ] > 0x2f ) {
F_2 ( V_2 , L_1 , V_6 ) ;
V_3 [ V_5 + 12 ] = 0x2f ;
}
return V_3 ;
}
static T_1 * F_3 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
switch ( V_2 -> V_7 ) {
case V_8 :
if ( * V_4 >= 75 &&
V_3 [ 61 ] == 0x05 && V_3 [ 62 ] == 0x08 &&
V_3 [ 63 ] == 0x19 && V_3 [ 64 ] == 0x08 &&
V_3 [ 65 ] == 0x29 && V_3 [ 66 ] == 0x0f &&
V_3 [ 71 ] == 0x75 && V_3 [ 72 ] == 0x08 &&
V_3 [ 73 ] == 0x95 && V_3 [ 74 ] == 0x01 ) {
F_2 ( V_2 ,
L_2
L_3 ) ;
V_3 [ 62 ] = 0x09 ;
V_3 [ 64 ] = 0x04 ;
V_3 [ 66 ] = 0x07 ;
V_3 [ 72 ] = 0x01 ;
V_3 [ 74 ] = 0x08 ;
}
break;
case V_9 :
if ( * V_4 == V_10 ) {
V_3 = V_11 ;
* V_4 = sizeof( V_11 ) ;
}
break;
case V_12 :
if ( * V_4 == V_13 ) {
V_3 = V_14 ;
* V_4 = sizeof( V_14 ) ;
}
break;
case V_15 :
if ( * V_4 == V_16 ) {
V_3 = V_17 ;
* V_4 = sizeof( V_17 ) ;
}
break;
case V_18 :
V_3 = F_1 ( V_2 , V_3 , V_4 , 104 ,
L_4 ) ;
break;
case V_19 :
V_3 = F_1 ( V_2 , V_3 , V_4 , 83 ,
L_5 ) ;
break;
case V_20 :
V_3 = F_1 ( V_2 , V_3 , V_4 , 104 ,
L_6 ) ;
break;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
struct V_21 * V_23 ;
struct V_24 * V_25 ;
T_2 * V_26 ;
V_22 = & V_2 -> V_27 [ V_28 ] . V_29 ;
F_5 (head, list) {
V_25 = F_6 ( V_23 , struct V_24 , V_22 ) ;
if ( V_25 -> V_30 == 5 )
break;
}
if ( V_23 == V_22 ) {
F_7 ( V_2 , L_7 ) ;
return - V_31 ;
}
if ( V_25 -> V_32 < 1 || V_25 -> V_33 [ 0 ] -> V_34 < 7 ) {
F_7 ( V_2 , L_8 ) ;
return - V_31 ;
}
V_26 = V_25 -> V_33 [ 0 ] -> V_26 ;
V_26 [ 0 ] = 0x12 ;
V_26 [ 1 ] = 0x10 ;
V_26 [ 2 ] = 0x11 ;
V_26 [ 3 ] = 0x12 ;
V_26 [ 4 ] = 0x00 ;
V_26 [ 5 ] = 0x00 ;
V_26 [ 6 ] = 0x00 ;
F_8 ( V_2 , V_25 , V_35 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , const struct V_36 * V_30 )
{
int V_37 ;
V_37 = F_10 ( V_2 ) ;
if ( V_37 ) {
F_7 ( V_2 , L_9 ) ;
goto V_38;
}
V_37 = F_11 ( V_2 , V_39 ) ;
if ( V_37 ) {
F_7 ( V_2 , L_10 ) ;
goto V_38;
}
switch ( V_30 -> V_7 ) {
case V_9 :
case V_12 :
case V_15 :
V_37 = F_4 ( V_2 ) ;
if ( V_37 ) {
F_7 ( V_2 , L_11 ) ;
goto V_40;
}
break;
case V_20 :
if ( F_12 ( V_2 ) )
F_13 ( V_2 ) ;
break;
}
return 0 ;
V_40:
F_14 ( V_2 ) ;
V_38:
return V_37 ;
}
