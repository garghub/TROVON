static int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_5 ;
if ( 1 != F_2 ( V_2 -> V_6 , & V_5 , 1 ) ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
F_3 ( L_2 , V_5 ) ;
if ( V_5 == 0xff )
return 0 ;
if ( V_5 == 0xfe )
return 1 ;
* V_3 = V_5 ;
* V_4 = V_5 ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_8 [ 2 ] ;
T_2 V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 -> V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_10 != 2 )
return - V_7 ;
if ( V_8 [ 1 ] == 0xff )
return 0 ;
V_2 -> V_11 = V_8 [ 1 ] ;
V_9 =
( ( V_8 [ 0 ] & 0x01 ) ? 0x0020 : 0 ) |
( ( V_8 [ 0 ] & 0x02 ) ? 0x0010 : 0 ) |
( ( V_8 [ 0 ] & 0x04 ) ? 0x0008 : 0 ) |
( ( V_8 [ 0 ] & 0x08 ) ? 0x0004 : 0 ) |
( ( V_8 [ 0 ] & 0x10 ) ? 0x0002 : 0 ) |
( ( V_8 [ 0 ] & 0x20 ) ? 0x0001 : 0 ) |
( ( V_8 [ 1 ] & 0x08 ) ? 0x1000 : 0 ) |
( ( V_8 [ 1 ] & 0x10 ) ? 0x0800 : 0 ) |
( ( V_8 [ 1 ] & 0x20 ) ? 0x0400 : 0 ) |
( ( V_8 [ 1 ] & 0x40 ) ? 0x0200 : 0 ) |
( ( V_8 [ 1 ] & 0x80 ) ? 0x0100 : 0 ) ;
F_3 ( L_3 ,
V_9 , V_8 [ 1 ] , V_8 [ 0 ] ) ;
* V_3 = V_9 ;
* V_4 = V_9 ;
return 1 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 * V_4 )
{
unsigned char V_8 [ 3 ] ;
if ( 3 != F_2 ( V_2 -> V_6 , V_8 , 3 ) ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
F_3 ( L_2 , V_8 [ 2 ] & 0x3f ) ;
if ( V_8 [ 0 ] != 0x00 )
return 0 ;
* V_3 = V_8 [ 2 ] & 0x3f ;
* V_4 = V_8 [ 2 ] & 0x3f ;
return 1 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 * V_4 )
{
unsigned char V_12 , V_13 , V_14 ;
struct V_15 V_16 [] = { { . V_17 = V_2 -> V_6 -> V_17 , . V_18 = 0 , . V_8 = & V_12 , . V_19 = 1 } ,
{ . V_17 = V_2 -> V_6 -> V_17 , . V_18 = V_20 , . V_8 = & V_13 , . V_19 = 1 } } ;
V_12 = 0x10 ;
if ( 2 != F_7 ( V_2 -> V_6 -> V_21 , V_16 , 2 ) ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
if ( V_13 == 0x00 )
return 0 ;
V_12 = 0x00 ;
V_16 [ 1 ] . V_8 = & V_14 ;
if ( 2 != F_7 ( V_2 -> V_6 -> V_21 , V_16 , 2 ) ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
if ( V_14 == 0x00 )
return 0 ;
* V_3 = V_14 ;
* V_4 = V_14 ;
return 1 ;
}
static int F_8 ( struct V_22 * V_2 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_27 ;
T_3 V_16 [ 3 ] = { 0 , 0 , 0 } ;
V_27 = V_26 -> V_28 ( V_26 , 0 , V_29 ,
V_16 , sizeof( V_16 ) ) ;
if ( V_27 < 0 )
return V_27 ;
V_24 -> V_30 = ( V_16 [ 0 ] >> 7 ) ;
V_24 -> V_31 = ( V_16 [ 0 ] & 0x7f ) ;
V_24 -> V_32 = V_16 [ 1 ] ;
V_24 -> V_33 [ 0 ] = V_16 [ 2 ] ;
return 0 ;
}
static int F_9 ( struct V_22 * V_2 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_27 ;
T_3 V_16 [ 5 ] = { 0 , 0 , 0 , 0 , 0 } ;
V_27 = V_26 -> V_28 ( V_26 , 0 , V_34 ,
V_16 , sizeof( V_16 ) ) ;
if ( V_27 < 0 )
return V_27 ;
V_24 -> V_30 = ( V_16 [ 0 ] >> 7 ) ;
V_24 -> V_31 = ( V_16 [ 0 ] & 0x7f ) ;
V_24 -> V_32 = V_16 [ 1 ] ;
V_24 -> V_33 [ 0 ] = V_16 [ 2 ] ;
V_24 -> V_33 [ 1 ] = V_16 [ 3 ] ;
V_24 -> V_33 [ 2 ] = V_16 [ 4 ] ;
return 0 ;
}
static void F_10 ( struct V_22 * V_2 )
{
int V_35 ;
struct V_23 V_24 ;
V_35 = V_2 -> V_36 ( V_2 , & V_24 ) ;
if ( F_11 ( V_35 < 0 ) ) {
F_12 ( L_4 , V_35 ) ;
return;
}
if ( F_11 ( V_24 . V_31 != V_2 -> V_37 ) ) {
F_12 ( L_5 , V_38 ,
V_24 . V_30 , V_24 . V_31 ,
V_24 . V_32 , V_24 . V_33 [ 0 ] ) ;
if ( V_2 -> V_39 )
F_13 ( V_2 -> V_27 ,
V_24 . V_32 << 8 |
V_24 . V_33 [ 0 ] ,
V_24 . V_30 ) ;
else
F_13 ( V_2 -> V_27 ,
V_24 . V_33 [ 0 ] ,
V_24 . V_30 ) ;
if ( V_2 -> V_26 -> V_40 == V_41 ||
V_2 -> V_26 -> V_40 == V_42 )
V_2 -> V_37 = 0 ;
else
V_2 -> V_37 = V_24 . V_31 ;
}
}
static void F_14 ( struct V_43 * V_44 )
{
struct V_22 * V_2 = F_15 ( V_44 , struct V_22 , V_44 . V_44 ) ;
F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_44 , F_17 ( V_2 -> V_45 ) ) ;
}
static int F_18 ( struct V_46 * V_27 )
{
struct V_22 * V_2 = V_27 -> V_47 ;
F_19 ( & V_2 -> V_44 , F_14 ) ;
F_16 ( & V_2 -> V_44 , 0 ) ;
return 0 ;
}
static void F_20 ( struct V_46 * V_27 )
{
struct V_22 * V_2 = V_27 -> V_47 ;
F_21 ( & V_2 -> V_44 ) ;
}
static int F_22 ( struct V_46 * V_46 , T_4 V_48 )
{
int V_27 = 0 ;
struct V_22 * V_2 = V_46 -> V_47 ;
struct V_25 * V_26 = V_2 -> V_26 ;
T_3 V_49 = V_50 ;
if ( V_48 == V_51 ) {
V_26 -> V_52 . V_53 |= V_54 ;
V_2 -> V_39 = 1 ;
} else if ( V_48 == V_55 ) {
V_26 -> V_52 . V_53 &= ~ V_54 ;
V_49 = V_56 ;
V_2 -> V_39 = 1 ;
} else if ( V_48 != V_57 )
V_27 = - V_58 ;
F_23 ( V_26 , V_59 , V_26 -> V_52 . V_53 ,
V_54 ) ;
switch ( V_26 -> V_40 ) {
case V_60 :
case V_61 :
V_2 -> V_36 = F_8 ;
break;
case V_42 :
case V_41 :
case V_62 :
V_2 -> V_36 = F_9 ;
F_24 ( V_26 , V_63 , & V_49 , 1 ) ;
break;
default:
F_25 ( L_6 ,
V_26 -> V_40 ) ;
V_27 = - V_58 ;
}
return V_27 ;
}
static void F_26 ( struct V_25 * V_26 )
{
struct V_64 V_65 ;
const unsigned short V_66 [] = {
0x1f , 0x30 , 0x47 , V_67
} ;
memset ( & V_65 , 0 , sizeof( struct V_64 ) ) ;
memset ( & V_26 -> V_68 , 0 , sizeof( V_26 -> V_68 ) ) ;
F_27 ( V_65 . type , L_7 , V_69 ) ;
switch ( V_26 -> V_70 ) {
case V_71 :
case V_72 :
V_26 -> V_68 . V_73 = V_74 ;
V_26 -> V_68 . V_36 = F_1 ;
V_26 -> V_68 . V_75 = L_8 ;
break;
case V_76 :
V_26 -> V_68 . V_73 = V_77 ;
V_26 -> V_68 . V_36 = F_5 ;
V_26 -> V_68 . V_75 = L_9 ;
break;
case V_78 :
V_26 -> V_68 . V_73 = V_79 ;
V_26 -> V_68 . V_36 = F_4 ;
V_26 -> V_68 . V_75 = L_10 ;
break;
case V_80 :
V_26 -> V_68 . V_73 = V_81 ;
V_26 -> V_68 . V_36 = F_6 ;
V_26 -> V_68 . V_75 = L_11 ;
break;
}
if ( V_26 -> V_68 . V_75 )
V_65 . V_82 = & V_26 -> V_68 ;
F_28 ( & V_26 -> V_83 , & V_65 , V_66 , NULL ) ;
}
static void F_29 ( struct V_43 * V_44 )
{
struct V_25 * V_26 =
F_15 ( V_44 , struct V_25 , V_84 . V_44 ) ;
int V_85 ;
V_85 = F_30 ( V_26 , V_86 ) ;
if ( V_85 & V_87 ) {
T_3 V_88 ;
V_88 = ( ( T_3 ) V_85 ) & ~ V_87 ;
F_24 ( V_26 , V_86 , & V_88 , 1 ) ;
F_31 ( V_26 -> V_89 , V_90 ,
1 ) ;
F_31 ( V_26 -> V_89 , V_90 ,
0 ) ;
}
F_16 ( & V_26 -> V_84 ,
F_17 ( V_91 ) ) ;
}
static void F_32 ( struct V_25 * V_26 )
{
struct V_92 * V_92 ;
int V_93 ;
F_33 ( L_12 ) ;
V_92 = F_34 () ;
if ( ! V_92 ) {
F_35 ( L_13 ) ;
return;
}
F_36 ( V_26 -> V_94 , V_26 -> V_95 ,
sizeof( V_26 -> V_95 ) ) ;
F_37 ( V_26 -> V_95 , L_14 ,
sizeof( V_26 -> V_95 ) ) ;
F_19 ( & V_26 -> V_84 , F_29 ) ;
V_92 -> V_75 = L_15 ;
V_92 -> V_96 = V_26 -> V_95 ;
V_92 -> V_97 [ 0 ] = F_38 ( V_98 ) | F_38 ( V_99 ) ;
F_39 ( V_90 , V_92 -> V_100 ) ;
V_92 -> V_101 = 0 ;
V_92 -> V_102 = 0 ;
V_92 -> V_103 . V_104 = V_105 ;
V_92 -> V_103 . V_106 = F_40 ( V_26 -> V_94 -> V_107 . V_108 ) ;
V_92 -> V_103 . V_109 = F_40 ( V_26 -> V_94 -> V_107 . V_110 ) ;
V_92 -> V_103 . V_111 = 1 ;
V_92 -> V_26 . V_112 = & V_26 -> V_94 -> V_26 ;
V_93 = F_41 ( V_92 ) ;
if ( V_93 ) {
F_35 ( L_16 ) ;
F_42 ( V_92 ) ;
return;
}
V_26 -> V_89 = V_92 ;
F_16 ( & V_26 -> V_84 ,
F_17 ( V_91 ) ) ;
return;
}
static void F_43 ( struct V_25 * V_26 )
{
if ( V_26 -> V_89 != NULL ) {
F_33 ( L_17 ) ;
F_21 ( & V_26 -> V_84 ) ;
F_44 ( V_26 -> V_89 ) ;
V_26 -> V_89 = NULL ;
}
return;
}
static int F_45 ( struct V_25 * V_26 )
{
struct V_22 * V_2 ;
struct V_46 * V_27 ;
int V_93 = - V_113 ;
if ( V_26 -> V_52 . V_73 == NULL ) {
F_46 ( L_18
L_19 ) ;
return 0 ;
}
V_2 = F_47 ( sizeof( * V_2 ) , V_114 ) ;
V_27 = F_48 () ;
if ( ! V_2 || ! V_27 )
goto V_115;
V_2 -> V_26 = V_26 ;
V_26 -> V_2 = V_2 ;
V_2 -> V_27 = V_27 ;
V_27 -> V_116 = V_51 | V_55 ;
V_27 -> V_47 = V_2 ;
V_27 -> V_117 = F_22 ;
V_27 -> V_118 = F_18 ;
V_27 -> V_119 = F_20 ;
V_93 = F_22 ( V_27 , V_57 ) ;
if ( V_93 )
goto V_115;
V_2 -> V_45 = 100 ;
snprintf ( V_2 -> V_75 , sizeof( V_2 -> V_75 ) , L_20 ,
V_26 -> V_75 ) ;
F_36 ( V_26 -> V_94 , V_2 -> V_96 , sizeof( V_2 -> V_96 ) ) ;
F_37 ( V_2 -> V_96 , L_21 , sizeof( V_2 -> V_96 ) ) ;
V_27 -> V_120 = V_2 -> V_75 ;
V_27 -> V_121 = V_2 -> V_96 ;
V_27 -> V_122 . V_104 = V_105 ;
V_27 -> V_122 . V_111 = 1 ;
V_27 -> V_122 . V_106 = F_40 ( V_26 -> V_94 -> V_107 . V_108 ) ;
V_27 -> V_122 . V_109 = F_40 ( V_26 -> V_94 -> V_107 . V_110 ) ;
V_27 -> V_26 . V_112 = & V_26 -> V_94 -> V_26 ;
V_27 -> V_123 = V_26 -> V_52 . V_73 ;
V_27 -> V_124 = V_125 ;
V_93 = F_49 ( V_27 ) ;
if ( V_93 )
goto V_126;
F_26 ( V_26 ) ;
#if F_50 ( V_127 ) && F_50 ( V_128 )
if ( V_26 -> V_52 . V_129 )
F_51 ( L_22 ) ;
#endif
if ( V_26 -> V_52 . V_130 )
F_32 ( V_26 ) ;
return 0 ;
V_126:
V_26 -> V_2 = NULL ;
V_115:
F_52 ( V_27 ) ;
F_53 ( V_2 ) ;
return V_93 ;
}
static int F_54 ( struct V_25 * V_26 )
{
struct V_22 * V_2 = V_26 -> V_2 ;
F_43 ( V_26 ) ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_27 )
F_55 ( V_2 -> V_27 ) ;
F_53 ( V_2 ) ;
V_26 -> V_2 = NULL ;
return 0 ;
}
static int T_5 F_56 ( void )
{
return F_57 ( & V_131 ) ;
}
static void T_6 F_58 ( void )
{
F_59 ( & V_131 ) ;
}
