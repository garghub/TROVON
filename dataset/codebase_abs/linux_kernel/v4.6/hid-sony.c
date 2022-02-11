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
static T_1 * F_3 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_7 ) ;
return V_7 ;
}
static T_1 * F_4 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_8 ) ;
return V_8 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 ,
unsigned long * * V_15 , int * V_16 )
{
unsigned int V_17 = V_14 -> V_18 & V_19 ;
if ( ( V_14 -> V_18 & V_20 ) != V_21 )
return - 1 ;
switch ( V_14 -> V_22 ) {
case 1 :
if ( V_17 >= F_6 ( V_23 ) )
return - 1 ;
V_17 = V_23 [ V_17 ] ;
if ( ! V_17 )
return - 1 ;
break;
case 2 :
if ( V_17 >= F_6 ( V_24 ) )
return - 1 ;
V_17 = V_24 [ V_17 ] ;
if ( ! V_17 )
return - 1 ;
break;
default:
return - 1 ;
}
F_7 ( V_10 , V_14 , V_15 , V_16 , V_25 , V_17 ) ;
return 1 ;
}
static T_1 * F_8 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
if ( V_27 -> V_28 & V_29 )
return V_3 ;
if ( ( V_27 -> V_28 & V_30 ) && * V_4 >= 56 &&
V_3 [ 2 ] == 0x09 && V_3 [ 3 ] == 0x02 &&
V_3 [ 54 ] == 0x81 && V_3 [ 55 ] == 0x07 ) {
F_10 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x06 ;
}
if ( V_27 -> V_28 & V_31 ) {
F_10 ( V_2 , L_2 ) ;
V_3 = V_32 ;
* V_4 = sizeof( V_32 ) ;
} else if ( V_27 -> V_28 & V_33 ) {
F_10 ( V_2 , L_3 ) ;
V_3 = V_34 ;
* V_4 = sizeof( V_34 ) ;
}
if ( V_27 -> V_28 & V_35 )
return F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_27 -> V_28 & V_36 )
return F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_27 -> V_28 & V_37 )
return F_3 ( V_2 , V_3 , V_4 ) ;
if ( V_27 -> V_28 & V_38 )
return F_4 ( V_2 , V_3 , V_4 ) ;
return V_3 ;
}
static void F_11 ( struct V_26 * V_27 , T_1 * V_39 , int V_40 )
{
static const T_1 V_41 [] = { 0 , 1 , 25 , 50 , 75 , 100 } ;
unsigned long V_42 ;
int V_43 ;
T_1 V_44 , V_45 , V_46 ;
V_43 = ( V_27 -> V_28 & V_36 ) ? 12 : 30 ;
if ( V_39 [ V_43 ] >= 0xee ) {
V_45 = 100 ;
V_46 = ! ( V_39 [ V_43 ] & 0x01 ) ;
V_44 = 1 ;
} else {
T_1 V_47 = V_39 [ V_43 ] <= 5 ? V_39 [ V_43 ] : 5 ;
V_45 = V_41 [ V_47 ] ;
V_46 = 0 ;
V_44 = 0 ;
}
F_12 ( & V_27 -> V_48 , V_42 ) ;
V_27 -> V_44 = V_44 ;
V_27 -> V_45 = V_45 ;
V_27 -> V_46 = V_46 ;
F_13 ( & V_27 -> V_48 , V_42 ) ;
}
static void F_14 ( struct V_26 * V_27 , T_1 * V_39 , int V_40 )
{
struct V_9 * V_49 = F_15 ( V_27 -> V_2 -> V_50 . V_51 ,
struct V_9 , V_52 ) ;
struct V_53 * V_53 = V_49 -> V_54 ;
unsigned long V_42 ;
int V_55 , V_43 ;
T_1 V_44 , V_45 , V_46 ;
V_43 = ( V_27 -> V_28 & V_31 ) ? 30 : 32 ;
V_44 = ( V_39 [ V_43 ] >> 4 ) & 0x01 ;
V_45 = V_39 [ V_43 ] & 0x0F ;
if ( ! V_44 || V_45 > 10 )
V_46 = 0 ;
else
V_46 = 1 ;
if ( ! V_44 )
V_45 ++ ;
if ( V_45 > 10 )
V_45 = 10 ;
V_45 *= 10 ;
F_12 ( & V_27 -> V_48 , V_42 ) ;
V_27 -> V_44 = V_44 ;
V_27 -> V_45 = V_45 ;
V_27 -> V_46 = V_46 ;
F_13 ( & V_27 -> V_48 , V_42 ) ;
V_43 += 5 ;
for ( V_55 = 0 ; V_55 < 2 ; V_55 ++ ) {
T_2 V_56 , V_57 ;
V_56 = V_39 [ V_43 + 1 ] | ( ( V_39 [ V_43 + 2 ] & 0xF ) << 8 ) ;
V_57 = ( ( V_39 [ V_43 + 2 ] & 0xF0 ) >> 4 ) | ( V_39 [ V_43 + 3 ] << 4 ) ;
F_16 ( V_53 , V_55 ) ;
F_17 ( V_53 , V_58 ,
! ( V_39 [ V_43 ] >> 7 ) ) ;
F_18 ( V_53 , V_59 , V_56 ) ;
F_18 ( V_53 , V_60 , V_57 ) ;
V_43 += 4 ;
}
}
static int F_19 ( struct V_1 * V_2 , struct V_61 * V_62 ,
T_1 * V_39 , int V_40 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
if ( ( V_27 -> V_28 & V_35 ) && V_39 [ 0 ] == 0x01 && V_40 == 49 ) {
if ( V_39 [ 1 ] == 0xff )
return - V_63 ;
F_20 ( V_39 [ 41 ] , V_39 [ 42 ] ) ;
F_20 ( V_39 [ 43 ] , V_39 [ 44 ] ) ;
F_20 ( V_39 [ 45 ] , V_39 [ 46 ] ) ;
F_20 ( V_39 [ 47 ] , V_39 [ 48 ] ) ;
F_11 ( V_27 , V_39 , V_40 ) ;
} else if ( ( V_27 -> V_28 & V_64 ) && V_39 [ 0 ] == 0x01 && V_40 == 49 ) {
F_11 ( V_27 , V_39 , V_40 ) ;
} else if ( ( V_27 -> V_28 & V_37 ) && V_39 [ 0 ] == 0x01 &&
V_40 == 49 ) {
F_11 ( V_27 , V_39 , V_40 ) ;
} else if ( ( ( V_27 -> V_28 & V_31 ) && V_39 [ 0 ] == 0x01 &&
V_40 == 64 ) || ( ( V_27 -> V_28 & V_33 )
&& V_39 [ 0 ] == 0x11 && V_40 == 78 ) ) {
F_14 ( V_27 , V_39 , V_40 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 ,
unsigned long * * V_15 , int * V_16 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
if ( V_27 -> V_28 & V_65 ) {
unsigned int V_17 = V_14 -> V_18 & V_19 ;
if ( ( V_14 -> V_18 & V_20 ) != V_21 )
return - 1 ;
switch ( V_14 -> V_22 ) {
case 1 :
if ( V_17 >= F_6 ( V_66 ) )
return - 1 ;
V_17 = V_66 [ V_17 ] ;
if ( ! V_17 )
return - 1 ;
break;
default:
return - 1 ;
}
F_7 ( V_10 , V_14 , V_15 , V_16 , V_25 , V_17 ) ;
return 1 ;
}
if ( V_27 -> V_28 & V_38 )
return F_5 ( V_2 , V_10 , V_12 , V_14 , V_15 , V_16 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , int V_67 ,
int V_68 , int V_69 )
{
struct V_53 * V_53 = V_10 -> V_54 ;
int V_70 ;
V_70 = F_23 ( V_53 , V_67 , 0 ) ;
if ( V_70 < 0 )
return V_70 ;
F_24 ( V_53 , V_59 , 0 , V_68 , 0 , 0 ) ;
F_24 ( V_53 , V_60 , 0 , V_69 , 0 , 0 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_9 * V_49 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
int V_70 ;
if ( V_27 -> V_28 & V_71 ) {
V_70 = F_22 ( V_49 , 2 , 1920 , 942 ) ;
if ( V_70 ) {
F_26 ( V_27 -> V_2 ,
L_4 ,
V_70 ) ;
return V_70 ;
}
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
const int V_72 =
V_16 ( V_73 , V_74 ) ;
T_1 * V_75 ;
int V_70 ;
V_75 = F_28 ( V_72 , V_76 ) ;
if ( ! V_75 )
return - V_77 ;
V_70 = F_29 ( V_2 , 0xf2 , V_75 , V_73 ,
V_78 , V_79 ) ;
if ( V_70 < 0 ) {
F_26 ( V_2 , L_5 ) ;
goto V_80;
}
V_70 = F_29 ( V_2 , 0xf5 , V_75 , V_74 ,
V_78 , V_79 ) ;
if ( V_70 < 0 ) {
F_26 ( V_2 , L_6 ) ;
goto V_80;
}
V_70 = F_30 ( V_2 , V_75 , 1 ) ;
if ( V_70 < 0 ) {
F_10 ( V_2 , L_7 ) ;
V_70 = 0 ;
}
V_80:
F_31 ( V_75 ) ;
return V_70 ;
}
static int F_32 ( struct V_1 * V_2 )
{
static const T_1 V_62 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
T_1 * V_75 ;
int V_70 ;
V_75 = F_33 ( V_62 , sizeof( V_62 ) , V_76 ) ;
if ( ! V_75 )
return - V_77 ;
V_70 = F_29 ( V_2 , V_75 [ 0 ] , V_75 , sizeof( V_62 ) ,
V_78 , V_81 ) ;
F_31 ( V_75 ) ;
return V_70 ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_1 * V_75 ;
int V_70 ;
V_75 = F_28 ( V_82 , V_76 ) ;
if ( ! V_75 )
return - V_77 ;
V_70 = F_29 ( V_2 , 0x02 , V_75 , V_82 ,
V_78 , V_79 ) ;
F_31 ( V_75 ) ;
return V_70 ;
}
static void F_35 ( struct V_26 * V_27 )
{
static const T_1 V_83 [ 10 ] [ 4 ] = {
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
int V_84 = V_27 -> V_85 ;
F_36 ( V_86 < F_6 ( V_83 [ 0 ] ) ) ;
if ( V_84 < 0 )
return;
V_84 %= 10 ;
memcpy ( V_27 -> V_87 , V_83 [ V_84 ] , sizeof( V_83 [ V_84 ] ) ) ;
}
static void F_37 ( struct V_26 * V_27 )
{
static const T_1 V_88 [ 7 ] [ 3 ] = {
{ 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 } ,
{ 0x02 , 0x00 , 0x01 } ,
{ 0x02 , 0x01 , 0x00 } ,
{ 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 }
} ;
int V_84 = V_27 -> V_85 ;
F_36 ( V_86 < F_6 ( V_88 [ 0 ] ) ) ;
if ( V_84 < 0 )
return;
V_84 %= 7 ;
memcpy ( V_27 -> V_87 , V_88 [ V_84 ] , sizeof( V_88 [ V_84 ] ) ) ;
}
static void F_38 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_89 * V_90 =
& V_2 -> V_91 [ V_92 ] . V_90 ;
struct V_61 * V_62 = F_15 ( V_90 -> V_51 ,
struct V_61 , V_52 ) ;
T_3 * V_93 = V_62 -> V_12 [ 0 ] -> V_93 ;
F_36 ( V_86 < 4 ) ;
V_93 [ 0 ] = 0x00 ;
V_93 [ 1 ] = V_27 -> V_87 [ 0 ] ? 0xff : 0x00 ;
V_93 [ 2 ] = V_27 -> V_87 [ 1 ] ? 0xff : 0x00 ;
V_93 [ 3 ] = V_27 -> V_87 [ 2 ] ? 0xff : 0x00 ;
V_93 [ 4 ] = V_27 -> V_87 [ 3 ] ? 0xff : 0x00 ;
V_93 [ 5 ] = 0x00 ;
V_93 [ 6 ] = 0x00 ;
F_39 ( V_2 , V_62 , V_81 ) ;
}
static void F_40 ( struct V_26 * V_27 )
{
if ( ! ( V_27 -> V_28 & V_65 ) )
F_41 ( & V_27 -> V_94 ) ;
else
F_38 ( V_27 ) ;
}
static void F_42 ( struct V_95 * V_96 ,
enum V_97 V_93 )
{
struct V_98 * V_99 = V_96 -> V_99 -> V_100 ;
struct V_1 * V_2 = F_43 ( V_99 ) ;
struct V_26 * V_101 ;
int V_55 ;
int V_102 ;
V_101 = F_9 ( V_2 ) ;
if ( ! V_101 ) {
F_26 ( V_2 , L_8 ) ;
return;
}
V_102 = ! ! ( V_101 -> V_28 & V_103 ) ;
for ( V_55 = 0 ; V_55 < V_101 -> V_104 ; V_55 ++ ) {
if ( V_96 == V_101 -> V_105 [ V_55 ] && ( V_102 ||
( V_93 != V_101 -> V_87 [ V_55 ] ||
V_101 -> V_106 [ V_55 ] ||
V_101 -> V_107 [ V_55 ] ) ) ) {
V_101 -> V_87 [ V_55 ] = V_93 ;
V_101 -> V_106 [ V_55 ] = 0 ;
V_101 -> V_107 [ V_55 ] = 0 ;
F_40 ( V_101 ) ;
break;
}
}
}
static enum V_97 F_44 ( struct V_95 * V_96 )
{
struct V_98 * V_99 = V_96 -> V_99 -> V_100 ;
struct V_1 * V_2 = F_43 ( V_99 ) ;
struct V_26 * V_101 ;
int V_55 ;
V_101 = F_9 ( V_2 ) ;
if ( ! V_101 ) {
F_26 ( V_2 , L_8 ) ;
return V_108 ;
}
for ( V_55 = 0 ; V_55 < V_101 -> V_104 ; V_55 ++ ) {
if ( V_96 == V_101 -> V_105 [ V_55 ] )
return V_101 -> V_87 [ V_55 ] ;
}
return V_108 ;
}
static int F_45 ( struct V_95 * V_96 , unsigned long * V_109 ,
unsigned long * V_110 )
{
struct V_98 * V_99 = V_96 -> V_99 -> V_100 ;
struct V_1 * V_2 = F_43 ( V_99 ) ;
struct V_26 * V_101 = F_9 ( V_2 ) ;
int V_55 ;
T_1 V_111 , V_112 ;
if ( ! V_101 ) {
F_26 ( V_2 , L_8 ) ;
return - V_63 ;
}
if ( * V_109 > 2550 )
* V_109 = 2550 ;
if ( * V_110 > 2550 )
* V_110 = 2550 ;
if ( ! * V_109 && ! * V_110 )
* V_109 = * V_110 = 500 ;
V_111 = * V_109 / 10 ;
V_112 = * V_110 / 10 ;
for ( V_55 = 0 ; V_55 < V_101 -> V_104 ; V_55 ++ ) {
if ( V_96 == V_101 -> V_105 [ V_55 ] )
break;
}
if ( V_55 >= V_101 -> V_104 )
return - V_63 ;
if ( V_111 != V_101 -> V_106 [ V_55 ] ||
V_112 != V_101 -> V_107 [ V_55 ] ) {
V_101 -> V_106 [ V_55 ] = V_111 ;
V_101 -> V_107 [ V_55 ] = V_112 ;
F_41 ( & V_101 -> V_94 ) ;
}
return 0 ;
}
static void F_46 ( struct V_26 * V_27 )
{
struct V_95 * V_96 ;
int V_55 ;
F_47 ( ! ( V_27 -> V_28 & V_113 ) ) ;
for ( V_55 = 0 ; V_55 < V_27 -> V_104 ; V_55 ++ ) {
V_96 = V_27 -> V_105 [ V_55 ] ;
V_27 -> V_105 [ V_55 ] = NULL ;
if ( ! V_96 )
continue;
F_48 ( V_96 ) ;
F_31 ( V_96 ) ;
}
V_27 -> V_104 = 0 ;
}
static int F_49 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
int V_55 , V_70 = 0 ;
int V_114 ;
struct V_95 * V_96 ;
T_4 V_115 ;
char * V_116 ;
T_4 V_117 ;
const char * V_118 ;
static const char * const V_119 [] = { L_9 , L_10 , L_11 ,
L_12 } ;
T_1 V_120 [ V_86 ] = { [ 0 ... ( V_86 - 1 ) ] = 1 } ;
T_1 V_121 [ V_86 ] = { 0 } ;
F_47 ( ! ( V_27 -> V_28 & V_113 ) ) ;
if ( V_27 -> V_28 & V_65 ) {
V_27 -> V_104 = 4 ;
V_114 = 0 ;
V_117 = strlen ( L_13 ) ;
V_118 = L_14 ;
if ( ! F_50 ( V_2 , V_92 , 0 , 0 , 7 ) )
return - V_122 ;
} else if ( V_27 -> V_28 & V_71 ) {
F_37 ( V_27 ) ;
V_27 -> V_87 [ 3 ] = 1 ;
V_27 -> V_104 = 4 ;
memset ( V_120 , 255 , 3 ) ;
V_121 [ 3 ] = 1 ;
V_114 = 1 ;
V_117 = 0 ;
V_118 = L_15 ;
} else if ( V_27 -> V_28 & V_36 ) {
V_27 -> V_104 = 3 ;
memset ( V_120 , 255 , 3 ) ;
V_114 = 1 ;
V_117 = 0 ;
V_118 = L_15 ;
} else if ( V_27 -> V_28 & V_37 ) {
static const T_1 V_123 [ 4 ] = { 0x01 , 0x00 , 0x00 , 0x00 } ;
memcpy ( V_27 -> V_87 , V_123 , sizeof( V_123 ) ) ;
V_27 -> V_104 = 1 ;
memset ( V_121 , 1 , 4 ) ;
V_114 = 0 ;
V_117 = strlen ( L_16 ) ;
V_118 = L_17 ;
} else {
F_35 ( V_27 ) ;
V_27 -> V_104 = 4 ;
memset ( V_121 , 1 , 4 ) ;
V_114 = 0 ;
V_117 = strlen ( L_16 ) ;
V_118 = L_17 ;
}
F_40 ( V_27 ) ;
V_115 = strlen ( F_51 ( & V_2 -> V_99 ) ) + V_117 + 1 ;
for ( V_55 = 0 ; V_55 < V_27 -> V_104 ; V_55 ++ ) {
if ( V_114 )
V_115 = strlen ( F_51 ( & V_2 -> V_99 ) ) + strlen ( V_119 [ V_55 ] ) + 2 ;
V_96 = F_52 ( sizeof( struct V_95 ) + V_115 , V_76 ) ;
if ( ! V_96 ) {
F_26 ( V_2 , L_18 , V_55 ) ;
V_70 = - V_77 ;
goto V_124;
}
V_116 = ( void * ) ( & V_96 [ 1 ] ) ;
if ( V_114 )
snprintf ( V_116 , V_115 , V_118 , F_51 ( & V_2 -> V_99 ) ,
V_119 [ V_55 ] ) ;
else
snprintf ( V_116 , V_115 , V_118 , F_51 ( & V_2 -> V_99 ) , V_55 + 1 ) ;
V_96 -> V_116 = V_116 ;
V_96 -> V_125 = V_27 -> V_87 [ V_55 ] ;
V_96 -> V_120 = V_120 [ V_55 ] ;
V_96 -> V_126 = F_44 ;
V_96 -> V_127 = F_42 ;
if ( V_121 [ V_55 ] )
V_96 -> V_128 = F_45 ;
V_27 -> V_105 [ V_55 ] = V_96 ;
V_70 = F_53 ( & V_2 -> V_99 , V_96 ) ;
if ( V_70 ) {
F_26 ( V_2 , L_19 , V_55 ) ;
V_27 -> V_105 [ V_55 ] = NULL ;
F_31 ( V_96 ) ;
goto V_124;
}
}
return V_70 ;
V_124:
F_46 ( V_27 ) ;
return V_70 ;
}
static void F_54 ( struct V_26 * V_27 )
{
static const union V_129 V_130 = {
. V_75 = {
0x01 ,
0x01 , 0xff , 0x00 , 0xff , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00
}
} ;
struct V_131 * V_62 =
(struct V_131 * ) V_27 -> V_132 ;
int V_55 ;
memcpy ( V_62 , & V_130 , sizeof( struct V_131 ) ) ;
#ifdef F_55
V_62 -> V_133 . V_134 = V_27 -> V_135 ? 1 : 0 ;
V_62 -> V_133 . V_136 = V_27 -> V_137 ;
#endif
V_62 -> V_138 |= V_27 -> V_87 [ 0 ] << 1 ;
V_62 -> V_138 |= V_27 -> V_87 [ 1 ] << 2 ;
V_62 -> V_138 |= V_27 -> V_87 [ 2 ] << 3 ;
V_62 -> V_138 |= V_27 -> V_87 [ 3 ] << 4 ;
if ( ( V_62 -> V_138 & 0x1E ) == 0 )
V_62 -> V_138 |= 0x20 ;
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
if ( V_27 -> V_106 [ V_55 ] || V_27 -> V_107 [ V_55 ] ) {
V_62 -> V_96 [ 3 - V_55 ] . V_139 = V_27 -> V_107 [ V_55 ] ;
V_62 -> V_96 [ 3 - V_55 ] . V_140 = V_27 -> V_106 [ V_55 ] ;
}
}
F_29 ( V_27 -> V_2 , V_62 -> V_141 , ( T_1 * ) V_62 ,
sizeof( struct V_131 ) ,
V_92 , V_81 ) ;
}
static void F_56 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
T_1 * V_75 = V_27 -> V_132 ;
int V_43 ;
if ( V_27 -> V_28 & V_31 ) {
memset ( V_75 , 0 , V_142 ) ;
V_75 [ 0 ] = 0x05 ;
V_75 [ 1 ] = 0xFF ;
V_43 = 4 ;
} else {
memset ( V_75 , 0 , V_143 ) ;
V_75 [ 0 ] = 0x11 ;
V_75 [ 1 ] = 0x80 ;
V_75 [ 3 ] = 0x0F ;
V_43 = 6 ;
}
#ifdef F_55
V_75 [ V_43 ++ ] = V_27 -> V_135 ;
V_75 [ V_43 ++ ] = V_27 -> V_137 ;
#else
V_43 += 2 ;
#endif
if ( V_27 -> V_87 [ 3 ] ) {
V_75 [ V_43 ++ ] = V_27 -> V_87 [ 0 ] ;
V_75 [ V_43 ++ ] = V_27 -> V_87 [ 1 ] ;
V_75 [ V_43 ++ ] = V_27 -> V_87 [ 2 ] ;
} else {
V_43 += 3 ;
}
V_75 [ V_43 ++ ] = V_27 -> V_106 [ 3 ] ;
V_75 [ V_43 ++ ] = V_27 -> V_107 [ 3 ] ;
if ( V_27 -> V_28 & V_31 )
F_30 ( V_2 , V_75 , V_142 ) ;
else
F_29 ( V_2 , 0x11 , V_75 , V_143 ,
V_92 , V_81 ) ;
}
static void F_57 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_144 * V_62 =
(struct V_144 * ) V_27 -> V_132 ;
memset ( V_62 , 0 , V_145 ) ;
V_62 -> type = 0x02 ;
V_62 -> V_146 = V_27 -> V_87 [ 0 ] ;
V_62 -> V_147 = V_27 -> V_87 [ 1 ] ;
V_62 -> V_148 = V_27 -> V_87 [ 2 ] ;
#ifdef F_55
V_62 -> V_133 = V_16 ( V_27 -> V_135 , V_27 -> V_137 ) ;
#endif
F_30 ( V_2 , ( T_1 * ) V_62 , V_145 ) ;
}
static inline void F_58 ( struct V_26 * V_27 )
{
if ( V_27 -> V_149 )
V_27 -> V_149 ( V_27 ) ;
}
static void F_59 ( struct V_150 * V_151 )
{
struct V_26 * V_27 = F_60 ( V_151 , struct V_26 , V_94 ) ;
V_27 -> V_149 ( V_27 ) ;
}
static int F_61 ( struct V_26 * V_27 )
{
if ( ( V_27 -> V_28 & V_35 ) ||
( V_27 -> V_28 & V_37 ) )
V_27 -> V_132 =
F_28 ( sizeof( union V_129 ) ,
V_76 ) ;
else if ( V_27 -> V_28 & V_33 )
V_27 -> V_132 = F_28 ( V_143 ,
V_76 ) ;
else if ( V_27 -> V_28 & V_31 )
V_27 -> V_132 = F_28 ( V_142 ,
V_76 ) ;
else if ( V_27 -> V_28 & V_36 )
V_27 -> V_132 = F_28 ( V_145 ,
V_76 ) ;
else
return 0 ;
if ( ! V_27 -> V_132 )
return - V_77 ;
return 0 ;
}
static int F_62 ( struct V_53 * V_99 , void * V_152 ,
struct V_153 * V_154 )
{
struct V_1 * V_18 = F_63 ( V_99 ) ;
struct V_26 * V_27 = F_9 ( V_18 ) ;
if ( V_154 -> type != V_155 )
return 0 ;
V_27 -> V_137 = V_154 -> V_156 . V_133 . V_157 / 256 ;
V_27 -> V_135 = V_154 -> V_156 . V_133 . V_158 / 256 ;
F_41 ( & V_27 -> V_94 ) ;
return 0 ;
}
static int F_64 ( struct V_26 * V_27 )
{
struct V_9 * V_49 = F_15 ( V_27 -> V_2 -> V_50 . V_51 ,
struct V_9 , V_52 ) ;
struct V_53 * V_53 = V_49 -> V_54 ;
F_65 ( V_53 , V_159 , V_155 ) ;
return F_66 ( V_53 , NULL , F_62 ) ;
}
static int F_64 ( struct V_26 * V_27 )
{
return 0 ;
}
static int F_67 ( struct V_160 * V_161 ,
enum V_162 V_163 ,
union V_164 * V_165 )
{
struct V_26 * V_27 = F_68 ( V_161 ) ;
unsigned long V_42 ;
int V_70 = 0 ;
T_1 V_46 , V_45 , V_44 ;
F_12 ( & V_27 -> V_48 , V_42 ) ;
V_46 = V_27 -> V_46 ;
V_45 = V_27 -> V_45 ;
V_44 = V_27 -> V_44 ;
F_13 ( & V_27 -> V_48 , V_42 ) ;
switch ( V_163 ) {
case V_166 :
V_165 -> V_167 = 1 ;
break;
case V_168 :
V_165 -> V_167 = V_169 ;
break;
case V_170 :
V_165 -> V_167 = V_45 ;
break;
case V_171 :
if ( V_46 )
V_165 -> V_167 = V_172 ;
else
if ( V_45 == 100 && V_44 )
V_165 -> V_167 = V_173 ;
else
V_165 -> V_167 = V_174 ;
break;
default:
V_70 = - V_63 ;
break;
}
return V_70 ;
}
static int F_69 ( struct V_26 * V_27 )
{
struct V_175 V_176 = { . V_101 = V_27 , } ;
struct V_1 * V_2 = V_27 -> V_2 ;
int V_70 ;
V_27 -> V_45 = 100 ;
V_27 -> V_177 . V_178 = V_179 ;
V_27 -> V_177 . V_180 = F_6 ( V_179 ) ;
V_27 -> V_177 . V_181 = F_67 ;
V_27 -> V_177 . type = V_182 ;
V_27 -> V_177 . V_183 = 0 ;
V_27 -> V_177 . V_116 = F_70 ( V_76 ,
L_20 ,
V_27 -> V_184 ) ;
if ( ! V_27 -> V_177 . V_116 )
return - V_77 ;
V_27 -> V_185 = F_71 ( & V_2 -> V_99 , & V_27 -> V_177 ,
& V_176 ) ;
if ( F_72 ( V_27 -> V_185 ) ) {
V_70 = F_73 ( V_27 -> V_185 ) ;
F_26 ( V_2 , L_21 ) ;
goto V_186;
}
F_74 ( V_27 -> V_185 , & V_2 -> V_99 ) ;
return 0 ;
V_186:
F_31 ( V_27 -> V_177 . V_116 ) ;
V_27 -> V_177 . V_116 = NULL ;
return V_70 ;
}
static void F_75 ( struct V_26 * V_27 )
{
if ( ! V_27 -> V_177 . V_116 )
return;
F_76 ( V_27 -> V_185 ) ;
F_31 ( V_27 -> V_177 . V_116 ) ;
V_27 -> V_177 . V_116 = NULL ;
}
static int F_77 ( struct V_26 * V_27 )
{
struct V_26 * V_187 ;
unsigned long V_42 ;
int V_70 ;
F_12 ( & V_188 , V_42 ) ;
F_78 (entry, &sony_device_list, list_node) {
V_70 = memcmp ( V_27 -> V_184 , V_187 -> V_184 ,
sizeof( V_27 -> V_184 ) ) ;
if ( ! V_70 ) {
V_70 = - V_189 ;
F_10 ( V_27 -> V_2 , L_22 ,
V_27 -> V_184 ) ;
goto V_190;
}
}
V_70 = 0 ;
F_79 ( & ( V_27 -> V_191 ) , & V_192 ) ;
V_190:
F_13 ( & V_188 , V_42 ) ;
return V_70 ;
}
static void F_80 ( struct V_26 * V_27 )
{
unsigned long V_42 ;
if ( V_27 -> V_191 . V_51 ) {
F_12 ( & V_188 , V_42 ) ;
F_81 ( & ( V_27 -> V_191 ) ) ;
F_13 ( & V_188 , V_42 ) ;
}
}
static int F_82 ( struct V_26 * V_27 )
{
int V_70 ;
V_70 = strlen ( V_27 -> V_2 -> V_193 ) ;
if ( V_70 != 17 )
return - V_63 ;
V_70 = sscanf ( V_27 -> V_2 -> V_193 ,
L_23 ,
& V_27 -> V_184 [ 5 ] , & V_27 -> V_184 [ 4 ] , & V_27 -> V_184 [ 3 ] ,
& V_27 -> V_184 [ 2 ] , & V_27 -> V_184 [ 1 ] , & V_27 -> V_184 [ 0 ] ) ;
if ( V_70 != 6 )
return - V_63 ;
return 0 ;
}
static int F_83 ( struct V_26 * V_27 )
{
T_1 * V_75 = NULL ;
int V_55 , V_70 ;
if ( ( V_27 -> V_28 & V_33 ) ||
( V_27 -> V_28 & V_64 ) ||
( V_27 -> V_28 & V_194 ) ||
( V_27 -> V_28 & V_195 ) ) {
if ( F_82 ( V_27 ) < 0 ) {
F_84 ( V_27 -> V_2 , L_24 ) ;
return 0 ;
}
} else if ( V_27 -> V_28 & V_31 ) {
V_75 = F_28 ( V_196 , V_76 ) ;
if ( ! V_75 )
return - V_77 ;
V_70 = F_29 ( V_27 -> V_2 , 0x81 , V_75 ,
V_196 , V_78 ,
V_79 ) ;
if ( V_70 != V_196 ) {
F_26 ( V_27 -> V_2 , L_25 ) ;
V_70 = V_70 < 0 ? V_70 : - V_63 ;
goto V_197;
}
memcpy ( V_27 -> V_184 , & V_75 [ 1 ] , sizeof( V_27 -> V_184 ) ) ;
} else if ( ( V_27 -> V_28 & V_103 ) ||
( V_27 -> V_28 & V_198 ) ) {
V_75 = F_28 ( V_73 , V_76 ) ;
if ( ! V_75 )
return - V_77 ;
V_70 = F_29 ( V_27 -> V_2 , 0xf2 , V_75 ,
V_73 , V_78 ,
V_79 ) ;
if ( V_70 != V_73 ) {
F_26 ( V_27 -> V_2 , L_26 ) ;
V_70 = V_70 < 0 ? V_70 : - V_63 ;
goto V_197;
}
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ )
V_27 -> V_184 [ 5 - V_55 ] = V_75 [ 4 + V_55 ] ;
} else {
return 0 ;
}
V_70 = F_77 ( V_27 ) ;
V_197:
F_31 ( V_75 ) ;
return V_70 ;
}
static int F_85 ( struct V_26 * V_27 )
{
int V_70 ;
if ( ( V_27 -> V_28 & V_35 ) ||
( V_27 -> V_28 & V_71 ) ) {
V_70 = F_86 ( & V_199 , 0 , 0 ,
V_76 ) ;
if ( V_70 < 0 ) {
V_27 -> V_85 = - 1 ;
return V_70 ;
}
V_27 -> V_85 = V_70 ;
} else {
V_27 -> V_85 = - 1 ;
}
return 0 ;
}
static void F_87 ( struct V_26 * V_27 )
{
if ( V_27 -> V_85 >= 0 ) {
F_88 ( & V_199 , V_27 -> V_85 ) ;
V_27 -> V_85 = - 1 ;
}
}
static inline void F_89 ( struct V_26 * V_27 ,
void (* V_149)( struct V_26 * ) )
{
V_27 -> V_149 = V_149 ;
if ( ! V_27 -> V_200 )
F_90 ( & V_27 -> V_94 , F_59 ) ;
V_27 -> V_200 = 1 ;
}
static inline void F_91 ( struct V_26 * V_27 )
{
if ( V_27 -> V_200 )
F_92 ( & V_27 -> V_94 ) ;
}
static int F_93 ( struct V_1 * V_2 , const struct V_201 * V_84 )
{
int V_70 ;
unsigned long V_28 = V_84 -> V_202 ;
struct V_26 * V_27 ;
unsigned int V_203 = V_204 ;
V_27 = F_94 ( & V_2 -> V_99 , sizeof( * V_27 ) , V_76 ) ;
if ( V_27 == NULL ) {
F_26 ( V_2 , L_27 ) ;
return - V_77 ;
}
F_95 ( & V_27 -> V_48 ) ;
V_27 -> V_28 = V_28 ;
F_96 ( V_2 , V_27 ) ;
V_27 -> V_2 = V_2 ;
V_70 = F_97 ( V_2 ) ;
if ( V_70 ) {
F_26 ( V_2 , L_28 ) ;
return V_70 ;
}
if ( V_27 -> V_28 & V_30 )
V_203 |= V_205 ;
else if ( V_27 -> V_28 & V_35 )
V_203 |= V_205 ;
V_70 = F_98 ( V_2 , V_203 ) ;
if ( V_70 ) {
F_26 ( V_2 , L_29 ) ;
return V_70 ;
}
V_70 = F_85 ( V_27 ) ;
if ( V_70 < 0 ) {
F_26 ( V_2 , L_30 ) ;
goto V_206;
}
V_70 = F_61 ( V_27 ) ;
if ( V_70 < 0 ) {
F_26 ( V_2 , L_31 ) ;
goto V_206;
}
if ( ( V_27 -> V_28 & V_103 ) ||
( V_27 -> V_28 & V_198 ) ) {
V_2 -> V_28 |= V_207 ;
V_2 -> V_28 |= V_208 ;
V_70 = F_27 ( V_2 ) ;
F_89 ( V_27 , F_54 ) ;
} else if ( ( V_27 -> V_28 & V_195 ) ||
( V_27 -> V_28 & V_194 ) ) {
V_2 -> V_28 |= V_207 ;
V_70 = F_32 ( V_2 ) ;
F_89 ( V_27 , F_54 ) ;
} else if ( V_27 -> V_28 & V_71 ) {
if ( V_27 -> V_28 & V_33 ) {
V_2 -> V_28 |= V_207 ;
V_70 = F_34 ( V_2 ) ;
if ( V_70 < 0 ) {
F_26 ( V_2 , L_32 ) ;
goto V_206;
}
}
F_89 ( V_27 , F_56 ) ;
} else if ( V_27 -> V_28 & V_36 ) {
F_89 ( V_27 , F_57 ) ;
} else {
V_70 = 0 ;
}
if ( V_70 < 0 )
goto V_206;
V_70 = F_83 ( V_27 ) ;
if ( V_70 < 0 )
goto V_206;
if ( V_27 -> V_28 & V_113 ) {
V_70 = F_49 ( V_27 ) ;
if ( V_70 < 0 )
goto V_206;
}
if ( V_27 -> V_28 & V_209 ) {
V_70 = F_69 ( V_27 ) ;
if ( V_70 < 0 )
goto V_206;
V_70 = F_99 ( V_2 ) ;
if ( V_70 < 0 ) {
F_26 ( V_2 , L_33 ) ;
goto V_206;
}
}
if ( V_27 -> V_28 & V_210 ) {
V_70 = F_64 ( V_27 ) ;
if ( V_70 < 0 )
goto V_211;
}
return 0 ;
V_211:
F_100 ( V_2 ) ;
V_206:
if ( V_27 -> V_28 & V_113 )
F_46 ( V_27 ) ;
if ( V_27 -> V_28 & V_209 )
F_75 ( V_27 ) ;
F_91 ( V_27 ) ;
F_31 ( V_27 -> V_132 ) ;
F_80 ( V_27 ) ;
F_87 ( V_27 ) ;
F_101 ( V_2 ) ;
return V_70 ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
if ( V_27 -> V_28 & V_113 )
F_46 ( V_27 ) ;
if ( V_27 -> V_28 & V_209 ) {
F_100 ( V_2 ) ;
F_75 ( V_27 ) ;
}
F_91 ( V_27 ) ;
F_31 ( V_27 -> V_132 ) ;
F_80 ( V_27 ) ;
F_87 ( V_27 ) ;
F_101 ( V_2 ) ;
}
static int F_103 ( struct V_1 * V_2 , T_5 V_212 )
{
if ( V_113 || V_210 ) {
struct V_26 * V_27 = F_9 ( V_2 ) ;
#ifdef F_55
V_27 -> V_137 = V_27 -> V_135 = 0 ;
#endif
memcpy ( V_27 -> V_213 , V_27 -> V_87 ,
sizeof( V_27 -> V_213 ) ) ;
memset ( V_27 -> V_87 , 0 , sizeof( V_27 -> V_87 ) ) ;
F_58 ( V_27 ) ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 )
{
if ( V_113 ) {
struct V_26 * V_27 = F_9 ( V_2 ) ;
memcpy ( V_27 -> V_87 , V_27 -> V_213 ,
sizeof( V_27 -> V_87 ) ) ;
if ( ( V_27 -> V_28 & V_103 ) ||
( V_27 -> V_28 & V_198 ) )
F_27 ( V_27 -> V_2 ) ;
F_40 ( V_27 ) ;
}
return 0 ;
}
static int T_6 F_105 ( void )
{
F_106 ( L_34 , V_214 ) ;
return F_107 ( & V_215 ) ;
}
static void T_7 F_108 ( void )
{
F_106 ( L_34 , V_214 ) ;
F_109 ( & V_215 ) ;
F_110 ( & V_199 ) ;
}
