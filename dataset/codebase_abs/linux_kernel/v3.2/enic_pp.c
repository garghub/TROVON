int F_1 ( struct V_1 * V_1 , int V_2 , int * V_3 )
{
if ( V_2 != V_4 ) {
#ifdef F_2
if ( F_3 ( V_1 ) ) {
if ( V_2 < 0 || V_2 >= V_1 -> V_5 ) {
* V_3 = - V_6 ;
goto V_7;
}
} else {
* V_3 = - V_8 ;
goto V_7;
}
#else
* V_3 = - V_8 ;
goto V_7;
#endif
}
if ( V_2 == V_4 && ! F_4 ( V_1 ) ) {
* V_3 = - V_8 ;
goto V_7;
}
* V_3 = 0 ;
return 1 ;
V_7:
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , int V_2 )
{
struct V_9 * V_10 = V_1 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
const T_1 V_15 [ 3 ] = V_16 ;
const T_2 V_17 = F_6 ( V_18 ) ;
char V_19 [ 38 ] ;
char V_20 [ 18 ] ;
T_1 * V_21 ;
int V_3 ;
F_7 ( V_1 , V_2 , V_12 , & V_3 ) ;
if ( V_3 )
return V_3 ;
if ( ! ( V_12 -> V_22 & V_23 ) || ! strlen ( V_12 -> V_24 ) )
return - V_6 ;
V_14 = F_8 ( V_25 , V_15 ,
V_26 ) ;
if ( ! V_14 )
return - V_27 ;
F_9 ( V_14 ,
V_28 ,
strlen ( V_12 -> V_24 ) + 1 , V_12 -> V_24 ) ;
if ( ! F_10 ( V_12 -> V_29 ) ) {
V_21 = V_12 -> V_29 ;
} else if ( V_2 == V_4 ) {
V_21 = V_10 -> V_30 ;
} else {
F_11 ( V_10 , L_1
L_2 , V_2 ) ;
V_3 = - V_6 ;
goto V_31;
}
F_9 ( V_14 ,
V_32 ,
V_33 , V_21 ) ;
snprintf ( V_20 , sizeof( V_20 ) , L_3 , V_21 ) ;
F_9 ( V_14 ,
V_34 ,
sizeof( V_20 ) , V_20 ) ;
if ( V_12 -> V_22 & V_35 ) {
sprintf ( V_19 , L_4 , V_12 -> V_36 ) ;
F_9 ( V_14 ,
V_37 ,
sizeof( V_19 ) , V_19 ) ;
}
if ( V_12 -> V_22 & V_38 ) {
sprintf ( V_19 , L_4 , V_12 -> V_39 ) ;
F_9 ( V_14 ,
V_40 ,
sizeof( V_19 ) , V_19 ) ;
}
F_9 ( V_14 ,
V_41 ,
sizeof( V_17 ) , & V_17 ) ;
F_12 ( V_2 , V_3 , V_1 , V_42 , ( T_1 * ) V_14 ,
F_13 ( V_14 ) ) ;
V_3 = F_14 ( V_3 ) ;
V_31:
F_15 ( V_14 ) ;
return V_3 ;
}
static int F_16 ( struct V_1 * V_1 , int V_2 )
{
int V_3 ;
F_12 ( V_2 , V_3 , V_1 , V_43 ) ;
if ( V_3 )
return F_14 ( V_3 ) ;
if ( V_2 == V_4 )
F_17 ( V_1 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_44 ,
struct V_11 * V_45 )
{
return strcmp ( V_44 -> V_24 , V_45 -> V_24 ) | ! ! memcmp ( V_44 -> V_36 ,
V_45 -> V_36 , V_46 ) |
! ! memcmp ( V_44 -> V_39 , V_45 -> V_39 , V_46 ) |
! ! memcmp ( V_44 -> V_29 , V_45 -> V_29 , V_33 ) ;
}
static int F_19 ( struct V_1 * V_1 , int V_2 ,
struct V_11 * V_47 , int * V_48 )
{
return - V_8 ;
}
static int F_20 ( struct V_1 * V_1 , int V_2 ,
struct V_11 * V_47 , int * V_48 )
{
struct V_9 * V_10 = V_1 -> V_10 ;
struct V_11 * V_12 ;
int V_3 ;
F_7 ( V_1 , V_2 , V_12 , & V_3 ) ;
if ( V_3 )
return V_3 ;
if ( ! F_10 ( V_12 -> V_29 ) )
F_12 ( V_2 , V_3 , V_1 , V_49 ,
V_12 -> V_29 ) ;
else if ( ! F_10 ( V_10 -> V_30 ) )
F_12 ( V_2 , V_3 , V_1 , V_49 ,
V_10 -> V_30 ) ;
return F_16 ( V_1 , V_2 ) ;
}
static int F_21 ( struct V_1 * V_1 , int V_2 ,
struct V_11 * V_47 , int * V_48 )
{
struct V_11 * V_12 ;
int V_3 ;
int V_50 = 0 ;
F_7 ( V_1 , V_2 , V_12 , & V_3 ) ;
if ( V_3 )
return V_3 ;
if ( V_12 -> V_51 != V_52 ) {
V_3 = V_53 [ V_54 ] ( V_1 , V_2 ,
V_47 , V_48 ) ;
if ( V_3 )
return V_3 ;
* V_48 = 0 ;
}
* V_48 = 0 ;
V_3 = F_5 ( V_1 , V_2 ) ;
if ( V_3 )
return V_3 ;
if ( V_12 -> V_51 != V_52 ) {
F_12 ( V_2 , V_3 , V_1 , V_55 ,
V_50 ) ;
V_3 = F_14 ( V_3 ) ;
}
return V_3 ;
}
static int F_22 ( struct V_1 * V_1 , int V_2 ,
struct V_11 * V_47 , int * V_48 )
{
struct V_9 * V_10 = V_1 -> V_10 ;
struct V_11 * V_12 ;
int V_3 ;
int V_50 = 1 ;
F_7 ( V_1 , V_2 , V_12 , & V_3 ) ;
if ( V_3 )
return V_3 ;
if ( V_47 -> V_51 != V_56 ||
( V_47 -> V_51 == V_56 &&
F_18 ( V_47 , V_12 ) ) ) {
V_3 = V_53 [ V_54 ] (
V_1 , V_2 , V_47 , V_48 ) ;
if ( V_3 )
return V_3 ;
* V_48 = 0 ;
}
V_3 = V_53 [ V_56 ] (
V_1 , V_2 , V_47 , V_48 ) ;
if ( V_3 )
return V_3 ;
* V_48 = 0 ;
F_12 ( V_2 , V_3 , V_1 , V_55 , V_50 ) ;
V_3 = F_14 ( V_3 ) ;
if ( V_3 )
return V_3 ;
if ( ! F_10 ( V_12 -> V_29 ) )
F_12 ( V_2 , V_3 , V_1 , V_57 ,
V_12 -> V_29 ) ;
else if ( ! F_10 ( V_10 -> V_30 ) )
F_12 ( V_2 , V_3 , V_1 , V_57 ,
V_10 -> V_30 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_1 , int V_2 ,
struct V_11 * V_47 , int * V_48 )
{
struct V_11 * V_12 ;
int V_3 ;
F_7 ( V_1 , V_2 , V_12 , & V_3 ) ;
if ( V_3 )
return V_3 ;
if ( V_12 -> V_51 >= V_58
|| ! V_53 [ V_12 -> V_51 ] )
return - V_8 ;
return V_53 [ V_12 -> V_51 ] ( V_1 , V_2 , V_47 , V_48 ) ;
}
int F_24 ( struct V_1 * V_1 , int V_2 ,
int V_51 , T_2 * V_59 )
{
int V_3 , V_60 = V_61 ;
switch ( V_51 ) {
case V_56 :
case V_52 :
F_12 ( V_2 , V_3 , V_1 ,
V_62 , & V_60 ) ;
break;
case V_54 :
F_12 ( V_2 , V_3 , V_1 ,
V_63 , & V_60 ) ;
break;
default:
return - V_6 ;
}
if ( V_3 )
V_60 = V_3 ;
switch ( V_60 ) {
case V_61 :
* V_59 = V_64 ;
break;
case V_65 :
* V_59 = V_66 ;
break;
case V_67 :
* V_59 = V_68 ;
break;
case V_69 :
* V_59 = V_70 ;
break;
case V_71 :
* V_59 = V_72 ;
break;
default:
* V_59 = V_73 ;
break;
}
return 0 ;
}
