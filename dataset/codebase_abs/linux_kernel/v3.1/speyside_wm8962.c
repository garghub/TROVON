static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_8 ;
int V_10 ;
if ( V_4 -> V_11 != V_8 -> V_11 )
return 0 ;
switch ( V_6 ) {
case V_12 :
if ( V_4 -> V_13 == V_14 ) {
V_10 = F_2 ( V_8 , V_15 ,
V_16 , 32768 ,
44100 * 256 ) ;
if ( V_10 < 0 )
F_3 ( L_1 , V_10 ) ;
V_10 = F_4 ( V_8 ,
V_17 ,
44100 * 256 ,
V_18 ) ;
if ( V_10 < 0 ) {
F_3 ( L_2 , V_10 ) ;
return V_10 ;
}
}
break;
default:
break;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_8 ;
int V_10 ;
if ( V_4 -> V_11 != V_8 -> V_11 )
return 0 ;
switch ( V_6 ) {
case V_14 :
V_10 = F_4 ( V_8 , V_19 ,
32768 , V_18 ) ;
if ( V_10 < 0 ) {
F_3 ( L_3 , V_10 ) ;
return V_10 ;
}
V_10 = F_2 ( V_8 , V_15 ,
0 , 0 , 0 ) ;
if ( V_10 < 0 ) {
F_3 ( L_4 , V_10 ) ;
return V_10 ;
}
break;
default:
break;
}
V_4 -> V_13 = V_6 ;
return 0 ;
}
static int F_6 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_24 * V_9 = V_21 -> V_25 ;
struct V_7 * V_26 = V_9 -> V_26 ;
struct V_7 * V_8 = V_9 -> V_8 ;
int V_10 ;
V_10 = F_7 ( V_8 , V_27
| V_28
| V_29 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_7 ( V_26 , V_27
| V_28
| V_29 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = V_2 -> V_9 [ 0 ] . V_31 ;
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_8 ;
int V_10 ;
V_10 = F_4 ( V_8 , V_19 ,
32768 , V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_9 ( V_31 , L_5 ,
V_32 | V_33 ,
& V_34 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_10 ( & V_34 ,
F_11 ( V_35 ) ,
V_35 ) ;
if ( V_10 )
return V_10 ;
F_12 ( V_31 , & V_34 ) ;
return 0 ;
}
static T_1 int F_13 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = & V_38 ;
int V_10 ;
V_2 -> V_11 = & V_37 -> V_11 ;
V_10 = F_14 ( V_2 ) ;
if ( V_10 ) {
F_15 ( & V_37 -> V_11 , L_6 ,
V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int T_2 F_16 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = F_17 ( V_37 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_39 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_39 ) ;
}
