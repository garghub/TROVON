static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_1 ) ;
V_6 = F_3 ( V_4 -> V_9 , 0x02 , 0x40 ) ;
V_6 = F_3 ( V_4 -> V_9 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x06 , 0x00 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x7a , 0x96 ) ;
if ( V_6 )
goto V_10;
V_6 = F_4 ( V_4 -> V_9 , 0x7e , L_2 , 2 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x82 , 0x00 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x24 , 0x05 ) ;
if ( V_6 )
goto V_10;
V_6 = F_4 ( V_4 -> V_9 , 0x87 , L_3 , 2 ) ;
if ( V_6 )
goto V_10;
V_6 = F_4 ( V_4 -> V_9 , 0x9f , L_4 , 2 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x2d , 0x1f ) ;
if ( V_6 )
goto V_10;
V_6 = F_4 ( V_4 -> V_9 , 0x70 , L_5 , 2 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x1a , 0x17 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x1f , 0x1a ) ;
if ( V_6 )
goto V_10;
V_4 -> V_11 = true ;
V_10:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_1 ) ;
V_4 -> V_11 = false ;
V_6 = F_3 ( V_4 -> V_9 , 0x00 , 0x00 ) ;
if ( V_6 )
goto V_10;
V_10:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_12 * V_13 = & V_2 -> V_14 ;
int V_6 , V_15 , V_16 ;
unsigned int V_17 , V_18 ;
T_1 V_19 ;
T_2 V_20 [ 5 ] , V_21 [ 4 ] , V_22 [ 4 ] ;
F_2 ( & V_4 -> V_7 -> V_8 ,
L_7 ,
V_13 -> V_23 , V_13 -> V_24 , V_13 -> V_25 ) ;
V_6 = F_3 ( V_4 -> V_9 , 0x1a , 0x00 ) ;
if ( V_6 )
goto V_10;
for ( V_15 = 0 ; V_15 < F_7 ( V_26 ) ; V_15 ++ ) {
if ( V_13 -> V_24 <= V_26 [ V_15 ] . V_27 )
break;
}
if ( V_15 == F_7 ( V_26 ) ) {
V_6 = - V_28 ;
goto V_10;
}
V_19 = 1ull * V_13 -> V_24 * V_26 [ V_15 ] . V_29 ;
V_17 = F_8 ( V_19 , V_4 -> clock , & V_18 ) ;
V_16 = F_9 ( 0x10000ULL * V_18 , V_4 -> clock ) ;
V_20 [ 0 ] = V_17 ;
V_20 [ 1 ] = ( V_16 >> 0 ) & 0xff ;
V_20 [ 2 ] = ( V_16 >> 8 ) & 0xff ;
V_20 [ 3 ] = 0x00 ;
V_20 [ 4 ] = V_26 [ V_15 ] . div ;
F_2 ( & V_4 -> V_7 -> V_8 , L_8 ,
V_19 , V_20 [ 0 ] , V_16 ) ;
V_6 = F_4 ( V_4 -> V_9 , 0x09 , V_20 , 5 ) ;
if ( V_6 )
goto V_10;
for ( V_15 = 0 ; V_15 < F_7 ( V_30 ) ; V_15 ++ ) {
if ( V_13 -> V_24 <= V_30 [ V_15 ] . V_27 )
break;
}
if ( V_15 == F_7 ( V_30 ) ) {
V_6 = - V_28 ;
goto V_10;
}
V_6 = F_3 ( V_4 -> V_9 , 0x10 , V_30 [ V_15 ] . V_31 ) ;
if ( V_6 )
goto V_10;
for ( V_15 = 0 ; V_15 < F_7 ( V_32 ) ; V_15 ++ ) {
if ( V_13 -> V_25 <= V_32 [ V_15 ] . V_27 )
break;
}
if ( V_15 == F_7 ( V_32 ) ) {
V_6 = - V_28 ;
goto V_10;
}
V_20 [ 0 ] = V_32 [ V_15 ] . V_33 ;
V_20 [ 1 ] = V_32 [ V_15 ] . V_34 ;
V_6 = F_4 ( V_4 -> V_9 , 0x11 , V_20 , 2 ) ;
if ( V_6 )
goto V_10;
for ( V_15 = 0 ; V_15 < F_7 ( V_35 ) ; V_15 ++ ) {
if ( V_13 -> V_24 <= V_35 [ V_15 ] . V_27 )
break;
}
if ( V_15 == F_7 ( V_35 ) ) {
V_6 = - V_28 ;
goto V_10;
}
V_6 = F_3 ( V_4 -> V_9 , 0x07 , V_35 [ V_15 ] . V_36 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x78 , V_35 [ V_15 ] . V_37 ) ;
if ( V_6 )
goto V_10;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
if ( V_15 == 0 )
V_6 = F_4 ( V_4 -> V_9 , 0x15 , L_9 , 3 ) ;
else if ( V_15 == 1 )
V_6 = F_4 ( V_4 -> V_9 , 0x15 , L_10 , 2 ) ;
else if ( V_15 == 2 )
V_6 = F_4 ( V_4 -> V_9 , 0x15 , L_11 , 1 ) ;
else
V_6 = F_4 ( V_4 -> V_9 , 0x16 , L_12 , 1 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x29 , 0x01 ) ;
if ( V_6 )
goto V_10;
V_6 = F_10 ( V_4 -> V_9 , 0x2a , V_20 , 3 ) ;
if ( V_6 )
goto V_10;
V_21 [ V_15 ] = ( ( ( V_20 [ 2 ] >> 0 ) & 0x3 ) << 6 ) | ( V_20 [ 0 ] & 0x3f ) ;
V_22 [ V_15 ] = ( ( ( V_20 [ 2 ] >> 4 ) & 0x3 ) << 6 ) | ( V_20 [ 1 ] & 0x3f ) ;
}
F_11 ( V_22 [ 2 ] , V_22 [ 3 ] ) ;
F_11 ( V_21 [ 2 ] , V_21 [ 3 ] ) ;
V_6 = F_4 ( V_4 -> V_9 , 0x50 , V_22 , 4 ) ;
if ( V_6 )
goto V_10;
V_6 = F_4 ( V_4 -> V_9 , 0x60 , V_21 , 4 ) ;
if ( V_6 )
goto V_10;
V_6 = F_3 ( V_4 -> V_9 , 0x1a , 0x17 ) ;
if ( V_6 )
goto V_10;
V_10:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 , T_3 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_1 ) ;
* V_24 = 0 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_2 V_38 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_13 ,
V_4 -> V_39 -> V_40 . V_31 , V_4 -> V_39 -> V_31 ,
V_4 -> V_41 -> V_40 . V_31 , V_4 -> V_41 -> V_31 ) ;
if ( V_4 -> V_39 -> V_31 && V_4 -> V_42 -> V_40 . V_31 )
V_38 = 0x17 ;
else if ( V_4 -> V_39 -> V_31 )
V_38 = 0x19 ;
else if ( V_4 -> V_42 -> V_40 . V_31 )
V_38 = 0x16 ;
else
V_38 = 0x10 ;
V_6 = F_3 ( V_4 -> V_9 , 0x1a , V_38 ) ;
if ( V_6 )
goto V_10;
if ( V_4 -> V_39 -> V_31 == false ) {
V_6 = F_3 ( V_4 -> V_9 , 0x14 , V_4 -> V_41 -> V_31 ) ;
if ( V_6 )
goto V_10;
}
V_10:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_2 V_38 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_14 ,
V_4 -> V_43 -> V_40 . V_31 , V_4 -> V_43 -> V_31 ,
V_4 -> V_44 -> V_40 . V_31 , V_4 -> V_44 -> V_31 ) ;
if ( V_4 -> V_43 -> V_31 )
V_38 = 0x15 ;
else
V_38 = 0x14 ;
V_6 = F_3 ( V_4 -> V_9 , 0x20 , V_38 ) ;
if ( V_6 )
goto V_10;
if ( V_4 -> V_43 -> V_31 == false ) {
V_6 = F_3 ( V_4 -> V_9 , 0x15 , V_4 -> V_44 -> V_31 ) ;
if ( V_6 )
goto V_10;
}
V_10:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_2 V_20 [ 2 ] ;
T_2 V_38 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_15 ,
V_4 -> V_42 -> V_40 . V_31 , V_4 -> V_42 -> V_31 ,
V_4 -> V_45 -> V_40 . V_31 , V_4 -> V_45 -> V_31 ) ;
if ( V_4 -> V_42 -> V_31 && V_4 -> V_39 -> V_40 . V_31 )
V_38 = 0x17 ;
else if ( V_4 -> V_39 -> V_40 . V_31 )
V_38 = 0x19 ;
else if ( V_4 -> V_42 -> V_31 )
V_38 = 0x16 ;
else
V_38 = 0x10 ;
V_6 = F_3 ( V_4 -> V_9 , 0x1a , V_38 ) ;
if ( V_6 )
goto V_10;
if ( V_4 -> V_42 -> V_31 == false ) {
V_20 [ 0 ] = V_46 [ V_4 -> V_45 -> V_31 ] . V_47 ;
V_20 [ 1 ] = V_46 [ V_4 -> V_45 -> V_31 ] . V_48 ;
V_6 = F_4 ( V_4 -> V_9 , 0x16 , V_20 , 2 ) ;
if ( V_6 )
goto V_10;
}
V_10:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
unsigned int V_49 ;
V_6 = F_17 ( V_4 -> V_9 , 0x07 , & V_49 ) ;
if ( V_6 )
goto V_10;
V_4 -> V_50 -> V_31 = ( V_49 & 0x01 ) ;
V_10:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_51 * V_52 )
{
struct V_3 * V_4 = F_19 ( V_52 -> V_53 , struct V_3 , V_54 ) ;
int V_6 ;
if ( ! V_4 -> V_11 )
return 0 ;
switch ( V_52 -> V_55 ) {
case V_56 :
V_6 = F_16 ( V_4 -> V_2 ) ;
break;
default:
F_2 ( & V_4 -> V_7 -> V_8 , L_16 ,
V_52 -> V_55 , V_52 -> V_57 ) ;
V_6 = - V_28 ;
}
return V_6 ;
}
static int F_20 ( struct V_51 * V_52 )
{
struct V_3 * V_4 = F_19 ( V_52 -> V_53 , struct V_3 , V_54 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_12 * V_13 = & V_2 -> V_14 ;
int V_6 ;
if ( ! V_4 -> V_11 )
return 0 ;
switch ( V_52 -> V_55 ) {
case V_58 :
case V_59 :
V_13 -> V_25 = V_4 -> V_60 -> V_31 ;
V_6 = F_6 ( V_4 -> V_2 ) ;
break;
case V_61 :
case V_62 :
V_6 = F_13 ( V_4 -> V_2 ) ;
break;
case V_63 :
case V_64 :
V_6 = F_14 ( V_4 -> V_2 ) ;
break;
case V_65 :
case V_66 :
V_6 = F_15 ( V_4 -> V_2 ) ;
break;
default:
F_2 ( & V_4 -> V_7 -> V_8 , L_16 ,
V_52 -> V_55 , V_52 -> V_57 ) ;
V_6 = - V_28 ;
}
return V_6 ;
}
static int F_21 ( struct V_67 * V_7 ,
const struct V_68 * V_55 )
{
struct V_69 * V_70 = V_7 -> V_8 . V_71 ;
struct V_1 * V_2 = V_70 -> V_2 ;
struct V_3 * V_4 ;
int V_6 ;
unsigned int V_49 ;
static const struct V_72 V_72 = {
. V_73 = 8 ,
. V_74 = 8 ,
. V_75 = 0xff ,
} ;
V_4 = F_22 ( sizeof( struct V_3 ) , V_76 ) ;
if ( ! V_4 ) {
V_6 = - V_77 ;
F_23 ( & V_7 -> V_8 , L_17 ) ;
goto V_10;
}
V_4 -> clock = V_70 -> clock ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 = V_70 -> V_2 ;
V_4 -> V_9 = F_24 ( V_7 , & V_72 ) ;
if ( F_25 ( V_4 -> V_9 ) ) {
V_6 = F_26 ( V_4 -> V_9 ) ;
goto V_10;
}
V_6 = F_17 ( V_4 -> V_9 , 0x02 , & V_49 ) ;
if ( V_6 )
goto V_10;
F_2 ( & V_4 -> V_7 -> V_8 , L_18 , V_49 ) ;
if ( V_49 != 0x40 ) {
V_6 = - V_78 ;
goto V_10;
}
V_6 = F_3 ( V_4 -> V_9 , 0x00 , 0x00 ) ;
if ( V_6 )
goto V_10;
#if F_27 ( V_79 )
F_28 ( & V_4 -> V_54 , 9 ) ;
V_4 -> V_80 = F_29 ( & V_4 -> V_54 , & V_81 ,
V_58 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_60 = F_29 ( & V_4 -> V_54 , & V_81 ,
V_59 , 4300000 , 11000000 , 100000 , 4300000 ) ;
F_30 ( 2 , & V_4 -> V_80 , 0 , false ) ;
V_4 -> V_39 = F_29 ( & V_4 -> V_54 , & V_81 ,
V_61 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_41 = F_29 ( & V_4 -> V_54 , & V_81 ,
V_62 , 0 , 15 , 1 , 10 ) ;
F_30 ( 2 , & V_4 -> V_39 , 0 , false ) ;
V_4 -> V_43 = F_29 ( & V_4 -> V_54 , & V_81 ,
V_63 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_44 = F_29 ( & V_4 -> V_54 , & V_81 ,
V_64 , 0 , 1 , 1 , 1 ) ;
F_30 ( 2 , & V_4 -> V_43 , 0 , false ) ;
V_4 -> V_42 = F_29 ( & V_4 -> V_54 , & V_81 ,
V_65 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_45 = F_29 ( & V_4 -> V_54 , & V_81 ,
V_66 , 0 , 54 , 1 , 0 ) ;
F_30 ( 2 , & V_4 -> V_42 , 0 , false ) ;
V_4 -> V_50 = F_29 ( & V_4 -> V_54 , & V_81 ,
V_56 , 0 , 1 , 1 , 0 ) ;
if ( V_4 -> V_54 . error ) {
V_6 = V_4 -> V_54 . error ;
F_23 ( & V_4 -> V_7 -> V_8 , L_19 ) ;
F_31 ( & V_4 -> V_54 ) ;
goto V_10;
}
V_4 -> V_82 . V_83 = & V_4 -> V_54 ;
#endif
F_32 ( & V_4 -> V_7 -> V_8 , L_20 ) ;
V_2 -> V_5 = V_4 ;
memcpy ( & V_2 -> V_84 . V_85 , & V_86 ,
sizeof( struct V_87 ) ) ;
F_33 ( & V_4 -> V_82 , V_7 ) ;
F_34 ( V_7 , & V_4 -> V_82 ) ;
return 0 ;
V_10:
if ( V_6 ) {
F_2 ( & V_7 -> V_8 , L_6 , V_6 ) ;
F_35 ( V_4 ) ;
}
return V_6 ;
}
static int F_36 ( struct V_67 * V_7 )
{
struct V_88 * V_82 = F_37 ( V_7 ) ;
struct V_3 * V_4 = F_19 ( V_82 , struct V_3 , V_82 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_2 ( & V_7 -> V_8 , L_1 ) ;
#if F_27 ( V_79 )
F_31 ( & V_4 -> V_54 ) ;
#endif
memset ( & V_2 -> V_84 . V_85 , 0 , sizeof( struct V_87 ) ) ;
V_2 -> V_5 = NULL ;
F_35 ( V_4 ) ;
return 0 ;
}
