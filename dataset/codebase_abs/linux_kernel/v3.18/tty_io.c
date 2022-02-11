void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_3 )
F_2 ( V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_5 = 0xDEADDEAD ;
F_3 ( V_2 ) ;
}
static inline struct V_1 * F_4 ( struct V_6 * V_6 )
{
return ( (struct V_7 * ) V_6 -> V_8 ) -> V_2 ;
}
int F_5 ( struct V_6 * V_6 )
{
struct V_7 * V_9 ;
V_9 = F_6 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_6 -> V_8 = V_9 ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 , struct V_6 * V_6 )
{
struct V_7 * V_9 = V_6 -> V_8 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_6 = V_6 ;
F_8 ( & V_12 ) ;
F_9 ( & V_9 -> V_13 , & V_2 -> V_14 ) ;
F_10 ( & V_12 ) ;
}
void F_11 ( struct V_6 * V_6 )
{
struct V_7 * V_9 = V_6 -> V_8 ;
V_6 -> V_8 = NULL ;
F_3 ( V_9 ) ;
}
static void F_12 ( struct V_6 * V_6 )
{
struct V_7 * V_9 = V_6 -> V_8 ;
F_8 ( & V_12 ) ;
F_13 ( & V_9 -> V_13 ) ;
F_10 ( & V_12 ) ;
F_11 ( V_6 ) ;
}
char * F_14 ( struct V_1 * V_2 , char * V_15 )
{
if ( ! V_2 )
strcpy ( V_15 , L_1 ) ;
else
strcpy ( V_15 , V_2 -> V_16 ) ;
return V_15 ;
}
int F_15 ( struct V_1 * V_2 , struct V_17 * V_17 ,
const char * V_18 )
{
#ifdef F_16
if ( ! V_2 ) {
F_17 ( V_19
L_2 ,
F_18 ( V_17 ) , F_19 ( V_17 ) , V_18 ) ;
return 1 ;
}
if ( V_2 -> V_5 != V_20 ) {
F_17 ( V_19
L_3 ,
F_18 ( V_17 ) , F_19 ( V_17 ) , V_18 ) ;
return 1 ;
}
#endif
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , const char * V_18 )
{
#ifdef F_21
struct V_21 * V_22 ;
int V_23 = 0 ;
F_8 ( & V_12 ) ;
F_22 (p, &tty->tty_files) {
V_23 ++ ;
}
F_10 ( & V_12 ) ;
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_27 &&
V_2 -> V_28 && V_2 -> V_28 -> V_23 )
V_23 ++ ;
if ( V_2 -> V_23 != V_23 ) {
F_17 ( V_19 L_4
L_5 ,
V_2 -> V_16 , V_2 -> V_23 , V_23 , V_18 ) ;
return V_23 ;
}
#endif
return 0 ;
}
static struct V_29 * F_23 ( T_1 V_30 , int * V_31 )
{
struct V_29 * V_22 ;
F_24 (p, &tty_drivers, tty_drivers) {
T_1 V_32 = F_25 ( V_22 -> V_33 , V_22 -> V_34 ) ;
if ( V_30 < V_32 || V_30 >= V_32 + V_22 -> V_35 )
continue;
* V_31 = V_30 - V_32 ;
return F_26 ( V_22 ) ;
}
return NULL ;
}
struct V_29 * F_27 ( char * V_16 , int * line )
{
struct V_29 * V_22 , * V_36 = NULL ;
int V_37 = 0 ;
int V_38 ;
char * V_39 , * V_40 ;
for ( V_39 = V_16 ; * V_39 ; V_39 ++ )
if ( ( * V_39 >= '0' && * V_39 <= '9' ) || * V_39 == ',' )
break;
if ( ! * V_39 )
return NULL ;
V_38 = V_39 - V_16 ;
V_37 = F_28 ( V_39 , & V_39 , 10 ) ;
F_29 ( & V_41 ) ;
F_24 (p, &tty_drivers, tty_drivers) {
if ( strncmp ( V_16 , V_22 -> V_16 , V_38 ) != 0 )
continue;
V_40 = V_39 ;
if ( * V_40 == ',' )
V_40 ++ ;
if ( * V_40 == '\0' )
V_40 = NULL ;
if ( V_37 >= 0 && V_37 < V_22 -> V_35 && V_22 -> V_42 &&
V_22 -> V_42 -> V_43 && ! V_22 -> V_42 -> V_43 ( V_22 , V_37 , V_40 ) ) {
V_36 = F_26 ( V_22 ) ;
* line = V_37 ;
break;
}
}
F_30 ( & V_41 ) ;
return V_36 ;
}
int F_31 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
int V_45 = 0 ;
if ( V_46 -> signal -> V_2 != V_2 )
return 0 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
if ( ! V_2 -> V_48 ) {
F_17 ( V_19 L_6 ) ;
goto V_49;
}
if ( F_33 ( V_46 ) == V_2 -> V_48 )
goto V_49;
F_34 ( & V_2 -> V_47 , V_44 ) ;
if ( F_35 ( V_50 ) )
goto V_51;
if ( F_36 () ) {
V_45 = - V_52 ;
goto V_51;
}
F_37 ( F_33 ( V_46 ) , V_50 , 1 ) ;
F_38 ( V_53 ) ;
V_45 = - V_54 ;
V_51:
return V_45 ;
V_49:
F_34 ( & V_2 -> V_47 , V_44 ) ;
return V_45 ;
}
static T_2 F_39 ( struct V_6 * V_6 , char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
return 0 ;
}
static T_2 F_40 ( struct V_6 * V_6 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
return - V_52 ;
}
static unsigned int F_41 ( struct V_6 * V_56 , T_6 * V_57 )
{
return V_58 | V_59 | V_60 | V_61 | V_62 | V_63 ;
}
static long F_42 ( struct V_6 * V_6 , unsigned int V_64 ,
unsigned long V_65 )
{
return V_64 == V_66 ? - V_67 : - V_52 ;
}
static long F_43 ( struct V_6 * V_6 ,
unsigned int V_64 , unsigned long V_65 )
{
return V_64 == V_66 ? - V_67 : - V_52 ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_68 * V_69 ;
if ( F_45 ( V_70 , & V_2 -> V_44 ) ) {
V_69 = F_46 ( V_2 ) ;
if ( V_69 ) {
if ( V_69 -> V_42 -> V_71 )
V_69 -> V_42 -> V_71 ( V_2 ) ;
F_47 ( V_69 ) ;
}
}
F_48 ( & V_2 -> V_72 , V_59 ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_73 )
{
struct V_74 * V_22 ;
int V_75 = 0 ;
struct V_76 * V_77 = NULL ;
F_50 ( & V_78 ) ;
if ( V_2 -> V_79 ) {
F_51 (tty->session, PIDTYPE_SID, p) {
F_52 ( & V_22 -> V_80 -> V_81 ) ;
if ( V_22 -> signal -> V_2 == V_2 ) {
V_22 -> signal -> V_2 = NULL ;
V_75 ++ ;
}
if ( ! V_22 -> signal -> V_82 ) {
F_53 ( & V_22 -> V_80 -> V_81 ) ;
continue;
}
F_54 ( V_83 , V_84 , V_22 ) ;
F_54 ( V_85 , V_84 , V_22 ) ;
F_55 ( V_22 -> signal -> V_86 ) ;
F_8 ( & V_2 -> V_47 ) ;
V_77 = F_56 ( V_2 -> V_48 ) ;
if ( V_2 -> V_48 )
V_22 -> signal -> V_86 = F_56 ( V_2 -> V_48 ) ;
F_10 ( & V_2 -> V_47 ) ;
F_53 ( & V_22 -> V_80 -> V_81 ) ;
} F_57 ( V_2 -> V_79 , V_87 , V_22 ) ;
}
F_58 ( & V_78 ) ;
if ( V_77 ) {
if ( V_73 )
F_37 ( V_77 , V_83 , V_73 ) ;
F_55 ( V_77 ) ;
}
return V_75 ;
}
static void F_59 ( struct V_1 * V_2 , int V_73 )
{
struct V_6 * V_88 = NULL ;
struct V_6 * V_56 , * V_89 = NULL ;
struct V_7 * V_9 ;
int V_90 = 0 , V_91 ;
int V_75 ;
if ( ! V_2 )
return;
F_8 ( & V_92 ) ;
if ( V_93 && F_4 ( V_93 ) == V_2 ) {
V_89 = V_93 ;
V_93 = NULL ;
}
F_10 ( & V_92 ) ;
F_60 ( V_2 ) ;
if ( F_45 ( V_94 , & V_2 -> V_44 ) ) {
F_61 ( V_2 ) ;
return;
}
F_62 ( V_95 , & V_2 -> V_44 ) ;
F_20 ( V_2 , L_7 ) ;
F_8 ( & V_12 ) ;
F_24 (priv, &tty->tty_files, list) {
V_56 = V_9 -> V_6 ;
if ( V_56 -> V_96 -> V_97 == V_98 )
V_88 = V_56 ;
if ( V_56 -> V_96 -> V_97 != V_99 )
continue;
V_90 ++ ;
F_63 ( - 1 , V_56 , 0 ) ;
V_56 -> V_96 = & V_100 ;
}
F_10 ( & V_12 ) ;
V_75 = F_49 ( V_2 , V_73 ) ;
while ( V_75 -- )
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
F_52 ( & V_2 -> V_47 ) ;
F_66 ( V_101 , & V_2 -> V_44 ) ;
F_66 ( V_70 , & V_2 -> V_44 ) ;
F_55 ( V_2 -> V_79 ) ;
F_55 ( V_2 -> V_48 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_48 = NULL ;
V_2 -> V_102 = 0 ;
F_53 ( & V_2 -> V_47 ) ;
if ( V_88 ) {
if ( V_2 -> V_42 -> V_103 )
for ( V_91 = 0 ; V_91 < V_90 ; V_91 ++ )
V_2 -> V_42 -> V_103 ( V_2 , V_88 ) ;
} else if ( V_2 -> V_42 -> V_104 )
V_2 -> V_42 -> V_104 ( V_2 ) ;
F_62 ( V_94 , & V_2 -> V_44 ) ;
F_66 ( V_95 , & V_2 -> V_44 ) ;
F_61 ( V_2 ) ;
if ( V_89 )
F_67 ( V_89 ) ;
}
static void F_68 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_69 ( V_106 , struct V_1 , V_107 ) ;
F_59 ( V_2 , 0 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
#ifdef F_71
char V_15 [ 64 ] ;
F_17 ( V_108 L_8 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_72 ( & V_2 -> V_107 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
#ifdef F_71
char V_15 [ 64 ] ;
F_17 ( V_108 L_9 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_59 ( V_2 , 0 ) ;
}
void F_74 ( void )
{
struct V_1 * V_2 ;
V_2 = F_75 () ;
if ( V_2 ) {
F_73 ( V_2 ) ;
F_64 ( V_2 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
#ifdef F_71
char V_15 [ 64 ] ;
F_17 ( V_108 L_10 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_59 ( V_2 , 1 ) ;
}
int F_77 ( struct V_6 * V_56 )
{
return ( V_56 -> V_96 == & V_100 ) ;
}
static void F_78 ( struct V_76 * V_79 )
{
struct V_74 * V_22 ;
F_51 (session, PIDTYPE_SID, p) {
F_79 ( V_22 ) ;
} F_57 ( V_79 , V_87 , V_22 ) ;
}
void F_80 ( int V_109 )
{
struct V_1 * V_2 ;
if ( ! V_46 -> signal -> V_82 )
return;
V_2 = F_75 () ;
if ( V_2 ) {
if ( V_109 && V_2 -> V_24 -> type != V_25 ) {
F_76 ( V_2 ) ;
} else {
struct V_76 * V_77 = F_81 ( V_2 ) ;
if ( V_77 ) {
F_37 ( V_77 , V_83 , V_109 ) ;
if ( ! V_109 )
F_37 ( V_77 , V_85 , V_109 ) ;
F_55 ( V_77 ) ;
}
}
F_64 ( V_2 ) ;
} else if ( V_109 ) {
struct V_76 * V_110 ;
F_52 ( & V_46 -> V_80 -> V_81 ) ;
V_110 = V_46 -> signal -> V_86 ;
V_46 -> signal -> V_86 = NULL ;
F_53 ( & V_46 -> V_80 -> V_81 ) ;
if ( V_110 ) {
F_37 ( V_110 , V_83 , V_109 ) ;
F_37 ( V_110 , V_85 , V_109 ) ;
F_55 ( V_110 ) ;
}
return;
}
F_52 ( & V_46 -> V_80 -> V_81 ) ;
F_55 ( V_46 -> signal -> V_86 ) ;
V_46 -> signal -> V_86 = NULL ;
V_2 = F_82 ( V_46 -> signal -> V_2 ) ;
if ( V_2 ) {
unsigned long V_44 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
F_55 ( V_2 -> V_79 ) ;
F_55 ( V_2 -> V_48 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_48 = NULL ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
F_64 ( V_2 ) ;
} else {
#ifdef F_71
F_17 ( V_108 L_11
L_12 , V_2 ) ;
#endif
}
F_53 ( & V_46 -> V_80 -> V_81 ) ;
F_50 ( & V_78 ) ;
F_78 ( F_83 ( V_46 ) ) ;
F_58 ( & V_78 ) ;
}
void F_84 ( void )
{
struct V_74 * V_111 = V_46 ;
F_80 ( 0 ) ;
F_79 ( V_111 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
if ( V_2 -> V_112 )
return;
V_2 -> V_112 = 1 ;
if ( V_2 -> V_42 -> V_113 )
( V_2 -> V_42 -> V_113 ) ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_32 ( & V_2 -> V_114 , V_44 ) ;
F_85 ( V_2 ) ;
F_34 ( & V_2 -> V_114 , V_44 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_112 || V_2 -> V_115 )
return;
V_2 -> V_112 = 0 ;
if ( V_2 -> V_42 -> V_116 )
( V_2 -> V_42 -> V_116 ) ( V_2 ) ;
F_44 ( V_2 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_32 ( & V_2 -> V_114 , V_44 ) ;
F_87 ( V_2 ) ;
F_34 ( & V_2 -> V_114 , V_44 ) ;
}
static void F_89 ( struct V_117 * time )
{
unsigned long V_118 = F_90 () & ~ 7 ;
if ( ( long ) ( V_118 - time -> V_119 ) > 0 )
time -> V_119 = V_118 ;
}
static T_2 F_91 ( struct V_6 * V_6 , char T_3 * V_15 , T_4 V_23 ,
T_5 * V_55 )
{
int V_120 ;
struct V_17 * V_17 = F_92 ( V_6 ) ;
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_68 * V_69 ;
if ( F_15 ( V_2 , V_17 , L_13 ) )
return - V_52 ;
if ( ! V_2 || ( F_45 ( V_121 , & V_2 -> V_44 ) ) )
return - V_52 ;
V_69 = F_93 ( V_2 ) ;
if ( V_69 -> V_42 -> V_122 )
V_120 = ( V_69 -> V_42 -> V_122 ) ( V_2 , V_6 , V_15 , V_23 ) ;
else
V_120 = - V_52 ;
F_47 ( V_69 ) ;
if ( V_120 > 0 )
F_89 ( & V_17 -> V_123 ) ;
return V_120 ;
}
static void F_94 ( struct V_1 * V_2 )
__releases( &tty->atomic_write_lock
static int F_95 ( struct V_1 * V_2 , int V_124 )
__acquires( &tty->atomic_write_lock
static inline T_2 F_96 (
T_2 (* V_97)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_15 ,
T_4 V_23 )
{
T_2 V_45 , V_125 = 0 ;
unsigned int V_126 ;
V_45 = F_95 ( V_2 , V_6 -> V_127 & V_128 ) ;
if ( V_45 < 0 )
return V_45 ;
V_126 = 2048 ;
if ( F_45 ( V_129 , & V_2 -> V_44 ) )
V_126 = 65536 ;
if ( V_23 < V_126 )
V_126 = V_23 ;
if ( V_2 -> V_130 < V_126 ) {
unsigned char * V_131 ;
if ( V_126 < 1024 )
V_126 = 1024 ;
V_131 = F_6 ( V_126 , V_10 ) ;
if ( ! V_131 ) {
V_45 = - V_11 ;
goto V_51;
}
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_130 = V_126 ;
V_2 -> V_4 = V_131 ;
}
for (; ; ) {
T_4 V_132 = V_23 ;
if ( V_132 > V_126 )
V_132 = V_126 ;
V_45 = - V_133 ;
if ( F_97 ( V_2 -> V_4 , V_15 , V_132 ) )
break;
V_45 = V_97 ( V_2 , V_6 , V_2 -> V_4 , V_132 ) ;
if ( V_45 <= 0 )
break;
V_125 += V_45 ;
V_15 += V_45 ;
V_23 -= V_45 ;
if ( ! V_23 )
break;
V_45 = - V_54 ;
if ( F_98 ( V_46 ) )
break;
F_99 () ;
}
if ( V_125 ) {
F_89 ( & F_92 ( V_6 ) -> V_134 ) ;
V_45 = V_125 ;
}
V_51:
F_94 ( V_2 ) ;
return V_45 ;
}
void F_100 ( struct V_1 * V_2 , char * V_135 )
{
if ( V_2 ) {
F_29 ( & V_2 -> V_136 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> V_42 -> V_97 && ! F_45 ( V_137 , & V_2 -> V_44 ) ) {
F_61 ( V_2 ) ;
V_2 -> V_42 -> V_97 ( V_2 , V_135 , strlen ( V_135 ) ) ;
} else
F_61 ( V_2 ) ;
F_94 ( V_2 ) ;
}
return;
}
static T_2 V_99 ( struct V_6 * V_6 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_68 * V_69 ;
T_2 V_45 ;
if ( F_15 ( V_2 , F_92 ( V_6 ) , L_14 ) )
return - V_52 ;
if ( ! V_2 || ! V_2 -> V_42 -> V_97 ||
( F_45 ( V_121 , & V_2 -> V_44 ) ) )
return - V_52 ;
if ( V_2 -> V_42 -> V_138 == NULL )
F_17 ( V_139 L_15 ,
V_2 -> V_24 -> V_16 ) ;
V_69 = F_93 ( V_2 ) ;
if ( ! V_69 -> V_42 -> V_97 )
V_45 = - V_52 ;
else
V_45 = F_96 ( V_69 -> V_42 -> V_97 , V_2 , V_6 , V_15 , V_23 ) ;
F_47 ( V_69 ) ;
return V_45 ;
}
T_2 V_98 ( struct V_6 * V_6 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_6 * V_22 = NULL ;
F_8 ( & V_92 ) ;
if ( V_93 )
V_22 = F_101 ( V_93 ) ;
F_10 ( & V_92 ) ;
if ( V_22 ) {
T_2 V_36 ;
V_36 = F_102 ( V_22 , V_15 , V_23 , & V_22 -> V_140 ) ;
F_67 ( V_22 ) ;
return V_36 ;
}
return V_99 ( V_6 , V_15 , V_23 , V_55 ) ;
}
int F_103 ( struct V_1 * V_2 , char V_141 )
{
int V_142 = V_2 -> V_112 ;
if ( V_2 -> V_42 -> V_143 ) {
V_2 -> V_42 -> V_143 ( V_2 , V_141 ) ;
return 0 ;
}
if ( F_95 ( V_2 , 0 ) < 0 )
return - V_54 ;
if ( V_142 )
F_88 ( V_2 ) ;
V_2 -> V_42 -> V_97 ( V_2 , & V_141 , 1 ) ;
if ( V_142 )
F_86 ( V_2 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
static void F_104 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
int V_120 = V_31 + V_24 -> V_144 ;
sprintf ( V_22 , L_16 ,
V_24 -> V_26 == V_27 ? L_17 : V_24 -> V_16 ,
V_145 [ V_120 >> 4 & 0xf ] , V_120 & 0xf ) ;
}
static T_2 F_105 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
if ( V_24 -> V_44 & V_146 )
return sprintf ( V_22 , L_18 , V_24 -> V_16 ) ;
else
return sprintf ( V_22 , L_19 , V_24 -> V_16 ,
V_31 + V_24 -> V_144 ) ;
}
static struct V_1 * F_106 ( struct V_29 * V_24 ,
struct V_17 * V_17 , int V_147 )
{
if ( V_24 -> V_42 -> V_148 )
return V_24 -> V_42 -> V_148 ( V_24 , V_17 , V_147 ) ;
return V_24 -> V_149 [ V_147 ] ;
}
int F_107 ( struct V_1 * V_2 )
{
struct V_150 * V_151 ;
int V_147 = V_2 -> V_31 ;
if ( V_2 -> V_24 -> V_44 & V_152 )
V_2 -> V_153 = V_2 -> V_24 -> V_154 ;
else {
V_151 = V_2 -> V_24 -> V_153 [ V_147 ] ;
if ( V_151 != NULL )
V_2 -> V_153 = * V_151 ;
else
V_2 -> V_153 = V_2 -> V_24 -> V_154 ;
}
V_2 -> V_153 . V_155 = F_108 ( & V_2 -> V_153 ) ;
V_2 -> V_153 . V_156 = F_109 ( & V_2 -> V_153 ) ;
return 0 ;
}
int F_110 ( struct V_29 * V_24 , struct V_1 * V_2 )
{
int V_45 = F_107 ( V_2 ) ;
if ( V_45 )
return V_45 ;
F_26 ( V_24 ) ;
V_2 -> V_23 ++ ;
V_24 -> V_149 [ V_2 -> V_31 ] = V_2 ;
return 0 ;
}
static int F_111 ( struct V_29 * V_24 ,
struct V_1 * V_2 )
{
return V_24 -> V_42 -> V_157 ? V_24 -> V_42 -> V_157 ( V_24 , V_2 ) :
F_110 ( V_24 , V_2 ) ;
}
void F_112 ( struct V_29 * V_24 , struct V_1 * V_2 )
{
if ( V_24 -> V_42 -> remove )
V_24 -> V_42 -> remove ( V_24 , V_2 ) ;
else
V_24 -> V_149 [ V_2 -> V_31 ] = NULL ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_29 * V_24 = V_2 -> V_24 ;
if ( F_45 ( V_137 , & V_2 -> V_44 ) ||
F_45 ( V_95 , & V_2 -> V_44 ) )
return - V_52 ;
if ( V_24 -> type == V_25 &&
V_24 -> V_26 == V_158 ) {
if ( V_2 -> V_23 )
return - V_52 ;
V_2 -> V_28 -> V_23 ++ ;
}
V_2 -> V_23 ++ ;
F_114 ( ! V_2 -> V_159 ) ;
return 0 ;
}
struct V_1 * F_115 ( struct V_29 * V_24 , int V_147 )
{
struct V_1 * V_2 ;
int V_160 ;
if ( ! F_116 ( V_24 -> V_161 ) )
return F_117 ( - V_162 ) ;
V_2 = F_118 ( V_24 , V_147 ) ;
if ( ! V_2 ) {
V_160 = - V_11 ;
goto V_163;
}
F_60 ( V_2 ) ;
V_160 = F_111 ( V_24 , V_2 ) ;
if ( V_160 < 0 )
goto V_164;
if ( ! V_2 -> V_165 )
V_2 -> V_165 = V_24 -> V_166 [ V_147 ] ;
F_119 ( ! V_2 -> V_165 ,
L_20 ,
V_167 , V_2 -> V_24 -> V_16 ) ;
V_2 -> V_165 -> V_168 = V_2 ;
V_160 = F_120 ( V_2 , V_2 -> V_28 ) ;
if ( V_160 )
goto V_169;
return V_2 ;
V_164:
F_61 ( V_2 ) ;
F_121 ( V_2 ) ;
F_1 ( V_2 ) ;
V_163:
F_122 ( V_24 -> V_161 ) ;
return F_117 ( V_160 ) ;
V_169:
F_61 ( V_2 ) ;
F_123 ( V_170 L_21
L_22 , V_147 ) ;
F_124 ( V_2 , V_147 ) ;
return F_117 ( V_160 ) ;
}
void F_125 ( struct V_1 * V_2 )
{
struct V_150 * V_151 ;
int V_147 = V_2 -> V_31 ;
if ( V_2 -> V_24 -> V_44 & V_152 )
return;
V_151 = V_2 -> V_24 -> V_153 [ V_147 ] ;
if ( V_151 == NULL ) {
V_151 = F_6 ( sizeof( struct V_150 ) , V_10 ) ;
if ( V_151 == NULL ) {
F_126 ( L_23 ) ;
return;
}
V_2 -> V_24 -> V_153 [ V_147 ] = V_151 ;
}
* V_151 = V_2 -> V_153 ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_128 ( & V_2 -> V_171 ) ;
F_128 ( & V_2 -> V_107 ) ;
}
static void F_129 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_69 ( V_106 , struct V_1 , V_107 ) ;
struct V_29 * V_24 = V_2 -> V_24 ;
struct V_172 * V_161 = V_24 -> V_161 ;
if ( V_2 -> V_42 -> V_173 )
V_2 -> V_42 -> V_173 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_130 ( V_24 ) ;
F_122 ( V_161 ) ;
F_8 ( & V_12 ) ;
F_131 ( & V_2 -> V_14 ) ;
F_10 ( & V_12 ) ;
F_55 ( V_2 -> V_48 ) ;
F_55 ( V_2 -> V_79 ) ;
F_1 ( V_2 ) ;
}
static void F_132 ( struct V_174 * V_174 )
{
struct V_1 * V_2 = F_69 ( V_174 , struct V_1 , V_174 ) ;
F_133 ( & V_2 -> V_107 , F_129 ) ;
F_72 ( & V_2 -> V_107 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
if ( V_2 )
F_134 ( & V_2 -> V_174 , F_132 ) ;
}
static void F_124 ( struct V_1 * V_2 , int V_147 )
{
F_114 ( V_2 -> V_31 != V_147 ) ;
F_114 ( ! F_135 ( & V_41 ) ) ;
if ( V_2 -> V_42 -> V_175 )
V_2 -> V_42 -> V_175 ( V_2 ) ;
F_125 ( V_2 ) ;
F_112 ( V_2 -> V_24 , V_2 ) ;
V_2 -> V_165 -> V_168 = NULL ;
if ( V_2 -> V_28 )
V_2 -> V_28 -> V_165 -> V_168 = NULL ;
F_136 ( & V_2 -> V_165 -> V_15 . V_106 ) ;
if ( V_2 -> V_28 )
F_64 ( V_2 -> V_28 ) ;
F_64 ( V_2 ) ;
}
static int F_137 ( struct V_1 * V_2 , struct V_1 * V_176 ,
int V_147 )
{
#ifdef F_16
if ( V_147 < 0 || V_147 >= V_2 -> V_24 -> V_35 ) {
F_17 ( V_108 L_24 ,
V_167 , V_2 -> V_16 ) ;
return - 1 ;
}
if ( V_2 -> V_24 -> V_44 & V_177 )
return 0 ;
if ( V_2 != V_2 -> V_24 -> V_149 [ V_147 ] ) {
F_17 ( V_108 L_25 ,
V_167 , V_147 , V_2 -> V_16 ) ;
return - 1 ;
}
if ( V_2 -> V_24 -> V_178 ) {
if ( V_176 != V_2 -> V_24 -> V_178 -> V_149 [ V_147 ] ) {
F_17 ( V_108 L_26 ,
V_167 , V_147 , V_2 -> V_16 ) ;
return - 1 ;
}
if ( V_176 -> V_28 != V_2 ) {
F_17 ( V_108 L_27 , V_167 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_138 ( struct V_17 * V_17 , struct V_6 * V_56 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
struct V_1 * V_176 ;
int V_179 , V_180 , V_181 , V_182 ;
int V_147 ;
char V_15 [ 64 ] ;
long V_183 = 0 ;
int V_184 = 1 ;
if ( F_15 ( V_2 , V_17 , V_167 ) )
return 0 ;
F_60 ( V_2 ) ;
F_20 ( V_2 , V_167 ) ;
F_63 ( - 1 , V_56 , 0 ) ;
V_147 = V_2 -> V_31 ;
V_179 = ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_158 ) ;
V_176 = V_2 -> V_28 ;
if ( F_137 ( V_2 , V_176 , V_147 ) ) {
F_61 ( V_2 ) ;
return 0 ;
}
#ifdef F_71
F_17 ( V_108 L_28 , V_167 ,
F_14 ( V_2 , V_15 ) , V_2 -> V_23 ) ;
#endif
if ( V_2 -> V_42 -> V_103 )
V_2 -> V_42 -> V_103 ( V_2 , V_56 ) ;
F_61 ( V_2 ) ;
while ( 1 ) {
F_29 ( & V_41 ) ;
F_139 ( V_2 , V_176 ) ;
V_180 = V_2 -> V_23 <= 1 ;
V_181 = V_176 &&
( V_176 -> V_23 <= ( V_179 ? 1 : 0 ) ) ;
V_182 = 0 ;
if ( V_180 ) {
if ( F_140 ( & V_2 -> V_185 ) ) {
F_141 ( & V_2 -> V_185 , V_58 ) ;
V_182 ++ ;
}
if ( F_140 ( & V_2 -> V_72 ) ) {
F_141 ( & V_2 -> V_72 , V_59 ) ;
V_182 ++ ;
}
}
if ( V_181 ) {
if ( F_140 ( & V_176 -> V_185 ) ) {
F_141 ( & V_176 -> V_185 , V_58 ) ;
V_182 ++ ;
}
if ( F_140 ( & V_176 -> V_72 ) ) {
F_141 ( & V_176 -> V_72 , V_59 ) ;
V_182 ++ ;
}
}
if ( ! V_182 )
break;
if ( V_184 ) {
V_184 = 0 ;
F_17 ( V_19 L_29 ,
V_167 , F_14 ( V_2 , V_15 ) ) ;
}
F_142 ( V_2 , V_176 ) ;
F_30 ( & V_41 ) ;
F_143 ( V_183 ) ;
if ( V_183 < 120 * V_186 )
V_183 = 2 * V_183 + 1 ;
else
V_183 = V_187 ;
}
if ( V_179 ) {
if ( -- V_176 -> V_23 < 0 ) {
F_17 ( V_19 L_30 ,
V_167 , V_176 -> V_23 , F_14 ( V_176 , V_15 ) ) ;
V_176 -> V_23 = 0 ;
}
}
if ( -- V_2 -> V_23 < 0 ) {
F_17 ( V_19 L_31 ,
V_167 , V_2 -> V_23 , F_14 ( V_2 , V_15 ) ) ;
V_2 -> V_23 = 0 ;
}
F_12 ( V_56 ) ;
if ( V_180 )
F_62 ( V_137 , & V_2 -> V_44 ) ;
if ( V_181 )
F_62 ( V_137 , & V_176 -> V_44 ) ;
if ( V_180 || V_181 ) {
F_50 ( & V_78 ) ;
F_78 ( V_2 -> V_79 ) ;
if ( V_176 )
F_78 ( V_176 -> V_79 ) ;
F_58 ( & V_78 ) ;
}
F_30 ( & V_41 ) ;
F_142 ( V_2 , V_176 ) ;
if ( ! V_180 || ( V_176 && ! V_181 ) )
return 0 ;
#ifdef F_71
F_17 ( V_108 L_32 , V_167 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_144 ( V_2 , V_176 ) ;
F_127 ( V_2 ) ;
if ( V_176 )
F_127 ( V_176 ) ;
#ifdef F_71
F_17 ( V_108 L_33 , V_167 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_29 ( & V_41 ) ;
F_124 ( V_2 , V_147 ) ;
F_30 ( & V_41 ) ;
return 0 ;
}
static struct V_1 * F_145 ( T_1 V_30 , struct V_6 * V_56 )
{
struct V_1 * V_2 ;
if ( V_30 != F_25 ( V_188 , 0 ) )
return NULL ;
V_2 = F_75 () ;
if ( ! V_2 )
return F_117 ( - V_189 ) ;
V_56 -> V_127 |= V_190 ;
F_64 ( V_2 ) ;
return V_2 ;
}
static struct V_29 * F_146 ( T_1 V_30 , struct V_6 * V_56 ,
int * V_191 , int * V_31 )
{
struct V_29 * V_24 ;
switch ( V_30 ) {
#ifdef F_147
case F_25 ( V_192 , 0 ) : {
extern struct V_29 * V_193 ;
V_24 = F_26 ( V_193 ) ;
* V_31 = V_194 ;
* V_191 = 1 ;
break;
}
#endif
case F_25 ( V_188 , 1 ) : {
struct V_29 * V_193 = F_148 ( V_31 ) ;
if ( V_193 ) {
V_24 = F_26 ( V_193 ) ;
if ( V_24 ) {
V_56 -> V_127 |= V_190 ;
* V_191 = 1 ;
break;
}
}
return F_117 ( - V_162 ) ;
}
default:
V_24 = F_23 ( V_30 , V_31 ) ;
if ( ! V_24 )
return F_117 ( - V_162 ) ;
break;
}
return V_24 ;
}
static int F_149 ( struct V_17 * V_17 , struct V_6 * V_56 )
{
struct V_1 * V_2 ;
int V_191 , V_160 ;
struct V_29 * V_24 = NULL ;
int V_31 ;
T_1 V_30 = V_17 -> V_195 ;
unsigned V_196 = V_56 -> V_127 ;
F_150 ( V_17 , V_56 ) ;
V_197:
V_160 = F_5 ( V_56 ) ;
if ( V_160 )
return - V_11 ;
V_191 = V_56 -> V_127 & V_198 ;
V_31 = - 1 ;
V_160 = 0 ;
F_29 ( & V_41 ) ;
V_2 = F_145 ( V_30 , V_56 ) ;
if ( F_151 ( V_2 ) ) {
V_160 = F_152 ( V_2 ) ;
goto V_199;
} else if ( ! V_2 ) {
V_24 = F_146 ( V_30 , V_56 , & V_191 , & V_31 ) ;
if ( F_151 ( V_24 ) ) {
V_160 = F_152 ( V_24 ) ;
goto V_199;
}
V_2 = F_106 ( V_24 , V_17 , V_31 ) ;
if ( F_151 ( V_2 ) ) {
V_160 = F_152 ( V_2 ) ;
goto V_199;
}
}
if ( V_2 ) {
F_60 ( V_2 ) ;
V_160 = F_113 ( V_2 ) ;
if ( V_160 < 0 ) {
F_61 ( V_2 ) ;
V_2 = F_117 ( V_160 ) ;
}
} else
V_2 = F_115 ( V_24 , V_31 ) ;
F_30 ( & V_41 ) ;
if ( V_24 )
F_130 ( V_24 ) ;
if ( F_151 ( V_2 ) ) {
V_160 = F_152 ( V_2 ) ;
goto V_200;
}
F_7 ( V_2 , V_56 ) ;
F_20 ( V_2 , V_167 ) ;
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_158 )
V_191 = 1 ;
#ifdef F_71
F_17 ( V_108 L_34 , V_167 , V_2 -> V_16 ) ;
#endif
if ( V_2 -> V_42 -> V_201 )
V_160 = V_2 -> V_42 -> V_201 ( V_2 , V_56 ) ;
else
V_160 = - V_162 ;
V_56 -> V_127 = V_196 ;
if ( ! V_160 && F_45 ( V_202 , & V_2 -> V_44 ) &&
! F_153 ( V_203 ) )
V_160 = - V_204 ;
if ( V_160 ) {
#ifdef F_71
F_17 ( V_108 L_35 , V_167 ,
V_160 , V_2 -> V_16 ) ;
#endif
F_61 ( V_2 ) ;
F_138 ( V_17 , V_56 ) ;
if ( V_160 != - V_54 )
return V_160 ;
if ( F_98 ( V_46 ) )
return V_160 ;
F_154 () ;
if ( V_56 -> V_96 == & V_100 )
V_56 -> V_96 = & V_205 ;
goto V_197;
}
F_66 ( V_94 , & V_2 -> V_44 ) ;
F_61 ( V_2 ) ;
F_29 ( & V_41 ) ;
F_60 ( V_2 ) ;
F_52 ( & V_46 -> V_80 -> V_81 ) ;
if ( ! V_191 &&
V_46 -> signal -> V_82 &&
! V_46 -> signal -> V_2 &&
V_2 -> V_79 == NULL )
F_155 ( V_46 , V_2 ) ;
F_53 ( & V_46 -> V_80 -> V_81 ) ;
F_61 ( V_2 ) ;
F_30 ( & V_41 ) ;
return 0 ;
V_199:
F_30 ( & V_41 ) ;
if ( ! F_156 ( V_24 ) )
F_130 ( V_24 ) ;
V_200:
F_11 ( V_56 ) ;
return V_160 ;
}
static unsigned int F_157 ( struct V_6 * V_56 , T_6 * V_57 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
struct V_68 * V_69 ;
int V_45 = 0 ;
if ( F_15 ( V_2 , F_92 ( V_56 ) , L_36 ) )
return 0 ;
V_69 = F_93 ( V_2 ) ;
if ( V_69 -> V_42 -> V_206 )
V_45 = ( V_69 -> V_42 -> V_206 ) ( V_2 , V_56 , V_57 ) ;
F_47 ( V_69 ) ;
return V_45 ;
}
static int F_63 ( int V_207 , struct V_6 * V_56 , int V_208 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
struct V_68 * V_159 ;
unsigned long V_44 ;
int V_160 = 0 ;
if ( F_15 ( V_2 , F_92 ( V_56 ) , L_37 ) )
goto V_51;
V_160 = F_158 ( V_207 , V_56 , V_208 , & V_2 -> V_209 ) ;
if ( V_160 <= 0 )
goto V_51;
V_159 = F_46 ( V_2 ) ;
if ( V_159 ) {
if ( V_159 -> V_42 -> V_209 )
V_159 -> V_42 -> V_209 ( V_2 , V_208 ) ;
F_47 ( V_159 ) ;
}
if ( V_208 ) {
enum V_210 type ;
struct V_76 * V_76 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_48 ) {
V_76 = V_2 -> V_48 ;
type = V_211 ;
} else {
V_76 = F_159 ( V_46 ) ;
type = V_212 ;
}
F_56 ( V_76 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
F_160 ( V_56 , V_76 , type , 0 ) ;
F_55 ( V_76 ) ;
V_160 = 0 ;
}
V_51:
return V_160 ;
}
static int F_161 ( int V_207 , struct V_6 * V_56 , int V_208 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
int V_160 ;
F_60 ( V_2 ) ;
V_160 = F_63 ( V_207 , V_56 , V_208 ) ;
F_61 ( V_2 ) ;
return V_160 ;
}
static int F_162 ( struct V_1 * V_2 , char T_3 * V_22 )
{
char V_141 , V_213 = 0 ;
struct V_68 * V_69 ;
if ( ( V_46 -> signal -> V_2 != V_2 ) && ! F_153 ( V_203 ) )
return - V_214 ;
if ( F_163 ( V_141 , V_22 ) )
return - V_133 ;
F_164 ( V_2 , V_141 ) ;
V_69 = F_93 ( V_2 ) ;
V_69 -> V_42 -> V_215 ( V_2 , & V_141 , & V_213 , 1 ) ;
F_47 ( V_69 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_216 T_3 * V_65 )
{
int V_217 ;
F_29 ( & V_2 -> V_218 ) ;
V_217 = F_166 ( V_65 , & V_2 -> V_216 , sizeof( * V_65 ) ) ;
F_30 ( & V_2 -> V_218 ) ;
return V_217 ? - V_133 : 0 ;
}
int F_167 ( struct V_1 * V_2 , struct V_216 * V_219 )
{
struct V_76 * V_48 ;
unsigned long V_44 ;
F_29 ( & V_2 -> V_218 ) ;
if ( ! memcmp ( V_219 , & V_2 -> V_216 , sizeof( * V_219 ) ) )
goto V_220;
F_32 ( & V_2 -> V_47 , V_44 ) ;
V_48 = F_56 ( V_2 -> V_48 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
if ( V_48 )
F_37 ( V_48 , V_221 , 1 ) ;
F_55 ( V_48 ) ;
V_2 -> V_216 = * V_219 ;
V_220:
F_30 ( & V_2 -> V_218 ) ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 , struct V_216 T_3 * V_65 )
{
struct V_216 V_222 ;
if ( F_97 ( & V_222 , V_65 , sizeof( * V_65 ) ) )
return - V_133 ;
if ( V_2 -> V_42 -> V_223 )
return V_2 -> V_42 -> V_223 ( V_2 , & V_222 ) ;
else
return F_167 ( V_2 , & V_222 ) ;
}
static int F_169 ( struct V_6 * V_6 )
{
if ( ! F_153 ( V_203 ) )
return - V_214 ;
if ( V_6 -> V_96 -> V_97 == V_98 ) {
struct V_6 * V_89 ;
F_8 ( & V_92 ) ;
V_89 = V_93 ;
V_93 = NULL ;
F_10 ( & V_92 ) ;
if ( V_89 )
F_67 ( V_89 ) ;
return 0 ;
}
F_8 ( & V_92 ) ;
if ( V_93 ) {
F_10 ( & V_92 ) ;
return - V_204 ;
}
V_93 = F_101 ( V_6 ) ;
F_10 ( & V_92 ) ;
return 0 ;
}
static int F_170 ( struct V_6 * V_6 , int T_3 * V_22 )
{
int V_224 ;
if ( F_163 ( V_224 , V_22 ) )
return - V_133 ;
F_8 ( & V_6 -> V_225 ) ;
if ( V_224 )
V_6 -> V_127 |= V_190 ;
else
V_6 -> V_127 &= ~ V_190 ;
F_10 ( & V_6 -> V_225 ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , int V_65 )
{
int V_45 = 0 ;
if ( V_46 -> signal -> V_82 && ( F_83 ( V_46 ) == V_2 -> V_79 ) )
return V_45 ;
F_29 ( & V_41 ) ;
if ( ! V_46 -> signal -> V_82 || V_46 -> signal -> V_2 ) {
V_45 = - V_214 ;
goto V_226;
}
if ( V_2 -> V_79 ) {
if ( V_65 == 1 && F_153 ( V_203 ) ) {
F_50 ( & V_78 ) ;
F_78 ( V_2 -> V_79 ) ;
F_58 ( & V_78 ) ;
} else {
V_45 = - V_214 ;
goto V_226;
}
}
F_172 ( V_46 , V_2 ) ;
V_226:
F_30 ( & V_41 ) ;
return V_45 ;
}
struct V_76 * F_81 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
struct V_76 * V_48 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
V_48 = F_56 ( V_2 -> V_48 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
return V_48 ;
}
static int F_173 ( struct V_1 * V_2 , struct V_1 * V_227 , T_7 T_3 * V_22 )
{
struct V_76 * V_76 ;
int V_45 ;
if ( V_2 == V_227 && V_46 -> signal -> V_2 != V_227 )
return - V_67 ;
V_76 = F_81 ( V_227 ) ;
V_45 = F_174 ( F_175 ( V_76 ) , V_22 ) ;
F_55 ( V_76 ) ;
return V_45 ;
}
static int F_176 ( struct V_1 * V_2 , struct V_1 * V_227 , T_7 T_3 * V_22 )
{
struct V_76 * V_48 ;
T_7 V_228 ;
int V_160 = F_31 ( V_227 ) ;
unsigned long V_44 ;
if ( V_160 == - V_52 )
return - V_67 ;
if ( V_160 )
return V_160 ;
if ( ! V_46 -> signal -> V_2 ||
( V_46 -> signal -> V_2 != V_227 ) ||
( V_227 -> V_79 != F_83 ( V_46 ) ) )
return - V_67 ;
if ( F_163 ( V_228 , V_22 ) )
return - V_133 ;
if ( V_228 < 0 )
return - V_229 ;
F_177 () ;
V_48 = F_178 ( V_228 ) ;
V_160 = - V_230 ;
if ( ! V_48 )
goto V_49;
V_160 = - V_214 ;
if ( F_179 ( V_48 ) != F_83 ( V_46 ) )
goto V_49;
V_160 = 0 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
F_55 ( V_227 -> V_48 ) ;
V_227 -> V_48 = F_56 ( V_48 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
V_49:
F_180 () ;
return V_160 ;
}
static int F_181 ( struct V_1 * V_2 , struct V_1 * V_227 , T_7 T_3 * V_22 )
{
if ( V_2 == V_227 && V_46 -> signal -> V_2 != V_227 )
return - V_67 ;
if ( ! V_227 -> V_79 )
return - V_67 ;
return F_174 ( F_175 ( V_227 -> V_79 ) , V_22 ) ;
}
static int F_182 ( struct V_1 * V_2 , int T_3 * V_22 )
{
int V_159 ;
int V_45 ;
if ( F_163 ( V_159 , V_22 ) )
return - V_133 ;
V_45 = F_183 ( V_2 , V_159 ) ;
return V_45 ;
}
static int F_184 ( struct V_1 * V_2 , unsigned int V_231 )
{
int V_160 ;
if ( V_2 -> V_42 -> V_232 == NULL )
return 0 ;
if ( V_2 -> V_24 -> V_44 & V_233 )
V_160 = V_2 -> V_42 -> V_232 ( V_2 , V_231 ) ;
else {
if ( F_95 ( V_2 , 0 ) < 0 )
return - V_234 ;
V_160 = V_2 -> V_42 -> V_232 ( V_2 , - 1 ) ;
if ( V_160 )
goto V_51;
if ( ! F_98 ( V_46 ) )
F_185 ( V_231 ) ;
V_160 = V_2 -> V_42 -> V_232 ( V_2 , 0 ) ;
V_51:
F_94 ( V_2 ) ;
if ( F_98 ( V_46 ) )
V_160 = - V_234 ;
}
return V_160 ;
}
static int F_186 ( struct V_1 * V_2 , int T_3 * V_22 )
{
int V_160 = - V_229 ;
if ( V_2 -> V_42 -> V_235 ) {
V_160 = V_2 -> V_42 -> V_235 ( V_2 ) ;
if ( V_160 >= 0 )
V_160 = F_174 ( V_160 , V_22 ) ;
}
return V_160 ;
}
static int F_187 ( struct V_1 * V_2 , unsigned int V_64 ,
unsigned T_3 * V_22 )
{
int V_160 ;
unsigned int V_236 , V_237 , V_238 ;
if ( V_2 -> V_42 -> V_239 == NULL )
return - V_229 ;
V_160 = F_163 ( V_238 , V_22 ) ;
if ( V_160 )
return V_160 ;
V_236 = V_237 = 0 ;
switch ( V_64 ) {
case V_240 :
V_236 = V_238 ;
break;
case V_241 :
V_237 = V_238 ;
break;
case V_242 :
V_236 = V_238 ;
V_237 = ~ V_238 ;
break;
}
V_236 &= V_243 | V_244 | V_245 | V_246 | V_247 ;
V_237 &= V_243 | V_244 | V_245 | V_246 | V_247 ;
return V_2 -> V_42 -> V_239 ( V_2 , V_236 , V_237 ) ;
}
static int F_188 ( struct V_1 * V_2 , void T_3 * V_65 )
{
int V_160 = - V_229 ;
struct V_248 V_249 ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
if ( V_2 -> V_42 -> V_250 )
V_160 = V_2 -> V_42 -> V_250 ( V_2 , & V_249 ) ;
if ( V_160 != 0 )
return V_160 ;
if ( F_166 ( V_65 , & V_249 , sizeof( V_249 ) ) )
return - V_133 ;
return 0 ;
}
struct V_1 * F_189 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_158 )
V_2 = V_2 -> V_28 ;
return V_2 ;
}
struct V_1 * F_190 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_158 )
return V_2 ;
return V_2 -> V_28 ;
}
long F_191 ( struct V_6 * V_6 , unsigned int V_64 , unsigned long V_65 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_1 * V_227 ;
void T_3 * V_22 = ( void T_3 * ) V_65 ;
int V_160 ;
struct V_68 * V_69 ;
if ( F_15 ( V_2 , F_92 ( V_6 ) , L_38 ) )
return - V_229 ;
V_227 = F_189 ( V_2 ) ;
switch ( V_64 ) {
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
V_160 = F_31 ( V_2 ) ;
if ( V_160 )
return V_160 ;
if ( V_64 != V_253 ) {
F_192 ( V_2 , 0 ) ;
if ( F_98 ( V_46 ) )
return - V_234 ;
}
break;
}
switch ( V_64 ) {
case V_256 :
return F_162 ( V_2 , V_22 ) ;
case V_257 :
return F_165 ( V_227 , V_22 ) ;
case V_258 :
return F_168 ( V_227 , V_22 ) ;
case V_259 :
return V_227 != V_2 ? - V_229 : F_169 ( V_6 ) ;
case V_260 :
return F_170 ( V_6 , V_22 ) ;
case V_261 :
F_62 ( V_202 , & V_2 -> V_44 ) ;
return 0 ;
case V_262 :
F_66 ( V_202 , & V_2 -> V_44 ) ;
return 0 ;
case V_263 :
{
int V_264 = F_45 ( V_202 , & V_2 -> V_44 ) ;
return F_174 ( V_264 , ( int T_3 * ) V_22 ) ;
}
case V_265 :
if ( V_46 -> signal -> V_2 != V_2 )
return - V_67 ;
F_84 () ;
return 0 ;
case V_266 :
return F_171 ( V_2 , V_65 ) ;
case V_267 :
return F_173 ( V_2 , V_227 , V_22 ) ;
case V_66 :
return F_176 ( V_2 , V_227 , V_22 ) ;
case V_268 :
return F_181 ( V_2 , V_227 , V_22 ) ;
case V_269 :
return F_174 ( V_2 -> V_159 -> V_42 -> V_35 , ( int T_3 * ) V_22 ) ;
case V_251 :
return F_182 ( V_2 , V_22 ) ;
case V_270 :
if ( ! F_153 ( V_203 ) )
return - V_214 ;
F_73 ( V_2 ) ;
return 0 ;
case V_271 :
{
unsigned int V_45 = F_193 ( F_194 ( V_227 ) ) ;
return F_174 ( V_45 , ( unsigned int T_3 * ) V_22 ) ;
}
case V_252 :
if ( V_2 -> V_42 -> V_232 )
return V_2 -> V_42 -> V_232 ( V_2 , - 1 ) ;
return 0 ;
case V_253 :
if ( V_2 -> V_42 -> V_232 )
return V_2 -> V_42 -> V_232 ( V_2 , 0 ) ;
return 0 ;
case V_254 :
if ( ! V_65 )
return F_184 ( V_2 , 250 ) ;
return 0 ;
case V_255 :
return F_184 ( V_2 , V_65 ? V_65 * 100 : 250 ) ;
case V_272 :
return F_186 ( V_2 , V_22 ) ;
case V_242 :
case V_241 :
case V_240 :
return F_187 ( V_2 , V_64 , V_22 ) ;
case V_273 :
V_160 = F_188 ( V_2 , V_22 ) ;
if ( V_160 != - V_229 )
return V_160 ;
break;
case V_274 :
switch ( V_65 ) {
case V_275 :
case V_276 :
F_195 ( V_2 ) ;
break;
}
break;
}
if ( V_2 -> V_42 -> V_277 ) {
V_160 = ( V_2 -> V_42 -> V_277 ) ( V_2 , V_64 , V_65 ) ;
if ( V_160 != - V_278 )
return V_160 ;
}
V_69 = F_93 ( V_2 ) ;
V_160 = - V_229 ;
if ( V_69 -> V_42 -> V_277 ) {
V_160 = V_69 -> V_42 -> V_277 ( V_2 , V_6 , V_64 , V_65 ) ;
if ( V_160 == - V_278 )
V_160 = - V_67 ;
}
F_47 ( V_69 ) ;
return V_160 ;
}
static long F_196 ( struct V_6 * V_6 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_68 * V_69 ;
int V_160 = - V_278 ;
if ( F_15 ( V_2 , F_92 ( V_6 ) , L_38 ) )
return - V_229 ;
if ( V_2 -> V_42 -> V_279 ) {
V_160 = ( V_2 -> V_42 -> V_279 ) ( V_2 , V_64 , V_65 ) ;
if ( V_160 != - V_278 )
return V_160 ;
}
V_69 = F_93 ( V_2 ) ;
if ( V_69 -> V_42 -> V_279 )
V_160 = V_69 -> V_42 -> V_279 ( V_2 , V_6 , V_64 , V_65 ) ;
else
V_160 = F_197 ( V_2 , V_6 , V_64 , V_65 ) ;
F_47 ( V_69 ) ;
return V_160 ;
}
static int F_198 ( const void * V_280 , struct V_6 * V_6 , unsigned V_207 )
{
if ( F_199 ( V_6 -> V_96 -> V_122 != F_91 ) )
return 0 ;
return F_4 ( V_6 ) != V_280 ? 0 : V_207 + 1 ;
}
void F_200 ( struct V_1 * V_2 )
{
#ifdef F_201
F_70 ( V_2 ) ;
#else
struct V_74 * V_281 , * V_22 ;
struct V_76 * V_79 ;
int V_120 ;
if ( ! V_2 )
return;
V_79 = V_2 -> V_79 ;
F_202 ( V_2 ) ;
F_203 ( V_2 ) ;
F_50 ( & V_78 ) ;
F_51 (session, PIDTYPE_SID, p) {
F_17 ( V_282 L_39
L_40 ,
F_204 ( V_22 ) , V_22 -> V_283 ) ;
F_205 ( V_284 , V_22 , 1 ) ;
} F_57 ( V_79 , V_87 , V_22 ) ;
F_206 (g, p) {
if ( V_22 -> signal -> V_2 == V_2 ) {
F_17 ( V_282 L_39
L_40 ,
F_204 ( V_22 ) , V_22 -> V_283 ) ;
F_205 ( V_284 , V_22 , 1 ) ;
continue;
}
F_207 ( V_22 ) ;
V_120 = F_208 ( V_22 -> V_285 , 0 , F_198 , V_2 ) ;
if ( V_120 != 0 ) {
F_17 ( V_282 L_39
L_41 ,
F_204 ( V_22 ) , V_22 -> V_283 , V_120 - 1 ) ;
F_209 ( V_284 , V_22 ) ;
}
F_210 ( V_22 ) ;
} F_211 ( V_281 , V_22 ) ;
F_58 ( & V_78 ) ;
#endif
}
static void F_212 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_69 ( V_106 , struct V_1 , V_171 ) ;
F_200 ( V_2 ) ;
}
void F_213 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_72 ( & V_2 -> V_171 ) ;
}
static int F_214 ( struct V_30 * V_3 , const void * V_286 )
{
const T_1 * V_287 = V_286 ;
return V_3 -> V_287 == * V_287 ;
}
static struct V_30 * F_215 ( struct V_1 * V_2 )
{
T_1 V_287 = F_194 ( V_2 ) ;
return F_216 ( V_288 , NULL , & V_287 , F_214 ) ;
}
struct V_1 * F_118 ( struct V_29 * V_24 , int V_147 )
{
struct V_1 * V_2 ;
V_2 = F_217 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_218 ( & V_2 -> V_174 ) ;
V_2 -> V_5 = V_20 ;
F_219 ( V_2 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_48 = NULL ;
F_220 ( & V_2 -> V_289 ) ;
F_220 ( & V_2 -> V_290 ) ;
F_221 ( & V_2 -> V_291 ) ;
F_220 ( & V_2 -> V_218 ) ;
F_222 ( & V_2 -> V_292 ) ;
F_223 ( & V_2 -> V_72 ) ;
F_223 ( & V_2 -> V_185 ) ;
F_133 ( & V_2 -> V_107 , F_68 ) ;
F_220 ( & V_2 -> V_136 ) ;
F_224 ( & V_2 -> V_47 ) ;
F_224 ( & V_2 -> V_114 ) ;
F_225 ( & V_2 -> V_14 ) ;
F_133 ( & V_2 -> V_171 , F_212 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_42 = V_24 -> V_42 ;
V_2 -> V_31 = V_147 ;
F_105 ( V_24 , V_147 , V_2 -> V_16 ) ;
V_2 -> V_3 = F_215 ( V_2 ) ;
return V_2 ;
}
void F_121 ( struct V_1 * V_2 )
{
F_226 ( V_2 ) ;
}
int F_227 ( struct V_1 * V_2 , unsigned char V_141 )
{
if ( V_2 -> V_42 -> V_293 )
return V_2 -> V_42 -> V_293 ( V_2 , V_141 ) ;
return V_2 -> V_42 -> V_97 ( V_2 , & V_141 , 1 ) ;
}
static int F_228 ( struct V_29 * V_24 , T_1 V_3 ,
unsigned int V_31 , unsigned int V_23 )
{
F_229 ( & V_24 -> V_294 [ V_31 ] , & V_205 ) ;
V_24 -> V_294 [ V_31 ] . V_161 = V_24 -> V_161 ;
return F_230 ( & V_24 -> V_294 [ V_31 ] , V_3 , V_23 ) ;
}
struct V_30 * F_231 ( struct V_29 * V_24 , unsigned V_31 ,
struct V_30 * V_30 )
{
return F_232 ( V_24 , V_31 , V_30 , NULL , NULL ) ;
}
static void F_233 ( struct V_30 * V_3 )
{
F_234 ( L_42 , F_235 ( V_3 ) , V_167 ) ;
F_3 ( V_3 ) ;
}
struct V_30 * F_232 ( struct V_29 * V_24 ,
unsigned V_31 , struct V_30 * V_30 ,
void * V_295 ,
const struct V_296 * * V_297 )
{
char V_16 [ 64 ] ;
T_1 V_287 = F_25 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ;
struct V_30 * V_3 = NULL ;
int V_160 = - V_162 ;
bool V_298 = false ;
if ( V_31 >= V_24 -> V_35 ) {
F_17 ( V_139 L_43
L_44 , V_31 ) ;
return F_117 ( - V_229 ) ;
}
if ( V_24 -> type == V_25 )
F_104 ( V_24 , V_31 , V_16 ) ;
else
F_105 ( V_24 , V_31 , V_16 ) ;
if ( ! ( V_24 -> V_44 & V_299 ) ) {
V_160 = F_228 ( V_24 , V_287 , V_31 , 1 ) ;
if ( V_160 )
goto error;
V_298 = true ;
}
V_3 = F_217 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 ) {
V_160 = - V_11 ;
goto error;
}
V_3 -> V_287 = V_287 ;
V_3 -> V_300 = V_288 ;
V_3 -> V_301 = V_30 ;
V_3 -> V_302 = F_233 ;
F_236 ( V_3 , L_18 , V_16 ) ;
V_3 -> V_303 = V_297 ;
F_237 ( V_3 , V_295 ) ;
V_160 = F_238 ( V_3 ) ;
if ( V_160 )
goto error;
return V_3 ;
error:
F_2 ( V_3 ) ;
if ( V_298 )
F_239 ( & V_24 -> V_294 [ V_31 ] ) ;
return F_117 ( V_160 ) ;
}
void F_240 ( struct V_29 * V_24 , unsigned V_31 )
{
F_241 ( V_288 ,
F_25 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ) ;
if ( ! ( V_24 -> V_44 & V_299 ) )
F_239 ( & V_24 -> V_294 [ V_31 ] ) ;
}
struct V_29 * F_242 ( unsigned int V_304 , struct V_172 * V_161 ,
unsigned long V_44 )
{
struct V_29 * V_24 ;
unsigned int V_294 = 1 ;
int V_217 ;
if ( ! V_304 || ( V_44 & V_146 && V_304 > 1 ) )
return F_117 ( - V_229 ) ;
V_24 = F_217 ( sizeof( struct V_29 ) , V_10 ) ;
if ( ! V_24 )
return F_117 ( - V_11 ) ;
F_218 ( & V_24 -> V_174 ) ;
V_24 -> V_5 = V_305 ;
V_24 -> V_35 = V_304 ;
V_24 -> V_161 = V_161 ;
V_24 -> V_44 = V_44 ;
if ( ! ( V_44 & V_177 ) ) {
V_24 -> V_149 = F_243 ( V_304 , sizeof( * V_24 -> V_149 ) ,
V_10 ) ;
V_24 -> V_153 = F_243 ( V_304 , sizeof( * V_24 -> V_153 ) ,
V_10 ) ;
if ( ! V_24 -> V_149 || ! V_24 -> V_153 ) {
V_217 = - V_11 ;
goto V_306;
}
}
if ( ! ( V_44 & V_299 ) ) {
V_24 -> V_166 = F_243 ( V_304 , sizeof( * V_24 -> V_166 ) ,
V_10 ) ;
if ( ! V_24 -> V_166 ) {
V_217 = - V_11 ;
goto V_306;
}
V_294 = V_304 ;
}
V_24 -> V_294 = F_243 ( V_294 , sizeof( * V_24 -> V_294 ) , V_10 ) ;
if ( ! V_24 -> V_294 ) {
V_217 = - V_11 ;
goto V_306;
}
return V_24 ;
V_306:
F_3 ( V_24 -> V_166 ) ;
F_3 ( V_24 -> V_149 ) ;
F_3 ( V_24 -> V_153 ) ;
F_3 ( V_24 ) ;
return F_117 ( V_217 ) ;
}
static void F_244 ( struct V_174 * V_174 )
{
struct V_29 * V_24 = F_69 ( V_174 , struct V_29 , V_174 ) ;
int V_120 ;
struct V_150 * V_151 ;
if ( V_24 -> V_44 & V_307 ) {
for ( V_120 = 0 ; V_120 < V_24 -> V_35 ; V_120 ++ ) {
V_151 = V_24 -> V_153 [ V_120 ] ;
if ( V_151 ) {
V_24 -> V_153 [ V_120 ] = NULL ;
F_3 ( V_151 ) ;
}
if ( ! ( V_24 -> V_44 & V_308 ) )
F_240 ( V_24 , V_120 ) ;
}
F_245 ( V_24 ) ;
if ( V_24 -> V_44 & V_299 )
F_239 ( & V_24 -> V_294 [ 0 ] ) ;
}
F_3 ( V_24 -> V_294 ) ;
F_3 ( V_24 -> V_166 ) ;
F_3 ( V_24 -> V_153 ) ;
F_3 ( V_24 -> V_149 ) ;
F_3 ( V_24 ) ;
}
void F_130 ( struct V_29 * V_24 )
{
F_134 ( & V_24 -> V_174 , F_244 ) ;
}
void F_246 ( struct V_29 * V_24 ,
const struct V_309 * V_310 )
{
V_24 -> V_42 = V_310 ;
}
void F_247 ( struct V_29 * V_311 )
{
F_130 ( V_311 ) ;
}
int F_248 ( struct V_29 * V_24 )
{
int error ;
int V_120 ;
T_1 V_3 ;
struct V_30 * V_311 ;
if ( ! V_24 -> V_33 ) {
error = F_249 ( & V_3 , V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_16 ) ;
if ( ! error ) {
V_24 -> V_33 = F_250 ( V_3 ) ;
V_24 -> V_34 = F_251 ( V_3 ) ;
}
} else {
V_3 = F_25 ( V_24 -> V_33 , V_24 -> V_34 ) ;
error = F_252 ( V_3 , V_24 -> V_35 , V_24 -> V_16 ) ;
}
if ( error < 0 )
goto V_217;
if ( V_24 -> V_44 & V_299 ) {
error = F_228 ( V_24 , V_3 , 0 , V_24 -> V_35 ) ;
if ( error )
goto V_312;
}
F_29 ( & V_41 ) ;
F_9 ( & V_24 -> V_313 , & V_313 ) ;
F_30 ( & V_41 ) ;
if ( ! ( V_24 -> V_44 & V_308 ) ) {
for ( V_120 = 0 ; V_120 < V_24 -> V_35 ; V_120 ++ ) {
V_311 = F_231 ( V_24 , V_120 , NULL ) ;
if ( F_151 ( V_311 ) ) {
error = F_152 ( V_311 ) ;
goto V_314;
}
}
}
F_253 ( V_24 ) ;
V_24 -> V_44 |= V_307 ;
return 0 ;
V_314:
for ( V_120 -- ; V_120 >= 0 ; V_120 -- )
F_240 ( V_24 , V_120 ) ;
F_29 ( & V_41 ) ;
F_13 ( & V_24 -> V_313 ) ;
F_30 ( & V_41 ) ;
V_312:
F_254 ( V_3 , V_24 -> V_35 ) ;
V_217:
return error ;
}
int F_255 ( struct V_29 * V_24 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_254 ( F_25 ( V_24 -> V_33 , V_24 -> V_34 ) ,
V_24 -> V_35 ) ;
F_29 ( & V_41 ) ;
F_13 ( & V_24 -> V_313 ) ;
F_30 ( & V_41 ) ;
return 0 ;
}
T_1 F_194 ( struct V_1 * V_2 )
{
return F_25 ( V_2 -> V_24 -> V_33 , V_2 -> V_24 -> V_34 ) + V_2 -> V_31 ;
}
void F_79 ( struct V_74 * V_22 )
{
unsigned long V_44 ;
struct V_1 * V_2 ;
F_32 ( & V_22 -> V_80 -> V_81 , V_44 ) ;
V_2 = V_22 -> signal -> V_2 ;
V_22 -> signal -> V_2 = NULL ;
F_34 ( & V_22 -> V_80 -> V_81 , V_44 ) ;
F_64 ( V_2 ) ;
}
static void F_155 ( struct V_74 * V_111 , struct V_1 * V_2 )
{
if ( V_2 ) {
unsigned long V_44 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
F_55 ( V_2 -> V_79 ) ;
F_55 ( V_2 -> V_48 ) ;
V_2 -> V_48 = F_56 ( F_33 ( V_111 ) ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
V_2 -> V_79 = F_56 ( F_83 ( V_111 ) ) ;
if ( V_111 -> signal -> V_2 ) {
F_17 ( V_108 L_45 ) ;
F_64 ( V_111 -> signal -> V_2 ) ;
}
}
F_55 ( V_111 -> signal -> V_86 ) ;
V_111 -> signal -> V_2 = F_82 ( V_2 ) ;
V_111 -> signal -> V_86 = NULL ;
}
static void F_172 ( struct V_74 * V_111 , struct V_1 * V_2 )
{
F_52 ( & V_111 -> V_80 -> V_81 ) ;
F_155 ( V_111 , V_2 ) ;
F_53 ( & V_111 -> V_80 -> V_81 ) ;
}
struct V_1 * F_75 ( void )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
F_32 ( & V_46 -> V_80 -> V_81 , V_44 ) ;
V_2 = F_82 ( V_46 -> signal -> V_2 ) ;
F_34 ( & V_46 -> V_80 -> V_81 , V_44 ) ;
return V_2 ;
}
void F_256 ( struct V_315 * V_316 )
{
* V_316 = V_205 ;
}
void T_8 F_257 ( void )
{
T_9 * V_317 ;
F_258 () ;
V_317 = V_318 ;
while ( V_317 < V_319 ) {
(* V_317)() ;
V_317 ++ ;
}
}
static char * F_259 ( struct V_30 * V_3 , T_10 * V_320 )
{
if ( ! V_320 )
return NULL ;
if ( V_3 -> V_287 == F_25 ( V_188 , 0 ) ||
V_3 -> V_287 == F_25 ( V_188 , 2 ) )
* V_320 = 0666 ;
return NULL ;
}
static int T_8 F_260 ( void )
{
V_288 = F_261 ( V_321 , L_17 ) ;
if ( F_151 ( V_288 ) )
return F_152 ( V_288 ) ;
V_288 -> V_322 = F_259 ;
return 0 ;
}
static T_2 F_262 ( struct V_30 * V_3 ,
struct V_323 * V_324 , char * V_15 )
{
struct V_325 * V_326 [ 16 ] ;
int V_120 = 0 ;
struct V_325 * V_327 ;
T_2 V_23 = 0 ;
F_263 () ;
F_264 (c) {
if ( ! V_327 -> V_30 )
continue;
if ( ! V_327 -> V_97 )
continue;
if ( ( V_327 -> V_44 & V_328 ) == 0 )
continue;
V_326 [ V_120 ++ ] = V_327 ;
if ( V_120 >= F_265 ( V_326 ) )
break;
}
while ( V_120 -- ) {
int V_31 = V_326 [ V_120 ] -> V_31 ;
struct V_29 * V_329 = V_326 [ V_120 ] -> V_30 ( V_326 [ V_120 ] , & V_31 ) ;
if ( V_329 && ( V_326 [ V_120 ] -> V_31 > 0 || V_329 -> V_33 != V_192 ) )
V_23 += F_105 ( V_329 , V_31 , V_15 + V_23 ) ;
else
V_23 += sprintf ( V_15 + V_23 , L_19 ,
V_326 [ V_120 ] -> V_16 , V_326 [ V_120 ] -> V_31 ) ;
V_23 += sprintf ( V_15 + V_23 , L_46 , V_120 ? ' ' : '\n' ) ;
}
F_266 () ;
return V_23 ;
}
void F_267 ( void )
{
if ( V_330 )
F_268 ( & V_330 -> V_331 , NULL , L_47 ) ;
}
int T_8 F_269 ( void )
{
F_229 ( & V_332 , & V_205 ) ;
if ( F_230 ( & V_332 , F_25 ( V_188 , 0 ) , 1 ) ||
F_252 ( F_25 ( V_188 , 0 ) , 1 , L_48 ) < 0 )
F_270 ( L_49 ) ;
F_271 ( V_288 , NULL , F_25 ( V_188 , 0 ) , NULL , L_17 ) ;
F_229 ( & V_333 , & V_334 ) ;
if ( F_230 ( & V_333 , F_25 ( V_188 , 1 ) , 1 ) ||
F_252 ( F_25 ( V_188 , 1 ) , 1 , L_50 ) < 0 )
F_270 ( L_51 ) ;
V_330 = F_271 ( V_288 , NULL , F_25 ( V_188 , 1 ) , NULL ,
L_52 ) ;
if ( F_151 ( V_330 ) )
V_330 = NULL ;
else
F_114 ( F_272 ( V_330 , & V_335 ) < 0 ) ;
#ifdef F_147
F_273 ( & V_334 ) ;
#endif
return 0 ;
}
