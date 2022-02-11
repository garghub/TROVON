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
struct V_12 * V_13 = V_9 -> V_14 ;
struct V_4 * V_5 = V_13 -> V_5 ;
T_1 V_15 = F_2 ( V_5 , V_7 ) ;
V_15 &= ~ 0x18 ;
switch ( F_5 ( V_11 ) ) {
case V_16 :
break;
case V_17 :
V_15 |= 0x10 ;
break;
case V_18 :
V_15 |= 0x08 ;
break;
default:
return - V_19 ;
}
F_3 ( V_5 , V_7 , V_15 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_20 ,
unsigned int V_21 )
{
struct V_4 * V_5 = V_20 -> V_5 ;
T_1 V_22 = F_2 ( V_5 , V_23 ) ;
switch ( V_21 & V_24 ) {
case V_25 :
V_22 |= 1 ;
break;
default:
return - V_19 ;
}
switch ( V_21 & V_26 ) {
case V_27 :
break;
default:
return - V_19 ;
}
switch ( V_21 & V_28 ) {
case V_29 :
V_22 &= ~ 0x22 ;
break;
case V_30 :
V_22 |= 0x20 ;
V_22 &= ~ 0x02 ;
break;
case V_31 :
V_22 |= 0x02 ;
V_22 &= ~ 0x20 ;
break;
case V_32 :
V_22 |= 0x22 ;
break;
default:
return - V_19 ;
}
F_3 ( V_5 , V_23 , V_22 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 ,
enum V_33 V_34 )
{
T_1 V_35 ;
int V_36 ;
switch ( V_34 ) {
case V_37 :
case V_38 :
case V_39 :
if ( V_5 -> V_40 . V_41 == V_42 ) {
V_35 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_35 & ~ 0x4 ) ;
for ( V_36 = 0 ; V_36 < F_8 ( V_43 ) ; V_36 ++ )
F_3 ( V_5 , V_36 ,
F_2 ( V_5 , V_36 ) ) ;
}
break;
case V_42 :
V_35 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_35 | 0x4 ) ;
break;
}
V_5 -> V_40 . V_41 = V_34 ;
return 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_42 ) ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_39 ) ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_44 * V_45 = F_12 ( V_5 ) ;
int V_46 ;
V_46 = F_13 ( V_5 , 7 , 9 , V_45 -> V_47 ) ;
if ( V_46 < 0 ) {
F_14 ( V_48 L_1 ,
V_46 ) ;
return V_46 ;
}
F_7 ( V_5 , V_39 ) ;
return V_46 ;
}
static int F_15 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_42 ) ;
return 0 ;
}
static int T_2 F_16 ( struct V_49 * V_50 )
{
struct V_44 * V_45 ;
int V_46 ;
V_45 = F_17 ( sizeof( struct V_44 ) , V_51 ) ;
if ( V_45 == NULL )
return - V_52 ;
V_45 -> V_47 = V_53 ;
F_18 ( V_50 , V_45 ) ;
V_46 = F_19 ( & V_50 -> V_54 ,
& V_55 , & V_56 , 1 ) ;
if ( V_46 < 0 )
F_20 ( V_45 ) ;
return V_46 ;
}
static int T_3 F_21 ( struct V_49 * V_50 )
{
F_22 ( & V_50 -> V_54 ) ;
F_20 ( F_23 ( V_50 ) ) ;
return 0 ;
}
static T_2 int F_24 ( struct V_57 * V_58 ,
const struct V_59 * V_60 )
{
struct V_44 * V_45 ;
int V_46 ;
V_45 = F_17 ( sizeof( struct V_44 ) , V_51 ) ;
if ( V_45 == NULL )
return - V_52 ;
F_25 ( V_58 , V_45 ) ;
V_45 -> V_47 = V_61 ;
V_46 = F_19 ( & V_58 -> V_54 ,
& V_55 , & V_56 , 1 ) ;
if ( V_46 < 0 )
F_20 ( V_45 ) ;
return V_46 ;
}
static T_3 int F_26 ( struct V_57 * V_62 )
{
F_22 ( & V_62 -> V_54 ) ;
F_20 ( F_27 ( V_62 ) ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
int V_46 = 0 ;
#if F_29 ( V_63 ) || F_29 ( V_64 )
V_46 = F_30 ( & V_65 ) ;
if ( V_46 != 0 ) {
F_14 ( V_48 L_2 ,
V_46 ) ;
}
#endif
#if F_29 ( V_66 )
V_46 = F_31 ( & V_67 ) ;
if ( V_46 != 0 ) {
F_14 ( V_48 L_3 ,
V_46 ) ;
}
#endif
return V_46 ;
}
static void T_5 F_32 ( void )
{
#if F_29 ( V_63 ) || F_29 ( V_64 )
F_33 ( & V_65 ) ;
#endif
#if F_29 ( V_66 )
F_34 ( & V_67 ) ;
#endif
}
