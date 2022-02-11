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
V_4 [ V_36 ] . V_37 =
F_4 ( V_13 , & V_16 , V_9 -> type ) ;
}
static int F_5 ( const struct V_38 * V_39 , const struct V_1 * V_2 ,
const struct V_40 * const V_41 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_42 ;
if ( V_41 [ V_43 ] == NULL )
return - V_44 ;
switch ( F_6 ( F_7 ( V_41 [ V_43 ] ) ) ) {
case V_45 :
V_9 -> type = V_46 ;
break;
case V_47 :
V_9 -> type = V_48 ;
break;
default:
return - V_44 ;
}
if ( V_41 [ V_49 ] == NULL )
return - V_44 ;
V_9 -> V_18 = F_6 ( F_7 ( V_41 [ V_49 ] ) ) ;
if ( V_9 -> V_18 != V_19 && V_9 -> V_18 != V_50 )
return - V_44 ;
if ( V_41 [ V_51 ] ) {
V_9 -> V_17 = F_6 ( F_7 (
V_41 [ V_51 ] ) ) ;
V_42 = F_8 ( V_9 -> V_17 ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_41 [ V_52 ] ) {
V_9 -> V_25 = F_6 ( F_7 (
V_41 [ V_52 ] ) ) ;
V_42 = F_8 ( V_9 -> V_25 ) ;
if ( V_42 < 0 )
return V_42 ;
} else
V_9 -> V_25 = V_9 -> V_17 ;
if ( V_41 [ V_53 ] ) {
V_9 -> V_29 = F_6 ( F_7 (
V_41 [ V_53 ] ) ) ;
V_42 = F_8 ( V_9 -> V_29 ) ;
if ( V_42 < 0 )
return V_42 ;
}
if ( V_41 [ V_54 ] ) {
V_9 -> V_34 = F_6 ( F_7 (
V_41 [ V_54 ] ) ) ;
V_42 = F_8 ( V_9 -> V_34 ) ;
if ( V_42 < 0 )
return V_42 ;
} else
V_9 -> V_34 = V_9 -> V_29 ;
return 0 ;
}
static int F_9 ( struct V_55 * V_14 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
switch ( V_9 -> type ) {
case V_46 :
if ( F_10 ( V_14 , V_43 , F_11 ( V_45 ) ) )
goto V_56;
break;
case V_48 :
if ( F_10 ( V_14 , V_43 , F_11 ( V_47 ) ) )
goto V_56;
break;
}
if ( F_10 ( V_14 , V_49 , F_11 ( V_9 -> V_18 ) ) )
goto V_56;
if ( F_10 ( V_14 ,
V_51 , F_11 ( V_9 -> V_17 ) ) )
goto V_56;
if ( F_10 ( V_14 ,
V_52 , F_11 ( V_9 -> V_25 ) ) )
goto V_56;
if ( F_10 ( V_14 ,
V_53 , F_11 ( V_9 -> V_29 ) ) )
goto V_56;
if ( F_10 ( V_14 ,
V_54 , F_11 ( V_9 -> V_34 ) ) )
goto V_56;
return 0 ;
V_56:
return - 1 ;
}
static int T_1 F_12 ( void )
{
int V_42 ;
V_42 = F_13 ( & V_57 ) ;
if ( V_42 < 0 )
return V_42 ;
return 0 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_57 ) ;
}
