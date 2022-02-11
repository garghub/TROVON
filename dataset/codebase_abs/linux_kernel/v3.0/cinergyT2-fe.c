static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_6 ;
T_1 V_7 = 0 ;
switch ( V_4 -> V_8 ) {
case V_9 :
V_7 |= ( 1 << 7 ) ;
break;
case V_10 :
V_7 |= ( 2 << 7 ) ;
break;
case V_11 :
V_7 |= ( 3 << 7 ) ;
break;
case V_12 :
V_7 |= ( 4 << 7 ) ;
break;
case V_13 :
case V_14 :
default:
;
}
switch ( V_4 -> V_15 ) {
case V_9 :
V_7 |= ( 1 << 4 ) ;
break;
case V_10 :
V_7 |= ( 2 << 4 ) ;
break;
case V_11 :
V_7 |= ( 3 << 4 ) ;
break;
case V_12 :
V_7 |= ( 4 << 4 ) ;
break;
case V_13 :
case V_14 :
default:
;
}
switch ( V_4 -> V_16 ) {
case V_17 :
V_7 |= ( 1 << 13 ) ;
break;
case V_18 :
V_7 |= ( 2 << 13 ) ;
break;
case V_19 :
default:
;
}
switch ( V_4 -> V_20 ) {
case V_21 :
V_7 |= ( 1 << 0 ) ;
break;
case V_22 :
default:
;
}
switch ( V_4 -> V_23 ) {
case V_24 :
V_7 |= ( 1 << 2 ) ;
break;
case V_25 :
V_7 |= ( 2 << 2 ) ;
break;
case V_26 :
V_7 |= ( 3 << 2 ) ;
break;
case V_27 :
default:
;
}
switch ( V_4 -> V_28 ) {
case V_29 :
V_7 |= ( 1 << 10 ) ;
break;
case V_30 :
V_7 |= ( 2 << 10 ) ;
break;
case V_31 :
V_7 |= ( 3 << 10 ) ;
break;
case V_32 :
default:
;
}
return V_7 ;
}
static int F_2 ( struct V_33 * V_34 ,
T_2 * V_35 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_39 V_40 ;
T_3 V_41 [] = { V_42 } ;
int V_43 ;
V_43 = F_3 ( V_37 -> V_44 , V_41 , sizeof( V_41 ) , ( T_3 * ) & V_40 ,
sizeof( V_40 ) , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
* V_35 = 0 ;
if ( 0xffff - F_4 ( V_40 . V_45 ) > 30 )
* V_35 |= V_46 ;
if ( V_40 . V_47 & ( 1 << 6 ) )
* V_35 |= V_48 ;
if ( V_40 . V_47 & ( 1 << 5 ) )
* V_35 |= V_49 ;
if ( V_40 . V_47 & ( 1 << 4 ) )
* V_35 |= V_50 ;
if ( V_40 . V_47 & ( 1 << 1 ) )
* V_35 |= V_51 ;
if ( ( * V_35 & ( V_50 | V_51 | V_49 ) ) !=
( V_50 | V_51 | V_49 ) )
* V_35 &= ~ V_48 ;
return 0 ;
}
static int F_5 ( struct V_33 * V_34 , T_4 * V_52 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_39 V_35 ;
char V_41 [] = { V_42 } ;
int V_43 ;
V_43 = F_3 ( V_37 -> V_44 , V_41 , sizeof( V_41 ) , ( char * ) & V_35 ,
sizeof( V_35 ) , 0 ) ;
if ( V_43 < 0 )
return V_43 ;
* V_52 = F_6 ( V_35 . V_53 ) ;
return 0 ;
}
static int F_7 ( struct V_33 * V_34 , T_4 * V_54 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_39 V_35 ;
T_3 V_41 [] = { V_42 } ;
int V_43 ;
V_43 = F_3 ( V_37 -> V_44 , V_41 , sizeof( V_41 ) , ( T_3 * ) & V_35 ,
sizeof( V_35 ) , 0 ) ;
if ( V_43 < 0 ) {
F_8 ( L_1 ,
V_43 ) ;
return V_43 ;
}
* V_54 = F_6 ( V_35 . V_55 ) ;
return 0 ;
}
static int F_9 ( struct V_33 * V_34 ,
T_5 * V_56 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_39 V_35 ;
char V_41 [] = { V_42 } ;
int V_43 ;
V_43 = F_3 ( V_37 -> V_44 , V_41 , sizeof( V_41 ) , ( char * ) & V_35 ,
sizeof( V_35 ) , 0 ) ;
if ( V_43 < 0 ) {
F_8 ( L_2
L_3 , V_43 ) ;
return V_43 ;
}
* V_56 = ( 0xffff - F_4 ( V_35 . V_45 ) ) ;
return 0 ;
}
static int F_10 ( struct V_33 * V_34 , T_5 * V_57 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_39 V_35 ;
char V_41 [] = { V_42 } ;
int V_43 ;
V_43 = F_3 ( V_37 -> V_44 , V_41 , sizeof( V_41 ) , ( char * ) & V_35 ,
sizeof( V_35 ) , 0 ) ;
if ( V_43 < 0 ) {
F_8 ( L_4 , V_43 ) ;
return V_43 ;
}
* V_57 = ( V_35 . V_57 << 8 ) | V_35 . V_57 ;
return 0 ;
}
static int F_11 ( struct V_33 * V_34 )
{
return 0 ;
}
static int F_12 ( struct V_33 * V_34 )
{
F_13 ( L_5 ) ;
return 0 ;
}
static int F_14 ( struct V_33 * V_34 ,
struct V_58 * V_59 )
{
V_59 -> V_60 = 800 ;
return 0 ;
}
static int F_15 ( struct V_33 * V_34 ,
struct V_1 * V_61 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_62 V_63 ;
char V_40 [ 2 ] ;
int F_8 ;
V_63 . V_41 = V_64 ;
V_63 . V_7 = F_16 ( F_1 ( V_61 ) ) ;
V_63 . V_65 = F_17 ( V_61 -> V_66 / 1000 ) ;
V_63 . V_67 = 8 - V_61 -> V_5 . V_6 . V_67 - V_68 ;
V_63 . V_69 = 0 ;
F_8 = F_3 ( V_37 -> V_44 ,
( char * ) & V_63 , sizeof( V_63 ) ,
V_40 , sizeof( V_40 ) , 0 ) ;
if ( F_8 < 0 )
F_8 ( L_6 , F_8 ) ;
return ( F_8 < 0 ) ? F_8 : 0 ;
}
static int F_18 ( struct V_33 * V_34 ,
struct V_1 * V_61 )
{
return 0 ;
}
static void F_19 ( struct V_33 * V_34 )
{
struct V_36 * V_37 = V_34 -> V_38 ;
if ( V_37 != NULL )
F_20 ( V_37 ) ;
}
struct V_33 * F_21 ( struct V_70 * V_44 )
{
struct V_36 * V_71 = F_22 ( sizeof(
struct V_36 ) , V_72 ) ;
if ( V_71 == NULL )
return NULL ;
V_71 -> V_44 = V_44 ;
memcpy ( & V_71 -> V_34 . V_73 , & V_74 , sizeof( struct V_75 ) ) ;
V_71 -> V_34 . V_38 = V_71 ;
return & V_71 -> V_34 ;
}
