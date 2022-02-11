static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 = F_2 ( V_5 , V_7 ) ;
if ( V_3 )
F_3 ( V_5 , V_7 , V_6 | 1 ) ;
else
F_3 ( V_5 , V_7 , V_6 & ~ 1 ) ;
return 0 ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_12 = F_2 ( V_5 , V_7 ) ;
V_12 &= ~ 0x18 ;
switch ( F_5 ( V_11 ) ) {
case V_13 :
break;
case V_14 :
V_12 |= 0x10 ;
break;
case V_15 :
V_12 |= 0x08 ;
break;
default:
return - V_16 ;
}
F_3 ( V_5 , V_7 , V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_17 ,
unsigned int V_18 )
{
struct V_4 * V_5 = V_17 -> V_5 ;
T_1 V_19 = F_2 ( V_5 , V_20 ) ;
switch ( V_18 & V_21 ) {
case V_22 :
V_19 |= 1 ;
break;
default:
return - V_16 ;
}
switch ( V_18 & V_23 ) {
case V_24 :
break;
default:
return - V_16 ;
}
switch ( V_18 & V_25 ) {
case V_26 :
V_19 &= ~ 0x22 ;
break;
case V_27 :
V_19 |= 0x20 ;
V_19 &= ~ 0x02 ;
break;
case V_28 :
V_19 |= 0x02 ;
V_19 &= ~ 0x20 ;
break;
case V_29 :
V_19 |= 0x22 ;
break;
default:
return - V_16 ;
}
F_3 ( V_5 , V_20 , V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 ,
enum V_30 V_31 )
{
struct V_32 * V_33 = F_8 ( V_5 ) ;
T_1 V_34 ;
switch ( V_31 ) {
case V_35 :
case V_36 :
case V_37 :
if ( V_5 -> V_38 . V_39 == V_40 ) {
V_34 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_34 & ~ 0x4 ) ;
F_9 ( V_33 -> V_41 ) ;
}
break;
case V_40 :
V_34 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_34 | 0x4 ) ;
break;
}
V_5 -> V_38 . V_39 = V_31 ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_40 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_37 ) ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 )
{
int V_42 ;
V_42 = F_13 ( V_5 , 7 , 9 , V_43 ) ;
if ( V_42 < 0 ) {
F_14 ( V_44 L_1 ,
V_42 ) ;
return V_42 ;
}
F_7 ( V_5 , V_37 ) ;
return V_42 ;
}
static int F_15 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_40 ) ;
return 0 ;
}
static int F_16 ( struct V_45 * V_46 )
{
struct V_32 * V_33 ;
int V_42 ;
V_33 = F_17 ( & V_46 -> V_47 , sizeof( struct V_32 ) ,
V_48 ) ;
if ( V_33 == NULL )
return - V_49 ;
V_33 -> V_41 = F_18 ( V_46 , & V_50 ) ;
if ( F_19 ( V_33 -> V_41 ) )
return F_20 ( V_33 -> V_41 ) ;
F_21 ( V_46 , V_33 ) ;
V_42 = F_22 ( & V_46 -> V_47 ,
& V_51 , & V_52 , 1 ) ;
return V_42 ;
}
static int F_23 ( struct V_45 * V_46 )
{
F_24 ( & V_46 -> V_47 ) ;
return 0 ;
}
static int F_25 ( struct V_53 * V_54 ,
const struct V_55 * V_56 )
{
struct V_32 * V_33 ;
int V_42 ;
V_33 = F_17 ( & V_54 -> V_47 , sizeof( struct V_32 ) ,
V_48 ) ;
if ( V_33 == NULL )
return - V_49 ;
V_33 -> V_41 = F_26 ( V_54 , & V_50 ) ;
if ( F_19 ( V_33 -> V_41 ) )
return F_20 ( V_33 -> V_41 ) ;
F_27 ( V_54 , V_33 ) ;
V_42 = F_22 ( & V_54 -> V_47 ,
& V_51 , & V_52 , 1 ) ;
return V_42 ;
}
static int F_28 ( struct V_53 * V_57 )
{
F_24 ( & V_57 -> V_47 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
int V_42 = 0 ;
#if F_30 ( V_58 ) || F_30 ( V_59 )
V_42 = F_31 ( & V_60 ) ;
if ( V_42 != 0 ) {
F_14 ( V_44 L_2 ,
V_42 ) ;
}
#endif
#if F_30 ( V_61 )
V_42 = F_32 ( & V_62 ) ;
if ( V_42 != 0 ) {
F_14 ( V_44 L_3 ,
V_42 ) ;
}
#endif
return V_42 ;
}
static void T_3 F_33 ( void )
{
#if F_30 ( V_58 ) || F_30 ( V_59 )
F_34 ( & V_60 ) ;
#endif
#if F_30 ( V_61 )
F_35 ( & V_62 ) ;
#endif
}
