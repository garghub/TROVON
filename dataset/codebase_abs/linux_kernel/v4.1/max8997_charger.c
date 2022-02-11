static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 ,
union V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 -> V_10 ;
int V_12 ;
T_1 V_13 ;
switch ( V_4 ) {
case V_14 :
V_6 -> V_15 = 0 ;
V_12 = F_3 ( V_10 , V_16 , & V_13 ) ;
if ( V_12 )
return V_12 ;
if ( ( V_13 & ( 1 << 0 ) ) == 0x1 )
V_6 -> V_15 = V_17 ;
break;
case V_18 :
V_6 -> V_15 = 0 ;
V_12 = F_3 ( V_10 , V_16 , & V_13 ) ;
if ( V_12 )
return V_12 ;
if ( ( V_13 & ( 1 << 2 ) ) == 0x0 )
V_6 -> V_15 = 1 ;
break;
case V_19 :
V_6 -> V_15 = 0 ;
V_12 = F_3 ( V_10 , V_16 , & V_13 ) ;
if ( V_12 )
return V_12 ;
if ( V_13 & ( 1 << 1 ) )
V_6 -> V_15 = 1 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_4 ( struct V_21 * V_22 )
{
int V_12 = 0 ;
struct V_7 * V_8 ;
struct V_23 * V_11 = F_5 ( V_22 -> V_24 . V_25 ) ;
struct V_26 * V_27 = F_6 ( V_11 -> V_24 ) ;
struct V_28 V_29 = {} ;
if ( ! V_27 )
return - V_20 ;
if ( V_27 -> V_30 ) {
int V_6 = ( V_27 -> V_30 - 50 ) / 10 ;
if ( V_6 < 0 )
V_6 = 0 ;
if ( V_6 > 0xf )
V_6 = 0xf ;
V_12 = F_7 ( V_11 -> V_10 ,
V_31 , V_6 , 0xf ) ;
if ( V_12 < 0 ) {
F_8 ( & V_22 -> V_24 , L_1 ) ;
return V_12 ;
}
}
switch ( V_27 -> V_32 ) {
case 5 :
V_12 = F_7 ( V_11 -> V_10 , V_33 ,
0x2 << 4 , 0x7 << 4 ) ;
break;
case 6 :
V_12 = F_7 ( V_11 -> V_10 , V_33 ,
0x3 << 4 , 0x7 << 4 ) ;
break;
case 7 :
V_12 = F_7 ( V_11 -> V_10 , V_33 ,
0x4 << 4 , 0x7 << 4 ) ;
break;
case 0 :
V_12 = F_7 ( V_11 -> V_10 , V_33 ,
0x7 << 4 , 0x7 << 4 ) ;
break;
default:
F_8 ( & V_22 -> V_24 , L_2 ,
V_27 -> V_32 ) ;
return - V_20 ;
}
if ( V_12 < 0 ) {
F_8 ( & V_22 -> V_24 , L_1 ) ;
return V_12 ;
}
V_8 = F_9 ( & V_22 -> V_24 , sizeof( struct V_7 ) ,
V_34 ) ;
if ( V_8 == NULL ) {
F_8 ( & V_22 -> V_24 , L_3 ) ;
return - V_35 ;
}
F_10 ( V_22 , V_8 ) ;
V_8 -> V_24 = & V_22 -> V_24 ;
V_8 -> V_11 = V_11 ;
V_29 . V_36 = V_8 ;
V_8 -> V_37 = F_11 ( & V_22 -> V_24 ,
& V_38 ,
& V_29 ) ;
if ( F_12 ( V_8 -> V_37 ) ) {
F_8 ( & V_22 -> V_24 , L_4 ) ;
return F_13 ( V_8 -> V_37 ) ;
}
return 0 ;
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_7 * V_8 = F_15 ( V_22 ) ;
F_16 ( V_8 -> V_37 ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_39 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_39 ) ;
}
