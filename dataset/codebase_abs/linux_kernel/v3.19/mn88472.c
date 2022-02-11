static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 400 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_12 = & V_2 -> V_13 ;
int V_14 , V_15 ;
T_1 V_16 = 0 ;
T_2 V_17 , V_18 [ 3 ] , V_19 [ 7 ] , V_20 ;
F_4 ( & V_7 -> V_10 ,
L_1 ,
V_12 -> V_21 , V_12 -> V_22 ,
V_12 -> V_23 , V_12 -> V_24 , V_12 -> V_25 ) ;
if ( ! V_10 -> V_26 ) {
V_14 = - V_27 ;
goto V_28;
}
switch ( V_12 -> V_21 ) {
case V_29 :
V_17 = 0x02 ;
break;
case V_30 :
V_17 = 0x03 ;
break;
case V_31 :
V_17 = 0x04 ;
break;
default:
V_14 = - V_32 ;
goto V_28;
}
switch ( V_12 -> V_21 ) {
case V_29 :
case V_30 :
if ( V_12 -> V_33 <= 6000000 ) {
memcpy ( V_18 , L_2 , 3 ) ;
memcpy ( V_19 , L_3 , 7 ) ;
V_20 = 0x02 ;
} else if ( V_12 -> V_33 <= 7000000 ) {
memcpy ( V_18 , L_4 , 3 ) ;
memcpy ( V_19 , L_5 , 7 ) ;
V_20 = 0x01 ;
} else if ( V_12 -> V_33 <= 8000000 ) {
memcpy ( V_18 , L_4 , 3 ) ;
memcpy ( V_19 , L_6 , 7 ) ;
V_20 = 0x00 ;
} else {
V_14 = - V_32 ;
goto V_28;
}
break;
case V_31 :
memcpy ( V_18 , L_7 , 3 ) ;
memcpy ( V_19 , L_6 , 7 ) ;
V_20 = 0x00 ;
break;
default:
V_14 = - V_32 ;
goto V_28;
}
if ( V_2 -> V_34 . V_35 . V_36 ) {
V_14 = V_2 -> V_34 . V_35 . V_36 ( V_2 ) ;
if ( V_14 )
goto V_28;
}
if ( V_2 -> V_34 . V_35 . V_37 ) {
V_14 = V_2 -> V_34 . V_35 . V_37 ( V_2 , & V_16 ) ;
if ( V_14 )
goto V_28;
F_4 ( & V_7 -> V_10 , L_8 , V_16 ) ;
}
switch ( V_16 ) {
case 3570000 :
case 4570000 :
case 5070000 :
break;
default:
F_5 ( & V_7 -> V_10 , L_9 ,
V_16 ) ;
V_14 = - V_32 ;
goto V_28;
}
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0xfb , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0xef , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0xf9 , 0x13 ) ;
if ( V_14 )
goto V_28;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x00 , 0x66 ) ;
if ( V_14 )
goto V_28;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x01 , 0x00 ) ;
if ( V_14 )
goto V_28;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x02 , 0x01 ) ;
if ( V_14 )
goto V_28;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x03 , V_17 ) ;
if ( V_14 )
goto V_28;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x04 , V_20 ) ;
if ( V_14 )
goto V_28;
for ( V_15 = 0 ; V_15 < sizeof( V_18 ) ; V_15 ++ ) {
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x10 + V_15 , V_18 [ V_15 ] ) ;
if ( V_14 )
goto V_28;
}
for ( V_15 = 0 ; V_15 < sizeof( V_19 ) ; V_15 ++ ) {
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x13 + V_15 , V_19 [ V_15 ] ) ;
if ( V_14 )
goto V_28;
}
switch ( V_12 -> V_21 ) {
case V_29 :
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0x07 , 0x26 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xb0 , 0x0a ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xb4 , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xcd , 0x1f ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xd4 , 0x0a ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xd6 , 0x48 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0x00 , 0xba ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0x01 , 0x13 ) ;
if ( V_14 )
goto V_28;
break;
case V_30 :
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x2b , 0x13 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x4f , 0x05 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 1 ] , 0xf6 , 0x05 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xb0 , 0x0a ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xb4 , 0xf6 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xcd , 0x01 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xd4 , 0x09 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xd6 , 0x46 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x30 , 0x80 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x32 , 0x00 ) ;
if ( V_14 )
goto V_28;
break;
case V_31 :
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xb0 , 0x0b ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xb4 , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xcd , 0x17 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xd4 , 0x09 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xd6 , 0x48 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 1 ] , 0x00 , 0xb0 ) ;
if ( V_14 )
goto V_28;
break;
default:
V_14 = - V_32 ;
goto V_28;
}
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0x46 , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xae , 0x00 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x08 , 0x1d ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xd9 , 0xe3 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0xf8 , 0x9f ) ;
if ( V_14 )
goto V_28;
V_10 -> V_21 = V_12 -> V_21 ;
return 0 ;
V_28:
F_4 ( & V_7 -> V_10 , L_10 , V_14 ) ;
return V_14 ;
}
static int F_7 ( struct V_1 * V_2 , T_3 * V_39 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_12 = & V_2 -> V_13 ;
int V_14 ;
unsigned int V_40 ;
* V_39 = 0 ;
if ( ! V_10 -> V_26 ) {
V_14 = - V_27 ;
goto V_28;
}
switch ( V_12 -> V_21 ) {
case V_29 :
case V_30 :
V_40 = 0x08 ;
break;
case V_31 :
V_14 = F_8 ( V_10 -> V_38 [ 1 ] , 0x84 , & V_40 ) ;
if ( V_14 )
goto V_28;
break;
default:
V_14 = - V_32 ;
goto V_28;
}
if ( V_40 == 0x08 )
* V_39 = V_41 | V_42 | V_43 |
V_44 | V_45 ;
return 0 ;
V_28:
F_4 ( & V_7 -> V_10 , L_10 , V_14 ) ;
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_14 , V_46 , V_47 ;
const struct V_48 * V_49 = NULL ;
T_2 * V_50 = V_51 ;
F_4 ( & V_7 -> V_10 , L_11 ) ;
V_10 -> V_26 = false ;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x05 , 0x00 ) ;
if ( V_14 )
goto V_28;
V_14 = F_10 ( V_10 -> V_38 [ 2 ] , 0x0b , L_12 , 2 ) ;
if ( V_14 )
goto V_28;
V_14 = F_11 ( & V_49 , V_50 , & V_7 -> V_10 ) ;
if ( V_14 ) {
F_5 ( & V_7 -> V_10 , L_13 ,
V_50 ) ;
goto V_28;
}
F_12 ( & V_7 -> V_10 , L_14 ,
V_50 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xf5 , 0x03 ) ;
if ( V_14 )
goto V_28;
for ( V_47 = V_49 -> V_52 ; V_47 > 0 ;
V_47 -= ( V_10 -> V_53 - 1 ) ) {
V_46 = V_47 ;
if ( V_46 > ( V_10 -> V_53 - 1 ) )
V_46 = ( V_10 -> V_53 - 1 ) ;
V_14 = F_10 ( V_10 -> V_38 [ 0 ] , 0xf6 ,
& V_49 -> V_54 [ V_49 -> V_52 - V_47 ] , V_46 ) ;
if ( V_14 ) {
F_5 ( & V_7 -> V_10 ,
L_15 , V_14 ) ;
goto V_28;
}
}
V_14 = F_6 ( V_10 -> V_38 [ 0 ] , 0xf5 , 0x00 ) ;
if ( V_14 )
goto V_28;
F_13 ( V_49 ) ;
V_49 = NULL ;
V_10 -> V_26 = true ;
return 0 ;
V_28:
if ( V_49 )
F_13 ( V_49 ) ;
F_4 ( & V_7 -> V_10 , L_10 , V_14 ) ;
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_14 ;
F_4 ( & V_7 -> V_10 , L_11 ) ;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x0b , 0x30 ) ;
if ( V_14 )
goto V_28;
V_14 = F_6 ( V_10 -> V_38 [ 2 ] , 0x05 , 0x3e ) ;
if ( V_14 )
goto V_28;
V_10 -> V_21 = V_55 ;
return 0 ;
V_28:
F_4 ( & V_7 -> V_10 , L_10 , V_14 ) ;
return V_14 ;
}
static int F_15 ( struct V_6 * V_7 ,
const struct V_56 * V_57 )
{
struct V_58 * V_59 = V_7 -> V_10 . V_60 ;
struct V_9 * V_10 ;
int V_14 ;
unsigned int V_40 ;
static const struct V_61 V_61 = {
. V_62 = 8 ,
. V_63 = 8 ,
} ;
F_4 ( & V_7 -> V_10 , L_11 ) ;
if ( V_59 -> V_2 == NULL ) {
F_5 ( & V_7 -> V_10 , L_16 ) ;
V_14 = - V_32 ;
goto V_28;
}
V_10 = F_16 ( sizeof( * V_10 ) , V_64 ) ;
if ( V_10 == NULL ) {
V_14 = - V_65 ;
goto V_28;
}
V_10 -> V_53 = V_59 -> V_53 ;
V_10 -> V_7 [ 0 ] = V_7 ;
V_10 -> V_38 [ 0 ] = F_17 ( V_10 -> V_7 [ 0 ] , & V_61 ) ;
if ( F_18 ( V_10 -> V_38 [ 0 ] ) ) {
V_14 = F_19 ( V_10 -> V_38 [ 0 ] ) ;
goto V_66;
}
V_14 = F_8 ( V_10 -> V_38 [ 0 ] , 0x00 , & V_40 ) ;
if ( V_14 )
goto V_67;
V_10 -> V_7 [ 1 ] = F_20 ( V_7 -> V_68 , 0x1a ) ;
if ( V_10 -> V_7 [ 1 ] == NULL ) {
V_14 = - V_69 ;
F_5 ( & V_7 -> V_10 , L_17 ) ;
if ( V_14 )
goto V_67;
}
V_10 -> V_38 [ 1 ] = F_17 ( V_10 -> V_7 [ 1 ] , & V_61 ) ;
if ( F_18 ( V_10 -> V_38 [ 1 ] ) ) {
V_14 = F_19 ( V_10 -> V_38 [ 1 ] ) ;
goto V_70;
}
F_21 ( V_10 -> V_7 [ 1 ] , V_10 ) ;
V_10 -> V_7 [ 2 ] = F_20 ( V_7 -> V_68 , 0x1c ) ;
if ( V_10 -> V_7 [ 2 ] == NULL ) {
V_14 = - V_69 ;
F_5 ( & V_7 -> V_10 , L_18 ) ;
if ( V_14 )
goto V_71;
}
V_10 -> V_38 [ 2 ] = F_17 ( V_10 -> V_7 [ 2 ] , & V_61 ) ;
if ( F_18 ( V_10 -> V_38 [ 2 ] ) ) {
V_14 = F_19 ( V_10 -> V_38 [ 2 ] ) ;
goto V_72;
}
F_21 ( V_10 -> V_7 [ 2 ] , V_10 ) ;
memcpy ( & V_10 -> V_2 . V_34 , & V_73 , sizeof( struct V_74 ) ) ;
V_10 -> V_2 . V_8 = V_7 ;
* V_59 -> V_2 = & V_10 -> V_2 ;
F_21 ( V_7 , V_10 ) ;
F_12 ( & V_7 -> V_10 , L_19 ) ;
return 0 ;
V_72:
F_22 ( V_10 -> V_7 [ 2 ] ) ;
V_71:
F_23 ( V_10 -> V_38 [ 1 ] ) ;
V_70:
F_22 ( V_10 -> V_7 [ 1 ] ) ;
V_67:
F_23 ( V_10 -> V_38 [ 0 ] ) ;
V_66:
F_24 ( V_10 ) ;
V_28:
F_4 ( & V_7 -> V_10 , L_10 , V_14 ) ;
return V_14 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_4 ( & V_7 -> V_10 , L_11 ) ;
F_23 ( V_10 -> V_38 [ 2 ] ) ;
F_22 ( V_10 -> V_7 [ 2 ] ) ;
F_23 ( V_10 -> V_38 [ 1 ] ) ;
F_22 ( V_10 -> V_7 [ 1 ] ) ;
F_23 ( V_10 -> V_38 [ 0 ] ) ;
F_24 ( V_10 ) ;
return 0 ;
}
