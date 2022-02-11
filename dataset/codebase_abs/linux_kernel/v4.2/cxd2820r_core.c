static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_8 [ V_9 ] ;
struct V_10 V_11 [ 1 ] = {
{
. V_12 = V_3 ,
. V_13 = 0 ,
. V_6 = V_6 + 1 ,
. V_8 = V_8 ,
}
} ;
if ( 1 + V_6 > sizeof( V_8 ) ) {
F_2 ( & V_2 -> V_3 -> V_14 ,
L_1 ,
V_15 , V_4 , V_6 ) ;
return - V_16 ;
}
V_8 [ 0 ] = V_4 ;
memcpy ( & V_8 [ 1 ] , V_5 , V_6 ) ;
V_7 = F_3 ( V_2 -> V_3 , V_11 , 1 ) ;
if ( V_7 == 1 ) {
V_7 = 0 ;
} else {
F_2 ( & V_2 -> V_3 -> V_14 , L_2 \
L_3 , V_15 , V_7 , V_4 , V_6 ) ;
V_7 = - V_17 ;
}
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 * V_5 , int V_6 )
{
int V_7 ;
T_1 V_8 [ V_9 ] ;
struct V_10 V_11 [ 2 ] = {
{
. V_12 = V_3 ,
. V_13 = 0 ,
. V_6 = 1 ,
. V_8 = & V_4 ,
} , {
. V_12 = V_3 ,
. V_13 = V_18 ,
. V_6 = V_6 ,
. V_8 = V_8 ,
}
} ;
if ( V_6 > sizeof( V_8 ) ) {
F_2 ( & V_2 -> V_3 -> V_14 ,
L_1 ,
V_15 , V_4 , V_6 ) ;
return - V_16 ;
}
V_7 = F_3 ( V_2 -> V_3 , V_11 , 2 ) ;
if ( V_7 == 2 ) {
memcpy ( V_5 , V_8 , V_6 ) ;
V_7 = 0 ;
} else {
F_2 ( & V_2 -> V_3 -> V_14 , L_4 \
L_3 , V_15 , V_7 , V_4 , V_6 ) ;
V_7 = - V_17 ;
}
return V_7 ;
}
int F_5 ( struct V_1 * V_2 , T_2 V_19 , T_1 * V_5 ,
int V_6 )
{
int V_7 ;
T_1 V_20 ;
T_1 V_4 = ( V_19 >> 0 ) & 0xff ;
T_1 V_21 = ( V_19 >> 8 ) & 0xff ;
T_1 V_3 = ( V_19 >> 16 ) & 0x01 ;
if ( V_3 )
V_20 = V_2 -> V_22 . V_23 | ( 1 << 1 ) ;
else
V_20 = V_2 -> V_22 . V_23 ;
if ( V_21 != V_2 -> V_21 [ V_3 ] ) {
V_7 = F_1 ( V_2 , V_20 , 0x00 , & V_21 , 1 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_21 [ V_3 ] = V_21 ;
}
return F_1 ( V_2 , V_20 , V_4 , V_5 , V_6 ) ;
}
int F_6 ( struct V_1 * V_2 , T_2 V_19 , T_1 * V_5 ,
int V_6 )
{
int V_7 ;
T_1 V_20 ;
T_1 V_4 = ( V_19 >> 0 ) & 0xff ;
T_1 V_21 = ( V_19 >> 8 ) & 0xff ;
T_1 V_3 = ( V_19 >> 16 ) & 0x01 ;
if ( V_3 )
V_20 = V_2 -> V_22 . V_23 | ( 1 << 1 ) ;
else
V_20 = V_2 -> V_22 . V_23 ;
if ( V_21 != V_2 -> V_21 [ V_3 ] ) {
V_7 = F_1 ( V_2 , V_20 , 0x00 , & V_21 , 1 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_21 [ V_3 ] = V_21 ;
}
return F_4 ( V_2 , V_20 , V_4 , V_5 , V_6 ) ;
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
T_1 V_24 )
{
int V_7 ;
T_1 V_25 ;
if ( V_24 != 0xff ) {
V_7 = F_8 ( V_2 , V_4 , & V_25 ) ;
if ( V_7 )
return V_7 ;
V_5 &= V_24 ;
V_25 &= ~ V_24 ;
V_5 |= V_25 ;
}
return F_7 ( V_2 , V_4 , V_5 ) ;
}
int F_10 ( struct V_26 * V_27 , T_1 * V_28 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 , V_30 ;
T_1 V_31 , V_32 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
if ( ! memcmp ( V_28 , V_2 -> V_28 , sizeof( V_2 -> V_28 ) ) )
return 0 ;
V_31 = 0x00 ;
V_32 = 0x00 ;
for ( V_30 = 0 ; V_30 < sizeof( V_2 -> V_28 ) ; V_30 ++ ) {
if ( V_28 [ V_30 ] & V_36 )
V_31 |= ( 2 << 6 ) >> ( 2 * V_30 ) ;
else
V_31 |= ( 1 << 6 ) >> ( 2 * V_30 ) ;
if ( V_28 [ V_30 ] & V_37 )
V_32 |= ( 1 << ( 3 + V_30 ) ) ;
else
V_32 |= ( 0 << ( 3 + V_30 ) ) ;
if ( V_28 [ V_30 ] & V_38 )
V_32 |= ( 1 << ( 0 + V_30 ) ) ;
else
V_32 |= ( 0 << ( 0 + V_30 ) ) ;
F_11 ( & V_2 -> V_3 -> V_14 , L_6 , V_33 ,
V_30 , V_31 , V_32 ) ;
}
F_11 ( & V_2 -> V_3 -> V_14 , L_7 , V_33 , V_31 ,
V_32 ) ;
V_7 = F_9 ( V_2 , 0x00089 , V_31 , 0xfc ) ;
if ( V_7 )
goto error;
V_7 = F_9 ( V_2 , 0x0008e , V_32 , 0x3f ) ;
if ( V_7 )
goto error;
memcpy ( V_2 -> V_28 , V_28 , sizeof( V_2 -> V_28 ) ) ;
return V_7 ;
error:
F_11 ( & V_2 -> V_3 -> V_14 , L_8 , V_33 , V_7 ) ;
return V_7 ;
}
static int F_12 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_39 * V_40 = & V_27 -> V_34 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_40 -> V_35 ) {
case V_41 :
V_7 = F_13 ( V_27 ) ;
if ( V_7 < 0 )
goto V_42;
V_7 = F_14 ( V_27 ) ;
if ( V_7 < 0 )
goto V_42;
break;
case V_43 :
V_7 = F_13 ( V_27 ) ;
if ( V_7 < 0 )
goto V_42;
V_7 = F_15 ( V_27 ) ;
if ( V_7 < 0 )
goto V_42;
break;
case V_44 :
V_7 = F_16 ( V_27 ) ;
if ( V_7 < 0 )
goto V_42;
V_7 = F_17 ( V_27 ) ;
if ( V_7 < 0 )
goto V_42;
break;
default:
F_11 ( & V_2 -> V_3 -> V_14 , L_9 , V_33 ,
V_27 -> V_34 . V_35 ) ;
V_7 = - V_16 ;
break;
}
V_42:
return V_7 ;
}
static int F_18 ( struct V_26 * V_27 , enum V_45 * V_46 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_41 :
V_7 = F_19 ( V_27 , V_46 ) ;
break;
case V_43 :
V_7 = F_20 ( V_27 , V_46 ) ;
break;
case V_44 :
V_7 = F_21 ( V_27 , V_46 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_22 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
if ( V_2 -> V_35 == V_47 )
return 0 ;
switch ( V_27 -> V_34 . V_35 ) {
case V_41 :
V_7 = F_23 ( V_27 ) ;
break;
case V_43 :
V_7 = F_24 ( V_27 ) ;
break;
case V_44 :
V_7 = F_25 ( V_27 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_26 ( struct V_26 * V_27 , T_2 * V_48 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_41 :
V_7 = F_27 ( V_27 , V_48 ) ;
break;
case V_43 :
V_7 = F_28 ( V_27 , V_48 ) ;
break;
case V_44 :
V_7 = F_29 ( V_27 , V_48 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_30 ( struct V_26 * V_27 , T_3 * V_49 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_41 :
V_7 = F_31 ( V_27 , V_49 ) ;
break;
case V_43 :
V_7 = F_32 ( V_27 , V_49 ) ;
break;
case V_44 :
V_7 = F_33 ( V_27 , V_49 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_34 ( struct V_26 * V_27 , T_3 * V_50 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_41 :
V_7 = F_35 ( V_27 , V_50 ) ;
break;
case V_43 :
V_7 = F_36 ( V_27 , V_50 ) ;
break;
case V_44 :
V_7 = F_37 ( V_27 , V_50 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_38 ( struct V_26 * V_27 , T_2 * V_51 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_41 :
V_7 = F_39 ( V_27 , V_51 ) ;
break;
case V_43 :
V_7 = F_40 ( V_27 , V_51 ) ;
break;
case V_44 :
V_7 = F_41 ( V_27 , V_51 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_42 ( struct V_26 * V_27 )
{
return 0 ;
}
static int F_43 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_41 :
V_7 = F_44 ( V_27 ) ;
break;
case V_43 :
V_7 = F_45 ( V_27 ) ;
break;
case V_44 :
V_7 = F_46 ( V_27 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_47 ( struct V_26 * V_27 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_41 :
V_7 = F_48 ( V_27 , V_53 ) ;
break;
case V_43 :
V_7 = F_49 ( V_27 , V_53 ) ;
break;
case V_44 :
V_7 = F_50 ( V_27 , V_53 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static enum V_54 F_51 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_39 * V_40 = & V_27 -> V_34 ;
int V_7 , V_30 ;
enum V_45 V_46 = 0 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
if ( V_2 -> V_55 ) {
if ( V_2 -> V_35 == V_41 ) {
V_7 = F_44 ( V_27 ) ;
if ( V_7 )
goto error;
V_40 -> V_35 = V_43 ;
} else if ( V_2 -> V_35 == V_43 ) {
V_7 = F_45 ( V_27 ) ;
if ( V_7 )
goto error;
V_40 -> V_35 = V_41 ;
}
}
V_7 = F_12 ( V_27 ) ;
if ( V_7 )
goto error;
switch ( V_2 -> V_35 ) {
case V_41 :
case V_44 :
V_30 = 20 ;
break;
case V_43 :
V_30 = 40 ;
break;
case V_47 :
default:
V_30 = 0 ;
break;
}
for (; V_30 > 0 ; V_30 -- ) {
F_11 ( & V_2 -> V_3 -> V_14 , L_10 , V_33 , V_30 ) ;
F_52 ( 50 ) ;
V_7 = F_18 ( V_27 , & V_46 ) ;
if ( V_7 )
goto error;
if ( V_46 & V_56 )
break;
}
if ( V_46 & V_56 ) {
V_2 -> V_55 = false ;
return V_57 ;
} else {
V_2 -> V_55 = true ;
return V_58 ;
}
error:
F_11 ( & V_2 -> V_3 -> V_14 , L_8 , V_33 , V_7 ) ;
return V_59 ;
}
static int F_53 ( struct V_26 * V_27 )
{
return V_60 ;
}
static void F_54 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_11 , V_33 ) ;
#ifdef F_55
if ( V_2 -> V_61 . V_62 )
F_56 ( & V_2 -> V_61 ) ;
#endif
F_57 ( V_2 ) ;
return;
}
static int F_58 ( struct V_26 * V_27 , int V_63 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_12 , V_33 , V_63 ) ;
return F_9 ( V_2 , 0xdb , V_63 ? 1 : 0 , 0x1 ) ;
}
static int F_59 ( struct V_61 * V_64 , unsigned V_65 ,
int V_5 )
{
struct V_1 * V_2 =
F_60 ( V_64 , struct V_1 , V_61 ) ;
T_1 V_28 [ V_66 ] ;
F_11 ( & V_2 -> V_3 -> V_14 , L_13 , V_33 , V_65 , V_5 ) ;
memcpy ( V_28 , V_2 -> V_28 , sizeof( V_28 ) ) ;
V_28 [ V_65 ] = V_36 | V_67 | ( V_5 << 2 ) ;
return F_10 ( & V_2 -> V_27 , V_28 ) ;
}
static void F_61 ( struct V_61 * V_64 , unsigned V_65 , int V_5 )
{
struct V_1 * V_2 =
F_60 ( V_64 , struct V_1 , V_61 ) ;
T_1 V_28 [ V_66 ] ;
F_11 ( & V_2 -> V_3 -> V_14 , L_13 , V_33 , V_65 , V_5 ) ;
memcpy ( V_28 , V_2 -> V_28 , sizeof( V_28 ) ) ;
V_28 [ V_65 ] = V_36 | V_67 | ( V_5 << 2 ) ;
( void ) F_10 ( & V_2 -> V_27 , V_28 ) ;
return;
}
static int F_62 ( struct V_61 * V_64 , unsigned V_65 )
{
struct V_1 * V_2 =
F_60 ( V_64 , struct V_1 , V_61 ) ;
F_11 ( & V_2 -> V_3 -> V_14 , L_14 , V_33 , V_65 ) ;
return ( V_2 -> V_28 [ V_65 ] >> 2 ) & 0x01 ;
}
struct V_26 * F_63 ( const struct V_68 * V_22 ,
struct V_69 * V_3 , int * V_70
)
{
struct V_1 * V_2 ;
int V_7 ;
T_1 V_25 ;
V_2 = F_64 ( sizeof( struct V_1 ) , V_71 ) ;
if ( ! V_2 ) {
V_7 = - V_72 ;
F_65 ( & V_3 -> V_14 , L_15 ,
V_15 ) ;
goto error;
}
V_2 -> V_3 = V_3 ;
memcpy ( & V_2 -> V_22 , V_22 , sizeof( struct V_68 ) ) ;
memcpy ( & V_2 -> V_27 . V_73 , & V_74 , sizeof( struct V_75 ) ) ;
V_2 -> V_27 . V_29 = V_2 ;
V_2 -> V_21 [ 0 ] = V_2 -> V_21 [ 1 ] = 0xff ;
V_7 = F_8 ( V_2 , 0x000fd , & V_25 ) ;
F_11 ( & V_2 -> V_3 -> V_14 , L_16 , V_33 , V_25 ) ;
if ( V_7 || V_25 != 0xe1 )
goto error;
if ( V_70 ) {
#ifdef F_55
V_2 -> V_61 . V_62 = V_15 ;
V_2 -> V_61 . V_14 = & V_2 -> V_3 -> V_14 ;
V_2 -> V_61 . V_76 = V_77 ;
V_2 -> V_61 . V_78 =
F_59 ;
V_2 -> V_61 . V_79 = F_61 ;
V_2 -> V_61 . V_80 = F_62 ;
V_2 -> V_61 . V_81 = - 1 ;
V_2 -> V_61 . V_82 = V_66 ;
V_2 -> V_61 . V_83 = 1 ;
V_7 = F_66 ( & V_2 -> V_61 ) ;
if ( V_7 )
goto error;
F_11 ( & V_2 -> V_3 -> V_14 , L_17 , V_33 ,
V_2 -> V_61 . V_81 ) ;
* V_70 = V_2 -> V_61 . V_81 ;
#else
T_1 V_28 [ V_66 ] ;
V_28 [ 0 ] = ( * V_70 >> 0 ) & 0x07 ;
V_28 [ 1 ] = ( * V_70 >> 3 ) & 0x07 ;
V_28 [ 2 ] = 0 ;
V_7 = F_10 ( & V_2 -> V_27 , V_28 ) ;
if ( V_7 )
goto error;
#endif
}
return & V_2 -> V_27 ;
error:
F_11 ( & V_3 -> V_14 , L_8 , V_33 , V_7 ) ;
F_57 ( V_2 ) ;
return NULL ;
}
