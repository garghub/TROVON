static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned char V_4 ;
if ( 1 != F_2 ( V_2 , & V_4 , 1 ) )
return - V_5 ;
if ( V_4 == 0xff )
return 0 ;
if ( V_4 == 0xfe )
return 1 ;
* V_3 = V_4 ;
return 1 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 * V_3 )
{
unsigned char V_6 [ 2 ] ;
T_2 V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 , V_6 , sizeof( V_6 ) ) ;
if ( V_8 != 2 )
return - V_5 ;
if ( V_6 [ 1 ] == 0xff )
return 0 ;
V_7 =
( ( V_6 [ 0 ] & 0x01 ) ? 0x0020 : 0 ) |
( ( V_6 [ 0 ] & 0x02 ) ? 0x0010 : 0 ) |
( ( V_6 [ 0 ] & 0x04 ) ? 0x0008 : 0 ) |
( ( V_6 [ 0 ] & 0x08 ) ? 0x0004 : 0 ) |
( ( V_6 [ 0 ] & 0x10 ) ? 0x0002 : 0 ) |
( ( V_6 [ 0 ] & 0x20 ) ? 0x0001 : 0 ) |
( ( V_6 [ 1 ] & 0x08 ) ? 0x1000 : 0 ) |
( ( V_6 [ 1 ] & 0x10 ) ? 0x0800 : 0 ) |
( ( V_6 [ 1 ] & 0x20 ) ? 0x0400 : 0 ) |
( ( V_6 [ 1 ] & 0x40 ) ? 0x0200 : 0 ) |
( ( V_6 [ 1 ] & 0x80 ) ? 0x0100 : 0 ) ;
* V_3 = V_7 ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
unsigned char V_6 [ 3 ] ;
if ( 3 != F_2 ( V_2 , V_6 , 3 ) )
return - V_5 ;
if ( V_6 [ 0 ] != 0x00 )
return 0 ;
* V_3 = V_6 [ 2 ] & 0x3f ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 ,
T_1 * V_3 )
{
unsigned char V_9 , V_10 , V_11 ;
struct V_12 V_13 [] = { { . V_14 = V_2 -> V_14 , . V_15 = 0 , . V_6 = & V_9 , . V_16 = 1 } ,
{ . V_14 = V_2 -> V_14 , . V_15 = V_17 , . V_6 = & V_10 , . V_16 = 1 } } ;
V_9 = 0x10 ;
if ( 2 != F_6 ( V_2 -> V_18 , V_13 , 2 ) )
return - V_5 ;
if ( V_10 == 0x00 )
return 0 ;
V_9 = 0x00 ;
V_13 [ 1 ] . V_6 = & V_11 ;
if ( 2 != F_6 ( V_2 -> V_18 , V_13 , 2 ) )
return - V_5 ;
if ( V_11 == 0x00 )
return 0 ;
* V_3 = V_11 ;
return 1 ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
int V_25 ;
T_3 V_13 [ 3 ] = { 0 , 0 , 0 } ;
V_25 = V_24 -> V_26 ( V_24 , 0 , V_27 ,
V_13 , sizeof( V_13 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_22 -> V_28 = ( V_13 [ 0 ] >> 7 ) ;
V_22 -> V_29 = ( V_13 [ 0 ] & 0x7f ) ;
V_22 -> V_30 = V_13 [ 1 ] << 8 | V_13 [ 2 ] ;
return 0 ;
}
static int F_8 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = V_20 -> V_24 ;
int V_25 ;
T_3 V_13 [ 5 ] = { 0 , 0 , 0 , 0 , 0 } ;
V_25 = V_24 -> V_26 ( V_24 , 0 , V_31 ,
V_13 , sizeof( V_13 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_22 -> V_28 = ( V_13 [ 0 ] >> 7 ) ;
V_22 -> V_29 = ( V_13 [ 0 ] & 0x7f ) ;
switch ( V_20 -> V_32 ) {
case V_33 :
V_22 -> V_30 = V_13 [ 1 ] << 8 | V_13 [ 2 ] ;
break;
case V_34 :
if ( ( V_13 [ 3 ] ^ V_13 [ 4 ] ) != 0xff )
V_22 -> V_30 = ( V_13 [ 1 ] << 24 ) |
( V_13 [ 2 ] << 16 ) |
( V_13 [ 3 ] << 8 ) |
V_13 [ 4 ] ;
else if ( ( V_13 [ 1 ] ^ V_13 [ 2 ] ) != 0xff )
V_22 -> V_30 = ( V_13 [ 1 ] << 16 ) |
( V_13 [ 2 ] << 8 ) |
V_13 [ 3 ] ;
else
V_22 -> V_30 = V_13 [ 1 ] << 8 | V_13 [ 3 ] ;
break;
case V_35 :
V_22 -> V_30 = V_13 [ 1 ] << 8 | V_13 [ 2 ] ;
break;
default:
V_22 -> V_30 = ( V_13 [ 1 ] << 24 ) | ( V_13 [ 2 ] << 16 ) |
( V_13 [ 3 ] << 8 ) | V_13 [ 4 ] ;
break;
}
return 0 ;
}
static int F_9 ( struct V_19 * V_20 )
{
static T_1 V_3 ;
int V_25 ;
struct V_1 V_36 ;
V_36 . V_18 = & V_20 -> V_24 -> V_37 ;
V_36 . V_14 = V_20 -> V_38 ;
V_25 = V_20 -> V_39 ( & V_36 , & V_3 ) ;
if ( V_25 < 0 ) {
F_10 ( L_1 , V_25 ) ;
return V_25 ;
}
if ( V_25 ) {
F_10 ( L_2 , V_40 , V_3 ) ;
F_11 ( V_20 -> V_25 , V_3 , 0 ) ;
}
return 0 ;
}
static void F_12 ( struct V_19 * V_20 )
{
int V_41 ;
struct V_21 V_22 ;
V_41 = V_20 -> V_42 ( V_20 , & V_22 ) ;
if ( F_13 ( V_41 < 0 ) ) {
F_10 ( L_3 , V_41 ) ;
return;
}
if ( F_13 ( V_22 . V_29 != V_20 -> V_43 ) ) {
F_10 ( L_4 , V_40 ,
V_22 . V_28 , V_22 . V_29 ,
V_22 . V_30 ) ;
if ( V_20 -> V_44 )
F_11 ( V_20 -> V_25 ,
V_22 . V_30 ,
V_22 . V_28 ) ;
else
F_11 ( V_20 -> V_25 ,
V_22 . V_30 & 0xff ,
V_22 . V_28 ) ;
if ( V_20 -> V_24 -> V_45 == V_46 ||
V_20 -> V_24 -> V_45 == V_47 )
V_20 -> V_43 = 0 ;
else
V_20 -> V_43 = V_22 . V_29 ;
}
}
static void F_14 ( struct V_48 * V_49 )
{
struct V_19 * V_20 = F_15 ( V_49 , struct V_19 , V_49 . V_49 ) ;
if ( V_20 -> V_38 )
F_9 ( V_20 ) ;
else
F_12 ( V_20 ) ;
F_16 ( & V_20 -> V_49 , F_17 ( V_20 -> V_50 ) ) ;
}
static int F_18 ( struct V_51 * V_25 )
{
struct V_19 * V_20 = V_25 -> V_52 ;
F_19 ( & V_20 -> V_49 , F_14 ) ;
F_16 ( & V_20 -> V_49 , 0 ) ;
return 0 ;
}
static void F_20 ( struct V_51 * V_25 )
{
struct V_19 * V_20 = V_25 -> V_52 ;
F_21 ( & V_20 -> V_49 ) ;
}
static int F_22 ( struct V_51 * V_51 , T_4 * V_32 )
{
struct V_19 * V_20 = V_51 -> V_52 ;
struct V_23 * V_24 = V_20 -> V_24 ;
if ( * V_32 & V_33 ) {
V_24 -> V_53 . V_54 |= V_55 ;
V_20 -> V_44 = 1 ;
* V_32 = V_33 ;
} else if ( * V_32 & V_34 ) {
V_24 -> V_53 . V_54 &= ~ V_55 ;
V_20 -> V_44 = 1 ;
* V_32 = V_34 ;
} else if ( * V_32 & V_56 ) {
* V_32 = V_56 ;
} else {
* V_32 = V_20 -> V_32 ;
return - V_57 ;
}
F_23 ( V_24 , V_58 , V_24 -> V_53 . V_54 ,
V_55 ) ;
V_20 -> V_32 = * V_32 ;
return 0 ;
}
static int F_24 ( struct V_51 * V_51 , T_4 * V_32 )
{
struct V_19 * V_20 = V_51 -> V_52 ;
struct V_23 * V_24 = V_20 -> V_24 ;
T_3 V_59 = V_60 ;
if ( * V_32 & V_33 ) {
V_24 -> V_53 . V_54 |= V_55 ;
V_20 -> V_44 = 1 ;
* V_32 = V_33 ;
} else if ( * V_32 & V_34 ) {
V_24 -> V_53 . V_54 &= ~ V_55 ;
V_59 = V_61 | V_62 ;
V_20 -> V_44 = 1 ;
* V_32 = V_34 ;
} else if ( * V_32 & V_35 ) {
V_24 -> V_53 . V_54 |= V_55 ;
V_59 = V_63 ;
V_20 -> V_44 = 1 ;
* V_32 = V_35 ;
} else if ( * V_32 & V_56 ) {
* V_32 = V_56 ;
} else {
* V_32 = V_20 -> V_32 ;
return - V_57 ;
}
F_25 ( V_24 , V_64 , & V_59 , 1 ) ;
F_23 ( V_24 , V_58 , V_24 -> V_53 . V_54 ,
V_55 ) ;
V_20 -> V_32 = * V_32 ;
return 0 ;
}
static int F_26 ( struct V_51 * V_51 , T_4 * V_32 )
{
struct V_19 * V_20 = V_51 -> V_52 ;
struct V_23 * V_24 = V_20 -> V_24 ;
switch ( V_24 -> V_45 ) {
case V_65 :
case V_66 :
return F_22 ( V_51 , V_32 ) ;
case V_47 :
case V_46 :
case V_67 :
return F_24 ( V_51 , V_32 ) ;
default:
F_27 ( L_5 ,
V_24 -> V_45 ) ;
return - V_57 ;
}
}
static int F_28 ( struct V_23 * V_24 )
{
int V_68 = 0 ;
const unsigned short V_69 [] = {
0x1f , 0x30 , 0x47 , V_70
} ;
while ( V_69 [ V_68 ] != V_70 ) {
if ( F_29 ( & V_24 -> V_37 , V_69 [ V_68 ] ) == 1 )
return V_69 [ V_68 ] ;
V_68 ++ ;
}
return - V_71 ;
}
static void F_30 ( struct V_48 * V_49 )
{
struct V_23 * V_24 =
F_15 ( V_49 , struct V_23 , V_72 . V_49 ) ;
int V_73 ;
V_73 = F_31 ( V_24 , V_74 ) ;
if ( V_73 & V_75 ) {
T_3 V_76 ;
V_76 = ( ( T_3 ) V_73 ) & ~ V_75 ;
F_25 ( V_24 , V_74 , & V_76 , 1 ) ;
F_32 ( V_24 -> V_77 , V_78 ,
1 ) ;
F_32 ( V_24 -> V_77 , V_78 ,
0 ) ;
}
F_16 ( & V_24 -> V_72 ,
F_17 ( V_79 ) ) ;
}
static void F_33 ( struct V_23 * V_24 )
{
struct V_80 * V_80 ;
int V_81 ;
F_34 ( L_6 ) ;
V_80 = F_35 () ;
if ( ! V_80 ) {
F_36 ( L_7 ) ;
return;
}
F_37 ( V_24 -> V_82 , V_24 -> V_83 ,
sizeof( V_24 -> V_83 ) ) ;
F_38 ( V_24 -> V_83 , L_8 ,
sizeof( V_24 -> V_83 ) ) ;
F_19 ( & V_24 -> V_72 , F_30 ) ;
V_80 -> V_84 = L_9 ;
V_80 -> V_85 = V_24 -> V_83 ;
V_80 -> V_86 [ 0 ] = F_39 ( V_87 ) | F_39 ( V_88 ) ;
F_40 ( V_78 , V_80 -> V_89 ) ;
V_80 -> V_90 = 0 ;
V_80 -> V_91 = 0 ;
V_80 -> V_92 . V_93 = V_94 ;
V_80 -> V_92 . V_95 = F_41 ( V_24 -> V_82 -> V_96 . V_97 ) ;
V_80 -> V_92 . V_98 = F_41 ( V_24 -> V_82 -> V_96 . V_99 ) ;
V_80 -> V_92 . V_100 = 1 ;
V_80 -> V_24 . V_101 = & V_24 -> V_82 -> V_24 ;
V_81 = F_42 ( V_80 ) ;
if ( V_81 ) {
F_36 ( L_10 ) ;
F_43 ( V_80 ) ;
return;
}
V_24 -> V_77 = V_80 ;
F_16 ( & V_24 -> V_72 ,
F_17 ( V_79 ) ) ;
return;
}
static void F_44 ( struct V_23 * V_24 )
{
if ( V_24 -> V_77 != NULL ) {
F_34 ( L_11 ) ;
F_21 ( & V_24 -> V_72 ) ;
F_45 ( V_24 -> V_77 ) ;
V_24 -> V_77 = NULL ;
}
return;
}
static int F_46 ( struct V_23 * V_24 )
{
struct V_19 * V_20 ;
struct V_51 * V_25 ;
int V_81 = - V_102 ;
T_4 V_32 ;
T_2 V_103 = 0 ;
if ( V_24 -> V_53 . V_104 )
F_33 ( V_24 ) ;
if ( V_24 -> V_53 . V_105 ) {
V_103 = F_28 ( V_24 ) ;
if ( ! V_103 ) {
V_24 -> V_53 . V_105 = 0 ;
F_47 ( L_12 ) ;
return - V_71 ;
}
}
if ( V_24 -> V_53 . V_106 == NULL && ! V_24 -> V_53 . V_105 ) {
F_47 ( L_13
L_14 ) ;
return 0 ;
}
V_20 = F_48 ( sizeof( * V_20 ) , V_107 ) ;
V_25 = F_49 () ;
if ( ! V_20 || ! V_25 )
goto error;
V_20 -> V_24 = V_24 ;
V_24 -> V_20 = V_20 ;
V_20 -> V_25 = V_25 ;
V_25 -> V_52 = V_20 ;
V_25 -> V_108 = F_18 ;
V_25 -> V_109 = F_20 ;
if ( V_24 -> V_53 . V_105 ) {
switch ( V_24 -> V_110 ) {
case V_111 :
case V_112 :
V_25 -> V_113 = V_114 ;
V_20 -> V_39 = F_1 ;
break;
case V_115 :
V_25 -> V_113 = V_116 ;
V_20 -> V_39 = F_4 ;
break;
case V_117 :
V_25 -> V_113 = V_118 ;
V_20 -> V_39 = F_3 ;
V_25 -> V_119 = V_33 ;
break;
case V_120 :
V_25 -> V_113 = V_121 ;
V_20 -> V_39 = F_5 ;
break;
default:
V_81 = - V_71 ;
goto error;
}
V_20 -> V_38 = V_103 ;
} else {
switch ( V_24 -> V_45 ) {
case V_65 :
case V_66 :
V_25 -> V_119 = V_33 | V_34 ;
V_20 -> V_42 = F_7 ;
break;
case V_47 :
case V_46 :
case V_67 :
V_20 -> V_42 = F_8 ;
V_25 -> V_119 = V_33 | V_34 |
V_35 ;
break;
default:
V_81 = - V_71 ;
goto error;
}
V_25 -> V_122 = F_26 ;
V_25 -> V_113 = V_24 -> V_53 . V_106 ;
V_32 = V_56 ;
V_81 = F_26 ( V_25 , & V_32 ) ;
if ( V_81 )
goto error;
}
V_20 -> V_50 = 100 ;
snprintf ( V_20 -> V_84 , sizeof( V_20 -> V_84 ) , L_15 , V_24 -> V_84 ) ;
F_37 ( V_24 -> V_82 , V_20 -> V_85 , sizeof( V_20 -> V_85 ) ) ;
F_38 ( V_20 -> V_85 , L_16 , sizeof( V_20 -> V_85 ) ) ;
V_25 -> V_123 = V_20 -> V_84 ;
V_25 -> V_124 = V_20 -> V_85 ;
V_25 -> V_125 . V_93 = V_94 ;
V_25 -> V_125 . V_100 = 1 ;
V_25 -> V_125 . V_95 = F_41 ( V_24 -> V_82 -> V_96 . V_97 ) ;
V_25 -> V_125 . V_98 = F_41 ( V_24 -> V_82 -> V_96 . V_99 ) ;
V_25 -> V_24 . V_101 = & V_24 -> V_82 -> V_24 ;
V_25 -> V_126 = V_127 ;
V_81 = F_50 ( V_25 ) ;
if ( V_81 )
goto error;
return 0 ;
error:
V_24 -> V_20 = NULL ;
F_51 ( V_25 ) ;
F_52 ( V_20 ) ;
return V_81 ;
}
static int F_53 ( struct V_23 * V_24 )
{
struct V_19 * V_20 = V_24 -> V_20 ;
F_44 ( V_24 ) ;
if ( ! V_20 )
return 0 ;
if ( V_20 -> V_25 )
F_54 ( V_20 -> V_25 ) ;
F_52 ( V_20 ) ;
V_24 -> V_20 = NULL ;
return 0 ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_128 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_128 ) ;
}
