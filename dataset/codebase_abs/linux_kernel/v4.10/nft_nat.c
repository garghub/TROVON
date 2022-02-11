static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_9 V_10 ;
struct V_11 * V_12 = F_3 ( V_6 -> V_13 , & V_10 ) ;
struct V_14 V_15 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
if ( V_8 -> V_16 ) {
if ( V_8 -> V_17 == V_18 ) {
V_15 . V_19 . V_20 = ( V_21 V_22 )
V_4 -> V_23 [ V_8 -> V_16 ] ;
V_15 . V_24 . V_20 = ( V_21 V_22 )
V_4 -> V_23 [ V_8 -> V_25 ] ;
} else {
memcpy ( V_15 . V_19 . V_26 ,
& V_4 -> V_23 [ V_8 -> V_16 ] ,
sizeof( V_15 . V_19 . V_26 ) ) ;
memcpy ( V_15 . V_24 . V_26 ,
& V_4 -> V_23 [ V_8 -> V_25 ] ,
sizeof( V_15 . V_24 . V_26 ) ) ;
}
V_15 . V_27 |= V_28 ;
}
if ( V_8 -> V_29 ) {
V_15 . V_30 . V_31 =
* ( V_32 * ) & V_4 -> V_23 [ V_8 -> V_29 ] ;
V_15 . V_33 . V_31 =
* ( V_32 * ) & V_4 -> V_23 [ V_8 -> V_34 ] ;
V_15 . V_27 |= V_35 ;
}
V_15 . V_27 |= V_8 -> V_27 ;
V_4 -> V_36 . V_37 = F_4 ( V_12 , & V_15 , V_8 -> type ) ;
}
static int F_5 ( const struct V_38 * V_39 ,
const struct V_1 * V_2 ,
const struct V_40 * * V_23 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_41 ;
V_41 = F_6 ( V_39 -> V_42 , V_43 ) ;
if ( V_41 < 0 )
return V_41 ;
switch ( V_8 -> type ) {
case V_44 :
V_41 = F_7 ( V_39 -> V_42 ,
( 1 << V_45 ) |
( 1 << V_46 ) ) ;
break;
case V_47 :
V_41 = F_7 ( V_39 -> V_42 ,
( 1 << V_48 ) |
( 1 << V_49 ) ) ;
break;
}
return V_41 ;
}
static int F_8 ( const struct V_38 * V_39 , const struct V_1 * V_2 ,
const struct V_50 * const V_51 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_52 , V_53 ;
T_1 V_17 ;
int V_41 ;
if ( V_51 [ V_54 ] == NULL ||
( V_51 [ V_55 ] == NULL &&
V_51 [ V_56 ] == NULL ) )
return - V_57 ;
switch ( F_9 ( F_10 ( V_51 [ V_54 ] ) ) ) {
case V_44 :
V_8 -> type = V_58 ;
break;
case V_47 :
V_8 -> type = V_59 ;
break;
default:
return - V_57 ;
}
V_41 = F_5 ( V_39 , V_2 , NULL ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_51 [ V_60 ] == NULL )
return - V_57 ;
V_17 = F_9 ( F_10 ( V_51 [ V_60 ] ) ) ;
if ( V_17 != V_39 -> V_61 -> V_17 )
return - V_62 ;
switch ( V_17 ) {
case V_63 :
V_52 = F_11 ( struct V_14 , V_19 . V_20 ) ;
break;
case V_64 :
V_52 = F_11 ( struct V_14 , V_19 . V_26 ) ;
break;
default:
return - V_65 ;
}
V_8 -> V_17 = V_17 ;
if ( V_51 [ V_55 ] ) {
V_8 -> V_16 =
F_12 ( V_51 [ V_55 ] ) ;
V_41 = F_13 ( V_8 -> V_16 , V_52 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_51 [ V_66 ] ) {
V_8 -> V_25 =
F_12 ( V_51 [ V_66 ] ) ;
V_41 = F_13 ( V_8 -> V_25 ,
V_52 ) ;
if ( V_41 < 0 )
return V_41 ;
} else {
V_8 -> V_25 = V_8 -> V_16 ;
}
}
V_53 = F_11 ( struct V_14 , V_19 . V_31 ) ;
if ( V_51 [ V_56 ] ) {
V_8 -> V_29 =
F_12 ( V_51 [ V_56 ] ) ;
V_41 = F_13 ( V_8 -> V_29 , V_53 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_51 [ V_67 ] ) {
V_8 -> V_34 =
F_12 ( V_51 [ V_67 ] ) ;
V_41 = F_13 ( V_8 -> V_34 ,
V_53 ) ;
if ( V_41 < 0 )
return V_41 ;
} else {
V_8 -> V_34 = V_8 -> V_29 ;
}
}
if ( V_51 [ V_68 ] ) {
V_8 -> V_27 = F_9 ( F_10 ( V_51 [ V_68 ] ) ) ;
if ( V_8 -> V_27 & ~ V_69 )
return - V_57 ;
}
return F_14 ( V_39 -> V_70 , V_17 ) ;
}
static int F_15 ( struct V_71 * V_13 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
switch ( V_8 -> type ) {
case V_58 :
if ( F_16 ( V_13 , V_54 , F_17 ( V_44 ) ) )
goto V_72;
break;
case V_59 :
if ( F_16 ( V_13 , V_54 , F_17 ( V_47 ) ) )
goto V_72;
break;
}
if ( F_16 ( V_13 , V_60 , F_17 ( V_8 -> V_17 ) ) )
goto V_72;
if ( V_8 -> V_16 ) {
if ( F_18 ( V_13 , V_55 ,
V_8 -> V_16 ) ||
F_18 ( V_13 , V_66 ,
V_8 -> V_25 ) )
goto V_72;
}
if ( V_8 -> V_29 ) {
if ( F_18 ( V_13 , V_56 ,
V_8 -> V_29 ) ||
F_18 ( V_13 , V_67 ,
V_8 -> V_34 ) )
goto V_72;
}
if ( V_8 -> V_27 != 0 ) {
if ( F_16 ( V_13 , V_68 , F_17 ( V_8 -> V_27 ) ) )
goto V_72;
}
return 0 ;
V_72:
return - 1 ;
}
static void
F_19 ( const struct V_38 * V_39 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
F_20 ( V_39 -> V_70 , V_8 -> V_17 ) ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_73 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_73 ) ;
}
