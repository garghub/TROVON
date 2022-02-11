static void F_1 ( struct V_1 * V_2 , unsigned char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
static char * V_7 [ 16 ] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
} ;
F_2 ( L_17 , V_3 [ 0 ] ) ;
F_2 ( L_18 , ( V_3 [ 0 ] & 0x01 ) ? L_19 : L_20 ) ;
F_2 ( L_21 , V_7 [ ( V_3 [ 0 ] >> 1 ) & 0x0f ] ) ;
F_2 ( L_22 , ( V_3 [ 0 ] & 0x20 ) ? L_23 : L_24 ) ;
F_2 ( L_25 , ( V_3 [ 0 ] & 0x40 ) ? L_26 : L_27 ) ;
F_2 ( L_28 , ( V_3 [ 0 ] & 0x80 ) ? L_23 : L_24 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned char * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
static char * V_8 [ 4 ] = {
L_29 ,
L_30 ,
L_31 ,
L_30
} ;
static char * V_9 [ 32 ] = {
L_32 , L_33 , L_34 , L_35 , L_36 , L_37 , L_38 , L_39 ,
L_40 , L_41 , L_42 , L_43 , L_44 , L_45 , L_46 , L_47 ,
L_48 , L_49 , L_50 , L_51 , L_52 , L_53 , L_54 , L_55 ,
L_56 , L_57 , L_58 , L_59 , L_60 , L_61 , L_62 , L_63
} ;
static char * V_10 [ 4 ] = {
L_20 , L_20 , L_64 , L_65
} ;
static char * V_11 [ 4 ] = {
L_66 ,
L_67 ,
L_68 ,
L_69
} ;
static char * V_12 [ 8 ] = {
L_70 ,
L_71 ,
L_72 ,
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
} ;
static char * V_13 [ 4 ] = {
L_78 ,
L_79 ,
L_79 ,
L_78 ,
} ;
F_2 ( L_80 , V_3 [ 1 ] ) ;
F_2 ( L_81 ,
( V_3 [ 1 ] & 0x01 ) ? L_82 : L_83 ) ;
F_2 ( L_84 ,
( V_3 [ 1 ] & 0x02 ) ? L_19 : L_20 ) ;
F_2 ( L_85 ,
( V_3 [ 1 ] & 0x04 ) ? L_86 : L_87 ) ;
F_2 ( L_88 ,
V_8 [ ( V_3 [ 1 ] & 0x18 ) >> 3 ] ) ;
F_2 ( L_89 ,
( V_3 [ 1 ] & 0x20 ) ? L_19 : L_20 ) ;
F_2 ( L_90 ,
( V_3 [ 1 ] & 0x40 ) ? L_91 : L_92 ) ;
F_2 ( L_93 ,
( V_3 [ 1 ] & 0x80 ) ? L_91 : L_92 ) ;
F_2 ( L_94 , V_3 [ 2 ] ) ;
F_2 ( L_95 ,
V_9 [ V_3 [ 2 ] & 0x1f ] ) ;
F_2 ( L_96 ,
V_10 [ ( V_3 [ 2 ] & 0x60 ) >> 5 ] ) ;
F_2 ( L_97 ,
( V_3 [ 2 ] & 0x80 ) ? L_42 : L_48 ) ;
F_2 ( L_98 , V_3 [ 3 ] ) ;
F_2 ( L_99 ,
V_11 [ ( V_3 [ 3 ] & 0x03 ) ] ) ;
F_2 ( L_100 ,
( V_3 [ 3 ] & 0x40 ) ? L_101 : L_102 ) ;
if ( V_3 [ 1 ] & 0x08 ) {
F_2 ( L_103 ,
V_13 [ ( V_3 [ 3 ] & 0x0c ) >> 2 ] ) ;
F_2 ( L_104 ,
( V_3 [ 3 ] & 0x80 )
? ( ( V_3 [ 3 ] & 0x10 ) ? L_105 :
L_106 )
: L_107 ) ;
} else {
F_2 ( L_103 ,
V_12 [ ( V_3 [ 3 ] & 0x1c ) >> 2 ] ) ;
F_2 ( L_108 ,
( V_3 [ 3 ] & 0x80 )
? ( ( V_3 [ 3 ] & 0x20 ) ? L_109 : L_110 )
: ( ( V_3 [ 3 ] & 0x20 ) ? L_111 : L_110 ) ) ;
F_2 ( L_104 ,
( V_3 [ 3 ] & 0x80 ) ? ( ( V_3 [ 3 ] & 0x20 )
? L_112
: L_113 )
: L_114 ) ;
}
F_2 ( L_115 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_14 * V_15 = NULL ;
char * V_3 = V_5 -> V_16 ;
int V_17 ;
if ( V_5 -> V_18 == V_19 ) {
if ( V_5 -> V_20 == V_21 )
V_15 = & V_22 ;
else
V_15 = & V_23 ;
} else {
for ( V_17 = 0 ; V_17 < F_5 ( V_24 ) ; V_17 ++ ) {
if ( V_24 [ V_17 ] . V_25 & V_5 -> V_25 ) {
V_15 = V_24 + V_17 ;
break;
}
}
}
if ( NULL == V_15 ) {
F_6 ( L_116 ) ;
return - 1 ;
}
F_6 ( L_117 , V_15 -> V_26 ) ;
V_3 [ 1 ] = V_15 -> V_27 ;
V_3 [ 2 ] = V_15 -> V_28 ;
V_3 [ 3 ] = V_15 -> V_29 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
char * V_3 = V_5 -> V_16 ;
if ( V_30 != V_31 ) {
if ( V_31 )
V_3 [ 1 ] |= V_32 ;
else
V_3 [ 1 ] &= ~ V_32 ;
}
if ( V_30 != V_33 ) {
if ( V_33 )
V_3 [ 1 ] |= V_34 ;
else
V_3 [ 1 ] &= ~ V_34 ;
}
if ( V_30 != V_35 ) {
if ( V_35 )
V_3 [ 1 ] |= V_36 ;
else
V_3 [ 1 ] &= ~ V_36 ;
}
if ( V_9 < 0x20 ) {
V_3 [ 2 ] &= ~ V_37 ;
V_3 [ 2 ] |= V_9 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
char * V_3 = V_5 -> V_16 ;
if ( V_5 -> V_38 & V_39 )
V_3 [ 1 ] &= ~ V_32 ;
if ( V_5 -> V_38 & V_40 )
V_3 [ 1 ] |= V_32 ;
if ( V_5 -> V_38 & V_41 )
V_3 [ 1 ] &= ~ V_34 ;
if ( V_5 -> V_38 & V_42 )
V_3 [ 1 ] |= V_34 ;
if ( V_5 -> V_38 & V_43 )
V_3 [ 1 ] |= V_36 ;
if ( V_5 -> V_38 & V_44 )
V_3 [ 1 ] &= ~ V_36 ;
if ( V_5 -> V_38 & V_45 )
V_3 [ 1 ] |= V_46 ;
if ( V_5 -> V_38 & V_47 ) {
V_3 [ 2 ] &= ~ 0x60 ;
switch ( V_5 -> V_38 & V_47 ) {
case V_48 :
V_3 [ 2 ] |= V_49 ;
break;
case V_50 :
V_3 [ 2 ] |= V_51 | V_52 ;
break;
case V_53 :
V_3 [ 2 ] |= V_51 | V_54 ;
break;
}
}
if ( V_5 -> V_38 & V_55 ) {
V_3 [ 2 ] &= ~ V_37 ;
V_3 [ 2 ] |= ( V_5 -> V_38 >> 8 ) & V_37 ;
}
if ( ( V_5 -> V_38 & V_56 ) &&
( V_5 -> V_25 & V_57 ) )
V_3 [ 1 ] &= ~ V_36 ;
if ( V_5 -> V_38 & V_58 )
V_3 [ 3 ] &= ~ V_59 ;
if ( V_5 -> V_18 == V_19 ) {
if ( V_5 -> V_38 & V_60 ) {
V_3 [ 3 ] &= ~ V_61 ;
V_3 [ 3 ] |= V_62 ;
}
if ( V_5 -> V_38 & V_63 )
V_3 [ 3 ] &= ~ V_64 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_3 [ 1 ] ;
int V_65 ;
V_65 = F_10 ( & V_5 -> V_66 , V_3 , 1 ) ;
if ( V_65 != 1 )
F_2 ( L_118 , V_65 ) ;
F_1 ( V_2 , V_3 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_65 ;
memset ( V_5 -> V_16 , 0 , sizeof( V_5 -> V_16 ) ) ;
F_4 ( V_2 ) ;
V_5 -> V_16 [ 1 ] |= V_32 ;
V_5 -> V_16 [ 1 ] |= V_34 ;
F_8 ( V_2 ) ;
F_7 ( V_2 ) ;
if ( V_5 -> V_67 )
V_5 -> V_16 [ 1 ] |= V_68 ;
F_6 ( L_119 ,
V_5 -> V_16 [ 1 ] , V_5 -> V_16 [ 2 ] , V_5 -> V_16 [ 3 ] ) ;
if ( V_69 > 1 )
F_3 ( V_2 , V_5 -> V_16 ) ;
if ( 4 != ( V_65 = F_12 ( & V_5 -> V_66 , V_5 -> V_16 , 4 ) ) )
F_2 ( L_120 , V_65 ) ;
if ( V_69 > 2 ) {
F_13 ( 1000 ) ;
F_9 ( V_2 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_2 ( L_121 ,
V_5 -> V_16 [ 1 ] , V_5 -> V_16 [ 2 ] , V_5 -> V_16 [ 3 ] ) ;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_7 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
static const int V_70 [] = {
- 12500 , - 37500 , - 62500 , - 97500 ,
- 112500 , - 137500 , - 162500 , - 187500 ,
187500 , 162500 , 137500 , 112500 ,
97500 , 62500 , 37500 , 12500
} ;
T_2 V_71 = 0 ;
if ( V_5 -> V_18 != V_19 )
return 0 ;
if ( 1 == F_10 ( & V_5 -> V_66 , & V_71 , 1 ) )
* V_7 = V_70 [ ( V_71 >> 1 ) & 0x0f ] ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_5 -> V_67 = true ;
F_11 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_5 -> V_67 = false ;
V_5 -> V_18 = V_73 -> V_18 ;
V_5 -> V_20 = V_73 -> V_20 ;
V_5 -> V_25 = V_73 -> V_25 ;
F_11 ( V_2 ) ;
}
static int F_18 ( struct V_1 * V_2 , void * V_74 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_5 -> V_38 = * ( unsigned int * ) V_74 ;
F_11 ( V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_20 ( & V_75 ) ;
if ( V_5 )
F_21 ( V_5 ) ;
F_22 ( & V_75 ) ;
V_2 -> V_6 = NULL ;
}
struct V_1 * F_23 ( struct V_1 * V_2 ,
struct V_76 * V_77 ,
T_3 V_78 )
{
struct V_4 * V_5 = NULL ;
int V_79 ;
F_20 ( & V_75 ) ;
V_79 = F_24 ( struct V_4 , V_5 ,
V_80 ,
V_77 , V_78 , L_122 ) ;
switch ( V_79 ) {
case 0 :
F_22 ( & V_75 ) ;
return NULL ;
case 1 :
V_2 -> V_6 = V_5 ;
V_5 -> V_67 = true ;
F_2 ( L_123 ) ;
break;
default:
V_2 -> V_6 = V_5 ;
break;
}
F_22 ( & V_75 ) ;
memcpy ( & V_2 -> V_81 . V_82 , & V_83 ,
sizeof( struct V_84 ) ) ;
return V_2 ;
}
