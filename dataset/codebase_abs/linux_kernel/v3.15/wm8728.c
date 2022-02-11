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
F_7 ( V_5 , V_37 ) ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_40 ) ;
return 0 ;
}
static int F_14 ( struct V_42 * V_43 )
{
struct V_32 * V_33 ;
int V_44 ;
V_33 = F_15 ( & V_43 -> V_45 , sizeof( struct V_32 ) ,
V_46 ) ;
if ( V_33 == NULL )
return - V_47 ;
V_33 -> V_41 = F_16 ( V_43 , & V_48 ) ;
if ( F_17 ( V_33 -> V_41 ) )
return F_18 ( V_33 -> V_41 ) ;
F_19 ( V_43 , V_33 ) ;
V_44 = F_20 ( & V_43 -> V_45 ,
& V_49 , & V_50 , 1 ) ;
return V_44 ;
}
static int F_21 ( struct V_42 * V_43 )
{
F_22 ( & V_43 -> V_45 ) ;
return 0 ;
}
static int F_23 ( struct V_51 * V_52 ,
const struct V_53 * V_54 )
{
struct V_32 * V_33 ;
int V_44 ;
V_33 = F_15 ( & V_52 -> V_45 , sizeof( struct V_32 ) ,
V_46 ) ;
if ( V_33 == NULL )
return - V_47 ;
V_33 -> V_41 = F_24 ( V_52 , & V_48 ) ;
if ( F_17 ( V_33 -> V_41 ) )
return F_18 ( V_33 -> V_41 ) ;
F_25 ( V_52 , V_33 ) ;
V_44 = F_20 ( & V_52 -> V_45 ,
& V_49 , & V_50 , 1 ) ;
return V_44 ;
}
static int F_26 ( struct V_51 * V_55 )
{
F_22 ( & V_55 -> V_45 ) ;
return 0 ;
}
static int T_2 F_27 ( void )
{
int V_44 = 0 ;
#if F_28 ( V_56 )
V_44 = F_29 ( & V_57 ) ;
if ( V_44 != 0 ) {
F_30 ( V_58 L_1 ,
V_44 ) ;
}
#endif
#if F_31 ( V_59 )
V_44 = F_32 ( & V_60 ) ;
if ( V_44 != 0 ) {
F_30 ( V_58 L_2 ,
V_44 ) ;
}
#endif
return V_44 ;
}
static void T_3 F_33 ( void )
{
#if F_28 ( V_56 )
F_34 ( & V_57 ) ;
#endif
#if F_31 ( V_59 )
F_35 ( & V_60 ) ;
#endif
}
