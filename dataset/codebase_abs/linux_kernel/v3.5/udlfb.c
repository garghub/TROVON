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
if ( V_52 + V_50 > V_40 -> V_41 . V_42 )
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
V_47 -> V_62 |= V_63 ;
return 0 ;
}
static int F_21 ( const T_1 * V_64 , const T_1 * * V_65 , int * V_66 )
{
int V_67 , V_68 ;
const unsigned long * V_69 = ( const unsigned long * ) V_64 ;
const unsigned long * V_70 = ( const unsigned long * ) * V_65 ;
const int V_71 = * V_66 / sizeof( unsigned long ) ;
int V_72 = V_71 ;
int V_48 = V_71 ;
int V_73 = V_71 ;
F_22 ( ( void * ) V_70 ) ;
F_22 ( ( void * ) V_69 ) ;
for ( V_67 = 0 ; V_67 < V_71 ; V_67 ++ ) {
if ( V_69 [ V_67 ] != V_70 [ V_67 ] ) {
V_48 = V_67 ;
break;
}
}
for ( V_68 = V_71 - 1 ; V_68 > V_67 ; V_68 -- ) {
if ( V_69 [ V_68 ] != V_70 [ V_68 ] ) {
V_73 = V_68 + 1 ;
break;
}
}
V_72 = V_48 + ( V_71 - V_73 ) ;
* V_65 = ( T_1 * ) & V_70 [ V_48 ] ;
* V_66 = ( V_73 - V_48 ) * sizeof( unsigned long ) ;
return V_72 * sizeof( unsigned long ) ;
}
static void F_23 (
const T_4 * * V_74 ,
const T_4 * const V_75 ,
T_5 * V_76 ,
T_6 * * V_77 ,
const T_6 * const V_78 )
{
const T_4 * V_79 = * V_74 ;
T_5 V_80 = * V_76 ;
T_6 * V_81 = * V_77 ;
const int V_82 = 2 ;
while ( ( V_75 > V_79 ) &&
( V_78 - V_83 > V_81 ) ) {
T_6 * V_84 = 0 ;
T_6 * V_85 = 0 ;
const T_4 * V_86 = 0 ;
const T_4 * V_87 , * V_88 = 0 ;
F_24 ( ( void * ) V_81 ) ;
* V_81 ++ = 0xAF ;
* V_81 ++ = 0x6B ;
* V_81 ++ = ( T_6 ) ( ( V_80 >> 16 ) & 0xFF ) ;
* V_81 ++ = ( T_6 ) ( ( V_80 >> 8 ) & 0xFF ) ;
* V_81 ++ = ( T_6 ) ( ( V_80 ) & 0xFF ) ;
V_85 = V_81 ++ ;
V_87 = V_79 ;
V_84 = V_81 ++ ;
V_86 = V_79 ;
V_88 = V_79 + F_25 ( V_89 + 1 ,
F_25 ( ( int ) ( V_75 - V_79 ) ,
( int ) ( V_78 - V_81 ) / V_82 ) ) ;
F_26 ( ( void * ) V_79 , ( V_88 - V_79 ) * V_82 ) ;
while ( V_79 < V_88 ) {
const T_4 * const V_90 = V_79 ;
* ( T_4 * ) V_81 = F_27 ( V_79 ) ;
V_81 += 2 ;
V_79 ++ ;
if ( F_28 ( ( V_79 < V_88 ) &&
( * V_79 == * V_90 ) ) ) {
* V_84 = ( ( V_90 -
V_86 ) + 1 ) & 0xFF ;
while ( ( V_79 < V_88 )
&& ( * V_79 == * V_90 ) ) {
V_79 ++ ;
}
* V_81 ++ = ( ( V_79 - V_90 ) - 1 ) & 0xFF ;
V_86 = V_79 ;
V_84 = V_81 ++ ;
}
}
if ( V_79 > V_86 ) {
* V_84 = ( V_79 - V_86 ) & 0xFF ;
}
* V_85 = ( V_79 - V_87 ) & 0xFF ;
V_80 += ( V_79 - V_87 ) * V_82 ;
}
if ( V_78 <= V_83 + V_81 ) {
if ( V_78 > V_81 )
memset ( V_81 , 0xAF , V_78 - V_81 ) ;
V_81 = ( T_6 * ) V_78 ;
}
* V_77 = V_81 ;
* V_74 = V_79 ;
* V_76 = V_80 ;
return;
}
static int F_29 ( struct V_31 * V_32 , struct V_35 * * V_91 ,
const char * V_70 , char * * V_92 ,
T_2 V_93 , T_2 V_94 ,
int * V_95 , int * V_96 )
{
const T_1 * V_97 , * V_98 , * V_99 ;
T_2 V_80 = V_32 -> V_100 + V_93 ;
struct V_35 * V_35 = * V_91 ;
T_1 * V_81 = * V_92 ;
T_1 * V_101 = ( T_1 * ) V_35 -> V_39 + V_35 -> V_102 ;
V_97 = ( T_1 * ) ( V_70 + V_93 ) ;
V_99 = V_97 ;
V_98 = V_99 + V_94 ;
if ( V_32 -> V_103 ) {
int V_52 ;
const T_1 * V_104 = ( T_1 * ) ( V_32 -> V_103
+ V_93 ) ;
* V_95 += F_21 ( V_104 , & V_99 ,
& V_94 ) ;
V_52 = V_99 - V_97 ;
V_98 = V_99 + V_94 ;
V_80 += V_52 ;
V_104 += V_52 ;
V_97 += V_52 ;
memcpy ( ( char * ) V_104 , ( char * ) V_97 ,
V_94 ) ;
}
while ( V_99 < V_98 ) {
F_23 ( ( const T_4 * * ) & V_99 ,
( const T_4 * ) V_98 , & V_80 ,
( T_1 * * ) & V_81 , ( T_1 * ) V_101 ) ;
if ( V_81 >= V_101 ) {
int V_105 = V_81 - ( T_1 * ) V_35 -> V_39 ;
if ( F_16 ( V_32 , V_35 , V_105 ) )
return 1 ;
* V_96 += V_105 ;
V_35 = F_15 ( V_32 ) ;
if ( ! V_35 )
return 1 ;
* V_91 = V_35 ;
V_81 = V_35 -> V_39 ;
V_101 = & V_81 [ V_35 -> V_102 ] ;
}
}
* V_92 = V_81 ;
return 0 ;
}
int F_30 ( struct V_31 * V_32 , int V_106 , int V_107 ,
int V_71 , int V_108 , char * V_109 )
{
int V_110 , V_111 ;
char * V_81 ;
T_7 V_112 , V_113 ;
int V_114 = 0 ;
int V_115 = 0 ;
struct V_35 * V_35 ;
int V_116 ;
V_112 = F_31 () ;
V_116 = F_32 ( V_106 , sizeof( unsigned long ) ) ;
V_71 = F_33 ( V_71 + ( V_106 - V_116 ) , sizeof( unsigned long ) ) ;
V_106 = V_116 ;
if ( ( V_71 <= 0 ) ||
( V_106 + V_71 > V_32 -> V_40 -> V_16 . V_24 ) ||
( V_107 + V_108 > V_32 -> V_40 -> V_16 . V_27 ) )
return - V_57 ;
if ( ! F_14 ( & V_32 -> V_36 ) )
return 0 ;
V_35 = F_15 ( V_32 ) ;
if ( ! V_35 )
return 0 ;
V_81 = V_35 -> V_39 ;
for ( V_110 = V_107 ; V_110 < V_107 + V_108 ; V_110 ++ ) {
const int V_117 = V_32 -> V_40 -> V_41 . V_118 * V_110 ;
const int V_93 = V_117 + ( V_106 * V_119 ) ;
if ( F_29 ( V_32 , & V_35 ,
( char * ) V_32 -> V_40 -> V_41 . V_58 ,
& V_81 , V_93 , V_71 * V_119 ,
& V_115 , & V_114 ) )
goto error;
}
if ( V_81 > ( char * ) V_35 -> V_39 ) {
int V_105 = V_81 - ( char * ) V_35 -> V_39 ;
V_111 = F_16 ( V_32 , V_35 , V_105 ) ;
V_114 += V_105 ;
} else
F_34 ( V_35 ) ;
error:
F_35 ( V_114 , & V_32 -> V_114 ) ;
F_35 ( V_115 , & V_32 -> V_115 ) ;
F_35 ( V_71 * V_108 * 2 , & V_32 -> V_120 ) ;
V_113 = F_31 () ;
F_35 ( ( ( unsigned int ) ( ( V_113 - V_112 )
>> 10 ) ) ,
& V_32 -> V_121 ) ;
return 0 ;
}
static T_8 F_36 ( struct V_45 * V_40 , const char T_9 * V_1 ,
T_10 V_122 , T_11 * V_123 )
{
T_8 V_124 ;
struct V_31 * V_32 = V_40 -> V_125 ;
T_2 V_52 = ( T_2 ) * V_123 ;
V_124 = F_37 ( V_40 , V_1 , V_122 , V_123 ) ;
if ( V_124 > 0 ) {
int V_48 = F_38 ( ( int ) ( V_52 / V_40 -> V_41 . V_118 ) - 1 , 0 ) ;
int V_126 = F_25 ( ( T_2 ) ( ( V_124 / V_40 -> V_41 . V_118 ) + 1 ) ,
( T_2 ) V_40 -> V_16 . V_27 ) ;
F_30 ( V_32 , 0 , V_48 , V_40 -> V_16 . V_24 ,
V_126 , V_40 -> V_127 ) ;
}
return V_124 ;
}
static void F_39 ( struct V_45 * V_40 ,
const struct V_128 * V_129 )
{
struct V_31 * V_32 = V_40 -> V_125 ;
F_40 ( V_40 , V_129 ) ;
F_30 ( V_32 , V_129 -> V_130 , V_129 -> V_131 ,
V_129 -> V_71 , V_129 -> V_108 , V_40 -> V_127 ) ;
}
static void F_41 ( struct V_45 * V_40 ,
const struct V_132 * V_133 )
{
struct V_31 * V_32 = V_40 -> V_125 ;
F_42 ( V_40 , V_133 ) ;
F_30 ( V_32 , V_133 -> V_130 , V_133 -> V_131 ,
V_133 -> V_71 , V_133 -> V_108 , V_40 -> V_127 ) ;
}
static void F_43 ( struct V_45 * V_40 ,
const struct V_134 * V_135 )
{
struct V_31 * V_32 = V_40 -> V_125 ;
F_44 ( V_40 , V_135 ) ;
F_30 ( V_32 , V_135 -> V_130 , V_135 -> V_131 , V_135 -> V_71 ,
V_135 -> V_108 , V_40 -> V_127 ) ;
}
static void F_45 ( struct V_45 * V_40 ,
struct V_136 * V_137 )
{
struct V_55 * V_138 ;
struct V_139 * V_140 = V_40 -> V_140 ;
struct V_31 * V_32 = V_40 -> V_125 ;
struct V_35 * V_35 ;
char * V_81 ;
T_7 V_112 , V_113 ;
int V_114 = 0 ;
int V_115 = 0 ;
int V_120 = 0 ;
if ( ! V_141 )
return;
if ( ! F_14 ( & V_32 -> V_36 ) )
return;
V_112 = F_31 () ;
V_35 = F_15 ( V_32 ) ;
if ( ! V_35 )
return;
V_81 = V_35 -> V_39 ;
F_46 (cur, &fbdefio->pagelist, lru) {
if ( F_29 ( V_32 , & V_35 , ( char * ) V_40 -> V_41 . V_58 ,
& V_81 , V_138 -> V_142 << V_54 ,
V_59 , & V_115 , & V_114 ) )
goto error;
V_120 += V_59 ;
}
if ( V_81 > ( char * ) V_35 -> V_39 ) {
int V_105 = V_81 - ( char * ) V_35 -> V_39 ;
F_16 ( V_32 , V_35 , V_105 ) ;
V_114 += V_105 ;
} else
F_34 ( V_35 ) ;
error:
F_35 ( V_114 , & V_32 -> V_114 ) ;
F_35 ( V_115 , & V_32 -> V_115 ) ;
F_35 ( V_120 , & V_32 -> V_120 ) ;
V_113 = F_31 () ;
F_35 ( ( ( unsigned int ) ( ( V_113 - V_112 )
>> 10 ) ) ,
& V_32 -> V_121 ) ;
}
static int F_47 ( struct V_31 * V_32 , char * V_143 , int V_105 )
{
int V_110 ;
int V_111 ;
char * V_144 ;
V_144 = F_48 ( 2 , V_145 ) ;
if ( ! V_144 )
return 0 ;
for ( V_110 = 0 ; V_110 < V_105 ; V_110 ++ ) {
V_111 = F_49 ( V_32 -> V_146 ,
F_50 ( V_32 -> V_146 , 0 ) , ( 0x02 ) ,
( 0x80 | ( 0x02 << 5 ) ) , V_110 << 8 , 0xA1 , V_144 , 2 ,
V_147 ) ;
if ( V_111 < 1 ) {
F_51 ( L_2 , V_110 , V_111 ) ;
V_110 -- ;
break;
}
V_143 [ V_110 ] = V_144 [ 1 ] ;
}
F_52 ( V_144 ) ;
return V_110 ;
}
static int F_53 ( struct V_45 * V_40 , unsigned int V_81 ,
unsigned long V_148 )
{
struct V_31 * V_32 = V_40 -> V_125 ;
if ( ! F_14 ( & V_32 -> V_36 ) )
return 0 ;
if ( V_81 == V_149 ) {
void T_9 * V_143 = ( void T_9 * ) V_148 ;
if ( F_54 ( V_143 , V_32 -> V_143 , V_32 -> V_150 ) )
return - V_151 ;
return 0 ;
}
if ( V_81 == V_152 ) {
struct V_153 V_129 ;
if ( F_55 ( & V_129 , ( void T_9 * ) V_148 ,
sizeof( struct V_153 ) ) )
return - V_151 ;
if ( V_40 -> V_140 )
V_40 -> V_140 -> V_154 = V_155 ;
if ( V_129 . V_106 < 0 )
V_129 . V_106 = 0 ;
if ( V_129 . V_106 > V_40 -> V_16 . V_24 )
V_129 . V_106 = V_40 -> V_16 . V_24 ;
if ( V_129 . V_107 < 0 )
V_129 . V_107 = 0 ;
if ( V_129 . V_107 > V_40 -> V_16 . V_27 )
V_129 . V_107 = V_40 -> V_16 . V_27 ;
F_30 ( V_32 , V_129 . V_106 , V_129 . V_107 , V_129 . V_156 , V_129 . V_157 ,
V_40 -> V_127 ) ;
}
return 0 ;
}
static int
F_56 ( unsigned V_158 , unsigned V_159 , unsigned V_160 ,
unsigned V_161 , unsigned V_162 , struct V_45 * V_40 )
{
int V_163 = 0 ;
if ( V_158 >= V_40 -> V_164 . V_105 )
return 1 ;
if ( V_158 < 16 ) {
if ( V_40 -> V_16 . V_159 . V_52 == 10 ) {
( ( T_2 * ) ( V_40 -> V_165 ) ) [ V_158 ] =
( ( V_159 & 0xf800 ) >> 1 ) |
( ( V_160 & 0xf800 ) >> 6 ) | ( ( V_161 & 0xf800 ) >> 11 ) ;
} else {
( ( T_2 * ) ( V_40 -> V_165 ) ) [ V_158 ] =
( ( V_159 & 0xf800 ) ) |
( ( V_160 & 0xfc00 ) >> 5 ) | ( ( V_161 & 0xf800 ) >> 11 ) ;
}
}
return V_163 ;
}
static int F_57 ( struct V_45 * V_40 , int V_166 )
{
struct V_31 * V_32 = V_40 -> V_125 ;
if ( ( V_166 == 0 ) && ( ! V_167 ) )
return - V_168 ;
if ( V_32 -> V_169 )
return - V_170 ;
V_32 -> V_171 ++ ;
F_58 ( & V_32 -> V_172 ) ;
if ( V_141 && ( V_40 -> V_140 == NULL ) ) {
struct V_139 * V_140 ;
V_140 = F_59 ( sizeof( struct V_139 ) , V_145 ) ;
if ( V_140 ) {
V_140 -> V_154 = V_173 ;
V_140 -> V_174 = F_45 ;
}
V_40 -> V_140 = V_140 ;
F_60 ( V_40 ) ;
}
F_18 ( L_3 ,
V_40 -> V_175 , V_166 , V_40 , V_32 -> V_171 ) ;
return 0 ;
}
static void F_61 ( struct V_172 * V_172 )
{
struct V_31 * V_32 = F_62 ( V_172 , struct V_31 , V_172 ) ;
if ( V_32 -> V_103 )
F_63 ( V_32 -> V_103 ) ;
F_52 ( V_32 -> V_143 ) ;
F_64 ( L_4 , V_32 ) ;
F_52 ( V_32 ) ;
}
static void F_65 ( struct V_176 * V_177 )
{
struct V_178 * V_179 = F_62 ( V_177 , struct V_178 ,
V_180 . V_177 ) ;
F_66 ( & V_179 -> V_32 -> V_181 . V_182 ) ;
}
static void F_67 ( struct V_31 * V_32 )
{
struct V_45 * V_40 = V_32 -> V_40 ;
if ( V_40 ) {
int V_175 = V_40 -> V_175 ;
F_68 ( V_40 ) ;
if ( V_40 -> V_164 . V_105 != 0 )
F_69 ( & V_40 -> V_164 ) ;
if ( V_40 -> V_183 . V_184 )
F_70 ( V_40 -> V_183 . V_184 ) ;
if ( V_40 -> V_127 )
F_63 ( V_40 -> V_127 ) ;
F_71 ( & V_40 -> V_185 ) ;
V_32 -> V_40 = NULL ;
F_72 ( V_40 ) ;
F_64 ( L_5 , V_175 ) ;
}
F_73 ( & V_32 -> V_172 , F_61 ) ;
}
static void F_74 ( struct V_176 * V_177 )
{
struct V_31 * V_32 = F_62 ( V_177 , struct V_31 ,
V_186 . V_177 ) ;
F_67 ( V_32 ) ;
}
static int F_75 ( struct V_45 * V_40 , int V_166 )
{
struct V_31 * V_32 = V_40 -> V_125 ;
V_32 -> V_171 -- ;
if ( V_32 -> V_169 && ( V_32 -> V_171 == 0 ) )
F_76 ( & V_32 -> V_186 , V_147 ) ;
if ( ( V_32 -> V_171 == 0 ) && ( V_40 -> V_140 ) ) {
F_77 ( V_40 ) ;
F_52 ( V_40 -> V_140 ) ;
V_40 -> V_140 = NULL ;
V_40 -> V_187 -> V_188 = F_17 ;
}
F_64 ( L_6 ,
V_40 -> V_175 , V_166 , V_32 -> V_171 ) ;
F_73 ( & V_32 -> V_172 , F_61 ) ;
return 0 ;
}
static int F_78 ( struct V_189 * V_190 ,
struct V_45 * V_40 )
{
struct V_31 * V_32 = V_40 -> V_125 ;
if ( V_190 -> V_24 * V_190 -> V_27 > V_32 -> V_191 ) {
F_64 ( L_7 ,
V_190 -> V_24 , V_190 -> V_27 ) ;
return 0 ;
}
F_79 ( L_8 , V_190 -> V_24 , V_190 -> V_27 ,
V_190 -> V_192 ) ;
return 1 ;
}
static void F_80 ( struct V_15 * V_16 )
{
const struct V_193 V_159 = { 11 , 5 , 0 } ;
const struct V_193 V_160 = { 5 , 6 , 0 } ;
const struct V_193 V_161 = { 0 , 5 , 0 } ;
V_16 -> V_194 = 16 ;
V_16 -> V_159 = V_159 ;
V_16 -> V_160 = V_160 ;
V_16 -> V_161 = V_161 ;
}
static int F_81 ( struct V_15 * V_16 ,
struct V_45 * V_40 )
{
struct V_189 V_190 ;
if ( ( V_16 -> V_24 * V_16 -> V_27 * 2 ) > V_40 -> V_41 . V_42 )
return - V_57 ;
F_80 ( V_16 ) ;
F_82 ( & V_190 , V_16 ) ;
if ( ! F_78 ( & V_190 , V_40 ) )
return - V_57 ;
return 0 ;
}
static int F_83 ( struct V_45 * V_40 )
{
struct V_31 * V_32 = V_40 -> V_125 ;
int V_124 ;
T_3 * V_195 ;
int V_110 ;
F_18 ( L_9 , V_40 -> V_16 . V_24 , V_40 -> V_16 . V_27 ) ;
V_124 = F_13 ( V_32 , & V_40 -> V_16 ) ;
if ( ( V_124 == 0 ) && ( V_32 -> V_171 == 0 ) ) {
V_195 = ( T_3 * ) V_40 -> V_127 ;
for ( V_110 = 0 ; V_110 < V_40 -> V_41 . V_42 / 2 ; V_110 ++ )
V_195 [ V_110 ] = 0x37e6 ;
F_30 ( V_32 , 0 , 0 , V_40 -> V_16 . V_24 , V_40 -> V_16 . V_27 ,
V_40 -> V_127 ) ;
}
return V_124 ;
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
struct V_31 * V_32 = V_40 -> V_125 ;
char * V_196 ;
struct V_35 * V_35 ;
F_79 ( L_10 ,
V_40 -> V_175 , V_32 -> V_44 , V_44 ) ;
if ( ( V_32 -> V_44 == V_5 ) &&
( V_44 != V_5 ) ) {
F_13 ( V_32 , & V_40 -> V_16 ) ;
}
V_35 = F_15 ( V_32 ) ;
if ( ! V_35 )
return 0 ;
V_196 = ( char * ) V_35 -> V_39 ;
V_196 = F_2 ( V_196 ) ;
V_196 = F_4 ( V_196 , V_44 ) ;
V_196 = F_3 ( V_196 ) ;
V_196 = F_84 ( V_196 ) ;
F_16 ( V_32 , V_35 , V_196 -
( char * ) V_35 -> V_39 ) ;
V_32 -> V_44 = V_44 ;
return 0 ;
}
static int F_86 ( struct V_31 * V_32 , struct V_45 * V_40 )
{
int V_33 = - V_38 ;
int V_197 = V_40 -> V_41 . V_42 ;
int V_198 ;
unsigned char * V_199 = V_40 -> V_127 ;
unsigned char * V_200 ;
unsigned char * V_201 = 0 ;
F_64 ( L_11 ) ;
V_198 = V_40 -> V_41 . V_118 * V_40 -> V_16 . V_27 ;
if ( F_87 ( V_198 ) > V_197 ) {
V_200 = F_88 ( V_198 ) ;
if ( ! V_200 ) {
F_51 ( L_12 ) ;
goto error;
}
if ( V_40 -> V_127 ) {
memcpy ( V_200 , V_199 , V_197 ) ;
F_63 ( V_40 -> V_127 ) ;
}
V_40 -> V_127 = V_200 ;
V_40 -> V_41 . V_42 = F_87 ( V_198 ) ;
V_40 -> V_41 . V_58 = ( unsigned long ) V_200 ;
V_40 -> V_202 = V_203 ;
if ( V_204 )
V_201 = F_89 ( V_198 ) ;
if ( ! V_201 )
F_79 ( L_13 ) ;
else {
if ( V_32 -> V_103 )
F_63 ( V_32 -> V_103 ) ;
V_32 -> V_103 = V_201 ;
}
}
V_33 = 0 ;
error:
return V_33 ;
}
static int F_90 ( struct V_31 * V_32 ,
struct V_45 * V_40 ,
char * V_205 , T_10 V_206 )
{
int V_110 ;
const struct V_189 * V_207 = NULL ;
int V_124 = 0 ;
char * V_143 ;
int V_208 = 3 ;
if ( V_40 -> V_32 )
F_91 ( & V_40 -> V_209 ) ;
V_143 = F_48 ( V_210 , V_145 ) ;
if ( ! V_143 ) {
V_124 = - V_38 ;
goto error;
}
F_71 ( & V_40 -> V_185 ) ;
memset ( & V_40 -> V_183 , 0 , sizeof( V_40 -> V_183 ) ) ;
while ( V_208 -- ) {
V_110 = F_47 ( V_32 , V_143 , V_210 ) ;
if ( V_110 >= V_210 )
F_92 ( V_143 , & V_40 -> V_183 ) ;
if ( V_40 -> V_183 . V_211 > 0 ) {
V_32 -> V_143 = V_143 ;
V_32 -> V_150 = V_110 ;
break;
}
}
if ( V_40 -> V_183 . V_211 == 0 ) {
F_51 ( L_14 ) ;
if ( V_32 -> V_143 ) {
F_92 ( V_32 -> V_143 , & V_40 -> V_183 ) ;
if ( V_40 -> V_183 . V_211 > 0 )
F_51 ( L_15 ) ;
}
}
if ( V_40 -> V_183 . V_211 == 0 ) {
if ( V_206 >= V_210 ) {
F_92 ( V_205 , & V_40 -> V_183 ) ;
if ( V_40 -> V_183 . V_211 > 0 ) {
memcpy ( V_143 , V_205 , V_206 ) ;
V_32 -> V_143 = V_143 ;
V_32 -> V_150 = V_206 ;
F_51 ( L_16 ) ;
}
}
}
if ( V_40 -> V_183 . V_211 > 0 ) {
for ( V_110 = 0 ; V_110 < V_40 -> V_183 . V_211 ; V_110 ++ ) {
if ( F_78 ( & V_40 -> V_183 . V_184 [ V_110 ] , V_40 ) )
F_93 ( & V_40 -> V_183 . V_184 [ V_110 ] ,
& V_40 -> V_185 ) ;
else {
if ( V_110 == 0 )
V_40 -> V_183 . V_212
&= ~ V_213 ;
}
}
V_207 = F_94 ( & V_40 -> V_183 ,
& V_40 -> V_185 ) ;
}
if ( V_207 == NULL ) {
struct V_189 V_214 = { 0 } ;
for ( V_110 = 0 ; V_110 < V_215 ; V_110 ++ ) {
if ( F_78 ( (struct V_189 * )
& V_216 [ V_110 ] , V_40 ) )
F_93 ( & V_216 [ V_110 ] ,
& V_40 -> V_185 ) ;
}
V_214 . V_24 = 800 ;
V_214 . V_27 = 600 ;
V_214 . V_192 = 60 ;
V_207 = F_95 ( & V_214 ,
& V_40 -> V_185 ) ;
}
if ( ( V_207 != NULL ) && ( V_32 -> V_171 == 0 ) ) {
F_96 ( & V_40 -> V_16 , V_207 ) ;
F_80 ( & V_40 -> V_16 ) ;
memcpy ( & V_40 -> V_41 , & V_217 , sizeof( V_217 ) ) ;
V_40 -> V_41 . V_118 = V_40 -> V_16 . V_24 *
( V_40 -> V_16 . V_194 / 8 ) ;
V_124 = F_86 ( V_32 , V_40 ) ;
} else
V_124 = - V_57 ;
error:
if ( V_143 && ( V_32 -> V_143 != V_143 ) )
F_52 ( V_143 ) ;
if ( V_40 -> V_32 )
F_97 ( & V_40 -> V_209 ) ;
return V_124 ;
}
static T_8 F_98 ( struct V_218 * V_219 ,
struct V_220 * V_221 , char * V_1 ) {
struct V_45 * V_45 = F_99 ( V_219 ) ;
struct V_31 * V_32 = V_45 -> V_125 ;
return snprintf ( V_1 , V_59 , L_17 ,
F_14 ( & V_32 -> V_120 ) ) ;
}
static T_8 F_100 ( struct V_218 * V_219 ,
struct V_220 * V_221 , char * V_1 ) {
struct V_45 * V_45 = F_99 ( V_219 ) ;
struct V_31 * V_32 = V_45 -> V_125 ;
return snprintf ( V_1 , V_59 , L_17 ,
F_14 ( & V_32 -> V_115 ) ) ;
}
static T_8 F_101 ( struct V_218 * V_219 ,
struct V_220 * V_221 , char * V_1 ) {
struct V_45 * V_45 = F_99 ( V_219 ) ;
struct V_31 * V_32 = V_45 -> V_125 ;
return snprintf ( V_1 , V_59 , L_17 ,
F_14 ( & V_32 -> V_114 ) ) ;
}
static T_8 F_102 ( struct V_218 * V_219 ,
struct V_220 * V_221 , char * V_1 ) {
struct V_45 * V_45 = F_99 ( V_219 ) ;
struct V_31 * V_32 = V_45 -> V_125 ;
return snprintf ( V_1 , V_59 , L_17 ,
F_14 ( & V_32 -> V_121 ) ) ;
}
static T_8 F_103 (
struct V_222 * V_223 ,
struct V_224 * V_225 , struct V_226 * V_221 ,
char * V_1 , T_11 V_227 , T_10 V_122 ) {
struct V_218 * V_219 = F_62 ( V_225 , struct V_218 , V_225 ) ;
struct V_45 * V_45 = F_99 ( V_219 ) ;
struct V_31 * V_32 = V_45 -> V_125 ;
if ( V_32 -> V_143 == NULL )
return 0 ;
if ( ( V_227 >= V_32 -> V_150 ) || ( V_122 > V_32 -> V_150 ) )
return 0 ;
if ( V_227 + V_122 > V_32 -> V_150 )
V_122 = V_32 -> V_150 - V_227 ;
F_79 ( L_18 ,
V_32 -> V_143 , V_1 , ( int ) V_122 ) ;
memcpy ( V_1 , V_32 -> V_143 , V_122 ) ;
return V_122 ;
}
static T_8 F_104 (
struct V_222 * V_223 ,
struct V_224 * V_225 , struct V_226 * V_221 ,
char * V_228 , T_11 V_229 , T_10 V_230 ) {
struct V_218 * V_219 = F_62 ( V_225 , struct V_218 , V_225 ) ;
struct V_45 * V_45 = F_99 ( V_219 ) ;
struct V_31 * V_32 = V_45 -> V_125 ;
int V_111 ;
if ( ( V_230 != V_210 ) || ( V_229 != 0 ) )
return - V_57 ;
V_111 = F_90 ( V_32 , V_45 , V_228 , V_230 ) ;
if ( V_111 )
return V_111 ;
if ( ! V_32 -> V_143 || memcmp ( V_228 , V_32 -> V_143 , V_230 ) )
return - V_57 ;
F_79 ( L_19 ) ;
F_83 ( V_45 ) ;
return V_230 ;
}
static T_8 F_105 ( struct V_218 * V_219 ,
struct V_220 * V_231 ,
const char * V_1 , T_10 V_122 )
{
struct V_45 * V_45 = F_99 ( V_219 ) ;
struct V_31 * V_32 = V_45 -> V_125 ;
F_106 ( & V_32 -> V_120 , 0 ) ;
F_106 ( & V_32 -> V_115 , 0 ) ;
F_106 ( & V_32 -> V_114 , 0 ) ;
F_106 ( & V_32 -> V_121 , 0 ) ;
return V_122 ;
}
static int F_107 ( struct V_31 * V_32 )
{
int V_111 ;
T_1 V_232 [] = { 0x57 , 0xCD , 0xDC , 0xA7 ,
0x1C , 0x88 , 0x5E , 0x15 ,
0x60 , 0xFE , 0xC6 , 0x97 ,
0x16 , 0x3D , 0x47 , 0xF2 } ;
V_111 = F_49 ( V_32 -> V_146 , F_108 ( V_32 -> V_146 , 0 ) ,
V_233 ,
( V_234 | V_235 ) , 0 , 0 ,
V_232 , sizeof( V_232 ) , V_236 ) ;
return V_111 ;
}
static int F_109 ( struct V_31 * V_32 ,
struct V_237 * V_238 )
{
char * V_239 ;
char * V_1 ;
char * V_240 ;
int V_241 = 0 ;
V_1 = F_59 ( V_242 , V_145 ) ;
if ( ! V_1 )
return false ;
V_239 = V_1 ;
V_241 = F_110 ( F_111 ( V_238 ) ,
0x5f ,
0 , V_239 , V_242 ) ;
if ( V_241 < 0 ) {
if ( 0 == F_112 ( V_238 -> V_243 ,
0x5f , & V_239 ) )
V_241 = ( int ) V_239 [ 0 ] ;
}
if ( V_241 > 5 ) {
F_79 ( L_20 \
L_21 ,
V_241 , V_239 [ 0 ] ,
V_239 [ 1 ] , V_239 [ 2 ] , V_239 [ 3 ] , V_239 [ 4 ] , V_239 [ 5 ] , V_239 [ 6 ] ,
V_239 [ 7 ] , V_239 [ 8 ] , V_239 [ 9 ] , V_239 [ 10 ] ) ;
if ( ( V_239 [ 0 ] != V_241 ) ||
( V_239 [ 1 ] != 0x5f ) ||
( V_239 [ 2 ] != 0x01 ) ||
( V_239 [ 3 ] != 0x00 ) ||
( V_239 [ 4 ] != V_241 - 2 ) )
goto V_244;
V_240 = V_239 + V_241 ;
V_239 += 5 ;
while ( V_239 < V_240 ) {
T_1 V_245 ;
T_3 V_246 ;
V_246 = F_113 ( * ( ( T_3 * ) V_239 ) ) ;
V_239 += sizeof( T_3 ) ;
V_245 = * V_239 ;
V_239 ++ ;
switch ( V_246 ) {
case 0x0200 : {
T_2 V_247 ;
V_247 = F_114 ( * ( ( T_2 * ) V_239 ) ) ;
F_64 ( L_22 ,
V_247 ) ;
V_32 -> V_191 = V_247 ;
break;
}
default:
break;
}
V_239 += V_245 ;
}
} else {
F_79 ( L_23 , V_241 ) ;
}
goto V_248;
V_244:
F_51 ( L_24 ) ;
V_248:
F_52 ( V_1 ) ;
return true ;
}
static int F_115 ( struct V_237 * V_238 ,
const struct V_249 * V_250 )
{
struct V_251 * V_252 ;
struct V_31 * V_32 = 0 ;
int V_33 = - V_38 ;
V_252 = F_111 ( V_238 ) ;
V_32 = F_59 ( sizeof( * V_32 ) , V_145 ) ;
if ( V_32 == NULL ) {
F_116 ( & V_238 -> V_32 , L_25 ) ;
goto error;
}
F_117 ( & V_32 -> V_172 ) ;
V_32 -> V_146 = V_252 ;
V_32 -> V_253 = & V_252 -> V_32 ;
F_118 ( V_238 , V_32 ) ;
F_79 ( L_26 ,
V_252 -> V_254 , V_252 -> V_255 , V_252 -> V_256 ) ;
F_79 ( L_27 ,
V_252 -> V_257 . V_258 , V_252 -> V_257 . V_259 ,
V_252 -> V_257 . V_260 , V_32 ) ;
F_79 ( L_28 , V_167 ) ;
F_79 ( L_29 , V_141 ) ;
F_79 ( L_30 , V_204 ) ;
V_32 -> V_191 = 2048 * 1152 ;
if ( ! F_109 ( V_32 , V_238 ) ) {
F_51 ( L_31 ) ;
goto error;
}
if ( V_261 ) {
F_64 ( L_32
L_33 ,
V_32 -> V_191 , V_261 ) ;
V_32 -> V_191 = V_261 ;
}
if ( ! F_119 ( V_32 , V_262 , V_263 ) ) {
V_33 = - V_38 ;
F_51 ( L_34 ) ;
goto error;
}
F_58 ( & V_32 -> V_172 ) ;
F_120 ( & V_32 -> V_264 ,
V_265 ) ;
F_76 ( & V_32 -> V_264 , 0 ) ;
return 0 ;
error:
if ( V_32 ) {
F_73 ( & V_32 -> V_172 , F_61 ) ;
F_73 ( & V_32 -> V_172 , F_61 ) ;
}
return V_33 ;
}
static void V_265 ( struct V_176 * V_177 )
{
struct V_31 * V_32 = F_62 ( V_177 , struct V_31 ,
V_264 . V_177 ) ;
struct V_45 * V_40 ;
int V_33 ;
int V_110 ;
V_40 = F_121 ( 0 , V_32 -> V_253 ) ;
if ( ! V_40 ) {
V_33 = - V_38 ;
F_51 ( L_35 ) ;
goto error;
}
V_32 -> V_40 = V_40 ;
V_40 -> V_125 = V_32 ;
V_40 -> V_165 = V_32 -> V_165 ;
V_40 -> V_187 = & V_266 ;
V_33 = F_122 ( & V_40 -> V_164 , 256 , 0 ) ;
if ( V_33 < 0 ) {
F_51 ( L_36 , V_33 ) ;
goto error;
}
F_120 ( & V_32 -> V_186 ,
F_74 ) ;
F_123 ( & V_40 -> V_185 ) ;
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
for ( V_110 = 0 ; V_110 < F_125 ( V_267 ) ; V_110 ++ ) {
V_33 = F_126 ( V_40 -> V_32 , & V_267 [ V_110 ] ) ;
if ( V_33 ) {
F_64 ( L_39 , V_33 ) ;
}
}
V_33 = F_127 ( V_40 -> V_32 , & V_268 ) ;
if ( V_33 ) {
F_64 ( L_40 , V_33 ) ;
}
F_79 ( L_41
L_42 , V_40 -> V_175 ,
V_40 -> V_16 . V_24 , V_40 -> V_16 . V_27 ,
( ( V_32 -> V_103 ) ?
V_40 -> V_41 . V_42 * 2 : V_40 -> V_41 . V_42 ) >> 10 ) ;
return;
error:
F_67 ( V_32 ) ;
}
static void F_128 ( struct V_237 * V_238 )
{
struct V_31 * V_32 ;
struct V_45 * V_40 ;
int V_110 ;
V_32 = F_129 ( V_238 ) ;
V_40 = V_32 -> V_40 ;
F_79 ( L_43 ) ;
V_32 -> V_169 = true ;
F_106 ( & V_32 -> V_36 , 0 ) ;
F_130 ( V_32 ) ;
if ( V_40 ) {
for ( V_110 = 0 ; V_110 < F_125 ( V_267 ) ; V_110 ++ )
F_131 ( V_40 -> V_32 , & V_267 [ V_110 ] ) ;
F_132 ( V_40 -> V_32 , & V_268 ) ;
F_133 ( V_40 ) ;
}
F_118 ( V_238 , NULL ) ;
V_32 -> V_146 = NULL ;
V_32 -> V_253 = NULL ;
if ( V_32 -> V_171 == 0 )
F_76 ( & V_32 -> V_186 , 0 ) ;
F_73 ( & V_32 -> V_172 , F_61 ) ;
return;
}
static void F_34 ( struct V_35 * V_35 )
{
struct V_178 * V_179 = V_35 -> V_269 ;
struct V_31 * V_32 = V_179 -> V_32 ;
unsigned long V_202 ;
if ( V_35 -> V_270 ) {
if ( ! ( V_35 -> V_270 == - V_271 ||
V_35 -> V_270 == - V_272 ||
V_35 -> V_270 == - V_273 ) ) {
F_51 ( L_44 ,
V_274 , V_35 -> V_270 ) ;
F_106 ( & V_32 -> V_275 , 1 ) ;
}
}
V_35 -> V_102 = V_32 -> V_181 . V_50 ;
F_134 ( & V_32 -> V_181 . V_209 , V_202 ) ;
F_135 ( & V_179 -> V_276 , & V_32 -> V_181 . V_277 ) ;
V_32 -> V_181 . V_278 ++ ;
F_136 ( & V_32 -> V_181 . V_209 , V_202 ) ;
if ( V_141 )
F_76 ( & V_179 -> V_180 , 0 ) ;
else
F_66 ( & V_32 -> V_181 . V_182 ) ;
}
static void F_130 ( struct V_31 * V_32 )
{
int V_122 = V_32 -> V_181 . V_122 ;
struct V_136 * V_175 ;
struct V_178 * V_179 ;
struct V_35 * V_35 ;
int V_111 ;
unsigned long V_202 ;
F_18 ( L_45 ) ;
while ( V_122 -- ) {
V_111 = F_137 ( & V_32 -> V_181 . V_182 ) ;
if ( V_111 )
break;
F_134 ( & V_32 -> V_181 . V_209 , V_202 ) ;
V_175 = V_32 -> V_181 . V_277 . V_279 ;
F_138 ( V_175 ) ;
F_136 ( & V_32 -> V_181 . V_209 , V_202 ) ;
V_179 = F_139 ( V_175 , struct V_178 , V_276 ) ;
V_35 = V_179 -> V_35 ;
F_140 ( V_35 -> V_32 , V_32 -> V_181 . V_50 ,
V_35 -> V_39 , V_35 -> V_280 ) ;
F_141 ( V_35 ) ;
F_52 ( V_175 ) ;
}
V_32 -> V_181 . V_122 = 0 ;
}
static int F_119 ( struct V_31 * V_32 , int V_122 , T_10 V_50 )
{
int V_110 = 0 ;
struct V_35 * V_35 ;
struct V_178 * V_179 ;
char * V_1 ;
F_142 ( & V_32 -> V_181 . V_209 ) ;
V_32 -> V_181 . V_50 = V_50 ;
F_123 ( & V_32 -> V_181 . V_277 ) ;
while ( V_110 < V_122 ) {
V_179 = F_59 ( sizeof( struct V_178 ) , V_145 ) ;
if ( ! V_179 )
break;
V_179 -> V_32 = V_32 ;
F_120 ( & V_179 -> V_180 ,
F_65 ) ;
V_35 = F_143 ( 0 , V_145 ) ;
if ( ! V_35 ) {
F_52 ( V_179 ) ;
break;
}
V_179 -> V_35 = V_35 ;
V_1 = F_144 ( V_32 -> V_146 , V_263 , V_145 ,
& V_35 -> V_280 ) ;
if ( ! V_1 ) {
F_52 ( V_179 ) ;
F_141 ( V_35 ) ;
break;
}
F_145 ( V_35 , V_32 -> V_146 , F_146 ( V_32 -> V_146 , 1 ) ,
V_1 , V_50 , F_34 , V_179 ) ;
V_35 -> V_281 |= V_282 ;
F_135 ( & V_179 -> V_276 , & V_32 -> V_181 . V_277 ) ;
V_110 ++ ;
}
F_147 ( & V_32 -> V_181 . V_182 , V_110 ) ;
V_32 -> V_181 . V_122 = V_110 ;
V_32 -> V_181 . V_278 = V_110 ;
F_18 ( L_46 , V_110 , ( int ) V_50 ) ;
return V_110 ;
}
static struct V_35 * F_15 ( struct V_31 * V_32 )
{
int V_111 = 0 ;
struct V_136 * V_276 ;
struct V_178 * V_179 ;
struct V_35 * V_35 = NULL ;
unsigned long V_202 ;
V_111 = F_148 ( & V_32 -> V_181 . V_182 , V_283 ) ;
if ( V_111 ) {
F_106 ( & V_32 -> V_275 , 1 ) ;
F_64 ( L_47 ,
V_111 , V_32 -> V_181 . V_278 ) ;
goto error;
}
F_134 ( & V_32 -> V_181 . V_209 , V_202 ) ;
F_149 ( F_150 ( & V_32 -> V_181 . V_277 ) ) ;
V_276 = V_32 -> V_181 . V_277 . V_279 ;
F_138 ( V_276 ) ;
V_32 -> V_181 . V_278 -- ;
F_136 ( & V_32 -> V_181 . V_209 , V_202 ) ;
V_179 = F_139 ( V_276 , struct V_178 , V_276 ) ;
V_35 = V_179 -> V_35 ;
error:
return V_35 ;
}
static int F_16 ( struct V_31 * V_32 , struct V_35 * V_35 , T_10 V_105 )
{
int V_111 ;
F_149 ( V_105 > V_32 -> V_181 . V_50 ) ;
V_35 -> V_102 = V_105 ;
V_111 = F_151 ( V_35 , V_145 ) ;
if ( V_111 ) {
F_34 ( V_35 ) ;
F_106 ( & V_32 -> V_275 , 1 ) ;
F_51 ( L_48 , V_111 ) ;
}
return V_111 ;
}
