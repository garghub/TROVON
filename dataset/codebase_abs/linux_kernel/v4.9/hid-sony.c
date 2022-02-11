static inline void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
F_2 ( & V_2 -> V_4 ) ;
}
static T_1 * F_3 ( struct V_5 * V_6 , T_1 * V_7 ,
unsigned int * V_8 )
{
* V_8 = sizeof( V_9 ) ;
return V_9 ;
}
static T_1 * F_4 ( struct V_5 * V_6 , T_1 * V_7 ,
unsigned int * V_8 )
{
* V_8 = sizeof( V_10 ) ;
return V_10 ;
}
static T_1 * F_5 ( struct V_5 * V_6 , T_1 * V_7 ,
unsigned int * V_8 )
{
* V_8 = sizeof( V_11 ) ;
return V_11 ;
}
static T_1 * F_6 ( struct V_5 * V_6 , T_1 * V_7 ,
unsigned int * V_8 )
{
* V_8 = sizeof( V_12 ) ;
return V_12 ;
}
static int F_7 ( struct V_5 * V_6 , struct V_13 * V_14 ,
struct V_15 * V_16 , struct V_17 * V_18 ,
unsigned long * * V_19 , int * V_20 )
{
unsigned int V_21 = V_18 -> V_22 & V_23 ;
if ( ( V_18 -> V_22 & V_24 ) != V_25 )
return - 1 ;
switch ( V_18 -> V_26 ) {
case 1 :
if ( V_21 >= F_8 ( V_27 ) )
return - 1 ;
V_21 = V_27 [ V_21 ] ;
if ( ! V_21 )
return - 1 ;
break;
case 2 :
if ( V_21 >= F_8 ( V_28 ) )
return - 1 ;
V_21 = V_28 [ V_21 ] ;
if ( ! V_21 )
return - 1 ;
break;
default:
return - 1 ;
}
F_9 ( V_14 , V_18 , V_19 , V_20 , V_29 , V_21 ) ;
return 1 ;
}
static T_1 * F_10 ( struct V_5 * V_6 , T_1 * V_7 ,
unsigned int * V_8 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
if ( V_2 -> V_30 & ( V_31 | V_32 ) )
return V_7 ;
if ( ( V_2 -> V_30 & V_33 ) && * V_8 >= 56 &&
V_7 [ 2 ] == 0x09 && V_7 [ 3 ] == 0x02 &&
V_7 [ 54 ] == 0x81 && V_7 [ 55 ] == 0x07 ) {
F_12 ( V_6 , L_1 ) ;
V_7 [ 55 ] = 0x06 ;
}
if ( V_2 -> V_30 & V_34 ) {
F_12 ( V_6 , L_2 ) ;
V_7 = V_35 ;
* V_8 = sizeof( V_35 ) ;
} else if ( V_2 -> V_30 & V_36 ) {
F_12 ( V_6 , L_3 ) ;
V_7 = V_37 ;
* V_8 = sizeof( V_37 ) ;
}
if ( V_2 -> V_30 & V_38 )
return F_3 ( V_6 , V_7 , V_8 ) ;
if ( V_2 -> V_30 & V_39 )
return F_4 ( V_6 , V_7 , V_8 ) ;
if ( V_2 -> V_30 & V_40 )
return F_5 ( V_6 , V_7 , V_8 ) ;
if ( V_2 -> V_30 & V_41 )
return F_6 ( V_6 , V_7 , V_8 ) ;
return V_7 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 * V_42 , int V_43 )
{
static const T_1 V_44 [] = { 0 , 1 , 25 , 50 , 75 , 100 } ;
unsigned long V_45 ;
int V_46 ;
T_1 V_47 , V_48 , V_49 ;
V_46 = ( V_2 -> V_30 & V_39 ) ? 12 : 30 ;
if ( V_42 [ V_46 ] >= 0xee ) {
V_48 = 100 ;
V_49 = ! ( V_42 [ V_46 ] & 0x01 ) ;
V_47 = 1 ;
} else {
T_1 V_50 = V_42 [ V_46 ] <= 5 ? V_42 [ V_46 ] : 5 ;
V_48 = V_44 [ V_50 ] ;
V_49 = 0 ;
V_47 = 0 ;
}
F_14 ( & V_2 -> V_51 , V_45 ) ;
V_2 -> V_47 = V_47 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_49 = V_49 ;
F_15 ( & V_2 -> V_51 , V_45 ) ;
}
static void F_16 ( struct V_1 * V_2 , T_1 * V_42 , int V_43 )
{
struct V_13 * V_52 = F_17 ( V_2 -> V_6 -> V_53 . V_54 ,
struct V_13 , V_55 ) ;
struct V_56 * V_56 = V_52 -> V_57 ;
unsigned long V_45 ;
int V_58 , V_46 ;
T_1 V_47 , V_48 , V_49 ;
V_46 = ( V_2 -> V_30 & V_34 ) ? 30 : 32 ;
V_47 = ( V_42 [ V_46 ] >> 4 ) & 0x01 ;
V_48 = V_42 [ V_46 ] & 0x0F ;
if ( ! V_47 || V_48 > 10 )
V_49 = 0 ;
else
V_49 = 1 ;
if ( ! V_47 )
V_48 ++ ;
if ( V_48 > 10 )
V_48 = 10 ;
V_48 *= 10 ;
F_14 ( & V_2 -> V_51 , V_45 ) ;
V_2 -> V_47 = V_47 ;
V_2 -> V_48 = V_48 ;
V_2 -> V_49 = V_49 ;
F_15 ( & V_2 -> V_51 , V_45 ) ;
V_46 += 5 ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
T_2 V_59 , V_60 ;
V_59 = V_42 [ V_46 + 1 ] | ( ( V_42 [ V_46 + 2 ] & 0xF ) << 8 ) ;
V_60 = ( ( V_42 [ V_46 + 2 ] & 0xF0 ) >> 4 ) | ( V_42 [ V_46 + 3 ] << 4 ) ;
F_18 ( V_56 , V_58 ) ;
F_19 ( V_56 , V_61 ,
! ( V_42 [ V_46 ] >> 7 ) ) ;
F_20 ( V_56 , V_62 , V_59 ) ;
F_20 ( V_56 , V_63 , V_60 ) ;
V_46 += 4 ;
}
}
static int F_21 ( struct V_5 * V_6 , struct V_64 * V_65 ,
T_1 * V_42 , int V_43 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
if ( ( V_2 -> V_30 & V_38 ) && V_42 [ 0 ] == 0x01 && V_43 == 49 ) {
if ( V_42 [ 1 ] == 0xff )
return - V_66 ;
F_22 ( V_42 [ 41 ] , V_42 [ 42 ] ) ;
F_22 ( V_42 [ 43 ] , V_42 [ 44 ] ) ;
F_22 ( V_42 [ 45 ] , V_42 [ 46 ] ) ;
F_22 ( V_42 [ 47 ] , V_42 [ 48 ] ) ;
F_13 ( V_2 , V_42 , V_43 ) ;
} else if ( ( V_2 -> V_30 & V_67 ) && V_42 [ 0 ] == 0x01 && V_43 == 49 ) {
F_13 ( V_2 , V_42 , V_43 ) ;
} else if ( ( V_2 -> V_30 & V_40 ) && V_42 [ 0 ] == 0x01 &&
V_43 == 49 ) {
F_13 ( V_2 , V_42 , V_43 ) ;
} else if ( ( ( V_2 -> V_30 & V_34 ) && V_42 [ 0 ] == 0x01 &&
V_43 == 64 ) || ( ( V_2 -> V_30 & V_36 )
&& V_42 [ 0 ] == 0x11 && V_43 == 78 ) ) {
F_16 ( V_2 , V_42 , V_43 ) ;
}
if ( V_2 -> V_3 ) {
V_2 -> V_3 = 0 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_23 ( struct V_5 * V_6 , struct V_13 * V_14 ,
struct V_15 * V_16 , struct V_17 * V_18 ,
unsigned long * * V_19 , int * V_20 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
if ( V_2 -> V_30 & V_68 ) {
unsigned int V_21 = V_18 -> V_22 & V_23 ;
if ( ( V_18 -> V_22 & V_24 ) != V_25 )
return - 1 ;
switch ( V_18 -> V_26 ) {
case 1 :
if ( V_21 >= F_8 ( V_69 ) )
return - 1 ;
V_21 = V_69 [ V_21 ] ;
if ( ! V_21 )
return - 1 ;
break;
default:
return - 1 ;
}
F_9 ( V_14 , V_18 , V_19 , V_20 , V_29 , V_21 ) ;
return 1 ;
}
if ( V_2 -> V_30 & V_41 )
return F_7 ( V_6 , V_14 , V_16 , V_18 , V_19 , V_20 ) ;
return 0 ;
}
static int F_24 ( struct V_13 * V_14 , int V_70 ,
int V_71 , int V_72 )
{
struct V_56 * V_56 = V_14 -> V_57 ;
int V_73 ;
V_73 = F_25 ( V_56 , V_70 , 0 ) ;
if ( V_73 < 0 )
return V_73 ;
F_26 ( V_56 , V_62 , 0 , V_71 , 0 , 0 ) ;
F_26 ( V_56 , V_63 , 0 , V_72 , 0 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_13 * V_52 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
int V_73 ;
if ( V_2 -> V_30 & V_74 ) {
V_73 = F_24 ( V_52 , 2 , 1920 , 942 ) ;
if ( V_73 ) {
F_28 ( V_2 -> V_6 ,
L_4 ,
V_73 ) ;
return V_73 ;
}
}
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
const int V_75 =
V_20 ( V_76 , V_77 ) ;
T_1 * V_78 ;
int V_73 ;
V_78 = F_30 ( V_75 , V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_73 = F_31 ( V_6 , 0xf2 , V_78 , V_76 ,
V_81 , V_82 ) ;
if ( V_73 < 0 ) {
F_28 ( V_6 , L_5 ) ;
goto V_83;
}
V_73 = F_31 ( V_6 , 0xf5 , V_78 , V_77 ,
V_81 , V_82 ) ;
if ( V_73 < 0 ) {
F_28 ( V_6 , L_6 ) ;
goto V_83;
}
V_73 = F_32 ( V_6 , V_78 , 1 ) ;
if ( V_73 < 0 ) {
F_12 ( V_6 , L_7 ) ;
V_73 = 0 ;
}
V_83:
F_33 ( V_78 ) ;
return V_73 ;
}
static int F_34 ( struct V_5 * V_6 )
{
static const T_1 V_65 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
T_1 * V_78 ;
int V_73 ;
V_78 = F_35 ( V_65 , sizeof( V_65 ) , V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_73 = F_31 ( V_6 , V_78 [ 0 ] , V_78 , sizeof( V_65 ) ,
V_81 , V_84 ) ;
F_33 ( V_78 ) ;
return V_73 ;
}
static int F_36 ( struct V_5 * V_6 )
{
T_1 * V_78 ;
int V_73 ;
V_78 = F_30 ( V_85 , V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_73 = F_31 ( V_6 , 0x02 , V_78 , V_85 ,
V_81 , V_82 ) ;
F_33 ( V_78 ) ;
return V_73 ;
}
static void F_37 ( struct V_1 * V_2 )
{
static const T_1 V_86 [ 10 ] [ 4 ] = {
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
int V_87 = V_2 -> V_88 ;
F_38 ( V_89 < F_8 ( V_86 [ 0 ] ) ) ;
if ( V_87 < 0 )
return;
V_87 %= 10 ;
memcpy ( V_2 -> V_90 , V_86 [ V_87 ] , sizeof( V_86 [ V_87 ] ) ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
static const T_1 V_91 [ 7 ] [ 3 ] = {
{ 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 } ,
{ 0x02 , 0x00 , 0x01 } ,
{ 0x02 , 0x01 , 0x00 } ,
{ 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 }
} ;
int V_87 = V_2 -> V_88 ;
F_38 ( V_89 < F_8 ( V_91 [ 0 ] ) ) ;
if ( V_87 < 0 )
return;
V_87 %= 7 ;
memcpy ( V_2 -> V_90 , V_91 [ V_87 ] , sizeof( V_91 [ V_87 ] ) ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_92 * V_93 =
& V_6 -> V_94 [ V_95 ] . V_93 ;
struct V_64 * V_65 = F_17 ( V_93 -> V_54 ,
struct V_64 , V_55 ) ;
T_3 * V_96 = V_65 -> V_16 [ 0 ] -> V_96 ;
F_38 ( V_89 < 4 ) ;
V_96 [ 0 ] = 0x00 ;
V_96 [ 1 ] = V_2 -> V_90 [ 0 ] ? 0xff : 0x00 ;
V_96 [ 2 ] = V_2 -> V_90 [ 1 ] ? 0xff : 0x00 ;
V_96 [ 3 ] = V_2 -> V_90 [ 2 ] ? 0xff : 0x00 ;
V_96 [ 4 ] = V_2 -> V_90 [ 3 ] ? 0xff : 0x00 ;
V_96 [ 5 ] = 0x00 ;
V_96 [ 6 ] = 0x00 ;
F_41 ( V_6 , V_65 , V_84 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_30 & V_68 ) )
F_1 ( V_2 ) ;
else
F_40 ( V_2 ) ;
}
static void F_43 ( struct V_97 * V_98 ,
enum V_99 V_96 )
{
struct V_100 * V_101 = V_98 -> V_101 -> V_102 ;
struct V_5 * V_6 = F_44 ( V_101 ) ;
struct V_1 * V_103 ;
int V_58 ;
int V_104 ;
V_103 = F_11 ( V_6 ) ;
if ( ! V_103 ) {
F_28 ( V_6 , L_8 ) ;
return;
}
V_104 = ! ! ( V_103 -> V_30 & V_105 ) ;
for ( V_58 = 0 ; V_58 < V_103 -> V_106 ; V_58 ++ ) {
if ( V_98 == V_103 -> V_107 [ V_58 ] && ( V_104 ||
( V_96 != V_103 -> V_90 [ V_58 ] ||
V_103 -> V_108 [ V_58 ] ||
V_103 -> V_109 [ V_58 ] ) ) ) {
V_103 -> V_90 [ V_58 ] = V_96 ;
V_103 -> V_108 [ V_58 ] = 0 ;
V_103 -> V_109 [ V_58 ] = 0 ;
F_42 ( V_103 ) ;
break;
}
}
}
static enum V_99 F_45 ( struct V_97 * V_98 )
{
struct V_100 * V_101 = V_98 -> V_101 -> V_102 ;
struct V_5 * V_6 = F_44 ( V_101 ) ;
struct V_1 * V_103 ;
int V_58 ;
V_103 = F_11 ( V_6 ) ;
if ( ! V_103 ) {
F_28 ( V_6 , L_8 ) ;
return V_110 ;
}
for ( V_58 = 0 ; V_58 < V_103 -> V_106 ; V_58 ++ ) {
if ( V_98 == V_103 -> V_107 [ V_58 ] )
return V_103 -> V_90 [ V_58 ] ;
}
return V_110 ;
}
static int F_46 ( struct V_97 * V_98 , unsigned long * V_111 ,
unsigned long * V_112 )
{
struct V_100 * V_101 = V_98 -> V_101 -> V_102 ;
struct V_5 * V_6 = F_44 ( V_101 ) ;
struct V_1 * V_103 = F_11 ( V_6 ) ;
int V_58 ;
T_1 V_113 , V_114 ;
if ( ! V_103 ) {
F_28 ( V_6 , L_8 ) ;
return - V_66 ;
}
if ( * V_111 > 2550 )
* V_111 = 2550 ;
if ( * V_112 > 2550 )
* V_112 = 2550 ;
if ( ! * V_111 && ! * V_112 )
* V_111 = * V_112 = 500 ;
V_113 = * V_111 / 10 ;
V_114 = * V_112 / 10 ;
for ( V_58 = 0 ; V_58 < V_103 -> V_106 ; V_58 ++ ) {
if ( V_98 == V_103 -> V_107 [ V_58 ] )
break;
}
if ( V_58 >= V_103 -> V_106 )
return - V_66 ;
if ( V_113 != V_103 -> V_108 [ V_58 ] ||
V_114 != V_103 -> V_109 [ V_58 ] ) {
V_103 -> V_108 [ V_58 ] = V_113 ;
V_103 -> V_109 [ V_58 ] = V_114 ;
F_1 ( V_103 ) ;
}
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_97 * V_98 ;
int V_58 ;
F_48 ( ! ( V_2 -> V_30 & V_115 ) ) ;
for ( V_58 = 0 ; V_58 < V_2 -> V_106 ; V_58 ++ ) {
V_98 = V_2 -> V_107 [ V_58 ] ;
V_2 -> V_107 [ V_58 ] = NULL ;
if ( ! V_98 )
continue;
F_49 ( V_98 ) ;
F_33 ( V_98 ) ;
}
V_2 -> V_106 = 0 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_58 , V_73 = 0 ;
int V_116 ;
struct V_97 * V_98 ;
T_4 V_117 ;
char * V_118 ;
T_4 V_119 ;
const char * V_120 ;
static const char * const V_121 [] = { L_9 , L_10 , L_11 ,
L_12 } ;
T_1 V_122 [ V_89 ] = { [ 0 ... ( V_89 - 1 ) ] = 1 } ;
T_1 V_123 [ V_89 ] = { 0 } ;
F_48 ( ! ( V_2 -> V_30 & V_115 ) ) ;
if ( V_2 -> V_30 & V_68 ) {
V_2 -> V_106 = 4 ;
V_116 = 0 ;
V_119 = strlen ( L_13 ) ;
V_120 = L_14 ;
if ( ! F_51 ( V_6 , V_95 , 0 , 0 , 7 ) )
return - V_124 ;
} else if ( V_2 -> V_30 & V_74 ) {
F_39 ( V_2 ) ;
V_2 -> V_90 [ 3 ] = 1 ;
V_2 -> V_106 = 4 ;
memset ( V_122 , 255 , 3 ) ;
V_123 [ 3 ] = 1 ;
V_116 = 1 ;
V_119 = 0 ;
V_120 = L_15 ;
} else if ( V_2 -> V_30 & V_39 ) {
V_2 -> V_106 = 3 ;
memset ( V_122 , 255 , 3 ) ;
V_116 = 1 ;
V_119 = 0 ;
V_120 = L_15 ;
} else if ( V_2 -> V_30 & V_40 ) {
static const T_1 V_125 [ 4 ] = { 0x01 , 0x00 , 0x00 , 0x00 } ;
memcpy ( V_2 -> V_90 , V_125 , sizeof( V_125 ) ) ;
V_2 -> V_106 = 1 ;
memset ( V_123 , 1 , 4 ) ;
V_116 = 0 ;
V_119 = strlen ( L_16 ) ;
V_120 = L_17 ;
} else {
F_37 ( V_2 ) ;
V_2 -> V_106 = 4 ;
memset ( V_123 , 1 , 4 ) ;
V_116 = 0 ;
V_119 = strlen ( L_16 ) ;
V_120 = L_17 ;
}
F_42 ( V_2 ) ;
V_117 = strlen ( F_52 ( & V_6 -> V_101 ) ) + V_119 + 1 ;
for ( V_58 = 0 ; V_58 < V_2 -> V_106 ; V_58 ++ ) {
if ( V_116 )
V_117 = strlen ( F_52 ( & V_6 -> V_101 ) ) + strlen ( V_121 [ V_58 ] ) + 2 ;
V_98 = F_53 ( sizeof( struct V_97 ) + V_117 , V_79 ) ;
if ( ! V_98 ) {
F_28 ( V_6 , L_18 , V_58 ) ;
V_73 = - V_80 ;
goto V_126;
}
V_118 = ( void * ) ( & V_98 [ 1 ] ) ;
if ( V_116 )
snprintf ( V_118 , V_117 , V_120 , F_52 ( & V_6 -> V_101 ) ,
V_121 [ V_58 ] ) ;
else
snprintf ( V_118 , V_117 , V_120 , F_52 ( & V_6 -> V_101 ) , V_58 + 1 ) ;
V_98 -> V_118 = V_118 ;
V_98 -> V_127 = V_2 -> V_90 [ V_58 ] ;
V_98 -> V_122 = V_122 [ V_58 ] ;
V_98 -> V_128 = F_45 ;
V_98 -> V_129 = F_43 ;
if ( V_123 [ V_58 ] )
V_98 -> V_130 = F_46 ;
V_2 -> V_107 [ V_58 ] = V_98 ;
V_73 = F_54 ( & V_6 -> V_101 , V_98 ) ;
if ( V_73 ) {
F_28 ( V_6 , L_19 , V_58 ) ;
V_2 -> V_107 [ V_58 ] = NULL ;
F_33 ( V_98 ) ;
goto V_126;
}
}
return V_73 ;
V_126:
F_47 ( V_2 ) ;
return V_73 ;
}
static void F_55 ( struct V_1 * V_2 )
{
static const union V_131 V_132 = {
. V_78 = {
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
struct V_133 * V_65 =
(struct V_133 * ) V_2 -> V_134 ;
int V_58 ;
memcpy ( V_65 , & V_132 , sizeof( struct V_133 ) ) ;
#ifdef F_56
V_65 -> V_135 . V_136 = V_2 -> V_137 ? 1 : 0 ;
V_65 -> V_135 . V_138 = V_2 -> V_139 ;
#endif
V_65 -> V_140 |= V_2 -> V_90 [ 0 ] << 1 ;
V_65 -> V_140 |= V_2 -> V_90 [ 1 ] << 2 ;
V_65 -> V_140 |= V_2 -> V_90 [ 2 ] << 3 ;
V_65 -> V_140 |= V_2 -> V_90 [ 3 ] << 4 ;
if ( ( V_65 -> V_140 & 0x1E ) == 0 )
V_65 -> V_140 |= 0x20 ;
for ( V_58 = 0 ; V_58 < 4 ; V_58 ++ ) {
if ( V_2 -> V_108 [ V_58 ] || V_2 -> V_109 [ V_58 ] ) {
V_65 -> V_98 [ 3 - V_58 ] . V_141 = V_2 -> V_109 [ V_58 ] ;
V_65 -> V_98 [ 3 - V_58 ] . V_142 = V_2 -> V_108 [ V_58 ] ;
}
}
F_31 ( V_2 -> V_6 , V_65 -> V_143 , ( T_1 * ) V_65 ,
sizeof( struct V_133 ) ,
V_95 , V_84 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 * V_78 = V_2 -> V_134 ;
int V_46 ;
if ( V_2 -> V_30 & V_34 ) {
memset ( V_78 , 0 , V_144 ) ;
V_78 [ 0 ] = 0x05 ;
V_78 [ 1 ] = 0xFF ;
V_46 = 4 ;
} else {
memset ( V_78 , 0 , V_145 ) ;
V_78 [ 0 ] = 0x11 ;
V_78 [ 1 ] = 0x80 ;
V_78 [ 3 ] = 0x0F ;
V_46 = 6 ;
}
#ifdef F_56
V_78 [ V_46 ++ ] = V_2 -> V_137 ;
V_78 [ V_46 ++ ] = V_2 -> V_139 ;
#else
V_46 += 2 ;
#endif
if ( V_2 -> V_90 [ 3 ] ) {
V_78 [ V_46 ++ ] = V_2 -> V_90 [ 0 ] ;
V_78 [ V_46 ++ ] = V_2 -> V_90 [ 1 ] ;
V_78 [ V_46 ++ ] = V_2 -> V_90 [ 2 ] ;
} else {
V_46 += 3 ;
}
V_78 [ V_46 ++ ] = V_2 -> V_108 [ 3 ] ;
V_78 [ V_46 ++ ] = V_2 -> V_109 [ 3 ] ;
if ( V_2 -> V_30 & V_34 )
F_32 ( V_6 , V_78 , V_144 ) ;
else
F_31 ( V_6 , 0x11 , V_78 , V_145 ,
V_95 , V_84 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_146 * V_65 =
(struct V_146 * ) V_2 -> V_134 ;
memset ( V_65 , 0 , V_147 ) ;
V_65 -> type = 0x02 ;
V_65 -> V_148 = V_2 -> V_90 [ 0 ] ;
V_65 -> V_149 = V_2 -> V_90 [ 1 ] ;
V_65 -> V_150 = V_2 -> V_90 [ 2 ] ;
#ifdef F_56
V_65 -> V_135 = V_20 ( V_2 -> V_137 , V_2 -> V_139 ) ;
#endif
F_32 ( V_6 , ( T_1 * ) V_65 , V_147 ) ;
}
static inline void F_59 ( struct V_1 * V_2 )
{
if ( V_2 -> V_151 )
V_2 -> V_151 ( V_2 ) ;
}
static void F_60 ( struct V_152 * V_153 )
{
struct V_1 * V_2 = F_61 ( V_153 , struct V_1 , V_4 ) ;
V_2 -> V_151 ( V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_30 & V_38 ) ||
( V_2 -> V_30 & V_40 ) )
V_2 -> V_134 =
F_30 ( sizeof( union V_131 ) ,
V_79 ) ;
else if ( V_2 -> V_30 & V_36 )
V_2 -> V_134 = F_30 ( V_145 ,
V_79 ) ;
else if ( V_2 -> V_30 & V_34 )
V_2 -> V_134 = F_30 ( V_144 ,
V_79 ) ;
else if ( V_2 -> V_30 & V_39 )
V_2 -> V_134 = F_30 ( V_147 ,
V_79 ) ;
else
return 0 ;
if ( ! V_2 -> V_134 )
return - V_80 ;
return 0 ;
}
static int F_63 ( struct V_56 * V_101 , void * V_154 ,
struct V_155 * V_156 )
{
struct V_5 * V_22 = F_64 ( V_101 ) ;
struct V_1 * V_2 = F_11 ( V_22 ) ;
if ( V_156 -> type != V_157 )
return 0 ;
V_2 -> V_139 = V_156 -> V_158 . V_135 . V_159 / 256 ;
V_2 -> V_137 = V_156 -> V_158 . V_135 . V_160 / 256 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_13 * V_52 = F_17 ( V_2 -> V_6 -> V_53 . V_54 ,
struct V_13 , V_55 ) ;
struct V_56 * V_56 = V_52 -> V_57 ;
F_66 ( V_56 , V_161 , V_157 ) ;
return F_67 ( V_56 , NULL , F_63 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_68 ( struct V_162 * V_163 ,
enum V_164 V_165 ,
union V_166 * V_167 )
{
struct V_1 * V_2 = F_69 ( V_163 ) ;
unsigned long V_45 ;
int V_73 = 0 ;
T_1 V_49 , V_48 , V_47 ;
F_14 ( & V_2 -> V_51 , V_45 ) ;
V_49 = V_2 -> V_49 ;
V_48 = V_2 -> V_48 ;
V_47 = V_2 -> V_47 ;
F_15 ( & V_2 -> V_51 , V_45 ) ;
switch ( V_165 ) {
case V_168 :
V_167 -> V_169 = 1 ;
break;
case V_170 :
V_167 -> V_169 = V_171 ;
break;
case V_172 :
V_167 -> V_169 = V_48 ;
break;
case V_173 :
if ( V_49 )
V_167 -> V_169 = V_174 ;
else
if ( V_48 == 100 && V_47 )
V_167 -> V_169 = V_175 ;
else
V_167 -> V_169 = V_176 ;
break;
default:
V_73 = - V_66 ;
break;
}
return V_73 ;
}
static int F_70 ( struct V_1 * V_2 , int V_177 )
{
const char * V_178 = V_177 ?
L_20 :
L_21 ;
struct V_179 V_180 = { . V_103 = V_2 , } ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_73 ;
V_2 -> V_48 = 100 ;
V_2 -> V_181 . V_182 = V_183 ;
V_2 -> V_181 . V_184 = F_8 ( V_183 ) ;
V_2 -> V_181 . V_185 = F_68 ;
V_2 -> V_181 . type = V_186 ;
V_2 -> V_181 . V_187 = 0 ;
V_2 -> V_181 . V_118 = F_71 ( V_79 , V_178 ,
V_2 -> V_188 , V_2 -> V_88 ) ;
if ( ! V_2 -> V_181 . V_118 )
return - V_80 ;
V_2 -> V_189 = F_72 ( & V_6 -> V_101 , & V_2 -> V_181 ,
& V_180 ) ;
if ( F_73 ( V_2 -> V_189 ) ) {
V_73 = F_74 ( V_2 -> V_189 ) ;
F_28 ( V_6 , L_22 ) ;
goto V_190;
}
F_75 ( V_2 -> V_189 , & V_6 -> V_101 ) ;
return 0 ;
V_190:
F_33 ( V_2 -> V_181 . V_118 ) ;
V_2 -> V_181 . V_118 = NULL ;
return V_73 ;
}
static void F_76 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_181 . V_118 )
return;
F_77 ( V_2 -> V_189 ) ;
F_33 ( V_2 -> V_181 . V_118 ) ;
V_2 -> V_181 . V_118 = NULL ;
}
static inline int F_78 ( struct V_1 * V_191 ,
struct V_1 * V_192 )
{
const int V_193 = ! ( V_191 -> V_30 & V_194 ) ;
const int V_195 = ! ( V_192 -> V_30 & V_194 ) ;
return V_193 == V_195 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_1 * V_196 ;
unsigned long V_45 ;
int V_73 ;
F_14 ( & V_197 , V_45 ) ;
F_80 (entry, &sony_device_list, list_node) {
V_73 = memcmp ( V_2 -> V_188 , V_196 -> V_188 ,
sizeof( V_2 -> V_188 ) ) ;
if ( ! V_73 ) {
if ( F_78 ( V_2 , V_196 ) ) {
V_73 = 1 ;
} else {
V_73 = - V_198 ;
F_12 ( V_2 -> V_6 ,
L_23 ,
V_2 -> V_188 ) ;
}
goto V_199;
}
}
V_73 = 0 ;
F_81 ( & ( V_2 -> V_200 ) , & V_201 ) ;
V_199:
F_15 ( & V_197 , V_45 ) ;
return V_73 ;
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned long V_45 ;
if ( V_2 -> V_200 . V_54 ) {
F_14 ( & V_197 , V_45 ) ;
F_83 ( & ( V_2 -> V_200 ) ) ;
F_15 ( & V_197 , V_45 ) ;
}
}
static int F_84 ( struct V_1 * V_2 )
{
int V_73 ;
V_73 = strlen ( V_2 -> V_6 -> V_202 ) ;
if ( V_73 != 17 )
return - V_66 ;
V_73 = sscanf ( V_2 -> V_6 -> V_202 ,
L_24 ,
& V_2 -> V_188 [ 5 ] , & V_2 -> V_188 [ 4 ] , & V_2 -> V_188 [ 3 ] ,
& V_2 -> V_188 [ 2 ] , & V_2 -> V_188 [ 1 ] , & V_2 -> V_188 [ 0 ] ) ;
if ( V_73 != 6 )
return - V_66 ;
return 0 ;
}
static int F_85 ( struct V_1 * V_2 )
{
T_1 * V_78 = NULL ;
int V_58 , V_73 ;
if ( ( V_2 -> V_30 & V_36 ) ||
( V_2 -> V_30 & V_67 ) ||
( V_2 -> V_30 & V_203 ) ||
( V_2 -> V_30 & V_204 ) ) {
if ( F_84 ( V_2 ) < 0 ) {
F_86 ( V_2 -> V_6 , L_25 ) ;
return 0 ;
}
} else if ( V_2 -> V_30 & V_34 ) {
V_78 = F_30 ( V_205 , V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_73 = F_31 ( V_2 -> V_6 , 0x81 , V_78 ,
V_205 , V_81 ,
V_82 ) ;
if ( V_73 != V_205 ) {
F_28 ( V_2 -> V_6 , L_26 ) ;
V_73 = V_73 < 0 ? V_73 : - V_66 ;
goto V_206;
}
memcpy ( V_2 -> V_188 , & V_78 [ 1 ] , sizeof( V_2 -> V_188 ) ) ;
} else if ( ( V_2 -> V_30 & V_105 ) ||
( V_2 -> V_30 & V_207 ) ) {
V_78 = F_30 ( V_76 , V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_73 = F_31 ( V_2 -> V_6 , 0xf2 , V_78 ,
V_76 , V_81 ,
V_82 ) ;
if ( V_73 != V_76 ) {
F_28 ( V_2 -> V_6 , L_27 ) ;
V_73 = V_73 < 0 ? V_73 : - V_66 ;
goto V_206;
}
for ( V_58 = 0 ; V_58 < 6 ; V_58 ++ )
V_2 -> V_188 [ 5 - V_58 ] = V_78 [ 4 + V_58 ] ;
} else {
return 0 ;
}
V_73 = F_79 ( V_2 ) ;
V_206:
F_33 ( V_78 ) ;
return V_73 ;
}
static int F_87 ( struct V_1 * V_2 )
{
int V_73 ;
if ( ( V_2 -> V_30 & V_38 ) ||
( V_2 -> V_30 & V_74 ) ) {
V_73 = F_88 ( & V_208 , 0 , 0 ,
V_79 ) ;
if ( V_73 < 0 ) {
V_2 -> V_88 = - 1 ;
return V_73 ;
}
V_2 -> V_88 = V_73 ;
} else {
V_2 -> V_88 = - 1 ;
}
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
if ( V_2 -> V_88 >= 0 ) {
F_90 ( & V_208 , V_2 -> V_88 ) ;
V_2 -> V_88 = - 1 ;
}
}
static inline void F_91 ( struct V_1 * V_2 ,
void (* V_151)( struct V_1 * ) )
{
V_2 -> V_151 = V_151 ;
if ( ! V_2 -> V_209 )
F_92 ( & V_2 -> V_4 , F_60 ) ;
V_2 -> V_209 = 1 ;
}
static inline void F_93 ( struct V_1 * V_2 )
{
if ( V_2 -> V_209 )
F_94 ( & V_2 -> V_4 ) ;
}
static int F_95 ( struct V_5 * V_6 , const struct V_210 * V_87 )
{
int V_73 ;
int V_177 ;
unsigned long V_30 = V_87 -> V_211 ;
struct V_1 * V_2 ;
unsigned int V_212 = V_213 ;
if ( ! strcmp ( V_6 -> V_118 , L_28 ) )
V_30 |= V_32 ;
V_2 = F_96 ( & V_6 -> V_101 , sizeof( * V_2 ) , V_79 ) ;
if ( V_2 == NULL ) {
F_28 ( V_6 , L_29 ) ;
return - V_80 ;
}
F_97 ( & V_2 -> V_51 ) ;
V_2 -> V_30 = V_30 ;
F_98 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_73 = F_99 ( V_6 ) ;
if ( V_73 ) {
F_28 ( V_6 , L_30 ) ;
return V_73 ;
}
if ( V_2 -> V_30 & V_33 )
V_212 |= V_214 ;
else if ( V_2 -> V_30 & V_38 )
V_212 |= V_214 ;
V_73 = F_100 ( V_6 , V_212 ) ;
if ( V_73 ) {
F_28 ( V_6 , L_31 ) ;
return V_73 ;
}
V_73 = F_87 ( V_2 ) ;
if ( V_73 < 0 ) {
F_28 ( V_6 , L_32 ) ;
goto V_215;
}
V_73 = F_62 ( V_2 ) ;
if ( V_73 < 0 ) {
F_28 ( V_6 , L_33 ) ;
goto V_215;
}
if ( ( V_2 -> V_30 & V_105 ) ||
( V_2 -> V_30 & V_207 ) ) {
V_6 -> V_30 |= V_216 ;
V_6 -> V_30 |= V_217 ;
V_2 -> V_3 = 1 ;
V_73 = F_29 ( V_6 ) ;
F_91 ( V_2 , F_55 ) ;
} else if ( ( V_2 -> V_30 & V_204 ) ||
( V_2 -> V_30 & V_203 ) ) {
V_6 -> V_30 |= V_216 ;
V_73 = F_34 ( V_6 ) ;
F_91 ( V_2 , F_55 ) ;
} else if ( V_2 -> V_30 & V_74 ) {
if ( V_2 -> V_30 & V_36 ) {
V_6 -> V_30 |= V_216 ;
V_73 = F_36 ( V_6 ) ;
if ( V_73 < 0 ) {
F_28 ( V_6 , L_34 ) ;
goto V_215;
}
}
F_91 ( V_2 , F_57 ) ;
} else if ( V_2 -> V_30 & V_39 ) {
F_91 ( V_2 , F_58 ) ;
} else {
V_73 = 0 ;
}
if ( V_73 < 0 )
goto V_215;
V_73 = V_177 = F_85 ( V_2 ) ;
if ( V_73 < 0 )
goto V_215;
if ( V_2 -> V_30 & V_115 ) {
V_73 = F_50 ( V_2 ) ;
if ( V_73 < 0 )
goto V_215;
}
if ( V_2 -> V_30 & V_218 ) {
V_73 = F_70 ( V_2 , V_177 ) ;
if ( V_73 < 0 )
goto V_215;
V_73 = F_101 ( V_6 ) ;
if ( V_73 < 0 ) {
F_28 ( V_6 , L_35 ) ;
goto V_215;
}
}
if ( V_2 -> V_30 & V_219 ) {
V_73 = F_65 ( V_2 ) ;
if ( V_73 < 0 )
goto V_220;
}
return 0 ;
V_220:
F_102 ( V_6 ) ;
V_215:
if ( V_2 -> V_30 & V_115 )
F_47 ( V_2 ) ;
if ( V_2 -> V_30 & V_218 )
F_76 ( V_2 ) ;
F_93 ( V_2 ) ;
F_33 ( V_2 -> V_134 ) ;
F_82 ( V_2 ) ;
F_89 ( V_2 ) ;
F_103 ( V_6 ) ;
return V_73 ;
}
static void F_104 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
if ( V_2 -> V_30 & V_115 )
F_47 ( V_2 ) ;
if ( V_2 -> V_30 & V_218 ) {
F_102 ( V_6 ) ;
F_76 ( V_2 ) ;
}
F_93 ( V_2 ) ;
F_33 ( V_2 -> V_134 ) ;
F_82 ( V_2 ) ;
F_89 ( V_2 ) ;
F_103 ( V_6 ) ;
}
static int F_105 ( struct V_5 * V_6 , T_5 V_221 )
{
if ( V_115 || V_219 ) {
struct V_1 * V_2 = F_11 ( V_6 ) ;
#ifdef F_56
V_2 -> V_139 = V_2 -> V_137 = 0 ;
#endif
memcpy ( V_2 -> V_222 , V_2 -> V_90 ,
sizeof( V_2 -> V_222 ) ) ;
memset ( V_2 -> V_90 , 0 , sizeof( V_2 -> V_90 ) ) ;
F_59 ( V_2 ) ;
}
return 0 ;
}
static int F_106 ( struct V_5 * V_6 )
{
if ( V_115 ) {
struct V_1 * V_2 = F_11 ( V_6 ) ;
memcpy ( V_2 -> V_90 , V_2 -> V_222 ,
sizeof( V_2 -> V_90 ) ) ;
if ( ( V_2 -> V_30 & V_105 ) ||
( V_2 -> V_30 & V_207 ) ) {
F_29 ( V_2 -> V_6 ) ;
V_2 -> V_3 = 1 ;
}
F_42 ( V_2 ) ;
}
return 0 ;
}
static int T_6 F_107 ( void )
{
F_108 ( L_36 , V_223 ) ;
return F_109 ( & V_224 ) ;
}
static void T_7 F_110 ( void )
{
F_108 ( L_36 , V_223 ) ;
F_111 ( & V_224 ) ;
F_112 ( & V_208 ) ;
}
