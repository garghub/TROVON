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
if ( * V_4 >= 74 &&
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
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_20 * V_22 ;
struct V_23 * V_24 ;
T_2 * V_25 ;
V_21 = & V_2 -> V_26 [ V_27 ] . V_28 ;
F_5 (head, list) {
V_24 = F_6 ( V_22 , struct V_23 , V_21 ) ;
if ( V_24 -> V_29 == 5 )
break;
}
if ( V_22 == V_21 ) {
F_7 ( V_2 , L_6 ) ;
return - V_30 ;
}
if ( V_24 -> V_31 < 1 || V_24 -> V_32 [ 0 ] -> V_33 < 7 ) {
F_7 ( V_2 , L_7 ) ;
return - V_30 ;
}
V_25 = V_24 -> V_32 [ 0 ] -> V_25 ;
V_25 [ 0 ] = 0x12 ;
V_25 [ 1 ] = 0x10 ;
V_25 [ 2 ] = 0x11 ;
V_25 [ 3 ] = 0x12 ;
V_25 [ 4 ] = 0x00 ;
V_25 [ 5 ] = 0x00 ;
V_25 [ 6 ] = 0x00 ;
F_8 ( V_2 , V_24 , V_34 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , const struct V_35 * V_29 )
{
int V_36 ;
V_36 = F_10 ( V_2 ) ;
if ( V_36 ) {
F_7 ( V_2 , L_8 ) ;
goto V_37;
}
V_36 = F_11 ( V_2 , V_38 ) ;
if ( V_36 ) {
F_7 ( V_2 , L_9 ) ;
goto V_37;
}
switch ( V_29 -> V_7 ) {
case V_9 :
case V_12 :
case V_15 :
V_36 = F_4 ( V_2 ) ;
if ( V_36 ) {
F_7 ( V_2 , L_10 ) ;
goto V_39;
}
break;
}
return 0 ;
V_39:
F_12 ( V_2 ) ;
V_37:
return V_36 ;
}
