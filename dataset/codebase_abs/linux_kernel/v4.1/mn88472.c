static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 800 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_12 = & V_2 -> V_13 ;
int V_14 , V_15 ;
T_1 V_16 = 0 ;
T_2 V_17 ;
T_3 V_18 , V_19 [ 3 ] , V_20 [ 7 ] , V_21 ;
F_4 ( & V_7 -> V_10 ,
L_1 ,
V_12 -> V_22 , V_12 -> V_23 ,
V_12 -> V_24 , V_12 -> V_25 , V_12 -> V_26 ) ;
if ( ! V_10 -> V_27 ) {
V_14 = - V_28 ;
goto V_29;
}
switch ( V_12 -> V_22 ) {
case V_30 :
V_18 = 0x02 ;
break;
case V_31 :
V_18 = 0x03 ;
break;
case V_32 :
V_18 = 0x04 ;
break;
default:
V_14 = - V_33 ;
goto V_29;
}
if ( V_12 -> V_34 <= 5000000 ) {
memcpy ( V_20 , L_2 , 7 ) ;
V_21 = 0x03 ;
} else if ( V_12 -> V_34 <= 6000000 ) {
memcpy ( V_20 , L_3 , 7 ) ;
V_21 = 0x02 ;
} else if ( V_12 -> V_34 <= 7000000 ) {
memcpy ( V_20 , L_4 , 7 ) ;
V_21 = 0x01 ;
} else if ( V_12 -> V_34 <= 8000000 ) {
memcpy ( V_20 , L_5 , 7 ) ;
V_21 = 0x00 ;
} else {
V_14 = - V_33 ;
goto V_29;
}
if ( V_2 -> V_35 . V_36 . V_37 ) {
V_14 = V_2 -> V_35 . V_36 . V_37 ( V_2 ) ;
if ( V_14 )
goto V_29;
}
if ( V_2 -> V_35 . V_36 . V_38 ) {
V_14 = V_2 -> V_35 . V_36 . V_38 ( V_2 , & V_16 ) ;
if ( V_14 )
goto V_29;
F_4 ( & V_7 -> V_10 , L_6 , V_16 ) ;
}
V_17 = F_5 ( V_16 * ( T_2 ) ( 1 << 24 ) + ( V_10 -> V_39 / 2 ) ,
V_10 -> V_39 ) ;
V_19 [ 0 ] = ( ( V_17 >> 16 ) & 0xff ) ;
V_19 [ 1 ] = ( ( V_17 >> 8 ) & 0xff ) ;
V_19 [ 2 ] = ( ( V_17 >> 0 ) & 0xff ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0xfb , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0xef , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0xf9 , 0x13 ) ;
if ( V_14 )
goto V_29;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x00 , 0x66 ) ;
if ( V_14 )
goto V_29;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x01 , 0x00 ) ;
if ( V_14 )
goto V_29;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x02 , 0x01 ) ;
if ( V_14 )
goto V_29;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x03 , V_18 ) ;
if ( V_14 )
goto V_29;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x04 , V_21 ) ;
if ( V_14 )
goto V_29;
for ( V_15 = 0 ; V_15 < sizeof( V_19 ) ; V_15 ++ ) {
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x10 + V_15 , V_19 [ V_15 ] ) ;
if ( V_14 )
goto V_29;
}
for ( V_15 = 0 ; V_15 < sizeof( V_20 ) ; V_15 ++ ) {
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x13 + V_15 , V_20 [ V_15 ] ) ;
if ( V_14 )
goto V_29;
}
switch ( V_12 -> V_22 ) {
case V_30 :
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x07 , 0x26 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xb0 , 0x0a ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xb4 , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xcd , 0x1f ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd4 , 0x0a ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd6 , 0x48 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x00 , 0xba ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x01 , 0x13 ) ;
if ( V_14 )
goto V_29;
break;
case V_31 :
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x2b , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x4f , 0x05 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 1 ] , 0xf6 , 0x05 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xb0 , 0x0a ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xb4 , 0xf6 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xcd , 0x01 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd4 , 0x09 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd6 , 0x46 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x30 , 0x80 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x32 , 0x00 ) ;
if ( V_14 )
goto V_29;
break;
case V_32 :
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xb0 , 0x0b ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xb4 , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xcd , 0x17 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd4 , 0x09 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd6 , 0x48 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 1 ] , 0x00 , 0xb0 ) ;
if ( V_14 )
goto V_29;
break;
default:
V_14 = - V_33 ;
goto V_29;
}
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0x46 , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xae , 0x00 ) ;
switch ( V_10 -> V_41 ) {
case V_42 :
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x08 , 0x1d ) ;
break;
case V_43 :
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x08 , 0x00 ) ;
break;
default:
F_4 ( & V_7 -> V_10 , L_7 , V_10 -> V_41 ) ;
V_14 = - V_33 ;
goto V_29;
}
switch ( V_10 -> V_44 ) {
case V_45 :
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd9 , 0xe3 ) ;
break;
case V_46 :
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xd9 , 0xe1 ) ;
break;
default:
F_4 ( & V_7 -> V_10 , L_8 , V_10 -> V_44 ) ;
V_14 = - V_33 ;
goto V_29;
}
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0xf8 , 0x9f ) ;
if ( V_14 )
goto V_29;
V_10 -> V_22 = V_12 -> V_22 ;
return 0 ;
V_29:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_7 ( struct V_1 * V_2 , T_4 * V_47 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_12 = & V_2 -> V_13 ;
int V_14 ;
unsigned int V_48 ;
int V_49 = 0 ;
* V_47 = 0 ;
if ( ! V_10 -> V_27 ) {
V_14 = - V_28 ;
goto V_29;
}
switch ( V_12 -> V_22 ) {
case V_30 :
V_14 = F_8 ( V_10 -> V_40 [ 0 ] , 0x7F , & V_48 ) ;
if ( V_14 )
goto V_29;
if ( ( V_48 & 0xF ) >= 0x09 )
V_49 = 1 ;
break;
case V_31 :
V_14 = F_8 ( V_10 -> V_40 [ 2 ] , 0x92 , & V_48 ) ;
if ( V_14 )
goto V_29;
if ( ( V_48 & 0xF ) >= 0x07 )
* V_47 |= V_50 ;
if ( ( V_48 & 0xF ) >= 0x0a )
* V_47 |= V_51 ;
if ( ( V_48 & 0xF ) >= 0x0d )
* V_47 |= V_52 | V_53 | V_54 ;
break;
case V_32 :
V_14 = F_8 ( V_10 -> V_40 [ 1 ] , 0x84 , & V_48 ) ;
if ( V_14 )
goto V_29;
if ( ( V_48 & 0xF ) >= 0x08 )
V_49 = 1 ;
break;
default:
V_14 = - V_33 ;
goto V_29;
}
if ( V_49 )
* V_47 = V_50 | V_51 | V_52 |
V_53 | V_54 ;
return 0 ;
V_29:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_14 , V_55 , V_56 ;
const struct V_57 * V_58 = NULL ;
T_3 * V_59 = V_60 ;
unsigned int V_17 ;
F_4 ( & V_7 -> V_10 , L_10 ) ;
V_10 -> V_27 = false ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x05 , 0x00 ) ;
if ( V_14 )
goto V_29;
V_14 = F_10 ( V_10 -> V_40 [ 2 ] , 0x0b , L_11 , 2 ) ;
if ( V_14 )
goto V_29;
V_14 = F_8 ( V_10 -> V_40 [ 0 ] , 0xf5 , & V_17 ) ;
if ( V_14 )
goto V_29;
if ( ! ( V_17 & 0x1 ) ) {
F_11 ( & V_7 -> V_10 , L_12 ) ;
V_10 -> V_27 = true ;
return 0 ;
}
V_14 = F_12 ( & V_58 , V_59 , & V_7 -> V_10 ) ;
if ( V_14 ) {
F_13 ( & V_7 -> V_10 , L_13 ,
V_59 ) ;
goto V_29;
}
F_11 ( & V_7 -> V_10 , L_14 ,
V_59 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xf5 , 0x03 ) ;
if ( V_14 )
goto V_61;
for ( V_56 = V_58 -> V_62 ; V_56 > 0 ;
V_56 -= ( V_10 -> V_63 - 1 ) ) {
V_55 = V_56 ;
if ( V_55 > ( V_10 -> V_63 - 1 ) )
V_55 = V_10 -> V_63 - 1 ;
V_14 = F_10 ( V_10 -> V_40 [ 0 ] , 0xf6 ,
& V_58 -> V_64 [ V_58 -> V_62 - V_56 ] , V_55 ) ;
if ( V_14 ) {
F_13 ( & V_7 -> V_10 ,
L_15 , V_14 ) ;
goto V_61;
}
}
V_14 = F_8 ( V_10 -> V_40 [ 0 ] , 0xf8 , & V_17 ) ;
if ( V_14 ) {
F_13 ( & V_7 -> V_10 ,
L_16 , V_14 ) ;
goto V_29;
}
if ( V_17 & 0x10 ) {
F_13 ( & V_7 -> V_10 ,
L_17 , V_17 ) ;
goto V_29;
}
F_13 ( & V_7 -> V_10 , L_18 , V_17 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 0 ] , 0xf5 , 0x00 ) ;
if ( V_14 )
goto V_61;
F_14 ( V_58 ) ;
V_58 = NULL ;
V_10 -> V_27 = true ;
return 0 ;
V_61:
F_14 ( V_58 ) ;
V_29:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_14 ;
F_4 ( & V_7 -> V_10 , L_10 ) ;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x0b , 0x30 ) ;
if ( V_14 )
goto V_29;
V_14 = F_6 ( V_10 -> V_40 [ 2 ] , 0x05 , 0x3e ) ;
if ( V_14 )
goto V_29;
V_10 -> V_22 = V_65 ;
return 0 ;
V_29:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_16 ( struct V_6 * V_7 ,
const struct V_66 * V_67 )
{
struct V_68 * V_69 = V_7 -> V_10 . V_70 ;
struct V_9 * V_10 ;
int V_14 ;
unsigned int V_48 ;
static const struct V_71 V_71 = {
. V_72 = 8 ,
. V_73 = 8 ,
} ;
F_4 ( & V_7 -> V_10 , L_10 ) ;
if ( V_69 -> V_2 == NULL ) {
F_13 ( & V_7 -> V_10 , L_19 ) ;
V_14 = - V_33 ;
goto V_29;
}
V_10 = F_17 ( sizeof( * V_10 ) , V_74 ) ;
if ( V_10 == NULL ) {
V_14 = - V_75 ;
goto V_29;
}
V_10 -> V_63 = V_69 -> V_63 ;
V_10 -> V_39 = V_69 -> V_39 ;
V_10 -> V_41 = V_69 -> V_41 ;
V_10 -> V_44 = V_69 -> V_44 ;
V_10 -> V_7 [ 0 ] = V_7 ;
V_10 -> V_40 [ 0 ] = F_18 ( V_10 -> V_7 [ 0 ] , & V_71 ) ;
if ( F_19 ( V_10 -> V_40 [ 0 ] ) ) {
V_14 = F_20 ( V_10 -> V_40 [ 0 ] ) ;
goto V_76;
}
V_14 = F_8 ( V_10 -> V_40 [ 0 ] , 0x00 , & V_48 ) ;
if ( V_14 )
goto V_77;
V_10 -> V_7 [ 1 ] = F_21 ( V_7 -> V_78 , 0x1a ) ;
if ( V_10 -> V_7 [ 1 ] == NULL ) {
V_14 = - V_79 ;
F_13 ( & V_7 -> V_10 , L_20 ) ;
if ( V_14 )
goto V_77;
}
V_10 -> V_40 [ 1 ] = F_18 ( V_10 -> V_7 [ 1 ] , & V_71 ) ;
if ( F_19 ( V_10 -> V_40 [ 1 ] ) ) {
V_14 = F_20 ( V_10 -> V_40 [ 1 ] ) ;
goto V_80;
}
F_22 ( V_10 -> V_7 [ 1 ] , V_10 ) ;
V_10 -> V_7 [ 2 ] = F_21 ( V_7 -> V_78 , 0x1c ) ;
if ( V_10 -> V_7 [ 2 ] == NULL ) {
V_14 = - V_79 ;
F_13 ( & V_7 -> V_10 , L_21 ) ;
if ( V_14 )
goto V_81;
}
V_10 -> V_40 [ 2 ] = F_18 ( V_10 -> V_7 [ 2 ] , & V_71 ) ;
if ( F_19 ( V_10 -> V_40 [ 2 ] ) ) {
V_14 = F_20 ( V_10 -> V_40 [ 2 ] ) ;
goto V_82;
}
F_22 ( V_10 -> V_7 [ 2 ] , V_10 ) ;
memcpy ( & V_10 -> V_2 . V_35 , & V_83 , sizeof( struct V_84 ) ) ;
V_10 -> V_2 . V_8 = V_7 ;
* V_69 -> V_2 = & V_10 -> V_2 ;
F_22 ( V_7 , V_10 ) ;
F_11 ( & V_7 -> V_10 , L_22 ) ;
return 0 ;
V_82:
F_23 ( V_10 -> V_7 [ 2 ] ) ;
V_81:
F_24 ( V_10 -> V_40 [ 1 ] ) ;
V_80:
F_23 ( V_10 -> V_7 [ 1 ] ) ;
V_77:
F_24 ( V_10 -> V_40 [ 0 ] ) ;
V_76:
F_25 ( V_10 ) ;
V_29:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_26 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_4 ( & V_7 -> V_10 , L_10 ) ;
F_24 ( V_10 -> V_40 [ 2 ] ) ;
F_23 ( V_10 -> V_7 [ 2 ] ) ;
F_24 ( V_10 -> V_40 [ 1 ] ) ;
F_23 ( V_10 -> V_7 [ 1 ] ) ;
F_24 ( V_10 -> V_40 [ 0 ] ) ;
F_25 ( V_10 ) ;
return 0 ;
}
