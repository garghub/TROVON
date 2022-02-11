static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_5 = 1000 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , enum V_6 * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
struct V_13 * V_14 = & V_2 -> V_15 ;
int V_16 ;
unsigned int V_17 ;
if ( ! V_12 -> V_18 ) {
V_16 = - V_19 ;
goto V_20;
}
switch ( V_14 -> V_21 ) {
case V_22 :
V_16 = F_4 ( V_12 -> V_23 [ 0 ] , 0x7f , & V_17 ) ;
if ( V_16 )
goto V_20;
if ( ( V_17 & 0x0f ) >= 0x09 )
* V_7 = V_24 | V_25 |
V_26 | V_27 | V_28 ;
else
* V_7 = 0 ;
break;
case V_29 :
V_16 = F_4 ( V_12 -> V_23 [ 2 ] , 0x92 , & V_17 ) ;
if ( V_16 )
goto V_20;
if ( ( V_17 & 0x0f ) >= 0x0d )
* V_7 = V_24 | V_25 |
V_26 | V_27 | V_28 ;
else if ( ( V_17 & 0x0f ) >= 0x0a )
* V_7 = V_24 | V_25 |
V_26 ;
else if ( ( V_17 & 0x0f ) >= 0x07 )
* V_7 = V_24 | V_25 ;
else
* V_7 = 0 ;
break;
case V_30 :
V_16 = F_4 ( V_12 -> V_23 [ 1 ] , 0x84 , & V_17 ) ;
if ( V_16 )
goto V_20;
if ( ( V_17 & 0x0f ) >= 0x08 )
* V_7 = V_24 | V_25 |
V_26 | V_27 | V_28 ;
else
* V_7 = 0 ;
break;
default:
V_16 = - V_31 ;
goto V_20;
}
return 0 ;
V_20:
F_5 ( & V_9 -> V_12 , L_1 , V_16 ) ;
return V_16 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
struct V_13 * V_14 = & V_2 -> V_15 ;
int V_16 , V_32 ;
unsigned int V_17 ;
T_1 V_33 ;
T_2 V_34 [ 3 ] , V_35 , V_36 , * V_37 ;
T_2 V_38 , V_39 , V_40 ;
T_2 V_41 ;
F_5 ( & V_9 -> V_12 ,
L_2 ,
V_14 -> V_21 , V_14 -> V_42 , V_14 -> V_43 ,
V_14 -> V_44 , V_14 -> V_45 , V_14 -> V_46 , V_14 -> V_47 ) ;
if ( ! V_12 -> V_18 ) {
V_16 = - V_19 ;
goto V_20;
}
switch ( V_14 -> V_21 ) {
case V_22 :
V_35 = 0x02 ;
V_38 = 0x00 ;
V_39 = 0x1f ;
V_40 = 0x0a ;
V_41 = 0x48 ;
break;
case V_29 :
V_35 = 0x03 ;
V_38 = 0xf6 ;
V_39 = 0x01 ;
V_40 = 0x09 ;
V_41 = 0x46 ;
break;
case V_30 :
V_35 = 0x04 ;
V_38 = 0x00 ;
V_39 = 0x17 ;
V_40 = 0x09 ;
V_41 = 0x48 ;
break;
default:
V_16 = - V_31 ;
goto V_20;
}
switch ( V_14 -> V_21 ) {
case V_22 :
case V_29 :
switch ( V_14 -> V_44 ) {
case 5000000 :
V_37 = L_3 ;
V_36 = 0x03 ;
break;
case 6000000 :
V_37 = L_4 ;
V_36 = 0x02 ;
break;
case 7000000 :
V_37 = L_5 ;
V_36 = 0x01 ;
break;
case 8000000 :
V_37 = L_6 ;
V_36 = 0x00 ;
break;
default:
V_16 = - V_31 ;
goto V_20;
}
break;
case V_30 :
V_37 = NULL ;
V_36 = 0x00 ;
break;
default:
break;
}
if ( V_2 -> V_48 . V_49 . V_50 ) {
V_16 = V_2 -> V_48 . V_49 . V_50 ( V_2 ) ;
if ( V_16 )
goto V_20;
}
if ( V_2 -> V_48 . V_49 . V_51 ) {
V_16 = V_2 -> V_48 . V_49 . V_51 ( V_2 , & V_33 ) ;
if ( V_16 )
goto V_20;
F_5 ( & V_9 -> V_12 , L_7 , V_33 ) ;
} else {
V_16 = - V_31 ;
goto V_20;
}
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x00 , 0x66 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x01 , 0x00 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x02 , 0x01 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x03 , V_35 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x04 , V_36 ) ;
if ( V_16 )
goto V_20;
V_17 = F_8 ( ( V_52 ) V_33 * 0x1000000 , V_12 -> V_53 ) ;
V_34 [ 0 ] = ( V_17 >> 16 ) & 0xff ;
V_34 [ 1 ] = ( V_17 >> 8 ) & 0xff ;
V_34 [ 2 ] = ( V_17 >> 0 ) & 0xff ;
for ( V_32 = 0 ; V_32 < 3 ; V_32 ++ ) {
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x10 + V_32 , V_34 [ V_32 ] ) ;
if ( V_16 )
goto V_20;
}
if ( V_37 ) {
for ( V_32 = 0 ; V_32 < 7 ; V_32 ++ ) {
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x13 + V_32 ,
V_37 [ V_32 ] ) ;
if ( V_16 )
goto V_20;
}
}
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0xb4 , V_38 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0xcd , V_39 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0xd4 , V_40 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0xd6 , V_41 ) ;
if ( V_16 )
goto V_20;
switch ( V_14 -> V_21 ) {
case V_22 :
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0x07 , 0x26 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0x00 , 0xba ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0x01 , 0x13 ) ;
if ( V_16 )
goto V_20;
break;
case V_29 :
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x2b , 0x13 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x4f , 0x05 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 1 ] , 0xf6 , 0x05 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x32 , V_14 -> V_47 ) ;
if ( V_16 )
goto V_20;
break;
case V_30 :
break;
default:
break;
}
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0xf8 , 0x9f ) ;
if ( V_16 )
goto V_20;
return 0 ;
V_20:
F_5 ( & V_9 -> V_12 , L_1 , V_16 ) ;
return V_16 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
int V_16 , V_54 , V_55 ;
unsigned int V_17 ;
const struct V_56 * V_56 ;
const char * V_57 = V_58 ;
F_5 ( & V_9 -> V_12 , L_8 ) ;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x05 , 0x00 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x0b , 0x00 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x0c , 0x00 ) ;
if ( V_16 )
goto V_20;
V_16 = F_4 ( V_12 -> V_23 [ 0 ] , 0xf5 , & V_17 ) ;
if ( V_16 )
goto V_20;
if ( ! ( V_17 & 0x01 ) )
goto V_59;
V_16 = F_10 ( & V_56 , V_57 , & V_9 -> V_12 ) ;
if ( V_16 ) {
F_11 ( & V_9 -> V_12 , L_9 , V_57 ) ;
goto V_20;
}
F_12 ( & V_9 -> V_12 , L_10 , V_57 ) ;
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0xf5 , 0x03 ) ;
if ( V_16 )
goto V_60;
for ( V_55 = V_56 -> V_61 ; V_55 > 0 ; V_55 -= ( V_12 -> V_62 - 1 ) ) {
V_54 = F_13 ( V_12 -> V_62 - 1 , V_55 ) ;
V_16 = F_14 ( V_12 -> V_23 [ 0 ] , 0xf6 ,
& V_56 -> V_63 [ V_56 -> V_61 - V_55 ] ,
V_54 ) ;
if ( V_16 ) {
F_11 ( & V_9 -> V_12 , L_11 ,
V_16 ) ;
goto V_60;
}
}
V_16 = F_4 ( V_12 -> V_23 [ 0 ] , 0xf8 , & V_17 ) ;
if ( V_16 )
goto V_60;
if ( V_17 & 0x10 ) {
V_16 = - V_31 ;
F_11 ( & V_9 -> V_12 , L_12 ) ;
goto V_60;
}
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0xf5 , 0x00 ) ;
if ( V_16 )
goto V_60;
F_15 ( V_56 ) ;
V_59:
switch ( V_12 -> V_64 ) {
case V_65 :
V_17 = 0x1d ;
break;
case V_66 :
V_17 = 0x00 ;
break;
default:
V_16 = - V_31 ;
goto V_20;
}
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x08 , V_17 ) ;
if ( V_16 )
goto V_20;
switch ( V_12 -> V_67 ) {
case V_68 :
V_17 = 0xe3 ;
break;
case V_69 :
V_17 = 0xe1 ;
break;
default:
V_16 = - V_31 ;
goto V_20;
}
V_16 = F_7 ( V_12 -> V_23 [ 0 ] , 0xd9 , V_17 ) ;
if ( V_16 )
goto V_20;
V_12 -> V_18 = true ;
return 0 ;
V_60:
F_15 ( V_56 ) ;
V_20:
F_5 ( & V_9 -> V_12 , L_1 , V_16 ) ;
return V_16 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = F_3 ( V_9 ) ;
int V_16 ;
F_5 ( & V_9 -> V_12 , L_8 ) ;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x0c , 0x30 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x0b , 0x30 ) ;
if ( V_16 )
goto V_20;
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x05 , 0x3e ) ;
if ( V_16 )
goto V_20;
return 0 ;
V_20:
F_5 ( & V_9 -> V_12 , L_1 , V_16 ) ;
return V_16 ;
}
static struct V_1 * F_17 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_3 ( V_9 ) ;
F_5 ( & V_9 -> V_12 , L_8 ) ;
return & V_12 -> V_2 ;
}
static int F_18 ( struct V_8 * V_9 ,
const struct V_70 * V_71 )
{
struct V_72 * V_73 = V_9 -> V_12 . V_74 ;
struct V_11 * V_12 ;
int V_16 ;
unsigned int V_17 ;
static const struct V_75 V_75 = {
. V_76 = 8 ,
. V_77 = 8 ,
} ;
F_5 ( & V_9 -> V_12 , L_8 ) ;
V_12 = F_19 ( sizeof( * V_12 ) , V_78 ) ;
if ( ! V_12 ) {
V_16 = - V_79 ;
goto V_20;
}
V_12 -> V_62 = V_73 -> V_80 ? V_73 -> V_80 : ~ 0 ;
V_12 -> V_53 = V_73 -> V_81 ;
V_12 -> V_64 = V_73 -> V_64 ;
V_12 -> V_67 = V_73 -> V_82 ;
V_12 -> V_9 [ 0 ] = V_9 ;
V_12 -> V_23 [ 0 ] = F_20 ( V_12 -> V_9 [ 0 ] , & V_75 ) ;
if ( F_21 ( V_12 -> V_23 [ 0 ] ) ) {
V_16 = F_22 ( V_12 -> V_23 [ 0 ] ) ;
goto V_83;
}
V_12 -> V_9 [ 1 ] = F_23 ( V_9 -> V_84 , 0x1a ) ;
if ( ! V_12 -> V_9 [ 1 ] ) {
V_16 = - V_85 ;
F_11 ( & V_9 -> V_12 , L_13 ) ;
if ( V_16 )
goto V_86;
}
V_12 -> V_23 [ 1 ] = F_20 ( V_12 -> V_9 [ 1 ] , & V_75 ) ;
if ( F_21 ( V_12 -> V_23 [ 1 ] ) ) {
V_16 = F_22 ( V_12 -> V_23 [ 1 ] ) ;
goto V_87;
}
F_24 ( V_12 -> V_9 [ 1 ] , V_12 ) ;
V_12 -> V_9 [ 2 ] = F_23 ( V_9 -> V_84 , 0x1c ) ;
if ( ! V_12 -> V_9 [ 2 ] ) {
V_16 = - V_85 ;
F_11 ( & V_9 -> V_12 , L_14 ) ;
if ( V_16 )
goto V_88;
}
V_12 -> V_23 [ 2 ] = F_20 ( V_12 -> V_9 [ 2 ] , & V_75 ) ;
if ( F_21 ( V_12 -> V_23 [ 2 ] ) ) {
V_16 = F_22 ( V_12 -> V_23 [ 2 ] ) ;
goto V_89;
}
F_24 ( V_12 -> V_9 [ 2 ] , V_12 ) ;
V_16 = F_4 ( V_12 -> V_23 [ 2 ] , 0xff , & V_17 ) ;
if ( V_16 )
goto V_90;
F_5 ( & V_9 -> V_12 , L_15 , V_17 ) ;
if ( V_17 != 0x02 ) {
V_16 = - V_85 ;
goto V_90;
}
V_16 = F_7 ( V_12 -> V_23 [ 2 ] , 0x05 , 0x3e ) ;
if ( V_16 )
goto V_90;
memcpy ( & V_12 -> V_2 . V_48 , & V_91 , sizeof( struct V_92 ) ) ;
V_12 -> V_2 . V_10 = V_9 ;
* V_73 -> V_2 = & V_12 -> V_2 ;
F_24 ( V_9 , V_12 ) ;
V_73 -> V_93 = F_17 ;
F_12 ( & V_9 -> V_12 , L_16 ) ;
return 0 ;
V_90:
F_25 ( V_12 -> V_23 [ 2 ] ) ;
V_89:
F_26 ( V_12 -> V_9 [ 2 ] ) ;
V_88:
F_25 ( V_12 -> V_23 [ 1 ] ) ;
V_87:
F_26 ( V_12 -> V_9 [ 1 ] ) ;
V_86:
F_25 ( V_12 -> V_23 [ 0 ] ) ;
V_83:
F_27 ( V_12 ) ;
V_20:
F_5 ( & V_9 -> V_12 , L_1 , V_16 ) ;
return V_16 ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_11 * V_12 = F_3 ( V_9 ) ;
F_5 ( & V_9 -> V_12 , L_8 ) ;
F_25 ( V_12 -> V_23 [ 2 ] ) ;
F_26 ( V_12 -> V_9 [ 2 ] ) ;
F_25 ( V_12 -> V_23 [ 1 ] ) ;
F_26 ( V_12 -> V_9 [ 1 ] ) ;
F_25 ( V_12 -> V_23 [ 0 ] ) ;
F_27 ( V_12 ) ;
return 0 ;
}
