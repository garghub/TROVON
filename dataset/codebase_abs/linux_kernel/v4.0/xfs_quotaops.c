STATIC int
F_1 ( int type )
{
switch ( type ) {
case V_1 :
return V_2 ;
case V_3 :
return V_4 ;
default:
return V_5 ;
}
}
STATIC int
F_2 (
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
return F_5 ( V_11 , V_9 ) ;
}
STATIC int
F_6 (
struct V_6 * V_7 ,
struct V_13 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
return F_7 ( V_11 , V_9 ) ;
}
static unsigned int
F_8 ( unsigned int V_14 )
{
unsigned int V_15 = 0 ;
if ( V_14 & V_16 )
V_15 |= V_17 ;
if ( V_14 & V_18 )
V_15 |= V_19 ;
if ( V_14 & V_20 )
V_15 |= V_21 ;
if ( V_14 & V_22 )
V_15 |= V_23 ;
if ( V_14 & V_24 )
V_15 |= V_25 ;
if ( V_14 & V_26 )
V_15 |= V_27 ;
return V_15 ;
}
STATIC int
F_9 (
struct V_6 * V_7 ,
unsigned int V_14 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( V_7 -> V_28 & V_29 )
return - V_30 ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
return F_10 ( V_11 , F_8 ( V_14 ) ) ;
}
STATIC int
F_11 (
struct V_6 * V_7 ,
unsigned int V_14 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( V_7 -> V_28 & V_29 )
return - V_30 ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
if ( ! F_12 ( V_11 ) )
return - V_31 ;
return F_13 ( V_11 , F_8 ( V_14 ) ) ;
}
STATIC int
F_14 (
struct V_6 * V_7 ,
unsigned int V_14 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
unsigned int V_15 = 0 ;
if ( V_7 -> V_28 & V_29 )
return - V_30 ;
if ( F_12 ( V_11 ) )
return - V_31 ;
if ( V_14 & V_32 )
V_15 |= V_2 ;
if ( V_14 & V_33 )
V_15 |= V_4 ;
if ( V_14 & V_34 )
V_15 |= V_5 ;
return F_15 ( V_11 , V_15 ) ;
}
STATIC int
F_16 (
struct V_6 * V_7 ,
struct V_35 V_36 ,
struct V_37 * V_38 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
if ( ! F_12 ( V_11 ) )
return - V_39 ;
return F_17 ( V_11 , F_18 ( & V_40 , V_36 ) ,
F_1 ( V_36 . type ) , V_38 ) ;
}
STATIC int
F_19 (
struct V_6 * V_7 ,
struct V_35 V_36 ,
struct V_37 * V_38 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( V_7 -> V_28 & V_29 )
return - V_30 ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
if ( ! F_12 ( V_11 ) )
return - V_39 ;
return F_20 ( V_11 , F_18 ( & V_40 , V_36 ) ,
F_1 ( V_36 . type ) , V_38 ) ;
}
