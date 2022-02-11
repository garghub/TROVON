static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ,
struct V_7 , V_9 ) ;
struct V_10 * V_11 = V_8 -> V_12 -> V_11 ;
int V_13 ;
T_1 V_14 ;
switch ( V_4 ) {
case V_15 :
V_6 -> V_16 = 0 ;
V_13 = F_3 ( V_11 , V_17 , & V_14 ) ;
if ( V_13 )
return V_13 ;
if ( ( V_14 & ( 1 << 0 ) ) == 0x1 )
V_6 -> V_16 = V_18 ;
break;
case V_19 :
V_6 -> V_16 = 0 ;
V_13 = F_3 ( V_11 , V_17 , & V_14 ) ;
if ( V_13 )
return V_13 ;
if ( ( V_14 & ( 1 << 2 ) ) == 0x0 )
V_6 -> V_16 = 1 ;
break;
case V_20 :
V_6 -> V_16 = 0 ;
V_13 = F_3 ( V_11 , V_17 , & V_14 ) ;
if ( V_13 )
return V_13 ;
if ( V_14 & ( 1 << 1 ) )
V_6 -> V_16 = 1 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_4 ( struct V_22 * V_23 )
{
int V_13 = 0 ;
struct V_7 * V_8 ;
struct V_24 * V_12 = F_5 ( V_23 -> V_25 . V_26 ) ;
struct V_27 * V_28 = F_6 ( V_12 -> V_25 ) ;
if ( ! V_28 )
return - V_21 ;
if ( V_28 -> V_29 ) {
int V_6 = ( V_28 -> V_29 - 50 ) / 10 ;
if ( V_6 < 0 )
V_6 = 0 ;
if ( V_6 > 0xf )
V_6 = 0xf ;
V_13 = F_7 ( V_12 -> V_11 ,
V_30 , V_6 , 0xf ) ;
if ( V_13 < 0 ) {
F_8 ( & V_23 -> V_25 , L_1 ) ;
return V_13 ;
}
}
switch ( V_28 -> V_31 ) {
case 5 :
V_13 = F_7 ( V_12 -> V_11 , V_32 ,
0x2 << 4 , 0x7 << 4 ) ;
break;
case 6 :
V_13 = F_7 ( V_12 -> V_11 , V_32 ,
0x3 << 4 , 0x7 << 4 ) ;
break;
case 7 :
V_13 = F_7 ( V_12 -> V_11 , V_32 ,
0x4 << 4 , 0x7 << 4 ) ;
break;
case 0 :
V_13 = F_7 ( V_12 -> V_11 , V_32 ,
0x7 << 4 , 0x7 << 4 ) ;
break;
default:
F_8 ( & V_23 -> V_25 , L_2 ,
V_28 -> V_31 ) ;
return - V_21 ;
}
if ( V_13 < 0 ) {
F_8 ( & V_23 -> V_25 , L_1 ) ;
return V_13 ;
}
V_8 = F_9 ( & V_23 -> V_25 , sizeof( struct V_7 ) ,
V_33 ) ;
if ( V_8 == NULL ) {
F_8 ( & V_23 -> V_25 , L_3 ) ;
return - V_34 ;
}
F_10 ( V_23 , V_8 ) ;
V_8 -> V_9 . V_35 = L_4 ;
V_8 -> V_9 . type = V_36 ;
V_8 -> V_9 . V_37 = F_1 ;
V_8 -> V_9 . V_38 = V_39 ;
V_8 -> V_9 . V_40 = F_11 ( V_39 ) ;
V_8 -> V_25 = & V_23 -> V_25 ;
V_8 -> V_12 = V_12 ;
V_13 = F_12 ( & V_23 -> V_25 , & V_8 -> V_9 ) ;
if ( V_13 ) {
F_8 ( & V_23 -> V_25 , L_5 ) ;
return V_13 ;
}
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_7 * V_8 = F_14 ( V_23 ) ;
F_15 ( & V_8 -> V_9 ) ;
return 0 ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_41 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_41 ) ;
}
