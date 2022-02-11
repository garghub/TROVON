static void * F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
const char * V_5 )
{
if ( V_2 -> V_6 != V_3 )
F_2 ( 1 , L_1 , V_2 -> V_6 , V_5 ) ;
if ( ( unsigned long ) V_2 -> V_7 % V_4 != 0 )
F_2 ( 1 , L_2 , V_2 -> V_7 , V_5 ) ;
return V_2 -> V_7 ;
}
static bool F_3 ( const struct V_1 V_2 [] , unsigned int V_8 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
if ( V_2 [ V_9 ] . V_6 )
return false ;
return true ;
}
static void F_4 ( struct V_1 V_2 [] , unsigned V_8 , unsigned V_10 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ ) {
unsigned int V_11 ;
V_11 = V_2 [ V_9 ] . V_6 < V_10 ? V_2 [ V_9 ] . V_6 : V_10 ;
V_2 [ V_9 ] . V_7 += V_11 ;
V_2 [ V_9 ] . V_6 -= V_11 ;
V_10 -= V_11 ;
}
assert ( V_10 == 0 ) ;
}
static T_2 * F_5 ( struct V_12 * V_13 )
{
return ( T_2 * ) ( V_13 -> V_14 + 1 )
+ V_13 -> V_15 * sizeof( struct V_16 ) ;
}
static void * F_6 ( unsigned long V_17 )
{
return V_18 + V_17 ;
}
static unsigned long F_7 ( const void * V_17 )
{
return ( V_17 - V_18 ) ;
}
static int F_8 ( const char * V_5 , int V_19 )
{
int V_20 = F_9 ( V_5 , V_19 ) ;
if ( V_20 < 0 )
F_10 ( 1 , L_3 , V_5 ) ;
return V_20 ;
}
static void * F_11 ( unsigned int V_21 )
{
int V_20 = F_8 ( L_4 , V_22 ) ;
void * V_17 ;
V_17 = F_12 ( NULL , F_13 () * ( V_21 + 2 ) ,
V_23 , V_24 , V_20 , 0 ) ;
if ( V_17 == V_25 )
F_10 ( 1 , L_5 , V_21 ) ;
if ( F_14 ( V_17 + F_13 () , F_13 () * V_21 ,
V_26 | V_27 ) == - 1 )
F_10 ( 1 , L_6 , V_21 ) ;
F_15 ( V_20 ) ;
return V_17 + F_13 () ;
}
static void * F_16 ( unsigned int V_21 )
{
void * V_17 = F_6 ( V_28 ) ;
V_28 += V_21 * F_13 () ;
if ( V_28 > V_29 )
F_2 ( 1 , L_7 ) ;
return V_17 ;
}
static void F_17 ( int V_20 , void * V_17 , unsigned long V_30 , unsigned long V_10 )
{
T_3 V_31 ;
if ( F_12 ( V_17 , V_10 , V_26 | V_27 ,
V_32 | V_24 , V_20 , V_30 ) != V_25 )
return;
V_31 = F_18 ( V_20 , V_17 , V_10 , V_30 ) ;
if ( V_31 != V_10 )
F_10 ( 1 , L_8 , V_30 , V_10 , V_31 ) ;
}
static unsigned long F_19 ( int V_33 , const T_4 * V_34 )
{
T_5 V_35 [ V_34 -> V_36 ] ;
unsigned int V_9 ;
if ( V_34 -> V_37 != V_38
|| V_34 -> V_39 != V_40
|| V_34 -> V_41 != sizeof( T_5 )
|| V_34 -> V_36 < 1 || V_34 -> V_36 > 65536U / sizeof( T_5 ) )
F_2 ( 1 , L_9 ) ;
if ( F_20 ( V_33 , V_34 -> V_42 , V_43 ) < 0 )
F_10 ( 1 , L_10 ) ;
if ( F_21 ( V_33 , V_35 , sizeof( V_35 ) ) != sizeof( V_35 ) )
F_10 ( 1 , L_11 ) ;
for ( V_9 = 0 ; V_9 < V_34 -> V_36 ; V_9 ++ ) {
if ( V_35 [ V_9 ] . V_44 != V_45 )
continue;
F_22 ( L_12 ,
V_9 , V_35 [ V_9 ] . V_46 , ( void * ) V_35 [ V_9 ] . V_47 ) ;
F_17 ( V_33 , F_6 ( V_35 [ V_9 ] . V_47 ) ,
V_35 [ V_9 ] . V_48 , V_35 [ V_9 ] . V_49 ) ;
}
return V_34 -> V_50 ;
}
static unsigned long F_23 ( int V_20 )
{
struct V_51 V_52 ;
int V_31 ;
void * V_53 = F_6 ( 0x100000 ) ;
F_20 ( V_20 , 0 , V_43 ) ;
F_21 ( V_20 , & V_52 , sizeof( V_52 ) ) ;
if ( memcmp ( & V_52 . V_54 . V_55 , L_13 , 4 ) != 0 )
F_2 ( 1 , L_14 ) ;
F_20 ( V_20 , ( V_52 . V_54 . V_56 + 1 ) * 512 , V_43 ) ;
while ( ( V_31 = F_21 ( V_20 , V_53 , 65536 ) ) > 0 )
V_53 += V_31 ;
return V_52 . V_54 . V_57 ;
}
static unsigned long F_24 ( int V_20 )
{
T_4 V_54 ;
if ( F_21 ( V_20 , & V_54 , sizeof( V_54 ) ) != sizeof( V_54 ) )
F_10 ( 1 , L_15 ) ;
if ( memcmp ( V_54 . V_58 , V_59 , V_60 ) == 0 )
return F_19 ( V_20 , & V_54 ) ;
return F_23 ( V_20 ) ;
}
static inline unsigned long F_25 ( unsigned long V_17 )
{
return ( ( V_17 + F_13 () - 1 ) & ~ ( F_13 () - 1 ) ) ;
}
static unsigned long F_26 ( const char * V_5 , unsigned long V_61 )
{
int V_62 ;
struct V_63 V_64 ;
unsigned long V_10 ;
V_62 = F_8 ( V_5 , V_22 ) ;
if ( F_27 ( V_62 , & V_64 ) < 0 )
F_10 ( 1 , L_16 , V_5 ) ;
V_10 = F_25 ( V_64 . V_65 ) ;
F_17 ( V_62 , F_6 ( V_61 - V_10 ) , 0 , V_64 . V_65 ) ;
F_15 ( V_62 ) ;
F_22 ( L_17 , V_5 , V_10 , ( void * ) V_61 - V_10 ) ;
return V_10 ;
}
static void F_28 ( char * V_66 , char * args [] )
{
unsigned int V_9 , V_10 = 0 ;
for ( V_9 = 0 ; args [ V_9 ] ; V_9 ++ ) {
if ( V_9 ) {
strcat ( V_66 + V_10 , L_18 ) ;
V_10 ++ ;
}
strcpy ( V_66 + V_10 , args [ V_9 ] ) ;
V_10 += strlen ( args [ V_9 ] ) ;
}
V_66 [ V_10 ] = '\0' ;
}
static void F_29 ( unsigned long V_67 )
{
unsigned long args [] = { V_68 ,
( unsigned long ) V_18 ,
V_28 / F_13 () , V_67 } ;
F_22 ( L_19 ,
V_18 , V_18 + V_28 , V_28 ) ;
V_69 = F_8 ( L_20 , V_70 ) ;
if ( F_30 ( V_69 , args , sizeof( args ) ) < 0 )
F_10 ( 1 , L_21 ) ;
}
static void * F_31 ( unsigned long V_17 , unsigned int V_3 ,
unsigned int line )
{
if ( ( V_17 + V_3 ) > V_28 || ( V_17 + V_3 ) < V_17 )
F_2 ( 1 , L_22 , __FILE__ , line , V_17 ) ;
return F_6 ( V_17 ) ;
}
static unsigned F_32 ( struct V_71 * V_14 ,
unsigned int V_9 , unsigned int V_72 )
{
unsigned int V_73 ;
if ( ! ( V_14 [ V_9 ] . V_19 & V_74 ) )
return V_72 ;
V_73 = V_14 [ V_9 ] . V_73 ;
F_33 () ;
if ( V_73 >= V_72 )
F_2 ( 1 , L_23 , V_73 ) ;
return V_73 ;
}
static void F_34 ( struct V_75 * V_76 )
{
unsigned long V_77 [] = { V_78 , V_76 -> V_79 . V_80 } ;
if ( ! V_76 -> V_81 )
return;
V_76 -> V_81 = 0 ;
if ( V_76 -> V_82 . V_83 -> V_19 & V_84 ) {
return;
}
if ( F_30 ( V_69 , V_77 , sizeof( V_77 ) ) != 0 )
F_10 ( 1 , L_24 , V_76 -> V_79 . V_80 ) ;
}
static unsigned F_35 ( struct V_75 * V_76 ,
struct V_1 V_2 [] ,
unsigned int * V_85 , unsigned int * V_86 )
{
unsigned int V_9 , V_87 , V_72 ;
struct V_71 * V_14 ;
T_6 V_88 = F_36 ( V_76 ) ;
while ( V_88 == V_76 -> V_82 . V_83 -> V_89 ) {
T_7 V_90 ;
F_34 ( V_76 ) ;
V_76 -> V_82 . V_11 -> V_19 &= ~ V_91 ;
F_37 () ;
if ( V_88 != V_76 -> V_82 . V_83 -> V_89 ) {
V_76 -> V_82 . V_11 -> V_19 |= V_91 ;
break;
}
if ( F_21 ( V_76 -> V_92 , & V_90 , sizeof( V_90 ) ) != sizeof( V_90 ) )
F_2 ( 1 , L_25 ) ;
V_76 -> V_82 . V_11 -> V_19 |= V_91 ;
}
if ( ( T_6 ) ( V_76 -> V_82 . V_83 -> V_89 - V_88 ) > V_76 -> V_82 . V_21 )
F_2 ( 1 , L_26 ,
V_88 , V_76 -> V_82 . V_83 -> V_89 ) ;
V_87 = V_76 -> V_82 . V_83 -> V_93 [ V_88 % V_76 -> V_82 . V_21 ] ;
F_36 ( V_76 ) ++ ;
if ( V_87 >= V_76 -> V_82 . V_21 )
F_2 ( 1 , L_27 , V_87 ) ;
* V_85 = * V_86 = 0 ;
V_72 = V_76 -> V_82 . V_21 ;
V_14 = V_76 -> V_82 . V_14 ;
V_9 = V_87 ;
if ( V_14 [ V_9 ] . V_19 & V_94 ) {
if ( V_14 [ V_9 ] . V_10 % sizeof( struct V_71 ) )
F_2 ( 1 , L_28 ) ;
V_72 = V_14 [ V_9 ] . V_10 / sizeof( struct V_71 ) ;
V_14 = F_38 ( V_14 [ V_9 ] . V_17 , V_14 [ V_9 ] . V_10 ) ;
V_9 = 0 ;
}
do {
V_2 [ * V_85 + * V_86 ] . V_6 = V_14 [ V_9 ] . V_10 ;
V_2 [ * V_85 + * V_86 ] . V_7
= F_38 ( V_14 [ V_9 ] . V_17 , V_14 [ V_9 ] . V_10 ) ;
if ( V_14 [ V_9 ] . V_19 & V_95 )
( * V_86 ) ++ ;
else {
if ( * V_86 )
F_2 ( 1 , L_29 ) ;
( * V_85 ) ++ ;
}
if ( * V_85 + * V_86 > V_72 )
F_2 ( 1 , L_30 ) ;
} while ( ( V_9 = F_32 ( V_14 , V_9 , V_72 ) ) != V_72 );
return V_87 ;
}
static void F_39 ( struct V_75 * V_76 , unsigned int V_87 , int V_10 )
{
struct V_96 * V_11 ;
V_11 = & V_76 -> V_82 . V_11 -> V_93 [ V_76 -> V_82 . V_11 -> V_89 % V_76 -> V_82 . V_21 ] ;
V_11 -> V_97 = V_87 ;
V_11 -> V_10 = V_10 ;
F_33 () ;
V_76 -> V_82 . V_11 -> V_89 ++ ;
V_76 -> V_81 ++ ;
}
static void F_40 ( struct V_75 * V_76 , unsigned V_87 , int V_10 )
{
F_39 ( V_76 , V_87 , V_10 ) ;
F_34 ( V_76 ) ;
}
static void F_41 ( struct V_75 * V_76 )
{
int V_10 ;
unsigned int V_87 , V_86 , V_85 ;
struct V_98 * abort = V_76 -> V_13 -> V_99 ;
struct V_1 V_2 [ V_76 -> V_82 . V_21 ] ;
V_87 = F_35 ( V_76 , V_2 , & V_85 , & V_86 ) ;
if ( V_85 )
F_2 ( 1 , L_31 ) ;
V_10 = F_42 ( V_100 , V_2 , V_86 ) ;
if ( V_10 <= 0 ) {
F_43 ( L_32 ) ;
for (; ; )
F_44 () ;
}
F_40 ( V_76 , V_87 , V_10 ) ;
if ( V_10 != 1 || ( ( char * ) V_2 [ 0 ] . V_7 ) [ 0 ] != 3 ) {
abort -> V_101 = 0 ;
return;
}
abort -> V_101 ++ ;
if ( abort -> V_101 == 1 )
F_45 ( & abort -> V_67 , NULL ) ;
else if ( abort -> V_101 == 3 ) {
struct V_102 V_103 ;
F_45 ( & V_103 , NULL ) ;
if ( V_103 . V_104 <= abort -> V_67 . V_104 + 1 )
F_46 ( 0 , V_105 ) ;
abort -> V_101 = 0 ;
}
}
static void F_47 ( struct V_75 * V_76 )
{
unsigned int V_87 , V_106 , V_107 ;
struct V_1 V_2 [ V_76 -> V_82 . V_21 ] ;
V_87 = F_35 ( V_76 , V_2 , & V_106 , & V_107 ) ;
if ( V_107 )
F_2 ( 1 , L_33 ) ;
while ( ! F_3 ( V_2 , V_106 ) ) {
int V_10 = F_48 ( V_108 , V_2 , V_106 ) ;
if ( V_10 <= 0 )
F_10 ( 1 , L_34 , V_10 ) ;
F_4 ( V_2 , V_106 , V_10 ) ;
}
F_39 ( V_76 , V_87 , 0 ) ;
}
static void F_49 ( struct V_75 * V_76 )
{
struct V_109 * V_109 = V_76 -> V_13 -> V_99 ;
unsigned int V_87 , V_106 , V_107 ;
struct V_1 V_2 [ V_76 -> V_82 . V_21 ] ;
V_87 = F_35 ( V_76 , V_2 , & V_106 , & V_107 ) ;
if ( V_107 )
F_2 ( 1 , L_35 ) ;
if ( F_48 ( V_109 -> V_110 , V_2 , V_106 ) < 0 )
F_2 ( 1 , L_36 ) ;
F_39 ( V_76 , V_87 , 0 ) ;
}
static bool F_50 ( int V_20 )
{
T_8 V_111 ;
struct V_102 V_112 = { 0 , 0 } ;
F_51 ( & V_111 ) ;
F_52 ( V_20 , & V_111 ) ;
return F_53 ( V_20 + 1 , & V_111 , NULL , NULL , & V_112 ) != 1 ;
}
static void F_54 ( struct V_75 * V_76 )
{
int V_10 ;
unsigned int V_87 , V_106 , V_107 ;
struct V_1 V_2 [ V_76 -> V_82 . V_21 ] ;
struct V_109 * V_109 = V_76 -> V_13 -> V_99 ;
V_87 = F_35 ( V_76 , V_2 , & V_106 , & V_107 ) ;
if ( V_106 )
F_2 ( 1 , L_37 ) ;
if ( V_76 -> V_81 && F_50 ( V_109 -> V_110 ) )
F_34 ( V_76 ) ;
V_10 = F_42 ( V_109 -> V_110 , V_2 , V_107 ) ;
if ( V_10 <= 0 )
F_10 ( 1 , L_38 ) ;
F_39 ( V_76 , V_87 , V_10 ) ;
}
static int F_55 ( void * V_113 )
{
struct V_75 * V_76 = V_113 ;
for (; ; )
V_76 -> V_114 ( V_76 ) ;
return 0 ;
}
static void F_56 ( int signal )
{
F_46 ( 0 , V_115 ) ;
}
static void F_57 ( struct V_12 * V_13 )
{
struct V_75 * V_76 ;
F_22 ( L_39 , V_13 -> V_5 ) ;
memset ( F_5 ( V_13 ) + V_13 -> V_116 , 0 , V_13 -> V_116 ) ;
signal ( V_117 , V_118 ) ;
for ( V_76 = V_13 -> V_76 ; V_76 ; V_76 = V_76 -> V_73 ) {
if ( V_76 -> V_119 != ( V_120 ) - 1 ) {
F_46 ( V_76 -> V_119 , V_115 ) ;
F_58 ( V_76 -> V_119 , NULL , 0 ) ;
V_76 -> V_119 = ( V_120 ) - 1 ;
}
memset ( V_76 -> V_82 . V_14 , 0 ,
F_59 ( V_76 -> V_79 . V_21 , V_121 ) ) ;
F_36 ( V_76 ) = 0 ;
}
V_13 -> V_122 = false ;
signal ( V_117 , ( void * ) F_56 ) ;
}
static void F_60 ( struct V_75 * V_76 )
{
char * V_123 = malloc ( 32768 ) ;
unsigned long args [] = { V_124 ,
V_76 -> V_79 . V_125 * F_13 () , 0 } ;
V_76 -> V_92 = V_92 ( 0 , 0 ) ;
if ( V_76 -> V_92 < 0 )
F_10 ( 1 , L_40 ) ;
args [ 2 ] = V_76 -> V_92 ;
if ( F_30 ( V_69 , & args , sizeof( args ) ) != 0 )
F_10 ( 1 , L_41 ) ;
V_76 -> V_119 = F_61 ( F_55 , V_123 + 32768 , V_126 | V_117 , V_76 ) ;
if ( V_76 -> V_119 == ( V_120 ) - 1 )
F_10 ( 1 , L_42 ) ;
F_15 ( V_76 -> V_92 ) ;
}
static void F_62 ( struct V_12 * V_13 )
{
unsigned int V_9 ;
struct V_75 * V_76 ;
F_22 ( L_43 , V_13 -> V_5 ) ;
for ( V_9 = 0 ; V_9 < V_13 -> V_116 ; V_9 ++ )
F_22 ( L_44 , F_5 ( V_13 ) [ V_9 ] ) ;
F_22 ( L_45 ) ;
for ( V_9 = 0 ; V_9 < V_13 -> V_116 ; V_9 ++ )
F_22 ( L_44 , F_5 ( V_13 )
[ V_13 -> V_116 + V_9 ] ) ;
for ( V_76 = V_13 -> V_76 ; V_76 ; V_76 = V_76 -> V_73 ) {
if ( V_76 -> V_114 )
F_60 ( V_76 ) ;
}
V_13 -> V_122 = true ;
}
static void F_63 ( void )
{
struct V_12 * V_13 ;
for ( V_13 = V_127 . V_13 ; V_13 ; V_13 = V_13 -> V_73 )
F_57 ( V_13 ) ;
if ( V_128 . V_129 & ( V_130 | V_131 | V_132 ) )
F_64 ( V_100 , V_133 , & V_128 ) ;
}
static void F_65 ( struct V_12 * V_13 )
{
if ( V_13 -> V_14 -> V_134 == 0 )
F_57 ( V_13 ) ;
else if ( V_13 -> V_14 -> V_134 & V_135 ) {
F_43 ( L_46 , V_13 -> V_5 ) ;
if ( V_13 -> V_122 )
F_57 ( V_13 ) ;
} else if ( V_13 -> V_14 -> V_134 & V_136 ) {
if ( ! V_13 -> V_122 )
F_62 ( V_13 ) ;
}
}
static void F_66 ( unsigned long V_17 )
{
struct V_12 * V_9 ;
for ( V_9 = V_127 . V_13 ; V_9 ; V_9 = V_9 -> V_73 ) {
struct V_75 * V_76 ;
if ( F_6 ( V_17 ) == V_9 -> V_14 ) {
F_65 ( V_9 ) ;
return;
}
for ( V_76 = V_9 -> V_76 ; V_76 ; V_76 = V_76 -> V_73 ) {
if ( V_17 != V_76 -> V_79 . V_125 * F_13 () )
continue;
if ( V_9 -> V_122 )
F_2 ( 1 , L_47 , V_9 -> V_5 ) ;
F_62 ( V_9 ) ;
return;
}
}
if ( V_17 >= V_28 )
F_2 ( 1 , L_48 , V_17 ) ;
F_30 ( V_108 , F_6 ( V_17 ) ,
F_67 ( F_6 ( V_17 ) , V_28 - V_17 ) ) ;
}
static T_2 * F_68 ( const struct V_12 * V_13 )
{
return ( void * ) ( V_13 -> V_14 + 1 )
+ V_13 -> V_15 * sizeof( struct V_16 )
+ V_13 -> V_116 * 2 ;
}
static struct V_137 * F_69 ( T_6 type )
{
struct V_137 V_138 = { . type = type } ;
void * V_53 ;
if ( V_127 . V_139 )
V_53 = F_68 ( V_127 . V_139 )
+ V_127 . V_139 -> V_14 -> V_140 ;
else
V_53 = V_127 . V_141 ;
if ( V_53 + sizeof( V_138 ) > ( void * ) V_127 . V_141 + F_13 () )
F_2 ( 1 , L_49 ) ;
return memcpy ( V_53 , & V_138 , sizeof( V_138 ) ) ;
}
static void F_70 ( struct V_12 * V_13 , unsigned int V_142 ,
void (* V_114)( struct V_75 * ) )
{
unsigned int V_143 ;
struct V_75 * * V_9 , * V_76 = malloc ( sizeof( * V_76 ) ) ;
void * V_53 ;
V_143 = ( F_59 ( V_142 , V_121 ) + F_13 () - 1 )
/ F_13 () ;
V_53 = F_16 ( V_143 ) ;
V_76 -> V_73 = NULL ;
V_76 -> V_144 = 0 ;
V_76 -> V_13 = V_13 ;
V_76 -> V_114 = V_114 ;
V_76 -> V_119 = ( V_120 ) - 1 ;
V_76 -> V_79 . V_21 = V_142 ;
V_76 -> V_79 . V_80 = V_127 . V_145 ++ ;
V_76 -> V_79 . V_125 = F_7 ( V_53 ) / F_13 () ;
F_71 ( & V_76 -> V_82 , V_142 , V_53 , V_121 ) ;
assert ( V_13 -> V_14 -> V_140 == 0 && V_13 -> V_14 -> V_116 == 0 ) ;
memcpy ( F_68 ( V_13 ) , & V_76 -> V_79 , sizeof( V_76 -> V_79 ) ) ;
V_13 -> V_15 ++ ;
V_13 -> V_14 -> V_15 ++ ;
F_22 ( L_50 , F_7 ( V_53 ) ) ;
for ( V_9 = & V_13 -> V_76 ; * V_9 ; V_9 = & ( * V_9 ) -> V_73 ) ;
* V_9 = V_76 ;
}
static void F_72 ( struct V_12 * V_13 , unsigned V_146 )
{
T_2 * V_147 = F_5 ( V_13 ) ;
if ( V_13 -> V_14 -> V_116 <= V_146 / V_148 ) {
assert ( V_13 -> V_14 -> V_140 == 0 ) ;
V_13 -> V_116 = V_13 -> V_14 -> V_116 = ( V_146 / V_148 ) + 1 ;
}
V_147 [ V_146 / V_148 ] |= ( 1 << ( V_146 % V_148 ) ) ;
}
static void F_73 ( struct V_12 * V_13 , unsigned V_10 , const void * V_149 )
{
if ( F_68 ( V_13 ) + V_10 > V_127 . V_141 + F_13 () )
F_2 ( 1 , L_49 ) ;
memcpy ( F_68 ( V_13 ) , V_149 , V_10 ) ;
V_13 -> V_14 -> V_140 = V_10 ;
assert ( V_13 -> V_14 -> V_140 == V_10 ) ;
}
static struct V_12 * F_74 ( const char * V_5 , T_6 type )
{
struct V_12 * V_13 = malloc ( sizeof( * V_13 ) ) ;
V_13 -> V_14 = F_69 ( type ) ;
V_13 -> V_5 = V_5 ;
V_13 -> V_76 = NULL ;
V_13 -> V_116 = 0 ;
V_13 -> V_15 = 0 ;
V_13 -> V_122 = false ;
if ( V_127 . V_139 )
V_127 . V_139 -> V_73 = V_13 ;
else
V_127 . V_13 = V_13 ;
V_127 . V_139 = V_13 ;
return V_13 ;
}
static void F_75 ( void )
{
struct V_12 * V_13 ;
if ( F_76 ( V_100 , & V_128 ) == 0 ) {
struct V_150 V_151 = V_128 ;
V_151 . V_129 &= ~ ( V_130 | V_131 | V_132 ) ;
F_64 ( V_100 , V_133 , & V_151 ) ;
}
V_13 = F_74 ( L_51 , V_152 ) ;
V_13 -> V_99 = malloc ( sizeof( struct V_98 ) ) ;
( (struct V_98 * ) V_13 -> V_99 ) -> V_101 = 0 ;
F_70 ( V_13 , V_153 , F_41 ) ;
F_70 ( V_13 , V_153 , F_47 ) ;
F_22 ( L_52 , ++ V_127 . V_154 ) ;
}
static T_9 F_77 ( const char * V_155 )
{
unsigned int V_156 [ 4 ] ;
if ( sscanf ( V_155 , L_53 , & V_156 [ 0 ] , & V_156 [ 1 ] , & V_156 [ 2 ] , & V_156 [ 3 ] ) != 4 )
F_2 ( 1 , L_54 , V_155 ) ;
return ( V_156 [ 0 ] << 24 ) | ( V_156 [ 1 ] << 16 ) | ( V_156 [ 2 ] << 8 ) | V_156 [ 3 ] ;
}
static void F_78 ( const char * V_157 , unsigned char V_158 [ 6 ] )
{
unsigned int V_159 [ 6 ] ;
if ( sscanf ( V_157 , L_55 ,
& V_159 [ 0 ] , & V_159 [ 1 ] , & V_159 [ 2 ] , & V_159 [ 3 ] , & V_159 [ 4 ] , & V_159 [ 5 ] ) != 6 )
F_2 ( 1 , L_56 , V_157 ) ;
V_158 [ 0 ] = V_159 [ 0 ] ;
V_158 [ 1 ] = V_159 [ 1 ] ;
V_158 [ 2 ] = V_159 [ 2 ] ;
V_158 [ 3 ] = V_159 [ 3 ] ;
V_158 [ 4 ] = V_159 [ 4 ] ;
V_158 [ 5 ] = V_159 [ 5 ] ;
}
static void F_79 ( int V_20 , const char * V_160 , const char * V_161 )
{
int V_162 ;
struct V_163 V_164 ;
if ( ! * V_161 )
F_2 ( 1 , L_57 ) ;
V_162 = F_80 ( V_160 ) ;
if ( ! V_162 )
F_2 ( 1 , L_58 , V_160 ) ;
strncpy ( V_164 . V_165 , V_161 , V_166 ) ;
V_164 . V_165 [ V_166 - 1 ] = '\0' ;
V_164 . V_167 = V_162 ;
if ( F_81 ( V_20 , V_168 , & V_164 ) < 0 )
F_10 ( 1 , L_59 , V_160 , V_161 ) ;
}
static void F_82 ( int V_20 , const char * V_169 , T_9 V_155 )
{
struct V_163 V_164 ;
struct V_170 sin ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
strcpy ( V_164 . V_165 , V_169 ) ;
sin . V_171 = V_172 ;
sin . V_173 . V_174 = F_83 ( V_155 ) ;
memcpy ( & V_164 . V_175 , & sin , sizeof( sin ) ) ;
if ( F_81 ( V_20 , V_176 , & V_164 ) != 0 )
F_10 ( 1 , L_60 , V_169 ) ;
V_164 . V_177 = V_178 ;
if ( F_81 ( V_20 , V_179 , & V_164 ) != 0 )
F_10 ( 1 , L_61 , V_169 ) ;
}
static int F_84 ( char V_169 [ V_166 ] )
{
struct V_163 V_164 ;
int V_180 ;
memset ( & V_164 , 0 , sizeof( V_164 ) ) ;
V_180 = F_8 ( L_62 , V_70 ) ;
V_164 . V_177 = V_181 | V_182 | V_183 ;
strcpy ( V_164 . V_165 , L_63 ) ;
if ( F_81 ( V_180 , V_184 , & V_164 ) != 0 )
F_10 ( 1 , L_64 ) ;
if ( F_81 ( V_180 , V_185 ,
V_186 | V_187 | V_188 | V_189 ) != 0 )
F_10 ( 1 , L_65 ) ;
F_81 ( V_180 , V_190 , 1 ) ;
memcpy ( V_169 , V_164 . V_165 , V_166 ) ;
return V_180 ;
}
static void F_85 ( char * V_191 )
{
struct V_12 * V_13 ;
struct V_109 * V_109 = malloc ( sizeof( * V_109 ) ) ;
int V_192 ;
T_9 V_193 = V_194 ;
bool V_195 = false ;
char V_169 [ V_166 ] , * V_53 ;
struct V_196 V_149 ;
V_109 -> V_110 = F_84 ( V_169 ) ;
V_13 = F_74 ( L_66 , V_197 ) ;
V_13 -> V_99 = V_109 ;
F_70 ( V_13 , V_153 , F_54 ) ;
F_70 ( V_13 , V_153 , F_49 ) ;
V_192 = F_86 ( V_198 , V_199 , V_200 ) ;
if ( V_192 < 0 )
F_10 ( 1 , L_67 ) ;
if ( ! strncmp ( V_201 , V_191 , strlen ( V_201 ) ) ) {
V_191 += strlen ( V_201 ) ;
V_195 = true ;
}
V_53 = strchr ( V_191 , ':' ) ;
if ( V_53 ) {
F_78 ( V_53 + 1 , V_149 . V_158 ) ;
F_72 ( V_13 , V_202 ) ;
* V_53 = '\0' ;
}
if ( V_195 )
F_79 ( V_192 , V_169 , V_191 ) ;
else
V_193 = F_77 ( V_191 ) ;
F_82 ( V_192 , V_169 , V_193 ) ;
F_72 ( V_13 , V_203 ) ;
F_72 ( V_13 , V_204 ) ;
F_72 ( V_13 , V_205 ) ;
F_72 ( V_13 , V_206 ) ;
F_72 ( V_13 , V_207 ) ;
F_72 ( V_13 , V_208 ) ;
F_72 ( V_13 , V_209 ) ;
F_72 ( V_13 , V_210 ) ;
F_72 ( V_13 , V_211 ) ;
F_73 ( V_13 , sizeof( V_149 ) , & V_149 ) ;
F_15 ( V_192 ) ;
V_127 . V_154 ++ ;
if ( V_195 )
F_22 ( L_68 ,
V_127 . V_154 , V_169 , V_191 ) ;
else
F_22 ( L_69 ,
V_127 . V_154 , V_169 , V_191 ) ;
}
static void F_87 ( struct V_75 * V_76 )
{
struct V_212 * V_213 = V_76 -> V_13 -> V_99 ;
unsigned int V_87 , V_85 , V_86 , V_214 ;
int V_215 ;
T_2 * V_107 ;
struct V_216 * V_106 ;
struct V_1 V_2 [ V_76 -> V_82 . V_21 ] ;
T_10 V_217 ;
V_87 = F_35 ( V_76 , V_2 , & V_85 , & V_86 ) ;
if ( V_85 == 0 || V_86 == 0 )
F_2 ( 1 , L_70 ,
V_87 , V_85 , V_86 ) ;
V_106 = F_88 ( & V_2 [ 0 ] , struct V_216 ) ;
V_107 = F_88 ( & V_2 [ V_85 + V_86 - 1 ] , T_2 ) ;
V_217 = V_106 -> V_218 * 512 ;
if ( V_106 -> type & V_219 ) {
fprintf ( V_220 , L_71 ) ;
* V_107 = V_221 ;
V_214 = sizeof( * V_107 ) ;
} else if ( V_106 -> type & V_222 ) {
if ( F_89 ( V_213 -> V_20 , V_217 , V_43 ) != V_217 )
F_10 ( 1 , L_72 , V_106 -> V_218 ) ;
V_215 = F_48 ( V_213 -> V_20 , V_2 + 1 , V_85 - 1 ) ;
F_22 ( L_73 , V_106 -> V_218 , V_215 ) ;
if ( V_215 > 0 && V_217 + V_215 > V_213 -> V_10 ) {
F_90 ( V_213 -> V_20 , V_213 -> V_10 ) ;
F_2 ( 1 , L_74 , V_217 , V_215 ) ;
}
V_214 = sizeof( * V_107 ) ;
* V_107 = ( V_215 >= 0 ? V_223 : V_224 ) ;
} else if ( V_106 -> type & V_225 ) {
V_215 = F_91 ( V_213 -> V_20 ) ;
F_22 ( L_75 , V_215 ) ;
V_214 = sizeof( * V_107 ) ;
* V_107 = ( V_215 >= 0 ? V_223 : V_224 ) ;
} else {
if ( F_89 ( V_213 -> V_20 , V_217 , V_43 ) != V_217 )
F_10 ( 1 , L_72 , V_106 -> V_218 ) ;
V_215 = F_42 ( V_213 -> V_20 , V_2 + 1 , V_86 - 1 ) ;
F_22 ( L_76 , V_106 -> V_218 , V_215 ) ;
if ( V_215 >= 0 ) {
V_214 = sizeof( * V_107 ) + V_215 ;
* V_107 = V_223 ;
} else {
V_214 = sizeof( * V_107 ) ;
* V_107 = V_224 ;
}
}
F_39 ( V_76 , V_87 , V_214 ) ;
}
static void F_92 ( const char * V_226 )
{
struct V_12 * V_13 ;
struct V_212 * V_213 ;
struct V_227 V_149 ;
V_13 = F_74 ( L_77 , V_228 ) ;
F_70 ( V_13 , V_153 , F_87 ) ;
V_213 = V_13 -> V_99 = malloc ( sizeof( * V_213 ) ) ;
V_213 -> V_20 = F_8 ( V_226 , V_70 | V_229 ) ;
V_213 -> V_10 = F_89 ( V_213 -> V_20 , 0 , V_230 ) ;
F_72 ( V_13 , V_231 ) ;
V_149 . V_232 = F_93 ( V_213 -> V_10 / 512 ) ;
F_72 ( V_13 , V_233 ) ;
V_149 . V_234 = F_94 ( V_153 - 2 ) ;
F_73 ( V_13 , F_95 ( struct V_227 , V_235 ) , & V_149 ) ;
F_22 ( L_78 ,
++ V_127 . V_154 , F_96 ( V_149 . V_232 ) ) ;
}
static void F_97 ( struct V_75 * V_76 )
{
int V_10 ;
unsigned int V_87 , V_86 , V_85 , V_236 = 0 ;
struct V_237 * V_237 = V_76 -> V_13 -> V_99 ;
struct V_1 V_2 [ V_76 -> V_82 . V_21 ] ;
V_87 = F_35 ( V_76 , V_2 , & V_85 , & V_86 ) ;
if ( V_85 )
F_2 ( 1 , L_79 ) ;
while ( ! F_3 ( V_2 , V_86 ) ) {
V_10 = F_42 ( V_237 -> V_238 , V_2 , V_86 ) ;
if ( V_10 <= 0 )
F_10 ( 1 , L_80 , V_10 ) ;
F_4 ( V_2 , V_86 , V_10 ) ;
V_236 += V_10 ;
}
F_39 ( V_76 , V_87 , V_236 ) ;
}
static void F_98 ( void )
{
struct V_12 * V_13 ;
struct V_237 * V_237 = malloc ( sizeof( * V_237 ) ) ;
V_237 -> V_238 = F_8 ( L_81 , V_22 ) ;
V_13 = F_74 ( L_82 , V_239 ) ;
V_13 -> V_99 = V_237 ;
F_70 ( V_13 , V_153 , F_97 ) ;
F_22 ( L_83 , V_127 . V_154 ++ ) ;
}
static void F_99 ( void )
{
F_2 ( 1 , L_84
L_85
L_86
L_87 ) ;
}
int main ( int V_240 , char * V_241 [] )
{
unsigned long V_61 = 0 , V_67 , V_242 = 0 ;
int V_9 , V_243 ;
struct V_51 * V_52 ;
const char * V_244 = NULL ;
struct V_245 * V_246 = NULL ;
char * V_247 = NULL ;
V_248 = V_241 ;
V_127 . V_139 = NULL ;
V_127 . V_145 = 1 ;
V_249 = 0 ;
for ( V_9 = 1 ; V_9 < V_240 ; V_9 ++ ) {
if ( V_241 [ V_9 ] [ 0 ] != '-' ) {
V_61 = atoi ( V_241 [ V_9 ] ) * 1024 * 1024 ;
V_18 = F_11 ( V_61 / F_13 ()
+ V_250 ) ;
V_28 = V_61 ;
V_29 = V_61 + V_250 * F_13 () ;
V_127 . V_141 = F_16 ( 1 ) ;
break;
}
}
while ( ( V_243 = F_100 ( V_240 , V_241 , L_88 , V_251 , NULL ) ) != V_252 ) {
switch ( V_243 ) {
case 'v' :
F_22 = true ;
break;
case 't' :
F_85 ( V_253 ) ;
break;
case 'b' :
F_92 ( V_253 ) ;
break;
case 'r' :
F_98 () ;
break;
case 'i' :
V_244 = V_253 ;
break;
case 'u' :
V_246 = F_101 ( V_253 ) ;
if ( ! V_246 )
F_10 ( 1 , L_89 ) ;
break;
case 'c' :
V_247 = V_253 ;
break;
default:
F_43 ( L_90 , V_241 [ V_254 ] ) ;
F_99 () ;
}
}
if ( V_254 + 2 > V_240 )
F_99 () ;
F_22 ( L_91 , V_18 ) ;
F_75 () ;
V_67 = F_24 ( F_8 ( V_241 [ V_254 + 1 ] , V_22 ) ) ;
V_52 = F_6 ( 0 ) ;
if ( V_244 ) {
V_242 = F_26 ( V_244 , V_61 ) ;
V_52 -> V_54 . V_255 = V_61 - V_242 ;
V_52 -> V_54 . V_256 = V_242 ;
V_52 -> V_54 . V_257 = 0xFF ;
}
V_52 -> V_258 = 1 ;
V_52 -> V_259 [ 0 ] = ( (struct V_260 ) { 0 , V_61 , V_261 } ) ;
V_52 -> V_54 . V_262 = F_7 ( V_52 + 1 ) ;
F_28 ( ( char * ) ( V_52 + 1 ) , V_241 + V_254 + 2 ) ;
V_52 -> V_54 . V_263 = 0x207 ;
V_52 -> V_54 . V_264 = 1 ;
V_52 -> V_54 . V_265 |= V_266 ;
F_29 ( V_67 ) ;
signal ( V_117 , F_56 ) ;
atexit ( F_63 ) ;
if ( V_247 ) {
if ( F_102 ( V_247 ) != 0 )
F_10 ( 1 , L_92 , V_247 ) ;
if ( F_103 ( L_93 ) != 0 )
F_10 ( 1 , L_94 ) ;
F_22 ( L_95 ) ;
}
if ( V_246 ) {
T_11 V_267 ;
T_12 V_268 ;
V_267 = V_246 -> V_269 ;
V_268 = V_246 -> V_270 ;
if ( F_104 ( V_246 -> V_271 , V_268 ) != 0 )
F_10 ( 1 , L_96 ) ;
if ( F_105 ( V_268 , V_268 , V_268 ) != 0 )
F_10 ( 1 , L_97 ) ;
if ( F_106 ( V_267 , V_267 , V_267 ) != 0 )
F_10 ( 1 , L_98 ) ;
F_22 ( L_99 ) ;
}
F_107 () ;
}
