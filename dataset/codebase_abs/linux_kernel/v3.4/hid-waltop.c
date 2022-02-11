static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( V_7 == NULL ) {
F_3 ( V_2 , L_1 ) ;
V_5 = - V_9 ;
goto V_10;
}
V_7 -> V_11 = 0 ;
V_7 -> V_12 = 0 ;
F_4 ( V_2 , V_7 ) ;
V_5 = F_5 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_2 ) ;
goto V_10;
}
V_5 = F_6 ( V_2 , V_13 ) ;
if ( V_5 ) {
F_3 ( V_2 , L_3 ) ;
goto V_10;
}
return 0 ;
V_10:
F_7 ( V_7 ) ;
return V_5 ;
}
static T_1 * F_8 ( struct V_1 * V_2 , T_1 * V_14 ,
unsigned int * V_15 )
{
switch ( V_2 -> V_16 ) {
case V_17 :
if ( * V_15 == V_18 ) {
V_14 = V_19 ;
* V_15 = sizeof( V_19 ) ;
}
break;
case V_20 :
if ( * V_15 == V_21 ) {
V_14 = V_22 ;
* V_15 = sizeof( V_22 ) ;
}
break;
case V_23 :
if ( * V_15 == V_24 ) {
V_14 = V_25 ;
* V_15 = sizeof( V_25 ) ;
}
break;
case V_26 :
if ( * V_15 == V_27 ) {
V_14 = V_28 ;
* V_15 = sizeof( V_28 ) ;
}
break;
case V_29 :
if ( * V_15 == V_30 ) {
V_14 = V_31 ;
* V_15 = sizeof( V_31 ) ;
}
break;
case V_32 :
if ( * V_15 == V_33 ) {
V_14 = V_34 ;
* V_15 = sizeof( V_34 ) ;
}
break;
}
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_35 * V_36 ,
T_2 * V_37 , int V_38 )
{
if ( V_2 -> V_16 == V_26 &&
V_36 -> type == V_39 &&
V_36 -> V_4 == 16 &&
V_38 == 8 ) {
struct V_6 * V_7 = F_10 ( V_2 ) ;
if ( ( V_37 [ 1 ] & 0xF ) > 1 ) {
V_37 [ 6 ] = V_7 -> V_11 ;
V_37 [ 7 ] = V_7 -> V_12 ;
} else {
V_7 -> V_11 = V_37 [ 6 ] ;
V_7 -> V_12 = V_37 [ 7 ] ;
}
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_10 ( V_2 ) ;
F_12 ( V_2 ) ;
F_7 ( V_7 ) ;
}
static int T_3 F_13 ( void )
{
return F_14 ( & V_40 ) ;
}
static void T_4 F_15 ( void )
{
F_16 ( & V_40 ) ;
}
