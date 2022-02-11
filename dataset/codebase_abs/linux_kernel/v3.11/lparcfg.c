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
V_53 [ V_54 - 1 ] = '\0' ;
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
if ( F_17 ( V_77 ) &&
F_7 ( V_78 , V_10 ) == V_79 )
F_9 ( V_30 , L_50 , V_10 [ 0 ] ) ;
}
static int F_38 ( struct V_29 * V_30 , void * V_80 )
{
int V_81 ;
int V_82 ;
struct V_31 * V_83 ;
const int * V_84 = NULL ;
V_83 = F_11 ( L_51 ) ;
if ( V_83 )
V_84 = F_12 ( V_83 , L_52 , NULL ) ;
if ( V_84 == NULL ) {
V_81 = V_85 -> V_86 ;
} else {
V_81 = * ( V_84 + 4 ) ;
}
F_13 ( V_83 ) ;
V_82 = F_30 () ;
if ( F_17 ( V_87 ) ) {
F_19 ( V_30 ) ;
F_8 ( V_30 ) ;
F_14 ( V_30 ) ;
F_16 ( V_30 ) ;
F_32 ( V_30 ) ;
F_36 ( V_30 ) ;
F_9 ( V_30 , L_53 , F_1 () ) ;
} else {
F_9 ( V_30 , L_3 ,
V_81 ) ;
F_9 ( V_30 , L_54 ,
V_81 ) ;
F_9 ( V_30 , L_55 ,
V_81 * 100 ) ;
F_9 ( V_30 , L_56 ,
V_82 * 100 ) ;
}
F_9 ( V_30 , L_57 ,
V_82 ) ;
F_9 ( V_30 , L_58 ,
V_81 ) ;
F_9 ( V_30 , L_59 , F_10 ( 0 ) . V_34 ) ;
F_9 ( V_30 , L_60 , V_88 ) ;
F_37 ( V_30 ) ;
return 0 ;
}
static T_1 F_39 ( T_2 * V_13 , T_3 * V_18 )
{
struct V_7 V_8 ;
T_3 V_89 ;
T_2 V_90 ;
T_1 V_91 ;
V_91 = F_4 ( & V_8 ) ;
if ( V_91 )
return V_91 ;
if ( V_13 ) {
V_89 = V_8 . V_18 ;
V_90 = * V_13 ;
} else if ( V_18 ) {
V_89 = * V_18 ;
V_90 = V_8 . V_13 ;
} else
return - V_92 ;
F_40 ( L_61 ,
V_57 , V_8 . V_13 , V_8 . V_18 ) ;
F_40 ( L_62 ,
V_57 , V_90 , V_89 ) ;
V_91 = F_41 ( V_93 , V_90 , V_89 ) ;
return V_91 ;
}
static T_1 F_42 ( T_2 * V_13 , T_3 * V_18 )
{
struct V_36 V_37 ;
T_2 V_90 ;
T_3 V_89 ;
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
V_89 = V_37 . V_40 ;
V_90 = * V_13 ;
} else if ( V_18 ) {
V_89 = * V_18 ;
V_90 = V_37 . V_38 ;
} else
return - V_92 ;
F_40 ( L_63 ,
V_57 , V_37 . V_38 , V_37 . V_40 ) ;
F_40 ( L_62 ,
V_57 , V_90 , V_89 ) ;
V_9 = F_41 ( V_94 , V_90 , V_89 ) ;
return V_9 ;
}
static T_1 F_44 ( struct V_95 * V_95 , const char T_4 * V_96 ,
T_5 V_68 , T_6 * V_97 )
{
int V_98 = 64 ;
char V_99 [ V_98 ] ;
char * V_100 ;
T_2 V_90 , * V_101 = & V_90 ;
T_3 V_89 , * V_102 = & V_89 ;
T_1 V_91 ;
if ( ! F_17 ( V_87 ) )
return - V_92 ;
if ( V_68 > V_98 )
return - V_92 ;
if ( F_45 ( V_99 , V_96 , V_68 ) )
return - V_103 ;
V_99 [ V_68 - 1 ] = '\0' ;
V_100 = strchr ( V_99 , '=' ) ;
if ( ! V_100 )
return - V_92 ;
* V_100 ++ = '\0' ;
if ( ! strcmp ( V_99 , L_64 ) ) {
char * V_104 ;
* V_101 = ( T_2 ) F_46 ( V_100 , & V_104 , 10 ) ;
if ( V_104 == V_100 )
return - V_92 ;
V_91 = F_39 ( V_101 , NULL ) ;
} else if ( ! strcmp ( V_99 , L_65 ) ) {
char * V_104 ;
* V_102 = ( T_3 ) F_46 ( V_100 , & V_104 , 10 ) ;
if ( V_104 == V_100 )
return - V_92 ;
V_91 = F_39 ( NULL , V_102 ) ;
} else if ( ! strcmp ( V_99 , L_66 ) ) {
char * V_104 ;
* V_101 = ( T_2 ) F_46 ( V_100 , & V_104 , 10 ) ;
if ( V_104 == V_100 )
return - V_92 ;
V_91 = F_42 ( V_101 , NULL ) ;
} else if ( ! strcmp ( V_99 , L_67 ) ) {
char * V_104 ;
* V_102 = ( T_3 ) F_46 ( V_100 , & V_104 , 10 ) ;
if ( V_104 == V_100 )
return - V_92 ;
V_91 = F_42 ( NULL , V_102 ) ;
} else
return - V_92 ;
if ( V_91 == V_79 || V_91 == V_105 ) {
V_91 = V_68 ;
} else if ( V_91 == V_106 ) {
V_91 = - V_107 ;
} else if ( V_91 == V_108 ) {
V_91 = - V_109 ;
} else if ( V_91 == V_110 ) {
V_91 = - V_92 ;
}
return V_91 ;
}
static int F_47 ( struct V_29 * V_30 , void * V_80 )
{
struct V_31 * V_111 ;
const char * V_112 = L_68 ;
const char * V_113 = L_68 ;
const char * V_100 ;
const unsigned int * V_114 ;
unsigned int V_115 = 0 ;
F_9 ( V_30 , L_69 , V_116 , V_117 ) ;
V_111 = F_11 ( L_12 ) ;
if ( V_111 ) {
V_100 = F_12 ( V_111 , L_70 , NULL ) ;
if ( V_100 )
V_112 = V_100 ;
V_100 = F_12 ( V_111 , L_71 , NULL ) ;
if ( V_100 )
V_113 = V_100 ;
V_114 = F_12 ( V_111 , L_72 ,
NULL ) ;
if ( V_114 )
V_115 = * V_114 ;
F_13 ( V_111 ) ;
}
F_9 ( V_30 , L_73 , V_113 ) ;
F_9 ( V_30 , L_74 , V_112 ) ;
F_9 ( V_30 , L_75 , ( int ) V_115 ) ;
return F_38 ( V_30 , V_80 ) ;
}
static int F_48 ( struct V_118 * V_118 , struct V_95 * V_95 )
{
return F_49 ( V_95 , F_47 , NULL ) ;
}
static int T_7 F_50 ( void )
{
T_8 V_119 = V_120 | V_121 | V_122 ;
if ( F_17 ( V_87 ) )
V_119 |= V_123 ;
if ( ! F_51 ( L_76 , V_119 , NULL , & V_124 ) ) {
F_21 ( V_56 L_77 ) ;
return - V_109 ;
}
return 0 ;
}
