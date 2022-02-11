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
} else {
T_1 V_41 = V_34 [ 30 ] <= 5 ? V_34 [ 30 ] : 5 ;
V_39 = V_36 [ V_41 ] ;
V_40 = 0 ;
}
V_38 = ! ( V_34 [ 31 ] & 0x04 ) ;
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
static int F_20 ( struct V_1 * V_2 )
{
int V_60 ;
char * V_61 = F_21 ( 18 , V_62 ) ;
if ( ! V_61 )
return - V_63 ;
V_60 = F_22 ( V_2 , 0xf2 , V_61 , 17 , V_64 ,
V_65 ) ;
if ( V_60 < 0 )
F_23 ( V_2 , L_4 ) ;
F_24 ( V_61 ) ;
return V_60 ;
}
static int F_25 ( struct V_1 * V_2 )
{
unsigned char V_61 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
return F_22 ( V_2 , V_61 [ 0 ] , V_61 , sizeof( V_61 ) ,
V_64 , V_66 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
T_1 V_61 [ 37 ] = { 0 } ;
return F_22 ( V_2 , 0x02 , V_61 , sizeof( V_61 ) ,
V_64 , V_65 ) ;
}
static void F_27 ( int V_67 , T_1 V_68 [ V_69 ] )
{
static const T_1 V_70 [ 10 ] [ 4 ] = {
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
F_28 ( V_69 < F_4 ( V_70 [ 0 ] ) ) ;
if ( V_67 < 0 )
return;
V_67 %= 10 ;
memcpy ( V_68 , V_70 [ V_67 ] , sizeof( V_70 [ V_67 ] ) ) ;
}
static void F_29 ( int V_67 , T_1 V_68 [ V_69 ] )
{
static const T_1 V_71 [ 7 ] [ 3 ] = {
{ 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 } ,
{ 0x02 , 0x00 , 0x01 } ,
{ 0x02 , 0x01 , 0x00 } ,
{ 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 }
} ;
F_28 ( V_69 < F_4 ( V_71 [ 0 ] ) ) ;
if ( V_67 < 0 )
return;
V_67 %= 7 ;
memcpy ( V_68 , V_71 [ V_67 ] , sizeof( V_71 [ V_67 ] ) ) ;
}
static void F_30 ( struct V_1 * V_2 , const T_1 * V_72 )
{
struct V_73 * V_74 =
& V_2 -> V_75 [ V_76 ] . V_74 ;
struct V_56 * V_57 = F_13 ( V_74 -> V_45 ,
struct V_56 , V_46 ) ;
T_3 * V_77 = V_57 -> V_10 [ 0 ] -> V_77 ;
V_77 [ 0 ] = 0x00 ;
V_77 [ 1 ] = V_72 [ 0 ] ? 0xff : 0x00 ;
V_77 [ 2 ] = V_72 [ 1 ] ? 0xff : 0x00 ;
V_77 [ 3 ] = V_72 [ 2 ] ? 0xff : 0x00 ;
V_77 [ 4 ] = V_72 [ 3 ] ? 0xff : 0x00 ;
V_77 [ 5 ] = 0x00 ;
V_77 [ 6 ] = 0x00 ;
F_31 ( V_2 , V_57 , V_66 ) ;
}
static void F_32 ( struct V_24 * V_25 , const T_1 * V_72 , int V_78 )
{
int V_49 ;
F_28 ( V_78 > V_69 ) ;
if ( V_25 -> V_26 & V_58 && V_78 == 4 ) {
F_30 ( V_25 -> V_2 , V_72 ) ;
} else {
for ( V_49 = 0 ; V_49 < V_78 ; V_49 ++ )
V_25 -> V_79 [ V_49 ] = V_72 [ V_49 ] ;
F_33 ( & V_25 -> V_80 ) ;
}
}
static void F_34 ( struct V_81 * V_82 ,
enum V_83 V_77 )
{
struct V_84 * V_85 = V_82 -> V_85 -> V_86 ;
struct V_1 * V_2 = F_35 ( V_85 , struct V_1 , V_85 ) ;
struct V_24 * V_87 ;
int V_49 ;
int V_88 ;
V_87 = F_7 ( V_2 ) ;
if ( ! V_87 ) {
F_23 ( V_2 , L_5 ) ;
return;
}
V_88 = ! ! ( V_87 -> V_26 & V_89 ) ;
for ( V_49 = 0 ; V_49 < V_87 -> V_90 ; V_49 ++ ) {
if ( V_82 == V_87 -> V_72 [ V_49 ] && ( V_88 ||
( V_77 != V_87 -> V_79 [ V_49 ] ||
V_87 -> V_91 [ V_49 ] ||
V_87 -> V_92 [ V_49 ] ) ) ) {
V_87 -> V_79 [ V_49 ] = V_77 ;
V_87 -> V_91 [ V_49 ] = 0 ;
V_87 -> V_92 [ V_49 ] = 0 ;
F_32 ( V_87 , V_87 -> V_79 ,
V_87 -> V_90 ) ;
break;
}
}
}
static enum V_83 F_36 ( struct V_81 * V_82 )
{
struct V_84 * V_85 = V_82 -> V_85 -> V_86 ;
struct V_1 * V_2 = F_35 ( V_85 , struct V_1 , V_85 ) ;
struct V_24 * V_87 ;
int V_49 ;
V_87 = F_7 ( V_2 ) ;
if ( ! V_87 ) {
F_23 ( V_2 , L_5 ) ;
return V_93 ;
}
for ( V_49 = 0 ; V_49 < V_87 -> V_90 ; V_49 ++ ) {
if ( V_82 == V_87 -> V_72 [ V_49 ] )
return V_87 -> V_79 [ V_49 ] ;
}
return V_93 ;
}
static int F_37 ( struct V_81 * V_82 , unsigned long * V_94 ,
unsigned long * V_95 )
{
struct V_84 * V_85 = V_82 -> V_85 -> V_86 ;
struct V_1 * V_2 = F_35 ( V_85 , struct V_1 , V_85 ) ;
struct V_24 * V_87 = F_7 ( V_2 ) ;
int V_49 ;
T_1 V_96 , V_97 ;
if ( ! V_87 ) {
F_23 ( V_2 , L_5 ) ;
return - V_98 ;
}
if ( * V_94 > 2550 )
* V_94 = 2550 ;
if ( * V_95 > 2550 )
* V_95 = 2550 ;
if ( ! * V_94 && ! * V_95 )
* V_94 = * V_95 = 500 ;
V_96 = * V_94 / 10 ;
V_97 = * V_95 / 10 ;
for ( V_49 = 0 ; V_49 < V_87 -> V_90 ; V_49 ++ ) {
if ( V_82 == V_87 -> V_72 [ V_49 ] )
break;
}
if ( V_49 >= V_87 -> V_90 )
return - V_98 ;
if ( V_96 != V_87 -> V_91 [ V_49 ] ||
V_97 != V_87 -> V_92 [ V_49 ] ) {
V_87 -> V_91 [ V_49 ] = V_96 ;
V_87 -> V_92 [ V_49 ] = V_97 ;
F_33 ( & V_87 -> V_80 ) ;
}
return 0 ;
}
static void F_38 ( struct V_24 * V_25 )
{
struct V_81 * V_82 ;
int V_49 ;
F_28 ( ! ( V_25 -> V_26 & V_99 ) ) ;
for ( V_49 = 0 ; V_49 < V_25 -> V_90 ; V_49 ++ ) {
V_82 = V_25 -> V_72 [ V_49 ] ;
V_25 -> V_72 [ V_49 ] = NULL ;
if ( ! V_82 )
continue;
F_39 ( V_82 ) ;
F_24 ( V_82 ) ;
}
V_25 -> V_90 = 0 ;
}
static int F_40 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_49 , V_60 = 0 ;
int V_100 ;
struct V_81 * V_82 ;
T_4 V_101 ;
char * V_102 ;
T_4 V_103 ;
const char * V_104 ;
static const char * const V_105 [] = { L_6 , L_7 , L_8 ,
L_9 } ;
T_1 V_106 [ V_69 ] = { 0 } ;
T_1 V_107 [ V_69 ] = { [ 0 ... ( V_69 - 1 ) ] = 1 } ;
T_1 V_108 [ V_69 ] = { 0 } ;
F_28 ( ! ( V_25 -> V_26 & V_99 ) ) ;
if ( V_25 -> V_26 & V_58 ) {
V_25 -> V_90 = 4 ;
V_100 = 0 ;
V_103 = strlen ( L_10 ) ;
V_104 = L_11 ;
if ( ! F_41 ( V_2 , V_76 , 0 , 0 , 7 ) )
return - V_109 ;
} else if ( V_25 -> V_26 & V_110 ) {
F_29 ( V_25 -> V_111 , V_106 ) ;
V_106 [ 3 ] = 1 ;
V_25 -> V_90 = 4 ;
memset ( V_107 , 255 , 3 ) ;
V_108 [ 3 ] = 1 ;
V_100 = 1 ;
V_103 = 0 ;
V_104 = L_12 ;
} else {
F_27 ( V_25 -> V_111 , V_106 ) ;
V_25 -> V_90 = 4 ;
memset ( V_108 , 1 , 4 ) ;
V_100 = 0 ;
V_103 = strlen ( L_13 ) ;
V_104 = L_14 ;
}
F_32 ( V_25 , V_106 , V_25 -> V_90 ) ;
V_101 = strlen ( F_42 ( & V_2 -> V_85 ) ) + V_103 + 1 ;
for ( V_49 = 0 ; V_49 < V_25 -> V_90 ; V_49 ++ ) {
if ( V_100 )
V_101 = strlen ( F_42 ( & V_2 -> V_85 ) ) + strlen ( V_105 [ V_49 ] ) + 2 ;
V_82 = F_43 ( sizeof( struct V_81 ) + V_101 , V_62 ) ;
if ( ! V_82 ) {
F_23 ( V_2 , L_15 , V_49 ) ;
V_60 = - V_63 ;
goto V_112;
}
V_102 = ( void * ) ( & V_82 [ 1 ] ) ;
if ( V_100 )
snprintf ( V_102 , V_101 , V_104 , F_42 ( & V_2 -> V_85 ) ,
V_105 [ V_49 ] ) ;
else
snprintf ( V_102 , V_101 , V_104 , F_42 ( & V_2 -> V_85 ) , V_49 + 1 ) ;
V_82 -> V_102 = V_102 ;
V_82 -> V_113 = V_106 [ V_49 ] ;
V_82 -> V_107 = V_107 [ V_49 ] ;
V_82 -> V_114 = F_36 ;
V_82 -> V_115 = F_34 ;
if ( V_108 [ V_49 ] )
V_82 -> V_116 = F_37 ;
V_25 -> V_72 [ V_49 ] = V_82 ;
V_60 = F_44 ( & V_2 -> V_85 , V_82 ) ;
if ( V_60 ) {
F_23 ( V_2 , L_16 , V_49 ) ;
V_25 -> V_72 [ V_49 ] = NULL ;
F_24 ( V_82 ) ;
goto V_112;
}
}
return V_60 ;
V_112:
F_38 ( V_25 ) ;
return V_60 ;
}
static void F_45 ( struct V_117 * V_118 )
{
struct V_24 * V_25 = F_35 ( V_118 , struct V_24 , V_80 ) ;
int V_49 ;
union V_119 V_57 = {
. V_61 = {
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
#ifdef F_46
V_57 . V_120 . V_121 . V_122 = V_25 -> V_123 ? 1 : 0 ;
V_57 . V_120 . V_121 . V_124 = V_25 -> V_125 ;
#endif
V_57 . V_120 . V_126 |= V_25 -> V_79 [ 0 ] << 1 ;
V_57 . V_120 . V_126 |= V_25 -> V_79 [ 1 ] << 2 ;
V_57 . V_120 . V_126 |= V_25 -> V_79 [ 2 ] << 3 ;
V_57 . V_120 . V_126 |= V_25 -> V_79 [ 3 ] << 4 ;
if ( ( V_57 . V_120 . V_126 & 0x1E ) == 0 )
V_57 . V_120 . V_126 |= 0x20 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
if ( V_25 -> V_91 [ V_49 ] || V_25 -> V_92 [ V_49 ] ) {
V_57 . V_120 . V_82 [ 3 - V_49 ] . V_127 = V_25 -> V_92 [ V_49 ] ;
V_57 . V_120 . V_82 [ 3 - V_49 ] . V_128 = V_25 -> V_91 [ V_49 ] ;
}
}
F_22 ( V_25 -> V_2 , V_57 . V_120 . V_129 , V_57 . V_61 ,
sizeof( V_57 ) , V_76 , V_66 ) ;
}
static void F_47 ( struct V_117 * V_118 )
{
struct V_24 * V_25 = F_35 ( V_118 , struct V_24 , V_80 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
int V_50 ;
T_1 V_61 [ 78 ] = { 0 } ;
if ( V_25 -> V_26 & V_28 ) {
V_61 [ 0 ] = 0x05 ;
V_61 [ 1 ] = 0xFF ;
V_50 = 4 ;
} else {
V_61 [ 0 ] = 0x11 ;
V_61 [ 1 ] = 0xB0 ;
V_61 [ 3 ] = 0x0F ;
V_50 = 6 ;
}
#ifdef F_46
V_61 [ V_50 ++ ] = V_25 -> V_123 ;
V_61 [ V_50 ++ ] = V_25 -> V_125 ;
#else
V_50 += 2 ;
#endif
if ( V_25 -> V_79 [ 3 ] ) {
V_61 [ V_50 ++ ] = V_25 -> V_79 [ 0 ] ;
V_61 [ V_50 ++ ] = V_25 -> V_79 [ 1 ] ;
V_61 [ V_50 ++ ] = V_25 -> V_79 [ 2 ] ;
} else {
V_50 += 3 ;
}
V_61 [ V_50 ++ ] = V_25 -> V_91 [ 3 ] ;
V_61 [ V_50 ++ ] = V_25 -> V_92 [ 3 ] ;
if ( V_25 -> V_26 & V_28 )
F_48 ( V_2 , V_61 , 32 ) ;
else
F_22 ( V_2 , 0x11 , V_61 , 78 ,
V_76 , V_66 ) ;
}
static int F_49 ( struct V_47 * V_85 , void * V_120 ,
struct V_130 * V_131 )
{
struct V_1 * V_16 = F_50 ( V_85 ) ;
struct V_24 * V_25 = F_7 ( V_16 ) ;
if ( V_131 -> type != V_132 )
return 0 ;
V_25 -> V_125 = V_131 -> V_133 . V_121 . V_134 / 256 ;
V_25 -> V_123 = V_131 -> V_133 . V_121 . V_135 / 256 ;
F_33 ( & V_25 -> V_80 ) ;
return 0 ;
}
static int F_51 ( struct V_24 * V_25 )
{
struct V_7 * V_43 = F_13 ( V_25 -> V_2 -> V_44 . V_45 ,
struct V_7 , V_46 ) ;
struct V_47 * V_47 = V_43 -> V_48 ;
F_52 ( V_47 , V_136 , V_132 ) ;
return F_53 ( V_47 , NULL , F_49 ) ;
}
static int F_51 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_54 ( struct V_137 * V_138 ,
enum V_139 V_140 ,
union V_141 * V_142 )
{
struct V_24 * V_25 = F_35 ( V_138 , struct V_24 , V_143 ) ;
unsigned long V_37 ;
int V_60 = 0 ;
T_5 V_40 , V_39 , V_38 ;
F_10 ( & V_25 -> V_42 , V_37 ) ;
V_40 = V_25 -> V_40 ;
V_39 = V_25 -> V_39 ;
V_38 = V_25 -> V_38 ;
F_11 ( & V_25 -> V_42 , V_37 ) ;
switch ( V_140 ) {
case V_144 :
V_142 -> V_145 = 1 ;
break;
case V_146 :
V_142 -> V_145 = V_147 ;
break;
case V_148 :
V_142 -> V_145 = V_39 ;
break;
case V_149 :
if ( V_40 )
V_142 -> V_145 = V_150 ;
else
if ( V_39 == 100 && V_38 )
V_142 -> V_145 = V_151 ;
else
V_142 -> V_145 = V_152 ;
break;
default:
V_60 = - V_98 ;
break;
}
return V_60 ;
}
static int F_55 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_60 ;
V_25 -> V_39 = 100 ;
V_25 -> V_143 . V_153 = V_154 ;
V_25 -> V_143 . V_155 = F_4 ( V_154 ) ;
V_25 -> V_143 . V_156 = F_54 ;
V_25 -> V_143 . type = V_157 ;
V_25 -> V_143 . V_158 = 0 ;
V_25 -> V_143 . V_102 = F_56 ( V_62 , L_17 ,
V_25 -> V_159 ) ;
if ( ! V_25 -> V_143 . V_102 )
return - V_63 ;
V_60 = F_57 ( & V_2 -> V_85 , & V_25 -> V_143 ) ;
if ( V_60 ) {
F_23 ( V_2 , L_18 ) ;
goto V_160;
}
F_58 ( & V_25 -> V_143 , & V_2 -> V_85 ) ;
return 0 ;
V_160:
F_24 ( V_25 -> V_143 . V_102 ) ;
V_25 -> V_143 . V_102 = NULL ;
return V_60 ;
}
static void F_59 ( struct V_24 * V_25 )
{
if ( ! V_25 -> V_143 . V_102 )
return;
F_60 ( & V_25 -> V_143 ) ;
F_24 ( V_25 -> V_143 . V_102 ) ;
V_25 -> V_143 . V_102 = NULL ;
}
static int F_61 ( struct V_24 * V_25 , int V_161 ,
int V_162 , int V_163 )
{
struct V_7 * V_43 = F_13 ( V_25 -> V_2 -> V_44 . V_45 ,
struct V_7 , V_46 ) ;
struct V_47 * V_47 = V_43 -> V_48 ;
int V_60 ;
V_60 = F_62 ( V_47 , V_161 , 0 ) ;
if ( V_60 < 0 ) {
F_23 ( V_25 -> V_2 , L_19 ) ;
return V_60 ;
}
F_63 ( V_47 , V_54 , 0 , V_162 , 0 , 0 ) ;
F_63 ( V_47 , V_55 , 0 , V_163 , 0 , 0 ) ;
return 0 ;
}
static int F_64 ( struct V_24 * V_25 )
{
struct V_24 * V_164 ;
unsigned long V_37 ;
int V_60 ;
F_10 ( & V_165 , V_37 ) ;
F_65 (entry, &sony_device_list, list_node) {
V_60 = memcmp ( V_25 -> V_159 , V_164 -> V_159 ,
sizeof( V_25 -> V_159 ) ) ;
if ( ! V_60 ) {
V_60 = - V_166 ;
F_8 ( V_25 -> V_2 , L_20 ,
V_25 -> V_159 ) ;
goto V_167;
}
}
V_60 = 0 ;
F_66 ( & ( V_25 -> V_168 ) , & V_169 ) ;
V_167:
F_11 ( & V_165 , V_37 ) ;
return V_60 ;
}
static void F_67 ( struct V_24 * V_25 )
{
unsigned long V_37 ;
if ( V_25 -> V_168 . V_45 ) {
F_10 ( & V_165 , V_37 ) ;
F_68 ( & ( V_25 -> V_168 ) ) ;
F_11 ( & V_165 , V_37 ) ;
}
}
static int F_69 ( struct V_24 * V_25 )
{
int V_60 ;
V_60 = strlen ( V_25 -> V_2 -> V_170 ) ;
if ( V_60 != 17 )
return - V_98 ;
V_60 = sscanf ( V_25 -> V_2 -> V_170 ,
L_21 ,
& V_25 -> V_159 [ 5 ] , & V_25 -> V_159 [ 4 ] , & V_25 -> V_159 [ 3 ] ,
& V_25 -> V_159 [ 2 ] , & V_25 -> V_159 [ 1 ] , & V_25 -> V_159 [ 0 ] ) ;
if ( V_60 != 6 )
return - V_98 ;
return 0 ;
}
static int F_70 ( struct V_24 * V_25 )
{
int V_49 , V_60 ;
if ( ( V_25 -> V_26 & V_30 ) ||
( V_25 -> V_26 & V_171 ) ) {
if ( F_69 ( V_25 ) < 0 ) {
F_71 ( V_25 -> V_2 , L_22 ) ;
return 0 ;
}
} else if ( V_25 -> V_26 & V_28 ) {
T_1 V_61 [ 7 ] ;
V_60 = F_22 ( V_25 -> V_2 , 0x81 , V_61 , sizeof( V_61 ) ,
V_64 , V_65 ) ;
if ( V_60 != 7 ) {
F_23 ( V_25 -> V_2 , L_23 ) ;
return V_60 < 0 ? V_60 : - V_98 ;
}
memcpy ( V_25 -> V_159 , & V_61 [ 1 ] , sizeof( V_25 -> V_159 ) ) ;
} else if ( V_25 -> V_26 & V_89 ) {
T_1 V_61 [ 18 ] ;
V_60 = F_22 ( V_25 -> V_2 , 0xf2 , V_61 , sizeof( V_61 ) ,
V_64 , V_65 ) ;
if ( V_60 != 18 ) {
F_23 ( V_25 -> V_2 , L_24 ) ;
return V_60 < 0 ? V_60 : - V_98 ;
}
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ )
V_25 -> V_159 [ 5 - V_49 ] = V_61 [ 4 + V_49 ] ;
} else {
return 0 ;
}
return F_64 ( V_25 ) ;
}
static int F_72 ( struct V_24 * V_25 )
{
int V_60 ;
if ( ( V_25 -> V_26 & V_32 ) ||
( V_25 -> V_26 & V_110 ) ) {
V_60 = F_73 ( & V_172 , 0 , 0 ,
V_62 ) ;
if ( V_60 < 0 ) {
V_25 -> V_111 = - 1 ;
return V_60 ;
}
V_25 -> V_111 = V_60 ;
} else {
V_25 -> V_111 = - 1 ;
}
return 0 ;
}
static void F_74 ( struct V_24 * V_25 )
{
if ( V_25 -> V_111 >= 0 ) {
F_75 ( & V_172 , V_25 -> V_111 ) ;
V_25 -> V_111 = - 1 ;
}
}
static inline void F_76 ( struct V_24 * V_25 ,
void (* F_77)( struct V_117 * ) )
{
if ( ! V_25 -> V_173 )
F_78 ( & V_25 -> V_80 , F_77 ) ;
V_25 -> V_173 = 1 ;
}
static inline void F_79 ( struct V_24 * V_25 )
{
if ( V_25 -> V_173 )
F_80 ( & V_25 -> V_80 ) ;
}
static int F_81 ( struct V_1 * V_2 , const struct V_174 * V_67 )
{
int V_60 ;
unsigned long V_26 = V_67 -> V_175 ;
struct V_24 * V_25 ;
unsigned int V_176 = V_177 ;
V_25 = F_82 ( & V_2 -> V_85 , sizeof( * V_25 ) , V_62 ) ;
if ( V_25 == NULL ) {
F_23 ( V_2 , L_25 ) ;
return - V_63 ;
}
V_25 -> V_26 = V_26 ;
F_83 ( V_2 , V_25 ) ;
V_25 -> V_2 = V_2 ;
V_60 = F_84 ( V_2 ) ;
if ( V_60 ) {
F_23 ( V_2 , L_26 ) ;
return V_60 ;
}
if ( V_25 -> V_26 & V_27 )
V_176 |= V_178 ;
else if ( V_25 -> V_26 & V_32 )
V_176 |= V_178 ;
V_60 = F_85 ( V_2 , V_176 ) ;
if ( V_60 ) {
F_23 ( V_2 , L_27 ) ;
return V_60 ;
}
V_60 = F_72 ( V_25 ) ;
if ( V_60 < 0 ) {
F_23 ( V_2 , L_28 ) ;
goto V_179;
}
if ( V_25 -> V_26 & V_89 ) {
V_2 -> V_26 |= V_180 ;
V_2 -> V_26 |= V_181 ;
V_60 = F_20 ( V_2 ) ;
F_76 ( V_25 , F_45 ) ;
} else if ( V_25 -> V_26 & V_171 ) {
V_2 -> V_26 |= V_180 ;
V_60 = F_25 ( V_2 ) ;
F_76 ( V_25 , F_45 ) ;
} else if ( V_25 -> V_26 & V_110 ) {
if ( V_25 -> V_26 & V_30 ) {
V_2 -> V_26 |= V_180 ;
V_60 = F_26 ( V_2 ) ;
if ( V_60 < 0 ) {
F_23 ( V_2 , L_29 ) ;
goto V_179;
}
}
V_60 = F_61 ( V_25 , 2 , 1920 , 940 ) ;
if ( V_60 < 0 )
goto V_179;
F_76 ( V_25 , F_47 ) ;
} else {
V_60 = 0 ;
}
if ( V_60 < 0 )
goto V_179;
V_60 = F_70 ( V_25 ) ;
if ( V_60 < 0 )
goto V_179;
if ( V_25 -> V_26 & V_99 ) {
V_60 = F_40 ( V_25 ) ;
if ( V_60 < 0 )
goto V_179;
}
if ( V_25 -> V_26 & V_182 ) {
V_60 = F_55 ( V_25 ) ;
if ( V_60 < 0 )
goto V_179;
V_60 = F_86 ( V_2 ) ;
if ( V_60 < 0 ) {
F_23 ( V_2 , L_30 ) ;
goto V_179;
}
}
if ( V_25 -> V_26 & V_183 ) {
V_60 = F_51 ( V_25 ) ;
if ( V_60 < 0 )
goto V_184;
}
return 0 ;
V_184:
F_87 ( V_2 ) ;
V_179:
if ( V_25 -> V_26 & V_99 )
F_38 ( V_25 ) ;
if ( V_25 -> V_26 & V_182 )
F_59 ( V_25 ) ;
F_79 ( V_25 ) ;
F_67 ( V_25 ) ;
F_74 ( V_25 ) ;
F_88 ( V_2 ) ;
return V_60 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_7 ( V_2 ) ;
if ( V_25 -> V_26 & V_99 )
F_38 ( V_25 ) ;
if ( V_25 -> V_26 & V_182 ) {
F_87 ( V_2 ) ;
F_59 ( V_25 ) ;
}
F_79 ( V_25 ) ;
F_67 ( V_25 ) ;
F_74 ( V_25 ) ;
F_88 ( V_2 ) ;
}
static int T_6 F_90 ( void )
{
F_91 ( L_31 , V_185 ) ;
return F_92 ( & V_186 ) ;
}
static void T_7 F_93 ( void )
{
F_91 ( L_31 , V_185 ) ;
F_94 ( & V_172 ) ;
F_95 ( & V_186 ) ;
}
