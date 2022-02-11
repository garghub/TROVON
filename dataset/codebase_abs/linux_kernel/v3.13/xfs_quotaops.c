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
struct V_13 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
return - F_7 ( V_11 , V_9 ) ;
}
STATIC int
F_8 (
struct V_6 * V_7 ,
unsigned int V_14 ,
int V_15 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
unsigned int V_16 = 0 ;
if ( V_7 -> V_17 & V_18 )
return - V_19 ;
if ( V_15 != V_20 && ! F_4 ( V_11 ) )
return - V_12 ;
if ( V_14 & V_21 )
V_16 |= V_22 ;
if ( V_14 & V_23 )
V_16 |= V_24 ;
if ( V_14 & V_25 )
V_16 |= V_26 ;
if ( V_14 & V_27 )
V_16 |= V_28 ;
if ( V_14 & V_29 )
V_16 |= V_30 ;
if ( V_14 & V_31 )
V_16 |= V_32 ;
switch ( V_15 ) {
case V_33 :
return - F_9 ( V_11 , V_16 ) ;
case V_34 :
if ( ! F_10 ( V_11 ) )
return - V_35 ;
return - F_11 ( V_11 , V_16 ) ;
case V_20 :
if ( F_10 ( V_11 ) )
return - V_35 ;
return - F_12 ( V_11 , V_16 ) ;
}
return - V_35 ;
}
STATIC int
F_13 (
struct V_6 * V_7 ,
struct V_36 V_37 ,
struct V_38 * V_39 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
if ( ! F_10 ( V_11 ) )
return - V_40 ;
return - F_14 ( V_11 , F_15 ( & V_41 , V_37 ) ,
F_1 ( V_37 . type ) , V_39 ) ;
}
STATIC int
F_16 (
struct V_6 * V_7 ,
struct V_36 V_37 ,
struct V_38 * V_39 )
{
struct V_10 * V_11 = F_3 ( V_7 ) ;
if ( V_7 -> V_17 & V_18 )
return - V_19 ;
if ( ! F_4 ( V_11 ) )
return - V_12 ;
if ( ! F_10 ( V_11 ) )
return - V_40 ;
return - F_17 ( V_11 , F_15 ( & V_41 , V_37 ) ,
F_1 ( V_37 . type ) , V_39 ) ;
}
