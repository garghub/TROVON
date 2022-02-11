static int F_1 ( int V_1 ,
const unsigned int V_2 , bool V_3 )
{
int V_4 = 1 ;
switch ( V_1 ) {
case V_5 :
case V_6 :
case V_7 :
return 0 ;
case V_8 :
case V_9 :
return ( ( V_4 << 4 ) | ( ! V_3 << 3 ) |
( V_2 << 2 ) ) ;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
return ( ( V_4 << 6 ) | ( ! V_3 << 5 ) |
( V_2 << 2 ) ) ;
default:
return - V_14 ;
}
}
static int F_2 ( struct V_15 * V_16 , T_1 V_2 ,
bool V_3 , int V_1 )
{
int V_17 ;
V_16 -> V_18 [ 0 ] = 0 ;
V_16 -> V_18 [ 1 ] = 0 ;
V_16 -> V_19 = F_1 ( V_1 ,
V_2 , V_3 ) ;
if ( V_1 != V_5 && V_1 != V_6 && V_1 != V_7 ) {
V_17 = F_3 ( V_16 -> V_20 , & V_16 -> V_21 ) ;
if ( V_17 < 0 )
return V_17 ;
} else {
V_17 = F_4 ( V_16 -> V_20 , & V_16 -> V_18 , sizeof( V_16 -> V_18 ) ) ;
if ( V_17 < 0 )
return V_17 ;
}
switch ( V_1 ) {
case V_5 :
return ( V_16 -> V_18 [ 0 ] << 5 | V_16 -> V_18 [ 1 ] >> 3 ) ;
case V_8 :
case V_10 :
case V_12 :
return ( V_16 -> V_18 [ 0 ] << 2 | V_16 -> V_18 [ 1 ] >> 6 ) ;
case V_6 :
return ( V_16 -> V_18 [ 0 ] << 7 | V_16 -> V_18 [ 1 ] >> 1 ) ;
case V_9 :
case V_11 :
case V_13 :
return ( V_16 -> V_18 [ 0 ] << 4 | V_16 -> V_18 [ 1 ] >> 4 ) ;
case V_7 :
return F_5 ( ( V_16 -> V_18 [ 0 ] & 0x1f ) << 8 | V_16 -> V_18 [ 1 ] , 12 ) ;
default:
return - V_14 ;
}
}
static int F_6 ( struct V_22 * V_23 ,
struct V_24 const * V_2 , int * V_25 ,
int * V_26 , long V_27 )
{
struct V_15 * V_16 = F_7 ( V_23 ) ;
int V_17 = - V_14 ;
int V_1 = 0 ;
F_8 ( & V_16 -> V_28 ) ;
V_1 = F_9 ( V_16 -> V_20 ) -> V_29 ;
switch ( V_27 ) {
case V_30 :
V_17 = F_2 ( V_16 , V_2 -> V_31 ,
V_2 -> V_3 , V_1 ) ;
if ( V_17 < 0 )
goto V_32;
* V_25 = V_17 ;
V_17 = V_33 ;
break;
case V_34 :
V_17 = F_10 ( V_16 -> V_35 ) ;
if ( V_17 < 0 )
goto V_32;
* V_25 = V_17 / 1000 ;
* V_26 = V_16 -> V_36 -> V_37 ;
V_17 = V_38 ;
break;
}
V_32:
F_11 ( & V_16 -> V_28 ) ;
return V_17 ;
}
static int F_12 ( struct V_39 * V_20 )
{
struct V_22 * V_23 ;
struct V_15 * V_16 ;
const struct V_40 * V_36 ;
int V_17 ;
V_23 = F_13 ( & V_20 -> V_41 , sizeof( * V_16 ) ) ;
if ( ! V_23 )
return - V_42 ;
V_16 = F_7 ( V_23 ) ;
V_16 -> V_20 = V_20 ;
V_23 -> V_41 . V_43 = & V_20 -> V_41 ;
V_23 -> V_44 = F_9 ( V_20 ) -> V_44 ;
V_23 -> V_45 = V_46 ;
V_23 -> V_47 = & V_48 ;
V_36 = & V_49 [ F_9 ( V_20 ) -> V_29 ] ;
V_23 -> V_50 = V_36 -> V_50 ;
V_23 -> V_51 = V_36 -> V_51 ;
V_16 -> V_36 = V_36 ;
V_16 -> V_52 [ 0 ] . V_19 = & V_16 -> V_19 ;
V_16 -> V_52 [ 0 ] . V_53 = sizeof( V_16 -> V_19 ) ;
V_16 -> V_52 [ 1 ] . V_18 = V_16 -> V_18 ;
V_16 -> V_52 [ 1 ] . V_53 = sizeof( V_16 -> V_18 ) ;
F_14 ( & V_16 -> V_21 , V_16 -> V_52 ,
F_15 ( V_16 -> V_52 ) ) ;
V_16 -> V_35 = F_16 ( & V_20 -> V_41 , L_1 ) ;
if ( F_17 ( V_16 -> V_35 ) )
return F_18 ( V_16 -> V_35 ) ;
V_17 = F_19 ( V_16 -> V_35 ) ;
if ( V_17 < 0 )
return V_17 ;
F_20 ( & V_16 -> V_28 ) ;
V_17 = F_21 ( V_23 ) ;
if ( V_17 < 0 )
goto V_54;
return 0 ;
V_54:
F_22 ( V_16 -> V_35 ) ;
return V_17 ;
}
static int F_23 ( struct V_39 * V_20 )
{
struct V_22 * V_23 = F_24 ( V_20 ) ;
struct V_15 * V_16 = F_7 ( V_23 ) ;
F_25 ( V_23 ) ;
F_22 ( V_16 -> V_35 ) ;
return 0 ;
}
