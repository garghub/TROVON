static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_4 = F_2 ( V_2 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_3 ;
}
static int F_3 ( struct V_5 * V_6 )
{
return ( F_1 ( V_6 -> V_7 ) > 0 ) ? 1 : 0 ;
}
static int F_4 ( struct V_5 * V_6 )
{
return F_1 ( V_6 -> V_8 ) ;
}
static int F_5 ( struct V_5 * V_6 )
{
return F_1 ( V_6 -> V_7 ) * 1000 ;
}
static int F_6 ( struct V_5 * V_6 )
{
return F_1 ( V_6 -> V_9 ) * 10 ;
}
static int F_7 ( struct V_5 * V_10 ,
int V_11 )
{
struct V_12 * V_13 ;
int V_14 , V_15 = 0 ;
if ( F_3 ( V_10 ) )
V_13 = V_10 -> V_16 -> V_17 ;
else
V_13 = V_10 -> V_16 -> V_18 ;
if ( V_11 > V_13 [ 0 ] . V_19 ) {
V_15 = V_13 [ 0 ] . V_20 ;
} else {
for ( V_14 = 0 ; V_13 [ V_14 + 1 ] . V_19 >= 0 ; V_14 ++ ) {
if ( V_11 <= V_13 [ V_14 ] . V_19 &&
V_11 >= V_13 [ V_14 + 1 ] . V_19 ) {
V_15 = V_13 [ V_14 ] . V_20 -
( ( V_13 [ V_14 ] . V_19 - V_11 ) *
( V_13 [ V_14 ] . V_20 -
V_13 [ V_14 + 1 ] . V_20 ) ) /
( V_13 [ V_14 ] . V_19 -
V_13 [ V_14 + 1 ] . V_19 ) ;
break;
}
}
}
return V_15 ;
}
static int F_8 ( struct V_21 * V_22 ,
enum V_23 V_24 ,
union V_25 * V_3 )
{
struct V_5 * V_10 = F_9 ( V_22 ) ;
switch ( V_24 ) {
case V_26 :
if ( F_7 ( V_10 ,
F_4 ( V_10 ) ) > 95 )
V_3 -> V_27 = V_28 ;
else {
if ( F_3 ( V_10 ) )
V_3 -> V_27 = V_29 ;
else
V_3 -> V_27 = V_30 ;
}
break;
case V_31 :
V_3 -> V_27 = F_4 ( V_10 ) * 1000 ;
break;
case V_32 :
V_3 -> V_27 = V_33 ;
break;
case V_34 :
V_3 -> V_27 = F_5 ( V_10 ) ;
break;
case V_35 :
V_3 -> V_27 = 1 ;
break;
case V_36 : {
int V_37 = F_7 ( V_10 ,
F_4 ( V_10 ) ) ;
V_3 -> V_27 = ( V_37 * V_10 -> V_16 -> V_38 ) / 100 ;
break;
}
case V_39 :
V_3 -> V_27 = F_7 ( V_10 ,
F_4 ( V_10 ) ) ;
break;
case V_40 :
V_3 -> V_27 = V_10 -> V_16 -> V_38 ;
break;
case V_41 :
V_3 -> V_27 = F_6 ( V_10 ) ;
break;
case V_42 : {
int V_37 = F_7 ( V_10 ,
F_4 ( V_10 ) ) ;
int V_43 = ( V_37 * ( V_10 -> V_16 -> V_38 / 1000 ) ) / 100 ;
V_3 -> V_27 = ( 3600l * V_43 ) / 400 ;
break;
}
default:
return - V_44 ;
}
return 0 ;
}
static void F_10 ( struct V_21 * V_22 )
{
F_11 ( V_22 ) ;
}
static int F_12 ( const void * V_45 , const void * V_46 )
{
return ( (struct V_12 * ) V_46 ) -> V_19 -
( (struct V_12 * ) V_45 ) -> V_19 ;
}
static int F_13 ( struct V_47 * V_48 )
{
struct V_5 * V_49 ;
struct V_50 * V_16 = V_48 -> V_51 . V_52 ;
struct V_53 V_54 = {} ;
int V_55 = 0 ;
V_49 = F_14 ( & V_48 -> V_51 , sizeof( * V_49 ) ,
V_56 ) ;
if ( ! V_49 )
return - V_57 ;
V_49 -> V_9 = F_15 ( & V_48 -> V_51 , L_1 ) ;
if ( F_16 ( V_49 -> V_9 ) ) {
V_55 = F_17 ( V_49 -> V_9 ) ;
goto V_4;
}
V_49 -> V_7 = F_15 ( & V_48 -> V_51 , L_2 ) ;
if ( F_16 ( V_49 -> V_7 ) ) {
V_55 = F_17 ( V_49 -> V_7 ) ;
goto V_58;
}
V_49 -> V_8 = F_15 ( & V_48 -> V_51 , L_3 ) ;
if ( F_16 ( V_49 -> V_8 ) ) {
V_55 = F_17 ( V_49 -> V_8 ) ;
goto V_59;
}
F_18 ( V_16 -> V_17 , V_16 -> V_60 ,
sizeof( struct V_12 ) ,
F_12 , NULL ) ;
F_18 ( V_16 -> V_18 , V_16 -> V_61 ,
sizeof( struct V_12 ) ,
F_12 , NULL ) ;
V_49 -> V_16 = V_16 ;
F_19 ( V_48 , V_49 ) ;
V_54 . V_62 = V_49 ;
V_49 -> V_22 = F_20 ( & V_48 -> V_51 ,
& V_63 ,
& V_54 ) ;
if ( F_16 ( V_49 -> V_22 ) ) {
V_55 = F_17 ( V_49 -> V_22 ) ;
goto V_64;
}
return 0 ;
V_64:
F_21 ( V_49 -> V_8 ) ;
V_59:
F_21 ( V_49 -> V_7 ) ;
V_58:
F_21 ( V_49 -> V_9 ) ;
V_4:
return V_55 ;
}
static int F_22 ( struct V_47 * V_48 )
{
struct V_5 * V_10 = F_23 ( V_48 ) ;
F_24 ( V_10 -> V_22 ) ;
F_21 ( V_10 -> V_8 ) ;
F_21 ( V_10 -> V_7 ) ;
F_21 ( V_10 -> V_9 ) ;
return 0 ;
}
