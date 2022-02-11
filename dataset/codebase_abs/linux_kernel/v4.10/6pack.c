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
int V_87 ;
if ( ! V_27 )
return;
V_3 = F_31 ( V_12 ) ;
if ( ! V_3 )
return;
V_87 = V_27 ;
while ( V_27 ) {
V_27 -- ;
if ( V_86 && * V_86 ++ ) {
if ( ! F_41 ( V_88 , & V_3 -> V_32 ) )
V_3 -> V_34 -> V_35 . V_89 ++ ;
continue;
}
}
F_42 ( V_3 , V_85 , V_87 ) ;
F_35 ( V_3 ) ;
F_43 ( V_12 ) ;
}
static void F_44 ( struct V_2 * V_3 , int V_90 )
{
char * V_25 ;
switch ( V_90 ) {
default:
case V_91 :
V_25 = L_6 ;
break;
case V_92 :
V_25 = L_7 ;
break;
case V_93 :
V_25 = L_8 ;
break;
}
V_3 -> V_94 = V_90 ;
F_8 ( V_95 L_9 , V_3 -> V_34 -> V_38 , V_25 ) ;
}
static inline void F_45 ( struct V_2 * V_3 , int V_90 )
{
int V_96 = V_3 -> V_94 ;
if ( V_96 != V_90 )
F_44 ( V_3 , V_90 ) ;
}
static void F_46 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
static char V_97 = 0xe8 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_100 = 1 ;
V_3 -> V_8 = 1 ;
V_3 -> V_17 = 0 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_97 , 1 ) ;
F_47 ( & V_3 -> V_101 ) ;
V_3 -> V_101 . V_46 = ( unsigned long ) V_3 ;
V_3 -> V_101 . V_102 = F_46 ;
V_3 -> V_101 . V_103 = V_21 + V_104 ;
F_48 ( & V_3 -> V_101 ) ;
}
static inline int F_49 ( struct V_2 * V_3 )
{
unsigned char V_105 = 0xe8 ;
F_45 ( V_3 , V_91 ) ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_105 , 1 ) ;
F_47 ( & V_3 -> V_101 ) ;
V_3 -> V_101 . V_46 = ( unsigned long ) V_3 ;
V_3 -> V_101 . V_102 = F_46 ;
V_3 -> V_101 . V_103 = V_21 + V_104 ;
F_48 ( & V_3 -> V_101 ) ;
return 0 ;
}
static int F_50 ( struct V_78 * V_12 )
{
char * V_106 = NULL , * V_16 = NULL ;
struct V_41 * V_34 ;
struct V_2 * V_3 ;
unsigned long V_24 ;
int V_107 = 0 ;
if ( ! F_51 ( V_108 ) )
return - V_109 ;
if ( V_12 -> V_13 -> V_14 == NULL )
return - V_110 ;
V_34 = F_52 ( sizeof( struct V_2 ) , L_10 , V_111 ,
F_25 ) ;
if ( ! V_34 ) {
V_107 = - V_112 ;
goto V_84;
}
V_3 = F_10 ( V_34 ) ;
V_3 -> V_34 = V_34 ;
F_53 ( & V_3 -> V_44 ) ;
F_54 ( & V_3 -> V_81 , 1 ) ;
F_55 ( & V_3 -> V_82 , 0 ) ;
V_24 = V_34 -> V_28 * 2 ;
V_106 = F_56 ( V_24 + 4 , V_113 ) ;
V_16 = F_56 ( V_24 + 4 , V_113 ) ;
if ( V_106 == NULL || V_16 == NULL ) {
V_107 = - V_114 ;
goto V_115;
}
F_13 ( & V_3 -> V_44 ) ;
V_3 -> V_12 = V_12 ;
V_3 -> V_106 = V_106 ;
V_3 -> V_16 = V_16 ;
V_3 -> V_28 = V_116 + 73 ;
V_3 -> V_117 = V_24 ;
V_3 -> V_72 = 0 ;
V_3 -> V_98 = 0 ;
V_3 -> V_99 = 0 ;
V_3 -> V_18 = 0 ;
V_3 -> V_32 = 0 ;
V_3 -> V_33 = 0 ;
V_3 -> V_30 = V_118 ;
V_3 -> V_10 = V_119 ;
V_3 -> V_6 = V_120 ;
V_3 -> V_11 = 0x60 ;
V_3 -> V_100 = 1 ;
V_3 -> V_8 = 1 ;
V_3 -> V_17 = 0 ;
V_3 -> V_15 = 0 ;
F_6 ( V_34 ) ;
F_57 ( & V_3 -> V_20 ) ;
V_3 -> V_20 . V_102 = F_1 ;
V_3 -> V_20 . V_46 = ( unsigned long ) V_3 ;
F_57 ( & V_3 -> V_101 ) ;
F_15 ( & V_3 -> V_44 ) ;
V_12 -> V_80 = V_3 ;
V_12 -> V_121 = 65536 ;
V_107 = F_58 ( V_34 ) ;
if ( V_107 )
goto V_115;
F_49 ( V_3 ) ;
return 0 ;
V_115:
F_59 ( V_16 ) ;
F_59 ( V_106 ) ;
V_58 ( V_34 ) ;
V_84:
return V_107 ;
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
F_14 ( V_3 -> V_34 ) ;
F_64 ( & V_3 -> V_20 ) ;
F_64 ( & V_3 -> V_101 ) ;
F_59 ( V_3 -> V_106 ) ;
F_59 ( V_3 -> V_16 ) ;
F_65 ( V_3 -> V_34 ) ;
}
static int F_66 ( struct V_78 * V_12 , struct V_122 * V_122 ,
unsigned int V_70 , unsigned long V_123 )
{
struct V_2 * V_3 = F_31 ( V_12 ) ;
struct V_41 * V_34 ;
unsigned int V_124 , V_107 ;
if ( ! V_3 )
return - V_125 ;
V_34 = V_3 -> V_34 ;
switch( V_70 ) {
case V_126 :
V_107 = F_67 ( ( void V_127 * ) V_123 , V_34 -> V_38 ,
strlen ( V_34 -> V_38 ) + 1 ) ? - V_128 : 0 ;
break;
case V_129 :
V_107 = F_68 ( 0 , ( int V_127 * ) V_123 ) ;
break;
case V_130 :
if ( F_69 ( V_124 , ( int V_127 * ) V_123 ) ) {
V_107 = - V_128 ;
break;
}
V_3 -> V_131 = V_124 ;
V_34 -> V_64 = V_54 ;
V_34 -> V_60 = V_132 +
V_61 + 3 ;
V_34 -> type = V_65 ;
V_107 = 0 ;
break;
case V_133 : {
char V_49 [ V_54 ] ;
if ( F_70 ( & V_49 ,
( void V_127 * ) V_123 , V_54 ) ) {
V_107 = - V_128 ;
break;
}
F_21 ( V_34 ) ;
memcpy ( V_34 -> V_52 , & V_49 , V_54 ) ;
F_24 ( V_34 ) ;
V_107 = 0 ;
break;
}
default:
V_107 = F_71 ( V_12 , V_122 , V_70 , V_123 ) ;
}
F_35 ( V_3 ) ;
return V_107 ;
}
static long F_72 ( struct V_78 * V_12 , struct V_122 * V_122 ,
unsigned int V_70 , unsigned long V_123 )
{
switch ( V_70 ) {
case V_126 :
case V_129 :
case V_130 :
case V_133 :
return F_66 ( V_12 , V_122 , V_70 ,
( unsigned long ) F_73 ( V_123 ) ) ;
}
return - V_134 ;
}
static int T_2 F_74 ( void )
{
int V_100 ;
F_8 ( V_135 ) ;
if ( ( V_100 = F_75 ( V_136 , & V_137 ) ) != 0 )
F_8 ( V_138 , V_100 ) ;
return V_100 ;
}
static void T_3 F_76 ( void )
{
int V_139 ;
if ( ( V_139 = F_77 ( V_136 ) ) )
F_8 ( V_140 , V_139 ) ;
}
static int F_4 ( unsigned char * V_141 , unsigned char * V_142 ,
int V_143 , unsigned char V_30 )
{
int V_27 = 0 ;
unsigned char V_144 = 0 , V_145 [ 400 ] ;
int V_146 = 0 ;
V_142 [ V_146 ++ ] = V_147 | V_148 ;
V_142 [ V_146 ++ ] = V_149 ;
V_145 [ 0 ] = V_30 ;
for ( V_27 = 1 ; V_27 < V_143 ; V_27 ++ )
V_145 [ V_27 ] = V_141 [ V_27 ] ;
for ( V_27 = 0 ; V_27 < V_143 ; V_27 ++ )
V_144 += V_145 [ V_27 ] ;
V_145 [ V_143 ] = ( unsigned char ) 0xff - V_144 ;
for ( V_27 = 0 ; V_27 <= V_143 ; V_27 ++ ) {
if ( ( V_27 % 3 ) == 0 ) {
V_142 [ V_146 ++ ] = ( V_145 [ V_27 ] & 0x3f ) ;
V_142 [ V_146 ] = ( ( V_145 [ V_27 ] >> 2 ) & 0x30 ) ;
} else if ( ( V_27 % 3 ) == 1 ) {
V_142 [ V_146 ++ ] |= ( V_145 [ V_27 ] & 0x0f ) ;
V_142 [ V_146 ] = ( ( V_145 [ V_27 ] >> 2 ) & 0x3c ) ;
} else {
V_142 [ V_146 ++ ] |= ( V_145 [ V_27 ] & 0x03 ) ;
V_142 [ V_146 ++ ] = ( V_145 [ V_27 ] >> 2 ) ;
}
}
if ( ( V_143 % 3 ) != 2 )
V_146 ++ ;
V_142 [ V_146 ++ ] = V_149 ;
return V_146 ;
}
static void F_78 ( struct V_2 * V_3 , unsigned char V_105 )
{
unsigned char * V_145 ;
if ( V_3 -> V_98 != 3 ) {
V_3 -> V_150 [ V_3 -> V_98 ++ ] = V_105 ;
return;
}
V_145 = V_3 -> V_150 ;
V_3 -> V_75 [ V_3 -> V_99 ++ ] =
V_145 [ 0 ] | ( ( V_145 [ 1 ] << 2 ) & 0xc0 ) ;
V_3 -> V_75 [ V_3 -> V_99 ++ ] =
( V_145 [ 1 ] & 0x0f ) | ( ( V_145 [ 2 ] << 2 ) & 0xf0 ) ;
V_3 -> V_75 [ V_3 -> V_99 ++ ] =
( V_145 [ 2 ] & 0x03 ) | ( V_105 << 2 ) ;
V_3 -> V_98 = 0 ;
}
static void F_79 ( struct V_2 * V_3 , unsigned char V_70 )
{
unsigned char V_1 ;
int V_4 ;
V_1 = V_70 & V_151 ;
if ( ( V_70 & V_152 ) != 0 ) {
if ( ( ( V_3 -> V_100 & V_9 ) == 0 ) &&
( ( V_70 & V_153 ) == V_153 ) ) {
if ( V_3 -> V_100 != 1 )
F_8 ( V_37 L_11 ) ;
else
V_3 -> V_100 = 0 ;
V_70 &= ~ V_153 ;
}
V_3 -> V_100 = V_70 & V_152 ;
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
if ( V_3 -> V_94 == V_93 ) {
F_47 ( & V_3 -> V_101 ) ;
V_3 -> V_101 . V_46 = ( unsigned long ) V_3 ;
V_3 -> V_101 . V_102 = F_46 ;
V_3 -> V_101 . V_103 = V_21 + V_154 ;
F_48 ( & V_3 -> V_101 ) ;
}
V_3 -> V_8 = V_70 & V_152 ;
}
static void F_80 ( struct V_2 * V_3 , unsigned char V_70 )
{
unsigned char V_144 = 0 , V_155 = 0 , V_1 ;
short V_156 ;
V_1 = V_70 & V_151 ;
switch ( V_70 & V_157 ) {
case V_149 :
if ( ( V_3 -> V_98 == 0 ) && ( V_3 -> V_99 == 0 ) ) {
if ( ( V_3 -> V_100 & V_153 ) ==
V_153 ) {
V_3 -> V_11 = 0x68 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
}
} else {
V_3 -> V_11 = 0x60 ;
V_3 -> V_12 -> V_13 -> V_14 ( V_3 -> V_12 , & V_3 -> V_11 , 1 ) ;
V_155 = V_3 -> V_98 ;
if ( V_155 != 0 )
for ( V_156 = V_155 ; V_156 <= 3 ; V_156 ++ )
F_78 ( V_3 , 0 ) ;
if ( V_155 == 2 )
V_3 -> V_99 -= 2 ;
else if ( V_155 == 3 )
V_3 -> V_99 -= 1 ;
for ( V_156 = 0 ; V_156 < V_3 -> V_99 ; V_156 ++ )
V_144 += V_3 -> V_75 [ V_156 ] ;
if ( V_144 != V_158 ) {
F_8 ( V_37 L_12 , V_144 ) ;
} else {
V_3 -> V_72 = V_3 -> V_99 - 2 ;
F_26 ( V_3 , 0 ) ;
}
V_3 -> V_99 = 0 ;
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
F_42 ( struct V_2 * V_3 , const unsigned char * V_162 , int V_27 )
{
unsigned char V_105 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_27 ; V_87 ++ ) {
V_105 = V_162 [ V_87 ] ;
if ( V_105 == V_163 ) {
F_45 ( V_3 , V_93 ) ;
F_47 ( & V_3 -> V_101 ) ;
}
if ( ( V_105 & V_147 ) != 0 )
F_79 ( V_3 , V_105 ) ;
else if ( ( V_105 & V_164 ) != 0 )
F_80 ( V_3 , V_105 ) ;
else if ( ( V_3 -> V_100 & V_153 ) == V_153 )
F_78 ( V_3 , V_105 ) ;
}
}
