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
const int V_65 =
V_14 ( V_66 , V_67 ) ;
T_1 * V_68 ;
int V_63 ;
V_68 = F_26 ( V_65 , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
V_63 = F_27 ( V_2 , 0xf2 , V_68 , V_66 ,
V_71 , V_72 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_5 ) ;
goto V_73;
}
V_63 = F_27 ( V_2 , 0xf5 , V_68 , V_67 ,
V_71 , V_72 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_6 ) ;
goto V_73;
}
V_63 = F_28 ( V_2 , V_68 , 1 ) ;
if ( V_63 < 0 )
F_24 ( V_2 , L_7 ) ;
V_73:
F_29 ( V_68 ) ;
return V_63 ;
}
static int F_30 ( struct V_1 * V_2 )
{
static const T_1 V_57 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
T_1 * V_68 ;
int V_63 ;
V_68 = F_31 ( V_57 , sizeof( V_57 ) , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
V_63 = F_27 ( V_2 , V_68 [ 0 ] , V_68 , sizeof( V_57 ) ,
V_71 , V_74 ) ;
F_29 ( V_68 ) ;
return V_63 ;
}
static int F_32 ( struct V_1 * V_2 )
{
T_1 * V_68 ;
int V_63 ;
V_68 = F_26 ( V_75 , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
V_63 = F_27 ( V_2 , 0x02 , V_68 , V_75 ,
V_71 , V_72 ) ;
F_29 ( V_68 ) ;
return V_63 ;
}
static void F_33 ( int V_76 , T_1 V_77 [ V_78 ] )
{
static const T_1 V_79 [ 10 ] [ 4 ] = {
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
F_34 ( V_78 < F_4 ( V_79 [ 0 ] ) ) ;
if ( V_76 < 0 )
return;
V_76 %= 10 ;
memcpy ( V_77 , V_79 [ V_76 ] , sizeof( V_79 [ V_76 ] ) ) ;
}
static void F_35 ( int V_76 , T_1 V_77 [ V_78 ] )
{
static const T_1 V_80 [ 7 ] [ 3 ] = {
{ 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 } ,
{ 0x02 , 0x00 , 0x01 } ,
{ 0x02 , 0x01 , 0x00 } ,
{ 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 }
} ;
F_34 ( V_78 < F_4 ( V_80 [ 0 ] ) ) ;
if ( V_76 < 0 )
return;
V_76 %= 7 ;
memcpy ( V_77 , V_80 [ V_76 ] , sizeof( V_80 [ V_76 ] ) ) ;
}
static void F_36 ( struct V_1 * V_2 , const T_1 * V_81 )
{
struct V_82 * V_83 =
& V_2 -> V_84 [ V_85 ] . V_83 ;
struct V_56 * V_57 = F_13 ( V_83 -> V_45 ,
struct V_56 , V_46 ) ;
T_3 * V_86 = V_57 -> V_10 [ 0 ] -> V_86 ;
V_86 [ 0 ] = 0x00 ;
V_86 [ 1 ] = V_81 [ 0 ] ? 0xff : 0x00 ;
V_86 [ 2 ] = V_81 [ 1 ] ? 0xff : 0x00 ;
V_86 [ 3 ] = V_81 [ 2 ] ? 0xff : 0x00 ;
V_86 [ 4 ] = V_81 [ 3 ] ? 0xff : 0x00 ;
V_86 [ 5 ] = 0x00 ;
V_86 [ 6 ] = 0x00 ;
F_37 ( V_2 , V_57 , V_74 ) ;
}
static void F_38 ( struct V_24 * V_25 , const T_1 * V_81 , int V_87 )
{
int V_49 ;
F_34 ( V_87 > V_78 ) ;
if ( V_25 -> V_26 & V_58 && V_87 == 4 ) {
F_36 ( V_25 -> V_2 , V_81 ) ;
} else {
for ( V_49 = 0 ; V_49 < V_87 ; V_49 ++ )
V_25 -> V_88 [ V_49 ] = V_81 [ V_49 ] ;
F_39 ( & V_25 -> V_89 ) ;
}
}
static void F_40 ( struct V_90 * V_91 ,
enum V_92 V_86 )
{
struct V_93 * V_94 = V_91 -> V_94 -> V_95 ;
struct V_1 * V_2 = F_41 ( V_94 , struct V_1 , V_94 ) ;
struct V_24 * V_96 ;
int V_49 ;
int V_97 ;
V_96 = F_7 ( V_2 ) ;
if ( ! V_96 ) {
F_24 ( V_2 , L_8 ) ;
return;
}
V_97 = ! ! ( V_96 -> V_26 & V_98 ) ;
for ( V_49 = 0 ; V_49 < V_96 -> V_99 ; V_49 ++ ) {
if ( V_91 == V_96 -> V_81 [ V_49 ] && ( V_97 ||
( V_86 != V_96 -> V_88 [ V_49 ] ||
V_96 -> V_100 [ V_49 ] ||
V_96 -> V_101 [ V_49 ] ) ) ) {
V_96 -> V_88 [ V_49 ] = V_86 ;
V_96 -> V_100 [ V_49 ] = 0 ;
V_96 -> V_101 [ V_49 ] = 0 ;
F_38 ( V_96 , V_96 -> V_88 ,
V_96 -> V_99 ) ;
break;
}
}
}
static enum V_92 F_42 ( struct V_90 * V_91 )
{
struct V_93 * V_94 = V_91 -> V_94 -> V_95 ;
struct V_1 * V_2 = F_41 ( V_94 , struct V_1 , V_94 ) ;
struct V_24 * V_96 ;
int V_49 ;
V_96 = F_7 ( V_2 ) ;
if ( ! V_96 ) {
F_24 ( V_2 , L_8 ) ;
return V_102 ;
}
for ( V_49 = 0 ; V_49 < V_96 -> V_99 ; V_49 ++ ) {
if ( V_91 == V_96 -> V_81 [ V_49 ] )
return V_96 -> V_88 [ V_49 ] ;
}
return V_102 ;
}
static int F_43 ( struct V_90 * V_91 , unsigned long * V_103 ,
unsigned long * V_104 )
{
struct V_93 * V_94 = V_91 -> V_94 -> V_95 ;
struct V_1 * V_2 = F_41 ( V_94 , struct V_1 , V_94 ) ;
struct V_24 * V_96 = F_7 ( V_2 ) ;
int V_49 ;
T_1 V_105 , V_106 ;
if ( ! V_96 ) {
F_24 ( V_2 , L_8 ) ;
return - V_107 ;
}
if ( * V_103 > 2550 )
* V_103 = 2550 ;
if ( * V_104 > 2550 )
* V_104 = 2550 ;
if ( ! * V_103 && ! * V_104 )
* V_103 = * V_104 = 500 ;
V_105 = * V_103 / 10 ;
V_106 = * V_104 / 10 ;
for ( V_49 = 0 ; V_49 < V_96 -> V_99 ; V_49 ++ ) {
if ( V_91 == V_96 -> V_81 [ V_49 ] )
break;
}
if ( V_49 >= V_96 -> V_99 )
return - V_107 ;
if ( V_105 != V_96 -> V_100 [ V_49 ] ||
V_106 != V_96 -> V_101 [ V_49 ] ) {
V_96 -> V_100 [ V_49 ] = V_105 ;
V_96 -> V_101 [ V_49 ] = V_106 ;
F_39 ( & V_96 -> V_89 ) ;
}
return 0 ;
}
static void F_44 ( struct V_24 * V_25 )
{
struct V_90 * V_91 ;
int V_49 ;
F_34 ( ! ( V_25 -> V_26 & V_108 ) ) ;
for ( V_49 = 0 ; V_49 < V_25 -> V_99 ; V_49 ++ ) {
V_91 = V_25 -> V_81 [ V_49 ] ;
V_25 -> V_81 [ V_49 ] = NULL ;
if ( ! V_91 )
continue;
F_45 ( V_91 ) ;
F_29 ( V_91 ) ;
}
V_25 -> V_99 = 0 ;
}
static int F_46 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_49 , V_63 = 0 ;
int V_109 ;
struct V_90 * V_91 ;
T_4 V_110 ;
char * V_111 ;
T_4 V_112 ;
const char * V_113 ;
static const char * const V_114 [] = { L_9 , L_10 , L_11 ,
L_12 } ;
T_1 V_115 [ V_78 ] = { 0 } ;
T_1 V_116 [ V_78 ] = { [ 0 ... ( V_78 - 1 ) ] = 1 } ;
T_1 V_117 [ V_78 ] = { 0 } ;
F_34 ( ! ( V_25 -> V_26 & V_108 ) ) ;
if ( V_25 -> V_26 & V_58 ) {
V_25 -> V_99 = 4 ;
V_109 = 0 ;
V_112 = strlen ( L_13 ) ;
V_113 = L_14 ;
if ( ! F_47 ( V_2 , V_85 , 0 , 0 , 7 ) )
return - V_118 ;
} else if ( V_25 -> V_26 & V_64 ) {
F_35 ( V_25 -> V_119 , V_115 ) ;
V_115 [ 3 ] = 1 ;
V_25 -> V_99 = 4 ;
memset ( V_116 , 255 , 3 ) ;
V_117 [ 3 ] = 1 ;
V_109 = 1 ;
V_112 = 0 ;
V_113 = L_15 ;
} else {
F_33 ( V_25 -> V_119 , V_115 ) ;
V_25 -> V_99 = 4 ;
memset ( V_117 , 1 , 4 ) ;
V_109 = 0 ;
V_112 = strlen ( L_16 ) ;
V_113 = L_17 ;
}
F_38 ( V_25 , V_115 , V_25 -> V_99 ) ;
V_110 = strlen ( F_48 ( & V_2 -> V_94 ) ) + V_112 + 1 ;
for ( V_49 = 0 ; V_49 < V_25 -> V_99 ; V_49 ++ ) {
if ( V_109 )
V_110 = strlen ( F_48 ( & V_2 -> V_94 ) ) + strlen ( V_114 [ V_49 ] ) + 2 ;
V_91 = F_49 ( sizeof( struct V_90 ) + V_110 , V_69 ) ;
if ( ! V_91 ) {
F_24 ( V_2 , L_18 , V_49 ) ;
V_63 = - V_70 ;
goto V_120;
}
V_111 = ( void * ) ( & V_91 [ 1 ] ) ;
if ( V_109 )
snprintf ( V_111 , V_110 , V_113 , F_48 ( & V_2 -> V_94 ) ,
V_114 [ V_49 ] ) ;
else
snprintf ( V_111 , V_110 , V_113 , F_48 ( & V_2 -> V_94 ) , V_49 + 1 ) ;
V_91 -> V_111 = V_111 ;
V_91 -> V_121 = V_115 [ V_49 ] ;
V_91 -> V_116 = V_116 [ V_49 ] ;
V_91 -> V_122 = F_42 ;
V_91 -> V_123 = F_40 ;
if ( V_117 [ V_49 ] )
V_91 -> V_124 = F_43 ;
V_25 -> V_81 [ V_49 ] = V_91 ;
V_63 = F_50 ( & V_2 -> V_94 , V_91 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_19 , V_49 ) ;
V_25 -> V_81 [ V_49 ] = NULL ;
F_29 ( V_91 ) ;
goto V_120;
}
}
return V_63 ;
V_120:
F_44 ( V_25 ) ;
return V_63 ;
}
static void F_51 ( struct V_125 * V_126 )
{
static const union V_127 V_128 = {
. V_68 = {
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
struct V_24 * V_25 = F_41 ( V_126 , struct V_24 , V_89 ) ;
struct V_129 * V_57 =
(struct V_129 * ) V_25 -> V_130 ;
int V_49 ;
memcpy ( V_57 , & V_128 , sizeof( struct V_129 ) ) ;
#ifdef F_52
V_57 -> V_131 . V_132 = V_25 -> V_133 ? 1 : 0 ;
V_57 -> V_131 . V_134 = V_25 -> V_135 ;
#endif
V_57 -> V_136 |= V_25 -> V_88 [ 0 ] << 1 ;
V_57 -> V_136 |= V_25 -> V_88 [ 1 ] << 2 ;
V_57 -> V_136 |= V_25 -> V_88 [ 2 ] << 3 ;
V_57 -> V_136 |= V_25 -> V_88 [ 3 ] << 4 ;
if ( ( V_57 -> V_136 & 0x1E ) == 0 )
V_57 -> V_136 |= 0x20 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
if ( V_25 -> V_100 [ V_49 ] || V_25 -> V_101 [ V_49 ] ) {
V_57 -> V_91 [ 3 - V_49 ] . V_137 = V_25 -> V_101 [ V_49 ] ;
V_57 -> V_91 [ 3 - V_49 ] . V_138 = V_25 -> V_100 [ V_49 ] ;
}
}
F_27 ( V_25 -> V_2 , V_57 -> V_139 , ( T_1 * ) V_57 ,
sizeof( struct V_129 ) ,
V_85 , V_74 ) ;
}
static void F_53 ( struct V_125 * V_126 )
{
struct V_24 * V_25 = F_41 ( V_126 , struct V_24 , V_89 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
T_1 * V_68 = V_25 -> V_130 ;
int V_50 ;
if ( V_25 -> V_26 & V_28 ) {
memset ( V_68 , 0 , V_140 ) ;
V_68 [ 0 ] = 0x05 ;
V_68 [ 1 ] = 0xFF ;
V_50 = 4 ;
} else {
memset ( V_68 , 0 , V_141 ) ;
V_68 [ 0 ] = 0x11 ;
V_68 [ 1 ] = 0xB0 ;
V_68 [ 3 ] = 0x0F ;
V_50 = 6 ;
}
#ifdef F_52
V_68 [ V_50 ++ ] = V_25 -> V_133 ;
V_68 [ V_50 ++ ] = V_25 -> V_135 ;
#else
V_50 += 2 ;
#endif
if ( V_25 -> V_88 [ 3 ] ) {
V_68 [ V_50 ++ ] = V_25 -> V_88 [ 0 ] ;
V_68 [ V_50 ++ ] = V_25 -> V_88 [ 1 ] ;
V_68 [ V_50 ++ ] = V_25 -> V_88 [ 2 ] ;
} else {
V_50 += 3 ;
}
V_68 [ V_50 ++ ] = V_25 -> V_100 [ 3 ] ;
V_68 [ V_50 ++ ] = V_25 -> V_101 [ 3 ] ;
if ( V_25 -> V_26 & V_28 )
F_28 ( V_2 , V_68 , V_140 ) ;
else
F_27 ( V_2 , 0x11 , V_68 , V_141 ,
V_85 , V_74 ) ;
}
static int F_54 ( struct V_24 * V_25 )
{
if ( V_25 -> V_26 & V_32 )
V_25 -> V_130 =
F_26 ( sizeof( union V_127 ) ,
V_69 ) ;
else if ( V_25 -> V_26 & V_30 )
V_25 -> V_130 = F_26 ( V_141 ,
V_69 ) ;
else if ( V_25 -> V_26 & V_28 )
V_25 -> V_130 = F_26 ( V_140 ,
V_69 ) ;
else
return 0 ;
if ( ! V_25 -> V_130 )
return - V_70 ;
return 0 ;
}
static int F_55 ( struct V_47 * V_94 , void * V_142 ,
struct V_143 * V_144 )
{
struct V_1 * V_16 = F_56 ( V_94 ) ;
struct V_24 * V_25 = F_7 ( V_16 ) ;
if ( V_144 -> type != V_145 )
return 0 ;
V_25 -> V_135 = V_144 -> V_146 . V_131 . V_147 / 256 ;
V_25 -> V_133 = V_144 -> V_146 . V_131 . V_148 / 256 ;
F_39 ( & V_25 -> V_89 ) ;
return 0 ;
}
static int F_57 ( struct V_24 * V_25 )
{
struct V_7 * V_43 = F_13 ( V_25 -> V_2 -> V_44 . V_45 ,
struct V_7 , V_46 ) ;
struct V_47 * V_47 = V_43 -> V_48 ;
F_58 ( V_47 , V_149 , V_145 ) ;
return F_59 ( V_47 , NULL , F_55 ) ;
}
static int F_57 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_60 ( struct V_150 * V_151 ,
enum V_152 V_153 ,
union V_154 * V_155 )
{
struct V_24 * V_25 = F_61 ( V_151 ) ;
unsigned long V_37 ;
int V_63 = 0 ;
T_5 V_40 , V_39 , V_38 ;
F_10 ( & V_25 -> V_42 , V_37 ) ;
V_40 = V_25 -> V_40 ;
V_39 = V_25 -> V_39 ;
V_38 = V_25 -> V_38 ;
F_11 ( & V_25 -> V_42 , V_37 ) ;
switch ( V_153 ) {
case V_156 :
V_155 -> V_157 = 1 ;
break;
case V_158 :
V_155 -> V_157 = V_159 ;
break;
case V_160 :
V_155 -> V_157 = V_39 ;
break;
case V_161 :
if ( V_40 )
V_155 -> V_157 = V_162 ;
else
if ( V_39 == 100 && V_38 )
V_155 -> V_157 = V_163 ;
else
V_155 -> V_157 = V_164 ;
break;
default:
V_63 = - V_107 ;
break;
}
return V_63 ;
}
static int F_62 ( struct V_24 * V_25 )
{
struct V_165 V_166 = { . V_96 = V_25 , } ;
struct V_1 * V_2 = V_25 -> V_2 ;
int V_63 ;
V_25 -> V_39 = 100 ;
V_25 -> V_167 . V_168 = V_169 ;
V_25 -> V_167 . V_170 = F_4 ( V_169 ) ;
V_25 -> V_167 . V_171 = F_60 ;
V_25 -> V_167 . type = V_172 ;
V_25 -> V_167 . V_173 = 0 ;
V_25 -> V_167 . V_111 = F_63 ( V_69 ,
L_20 ,
V_25 -> V_174 ) ;
if ( ! V_25 -> V_167 . V_111 )
return - V_70 ;
V_25 -> V_175 = F_64 ( & V_2 -> V_94 , & V_25 -> V_167 ,
& V_166 ) ;
if ( F_65 ( V_25 -> V_175 ) ) {
V_63 = F_66 ( V_25 -> V_175 ) ;
F_24 ( V_2 , L_21 ) ;
goto V_176;
}
F_67 ( V_25 -> V_175 , & V_2 -> V_94 ) ;
return 0 ;
V_176:
F_29 ( V_25 -> V_167 . V_111 ) ;
V_25 -> V_167 . V_111 = NULL ;
return V_63 ;
}
static void F_68 ( struct V_24 * V_25 )
{
if ( ! V_25 -> V_167 . V_111 )
return;
F_69 ( V_25 -> V_175 ) ;
F_29 ( V_25 -> V_167 . V_111 ) ;
V_25 -> V_167 . V_111 = NULL ;
}
static int F_70 ( struct V_24 * V_25 )
{
struct V_24 * V_177 ;
unsigned long V_37 ;
int V_63 ;
F_10 ( & V_178 , V_37 ) ;
F_71 (entry, &sony_device_list, list_node) {
V_63 = memcmp ( V_25 -> V_174 , V_177 -> V_174 ,
sizeof( V_25 -> V_174 ) ) ;
if ( ! V_63 ) {
V_63 = - V_179 ;
F_8 ( V_25 -> V_2 , L_22 ,
V_25 -> V_174 ) ;
goto V_180;
}
}
V_63 = 0 ;
F_72 ( & ( V_25 -> V_181 ) , & V_182 ) ;
V_180:
F_11 ( & V_178 , V_37 ) ;
return V_63 ;
}
static void F_73 ( struct V_24 * V_25 )
{
unsigned long V_37 ;
if ( V_25 -> V_181 . V_45 ) {
F_10 ( & V_178 , V_37 ) ;
F_74 ( & ( V_25 -> V_181 ) ) ;
F_11 ( & V_178 , V_37 ) ;
}
}
static int F_75 ( struct V_24 * V_25 )
{
int V_63 ;
V_63 = strlen ( V_25 -> V_2 -> V_183 ) ;
if ( V_63 != 17 )
return - V_107 ;
V_63 = sscanf ( V_25 -> V_2 -> V_183 ,
L_23 ,
& V_25 -> V_174 [ 5 ] , & V_25 -> V_174 [ 4 ] , & V_25 -> V_174 [ 3 ] ,
& V_25 -> V_174 [ 2 ] , & V_25 -> V_174 [ 1 ] , & V_25 -> V_174 [ 0 ] ) ;
if ( V_63 != 6 )
return - V_107 ;
return 0 ;
}
static int F_76 ( struct V_24 * V_25 )
{
T_1 * V_68 = NULL ;
int V_49 , V_63 ;
if ( ( V_25 -> V_26 & V_30 ) ||
( V_25 -> V_26 & V_184 ) ) {
if ( F_75 ( V_25 ) < 0 ) {
F_77 ( V_25 -> V_2 , L_24 ) ;
return 0 ;
}
} else if ( V_25 -> V_26 & V_28 ) {
V_68 = F_26 ( V_185 , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
V_63 = F_27 ( V_25 -> V_2 , 0x81 , V_68 ,
V_185 , V_71 ,
V_72 ) ;
if ( V_63 != V_185 ) {
F_24 ( V_25 -> V_2 , L_25 ) ;
V_63 = V_63 < 0 ? V_63 : - V_107 ;
goto V_186;
}
memcpy ( V_25 -> V_174 , & V_68 [ 1 ] , sizeof( V_25 -> V_174 ) ) ;
} else if ( V_25 -> V_26 & V_98 ) {
V_68 = F_26 ( V_66 , V_69 ) ;
if ( ! V_68 )
return - V_70 ;
V_63 = F_27 ( V_25 -> V_2 , 0xf2 , V_68 ,
V_66 , V_71 ,
V_72 ) ;
if ( V_63 != V_66 ) {
F_24 ( V_25 -> V_2 , L_26 ) ;
V_63 = V_63 < 0 ? V_63 : - V_107 ;
goto V_186;
}
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ )
V_25 -> V_174 [ 5 - V_49 ] = V_68 [ 4 + V_49 ] ;
} else {
return 0 ;
}
V_63 = F_70 ( V_25 ) ;
V_186:
F_29 ( V_68 ) ;
return V_63 ;
}
static int F_78 ( struct V_24 * V_25 )
{
int V_63 ;
if ( ( V_25 -> V_26 & V_32 ) ||
( V_25 -> V_26 & V_64 ) ) {
V_63 = F_79 ( & V_187 , 0 , 0 ,
V_69 ) ;
if ( V_63 < 0 ) {
V_25 -> V_119 = - 1 ;
return V_63 ;
}
V_25 -> V_119 = V_63 ;
} else {
V_25 -> V_119 = - 1 ;
}
return 0 ;
}
static void F_80 ( struct V_24 * V_25 )
{
if ( V_25 -> V_119 >= 0 ) {
F_81 ( & V_187 , V_25 -> V_119 ) ;
V_25 -> V_119 = - 1 ;
}
}
static inline void F_82 ( struct V_24 * V_25 ,
void (* F_83)( struct V_125 * ) )
{
if ( ! V_25 -> V_188 )
F_84 ( & V_25 -> V_89 , F_83 ) ;
V_25 -> V_188 = 1 ;
}
static inline void F_85 ( struct V_24 * V_25 )
{
if ( V_25 -> V_188 )
F_86 ( & V_25 -> V_89 ) ;
}
static int F_87 ( struct V_1 * V_2 , const struct V_189 * V_76 )
{
int V_63 ;
unsigned long V_26 = V_76 -> V_190 ;
struct V_24 * V_25 ;
unsigned int V_191 = V_192 ;
V_25 = F_88 ( & V_2 -> V_94 , sizeof( * V_25 ) , V_69 ) ;
if ( V_25 == NULL ) {
F_24 ( V_2 , L_27 ) ;
return - V_70 ;
}
F_89 ( & V_25 -> V_42 ) ;
V_25 -> V_26 = V_26 ;
F_90 ( V_2 , V_25 ) ;
V_25 -> V_2 = V_2 ;
V_63 = F_91 ( V_2 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_28 ) ;
return V_63 ;
}
if ( V_25 -> V_26 & V_27 )
V_191 |= V_193 ;
else if ( V_25 -> V_26 & V_32 )
V_191 |= V_193 ;
V_63 = F_92 ( V_2 , V_191 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_29 ) ;
return V_63 ;
}
V_63 = F_54 ( V_25 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_30 ) ;
goto V_194;
}
V_63 = F_78 ( V_25 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_31 ) ;
goto V_194;
}
if ( V_25 -> V_26 & V_98 ) {
V_2 -> V_26 |= V_195 ;
V_2 -> V_26 |= V_196 ;
V_63 = F_25 ( V_2 ) ;
F_82 ( V_25 , F_51 ) ;
} else if ( V_25 -> V_26 & V_184 ) {
V_2 -> V_26 |= V_195 ;
V_63 = F_30 ( V_2 ) ;
F_82 ( V_25 , F_51 ) ;
} else if ( V_25 -> V_26 & V_64 ) {
if ( V_25 -> V_26 & V_30 ) {
V_2 -> V_26 |= V_195 ;
V_63 = F_32 ( V_2 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_32 ) ;
goto V_194;
}
}
F_82 ( V_25 , F_53 ) ;
} else {
V_63 = 0 ;
}
if ( V_63 < 0 )
goto V_194;
V_63 = F_76 ( V_25 ) ;
if ( V_63 < 0 )
goto V_194;
if ( V_25 -> V_26 & V_108 ) {
V_63 = F_46 ( V_25 ) ;
if ( V_63 < 0 )
goto V_194;
}
if ( V_25 -> V_26 & V_197 ) {
V_63 = F_62 ( V_25 ) ;
if ( V_63 < 0 )
goto V_194;
V_63 = F_93 ( V_2 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_33 ) ;
goto V_194;
}
}
if ( V_25 -> V_26 & V_198 ) {
V_63 = F_57 ( V_25 ) ;
if ( V_63 < 0 )
goto V_199;
}
return 0 ;
V_199:
F_94 ( V_2 ) ;
V_194:
if ( V_25 -> V_26 & V_108 )
F_44 ( V_25 ) ;
if ( V_25 -> V_26 & V_197 )
F_68 ( V_25 ) ;
F_85 ( V_25 ) ;
F_29 ( V_25 -> V_130 ) ;
F_73 ( V_25 ) ;
F_80 ( V_25 ) ;
F_95 ( V_2 ) ;
return V_63 ;
}
static void F_96 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_7 ( V_2 ) ;
if ( V_25 -> V_26 & V_108 )
F_44 ( V_25 ) ;
if ( V_25 -> V_26 & V_197 ) {
F_94 ( V_2 ) ;
F_68 ( V_25 ) ;
}
F_85 ( V_25 ) ;
F_29 ( V_25 -> V_130 ) ;
F_73 ( V_25 ) ;
F_80 ( V_25 ) ;
F_95 ( V_2 ) ;
}
static int T_6 F_97 ( void )
{
F_98 ( L_34 , V_200 ) ;
return F_99 ( & V_201 ) ;
}
static void T_7 F_100 ( void )
{
F_98 ( L_34 , V_200 ) ;
F_101 ( & V_201 ) ;
F_102 ( & V_187 ) ;
}
