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
unsigned int V_16 ;
T_1 V_17 ;
T_2 V_18 , V_19 [ 3 ] , * V_20 ;
T_2 V_21 , V_22 ;
F_4 ( & V_7 -> V_10 ,
L_1 ,
V_12 -> V_23 , V_12 -> V_24 , V_12 -> V_25 ,
V_12 -> V_26 , V_12 -> V_27 , V_12 -> V_28 , V_12 -> V_29 ) ;
if ( ! V_10 -> V_30 ) {
V_14 = - V_31 ;
goto V_32;
}
switch ( V_12 -> V_23 ) {
case V_33 :
V_18 = 0x02 ;
V_21 = 0x23 ;
V_22 = 0x2a ;
break;
case V_34 :
V_18 = 0x03 ;
V_21 = 0x3b ;
V_22 = 0x29 ;
break;
case V_35 :
V_18 = 0x04 ;
V_21 = 0x3b ;
V_22 = 0x29 ;
break;
default:
V_14 = - V_36 ;
goto V_32;
}
switch ( V_12 -> V_23 ) {
case V_33 :
case V_34 :
switch ( V_12 -> V_26 ) {
case 6000000 :
V_20 = L_2 ;
break;
case 7000000 :
V_20 = L_3 ;
break;
case 8000000 :
V_20 = L_4 ;
break;
default:
V_14 = - V_36 ;
goto V_32;
}
break;
case V_35 :
V_20 = L_5 ;
break;
default:
break;
}
if ( V_2 -> V_37 . V_38 . V_39 ) {
V_14 = V_2 -> V_37 . V_38 . V_39 ( V_2 ) ;
if ( V_14 )
goto V_32;
}
if ( V_2 -> V_37 . V_38 . V_40 ) {
V_14 = V_2 -> V_37 . V_38 . V_40 ( V_2 , & V_17 ) ;
if ( V_14 )
goto V_32;
F_4 ( & V_7 -> V_10 , L_6 , V_17 ) ;
} else {
V_14 = - V_36 ;
goto V_32;
}
V_16 = F_5 ( ( V_41 ) V_17 * 0x1000000 , V_10 -> V_42 ) ;
V_19 [ 0 ] = ( V_16 >> 16 ) & 0xff ;
V_19 [ 1 ] = ( V_16 >> 8 ) & 0xff ;
V_19 [ 2 ] = ( V_16 >> 0 ) & 0xff ;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x05 , 0x00 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0xfb , 0x13 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0xef , 0x13 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0xf9 , 0x13 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x00 , 0x18 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x01 , 0x01 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x02 , 0x21 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x03 , V_18 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x0b , 0x00 ) ;
if ( V_14 )
goto V_32;
for ( V_15 = 0 ; V_15 < sizeof( V_19 ) ; V_15 ++ ) {
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x10 + V_15 , V_19 [ V_15 ] ) ;
if ( V_14 )
goto V_32;
}
switch ( V_12 -> V_23 ) {
case V_33 :
case V_34 :
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ ) {
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x13 + V_15 ,
V_20 [ V_15 ] ) ;
if ( V_14 )
goto V_32;
}
break;
case V_35 :
V_14 = F_7 ( V_10 -> V_43 [ 1 ] , 0x10 , V_20 , 6 ) ;
if ( V_14 )
goto V_32;
break;
default:
break;
}
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x2d , V_21 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x2e , 0x00 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x56 , 0x0d ) ;
if ( V_14 )
goto V_32;
V_14 = F_7 ( V_10 -> V_43 [ 0 ] , 0x01 ,
L_7 , 8 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0x0a , 0x1a ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0x13 , 0x1f ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0x19 , 0x03 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0x1d , 0xb0 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0x2a , 0x72 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0x2d , 0x00 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0x3c , 0x00 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0x3f , 0xf8 ) ;
if ( V_14 )
goto V_32;
V_14 = F_7 ( V_10 -> V_43 [ 0 ] , 0x40 , L_8 , 2 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0xd2 , V_22 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0xd4 , 0x55 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 1 ] , 0xbe , 0x08 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0xb2 , 0x37 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0xd7 , 0x04 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0xf8 , 0x9f ) ;
if ( V_14 )
goto V_32;
return 0 ;
V_32:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 , enum V_44 * V_45 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
struct V_11 * V_12 = & V_2 -> V_13 ;
int V_14 ;
unsigned int V_16 ;
if ( ! V_10 -> V_30 ) {
V_14 = - V_31 ;
goto V_32;
}
* V_45 = 0 ;
switch ( V_12 -> V_23 ) {
case V_33 :
V_14 = F_9 ( V_10 -> V_43 [ 0 ] , 0x62 , & V_16 ) ;
if ( V_14 )
goto V_32;
if ( ! ( V_16 & 0xa0 ) ) {
if ( ( V_16 & 0x0f ) >= 0x09 )
* V_45 = V_46 | V_47 |
V_48 | V_49 |
V_50 ;
else if ( ( V_16 & 0x0f ) >= 0x03 )
* V_45 = V_46 | V_47 ;
}
break;
case V_34 :
V_14 = F_9 ( V_10 -> V_43 [ 2 ] , 0x8b , & V_16 ) ;
if ( V_14 )
goto V_32;
if ( ! ( V_16 & 0x40 ) ) {
if ( ( V_16 & 0x0f ) >= 0x0d )
* V_45 = V_46 | V_47 |
V_48 | V_49 |
V_50 ;
else if ( ( V_16 & 0x0f ) >= 0x0a )
* V_45 = V_46 | V_47 |
V_48 ;
else if ( ( V_16 & 0x0f ) >= 0x07 )
* V_45 = V_46 | V_47 ;
}
break;
case V_35 :
V_14 = F_9 ( V_10 -> V_43 [ 1 ] , 0x85 , & V_16 ) ;
if ( V_14 )
goto V_32;
if ( ! ( V_16 & 0x40 ) ) {
V_14 = F_9 ( V_10 -> V_43 [ 1 ] , 0x89 , & V_16 ) ;
if ( V_14 )
goto V_32;
if ( V_16 & 0x01 )
* V_45 = V_46 | V_47 |
V_48 | V_49 |
V_50 ;
}
break;
default:
V_14 = - V_36 ;
goto V_32;
}
return 0 ;
V_32:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_14 , V_51 , V_52 ;
unsigned int V_16 ;
const struct V_53 * V_54 ;
const char * V_55 = V_56 ;
F_4 ( & V_7 -> V_10 , L_10 ) ;
V_14 = F_9 ( V_10 -> V_43 [ 0 ] , 0xf5 , & V_16 ) ;
if ( V_14 )
goto V_32;
if ( ! ( V_16 & 0x01 ) )
goto V_57;
V_14 = F_11 ( & V_54 , V_55 , & V_7 -> V_10 ) ;
if ( V_14 ) {
F_12 ( & V_7 -> V_10 , L_11 , V_55 ) ;
goto V_32;
}
F_13 ( & V_7 -> V_10 , L_12 , V_55 ) ;
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0xf5 , 0x03 ) ;
if ( V_14 )
goto V_58;
for ( V_52 = V_54 -> V_59 ; V_52 > 0 ; V_52 -= ( V_10 -> V_60 - 1 ) ) {
V_51 = F_14 ( V_10 -> V_60 - 1 , V_52 ) ;
V_14 = F_7 ( V_10 -> V_43 [ 0 ] , 0xf6 ,
& V_54 -> V_61 [ V_54 -> V_59 - V_52 ] , V_51 ) ;
if ( V_14 ) {
F_12 ( & V_7 -> V_10 , L_13 ,
V_14 ) ;
goto V_58;
}
}
F_15 ( V_54 ) ;
V_14 = F_9 ( V_10 -> V_43 [ 0 ] , 0xf8 , & V_16 ) ;
if ( V_14 )
goto V_32;
if ( V_16 & 0x10 ) {
F_12 ( & V_7 -> V_10 , L_14 ) ;
V_14 = - V_36 ;
goto V_32;
}
V_14 = F_6 ( V_10 -> V_43 [ 0 ] , 0xf5 , 0x00 ) ;
if ( V_14 )
goto V_32;
V_57:
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x09 , 0x08 ) ;
if ( V_14 )
goto V_32;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x08 , 0x1d ) ;
if ( V_14 )
goto V_32;
V_10 -> V_30 = true ;
return 0 ;
V_58:
F_15 ( V_54 ) ;
V_32:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = F_3 ( V_7 ) ;
int V_14 ;
F_4 ( & V_7 -> V_10 , L_10 ) ;
V_10 -> V_30 = false ;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x05 , 0x3e ) ;
if ( V_14 )
goto V_32;
return 0 ;
V_32:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_17 ( struct V_6 * V_7 ,
const struct V_62 * V_63 )
{
struct V_64 * V_65 = V_7 -> V_10 . V_66 ;
struct V_9 * V_10 ;
int V_14 ;
unsigned int V_16 ;
static const struct V_67 V_67 = {
. V_68 = 8 ,
. V_69 = 8 ,
} ;
F_4 ( & V_7 -> V_10 , L_10 ) ;
if ( V_65 -> V_2 == NULL ) {
F_12 ( & V_7 -> V_10 , L_15 ) ;
V_14 = - V_36 ;
goto V_32;
}
V_10 = F_18 ( sizeof( * V_10 ) , V_70 ) ;
if ( V_10 == NULL ) {
V_14 = - V_71 ;
goto V_32;
}
if ( V_65 -> V_60 )
V_10 -> V_60 = V_65 -> V_60 ;
else
V_10 -> V_60 = ~ 0 ;
if ( V_65 -> V_72 )
V_10 -> V_42 = V_65 -> V_72 ;
else
V_10 -> V_42 = 25000000 ;
V_10 -> V_7 [ 0 ] = V_7 ;
V_10 -> V_43 [ 0 ] = F_19 ( V_10 -> V_7 [ 0 ] , & V_67 ) ;
if ( F_20 ( V_10 -> V_43 [ 0 ] ) ) {
V_14 = F_21 ( V_10 -> V_43 [ 0 ] ) ;
goto V_73;
}
V_14 = F_9 ( V_10 -> V_43 [ 0 ] , 0xff , & V_16 ) ;
if ( V_14 )
goto V_74;
F_4 ( & V_7 -> V_10 , L_16 , V_16 ) ;
if ( V_16 != 0x03 ) {
V_14 = - V_75 ;
goto V_74;
}
V_10 -> V_7 [ 1 ] = F_22 ( V_7 -> V_76 , 0x1a ) ;
if ( V_10 -> V_7 [ 1 ] == NULL ) {
V_14 = - V_75 ;
F_12 ( & V_7 -> V_10 , L_17 ) ;
if ( V_14 )
goto V_74;
}
V_10 -> V_43 [ 1 ] = F_19 ( V_10 -> V_7 [ 1 ] , & V_67 ) ;
if ( F_20 ( V_10 -> V_43 [ 1 ] ) ) {
V_14 = F_21 ( V_10 -> V_43 [ 1 ] ) ;
goto V_77;
}
F_23 ( V_10 -> V_7 [ 1 ] , V_10 ) ;
V_10 -> V_7 [ 2 ] = F_22 ( V_7 -> V_76 , 0x1c ) ;
if ( V_10 -> V_7 [ 2 ] == NULL ) {
V_14 = - V_75 ;
F_12 ( & V_7 -> V_10 , L_18 ) ;
if ( V_14 )
goto V_78;
}
V_10 -> V_43 [ 2 ] = F_19 ( V_10 -> V_7 [ 2 ] , & V_67 ) ;
if ( F_20 ( V_10 -> V_43 [ 2 ] ) ) {
V_14 = F_21 ( V_10 -> V_43 [ 2 ] ) ;
goto V_79;
}
F_23 ( V_10 -> V_7 [ 2 ] , V_10 ) ;
V_14 = F_6 ( V_10 -> V_43 [ 2 ] , 0x05 , 0x3e ) ;
if ( V_14 )
goto V_79;
memcpy ( & V_10 -> V_80 . V_37 , & V_81 , sizeof( V_10 -> V_80 . V_37 ) ) ;
V_10 -> V_80 . V_8 = V_7 ;
* V_65 -> V_2 = & V_10 -> V_80 ;
F_23 ( V_7 , V_10 ) ;
F_13 ( & V_7 -> V_10 , L_19 ) ;
return 0 ;
V_79:
F_24 ( V_10 -> V_7 [ 2 ] ) ;
V_78:
F_25 ( V_10 -> V_43 [ 1 ] ) ;
V_77:
F_24 ( V_10 -> V_7 [ 1 ] ) ;
V_74:
F_25 ( V_10 -> V_43 [ 0 ] ) ;
V_73:
F_26 ( V_10 ) ;
V_32:
F_4 ( & V_7 -> V_10 , L_9 , V_14 ) ;
return V_14 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = F_3 ( V_7 ) ;
F_4 ( & V_7 -> V_10 , L_10 ) ;
F_25 ( V_10 -> V_43 [ 2 ] ) ;
F_24 ( V_10 -> V_7 [ 2 ] ) ;
F_25 ( V_10 -> V_43 [ 1 ] ) ;
F_24 ( V_10 -> V_7 [ 1 ] ) ;
F_25 ( V_10 -> V_43 [ 0 ] ) ;
F_26 ( V_10 ) ;
return 0 ;
}
