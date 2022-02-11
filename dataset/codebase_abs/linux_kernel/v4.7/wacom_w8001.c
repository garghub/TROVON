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
struct V_18 * V_19 = V_13 -> V_20 ;
unsigned char * V_1 = V_13 -> V_1 ;
unsigned int V_8 , V_9 ;
int V_21 ;
int V_22 = 0 ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
bool V_23 = V_1 [ 0 ] & ( 1 << V_21 ) ;
F_5 ( V_19 , V_21 ) ;
F_6 ( V_19 , V_24 , V_23 ) ;
if ( V_23 ) {
V_8 = ( V_1 [ 6 * V_21 + 1 ] << 7 ) | V_1 [ 6 * V_21 + 2 ] ;
V_9 = ( V_1 [ 6 * V_21 + 3 ] << 7 ) | V_1 [ 6 * V_21 + 4 ] ;
F_3 ( V_13 , & V_8 , & V_9 ) ;
F_7 ( V_19 , V_25 , V_8 ) ;
F_7 ( V_19 , V_26 , V_9 ) ;
V_22 ++ ;
}
}
if ( V_13 -> type != V_27 &&
V_13 -> type != V_28 ) {
V_13 -> type = V_22 == 1 ? V_29 : V_30 ;
F_8 ( V_19 , true ) ;
}
F_9 ( V_19 ) ;
}
static void F_10 ( T_1 * V_1 , struct V_31 * V_32 )
{
memset ( V_32 , 0 , sizeof( * V_32 ) ) ;
V_32 -> V_33 = V_1 [ 1 ] ;
V_32 -> V_34 = V_1 [ 2 ] & 0x7 ;
V_32 -> V_35 = V_1 [ 7 ] ;
V_32 -> V_8 = V_1 [ 3 ] << 9 ;
V_32 -> V_8 |= V_1 [ 4 ] << 2 ;
V_32 -> V_8 |= ( V_1 [ 2 ] >> 5 ) & 0x3 ;
V_32 -> V_9 = V_1 [ 5 ] << 9 ;
V_32 -> V_9 |= V_1 [ 6 ] << 2 ;
V_32 -> V_9 |= ( V_1 [ 2 ] >> 3 ) & 0x3 ;
if ( ! V_32 -> V_8 && ! V_32 -> V_9 ) {
V_32 -> V_8 = 1024 ;
V_32 -> V_9 = 1024 ;
if ( V_32 -> V_33 )
V_32 -> V_8 = V_32 -> V_9 = ( 1 << V_32 -> V_33 ) ;
V_32 -> V_33 = V_36 ;
}
}
static void F_11 ( struct V_13 * V_13 , struct V_2 * V_3 )
{
struct V_18 * V_19 = V_13 -> V_37 ;
switch ( V_13 -> type ) {
case V_28 :
if ( ! V_3 -> V_7 ) {
F_7 ( V_19 , V_38 , 0 ) ;
F_12 ( V_19 , V_39 , 0 ) ;
F_12 ( V_19 , V_40 , 0 ) ;
F_12 ( V_19 , V_41 , 0 ) ;
F_12 ( V_19 , V_28 , 0 ) ;
F_9 ( V_19 ) ;
V_13 -> type = V_27 ;
}
break;
case V_29 :
case V_30 :
V_13 -> type = V_3 -> V_7 ? V_28 : V_27 ;
break;
default:
F_12 ( V_19 , V_41 , V_3 -> V_7 ) ;
break;
}
F_7 ( V_19 , V_42 , V_3 -> V_8 ) ;
F_7 ( V_19 , V_43 , V_3 -> V_9 ) ;
F_7 ( V_19 , V_38 , V_3 -> V_10 ) ;
F_12 ( V_19 , V_39 , V_3 -> V_5 ) ;
F_12 ( V_19 , V_40 , V_3 -> V_6 ) ;
F_12 ( V_19 , V_13 -> type , V_3 -> V_4 ) ;
F_9 ( V_19 ) ;
if ( ! V_3 -> V_4 )
V_13 -> type = V_30 ;
}
static void F_13 ( struct V_13 * V_13 , struct V_2 * V_3 )
{
struct V_18 * V_19 = V_13 -> V_20 ;
unsigned int V_8 = V_3 -> V_8 ;
unsigned int V_9 = V_3 -> V_9 ;
F_3 ( V_13 , & V_8 , & V_9 ) ;
F_7 ( V_19 , V_42 , V_8 ) ;
F_7 ( V_19 , V_43 , V_9 ) ;
F_12 ( V_19 , V_39 , V_3 -> V_5 ) ;
F_9 ( V_19 ) ;
V_13 -> type = V_3 -> V_5 ? V_29 : V_30 ;
}
static T_2 F_14 ( struct V_44 * V_44 ,
unsigned char V_1 , unsigned int V_45 )
{
struct V_13 * V_13 = F_15 ( V_44 ) ;
struct V_2 V_3 ;
unsigned char V_46 ;
V_13 -> V_1 [ V_13 -> V_47 ] = V_1 ;
switch ( V_13 -> V_47 ++ ) {
case 0 :
if ( ( V_1 & V_48 ) != V_49 ) {
F_16 ( L_1 , V_1 ) ;
V_13 -> V_47 = 0 ;
}
break;
case V_50 - 1 :
case V_51 - 1 :
V_46 = V_13 -> V_1 [ 0 ] & V_52 ;
if ( V_46 != V_52 )
break;
if ( V_13 -> V_53 == V_13 -> V_47 ) {
V_13 -> V_47 = 0 ;
if ( V_13 -> type != V_27 &&
V_13 -> type != V_28 ) {
F_2 ( V_13 -> V_1 , & V_3 ) ;
F_13 ( V_13 , & V_3 ) ;
}
}
break;
case V_54 - 1 :
V_46 = V_13 -> V_1 [ 0 ] & V_55 ;
if ( F_17 ( V_46 == V_56 ) )
break;
V_46 = V_13 -> V_1 [ 0 ] & V_52 ;
if ( V_46 == V_52 )
break;
V_13 -> V_47 = 0 ;
F_1 ( V_13 -> V_1 , & V_3 ) ;
F_11 ( V_13 , & V_3 ) ;
break;
case V_57 - 1 :
V_46 = V_13 -> V_1 [ 0 ] & V_58 ;
if ( V_46 == V_52 )
break;
V_13 -> V_47 = 0 ;
memcpy ( V_13 -> V_59 , V_13 -> V_1 , V_60 ) ;
V_13 -> V_61 = V_62 ;
F_18 ( & V_13 -> V_63 ) ;
break;
case V_64 - 1 :
V_13 -> V_47 = 0 ;
F_4 ( V_13 ) ;
break;
default:
if ( ! V_13 -> V_20 && V_13 -> V_47 > V_54 - 1 )
V_13 -> V_47 = 0 ;
}
return V_65 ;
}
static int F_19 ( struct V_13 * V_13 , unsigned char V_66 ,
bool V_67 )
{
int V_68 ;
V_13 -> V_61 = 0 ;
F_20 ( & V_13 -> V_63 ) ;
V_68 = F_21 ( V_13 -> V_44 , V_66 ) ;
if ( V_68 == 0 && V_67 ) {
F_22 ( & V_13 -> V_63 , V_69 ) ;
if ( V_13 -> V_61 != V_62 )
V_68 = - V_70 ;
}
return V_68 ;
}
static int F_23 ( struct V_18 * V_19 )
{
struct V_13 * V_13 = F_24 ( V_19 ) ;
int V_71 ;
V_71 = F_25 ( & V_13 -> V_72 ) ;
if ( V_71 )
return V_71 ;
if ( V_13 -> V_73 ++ == 0 ) {
V_71 = F_19 ( V_13 , V_74 , false ) ;
if ( V_71 )
V_13 -> V_73 -- ;
}
F_26 ( & V_13 -> V_72 ) ;
return V_71 ;
}
static void F_27 ( struct V_18 * V_19 )
{
struct V_13 * V_13 = F_24 ( V_19 ) ;
F_28 ( & V_13 -> V_72 ) ;
if ( -- V_13 -> V_73 == 0 )
F_19 ( V_13 , V_75 , false ) ;
F_26 ( & V_13 -> V_72 ) ;
}
static int F_29 ( struct V_13 * V_13 )
{
int error ;
error = F_19 ( V_13 , V_75 , false ) ;
if ( error )
return error ;
F_30 ( 250 ) ;
return 0 ;
}
static int F_31 ( struct V_13 * V_13 , char * V_76 ,
T_3 V_77 )
{
struct V_18 * V_19 = V_13 -> V_37 ;
struct V_2 V_3 ;
int error ;
error = F_19 ( V_13 , V_78 , true ) ;
if ( error )
return error ;
F_32 ( V_79 , V_19 -> V_80 ) ;
F_32 ( V_81 , V_19 -> V_80 ) ;
F_32 ( V_39 , V_19 -> V_82 ) ;
F_32 ( V_27 , V_19 -> V_82 ) ;
F_32 ( V_28 , V_19 -> V_82 ) ;
F_32 ( V_40 , V_19 -> V_82 ) ;
F_32 ( V_41 , V_19 -> V_82 ) ;
F_32 ( V_83 , V_19 -> V_84 ) ;
F_1 ( V_13 -> V_59 , & V_3 ) ;
V_13 -> V_14 = V_3 . V_8 ;
V_13 -> V_16 = V_3 . V_9 ;
F_33 ( V_19 , V_42 , 0 , V_3 . V_8 , 0 , 0 ) ;
F_33 ( V_19 , V_43 , 0 , V_3 . V_9 , 0 , 0 ) ;
F_34 ( V_19 , V_42 , V_85 ) ;
F_34 ( V_19 , V_43 , V_85 ) ;
F_33 ( V_19 , V_38 , 0 , V_3 . V_10 , 0 , 0 ) ;
if ( V_3 . V_11 && V_3 . V_12 ) {
F_33 ( V_19 , V_86 , 0 , V_3 . V_11 , 0 , 0 ) ;
F_33 ( V_19 , V_87 , 0 , V_3 . V_12 , 0 , 0 ) ;
}
V_13 -> V_88 = 0x90 ;
F_35 ( V_76 , L_2 , V_77 ) ;
return 0 ;
}
static int F_36 ( struct V_13 * V_13 , char * V_76 ,
T_3 V_77 )
{
struct V_18 * V_19 = V_13 -> V_20 ;
struct V_31 V_23 ;
int error ;
error = F_19 ( V_13 , V_89 , true ) ;
if ( error )
return error ;
if ( ! V_13 -> V_59 [ 1 ] )
return - V_90 ;
F_32 ( V_79 , V_19 -> V_80 ) ;
F_32 ( V_81 , V_19 -> V_80 ) ;
F_32 ( V_39 , V_19 -> V_82 ) ;
F_32 ( V_83 , V_19 -> V_84 ) ;
F_10 ( V_13 -> V_59 , & V_23 ) ;
V_13 -> V_15 = V_23 . V_8 ;
V_13 -> V_17 = V_23 . V_9 ;
if ( V_13 -> V_14 && V_13 -> V_16 ) {
V_23 . V_8 = V_13 -> V_14 ;
V_23 . V_9 = V_13 -> V_16 ;
V_23 . V_33 = V_85 ;
}
F_33 ( V_19 , V_42 , 0 , V_23 . V_8 , 0 , 0 ) ;
F_33 ( V_19 , V_43 , 0 , V_23 . V_9 , 0 , 0 ) ;
F_34 ( V_19 , V_42 , V_23 . V_33 ) ;
F_34 ( V_19 , V_43 , V_23 . V_33 ) ;
switch ( V_23 . V_34 ) {
case 0 :
case 2 :
V_13 -> V_53 = V_50 ;
V_13 -> V_88 = 0x93 ;
F_35 ( V_76 , L_3 , V_77 ) ;
break;
case 1 :
case 3 :
case 4 :
V_13 -> V_53 = V_51 ;
F_35 ( V_76 , L_3 , V_77 ) ;
V_13 -> V_88 = 0x9a ;
break;
case 5 :
V_13 -> V_53 = V_64 ;
F_32 ( V_91 , V_19 -> V_82 ) ;
F_37 ( V_19 , 2 , 0 ) ;
F_33 ( V_19 , V_25 ,
0 , V_23 . V_8 , 0 , 0 ) ;
F_33 ( V_19 , V_26 ,
0 , V_23 . V_9 , 0 , 0 ) ;
F_33 ( V_19 , V_92 ,
0 , V_93 , 0 , 0 ) ;
F_35 ( V_76 , L_4 , V_77 ) ;
if ( V_13 -> V_14 && V_13 -> V_16 )
V_13 -> V_88 = 0xE3 ;
else
V_13 -> V_88 = 0xE2 ;
break;
}
F_35 ( V_76 , L_5 , V_77 ) ;
return 0 ;
}
static void F_38 ( struct V_18 * V_19 , struct V_13 * V_13 ,
struct V_44 * V_44 )
{
V_19 -> V_94 = V_13 -> V_94 ;
V_19 -> V_88 . V_95 = V_96 ;
V_19 -> V_88 . V_97 = V_13 -> V_88 ;
V_19 -> V_88 . V_98 = 0x056a ;
V_19 -> V_88 . V_99 = 0x0100 ;
V_19 -> V_100 = F_23 ;
V_19 -> V_101 = F_27 ;
V_19 -> V_19 . V_102 = & V_44 -> V_19 ;
F_39 ( V_19 , V_13 ) ;
}
static void F_40 ( struct V_44 * V_44 )
{
struct V_13 * V_13 = F_15 ( V_44 ) ;
F_41 ( V_44 ) ;
if ( V_13 -> V_37 )
F_42 ( V_13 -> V_37 ) ;
if ( V_13 -> V_20 )
F_42 ( V_13 -> V_20 ) ;
F_43 ( V_13 ) ;
F_44 ( V_44 , NULL ) ;
}
static int F_45 ( struct V_44 * V_44 , struct V_103 * V_104 )
{
struct V_13 * V_13 ;
struct V_18 * V_105 ;
struct V_18 * V_106 ;
char V_76 [ 64 ] ;
int V_71 , V_107 , V_108 ;
V_13 = F_46 ( sizeof( struct V_13 ) , V_109 ) ;
V_105 = F_47 () ;
V_106 = F_47 () ;
if ( ! V_13 || ! V_105 || ! V_106 ) {
V_71 = - V_110 ;
goto V_111;
}
V_13 -> V_44 = V_44 ;
V_13 -> V_37 = V_105 ;
V_13 -> V_20 = V_106 ;
F_48 ( & V_13 -> V_72 ) ;
F_20 ( & V_13 -> V_63 ) ;
snprintf ( V_13 -> V_94 , sizeof( V_13 -> V_94 ) , L_6 , V_44 -> V_94 ) ;
F_44 ( V_44 , V_13 ) ;
V_71 = F_49 ( V_44 , V_104 ) ;
if ( V_71 )
goto V_112;
V_71 = F_29 ( V_13 ) ;
if ( V_71 )
goto V_113;
F_50 ( V_76 , L_7 , sizeof( V_76 ) ) ;
V_107 = F_31 ( V_13 , V_76 , sizeof( V_76 ) ) ;
V_108 = F_36 ( V_13 , V_76 , sizeof( V_76 ) ) ;
if ( V_107 && V_108 ) {
V_71 = - V_90 ;
goto V_113;
}
if ( ! V_107 ) {
F_50 ( V_13 -> V_114 , V_76 , sizeof( V_13 -> V_114 ) ) ;
F_35 ( V_13 -> V_114 , L_8 , sizeof( V_13 -> V_114 ) ) ;
V_105 -> V_115 = V_13 -> V_114 ;
F_38 ( V_105 , V_13 , V_44 ) ;
V_71 = F_51 ( V_13 -> V_37 ) ;
if ( V_71 )
goto V_113;
} else {
F_52 ( V_105 ) ;
V_105 = NULL ;
V_13 -> V_37 = NULL ;
}
if ( ! V_108 ) {
F_50 ( V_13 -> V_116 , V_76 , sizeof( V_13 -> V_116 ) ) ;
F_35 ( V_13 -> V_116 , L_9 ,
sizeof( V_13 -> V_116 ) ) ;
V_106 -> V_115 = V_13 -> V_116 ;
F_38 ( V_106 , V_13 , V_44 ) ;
V_71 = F_51 ( V_13 -> V_20 ) ;
if ( V_71 )
goto V_117;
} else {
F_52 ( V_106 ) ;
V_106 = NULL ;
V_13 -> V_20 = NULL ;
}
return 0 ;
V_117:
if ( V_13 -> V_37 )
F_42 ( V_13 -> V_37 ) ;
V_113:
F_41 ( V_44 ) ;
V_112:
F_44 ( V_44 , NULL ) ;
V_111:
F_52 ( V_105 ) ;
F_52 ( V_106 ) ;
F_43 ( V_13 ) ;
return V_71 ;
}
