static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
switch ( V_2 -> V_4 ) {
case V_5 :
V_3 |= ( 1 << 7 ) ;
break;
case V_6 :
V_3 |= ( 2 << 7 ) ;
break;
case V_7 :
V_3 |= ( 3 << 7 ) ;
break;
case V_8 :
V_3 |= ( 4 << 7 ) ;
break;
case V_9 :
case V_10 :
default:
;
}
switch ( V_2 -> V_11 ) {
case V_5 :
V_3 |= ( 1 << 4 ) ;
break;
case V_6 :
V_3 |= ( 2 << 4 ) ;
break;
case V_7 :
V_3 |= ( 3 << 4 ) ;
break;
case V_8 :
V_3 |= ( 4 << 4 ) ;
break;
case V_9 :
case V_10 :
default:
;
}
switch ( V_2 -> V_12 ) {
case V_13 :
V_3 |= ( 1 << 13 ) ;
break;
case V_14 :
V_3 |= ( 2 << 13 ) ;
break;
case V_15 :
default:
;
}
switch ( V_2 -> V_16 ) {
case V_17 :
V_3 |= ( 1 << 0 ) ;
break;
case V_18 :
default:
;
}
switch ( V_2 -> V_19 ) {
case V_20 :
V_3 |= ( 1 << 2 ) ;
break;
case V_21 :
V_3 |= ( 2 << 2 ) ;
break;
case V_22 :
V_3 |= ( 3 << 2 ) ;
break;
case V_23 :
default:
;
}
switch ( V_2 -> V_24 ) {
case V_25 :
V_3 |= ( 1 << 10 ) ;
break;
case V_26 :
V_3 |= ( 2 << 10 ) ;
break;
case V_27 :
V_3 |= ( 3 << 10 ) ;
break;
case V_28 :
default:
;
}
return V_3 ;
}
static int F_2 ( struct V_29 * V_30 ,
enum V_31 * V_32 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
struct V_36 V_37 ;
T_2 V_38 [] = { V_39 } ;
int V_40 ;
V_40 = F_3 ( V_34 -> V_41 , V_38 , sizeof( V_38 ) , ( T_2 * ) & V_37 ,
sizeof( V_37 ) , 0 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_32 = 0 ;
if ( 0xffff - F_4 ( V_37 . V_42 ) > 30 )
* V_32 |= V_43 ;
if ( V_37 . V_44 & ( 1 << 6 ) )
* V_32 |= V_45 ;
if ( V_37 . V_44 & ( 1 << 5 ) )
* V_32 |= V_46 ;
if ( V_37 . V_44 & ( 1 << 4 ) )
* V_32 |= V_47 ;
if ( V_37 . V_44 & ( 1 << 1 ) )
* V_32 |= V_48 ;
if ( ( * V_32 & ( V_47 | V_48 | V_46 ) ) !=
( V_47 | V_48 | V_46 ) )
* V_32 &= ~ V_45 ;
return 0 ;
}
static int F_5 ( struct V_29 * V_30 , T_3 * V_49 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
struct V_36 V_32 ;
char V_38 [] = { V_39 } ;
int V_40 ;
V_40 = F_3 ( V_34 -> V_41 , V_38 , sizeof( V_38 ) , ( char * ) & V_32 ,
sizeof( V_32 ) , 0 ) ;
if ( V_40 < 0 )
return V_40 ;
* V_49 = F_6 ( V_32 . V_50 ) ;
return 0 ;
}
static int F_7 ( struct V_29 * V_30 , T_3 * V_51 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
struct V_36 V_32 ;
T_2 V_38 [] = { V_39 } ;
int V_40 ;
V_40 = F_3 ( V_34 -> V_41 , V_38 , sizeof( V_38 ) , ( T_2 * ) & V_32 ,
sizeof( V_32 ) , 0 ) ;
if ( V_40 < 0 ) {
F_8 ( L_1 ,
V_40 ) ;
return V_40 ;
}
* V_51 = F_6 ( V_32 . V_52 ) ;
return 0 ;
}
static int F_9 ( struct V_29 * V_30 ,
T_4 * V_53 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
struct V_36 V_32 ;
char V_38 [] = { V_39 } ;
int V_40 ;
V_40 = F_3 ( V_34 -> V_41 , V_38 , sizeof( V_38 ) , ( char * ) & V_32 ,
sizeof( V_32 ) , 0 ) ;
if ( V_40 < 0 ) {
F_8 ( L_2
L_3 , V_40 ) ;
return V_40 ;
}
* V_53 = ( 0xffff - F_4 ( V_32 . V_42 ) ) ;
return 0 ;
}
static int F_10 ( struct V_29 * V_30 , T_4 * V_54 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
struct V_36 V_32 ;
char V_38 [] = { V_39 } ;
int V_40 ;
V_40 = F_3 ( V_34 -> V_41 , V_38 , sizeof( V_38 ) , ( char * ) & V_32 ,
sizeof( V_32 ) , 0 ) ;
if ( V_40 < 0 ) {
F_8 ( L_4 , V_40 ) ;
return V_40 ;
}
* V_54 = ( V_32 . V_54 << 8 ) | V_32 . V_54 ;
return 0 ;
}
static int F_11 ( struct V_29 * V_30 )
{
return 0 ;
}
static int F_12 ( struct V_29 * V_30 )
{
F_13 ( L_5 ) ;
return 0 ;
}
static int F_14 ( struct V_29 * V_30 ,
struct V_55 * V_56 )
{
V_56 -> V_57 = 800 ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_1 * V_58 = & V_30 -> V_59 ;
struct V_33 * V_34 = V_30 -> V_35 ;
struct V_60 V_61 ;
char V_37 [ 2 ] ;
int F_8 ;
V_61 . V_38 = V_62 ;
V_61 . V_3 = F_16 ( F_1 ( V_58 ) ) ;
V_61 . V_63 = F_17 ( V_58 -> V_64 / 1000 ) ;
V_61 . V_65 = 0 ;
switch ( V_58 -> V_66 ) {
default:
case 8000000 :
V_61 . V_67 = 8 ;
break;
case 7000000 :
V_61 . V_67 = 7 ;
break;
case 6000000 :
V_61 . V_67 = 6 ;
break;
}
F_8 = F_3 ( V_34 -> V_41 ,
( char * ) & V_61 , sizeof( V_61 ) ,
V_37 , sizeof( V_37 ) , 0 ) ;
if ( F_8 < 0 )
F_8 ( L_6 , F_8 ) ;
return ( F_8 < 0 ) ? F_8 : 0 ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
F_19 ( V_34 ) ;
}
struct V_29 * F_20 ( struct V_68 * V_41 )
{
struct V_33 * V_69 = F_21 ( sizeof(
struct V_33 ) , V_70 ) ;
if ( V_69 == NULL )
return NULL ;
V_69 -> V_41 = V_41 ;
memcpy ( & V_69 -> V_30 . V_71 , & V_72 , sizeof( struct V_73 ) ) ;
V_69 -> V_30 . V_35 = V_69 ;
return & V_69 -> V_30 ;
}
