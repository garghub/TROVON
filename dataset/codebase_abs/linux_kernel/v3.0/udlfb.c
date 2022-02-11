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
static char * F_4 ( char * V_1 , bool V_4 )
{
if ( V_4 )
return F_1 ( V_1 , 0x1F , 0x00 ) ;
else
return F_1 ( V_1 , 0x1F , 0x07 ) ;
}
static char * F_5 ( char * V_1 , T_1 V_5 )
{
return F_1 ( V_1 , 0x00 , V_5 ) ;
}
static char * F_6 ( char * V_6 , T_2 V_7 )
{
V_6 = F_1 ( V_6 , 0x20 , V_7 >> 16 ) ;
V_6 = F_1 ( V_6 , 0x21 , V_7 >> 8 ) ;
return F_1 ( V_6 , 0x22 , V_7 ) ;
}
static char * F_7 ( char * V_6 , T_2 V_7 )
{
V_6 = F_1 ( V_6 , 0x26 , V_7 >> 16 ) ;
V_6 = F_1 ( V_6 , 0x27 , V_7 >> 8 ) ;
return F_1 ( V_6 , 0x28 , V_7 ) ;
}
static char * F_8 ( char * V_6 , T_1 V_2 , T_3 V_8 )
{
V_6 = F_1 ( V_6 , V_2 , V_8 >> 8 ) ;
return F_1 ( V_6 , V_2 + 1 , V_8 ) ;
}
static char * F_9 ( char * V_6 , T_1 V_2 , T_3 V_8 )
{
V_6 = F_1 ( V_6 , V_2 , V_8 ) ;
return F_1 ( V_6 , V_2 + 1 , V_8 >> 8 ) ;
}
static T_3 F_10 ( T_3 V_9 )
{
T_2 V_10 = 0xFFFF ;
while ( V_9 -- ) {
V_10 = ( ( V_10 << 1 ) |
( ( ( V_10 >> 15 ) ^ ( V_10 >> 4 ) ^ ( V_10 >> 2 ) ^ ( V_10 >> 1 ) ) & 1 ) )
& 0xFFFF ;
}
return ( T_3 ) V_10 ;
}
static char * F_11 ( char * V_6 , T_1 V_2 , T_3 V_8 )
{
return F_8 ( V_6 , V_2 , F_10 ( V_8 ) ) ;
}
static char * F_12 ( char * V_6 , struct V_11 * V_12 )
{
T_3 V_13 , V_14 ;
T_3 V_15 , V_16 ;
T_3 V_17 ;
V_13 = V_12 -> V_18 + V_12 -> V_19 ;
V_6 = F_11 ( V_6 , 0x01 , V_13 ) ;
V_15 = V_13 + V_12 -> V_20 ;
V_6 = F_11 ( V_6 , 0x03 , V_15 ) ;
V_14 = V_12 -> V_21 + V_12 -> V_22 ;
V_6 = F_11 ( V_6 , 0x05 , V_14 ) ;
V_16 = V_14 + V_12 -> V_23 ;
V_6 = F_11 ( V_6 , 0x07 , V_16 ) ;
V_6 = F_11 ( V_6 , 0x09 ,
V_15 + V_12 -> V_24 - 1 ) ;
V_6 = F_11 ( V_6 , 0x0B , 1 ) ;
V_6 = F_11 ( V_6 , 0x0D , V_12 -> V_19 + 1 ) ;
V_6 = F_8 ( V_6 , 0x0F , V_12 -> V_20 ) ;
V_17 = V_12 -> V_23 + V_12 -> V_21 + V_12 -> V_25 +
V_12 -> V_22 ;
V_6 = F_11 ( V_6 , 0x11 , V_17 ) ;
V_6 = F_11 ( V_6 , 0x13 , 0 ) ;
V_6 = F_11 ( V_6 , 0x15 , V_12 -> V_22 ) ;
V_6 = F_8 ( V_6 , 0x17 , V_12 -> V_23 ) ;
V_6 = F_9 ( V_6 , 0x1B ,
200 * 1000 * 1000 / V_12 -> V_26 ) ;
return V_6 ;
}
static int F_13 ( struct V_27 * V_28 ,
struct V_11 * V_12 )
{
char * V_1 ;
char * V_6 ;
int V_29 = 0 ;
int V_30 ;
struct V_31 * V_31 ;
if ( ! F_14 ( & V_28 -> V_32 ) )
return - V_33 ;
V_31 = F_15 ( V_28 ) ;
if ( ! V_31 )
return - V_34 ;
V_1 = ( char * ) V_31 -> V_35 ;
V_6 = F_2 ( V_1 ) ;
V_6 = F_5 ( V_6 , 0x00 ) ;
V_6 = F_6 ( V_6 , 0 ) ;
V_6 = F_7 ( V_6 , V_28 -> V_36 -> V_37 . V_38 ) ;
V_6 = F_12 ( V_6 , V_12 ) ;
V_6 = F_4 ( V_6 , true ) ;
V_6 = F_3 ( V_6 ) ;
V_30 = V_6 - V_1 ;
V_29 = F_16 ( V_28 , V_31 , V_30 ) ;
return V_29 ;
}
static int F_17 ( struct V_39 * V_36 , struct V_40 * V_41 )
{
unsigned long V_42 = V_41 -> V_43 ;
unsigned long V_44 = V_41 -> V_45 - V_41 -> V_43 ;
unsigned long V_46 = V_41 -> V_47 << V_48 ;
unsigned long V_49 , V_50 ;
if ( V_46 + V_44 > V_36 -> V_37 . V_38 )
return - V_51 ;
V_50 = ( unsigned long ) V_36 -> V_37 . V_52 + V_46 ;
F_18 ( L_1 ,
V_50 , V_44 ) ;
while ( V_44 > 0 ) {
V_49 = F_19 ( ( void * ) V_50 ) ;
if ( F_20 ( V_41 , V_42 , V_49 , V_53 , V_54 ) )
return - V_55 ;
V_42 += V_53 ;
V_50 += V_53 ;
if ( V_44 > V_53 )
V_44 -= V_53 ;
else
V_44 = 0 ;
}
V_41 -> V_56 |= V_57 ;
return 0 ;
}
static int F_21 ( const T_1 * V_58 , const T_1 * * V_59 , int * V_60 )
{
int V_61 , V_62 ;
const unsigned long * V_63 = ( const unsigned long * ) V_58 ;
const unsigned long * V_64 = ( const unsigned long * ) * V_59 ;
const int V_65 = * V_60 / sizeof( unsigned long ) ;
int V_66 = V_65 ;
int V_42 = V_65 ;
int V_67 = V_65 ;
F_22 ( ( void * ) V_64 ) ;
F_22 ( ( void * ) V_63 ) ;
for ( V_61 = 0 ; V_61 < V_65 ; V_61 ++ ) {
if ( V_63 [ V_61 ] != V_64 [ V_61 ] ) {
V_42 = V_61 ;
break;
}
}
for ( V_62 = V_65 - 1 ; V_62 > V_61 ; V_62 -- ) {
if ( V_63 [ V_62 ] != V_64 [ V_62 ] ) {
V_67 = V_62 + 1 ;
break;
}
}
V_66 = V_42 + ( V_65 - V_67 ) ;
* V_59 = ( T_1 * ) & V_64 [ V_42 ] ;
* V_60 = ( V_67 - V_42 ) * sizeof( unsigned long ) ;
return V_66 * sizeof( unsigned long ) ;
}
static void F_23 (
const T_4 * * V_68 ,
const T_4 * const V_69 ,
T_5 * V_70 ,
T_6 * * V_71 ,
const T_6 * const V_72 )
{
const T_4 * V_73 = * V_68 ;
T_5 V_74 = * V_70 ;
T_6 * V_75 = * V_71 ;
const int V_76 = 2 ;
while ( ( V_69 > V_73 ) &&
( V_72 - V_77 > V_75 ) ) {
T_6 * V_78 = 0 ;
T_6 * V_79 = 0 ;
const T_4 * V_80 = 0 ;
const T_4 * V_81 , * V_82 = 0 ;
F_24 ( ( void * ) V_75 ) ;
* V_75 ++ = 0xAF ;
* V_75 ++ = 0x6B ;
* V_75 ++ = ( T_6 ) ( ( V_74 >> 16 ) & 0xFF ) ;
* V_75 ++ = ( T_6 ) ( ( V_74 >> 8 ) & 0xFF ) ;
* V_75 ++ = ( T_6 ) ( ( V_74 ) & 0xFF ) ;
V_79 = V_75 ++ ;
V_81 = V_73 ;
V_78 = V_75 ++ ;
V_80 = V_73 ;
V_82 = V_73 + F_25 ( V_83 + 1 ,
F_25 ( ( int ) ( V_69 - V_73 ) ,
( int ) ( V_72 - V_75 ) / V_76 ) ) ;
F_26 ( ( void * ) V_73 , ( V_82 - V_73 ) * V_76 ) ;
while ( V_73 < V_82 ) {
const T_4 * const V_84 = V_73 ;
* ( T_4 * ) V_75 = F_27 ( V_73 ) ;
V_75 += 2 ;
V_73 ++ ;
if ( F_28 ( ( V_73 < V_82 ) &&
( * V_73 == * V_84 ) ) ) {
* V_78 = ( ( V_84 -
V_80 ) + 1 ) & 0xFF ;
while ( ( V_73 < V_82 )
&& ( * V_73 == * V_84 ) ) {
V_73 ++ ;
}
* V_75 ++ = ( ( V_73 - V_84 ) - 1 ) & 0xFF ;
V_80 = V_73 ;
V_78 = V_75 ++ ;
}
}
if ( V_73 > V_80 ) {
* V_78 = ( V_73 - V_80 ) & 0xFF ;
}
* V_79 = ( V_73 - V_81 ) & 0xFF ;
V_74 += ( V_73 - V_81 ) * V_76 ;
}
if ( V_72 <= V_77 + V_75 ) {
if ( V_72 > V_75 )
memset ( V_75 , 0xAF , V_72 - V_75 ) ;
V_75 = ( T_6 * ) V_72 ;
}
* V_71 = V_75 ;
* V_68 = V_73 ;
* V_70 = V_74 ;
return;
}
static int F_29 ( struct V_27 * V_28 , struct V_31 * * V_85 ,
const char * V_64 , char * * V_86 ,
T_2 V_87 , T_2 V_88 ,
int * V_89 , int * V_90 )
{
const T_1 * V_91 , * V_92 , * V_93 ;
T_2 V_74 = V_28 -> V_94 + V_87 ;
struct V_31 * V_31 = * V_85 ;
T_1 * V_75 = * V_86 ;
T_1 * V_95 = ( T_1 * ) V_31 -> V_35 + V_31 -> V_96 ;
V_91 = ( T_1 * ) ( V_64 + V_87 ) ;
V_93 = V_91 ;
V_92 = V_93 + V_88 ;
if ( V_28 -> V_97 ) {
int V_46 ;
const T_1 * V_98 = ( T_1 * ) ( V_28 -> V_97
+ V_87 ) ;
* V_89 += F_21 ( V_98 , & V_93 ,
& V_88 ) ;
V_46 = V_93 - V_91 ;
V_92 = V_93 + V_88 ;
V_74 += V_46 ;
V_98 += V_46 ;
V_91 += V_46 ;
memcpy ( ( char * ) V_98 , ( char * ) V_91 ,
V_88 ) ;
}
while ( V_93 < V_92 ) {
F_23 ( ( const T_4 * * ) & V_93 ,
( const T_4 * ) V_92 , & V_74 ,
( T_1 * * ) & V_75 , ( T_1 * ) V_95 ) ;
if ( V_75 >= V_95 ) {
int V_99 = V_75 - ( T_1 * ) V_31 -> V_35 ;
if ( F_16 ( V_28 , V_31 , V_99 ) )
return 1 ;
* V_90 += V_99 ;
V_31 = F_15 ( V_28 ) ;
if ( ! V_31 )
return 1 ;
* V_85 = V_31 ;
V_75 = V_31 -> V_35 ;
V_95 = & V_75 [ V_31 -> V_96 ] ;
}
}
* V_86 = V_75 ;
return 0 ;
}
int F_30 ( struct V_27 * V_28 , int V_100 , int V_101 ,
int V_65 , int V_102 , char * V_103 )
{
int V_104 , V_105 ;
char * V_75 ;
T_7 V_106 , V_107 ;
int V_108 = 0 ;
int V_109 = 0 ;
struct V_31 * V_31 ;
int V_110 ;
V_106 = F_31 () ;
V_110 = F_32 ( V_100 , sizeof( unsigned long ) ) ;
V_65 = F_33 ( V_65 + ( V_100 - V_110 ) , sizeof( unsigned long ) ) ;
V_100 = V_110 ;
if ( ( V_65 <= 0 ) ||
( V_100 + V_65 > V_28 -> V_36 -> V_12 . V_20 ) ||
( V_101 + V_102 > V_28 -> V_36 -> V_12 . V_23 ) )
return - V_51 ;
if ( ! F_14 ( & V_28 -> V_32 ) )
return 0 ;
V_31 = F_15 ( V_28 ) ;
if ( ! V_31 )
return 0 ;
V_75 = V_31 -> V_35 ;
for ( V_104 = V_101 ; V_104 < V_101 + V_102 ; V_104 ++ ) {
const int V_111 = V_28 -> V_36 -> V_37 . V_112 * V_104 ;
const int V_87 = V_111 + ( V_100 * V_113 ) ;
if ( F_29 ( V_28 , & V_31 ,
( char * ) V_28 -> V_36 -> V_37 . V_52 ,
& V_75 , V_87 , V_65 * V_113 ,
& V_109 , & V_108 ) )
goto error;
}
if ( V_75 > ( char * ) V_31 -> V_35 ) {
int V_99 = V_75 - ( char * ) V_31 -> V_35 ;
V_105 = F_16 ( V_28 , V_31 , V_99 ) ;
V_108 += V_99 ;
} else
F_34 ( V_31 ) ;
error:
F_35 ( V_108 , & V_28 -> V_108 ) ;
F_35 ( V_109 , & V_28 -> V_109 ) ;
F_35 ( V_65 * V_102 * 2 , & V_28 -> V_114 ) ;
V_107 = F_31 () ;
F_35 ( ( ( unsigned int ) ( ( V_107 - V_106 )
>> 10 ) ) ,
& V_28 -> V_115 ) ;
return 0 ;
}
static T_8 F_36 ( struct V_39 * V_36 , const char T_9 * V_1 ,
T_10 V_116 , T_11 * V_117 )
{
T_8 V_118 ;
struct V_27 * V_28 = V_36 -> V_119 ;
T_2 V_46 = ( T_2 ) * V_117 ;
V_118 = F_37 ( V_36 , V_1 , V_116 , V_117 ) ;
if ( V_118 > 0 ) {
int V_42 = F_38 ( ( int ) ( V_46 / V_36 -> V_37 . V_112 ) - 1 , 0 ) ;
int V_120 = F_25 ( ( T_2 ) ( ( V_118 / V_36 -> V_37 . V_112 ) + 1 ) ,
( T_2 ) V_36 -> V_12 . V_23 ) ;
F_30 ( V_28 , 0 , V_42 , V_36 -> V_12 . V_20 ,
V_120 , V_36 -> V_121 ) ;
}
return V_118 ;
}
static void F_39 ( struct V_39 * V_36 ,
const struct V_122 * V_123 )
{
struct V_27 * V_28 = V_36 -> V_119 ;
F_40 ( V_36 , V_123 ) ;
F_30 ( V_28 , V_123 -> V_124 , V_123 -> V_125 ,
V_123 -> V_65 , V_123 -> V_102 , V_36 -> V_121 ) ;
}
static void F_41 ( struct V_39 * V_36 ,
const struct V_126 * V_127 )
{
struct V_27 * V_28 = V_36 -> V_119 ;
F_42 ( V_36 , V_127 ) ;
F_30 ( V_28 , V_127 -> V_124 , V_127 -> V_125 ,
V_127 -> V_65 , V_127 -> V_102 , V_36 -> V_121 ) ;
}
static void F_43 ( struct V_39 * V_36 ,
const struct V_128 * V_129 )
{
struct V_27 * V_28 = V_36 -> V_119 ;
F_44 ( V_36 , V_129 ) ;
F_30 ( V_28 , V_129 -> V_124 , V_129 -> V_125 , V_129 -> V_65 ,
V_129 -> V_102 , V_36 -> V_121 ) ;
}
static void F_45 ( struct V_39 * V_36 ,
struct V_130 * V_131 )
{
struct V_49 * V_132 ;
struct V_133 * V_134 = V_36 -> V_134 ;
struct V_27 * V_28 = V_36 -> V_119 ;
struct V_31 * V_31 ;
char * V_75 ;
T_7 V_106 , V_107 ;
int V_108 = 0 ;
int V_109 = 0 ;
int V_114 = 0 ;
if ( ! V_135 )
return;
if ( ! F_14 ( & V_28 -> V_32 ) )
return;
V_106 = F_31 () ;
V_31 = F_15 ( V_28 ) ;
if ( ! V_31 )
return;
V_75 = V_31 -> V_35 ;
F_46 (cur, &fbdefio->pagelist, lru) {
if ( F_29 ( V_28 , & V_31 , ( char * ) V_36 -> V_37 . V_52 ,
& V_75 , V_132 -> V_136 << V_48 ,
V_53 , & V_109 , & V_108 ) )
goto error;
V_114 += V_53 ;
}
if ( V_75 > ( char * ) V_31 -> V_35 ) {
int V_99 = V_75 - ( char * ) V_31 -> V_35 ;
F_16 ( V_28 , V_31 , V_99 ) ;
V_108 += V_99 ;
} else
F_34 ( V_31 ) ;
error:
F_35 ( V_108 , & V_28 -> V_108 ) ;
F_35 ( V_109 , & V_28 -> V_109 ) ;
F_35 ( V_114 , & V_28 -> V_114 ) ;
V_107 = F_31 () ;
F_35 ( ( ( unsigned int ) ( ( V_107 - V_106 )
>> 10 ) ) ,
& V_28 -> V_115 ) ;
}
static int F_47 ( struct V_27 * V_28 , char * V_137 , int V_99 )
{
int V_104 ;
int V_105 ;
char * V_138 ;
V_138 = F_48 ( 2 , V_139 ) ;
if ( ! V_138 )
return 0 ;
for ( V_104 = 0 ; V_104 < V_99 ; V_104 ++ ) {
V_105 = F_49 ( V_28 -> V_140 ,
F_50 ( V_28 -> V_140 , 0 ) , ( 0x02 ) ,
( 0x80 | ( 0x02 << 5 ) ) , V_104 << 8 , 0xA1 , V_138 , 2 ,
V_141 ) ;
if ( V_105 < 1 ) {
F_51 ( L_2 , V_104 , V_105 ) ;
V_104 -- ;
break;
}
V_137 [ V_104 ] = V_138 [ 1 ] ;
}
F_52 ( V_138 ) ;
return V_104 ;
}
static int F_53 ( struct V_39 * V_36 , unsigned int V_75 ,
unsigned long V_142 )
{
struct V_27 * V_28 = V_36 -> V_119 ;
struct V_143 * V_123 = NULL ;
if ( ! F_14 ( & V_28 -> V_32 ) )
return 0 ;
if ( V_75 == V_144 ) {
char * V_137 = ( char * ) V_142 ;
if ( F_54 ( V_137 , V_28 -> V_137 , V_28 -> V_145 ) )
return - V_146 ;
return 0 ;
}
if ( V_75 == V_147 ) {
if ( V_36 -> V_134 )
V_36 -> V_134 -> V_148 = V_149 ;
V_123 = (struct V_143 * ) V_142 ;
if ( V_123 -> V_100 < 0 )
V_123 -> V_100 = 0 ;
if ( V_123 -> V_100 > V_36 -> V_12 . V_20 )
V_123 -> V_100 = V_36 -> V_12 . V_20 ;
if ( V_123 -> V_101 < 0 )
V_123 -> V_101 = 0 ;
if ( V_123 -> V_101 > V_36 -> V_12 . V_23 )
V_123 -> V_101 = V_36 -> V_12 . V_23 ;
F_30 ( V_28 , V_123 -> V_100 , V_123 -> V_101 , V_123 -> V_150 , V_123 -> V_151 ,
V_36 -> V_121 ) ;
}
return 0 ;
}
static int
F_55 ( unsigned V_152 , unsigned V_153 , unsigned V_154 ,
unsigned V_155 , unsigned V_156 , struct V_39 * V_36 )
{
int V_157 = 0 ;
if ( V_152 >= V_36 -> V_158 . V_99 )
return 1 ;
if ( V_152 < 16 ) {
if ( V_36 -> V_12 . V_153 . V_46 == 10 ) {
( ( T_2 * ) ( V_36 -> V_159 ) ) [ V_152 ] =
( ( V_153 & 0xf800 ) >> 1 ) |
( ( V_154 & 0xf800 ) >> 6 ) | ( ( V_155 & 0xf800 ) >> 11 ) ;
} else {
( ( T_2 * ) ( V_36 -> V_159 ) ) [ V_152 ] =
( ( V_153 & 0xf800 ) ) |
( ( V_154 & 0xfc00 ) >> 5 ) | ( ( V_155 & 0xf800 ) >> 11 ) ;
}
}
return V_157 ;
}
static int F_56 ( struct V_39 * V_36 , int V_160 )
{
struct V_27 * V_28 = V_36 -> V_119 ;
if ( ( V_160 == 0 ) & ( ! V_161 ) )
return - V_162 ;
if ( V_28 -> V_163 )
return - V_164 ;
V_28 -> V_165 ++ ;
F_57 ( & V_28 -> V_166 ) ;
if ( V_135 && ( V_36 -> V_134 == NULL ) ) {
struct V_133 * V_134 ;
V_134 = F_48 ( sizeof( struct V_133 ) , V_139 ) ;
if ( V_134 ) {
V_134 -> V_148 = V_167 ;
V_134 -> V_168 = F_45 ;
}
V_36 -> V_134 = V_134 ;
F_58 ( V_36 ) ;
}
F_18 ( L_3 ,
V_36 -> V_169 , V_160 , V_36 , V_28 -> V_165 ) ;
return 0 ;
}
static void F_59 ( struct V_166 * V_166 )
{
struct V_27 * V_28 = F_60 ( V_166 , struct V_27 , V_166 ) ;
if ( V_28 -> V_170 . V_116 > 0 )
F_61 ( V_28 ) ;
if ( V_28 -> V_97 )
F_62 ( V_28 -> V_97 ) ;
F_52 ( V_28 -> V_137 ) ;
F_63 ( L_4 , V_28 ) ;
F_52 ( V_28 ) ;
}
static void F_64 ( struct V_171 * V_172 )
{
struct V_173 * V_174 = F_60 ( V_172 , struct V_173 ,
V_175 . V_172 ) ;
F_65 ( & V_174 -> V_28 -> V_170 . V_176 ) ;
}
static void F_66 ( struct V_171 * V_172 )
{
struct V_27 * V_28 = F_60 ( V_172 , struct V_27 ,
V_177 . V_172 ) ;
struct V_39 * V_36 = V_28 -> V_36 ;
int V_169 = V_36 -> V_169 ;
F_67 ( V_36 ) ;
if ( V_36 -> V_158 . V_99 != 0 )
F_68 ( & V_36 -> V_158 ) ;
if ( V_36 -> V_178 . V_179 )
F_69 ( V_36 -> V_178 . V_179 ) ;
if ( V_36 -> V_121 )
F_62 ( V_36 -> V_121 ) ;
F_70 ( & V_36 -> V_180 ) ;
V_28 -> V_36 = 0 ;
F_71 ( V_36 ) ;
F_63 ( L_5 , V_169 ) ;
F_72 ( & V_28 -> V_166 , F_59 ) ;
}
static int F_73 ( struct V_39 * V_36 , int V_160 )
{
struct V_27 * V_28 = V_36 -> V_119 ;
V_28 -> V_165 -- ;
if ( V_28 -> V_163 && ( V_28 -> V_165 == 0 ) )
F_74 ( & V_28 -> V_177 , V_141 ) ;
if ( ( V_28 -> V_165 == 0 ) && ( V_36 -> V_134 ) ) {
F_75 ( V_36 ) ;
F_52 ( V_36 -> V_134 ) ;
V_36 -> V_134 = NULL ;
V_36 -> V_181 -> V_182 = F_17 ;
}
F_63 ( L_6 ,
V_36 -> V_169 , V_160 , V_28 -> V_165 ) ;
F_72 ( & V_28 -> V_166 , F_59 ) ;
return 0 ;
}
static int F_76 ( struct V_183 * V_184 ,
struct V_39 * V_36 )
{
struct V_27 * V_28 = V_36 -> V_119 ;
if ( V_184 -> V_20 * V_184 -> V_23 > V_28 -> V_185 ) {
F_63 ( L_7 ,
V_184 -> V_20 , V_184 -> V_23 ) ;
return 0 ;
}
F_77 ( L_8 , V_184 -> V_20 , V_184 -> V_23 ) ;
return 1 ;
}
static void F_78 ( struct V_11 * V_12 )
{
const struct V_186 V_153 = { 11 , 5 , 0 } ;
const struct V_186 V_154 = { 5 , 6 , 0 } ;
const struct V_186 V_155 = { 0 , 5 , 0 } ;
V_12 -> V_187 = 16 ;
V_12 -> V_153 = V_153 ;
V_12 -> V_154 = V_154 ;
V_12 -> V_155 = V_155 ;
}
static int F_79 ( struct V_11 * V_12 ,
struct V_39 * V_36 )
{
struct V_183 V_184 ;
if ( ( V_12 -> V_20 * V_12 -> V_23 * 2 ) > V_36 -> V_37 . V_38 )
return - V_51 ;
F_78 ( V_12 ) ;
F_80 ( & V_184 , V_12 ) ;
if ( ! F_76 ( & V_184 , V_36 ) )
return - V_51 ;
return 0 ;
}
static int F_81 ( struct V_39 * V_36 )
{
struct V_27 * V_28 = V_36 -> V_119 ;
int V_118 ;
T_3 * V_188 ;
int V_104 ;
F_18 ( L_9 , V_36 -> V_12 . V_20 , V_36 -> V_12 . V_23 ) ;
V_118 = F_13 ( V_28 , & V_36 -> V_12 ) ;
if ( ( V_118 == 0 ) && ( V_28 -> V_165 == 0 ) ) {
V_188 = ( T_3 * ) V_36 -> V_121 ;
for ( V_104 = 0 ; V_104 < V_36 -> V_37 . V_38 / 2 ; V_104 ++ )
V_188 [ V_104 ] = 0x37e6 ;
F_30 ( V_28 , 0 , 0 , V_36 -> V_12 . V_20 , V_36 -> V_12 . V_23 ,
V_36 -> V_121 ) ;
}
return V_118 ;
}
static int F_82 ( int V_189 , struct V_39 * V_36 )
{
struct V_27 * V_28 = V_36 -> V_119 ;
if ( V_189 != V_190 ) {
char * V_191 ;
struct V_31 * V_31 ;
V_31 = F_15 ( V_28 ) ;
if ( ! V_31 )
return 0 ;
V_191 = ( char * ) V_31 -> V_35 ;
V_191 = F_2 ( V_191 ) ;
V_191 = F_4 ( V_191 , false ) ;
V_191 = F_3 ( V_191 ) ;
F_16 ( V_28 , V_31 , V_191 -
( char * ) V_31 -> V_35 ) ;
} else {
F_13 ( V_28 , & V_36 -> V_12 ) ;
}
return 0 ;
}
static int F_83 ( struct V_27 * V_28 , struct V_39 * V_36 )
{
int V_29 = - V_34 ;
int V_192 = V_36 -> V_37 . V_38 ;
int V_193 ;
unsigned char * V_194 = V_36 -> V_121 ;
unsigned char * V_195 ;
unsigned char * V_196 ;
F_63 ( L_10 ) ;
V_193 = V_36 -> V_37 . V_112 * V_36 -> V_12 . V_23 ;
if ( F_84 ( V_193 ) > V_192 ) {
V_195 = F_85 ( V_193 ) ;
if ( ! V_195 ) {
F_51 ( L_11 ) ;
goto error;
}
if ( V_36 -> V_121 ) {
memcpy ( V_195 , V_194 , V_192 ) ;
F_62 ( V_36 -> V_121 ) ;
}
V_36 -> V_121 = V_195 ;
V_36 -> V_37 . V_38 = F_84 ( V_193 ) ;
V_36 -> V_37 . V_52 = ( unsigned long ) V_195 ;
V_36 -> V_197 = V_198 ;
V_196 = F_86 ( V_193 ) ;
if ( ! V_196 )
F_77 ( L_12 ) ;
else {
if ( V_28 -> V_97 )
F_62 ( V_28 -> V_97 ) ;
V_28 -> V_97 = V_196 ;
}
}
V_29 = 0 ;
error:
return V_29 ;
}
static int F_87 ( struct V_27 * V_28 ,
struct V_39 * V_36 ,
char * V_199 , T_10 V_200 )
{
int V_104 ;
const struct V_183 * V_201 = NULL ;
int V_118 = 0 ;
char * V_137 ;
int V_202 = 3 ;
if ( V_36 -> V_28 )
F_88 ( & V_36 -> V_203 ) ;
V_137 = F_48 ( V_204 , V_139 ) ;
if ( ! V_137 ) {
V_118 = - V_34 ;
goto error;
}
F_70 ( & V_36 -> V_180 ) ;
memset ( & V_36 -> V_178 , 0 , sizeof( V_36 -> V_178 ) ) ;
while ( V_202 -- ) {
V_104 = F_47 ( V_28 , V_137 , V_204 ) ;
if ( V_104 >= V_204 )
F_89 ( V_137 , & V_36 -> V_178 ) ;
if ( V_36 -> V_178 . V_205 > 0 ) {
V_28 -> V_137 = V_137 ;
V_28 -> V_145 = V_104 ;
break;
}
}
if ( V_36 -> V_178 . V_205 == 0 ) {
F_51 ( L_13 ) ;
if ( V_28 -> V_137 ) {
F_89 ( V_28 -> V_137 , & V_36 -> V_178 ) ;
if ( V_36 -> V_178 . V_205 > 0 )
F_51 ( L_14 ) ;
}
}
if ( V_36 -> V_178 . V_205 == 0 ) {
if ( V_200 >= V_204 ) {
F_89 ( V_199 , & V_36 -> V_178 ) ;
if ( V_36 -> V_178 . V_205 > 0 ) {
memcpy ( V_137 , V_199 , V_200 ) ;
V_28 -> V_137 = V_137 ;
V_28 -> V_145 = V_200 ;
F_51 ( L_15 ) ;
}
}
}
if ( V_36 -> V_178 . V_205 > 0 ) {
for ( V_104 = 0 ; V_104 < V_36 -> V_178 . V_205 ; V_104 ++ ) {
if ( F_76 ( & V_36 -> V_178 . V_179 [ V_104 ] , V_36 ) )
F_90 ( & V_36 -> V_178 . V_179 [ V_104 ] ,
& V_36 -> V_180 ) ;
else {
if ( V_104 == 0 )
V_36 -> V_178 . V_206
&= ~ V_207 ;
}
}
V_201 = F_91 ( & V_36 -> V_178 ,
& V_36 -> V_180 ) ;
}
if ( V_201 == NULL ) {
struct V_183 V_208 = { 0 } ;
for ( V_104 = 0 ; V_104 < V_209 ; V_104 ++ ) {
if ( F_76 ( (struct V_183 * )
& V_210 [ V_104 ] , V_36 ) )
F_90 ( & V_210 [ V_104 ] ,
& V_36 -> V_180 ) ;
}
V_208 . V_20 = 800 ;
V_208 . V_23 = 600 ;
V_208 . V_211 = 60 ;
V_201 = F_92 ( & V_208 ,
& V_36 -> V_180 ) ;
}
if ( ( V_201 != NULL ) && ( V_28 -> V_165 == 0 ) ) {
F_93 ( & V_36 -> V_12 , V_201 ) ;
F_78 ( & V_36 -> V_12 ) ;
memcpy ( & V_36 -> V_37 , & V_212 , sizeof( V_212 ) ) ;
V_36 -> V_37 . V_112 = V_36 -> V_12 . V_20 *
( V_36 -> V_12 . V_187 / 8 ) ;
V_118 = F_83 ( V_28 , V_36 ) ;
} else
V_118 = - V_51 ;
error:
if ( V_137 && ( V_28 -> V_137 != V_137 ) )
F_52 ( V_137 ) ;
if ( V_36 -> V_28 )
F_94 ( & V_36 -> V_203 ) ;
return V_118 ;
}
static T_8 F_95 ( struct V_213 * V_214 ,
struct V_215 * V_216 , char * V_1 ) {
struct V_39 * V_39 = F_96 ( V_214 ) ;
struct V_27 * V_28 = V_39 -> V_119 ;
return snprintf ( V_1 , V_53 , L_16 ,
F_14 ( & V_28 -> V_114 ) ) ;
}
static T_8 F_97 ( struct V_213 * V_214 ,
struct V_215 * V_216 , char * V_1 ) {
struct V_39 * V_39 = F_96 ( V_214 ) ;
struct V_27 * V_28 = V_39 -> V_119 ;
return snprintf ( V_1 , V_53 , L_16 ,
F_14 ( & V_28 -> V_109 ) ) ;
}
static T_8 F_98 ( struct V_213 * V_214 ,
struct V_215 * V_216 , char * V_1 ) {
struct V_39 * V_39 = F_96 ( V_214 ) ;
struct V_27 * V_28 = V_39 -> V_119 ;
return snprintf ( V_1 , V_53 , L_16 ,
F_14 ( & V_28 -> V_108 ) ) ;
}
static T_8 F_99 ( struct V_213 * V_214 ,
struct V_215 * V_216 , char * V_1 ) {
struct V_39 * V_39 = F_96 ( V_214 ) ;
struct V_27 * V_28 = V_39 -> V_119 ;
return snprintf ( V_1 , V_53 , L_16 ,
F_14 ( & V_28 -> V_115 ) ) ;
}
static T_8 F_100 (
struct V_217 * V_218 ,
struct V_219 * V_220 , struct V_221 * V_216 ,
char * V_1 , T_11 V_222 , T_10 V_116 ) {
struct V_213 * V_214 = F_60 ( V_220 , struct V_213 , V_220 ) ;
struct V_39 * V_39 = F_96 ( V_214 ) ;
struct V_27 * V_28 = V_39 -> V_119 ;
if ( V_28 -> V_137 == NULL )
return 0 ;
if ( ( V_222 >= V_28 -> V_145 ) || ( V_116 > V_28 -> V_145 ) )
return 0 ;
if ( V_222 + V_116 > V_28 -> V_145 )
V_116 = V_28 -> V_145 - V_222 ;
F_77 ( L_17 ,
V_28 -> V_137 , V_1 , ( int ) V_116 ) ;
memcpy ( V_1 , V_28 -> V_137 , V_116 ) ;
return V_116 ;
}
static T_8 F_101 (
struct V_217 * V_218 ,
struct V_219 * V_220 , struct V_221 * V_216 ,
char * V_223 , T_11 V_224 , T_10 V_225 ) {
struct V_213 * V_214 = F_60 ( V_220 , struct V_213 , V_220 ) ;
struct V_39 * V_39 = F_96 ( V_214 ) ;
struct V_27 * V_28 = V_39 -> V_119 ;
if ( ( V_225 != V_204 ) || ( V_224 != 0 ) )
return 0 ;
F_87 ( V_28 , V_39 , V_223 , V_225 ) ;
if ( V_28 -> V_137 && ( memcmp ( V_223 , V_28 -> V_137 , V_225 ) == 0 ) ) {
F_77 ( L_18 ) ;
F_81 ( V_39 ) ;
return V_225 ;
} else
return 0 ;
}
static T_8 F_102 ( struct V_213 * V_214 ,
struct V_215 * V_226 ,
const char * V_1 , T_10 V_116 )
{
struct V_39 * V_39 = F_96 ( V_214 ) ;
struct V_27 * V_28 = V_39 -> V_119 ;
F_103 ( & V_28 -> V_114 , 0 ) ;
F_103 ( & V_28 -> V_109 , 0 ) ;
F_103 ( & V_28 -> V_108 , 0 ) ;
F_103 ( & V_28 -> V_115 , 0 ) ;
return V_116 ;
}
static int F_104 ( struct V_27 * V_28 )
{
int V_105 ;
T_1 V_227 [] = { 0x57 , 0xCD , 0xDC , 0xA7 ,
0x1C , 0x88 , 0x5E , 0x15 ,
0x60 , 0xFE , 0xC6 , 0x97 ,
0x16 , 0x3D , 0x47 , 0xF2 } ;
V_105 = F_49 ( V_28 -> V_140 , F_105 ( V_28 -> V_140 , 0 ) ,
V_228 ,
( V_229 | V_230 ) , 0 , 0 ,
V_227 , sizeof( V_227 ) , V_231 ) ;
return V_105 ;
}
static int F_106 ( struct V_27 * V_28 ,
struct V_232 * V_233 )
{
char * V_234 ;
char * V_1 ;
char * V_235 ;
T_1 V_236 = 0 ;
V_1 = F_107 ( V_237 , V_139 ) ;
if ( ! V_1 )
return false ;
V_234 = V_1 ;
V_236 = F_108 ( V_233 , 0x5f ,
0 , V_234 , V_237 ) ;
if ( V_236 > 5 ) {
F_77 ( L_19 \
L_20 ,
V_236 , V_234 [ 0 ] ,
V_234 [ 1 ] , V_234 [ 2 ] , V_234 [ 3 ] , V_234 [ 4 ] , V_234 [ 5 ] , V_234 [ 6 ] ,
V_234 [ 7 ] , V_234 [ 8 ] , V_234 [ 9 ] , V_234 [ 10 ] ) ;
if ( ( V_234 [ 0 ] != V_236 ) ||
( V_234 [ 1 ] != 0x5f ) ||
( V_234 [ 2 ] != 0x01 ) ||
( V_234 [ 3 ] != 0x00 ) ||
( V_234 [ 4 ] != V_236 - 2 ) )
goto V_238;
V_235 = V_234 + V_236 ;
V_234 += 5 ;
while ( V_234 < V_235 ) {
T_1 V_239 ;
T_3 V_240 ;
V_240 = * ( ( T_3 * ) V_234 ) ;
V_234 += sizeof( T_3 ) ;
V_239 = * V_234 ;
V_234 ++ ;
switch ( V_240 ) {
case 0x0200 : {
T_2 V_241 ;
V_241 = F_109 ( * ( ( T_2 * ) V_234 ) ) ;
F_63 ( L_21 ,
V_241 ) ;
V_28 -> V_185 = V_241 ;
break;
}
default:
break;
}
V_234 += V_239 ;
}
}
goto V_242;
V_238:
F_51 ( L_22 ) ;
V_242:
F_52 ( V_1 ) ;
return true ;
}
static int F_110 ( struct V_243 * V_244 ,
const struct V_245 * V_246 )
{
struct V_232 * V_233 ;
struct V_27 * V_28 = 0 ;
struct V_39 * V_36 = 0 ;
int V_29 = - V_34 ;
int V_104 ;
V_233 = F_111 ( V_244 ) ;
V_28 = F_107 ( sizeof( * V_28 ) , V_139 ) ;
if ( V_28 == NULL ) {
V_157 ( L_23 ) ;
goto error;
}
F_112 ( & V_28 -> V_166 ) ;
F_57 ( & V_28 -> V_166 ) ;
V_28 -> V_140 = V_233 ;
V_28 -> V_247 = & V_233 -> V_28 ;
F_113 ( V_244 , V_28 ) ;
F_77 ( L_24 ,
V_233 -> V_248 , V_233 -> V_249 , V_233 -> V_250 ) ;
F_77 ( L_25 ,
V_233 -> V_251 . V_252 , V_233 -> V_251 . V_253 ,
V_233 -> V_251 . V_254 , V_28 ) ;
F_77 ( L_26 , V_161 ) ;
F_77 ( L_27 , V_135 ) ;
V_28 -> V_185 = 2048 * 1152 ;
if ( ! F_106 ( V_28 , V_233 ) ) {
F_51 ( L_28 ) ;
goto error;
}
if ( ! F_114 ( V_28 , V_255 , V_256 ) ) {
V_29 = - V_34 ;
F_51 ( L_29 ) ;
goto error;
}
V_36 = F_115 ( 0 , & V_233 -> V_28 ) ;
if ( ! V_36 ) {
V_29 = - V_34 ;
F_51 ( L_30 ) ;
goto error;
}
V_28 -> V_36 = V_36 ;
V_36 -> V_119 = V_28 ;
V_36 -> V_159 = V_28 -> V_159 ;
V_36 -> V_181 = & V_257 ;
V_29 = F_116 ( & V_36 -> V_158 , 256 , 0 ) ;
if ( V_29 < 0 ) {
F_51 ( L_31 , V_29 ) ;
goto error;
}
F_117 ( & V_28 -> V_177 ,
F_66 ) ;
F_118 ( & V_36 -> V_180 ) ;
V_29 = F_87 ( V_28 , V_36 , NULL , 0 ) ;
if ( V_29 != 0 ) {
F_51 ( L_32 ) ;
goto error;
}
F_103 ( & V_28 -> V_32 , 1 ) ;
F_104 ( V_28 ) ;
F_79 ( & V_36 -> V_12 , V_36 ) ;
F_81 ( V_36 ) ;
V_29 = F_119 ( V_36 ) ;
if ( V_29 < 0 ) {
F_51 ( L_33 , V_29 ) ;
goto error;
}
for ( V_104 = 0 ; V_104 < F_120 ( V_258 ) ; V_104 ++ ) {
V_29 = F_121 ( V_36 -> V_28 , & V_258 [ V_104 ] ) ;
if ( V_29 ) {
F_51 ( L_34 , V_29 ) ;
goto V_259;
}
}
V_29 = F_122 ( V_36 -> V_28 , & V_260 ) ;
if ( V_29 ) {
F_51 ( L_35 , V_29 ) ;
goto V_259;
}
F_77 ( L_36
L_37 , V_36 -> V_169 ,
V_36 -> V_12 . V_20 , V_36 -> V_12 . V_23 ,
( ( V_28 -> V_97 ) ?
V_36 -> V_37 . V_38 * 2 : V_36 -> V_37 . V_38 ) >> 10 ) ;
return 0 ;
V_259:
for ( V_104 -= 1 ; V_104 >= 0 ; V_104 -- )
F_123 ( V_36 -> V_28 , & V_258 [ V_104 ] ) ;
error:
if ( V_28 ) {
if ( V_36 ) {
if ( V_36 -> V_158 . V_99 != 0 )
F_68 ( & V_36 -> V_158 ) ;
if ( V_36 -> V_178 . V_179 )
F_69 ( V_36 -> V_178 . V_179 ) ;
if ( V_36 -> V_121 )
F_62 ( V_36 -> V_121 ) ;
F_70 ( & V_36 -> V_180 ) ;
F_71 ( V_36 ) ;
}
if ( V_28 -> V_97 )
F_62 ( V_28 -> V_97 ) ;
F_72 ( & V_28 -> V_166 , F_59 ) ;
F_72 ( & V_28 -> V_166 , F_59 ) ;
}
return V_29 ;
}
static void F_124 ( struct V_243 * V_244 )
{
struct V_27 * V_28 ;
struct V_39 * V_36 ;
int V_104 ;
V_28 = F_125 ( V_244 ) ;
V_36 = V_28 -> V_36 ;
F_77 ( L_38 ) ;
V_28 -> V_163 = true ;
F_103 ( & V_28 -> V_32 , 0 ) ;
for ( V_104 = 0 ; V_104 < F_120 ( V_258 ) ; V_104 ++ )
F_123 ( V_36 -> V_28 , & V_258 [ V_104 ] ) ;
F_126 ( V_36 -> V_28 , & V_260 ) ;
F_113 ( V_244 , NULL ) ;
if ( V_28 -> V_165 == 0 )
F_74 ( & V_28 -> V_177 , 0 ) ;
F_72 ( & V_28 -> V_166 , F_59 ) ;
return;
}
static int T_12 F_127 ( void )
{
int V_261 ;
V_261 = F_128 ( & V_262 ) ;
if ( V_261 )
V_157 ( L_39 , V_261 ) ;
return V_261 ;
}
static void T_13 F_129 ( void )
{
F_130 ( & V_262 ) ;
}
static void F_34 ( struct V_31 * V_31 )
{
struct V_173 * V_174 = V_31 -> V_263 ;
struct V_27 * V_28 = V_174 -> V_28 ;
unsigned long V_197 ;
if ( V_31 -> V_264 ) {
if ( ! ( V_31 -> V_264 == - V_265 ||
V_31 -> V_264 == - V_266 ||
V_31 -> V_264 == - V_267 ) ) {
F_51 ( L_40 ,
V_268 , V_31 -> V_264 ) ;
F_103 ( & V_28 -> V_269 , 1 ) ;
}
}
V_31 -> V_96 = V_28 -> V_170 . V_44 ;
F_131 ( & V_28 -> V_170 . V_203 , V_197 ) ;
F_132 ( & V_174 -> V_270 , & V_28 -> V_170 . V_271 ) ;
V_28 -> V_170 . V_272 ++ ;
F_133 ( & V_28 -> V_170 . V_203 , V_197 ) ;
if ( V_135 )
F_74 ( & V_174 -> V_175 , 0 ) ;
else
F_65 ( & V_28 -> V_170 . V_176 ) ;
}
static void F_61 ( struct V_27 * V_28 )
{
int V_116 = V_28 -> V_170 . V_116 ;
struct V_130 * V_169 ;
struct V_173 * V_174 ;
struct V_31 * V_31 ;
int V_105 ;
unsigned long V_197 ;
F_18 ( L_41 ) ;
while ( V_116 -- ) {
V_105 = F_134 ( & V_28 -> V_170 . V_176 ) ;
if ( V_105 )
break;
F_131 ( & V_28 -> V_170 . V_203 , V_197 ) ;
V_169 = V_28 -> V_170 . V_271 . V_273 ;
F_135 ( V_169 ) ;
F_133 ( & V_28 -> V_170 . V_203 , V_197 ) ;
V_174 = F_136 ( V_169 , struct V_173 , V_270 ) ;
V_31 = V_174 -> V_31 ;
F_137 ( V_31 -> V_28 , V_28 -> V_170 . V_44 ,
V_31 -> V_35 , V_31 -> V_274 ) ;
F_138 ( V_31 ) ;
F_52 ( V_169 ) ;
}
}
static int F_114 ( struct V_27 * V_28 , int V_116 , T_10 V_44 )
{
int V_104 = 0 ;
struct V_31 * V_31 ;
struct V_173 * V_174 ;
char * V_1 ;
F_139 ( & V_28 -> V_170 . V_203 ) ;
V_28 -> V_170 . V_44 = V_44 ;
F_118 ( & V_28 -> V_170 . V_271 ) ;
while ( V_104 < V_116 ) {
V_174 = F_107 ( sizeof( struct V_173 ) , V_139 ) ;
if ( ! V_174 )
break;
V_174 -> V_28 = V_28 ;
F_117 ( & V_174 -> V_175 ,
F_64 ) ;
V_31 = F_140 ( 0 , V_139 ) ;
if ( ! V_31 ) {
F_52 ( V_174 ) ;
break;
}
V_174 -> V_31 = V_31 ;
V_1 = F_141 ( V_28 -> V_140 , V_256 , V_139 ,
& V_31 -> V_274 ) ;
if ( ! V_1 ) {
F_52 ( V_174 ) ;
F_138 ( V_31 ) ;
break;
}
F_142 ( V_31 , V_28 -> V_140 , F_143 ( V_28 -> V_140 , 1 ) ,
V_1 , V_44 , F_34 , V_174 ) ;
V_31 -> V_275 |= V_276 ;
F_132 ( & V_174 -> V_270 , & V_28 -> V_170 . V_271 ) ;
V_104 ++ ;
}
F_144 ( & V_28 -> V_170 . V_176 , V_104 ) ;
V_28 -> V_170 . V_116 = V_104 ;
V_28 -> V_170 . V_272 = V_104 ;
F_18 ( L_42 , V_104 , ( int ) V_44 ) ;
return V_104 ;
}
static struct V_31 * F_15 ( struct V_27 * V_28 )
{
int V_105 = 0 ;
struct V_130 * V_270 ;
struct V_173 * V_174 ;
struct V_31 * V_31 = NULL ;
unsigned long V_197 ;
V_105 = F_145 ( & V_28 -> V_170 . V_176 , V_277 ) ;
if ( V_105 ) {
F_103 ( & V_28 -> V_269 , 1 ) ;
F_63 ( L_43 ,
V_105 , V_28 -> V_170 . V_272 ) ;
goto error;
}
F_131 ( & V_28 -> V_170 . V_203 , V_197 ) ;
F_146 ( F_147 ( & V_28 -> V_170 . V_271 ) ) ;
V_270 = V_28 -> V_170 . V_271 . V_273 ;
F_135 ( V_270 ) ;
V_28 -> V_170 . V_272 -- ;
F_133 ( & V_28 -> V_170 . V_203 , V_197 ) ;
V_174 = F_136 ( V_270 , struct V_173 , V_270 ) ;
V_31 = V_174 -> V_31 ;
error:
return V_31 ;
}
static int F_16 ( struct V_27 * V_28 , struct V_31 * V_31 , T_10 V_99 )
{
int V_105 ;
F_146 ( V_99 > V_28 -> V_170 . V_44 ) ;
V_31 -> V_96 = V_99 ;
V_105 = F_148 ( V_31 , V_139 ) ;
if ( V_105 ) {
F_34 ( V_31 ) ;
F_103 ( & V_28 -> V_269 , 1 ) ;
F_51 ( L_44 , V_105 ) ;
}
return V_105 ;
}
