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
if ( V_40 -> V_42 == F_11 ( V_43 ) )
return F_12 ( V_40 ) ;
F_13 ( & V_3 -> V_44 ) ;
F_14 ( V_34 ) ;
V_34 -> V_35 . V_45 += V_40 -> V_24 ;
F_3 ( V_3 , V_40 -> V_46 , V_40 -> V_24 ) ;
F_15 ( & V_3 -> V_44 ) ;
F_16 ( V_40 ) ;
return V_47 ;
}
static int F_17 ( struct V_41 * V_34 )
{
struct V_2 * V_3 = F_10 ( V_34 ) ;
if ( V_3 -> V_12 == NULL )
return - V_48 ;
return 0 ;
}
static int F_18 ( struct V_41 * V_34 )
{
struct V_2 * V_3 = F_10 ( V_34 ) ;
F_13 ( & V_3 -> V_44 ) ;
if ( V_3 -> V_12 ) {
F_19 ( V_31 , & V_3 -> V_12 -> V_32 ) ;
}
F_14 ( V_34 ) ;
F_15 ( & V_3 -> V_44 ) ;
return 0 ;
}
static int F_20 ( struct V_41 * V_34 , void * V_49 )
{
struct V_50 * V_51 = V_49 ;
F_21 ( V_34 ) ;
F_22 ( V_34 ) ;
memcpy ( V_34 -> V_52 , & V_51 -> V_53 , V_54 ) ;
F_23 ( V_34 ) ;
F_24 ( V_34 ) ;
return 0 ;
}
static void F_25 ( struct V_41 * V_34 )
{
V_34 -> V_55 = & V_56 ;
V_34 -> V_57 = V_58 ;
V_34 -> V_28 = V_59 ;
V_34 -> V_60 = V_61 ;
V_34 -> V_62 = & V_63 ;
V_34 -> V_64 = V_54 ;
V_34 -> type = V_65 ;
V_34 -> V_66 = 10 ;
memcpy ( V_34 -> V_67 , & V_68 , V_54 ) ;
memcpy ( V_34 -> V_52 , & V_69 , V_54 ) ;
V_34 -> V_32 = 0 ;
}
static void F_26 ( struct V_2 * V_3 , char V_70 )
{
struct V_39 * V_40 ;
int V_27 ;
unsigned char * V_71 ;
V_27 = V_3 -> V_72 + 1 ;
V_3 -> V_34 -> V_35 . V_73 += V_27 ;
if ( ( V_40 = F_27 ( V_27 ) ) == NULL )
goto V_74;
V_71 = F_28 ( V_40 , V_27 ) ;
* V_71 ++ = V_70 ;
memcpy ( V_71 , V_3 -> V_75 + 1 , V_27 ) ;
V_40 -> V_42 = F_29 ( V_40 , V_3 -> V_34 ) ;
F_30 ( V_40 ) ;
V_3 -> V_34 -> V_35 . V_76 ++ ;
return;
V_74:
V_3 -> V_34 -> V_35 . V_77 ++ ;
}
static struct V_2 * F_31 ( struct V_78 * V_12 )
{
struct V_2 * V_3 ;
F_32 ( & V_79 ) ;
V_3 = V_12 -> V_80 ;
if ( V_3 )
F_33 ( & V_3 -> V_81 ) ;
F_34 ( & V_79 ) ;
return V_3 ;
}
static void F_35 ( struct V_2 * V_3 )
{
if ( F_36 ( & V_3 -> V_81 ) )
F_37 ( & V_3 -> V_82 ) ;
}
static void F_38 ( struct V_78 * V_12 )
{
struct V_2 * V_3 = F_31 ( V_12 ) ;
int V_4 ;
if ( ! V_3 )
return;
if ( V_3 -> V_18 <= 0 ) {
V_3 -> V_34 -> V_35 . V_83 ++ ;
F_19 ( V_31 , & V_12 -> V_32 ) ;
V_3 -> V_15 = 0 ;
F_39 ( V_3 -> V_34 ) ;
goto V_84;
}
if ( V_3 -> V_15 ) {
V_4 = V_12 -> V_13 -> V_14 ( V_12 , V_3 -> V_19 , V_3 -> V_18 ) ;
V_3 -> V_18 -= V_4 ;
V_3 -> V_19 += V_4 ;
}
V_84:
F_35 ( V_3 ) ;
}
static void F_40 ( struct V_78 * V_12 ,
const unsigned char * V_85 , char * V_86 , int V_27 )
{
struct V_2 * V_3 ;
unsigned char V_87 [ 512 ] ;
int V_88 ;
if ( ! V_27 )
return;
V_3 = F_31 ( V_12 ) ;
if ( ! V_3 )
return;
memcpy ( V_87 , V_85 , V_27 < sizeof( V_87 ) ? V_27 : sizeof( V_87 ) ) ;
V_88 = V_27 ;
while ( V_27 ) {
V_27 -- ;
if ( V_86 && * V_86 ++ ) {
if ( ! F_41 ( V_89 , & V_3 -> V_32 ) )
V_3 -> V_34 -> V_35 . V_90 ++ ;
continue;
}
}
F_42 ( V_3 , V_87 , V_88 ) ;
F_35 ( V_3 ) ;
F_43 ( V_12 ) ;
}
static void F_44 ( struct V_2 * V_3 , int V_91 )
{
char * V_25 ;
switch ( V_91 ) {
default:
case V_92 :
V_25 = L_6 ;
break;
case V_93 :
V_25 = L_7 ;
break;
case V_94 :
V_25 = L_8 ;
break;
}
V_3 -> V_95 = V_91 ;
F_8 ( V_96 L_9 , V_3 -> V_34 -> V_38 , V_25 ) ;
}
static inline void F_45 ( struct V_2 * V_3 , int V_91 )
{
int V_97 = V_3 -> V_95 ;
if ( V_97 != V_91 )
F_44 ( V_3 , V_91 ) ;
}
static void F_46 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
static char V_98 = 0xe8 ;
V_3 -> V_99 = 0 ;
V_3 -> V_100 = 0 ;
V_3 -> V_101 = 1 ;
V_3 -> V_8 = 1 ;
V_3 -> V_17 = 0 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_98 , 1 ) ;
F_47 ( & V_3 -> V_102 ) ;
V_3 -> V_102 . V_46 = ( unsigned long ) V_3 ;
V_3 -> V_102 . V_103 = F_46 ;
V_3 -> V_102 . V_104 = V_21 + V_105 ;
F_48 ( & V_3 -> V_102 ) ;
}
static inline int F_49 ( struct V_2 * V_3 )
{
unsigned char V_106 = 0xe8 ;
F_45 ( V_3 , V_92 ) ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_106 , 1 ) ;
F_47 ( & V_3 -> V_102 ) ;
V_3 -> V_102 . V_46 = ( unsigned long ) V_3 ;
V_3 -> V_102 . V_103 = F_46 ;
V_3 -> V_102 . V_104 = V_21 + V_105 ;
F_48 ( & V_3 -> V_102 ) ;
return 0 ;
}
static int F_50 ( struct V_78 * V_12 )
{
char * V_107 = NULL , * V_16 = NULL ;
struct V_41 * V_34 ;
struct V_2 * V_3 ;
unsigned long V_24 ;
int V_108 = 0 ;
if ( ! F_51 ( V_109 ) )
return - V_110 ;
if ( V_12 -> V_13 -> V_14 == NULL )
return - V_111 ;
V_34 = F_52 ( sizeof( struct V_2 ) , L_10 , V_112 ,
F_25 ) ;
if ( ! V_34 ) {
V_108 = - V_113 ;
goto V_84;
}
V_3 = F_10 ( V_34 ) ;
V_3 -> V_34 = V_34 ;
F_53 ( & V_3 -> V_44 ) ;
F_54 ( & V_3 -> V_81 , 1 ) ;
F_55 ( & V_3 -> V_82 , 0 ) ;
V_24 = V_34 -> V_28 * 2 ;
V_107 = F_56 ( V_24 + 4 , V_114 ) ;
V_16 = F_56 ( V_24 + 4 , V_114 ) ;
if ( V_107 == NULL || V_16 == NULL ) {
V_108 = - V_115 ;
goto V_116;
}
F_13 ( & V_3 -> V_44 ) ;
V_3 -> V_12 = V_12 ;
V_3 -> V_107 = V_107 ;
V_3 -> V_16 = V_16 ;
V_3 -> V_28 = V_117 + 73 ;
V_3 -> V_118 = V_24 ;
V_3 -> V_72 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_100 = 0 ;
V_3 -> V_18 = 0 ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = 0 ;
V_3 -> V_30 = V_119 ;
V_3 -> V_10 = V_120 ;
V_3 -> V_6 = V_121 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_101 = 1 ;
V_3 -> V_8 = 1 ;
V_3 -> V_17 = 0 ;
V_3 -> V_15 = 0 ;
F_6 ( V_34 ) ;
F_57 ( & V_3 -> V_20 ) ;
V_3 -> V_20 . V_103 = F_1 ;
V_3 -> V_20 . V_46 = ( unsigned long ) V_3 ;
F_57 ( & V_3 -> V_102 ) ;
F_15 ( & V_3 -> V_44 ) ;
V_12 -> V_80 = V_3 ;
V_12 -> V_122 = 65536 ;
V_108 = F_58 ( V_34 ) ;
if ( V_108 )
goto V_116;
F_49 ( V_3 ) ;
return 0 ;
V_116:
F_59 ( V_16 ) ;
F_59 ( V_107 ) ;
V_58 ( V_34 ) ;
V_84:
return V_108 ;
}
static void F_60 ( struct V_78 * V_12 )
{
struct V_2 * V_3 ;
F_61 ( & V_79 ) ;
V_3 = V_12 -> V_80 ;
V_12 -> V_80 = NULL ;
F_62 ( & V_79 ) ;
if ( ! V_3 )
return;
if ( ! F_36 ( & V_3 -> V_81 ) )
F_63 ( & V_3 -> V_82 ) ;
F_64 ( V_3 -> V_34 ) ;
F_47 ( & V_3 -> V_20 ) ;
F_47 ( & V_3 -> V_102 ) ;
F_59 ( V_3 -> V_107 ) ;
F_59 ( V_3 -> V_16 ) ;
}
static int F_65 ( struct V_78 * V_12 , struct V_123 * V_123 ,
unsigned int V_70 , unsigned long V_124 )
{
struct V_2 * V_3 = F_31 ( V_12 ) ;
struct V_41 * V_34 ;
unsigned int V_125 , V_108 ;
if ( ! V_3 )
return - V_126 ;
V_34 = V_3 -> V_34 ;
switch( V_70 ) {
case V_127 :
V_108 = F_66 ( ( void V_128 * ) V_124 , V_34 -> V_38 ,
strlen ( V_34 -> V_38 ) + 1 ) ? - V_129 : 0 ;
break;
case V_130 :
V_108 = F_67 ( 0 , ( int V_128 * ) V_124 ) ;
break;
case V_131 :
if ( F_68 ( V_125 , ( int V_128 * ) V_124 ) ) {
V_108 = - V_129 ;
break;
}
V_3 -> V_132 = V_125 ;
V_34 -> V_64 = V_54 ;
V_34 -> V_60 = V_133 +
V_61 + 3 ;
V_34 -> type = V_65 ;
V_108 = 0 ;
break;
case V_134 : {
char V_49 [ V_54 ] ;
if ( F_69 ( & V_49 ,
( void V_128 * ) V_124 , V_54 ) ) {
V_108 = - V_129 ;
break;
}
F_21 ( V_34 ) ;
memcpy ( V_34 -> V_52 , & V_49 , V_54 ) ;
F_24 ( V_34 ) ;
V_108 = 0 ;
break;
}
default:
V_108 = F_70 ( V_12 , V_123 , V_70 , V_124 ) ;
}
F_35 ( V_3 ) ;
return V_108 ;
}
static long F_71 ( struct V_78 * V_12 , struct V_123 * V_123 ,
unsigned int V_70 , unsigned long V_124 )
{
switch ( V_70 ) {
case V_127 :
case V_130 :
case V_131 :
case V_134 :
return F_65 ( V_12 , V_123 , V_70 ,
( unsigned long ) F_72 ( V_124 ) ) ;
}
return - V_135 ;
}
static int T_2 F_73 ( void )
{
int V_101 ;
F_8 ( V_136 ) ;
if ( ( V_101 = F_74 ( V_137 , & V_138 ) ) != 0 )
F_8 ( V_139 , V_101 ) ;
return V_101 ;
}
static void T_3 F_75 ( void )
{
int V_140 ;
if ( ( V_140 = F_76 ( V_137 ) ) )
F_8 ( V_141 , V_140 ) ;
}
static int F_4 ( unsigned char * V_142 , unsigned char * V_143 ,
int V_144 , unsigned char V_30 )
{
int V_27 = 0 ;
unsigned char V_145 = 0 , V_87 [ 400 ] ;
int V_146 = 0 ;
V_143 [ V_146 ++ ] = V_147 | V_148 ;
V_143 [ V_146 ++ ] = V_149 ;
V_87 [ 0 ] = V_30 ;
for ( V_27 = 1 ; V_27 < V_144 ; V_27 ++ )
V_87 [ V_27 ] = V_142 [ V_27 ] ;
for ( V_27 = 0 ; V_27 < V_144 ; V_27 ++ )
V_145 += V_87 [ V_27 ] ;
V_87 [ V_144 ] = ( unsigned char ) 0xff - V_145 ;
for ( V_27 = 0 ; V_27 <= V_144 ; V_27 ++ ) {
if ( ( V_27 % 3 ) == 0 ) {
V_143 [ V_146 ++ ] = ( V_87 [ V_27 ] & 0x3f ) ;
V_143 [ V_146 ] = ( ( V_87 [ V_27 ] >> 2 ) & 0x30 ) ;
} else if ( ( V_27 % 3 ) == 1 ) {
V_143 [ V_146 ++ ] |= ( V_87 [ V_27 ] & 0x0f ) ;
V_143 [ V_146 ] = ( ( V_87 [ V_27 ] >> 2 ) & 0x3c ) ;
} else {
V_143 [ V_146 ++ ] |= ( V_87 [ V_27 ] & 0x03 ) ;
V_143 [ V_146 ++ ] = ( V_87 [ V_27 ] >> 2 ) ;
}
}
if ( ( V_144 % 3 ) != 2 )
V_146 ++ ;
V_143 [ V_146 ++ ] = V_149 ;
return V_146 ;
}
static void F_77 ( struct V_2 * V_3 , unsigned char V_106 )
{
unsigned char * V_87 ;
if ( V_3 -> V_99 != 3 ) {
V_3 -> V_150 [ V_3 -> V_99 ++ ] = V_106 ;
return;
}
V_87 = V_3 -> V_150 ;
V_3 -> V_75 [ V_3 -> V_100 ++ ] =
V_87 [ 0 ] | ( ( V_87 [ 1 ] << 2 ) & 0xc0 ) ;
V_3 -> V_75 [ V_3 -> V_100 ++ ] =
( V_87 [ 1 ] & 0x0f ) | ( ( V_87 [ 2 ] << 2 ) & 0xf0 ) ;
V_3 -> V_75 [ V_3 -> V_100 ++ ] =
( V_87 [ 2 ] & 0x03 ) | ( V_106 << 2 ) ;
V_3 -> V_99 = 0 ;
}
static void F_78 ( struct V_2 * V_3 , unsigned char V_70 )
{
unsigned char V_1 ;
int V_4 ;
V_1 = V_70 & V_151 ;
if ( ( V_70 & V_152 ) != 0 ) {
if ( ( ( V_3 -> V_101 & V_9 ) == 0 ) &&
( ( V_70 & V_153 ) == V_153 ) ) {
if ( V_3 -> V_101 != 1 )
F_8 ( V_37 L_11 ) ;
else
V_3 -> V_101 = 0 ;
V_70 &= ~ V_153 ;
}
V_3 -> V_101 = V_70 & V_152 ;
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
if ( V_3 -> V_95 == V_94 ) {
F_47 ( & V_3 -> V_102 ) ;
V_3 -> V_102 . V_46 = ( unsigned long ) V_3 ;
V_3 -> V_102 . V_103 = F_46 ;
V_3 -> V_102 . V_104 = V_21 + V_154 ;
F_48 ( & V_3 -> V_102 ) ;
}
V_3 -> V_8 = V_70 & V_152 ;
}
static void F_79 ( struct V_2 * V_3 , unsigned char V_70 )
{
unsigned char V_145 = 0 , V_155 = 0 , V_1 ;
short V_156 ;
V_1 = V_70 & V_151 ;
switch ( V_70 & V_157 ) {
case V_149 :
if ( ( V_3 -> V_99 == 0 ) && ( V_3 -> V_100 == 0 ) ) {
if ( ( V_3 -> V_101 & V_153 ) ==
V_153 ) {
V_3 -> V_11 = 0x68 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
}
} else {
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_155 = V_3 -> V_99 ;
if ( V_155 != 0 )
for ( V_156 = V_155 ; V_156 <= 3 ; V_156 ++ )
F_77 ( V_3 , 0 ) ;
if ( V_155 == 2 )
V_3 -> V_100 -= 2 ;
else if ( V_155 == 3 )
V_3 -> V_100 -= 1 ;
for ( V_156 = 0 ; V_156 < V_3 -> V_100 ; V_156 ++ )
V_145 += V_3 -> V_75 [ V_156 ] ;
if ( V_145 != V_158 ) {
F_8 ( V_37 L_12 , V_145 ) ;
} else {
V_3 -> V_72 = V_3 -> V_100 - 2 ;
F_26 ( V_3 , 0 ) ;
}
V_3 -> V_100 = 0 ;
}
break;
case V_159 : F_8 ( V_37 L_13 ) ;
break;
case V_160 : F_8 ( V_37 L_14 ) ;
break;
case V_161 :
F_8 ( V_37 L_15 ) ;
}
}
static void
F_42 ( struct V_2 * V_3 , unsigned char * V_162 , int V_27 )
{
unsigned char V_106 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_27 ; V_88 ++ ) {
V_106 = V_162 [ V_88 ] ;
if ( V_106 == V_163 ) {
F_45 ( V_3 , V_94 ) ;
F_47 ( & V_3 -> V_102 ) ;
}
if ( ( V_106 & V_147 ) != 0 )
F_78 ( V_3 , V_106 ) ;
else if ( ( V_106 & V_164 ) != 0 )
F_79 ( V_3 , V_106 ) ;
else if ( ( V_3 -> V_101 & V_153 ) == V_153 )
F_77 ( V_3 , V_106 ) ;
}
}
