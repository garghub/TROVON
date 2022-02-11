static unsigned long F_1 ( void )
{
unsigned long V_1 = 0 ;
int V_2 ;
F_2 (cpu) {
if ( F_3 ( V_3 ) )
V_1 += F_4 ( V_2 ) . V_4 ;
else {
struct V_5 * V_6 ;
V_6 = & F_5 ( V_7 , V_2 ) ;
V_1 += V_6 -> V_8 ;
}
}
return V_1 ;
}
static int F_6 ( struct V_9 * V_10 , void * V_11 )
{
unsigned long V_12 ;
int V_13 , V_14 , V_15 ;
int V_16 , V_17 ;
unsigned long V_18 = F_1 () ;
V_13 = ( int ) ( V_19 -> V_20 -> V_21 ) ;
F_7 ( V_10 , L_1 ,
( int ) F_8 () ) ;
F_7 ( V_10 , L_2 ,
( int ) F_8 () ) ;
V_16 = ( int ) F_9 () ;
F_7 ( V_10 , L_3 , V_16 ) ;
V_17 = ( int ) F_10 () ;
F_7 ( V_10 , L_4 , V_17 ) ;
if ( V_13 ) {
V_14 = F_11 () ;
V_15 = F_12 () ;
} else {
V_14 = V_16 * 100 ;
V_15 = V_17 * 100 ;
}
F_7 ( V_10 , L_5 , V_14 ) ;
F_7 ( V_10 , L_6 ,
V_15 ) ;
if ( V_13 ) {
V_12 = F_13 () ;
F_7 ( V_10 , L_7 , ( int ) V_12 ) ;
F_7 ( V_10 , L_8 ,
( int ) ( F_14 ( V_12 ) *
100 ) ) ;
F_7 ( V_10 , L_9 , V_18 ) ;
}
F_7 ( V_10 , L_10 , V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 , void * V_11 )
{
return 0 ;
}
static unsigned int F_15 ( struct V_22 * V_23 )
{
unsigned long V_24 ;
unsigned long V_25 [ V_26 ] ;
V_24 = F_16 ( V_27 , V_25 ) ;
V_23 -> V_28 = V_25 [ 0 ] ;
V_23 -> V_29 = V_25 [ 1 ] ;
V_23 -> V_30 = ( V_25 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_23 -> V_31 = V_25 [ 2 ] & 0xffff ;
V_23 -> V_32 = ( V_25 [ 3 ] >> 6 * 8 ) & 0x01 ;
V_23 -> V_33 = ( V_25 [ 3 ] >> 5 * 8 ) & 0xff ;
V_23 -> V_34 = ( V_25 [ 3 ] >> 4 * 8 ) & 0xff ;
V_23 -> V_35 = ( V_25 [ 3 ] >> 2 * 8 ) & 0xffff ;
V_23 -> V_36 = V_25 [ 3 ] & 0xffff ;
V_23 -> V_37 = V_25 [ 4 ] >> 6 * 8 ;
V_23 -> V_38 = ( V_25 [ 4 ] >> 3 * 8 ) & 0xffffff ;
V_23 -> V_39 = V_25 [ 4 ] & 0xffffff ;
return V_24 ;
}
static unsigned F_17 ( unsigned long * V_40 ,
unsigned long * V_41 )
{
unsigned long V_24 ;
unsigned long V_25 [ V_42 ] ;
V_24 = F_18 ( V_43 , V_25 ) ;
* V_40 = V_25 [ 0 ] ;
* V_41 = V_25 [ 1 ] ;
return V_24 ;
}
static void F_19 ( struct V_9 * V_10 )
{
struct V_22 V_23 ;
struct V_44 * V_45 ;
const int * V_46 ;
int V_24 ;
V_24 = F_15 ( & V_23 ) ;
if ( V_24 )
return;
F_7 ( V_10 , L_11 ,
V_23 . V_28 ) ;
F_7 ( V_10 , L_12 , V_23 . V_30 ) ;
F_7 ( V_10 , L_1 ,
V_23 . V_36 ) ;
if ( F_4 ( 0 ) . V_21 ) {
unsigned long V_40 , V_47 ;
F_7 ( V_10 , L_7 , V_23 . V_31 ) ;
F_7 ( V_10 , L_8 ,
V_23 . V_35 * 100 ) ;
F_17 ( & V_40 , & V_47 ) ;
F_7 ( V_10 , L_13 , V_40 ) ;
F_7 ( V_10 , L_14 , V_47 ) ;
}
F_7 ( V_10 , L_15 ,
V_23 . V_34 ) ;
F_7 ( V_10 , L_16 , V_23 . V_33 ) ;
F_7 ( V_10 , L_17 , V_23 . V_32 ) ;
F_7 ( V_10 , L_18 ,
V_23 . V_29 ) ;
V_45 = F_20 ( L_19 ) ;
if ( V_45 ) {
V_46 = F_21 ( V_45 ,
L_20 ,
NULL ) ;
if ( V_46 && ( * V_46 >= 1 ) ) {
F_7 ( V_10 ,
L_21 ,
V_23 . V_37 ) ;
F_7 ( V_10 , L_22 ,
V_23 . V_38 ) ;
F_7 ( V_10 , L_23 ,
V_23 . V_39 ) ;
}
F_22 ( V_45 ) ;
}
}
static void F_23 ( struct V_9 * V_10 )
{
struct V_48 V_49 ;
int V_24 ;
V_24 = F_24 ( & V_49 ) ;
if ( V_24 )
return;
F_7 ( V_10 , L_24 , V_49 . V_50 ) ;
if ( V_49 . V_51 != - 1 )
F_7 ( V_10 , L_25 ,
V_49 . V_51 ) ;
F_7 ( V_10 , L_26 , V_49 . V_30 ) ;
F_7 ( V_10 , L_27 , V_49 . V_31 ) ;
F_7 ( V_10 , L_28 , V_49 . V_52 ) ;
F_7 ( V_10 , L_29 ,
V_49 . V_53 ) ;
F_7 ( V_10 , L_30 ,
V_49 . V_29 ) ;
if ( V_49 . V_54 != - 1 )
F_7 ( V_10 , L_31 ,
V_49 . V_54 ) ;
F_7 ( V_10 , L_32 ,
V_49 . V_55 ) ;
F_7 ( V_10 , L_33 , V_49 . V_56 ) ;
}
static void F_25 ( struct V_9 * V_10 )
{
struct V_57 V_58 ;
if ( ! F_3 ( V_59 ) )
return;
if ( F_26 ( & V_58 ) )
return;
F_7 ( V_10 , L_34 , V_58 . V_60 ) ;
if ( V_58 . V_61 )
F_7 ( V_10 , L_35 ,
V_58 . V_61 ) ;
if ( V_58 . V_62 )
F_7 ( V_10 , L_36 , V_58 . V_62 ) ;
if ( V_58 . V_63 )
F_7 ( V_10 , L_37 , V_58 . V_63 ) ;
}
static void F_27 ( struct V_9 * V_10 )
{
int V_64 ;
unsigned char * V_65 = F_28 ( V_66 , V_67 ) ;
if ( ! V_65 ) {
F_29 ( V_68 L_38 ,
__FILE__ , V_69 , __LINE__ ) ;
return;
}
F_30 ( & V_70 ) ;
memset ( V_71 , 0 , V_66 ) ;
V_64 = F_31 ( F_32 ( L_39 ) , 3 , 1 ,
NULL ,
V_72 ,
F_33 ( V_71 ) ,
V_73 ) ;
memcpy ( V_65 , V_71 , V_66 ) ;
F_34 ( & V_70 ) ;
if ( V_64 != 0 ) {
F_29 ( V_74
L_40 ,
__FILE__ , V_69 , V_64 ) ;
} else {
int V_75 ;
int V_76 , V_77 ;
char * V_78 = F_35 ( V_66 , V_67 ) ;
if ( ! V_78 ) {
F_29 ( V_68 L_38 ,
__FILE__ , V_69 , __LINE__ ) ;
F_36 ( V_65 ) ;
return;
}
#ifdef F_37
F_29 ( V_74 L_41 ) ;
#endif
V_75 = V_65 [ 0 ] * 256 + V_65 [ 1 ] ;
V_65 += 2 ;
V_77 = 0 ;
V_76 = 0 ;
while ( ( * V_65 ) && ( V_76 < V_75 ) ) {
V_78 [ V_77 ++ ] = V_65 [ V_76 ++ ] ;
if ( ( V_65 [ V_76 ] == ',' )
|| ( V_65 [ V_76 ] == '\0' ) ) {
V_78 [ V_77 ] = '\0' ;
if ( V_77 ) {
F_7 ( V_10 , L_42 , V_78 ) ;
}
memset ( V_78 , 0 , V_66 ) ;
V_76 ++ ;
V_77 = 0 ;
} else if ( V_65 [ V_76 ] == '=' ) {
if ( 0 == strcmp ( V_78 , L_43 ) ) {
strcpy ( V_78 ,
L_44 ) ;
V_77 = strlen ( V_78 ) ;
}
if ( 0 == strcmp ( V_78 , L_45 ) ) {
strcpy ( V_78 ,
L_46 ) ;
V_77 = strlen ( V_78 ) ;
}
}
}
F_36 ( V_78 ) ;
V_65 -= 2 ;
}
F_36 ( V_65 ) ;
}
static int F_38 ( void )
{
struct V_44 * V_79 = NULL ;
int V_80 = 0 ;
while ( ( V_79 = F_39 ( V_79 , L_47 ) ) ) {
#ifdef F_37
F_29 ( V_68 L_48 , V_79 ) ;
#endif
V_80 ++ ;
}
return V_80 ;
}
static void F_40 ( struct V_9 * V_10 )
{
int V_2 ;
unsigned long V_81 = 0 ;
unsigned long V_82 = 0 ;
F_7 ( V_10 , L_49 , F_3 ( V_83 ) ) ;
if ( ! F_3 ( V_83 ) )
return;
F_2 (cpu) {
V_81 += F_4 ( V_2 ) . V_81 ;
V_82 += F_4 ( V_2 ) . V_82 ;
}
F_7 ( V_10 , L_50 , V_81 ) ;
F_7 ( V_10 , L_51 ,
V_82 / V_84 ) ;
F_7 ( V_10 , L_52 , F_41 () ) ;
F_7 ( V_10 , L_53 , F_42 () ) ;
F_7 ( V_10 , L_54 , F_43 () ) ;
}
static void F_44 ( struct V_9 * V_10 )
{
int V_2 ;
unsigned long V_85 = 0 ;
unsigned long V_86 = 0 ;
F_2 (cpu) {
V_85 += F_4 ( V_2 ) . V_87 ;
V_86 += F_4 ( V_2 ) . V_88 ;
}
F_7 ( V_10 , L_55 , V_85 ) ;
F_7 ( V_10 , L_56 , V_86 ) ;
}
static void F_45 ( struct V_9 * V_10 )
{
unsigned long V_25 [ V_42 ] ;
if ( F_18 ( V_89 , V_25 ) == V_90 )
F_7 ( V_10 , L_57 , V_25 [ 0 ] ) ;
}
static int F_46 ( struct V_9 * V_10 , void * V_11 )
{
int V_91 ;
int V_92 ;
struct V_44 * V_93 ;
const int * V_94 = NULL ;
V_93 = F_20 ( L_58 ) ;
if ( V_93 )
V_94 = F_21 ( V_93 , L_59 , NULL ) ;
if ( V_94 == NULL ) {
V_91 = V_95 -> V_96 ;
} else {
V_91 = * ( V_94 + 4 ) ;
}
F_22 ( V_93 ) ;
V_92 = F_38 () ;
if ( F_3 ( V_97 ) ) {
F_27 ( V_10 ) ;
F_19 ( V_10 ) ;
F_23 ( V_10 ) ;
F_25 ( V_10 ) ;
F_40 ( V_10 ) ;
F_44 ( V_10 ) ;
F_7 ( V_10 , L_9 , F_1 () ) ;
} else {
F_7 ( V_10 , L_1 ,
V_91 ) ;
F_7 ( V_10 , L_2 ,
V_91 ) ;
F_7 ( V_10 , L_6 ,
V_91 * 100 ) ;
F_7 ( V_10 , L_5 ,
V_92 * 100 ) ;
}
F_7 ( V_10 , L_3 ,
V_92 ) ;
F_7 ( V_10 , L_4 ,
V_91 ) ;
F_7 ( V_10 , L_10 , F_4 ( 0 ) . V_21 ) ;
F_7 ( V_10 , L_60 , V_98 ) ;
F_45 ( V_10 ) ;
return 0 ;
}
static T_1 F_47 ( T_2 * V_28 , T_3 * V_33 )
{
struct V_22 V_23 ;
T_3 V_99 ;
T_2 V_100 ;
T_1 V_101 ;
V_101 = F_15 ( & V_23 ) ;
if ( V_101 )
return V_101 ;
if ( V_28 ) {
V_99 = V_23 . V_33 ;
V_100 = * V_28 ;
} else if ( V_33 ) {
V_99 = * V_33 ;
V_100 = V_23 . V_28 ;
} else
return - V_102 ;
F_48 ( L_61 ,
V_69 , V_23 . V_28 , V_23 . V_33 ) ;
F_48 ( L_62 ,
V_69 , V_100 , V_99 ) ;
V_101 = F_49 ( V_103 , V_100 , V_99 ) ;
return V_101 ;
}
static T_1 F_50 ( T_2 * V_28 , T_3 * V_33 )
{
struct V_48 V_49 ;
T_2 V_100 ;
T_3 V_99 ;
T_1 V_24 ;
if ( V_28 ) {
V_24 = F_51 ( * V_28 ) ;
if ( V_24 )
return V_24 ;
}
V_24 = F_24 ( & V_49 ) ;
if ( V_24 )
return V_24 ;
if ( V_28 ) {
V_99 = V_49 . V_52 ;
V_100 = * V_28 ;
} else if ( V_33 ) {
V_99 = * V_33 ;
V_100 = V_49 . V_50 ;
} else
return - V_102 ;
F_48 ( L_63 ,
V_69 , V_49 . V_50 , V_49 . V_52 ) ;
F_48 ( L_62 ,
V_69 , V_100 , V_99 ) ;
V_24 = F_49 ( V_104 , V_100 , V_99 ) ;
return V_24 ;
}
static T_1 F_52 ( struct V_105 * V_105 , const char T_4 * V_106 ,
T_5 V_80 , T_6 * V_107 )
{
int V_108 = 64 ;
char V_109 [ V_108 ] ;
char * V_110 ;
T_2 V_100 , * V_111 = & V_100 ;
T_3 V_99 , * V_112 = & V_99 ;
T_1 V_101 ;
if ( ! F_3 ( V_97 ) ||
F_3 ( V_3 ) )
return - V_102 ;
if ( V_80 > V_108 )
return - V_102 ;
if ( F_53 ( V_109 , V_106 , V_80 ) )
return - V_113 ;
V_109 [ V_80 - 1 ] = '\0' ;
V_110 = strchr ( V_109 , '=' ) ;
if ( ! V_110 )
return - V_102 ;
* V_110 ++ = '\0' ;
if ( ! strcmp ( V_109 , L_64 ) ) {
char * V_114 ;
* V_111 = ( T_2 ) F_54 ( V_110 , & V_114 , 10 ) ;
if ( V_114 == V_110 )
return - V_102 ;
V_101 = F_47 ( V_111 , NULL ) ;
} else if ( ! strcmp ( V_109 , L_65 ) ) {
char * V_114 ;
* V_112 = ( T_3 ) F_54 ( V_110 , & V_114 , 10 ) ;
if ( V_114 == V_110 )
return - V_102 ;
V_101 = F_47 ( NULL , V_112 ) ;
} else if ( ! strcmp ( V_109 , L_66 ) ) {
char * V_114 ;
* V_111 = ( T_2 ) F_54 ( V_110 , & V_114 , 10 ) ;
if ( V_114 == V_110 )
return - V_102 ;
V_101 = F_50 ( V_111 , NULL ) ;
} else if ( ! strcmp ( V_109 , L_67 ) ) {
char * V_114 ;
* V_112 = ( T_3 ) F_54 ( V_110 , & V_114 , 10 ) ;
if ( V_114 == V_110 )
return - V_102 ;
V_101 = F_50 ( NULL , V_112 ) ;
} else
return - V_102 ;
if ( V_101 == V_90 || V_101 == V_115 ) {
V_101 = V_80 ;
} else if ( V_101 == V_116 ) {
V_101 = - V_117 ;
} else if ( V_101 == V_118 ) {
V_101 = - V_119 ;
} else if ( V_101 == V_120 ) {
V_101 = - V_102 ;
}
return V_101 ;
}
static int F_46 ( struct V_9 * V_10 , void * V_11 )
{
return 0 ;
}
static T_1 F_52 ( struct V_105 * V_105 , const char T_4 * V_106 ,
T_5 V_80 , T_6 * V_107 )
{
return - V_102 ;
}
static int F_55 ( struct V_9 * V_10 , void * V_11 )
{
struct V_44 * V_121 ;
const char * V_122 = L_68 ;
const char * V_123 = L_68 ;
const char * V_110 ;
const unsigned int * V_124 ;
unsigned int V_125 = 0 ;
F_7 ( V_10 , L_69 , V_126 , V_127 ) ;
V_121 = F_20 ( L_19 ) ;
if ( V_121 ) {
V_110 = F_21 ( V_121 , L_70 , NULL ) ;
if ( V_110 ) {
V_122 = V_110 ;
if ( F_3 ( V_3 ) )
V_122 += 4 ;
}
V_110 = F_21 ( V_121 , L_71 , NULL ) ;
if ( V_110 ) {
V_123 = V_110 ;
if ( F_3 ( V_3 ) )
V_123 += 4 ;
}
V_124 = F_21 ( V_121 , L_72 ,
NULL ) ;
if ( V_124 )
V_125 = * V_124 ;
F_22 ( V_121 ) ;
}
F_7 ( V_10 , L_73 , V_123 ) ;
F_7 ( V_10 , L_74 , V_122 ) ;
F_7 ( V_10 , L_75 , ( int ) V_125 ) ;
if ( F_3 ( V_3 ) )
return F_6 ( V_10 , V_11 ) ;
return F_46 ( V_10 , V_11 ) ;
}
static int F_56 ( struct V_128 * V_128 , struct V_105 * V_105 )
{
return F_57 ( V_105 , F_55 , NULL ) ;
}
static int T_7 F_58 ( void )
{
struct V_129 * V_130 ;
T_8 V_131 = V_132 | V_133 | V_134 ;
if ( F_3 ( V_97 ) &&
! F_3 ( V_3 ) )
V_131 |= V_135 ;
V_130 = F_59 ( L_76 , V_131 , NULL , & V_136 ) ;
if ( ! V_130 ) {
F_29 ( V_68 L_77 ) ;
return - V_119 ;
}
V_137 = V_130 ;
return 0 ;
}
static void T_9 F_60 ( void )
{
if ( V_137 )
F_61 ( L_78 , V_137 -> V_138 ) ;
}
