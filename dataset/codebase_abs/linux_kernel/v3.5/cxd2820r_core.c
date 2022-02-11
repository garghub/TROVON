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
F_3 ( L_1 , V_7 , V_4 , V_6 ) ;
V_7 = - V_13 ;
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
. V_12 = V_14 ,
. V_6 = sizeof( V_8 ) ,
. V_8 = V_8 ,
}
} ;
V_7 = F_2 ( V_2 -> V_3 , V_10 , 2 ) ;
if ( V_7 == 2 ) {
memcpy ( V_5 , V_8 , V_6 ) ;
V_7 = 0 ;
} else {
F_3 ( L_2 , V_7 , V_4 , V_6 ) ;
V_7 = - V_13 ;
}
return V_7 ;
}
int F_5 ( struct V_1 * V_2 , T_2 V_15 , T_1 * V_5 ,
int V_6 )
{
int V_7 ;
T_1 V_16 ;
T_1 V_4 = ( V_15 >> 0 ) & 0xff ;
T_1 V_17 = ( V_15 >> 8 ) & 0xff ;
T_1 V_3 = ( V_15 >> 16 ) & 0x01 ;
if ( V_3 )
V_16 = V_2 -> V_18 . V_19 | ( 1 << 1 ) ;
else
V_16 = V_2 -> V_18 . V_19 ;
if ( V_17 != V_2 -> V_17 [ V_3 ] ) {
V_7 = F_1 ( V_2 , V_16 , 0x00 , & V_17 , 1 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_17 [ V_3 ] = V_17 ;
}
return F_1 ( V_2 , V_16 , V_4 , V_5 , V_6 ) ;
}
int F_6 ( struct V_1 * V_2 , T_2 V_15 , T_1 * V_5 ,
int V_6 )
{
int V_7 ;
T_1 V_16 ;
T_1 V_4 = ( V_15 >> 0 ) & 0xff ;
T_1 V_17 = ( V_15 >> 8 ) & 0xff ;
T_1 V_3 = ( V_15 >> 16 ) & 0x01 ;
if ( V_3 )
V_16 = V_2 -> V_18 . V_19 | ( 1 << 1 ) ;
else
V_16 = V_2 -> V_18 . V_19 ;
if ( V_17 != V_2 -> V_17 [ V_3 ] ) {
V_7 = F_1 ( V_2 , V_16 , 0x00 , & V_17 , 1 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_17 [ V_3 ] = V_17 ;
}
return F_4 ( V_2 , V_16 , V_4 , V_5 , V_6 ) ;
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
T_1 V_20 )
{
int V_7 ;
T_1 V_21 ;
if ( V_20 != 0xff ) {
V_7 = F_8 ( V_2 , V_4 , & V_21 ) ;
if ( V_7 )
return V_7 ;
V_5 &= V_20 ;
V_21 &= ~ V_20 ;
V_5 |= V_21 ;
}
return F_7 ( V_2 , V_4 , V_5 ) ;
}
int F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
int V_7 , V_25 ;
T_1 * V_26 , V_27 , V_28 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
switch ( V_23 -> V_30 . V_31 ) {
case V_32 :
V_26 = V_2 -> V_18 . V_33 ;
break;
case V_34 :
V_26 = V_2 -> V_18 . V_35 ;
break;
case V_36 :
V_26 = V_2 -> V_18 . V_37 ;
break;
default:
V_7 = - V_38 ;
goto error;
}
if ( ! memcmp ( V_26 , V_2 -> V_26 , sizeof( V_2 -> V_26 ) ) )
return 0 ;
V_27 = 0x00 ;
V_28 = 0x00 ;
for ( V_25 = 0 ; V_25 < sizeof( V_2 -> V_26 ) ; V_25 ++ ) {
if ( V_26 [ V_25 ] & V_39 )
V_27 |= ( 2 << 6 ) >> ( 2 * V_25 ) ;
else
V_27 |= ( 1 << 6 ) >> ( 2 * V_25 ) ;
if ( V_26 [ V_25 ] & V_40 )
V_28 |= ( 1 << ( 3 + V_25 ) ) ;
else
V_28 |= ( 0 << ( 3 + V_25 ) ) ;
if ( V_26 [ V_25 ] & V_41 )
V_28 |= ( 1 << ( 0 + V_25 ) ) ;
else
V_28 |= ( 0 << ( 0 + V_25 ) ) ;
F_11 ( L_4 , V_29 , V_25 , V_27 , V_28 ) ;
}
F_11 ( L_5 , V_29 , V_27 , V_28 ) ;
V_7 = F_9 ( V_2 , 0x00089 , V_27 , 0xfc ) ;
if ( V_7 )
goto error;
V_7 = F_9 ( V_2 , 0x0008e , V_28 , 0x3f ) ;
if ( V_7 )
goto error;
memcpy ( V_2 -> V_26 , V_26 , sizeof( V_2 -> V_26 ) ) ;
return V_7 ;
error:
F_11 ( L_6 , V_29 , V_7 ) ;
return V_7 ;
}
T_2 F_12 ( T_3 V_42 , T_2 V_43 )
{
return F_13 ( V_42 + ( V_43 / 2 ) , V_43 ) ;
}
static int F_14 ( struct V_22 * V_23 )
{
struct V_44 * V_45 = & V_23 -> V_30 ;
int V_7 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
switch ( V_45 -> V_31 ) {
case V_32 :
V_7 = F_15 ( V_23 ) ;
if ( V_7 < 0 )
goto V_46;
V_7 = F_16 ( V_23 ) ;
if ( V_7 < 0 )
goto V_46;
break;
case V_34 :
V_7 = F_15 ( V_23 ) ;
if ( V_7 < 0 )
goto V_46;
V_7 = F_17 ( V_23 ) ;
if ( V_7 < 0 )
goto V_46;
break;
case V_47 :
V_7 = F_18 ( V_23 ) ;
if ( V_7 < 0 )
goto V_46;
V_7 = F_19 ( V_23 ) ;
if ( V_7 < 0 )
goto V_46;
break;
default:
F_11 ( L_7 , V_29 , V_23 -> V_30 . V_31 ) ;
V_7 = - V_38 ;
break;
}
V_46:
return V_7 ;
}
static int F_20 ( struct V_22 * V_23 , T_4 * V_48 )
{
int V_7 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
switch ( V_23 -> V_30 . V_31 ) {
case V_32 :
V_7 = F_21 ( V_23 , V_48 ) ;
break;
case V_34 :
V_7 = F_22 ( V_23 , V_48 ) ;
break;
case V_47 :
V_7 = F_23 ( V_23 , V_48 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static int F_24 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
int V_7 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
if ( V_2 -> V_31 == V_49 )
return 0 ;
switch ( V_23 -> V_30 . V_31 ) {
case V_32 :
V_7 = F_25 ( V_23 ) ;
break;
case V_34 :
V_7 = F_26 ( V_23 ) ;
break;
case V_47 :
V_7 = F_27 ( V_23 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static int F_28 ( struct V_22 * V_23 , T_2 * V_50 )
{
int V_7 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
switch ( V_23 -> V_30 . V_31 ) {
case V_32 :
V_7 = F_29 ( V_23 , V_50 ) ;
break;
case V_34 :
V_7 = F_30 ( V_23 , V_50 ) ;
break;
case V_47 :
V_7 = F_31 ( V_23 , V_50 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static int F_32 ( struct V_22 * V_23 , T_5 * V_51 )
{
int V_7 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
switch ( V_23 -> V_30 . V_31 ) {
case V_32 :
V_7 = F_33 ( V_23 , V_51 ) ;
break;
case V_34 :
V_7 = F_34 ( V_23 , V_51 ) ;
break;
case V_47 :
V_7 = F_35 ( V_23 , V_51 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static int F_36 ( struct V_22 * V_23 , T_5 * V_52 )
{
int V_7 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
switch ( V_23 -> V_30 . V_31 ) {
case V_32 :
V_7 = F_37 ( V_23 , V_52 ) ;
break;
case V_34 :
V_7 = F_38 ( V_23 , V_52 ) ;
break;
case V_47 :
V_7 = F_39 ( V_23 , V_52 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static int F_40 ( struct V_22 * V_23 , T_2 * V_53 )
{
int V_7 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
switch ( V_23 -> V_30 . V_31 ) {
case V_32 :
V_7 = F_41 ( V_23 , V_53 ) ;
break;
case V_34 :
V_7 = F_42 ( V_23 , V_53 ) ;
break;
case V_47 :
V_7 = F_43 ( V_23 , V_53 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static int F_44 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_45 ( struct V_22 * V_23 )
{
int V_7 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
switch ( V_23 -> V_30 . V_31 ) {
case V_32 :
V_7 = F_46 ( V_23 ) ;
break;
case V_34 :
V_7 = F_47 ( V_23 ) ;
break;
case V_47 :
V_7 = F_48 ( V_23 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static int F_49 ( struct V_22 * V_23 ,
struct V_54 * V_55 )
{
int V_7 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
switch ( V_23 -> V_30 . V_31 ) {
case V_32 :
V_7 = F_50 ( V_23 , V_55 ) ;
break;
case V_34 :
V_7 = F_51 ( V_23 , V_55 ) ;
break;
case V_47 :
V_7 = F_52 ( V_23 , V_55 ) ;
break;
default:
V_7 = - V_38 ;
break;
}
return V_7 ;
}
static enum V_56 F_53 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
struct V_44 * V_45 = & V_23 -> V_30 ;
int V_7 , V_25 ;
T_4 V_48 = 0 ;
F_11 ( L_3 , V_29 , V_23 -> V_30 . V_31 ) ;
if ( V_2 -> V_57 ) {
if ( V_2 -> V_31 == V_32 ) {
V_7 = F_46 ( V_23 ) ;
if ( V_7 )
goto error;
V_45 -> V_31 = V_34 ;
} else if ( V_2 -> V_31 == V_34 ) {
V_7 = F_47 ( V_23 ) ;
if ( V_7 )
goto error;
V_45 -> V_31 = V_32 ;
}
}
V_7 = F_14 ( V_23 ) ;
if ( V_7 )
goto error;
switch ( V_2 -> V_31 ) {
case V_32 :
case V_47 :
V_25 = 20 ;
break;
case V_34 :
V_25 = 40 ;
break;
case V_49 :
default:
V_25 = 0 ;
break;
}
for (; V_25 > 0 ; V_25 -- ) {
F_11 ( L_8 , V_29 , V_25 ) ;
F_54 ( 50 ) ;
V_7 = F_20 ( V_23 , & V_48 ) ;
if ( V_7 )
goto error;
if ( V_48 & V_58 )
break;
}
if ( V_48 & V_58 ) {
V_2 -> V_57 = 0 ;
return V_59 ;
} else {
V_2 -> V_57 = 1 ;
return V_60 ;
}
error:
F_11 ( L_6 , V_29 , V_7 ) ;
return V_61 ;
}
static int F_55 ( struct V_22 * V_23 )
{
return V_62 ;
}
static void F_56 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_11 ( L_9 , V_29 ) ;
F_57 ( V_2 ) ;
return;
}
static int F_58 ( struct V_22 * V_23 , int V_63 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
F_11 ( L_10 , V_29 , V_63 ) ;
return F_9 ( V_2 , 0xdb , V_63 ? 1 : 0 , 0x1 ) ;
}
struct V_22 * F_59 ( const struct V_64 * V_18 ,
struct V_65 * V_3 )
{
struct V_1 * V_2 = NULL ;
int V_7 ;
T_1 V_21 ;
V_2 = F_60 ( sizeof ( struct V_1 ) , V_66 ) ;
if ( ! V_2 )
goto error;
V_2 -> V_3 = V_3 ;
memcpy ( & V_2 -> V_18 , V_18 , sizeof ( struct V_64 ) ) ;
V_2 -> V_17 [ 0 ] = V_2 -> V_17 [ 1 ] = 0xff ;
V_7 = F_8 ( V_2 , 0x000fd , & V_21 ) ;
F_11 ( L_11 , V_29 , V_21 ) ;
if ( V_7 || V_21 != 0xe1 )
goto error;
memcpy ( & V_2 -> V_23 . V_67 , & V_68 , sizeof ( struct V_69 ) ) ;
V_2 -> V_23 . V_24 = V_2 ;
return & V_2 -> V_23 ;
error:
F_57 ( V_2 ) ;
return NULL ;
}
