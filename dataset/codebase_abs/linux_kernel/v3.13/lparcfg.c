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
const T_1 * V_33 ;
int V_9 ;
V_9 = F_4 ( & V_8 ) ;
if ( V_9 )
return;
F_9 ( V_30 , L_1 ,
V_8 . V_13 ) ;
F_9 ( V_30 , L_2 , V_8 . V_15 ) ;
F_9 ( V_30 , L_3 ,
V_8 . V_21 ) ;
if ( F_10 ( F_11 () ) ) {
unsigned long V_25 , V_34 ;
F_9 ( V_30 , L_4 , V_8 . V_16 ) ;
F_9 ( V_30 , L_5 ,
V_8 . V_20 * 100 ) ;
F_6 ( & V_25 , & V_34 ) ;
F_9 ( V_30 , L_6 , V_25 ) ;
F_9 ( V_30 , L_7 , V_34 ) ;
}
F_9 ( V_30 , L_8 ,
V_8 . V_19 ) ;
F_9 ( V_30 , L_9 , V_8 . V_18 ) ;
F_9 ( V_30 , L_10 , V_8 . V_17 ) ;
F_9 ( V_30 , L_11 ,
V_8 . V_14 ) ;
V_32 = F_12 ( L_12 ) ;
if ( V_32 ) {
V_33 = F_13 ( V_32 ,
L_13 ,
NULL ) ;
if ( V_33 && ( F_14 ( V_33 ) >= 1 ) ) {
F_9 ( V_30 ,
L_14 ,
V_8 . V_22 ) ;
F_9 ( V_30 , L_15 ,
V_8 . V_23 ) ;
F_9 ( V_30 , L_16 ,
V_8 . V_24 ) ;
}
F_15 ( V_32 ) ;
}
}
static void F_16 ( struct V_29 * V_30 )
{
struct V_35 V_36 ;
int V_9 ;
V_9 = F_17 ( & V_36 ) ;
if ( V_9 )
return;
F_9 ( V_30 , L_17 , V_36 . V_37 ) ;
if ( V_36 . V_38 != - 1 )
F_9 ( V_30 , L_18 ,
V_36 . V_38 ) ;
F_9 ( V_30 , L_19 , V_36 . V_15 ) ;
F_9 ( V_30 , L_20 , V_36 . V_16 ) ;
F_9 ( V_30 , L_21 , V_36 . V_39 ) ;
F_9 ( V_30 , L_22 ,
V_36 . V_40 ) ;
F_9 ( V_30 , L_23 ,
V_36 . V_14 ) ;
if ( V_36 . V_41 != - 1 )
F_9 ( V_30 , L_24 ,
V_36 . V_41 ) ;
F_9 ( V_30 , L_25 ,
V_36 . V_42 ) ;
F_9 ( V_30 , L_26 , V_36 . V_43 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_44 V_45 ;
if ( ! F_19 ( V_46 ) )
return;
if ( F_20 ( & V_45 ) )
return;
F_9 ( V_30 , L_27 , V_45 . V_47 ) ;
if ( V_45 . V_48 )
F_9 ( V_30 , L_28 ,
V_45 . V_48 ) ;
if ( V_45 . V_49 )
F_9 ( V_30 , L_29 , V_45 . V_49 ) ;
if ( V_45 . V_50 )
F_9 ( V_30 , L_30 , V_45 . V_50 ) ;
}
static void F_21 ( struct V_29 * V_30 )
{
int V_51 ;
unsigned char * V_52 = F_22 ( V_53 , V_54 ) ;
if ( ! V_52 ) {
F_23 ( V_55 L_31 ,
__FILE__ , V_56 , __LINE__ ) ;
return;
}
F_24 ( & V_57 ) ;
memset ( V_58 , 0 , V_53 ) ;
V_51 = F_25 ( F_26 ( L_32 ) , 3 , 1 ,
NULL ,
V_59 ,
F_27 ( V_58 ) ,
V_60 ) ;
memcpy ( V_52 , V_58 , V_53 ) ;
V_52 [ V_53 - 1 ] = '\0' ;
F_28 ( & V_57 ) ;
if ( V_51 != 0 ) {
F_23 ( V_61
L_33 ,
__FILE__ , V_56 , V_51 ) ;
} else {
int V_62 ;
int V_63 , V_64 ;
char * V_65 = F_29 ( V_53 , V_54 ) ;
if ( ! V_65 ) {
F_23 ( V_55 L_31 ,
__FILE__ , V_56 , __LINE__ ) ;
F_30 ( V_52 ) ;
return;
}
#ifdef F_31
F_23 ( V_61 L_34 ) ;
#endif
V_62 = V_52 [ 0 ] * 256 + V_52 [ 1 ] ;
V_52 += 2 ;
V_64 = 0 ;
V_63 = 0 ;
while ( ( * V_52 ) && ( V_63 < V_62 ) ) {
V_65 [ V_64 ++ ] = V_52 [ V_63 ++ ] ;
if ( ( V_52 [ V_63 ] == ',' )
|| ( V_52 [ V_63 ] == '\0' ) ) {
V_65 [ V_64 ] = '\0' ;
if ( V_64 ) {
F_9 ( V_30 , L_35 , V_65 ) ;
}
memset ( V_65 , 0 , V_53 ) ;
V_63 ++ ;
V_64 = 0 ;
} else if ( V_52 [ V_63 ] == '=' ) {
if ( 0 == strcmp ( V_65 , L_36 ) ) {
strcpy ( V_65 ,
L_37 ) ;
V_64 = strlen ( V_65 ) ;
}
if ( 0 == strcmp ( V_65 , L_38 ) ) {
strcpy ( V_65 ,
L_39 ) ;
V_64 = strlen ( V_65 ) ;
}
}
}
F_30 ( V_65 ) ;
V_52 -= 2 ;
}
F_30 ( V_52 ) ;
}
static int F_32 ( void )
{
struct V_31 * V_66 = NULL ;
int V_67 = 0 ;
while ( ( V_66 = F_33 ( V_66 , L_40 ) ) ) {
#ifdef F_31
F_23 ( V_55 L_41 , V_66 ) ;
#endif
V_67 ++ ;
}
return V_67 ;
}
static void F_34 ( struct V_29 * V_30 )
{
int V_2 ;
unsigned long V_68 = 0 ;
unsigned long V_69 = 0 ;
F_9 ( V_30 , L_42 , F_19 ( V_70 ) ) ;
if ( ! F_19 ( V_70 ) )
return;
F_2 (cpu) {
V_68 += F_35 ( F_36 ( V_2 ) . V_68 ) ;
V_69 += F_35 ( F_36 ( V_2 ) . V_69 ) ;
}
F_9 ( V_30 , L_43 , V_68 ) ;
F_9 ( V_30 , L_44 ,
V_69 / V_71 ) ;
F_9 ( V_30 , L_45 , F_37 () ) ;
F_9 ( V_30 , L_46 , F_38 () ) ;
F_9 ( V_30 , L_47 , F_39 () ) ;
}
static void F_40 ( struct V_29 * V_30 )
{
int V_2 ;
unsigned long V_72 = 0 ;
unsigned long V_73 = 0 ;
F_2 (cpu) {
V_72 += F_41 ( F_36 ( V_2 ) . V_74 ) ;
V_73 +=
F_41 ( F_36 ( V_2 ) . V_75 ) ;
}
F_9 ( V_30 , L_48 , V_72 ) ;
F_9 ( V_30 , L_49 , V_73 ) ;
}
static void F_42 ( struct V_29 * V_30 )
{
unsigned long V_10 [ V_27 ] ;
if ( F_19 ( V_76 ) &&
F_7 ( V_77 , V_10 ) == V_78 )
F_9 ( V_30 , L_50 , V_10 [ 0 ] ) ;
}
static int F_43 ( struct V_29 * V_30 , void * V_79 )
{
int V_80 ;
int V_81 ;
struct V_31 * V_82 ;
const T_1 * V_83 = NULL ;
V_82 = F_12 ( L_51 ) ;
if ( V_82 )
V_83 = F_13 ( V_82 , L_52 , NULL ) ;
if ( V_83 == NULL ) {
V_80 = V_84 -> V_85 ;
} else {
V_80 = F_14 ( V_83 + 4 ) ;
}
F_15 ( V_82 ) ;
V_81 = F_32 () ;
if ( F_19 ( V_86 ) ) {
F_21 ( V_30 ) ;
F_8 ( V_30 ) ;
F_16 ( V_30 ) ;
F_18 ( V_30 ) ;
F_34 ( V_30 ) ;
F_40 ( V_30 ) ;
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
F_9 ( V_30 , L_59 ,
F_10 ( F_11 () ) ) ;
F_9 ( V_30 , L_60 , V_87 ) ;
F_42 ( V_30 ) ;
return 0 ;
}
static T_2 F_44 ( T_3 * V_13 , T_4 * V_18 )
{
struct V_7 V_8 ;
T_4 V_88 ;
T_3 V_89 ;
T_2 V_90 ;
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
F_45 ( L_61 ,
V_56 , V_8 . V_13 , V_8 . V_18 ) ;
F_45 ( L_62 ,
V_56 , V_89 , V_88 ) ;
V_90 = F_46 ( V_92 , V_89 , V_88 ) ;
return V_90 ;
}
static T_2 F_47 ( T_3 * V_13 , T_4 * V_18 )
{
struct V_35 V_36 ;
T_3 V_89 ;
T_4 V_88 ;
T_2 V_9 ;
if ( V_13 ) {
V_9 = F_48 ( * V_13 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_17 ( & V_36 ) ;
if ( V_9 )
return V_9 ;
if ( V_13 ) {
V_88 = V_36 . V_39 ;
V_89 = * V_13 ;
} else if ( V_18 ) {
V_88 = * V_18 ;
V_89 = V_36 . V_37 ;
} else
return - V_91 ;
F_45 ( L_63 ,
V_56 , V_36 . V_37 , V_36 . V_39 ) ;
F_45 ( L_62 ,
V_56 , V_89 , V_88 ) ;
V_9 = F_46 ( V_93 , V_89 , V_88 ) ;
return V_9 ;
}
static T_2 F_49 ( struct V_94 * V_94 , const char T_5 * V_95 ,
T_6 V_67 , T_7 * V_96 )
{
int V_97 = 64 ;
char V_98 [ V_97 ] ;
char * V_99 ;
T_3 V_89 , * V_100 = & V_89 ;
T_4 V_88 , * V_101 = & V_88 ;
T_2 V_90 ;
if ( ! F_19 ( V_86 ) )
return - V_91 ;
if ( V_67 > V_97 )
return - V_91 ;
if ( F_50 ( V_98 , V_95 , V_67 ) )
return - V_102 ;
V_98 [ V_67 - 1 ] = '\0' ;
V_99 = strchr ( V_98 , '=' ) ;
if ( ! V_99 )
return - V_91 ;
* V_99 ++ = '\0' ;
if ( ! strcmp ( V_98 , L_64 ) ) {
char * V_103 ;
* V_100 = ( T_3 ) F_51 ( V_99 , & V_103 , 10 ) ;
if ( V_103 == V_99 )
return - V_91 ;
V_90 = F_44 ( V_100 , NULL ) ;
} else if ( ! strcmp ( V_98 , L_65 ) ) {
char * V_103 ;
* V_101 = ( T_4 ) F_51 ( V_99 , & V_103 , 10 ) ;
if ( V_103 == V_99 )
return - V_91 ;
V_90 = F_44 ( NULL , V_101 ) ;
} else if ( ! strcmp ( V_98 , L_66 ) ) {
char * V_103 ;
* V_100 = ( T_3 ) F_51 ( V_99 , & V_103 , 10 ) ;
if ( V_103 == V_99 )
return - V_91 ;
V_90 = F_47 ( V_100 , NULL ) ;
} else if ( ! strcmp ( V_98 , L_67 ) ) {
char * V_103 ;
* V_101 = ( T_4 ) F_51 ( V_99 , & V_103 , 10 ) ;
if ( V_103 == V_99 )
return - V_91 ;
V_90 = F_47 ( NULL , V_101 ) ;
} else
return - V_91 ;
if ( V_90 == V_78 || V_90 == V_104 ) {
V_90 = V_67 ;
} else if ( V_90 == V_105 ) {
V_90 = - V_106 ;
} else if ( V_90 == V_107 ) {
V_90 = - V_108 ;
} else if ( V_90 == V_109 ) {
V_90 = - V_91 ;
}
return V_90 ;
}
static int F_52 ( struct V_29 * V_30 , void * V_79 )
{
struct V_31 * V_110 ;
const char * V_111 = L_68 ;
const char * V_112 = L_68 ;
const char * V_99 ;
const T_1 * V_113 ;
unsigned int V_114 = 0 ;
F_9 ( V_30 , L_69 , V_115 , V_116 ) ;
V_110 = F_12 ( L_12 ) ;
if ( V_110 ) {
V_99 = F_13 ( V_110 , L_70 , NULL ) ;
if ( V_99 )
V_111 = V_99 ;
V_99 = F_13 ( V_110 , L_71 , NULL ) ;
if ( V_99 )
V_112 = V_99 ;
V_113 = F_13 ( V_110 , L_72 ,
NULL ) ;
if ( V_113 )
V_114 = F_14 ( V_113 ) ;
F_15 ( V_110 ) ;
}
F_9 ( V_30 , L_73 , V_112 ) ;
F_9 ( V_30 , L_74 , V_111 ) ;
F_9 ( V_30 , L_75 , ( int ) V_114 ) ;
return F_43 ( V_30 , V_79 ) ;
}
static int F_53 ( struct V_117 * V_117 , struct V_94 * V_94 )
{
return F_54 ( V_94 , F_52 , NULL ) ;
}
static int T_8 F_55 ( void )
{
T_9 V_118 = V_119 | V_120 | V_121 ;
if ( F_19 ( V_86 ) )
V_118 |= V_122 ;
if ( ! F_56 ( L_76 , V_118 , NULL , & V_123 ) ) {
F_23 ( V_55 L_77 ) ;
return - V_108 ;
}
return 0 ;
}
