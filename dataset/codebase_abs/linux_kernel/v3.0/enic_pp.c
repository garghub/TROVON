static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
struct V_4 * V_5 ;
const T_1 V_6 [ 3 ] = V_7 ;
const T_2 V_8 = F_2 ( V_9 ) ;
char V_10 [ 38 ] ;
char V_11 [ 18 ] ;
T_1 * V_12 ;
int V_13 ;
if ( ! ( V_1 -> V_14 . V_15 & V_16 ) || ! strlen ( V_1 -> V_14 . V_17 ) )
return - V_18 ;
V_5 = F_3 ( V_19 , V_6 ,
V_20 ) ;
if ( ! V_5 )
return - V_21 ;
F_4 ( V_5 ,
V_22 ,
strlen ( V_1 -> V_14 . V_17 ) + 1 , V_1 -> V_14 . V_17 ) ;
if ( ! F_5 ( V_1 -> V_14 . V_23 ) )
V_12 = V_1 -> V_14 . V_23 ;
else
V_12 = V_3 -> V_24 ;
F_4 ( V_5 ,
V_25 ,
V_26 , V_12 ) ;
snprintf ( V_11 , sizeof( V_11 ) , L_1 , V_12 ) ;
F_4 ( V_5 ,
V_27 ,
sizeof( V_11 ) , V_11 ) ;
if ( V_1 -> V_14 . V_15 & V_28 ) {
sprintf ( V_10 , L_2 , V_1 -> V_14 . V_29 ) ;
F_4 ( V_5 ,
V_30 ,
sizeof( V_10 ) , V_10 ) ;
}
if ( V_1 -> V_14 . V_15 & V_31 ) {
sprintf ( V_10 , L_2 , V_1 -> V_14 . V_32 ) ;
F_4 ( V_5 ,
V_33 ,
sizeof( V_10 ) , V_10 ) ;
}
F_4 ( V_5 ,
V_34 ,
sizeof( V_8 ) , & V_8 ) ;
V_13 = F_6 ( F_7 ( V_1 , V_5 ) ) ;
V_35:
F_8 ( V_5 ) ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_1 )
{
int V_13 ;
V_13 = F_10 ( V_1 ) ;
if ( V_13 )
return F_6 ( V_13 ) ;
F_11 ( V_1 ) ;
return 0 ;
}
static int F_12 ( struct V_36 * V_37 ,
struct V_36 * V_38 )
{
return strcmp ( V_37 -> V_17 , V_38 -> V_17 ) | ! ! memcmp ( V_37 -> V_29 ,
V_38 -> V_29 , V_39 ) |
! ! memcmp ( V_37 -> V_32 , V_38 -> V_32 , V_39 ) |
! ! memcmp ( V_37 -> V_23 , V_38 -> V_23 , V_26 ) ;
}
static int F_13 ( struct V_1 * V_1 ,
struct V_36 * V_40 , int * V_41 )
{
return - V_42 ;
}
static int F_14 ( struct V_1 * V_1 ,
struct V_36 * V_40 , int * V_41 )
{
return F_9 ( V_1 ) ;
}
static int F_15 ( struct V_1 * V_1 ,
struct V_36 * V_40 , int * V_41 )
{
int V_13 ;
int V_43 = 0 ;
if ( V_1 -> V_14 . V_44 != V_45 ) {
V_13 = V_46 [ V_47 ] ( V_1 ,
V_40 , V_41 ) ;
if ( V_13 )
return V_13 ;
* V_41 = 0 ;
}
* V_41 = 0 ;
V_13 = F_1 ( V_1 ) ;
if ( V_13 )
return V_13 ;
if ( V_1 -> V_14 . V_44 != V_45 )
V_13 = F_6 ( F_16 ( V_1 , V_43 ) ) ;
return V_13 ;
}
static int F_17 ( struct V_1 * V_1 ,
struct V_36 * V_40 , int * V_41 )
{
int V_13 ;
int V_43 = 1 ;
if ( V_40 -> V_44 != V_48 ||
( V_40 -> V_44 == V_48 &&
F_12 ( V_40 , & V_1 -> V_14 ) ) ) {
V_13 = V_46 [ V_47 ] (
V_1 , V_40 , V_41 ) ;
if ( V_13 )
return V_13 ;
* V_41 = 0 ;
}
V_13 = V_46 [ V_48 ] (
V_1 , V_40 , V_41 ) ;
if ( V_13 )
return V_13 ;
* V_41 = 0 ;
return F_6 ( F_16 ( V_1 , V_43 ) ) ;
}
int F_18 ( struct V_1 * V_1 ,
struct V_36 * V_40 , int * V_41 )
{
if ( V_1 -> V_14 . V_44 < V_49
&& V_46 [ V_1 -> V_14 . V_44 ] )
return V_46 [ V_1 -> V_14 . V_44 ] ( V_1 ,
V_40 , V_41 ) ;
else
return - V_42 ;
}
int F_19 ( struct V_1 * V_1 , int V_44 ,
T_2 * V_50 )
{
int V_13 , V_51 = V_52 ;
switch ( V_44 ) {
case V_48 :
case V_45 :
V_13 = F_20 ( V_1 , & V_51 ) ;
break;
case V_47 :
V_13 = F_21 ( V_1 , & V_51 ) ;
break;
default:
return - V_18 ;
}
if ( V_13 )
V_51 = V_13 ;
switch ( V_51 ) {
case V_52 :
* V_50 = V_53 ;
break;
case V_54 :
* V_50 = V_55 ;
break;
case V_56 :
* V_50 = V_57 ;
break;
case V_58 :
* V_50 = V_59 ;
break;
case V_60 :
* V_50 = V_61 ;
break;
default:
* V_50 = V_62 ;
break;
}
return 0 ;
}
