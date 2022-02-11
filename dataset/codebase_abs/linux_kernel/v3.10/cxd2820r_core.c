static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_8 [ V_6 + 1 ] ;
struct V_9 V_10 [ 1 ] = {
{
. V_11 = V_3 ,
. V_12 = 0 ,
. V_6 = sizeof( V_8 ) ,
. V_8 = V_8 ,
}
} ;
V_8 [ 0 ] = V_4 ;
memcpy ( & V_8 [ 1 ] , V_5 , V_6 ) ;
V_7 = F_2 ( V_2 -> V_3 , V_10 , 1 ) ;
if ( V_7 == 1 ) {
V_7 = 0 ;
} else {
F_3 ( & V_2 -> V_3 -> V_13 , L_1 \
L_2 , V_14 , V_7 , V_4 , V_6 ) ;
V_7 = - V_15 ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_8 [ V_6 ] ;
struct V_9 V_10 [ 2 ] = {
{
. V_11 = V_3 ,
. V_12 = 0 ,
. V_6 = 1 ,
. V_8 = & V_4 ,
} , {
. V_11 = V_3 ,
. V_12 = V_16 ,
. V_6 = sizeof( V_8 ) ,
. V_8 = V_8 ,
}
} ;
V_7 = F_2 ( V_2 -> V_3 , V_10 , 2 ) ;
if ( V_7 == 2 ) {
memcpy ( V_5 , V_8 , V_6 ) ;
V_7 = 0 ;
} else {
F_3 ( & V_2 -> V_3 -> V_13 , L_3 \
L_2 , V_14 , V_7 , V_4 , V_6 ) ;
V_7 = - V_15 ;
}
return V_7 ;
}
int F_5 ( struct V_1 * V_2 , T_2 V_17 , T_1 * V_5 ,
int V_6 )
{
int V_7 ;
T_1 V_18 ;
T_1 V_4 = ( V_17 >> 0 ) & 0xff ;
T_1 V_19 = ( V_17 >> 8 ) & 0xff ;
T_1 V_3 = ( V_17 >> 16 ) & 0x01 ;
if ( V_3 )
V_18 = V_2 -> V_20 . V_21 | ( 1 << 1 ) ;
else
V_18 = V_2 -> V_20 . V_21 ;
if ( V_19 != V_2 -> V_19 [ V_3 ] ) {
V_7 = F_1 ( V_2 , V_18 , 0x00 , & V_19 , 1 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_19 [ V_3 ] = V_19 ;
}
return F_1 ( V_2 , V_18 , V_4 , V_5 , V_6 ) ;
}
int F_6 ( struct V_1 * V_2 , T_2 V_17 , T_1 * V_5 ,
int V_6 )
{
int V_7 ;
T_1 V_18 ;
T_1 V_4 = ( V_17 >> 0 ) & 0xff ;
T_1 V_19 = ( V_17 >> 8 ) & 0xff ;
T_1 V_3 = ( V_17 >> 16 ) & 0x01 ;
if ( V_3 )
V_18 = V_2 -> V_20 . V_21 | ( 1 << 1 ) ;
else
V_18 = V_2 -> V_20 . V_21 ;
if ( V_19 != V_2 -> V_19 [ V_3 ] ) {
V_7 = F_1 ( V_2 , V_18 , 0x00 , & V_19 , 1 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_19 [ V_3 ] = V_19 ;
}
return F_4 ( V_2 , V_18 , V_4 , V_5 , V_6 ) ;
}
int F_7 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_5 )
{
return F_5 ( V_2 , V_4 , & V_5 , 1 ) ;
}
int F_8 ( struct V_1 * V_2 , T_2 V_4 , T_1 * V_5 )
{
return F_6 ( V_2 , V_4 , V_5 , 1 ) ;
}
int F_9 ( struct V_1 * V_2 , T_2 V_4 , T_1 V_5 ,
T_1 V_22 )
{
int V_7 ;
T_1 V_23 ;
if ( V_22 != 0xff ) {
V_7 = F_8 ( V_2 , V_4 , & V_23 ) ;
if ( V_7 )
return V_7 ;
V_5 &= V_22 ;
V_23 &= ~ V_22 ;
V_5 |= V_23 ;
}
return F_7 ( V_2 , V_4 , V_5 ) ;
}
int F_10 ( struct V_24 * V_25 , T_1 * V_26 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 , V_28 ;
T_1 V_29 , V_30 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
if ( ! memcmp ( V_26 , V_2 -> V_26 , sizeof( V_2 -> V_26 ) ) )
return 0 ;
V_29 = 0x00 ;
V_30 = 0x00 ;
for ( V_28 = 0 ; V_28 < sizeof( V_2 -> V_26 ) ; V_28 ++ ) {
if ( V_26 [ V_28 ] & V_34 )
V_29 |= ( 2 << 6 ) >> ( 2 * V_28 ) ;
else
V_29 |= ( 1 << 6 ) >> ( 2 * V_28 ) ;
if ( V_26 [ V_28 ] & V_35 )
V_30 |= ( 1 << ( 3 + V_28 ) ) ;
else
V_30 |= ( 0 << ( 3 + V_28 ) ) ;
if ( V_26 [ V_28 ] & V_36 )
V_30 |= ( 1 << ( 0 + V_28 ) ) ;
else
V_30 |= ( 0 << ( 0 + V_28 ) ) ;
F_11 ( & V_2 -> V_3 -> V_13 , L_5 , V_31 ,
V_28 , V_29 , V_30 ) ;
}
F_11 ( & V_2 -> V_3 -> V_13 , L_6 , V_31 , V_29 ,
V_30 ) ;
V_7 = F_9 ( V_2 , 0x00089 , V_29 , 0xfc ) ;
if ( V_7 )
goto error;
V_7 = F_9 ( V_2 , 0x0008e , V_30 , 0x3f ) ;
if ( V_7 )
goto error;
memcpy ( V_2 -> V_26 , V_26 , sizeof( V_2 -> V_26 ) ) ;
return V_7 ;
error:
F_11 ( & V_2 -> V_3 -> V_13 , L_7 , V_31 , V_7 ) ;
return V_7 ;
}
T_2 F_12 ( T_3 V_37 , T_2 V_38 )
{
return F_13 ( V_37 + ( V_38 / 2 ) , V_38 ) ;
}
static int F_14 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
struct V_39 * V_40 = & V_25 -> V_32 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
switch ( V_40 -> V_33 ) {
case V_41 :
V_7 = F_15 ( V_25 ) ;
if ( V_7 < 0 )
goto V_42;
V_7 = F_16 ( V_25 ) ;
if ( V_7 < 0 )
goto V_42;
break;
case V_43 :
V_7 = F_15 ( V_25 ) ;
if ( V_7 < 0 )
goto V_42;
V_7 = F_17 ( V_25 ) ;
if ( V_7 < 0 )
goto V_42;
break;
case V_44 :
V_7 = F_18 ( V_25 ) ;
if ( V_7 < 0 )
goto V_42;
V_7 = F_19 ( V_25 ) ;
if ( V_7 < 0 )
goto V_42;
break;
default:
F_11 ( & V_2 -> V_3 -> V_13 , L_8 , V_31 ,
V_25 -> V_32 . V_33 ) ;
V_7 = - V_45 ;
break;
}
V_42:
return V_7 ;
}
static int F_20 ( struct V_24 * V_25 , T_4 * V_46 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
switch ( V_25 -> V_32 . V_33 ) {
case V_41 :
V_7 = F_21 ( V_25 , V_46 ) ;
break;
case V_43 :
V_7 = F_22 ( V_25 , V_46 ) ;
break;
case V_44 :
V_7 = F_23 ( V_25 , V_46 ) ;
break;
default:
V_7 = - V_45 ;
break;
}
return V_7 ;
}
static int F_24 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
if ( V_2 -> V_33 == V_47 )
return 0 ;
switch ( V_25 -> V_32 . V_33 ) {
case V_41 :
V_7 = F_25 ( V_25 ) ;
break;
case V_43 :
V_7 = F_26 ( V_25 ) ;
break;
case V_44 :
V_7 = F_27 ( V_25 ) ;
break;
default:
V_7 = - V_45 ;
break;
}
return V_7 ;
}
static int F_28 ( struct V_24 * V_25 , T_2 * V_48 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
switch ( V_25 -> V_32 . V_33 ) {
case V_41 :
V_7 = F_29 ( V_25 , V_48 ) ;
break;
case V_43 :
V_7 = F_30 ( V_25 , V_48 ) ;
break;
case V_44 :
V_7 = F_31 ( V_25 , V_48 ) ;
break;
default:
V_7 = - V_45 ;
break;
}
return V_7 ;
}
static int F_32 ( struct V_24 * V_25 , T_5 * V_49 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
switch ( V_25 -> V_32 . V_33 ) {
case V_41 :
V_7 = F_33 ( V_25 , V_49 ) ;
break;
case V_43 :
V_7 = F_34 ( V_25 , V_49 ) ;
break;
case V_44 :
V_7 = F_35 ( V_25 , V_49 ) ;
break;
default:
V_7 = - V_45 ;
break;
}
return V_7 ;
}
static int F_36 ( struct V_24 * V_25 , T_5 * V_50 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
switch ( V_25 -> V_32 . V_33 ) {
case V_41 :
V_7 = F_37 ( V_25 , V_50 ) ;
break;
case V_43 :
V_7 = F_38 ( V_25 , V_50 ) ;
break;
case V_44 :
V_7 = F_39 ( V_25 , V_50 ) ;
break;
default:
V_7 = - V_45 ;
break;
}
return V_7 ;
}
static int F_40 ( struct V_24 * V_25 , T_2 * V_51 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
switch ( V_25 -> V_32 . V_33 ) {
case V_41 :
V_7 = F_41 ( V_25 , V_51 ) ;
break;
case V_43 :
V_7 = F_42 ( V_25 , V_51 ) ;
break;
case V_44 :
V_7 = F_43 ( V_25 , V_51 ) ;
break;
default:
V_7 = - V_45 ;
break;
}
return V_7 ;
}
static int F_44 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_45 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
switch ( V_25 -> V_32 . V_33 ) {
case V_41 :
V_7 = F_46 ( V_25 ) ;
break;
case V_43 :
V_7 = F_47 ( V_25 ) ;
break;
case V_44 :
V_7 = F_48 ( V_25 ) ;
break;
default:
V_7 = - V_45 ;
break;
}
return V_7 ;
}
static int F_49 ( struct V_24 * V_25 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
switch ( V_25 -> V_32 . V_33 ) {
case V_41 :
V_7 = F_50 ( V_25 , V_53 ) ;
break;
case V_43 :
V_7 = F_51 ( V_25 , V_53 ) ;
break;
case V_44 :
V_7 = F_52 ( V_25 , V_53 ) ;
break;
default:
V_7 = - V_45 ;
break;
}
return V_7 ;
}
static enum V_54 F_53 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
struct V_39 * V_40 = & V_25 -> V_32 ;
int V_7 , V_28 ;
T_4 V_46 = 0 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_4 , V_31 ,
V_25 -> V_32 . V_33 ) ;
if ( V_2 -> V_55 ) {
if ( V_2 -> V_33 == V_41 ) {
V_7 = F_46 ( V_25 ) ;
if ( V_7 )
goto error;
V_40 -> V_33 = V_43 ;
} else if ( V_2 -> V_33 == V_43 ) {
V_7 = F_47 ( V_25 ) ;
if ( V_7 )
goto error;
V_40 -> V_33 = V_41 ;
}
}
V_7 = F_14 ( V_25 ) ;
if ( V_7 )
goto error;
switch ( V_2 -> V_33 ) {
case V_41 :
case V_44 :
V_28 = 20 ;
break;
case V_43 :
V_28 = 40 ;
break;
case V_47 :
default:
V_28 = 0 ;
break;
}
for (; V_28 > 0 ; V_28 -- ) {
F_11 ( & V_2 -> V_3 -> V_13 , L_9 , V_31 , V_28 ) ;
F_54 ( 50 ) ;
V_7 = F_20 ( V_25 , & V_46 ) ;
if ( V_7 )
goto error;
if ( V_46 & V_56 )
break;
}
if ( V_46 & V_56 ) {
V_2 -> V_55 = 0 ;
return V_57 ;
} else {
V_2 -> V_55 = 1 ;
return V_58 ;
}
error:
F_11 ( & V_2 -> V_3 -> V_13 , L_7 , V_31 , V_7 ) ;
return V_59 ;
}
static int F_55 ( struct V_24 * V_25 )
{
return V_60 ;
}
static void F_56 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
int V_61 ( V_7 ) ;
F_11 ( & V_2 -> V_3 -> V_13 , L_10 , V_31 ) ;
#ifdef F_57
if ( V_2 -> V_62 . V_63 ) {
V_7 = F_58 ( & V_2 -> V_62 ) ;
if ( V_7 )
F_59 ( & V_2 -> V_3 -> V_13 , L_11 \
L_12 , V_14 , V_7 ) ;
}
#endif
F_60 ( V_2 ) ;
return;
}
static int F_61 ( struct V_24 * V_25 , int V_64 )
{
struct V_1 * V_2 = V_25 -> V_27 ;
F_11 ( & V_2 -> V_3 -> V_13 , L_13 , V_31 , V_64 ) ;
return F_9 ( V_2 , 0xdb , V_64 ? 1 : 0 , 0x1 ) ;
}
static int F_62 ( struct V_62 * V_65 , unsigned V_66 ,
int V_5 )
{
struct V_1 * V_2 =
F_63 ( V_65 , struct V_1 , V_62 ) ;
T_1 V_26 [ V_67 ] ;
F_11 ( & V_2 -> V_3 -> V_13 , L_14 , V_31 , V_66 , V_5 ) ;
memcpy ( V_26 , V_2 -> V_26 , sizeof( V_26 ) ) ;
V_26 [ V_66 ] = V_34 | V_68 | ( V_5 << 2 ) ;
return F_10 ( & V_2 -> V_25 , V_26 ) ;
}
static void F_64 ( struct V_62 * V_65 , unsigned V_66 , int V_5 )
{
struct V_1 * V_2 =
F_63 ( V_65 , struct V_1 , V_62 ) ;
T_1 V_26 [ V_67 ] ;
F_11 ( & V_2 -> V_3 -> V_13 , L_14 , V_31 , V_66 , V_5 ) ;
memcpy ( V_26 , V_2 -> V_26 , sizeof( V_26 ) ) ;
V_26 [ V_66 ] = V_34 | V_68 | ( V_5 << 2 ) ;
( void ) F_10 ( & V_2 -> V_25 , V_26 ) ;
return;
}
static int F_65 ( struct V_62 * V_65 , unsigned V_66 )
{
struct V_1 * V_2 =
F_63 ( V_65 , struct V_1 , V_62 ) ;
F_11 ( & V_2 -> V_3 -> V_13 , L_15 , V_31 , V_66 ) ;
return ( V_2 -> V_26 [ V_66 ] >> 2 ) & 0x01 ;
}
struct V_24 * F_66 ( const struct V_69 * V_20 ,
struct V_70 * V_3 , int * V_71
)
{
struct V_1 * V_2 ;
int V_7 ;
T_1 V_23 ;
V_2 = F_67 ( sizeof( struct V_1 ) , V_72 ) ;
if ( ! V_2 ) {
V_7 = - V_73 ;
F_59 ( & V_3 -> V_13 , L_16 ,
V_14 ) ;
goto error;
}
V_2 -> V_3 = V_3 ;
memcpy ( & V_2 -> V_20 , V_20 , sizeof( struct V_69 ) ) ;
memcpy ( & V_2 -> V_25 . V_74 , & V_75 , sizeof( struct V_76 ) ) ;
V_2 -> V_25 . V_27 = V_2 ;
V_2 -> V_19 [ 0 ] = V_2 -> V_19 [ 1 ] = 0xff ;
V_7 = F_8 ( V_2 , 0x000fd , & V_23 ) ;
F_11 ( & V_2 -> V_3 -> V_13 , L_17 , V_31 , V_23 ) ;
if ( V_7 || V_23 != 0xe1 )
goto error;
if ( V_71 ) {
#ifdef F_57
V_2 -> V_62 . V_63 = V_14 ;
V_2 -> V_62 . V_13 = & V_2 -> V_3 -> V_13 ;
V_2 -> V_62 . V_77 = V_78 ;
V_2 -> V_62 . V_79 =
F_62 ;
V_2 -> V_62 . V_80 = F_64 ;
V_2 -> V_62 . V_81 = F_65 ;
V_2 -> V_62 . V_82 = - 1 ;
V_2 -> V_62 . V_83 = V_67 ;
V_2 -> V_62 . V_84 = 1 ;
V_7 = F_68 ( & V_2 -> V_62 ) ;
if ( V_7 )
goto error;
F_11 ( & V_2 -> V_3 -> V_13 , L_18 , V_31 ,
V_2 -> V_62 . V_82 ) ;
* V_71 = V_2 -> V_62 . V_82 ;
#else
T_1 V_26 [ V_67 ] ;
V_26 [ 0 ] = ( * V_71 >> 0 ) & 0x07 ;
V_26 [ 1 ] = ( * V_71 >> 3 ) & 0x07 ;
V_26 [ 2 ] = 0 ;
V_7 = F_10 ( & V_2 -> V_25 , V_26 ) ;
if ( V_7 )
goto error;
#endif
}
return & V_2 -> V_25 ;
error:
F_11 ( & V_3 -> V_13 , L_7 , V_31 , V_7 ) ;
F_60 ( V_2 ) ;
return NULL ;
}
