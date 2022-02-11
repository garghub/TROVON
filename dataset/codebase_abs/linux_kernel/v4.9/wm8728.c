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
if ( F_9 ( V_5 ) == V_35 ) {
V_31 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_31 & ~ 0x4 ) ;
F_10 ( V_30 -> V_36 ) ;
}
break;
case V_35 :
V_31 = F_2 ( V_5 , V_7 ) ;
F_3 ( V_5 , V_7 , V_31 | 0x4 ) ;
break;
}
return 0 ;
}
static int F_11 ( struct V_37 * V_38 )
{
struct V_29 * V_30 ;
int V_39 ;
V_30 = F_12 ( & V_38 -> V_40 , sizeof( struct V_29 ) ,
V_41 ) ;
if ( V_30 == NULL )
return - V_42 ;
V_30 -> V_36 = F_13 ( V_38 , & V_43 ) ;
if ( F_14 ( V_30 -> V_36 ) )
return F_15 ( V_30 -> V_36 ) ;
F_16 ( V_38 , V_30 ) ;
V_39 = F_17 ( & V_38 -> V_40 ,
& V_44 , & V_45 , 1 ) ;
return V_39 ;
}
static int F_18 ( struct V_37 * V_38 )
{
F_19 ( & V_38 -> V_40 ) ;
return 0 ;
}
static int F_20 ( struct V_46 * V_47 ,
const struct V_48 * V_49 )
{
struct V_29 * V_30 ;
int V_39 ;
V_30 = F_12 ( & V_47 -> V_40 , sizeof( struct V_29 ) ,
V_41 ) ;
if ( V_30 == NULL )
return - V_42 ;
V_30 -> V_36 = F_21 ( V_47 , & V_43 ) ;
if ( F_14 ( V_30 -> V_36 ) )
return F_15 ( V_30 -> V_36 ) ;
F_22 ( V_47 , V_30 ) ;
V_39 = F_17 ( & V_47 -> V_40 ,
& V_44 , & V_45 , 1 ) ;
return V_39 ;
}
static int F_23 ( struct V_46 * V_50 )
{
F_19 ( & V_50 -> V_40 ) ;
return 0 ;
}
static int T_2 F_24 ( void )
{
int V_39 = 0 ;
#if F_25 ( V_51 )
V_39 = F_26 ( & V_52 ) ;
if ( V_39 != 0 ) {
F_27 ( V_53 L_1 ,
V_39 ) ;
}
#endif
#if F_28 ( V_54 )
V_39 = F_29 ( & V_55 ) ;
if ( V_39 != 0 ) {
F_27 ( V_53 L_2 ,
V_39 ) ;
}
#endif
return V_39 ;
}
static void T_3 F_30 ( void )
{
#if F_25 ( V_51 )
F_31 ( & V_52 ) ;
#endif
#if F_28 ( V_54 )
F_32 ( & V_55 ) ;
#endif
}
