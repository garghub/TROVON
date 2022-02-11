static void
F_1 ( struct V_1 * V_2 , unsigned char * V_3 )
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
static int
F_4 ( struct V_11 * V_12 , char * V_3 )
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
static int
F_5 ( struct V_11 * V_12 , unsigned char * V_3 )
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
static void
F_6 ( struct V_15 * V_16 , unsigned char * V_3 )
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
static int
F_8 ( struct V_11 * V_12 , unsigned char * V_3 )
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
static int
F_9 ( struct V_11 * V_12 , unsigned char * V_3 )
{
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = 0x07 ;
if ( V_12 -> V_17 -> V_22 -> V_65 . V_66 > 0 )
V_3 [ 6 ] = 0x01 ;
return 0 ;
}
static int
F_10 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
int V_67 = 0 ;
if ( V_16 -> V_22 -> V_65 . V_68 || V_16 -> V_22 -> V_65 . V_69 )
V_67 = 1 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = V_67 ? 0x3c : 0x10 ;
V_3 [ 4 ] = 0x01 ;
F_11 ( 1 , & V_3 [ 6 ] ) ;
F_12 ( V_16 -> V_22 -> V_65 . V_70 , & V_3 [ 8 ] ) ;
F_12 ( V_16 -> V_22 -> V_65 . V_71 , & V_3 [ 12 ] ) ;
if ( ! V_67 )
return 0 ;
F_12 ( V_16 -> V_22 -> V_65 . V_72 , & V_3 [ 20 ] ) ;
F_12 ( V_16 -> V_22 -> V_65 . V_73 ,
& V_3 [ 24 ] ) ;
F_12 ( V_16 -> V_22 -> V_65 . V_74 , & V_3 [ 28 ] ) ;
F_12 ( V_16 -> V_22 -> V_65 . V_75 ,
& V_3 [ 32 ] ) ;
if ( V_16 -> V_22 -> V_65 . V_75 != 0 )
V_3 [ 32 ] |= 0x80 ;
return 0 ;
}
static int
F_13 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = V_16 -> V_22 -> V_65 . V_76 ? 1 : 0 ;
return 0 ;
}
static int
F_14 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
F_11 ( 0x0004 , & V_3 [ 2 ] ) ;
V_3 [ 4 ] = 0x00 ;
if ( V_16 -> V_22 -> V_65 . V_68 != 0 )
V_3 [ 5 ] = 0x80 ;
if ( V_16 -> V_22 -> V_65 . V_69 != 0 )
V_3 [ 5 ] |= 0x40 ;
return 0 ;
}
static int
F_15 ( struct V_11 * V_12 , unsigned char * V_3 )
{
int V_35 ;
if ( V_12 -> V_17 -> V_22 -> V_31 &
V_32 ) {
V_3 [ 3 ] = F_16 ( V_77 ) ;
for ( V_35 = 0 ; V_35 < F_16 ( V_77 ) ; ++ V_35 )
V_3 [ V_35 + 4 ] = V_77 [ V_35 ] . V_78 ;
}
return 0 ;
}
int F_17 ( struct V_79 * V_80 )
{
struct V_11 * V_12 = V_80 -> V_81 ;
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_39 * V_40 = V_12 -> V_13 -> V_26 -> V_55 ;
unsigned char * V_3 , * V_82 ;
unsigned char * V_83 = V_12 -> V_84 ;
int V_35 , V_85 ;
V_82 = F_18 ( V_12 ) ;
if ( V_12 -> V_86 < V_87 &&
( V_12 -> V_88 & V_89 ) ) {
V_3 = F_19 ( V_87 , V_90 ) ;
if ( ! V_3 ) {
F_20 ( V_12 ) ;
V_12 -> V_91 = V_92 ;
return - V_93 ;
}
} else {
V_3 = V_82 ;
}
if ( V_16 == V_40 -> V_94 . V_95 )
V_3 [ 0 ] = 0x3f ;
else
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
if ( ! ( V_83 [ 1 ] & 0x1 ) ) {
if ( V_83 [ 2 ] ) {
F_21 ( L_5 ,
V_83 [ 2 ] ) ;
V_12 -> V_91 = V_96 ;
V_85 = - V_97 ;
goto V_98;
}
V_85 = F_4 ( V_12 , V_3 ) ;
goto V_98;
}
for ( V_35 = 0 ; V_35 < F_16 ( V_77 ) ; ++ V_35 ) {
if ( V_83 [ 2 ] == V_77 [ V_35 ] . V_78 ) {
V_3 [ 1 ] = V_83 [ 2 ] ;
V_85 = V_77 [ V_35 ] . F_22 ( V_12 , V_3 ) ;
goto V_98;
}
}
F_21 ( L_6 , V_83 [ 2 ] ) ;
V_12 -> V_91 = V_96 ;
V_85 = - V_97 ;
V_98:
if ( V_3 != V_82 ) {
memcpy ( V_82 , V_3 , V_12 -> V_86 ) ;
F_23 ( V_3 ) ;
}
F_20 ( V_12 ) ;
if ( ! V_85 ) {
V_80 -> V_99 = V_100 ;
F_24 ( V_80 , 1 ) ;
}
return V_85 ;
}
int F_25 ( struct V_79 * V_80 )
{
struct V_11 * V_12 = V_80 -> V_81 ;
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 ;
unsigned long long V_101 = V_16 -> V_18 -> V_102 ( V_16 ) ;
T_2 V_103 ;
if ( V_101 >= 0x00000000ffffffff )
V_103 = 0xffffffff ;
else
V_103 = ( T_2 ) V_101 ;
V_3 = F_18 ( V_12 ) ;
V_3 [ 0 ] = ( V_103 >> 24 ) & 0xff ;
V_3 [ 1 ] = ( V_103 >> 16 ) & 0xff ;
V_3 [ 2 ] = ( V_103 >> 8 ) & 0xff ;
V_3 [ 3 ] = V_103 & 0xff ;
V_3 [ 4 ] = ( V_16 -> V_22 -> V_65 . V_104 >> 24 ) & 0xff ;
V_3 [ 5 ] = ( V_16 -> V_22 -> V_65 . V_104 >> 16 ) & 0xff ;
V_3 [ 6 ] = ( V_16 -> V_22 -> V_65 . V_104 >> 8 ) & 0xff ;
V_3 [ 7 ] = V_16 -> V_22 -> V_65 . V_104 & 0xff ;
F_20 ( V_12 ) ;
V_80 -> V_99 = V_100 ;
F_24 ( V_80 , 1 ) ;
return 0 ;
}
int F_26 ( struct V_79 * V_80 )
{
struct V_11 * V_12 = V_80 -> V_81 ;
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 ;
unsigned long long V_103 = V_16 -> V_18 -> V_102 ( V_16 ) ;
V_3 = F_18 ( V_12 ) ;
V_3 [ 0 ] = ( V_103 >> 56 ) & 0xff ;
V_3 [ 1 ] = ( V_103 >> 48 ) & 0xff ;
V_3 [ 2 ] = ( V_103 >> 40 ) & 0xff ;
V_3 [ 3 ] = ( V_103 >> 32 ) & 0xff ;
V_3 [ 4 ] = ( V_103 >> 24 ) & 0xff ;
V_3 [ 5 ] = ( V_103 >> 16 ) & 0xff ;
V_3 [ 6 ] = ( V_103 >> 8 ) & 0xff ;
V_3 [ 7 ] = V_103 & 0xff ;
V_3 [ 8 ] = ( V_16 -> V_22 -> V_65 . V_104 >> 24 ) & 0xff ;
V_3 [ 9 ] = ( V_16 -> V_22 -> V_65 . V_104 >> 16 ) & 0xff ;
V_3 [ 10 ] = ( V_16 -> V_22 -> V_65 . V_104 >> 8 ) & 0xff ;
V_3 [ 11 ] = V_16 -> V_22 -> V_65 . V_104 & 0xff ;
if ( V_16 -> V_22 -> V_65 . V_68 || V_16 -> V_22 -> V_65 . V_69 )
V_3 [ 14 ] = 0x80 ;
F_20 ( V_12 ) ;
V_80 -> V_99 = V_100 ;
F_24 ( V_80 , 1 ) ;
return 0 ;
}
static int
F_27 ( unsigned char * V_35 )
{
V_35 [ 0 ] = 0x01 ;
V_35 [ 1 ] = 0x0a ;
return 12 ;
}
static int
F_28 ( struct V_15 * V_16 , unsigned char * V_35 )
{
V_35 [ 0 ] = 0x0a ;
V_35 [ 1 ] = 0x0a ;
V_35 [ 2 ] = 2 ;
V_35 [ 3 ] = ( V_16 -> V_22 -> V_65 . V_105 == 1 ) ? 0x00 : 0x10 ;
V_35 [ 4 ] = ( V_16 -> V_22 -> V_65 . V_106 == 2 ) ? 0x30 :
( V_16 -> V_22 -> V_65 . V_106 == 1 ) ? 0x20 : 0x00 ;
V_35 [ 5 ] = ( V_16 -> V_22 -> V_65 . V_107 ) ? 0x40 : 0x00 ;
V_35 [ 8 ] = 0xff ;
V_35 [ 9 ] = 0xff ;
V_35 [ 11 ] = 30 ;
return 12 ;
}
static int
F_29 ( struct V_15 * V_16 , unsigned char * V_35 )
{
V_35 [ 0 ] = 0x08 ;
V_35 [ 1 ] = 0x12 ;
if ( V_16 -> V_22 -> V_65 . V_66 > 0 )
V_35 [ 2 ] = 0x04 ;
V_35 [ 12 ] = 0x20 ;
return 20 ;
}
static void
F_30 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_108 :
case V_20 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void
F_31 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_108 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
int F_32 ( struct V_79 * V_80 )
{
struct V_11 * V_12 = V_80 -> V_81 ;
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_83 = V_12 -> V_84 ;
unsigned char * V_109 ;
int type = V_16 -> V_18 -> V_19 ( V_16 ) ;
int V_110 = ( V_12 -> V_84 [ 0 ] == V_111 ) ;
int V_112 = V_110 ? 8 : 4 ;
int V_113 = 0 ;
unsigned char V_3 [ V_114 ] ;
memset ( V_3 , 0 , V_114 ) ;
switch ( V_83 [ 2 ] & 0x3f ) {
case 0x01 :
V_113 = F_27 ( & V_3 [ V_112 ] ) ;
break;
case 0x08 :
V_113 = F_29 ( V_16 , & V_3 [ V_112 ] ) ;
break;
case 0x0a :
V_113 = F_28 ( V_16 , & V_3 [ V_112 ] ) ;
break;
case 0x3f :
V_113 = F_27 ( & V_3 [ V_112 ] ) ;
V_113 += F_29 ( V_16 , & V_3 [ V_112 + V_113 ] ) ;
V_113 += F_28 ( V_16 , & V_3 [ V_112 + V_113 ] ) ;
break;
default:
F_21 ( L_7 ,
V_83 [ 2 ] & 0x3f , V_83 [ 3 ] ) ;
V_12 -> V_91 = V_115 ;
return - V_97 ;
}
V_112 += V_113 ;
if ( V_110 ) {
V_112 -= 2 ;
V_3 [ 0 ] = ( V_112 >> 8 ) & 0xff ;
V_3 [ 1 ] = V_112 & 0xff ;
if ( ( V_12 -> V_13 -> V_116 & V_117 ) ||
( V_12 -> V_118 &&
( V_12 -> V_118 -> V_119 & V_117 ) ) )
F_30 ( & V_3 [ 3 ] , type ) ;
if ( ( V_16 -> V_22 -> V_65 . V_66 > 0 ) &&
( V_16 -> V_22 -> V_65 . V_120 > 0 ) )
F_31 ( & V_3 [ 3 ] , type ) ;
if ( ( V_112 + 2 ) > V_12 -> V_86 )
V_112 = V_12 -> V_86 ;
} else {
V_112 -= 1 ;
V_3 [ 0 ] = V_112 & 0xff ;
if ( ( V_12 -> V_13 -> V_116 & V_117 ) ||
( V_12 -> V_118 &&
( V_12 -> V_118 -> V_119 & V_117 ) ) )
F_30 ( & V_3 [ 2 ] , type ) ;
if ( ( V_16 -> V_22 -> V_65 . V_66 > 0 ) &&
( V_16 -> V_22 -> V_65 . V_120 > 0 ) )
F_31 ( & V_3 [ 2 ] , type ) ;
if ( ( V_112 + 1 ) > V_12 -> V_86 )
V_112 = V_12 -> V_86 ;
}
V_109 = F_18 ( V_12 ) ;
memcpy ( V_109 , V_3 , V_112 ) ;
F_20 ( V_12 ) ;
V_80 -> V_99 = V_100 ;
F_24 ( V_80 , 1 ) ;
return 0 ;
}
int F_33 ( struct V_79 * V_80 )
{
struct V_11 * V_12 = V_80 -> V_81 ;
unsigned char * V_83 = V_12 -> V_84 ;
unsigned char * V_3 ;
T_3 V_121 = 0 , V_122 = 0 ;
int V_123 = 0 ;
if ( V_83 [ 1 ] & 0x01 ) {
F_21 ( L_8
L_9 ) ;
V_12 -> V_91 = V_96 ;
return - V_124 ;
}
V_3 = F_18 ( V_12 ) ;
if ( ! F_34 ( V_12 , & V_121 , & V_122 ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_125 ] = V_126 ;
if ( V_12 -> V_86 < 18 ) {
V_3 [ 7 ] = 0x00 ;
V_123 = - V_97 ;
goto V_127;
}
V_3 [ V_128 ] = V_121 ;
V_3 [ V_129 ] = V_122 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_125 ] = V_130 ;
if ( V_12 -> V_86 < 18 ) {
V_3 [ 7 ] = 0x00 ;
V_123 = - V_97 ;
goto V_127;
}
V_3 [ V_128 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
V_127:
F_20 ( V_12 ) ;
V_80 -> V_99 = V_100 ;
F_24 ( V_80 , 1 ) ;
return 0 ;
}
int F_35 ( struct V_79 * V_80 )
{
struct V_11 * V_12 = V_80 -> V_81 ;
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 , * V_131 = NULL ;
unsigned char * V_83 = & V_12 -> V_84 [ 0 ] ;
T_4 V_132 ;
unsigned int V_133 = V_12 -> V_86 , V_134 ;
int V_85 = 0 , V_112 ;
unsigned short V_135 , V_136 ;
if ( ! V_16 -> V_18 -> V_137 ) {
F_21 ( L_10 ,
V_16 -> V_18 -> V_138 ) ;
V_12 -> V_91 = V_139 ;
return - V_124 ;
}
V_112 = 8 ;
V_133 -= 8 ;
V_135 = F_36 ( & V_83 [ 0 ] ) ;
V_136 = F_36 ( & V_83 [ 2 ] ) ;
V_3 = F_18 ( V_12 ) ;
V_131 = & V_3 [ V_112 ] ;
F_37 ( L_11
L_12 , V_16 -> V_18 -> V_138 , V_135 , V_136 , V_133 , V_131 ) ;
while ( V_133 ) {
V_132 = F_38 ( & V_131 [ 0 ] ) ;
V_134 = F_39 ( & V_131 [ 8 ] ) ;
F_37 ( L_13 ,
( unsigned long long ) V_132 , V_134 ) ;
V_85 = V_16 -> V_18 -> V_137 ( V_16 , V_132 , V_134 ) ;
if ( V_85 < 0 ) {
F_21 ( L_14 ,
V_85 ) ;
goto V_123;
}
V_131 += 16 ;
V_133 -= 16 ;
}
V_123:
F_20 ( V_12 ) ;
if ( ! V_85 ) {
V_80 -> V_99 = V_100 ;
F_24 ( V_80 , 1 ) ;
}
return V_85 ;
}
int F_40 ( struct V_79 * V_80 )
{
struct V_11 * V_12 = V_80 -> V_81 ;
struct V_15 * V_16 = V_12 -> V_17 ;
T_4 V_134 ;
T_4 V_132 = V_12 -> V_140 ;
T_2 V_141 ;
int V_85 ;
if ( ! V_16 -> V_18 -> V_137 ) {
F_21 ( L_15
L_16 , V_16 -> V_18 -> V_138 ) ;
V_12 -> V_91 = V_139 ;
return - V_124 ;
}
if ( V_12 -> V_84 [ 0 ] == V_142 )
V_141 = F_36 ( & V_12 -> V_84 [ 7 ] ) ;
else if ( V_12 -> V_84 [ 0 ] == V_143 )
V_141 = F_39 ( & V_12 -> V_84 [ 10 ] ) ;
else
V_141 = F_39 ( & V_12 -> V_84 [ 28 ] ) ;
if ( V_141 != 0 )
V_134 = V_141 ;
else
V_134 = ( V_16 -> V_18 -> V_102 ( V_16 ) - V_132 ) ;
F_37 ( L_17 ,
( unsigned long long ) V_132 , ( unsigned long long ) V_134 ) ;
V_85 = V_16 -> V_18 -> V_137 ( V_16 , V_132 , V_134 ) ;
if ( V_85 < 0 ) {
F_37 ( L_18 ) ;
return V_85 ;
}
V_80 -> V_99 = V_100 ;
F_24 ( V_80 , 1 ) ;
return 0 ;
}
int F_41 ( struct V_79 * V_80 )
{
struct V_15 * V_16 = V_80 -> V_81 -> V_17 ;
struct V_11 * V_12 = V_80 -> V_81 ;
if ( ! V_16 -> V_18 -> V_144 ) {
F_21 ( L_19
L_16 , V_16 -> V_18 -> V_138 ) ;
V_12 -> V_91 = V_139 ;
return - V_124 ;
}
V_16 -> V_18 -> V_144 ( V_80 ) ;
return 0 ;
}
int F_42 ( struct V_79 * V_80 )
{
V_80 -> V_99 = V_100 ;
F_24 ( V_80 , 1 ) ;
return 0 ;
}
void F_43 ( struct V_79 * V_80 , unsigned char * V_83 )
{
struct V_11 * V_12 = V_80 -> V_81 ;
unsigned int V_145 = F_44 ( V_12 -> V_84 ) ;
memcpy ( V_83 , V_12 -> V_84 , V_145 ) ;
if ( V_12 -> V_88 & V_146 ) {
unsigned long long V_132 = V_80 -> V_147 ;
T_2 V_148 = V_80 -> V_149 ;
switch ( V_145 ) {
case 6 :
V_83 [ 1 ] = ( V_132 >> 16 ) & 0x1f ;
V_83 [ 2 ] = ( V_132 >> 8 ) & 0xff ;
V_83 [ 3 ] = V_132 & 0xff ;
V_83 [ 4 ] = V_148 & 0xff ;
break;
case 10 :
F_12 ( V_132 , & V_83 [ 2 ] ) ;
F_11 ( V_148 , & V_83 [ 7 ] ) ;
break;
case 12 :
F_12 ( V_132 , & V_83 [ 2 ] ) ;
F_12 ( V_148 , & V_83 [ 6 ] ) ;
break;
case 16 :
F_45 ( V_132 , & V_83 [ 2 ] ) ;
F_12 ( V_148 , & V_83 [ 10 ] ) ;
break;
case 32 :
F_45 ( V_132 , & V_83 [ 12 ] ) ;
F_12 ( V_148 , & V_83 [ 28 ] ) ;
break;
default:
F_46 () ;
}
}
}
