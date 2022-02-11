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
}
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_16 * V_18 ;
struct V_19 * V_20 ;
T_2 * V_21 ;
V_17 = & V_2 -> V_22 [ V_23 ] . V_24 ;
F_4 (head, list) {
V_20 = F_5 ( V_18 , struct V_19 , V_17 ) ;
if ( V_20 -> V_25 == 5 )
break;
}
if ( V_18 == V_17 ) {
F_6 ( V_2 , L_3 ) ;
return - V_26 ;
}
if ( V_20 -> V_27 < 1 || V_20 -> V_28 [ 0 ] -> V_29 < 7 ) {
F_6 ( V_2 , L_4 ) ;
return - V_26 ;
}
V_21 = V_20 -> V_28 [ 0 ] -> V_21 ;
V_21 [ 0 ] = 0x12 ;
V_21 [ 1 ] = 0x10 ;
V_21 [ 2 ] = 0x11 ;
V_21 [ 3 ] = 0x12 ;
V_21 [ 4 ] = 0x00 ;
V_21 [ 5 ] = 0x00 ;
V_21 [ 6 ] = 0x00 ;
F_7 ( V_2 , V_20 , V_30 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , const struct V_31 * V_25 )
{
int V_32 ;
V_32 = F_9 ( V_2 ) ;
if ( V_32 ) {
F_6 ( V_2 , L_5 ) ;
goto V_33;
}
V_32 = F_10 ( V_2 , V_34 ) ;
if ( V_32 ) {
F_6 ( V_2 , L_6 ) ;
goto V_33;
}
switch ( V_25 -> V_5 ) {
case V_7 :
case V_10 :
case V_13 :
V_32 = F_3 ( V_2 ) ;
if ( V_32 ) {
F_6 ( V_2 , L_7 ) ;
goto V_35;
}
break;
}
return 0 ;
V_35:
F_11 ( V_2 ) ;
V_33:
return V_32 ;
}
static int T_3 F_12 ( void )
{
return F_13 ( & V_36 ) ;
}
static void T_4 F_14 ( void )
{
F_15 ( & V_36 ) ;
}
