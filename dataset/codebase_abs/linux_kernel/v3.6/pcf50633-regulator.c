static T_1 F_1 ( unsigned int V_1 )
{
if ( V_1 < 1800 )
return 0x2f ;
if ( V_1 > 3800 )
return 0xff ;
V_1 -= 625 ;
return V_1 / 25 ;
}
static T_1 F_2 ( unsigned int V_1 )
{
if ( V_1 < 625 )
return 0 ;
else if ( V_1 > 3000 )
return 0xff ;
V_1 -= 625 ;
return V_1 / 25 ;
}
static T_1 F_3 ( unsigned int V_1 )
{
if ( V_1 < 900 )
return 0 ;
else if ( V_1 > 3600 )
return 0x1f ;
V_1 -= 900 ;
return V_1 / 100 ;
}
static unsigned int F_4 ( T_1 V_2 )
{
if ( V_2 < 0x2f )
return 0 ;
return 625 + ( V_2 * 25 ) ;
}
static unsigned int F_5 ( T_1 V_2 )
{
return 625 + ( V_2 * 25 ) ;
}
static unsigned int F_6 ( T_1 V_2 )
{
V_2 &= 0x1f ;
return 900 + ( V_2 * 100 ) ;
}
static int F_7 ( struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 ;
int V_9 , V_1 ;
T_1 V_10 ;
V_8 = F_8 ( V_4 ) ;
V_9 = F_9 ( V_4 ) ;
if ( V_9 >= V_11 )
return - V_12 ;
V_1 = V_5 / 1000 ;
switch ( V_9 ) {
case V_13 :
V_10 = F_1 ( V_1 ) ;
break;
case V_14 :
case V_15 :
V_10 = F_2 ( V_1 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_10 = F_3 ( V_1 ) ;
break;
default:
return - V_12 ;
}
return V_10 ;
}
static int F_10 ( struct V_3 * V_4 ,
unsigned int V_24 )
{
int V_9 = F_9 ( V_4 ) ;
int V_1 ;
switch ( V_9 ) {
case V_13 :
V_1 = F_4 ( V_24 ) ;
break;
case V_14 :
case V_15 :
V_1 = F_5 ( V_24 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_1 = F_6 ( V_24 ) ;
break;
default:
return - V_12 ;
}
return V_1 * 1000 ;
}
static int T_2 F_11 ( struct V_25 * V_26 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
struct V_27 V_28 = { } ;
V_8 = F_12 ( V_26 -> V_29 . V_30 ) ;
V_28 . V_29 = & V_26 -> V_29 ;
V_28 . V_31 = V_26 -> V_29 . V_32 ;
V_28 . V_33 = V_8 ;
V_28 . V_34 = V_8 -> V_34 ;
V_4 = F_13 ( & V_35 [ V_26 -> V_36 ] , & V_28 ) ;
if ( F_14 ( V_4 ) )
return F_15 ( V_4 ) ;
F_16 ( V_26 , V_4 ) ;
if ( V_8 -> V_37 -> V_38 )
V_8 -> V_37 -> V_38 ( V_8 , V_26 -> V_36 ) ;
return 0 ;
}
static int T_3 F_17 ( struct V_25 * V_26 )
{
struct V_3 * V_4 = F_18 ( V_26 ) ;
F_16 ( V_26 , NULL ) ;
F_19 ( V_4 ) ;
return 0 ;
}
static int T_4 F_20 ( void )
{
return F_21 ( & V_39 ) ;
}
static void T_5 F_22 ( void )
{
F_23 ( & V_39 ) ;
}
