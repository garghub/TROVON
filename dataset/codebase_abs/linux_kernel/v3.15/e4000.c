static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_1 , V_9 ) ;
V_6 = F_3 ( V_4 -> V_10 , 0x02 , 0x40 ) ;
V_6 = F_3 ( V_4 -> V_10 , 0x00 , 0x01 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x06 , 0x00 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x7a , 0x96 ) ;
if ( V_6 )
goto V_11;
V_6 = F_4 ( V_4 -> V_10 , 0x7e , L_2 , 2 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x82 , 0x00 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x24 , 0x05 ) ;
if ( V_6 )
goto V_11;
V_6 = F_4 ( V_4 -> V_10 , 0x87 , L_3 , 2 ) ;
if ( V_6 )
goto V_11;
V_6 = F_4 ( V_4 -> V_10 , 0x9f , L_4 , 2 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x2d , 0x1f ) ;
if ( V_6 )
goto V_11;
V_6 = F_4 ( V_4 -> V_10 , 0x70 , L_5 , 2 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x1a , 0x17 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x1f , 0x1a ) ;
if ( V_6 )
goto V_11;
V_4 -> V_12 = true ;
V_11:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_9 , V_6 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_1 , V_9 ) ;
V_4 -> V_12 = false ;
V_6 = F_3 ( V_4 -> V_10 , 0x00 , 0x00 ) ;
if ( V_6 )
goto V_11;
V_11:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_9 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_13 * V_14 = & V_2 -> V_15 ;
int V_6 , V_16 , V_17 ;
unsigned int V_18 , V_19 ;
T_1 V_20 ;
T_2 V_21 [ 5 ] , V_22 [ 4 ] , V_23 [ 4 ] ;
F_2 ( & V_4 -> V_7 -> V_8 ,
L_7 ,
V_9 , V_14 -> V_24 , V_14 -> V_25 ,
V_14 -> V_26 ) ;
V_6 = F_3 ( V_4 -> V_10 , 0x1a , 0x00 ) ;
if ( V_6 )
goto V_11;
for ( V_16 = 0 ; V_16 < F_7 ( V_27 ) ; V_16 ++ ) {
if ( V_14 -> V_25 <= V_27 [ V_16 ] . V_28 )
break;
}
if ( V_16 == F_7 ( V_27 ) ) {
V_6 = - V_29 ;
goto V_11;
}
V_20 = 1ull * V_14 -> V_25 * V_27 [ V_16 ] . V_30 ;
V_18 = F_8 ( V_20 , V_4 -> clock , & V_19 ) ;
V_17 = F_9 ( 0x10000ULL * V_19 , V_4 -> clock ) ;
V_21 [ 0 ] = V_18 ;
V_21 [ 1 ] = ( V_17 >> 0 ) & 0xff ;
V_21 [ 2 ] = ( V_17 >> 8 ) & 0xff ;
V_21 [ 3 ] = 0x00 ;
V_21 [ 4 ] = V_27 [ V_16 ] . div ;
F_2 ( & V_4 -> V_7 -> V_8 ,
L_8 ,
V_9 , V_20 , V_21 [ 0 ] , V_17 ) ;
V_6 = F_4 ( V_4 -> V_10 , 0x09 , V_21 , 5 ) ;
if ( V_6 )
goto V_11;
for ( V_16 = 0 ; V_16 < F_7 ( V_31 ) ; V_16 ++ ) {
if ( V_14 -> V_25 <= V_31 [ V_16 ] . V_28 )
break;
}
if ( V_16 == F_7 ( V_31 ) ) {
V_6 = - V_29 ;
goto V_11;
}
V_6 = F_3 ( V_4 -> V_10 , 0x10 , V_31 [ V_16 ] . V_32 ) ;
if ( V_6 )
goto V_11;
for ( V_16 = 0 ; V_16 < F_7 ( V_33 ) ; V_16 ++ ) {
if ( V_14 -> V_26 <= V_33 [ V_16 ] . V_28 )
break;
}
if ( V_16 == F_7 ( V_33 ) ) {
V_6 = - V_29 ;
goto V_11;
}
V_21 [ 0 ] = V_33 [ V_16 ] . V_34 ;
V_21 [ 1 ] = V_33 [ V_16 ] . V_35 ;
V_6 = F_4 ( V_4 -> V_10 , 0x11 , V_21 , 2 ) ;
if ( V_6 )
goto V_11;
for ( V_16 = 0 ; V_16 < F_7 ( V_36 ) ; V_16 ++ ) {
if ( V_14 -> V_25 <= V_36 [ V_16 ] . V_28 )
break;
}
if ( V_16 == F_7 ( V_36 ) ) {
V_6 = - V_29 ;
goto V_11;
}
V_6 = F_3 ( V_4 -> V_10 , 0x07 , V_36 [ V_16 ] . V_37 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x78 , V_36 [ V_16 ] . V_38 ) ;
if ( V_6 )
goto V_11;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
if ( V_16 == 0 )
V_6 = F_4 ( V_4 -> V_10 , 0x15 , L_9 , 3 ) ;
else if ( V_16 == 1 )
V_6 = F_4 ( V_4 -> V_10 , 0x15 , L_10 , 2 ) ;
else if ( V_16 == 2 )
V_6 = F_4 ( V_4 -> V_10 , 0x15 , L_11 , 1 ) ;
else
V_6 = F_4 ( V_4 -> V_10 , 0x16 , L_12 , 1 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x29 , 0x01 ) ;
if ( V_6 )
goto V_11;
V_6 = F_10 ( V_4 -> V_10 , 0x2a , V_21 , 3 ) ;
if ( V_6 )
goto V_11;
V_22 [ V_16 ] = ( ( ( V_21 [ 2 ] >> 0 ) & 0x3 ) << 6 ) | ( V_21 [ 0 ] & 0x3f ) ;
V_23 [ V_16 ] = ( ( ( V_21 [ 2 ] >> 4 ) & 0x3 ) << 6 ) | ( V_21 [ 1 ] & 0x3f ) ;
}
F_11 ( V_23 [ 2 ] , V_23 [ 3 ] ) ;
F_11 ( V_22 [ 2 ] , V_22 [ 3 ] ) ;
V_6 = F_4 ( V_4 -> V_10 , 0x50 , V_23 , 4 ) ;
if ( V_6 )
goto V_11;
V_6 = F_4 ( V_4 -> V_10 , 0x60 , V_22 , 4 ) ;
if ( V_6 )
goto V_11;
V_6 = F_3 ( V_4 -> V_10 , 0x1a , 0x17 ) ;
if ( V_6 )
goto V_11;
V_11:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_9 , V_6 ) ;
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 , T_3 * V_25 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_1 , V_9 ) ;
* V_25 = 0 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_2 V_39 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_13 ,
V_9 , V_4 -> V_40 -> V_41 . V_32 ,
V_4 -> V_40 -> V_32 , V_4 -> V_42 -> V_41 . V_32 ,
V_4 -> V_42 -> V_32 ) ;
if ( V_4 -> V_40 -> V_32 && V_4 -> V_43 -> V_41 . V_32 )
V_39 = 0x17 ;
else if ( V_4 -> V_40 -> V_32 )
V_39 = 0x19 ;
else if ( V_4 -> V_43 -> V_41 . V_32 )
V_39 = 0x16 ;
else
V_39 = 0x10 ;
V_6 = F_3 ( V_4 -> V_10 , 0x1a , V_39 ) ;
if ( V_6 )
goto V_11;
if ( V_4 -> V_40 -> V_32 == false ) {
V_6 = F_3 ( V_4 -> V_10 , 0x14 , V_4 -> V_42 -> V_32 ) ;
if ( V_6 )
goto V_11;
}
V_11:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_9 , V_6 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_2 V_39 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_14 ,
V_9 , V_4 -> V_44 -> V_41 . V_32 ,
V_4 -> V_44 -> V_32 , V_4 -> V_45 -> V_41 . V_32 ,
V_4 -> V_45 -> V_32 ) ;
if ( V_4 -> V_44 -> V_32 )
V_39 = 0x15 ;
else
V_39 = 0x14 ;
V_6 = F_3 ( V_4 -> V_10 , 0x20 , V_39 ) ;
if ( V_6 )
goto V_11;
if ( V_4 -> V_44 -> V_32 == false ) {
V_6 = F_3 ( V_4 -> V_10 , 0x15 , V_4 -> V_45 -> V_32 ) ;
if ( V_6 )
goto V_11;
}
V_11:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_9 , V_6 ) ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
T_2 V_21 [ 2 ] ;
T_2 V_39 ;
F_2 ( & V_4 -> V_7 -> V_8 , L_15 ,
V_9 , V_4 -> V_43 -> V_41 . V_32 ,
V_4 -> V_43 -> V_32 , V_4 -> V_46 -> V_41 . V_32 ,
V_4 -> V_46 -> V_32 ) ;
if ( V_4 -> V_43 -> V_32 && V_4 -> V_40 -> V_41 . V_32 )
V_39 = 0x17 ;
else if ( V_4 -> V_40 -> V_41 . V_32 )
V_39 = 0x19 ;
else if ( V_4 -> V_43 -> V_32 )
V_39 = 0x16 ;
else
V_39 = 0x10 ;
V_6 = F_3 ( V_4 -> V_10 , 0x1a , V_39 ) ;
if ( V_6 )
goto V_11;
if ( V_4 -> V_43 -> V_32 == false ) {
V_21 [ 0 ] = V_47 [ V_4 -> V_46 -> V_32 ] . V_48 ;
V_21 [ 1 ] = V_47 [ V_4 -> V_46 -> V_32 ] . V_49 ;
V_6 = F_4 ( V_4 -> V_10 , 0x16 , V_21 , 2 ) ;
if ( V_6 )
goto V_11;
}
V_11:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_9 , V_6 ) ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 ;
unsigned int V_50 ;
V_6 = F_17 ( V_4 -> V_10 , 0x07 , & V_50 ) ;
if ( V_6 )
goto V_11;
V_4 -> V_51 -> V_32 = ( V_50 & 0x01 ) ;
V_11:
if ( V_6 )
F_2 ( & V_4 -> V_7 -> V_8 , L_6 , V_9 , V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_52 * V_53 )
{
struct V_3 * V_4 = F_19 ( V_53 -> V_54 , struct V_3 , V_55 ) ;
int V_6 ;
if ( V_4 -> V_12 == false )
return 0 ;
switch ( V_53 -> V_56 ) {
case V_57 :
V_6 = F_16 ( V_4 -> V_2 ) ;
break;
default:
F_2 ( & V_4 -> V_7 -> V_8 , L_16 ,
V_9 , V_53 -> V_56 , V_53 -> V_58 ) ;
V_6 = - V_29 ;
}
return V_6 ;
}
static int F_20 ( struct V_52 * V_53 )
{
struct V_3 * V_4 = F_19 ( V_53 -> V_54 , struct V_3 , V_55 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_13 * V_14 = & V_2 -> V_15 ;
int V_6 ;
if ( V_4 -> V_12 == false )
return 0 ;
switch ( V_53 -> V_56 ) {
case V_59 :
case V_60 :
V_14 -> V_26 = V_4 -> V_61 -> V_32 ;
V_6 = F_6 ( V_4 -> V_2 ) ;
break;
case V_62 :
case V_63 :
V_6 = F_13 ( V_4 -> V_2 ) ;
break;
case V_64 :
case V_65 :
V_6 = F_14 ( V_4 -> V_2 ) ;
break;
case V_66 :
case V_67 :
V_6 = F_15 ( V_4 -> V_2 ) ;
break;
default:
F_2 ( & V_4 -> V_7 -> V_8 , L_16 ,
V_9 , V_53 -> V_56 , V_53 -> V_58 ) ;
V_6 = - V_29 ;
}
return V_6 ;
}
static int F_21 ( struct V_68 * V_7 ,
const struct V_69 * V_56 )
{
struct V_70 * V_71 = V_7 -> V_8 . V_72 ;
struct V_1 * V_2 = V_71 -> V_2 ;
struct V_3 * V_4 ;
int V_6 ;
unsigned int V_50 ;
static const struct V_73 V_73 = {
. V_74 = 8 ,
. V_75 = 8 ,
. V_76 = 0xff ,
} ;
V_4 = F_22 ( sizeof( struct V_3 ) , V_77 ) ;
if ( ! V_4 ) {
V_6 = - V_78 ;
F_23 ( & V_7 -> V_8 , L_17 , V_79 ) ;
goto V_11;
}
V_4 -> clock = V_71 -> clock ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 = V_71 -> V_2 ;
V_4 -> V_10 = F_24 ( V_7 , & V_73 ) ;
if ( F_25 ( V_4 -> V_10 ) ) {
V_6 = F_26 ( V_4 -> V_10 ) ;
goto V_11;
}
V_6 = F_17 ( V_4 -> V_10 , 0x02 , & V_50 ) ;
if ( V_6 )
goto V_11;
F_2 ( & V_4 -> V_7 -> V_8 , L_18 , V_9 , V_50 ) ;
if ( V_50 != 0x40 ) {
V_6 = - V_80 ;
goto V_11;
}
V_6 = F_3 ( V_4 -> V_10 , 0x00 , 0x00 ) ;
if ( V_6 )
goto V_11;
#if F_27 ( V_81 )
F_28 ( & V_4 -> V_55 , 9 ) ;
V_4 -> V_82 = F_29 ( & V_4 -> V_55 , & V_83 ,
V_59 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_61 = F_29 ( & V_4 -> V_55 , & V_83 ,
V_60 , 4300000 , 11000000 , 100000 , 4300000 ) ;
F_30 ( 2 , & V_4 -> V_82 , 0 , false ) ;
V_4 -> V_40 = F_29 ( & V_4 -> V_55 , & V_83 ,
V_62 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_42 = F_29 ( & V_4 -> V_55 , & V_83 ,
V_63 , 0 , 15 , 1 , 10 ) ;
F_30 ( 2 , & V_4 -> V_40 , 0 , false ) ;
V_4 -> V_44 = F_29 ( & V_4 -> V_55 , & V_83 ,
V_64 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_45 = F_29 ( & V_4 -> V_55 , & V_83 ,
V_65 , 0 , 1 , 1 , 1 ) ;
F_30 ( 2 , & V_4 -> V_44 , 0 , false ) ;
V_4 -> V_43 = F_29 ( & V_4 -> V_55 , & V_83 ,
V_66 , 0 , 1 , 1 , 1 ) ;
V_4 -> V_46 = F_29 ( & V_4 -> V_55 , & V_83 ,
V_67 , 0 , 54 , 1 , 0 ) ;
F_30 ( 2 , & V_4 -> V_43 , 0 , false ) ;
V_4 -> V_51 = F_29 ( & V_4 -> V_55 , & V_83 ,
V_57 , 0 , 1 , 1 , 0 ) ;
if ( V_4 -> V_55 . error ) {
V_6 = V_4 -> V_55 . error ;
F_23 ( & V_4 -> V_7 -> V_8 , L_19 ) ;
F_31 ( & V_4 -> V_55 ) ;
goto V_11;
}
V_4 -> V_84 . V_85 = & V_4 -> V_55 ;
#endif
F_32 ( & V_4 -> V_7 -> V_8 ,
L_20 ,
V_79 ) ;
V_2 -> V_5 = V_4 ;
memcpy ( & V_2 -> V_86 . V_87 , & V_88 ,
sizeof( struct V_89 ) ) ;
F_33 ( & V_4 -> V_84 , V_7 ) ;
F_34 ( V_7 , & V_4 -> V_84 ) ;
return 0 ;
V_11:
if ( V_6 ) {
F_2 ( & V_7 -> V_8 , L_6 , V_9 , V_6 ) ;
F_35 ( V_4 ) ;
}
return V_6 ;
}
static int F_36 ( struct V_68 * V_7 )
{
struct V_90 * V_84 = F_37 ( V_7 ) ;
struct V_3 * V_4 = F_19 ( V_84 , struct V_3 , V_84 ) ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_2 ( & V_7 -> V_8 , L_1 , V_9 ) ;
#if F_27 ( V_81 )
F_31 ( & V_4 -> V_55 ) ;
#endif
memset ( & V_2 -> V_86 . V_87 , 0 , sizeof( struct V_89 ) ) ;
V_2 -> V_5 = NULL ;
F_35 ( V_4 ) ;
return 0 ;
}
