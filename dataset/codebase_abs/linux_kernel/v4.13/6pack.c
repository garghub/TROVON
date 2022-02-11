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
V_34 -> V_57 = true ;
V_34 -> V_28 = V_58 ;
V_34 -> V_59 = V_60 ;
V_34 -> V_61 = & V_62 ;
V_34 -> V_63 = V_54 ;
V_34 -> type = V_64 ;
V_34 -> V_65 = 10 ;
memcpy ( V_34 -> V_66 , & V_67 , V_54 ) ;
memcpy ( V_34 -> V_52 , & V_68 , V_54 ) ;
V_34 -> V_32 = 0 ;
}
static void F_26 ( struct V_2 * V_3 , char V_69 )
{
struct V_39 * V_40 ;
int V_27 ;
unsigned char * V_70 ;
V_27 = V_3 -> V_71 + 1 ;
V_3 -> V_34 -> V_35 . V_72 += V_27 ;
if ( ( V_40 = F_27 ( V_27 ) ) == NULL )
goto V_73;
V_70 = F_28 ( V_40 , V_27 ) ;
* V_70 ++ = V_69 ;
memcpy ( V_70 , V_3 -> V_74 + 1 , V_27 ) ;
V_40 -> V_42 = F_29 ( V_40 , V_3 -> V_34 ) ;
F_30 ( V_40 ) ;
V_3 -> V_34 -> V_35 . V_75 ++ ;
return;
V_73:
V_3 -> V_34 -> V_35 . V_76 ++ ;
}
static struct V_2 * F_31 ( struct V_77 * V_12 )
{
struct V_2 * V_3 ;
F_32 ( & V_78 ) ;
V_3 = V_12 -> V_79 ;
if ( V_3 )
F_33 ( & V_3 -> V_80 ) ;
F_34 ( & V_78 ) ;
return V_3 ;
}
static void F_35 ( struct V_2 * V_3 )
{
if ( F_36 ( & V_3 -> V_80 ) )
F_37 ( & V_3 -> V_81 ) ;
}
static void F_38 ( struct V_77 * V_12 )
{
struct V_2 * V_3 = F_31 ( V_12 ) ;
int V_4 ;
if ( ! V_3 )
return;
if ( V_3 -> V_18 <= 0 ) {
V_3 -> V_34 -> V_35 . V_82 ++ ;
F_19 ( V_31 , & V_12 -> V_32 ) ;
V_3 -> V_15 = 0 ;
F_39 ( V_3 -> V_34 ) ;
goto V_83;
}
if ( V_3 -> V_15 ) {
V_4 = V_12 -> V_13 -> V_14 ( V_12 , V_3 -> V_19 , V_3 -> V_18 ) ;
V_3 -> V_18 -= V_4 ;
V_3 -> V_19 += V_4 ;
}
V_83:
F_35 ( V_3 ) ;
}
static void F_40 ( struct V_77 * V_12 ,
const unsigned char * V_84 , char * V_85 , int V_27 )
{
struct V_2 * V_3 ;
int V_86 ;
if ( ! V_27 )
return;
V_3 = F_31 ( V_12 ) ;
if ( ! V_3 )
return;
V_86 = V_27 ;
while ( V_27 ) {
V_27 -- ;
if ( V_85 && * V_85 ++ ) {
if ( ! F_41 ( V_87 , & V_3 -> V_32 ) )
V_3 -> V_34 -> V_35 . V_88 ++ ;
continue;
}
}
F_42 ( V_3 , V_84 , V_86 ) ;
F_35 ( V_3 ) ;
F_43 ( V_12 ) ;
}
static void F_44 ( struct V_2 * V_3 , int V_89 )
{
char * V_25 ;
switch ( V_89 ) {
default:
case V_90 :
V_25 = L_6 ;
break;
case V_91 :
V_25 = L_7 ;
break;
case V_92 :
V_25 = L_8 ;
break;
}
V_3 -> V_93 = V_89 ;
F_8 ( V_94 L_9 , V_3 -> V_34 -> V_38 , V_25 ) ;
}
static inline void F_45 ( struct V_2 * V_3 , int V_89 )
{
int V_95 = V_3 -> V_93 ;
if ( V_95 != V_89 )
F_44 ( V_3 , V_89 ) ;
}
static void F_46 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
static char V_96 = 0xe8 ;
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 1 ;
V_3 -> V_8 = 1 ;
V_3 -> V_17 = 0 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_96 , 1 ) ;
F_47 ( & V_3 -> V_100 ) ;
V_3 -> V_100 . V_46 = ( unsigned long ) V_3 ;
V_3 -> V_100 . V_101 = F_46 ;
V_3 -> V_100 . V_102 = V_21 + V_103 ;
F_48 ( & V_3 -> V_100 ) ;
}
static inline int F_49 ( struct V_2 * V_3 )
{
unsigned char V_104 = 0xe8 ;
F_45 ( V_3 , V_90 ) ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_104 , 1 ) ;
F_47 ( & V_3 -> V_100 ) ;
V_3 -> V_100 . V_46 = ( unsigned long ) V_3 ;
V_3 -> V_100 . V_101 = F_46 ;
V_3 -> V_100 . V_102 = V_21 + V_103 ;
F_48 ( & V_3 -> V_100 ) ;
return 0 ;
}
static int F_50 ( struct V_77 * V_12 )
{
char * V_105 = NULL , * V_16 = NULL ;
struct V_41 * V_34 ;
struct V_2 * V_3 ;
unsigned long V_24 ;
int V_106 = 0 ;
if ( ! F_51 ( V_107 ) )
return - V_108 ;
if ( V_12 -> V_13 -> V_14 == NULL )
return - V_109 ;
V_34 = F_52 ( sizeof( struct V_2 ) , L_10 , V_110 ,
F_25 ) ;
if ( ! V_34 ) {
V_106 = - V_111 ;
goto V_83;
}
V_3 = F_10 ( V_34 ) ;
V_3 -> V_34 = V_34 ;
F_53 ( & V_3 -> V_44 ) ;
F_54 ( & V_3 -> V_80 , 1 ) ;
F_55 ( & V_3 -> V_81 , 0 ) ;
V_24 = V_34 -> V_28 * 2 ;
V_105 = F_56 ( V_24 + 4 , V_112 ) ;
V_16 = F_56 ( V_24 + 4 , V_112 ) ;
if ( V_105 == NULL || V_16 == NULL ) {
V_106 = - V_113 ;
goto V_114;
}
F_13 ( & V_3 -> V_44 ) ;
V_3 -> V_12 = V_12 ;
V_3 -> V_105 = V_105 ;
V_3 -> V_16 = V_16 ;
V_3 -> V_28 = V_115 + 73 ;
V_3 -> V_116 = V_24 ;
V_3 -> V_71 = 0 ;
V_3 -> V_97 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> V_18 = 0 ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = 0 ;
V_3 -> V_30 = V_117 ;
V_3 -> V_10 = V_118 ;
V_3 -> V_6 = V_119 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_99 = 1 ;
V_3 -> V_8 = 1 ;
V_3 -> V_17 = 0 ;
V_3 -> V_15 = 0 ;
F_6 ( V_34 ) ;
F_57 ( & V_3 -> V_20 ) ;
V_3 -> V_20 . V_101 = F_1 ;
V_3 -> V_20 . V_46 = ( unsigned long ) V_3 ;
F_57 ( & V_3 -> V_100 ) ;
F_15 ( & V_3 -> V_44 ) ;
V_12 -> V_79 = V_3 ;
V_12 -> V_120 = 65536 ;
V_106 = F_58 ( V_34 ) ;
if ( V_106 )
goto V_114;
F_49 ( V_3 ) ;
return 0 ;
V_114:
F_59 ( V_16 ) ;
F_59 ( V_105 ) ;
F_60 ( V_34 ) ;
V_83:
return V_106 ;
}
static void F_61 ( struct V_77 * V_12 )
{
struct V_2 * V_3 ;
F_62 ( & V_78 ) ;
V_3 = V_12 -> V_79 ;
V_12 -> V_79 = NULL ;
F_63 ( & V_78 ) ;
if ( ! V_3 )
return;
if ( ! F_36 ( & V_3 -> V_80 ) )
F_64 ( & V_3 -> V_81 ) ;
F_14 ( V_3 -> V_34 ) ;
F_65 ( & V_3 -> V_20 ) ;
F_65 ( & V_3 -> V_100 ) ;
F_59 ( V_3 -> V_105 ) ;
F_59 ( V_3 -> V_16 ) ;
F_66 ( V_3 -> V_34 ) ;
}
static int F_67 ( struct V_77 * V_12 , struct V_121 * V_121 ,
unsigned int V_69 , unsigned long V_122 )
{
struct V_2 * V_3 = F_31 ( V_12 ) ;
struct V_41 * V_34 ;
unsigned int V_123 , V_106 ;
if ( ! V_3 )
return - V_124 ;
V_34 = V_3 -> V_34 ;
switch( V_69 ) {
case V_125 :
V_106 = F_68 ( ( void V_126 * ) V_122 , V_34 -> V_38 ,
strlen ( V_34 -> V_38 ) + 1 ) ? - V_127 : 0 ;
break;
case V_128 :
V_106 = F_69 ( 0 , ( int V_126 * ) V_122 ) ;
break;
case V_129 :
if ( F_70 ( V_123 , ( int V_126 * ) V_122 ) ) {
V_106 = - V_127 ;
break;
}
V_3 -> V_130 = V_123 ;
V_34 -> V_63 = V_54 ;
V_34 -> V_59 = V_131 +
V_60 + 3 ;
V_34 -> type = V_64 ;
V_106 = 0 ;
break;
case V_132 : {
char V_49 [ V_54 ] ;
if ( F_71 ( & V_49 ,
( void V_126 * ) V_122 , V_54 ) ) {
V_106 = - V_127 ;
break;
}
F_21 ( V_34 ) ;
memcpy ( V_34 -> V_52 , & V_49 , V_54 ) ;
F_24 ( V_34 ) ;
V_106 = 0 ;
break;
}
default:
V_106 = F_72 ( V_12 , V_121 , V_69 , V_122 ) ;
}
F_35 ( V_3 ) ;
return V_106 ;
}
static long F_73 ( struct V_77 * V_12 , struct V_121 * V_121 ,
unsigned int V_69 , unsigned long V_122 )
{
switch ( V_69 ) {
case V_125 :
case V_128 :
case V_129 :
case V_132 :
return F_67 ( V_12 , V_121 , V_69 ,
( unsigned long ) F_74 ( V_122 ) ) ;
}
return - V_133 ;
}
static int T_2 F_75 ( void )
{
int V_99 ;
F_8 ( V_134 ) ;
if ( ( V_99 = F_76 ( V_135 , & V_136 ) ) != 0 )
F_8 ( V_137 , V_99 ) ;
return V_99 ;
}
static void T_3 F_77 ( void )
{
int V_138 ;
if ( ( V_138 = F_78 ( V_135 ) ) )
F_8 ( V_139 , V_138 ) ;
}
static int F_4 ( unsigned char * V_140 , unsigned char * V_141 ,
int V_142 , unsigned char V_30 )
{
int V_27 = 0 ;
unsigned char V_143 = 0 , V_144 [ 400 ] ;
int V_145 = 0 ;
V_141 [ V_145 ++ ] = V_146 | V_147 ;
V_141 [ V_145 ++ ] = V_148 ;
V_144 [ 0 ] = V_30 ;
for ( V_27 = 1 ; V_27 < V_142 ; V_27 ++ )
V_144 [ V_27 ] = V_140 [ V_27 ] ;
for ( V_27 = 0 ; V_27 < V_142 ; V_27 ++ )
V_143 += V_144 [ V_27 ] ;
V_144 [ V_142 ] = ( unsigned char ) 0xff - V_143 ;
for ( V_27 = 0 ; V_27 <= V_142 ; V_27 ++ ) {
if ( ( V_27 % 3 ) == 0 ) {
V_141 [ V_145 ++ ] = ( V_144 [ V_27 ] & 0x3f ) ;
V_141 [ V_145 ] = ( ( V_144 [ V_27 ] >> 2 ) & 0x30 ) ;
} else if ( ( V_27 % 3 ) == 1 ) {
V_141 [ V_145 ++ ] |= ( V_144 [ V_27 ] & 0x0f ) ;
V_141 [ V_145 ] = ( ( V_144 [ V_27 ] >> 2 ) & 0x3c ) ;
} else {
V_141 [ V_145 ++ ] |= ( V_144 [ V_27 ] & 0x03 ) ;
V_141 [ V_145 ++ ] = ( V_144 [ V_27 ] >> 2 ) ;
}
}
if ( ( V_142 % 3 ) != 2 )
V_145 ++ ;
V_141 [ V_145 ++ ] = V_148 ;
return V_145 ;
}
static void F_79 ( struct V_2 * V_3 , unsigned char V_104 )
{
unsigned char * V_144 ;
if ( V_3 -> V_97 != 3 ) {
V_3 -> V_149 [ V_3 -> V_97 ++ ] = V_104 ;
return;
}
V_144 = V_3 -> V_149 ;
V_3 -> V_74 [ V_3 -> V_98 ++ ] =
V_144 [ 0 ] | ( ( V_144 [ 1 ] << 2 ) & 0xc0 ) ;
V_3 -> V_74 [ V_3 -> V_98 ++ ] =
( V_144 [ 1 ] & 0x0f ) | ( ( V_144 [ 2 ] << 2 ) & 0xf0 ) ;
V_3 -> V_74 [ V_3 -> V_98 ++ ] =
( V_144 [ 2 ] & 0x03 ) | ( V_104 << 2 ) ;
V_3 -> V_97 = 0 ;
}
static void F_80 ( struct V_2 * V_3 , unsigned char V_69 )
{
unsigned char V_1 ;
int V_4 ;
V_1 = V_69 & V_150 ;
if ( ( V_69 & V_151 ) != 0 ) {
if ( ( ( V_3 -> V_99 & V_9 ) == 0 ) &&
( ( V_69 & V_152 ) == V_152 ) ) {
if ( V_3 -> V_99 != 1 )
F_8 ( V_37 L_11 ) ;
else
V_3 -> V_99 = 0 ;
V_69 &= ~ V_152 ;
}
V_3 -> V_99 = V_69 & V_151 ;
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
if ( V_3 -> V_93 == V_92 ) {
F_47 ( & V_3 -> V_100 ) ;
V_3 -> V_100 . V_46 = ( unsigned long ) V_3 ;
V_3 -> V_100 . V_101 = F_46 ;
V_3 -> V_100 . V_102 = V_21 + V_153 ;
F_48 ( & V_3 -> V_100 ) ;
}
V_3 -> V_8 = V_69 & V_151 ;
}
static void F_81 ( struct V_2 * V_3 , unsigned char V_69 )
{
unsigned char V_143 = 0 , V_154 = 0 , V_1 ;
short V_155 ;
V_1 = V_69 & V_150 ;
switch ( V_69 & V_156 ) {
case V_148 :
if ( ( V_3 -> V_97 == 0 ) && ( V_3 -> V_98 == 0 ) ) {
if ( ( V_3 -> V_99 & V_152 ) ==
V_152 ) {
V_3 -> V_11 = 0x68 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
}
} else {
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_154 = V_3 -> V_97 ;
if ( V_154 != 0 )
for ( V_155 = V_154 ; V_155 <= 3 ; V_155 ++ )
F_79 ( V_3 , 0 ) ;
if ( V_154 == 2 )
V_3 -> V_98 -= 2 ;
else if ( V_154 == 3 )
V_3 -> V_98 -= 1 ;
for ( V_155 = 0 ; V_155 < V_3 -> V_98 ; V_155 ++ )
V_143 += V_3 -> V_74 [ V_155 ] ;
if ( V_143 != V_157 ) {
F_8 ( V_37 L_12 , V_143 ) ;
} else {
V_3 -> V_71 = V_3 -> V_98 - 2 ;
F_26 ( V_3 , 0 ) ;
}
V_3 -> V_98 = 0 ;
}
break;
case V_158 : F_8 ( V_37 L_13 ) ;
break;
case V_159 : F_8 ( V_37 L_14 ) ;
break;
case V_160 :
F_8 ( V_37 L_15 ) ;
}
}
static void
F_42 ( struct V_2 * V_3 , const unsigned char * V_161 , int V_27 )
{
unsigned char V_104 ;
int V_86 ;
for ( V_86 = 0 ; V_86 < V_27 ; V_86 ++ ) {
V_104 = V_161 [ V_86 ] ;
if ( V_104 == V_162 ) {
F_45 ( V_3 , V_92 ) ;
F_47 ( & V_3 -> V_100 ) ;
}
if ( ( V_104 & V_146 ) != 0 )
F_80 ( V_3 , V_104 ) ;
else if ( ( V_104 & V_163 ) != 0 )
F_81 ( V_3 , V_104 ) ;
else if ( ( V_3 -> V_99 & V_152 ) == V_152 )
F_79 ( V_3 , V_104 ) ;
}
}
