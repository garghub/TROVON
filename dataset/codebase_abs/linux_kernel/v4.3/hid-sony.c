static T_1 * F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_5 ) ;
return V_5 ;
}
static T_2 * F_2 ( struct V_1 * V_2 , T_2 * V_3 ,
unsigned int * V_4 )
{
* V_4 = sizeof( V_6 ) ;
return V_6 ;
}
static T_2 * F_3 ( struct V_1 * V_2 , T_2 * V_3 ,
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
if ( ( V_27 -> V_28 & V_29 ) && * V_4 >= 56 &&
V_3 [ 2 ] == 0x09 && V_3 [ 3 ] == 0x02 &&
V_3 [ 54 ] == 0x81 && V_3 [ 55 ] == 0x07 ) {
F_10 ( V_2 , L_1 ) ;
V_3 [ 55 ] = 0x06 ;
}
if ( ( V_27 -> V_28 & V_30 ) && * V_4 == 467 ) {
F_10 ( V_2 , L_2 ) ;
V_3 = V_31 ;
* V_4 = sizeof( V_31 ) ;
} else if ( ( V_27 -> V_28 & V_32 ) && * V_4 == 357 ) {
F_10 ( V_2 , L_3 ) ;
V_3 = V_33 ;
* V_4 = sizeof( V_33 ) ;
}
if ( V_27 -> V_28 & V_34 )
return F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_27 -> V_28 & V_35 )
return F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_27 -> V_28 & V_36 )
return F_3 ( V_2 , V_3 , V_4 ) ;
if ( V_27 -> V_28 & V_37 )
return F_4 ( V_2 , V_3 , V_4 ) ;
return V_3 ;
}
static void F_11 ( struct V_26 * V_27 , T_1 * V_38 , int V_39 )
{
static const T_1 V_40 [] = { 0 , 1 , 25 , 50 , 75 , 100 } ;
unsigned long V_41 ;
int V_42 ;
T_1 V_43 , V_44 , V_45 ;
V_42 = ( V_27 -> V_28 & V_35 ) ? 12 : 30 ;
if ( V_38 [ V_42 ] >= 0xee ) {
V_44 = 100 ;
V_45 = ! ( V_38 [ V_42 ] & 0x01 ) ;
V_43 = 1 ;
} else {
T_1 V_46 = V_38 [ V_42 ] <= 5 ? V_38 [ V_42 ] : 5 ;
V_44 = V_40 [ V_46 ] ;
V_45 = 0 ;
V_43 = 0 ;
}
F_12 ( & V_27 -> V_47 , V_41 ) ;
V_27 -> V_43 = V_43 ;
V_27 -> V_44 = V_44 ;
V_27 -> V_45 = V_45 ;
F_13 ( & V_27 -> V_47 , V_41 ) ;
}
static void F_14 ( struct V_26 * V_27 , T_1 * V_38 , int V_39 )
{
struct V_9 * V_48 = F_15 ( V_27 -> V_2 -> V_49 . V_50 ,
struct V_9 , V_51 ) ;
struct V_52 * V_52 = V_48 -> V_53 ;
unsigned long V_41 ;
int V_54 , V_42 ;
T_1 V_43 , V_44 , V_45 ;
V_42 = ( V_27 -> V_28 & V_30 ) ? 30 : 32 ;
V_43 = ( V_38 [ V_42 ] >> 4 ) & 0x01 ;
V_44 = V_38 [ V_42 ] & 0x0F ;
if ( ! V_43 || V_44 > 10 )
V_45 = 0 ;
else
V_45 = 1 ;
if ( ! V_43 )
V_44 ++ ;
if ( V_44 > 10 )
V_44 = 10 ;
V_44 *= 10 ;
F_12 ( & V_27 -> V_47 , V_41 ) ;
V_27 -> V_43 = V_43 ;
V_27 -> V_44 = V_44 ;
V_27 -> V_45 = V_45 ;
F_13 ( & V_27 -> V_47 , V_41 ) ;
V_42 += 5 ;
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
T_3 V_55 , V_56 ;
V_55 = V_38 [ V_42 + 1 ] | ( ( V_38 [ V_42 + 2 ] & 0xF ) << 8 ) ;
V_56 = ( ( V_38 [ V_42 + 2 ] & 0xF0 ) >> 4 ) | ( V_38 [ V_42 + 3 ] << 4 ) ;
F_16 ( V_52 , V_54 ) ;
F_17 ( V_52 , V_57 ,
! ( V_38 [ V_42 ] >> 7 ) ) ;
F_18 ( V_52 , V_58 , V_55 ) ;
F_18 ( V_52 , V_59 , V_56 ) ;
V_42 += 4 ;
}
}
static int F_19 ( struct V_1 * V_2 , struct V_60 * V_61 ,
T_1 * V_38 , int V_39 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
if ( ( V_27 -> V_28 & V_34 ) && V_38 [ 0 ] == 0x01 && V_39 == 49 ) {
if ( V_38 [ 1 ] == 0xff )
return - V_62 ;
F_20 ( V_38 [ 41 ] , V_38 [ 42 ] ) ;
F_20 ( V_38 [ 43 ] , V_38 [ 44 ] ) ;
F_20 ( V_38 [ 45 ] , V_38 [ 46 ] ) ;
F_20 ( V_38 [ 47 ] , V_38 [ 48 ] ) ;
F_11 ( V_27 , V_38 , V_39 ) ;
} else if ( ( V_27 -> V_28 & V_63 ) && V_38 [ 0 ] == 0x01 && V_39 == 49 ) {
F_11 ( V_27 , V_38 , V_39 ) ;
} else if ( ( V_27 -> V_28 & V_36 ) && V_38 [ 0 ] == 0x01 &&
V_39 == 49 ) {
F_11 ( V_27 , V_38 , V_39 ) ;
} else if ( ( ( V_27 -> V_28 & V_30 ) && V_38 [ 0 ] == 0x01 &&
V_39 == 64 ) || ( ( V_27 -> V_28 & V_32 )
&& V_38 [ 0 ] == 0x11 && V_39 == 78 ) ) {
F_14 ( V_27 , V_38 , V_39 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 ,
unsigned long * * V_15 , int * V_16 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
if ( V_27 -> V_28 & V_64 ) {
unsigned int V_17 = V_14 -> V_18 & V_19 ;
if ( ( V_14 -> V_18 & V_20 ) != V_21 )
return - 1 ;
switch ( V_14 -> V_22 ) {
case 1 :
if ( V_17 >= F_6 ( V_65 ) )
return - 1 ;
V_17 = V_65 [ V_17 ] ;
if ( ! V_17 )
return - 1 ;
break;
default:
return - 1 ;
}
F_7 ( V_10 , V_14 , V_15 , V_16 , V_25 , V_17 ) ;
return 1 ;
}
if ( V_27 -> V_28 & V_37 )
return F_5 ( V_2 , V_10 , V_12 , V_14 , V_15 , V_16 ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 , int V_66 ,
int V_67 , int V_68 )
{
struct V_52 * V_52 = V_10 -> V_53 ;
int V_69 ;
V_69 = F_23 ( V_52 , V_66 , 0 ) ;
if ( V_69 < 0 )
return V_69 ;
F_24 ( V_52 , V_58 , 0 , V_67 , 0 , 0 ) ;
F_24 ( V_52 , V_59 , 0 , V_68 , 0 , 0 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_9 * V_48 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
if ( V_27 -> V_28 & V_70 ) {
if ( F_22 ( V_48 , 2 , 1920 , 942 ) != 0 )
F_26 ( V_27 -> V_2 ,
L_4 ) ;
}
}
static int F_27 ( struct V_1 * V_2 )
{
const int V_71 =
V_16 ( V_72 , V_73 ) ;
T_1 * V_74 ;
int V_69 ;
V_74 = F_28 ( V_71 , V_75 ) ;
if ( ! V_74 )
return - V_76 ;
V_69 = F_29 ( V_2 , 0xf2 , V_74 , V_72 ,
V_77 , V_78 ) ;
if ( V_69 < 0 ) {
F_26 ( V_2 , L_5 ) ;
goto V_79;
}
V_69 = F_29 ( V_2 , 0xf5 , V_74 , V_73 ,
V_77 , V_78 ) ;
if ( V_69 < 0 ) {
F_26 ( V_2 , L_6 ) ;
goto V_79;
}
V_69 = F_30 ( V_2 , V_74 , 1 ) ;
if ( V_69 < 0 )
F_26 ( V_2 , L_7 ) ;
V_79:
F_31 ( V_74 ) ;
return V_69 ;
}
static int F_32 ( struct V_1 * V_2 )
{
static const T_1 V_61 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
T_1 * V_74 ;
int V_69 ;
V_74 = F_33 ( V_61 , sizeof( V_61 ) , V_75 ) ;
if ( ! V_74 )
return - V_76 ;
V_69 = F_29 ( V_2 , V_74 [ 0 ] , V_74 , sizeof( V_61 ) ,
V_77 , V_80 ) ;
F_31 ( V_74 ) ;
return V_69 ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_1 * V_74 ;
int V_69 ;
V_74 = F_28 ( V_81 , V_75 ) ;
if ( ! V_74 )
return - V_76 ;
V_69 = F_29 ( V_2 , 0x02 , V_74 , V_81 ,
V_77 , V_78 ) ;
F_31 ( V_74 ) ;
return V_69 ;
}
static void F_35 ( struct V_26 * V_27 )
{
static const T_1 V_82 [ 10 ] [ 4 ] = {
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
int V_83 = V_27 -> V_84 ;
F_36 ( V_85 < F_6 ( V_82 [ 0 ] ) ) ;
if ( V_83 < 0 )
return;
V_83 %= 10 ;
memcpy ( V_27 -> V_86 , V_82 [ V_83 ] , sizeof( V_82 [ V_83 ] ) ) ;
}
static void F_37 ( struct V_26 * V_27 )
{
static const T_1 V_87 [ 7 ] [ 3 ] = {
{ 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 } ,
{ 0x02 , 0x00 , 0x01 } ,
{ 0x02 , 0x01 , 0x00 } ,
{ 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 }
} ;
int V_83 = V_27 -> V_84 ;
F_36 ( V_85 < F_6 ( V_87 [ 0 ] ) ) ;
if ( V_83 < 0 )
return;
V_83 %= 7 ;
memcpy ( V_27 -> V_86 , V_87 [ V_83 ] , sizeof( V_87 [ V_83 ] ) ) ;
}
static void F_38 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_88 * V_89 =
& V_2 -> V_90 [ V_91 ] . V_89 ;
struct V_60 * V_61 = F_15 ( V_89 -> V_50 ,
struct V_60 , V_51 ) ;
T_4 * V_92 = V_61 -> V_12 [ 0 ] -> V_92 ;
F_36 ( V_85 < 4 ) ;
V_92 [ 0 ] = 0x00 ;
V_92 [ 1 ] = V_27 -> V_86 [ 0 ] ? 0xff : 0x00 ;
V_92 [ 2 ] = V_27 -> V_86 [ 1 ] ? 0xff : 0x00 ;
V_92 [ 3 ] = V_27 -> V_86 [ 2 ] ? 0xff : 0x00 ;
V_92 [ 4 ] = V_27 -> V_86 [ 3 ] ? 0xff : 0x00 ;
V_92 [ 5 ] = 0x00 ;
V_92 [ 6 ] = 0x00 ;
F_39 ( V_2 , V_61 , V_80 ) ;
}
static void F_40 ( struct V_26 * V_27 )
{
if ( ! ( V_27 -> V_28 & V_64 ) )
F_41 ( & V_27 -> V_93 ) ;
else
F_38 ( V_27 ) ;
}
static void F_42 ( struct V_94 * V_95 ,
enum V_96 V_92 )
{
struct V_97 * V_98 = V_95 -> V_98 -> V_99 ;
struct V_1 * V_2 = F_43 ( V_98 , struct V_1 , V_98 ) ;
struct V_26 * V_100 ;
int V_54 ;
int V_101 ;
V_100 = F_9 ( V_2 ) ;
if ( ! V_100 ) {
F_26 ( V_2 , L_8 ) ;
return;
}
V_101 = ! ! ( V_100 -> V_28 & V_102 ) ;
for ( V_54 = 0 ; V_54 < V_100 -> V_103 ; V_54 ++ ) {
if ( V_95 == V_100 -> V_104 [ V_54 ] && ( V_101 ||
( V_92 != V_100 -> V_86 [ V_54 ] ||
V_100 -> V_105 [ V_54 ] ||
V_100 -> V_106 [ V_54 ] ) ) ) {
V_100 -> V_86 [ V_54 ] = V_92 ;
V_100 -> V_105 [ V_54 ] = 0 ;
V_100 -> V_106 [ V_54 ] = 0 ;
F_40 ( V_100 ) ;
break;
}
}
}
static enum V_96 F_44 ( struct V_94 * V_95 )
{
struct V_97 * V_98 = V_95 -> V_98 -> V_99 ;
struct V_1 * V_2 = F_43 ( V_98 , struct V_1 , V_98 ) ;
struct V_26 * V_100 ;
int V_54 ;
V_100 = F_9 ( V_2 ) ;
if ( ! V_100 ) {
F_26 ( V_2 , L_8 ) ;
return V_107 ;
}
for ( V_54 = 0 ; V_54 < V_100 -> V_103 ; V_54 ++ ) {
if ( V_95 == V_100 -> V_104 [ V_54 ] )
return V_100 -> V_86 [ V_54 ] ;
}
return V_107 ;
}
static int F_45 ( struct V_94 * V_95 , unsigned long * V_108 ,
unsigned long * V_109 )
{
struct V_97 * V_98 = V_95 -> V_98 -> V_99 ;
struct V_1 * V_2 = F_43 ( V_98 , struct V_1 , V_98 ) ;
struct V_26 * V_100 = F_9 ( V_2 ) ;
int V_54 ;
T_1 V_110 , V_111 ;
if ( ! V_100 ) {
F_26 ( V_2 , L_8 ) ;
return - V_62 ;
}
if ( * V_108 > 2550 )
* V_108 = 2550 ;
if ( * V_109 > 2550 )
* V_109 = 2550 ;
if ( ! * V_108 && ! * V_109 )
* V_108 = * V_109 = 500 ;
V_110 = * V_108 / 10 ;
V_111 = * V_109 / 10 ;
for ( V_54 = 0 ; V_54 < V_100 -> V_103 ; V_54 ++ ) {
if ( V_95 == V_100 -> V_104 [ V_54 ] )
break;
}
if ( V_54 >= V_100 -> V_103 )
return - V_62 ;
if ( V_110 != V_100 -> V_105 [ V_54 ] ||
V_111 != V_100 -> V_106 [ V_54 ] ) {
V_100 -> V_105 [ V_54 ] = V_110 ;
V_100 -> V_106 [ V_54 ] = V_111 ;
F_41 ( & V_100 -> V_93 ) ;
}
return 0 ;
}
static void F_46 ( struct V_26 * V_27 )
{
struct V_94 * V_95 ;
int V_54 ;
F_47 ( ! ( V_27 -> V_28 & V_112 ) ) ;
for ( V_54 = 0 ; V_54 < V_27 -> V_103 ; V_54 ++ ) {
V_95 = V_27 -> V_104 [ V_54 ] ;
V_27 -> V_104 [ V_54 ] = NULL ;
if ( ! V_95 )
continue;
F_48 ( V_95 ) ;
F_31 ( V_95 ) ;
}
V_27 -> V_103 = 0 ;
}
static int F_49 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
int V_54 , V_69 = 0 ;
int V_113 ;
struct V_94 * V_95 ;
T_5 V_114 ;
char * V_115 ;
T_5 V_116 ;
const char * V_117 ;
static const char * const V_118 [] = { L_9 , L_10 , L_11 ,
L_12 } ;
T_1 V_119 [ V_85 ] = { [ 0 ... ( V_85 - 1 ) ] = 1 } ;
T_1 V_120 [ V_85 ] = { 0 } ;
F_47 ( ! ( V_27 -> V_28 & V_112 ) ) ;
if ( V_27 -> V_28 & V_64 ) {
V_27 -> V_103 = 4 ;
V_113 = 0 ;
V_116 = strlen ( L_13 ) ;
V_117 = L_14 ;
if ( ! F_50 ( V_2 , V_91 , 0 , 0 , 7 ) )
return - V_121 ;
} else if ( V_27 -> V_28 & V_70 ) {
F_37 ( V_27 ) ;
V_27 -> V_86 [ 3 ] = 1 ;
V_27 -> V_103 = 4 ;
memset ( V_119 , 255 , 3 ) ;
V_120 [ 3 ] = 1 ;
V_113 = 1 ;
V_116 = 0 ;
V_117 = L_15 ;
} else if ( V_27 -> V_28 & V_35 ) {
V_27 -> V_103 = 3 ;
memset ( V_119 , 255 , 3 ) ;
V_113 = 1 ;
V_116 = 0 ;
V_117 = L_15 ;
} else if ( V_27 -> V_28 & V_36 ) {
static const T_1 V_122 [ 4 ] = { 0x01 , 0x00 , 0x00 , 0x00 } ;
memcpy ( V_27 -> V_86 , V_122 , sizeof( V_122 ) ) ;
V_27 -> V_103 = 1 ;
memset ( V_120 , 1 , 4 ) ;
V_113 = 0 ;
V_116 = strlen ( L_16 ) ;
V_117 = L_17 ;
} else {
F_35 ( V_27 ) ;
V_27 -> V_103 = 4 ;
memset ( V_120 , 1 , 4 ) ;
V_113 = 0 ;
V_116 = strlen ( L_16 ) ;
V_117 = L_17 ;
}
F_40 ( V_27 ) ;
V_114 = strlen ( F_51 ( & V_2 -> V_98 ) ) + V_116 + 1 ;
for ( V_54 = 0 ; V_54 < V_27 -> V_103 ; V_54 ++ ) {
if ( V_113 )
V_114 = strlen ( F_51 ( & V_2 -> V_98 ) ) + strlen ( V_118 [ V_54 ] ) + 2 ;
V_95 = F_52 ( sizeof( struct V_94 ) + V_114 , V_75 ) ;
if ( ! V_95 ) {
F_26 ( V_2 , L_18 , V_54 ) ;
V_69 = - V_76 ;
goto V_123;
}
V_115 = ( void * ) ( & V_95 [ 1 ] ) ;
if ( V_113 )
snprintf ( V_115 , V_114 , V_117 , F_51 ( & V_2 -> V_98 ) ,
V_118 [ V_54 ] ) ;
else
snprintf ( V_115 , V_114 , V_117 , F_51 ( & V_2 -> V_98 ) , V_54 + 1 ) ;
V_95 -> V_115 = V_115 ;
V_95 -> V_124 = V_27 -> V_86 [ V_54 ] ;
V_95 -> V_119 = V_119 [ V_54 ] ;
V_95 -> V_125 = F_44 ;
V_95 -> V_126 = F_42 ;
if ( V_120 [ V_54 ] )
V_95 -> V_127 = F_45 ;
V_27 -> V_104 [ V_54 ] = V_95 ;
V_69 = F_53 ( & V_2 -> V_98 , V_95 ) ;
if ( V_69 ) {
F_26 ( V_2 , L_19 , V_54 ) ;
V_27 -> V_104 [ V_54 ] = NULL ;
F_31 ( V_95 ) ;
goto V_123;
}
}
return V_69 ;
V_123:
F_46 ( V_27 ) ;
return V_69 ;
}
static void F_54 ( struct V_128 * V_129 )
{
static const union V_130 V_131 = {
. V_74 = {
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
struct V_26 * V_27 = F_43 ( V_129 , struct V_26 , V_93 ) ;
struct V_132 * V_61 =
(struct V_132 * ) V_27 -> V_133 ;
int V_54 ;
memcpy ( V_61 , & V_131 , sizeof( struct V_132 ) ) ;
#ifdef F_55
V_61 -> V_134 . V_135 = V_27 -> V_136 ? 1 : 0 ;
V_61 -> V_134 . V_137 = V_27 -> V_138 ;
#endif
V_61 -> V_139 |= V_27 -> V_86 [ 0 ] << 1 ;
V_61 -> V_139 |= V_27 -> V_86 [ 1 ] << 2 ;
V_61 -> V_139 |= V_27 -> V_86 [ 2 ] << 3 ;
V_61 -> V_139 |= V_27 -> V_86 [ 3 ] << 4 ;
if ( ( V_61 -> V_139 & 0x1E ) == 0 )
V_61 -> V_139 |= 0x20 ;
for ( V_54 = 0 ; V_54 < 4 ; V_54 ++ ) {
if ( V_27 -> V_105 [ V_54 ] || V_27 -> V_106 [ V_54 ] ) {
V_61 -> V_95 [ 3 - V_54 ] . V_140 = V_27 -> V_106 [ V_54 ] ;
V_61 -> V_95 [ 3 - V_54 ] . V_141 = V_27 -> V_105 [ V_54 ] ;
}
}
F_29 ( V_27 -> V_2 , V_61 -> V_142 , ( T_1 * ) V_61 ,
sizeof( struct V_132 ) ,
V_91 , V_80 ) ;
}
static void F_56 ( struct V_128 * V_129 )
{
struct V_26 * V_27 = F_43 ( V_129 , struct V_26 , V_93 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
T_1 * V_74 = V_27 -> V_133 ;
int V_42 ;
if ( V_27 -> V_28 & V_30 ) {
memset ( V_74 , 0 , V_143 ) ;
V_74 [ 0 ] = 0x05 ;
V_74 [ 1 ] = 0xFF ;
V_42 = 4 ;
} else {
memset ( V_74 , 0 , V_144 ) ;
V_74 [ 0 ] = 0x11 ;
V_74 [ 1 ] = 0x80 ;
V_74 [ 3 ] = 0x0F ;
V_42 = 6 ;
}
#ifdef F_55
V_74 [ V_42 ++ ] = V_27 -> V_136 ;
V_74 [ V_42 ++ ] = V_27 -> V_138 ;
#else
V_42 += 2 ;
#endif
if ( V_27 -> V_86 [ 3 ] ) {
V_74 [ V_42 ++ ] = V_27 -> V_86 [ 0 ] ;
V_74 [ V_42 ++ ] = V_27 -> V_86 [ 1 ] ;
V_74 [ V_42 ++ ] = V_27 -> V_86 [ 2 ] ;
} else {
V_42 += 3 ;
}
V_74 [ V_42 ++ ] = V_27 -> V_105 [ 3 ] ;
V_74 [ V_42 ++ ] = V_27 -> V_106 [ 3 ] ;
if ( V_27 -> V_28 & V_30 )
F_30 ( V_2 , V_74 , V_143 ) ;
else
F_29 ( V_2 , 0x11 , V_74 , V_144 ,
V_91 , V_80 ) ;
}
static void F_57 ( struct V_128 * V_129 )
{
struct V_26 * V_27 = F_43 ( V_129 , struct V_26 , V_93 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_145 * V_61 =
(struct V_145 * ) V_27 -> V_133 ;
memset ( V_61 , 0 , V_146 ) ;
V_61 -> type = 0x02 ;
V_61 -> V_147 = V_27 -> V_86 [ 0 ] ;
V_61 -> V_148 = V_27 -> V_86 [ 1 ] ;
V_61 -> V_149 = V_27 -> V_86 [ 2 ] ;
#ifdef F_55
V_61 -> V_134 = V_16 ( V_27 -> V_136 , V_27 -> V_138 ) ;
#endif
F_30 ( V_2 , ( T_1 * ) V_61 , V_146 ) ;
}
static int F_58 ( struct V_26 * V_27 )
{
if ( ( V_27 -> V_28 & V_34 ) ||
( V_27 -> V_28 & V_36 ) )
V_27 -> V_133 =
F_28 ( sizeof( union V_130 ) ,
V_75 ) ;
else if ( V_27 -> V_28 & V_32 )
V_27 -> V_133 = F_28 ( V_144 ,
V_75 ) ;
else if ( V_27 -> V_28 & V_30 )
V_27 -> V_133 = F_28 ( V_143 ,
V_75 ) ;
else if ( V_27 -> V_28 & V_35 )
V_27 -> V_133 = F_28 ( V_146 ,
V_75 ) ;
else
return 0 ;
if ( ! V_27 -> V_133 )
return - V_76 ;
return 0 ;
}
static int F_59 ( struct V_52 * V_98 , void * V_150 ,
struct V_151 * V_152 )
{
struct V_1 * V_18 = F_60 ( V_98 ) ;
struct V_26 * V_27 = F_9 ( V_18 ) ;
if ( V_152 -> type != V_153 )
return 0 ;
V_27 -> V_138 = V_152 -> V_154 . V_134 . V_155 / 256 ;
V_27 -> V_136 = V_152 -> V_154 . V_134 . V_156 / 256 ;
F_41 ( & V_27 -> V_93 ) ;
return 0 ;
}
static int F_61 ( struct V_26 * V_27 )
{
struct V_9 * V_48 = F_15 ( V_27 -> V_2 -> V_49 . V_50 ,
struct V_9 , V_51 ) ;
struct V_52 * V_52 = V_48 -> V_53 ;
F_62 ( V_52 , V_157 , V_153 ) ;
return F_63 ( V_52 , NULL , F_59 ) ;
}
static int F_61 ( struct V_26 * V_27 )
{
return 0 ;
}
static int F_64 ( struct V_158 * V_159 ,
enum V_160 V_161 ,
union V_162 * V_163 )
{
struct V_26 * V_27 = F_65 ( V_159 ) ;
unsigned long V_41 ;
int V_69 = 0 ;
T_2 V_45 , V_44 , V_43 ;
F_12 ( & V_27 -> V_47 , V_41 ) ;
V_45 = V_27 -> V_45 ;
V_44 = V_27 -> V_44 ;
V_43 = V_27 -> V_43 ;
F_13 ( & V_27 -> V_47 , V_41 ) ;
switch ( V_161 ) {
case V_164 :
V_163 -> V_165 = 1 ;
break;
case V_166 :
V_163 -> V_165 = V_167 ;
break;
case V_168 :
V_163 -> V_165 = V_44 ;
break;
case V_169 :
if ( V_45 )
V_163 -> V_165 = V_170 ;
else
if ( V_44 == 100 && V_43 )
V_163 -> V_165 = V_171 ;
else
V_163 -> V_165 = V_172 ;
break;
default:
V_69 = - V_62 ;
break;
}
return V_69 ;
}
static int F_66 ( struct V_26 * V_27 )
{
struct V_173 V_174 = { . V_100 = V_27 , } ;
struct V_1 * V_2 = V_27 -> V_2 ;
int V_69 ;
V_27 -> V_44 = 100 ;
V_27 -> V_175 . V_176 = V_177 ;
V_27 -> V_175 . V_178 = F_6 ( V_177 ) ;
V_27 -> V_175 . V_179 = F_64 ;
V_27 -> V_175 . type = V_180 ;
V_27 -> V_175 . V_181 = 0 ;
V_27 -> V_175 . V_115 = F_67 ( V_75 ,
L_20 ,
V_27 -> V_182 ) ;
if ( ! V_27 -> V_175 . V_115 )
return - V_76 ;
V_27 -> V_183 = F_68 ( & V_2 -> V_98 , & V_27 -> V_175 ,
& V_174 ) ;
if ( F_69 ( V_27 -> V_183 ) ) {
V_69 = F_70 ( V_27 -> V_183 ) ;
F_26 ( V_2 , L_21 ) ;
goto V_184;
}
F_71 ( V_27 -> V_183 , & V_2 -> V_98 ) ;
return 0 ;
V_184:
F_31 ( V_27 -> V_175 . V_115 ) ;
V_27 -> V_175 . V_115 = NULL ;
return V_69 ;
}
static void F_72 ( struct V_26 * V_27 )
{
if ( ! V_27 -> V_175 . V_115 )
return;
F_73 ( V_27 -> V_183 ) ;
F_31 ( V_27 -> V_175 . V_115 ) ;
V_27 -> V_175 . V_115 = NULL ;
}
static int F_74 ( struct V_26 * V_27 )
{
struct V_26 * V_185 ;
unsigned long V_41 ;
int V_69 ;
F_12 ( & V_186 , V_41 ) ;
F_75 (entry, &sony_device_list, list_node) {
V_69 = memcmp ( V_27 -> V_182 , V_185 -> V_182 ,
sizeof( V_27 -> V_182 ) ) ;
if ( ! V_69 ) {
V_69 = - V_187 ;
F_10 ( V_27 -> V_2 , L_22 ,
V_27 -> V_182 ) ;
goto V_188;
}
}
V_69 = 0 ;
F_76 ( & ( V_27 -> V_189 ) , & V_190 ) ;
V_188:
F_13 ( & V_186 , V_41 ) ;
return V_69 ;
}
static void F_77 ( struct V_26 * V_27 )
{
unsigned long V_41 ;
if ( V_27 -> V_189 . V_50 ) {
F_12 ( & V_186 , V_41 ) ;
F_78 ( & ( V_27 -> V_189 ) ) ;
F_13 ( & V_186 , V_41 ) ;
}
}
static int F_79 ( struct V_26 * V_27 )
{
int V_69 ;
V_69 = strlen ( V_27 -> V_2 -> V_191 ) ;
if ( V_69 != 17 )
return - V_62 ;
V_69 = sscanf ( V_27 -> V_2 -> V_191 ,
L_23 ,
& V_27 -> V_182 [ 5 ] , & V_27 -> V_182 [ 4 ] , & V_27 -> V_182 [ 3 ] ,
& V_27 -> V_182 [ 2 ] , & V_27 -> V_182 [ 1 ] , & V_27 -> V_182 [ 0 ] ) ;
if ( V_69 != 6 )
return - V_62 ;
return 0 ;
}
static int F_80 ( struct V_26 * V_27 )
{
T_1 * V_74 = NULL ;
int V_54 , V_69 ;
if ( ( V_27 -> V_28 & V_32 ) ||
( V_27 -> V_28 & V_63 ) ||
( V_27 -> V_28 & V_192 ) ||
( V_27 -> V_28 & V_193 ) ) {
if ( F_79 ( V_27 ) < 0 ) {
F_81 ( V_27 -> V_2 , L_24 ) ;
return 0 ;
}
} else if ( V_27 -> V_28 & V_30 ) {
V_74 = F_28 ( V_194 , V_75 ) ;
if ( ! V_74 )
return - V_76 ;
V_69 = F_29 ( V_27 -> V_2 , 0x81 , V_74 ,
V_194 , V_77 ,
V_78 ) ;
if ( V_69 != V_194 ) {
F_26 ( V_27 -> V_2 , L_25 ) ;
V_69 = V_69 < 0 ? V_69 : - V_62 ;
goto V_195;
}
memcpy ( V_27 -> V_182 , & V_74 [ 1 ] , sizeof( V_27 -> V_182 ) ) ;
} else if ( ( V_27 -> V_28 & V_102 ) ||
( V_27 -> V_28 & V_196 ) ) {
V_74 = F_28 ( V_72 , V_75 ) ;
if ( ! V_74 )
return - V_76 ;
V_69 = F_29 ( V_27 -> V_2 , 0xf2 , V_74 ,
V_72 , V_77 ,
V_78 ) ;
if ( V_69 != V_72 ) {
F_26 ( V_27 -> V_2 , L_26 ) ;
V_69 = V_69 < 0 ? V_69 : - V_62 ;
goto V_195;
}
for ( V_54 = 0 ; V_54 < 6 ; V_54 ++ )
V_27 -> V_182 [ 5 - V_54 ] = V_74 [ 4 + V_54 ] ;
} else {
return 0 ;
}
V_69 = F_74 ( V_27 ) ;
V_195:
F_31 ( V_74 ) ;
return V_69 ;
}
static int F_82 ( struct V_26 * V_27 )
{
int V_69 ;
if ( ( V_27 -> V_28 & V_34 ) ||
( V_27 -> V_28 & V_70 ) ) {
V_69 = F_83 ( & V_197 , 0 , 0 ,
V_75 ) ;
if ( V_69 < 0 ) {
V_27 -> V_84 = - 1 ;
return V_69 ;
}
V_27 -> V_84 = V_69 ;
} else {
V_27 -> V_84 = - 1 ;
}
return 0 ;
}
static void F_84 ( struct V_26 * V_27 )
{
if ( V_27 -> V_84 >= 0 ) {
F_85 ( & V_197 , V_27 -> V_84 ) ;
V_27 -> V_84 = - 1 ;
}
}
static inline void F_86 ( struct V_26 * V_27 ,
void (* F_87)( struct V_128 * ) )
{
if ( ! V_27 -> V_198 )
F_88 ( & V_27 -> V_93 , F_87 ) ;
V_27 -> V_198 = 1 ;
}
static inline void F_89 ( struct V_26 * V_27 )
{
if ( V_27 -> V_198 )
F_90 ( & V_27 -> V_93 ) ;
}
static int F_91 ( struct V_1 * V_2 , const struct V_199 * V_83 )
{
int V_69 ;
unsigned long V_28 = V_83 -> V_200 ;
struct V_26 * V_27 ;
unsigned int V_201 = V_202 ;
V_27 = F_92 ( & V_2 -> V_98 , sizeof( * V_27 ) , V_75 ) ;
if ( V_27 == NULL ) {
F_26 ( V_2 , L_27 ) ;
return - V_76 ;
}
F_93 ( & V_27 -> V_47 ) ;
V_27 -> V_28 = V_28 ;
F_94 ( V_2 , V_27 ) ;
V_27 -> V_2 = V_2 ;
V_69 = F_95 ( V_2 ) ;
if ( V_69 ) {
F_26 ( V_2 , L_28 ) ;
return V_69 ;
}
if ( V_27 -> V_28 & V_29 )
V_201 |= V_203 ;
else if ( V_27 -> V_28 & V_34 )
V_201 |= V_203 ;
V_69 = F_96 ( V_2 , V_201 ) ;
if ( V_69 ) {
F_26 ( V_2 , L_29 ) ;
return V_69 ;
}
V_69 = F_82 ( V_27 ) ;
if ( V_69 < 0 ) {
F_26 ( V_2 , L_30 ) ;
goto V_204;
}
V_69 = F_58 ( V_27 ) ;
if ( V_69 < 0 ) {
F_26 ( V_2 , L_31 ) ;
goto V_204;
}
if ( ( V_27 -> V_28 & V_102 ) ||
( V_27 -> V_28 & V_196 ) ) {
V_2 -> V_28 |= V_205 ;
V_2 -> V_28 |= V_206 ;
V_69 = F_27 ( V_2 ) ;
F_86 ( V_27 , F_54 ) ;
} else if ( ( V_27 -> V_28 & V_193 ) ||
( V_27 -> V_28 & V_192 ) ) {
V_2 -> V_28 |= V_205 ;
V_69 = F_32 ( V_2 ) ;
F_86 ( V_27 , F_54 ) ;
} else if ( V_27 -> V_28 & V_70 ) {
if ( V_27 -> V_28 & V_32 ) {
V_2 -> V_28 |= V_205 ;
V_69 = F_34 ( V_2 ) ;
if ( V_69 < 0 ) {
F_26 ( V_2 , L_32 ) ;
goto V_204;
}
}
F_86 ( V_27 , F_56 ) ;
} else if ( V_27 -> V_28 & V_35 ) {
F_86 ( V_27 , F_57 ) ;
} else {
V_69 = 0 ;
}
if ( V_69 < 0 )
goto V_204;
V_69 = F_80 ( V_27 ) ;
if ( V_69 < 0 )
goto V_204;
if ( V_27 -> V_28 & V_112 ) {
V_69 = F_49 ( V_27 ) ;
if ( V_69 < 0 )
goto V_204;
}
if ( V_27 -> V_28 & V_207 ) {
V_69 = F_66 ( V_27 ) ;
if ( V_69 < 0 )
goto V_204;
V_69 = F_97 ( V_2 ) ;
if ( V_69 < 0 ) {
F_26 ( V_2 , L_33 ) ;
goto V_204;
}
}
if ( V_27 -> V_28 & V_208 ) {
V_69 = F_61 ( V_27 ) ;
if ( V_69 < 0 )
goto V_209;
}
return 0 ;
V_209:
F_98 ( V_2 ) ;
V_204:
if ( V_27 -> V_28 & V_112 )
F_46 ( V_27 ) ;
if ( V_27 -> V_28 & V_207 )
F_72 ( V_27 ) ;
F_89 ( V_27 ) ;
F_31 ( V_27 -> V_133 ) ;
F_77 ( V_27 ) ;
F_84 ( V_27 ) ;
F_99 ( V_2 ) ;
return V_69 ;
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
if ( V_27 -> V_28 & V_112 )
F_46 ( V_27 ) ;
if ( V_27 -> V_28 & V_207 ) {
F_98 ( V_2 ) ;
F_72 ( V_27 ) ;
}
F_89 ( V_27 ) ;
F_31 ( V_27 -> V_133 ) ;
F_77 ( V_27 ) ;
F_84 ( V_27 ) ;
F_99 ( V_2 ) ;
}
static int T_6 F_101 ( void )
{
F_102 ( L_34 , V_210 ) ;
return F_103 ( & V_211 ) ;
}
static void T_7 F_104 ( void )
{
F_102 ( L_34 , V_210 ) ;
F_105 ( & V_211 ) ;
F_106 ( & V_197 ) ;
}
