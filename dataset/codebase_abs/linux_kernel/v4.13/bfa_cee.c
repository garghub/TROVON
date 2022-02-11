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
enum V_15
F_14 ( struct V_13 * V_14 , struct V_2 * V_19 ,
T_4 V_23 , void * V_38 )
{
struct V_39 * V_40 ;
F_15 ( ! ( ( V_14 != NULL ) && ( V_14 -> V_41 != NULL ) ) ) ;
if ( ! F_16 ( V_14 -> V_41 ) )
return V_42 ;
if ( V_14 -> V_22 )
return V_43 ;
V_14 -> V_22 = true ;
V_40 = (struct V_39 * ) V_14 -> V_44 . V_45 ;
V_14 -> V_19 = V_19 ;
V_14 -> V_23 . V_24 = V_23 ;
V_14 -> V_23 . V_25 = V_38 ;
F_17 ( V_40 -> V_46 , V_47 , V_48 ,
F_18 ( V_14 -> V_41 ) ) ;
F_19 ( V_40 -> V_49 , V_14 -> V_20 . V_37 ) ;
F_20 ( V_14 -> V_41 , & V_14 -> V_44 , NULL , NULL ) ;
return V_18 ;
}
static void
F_21 ( void * V_38 , struct V_50 * V_51 )
{
union V_52 * V_45 ;
struct V_53 * V_54 ;
struct V_13 * V_14 = (struct V_13 * ) V_38 ;
V_45 = (union V_52 * ) V_51 ;
V_54 = (struct V_53 * ) V_51 ;
switch ( V_45 -> V_46 . V_55 ) {
case V_56 :
F_9 ( V_14 , V_54 -> V_57 ) ;
break;
case V_58 :
F_10 ( V_14 , V_54 -> V_57 ) ;
break;
case V_59 :
F_11 ( V_14 , V_54 -> V_57 ) ;
break;
default:
F_15 ( 1 ) ;
}
}
static void
F_22 ( void * V_60 , enum V_61 V_62 )
{
struct V_13 * V_14 ;
V_14 = (struct V_13 * ) V_60 ;
switch ( V_62 ) {
case V_63 :
case V_64 :
if ( V_14 -> V_22 ) {
V_14 -> V_17 = V_65 ;
V_14 -> V_22 = false ;
if ( V_14 -> V_23 . V_24 ) {
V_14 -> V_23 . V_24 (
V_14 -> V_23 . V_25 ,
V_65 ) ;
}
}
if ( V_14 -> V_28 ) {
V_14 -> V_26 = V_65 ;
V_14 -> V_28 = false ;
if ( V_14 -> V_23 . V_29 ) {
V_14 -> V_23 . V_29 (
V_14 -> V_23 . V_30 ,
V_65 ) ;
}
}
if ( V_14 -> V_32 ) {
V_14 -> V_31 = V_65 ;
V_14 -> V_32 = false ;
if ( V_14 -> V_23 . V_33 ) {
V_14 -> V_23 . V_33 (
V_14 -> V_23 . V_34 ,
V_65 ) ;
}
}
break;
default:
break;
}
}
void
F_23 ( struct V_13 * V_14 , struct V_66 * V_41 ,
void * V_67 )
{
F_15 ( ! ( V_14 != NULL ) ) ;
V_14 -> V_67 = V_67 ;
V_14 -> V_41 = V_41 ;
F_24 ( V_14 -> V_41 , V_47 , F_21 , V_14 ) ;
F_25 ( & V_14 -> V_68 , F_22 , V_14 ) ;
F_26 ( V_14 -> V_41 , & V_14 -> V_68 ) ;
}
