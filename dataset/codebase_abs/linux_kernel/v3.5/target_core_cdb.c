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
static int
F_14 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = V_16 -> V_22 -> V_65 . V_78 ? 1 : 0 ;
return 0 ;
}
static int
F_15 ( struct V_11 * V_12 , unsigned char * V_3 )
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
static int
F_16 ( struct V_11 * V_12 , unsigned char * V_3 )
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
int F_18 ( struct V_11 * V_12 )
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
int F_26 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 ;
unsigned long long V_99 = V_16 -> V_18 -> V_100 ( V_16 ) ;
T_2 V_101 ;
if ( V_99 >= 0x00000000ffffffff )
V_101 = 0xffffffff ;
else
V_101 = ( T_2 ) V_99 ;
V_3 = F_19 ( V_12 ) ;
V_3 [ 0 ] = ( V_101 >> 24 ) & 0xff ;
V_3 [ 1 ] = ( V_101 >> 16 ) & 0xff ;
V_3 [ 2 ] = ( V_101 >> 8 ) & 0xff ;
V_3 [ 3 ] = V_101 & 0xff ;
V_3 [ 4 ] = ( V_16 -> V_22 -> V_65 . V_102 >> 24 ) & 0xff ;
V_3 [ 5 ] = ( V_16 -> V_22 -> V_65 . V_102 >> 16 ) & 0xff ;
V_3 [ 6 ] = ( V_16 -> V_22 -> V_65 . V_102 >> 8 ) & 0xff ;
V_3 [ 7 ] = V_16 -> V_22 -> V_65 . V_102 & 0xff ;
F_21 ( V_12 ) ;
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
int F_27 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 ;
unsigned long long V_101 = V_16 -> V_18 -> V_100 ( V_16 ) ;
V_3 = F_19 ( V_12 ) ;
V_3 [ 0 ] = ( V_101 >> 56 ) & 0xff ;
V_3 [ 1 ] = ( V_101 >> 48 ) & 0xff ;
V_3 [ 2 ] = ( V_101 >> 40 ) & 0xff ;
V_3 [ 3 ] = ( V_101 >> 32 ) & 0xff ;
V_3 [ 4 ] = ( V_101 >> 24 ) & 0xff ;
V_3 [ 5 ] = ( V_101 >> 16 ) & 0xff ;
V_3 [ 6 ] = ( V_101 >> 8 ) & 0xff ;
V_3 [ 7 ] = V_101 & 0xff ;
V_3 [ 8 ] = ( V_16 -> V_22 -> V_65 . V_102 >> 24 ) & 0xff ;
V_3 [ 9 ] = ( V_16 -> V_22 -> V_65 . V_102 >> 16 ) & 0xff ;
V_3 [ 10 ] = ( V_16 -> V_22 -> V_65 . V_102 >> 8 ) & 0xff ;
V_3 [ 11 ] = V_16 -> V_22 -> V_65 . V_102 & 0xff ;
if ( V_16 -> V_22 -> V_65 . V_69 || V_16 -> V_22 -> V_65 . V_70 )
V_3 [ 14 ] = 0x80 ;
F_21 ( V_12 ) ;
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
static int
F_28 ( unsigned char * V_35 )
{
V_35 [ 0 ] = 0x01 ;
V_35 [ 1 ] = 0x0a ;
return 12 ;
}
static int
F_29 ( struct V_15 * V_16 , unsigned char * V_35 )
{
V_35 [ 0 ] = 0x0a ;
V_35 [ 1 ] = 0x0a ;
V_35 [ 2 ] = 2 ;
V_35 [ 3 ] = ( V_16 -> V_22 -> V_65 . V_103 == 1 ) ? 0x00 : 0x10 ;
V_35 [ 4 ] = ( V_16 -> V_22 -> V_65 . V_104 == 2 ) ? 0x30 :
( V_16 -> V_22 -> V_65 . V_104 == 1 ) ? 0x20 : 0x00 ;
V_35 [ 5 ] = ( V_16 -> V_22 -> V_65 . V_105 ) ? 0x40 : 0x00 ;
V_35 [ 8 ] = 0xff ;
V_35 [ 9 ] = 0xff ;
V_35 [ 11 ] = 30 ;
return 12 ;
}
static int
F_30 ( struct V_15 * V_16 , unsigned char * V_35 )
{
V_35 [ 0 ] = 0x08 ;
V_35 [ 1 ] = 0x12 ;
if ( V_16 -> V_22 -> V_65 . V_66 > 0 )
V_35 [ 2 ] = 0x04 ;
V_35 [ 12 ] = 0x20 ;
return 20 ;
}
static void
F_31 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_106 :
case V_20 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void
F_32 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_106 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
int F_33 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_82 = V_12 -> V_83 ;
unsigned char * V_107 ;
int type = V_16 -> V_18 -> V_19 ( V_16 ) ;
int V_108 = ( V_12 -> V_83 [ 0 ] == V_109 ) ;
int V_110 = V_108 ? 8 : 4 ;
int V_111 = 0 ;
unsigned char V_3 [ V_112 ] ;
memset ( V_3 , 0 , V_112 ) ;
switch ( V_82 [ 2 ] & 0x3f ) {
case 0x01 :
V_111 = F_28 ( & V_3 [ V_110 ] ) ;
break;
case 0x08 :
V_111 = F_30 ( V_16 , & V_3 [ V_110 ] ) ;
break;
case 0x0a :
V_111 = F_29 ( V_16 , & V_3 [ V_110 ] ) ;
break;
case 0x3f :
V_111 = F_28 ( & V_3 [ V_110 ] ) ;
V_111 += F_30 ( V_16 , & V_3 [ V_110 + V_111 ] ) ;
V_111 += F_29 ( V_16 , & V_3 [ V_110 + V_111 ] ) ;
break;
default:
F_22 ( L_7 ,
V_82 [ 2 ] & 0x3f , V_82 [ 3 ] ) ;
V_12 -> V_90 = V_113 ;
return - V_96 ;
}
V_110 += V_111 ;
if ( V_108 ) {
V_110 -= 2 ;
V_3 [ 0 ] = ( V_110 >> 8 ) & 0xff ;
V_3 [ 1 ] = V_110 & 0xff ;
if ( ( V_12 -> V_13 -> V_114 & V_115 ) ||
( V_12 -> V_116 &&
( V_12 -> V_116 -> V_117 & V_115 ) ) )
F_31 ( & V_3 [ 3 ] , type ) ;
if ( ( V_16 -> V_22 -> V_65 . V_66 > 0 ) &&
( V_16 -> V_22 -> V_65 . V_118 > 0 ) )
F_32 ( & V_3 [ 3 ] , type ) ;
if ( ( V_110 + 2 ) > V_12 -> V_85 )
V_110 = V_12 -> V_85 ;
} else {
V_110 -= 1 ;
V_3 [ 0 ] = V_110 & 0xff ;
if ( ( V_12 -> V_13 -> V_114 & V_115 ) ||
( V_12 -> V_116 &&
( V_12 -> V_116 -> V_117 & V_115 ) ) )
F_31 ( & V_3 [ 2 ] , type ) ;
if ( ( V_16 -> V_22 -> V_65 . V_66 > 0 ) &&
( V_16 -> V_22 -> V_65 . V_118 > 0 ) )
F_32 ( & V_3 [ 2 ] , type ) ;
if ( ( V_110 + 1 ) > V_12 -> V_85 )
V_110 = V_12 -> V_85 ;
}
V_107 = F_19 ( V_12 ) ;
memcpy ( V_107 , V_3 , V_110 ) ;
F_21 ( V_12 ) ;
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
int F_34 ( struct V_11 * V_12 )
{
unsigned char * V_82 = V_12 -> V_83 ;
unsigned char * V_3 ;
T_3 V_119 = 0 , V_120 = 0 ;
int V_121 = 0 ;
if ( V_82 [ 1 ] & 0x01 ) {
F_22 ( L_8
L_9 ) ;
V_12 -> V_90 = V_95 ;
return - V_122 ;
}
V_3 = F_19 ( V_12 ) ;
if ( ! F_35 ( V_12 , & V_119 , & V_120 ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_123 ] = V_124 ;
if ( V_12 -> V_85 < 18 ) {
V_3 [ 7 ] = 0x00 ;
V_121 = - V_96 ;
goto V_125;
}
V_3 [ V_126 ] = V_119 ;
V_3 [ V_127 ] = V_120 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_123 ] = V_128 ;
if ( V_12 -> V_85 < 18 ) {
V_3 [ 7 ] = 0x00 ;
V_121 = - V_96 ;
goto V_125;
}
V_3 [ V_126 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
V_125:
F_21 ( V_12 ) ;
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
int F_36 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_3 , * V_129 = NULL ;
unsigned char * V_82 = & V_12 -> V_83 [ 0 ] ;
T_4 V_130 ;
unsigned int V_131 = V_12 -> V_85 , V_132 ;
int V_84 = 0 , V_110 ;
unsigned short V_133 , V_134 ;
if ( ! V_16 -> V_18 -> V_135 ) {
F_22 ( L_10 ,
V_16 -> V_18 -> V_136 ) ;
V_12 -> V_90 = V_137 ;
return - V_122 ;
}
V_110 = 8 ;
V_131 -= 8 ;
V_133 = F_37 ( & V_82 [ 0 ] ) ;
V_134 = F_37 ( & V_82 [ 2 ] ) ;
V_3 = F_19 ( V_12 ) ;
V_129 = & V_3 [ V_110 ] ;
F_38 ( L_11
L_12 , V_16 -> V_18 -> V_136 , V_133 , V_134 , V_131 , V_129 ) ;
while ( V_131 ) {
V_130 = F_39 ( & V_129 [ 0 ] ) ;
V_132 = F_40 ( & V_129 [ 8 ] ) ;
F_38 ( L_13 ,
( unsigned long long ) V_130 , V_132 ) ;
V_84 = V_16 -> V_18 -> V_135 ( V_16 , V_130 , V_132 ) ;
if ( V_84 < 0 ) {
F_22 ( L_14 ,
V_84 ) ;
goto V_121;
}
V_129 += 16 ;
V_131 -= 16 ;
}
V_121:
F_21 ( V_12 ) ;
if ( ! V_84 )
F_25 ( V_12 , V_98 ) ;
return V_84 ;
}
int F_41 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_4 V_132 ;
T_4 V_130 = V_12 -> V_138 ;
T_2 V_139 ;
int V_84 ;
if ( ! V_16 -> V_18 -> V_135 ) {
F_22 ( L_15
L_16 , V_16 -> V_18 -> V_136 ) ;
V_12 -> V_90 = V_137 ;
return - V_122 ;
}
if ( V_12 -> V_83 [ 0 ] == V_140 )
V_139 = F_37 ( & V_12 -> V_83 [ 7 ] ) ;
else if ( V_12 -> V_83 [ 0 ] == V_141 )
V_139 = F_40 ( & V_12 -> V_83 [ 10 ] ) ;
else
V_139 = F_40 ( & V_12 -> V_83 [ 28 ] ) ;
if ( V_139 != 0 )
V_132 = V_139 ;
else
V_132 = ( V_16 -> V_18 -> V_100 ( V_16 ) - V_130 ) + 1 ;
F_38 ( L_17 ,
( unsigned long long ) V_130 , ( unsigned long long ) V_132 ) ;
V_84 = V_16 -> V_18 -> V_135 ( V_16 , V_130 , V_132 ) ;
if ( V_84 < 0 ) {
F_38 ( L_18 ) ;
return V_84 ;
}
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
int F_42 ( struct V_11 * V_12 )
{
if ( ! V_12 -> V_17 -> V_18 -> V_142 ) {
F_22 ( L_19
L_16 , V_12 -> V_17 -> V_18 -> V_136 ) ;
V_12 -> V_90 = V_137 ;
return - V_122 ;
}
V_12 -> V_17 -> V_18 -> V_142 ( V_12 ) ;
return 0 ;
}
int F_43 ( struct V_11 * V_12 )
{
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
