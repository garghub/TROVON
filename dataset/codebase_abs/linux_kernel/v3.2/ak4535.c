static int F_1 ( struct V_1 * V_2 ,
int V_3 , unsigned int V_4 , int V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
V_9 -> V_10 = V_4 ;
return 0 ;
}
static int F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 ,
struct V_1 * V_15 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_6 * V_7 = V_17 -> V_7 ;
struct V_8 * V_9 = F_2 ( V_7 ) ;
T_1 V_19 = F_4 ( V_7 , V_20 ) & ~ ( 0x3 << 5 ) ;
int V_21 = F_5 ( V_14 ) , V_22 = 256 ;
if ( V_21 )
V_22 = V_9 -> V_10 / V_21 ;
switch ( V_22 ) {
case 1024 :
V_19 |= ( 0x2 << 5 ) ;
break;
case 512 :
V_19 |= ( 0x1 << 5 ) ;
break;
case 256 :
break;
}
F_6 ( V_7 , V_20 , V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_1 V_24 = 0 ;
switch ( V_23 & V_25 ) {
case V_26 :
V_24 = 0x0002 ;
break;
case V_27 :
V_24 = 0x0001 ;
break;
default:
return - V_28 ;
}
V_24 |= 0x4 ;
F_6 ( V_7 , V_29 , V_24 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_15 , int V_30 )
{
struct V_6 * V_7 = V_15 -> V_7 ;
T_2 V_31 = F_4 ( V_7 , V_32 ) ;
if ( ! V_30 )
F_6 ( V_7 , V_32 , V_31 & ~ 0x20 ) ;
else
F_6 ( V_7 , V_32 , V_31 | 0x20 ) ;
return 0 ;
}
static int F_9 ( struct V_6 * V_7 ,
enum V_33 V_34 )
{
switch ( V_34 ) {
case V_35 :
F_10 ( V_7 , V_32 , 0x20 , 0 ) ;
break;
case V_36 :
F_10 ( V_7 , V_32 , 0x20 , 0x20 ) ;
break;
case V_37 :
F_10 ( V_7 , V_38 , 0x80 , 0x80 ) ;
F_10 ( V_7 , V_39 , 0x80 , 0 ) ;
break;
case V_40 :
F_10 ( V_7 , V_38 , 0x80 , 0 ) ;
break;
}
V_7 -> V_41 . V_42 = V_34 ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , T_3 V_43 )
{
F_9 ( V_7 , V_40 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 )
{
F_13 ( V_7 ) ;
F_9 ( V_7 , V_37 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_44 ;
F_15 ( V_45 L_1 , V_46 ) ;
V_44 = F_16 ( V_7 , 8 , 8 , V_9 -> V_47 ) ;
if ( V_44 < 0 ) {
F_17 ( V_7 -> V_48 , L_2 , V_44 ) ;
return V_44 ;
}
F_9 ( V_7 , V_37 ) ;
F_18 ( V_7 , V_49 ,
F_19 ( V_49 ) ) ;
return 0 ;
}
static int F_20 ( struct V_6 * V_7 )
{
F_9 ( V_7 , V_40 ) ;
return 0 ;
}
static T_4 int F_21 ( struct V_50 * V_51 ,
const struct V_52 * V_53 )
{
struct V_8 * V_9 ;
int V_44 ;
V_9 = F_22 ( sizeof( struct V_8 ) , V_54 ) ;
if ( V_9 == NULL )
return - V_55 ;
F_23 ( V_51 , V_9 ) ;
V_9 -> V_47 = V_56 ;
V_44 = F_24 ( & V_51 -> V_48 ,
& V_57 , & V_58 , 1 ) ;
if ( V_44 < 0 )
F_25 ( V_9 ) ;
return V_44 ;
}
static T_5 int F_26 ( struct V_50 * V_59 )
{
F_27 ( & V_59 -> V_48 ) ;
F_25 ( F_28 ( V_59 ) ) ;
return 0 ;
}
static int T_6 F_29 ( void )
{
int V_44 = 0 ;
#if F_30 ( V_60 ) || F_30 ( V_61 )
V_44 = F_31 ( & V_62 ) ;
if ( V_44 != 0 ) {
F_15 ( V_63 L_3 ,
V_44 ) ;
}
#endif
return V_44 ;
}
static void T_7 F_32 ( void )
{
#if F_30 ( V_60 ) || F_30 ( V_61 )
F_33 ( & V_62 ) ;
#endif
}
