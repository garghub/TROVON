static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
V_2 -> V_5 = V_3 ;
V_4 = F_2 ( V_2 -> V_6 , & V_2 -> V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return ( ( V_2 -> V_7 [ 0 ] & 0x3f ) << 6 ) |
( V_2 -> V_7 [ 1 ] >> 2 ) ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 const * V_11 , int * V_12 ,
int * V_13 , long V_14 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
int V_4 = - V_15 ;
F_5 ( & V_2 -> V_16 ) ;
switch ( V_14 ) {
case V_17 :
if ( V_11 -> V_18 )
V_4 = F_1 ( V_2 ,
V_19 | V_11 -> V_20 ) ;
else
V_4 = F_1 ( V_2 ,
V_19 | V_21 |
V_11 -> V_20 ) ;
if ( V_4 < 0 )
goto V_22;
* V_12 = V_4 ;
V_4 = V_23 ;
break;
case V_24 :
V_4 = F_6 ( V_2 -> V_25 ) ;
if ( V_4 < 0 )
goto V_22;
* V_12 = V_4 / 1000 ;
* V_13 = 12 ;
V_4 = V_26 ;
break;
default:
break;
}
V_22:
F_7 ( & V_2 -> V_16 ) ;
return V_4 ;
}
static int F_8 ( struct V_27 * V_6 )
{
struct V_8 * V_9 ;
struct V_1 * V_2 ;
const struct V_28 * V_29 ;
int V_4 ;
V_9 = F_9 ( sizeof( * V_2 ) ) ;
if ( ! V_9 )
return - V_30 ;
V_2 = F_4 ( V_9 ) ;
V_2 -> V_6 = V_6 ;
V_9 -> V_31 . V_32 = & V_6 -> V_31 ;
V_9 -> V_33 = F_10 ( V_6 ) -> V_33 ;
V_9 -> V_34 = V_35 ;
V_9 -> V_36 = & V_37 ;
V_29 = & V_38 [ F_10 ( V_6 ) -> V_39 ] ;
V_9 -> V_40 = V_29 -> V_40 ;
V_9 -> V_41 = V_29 -> V_41 ;
V_2 -> V_42 [ 0 ] . V_5 = & V_2 -> V_5 ;
V_2 -> V_42 [ 0 ] . V_43 = sizeof( V_2 -> V_5 ) ;
V_2 -> V_42 [ 1 ] . V_7 = V_2 -> V_7 ;
V_2 -> V_42 [ 1 ] . V_43 = sizeof( V_2 -> V_7 ) ;
F_11 ( & V_2 -> V_3 , V_2 -> V_42 ,
F_12 ( V_2 -> V_42 ) ) ;
V_2 -> V_25 = F_13 ( & V_6 -> V_31 , L_1 ) ;
if ( F_14 ( V_2 -> V_25 ) ) {
V_4 = F_15 ( V_2 -> V_25 ) ;
goto V_44;
}
V_4 = F_16 ( V_2 -> V_25 ) ;
if ( V_4 < 0 )
goto V_45;
F_17 ( & V_2 -> V_16 ) ;
V_4 = F_18 ( V_9 ) ;
if ( V_4 < 0 )
goto V_46;
return 0 ;
V_46:
F_19 ( V_2 -> V_25 ) ;
V_45:
F_20 ( V_2 -> V_25 ) ;
V_44:
F_21 ( V_9 ) ;
return V_4 ;
}
static int F_22 ( struct V_27 * V_6 )
{
struct V_8 * V_9 = F_23 ( V_6 ) ;
struct V_1 * V_2 = F_4 ( V_9 ) ;
F_24 ( V_9 ) ;
F_19 ( V_2 -> V_25 ) ;
F_20 ( V_2 -> V_25 ) ;
F_21 ( V_9 ) ;
return 0 ;
}
