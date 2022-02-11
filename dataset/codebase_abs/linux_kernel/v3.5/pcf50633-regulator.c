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
int V_5 , int V_6 ,
unsigned * V_7 )
{
struct V_8 * V_9 ;
int V_10 , V_1 ;
T_1 V_11 , V_12 ;
V_9 = F_8 ( V_4 ) ;
V_10 = F_9 ( V_4 ) ;
if ( V_10 >= V_13 )
return - V_14 ;
V_1 = V_5 / 1000 ;
V_12 = V_4 -> V_15 -> V_16 ;
switch ( V_10 ) {
case V_17 :
V_11 = F_1 ( V_1 ) ;
break;
case V_18 :
V_11 = F_2 ( V_1 ) ;
break;
case V_19 :
V_11 = F_2 ( V_1 ) ;
break;
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_11 = F_3 ( V_1 ) ;
break;
default:
return - V_14 ;
}
* V_7 = V_11 ;
return F_10 ( V_9 , V_12 , V_11 ) ;
}
static int F_11 ( struct V_3 * V_4 ,
unsigned int V_28 )
{
int V_10 = F_9 ( V_4 ) ;
int V_1 ;
switch ( V_10 ) {
case V_17 :
V_1 = F_4 ( V_28 ) ;
break;
case V_18 :
V_1 = F_5 ( V_28 ) ;
break;
case V_19 :
V_1 = F_5 ( V_28 ) ;
break;
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_1 = F_6 ( V_28 ) ;
break;
default:
return - V_14 ;
}
return V_1 * 1000 ;
}
static int T_2 F_12 ( struct V_29 * V_30 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
struct V_31 V_32 = { } ;
V_9 = F_13 ( V_30 -> V_33 . V_34 ) ;
V_32 . V_33 = & V_30 -> V_33 ;
V_32 . V_35 = V_30 -> V_33 . V_36 ;
V_32 . V_37 = V_9 ;
V_32 . V_38 = V_9 -> V_38 ;
V_4 = F_14 ( & V_39 [ V_30 -> V_40 ] , & V_32 ) ;
if ( F_15 ( V_4 ) )
return F_16 ( V_4 ) ;
F_17 ( V_30 , V_4 ) ;
if ( V_9 -> V_41 -> V_42 )
V_9 -> V_41 -> V_42 ( V_9 , V_30 -> V_40 ) ;
return 0 ;
}
static int T_3 F_18 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = F_19 ( V_30 ) ;
F_17 ( V_30 , NULL ) ;
F_20 ( V_4 ) ;
return 0 ;
}
static int T_4 F_21 ( void )
{
return F_22 ( & V_43 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_43 ) ;
}
