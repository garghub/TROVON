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
static int F_10 ( struct V_5 * V_6 , struct V_13 * V_14 ,
struct V_15 * V_16 , struct V_17 * V_18 ,
unsigned long * * V_19 , int * V_20 )
{
if ( ( V_18 -> V_22 & V_24 ) == V_25 ) {
unsigned int V_21 = V_18 -> V_22 & V_23 ;
if ( V_21 >= F_8 ( V_30 ) )
return - 1 ;
V_21 = V_30 [ V_21 ] ;
F_9 ( V_14 , V_18 , V_19 , V_20 , V_29 , V_21 ) ;
return 1 ;
} else if ( ( V_18 -> V_22 & V_24 ) == V_31 ) {
unsigned int abs = V_18 -> V_22 & V_23 ;
if ( V_18 -> V_22 == V_32 )
return 0 ;
if ( abs >= F_8 ( V_33 ) )
return - 1 ;
abs = V_33 [ abs ] ;
F_9 ( V_14 , V_18 , V_19 , V_20 , V_34 , abs ) ;
return 1 ;
}
return 0 ;
}
static T_1 * F_11 ( struct V_5 * V_6 , T_1 * V_7 ,
unsigned int * V_8 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
if ( V_2 -> V_35 & ( V_36 | V_37 ) )
return V_7 ;
if ( ( V_2 -> V_35 & V_38 ) && * V_8 >= 56 &&
V_7 [ 2 ] == 0x09 && V_7 [ 3 ] == 0x02 &&
V_7 [ 54 ] == 0x81 && V_7 [ 55 ] == 0x07 ) {
F_13 ( V_6 , L_1 ) ;
V_7 [ 55 ] = 0x06 ;
}
if ( V_2 -> V_35 & V_39 ) {
F_13 ( V_6 , L_2 ) ;
V_7 = V_40 ;
* V_8 = sizeof( V_40 ) ;
} else if ( V_2 -> V_35 & V_41 ) {
F_13 ( V_6 , L_3 ) ;
V_7 = V_42 ;
* V_8 = sizeof( V_42 ) ;
}
if ( V_2 -> V_35 & V_43 )
return F_3 ( V_6 , V_7 , V_8 ) ;
if ( V_2 -> V_35 & V_44 )
return F_4 ( V_6 , V_7 , V_8 ) ;
if ( V_2 -> V_35 & V_45 )
return F_5 ( V_6 , V_7 , V_8 ) ;
if ( V_2 -> V_35 & V_46 )
return F_6 ( V_6 , V_7 , V_8 ) ;
return V_7 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 * V_47 , int V_48 )
{
static const T_1 V_49 [] = { 0 , 1 , 25 , 50 , 75 , 100 } ;
unsigned long V_50 ;
int V_51 ;
T_1 V_52 , V_53 , V_54 ;
V_51 = ( V_2 -> V_35 & V_44 ) ? 12 : 30 ;
if ( V_47 [ V_51 ] >= 0xee ) {
V_53 = 100 ;
V_54 = ! ( V_47 [ V_51 ] & 0x01 ) ;
V_52 = 1 ;
} else {
T_1 V_55 = V_47 [ V_51 ] <= 5 ? V_47 [ V_51 ] : 5 ;
V_53 = V_49 [ V_55 ] ;
V_54 = 0 ;
V_52 = 0 ;
}
F_15 ( & V_2 -> V_56 , V_50 ) ;
V_2 -> V_52 = V_52 ;
V_2 -> V_53 = V_53 ;
V_2 -> V_54 = V_54 ;
F_16 ( & V_2 -> V_56 , V_50 ) ;
}
static void F_17 ( struct V_1 * V_2 , T_1 * V_47 , int V_48 )
{
unsigned long V_50 ;
int V_57 , V_58 , V_51 , V_59 , V_60 ;
T_1 V_52 , V_53 , V_54 ;
int V_61 = ( V_2 -> V_35 & V_39 ) ? 0 : 2 ;
V_51 = V_61 + V_62 ;
F_18 ( V_2 -> V_63 , V_64 , V_47 [ V_51 + 2 ] & 0x2 ) ;
V_51 = V_61 + V_65 ;
V_52 = ( V_47 [ V_51 ] >> 4 ) & 0x01 ;
V_53 = V_47 [ V_51 ] & 0x0F ;
if ( ! V_52 || V_53 > 10 )
V_54 = 0 ;
else
V_54 = 1 ;
if ( ! V_52 )
V_53 ++ ;
if ( V_53 > 10 )
V_53 = 10 ;
V_53 *= 10 ;
F_15 ( & V_2 -> V_56 , V_50 ) ;
V_2 -> V_52 = V_52 ;
V_2 -> V_53 = V_53 ;
V_2 -> V_54 = V_54 ;
F_16 ( & V_2 -> V_56 , V_50 ) ;
V_51 = V_61 + V_66 ;
V_60 = ( V_2 -> V_35 & V_39 ) ? 3 : 4 ;
if ( V_47 [ V_51 ] > 0 && V_47 [ V_51 ] <= V_60 )
V_59 = V_47 [ V_51 ] ;
else
V_59 = 1 ;
V_51 += 1 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
V_51 += 1 ;
for ( V_57 = 0 ; V_57 < 2 ; V_57 ++ ) {
T_2 V_67 , V_68 ;
bool V_69 ;
V_67 = V_47 [ V_51 + 1 ] | ( ( V_47 [ V_51 + 2 ] & 0xF ) << 8 ) ;
V_68 = ( ( V_47 [ V_51 + 2 ] & 0xF0 ) >> 4 ) | ( V_47 [ V_51 + 3 ] << 4 ) ;
V_69 = ! ( V_47 [ V_51 ] >> 7 ) ;
F_19 ( V_2 -> V_63 , V_57 ) ;
F_20 ( V_2 -> V_63 , V_70 , V_69 ) ;
if ( V_69 ) {
F_21 ( V_2 -> V_63 , V_71 , V_67 ) ;
F_21 ( V_2 -> V_63 , V_72 , V_68 ) ;
}
V_51 += 4 ;
}
F_22 ( V_2 -> V_63 ) ;
F_23 ( V_2 -> V_63 ) ;
}
}
static int F_24 ( struct V_5 * V_6 , struct V_73 * V_74 ,
T_1 * V_47 , int V_48 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
if ( ( V_2 -> V_35 & V_43 ) && V_47 [ 0 ] == 0x01 && V_48 == 49 ) {
if ( V_47 [ 1 ] == 0xff )
return - V_75 ;
F_25 ( V_47 [ 41 ] , V_47 [ 42 ] ) ;
F_25 ( V_47 [ 43 ] , V_47 [ 44 ] ) ;
F_25 ( V_47 [ 45 ] , V_47 [ 46 ] ) ;
F_25 ( V_47 [ 47 ] , V_47 [ 48 ] ) ;
F_14 ( V_2 , V_47 , V_48 ) ;
} else if ( ( V_2 -> V_35 & V_76 ) && V_47 [ 0 ] == 0x01 && V_48 == 49 ) {
F_14 ( V_2 , V_47 , V_48 ) ;
} else if ( ( V_2 -> V_35 & V_45 ) && V_47 [ 0 ] == 0x01 &&
V_48 == 49 ) {
F_14 ( V_2 , V_47 , V_48 ) ;
} else if ( ( ( V_2 -> V_35 & V_39 ) && V_47 [ 0 ] == 0x01 &&
V_48 == 64 ) || ( ( V_2 -> V_35 & V_41 )
&& V_47 [ 0 ] == 0x11 && V_48 == 78 ) ) {
if ( V_2 -> V_35 & V_41 ) {
T_1 V_77 = 0xA1 ;
T_3 V_78 ;
T_3 V_79 ;
V_78 = F_26 ( 0xFFFFFFFF , & V_77 , 1 ) ;
V_78 = ~ F_26 ( V_78 , V_47 , V_80 - 4 ) ;
V_79 = F_27 ( & V_47 [ V_80 - 4 ] ) ;
if ( V_78 != V_79 ) {
F_28 ( V_2 -> V_6 , L_4 ,
V_79 , V_78 ) ;
return - V_81 ;
}
}
if ( V_2 -> V_6 -> V_82 == V_83 &&
V_2 -> V_6 -> V_84 == V_85 ) {
bool V_86 = ( V_47 [ 31 ] & 0x04 ) ? false : true ;
if ( ! V_2 -> V_87 && V_86 ) {
F_13 ( V_2 -> V_6 , L_5 ) ;
F_29 ( V_2 ) ;
V_2 -> V_87 = true ;
} else if ( V_2 -> V_87 && ! V_86 ) {
F_13 ( V_2 -> V_6 , L_6 ) ;
V_2 -> V_87 = false ;
return 0 ;
} else if ( ! V_2 -> V_87 ) {
return 0 ;
}
}
F_17 ( V_2 , V_47 , V_48 ) ;
}
if ( V_2 -> V_3 ) {
V_2 -> V_3 = 0 ;
F_1 ( V_2 ) ;
}
return 0 ;
}
static int F_30 ( struct V_5 * V_6 , struct V_13 * V_14 ,
struct V_15 * V_16 , struct V_17 * V_18 ,
unsigned long * * V_19 , int * V_20 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
if ( V_2 -> V_35 & V_88 ) {
unsigned int V_21 = V_18 -> V_22 & V_23 ;
if ( ( V_18 -> V_22 & V_24 ) != V_25 )
return - 1 ;
switch ( V_18 -> V_26 ) {
case 1 :
if ( V_21 >= F_8 ( V_89 ) )
return - 1 ;
V_21 = V_89 [ V_21 ] ;
if ( ! V_21 )
return - 1 ;
break;
default:
return - 1 ;
}
F_9 ( V_14 , V_18 , V_19 , V_20 , V_29 , V_21 ) ;
return 1 ;
}
if ( V_2 -> V_35 & V_46 )
return F_7 ( V_6 , V_14 , V_16 , V_18 , V_19 , V_20 ) ;
if ( V_2 -> V_35 & V_90 )
return F_10 ( V_6 , V_14 , V_16 , V_18 , V_19 , V_20 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , int V_91 ,
int V_92 , int V_93 )
{
T_4 V_94 ;
char * V_95 ;
int V_96 ;
V_2 -> V_63 = F_32 () ;
if ( ! V_2 -> V_63 )
return - V_97 ;
F_33 ( V_2 -> V_63 , V_2 ) ;
V_2 -> V_63 -> V_98 . V_99 = & V_2 -> V_6 -> V_98 ;
V_2 -> V_63 -> V_100 = V_2 -> V_6 -> V_100 ;
V_2 -> V_63 -> V_101 = V_2 -> V_6 -> V_101 ;
V_2 -> V_63 -> V_102 . V_103 = V_2 -> V_6 -> V_104 ;
V_2 -> V_63 -> V_102 . V_82 = V_2 -> V_6 -> V_82 ;
V_2 -> V_63 -> V_102 . V_84 = V_2 -> V_6 -> V_84 ;
V_2 -> V_63 -> V_102 . V_105 = V_2 -> V_6 -> V_105 ;
V_94 = strlen ( V_2 -> V_6 -> V_95 ) + sizeof( V_106 ) ;
V_95 = F_34 ( V_94 , V_107 ) ;
if ( ! V_95 ) {
V_96 = - V_97 ;
goto V_108;
}
snprintf ( V_95 , V_94 , L_7 V_106 , V_2 -> V_6 -> V_95 ) ;
V_2 -> V_63 -> V_95 = V_95 ;
V_96 = F_35 ( V_2 -> V_63 , V_91 , 0 ) ;
if ( V_96 < 0 )
goto V_108;
F_36 ( V_29 , V_2 -> V_63 -> V_109 ) ;
F_36 ( V_64 , V_2 -> V_63 -> V_110 ) ;
F_36 ( V_111 , V_2 -> V_63 -> V_112 ) ;
F_37 ( V_2 -> V_63 , V_71 , 0 , V_92 , 0 , 0 ) ;
F_37 ( V_2 -> V_63 , V_72 , 0 , V_93 , 0 , 0 ) ;
V_96 = F_38 ( V_2 -> V_63 ) ;
if ( V_96 < 0 )
goto V_108;
return 0 ;
V_108:
F_39 ( V_2 -> V_63 -> V_95 ) ;
V_2 -> V_63 -> V_95 = NULL ;
F_40 ( V_2 -> V_63 ) ;
V_2 -> V_63 = NULL ;
return V_96 ;
}
static void F_41 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_63 )
return;
F_39 ( V_2 -> V_63 -> V_95 ) ;
V_2 -> V_63 -> V_95 = NULL ;
F_42 ( V_2 -> V_63 ) ;
V_2 -> V_63 = NULL ;
}
static int F_43 ( struct V_5 * V_6 )
{
const int V_113 =
V_20 ( V_114 , V_115 ) ;
T_1 * V_116 ;
int V_96 ;
V_116 = F_44 ( V_113 , V_107 ) ;
if ( ! V_116 )
return - V_97 ;
V_96 = F_45 ( V_6 , 0xf2 , V_116 , V_114 ,
V_117 , V_118 ) ;
if ( V_96 < 0 ) {
F_46 ( V_6 , L_8 ) ;
goto V_119;
}
V_96 = F_45 ( V_6 , 0xf5 , V_116 , V_115 ,
V_117 , V_118 ) ;
if ( V_96 < 0 ) {
F_46 ( V_6 , L_9 ) ;
goto V_119;
}
V_96 = F_47 ( V_6 , V_116 , 1 ) ;
if ( V_96 < 0 ) {
F_13 ( V_6 , L_10 ) ;
V_96 = 0 ;
}
V_119:
F_39 ( V_116 ) ;
return V_96 ;
}
static int F_48 ( struct V_5 * V_6 )
{
static const T_1 V_74 [] = { 0xf4 , 0x42 , 0x03 , 0x00 , 0x00 } ;
T_1 * V_116 ;
int V_96 ;
V_116 = F_49 ( V_74 , sizeof( V_74 ) , V_107 ) ;
if ( ! V_116 )
return - V_97 ;
V_96 = F_45 ( V_6 , V_116 [ 0 ] , V_116 , sizeof( V_74 ) ,
V_117 , V_120 ) ;
F_39 ( V_116 ) ;
return V_96 ;
}
static int F_50 ( struct V_5 * V_6 )
{
T_1 * V_116 ;
int V_96 ;
V_116 = F_44 ( V_121 , V_107 ) ;
if ( ! V_116 )
return - V_97 ;
V_96 = F_45 ( V_6 , 0x02 , V_116 , V_121 ,
V_117 , V_118 ) ;
F_39 ( V_116 ) ;
return V_96 ;
}
static void F_51 ( struct V_1 * V_2 )
{
static const T_1 V_122 [ 10 ] [ 4 ] = {
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
int V_102 = V_2 -> V_123 ;
F_52 ( V_124 < F_8 ( V_122 [ 0 ] ) ) ;
if ( V_102 < 0 )
return;
V_102 %= 10 ;
memcpy ( V_2 -> V_125 , V_122 [ V_102 ] , sizeof( V_122 [ V_102 ] ) ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
static const T_1 V_126 [ 7 ] [ 3 ] = {
{ 0x00 , 0x00 , 0x01 } ,
{ 0x01 , 0x00 , 0x00 } ,
{ 0x00 , 0x01 , 0x00 } ,
{ 0x02 , 0x00 , 0x01 } ,
{ 0x02 , 0x01 , 0x00 } ,
{ 0x00 , 0x01 , 0x01 } ,
{ 0x01 , 0x01 , 0x01 }
} ;
int V_102 = V_2 -> V_123 ;
F_52 ( V_124 < F_8 ( V_126 [ 0 ] ) ) ;
if ( V_102 < 0 )
return;
V_102 %= 7 ;
memcpy ( V_2 -> V_125 , V_126 [ V_102 ] , sizeof( V_126 [ V_102 ] ) ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_127 * V_128 =
& V_6 -> V_129 [ V_130 ] . V_128 ;
struct V_73 * V_74 = F_55 ( V_128 -> V_131 ,
struct V_73 , V_132 ) ;
T_5 * V_133 = V_74 -> V_16 [ 0 ] -> V_133 ;
F_52 ( V_124 < 4 ) ;
V_133 [ 0 ] = 0x00 ;
V_133 [ 1 ] = V_2 -> V_125 [ 0 ] ? 0xff : 0x00 ;
V_133 [ 2 ] = V_2 -> V_125 [ 1 ] ? 0xff : 0x00 ;
V_133 [ 3 ] = V_2 -> V_125 [ 2 ] ? 0xff : 0x00 ;
V_133 [ 4 ] = V_2 -> V_125 [ 3 ] ? 0xff : 0x00 ;
V_133 [ 5 ] = 0x00 ;
V_133 [ 6 ] = 0x00 ;
F_56 ( V_6 , V_74 , V_120 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_35 & V_88 ) )
F_1 ( V_2 ) ;
else
F_54 ( V_2 ) ;
}
static void F_57 ( struct V_134 * V_135 ,
enum V_136 V_133 )
{
struct V_137 * V_98 = V_135 -> V_98 -> V_99 ;
struct V_5 * V_6 = F_58 ( V_98 ) ;
struct V_1 * V_138 ;
int V_57 ;
int V_139 ;
V_138 = F_12 ( V_6 ) ;
if ( ! V_138 ) {
F_46 ( V_6 , L_11 ) ;
return;
}
V_139 = ! ! ( V_138 -> V_35 & V_140 ) ;
for ( V_57 = 0 ; V_57 < V_138 -> V_141 ; V_57 ++ ) {
if ( V_135 == V_138 -> V_142 [ V_57 ] && ( V_139 ||
( V_133 != V_138 -> V_125 [ V_57 ] ||
V_138 -> V_143 [ V_57 ] ||
V_138 -> V_144 [ V_57 ] ) ) ) {
V_138 -> V_125 [ V_57 ] = V_133 ;
V_138 -> V_143 [ V_57 ] = 0 ;
V_138 -> V_144 [ V_57 ] = 0 ;
F_29 ( V_138 ) ;
break;
}
}
}
static enum V_136 F_59 ( struct V_134 * V_135 )
{
struct V_137 * V_98 = V_135 -> V_98 -> V_99 ;
struct V_5 * V_6 = F_58 ( V_98 ) ;
struct V_1 * V_138 ;
int V_57 ;
V_138 = F_12 ( V_6 ) ;
if ( ! V_138 ) {
F_46 ( V_6 , L_11 ) ;
return V_145 ;
}
for ( V_57 = 0 ; V_57 < V_138 -> V_141 ; V_57 ++ ) {
if ( V_135 == V_138 -> V_142 [ V_57 ] )
return V_138 -> V_125 [ V_57 ] ;
}
return V_145 ;
}
static int F_60 ( struct V_134 * V_135 , unsigned long * V_146 ,
unsigned long * V_147 )
{
struct V_137 * V_98 = V_135 -> V_98 -> V_99 ;
struct V_5 * V_6 = F_58 ( V_98 ) ;
struct V_1 * V_138 = F_12 ( V_6 ) ;
int V_57 ;
T_1 V_148 , V_149 ;
if ( ! V_138 ) {
F_46 ( V_6 , L_11 ) ;
return - V_75 ;
}
if ( * V_146 > 2550 )
* V_146 = 2550 ;
if ( * V_147 > 2550 )
* V_147 = 2550 ;
if ( ! * V_146 && ! * V_147 )
* V_146 = * V_147 = 500 ;
V_148 = * V_146 / 10 ;
V_149 = * V_147 / 10 ;
for ( V_57 = 0 ; V_57 < V_138 -> V_141 ; V_57 ++ ) {
if ( V_135 == V_138 -> V_142 [ V_57 ] )
break;
}
if ( V_57 >= V_138 -> V_141 )
return - V_75 ;
if ( V_148 != V_138 -> V_143 [ V_57 ] ||
V_149 != V_138 -> V_144 [ V_57 ] ) {
V_138 -> V_143 [ V_57 ] = V_148 ;
V_138 -> V_144 [ V_57 ] = V_149 ;
F_1 ( V_138 ) ;
}
return 0 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_134 * V_135 ;
int V_57 ;
F_62 ( ! ( V_2 -> V_35 & V_150 ) ) ;
for ( V_57 = 0 ; V_57 < V_2 -> V_141 ; V_57 ++ ) {
V_135 = V_2 -> V_142 [ V_57 ] ;
V_2 -> V_142 [ V_57 ] = NULL ;
if ( ! V_135 )
continue;
F_63 ( V_135 ) ;
F_39 ( V_135 ) ;
}
V_2 -> V_141 = 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_57 , V_96 = 0 ;
int V_151 ;
struct V_134 * V_135 ;
T_4 V_94 ;
char * V_95 ;
T_4 V_152 ;
const char * V_153 ;
static const char * const V_154 [] = { L_12 , L_13 , L_14 ,
L_15 } ;
T_1 V_155 [ V_124 ] = { [ 0 ... ( V_124 - 1 ) ] = 1 } ;
T_1 V_156 [ V_124 ] = { 0 } ;
F_62 ( ! ( V_2 -> V_35 & V_150 ) ) ;
if ( V_2 -> V_35 & V_88 ) {
V_2 -> V_141 = 4 ;
V_151 = 0 ;
V_152 = strlen ( L_16 ) ;
V_153 = L_17 ;
if ( ! F_65 ( V_6 , V_130 , 0 , 0 , 7 ) )
return - V_157 ;
} else if ( V_2 -> V_35 & V_90 ) {
F_53 ( V_2 ) ;
V_2 -> V_125 [ 3 ] = 1 ;
V_2 -> V_141 = 4 ;
memset ( V_155 , 255 , 3 ) ;
V_156 [ 3 ] = 1 ;
V_151 = 1 ;
V_152 = 0 ;
V_153 = L_18 ;
} else if ( V_2 -> V_35 & V_44 ) {
V_2 -> V_141 = 3 ;
memset ( V_155 , 255 , 3 ) ;
V_151 = 1 ;
V_152 = 0 ;
V_153 = L_18 ;
} else if ( V_2 -> V_35 & V_45 ) {
static const T_1 V_158 [ 4 ] = { 0x01 , 0x00 , 0x00 , 0x00 } ;
memcpy ( V_2 -> V_125 , V_158 , sizeof( V_158 ) ) ;
V_2 -> V_141 = 1 ;
memset ( V_156 , 1 , 4 ) ;
V_151 = 0 ;
V_152 = strlen ( L_19 ) ;
V_153 = L_20 ;
} else {
F_51 ( V_2 ) ;
V_2 -> V_141 = 4 ;
memset ( V_156 , 1 , 4 ) ;
V_151 = 0 ;
V_152 = strlen ( L_19 ) ;
V_153 = L_20 ;
}
F_29 ( V_2 ) ;
V_94 = strlen ( F_66 ( & V_6 -> V_98 ) ) + V_152 + 1 ;
for ( V_57 = 0 ; V_57 < V_2 -> V_141 ; V_57 ++ ) {
if ( V_151 )
V_94 = strlen ( F_66 ( & V_6 -> V_98 ) ) + strlen ( V_154 [ V_57 ] ) + 2 ;
V_135 = F_34 ( sizeof( struct V_134 ) + V_94 , V_107 ) ;
if ( ! V_135 ) {
F_46 ( V_6 , L_21 , V_57 ) ;
V_96 = - V_97 ;
goto V_159;
}
V_95 = ( void * ) ( & V_135 [ 1 ] ) ;
if ( V_151 )
snprintf ( V_95 , V_94 , V_153 , F_66 ( & V_6 -> V_98 ) ,
V_154 [ V_57 ] ) ;
else
snprintf ( V_95 , V_94 , V_153 , F_66 ( & V_6 -> V_98 ) , V_57 + 1 ) ;
V_135 -> V_95 = V_95 ;
V_135 -> V_160 = V_2 -> V_125 [ V_57 ] ;
V_135 -> V_155 = V_155 [ V_57 ] ;
V_135 -> V_161 = F_59 ;
V_135 -> V_162 = F_57 ;
if ( V_156 [ V_57 ] )
V_135 -> V_163 = F_60 ;
V_2 -> V_142 [ V_57 ] = V_135 ;
V_96 = F_67 ( & V_6 -> V_98 , V_135 ) ;
if ( V_96 ) {
F_46 ( V_6 , L_22 , V_57 ) ;
V_2 -> V_142 [ V_57 ] = NULL ;
F_39 ( V_135 ) ;
goto V_159;
}
}
return V_96 ;
V_159:
F_61 ( V_2 ) ;
return V_96 ;
}
static void F_68 ( struct V_1 * V_2 )
{
static const union V_164 V_165 = {
. V_116 = {
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
struct V_166 * V_74 =
(struct V_166 * ) V_2 -> V_167 ;
int V_57 ;
memcpy ( V_74 , & V_165 , sizeof( struct V_166 ) ) ;
#ifdef F_69
V_74 -> V_168 . V_169 = V_2 -> V_170 ? 1 : 0 ;
V_74 -> V_168 . V_171 = V_2 -> V_172 ;
#endif
V_74 -> V_173 |= V_2 -> V_125 [ 0 ] << 1 ;
V_74 -> V_173 |= V_2 -> V_125 [ 1 ] << 2 ;
V_74 -> V_173 |= V_2 -> V_125 [ 2 ] << 3 ;
V_74 -> V_173 |= V_2 -> V_125 [ 3 ] << 4 ;
if ( ( V_74 -> V_173 & 0x1E ) == 0 )
V_74 -> V_173 |= 0x20 ;
for ( V_57 = 0 ; V_57 < 4 ; V_57 ++ ) {
if ( V_2 -> V_143 [ V_57 ] || V_2 -> V_144 [ V_57 ] ) {
V_74 -> V_135 [ 3 - V_57 ] . V_174 = V_2 -> V_144 [ V_57 ] ;
V_74 -> V_135 [ 3 - V_57 ] . V_175 = V_2 -> V_143 [ V_57 ] ;
}
}
F_45 ( V_2 -> V_6 , V_74 -> V_176 , ( T_1 * ) V_74 ,
sizeof( struct V_166 ) ,
V_130 , V_120 ) ;
}
static void F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 * V_116 = V_2 -> V_167 ;
int V_51 ;
if ( V_2 -> V_35 & V_39 ) {
memset ( V_116 , 0 , V_177 ) ;
V_116 [ 0 ] = 0x05 ;
V_116 [ 1 ] = 0xFF ;
V_51 = 4 ;
} else {
memset ( V_116 , 0 , V_178 ) ;
V_116 [ 0 ] = 0x11 ;
V_116 [ 1 ] = 0xC0 ;
V_116 [ 3 ] = 0x0F ;
V_51 = 6 ;
}
#ifdef F_69
V_116 [ V_51 ++ ] = V_2 -> V_170 ;
V_116 [ V_51 ++ ] = V_2 -> V_172 ;
#else
V_51 += 2 ;
#endif
if ( V_2 -> V_125 [ 3 ] ) {
V_116 [ V_51 ++ ] = V_2 -> V_125 [ 0 ] ;
V_116 [ V_51 ++ ] = V_2 -> V_125 [ 1 ] ;
V_116 [ V_51 ++ ] = V_2 -> V_125 [ 2 ] ;
} else {
V_51 += 3 ;
}
V_116 [ V_51 ++ ] = V_2 -> V_143 [ 3 ] ;
V_116 [ V_51 ++ ] = V_2 -> V_144 [ 3 ] ;
if ( V_2 -> V_35 & V_39 )
F_47 ( V_6 , V_116 , V_177 ) ;
else {
T_1 V_77 = 0xA2 ;
T_3 V_78 ;
V_78 = F_26 ( 0xFFFFFFFF , & V_77 , 1 ) ;
V_78 = ~ F_26 ( V_78 , V_116 , V_178 - 4 ) ;
F_71 ( V_78 , & V_116 [ 74 ] ) ;
F_47 ( V_6 , V_116 , V_178 ) ;
}
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_179 * V_74 =
(struct V_179 * ) V_2 -> V_167 ;
memset ( V_74 , 0 , V_180 ) ;
V_74 -> type = 0x02 ;
V_74 -> V_181 = V_2 -> V_125 [ 0 ] ;
V_74 -> V_182 = V_2 -> V_125 [ 1 ] ;
V_74 -> V_183 = V_2 -> V_125 [ 2 ] ;
#ifdef F_69
V_74 -> V_168 = V_20 ( V_2 -> V_170 , V_2 -> V_172 ) ;
#endif
F_47 ( V_6 , ( T_1 * ) V_74 , V_180 ) ;
}
static inline void F_73 ( struct V_1 * V_2 )
{
if ( V_2 -> V_184 )
V_2 -> V_184 ( V_2 ) ;
}
static void F_74 ( struct V_185 * V_186 )
{
struct V_1 * V_2 = F_75 ( V_186 , struct V_1 , V_4 ) ;
V_2 -> V_184 ( V_2 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_35 & V_43 ) ||
( V_2 -> V_35 & V_45 ) )
V_2 -> V_167 =
F_44 ( sizeof( union V_164 ) ,
V_107 ) ;
else if ( V_2 -> V_35 & V_41 )
V_2 -> V_167 = F_44 ( V_178 ,
V_107 ) ;
else if ( V_2 -> V_35 & V_39 )
V_2 -> V_167 = F_44 ( V_177 ,
V_107 ) ;
else if ( V_2 -> V_35 & V_44 )
V_2 -> V_167 = F_44 ( V_180 ,
V_107 ) ;
else
return 0 ;
if ( ! V_2 -> V_167 )
return - V_97 ;
return 0 ;
}
static int F_77 ( struct V_187 * V_98 , void * V_188 ,
struct V_189 * V_190 )
{
struct V_5 * V_22 = F_78 ( V_98 ) ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
if ( V_190 -> type != V_191 )
return 0 ;
V_2 -> V_172 = V_190 -> V_192 . V_168 . V_193 / 256 ;
V_2 -> V_170 = V_190 -> V_192 . V_168 . V_194 / 256 ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
struct V_13 * V_195 = F_55 ( V_2 -> V_6 -> V_196 . V_131 ,
struct V_13 , V_132 ) ;
struct V_187 * V_187 = V_195 -> V_197 ;
F_80 ( V_187 , V_198 , V_191 ) ;
return F_81 ( V_187 , NULL , F_77 ) ;
}
static int F_79 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_82 ( struct V_199 * V_200 ,
enum V_201 V_202 ,
union V_203 * V_204 )
{
struct V_1 * V_2 = F_83 ( V_200 ) ;
unsigned long V_50 ;
int V_96 = 0 ;
T_1 V_54 , V_53 , V_52 ;
F_15 ( & V_2 -> V_56 , V_50 ) ;
V_54 = V_2 -> V_54 ;
V_53 = V_2 -> V_53 ;
V_52 = V_2 -> V_52 ;
F_16 ( & V_2 -> V_56 , V_50 ) ;
switch ( V_202 ) {
case V_205 :
V_204 -> V_206 = 1 ;
break;
case V_207 :
V_204 -> V_206 = V_208 ;
break;
case V_209 :
V_204 -> V_206 = V_53 ;
break;
case V_210 :
if ( V_54 )
V_204 -> V_206 = V_211 ;
else
if ( V_53 == 100 && V_52 )
V_204 -> V_206 = V_212 ;
else
V_204 -> V_206 = V_213 ;
break;
default:
V_96 = - V_75 ;
break;
}
return V_96 ;
}
static int F_84 ( struct V_1 * V_2 , int V_214 )
{
const char * V_215 = V_214 ?
L_23 :
L_24 ;
struct V_216 V_217 = { . V_138 = V_2 , } ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_96 ;
V_2 -> V_53 = 100 ;
V_2 -> V_218 . V_219 = V_220 ;
V_2 -> V_218 . V_221 = F_8 ( V_220 ) ;
V_2 -> V_218 . V_222 = F_82 ;
V_2 -> V_218 . type = V_223 ;
V_2 -> V_218 . V_224 = 0 ;
V_2 -> V_218 . V_95 = F_85 ( V_107 , V_215 ,
V_2 -> V_225 , V_2 -> V_123 ) ;
if ( ! V_2 -> V_218 . V_95 )
return - V_97 ;
V_2 -> V_226 = F_86 ( & V_6 -> V_98 , & V_2 -> V_218 ,
& V_217 ) ;
if ( F_87 ( V_2 -> V_226 ) ) {
V_96 = F_88 ( V_2 -> V_226 ) ;
F_46 ( V_6 , L_25 ) ;
goto V_227;
}
F_89 ( V_2 -> V_226 , & V_6 -> V_98 ) ;
return 0 ;
V_227:
F_39 ( V_2 -> V_218 . V_95 ) ;
V_2 -> V_218 . V_95 = NULL ;
return V_96 ;
}
static void F_90 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_218 . V_95 )
return;
F_91 ( V_2 -> V_226 ) ;
F_39 ( V_2 -> V_218 . V_95 ) ;
V_2 -> V_218 . V_95 = NULL ;
}
static inline int F_92 ( struct V_1 * V_228 ,
struct V_1 * V_229 )
{
const int V_230 = ! ( V_228 -> V_35 & V_231 ) ;
const int V_232 = ! ( V_229 -> V_35 & V_231 ) ;
return V_230 == V_232 ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_1 * V_233 ;
unsigned long V_50 ;
int V_96 ;
F_15 ( & V_234 , V_50 ) ;
F_94 (entry, &sony_device_list, list_node) {
V_96 = memcmp ( V_2 -> V_225 , V_233 -> V_225 ,
sizeof( V_2 -> V_225 ) ) ;
if ( ! V_96 ) {
if ( F_92 ( V_2 , V_233 ) ) {
V_96 = 1 ;
} else {
V_96 = - V_235 ;
F_13 ( V_2 -> V_6 ,
L_26 ,
V_2 -> V_225 ) ;
}
goto V_236;
}
}
V_96 = 0 ;
F_95 ( & ( V_2 -> V_237 ) , & V_238 ) ;
V_236:
F_16 ( & V_234 , V_50 ) ;
return V_96 ;
}
static void F_96 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
if ( V_2 -> V_237 . V_131 ) {
F_15 ( & V_234 , V_50 ) ;
F_97 ( & ( V_2 -> V_237 ) ) ;
F_16 ( & V_234 , V_50 ) ;
}
}
static int F_98 ( struct V_1 * V_2 )
{
int V_96 ;
V_96 = strlen ( V_2 -> V_6 -> V_101 ) ;
if ( V_96 != 17 )
return - V_75 ;
V_96 = sscanf ( V_2 -> V_6 -> V_101 ,
L_27 ,
& V_2 -> V_225 [ 5 ] , & V_2 -> V_225 [ 4 ] , & V_2 -> V_225 [ 3 ] ,
& V_2 -> V_225 [ 2 ] , & V_2 -> V_225 [ 1 ] , & V_2 -> V_225 [ 0 ] ) ;
if ( V_96 != 6 )
return - V_75 ;
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
T_1 * V_116 = NULL ;
int V_57 , V_96 ;
if ( ( V_2 -> V_35 & V_41 ) ||
( V_2 -> V_35 & V_76 ) ||
( V_2 -> V_35 & V_239 ) ||
( V_2 -> V_35 & V_240 ) ) {
if ( F_98 ( V_2 ) < 0 ) {
F_100 ( V_2 -> V_6 , L_28 ) ;
return 0 ;
}
} else if ( V_2 -> V_35 & V_39 ) {
V_116 = F_44 ( V_241 , V_107 ) ;
if ( ! V_116 )
return - V_97 ;
V_96 = F_45 ( V_2 -> V_6 , 0x81 , V_116 ,
V_241 , V_117 ,
V_118 ) ;
if ( V_96 != V_241 ) {
F_46 ( V_2 -> V_6 , L_29 ) ;
V_96 = V_96 < 0 ? V_96 : - V_75 ;
goto V_242;
}
memcpy ( V_2 -> V_225 , & V_116 [ 1 ] , sizeof( V_2 -> V_225 ) ) ;
snprintf ( V_2 -> V_6 -> V_101 , sizeof( V_2 -> V_6 -> V_101 ) ,
L_27 ,
V_2 -> V_225 [ 5 ] , V_2 -> V_225 [ 4 ] ,
V_2 -> V_225 [ 3 ] , V_2 -> V_225 [ 2 ] ,
V_2 -> V_225 [ 1 ] , V_2 -> V_225 [ 0 ] ) ;
} else if ( ( V_2 -> V_35 & V_140 ) ||
( V_2 -> V_35 & V_243 ) ) {
V_116 = F_44 ( V_114 , V_107 ) ;
if ( ! V_116 )
return - V_97 ;
V_96 = F_45 ( V_2 -> V_6 , 0xf2 , V_116 ,
V_114 , V_117 ,
V_118 ) ;
if ( V_96 != V_114 ) {
F_46 ( V_2 -> V_6 , L_30 ) ;
V_96 = V_96 < 0 ? V_96 : - V_75 ;
goto V_242;
}
for ( V_57 = 0 ; V_57 < 6 ; V_57 ++ )
V_2 -> V_225 [ 5 - V_57 ] = V_116 [ 4 + V_57 ] ;
} else {
return 0 ;
}
V_96 = F_93 ( V_2 ) ;
V_242:
F_39 ( V_116 ) ;
return V_96 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_96 ;
if ( ( V_2 -> V_35 & V_43 ) ||
( V_2 -> V_35 & V_90 ) ) {
V_96 = F_102 ( & V_244 , 0 , 0 ,
V_107 ) ;
if ( V_96 < 0 ) {
V_2 -> V_123 = - 1 ;
return V_96 ;
}
V_2 -> V_123 = V_96 ;
} else {
V_2 -> V_123 = - 1 ;
}
return 0 ;
}
static void F_103 ( struct V_1 * V_2 )
{
if ( V_2 -> V_123 >= 0 ) {
F_104 ( & V_244 , V_2 -> V_123 ) ;
V_2 -> V_123 = - 1 ;
}
}
static inline void F_105 ( struct V_1 * V_2 ,
void (* V_184)( struct V_1 * ) )
{
V_2 -> V_184 = V_184 ;
if ( ! V_2 -> V_245 )
F_106 ( & V_2 -> V_4 , F_74 ) ;
V_2 -> V_245 = 1 ;
}
static inline void F_107 ( struct V_1 * V_2 )
{
if ( V_2 -> V_245 )
F_108 ( & V_2 -> V_4 ) ;
}
static int F_109 ( struct V_5 * V_6 ,
struct V_13 * V_195 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
int V_214 ;
int V_96 ;
V_96 = F_101 ( V_2 ) ;
if ( V_96 < 0 ) {
F_46 ( V_6 , L_31 ) ;
goto V_246;
}
V_96 = F_76 ( V_2 ) ;
if ( V_96 < 0 ) {
F_46 ( V_6 , L_32 ) ;
goto V_246;
}
if ( ( V_2 -> V_35 & V_140 ) ||
( V_2 -> V_35 & V_243 ) ) {
V_6 -> V_35 |= V_247 ;
V_6 -> V_35 |= V_248 ;
V_2 -> V_3 = 1 ;
V_96 = F_43 ( V_6 ) ;
F_105 ( V_2 , F_68 ) ;
} else if ( ( V_2 -> V_35 & V_240 ) ||
( V_2 -> V_35 & V_239 ) ) {
V_6 -> V_35 |= V_247 ;
V_96 = F_48 ( V_6 ) ;
F_105 ( V_2 , F_68 ) ;
} else if ( V_2 -> V_35 & V_90 ) {
if ( V_2 -> V_35 & V_41 ) {
V_96 = F_50 ( V_6 ) ;
if ( V_96 < 0 ) {
F_46 ( V_6 , L_33 ) ;
goto V_246;
}
}
V_96 = F_31 ( V_2 , 2 , 1920 , 942 ) ;
if ( V_96 ) {
F_46 ( V_2 -> V_6 ,
L_34 ,
V_96 ) ;
goto V_246;
}
F_105 ( V_2 , F_70 ) ;
} else if ( V_2 -> V_35 & V_44 ) {
F_105 ( V_2 , F_72 ) ;
} else {
V_96 = 0 ;
}
if ( V_96 < 0 )
goto V_246;
V_96 = V_214 = F_99 ( V_2 ) ;
if ( V_96 < 0 )
goto V_246;
if ( V_2 -> V_35 & V_150 ) {
V_96 = F_64 ( V_2 ) ;
if ( V_96 < 0 )
goto V_246;
}
if ( V_2 -> V_35 & V_249 ) {
V_96 = F_84 ( V_2 , V_214 ) ;
if ( V_96 < 0 )
goto V_246;
V_96 = F_110 ( V_6 ) ;
if ( V_96 < 0 ) {
F_46 ( V_6 , L_35 ) ;
goto V_246;
}
}
if ( V_2 -> V_35 & V_250 ) {
V_96 = F_79 ( V_2 ) ;
if ( V_96 < 0 )
goto V_251;
}
return 0 ;
V_251:
F_111 ( V_6 ) ;
V_246:
if ( V_2 -> V_35 & V_150 )
F_61 ( V_2 ) ;
if ( V_2 -> V_35 & V_249 )
F_90 ( V_2 ) ;
if ( V_2 -> V_63 )
F_41 ( V_2 ) ;
F_107 ( V_2 ) ;
F_39 ( V_2 -> V_167 ) ;
F_96 ( V_2 ) ;
F_103 ( V_2 ) ;
F_112 ( V_6 ) ;
return V_96 ;
}
static int F_113 ( struct V_5 * V_6 , const struct V_252 * V_102 )
{
int V_96 ;
unsigned long V_35 = V_102 -> V_253 ;
struct V_1 * V_2 ;
unsigned int V_254 = V_255 ;
if ( ! strcmp ( V_6 -> V_95 , L_36 ) )
V_35 |= V_37 ;
V_2 = F_114 ( & V_6 -> V_98 , sizeof( * V_2 ) , V_107 ) ;
if ( V_2 == NULL ) {
F_46 ( V_6 , L_37 ) ;
return - V_97 ;
}
F_115 ( & V_2 -> V_56 ) ;
V_2 -> V_35 = V_35 ;
F_116 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_96 = F_117 ( V_6 ) ;
if ( V_96 ) {
F_46 ( V_6 , L_38 ) ;
return V_96 ;
}
if ( V_2 -> V_35 & V_38 )
V_254 |= V_256 ;
else if ( V_2 -> V_35 & V_43 )
V_254 |= V_256 ;
if ( V_2 -> V_35 & V_90 )
V_6 -> V_105 |= 0x8000 ;
V_96 = F_118 ( V_6 , V_254 ) ;
if ( V_96 ) {
F_46 ( V_6 , L_39 ) ;
return V_96 ;
}
if ( ! ( V_6 -> V_257 & V_258 ) ) {
F_46 ( V_6 , L_40 ) ;
return - V_157 ;
}
return V_96 ;
}
static void F_119 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_12 ( V_6 ) ;
F_111 ( V_6 ) ;
if ( V_2 -> V_35 & V_150 )
F_61 ( V_2 ) ;
if ( V_2 -> V_35 & V_249 )
F_90 ( V_2 ) ;
if ( V_2 -> V_63 )
F_41 ( V_2 ) ;
F_107 ( V_2 ) ;
F_39 ( V_2 -> V_167 ) ;
F_96 ( V_2 ) ;
F_103 ( V_2 ) ;
F_112 ( V_6 ) ;
}
static int F_120 ( struct V_5 * V_6 , T_6 V_259 )
{
if ( V_150 || V_250 ) {
struct V_1 * V_2 = F_12 ( V_6 ) ;
#ifdef F_69
V_2 -> V_172 = V_2 -> V_170 = 0 ;
#endif
memcpy ( V_2 -> V_260 , V_2 -> V_125 ,
sizeof( V_2 -> V_260 ) ) ;
memset ( V_2 -> V_125 , 0 , sizeof( V_2 -> V_125 ) ) ;
F_73 ( V_2 ) ;
}
return 0 ;
}
static int F_121 ( struct V_5 * V_6 )
{
if ( V_150 ) {
struct V_1 * V_2 = F_12 ( V_6 ) ;
memcpy ( V_2 -> V_125 , V_2 -> V_260 ,
sizeof( V_2 -> V_125 ) ) ;
if ( ( V_2 -> V_35 & V_140 ) ||
( V_2 -> V_35 & V_243 ) ) {
F_43 ( V_2 -> V_6 ) ;
V_2 -> V_3 = 1 ;
}
F_29 ( V_2 ) ;
}
return 0 ;
}
static int T_7 F_122 ( void )
{
F_123 ( L_41 , V_261 ) ;
return F_124 ( & V_262 ) ;
}
static void T_8 F_125 ( void )
{
F_123 ( L_41 , V_261 ) ;
F_126 ( & V_262 ) ;
F_127 ( & V_244 ) ;
}
