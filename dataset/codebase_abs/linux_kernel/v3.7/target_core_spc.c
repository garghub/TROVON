static void F_1 ( struct V_1 * V_2 , unsigned char * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_3 [ 5 ] = 0x80 ;
if ( ! V_2 )
return;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
return;
F_2 ( & V_7 -> V_9 ) ;
V_5 = V_7 -> V_5 ;
if ( V_5 )
V_3 [ 5 ] |= V_5 -> V_10 ;
F_3 ( & V_7 -> V_9 ) ;
}
static int F_4 ( struct V_11 * V_12 , char * V_3 )
{
struct V_13 * V_14 = V_12 -> V_13 ;
struct V_15 * V_16 = V_12 -> V_17 ;
if ( V_16 -> V_18 -> V_19 ( V_16 ) == V_20 )
V_3 [ 1 ] = 0x80 ;
V_3 [ 2 ] = V_16 -> V_18 -> V_21 ( V_16 ) ;
V_3 [ 3 ] = 2 ;
if ( V_16 -> V_22 -> V_23 . V_24 == V_25 )
F_1 ( V_14 -> V_26 , V_3 ) ;
V_3 [ 7 ] = 0x2 ;
snprintf ( & V_3 [ 8 ] , 8 , L_1 ) ;
snprintf ( & V_3 [ 16 ] , 16 , L_2 , V_16 -> V_22 -> V_27 . V_28 ) ;
snprintf ( & V_3 [ 32 ] , 4 , L_2 , V_16 -> V_22 -> V_27 . V_29 ) ;
V_3 [ 4 ] = 31 ;
return 0 ;
}
static int F_5 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_1 V_30 = 0 ;
if ( V_16 -> V_22 -> V_31 &
V_32 ) {
T_2 V_33 ;
V_33 = strlen ( V_16 -> V_22 -> V_27 . V_34 ) ;
V_33 ++ ;
V_30 += sprintf ( & V_3 [ 4 ] , L_2 ,
V_16 -> V_22 -> V_27 . V_34 ) ;
V_30 ++ ;
V_3 [ 3 ] = V_30 ;
}
return 0 ;
}
static void F_6 ( struct V_15 * V_16 ,
unsigned char * V_3 )
{
unsigned char * V_35 = & V_16 -> V_22 -> V_27 . V_34 [ 0 ] ;
int V_36 ;
bool V_37 = true ;
for ( V_36 = 0 ; * V_35 && V_36 < 13 ; V_35 ++ ) {
int V_38 = F_7 ( * V_35 ) ;
if ( V_38 < 0 )
continue;
if ( V_37 ) {
V_37 = false ;
V_3 [ V_36 ++ ] |= V_38 ;
} else {
V_37 = true ;
V_3 [ V_36 ] = V_38 << 4 ;
}
}
}
static int F_8 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_13 * V_14 = V_12 -> V_13 ;
struct V_1 * V_2 = NULL ;
struct V_39 * V_40 = NULL ;
struct V_41 * V_42 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned char * V_43 = & V_16 -> V_22 -> V_27 . V_28 [ 0 ] ;
T_2 V_44 ;
T_2 V_33 , V_45 = 0 ;
T_1 V_30 = 0 , V_46 ;
V_45 = 4 ;
if ( ! ( V_16 -> V_22 -> V_31 & V_32 ) )
goto V_47;
V_3 [ V_45 ++ ] = 0x1 ;
V_3 [ V_45 ] = 0x00 ;
V_3 [ V_45 ++ ] |= 0x3 ;
V_45 ++ ;
V_3 [ V_45 ++ ] = 0x10 ;
V_3 [ V_45 ++ ] = ( 0x6 << 4 ) ;
V_3 [ V_45 ++ ] = 0x01 ;
V_3 [ V_45 ++ ] = 0x40 ;
V_3 [ V_45 ] = ( 0x5 << 4 ) ;
F_6 ( V_16 , & V_3 [ V_45 ] ) ;
V_30 = 20 ;
V_45 = ( V_30 + 4 ) ;
V_47:
V_46 = 8 ;
V_44 = 4 ;
V_44 += 8 ;
V_44 += strlen ( V_43 ) ;
V_44 ++ ;
if ( V_16 -> V_22 -> V_31 &
V_32 ) {
V_33 =
strlen ( & V_16 -> V_22 -> V_27 . V_34 [ 0 ] ) ;
V_33 ++ ;
V_46 += sprintf ( & V_3 [ V_45 + 12 ] , L_3 , V_43 ,
& V_16 -> V_22 -> V_27 . V_34 [ 0 ] ) ;
}
V_3 [ V_45 ] = 0x2 ;
V_3 [ V_45 + 1 ] = 0x1 ;
V_3 [ V_45 + 2 ] = 0x0 ;
memcpy ( & V_3 [ V_45 + 4 ] , L_1 , 8 ) ;
V_46 ++ ;
V_3 [ V_45 + 3 ] = V_46 ;
V_30 += ( V_46 + 4 ) ;
V_45 += ( V_46 + 4 ) ;
V_2 = V_14 -> V_26 ;
if ( V_2 ) {
struct V_48 * V_49 ;
T_2 V_50 , V_51 ;
T_1 V_52 = 0 ;
T_1 V_53 = 0 ;
T_1 V_54 ;
V_40 = V_2 -> V_55 ;
V_3 [ V_45 ] =
( V_40 -> V_56 -> V_57 ( V_40 ) << 4 ) ;
V_3 [ V_45 ++ ] |= 0x1 ;
V_3 [ V_45 ] = 0x80 ;
V_3 [ V_45 ] |= 0x10 ;
V_3 [ V_45 ++ ] |= 0x4 ;
V_45 ++ ;
V_3 [ V_45 ++ ] = 4 ;
V_45 += 2 ;
V_3 [ V_45 ++ ] = ( ( V_2 -> V_58 >> 8 ) & 0xff ) ;
V_3 [ V_45 ++ ] = ( V_2 -> V_58 & 0xff ) ;
V_30 += 8 ;
if ( V_16 -> V_22 -> V_23 . V_24 !=
V_25 )
goto V_59;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
goto V_60;
F_2 ( & V_7 -> V_9 ) ;
V_5 = V_7 -> V_5 ;
if ( ! V_5 ) {
F_3 ( & V_7 -> V_9 ) ;
goto V_60;
}
V_53 = V_5 -> V_53 ;
F_3 ( & V_7 -> V_9 ) ;
V_3 [ V_45 ] =
( V_40 -> V_56 -> V_57 ( V_40 ) << 4 ) ;
V_3 [ V_45 ++ ] |= 0x1 ;
V_3 [ V_45 ] = 0x80 ;
V_3 [ V_45 ] |= 0x10 ;
V_3 [ V_45 ++ ] |= 0x5 ;
V_45 ++ ;
V_3 [ V_45 ++ ] = 4 ;
V_45 += 2 ;
V_3 [ V_45 ++ ] = ( ( V_53 >> 8 ) & 0xff ) ;
V_3 [ V_45 ++ ] = ( V_53 & 0xff ) ;
V_30 += 8 ;
V_60:
V_42 = V_16 -> V_61 ;
if ( ! V_42 )
goto V_59;
F_2 ( & V_42 -> V_62 ) ;
V_49 = V_42 -> V_49 ;
if ( ! V_49 ) {
F_3 ( & V_42 -> V_62 ) ;
goto V_59;
}
V_52 = V_49 -> V_52 ;
F_3 ( & V_42 -> V_62 ) ;
V_3 [ V_45 ++ ] |= 0x1 ;
V_3 [ V_45 ++ ] |= 0x6 ;
V_45 ++ ;
V_3 [ V_45 ++ ] = 4 ;
V_45 += 2 ;
V_3 [ V_45 ++ ] = ( ( V_52 >> 8 ) & 0xff ) ;
V_3 [ V_45 ++ ] = ( V_52 & 0xff ) ;
V_30 += 8 ;
V_59:
V_51 = strlen ( V_40 -> V_56 -> V_63 ( V_40 ) ) ;
V_51 += 10 ;
V_50 = ( ( - V_51 ) & 3 ) ;
if ( V_50 != 0 )
V_51 += V_50 ;
V_51 += 4 ;
V_3 [ V_45 ] =
( V_40 -> V_56 -> V_57 ( V_40 ) << 4 ) ;
V_3 [ V_45 ++ ] |= 0x3 ;
V_3 [ V_45 ] = 0x80 ;
V_3 [ V_45 ] |= 0x10 ;
V_3 [ V_45 ++ ] |= 0x8 ;
V_45 += 2 ;
V_54 = V_40 -> V_56 -> V_64 ( V_40 ) ;
V_51 = sprintf ( & V_3 [ V_45 ] , L_4 ,
V_40 -> V_56 -> V_63 ( V_40 ) , V_54 ) ;
V_51 += 1 ;
if ( V_50 )
V_51 += V_50 ;
V_3 [ V_45 - 1 ] = V_51 ;
V_45 += V_51 ;
V_30 += ( V_51 + 4 ) ;
}
V_3 [ 2 ] = ( ( V_30 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_30 & 0xff ) ;
return 0 ;
}
static int F_9 ( struct V_11 * V_12 , unsigned char * V_3 )
{
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = 0x07 ;
if ( V_12 -> V_17 -> V_22 -> V_65 . V_66 > 0 )
V_3 [ 6 ] = 0x01 ;
return 0 ;
}
static int F_10 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_2 V_67 ;
int V_68 = 0 ;
if ( V_16 -> V_22 -> V_65 . V_69 || V_16 -> V_22 -> V_65 . V_70 )
V_68 = 1 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = V_68 ? 0x3c : 0x10 ;
V_3 [ 4 ] = 0x01 ;
F_11 ( 1 , & V_3 [ 6 ] ) ;
V_67 = F_12 ( V_16 -> V_22 -> V_65 . V_71 ,
V_16 -> V_22 -> V_65 . V_72 ) ;
F_13 ( V_67 , & V_3 [ 8 ] ) ;
F_13 ( V_16 -> V_22 -> V_65 . V_73 , & V_3 [ 12 ] ) ;
if ( ! V_68 )
return 0 ;
F_13 ( V_16 -> V_22 -> V_65 . V_74 , & V_3 [ 20 ] ) ;
F_13 ( V_16 -> V_22 -> V_65 . V_75 ,
& V_3 [ 24 ] ) ;
F_13 ( V_16 -> V_22 -> V_65 . V_76 , & V_3 [ 28 ] ) ;
F_13 ( V_16 -> V_22 -> V_65 . V_77 ,
& V_3 [ 32 ] ) ;
if ( V_16 -> V_22 -> V_65 . V_77 != 0 )
V_3 [ 32 ] |= 0x80 ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = V_16 -> V_22 -> V_65 . V_78 ? 1 : 0 ;
return 0 ;
}
static int F_15 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
F_11 ( 0x0004 , & V_3 [ 2 ] ) ;
V_3 [ 4 ] = 0x00 ;
if ( V_16 -> V_22 -> V_65 . V_69 != 0 )
V_3 [ 5 ] = 0x80 ;
if ( V_16 -> V_22 -> V_65 . V_70 != 0 )
V_3 [ 5 ] |= 0x40 ;
return 0 ;
}
static int F_16 ( struct V_11 * V_12 , unsigned char * V_3 )
{
int V_35 ;
if ( V_12 -> V_17 -> V_22 -> V_31 &
V_32 ) {
V_3 [ 3 ] = F_17 ( V_79 ) ;
for ( V_35 = 0 ; V_35 < F_17 ( V_79 ) ; ++ V_35 )
V_3 [ V_35 + 4 ] = V_79 [ V_35 ] . V_80 ;
}
return 0 ;
}
static int F_18 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_39 * V_40 = V_12 -> V_13 -> V_26 -> V_55 ;
unsigned char * V_81 ;
unsigned char * V_82 = V_12 -> V_83 ;
unsigned char V_3 [ V_84 ] ;
int V_35 , V_85 ;
memset ( V_3 , 0 , V_84 ) ;
if ( V_16 == V_40 -> V_86 . V_87 )
V_3 [ 0 ] = 0x3f ;
else
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
if ( ! ( V_82 [ 1 ] & 0x1 ) ) {
if ( V_82 [ 2 ] ) {
F_19 ( L_5 ,
V_82 [ 2 ] ) ;
V_12 -> V_88 = V_89 ;
V_85 = - V_90 ;
goto V_91;
}
V_85 = F_4 ( V_12 , V_3 ) ;
goto V_91;
}
for ( V_35 = 0 ; V_35 < F_17 ( V_79 ) ; ++ V_35 ) {
if ( V_82 [ 2 ] == V_79 [ V_35 ] . V_80 ) {
V_3 [ 1 ] = V_82 [ 2 ] ;
V_85 = V_79 [ V_35 ] . F_20 ( V_12 , V_3 ) ;
goto V_91;
}
}
F_19 ( L_6 , V_82 [ 2 ] ) ;
V_12 -> V_88 = V_89 ;
V_85 = - V_90 ;
V_91:
V_81 = F_21 ( V_12 ) ;
if ( V_81 ) {
memcpy ( V_81 , V_3 , F_22 ( T_2 , sizeof( V_3 ) , V_12 -> V_92 ) ) ;
F_23 ( V_12 ) ;
}
if ( ! V_85 )
F_24 ( V_12 , V_93 ) ;
return V_85 ;
}
static int F_25 ( unsigned char * V_35 )
{
V_35 [ 0 ] = 0x01 ;
V_35 [ 1 ] = 0x0a ;
return 12 ;
}
static int F_26 ( struct V_15 * V_16 , unsigned char * V_35 )
{
V_35 [ 0 ] = 0x0a ;
V_35 [ 1 ] = 0x0a ;
V_35 [ 2 ] = 2 ;
V_35 [ 3 ] = ( V_16 -> V_22 -> V_65 . V_94 == 1 ) ? 0x00 : 0x10 ;
V_35 [ 4 ] = ( V_16 -> V_22 -> V_65 . V_95 == 2 ) ? 0x30 :
( V_16 -> V_22 -> V_65 . V_95 == 1 ) ? 0x20 : 0x00 ;
V_35 [ 5 ] = ( V_16 -> V_22 -> V_65 . V_96 ) ? 0x40 : 0x00 ;
V_35 [ 8 ] = 0xff ;
V_35 [ 9 ] = 0xff ;
V_35 [ 11 ] = 30 ;
return 12 ;
}
static int F_27 ( struct V_15 * V_16 , unsigned char * V_35 )
{
V_35 [ 0 ] = 0x08 ;
V_35 [ 1 ] = 0x12 ;
if ( V_16 -> V_22 -> V_65 . V_66 > 0 )
V_35 [ 2 ] = 0x04 ;
V_35 [ 12 ] = 0x20 ;
return 20 ;
}
static void F_28 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_97 :
case V_20 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void F_29 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_97 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
static int F_30 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_82 = V_12 -> V_83 ;
unsigned char * V_81 ;
int type = V_16 -> V_18 -> V_19 ( V_16 ) ;
int V_98 = ( V_12 -> V_83 [ 0 ] == V_99 ) ;
T_2 V_100 = V_98 ? 8 : 4 ;
int V_101 = 0 ;
unsigned char V_3 [ V_102 ] ;
memset ( V_3 , 0 , V_102 ) ;
switch ( V_82 [ 2 ] & 0x3f ) {
case 0x01 :
V_101 = F_25 ( & V_3 [ V_100 ] ) ;
break;
case 0x08 :
V_101 = F_27 ( V_16 , & V_3 [ V_100 ] ) ;
break;
case 0x0a :
V_101 = F_26 ( V_16 , & V_3 [ V_100 ] ) ;
break;
case 0x3f :
V_101 = F_25 ( & V_3 [ V_100 ] ) ;
V_101 += F_27 ( V_16 , & V_3 [ V_100 + V_101 ] ) ;
V_101 += F_26 ( V_16 , & V_3 [ V_100 + V_101 ] ) ;
break;
default:
F_19 ( L_7 ,
V_82 [ 2 ] & 0x3f , V_82 [ 3 ] ) ;
V_12 -> V_88 = V_103 ;
return - V_90 ;
}
V_100 += V_101 ;
if ( V_98 ) {
V_100 -= 2 ;
V_3 [ 0 ] = ( V_100 >> 8 ) & 0xff ;
V_3 [ 1 ] = V_100 & 0xff ;
V_100 += 2 ;
if ( ( V_12 -> V_13 -> V_104 & V_105 ) ||
( V_12 -> V_106 &&
( V_12 -> V_106 -> V_107 & V_105 ) ) )
F_28 ( & V_3 [ 3 ] , type ) ;
if ( ( V_16 -> V_22 -> V_65 . V_66 > 0 ) &&
( V_16 -> V_22 -> V_65 . V_108 > 0 ) )
F_29 ( & V_3 [ 3 ] , type ) ;
} else {
V_100 -= 1 ;
V_3 [ 0 ] = V_100 & 0xff ;
V_100 += 1 ;
if ( ( V_12 -> V_13 -> V_104 & V_105 ) ||
( V_12 -> V_106 &&
( V_12 -> V_106 -> V_107 & V_105 ) ) )
F_28 ( & V_3 [ 2 ] , type ) ;
if ( ( V_16 -> V_22 -> V_65 . V_66 > 0 ) &&
( V_16 -> V_22 -> V_65 . V_108 > 0 ) )
F_29 ( & V_3 [ 2 ] , type ) ;
}
V_81 = F_21 ( V_12 ) ;
if ( V_81 ) {
memcpy ( V_81 , V_3 , F_12 ( V_100 , V_12 -> V_92 ) ) ;
F_23 ( V_12 ) ;
}
F_24 ( V_12 , V_93 ) ;
return 0 ;
}
static int F_31 ( struct V_11 * V_12 )
{
unsigned char * V_82 = V_12 -> V_83 ;
unsigned char * V_81 ;
T_3 V_109 = 0 , V_110 = 0 ;
unsigned char V_3 [ V_111 ] ;
memset ( V_3 , 0 , V_111 ) ;
if ( V_82 [ 1 ] & 0x01 ) {
F_19 ( L_8
L_9 ) ;
V_12 -> V_88 = V_89 ;
return - V_112 ;
}
V_81 = F_21 ( V_12 ) ;
if ( V_12 -> V_88 != 0 ) {
F_24 ( V_12 , V_113 ) ;
return 0 ;
} else if ( ! F_32 ( V_12 , & V_109 , & V_110 ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_114 ] = V_115 ;
V_3 [ V_116 ] = V_109 ;
V_3 [ V_117 ] = V_110 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_114 ] = V_118 ;
V_3 [ V_116 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
if ( V_81 ) {
memcpy ( V_81 , V_3 , F_22 ( T_2 , sizeof( V_3 ) , V_12 -> V_92 ) ) ;
F_23 ( V_12 ) ;
}
F_24 ( V_12 , V_93 ) ;
return 0 ;
}
static int F_33 ( struct V_11 * V_12 )
{
F_24 ( V_12 , V_93 ) ;
return 0 ;
}
int F_34 ( struct V_11 * V_12 , unsigned int * V_119 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_120 * V_121 = V_16 -> V_22 ;
unsigned char * V_82 = V_12 -> V_83 ;
switch ( V_82 [ 0 ] ) {
case V_122 :
* V_119 = V_82 [ 4 ] ;
break;
case V_123 :
* V_119 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_124 :
* V_119 = V_82 [ 4 ] ;
V_12 -> V_125 = F_30 ;
break;
case V_99 :
* V_119 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
V_12 -> V_125 = F_30 ;
break;
case V_126 :
case V_127 :
* V_119 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_128 :
if ( V_121 -> V_129 . V_130 == V_131 )
V_12 -> V_125 = V_132 ;
* V_119 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_133 :
if ( V_121 -> V_129 . V_130 == V_131 )
V_12 -> V_125 = V_134 ;
* V_119 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_135 :
case V_136 :
if ( V_82 [ 0 ] == V_136 )
* V_119 = ( V_82 [ 7 ] << 8 ) | V_82 [ 8 ] ;
else
* V_119 = V_12 -> V_92 ;
if ( V_121 -> V_129 . V_130 != V_137 )
V_12 -> V_125 = V_138 ;
break;
case V_139 :
case V_140 :
if ( V_82 [ 0 ] == V_140 )
* V_119 = ( V_82 [ 7 ] << 8 ) | V_82 [ 8 ] ;
else
* V_119 = V_12 -> V_92 ;
if ( V_121 -> V_129 . V_130 != V_137 )
V_12 -> V_125 = V_141 ;
break;
case V_142 :
* V_119 = V_82 [ 4 ] ;
V_12 -> V_125 = F_31 ;
break;
case V_143 :
* V_119 = ( V_82 [ 3 ] << 8 ) + V_82 [ 4 ] ;
if ( V_12 -> V_17 -> V_144 == V_145 )
V_12 -> V_146 = V_147 ;
V_12 -> V_125 = F_18 ;
break;
case V_148 :
case V_149 :
* V_119 = ( V_82 [ 6 ] << 24 ) | ( V_82 [ 7 ] << 16 ) | ( V_82 [ 8 ] << 8 ) | V_82 [ 9 ] ;
break;
case V_150 :
case V_151 :
case V_152 :
case V_153 :
* V_119 = ( V_82 [ 10 ] << 24 ) | ( V_82 [ 11 ] << 16 ) |
( V_82 [ 12 ] << 8 ) | V_82 [ 13 ] ;
break;
case V_154 :
case V_155 :
* V_119 = ( V_82 [ 3 ] << 8 ) | V_82 [ 4 ] ;
break;
case V_156 :
* V_119 = ( V_82 [ 6 ] << 16 ) + ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_157 :
V_12 -> V_125 = V_158 ;
* V_119 = ( V_82 [ 6 ] << 24 ) | ( V_82 [ 7 ] << 16 ) | ( V_82 [ 8 ] << 8 ) | V_82 [ 9 ] ;
if ( V_12 -> V_17 -> V_144 == V_145 )
V_12 -> V_146 = V_147 ;
break;
case V_159 :
V_12 -> V_125 = F_33 ;
* V_119 = 0 ;
break;
case V_160 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_161 ) {
if ( ( V_82 [ 1 ] & 0x1f ) == V_162 &&
V_121 -> V_23 . V_24 == V_25 ) {
V_12 -> V_125 =
V_163 ;
}
* V_119 = F_35 ( & V_82 [ 6 ] ) ;
} else {
* V_119 = F_36 ( & V_82 [ 8 ] ) ;
}
break;
case V_164 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_161 ) {
if ( V_82 [ 1 ] == V_165 &&
V_121 -> V_23 . V_24 == V_25 ) {
V_12 -> V_125 =
V_166 ;
}
* V_119 = F_35 ( & V_82 [ 6 ] ) ;
} else {
* V_119 = F_36 ( & V_82 [ 8 ] ) ;
}
break;
default:
F_37 ( L_10
L_11 ,
V_12 -> V_167 -> V_168 () , V_82 [ 0 ] ) ;
V_12 -> V_169 |= V_170 ;
V_12 -> V_88 = V_171 ;
return - V_90 ;
}
return 0 ;
}
