static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = F_2 ( V_4 , & V_2 -> V_6 , 2 ) ;
if ( V_5 )
return V_5 ;
return ( V_2 -> V_6 [ 0 ] << 2 & 0xff ) | ( V_2 -> V_6 [ 1 ] >> 6 ) ;
}
static int F_3 ( struct V_1 * V_2 , int V_7 ,
bool V_8 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 V_10 = {
. V_11 = V_2 -> V_11 ,
. V_6 = V_2 -> V_6 ,
. V_12 = 2 ,
} ;
int V_5 ;
if ( ! V_2 -> V_13 )
return F_1 ( V_2 ) ;
V_2 -> V_11 [ 0 ] = 1 << ( V_2 -> V_13 + 1 ) ;
V_2 -> V_11 [ 0 ] |= V_8 ? 0 : ( 1 << V_2 -> V_13 ) ;
V_2 -> V_11 [ 0 ] |= ( V_7 % 2 ) << ( V_2 -> V_13 - 1 ) ;
if ( V_2 -> V_13 > 1 )
V_2 -> V_11 [ 0 ] |= V_7 / 2 ;
V_2 -> V_11 [ 0 ] <<= 1 ;
V_5 = F_4 ( V_4 , & V_10 , 1 ) ;
if ( V_5 )
return V_5 ;
return V_2 -> V_6 [ 1 ] ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_16 const * V_7 , int * V_17 ,
int * V_18 , long V_19 )
{
struct V_1 * V_2 = F_6 ( V_15 ) ;
switch ( V_19 ) {
case V_20 :
F_7 ( & V_2 -> V_21 ) ;
* V_17 = F_3 ( V_2 , V_7 -> V_7 ,
V_7 -> V_8 ) ;
F_8 ( & V_2 -> V_21 ) ;
if ( * V_17 < 0 )
return * V_17 ;
return V_22 ;
case V_23 :
* V_17 = F_9 ( V_2 -> V_24 ) ;
if ( * V_17 < 0 )
return * V_17 ;
* V_17 /= 1000 ;
* V_18 = 8 ;
return V_25 ;
}
return - V_26 ;
}
static T_1 F_10 ( int V_27 , void * V_28 )
{
struct V_29 * V_30 = V_28 ;
struct V_14 * V_31 = V_30 -> V_31 ;
struct V_1 * V_2 = F_6 ( V_31 ) ;
T_2 V_32 [ 24 ] = { } ;
int V_33 ;
int V_34 = 0 ;
F_7 ( & V_2 -> V_21 ) ;
F_11 (scan_index, indio_dev->active_scan_mask,
indio_dev->masklength) {
const struct V_16 * V_35 =
& V_31 -> V_36 [ V_33 ] ;
int V_5 = F_3 ( V_2 , V_35 -> V_7 ,
V_35 -> V_8 ) ;
if ( V_5 < 0 ) {
F_12 ( & V_2 -> V_4 -> V_37 ,
L_1 ) ;
goto V_38;
}
V_32 [ V_34 ] = V_5 ;
V_34 ++ ;
}
F_13 ( V_31 , V_32 ,
F_14 ( V_31 ) ) ;
V_38:
F_8 ( & V_2 -> V_21 ) ;
F_15 ( V_31 -> V_39 ) ;
return V_40 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_14 * V_31 ;
struct V_1 * V_2 ;
int V_5 ;
V_31 = F_17 ( & V_4 -> V_37 , sizeof( * V_2 ) ) ;
if ( ! V_31 )
return - V_41 ;
V_2 = F_6 ( V_31 ) ;
V_2 -> V_4 = V_4 ;
F_18 ( & V_2 -> V_21 ) ;
V_31 -> V_42 = F_19 ( V_4 ) -> V_42 ;
V_31 -> V_37 . V_43 = & V_4 -> V_37 ;
V_31 -> V_37 . V_44 = V_4 -> V_37 . V_44 ;
V_31 -> V_45 = & V_46 ;
V_31 -> V_47 = V_48 ;
switch ( F_19 ( V_4 ) -> V_49 ) {
case V_50 :
V_2 -> V_13 = 0 ;
V_31 -> V_36 = V_51 ;
V_31 -> V_52 = F_20 ( V_51 ) ;
break;
case V_1 :
V_2 -> V_13 = 1 ;
V_31 -> V_36 = V_53 ;
V_31 -> V_52 = F_20 ( V_53 ) ;
break;
case V_54 :
V_2 -> V_13 = 2 ;
V_31 -> V_36 = V_55 ;
V_31 -> V_52 = F_20 ( V_55 ) ;
break;
case V_56 :
V_2 -> V_13 = 3 ;
V_31 -> V_36 = V_57 ;
V_31 -> V_52 = F_20 ( V_57 ) ;
break;
default:
return - V_26 ;
}
V_2 -> V_24 = F_21 ( & V_4 -> V_37 , L_2 ) ;
if ( F_22 ( V_2 -> V_24 ) )
return F_23 ( V_2 -> V_24 ) ;
V_5 = F_24 ( V_2 -> V_24 ) ;
if ( V_5 )
return V_5 ;
F_25 ( V_4 , V_31 ) ;
V_5 = F_26 ( V_31 , NULL ,
F_10 , NULL ) ;
if ( V_5 )
goto V_58;
V_5 = F_27 ( V_31 ) ;
if ( V_5 )
goto V_59;
return 0 ;
V_59:
F_28 ( V_31 ) ;
V_58:
F_29 ( V_2 -> V_24 ) ;
return V_5 ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_14 * V_31 = F_31 ( V_4 ) ;
struct V_1 * V_2 = F_6 ( V_31 ) ;
F_32 ( V_31 ) ;
F_28 ( V_31 ) ;
F_29 ( V_2 -> V_24 ) ;
return 0 ;
}
