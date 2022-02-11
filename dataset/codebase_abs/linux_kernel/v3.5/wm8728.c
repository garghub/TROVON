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
T_1 V_32 ;
int V_33 ;
switch ( V_31 ) {
case V_34 :
case V_35 :
case V_36 :
if ( V_5 -> V_37 . V_38 == V_39 ) {
V_32 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_32 & ~ 0x4 ) ;
for ( V_33 = 0 ; V_33 < F_8 ( V_40 ) ; V_33 ++ )
F_3 ( V_5 , V_33 ,
F_2 ( V_5 , V_33 ) ) ;
}
break;
case V_39 :
V_32 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_32 | 0x4 ) ;
break;
}
V_5 -> V_37 . V_38 = V_31 ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_39 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_36 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_41 * V_42 = F_12 ( V_5 ) ;
int V_43 ;
V_43 = F_13 ( V_5 , 7 , 9 , V_42 -> V_44 ) ;
if ( V_43 < 0 ) {
F_14 ( V_45 L_1 ,
V_43 ) ;
return V_43 ;
}
F_7 ( V_5 , V_36 ) ;
return V_43 ;
}
static int F_15 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_39 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_46 * V_47 )
{
struct V_41 * V_42 ;
int V_43 ;
V_42 = F_17 ( sizeof( struct V_41 ) , V_48 ) ;
if ( V_42 == NULL )
return - V_49 ;
V_42 -> V_44 = V_50 ;
F_18 ( V_47 , V_42 ) ;
V_43 = F_19 ( & V_47 -> V_51 ,
& V_52 , & V_53 , 1 ) ;
if ( V_43 < 0 )
F_20 ( V_42 ) ;
return V_43 ;
}
static int T_3 F_21 ( struct V_46 * V_47 )
{
F_22 ( & V_47 -> V_51 ) ;
F_20 ( F_23 ( V_47 ) ) ;
return 0 ;
}
static T_2 int F_24 ( struct V_54 * V_55 ,
const struct V_56 * V_57 )
{
struct V_41 * V_42 ;
int V_43 ;
V_42 = F_17 ( sizeof( struct V_41 ) , V_48 ) ;
if ( V_42 == NULL )
return - V_49 ;
F_25 ( V_55 , V_42 ) ;
V_42 -> V_44 = V_58 ;
V_43 = F_19 ( & V_55 -> V_51 ,
& V_52 , & V_53 , 1 ) ;
if ( V_43 < 0 )
F_20 ( V_42 ) ;
return V_43 ;
}
static T_3 int F_26 ( struct V_54 * V_59 )
{
F_22 ( & V_59 -> V_51 ) ;
F_20 ( F_27 ( V_59 ) ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
int V_43 = 0 ;
#if F_29 ( V_60 ) || F_29 ( V_61 )
V_43 = F_30 ( & V_62 ) ;
if ( V_43 != 0 ) {
F_14 ( V_45 L_2 ,
V_43 ) ;
}
#endif
#if F_29 ( V_63 )
V_43 = F_31 ( & V_64 ) ;
if ( V_43 != 0 ) {
F_14 ( V_45 L_3 ,
V_43 ) ;
}
#endif
return V_43 ;
}
static void T_5 F_32 ( void )
{
#if F_29 ( V_60 ) || F_29 ( V_61 )
F_33 ( & V_62 ) ;
#endif
#if F_29 ( V_63 )
F_34 ( & V_64 ) ;
#endif
}
