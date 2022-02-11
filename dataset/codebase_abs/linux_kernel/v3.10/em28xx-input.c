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
struct V_23 * V_24 = V_20 -> V_24 ;
static T_1 V_3 ;
int V_25 ;
struct V_1 V_36 ;
V_36 . V_18 = & V_20 -> V_24 -> V_37 [ V_24 -> V_38 ] ;
V_36 . V_14 = V_20 -> V_39 ;
V_25 = V_20 -> V_40 ( & V_36 , & V_3 ) ;
if ( V_25 < 0 ) {
F_10 ( L_1 , V_25 ) ;
return V_25 ;
}
if ( V_25 ) {
F_10 ( L_2 , V_41 , V_3 ) ;
F_11 ( V_20 -> V_25 , V_3 , 0 ) ;
}
return 0 ;
}
static void F_12 ( struct V_19 * V_20 )
{
int V_42 ;
struct V_21 V_22 ;
V_42 = V_20 -> V_43 ( V_20 , & V_22 ) ;
if ( F_13 ( V_42 < 0 ) ) {
F_10 ( L_3 , V_42 ) ;
return;
}
if ( F_13 ( V_22 . V_29 != V_20 -> V_44 ) ) {
F_10 ( L_4 , V_41 ,
V_22 . V_28 , V_22 . V_29 ,
V_22 . V_30 ) ;
if ( V_20 -> V_45 )
F_11 ( V_20 -> V_25 ,
V_22 . V_30 ,
V_22 . V_28 ) ;
else
F_11 ( V_20 -> V_25 ,
V_22 . V_30 & 0xff ,
V_22 . V_28 ) ;
if ( V_20 -> V_24 -> V_46 == V_47 ||
V_20 -> V_24 -> V_46 == V_48 )
V_20 -> V_44 = 0 ;
else
V_20 -> V_44 = V_22 . V_29 ;
}
}
static void F_14 ( struct V_49 * V_50 )
{
struct V_19 * V_20 = F_15 ( V_50 , struct V_19 , V_50 . V_50 ) ;
if ( V_20 -> V_39 )
F_9 ( V_20 ) ;
else
F_12 ( V_20 ) ;
F_16 ( & V_20 -> V_50 , F_17 ( V_20 -> V_51 ) ) ;
}
static int F_18 ( struct V_52 * V_25 )
{
struct V_19 * V_20 = V_25 -> V_53 ;
F_19 ( & V_20 -> V_50 , F_14 ) ;
F_16 ( & V_20 -> V_50 , 0 ) ;
return 0 ;
}
static void F_20 ( struct V_52 * V_25 )
{
struct V_19 * V_20 = V_25 -> V_53 ;
F_21 ( & V_20 -> V_50 ) ;
}
static int F_22 ( struct V_52 * V_52 , T_4 * V_32 )
{
struct V_19 * V_20 = V_52 -> V_53 ;
struct V_23 * V_24 = V_20 -> V_24 ;
if ( * V_32 & V_33 ) {
V_24 -> V_54 . V_55 |= V_56 ;
V_20 -> V_45 = 1 ;
* V_32 = V_33 ;
} else if ( * V_32 & V_34 ) {
V_24 -> V_54 . V_55 &= ~ V_56 ;
V_20 -> V_45 = 1 ;
* V_32 = V_34 ;
} else if ( * V_32 & V_57 ) {
* V_32 = V_57 ;
} else {
* V_32 = V_20 -> V_32 ;
return - V_58 ;
}
F_23 ( V_24 , V_59 , V_24 -> V_54 . V_55 ,
V_56 ) ;
V_20 -> V_32 = * V_32 ;
return 0 ;
}
static int F_24 ( struct V_52 * V_52 , T_4 * V_32 )
{
struct V_19 * V_20 = V_52 -> V_53 ;
struct V_23 * V_24 = V_20 -> V_24 ;
T_3 V_60 = V_61 ;
if ( * V_32 & V_33 ) {
V_24 -> V_54 . V_55 |= V_56 ;
V_20 -> V_45 = 1 ;
* V_32 = V_33 ;
} else if ( * V_32 & V_34 ) {
V_24 -> V_54 . V_55 &= ~ V_56 ;
V_60 = V_62 | V_63 ;
V_20 -> V_45 = 1 ;
* V_32 = V_34 ;
} else if ( * V_32 & V_35 ) {
V_24 -> V_54 . V_55 |= V_56 ;
V_60 = V_64 ;
V_20 -> V_45 = 1 ;
* V_32 = V_35 ;
} else if ( * V_32 & V_57 ) {
* V_32 = V_57 ;
} else {
* V_32 = V_20 -> V_32 ;
return - V_58 ;
}
F_25 ( V_24 , V_65 , & V_60 , 1 ) ;
F_23 ( V_24 , V_59 , V_24 -> V_54 . V_55 ,
V_56 ) ;
V_20 -> V_32 = * V_32 ;
return 0 ;
}
static int F_26 ( struct V_52 * V_52 , T_4 * V_32 )
{
struct V_19 * V_20 = V_52 -> V_53 ;
struct V_23 * V_24 = V_20 -> V_24 ;
switch ( V_24 -> V_46 ) {
case V_66 :
case V_67 :
return F_22 ( V_52 , V_32 ) ;
case V_48 :
case V_47 :
case V_68 :
return F_24 ( V_52 , V_32 ) ;
default:
F_27 ( L_5 ,
V_24 -> V_46 ) ;
return - V_58 ;
}
}
static int F_28 ( struct V_23 * V_24 )
{
int V_69 = 0 ;
const unsigned short V_70 [] = {
0x1f , 0x30 , 0x47 , V_71
} ;
while ( V_70 [ V_69 ] != V_71 ) {
if ( F_29 ( & V_24 -> V_37 [ V_24 -> V_38 ] , V_70 [ V_69 ] ) == 1 )
return V_70 [ V_69 ] ;
V_69 ++ ;
}
return - V_72 ;
}
static void F_30 ( struct V_49 * V_50 )
{
struct V_23 * V_24 =
F_15 ( V_50 , struct V_23 , V_73 . V_50 ) ;
int V_74 ;
V_74 = F_31 ( V_24 , V_75 ) ;
if ( V_74 & V_76 ) {
T_3 V_77 ;
V_77 = ( ( T_3 ) V_74 ) & ~ V_76 ;
F_25 ( V_24 , V_75 , & V_77 , 1 ) ;
F_32 ( V_24 -> V_78 , V_79 ,
1 ) ;
F_32 ( V_24 -> V_78 , V_79 ,
0 ) ;
}
F_16 ( & V_24 -> V_73 ,
F_17 ( V_80 ) ) ;
}
static void F_33 ( struct V_23 * V_24 )
{
struct V_81 * V_81 ;
int V_82 ;
F_34 ( L_6 ) ;
V_81 = F_35 () ;
if ( ! V_81 ) {
F_36 ( L_7 ) ;
return;
}
F_37 ( V_24 -> V_83 , V_24 -> V_84 ,
sizeof( V_24 -> V_84 ) ) ;
F_38 ( V_24 -> V_84 , L_8 ,
sizeof( V_24 -> V_84 ) ) ;
F_19 ( & V_24 -> V_73 , F_30 ) ;
V_81 -> V_85 = L_9 ;
V_81 -> V_86 = V_24 -> V_84 ;
V_81 -> V_87 [ 0 ] = F_39 ( V_88 ) | F_39 ( V_89 ) ;
F_40 ( V_79 , V_81 -> V_90 ) ;
V_81 -> V_91 = 0 ;
V_81 -> V_92 = 0 ;
V_81 -> V_93 . V_94 = V_95 ;
V_81 -> V_93 . V_96 = F_41 ( V_24 -> V_83 -> V_97 . V_98 ) ;
V_81 -> V_93 . V_99 = F_41 ( V_24 -> V_83 -> V_97 . V_100 ) ;
V_81 -> V_93 . V_101 = 1 ;
V_81 -> V_24 . V_102 = & V_24 -> V_83 -> V_24 ;
V_82 = F_42 ( V_81 ) ;
if ( V_82 ) {
F_36 ( L_10 ) ;
F_43 ( V_81 ) ;
return;
}
V_24 -> V_78 = V_81 ;
F_16 ( & V_24 -> V_73 ,
F_17 ( V_80 ) ) ;
return;
}
static void F_44 ( struct V_23 * V_24 )
{
if ( V_24 -> V_78 != NULL ) {
F_34 ( L_11 ) ;
F_21 ( & V_24 -> V_73 ) ;
F_45 ( V_24 -> V_78 ) ;
V_24 -> V_78 = NULL ;
}
return;
}
static int F_46 ( struct V_23 * V_24 )
{
struct V_19 * V_20 ;
struct V_52 * V_25 ;
int V_82 = - V_103 ;
T_4 V_32 ;
T_2 V_104 = 0 ;
if ( V_24 -> V_54 . V_105 )
F_33 ( V_24 ) ;
if ( V_24 -> V_54 . V_106 ) {
V_104 = F_28 ( V_24 ) ;
if ( ! V_104 ) {
V_24 -> V_54 . V_106 = 0 ;
F_47 ( L_12 ) ;
return - V_72 ;
}
}
if ( V_24 -> V_54 . V_107 == NULL && ! V_24 -> V_54 . V_106 ) {
F_47 ( L_13
L_14 ) ;
return 0 ;
}
V_20 = F_48 ( sizeof( * V_20 ) , V_108 ) ;
V_25 = F_49 () ;
if ( ! V_20 || ! V_25 )
goto error;
V_20 -> V_24 = V_24 ;
V_24 -> V_20 = V_20 ;
V_20 -> V_25 = V_25 ;
V_25 -> V_53 = V_20 ;
V_25 -> V_109 = F_18 ;
V_25 -> V_110 = F_20 ;
if ( V_24 -> V_54 . V_106 ) {
switch ( V_24 -> V_111 ) {
case V_112 :
case V_113 :
V_25 -> V_114 = V_115 ;
V_20 -> V_40 = F_1 ;
break;
case V_116 :
V_25 -> V_114 = V_117 ;
V_20 -> V_40 = F_4 ;
break;
case V_118 :
V_25 -> V_114 = V_119 ;
V_20 -> V_40 = F_3 ;
V_25 -> V_120 = V_33 ;
break;
case V_121 :
V_25 -> V_114 = V_122 ;
V_20 -> V_40 = F_5 ;
break;
default:
V_82 = - V_72 ;
goto error;
}
V_20 -> V_39 = V_104 ;
} else {
switch ( V_24 -> V_46 ) {
case V_66 :
case V_67 :
V_25 -> V_120 = V_33 | V_34 ;
V_20 -> V_43 = F_7 ;
break;
case V_48 :
case V_47 :
case V_68 :
V_20 -> V_43 = F_8 ;
V_25 -> V_120 = V_33 | V_34 |
V_35 ;
break;
default:
V_82 = - V_72 ;
goto error;
}
V_25 -> V_123 = F_26 ;
V_25 -> V_114 = V_24 -> V_54 . V_107 ;
V_32 = V_57 ;
V_82 = F_26 ( V_25 , & V_32 ) ;
if ( V_82 )
goto error;
}
V_20 -> V_51 = 100 ;
snprintf ( V_20 -> V_85 , sizeof( V_20 -> V_85 ) , L_15 , V_24 -> V_85 ) ;
F_37 ( V_24 -> V_83 , V_20 -> V_86 , sizeof( V_20 -> V_86 ) ) ;
F_38 ( V_20 -> V_86 , L_16 , sizeof( V_20 -> V_86 ) ) ;
V_25 -> V_124 = V_20 -> V_85 ;
V_25 -> V_125 = V_20 -> V_86 ;
V_25 -> V_126 . V_94 = V_95 ;
V_25 -> V_126 . V_101 = 1 ;
V_25 -> V_126 . V_96 = F_41 ( V_24 -> V_83 -> V_97 . V_98 ) ;
V_25 -> V_126 . V_99 = F_41 ( V_24 -> V_83 -> V_97 . V_100 ) ;
V_25 -> V_24 . V_102 = & V_24 -> V_83 -> V_24 ;
V_25 -> V_127 = V_128 ;
V_82 = F_50 ( V_25 ) ;
if ( V_82 )
goto error;
return 0 ;
error:
V_24 -> V_20 = NULL ;
F_51 ( V_25 ) ;
F_52 ( V_20 ) ;
return V_82 ;
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
return F_56 ( & V_129 ) ;
}
static void T_6 F_57 ( void )
{
F_58 ( & V_129 ) ;
}
