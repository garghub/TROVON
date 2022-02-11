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
if ( V_16 -> V_22 . V_68 || V_16 -> V_22 . V_69 )
V_67 = 1 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = V_67 ? 0x3c : 0x10 ;
V_3 [ 4 ] = 0x01 ;
if ( V_16 -> V_22 . V_70 )
V_3 [ 5 ] = 0x01 ;
F_13 ( 1 , & V_3 [ 6 ] ) ;
V_66 = F_14 ( V_16 -> V_22 . V_71 ,
V_16 -> V_22 . V_72 ) ;
F_15 ( V_66 , & V_3 [ 8 ] ) ;
F_15 ( V_16 -> V_22 . V_73 , & V_3 [ 12 ] ) ;
if ( ! V_67 )
goto V_74;
F_15 ( V_16 -> V_22 . V_75 , & V_3 [ 20 ] ) ;
F_15 ( V_16 -> V_22 . V_76 ,
& V_3 [ 24 ] ) ;
F_15 ( V_16 -> V_22 . V_77 , & V_3 [ 28 ] ) ;
F_15 ( V_16 -> V_22 . V_78 ,
& V_3 [ 32 ] ) ;
if ( V_16 -> V_22 . V_78 != 0 )
V_3 [ 32 ] |= 0x80 ;
V_74:
F_16 ( V_16 -> V_22 . V_79 , & V_3 [ 36 ] ) ;
return 0 ;
}
static T_1
F_17 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
V_3 [ 3 ] = 0x3c ;
V_3 [ 5 ] = V_16 -> V_22 . V_80 ? 1 : 0 ;
return 0 ;
}
static T_1
F_18 ( struct V_11 * V_12 , unsigned char * V_3 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
F_13 ( 0x0004 , & V_3 [ 2 ] ) ;
V_3 [ 4 ] = 0x00 ;
if ( V_16 -> V_22 . V_68 != 0 )
V_3 [ 5 ] = 0x80 ;
if ( V_16 -> V_22 . V_69 != 0 )
V_3 [ 5 ] |= 0x40 ;
return 0 ;
}
static T_1
F_19 ( struct V_11 * V_12 , unsigned char * V_3 )
{
int V_33 ;
if ( V_12 -> V_17 -> V_29 & V_30 ) {
V_3 [ 3 ] = F_20 ( V_81 ) ;
for ( V_33 = 0 ; V_33 < F_20 ( V_81 ) ; ++ V_33 )
V_3 [ V_33 + 4 ] = V_81 [ V_33 ] . V_82 ;
}
return 0 ;
}
static T_1
F_21 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
struct V_37 * V_38 = V_12 -> V_13 -> V_21 -> V_53 ;
unsigned char * V_83 ;
unsigned char * V_84 = V_12 -> V_85 ;
unsigned char V_3 [ V_86 ] ;
T_1 V_87 ;
int V_33 ;
memset ( V_3 , 0 , V_86 ) ;
if ( V_16 == V_38 -> V_88 . V_89 )
V_3 [ 0 ] = 0x3f ;
else
V_3 [ 0 ] = V_16 -> V_18 -> V_19 ( V_16 ) ;
if ( ! ( V_84 [ 1 ] & 0x1 ) ) {
if ( V_84 [ 2 ] ) {
F_22 ( L_6 ,
V_84 [ 2 ] ) ;
V_87 = V_90 ;
goto V_91;
}
V_87 = F_4 ( V_12 , V_3 ) ;
goto V_91;
}
for ( V_33 = 0 ; V_33 < F_20 ( V_81 ) ; ++ V_33 ) {
if ( V_84 [ 2 ] == V_81 [ V_33 ] . V_82 ) {
V_3 [ 1 ] = V_84 [ 2 ] ;
V_87 = V_81 [ V_33 ] . F_23 ( V_12 , V_3 ) ;
goto V_91;
}
}
F_22 ( L_7 , V_84 [ 2 ] ) ;
V_87 = V_90 ;
V_91:
V_83 = F_24 ( V_12 ) ;
if ( V_83 ) {
memcpy ( V_83 , V_3 , F_5 ( T_3 , sizeof( V_3 ) , V_12 -> V_92 ) ) ;
F_25 ( V_12 ) ;
}
if ( ! V_87 )
F_26 ( V_12 , V_93 ) ;
return V_87 ;
}
static int F_27 ( struct V_15 * V_16 , T_4 V_94 , T_4 * V_33 )
{
V_33 [ 0 ] = 0x01 ;
V_33 [ 1 ] = 0x0a ;
if ( V_94 == 1 )
goto V_91;
V_91:
return 12 ;
}
static int F_28 ( struct V_15 * V_16 , T_4 V_94 , T_4 * V_33 )
{
V_33 [ 0 ] = 0x0a ;
V_33 [ 1 ] = 0x0a ;
if ( V_94 == 1 )
goto V_91;
V_33 [ 2 ] = 2 ;
V_33 [ 3 ] = ( V_16 -> V_22 . V_95 == 1 ) ? 0x00 : 0x10 ;
V_33 [ 4 ] = ( V_16 -> V_22 . V_96 == 2 ) ? 0x30 :
( V_16 -> V_22 . V_96 == 1 ) ? 0x20 : 0x00 ;
V_33 [ 5 ] = ( V_16 -> V_22 . V_97 ) ? 0x40 : 0x00 ;
V_33 [ 8 ] = 0xff ;
V_33 [ 9 ] = 0xff ;
V_33 [ 11 ] = 30 ;
V_91:
return 12 ;
}
static int F_29 ( struct V_15 * V_16 , T_4 V_94 , T_4 * V_33 )
{
V_33 [ 0 ] = 0x08 ;
V_33 [ 1 ] = 0x12 ;
if ( V_94 == 1 )
goto V_91;
if ( F_10 ( V_16 ) )
V_33 [ 2 ] = 0x04 ;
V_33 [ 12 ] = 0x20 ;
V_91:
return 20 ;
}
static int F_30 ( struct V_15 * V_16 , T_4 V_94 , unsigned char * V_33 )
{
V_33 [ 0 ] = 0x1c ;
V_33 [ 1 ] = 0x0a ;
if ( V_94 == 1 )
goto V_91;
V_91:
return 12 ;
}
static void F_31 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_98 :
case V_20 :
default:
V_3 [ 0 ] |= 0x80 ;
break;
}
}
static void F_32 ( unsigned char * V_3 , int type )
{
switch ( type ) {
case V_98 :
V_3 [ 0 ] |= 0x10 ;
break;
default:
break;
}
}
static int F_33 ( unsigned char * V_3 , T_5 V_99 , T_3 V_100 )
{
* V_3 ++ = 8 ;
F_15 ( F_14 ( V_99 , 0xffffffffull ) , V_3 ) ;
V_3 += 4 ;
F_15 ( V_100 , V_3 ) ;
return 9 ;
}
static int F_34 ( unsigned char * V_3 , T_5 V_99 , T_3 V_100 )
{
if ( V_99 <= 0xffffffff )
return F_33 ( V_3 + 3 , V_99 , V_100 ) + 3 ;
* V_3 ++ = 1 ;
V_3 += 2 ;
* V_3 ++ = 16 ;
F_16 ( V_99 , V_3 ) ;
V_3 += 12 ;
F_15 ( V_100 , V_3 ) ;
return 17 ;
}
static T_1 F_35 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_84 = V_12 -> V_85 ;
unsigned char V_3 [ V_101 ] , * V_83 ;
int type = V_16 -> V_18 -> V_19 ( V_16 ) ;
int V_102 = ( V_12 -> V_85 [ 0 ] == V_103 ) ;
bool V_104 = ! ! ( V_84 [ 1 ] & 0x08 ) ;
bool V_105 = V_102 ? ! ! ( V_84 [ 1 ] & 0x10 ) : false ;
T_4 V_94 = V_84 [ 2 ] >> 6 ;
T_4 V_82 = V_84 [ 2 ] & 0x3f ;
T_4 V_106 = V_84 [ 3 ] ;
int V_107 = 0 ;
int V_87 ;
int V_108 ;
memset ( V_3 , 0 , V_101 ) ;
V_107 = V_102 ? 3 : 2 ;
if ( ( V_12 -> V_13 -> V_109 & V_110 ) ||
( V_12 -> V_111 &&
( V_12 -> V_111 -> V_112 & V_110 ) ) )
F_31 ( & V_3 [ V_107 ] , type ) ;
if ( ( F_10 ( V_16 ) ) &&
( V_16 -> V_22 . V_113 > 0 ) )
F_32 ( & V_3 [ V_107 ] , type ) ;
++ V_107 ;
if ( ! V_104 && type == V_98 ) {
T_5 V_99 = V_16 -> V_18 -> V_114 ( V_16 ) ;
T_3 V_100 = V_16 -> V_22 . V_100 ;
if ( V_102 ) {
if ( V_105 ) {
V_107 += F_34 ( & V_3 [ V_107 ] ,
V_99 , V_100 ) ;
} else {
V_107 += 3 ;
V_107 += F_33 ( & V_3 [ V_107 ] ,
V_99 , V_100 ) ;
}
} else {
V_107 += F_33 ( & V_3 [ V_107 ] , V_99 ,
V_100 ) ;
}
} else {
if ( V_102 )
V_107 += 4 ;
else
V_107 += 1 ;
}
if ( V_82 == 0x3f ) {
if ( V_106 != 0x00 && V_106 != 0xff ) {
F_36 ( L_8 , V_106 ) ;
return V_90 ;
}
for ( V_108 = 0 ; V_108 < F_20 ( V_115 ) ; ++ V_108 ) {
if ( ( V_115 [ V_108 ] . V_106 & ~ V_106 ) == 0 ) {
V_87 = V_115 [ V_108 ] . F_23 ( V_16 , V_94 , & V_3 [ V_107 ] ) ;
if ( ! V_102 && V_107 + V_87 >= 255 )
break;
V_107 += V_87 ;
}
}
goto V_116;
}
for ( V_108 = 0 ; V_108 < F_20 ( V_115 ) ; ++ V_108 )
if ( V_115 [ V_108 ] . V_82 == V_82 &&
V_115 [ V_108 ] . V_106 == V_106 ) {
V_107 += V_115 [ V_108 ] . F_23 ( V_16 , V_94 , & V_3 [ V_107 ] ) ;
goto V_116;
}
if ( V_82 != 0x03 )
F_22 ( L_9 ,
V_82 , V_106 ) ;
return V_117 ;
V_116:
if ( V_102 )
F_13 ( V_107 - 2 , V_3 ) ;
else
V_3 [ 0 ] = V_107 - 1 ;
V_83 = F_24 ( V_12 ) ;
if ( V_83 ) {
memcpy ( V_83 , V_3 , F_5 ( T_3 , V_101 , V_12 -> V_92 ) ) ;
F_25 ( V_12 ) ;
}
F_26 ( V_12 , V_93 ) ;
return 0 ;
}
static T_1 F_37 ( struct V_11 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
char * V_84 = V_12 -> V_85 ;
bool V_102 = V_84 [ 0 ] == V_118 ;
int V_43 = V_102 ? 8 : 4 ;
bool V_119 = ! ! ( V_84 [ 1 ] & 0x10 ) ;
T_4 V_82 , V_106 ;
unsigned char * V_3 ;
unsigned char V_120 [ V_101 ] ;
int V_107 ;
int V_87 = 0 ;
int V_108 ;
if ( ! V_12 -> V_92 ) {
F_26 ( V_12 , V_93 ) ;
return 0 ;
}
if ( V_12 -> V_92 < V_43 + 2 )
return V_121 ;
V_3 = F_24 ( V_12 ) ;
if ( ! V_3 )
return V_122 ;
if ( ! V_119 ) {
V_87 = V_90 ;
goto V_91;
}
V_82 = V_3 [ V_43 ] & 0x3f ;
V_106 = V_3 [ V_43 ] & 0x40 ? V_3 [ V_43 + 1 ] : 0 ;
for ( V_108 = 0 ; V_108 < F_20 ( V_115 ) ; ++ V_108 )
if ( V_115 [ V_108 ] . V_82 == V_82 &&
V_115 [ V_108 ] . V_106 == V_106 ) {
memset ( V_120 , 0 , V_101 ) ;
V_107 = V_115 [ V_108 ] . F_23 ( V_16 , 0 , V_120 ) ;
goto V_123;
}
V_87 = V_117 ;
goto V_91;
V_123:
if ( V_12 -> V_92 < V_43 + V_107 ) {
V_87 = V_121 ;
goto V_91;
}
if ( memcmp ( V_3 + V_43 , V_120 , V_107 ) )
V_87 = V_124 ;
V_91:
F_25 ( V_12 ) ;
if ( ! V_87 )
F_26 ( V_12 , V_93 ) ;
return V_87 ;
}
static T_1 F_38 ( struct V_11 * V_12 )
{
unsigned char * V_84 = V_12 -> V_85 ;
unsigned char * V_83 ;
T_4 V_125 = 0 , V_126 = 0 ;
unsigned char V_3 [ V_127 ] ;
memset ( V_3 , 0 , V_127 ) ;
if ( V_84 [ 1 ] & 0x01 ) {
F_22 ( L_10
L_11 ) ;
return V_90 ;
}
V_83 = F_24 ( V_12 ) ;
if ( ! V_83 )
return V_122 ;
if ( ! F_39 ( V_12 , & V_125 , & V_126 ) ) {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_128 ] = V_129 ;
V_3 [ V_130 ] = V_125 ;
V_3 [ V_131 ] = V_126 ;
V_3 [ 7 ] = 0x0A ;
} else {
V_3 [ 0 ] = 0x70 ;
V_3 [ V_128 ] = V_132 ;
V_3 [ V_130 ] = 0x00 ;
V_3 [ 7 ] = 0x0A ;
}
memcpy ( V_83 , V_3 , F_5 ( T_3 , sizeof( V_3 ) , V_12 -> V_92 ) ) ;
F_25 ( V_12 ) ;
F_26 ( V_12 , V_93 ) ;
return 0 ;
}
T_1 F_40 ( struct V_11 * V_12 )
{
struct V_133 * V_134 ;
struct V_135 * V_136 = V_12 -> V_137 ;
unsigned char * V_3 ;
T_3 V_138 = 0 , V_139 = 8 , V_108 ;
if ( V_12 -> V_92 < 16 ) {
F_36 ( L_12 ,
V_12 -> V_92 ) ;
return V_90 ;
}
V_3 = F_24 ( V_12 ) ;
if ( ! V_3 )
return V_122 ;
if ( ! V_136 ) {
F_41 ( 0 , (struct V_140 * ) & V_3 [ V_139 ] ) ;
V_138 = 1 ;
goto V_141;
}
F_42 ( & V_136 -> V_142 -> V_143 ) ;
for ( V_108 = 0 ; V_108 < V_144 ; V_108 ++ ) {
V_134 = V_136 -> V_142 -> V_145 [ V_108 ] ;
if ( ! ( V_134 -> V_112 & V_146 ) )
continue;
V_138 ++ ;
if ( ( V_139 + 8 ) > V_12 -> V_92 )
continue;
F_41 ( V_134 -> V_147 , (struct V_140 * ) & V_3 [ V_139 ] ) ;
V_139 += 8 ;
}
F_43 ( & V_136 -> V_142 -> V_143 ) ;
V_141:
V_138 *= 8 ;
V_3 [ 0 ] = ( ( V_138 >> 24 ) & 0xff ) ;
V_3 [ 1 ] = ( ( V_138 >> 16 ) & 0xff ) ;
V_3 [ 2 ] = ( ( V_138 >> 8 ) & 0xff ) ;
V_3 [ 3 ] = ( V_138 & 0xff ) ;
F_25 ( V_12 ) ;
F_26 ( V_12 , V_93 ) ;
return 0 ;
}
static T_1
F_44 ( struct V_11 * V_12 )
{
F_26 ( V_12 , V_93 ) ;
return 0 ;
}
T_1
F_45 ( struct V_11 * V_12 , unsigned int * V_148 )
{
struct V_15 * V_16 = V_12 -> V_17 ;
unsigned char * V_84 = V_12 -> V_85 ;
switch ( V_84 [ 0 ] ) {
case V_149 :
* V_148 = V_84 [ 4 ] ;
V_12 -> V_150 = F_37 ;
break;
case V_118 :
* V_148 = ( V_84 [ 7 ] << 8 ) + V_84 [ 8 ] ;
V_12 -> V_150 = F_37 ;
break;
case V_151 :
* V_148 = V_84 [ 4 ] ;
V_12 -> V_150 = F_35 ;
break;
case V_103 :
* V_148 = ( V_84 [ 7 ] << 8 ) + V_84 [ 8 ] ;
V_12 -> V_150 = F_35 ;
break;
case V_152 :
case V_153 :
* V_148 = ( V_84 [ 7 ] << 8 ) + V_84 [ 8 ] ;
break;
case V_154 :
* V_148 = ( V_84 [ 7 ] << 8 ) + V_84 [ 8 ] ;
V_12 -> V_150 = V_155 ;
break;
case V_156 :
* V_148 = ( V_84 [ 7 ] << 8 ) + V_84 [ 8 ] ;
V_12 -> V_150 = V_157 ;
break;
case V_158 :
case V_159 :
if ( V_84 [ 0 ] == V_159 )
* V_148 = ( V_84 [ 7 ] << 8 ) | V_84 [ 8 ] ;
else
* V_148 = V_12 -> V_92 ;
V_12 -> V_150 = V_160 ;
break;
case V_161 :
case V_162 :
if ( V_84 [ 0 ] == V_162 )
* V_148 = ( V_84 [ 7 ] << 8 ) | V_84 [ 8 ] ;
else
* V_148 = V_12 -> V_92 ;
V_12 -> V_150 = V_163 ;
break;
case V_164 :
* V_148 = V_84 [ 4 ] ;
V_12 -> V_150 = F_38 ;
break;
case V_165 :
* V_148 = ( V_84 [ 3 ] << 8 ) + V_84 [ 4 ] ;
V_12 -> V_166 = V_167 ;
V_12 -> V_150 = F_21 ;
break;
case V_168 :
case V_169 :
* V_148 = ( V_84 [ 6 ] << 24 ) | ( V_84 [ 7 ] << 16 ) | ( V_84 [ 8 ] << 8 ) | V_84 [ 9 ] ;
break;
case V_170 :
* V_148 = F_46 ( & V_84 [ 10 ] ) ;
V_12 -> V_150 = V_171 ;
break;
case V_172 :
* V_148 = F_46 ( & V_84 [ 10 ] ) ;
V_12 -> V_150 = V_173 ;
break;
case V_174 :
case V_175 :
* V_148 = ( V_84 [ 10 ] << 24 ) | ( V_84 [ 11 ] << 16 ) |
( V_84 [ 12 ] << 8 ) | V_84 [ 13 ] ;
break;
case V_176 :
case V_177 :
* V_148 = ( V_84 [ 3 ] << 8 ) | V_84 [ 4 ] ;
break;
case V_178 :
* V_148 = ( V_84 [ 6 ] << 16 ) + ( V_84 [ 7 ] << 8 ) + V_84 [ 8 ] ;
break;
case V_179 :
V_12 -> V_150 = F_40 ;
* V_148 = ( V_84 [ 6 ] << 24 ) | ( V_84 [ 7 ] << 16 ) | ( V_84 [ 8 ] << 8 ) | V_84 [ 9 ] ;
V_12 -> V_166 = V_167 ;
break;
case V_180 :
V_12 -> V_150 = F_44 ;
* V_148 = 0 ;
break;
case V_181 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_182 ) {
if ( ( V_84 [ 1 ] & 0x1f ) == V_183 ) {
V_12 -> V_150 =
V_184 ;
}
* V_148 = F_46 ( & V_84 [ 6 ] ) ;
} else {
* V_148 = F_47 ( & V_84 [ 8 ] ) ;
}
break;
case V_185 :
if ( V_16 -> V_18 -> V_19 ( V_16 ) != V_182 ) {
if ( V_84 [ 1 ] == V_186 ) {
V_12 -> V_150 =
V_187 ;
}
* V_148 = F_46 ( & V_84 [ 6 ] ) ;
} else {
* V_148 = F_47 ( & V_84 [ 8 ] ) ;
}
break;
default:
F_36 ( L_13
L_14 ,
V_12 -> V_188 -> V_189 () , V_84 [ 0 ] ) ;
return V_190 ;
}
return 0 ;
}
