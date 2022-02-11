static unsigned long F_1 ( void )
{
unsigned long V_1 = 0 ;
int V_2 ;
F_2 (cpu) {
struct V_3 * V_4 ;
V_4 = & F_3 ( V_5 , V_2 ) ;
V_1 += V_4 -> V_6 ;
}
return V_1 ;
}
static unsigned int F_4 ( struct V_7 * V_8 )
{
unsigned long V_9 ;
unsigned long V_10 [ V_11 ] ;
V_9 = F_5 ( V_12 , V_10 ) ;
V_8 -> V_13 = V_10 [ 0 ] ;
V_8 -> V_14 = V_10 [ 1 ] ;
V_8 -> V_15 = ( V_10 [ 2 ] >> 2 * 8 ) & 0xffff ;
V_8 -> V_16 = V_10 [ 2 ] & 0xffff ;
V_8 -> V_17 = ( V_10 [ 3 ] >> 6 * 8 ) & 0x01 ;
V_8 -> V_18 = ( V_10 [ 3 ] >> 5 * 8 ) & 0xff ;
V_8 -> V_19 = ( V_10 [ 3 ] >> 4 * 8 ) & 0xff ;
V_8 -> V_20 = ( V_10 [ 3 ] >> 2 * 8 ) & 0xffff ;
V_8 -> V_21 = V_10 [ 3 ] & 0xffff ;
V_8 -> V_22 = V_10 [ 4 ] >> 6 * 8 ;
V_8 -> V_23 = ( V_10 [ 4 ] >> 3 * 8 ) & 0xffffff ;
V_8 -> V_24 = V_10 [ 4 ] & 0xffffff ;
return V_9 ;
}
static unsigned F_6 ( unsigned long * V_25 ,
unsigned long * V_26 )
{
unsigned long V_9 ;
unsigned long V_10 [ V_27 ] ;
V_9 = F_7 ( V_28 , V_10 ) ;
* V_25 = V_10 [ 0 ] ;
* V_26 = V_10 [ 1 ] ;
return V_9 ;
}
static void F_8 ( struct V_29 * V_30 )
{
struct V_7 V_8 ;
struct V_31 * V_32 ;
const int * V_33 ;
int V_9 ;
V_9 = F_4 ( & V_8 ) ;
if ( V_9 )
return;
F_9 ( V_30 , L_1 ,
V_8 . V_13 ) ;
F_9 ( V_30 , L_2 , V_8 . V_15 ) ;
F_9 ( V_30 , L_3 ,
V_8 . V_21 ) ;
if ( F_10 ( 0 ) . V_34 ) {
unsigned long V_25 , V_35 ;
F_9 ( V_30 , L_4 , V_8 . V_16 ) ;
F_9 ( V_30 , L_5 ,
V_8 . V_20 * 100 ) ;
F_6 ( & V_25 , & V_35 ) ;
F_9 ( V_30 , L_6 , V_25 ) ;
F_9 ( V_30 , L_7 , V_35 ) ;
}
F_9 ( V_30 , L_8 ,
V_8 . V_19 ) ;
F_9 ( V_30 , L_9 , V_8 . V_18 ) ;
F_9 ( V_30 , L_10 , V_8 . V_17 ) ;
F_9 ( V_30 , L_11 ,
V_8 . V_14 ) ;
V_32 = F_11 ( L_12 ) ;
if ( V_32 ) {
V_33 = F_12 ( V_32 ,
L_13 ,
NULL ) ;
if ( V_33 && ( * V_33 >= 1 ) ) {
F_9 ( V_30 ,
L_14 ,
V_8 . V_22 ) ;
F_9 ( V_30 , L_15 ,
V_8 . V_23 ) ;
F_9 ( V_30 , L_16 ,
V_8 . V_24 ) ;
}
F_13 ( V_32 ) ;
}
}
static void F_14 ( struct V_29 * V_30 )
{
struct V_36 V_37 ;
int V_9 ;
V_9 = F_15 ( & V_37 ) ;
if ( V_9 )
return;
F_9 ( V_30 , L_17 , V_37 . V_38 ) ;
if ( V_37 . V_39 != - 1 )
F_9 ( V_30 , L_18 ,
V_37 . V_39 ) ;
F_9 ( V_30 , L_19 , V_37 . V_15 ) ;
F_9 ( V_30 , L_20 , V_37 . V_16 ) ;
F_9 ( V_30 , L_21 , V_37 . V_40 ) ;
F_9 ( V_30 , L_22 ,
V_37 . V_41 ) ;
F_9 ( V_30 , L_23 ,
V_37 . V_14 ) ;
if ( V_37 . V_42 != - 1 )
F_9 ( V_30 , L_24 ,
V_37 . V_42 ) ;
F_9 ( V_30 , L_25 ,
V_37 . V_43 ) ;
F_9 ( V_30 , L_26 , V_37 . V_44 ) ;
}
static void F_16 ( struct V_29 * V_30 )
{
struct V_45 V_46 ;
if ( ! F_17 ( V_47 ) )
return;
if ( F_18 ( & V_46 ) )
return;
F_9 ( V_30 , L_27 , V_46 . V_48 ) ;
if ( V_46 . V_49 )
F_9 ( V_30 , L_28 ,
V_46 . V_49 ) ;
if ( V_46 . V_50 )
F_9 ( V_30 , L_29 , V_46 . V_50 ) ;
if ( V_46 . V_51 )
F_9 ( V_30 , L_30 , V_46 . V_51 ) ;
}
static void F_19 ( struct V_29 * V_30 )
{
int V_52 ;
unsigned char * V_53 = F_20 ( V_54 , V_55 ) ;
if ( ! V_53 ) {
F_21 ( V_56 L_31 ,
__FILE__ , V_57 , __LINE__ ) ;
return;
}
F_22 ( & V_58 ) ;
memset ( V_59 , 0 , V_54 ) ;
V_52 = F_23 ( F_24 ( L_32 ) , 3 , 1 ,
NULL ,
V_60 ,
F_25 ( V_59 ) ,
V_61 ) ;
memcpy ( V_53 , V_59 , V_54 ) ;
F_26 ( & V_58 ) ;
if ( V_52 != 0 ) {
F_21 ( V_62
L_33 ,
__FILE__ , V_57 , V_52 ) ;
} else {
int V_63 ;
int V_64 , V_65 ;
char * V_66 = F_27 ( V_54 , V_55 ) ;
if ( ! V_66 ) {
F_21 ( V_56 L_31 ,
__FILE__ , V_57 , __LINE__ ) ;
F_28 ( V_53 ) ;
return;
}
#ifdef F_29
F_21 ( V_62 L_34 ) ;
#endif
V_63 = V_53 [ 0 ] * 256 + V_53 [ 1 ] ;
V_53 += 2 ;
V_65 = 0 ;
V_64 = 0 ;
while ( ( * V_53 ) && ( V_64 < V_63 ) ) {
V_66 [ V_65 ++ ] = V_53 [ V_64 ++ ] ;
if ( ( V_53 [ V_64 ] == ',' )
|| ( V_53 [ V_64 ] == '\0' ) ) {
V_66 [ V_65 ] = '\0' ;
if ( V_65 ) {
F_9 ( V_30 , L_35 , V_66 ) ;
}
memset ( V_66 , 0 , V_54 ) ;
V_64 ++ ;
V_65 = 0 ;
} else if ( V_53 [ V_64 ] == '=' ) {
if ( 0 == strcmp ( V_66 , L_36 ) ) {
strcpy ( V_66 ,
L_37 ) ;
V_65 = strlen ( V_66 ) ;
}
if ( 0 == strcmp ( V_66 , L_38 ) ) {
strcpy ( V_66 ,
L_39 ) ;
V_65 = strlen ( V_66 ) ;
}
}
}
F_28 ( V_66 ) ;
V_53 -= 2 ;
}
F_28 ( V_53 ) ;
}
static int F_30 ( void )
{
struct V_31 * V_67 = NULL ;
int V_68 = 0 ;
while ( ( V_67 = F_31 ( V_67 , L_40 ) ) ) {
#ifdef F_29
F_21 ( V_56 L_41 , V_67 ) ;
#endif
V_68 ++ ;
}
return V_68 ;
}
static void F_32 ( struct V_29 * V_30 )
{
int V_2 ;
unsigned long V_69 = 0 ;
unsigned long V_70 = 0 ;
F_9 ( V_30 , L_42 , F_17 ( V_71 ) ) ;
if ( ! F_17 ( V_71 ) )
return;
F_2 (cpu) {
V_69 += F_10 ( V_2 ) . V_69 ;
V_70 += F_10 ( V_2 ) . V_70 ;
}
F_9 ( V_30 , L_43 , V_69 ) ;
F_9 ( V_30 , L_44 ,
V_70 / V_72 ) ;
F_9 ( V_30 , L_45 , F_33 () ) ;
F_9 ( V_30 , L_46 , F_34 () ) ;
F_9 ( V_30 , L_47 , F_35 () ) ;
}
static void F_36 ( struct V_29 * V_30 )
{
int V_2 ;
unsigned long V_73 = 0 ;
unsigned long V_74 = 0 ;
F_2 (cpu) {
V_73 += F_10 ( V_2 ) . V_75 ;
V_74 += F_10 ( V_2 ) . V_76 ;
}
F_9 ( V_30 , L_48 , V_73 ) ;
F_9 ( V_30 , L_49 , V_74 ) ;
}
static void F_37 ( struct V_29 * V_30 )
{
unsigned long V_10 [ V_27 ] ;
if ( F_7 ( V_77 , V_10 ) == V_78 )
F_9 ( V_30 , L_50 , V_10 [ 0 ] ) ;
}
static int F_38 ( struct V_29 * V_30 , void * V_79 )
{
int V_80 ;
int V_81 ;
struct V_31 * V_82 ;
const int * V_83 = NULL ;
V_82 = F_11 ( L_51 ) ;
if ( V_82 )
V_83 = F_12 ( V_82 , L_52 , NULL ) ;
if ( V_83 == NULL ) {
V_80 = V_84 -> V_85 ;
} else {
V_80 = * ( V_83 + 4 ) ;
}
F_13 ( V_82 ) ;
V_81 = F_30 () ;
if ( F_17 ( V_86 ) ) {
F_19 ( V_30 ) ;
F_8 ( V_30 ) ;
F_14 ( V_30 ) ;
F_16 ( V_30 ) ;
F_32 ( V_30 ) ;
F_36 ( V_30 ) ;
F_9 ( V_30 , L_53 , F_1 () ) ;
} else {
F_9 ( V_30 , L_3 ,
V_80 ) ;
F_9 ( V_30 , L_54 ,
V_80 ) ;
F_9 ( V_30 , L_55 ,
V_80 * 100 ) ;
F_9 ( V_30 , L_56 ,
V_81 * 100 ) ;
}
F_9 ( V_30 , L_57 ,
V_81 ) ;
F_9 ( V_30 , L_58 ,
V_80 ) ;
F_9 ( V_30 , L_59 , F_10 ( 0 ) . V_34 ) ;
F_9 ( V_30 , L_60 , V_87 ) ;
F_37 ( V_30 ) ;
return 0 ;
}
static T_1 F_39 ( T_2 * V_13 , T_3 * V_18 )
{
struct V_7 V_8 ;
T_3 V_88 ;
T_2 V_89 ;
T_1 V_90 ;
V_90 = F_4 ( & V_8 ) ;
if ( V_90 )
return V_90 ;
if ( V_13 ) {
V_88 = V_8 . V_18 ;
V_89 = * V_13 ;
} else if ( V_18 ) {
V_88 = * V_18 ;
V_89 = V_8 . V_13 ;
} else
return - V_91 ;
F_40 ( L_61 ,
V_57 , V_8 . V_13 , V_8 . V_18 ) ;
F_40 ( L_62 ,
V_57 , V_89 , V_88 ) ;
V_90 = F_41 ( V_92 , V_89 , V_88 ) ;
return V_90 ;
}
static T_1 F_42 ( T_2 * V_13 , T_3 * V_18 )
{
struct V_36 V_37 ;
T_2 V_89 ;
T_3 V_88 ;
T_1 V_9 ;
if ( V_13 ) {
V_9 = F_43 ( * V_13 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_15 ( & V_37 ) ;
if ( V_9 )
return V_9 ;
if ( V_13 ) {
V_88 = V_37 . V_40 ;
V_89 = * V_13 ;
} else if ( V_18 ) {
V_88 = * V_18 ;
V_89 = V_37 . V_38 ;
} else
return - V_91 ;
F_40 ( L_63 ,
V_57 , V_37 . V_38 , V_37 . V_40 ) ;
F_40 ( L_62 ,
V_57 , V_89 , V_88 ) ;
V_9 = F_41 ( V_93 , V_89 , V_88 ) ;
return V_9 ;
}
static T_1 F_44 ( struct V_94 * V_94 , const char T_4 * V_95 ,
T_5 V_68 , T_6 * V_96 )
{
int V_97 = 64 ;
char V_98 [ V_97 ] ;
char * V_99 ;
T_2 V_89 , * V_100 = & V_89 ;
T_3 V_88 , * V_101 = & V_88 ;
T_1 V_90 ;
if ( ! F_17 ( V_86 ) )
return - V_91 ;
if ( V_68 > V_97 )
return - V_91 ;
if ( F_45 ( V_98 , V_95 , V_68 ) )
return - V_102 ;
V_98 [ V_68 - 1 ] = '\0' ;
V_99 = strchr ( V_98 , '=' ) ;
if ( ! V_99 )
return - V_91 ;
* V_99 ++ = '\0' ;
if ( ! strcmp ( V_98 , L_64 ) ) {
char * V_103 ;
* V_100 = ( T_2 ) F_46 ( V_99 , & V_103 , 10 ) ;
if ( V_103 == V_99 )
return - V_91 ;
V_90 = F_39 ( V_100 , NULL ) ;
} else if ( ! strcmp ( V_98 , L_65 ) ) {
char * V_103 ;
* V_101 = ( T_3 ) F_46 ( V_99 , & V_103 , 10 ) ;
if ( V_103 == V_99 )
return - V_91 ;
V_90 = F_39 ( NULL , V_101 ) ;
} else if ( ! strcmp ( V_98 , L_66 ) ) {
char * V_103 ;
* V_100 = ( T_2 ) F_46 ( V_99 , & V_103 , 10 ) ;
if ( V_103 == V_99 )
return - V_91 ;
V_90 = F_42 ( V_100 , NULL ) ;
} else if ( ! strcmp ( V_98 , L_67 ) ) {
char * V_103 ;
* V_101 = ( T_3 ) F_46 ( V_99 , & V_103 , 10 ) ;
if ( V_103 == V_99 )
return - V_91 ;
V_90 = F_42 ( NULL , V_101 ) ;
} else
return - V_91 ;
if ( V_90 == V_78 || V_90 == V_104 ) {
V_90 = V_68 ;
} else if ( V_90 == V_105 ) {
V_90 = - V_106 ;
} else if ( V_90 == V_107 ) {
V_90 = - V_108 ;
} else if ( V_90 == V_109 ) {
V_90 = - V_91 ;
}
return V_90 ;
}
static int F_47 ( struct V_29 * V_30 , void * V_79 )
{
struct V_31 * V_110 ;
const char * V_111 = L_68 ;
const char * V_112 = L_68 ;
const char * V_99 ;
const unsigned int * V_113 ;
unsigned int V_114 = 0 ;
F_9 ( V_30 , L_69 , V_115 , V_116 ) ;
V_110 = F_11 ( L_12 ) ;
if ( V_110 ) {
V_99 = F_12 ( V_110 , L_70 , NULL ) ;
if ( V_99 )
V_111 = V_99 ;
V_99 = F_12 ( V_110 , L_71 , NULL ) ;
if ( V_99 )
V_112 = V_99 ;
V_113 = F_12 ( V_110 , L_72 ,
NULL ) ;
if ( V_113 )
V_114 = * V_113 ;
F_13 ( V_110 ) ;
}
F_9 ( V_30 , L_73 , V_112 ) ;
F_9 ( V_30 , L_74 , V_111 ) ;
F_9 ( V_30 , L_75 , ( int ) V_114 ) ;
return F_38 ( V_30 , V_79 ) ;
}
static int F_48 ( struct V_117 * V_117 , struct V_94 * V_94 )
{
return F_49 ( V_94 , F_47 , NULL ) ;
}
static int T_7 F_50 ( void )
{
struct V_118 * V_119 ;
T_8 V_120 = V_121 | V_122 | V_123 ;
if ( F_17 ( V_86 ) )
V_120 |= V_124 ;
V_119 = F_51 ( L_76 , V_120 , NULL , & V_125 ) ;
if ( ! V_119 ) {
F_21 ( V_56 L_77 ) ;
return - V_108 ;
}
V_126 = V_119 ;
return 0 ;
}
static void T_9 F_52 ( void )
{
if ( V_126 )
F_53 ( L_78 , V_126 -> V_127 ) ;
}
