static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
enum V_10 V_11 ;
struct V_12 * V_13 = F_3 ( V_7 -> V_14 , & V_11 ) ;
struct V_15 V_16 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
if ( V_9 -> V_17 ) {
if ( V_9 -> V_18 == V_19 ) {
V_16 . V_20 . V_21 = ( V_22 V_23 )
V_4 [ V_9 -> V_17 ] . V_4 [ 0 ] ;
V_16 . V_24 . V_21 = ( V_22 V_23 )
V_4 [ V_9 -> V_25 ] . V_4 [ 0 ] ;
} else {
memcpy ( V_16 . V_20 . V_26 ,
V_4 [ V_9 -> V_17 ] . V_4 ,
sizeof( struct V_3 ) ) ;
memcpy ( V_16 . V_24 . V_26 ,
V_4 [ V_9 -> V_25 ] . V_4 ,
sizeof( struct V_3 ) ) ;
}
V_16 . V_27 |= V_28 ;
}
if ( V_9 -> V_29 ) {
V_16 . V_30 . V_31 =
* ( V_32 * ) & V_4 [ V_9 -> V_29 ] . V_4 [ 0 ] ;
V_16 . V_33 . V_31 =
* ( V_32 * ) & V_4 [ V_9 -> V_34 ] . V_4 [ 0 ] ;
V_16 . V_27 |= V_35 ;
}
V_16 . V_27 |= V_9 -> V_27 ;
V_4 [ V_36 ] . V_37 =
F_4 ( V_13 , & V_16 , V_9 -> type ) ;
}
static int F_5 ( const struct V_38 * V_39 ,
const struct V_1 * V_2 ,
const struct V_3 * * V_4 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_40 ;
V_40 = F_6 ( V_39 -> V_41 , V_42 ) ;
if ( V_40 < 0 )
return V_40 ;
switch ( V_9 -> type ) {
case V_43 :
V_40 = F_7 ( V_39 -> V_41 ,
( 1 << V_44 ) |
( 1 << V_45 ) ) ;
break;
case V_46 :
V_40 = F_7 ( V_39 -> V_41 ,
( 1 << V_47 ) |
( 1 << V_48 ) ) ;
break;
}
return V_40 ;
}
static int F_8 ( const struct V_38 * V_39 , const struct V_1 * V_2 ,
const struct V_49 * const V_50 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_18 ;
int V_40 ;
if ( V_50 [ V_51 ] == NULL ||
( V_50 [ V_52 ] == NULL &&
V_50 [ V_53 ] == NULL ) )
return - V_54 ;
switch ( F_9 ( F_10 ( V_50 [ V_51 ] ) ) ) {
case V_43 :
V_9 -> type = V_55 ;
break;
case V_46 :
V_9 -> type = V_56 ;
break;
default:
return - V_54 ;
}
V_40 = F_5 ( V_39 , V_2 , NULL ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_50 [ V_57 ] == NULL )
return - V_54 ;
V_18 = F_9 ( F_10 ( V_50 [ V_57 ] ) ) ;
if ( V_18 != V_19 && V_18 != V_58 )
return - V_59 ;
if ( V_18 != V_39 -> V_60 -> V_18 )
return - V_61 ;
V_9 -> V_18 = V_18 ;
if ( V_50 [ V_52 ] ) {
V_9 -> V_17 =
F_9 ( F_10 ( V_50 [ V_52 ] ) ) ;
V_40 = F_11 ( V_9 -> V_17 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_50 [ V_62 ] ) {
V_9 -> V_25 =
F_9 ( F_10 ( V_50 [ V_62 ] ) ) ;
V_40 = F_11 ( V_9 -> V_25 ) ;
if ( V_40 < 0 )
return V_40 ;
} else {
V_9 -> V_25 = V_9 -> V_17 ;
}
}
if ( V_50 [ V_53 ] ) {
V_9 -> V_29 =
F_9 ( F_10 ( V_50 [ V_53 ] ) ) ;
V_40 = F_11 ( V_9 -> V_29 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_50 [ V_63 ] ) {
V_9 -> V_34 =
F_9 ( F_10 ( V_50 [ V_63 ] ) ) ;
V_40 = F_11 ( V_9 -> V_34 ) ;
if ( V_40 < 0 )
return V_40 ;
} else {
V_9 -> V_34 = V_9 -> V_29 ;
}
}
if ( V_50 [ V_64 ] ) {
V_9 -> V_27 = F_9 ( F_10 ( V_50 [ V_64 ] ) ) ;
if ( V_9 -> V_27 & ~ V_65 )
return - V_54 ;
}
return 0 ;
}
static int F_12 ( struct V_66 * V_14 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_9 -> type ) {
case V_55 :
if ( F_13 ( V_14 , V_51 , F_14 ( V_43 ) ) )
goto V_67;
break;
case V_56 :
if ( F_13 ( V_14 , V_51 , F_14 ( V_46 ) ) )
goto V_67;
break;
}
if ( F_13 ( V_14 , V_57 , F_14 ( V_9 -> V_18 ) ) )
goto V_67;
if ( V_9 -> V_17 ) {
if ( F_13 ( V_14 , V_52 ,
F_14 ( V_9 -> V_17 ) ) ||
F_13 ( V_14 , V_62 ,
F_14 ( V_9 -> V_25 ) ) )
goto V_67;
}
if ( V_9 -> V_29 ) {
if ( F_13 ( V_14 , V_53 ,
F_14 ( V_9 -> V_29 ) ) ||
F_13 ( V_14 , V_63 ,
F_14 ( V_9 -> V_34 ) ) )
goto V_67;
}
if ( V_9 -> V_27 != 0 ) {
if ( F_13 ( V_14 , V_64 , F_14 ( V_9 -> V_27 ) ) )
goto V_67;
}
return 0 ;
V_67:
return - 1 ;
}
static int T_2 F_15 ( void )
{
return F_16 ( & V_68 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_68 ) ;
}
