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
V_17 * 512 ) ;
if ( V_10 < 0 ) {
F_3 ( L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_4 ( V_8 ,
V_18 ,
V_17 * 512 ,
V_19 ) ;
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
V_10 = F_4 ( V_8 , V_20 ,
32768 , V_19 ) ;
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
static int F_6 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_9 = V_22 -> V_26 ;
struct V_7 * V_8 = V_9 -> V_8 ;
int V_10 ;
V_17 = F_7 ( V_24 ) ;
V_10 = F_2 ( V_8 , V_15 ,
V_16 , 32768 ,
V_17 * 512 ) ;
if ( V_10 < 0 ) {
F_3 ( L_1 , V_10 ) ;
return V_10 ;
}
V_10 = F_4 ( V_8 ,
V_18 ,
V_17 * 512 ,
V_19 ) ;
if ( V_10 < 0 ) {
F_3 ( L_2 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = V_2 -> V_9 [ 0 ] . V_28 ;
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_8 ;
int V_10 ;
V_10 = F_4 ( V_8 , V_20 ,
32768 , V_19 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_9 ( V_28 , L_5 ,
V_29 | V_30 |
V_31 | V_32 |
V_33 | V_34 |
V_35 | V_36 ,
& V_37 ) ;
if ( V_10 )
return V_10 ;
F_10 ( V_28 , & V_37 , NULL , NULL ) ;
return 0 ;
}
static T_1 int F_11 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = & V_40 ;
int V_10 ;
V_2 -> V_11 = & V_39 -> V_11 ;
V_10 = F_12 ( V_2 ) ;
if ( V_10 ) {
F_13 ( & V_39 -> V_11 , L_6 ,
V_10 ) ;
return V_10 ;
}
return 0 ;
}
static int T_2 F_14 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_15 ( V_39 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
