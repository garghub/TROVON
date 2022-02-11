static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_5 ) ;
return V_5 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
unsigned int V_14 = V_11 -> V_15 & V_16 ;
if ( ( V_11 -> V_15 & V_17 ) != V_18 )
return - 1 ;
switch ( V_11 -> V_19 ) {
case 1 :
if ( V_14 >= F_3 ( V_20 ) )
return - 1 ;
V_14 = V_20 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
case 2 :
if ( V_14 >= F_3 ( V_21 ) )
return - 1 ;
V_14 = V_21 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
default:
return - 1 ;
}
F_4 ( V_7 , V_11 , V_12 , V_13 , V_22 , V_14 ) ;
return 1 ;
}
static T_1 * F_5 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( ( V_24 -> V_25 & V_26 ) && * V_4 >= 56 &&
V_3 [ 2 ] == 0x09 && V_3 [ 3 ] == 0x02 &&
V_3 [ 54 ] == 0x81 && V_3 [ 55 ] == 0x07 ) {
F_7 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x06 ;
}
if ( ( V_24 -> V_25 & V_27 ) && * V_4 == 467 ) {
F_7 ( V_2 , L_2 ) ;
V_3 = V_28 ;
* V_4 = sizeof( V_28 ) ;
} else if ( ( V_24 -> V_25 & V_29 ) && * V_4 == 357 ) {
F_7 ( V_2 , L_3 ) ;
V_3 = V_30 ;
* V_4 = sizeof( V_30 ) ;
}
if ( ( ( ( V_24 -> V_25 & V_31 ) && * V_4 == 148 ) ||
( ( V_24 -> V_25 & V_32 ) && * V_4 == 149 ) ) &&
V_3 [ 83 ] == 0x75 ) {
F_7 ( V_2 , L_4 ) ;
memcpy ( ( void * ) & V_3 [ 83 ] , ( void * ) & V_33 ,
sizeof( V_33 ) ) ;
} else if ( V_24 -> V_25 & V_31 &&
* V_4 > sizeof( V_34 ) ) {
F_7 ( V_2 , L_5 ,
* V_4 , ( int ) sizeof( V_34 ) ) ;
* V_4 = sizeof( V_34 ) ;
memcpy ( V_3 , & V_34 , * V_4 ) ;
}
if ( V_24 -> V_25 & V_35 )
return F_1 ( V_2 , V_3 , V_4 ) ;
return V_3 ;
}
static void F_8 ( struct V_23 * V_24 , T_1 * V_36 , int V_37 )
{
static const T_1 V_38 [] = { 0 , 1 , 25 , 50 , 75 , 100 } ;
unsigned long V_39 ;
T_1 V_40 , V_41 , V_42 ;
if ( V_36 [ 30 ] >= 0xee ) {
V_41 = 100 ;
V_42 = ! ( V_36 [ 30 ] & 0x01 ) ;
} else {
T_1 V_43 = V_36 [ 30 ] <= 5 ? V_36 [ 30 ] : 5 ;
V_41 = V_38 [ V_43 ] ;
V_42 = 0 ;
}
V_40 = ! ( V_36 [ 31 ] & 0x04 ) ;
F_9 ( & V_24 -> V_44 , V_39 ) ;
V_24 -> V_40 = V_40 ;
V_24 -> V_41 = V_41 ;
V_24 -> V_42 = V_42 ;
F_10 ( & V_24 -> V_44 , V_39 ) ;
}
static void F_11 ( struct V_23 * V_24 , T_1 * V_36 , int V_37 )
{
struct V_6 * V_45 = F_12 ( V_24 -> V_2 -> V_46 . V_47 ,
struct V_6 , V_48 ) ;
struct V_49 * V_49 = V_45 -> V_50 ;
unsigned long V_39 ;
int V_51 , V_52 ;
T_1 V_40 , V_41 , V_42 ;
V_52 = ( V_24 -> V_25 & V_27 ) ? 30 : 32 ;
V_40 = ( V_36 [ V_52 ] >> 4 ) & 0x01 ;
V_41 = V_36 [ V_52 ] & 0x0F ;
if ( ! V_40 || V_41 > 10 )
V_42 = 0 ;
else
V_42 = 1 ;
if ( ! V_40 )
V_41 ++ ;
if ( V_41 > 10 )
V_41 = 10 ;
V_41 *= 10 ;
F_9 ( & V_24 -> V_44 , V_39 ) ;
V_24 -> V_40 = V_40 ;
V_24 -> V_41 = V_41 ;
V_24 -> V_42 = V_42 ;
F_10 ( & V_24 -> V_44 , V_39 ) ;
V_52 += 5 ;
for ( V_51 = 0 ; V_51 < 2 ; V_51 ++ ) {
T_2 V_53 , V_54 ;
V_53 = V_36 [ V_52 + 1 ] | ( ( V_36 [ V_52 + 2 ] & 0xF ) << 8 ) ;
V_54 = ( ( V_36 [ V_52 + 2 ] & 0xF0 ) >> 4 ) | ( V_36 [ V_52 + 3 ] << 4 ) ;
F_13 ( V_49 , V_51 ) ;
F_14 ( V_49 , V_55 ,
! ( V_36 [ V_52 ] >> 7 ) ) ;
F_15 ( V_49 , V_56 , V_53 ) ;
F_15 ( V_49 , V_57 , V_54 ) ;
V_52 += 4 ;
}
}
static int F_16 ( struct V_1 * V_2 , struct V_58 * V_59 ,
T_1 * V_36 , int V_37 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( ( V_24 -> V_25 & V_60 ) && V_36 [ 0 ] == 0x01 && V_37 == 49 ) {
F_17 ( V_36 [ 41 ] , V_36 [ 42 ] ) ;
F_17 ( V_36 [ 43 ] , V_36 [ 44 ] ) ;
F_17 ( V_36 [ 45 ] , V_36 [ 46 ] ) ;
F_17 ( V_36 [ 47 ] , V_36 [ 48 ] ) ;
F_8 ( V_24 , V_36 , V_37 ) ;
} else if ( ( ( V_24 -> V_25 & V_27 ) && V_36 [ 0 ] == 0x01 &&
V_37 == 64 ) || ( ( V_24 -> V_25 & V_29 )
&& V_36 [ 0 ] == 0x11 && V_37 == 78 ) ) {
F_11 ( V_24 , V_36 , V_37 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned long * * V_12 , int * V_13 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( V_24 -> V_25 & V_61 ) {
unsigned int V_14 = V_11 -> V_15 & V_16 ;
if ( ( V_11 -> V_15 & V_17 ) != V_18 )
return - 1 ;
switch ( V_11 -> V_19 ) {
case 1 :
if ( V_14 >= F_3 ( V_62 ) )
return - 1 ;
V_14 = V_62 [ V_14 ] ;
if ( ! V_14 )
return - 1 ;
break;
default:
return - 1 ;
}
F_4 ( V_7 , V_11 , V_12 , V_13 , V_22 , V_14 ) ;
return 1 ;
}
if ( V_24 -> V_25 & V_35 )
return F_2 ( V_2 , V_7 , V_9 , V_11 , V_12 , V_13 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_63 ;
char * V_64 = F_20 ( 18 , V_65 ) ;
if ( ! V_64 )
return - V_66 ;
V_63 = F_21 ( V_2 , 0xf2 , V_64 , 17 , V_67 ,
V_68 ) ;
if ( V_63 < 0 )
F_22 ( V_2 , L_6 ) ;
F_23 ( V_64 ) ;
return V_63 ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned char V_64 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
return F_21 ( V_2 , V_64 [ 0 ] , V_64 , sizeof( V_64 ) ,
V_67 , V_69 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 V_64 [ 37 ] = { 0 } ;
return F_21 ( V_2 , 0x02 , V_64 , sizeof( V_64 ) ,
V_67 , V_68 ) ;
}
static void F_26 ( int V_70 , T_1 V_71 [ V_72 ] )
{
static const T_1 V_73 [ 10 ] [ 4 ] = {
{ 0x01 , 0x00 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x00 , 0x01 , 0x00 } ,
{ 0x00 , 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 , 0x01 } ,
{ 0x00 , 0x01 , 0x00 , 0x01 } ,
{ 0x00 , 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x00 , 0x01 , 0x01 } ,
{ 0x00 , 0x01 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 , 0x01 }
} ;
F_27 ( V_72 < F_3 ( V_73 [ 0 ] ) ) ;
if ( V_70 < 0 )
return;
V_70 %= 10 ;
memcpy ( V_71 , V_73 [ V_70 ] , sizeof( V_73 [ V_70 ] ) ) ;
}
static void F_28 ( int V_70 , T_1 V_71 [ V_72 ] )
{
static const T_1 V_74 [ 7 ] [ 3 ] = {
{ 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 } ,
{ 0x02 , 0x00 , 0x01 } ,
{ 0x02 , 0x01 , 0x00 } ,
{ 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 }
} ;
F_27 ( V_72 < F_3 ( V_74 [ 0 ] ) ) ;
if ( V_70 < 0 )
return;
V_70 %= 7 ;
memcpy ( V_71 , V_74 [ V_70 ] , sizeof( V_74 [ V_70 ] ) ) ;
}
static void F_29 ( struct V_1 * V_2 , const T_1 * V_75 )
{
struct V_76 * V_77 =
& V_2 -> V_78 [ V_79 ] . V_77 ;
struct V_58 * V_59 = F_12 ( V_77 -> V_47 ,
struct V_58 , V_48 ) ;
T_3 * V_80 = V_59 -> V_9 [ 0 ] -> V_80 ;
V_80 [ 0 ] = 0x00 ;
V_80 [ 1 ] = V_75 [ 0 ] ? 0xff : 0x00 ;
V_80 [ 2 ] = V_75 [ 1 ] ? 0xff : 0x00 ;
V_80 [ 3 ] = V_75 [ 2 ] ? 0xff : 0x00 ;
V_80 [ 4 ] = V_75 [ 3 ] ? 0xff : 0x00 ;
V_80 [ 5 ] = 0x00 ;
V_80 [ 6 ] = 0x00 ;
F_30 ( V_2 , V_59 , V_69 ) ;
}
static void F_31 ( struct V_23 * V_24 , const T_1 * V_75 , int V_81 )
{
int V_51 ;
F_27 ( V_81 > V_72 ) ;
if ( V_24 -> V_25 & V_61 && V_81 == 4 ) {
F_29 ( V_24 -> V_2 , V_75 ) ;
} else {
for ( V_51 = 0 ; V_51 < V_81 ; V_51 ++ )
V_24 -> V_82 [ V_51 ] = V_75 [ V_51 ] ;
F_32 ( & V_24 -> V_83 ) ;
}
}
static void F_33 ( struct V_84 * V_85 ,
enum V_86 V_80 )
{
struct V_87 * V_88 = V_85 -> V_88 -> V_89 ;
struct V_1 * V_2 = F_34 ( V_88 , struct V_1 , V_88 ) ;
struct V_23 * V_90 ;
int V_51 ;
int V_91 ;
V_90 = F_6 ( V_2 ) ;
if ( ! V_90 ) {
F_22 ( V_2 , L_7 ) ;
return;
}
V_91 = ! ! ( V_90 -> V_25 & V_31 ) ;
for ( V_51 = 0 ; V_51 < V_90 -> V_92 ; V_51 ++ ) {
if ( V_85 == V_90 -> V_75 [ V_51 ] && ( V_91 ||
( V_80 != V_90 -> V_82 [ V_51 ] ||
V_90 -> V_93 [ V_51 ] ||
V_90 -> V_94 [ V_51 ] ) ) ) {
V_90 -> V_82 [ V_51 ] = V_80 ;
V_90 -> V_93 [ V_51 ] = 0 ;
V_90 -> V_94 [ V_51 ] = 0 ;
F_31 ( V_90 , V_90 -> V_82 ,
V_90 -> V_92 ) ;
break;
}
}
}
static enum V_86 F_35 ( struct V_84 * V_85 )
{
struct V_87 * V_88 = V_85 -> V_88 -> V_89 ;
struct V_1 * V_2 = F_34 ( V_88 , struct V_1 , V_88 ) ;
struct V_23 * V_90 ;
int V_51 ;
V_90 = F_6 ( V_2 ) ;
if ( ! V_90 ) {
F_22 ( V_2 , L_7 ) ;
return V_95 ;
}
for ( V_51 = 0 ; V_51 < V_90 -> V_92 ; V_51 ++ ) {
if ( V_85 == V_90 -> V_75 [ V_51 ] )
return V_90 -> V_82 [ V_51 ] ;
}
return V_95 ;
}
static int F_36 ( struct V_84 * V_85 , unsigned long * V_96 ,
unsigned long * V_97 )
{
struct V_87 * V_88 = V_85 -> V_88 -> V_89 ;
struct V_1 * V_2 = F_34 ( V_88 , struct V_1 , V_88 ) ;
struct V_23 * V_90 = F_6 ( V_2 ) ;
int V_51 ;
T_1 V_98 , V_99 ;
if ( ! V_90 ) {
F_22 ( V_2 , L_7 ) ;
return - V_100 ;
}
if ( * V_96 > 2550 )
* V_96 = 2550 ;
if ( * V_97 > 2550 )
* V_97 = 2550 ;
if ( ! * V_96 && ! * V_97 )
* V_96 = * V_97 = 500 ;
V_98 = * V_96 / 10 ;
V_99 = * V_97 / 10 ;
for ( V_51 = 0 ; V_51 < V_90 -> V_92 ; V_51 ++ ) {
if ( V_85 == V_90 -> V_75 [ V_51 ] )
break;
}
if ( V_51 >= V_90 -> V_92 )
return - V_100 ;
if ( V_98 != V_90 -> V_93 [ V_51 ] ||
V_99 != V_90 -> V_94 [ V_51 ] ) {
V_90 -> V_93 [ V_51 ] = V_98 ;
V_90 -> V_94 [ V_51 ] = V_99 ;
F_32 ( & V_90 -> V_83 ) ;
}
return 0 ;
}
static void F_37 ( struct V_23 * V_24 )
{
struct V_84 * V_85 ;
int V_51 ;
F_27 ( ! ( V_24 -> V_25 & V_101 ) ) ;
for ( V_51 = 0 ; V_51 < V_24 -> V_92 ; V_51 ++ ) {
V_85 = V_24 -> V_75 [ V_51 ] ;
V_24 -> V_75 [ V_51 ] = NULL ;
if ( ! V_85 )
continue;
F_38 ( V_85 ) ;
F_23 ( V_85 ) ;
}
V_24 -> V_92 = 0 ;
}
static int F_39 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
int V_51 , V_63 = 0 ;
int V_102 ;
struct V_84 * V_85 ;
T_4 V_103 ;
char * V_104 ;
T_4 V_105 ;
const char * V_106 ;
static const char * const V_107 [] = { L_8 , L_9 , L_10 ,
L_11 } ;
T_1 V_108 [ V_72 ] = { 0 } ;
T_1 V_109 [ V_72 ] = { 1 } ;
T_1 V_110 [ V_72 ] = { 0 } ;
F_27 ( ! ( V_24 -> V_25 & V_101 ) ) ;
if ( V_24 -> V_25 & V_61 ) {
V_24 -> V_92 = 4 ;
V_102 = 0 ;
V_105 = strlen ( L_12 ) ;
V_106 = L_13 ;
if ( ! F_40 ( V_2 , V_79 , 0 , 0 , 7 ) )
return - V_111 ;
} else if ( V_24 -> V_25 & V_112 ) {
F_28 ( V_24 -> V_113 , V_108 ) ;
V_108 [ 3 ] = 1 ;
V_24 -> V_92 = 4 ;
memset ( V_109 , 255 , 3 ) ;
V_110 [ 3 ] = 1 ;
V_102 = 1 ;
V_105 = 0 ;
V_106 = L_14 ;
} else {
F_26 ( V_24 -> V_113 , V_108 ) ;
V_24 -> V_92 = 4 ;
memset ( V_110 , 1 , 4 ) ;
V_102 = 0 ;
V_105 = strlen ( L_15 ) ;
V_106 = L_16 ;
}
F_31 ( V_24 , V_108 , V_24 -> V_92 ) ;
V_103 = strlen ( F_41 ( & V_2 -> V_88 ) ) + V_105 + 1 ;
for ( V_51 = 0 ; V_51 < V_24 -> V_92 ; V_51 ++ ) {
if ( V_102 )
V_103 = strlen ( F_41 ( & V_2 -> V_88 ) ) + strlen ( V_107 [ V_51 ] ) + 2 ;
V_85 = F_42 ( sizeof( struct V_84 ) + V_103 , V_65 ) ;
if ( ! V_85 ) {
F_22 ( V_2 , L_17 , V_51 ) ;
V_63 = - V_66 ;
goto V_114;
}
V_104 = ( void * ) ( & V_85 [ 1 ] ) ;
if ( V_102 )
snprintf ( V_104 , V_103 , V_106 , F_41 ( & V_2 -> V_88 ) ,
V_107 [ V_51 ] ) ;
else
snprintf ( V_104 , V_103 , V_106 , F_41 ( & V_2 -> V_88 ) , V_51 + 1 ) ;
V_85 -> V_104 = V_104 ;
V_85 -> V_115 = V_108 [ V_51 ] ;
V_85 -> V_109 = V_109 [ V_51 ] ;
V_85 -> V_116 = F_35 ;
V_85 -> V_117 = F_33 ;
if ( V_110 [ V_51 ] )
V_85 -> V_118 = F_36 ;
V_24 -> V_75 [ V_51 ] = V_85 ;
V_63 = F_43 ( & V_2 -> V_88 , V_85 ) ;
if ( V_63 ) {
F_22 ( V_2 , L_18 , V_51 ) ;
V_24 -> V_75 [ V_51 ] = NULL ;
F_23 ( V_85 ) ;
goto V_114;
}
}
return V_63 ;
V_114:
F_37 ( V_24 ) ;
return V_63 ;
}
static void F_44 ( struct V_119 * V_120 )
{
struct V_23 * V_24 = F_34 ( V_120 , struct V_23 , V_83 ) ;
int V_51 ;
union V_121 V_59 = {
. V_64 = {
0x01 ,
0x00 , 0xff , 0x00 , 0xff , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00
}
} ;
#ifdef F_45
V_59 . V_122 . V_123 . V_124 = V_24 -> V_125 ? 1 : 0 ;
V_59 . V_122 . V_123 . V_126 = V_24 -> V_127 ;
#endif
V_59 . V_122 . V_128 |= V_24 -> V_82 [ 0 ] << 1 ;
V_59 . V_122 . V_128 |= V_24 -> V_82 [ 1 ] << 2 ;
V_59 . V_122 . V_128 |= V_24 -> V_82 [ 2 ] << 3 ;
V_59 . V_122 . V_128 |= V_24 -> V_82 [ 3 ] << 4 ;
if ( ( V_59 . V_122 . V_128 & 0x1E ) == 0 )
V_59 . V_122 . V_128 |= 0x20 ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
if ( V_24 -> V_93 [ V_51 ] || V_24 -> V_94 [ V_51 ] ) {
V_59 . V_122 . V_85 [ 3 - V_51 ] . V_129 = V_24 -> V_94 [ V_51 ] ;
V_59 . V_122 . V_85 [ 3 - V_51 ] . V_130 = V_24 -> V_93 [ V_51 ] ;
}
}
F_21 ( V_24 -> V_2 , V_59 . V_122 . V_131 , V_59 . V_64 ,
sizeof( V_59 ) , V_79 , V_69 ) ;
}
static void F_46 ( struct V_119 * V_120 )
{
struct V_23 * V_24 = F_34 ( V_120 , struct V_23 , V_83 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
int V_52 ;
T_1 V_64 [ 78 ] = { 0 } ;
if ( V_24 -> V_25 & V_27 ) {
V_64 [ 0 ] = 0x05 ;
V_64 [ 1 ] = 0xFF ;
V_52 = 4 ;
} else {
V_64 [ 0 ] = 0x11 ;
V_64 [ 1 ] = 0xB0 ;
V_64 [ 3 ] = 0x0F ;
V_52 = 6 ;
}
#ifdef F_45
V_64 [ V_52 ++ ] = V_24 -> V_125 ;
V_64 [ V_52 ++ ] = V_24 -> V_127 ;
#else
V_52 += 2 ;
#endif
if ( V_24 -> V_82 [ 3 ] ) {
V_64 [ V_52 ++ ] = V_24 -> V_82 [ 0 ] ;
V_64 [ V_52 ++ ] = V_24 -> V_82 [ 1 ] ;
V_64 [ V_52 ++ ] = V_24 -> V_82 [ 2 ] ;
} else {
V_52 += 3 ;
}
V_64 [ V_52 ++ ] = V_24 -> V_93 [ 3 ] ;
V_64 [ V_52 ++ ] = V_24 -> V_94 [ 3 ] ;
if ( V_24 -> V_25 & V_27 )
F_47 ( V_2 , V_64 , 32 ) ;
else
F_21 ( V_2 , 0x11 , V_64 , 78 ,
V_79 , V_69 ) ;
}
static int F_48 ( struct V_49 * V_88 , void * V_122 ,
struct V_132 * V_133 )
{
struct V_1 * V_15 = F_49 ( V_88 ) ;
struct V_23 * V_24 = F_6 ( V_15 ) ;
if ( V_133 -> type != V_134 )
return 0 ;
V_24 -> V_127 = V_133 -> V_135 . V_123 . V_136 / 256 ;
V_24 -> V_125 = V_133 -> V_135 . V_123 . V_137 / 256 ;
F_32 ( & V_24 -> V_83 ) ;
return 0 ;
}
static int F_50 ( struct V_23 * V_24 )
{
struct V_6 * V_45 = F_12 ( V_24 -> V_2 -> V_46 . V_47 ,
struct V_6 , V_48 ) ;
struct V_49 * V_49 = V_45 -> V_50 ;
F_51 ( V_49 , V_138 , V_134 ) ;
return F_52 ( V_49 , NULL , F_48 ) ;
}
static int F_50 ( struct V_23 * V_24 )
{
return 0 ;
}
static int F_53 ( struct V_139 * V_140 ,
enum V_141 V_142 ,
union V_143 * V_144 )
{
struct V_23 * V_24 = F_34 ( V_140 , struct V_23 , V_145 ) ;
unsigned long V_39 ;
int V_63 = 0 ;
T_5 V_42 , V_41 , V_40 ;
F_9 ( & V_24 -> V_44 , V_39 ) ;
V_42 = V_24 -> V_42 ;
V_41 = V_24 -> V_41 ;
V_40 = V_24 -> V_40 ;
F_10 ( & V_24 -> V_44 , V_39 ) ;
switch ( V_142 ) {
case V_146 :
V_144 -> V_147 = 1 ;
break;
case V_148 :
V_144 -> V_147 = V_149 ;
break;
case V_150 :
V_144 -> V_147 = V_41 ;
break;
case V_151 :
if ( V_42 )
V_144 -> V_147 = V_152 ;
else
if ( V_41 == 100 && V_40 )
V_144 -> V_147 = V_153 ;
else
V_144 -> V_147 = V_154 ;
break;
default:
V_63 = - V_100 ;
break;
}
return V_63 ;
}
static int F_54 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
int V_63 ;
V_24 -> V_41 = 100 ;
V_24 -> V_145 . V_155 = V_156 ;
V_24 -> V_145 . V_157 = F_3 ( V_156 ) ;
V_24 -> V_145 . V_158 = F_53 ;
V_24 -> V_145 . type = V_159 ;
V_24 -> V_145 . V_160 = 0 ;
V_24 -> V_145 . V_104 = F_55 ( V_65 , L_19 ,
V_24 -> V_161 ) ;
if ( ! V_24 -> V_145 . V_104 )
return - V_66 ;
V_63 = F_56 ( & V_2 -> V_88 , & V_24 -> V_145 ) ;
if ( V_63 ) {
F_22 ( V_2 , L_20 ) ;
goto V_162;
}
F_57 ( & V_24 -> V_145 , & V_2 -> V_88 ) ;
return 0 ;
V_162:
F_23 ( V_24 -> V_145 . V_104 ) ;
V_24 -> V_145 . V_104 = NULL ;
return V_63 ;
}
static void F_58 ( struct V_23 * V_24 )
{
if ( ! V_24 -> V_145 . V_104 )
return;
F_59 ( & V_24 -> V_145 ) ;
F_23 ( V_24 -> V_145 . V_104 ) ;
V_24 -> V_145 . V_104 = NULL ;
}
static int F_60 ( struct V_23 * V_24 , int V_163 ,
int V_164 , int V_165 )
{
struct V_6 * V_45 = F_12 ( V_24 -> V_2 -> V_46 . V_47 ,
struct V_6 , V_48 ) ;
struct V_49 * V_49 = V_45 -> V_50 ;
int V_63 ;
V_63 = F_61 ( V_49 , V_163 , 0 ) ;
if ( V_63 < 0 ) {
F_22 ( V_24 -> V_2 , L_21 ) ;
return V_63 ;
}
F_62 ( V_49 , V_56 , 0 , V_164 , 0 , 0 ) ;
F_62 ( V_49 , V_57 , 0 , V_165 , 0 , 0 ) ;
return 0 ;
}
static int F_63 ( struct V_23 * V_24 )
{
struct V_23 * V_166 ;
unsigned long V_39 ;
int V_63 ;
F_9 ( & V_167 , V_39 ) ;
F_64 (entry, &sony_device_list, list_node) {
V_63 = memcmp ( V_24 -> V_161 , V_166 -> V_161 ,
sizeof( V_24 -> V_161 ) ) ;
if ( ! V_63 ) {
V_63 = - V_168 ;
F_7 ( V_24 -> V_2 , L_22 ,
V_24 -> V_161 ) ;
goto V_169;
}
}
V_63 = 0 ;
F_65 ( & ( V_24 -> V_170 ) , & V_171 ) ;
V_169:
F_10 ( & V_167 , V_39 ) ;
return V_63 ;
}
static void F_66 ( struct V_23 * V_24 )
{
unsigned long V_39 ;
if ( V_24 -> V_170 . V_47 ) {
F_9 ( & V_167 , V_39 ) ;
F_67 ( & ( V_24 -> V_170 ) ) ;
F_10 ( & V_167 , V_39 ) ;
}
}
static int F_68 ( struct V_23 * V_24 )
{
int V_63 ;
V_63 = strlen ( V_24 -> V_2 -> V_172 ) ;
if ( V_63 != 17 )
return - V_100 ;
V_63 = sscanf ( V_24 -> V_2 -> V_172 ,
L_23 ,
& V_24 -> V_161 [ 5 ] , & V_24 -> V_161 [ 4 ] , & V_24 -> V_161 [ 3 ] ,
& V_24 -> V_161 [ 2 ] , & V_24 -> V_161 [ 1 ] , & V_24 -> V_161 [ 0 ] ) ;
if ( V_63 != 6 )
return - V_100 ;
return 0 ;
}
static int F_69 ( struct V_23 * V_24 )
{
int V_51 , V_63 ;
if ( ( V_24 -> V_25 & V_29 ) ||
( V_24 -> V_25 & V_32 ) ) {
if ( F_68 ( V_24 ) < 0 ) {
F_70 ( V_24 -> V_2 , L_24 ) ;
return 0 ;
}
} else if ( V_24 -> V_25 & V_27 ) {
T_1 V_64 [ 7 ] ;
V_63 = F_21 ( V_24 -> V_2 , 0x81 , V_64 , sizeof( V_64 ) ,
V_67 , V_68 ) ;
if ( V_63 != 7 ) {
F_22 ( V_24 -> V_2 , L_25 ) ;
return V_63 < 0 ? V_63 : - V_100 ;
}
memcpy ( V_24 -> V_161 , & V_64 [ 1 ] , sizeof( V_24 -> V_161 ) ) ;
} else if ( V_24 -> V_25 & V_31 ) {
T_1 V_64 [ 18 ] ;
V_63 = F_21 ( V_24 -> V_2 , 0xf2 , V_64 , sizeof( V_64 ) ,
V_67 , V_68 ) ;
if ( V_63 != 18 ) {
F_22 ( V_24 -> V_2 , L_26 ) ;
return V_63 < 0 ? V_63 : - V_100 ;
}
for ( V_51 = 0 ; V_51 < 6 ; V_51 ++ )
V_24 -> V_161 [ 5 - V_51 ] = V_64 [ 4 + V_51 ] ;
} else {
return 0 ;
}
return F_63 ( V_24 ) ;
}
static int F_71 ( struct V_23 * V_24 )
{
int V_63 ;
if ( ( V_24 -> V_25 & V_60 ) ||
( V_24 -> V_25 & V_112 ) ) {
V_63 = F_72 ( & V_173 , 0 , 0 ,
V_65 ) ;
if ( V_63 < 0 ) {
V_24 -> V_113 = - 1 ;
return V_63 ;
}
V_24 -> V_113 = V_63 ;
} else {
V_24 -> V_113 = - 1 ;
}
return 0 ;
}
static void F_73 ( struct V_23 * V_24 )
{
if ( V_24 -> V_113 >= 0 ) {
F_74 ( & V_173 , V_24 -> V_113 ) ;
V_24 -> V_113 = - 1 ;
}
}
static inline void F_75 ( struct V_23 * V_24 ,
void (* F_76)( struct V_119 * ) )
{
if ( ! V_24 -> V_174 )
F_77 ( & V_24 -> V_83 , F_76 ) ;
V_24 -> V_174 = 1 ;
}
static inline void F_78 ( struct V_23 * V_24 )
{
if ( V_24 -> V_174 )
F_79 ( & V_24 -> V_83 ) ;
}
static int F_80 ( struct V_1 * V_2 , const struct V_175 * V_70 )
{
int V_63 ;
unsigned long V_25 = V_70 -> V_176 ;
struct V_23 * V_24 ;
unsigned int V_177 = V_178 ;
V_24 = F_81 ( & V_2 -> V_88 , sizeof( * V_24 ) , V_65 ) ;
if ( V_24 == NULL ) {
F_22 ( V_2 , L_27 ) ;
return - V_66 ;
}
V_24 -> V_25 = V_25 ;
F_82 ( V_2 , V_24 ) ;
V_24 -> V_2 = V_2 ;
V_63 = F_83 ( V_2 ) ;
if ( V_63 ) {
F_22 ( V_2 , L_28 ) ;
return V_63 ;
}
if ( V_24 -> V_25 & V_26 )
V_177 |= V_179 ;
else if ( V_24 -> V_25 & V_31 )
V_177 |= V_179 ;
else if ( V_24 -> V_25 & V_32 )
V_177 |= V_179 ;
V_63 = F_84 ( V_2 , V_177 ) ;
if ( V_63 ) {
F_22 ( V_2 , L_29 ) ;
return V_63 ;
}
V_63 = F_71 ( V_24 ) ;
if ( V_63 < 0 ) {
F_22 ( V_2 , L_30 ) ;
goto V_180;
}
if ( V_24 -> V_25 & V_31 ) {
V_2 -> V_25 |= V_181 ;
V_2 -> V_25 |= V_182 ;
V_63 = F_19 ( V_2 ) ;
F_75 ( V_24 , F_44 ) ;
} else if ( V_24 -> V_25 & V_32 ) {
V_2 -> V_25 |= V_181 ;
V_63 = F_24 ( V_2 ) ;
F_75 ( V_24 , F_44 ) ;
} else if ( V_24 -> V_25 & V_112 ) {
if ( V_24 -> V_25 & V_29 ) {
V_2 -> V_25 |= V_181 ;
V_63 = F_25 ( V_2 ) ;
if ( V_63 < 0 ) {
F_22 ( V_2 , L_31 ) ;
goto V_180;
}
}
V_63 = F_60 ( V_24 , 2 , 1920 , 940 ) ;
if ( V_63 < 0 )
goto V_180;
F_75 ( V_24 , F_46 ) ;
} else {
V_63 = 0 ;
}
if ( V_63 < 0 )
goto V_180;
V_63 = F_69 ( V_24 ) ;
if ( V_63 < 0 )
goto V_180;
if ( V_24 -> V_25 & V_101 ) {
V_63 = F_39 ( V_24 ) ;
if ( V_63 < 0 )
goto V_180;
}
if ( V_24 -> V_25 & V_183 ) {
V_63 = F_54 ( V_24 ) ;
if ( V_63 < 0 )
goto V_180;
V_63 = F_85 ( V_2 ) ;
if ( V_63 < 0 ) {
F_22 ( V_2 , L_32 ) ;
goto V_180;
}
}
if ( V_24 -> V_25 & V_184 ) {
V_63 = F_50 ( V_24 ) ;
if ( V_63 < 0 )
goto V_185;
}
return 0 ;
V_185:
F_86 ( V_2 ) ;
V_180:
if ( V_24 -> V_25 & V_101 )
F_37 ( V_24 ) ;
if ( V_24 -> V_25 & V_183 )
F_58 ( V_24 ) ;
F_78 ( V_24 ) ;
F_66 ( V_24 ) ;
F_73 ( V_24 ) ;
F_87 ( V_2 ) ;
return V_63 ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( V_24 -> V_25 & V_101 )
F_37 ( V_24 ) ;
if ( V_24 -> V_25 & V_183 ) {
F_86 ( V_2 ) ;
F_58 ( V_24 ) ;
}
F_78 ( V_24 ) ;
F_66 ( V_24 ) ;
F_73 ( V_24 ) ;
F_87 ( V_2 ) ;
}
static int T_6 F_89 ( void )
{
F_90 ( L_33 , V_186 ) ;
return F_91 ( & V_187 ) ;
}
static void T_7 F_92 ( void )
{
F_90 ( L_33 , V_186 ) ;
F_93 ( & V_173 ) ;
F_94 ( & V_187 ) ;
}
