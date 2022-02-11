void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
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
void F_44 ( struct V_68 * V_22 )
{
unsigned long V_44 ;
struct V_1 * V_2 ;
F_32 ( & V_22 -> V_69 -> V_70 , V_44 ) ;
V_2 = V_22 -> signal -> V_2 ;
V_22 -> signal -> V_2 = NULL ;
F_34 ( & V_22 -> V_69 -> V_70 , V_44 ) ;
F_45 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
F_47 ( V_2 -> V_71 ) ;
F_47 ( V_2 -> V_48 ) ;
V_2 -> V_48 = F_48 ( F_33 ( V_46 ) ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
V_2 -> V_71 = F_48 ( F_49 ( V_46 ) ) ;
if ( V_46 -> signal -> V_2 ) {
F_17 ( V_72 L_7 ) ;
F_45 ( V_46 -> signal -> V_2 ) ;
}
F_47 ( V_46 -> signal -> V_73 ) ;
V_46 -> signal -> V_2 = F_50 ( V_2 ) ;
V_46 -> signal -> V_73 = NULL ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_46 -> V_69 -> V_70 ) ;
F_46 ( V_2 ) ;
F_53 ( & V_46 -> V_69 -> V_70 ) ;
}
struct V_1 * F_54 ( void )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
F_32 ( & V_46 -> V_69 -> V_70 , V_44 ) ;
V_2 = F_50 ( V_46 -> signal -> V_2 ) ;
F_34 ( & V_46 -> V_69 -> V_70 , V_44 ) ;
return V_2 ;
}
static void F_55 ( struct V_74 * V_71 )
{
struct V_68 * V_22 ;
F_56 (session, PIDTYPE_SID, p) {
F_44 ( V_22 ) ;
} F_57 ( V_71 , V_75 , V_22 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
if ( F_59 ( V_78 , & V_2 -> V_44 ) ) {
V_77 = F_60 ( V_2 ) ;
if ( V_77 ) {
if ( V_77 -> V_42 -> V_79 )
V_77 -> V_42 -> V_79 ( V_2 ) ;
F_61 ( V_77 ) ;
}
}
F_62 ( & V_2 -> V_80 , V_59 ) ;
}
static int F_63 ( struct V_1 * V_2 , int V_81 )
{
struct V_68 * V_22 ;
int V_82 = 0 ;
struct V_74 * V_83 = NULL ;
F_64 ( & V_84 ) ;
if ( V_2 -> V_71 ) {
F_56 (tty->session, PIDTYPE_SID, p) {
F_52 ( & V_22 -> V_69 -> V_70 ) ;
if ( V_22 -> signal -> V_2 == V_2 ) {
V_22 -> signal -> V_2 = NULL ;
V_82 ++ ;
}
if ( ! V_22 -> signal -> V_85 ) {
F_53 ( & V_22 -> V_69 -> V_70 ) ;
continue;
}
F_65 ( V_86 , V_87 , V_22 ) ;
F_65 ( V_88 , V_87 , V_22 ) ;
F_47 ( V_22 -> signal -> V_73 ) ;
F_8 ( & V_2 -> V_47 ) ;
V_83 = F_48 ( V_2 -> V_48 ) ;
if ( V_2 -> V_48 )
V_22 -> signal -> V_73 = F_48 ( V_2 -> V_48 ) ;
F_10 ( & V_2 -> V_47 ) ;
F_53 ( & V_22 -> V_69 -> V_70 ) ;
} F_57 ( V_2 -> V_71 , V_75 , V_22 ) ;
}
F_66 ( & V_84 ) ;
if ( V_83 ) {
if ( V_81 )
F_37 ( V_83 , V_86 , V_81 ) ;
F_47 ( V_83 ) ;
}
return V_82 ;
}
static void F_67 ( struct V_1 * V_2 , int V_81 )
{
struct V_6 * V_89 = NULL ;
struct V_6 * V_56 , * V_90 = NULL ;
struct V_7 * V_9 ;
int V_91 = 0 , V_92 ;
int V_82 ;
if ( ! V_2 )
return;
F_8 ( & V_93 ) ;
if ( V_94 && F_4 ( V_94 ) == V_2 ) {
V_90 = V_94 ;
V_94 = NULL ;
}
F_10 ( & V_93 ) ;
F_68 ( V_2 ) ;
if ( F_59 ( V_95 , & V_2 -> V_44 ) ) {
F_69 ( V_2 ) ;
return;
}
F_20 ( V_2 , L_8 ) ;
F_8 ( & V_12 ) ;
F_24 (priv, &tty->tty_files, list) {
V_56 = V_9 -> V_6 ;
if ( V_56 -> V_96 -> V_97 == V_98 )
V_89 = V_56 ;
if ( V_56 -> V_96 -> V_97 != V_99 )
continue;
V_91 ++ ;
F_70 ( - 1 , V_56 , 0 ) ;
V_56 -> V_96 = & V_100 ;
}
F_10 ( & V_12 ) ;
V_82 = F_63 ( V_2 , V_81 ) ;
while ( V_82 -- )
F_45 ( V_2 ) ;
F_71 ( V_2 ) ;
F_52 ( & V_2 -> V_47 ) ;
F_72 ( V_101 , & V_2 -> V_44 ) ;
F_72 ( V_78 , & V_2 -> V_44 ) ;
F_47 ( V_2 -> V_71 ) ;
F_47 ( V_2 -> V_48 ) ;
V_2 -> V_71 = NULL ;
V_2 -> V_48 = NULL ;
V_2 -> V_102 = 0 ;
F_53 ( & V_2 -> V_47 ) ;
if ( V_89 ) {
if ( V_2 -> V_42 -> V_103 )
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ )
V_2 -> V_42 -> V_103 ( V_2 , V_89 ) ;
} else if ( V_2 -> V_42 -> V_104 )
V_2 -> V_42 -> V_104 ( V_2 ) ;
F_73 ( V_95 , & V_2 -> V_44 ) ;
F_69 ( V_2 ) ;
if ( V_90 )
F_74 ( V_90 ) ;
}
static void F_75 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_76 ( V_106 , struct V_1 , V_107 ) ;
F_67 ( V_2 , 0 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
#ifdef F_78
char V_15 [ 64 ] ;
F_17 ( V_72 L_9 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_79 ( & V_2 -> V_107 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
#ifdef F_78
char V_15 [ 64 ] ;
F_17 ( V_72 L_10 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_67 ( V_2 , 0 ) ;
}
void F_81 ( void )
{
struct V_1 * V_2 ;
V_2 = F_54 () ;
if ( V_2 ) {
F_80 ( V_2 ) ;
F_45 ( V_2 ) ;
}
}
static void F_82 ( struct V_1 * V_2 )
{
#ifdef F_78
char V_15 [ 64 ] ;
F_17 ( V_72 L_11 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_67 ( V_2 , 1 ) ;
}
int F_83 ( struct V_6 * V_56 )
{
return ( V_56 -> V_96 == & V_100 ) ;
}
void F_84 ( int V_108 )
{
struct V_1 * V_2 ;
if ( ! V_46 -> signal -> V_85 )
return;
V_2 = F_54 () ;
if ( V_2 ) {
if ( V_108 && V_2 -> V_24 -> type != V_25 ) {
F_82 ( V_2 ) ;
} else {
struct V_74 * V_83 = F_85 ( V_2 ) ;
if ( V_83 ) {
F_37 ( V_83 , V_86 , V_108 ) ;
if ( ! V_108 )
F_37 ( V_83 , V_88 , V_108 ) ;
F_47 ( V_83 ) ;
}
}
F_45 ( V_2 ) ;
} else if ( V_108 ) {
struct V_74 * V_109 ;
F_52 ( & V_46 -> V_69 -> V_70 ) ;
V_109 = V_46 -> signal -> V_73 ;
V_46 -> signal -> V_73 = NULL ;
F_53 ( & V_46 -> V_69 -> V_70 ) ;
if ( V_109 ) {
F_37 ( V_109 , V_86 , V_108 ) ;
F_37 ( V_109 , V_88 , V_108 ) ;
F_47 ( V_109 ) ;
}
return;
}
F_52 ( & V_46 -> V_69 -> V_70 ) ;
F_47 ( V_46 -> signal -> V_73 ) ;
V_46 -> signal -> V_73 = NULL ;
V_2 = F_50 ( V_46 -> signal -> V_2 ) ;
if ( V_2 ) {
unsigned long V_44 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
F_47 ( V_2 -> V_71 ) ;
F_47 ( V_2 -> V_48 ) ;
V_2 -> V_71 = NULL ;
V_2 -> V_48 = NULL ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
F_45 ( V_2 ) ;
} else {
#ifdef F_78
F_17 ( V_72 L_12
L_13 , V_2 ) ;
#endif
}
F_53 ( & V_46 -> V_69 -> V_70 ) ;
F_64 ( & V_84 ) ;
F_55 ( F_49 ( V_46 ) ) ;
F_66 ( & V_84 ) ;
}
void F_86 ( void )
{
struct V_68 * V_110 = V_46 ;
F_84 ( 0 ) ;
F_44 ( V_110 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
if ( V_2 -> V_111 )
return;
V_2 -> V_111 = 1 ;
if ( V_2 -> V_42 -> V_112 )
V_2 -> V_42 -> V_112 ( V_2 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_32 ( & V_2 -> V_113 , V_44 ) ;
F_87 ( V_2 ) ;
F_34 ( & V_2 -> V_113 , V_44 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_111 || V_2 -> V_114 )
return;
V_2 -> V_111 = 0 ;
if ( V_2 -> V_42 -> V_115 )
V_2 -> V_42 -> V_115 ( V_2 ) ;
F_58 ( V_2 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_32 ( & V_2 -> V_113 , V_44 ) ;
F_89 ( V_2 ) ;
F_34 ( & V_2 -> V_113 , V_44 ) ;
}
static void F_91 ( struct V_116 * time )
{
unsigned long V_117 = F_92 () ;
if ( ( V_117 ^ time -> V_118 ) & ~ 7 )
time -> V_118 = V_117 ;
}
static T_2 F_93 ( struct V_6 * V_6 , char T_3 * V_15 , T_4 V_23 ,
T_5 * V_55 )
{
int V_119 ;
struct V_17 * V_17 = F_94 ( V_6 ) ;
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_76 * V_77 ;
if ( F_15 ( V_2 , V_17 , L_14 ) )
return - V_52 ;
if ( ! V_2 || ( F_59 ( V_120 , & V_2 -> V_44 ) ) )
return - V_52 ;
V_77 = F_95 ( V_2 ) ;
if ( V_77 -> V_42 -> V_121 )
V_119 = V_77 -> V_42 -> V_121 ( V_2 , V_6 , V_15 , V_23 ) ;
else
V_119 = - V_52 ;
F_61 ( V_77 ) ;
if ( V_119 > 0 )
F_91 ( & V_17 -> V_122 ) ;
return V_119 ;
}
static void F_96 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_123 ) ;
F_62 ( & V_2 -> V_80 , V_59 ) ;
}
static int F_97 ( struct V_1 * V_2 , int V_124 )
{
if ( ! F_98 ( & V_2 -> V_123 ) ) {
if ( V_124 )
return - V_125 ;
if ( F_99 ( & V_2 -> V_123 ) )
return - V_54 ;
}
return 0 ;
}
static inline T_2 F_100 (
T_2 (* V_97)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_15 ,
T_4 V_23 )
{
T_2 V_45 , V_126 = 0 ;
unsigned int V_127 ;
V_45 = F_97 ( V_2 , V_6 -> V_128 & V_129 ) ;
if ( V_45 < 0 )
return V_45 ;
V_127 = 2048 ;
if ( F_59 ( V_130 , & V_2 -> V_44 ) )
V_127 = 65536 ;
if ( V_23 < V_127 )
V_127 = V_23 ;
if ( V_2 -> V_131 < V_127 ) {
unsigned char * V_132 ;
if ( V_127 < 1024 )
V_127 = 1024 ;
V_132 = F_6 ( V_127 , V_10 ) ;
if ( ! V_132 ) {
V_45 = - V_11 ;
goto V_51;
}
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_131 = V_127 ;
V_2 -> V_4 = V_132 ;
}
for (; ; ) {
T_4 V_133 = V_23 ;
if ( V_133 > V_127 )
V_133 = V_127 ;
V_45 = - V_134 ;
if ( F_101 ( V_2 -> V_4 , V_15 , V_133 ) )
break;
V_45 = V_97 ( V_2 , V_6 , V_2 -> V_4 , V_133 ) ;
if ( V_45 <= 0 )
break;
V_126 += V_45 ;
V_15 += V_45 ;
V_23 -= V_45 ;
if ( ! V_23 )
break;
V_45 = - V_54 ;
if ( F_102 ( V_46 ) )
break;
F_103 () ;
}
if ( V_126 ) {
F_91 ( & F_94 ( V_6 ) -> V_135 ) ;
V_45 = V_126 ;
}
V_51:
F_96 ( V_2 ) ;
return V_45 ;
}
void F_104 ( struct V_1 * V_2 , char * V_136 )
{
if ( V_2 ) {
F_29 ( & V_2 -> V_123 ) ;
F_68 ( V_2 ) ;
if ( V_2 -> V_42 -> V_97 && V_2 -> V_23 > 0 ) {
F_69 ( V_2 ) ;
V_2 -> V_42 -> V_97 ( V_2 , V_136 , strlen ( V_136 ) ) ;
} else
F_69 ( V_2 ) ;
F_96 ( V_2 ) ;
}
return;
}
static T_2 V_99 ( struct V_6 * V_6 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_76 * V_77 ;
T_2 V_45 ;
if ( F_15 ( V_2 , F_94 ( V_6 ) , L_15 ) )
return - V_52 ;
if ( ! V_2 || ! V_2 -> V_42 -> V_97 ||
( F_59 ( V_120 , & V_2 -> V_44 ) ) )
return - V_52 ;
if ( V_2 -> V_42 -> V_137 == NULL )
F_17 ( V_138 L_16 ,
V_2 -> V_24 -> V_16 ) ;
V_77 = F_95 ( V_2 ) ;
if ( ! V_77 -> V_42 -> V_97 )
V_45 = - V_52 ;
else
V_45 = F_100 ( V_77 -> V_42 -> V_97 , V_2 , V_6 , V_15 , V_23 ) ;
F_61 ( V_77 ) ;
return V_45 ;
}
T_2 V_98 ( struct V_6 * V_6 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_6 * V_22 = NULL ;
F_8 ( & V_93 ) ;
if ( V_94 )
V_22 = F_105 ( V_94 ) ;
F_10 ( & V_93 ) ;
if ( V_22 ) {
T_2 V_36 ;
V_36 = F_106 ( V_22 , V_15 , V_23 , & V_22 -> V_139 ) ;
F_74 ( V_22 ) ;
return V_36 ;
}
return V_99 ( V_6 , V_15 , V_23 , V_55 ) ;
}
int F_107 ( struct V_1 * V_2 , char V_140 )
{
int V_141 = V_2 -> V_111 ;
if ( V_2 -> V_42 -> V_142 ) {
V_2 -> V_42 -> V_142 ( V_2 , V_140 ) ;
return 0 ;
}
if ( F_97 ( V_2 , 0 ) < 0 )
return - V_54 ;
if ( V_141 )
F_90 ( V_2 ) ;
V_2 -> V_42 -> V_97 ( V_2 , & V_140 , 1 ) ;
if ( V_141 )
F_88 ( V_2 ) ;
F_96 ( V_2 ) ;
return 0 ;
}
static void F_108 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
int V_119 = V_31 + V_24 -> V_143 ;
sprintf ( V_22 , L_17 ,
V_24 -> V_26 == V_27 ? L_18 : V_24 -> V_16 ,
V_144 [ V_119 >> 4 & 0xf ] , V_119 & 0xf ) ;
}
static T_2 F_109 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
if ( V_24 -> V_44 & V_145 )
return sprintf ( V_22 , L_19 , V_24 -> V_16 ) ;
else
return sprintf ( V_22 , L_20 , V_24 -> V_16 ,
V_31 + V_24 -> V_143 ) ;
}
static struct V_1 * F_110 ( struct V_29 * V_24 ,
struct V_17 * V_17 , int V_146 )
{
struct V_1 * V_2 ;
if ( V_24 -> V_42 -> V_147 )
V_2 = V_24 -> V_42 -> V_147 ( V_24 , V_17 , V_146 ) ;
else
V_2 = V_24 -> V_148 [ V_146 ] ;
if ( ! F_111 ( V_2 ) )
F_50 ( V_2 ) ;
return V_2 ;
}
int F_112 ( struct V_1 * V_2 )
{
struct V_149 * V_150 ;
int V_146 = V_2 -> V_31 ;
if ( V_2 -> V_24 -> V_44 & V_151 )
V_2 -> V_152 = V_2 -> V_24 -> V_153 ;
else {
V_150 = V_2 -> V_24 -> V_152 [ V_146 ] ;
if ( V_150 != NULL )
V_2 -> V_152 = * V_150 ;
else
V_2 -> V_152 = V_2 -> V_24 -> V_153 ;
}
V_2 -> V_152 . V_154 = F_113 ( & V_2 -> V_152 ) ;
V_2 -> V_152 . V_155 = F_114 ( & V_2 -> V_152 ) ;
return 0 ;
}
int F_115 ( struct V_29 * V_24 , struct V_1 * V_2 )
{
int V_45 = F_112 ( V_2 ) ;
if ( V_45 )
return V_45 ;
F_26 ( V_24 ) ;
V_2 -> V_23 ++ ;
V_24 -> V_148 [ V_2 -> V_31 ] = V_2 ;
return 0 ;
}
static int F_116 ( struct V_29 * V_24 ,
struct V_1 * V_2 )
{
return V_24 -> V_42 -> V_156 ? V_24 -> V_42 -> V_156 ( V_24 , V_2 ) :
F_115 ( V_24 , V_2 ) ;
}
void F_117 ( struct V_29 * V_24 , struct V_1 * V_2 )
{
if ( V_24 -> V_42 -> remove )
V_24 -> V_42 -> remove ( V_24 , V_2 ) ;
else
V_24 -> V_148 [ V_2 -> V_31 ] = NULL ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_29 * V_24 = V_2 -> V_24 ;
if ( ! V_2 -> V_23 )
return - V_52 ;
if ( V_24 -> type == V_25 &&
V_24 -> V_26 == V_157 )
return - V_52 ;
if ( F_59 ( V_158 , & V_2 -> V_44 ) && ! F_119 ( V_159 ) )
return - V_160 ;
V_2 -> V_23 ++ ;
F_120 ( ! V_2 -> V_161 ) ;
return 0 ;
}
struct V_1 * F_121 ( struct V_29 * V_24 , int V_146 )
{
struct V_1 * V_2 ;
int V_162 ;
if ( ! F_122 ( V_24 -> V_163 ) )
return F_123 ( - V_164 ) ;
V_2 = F_124 ( V_24 , V_146 ) ;
if ( ! V_2 ) {
V_162 = - V_11 ;
goto V_165;
}
F_68 ( V_2 ) ;
V_162 = F_116 ( V_24 , V_2 ) ;
if ( V_162 < 0 )
goto V_166;
if ( ! V_2 -> V_167 )
V_2 -> V_167 = V_24 -> V_168 [ V_146 ] ;
F_125 ( ! V_2 -> V_167 ,
L_21 ,
V_169 , V_2 -> V_24 -> V_16 ) ;
V_2 -> V_167 -> V_170 = V_2 ;
V_162 = F_126 ( V_2 , V_2 -> V_28 ) ;
if ( V_162 )
goto V_171;
return V_2 ;
V_166:
F_69 ( V_2 ) ;
F_127 ( V_2 ) ;
F_1 ( V_2 ) ;
V_165:
F_128 ( V_24 -> V_163 ) ;
return F_123 ( V_162 ) ;
V_171:
F_69 ( V_2 ) ;
F_129 ( V_172 L_22
L_23 , V_146 ) ;
F_130 ( V_2 , V_146 ) ;
return F_123 ( V_162 ) ;
}
void F_131 ( struct V_1 * V_2 )
{
struct V_149 * V_150 ;
int V_146 = V_2 -> V_31 ;
if ( V_2 -> V_24 -> V_44 & V_151 )
return;
V_150 = V_2 -> V_24 -> V_152 [ V_146 ] ;
if ( V_150 == NULL ) {
V_150 = F_6 ( sizeof( struct V_149 ) , V_10 ) ;
if ( V_150 == NULL ) {
F_132 ( L_24 ) ;
return;
}
V_2 -> V_24 -> V_152 [ V_146 ] = V_150 ;
}
* V_150 = V_2 -> V_152 ;
}
static void F_133 ( struct V_1 * V_2 )
{
F_134 ( & V_2 -> V_173 ) ;
F_134 ( & V_2 -> V_107 ) ;
if ( V_2 -> V_28 ) {
F_134 ( & V_2 -> V_28 -> V_173 ) ;
F_134 ( & V_2 -> V_28 -> V_107 ) ;
}
}
static void F_135 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_76 ( V_106 , struct V_1 , V_107 ) ;
struct V_29 * V_24 = V_2 -> V_24 ;
struct V_174 * V_163 = V_24 -> V_163 ;
if ( V_2 -> V_42 -> V_175 )
V_2 -> V_42 -> V_175 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_136 ( V_24 ) ;
F_128 ( V_163 ) ;
F_8 ( & V_12 ) ;
F_137 ( & V_2 -> V_14 ) ;
F_10 ( & V_12 ) ;
F_47 ( V_2 -> V_48 ) ;
F_47 ( V_2 -> V_71 ) ;
F_1 ( V_2 ) ;
}
static void F_138 ( struct V_176 * V_176 )
{
struct V_1 * V_2 = F_76 ( V_176 , struct V_1 , V_176 ) ;
F_139 ( & V_2 -> V_107 , F_135 ) ;
F_79 ( & V_2 -> V_107 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( V_2 )
F_140 ( & V_2 -> V_176 , F_138 ) ;
}
static void F_130 ( struct V_1 * V_2 , int V_146 )
{
F_120 ( V_2 -> V_31 != V_146 ) ;
F_120 ( ! F_141 ( & V_41 ) ) ;
if ( V_2 -> V_42 -> V_177 )
V_2 -> V_42 -> V_177 ( V_2 ) ;
F_131 ( V_2 ) ;
F_117 ( V_2 -> V_24 , V_2 ) ;
V_2 -> V_167 -> V_170 = NULL ;
if ( V_2 -> V_28 )
V_2 -> V_28 -> V_167 -> V_170 = NULL ;
F_142 ( & V_2 -> V_167 -> V_15 . V_106 ) ;
F_45 ( V_2 -> V_28 ) ;
F_45 ( V_2 ) ;
}
static int F_143 ( struct V_1 * V_2 , int V_146 )
{
#ifdef F_16
if ( V_146 < 0 || V_146 >= V_2 -> V_24 -> V_35 ) {
F_17 ( V_72 L_25 ,
V_169 , V_2 -> V_16 ) ;
return - 1 ;
}
if ( V_2 -> V_24 -> V_44 & V_178 )
return 0 ;
if ( V_2 != V_2 -> V_24 -> V_148 [ V_146 ] ) {
F_17 ( V_72 L_26 ,
V_169 , V_146 , V_2 -> V_16 ) ;
return - 1 ;
}
if ( V_2 -> V_24 -> V_179 ) {
struct V_1 * V_180 = V_2 -> V_28 ;
if ( V_180 != V_2 -> V_24 -> V_179 -> V_148 [ V_146 ] ) {
F_17 ( V_72 L_27 ,
V_169 , V_146 , V_2 -> V_16 ) ;
return - 1 ;
}
if ( V_180 -> V_28 != V_2 ) {
F_17 ( V_72 L_28 , V_169 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_144 ( struct V_17 * V_17 , struct V_6 * V_56 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
struct V_1 * V_180 = NULL ;
int V_181 , V_182 ;
int V_146 ;
char V_15 [ 64 ] ;
long V_183 = 0 ;
int V_184 = 1 ;
if ( F_15 ( V_2 , V_17 , V_169 ) )
return 0 ;
F_68 ( V_2 ) ;
F_20 ( V_2 , V_169 ) ;
F_70 ( - 1 , V_56 , 0 ) ;
V_146 = V_2 -> V_31 ;
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_157 )
V_180 = V_2 -> V_28 ;
if ( F_143 ( V_2 , V_146 ) ) {
F_69 ( V_2 ) ;
return 0 ;
}
#ifdef F_78
F_17 ( V_72 L_29 , V_169 ,
F_14 ( V_2 , V_15 ) , V_2 -> V_23 ) ;
#endif
if ( V_2 -> V_42 -> V_103 )
V_2 -> V_42 -> V_103 ( V_2 , V_56 ) ;
F_145 ( V_180 ) ;
while ( 1 ) {
V_181 = 0 ;
if ( V_2 -> V_23 <= 1 ) {
if ( F_146 ( & V_2 -> V_185 ) ) {
F_147 ( & V_2 -> V_185 , V_58 ) ;
V_181 ++ ;
}
if ( F_146 ( & V_2 -> V_80 ) ) {
F_147 ( & V_2 -> V_80 , V_59 ) ;
V_181 ++ ;
}
}
if ( V_180 && V_180 -> V_23 <= 1 ) {
if ( F_146 ( & V_180 -> V_185 ) ) {
F_147 ( & V_180 -> V_185 , V_58 ) ;
V_181 ++ ;
}
if ( F_146 ( & V_180 -> V_80 ) ) {
F_147 ( & V_180 -> V_80 , V_59 ) ;
V_181 ++ ;
}
}
if ( ! V_181 )
break;
if ( V_184 ) {
V_184 = 0 ;
F_17 ( V_19 L_30 ,
V_169 , F_14 ( V_2 , V_15 ) ) ;
}
F_148 ( V_183 ) ;
if ( V_183 < 120 * V_186 )
V_183 = 2 * V_183 + 1 ;
else
V_183 = V_187 ;
}
if ( V_180 ) {
if ( -- V_180 -> V_23 < 0 ) {
F_17 ( V_19 L_31 ,
V_169 , V_180 -> V_23 , F_14 ( V_180 , V_15 ) ) ;
V_180 -> V_23 = 0 ;
}
}
if ( -- V_2 -> V_23 < 0 ) {
F_17 ( V_19 L_32 ,
V_169 , V_2 -> V_23 , F_14 ( V_2 , V_15 ) ) ;
V_2 -> V_23 = 0 ;
}
F_12 ( V_56 ) ;
if ( ! V_2 -> V_23 ) {
F_64 ( & V_84 ) ;
F_55 ( V_2 -> V_71 ) ;
if ( V_180 )
F_55 ( V_180 -> V_71 ) ;
F_66 ( & V_84 ) ;
}
V_182 = ! V_2 -> V_23 && ! ( V_180 && V_180 -> V_23 ) ;
F_149 ( V_180 ) ;
F_69 ( V_2 ) ;
if ( ! V_182 )
return 0 ;
#ifdef F_78
F_17 ( V_72 L_33 , V_169 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_150 ( V_2 ) ;
F_133 ( V_2 ) ;
#ifdef F_78
F_17 ( V_72 L_34 , V_169 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_29 ( & V_41 ) ;
F_130 ( V_2 , V_146 ) ;
F_30 ( & V_41 ) ;
return 0 ;
}
static struct V_1 * F_151 ( T_1 V_30 , struct V_6 * V_56 )
{
struct V_1 * V_2 ;
int V_162 ;
if ( V_30 != F_25 ( V_188 , 0 ) )
return NULL ;
V_2 = F_54 () ;
if ( ! V_2 )
return F_123 ( - V_189 ) ;
V_56 -> V_128 |= V_190 ;
F_68 ( V_2 ) ;
F_45 ( V_2 ) ;
V_162 = F_118 ( V_2 ) ;
if ( V_162 < 0 ) {
F_69 ( V_2 ) ;
V_2 = F_123 ( V_162 ) ;
}
return V_2 ;
}
static struct V_29 * F_152 ( T_1 V_30 , struct V_6 * V_56 ,
int * V_191 , int * V_31 )
{
struct V_29 * V_24 ;
switch ( V_30 ) {
#ifdef F_153
case F_25 ( V_192 , 0 ) : {
extern struct V_29 * V_193 ;
V_24 = F_26 ( V_193 ) ;
* V_31 = V_194 ;
* V_191 = 1 ;
break;
}
#endif
case F_25 ( V_188 , 1 ) : {
struct V_29 * V_193 = F_154 ( V_31 ) ;
if ( V_193 ) {
V_24 = F_26 ( V_193 ) ;
if ( V_24 ) {
V_56 -> V_128 |= V_190 ;
* V_191 = 1 ;
break;
}
}
return F_123 ( - V_164 ) ;
}
default:
V_24 = F_23 ( V_30 , V_31 ) ;
if ( ! V_24 )
return F_123 ( - V_164 ) ;
break;
}
return V_24 ;
}
static int F_155 ( struct V_17 * V_17 , struct V_6 * V_56 )
{
struct V_1 * V_2 ;
int V_191 , V_162 ;
struct V_29 * V_24 = NULL ;
int V_31 ;
T_1 V_30 = V_17 -> V_195 ;
unsigned V_196 = V_56 -> V_128 ;
F_156 ( V_17 , V_56 ) ;
V_197:
V_162 = F_5 ( V_56 ) ;
if ( V_162 )
return - V_11 ;
V_191 = V_56 -> V_128 & V_198 ;
V_31 = - 1 ;
V_162 = 0 ;
V_2 = F_151 ( V_30 , V_56 ) ;
if ( ! V_2 ) {
F_29 ( & V_41 ) ;
V_24 = F_152 ( V_30 , V_56 , & V_191 , & V_31 ) ;
if ( F_111 ( V_24 ) ) {
V_162 = F_157 ( V_24 ) ;
goto V_199;
}
V_2 = F_110 ( V_24 , V_17 , V_31 ) ;
if ( F_111 ( V_2 ) ) {
V_162 = F_157 ( V_2 ) ;
goto V_199;
}
if ( V_2 ) {
F_30 ( & V_41 ) ;
F_68 ( V_2 ) ;
F_45 ( V_2 ) ;
V_162 = F_118 ( V_2 ) ;
if ( V_162 < 0 ) {
F_69 ( V_2 ) ;
V_2 = F_123 ( V_162 ) ;
}
} else {
V_2 = F_121 ( V_24 , V_31 ) ;
F_30 ( & V_41 ) ;
}
F_136 ( V_24 ) ;
}
if ( F_111 ( V_2 ) ) {
V_162 = F_157 ( V_2 ) ;
goto V_200;
}
F_7 ( V_2 , V_56 ) ;
F_20 ( V_2 , V_169 ) ;
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_157 )
V_191 = 1 ;
#ifdef F_78
F_17 ( V_72 L_35 , V_169 , V_2 -> V_16 ) ;
#endif
if ( V_2 -> V_42 -> V_201 )
V_162 = V_2 -> V_42 -> V_201 ( V_2 , V_56 ) ;
else
V_162 = - V_164 ;
V_56 -> V_128 = V_196 ;
if ( V_162 ) {
#ifdef F_78
F_17 ( V_72 L_36 , V_169 ,
V_162 , V_2 -> V_16 ) ;
#endif
F_69 ( V_2 ) ;
F_144 ( V_17 , V_56 ) ;
if ( V_162 != - V_54 )
return V_162 ;
if ( F_102 ( V_46 ) )
return V_162 ;
F_158 () ;
if ( F_83 ( V_56 ) )
V_56 -> V_96 = & V_202 ;
goto V_197;
}
F_72 ( V_95 , & V_2 -> V_44 ) ;
F_64 ( & V_84 ) ;
F_52 ( & V_46 -> V_69 -> V_70 ) ;
if ( ! V_191 &&
V_46 -> signal -> V_85 &&
! V_46 -> signal -> V_2 &&
V_2 -> V_71 == NULL )
F_46 ( V_2 ) ;
F_53 ( & V_46 -> V_69 -> V_70 ) ;
F_66 ( & V_84 ) ;
F_69 ( V_2 ) ;
return 0 ;
V_199:
F_30 ( & V_41 ) ;
if ( ! F_159 ( V_24 ) )
F_136 ( V_24 ) ;
V_200:
F_11 ( V_56 ) ;
return V_162 ;
}
static unsigned int F_160 ( struct V_6 * V_56 , T_6 * V_57 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
struct V_76 * V_77 ;
int V_45 = 0 ;
if ( F_15 ( V_2 , F_94 ( V_56 ) , L_37 ) )
return 0 ;
V_77 = F_95 ( V_2 ) ;
if ( V_77 -> V_42 -> V_203 )
V_45 = V_77 -> V_42 -> V_203 ( V_2 , V_56 , V_57 ) ;
F_61 ( V_77 ) ;
return V_45 ;
}
static int F_70 ( int V_204 , struct V_6 * V_56 , int V_205 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
struct V_76 * V_161 ;
unsigned long V_44 ;
int V_162 = 0 ;
if ( F_15 ( V_2 , F_94 ( V_56 ) , L_38 ) )
goto V_51;
V_162 = F_161 ( V_204 , V_56 , V_205 , & V_2 -> V_206 ) ;
if ( V_162 <= 0 )
goto V_51;
V_161 = F_60 ( V_2 ) ;
if ( V_161 ) {
if ( V_161 -> V_42 -> V_206 )
V_161 -> V_42 -> V_206 ( V_2 , V_205 ) ;
F_61 ( V_161 ) ;
}
if ( V_205 ) {
enum V_207 type ;
struct V_74 * V_74 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_48 ) {
V_74 = V_2 -> V_48 ;
type = V_208 ;
} else {
V_74 = F_162 ( V_46 ) ;
type = V_209 ;
}
F_48 ( V_74 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
F_163 ( V_56 , V_74 , type , 0 ) ;
F_47 ( V_74 ) ;
V_162 = 0 ;
}
V_51:
return V_162 ;
}
static int F_164 ( int V_204 , struct V_6 * V_56 , int V_205 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
int V_162 ;
F_68 ( V_2 ) ;
V_162 = F_70 ( V_204 , V_56 , V_205 ) ;
F_69 ( V_2 ) ;
return V_162 ;
}
static int F_165 ( struct V_1 * V_2 , char T_3 * V_22 )
{
char V_140 , V_210 = 0 ;
struct V_76 * V_77 ;
if ( ( V_46 -> signal -> V_2 != V_2 ) && ! F_119 ( V_159 ) )
return - V_211 ;
if ( F_166 ( V_140 , V_22 ) )
return - V_134 ;
F_167 ( V_2 , V_140 ) ;
V_77 = F_95 ( V_2 ) ;
V_77 -> V_42 -> V_212 ( V_2 , & V_140 , & V_210 , 1 ) ;
F_61 ( V_77 ) ;
return 0 ;
}
static int F_168 ( struct V_1 * V_2 , struct V_213 T_3 * V_65 )
{
int V_214 ;
F_29 ( & V_2 -> V_215 ) ;
V_214 = F_169 ( V_65 , & V_2 -> V_213 , sizeof( * V_65 ) ) ;
F_30 ( & V_2 -> V_215 ) ;
return V_214 ? - V_134 : 0 ;
}
int F_170 ( struct V_1 * V_2 , struct V_213 * V_216 )
{
struct V_74 * V_48 ;
F_29 ( & V_2 -> V_215 ) ;
if ( ! memcmp ( V_216 , & V_2 -> V_213 , sizeof( * V_216 ) ) )
goto V_217;
V_48 = F_85 ( V_2 ) ;
if ( V_48 )
F_37 ( V_48 , V_218 , 1 ) ;
F_47 ( V_48 ) ;
V_2 -> V_213 = * V_216 ;
V_217:
F_30 ( & V_2 -> V_215 ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , struct V_213 T_3 * V_65 )
{
struct V_213 V_219 ;
if ( F_101 ( & V_219 , V_65 , sizeof( * V_65 ) ) )
return - V_134 ;
if ( V_2 -> V_42 -> V_220 )
return V_2 -> V_42 -> V_220 ( V_2 , & V_219 ) ;
else
return F_170 ( V_2 , & V_219 ) ;
}
static int F_172 ( struct V_6 * V_6 )
{
if ( ! F_119 ( V_159 ) )
return - V_211 ;
if ( V_6 -> V_96 -> V_97 == V_98 ) {
struct V_6 * V_90 ;
F_8 ( & V_93 ) ;
V_90 = V_94 ;
V_94 = NULL ;
F_10 ( & V_93 ) ;
if ( V_90 )
F_74 ( V_90 ) ;
return 0 ;
}
F_8 ( & V_93 ) ;
if ( V_94 ) {
F_10 ( & V_93 ) ;
return - V_160 ;
}
V_94 = F_105 ( V_6 ) ;
F_10 ( & V_93 ) ;
return 0 ;
}
static int F_173 ( struct V_6 * V_6 , int T_3 * V_22 )
{
int V_221 ;
if ( F_166 ( V_221 , V_22 ) )
return - V_134 ;
F_8 ( & V_6 -> V_222 ) ;
if ( V_221 )
V_6 -> V_128 |= V_190 ;
else
V_6 -> V_128 &= ~ V_190 ;
F_10 ( & V_6 -> V_222 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , int V_65 )
{
int V_45 = 0 ;
F_68 ( V_2 ) ;
F_64 ( & V_84 ) ;
if ( V_46 -> signal -> V_85 && ( F_49 ( V_46 ) == V_2 -> V_71 ) )
goto V_223;
if ( ! V_46 -> signal -> V_85 || V_46 -> signal -> V_2 ) {
V_45 = - V_211 ;
goto V_223;
}
if ( V_2 -> V_71 ) {
if ( V_65 == 1 && F_119 ( V_159 ) ) {
F_55 ( V_2 -> V_71 ) ;
} else {
V_45 = - V_211 ;
goto V_223;
}
}
F_51 ( V_2 ) ;
V_223:
F_66 ( & V_84 ) ;
F_69 ( V_2 ) ;
return V_45 ;
}
struct V_74 * F_85 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
struct V_74 * V_48 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
V_48 = F_48 ( V_2 -> V_48 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
return V_48 ;
}
static struct V_74 * F_175 ( struct V_74 * V_48 )
{
struct V_68 * V_22 ;
struct V_74 * V_224 = NULL ;
V_22 = F_176 ( V_48 , V_208 ) ;
if ( V_22 == NULL )
V_22 = F_176 ( V_48 , V_209 ) ;
if ( V_22 != NULL )
V_224 = F_49 ( V_22 ) ;
return V_224 ;
}
static int F_177 ( struct V_1 * V_2 , struct V_1 * V_225 , T_7 T_3 * V_22 )
{
struct V_74 * V_74 ;
int V_45 ;
if ( V_2 == V_225 && V_46 -> signal -> V_2 != V_225 )
return - V_67 ;
V_74 = F_85 ( V_225 ) ;
V_45 = F_178 ( F_179 ( V_74 ) , V_22 ) ;
F_47 ( V_74 ) ;
return V_45 ;
}
static int F_180 ( struct V_1 * V_2 , struct V_1 * V_225 , T_7 T_3 * V_22 )
{
struct V_74 * V_48 ;
T_7 V_226 ;
int V_162 = F_31 ( V_225 ) ;
unsigned long V_44 ;
if ( V_162 == - V_52 )
return - V_67 ;
if ( V_162 )
return V_162 ;
if ( ! V_46 -> signal -> V_2 ||
( V_46 -> signal -> V_2 != V_225 ) ||
( V_225 -> V_71 != F_49 ( V_46 ) ) )
return - V_67 ;
if ( F_166 ( V_226 , V_22 ) )
return - V_134 ;
if ( V_226 < 0 )
return - V_227 ;
F_181 () ;
V_48 = F_182 ( V_226 ) ;
V_162 = - V_228 ;
if ( ! V_48 )
goto V_49;
V_162 = - V_211 ;
if ( F_175 ( V_48 ) != F_49 ( V_46 ) )
goto V_49;
V_162 = 0 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
F_47 ( V_225 -> V_48 ) ;
V_225 -> V_48 = F_48 ( V_48 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
V_49:
F_183 () ;
return V_162 ;
}
static int F_184 ( struct V_1 * V_2 , struct V_1 * V_225 , T_7 T_3 * V_22 )
{
if ( V_2 == V_225 && V_46 -> signal -> V_2 != V_225 )
return - V_67 ;
if ( ! V_225 -> V_71 )
return - V_67 ;
return F_178 ( F_179 ( V_225 -> V_71 ) , V_22 ) ;
}
static int F_185 ( struct V_1 * V_2 , int T_3 * V_22 )
{
int V_161 ;
int V_45 ;
if ( F_166 ( V_161 , V_22 ) )
return - V_134 ;
V_45 = F_186 ( V_2 , V_161 ) ;
return V_45 ;
}
static int F_187 ( struct V_1 * V_2 , unsigned int V_229 )
{
int V_162 ;
if ( V_2 -> V_42 -> V_230 == NULL )
return 0 ;
if ( V_2 -> V_24 -> V_44 & V_231 )
V_162 = V_2 -> V_42 -> V_230 ( V_2 , V_229 ) ;
else {
if ( F_97 ( V_2 , 0 ) < 0 )
return - V_232 ;
V_162 = V_2 -> V_42 -> V_230 ( V_2 , - 1 ) ;
if ( V_162 )
goto V_51;
if ( ! F_102 ( V_46 ) )
F_188 ( V_229 ) ;
V_162 = V_2 -> V_42 -> V_230 ( V_2 , 0 ) ;
V_51:
F_96 ( V_2 ) ;
if ( F_102 ( V_46 ) )
V_162 = - V_232 ;
}
return V_162 ;
}
static int F_189 ( struct V_1 * V_2 , int T_3 * V_22 )
{
int V_162 = - V_227 ;
if ( V_2 -> V_42 -> V_233 ) {
V_162 = V_2 -> V_42 -> V_233 ( V_2 ) ;
if ( V_162 >= 0 )
V_162 = F_178 ( V_162 , V_22 ) ;
}
return V_162 ;
}
static int F_190 ( struct V_1 * V_2 , unsigned int V_64 ,
unsigned T_3 * V_22 )
{
int V_162 ;
unsigned int V_234 , V_235 , V_236 ;
if ( V_2 -> V_42 -> V_237 == NULL )
return - V_227 ;
V_162 = F_166 ( V_236 , V_22 ) ;
if ( V_162 )
return V_162 ;
V_234 = V_235 = 0 ;
switch ( V_64 ) {
case V_238 :
V_234 = V_236 ;
break;
case V_239 :
V_235 = V_236 ;
break;
case V_240 :
V_234 = V_236 ;
V_235 = ~ V_236 ;
break;
}
V_234 &= V_241 | V_242 | V_243 | V_244 | V_245 ;
V_235 &= V_241 | V_242 | V_243 | V_244 | V_245 ;
return V_2 -> V_42 -> V_237 ( V_2 , V_234 , V_235 ) ;
}
static int F_191 ( struct V_1 * V_2 , void T_3 * V_65 )
{
int V_162 = - V_227 ;
struct V_246 V_247 ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
if ( V_2 -> V_42 -> V_248 )
V_162 = V_2 -> V_42 -> V_248 ( V_2 , & V_247 ) ;
if ( V_162 != 0 )
return V_162 ;
if ( F_169 ( V_65 , & V_247 , sizeof( V_247 ) ) )
return - V_134 ;
return 0 ;
}
static void F_192 ( struct V_249 T_3 * V_250 )
{
static F_193 ( V_251 ,
V_252 ,
V_253 ) ;
char V_254 [ V_255 ] ;
int V_44 ;
if ( F_166 ( V_44 , & V_250 -> V_44 ) )
return;
V_44 &= V_256 ;
if ( V_44 && F_194 ( & V_251 ) )
F_195 ( L_39 ,
V_169 , F_196 ( V_254 , V_46 ) , V_44 ) ;
}
static struct V_1 * F_197 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_157 )
V_2 = V_2 -> V_28 ;
return V_2 ;
}
long F_198 ( struct V_6 * V_6 , unsigned int V_64 , unsigned long V_65 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_1 * V_225 ;
void T_3 * V_22 = ( void T_3 * ) V_65 ;
int V_162 ;
struct V_76 * V_77 ;
if ( F_15 ( V_2 , F_94 ( V_6 ) , L_40 ) )
return - V_227 ;
V_225 = F_197 ( V_2 ) ;
switch ( V_64 ) {
case V_257 :
case V_258 :
case V_259 :
case V_260 :
case V_261 :
V_162 = F_31 ( V_2 ) ;
if ( V_162 )
return V_162 ;
if ( V_64 != V_259 ) {
F_199 ( V_2 , 0 ) ;
if ( F_102 ( V_46 ) )
return - V_232 ;
}
break;
}
switch ( V_64 ) {
case V_262 :
return F_165 ( V_2 , V_22 ) ;
case V_263 :
return F_168 ( V_225 , V_22 ) ;
case V_264 :
return F_171 ( V_225 , V_22 ) ;
case V_265 :
return V_225 != V_2 ? - V_227 : F_172 ( V_6 ) ;
case V_266 :
return F_173 ( V_6 , V_22 ) ;
case V_267 :
F_73 ( V_158 , & V_2 -> V_44 ) ;
return 0 ;
case V_268 :
F_72 ( V_158 , & V_2 -> V_44 ) ;
return 0 ;
case V_269 :
{
int V_270 = F_59 ( V_158 , & V_2 -> V_44 ) ;
return F_178 ( V_270 , ( int T_3 * ) V_22 ) ;
}
case V_271 :
if ( V_46 -> signal -> V_2 != V_2 )
return - V_67 ;
F_86 () ;
return 0 ;
case V_272 :
return F_174 ( V_2 , V_65 ) ;
case V_273 :
return F_177 ( V_2 , V_225 , V_22 ) ;
case V_66 :
return F_180 ( V_2 , V_225 , V_22 ) ;
case V_274 :
return F_184 ( V_2 , V_225 , V_22 ) ;
case V_275 :
return F_178 ( V_2 -> V_161 -> V_42 -> V_35 , ( int T_3 * ) V_22 ) ;
case V_257 :
return F_185 ( V_2 , V_22 ) ;
case V_276 :
if ( ! F_119 ( V_159 ) )
return - V_211 ;
F_80 ( V_2 ) ;
return 0 ;
case V_277 :
{
unsigned int V_45 = F_200 ( F_201 ( V_225 ) ) ;
return F_178 ( V_45 , ( unsigned int T_3 * ) V_22 ) ;
}
case V_258 :
if ( V_2 -> V_42 -> V_230 )
return V_2 -> V_42 -> V_230 ( V_2 , - 1 ) ;
return 0 ;
case V_259 :
if ( V_2 -> V_42 -> V_230 )
return V_2 -> V_42 -> V_230 ( V_2 , 0 ) ;
return 0 ;
case V_260 :
if ( ! V_65 )
return F_187 ( V_2 , 250 ) ;
return 0 ;
case V_261 :
return F_187 ( V_2 , V_65 ? V_65 * 100 : 250 ) ;
case V_278 :
return F_189 ( V_2 , V_22 ) ;
case V_240 :
case V_239 :
case V_238 :
return F_190 ( V_2 , V_64 , V_22 ) ;
case V_279 :
V_162 = F_191 ( V_2 , V_22 ) ;
if ( V_162 != - V_227 )
return V_162 ;
break;
case V_280 :
switch ( V_65 ) {
case V_281 :
case V_282 :
F_202 ( V_2 , NULL ) ;
break;
}
break;
case V_283 :
F_192 ( V_22 ) ;
break;
}
if ( V_2 -> V_42 -> V_284 ) {
V_162 = V_2 -> V_42 -> V_284 ( V_2 , V_64 , V_65 ) ;
if ( V_162 != - V_285 )
return V_162 ;
}
V_77 = F_95 ( V_2 ) ;
V_162 = - V_227 ;
if ( V_77 -> V_42 -> V_284 ) {
V_162 = V_77 -> V_42 -> V_284 ( V_2 , V_6 , V_64 , V_65 ) ;
if ( V_162 == - V_285 )
V_162 = - V_67 ;
}
F_61 ( V_77 ) ;
return V_162 ;
}
static long F_203 ( struct V_6 * V_6 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_76 * V_77 ;
int V_162 = - V_285 ;
if ( F_15 ( V_2 , F_94 ( V_6 ) , L_40 ) )
return - V_227 ;
if ( V_2 -> V_42 -> V_286 ) {
V_162 = V_2 -> V_42 -> V_286 ( V_2 , V_64 , V_65 ) ;
if ( V_162 != - V_285 )
return V_162 ;
}
V_77 = F_95 ( V_2 ) ;
if ( V_77 -> V_42 -> V_286 )
V_162 = V_77 -> V_42 -> V_286 ( V_2 , V_6 , V_64 , V_65 ) ;
else
V_162 = F_204 ( V_2 , V_6 , V_64 , V_65 ) ;
F_61 ( V_77 ) ;
return V_162 ;
}
static int F_205 ( const void * V_287 , struct V_6 * V_6 , unsigned V_204 )
{
if ( F_206 ( V_6 -> V_96 -> V_121 != F_93 ) )
return 0 ;
return F_4 ( V_6 ) != V_287 ? 0 : V_204 + 1 ;
}
void F_207 ( struct V_1 * V_2 )
{
#ifdef F_208
F_77 ( V_2 ) ;
#else
struct V_68 * V_288 , * V_22 ;
struct V_74 * V_71 ;
int V_119 ;
if ( ! V_2 )
return;
V_71 = V_2 -> V_71 ;
F_209 ( V_2 ) ;
F_210 ( V_2 ) ;
F_64 ( & V_84 ) ;
F_56 (session, PIDTYPE_SID, p) {
F_17 ( V_289 L_41
L_42 ,
F_211 ( V_22 ) , V_22 -> V_254 ) ;
F_212 ( V_290 , V_22 , 1 ) ;
} F_57 ( V_71 , V_75 , V_22 ) ;
F_213 (g, p) {
if ( V_22 -> signal -> V_2 == V_2 ) {
F_17 ( V_289 L_41
L_42 ,
F_211 ( V_22 ) , V_22 -> V_254 ) ;
F_212 ( V_290 , V_22 , 1 ) ;
continue;
}
F_214 ( V_22 ) ;
V_119 = F_215 ( V_22 -> V_291 , 0 , F_205 , V_2 ) ;
if ( V_119 != 0 ) {
F_17 ( V_289 L_41
L_43 ,
F_211 ( V_22 ) , V_22 -> V_254 , V_119 - 1 ) ;
F_216 ( V_290 , V_22 ) ;
}
F_217 ( V_22 ) ;
} F_218 ( V_288 , V_22 ) ;
F_66 ( & V_84 ) ;
#endif
}
static void F_219 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_76 ( V_106 , struct V_1 , V_173 ) ;
F_207 ( V_2 ) ;
}
void F_220 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_79 ( & V_2 -> V_173 ) ;
}
static int F_221 ( struct V_30 * V_3 , const void * V_292 )
{
const T_1 * V_293 = V_292 ;
return V_3 -> V_293 == * V_293 ;
}
static struct V_30 * F_222 ( struct V_1 * V_2 )
{
T_1 V_293 = F_201 ( V_2 ) ;
return F_223 ( V_294 , NULL , & V_293 , F_221 ) ;
}
struct V_1 * F_124 ( struct V_29 * V_24 , int V_146 )
{
struct V_1 * V_2 ;
V_2 = F_224 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_225 ( & V_2 -> V_176 ) ;
V_2 -> V_5 = V_20 ;
F_226 ( V_2 ) ;
V_2 -> V_71 = NULL ;
V_2 -> V_48 = NULL ;
F_227 ( & V_2 -> V_295 ) ;
F_227 ( & V_2 -> V_296 ) ;
F_228 ( & V_2 -> V_297 ) ;
F_227 ( & V_2 -> V_215 ) ;
F_229 ( & V_2 -> V_298 ) ;
F_230 ( & V_2 -> V_80 ) ;
F_230 ( & V_2 -> V_185 ) ;
F_139 ( & V_2 -> V_107 , F_75 ) ;
F_227 ( & V_2 -> V_123 ) ;
F_231 ( & V_2 -> V_47 ) ;
F_231 ( & V_2 -> V_113 ) ;
F_232 ( & V_2 -> V_14 ) ;
F_139 ( & V_2 -> V_173 , F_219 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_42 = V_24 -> V_42 ;
V_2 -> V_31 = V_146 ;
F_109 ( V_24 , V_146 , V_2 -> V_16 ) ;
V_2 -> V_3 = F_222 ( V_2 ) ;
return V_2 ;
}
void F_127 ( struct V_1 * V_2 )
{
F_233 ( V_2 ) ;
}
int F_234 ( struct V_1 * V_2 , unsigned char V_140 )
{
if ( V_2 -> V_42 -> V_299 )
return V_2 -> V_42 -> V_299 ( V_2 , V_140 ) ;
return V_2 -> V_42 -> V_97 ( V_2 , & V_140 , 1 ) ;
}
static int F_235 ( struct V_29 * V_24 , T_1 V_3 ,
unsigned int V_31 , unsigned int V_23 )
{
F_236 ( & V_24 -> V_300 [ V_31 ] , & V_202 ) ;
V_24 -> V_300 [ V_31 ] . V_163 = V_24 -> V_163 ;
return F_237 ( & V_24 -> V_300 [ V_31 ] , V_3 , V_23 ) ;
}
struct V_30 * F_238 ( struct V_29 * V_24 , unsigned V_31 ,
struct V_30 * V_30 )
{
return F_239 ( V_24 , V_31 , V_30 , NULL , NULL ) ;
}
static void F_240 ( struct V_30 * V_3 )
{
F_241 ( L_44 , F_242 ( V_3 ) , V_169 ) ;
F_3 ( V_3 ) ;
}
struct V_30 * F_239 ( struct V_29 * V_24 ,
unsigned V_31 , struct V_30 * V_30 ,
void * V_301 ,
const struct V_302 * * V_303 )
{
char V_16 [ 64 ] ;
T_1 V_293 = F_25 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ;
struct V_30 * V_3 = NULL ;
int V_162 = - V_164 ;
bool V_304 = false ;
if ( V_31 >= V_24 -> V_35 ) {
F_17 ( V_138 L_45
L_46 , V_31 ) ;
return F_123 ( - V_227 ) ;
}
if ( V_24 -> type == V_25 )
F_108 ( V_24 , V_31 , V_16 ) ;
else
F_109 ( V_24 , V_31 , V_16 ) ;
if ( ! ( V_24 -> V_44 & V_305 ) ) {
V_162 = F_235 ( V_24 , V_293 , V_31 , 1 ) ;
if ( V_162 )
goto error;
V_304 = true ;
}
V_3 = F_224 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 ) {
V_162 = - V_11 ;
goto error;
}
V_3 -> V_293 = V_293 ;
V_3 -> V_306 = V_294 ;
V_3 -> V_307 = V_30 ;
V_3 -> V_308 = F_240 ;
F_243 ( V_3 , L_19 , V_16 ) ;
V_3 -> V_309 = V_303 ;
F_244 ( V_3 , V_301 ) ;
V_162 = F_245 ( V_3 ) ;
if ( V_162 )
goto error;
return V_3 ;
error:
F_2 ( V_3 ) ;
if ( V_304 )
F_246 ( & V_24 -> V_300 [ V_31 ] ) ;
return F_123 ( V_162 ) ;
}
void F_247 ( struct V_29 * V_24 , unsigned V_31 )
{
F_248 ( V_294 ,
F_25 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ) ;
if ( ! ( V_24 -> V_44 & V_305 ) )
F_246 ( & V_24 -> V_300 [ V_31 ] ) ;
}
struct V_29 * F_249 ( unsigned int V_310 , struct V_174 * V_163 ,
unsigned long V_44 )
{
struct V_29 * V_24 ;
unsigned int V_300 = 1 ;
int V_214 ;
if ( ! V_310 || ( V_44 & V_145 && V_310 > 1 ) )
return F_123 ( - V_227 ) ;
V_24 = F_224 ( sizeof( struct V_29 ) , V_10 ) ;
if ( ! V_24 )
return F_123 ( - V_11 ) ;
F_225 ( & V_24 -> V_176 ) ;
V_24 -> V_5 = V_311 ;
V_24 -> V_35 = V_310 ;
V_24 -> V_163 = V_163 ;
V_24 -> V_44 = V_44 ;
if ( ! ( V_44 & V_178 ) ) {
V_24 -> V_148 = F_250 ( V_310 , sizeof( * V_24 -> V_148 ) ,
V_10 ) ;
V_24 -> V_152 = F_250 ( V_310 , sizeof( * V_24 -> V_152 ) ,
V_10 ) ;
if ( ! V_24 -> V_148 || ! V_24 -> V_152 ) {
V_214 = - V_11 ;
goto V_312;
}
}
if ( ! ( V_44 & V_305 ) ) {
V_24 -> V_168 = F_250 ( V_310 , sizeof( * V_24 -> V_168 ) ,
V_10 ) ;
if ( ! V_24 -> V_168 ) {
V_214 = - V_11 ;
goto V_312;
}
V_300 = V_310 ;
}
V_24 -> V_300 = F_250 ( V_300 , sizeof( * V_24 -> V_300 ) , V_10 ) ;
if ( ! V_24 -> V_300 ) {
V_214 = - V_11 ;
goto V_312;
}
return V_24 ;
V_312:
F_3 ( V_24 -> V_168 ) ;
F_3 ( V_24 -> V_148 ) ;
F_3 ( V_24 -> V_152 ) ;
F_3 ( V_24 ) ;
return F_123 ( V_214 ) ;
}
static void F_251 ( struct V_176 * V_176 )
{
struct V_29 * V_24 = F_76 ( V_176 , struct V_29 , V_176 ) ;
int V_119 ;
struct V_149 * V_150 ;
if ( V_24 -> V_44 & V_313 ) {
for ( V_119 = 0 ; V_119 < V_24 -> V_35 ; V_119 ++ ) {
V_150 = V_24 -> V_152 [ V_119 ] ;
if ( V_150 ) {
V_24 -> V_152 [ V_119 ] = NULL ;
F_3 ( V_150 ) ;
}
if ( ! ( V_24 -> V_44 & V_314 ) )
F_247 ( V_24 , V_119 ) ;
}
F_252 ( V_24 ) ;
if ( V_24 -> V_44 & V_305 )
F_246 ( & V_24 -> V_300 [ 0 ] ) ;
}
F_3 ( V_24 -> V_300 ) ;
F_3 ( V_24 -> V_168 ) ;
F_3 ( V_24 -> V_152 ) ;
F_3 ( V_24 -> V_148 ) ;
F_3 ( V_24 ) ;
}
void F_136 ( struct V_29 * V_24 )
{
F_140 ( & V_24 -> V_176 , F_251 ) ;
}
void F_253 ( struct V_29 * V_24 ,
const struct V_315 * V_316 )
{
V_24 -> V_42 = V_316 ;
}
void F_254 ( struct V_29 * V_317 )
{
F_136 ( V_317 ) ;
}
int F_255 ( struct V_29 * V_24 )
{
int error ;
int V_119 ;
T_1 V_3 ;
struct V_30 * V_317 ;
if ( ! V_24 -> V_33 ) {
error = F_256 ( & V_3 , V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_16 ) ;
if ( ! error ) {
V_24 -> V_33 = F_257 ( V_3 ) ;
V_24 -> V_34 = F_258 ( V_3 ) ;
}
} else {
V_3 = F_25 ( V_24 -> V_33 , V_24 -> V_34 ) ;
error = F_259 ( V_3 , V_24 -> V_35 , V_24 -> V_16 ) ;
}
if ( error < 0 )
goto V_214;
if ( V_24 -> V_44 & V_305 ) {
error = F_235 ( V_24 , V_3 , 0 , V_24 -> V_35 ) ;
if ( error )
goto V_318;
}
F_29 ( & V_41 ) ;
F_9 ( & V_24 -> V_319 , & V_319 ) ;
F_30 ( & V_41 ) ;
if ( ! ( V_24 -> V_44 & V_314 ) ) {
for ( V_119 = 0 ; V_119 < V_24 -> V_35 ; V_119 ++ ) {
V_317 = F_238 ( V_24 , V_119 , NULL ) ;
if ( F_111 ( V_317 ) ) {
error = F_157 ( V_317 ) ;
goto V_320;
}
}
}
F_260 ( V_24 ) ;
V_24 -> V_44 |= V_313 ;
return 0 ;
V_320:
for ( V_119 -- ; V_119 >= 0 ; V_119 -- )
F_247 ( V_24 , V_119 ) ;
F_29 ( & V_41 ) ;
F_13 ( & V_24 -> V_319 ) ;
F_30 ( & V_41 ) ;
V_318:
F_261 ( V_3 , V_24 -> V_35 ) ;
V_214:
return error ;
}
int F_262 ( struct V_29 * V_24 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_261 ( F_25 ( V_24 -> V_33 , V_24 -> V_34 ) ,
V_24 -> V_35 ) ;
F_29 ( & V_41 ) ;
F_13 ( & V_24 -> V_319 ) ;
F_30 ( & V_41 ) ;
return 0 ;
}
T_1 F_201 ( struct V_1 * V_2 )
{
return F_25 ( V_2 -> V_24 -> V_33 , V_2 -> V_24 -> V_34 ) + V_2 -> V_31 ;
}
void F_263 ( struct V_321 * V_322 )
{
* V_322 = V_202 ;
}
void T_8 F_264 ( void )
{
T_9 * V_323 ;
F_265 () ;
V_323 = V_324 ;
while ( V_323 < V_325 ) {
(* V_323)() ;
V_323 ++ ;
}
}
static char * F_266 ( struct V_30 * V_3 , T_10 * V_326 )
{
if ( ! V_326 )
return NULL ;
if ( V_3 -> V_293 == F_25 ( V_188 , 0 ) ||
V_3 -> V_293 == F_25 ( V_188 , 2 ) )
* V_326 = 0666 ;
return NULL ;
}
static int T_8 F_267 ( void )
{
V_294 = F_268 ( V_327 , L_18 ) ;
if ( F_111 ( V_294 ) )
return F_157 ( V_294 ) ;
V_294 -> V_328 = F_266 ;
return 0 ;
}
static T_2 F_269 ( struct V_30 * V_3 ,
struct V_329 * V_330 , char * V_15 )
{
struct V_331 * V_332 [ 16 ] ;
int V_119 = 0 ;
struct V_331 * V_333 ;
T_2 V_23 = 0 ;
F_270 () ;
F_271 (c) {
if ( ! V_333 -> V_30 )
continue;
if ( ! V_333 -> V_97 )
continue;
if ( ( V_333 -> V_44 & V_334 ) == 0 )
continue;
V_332 [ V_119 ++ ] = V_333 ;
if ( V_119 >= F_272 ( V_332 ) )
break;
}
while ( V_119 -- ) {
int V_31 = V_332 [ V_119 ] -> V_31 ;
struct V_29 * V_335 = V_332 [ V_119 ] -> V_30 ( V_332 [ V_119 ] , & V_31 ) ;
if ( V_335 && ( V_332 [ V_119 ] -> V_31 > 0 || V_335 -> V_33 != V_192 ) )
V_23 += F_109 ( V_335 , V_31 , V_15 + V_23 ) ;
else
V_23 += sprintf ( V_15 + V_23 , L_20 ,
V_332 [ V_119 ] -> V_16 , V_332 [ V_119 ] -> V_31 ) ;
V_23 += sprintf ( V_15 + V_23 , L_47 , V_119 ? ' ' : '\n' ) ;
}
F_273 () ;
return V_23 ;
}
void F_274 ( void )
{
if ( V_336 )
F_275 ( & V_336 -> V_337 , NULL , L_48 ) ;
}
int T_8 F_276 ( void )
{
F_236 ( & V_338 , & V_202 ) ;
if ( F_237 ( & V_338 , F_25 ( V_188 , 0 ) , 1 ) ||
F_259 ( F_25 ( V_188 , 0 ) , 1 , L_49 ) < 0 )
F_277 ( L_50 ) ;
F_278 ( V_294 , NULL , F_25 ( V_188 , 0 ) , NULL , L_18 ) ;
F_236 ( & V_339 , & V_340 ) ;
if ( F_237 ( & V_339 , F_25 ( V_188 , 1 ) , 1 ) ||
F_259 ( F_25 ( V_188 , 1 ) , 1 , L_51 ) < 0 )
F_277 ( L_52 ) ;
V_336 = F_279 ( V_294 , NULL ,
F_25 ( V_188 , 1 ) , NULL ,
V_341 , L_53 ) ;
if ( F_111 ( V_336 ) )
V_336 = NULL ;
#ifdef F_153
F_280 ( & V_340 ) ;
#endif
return 0 ;
}
