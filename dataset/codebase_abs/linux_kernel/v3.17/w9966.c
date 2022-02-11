static inline void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
V_2 -> V_5 = ( V_2 -> V_5 & ~ V_3 ) ^ V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return ( ( V_2 -> V_5 & V_3 ) == V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , V_6 , V_6 ) )
return;
F_4 ( V_2 -> V_7 ) ;
F_1 ( V_2 , V_6 , V_6 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , V_6 , 0 ) )
return;
F_6 ( V_2 -> V_7 ) ;
F_1 ( V_2 , V_6 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_8 )
{
const unsigned char V_9 = 0x80 | ( V_8 & 0x1f ) ;
unsigned char V_4 ;
if ( F_8 ( V_2 -> V_10 , V_2 -> V_11 | V_12 ) != 0 )
return - 1 ;
if ( F_9 ( V_2 -> V_10 , & V_9 , 1 ) != 1 )
return - 1 ;
if ( F_8 ( V_2 -> V_10 , V_2 -> V_11 | V_13 ) != 0 )
return - 1 ;
if ( F_10 ( V_2 -> V_10 , & V_4 , 1 ) != 1 )
return - 1 ;
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 , int V_8 , int V_14 )
{
const unsigned char V_9 = 0xc0 | ( V_8 & 0x1f ) ;
const unsigned char V_4 = V_14 ;
if ( F_8 ( V_2 -> V_10 , V_2 -> V_11 | V_12 ) != 0 )
return - 1 ;
if ( F_9 ( V_2 -> V_10 , & V_9 , 1 ) != 1 )
return - 1 ;
if ( F_8 ( V_2 -> V_10 , V_2 -> V_11 | V_13 ) != 0 )
return - 1 ;
if ( F_9 ( V_2 -> V_10 , & V_4 , 1 ) != 1 )
return - 1 ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , int V_15 )
{
if ( V_15 )
V_2 -> V_16 |= V_17 ;
else
V_2 -> V_16 &= ~ V_17 ;
F_11 ( V_2 , 0x18 , V_2 -> V_16 ) ;
F_13 ( 5 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
const unsigned char V_15 = F_7 ( V_2 , 0x18 ) ;
return ( ( V_15 & V_18 ) > 0 ) ;
}
static int F_15 ( struct V_1 * V_2 , int V_15 )
{
unsigned long V_19 ;
if ( V_15 )
V_2 -> V_16 |= V_20 ;
else
V_2 -> V_16 &= ~ V_20 ;
F_11 ( V_2 , 0x18 , V_2 -> V_16 ) ;
F_13 ( 5 ) ;
if ( V_15 ) {
V_19 = V_21 + 100 ;
while ( ! F_14 ( V_2 ) ) {
if ( F_16 ( V_21 , V_19 ) )
return - 1 ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_14 )
{
int V_22 ;
for ( V_22 = 7 ; V_22 >= 0 ; V_22 -- ) {
F_12 ( V_2 , ( V_14 >> V_22 ) & 0x01 ) ;
if ( F_15 ( V_2 , 1 ) == - 1 )
return - 1 ;
F_15 ( V_2 , 0 ) ;
}
F_12 ( V_2 , 1 ) ;
if ( F_15 ( V_2 , 1 ) == - 1 )
return - 1 ;
F_15 ( V_2 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , int V_8 , int V_14 )
{
F_12 ( V_2 , 0 ) ;
F_15 ( V_2 , 0 ) ;
if ( F_17 ( V_2 , V_23 ) == - 1 ||
F_17 ( V_2 , V_8 ) == - 1 ||
F_17 ( V_2 , V_14 ) == - 1 )
return - 1 ;
F_12 ( V_2 , 0 ) ;
if ( F_15 ( V_2 , 1 ) == - 1 )
return - 1 ;
F_12 ( V_2 , 1 ) ;
return 0 ;
}
static int F_19 ( int V_24 , int V_25 , int V_26 )
{
int V_27 = V_25 ;
int V_28 = abs ( V_24 - V_27 ) ;
int V_29 ;
for ( V_29 = V_25 + 1 ; V_29 < V_26 ; V_29 ++ ) {
int V_30 ;
if ( ( ( 64 * V_25 ) % V_29 ) != 0 )
continue;
V_30 = abs ( V_24 - V_29 ) ;
if ( V_30 > V_28 )
break;
V_28 = V_30 ;
V_27 = V_29 ;
}
return V_27 ;
}
static int F_20 ( int V_25 , int V_31 , int V_32 , int * V_33 , int * V_34 , unsigned char * V_35 )
{
int V_26 = V_32 - V_31 ;
int V_29 = * V_34 - * V_33 + 1 ;
int V_36 = F_19 ( V_29 , V_25 , V_26 ) ;
int V_30 = V_36 - V_29 ;
if ( V_36 > V_26 || V_36 < V_25 )
return - 1 ;
* V_35 = ( 64 * V_25 ) / V_36 ;
if ( * V_35 == 64 )
* V_35 = 0x00 ;
else
* V_35 |= 0x80 ;
* V_33 -= V_30 / 2 ;
* V_34 += V_30 - ( V_30 / 2 ) ;
if ( * V_33 < V_31 ) {
* V_34 += V_31 - * V_33 ;
* V_33 += V_31 - * V_33 ;
}
if ( * V_34 > V_32 ) {
* V_33 -= * V_34 - V_32 ;
* V_34 -= * V_34 - V_32 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_37 , int y1 , int V_38 , int V_39 , int V_40 , int V_41 )
{
unsigned int V_22 ;
unsigned int V_42 , V_43 ;
unsigned char V_44 , V_45 ;
unsigned char V_46 [ 0x1c ] ;
unsigned char V_47 [] = {
0x21 , 0x00 , 0xd8 , 0x23 , 0x00 , 0x80 , 0x80 , 0x00 ,
0x88 , 0x10 , 0x80 , 0x40 , 0x40 , 0x00 , 0x01 , 0x00 ,
0x48 , 0x0c , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x71 , 0xe7 , 0x00 , 0x00 , 0xc0
} ;
if ( V_40 * V_41 * 2 > V_48 ) {
F_22 ( L_1 ) ;
V_40 = 200 ; V_41 = 160 ;
}
V_40 &= ~ 0x1 ;
if ( V_40 < 2 )
V_40 = 2 ;
if ( V_41 < 1 )
V_41 = 1 ;
if ( V_40 > V_49 )
V_40 = V_49 ;
if ( V_41 > V_50 )
V_41 = V_50 ;
V_2 -> V_51 = V_40 ;
V_2 -> V_52 = V_41 ;
V_42 = 0 ;
V_43 = V_40 * V_41 * 2 ;
if ( F_20 ( V_40 , V_53 , V_54 , & V_37 , & V_38 , & V_44 ) != 0 ||
F_20 ( V_41 , V_55 , V_56 , & y1 , & V_39 , & V_45 ) != 0 )
return - 1 ;
F_22 ( L_2 ,
V_40 , V_41 , V_37 , V_38 , y1 , V_39 , V_44 & ~ 0x80 , V_45 & ~ 0x80 ) ;
V_46 [ 0x00 ] = 0x00 ;
V_46 [ 0x01 ] = 0x18 ;
V_46 [ 0x02 ] = V_45 ;
V_46 [ 0x03 ] = V_44 ;
V_46 [ 0x04 ] = ( V_37 & 0x0ff ) ;
V_46 [ 0x05 ] = ( V_37 & 0x300 ) >> 8 ;
V_46 [ 0x06 ] = ( y1 & 0x0ff ) ;
V_46 [ 0x07 ] = ( y1 & 0x300 ) >> 8 ;
V_46 [ 0x08 ] = ( V_38 & 0x0ff ) ;
V_46 [ 0x09 ] = ( V_38 & 0x300 ) >> 8 ;
V_46 [ 0x0a ] = ( V_39 & 0x0ff ) ;
V_46 [ 0x0c ] = V_57 ;
V_46 [ 0x0d ] = ( V_42 & 0x000ff ) ;
V_46 [ 0x0e ] = ( V_42 & 0x0ff00 ) >> 8 ;
V_46 [ 0x0f ] = ( V_42 & 0x70000 ) >> 16 ;
V_46 [ 0x10 ] = ( V_43 & 0x000ff ) ;
V_46 [ 0x11 ] = ( V_43 & 0x0ff00 ) >> 8 ;
V_46 [ 0x12 ] = ( V_43 & 0x70000 ) >> 16 ;
V_46 [ 0x13 ] = 0x40 ;
V_46 [ 0x17 ] = 0x00 ;
V_46 [ 0x18 ] = V_2 -> V_16 = 0x00 ;
V_46 [ 0x19 ] = 0xff ;
V_46 [ 0x1a ] = 0xff ;
V_46 [ 0x1b ] = 0x10 ;
V_47 [ 0x0a ] = V_2 -> V_58 ;
V_47 [ 0x0b ] = V_2 -> V_59 ;
V_47 [ 0x0c ] = V_2 -> V_60 ;
V_47 [ 0x0d ] = V_2 -> V_61 ;
if ( F_11 ( V_2 , 0x00 , 0x03 ) == - 1 )
return - 1 ;
for ( V_22 = 0 ; V_22 < 0x1c ; V_22 ++ )
if ( F_11 ( V_2 , V_22 , V_46 [ V_22 ] ) == - 1 )
return - 1 ;
for ( V_22 = 0 ; V_22 < 0x20 ; V_22 ++ )
if ( F_18 ( V_2 , V_22 , V_47 [ V_22 ] ) == - 1 )
return - 1 ;
return 0 ;
}
static int F_23 ( struct V_62 * V_62 , void * V_63 ,
struct V_64 * V_65 )
{
struct V_1 * V_2 = F_24 ( V_62 ) ;
F_25 ( V_65 -> V_66 , V_2 -> V_67 . V_68 , sizeof( V_65 -> V_66 ) ) ;
F_25 ( V_65 -> V_69 , V_70 , sizeof( V_65 -> V_69 ) ) ;
F_25 ( V_65 -> V_71 , L_3 , sizeof( V_65 -> V_71 ) ) ;
V_65 -> V_72 = V_73 | V_74 ;
V_65 -> V_75 = V_65 -> V_72 | V_76 ;
return 0 ;
}
static int F_26 ( struct V_62 * V_62 , void * V_77 , struct V_78 * V_79 )
{
if ( V_79 -> V_80 > 0 )
return - V_81 ;
F_25 ( V_79 -> V_68 , L_4 , sizeof( V_79 -> V_68 ) ) ;
V_79 -> type = V_82 ;
V_79 -> V_83 = 0 ;
V_79 -> V_84 = 0 ;
V_79 -> V_85 = 0 ;
V_79 -> V_86 = 0 ;
return 0 ;
}
static int F_27 ( struct V_62 * V_62 , void * V_77 , unsigned int * V_87 )
{
* V_87 = 0 ;
return 0 ;
}
static int F_28 ( struct V_62 * V_62 , void * V_77 , unsigned int V_87 )
{
return ( V_87 > 0 ) ? - V_81 : 0 ;
}
static int F_29 ( struct V_88 * V_89 )
{
struct V_1 * V_2 =
F_30 ( V_89 -> V_90 , struct V_1 , V_91 ) ;
int V_92 = 0 ;
F_31 ( & V_2 -> V_93 ) ;
switch ( V_89 -> V_94 ) {
case V_95 :
V_2 -> V_58 = V_89 -> V_4 ;
break;
case V_96 :
V_2 -> V_59 = V_89 -> V_4 ;
break;
case V_97 :
V_2 -> V_60 = V_89 -> V_4 ;
break;
case V_98 :
V_2 -> V_61 = V_89 -> V_4 ;
break;
default:
V_92 = - V_81 ;
break;
}
if ( V_92 == 0 ) {
F_3 ( V_2 ) ;
if ( F_18 ( V_2 , 0x0a , V_2 -> V_58 ) == - 1 ||
F_18 ( V_2 , 0x0b , V_2 -> V_59 ) == - 1 ||
F_18 ( V_2 , 0x0c , V_2 -> V_60 ) == - 1 ||
F_18 ( V_2 , 0x0d , V_2 -> V_61 ) == - 1 ) {
V_92 = - V_99 ;
}
F_5 ( V_2 ) ;
}
F_32 ( & V_2 -> V_93 ) ;
return V_92 ;
}
static int F_33 ( struct V_62 * V_62 , void * V_77 , struct V_100 * V_101 )
{
struct V_1 * V_2 = F_24 ( V_62 ) ;
struct V_102 * V_103 = & V_101 -> V_101 . V_103 ;
V_103 -> V_51 = V_2 -> V_51 ;
V_103 -> V_52 = V_2 -> V_52 ;
V_103 -> V_104 = V_105 ;
V_103 -> V_106 = V_107 ;
V_103 -> V_108 = 2 * V_2 -> V_51 ;
V_103 -> V_109 = 2 * V_2 -> V_51 * V_2 -> V_52 ;
V_103 -> V_110 = V_111 ;
return 0 ;
}
static int F_34 ( struct V_62 * V_62 , void * V_77 , struct V_100 * V_101 )
{
struct V_102 * V_103 = & V_101 -> V_101 . V_103 ;
if ( V_103 -> V_51 < 2 )
V_103 -> V_51 = 2 ;
if ( V_103 -> V_52 < 1 )
V_103 -> V_52 = 1 ;
if ( V_103 -> V_51 > V_49 )
V_103 -> V_51 = V_49 ;
if ( V_103 -> V_52 > V_50 )
V_103 -> V_52 = V_50 ;
V_103 -> V_104 = V_105 ;
V_103 -> V_106 = V_107 ;
V_103 -> V_108 = 2 * V_103 -> V_51 ;
V_103 -> V_109 = 2 * V_103 -> V_51 * V_103 -> V_52 ;
V_103 -> V_110 = V_111 ;
return 0 ;
}
static int F_35 ( struct V_62 * V_62 , void * V_77 , struct V_100 * V_101 )
{
struct V_1 * V_2 = F_24 ( V_62 ) ;
struct V_102 * V_103 = & V_101 -> V_101 . V_103 ;
int V_92 = F_34 ( V_62 , V_77 , V_101 ) ;
if ( V_92 )
return V_92 ;
F_31 ( & V_2 -> V_93 ) ;
F_3 ( V_2 ) ;
V_92 = F_21 ( V_2 , 0 , 0 , 1023 , 1023 , V_103 -> V_51 , V_103 -> V_52 ) ;
F_5 ( V_2 ) ;
F_32 ( & V_2 -> V_93 ) ;
return V_92 ;
}
static int F_36 ( struct V_62 * V_62 , void * V_77 , struct V_112 * V_101 )
{
static struct V_112 V_113 [] = {
{ 0 , 0 , 0 ,
L_5 , V_105 ,
{ 0 , 0 , 0 , 0 }
} ,
} ;
enum V_114 type = V_101 -> type ;
if ( V_101 -> V_80 > 0 )
return - V_81 ;
* V_101 = V_113 [ V_101 -> V_80 ] ;
V_101 -> type = type ;
return 0 ;
}
static T_1 F_37 ( struct V_62 * V_62 , char T_2 * V_115 ,
T_3 V_116 , T_4 * V_117 )
{
struct V_1 * V_2 = F_24 ( V_62 ) ;
unsigned char V_9 = 0xa0 ;
unsigned char T_2 * V_118 = ( unsigned char T_2 * ) V_115 ;
unsigned long V_119 = V_116 ;
unsigned char * V_120 ;
if ( V_116 > V_2 -> V_51 * V_2 -> V_52 * 2 )
return - V_81 ;
F_31 ( & V_2 -> V_93 ) ;
F_3 ( V_2 ) ;
F_11 ( V_2 , 0x00 , 0x02 ) ;
F_11 ( V_2 , 0x00 , 0x00 ) ;
F_11 ( V_2 , 0x01 , 0x98 ) ;
if ( ( F_8 ( V_2 -> V_10 , V_2 -> V_11 | V_12 ) != 0 ) ||
( F_9 ( V_2 -> V_10 , & V_9 , 1 ) != 1 ) ||
( F_8 ( V_2 -> V_10 , V_2 -> V_11 | V_13 ) != 0 ) ) {
F_5 ( V_2 ) ;
F_32 ( & V_2 -> V_93 ) ;
return - V_121 ;
}
V_120 = F_38 ( V_122 , V_123 ) ;
if ( V_120 == NULL ) {
V_116 = - V_124 ;
goto V_125;
}
while ( V_119 > 0 ) {
unsigned long V_126 = ( V_119 > V_122 ) ? V_122 : V_119 ;
if ( F_10 ( V_2 -> V_10 , V_120 , V_126 ) < V_126 ) {
V_116 = - V_121 ;
goto V_125;
}
if ( F_39 ( V_118 , V_120 , V_126 ) != 0 ) {
V_116 = - V_121 ;
goto V_125;
}
V_118 += V_126 ;
V_119 -= V_126 ;
}
F_11 ( V_2 , 0x01 , 0x18 ) ;
V_125:
F_40 ( V_120 ) ;
F_5 ( V_2 ) ;
F_32 ( & V_2 -> V_93 ) ;
return V_116 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_127 * V_128 )
{
struct V_129 * V_67 = & V_2 -> V_67 ;
if ( V_2 -> V_5 != 0 )
return - 1 ;
F_25 ( V_67 -> V_68 , L_6 , sizeof( V_67 -> V_68 ) ) ;
if ( F_42 ( NULL , V_67 ) < 0 ) {
F_43 ( V_67 , L_7 ) ;
return - 1 ;
}
F_44 ( & V_2 -> V_91 , 4 ) ;
F_45 ( & V_2 -> V_91 , & V_130 ,
V_95 , 0 , 255 , 1 , 128 ) ;
F_45 ( & V_2 -> V_91 , & V_130 ,
V_96 , - 64 , 64 , 1 , 64 ) ;
F_45 ( & V_2 -> V_91 , & V_130 ,
V_97 , - 64 , 64 , 1 , 64 ) ;
F_45 ( & V_2 -> V_91 , & V_130 ,
V_98 , - 128 , 127 , 1 , 0 ) ;
if ( V_2 -> V_91 . error ) {
F_43 ( V_67 , L_8 ) ;
return - 1 ;
}
V_2 -> V_10 = V_128 ;
V_2 -> V_58 = 128 ;
V_2 -> V_59 = 64 ;
V_2 -> V_60 = 64 ;
V_2 -> V_61 = 0 ;
switch ( V_131 ) {
default:
case 0 :
if ( V_128 -> V_132 & V_133 )
V_2 -> V_11 = V_134 ;
else if ( V_128 -> V_132 & V_135 )
V_2 -> V_11 = V_136 ;
else
V_2 -> V_11 = V_134 ;
break;
case 1 :
V_2 -> V_11 = V_134 ;
break;
case 2 :
V_2 -> V_11 = V_136 ;
break;
}
V_2 -> V_7 = F_46 ( V_128 , L_6 , NULL , NULL , NULL , 0 , NULL ) ;
if ( V_2 -> V_7 == NULL ) {
F_22 ( L_9 ) ;
return - 1 ;
}
F_1 ( V_2 , V_137 , V_137 ) ;
F_3 ( V_2 ) ;
if ( F_21 ( V_2 , 0 , 0 , 1023 , 1023 , 200 , 160 ) != 0 ) {
F_22 ( L_10 ) ;
return - 1 ;
}
F_5 ( V_2 ) ;
F_25 ( V_2 -> V_138 . V_68 , V_70 , sizeof( V_2 -> V_138 . V_68 ) ) ;
V_2 -> V_138 . V_67 = V_67 ;
V_2 -> V_138 . V_139 = & V_140 ;
V_2 -> V_138 . V_141 = & V_142 ;
V_2 -> V_138 . V_143 = V_144 ;
V_2 -> V_138 . V_145 = & V_2 -> V_91 ;
F_47 ( & V_2 -> V_138 , V_2 ) ;
F_48 ( & V_2 -> V_93 ) ;
if ( F_49 ( & V_2 -> V_138 , V_146 , V_147 ) < 0 )
return - 1 ;
F_1 ( V_2 , V_148 , V_148 ) ;
F_50 ( V_67 , L_11 ,
V_2 -> V_10 -> V_68 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 , V_148 , V_148 ) ) {
F_52 ( & V_2 -> V_138 ) ;
F_1 ( V_2 , V_148 , 0 ) ;
}
F_53 ( & V_2 -> V_91 ) ;
if ( F_2 ( V_2 , V_137 , V_137 ) ) {
F_3 ( V_2 ) ;
F_8 ( V_2 -> V_10 , V_149 ) ;
F_5 ( V_2 ) ;
}
if ( F_2 ( V_2 , V_137 , V_137 ) ) {
F_54 ( V_2 -> V_7 ) ;
F_1 ( V_2 , V_137 , 0 ) ;
}
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
static void F_55 ( struct V_127 * V_128 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_150 ; V_22 ++ ) {
if ( V_151 [ V_22 ] . V_5 != 0 )
continue;
if ( strcmp ( V_152 [ V_22 ] , L_12 ) == 0 || strcmp ( V_152 [ V_22 ] , V_128 -> V_68 ) == 0 ) {
if ( F_41 ( & V_151 [ V_22 ] , V_128 ) != 0 )
F_51 ( & V_151 [ V_22 ] ) ;
break;
}
}
}
static void F_56 ( struct V_127 * V_128 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_150 ; V_22 ++ )
if ( V_151 [ V_22 ] . V_5 != 0 && V_151 [ V_22 ] . V_10 == V_128 )
F_51 ( & V_151 [ V_22 ] ) ;
}
static int T_5 F_57 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_150 ; V_22 ++ )
V_151 [ V_22 ] . V_5 = 0 ;
return F_58 ( & V_153 ) ;
}
static void T_6 F_59 ( void )
{
F_60 ( & V_153 ) ;
}
