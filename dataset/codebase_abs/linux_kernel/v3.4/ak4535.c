static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_5 * V_6 ,
int V_7 , unsigned int V_8 , int V_9 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
V_13 -> V_14 = V_8 ;
return 0 ;
}
static int F_4 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
struct V_5 * V_19 )
{
struct V_20 * V_21 = V_16 -> V_22 ;
struct V_10 * V_11 = V_21 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
T_1 V_23 = F_5 ( V_11 , V_24 ) & ~ ( 0x3 << 5 ) ;
int V_25 = F_6 ( V_18 ) , V_26 = 256 ;
if ( V_25 )
V_26 = V_13 -> V_14 / V_25 ;
switch ( V_26 ) {
case 1024 :
V_23 |= ( 0x2 << 5 ) ;
break;
case 512 :
V_23 |= ( 0x1 << 5 ) ;
break;
case 256 :
break;
}
F_7 ( V_11 , V_24 , V_23 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 ,
unsigned int V_27 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
T_1 V_28 = 0 ;
switch ( V_27 & V_29 ) {
case V_30 :
V_28 = 0x0002 ;
break;
case V_31 :
V_28 = 0x0001 ;
break;
default:
return - V_32 ;
}
V_28 |= 0x4 ;
F_7 ( V_11 , V_33 , V_28 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_19 , int V_34 )
{
struct V_10 * V_11 = V_19 -> V_11 ;
T_2 V_35 = F_5 ( V_11 , V_36 ) ;
if ( ! V_34 )
F_7 ( V_11 , V_36 , V_35 & ~ 0x20 ) ;
else
F_7 ( V_11 , V_36 , V_35 | 0x20 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 ,
enum V_37 V_38 )
{
switch ( V_38 ) {
case V_39 :
F_11 ( V_11 , V_36 , 0x20 , 0 ) ;
break;
case V_40 :
F_11 ( V_11 , V_36 , 0x20 , 0x20 ) ;
break;
case V_41 :
F_11 ( V_11 , V_42 , 0x80 , 0x80 ) ;
F_11 ( V_11 , V_43 , 0x80 , 0 ) ;
break;
case V_44 :
F_11 ( V_11 , V_42 , 0x80 , 0 ) ;
break;
}
V_11 -> V_45 . V_46 = V_38 ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 )
{
F_10 ( V_11 , V_44 ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
F_14 ( V_11 ) ;
F_10 ( V_11 , V_41 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = F_3 ( V_11 ) ;
int V_47 ;
V_11 -> V_48 = V_13 -> V_49 ;
V_47 = F_16 ( V_11 , 8 , 8 , V_50 ) ;
if ( V_47 < 0 ) {
F_17 ( V_11 -> V_2 , L_1 , V_47 ) ;
return V_47 ;
}
F_10 ( V_11 , V_41 ) ;
F_18 ( V_11 , V_51 ,
F_19 ( V_51 ) ) ;
return 0 ;
}
static int F_20 ( struct V_10 * V_11 )
{
F_10 ( V_11 , V_44 ) ;
return 0 ;
}
static T_3 int F_21 ( struct V_52 * V_53 ,
const struct V_54 * V_55 )
{
struct V_12 * V_13 ;
int V_47 ;
V_13 = F_22 ( & V_53 -> V_2 , sizeof( struct V_12 ) ,
V_56 ) ;
if ( V_13 == NULL )
return - V_57 ;
V_13 -> V_49 = F_23 ( V_53 , & V_58 ) ;
if ( F_24 ( V_13 -> V_49 ) ) {
V_47 = F_25 ( V_13 -> V_49 ) ;
F_17 ( & V_53 -> V_2 , L_2 , V_47 ) ;
return V_47 ;
}
F_26 ( V_53 , V_13 ) ;
V_47 = F_27 ( & V_53 -> V_2 ,
& V_59 , & V_60 , 1 ) ;
if ( V_47 != 0 )
F_28 ( V_13 -> V_49 ) ;
return V_47 ;
}
static T_4 int F_29 ( struct V_52 * V_61 )
{
struct V_12 * V_13 = F_30 ( V_61 ) ;
F_31 ( & V_61 -> V_2 ) ;
F_28 ( V_13 -> V_49 ) ;
return 0 ;
}
