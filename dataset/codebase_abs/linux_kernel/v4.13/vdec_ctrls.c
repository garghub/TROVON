static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 . V_8 ;
switch ( V_2 -> V_9 ) {
case V_10 :
V_6 -> V_11 = V_2 -> V_12 ;
break;
case V_13 :
case V_14 :
case V_15 :
V_6 -> V_16 = V_2 -> V_12 ;
break;
case V_17 :
case V_18 :
V_6 -> V_19 = V_2 -> V_12 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_7 . V_8 ;
union V_21 V_22 ;
T_1 V_23 = V_24 ;
int V_25 ;
switch ( V_2 -> V_9 ) {
case V_13 :
case V_14 :
case V_15 :
V_25 = F_4 ( V_4 , V_23 , & V_22 ) ;
if ( ! V_25 )
V_6 -> V_16 = V_22 . V_26 . V_16 ;
V_2 -> V_12 = V_6 -> V_16 ;
break;
case V_17 :
case V_18 :
V_25 = F_4 ( V_4 , V_23 , & V_22 ) ;
if ( ! V_25 )
V_6 -> V_19 = V_22 . V_26 . V_19 ;
V_2 -> V_12 = V_6 -> V_19 ;
break;
case V_10 :
V_2 -> V_12 = V_6 -> V_11 ;
break;
case V_27 :
V_2 -> V_12 = V_4 -> V_28 ;
break;
default:
return - V_20 ;
} ;
return 0 ;
}
int F_5 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_25 ;
V_25 = F_6 ( & V_4 -> V_29 , 7 ) ;
if ( V_25 )
return V_25 ;
V_2 = F_7 ( & V_4 -> V_29 , & V_30 ,
V_14 ,
V_31 ,
~ ( ( 1 << V_32 ) |
( 1 << V_33 ) ) ,
V_32 ) ;
if ( V_2 )
V_2 -> V_34 |= V_35 ;
V_2 = F_7 ( & V_4 -> V_29 , & V_30 ,
V_18 ,
V_36 ,
0 , V_37 ) ;
if ( V_2 )
V_2 -> V_34 |= V_35 ;
V_2 = F_7 ( & V_4 -> V_29 , & V_30 ,
V_13 ,
V_38 ,
~ ( ( 1 << V_39 ) |
( 1 << V_40 ) |
( 1 << V_41 ) |
( 1 << V_42 ) |
( 1 << V_43 ) |
( 1 << V_38 ) ) ,
V_39 ) ;
if ( V_2 )
V_2 -> V_34 |= V_35 ;
V_2 = F_7 ( & V_4 -> V_29 , & V_30 ,
V_17 ,
V_44 ,
0 , V_45 ) ;
if ( V_2 )
V_2 -> V_34 |= V_35 ;
V_2 = F_8 ( & V_4 -> V_29 , & V_30 ,
V_15 , 0 , 3 , 1 , 0 ) ;
if ( V_2 )
V_2 -> V_34 |= V_35 ;
F_8 ( & V_4 -> V_29 , & V_30 ,
V_10 , 0 , 1 , 1 , 0 ) ;
V_2 = F_8 ( & V_4 -> V_29 , & V_30 ,
V_27 , 1 , 32 , 1 , 1 ) ;
if ( V_2 )
V_2 -> V_34 |= V_35 ;
V_25 = V_4 -> V_29 . error ;
if ( V_25 ) {
F_9 ( & V_4 -> V_29 ) ;
return V_25 ;
}
return 0 ;
}
void F_10 ( struct V_3 * V_4 )
{
F_9 ( & V_4 -> V_29 ) ;
}
