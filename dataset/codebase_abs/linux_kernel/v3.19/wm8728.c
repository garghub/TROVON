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
case 16 :
break;
case 20 :
V_12 |= 0x10 ;
break;
case 24 :
V_12 |= 0x08 ;
break;
default:
return - V_13 ;
}
F_3 ( V_5 , V_7 , V_12 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_14 ,
unsigned int V_15 )
{
struct V_4 * V_5 = V_14 -> V_5 ;
T_1 V_16 = F_2 ( V_5 , V_17 ) ;
switch ( V_15 & V_18 ) {
case V_19 :
V_16 |= 1 ;
break;
default:
return - V_13 ;
}
switch ( V_15 & V_20 ) {
case V_21 :
break;
default:
return - V_13 ;
}
switch ( V_15 & V_22 ) {
case V_23 :
V_16 &= ~ 0x22 ;
break;
case V_24 :
V_16 |= 0x20 ;
V_16 &= ~ 0x02 ;
break;
case V_25 :
V_16 |= 0x02 ;
V_16 &= ~ 0x20 ;
break;
case V_26 :
V_16 |= 0x22 ;
break;
default:
return - V_13 ;
}
F_3 ( V_5 , V_17 , V_16 ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 ,
enum V_27 V_28 )
{
struct V_29 * V_30 = F_8 ( V_5 ) ;
T_1 V_31 ;
switch ( V_28 ) {
case V_32 :
case V_33 :
case V_34 :
if ( V_5 -> V_35 . V_36 == V_37 ) {
V_31 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_31 & ~ 0x4 ) ;
F_9 ( V_30 -> V_38 ) ;
}
break;
case V_37 :
V_31 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_31 | 0x4 ) ;
break;
}
V_5 -> V_35 . V_36 = V_28 ;
return 0 ;
}
static int F_10 ( struct V_39 * V_40 )
{
struct V_29 * V_30 ;
int V_41 ;
V_30 = F_11 ( & V_40 -> V_42 , sizeof( struct V_29 ) ,
V_43 ) ;
if ( V_30 == NULL )
return - V_44 ;
V_30 -> V_38 = F_12 ( V_40 , & V_45 ) ;
if ( F_13 ( V_30 -> V_38 ) )
return F_14 ( V_30 -> V_38 ) ;
F_15 ( V_40 , V_30 ) ;
V_41 = F_16 ( & V_40 -> V_42 ,
& V_46 , & V_47 , 1 ) ;
return V_41 ;
}
static int F_17 ( struct V_39 * V_40 )
{
F_18 ( & V_40 -> V_42 ) ;
return 0 ;
}
static int F_19 ( struct V_48 * V_49 ,
const struct V_50 * V_51 )
{
struct V_29 * V_30 ;
int V_41 ;
V_30 = F_11 ( & V_49 -> V_42 , sizeof( struct V_29 ) ,
V_43 ) ;
if ( V_30 == NULL )
return - V_44 ;
V_30 -> V_38 = F_20 ( V_49 , & V_45 ) ;
if ( F_13 ( V_30 -> V_38 ) )
return F_14 ( V_30 -> V_38 ) ;
F_21 ( V_49 , V_30 ) ;
V_41 = F_16 ( & V_49 -> V_42 ,
& V_46 , & V_47 , 1 ) ;
return V_41 ;
}
static int F_22 ( struct V_48 * V_52 )
{
F_18 ( & V_52 -> V_42 ) ;
return 0 ;
}
static int T_2 F_23 ( void )
{
int V_41 = 0 ;
#if F_24 ( V_53 )
V_41 = F_25 ( & V_54 ) ;
if ( V_41 != 0 ) {
F_26 ( V_55 L_1 ,
V_41 ) ;
}
#endif
#if F_27 ( V_56 )
V_41 = F_28 ( & V_57 ) ;
if ( V_41 != 0 ) {
F_26 ( V_55 L_2 ,
V_41 ) ;
}
#endif
return V_41 ;
}
static void T_3 F_29 ( void )
{
#if F_24 ( V_53 )
F_30 ( & V_54 ) ;
#endif
#if F_27 ( V_56 )
F_31 ( & V_57 ) ;
#endif
}
