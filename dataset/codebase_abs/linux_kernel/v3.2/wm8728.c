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
static int F_9 ( struct V_4 * V_5 , T_2 V_44 )
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
struct V_45 * V_46 = F_12 ( V_5 ) ;
int V_47 ;
V_47 = F_13 ( V_5 , 7 , 9 , V_46 -> V_48 ) ;
if ( V_47 < 0 ) {
F_14 ( V_49 L_1 ,
V_47 ) ;
return V_47 ;
}
F_7 ( V_5 , V_39 ) ;
F_15 ( V_5 , V_50 ,
F_8 ( V_50 ) ) ;
return V_47 ;
}
static int F_16 ( struct V_4 * V_5 )
{
F_7 ( V_5 , V_42 ) ;
return 0 ;
}
static int T_3 F_17 ( struct V_51 * V_52 )
{
struct V_45 * V_46 ;
int V_47 ;
V_46 = F_18 ( sizeof( struct V_45 ) , V_53 ) ;
if ( V_46 == NULL )
return - V_54 ;
V_46 -> V_48 = V_55 ;
F_19 ( V_52 , V_46 ) ;
V_47 = F_20 ( & V_52 -> V_56 ,
& V_57 , & V_58 , 1 ) ;
if ( V_47 < 0 )
F_21 ( V_46 ) ;
return V_47 ;
}
static int T_4 F_22 ( struct V_51 * V_52 )
{
F_23 ( & V_52 -> V_56 ) ;
F_21 ( F_24 ( V_52 ) ) ;
return 0 ;
}
static T_3 int F_25 ( struct V_59 * V_60 ,
const struct V_61 * V_62 )
{
struct V_45 * V_46 ;
int V_47 ;
V_46 = F_18 ( sizeof( struct V_45 ) , V_53 ) ;
if ( V_46 == NULL )
return - V_54 ;
F_26 ( V_60 , V_46 ) ;
V_46 -> V_48 = V_63 ;
V_47 = F_20 ( & V_60 -> V_56 ,
& V_57 , & V_58 , 1 ) ;
if ( V_47 < 0 )
F_21 ( V_46 ) ;
return V_47 ;
}
static T_4 int F_27 ( struct V_59 * V_64 )
{
F_23 ( & V_64 -> V_56 ) ;
F_21 ( F_28 ( V_64 ) ) ;
return 0 ;
}
static int T_5 F_29 ( void )
{
int V_47 = 0 ;
#if F_30 ( V_65 ) || F_30 ( V_66 )
V_47 = F_31 ( & V_67 ) ;
if ( V_47 != 0 ) {
F_14 ( V_49 L_2 ,
V_47 ) ;
}
#endif
#if F_30 ( V_68 )
V_47 = F_32 ( & V_69 ) ;
if ( V_47 != 0 ) {
F_14 ( V_49 L_3 ,
V_47 ) ;
}
#endif
return V_47 ;
}
static void T_6 F_33 ( void )
{
#if F_30 ( V_65 ) || F_30 ( V_66 )
F_34 ( & V_67 ) ;
#endif
#if F_30 ( V_68 )
F_35 ( & V_69 ) ;
#endif
}
