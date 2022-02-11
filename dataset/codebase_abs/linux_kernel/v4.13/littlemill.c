static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_2 -> V_12 [ 0 ] . V_13 ) ;
V_10 = V_8 -> V_14 ;
if ( V_4 -> V_15 != V_10 -> V_15 )
return 0 ;
switch ( V_6 ) {
case V_16 :
if ( V_4 -> V_17 == V_18 ) {
V_11 = F_3 ( V_10 , V_19 ,
V_20 , 32768 ,
V_21 * 512 ) ;
if ( V_11 < 0 ) {
F_4 ( L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_5 ( V_10 ,
V_22 ,
V_21 * 512 ,
V_23 ) ;
if ( V_11 < 0 ) {
F_4 ( L_2 , V_11 ) ;
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
V_10 = V_8 -> V_14 ;
if ( V_4 -> V_15 != V_10 -> V_15 )
return 0 ;
switch ( V_6 ) {
case V_18 :
V_11 = F_5 ( V_10 , V_24 ,
32768 , V_23 ) ;
if ( V_11 < 0 ) {
F_4 ( L_3 , V_11 ) ;
return V_11 ;
}
V_11 = F_3 ( V_10 , V_19 ,
0 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_4 ( L_4 , V_11 ) ;
return V_11 ;
}
break;
default:
break;
}
V_4 -> V_17 = V_6 ;
return 0 ;
}
static int F_7 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_7 * V_8 = V_26 -> V_29 ;
struct V_9 * V_14 = V_8 -> V_14 ;
int V_11 ;
V_21 = F_8 ( V_28 ) ;
V_11 = F_3 ( V_14 , V_19 ,
V_20 , 32768 ,
V_21 * 512 ) ;
if ( V_11 < 0 ) {
F_4 ( L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_5 ( V_14 ,
V_22 ,
V_21 * 512 ,
V_23 ) ;
if ( V_11 < 0 ) {
F_4 ( L_2 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static int F_9 ( struct V_30 * V_31 ,
struct V_32 * V_33 , int V_34 )
{
struct V_1 * V_2 = V_31 -> V_4 -> V_2 ;
struct V_7 * V_8 ;
struct V_9 * V_35 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_2 -> V_12 [ 1 ] . V_13 ) ;
V_35 = V_8 -> V_36 ;
switch ( V_34 ) {
case V_37 :
V_11 = F_3 ( V_35 , V_38 ,
V_39 , 64 * 8000 ,
8000 * 256 ) ;
if ( V_11 < 0 ) {
F_4 ( L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_5 ( V_35 , V_40 ,
8000 * 256 ,
V_23 ) ;
if ( V_11 < 0 ) {
F_4 ( L_2 , V_11 ) ;
return V_11 ;
}
break;
case V_41 :
V_11 = F_5 ( V_35 , V_24 ,
32768 , V_23 ) ;
if ( V_11 < 0 ) {
F_4 ( L_5 , V_11 ) ;
return V_11 ;
}
V_11 = F_3 ( V_35 , V_38 ,
0 , 0 , 0 ) ;
if ( V_11 < 0 ) {
F_4 ( L_6 , V_11 ) ;
return V_11 ;
}
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_43 * V_44 ;
struct V_9 * V_10 ;
struct V_9 * V_35 ;
int V_11 ;
V_8 = F_2 ( V_2 , V_2 -> V_12 [ 0 ] . V_13 ) ;
V_44 = V_8 -> V_44 ;
V_10 = V_8 -> V_14 ;
V_8 = F_2 ( V_2 , V_2 -> V_12 [ 1 ] . V_13 ) ;
V_35 = V_8 -> V_36 ;
V_11 = F_5 ( V_10 , V_24 ,
32768 , V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_5 ( V_35 , V_24 ,
32768 , V_23 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_11 ( V_2 , L_7 ,
V_45 | V_46 |
V_47 | V_48 |
V_49 | V_50 |
V_51 | V_52 ,
& V_53 , NULL , 0 ) ;
if ( V_11 )
return V_11 ;
F_12 ( V_44 , & V_53 , NULL , NULL , NULL , NULL ) ;
F_13 ( V_44 , & V_53 , 1 ) ;
return 0 ;
}
static int F_14 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = & V_56 ;
int V_11 ;
V_2 -> V_15 = & V_55 -> V_15 ;
V_11 = F_15 ( & V_55 -> V_15 , V_2 ) ;
if ( V_11 )
F_16 ( & V_55 -> V_15 , L_8 ,
V_11 ) ;
return V_11 ;
}
