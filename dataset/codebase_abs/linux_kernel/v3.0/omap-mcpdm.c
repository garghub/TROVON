static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
if ( ! V_4 -> V_6 )
V_5 = F_2 () ;
return V_5 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_4 -> V_6 )
F_4 () ;
}
static int F_5 ( struct V_1 * V_2 , int V_7 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = F_6 ( V_4 ) ;
int V_10 = V_2 -> V_10 ;
int V_5 = 0 ;
switch ( V_7 ) {
case V_11 :
case V_12 :
case V_13 :
if ( ! V_9 -> V_6 ++ )
F_7 ( V_10 ) ;
break;
case V_14 :
case V_15 :
case V_16 :
if ( ! -- V_9 -> V_6 )
F_8 ( V_10 ) ;
break;
default:
V_5 = - V_17 ;
}
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = F_6 ( V_4 ) ;
struct V_20 * V_21 = V_9 -> V_22 ;
int V_10 = V_2 -> V_10 ;
int V_23 , V_5 , V_24 = 0 ;
F_10 ( V_4 , V_2 ,
& V_25 [ V_10 ] ) ;
V_23 = F_11 ( V_19 ) ;
switch ( V_23 ) {
case 4 :
if ( V_10 == V_26 )
return - V_17 ;
V_24 |= 1 << 3 ;
case 3 :
if ( V_10 == V_26 )
return - V_17 ;
V_24 |= 1 << 2 ;
case 2 :
V_24 |= 1 << 1 ;
case 1 :
V_24 |= 1 << 0 ;
break;
default:
return - V_17 ;
}
if ( V_10 == V_27 ) {
V_21 [ V_10 ] . V_23 = V_24 << 3 ;
V_5 = F_12 ( & V_21 [ V_10 ] ) ;
} else {
V_21 [ V_10 ] . V_23 = V_24 << 0 ;
V_5 = F_13 ( & V_21 [ V_10 ] ) ;
}
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = F_6 ( V_4 ) ;
struct V_20 * V_21 = V_9 -> V_22 ;
int V_10 = V_2 -> V_10 ;
int V_5 ;
if ( V_2 -> V_10 == V_27 )
V_5 = F_15 ( & V_21 [ V_10 ] ) ;
else
V_5 = F_16 ( & V_21 [ V_10 ] ) ;
return V_5 ;
}
static int F_17 ( struct V_3 * V_4 )
{
F_18 ( V_4 , & V_28 ) ;
return 0 ;
}
static T_1 int F_19 ( struct V_29 * V_30 )
{
int V_31 ;
V_31 = F_20 ( V_30 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = F_21 ( & V_30 -> V_32 , & V_33 ) ;
if ( V_31 < 0 )
F_22 ( V_30 ) ;
return V_31 ;
}
static int T_2 F_23 ( struct V_29 * V_30 )
{
F_24 ( & V_30 -> V_32 ) ;
F_22 ( V_30 ) ;
return 0 ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_34 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_34 ) ;
}
