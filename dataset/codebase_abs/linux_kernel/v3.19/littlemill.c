static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_10 ;
int V_11 ;
if ( V_4 -> V_12 != V_8 -> V_12 )
return 0 ;
switch ( V_6 ) {
case V_13 :
if ( V_4 -> V_14 == V_15 ) {
V_11 = F_2 ( V_8 , V_16 ,
V_17 , 32768 ,
V_18 * 512 ) ;
if ( V_11 < 0 ) {
F_3 ( L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_4 ( V_8 ,
V_19 ,
V_18 * 512 ,
V_20 ) ;
if ( V_11 < 0 ) {
F_3 ( L_2 , V_11 ) ;
return V_11 ;
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
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_10 ;
int V_11 ;
if ( V_4 -> V_12 != V_8 -> V_12 )
return 0 ;
switch ( V_6 ) {
case V_15 :
V_11 = F_4 ( V_8 , V_21 ,
32768 , V_20 ) ;
if ( V_11 < 0 ) {
F_3 ( L_3 , V_11 ) ;
return V_11 ;
}
V_11 = F_2 ( V_8 , V_16 ,
0 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_3 ( L_4 , V_11 ) ;
return V_11 ;
}
break;
default:
break;
}
V_4 -> V_14 = V_6 ;
return 0 ;
}
static int F_6 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_9 = V_23 -> V_27 ;
struct V_7 * V_10 = V_9 -> V_10 ;
int V_11 ;
V_18 = F_7 ( V_25 ) ;
V_11 = F_2 ( V_10 , V_16 ,
V_17 , 32768 ,
V_18 * 512 ) ;
if ( V_11 < 0 ) {
F_3 ( L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_4 ( V_10 ,
V_19 ,
V_18 * 512 ,
V_20 ) ;
if ( V_11 < 0 ) {
F_3 ( L_2 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_8 ( struct V_28 * V_29 ,
struct V_30 * V_31 , int V_32 )
{
struct V_1 * V_2 = V_29 -> V_4 -> V_2 ;
struct V_7 * V_33 = V_2 -> V_9 [ 1 ] . V_34 ;
int V_11 ;
switch ( V_32 ) {
case V_35 :
V_11 = F_2 ( V_33 , V_36 ,
V_37 , 64 * 8000 ,
8000 * 256 ) ;
if ( V_11 < 0 ) {
F_3 ( L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_4 ( V_33 , V_38 ,
8000 * 256 ,
V_20 ) ;
if ( V_11 < 0 ) {
F_3 ( L_2 , V_11 ) ;
return V_11 ;
}
break;
case V_39 :
V_11 = F_4 ( V_33 , V_21 ,
32768 , V_20 ) ;
if ( V_11 < 0 ) {
F_3 ( L_5 , V_11 ) ;
return V_11 ;
}
V_11 = F_2 ( V_33 , V_36 ,
0 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_3 ( L_6 , V_11 ) ;
return V_11 ;
}
break;
default:
return - V_40 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = V_2 -> V_9 [ 0 ] . V_42 ;
struct V_7 * V_8 = V_2 -> V_9 [ 0 ] . V_10 ;
struct V_7 * V_33 = V_2 -> V_9 [ 1 ] . V_34 ;
int V_11 ;
V_11 = F_4 ( V_8 , V_21 ,
32768 , V_20 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_4 ( V_33 , V_21 ,
32768 , V_20 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_10 ( V_42 , L_7 ,
V_43 | V_44 |
V_45 | V_46 |
V_47 | V_48 |
V_49 | V_50 ,
& V_51 ) ;
if ( V_11 )
return V_11 ;
F_11 ( V_42 , & V_51 , NULL , NULL , NULL , NULL ) ;
F_12 ( V_42 , & V_51 , 1 ) ;
return 0 ;
}
static int F_13 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = & V_54 ;
int V_11 ;
V_2 -> V_12 = & V_53 -> V_12 ;
V_11 = F_14 ( & V_53 -> V_12 , V_2 ) ;
if ( V_11 )
F_15 ( & V_53 -> V_12 , L_8 ,
V_11 ) ;
return V_11 ;
}
