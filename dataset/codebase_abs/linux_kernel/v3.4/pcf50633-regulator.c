static T_1 F_1 ( unsigned int V_1 )
{
if ( V_1 < 1800 )
return 0 ;
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
V_12 = V_15 [ V_10 ] ;
switch ( V_10 ) {
case V_16 :
V_11 = F_1 ( V_1 ) ;
break;
case V_17 :
V_11 = F_2 ( V_1 ) ;
break;
case V_18 :
V_11 = F_2 ( V_1 ) ;
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_11 = F_3 ( V_1 ) ;
break;
default:
return - V_14 ;
}
* V_7 = V_11 ;
return F_10 ( V_9 , V_12 , V_11 ) ;
}
static int F_11 ( enum V_27 V_28 ,
T_1 V_2 )
{
int V_1 ;
switch ( V_28 ) {
case V_16 :
V_1 = F_4 ( V_2 ) ;
break;
case V_17 :
V_1 = F_5 ( V_2 ) ;
break;
case V_18 :
V_1 = F_5 ( V_2 ) ;
break;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
V_1 = F_6 ( V_2 ) ;
break;
default:
return - V_14 ;
}
return V_1 * 1000 ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_8 * V_9 ;
int V_10 ;
T_1 V_11 , V_12 ;
V_9 = F_8 ( V_4 ) ;
V_10 = F_9 ( V_4 ) ;
if ( V_10 >= V_13 )
return - V_14 ;
V_12 = V_15 [ V_10 ] ;
V_11 = F_13 ( V_9 , V_12 ) ;
return F_11 ( V_10 , V_11 ) ;
}
static int F_14 ( struct V_3 * V_4 ,
unsigned int V_29 )
{
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_8 ( V_4 ) ;
V_10 = F_9 ( V_4 ) ;
switch ( V_10 ) {
case V_16 :
V_29 += 0x2f ;
break;
default:
break;
}
return F_11 ( V_10 , V_29 ) ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_8 ( V_4 ) ;
int V_10 ;
T_1 V_12 ;
V_10 = F_9 ( V_4 ) ;
if ( V_10 >= V_13 )
return - V_14 ;
V_12 = V_15 [ V_10 ] + 1 ;
return F_16 ( V_9 , V_12 , V_30 ,
V_30 ) ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_8 ( V_4 ) ;
int V_10 ;
T_1 V_12 ;
V_10 = F_9 ( V_4 ) ;
if ( V_10 >= V_13 )
return - V_14 ;
V_12 = V_15 [ V_10 ] + 1 ;
return F_16 ( V_9 , V_12 ,
V_30 , 0 ) ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_8 * V_9 = F_8 ( V_4 ) ;
int V_10 = F_9 ( V_4 ) ;
T_1 V_12 ;
V_10 = F_9 ( V_4 ) ;
if ( V_10 >= V_13 )
return - V_14 ;
V_12 = V_15 [ V_10 ] + 1 ;
return F_13 ( V_9 , V_12 ) & V_30 ;
}
static int T_2 F_19 ( struct V_31 * V_32 )
{
struct V_3 * V_4 ;
struct V_8 * V_9 ;
V_9 = F_20 ( V_32 -> V_33 . V_34 ) ;
V_4 = F_21 ( & V_35 [ V_32 -> V_28 ] , & V_32 -> V_33 ,
V_32 -> V_33 . V_36 , V_9 , NULL ) ;
if ( F_22 ( V_4 ) )
return F_23 ( V_4 ) ;
F_24 ( V_32 , V_4 ) ;
if ( V_9 -> V_37 -> V_38 )
V_9 -> V_37 -> V_38 ( V_9 , V_32 -> V_28 ) ;
return 0 ;
}
static int T_3 F_25 ( struct V_31 * V_32 )
{
struct V_3 * V_4 = F_26 ( V_32 ) ;
F_24 ( V_32 , NULL ) ;
F_27 ( V_4 ) ;
return 0 ;
}
static int T_4 F_28 ( void )
{
return F_29 ( & V_39 ) ;
}
static void T_5 F_30 ( void )
{
F_31 ( & V_39 ) ;
}
