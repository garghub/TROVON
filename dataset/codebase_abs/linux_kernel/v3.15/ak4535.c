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
struct V_10 * V_11 = V_19 -> V_11 ;
struct V_12 * V_13 = F_3 ( V_11 ) ;
T_1 V_20 = F_5 ( V_11 , V_21 ) & ~ ( 0x3 << 5 ) ;
int V_22 = F_6 ( V_18 ) , V_23 = 256 ;
if ( V_22 )
V_23 = V_13 -> V_14 / V_22 ;
switch ( V_23 ) {
case 1024 :
V_20 |= ( 0x2 << 5 ) ;
break;
case 512 :
V_20 |= ( 0x1 << 5 ) ;
break;
case 256 :
break;
}
F_7 ( V_11 , V_21 , V_20 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 ,
unsigned int V_24 )
{
struct V_10 * V_11 = V_6 -> V_11 ;
T_1 V_25 = 0 ;
switch ( V_24 & V_26 ) {
case V_27 :
V_25 = 0x0002 ;
break;
case V_28 :
V_25 = 0x0001 ;
break;
default:
return - V_29 ;
}
V_25 |= 0x4 ;
F_7 ( V_11 , V_30 , V_25 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_19 , int V_31 )
{
struct V_10 * V_11 = V_19 -> V_11 ;
T_2 V_32 = F_5 ( V_11 , V_33 ) ;
if ( ! V_31 )
F_7 ( V_11 , V_33 , V_32 & ~ 0x20 ) ;
else
F_7 ( V_11 , V_33 , V_32 | 0x20 ) ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 ,
enum V_34 V_35 )
{
switch ( V_35 ) {
case V_36 :
F_11 ( V_11 , V_33 , 0x20 , 0 ) ;
break;
case V_37 :
F_11 ( V_11 , V_33 , 0x20 , 0x20 ) ;
break;
case V_38 :
F_11 ( V_11 , V_39 , 0x80 , 0x80 ) ;
F_11 ( V_11 , V_40 , 0x80 , 0 ) ;
break;
case V_41 :
F_11 ( V_11 , V_39 , 0x80 , 0 ) ;
break;
}
V_11 -> V_42 . V_43 = V_35 ;
return 0 ;
}
static int F_12 ( struct V_10 * V_11 )
{
F_10 ( V_11 , V_41 ) ;
return 0 ;
}
static int F_13 ( struct V_10 * V_11 )
{
F_14 ( V_11 ) ;
F_10 ( V_11 , V_38 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 )
{
F_10 ( V_11 , V_38 ) ;
F_16 ( V_11 , V_44 ,
F_17 ( V_44 ) ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 )
{
F_10 ( V_11 , V_41 ) ;
return 0 ;
}
static int F_19 ( struct V_45 * V_46 ,
const struct V_47 * V_48 )
{
struct V_12 * V_13 ;
int V_49 ;
V_13 = F_20 ( & V_46 -> V_2 , sizeof( struct V_12 ) ,
V_50 ) ;
if ( V_13 == NULL )
return - V_51 ;
V_13 -> V_52 = F_21 ( V_46 , & V_53 ) ;
if ( F_22 ( V_13 -> V_52 ) ) {
V_49 = F_23 ( V_13 -> V_52 ) ;
F_24 ( & V_46 -> V_2 , L_1 , V_49 ) ;
return V_49 ;
}
F_25 ( V_46 , V_13 ) ;
V_49 = F_26 ( & V_46 -> V_2 ,
& V_54 , & V_55 , 1 ) ;
return V_49 ;
}
static int F_27 ( struct V_45 * V_56 )
{
F_28 ( & V_56 -> V_2 ) ;
return 0 ;
}
