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
T_1
F_4 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_13 * V_14 = V_12 -> V_13 ;
struct V_15 * V_16 = V_12 -> V_17 ;
if ( V_16 -> V_18 -> V_19 ( V_16 ) == V_20 )
V_3 [ 1 ] = 0x80 ;
V_3 [ 2 ] = 0x05 ;
V_3 [ 3 ] = 2 ;
F_1 ( V_14 -> V_21 , V_3 ) ;
V_3 [ 7 ] = 0x2 ;
snprintf ( & V_3 [ 8 ] , 8 , L_1 ) ;
snprintf ( & V_3 [ 16 ] , 16 , L_2 , V_16 -> V_22 . V_23 ) ;
snprintf ( & V_3 [ 32 ] , 4 , L_2 , V_16 -> V_22 . V_24 ) ;
V_3 [ 4 ] = 31 ;
return 0 ;
}
static T_1
F_5 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_2 V_25 = 0 ;
if ( V_16 -> V_26 & V_27 ) {
T_3 V_28 ;
V_28 = strlen ( V_16 -> V_22 . V_29 ) ;
V_28 ++ ;
V_25 += sprintf ( & V_3 [ 4 ] , L_2 , V_16 -> V_22 . V_29 ) ;
V_25 ++ ;
V_3 [ 3 ] = V_25 ;
}
return 0 ;
}
static void F_6 ( struct V_15 * V_16 ,
unsigned char * V_3 )
{
unsigned char * V_30 = & V_16 -> V_22 . V_29 [ 0 ] ;
int V_31 ;
bool V_32 = true ;
for ( V_31 = 0 ; * V_30 && V_31 < 13 ; V_30 ++ ) {
int V_33 = F_7 ( * V_30 ) ;
if ( V_33 < 0 )
continue;
if ( V_32 ) {
V_32 = false ;
V_3 [ V_31 ++ ] |= V_33 ;
} else {
V_32 = true ;
V_3 [ V_31 ] = V_33 << 4 ;
}
}
}
T_1
F_8 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_13 * V_14 = V_12 -> V_13 ;
struct V_1 * V_2 = NULL ;
struct V_34 * V_35 = NULL ;
struct V_36 * V_37 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned char * V_38 = & V_16 -> V_22 . V_23 [ 0 ] ;
T_3 V_39 ;
T_3 V_28 , V_40 = 0 ;
T_2 V_25 = 0 , V_41 ;
V_40 = 4 ;
if ( ! ( V_16 -> V_26 & V_27 ) )
goto V_42;
V_3 [ V_40 ++ ] = 0x1 ;
V_3 [ V_40 ] = 0x00 ;
V_3 [ V_40 ++ ] |= 0x3 ;
V_40 ++ ;
V_3 [ V_40 ++ ] = 0x10 ;
V_3 [ V_40 ++ ] = ( 0x6 << 4 ) ;
V_3 [ V_40 ++ ] = 0x01 ;
V_3 [ V_40 ++ ] = 0x40 ;
V_3 [ V_40 ] = ( 0x5 << 4 ) ;
F_6 ( V_16 , & V_3 [ V_40 ] ) ;
V_25 = 20 ;
V_40 = ( V_25 + 4 ) ;
V_42:
V_41 = 8 ;
V_39 = 4 ;
V_39 += 8 ;
V_39 += strlen ( V_38 ) ;
V_39 ++ ;
if ( V_16 -> V_26 & V_27 ) {
V_28 = strlen ( & V_16 -> V_22 . V_29 [ 0 ] ) ;
V_28 ++ ;
V_41 += sprintf ( & V_3 [ V_40 + 12 ] , L_3 , V_38 ,
& V_16 -> V_22 . V_29 [ 0 ] ) ;
}
V_3 [ V_40 ] = 0x2 ;
V_3 [ V_40 + 1 ] = 0x1 ;
V_3 [ V_40 + 2 ] = 0x0 ;
memcpy ( & V_3 [ V_40 + 4 ] , L_1 , 8 ) ;
V_41 ++ ;
V_3 [ V_40 + 3 ] = V_41 ;
V_25 += ( V_41 + 4 ) ;
V_40 += ( V_41 + 4 ) ;
V_2 = V_14 -> V_21 ;
if ( V_2 ) {
struct V_43 * V_44 ;
T_3 V_45 , V_46 ;
T_2 V_47 = 0 ;
T_2 V_48 = 0 ;
T_2 V_49 ;
V_35 = V_2 -> V_50 ;
V_3 [ V_40 ] =
( V_35 -> V_51 -> V_52 ( V_35 ) << 4 ) ;
V_3 [ V_40 ++ ] |= 0x1 ;
V_3 [ V_40 ] = 0x80 ;
V_3 [ V_40 ] |= 0x10 ;
V_3 [ V_40 ++ ] |= 0x4 ;
V_40 ++ ;
V_3 [ V_40 ++ ] = 4 ;
V_40 += 2 ;
V_3 [ V_40 ++ ] = ( ( V_2 -> V_53 >> 8 ) & 0xff ) ;
V_3 [ V_40 ++ ] = ( V_2 -> V_53 & 0xff ) ;
V_25 += 8 ;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
goto V_54;
F_2 ( & V_7 -> V_9 ) ;
V_5 = V_7 -> V_5 ;
if ( ! V_5 ) {
F_3 ( & V_7 -> V_9 ) ;
goto V_54;
}
V_48 = V_5 -> V_48 ;
F_3 ( & V_7 -> V_9 ) ;
V_3 [ V_40 ] =
( V_35 -> V_51 -> V_52 ( V_35 ) << 4 ) ;
V_3 [ V_40 ++ ] |= 0x1 ;
V_3 [ V_40 ] = 0x80 ;
V_3 [ V_40 ] |= 0x10 ;
V_3 [ V_40 ++ ] |= 0x5 ;
V_40 ++ ;
V_3 [ V_40 ++ ] = 4 ;
V_40 += 2 ;
V_3 [ V_40 ++ ] = ( ( V_48 >> 8 ) & 0xff ) ;
V_3 [ V_40 ++ ] = ( V_48 & 0xff ) ;
V_25 += 8 ;
V_54:
V_37 = V_16 -> V_55 ;
if ( ! V_37 )
goto V_56;
F_2 ( & V_37 -> V_57 ) ;
V_44 = V_37 -> V_44 ;
if ( ! V_44 ) {
F_3 ( & V_37 -> V_57 ) ;
goto V_56;
}
V_47 = V_44 -> V_47 ;
F_3 ( & V_37 -> V_57 ) ;
V_3 [ V_40 ++ ] |= 0x1 ;
V_3 [ V_40 ++ ] |= 0x6 ;
V_40 ++ ;
V_3 [ V_40 ++ ] = 4 ;
V_40 += 2 ;
V_3 [ V_40 ++ ] = ( ( V_47 >> 8 ) & 0xff ) ;
V_3 [ V_40 ++ ] = ( V_47 & 0xff ) ;
V_25 += 8 ;
V_56:
V_46 = strlen ( V_35 -> V_51 -> V_58 ( V_35 ) ) ;
V_46 += 10 ;
V_45 = ( ( - V_46 ) & 3 ) ;
if ( V_45 != 0 )
V_46 += V_45 ;
V_46 += 4 ;
V_3 [ V_40 ] =
( V_35 -> V_51 -> V_52 ( V_35 ) << 4 ) ;
V_3 [ V_40 ++ ] |= 0x3 ;
V_3 [ V_40 ] = 0x80 ;
V_3 [ V_40 ] |= 0x10 ;
V_3 [ V_40 ++ ] |= 0x8 ;
V_40 += 2 ;
V_49 = V_35 -> V_51 -> V_59 ( V_35 ) ;
V_46 = sprintf ( & V_3 [ V_40 ] , L_4 ,
V_35 -> V_51 -> V_58 ( V_35 ) , V_49 ) ;
V_46 += 1 ;
if ( V_45 )
V_46 += V_45 ;
V_3 [ V_40 - 1 ] = V_46 ;
V_40 += V_46 ;
V_25 += ( V_46 + 4 ) ;
}
V_3 [ 2 ] = ( ( V_25 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_25 & 0xff ) ;
return 0 ;
}
static bool
F_9 ( struct V_15 * V_16 )
{
bool V_60 = false ;
if ( V_16 -> V_18 -> V_61 )
V_60 = V_16 -> V_18 -> V_61 ( V_16 ) ;
else if ( V_16 -> V_62 . V_63 > 0 )
V_60 = true ;
return V_60 ;
}
static T_1
F_10 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = 0x07 ;
if ( F_9 ( V_16 ) )
V_3 [ 6 ] = 0x01 ;
return 0 ;
}
static T_1
F_11 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_3 V_64 ;
int V_65 = 0 ;
if ( V_16 -> V_62 . V_66 || V_16 -> V_62 . V_67 )
V_65 = 1 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = V_65 ? 0x3c : 0x10 ;
V_3 [ 4 ] = 0x01 ;
F_12 ( 1 , & V_3 [ 6 ] ) ;
V_64 = F_13 ( V_16 -> V_62 . V_68 ,
V_16 -> V_62 . V_69 ) ;
F_14 ( V_64 , & V_3 [ 8 ] ) ;
F_14 ( V_16 -> V_62 . V_70 , & V_3 [ 12 ] ) ;
if ( ! V_65 )
goto V_71;
F_14 ( V_16 -> V_62 . V_72 , & V_3 [ 20 ] ) ;
F_14 ( V_16 -> V_62 . V_73 ,
& V_3 [ 24 ] ) ;
F_14 ( V_16 -> V_62 . V_74 , & V_3 [ 28 ] ) ;
F_14 ( V_16 -> V_62 . V_75 ,
& V_3 [ 32 ] ) ;
if ( V_16 -> V_62 . V_75 != 0 )
V_3 [ 32 ] |= 0x80 ;
V_71:
F_15 ( V_16 -> V_62 . V_76 , & V_3 [ 36 ] ) ;
return 0 ;
}
static T_1
F_16 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = V_16 -> V_62 . V_77 ? 1 : 0 ;
return 0 ;
}
static T_1
F_17 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
F_12 ( 0x0004 , & V_3 [ 2 ] ) ;
V_3 [ 4 ] = 0x00 ;
if ( V_16 -> V_62 . V_66 != 0 )
V_3 [ 5 ] = 0x80 ;
if ( V_16 -> V_62 . V_67 != 0 )
V_3 [ 5 ] |= 0x40 ;
return 0 ;
}
static T_1
F_18 ( struct V_11 * V_12 , unsigned char * V_3 )
{
int V_30 ;
if ( V_12 -> V_17 -> V_26 & V_27 ) {
V_3 [ 3 ] = F_19 ( V_78 ) ;
for ( V_30 = 0 ; V_30 < F_19 ( V_78 ) ; ++ V_30 )
V_3 [ V_30 + 4 ] = V_78 [ V_30 ] . V_79 ;
}
return 0 ;
}
static T_1
F_20 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_34 * V_35 = V_12 -> V_13 -> V_21 -> V_50 ;
unsigned char * V_80 ;
unsigned char * V_81 = V_12 -> V_82 ;
unsigned char V_3 [ V_83 ] ;
T_1 V_84 ;
int V_30 ;
memset ( V_3 , 0 , V_83 ) ;
if ( V_16 == V_35 -> V_85 . V_86 )
V_3 [ 0 ] = 0x3f ;
else
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
if ( ! ( V_81 [ 1 ] & 0x1 ) ) {
if ( V_81 [ 2 ] ) {
F_21 ( L_5 ,
V_81 [ 2 ] ) ;
V_84 = V_87 ;
goto V_88;
}
V_84 = F_4 ( V_12 , V_3 ) ;
goto V_88;
}
for ( V_30 = 0 ; V_30 < F_19 ( V_78 ) ; ++ V_30 ) {
if ( V_81 [ 2 ] == V_78 [ V_30 ] . V_79 ) {
V_3 [ 1 ] = V_81 [ 2 ] ;
V_84 = V_78 [ V_30 ] . F_22 ( V_12 , V_3 ) ;
goto V_88;
}
}
F_21 ( L_6 , V_81 [ 2 ] ) ;
V_84 = V_87 ;
V_88:
V_80 = F_23 ( V_12 ) ;
if ( V_80 ) {
memcpy ( V_80 , V_3 , F_24 ( T_3 , sizeof( V_3 ) , V_12 -> V_89 ) ) ;
F_25 ( V_12 ) ;
}
if ( ! V_84 )
F_26 ( V_12 , V_90 ) ;
return V_84 ;
}
static int F_27 ( struct V_15 * V_16 , T_4 V_91 , T_4 * V_30 )
{
V_30 [ 0 ] = 0x01 ;
V_30 [ 1 ] = 0x0a ;
if ( V_91 == 1 )
goto V_88;
V_88:
return 12 ;
}
static int F_28 ( struct V_15 * V_16 , T_4 V_91 , T_4 * V_30 )
{
V_30 [ 0 ] = 0x0a ;
V_30 [ 1 ] = 0x0a ;
if ( V_91 == 1 )
goto V_88;
V_30 [ 2 ] = 2 ;
V_30 [ 3 ] = ( V_16 -> V_62 . V_92 == 1 ) ? 0x00 : 0x10 ;
V_30 [ 4 ] = ( V_16 -> V_62 . V_93 == 2 ) ? 0x30 :
( V_16 -> V_62 . V_93 == 1 ) ? 0x20 : 0x00 ;
V_30 [ 5 ] = ( V_16 -> V_62 . V_94 ) ? 0x40 : 0x00 ;
V_30 [ 8 ] = 0xff ;
V_30 [ 9 ] = 0xff ;
V_30 [ 11 ] = 30 ;
V_88:
return 12 ;
}
static int F_29 ( struct V_15 * V_16 , T_4 V_91 , T_4 * V_30 )
{
V_30 [ 0 ] = 0x08 ;
V_30 [ 1 ] = 0x12 ;
if ( V_91 == 1 )
goto V_88;
if ( F_9 ( V_16 ) )
V_30 [ 2 ] = 0x04 ;
V_30 [ 12 ] = 0x20 ;
V_88:
return 20 ;
}
static int F_30 ( struct V_15 * V_16 , T_4 V_91 , unsigned char * V_30 )
{
V_30 [ 0 ] = 0x1c ;
V_30 [ 1 ] = 0x0a ;
if ( V_91 == 1 )
goto V_88;
V_88:
return 12 ;
}
static void F_31 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_95 :
case V_20 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void F_32 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_95 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
static int F_33 ( unsigned char * V_3 , T_5 V_96 , T_3 V_97 )
{
* V_3 ++ = 8 ;
F_14 ( F_13 ( V_96 , 0xffffffffull ) , V_3 ) ;
V_3 += 4 ;
F_14 ( V_97 , V_3 ) ;
return 9 ;
}
static int F_34 ( unsigned char * V_3 , T_5 V_96 , T_3 V_97 )
{
if ( V_96 <= 0xffffffff )
return F_33 ( V_3 + 3 , V_96 , V_97 ) + 3 ;
* V_3 ++ = 1 ;
V_3 += 2 ;
* V_3 ++ = 16 ;
F_15 ( V_96 , V_3 ) ;
V_3 += 12 ;
F_14 ( V_97 , V_3 ) ;
return 17 ;
}
static T_1 F_35 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_81 = V_12 -> V_82 ;
unsigned char V_3 [ V_98 ] , * V_80 ;
int type = V_16 -> V_18 -> V_19 ( V_16 ) ;
int V_99 = ( V_12 -> V_82 [ 0 ] == V_100 ) ;
bool V_101 = ! ! ( V_81 [ 1 ] & 0x08 ) ;
bool V_102 = V_99 ? ! ! ( V_81 [ 1 ] & 0x10 ) : false ;
T_4 V_91 = V_81 [ 2 ] >> 6 ;
T_4 V_79 = V_81 [ 2 ] & 0x3f ;
T_4 V_103 = V_81 [ 3 ] ;
int V_104 = 0 ;
int V_84 ;
int V_105 ;
memset ( V_3 , 0 , V_98 ) ;
V_104 = V_99 ? 3 : 2 ;
if ( ( V_12 -> V_13 -> V_106 & V_107 ) ||
( V_12 -> V_108 &&
( V_12 -> V_108 -> V_109 & V_107 ) ) )
F_31 ( & V_3 [ V_104 ] , type ) ;
if ( ( F_9 ( V_16 ) ) &&
( V_16 -> V_62 . V_110 > 0 ) )
F_32 ( & V_3 [ V_104 ] , type ) ;
++ V_104 ;
if ( ! V_101 && type == V_95 ) {
T_5 V_96 = V_16 -> V_18 -> V_111 ( V_16 ) ;
T_3 V_97 = V_16 -> V_62 . V_97 ;
if ( V_99 ) {
if ( V_102 ) {
V_104 += F_34 ( & V_3 [ V_104 ] ,
V_96 , V_97 ) ;
} else {
V_104 += 3 ;
V_104 += F_33 ( & V_3 [ V_104 ] ,
V_96 , V_97 ) ;
}
} else {
V_104 += F_33 ( & V_3 [ V_104 ] , V_96 ,
V_97 ) ;
}
} else {
if ( V_99 )
V_104 += 4 ;
else
V_104 += 1 ;
}
if ( V_79 == 0x3f ) {
if ( V_103 != 0x00 && V_103 != 0xff ) {
F_36 ( L_7 , V_103 ) ;
return V_87 ;
}
for ( V_105 = 0 ; V_105 < F_19 ( V_112 ) ; ++ V_105 ) {
if ( ( V_112 [ V_105 ] . V_103 & ~ V_103 ) == 0 ) {
V_84 = V_112 [ V_105 ] . F_22 ( V_16 , V_91 , & V_3 [ V_104 ] ) ;
if ( ! V_99 && V_104 + V_84 >= 255 )
break;
V_104 += V_84 ;
}
}
goto V_113;
}
for ( V_105 = 0 ; V_105 < F_19 ( V_112 ) ; ++ V_105 )
if ( V_112 [ V_105 ] . V_79 == V_79 &&
V_112 [ V_105 ] . V_103 == V_103 ) {
V_104 += V_112 [ V_105 ] . F_22 ( V_16 , V_91 , & V_3 [ V_104 ] ) ;
goto V_113;
}
if ( V_79 != 0x03 )
F_21 ( L_8 ,
V_79 , V_103 ) ;
return V_114 ;
V_113:
if ( V_99 )
F_12 ( V_104 - 2 , V_3 ) ;
else
V_3 [ 0 ] = V_104 - 1 ;
V_80 = F_23 ( V_12 ) ;
if ( V_80 ) {
memcpy ( V_80 , V_3 , F_24 ( T_3 , V_98 , V_12 -> V_89 ) ) ;
F_25 ( V_12 ) ;
}
F_26 ( V_12 , V_90 ) ;
return 0 ;
}
static T_1 F_37 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_81 = V_12 -> V_82 ;
bool V_99 = V_81 [ 0 ] == V_115 ;
int V_40 = V_99 ? 8 : 4 ;
bool V_116 = ! ! ( V_81 [ 1 ] & 0x10 ) ;
T_4 V_79 , V_103 ;
unsigned char * V_3 ;
unsigned char V_117 [ V_98 ] ;
int V_104 ;
int V_84 = 0 ;
int V_105 ;
if ( ! V_12 -> V_89 ) {
F_26 ( V_12 , V_90 ) ;
return 0 ;
}
if ( V_12 -> V_89 < V_40 + 2 )
return V_118 ;
V_3 = F_23 ( V_12 ) ;
if ( ! V_3 )
return V_119 ;
if ( ! V_116 ) {
V_84 = V_87 ;
goto V_88;
}
V_79 = V_3 [ V_40 ] & 0x3f ;
V_103 = V_3 [ V_40 ] & 0x40 ? V_3 [ V_40 + 1 ] : 0 ;
for ( V_105 = 0 ; V_105 < F_19 ( V_112 ) ; ++ V_105 )
if ( V_112 [ V_105 ] . V_79 == V_79 &&
V_112 [ V_105 ] . V_103 == V_103 ) {
memset ( V_117 , 0 , V_98 ) ;
V_104 = V_112 [ V_105 ] . F_22 ( V_16 , 0 , V_117 ) ;
goto V_120;
}
V_84 = V_114 ;
goto V_88;
V_120:
if ( V_12 -> V_89 < V_40 + V_104 ) {
V_84 = V_118 ;
goto V_88;
}
if ( memcmp ( V_3 + V_40 , V_117 , V_104 ) )
V_84 = V_121 ;
V_88:
F_25 ( V_12 ) ;
if ( ! V_84 )
F_26 ( V_12 , V_90 ) ;
return V_84 ;
}
static T_1 F_38 ( struct V_11 * V_12 )
{
unsigned char * V_81 = V_12 -> V_82 ;
unsigned char * V_80 ;
T_4 V_122 = 0 , V_123 = 0 ;
unsigned char V_3 [ V_124 ] ;
memset ( V_3 , 0 , V_124 ) ;
if ( V_81 [ 1 ] & 0x01 ) {
F_21 ( L_9
L_10 ) ;
return V_87 ;
}
V_80 = F_23 ( V_12 ) ;
if ( ! V_80 )
return V_119 ;
if ( ! F_39 ( V_12 , & V_122 , & V_123 ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_125 ] = V_126 ;
V_3 [ V_127 ] = V_122 ;
V_3 [ V_128 ] = V_123 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_125 ] = V_129 ;
V_3 [ V_127 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
memcpy ( V_80 , V_3 , F_24 ( T_3 , sizeof( V_3 ) , V_12 -> V_89 ) ) ;
F_25 ( V_12 ) ;
F_26 ( V_12 , V_90 ) ;
return 0 ;
}
T_1 F_40 ( struct V_11 * V_12 )
{
struct V_130 * V_131 ;
struct V_132 * V_133 = V_12 -> V_134 ;
unsigned char * V_3 ;
T_3 V_135 = 0 , V_136 = 8 , V_105 ;
if ( V_12 -> V_89 < 16 ) {
F_36 ( L_11 ,
V_12 -> V_89 ) ;
return V_87 ;
}
V_3 = F_23 ( V_12 ) ;
if ( ! V_3 )
return V_119 ;
if ( ! V_133 ) {
F_41 ( 0 , (struct V_137 * ) & V_3 [ V_136 ] ) ;
V_135 = 1 ;
goto V_138;
}
F_42 ( & V_133 -> V_139 -> V_140 ) ;
for ( V_105 = 0 ; V_105 < V_141 ; V_105 ++ ) {
V_131 = V_133 -> V_139 -> V_142 [ V_105 ] ;
if ( ! ( V_131 -> V_109 & V_143 ) )
continue;
V_135 ++ ;
if ( ( V_136 + 8 ) > V_12 -> V_89 )
continue;
F_41 ( V_131 -> V_144 , (struct V_137 * ) & V_3 [ V_136 ] ) ;
V_136 += 8 ;
}
F_43 ( & V_133 -> V_139 -> V_140 ) ;
V_138:
V_135 *= 8 ;
V_3 [ 0 ] = ( ( V_135 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_135 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_135 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_135 & 0xff ) ;
F_25 ( V_12 ) ;
F_26 ( V_12 , V_90 ) ;
return 0 ;
}
static T_1
F_44 ( struct V_11 * V_12 )
{
F_26 ( V_12 , V_90 ) ;
return 0 ;
}
T_1
F_45 ( struct V_11 * V_12 , unsigned int * V_145 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_81 = V_12 -> V_82 ;
switch ( V_81 [ 0 ] ) {
case V_146 :
* V_145 = V_81 [ 4 ] ;
V_12 -> V_147 = F_37 ;
break;
case V_115 :
* V_145 = ( V_81 [ 7 ] << 8 ) + V_81 [ 8 ] ;
V_12 -> V_147 = F_37 ;
break;
case V_148 :
* V_145 = V_81 [ 4 ] ;
V_12 -> V_147 = F_35 ;
break;
case V_100 :
* V_145 = ( V_81 [ 7 ] << 8 ) + V_81 [ 8 ] ;
V_12 -> V_147 = F_35 ;
break;
case V_149 :
case V_150 :
* V_145 = ( V_81 [ 7 ] << 8 ) + V_81 [ 8 ] ;
break;
case V_151 :
* V_145 = ( V_81 [ 7 ] << 8 ) + V_81 [ 8 ] ;
V_12 -> V_147 = V_152 ;
break;
case V_153 :
* V_145 = ( V_81 [ 7 ] << 8 ) + V_81 [ 8 ] ;
V_12 -> V_147 = V_154 ;
break;
case V_155 :
case V_156 :
if ( V_81 [ 0 ] == V_156 )
* V_145 = ( V_81 [ 7 ] << 8 ) | V_81 [ 8 ] ;
else
* V_145 = V_12 -> V_89 ;
V_12 -> V_147 = V_157 ;
break;
case V_158 :
case V_159 :
if ( V_81 [ 0 ] == V_159 )
* V_145 = ( V_81 [ 7 ] << 8 ) | V_81 [ 8 ] ;
else
* V_145 = V_12 -> V_89 ;
V_12 -> V_147 = V_160 ;
break;
case V_161 :
* V_145 = V_81 [ 4 ] ;
V_12 -> V_147 = F_38 ;
break;
case V_162 :
* V_145 = ( V_81 [ 3 ] << 8 ) + V_81 [ 4 ] ;
V_12 -> V_163 = V_164 ;
V_12 -> V_147 = F_20 ;
break;
case V_165 :
case V_166 :
* V_145 = ( V_81 [ 6 ] << 24 ) | ( V_81 [ 7 ] << 16 ) | ( V_81 [ 8 ] << 8 ) | V_81 [ 9 ] ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
* V_145 = ( V_81 [ 10 ] << 24 ) | ( V_81 [ 11 ] << 16 ) |
( V_81 [ 12 ] << 8 ) | V_81 [ 13 ] ;
break;
case V_171 :
case V_172 :
* V_145 = ( V_81 [ 3 ] << 8 ) | V_81 [ 4 ] ;
break;
case V_173 :
* V_145 = ( V_81 [ 6 ] << 16 ) + ( V_81 [ 7 ] << 8 ) + V_81 [ 8 ] ;
break;
case V_174 :
V_12 -> V_147 = F_40 ;
* V_145 = ( V_81 [ 6 ] << 24 ) | ( V_81 [ 7 ] << 16 ) | ( V_81 [ 8 ] << 8 ) | V_81 [ 9 ] ;
V_12 -> V_163 = V_164 ;
break;
case V_175 :
V_12 -> V_147 = F_44 ;
* V_145 = 0 ;
break;
case V_176 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_177 ) {
if ( ( V_81 [ 1 ] & 0x1f ) == V_178 ) {
V_12 -> V_147 =
V_179 ;
}
* V_145 = F_46 ( & V_81 [ 6 ] ) ;
} else {
* V_145 = F_47 ( & V_81 [ 8 ] ) ;
}
break;
case V_180 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_177 ) {
if ( V_81 [ 1 ] == V_181 ) {
V_12 -> V_147 =
V_182 ;
}
* V_145 = F_46 ( & V_81 [ 6 ] ) ;
} else {
* V_145 = F_47 ( & V_81 [ 8 ] ) ;
}
break;
default:
F_36 ( L_12
L_13 ,
V_12 -> V_183 -> V_184 () , V_81 [ 0 ] ) ;
return V_185 ;
}
return 0 ;
}
