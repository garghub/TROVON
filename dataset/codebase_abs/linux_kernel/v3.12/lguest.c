static bool F_1 ( const struct V_1 V_2 [] , unsigned int V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
if ( V_2 [ V_4 ] . V_5 )
return false ;
return true ;
}
static void F_2 ( struct V_1 V_2 [] , unsigned V_3 ,
void * V_6 , unsigned V_7 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
unsigned int V_8 ;
V_8 = V_2 [ V_4 ] . V_5 < V_7 ? V_2 [ V_4 ] . V_5 : V_7 ;
if ( V_6 ) {
memcpy ( V_6 , V_2 [ V_4 ] . V_9 , V_8 ) ;
V_6 += V_8 ;
}
V_2 [ V_4 ] . V_9 += V_8 ;
V_2 [ V_4 ] . V_5 -= V_8 ;
V_7 -= V_8 ;
}
if ( V_7 != 0 )
F_3 ( 1 , L_1 ) ;
}
static T_1 * F_4 ( struct V_10 * V_11 )
{
return ( T_1 * ) ( V_11 -> V_12 + 1 )
+ V_11 -> V_13 * sizeof( struct V_14 ) ;
}
static void * F_5 ( unsigned long V_15 )
{
return V_16 + V_15 ;
}
static unsigned long F_6 ( const void * V_15 )
{
return ( V_15 - V_16 ) ;
}
static int F_7 ( const char * V_17 , int V_18 )
{
int V_19 = F_8 ( V_17 , V_18 ) ;
if ( V_19 < 0 )
F_9 ( 1 , L_2 , V_17 ) ;
return V_19 ;
}
static void * F_10 ( unsigned int V_20 )
{
int V_19 = F_7 ( L_3 , V_21 ) ;
void * V_15 ;
V_15 = F_11 ( NULL , F_12 () * ( V_20 + 2 ) ,
V_22 , V_23 , V_19 , 0 ) ;
if ( V_15 == V_24 )
F_9 ( 1 , L_4 , V_20 ) ;
if ( F_13 ( V_15 + F_12 () , F_12 () * V_20 ,
V_25 | V_26 ) == - 1 )
F_9 ( 1 , L_5 , V_20 ) ;
F_14 ( V_19 ) ;
return V_15 + F_12 () ;
}
static void * F_15 ( unsigned int V_20 )
{
void * V_15 = F_5 ( V_27 ) ;
V_27 += V_20 * F_12 () ;
if ( V_27 > V_28 )
F_3 ( 1 , L_6 ) ;
return V_15 ;
}
static void F_16 ( int V_19 , void * V_15 , unsigned long V_29 , unsigned long V_7 )
{
T_2 V_30 ;
if ( F_11 ( V_15 , V_7 , V_25 | V_26 ,
V_31 | V_23 , V_19 , V_29 ) != V_24 )
return;
V_30 = F_17 ( V_19 , V_15 , V_7 , V_29 ) ;
if ( V_30 != V_7 )
F_9 ( 1 , L_7 , V_29 , V_7 , V_30 ) ;
}
static unsigned long F_18 ( int V_32 , const T_3 * V_33 )
{
T_4 V_34 [ V_33 -> V_35 ] ;
unsigned int V_4 ;
if ( V_33 -> V_36 != V_37
|| V_33 -> V_38 != V_39
|| V_33 -> V_40 != sizeof( T_4 )
|| V_33 -> V_35 < 1 || V_33 -> V_35 > 65536U / sizeof( T_4 ) )
F_3 ( 1 , L_8 ) ;
if ( F_19 ( V_32 , V_33 -> V_41 , V_42 ) < 0 )
F_9 ( 1 , L_9 ) ;
if ( F_20 ( V_32 , V_34 , sizeof( V_34 ) ) != sizeof( V_34 ) )
F_9 ( 1 , L_10 ) ;
for ( V_4 = 0 ; V_4 < V_33 -> V_35 ; V_4 ++ ) {
if ( V_34 [ V_4 ] . V_43 != V_44 )
continue;
F_21 ( L_11 ,
V_4 , V_34 [ V_4 ] . V_45 , ( void * ) V_34 [ V_4 ] . V_46 ) ;
F_16 ( V_32 , F_5 ( V_34 [ V_4 ] . V_46 ) ,
V_34 [ V_4 ] . V_47 , V_34 [ V_4 ] . V_48 ) ;
}
return V_33 -> V_49 ;
}
static unsigned long F_22 ( int V_19 )
{
struct V_50 V_51 ;
int V_30 ;
void * V_52 = F_5 ( 0x100000 ) ;
F_19 ( V_19 , 0 , V_42 ) ;
F_20 ( V_19 , & V_51 , sizeof( V_51 ) ) ;
if ( memcmp ( & V_51 . V_53 . V_54 , L_12 , 4 ) != 0 )
F_3 ( 1 , L_13 ) ;
F_19 ( V_19 , ( V_51 . V_53 . V_55 + 1 ) * 512 , V_42 ) ;
while ( ( V_30 = F_20 ( V_19 , V_52 , 65536 ) ) > 0 )
V_52 += V_30 ;
return V_51 . V_53 . V_56 ;
}
static unsigned long F_23 ( int V_19 )
{
T_3 V_53 ;
if ( F_20 ( V_19 , & V_53 , sizeof( V_53 ) ) != sizeof( V_53 ) )
F_9 ( 1 , L_14 ) ;
if ( memcmp ( V_53 . V_57 , V_58 , V_59 ) == 0 )
return F_18 ( V_19 , & V_53 ) ;
return F_22 ( V_19 ) ;
}
static inline unsigned long F_24 ( unsigned long V_15 )
{
return ( ( V_15 + F_12 () - 1 ) & ~ ( F_12 () - 1 ) ) ;
}
static unsigned long F_25 ( const char * V_17 , unsigned long V_60 )
{
int V_61 ;
struct V_62 V_63 ;
unsigned long V_7 ;
V_61 = F_7 ( V_17 , V_21 ) ;
if ( F_26 ( V_61 , & V_63 ) < 0 )
F_9 ( 1 , L_15 , V_17 ) ;
V_7 = F_24 ( V_63 . V_64 ) ;
F_16 ( V_61 , F_5 ( V_60 - V_7 ) , 0 , V_63 . V_64 ) ;
F_14 ( V_61 ) ;
F_21 ( L_16 , V_17 , V_7 , ( void * ) V_60 - V_7 ) ;
return V_7 ;
}
static void F_27 ( char * V_65 , char * args [] )
{
unsigned int V_4 , V_7 = 0 ;
for ( V_4 = 0 ; args [ V_4 ] ; V_4 ++ ) {
if ( V_4 ) {
strcat ( V_65 + V_7 , L_17 ) ;
V_7 ++ ;
}
strcpy ( V_65 + V_7 , args [ V_4 ] ) ;
V_7 += strlen ( args [ V_4 ] ) ;
}
V_65 [ V_7 ] = '\0' ;
}
static void F_28 ( unsigned long V_66 )
{
unsigned long args [] = { V_67 ,
( unsigned long ) V_16 ,
V_27 / F_12 () , V_66 } ;
F_21 ( L_18 ,
V_16 , V_16 + V_27 , V_27 ) ;
V_68 = F_7 ( L_19 , V_69 ) ;
if ( F_29 ( V_68 , args , sizeof( args ) ) < 0 )
F_9 ( 1 , L_20 ) ;
}
static void * F_30 ( unsigned long V_15 , unsigned int V_70 ,
unsigned int line )
{
if ( ( V_15 + V_70 ) > V_27 || ( V_15 + V_70 ) < V_15 )
F_3 ( 1 , L_21 , __FILE__ , line , V_15 ) ;
return F_5 ( V_15 ) ;
}
static unsigned F_31 ( struct V_71 * V_12 ,
unsigned int V_4 , unsigned int V_72 )
{
unsigned int V_73 ;
if ( ! ( V_12 [ V_4 ] . V_18 & V_74 ) )
return V_72 ;
V_73 = V_12 [ V_4 ] . V_73 ;
F_32 () ;
if ( V_73 >= V_72 )
F_3 ( 1 , L_22 , V_73 ) ;
return V_73 ;
}
static void F_33 ( struct V_75 * V_76 )
{
unsigned long V_77 [] = { V_78 , V_76 -> V_79 . V_80 } ;
if ( ! V_76 -> V_81 )
return;
V_76 -> V_81 = 0 ;
if ( V_76 -> V_82 . V_83 -> V_18 & V_84 ) {
return;
}
if ( F_29 ( V_68 , V_77 , sizeof( V_77 ) ) != 0 )
F_9 ( 1 , L_23 , V_76 -> V_79 . V_80 ) ;
}
static unsigned F_34 ( struct V_75 * V_76 ,
struct V_1 V_2 [] ,
unsigned int * V_85 , unsigned int * V_86 )
{
unsigned int V_4 , V_87 , V_72 ;
struct V_71 * V_12 ;
T_5 V_88 = F_35 ( V_76 ) ;
while ( V_88 == V_76 -> V_82 . V_83 -> V_89 ) {
T_6 V_90 ;
F_33 ( V_76 ) ;
V_76 -> V_82 . V_8 -> V_18 &= ~ V_91 ;
F_36 () ;
if ( V_88 != V_76 -> V_82 . V_83 -> V_89 ) {
V_76 -> V_82 . V_8 -> V_18 |= V_91 ;
break;
}
if ( F_20 ( V_76 -> V_92 , & V_90 , sizeof( V_90 ) ) != sizeof( V_90 ) )
F_3 ( 1 , L_24 ) ;
V_76 -> V_82 . V_8 -> V_18 |= V_91 ;
}
if ( ( T_5 ) ( V_76 -> V_82 . V_83 -> V_89 - V_88 ) > V_76 -> V_82 . V_20 )
F_3 ( 1 , L_25 ,
V_88 , V_76 -> V_82 . V_83 -> V_89 ) ;
F_37 () ;
V_87 = V_76 -> V_82 . V_83 -> V_93 [ V_88 % V_76 -> V_82 . V_20 ] ;
F_35 ( V_76 ) ++ ;
if ( V_87 >= V_76 -> V_82 . V_20 )
F_3 ( 1 , L_26 , V_87 ) ;
* V_85 = * V_86 = 0 ;
V_72 = V_76 -> V_82 . V_20 ;
V_12 = V_76 -> V_82 . V_12 ;
V_4 = V_87 ;
if ( V_12 [ V_4 ] . V_18 & V_94 ) {
if ( V_12 [ V_4 ] . V_7 % sizeof( struct V_71 ) )
F_3 ( 1 , L_27 ) ;
V_72 = V_12 [ V_4 ] . V_7 / sizeof( struct V_71 ) ;
V_12 = F_38 ( V_12 [ V_4 ] . V_15 , V_12 [ V_4 ] . V_7 ) ;
V_4 = 0 ;
}
do {
V_2 [ * V_85 + * V_86 ] . V_5 = V_12 [ V_4 ] . V_7 ;
V_2 [ * V_85 + * V_86 ] . V_9
= F_38 ( V_12 [ V_4 ] . V_15 , V_12 [ V_4 ] . V_7 ) ;
if ( V_12 [ V_4 ] . V_18 & V_95 )
( * V_86 ) ++ ;
else {
if ( * V_86 )
F_3 ( 1 , L_28 ) ;
( * V_85 ) ++ ;
}
if ( * V_85 + * V_86 > V_72 )
F_3 ( 1 , L_29 ) ;
} while ( ( V_4 = F_31 ( V_12 , V_4 , V_72 ) ) != V_72 );
return V_87 ;
}
static void F_39 ( struct V_75 * V_76 , unsigned int V_87 , int V_7 )
{
struct V_96 * V_8 ;
V_8 = & V_76 -> V_82 . V_8 -> V_93 [ V_76 -> V_82 . V_8 -> V_89 % V_76 -> V_82 . V_20 ] ;
V_8 -> V_97 = V_87 ;
V_8 -> V_7 = V_7 ;
F_32 () ;
V_76 -> V_82 . V_8 -> V_89 ++ ;
V_76 -> V_81 ++ ;
}
static void F_40 ( struct V_75 * V_76 , unsigned V_87 , int V_7 )
{
F_39 ( V_76 , V_87 , V_7 ) ;
F_33 ( V_76 ) ;
}
static void F_41 ( struct V_75 * V_76 )
{
int V_7 ;
unsigned int V_87 , V_86 , V_85 ;
struct V_98 * abort = V_76 -> V_11 -> V_99 ;
struct V_1 V_2 [ V_76 -> V_82 . V_20 ] ;
V_87 = F_34 ( V_76 , V_2 , & V_85 , & V_86 ) ;
if ( V_85 )
F_3 ( 1 , L_30 ) ;
V_7 = F_42 ( V_100 , V_2 , V_86 ) ;
if ( V_7 <= 0 ) {
F_43 ( L_31 ) ;
for (; ; )
F_44 () ;
}
F_40 ( V_76 , V_87 , V_7 ) ;
if ( V_7 != 1 || ( ( char * ) V_2 [ 0 ] . V_9 ) [ 0 ] != 3 ) {
abort -> V_101 = 0 ;
return;
}
abort -> V_101 ++ ;
if ( abort -> V_101 == 1 )
F_45 ( & abort -> V_66 , NULL ) ;
else if ( abort -> V_101 == 3 ) {
struct V_102 V_103 ;
F_45 ( & V_103 , NULL ) ;
if ( V_103 . V_104 <= abort -> V_66 . V_104 + 1 )
F_46 ( 0 , V_105 ) ;
abort -> V_101 = 0 ;
}
}
static void F_47 ( struct V_75 * V_76 )
{
unsigned int V_87 , V_106 , V_107 ;
struct V_1 V_2 [ V_76 -> V_82 . V_20 ] ;
V_87 = F_34 ( V_76 , V_2 , & V_106 , & V_107 ) ;
if ( V_107 )
F_3 ( 1 , L_32 ) ;
while ( ! F_1 ( V_2 , V_106 ) ) {
int V_7 = F_48 ( V_108 , V_2 , V_106 ) ;
if ( V_7 <= 0 ) {
F_49 ( L_33 , V_7 , V_109 ) ;
break;
}
F_2 ( V_2 , V_106 , NULL , V_7 ) ;
}
F_39 ( V_76 , V_87 , 0 ) ;
}
static void F_50 ( struct V_75 * V_76 )
{
struct V_110 * V_110 = V_76 -> V_11 -> V_99 ;
unsigned int V_87 , V_106 , V_107 ;
struct V_1 V_2 [ V_76 -> V_82 . V_20 ] ;
V_87 = F_34 ( V_76 , V_2 , & V_106 , & V_107 ) ;
if ( V_107 )
F_3 ( 1 , L_34 ) ;
if ( F_48 ( V_110 -> V_111 , V_2 , V_106 ) < 0 )
F_43 ( L_35 , V_109 ) ;
F_39 ( V_76 , V_87 , 0 ) ;
}
static bool F_51 ( int V_19 )
{
T_7 V_112 ;
struct V_102 V_113 = { 0 , 0 } ;
F_52 ( & V_112 ) ;
F_53 ( V_19 , & V_112 ) ;
return F_54 ( V_19 + 1 , & V_112 , NULL , NULL , & V_113 ) != 1 ;
}
static void F_55 ( struct V_75 * V_76 )
{
int V_7 ;
unsigned int V_87 , V_106 , V_107 ;
struct V_1 V_2 [ V_76 -> V_82 . V_20 ] ;
struct V_110 * V_110 = V_76 -> V_11 -> V_99 ;
V_87 = F_34 ( V_76 , V_2 , & V_106 , & V_107 ) ;
if ( V_106 )
F_3 ( 1 , L_36 ) ;
if ( V_76 -> V_81 && F_51 ( V_110 -> V_111 ) )
F_33 ( V_76 ) ;
V_7 = F_42 ( V_110 -> V_111 , V_2 , V_107 ) ;
if ( V_7 <= 0 )
F_49 ( L_37 , V_109 ) ;
F_39 ( V_76 , V_87 , V_7 ) ;
}
static int F_56 ( void * V_114 )
{
struct V_75 * V_76 = V_114 ;
for (; ; )
V_76 -> V_115 ( V_76 ) ;
return 0 ;
}
static void F_57 ( int signal )
{
F_46 ( 0 , V_116 ) ;
}
static void F_58 ( struct V_10 * V_11 )
{
struct V_75 * V_76 ;
F_21 ( L_38 , V_11 -> V_17 ) ;
memset ( F_4 ( V_11 ) + V_11 -> V_117 , 0 , V_11 -> V_117 ) ;
signal ( V_118 , V_119 ) ;
for ( V_76 = V_11 -> V_76 ; V_76 ; V_76 = V_76 -> V_73 ) {
if ( V_76 -> V_120 != ( V_121 ) - 1 ) {
F_46 ( V_76 -> V_120 , V_116 ) ;
F_59 ( V_76 -> V_120 , NULL , 0 ) ;
V_76 -> V_120 = ( V_121 ) - 1 ;
}
memset ( V_76 -> V_82 . V_12 , 0 ,
F_60 ( V_76 -> V_79 . V_20 , V_122 ) ) ;
F_35 ( V_76 ) = 0 ;
}
V_11 -> V_123 = false ;
signal ( V_118 , ( void * ) F_57 ) ;
}
static void F_61 ( struct V_75 * V_76 )
{
char * V_124 = malloc ( 32768 ) ;
unsigned long args [] = { V_125 ,
V_76 -> V_79 . V_126 * F_12 () , 0 } ;
V_76 -> V_92 = V_92 ( 0 , 0 ) ;
if ( V_76 -> V_92 < 0 )
F_9 ( 1 , L_39 ) ;
args [ 2 ] = V_76 -> V_92 ;
if ( F_29 ( V_68 , & args , sizeof( args ) ) != 0 )
F_9 ( 1 , L_40 ) ;
V_76 -> V_120 = F_62 ( F_56 , V_124 + 32768 , V_127 | V_118 , V_76 ) ;
if ( V_76 -> V_120 == ( V_121 ) - 1 )
F_9 ( 1 , L_41 ) ;
F_14 ( V_76 -> V_92 ) ;
}
static void F_63 ( struct V_10 * V_11 )
{
unsigned int V_4 ;
struct V_75 * V_76 ;
F_21 ( L_42 , V_11 -> V_17 ) ;
for ( V_4 = 0 ; V_4 < V_11 -> V_117 ; V_4 ++ )
F_21 ( L_43 , F_4 ( V_11 ) [ V_4 ] ) ;
F_21 ( L_44 ) ;
for ( V_4 = 0 ; V_4 < V_11 -> V_117 ; V_4 ++ )
F_21 ( L_43 , F_4 ( V_11 )
[ V_11 -> V_117 + V_4 ] ) ;
for ( V_76 = V_11 -> V_76 ; V_76 ; V_76 = V_76 -> V_73 ) {
if ( V_76 -> V_115 )
F_61 ( V_76 ) ;
}
V_11 -> V_123 = true ;
}
static void F_64 ( void )
{
struct V_10 * V_11 ;
for ( V_11 = V_128 . V_11 ; V_11 ; V_11 = V_11 -> V_73 )
F_58 ( V_11 ) ;
if ( V_129 . V_130 & ( V_131 | V_132 | V_133 ) )
F_65 ( V_100 , V_134 , & V_129 ) ;
}
static void F_66 ( struct V_10 * V_11 )
{
if ( V_11 -> V_12 -> V_135 == 0 )
F_58 ( V_11 ) ;
else if ( V_11 -> V_12 -> V_135 & V_136 ) {
F_43 ( L_45 , V_11 -> V_17 ) ;
if ( V_11 -> V_123 )
F_58 ( V_11 ) ;
} else {
if ( V_11 -> V_123 )
F_9 ( 1 , L_46 , V_11 -> V_17 ) ;
F_63 ( V_11 ) ;
}
}
static void F_67 ( unsigned long V_15 )
{
struct V_10 * V_4 ;
for ( V_4 = V_128 . V_11 ; V_4 ; V_4 = V_4 -> V_73 ) {
struct V_75 * V_76 ;
if ( F_5 ( V_15 ) == V_4 -> V_12 ) {
F_66 ( V_4 ) ;
return;
}
for ( V_76 = V_4 -> V_76 ; V_76 ; V_76 = V_76 -> V_73 ) {
if ( V_15 != V_76 -> V_79 . V_126 * F_12 () )
continue;
F_3 ( 1 , L_47 , V_4 -> V_17 ) ;
}
}
if ( V_15 >= V_27 )
F_3 ( 1 , L_48 , V_15 ) ;
F_29 ( V_108 , F_5 ( V_15 ) ,
F_68 ( F_5 ( V_15 ) , V_27 - V_15 ) ) ;
}
static T_1 * F_69 ( const struct V_10 * V_11 )
{
return ( void * ) ( V_11 -> V_12 + 1 )
+ V_11 -> V_13 * sizeof( struct V_14 )
+ V_11 -> V_117 * 2 ;
}
static struct V_137 * F_70 ( T_5 type )
{
struct V_137 V_138 = { . type = type } ;
void * V_52 ;
if ( V_128 . V_139 )
V_52 = F_69 ( V_128 . V_139 )
+ V_128 . V_139 -> V_12 -> V_140 ;
else
V_52 = V_128 . V_141 ;
if ( V_52 + sizeof( V_138 ) > ( void * ) V_128 . V_141 + F_12 () )
F_3 ( 1 , L_49 ) ;
return memcpy ( V_52 , & V_138 , sizeof( V_138 ) ) ;
}
static void F_71 ( struct V_10 * V_11 , unsigned int V_142 ,
void (* V_115)( struct V_75 * ) )
{
unsigned int V_143 ;
struct V_75 * * V_4 , * V_76 = malloc ( sizeof( * V_76 ) ) ;
void * V_52 ;
V_143 = ( F_60 ( V_142 , V_122 ) + F_12 () - 1 )
/ F_12 () ;
V_52 = F_15 ( V_143 ) ;
V_76 -> V_73 = NULL ;
V_76 -> V_144 = 0 ;
V_76 -> V_11 = V_11 ;
V_76 -> V_115 = V_115 ;
V_76 -> V_120 = ( V_121 ) - 1 ;
V_76 -> V_79 . V_20 = V_142 ;
V_76 -> V_79 . V_80 = V_128 . V_145 ++ ;
V_76 -> V_79 . V_126 = F_6 ( V_52 ) / F_12 () ;
F_72 ( & V_76 -> V_82 , V_142 , V_52 , V_122 ) ;
assert ( V_11 -> V_12 -> V_140 == 0 && V_11 -> V_12 -> V_117 == 0 ) ;
memcpy ( F_69 ( V_11 ) , & V_76 -> V_79 , sizeof( V_76 -> V_79 ) ) ;
V_11 -> V_13 ++ ;
V_11 -> V_12 -> V_13 ++ ;
F_21 ( L_50 , F_6 ( V_52 ) ) ;
for ( V_4 = & V_11 -> V_76 ; * V_4 ; V_4 = & ( * V_4 ) -> V_73 ) ;
* V_4 = V_76 ;
}
static void F_73 ( struct V_10 * V_11 , unsigned V_146 )
{
T_1 * V_147 = F_4 ( V_11 ) ;
if ( V_11 -> V_12 -> V_117 <= V_146 / V_148 ) {
assert ( V_11 -> V_12 -> V_140 == 0 ) ;
V_11 -> V_117 = V_11 -> V_12 -> V_117 = ( V_146 / V_148 ) + 1 ;
}
V_147 [ V_146 / V_148 ] |= ( 1 << ( V_146 % V_148 ) ) ;
}
static void F_74 ( struct V_10 * V_11 , unsigned V_7 , const void * V_149 )
{
if ( F_69 ( V_11 ) + V_7 > V_128 . V_141 + F_12 () )
F_3 ( 1 , L_49 ) ;
memcpy ( F_69 ( V_11 ) , V_149 , V_7 ) ;
V_11 -> V_12 -> V_140 = V_7 ;
assert ( V_11 -> V_12 -> V_140 == V_7 ) ;
}
static struct V_10 * F_75 ( const char * V_17 , T_5 type )
{
struct V_10 * V_11 = malloc ( sizeof( * V_11 ) ) ;
V_11 -> V_12 = F_70 ( type ) ;
V_11 -> V_17 = V_17 ;
V_11 -> V_76 = NULL ;
V_11 -> V_117 = 0 ;
V_11 -> V_13 = 0 ;
V_11 -> V_123 = false ;
V_11 -> V_73 = NULL ;
if ( V_128 . V_139 )
V_128 . V_139 -> V_73 = V_11 ;
else
V_128 . V_11 = V_11 ;
V_128 . V_139 = V_11 ;
return V_11 ;
}
static void F_76 ( void )
{
struct V_10 * V_11 ;
if ( F_77 ( V_100 , & V_129 ) == 0 ) {
struct V_150 V_151 = V_129 ;
V_151 . V_130 &= ~ ( V_131 | V_132 | V_133 ) ;
F_65 ( V_100 , V_134 , & V_151 ) ;
}
V_11 = F_75 ( L_51 , V_152 ) ;
V_11 -> V_99 = malloc ( sizeof( struct V_98 ) ) ;
( (struct V_98 * ) V_11 -> V_99 ) -> V_101 = 0 ;
F_71 ( V_11 , V_153 , F_41 ) ;
F_71 ( V_11 , V_153 , F_47 ) ;
F_21 ( L_52 , ++ V_128 . V_154 ) ;
}
static T_8 F_78 ( const char * V_155 )
{
unsigned int V_156 [ 4 ] ;
if ( sscanf ( V_155 , L_53 , & V_156 [ 0 ] , & V_156 [ 1 ] , & V_156 [ 2 ] , & V_156 [ 3 ] ) != 4 )
F_3 ( 1 , L_54 , V_155 ) ;
return ( V_156 [ 0 ] << 24 ) | ( V_156 [ 1 ] << 16 ) | ( V_156 [ 2 ] << 8 ) | V_156 [ 3 ] ;
}
static void F_79 ( const char * V_157 , unsigned char V_158 [ 6 ] )
{
unsigned int V_159 [ 6 ] ;
if ( sscanf ( V_157 , L_55 ,
& V_159 [ 0 ] , & V_159 [ 1 ] , & V_159 [ 2 ] , & V_159 [ 3 ] , & V_159 [ 4 ] , & V_159 [ 5 ] ) != 6 )
F_3 ( 1 , L_56 , V_157 ) ;
V_158 [ 0 ] = V_159 [ 0 ] ;
V_158 [ 1 ] = V_159 [ 1 ] ;
V_158 [ 2 ] = V_159 [ 2 ] ;
V_158 [ 3 ] = V_159 [ 3 ] ;
V_158 [ 4 ] = V_159 [ 4 ] ;
V_158 [ 5 ] = V_159 [ 5 ] ;
}
static void F_80 ( int V_19 , const char * V_160 , const char * V_161 )
{
int V_162 ;
struct V_163 V_164 ;
if ( ! * V_161 )
F_3 ( 1 , L_57 ) ;
V_162 = F_81 ( V_160 ) ;
if ( ! V_162 )
F_3 ( 1 , L_58 , V_160 ) ;
strncpy ( V_164 . V_165 , V_161 , V_166 ) ;
V_164 . V_165 [ V_166 - 1 ] = '\0' ;
V_164 . V_167 = V_162 ;
if ( F_82 ( V_19 , V_168 , & V_164 ) < 0 )
F_9 ( 1 , L_59 , V_160 , V_161 ) ;
}
static void F_83 ( int V_19 , const char * V_169 , T_8 V_155 )
{
struct V_163 V_164 ;
struct V_170 sin ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
strcpy ( V_164 . V_165 , V_169 ) ;
sin . V_171 = V_172 ;
sin . V_173 . V_174 = F_84 ( V_155 ) ;
memcpy ( & V_164 . V_175 , & sin , sizeof( sin ) ) ;
if ( F_82 ( V_19 , V_176 , & V_164 ) != 0 )
F_9 ( 1 , L_60 , V_169 ) ;
V_164 . V_177 = V_178 ;
if ( F_82 ( V_19 , V_179 , & V_164 ) != 0 )
F_9 ( 1 , L_61 , V_169 ) ;
}
static int F_85 ( char V_169 [ V_166 ] )
{
struct V_163 V_164 ;
int V_180 ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_180 = F_7 ( L_62 , V_69 ) ;
V_164 . V_177 = V_181 | V_182 | V_183 ;
strcpy ( V_164 . V_165 , L_63 ) ;
if ( F_82 ( V_180 , V_184 , & V_164 ) != 0 )
F_9 ( 1 , L_64 ) ;
if ( F_82 ( V_180 , V_185 ,
V_186 | V_187 | V_188 | V_189 ) != 0 )
F_9 ( 1 , L_65 ) ;
F_82 ( V_180 , V_190 , 1 ) ;
memcpy ( V_169 , V_164 . V_165 , V_166 ) ;
return V_180 ;
}
static void F_86 ( char * V_191 )
{
struct V_10 * V_11 ;
struct V_110 * V_110 = malloc ( sizeof( * V_110 ) ) ;
int V_192 ;
T_8 V_193 = V_194 ;
bool V_195 = false ;
char V_169 [ V_166 ] , * V_52 ;
struct V_196 V_149 ;
V_110 -> V_111 = F_85 ( V_169 ) ;
V_11 = F_75 ( L_66 , V_197 ) ;
V_11 -> V_99 = V_110 ;
F_71 ( V_11 , V_153 , F_55 ) ;
F_71 ( V_11 , V_153 , F_50 ) ;
V_192 = F_87 ( V_198 , V_199 , V_200 ) ;
if ( V_192 < 0 )
F_9 ( 1 , L_67 ) ;
if ( ! strncmp ( V_201 , V_191 , strlen ( V_201 ) ) ) {
V_191 += strlen ( V_201 ) ;
V_195 = true ;
}
V_52 = strchr ( V_191 , ':' ) ;
if ( V_52 ) {
F_79 ( V_52 + 1 , V_149 . V_158 ) ;
F_73 ( V_11 , V_202 ) ;
* V_52 = '\0' ;
}
if ( V_195 )
F_80 ( V_192 , V_169 , V_191 ) ;
else
V_193 = F_78 ( V_191 ) ;
F_83 ( V_192 , V_169 , V_193 ) ;
F_73 ( V_11 , V_203 ) ;
F_73 ( V_11 , V_204 ) ;
F_73 ( V_11 , V_205 ) ;
F_73 ( V_11 , V_206 ) ;
F_73 ( V_11 , V_207 ) ;
F_73 ( V_11 , V_208 ) ;
F_73 ( V_11 , V_209 ) ;
F_73 ( V_11 , V_210 ) ;
F_73 ( V_11 , V_211 ) ;
F_73 ( V_11 , V_212 ) ;
F_74 ( V_11 , sizeof( V_149 ) , & V_149 ) ;
F_14 ( V_192 ) ;
V_128 . V_154 ++ ;
if ( V_195 )
F_21 ( L_68 ,
V_128 . V_154 , V_169 , V_191 ) ;
else
F_21 ( L_69 ,
V_128 . V_154 , V_169 , V_191 ) ;
}
static void F_88 ( struct V_75 * V_76 )
{
struct V_213 * V_214 = V_76 -> V_11 -> V_99 ;
unsigned int V_87 , V_85 , V_86 , V_215 ;
int V_216 , V_4 ;
T_1 * V_107 ;
struct V_217 V_106 ;
struct V_1 V_2 [ V_76 -> V_82 . V_20 ] ;
T_9 V_218 ;
V_87 = F_34 ( V_76 , V_2 , & V_85 , & V_86 ) ;
F_2 ( V_2 , V_85 , & V_106 , sizeof( V_106 ) ) ;
V_107 = NULL ;
for ( V_4 = V_85 + V_86 - 1 ; V_4 >= V_85 ; V_4 -- ) {
if ( V_2 [ V_4 ] . V_5 > 0 ) {
V_107 = V_2 [ V_4 ] . V_9 + V_2 [ V_4 ] . V_5 - 1 ;
V_2 [ V_4 ] . V_5 -- ;
break;
}
}
if ( ! V_107 )
F_3 ( 1 , L_70 ) ;
V_218 = V_106 . V_219 * 512 ;
if ( V_106 . type & V_220 ) {
fprintf ( V_221 , L_71 ) ;
* V_107 = V_222 ;
V_215 = sizeof( * V_107 ) ;
} else if ( V_106 . type & V_223 ) {
if ( F_89 ( V_214 -> V_19 , V_218 , V_42 ) != V_218 )
F_9 ( 1 , L_72 , V_106 . V_219 ) ;
V_216 = F_48 ( V_214 -> V_19 , V_2 , V_85 ) ;
F_21 ( L_73 , V_106 . V_219 , V_216 ) ;
if ( V_216 > 0 && V_218 + V_216 > V_214 -> V_7 ) {
F_90 ( V_214 -> V_19 , V_214 -> V_7 ) ;
F_3 ( 1 , L_74 , V_218 , V_216 ) ;
}
V_215 = sizeof( * V_107 ) ;
* V_107 = ( V_216 >= 0 ? V_224 : V_225 ) ;
} else if ( V_106 . type & V_226 ) {
V_216 = F_91 ( V_214 -> V_19 ) ;
F_21 ( L_75 , V_216 ) ;
V_215 = sizeof( * V_107 ) ;
* V_107 = ( V_216 >= 0 ? V_224 : V_225 ) ;
} else {
if ( F_89 ( V_214 -> V_19 , V_218 , V_42 ) != V_218 )
F_9 ( 1 , L_72 , V_106 . V_219 ) ;
V_216 = F_42 ( V_214 -> V_19 , V_2 + V_85 , V_86 ) ;
if ( V_216 >= 0 ) {
V_215 = sizeof( * V_107 ) + V_216 ;
* V_107 = V_224 ;
} else {
V_215 = sizeof( * V_107 ) ;
* V_107 = V_225 ;
}
}
F_39 ( V_76 , V_87 , V_215 ) ;
}
static void F_92 ( const char * V_227 )
{
struct V_10 * V_11 ;
struct V_213 * V_214 ;
struct V_228 V_149 ;
V_11 = F_75 ( L_76 , V_229 ) ;
F_71 ( V_11 , V_153 , F_88 ) ;
V_214 = V_11 -> V_99 = malloc ( sizeof( * V_214 ) ) ;
V_214 -> V_19 = F_7 ( V_227 , V_69 | V_230 ) ;
V_214 -> V_7 = F_89 ( V_214 -> V_19 , 0 , V_231 ) ;
F_73 ( V_11 , V_232 ) ;
V_149 . V_233 = F_93 ( V_214 -> V_7 / 512 ) ;
F_73 ( V_11 , V_234 ) ;
V_149 . V_235 = F_94 ( V_153 - 2 ) ;
F_74 ( V_11 , F_95 ( struct V_228 , V_236 ) , & V_149 ) ;
F_21 ( L_77 ,
++ V_128 . V_154 , F_96 ( V_149 . V_233 ) ) ;
}
static void F_97 ( struct V_75 * V_76 )
{
int V_7 ;
unsigned int V_87 , V_86 , V_85 , V_237 = 0 ;
struct V_238 * V_238 = V_76 -> V_11 -> V_99 ;
struct V_1 V_2 [ V_76 -> V_82 . V_20 ] ;
V_87 = F_34 ( V_76 , V_2 , & V_85 , & V_86 ) ;
if ( V_85 )
F_3 ( 1 , L_78 ) ;
while ( ! F_1 ( V_2 , V_86 ) ) {
V_7 = F_42 ( V_238 -> V_239 , V_2 , V_86 ) ;
if ( V_7 <= 0 )
F_9 ( 1 , L_79 , V_7 ) ;
F_2 ( V_2 , V_86 , NULL , V_7 ) ;
V_237 += V_7 ;
}
F_39 ( V_76 , V_87 , V_237 ) ;
}
static void F_98 ( void )
{
struct V_10 * V_11 ;
struct V_238 * V_238 = malloc ( sizeof( * V_238 ) ) ;
V_238 -> V_239 = F_7 ( L_80 , V_21 ) ;
V_11 = F_75 ( L_81 , V_240 ) ;
V_11 -> V_99 = V_238 ;
F_71 ( V_11 , V_153 , F_97 ) ;
F_21 ( L_82 , V_128 . V_154 ++ ) ;
}
static void F_99 ( void )
{
F_3 ( 1 , L_83
L_84
L_85
L_86 ) ;
}
int main ( int V_241 , char * V_242 [] )
{
unsigned long V_60 = 0 , V_66 , V_243 = 0 ;
int V_4 , V_244 ;
struct V_50 * V_51 ;
const char * V_245 = NULL ;
struct V_246 * V_247 = NULL ;
char * V_248 = NULL ;
V_249 = V_242 ;
V_128 . V_139 = NULL ;
V_128 . V_145 = 1 ;
V_250 = 0 ;
for ( V_4 = 1 ; V_4 < V_241 ; V_4 ++ ) {
if ( V_242 [ V_4 ] [ 0 ] != '-' ) {
V_60 = atoi ( V_242 [ V_4 ] ) * 1024 * 1024 ;
V_16 = F_10 ( V_60 / F_12 ()
+ V_251 ) ;
V_27 = V_60 ;
V_28 = V_60 + V_251 * F_12 () ;
V_128 . V_141 = F_15 ( 1 ) ;
break;
}
}
while ( ( V_244 = F_100 ( V_241 , V_242 , L_87 , V_252 , NULL ) ) != V_253 ) {
switch ( V_244 ) {
case 'v' :
F_21 = true ;
break;
case 't' :
F_86 ( V_254 ) ;
break;
case 'b' :
F_92 ( V_254 ) ;
break;
case 'r' :
F_98 () ;
break;
case 'i' :
V_245 = V_254 ;
break;
case 'u' :
V_247 = F_101 ( V_254 ) ;
if ( ! V_247 )
F_9 ( 1 , L_88 ) ;
break;
case 'c' :
V_248 = V_254 ;
break;
default:
F_43 ( L_89 , V_242 [ V_255 ] ) ;
F_99 () ;
}
}
if ( V_255 + 2 > V_241 )
F_99 () ;
F_21 ( L_90 , V_16 ) ;
F_76 () ;
V_66 = F_23 ( F_7 ( V_242 [ V_255 + 1 ] , V_21 ) ) ;
V_51 = F_5 ( 0 ) ;
if ( V_245 ) {
V_243 = F_25 ( V_245 , V_60 ) ;
V_51 -> V_53 . V_256 = V_60 - V_243 ;
V_51 -> V_53 . V_257 = V_243 ;
V_51 -> V_53 . V_258 = 0xFF ;
}
V_51 -> V_259 = 1 ;
V_51 -> V_260 [ 0 ] = ( (struct V_261 ) { 0 , V_60 , V_262 } ) ;
V_51 -> V_53 . V_263 = F_6 ( V_51 + 1 ) ;
F_27 ( ( char * ) ( V_51 + 1 ) , V_242 + V_255 + 2 ) ;
V_51 -> V_53 . V_264 = 0x1000000 ;
V_51 -> V_53 . V_265 = 0x207 ;
V_51 -> V_53 . V_266 = 1 ;
V_51 -> V_53 . V_267 |= V_268 ;
F_28 ( V_66 ) ;
signal ( V_118 , F_57 ) ;
atexit ( F_64 ) ;
if ( V_248 ) {
if ( F_102 ( V_248 ) != 0 )
F_9 ( 1 , L_91 , V_248 ) ;
if ( F_103 ( L_92 ) != 0 )
F_9 ( 1 , L_93 ) ;
F_21 ( L_94 ) ;
}
if ( V_247 ) {
T_10 V_269 ;
T_11 V_270 ;
V_269 = V_247 -> V_271 ;
V_270 = V_247 -> V_272 ;
if ( F_104 ( V_247 -> V_273 , V_270 ) != 0 )
F_9 ( 1 , L_95 ) ;
if ( F_105 ( V_270 , V_270 , V_270 ) != 0 )
F_9 ( 1 , L_96 ) ;
if ( F_106 ( V_269 , V_269 , V_269 ) != 0 )
F_9 ( 1 , L_97 ) ;
F_21 ( L_98 ) ;
}
F_107 () ;
}
