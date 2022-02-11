static int F_1 ( int V_1 ,
const unsigned int V_2 , bool V_3 )
{
int V_4 = 1 ;
switch ( V_1 ) {
case V_5 :
case V_6 :
return 0 ;
case V_7 :
case V_8 :
return ( ( V_4 << 4 ) | ( ! V_3 << 3 ) |
( V_2 << 2 ) ) ;
case V_9 :
case V_10 :
case V_11 :
case V_12 :
return ( ( V_4 << 6 ) | ( ! V_3 << 5 ) |
( V_2 << 2 ) ) ;
default:
return - V_13 ;
}
}
static int F_2 ( struct V_14 * V_15 , T_1 V_2 ,
bool V_3 , int V_1 )
{
int V_16 ;
V_15 -> V_17 [ 0 ] = 0 ;
V_15 -> V_17 [ 1 ] = 0 ;
V_15 -> V_18 = F_1 ( V_1 ,
V_2 , V_3 ) ;
if ( V_1 != V_5 && V_1 != V_6 ) {
V_16 = F_3 ( V_15 -> V_19 , & V_15 -> V_20 ) ;
if ( V_16 < 0 )
return V_16 ;
} else {
V_16 = F_4 ( V_15 -> V_19 , & V_15 -> V_17 , sizeof( V_15 -> V_17 ) ) ;
if ( V_16 < 0 )
return V_16 ;
}
switch ( V_1 ) {
case V_5 :
return ( V_15 -> V_17 [ 0 ] << 5 | V_15 -> V_17 [ 1 ] >> 3 ) ;
case V_7 :
case V_9 :
case V_11 :
return ( V_15 -> V_17 [ 0 ] << 2 | V_15 -> V_17 [ 1 ] >> 6 ) ;
case V_6 :
return ( V_15 -> V_17 [ 0 ] << 7 | V_15 -> V_17 [ 1 ] >> 1 ) ;
case V_8 :
case V_10 :
case V_12 :
return ( V_15 -> V_17 [ 0 ] << 4 | V_15 -> V_17 [ 1 ] >> 4 ) ;
default:
return - V_13 ;
}
}
static int F_5 ( struct V_21 * V_22 ,
struct V_23 const * V_2 , int * V_24 ,
int * V_25 , long V_26 )
{
struct V_14 * V_15 = F_6 ( V_22 ) ;
int V_16 = - V_13 ;
int V_1 = 0 ;
F_7 ( & V_15 -> V_27 ) ;
V_1 = F_8 ( V_15 -> V_19 ) -> V_28 ;
switch ( V_26 ) {
case V_29 :
V_16 = F_2 ( V_15 , V_2 -> V_30 ,
V_2 -> V_3 , V_1 ) ;
if ( V_16 < 0 )
goto V_31;
* V_24 = V_16 ;
V_16 = V_32 ;
break;
case V_33 :
V_16 = F_9 ( V_15 -> V_34 ) ;
if ( V_16 < 0 )
goto V_31;
* V_24 = V_16 / 1000 ;
* V_25 = V_15 -> V_35 -> V_36 ;
V_16 = V_37 ;
break;
}
V_31:
F_10 ( & V_15 -> V_27 ) ;
return V_16 ;
}
static int F_11 ( struct V_38 * V_19 )
{
struct V_21 * V_22 ;
struct V_14 * V_15 ;
const struct V_39 * V_35 ;
int V_16 ;
V_22 = F_12 ( & V_19 -> V_40 , sizeof( * V_15 ) ) ;
if ( ! V_22 )
return - V_41 ;
V_15 = F_6 ( V_22 ) ;
V_15 -> V_19 = V_19 ;
V_22 -> V_40 . V_42 = & V_19 -> V_40 ;
V_22 -> V_43 = F_8 ( V_19 ) -> V_43 ;
V_22 -> V_44 = V_45 ;
V_22 -> V_46 = & V_47 ;
V_35 = & V_48 [ F_8 ( V_19 ) -> V_28 ] ;
V_22 -> V_49 = V_35 -> V_49 ;
V_22 -> V_50 = V_35 -> V_50 ;
V_15 -> V_51 [ 0 ] . V_18 = & V_15 -> V_18 ;
V_15 -> V_51 [ 0 ] . V_52 = sizeof( V_15 -> V_18 ) ;
V_15 -> V_51 [ 1 ] . V_17 = V_15 -> V_17 ;
V_15 -> V_51 [ 1 ] . V_52 = sizeof( V_15 -> V_17 ) ;
F_13 ( & V_15 -> V_20 , V_15 -> V_51 ,
F_14 ( V_15 -> V_51 ) ) ;
V_15 -> V_34 = F_15 ( & V_19 -> V_40 , L_1 ) ;
if ( F_16 ( V_15 -> V_34 ) )
return F_17 ( V_15 -> V_34 ) ;
V_16 = F_18 ( V_15 -> V_34 ) ;
if ( V_16 < 0 )
return V_16 ;
F_19 ( & V_15 -> V_27 ) ;
V_16 = F_20 ( V_22 ) ;
if ( V_16 < 0 )
goto V_53;
return 0 ;
V_53:
F_21 ( V_15 -> V_34 ) ;
return V_16 ;
}
static int F_22 ( struct V_38 * V_19 )
{
struct V_21 * V_22 = F_23 ( V_19 ) ;
struct V_14 * V_15 = F_6 ( V_22 ) ;
F_24 ( V_22 ) ;
F_21 ( V_15 -> V_34 ) ;
return 0 ;
}
