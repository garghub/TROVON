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
T_2 * V_31 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_35 V_36 ;
T_3 V_37 [] = { V_38 } ;
int V_39 ;
V_39 = F_3 ( V_33 -> V_40 , V_37 , sizeof( V_37 ) , ( T_3 * ) & V_36 ,
sizeof( V_36 ) , 0 ) ;
if ( V_39 < 0 )
return V_39 ;
* V_31 = 0 ;
if ( 0xffff - F_4 ( V_36 . V_41 ) > 30 )
* V_31 |= V_42 ;
if ( V_36 . V_43 & ( 1 << 6 ) )
* V_31 |= V_44 ;
if ( V_36 . V_43 & ( 1 << 5 ) )
* V_31 |= V_45 ;
if ( V_36 . V_43 & ( 1 << 4 ) )
* V_31 |= V_46 ;
if ( V_36 . V_43 & ( 1 << 1 ) )
* V_31 |= V_47 ;
if ( ( * V_31 & ( V_46 | V_47 | V_45 ) ) !=
( V_46 | V_47 | V_45 ) )
* V_31 &= ~ V_44 ;
return 0 ;
}
static int F_5 ( struct V_29 * V_30 , T_4 * V_48 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_35 V_31 ;
char V_37 [] = { V_38 } ;
int V_39 ;
V_39 = F_3 ( V_33 -> V_40 , V_37 , sizeof( V_37 ) , ( char * ) & V_31 ,
sizeof( V_31 ) , 0 ) ;
if ( V_39 < 0 )
return V_39 ;
* V_48 = F_6 ( V_31 . V_49 ) ;
return 0 ;
}
static int F_7 ( struct V_29 * V_30 , T_4 * V_50 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_35 V_31 ;
T_3 V_37 [] = { V_38 } ;
int V_39 ;
V_39 = F_3 ( V_33 -> V_40 , V_37 , sizeof( V_37 ) , ( T_3 * ) & V_31 ,
sizeof( V_31 ) , 0 ) ;
if ( V_39 < 0 ) {
F_8 ( L_1 ,
V_39 ) ;
return V_39 ;
}
* V_50 = F_6 ( V_31 . V_51 ) ;
return 0 ;
}
static int F_9 ( struct V_29 * V_30 ,
T_5 * V_52 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_35 V_31 ;
char V_37 [] = { V_38 } ;
int V_39 ;
V_39 = F_3 ( V_33 -> V_40 , V_37 , sizeof( V_37 ) , ( char * ) & V_31 ,
sizeof( V_31 ) , 0 ) ;
if ( V_39 < 0 ) {
F_8 ( L_2
L_3 , V_39 ) ;
return V_39 ;
}
* V_52 = ( 0xffff - F_4 ( V_31 . V_41 ) ) ;
return 0 ;
}
static int F_10 ( struct V_29 * V_30 , T_5 * V_53 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_35 V_31 ;
char V_37 [] = { V_38 } ;
int V_39 ;
V_39 = F_3 ( V_33 -> V_40 , V_37 , sizeof( V_37 ) , ( char * ) & V_31 ,
sizeof( V_31 ) , 0 ) ;
if ( V_39 < 0 ) {
F_8 ( L_4 , V_39 ) ;
return V_39 ;
}
* V_53 = ( V_31 . V_53 << 8 ) | V_31 . V_53 ;
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
struct V_54 * V_55 )
{
V_55 -> V_56 = 800 ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 )
{
struct V_1 * V_57 = & V_30 -> V_58 ;
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_59 V_60 ;
char V_36 [ 2 ] ;
int F_8 ;
V_60 . V_37 = V_61 ;
V_60 . V_3 = F_16 ( F_1 ( V_57 ) ) ;
V_60 . V_62 = F_17 ( V_57 -> V_63 / 1000 ) ;
V_60 . V_64 = 0 ;
switch ( V_57 -> V_65 ) {
default:
case 8000000 :
V_60 . V_66 = 8 ;
break;
case 7000000 :
V_60 . V_66 = 7 ;
break;
case 6000000 :
V_60 . V_66 = 6 ;
break;
}
F_8 = F_3 ( V_33 -> V_40 ,
( char * ) & V_60 , sizeof( V_60 ) ,
V_36 , sizeof( V_36 ) , 0 ) ;
if ( F_8 < 0 )
F_8 ( L_6 , F_8 ) ;
return ( F_8 < 0 ) ? F_8 : 0 ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_32 * V_33 = V_30 -> V_34 ;
if ( V_33 != NULL )
F_19 ( V_33 ) ;
}
struct V_29 * F_20 ( struct V_67 * V_40 )
{
struct V_32 * V_68 = F_21 ( sizeof(
struct V_32 ) , V_69 ) ;
if ( V_68 == NULL )
return NULL ;
V_68 -> V_40 = V_40 ;
memcpy ( & V_68 -> V_30 . V_70 , & V_71 , sizeof( struct V_72 ) ) ;
V_68 -> V_30 . V_34 = V_68 ;
return & V_68 -> V_30 ;
}
