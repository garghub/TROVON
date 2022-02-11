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
T_2 F_12 ( T_3 V_39 , T_2 V_40 )
{
return F_13 ( V_39 + ( V_40 / 2 ) , V_40 ) ;
}
static int F_14 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_41 * V_42 = & V_27 -> V_34 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_42 -> V_35 ) {
case V_43 :
V_7 = F_15 ( V_27 ) ;
if ( V_7 < 0 )
goto V_44;
V_7 = F_16 ( V_27 ) ;
if ( V_7 < 0 )
goto V_44;
break;
case V_45 :
V_7 = F_15 ( V_27 ) ;
if ( V_7 < 0 )
goto V_44;
V_7 = F_17 ( V_27 ) ;
if ( V_7 < 0 )
goto V_44;
break;
case V_46 :
V_7 = F_18 ( V_27 ) ;
if ( V_7 < 0 )
goto V_44;
V_7 = F_19 ( V_27 ) ;
if ( V_7 < 0 )
goto V_44;
break;
default:
F_11 ( & V_2 -> V_3 -> V_14 , L_9 , V_33 ,
V_27 -> V_34 . V_35 ) ;
V_7 = - V_16 ;
break;
}
V_44:
return V_7 ;
}
static int F_20 ( struct V_26 * V_27 , T_4 * V_47 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_43 :
V_7 = F_21 ( V_27 , V_47 ) ;
break;
case V_45 :
V_7 = F_22 ( V_27 , V_47 ) ;
break;
case V_46 :
V_7 = F_23 ( V_27 , V_47 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_24 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
if ( V_2 -> V_35 == V_48 )
return 0 ;
switch ( V_27 -> V_34 . V_35 ) {
case V_43 :
V_7 = F_25 ( V_27 ) ;
break;
case V_45 :
V_7 = F_26 ( V_27 ) ;
break;
case V_46 :
V_7 = F_27 ( V_27 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_28 ( struct V_26 * V_27 , T_2 * V_49 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_43 :
V_7 = F_29 ( V_27 , V_49 ) ;
break;
case V_45 :
V_7 = F_30 ( V_27 , V_49 ) ;
break;
case V_46 :
V_7 = F_31 ( V_27 , V_49 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_32 ( struct V_26 * V_27 , T_5 * V_50 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_43 :
V_7 = F_33 ( V_27 , V_50 ) ;
break;
case V_45 :
V_7 = F_34 ( V_27 , V_50 ) ;
break;
case V_46 :
V_7 = F_35 ( V_27 , V_50 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_36 ( struct V_26 * V_27 , T_5 * V_51 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_43 :
V_7 = F_37 ( V_27 , V_51 ) ;
break;
case V_45 :
V_7 = F_38 ( V_27 , V_51 ) ;
break;
case V_46 :
V_7 = F_39 ( V_27 , V_51 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_40 ( struct V_26 * V_27 , T_2 * V_52 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_43 :
V_7 = F_41 ( V_27 , V_52 ) ;
break;
case V_45 :
V_7 = F_42 ( V_27 , V_52 ) ;
break;
case V_46 :
V_7 = F_43 ( V_27 , V_52 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_44 ( struct V_26 * V_27 )
{
return 0 ;
}
static int F_45 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_43 :
V_7 = F_46 ( V_27 ) ;
break;
case V_45 :
V_7 = F_47 ( V_27 ) ;
break;
case V_46 :
V_7 = F_48 ( V_27 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static int F_49 ( struct V_26 * V_27 ,
struct V_53 * V_54 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_7 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
switch ( V_27 -> V_34 . V_35 ) {
case V_43 :
V_7 = F_50 ( V_27 , V_54 ) ;
break;
case V_45 :
V_7 = F_51 ( V_27 , V_54 ) ;
break;
case V_46 :
V_7 = F_52 ( V_27 , V_54 ) ;
break;
default:
V_7 = - V_16 ;
break;
}
return V_7 ;
}
static enum V_55 F_53 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
struct V_41 * V_42 = & V_27 -> V_34 ;
int V_7 , V_30 ;
T_4 V_47 = 0 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_5 , V_33 ,
V_27 -> V_34 . V_35 ) ;
if ( V_2 -> V_56 ) {
if ( V_2 -> V_35 == V_43 ) {
V_7 = F_46 ( V_27 ) ;
if ( V_7 )
goto error;
V_42 -> V_35 = V_45 ;
} else if ( V_2 -> V_35 == V_45 ) {
V_7 = F_47 ( V_27 ) ;
if ( V_7 )
goto error;
V_42 -> V_35 = V_43 ;
}
}
V_7 = F_14 ( V_27 ) ;
if ( V_7 )
goto error;
switch ( V_2 -> V_35 ) {
case V_43 :
case V_46 :
V_30 = 20 ;
break;
case V_45 :
V_30 = 40 ;
break;
case V_48 :
default:
V_30 = 0 ;
break;
}
for (; V_30 > 0 ; V_30 -- ) {
F_11 ( & V_2 -> V_3 -> V_14 , L_10 , V_33 , V_30 ) ;
F_54 ( 50 ) ;
V_7 = F_20 ( V_27 , & V_47 ) ;
if ( V_7 )
goto error;
if ( V_47 & V_57 )
break;
}
if ( V_47 & V_57 ) {
V_2 -> V_56 = 0 ;
return V_58 ;
} else {
V_2 -> V_56 = 1 ;
return V_59 ;
}
error:
F_11 ( & V_2 -> V_3 -> V_14 , L_8 , V_33 , V_7 ) ;
return V_60 ;
}
static int F_55 ( struct V_26 * V_27 )
{
return V_61 ;
}
static void F_56 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
int V_62 ( V_7 ) ;
F_11 ( & V_2 -> V_3 -> V_14 , L_11 , V_33 ) ;
#ifdef F_57
if ( V_2 -> V_63 . V_64 ) {
V_7 = F_58 ( & V_2 -> V_63 ) ;
if ( V_7 )
F_59 ( & V_2 -> V_3 -> V_14 , L_12 \
L_13 , V_15 , V_7 ) ;
}
#endif
F_60 ( V_2 ) ;
return;
}
static int F_61 ( struct V_26 * V_27 , int V_65 )
{
struct V_1 * V_2 = V_27 -> V_29 ;
F_11 ( & V_2 -> V_3 -> V_14 , L_14 , V_33 , V_65 ) ;
return F_9 ( V_2 , 0xdb , V_65 ? 1 : 0 , 0x1 ) ;
}
static int F_62 ( struct V_63 * V_66 , unsigned V_67 ,
int V_5 )
{
struct V_1 * V_2 =
F_63 ( V_66 , struct V_1 , V_63 ) ;
T_1 V_28 [ V_68 ] ;
F_11 ( & V_2 -> V_3 -> V_14 , L_15 , V_33 , V_67 , V_5 ) ;
memcpy ( V_28 , V_2 -> V_28 , sizeof( V_28 ) ) ;
V_28 [ V_67 ] = V_36 | V_69 | ( V_5 << 2 ) ;
return F_10 ( & V_2 -> V_27 , V_28 ) ;
}
static void F_64 ( struct V_63 * V_66 , unsigned V_67 , int V_5 )
{
struct V_1 * V_2 =
F_63 ( V_66 , struct V_1 , V_63 ) ;
T_1 V_28 [ V_68 ] ;
F_11 ( & V_2 -> V_3 -> V_14 , L_15 , V_33 , V_67 , V_5 ) ;
memcpy ( V_28 , V_2 -> V_28 , sizeof( V_28 ) ) ;
V_28 [ V_67 ] = V_36 | V_69 | ( V_5 << 2 ) ;
( void ) F_10 ( & V_2 -> V_27 , V_28 ) ;
return;
}
static int F_65 ( struct V_63 * V_66 , unsigned V_67 )
{
struct V_1 * V_2 =
F_63 ( V_66 , struct V_1 , V_63 ) ;
F_11 ( & V_2 -> V_3 -> V_14 , L_16 , V_33 , V_67 ) ;
return ( V_2 -> V_28 [ V_67 ] >> 2 ) & 0x01 ;
}
struct V_26 * F_66 ( const struct V_70 * V_22 ,
struct V_71 * V_3 , int * V_72
)
{
struct V_1 * V_2 ;
int V_7 ;
T_1 V_25 ;
V_2 = F_67 ( sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 ) {
V_7 = - V_74 ;
F_59 ( & V_3 -> V_14 , L_17 ,
V_15 ) ;
goto error;
}
V_2 -> V_3 = V_3 ;
memcpy ( & V_2 -> V_22 , V_22 , sizeof( struct V_70 ) ) ;
memcpy ( & V_2 -> V_27 . V_75 , & V_76 , sizeof( struct V_77 ) ) ;
V_2 -> V_27 . V_29 = V_2 ;
V_2 -> V_21 [ 0 ] = V_2 -> V_21 [ 1 ] = 0xff ;
V_7 = F_8 ( V_2 , 0x000fd , & V_25 ) ;
F_11 ( & V_2 -> V_3 -> V_14 , L_18 , V_33 , V_25 ) ;
if ( V_7 || V_25 != 0xe1 )
goto error;
if ( V_72 ) {
#ifdef F_57
V_2 -> V_63 . V_64 = V_15 ;
V_2 -> V_63 . V_14 = & V_2 -> V_3 -> V_14 ;
V_2 -> V_63 . V_78 = V_79 ;
V_2 -> V_63 . V_80 =
F_62 ;
V_2 -> V_63 . V_81 = F_64 ;
V_2 -> V_63 . V_82 = F_65 ;
V_2 -> V_63 . V_83 = - 1 ;
V_2 -> V_63 . V_84 = V_68 ;
V_2 -> V_63 . V_85 = 1 ;
V_7 = F_68 ( & V_2 -> V_63 ) ;
if ( V_7 )
goto error;
F_11 ( & V_2 -> V_3 -> V_14 , L_19 , V_33 ,
V_2 -> V_63 . V_83 ) ;
* V_72 = V_2 -> V_63 . V_83 ;
#else
T_1 V_28 [ V_68 ] ;
V_28 [ 0 ] = ( * V_72 >> 0 ) & 0x07 ;
V_28 [ 1 ] = ( * V_72 >> 3 ) & 0x07 ;
V_28 [ 2 ] = 0 ;
V_7 = F_10 ( & V_2 -> V_27 , V_28 ) ;
if ( V_7 )
goto error;
#endif
}
return & V_2 -> V_27 ;
error:
F_11 ( & V_3 -> V_14 , L_8 , V_33 , V_7 ) ;
F_60 ( V_2 ) ;
return NULL ;
}
