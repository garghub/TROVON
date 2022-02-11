static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
int V_5 = V_2 -> V_5 ;
if( V_6 > 4 )
F_2 ( V_7 L_1 , V_8 ) ;
if( V_5 > 0x1ff )
return F_3 ( V_2 , V_5 ) ;
else if( V_5 != 0 )
return - V_9 ;
for( V_3 = 0 ; ( V_4 = V_10 [ V_3 ] ) ; V_3 ++ )
if( F_3 ( V_2 , V_4 ) == 0 )
return 0 ;
for( V_3 = 0 ; ( V_4 = V_11 [ V_3 ] ) ; V_3 ++ )
if( F_3 ( V_2 , V_4 ) == 0 )
return 0 ;
return - V_12 ;
}
struct V_1 * T_1 F_4 ( int V_13 )
{
struct V_1 * V_2 = F_5 ( sizeof( struct V_14 ) ) ;
int V_15 ;
if ( ! V_2 )
return F_6 ( - V_16 ) ;
sprintf ( V_2 -> V_17 , L_2 , V_13 ) ;
F_7 ( V_2 ) ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 )
goto V_18;
return V_2 ;
V_18:
F_8 ( V_2 ) ;
return F_6 ( V_15 ) ;
}
static int T_1 F_3 ( struct V_1 * V_2 , int V_4 )
{
struct V_14 * V_19 = F_9 ( V_2 ) ;
static unsigned V_20 ;
int V_21 ;
if ( ! F_10 ( V_4 , V_22 , V_8 ) )
return - V_23 ;
if( V_4 < 0x1000 ) {
if( V_10 [ ( F_11 ( V_4 + V_24 ) & 0x07 ) ]
!= V_4 ) {
V_21 = - V_12 ;
goto V_18;
}
}
if( F_12 ( V_4 ) != 0 ) {
V_21 = - V_12 ;
goto V_18;
}
F_13 ( V_25 , V_4 ) ;
F_14 ( 0x00 , V_4 + V_26 ) ;
F_14 ( 0x00 , V_4 + V_27 ) ;
F_15 ( V_4 + V_28 , F_16 ( 7 ) ) ;
if( ( V_6 & V_20 ++ ) == 0 )
F_2 ( V_29 L_3 , V_30 ) ;
V_2 -> V_5 = V_4 ;
V_2 -> V_31 = F_17 ( V_4 ) ;
if ( ( V_21 = F_18 ( V_2 -> V_31 , ( void * ) & V_32 , 0 , V_8 , V_2 ) ) ) {
F_2 ( V_33 L_4 ,
V_8 , V_4 , V_2 -> V_31 ) ;
goto V_18;
}
F_2 ( V_29 L_5 ,
V_2 -> V_17 , V_8 , V_4 , V_2 -> V_31 ) ;
F_13 ( V_25 , V_4 ) ;
F_14 ( 0x38 , V_4 + V_26 ) ;
F_19 ( V_2 , 1 ) ;
F_20 ( V_4 + V_34 , V_35 ) ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = V_39 ;
F_21 ( & V_19 -> V_40 ) ;
V_21 = F_22 ( V_2 ) ;
if ( V_21 )
goto V_41;
return 0 ;
V_41:
F_23 ( V_2 -> V_31 , V_2 ) ;
V_18:
F_24 ( V_4 , V_22 ) ;
return V_21 ;
}
static void F_19 ( struct V_1 * V_2 , int V_42 )
{
int V_4 = V_2 -> V_5 ;
int V_3 , V_43 = 0 ;
unsigned char V_44 = 0 ;
F_13 ( V_45 , V_4 ) ;
for( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
unsigned short V_46 = F_25 ( V_4 , V_47 + V_3 ) ;
( ( unsigned short * ) V_2 -> V_48 ) [ V_3 ] = F_26 ( V_46 ) ;
}
for( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
F_14 ( ( ( unsigned char * ) V_2 -> V_48 ) [ V_3 ] , V_4 + V_49 + V_3 ) ;
if( V_42 ) {
F_2 ( L_6 , F_11 ( V_4 + V_49 + V_3 ) ) ;
if( V_3 != 5 )
F_2 ( L_7 ) ;
}
}
F_13 ( V_50 , V_4 ) ;
for( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
F_14 ( 0x00 , V_4 + V_51 + V_3 ) ;
F_13 ( 2 , V_4 ) ;
V_44 = 0 ;
V_43 = F_25 ( V_4 , V_52 ) ;
if( ( V_43 & 0xFF00 ) == 0x0800 )
V_44 |= V_53 ;
V_44 |= V_54 ;
if( ( V_43 & 0x00FF ) == 64 )
V_44 |= V_55 ;
V_44 |= V_56 | V_57 | ( V_58 << 2 ) ;
F_14 ( V_44 , V_4 + V_28 ) ;
F_14 ( V_59 , V_4 + V_60 ) ;
#ifdef F_27
#else
V_2 -> V_61 = ( V_2 -> V_62 < V_63 ) ?
V_2 -> V_62 : V_63 ;
#endif
if( V_42 ) {
static const char * const V_64 [] = {
L_8 , L_9 , L_10 , L_11 , L_12
} ;
switch( V_2 -> V_61 )
{
case V_63 :
V_2 -> V_61 = F_25 ( V_4 , V_65 ) ;
break;
case V_66 :
V_2 -> V_61 = F_28 ( V_4 ) ;
break;
case V_67 :
case V_68 :
case V_69 :
break;
}
F_2 ( L_13 , V_64 [ V_2 -> V_61 ] ) ;
F_29 ( V_4 , V_2 -> V_61 ) ;
}
F_14 ( V_70 , V_4 + V_71 ) ;
}
static int F_28 ( int V_4 )
{
int V_3 ;
int V_72 ;
unsigned char V_73 [ 64 ] ;
F_14 ( 0xc0 | V_35 , V_4 + V_34 ) ;
F_15 ( V_4 + V_28 , V_56 ) ;
F_13 ( V_45 , V_4 ) ;
for( V_3 = 0 ; V_3 < 6 ; V_3 ++ ) {
V_73 [ V_3 ] = F_11 ( V_4 + V_49 + V_3 ) ;
V_73 [ V_3 + 6 ] = F_11 ( V_4 + V_49 + V_3 ) ;
}
V_73 [ 12 ] = 0x00 ;
V_73 [ 13 ] = 0x04 ;
memset ( V_73 + 14 , 0 , sizeof( V_73 ) - 14 ) ;
F_13 ( 2 , V_4 ) ;
for( V_3 = 0 ; V_3 < 3 ; V_3 ++ ) {
F_15 ( V_4 + V_28 , V_56 ) ;
F_20 ( V_4 + V_28 , V_56 ) ;
F_29 ( V_4 , V_3 ) ;
if( V_6 > 1 )
F_2 ( V_7 L_14 , V_3 ) ;
V_72 = F_30 ( V_4 , V_73 , 64 ) ;
if( V_72 == 0 ) {
V_72 = F_31 ( V_4 ) ;
if( V_72 != - 1 ) {
if( V_6 > 1 )
F_2 ( V_7 L_15 , V_3 ) ;
return V_3 ;
}
}
else {
if( V_6 > 1 )
F_2 ( V_7 L_16 ) ;
}
}
if( V_6 > 1 )
F_2 ( V_7 L_17 ) ;
return V_67 ;
}
static void F_29 ( int V_4 , int V_64 )
{
unsigned short V_74 = 0 ;
F_13 ( V_25 , V_4 ) ;
F_14 ( V_75 , V_4 + V_76 ) ;
V_74 |= V_77 ;
switch( V_64 ) {
case V_67 :
V_74 |= V_78 ;
break;
case V_68 :
break;
case V_69 :
V_74 |= V_78 ;
F_15 ( V_4 + V_76 , V_79 ) ;
break;
}
F_14 ( V_74 , V_4 + V_26 ) ;
if( V_6 > 1 ) {
F_2 ( V_7 L_18 , F_11 ( V_4 + V_76 ) ) ;
F_2 ( V_7 L_19 ,
F_11 ( V_4 + V_26 ) ) ;
}
}
static int F_30 ( int V_4 , unsigned char * V_80 , int V_81 )
{
unsigned long V_82 ;
F_14 ( 0xff , V_4 + V_83 ) ;
F_32 ( V_81 , V_4 + V_84 ) ;
F_33 ( V_4 + V_84 , ( unsigned short * ) V_80 , ( V_81 + 1 ) >> 1 ) ;
V_82 = V_85 ;
F_14 ( V_86 | 1 , V_4 + V_87 ) ;
while( ( F_11 ( V_4 + V_83 ) & 0x80 ) == 0 ) {
if( F_34 ( V_85 , V_82 + V_39 ) ) {
return - 1 ;
}
}
return 0 ;
}
static int F_31 ( int V_4 )
{
unsigned long V_82 ;
V_82 = V_85 ;
while( ( F_11 ( V_4 + V_83 ) & 0x20 ) == 0 ) {
if( F_34 ( V_85 , V_82 + V_39 ) ) {
if( V_6 > 1 )
F_2 ( V_7 L_20 ) ;
V_82 = V_85 ;
while( ( F_11 ( V_4 + V_88 ) & 0x80 ) == 0 ) {
if( F_34 ( V_85 , V_82 + V_39 ) ) {
if( V_6 > 1 )
F_2 ( V_7 L_21 ) ;
return - 1 ;
}
}
if( V_6 > 1 )
F_2 ( V_7 L_22 ) ;
return 0 ;
}
}
if( V_6 > 1 ) {
F_2 ( V_7 L_23 , F_11 ( V_4 + V_83 ) ) ;
F_2 ( V_7 L_24 , F_11 ( V_4 + V_88 ) ) ;
}
return 0 ;
}
static int T_1 F_17 ( int V_4 )
{
unsigned char V_89 ;
if( V_4 < 0x1000 ) {
V_89 = F_11 ( V_4 + V_24 ) ;
return V_90 [ ( ( V_89 & 0xC0 ) >> 6 ) ] ;
} else {
unsigned short V_91 = 0 ;
V_89 = F_11 ( V_4 + V_92 ) ;
while( ( V_89 & 0x01 ) == 0 ) {
V_89 = V_89 >> 1 ;
V_91 ++ ;
}
return V_93 [ V_91 ] ;
}
}
static int T_1 F_12 ( int V_4 )
{
int V_3 ;
unsigned char V_94 [ 4 ] = { 0 } ;
for( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
V_94 [ V_3 ] = F_11 ( V_4 + V_76 + V_3 ) ;
if( V_6 > 1 )
F_2 ( L_25 ,
V_94 [ V_3 ] ,
V_4 + V_76 + V_3 ) ;
}
V_94 [ 0 ] &= 0x0F ;
V_94 [ 2 ] &= 0x7F ;
#if 0
if( ! ((creg[0] == 0x06) && (creg[1] == 0x41)) ) {
if(creg[1] != 0x42)
return -1;
}
#endif
if( ! ( ( V_94 [ 2 ] == 0x36 ) && ( V_94 [ 3 ] == 0xE0 ) ) ) {
V_94 [ 2 ] &= 0x40 ;
V_94 [ 3 ] &= 0x03 ;
if( ! ( ( V_94 [ 2 ] == 0x40 ) && ( V_94 [ 3 ] == 0x00 ) ) )
return - 1 ;
}
if( F_25 ( V_4 , V_47 ) != 0 )
return - 1 ;
if( ( F_25 ( V_4 , V_95 ) & 0xFF00 ) != 0x4B00 )
return - 1 ;
return 0 ;
}
static int F_25 ( int V_4 , int V_96 )
{
int V_97 = 0 ;
F_35 ( V_4 , V_98 | V_96 ) ;
F_14 ( V_99 , V_4 + V_100 ) ;
V_97 = F_36 ( V_4 ) ;
F_14 ( V_101 | V_102 , V_4 + V_100 ) ;
return V_97 ;
}
static int F_36 ( int V_4 )
{
int V_3 ;
int V_97 = 0 ;
for( V_3 = 16 ; V_3 > 0 ; V_3 -- ) {
F_14 ( V_99 | V_102 , V_4 + V_100 ) ;
F_37 () ;
F_14 ( V_99 | V_103 , V_4 + V_100 ) ;
F_37 () ;
V_97 = ( V_97 << 1 ) |
( ( F_11 ( V_4 + V_104 ) & V_105 ) ? 1 : 0 ) ;
F_37 () ;
}
return V_97 ;
}
static void F_35 ( int V_4 , unsigned char V_106 )
{
int V_3 ;
F_14 ( V_101 | V_102 , V_4 + V_100 ) ;
F_14 ( V_107 , V_4 + V_104 ) ;
F_14 ( V_99 | V_102 , V_4 + V_100 ) ;
F_14 ( V_105 , V_4 + V_104 ) ;
F_14 ( V_99 | V_103 , V_4 + V_100 ) ;
for( V_3 = 7 ; V_3 >= 0 ; V_3 -- ) {
short V_108 = ( ( V_106 & ( 1 << V_3 ) ) ? V_105 : V_107 ) ;
F_14 ( V_108 , V_4 + V_104 ) ;
F_14 ( V_99 | V_102 , V_4 + V_100 ) ;
F_37 () ;
F_14 ( V_99 | V_103 , V_4 + V_100 ) ;
F_37 () ;
}
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_14 * V_19 = F_9 ( V_2 ) ;
int V_4 = V_2 -> V_5 ;
F_14 ( 0xc0 | V_35 , V_4 + V_34 ) ;
F_19 ( V_2 , 0 ) ;
V_19 -> V_109 = V_110 [ V_58 & 0x03 ] ;
if( V_6 > 0 )
F_2 ( V_7 L_26 ,
V_2 -> V_17 , V_19 -> V_109 ) ;
F_20 ( V_4 + V_28 , V_56 ) ;
F_13 ( 2 , V_4 ) ;
V_19 -> V_111 = V_85 ;
V_19 -> V_112 = 0 ;
V_19 -> V_113 = 0 ;
V_19 -> V_114 = 0 ;
F_32 ( V_115 , V_4 + V_116 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_14 * V_19 = F_9 ( V_2 ) ;
int V_4 = V_2 -> V_5 ;
F_41 ( V_2 ) ;
F_32 ( V_117 , V_4 + V_116 ) ;
F_42 ( V_2 ) ;
V_19 -> V_111 = 0 ;
F_15 ( V_4 + V_28 , V_56 ) ;
F_14 ( 0x00 , V_4 + V_34 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_14 * V_19 = F_9 ( V_2 ) ;
int V_4 = V_2 -> V_5 ;
F_32 ( V_117 , V_4 + V_116 ) ;
F_2 ( V_33 L_27 ,
V_2 -> V_17 ,
F_44 ( V_4 + V_83 ) , ( F_11 ( V_4 + V_83 ) & V_118 ) ?
L_28 : L_29 ) ;
V_2 -> V_119 = V_85 ;
if( V_6 > 0 ) {
F_2 ( V_7 L_30 ,
V_2 -> V_17 , F_11 ( V_4 + 0 ) ,
F_11 ( V_4 + 1 ) , F_11 ( V_4 + 2 ) ,
F_11 ( V_4 + 3 ) , F_11 ( V_4 + 4 ) ,
F_11 ( V_4 + 5 ) ,
F_11 ( V_4 + 6 ) , F_11 ( V_4 + 7 ) ) ;
F_2 ( V_7 L_31 ,
V_2 -> V_17 , F_11 ( V_4 + V_87 ) ,
F_11 ( V_4 + V_60 ) ) ;
F_2 ( V_7 L_32 , V_19 -> V_113 ) ;
F_2 ( V_7 L_33 , V_19 -> V_114 ) ;
F_2 ( V_7 L_34 , V_19 -> V_112 ) ;
}
V_2 -> V_120 . V_121 ++ ;
F_41 ( V_2 ) ;
V_2 -> V_119 = V_85 ;
F_32 ( V_115 , V_4 + V_116 ) ;
F_45 ( V_2 ) ;
}
static T_2 F_46 ( struct V_122 * V_123 , struct V_1 * V_2 )
{
struct V_14 * V_19 = F_9 ( V_2 ) ;
int V_4 = V_2 -> V_5 ;
int V_124 = 0 ;
T_3 V_125 = V_123 -> V_126 ;
unsigned char * V_127 ;
unsigned long V_128 ;
if ( V_125 < V_129 ) {
if ( F_47 ( V_123 , V_129 ) )
return V_130 ;
V_125 = V_129 ;
}
V_127 = V_123 -> V_97 ;
F_42 ( V_2 ) ;
F_32 ( V_117 , V_4 + V_116 ) ;
F_48 ( & V_19 -> V_40 , V_128 ) ;
if( ( V_125 + 2 ) > ( V_19 -> V_109 - V_19 -> V_114 ) ) {
if( V_6 > 0 )
F_2 ( V_33 L_35 , V_2 -> V_17 ) ;
}
else {
F_32 ( V_125 , V_4 + V_84 ) ;
if( V_4 < 0x1000 )
F_33 ( V_4 + V_84 , V_127 , ( V_125 + 1 ) >> 1 ) ;
else {
unsigned char V_131 = V_125 % 4 ;
F_49 ( V_4 + V_84 , V_127 , V_125 >> 2 ) ;
if( V_131 != 0 ) {
F_33 ( V_4 + V_84 , ( V_127 + ( V_125 & 0xFFFC ) ) , 1 ) ;
if( V_131 == 3 )
F_33 ( V_4 + V_84 ,
( V_127 + ( V_125 & 0xFFFC ) + 2 ) , 1 ) ;
}
}
V_19 -> V_132 ++ ;
V_19 -> V_133 = V_125 ;
V_19 -> V_113 ++ ;
V_19 -> V_114 += V_125 + 2 ;
}
V_19 -> V_134 = 0 ;
if( V_19 -> V_112 == 0 ) {
F_14 ( V_86 | V_19 -> V_113 , V_4 + V_87 ) ;
V_19 -> V_113 = 0 ;
V_19 -> V_114 = 0 ;
V_19 -> V_112 = 1 ;
F_45 ( V_2 ) ;
}
else if( V_19 -> V_114 < V_19 -> V_109 - ( V_135 + 2 ) ) {
F_45 ( V_2 ) ;
}
F_50 ( & V_19 -> V_40 , V_128 ) ;
F_32 ( V_115 , V_4 + V_116 ) ;
V_124 = 0 ;
F_51 ( V_123 ) ;
return V_130 ;
}
static void F_52 ( struct V_1 * V_2 )
{
int V_4 = V_2 -> V_5 ;
int V_136 = V_137 ;
while( ( F_11 ( V_4 + V_71 ) & V_138 ) == 0 ) {
T_3 V_124 = F_44 ( V_4 + V_84 ) ;
T_3 V_139 = F_44 ( V_4 + V_84 ) ;
if( V_6 > 4 )
F_2 ( V_7 L_36 ,
V_2 -> V_17 ,
F_11 ( V_4 + V_71 ) , V_124 ) ;
if( ! ( V_124 & V_140 ) ) {
V_2 -> V_120 . V_141 ++ ;
if( ( V_139 < V_129 ) || ( V_139 > V_135 ) ) {
V_2 -> V_120 . V_142 ++ ;
F_41 ( V_2 ) ;
return;
}
else {
F_53 ( V_2 ) ;
V_2 -> V_120 . V_143 ++ ;
}
}
else {
struct V_122 * V_123 ;
V_123 = F_54 ( V_139 + 3 ) ;
if( V_123 == NULL ) {
F_2 ( V_33 L_37 ,
V_2 -> V_17 , V_139 ) ;
F_53 ( V_2 ) ;
V_2 -> V_120 . V_143 ++ ;
break;
}
F_55 ( V_123 , 2 ) ;
if( V_4 < 0x1000 )
F_56 ( V_4 + V_84 , F_57 ( V_123 , V_139 ) ,
( V_139 + 1 ) >> 1 ) ;
else {
unsigned char * V_127 = F_57 ( V_123 , V_139 ) ;
unsigned char V_131 = V_139 % 4 ;
F_58 ( V_4 + V_84 , V_127 , V_139 >> 2 ) ;
if( V_131 != 0 ) {
unsigned short V_144 [ 2 ] ;
V_144 [ 0 ] = F_44 ( V_4 + V_84 ) ;
if( V_131 == 3 )
V_144 [ 1 ] = F_44 ( V_4 + V_84 ) ;
memcpy ( V_127 + ( V_139 & 0xfffc ) , ( char * ) V_144 , V_131 ) ;
}
}
V_123 -> V_145 = F_59 ( V_123 , V_2 ) ;
if( V_6 > 5 ) {
int V_3 ;
F_2 ( V_7 L_38 ,
V_2 -> V_17 , V_139 ) ;
for( V_3 = 0 ; V_3 < 14 ; V_3 ++ )
F_2 ( V_7 L_39 , V_123 -> V_97 [ V_3 ] ) ;
F_2 ( V_7 L_40 ) ;
}
F_60 ( V_123 ) ;
V_2 -> V_120 . V_146 ++ ;
V_2 -> V_120 . V_147 += V_139 ;
}
if( -- V_136 <= 0 )
break;
}
}
static T_4 V_32 ( int V_31 , void * V_148 )
{
struct V_1 * V_2 = V_148 ;
struct V_14 * V_19 ;
int V_4 = 0 , V_124 ;
int V_149 = 0 ;
V_4 = V_2 -> V_5 ;
V_19 = F_9 ( V_2 ) ;
F_32 ( V_117 , V_4 + V_116 ) ;
F_61 ( & V_19 -> V_40 ) ;
V_124 = F_44 ( V_4 + V_83 ) ;
F_32 ( V_124 , V_4 + V_83 ) ;
if ( V_124 )
V_149 = 1 ;
if( V_6 > 3 )
F_2 ( V_7 L_41 , V_2 -> V_17 , V_124 ) ;
if( V_124 & 0x7f00 ) {
V_2 -> V_120 . V_141 ++ ;
if( V_124 & ( V_150 << 8 ) )
F_2 ( V_33 L_42 , V_2 -> V_17 ) ;
if( V_124 & ( V_151 << 8 ) ) V_2 -> V_120 . V_142 ++ ;
if( V_124 & ( V_152 << 8 ) ) V_2 -> V_120 . V_153 ++ ;
if( V_124 & ( V_154 << 8 ) ) V_2 -> V_120 . V_155 ++ ;
if( V_124 & ( V_156 << 8 ) ) V_2 -> V_120 . V_157 ++ ;
}
if( V_124 & 0x001a ) {
V_2 -> V_120 . V_121 ++ ;
if( V_124 & V_158 ) V_2 -> V_120 . V_159 ++ ;
if( V_124 & V_160 ) V_2 -> V_120 . V_161 ++ ;
#if 0
if(status & COLLISION) {
dev->stats.collisions +=
((inb(ioaddr+TRANSMIT_MODE_REG) & 0xF0) >> 4);
}
#endif
if( V_124 & V_162 ) {
if( V_19 -> V_163 < V_164 ) {
V_19 -> V_163 ++ ;
V_2 -> V_120 . V_165 ++ ;
F_14 ( 0x02 , V_4 + V_60 ) ;
}
else {
F_2 ( V_33 L_43 , V_2 -> V_17 ) ;
}
}
}
if( V_124 & 0x00ff ) {
if( V_124 & V_118 ) {
V_2 -> V_120 . V_166 = V_19 -> V_132 ;
V_2 -> V_120 . V_167 += V_19 -> V_133 ;
V_19 -> V_163 = 0 ;
if( V_19 -> V_113 ) {
F_14 ( V_86 | V_19 -> V_113 , V_4 + V_87 ) ;
V_19 -> V_113 = 0 ;
V_19 -> V_114 = 0 ;
V_19 -> V_112 = 1 ;
}
else {
V_19 -> V_112 = 0 ;
}
F_45 ( V_2 ) ;
}
}
if( ( V_124 & 0x8000 ) ||
( ( F_11 ( V_4 + V_71 ) & V_138 ) == 0 ) ) {
F_52 ( V_2 ) ;
}
F_32 ( V_115 , V_4 + V_116 ) ;
if( V_19 -> V_114 < V_19 -> V_109 - ( V_135 + 2 ) ) {
F_45 ( V_2 ) ;
}
F_62 ( & V_19 -> V_40 ) ;
return F_63 ( V_149 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
int V_4 = V_2 -> V_5 ;
F_44 ( V_4 + V_84 ) ;
F_44 ( V_4 + V_84 ) ;
F_44 ( V_4 + V_84 ) ;
F_14 ( V_168 , V_4 + V_169 ) ;
while( F_11 ( V_4 + V_169 ) != 0 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_14 * V_19 = F_9 ( V_2 ) ;
int V_4 = V_2 -> V_5 ;
if( V_6 > 1 )
F_2 ( V_7 L_44 , V_2 -> V_17 ) ;
F_15 ( V_4 + V_28 , V_56 ) ;
F_32 ( 0xffff , V_4 + V_83 ) ;
F_13 ( 2 , V_4 ) ;
V_19 -> V_112 = 0 ;
V_19 -> V_134 = 0 ;
V_19 -> V_113 = 0 ;
V_19 -> V_114 = 0 ;
F_20 ( V_4 + V_28 , V_56 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
int V_4 = V_2 -> V_5 ;
if ( ! F_65 ( V_2 ) || V_2 -> V_128 & ( V_170 | V_171 ) )
{
F_14 ( 3 , V_4 + V_71 ) ;
} else {
F_14 ( 2 , V_4 + V_71 ) ;
}
}
static void F_13 ( unsigned char V_172 , int V_4 )
{
unsigned char V_97 ;
V_97 = F_11 ( V_4 + V_34 ) ;
F_14 ( ( ( V_97 & 0xF3 ) | ( ( V_172 & 0x03 ) << 2 ) ) , V_4 + V_34 ) ;
}
static T_3 F_66 ( const char * V_173 )
{
if( ! V_173 )
return V_63 ;
if ( ! strncmp ( V_173 , L_45 , 3 ) )
return V_67 ;
else if ( ! strncmp ( V_173 , L_46 , 2 ) )
return V_68 ;
else if ( ! strncmp ( V_173 , L_47 , 3 ) )
return V_69 ;
else if ( ! strncmp ( V_173 , L_48 , 4 ) )
return V_66 ;
else
return V_63 ;
}
int T_1 F_67 ( void )
{
int V_174 , V_175 = 0 ;
struct V_1 * V_2 ;
for ( V_174 = 0 ; V_174 < V_176 ; V_174 ++ ) {
V_2 = F_5 ( sizeof( struct V_14 ) ) ;
if ( ! V_2 )
break;
V_2 -> V_5 = V_177 [ V_174 ] ;
if( V_178 != - 1 )
V_6 = V_178 ;
if( V_6 > 1 )
F_2 ( V_179 L_49 , V_174 , V_180 [ V_174 ] ? V_180 [ V_174 ] : L_50 ) ;
V_2 -> V_61 = F_66 ( V_180 [ V_174 ] ) ;
if( V_177 [ V_174 ] == 0 ) {
if ( V_174 != 0 ) {
F_8 ( V_2 ) ;
break;
}
F_2 ( V_179 L_51 ) ;
}
if ( F_1 ( V_2 ) == 0 ) {
V_181 [ V_175 ++ ] = V_2 ;
continue;
}
F_2 ( V_33 L_52 ,
V_177 [ V_174 ] ) ;
F_8 ( V_2 ) ;
break;
}
if ( V_175 )
return 0 ;
return - V_9 ;
}
void T_5 F_68 ( void )
{
int V_174 ;
for( V_174 = 0 ; V_174 < V_176 ; V_174 ++ ) {
struct V_1 * V_2 = V_181 [ V_174 ] ;
if ( F_9 ( V_2 ) ) {
F_69 ( V_2 ) ;
F_23 ( V_2 -> V_31 , V_2 ) ;
F_24 ( V_2 -> V_5 , V_22 ) ;
F_8 ( V_2 ) ;
}
}
}
