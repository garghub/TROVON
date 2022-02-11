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
unsigned char * V_3 , * V_81 ;
unsigned char * V_82 = V_12 -> V_83 ;
int V_35 , V_84 ;
V_81 = F_19 ( V_12 ) ;
if ( V_12 -> V_85 < V_86 &&
( V_12 -> V_87 & V_88 ) ) {
V_3 = F_20 ( V_86 , V_89 ) ;
if ( ! V_3 ) {
F_21 ( V_12 ) ;
V_12 -> V_90 = V_91 ;
return - V_92 ;
}
} else {
V_3 = V_81 ;
}
if ( V_16 == V_40 -> V_93 . V_94 )
V_3 [ 0 ] = 0x3f ;
else
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
if ( ! ( V_82 [ 1 ] & 0x1 ) ) {
if ( V_82 [ 2 ] ) {
F_22 ( L_5 ,
V_82 [ 2 ] ) ;
V_12 -> V_90 = V_95 ;
V_84 = - V_96 ;
goto V_97;
}
V_84 = F_4 ( V_12 , V_3 ) ;
goto V_97;
}
for ( V_35 = 0 ; V_35 < F_17 ( V_79 ) ; ++ V_35 ) {
if ( V_82 [ 2 ] == V_79 [ V_35 ] . V_80 ) {
V_3 [ 1 ] = V_82 [ 2 ] ;
V_84 = V_79 [ V_35 ] . F_23 ( V_12 , V_3 ) ;
goto V_97;
}
}
F_22 ( L_6 , V_82 [ 2 ] ) ;
V_12 -> V_90 = V_95 ;
V_84 = - V_96 ;
V_97:
if ( V_3 != V_81 ) {
memcpy ( V_81 , V_3 , V_12 -> V_85 ) ;
F_24 ( V_3 ) ;
}
F_21 ( V_12 ) ;
if ( ! V_84 )
F_25 ( V_12 , V_98 ) ;
return V_84 ;
}
static int F_26 ( unsigned char * V_35 )
{
V_35 [ 0 ] = 0x01 ;
V_35 [ 1 ] = 0x0a ;
return 12 ;
}
static int F_27 ( struct V_15 * V_16 , unsigned char * V_35 )
{
V_35 [ 0 ] = 0x0a ;
V_35 [ 1 ] = 0x0a ;
V_35 [ 2 ] = 2 ;
V_35 [ 3 ] = ( V_16 -> V_22 -> V_65 . V_99 == 1 ) ? 0x00 : 0x10 ;
V_35 [ 4 ] = ( V_16 -> V_22 -> V_65 . V_100 == 2 ) ? 0x30 :
( V_16 -> V_22 -> V_65 . V_100 == 1 ) ? 0x20 : 0x00 ;
V_35 [ 5 ] = ( V_16 -> V_22 -> V_65 . V_101 ) ? 0x40 : 0x00 ;
V_35 [ 8 ] = 0xff ;
V_35 [ 9 ] = 0xff ;
V_35 [ 11 ] = 30 ;
return 12 ;
}
static int F_28 ( struct V_15 * V_16 , unsigned char * V_35 )
{
V_35 [ 0 ] = 0x08 ;
V_35 [ 1 ] = 0x12 ;
if ( V_16 -> V_22 -> V_65 . V_66 > 0 )
V_35 [ 2 ] = 0x04 ;
V_35 [ 12 ] = 0x20 ;
return 20 ;
}
static void F_29 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_102 :
case V_20 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void F_30 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_102 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
static int F_31 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_82 = V_12 -> V_83 ;
unsigned char * V_103 ;
int type = V_16 -> V_18 -> V_19 ( V_16 ) ;
int V_104 = ( V_12 -> V_83 [ 0 ] == V_105 ) ;
int V_106 = V_104 ? 8 : 4 ;
int V_107 = 0 ;
unsigned char V_3 [ V_108 ] ;
memset ( V_3 , 0 , V_108 ) ;
switch ( V_82 [ 2 ] & 0x3f ) {
case 0x01 :
V_107 = F_26 ( & V_3 [ V_106 ] ) ;
break;
case 0x08 :
V_107 = F_28 ( V_16 , & V_3 [ V_106 ] ) ;
break;
case 0x0a :
V_107 = F_27 ( V_16 , & V_3 [ V_106 ] ) ;
break;
case 0x3f :
V_107 = F_26 ( & V_3 [ V_106 ] ) ;
V_107 += F_28 ( V_16 , & V_3 [ V_106 + V_107 ] ) ;
V_107 += F_27 ( V_16 , & V_3 [ V_106 + V_107 ] ) ;
break;
default:
F_22 ( L_7 ,
V_82 [ 2 ] & 0x3f , V_82 [ 3 ] ) ;
V_12 -> V_90 = V_109 ;
return - V_96 ;
}
V_106 += V_107 ;
if ( V_104 ) {
V_106 -= 2 ;
V_3 [ 0 ] = ( V_106 >> 8 ) & 0xff ;
V_3 [ 1 ] = V_106 & 0xff ;
if ( ( V_12 -> V_13 -> V_110 & V_111 ) ||
( V_12 -> V_112 &&
( V_12 -> V_112 -> V_113 & V_111 ) ) )
F_29 ( & V_3 [ 3 ] , type ) ;
if ( ( V_16 -> V_22 -> V_65 . V_66 > 0 ) &&
( V_16 -> V_22 -> V_65 . V_114 > 0 ) )
F_30 ( & V_3 [ 3 ] , type ) ;
if ( ( V_106 + 2 ) > V_12 -> V_85 )
V_106 = V_12 -> V_85 ;
} else {
V_106 -= 1 ;
V_3 [ 0 ] = V_106 & 0xff ;
if ( ( V_12 -> V_13 -> V_110 & V_111 ) ||
( V_12 -> V_112 &&
( V_12 -> V_112 -> V_113 & V_111 ) ) )
F_29 ( & V_3 [ 2 ] , type ) ;
if ( ( V_16 -> V_22 -> V_65 . V_66 > 0 ) &&
( V_16 -> V_22 -> V_65 . V_114 > 0 ) )
F_30 ( & V_3 [ 2 ] , type ) ;
if ( ( V_106 + 1 ) > V_12 -> V_85 )
V_106 = V_12 -> V_85 ;
}
V_103 = F_19 ( V_12 ) ;
memcpy ( V_103 , V_3 , V_106 ) ;
F_21 ( V_12 ) ;
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
static int F_32 ( struct V_11 * V_12 )
{
unsigned char * V_82 = V_12 -> V_83 ;
unsigned char * V_103 ;
T_3 V_115 = 0 , V_116 = 0 ;
unsigned char V_3 [ V_117 ] ;
memset ( V_3 , 0 , V_117 ) ;
if ( V_82 [ 1 ] & 0x01 ) {
F_22 ( L_8
L_9 ) ;
V_12 -> V_90 = V_95 ;
return - V_118 ;
}
V_103 = F_19 ( V_12 ) ;
if ( V_12 -> V_90 != 0 ) {
F_25 ( V_12 , V_119 ) ;
return 0 ;
} else if ( ! F_33 ( V_12 , & V_115 , & V_116 ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_120 ] = V_121 ;
V_3 [ V_122 ] = V_115 ;
V_3 [ V_123 ] = V_116 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_120 ] = V_124 ;
V_3 [ V_122 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
if ( V_103 ) {
memcpy ( V_103 , V_3 , F_34 ( T_2 , sizeof( V_3 ) , V_12 -> V_85 ) ) ;
F_21 ( V_12 ) ;
}
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
static int F_35 ( struct V_11 * V_12 )
{
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
int F_36 ( struct V_11 * V_12 , unsigned int * V_125 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_126 * V_127 = V_16 -> V_22 ;
unsigned char * V_82 = V_12 -> V_83 ;
switch ( V_82 [ 0 ] ) {
case V_128 :
* V_125 = V_82 [ 4 ] ;
break;
case V_129 :
* V_125 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_130 :
* V_125 = V_82 [ 4 ] ;
V_12 -> V_131 = F_31 ;
break;
case V_105 :
* V_125 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
V_12 -> V_131 = F_31 ;
break;
case V_132 :
case V_133 :
* V_125 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_134 :
if ( V_127 -> V_135 . V_136 == V_137 )
V_12 -> V_131 = V_138 ;
* V_125 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_139 :
if ( V_127 -> V_135 . V_136 == V_137 )
V_12 -> V_131 = V_140 ;
* V_125 = ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_141 :
case V_142 :
if ( V_82 [ 0 ] == V_142 )
* V_125 = ( V_82 [ 7 ] << 8 ) | V_82 [ 8 ] ;
else
* V_125 = V_12 -> V_85 ;
if ( V_127 -> V_135 . V_136 != V_143 )
V_12 -> V_131 = V_144 ;
break;
case V_145 :
case V_146 :
if ( V_82 [ 0 ] == V_146 )
* V_125 = ( V_82 [ 7 ] << 8 ) | V_82 [ 8 ] ;
else
* V_125 = V_12 -> V_85 ;
if ( V_127 -> V_135 . V_136 != V_143 )
V_12 -> V_131 = V_147 ;
break;
case V_148 :
* V_125 = V_82 [ 4 ] ;
V_12 -> V_131 = F_32 ;
break;
case V_149 :
* V_125 = ( V_82 [ 3 ] << 8 ) + V_82 [ 4 ] ;
if ( V_12 -> V_17 -> V_150 == V_151 )
V_12 -> V_152 = V_153 ;
V_12 -> V_131 = F_18 ;
break;
case V_154 :
case V_155 :
* V_125 = ( V_82 [ 6 ] << 24 ) | ( V_82 [ 7 ] << 16 ) | ( V_82 [ 8 ] << 8 ) | V_82 [ 9 ] ;
break;
case V_156 :
case V_157 :
case V_158 :
case V_159 :
* V_125 = ( V_82 [ 10 ] << 24 ) | ( V_82 [ 11 ] << 16 ) |
( V_82 [ 12 ] << 8 ) | V_82 [ 13 ] ;
break;
case V_160 :
case V_161 :
* V_125 = ( V_82 [ 3 ] << 8 ) | V_82 [ 4 ] ;
break;
case V_162 :
* V_125 = ( V_82 [ 6 ] << 16 ) + ( V_82 [ 7 ] << 8 ) + V_82 [ 8 ] ;
break;
case V_163 :
V_12 -> V_131 = V_164 ;
* V_125 = ( V_82 [ 6 ] << 24 ) | ( V_82 [ 7 ] << 16 ) | ( V_82 [ 8 ] << 8 ) | V_82 [ 9 ] ;
if ( V_12 -> V_17 -> V_150 == V_151 )
V_12 -> V_152 = V_153 ;
break;
case V_165 :
V_12 -> V_131 = F_35 ;
* V_125 = 0 ;
break;
case V_166 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_167 ) {
if ( ( V_82 [ 1 ] & 0x1f ) == V_168 &&
V_127 -> V_23 . V_24 == V_25 ) {
V_12 -> V_131 =
V_169 ;
}
* V_125 = F_37 ( & V_82 [ 6 ] ) ;
} else {
* V_125 = F_38 ( & V_82 [ 8 ] ) ;
}
break;
case V_170 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_167 ) {
if ( V_82 [ 1 ] == V_171 &&
V_127 -> V_23 . V_24 == V_25 ) {
V_12 -> V_131 =
V_172 ;
}
* V_125 = F_37 ( & V_82 [ 6 ] ) ;
} else {
* V_125 = F_38 ( & V_82 [ 8 ] ) ;
}
break;
default:
F_39 ( L_10
L_11 ,
V_12 -> V_173 -> V_174 () , V_82 [ 0 ] ) ;
V_12 -> V_87 |= V_175 ;
V_12 -> V_90 = V_176 ;
return - V_96 ;
}
return 0 ;
}
