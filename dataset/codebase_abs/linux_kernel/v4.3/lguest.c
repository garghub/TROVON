static bool F_1 ( const struct V_1 V_2 [] , unsigned int V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
if ( V_2 [ V_4 ] . V_5 )
return false ;
return true ;
}
static void F_2 ( struct V_6 * V_7 ,
struct V_1 V_2 [] , unsigned V_3 ,
void * V_8 , unsigned V_9 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
unsigned int V_10 ;
V_10 = V_2 [ V_4 ] . V_5 < V_9 ? V_2 [ V_4 ] . V_5 : V_9 ;
if ( V_8 ) {
memcpy ( V_8 , V_2 [ V_4 ] . V_11 , V_10 ) ;
V_8 += V_10 ;
}
V_2 [ V_4 ] . V_11 += V_10 ;
V_2 [ V_4 ] . V_5 -= V_10 ;
V_9 -= V_10 ;
}
if ( V_9 != 0 )
F_3 ( V_7 , L_1 ) ;
}
static void * F_4 ( unsigned long V_12 )
{
return V_13 + V_12 ;
}
static unsigned long F_5 ( const void * V_12 )
{
return ( V_12 - V_13 ) ;
}
static int F_6 ( const char * V_14 , int V_15 )
{
int V_16 = F_7 ( V_14 , V_15 ) ;
if ( V_16 < 0 )
F_8 ( 1 , L_2 , V_14 ) ;
return V_16 ;
}
static void * F_9 ( unsigned int V_17 )
{
int V_16 = F_6 ( L_3 , V_18 ) ;
void * V_12 ;
V_12 = F_10 ( NULL , F_11 () * ( V_17 + 2 ) ,
V_19 , V_20 , V_16 , 0 ) ;
if ( V_12 == V_21 )
F_8 ( 1 , L_4 , V_17 ) ;
if ( F_12 ( V_12 + F_11 () , F_11 () * V_17 ,
V_22 | V_23 ) == - 1 )
F_8 ( 1 , L_5 , V_17 ) ;
F_13 ( V_16 ) ;
return V_12 + F_11 () ;
}
static unsigned long F_14 ( T_1 V_24 )
{
unsigned long V_12 = V_25 ;
T_1 V_4 ;
if ( ! V_24 )
return V_12 ;
for ( V_4 = 1 ; V_4 < V_24 ; V_4 <<= 1 ) ;
V_25 += V_4 ;
return V_12 ;
}
static void F_15 ( int V_16 , void * V_12 , unsigned long V_26 , unsigned long V_9 )
{
T_2 V_27 ;
if ( F_10 ( V_12 , V_9 , V_22 | V_23 ,
V_28 | V_20 , V_16 , V_26 ) != V_21 )
return;
V_27 = F_16 ( V_16 , V_12 , V_9 , V_26 ) ;
if ( V_27 != V_9 )
F_8 ( 1 , L_6 , V_26 , V_9 , V_27 ) ;
}
static unsigned long F_17 ( int V_29 , const T_3 * V_30 )
{
T_4 V_31 [ V_30 -> V_32 ] ;
unsigned int V_4 ;
if ( V_30 -> V_33 != V_34
|| V_30 -> V_35 != V_36
|| V_30 -> V_37 != sizeof( T_4 )
|| V_30 -> V_32 < 1 || V_30 -> V_32 > 65536U / sizeof( T_4 ) )
F_18 ( 1 , L_7 ) ;
if ( F_19 ( V_29 , V_30 -> V_38 , V_39 ) < 0 )
F_8 ( 1 , L_8 ) ;
if ( F_20 ( V_29 , V_31 , sizeof( V_31 ) ) != sizeof( V_31 ) )
F_8 ( 1 , L_9 ) ;
for ( V_4 = 0 ; V_4 < V_30 -> V_32 ; V_4 ++ ) {
if ( V_31 [ V_4 ] . V_40 != V_41 )
continue;
F_21 ( L_10 ,
V_4 , V_31 [ V_4 ] . V_42 , ( void * ) V_31 [ V_4 ] . V_43 ) ;
F_15 ( V_29 , F_4 ( V_31 [ V_4 ] . V_43 ) ,
V_31 [ V_4 ] . V_44 , V_31 [ V_4 ] . V_45 ) ;
}
return V_30 -> V_46 ;
}
static unsigned long F_22 ( int V_16 )
{
struct V_47 V_48 ;
int V_27 ;
void * V_49 = F_4 ( 0x100000 ) ;
F_19 ( V_16 , 0 , V_39 ) ;
F_20 ( V_16 , & V_48 , sizeof( V_48 ) ) ;
if ( memcmp ( & V_48 . V_50 . V_51 , L_11 , 4 ) != 0 )
F_18 ( 1 , L_12 ) ;
F_19 ( V_16 , ( V_48 . V_50 . V_52 + 1 ) * 512 , V_39 ) ;
while ( ( V_27 = F_20 ( V_16 , V_49 , 65536 ) ) > 0 )
V_49 += V_27 ;
return V_48 . V_50 . V_53 ;
}
static unsigned long F_23 ( int V_16 )
{
T_3 V_50 ;
if ( F_20 ( V_16 , & V_50 , sizeof( V_50 ) ) != sizeof( V_50 ) )
F_8 ( 1 , L_13 ) ;
if ( memcmp ( V_50 . V_54 , V_55 , V_56 ) == 0 )
return F_17 ( V_16 , & V_50 ) ;
return F_22 ( V_16 ) ;
}
static inline unsigned long F_24 ( unsigned long V_12 )
{
return ( ( V_12 + F_11 () - 1 ) & ~ ( F_11 () - 1 ) ) ;
}
static unsigned long F_25 ( const char * V_14 , unsigned long V_57 )
{
int V_58 ;
struct V_59 V_60 ;
unsigned long V_9 ;
V_58 = F_6 ( V_14 , V_18 ) ;
if ( F_26 ( V_58 , & V_60 ) < 0 )
F_8 ( 1 , L_14 , V_14 ) ;
V_9 = F_24 ( V_60 . V_61 ) ;
F_15 ( V_58 , F_4 ( V_57 - V_9 ) , 0 , V_60 . V_61 ) ;
F_13 ( V_58 ) ;
F_21 ( L_15 , V_14 , V_9 , ( void * ) V_57 - V_9 ) ;
return V_9 ;
}
static void F_27 ( char * V_62 , char * args [] )
{
unsigned int V_4 , V_9 = 0 ;
for ( V_4 = 0 ; args [ V_4 ] ; V_4 ++ ) {
if ( V_4 ) {
strcat ( V_62 + V_9 , L_16 ) ;
V_9 ++ ;
}
strcpy ( V_62 + V_9 , args [ V_4 ] ) ;
V_9 += strlen ( args [ V_4 ] ) ;
}
V_62 [ V_9 ] = '\0' ;
}
static void F_28 ( unsigned long V_63 )
{
unsigned long args [] = { V_64 ,
( unsigned long ) V_13 ,
V_65 / F_11 () , V_63 ,
( V_25 + F_11 () - 1 ) / F_11 () } ;
F_21 ( L_17 ,
V_13 , V_13 + V_65 ,
V_65 , V_25 ) ;
V_66 = F_6 ( L_18 , V_67 ) ;
if ( F_29 ( V_66 , args , sizeof( args ) ) < 0 )
F_8 ( 1 , L_19 ) ;
}
static void * F_30 ( struct V_6 * V_7 ,
unsigned long V_12 , unsigned int V_24 ,
unsigned int line )
{
if ( ( V_12 + V_24 ) > V_65 || ( V_12 + V_24 ) < V_12 )
F_3 ( V_7 , L_20 ,
__FILE__ , line , V_12 ) ;
return F_4 ( V_12 ) ;
}
static unsigned F_31 ( struct V_6 * V_7 , struct V_68 * V_69 ,
unsigned int V_4 , unsigned int V_70 )
{
unsigned int V_71 ;
if ( ! ( V_69 [ V_4 ] . V_15 & V_72 ) )
return V_70 ;
V_71 = V_69 [ V_4 ] . V_71 ;
F_32 () ;
if ( V_71 >= V_70 )
F_3 ( V_7 , L_21 , V_71 ) ;
return V_71 ;
}
static void F_33 ( struct V_73 * V_74 )
{
unsigned long V_75 [] = { V_76 , V_74 -> V_77 -> V_78 . V_79 } ;
if ( ! V_74 -> V_80 )
return;
V_74 -> V_80 = 0 ;
if ( V_74 -> V_81 . V_82 -> V_15 > 1 )
F_34 ( V_74 , L_22 , V_74 -> V_81 . V_82 -> V_15 ) ;
if ( V_74 -> V_81 . V_82 -> V_15 & V_83 ) {
return;
}
V_74 -> V_77 -> V_84 -> V_85 = 0x1 ;
if ( F_29 ( V_66 , V_75 , sizeof( V_75 ) ) != 0 )
F_8 ( 1 , L_23 , V_74 -> V_77 -> V_78 . V_79 ) ;
}
static unsigned F_35 ( struct V_73 * V_74 ,
struct V_1 V_2 [] ,
unsigned int * V_86 , unsigned int * V_87 )
{
unsigned int V_4 , V_88 , V_70 ;
struct V_68 * V_69 ;
T_5 V_89 = F_36 ( V_74 ) ;
while ( V_89 == V_74 -> V_81 . V_82 -> V_90 ) {
T_6 V_91 ;
F_33 ( V_74 ) ;
V_74 -> V_81 . V_10 -> V_15 &= ~ V_92 ;
F_37 () ;
if ( V_89 != V_74 -> V_81 . V_82 -> V_90 ) {
V_74 -> V_81 . V_10 -> V_15 |= V_92 ;
break;
}
if ( F_20 ( V_74 -> V_93 , & V_91 , sizeof( V_91 ) ) != sizeof( V_91 ) )
F_18 ( 1 , L_24 ) ;
V_74 -> V_81 . V_10 -> V_15 |= V_92 ;
}
if ( ( T_5 ) ( V_74 -> V_81 . V_82 -> V_90 - V_89 ) > V_74 -> V_81 . V_17 )
F_34 ( V_74 , L_25 ,
V_89 , V_74 -> V_81 . V_82 -> V_90 ) ;
F_38 () ;
V_88 = V_74 -> V_81 . V_82 -> V_94 [ V_89 % V_74 -> V_81 . V_17 ] ;
F_36 ( V_74 ) ++ ;
if ( V_88 >= V_74 -> V_81 . V_17 )
F_34 ( V_74 , L_26 , V_88 ) ;
* V_86 = * V_87 = 0 ;
V_70 = V_74 -> V_81 . V_17 ;
V_69 = V_74 -> V_81 . V_69 ;
V_4 = V_88 ;
do {
if ( V_69 [ V_4 ] . V_15 & V_95 ) {
if ( ! ( V_74 -> V_77 -> V_96 &
( 1 << V_97 ) ) )
F_34 ( V_74 , L_27 ) ;
if ( V_69 != V_74 -> V_81 . V_69 )
F_34 ( V_74 , L_28 ) ;
if ( V_69 [ V_4 ] . V_15 & V_72 )
F_34 ( V_74 , L_29 ) ;
if ( V_69 [ V_4 ] . V_9 % sizeof( struct V_68 ) )
F_34 ( V_74 ,
L_30 ) ;
V_70 = V_69 [ V_4 ] . V_9 / sizeof( struct V_68 ) ;
V_69 = F_39 ( V_74 -> V_77 , V_69 [ V_4 ] . V_12 , V_69 [ V_4 ] . V_9 ) ;
V_4 = 0 ;
if ( V_70 > V_74 -> V_98 . V_99 )
F_34 ( V_74 ,
L_31 ) ;
}
V_2 [ * V_86 + * V_87 ] . V_5 = V_69 [ V_4 ] . V_9 ;
V_2 [ * V_86 + * V_87 ] . V_11
= F_39 ( V_74 -> V_77 , V_69 [ V_4 ] . V_12 , V_69 [ V_4 ] . V_9 ) ;
if ( V_69 [ V_4 ] . V_15 & V_100 )
( * V_87 ) ++ ;
else {
if ( * V_87 )
F_34 ( V_74 ,
L_32 ) ;
( * V_86 ) ++ ;
}
if ( * V_86 + * V_87 > V_70 )
F_34 ( V_74 , L_33 ) ;
} while ( ( V_4 = F_31 ( V_74 -> V_77 , V_69 , V_4 , V_70 ) ) != V_70 );
return V_88 ;
}
static void F_40 ( struct V_73 * V_74 , unsigned int V_88 , int V_9 )
{
struct V_101 * V_10 ;
V_10 = & V_74 -> V_81 . V_10 -> V_94 [ V_74 -> V_81 . V_10 -> V_90 % V_74 -> V_81 . V_17 ] ;
V_10 -> V_102 = V_88 ;
V_10 -> V_9 = V_9 ;
F_32 () ;
V_74 -> V_81 . V_10 -> V_90 ++ ;
V_74 -> V_80 ++ ;
}
static void F_41 ( struct V_73 * V_74 , unsigned V_88 , int V_9 )
{
F_40 ( V_74 , V_88 , V_9 ) ;
F_33 ( V_74 ) ;
}
static void F_42 ( struct V_73 * V_74 )
{
int V_9 ;
unsigned int V_88 , V_87 , V_86 ;
struct V_103 * abort = V_74 -> V_77 -> V_104 ;
struct V_1 V_2 [ V_74 -> V_81 . V_17 ] ;
V_88 = F_35 ( V_74 , V_2 , & V_86 , & V_87 ) ;
if ( V_86 )
F_34 ( V_74 , L_34 ) ;
V_9 = F_43 ( V_105 , V_2 , V_87 ) ;
if ( V_9 <= 0 ) {
F_44 ( L_35 ) ;
for (; ; )
F_45 () ;
}
F_41 ( V_74 , V_88 , V_9 ) ;
if ( V_9 != 1 || ( ( char * ) V_2 [ 0 ] . V_11 ) [ 0 ] != 3 ) {
abort -> V_106 = 0 ;
return;
}
abort -> V_106 ++ ;
if ( abort -> V_106 == 1 )
F_46 ( & abort -> V_63 , NULL ) ;
else if ( abort -> V_106 == 3 ) {
struct V_107 V_108 ;
F_46 ( & V_108 , NULL ) ;
if ( V_108 . V_109 <= abort -> V_63 . V_109 + 1 )
F_47 ( 0 , V_110 ) ;
abort -> V_106 = 0 ;
}
}
static void F_48 ( struct V_73 * V_74 )
{
unsigned int V_88 , V_111 , V_112 ;
struct V_1 V_2 [ V_74 -> V_81 . V_17 ] ;
V_88 = F_35 ( V_74 , V_2 , & V_111 , & V_112 ) ;
if ( V_112 )
F_34 ( V_74 , L_36 ) ;
while ( ! F_1 ( V_2 , V_111 ) ) {
int V_9 = F_49 ( V_113 , V_2 , V_111 ) ;
if ( V_9 <= 0 ) {
F_50 ( L_37 , V_9 , V_114 ) ;
break;
}
F_2 ( V_74 -> V_77 , V_2 , V_111 , NULL , V_9 ) ;
}
F_40 ( V_74 , V_88 , 0 ) ;
}
static void F_51 ( struct V_73 * V_74 )
{
struct V_115 * V_115 = V_74 -> V_77 -> V_104 ;
unsigned int V_88 , V_111 , V_112 ;
struct V_1 V_2 [ V_74 -> V_81 . V_17 ] ;
V_88 = F_35 ( V_74 , V_2 , & V_111 , & V_112 ) ;
if ( V_112 )
F_34 ( V_74 , L_38 ) ;
if ( F_49 ( V_115 -> V_116 , V_2 , V_111 ) < 0 )
F_44 ( L_39 , V_114 ) ;
F_40 ( V_74 , V_88 , 0 ) ;
}
static bool F_52 ( int V_16 )
{
T_7 V_117 ;
struct V_107 V_118 = { 0 , 0 } ;
F_53 ( & V_117 ) ;
F_54 ( V_16 , & V_117 ) ;
return F_55 ( V_16 + 1 , & V_117 , NULL , NULL , & V_118 ) != 1 ;
}
static void F_56 ( struct V_73 * V_74 )
{
int V_9 ;
unsigned int V_88 , V_111 , V_112 ;
struct V_1 V_2 [ V_74 -> V_81 . V_17 ] ;
struct V_115 * V_115 = V_74 -> V_77 -> V_104 ;
V_88 = F_35 ( V_74 , V_2 , & V_111 , & V_112 ) ;
if ( V_111 )
F_34 ( V_74 , L_40 ) ;
if ( V_74 -> V_80 && F_52 ( V_115 -> V_116 ) )
F_33 ( V_74 ) ;
V_9 = F_43 ( V_115 -> V_116 , V_2 , V_112 ) ;
if ( V_9 <= 0 )
F_50 ( L_41 , V_114 ) ;
F_40 ( V_74 , V_88 , V_9 ) ;
}
static int F_57 ( void * V_119 )
{
struct V_73 * V_74 = V_119 ;
for (; ; )
V_74 -> V_120 ( V_74 ) ;
return 0 ;
}
static void F_58 ( int signal )
{
F_47 ( 0 , V_121 ) ;
}
static void F_59 ( struct V_73 * V_74 )
{
V_74 -> V_98 . V_99 = V_122 ;
V_74 -> V_98 . V_123 = 0 ;
}
static void F_60 ( struct V_6 * V_77 )
{
struct V_73 * V_74 ;
F_21 ( L_42 , V_77 -> V_14 ) ;
V_77 -> V_96 = 0 ;
signal ( V_124 , V_125 ) ;
V_77 -> V_84 -> V_126 . V_123 = 0 ;
for ( V_74 = V_77 -> V_74 ; V_74 ; V_74 = V_74 -> V_71 ) {
V_74 -> V_127 = 0 ;
F_59 ( V_74 ) ;
if ( V_74 -> V_128 != ( V_129 ) - 1 ) {
F_47 ( V_74 -> V_128 , V_121 ) ;
F_61 ( V_74 -> V_128 , NULL , 0 ) ;
V_74 -> V_128 = ( V_129 ) - 1 ;
}
}
V_77 -> V_130 = false ;
V_77 -> V_131 = false ;
signal ( V_124 , ( void * ) F_58 ) ;
}
static void F_62 ( void )
{
unsigned int V_4 ;
for ( V_4 = 1 ; V_4 < V_132 ; V_4 ++ ) {
struct V_6 * V_7 = V_133 . V_134 [ V_4 ] ;
if ( ! V_7 )
continue;
F_60 ( V_7 ) ;
}
if ( V_135 . V_136 & ( V_137 | V_138 | V_139 ) )
F_63 ( V_105 , V_140 , & V_135 ) ;
}
static void F_64 ( void )
{
V_141 . V_14 = L_43 ;
V_141 . V_78 . V_142 = 0x06 ;
V_141 . V_78 . V_143 = 0 ;
V_133 . V_134 [ 0 ] = & V_141 ;
}
static struct V_6 * F_65 ( unsigned int V_144 )
{
return V_133 . V_134 [ V_144 ] ;
}
static void F_66 ( T_5 V_145 , T_8 V_146 , T_8 V_147 , T_8 * V_148 )
{
assert ( V_145 < 4 ) ;
assert ( V_147 == 0xFF || V_147 == 0xFFFF || V_147 == 0xFFFFFFFF ) ;
* V_148 = ( V_146 >> ( V_145 * 8 ) ) & V_147 ;
}
static void F_67 ( T_5 V_145 , T_8 V_146 , T_8 V_147 , T_8 * V_62 )
{
assert ( V_145 < 4 ) ;
assert ( V_147 == 0xFF || V_147 == 0xFFFF || V_147 == 0xFFFFFFFF ) ;
* V_62 &= ~ ( V_147 << ( V_145 * 8 ) ) ;
* V_62 |= ( V_146 & V_147 ) << ( V_145 * 8 ) ;
}
static struct V_6 * F_68 ( T_8 * V_149 )
{
if ( ! V_150 . V_151 . V_152 )
return NULL ;
if ( V_150 . V_151 . V_153 != 0 )
return NULL ;
if ( V_150 . V_151 . V_154 != 0 )
return NULL ;
if ( V_150 . V_151 . V_26 * 4 >= sizeof( struct V_98 ) )
return NULL ;
* V_149 = V_150 . V_151 . V_26 ;
return F_65 ( V_150 . V_151 . V_155 ) ;
}
static bool F_69 ( struct V_6 * V_7 ,
struct V_156 * V_157 )
{
if ( V_157 -> V_158 . V_159 != 0 )
return false ;
if ( V_157 -> V_158 . V_26 >= V_7 -> V_160
|| V_157 -> V_158 . V_26 + V_157 -> V_158 . V_161 > V_7 -> V_160 )
return false ;
if ( V_157 -> V_158 . V_161 != 1
&& V_157 -> V_158 . V_161 != 2
&& V_157 -> V_158 . V_161 != 4 )
return false ;
if ( V_157 -> V_158 . V_26 % V_157 -> V_158 . V_161 != 0 )
return false ;
return true ;
}
static bool F_70 ( T_5 V_162 )
{
return V_162 >= V_163 && V_162 < V_163 + 4 ;
}
static bool F_71 ( T_5 V_162 , T_8 V_147 , T_8 V_148 )
{
F_67 ( V_162 - V_163 , V_148 , V_147 ,
& V_150 . V_148 ) ;
F_21 ( L_44 ,
V_150 . V_151 . V_152 ? L_45 : L_46 ,
V_148 , V_147 ,
V_150 . V_151 . V_154 ,
V_150 . V_151 . V_155 ,
V_150 . V_151 . V_153 ,
V_150 . V_151 . V_26 ) ;
return true ;
}
static void F_72 ( T_5 V_162 , T_8 V_147 , T_8 * V_148 )
{
F_66 ( V_162 - V_163 , V_150 . V_148 , V_147 , V_148 ) ;
}
static bool F_73 ( T_5 V_162 )
{
return V_162 >= V_164 && V_162 < V_164 + 4 ;
}
static bool F_74 ( T_5 V_162 , T_8 V_147 , T_8 V_148 )
{
T_8 V_149 , V_165 ;
struct V_6 * V_7 = F_68 ( & V_149 ) ;
if ( ! V_7 )
return false ;
V_165 = V_162 - V_164 ;
if ( & V_7 -> V_166 [ V_149 ] == & V_7 -> V_78 . V_159 [ 0 ] ) {
int V_4 ;
F_67 ( V_165 , V_148 , V_147 , & V_7 -> V_78 . V_159 [ 0 ] ) ;
for ( V_4 = 0 ; ( 1 << V_4 ) < V_7 -> V_160 ; V_4 ++ )
V_7 -> V_78 . V_159 [ 0 ] &= ~ ( 1 << V_4 ) ;
return true ;
} else if ( ( & V_7 -> V_166 [ V_149 ] > & V_7 -> V_78 . V_159 [ 0 ]
&& & V_7 -> V_166 [ V_149 ] <= & V_7 -> V_78 . V_159 [ 6 ] )
|| & V_7 -> V_166 [ V_149 ] == & V_7 -> V_78 . V_167 ) {
F_67 ( V_165 , V_148 , V_147 , & V_7 -> V_166 [ V_149 ] ) ;
return true ;
} else if ( & V_7 -> V_166 [ V_149 ] == ( void * ) & V_7 -> V_78 . V_168 ) {
if ( V_147 == 0xFFFFFFFF )
V_147 = 0xFFFF ;
F_67 ( V_165 , V_148 , V_147 , & V_7 -> V_166 [ V_149 ] ) ;
return true ;
} else if ( & V_7 -> V_166 [ V_149 ] == ( void * ) & V_7 -> V_78 . V_169
&& V_147 == 0xFFFF ) {
return true ;
} else if ( & V_7 -> V_166 [ V_149 ]
== ( void * ) & V_7 -> V_78 . V_157 . V_158 . V_159
|| & V_7 -> V_166 [ V_149 ]
== & V_7 -> V_78 . V_157 . V_158 . V_161
|| & V_7 -> V_166 [ V_149 ]
== & V_7 -> V_78 . V_157 . V_158 . V_26 ) {
F_67 ( V_165 , V_148 , V_147 , & V_7 -> V_166 [ V_149 ] ) ;
return true ;
} else if ( & V_7 -> V_166 [ V_149 ] == & V_7 -> V_78 . V_157 . V_170 ) {
T_8 V_171 ;
if ( ! F_69 ( V_7 , & V_7 -> V_78 . V_157 ) )
return false ;
F_67 ( V_165 , V_148 , V_147 , & V_7 -> V_78 . V_157 . V_170 ) ;
V_171 = ( 1ULL << ( 8 * V_7 -> V_78 . V_157 . V_158 . V_161 ) ) - 1 ;
F_21 ( L_47 ,
V_7 -> V_78 . V_157 . V_170 , V_171 ,
V_7 -> V_78 . V_157 . V_158 . V_159 ,
V_7 -> V_78 . V_157 . V_158 . V_26 ,
V_7 -> V_78 . V_157 . V_158 . V_161 ) ;
F_75 ( V_7 , V_7 -> V_78 . V_157 . V_158 . V_26 ,
V_7 -> V_78 . V_157 . V_170 ,
V_171 ) ;
return true ;
}
return false ;
}
static void F_76 ( T_5 V_162 , T_8 V_147 , T_8 * V_148 )
{
T_8 V_149 ;
struct V_6 * V_7 = F_68 ( & V_149 ) ;
if ( ! V_7 )
return;
if ( & V_7 -> V_166 [ V_149 ] == & V_7 -> V_78 . V_157 . V_170 ) {
T_8 V_172 ;
if ( ! F_69 ( V_7 , & V_7 -> V_78 . V_157 ) )
F_3 ( V_7 ,
L_48 ,
V_7 -> V_78 . V_157 . V_158 . V_159 ,
V_7 -> V_78 . V_157 . V_158 . V_26 ,
V_7 -> V_78 . V_157 . V_158 . V_161 ) ;
V_172 = ( 1ULL << ( 8 * V_7 -> V_78 . V_157 . V_158 . V_161 ) ) - 1 ;
V_7 -> V_78 . V_157 . V_170
= F_77 ( V_7 ,
V_7 -> V_78 . V_157 . V_158 . V_26 ,
V_172 ) ;
F_21 ( L_49 ,
V_7 -> V_78 . V_157 . V_170 , V_172 ,
V_7 -> V_78 . V_157 . V_158 . V_159 ,
V_7 -> V_78 . V_157 . V_158 . V_26 ,
V_7 -> V_78 . V_157 . V_158 . V_161 ) ;
}
F_66 ( V_162 - V_164 , V_7 -> V_166 [ V_149 ] , V_147 , V_148 ) ;
}
static T_8 F_78 ( T_1 V_26 )
{
T_8 V_27 ;
unsigned long args [] = { V_173 , V_26 } ;
if ( F_79 ( V_66 , args , sizeof( args ) , V_174 ) < 0 )
F_8 ( 1 , L_50 , V_26 ) ;
if ( F_16 ( V_66 , & V_27 , sizeof( V_27 ) , V_174 ) != sizeof( V_27 ) )
F_8 ( 1 , L_51 , V_26 ) ;
return V_27 ;
}
static void F_80 ( T_1 V_26 , T_8 V_148 )
{
unsigned long args [] = { V_175 , V_26 , V_148 } ;
if ( F_79 ( V_66 , args , sizeof( args ) , V_174 ) < 0 )
F_8 ( 1 , L_52 , V_26 ) ;
}
static T_8 F_81 ( unsigned V_176 , T_8 V_147 )
{
if ( V_147 == 0xFF && ( V_176 & 0x4 ) )
return F_81 ( V_176 & 0x3 , 0xFFFF ) >> 8 ;
switch ( V_176 ) {
case 0 : return F_82 ( V_177 ) & V_147 ;
case 1 : return F_82 ( V_178 ) & V_147 ;
case 2 : return F_82 ( V_179 ) & V_147 ;
case 3 : return F_82 ( V_180 ) & V_147 ;
case 4 : return F_82 ( V_181 ) & V_147 ;
case 5 : return F_82 ( V_182 ) & V_147 ;
case 6 : return F_82 ( V_183 ) & V_147 ;
case 7 : return F_82 ( V_184 ) & V_147 ;
}
abort () ;
}
static void F_83 ( unsigned V_176 , T_8 V_148 , T_8 V_147 )
{
assert ( ~ ( V_148 & ~ V_147 ) ) ;
if ( V_147 == 0xFF && ( V_176 & 0x4 ) ) {
V_148 = ( V_148 << 8 ) | F_81 ( V_176 & 0x3 , 0xFF ) ;
F_83 ( V_176 & 0x3 , V_148 , 0xFFFF ) ;
return;
}
switch ( V_176 ) {
case 0 : F_84 ( V_177 , V_148 | ( F_82 ( V_177 ) & ~ V_147 ) ) ; return;
case 1 : F_84 ( V_178 , V_148 | ( F_82 ( V_178 ) & ~ V_147 ) ) ; return;
case 2 : F_84 ( V_179 , V_148 | ( F_82 ( V_179 ) & ~ V_147 ) ) ; return;
case 3 : F_84 ( V_180 , V_148 | ( F_82 ( V_180 ) & ~ V_147 ) ) ; return;
case 4 : F_84 ( V_181 , V_148 | ( F_82 ( V_181 ) & ~ V_147 ) ) ; return;
case 5 : F_84 ( V_182 , V_148 | ( F_82 ( V_182 ) & ~ V_147 ) ) ; return;
case 6 : F_84 ( V_183 , V_148 | ( F_82 ( V_183 ) & ~ V_147 ) ) ; return;
case 7 : F_84 ( V_184 , V_148 | ( F_82 ( V_184 ) & ~ V_147 ) ) ; return;
}
abort () ;
}
static T_8 F_85 ( T_9 V_185 )
{
switch ( V_185 >> 6 ) {
case 0 :
if ( ( V_185 & 0x7 ) == 0x5 )
return 2 ;
return 0 ;
case 1 :
return 1 ;
case 2 :
return 4 ;
case 3 :
return 0 ;
}
abort () ;
}
static void F_86 ( const T_9 V_186 [] )
{
unsigned long args [] = { V_187 , 13 } ;
unsigned int V_188 = 0 , V_112 = 0 , V_189 = 0 , V_190 ;
unsigned int V_177 , V_162 , V_147 ;
T_8 V_148 = 0xFFFFFFFF ;
if ( ( F_82 ( V_191 ) & 3 ) != 0x1 )
goto V_192;
if ( V_186 [ V_188 ] == 0xfa ) {
V_188 = 1 ;
goto V_193;
}
if ( V_186 [ V_188 ] == 0x66 ) {
V_189 = 1 ;
V_188 = 1 ;
}
V_190 = ! ( V_186 [ V_188 ] & 1 ) ;
switch ( V_186 [ V_188 ] & 0xFE ) {
case 0xE4 :
V_162 = V_186 [ V_188 + 1 ] ;
V_188 += 2 ;
V_112 = 1 ;
break;
case 0xEC :
V_162 = F_82 ( V_179 ) & 0xFFFF ;
V_188 += 1 ;
V_112 = 1 ;
break;
case 0xE6 :
V_162 = V_186 [ V_188 + 1 ] ;
V_188 += 2 ;
break;
case 0xEE :
V_162 = F_82 ( V_179 ) & 0xFFFF ;
V_188 += 1 ;
break;
default:
goto V_192;
}
if ( V_190 )
V_147 = 0xFF ;
else if ( V_189 )
V_147 = 0xFFFF ;
else
V_147 = 0xFFFFFFFF ;
V_177 = F_82 ( V_177 ) ;
if ( V_112 ) {
if ( V_162 == 0x64 )
V_148 = 1 ;
else if ( F_70 ( V_162 ) )
F_72 ( V_162 , V_147 , & V_148 ) ;
else if ( F_73 ( V_162 ) )
F_76 ( V_162 , V_147 , & V_148 ) ;
V_177 &= ~ V_147 ;
V_177 |= V_148 & V_147 ;
F_84 ( V_177 , V_177 ) ;
} else {
if ( F_70 ( V_162 ) ) {
if ( ! F_71 ( V_162 , V_147 , V_177 ) )
goto V_194;
} else if ( F_73 ( V_162 ) ) {
if ( ! F_74 ( V_162 , V_147 , V_177 ) )
goto V_194;
}
}
F_21 ( L_53 ,
V_112 ? L_54 : L_55 , V_147 , V_162 , V_177 ) ;
V_193:
F_84 ( V_195 , F_82 ( V_195 ) + V_188 ) ;
return;
V_194:
F_44 ( L_56 ,
V_112 ? L_57 : L_58 , V_162 , V_147 ) ;
V_192:
if ( F_29 ( V_66 , args , sizeof( args ) ) < 0 )
F_8 ( 1 , L_59 , F_82 ( V_195 ) ) ;
}
static struct V_6 * F_87 ( unsigned long V_196 , T_8 * V_145 )
{
unsigned int V_4 ;
for ( V_4 = 1 ; V_4 < V_132 ; V_4 ++ ) {
struct V_6 * V_7 = V_133 . V_134 [ V_4 ] ;
if ( ! V_7 )
continue;
if ( V_196 < V_7 -> V_197 )
continue;
if ( V_196 >= V_7 -> V_197 + V_7 -> V_160 )
continue;
* V_145 = V_196 - V_7 -> V_197 ;
return V_7 ;
}
return NULL ;
}
static struct V_73 * F_88 ( struct V_6 * V_7 , T_8 V_17 )
{
struct V_73 * V_74 = V_7 -> V_74 ;
while ( V_17 -- && V_74 )
V_74 = V_74 -> V_71 ;
return V_74 ;
}
static void F_89 ( const struct V_198 * V_126 ,
struct V_73 * V_74 )
{
V_74 -> V_98 = * V_126 ;
}
static void F_90 ( struct V_198 * V_126 ,
struct V_73 * V_74 )
{
T_1 V_145 = F_91 ( struct V_198 , V_99 ) ;
memcpy ( ( void * ) V_126 + V_145 , ( void * ) & V_74 -> V_98 + V_145 ,
sizeof( * V_126 ) - V_145 ) ;
}
static void F_92 ( struct V_6 * V_7 , struct V_73 * V_74 )
{
if ( V_74 -> V_98 . V_199
|| V_74 -> V_98 . V_200
|| V_74 -> V_98 . V_201 )
F_34 ( V_74 , L_60 ) ;
if ( V_74 -> V_98 . V_202 % 16
|| V_74 -> V_98 . V_203 % 2
|| V_74 -> V_98 . V_204 % 4 )
F_34 ( V_74 , L_61 ) ;
V_74 -> V_81 . V_17 = V_74 -> V_98 . V_99 ;
V_74 -> V_81 . V_69 = F_39 ( V_74 -> V_77 ,
V_74 -> V_98 . V_202 ,
sizeof( * V_74 -> V_81 . V_69 ) * V_74 -> V_81 . V_17 ) ;
V_74 -> V_81 . V_82 = F_39 ( V_74 -> V_77 ,
V_74 -> V_98 . V_203 ,
sizeof( * V_74 -> V_81 . V_82 )
+ ( sizeof( V_74 -> V_81 . V_82 -> V_94 [ 0 ] )
* V_74 -> V_81 . V_17 ) ) ;
V_74 -> V_81 . V_10 = F_39 ( V_74 -> V_77 ,
V_74 -> V_98 . V_204 ,
sizeof( * V_74 -> V_81 . V_10 )
+ ( sizeof( V_74 -> V_81 . V_10 -> V_94 [ 0 ] )
* V_74 -> V_81 . V_17 ) ) ;
if ( V_74 -> V_81 . V_10 -> V_15 != 0 )
F_34 ( V_74 , L_62 ,
V_74 -> V_81 . V_10 -> V_15 ) ;
}
static void F_93 ( struct V_73 * V_74 )
{
char * V_205 = malloc ( 32768 ) ;
V_74 -> V_93 = V_93 ( 0 , 0 ) ;
if ( V_74 -> V_93 < 0 )
F_8 ( 1 , L_63 ) ;
V_74 -> V_128 = F_94 ( F_57 , V_205 + 32768 , V_206 | V_124 , V_74 ) ;
if ( V_74 -> V_128 == ( V_129 ) - 1 )
F_8 ( 1 , L_64 ) ;
}
static void F_95 ( struct V_6 * V_7 )
{
struct V_73 * V_74 ;
for ( V_74 = V_7 -> V_74 ; V_74 ; V_74 = V_74 -> V_71 ) {
if ( V_74 -> V_98 . V_123 )
F_93 ( V_74 ) ;
}
}
static void F_75 ( struct V_6 * V_7 , T_8 V_145 , T_8 V_148 , T_8 V_147 )
{
struct V_73 * V_74 ;
switch ( V_145 ) {
case F_91 ( struct V_207 , V_126 . V_208 ) :
if ( V_148 == 0 )
V_7 -> V_84 -> V_126 . V_209 = V_7 -> V_210 ;
else if ( V_148 == 1 )
V_7 -> V_84 -> V_126 . V_209 = ( V_7 -> V_210 >> 32 ) ;
else
V_7 -> V_84 -> V_126 . V_209 = 0 ;
goto V_211;
case F_91 ( struct V_207 , V_126 . V_212 ) :
if ( V_148 > 1 )
F_3 ( V_7 , L_65 , V_148 ) ;
goto V_211;
case F_91 ( struct V_207 , V_126 . V_213 ) :
if ( V_7 -> V_84 -> V_126 . V_212 == 0 ) {
V_7 -> V_96 &= ~ ( ( T_6 ) 0xFFFFFFFF ) ;
V_7 -> V_96 |= V_148 ;
} else {
assert ( V_7 -> V_84 -> V_126 . V_212 == 1 ) ;
V_7 -> V_96 &= 0xFFFFFFFF ;
V_7 -> V_96 |= ( ( T_6 ) V_148 ) << 32 ;
}
if ( V_7 -> V_96 & ~ V_7 -> V_210 )
F_3 ( V_7 , L_66 ,
V_7 -> V_96 , V_7 -> V_210 ) ;
goto V_211;
case F_91 ( struct V_207 , V_126 . V_214 ) : {
T_9 V_215 ;
F_21 ( L_67 , V_7 -> V_14 , V_148 ) ;
if ( V_148 == 0 ) {
F_60 ( V_7 ) ;
goto V_216;
}
if ( V_7 -> V_84 -> V_126 . V_214 & ~ V_148 )
F_3 ( V_7 , L_68 ,
V_7 -> V_84 -> V_126 . V_214 , V_148 ) ;
if ( V_148 & V_217
&& ! ( V_7 -> V_84 -> V_126 . V_214 & V_217 ) )
F_95 ( V_7 ) ;
V_215 = 0 ;
switch ( V_148 & ~ V_7 -> V_84 -> V_126 . V_214 ) {
case V_217 :
V_215 |= V_218 ;
case V_218 :
V_215 |= V_219 ;
case V_219 :
V_215 |= V_220 ;
case V_220 :
break;
default:
F_3 ( V_7 , L_69 ,
V_7 -> V_84 -> V_126 . V_214 , V_148 ) ;
}
if ( V_7 -> V_84 -> V_126 . V_214 != V_215 )
F_3 ( V_7 , L_70 ,
V_7 -> V_84 -> V_126 . V_214 , V_148 ) ;
switch ( V_148 & ~ V_7 -> V_84 -> V_126 . V_214 ) {
case V_218 :
V_7 -> V_131 = true ;
break;
case V_217 :
if ( V_7 -> V_131 )
F_3 ( V_7 , L_71 ) ;
break;
}
goto V_216;
}
case F_91 ( struct V_207 , V_126 . V_221 ) :
V_74 = F_88 ( V_7 , V_148 ) ;
if ( ! V_74 ) {
V_7 -> V_84 -> V_126 . V_99 = 0 ;
goto V_222;
}
if ( V_7 -> V_84 -> V_126 . V_99 )
F_89 ( & V_7 -> V_84 -> V_126 ,
F_88 ( V_7 , V_7 -> V_84 -> V_126 . V_221 ) ) ;
F_90 ( & V_7 -> V_84 -> V_126 , V_74 ) ;
goto V_222;
case F_91 ( struct V_207 , V_126 . V_99 ) :
if ( V_148 & ( V_148 - 1 ) )
F_3 ( V_7 , L_72 , V_148 ) ;
if ( V_7 -> V_84 -> V_126 . V_123 )
F_3 ( V_7 , L_73 ) ;
goto V_222;
case F_91 ( struct V_207 , V_126 . V_223 ) :
F_3 ( V_7 , L_74 , V_148 ) ;
case F_91 ( struct V_207 , V_126 . V_123 ) : {
struct V_73 * V_74 = F_88 ( V_7 , V_7 -> V_84 -> V_126 . V_221 ) ;
if ( V_148 != 1 )
F_3 ( V_7 , L_75 , V_148 ) ;
if ( V_7 -> V_84 -> V_126 . V_214 & V_217 )
F_3 ( V_7 , L_76 ) ;
V_7 -> V_84 -> V_126 . V_123 = V_148 ;
F_89 ( & V_7 -> V_84 -> V_126 , V_74 ) ;
F_92 ( V_7 , V_74 ) ;
goto V_222;
}
case F_91 ( struct V_207 , V_126 . V_224 ) :
F_3 ( V_7 , L_77 ) ;
case F_91 ( struct V_207 , V_126 . V_202 ) :
case F_91 ( struct V_207 , V_126 . V_199 ) :
case F_91 ( struct V_207 , V_126 . V_203 ) :
case F_91 ( struct V_207 , V_126 . V_200 ) :
case F_91 ( struct V_207 , V_126 . V_204 ) :
case F_91 ( struct V_207 , V_126 . V_201 ) :
if ( V_7 -> V_84 -> V_126 . V_123 )
F_3 ( V_7 , L_78 ) ;
if ( ! ( V_7 -> V_84 -> V_126 . V_214 & V_218 ) )
F_3 ( V_7 , L_79 ) ;
if ( V_7 -> V_131 )
F_3 ( V_7 , L_80 ) ;
goto V_225;
case F_91 ( struct V_207 , V_226 ) :
V_74 = F_88 ( V_7 , V_148 ) ;
if ( ! V_74 )
F_3 ( V_7 , L_81 , V_148 ) ;
F_29 ( V_74 -> V_93 , L_82 , 8 ) ;
goto V_222;
case F_91 ( struct V_207 , V_85 ) :
F_3 ( V_7 , L_83 ) ;
case sizeof( struct V_207 )
+ F_91 ( struct V_227 , V_228 ) :
if ( strcmp ( V_7 -> V_14 , L_84 ) == 0 ) {
char V_229 = V_148 ;
F_29 ( V_113 , & V_229 , 1 ) ;
goto V_225;
}
default:
F_3 ( V_7 , L_85 , V_145 ) ;
}
V_211:
if ( ! ( V_7 -> V_84 -> V_126 . V_214 & V_219 ) )
F_3 ( V_7 , L_86 ) ;
if ( V_7 -> V_84 -> V_126 . V_214 & V_218 )
F_3 ( V_7 , L_87 ) ;
V_225:
if ( V_147 != 0xFFFFFFFF ) {
F_3 ( V_7 , L_88 ,
V_145 , F_82 ( V_195 ) ) ;
return;
}
memcpy ( ( char * ) V_7 -> V_84 + V_145 , & V_148 , 4 ) ;
return;
V_222:
if ( V_147 != 0xFFFF )
F_3 ( V_7 , L_89 ,
V_145 , F_82 ( V_195 ) ) ;
memcpy ( ( char * ) V_7 -> V_84 + V_145 , & V_148 , 2 ) ;
return;
V_216:
if ( V_147 != 0xFF )
F_3 ( V_7 , L_90 ,
V_145 , F_82 ( V_195 ) ) ;
memcpy ( ( char * ) V_7 -> V_84 + V_145 , & V_148 , 1 ) ;
return;
}
static T_8 F_77 ( struct V_6 * V_7 , T_8 V_145 , T_8 V_147 )
{
T_9 V_85 ;
T_8 V_148 = 0 ;
switch ( V_145 ) {
case F_91 ( struct V_207 , V_126 . V_208 ) :
case F_91 ( struct V_207 , V_126 . V_209 ) :
case F_91 ( struct V_207 , V_126 . V_212 ) :
case F_91 ( struct V_207 , V_126 . V_213 ) :
if ( ! ( V_7 -> V_84 -> V_126 . V_214 & V_219 ) )
F_3 ( V_7 ,
L_91 ) ;
goto V_230;
case F_91 ( struct V_207 , V_126 . V_231 ) :
F_3 ( V_7 , L_92 ) ;
case F_91 ( struct V_207 , V_126 . V_232 ) :
goto V_233;
case F_91 ( struct V_207 , V_126 . V_214 ) :
V_7 -> V_131 = false ;
goto V_234;
case F_91 ( struct V_207 , V_126 . V_235 ) :
goto V_234;
case F_91 ( struct V_207 , V_226 ) :
if ( ! ( V_7 -> V_84 -> V_126 . V_214 & V_217 ) )
F_3 ( V_7 , L_93 ) ;
goto V_233;
case F_91 ( struct V_207 , V_85 ) :
if ( V_147 != 0xFF )
F_3 ( V_7 , L_94 ,
V_145 , F_82 ( V_195 ) ) ;
V_85 = V_7 -> V_84 -> V_85 ;
V_7 -> V_84 -> V_85 = 0 ;
return V_85 ;
case F_91 ( struct V_207 , V_236 ) :
F_3 ( V_7 , L_95 , F_82 ( V_195 ) ) ;
default:
if ( V_145 > V_7 -> V_160 - 4 )
F_3 ( V_7 , L_96 , F_82 ( V_195 ) ) ;
if ( ! ( V_7 -> V_84 -> V_126 . V_214 & V_219 ) )
F_3 ( V_7 ,
L_97 ) ;
if ( V_147 == 0xFFFFFFFF )
goto V_230;
else if ( V_147 == 0xFFFF )
goto V_233;
else
goto V_234;
}
V_230:
if ( V_147 != 0xFFFFFFFF )
F_3 ( V_7 , L_98 ,
V_145 , F_82 ( V_195 ) ) ;
memcpy ( & V_148 , ( char * ) V_7 -> V_84 + V_145 , 4 ) ;
return V_148 ;
V_233:
if ( V_147 != 0xFFFF )
F_3 ( V_7 , L_99 ,
V_145 , F_82 ( V_195 ) ) ;
memcpy ( & V_148 , ( char * ) V_7 -> V_84 + V_145 , 2 ) ;
return V_148 ;
V_234:
if ( V_147 != 0xFF )
F_3 ( V_7 , L_100 ,
V_145 , F_82 ( V_195 ) ) ;
memcpy ( & V_148 , ( char * ) V_7 -> V_84 + V_145 , 1 ) ;
return V_148 ;
}
static void F_96 ( unsigned long V_196 , const T_9 * V_186 )
{
T_8 V_148 , V_145 , V_147 = 0xFFFFFFFF , V_188 = 0 ;
struct V_6 * V_7 = F_87 ( V_196 , & V_145 ) ;
unsigned long args [] = { V_187 , 14 } ;
if ( ! V_7 ) {
F_44 ( L_101 , V_196 ) ;
goto V_237;
}
if ( V_186 [ 0 ] == 0x66 ) {
V_147 = 0xFFFF ;
V_188 ++ ;
}
if ( V_186 [ V_188 ] == 0x89 ) {
V_148 = F_81 ( ( V_186 [ V_188 + 1 ] >> 3 ) & 0x7 , V_147 ) ;
F_75 ( V_7 , V_145 , V_148 , V_147 ) ;
V_188 += 2 + F_85 ( V_186 [ V_188 + 1 ] ) ;
} else if ( V_186 [ V_188 ] == 0x8b ) {
V_148 = F_77 ( V_7 , V_145 , V_147 ) ;
F_83 ( ( V_186 [ V_188 + 1 ] >> 3 ) & 0x7 , V_148 , V_147 ) ;
V_188 += 2 + F_85 ( V_186 [ V_188 + 1 ] ) ;
} else if ( V_186 [ 0 ] == 0x88 ) {
V_147 = 0xff ;
V_148 = F_81 ( ( V_186 [ 1 ] >> 3 ) & 0x7 , V_147 ) ;
F_75 ( V_7 , V_145 , V_148 , V_147 ) ;
V_188 = 2 + F_85 ( V_186 [ 1 ] ) ;
} else if ( V_186 [ 0 ] == 0x8a ) {
V_147 = 0xff ;
V_148 = F_77 ( V_7 , V_145 , V_147 ) ;
F_83 ( ( V_186 [ 1 ] >> 3 ) & 0x7 , V_148 , V_147 ) ;
V_188 = 2 + F_85 ( V_186 [ 1 ] ) ;
} else {
F_44 ( L_102
L_103 ,
V_196 , V_186 [ 0 ] , V_186 [ 1 ] , V_186 [ 2 ] , V_186 [ 3 ] , F_82 ( V_195 ) ) ;
V_237:
if ( F_29 ( V_66 , args , sizeof( args ) ) < 0 )
F_8 ( 1 , L_104 ,
F_82 ( V_195 ) ) ;
return;
}
F_84 ( V_195 , F_82 ( V_195 ) + V_188 ) ;
}
static void F_97 ( struct V_6 * V_77 ,
void (* V_120)( struct V_73 * ) ,
const char * V_14 )
{
struct V_73 * * V_4 , * V_74 = malloc ( sizeof( * V_74 ) ) ;
V_74 -> V_71 = NULL ;
V_74 -> V_127 = 0 ;
V_74 -> V_77 = V_77 ;
V_74 -> V_14 = V_14 ;
V_74 -> V_120 = V_120 ;
V_74 -> V_128 = ( V_129 ) - 1 ;
F_59 ( V_74 ) ;
V_74 -> V_98 . V_224 = 0 ;
V_74 -> V_77 -> V_84 -> V_126 . V_232 ++ ;
for ( V_4 = & V_77 -> V_74 ; * V_4 ; V_4 = & ( * V_4 ) -> V_71 ) ;
* V_4 = V_74 ;
}
static void F_98 ( struct V_6 * V_77 , unsigned V_238 )
{
V_77 -> V_210 |= ( 1ULL << V_238 ) ;
}
static void F_99 ( struct V_6 * V_77 )
{
V_77 -> V_197 = F_14 ( V_77 -> V_160 ) ;
V_77 -> V_78 . V_159 [ 0 ] = V_77 -> V_197 ;
assert ( ~ ( V_77 -> V_78 . V_159 [ 0 ] & 0xF ) ) ;
}
static void F_100 ( struct V_6 * V_77 , const void * V_239 , T_1 V_9 )
{
V_77 -> V_160 += V_9 ;
V_77 -> V_84 = realloc ( V_77 -> V_84 , V_77 -> V_160 ) ;
memcpy ( V_77 -> V_84 + 1 , V_239 , V_9 ) ;
V_77 -> V_78 . V_157 . V_158 . V_240
= F_91 ( struct V_98 , V_6 ) ;
assert ( V_77 -> V_78 . V_157 . V_158 . V_240 % 4 == 0 ) ;
V_77 -> V_78 . V_6 . V_161 = V_9 ;
F_99 ( V_77 ) ;
}
static void F_101 ( struct V_241 * V_158 , T_1 V_242 , int type ,
T_1 V_243 , T_1 V_244 , T_9 V_71 )
{
V_158 -> V_245 = V_246 ;
V_158 -> V_240 = V_71 ;
V_158 -> V_247 = V_242 ;
V_158 -> V_248 = type ;
V_158 -> V_159 = 0 ;
memset ( V_158 -> V_236 , 0 , sizeof( V_158 -> V_236 ) ) ;
V_158 -> V_26 = V_243 ;
V_158 -> V_161 = V_244 ;
}
static void F_102 ( struct V_98 * V_134 , T_5 type ,
T_9 V_142 , T_9 V_143 )
{
T_1 V_243 , V_249 ;
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
V_134 -> V_250 = 0x1AF4 ;
V_134 -> V_251 = 0x1040 + type ;
V_134 -> V_142 = V_142 ;
V_134 -> V_143 = V_143 ;
V_134 -> V_252 = 1 ;
V_134 -> V_253 = 0x40 ;
V_134 -> V_79 = V_133 . V_254 ++ ;
V_134 -> V_255 = 0 ;
V_134 -> V_256 = ( 1 << 4 ) ;
V_134 -> V_257 = F_91 ( struct V_98 , V_258 ) ;
assert ( V_134 -> V_257 % 4 == 0 ) ;
V_243 = F_91 ( struct V_207 , V_126 ) ;
V_249 = sizeof( ( (struct V_207 * ) 0 ) -> V_126 ) ;
F_101 ( & V_134 -> V_258 , sizeof( V_134 -> V_258 ) , V_259 ,
V_243 , V_249 ,
F_91 ( struct V_98 , V_226 ) ) ;
V_243 += V_249 ;
V_249 = sizeof( ( (struct V_207 * ) 0 ) -> V_226 ) ;
assert ( V_134 -> V_258 . V_240 % 2 == 0 ) ;
assert ( V_249 >= 2 ) ;
F_101 ( & V_134 -> V_226 . V_158 , sizeof( V_134 -> V_226 ) ,
V_260 ,
V_243 , V_249 ,
F_91 ( struct V_98 , V_85 ) ) ;
V_243 += V_249 ;
V_249 = sizeof( ( (struct V_207 * ) 0 ) -> V_85 ) ;
F_101 ( & V_134 -> V_85 , sizeof( V_134 -> V_85 ) ,
V_261 ,
V_243 , V_249 ,
F_91 ( struct V_98 , V_157 ) ) ;
F_101 ( & V_134 -> V_157 . V_158 , sizeof( V_134 -> V_157 ) ,
V_262 ,
0 , 0 , 0 ) ;
V_243 += V_249 + sizeof( ( (struct V_207 * ) 0 ) -> V_236 ) ;
assert ( V_243 == sizeof( struct V_207 ) ) ;
F_101 ( & V_134 -> V_6 , sizeof( V_134 -> V_6 ) , V_263 ,
V_243 , 0 , 0 ) ;
}
static struct V_6 * F_103 ( const char * V_14 , T_5 type ,
T_9 V_142 , T_9 V_143 )
{
struct V_6 * V_77 = malloc ( sizeof( * V_77 ) ) ;
V_77 -> V_14 = V_14 ;
V_77 -> V_74 = NULL ;
V_77 -> V_130 = false ;
V_77 -> V_131 = false ;
V_77 -> V_160 = sizeof( struct V_207 ) ;
V_77 -> V_84 = calloc ( 1 , V_77 -> V_160 ) ;
V_77 -> V_210 = ( T_6 ) 1 << V_264 ;
V_77 -> V_96 = 0 ;
if ( V_133 . V_265 + 1 >= V_132 )
F_18 ( 1 , L_105 ) ;
F_102 ( & V_77 -> V_78 , type , V_142 , V_143 ) ;
assert ( ! V_133 . V_134 [ V_133 . V_265 + 1 ] ) ;
V_133 . V_134 [ ++ V_133 . V_265 ] = V_77 ;
return V_77 ;
}
static void F_104 ( void )
{
struct V_6 * V_77 ;
struct V_227 V_239 ;
if ( F_105 ( V_105 , & V_135 ) == 0 ) {
struct V_266 V_267 = V_135 ;
V_267 . V_136 &= ~ ( V_137 | V_138 | V_139 ) ;
F_63 ( V_105 , V_140 , & V_267 ) ;
}
V_77 = F_103 ( L_84 , V_268 , 0x07 , 0x00 ) ;
V_77 -> V_104 = malloc ( sizeof( struct V_103 ) ) ;
( (struct V_103 * ) V_77 -> V_104 ) -> V_106 = 0 ;
F_97 ( V_77 , F_42 , L_106 ) ;
F_97 ( V_77 , F_48 , L_107 ) ;
F_98 ( V_77 , V_269 ) ;
F_100 ( V_77 , & V_239 , sizeof( V_239 ) ) ;
F_21 ( L_108 , V_133 . V_265 ) ;
}
static T_8 F_106 ( const char * V_270 )
{
unsigned int V_271 [ 4 ] ;
if ( sscanf ( V_270 , L_109 , & V_271 [ 0 ] , & V_271 [ 1 ] , & V_271 [ 2 ] , & V_271 [ 3 ] ) != 4 )
F_18 ( 1 , L_110 , V_270 ) ;
return ( V_271 [ 0 ] << 24 ) | ( V_271 [ 1 ] << 16 ) | ( V_271 [ 2 ] << 8 ) | V_271 [ 3 ] ;
}
static void F_107 ( const char * V_272 , unsigned char V_273 [ 6 ] )
{
unsigned int V_274 [ 6 ] ;
if ( sscanf ( V_272 , L_111 ,
& V_274 [ 0 ] , & V_274 [ 1 ] , & V_274 [ 2 ] , & V_274 [ 3 ] , & V_274 [ 4 ] , & V_274 [ 5 ] ) != 6 )
F_18 ( 1 , L_112 , V_272 ) ;
V_273 [ 0 ] = V_274 [ 0 ] ;
V_273 [ 1 ] = V_274 [ 1 ] ;
V_273 [ 2 ] = V_274 [ 2 ] ;
V_273 [ 3 ] = V_274 [ 3 ] ;
V_273 [ 4 ] = V_274 [ 4 ] ;
V_273 [ 5 ] = V_274 [ 5 ] ;
}
static void F_108 ( int V_16 , const char * V_275 , const char * V_276 )
{
int V_277 ;
struct V_278 V_279 ;
if ( ! * V_276 )
F_18 ( 1 , L_113 ) ;
V_277 = F_109 ( V_275 ) ;
if ( ! V_277 )
F_18 ( 1 , L_114 , V_275 ) ;
strncpy ( V_279 . V_280 , V_276 , V_281 ) ;
V_279 . V_280 [ V_281 - 1 ] = '\0' ;
V_279 . V_282 = V_277 ;
if ( F_110 ( V_16 , V_283 , & V_279 ) < 0 )
F_8 ( 1 , L_115 , V_275 , V_276 ) ;
}
static void F_111 ( int V_16 , const char * V_284 , T_8 V_270 )
{
struct V_278 V_279 ;
struct V_285 sin ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
strcpy ( V_279 . V_280 , V_284 ) ;
sin . V_286 = V_287 ;
sin . V_288 . V_289 = F_112 ( V_270 ) ;
memcpy ( & V_279 . V_290 , & sin , sizeof( sin ) ) ;
if ( F_110 ( V_16 , V_291 , & V_279 ) != 0 )
F_8 ( 1 , L_116 , V_284 ) ;
V_279 . V_292 = V_293 ;
if ( F_110 ( V_16 , V_294 , & V_279 ) != 0 )
F_8 ( 1 , L_117 , V_284 ) ;
}
static int F_113 ( char V_284 [ V_281 ] )
{
struct V_278 V_279 ;
int V_295 ;
int V_296 ;
memset ( & V_279 , 0 , sizeof( V_279 ) ) ;
V_296 = F_6 ( L_118 , V_67 ) ;
V_279 . V_292 = V_297 | V_298 | V_299 ;
strcpy ( V_279 . V_280 , L_119 ) ;
if ( F_110 ( V_296 , V_300 , & V_279 ) != 0 )
F_8 ( 1 , L_120 ) ;
if ( F_110 ( V_296 , V_301 ,
V_302 | V_303 | V_304 | V_305 ) != 0 )
F_8 ( 1 , L_121 ) ;
F_110 ( V_296 , V_306 , 1 ) ;
V_295 = sizeof( struct V_307 ) ;
if ( F_110 ( V_296 , V_308 , & V_295 ) != 0 )
F_8 ( 1 , L_122 , V_295 ) ;
memcpy ( V_284 , V_279 . V_280 , V_281 ) ;
return V_296 ;
}
static void F_114 ( char * V_309 )
{
struct V_6 * V_77 ;
struct V_115 * V_115 = malloc ( sizeof( * V_115 ) ) ;
int V_310 ;
T_8 V_311 = V_312 ;
bool V_313 = false ;
char V_284 [ V_281 ] , * V_49 ;
struct V_314 V_239 ;
V_115 -> V_116 = F_113 ( V_284 ) ;
V_77 = F_103 ( L_123 , V_315 , 0x02 , 0x00 ) ;
V_77 -> V_104 = V_115 ;
F_97 ( V_77 , F_56 , L_124 ) ;
F_97 ( V_77 , F_51 , L_125 ) ;
V_310 = F_115 ( V_316 , V_317 , V_318 ) ;
if ( V_310 < 0 )
F_8 ( 1 , L_126 ) ;
if ( ! strncmp ( V_319 , V_309 , strlen ( V_319 ) ) ) {
V_309 += strlen ( V_319 ) ;
V_313 = true ;
}
V_49 = strchr ( V_309 , ':' ) ;
if ( V_49 ) {
F_107 ( V_49 + 1 , V_239 . V_273 ) ;
F_98 ( V_77 , V_320 ) ;
* V_49 = '\0' ;
}
if ( V_313 )
F_108 ( V_310 , V_284 , V_309 ) ;
else
V_311 = F_106 ( V_309 ) ;
F_111 ( V_310 , V_284 , V_311 ) ;
F_98 ( V_77 , V_321 ) ;
F_98 ( V_77 , V_322 ) ;
F_98 ( V_77 , V_323 ) ;
F_98 ( V_77 , V_324 ) ;
F_98 ( V_77 , V_325 ) ;
F_98 ( V_77 , V_326 ) ;
F_98 ( V_77 , V_327 ) ;
F_98 ( V_77 , V_328 ) ;
F_98 ( V_77 , V_97 ) ;
F_100 ( V_77 , & V_239 , sizeof( V_239 ) ) ;
F_13 ( V_310 ) ;
if ( V_313 )
F_21 ( L_127 ,
V_133 . V_265 , V_284 , V_309 ) ;
else
F_21 ( L_128 ,
V_133 . V_265 , V_284 , V_309 ) ;
}
static void F_116 ( struct V_73 * V_74 )
{
struct V_329 * V_330 = V_74 -> V_77 -> V_104 ;
unsigned int V_88 , V_86 , V_87 , V_331 ;
int V_332 , V_4 ;
T_9 * V_112 ;
struct V_333 V_111 ;
struct V_1 V_2 [ V_74 -> V_81 . V_17 ] ;
T_10 V_145 ;
V_88 = F_35 ( V_74 , V_2 , & V_86 , & V_87 ) ;
F_2 ( V_74 -> V_77 , V_2 , V_86 , & V_111 , sizeof( V_111 ) ) ;
V_112 = NULL ;
for ( V_4 = V_86 + V_87 - 1 ; V_4 >= V_86 ; V_4 -- ) {
if ( V_2 [ V_4 ] . V_5 > 0 ) {
V_112 = V_2 [ V_4 ] . V_11 + V_2 [ V_4 ] . V_5 - 1 ;
V_2 [ V_4 ] . V_5 -- ;
break;
}
}
if ( ! V_112 )
F_34 ( V_74 , L_129 ) ;
V_145 = V_111 . V_334 * 512 ;
if ( V_111 . type & V_335 ) {
if ( F_117 ( V_330 -> V_16 , V_145 , V_39 ) != V_145 )
F_8 ( 1 , L_130 , V_111 . V_334 ) ;
V_332 = F_49 ( V_330 -> V_16 , V_2 , V_86 ) ;
F_21 ( L_131 , V_111 . V_334 , V_332 ) ;
if ( V_332 > 0 && V_145 + V_332 > V_330 -> V_9 ) {
F_118 ( V_330 -> V_16 , V_330 -> V_9 ) ;
F_34 ( V_74 , L_132 , V_145 , V_332 ) ;
}
V_331 = sizeof( * V_112 ) ;
* V_112 = ( V_332 >= 0 ? V_336 : V_337 ) ;
} else if ( V_111 . type & V_338 ) {
V_332 = F_119 ( V_330 -> V_16 ) ;
F_21 ( L_133 , V_332 ) ;
V_331 = sizeof( * V_112 ) ;
* V_112 = ( V_332 >= 0 ? V_336 : V_337 ) ;
} else {
if ( F_117 ( V_330 -> V_16 , V_145 , V_39 ) != V_145 )
F_8 ( 1 , L_130 , V_111 . V_334 ) ;
V_332 = F_43 ( V_330 -> V_16 , V_2 + V_86 , V_87 ) ;
if ( V_332 >= 0 ) {
V_331 = sizeof( * V_112 ) + V_332 ;
* V_112 = V_336 ;
} else {
V_331 = sizeof( * V_112 ) ;
* V_112 = V_337 ;
}
}
F_40 ( V_74 , V_88 , V_331 ) ;
}
static void F_120 ( const char * V_339 )
{
struct V_6 * V_77 ;
struct V_329 * V_330 ;
struct V_340 V_239 ;
V_77 = F_103 ( L_134 , V_341 , 0x01 , 0x80 ) ;
F_97 ( V_77 , F_116 , L_135 ) ;
V_330 = V_77 -> V_104 = malloc ( sizeof( * V_330 ) ) ;
V_330 -> V_16 = F_6 ( V_339 , V_67 | V_342 ) ;
V_330 -> V_9 = F_117 ( V_330 -> V_16 , 0 , V_343 ) ;
V_239 . V_344 = F_121 ( V_330 -> V_9 / 512 ) ;
F_98 ( V_77 , V_345 ) ;
V_239 . V_346 = F_122 ( V_122 - 2 ) ;
F_100 ( V_77 , & V_239 , sizeof( struct V_340 ) ) ;
F_21 ( L_136 ,
V_133 . V_265 , F_123 ( V_239 . V_344 ) ) ;
}
static void F_124 ( struct V_73 * V_74 )
{
int V_9 ;
unsigned int V_88 , V_87 , V_86 , V_347 = 0 ;
struct V_348 * V_348 = V_74 -> V_77 -> V_104 ;
struct V_1 V_2 [ V_74 -> V_81 . V_17 ] ;
V_88 = F_35 ( V_74 , V_2 , & V_86 , & V_87 ) ;
if ( V_86 )
F_34 ( V_74 , L_137 ) ;
while ( ! F_1 ( V_2 , V_87 ) ) {
V_9 = F_43 ( V_348 -> V_349 , V_2 , V_87 ) ;
if ( V_9 <= 0 )
F_8 ( 1 , L_138 , V_9 ) ;
F_2 ( V_74 -> V_77 , V_2 , V_87 , NULL , V_9 ) ;
V_347 += V_9 ;
}
F_40 ( V_74 , V_88 , V_347 ) ;
}
static void F_125 ( void )
{
struct V_6 * V_77 ;
struct V_348 * V_348 = malloc ( sizeof( * V_348 ) ) ;
V_348 -> V_349 = F_6 ( L_139 , V_18 ) ;
V_77 = F_103 ( L_140 , V_350 , 0xff , 0 ) ;
V_77 -> V_104 = V_348 ;
F_97 ( V_77 , F_124 , L_106 ) ;
F_99 ( V_77 ) ;
F_21 ( L_141 , V_133 . V_265 ) ;
}
static void F_126 ( void )
{
F_18 ( 1 , L_142
L_143
L_144
L_145 ) ;
}
int main ( int V_351 , char * V_352 [] )
{
unsigned long V_57 = 0 , V_63 , V_353 = 0 ;
int V_4 , V_229 ;
struct V_47 * V_48 ;
const char * V_354 = NULL ;
struct V_355 * V_356 = NULL ;
char * V_357 = NULL ;
V_358 = V_352 ;
V_133 . V_254 = 1 ;
V_174 = 0 ;
for ( V_4 = 1 ; V_4 < V_351 ; V_4 ++ ) {
if ( V_352 [ V_4 ] [ 0 ] != '-' ) {
V_57 = atoi ( V_352 [ V_4 ] ) * 1024 * 1024 ;
V_13 = F_9 ( V_57 / F_11 ()
+ V_359 ) ;
V_65 = V_57 ;
V_360 = V_25 = V_57 + V_359 * F_11 () ;
break;
}
}
F_104 () ;
while ( ( V_229 = F_127 ( V_351 , V_352 , L_146 , V_361 , NULL ) ) != V_362 ) {
switch ( V_229 ) {
case 'v' :
F_21 = true ;
break;
case 't' :
F_114 ( V_363 ) ;
break;
case 'b' :
F_120 ( V_363 ) ;
break;
case 'r' :
F_125 () ;
break;
case 'i' :
V_354 = V_363 ;
break;
case 'u' :
V_356 = F_128 ( V_363 ) ;
if ( ! V_356 )
F_8 ( 1 , L_147 ) ;
break;
case 'c' :
V_357 = V_363 ;
break;
default:
F_44 ( L_148 , V_352 [ V_364 ] ) ;
F_126 () ;
}
}
if ( V_364 + 2 > V_351 )
F_126 () ;
F_21 ( L_149 , V_13 ) ;
F_64 () ;
V_63 = F_23 ( F_6 ( V_352 [ V_364 + 1 ] , V_18 ) ) ;
V_48 = F_4 ( 0 ) ;
if ( V_354 ) {
V_353 = F_25 ( V_354 , V_57 ) ;
V_48 -> V_50 . V_365 = V_57 - V_353 ;
V_48 -> V_50 . V_366 = V_353 ;
V_48 -> V_50 . V_367 = 0xFF ;
}
V_48 -> V_368 = 1 ;
V_48 -> V_369 [ 0 ] = ( (struct V_370 ) { 0 , V_57 , V_371 } ) ;
V_48 -> V_50 . V_372 = F_5 ( V_48 + 1 ) ;
F_27 ( ( char * ) ( V_48 + 1 ) , V_352 + V_364 + 2 ) ;
V_48 -> V_50 . V_373 = 0x1000000 ;
V_48 -> V_50 . V_374 = 0x207 ;
V_48 -> V_50 . V_375 = 1 ;
V_48 -> V_50 . V_376 |= V_377 ;
F_28 ( V_63 ) ;
signal ( V_124 , F_58 ) ;
atexit ( F_62 ) ;
if ( V_357 ) {
if ( F_129 ( V_357 ) != 0 )
F_8 ( 1 , L_150 , V_357 ) ;
if ( F_130 ( L_151 ) != 0 )
F_8 ( 1 , L_152 ) ;
F_21 ( L_153 ) ;
}
if ( V_356 ) {
T_11 V_378 ;
T_12 V_379 ;
V_378 = V_356 -> V_380 ;
V_379 = V_356 -> V_381 ;
if ( F_131 ( V_356 -> V_382 , V_379 ) != 0 )
F_8 ( 1 , L_154 ) ;
if ( F_132 ( V_379 , V_379 , V_379 ) != 0 )
F_8 ( 1 , L_155 ) ;
if ( F_133 ( V_378 , V_378 , V_378 ) != 0 )
F_8 ( 1 , L_156 ) ;
F_21 ( L_157 ) ;
}
F_134 () ;
}
