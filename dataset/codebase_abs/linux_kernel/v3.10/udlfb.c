static char * F_1 ( char * V_1 , T_1 V_2 , T_1 V_3 )
{
* V_1 ++ = 0xAF ;
* V_1 ++ = 0x20 ;
* V_1 ++ = V_2 ;
* V_1 ++ = V_3 ;
return V_1 ;
}
static char * F_2 ( char * V_1 )
{
return F_1 ( V_1 , 0xFF , 0x00 ) ;
}
static char * F_3 ( char * V_1 )
{
return F_1 ( V_1 , 0xFF , 0xFF ) ;
}
static char * F_4 ( char * V_1 , int V_4 )
{
T_1 V_2 ;
switch ( V_4 ) {
case V_5 :
V_2 = 0x07 ;
break;
case V_6 :
V_2 = 0x05 ;
break;
case V_7 :
V_2 = 0x03 ;
break;
case V_8 :
V_2 = 0x01 ;
break;
default:
V_2 = 0x00 ;
}
V_1 = F_1 ( V_1 , 0x1F , V_2 ) ;
return V_1 ;
}
static char * F_5 ( char * V_1 , T_1 V_9 )
{
return F_1 ( V_1 , 0x00 , V_9 ) ;
}
static char * F_6 ( char * V_10 , T_2 V_11 )
{
V_10 = F_1 ( V_10 , 0x20 , V_11 >> 16 ) ;
V_10 = F_1 ( V_10 , 0x21 , V_11 >> 8 ) ;
return F_1 ( V_10 , 0x22 , V_11 ) ;
}
static char * F_7 ( char * V_10 , T_2 V_11 )
{
V_10 = F_1 ( V_10 , 0x26 , V_11 >> 16 ) ;
V_10 = F_1 ( V_10 , 0x27 , V_11 >> 8 ) ;
return F_1 ( V_10 , 0x28 , V_11 ) ;
}
static char * F_8 ( char * V_10 , T_1 V_2 , T_3 V_12 )
{
V_10 = F_1 ( V_10 , V_2 , V_12 >> 8 ) ;
return F_1 ( V_10 , V_2 + 1 , V_12 ) ;
}
static char * F_9 ( char * V_10 , T_1 V_2 , T_3 V_12 )
{
V_10 = F_1 ( V_10 , V_2 , V_12 ) ;
return F_1 ( V_10 , V_2 + 1 , V_12 >> 8 ) ;
}
static T_3 F_10 ( T_3 V_13 )
{
T_2 V_14 = 0xFFFF ;
while ( V_13 -- ) {
V_14 = ( ( V_14 << 1 ) |
( ( ( V_14 >> 15 ) ^ ( V_14 >> 4 ) ^ ( V_14 >> 2 ) ^ ( V_14 >> 1 ) ) & 1 ) )
& 0xFFFF ;
}
return ( T_3 ) V_14 ;
}
static char * F_11 ( char * V_10 , T_1 V_2 , T_3 V_12 )
{
return F_8 ( V_10 , V_2 , F_10 ( V_12 ) ) ;
}
static char * F_12 ( char * V_10 , struct V_15 * V_16 )
{
T_3 V_17 , V_18 ;
T_3 V_19 , V_20 ;
T_3 V_21 ;
V_17 = V_16 -> V_22 + V_16 -> V_23 ;
V_10 = F_11 ( V_10 , 0x01 , V_17 ) ;
V_19 = V_17 + V_16 -> V_24 ;
V_10 = F_11 ( V_10 , 0x03 , V_19 ) ;
V_18 = V_16 -> V_25 + V_16 -> V_26 ;
V_10 = F_11 ( V_10 , 0x05 , V_18 ) ;
V_20 = V_18 + V_16 -> V_27 ;
V_10 = F_11 ( V_10 , 0x07 , V_20 ) ;
V_10 = F_11 ( V_10 , 0x09 ,
V_19 + V_16 -> V_28 - 1 ) ;
V_10 = F_11 ( V_10 , 0x0B , 1 ) ;
V_10 = F_11 ( V_10 , 0x0D , V_16 -> V_23 + 1 ) ;
V_10 = F_8 ( V_10 , 0x0F , V_16 -> V_24 ) ;
V_21 = V_16 -> V_27 + V_16 -> V_25 + V_16 -> V_29 +
V_16 -> V_26 ;
V_10 = F_11 ( V_10 , 0x11 , V_21 ) ;
V_10 = F_11 ( V_10 , 0x13 , 0 ) ;
V_10 = F_11 ( V_10 , 0x15 , V_16 -> V_26 ) ;
V_10 = F_8 ( V_10 , 0x17 , V_16 -> V_27 ) ;
V_10 = F_9 ( V_10 , 0x1B ,
200 * 1000 * 1000 / V_16 -> V_30 ) ;
return V_10 ;
}
static int F_13 ( struct V_31 * V_32 ,
struct V_15 * V_16 )
{
char * V_1 ;
char * V_10 ;
int V_33 = 0 ;
int V_34 ;
struct V_35 * V_35 ;
if ( ! F_14 ( & V_32 -> V_36 ) )
return - V_37 ;
V_35 = F_15 ( V_32 ) ;
if ( ! V_35 )
return - V_38 ;
V_1 = ( char * ) V_35 -> V_39 ;
V_10 = F_2 ( V_1 ) ;
V_10 = F_5 ( V_10 , 0x00 ) ;
V_10 = F_6 ( V_10 , 0 ) ;
V_10 = F_7 ( V_10 , V_32 -> V_40 -> V_41 . V_42 ) ;
V_10 = F_12 ( V_10 , V_16 ) ;
V_10 = F_4 ( V_10 , V_43 ) ;
V_10 = F_3 ( V_10 ) ;
V_34 = V_10 - V_1 ;
V_33 = F_16 ( V_32 , V_35 , V_34 ) ;
V_32 -> V_44 = V_43 ;
return V_33 ;
}
static int F_17 ( struct V_45 * V_40 , struct V_46 * V_47 )
{
unsigned long V_48 = V_47 -> V_49 ;
unsigned long V_50 = V_47 -> V_51 - V_47 -> V_49 ;
unsigned long V_52 = V_47 -> V_53 << V_54 ;
unsigned long V_55 , V_56 ;
if ( V_47 -> V_53 > ( ~ 0UL >> V_54 ) )
return - V_57 ;
if ( V_50 > V_40 -> V_41 . V_42 )
return - V_57 ;
if ( V_52 > V_40 -> V_41 . V_42 - V_50 )
return - V_57 ;
V_56 = ( unsigned long ) V_40 -> V_41 . V_58 + V_52 ;
F_18 ( L_1 ,
V_56 , V_50 ) ;
while ( V_50 > 0 ) {
V_55 = F_19 ( ( void * ) V_56 ) ;
if ( F_20 ( V_47 , V_48 , V_55 , V_59 , V_60 ) )
return - V_61 ;
V_48 += V_59 ;
V_56 += V_59 ;
if ( V_50 > V_59 )
V_50 -= V_59 ;
else
V_50 = 0 ;
}
return 0 ;
}
static int F_21 ( const T_1 * V_62 , const T_1 * * V_63 , int * V_64 )
{
int V_65 , V_66 ;
const unsigned long * V_67 = ( const unsigned long * ) V_62 ;
const unsigned long * V_68 = ( const unsigned long * ) * V_63 ;
const int V_69 = * V_64 / sizeof( unsigned long ) ;
int V_70 = V_69 ;
int V_48 = V_69 ;
int V_71 = V_69 ;
F_22 ( ( void * ) V_68 ) ;
F_22 ( ( void * ) V_67 ) ;
for ( V_65 = 0 ; V_65 < V_69 ; V_65 ++ ) {
if ( V_67 [ V_65 ] != V_68 [ V_65 ] ) {
V_48 = V_65 ;
break;
}
}
for ( V_66 = V_69 - 1 ; V_66 > V_65 ; V_66 -- ) {
if ( V_67 [ V_66 ] != V_68 [ V_66 ] ) {
V_71 = V_66 + 1 ;
break;
}
}
V_70 = V_48 + ( V_69 - V_71 ) ;
* V_63 = ( T_1 * ) & V_68 [ V_48 ] ;
* V_64 = ( V_71 - V_48 ) * sizeof( unsigned long ) ;
return V_70 * sizeof( unsigned long ) ;
}
static void F_23 (
const T_4 * * V_72 ,
const T_4 * const V_73 ,
T_5 * V_74 ,
T_6 * * V_75 ,
const T_6 * const V_76 )
{
const T_4 * V_77 = * V_72 ;
T_5 V_78 = * V_74 ;
T_6 * V_79 = * V_75 ;
const int V_80 = 2 ;
while ( ( V_73 > V_77 ) &&
( V_76 - V_81 > V_79 ) ) {
T_6 * V_82 = 0 ;
T_6 * V_83 = 0 ;
const T_4 * V_84 = 0 ;
const T_4 * V_85 , * V_86 = 0 ;
F_24 ( ( void * ) V_79 ) ;
* V_79 ++ = 0xAF ;
* V_79 ++ = 0x6B ;
* V_79 ++ = ( T_6 ) ( ( V_78 >> 16 ) & 0xFF ) ;
* V_79 ++ = ( T_6 ) ( ( V_78 >> 8 ) & 0xFF ) ;
* V_79 ++ = ( T_6 ) ( ( V_78 ) & 0xFF ) ;
V_83 = V_79 ++ ;
V_85 = V_77 ;
V_82 = V_79 ++ ;
V_84 = V_77 ;
V_86 = V_77 + F_25 ( V_87 + 1 ,
F_25 ( ( int ) ( V_73 - V_77 ) ,
( int ) ( V_76 - V_79 ) / V_80 ) ) ;
F_26 ( ( void * ) V_77 , ( V_86 - V_77 ) * V_80 ) ;
while ( V_77 < V_86 ) {
const T_4 * const V_88 = V_77 ;
* ( T_4 * ) V_79 = F_27 ( V_77 ) ;
V_79 += 2 ;
V_77 ++ ;
if ( F_28 ( ( V_77 < V_86 ) &&
( * V_77 == * V_88 ) ) ) {
* V_82 = ( ( V_88 -
V_84 ) + 1 ) & 0xFF ;
while ( ( V_77 < V_86 )
&& ( * V_77 == * V_88 ) ) {
V_77 ++ ;
}
* V_79 ++ = ( ( V_77 - V_88 ) - 1 ) & 0xFF ;
V_84 = V_77 ;
V_82 = V_79 ++ ;
}
}
if ( V_77 > V_84 ) {
* V_82 = ( V_77 - V_84 ) & 0xFF ;
}
* V_83 = ( V_77 - V_85 ) & 0xFF ;
V_78 += ( V_77 - V_85 ) * V_80 ;
}
if ( V_76 <= V_81 + V_79 ) {
if ( V_76 > V_79 )
memset ( V_79 , 0xAF , V_76 - V_79 ) ;
V_79 = ( T_6 * ) V_76 ;
}
* V_75 = V_79 ;
* V_72 = V_77 ;
* V_74 = V_78 ;
return;
}
static int F_29 ( struct V_31 * V_32 , struct V_35 * * V_89 ,
const char * V_68 , char * * V_90 ,
T_2 V_91 , T_2 V_92 ,
int * V_93 , int * V_94 )
{
const T_1 * V_95 , * V_96 , * V_97 ;
T_2 V_78 = V_32 -> V_98 + V_91 ;
struct V_35 * V_35 = * V_89 ;
T_1 * V_79 = * V_90 ;
T_1 * V_99 = ( T_1 * ) V_35 -> V_39 + V_35 -> V_100 ;
V_95 = ( T_1 * ) ( V_68 + V_91 ) ;
V_97 = V_95 ;
V_96 = V_97 + V_92 ;
if ( V_32 -> V_101 ) {
int V_52 ;
const T_1 * V_102 = ( T_1 * ) ( V_32 -> V_101
+ V_91 ) ;
* V_93 += F_21 ( V_102 , & V_97 ,
& V_92 ) ;
V_52 = V_97 - V_95 ;
V_96 = V_97 + V_92 ;
V_78 += V_52 ;
V_102 += V_52 ;
V_95 += V_52 ;
memcpy ( ( char * ) V_102 , ( char * ) V_95 ,
V_92 ) ;
}
while ( V_97 < V_96 ) {
F_23 ( ( const T_4 * * ) & V_97 ,
( const T_4 * ) V_96 , & V_78 ,
( T_1 * * ) & V_79 , ( T_1 * ) V_99 ) ;
if ( V_79 >= V_99 ) {
int V_103 = V_79 - ( T_1 * ) V_35 -> V_39 ;
if ( F_16 ( V_32 , V_35 , V_103 ) )
return 1 ;
* V_94 += V_103 ;
V_35 = F_15 ( V_32 ) ;
if ( ! V_35 )
return 1 ;
* V_89 = V_35 ;
V_79 = V_35 -> V_39 ;
V_99 = & V_79 [ V_35 -> V_100 ] ;
}
}
* V_90 = V_79 ;
return 0 ;
}
int F_30 ( struct V_31 * V_32 , int V_104 , int V_105 ,
int V_69 , int V_106 , char * V_107 )
{
int V_108 , V_109 ;
char * V_79 ;
T_7 V_110 , V_111 ;
int V_112 = 0 ;
int V_113 = 0 ;
struct V_35 * V_35 ;
int V_114 ;
V_110 = F_31 () ;
V_114 = F_32 ( V_104 , sizeof( unsigned long ) ) ;
V_69 = F_33 ( V_69 + ( V_104 - V_114 ) , sizeof( unsigned long ) ) ;
V_104 = V_114 ;
if ( ( V_69 <= 0 ) ||
( V_104 + V_69 > V_32 -> V_40 -> V_16 . V_24 ) ||
( V_105 + V_106 > V_32 -> V_40 -> V_16 . V_27 ) )
return - V_57 ;
if ( ! F_14 ( & V_32 -> V_36 ) )
return 0 ;
V_35 = F_15 ( V_32 ) ;
if ( ! V_35 )
return 0 ;
V_79 = V_35 -> V_39 ;
for ( V_108 = V_105 ; V_108 < V_105 + V_106 ; V_108 ++ ) {
const int V_115 = V_32 -> V_40 -> V_41 . V_116 * V_108 ;
const int V_91 = V_115 + ( V_104 * V_117 ) ;
if ( F_29 ( V_32 , & V_35 ,
( char * ) V_32 -> V_40 -> V_41 . V_58 ,
& V_79 , V_91 , V_69 * V_117 ,
& V_113 , & V_112 ) )
goto error;
}
if ( V_79 > ( char * ) V_35 -> V_39 ) {
int V_103 = V_79 - ( char * ) V_35 -> V_39 ;
V_109 = F_16 ( V_32 , V_35 , V_103 ) ;
V_112 += V_103 ;
} else
F_34 ( V_35 ) ;
error:
F_35 ( V_112 , & V_32 -> V_112 ) ;
F_35 ( V_113 , & V_32 -> V_113 ) ;
F_35 ( V_69 * V_106 * 2 , & V_32 -> V_118 ) ;
V_111 = F_31 () ;
F_35 ( ( ( unsigned int ) ( ( V_111 - V_110 )
>> 10 ) ) ,
& V_32 -> V_119 ) ;
return 0 ;
}
static T_8 F_36 ( struct V_45 * V_40 , const char T_9 * V_1 ,
T_10 V_120 , T_11 * V_121 )
{
T_8 V_122 ;
struct V_31 * V_32 = V_40 -> V_123 ;
T_2 V_52 = ( T_2 ) * V_121 ;
V_122 = F_37 ( V_40 , V_1 , V_120 , V_121 ) ;
if ( V_122 > 0 ) {
int V_48 = F_38 ( ( int ) ( V_52 / V_40 -> V_41 . V_116 ) , 0 ) ;
int V_124 = F_25 ( ( T_2 ) ( ( V_122 / V_40 -> V_41 . V_116 ) + 1 ) ,
( T_2 ) V_40 -> V_16 . V_27 ) ;
F_30 ( V_32 , 0 , V_48 , V_40 -> V_16 . V_24 ,
V_124 , V_40 -> V_125 ) ;
}
return V_122 ;
}
static void F_39 ( struct V_45 * V_40 ,
const struct V_126 * V_127 )
{
struct V_31 * V_32 = V_40 -> V_123 ;
F_40 ( V_40 , V_127 ) ;
F_30 ( V_32 , V_127 -> V_128 , V_127 -> V_129 ,
V_127 -> V_69 , V_127 -> V_106 , V_40 -> V_125 ) ;
}
static void F_41 ( struct V_45 * V_40 ,
const struct V_130 * V_131 )
{
struct V_31 * V_32 = V_40 -> V_123 ;
F_42 ( V_40 , V_131 ) ;
F_30 ( V_32 , V_131 -> V_128 , V_131 -> V_129 ,
V_131 -> V_69 , V_131 -> V_106 , V_40 -> V_125 ) ;
}
static void F_43 ( struct V_45 * V_40 ,
const struct V_132 * V_133 )
{
struct V_31 * V_32 = V_40 -> V_123 ;
F_44 ( V_40 , V_133 ) ;
F_30 ( V_32 , V_133 -> V_128 , V_133 -> V_129 , V_133 -> V_69 ,
V_133 -> V_106 , V_40 -> V_125 ) ;
}
static void F_45 ( struct V_45 * V_40 ,
struct V_134 * V_135 )
{
struct V_55 * V_136 ;
struct V_137 * V_138 = V_40 -> V_138 ;
struct V_31 * V_32 = V_40 -> V_123 ;
struct V_35 * V_35 ;
char * V_79 ;
T_7 V_110 , V_111 ;
int V_112 = 0 ;
int V_113 = 0 ;
int V_118 = 0 ;
if ( ! V_139 )
return;
if ( ! F_14 ( & V_32 -> V_36 ) )
return;
V_110 = F_31 () ;
V_35 = F_15 ( V_32 ) ;
if ( ! V_35 )
return;
V_79 = V_35 -> V_39 ;
F_46 (cur, &fbdefio->pagelist, lru) {
if ( F_29 ( V_32 , & V_35 , ( char * ) V_40 -> V_41 . V_58 ,
& V_79 , V_136 -> V_140 << V_54 ,
V_59 , & V_113 , & V_112 ) )
goto error;
V_118 += V_59 ;
}
if ( V_79 > ( char * ) V_35 -> V_39 ) {
int V_103 = V_79 - ( char * ) V_35 -> V_39 ;
F_16 ( V_32 , V_35 , V_103 ) ;
V_112 += V_103 ;
} else
F_34 ( V_35 ) ;
error:
F_35 ( V_112 , & V_32 -> V_112 ) ;
F_35 ( V_113 , & V_32 -> V_113 ) ;
F_35 ( V_118 , & V_32 -> V_118 ) ;
V_111 = F_31 () ;
F_35 ( ( ( unsigned int ) ( ( V_111 - V_110 )
>> 10 ) ) ,
& V_32 -> V_119 ) ;
}
static int F_47 ( struct V_31 * V_32 , char * V_141 , int V_103 )
{
int V_108 ;
int V_109 ;
char * V_142 ;
V_142 = F_48 ( 2 , V_143 ) ;
if ( ! V_142 )
return 0 ;
for ( V_108 = 0 ; V_108 < V_103 ; V_108 ++ ) {
V_109 = F_49 ( V_32 -> V_144 ,
F_50 ( V_32 -> V_144 , 0 ) , ( 0x02 ) ,
( 0x80 | ( 0x02 << 5 ) ) , V_108 << 8 , 0xA1 , V_142 , 2 ,
V_145 ) ;
if ( V_109 < 1 ) {
F_51 ( L_2 , V_108 , V_109 ) ;
V_108 -- ;
break;
}
V_141 [ V_108 ] = V_142 [ 1 ] ;
}
F_52 ( V_142 ) ;
return V_108 ;
}
static int F_53 ( struct V_45 * V_40 , unsigned int V_79 ,
unsigned long V_146 )
{
struct V_31 * V_32 = V_40 -> V_123 ;
if ( ! F_14 ( & V_32 -> V_36 ) )
return 0 ;
if ( V_79 == V_147 ) {
void T_9 * V_141 = ( void T_9 * ) V_146 ;
if ( F_54 ( V_141 , V_32 -> V_141 , V_32 -> V_148 ) )
return - V_149 ;
return 0 ;
}
if ( V_79 == V_150 ) {
struct V_151 V_127 ;
if ( F_55 ( & V_127 , ( void T_9 * ) V_146 ,
sizeof( struct V_151 ) ) )
return - V_149 ;
if ( V_40 -> V_138 )
V_40 -> V_138 -> V_152 = V_153 ;
if ( V_127 . V_104 < 0 )
V_127 . V_104 = 0 ;
if ( V_127 . V_104 > V_40 -> V_16 . V_24 )
V_127 . V_104 = V_40 -> V_16 . V_24 ;
if ( V_127 . V_105 < 0 )
V_127 . V_105 = 0 ;
if ( V_127 . V_105 > V_40 -> V_16 . V_27 )
V_127 . V_105 = V_40 -> V_16 . V_27 ;
F_30 ( V_32 , V_127 . V_104 , V_127 . V_105 , V_127 . V_154 , V_127 . V_155 ,
V_40 -> V_125 ) ;
}
return 0 ;
}
static int
F_56 ( unsigned V_156 , unsigned V_157 , unsigned V_158 ,
unsigned V_159 , unsigned V_160 , struct V_45 * V_40 )
{
int V_161 = 0 ;
if ( V_156 >= V_40 -> V_162 . V_103 )
return 1 ;
if ( V_156 < 16 ) {
if ( V_40 -> V_16 . V_157 . V_52 == 10 ) {
( ( T_2 * ) ( V_40 -> V_163 ) ) [ V_156 ] =
( ( V_157 & 0xf800 ) >> 1 ) |
( ( V_158 & 0xf800 ) >> 6 ) | ( ( V_159 & 0xf800 ) >> 11 ) ;
} else {
( ( T_2 * ) ( V_40 -> V_163 ) ) [ V_156 ] =
( ( V_157 & 0xf800 ) ) |
( ( V_158 & 0xfc00 ) >> 5 ) | ( ( V_159 & 0xf800 ) >> 11 ) ;
}
}
return V_161 ;
}
static int F_57 ( struct V_45 * V_40 , int V_164 )
{
struct V_31 * V_32 = V_40 -> V_123 ;
if ( ( V_164 == 0 ) && ( ! V_165 ) )
return - V_166 ;
if ( V_32 -> V_167 )
return - V_168 ;
V_32 -> V_169 ++ ;
F_58 ( & V_32 -> V_170 ) ;
if ( V_139 && ( V_40 -> V_138 == NULL ) ) {
struct V_137 * V_138 ;
V_138 = F_59 ( sizeof( struct V_137 ) , V_143 ) ;
if ( V_138 ) {
V_138 -> V_152 = V_171 ;
V_138 -> V_172 = F_45 ;
}
V_40 -> V_138 = V_138 ;
F_60 ( V_40 ) ;
}
F_18 ( L_3 ,
V_40 -> V_173 , V_164 , V_40 , V_32 -> V_169 ) ;
return 0 ;
}
static void F_61 ( struct V_170 * V_170 )
{
struct V_31 * V_32 = F_62 ( V_170 , struct V_31 , V_170 ) ;
if ( V_32 -> V_101 )
F_63 ( V_32 -> V_101 ) ;
F_52 ( V_32 -> V_141 ) ;
F_64 ( L_4 , V_32 ) ;
F_52 ( V_32 ) ;
}
static void F_65 ( struct V_174 * V_175 )
{
struct V_176 * V_177 = F_62 ( V_175 , struct V_176 ,
V_178 . V_175 ) ;
F_66 ( & V_177 -> V_32 -> V_179 . V_180 ) ;
}
static void F_67 ( struct V_31 * V_32 )
{
struct V_45 * V_40 = V_32 -> V_40 ;
if ( V_40 ) {
int V_173 = V_40 -> V_173 ;
F_68 ( V_40 ) ;
if ( V_40 -> V_162 . V_103 != 0 )
F_69 ( & V_40 -> V_162 ) ;
if ( V_40 -> V_181 . V_182 )
F_70 ( V_40 -> V_181 . V_182 ) ;
if ( V_40 -> V_125 )
F_63 ( V_40 -> V_125 ) ;
F_71 ( & V_40 -> V_183 ) ;
V_32 -> V_40 = NULL ;
F_72 ( V_40 ) ;
F_64 ( L_5 , V_173 ) ;
}
F_73 ( & V_32 -> V_170 , F_61 ) ;
}
static void F_74 ( struct V_174 * V_175 )
{
struct V_31 * V_32 = F_62 ( V_175 , struct V_31 ,
V_184 . V_175 ) ;
F_67 ( V_32 ) ;
}
static int F_75 ( struct V_45 * V_40 , int V_164 )
{
struct V_31 * V_32 = V_40 -> V_123 ;
V_32 -> V_169 -- ;
if ( V_32 -> V_167 && ( V_32 -> V_169 == 0 ) )
F_76 ( & V_32 -> V_184 , V_145 ) ;
if ( ( V_32 -> V_169 == 0 ) && ( V_40 -> V_138 ) ) {
F_77 ( V_40 ) ;
F_52 ( V_40 -> V_138 ) ;
V_40 -> V_138 = NULL ;
V_40 -> V_185 -> V_186 = F_17 ;
}
F_64 ( L_6 ,
V_40 -> V_173 , V_164 , V_32 -> V_169 ) ;
F_73 ( & V_32 -> V_170 , F_61 ) ;
return 0 ;
}
static int F_78 ( struct V_187 * V_188 ,
struct V_45 * V_40 )
{
struct V_31 * V_32 = V_40 -> V_123 ;
if ( V_188 -> V_24 * V_188 -> V_27 > V_32 -> V_189 ) {
F_64 ( L_7 ,
V_188 -> V_24 , V_188 -> V_27 ) ;
return 0 ;
}
F_79 ( L_8 , V_188 -> V_24 , V_188 -> V_27 ,
V_188 -> V_190 ) ;
return 1 ;
}
static void F_80 ( struct V_15 * V_16 )
{
const struct V_191 V_157 = { 11 , 5 , 0 } ;
const struct V_191 V_158 = { 5 , 6 , 0 } ;
const struct V_191 V_159 = { 0 , 5 , 0 } ;
V_16 -> V_192 = 16 ;
V_16 -> V_157 = V_157 ;
V_16 -> V_158 = V_158 ;
V_16 -> V_159 = V_159 ;
}
static int F_81 ( struct V_15 * V_16 ,
struct V_45 * V_40 )
{
struct V_187 V_188 ;
if ( ( V_16 -> V_24 * V_16 -> V_27 * 2 ) > V_40 -> V_41 . V_42 )
return - V_57 ;
F_80 ( V_16 ) ;
F_82 ( & V_188 , V_16 ) ;
if ( ! F_78 ( & V_188 , V_40 ) )
return - V_57 ;
return 0 ;
}
static int F_83 ( struct V_45 * V_40 )
{
struct V_31 * V_32 = V_40 -> V_123 ;
int V_122 ;
T_3 * V_193 ;
int V_108 ;
F_18 ( L_9 , V_40 -> V_16 . V_24 , V_40 -> V_16 . V_27 ) ;
V_122 = F_13 ( V_32 , & V_40 -> V_16 ) ;
if ( ( V_122 == 0 ) && ( V_32 -> V_169 == 0 ) ) {
V_193 = ( T_3 * ) V_40 -> V_125 ;
for ( V_108 = 0 ; V_108 < V_40 -> V_41 . V_42 / 2 ; V_108 ++ )
V_193 [ V_108 ] = 0x37e6 ;
F_30 ( V_32 , 0 , 0 , V_40 -> V_16 . V_24 , V_40 -> V_16 . V_27 ,
V_40 -> V_125 ) ;
}
return V_122 ;
}
static char * F_84 ( char * V_1 )
{
* V_1 ++ = 0xAF ;
* V_1 ++ = 0x6A ;
* V_1 ++ = 0x00 ;
* V_1 ++ = 0x00 ;
* V_1 ++ = 0x00 ;
* V_1 ++ = 0x01 ;
* V_1 ++ = 0x00 ;
* V_1 ++ = 0x00 ;
* V_1 ++ = 0x00 ;
return V_1 ;
}
static int F_85 ( int V_44 , struct V_45 * V_40 )
{
struct V_31 * V_32 = V_40 -> V_123 ;
char * V_194 ;
struct V_35 * V_35 ;
F_79 ( L_10 ,
V_40 -> V_173 , V_32 -> V_44 , V_44 ) ;
if ( ( V_32 -> V_44 == V_5 ) &&
( V_44 != V_5 ) ) {
F_13 ( V_32 , & V_40 -> V_16 ) ;
}
V_35 = F_15 ( V_32 ) ;
if ( ! V_35 )
return 0 ;
V_194 = ( char * ) V_35 -> V_39 ;
V_194 = F_2 ( V_194 ) ;
V_194 = F_4 ( V_194 , V_44 ) ;
V_194 = F_3 ( V_194 ) ;
V_194 = F_84 ( V_194 ) ;
F_16 ( V_32 , V_35 , V_194 -
( char * ) V_35 -> V_39 ) ;
V_32 -> V_44 = V_44 ;
return 0 ;
}
static int F_86 ( struct V_31 * V_32 , struct V_45 * V_40 )
{
int V_33 = - V_38 ;
int V_195 = V_40 -> V_41 . V_42 ;
int V_196 ;
unsigned char * V_197 = V_40 -> V_125 ;
unsigned char * V_198 ;
unsigned char * V_199 = 0 ;
F_64 ( L_11 ) ;
V_196 = V_40 -> V_41 . V_116 * V_40 -> V_16 . V_27 ;
if ( F_87 ( V_196 ) > V_195 ) {
V_198 = F_88 ( V_196 ) ;
if ( ! V_198 ) {
F_51 ( L_12 ) ;
goto error;
}
if ( V_40 -> V_125 ) {
memcpy ( V_198 , V_197 , V_195 ) ;
F_63 ( V_40 -> V_125 ) ;
}
V_40 -> V_125 = V_198 ;
V_40 -> V_41 . V_42 = F_87 ( V_196 ) ;
V_40 -> V_41 . V_58 = ( unsigned long ) V_198 ;
V_40 -> V_200 = V_201 ;
if ( V_202 )
V_199 = F_89 ( V_196 ) ;
if ( ! V_199 )
F_79 ( L_13 ) ;
else {
if ( V_32 -> V_101 )
F_63 ( V_32 -> V_101 ) ;
V_32 -> V_101 = V_199 ;
}
}
V_33 = 0 ;
error:
return V_33 ;
}
static int F_90 ( struct V_31 * V_32 ,
struct V_45 * V_40 ,
char * V_203 , T_10 V_204 )
{
int V_108 ;
const struct V_187 * V_205 = NULL ;
int V_122 = 0 ;
char * V_141 ;
int V_206 = 3 ;
if ( V_40 -> V_32 )
F_91 ( & V_40 -> V_207 ) ;
V_141 = F_48 ( V_208 , V_143 ) ;
if ( ! V_141 ) {
V_122 = - V_38 ;
goto error;
}
F_71 ( & V_40 -> V_183 ) ;
memset ( & V_40 -> V_181 , 0 , sizeof( V_40 -> V_181 ) ) ;
while ( V_206 -- ) {
V_108 = F_47 ( V_32 , V_141 , V_208 ) ;
if ( V_108 >= V_208 )
F_92 ( V_141 , & V_40 -> V_181 ) ;
if ( V_40 -> V_181 . V_209 > 0 ) {
V_32 -> V_141 = V_141 ;
V_32 -> V_148 = V_108 ;
break;
}
}
if ( V_40 -> V_181 . V_209 == 0 ) {
F_51 ( L_14 ) ;
if ( V_32 -> V_141 ) {
F_92 ( V_32 -> V_141 , & V_40 -> V_181 ) ;
if ( V_40 -> V_181 . V_209 > 0 )
F_51 ( L_15 ) ;
}
}
if ( V_40 -> V_181 . V_209 == 0 ) {
if ( V_204 >= V_208 ) {
F_92 ( V_203 , & V_40 -> V_181 ) ;
if ( V_40 -> V_181 . V_209 > 0 ) {
memcpy ( V_141 , V_203 , V_204 ) ;
V_32 -> V_141 = V_141 ;
V_32 -> V_148 = V_204 ;
F_51 ( L_16 ) ;
}
}
}
if ( V_40 -> V_181 . V_209 > 0 ) {
for ( V_108 = 0 ; V_108 < V_40 -> V_181 . V_209 ; V_108 ++ ) {
if ( F_78 ( & V_40 -> V_181 . V_182 [ V_108 ] , V_40 ) )
F_93 ( & V_40 -> V_181 . V_182 [ V_108 ] ,
& V_40 -> V_183 ) ;
else {
if ( V_108 == 0 )
V_40 -> V_181 . V_210
&= ~ V_211 ;
}
}
V_205 = F_94 ( & V_40 -> V_181 ,
& V_40 -> V_183 ) ;
}
if ( V_205 == NULL ) {
struct V_187 V_212 = { 0 } ;
for ( V_108 = 0 ; V_108 < V_213 ; V_108 ++ ) {
if ( F_78 ( (struct V_187 * )
& V_214 [ V_108 ] , V_40 ) )
F_93 ( & V_214 [ V_108 ] ,
& V_40 -> V_183 ) ;
}
V_212 . V_24 = 800 ;
V_212 . V_27 = 600 ;
V_212 . V_190 = 60 ;
V_205 = F_95 ( & V_212 ,
& V_40 -> V_183 ) ;
}
if ( ( V_205 != NULL ) && ( V_32 -> V_169 == 0 ) ) {
F_96 ( & V_40 -> V_16 , V_205 ) ;
F_80 ( & V_40 -> V_16 ) ;
memcpy ( & V_40 -> V_41 , & V_215 , sizeof( V_215 ) ) ;
V_40 -> V_41 . V_116 = V_40 -> V_16 . V_24 *
( V_40 -> V_16 . V_192 / 8 ) ;
V_122 = F_86 ( V_32 , V_40 ) ;
} else
V_122 = - V_57 ;
error:
if ( V_141 && ( V_32 -> V_141 != V_141 ) )
F_52 ( V_141 ) ;
if ( V_40 -> V_32 )
F_97 ( & V_40 -> V_207 ) ;
return V_122 ;
}
static T_8 F_98 ( struct V_216 * V_217 ,
struct V_218 * V_219 , char * V_1 ) {
struct V_45 * V_45 = F_99 ( V_217 ) ;
struct V_31 * V_32 = V_45 -> V_123 ;
return snprintf ( V_1 , V_59 , L_17 ,
F_14 ( & V_32 -> V_118 ) ) ;
}
static T_8 F_100 ( struct V_216 * V_217 ,
struct V_218 * V_219 , char * V_1 ) {
struct V_45 * V_45 = F_99 ( V_217 ) ;
struct V_31 * V_32 = V_45 -> V_123 ;
return snprintf ( V_1 , V_59 , L_17 ,
F_14 ( & V_32 -> V_113 ) ) ;
}
static T_8 F_101 ( struct V_216 * V_217 ,
struct V_218 * V_219 , char * V_1 ) {
struct V_45 * V_45 = F_99 ( V_217 ) ;
struct V_31 * V_32 = V_45 -> V_123 ;
return snprintf ( V_1 , V_59 , L_17 ,
F_14 ( & V_32 -> V_112 ) ) ;
}
static T_8 F_102 ( struct V_216 * V_217 ,
struct V_218 * V_219 , char * V_1 ) {
struct V_45 * V_45 = F_99 ( V_217 ) ;
struct V_31 * V_32 = V_45 -> V_123 ;
return snprintf ( V_1 , V_59 , L_17 ,
F_14 ( & V_32 -> V_119 ) ) ;
}
static T_8 F_103 (
struct V_220 * V_221 ,
struct V_222 * V_223 , struct V_224 * V_219 ,
char * V_1 , T_11 V_225 , T_10 V_120 ) {
struct V_216 * V_217 = F_62 ( V_223 , struct V_216 , V_223 ) ;
struct V_45 * V_45 = F_99 ( V_217 ) ;
struct V_31 * V_32 = V_45 -> V_123 ;
if ( V_32 -> V_141 == NULL )
return 0 ;
if ( ( V_225 >= V_32 -> V_148 ) || ( V_120 > V_32 -> V_148 ) )
return 0 ;
if ( V_225 + V_120 > V_32 -> V_148 )
V_120 = V_32 -> V_148 - V_225 ;
F_79 ( L_18 ,
V_32 -> V_141 , V_1 , ( int ) V_120 ) ;
memcpy ( V_1 , V_32 -> V_141 , V_120 ) ;
return V_120 ;
}
static T_8 F_104 (
struct V_220 * V_221 ,
struct V_222 * V_223 , struct V_224 * V_219 ,
char * V_226 , T_11 V_227 , T_10 V_228 ) {
struct V_216 * V_217 = F_62 ( V_223 , struct V_216 , V_223 ) ;
struct V_45 * V_45 = F_99 ( V_217 ) ;
struct V_31 * V_32 = V_45 -> V_123 ;
int V_109 ;
if ( ( V_228 != V_208 ) || ( V_227 != 0 ) )
return - V_57 ;
V_109 = F_90 ( V_32 , V_45 , V_226 , V_228 ) ;
if ( V_109 )
return V_109 ;
if ( ! V_32 -> V_141 || memcmp ( V_226 , V_32 -> V_141 , V_228 ) )
return - V_57 ;
F_79 ( L_19 ) ;
F_83 ( V_45 ) ;
return V_228 ;
}
static T_8 F_105 ( struct V_216 * V_217 ,
struct V_218 * V_229 ,
const char * V_1 , T_10 V_120 )
{
struct V_45 * V_45 = F_99 ( V_217 ) ;
struct V_31 * V_32 = V_45 -> V_123 ;
F_106 ( & V_32 -> V_118 , 0 ) ;
F_106 ( & V_32 -> V_113 , 0 ) ;
F_106 ( & V_32 -> V_112 , 0 ) ;
F_106 ( & V_32 -> V_119 , 0 ) ;
return V_120 ;
}
static int F_107 ( struct V_31 * V_32 )
{
int V_109 ;
T_1 V_230 [] = { 0x57 , 0xCD , 0xDC , 0xA7 ,
0x1C , 0x88 , 0x5E , 0x15 ,
0x60 , 0xFE , 0xC6 , 0x97 ,
0x16 , 0x3D , 0x47 , 0xF2 } ;
V_109 = F_49 ( V_32 -> V_144 , F_108 ( V_32 -> V_144 , 0 ) ,
V_231 ,
( V_232 | V_233 ) , 0 , 0 ,
V_230 , sizeof( V_230 ) , V_234 ) ;
return V_109 ;
}
static int F_109 ( struct V_31 * V_32 ,
struct V_235 * V_236 )
{
char * V_237 ;
char * V_1 ;
char * V_238 ;
int V_239 = 0 ;
V_1 = F_59 ( V_240 , V_143 ) ;
if ( ! V_1 )
return false ;
V_237 = V_1 ;
V_239 = F_110 ( F_111 ( V_236 ) ,
0x5f ,
0 , V_237 , V_240 ) ;
if ( V_239 < 0 ) {
if ( 0 == F_112 ( V_236 -> V_241 ,
0x5f , & V_237 ) )
V_239 = ( int ) V_237 [ 0 ] ;
}
if ( V_239 > 5 ) {
F_79 ( L_20 \
L_21 ,
V_239 , V_237 [ 0 ] ,
V_237 [ 1 ] , V_237 [ 2 ] , V_237 [ 3 ] , V_237 [ 4 ] , V_237 [ 5 ] , V_237 [ 6 ] ,
V_237 [ 7 ] , V_237 [ 8 ] , V_237 [ 9 ] , V_237 [ 10 ] ) ;
if ( ( V_237 [ 0 ] != V_239 ) ||
( V_237 [ 1 ] != 0x5f ) ||
( V_237 [ 2 ] != 0x01 ) ||
( V_237 [ 3 ] != 0x00 ) ||
( V_237 [ 4 ] != V_239 - 2 ) )
goto V_242;
V_238 = V_237 + V_239 ;
V_237 += 5 ;
while ( V_237 < V_238 ) {
T_1 V_243 ;
T_3 V_244 ;
V_244 = F_113 ( * ( ( T_3 * ) V_237 ) ) ;
V_237 += sizeof( T_3 ) ;
V_243 = * V_237 ;
V_237 ++ ;
switch ( V_244 ) {
case 0x0200 : {
T_2 V_245 ;
V_245 = F_114 ( * ( ( T_2 * ) V_237 ) ) ;
F_64 ( L_22 ,
V_245 ) ;
V_32 -> V_189 = V_245 ;
break;
}
default:
break;
}
V_237 += V_243 ;
}
} else {
F_79 ( L_23 , V_239 ) ;
}
goto V_246;
V_242:
F_51 ( L_24 ) ;
V_246:
F_52 ( V_1 ) ;
return true ;
}
static int F_115 ( struct V_235 * V_236 ,
const struct V_247 * V_248 )
{
struct V_249 * V_250 ;
struct V_31 * V_32 = 0 ;
int V_33 = - V_38 ;
V_250 = F_111 ( V_236 ) ;
V_32 = F_59 ( sizeof( * V_32 ) , V_143 ) ;
if ( V_32 == NULL ) {
F_116 ( & V_236 -> V_32 , L_25 ) ;
goto error;
}
F_117 ( & V_32 -> V_170 ) ;
V_32 -> V_144 = V_250 ;
V_32 -> V_251 = & V_250 -> V_32 ;
F_118 ( V_236 , V_32 ) ;
F_79 ( L_26 ,
V_250 -> V_252 , V_250 -> V_253 , V_250 -> V_254 ) ;
F_79 ( L_27 ,
V_250 -> V_255 . V_256 , V_250 -> V_255 . V_257 ,
V_250 -> V_255 . V_258 , V_32 ) ;
F_79 ( L_28 , V_165 ) ;
F_79 ( L_29 , V_139 ) ;
F_79 ( L_30 , V_202 ) ;
V_32 -> V_189 = 2048 * 1152 ;
if ( ! F_109 ( V_32 , V_236 ) ) {
F_51 ( L_31 ) ;
goto error;
}
if ( V_259 ) {
F_64 ( L_32
L_33 ,
V_32 -> V_189 , V_259 ) ;
V_32 -> V_189 = V_259 ;
}
if ( ! F_119 ( V_32 , V_260 , V_261 ) ) {
V_33 = - V_38 ;
F_51 ( L_34 ) ;
goto error;
}
F_58 ( & V_32 -> V_170 ) ;
F_120 ( & V_32 -> V_262 ,
V_263 ) ;
F_76 ( & V_32 -> V_262 , 0 ) ;
return 0 ;
error:
if ( V_32 ) {
F_73 ( & V_32 -> V_170 , F_61 ) ;
F_73 ( & V_32 -> V_170 , F_61 ) ;
}
return V_33 ;
}
static void V_263 ( struct V_174 * V_175 )
{
struct V_31 * V_32 = F_62 ( V_175 , struct V_31 ,
V_262 . V_175 ) ;
struct V_45 * V_40 ;
int V_33 ;
int V_108 ;
V_40 = F_121 ( 0 , V_32 -> V_251 ) ;
if ( ! V_40 ) {
V_33 = - V_38 ;
F_51 ( L_35 ) ;
goto error;
}
V_32 -> V_40 = V_40 ;
V_40 -> V_123 = V_32 ;
V_40 -> V_163 = V_32 -> V_163 ;
V_40 -> V_185 = & V_264 ;
V_33 = F_122 ( & V_40 -> V_162 , 256 , 0 ) ;
if ( V_33 < 0 ) {
F_51 ( L_36 , V_33 ) ;
goto error;
}
F_120 ( & V_32 -> V_184 ,
F_74 ) ;
F_123 ( & V_40 -> V_183 ) ;
V_33 = F_90 ( V_32 , V_40 , NULL , 0 ) ;
if ( V_33 != 0 ) {
F_51 ( L_37 ) ;
goto error;
}
F_106 ( & V_32 -> V_36 , 1 ) ;
F_107 ( V_32 ) ;
F_81 ( & V_40 -> V_16 , V_40 ) ;
F_83 ( V_40 ) ;
V_33 = F_124 ( V_40 ) ;
if ( V_33 < 0 ) {
F_51 ( L_38 , V_33 ) ;
goto error;
}
for ( V_108 = 0 ; V_108 < F_125 ( V_265 ) ; V_108 ++ ) {
V_33 = F_126 ( V_40 -> V_32 , & V_265 [ V_108 ] ) ;
if ( V_33 ) {
F_64 ( L_39 , V_33 ) ;
}
}
V_33 = F_127 ( V_40 -> V_32 , & V_266 ) ;
if ( V_33 ) {
F_64 ( L_40 , V_33 ) ;
}
F_79 ( L_41
L_42 , V_40 -> V_173 ,
V_40 -> V_16 . V_24 , V_40 -> V_16 . V_27 ,
( ( V_32 -> V_101 ) ?
V_40 -> V_41 . V_42 * 2 : V_40 -> V_41 . V_42 ) >> 10 ) ;
return;
error:
F_67 ( V_32 ) ;
}
static void F_128 ( struct V_235 * V_236 )
{
struct V_31 * V_32 ;
struct V_45 * V_40 ;
int V_108 ;
V_32 = F_129 ( V_236 ) ;
V_40 = V_32 -> V_40 ;
F_79 ( L_43 ) ;
V_32 -> V_167 = true ;
F_106 ( & V_32 -> V_36 , 0 ) ;
F_130 ( V_32 ) ;
if ( V_40 ) {
for ( V_108 = 0 ; V_108 < F_125 ( V_265 ) ; V_108 ++ )
F_131 ( V_40 -> V_32 , & V_265 [ V_108 ] ) ;
F_132 ( V_40 -> V_32 , & V_266 ) ;
F_133 ( V_40 ) ;
}
F_118 ( V_236 , NULL ) ;
V_32 -> V_144 = NULL ;
V_32 -> V_251 = NULL ;
if ( V_32 -> V_169 == 0 )
F_76 ( & V_32 -> V_184 , 0 ) ;
F_73 ( & V_32 -> V_170 , F_61 ) ;
return;
}
static void F_34 ( struct V_35 * V_35 )
{
struct V_176 * V_177 = V_35 -> V_267 ;
struct V_31 * V_32 = V_177 -> V_32 ;
unsigned long V_200 ;
if ( V_35 -> V_268 ) {
if ( ! ( V_35 -> V_268 == - V_269 ||
V_35 -> V_268 == - V_270 ||
V_35 -> V_268 == - V_271 ) ) {
F_51 ( L_44 ,
V_272 , V_35 -> V_268 ) ;
F_106 ( & V_32 -> V_273 , 1 ) ;
}
}
V_35 -> V_100 = V_32 -> V_179 . V_50 ;
F_134 ( & V_32 -> V_179 . V_207 , V_200 ) ;
F_135 ( & V_177 -> V_274 , & V_32 -> V_179 . V_275 ) ;
V_32 -> V_179 . V_276 ++ ;
F_136 ( & V_32 -> V_179 . V_207 , V_200 ) ;
if ( V_139 )
F_76 ( & V_177 -> V_178 , 0 ) ;
else
F_66 ( & V_32 -> V_179 . V_180 ) ;
}
static void F_130 ( struct V_31 * V_32 )
{
int V_120 = V_32 -> V_179 . V_120 ;
struct V_134 * V_173 ;
struct V_176 * V_177 ;
struct V_35 * V_35 ;
int V_109 ;
unsigned long V_200 ;
F_18 ( L_45 ) ;
while ( V_120 -- ) {
V_109 = F_137 ( & V_32 -> V_179 . V_180 ) ;
if ( V_109 )
break;
F_134 ( & V_32 -> V_179 . V_207 , V_200 ) ;
V_173 = V_32 -> V_179 . V_275 . V_277 ;
F_138 ( V_173 ) ;
F_136 ( & V_32 -> V_179 . V_207 , V_200 ) ;
V_177 = F_139 ( V_173 , struct V_176 , V_274 ) ;
V_35 = V_177 -> V_35 ;
F_140 ( V_35 -> V_32 , V_32 -> V_179 . V_50 ,
V_35 -> V_39 , V_35 -> V_278 ) ;
F_141 ( V_35 ) ;
F_52 ( V_173 ) ;
}
V_32 -> V_179 . V_120 = 0 ;
}
static int F_119 ( struct V_31 * V_32 , int V_120 , T_10 V_50 )
{
int V_108 = 0 ;
struct V_35 * V_35 ;
struct V_176 * V_177 ;
char * V_1 ;
F_142 ( & V_32 -> V_179 . V_207 ) ;
V_32 -> V_179 . V_50 = V_50 ;
F_123 ( & V_32 -> V_179 . V_275 ) ;
while ( V_108 < V_120 ) {
V_177 = F_59 ( sizeof( struct V_176 ) , V_143 ) ;
if ( ! V_177 )
break;
V_177 -> V_32 = V_32 ;
F_120 ( & V_177 -> V_178 ,
F_65 ) ;
V_35 = F_143 ( 0 , V_143 ) ;
if ( ! V_35 ) {
F_52 ( V_177 ) ;
break;
}
V_177 -> V_35 = V_35 ;
V_1 = F_144 ( V_32 -> V_144 , V_261 , V_143 ,
& V_35 -> V_278 ) ;
if ( ! V_1 ) {
F_52 ( V_177 ) ;
F_141 ( V_35 ) ;
break;
}
F_145 ( V_35 , V_32 -> V_144 , F_146 ( V_32 -> V_144 , 1 ) ,
V_1 , V_50 , F_34 , V_177 ) ;
V_35 -> V_279 |= V_280 ;
F_135 ( & V_177 -> V_274 , & V_32 -> V_179 . V_275 ) ;
V_108 ++ ;
}
F_147 ( & V_32 -> V_179 . V_180 , V_108 ) ;
V_32 -> V_179 . V_120 = V_108 ;
V_32 -> V_179 . V_276 = V_108 ;
F_18 ( L_46 , V_108 , ( int ) V_50 ) ;
return V_108 ;
}
static struct V_35 * F_15 ( struct V_31 * V_32 )
{
int V_109 = 0 ;
struct V_134 * V_274 ;
struct V_176 * V_177 ;
struct V_35 * V_35 = NULL ;
unsigned long V_200 ;
V_109 = F_148 ( & V_32 -> V_179 . V_180 , V_281 ) ;
if ( V_109 ) {
F_106 ( & V_32 -> V_273 , 1 ) ;
F_64 ( L_47 ,
V_109 , V_32 -> V_179 . V_276 ) ;
goto error;
}
F_134 ( & V_32 -> V_179 . V_207 , V_200 ) ;
F_149 ( F_150 ( & V_32 -> V_179 . V_275 ) ) ;
V_274 = V_32 -> V_179 . V_275 . V_277 ;
F_138 ( V_274 ) ;
V_32 -> V_179 . V_276 -- ;
F_136 ( & V_32 -> V_179 . V_207 , V_200 ) ;
V_177 = F_139 ( V_274 , struct V_176 , V_274 ) ;
V_35 = V_177 -> V_35 ;
error:
return V_35 ;
}
static int F_16 ( struct V_31 * V_32 , struct V_35 * V_35 , T_10 V_103 )
{
int V_109 ;
F_149 ( V_103 > V_32 -> V_179 . V_50 ) ;
V_35 -> V_100 = V_103 ;
V_109 = F_151 ( V_35 , V_143 ) ;
if ( V_109 ) {
F_34 ( V_35 ) ;
F_106 ( & V_32 -> V_273 , 1 ) ;
F_51 ( L_48 , V_109 ) ;
}
return V_109 ;
}
