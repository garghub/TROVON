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
return - F_5 ( V_11 , V_9 ) ;
}
STATIC int
F_6 (
struct V_6 * V_7 ,
unsigned int V_13 ,
int V_14 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
unsigned int V_15 = 0 ;
if ( V_7 -> V_16 & V_17 )
return - V_18 ;
if ( V_14 != V_19 && ! F_4 ( V_11 ) )
return - V_12 ;
if ( V_13 & V_20 )
V_15 |= V_21 ;
if ( V_13 & V_22 )
V_15 |= V_23 ;
if ( V_13 & V_24 )
V_15 |= V_25 ;
if ( V_13 & V_26 )
V_15 |= V_27 ;
if ( V_13 & V_28 )
V_15 |= V_29 ;
if ( V_13 & V_30 )
V_15 |= V_31 ;
switch ( V_14 ) {
case V_32 :
return - F_7 ( V_11 , V_15 ) ;
case V_33 :
if ( ! F_8 ( V_11 ) )
return - V_34 ;
return - F_9 ( V_11 , V_15 ) ;
case V_19 :
if ( F_8 ( V_11 ) )
return - V_34 ;
return - F_10 ( V_11 , V_15 ) ;
}
return - V_34 ;
}
STATIC int
F_11 (
struct V_6 * V_7 ,
struct V_35 V_36 ,
struct V_37 * V_38 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
if ( ! F_8 ( V_11 ) )
return - V_39 ;
return - F_12 ( V_11 , F_13 ( & V_40 , V_36 ) ,
F_1 ( V_36 . type ) , V_38 ) ;
}
STATIC int
F_14 (
struct V_6 * V_7 ,
struct V_35 V_36 ,
struct V_37 * V_38 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( V_7 -> V_16 & V_17 )
return - V_18 ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
if ( ! F_8 ( V_11 ) )
return - V_39 ;
return - F_15 ( V_11 , F_13 ( & V_40 , V_36 ) ,
F_1 ( V_36 . type ) , V_38 ) ;
}
