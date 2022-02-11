static enum V_1 T_1 F_1 ( struct V_2 * V_3 )
{
switch ( V_3 -> V_4 ) {
case V_5 :
switch ( V_3 -> V_6 ) {
case V_7 :
case V_8 :
case V_9 :
return V_10 ;
default:
return V_11 ;
}
break;
case V_12 :
switch ( V_3 -> V_6 ) {
case V_13 :
return V_10 ;
case V_14 :
return V_15 ;
default:
return V_11 ;
}
break;
case V_16 :
return V_17 ;
break;
case V_18 :
case V_19 :
case V_20 :
if ( V_3 -> V_6 == V_14 )
return V_15 ;
else
return V_11 ;
break;
case V_21 :
return V_22 ;
break;
case V_23 :
switch ( V_3 -> V_6 ) {
case V_24 :
return V_25 ;
default:
return V_26 ;
}
break;
case V_27 :
if ( V_3 -> V_6 == V_28 ||
V_3 -> V_6 == V_24 )
return V_10 ;
else
return V_29 ;
break;
}
return V_10 ;
}
static enum V_30 T_1 F_2 ( volatile unsigned long V_31 )
{
unsigned long V_32 = 0xA5A0B5B0 ;
unsigned long V_33 = 0x00000000 ;
F_3 ( V_31 , & V_32 , 4 ) ;
if ( F_4 ( & V_32 , V_31 , 4 ) == 0 )
return V_34 ;
F_5 ( V_31 , & V_32 , 4 ) ;
F_6 ( & V_33 , V_31 , 4 ) ;
if ( V_32 == V_33 )
return V_35 ;
return V_36 ;
}
static int T_1 F_7 ( unsigned long V_31 )
{
unsigned long V_37 ;
int V_38 , V_39 ;
F_8 ( V_37 ) ;
for ( V_38 = 0 ; V_38 < 8 ; V_38 ++ ) {
volatile unsigned short * V_40 = ( unsigned short * ) ( V_31 + ( V_38 * 0x1000 ) ) ;
if ( F_9 ( V_40 ) == 0 )
break;
* V_40 = 0xA5A0 | V_38 ;
if ( * V_40 != ( 0xA5A0 | V_38 ) )
break;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
volatile unsigned short * V_41 = ( unsigned short * ) ( V_31 + ( V_39 * 0x1000 ) ) ;
if ( * V_41 != ( 0xA5A0 | V_39 ) )
break;
}
}
F_10 ( V_37 ) ;
return V_38 * 0x1000 ;
}
static bool T_1 F_11 ( struct V_42 * V_3 , struct V_2 * V_43 ,
enum V_1 V_44 )
{
struct V_45 V_46 ;
struct V_47 V_48 ;
int V_49 ;
volatile unsigned short * V_38 ;
F_12 (KERN_INFO pr_fmt(L_1), version) ;
V_3 -> V_50 = F_13 ( V_43 -> V_51 -> V_52 ) ;
V_3 -> V_53 = ( V_43 -> V_51 -> V_54 |
( ( V_43 -> V_51 -> V_52 & 0xf ) << 20 ) ) ;
if ( F_14 ( V_43 , & V_46 ) == - 1 ) {
F_15 ( L_2 ,
V_3 -> V_55 , V_43 -> V_51 -> V_52 ) ;
return false ;
}
if ( F_16 ( & V_46 , V_56 , & V_48 ) == - 1 ) {
F_17 ( L_3 , V_3 -> V_55 ) ;
return false ;
}
F_18 ( V_3 -> V_57 , & V_48 , 6 ) ;
if ( V_58 [ V_44 ] == 1 ) {
F_19 ( & V_46 ) ;
if ( F_16 ( & V_46 , V_59 ,
& V_48 ) == - 1 ) {
F_15 ( L_4 ,
V_3 -> V_55 , V_43 -> V_51 -> V_52 ) ;
return false ;
}
F_18 ( & V_49 , & V_48 , 4 ) ;
V_3 -> V_60 = V_3 -> V_53 + V_49 ;
V_3 -> V_53 = V_3 -> V_60 + 0x10000 ;
F_19 ( & V_46 ) ;
if ( F_16 ( & V_46 , V_61 ,
& V_48 ) == - 1 ) {
F_17 ( L_5 ,
V_3 -> V_55 , V_43 -> V_51 -> V_52 ) ;
V_49 = F_7 ( V_3 -> V_60 ) ;
} else {
F_18 ( & V_49 , & V_48 , 4 ) ;
}
V_3 -> V_62 = V_3 -> V_60 + V_49 ;
} else {
switch ( V_44 ) {
case V_26 :
case V_29 :
V_3 -> V_53 = ( int ) ( V_43 -> V_51 -> V_54 +
V_63 ) ;
V_3 -> V_60 = ( int ) ( V_43 -> V_51 -> V_54 +
V_64 ) ;
V_3 -> V_62 = V_3 -> V_60 +
F_7 ( V_3 -> V_60 ) ;
break;
case V_25 :
V_3 -> V_53 = ( int ) ( V_43 -> V_51 -> V_54 +
V_65 ) ;
V_3 -> V_60 = ( int ) ( V_43 -> V_51 -> V_54 +
V_66 ) ;
V_3 -> V_62 = V_3 -> V_60 +
F_7 ( V_3 -> V_60 ) ;
break;
case V_15 :
V_3 -> V_53 = ( int ) ( V_43 -> V_51 -> V_54 +
V_67 ) ;
V_3 -> V_60 = ( int ) ( V_43 -> V_51 -> V_54 +
V_68 ) ;
V_38 = ( void * ) V_3 -> V_53 ;
* V_38 = 0x21 ;
V_3 -> V_62 = V_3 -> V_60 +
F_7 ( V_3 -> V_60 ) ;
break;
default:
F_15 ( L_6 ,
V_43 -> V_51 -> V_55 ) ;
return false ;
}
}
return true ;
}
struct V_42 * T_1 F_20 ( int V_69 )
{
struct V_42 * V_3 ;
struct V_2 * V_43 = NULL ;
int V_70 = - V_71 ;
struct V_72 * V_73 ;
static unsigned int V_74 ;
enum V_1 V_44 ;
if ( ! V_75 )
return F_21 ( - V_71 ) ;
V_3 = F_22 ( 0 ) ;
if ( ! V_3 )
return F_21 ( - V_76 ) ;
if ( V_69 >= 0 )
sprintf ( V_3 -> V_55 , L_7 , V_69 ) ;
while ( ( V_43 = F_23 ( V_77 , V_78 ,
V_43 ) ) ) {
if ( V_74 & ( 1 << V_43 -> V_51 -> V_52 ) )
continue;
V_74 |= 1 << V_43 -> V_51 -> V_52 ;
V_44 = F_1 ( V_43 ) ;
if ( V_44 == V_10 )
continue;
if ( ! F_11 ( V_3 , V_43 , V_44 ) )
continue;
if ( ! F_24 ( V_3 , V_43 , V_44 ) )
break;
}
if ( ! V_43 )
goto V_79;
V_73 = F_25 ( V_3 ) ;
V_73 -> V_80 = V_81 ;
V_70 = F_26 ( V_3 ) ;
if ( V_70 )
goto V_79;
return V_3 ;
V_79:
F_27 ( V_3 ) ;
return F_21 ( V_70 ) ;
}
int T_1 F_28 ( void )
{
V_82 = F_20 ( - 1 ) ;
if ( F_29 ( V_82 ) ) {
F_30 ( L_8 ) ;
return F_31 ( V_82 ) ;
}
return 0 ;
}
void T_2 F_32 ( void )
{
F_33 ( V_82 ) ;
F_27 ( V_82 ) ;
}
static int T_1 F_24 ( struct V_42 * V_3 ,
struct V_2 * V_43 ,
enum V_1 type )
{
static T_3 V_83 [ 16 ] = {
0 , 4 , 8 , 12 ,
16 , 20 , 24 , 28 ,
32 , 36 , 40 , 44 ,
48 , 52 , 56 , 60
} ;
static T_3 V_84 [ 16 ] = {
60 , 56 , 52 , 48 ,
44 , 40 , 36 , 32 ,
28 , 24 , 20 , 16 ,
12 , 8 , 4 , 0
} ;
static T_3 V_85 [ 16 ] = {
0 , 2 , 4 , 6 ,
8 , 10 , 12 , 14 ,
16 , 18 , 20 , 22 ,
24 , 26 , 28 , 30
} ;
int V_86 = 0 ;
V_3 -> V_87 = & V_88 ;
V_89 . V_55 = V_90 [ type ] ;
V_89 . V_91 = V_91 [ type ] ;
if ( type == V_15 ) {
V_89 . V_92 = V_93 ;
V_89 . V_94 = V_95 ;
V_89 . V_96 = V_97 ;
V_89 . V_98 = V_3 -> V_60 ;
V_89 . V_99 = V_3 -> V_60 + V_97 * 256 ;
} else {
V_89 . V_92 = V_100 ;
V_89 . V_94 = V_100 + V_101 ;
V_89 . V_96 = ( V_3 -> V_62 - V_3 -> V_60 ) / 256 ;
V_89 . V_98 = V_3 -> V_60 + V_101 * 256 ;
V_89 . V_99 = V_3 -> V_62 ;
}
switch ( type ) {
case V_22 :
case V_11 :
switch ( F_2 ( V_3 -> V_60 ) ) {
case V_36 :
F_15 ( L_9 ) ;
return - V_71 ;
case V_35 :
V_89 . V_102 = V_103 ;
V_89 . V_104 = V_105 ;
V_89 . V_106 = V_107 ;
V_89 . V_108 = V_109 ;
V_89 . V_110 = V_84 ;
break;
case V_34 :
V_89 . V_102 = V_103 ;
V_89 . V_104 = V_111 ;
V_89 . V_106 = V_112 ;
V_89 . V_108 = V_113 ;
V_89 . V_110 = V_84 ;
V_86 = 1 ;
break;
}
break;
case V_17 :
V_89 . V_102 = V_103 ;
V_89 . V_104 = V_105 ;
V_89 . V_106 = V_107 ;
V_89 . V_108 = V_109 ;
V_89 . V_110 = V_84 ;
break;
case V_15 :
V_89 . V_102 = V_103 ;
V_89 . V_104 = V_105 ;
V_89 . V_106 = V_107 ;
V_89 . V_108 = V_109 ;
V_89 . V_110 = V_85 ;
break;
case V_29 :
case V_26 :
V_89 . V_102 = V_103 ;
V_89 . V_104 = V_114 ;
V_89 . V_106 = V_115 ;
V_89 . V_108 = V_116 ;
V_89 . V_110 = V_83 ;
break;
case V_25 :
V_89 . V_102 = V_117 ;
V_89 . V_104 = V_105 ;
V_89 . V_106 = V_107 ;
V_89 . V_108 = V_109 ;
V_89 . V_110 = V_83 ;
break;
default:
F_15 ( L_6 ,
V_43 -> V_51 -> V_55 ) ;
return - V_71 ;
}
F_34 ( V_3 , 0 ) ;
F_17 ( L_10 ,
V_3 -> V_55 , V_43 -> V_51 -> V_55 , V_43 -> V_51 -> V_52 ,
V_90 [ type ] ) ;
F_17 ( L_11 ,
V_3 -> V_57 , V_3 -> V_50 ,
( unsigned int ) ( V_3 -> V_62 - V_3 -> V_60 ) >> 10 ,
V_3 -> V_60 , V_86 ? 32 : 16 ) ;
return 0 ;
}
static int F_35 ( struct V_42 * V_3 )
{
int V_70 ;
F_36 ( V_3 ) ;
V_70 = F_37 ( V_3 -> V_50 , V_118 , 0 , L_12 , V_3 ) ;
if ( V_70 )
F_15 ( L_13 , V_3 -> V_55 , V_3 -> V_50 ) ;
return V_70 ;
}
static int F_38 ( struct V_42 * V_3 )
{
F_39 ( V_3 -> V_50 , V_3 ) ;
F_40 ( V_3 ) ;
return 0 ;
}
static void V_103 ( struct V_42 * V_3 )
{
struct V_72 * V_73 = F_25 ( V_3 ) ;
V_89 . V_119 = 0 ;
F_41 ( V_73 , V_120 , V_3 , L_14 ) ;
}
static void V_117 ( struct V_42 * V_3 )
{
unsigned char * V_121 = F_42 ( F_43 ( V_3 -> V_50 ) ) ;
struct V_72 * V_73 = F_25 ( V_3 ) ;
F_41 ( V_73 , V_120 , V_3 , L_15 ,
V_122 ) ;
V_89 . V_119 = 0 ;
V_121 [ 0xC0000 ] = 0 ;
if ( F_44 ( V_73 ) )
F_45 ( L_16 ) ;
}
static void F_46 ( struct V_42 * V_3 , void * V_123 , int V_124 ,
int V_125 )
{
volatile unsigned char * V_126 ;
unsigned char * V_121 = V_123 ;
V_124 <<= 1 ;
V_126 = ( unsigned char * ) ( V_3 -> V_60 + V_124 ) ;
if ( V_124 & 2 ) {
* V_121 ++ = V_126 [ - 1 ] ;
V_126 += 2 ;
V_125 -- ;
}
while ( V_125 >= 2 ) {
* ( unsigned short * ) V_121 = * ( unsigned short volatile * ) V_126 ;
V_126 += 4 ;
V_121 += 2 ;
V_125 -= 2 ;
}
if ( V_125 )
* V_121 = * V_126 ;
}
static void F_47 ( struct V_42 * V_3 , int V_123 ,
const void * V_124 , int V_125 )
{
volatile unsigned short * V_126 ;
const unsigned char * V_127 = V_124 ;
V_123 <<= 1 ;
V_126 = ( unsigned short * ) ( V_3 -> V_60 + V_123 ) ;
if ( V_123 & 2 ) {
V_126 [ - 1 ] = ( V_126 [ - 1 ] & 0xFF00 ) | * V_127 ++ ;
V_126 ++ ;
V_125 -- ;
}
while ( V_125 >= 2 ) {
* V_126 ++ = * ( unsigned short * ) V_127 ;
V_126 ++ ;
V_127 += 2 ;
V_125 -= 2 ;
}
if ( V_125 ) {
* V_126 = ( * V_126 & 0x00FF ) | ( * V_127 << 8 ) ;
}
}
static void V_113 ( struct V_42 * V_3 ,
struct V_128 * V_129 , int V_130 )
{
unsigned long V_131 = ( V_130 - V_100 ) << 8 ;
F_48 ( V_129 , V_3 -> V_60 + V_131 , 4 ) ;
V_129 -> V_125 = F_49 ( V_129 -> V_125 ) ;
}
static void V_111 ( struct V_42 * V_3 , int V_125 ,
struct V_132 * V_133 , int V_134 )
{
unsigned long V_135 = V_134 - ( V_100 << 8 ) ;
unsigned long V_136 = V_135 + V_3 -> V_60 ;
if ( V_136 + V_125 > V_89 . V_99 ) {
int V_137 = V_89 . V_99 - V_136 ;
F_48 ( V_133 -> V_138 , V_3 -> V_60 + V_135 ,
V_137 ) ;
V_125 -= V_137 ;
F_48 ( V_133 -> V_138 + V_137 , V_89 . V_98 ,
V_125 ) ;
} else {
F_48 ( V_133 -> V_138 , V_3 -> V_60 + V_135 , V_125 ) ;
}
}
static void V_112 ( struct V_42 * V_3 , int V_125 ,
const unsigned char * V_139 , int V_140 )
{
long V_141 = ( V_140 - V_100 ) << 8 ;
F_3 ( V_3 -> V_60 + V_141 , V_139 , V_125 ) ;
}
static void V_116 ( struct V_42 * V_3 ,
struct V_128 * V_129 , int V_130 )
{
unsigned long V_131 = ( V_130 - V_100 ) << 8 ;
F_46 ( V_3 , V_129 , V_131 , 4 ) ;
V_129 -> V_125 = ( V_129 -> V_125 & 0xFF ) << 8 | ( V_129 -> V_125 >> 8 ) ;
}
static void V_114 ( struct V_42 * V_3 , int V_125 ,
struct V_132 * V_133 , int V_134 )
{
unsigned long V_135 = V_134 - ( V_100 << 8 ) ;
unsigned long V_136 = V_135 + V_3 -> V_60 ;
if ( V_136 + V_125 > V_89 . V_99 ) {
int V_137 = V_89 . V_99 - V_136 ;
F_46 ( V_3 , V_133 -> V_138 , V_135 , V_137 ) ;
V_125 -= V_137 ;
F_46 ( V_3 , V_133 -> V_138 + V_137 ,
V_89 . V_98 - V_3 -> V_60 ,
V_125 ) ;
} else {
F_46 ( V_3 , V_133 -> V_138 , V_135 , V_125 ) ;
}
}
static void V_115 ( struct V_42 * V_3 , int V_125 ,
const unsigned char * V_139 ,
int V_140 )
{
long V_141 = ( V_140 - V_100 ) << 8 ;
F_47 ( V_3 , V_141 , V_139 , V_125 ) ;
}
static void V_109 ( struct V_42 * V_3 ,
struct V_128 * V_129 ,
int V_130 )
{
unsigned long V_131 = ( V_130 - V_100 ) << 8 ;
F_6 ( V_129 , V_3 -> V_60 + V_131 , 4 ) ;
V_129 -> V_125 = ( V_129 -> V_125 & 0xFF ) << 8 | ( V_129 -> V_125 >> 8 ) ;
}
static void V_105 ( struct V_42 * V_3 , int V_125 ,
struct V_132 * V_133 , int V_134 )
{
unsigned long V_135 = V_134 - ( V_100 << 8 ) ;
unsigned long V_136 = V_135 + V_3 -> V_60 ;
if ( V_136 + V_125 > V_89 . V_99 ) {
int V_137 = V_89 . V_99 - V_136 ;
F_6 ( V_133 -> V_138 , V_3 -> V_60 + V_135 ,
V_137 ) ;
V_125 -= V_137 ;
F_6 ( V_133 -> V_138 + V_137 ,
V_89 . V_98 , V_125 ) ;
} else {
F_6 ( V_133 -> V_138 , V_3 -> V_60 + V_135 ,
V_125 ) ;
}
}
static void V_107 ( struct V_42 * V_3 , int V_125 ,
const unsigned char * V_139 , int V_140 )
{
long V_141 = ( V_140 - V_100 ) << 8 ;
F_5 ( V_3 -> V_60 + V_141 , V_139 , V_125 ) ;
}
static void F_5 ( unsigned long V_142 , const void * V_143 , int V_125 )
{
volatile unsigned short * V_123 = ( void * ) V_142 ;
const unsigned short * V_124 = V_143 ;
V_125 ++ ;
V_125 /= 2 ;
while ( V_125 -- )
* V_123 ++ = * V_124 ++ ;
}
static void F_6 ( void * V_142 , unsigned long V_143 , int V_125 )
{
unsigned short * V_123 = V_142 ;
const volatile unsigned short * V_124 = ( const void * ) V_143 ;
V_125 ++ ;
V_125 /= 2 ;
while ( V_125 -- )
* V_123 ++ = * V_124 ++ ;
}
