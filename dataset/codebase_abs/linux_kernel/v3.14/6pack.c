static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_4 , V_5 = V_3 -> V_6 ;
static unsigned char V_7 ;
V_7 = V_7 * 17 + 41 ;
if ( ( ( V_3 -> V_8 & V_9 ) == 0 ) && ( V_7 < V_3 -> V_10 ) ) {
V_3 -> V_11 = 0x70 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_3 -> V_15 = 1 ;
V_4 = V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , V_3 -> V_16 , V_3 -> V_17 ) ;
V_3 -> V_18 -= V_4 ;
V_3 -> V_19 += V_4 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_3 -> V_17 = 0 ;
} else
F_2 ( & V_3 -> V_20 , V_21 + ( ( V_5 + 1 ) * V_22 ) / 100 ) ;
}
static void F_3 ( struct V_2 * V_3 , unsigned char * V_23 , int V_24 )
{
unsigned char * V_25 , * V_26 = V_23 ;
int V_4 , V_27 ;
if ( V_24 > V_3 -> V_28 ) {
V_25 = L_1 ;
goto V_29;
}
if ( V_24 > V_3 -> V_28 ) {
V_25 = L_1 ;
goto V_29;
}
if ( V_26 [ 0 ] > 5 ) {
V_25 = L_2 ;
goto V_29;
}
if ( ( V_26 [ 0 ] != 0 ) && ( V_24 > 2 ) ) {
V_25 = L_3 ;
goto V_29;
}
if ( ( V_26 [ 0 ] == 0 ) && ( V_24 < 15 ) ) {
V_25 = L_4 ;
goto V_29;
}
V_27 = F_4 ( V_26 , V_3 -> V_16 , V_24 , V_3 -> V_30 ) ;
F_5 ( V_31 , & V_3 -> V_12 -> V_32 ) ;
switch ( V_26 [ 0 ] ) {
case 1 : V_3 -> V_30 = V_26 [ 1 ] ;
return;
case 2 : V_3 -> V_10 = V_26 [ 1 ] ;
return;
case 3 : V_3 -> V_6 = V_26 [ 1 ] ;
return;
case 4 :
return;
case 5 : V_3 -> V_33 = V_26 [ 1 ] ;
return;
}
if ( V_26 [ 0 ] != 0 )
return;
if ( V_3 -> V_33 == 1 ) {
V_3 -> V_11 = 0x70 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_3 -> V_15 = 1 ;
V_4 = V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , V_3 -> V_16 , V_27 ) ;
V_3 -> V_18 = V_27 - V_4 ;
V_3 -> V_19 = V_3 -> V_16 + V_4 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
} else {
V_3 -> V_18 = V_27 ;
V_3 -> V_19 = V_3 -> V_16 ;
V_3 -> V_17 = V_27 ;
F_1 ( ( unsigned long ) V_3 ) ;
}
return;
V_29:
V_3 -> V_34 -> V_35 . V_36 ++ ;
F_6 ( V_3 -> V_34 ) ;
if ( F_7 () )
F_8 ( V_37 L_5 , V_3 -> V_34 -> V_38 , V_25 ) ;
}
static T_1 F_9 ( struct V_39 * V_40 , struct V_41 * V_34 )
{
struct V_2 * V_3 = F_10 ( V_34 ) ;
F_11 ( & V_3 -> V_42 ) ;
F_12 ( V_34 ) ;
V_34 -> V_35 . V_43 += V_40 -> V_24 ;
F_3 ( V_3 , V_40 -> V_44 , V_40 -> V_24 ) ;
F_13 ( & V_3 -> V_42 ) ;
F_14 ( V_40 ) ;
return V_45 ;
}
static int F_15 ( struct V_41 * V_34 )
{
struct V_2 * V_3 = F_10 ( V_34 ) ;
if ( V_3 -> V_12 == NULL )
return - V_46 ;
return 0 ;
}
static int F_16 ( struct V_41 * V_34 )
{
struct V_2 * V_3 = F_10 ( V_34 ) ;
F_11 ( & V_3 -> V_42 ) ;
if ( V_3 -> V_12 ) {
F_17 ( V_31 , & V_3 -> V_12 -> V_32 ) ;
}
F_12 ( V_34 ) ;
F_13 ( & V_3 -> V_42 ) ;
return 0 ;
}
static int F_18 ( struct V_39 * V_40 , struct V_41 * V_34 ,
unsigned short type , const void * V_47 ,
const void * V_48 , unsigned V_24 )
{
#ifdef F_19
if ( type != V_49 )
return F_20 ( V_40 , V_34 , type , V_47 , V_48 , V_24 ) ;
#endif
return 0 ;
}
static int F_21 ( struct V_41 * V_34 , void * V_50 )
{
struct V_51 * V_52 = V_50 ;
F_22 ( V_34 ) ;
F_23 ( V_34 ) ;
memcpy ( V_34 -> V_53 , & V_52 -> V_54 , V_55 ) ;
F_24 ( V_34 ) ;
F_25 ( V_34 ) ;
return 0 ;
}
static int F_26 ( struct V_39 * V_40 )
{
#ifdef F_19
return F_27 ( V_40 ) ;
#else
return 0 ;
#endif
}
static void F_28 ( struct V_41 * V_34 )
{
V_34 -> V_56 = & V_57 ;
V_34 -> V_58 = V_59 ;
V_34 -> V_28 = V_60 ;
V_34 -> V_61 = V_62 ;
V_34 -> V_63 = & V_64 ;
V_34 -> V_65 = V_55 ;
V_34 -> type = V_66 ;
V_34 -> V_67 = 10 ;
memcpy ( V_34 -> V_68 , & V_69 , V_55 ) ;
memcpy ( V_34 -> V_53 , & V_70 , V_55 ) ;
V_34 -> V_32 = 0 ;
}
static void F_29 ( struct V_2 * V_3 , char V_71 )
{
struct V_39 * V_40 ;
int V_27 ;
unsigned char * V_72 ;
V_27 = V_3 -> V_73 + 1 ;
V_3 -> V_34 -> V_35 . V_74 += V_27 ;
if ( ( V_40 = F_30 ( V_27 ) ) == NULL )
goto V_75;
V_72 = F_31 ( V_40 , V_27 ) ;
* V_72 ++ = V_71 ;
memcpy ( V_72 , V_3 -> V_76 + 1 , V_27 ) ;
V_40 -> V_77 = F_32 ( V_40 , V_3 -> V_34 ) ;
F_33 ( V_40 ) ;
V_3 -> V_34 -> V_35 . V_78 ++ ;
return;
V_75:
V_3 -> V_34 -> V_35 . V_79 ++ ;
}
static struct V_2 * F_34 ( struct V_80 * V_12 )
{
struct V_2 * V_3 ;
F_35 ( & V_81 ) ;
V_3 = V_12 -> V_82 ;
if ( V_3 )
F_36 ( & V_3 -> V_83 ) ;
F_37 ( & V_81 ) ;
return V_3 ;
}
static void F_38 ( struct V_2 * V_3 )
{
if ( F_39 ( & V_3 -> V_83 ) )
F_40 ( & V_3 -> V_84 ) ;
}
static void F_41 ( struct V_80 * V_12 )
{
struct V_2 * V_3 = F_34 ( V_12 ) ;
int V_4 ;
if ( ! V_3 )
return;
if ( V_3 -> V_18 <= 0 ) {
V_3 -> V_34 -> V_35 . V_85 ++ ;
F_17 ( V_31 , & V_12 -> V_32 ) ;
V_3 -> V_15 = 0 ;
F_42 ( V_3 -> V_34 ) ;
goto V_86;
}
if ( V_3 -> V_15 ) {
V_4 = V_12 -> V_13 -> V_14 ( V_12 , V_3 -> V_19 , V_3 -> V_18 ) ;
V_3 -> V_18 -= V_4 ;
V_3 -> V_19 += V_4 ;
}
V_86:
F_38 ( V_3 ) ;
}
static void F_43 ( struct V_80 * V_12 ,
const unsigned char * V_87 , char * V_88 , int V_27 )
{
struct V_2 * V_3 ;
unsigned char V_89 [ 512 ] ;
int V_90 ;
if ( ! V_27 )
return;
V_3 = F_34 ( V_12 ) ;
if ( ! V_3 )
return;
memcpy ( V_89 , V_87 , V_27 < sizeof( V_89 ) ? V_27 : sizeof( V_89 ) ) ;
V_90 = V_27 ;
while ( V_27 ) {
V_27 -- ;
if ( V_88 && * V_88 ++ ) {
if ( ! F_44 ( V_91 , & V_3 -> V_32 ) )
V_3 -> V_34 -> V_35 . V_92 ++ ;
continue;
}
}
F_45 ( V_3 , V_89 , V_90 ) ;
F_38 ( V_3 ) ;
F_46 ( V_12 ) ;
}
static void F_47 ( struct V_2 * V_3 , int V_93 )
{
char * V_25 ;
switch ( V_93 ) {
default:
case V_94 :
V_25 = L_6 ;
break;
case V_95 :
V_25 = L_7 ;
break;
case V_96 :
V_25 = L_8 ;
break;
}
V_3 -> V_97 = V_93 ;
F_8 ( V_98 L_9 , V_3 -> V_34 -> V_38 , V_25 ) ;
}
static inline void F_48 ( struct V_2 * V_3 , int V_93 )
{
int V_99 = V_3 -> V_97 ;
if ( V_99 != V_93 )
F_47 ( V_3 , V_93 ) ;
}
static void F_49 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
static char V_100 = 0xe8 ;
V_3 -> V_101 = 0 ;
V_3 -> V_102 = 0 ;
V_3 -> V_103 = 1 ;
V_3 -> V_8 = 1 ;
V_3 -> V_17 = 0 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_100 , 1 ) ;
F_50 ( & V_3 -> V_104 ) ;
V_3 -> V_104 . V_44 = ( unsigned long ) V_3 ;
V_3 -> V_104 . V_105 = F_49 ;
V_3 -> V_104 . V_106 = V_21 + V_107 ;
F_51 ( & V_3 -> V_104 ) ;
}
static inline int F_52 ( struct V_2 * V_3 )
{
unsigned char V_108 = 0xe8 ;
F_48 ( V_3 , V_94 ) ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_108 , 1 ) ;
F_50 ( & V_3 -> V_104 ) ;
V_3 -> V_104 . V_44 = ( unsigned long ) V_3 ;
V_3 -> V_104 . V_105 = F_49 ;
V_3 -> V_104 . V_106 = V_21 + V_107 ;
F_51 ( & V_3 -> V_104 ) ;
return 0 ;
}
static int F_53 ( struct V_80 * V_12 )
{
char * V_109 = NULL , * V_16 = NULL ;
struct V_41 * V_34 ;
struct V_2 * V_3 ;
unsigned long V_24 ;
int V_110 = 0 ;
if ( ! F_54 ( V_111 ) )
return - V_112 ;
if ( V_12 -> V_13 -> V_14 == NULL )
return - V_113 ;
V_34 = F_55 ( sizeof( struct V_2 ) , L_10 , F_28 ) ;
if ( ! V_34 ) {
V_110 = - V_114 ;
goto V_86;
}
V_3 = F_10 ( V_34 ) ;
V_3 -> V_34 = V_34 ;
F_56 ( & V_3 -> V_42 ) ;
F_57 ( & V_3 -> V_83 , 1 ) ;
F_58 ( & V_3 -> V_84 , 0 ) ;
V_24 = V_34 -> V_28 * 2 ;
V_109 = F_59 ( V_24 + 4 , V_115 ) ;
V_16 = F_59 ( V_24 + 4 , V_115 ) ;
if ( V_109 == NULL || V_16 == NULL ) {
V_110 = - V_116 ;
goto V_117;
}
F_11 ( & V_3 -> V_42 ) ;
V_3 -> V_12 = V_12 ;
V_3 -> V_109 = V_109 ;
V_3 -> V_16 = V_16 ;
V_3 -> V_28 = V_118 + 73 ;
V_3 -> V_119 = V_24 ;
V_3 -> V_73 = 0 ;
V_3 -> V_101 = 0 ;
V_3 -> V_102 = 0 ;
V_3 -> V_18 = 0 ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = 0 ;
V_3 -> V_30 = V_120 ;
V_3 -> V_10 = V_121 ;
V_3 -> V_6 = V_122 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_103 = 1 ;
V_3 -> V_8 = 1 ;
V_3 -> V_17 = 0 ;
V_3 -> V_15 = 0 ;
F_6 ( V_34 ) ;
F_60 ( & V_3 -> V_20 ) ;
V_3 -> V_20 . V_105 = F_1 ;
V_3 -> V_20 . V_44 = ( unsigned long ) V_3 ;
F_60 ( & V_3 -> V_104 ) ;
F_13 ( & V_3 -> V_42 ) ;
V_12 -> V_82 = V_3 ;
V_12 -> V_123 = 65536 ;
V_110 = F_61 ( V_34 ) ;
if ( V_110 )
goto V_117;
F_52 ( V_3 ) ;
return 0 ;
V_117:
F_62 ( V_16 ) ;
F_62 ( V_109 ) ;
if ( V_34 )
V_59 ( V_34 ) ;
V_86:
return V_110 ;
}
static void F_63 ( struct V_80 * V_12 )
{
struct V_2 * V_3 ;
F_64 ( & V_81 ) ;
V_3 = V_12 -> V_82 ;
V_12 -> V_82 = NULL ;
F_65 ( & V_81 ) ;
if ( ! V_3 )
return;
if ( ! F_39 ( & V_3 -> V_83 ) )
F_66 ( & V_3 -> V_84 ) ;
F_67 ( V_3 -> V_34 ) ;
F_50 ( & V_3 -> V_20 ) ;
F_50 ( & V_3 -> V_104 ) ;
F_62 ( V_3 -> V_109 ) ;
F_62 ( V_3 -> V_16 ) ;
}
static int F_68 ( struct V_80 * V_12 , struct V_124 * V_124 ,
unsigned int V_71 , unsigned long V_125 )
{
struct V_2 * V_3 = F_34 ( V_12 ) ;
struct V_41 * V_34 ;
unsigned int V_126 , V_110 ;
if ( ! V_3 )
return - V_127 ;
V_34 = V_3 -> V_34 ;
switch( V_71 ) {
case V_128 :
V_110 = F_69 ( ( void V_129 * ) V_125 , V_34 -> V_38 ,
strlen ( V_34 -> V_38 ) + 1 ) ? - V_130 : 0 ;
break;
case V_131 :
V_110 = F_70 ( 0 , ( int V_129 * ) V_125 ) ;
break;
case V_132 :
if ( F_71 ( V_126 , ( int V_129 * ) V_125 ) ) {
V_110 = - V_130 ;
break;
}
V_3 -> V_133 = V_126 ;
V_34 -> V_65 = V_55 ;
V_34 -> V_61 = V_134 +
V_62 + 3 ;
V_34 -> type = V_66 ;
V_110 = 0 ;
break;
case V_135 : {
char V_50 [ V_55 ] ;
if ( F_72 ( & V_50 ,
( void V_129 * ) V_125 , V_55 ) ) {
V_110 = - V_130 ;
break;
}
F_22 ( V_34 ) ;
memcpy ( V_34 -> V_53 , & V_50 , V_55 ) ;
F_25 ( V_34 ) ;
V_110 = 0 ;
break;
}
default:
V_110 = F_73 ( V_12 , V_124 , V_71 , V_125 ) ;
}
F_38 ( V_3 ) ;
return V_110 ;
}
static long F_74 ( struct V_80 * V_12 , struct V_124 * V_124 ,
unsigned int V_71 , unsigned long V_125 )
{
switch ( V_71 ) {
case V_128 :
case V_131 :
case V_132 :
case V_135 :
return F_68 ( V_12 , V_124 , V_71 ,
( unsigned long ) F_75 ( V_125 ) ) ;
}
return - V_136 ;
}
static int T_2 F_76 ( void )
{
int V_103 ;
F_8 ( V_137 ) ;
if ( ( V_103 = F_77 ( V_138 , & V_139 ) ) != 0 )
F_8 ( V_140 , V_103 ) ;
return V_103 ;
}
static void T_3 F_78 ( void )
{
int V_141 ;
if ( ( V_141 = F_79 ( V_138 ) ) )
F_8 ( V_142 , V_141 ) ;
}
static int F_4 ( unsigned char * V_143 , unsigned char * V_144 ,
int V_145 , unsigned char V_30 )
{
int V_27 = 0 ;
unsigned char V_146 = 0 , V_89 [ 400 ] ;
int V_147 = 0 ;
V_144 [ V_147 ++ ] = V_148 | V_149 ;
V_144 [ V_147 ++ ] = V_150 ;
V_89 [ 0 ] = V_30 ;
for ( V_27 = 1 ; V_27 < V_145 ; V_27 ++ )
V_89 [ V_27 ] = V_143 [ V_27 ] ;
for ( V_27 = 0 ; V_27 < V_145 ; V_27 ++ )
V_146 += V_89 [ V_27 ] ;
V_89 [ V_145 ] = ( unsigned char ) 0xff - V_146 ;
for ( V_27 = 0 ; V_27 <= V_145 ; V_27 ++ ) {
if ( ( V_27 % 3 ) == 0 ) {
V_144 [ V_147 ++ ] = ( V_89 [ V_27 ] & 0x3f ) ;
V_144 [ V_147 ] = ( ( V_89 [ V_27 ] >> 2 ) & 0x30 ) ;
} else if ( ( V_27 % 3 ) == 1 ) {
V_144 [ V_147 ++ ] |= ( V_89 [ V_27 ] & 0x0f ) ;
V_144 [ V_147 ] = ( ( V_89 [ V_27 ] >> 2 ) & 0x3c ) ;
} else {
V_144 [ V_147 ++ ] |= ( V_89 [ V_27 ] & 0x03 ) ;
V_144 [ V_147 ++ ] = ( V_89 [ V_27 ] >> 2 ) ;
}
}
if ( ( V_145 % 3 ) != 2 )
V_147 ++ ;
V_144 [ V_147 ++ ] = V_150 ;
return V_147 ;
}
static void F_80 ( struct V_2 * V_3 , unsigned char V_108 )
{
unsigned char * V_89 ;
if ( V_3 -> V_101 != 3 ) {
V_3 -> V_151 [ V_3 -> V_101 ++ ] = V_108 ;
return;
}
V_89 = V_3 -> V_151 ;
V_3 -> V_76 [ V_3 -> V_102 ++ ] =
V_89 [ 0 ] | ( ( V_89 [ 1 ] << 2 ) & 0xc0 ) ;
V_3 -> V_76 [ V_3 -> V_102 ++ ] =
( V_89 [ 1 ] & 0x0f ) | ( ( V_89 [ 2 ] << 2 ) & 0xf0 ) ;
V_3 -> V_76 [ V_3 -> V_102 ++ ] =
( V_89 [ 2 ] & 0x03 ) | ( V_108 << 2 ) ;
V_3 -> V_101 = 0 ;
}
static void F_81 ( struct V_2 * V_3 , unsigned char V_71 )
{
unsigned char V_1 ;
int V_4 ;
V_1 = V_71 & V_152 ;
if ( ( V_71 & V_153 ) != 0 ) {
if ( ( ( V_3 -> V_103 & V_9 ) == 0 ) &&
( ( V_71 & V_154 ) == V_154 ) ) {
if ( V_3 -> V_103 != 1 )
F_8 ( V_37 L_11 ) ;
else
V_3 -> V_103 = 0 ;
V_71 &= ~ V_154 ;
}
V_3 -> V_103 = V_71 & V_153 ;
} else {
if ( ( V_3 -> V_17 != 0 ) && ( V_3 -> V_33 == 1 ) ) {
V_3 -> V_11 = 0x70 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_3 -> V_15 = 1 ;
V_4 = V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , V_3 -> V_16 , V_3 -> V_17 ) ;
V_3 -> V_18 -= V_4 ;
V_3 -> V_19 += V_4 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_17 = 0 ;
}
}
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
if ( V_3 -> V_97 == V_96 ) {
F_50 ( & V_3 -> V_104 ) ;
V_3 -> V_104 . V_44 = ( unsigned long ) V_3 ;
V_3 -> V_104 . V_105 = F_49 ;
V_3 -> V_104 . V_106 = V_21 + V_155 ;
F_51 ( & V_3 -> V_104 ) ;
}
V_3 -> V_8 = V_71 & V_153 ;
}
static void F_82 ( struct V_2 * V_3 , unsigned char V_71 )
{
unsigned char V_146 = 0 , V_156 = 0 , V_1 ;
short V_157 ;
V_1 = V_71 & V_152 ;
switch ( V_71 & V_158 ) {
case V_150 :
if ( ( V_3 -> V_101 == 0 ) && ( V_3 -> V_102 == 0 ) ) {
if ( ( V_3 -> V_103 & V_154 ) ==
V_154 ) {
V_3 -> V_11 = 0x68 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
}
} else {
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_156 = V_3 -> V_101 ;
if ( V_156 != 0 )
for ( V_157 = V_156 ; V_157 <= 3 ; V_157 ++ )
F_80 ( V_3 , 0 ) ;
if ( V_156 == 2 )
V_3 -> V_102 -= 2 ;
else if ( V_156 == 3 )
V_3 -> V_102 -= 1 ;
for ( V_157 = 0 ; V_157 < V_3 -> V_102 ; V_157 ++ )
V_146 += V_3 -> V_76 [ V_157 ] ;
if ( V_146 != V_159 ) {
F_8 ( V_37 L_12 , V_146 ) ;
} else {
V_3 -> V_73 = V_3 -> V_102 - 2 ;
F_29 ( V_3 , 0 ) ;
}
V_3 -> V_102 = 0 ;
}
break;
case V_160 : F_8 ( V_37 L_13 ) ;
break;
case V_161 : F_8 ( V_37 L_14 ) ;
break;
case V_162 :
F_8 ( V_37 L_15 ) ;
}
}
static void
F_45 ( struct V_2 * V_3 , unsigned char * V_163 , int V_27 )
{
unsigned char V_108 ;
int V_90 ;
for ( V_90 = 0 ; V_90 < V_27 ; V_90 ++ ) {
V_108 = V_163 [ V_90 ] ;
if ( V_108 == V_164 ) {
F_48 ( V_3 , V_96 ) ;
F_50 ( & V_3 -> V_104 ) ;
}
if ( ( V_108 & V_148 ) != 0 )
F_81 ( V_3 , V_108 ) ;
else if ( ( V_108 & V_165 ) != 0 )
F_82 ( V_3 , V_108 ) ;
else if ( ( V_3 -> V_103 & V_154 ) == V_154 )
F_80 ( V_3 , V_108 ) ;
}
}
