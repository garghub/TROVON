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
static const T_1 V_57 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
T_1 * V_65 ;
int V_63 ;
V_65 = F_30 ( V_57 , sizeof( V_57 ) , V_66 ) ;
if ( ! V_65 )
return - V_67 ;
V_63 = F_27 ( V_2 , V_65 [ 0 ] , V_65 , sizeof( V_57 ) ,
V_68 , V_70 ) ;
F_28 ( V_65 ) ;
return V_63 ;
}
static int F_31 ( struct V_1 * V_2 )
{
T_1 * V_65 ;
int V_63 ;
V_65 = F_26 ( V_71 , V_66 ) ;
if ( ! V_65 )
return - V_67 ;
V_63 = F_27 ( V_2 , 0x02 , V_65 , V_71 ,
V_68 , V_69 ) ;
F_28 ( V_65 ) ;
return V_63 ;
}
static void F_32 ( int V_72 , T_1 V_73 [ V_74 ] )
{
static const T_1 V_75 [ 10 ] [ 4 ] = {
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
F_33 ( V_74 < F_4 ( V_75 [ 0 ] ) ) ;
if ( V_72 < 0 )
return;
V_72 %= 10 ;
memcpy ( V_73 , V_75 [ V_72 ] , sizeof( V_75 [ V_72 ] ) ) ;
}
static void F_34 ( int V_72 , T_1 V_73 [ V_74 ] )
{
static const T_1 V_76 [ 7 ] [ 3 ] = {
{ 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 } ,
{ 0x02 , 0x00 , 0x01 } ,
{ 0x02 , 0x01 , 0x00 } ,
{ 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 }
} ;
F_33 ( V_74 < F_4 ( V_76 [ 0 ] ) ) ;
if ( V_72 < 0 )
return;
V_72 %= 7 ;
memcpy ( V_73 , V_76 [ V_72 ] , sizeof( V_76 [ V_72 ] ) ) ;
}
static void F_35 ( struct V_1 * V_2 , const T_1 * V_77 )
{
struct V_78 * V_79 =
& V_2 -> V_80 [ V_81 ] . V_79 ;
struct V_56 * V_57 = F_13 ( V_79 -> V_45 ,
struct V_56 , V_46 ) ;
T_3 * V_82 = V_57 -> V_10 [ 0 ] -> V_82 ;
V_82 [ 0 ] = 0x00 ;
V_82 [ 1 ] = V_77 [ 0 ] ? 0xff : 0x00 ;
V_82 [ 2 ] = V_77 [ 1 ] ? 0xff : 0x00 ;
V_82 [ 3 ] = V_77 [ 2 ] ? 0xff : 0x00 ;
V_82 [ 4 ] = V_77 [ 3 ] ? 0xff : 0x00 ;
V_82 [ 5 ] = 0x00 ;
V_82 [ 6 ] = 0x00 ;
F_36 ( V_2 , V_57 , V_70 ) ;
}
static void F_37 ( struct V_24 * V_25 , const T_1 * V_77 , int V_83 )
{
int V_49 ;
F_33 ( V_83 > V_74 ) ;
if ( V_25 -> V_26 & V_58 && V_83 == 4 ) {
F_35 ( V_25 -> V_2 , V_77 ) ;
} else {
for ( V_49 = 0 ; V_49 < V_83 ; V_49 ++ )
V_25 -> V_84 [ V_49 ] = V_77 [ V_49 ] ;
F_38 ( & V_25 -> V_85 ) ;
}
}
static void F_39 ( struct V_86 * V_87 ,
enum V_88 V_82 )
{
struct V_89 * V_90 = V_87 -> V_90 -> V_91 ;
struct V_1 * V_2 = F_40 ( V_90 , struct V_1 , V_90 ) ;
struct V_24 * V_92 ;
int V_49 ;
int V_93 ;
V_92 = F_7 ( V_2 ) ;
if ( ! V_92 ) {
F_24 ( V_2 , L_6 ) ;
return;
}
V_93 = ! ! ( V_92 -> V_26 & V_94 ) ;
for ( V_49 = 0 ; V_49 < V_92 -> V_95 ; V_49 ++ ) {
if ( V_87 == V_92 -> V_77 [ V_49 ] && ( V_93 ||
( V_82 != V_92 -> V_84 [ V_49 ] ||
V_92 -> V_96 [ V_49 ] ||
V_92 -> V_97 [ V_49 ] ) ) ) {
V_92 -> V_84 [ V_49 ] = V_82 ;
V_92 -> V_96 [ V_49 ] = 0 ;
V_92 -> V_97 [ V_49 ] = 0 ;
F_37 ( V_92 , V_92 -> V_84 ,
V_92 -> V_95 ) ;
break;
}
}
}
static enum V_88 F_41 ( struct V_86 * V_87 )
{
struct V_89 * V_90 = V_87 -> V_90 -> V_91 ;
struct V_1 * V_2 = F_40 ( V_90 , struct V_1 , V_90 ) ;
struct V_24 * V_92 ;
int V_49 ;
V_92 = F_7 ( V_2 ) ;
if ( ! V_92 ) {
F_24 ( V_2 , L_6 ) ;
return V_98 ;
}
for ( V_49 = 0 ; V_49 < V_92 -> V_95 ; V_49 ++ ) {
if ( V_87 == V_92 -> V_77 [ V_49 ] )
return V_92 -> V_84 [ V_49 ] ;
}
return V_98 ;
}
static int F_42 ( struct V_86 * V_87 , unsigned long * V_99 ,
unsigned long * V_100 )
{
struct V_89 * V_90 = V_87 -> V_90 -> V_91 ;
struct V_1 * V_2 = F_40 ( V_90 , struct V_1 , V_90 ) ;
struct V_24 * V_92 = F_7 ( V_2 ) ;
int V_49 ;
T_1 V_101 , V_102 ;
if ( ! V_92 ) {
F_24 ( V_2 , L_6 ) ;
return - V_103 ;
}
if ( * V_99 > 2550 )
* V_99 = 2550 ;
if ( * V_100 > 2550 )
* V_100 = 2550 ;
if ( ! * V_99 && ! * V_100 )
* V_99 = * V_100 = 500 ;
V_101 = * V_99 / 10 ;
V_102 = * V_100 / 10 ;
for ( V_49 = 0 ; V_49 < V_92 -> V_95 ; V_49 ++ ) {
if ( V_87 == V_92 -> V_77 [ V_49 ] )
break;
}
if ( V_49 >= V_92 -> V_95 )
return - V_103 ;
if ( V_101 != V_92 -> V_96 [ V_49 ] ||
V_102 != V_92 -> V_97 [ V_49 ] ) {
V_92 -> V_96 [ V_49 ] = V_101 ;
V_92 -> V_97 [ V_49 ] = V_102 ;
F_38 ( & V_92 -> V_85 ) ;
}
return 0 ;
}
static void F_43 ( struct V_24 * V_25 )
{
struct V_86 * V_87 ;
int V_49 ;
F_33 ( ! ( V_25 -> V_26 & V_104 ) ) ;
for ( V_49 = 0 ; V_49 < V_25 -> V_95 ; V_49 ++ ) {
V_87 = V_25 -> V_77 [ V_49 ] ;
V_25 -> V_77 [ V_49 ] = NULL ;
if ( ! V_87 )
continue;
F_44 ( V_87 ) ;
F_28 ( V_87 ) ;
}
V_25 -> V_95 = 0 ;
}
static int F_45 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_49 , V_63 = 0 ;
int V_105 ;
struct V_86 * V_87 ;
T_4 V_106 ;
char * V_107 ;
T_4 V_108 ;
const char * V_109 ;
static const char * const V_110 [] = { L_7 , L_8 , L_9 ,
L_10 } ;
T_1 V_111 [ V_74 ] = { 0 } ;
T_1 V_112 [ V_74 ] = { [ 0 ... ( V_74 - 1 ) ] = 1 } ;
T_1 V_113 [ V_74 ] = { 0 } ;
F_33 ( ! ( V_25 -> V_26 & V_104 ) ) ;
if ( V_25 -> V_26 & V_58 ) {
V_25 -> V_95 = 4 ;
V_105 = 0 ;
V_108 = strlen ( L_11 ) ;
V_109 = L_12 ;
if ( ! F_46 ( V_2 , V_81 , 0 , 0 , 7 ) )
return - V_114 ;
} else if ( V_25 -> V_26 & V_64 ) {
F_34 ( V_25 -> V_115 , V_111 ) ;
V_111 [ 3 ] = 1 ;
V_25 -> V_95 = 4 ;
memset ( V_112 , 255 , 3 ) ;
V_113 [ 3 ] = 1 ;
V_105 = 1 ;
V_108 = 0 ;
V_109 = L_13 ;
} else {
F_32 ( V_25 -> V_115 , V_111 ) ;
V_25 -> V_95 = 4 ;
memset ( V_113 , 1 , 4 ) ;
V_105 = 0 ;
V_108 = strlen ( L_14 ) ;
V_109 = L_15 ;
}
F_37 ( V_25 , V_111 , V_25 -> V_95 ) ;
V_106 = strlen ( F_47 ( & V_2 -> V_90 ) ) + V_108 + 1 ;
for ( V_49 = 0 ; V_49 < V_25 -> V_95 ; V_49 ++ ) {
if ( V_105 )
V_106 = strlen ( F_47 ( & V_2 -> V_90 ) ) + strlen ( V_110 [ V_49 ] ) + 2 ;
V_87 = F_48 ( sizeof( struct V_86 ) + V_106 , V_66 ) ;
if ( ! V_87 ) {
F_24 ( V_2 , L_16 , V_49 ) ;
V_63 = - V_67 ;
goto V_116;
}
V_107 = ( void * ) ( & V_87 [ 1 ] ) ;
if ( V_105 )
snprintf ( V_107 , V_106 , V_109 , F_47 ( & V_2 -> V_90 ) ,
V_110 [ V_49 ] ) ;
else
snprintf ( V_107 , V_106 , V_109 , F_47 ( & V_2 -> V_90 ) , V_49 + 1 ) ;
V_87 -> V_107 = V_107 ;
V_87 -> V_117 = V_111 [ V_49 ] ;
V_87 -> V_112 = V_112 [ V_49 ] ;
V_87 -> V_118 = F_41 ;
V_87 -> V_119 = F_39 ;
if ( V_113 [ V_49 ] )
V_87 -> V_120 = F_42 ;
V_25 -> V_77 [ V_49 ] = V_87 ;
V_63 = F_49 ( & V_2 -> V_90 , V_87 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_17 , V_49 ) ;
V_25 -> V_77 [ V_49 ] = NULL ;
F_28 ( V_87 ) ;
goto V_116;
}
}
return V_63 ;
V_116:
F_43 ( V_25 ) ;
return V_63 ;
}
static void F_50 ( struct V_121 * V_122 )
{
static const union V_123 V_124 = {
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
struct V_24 * V_25 = F_40 ( V_122 , struct V_24 , V_85 ) ;
struct V_125 * V_57 =
(struct V_125 * ) V_25 -> V_126 ;
int V_49 ;
memcpy ( V_57 , & V_124 , sizeof( struct V_125 ) ) ;
#ifdef F_51
V_57 -> V_127 . V_128 = V_25 -> V_129 ? 1 : 0 ;
V_57 -> V_127 . V_130 = V_25 -> V_131 ;
#endif
V_57 -> V_132 |= V_25 -> V_84 [ 0 ] << 1 ;
V_57 -> V_132 |= V_25 -> V_84 [ 1 ] << 2 ;
V_57 -> V_132 |= V_25 -> V_84 [ 2 ] << 3 ;
V_57 -> V_132 |= V_25 -> V_84 [ 3 ] << 4 ;
if ( ( V_57 -> V_132 & 0x1E ) == 0 )
V_57 -> V_132 |= 0x20 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
if ( V_25 -> V_96 [ V_49 ] || V_25 -> V_97 [ V_49 ] ) {
V_57 -> V_87 [ 3 - V_49 ] . V_133 = V_25 -> V_97 [ V_49 ] ;
V_57 -> V_87 [ 3 - V_49 ] . V_134 = V_25 -> V_96 [ V_49 ] ;
}
}
F_27 ( V_25 -> V_2 , V_57 -> V_135 , ( T_1 * ) V_57 ,
sizeof( struct V_125 ) ,
V_81 , V_70 ) ;
}
static void F_52 ( struct V_121 * V_122 )
{
struct V_24 * V_25 = F_40 ( V_122 , struct V_24 , V_85 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
T_1 * V_65 = V_25 -> V_126 ;
int V_50 ;
if ( V_25 -> V_26 & V_28 ) {
memset ( V_65 , 0 , V_136 ) ;
V_65 [ 0 ] = 0x05 ;
V_65 [ 1 ] = 0xFF ;
V_50 = 4 ;
} else {
memset ( V_65 , 0 , V_137 ) ;
V_65 [ 0 ] = 0x11 ;
V_65 [ 1 ] = 0xB0 ;
V_65 [ 3 ] = 0x0F ;
V_50 = 6 ;
}
#ifdef F_51
V_65 [ V_50 ++ ] = V_25 -> V_129 ;
V_65 [ V_50 ++ ] = V_25 -> V_131 ;
#else
V_50 += 2 ;
#endif
if ( V_25 -> V_84 [ 3 ] ) {
V_65 [ V_50 ++ ] = V_25 -> V_84 [ 0 ] ;
V_65 [ V_50 ++ ] = V_25 -> V_84 [ 1 ] ;
V_65 [ V_50 ++ ] = V_25 -> V_84 [ 2 ] ;
} else {
V_50 += 3 ;
}
V_65 [ V_50 ++ ] = V_25 -> V_96 [ 3 ] ;
V_65 [ V_50 ++ ] = V_25 -> V_97 [ 3 ] ;
if ( V_25 -> V_26 & V_28 )
F_53 ( V_2 , V_65 , V_136 ) ;
else
F_27 ( V_2 , 0x11 , V_65 , V_137 ,
V_81 , V_70 ) ;
}
static int F_54 ( struct V_24 * V_25 )
{
if ( V_25 -> V_26 & V_32 )
V_25 -> V_126 =
F_26 ( sizeof( union V_123 ) ,
V_66 ) ;
else if ( V_25 -> V_26 & V_30 )
V_25 -> V_126 = F_26 ( V_137 ,
V_66 ) ;
else if ( V_25 -> V_26 & V_28 )
V_25 -> V_126 = F_26 ( V_136 ,
V_66 ) ;
else
return 0 ;
if ( ! V_25 -> V_126 )
return - V_67 ;
return 0 ;
}
static int F_55 ( struct V_47 * V_90 , void * V_138 ,
struct V_139 * V_140 )
{
struct V_1 * V_16 = F_56 ( V_90 ) ;
struct V_24 * V_25 = F_7 ( V_16 ) ;
if ( V_140 -> type != V_141 )
return 0 ;
V_25 -> V_131 = V_140 -> V_142 . V_127 . V_143 / 256 ;
V_25 -> V_129 = V_140 -> V_142 . V_127 . V_144 / 256 ;
F_38 ( & V_25 -> V_85 ) ;
return 0 ;
}
static int F_57 ( struct V_24 * V_25 )
{
struct V_7 * V_43 = F_13 ( V_25 -> V_2 -> V_44 . V_45 ,
struct V_7 , V_46 ) ;
struct V_47 * V_47 = V_43 -> V_48 ;
F_58 ( V_47 , V_145 , V_141 ) ;
return F_59 ( V_47 , NULL , F_55 ) ;
}
static int F_57 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_60 ( struct V_146 * V_147 ,
enum V_148 V_149 ,
union V_150 * V_151 )
{
struct V_24 * V_25 = F_40 ( V_147 , struct V_24 , V_152 ) ;
unsigned long V_37 ;
int V_63 = 0 ;
T_5 V_40 , V_39 , V_38 ;
F_10 ( & V_25 -> V_42 , V_37 ) ;
V_40 = V_25 -> V_40 ;
V_39 = V_25 -> V_39 ;
V_38 = V_25 -> V_38 ;
F_11 ( & V_25 -> V_42 , V_37 ) ;
switch ( V_149 ) {
case V_153 :
V_151 -> V_154 = 1 ;
break;
case V_155 :
V_151 -> V_154 = V_156 ;
break;
case V_157 :
V_151 -> V_154 = V_39 ;
break;
case V_158 :
if ( V_40 )
V_151 -> V_154 = V_159 ;
else
if ( V_39 == 100 && V_38 )
V_151 -> V_154 = V_160 ;
else
V_151 -> V_154 = V_161 ;
break;
default:
V_63 = - V_103 ;
break;
}
return V_63 ;
}
static int F_61 ( struct V_24 * V_25 )
{
struct V_1 * V_2 = V_25 -> V_2 ;
int V_63 ;
V_25 -> V_39 = 100 ;
V_25 -> V_152 . V_162 = V_163 ;
V_25 -> V_152 . V_164 = F_4 ( V_163 ) ;
V_25 -> V_152 . V_165 = F_60 ;
V_25 -> V_152 . type = V_166 ;
V_25 -> V_152 . V_167 = 0 ;
V_25 -> V_152 . V_107 = F_62 ( V_66 , L_18 ,
V_25 -> V_168 ) ;
if ( ! V_25 -> V_152 . V_107 )
return - V_67 ;
V_63 = F_63 ( & V_2 -> V_90 , & V_25 -> V_152 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_19 ) ;
goto V_169;
}
F_64 ( & V_25 -> V_152 , & V_2 -> V_90 ) ;
return 0 ;
V_169:
F_28 ( V_25 -> V_152 . V_107 ) ;
V_25 -> V_152 . V_107 = NULL ;
return V_63 ;
}
static void F_65 ( struct V_24 * V_25 )
{
if ( ! V_25 -> V_152 . V_107 )
return;
F_66 ( & V_25 -> V_152 ) ;
F_28 ( V_25 -> V_152 . V_107 ) ;
V_25 -> V_152 . V_107 = NULL ;
}
static int F_67 ( struct V_24 * V_25 )
{
struct V_24 * V_170 ;
unsigned long V_37 ;
int V_63 ;
F_10 ( & V_171 , V_37 ) ;
F_68 (entry, &sony_device_list, list_node) {
V_63 = memcmp ( V_25 -> V_168 , V_170 -> V_168 ,
sizeof( V_25 -> V_168 ) ) ;
if ( ! V_63 ) {
V_63 = - V_172 ;
F_8 ( V_25 -> V_2 , L_20 ,
V_25 -> V_168 ) ;
goto V_173;
}
}
V_63 = 0 ;
F_69 ( & ( V_25 -> V_174 ) , & V_175 ) ;
V_173:
F_11 ( & V_171 , V_37 ) ;
return V_63 ;
}
static void F_70 ( struct V_24 * V_25 )
{
unsigned long V_37 ;
if ( V_25 -> V_174 . V_45 ) {
F_10 ( & V_171 , V_37 ) ;
F_71 ( & ( V_25 -> V_174 ) ) ;
F_11 ( & V_171 , V_37 ) ;
}
}
static int F_72 ( struct V_24 * V_25 )
{
int V_63 ;
V_63 = strlen ( V_25 -> V_2 -> V_176 ) ;
if ( V_63 != 17 )
return - V_103 ;
V_63 = sscanf ( V_25 -> V_2 -> V_176 ,
L_21 ,
& V_25 -> V_168 [ 5 ] , & V_25 -> V_168 [ 4 ] , & V_25 -> V_168 [ 3 ] ,
& V_25 -> V_168 [ 2 ] , & V_25 -> V_168 [ 1 ] , & V_25 -> V_168 [ 0 ] ) ;
if ( V_63 != 6 )
return - V_103 ;
return 0 ;
}
static int F_73 ( struct V_24 * V_25 )
{
T_1 * V_65 = NULL ;
int V_49 , V_63 ;
if ( ( V_25 -> V_26 & V_30 ) ||
( V_25 -> V_26 & V_177 ) ) {
if ( F_72 ( V_25 ) < 0 ) {
F_74 ( V_25 -> V_2 , L_22 ) ;
return 0 ;
}
} else if ( V_25 -> V_26 & V_28 ) {
V_65 = F_26 ( V_178 , V_66 ) ;
if ( ! V_65 )
return - V_67 ;
V_63 = F_27 ( V_25 -> V_2 , 0x81 , V_65 ,
V_178 , V_68 ,
V_69 ) ;
if ( V_63 != V_178 ) {
F_24 ( V_25 -> V_2 , L_23 ) ;
V_63 = V_63 < 0 ? V_63 : - V_103 ;
goto V_179;
}
memcpy ( V_25 -> V_168 , & V_65 [ 1 ] , sizeof( V_25 -> V_168 ) ) ;
} else if ( V_25 -> V_26 & V_94 ) {
V_65 = F_26 ( V_180 , V_66 ) ;
if ( ! V_65 )
return - V_67 ;
V_63 = F_27 ( V_25 -> V_2 , 0xf2 , V_65 ,
V_180 , V_68 ,
V_69 ) ;
if ( V_63 != V_180 ) {
F_24 ( V_25 -> V_2 , L_24 ) ;
V_63 = V_63 < 0 ? V_63 : - V_103 ;
goto V_179;
}
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ )
V_25 -> V_168 [ 5 - V_49 ] = V_65 [ 4 + V_49 ] ;
} else {
return 0 ;
}
V_63 = F_67 ( V_25 ) ;
V_179:
F_28 ( V_65 ) ;
return V_63 ;
}
static int F_75 ( struct V_24 * V_25 )
{
int V_63 ;
if ( ( V_25 -> V_26 & V_32 ) ||
( V_25 -> V_26 & V_64 ) ) {
V_63 = F_76 ( & V_181 , 0 , 0 ,
V_66 ) ;
if ( V_63 < 0 ) {
V_25 -> V_115 = - 1 ;
return V_63 ;
}
V_25 -> V_115 = V_63 ;
} else {
V_25 -> V_115 = - 1 ;
}
return 0 ;
}
static void F_77 ( struct V_24 * V_25 )
{
if ( V_25 -> V_115 >= 0 ) {
F_78 ( & V_181 , V_25 -> V_115 ) ;
V_25 -> V_115 = - 1 ;
}
}
static inline void F_79 ( struct V_24 * V_25 ,
void (* F_80)( struct V_121 * ) )
{
if ( ! V_25 -> V_182 )
F_81 ( & V_25 -> V_85 , F_80 ) ;
V_25 -> V_182 = 1 ;
}
static inline void F_82 ( struct V_24 * V_25 )
{
if ( V_25 -> V_182 )
F_83 ( & V_25 -> V_85 ) ;
}
static int F_84 ( struct V_1 * V_2 , const struct V_183 * V_72 )
{
int V_63 ;
unsigned long V_26 = V_72 -> V_184 ;
struct V_24 * V_25 ;
unsigned int V_185 = V_186 ;
V_25 = F_85 ( & V_2 -> V_90 , sizeof( * V_25 ) , V_66 ) ;
if ( V_25 == NULL ) {
F_24 ( V_2 , L_25 ) ;
return - V_67 ;
}
F_86 ( & V_25 -> V_42 ) ;
V_25 -> V_26 = V_26 ;
F_87 ( V_2 , V_25 ) ;
V_25 -> V_2 = V_2 ;
V_63 = F_88 ( V_2 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_26 ) ;
return V_63 ;
}
if ( V_25 -> V_26 & V_27 )
V_185 |= V_187 ;
else if ( V_25 -> V_26 & V_32 )
V_185 |= V_187 ;
V_63 = F_89 ( V_2 , V_185 ) ;
if ( V_63 ) {
F_24 ( V_2 , L_27 ) ;
return V_63 ;
}
V_63 = F_54 ( V_25 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_28 ) ;
goto V_188;
}
V_63 = F_75 ( V_25 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_29 ) ;
goto V_188;
}
if ( V_25 -> V_26 & V_94 ) {
V_2 -> V_26 |= V_189 ;
V_2 -> V_26 |= V_190 ;
V_63 = F_25 ( V_2 ) ;
F_79 ( V_25 , F_50 ) ;
} else if ( V_25 -> V_26 & V_177 ) {
V_2 -> V_26 |= V_189 ;
V_63 = F_29 ( V_2 ) ;
F_79 ( V_25 , F_50 ) ;
} else if ( V_25 -> V_26 & V_64 ) {
if ( V_25 -> V_26 & V_30 ) {
V_2 -> V_26 |= V_189 ;
V_63 = F_31 ( V_2 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_30 ) ;
goto V_188;
}
}
F_79 ( V_25 , F_52 ) ;
} else {
V_63 = 0 ;
}
if ( V_63 < 0 )
goto V_188;
V_63 = F_73 ( V_25 ) ;
if ( V_63 < 0 )
goto V_188;
if ( V_25 -> V_26 & V_104 ) {
V_63 = F_45 ( V_25 ) ;
if ( V_63 < 0 )
goto V_188;
}
if ( V_25 -> V_26 & V_191 ) {
V_63 = F_61 ( V_25 ) ;
if ( V_63 < 0 )
goto V_188;
V_63 = F_90 ( V_2 ) ;
if ( V_63 < 0 ) {
F_24 ( V_2 , L_31 ) ;
goto V_188;
}
}
if ( V_25 -> V_26 & V_192 ) {
V_63 = F_57 ( V_25 ) ;
if ( V_63 < 0 )
goto V_193;
}
return 0 ;
V_193:
F_91 ( V_2 ) ;
V_188:
if ( V_25 -> V_26 & V_104 )
F_43 ( V_25 ) ;
if ( V_25 -> V_26 & V_191 )
F_65 ( V_25 ) ;
F_82 ( V_25 ) ;
F_28 ( V_25 -> V_126 ) ;
F_70 ( V_25 ) ;
F_77 ( V_25 ) ;
F_92 ( V_2 ) ;
return V_63 ;
}
static void F_93 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_7 ( V_2 ) ;
if ( V_25 -> V_26 & V_104 )
F_43 ( V_25 ) ;
if ( V_25 -> V_26 & V_191 ) {
F_91 ( V_2 ) ;
F_65 ( V_25 ) ;
}
F_82 ( V_25 ) ;
F_28 ( V_25 -> V_126 ) ;
F_70 ( V_25 ) ;
F_77 ( V_25 ) ;
F_92 ( V_2 ) ;
}
static int T_6 F_94 ( void )
{
F_95 ( L_32 , V_194 ) ;
return F_96 ( & V_195 ) ;
}
static void T_7 F_97 ( void )
{
F_95 ( L_32 , V_194 ) ;
F_98 ( & V_195 ) ;
F_99 ( & V_181 ) ;
}
