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
V_16 . V_30 . V_31 = ( V_22 V_32 )
V_4 [ V_9 -> V_29 ] . V_4 [ 0 ] ;
V_16 . V_33 . V_31 = ( V_22 V_32 )
V_4 [ V_9 -> V_34 ] . V_4 [ 0 ] ;
V_16 . V_27 |= V_35 ;
}
V_16 . V_27 |= V_9 -> V_27 ;
V_4 [ V_36 ] . V_37 =
F_4 ( V_13 , & V_16 , V_9 -> type ) ;
}
static int F_5 ( const struct V_38 * V_39 , const struct V_1 * V_2 ,
const struct V_40 * const V_41 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_18 ;
int V_42 ;
V_42 = F_6 ( V_39 -> V_43 , V_44 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_41 [ V_45 ] == NULL ||
( V_41 [ V_46 ] == NULL &&
V_41 [ V_47 ] == NULL ) )
return - V_48 ;
switch ( F_7 ( F_8 ( V_41 [ V_45 ] ) ) ) {
case V_49 :
V_9 -> type = V_50 ;
break;
case V_51 :
V_9 -> type = V_52 ;
break;
default:
return - V_48 ;
}
if ( V_41 [ V_53 ] == NULL )
return - V_48 ;
V_18 = F_7 ( F_8 ( V_41 [ V_53 ] ) ) ;
if ( V_18 != V_19 && V_18 != V_54 )
return - V_55 ;
if ( V_18 != V_39 -> V_56 -> V_18 )
return - V_57 ;
V_9 -> V_18 = V_18 ;
if ( V_41 [ V_46 ] ) {
V_9 -> V_17 =
F_7 ( F_8 ( V_41 [ V_46 ] ) ) ;
V_42 = F_9 ( V_9 -> V_17 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_41 [ V_58 ] ) {
V_9 -> V_25 =
F_7 ( F_8 ( V_41 [ V_58 ] ) ) ;
V_42 = F_9 ( V_9 -> V_25 ) ;
if ( V_42 < 0 )
return V_42 ;
} else {
V_9 -> V_25 = V_9 -> V_17 ;
}
}
if ( V_41 [ V_47 ] ) {
V_9 -> V_29 =
F_7 ( F_8 ( V_41 [ V_47 ] ) ) ;
V_42 = F_9 ( V_9 -> V_29 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_41 [ V_59 ] ) {
V_9 -> V_34 =
F_7 ( F_8 ( V_41 [ V_59 ] ) ) ;
V_42 = F_9 ( V_9 -> V_34 ) ;
if ( V_42 < 0 )
return V_42 ;
} else {
V_9 -> V_34 = V_9 -> V_29 ;
}
}
if ( V_41 [ V_60 ] ) {
V_9 -> V_27 = F_7 ( F_8 ( V_41 [ V_60 ] ) ) ;
if ( V_9 -> V_27 & ~ V_61 )
return - V_48 ;
}
return 0 ;
}
static int F_10 ( struct V_62 * V_14 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_9 -> type ) {
case V_50 :
if ( F_11 ( V_14 , V_45 , F_12 ( V_49 ) ) )
goto V_63;
break;
case V_52 :
if ( F_11 ( V_14 , V_45 , F_12 ( V_51 ) ) )
goto V_63;
break;
}
if ( F_11 ( V_14 , V_53 , F_12 ( V_9 -> V_18 ) ) )
goto V_63;
if ( V_9 -> V_17 ) {
if ( F_11 ( V_14 , V_46 ,
F_12 ( V_9 -> V_17 ) ) ||
F_11 ( V_14 , V_58 ,
F_12 ( V_9 -> V_25 ) ) )
goto V_63;
}
if ( V_9 -> V_29 ) {
if ( F_11 ( V_14 , V_47 ,
F_12 ( V_9 -> V_29 ) ) ||
F_11 ( V_14 , V_59 ,
F_12 ( V_9 -> V_34 ) ) )
goto V_63;
}
if ( V_9 -> V_27 != 0 ) {
if ( F_11 ( V_14 , V_60 , F_12 ( V_9 -> V_27 ) ) )
goto V_63;
}
return 0 ;
V_63:
return - 1 ;
}
static int F_13 ( const struct V_38 * V_39 ,
const struct V_1 * V_2 ,
const struct V_3 * * V_4 )
{
return F_6 ( V_39 -> V_43 , V_44 ) ;
}
static int T_2 F_14 ( void )
{
return F_15 ( & V_64 ) ;
}
static void T_3 F_16 ( void )
{
F_17 ( & V_64 ) ;
}
