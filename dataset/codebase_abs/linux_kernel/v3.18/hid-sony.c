static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_5 ) ;
return V_5 ;
}
static T_1 * F_2 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_6 ) ;
return V_6 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned long * * V_13 , int * V_14 )
{
unsigned int V_15 = V_12 -> V_16 & V_17 ;
if ( ( V_12 -> V_16 & V_18 ) != V_19 )
return - 1 ;
switch ( V_12 -> V_20 ) {
case 1 :
if ( V_15 >= F_4 ( V_21 ) )
return - 1 ;
V_15 = V_21 [ V_15 ] ;
if ( ! V_15 )
return - 1 ;
break;
case 2 :
if ( V_15 >= F_4 ( V_22 ) )
return - 1 ;
V_15 = V_22 [ V_15 ] ;
if ( ! V_15 )
return - 1 ;
break;
default:
return - 1 ;
}
F_5 ( V_8 , V_12 , V_13 , V_14 , V_23 , V_15 ) ;
return 1 ;
}
static T_1 * F_6 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_24 * V_25 = F_7 ( V_2 ) ;
if ( ( V_25 -> V_26 & V_27 ) && * V_4 >= 56 &&
V_3 [ 2 ] == 0x09 && V_3 [ 3 ] == 0x02 &&
V_3 [ 54 ] == 0x81 && V_3 [ 55 ] == 0x07 ) {
F_8 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x06 ;
}
if ( ( V_25 -> V_26 & V_28 ) && * V_4 == 467 ) {
F_8 ( V_2 , L_2 ) ;
V_3 = V_29 ;
* V_4 = sizeof( V_29 ) ;
} else if ( ( V_25 -> V_26 & V_30 ) && * V_4 == 357 ) {
F_8 ( V_2 , L_3 ) ;
V_3 = V_31 ;
* V_4 = sizeof( V_31 ) ;
}
if ( V_25 -> V_26 & V_32 )
return F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_25 -> V_26 & V_33 )
return F_2 ( V_2 , V_3 , V_4 ) ;
return V_3 ;
}
static void F_9 ( struct V_24 * V_25 , T_1 * V_34 , int V_35 )
{
static const T_1 V_36 [] = { 0 , 1 , 25 , 50 , 75 , 100 } ;
unsigned long V_37 ;
T_1 V_38 , V_39 , V_40 ;
if ( V_34 [ 30 ] >= 0xee ) {
V_39 = 100 ;
V_40 = ! ( V_34 [ 30 ] & 0x01 ) ;
V_38 = 1 ;
} else {
T_1 V_41 = V_34 [ 30 ] <= 5 ? V_34 [ 30 ] : 5 ;
V_39 = V_36 [ V_41 ] ;
V_40 = 0 ;
V_38 = 0 ;
}
F_10 ( & V_25 -> V_42 , V_37 ) ;
V_25 -> V_38 = V_38 ;
V_25 -> V_39 = V_39 ;
V_25 -> V_40 = V_40 ;
F_11 ( & V_25 -> V_42 , V_37 ) ;
}
static void F_12 ( struct V_24 * V_25 , T_1 * V_34 , int V_35 )
{
struct V_7 * V_43 = F_13 ( V_25 -> V_2 -> V_44 . V_45 ,
struct V_7 , V_46 ) ;
struct V_47 * V_47 = V_43 -> V_48 ;
unsigned long V_37 ;
int V_49 , V_50 ;
T_1 V_38 , V_39 , V_40 ;
V_50 = ( V_25 -> V_26 & V_28 ) ? 30 : 32 ;
V_38 = ( V_34 [ V_50 ] >> 4 ) & 0x01 ;
V_39 = V_34 [ V_50 ] & 0x0F ;
if ( ! V_38 || V_39 > 10 )
V_40 = 0 ;
else
V_40 = 1 ;
if ( ! V_38 )
V_39 ++ ;
if ( V_39 > 10 )
V_39 = 10 ;
V_39 *= 10 ;
F_10 ( & V_25 -> V_42 , V_37 ) ;
V_25 -> V_38 = V_38 ;
V_25 -> V_39 = V_39 ;
V_25 -> V_40 = V_40 ;
F_11 ( & V_25 -> V_42 , V_37 ) ;
V_50 += 5 ;
for ( V_49 = 0 ; V_49 < 2 ; V_49 ++ ) {
T_2 V_51 , V_52 ;
V_51 = V_34 [ V_50 + 1 ] | ( ( V_34 [ V_50 + 2 ] & 0xF ) << 8 ) ;
V_52 = ( ( V_34 [ V_50 + 2 ] & 0xF0 ) >> 4 ) | ( V_34 [ V_50 + 3 ] << 4 ) ;
F_14 ( V_47 , V_49 ) ;
F_15 ( V_47 , V_53 ,
! ( V_34 [ V_50 ] >> 7 ) ) ;
F_16 ( V_47 , V_54 , V_51 ) ;
F_16 ( V_47 , V_55 , V_52 ) ;
V_50 += 4 ;
}
}
static int F_17 ( struct V_1 * V_2 , struct V_56 * V_57 ,
T_1 * V_34 , int V_35 )
{
struct V_24 * V_25 = F_7 ( V_2 ) ;
if ( ( V_25 -> V_26 & V_32 ) && V_34 [ 0 ] == 0x01 && V_35 == 49 ) {
F_18 ( V_34 [ 41 ] , V_34 [ 42 ] ) ;
F_18 ( V_34 [ 43 ] , V_34 [ 44 ] ) ;
F_18 ( V_34 [ 45 ] , V_34 [ 46 ] ) ;
F_18 ( V_34 [ 47 ] , V_34 [ 48 ] ) ;
F_9 ( V_25 , V_34 , V_35 ) ;
} else if ( ( ( V_25 -> V_26 & V_28 ) && V_34 [ 0 ] == 0x01 &&
V_35 == 64 ) || ( ( V_25 -> V_26 & V_30 )
&& V_34 [ 0 ] == 0x11 && V_35 == 78 ) ) {
F_12 ( V_25 , V_34 , V_35 ) ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_11 * V_12 ,
unsigned long * * V_13 , int * V_14 )
{
struct V_24 * V_25 = F_7 ( V_2 ) ;
if ( V_25 -> V_26 & V_58 ) {
unsigned int V_15 = V_12 -> V_16 & V_17 ;
if ( ( V_12 -> V_16 & V_18 ) != V_19 )
return - 1 ;
switch ( V_12 -> V_20 ) {
case 1 :
if ( V_15 >= F_4 ( V_59 ) )
return - 1 ;
V_15 = V_59 [ V_15 ] ;
if ( ! V_15 )
return - 1 ;
break;
default:
return - 1 ;
}
F_5 ( V_8 , V_12 , V_13 , V_14 , V_23 , V_15 ) ;
return 1 ;
}
if ( V_25 -> V_26 & V_33 )
return F_3 ( V_2 , V_8 , V_10 , V_12 , V_13 , V_14 ) ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , int V_60 ,
int V_61 , int V_62 )
{
struct V_47 * V_47 = V_8 -> V_48 ;
int V_63 ;
V_63 = F_21 ( V_47 , V_60 , 0 ) ;
if ( V_63 < 0 )
return V_63 ;
F_22 ( V_47 , V_54 , 0 , V_61 , 0 , 0 ) ;
F_22 ( V_47 , V_55 , 0 , V_62 , 0 , 0 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_7 * V_43 )
{
struct V_24 * V_25 = F_7 ( V_2 ) ;
if ( V_25 -> V_26 & V_64 ) {
if ( F_20 ( V_43 , 2 , 1920 , 942 ) != 0 )
F_24 ( V_25 -> V_2 ,
L_4 ) ;
}
}
static int F_25 ( struct V_1 * V_2 )
{
int V_63 ;
char * V_65 = F_26 ( 18 , V_66 ) ;
if ( ! V_65 )
return - V_67 ;
V_63 = F_27 ( V_2 , 0xf2 , V_65 , 17 , V_68 ,
V_69 ) ;
if ( V_63 < 0 )
F_24 ( V_2 , L_5 ) ;
F_28 ( V_65 ) ;
return V_63 ;
}
static int F_29 ( struct V_1 * V_2 )
{
unsigned char V_65 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
return F_27 ( V_2 , V_65 [ 0 ] , V_65 , sizeof( V_65 ) ,
V_68 , V_70 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_65 [ 37 ] = { 0 } ;
return F_27 ( V_2 , 0x02 , V_65 , sizeof( V_65 ) ,
V_68 , V_69 ) ;
}
static void F_31 ( int V_71 , T_1 V_72 [ V_73 ] )
{
static const T_1 V_74 [ 10 ] [ 4 ] = {
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
F_32 ( V_73 < F_4 ( V_74 [ 0 ] ) ) ;
if ( V_71 < 0 )
return;
V_71 %= 10 ;
memcpy ( V_72 , V_74 [ V_71 ] , sizeof( V_74 [ V_71 ] ) ) ;
}
static void F_33 ( int V_71 , T_1 V_72 [ V_73 ] )
{
static const T_1 V_75 [ 7 ] [ 3 ] = {
{ 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 } ,
{ 0x02 , 0x00 , 0x01 } ,
{ 0x02 , 0x01 , 0x00 } ,
{ 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 }
} ;
F_32 ( V_73 < F_4 ( V_75 [ 0 ] ) ) ;
if ( V_71 < 0 )
return;
V_71 %= 7 ;
memcpy ( V_72 , V_75 [ V_71 ] , sizeof( V_75 [ V_71 ] ) ) ;
}
static void F_34 ( struct V_1 * V_2 , const T_1 * V_76 )
{
struct V_77 * V_78 =
& V_2 -> V_79 [ V_80 ] . V_78 ;
struct V_56 * V_57 = F_13 ( V_78 -> V_45 ,
struct V_56 , V_46 ) ;
T_3 * V_81 = V_57 -> V_10 [ 0 ] -> V_81 ;
V_81 [ 0 ] = 0x00 ;
V_81 [ 1 ] = V_76 [ 0 ] ? 0xff : 0x00 ;
V_81 [ 2 ] = V_76 [ 1 ] ? 0xff : 0x00 ;
V_81 [ 3 ] = V_76 [ 2 ] ? 0xff : 0x00 ;
V_81 [ 4 ] = V_76 [ 3 ] ? 0xff : 0x00 ;
V_81 [ 5 ] = 0x00 ;
V_81 [ 6 ] = 0x00 ;
F_35 ( V_2 , V_57 , V_70 ) ;
}
static void F_36 ( struct V_24 * V_25 , const T_1 * V_76 , int V_82 )
{
int V_49 ;
F_32 ( V_82 > V_73 ) ;
if ( V_25 -> V_26 & V_58 && V_82 == 4 ) {
F_34 ( V_25 -> V_2 , V_76 ) ;
} else {
for ( V_49 = 0 ; V_49 < V_82 ; V_49 ++ )
V_25 -> V_83 [ V_49 ] = V_76 [ V_49 ] ;
F_37 ( & V_25 -> V_84 ) ;
}
}
static void F_38 ( struct V_85 * V_86 ,
enum V_87 V_81 )
{
struct V_88 * V_89 = V_86 -> V_89 -> V_90 ;
struct V_1 * V_2 = F_39 ( V_89 , struct V_1 , V_89 ) ;
struct V_24 * V_91 ;
int V_49 ;
int V_92 ;
V_91 = F_7 ( V_2 ) ;
if ( ! V_91 ) {
F_24 ( V_2 , L_6 ) ;
return;
}
V_92 = ! ! ( V_91 -> V_26 & V_93 ) ;
for ( V_49 = 0 ; V_49 < V_91 -> V_94 ; V_49 ++ ) {
if ( V_86 == V_91 -> V_76 [ V_49 ] && ( V_92 ||
( V_81 != V_91 -> V_83 [ V_49 ] ||
V_91 -> V_95 [ V_49 ] ||
V_91 -> V_96 [ V_49 ] ) ) ) {
V_91 -> V_83 [ V_49 ] = V_81 ;
V_91 -> V_95 [ V_49 ] = 0 ;
V_91 -> V_96 [ V_49 ] = 0 ;
F_36 ( V_91 , V_91 -> V_83 ,
V_91 -> V_94 ) ;
break;
}
}
}
static enum V_87 F_40 ( struct V_85 * V_86 )
{
struct V_88 * V_89 = V_86 -> V_89 -> V_90 ;
struct V_1 * V_2 = F_39 ( V_89 , struct V_1 , V_89 ) ;
struct V_24 * V_91 ;
int V_49 ;
V_91 = F_7 ( V_2 ) ;
if ( ! V_91 ) {
F_24 ( V_2 , L_6 ) ;
return V_97 ;
}
for ( V_49 = 0 ; V_49 < V_91 -> V_94 ; V_49 ++ ) {
if ( V_86 == V_91 -> V_76 [ V_49 ] )
return V_91 -> V_83 [ V_49 ] ;
}
return V_97 ;
}
static int F_41 ( struct V_85 * V_86 , unsigned long * V_98 ,
unsigned long * V_99 )
{
struct V_88 * V_89 = V_86 -> V_89 -> V_90 ;
struct V_1 * V_2 = F_39 ( V_89 , struct V_1 , V_89 ) ;
struct V_24 * V_91 = F_7 ( V_2 ) ;
int V_49 ;
T_1 V_100 , V_101 ;
if ( ! V_91 ) {
F_24 ( V_2 , L_6 ) ;
return - V_102 ;
}
if ( * V_98 > 2550 )
* V_98 = 2550 ;
if ( * V_99 > 2550 )
* V_99 = 2550 ;
if ( ! * V_98 && ! * V_99 )
* V_98 = * V_99 = 500 ;
V_100 = * V_98 / 10 ;
V_101 = * V_99 / 10 ;
for ( V_49 = 0 ; V_49 < V_91 -> V_94 ; V_49 ++ ) {
if ( V_86 == V_91 -> V_76 [ V_49 ] )
break;
}
if ( V_49 >= V_91 -> V_94 )
return - V_102 ;
if ( V_100 != V_91 -> V_95 [ V_49 ] ||
V_101 != V_91 -> V_96 [ V_49 ] ) {
V_91 -> V_95 [ V_49 ] = V_100 ;
V_91 -> V_96 [ V_49 ] = V_101 ;
F_37 ( & V_91 -> V_84 ) ;
}
return 0 ;
}
static void F_42 ( struct V_24 * V_25 )
{
struct V_85 * V_86 ;
int V_49 ;
F_32 ( ! ( V_25 -> V_26 & V_103 ) ) ;
for ( V_49 = 0 ; V_49 < V_25 -> V_94 ; V_49 ++ ) {
V_86 = V_25 -> V_76 [ V_49 ] ;
V_25 -> V_76 [ V_49 ] = NULL ;
if ( ! V_86 )
continue;
F_43 ( V_86 ) ;
F_28 ( V_86 ) ;
}
V_25 -> V_94 = 0 ;
}
static int F_44 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_49 , V_63 = 0 ;
int V_104 ;
struct V_85 * V_86 ;
T_4 V_105 ;
char * V_106 ;
T_4 V_107 ;
const char * V_108 ;
static const char * const V_109 [] = { L_7 , L_8 , L_9 ,
L_10 } ;
T_1 V_110 [ V_73 ] = { 0 } ;
T_1 V_111 [ V_73 ] = { [ 0 ... ( V_73 - 1 ) ] = 1 } ;
T_1 V_112 [ V_73 ] = { 0 } ;
F_32 ( ! ( V_25 -> V_26 & V_103 ) ) ;
if ( V_25 -> V_26 & V_58 ) {
V_25 -> V_94 = 4 ;
V_104 = 0 ;
V_107 = strlen ( L_11 ) ;
V_108 = L_12 ;
if ( ! F_45 ( V_2 , V_80 , 0 , 0 , 7 ) )
return - V_113 ;
} else if ( V_25 -> V_26 & V_64 ) {
F_33 ( V_25 -> V_114 , V_110 ) ;
V_110 [ 3 ] = 1 ;
V_25 -> V_94 = 4 ;
memset ( V_111 , 255 , 3 ) ;
V_112 [ 3 ] = 1 ;
V_104 = 1 ;
V_107 = 0 ;
V_108 = L_13 ;
} else {
F_31 ( V_25 -> V_114 , V_110 ) ;
V_25 -> V_94 = 4 ;
memset ( V_112 , 1 , 4 ) ;
V_104 = 0 ;
V_107 = strlen ( L_14 ) ;
V_108 = L_15 ;
}
F_36 ( V_25 , V_110 , V_25 -> V_94 ) ;
V_105 = strlen ( F_46 ( & V_2 -> V_89 ) ) + V_107 + 1 ;
for ( V_49 = 0 ; V_49 < V_25 -> V_94 ; V_49 ++ ) {
if ( V_104 )
V_105 = strlen ( F_46 ( & V_2 -> V_89 ) ) + strlen ( V_109 [ V_49 ] ) + 2 ;
V_86 = F_47 ( sizeof( struct V_85 ) + V_105 , V_66 ) ;
if ( ! V_86 ) {
F_24 ( V_2 , L_16 , V_49 ) ;
V_63 = - V_67 ;
goto V_115;
}
V_106 = ( void * ) ( & V_86 [ 1 ] ) ;
if ( V_104 )
snprintf ( V_106 , V_105 , V_108 , F_46 ( & V_2 -> V_89 ) ,
V_109 [ V_49 ] ) ;
else
snprintf ( V_106 , V_105 , V_108 , F_46 ( & V_2 -> V_89 ) , V_49 + 1 ) ;
V_86 -> V_106 = V_106 ;
V_86 -> V_116 = V_110 [ V_49 ] ;
V_86 -> V_111 = V_111 [ V_49 ] ;
V_86 -> V_117 = F_40 ;
V_86 -> V_118 = F_38 ;
if ( V_112 [ V_49 ] )
V_86 -> V_119 = F_41 ;
V_25 -> V_76 [ V_49 ] = V_86 ;
V_63 = F_48 ( & V_2 -> V_89 , V_86 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_17 , V_49 ) ;
V_25 -> V_76 [ V_49 ] = NULL ;
F_28 ( V_86 ) ;
goto V_115;
}
}
return V_63 ;
V_115:
F_42 ( V_25 ) ;
return V_63 ;
}
static void F_49 ( struct V_120 * V_121 )
{
struct V_24 * V_25 = F_39 ( V_121 , struct V_24 , V_84 ) ;
int V_49 ;
union V_122 V_57 = {
. V_65 = {
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
#ifdef F_50
V_57 . V_123 . V_124 . V_125 = V_25 -> V_126 ? 1 : 0 ;
V_57 . V_123 . V_124 . V_127 = V_25 -> V_128 ;
#endif
V_57 . V_123 . V_129 |= V_25 -> V_83 [ 0 ] << 1 ;
V_57 . V_123 . V_129 |= V_25 -> V_83 [ 1 ] << 2 ;
V_57 . V_123 . V_129 |= V_25 -> V_83 [ 2 ] << 3 ;
V_57 . V_123 . V_129 |= V_25 -> V_83 [ 3 ] << 4 ;
if ( ( V_57 . V_123 . V_129 & 0x1E ) == 0 )
V_57 . V_123 . V_129 |= 0x20 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
if ( V_25 -> V_95 [ V_49 ] || V_25 -> V_96 [ V_49 ] ) {
V_57 . V_123 . V_86 [ 3 - V_49 ] . V_130 = V_25 -> V_96 [ V_49 ] ;
V_57 . V_123 . V_86 [ 3 - V_49 ] . V_131 = V_25 -> V_95 [ V_49 ] ;
}
}
F_27 ( V_25 -> V_2 , V_57 . V_123 . V_132 , V_57 . V_65 ,
sizeof( V_57 ) , V_80 , V_70 ) ;
}
static void F_51 ( struct V_120 * V_121 )
{
struct V_24 * V_25 = F_39 ( V_121 , struct V_24 , V_84 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
int V_50 ;
T_1 V_65 [ 78 ] = { 0 } ;
if ( V_25 -> V_26 & V_28 ) {
V_65 [ 0 ] = 0x05 ;
V_65 [ 1 ] = 0xFF ;
V_50 = 4 ;
} else {
V_65 [ 0 ] = 0x11 ;
V_65 [ 1 ] = 0xB0 ;
V_65 [ 3 ] = 0x0F ;
V_50 = 6 ;
}
#ifdef F_50
V_65 [ V_50 ++ ] = V_25 -> V_126 ;
V_65 [ V_50 ++ ] = V_25 -> V_128 ;
#else
V_50 += 2 ;
#endif
if ( V_25 -> V_83 [ 3 ] ) {
V_65 [ V_50 ++ ] = V_25 -> V_83 [ 0 ] ;
V_65 [ V_50 ++ ] = V_25 -> V_83 [ 1 ] ;
V_65 [ V_50 ++ ] = V_25 -> V_83 [ 2 ] ;
} else {
V_50 += 3 ;
}
V_65 [ V_50 ++ ] = V_25 -> V_95 [ 3 ] ;
V_65 [ V_50 ++ ] = V_25 -> V_96 [ 3 ] ;
if ( V_25 -> V_26 & V_28 )
F_52 ( V_2 , V_65 , 32 ) ;
else
F_27 ( V_2 , 0x11 , V_65 , 78 ,
V_80 , V_70 ) ;
}
static int F_53 ( struct V_47 * V_89 , void * V_123 ,
struct V_133 * V_134 )
{
struct V_1 * V_16 = F_54 ( V_89 ) ;
struct V_24 * V_25 = F_7 ( V_16 ) ;
if ( V_134 -> type != V_135 )
return 0 ;
V_25 -> V_128 = V_134 -> V_136 . V_124 . V_137 / 256 ;
V_25 -> V_126 = V_134 -> V_136 . V_124 . V_138 / 256 ;
F_37 ( & V_25 -> V_84 ) ;
return 0 ;
}
static int F_55 ( struct V_24 * V_25 )
{
struct V_7 * V_43 = F_13 ( V_25 -> V_2 -> V_44 . V_45 ,
struct V_7 , V_46 ) ;
struct V_47 * V_47 = V_43 -> V_48 ;
F_56 ( V_47 , V_139 , V_135 ) ;
return F_57 ( V_47 , NULL , F_53 ) ;
}
static int F_55 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_58 ( struct V_140 * V_141 ,
enum V_142 V_143 ,
union V_144 * V_145 )
{
struct V_24 * V_25 = F_39 ( V_141 , struct V_24 , V_146 ) ;
unsigned long V_37 ;
int V_63 = 0 ;
T_5 V_40 , V_39 , V_38 ;
F_10 ( & V_25 -> V_42 , V_37 ) ;
V_40 = V_25 -> V_40 ;
V_39 = V_25 -> V_39 ;
V_38 = V_25 -> V_38 ;
F_11 ( & V_25 -> V_42 , V_37 ) ;
switch ( V_143 ) {
case V_147 :
V_145 -> V_148 = 1 ;
break;
case V_149 :
V_145 -> V_148 = V_150 ;
break;
case V_151 :
V_145 -> V_148 = V_39 ;
break;
case V_152 :
if ( V_40 )
V_145 -> V_148 = V_153 ;
else
if ( V_39 == 100 && V_38 )
V_145 -> V_148 = V_154 ;
else
V_145 -> V_148 = V_155 ;
break;
default:
V_63 = - V_102 ;
break;
}
return V_63 ;
}
static int F_59 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_63 ;
V_25 -> V_39 = 100 ;
V_25 -> V_146 . V_156 = V_157 ;
V_25 -> V_146 . V_158 = F_4 ( V_157 ) ;
V_25 -> V_146 . V_159 = F_58 ;
V_25 -> V_146 . type = V_160 ;
V_25 -> V_146 . V_161 = 0 ;
V_25 -> V_146 . V_106 = F_60 ( V_66 , L_18 ,
V_25 -> V_162 ) ;
if ( ! V_25 -> V_146 . V_106 )
return - V_67 ;
V_63 = F_61 ( & V_2 -> V_89 , & V_25 -> V_146 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_19 ) ;
goto V_163;
}
F_62 ( & V_25 -> V_146 , & V_2 -> V_89 ) ;
return 0 ;
V_163:
F_28 ( V_25 -> V_146 . V_106 ) ;
V_25 -> V_146 . V_106 = NULL ;
return V_63 ;
}
static void F_63 ( struct V_24 * V_25 )
{
if ( ! V_25 -> V_146 . V_106 )
return;
F_64 ( & V_25 -> V_146 ) ;
F_28 ( V_25 -> V_146 . V_106 ) ;
V_25 -> V_146 . V_106 = NULL ;
}
static int F_65 ( struct V_24 * V_25 )
{
struct V_24 * V_164 ;
unsigned long V_37 ;
int V_63 ;
F_10 ( & V_165 , V_37 ) ;
F_66 (entry, &sony_device_list, list_node) {
V_63 = memcmp ( V_25 -> V_162 , V_164 -> V_162 ,
sizeof( V_25 -> V_162 ) ) ;
if ( ! V_63 ) {
V_63 = - V_166 ;
F_8 ( V_25 -> V_2 , L_20 ,
V_25 -> V_162 ) ;
goto V_167;
}
}
V_63 = 0 ;
F_67 ( & ( V_25 -> V_168 ) , & V_169 ) ;
V_167:
F_11 ( & V_165 , V_37 ) ;
return V_63 ;
}
static void F_68 ( struct V_24 * V_25 )
{
unsigned long V_37 ;
if ( V_25 -> V_168 . V_45 ) {
F_10 ( & V_165 , V_37 ) ;
F_69 ( & ( V_25 -> V_168 ) ) ;
F_11 ( & V_165 , V_37 ) ;
}
}
static int F_70 ( struct V_24 * V_25 )
{
int V_63 ;
V_63 = strlen ( V_25 -> V_2 -> V_170 ) ;
if ( V_63 != 17 )
return - V_102 ;
V_63 = sscanf ( V_25 -> V_2 -> V_170 ,
L_21 ,
& V_25 -> V_162 [ 5 ] , & V_25 -> V_162 [ 4 ] , & V_25 -> V_162 [ 3 ] ,
& V_25 -> V_162 [ 2 ] , & V_25 -> V_162 [ 1 ] , & V_25 -> V_162 [ 0 ] ) ;
if ( V_63 != 6 )
return - V_102 ;
return 0 ;
}
static int F_71 ( struct V_24 * V_25 )
{
int V_49 , V_63 ;
if ( ( V_25 -> V_26 & V_30 ) ||
( V_25 -> V_26 & V_171 ) ) {
if ( F_70 ( V_25 ) < 0 ) {
F_72 ( V_25 -> V_2 , L_22 ) ;
return 0 ;
}
} else if ( V_25 -> V_26 & V_28 ) {
T_1 V_65 [ 7 ] ;
V_63 = F_27 ( V_25 -> V_2 , 0x81 , V_65 , sizeof( V_65 ) ,
V_68 , V_69 ) ;
if ( V_63 != 7 ) {
F_24 ( V_25 -> V_2 , L_23 ) ;
return V_63 < 0 ? V_63 : - V_102 ;
}
memcpy ( V_25 -> V_162 , & V_65 [ 1 ] , sizeof( V_25 -> V_162 ) ) ;
} else if ( V_25 -> V_26 & V_93 ) {
T_1 V_65 [ 18 ] ;
V_63 = F_27 ( V_25 -> V_2 , 0xf2 , V_65 , sizeof( V_65 ) ,
V_68 , V_69 ) ;
if ( V_63 != 18 ) {
F_24 ( V_25 -> V_2 , L_24 ) ;
return V_63 < 0 ? V_63 : - V_102 ;
}
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ )
V_25 -> V_162 [ 5 - V_49 ] = V_65 [ 4 + V_49 ] ;
} else {
return 0 ;
}
return F_65 ( V_25 ) ;
}
static int F_73 ( struct V_24 * V_25 )
{
int V_63 ;
if ( ( V_25 -> V_26 & V_32 ) ||
( V_25 -> V_26 & V_64 ) ) {
V_63 = F_74 ( & V_172 , 0 , 0 ,
V_66 ) ;
if ( V_63 < 0 ) {
V_25 -> V_114 = - 1 ;
return V_63 ;
}
V_25 -> V_114 = V_63 ;
} else {
V_25 -> V_114 = - 1 ;
}
return 0 ;
}
static void F_75 ( struct V_24 * V_25 )
{
if ( V_25 -> V_114 >= 0 ) {
F_76 ( & V_172 , V_25 -> V_114 ) ;
V_25 -> V_114 = - 1 ;
}
}
static inline void F_77 ( struct V_24 * V_25 ,
void (* F_78)( struct V_120 * ) )
{
if ( ! V_25 -> V_173 )
F_79 ( & V_25 -> V_84 , F_78 ) ;
V_25 -> V_173 = 1 ;
}
static inline void F_80 ( struct V_24 * V_25 )
{
if ( V_25 -> V_173 )
F_81 ( & V_25 -> V_84 ) ;
}
static int F_82 ( struct V_1 * V_2 , const struct V_174 * V_71 )
{
int V_63 ;
unsigned long V_26 = V_71 -> V_175 ;
struct V_24 * V_25 ;
unsigned int V_176 = V_177 ;
V_25 = F_83 ( & V_2 -> V_89 , sizeof( * V_25 ) , V_66 ) ;
if ( V_25 == NULL ) {
F_24 ( V_2 , L_25 ) ;
return - V_67 ;
}
V_25 -> V_26 = V_26 ;
F_84 ( V_2 , V_25 ) ;
V_25 -> V_2 = V_2 ;
V_63 = F_85 ( V_2 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_26 ) ;
return V_63 ;
}
if ( V_25 -> V_26 & V_27 )
V_176 |= V_178 ;
else if ( V_25 -> V_26 & V_32 )
V_176 |= V_178 ;
V_63 = F_86 ( V_2 , V_176 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_27 ) ;
return V_63 ;
}
V_63 = F_73 ( V_25 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_28 ) ;
goto V_179;
}
if ( V_25 -> V_26 & V_93 ) {
V_2 -> V_26 |= V_180 ;
V_2 -> V_26 |= V_181 ;
V_63 = F_25 ( V_2 ) ;
F_77 ( V_25 , F_49 ) ;
} else if ( V_25 -> V_26 & V_171 ) {
V_2 -> V_26 |= V_180 ;
V_63 = F_29 ( V_2 ) ;
F_77 ( V_25 , F_49 ) ;
} else if ( V_25 -> V_26 & V_64 ) {
if ( V_25 -> V_26 & V_30 ) {
V_2 -> V_26 |= V_180 ;
V_63 = F_30 ( V_2 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_29 ) ;
goto V_179;
}
}
F_77 ( V_25 , F_51 ) ;
} else {
V_63 = 0 ;
}
if ( V_63 < 0 )
goto V_179;
V_63 = F_71 ( V_25 ) ;
if ( V_63 < 0 )
goto V_179;
if ( V_25 -> V_26 & V_103 ) {
V_63 = F_44 ( V_25 ) ;
if ( V_63 < 0 )
goto V_179;
}
if ( V_25 -> V_26 & V_182 ) {
V_63 = F_59 ( V_25 ) ;
if ( V_63 < 0 )
goto V_179;
V_63 = F_87 ( V_2 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_30 ) ;
goto V_179;
}
}
if ( V_25 -> V_26 & V_183 ) {
V_63 = F_55 ( V_25 ) ;
if ( V_63 < 0 )
goto V_184;
}
return 0 ;
V_184:
F_88 ( V_2 ) ;
V_179:
if ( V_25 -> V_26 & V_103 )
F_42 ( V_25 ) ;
if ( V_25 -> V_26 & V_182 )
F_63 ( V_25 ) ;
F_80 ( V_25 ) ;
F_68 ( V_25 ) ;
F_75 ( V_25 ) ;
F_89 ( V_2 ) ;
return V_63 ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_7 ( V_2 ) ;
if ( V_25 -> V_26 & V_103 )
F_42 ( V_25 ) ;
if ( V_25 -> V_26 & V_182 ) {
F_88 ( V_2 ) ;
F_63 ( V_25 ) ;
}
F_80 ( V_25 ) ;
F_68 ( V_25 ) ;
F_75 ( V_25 ) ;
F_89 ( V_2 ) ;
}
static int T_6 F_91 ( void )
{
F_92 ( L_31 , V_185 ) ;
return F_93 ( & V_186 ) ;
}
static void T_7 F_94 ( void )
{
F_92 ( L_31 , V_185 ) ;
F_95 ( & V_172 ) ;
F_96 ( & V_186 ) ;
}
