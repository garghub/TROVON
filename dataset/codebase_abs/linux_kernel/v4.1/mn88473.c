static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 1000 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_12 = & V_2 -> V_13 ;
int V_14 , V_15 ;
T_1 V_16 ;
T_2 V_17 ;
T_3 V_18 , V_19 [ 3 ] , V_20 [ 7 ] ;
F_4 ( & V_7 -> V_10 ,
L_1 ,
V_12 -> V_21 ,
V_12 -> V_22 ,
V_12 -> V_23 ,
V_12 -> V_24 ,
V_12 -> V_25 ,
V_12 -> V_26 ,
V_12 -> V_27 ) ;
if ( ! V_10 -> V_28 ) {
V_14 = - V_29 ;
goto V_30;
}
switch ( V_12 -> V_21 ) {
case V_31 :
V_18 = 0x02 ;
break;
case V_32 :
V_18 = 0x03 ;
break;
case V_33 :
V_18 = 0x04 ;
break;
default:
V_14 = - V_34 ;
goto V_30;
}
if ( V_12 -> V_24 <= 6000000 ) {
memcpy ( V_20 , L_2 , 7 ) ;
} else if ( V_12 -> V_24 <= 7000000 ) {
memcpy ( V_20 , L_3 , 7 ) ;
} else if ( V_12 -> V_24 <= 8000000 ) {
memcpy ( V_20 , L_4 , 7 ) ;
} else {
V_14 = - V_34 ;
goto V_30;
}
if ( V_2 -> V_35 . V_36 . V_37 ) {
V_14 = V_2 -> V_35 . V_36 . V_37 ( V_2 ) ;
if ( V_14 )
goto V_30;
}
if ( V_2 -> V_35 . V_36 . V_38 ) {
V_14 = V_2 -> V_35 . V_36 . V_38 ( V_2 , & V_16 ) ;
if ( V_14 )
goto V_30;
F_4 ( & V_7 -> V_10 , L_5 , V_16 ) ;
} else {
V_16 = 0 ;
}
V_17 = F_5 ( V_16 * ( T_2 ) ( 1 << 24 ) + ( V_10 -> V_39 / 2 ) ,
V_10 -> V_39 ) ;
V_19 [ 0 ] = ( ( V_17 >> 16 ) & 0xff ) ;
V_19 [ 1 ] = ( ( V_17 >> 8 ) & 0xff ) ;
V_19 [ 2 ] = ( ( V_17 >> 0 ) & 0xff ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x05 , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0xfb , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0xef , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0xf9 , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x00 , 0x18 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x01 , 0x01 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x02 , 0x21 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x03 , V_18 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x0b , 0x00 ) ;
for ( V_15 = 0 ; V_15 < sizeof( V_19 ) ; V_15 ++ ) {
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x10 + V_15 , V_19 [ V_15 ] ) ;
if ( V_14 )
goto V_30;
}
for ( V_15 = 0 ; V_15 < sizeof( V_20 ) ; V_15 ++ ) {
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x13 + V_15 , V_20 [ V_15 ] ) ;
if ( V_14 )
goto V_30;
}
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x2d , 0x3b ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x2e , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x56 , 0x0d ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x01 , 0xba ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x02 , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x03 , 0x80 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x04 , 0xba ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x05 , 0x91 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x07 , 0xe7 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x08 , 0x28 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x0a , 0x1a ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x13 , 0x1f ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x19 , 0x03 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x1d , 0xb0 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x2a , 0x72 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x2d , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x3c , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x3f , 0xf8 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x40 , 0xf4 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x41 , 0x08 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd2 , 0x29 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd4 , 0x55 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 1 ] , 0x10 , 0x10 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 1 ] , 0x11 , 0xab ) ;
V_14 = F_6 ( V_10 -> V_40 [ 1 ] , 0x12 , 0x0d ) ;
V_14 = F_6 ( V_10 -> V_40 [ 1 ] , 0x13 , 0xae ) ;
V_14 = F_6 ( V_10 -> V_40 [ 1 ] , 0x14 , 0x1d ) ;
V_14 = F_6 ( V_10 -> V_40 [ 1 ] , 0x15 , 0x9d ) ;
V_14 = F_6 ( V_10 -> V_40 [ 1 ] , 0xbe , 0x08 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x09 , 0x08 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x08 , 0x1d ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xb2 , 0x37 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd7 , 0x04 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x32 , 0x80 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x36 , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0xf8 , 0x9f ) ;
if ( V_14 )
goto V_30;
V_10 -> V_21 = V_12 -> V_21 ;
return 0 ;
V_30:
F_4 ( & V_7 -> V_10 , L_6 , V_14 ) ;
return V_14 ;
}
static int F_7 ( struct V_1 * V_2 , T_4 * V_41 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_12 = & V_2 -> V_13 ;
int V_14 ;
unsigned int V_42 ;
int V_43 = 0 ;
* V_41 = 0 ;
if ( ! V_10 -> V_28 ) {
V_14 = - V_29 ;
goto V_30;
}
switch ( V_12 -> V_21 ) {
case V_31 :
V_14 = F_8 ( V_10 -> V_40 [ 0 ] , 0x62 , & V_42 ) ;
if ( V_14 )
goto V_30;
if ( ! ( V_42 & 0xA0 ) ) {
if ( ( V_42 & 0xF ) >= 0x03 )
* V_41 |= V_44 ;
if ( ( V_42 & 0xF ) >= 0x09 )
V_43 = 1 ;
}
break;
case V_32 :
V_14 = F_8 ( V_10 -> V_40 [ 2 ] , 0x8B , & V_42 ) ;
if ( V_14 )
goto V_30;
if ( ! ( V_42 & 0x40 ) ) {
if ( ( V_42 & 0xF ) >= 0x07 )
* V_41 |= V_44 ;
if ( ( V_42 & 0xF ) >= 0x0a )
* V_41 |= V_45 ;
if ( ( V_42 & 0xF ) >= 0x0d )
* V_41 |= V_46 | V_47 | V_48 ;
}
break;
case V_33 :
V_14 = F_8 ( V_10 -> V_40 [ 1 ] , 0x85 , & V_42 ) ;
if ( V_14 )
goto V_30;
if ( ! ( V_42 & 0x40 ) ) {
V_14 = F_8 ( V_10 -> V_40 [ 1 ] , 0x89 , & V_42 ) ;
if ( V_14 )
goto V_30;
if ( V_42 & 0x01 )
V_43 = 1 ;
}
break;
default:
V_14 = - V_34 ;
goto V_30;
}
if ( V_43 )
* V_41 = V_44 | V_45 | V_46 |
V_47 | V_48 ;
return 0 ;
V_30:
F_4 ( & V_7 -> V_10 , L_6 , V_14 ) ;
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_14 , V_49 , V_50 ;
const struct V_51 * V_52 = NULL ;
T_3 * V_53 = V_54 ;
unsigned int V_17 ;
F_4 ( & V_7 -> V_10 , L_7 ) ;
V_10 -> V_28 = false ;
V_14 = F_8 ( V_10 -> V_40 [ 0 ] , 0xf5 , & V_17 ) ;
if ( V_14 )
goto V_30;
if ( ! ( V_17 & 0x1 ) ) {
F_10 ( & V_7 -> V_10 , L_8 ) ;
V_10 -> V_28 = true ;
return 0 ;
}
V_14 = F_11 ( & V_52 , V_53 , & V_7 -> V_10 ) ;
if ( V_14 ) {
F_12 ( & V_7 -> V_10 , L_9 , V_53 ) ;
goto V_55;
}
F_10 ( & V_7 -> V_10 , L_10 ,
V_53 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xf5 , 0x03 ) ;
if ( V_14 )
goto V_30;
for ( V_50 = V_52 -> V_56 ; V_50 > 0 ;
V_50 -= ( V_10 -> V_57 - 1 ) ) {
V_49 = V_50 ;
if ( V_49 > ( V_10 -> V_57 - 1 ) )
V_49 = V_10 -> V_57 - 1 ;
V_14 = F_13 ( V_10 -> V_40 [ 0 ] , 0xf6 ,
& V_52 -> V_58 [ V_52 -> V_56 - V_50 ] , V_49 ) ;
if ( V_14 ) {
F_12 ( & V_7 -> V_10 , L_11 ,
V_14 ) ;
goto V_30;
}
}
V_14 = F_8 ( V_10 -> V_40 [ 0 ] , 0xf8 , & V_17 ) ;
if ( V_14 ) {
F_12 ( & V_7 -> V_10 ,
L_12 , V_14 ) ;
goto V_30;
}
if ( V_17 & 0x10 ) {
F_12 ( & V_7 -> V_10 ,
L_13 , V_17 ) ;
goto V_30;
}
F_12 ( & V_7 -> V_10 , L_14 , V_17 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xf5 , 0x00 ) ;
if ( V_14 )
goto V_30;
F_14 ( V_52 ) ;
V_52 = NULL ;
V_10 -> V_28 = true ;
return 0 ;
V_30:
F_14 ( V_52 ) ;
V_55:
F_4 ( & V_7 -> V_10 , L_6 , V_14 ) ;
return V_14 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_14 ;
F_4 ( & V_7 -> V_10 , L_7 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x05 , 0x3e ) ;
if ( V_14 )
goto V_30;
V_10 -> V_21 = V_59 ;
return 0 ;
V_30:
F_4 ( & V_7 -> V_10 , L_6 , V_14 ) ;
return V_14 ;
}
static int F_16 ( struct V_6 * V_7 ,
const struct V_60 * V_61 )
{
struct V_62 * V_63 = V_7 -> V_10 . V_64 ;
struct V_9 * V_10 ;
int V_14 ;
unsigned int V_42 ;
static const struct V_65 V_65 = {
. V_66 = 8 ,
. V_67 = 8 ,
} ;
F_4 ( & V_7 -> V_10 , L_7 ) ;
if ( V_63 -> V_2 == NULL ) {
F_12 ( & V_7 -> V_10 , L_15 ) ;
V_14 = - V_34 ;
goto V_30;
}
V_10 = F_17 ( sizeof( * V_10 ) , V_68 ) ;
if ( V_10 == NULL ) {
V_14 = - V_69 ;
goto V_30;
}
V_10 -> V_57 = V_63 -> V_57 ;
if ( ! V_63 -> V_39 )
V_10 -> V_39 = 25000000 ;
else
V_10 -> V_39 = V_63 -> V_39 ;
V_10 -> V_7 [ 0 ] = V_7 ;
V_10 -> V_40 [ 0 ] = F_18 ( V_10 -> V_7 [ 0 ] , & V_65 ) ;
if ( F_19 ( V_10 -> V_40 [ 0 ] ) ) {
V_14 = F_20 ( V_10 -> V_40 [ 0 ] ) ;
goto V_70;
}
V_14 = F_8 ( V_10 -> V_40 [ 0 ] , 0x00 , & V_42 ) ;
if ( V_14 )
goto V_71;
V_10 -> V_7 [ 1 ] = F_21 ( V_7 -> V_72 , 0x1a ) ;
if ( V_10 -> V_7 [ 1 ] == NULL ) {
V_14 = - V_73 ;
F_12 ( & V_7 -> V_10 , L_16 ) ;
if ( V_14 )
goto V_71;
}
V_10 -> V_40 [ 1 ] = F_18 ( V_10 -> V_7 [ 1 ] , & V_65 ) ;
if ( F_19 ( V_10 -> V_40 [ 1 ] ) ) {
V_14 = F_20 ( V_10 -> V_40 [ 1 ] ) ;
goto V_74;
}
F_22 ( V_10 -> V_7 [ 1 ] , V_10 ) ;
V_10 -> V_7 [ 2 ] = F_21 ( V_7 -> V_72 , 0x1c ) ;
if ( V_10 -> V_7 [ 2 ] == NULL ) {
V_14 = - V_73 ;
F_12 ( & V_7 -> V_10 , L_17 ) ;
if ( V_14 )
goto V_75;
}
V_10 -> V_40 [ 2 ] = F_18 ( V_10 -> V_7 [ 2 ] , & V_65 ) ;
if ( F_19 ( V_10 -> V_40 [ 2 ] ) ) {
V_14 = F_20 ( V_10 -> V_40 [ 2 ] ) ;
goto V_76;
}
F_22 ( V_10 -> V_7 [ 2 ] , V_10 ) ;
memcpy ( & V_10 -> V_2 . V_35 , & V_77 , sizeof( struct V_78 ) ) ;
V_10 -> V_2 . V_8 = V_7 ;
* V_63 -> V_2 = & V_10 -> V_2 ;
F_22 ( V_7 , V_10 ) ;
F_10 ( & V_10 -> V_7 [ 0 ] -> V_10 , L_18 ) ;
return 0 ;
V_76:
F_23 ( V_10 -> V_7 [ 2 ] ) ;
V_75:
F_24 ( V_10 -> V_40 [ 1 ] ) ;
V_74:
F_23 ( V_10 -> V_7 [ 1 ] ) ;
V_71:
F_24 ( V_10 -> V_40 [ 0 ] ) ;
V_70:
F_25 ( V_10 ) ;
V_30:
F_4 ( & V_7 -> V_10 , L_6 , V_14 ) ;
return V_14 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_4 ( & V_7 -> V_10 , L_7 ) ;
F_24 ( V_10 -> V_40 [ 2 ] ) ;
F_23 ( V_10 -> V_7 [ 2 ] ) ;
F_24 ( V_10 -> V_40 [ 1 ] ) ;
F_23 ( V_10 -> V_7 [ 1 ] ) ;
F_24 ( V_10 -> V_40 [ 0 ] ) ;
F_25 ( V_10 ) ;
return 0 ;
}
