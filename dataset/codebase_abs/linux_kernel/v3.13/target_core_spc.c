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
if ( V_16 -> V_22 . V_23 )
V_3 [ 5 ] |= 0x8 ;
V_3 [ 7 ] = 0x2 ;
memcpy ( & V_3 [ 8 ] , L_1 , 8 ) ;
memset ( & V_3 [ 16 ] , 0x20 , 16 ) ;
memcpy ( & V_3 [ 16 ] , V_16 -> V_24 . V_25 ,
F_5 ( V_26 , strlen ( V_16 -> V_24 . V_25 ) , 16 ) ) ;
memcpy ( & V_3 [ 32 ] , V_16 -> V_24 . V_27 ,
F_5 ( V_26 , strlen ( V_16 -> V_24 . V_27 ) , 4 ) ) ;
V_3 [ 4 ] = 31 ;
return 0 ;
}
static T_1
F_6 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_2 V_28 = 0 ;
if ( V_16 -> V_29 & V_30 ) {
T_3 V_31 ;
V_31 = strlen ( V_16 -> V_24 . V_32 ) ;
V_31 ++ ;
V_28 += sprintf ( & V_3 [ 4 ] , L_2 , V_16 -> V_24 . V_32 ) ;
V_28 ++ ;
V_3 [ 3 ] = V_28 ;
}
return 0 ;
}
void F_7 ( struct V_15 * V_16 ,
unsigned char * V_3 )
{
unsigned char * V_33 = & V_16 -> V_24 . V_32 [ 0 ] ;
int V_34 ;
bool V_35 = true ;
for ( V_34 = 0 ; * V_33 && V_34 < 13 ; V_33 ++ ) {
int V_36 = F_8 ( * V_33 ) ;
if ( V_36 < 0 )
continue;
if ( V_35 ) {
V_35 = false ;
V_3 [ V_34 ++ ] |= V_36 ;
} else {
V_35 = true ;
V_3 [ V_34 ] = V_36 << 4 ;
}
}
}
T_1
F_9 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_13 * V_14 = V_12 -> V_13 ;
struct V_1 * V_2 = NULL ;
struct V_37 * V_38 = NULL ;
struct V_39 * V_40 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned char * V_41 = & V_16 -> V_24 . V_25 [ 0 ] ;
T_3 V_42 ;
T_3 V_31 , V_43 = 0 ;
T_2 V_28 = 0 , V_44 ;
V_43 = 4 ;
if ( ! ( V_16 -> V_29 & V_30 ) )
goto V_45;
V_3 [ V_43 ++ ] = 0x1 ;
V_3 [ V_43 ] = 0x00 ;
V_3 [ V_43 ++ ] |= 0x3 ;
V_43 ++ ;
V_3 [ V_43 ++ ] = 0x10 ;
V_3 [ V_43 ++ ] = ( 0x6 << 4 ) ;
V_3 [ V_43 ++ ] = 0x01 ;
V_3 [ V_43 ++ ] = 0x40 ;
V_3 [ V_43 ] = ( 0x5 << 4 ) ;
F_7 ( V_16 , & V_3 [ V_43 ] ) ;
V_28 = 20 ;
V_43 = ( V_28 + 4 ) ;
V_45:
V_44 = 8 ;
V_42 = 4 ;
V_42 += 8 ;
V_42 += strlen ( V_41 ) ;
V_42 ++ ;
if ( V_16 -> V_29 & V_30 ) {
V_31 = strlen ( & V_16 -> V_24 . V_32 [ 0 ] ) ;
V_31 ++ ;
V_44 += sprintf ( & V_3 [ V_43 + 12 ] , L_3 , V_41 ,
& V_16 -> V_24 . V_32 [ 0 ] ) ;
}
V_3 [ V_43 ] = 0x2 ;
V_3 [ V_43 + 1 ] = 0x1 ;
V_3 [ V_43 + 2 ] = 0x0 ;
memcpy ( & V_3 [ V_43 + 4 ] , L_4 , 8 ) ;
V_44 ++ ;
V_3 [ V_43 + 3 ] = V_44 ;
V_28 += ( V_44 + 4 ) ;
V_43 += ( V_44 + 4 ) ;
V_2 = V_14 -> V_21 ;
if ( V_2 ) {
struct V_46 * V_47 ;
T_3 V_48 , V_49 ;
T_2 V_50 = 0 ;
T_2 V_51 = 0 ;
T_2 V_52 ;
V_38 = V_2 -> V_53 ;
V_3 [ V_43 ] =
( V_38 -> V_54 -> V_55 ( V_38 ) << 4 ) ;
V_3 [ V_43 ++ ] |= 0x1 ;
V_3 [ V_43 ] = 0x80 ;
V_3 [ V_43 ] |= 0x10 ;
V_3 [ V_43 ++ ] |= 0x4 ;
V_43 ++ ;
V_3 [ V_43 ++ ] = 4 ;
V_43 += 2 ;
V_3 [ V_43 ++ ] = ( ( V_2 -> V_56 >> 8 ) & 0xff ) ;
V_3 [ V_43 ++ ] = ( V_2 -> V_56 & 0xff ) ;
V_28 += 8 ;
V_7 = V_2 -> V_8 ;
if ( ! V_7 )
goto V_57;
F_2 ( & V_7 -> V_9 ) ;
V_5 = V_7 -> V_5 ;
if ( ! V_5 ) {
F_3 ( & V_7 -> V_9 ) ;
goto V_57;
}
V_51 = V_5 -> V_51 ;
F_3 ( & V_7 -> V_9 ) ;
V_3 [ V_43 ] =
( V_38 -> V_54 -> V_55 ( V_38 ) << 4 ) ;
V_3 [ V_43 ++ ] |= 0x1 ;
V_3 [ V_43 ] = 0x80 ;
V_3 [ V_43 ] |= 0x10 ;
V_3 [ V_43 ++ ] |= 0x5 ;
V_43 ++ ;
V_3 [ V_43 ++ ] = 4 ;
V_43 += 2 ;
V_3 [ V_43 ++ ] = ( ( V_51 >> 8 ) & 0xff ) ;
V_3 [ V_43 ++ ] = ( V_51 & 0xff ) ;
V_28 += 8 ;
V_57:
V_40 = V_16 -> V_58 ;
if ( ! V_40 )
goto V_59;
F_2 ( & V_40 -> V_60 ) ;
V_47 = V_40 -> V_47 ;
if ( ! V_47 ) {
F_3 ( & V_40 -> V_60 ) ;
goto V_59;
}
V_50 = V_47 -> V_50 ;
F_3 ( & V_40 -> V_60 ) ;
V_3 [ V_43 ++ ] |= 0x1 ;
V_3 [ V_43 ++ ] |= 0x6 ;
V_43 ++ ;
V_3 [ V_43 ++ ] = 4 ;
V_43 += 2 ;
V_3 [ V_43 ++ ] = ( ( V_50 >> 8 ) & 0xff ) ;
V_3 [ V_43 ++ ] = ( V_50 & 0xff ) ;
V_28 += 8 ;
V_59:
V_49 = strlen ( V_38 -> V_54 -> V_61 ( V_38 ) ) ;
V_49 += 10 ;
V_48 = ( ( - V_49 ) & 3 ) ;
if ( V_48 != 0 )
V_49 += V_48 ;
V_49 += 4 ;
V_3 [ V_43 ] =
( V_38 -> V_54 -> V_55 ( V_38 ) << 4 ) ;
V_3 [ V_43 ++ ] |= 0x3 ;
V_3 [ V_43 ] = 0x80 ;
V_3 [ V_43 ] |= 0x10 ;
V_3 [ V_43 ++ ] |= 0x8 ;
V_43 += 2 ;
V_52 = V_38 -> V_54 -> V_62 ( V_38 ) ;
V_49 = sprintf ( & V_3 [ V_43 ] , L_5 ,
V_38 -> V_54 -> V_61 ( V_38 ) , V_52 ) ;
V_49 += 1 ;
if ( V_48 )
V_49 += V_48 ;
V_3 [ V_43 - 1 ] = V_49 ;
V_43 += V_49 ;
V_28 += ( V_49 + 4 ) ;
}
V_3 [ 2 ] = ( ( V_28 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_28 & 0xff ) ;
return 0 ;
}
static bool
F_10 ( struct V_15 * V_16 )
{
bool V_63 = false ;
if ( V_16 -> V_18 -> V_64 )
V_63 = V_16 -> V_18 -> V_64 ( V_16 ) ;
else if ( V_16 -> V_22 . V_65 > 0 )
V_63 = true ;
return V_63 ;
}
static T_1
F_11 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = 0x07 ;
if ( F_10 ( V_16 ) )
V_3 [ 6 ] = 0x01 ;
return 0 ;
}
static T_1
F_12 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
T_3 V_66 ;
int V_67 = 0 ;
int V_68 , V_69 ;
if ( V_16 -> V_22 . V_70 || V_16 -> V_22 . V_71 )
V_67 = 1 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = V_67 ? 0x3c : 0x10 ;
V_3 [ 4 ] = 0x01 ;
if ( V_16 -> V_22 . V_72 )
V_3 [ 5 ] = 0x01 ;
if ( V_16 -> V_18 -> V_73 && ( V_69 = V_16 -> V_18 -> V_73 ( V_16 ) ) )
F_13 ( V_69 / V_16 -> V_22 . V_74 , & V_3 [ 6 ] ) ;
else
F_13 ( 1 , & V_3 [ 6 ] ) ;
V_66 = V_69 ( V_16 -> V_22 . V_75 ,
V_16 -> V_22 . V_76 ) ;
F_14 ( V_66 , & V_3 [ 8 ] ) ;
if ( V_16 -> V_18 -> V_77 && ( V_68 = V_16 -> V_18 -> V_77 ( V_16 ) ) )
F_14 ( V_68 / V_16 -> V_22 . V_74 , & V_3 [ 12 ] ) ;
else
F_14 ( V_16 -> V_22 . V_78 , & V_3 [ 12 ] ) ;
if ( ! V_67 )
goto V_79;
F_14 ( V_16 -> V_22 . V_80 , & V_3 [ 20 ] ) ;
F_14 ( V_16 -> V_22 . V_81 ,
& V_3 [ 24 ] ) ;
F_14 ( V_16 -> V_22 . V_82 , & V_3 [ 28 ] ) ;
F_14 ( V_16 -> V_22 . V_83 ,
& V_3 [ 32 ] ) ;
if ( V_16 -> V_22 . V_83 != 0 )
V_3 [ 32 ] |= 0x80 ;
V_79:
F_15 ( V_16 -> V_22 . V_84 , & V_3 [ 36 ] ) ;
return 0 ;
}
static T_1
F_16 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = V_16 -> V_22 . V_85 ? 1 : 0 ;
return 0 ;
}
static T_1
F_17 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
F_13 ( 0x0004 , & V_3 [ 2 ] ) ;
V_3 [ 4 ] = 0x00 ;
if ( V_16 -> V_22 . V_70 != 0 )
V_3 [ 5 ] = 0x80 ;
if ( V_16 -> V_22 . V_71 != 0 )
V_3 [ 5 ] |= 0x40 ;
return 0 ;
}
static T_1
F_18 ( struct V_11 * V_12 , unsigned char * V_3 )
{
int V_33 ;
if ( V_12 -> V_17 -> V_29 & V_30 ) {
V_3 [ 3 ] = F_19 ( V_86 ) ;
for ( V_33 = 0 ; V_33 < F_19 ( V_86 ) ; ++ V_33 )
V_3 [ V_33 + 4 ] = V_86 [ V_33 ] . V_87 ;
}
return 0 ;
}
static T_1
F_20 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_37 * V_38 = V_12 -> V_13 -> V_21 -> V_53 ;
unsigned char * V_88 ;
unsigned char * V_89 = V_12 -> V_90 ;
unsigned char V_3 [ V_91 ] ;
T_1 V_92 ;
int V_33 ;
memset ( V_3 , 0 , V_91 ) ;
if ( V_16 == V_38 -> V_93 . V_94 )
V_3 [ 0 ] = 0x3f ;
else
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
if ( ! ( V_89 [ 1 ] & 0x1 ) ) {
if ( V_89 [ 2 ] ) {
F_21 ( L_6 ,
V_89 [ 2 ] ) ;
V_92 = V_95 ;
goto V_96;
}
V_92 = F_4 ( V_12 , V_3 ) ;
goto V_96;
}
for ( V_33 = 0 ; V_33 < F_19 ( V_86 ) ; ++ V_33 ) {
if ( V_89 [ 2 ] == V_86 [ V_33 ] . V_87 ) {
V_3 [ 1 ] = V_89 [ 2 ] ;
V_92 = V_86 [ V_33 ] . F_22 ( V_12 , V_3 ) ;
goto V_96;
}
}
F_21 ( L_7 , V_89 [ 2 ] ) ;
V_92 = V_95 ;
V_96:
V_88 = F_23 ( V_12 ) ;
if ( V_88 ) {
memcpy ( V_88 , V_3 , F_5 ( T_3 , sizeof( V_3 ) , V_12 -> V_97 ) ) ;
F_24 ( V_12 ) ;
}
if ( ! V_92 )
F_25 ( V_12 , V_98 ) ;
return V_92 ;
}
static int F_26 ( struct V_15 * V_16 , T_4 V_99 , T_4 * V_33 )
{
V_33 [ 0 ] = 0x01 ;
V_33 [ 1 ] = 0x0a ;
if ( V_99 == 1 )
goto V_96;
V_96:
return 12 ;
}
static int F_27 ( struct V_15 * V_16 , T_4 V_99 , T_4 * V_33 )
{
V_33 [ 0 ] = 0x0a ;
V_33 [ 1 ] = 0x0a ;
if ( V_99 == 1 )
goto V_96;
V_33 [ 2 ] = 2 ;
V_33 [ 3 ] = ( V_16 -> V_22 . V_100 == 1 ) ? 0x00 : 0x10 ;
V_33 [ 4 ] = ( V_16 -> V_22 . V_101 == 2 ) ? 0x30 :
( V_16 -> V_22 . V_101 == 1 ) ? 0x20 : 0x00 ;
V_33 [ 5 ] = ( V_16 -> V_22 . V_102 ) ? 0x40 : 0x00 ;
V_33 [ 8 ] = 0xff ;
V_33 [ 9 ] = 0xff ;
V_33 [ 11 ] = 30 ;
V_96:
return 12 ;
}
static int F_28 ( struct V_15 * V_16 , T_4 V_99 , T_4 * V_33 )
{
V_33 [ 0 ] = 0x08 ;
V_33 [ 1 ] = 0x12 ;
if ( V_99 == 1 )
goto V_96;
if ( F_10 ( V_16 ) )
V_33 [ 2 ] = 0x04 ;
V_33 [ 12 ] = 0x20 ;
V_96:
return 20 ;
}
static int F_29 ( struct V_15 * V_16 , T_4 V_99 , unsigned char * V_33 )
{
V_33 [ 0 ] = 0x1c ;
V_33 [ 1 ] = 0x0a ;
if ( V_99 == 1 )
goto V_96;
V_96:
return 12 ;
}
static void F_30 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_103 :
case V_20 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void F_31 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_103 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
static int F_32 ( unsigned char * V_3 , T_5 V_104 , T_3 V_74 )
{
* V_3 ++ = 8 ;
F_14 ( V_69 ( V_104 , 0xffffffffull ) , V_3 ) ;
V_3 += 4 ;
F_14 ( V_74 , V_3 ) ;
return 9 ;
}
static int F_33 ( unsigned char * V_3 , T_5 V_104 , T_3 V_74 )
{
if ( V_104 <= 0xffffffff )
return F_32 ( V_3 + 3 , V_104 , V_74 ) + 3 ;
* V_3 ++ = 1 ;
V_3 += 2 ;
* V_3 ++ = 16 ;
F_15 ( V_104 , V_3 ) ;
V_3 += 12 ;
F_14 ( V_74 , V_3 ) ;
return 17 ;
}
static T_1 F_34 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_89 = V_12 -> V_90 ;
unsigned char V_3 [ V_105 ] , * V_88 ;
int type = V_16 -> V_18 -> V_19 ( V_16 ) ;
int V_106 = ( V_12 -> V_90 [ 0 ] == V_107 ) ;
bool V_108 = ! ! ( V_89 [ 1 ] & 0x08 ) ;
bool V_109 = V_106 ? ! ! ( V_89 [ 1 ] & 0x10 ) : false ;
T_4 V_99 = V_89 [ 2 ] >> 6 ;
T_4 V_87 = V_89 [ 2 ] & 0x3f ;
T_4 V_110 = V_89 [ 3 ] ;
int V_111 = 0 ;
int V_92 ;
int V_112 ;
memset ( V_3 , 0 , V_105 ) ;
V_111 = V_106 ? 3 : 2 ;
if ( ( V_12 -> V_13 -> V_113 & V_114 ) ||
( V_12 -> V_115 &&
( V_12 -> V_115 -> V_116 & V_114 ) ) )
F_30 ( & V_3 [ V_111 ] , type ) ;
if ( ( F_10 ( V_16 ) ) &&
( V_16 -> V_22 . V_117 > 0 ) )
F_31 ( & V_3 [ V_111 ] , type ) ;
++ V_111 ;
if ( ! V_108 && type == V_103 ) {
T_5 V_104 = V_16 -> V_18 -> V_118 ( V_16 ) ;
T_3 V_74 = V_16 -> V_22 . V_74 ;
if ( V_106 ) {
if ( V_109 ) {
V_111 += F_33 ( & V_3 [ V_111 ] ,
V_104 , V_74 ) ;
} else {
V_111 += 3 ;
V_111 += F_32 ( & V_3 [ V_111 ] ,
V_104 , V_74 ) ;
}
} else {
V_111 += F_32 ( & V_3 [ V_111 ] , V_104 ,
V_74 ) ;
}
} else {
if ( V_106 )
V_111 += 4 ;
else
V_111 += 1 ;
}
if ( V_87 == 0x3f ) {
if ( V_110 != 0x00 && V_110 != 0xff ) {
F_35 ( L_8 , V_110 ) ;
return V_95 ;
}
for ( V_112 = 0 ; V_112 < F_19 ( V_119 ) ; ++ V_112 ) {
if ( ( V_119 [ V_112 ] . V_110 & ~ V_110 ) == 0 ) {
V_92 = V_119 [ V_112 ] . F_22 ( V_16 , V_99 , & V_3 [ V_111 ] ) ;
if ( ! V_106 && V_111 + V_92 >= 255 )
break;
V_111 += V_92 ;
}
}
goto V_120;
}
for ( V_112 = 0 ; V_112 < F_19 ( V_119 ) ; ++ V_112 )
if ( V_119 [ V_112 ] . V_87 == V_87 &&
V_119 [ V_112 ] . V_110 == V_110 ) {
V_111 += V_119 [ V_112 ] . F_22 ( V_16 , V_99 , & V_3 [ V_111 ] ) ;
goto V_120;
}
if ( V_87 != 0x03 )
F_21 ( L_9 ,
V_87 , V_110 ) ;
return V_121 ;
V_120:
if ( V_106 )
F_13 ( V_111 - 2 , V_3 ) ;
else
V_3 [ 0 ] = V_111 - 1 ;
V_88 = F_23 ( V_12 ) ;
if ( V_88 ) {
memcpy ( V_88 , V_3 , F_5 ( T_3 , V_105 , V_12 -> V_97 ) ) ;
F_24 ( V_12 ) ;
}
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
static T_1 F_36 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_89 = V_12 -> V_90 ;
bool V_106 = V_89 [ 0 ] == V_122 ;
int V_43 = V_106 ? 8 : 4 ;
bool V_123 = ! ! ( V_89 [ 1 ] & 0x10 ) ;
T_4 V_87 , V_110 ;
unsigned char * V_3 ;
unsigned char V_124 [ V_105 ] ;
int V_111 ;
int V_92 = 0 ;
int V_112 ;
if ( ! V_12 -> V_97 ) {
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
if ( V_12 -> V_97 < V_43 + 2 )
return V_125 ;
V_3 = F_23 ( V_12 ) ;
if ( ! V_3 )
return V_126 ;
if ( ! V_123 ) {
V_92 = V_95 ;
goto V_96;
}
V_87 = V_3 [ V_43 ] & 0x3f ;
V_110 = V_3 [ V_43 ] & 0x40 ? V_3 [ V_43 + 1 ] : 0 ;
for ( V_112 = 0 ; V_112 < F_19 ( V_119 ) ; ++ V_112 )
if ( V_119 [ V_112 ] . V_87 == V_87 &&
V_119 [ V_112 ] . V_110 == V_110 ) {
memset ( V_124 , 0 , V_105 ) ;
V_111 = V_119 [ V_112 ] . F_22 ( V_16 , 0 , V_124 ) ;
goto V_127;
}
V_92 = V_121 ;
goto V_96;
V_127:
if ( V_12 -> V_97 < V_43 + V_111 ) {
V_92 = V_125 ;
goto V_96;
}
if ( memcmp ( V_3 + V_43 , V_124 , V_111 ) )
V_92 = V_128 ;
V_96:
F_24 ( V_12 ) ;
if ( ! V_92 )
F_25 ( V_12 , V_98 ) ;
return V_92 ;
}
static T_1 F_37 ( struct V_11 * V_12 )
{
unsigned char * V_89 = V_12 -> V_90 ;
unsigned char * V_88 ;
T_4 V_129 = 0 , V_130 = 0 ;
unsigned char V_3 [ V_131 ] ;
memset ( V_3 , 0 , V_131 ) ;
if ( V_89 [ 1 ] & 0x01 ) {
F_21 ( L_10
L_11 ) ;
return V_95 ;
}
V_88 = F_23 ( V_12 ) ;
if ( ! V_88 )
return V_126 ;
if ( ! F_38 ( V_12 , & V_129 , & V_130 ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_132 ] = V_133 ;
V_3 [ V_134 ] = V_129 ;
V_3 [ V_135 ] = V_130 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_132 ] = V_136 ;
V_3 [ V_134 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
memcpy ( V_88 , V_3 , F_5 ( T_3 , sizeof( V_3 ) , V_12 -> V_97 ) ) ;
F_24 ( V_12 ) ;
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
T_1 F_39 ( struct V_11 * V_12 )
{
struct V_137 * V_138 ;
struct V_139 * V_140 = V_12 -> V_141 ;
unsigned char * V_3 ;
T_3 V_142 = 0 , V_143 = 8 , V_112 ;
if ( V_12 -> V_97 < 16 ) {
F_35 ( L_12 ,
V_12 -> V_97 ) ;
return V_95 ;
}
V_3 = F_23 ( V_12 ) ;
if ( ! V_3 )
return V_126 ;
if ( ! V_140 ) {
F_40 ( 0 , (struct V_144 * ) & V_3 [ V_143 ] ) ;
V_142 = 1 ;
goto V_145;
}
F_41 ( & V_140 -> V_146 -> V_147 ) ;
for ( V_112 = 0 ; V_112 < V_148 ; V_112 ++ ) {
V_138 = V_140 -> V_146 -> V_149 [ V_112 ] ;
if ( ! ( V_138 -> V_116 & V_150 ) )
continue;
V_142 ++ ;
if ( ( V_143 + 8 ) > V_12 -> V_97 )
continue;
F_40 ( V_138 -> V_151 , (struct V_144 * ) & V_3 [ V_143 ] ) ;
V_143 += 8 ;
}
F_42 ( & V_140 -> V_146 -> V_147 ) ;
V_145:
V_142 *= 8 ;
V_3 [ 0 ] = ( ( V_142 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_142 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_142 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_142 & 0xff ) ;
F_24 ( V_12 ) ;
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
static T_1
F_43 ( struct V_11 * V_12 )
{
F_25 ( V_12 , V_98 ) ;
return 0 ;
}
T_1
F_44 ( struct V_11 * V_12 , unsigned int * V_152 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_89 = V_12 -> V_90 ;
switch ( V_89 [ 0 ] ) {
case V_153 :
* V_152 = V_89 [ 4 ] ;
V_12 -> V_154 = F_36 ;
break;
case V_122 :
* V_152 = ( V_89 [ 7 ] << 8 ) + V_89 [ 8 ] ;
V_12 -> V_154 = F_36 ;
break;
case V_155 :
* V_152 = V_89 [ 4 ] ;
V_12 -> V_154 = F_34 ;
break;
case V_107 :
* V_152 = ( V_89 [ 7 ] << 8 ) + V_89 [ 8 ] ;
V_12 -> V_154 = F_34 ;
break;
case V_156 :
case V_157 :
* V_152 = ( V_89 [ 7 ] << 8 ) + V_89 [ 8 ] ;
break;
case V_158 :
* V_152 = ( V_89 [ 7 ] << 8 ) + V_89 [ 8 ] ;
V_12 -> V_154 = V_159 ;
break;
case V_160 :
* V_152 = ( V_89 [ 7 ] << 8 ) + V_89 [ 8 ] ;
V_12 -> V_154 = V_161 ;
break;
case V_162 :
case V_163 :
if ( V_89 [ 0 ] == V_163 )
* V_152 = ( V_89 [ 7 ] << 8 ) | V_89 [ 8 ] ;
else
* V_152 = V_12 -> V_97 ;
V_12 -> V_154 = V_164 ;
break;
case V_165 :
case V_166 :
if ( V_89 [ 0 ] == V_166 )
* V_152 = ( V_89 [ 7 ] << 8 ) | V_89 [ 8 ] ;
else
* V_152 = V_12 -> V_97 ;
V_12 -> V_154 = V_167 ;
break;
case V_168 :
* V_152 = V_89 [ 4 ] ;
V_12 -> V_154 = F_37 ;
break;
case V_169 :
* V_152 = ( V_89 [ 3 ] << 8 ) + V_89 [ 4 ] ;
V_12 -> V_170 = V_171 ;
V_12 -> V_154 = F_20 ;
break;
case V_172 :
case V_173 :
* V_152 = ( V_89 [ 6 ] << 24 ) | ( V_89 [ 7 ] << 16 ) | ( V_89 [ 8 ] << 8 ) | V_89 [ 9 ] ;
break;
case V_174 :
* V_152 = F_45 ( & V_89 [ 10 ] ) ;
V_12 -> V_154 = V_175 ;
break;
case V_176 :
* V_152 = F_45 ( & V_89 [ 10 ] ) ;
V_12 -> V_154 = V_177 ;
break;
case V_178 :
case V_179 :
* V_152 = ( V_89 [ 10 ] << 24 ) | ( V_89 [ 11 ] << 16 ) |
( V_89 [ 12 ] << 8 ) | V_89 [ 13 ] ;
break;
case V_180 :
case V_181 :
* V_152 = ( V_89 [ 3 ] << 8 ) | V_89 [ 4 ] ;
break;
case V_182 :
* V_152 = ( V_89 [ 6 ] << 16 ) + ( V_89 [ 7 ] << 8 ) + V_89 [ 8 ] ;
break;
case V_183 :
V_12 -> V_154 = F_39 ;
* V_152 = ( V_89 [ 6 ] << 24 ) | ( V_89 [ 7 ] << 16 ) | ( V_89 [ 8 ] << 8 ) | V_89 [ 9 ] ;
V_12 -> V_170 = V_171 ;
break;
case V_184 :
V_12 -> V_154 = F_43 ;
* V_152 = 0 ;
break;
case V_185 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_186 ) {
if ( ( V_89 [ 1 ] & 0x1f ) == V_187 ) {
V_12 -> V_154 =
V_188 ;
}
* V_152 = F_45 ( & V_89 [ 6 ] ) ;
} else {
* V_152 = F_46 ( & V_89 [ 8 ] ) ;
}
break;
case V_189 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_186 ) {
if ( V_89 [ 1 ] == V_190 ) {
V_12 -> V_154 =
V_191 ;
}
* V_152 = F_45 ( & V_89 [ 6 ] ) ;
} else {
* V_152 = F_46 ( & V_89 [ 8 ] ) ;
}
break;
default:
F_35 ( L_13
L_14 ,
V_12 -> V_192 -> V_193 () , V_89 [ 0 ] ) ;
return V_194 ;
}
return 0 ;
}
