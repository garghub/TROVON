static int F_1 ( int V_1 )
{
struct V_2 V_3 ;
int V_4 ;
V_3 . V_5 = V_1 ;
V_3 . V_6 = V_7 ;
V_3 . type = V_8 ;
V_3 . V_9 = 0 ;
V_3 . V_10 = false ;
V_3 . V_11 = NULL ;
V_4 = F_2 ( & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_3 . V_12 [ F_3 ( V_1 ) - 1 ] ;
}
static int F_4 ( void )
{
return ( F_1 ( V_13 ) > 0 ) ? 1 : 0 ;
}
static int F_5 ( void )
{
return F_1 ( V_14 ) ;
}
static int F_6 ( void )
{
return F_1 ( V_13 ) * 1000 ;
}
static int F_7 ( void )
{
return F_1 ( V_15 ) * 10 ;
}
static int F_8 ( struct V_16 * V_17 ,
int V_18 )
{
struct V_19 * V_20 ;
int V_21 , V_22 = 0 ;
if ( F_4 () )
V_20 = V_17 -> V_23 -> V_24 ;
else
V_20 = V_17 -> V_23 -> V_25 ;
if ( V_18 > V_20 [ 0 ] . V_26 ) {
V_22 = V_20 [ 0 ] . V_27 ;
} else {
for ( V_21 = 0 ; V_20 [ V_21 + 1 ] . V_26 >= 0 ; V_21 ++ ) {
if ( V_18 <= V_20 [ V_21 ] . V_26 &&
V_18 >= V_20 [ V_21 + 1 ] . V_26 ) {
V_22 = V_20 [ V_21 ] . V_27 -
( ( V_20 [ V_21 ] . V_26 - V_18 ) *
( V_20 [ V_21 ] . V_27 -
V_20 [ V_21 + 1 ] . V_27 ) ) /
( V_20 [ V_21 ] . V_26 -
V_20 [ V_21 + 1 ] . V_26 ) ;
break;
}
}
}
return V_22 ;
}
static int F_9 ( struct V_28 * V_29 ,
enum V_30 V_31 ,
union V_32 * V_4 )
{
struct V_16 * V_17 = F_10 ( V_29 ,
struct V_16 , V_29 ) ;
switch ( V_31 ) {
case V_33 :
if ( F_8 ( V_17 ,
F_5 () ) > 95 )
V_4 -> V_34 = V_35 ;
else {
if ( F_4 () )
V_4 -> V_34 = V_36 ;
else
V_4 -> V_34 = V_37 ;
}
break;
case V_38 :
V_4 -> V_34 = F_5 () * 1000 ;
break;
case V_39 :
V_4 -> V_34 = V_40 ;
break;
case V_41 :
V_4 -> V_34 = F_6 () ;
break;
case V_42 :
V_4 -> V_34 = 1 ;
break;
case V_43 : {
int V_44 = F_8 ( V_17 ,
F_5 () ) ;
V_4 -> V_34 = ( V_44 * V_17 -> V_23 -> V_45 ) / 100 ;
break;
}
case V_46 :
V_4 -> V_34 = F_8 ( V_17 ,
F_5 () ) ;
break;
case V_47 :
V_4 -> V_34 = V_17 -> V_23 -> V_45 ;
break;
case V_48 :
V_4 -> V_34 = F_7 () ;
break;
case V_49 : {
int V_44 = F_8 ( V_17 ,
F_5 () ) ;
int V_50 = ( V_44 * ( V_17 -> V_23 -> V_45 / 1000 ) ) / 100 ;
V_4 -> V_34 = ( 3600l * V_50 ) / 400 ;
break;
}
default:
return - V_51 ;
}
return 0 ;
}
static void F_11 ( struct V_28 * V_29 )
{
struct V_16 * V_17 = F_10 ( V_29 ,
struct V_16 , V_29 ) ;
F_12 ( & V_17 -> V_29 ) ;
}
static int F_13 ( const void * V_52 , const void * V_53 )
{
return ( (struct V_19 * ) V_53 ) -> V_26 -
( (struct V_19 * ) V_52 ) -> V_26 ;
}
static int F_14 ( struct V_54 * V_55 )
{
struct V_16 * V_56 ;
struct V_57 * V_23 = V_55 -> V_58 . V_59 ;
V_56 = F_15 ( sizeof( * V_56 ) , V_60 ) ;
if ( ! V_56 )
return - V_61 ;
V_56 -> V_29 . V_62 = L_1 ;
V_56 -> V_29 . type = V_63 ;
V_56 -> V_29 . V_64 = V_65 ;
V_56 -> V_29 . V_66 =
F_16 ( V_65 ) ;
V_56 -> V_29 . V_67 = F_9 ;
V_56 -> V_29 . V_68 =
F_11 ;
F_17 ( V_23 -> V_24 , V_23 -> V_69 ,
sizeof( struct V_19 ) ,
F_13 , NULL ) ;
F_17 ( V_23 -> V_25 , V_23 -> V_70 ,
sizeof( struct V_19 ) ,
F_13 , NULL ) ;
V_56 -> V_23 = V_23 ;
F_18 ( V_55 , V_56 ) ;
F_19 ( & V_55 -> V_58 , & V_56 -> V_29 ) ;
return 0 ;
}
static int F_20 ( struct V_54 * V_55 )
{
struct V_16 * V_17 = F_21 ( V_55 ) ;
F_22 ( & V_17 -> V_29 ) ;
F_23 ( V_17 ) ;
return 0 ;
}
