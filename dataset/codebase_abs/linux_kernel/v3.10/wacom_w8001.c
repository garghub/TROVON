static void F_1 ( T_1 * V_1 , struct V_2 * V_3 )
{
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_4 = V_1 [ 0 ] & 0x20 ;
V_3 -> V_5 = V_1 [ 0 ] & 0x01 ;
V_3 -> V_6 = V_1 [ 0 ] & 0x02 ;
V_3 -> V_7 = V_1 [ 0 ] & 0x04 ;
V_3 -> V_8 = ( V_1 [ 1 ] & 0x7F ) << 9 ;
V_3 -> V_8 |= ( V_1 [ 2 ] & 0x7F ) << 2 ;
V_3 -> V_8 |= ( V_1 [ 6 ] & 0x60 ) >> 5 ;
V_3 -> V_9 = ( V_1 [ 3 ] & 0x7F ) << 9 ;
V_3 -> V_9 |= ( V_1 [ 4 ] & 0x7F ) << 2 ;
V_3 -> V_9 |= ( V_1 [ 6 ] & 0x18 ) >> 3 ;
V_3 -> V_10 = V_1 [ 5 ] & 0x7F ;
V_3 -> V_10 |= ( V_1 [ 6 ] & 0x07 ) << 7 ;
V_3 -> V_11 = V_1 [ 7 ] & 0x7F ;
V_3 -> V_12 = V_1 [ 8 ] & 0x7F ;
}
static void F_2 ( T_1 * V_1 , struct V_2 * V_3 )
{
V_3 -> V_8 = ( V_1 [ 1 ] << 7 ) | V_1 [ 2 ] ;
V_3 -> V_9 = ( V_1 [ 3 ] << 7 ) | V_1 [ 4 ] ;
V_3 -> V_5 = V_1 [ 0 ] & 0x01 ;
}
static void F_3 ( struct V_13 * V_13 ,
unsigned int * V_8 , unsigned int * V_9 )
{
if ( V_13 -> V_14 && V_13 -> V_15 )
* V_8 = * V_8 * V_13 -> V_14 / V_13 -> V_15 ;
if ( V_13 -> V_16 && V_13 -> V_17 )
* V_9 = * V_9 * V_13 -> V_16 / V_13 -> V_17 ;
}
static void F_4 ( struct V_13 * V_13 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
unsigned char * V_1 = V_13 -> V_1 ;
unsigned int V_8 , V_9 ;
int V_20 ;
int V_21 = 0 ;
for ( V_20 = 0 ; V_20 < 2 ; V_20 ++ ) {
bool V_22 = V_1 [ 0 ] & ( 1 << V_20 ) ;
F_5 ( V_19 , V_20 ) ;
F_6 ( V_19 , V_23 , V_22 ) ;
if ( V_22 ) {
V_8 = ( V_1 [ 6 * V_20 + 1 ] << 7 ) | V_1 [ 6 * V_20 + 2 ] ;
V_9 = ( V_1 [ 6 * V_20 + 3 ] << 7 ) | V_1 [ 6 * V_20 + 4 ] ;
F_3 ( V_13 , & V_8 , & V_9 ) ;
F_7 ( V_19 , V_24 , V_8 ) ;
F_7 ( V_19 , V_25 , V_9 ) ;
V_21 ++ ;
}
}
if ( V_13 -> type != V_26 &&
V_13 -> type != V_27 ) {
V_13 -> type = V_21 == 1 ? V_28 : V_29 ;
F_8 ( V_19 , true ) ;
}
F_9 ( V_19 ) ;
}
static void F_10 ( T_1 * V_1 , struct V_30 * V_31 )
{
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_32 = V_1 [ 1 ] ;
V_31 -> V_33 = V_1 [ 2 ] & 0x7 ;
V_31 -> V_34 = V_1 [ 7 ] ;
V_31 -> V_8 = V_1 [ 3 ] << 9 ;
V_31 -> V_8 |= V_1 [ 4 ] << 2 ;
V_31 -> V_8 |= ( V_1 [ 2 ] >> 5 ) & 0x3 ;
V_31 -> V_9 = V_1 [ 5 ] << 9 ;
V_31 -> V_9 |= V_1 [ 6 ] << 2 ;
V_31 -> V_9 |= ( V_1 [ 2 ] >> 3 ) & 0x3 ;
if ( ! V_31 -> V_8 && ! V_31 -> V_9 ) {
V_31 -> V_8 = 1024 ;
V_31 -> V_9 = 1024 ;
if ( V_31 -> V_32 )
V_31 -> V_8 = V_31 -> V_9 = ( 1 << V_31 -> V_32 ) ;
V_31 -> V_32 = V_35 ;
}
}
static void F_11 ( struct V_13 * V_13 , struct V_2 * V_3 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
switch ( V_13 -> type ) {
case V_27 :
if ( ! V_3 -> V_7 ) {
F_7 ( V_19 , V_36 , 0 ) ;
F_12 ( V_19 , V_37 , 0 ) ;
F_12 ( V_19 , V_38 , 0 ) ;
F_12 ( V_19 , V_39 , 0 ) ;
F_12 ( V_19 , V_27 , 0 ) ;
F_9 ( V_19 ) ;
V_13 -> type = V_26 ;
}
break;
case V_28 :
F_12 ( V_19 , V_37 , 0 ) ;
F_12 ( V_19 , V_28 , 0 ) ;
F_9 ( V_19 ) ;
case V_29 :
V_13 -> type = V_3 -> V_7 ? V_27 : V_26 ;
break;
default:
F_12 ( V_19 , V_39 , V_3 -> V_7 ) ;
break;
}
F_7 ( V_19 , V_40 , V_3 -> V_8 ) ;
F_7 ( V_19 , V_41 , V_3 -> V_9 ) ;
F_7 ( V_19 , V_36 , V_3 -> V_10 ) ;
F_12 ( V_19 , V_37 , V_3 -> V_5 ) ;
F_12 ( V_19 , V_38 , V_3 -> V_6 ) ;
F_12 ( V_19 , V_13 -> type , V_3 -> V_4 ) ;
F_9 ( V_19 ) ;
if ( ! V_3 -> V_4 )
V_13 -> type = V_29 ;
}
static void F_13 ( struct V_13 * V_13 , struct V_2 * V_3 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
unsigned int V_8 = V_3 -> V_8 ;
unsigned int V_9 = V_3 -> V_9 ;
F_3 ( V_13 , & V_8 , & V_9 ) ;
F_7 ( V_19 , V_40 , V_8 ) ;
F_7 ( V_19 , V_41 , V_9 ) ;
F_12 ( V_19 , V_37 , V_3 -> V_5 ) ;
F_12 ( V_19 , V_28 , V_3 -> V_5 ) ;
F_9 ( V_19 ) ;
V_13 -> type = V_3 -> V_5 ? V_28 : V_29 ;
}
static T_2 F_14 ( struct V_42 * V_42 ,
unsigned char V_1 , unsigned int V_43 )
{
struct V_13 * V_13 = F_15 ( V_42 ) ;
struct V_2 V_3 ;
unsigned char V_44 ;
V_13 -> V_1 [ V_13 -> V_45 ] = V_1 ;
switch ( V_13 -> V_45 ++ ) {
case 0 :
if ( ( V_1 & V_46 ) != V_47 ) {
F_16 ( L_1 , V_1 ) ;
V_13 -> V_45 = 0 ;
}
break;
case V_48 - 1 :
case V_49 - 1 :
V_44 = V_13 -> V_1 [ 0 ] & V_50 ;
if ( V_44 != V_50 )
break;
if ( V_13 -> V_51 == V_13 -> V_45 ) {
V_13 -> V_45 = 0 ;
if ( V_13 -> type != V_26 &&
V_13 -> type != V_27 ) {
F_2 ( V_13 -> V_1 , & V_3 ) ;
F_13 ( V_13 , & V_3 ) ;
}
}
break;
case V_52 - 1 :
V_44 = V_13 -> V_1 [ 0 ] & V_53 ;
if ( F_17 ( V_44 == V_54 ) )
break;
V_44 = V_13 -> V_1 [ 0 ] & V_50 ;
if ( V_44 == V_50 )
break;
V_13 -> V_45 = 0 ;
F_1 ( V_13 -> V_1 , & V_3 ) ;
F_11 ( V_13 , & V_3 ) ;
break;
case V_55 - 1 :
V_44 = V_13 -> V_1 [ 0 ] & V_56 ;
if ( V_44 == V_50 )
break;
V_13 -> V_45 = 0 ;
memcpy ( V_13 -> V_57 , V_13 -> V_1 , V_58 ) ;
V_13 -> V_59 = V_60 ;
F_18 ( & V_13 -> V_61 ) ;
break;
case V_62 - 1 :
V_13 -> V_45 = 0 ;
F_4 ( V_13 ) ;
break;
}
return V_63 ;
}
static int F_19 ( struct V_13 * V_13 , unsigned char V_64 ,
bool V_65 )
{
int V_66 ;
V_13 -> V_59 = 0 ;
F_20 ( & V_13 -> V_61 ) ;
V_66 = F_21 ( V_13 -> V_42 , V_64 ) ;
if ( V_66 == 0 && V_65 ) {
F_22 ( & V_13 -> V_61 , V_67 ) ;
if ( V_13 -> V_59 != V_60 )
V_66 = - V_68 ;
}
return V_66 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_13 * V_13 = F_24 ( V_19 ) ;
return F_19 ( V_13 , V_69 , false ) ;
}
static void F_25 ( struct V_18 * V_19 )
{
struct V_13 * V_13 = F_24 ( V_19 ) ;
F_19 ( V_13 , V_70 , false ) ;
}
static int F_26 ( struct V_13 * V_13 )
{
struct V_18 * V_19 = V_13 -> V_19 ;
struct V_2 V_3 ;
struct V_30 V_22 ;
int error ;
error = F_19 ( V_13 , V_70 , false ) ;
if ( error )
return error ;
F_27 ( 250 ) ;
V_19 -> V_71 [ 0 ] = F_28 ( V_72 ) | F_28 ( V_73 ) ;
F_29 ( V_13 -> V_74 , L_2 , sizeof( V_13 -> V_74 ) ) ;
F_30 ( V_75 , V_19 -> V_76 ) ;
error = F_19 ( V_13 , V_77 , true ) ;
if ( ! error ) {
F_30 ( V_37 , V_19 -> V_78 ) ;
F_30 ( V_26 , V_19 -> V_78 ) ;
F_30 ( V_27 , V_19 -> V_78 ) ;
F_30 ( V_38 , V_19 -> V_78 ) ;
F_30 ( V_39 , V_19 -> V_78 ) ;
F_1 ( V_13 -> V_57 , & V_3 ) ;
V_13 -> V_14 = V_3 . V_8 ;
V_13 -> V_16 = V_3 . V_9 ;
F_31 ( V_19 , V_40 , 0 , V_3 . V_8 , 0 , 0 ) ;
F_31 ( V_19 , V_41 , 0 , V_3 . V_9 , 0 , 0 ) ;
F_32 ( V_19 , V_40 , V_79 ) ;
F_32 ( V_19 , V_41 , V_79 ) ;
F_31 ( V_19 , V_36 , 0 , V_3 . V_10 , 0 , 0 ) ;
if ( V_3 . V_11 && V_3 . V_12 ) {
F_31 ( V_19 , V_80 , 0 , V_3 . V_11 , 0 , 0 ) ;
F_31 ( V_19 , V_81 , 0 , V_3 . V_12 , 0 , 0 ) ;
}
V_13 -> V_82 = 0x90 ;
F_29 ( V_13 -> V_74 , L_3 , sizeof( V_13 -> V_74 ) ) ;
}
error = F_19 ( V_13 , V_83 , true ) ;
if ( ! error && V_13 -> V_57 [ 1 ] ) {
F_30 ( V_37 , V_19 -> V_78 ) ;
F_30 ( V_28 , V_19 -> V_78 ) ;
F_10 ( V_13 -> V_57 , & V_22 ) ;
V_13 -> V_15 = V_22 . V_8 ;
V_13 -> V_17 = V_22 . V_9 ;
if ( V_13 -> V_14 && V_13 -> V_16 ) {
V_22 . V_8 = V_13 -> V_14 ;
V_22 . V_9 = V_13 -> V_16 ;
V_22 . V_32 = V_79 ;
}
F_31 ( V_19 , V_40 , 0 , V_22 . V_8 , 0 , 0 ) ;
F_31 ( V_19 , V_41 , 0 , V_22 . V_9 , 0 , 0 ) ;
F_32 ( V_19 , V_40 , V_22 . V_32 ) ;
F_32 ( V_19 , V_41 , V_22 . V_32 ) ;
switch ( V_22 . V_33 ) {
case 0 :
case 2 :
V_13 -> V_51 = V_48 ;
V_13 -> V_82 = 0x93 ;
F_29 ( V_13 -> V_74 , L_4 , sizeof( V_13 -> V_74 ) ) ;
break;
case 1 :
case 3 :
case 4 :
V_13 -> V_51 = V_49 ;
F_29 ( V_13 -> V_74 , L_4 , sizeof( V_13 -> V_74 ) ) ;
V_13 -> V_82 = 0x9a ;
break;
case 5 :
V_13 -> V_51 = V_62 ;
F_33 ( V_19 , 2 , 0 ) ;
F_31 ( V_19 , V_24 ,
0 , V_22 . V_8 , 0 , 0 ) ;
F_31 ( V_19 , V_25 ,
0 , V_22 . V_9 , 0 , 0 ) ;
F_31 ( V_19 , V_84 ,
0 , V_85 , 0 , 0 ) ;
F_29 ( V_13 -> V_74 , L_5 , sizeof( V_13 -> V_74 ) ) ;
if ( V_13 -> V_14 && V_13 -> V_16 )
V_13 -> V_82 = 0xE3 ;
else
V_13 -> V_82 = 0xE2 ;
break;
}
}
F_29 ( V_13 -> V_74 , L_6 , sizeof( V_13 -> V_74 ) ) ;
return 0 ;
}
static void F_34 ( struct V_42 * V_42 )
{
struct V_13 * V_13 = F_15 ( V_42 ) ;
F_35 ( V_42 ) ;
F_36 ( V_13 -> V_19 ) ;
F_37 ( V_13 ) ;
F_38 ( V_42 , NULL ) ;
}
static int F_39 ( struct V_42 * V_42 , struct V_86 * V_87 )
{
struct V_13 * V_13 ;
struct V_18 * V_18 ;
int V_88 ;
V_13 = F_40 ( sizeof( struct V_13 ) , V_89 ) ;
V_18 = F_41 () ;
if ( ! V_13 || ! V_18 ) {
V_88 = - V_90 ;
goto V_91;
}
V_13 -> V_42 = V_42 ;
V_13 -> V_19 = V_18 ;
F_20 ( & V_13 -> V_61 ) ;
snprintf ( V_13 -> V_92 , sizeof( V_13 -> V_92 ) , L_7 , V_42 -> V_92 ) ;
F_38 ( V_42 , V_13 ) ;
V_88 = F_42 ( V_42 , V_87 ) ;
if ( V_88 )
goto V_93;
V_88 = F_26 ( V_13 ) ;
if ( V_88 )
goto V_94;
V_18 -> V_74 = V_13 -> V_74 ;
V_18 -> V_92 = V_13 -> V_92 ;
V_18 -> V_82 . V_95 = V_13 -> V_82 ;
V_18 -> V_82 . V_96 = V_97 ;
V_18 -> V_82 . V_98 = 0x056a ;
V_18 -> V_82 . V_99 = 0x0100 ;
V_18 -> V_19 . V_100 = & V_42 -> V_19 ;
V_18 -> V_101 = F_23 ;
V_18 -> V_102 = F_25 ;
F_43 ( V_18 , V_13 ) ;
V_88 = F_44 ( V_13 -> V_19 ) ;
if ( V_88 )
goto V_94;
return 0 ;
V_94:
F_35 ( V_42 ) ;
V_93:
F_38 ( V_42 , NULL ) ;
V_91:
F_45 ( V_18 ) ;
F_37 ( V_13 ) ;
return V_88 ;
}
