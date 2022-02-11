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
int V_36 ;
F_3 ( & V_34 -> V_37 ) ;
V_34 -> V_38 [ 0 ] = V_39 ;
V_36 = F_4 ( V_34 -> V_40 , V_34 -> V_38 , 1 ,
V_34 -> V_38 , sizeof( V_34 -> V_32 ) , 0 ) ;
if ( ! V_36 )
memcpy ( & V_34 -> V_32 , V_34 -> V_38 , sizeof( V_34 -> V_32 ) ) ;
F_5 ( & V_34 -> V_37 ) ;
if ( V_36 < 0 )
return V_36 ;
* V_32 = 0 ;
if ( 0xffff - F_6 ( V_34 -> V_32 . V_41 ) > 30 )
* V_32 |= V_42 ;
if ( V_34 -> V_32 . V_43 & ( 1 << 6 ) )
* V_32 |= V_44 ;
if ( V_34 -> V_32 . V_43 & ( 1 << 5 ) )
* V_32 |= V_45 ;
if ( V_34 -> V_32 . V_43 & ( 1 << 4 ) )
* V_32 |= V_46 ;
if ( V_34 -> V_32 . V_43 & ( 1 << 1 ) )
* V_32 |= V_47 ;
if ( ( * V_32 & ( V_46 | V_47 | V_45 ) ) !=
( V_46 | V_47 | V_45 ) )
* V_32 &= ~ V_44 ;
return 0 ;
}
static int F_7 ( struct V_29 * V_30 , T_2 * V_48 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
* V_48 = F_8 ( V_34 -> V_32 . V_49 ) ;
return 0 ;
}
static int F_9 ( struct V_29 * V_30 , T_2 * V_50 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
* V_50 = F_8 ( V_34 -> V_32 . V_51 ) ;
return 0 ;
}
static int F_10 ( struct V_29 * V_30 ,
T_3 * V_52 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
* V_52 = ( 0xffff - F_6 ( V_34 -> V_32 . V_41 ) ) ;
return 0 ;
}
static int F_11 ( struct V_29 * V_30 , T_3 * V_53 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
* V_53 = ( V_34 -> V_32 . V_53 << 8 ) | V_34 -> V_32 . V_53 ;
return 0 ;
}
static int F_12 ( struct V_29 * V_30 )
{
return 0 ;
}
static int F_13 ( struct V_29 * V_30 )
{
F_14 ( L_1 ) ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 ,
struct V_54 * V_55 )
{
V_55 -> V_56 = 800 ;
return 0 ;
}
static int F_16 ( struct V_29 * V_30 )
{
struct V_1 * V_57 = & V_30 -> V_58 ;
struct V_33 * V_34 = V_30 -> V_35 ;
struct V_59 * V_60 ;
int V_61 ;
F_3 ( & V_34 -> V_37 ) ;
V_60 = ( void * ) V_34 -> V_38 ;
V_60 -> V_62 = V_63 ;
V_60 -> V_3 = F_17 ( F_1 ( V_57 ) ) ;
V_60 -> V_64 = F_18 ( V_57 -> V_65 / 1000 ) ;
V_60 -> V_66 = 0 ;
switch ( V_57 -> V_67 ) {
default:
case 8000000 :
V_60 -> V_68 = 8 ;
break;
case 7000000 :
V_60 -> V_68 = 7 ;
break;
case 6000000 :
V_60 -> V_68 = 6 ;
break;
}
V_61 = F_4 ( V_34 -> V_40 , V_34 -> V_38 , sizeof( * V_60 ) ,
V_34 -> V_38 , 2 , 0 ) ;
if ( V_61 < 0 )
V_61 ( L_2 , V_61 ) ;
F_5 ( & V_34 -> V_37 ) ;
return ( V_61 < 0 ) ? V_61 : 0 ;
}
static void F_19 ( struct V_29 * V_30 )
{
struct V_33 * V_34 = V_30 -> V_35 ;
F_20 ( V_34 ) ;
}
struct V_29 * F_21 ( struct V_69 * V_40 )
{
struct V_33 * V_70 = F_22 ( sizeof(
struct V_33 ) , V_71 ) ;
if ( V_70 == NULL )
return NULL ;
V_70 -> V_40 = V_40 ;
memcpy ( & V_70 -> V_30 . V_72 , & V_73 , sizeof( struct V_74 ) ) ;
V_70 -> V_30 . V_35 = V_70 ;
F_23 ( & V_70 -> V_37 ) ;
return & V_70 -> V_30 ;
}
