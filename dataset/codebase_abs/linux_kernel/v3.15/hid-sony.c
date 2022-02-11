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
static void F_26 ( struct V_1 * V_2 , const T_1 * V_70 )
{
struct V_71 * V_72 =
& V_2 -> V_73 [ V_74 ] . V_72 ;
struct V_58 * V_59 = F_12 ( V_72 -> V_47 ,
struct V_58 , V_48 ) ;
T_3 * V_75 = V_59 -> V_9 [ 0 ] -> V_75 ;
V_75 [ 0 ] = 0x00 ;
V_75 [ 1 ] = V_70 [ 0 ] ? 0xff : 0x00 ;
V_75 [ 2 ] = V_70 [ 1 ] ? 0xff : 0x00 ;
V_75 [ 3 ] = V_70 [ 2 ] ? 0xff : 0x00 ;
V_75 [ 4 ] = V_70 [ 3 ] ? 0xff : 0x00 ;
V_75 [ 5 ] = 0x00 ;
V_75 [ 6 ] = 0x00 ;
F_27 ( V_2 , V_59 , V_69 ) ;
}
static void F_28 ( struct V_1 * V_2 , const T_1 * V_70 , int V_76 )
{
struct V_23 * V_77 = F_6 ( V_2 ) ;
int V_51 ;
F_29 ( V_76 > V_78 ) ;
if ( V_77 -> V_25 & V_61 && V_76 == 4 ) {
F_26 ( V_2 , V_70 ) ;
} else {
for ( V_51 = 0 ; V_51 < V_76 ; V_51 ++ )
V_77 -> V_79 [ V_51 ] = V_70 [ V_51 ] ;
F_30 ( & V_77 -> V_80 ) ;
}
}
static void F_31 ( struct V_81 * V_82 ,
enum V_83 V_75 )
{
struct V_84 * V_85 = V_82 -> V_85 -> V_86 ;
struct V_1 * V_2 = F_32 ( V_85 , struct V_1 , V_85 ) ;
struct V_23 * V_77 ;
int V_51 ;
V_77 = F_6 ( V_2 ) ;
if ( ! V_77 ) {
F_22 ( V_2 , L_7 ) ;
return;
}
for ( V_51 = 0 ; V_51 < V_77 -> V_87 ; V_51 ++ ) {
if ( V_82 == V_77 -> V_70 [ V_51 ] ) {
if ( V_75 != V_77 -> V_79 [ V_51 ] ) {
V_77 -> V_79 [ V_51 ] = V_75 ;
F_28 ( V_2 , V_77 -> V_79 , V_77 -> V_87 ) ;
}
break;
}
}
}
static enum V_83 F_33 ( struct V_81 * V_82 )
{
struct V_84 * V_85 = V_82 -> V_85 -> V_86 ;
struct V_1 * V_2 = F_32 ( V_85 , struct V_1 , V_85 ) ;
struct V_23 * V_77 ;
int V_51 ;
V_77 = F_6 ( V_2 ) ;
if ( ! V_77 ) {
F_22 ( V_2 , L_7 ) ;
return V_88 ;
}
for ( V_51 = 0 ; V_51 < V_77 -> V_87 ; V_51 ++ ) {
if ( V_82 == V_77 -> V_70 [ V_51 ] )
return V_77 -> V_79 [ V_51 ] ;
}
return V_88 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_23 * V_77 ;
struct V_81 * V_82 ;
int V_51 ;
V_77 = F_6 ( V_2 ) ;
F_29 ( ! ( V_77 -> V_25 & V_89 ) ) ;
for ( V_51 = 0 ; V_51 < V_77 -> V_87 ; V_51 ++ ) {
V_82 = V_77 -> V_70 [ V_51 ] ;
V_77 -> V_70 [ V_51 ] = NULL ;
if ( ! V_82 )
continue;
F_35 ( V_82 ) ;
F_23 ( V_82 ) ;
}
V_77 -> V_87 = 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_23 * V_77 ;
int V_51 , V_63 = 0 ;
int V_90 ;
int V_91 ;
struct V_81 * V_82 ;
T_4 V_92 ;
char * V_93 ;
T_4 V_94 ;
const char * V_95 ;
static const char * const V_96 [] = { L_8 , L_9 , L_10 } ;
static const T_1 V_97 [ V_78 ] = { 0x00 , 0x00 , 0x00 , 0x00 } ;
V_77 = F_6 ( V_2 ) ;
F_29 ( ! ( V_77 -> V_25 & V_89 ) ) ;
if ( V_77 -> V_25 & V_61 ) {
V_77 -> V_87 = 4 ;
V_90 = 1 ;
V_91 = 0 ;
V_94 = strlen ( L_11 ) ;
V_95 = L_12 ;
if ( ! F_37 ( V_2 , V_74 , 0 , 0 , 7 ) )
return - V_98 ;
} else if ( V_77 -> V_25 & V_99 ) {
V_77 -> V_87 = 3 ;
V_90 = 255 ;
V_91 = 1 ;
V_94 = 0 ;
V_95 = L_13 ;
} else {
V_77 -> V_87 = 4 ;
V_90 = 1 ;
V_91 = 0 ;
V_94 = strlen ( L_14 ) ;
V_95 = L_15 ;
}
F_28 ( V_2 , V_97 , V_77 -> V_87 ) ;
V_92 = strlen ( F_38 ( & V_2 -> V_85 ) ) + V_94 + 1 ;
for ( V_51 = 0 ; V_51 < V_77 -> V_87 ; V_51 ++ ) {
if ( V_91 )
V_92 = strlen ( F_38 ( & V_2 -> V_85 ) ) + strlen ( V_96 [ V_51 ] ) + 2 ;
V_82 = F_39 ( sizeof( struct V_81 ) + V_92 , V_65 ) ;
if ( ! V_82 ) {
F_22 ( V_2 , L_16 , V_51 ) ;
V_63 = - V_66 ;
goto V_100;
}
V_93 = ( void * ) ( & V_82 [ 1 ] ) ;
if ( V_91 )
snprintf ( V_93 , V_92 , V_95 , F_38 ( & V_2 -> V_85 ) , V_96 [ V_51 ] ) ;
else
snprintf ( V_93 , V_92 , V_95 , F_38 ( & V_2 -> V_85 ) , V_51 + 1 ) ;
V_82 -> V_93 = V_93 ;
V_82 -> V_101 = 0 ;
V_82 -> V_90 = V_90 ;
V_82 -> V_102 = F_33 ;
V_82 -> V_103 = F_31 ;
V_63 = F_40 ( & V_2 -> V_85 , V_82 ) ;
if ( V_63 ) {
F_22 ( V_2 , L_17 , V_51 ) ;
F_23 ( V_82 ) ;
goto V_100;
}
V_77 -> V_70 [ V_51 ] = V_82 ;
}
return V_63 ;
V_100:
F_34 ( V_2 ) ;
return V_63 ;
}
static void F_41 ( struct V_104 * V_105 )
{
struct V_23 * V_24 = F_32 ( V_105 , struct V_23 , V_80 ) ;
unsigned char V_64 [] = {
0x01 ,
0x00 , 0xff , 0x00 , 0xff , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0xff , 0x27 , 0x10 , 0x00 , 0x32 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
#ifdef F_42
V_64 [ 3 ] = V_24 -> V_106 ? 1 : 0 ;
V_64 [ 5 ] = V_24 -> V_107 ;
#endif
V_64 [ 10 ] |= V_24 -> V_79 [ 0 ] << 1 ;
V_64 [ 10 ] |= V_24 -> V_79 [ 1 ] << 2 ;
V_64 [ 10 ] |= V_24 -> V_79 [ 2 ] << 3 ;
V_64 [ 10 ] |= V_24 -> V_79 [ 3 ] << 4 ;
F_21 ( V_24 -> V_2 , 0x01 , V_64 , sizeof( V_64 ) , V_74 ,
V_69 ) ;
}
static void F_43 ( struct V_104 * V_105 )
{
struct V_23 * V_24 = F_32 ( V_105 , struct V_23 , V_80 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
int V_52 ;
T_1 V_64 [ 78 ] = { 0 } ;
if ( V_24 -> V_25 & V_27 ) {
V_64 [ 0 ] = 0x05 ;
V_64 [ 1 ] = 0x03 ;
V_52 = 4 ;
} else {
V_64 [ 0 ] = 0x11 ;
V_64 [ 1 ] = 0xB0 ;
V_64 [ 3 ] = 0x0F ;
V_52 = 6 ;
}
#ifdef F_42
V_64 [ V_52 ++ ] = V_24 -> V_106 ;
V_64 [ V_52 ++ ] = V_24 -> V_107 ;
#else
V_52 += 2 ;
#endif
V_64 [ V_52 ++ ] = V_24 -> V_79 [ 0 ] ;
V_64 [ V_52 ++ ] = V_24 -> V_79 [ 1 ] ;
V_64 [ V_52 ++ ] = V_24 -> V_79 [ 2 ] ;
if ( V_24 -> V_25 & V_27 )
F_44 ( V_2 , V_64 , 32 ) ;
else
F_21 ( V_2 , 0x11 , V_64 , 78 ,
V_74 , V_69 ) ;
}
static int F_45 ( struct V_49 * V_85 , void * V_108 ,
struct V_109 * V_110 )
{
struct V_1 * V_15 = F_46 ( V_85 ) ;
struct V_23 * V_24 = F_6 ( V_15 ) ;
if ( V_110 -> type != V_111 )
return 0 ;
V_24 -> V_107 = V_110 -> V_112 . V_113 . V_114 / 256 ;
V_24 -> V_106 = V_110 -> V_112 . V_113 . V_115 / 256 ;
F_30 ( & V_24 -> V_80 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_45 = F_12 ( V_2 -> V_46 . V_47 ,
struct V_6 , V_48 ) ;
struct V_49 * V_49 = V_45 -> V_50 ;
F_48 ( V_49 , V_116 , V_111 ) ;
return F_49 ( V_49 , NULL , F_45 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_50 ( struct V_117 * V_118 ,
enum V_119 V_120 ,
union V_121 * V_122 )
{
struct V_23 * V_24 = F_32 ( V_118 , struct V_23 , V_123 ) ;
unsigned long V_39 ;
int V_63 = 0 ;
T_5 V_42 , V_41 , V_40 ;
F_9 ( & V_24 -> V_44 , V_39 ) ;
V_42 = V_24 -> V_42 ;
V_41 = V_24 -> V_41 ;
V_40 = V_24 -> V_40 ;
F_10 ( & V_24 -> V_44 , V_39 ) ;
switch ( V_120 ) {
case V_124 :
V_122 -> V_125 = 1 ;
break;
case V_126 :
V_122 -> V_125 = V_127 ;
break;
case V_128 :
V_122 -> V_125 = V_41 ;
break;
case V_129 :
if ( V_42 )
V_122 -> V_125 = V_130 ;
else
if ( V_41 == 100 && V_40 )
V_122 -> V_125 = V_131 ;
else
V_122 -> V_125 = V_132 ;
break;
default:
V_63 = - V_133 ;
break;
}
return V_63 ;
}
static int F_51 ( struct V_23 * V_24 )
{
static T_6 V_134 = F_52 ( 0 ) ;
unsigned long V_135 ;
struct V_1 * V_2 = V_24 -> V_2 ;
int V_63 ;
V_24 -> V_41 = 100 ;
V_135 = ( unsigned long ) F_53 ( & V_134 ) ;
V_24 -> V_123 . V_136 = V_137 ;
V_24 -> V_123 . V_138 = F_3 ( V_137 ) ;
V_24 -> V_123 . V_139 = F_50 ;
V_24 -> V_123 . type = V_140 ;
V_24 -> V_123 . V_141 = 0 ;
V_24 -> V_123 . V_93 = F_54 ( V_65 , L_18 ,
V_135 ) ;
if ( ! V_24 -> V_123 . V_93 )
return - V_66 ;
V_63 = F_55 ( & V_2 -> V_85 , & V_24 -> V_123 ) ;
if ( V_63 ) {
F_22 ( V_2 , L_19 ) ;
goto V_142;
}
F_56 ( & V_24 -> V_123 , & V_2 -> V_85 ) ;
return 0 ;
V_142:
F_23 ( V_24 -> V_123 . V_93 ) ;
V_24 -> V_123 . V_93 = NULL ;
return V_63 ;
}
static void F_57 ( struct V_23 * V_24 )
{
if ( ! V_24 -> V_123 . V_93 )
return;
F_58 ( & V_24 -> V_123 ) ;
F_23 ( V_24 -> V_123 . V_93 ) ;
V_24 -> V_123 . V_93 = NULL ;
}
static int F_59 ( struct V_23 * V_24 , int V_143 ,
int V_144 , int V_145 )
{
struct V_6 * V_45 = F_12 ( V_24 -> V_2 -> V_46 . V_47 ,
struct V_6 , V_48 ) ;
struct V_49 * V_49 = V_45 -> V_50 ;
int V_63 ;
V_63 = F_60 ( V_49 , V_143 , 0 ) ;
if ( V_63 < 0 ) {
F_22 ( V_24 -> V_2 , L_20 ) ;
return V_63 ;
}
F_61 ( V_49 , V_56 , 0 , V_144 , 0 , 0 ) ;
F_61 ( V_49 , V_57 , 0 , V_145 , 0 , 0 ) ;
return 0 ;
}
static int F_62 ( struct V_23 * V_24 )
{
struct V_23 * V_146 ;
unsigned long V_39 ;
int V_63 ;
F_9 ( & V_147 , V_39 ) ;
F_63 (entry, &sony_device_list, list_node) {
V_63 = memcmp ( V_24 -> V_148 , V_146 -> V_148 ,
sizeof( V_24 -> V_148 ) ) ;
if ( ! V_63 ) {
V_63 = - V_149 ;
F_7 ( V_24 -> V_2 , L_21 ,
V_24 -> V_148 ) ;
goto V_150;
}
}
V_63 = 0 ;
F_64 ( & ( V_24 -> V_151 ) , & V_152 ) ;
V_150:
F_10 ( & V_147 , V_39 ) ;
return V_63 ;
}
static void F_65 ( struct V_23 * V_24 )
{
unsigned long V_39 ;
if ( V_24 -> V_151 . V_47 ) {
F_9 ( & V_147 , V_39 ) ;
F_66 ( & ( V_24 -> V_151 ) ) ;
F_10 ( & V_147 , V_39 ) ;
}
}
static int F_67 ( struct V_23 * V_24 )
{
int V_63 ;
V_63 = strlen ( V_24 -> V_2 -> V_153 ) ;
if ( V_63 != 17 )
return - V_133 ;
V_63 = sscanf ( V_24 -> V_2 -> V_153 ,
L_22 ,
& V_24 -> V_148 [ 5 ] , & V_24 -> V_148 [ 4 ] , & V_24 -> V_148 [ 3 ] ,
& V_24 -> V_148 [ 2 ] , & V_24 -> V_148 [ 1 ] , & V_24 -> V_148 [ 0 ] ) ;
if ( V_63 != 6 )
return - V_133 ;
return 0 ;
}
static int F_68 ( struct V_23 * V_24 )
{
int V_51 , V_63 ;
if ( ( V_24 -> V_25 & V_29 ) ||
( V_24 -> V_25 & V_32 ) ) {
if ( F_67 ( V_24 ) < 0 ) {
F_69 ( V_24 -> V_2 , L_23 ) ;
return 0 ;
}
} else if ( V_24 -> V_25 & V_27 ) {
T_1 V_64 [ 7 ] ;
V_63 = F_21 ( V_24 -> V_2 , 0x81 , V_64 , sizeof( V_64 ) ,
V_67 , V_68 ) ;
if ( V_63 != 7 ) {
F_22 ( V_24 -> V_2 , L_24 ) ;
return V_63 < 0 ? V_63 : - V_133 ;
}
memcpy ( V_24 -> V_148 , & V_64 [ 1 ] , sizeof( V_24 -> V_148 ) ) ;
} else if ( V_24 -> V_25 & V_31 ) {
T_1 V_64 [ 18 ] ;
V_63 = F_21 ( V_24 -> V_2 , 0xf2 , V_64 , sizeof( V_64 ) ,
V_67 , V_68 ) ;
if ( V_63 != 18 ) {
F_22 ( V_24 -> V_2 , L_25 ) ;
return V_63 < 0 ? V_63 : - V_133 ;
}
for ( V_51 = 0 ; V_51 < 6 ; V_51 ++ )
V_24 -> V_148 [ 5 - V_51 ] = V_64 [ 4 + V_51 ] ;
} else {
return 0 ;
}
return F_62 ( V_24 ) ;
}
static int F_70 ( struct V_1 * V_2 , const struct V_154 * V_155 )
{
int V_63 ;
unsigned long V_25 = V_155 -> V_156 ;
struct V_23 * V_24 ;
unsigned int V_157 = V_158 ;
V_24 = F_71 ( & V_2 -> V_85 , sizeof( * V_24 ) , V_65 ) ;
if ( V_24 == NULL ) {
F_22 ( V_2 , L_26 ) ;
return - V_66 ;
}
V_24 -> V_25 = V_25 ;
F_72 ( V_2 , V_24 ) ;
V_24 -> V_2 = V_2 ;
V_63 = F_73 ( V_2 ) ;
if ( V_63 ) {
F_22 ( V_2 , L_27 ) ;
return V_63 ;
}
if ( V_24 -> V_25 & V_26 )
V_157 |= V_159 ;
else if ( V_24 -> V_25 & V_31 )
V_157 |= V_159 ;
else if ( V_24 -> V_25 & V_32 )
V_157 |= V_159 ;
V_63 = F_74 ( V_2 , V_157 ) ;
if ( V_63 ) {
F_22 ( V_2 , L_28 ) ;
return V_63 ;
}
if ( V_24 -> V_25 & V_31 ) {
V_2 -> V_25 |= V_160 ;
V_2 -> V_25 |= V_161 ;
V_63 = F_19 ( V_2 ) ;
V_24 -> V_162 = 1 ;
F_75 ( & V_24 -> V_80 , F_41 ) ;
} else if ( V_24 -> V_25 & V_32 ) {
V_2 -> V_25 |= V_160 ;
V_63 = F_24 ( V_2 ) ;
V_24 -> V_162 = 1 ;
F_75 ( & V_24 -> V_80 , F_41 ) ;
} else if ( V_24 -> V_25 & V_99 ) {
if ( V_24 -> V_25 & V_29 ) {
V_2 -> V_25 |= V_160 ;
V_63 = F_25 ( V_2 ) ;
if ( V_63 < 0 ) {
F_22 ( V_2 , L_29 ) ;
goto V_163;
}
}
V_63 = F_59 ( V_24 , 2 , 1920 , 940 ) ;
if ( V_63 < 0 )
goto V_163;
V_24 -> V_162 = 1 ;
F_75 ( & V_24 -> V_80 , F_43 ) ;
} else {
V_63 = 0 ;
}
if ( V_63 < 0 )
goto V_163;
V_63 = F_68 ( V_24 ) ;
if ( V_63 < 0 )
goto V_163;
if ( V_24 -> V_25 & V_89 ) {
V_63 = F_36 ( V_2 ) ;
if ( V_63 < 0 )
goto V_163;
}
if ( V_24 -> V_25 & V_164 ) {
V_63 = F_51 ( V_24 ) ;
if ( V_63 < 0 )
goto V_163;
V_63 = F_76 ( V_2 ) ;
if ( V_63 < 0 ) {
F_22 ( V_2 , L_30 ) ;
goto V_163;
}
}
if ( V_24 -> V_25 & V_165 ) {
V_63 = F_47 ( V_2 ) ;
if ( V_63 < 0 )
goto V_166;
}
return 0 ;
V_166:
F_77 ( V_2 ) ;
V_163:
if ( V_24 -> V_25 & V_89 )
F_34 ( V_2 ) ;
if ( V_24 -> V_25 & V_164 )
F_57 ( V_24 ) ;
if ( V_24 -> V_162 )
F_78 ( & V_24 -> V_80 ) ;
F_65 ( V_24 ) ;
F_79 ( V_2 ) ;
return V_63 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_6 ( V_2 ) ;
if ( V_24 -> V_25 & V_89 )
F_34 ( V_2 ) ;
if ( V_24 -> V_25 & V_164 ) {
F_77 ( V_2 ) ;
F_57 ( V_24 ) ;
}
if ( V_24 -> V_162 )
F_78 ( & V_24 -> V_80 ) ;
F_65 ( V_24 ) ;
F_79 ( V_2 ) ;
}
