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
if ( V_23 ) {
V_8 = ( V_1 [ 6 * V_21 + 1 ] << 7 ) | V_1 [ 6 * V_21 + 2 ] ;
V_9 = ( V_1 [ 6 * V_21 + 3 ] << 7 ) | V_1 [ 6 * V_21 + 4 ] ;
F_3 ( V_13 , & V_8 , & V_9 ) ;
F_6 ( V_19 , V_24 , V_8 ) ;
F_6 ( V_19 , V_25 , V_9 ) ;
V_22 ++ ;
}
}
if ( V_13 -> type != V_26 &&
V_13 -> type != V_27 ) {
V_13 -> type = V_22 == 1 ? V_28 : V_29 ;
F_7 ( V_19 , true ) ;
}
F_8 ( V_19 ) ;
}
static void F_9 ( T_1 * V_1 , struct V_30 * V_31 )
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
static void F_10 ( struct V_13 * V_13 , struct V_2 * V_3 )
{
struct V_18 * V_19 = V_13 -> V_36 ;
switch ( V_13 -> type ) {
case V_27 :
if ( ! V_3 -> V_7 ) {
F_6 ( V_19 , V_37 , 0 ) ;
F_11 ( V_19 , V_38 , 0 ) ;
F_11 ( V_19 , V_39 , 0 ) ;
F_11 ( V_19 , V_40 , 0 ) ;
F_11 ( V_19 , V_27 , 0 ) ;
F_8 ( V_19 ) ;
V_13 -> type = V_26 ;
}
break;
case V_28 :
case V_29 :
V_13 -> type = V_3 -> V_7 ? V_27 : V_26 ;
break;
default:
F_11 ( V_19 , V_40 , V_3 -> V_7 ) ;
break;
}
F_6 ( V_19 , V_41 , V_3 -> V_8 ) ;
F_6 ( V_19 , V_42 , V_3 -> V_9 ) ;
F_6 ( V_19 , V_37 , V_3 -> V_10 ) ;
F_11 ( V_19 , V_38 , V_3 -> V_5 ) ;
F_11 ( V_19 , V_39 , V_3 -> V_6 ) ;
F_11 ( V_19 , V_13 -> type , V_3 -> V_4 ) ;
F_8 ( V_19 ) ;
if ( ! V_3 -> V_4 )
V_13 -> type = V_29 ;
}
static void F_12 ( struct V_13 * V_13 , struct V_2 * V_3 )
{
struct V_18 * V_19 = V_13 -> V_20 ;
unsigned int V_8 = V_3 -> V_8 ;
unsigned int V_9 = V_3 -> V_9 ;
F_3 ( V_13 , & V_8 , & V_9 ) ;
F_6 ( V_19 , V_41 , V_8 ) ;
F_6 ( V_19 , V_42 , V_9 ) ;
F_11 ( V_19 , V_38 , V_3 -> V_5 ) ;
F_8 ( V_19 ) ;
V_13 -> type = V_3 -> V_5 ? V_28 : V_29 ;
}
static T_2 F_13 ( struct V_43 * V_43 ,
unsigned char V_1 , unsigned int V_44 )
{
struct V_13 * V_13 = F_14 ( V_43 ) ;
struct V_2 V_3 ;
unsigned char V_45 ;
V_13 -> V_1 [ V_13 -> V_46 ] = V_1 ;
switch ( V_13 -> V_46 ++ ) {
case 0 :
if ( ( V_1 & V_47 ) != V_48 ) {
F_15 ( L_1 , V_1 ) ;
V_13 -> V_46 = 0 ;
}
break;
case V_49 - 1 :
case V_50 - 1 :
V_45 = V_13 -> V_1 [ 0 ] & V_51 ;
if ( V_45 != V_51 )
break;
if ( V_13 -> V_52 == V_13 -> V_46 ) {
V_13 -> V_46 = 0 ;
if ( V_13 -> type != V_26 &&
V_13 -> type != V_27 ) {
F_2 ( V_13 -> V_1 , & V_3 ) ;
F_12 ( V_13 , & V_3 ) ;
}
}
break;
case V_53 - 1 :
V_45 = V_13 -> V_1 [ 0 ] & V_54 ;
if ( F_16 ( V_45 == V_55 ) )
break;
V_45 = V_13 -> V_1 [ 0 ] & V_51 ;
if ( V_45 == V_51 )
break;
V_13 -> V_46 = 0 ;
F_1 ( V_13 -> V_1 , & V_3 ) ;
F_10 ( V_13 , & V_3 ) ;
break;
case V_56 - 1 :
V_45 = V_13 -> V_1 [ 0 ] & V_57 ;
if ( V_45 == V_51 )
break;
V_13 -> V_46 = 0 ;
memcpy ( V_13 -> V_58 , V_13 -> V_1 , V_59 ) ;
V_13 -> V_60 = V_61 ;
F_17 ( & V_13 -> V_62 ) ;
break;
case V_63 - 1 :
V_13 -> V_46 = 0 ;
F_4 ( V_13 ) ;
break;
}
return V_64 ;
}
static int F_18 ( struct V_13 * V_13 , unsigned char V_65 ,
bool V_66 )
{
int V_67 ;
V_13 -> V_60 = 0 ;
F_19 ( & V_13 -> V_62 ) ;
V_67 = F_20 ( V_13 -> V_43 , V_65 ) ;
if ( V_67 == 0 && V_66 ) {
F_21 ( & V_13 -> V_62 , V_68 ) ;
if ( V_13 -> V_60 != V_61 )
V_67 = - V_69 ;
}
return V_67 ;
}
static int F_22 ( struct V_18 * V_19 )
{
struct V_13 * V_13 = F_23 ( V_19 ) ;
int V_70 ;
V_70 = F_24 ( & V_13 -> V_71 ) ;
if ( V_70 )
return V_70 ;
if ( V_13 -> V_72 ++ == 0 ) {
V_70 = F_18 ( V_13 , V_73 , false ) ;
if ( V_70 )
V_13 -> V_72 -- ;
}
F_25 ( & V_13 -> V_71 ) ;
return V_70 ;
}
static void F_26 ( struct V_18 * V_19 )
{
struct V_13 * V_13 = F_23 ( V_19 ) ;
F_27 ( & V_13 -> V_71 ) ;
if ( -- V_13 -> V_72 == 0 )
F_18 ( V_13 , V_74 , false ) ;
F_25 ( & V_13 -> V_71 ) ;
}
static int F_28 ( struct V_13 * V_13 )
{
int error ;
error = F_18 ( V_13 , V_74 , false ) ;
if ( error )
return error ;
F_29 ( 250 ) ;
return 0 ;
}
static int F_30 ( struct V_13 * V_13 , char * V_75 ,
T_3 V_76 )
{
struct V_18 * V_19 = V_13 -> V_36 ;
struct V_2 V_3 ;
int error ;
error = F_18 ( V_13 , V_77 , true ) ;
if ( error )
return error ;
F_31 ( V_78 , V_19 -> V_79 ) ;
F_31 ( V_80 , V_19 -> V_79 ) ;
F_31 ( V_38 , V_19 -> V_81 ) ;
F_31 ( V_26 , V_19 -> V_81 ) ;
F_31 ( V_27 , V_19 -> V_81 ) ;
F_31 ( V_39 , V_19 -> V_81 ) ;
F_31 ( V_40 , V_19 -> V_81 ) ;
F_31 ( V_82 , V_19 -> V_83 ) ;
F_1 ( V_13 -> V_58 , & V_3 ) ;
V_13 -> V_14 = V_3 . V_8 ;
V_13 -> V_16 = V_3 . V_9 ;
F_32 ( V_19 , V_41 , 0 , V_3 . V_8 , 0 , 0 ) ;
F_32 ( V_19 , V_42 , 0 , V_3 . V_9 , 0 , 0 ) ;
F_33 ( V_19 , V_41 , V_84 ) ;
F_33 ( V_19 , V_42 , V_84 ) ;
F_32 ( V_19 , V_37 , 0 , V_3 . V_10 , 0 , 0 ) ;
if ( V_3 . V_11 && V_3 . V_12 ) {
F_32 ( V_19 , V_85 , 0 , V_3 . V_11 , 0 , 0 ) ;
F_32 ( V_19 , V_86 , 0 , V_3 . V_12 , 0 , 0 ) ;
}
V_13 -> V_87 = 0x90 ;
F_34 ( V_75 , L_2 , V_76 ) ;
return 0 ;
}
static int F_35 ( struct V_13 * V_13 , char * V_75 ,
T_3 V_76 )
{
struct V_18 * V_19 = V_13 -> V_20 ;
struct V_30 V_23 ;
int error ;
error = F_18 ( V_13 , V_88 , true ) ;
if ( error )
return error ;
if ( ! V_13 -> V_58 [ 1 ] )
return - V_89 ;
F_31 ( V_78 , V_19 -> V_79 ) ;
F_31 ( V_80 , V_19 -> V_79 ) ;
F_31 ( V_38 , V_19 -> V_81 ) ;
F_31 ( V_82 , V_19 -> V_83 ) ;
F_9 ( V_13 -> V_58 , & V_23 ) ;
V_13 -> V_15 = V_23 . V_8 ;
V_13 -> V_17 = V_23 . V_9 ;
if ( V_13 -> V_14 && V_13 -> V_16 ) {
V_23 . V_8 = V_13 -> V_14 ;
V_23 . V_9 = V_13 -> V_16 ;
V_23 . V_32 = V_84 ;
}
F_32 ( V_19 , V_41 , 0 , V_23 . V_8 , 0 , 0 ) ;
F_32 ( V_19 , V_42 , 0 , V_23 . V_9 , 0 , 0 ) ;
F_33 ( V_19 , V_41 , V_23 . V_32 ) ;
F_33 ( V_19 , V_42 , V_23 . V_32 ) ;
switch ( V_23 . V_33 ) {
case 0 :
case 2 :
V_13 -> V_52 = V_49 ;
V_13 -> V_87 = 0x93 ;
F_34 ( V_75 , L_3 , V_76 ) ;
break;
case 1 :
case 3 :
case 4 :
V_13 -> V_52 = V_50 ;
F_34 ( V_75 , L_3 , V_76 ) ;
V_13 -> V_87 = 0x9a ;
break;
case 5 :
V_13 -> V_52 = V_63 ;
F_31 ( V_90 , V_19 -> V_81 ) ;
F_36 ( V_19 , 2 , 0 ) ;
F_32 ( V_19 , V_24 ,
0 , V_23 . V_8 , 0 , 0 ) ;
F_32 ( V_19 , V_25 ,
0 , V_23 . V_9 , 0 , 0 ) ;
F_34 ( V_75 , L_4 , V_76 ) ;
if ( V_13 -> V_14 && V_13 -> V_16 )
V_13 -> V_87 = 0xE3 ;
else
V_13 -> V_87 = 0xE2 ;
break;
}
F_34 ( V_75 , L_5 , V_76 ) ;
return 0 ;
}
static void F_37 ( struct V_18 * V_19 , struct V_13 * V_13 ,
struct V_43 * V_43 )
{
V_19 -> V_91 = V_13 -> V_91 ;
V_19 -> V_87 . V_92 = V_93 ;
V_19 -> V_87 . V_94 = V_13 -> V_87 ;
V_19 -> V_87 . V_95 = 0x056a ;
V_19 -> V_87 . V_96 = 0x0100 ;
V_19 -> V_97 = F_22 ;
V_19 -> V_98 = F_26 ;
V_19 -> V_19 . V_99 = & V_43 -> V_19 ;
F_38 ( V_19 , V_13 ) ;
}
static void F_39 ( struct V_43 * V_43 )
{
struct V_13 * V_13 = F_14 ( V_43 ) ;
F_40 ( V_43 ) ;
if ( V_13 -> V_36 )
F_41 ( V_13 -> V_36 ) ;
if ( V_13 -> V_20 )
F_41 ( V_13 -> V_20 ) ;
F_42 ( V_13 ) ;
F_43 ( V_43 , NULL ) ;
}
static int F_44 ( struct V_43 * V_43 , struct V_100 * V_101 )
{
struct V_13 * V_13 ;
struct V_18 * V_102 ;
struct V_18 * V_103 ;
char V_75 [ 64 ] ;
int V_70 , V_104 , V_105 ;
V_13 = F_45 ( sizeof( struct V_13 ) , V_106 ) ;
V_102 = F_46 () ;
V_103 = F_46 () ;
if ( ! V_13 || ! V_102 || ! V_103 ) {
V_70 = - V_107 ;
goto V_108;
}
V_13 -> V_43 = V_43 ;
V_13 -> V_36 = V_102 ;
V_13 -> V_20 = V_103 ;
F_47 ( & V_13 -> V_71 ) ;
F_19 ( & V_13 -> V_62 ) ;
snprintf ( V_13 -> V_91 , sizeof( V_13 -> V_91 ) , L_6 , V_43 -> V_91 ) ;
F_43 ( V_43 , V_13 ) ;
V_70 = F_48 ( V_43 , V_101 ) ;
if ( V_70 )
goto V_109;
V_70 = F_28 ( V_13 ) ;
if ( V_70 )
goto V_110;
F_49 ( V_75 , L_7 , sizeof( V_75 ) ) ;
V_104 = F_30 ( V_13 , V_75 , sizeof( V_75 ) ) ;
V_105 = F_35 ( V_13 , V_75 , sizeof( V_75 ) ) ;
if ( V_104 && V_105 ) {
V_70 = - V_89 ;
goto V_110;
}
if ( ! V_104 ) {
F_49 ( V_13 -> V_111 , V_75 , sizeof( V_13 -> V_111 ) ) ;
F_34 ( V_13 -> V_111 , L_8 , sizeof( V_13 -> V_111 ) ) ;
V_102 -> V_112 = V_13 -> V_111 ;
F_37 ( V_102 , V_13 , V_43 ) ;
V_70 = F_50 ( V_13 -> V_36 ) ;
if ( V_70 )
goto V_110;
} else {
F_51 ( V_102 ) ;
V_102 = NULL ;
V_13 -> V_36 = NULL ;
}
if ( ! V_105 ) {
F_49 ( V_13 -> V_113 , V_75 , sizeof( V_13 -> V_113 ) ) ;
F_34 ( V_13 -> V_113 , L_9 ,
sizeof( V_13 -> V_113 ) ) ;
V_103 -> V_112 = V_13 -> V_113 ;
F_37 ( V_103 , V_13 , V_43 ) ;
V_70 = F_50 ( V_13 -> V_20 ) ;
if ( V_70 )
goto V_114;
} else {
F_51 ( V_103 ) ;
V_103 = NULL ;
V_13 -> V_20 = NULL ;
}
return 0 ;
V_114:
if ( V_13 -> V_36 )
F_41 ( V_13 -> V_36 ) ;
V_110:
F_40 ( V_43 ) ;
V_109:
F_43 ( V_43 , NULL ) ;
V_108:
F_51 ( V_102 ) ;
F_51 ( V_103 ) ;
F_42 ( V_13 ) ;
return V_70 ;
}
