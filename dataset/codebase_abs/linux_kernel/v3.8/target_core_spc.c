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
static T_1
F_4 ( struct V_11 * V_12 , char * V_3 )
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
static T_1
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
static T_1
F_9 ( struct V_11 * V_12 , unsigned char * V_3 )
{
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = 0x07 ;
if ( V_12 -> V_17 -> V_60 . V_61 > 0 )
V_3 [ 6 ] = 0x01 ;
return 0 ;
}
static T_1
F_10 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_3 V_62 ;
int V_63 = 0 ;
if ( V_16 -> V_60 . V_64 || V_16 -> V_60 . V_65 )
V_63 = 1 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = V_63 ? 0x3c : 0x10 ;
V_3 [ 4 ] = 0x01 ;
F_11 ( 1 , & V_3 [ 6 ] ) ;
V_62 = F_12 ( V_16 -> V_60 . V_66 ,
V_16 -> V_60 . V_67 ) ;
F_13 ( V_62 , & V_3 [ 8 ] ) ;
F_13 ( V_16 -> V_60 . V_68 , & V_3 [ 12 ] ) ;
if ( ! V_63 )
goto V_69;
F_13 ( V_16 -> V_60 . V_70 , & V_3 [ 20 ] ) ;
F_13 ( V_16 -> V_60 . V_71 ,
& V_3 [ 24 ] ) ;
F_13 ( V_16 -> V_60 . V_72 , & V_3 [ 28 ] ) ;
F_13 ( V_16 -> V_60 . V_73 ,
& V_3 [ 32 ] ) ;
if ( V_16 -> V_60 . V_73 != 0 )
V_3 [ 32 ] |= 0x80 ;
V_69:
F_14 ( V_16 -> V_60 . V_74 , & V_3 [ 36 ] ) ;
return 0 ;
}
static T_1
F_15 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = V_16 -> V_60 . V_75 ? 1 : 0 ;
return 0 ;
}
static T_1
F_16 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
F_11 ( 0x0004 , & V_3 [ 2 ] ) ;
V_3 [ 4 ] = 0x00 ;
if ( V_16 -> V_60 . V_64 != 0 )
V_3 [ 5 ] = 0x80 ;
if ( V_16 -> V_60 . V_65 != 0 )
V_3 [ 5 ] |= 0x40 ;
return 0 ;
}
static T_1
F_17 ( struct V_11 * V_12 , unsigned char * V_3 )
{
int V_30 ;
if ( V_12 -> V_17 -> V_26 & V_27 ) {
V_3 [ 3 ] = F_18 ( V_76 ) ;
for ( V_30 = 0 ; V_30 < F_18 ( V_76 ) ; ++ V_30 )
V_3 [ V_30 + 4 ] = V_76 [ V_30 ] . V_77 ;
}
return 0 ;
}
static T_1
F_19 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_34 * V_35 = V_12 -> V_13 -> V_21 -> V_50 ;
unsigned char * V_78 ;
unsigned char * V_79 = V_12 -> V_80 ;
unsigned char V_3 [ V_81 ] ;
T_1 V_82 ;
int V_30 ;
memset ( V_3 , 0 , V_81 ) ;
if ( V_16 == V_35 -> V_83 . V_84 )
V_3 [ 0 ] = 0x3f ;
else
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
if ( ! ( V_79 [ 1 ] & 0x1 ) ) {
if ( V_79 [ 2 ] ) {
F_20 ( L_5 ,
V_79 [ 2 ] ) ;
V_82 = V_85 ;
goto V_86;
}
V_82 = F_4 ( V_12 , V_3 ) ;
goto V_86;
}
for ( V_30 = 0 ; V_30 < F_18 ( V_76 ) ; ++ V_30 ) {
if ( V_79 [ 2 ] == V_76 [ V_30 ] . V_77 ) {
V_3 [ 1 ] = V_79 [ 2 ] ;
V_82 = V_76 [ V_30 ] . F_21 ( V_12 , V_3 ) ;
goto V_86;
}
}
F_20 ( L_6 , V_79 [ 2 ] ) ;
V_82 = V_85 ;
V_86:
V_78 = F_22 ( V_12 ) ;
if ( V_78 ) {
memcpy ( V_78 , V_3 , F_23 ( T_3 , sizeof( V_3 ) , V_12 -> V_87 ) ) ;
F_24 ( V_12 ) ;
}
if ( ! V_82 )
F_25 ( V_12 , V_88 ) ;
return V_82 ;
}
static int F_26 ( struct V_15 * V_16 , T_4 V_89 , T_4 * V_30 )
{
V_30 [ 0 ] = 0x01 ;
V_30 [ 1 ] = 0x0a ;
if ( V_89 == 1 )
goto V_86;
V_86:
return 12 ;
}
static int F_27 ( struct V_15 * V_16 , T_4 V_89 , T_4 * V_30 )
{
V_30 [ 0 ] = 0x0a ;
V_30 [ 1 ] = 0x0a ;
if ( V_89 == 1 )
goto V_86;
V_30 [ 2 ] = 2 ;
V_30 [ 3 ] = ( V_16 -> V_60 . V_90 == 1 ) ? 0x00 : 0x10 ;
V_30 [ 4 ] = ( V_16 -> V_60 . V_91 == 2 ) ? 0x30 :
( V_16 -> V_60 . V_91 == 1 ) ? 0x20 : 0x00 ;
V_30 [ 5 ] = ( V_16 -> V_60 . V_92 ) ? 0x40 : 0x00 ;
V_30 [ 8 ] = 0xff ;
V_30 [ 9 ] = 0xff ;
V_30 [ 11 ] = 30 ;
V_86:
return 12 ;
}
static int F_28 ( struct V_15 * V_16 , T_4 V_89 , T_4 * V_30 )
{
V_30 [ 0 ] = 0x08 ;
V_30 [ 1 ] = 0x12 ;
if ( V_89 == 1 )
goto V_86;
if ( V_16 -> V_60 . V_61 > 0 )
V_30 [ 2 ] = 0x04 ;
V_30 [ 12 ] = 0x20 ;
V_86:
return 20 ;
}
static int F_29 ( struct V_15 * V_16 , T_4 V_89 , unsigned char * V_30 )
{
V_30 [ 0 ] = 0x1c ;
V_30 [ 1 ] = 0x0a ;
if ( V_89 == 1 )
goto V_86;
V_86:
return 12 ;
}
static void F_30 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_93 :
case V_20 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void F_31 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_93 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
static int F_32 ( unsigned char * V_3 , T_5 V_94 , T_3 V_95 )
{
* V_3 ++ = 8 ;
F_13 ( F_12 ( V_94 , 0xffffffffull ) , V_3 ) ;
V_3 += 4 ;
F_13 ( V_95 , V_3 ) ;
return 9 ;
}
static int F_33 ( unsigned char * V_3 , T_5 V_94 , T_3 V_95 )
{
if ( V_94 <= 0xffffffff )
return F_32 ( V_3 + 3 , V_94 , V_95 ) + 3 ;
* V_3 ++ = 1 ;
V_3 += 2 ;
* V_3 ++ = 16 ;
F_14 ( V_94 , V_3 ) ;
V_3 += 12 ;
F_13 ( V_95 , V_3 ) ;
return 17 ;
}
static T_1 F_34 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_79 = V_12 -> V_80 ;
unsigned char V_3 [ V_96 ] , * V_78 ;
int type = V_16 -> V_18 -> V_19 ( V_16 ) ;
int V_97 = ( V_12 -> V_80 [ 0 ] == V_98 ) ;
bool V_99 = ! ! ( V_79 [ 1 ] & 0x08 ) ;
bool V_100 = V_97 ? ! ! ( V_79 [ 1 ] & 0x10 ) : false ;
T_4 V_89 = V_79 [ 2 ] >> 6 ;
T_4 V_77 = V_79 [ 2 ] & 0x3f ;
T_4 V_101 = V_79 [ 3 ] ;
int V_102 = 0 ;
int V_82 ;
int V_103 ;
memset ( V_3 , 0 , V_96 ) ;
V_102 = V_97 ? 3 : 2 ;
if ( ( V_12 -> V_13 -> V_104 & V_105 ) ||
( V_12 -> V_106 &&
( V_12 -> V_106 -> V_107 & V_105 ) ) )
F_30 ( & V_3 [ V_102 ] , type ) ;
if ( ( V_16 -> V_60 . V_61 > 0 ) &&
( V_16 -> V_60 . V_108 > 0 ) )
F_31 ( & V_3 [ V_102 ] , type ) ;
++ V_102 ;
if ( ! V_99 && type == V_93 ) {
T_5 V_94 = V_16 -> V_18 -> V_109 ( V_16 ) ;
T_3 V_95 = V_16 -> V_60 . V_95 ;
if ( V_97 ) {
if ( V_100 ) {
V_102 += F_33 ( & V_3 [ V_102 ] ,
V_94 , V_95 ) ;
} else {
V_102 += 3 ;
V_102 += F_32 ( & V_3 [ V_102 ] ,
V_94 , V_95 ) ;
}
} else {
V_102 += F_32 ( & V_3 [ V_102 ] , V_94 ,
V_95 ) ;
}
} else {
if ( V_97 )
V_102 += 4 ;
else
V_102 += 1 ;
}
if ( V_77 == 0x3f ) {
if ( V_101 != 0x00 && V_101 != 0xff ) {
F_35 ( L_7 , V_101 ) ;
return V_85 ;
}
for ( V_103 = 0 ; V_103 < F_18 ( V_110 ) ; ++ V_103 ) {
if ( ( V_110 [ V_103 ] . V_101 & ~ V_101 ) == 0 ) {
V_82 = V_110 [ V_103 ] . F_21 ( V_16 , V_89 , & V_3 [ V_102 ] ) ;
if ( ! V_97 && V_102 + V_82 >= 255 )
break;
V_102 += V_82 ;
}
}
goto V_111;
}
for ( V_103 = 0 ; V_103 < F_18 ( V_110 ) ; ++ V_103 )
if ( V_110 [ V_103 ] . V_77 == V_77 &&
V_110 [ V_103 ] . V_101 == V_101 ) {
V_102 += V_110 [ V_103 ] . F_21 ( V_16 , V_89 , & V_3 [ V_102 ] ) ;
goto V_111;
}
if ( V_77 != 0x03 )
F_20 ( L_8 ,
V_77 , V_101 ) ;
return V_112 ;
V_111:
if ( V_97 )
F_11 ( V_102 - 2 , V_3 ) ;
else
V_3 [ 0 ] = V_102 - 1 ;
V_78 = F_22 ( V_12 ) ;
if ( V_78 ) {
memcpy ( V_78 , V_3 , F_23 ( T_3 , V_96 , V_12 -> V_87 ) ) ;
F_24 ( V_12 ) ;
}
F_25 ( V_12 , V_88 ) ;
return 0 ;
}
static T_1 F_36 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_79 = V_12 -> V_80 ;
bool V_97 = V_79 [ 0 ] == V_113 ;
int V_40 = V_97 ? 8 : 4 ;
bool V_114 = ! ! ( V_79 [ 1 ] & 0x10 ) ;
T_4 V_77 , V_101 ;
unsigned char * V_3 ;
unsigned char V_115 [ V_96 ] ;
int V_102 ;
int V_82 = 0 ;
int V_103 ;
V_3 = F_22 ( V_12 ) ;
if ( ! V_3 )
return V_116 ;
if ( ! V_114 ) {
V_82 = V_85 ;
goto V_86;
}
V_77 = V_3 [ V_40 ] & 0x3f ;
V_101 = V_3 [ V_40 ] & 0x40 ? V_3 [ V_40 + 1 ] : 0 ;
for ( V_103 = 0 ; V_103 < F_18 ( V_110 ) ; ++ V_103 )
if ( V_110 [ V_103 ] . V_77 == V_77 &&
V_110 [ V_103 ] . V_101 == V_101 ) {
memset ( V_115 , 0 , V_96 ) ;
V_102 = V_110 [ V_103 ] . F_21 ( V_16 , 0 , V_115 ) ;
goto V_117;
}
V_82 = V_112 ;
goto V_86;
V_117:
if ( memcmp ( V_3 + V_40 , V_115 , V_102 ) )
V_82 = V_118 ;
V_86:
F_24 ( V_12 ) ;
if ( ! V_82 )
F_25 ( V_12 , V_88 ) ;
return V_82 ;
}
static T_1 F_37 ( struct V_11 * V_12 )
{
unsigned char * V_79 = V_12 -> V_80 ;
unsigned char * V_78 ;
T_4 V_119 = 0 , V_120 = 0 ;
unsigned char V_3 [ V_121 ] ;
memset ( V_3 , 0 , V_121 ) ;
if ( V_79 [ 1 ] & 0x01 ) {
F_20 ( L_9
L_10 ) ;
return V_85 ;
}
V_78 = F_22 ( V_12 ) ;
if ( ! V_78 )
return V_116 ;
if ( ! F_38 ( V_12 , & V_119 , & V_120 ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_122 ] = V_123 ;
V_3 [ V_124 ] = V_119 ;
V_3 [ V_125 ] = V_120 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_122 ] = V_126 ;
V_3 [ V_124 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
memcpy ( V_78 , V_3 , F_23 ( T_3 , sizeof( V_3 ) , V_12 -> V_87 ) ) ;
F_24 ( V_12 ) ;
F_25 ( V_12 , V_88 ) ;
return 0 ;
}
T_1 F_39 ( struct V_11 * V_12 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 = V_12 -> V_131 ;
unsigned char * V_3 ;
T_3 V_132 = 0 , V_133 = 8 , V_103 ;
if ( V_12 -> V_87 < 16 ) {
F_35 ( L_11 ,
V_12 -> V_87 ) ;
return V_85 ;
}
V_3 = F_22 ( V_12 ) ;
if ( ! V_3 )
return V_116 ;
if ( ! V_130 ) {
F_40 ( 0 , (struct V_134 * ) & V_3 [ V_133 ] ) ;
V_132 = 1 ;
goto V_135;
}
F_41 ( & V_130 -> V_136 -> V_137 ) ;
for ( V_103 = 0 ; V_103 < V_138 ; V_103 ++ ) {
V_128 = V_130 -> V_136 -> V_139 [ V_103 ] ;
if ( ! ( V_128 -> V_107 & V_140 ) )
continue;
V_132 ++ ;
if ( ( V_133 + 8 ) > V_12 -> V_87 )
continue;
F_40 ( V_128 -> V_141 , (struct V_134 * ) & V_3 [ V_133 ] ) ;
V_133 += 8 ;
}
F_42 ( & V_130 -> V_136 -> V_137 ) ;
V_135:
V_132 *= 8 ;
V_3 [ 0 ] = ( ( V_132 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_132 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_132 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_132 & 0xff ) ;
F_24 ( V_12 ) ;
F_25 ( V_12 , V_88 ) ;
return 0 ;
}
static T_1
F_43 ( struct V_11 * V_12 )
{
F_25 ( V_12 , V_88 ) ;
return 0 ;
}
T_1
F_44 ( struct V_11 * V_12 , unsigned int * V_142 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_79 = V_12 -> V_80 ;
switch ( V_79 [ 0 ] ) {
case V_143 :
* V_142 = V_79 [ 4 ] ;
V_12 -> V_144 = F_36 ;
break;
case V_113 :
* V_142 = ( V_79 [ 7 ] << 8 ) + V_79 [ 8 ] ;
V_12 -> V_144 = F_36 ;
break;
case V_145 :
* V_142 = V_79 [ 4 ] ;
V_12 -> V_144 = F_34 ;
break;
case V_98 :
* V_142 = ( V_79 [ 7 ] << 8 ) + V_79 [ 8 ] ;
V_12 -> V_144 = F_34 ;
break;
case V_146 :
case V_147 :
* V_142 = ( V_79 [ 7 ] << 8 ) + V_79 [ 8 ] ;
break;
case V_148 :
* V_142 = ( V_79 [ 7 ] << 8 ) + V_79 [ 8 ] ;
V_12 -> V_144 = V_149 ;
break;
case V_150 :
* V_142 = ( V_79 [ 7 ] << 8 ) + V_79 [ 8 ] ;
V_12 -> V_144 = V_151 ;
break;
case V_152 :
case V_153 :
if ( V_79 [ 0 ] == V_153 )
* V_142 = ( V_79 [ 7 ] << 8 ) | V_79 [ 8 ] ;
else
* V_142 = V_12 -> V_87 ;
V_12 -> V_144 = V_154 ;
break;
case V_155 :
case V_156 :
if ( V_79 [ 0 ] == V_156 )
* V_142 = ( V_79 [ 7 ] << 8 ) | V_79 [ 8 ] ;
else
* V_142 = V_12 -> V_87 ;
V_12 -> V_144 = V_157 ;
break;
case V_158 :
* V_142 = V_79 [ 4 ] ;
V_12 -> V_144 = F_37 ;
break;
case V_159 :
* V_142 = ( V_79 [ 3 ] << 8 ) + V_79 [ 4 ] ;
V_12 -> V_160 = V_161 ;
V_12 -> V_144 = F_19 ;
break;
case V_162 :
case V_163 :
* V_142 = ( V_79 [ 6 ] << 24 ) | ( V_79 [ 7 ] << 16 ) | ( V_79 [ 8 ] << 8 ) | V_79 [ 9 ] ;
break;
case V_164 :
case V_165 :
case V_166 :
case V_167 :
* V_142 = ( V_79 [ 10 ] << 24 ) | ( V_79 [ 11 ] << 16 ) |
( V_79 [ 12 ] << 8 ) | V_79 [ 13 ] ;
break;
case V_168 :
case V_169 :
* V_142 = ( V_79 [ 3 ] << 8 ) | V_79 [ 4 ] ;
break;
case V_170 :
* V_142 = ( V_79 [ 6 ] << 16 ) + ( V_79 [ 7 ] << 8 ) + V_79 [ 8 ] ;
break;
case V_171 :
V_12 -> V_144 = F_39 ;
* V_142 = ( V_79 [ 6 ] << 24 ) | ( V_79 [ 7 ] << 16 ) | ( V_79 [ 8 ] << 8 ) | V_79 [ 9 ] ;
V_12 -> V_160 = V_161 ;
break;
case V_172 :
V_12 -> V_144 = F_43 ;
* V_142 = 0 ;
break;
case V_173 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_174 ) {
if ( ( V_79 [ 1 ] & 0x1f ) == V_175 ) {
V_12 -> V_144 =
V_176 ;
}
* V_142 = F_45 ( & V_79 [ 6 ] ) ;
} else {
* V_142 = F_46 ( & V_79 [ 8 ] ) ;
}
break;
case V_177 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_174 ) {
if ( V_79 [ 1 ] == V_178 ) {
V_12 -> V_144 =
V_179 ;
}
* V_142 = F_45 ( & V_79 [ 6 ] ) ;
} else {
* V_142 = F_46 ( & V_79 [ 8 ] ) ;
}
break;
default:
F_35 ( L_12
L_13 ,
V_12 -> V_180 -> V_181 () , V_79 [ 0 ] ) ;
return V_182 ;
}
return 0 ;
}
