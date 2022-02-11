static void
F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 ( & V_3 -> V_4 ) ;
}
static void
F_3 ( struct V_5 * V_6 )
{
T_1 * V_1 = ( T_1 * ) V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < ( sizeof( struct V_5 ) / sizeof( T_1 ) ) ;
V_7 ++ ) {
V_1 [ V_7 ] = F_4 ( V_1 [ V_7 ] ) ;
}
}
static void
F_2 ( struct V_8 * V_9 )
{
V_9 -> V_10 =
F_5 ( V_9 -> V_10 ) ;
V_9 -> V_11 =
F_5 ( V_9 -> V_11 ) ;
}
static T_1
F_6 ( void )
{
return F_7 ( sizeof( struct V_2 ) , V_12 ) ;
}
static T_1
F_8 ( void )
{
return F_7 ( sizeof( struct V_5 ) , V_12 ) ;
}
static void
F_9 ( struct V_13 * V_14 , enum V_15 V_16 )
{
V_14 -> V_17 = V_16 ;
if ( V_16 == V_18 ) {
memcpy ( V_14 -> V_19 , V_14 -> V_20 . V_21 ,
sizeof( struct V_2 ) ) ;
F_1 ( V_14 -> V_19 ) ;
}
V_14 -> V_22 = false ;
if ( V_14 -> V_23 . V_24 )
V_14 -> V_23 . V_24 ( V_14 -> V_23 . V_25 , V_16 ) ;
}
static void
F_10 ( struct V_13 * V_14 , enum V_15 V_16 )
{
V_14 -> V_26 = V_16 ;
if ( V_16 == V_18 ) {
memcpy ( V_14 -> V_6 , V_14 -> V_27 . V_21 ,
sizeof( struct V_5 ) ) ;
F_3 ( V_14 -> V_6 ) ;
}
V_14 -> V_28 = false ;
if ( V_14 -> V_23 . V_29 )
V_14 -> V_23 . V_29 ( V_14 -> V_23 . V_30 , V_16 ) ;
}
static void
F_11 ( struct V_13 * V_14 , enum V_15 V_16 )
{
V_14 -> V_31 = V_16 ;
V_14 -> V_32 = false ;
if ( V_14 -> V_23 . V_33 )
V_14 -> V_23 . V_33 ( V_14 -> V_23 . V_34 , V_16 ) ;
}
T_1
F_12 ( void )
{
return F_6 () + F_8 () ;
}
void
F_13 ( struct V_13 * V_14 , T_2 * V_35 , T_3 V_36 )
{
V_14 -> V_20 . V_21 = V_35 ;
V_14 -> V_20 . V_37 = V_36 ;
V_14 -> V_27 . V_21 = V_35 + F_6 () ;
V_14 -> V_27 . V_37 = V_36 + F_6 () ;
V_14 -> V_19 = (struct V_2 * ) V_35 ;
V_14 -> V_6 = (struct V_5 * )
( V_35 + F_6 () ) ;
}
static void
F_14 ( void * V_38 , struct V_39 * V_40 )
{
union V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_13 * V_14 = (struct V_13 * ) V_38 ;
V_42 = (union V_41 * ) V_40 ;
V_44 = (struct V_43 * ) V_40 ;
switch ( V_42 -> V_45 . V_46 ) {
case V_47 :
F_9 ( V_14 , V_44 -> V_48 ) ;
break;
case V_49 :
F_10 ( V_14 , V_44 -> V_48 ) ;
break;
case V_50 :
F_11 ( V_14 , V_44 -> V_48 ) ;
break;
default:
F_15 ( 1 ) ;
}
}
static void
F_16 ( void * V_51 , enum V_52 V_53 )
{
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) V_51 ;
switch ( V_53 ) {
case V_54 :
case V_55 :
if ( V_14 -> V_22 == true ) {
V_14 -> V_17 = V_56 ;
V_14 -> V_22 = false ;
if ( V_14 -> V_23 . V_24 ) {
V_14 -> V_23 . V_24 (
V_14 -> V_23 . V_25 ,
V_56 ) ;
}
}
if ( V_14 -> V_28 == true ) {
V_14 -> V_26 = V_56 ;
V_14 -> V_28 = false ;
if ( V_14 -> V_23 . V_29 ) {
V_14 -> V_23 . V_29 (
V_14 -> V_23 . V_30 ,
V_56 ) ;
}
}
if ( V_14 -> V_32 == true ) {
V_14 -> V_31 = V_56 ;
V_14 -> V_32 = false ;
if ( V_14 -> V_23 . V_33 ) {
V_14 -> V_23 . V_33 (
V_14 -> V_23 . V_34 ,
V_56 ) ;
}
}
break;
default:
break;
}
}
void
F_17 ( struct V_13 * V_14 , struct V_57 * V_58 ,
void * V_59 )
{
F_15 ( ! ( V_14 != NULL ) ) ;
V_14 -> V_59 = V_59 ;
V_14 -> V_58 = V_58 ;
F_18 ( V_14 -> V_58 , V_60 , F_14 , V_14 ) ;
F_19 ( & V_14 -> V_61 ) ;
F_20 ( & V_14 -> V_61 , F_16 , V_14 ) ;
F_21 ( V_14 -> V_58 , & V_14 -> V_61 ) ;
}
