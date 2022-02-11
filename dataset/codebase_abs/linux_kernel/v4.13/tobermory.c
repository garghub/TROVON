static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_2 -> V_12 [ 0 ] . V_13 ) ;
V_10 = V_8 -> V_10 ;
if ( V_4 -> V_14 != V_10 -> V_14 )
return 0 ;
switch ( V_6 ) {
case V_15 :
if ( V_4 -> V_16 == V_17 ) {
V_11 = F_3 ( V_10 , V_18 ,
V_19 , 32768 ,
V_20 * 512 ) ;
if ( V_11 < 0 )
F_4 ( L_1 , V_11 ) ;
V_11 = F_5 ( V_10 ,
V_21 ,
V_20 * 512 ,
V_22 ) ;
if ( V_11 < 0 ) {
F_4 ( L_2 , V_11 ) ;
F_3 ( V_10 , V_18 ,
0 , 0 , 0 ) ;
return V_11 ;
}
}
break;
default:
break;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_2 -> V_12 [ 0 ] . V_13 ) ;
V_10 = V_8 -> V_10 ;
if ( V_4 -> V_14 != V_10 -> V_14 )
return 0 ;
switch ( V_6 ) {
case V_17 :
V_11 = F_5 ( V_10 , V_23 ,
32768 , V_22 ) ;
if ( V_11 < 0 ) {
F_4 ( L_3 , V_11 ) ;
return V_11 ;
}
V_11 = F_3 ( V_10 , V_18 ,
0 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_4 ( L_4 , V_11 ) ;
return V_11 ;
}
break;
default:
break;
}
V_4 -> V_16 = V_6 ;
return 0 ;
}
static int F_7 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
V_20 = F_8 ( V_27 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_28 * V_29 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_2 -> V_12 [ 0 ] . V_13 ) ;
V_29 = V_8 -> V_29 ;
V_10 = V_8 -> V_10 ;
V_11 = F_5 ( V_10 , V_23 ,
32768 , V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_10 ( V_2 , L_5 , V_30 |
V_31 , & V_32 ,
V_33 ,
F_11 ( V_33 ) ) ;
if ( V_11 )
return V_11 ;
F_12 ( V_29 , & V_32 ) ;
return 0 ;
}
static int F_13 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = & V_36 ;
int V_11 ;
V_2 -> V_14 = & V_35 -> V_14 ;
V_11 = F_14 ( & V_35 -> V_14 , V_2 ) ;
if ( V_11 )
F_15 ( & V_35 -> V_14 , L_6 ,
V_11 ) ;
return V_11 ;
}
