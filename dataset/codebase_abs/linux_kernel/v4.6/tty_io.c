static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
F_3 ( V_2 -> V_3 ) ;
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_5 = 0xDEADDEAD ;
F_4 ( V_2 ) ;
}
static inline struct V_1 * F_5 ( struct V_6 * V_6 )
{
return ( (struct V_7 * ) V_6 -> V_8 ) -> V_2 ;
}
int F_6 ( struct V_6 * V_6 )
{
struct V_7 * V_9 ;
V_9 = F_7 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_6 -> V_8 = V_9 ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 , struct V_6 * V_6 )
{
struct V_7 * V_9 = V_6 -> V_8 ;
V_9 -> V_2 = V_2 ;
V_9 -> V_6 = V_6 ;
F_9 ( & V_2 -> V_12 ) ;
F_10 ( & V_9 -> V_13 , & V_2 -> V_14 ) ;
F_11 ( & V_2 -> V_12 ) ;
}
void F_12 ( struct V_6 * V_6 )
{
struct V_7 * V_9 = V_6 -> V_8 ;
V_6 -> V_8 = NULL ;
F_4 ( V_9 ) ;
}
static void F_13 ( struct V_6 * V_6 )
{
struct V_7 * V_9 = V_6 -> V_8 ;
struct V_1 * V_2 = V_9 -> V_2 ;
F_9 ( & V_2 -> V_12 ) ;
F_14 ( & V_9 -> V_13 ) ;
F_11 ( & V_2 -> V_12 ) ;
F_12 ( V_6 ) ;
}
const char * F_15 ( const struct V_1 * V_2 )
{
if ( ! V_2 )
return L_1 ;
return V_2 -> V_15 ;
}
const char * F_16 ( const struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_16 )
return L_2 ;
return V_2 -> V_16 -> V_15 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_17 * V_17 ,
const char * V_18 )
{
#ifdef F_18
if ( ! V_2 ) {
F_19 ( L_3 ,
F_20 ( V_17 ) , F_21 ( V_17 ) , V_18 ) ;
return 1 ;
}
if ( V_2 -> V_5 != V_19 ) {
F_19 ( L_4 ,
F_20 ( V_17 ) , F_21 ( V_17 ) , V_18 ) ;
return 1 ;
}
#endif
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , const char * V_18 )
{
#ifdef F_23
struct V_20 * V_21 ;
int V_22 = 0 ;
F_9 ( & V_2 -> V_12 ) ;
F_24 (p, &tty->tty_files) {
V_22 ++ ;
}
F_11 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_25 &&
V_2 -> V_26 && V_2 -> V_26 -> V_22 )
V_22 ++ ;
if ( V_2 -> V_22 != V_22 ) {
F_25 ( V_2 , L_5 ,
V_18 , V_2 -> V_22 , V_22 ) ;
return V_22 ;
}
#endif
return 0 ;
}
static struct V_27 * F_26 ( T_1 V_28 , int * V_29 )
{
struct V_27 * V_21 ;
F_27 (p, &tty_drivers, tty_drivers) {
T_1 V_30 = F_28 ( V_21 -> V_31 , V_21 -> V_32 ) ;
if ( V_28 < V_30 || V_28 >= V_30 + V_21 -> V_33 )
continue;
* V_29 = V_28 - V_30 ;
return F_29 ( V_21 ) ;
}
return NULL ;
}
struct V_27 * F_30 ( char * V_15 , int * line )
{
struct V_27 * V_21 , * V_34 = NULL ;
int V_35 = 0 ;
int V_36 ;
char * V_37 , * V_38 ;
for ( V_37 = V_15 ; * V_37 ; V_37 ++ )
if ( ( * V_37 >= '0' && * V_37 <= '9' ) || * V_37 == ',' )
break;
if ( ! * V_37 )
return NULL ;
V_36 = V_37 - V_15 ;
V_35 = F_31 ( V_37 , & V_37 , 10 ) ;
F_32 ( & V_39 ) ;
F_27 (p, &tty_drivers, tty_drivers) {
if ( strncmp ( V_15 , V_21 -> V_15 , V_36 ) != 0 )
continue;
V_38 = V_37 ;
if ( * V_38 == ',' )
V_38 ++ ;
if ( * V_38 == '\0' )
V_38 = NULL ;
if ( V_35 >= 0 && V_35 < V_21 -> V_33 && V_21 -> V_40 &&
V_21 -> V_40 -> V_41 && ! V_21 -> V_40 -> V_41 ( V_21 , V_35 , V_38 ) ) {
V_34 = F_29 ( V_21 ) ;
* line = V_35 ;
break;
}
}
F_33 ( & V_39 ) ;
return V_34 ;
}
static int F_34 ( int V_42 )
{
return ( F_35 ( & V_43 -> V_44 , V_42 ) ||
V_43 -> V_45 -> V_46 [ V_42 - 1 ] . V_47 . V_48 == V_49 ) ;
}
int F_36 ( struct V_1 * V_2 , int V_42 )
{
unsigned long V_50 ;
struct V_51 * V_52 , * V_53 ;
int V_54 = 0 ;
if ( V_43 -> signal -> V_2 != V_2 )
return 0 ;
F_37 () ;
V_52 = F_38 ( V_43 ) ;
F_39 ( & V_2 -> V_55 , V_50 ) ;
V_53 = V_2 -> V_52 ;
F_40 ( & V_2 -> V_55 , V_50 ) ;
if ( V_53 && V_52 != V_2 -> V_52 ) {
if ( F_34 ( V_42 ) ) {
if ( V_42 == V_56 )
V_54 = - V_57 ;
} else if ( F_41 () )
V_54 = - V_57 ;
else {
F_42 ( V_52 , V_42 , 1 ) ;
F_43 ( V_58 ) ;
V_54 = - V_59 ;
}
}
F_44 () ;
if ( ! V_53 )
F_25 ( V_2 , L_6 , V_42 ) ;
return V_54 ;
}
int F_45 ( struct V_1 * V_2 )
{
return F_36 ( V_2 , V_60 ) ;
}
static T_2 F_46 ( struct V_6 * V_6 , char T_3 * V_61 ,
T_4 V_22 , T_5 * V_62 )
{
return 0 ;
}
static T_2 F_47 ( struct V_6 * V_6 , const char T_3 * V_61 ,
T_4 V_22 , T_5 * V_62 )
{
return - V_57 ;
}
static unsigned int F_48 ( struct V_6 * V_63 , T_6 * V_64 )
{
return V_65 | V_66 | V_67 | V_68 | V_69 | V_70 ;
}
static long F_49 ( struct V_6 * V_6 , unsigned int V_71 ,
unsigned long V_72 )
{
return V_71 == V_73 ? - V_74 : - V_57 ;
}
static long F_50 ( struct V_6 * V_6 ,
unsigned int V_71 , unsigned long V_72 )
{
return V_71 == V_73 ? - V_74 : - V_57 ;
}
static int F_51 ( int V_75 , struct V_6 * V_6 , int V_76 )
{
return - V_74 ;
}
void F_52 ( struct V_77 * V_21 )
{
unsigned long V_50 ;
struct V_1 * V_2 ;
F_39 ( & V_21 -> V_45 -> V_78 , V_50 ) ;
V_2 = V_21 -> signal -> V_2 ;
V_21 -> signal -> V_2 = NULL ;
F_40 ( & V_21 -> V_45 -> V_78 , V_50 ) ;
F_53 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
F_39 ( & V_2 -> V_55 , V_50 ) ;
F_55 ( V_2 -> V_79 ) ;
F_55 ( V_2 -> V_52 ) ;
V_2 -> V_52 = F_56 ( F_38 ( V_43 ) ) ;
F_40 ( & V_2 -> V_55 , V_50 ) ;
V_2 -> V_79 = F_56 ( F_57 ( V_43 ) ) ;
if ( V_43 -> signal -> V_2 ) {
F_58 ( V_2 , L_7 ,
V_43 -> signal -> V_2 -> V_15 ) ;
F_53 ( V_43 -> signal -> V_2 ) ;
}
F_55 ( V_43 -> signal -> V_80 ) ;
V_43 -> signal -> V_2 = F_59 ( V_2 ) ;
V_43 -> signal -> V_80 = NULL ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_61 ( & V_43 -> V_45 -> V_78 ) ;
F_54 ( V_2 ) ;
F_62 ( & V_43 -> V_45 -> V_78 ) ;
}
struct V_1 * F_63 ( void )
{
struct V_1 * V_2 ;
unsigned long V_50 ;
F_39 ( & V_43 -> V_45 -> V_78 , V_50 ) ;
V_2 = F_59 ( V_43 -> signal -> V_2 ) ;
F_40 ( & V_43 -> V_45 -> V_78 , V_50 ) ;
return V_2 ;
}
static void F_64 ( struct V_51 * V_79 )
{
struct V_77 * V_21 ;
F_65 (session, PIDTYPE_SID, p) {
F_52 ( V_21 ) ;
} F_66 ( V_79 , V_81 , V_21 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
struct V_82 * V_83 ;
if ( F_68 ( V_84 , & V_2 -> V_50 ) ) {
V_83 = F_69 ( V_2 ) ;
if ( V_83 ) {
if ( V_83 -> V_40 -> V_85 )
V_83 -> V_40 -> V_85 ( V_2 ) ;
F_70 ( V_83 ) ;
}
}
F_71 ( & V_2 -> V_86 , V_66 ) ;
}
static int F_72 ( struct V_1 * V_2 , int V_87 )
{
struct V_77 * V_21 ;
int V_88 = 0 ;
struct V_51 * V_53 = NULL ;
F_73 ( & V_89 ) ;
if ( V_2 -> V_79 ) {
F_65 (tty->session, PIDTYPE_SID, p) {
F_61 ( & V_21 -> V_45 -> V_78 ) ;
if ( V_21 -> signal -> V_2 == V_2 ) {
V_21 -> signal -> V_2 = NULL ;
V_88 ++ ;
}
if ( ! V_21 -> signal -> V_90 ) {
F_62 ( & V_21 -> V_45 -> V_78 ) ;
continue;
}
F_74 ( V_91 , V_92 , V_21 ) ;
F_74 ( V_93 , V_92 , V_21 ) ;
F_55 ( V_21 -> signal -> V_80 ) ;
F_9 ( & V_2 -> V_55 ) ;
V_53 = F_56 ( V_2 -> V_52 ) ;
if ( V_2 -> V_52 )
V_21 -> signal -> V_80 = F_56 ( V_2 -> V_52 ) ;
F_11 ( & V_2 -> V_55 ) ;
F_62 ( & V_21 -> V_45 -> V_78 ) ;
} F_66 ( V_2 -> V_79 , V_81 , V_21 ) ;
}
F_75 ( & V_89 ) ;
if ( V_53 ) {
if ( V_87 )
F_42 ( V_53 , V_91 , V_87 ) ;
F_55 ( V_53 ) ;
}
return V_88 ;
}
static void F_76 ( struct V_1 * V_2 , int V_87 )
{
struct V_6 * V_94 = NULL ;
struct V_6 * V_63 , * V_95 = NULL ;
struct V_7 * V_9 ;
int V_96 = 0 , V_97 ;
int V_88 ;
if ( ! V_2 )
return;
F_9 ( & V_98 ) ;
if ( V_99 && F_5 ( V_99 ) == V_2 ) {
V_95 = V_99 ;
V_99 = NULL ;
}
F_11 ( & V_98 ) ;
F_77 ( V_2 ) ;
if ( F_68 ( V_100 , & V_2 -> V_50 ) ) {
F_78 ( V_2 ) ;
return;
}
F_22 ( V_2 , L_8 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_27 (priv, &tty->tty_files, list) {
V_63 = V_9 -> V_6 ;
if ( V_63 -> V_101 -> V_102 == V_103 )
V_94 = V_63 ;
if ( V_63 -> V_101 -> V_102 != V_104 )
continue;
V_96 ++ ;
F_79 ( - 1 , V_63 , 0 ) ;
V_63 -> V_101 = & V_105 ;
}
F_11 ( & V_2 -> V_12 ) ;
V_88 = F_72 ( V_2 , V_87 ) ;
while ( V_88 -- )
F_53 ( V_2 ) ;
F_80 ( V_2 , V_94 != NULL ) ;
F_61 ( & V_2 -> V_55 ) ;
F_81 ( V_106 , & V_2 -> V_50 ) ;
F_81 ( V_84 , & V_2 -> V_50 ) ;
F_55 ( V_2 -> V_79 ) ;
F_55 ( V_2 -> V_52 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_52 = NULL ;
V_2 -> V_107 = 0 ;
F_62 ( & V_2 -> V_55 ) ;
if ( V_94 ) {
if ( V_2 -> V_40 -> V_108 )
for ( V_97 = 0 ; V_97 < V_96 ; V_97 ++ )
V_2 -> V_40 -> V_108 ( V_2 , V_94 ) ;
} else if ( V_2 -> V_40 -> V_109 )
V_2 -> V_40 -> V_109 ( V_2 ) ;
F_82 ( V_100 , & V_2 -> V_50 ) ;
F_78 ( V_2 ) ;
if ( V_95 )
F_83 ( V_95 ) ;
}
static void F_84 ( struct V_110 * V_111 )
{
struct V_1 * V_2 =
F_85 ( V_111 , struct V_1 , V_112 ) ;
F_76 ( V_2 , 0 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
F_87 ( V_2 , L_9 ) ;
F_88 ( & V_2 -> V_112 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
F_87 ( V_2 , L_10 ) ;
F_76 ( V_2 , 0 ) ;
}
void F_90 ( void )
{
struct V_1 * V_2 ;
V_2 = F_63 () ;
if ( V_2 ) {
F_89 ( V_2 ) ;
F_53 ( V_2 ) ;
}
}
static void F_91 ( struct V_1 * V_2 )
{
F_87 ( V_2 , L_11 ) ;
F_76 ( V_2 , 1 ) ;
}
int F_92 ( struct V_6 * V_63 )
{
return ( V_63 -> V_101 == & V_105 ) ;
}
void F_93 ( int V_113 )
{
struct V_1 * V_2 ;
if ( ! V_43 -> signal -> V_90 )
return;
V_2 = F_63 () ;
if ( V_2 ) {
if ( V_113 && V_2 -> V_16 -> type != V_23 ) {
F_91 ( V_2 ) ;
} else {
struct V_51 * V_53 = F_94 ( V_2 ) ;
if ( V_53 ) {
F_42 ( V_53 , V_91 , V_113 ) ;
if ( ! V_113 )
F_42 ( V_53 , V_93 , V_113 ) ;
F_55 ( V_53 ) ;
}
}
F_53 ( V_2 ) ;
} else if ( V_113 ) {
struct V_51 * V_114 ;
F_61 ( & V_43 -> V_45 -> V_78 ) ;
V_114 = V_43 -> signal -> V_80 ;
V_43 -> signal -> V_80 = NULL ;
F_62 ( & V_43 -> V_45 -> V_78 ) ;
if ( V_114 ) {
F_42 ( V_114 , V_91 , V_113 ) ;
F_42 ( V_114 , V_93 , V_113 ) ;
F_55 ( V_114 ) ;
}
return;
}
F_61 ( & V_43 -> V_45 -> V_78 ) ;
F_55 ( V_43 -> signal -> V_80 ) ;
V_43 -> signal -> V_80 = NULL ;
V_2 = F_59 ( V_43 -> signal -> V_2 ) ;
if ( V_2 ) {
unsigned long V_50 ;
F_39 ( & V_2 -> V_55 , V_50 ) ;
F_55 ( V_2 -> V_79 ) ;
F_55 ( V_2 -> V_52 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_52 = NULL ;
F_40 ( & V_2 -> V_55 , V_50 ) ;
F_53 ( V_2 ) ;
} else
F_87 ( V_2 , L_12 ) ;
F_62 ( & V_43 -> V_45 -> V_78 ) ;
F_73 ( & V_89 ) ;
F_64 ( F_57 ( V_43 ) ) ;
F_75 ( & V_89 ) ;
}
void F_95 ( void )
{
struct V_77 * V_115 = V_43 ;
F_93 ( 0 ) ;
F_52 ( V_115 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
if ( V_2 -> V_116 )
return;
V_2 -> V_116 = 1 ;
if ( V_2 -> V_40 -> V_117 )
V_2 -> V_40 -> V_117 ( V_2 ) ;
}
void F_97 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
F_39 ( & V_2 -> V_118 , V_50 ) ;
F_96 ( V_2 ) ;
F_40 ( & V_2 -> V_118 , V_50 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_116 || V_2 -> V_119 )
return;
V_2 -> V_116 = 0 ;
if ( V_2 -> V_40 -> V_120 )
V_2 -> V_40 -> V_120 ( V_2 ) ;
F_67 ( V_2 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
F_39 ( & V_2 -> V_118 , V_50 ) ;
F_98 ( V_2 ) ;
F_40 ( & V_2 -> V_118 , V_50 ) ;
}
static void F_100 ( struct V_121 * time )
{
unsigned long V_122 = F_101 () ;
if ( ( V_122 ^ time -> V_123 ) & ~ 7 )
time -> V_123 = V_122 ;
}
static T_2 F_102 ( struct V_6 * V_6 , char T_3 * V_61 , T_4 V_22 ,
T_5 * V_62 )
{
int V_124 ;
struct V_17 * V_17 = F_103 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_82 * V_83 ;
if ( F_17 ( V_2 , V_17 , L_13 ) )
return - V_57 ;
if ( ! V_2 || ( F_68 ( V_125 , & V_2 -> V_50 ) ) )
return - V_57 ;
V_83 = F_104 ( V_2 ) ;
if ( ! V_83 )
return F_46 ( V_6 , V_61 , V_22 , V_62 ) ;
if ( V_83 -> V_40 -> V_126 )
V_124 = V_83 -> V_40 -> V_126 ( V_2 , V_6 , V_61 , V_22 ) ;
else
V_124 = - V_57 ;
F_70 ( V_83 ) ;
if ( V_124 > 0 )
F_100 ( & V_17 -> V_127 ) ;
return V_124 ;
}
static void F_105 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_128 ) ;
F_71 ( & V_2 -> V_86 , V_66 ) ;
}
static int F_106 ( struct V_1 * V_2 , int V_129 )
{
if ( ! F_107 ( & V_2 -> V_128 ) ) {
if ( V_129 )
return - V_130 ;
if ( F_108 ( & V_2 -> V_128 ) )
return - V_59 ;
}
return 0 ;
}
static inline T_2 F_109 (
T_2 (* V_102)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_61 ,
T_4 V_22 )
{
T_2 V_54 , V_131 = 0 ;
unsigned int V_132 ;
V_54 = F_106 ( V_2 , V_6 -> V_133 & V_134 ) ;
if ( V_54 < 0 )
return V_54 ;
V_132 = 2048 ;
if ( F_68 ( V_135 , & V_2 -> V_50 ) )
V_132 = 65536 ;
if ( V_22 < V_132 )
V_132 = V_22 ;
if ( V_2 -> V_136 < V_132 ) {
unsigned char * V_137 ;
if ( V_132 < 1024 )
V_132 = 1024 ;
V_137 = F_7 ( V_132 , V_10 ) ;
if ( ! V_137 ) {
V_54 = - V_11 ;
goto V_138;
}
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_136 = V_132 ;
V_2 -> V_4 = V_137 ;
}
for (; ; ) {
T_4 V_139 = V_22 ;
if ( V_139 > V_132 )
V_139 = V_132 ;
V_54 = - V_140 ;
if ( F_110 ( V_2 -> V_4 , V_61 , V_139 ) )
break;
V_54 = V_102 ( V_2 , V_6 , V_2 -> V_4 , V_139 ) ;
if ( V_54 <= 0 )
break;
V_131 += V_54 ;
V_61 += V_54 ;
V_22 -= V_54 ;
if ( ! V_22 )
break;
V_54 = - V_59 ;
if ( F_111 ( V_43 ) )
break;
F_112 () ;
}
if ( V_131 ) {
F_100 ( & F_103 ( V_6 ) -> V_141 ) ;
V_54 = V_131 ;
}
V_138:
F_105 ( V_2 ) ;
return V_54 ;
}
void F_113 ( struct V_1 * V_2 , char * V_142 )
{
if ( V_2 ) {
F_32 ( & V_2 -> V_128 ) ;
F_77 ( V_2 ) ;
if ( V_2 -> V_40 -> V_102 && V_2 -> V_22 > 0 )
V_2 -> V_40 -> V_102 ( V_2 , V_142 , strlen ( V_142 ) ) ;
F_78 ( V_2 ) ;
F_105 ( V_2 ) ;
}
return;
}
static T_2 V_104 ( struct V_6 * V_6 , const char T_3 * V_61 ,
T_4 V_22 , T_5 * V_62 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_82 * V_83 ;
T_2 V_54 ;
if ( F_17 ( V_2 , F_103 ( V_6 ) , L_14 ) )
return - V_57 ;
if ( ! V_2 || ! V_2 -> V_40 -> V_102 ||
( F_68 ( V_125 , & V_2 -> V_50 ) ) )
return - V_57 ;
if ( V_2 -> V_40 -> V_143 == NULL )
F_114 ( V_2 , L_15 ) ;
V_83 = F_104 ( V_2 ) ;
if ( ! V_83 )
return F_47 ( V_6 , V_61 , V_22 , V_62 ) ;
if ( ! V_83 -> V_40 -> V_102 )
V_54 = - V_57 ;
else
V_54 = F_109 ( V_83 -> V_40 -> V_102 , V_2 , V_6 , V_61 , V_22 ) ;
F_70 ( V_83 ) ;
return V_54 ;
}
T_2 V_103 ( struct V_6 * V_6 , const char T_3 * V_61 ,
T_4 V_22 , T_5 * V_62 )
{
struct V_6 * V_21 = NULL ;
F_9 ( & V_98 ) ;
if ( V_99 )
V_21 = F_115 ( V_99 ) ;
F_11 ( & V_98 ) ;
if ( V_21 ) {
T_2 V_34 ;
V_34 = F_116 ( V_21 , V_61 , V_22 , & V_21 -> V_144 ) ;
F_83 ( V_21 ) ;
return V_34 ;
}
return V_104 ( V_6 , V_61 , V_22 , V_62 ) ;
}
int F_117 ( struct V_1 * V_2 , char V_145 )
{
int V_146 = V_2 -> V_116 ;
if ( V_2 -> V_40 -> V_147 ) {
F_118 ( & V_2 -> V_148 ) ;
V_2 -> V_40 -> V_147 ( V_2 , V_145 ) ;
F_119 ( & V_2 -> V_148 ) ;
return 0 ;
}
if ( F_106 ( V_2 , 0 ) < 0 )
return - V_59 ;
F_118 ( & V_2 -> V_148 ) ;
if ( V_146 )
F_99 ( V_2 ) ;
V_2 -> V_40 -> V_102 ( V_2 , & V_145 , 1 ) ;
if ( V_146 )
F_97 ( V_2 ) ;
F_119 ( & V_2 -> V_148 ) ;
F_105 ( V_2 ) ;
return 0 ;
}
static void F_120 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
int V_124 = V_29 + V_16 -> V_149 ;
sprintf ( V_21 , L_16 ,
V_16 -> V_24 == V_25 ? L_17 : V_16 -> V_15 ,
V_150 [ V_124 >> 4 & 0xf ] , V_124 & 0xf ) ;
}
static T_2 F_121 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
if ( V_16 -> V_50 & V_151 )
return sprintf ( V_21 , L_18 , V_16 -> V_15 ) ;
else
return sprintf ( V_21 , L_19 , V_16 -> V_15 ,
V_29 + V_16 -> V_149 ) ;
}
static struct V_1 * F_122 ( struct V_27 * V_16 ,
struct V_6 * V_6 , int V_152 )
{
struct V_1 * V_2 ;
if ( V_16 -> V_40 -> V_153 )
V_2 = V_16 -> V_40 -> V_153 ( V_16 , V_6 , V_152 ) ;
else
V_2 = V_16 -> V_154 [ V_152 ] ;
if ( ! F_123 ( V_2 ) )
F_59 ( V_2 ) ;
return V_2 ;
}
void F_124 ( struct V_1 * V_2 )
{
struct V_155 * V_156 ;
int V_152 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_50 & V_157 )
V_2 -> V_158 = V_2 -> V_16 -> V_159 ;
else {
V_156 = V_2 -> V_16 -> V_158 [ V_152 ] ;
if ( V_156 != NULL ) {
V_2 -> V_158 = * V_156 ;
V_2 -> V_158 . V_160 = V_2 -> V_16 -> V_159 . V_160 ;
} else
V_2 -> V_158 = V_2 -> V_16 -> V_159 ;
}
V_2 -> V_158 . V_161 = F_125 ( & V_2 -> V_158 ) ;
V_2 -> V_158 . V_162 = F_126 ( & V_2 -> V_158 ) ;
}
int F_127 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
F_124 ( V_2 ) ;
F_29 ( V_16 ) ;
V_2 -> V_22 ++ ;
V_16 -> V_154 [ V_2 -> V_29 ] = V_2 ;
return 0 ;
}
static int F_128 ( struct V_27 * V_16 ,
struct V_1 * V_2 )
{
return V_16 -> V_40 -> V_163 ? V_16 -> V_40 -> V_163 ( V_16 , V_2 ) :
F_127 ( V_16 , V_2 ) ;
}
static void F_129 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
if ( V_16 -> V_40 -> remove )
V_16 -> V_40 -> remove ( V_16 , V_2 ) ;
else
V_16 -> V_154 [ V_2 -> V_29 ] = NULL ;
}
static int F_130 ( struct V_1 * V_2 )
{
struct V_27 * V_16 = V_2 -> V_16 ;
if ( V_16 -> type == V_23 &&
V_16 -> V_24 == V_164 )
return - V_57 ;
if ( ! V_2 -> V_22 )
return - V_130 ;
if ( F_68 ( V_165 , & V_2 -> V_50 ) && ! F_131 ( V_166 ) )
return - V_167 ;
V_2 -> V_22 ++ ;
if ( ! V_2 -> V_168 )
return F_132 ( V_2 , V_2 -> V_158 . V_160 ) ;
return 0 ;
}
struct V_1 * F_133 ( struct V_27 * V_16 , int V_152 )
{
struct V_1 * V_2 ;
int V_169 ;
if ( ! F_134 ( V_16 -> V_170 ) )
return F_135 ( - V_171 ) ;
V_2 = F_136 ( V_16 , V_152 ) ;
if ( ! V_2 ) {
V_169 = - V_11 ;
goto V_172;
}
F_77 ( V_2 ) ;
V_169 = F_128 ( V_16 , V_2 ) ;
if ( V_169 < 0 )
goto V_173;
if ( ! V_2 -> V_174 )
V_2 -> V_174 = V_16 -> V_175 [ V_152 ] ;
F_137 ( ! V_2 -> V_174 ,
L_20 ,
V_176 , V_2 -> V_16 -> V_15 ) ;
V_2 -> V_174 -> V_177 = V_2 ;
V_169 = F_138 ( V_2 , V_2 -> V_26 ) ;
if ( V_169 )
goto V_178;
return V_2 ;
V_173:
F_78 ( V_2 ) ;
F_1 ( V_2 ) ;
V_172:
F_139 ( V_16 -> V_170 ) ;
return F_135 ( V_169 ) ;
V_178:
F_78 ( V_2 ) ;
F_140 ( V_2 , L_21 ,
V_169 , V_152 ) ;
F_141 ( V_2 , V_152 ) ;
return F_135 ( V_169 ) ;
}
static void F_142 ( struct V_1 * V_2 )
{
struct V_155 * V_156 ;
int V_152 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_50 & V_157 )
return;
V_156 = V_2 -> V_16 -> V_158 [ V_152 ] ;
if ( V_156 == NULL ) {
V_156 = F_7 ( sizeof( struct V_155 ) , V_10 ) ;
if ( V_156 == NULL )
return;
V_2 -> V_16 -> V_158 [ V_152 ] = V_156 ;
}
* V_156 = V_2 -> V_158 ;
}
static void F_143 ( struct V_1 * V_2 )
{
F_144 ( & V_2 -> V_179 ) ;
F_144 ( & V_2 -> V_112 ) ;
if ( V_2 -> V_26 ) {
F_144 ( & V_2 -> V_26 -> V_179 ) ;
F_144 ( & V_2 -> V_26 -> V_112 ) ;
}
}
static void F_145 ( struct V_110 * V_111 )
{
struct V_1 * V_2 =
F_85 ( V_111 , struct V_1 , V_112 ) ;
struct V_27 * V_16 = V_2 -> V_16 ;
struct V_180 * V_170 = V_16 -> V_170 ;
if ( V_2 -> V_40 -> V_181 )
V_2 -> V_40 -> V_181 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_146 ( V_16 ) ;
F_139 ( V_170 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_147 ( & V_2 -> V_14 ) ;
F_11 ( & V_2 -> V_12 ) ;
F_55 ( V_2 -> V_52 ) ;
F_55 ( V_2 -> V_79 ) ;
F_1 ( V_2 ) ;
}
static void F_148 ( struct V_182 * V_182 )
{
struct V_1 * V_2 = F_85 ( V_182 , struct V_1 , V_182 ) ;
F_149 ( & V_2 -> V_112 , F_145 ) ;
F_88 ( & V_2 -> V_112 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( V_2 )
F_150 ( & V_2 -> V_182 , F_148 ) ;
}
static void F_141 ( struct V_1 * V_2 , int V_152 )
{
F_151 ( V_2 -> V_29 != V_152 ) ;
F_151 ( ! F_152 ( & V_39 ) ) ;
if ( V_2 -> V_40 -> V_183 )
V_2 -> V_40 -> V_183 ( V_2 ) ;
F_142 ( V_2 ) ;
F_129 ( V_2 -> V_16 , V_2 ) ;
V_2 -> V_174 -> V_177 = NULL ;
if ( V_2 -> V_26 )
V_2 -> V_26 -> V_174 -> V_177 = NULL ;
F_153 ( V_2 -> V_174 ) ;
F_53 ( V_2 -> V_26 ) ;
F_53 ( V_2 ) ;
}
static int F_154 ( struct V_1 * V_2 , int V_152 )
{
#ifdef F_18
if ( V_152 < 0 || V_152 >= V_2 -> V_16 -> V_33 ) {
F_58 ( V_2 , L_22 , V_152 ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_50 & V_184 )
return 0 ;
if ( V_2 != V_2 -> V_16 -> V_154 [ V_152 ] ) {
F_58 ( V_2 , L_23 ,
V_152 , V_2 -> V_16 -> V_154 [ V_152 ] ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_185 ) {
struct V_1 * V_186 = V_2 -> V_26 ;
if ( V_186 != V_2 -> V_16 -> V_185 -> V_154 [ V_152 ] ) {
F_58 ( V_2 , L_24 ,
V_152 , V_2 -> V_16 -> V_185 -> V_154 [ V_152 ] ) ;
return - 1 ;
}
if ( V_186 -> V_26 != V_2 ) {
F_58 ( V_2 , L_25 , V_186 -> V_26 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_155 ( struct V_17 * V_17 , struct V_6 * V_63 )
{
struct V_1 * V_2 = F_5 ( V_63 ) ;
struct V_1 * V_186 = NULL ;
int V_187 , V_188 ;
int V_152 ;
long V_189 = 0 ;
int V_190 = 1 ;
if ( F_17 ( V_2 , V_17 , V_176 ) )
return 0 ;
F_77 ( V_2 ) ;
F_22 ( V_2 , V_176 ) ;
F_79 ( - 1 , V_63 , 0 ) ;
V_152 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_164 )
V_186 = V_2 -> V_26 ;
if ( F_154 ( V_2 , V_152 ) ) {
F_78 ( V_2 ) ;
return 0 ;
}
F_87 ( V_2 , L_26 , V_2 -> V_22 ) ;
if ( V_2 -> V_40 -> V_108 )
V_2 -> V_40 -> V_108 ( V_2 , V_63 ) ;
F_156 ( V_186 ) ;
while ( 1 ) {
V_187 = 0 ;
if ( V_2 -> V_22 <= 1 ) {
if ( F_157 ( & V_2 -> V_191 ) ) {
F_158 ( & V_2 -> V_191 , V_65 ) ;
V_187 ++ ;
}
if ( F_157 ( & V_2 -> V_86 ) ) {
F_158 ( & V_2 -> V_86 , V_66 ) ;
V_187 ++ ;
}
}
if ( V_186 && V_186 -> V_22 <= 1 ) {
if ( F_157 ( & V_186 -> V_191 ) ) {
F_158 ( & V_186 -> V_191 , V_65 ) ;
V_187 ++ ;
}
if ( F_157 ( & V_186 -> V_86 ) ) {
F_158 ( & V_186 -> V_86 , V_66 ) ;
V_187 ++ ;
}
}
if ( ! V_187 )
break;
if ( V_190 ) {
V_190 = 0 ;
F_25 ( V_2 , L_27 ) ;
}
F_159 ( V_189 ) ;
if ( V_189 < 120 * V_192 )
V_189 = 2 * V_189 + 1 ;
else
V_189 = V_193 ;
}
if ( V_186 ) {
if ( -- V_186 -> V_22 < 0 ) {
F_25 ( V_2 , L_28 , V_186 -> V_22 ) ;
V_186 -> V_22 = 0 ;
}
}
if ( -- V_2 -> V_22 < 0 ) {
F_25 ( V_2 , L_29 , V_2 -> V_22 ) ;
V_2 -> V_22 = 0 ;
}
F_13 ( V_63 ) ;
if ( ! V_2 -> V_22 ) {
F_73 ( & V_89 ) ;
F_64 ( V_2 -> V_79 ) ;
if ( V_186 )
F_64 ( V_186 -> V_79 ) ;
F_75 ( & V_89 ) ;
}
V_188 = ! V_2 -> V_22 && ! ( V_186 && V_186 -> V_22 ) ;
F_160 ( V_186 ) ;
F_78 ( V_2 ) ;
if ( ! V_188 )
return 0 ;
F_87 ( V_2 , L_30 ) ;
F_161 ( V_2 ) ;
F_143 ( V_2 ) ;
F_87 ( V_2 , L_31 ) ;
F_32 ( & V_39 ) ;
F_141 ( V_2 , V_152 ) ;
F_33 ( & V_39 ) ;
return 0 ;
}
static struct V_1 * F_162 ( T_1 V_28 , struct V_6 * V_63 )
{
struct V_1 * V_2 ;
int V_169 ;
if ( V_28 != F_28 ( V_194 , 0 ) )
return NULL ;
V_2 = F_63 () ;
if ( ! V_2 )
return F_135 ( - V_195 ) ;
V_63 -> V_133 |= V_196 ;
F_77 ( V_2 ) ;
F_53 ( V_2 ) ;
V_169 = F_130 ( V_2 ) ;
if ( V_169 < 0 ) {
F_78 ( V_2 ) ;
V_2 = F_135 ( V_169 ) ;
}
return V_2 ;
}
static struct V_27 * F_163 ( T_1 V_28 , struct V_6 * V_63 ,
int * V_29 )
{
struct V_27 * V_16 ;
switch ( V_28 ) {
#ifdef F_164
case F_28 ( V_197 , 0 ) : {
extern struct V_27 * V_198 ;
V_16 = F_29 ( V_198 ) ;
* V_29 = V_199 ;
break;
}
#endif
case F_28 ( V_194 , 1 ) : {
struct V_27 * V_198 = F_165 ( V_29 ) ;
if ( V_198 ) {
V_16 = F_29 ( V_198 ) ;
if ( V_16 ) {
V_63 -> V_133 |= V_196 ;
break;
}
}
return F_135 ( - V_171 ) ;
}
default:
V_16 = F_26 ( V_28 , V_29 ) ;
if ( ! V_16 )
return F_135 ( - V_171 ) ;
break;
}
return V_16 ;
}
static struct V_1 * F_166 ( T_1 V_28 , struct V_17 * V_17 ,
struct V_6 * V_63 )
{
struct V_1 * V_2 ;
struct V_27 * V_16 = NULL ;
int V_29 = - 1 ;
int V_169 ;
F_32 ( & V_39 ) ;
V_16 = F_163 ( V_28 , V_63 , & V_29 ) ;
if ( F_123 ( V_16 ) ) {
F_33 ( & V_39 ) ;
return F_167 ( V_16 ) ;
}
V_2 = F_122 ( V_16 , V_63 , V_29 ) ;
if ( F_123 ( V_2 ) ) {
F_33 ( & V_39 ) ;
goto V_138;
}
if ( V_2 ) {
F_33 ( & V_39 ) ;
V_169 = F_168 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( V_169 ) {
if ( V_169 == - V_200 )
V_169 = - V_59 ;
V_2 = F_135 ( V_169 ) ;
goto V_138;
}
V_169 = F_130 ( V_2 ) ;
if ( V_169 < 0 ) {
F_78 ( V_2 ) ;
V_2 = F_135 ( V_169 ) ;
}
} else {
V_2 = F_133 ( V_16 , V_29 ) ;
F_33 ( & V_39 ) ;
}
V_138:
F_146 ( V_16 ) ;
return V_2 ;
}
static int F_169 ( struct V_17 * V_17 , struct V_6 * V_63 )
{
struct V_1 * V_2 ;
int V_201 , V_169 ;
T_1 V_28 = V_17 -> V_202 ;
unsigned V_203 = V_63 -> V_133 ;
F_170 ( V_17 , V_63 ) ;
V_204:
V_169 = F_6 ( V_63 ) ;
if ( V_169 )
return - V_11 ;
V_2 = F_162 ( V_28 , V_63 ) ;
if ( ! V_2 )
V_2 = F_166 ( V_28 , V_17 , V_63 ) ;
if ( F_123 ( V_2 ) ) {
F_12 ( V_63 ) ;
V_169 = F_171 ( V_2 ) ;
if ( V_169 != - V_130 || F_111 ( V_43 ) )
return V_169 ;
F_172 () ;
goto V_204;
}
F_8 ( V_2 , V_63 ) ;
F_22 ( V_2 , V_176 ) ;
F_87 ( V_2 , L_32 , V_2 -> V_22 ) ;
if ( V_2 -> V_40 -> V_205 )
V_169 = V_2 -> V_40 -> V_205 ( V_2 , V_63 ) ;
else
V_169 = - V_171 ;
V_63 -> V_133 = V_203 ;
if ( V_169 ) {
F_87 ( V_2 , L_33 , V_169 ) ;
F_78 ( V_2 ) ;
F_155 ( V_17 , V_63 ) ;
if ( V_169 != - V_59 )
return V_169 ;
if ( F_111 ( V_43 ) )
return V_169 ;
F_172 () ;
if ( F_92 ( V_63 ) )
V_63 -> V_101 = & V_206 ;
goto V_204;
}
F_81 ( V_100 , & V_2 -> V_50 ) ;
F_73 ( & V_89 ) ;
F_61 ( & V_43 -> V_45 -> V_78 ) ;
V_201 = ( V_63 -> V_133 & V_207 ) ||
( F_173 ( F_164 ) && V_28 == F_28 ( V_197 , 0 ) ) ||
V_28 == F_28 ( V_194 , 1 ) ||
( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_164 ) ;
if ( ! V_201 &&
V_43 -> signal -> V_90 &&
! V_43 -> signal -> V_2 &&
V_2 -> V_79 == NULL ) {
if ( V_63 -> V_208 & V_209 )
F_54 ( V_2 ) ;
}
F_62 ( & V_43 -> V_45 -> V_78 ) ;
F_75 ( & V_89 ) ;
F_78 ( V_2 ) ;
return 0 ;
}
static unsigned int F_174 ( struct V_6 * V_63 , T_6 * V_64 )
{
struct V_1 * V_2 = F_5 ( V_63 ) ;
struct V_82 * V_83 ;
int V_54 = 0 ;
if ( F_17 ( V_2 , F_103 ( V_63 ) , L_34 ) )
return 0 ;
V_83 = F_104 ( V_2 ) ;
if ( ! V_83 )
return F_48 ( V_63 , V_64 ) ;
if ( V_83 -> V_40 -> V_210 )
V_54 = V_83 -> V_40 -> V_210 ( V_2 , V_63 , V_64 ) ;
F_70 ( V_83 ) ;
return V_54 ;
}
static int F_79 ( int V_75 , struct V_6 * V_63 , int V_76 )
{
struct V_1 * V_2 = F_5 ( V_63 ) ;
unsigned long V_50 ;
int V_169 = 0 ;
if ( F_17 ( V_2 , F_103 ( V_63 ) , L_35 ) )
goto V_138;
V_169 = F_175 ( V_75 , V_63 , V_76 , & V_2 -> V_211 ) ;
if ( V_169 <= 0 )
goto V_138;
if ( V_76 ) {
enum V_212 type ;
struct V_51 * V_51 ;
F_39 ( & V_2 -> V_55 , V_50 ) ;
if ( V_2 -> V_52 ) {
V_51 = V_2 -> V_52 ;
type = V_213 ;
} else {
V_51 = F_176 ( V_43 ) ;
type = V_214 ;
}
F_56 ( V_51 ) ;
F_40 ( & V_2 -> V_55 , V_50 ) ;
F_177 ( V_63 , V_51 , type , 0 ) ;
F_55 ( V_51 ) ;
V_169 = 0 ;
}
V_138:
return V_169 ;
}
static int F_178 ( int V_75 , struct V_6 * V_63 , int V_76 )
{
struct V_1 * V_2 = F_5 ( V_63 ) ;
int V_169 = - V_74 ;
F_77 ( V_2 ) ;
if ( ! F_92 ( V_63 ) )
V_169 = F_79 ( V_75 , V_63 , V_76 ) ;
F_78 ( V_2 ) ;
return V_169 ;
}
static int F_179 ( struct V_1 * V_2 , char T_3 * V_21 )
{
char V_145 , V_215 = 0 ;
struct V_82 * V_83 ;
if ( ( V_43 -> signal -> V_2 != V_2 ) && ! F_131 ( V_166 ) )
return - V_216 ;
if ( F_180 ( V_145 , V_21 ) )
return - V_140 ;
F_181 ( V_2 , V_145 ) ;
V_83 = F_104 ( V_2 ) ;
if ( ! V_83 )
return - V_57 ;
V_83 -> V_40 -> V_217 ( V_2 , & V_145 , & V_215 , 1 ) ;
F_70 ( V_83 ) ;
return 0 ;
}
static int F_182 ( struct V_1 * V_2 , struct V_218 T_3 * V_72 )
{
int V_219 ;
F_32 ( & V_2 -> V_220 ) ;
V_219 = F_183 ( V_72 , & V_2 -> V_218 , sizeof( * V_72 ) ) ;
F_33 ( & V_2 -> V_220 ) ;
return V_219 ? - V_140 : 0 ;
}
int F_184 ( struct V_1 * V_2 , struct V_218 * V_221 )
{
struct V_51 * V_52 ;
F_32 ( & V_2 -> V_220 ) ;
if ( ! memcmp ( V_221 , & V_2 -> V_218 , sizeof( * V_221 ) ) )
goto V_222;
V_52 = F_94 ( V_2 ) ;
if ( V_52 )
F_42 ( V_52 , V_223 , 1 ) ;
F_55 ( V_52 ) ;
V_2 -> V_218 = * V_221 ;
V_222:
F_33 ( & V_2 -> V_220 ) ;
return 0 ;
}
static int F_185 ( struct V_1 * V_2 , struct V_218 T_3 * V_72 )
{
struct V_218 V_224 ;
if ( F_110 ( & V_224 , V_72 , sizeof( * V_72 ) ) )
return - V_140 ;
if ( V_2 -> V_40 -> V_225 )
return V_2 -> V_40 -> V_225 ( V_2 , & V_224 ) ;
else
return F_184 ( V_2 , & V_224 ) ;
}
static int F_186 ( struct V_6 * V_6 )
{
if ( ! F_131 ( V_166 ) )
return - V_216 ;
if ( V_6 -> V_101 -> V_102 == V_103 ) {
struct V_6 * V_95 ;
F_9 ( & V_98 ) ;
V_95 = V_99 ;
V_99 = NULL ;
F_11 ( & V_98 ) ;
if ( V_95 )
F_83 ( V_95 ) ;
return 0 ;
}
F_9 ( & V_98 ) ;
if ( V_99 ) {
F_11 ( & V_98 ) ;
return - V_167 ;
}
V_99 = F_115 ( V_6 ) ;
F_11 ( & V_98 ) ;
return 0 ;
}
static int F_187 ( struct V_6 * V_6 , int T_3 * V_21 )
{
int V_226 ;
if ( F_180 ( V_226 , V_21 ) )
return - V_140 ;
F_9 ( & V_6 -> V_227 ) ;
if ( V_226 )
V_6 -> V_133 |= V_196 ;
else
V_6 -> V_133 &= ~ V_196 ;
F_11 ( & V_6 -> V_227 ) ;
return 0 ;
}
static int F_188 ( struct V_1 * V_2 , struct V_6 * V_6 , int V_72 )
{
int V_54 = 0 ;
F_77 ( V_2 ) ;
F_73 ( & V_89 ) ;
if ( V_43 -> signal -> V_90 && ( F_57 ( V_43 ) == V_2 -> V_79 ) )
goto V_228;
if ( ! V_43 -> signal -> V_90 || V_43 -> signal -> V_2 ) {
V_54 = - V_216 ;
goto V_228;
}
if ( V_2 -> V_79 ) {
if ( V_72 == 1 && F_131 ( V_166 ) ) {
F_64 ( V_2 -> V_79 ) ;
} else {
V_54 = - V_216 ;
goto V_228;
}
}
if ( ( V_6 -> V_208 & V_209 ) == 0 && ! F_131 ( V_166 ) ) {
V_54 = - V_216 ;
goto V_228;
}
F_60 ( V_2 ) ;
V_228:
F_75 ( & V_89 ) ;
F_78 ( V_2 ) ;
return V_54 ;
}
struct V_51 * F_94 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
struct V_51 * V_52 ;
F_39 ( & V_2 -> V_55 , V_50 ) ;
V_52 = F_56 ( V_2 -> V_52 ) ;
F_40 ( & V_2 -> V_55 , V_50 ) ;
return V_52 ;
}
static struct V_51 * F_189 ( struct V_51 * V_52 )
{
struct V_77 * V_21 ;
struct V_51 * V_229 = NULL ;
V_21 = F_190 ( V_52 , V_213 ) ;
if ( V_21 == NULL )
V_21 = F_190 ( V_52 , V_214 ) ;
if ( V_21 != NULL )
V_229 = F_57 ( V_21 ) ;
return V_229 ;
}
static int F_191 ( struct V_1 * V_2 , struct V_1 * V_230 , T_7 T_3 * V_21 )
{
struct V_51 * V_51 ;
int V_54 ;
if ( V_2 == V_230 && V_43 -> signal -> V_2 != V_230 )
return - V_74 ;
V_51 = F_94 ( V_230 ) ;
V_54 = F_192 ( F_193 ( V_51 ) , V_21 ) ;
F_55 ( V_51 ) ;
return V_54 ;
}
static int F_194 ( struct V_1 * V_2 , struct V_1 * V_230 , T_7 T_3 * V_21 )
{
struct V_51 * V_52 ;
T_7 V_231 ;
int V_169 = F_45 ( V_230 ) ;
if ( V_169 == - V_57 )
return - V_74 ;
if ( V_169 )
return V_169 ;
if ( ! V_43 -> signal -> V_2 ||
( V_43 -> signal -> V_2 != V_230 ) ||
( V_230 -> V_79 != F_57 ( V_43 ) ) )
return - V_74 ;
if ( F_180 ( V_231 , V_21 ) )
return - V_140 ;
if ( V_231 < 0 )
return - V_232 ;
F_37 () ;
V_52 = F_195 ( V_231 ) ;
V_169 = - V_233 ;
if ( ! V_52 )
goto V_234;
V_169 = - V_216 ;
if ( F_189 ( V_52 ) != F_57 ( V_43 ) )
goto V_234;
V_169 = 0 ;
F_61 ( & V_2 -> V_55 ) ;
F_55 ( V_230 -> V_52 ) ;
V_230 -> V_52 = F_56 ( V_52 ) ;
F_62 ( & V_2 -> V_55 ) ;
V_234:
F_44 () ;
return V_169 ;
}
static int F_196 ( struct V_1 * V_2 , struct V_1 * V_230 , T_7 T_3 * V_21 )
{
if ( V_2 == V_230 && V_43 -> signal -> V_2 != V_230 )
return - V_74 ;
if ( ! V_230 -> V_79 )
return - V_74 ;
return F_192 ( F_193 ( V_230 -> V_79 ) , V_21 ) ;
}
static int F_197 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_235 ;
int V_54 ;
if ( F_180 ( V_235 , V_21 ) )
return - V_140 ;
V_54 = F_198 ( V_2 , V_235 ) ;
return V_54 ;
}
static int F_199 ( struct V_1 * V_2 , int T_3 * V_21 )
{
struct V_82 * V_83 ;
int V_54 ;
V_83 = F_104 ( V_2 ) ;
if ( ! V_83 )
return - V_57 ;
V_54 = F_192 ( V_83 -> V_40 -> V_33 , V_21 ) ;
F_70 ( V_83 ) ;
return V_54 ;
}
static int F_200 ( struct V_1 * V_2 , unsigned int V_236 )
{
int V_169 ;
if ( V_2 -> V_40 -> V_237 == NULL )
return 0 ;
if ( V_2 -> V_16 -> V_50 & V_238 )
V_169 = V_2 -> V_40 -> V_237 ( V_2 , V_236 ) ;
else {
if ( F_106 ( V_2 , 0 ) < 0 )
return - V_200 ;
V_169 = V_2 -> V_40 -> V_237 ( V_2 , - 1 ) ;
if ( V_169 )
goto V_138;
if ( ! F_111 ( V_43 ) )
F_201 ( V_236 ) ;
V_169 = V_2 -> V_40 -> V_237 ( V_2 , 0 ) ;
V_138:
F_105 ( V_2 ) ;
if ( F_111 ( V_43 ) )
V_169 = - V_200 ;
}
return V_169 ;
}
static int F_202 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_169 = - V_232 ;
if ( V_2 -> V_40 -> V_239 ) {
V_169 = V_2 -> V_40 -> V_239 ( V_2 ) ;
if ( V_169 >= 0 )
V_169 = F_192 ( V_169 , V_21 ) ;
}
return V_169 ;
}
static int F_203 ( struct V_1 * V_2 , unsigned int V_71 ,
unsigned T_3 * V_21 )
{
int V_169 ;
unsigned int V_240 , V_241 , V_242 ;
if ( V_2 -> V_40 -> V_243 == NULL )
return - V_232 ;
V_169 = F_180 ( V_242 , V_21 ) ;
if ( V_169 )
return V_169 ;
V_240 = V_241 = 0 ;
switch ( V_71 ) {
case V_244 :
V_240 = V_242 ;
break;
case V_245 :
V_241 = V_242 ;
break;
case V_246 :
V_240 = V_242 ;
V_241 = ~ V_242 ;
break;
}
V_240 &= V_247 | V_248 | V_249 | V_250 | V_251 ;
V_241 &= V_247 | V_248 | V_249 | V_250 | V_251 ;
return V_2 -> V_40 -> V_243 ( V_2 , V_240 , V_241 ) ;
}
static int F_204 ( struct V_1 * V_2 , void T_3 * V_72 )
{
int V_169 = - V_232 ;
struct V_252 V_253 ;
memset ( & V_253 , 0 , sizeof( V_253 ) ) ;
if ( V_2 -> V_40 -> V_254 )
V_169 = V_2 -> V_40 -> V_254 ( V_2 , & V_253 ) ;
if ( V_169 != 0 )
return V_169 ;
if ( F_183 ( V_72 , & V_253 , sizeof( V_253 ) ) )
return - V_140 ;
return 0 ;
}
static void F_205 ( struct V_255 T_3 * V_256 )
{
static F_206 ( V_257 ,
V_258 ,
V_259 ) ;
char V_260 [ V_261 ] ;
int V_50 ;
if ( F_180 ( V_50 , & V_256 -> V_50 ) )
return;
V_50 &= V_262 ;
if ( V_50 && F_207 ( & V_257 ) )
F_208 ( L_36 ,
V_176 , F_209 ( V_260 , V_43 ) , V_50 ) ;
}
static struct V_1 * F_210 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_164 )
V_2 = V_2 -> V_26 ;
return V_2 ;
}
long F_211 ( struct V_6 * V_6 , unsigned int V_71 , unsigned long V_72 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_1 * V_230 ;
void T_3 * V_21 = ( void T_3 * ) V_72 ;
int V_169 ;
struct V_82 * V_83 ;
if ( F_17 ( V_2 , F_103 ( V_6 ) , L_37 ) )
return - V_232 ;
V_230 = F_210 ( V_2 ) ;
switch ( V_71 ) {
case V_263 :
case V_264 :
case V_265 :
case V_266 :
case V_267 :
V_169 = F_45 ( V_2 ) ;
if ( V_169 )
return V_169 ;
if ( V_71 != V_265 ) {
F_212 ( V_2 , 0 ) ;
if ( F_111 ( V_43 ) )
return - V_200 ;
}
break;
}
switch ( V_71 ) {
case V_268 :
return F_179 ( V_2 , V_21 ) ;
case V_269 :
return F_182 ( V_230 , V_21 ) ;
case V_270 :
return F_185 ( V_230 , V_21 ) ;
case V_271 :
return V_230 != V_2 ? - V_232 : F_186 ( V_6 ) ;
case V_272 :
return F_187 ( V_6 , V_21 ) ;
case V_273 :
F_82 ( V_165 , & V_2 -> V_50 ) ;
return 0 ;
case V_274 :
F_81 ( V_165 , & V_2 -> V_50 ) ;
return 0 ;
case V_275 :
{
int V_276 = F_68 ( V_165 , & V_2 -> V_50 ) ;
return F_192 ( V_276 , ( int T_3 * ) V_21 ) ;
}
case V_277 :
if ( V_43 -> signal -> V_2 != V_2 )
return - V_74 ;
F_95 () ;
return 0 ;
case V_278 :
return F_188 ( V_230 , V_6 , V_72 ) ;
case V_279 :
return F_191 ( V_2 , V_230 , V_21 ) ;
case V_73 :
return F_194 ( V_2 , V_230 , V_21 ) ;
case V_280 :
return F_196 ( V_2 , V_230 , V_21 ) ;
case V_281 :
return F_199 ( V_2 , V_21 ) ;
case V_263 :
return F_197 ( V_2 , V_21 ) ;
case V_282 :
if ( ! F_131 ( V_166 ) )
return - V_216 ;
F_89 ( V_2 ) ;
return 0 ;
case V_283 :
{
unsigned int V_54 = F_213 ( F_214 ( V_230 ) ) ;
return F_192 ( V_54 , ( unsigned int T_3 * ) V_21 ) ;
}
case V_264 :
if ( V_2 -> V_40 -> V_237 )
return V_2 -> V_40 -> V_237 ( V_2 , - 1 ) ;
return 0 ;
case V_265 :
if ( V_2 -> V_40 -> V_237 )
return V_2 -> V_40 -> V_237 ( V_2 , 0 ) ;
return 0 ;
case V_266 :
if ( ! V_72 )
return F_200 ( V_2 , 250 ) ;
return 0 ;
case V_267 :
return F_200 ( V_2 , V_72 ? V_72 * 100 : 250 ) ;
case V_284 :
return F_202 ( V_2 , V_21 ) ;
case V_246 :
case V_245 :
case V_244 :
return F_203 ( V_2 , V_71 , V_21 ) ;
case V_285 :
V_169 = F_204 ( V_2 , V_21 ) ;
if ( V_169 != - V_232 )
return V_169 ;
break;
case V_286 :
switch ( V_72 ) {
case V_287 :
case V_288 :
F_215 ( V_2 , NULL ) ;
break;
}
break;
case V_289 :
F_205 ( V_21 ) ;
break;
}
if ( V_2 -> V_40 -> V_290 ) {
V_169 = V_2 -> V_40 -> V_290 ( V_2 , V_71 , V_72 ) ;
if ( V_169 != - V_291 )
return V_169 ;
}
V_83 = F_104 ( V_2 ) ;
if ( ! V_83 )
return F_49 ( V_6 , V_71 , V_72 ) ;
V_169 = - V_232 ;
if ( V_83 -> V_40 -> V_290 ) {
V_169 = V_83 -> V_40 -> V_290 ( V_2 , V_6 , V_71 , V_72 ) ;
if ( V_169 == - V_291 )
V_169 = - V_74 ;
}
F_70 ( V_83 ) ;
return V_169 ;
}
static long F_216 ( struct V_6 * V_6 , unsigned int V_71 ,
unsigned long V_72 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_82 * V_83 ;
int V_169 = - V_291 ;
if ( F_17 ( V_2 , F_103 ( V_6 ) , L_37 ) )
return - V_232 ;
if ( V_2 -> V_40 -> V_292 ) {
V_169 = V_2 -> V_40 -> V_292 ( V_2 , V_71 , V_72 ) ;
if ( V_169 != - V_291 )
return V_169 ;
}
V_83 = F_104 ( V_2 ) ;
if ( ! V_83 )
return F_50 ( V_6 , V_71 , V_72 ) ;
if ( V_83 -> V_40 -> V_292 )
V_169 = V_83 -> V_40 -> V_292 ( V_2 , V_6 , V_71 , V_72 ) ;
else
V_169 = F_217 ( V_2 , V_6 , V_71 , V_72 ) ;
F_70 ( V_83 ) ;
return V_169 ;
}
static int F_218 ( const void * V_293 , struct V_6 * V_6 , unsigned V_75 )
{
if ( F_219 ( V_6 -> V_101 -> V_126 != F_102 ) )
return 0 ;
return F_5 ( V_6 ) != V_293 ? 0 : V_75 + 1 ;
}
void F_220 ( struct V_1 * V_2 )
{
#ifdef F_221
F_86 ( V_2 ) ;
#else
struct V_77 * V_294 , * V_21 ;
struct V_51 * V_79 ;
int V_124 ;
if ( ! V_2 )
return;
V_79 = V_2 -> V_79 ;
F_222 ( V_2 ) ;
F_223 ( V_2 ) ;
F_73 ( & V_89 ) ;
F_65 (session, PIDTYPE_SID, p) {
F_224 ( V_2 , L_38 ,
F_225 ( V_21 ) , V_21 -> V_260 ) ;
F_226 ( V_295 , V_21 , 1 ) ;
} F_66 ( V_79 , V_81 , V_21 ) ;
F_227 (g, p) {
if ( V_21 -> signal -> V_2 == V_2 ) {
F_224 ( V_2 , L_39 ,
F_225 ( V_21 ) , V_21 -> V_260 ) ;
F_226 ( V_295 , V_21 , 1 ) ;
continue;
}
F_228 ( V_21 ) ;
V_124 = F_229 ( V_21 -> V_296 , 0 , F_218 , V_2 ) ;
if ( V_124 != 0 ) {
F_224 ( V_2 , L_40 ,
F_225 ( V_21 ) , V_21 -> V_260 , V_124 - 1 ) ;
F_230 ( V_295 , V_21 ) ;
}
F_231 ( V_21 ) ;
} F_232 ( V_294 , V_21 ) ;
F_75 ( & V_89 ) ;
#endif
}
static void F_233 ( struct V_110 * V_111 )
{
struct V_1 * V_2 =
F_85 ( V_111 , struct V_1 , V_179 ) ;
F_220 ( V_2 ) ;
}
void F_234 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_88 ( & V_2 -> V_179 ) ;
}
static int F_235 ( struct V_28 * V_3 , const void * V_297 )
{
const T_1 * V_298 = V_297 ;
return V_3 -> V_298 == * V_298 ;
}
static struct V_28 * F_236 ( struct V_1 * V_2 )
{
T_1 V_298 = F_214 ( V_2 ) ;
return F_237 ( V_299 , NULL , & V_298 , F_235 ) ;
}
struct V_1 * F_136 ( struct V_27 * V_16 , int V_152 )
{
struct V_1 * V_2 ;
V_2 = F_238 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_239 ( & V_2 -> V_182 ) ;
V_2 -> V_5 = V_19 ;
F_240 ( V_2 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_52 = NULL ;
F_241 ( & V_2 -> V_300 ) ;
F_241 ( & V_2 -> V_301 ) ;
F_242 ( & V_2 -> V_148 ) ;
F_241 ( & V_2 -> V_220 ) ;
F_243 ( & V_2 -> V_302 ) ;
F_244 ( & V_2 -> V_86 ) ;
F_244 ( & V_2 -> V_191 ) ;
F_149 ( & V_2 -> V_112 , F_84 ) ;
F_241 ( & V_2 -> V_128 ) ;
F_245 ( & V_2 -> V_55 ) ;
F_245 ( & V_2 -> V_118 ) ;
F_245 ( & V_2 -> V_12 ) ;
F_246 ( & V_2 -> V_14 ) ;
F_149 ( & V_2 -> V_179 , F_233 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_40 = V_16 -> V_40 ;
V_2 -> V_29 = V_152 ;
F_121 ( V_16 , V_152 , V_2 -> V_15 ) ;
V_2 -> V_3 = F_236 ( V_2 ) ;
return V_2 ;
}
int F_247 ( struct V_1 * V_2 , unsigned char V_145 )
{
if ( V_2 -> V_40 -> V_303 )
return V_2 -> V_40 -> V_303 ( V_2 , V_145 ) ;
return V_2 -> V_40 -> V_102 ( V_2 , & V_145 , 1 ) ;
}
static int F_248 ( struct V_27 * V_16 , T_1 V_3 ,
unsigned int V_29 , unsigned int V_22 )
{
int V_219 ;
V_16 -> V_304 [ V_29 ] = F_249 () ;
if ( ! V_16 -> V_304 [ V_29 ] )
return - V_11 ;
V_16 -> V_304 [ V_29 ] -> V_40 = & V_206 ;
V_16 -> V_304 [ V_29 ] -> V_170 = V_16 -> V_170 ;
V_219 = F_250 ( V_16 -> V_304 [ V_29 ] , V_3 , V_22 ) ;
if ( V_219 )
F_251 ( & V_16 -> V_304 [ V_29 ] -> V_305 ) ;
return V_219 ;
}
struct V_28 * F_252 ( struct V_27 * V_16 , unsigned V_29 ,
struct V_28 * V_28 )
{
return F_253 ( V_16 , V_29 , V_28 , NULL , NULL ) ;
}
static void F_254 ( struct V_28 * V_3 )
{
F_255 ( V_3 , L_41 ) ;
F_4 ( V_3 ) ;
}
struct V_28 * F_253 ( struct V_27 * V_16 ,
unsigned V_29 , struct V_28 * V_28 ,
void * V_306 ,
const struct V_307 * * V_308 )
{
char V_15 [ 64 ] ;
T_1 V_298 = F_28 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ;
struct V_28 * V_3 = NULL ;
int V_169 = - V_171 ;
bool V_309 = false ;
if ( V_29 >= V_16 -> V_33 ) {
F_256 ( L_42 ,
V_16 -> V_15 , V_29 ) ;
return F_135 ( - V_232 ) ;
}
if ( V_16 -> type == V_23 )
F_120 ( V_16 , V_29 , V_15 ) ;
else
F_121 ( V_16 , V_29 , V_15 ) ;
if ( ! ( V_16 -> V_50 & V_310 ) ) {
V_169 = F_248 ( V_16 , V_298 , V_29 , 1 ) ;
if ( V_169 )
goto error;
V_309 = true ;
}
V_3 = F_238 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 ) {
V_169 = - V_11 ;
goto error;
}
V_3 -> V_298 = V_298 ;
V_3 -> V_311 = V_299 ;
V_3 -> V_312 = V_28 ;
V_3 -> V_313 = F_254 ;
F_257 ( V_3 , L_18 , V_15 ) ;
V_3 -> V_314 = V_308 ;
F_258 ( V_3 , V_306 ) ;
V_169 = F_259 ( V_3 ) ;
if ( V_169 )
goto error;
return V_3 ;
error:
F_3 ( V_3 ) ;
if ( V_309 ) {
F_260 ( V_16 -> V_304 [ V_29 ] ) ;
V_16 -> V_304 [ V_29 ] = NULL ;
}
return F_135 ( V_169 ) ;
}
void F_261 ( struct V_27 * V_16 , unsigned V_29 )
{
F_262 ( V_299 ,
F_28 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ) ;
if ( ! ( V_16 -> V_50 & V_310 ) ) {
F_260 ( V_16 -> V_304 [ V_29 ] ) ;
V_16 -> V_304 [ V_29 ] = NULL ;
}
}
struct V_27 * F_263 ( unsigned int V_315 , struct V_180 * V_170 ,
unsigned long V_50 )
{
struct V_27 * V_16 ;
unsigned int V_304 = 1 ;
int V_219 ;
if ( ! V_315 || ( V_50 & V_151 && V_315 > 1 ) )
return F_135 ( - V_232 ) ;
V_16 = F_238 ( sizeof( struct V_27 ) , V_10 ) ;
if ( ! V_16 )
return F_135 ( - V_11 ) ;
F_239 ( & V_16 -> V_182 ) ;
V_16 -> V_5 = V_316 ;
V_16 -> V_33 = V_315 ;
V_16 -> V_170 = V_170 ;
V_16 -> V_50 = V_50 ;
if ( ! ( V_50 & V_184 ) ) {
V_16 -> V_154 = F_264 ( V_315 , sizeof( * V_16 -> V_154 ) ,
V_10 ) ;
V_16 -> V_158 = F_264 ( V_315 , sizeof( * V_16 -> V_158 ) ,
V_10 ) ;
if ( ! V_16 -> V_154 || ! V_16 -> V_158 ) {
V_219 = - V_11 ;
goto V_317;
}
}
if ( ! ( V_50 & V_310 ) ) {
V_16 -> V_175 = F_264 ( V_315 , sizeof( * V_16 -> V_175 ) ,
V_10 ) ;
if ( ! V_16 -> V_175 ) {
V_219 = - V_11 ;
goto V_317;
}
V_304 = V_315 ;
}
V_16 -> V_304 = F_264 ( V_304 , sizeof( * V_16 -> V_304 ) , V_10 ) ;
if ( ! V_16 -> V_304 ) {
V_219 = - V_11 ;
goto V_317;
}
return V_16 ;
V_317:
F_4 ( V_16 -> V_175 ) ;
F_4 ( V_16 -> V_154 ) ;
F_4 ( V_16 -> V_158 ) ;
F_4 ( V_16 -> V_304 ) ;
F_4 ( V_16 ) ;
return F_135 ( V_219 ) ;
}
static void F_265 ( struct V_182 * V_182 )
{
struct V_27 * V_16 = F_85 ( V_182 , struct V_27 , V_182 ) ;
int V_124 ;
struct V_155 * V_156 ;
if ( V_16 -> V_50 & V_318 ) {
for ( V_124 = 0 ; V_124 < V_16 -> V_33 ; V_124 ++ ) {
V_156 = V_16 -> V_158 [ V_124 ] ;
if ( V_156 ) {
V_16 -> V_158 [ V_124 ] = NULL ;
F_4 ( V_156 ) ;
}
if ( ! ( V_16 -> V_50 & V_319 ) )
F_261 ( V_16 , V_124 ) ;
}
F_266 ( V_16 ) ;
if ( V_16 -> V_50 & V_310 )
F_260 ( V_16 -> V_304 [ 0 ] ) ;
}
F_4 ( V_16 -> V_304 ) ;
F_4 ( V_16 -> V_175 ) ;
F_4 ( V_16 -> V_158 ) ;
F_4 ( V_16 -> V_154 ) ;
F_4 ( V_16 ) ;
}
void F_146 ( struct V_27 * V_16 )
{
F_150 ( & V_16 -> V_182 , F_265 ) ;
}
void F_267 ( struct V_27 * V_16 ,
const struct V_320 * V_321 )
{
V_16 -> V_40 = V_321 ;
}
void F_268 ( struct V_27 * V_322 )
{
F_146 ( V_322 ) ;
}
int F_269 ( struct V_27 * V_16 )
{
int error ;
int V_124 ;
T_1 V_3 ;
struct V_28 * V_322 ;
if ( ! V_16 -> V_31 ) {
error = F_270 ( & V_3 , V_16 -> V_32 ,
V_16 -> V_33 , V_16 -> V_15 ) ;
if ( ! error ) {
V_16 -> V_31 = F_271 ( V_3 ) ;
V_16 -> V_32 = F_272 ( V_3 ) ;
}
} else {
V_3 = F_28 ( V_16 -> V_31 , V_16 -> V_32 ) ;
error = F_273 ( V_3 , V_16 -> V_33 , V_16 -> V_15 ) ;
}
if ( error < 0 )
goto V_219;
if ( V_16 -> V_50 & V_310 ) {
error = F_248 ( V_16 , V_3 , 0 , V_16 -> V_33 ) ;
if ( error )
goto V_323;
}
F_32 ( & V_39 ) ;
F_10 ( & V_16 -> V_324 , & V_324 ) ;
F_33 ( & V_39 ) ;
if ( ! ( V_16 -> V_50 & V_319 ) ) {
for ( V_124 = 0 ; V_124 < V_16 -> V_33 ; V_124 ++ ) {
V_322 = F_252 ( V_16 , V_124 , NULL ) ;
if ( F_123 ( V_322 ) ) {
error = F_171 ( V_322 ) ;
goto V_325;
}
}
}
F_274 ( V_16 ) ;
V_16 -> V_50 |= V_318 ;
return 0 ;
V_325:
for ( V_124 -- ; V_124 >= 0 ; V_124 -- )
F_261 ( V_16 , V_124 ) ;
F_32 ( & V_39 ) ;
F_14 ( & V_16 -> V_324 ) ;
F_33 ( & V_39 ) ;
V_323:
F_275 ( V_3 , V_16 -> V_33 ) ;
V_219:
return error ;
}
int F_276 ( struct V_27 * V_16 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_275 ( F_28 ( V_16 -> V_31 , V_16 -> V_32 ) ,
V_16 -> V_33 ) ;
F_32 ( & V_39 ) ;
F_14 ( & V_16 -> V_324 ) ;
F_33 ( & V_39 ) ;
return 0 ;
}
T_1 F_214 ( struct V_1 * V_2 )
{
return F_28 ( V_2 -> V_16 -> V_31 , V_2 -> V_16 -> V_32 ) + V_2 -> V_29 ;
}
void F_277 ( struct V_326 * V_327 )
{
* V_327 = V_206 ;
}
void T_8 F_278 ( void )
{
T_9 * V_328 ;
F_279 () ;
V_328 = V_329 ;
while ( V_328 < V_330 ) {
(* V_328)() ;
V_328 ++ ;
}
}
static char * F_280 ( struct V_28 * V_3 , T_10 * V_331 )
{
if ( ! V_331 )
return NULL ;
if ( V_3 -> V_298 == F_28 ( V_194 , 0 ) ||
V_3 -> V_298 == F_28 ( V_194 , 2 ) )
* V_331 = 0666 ;
return NULL ;
}
static int T_8 F_281 ( void )
{
V_299 = F_282 ( V_332 , L_17 ) ;
if ( F_123 ( V_299 ) )
return F_171 ( V_299 ) ;
V_299 -> V_333 = F_280 ;
return 0 ;
}
static T_2 F_283 ( struct V_28 * V_3 ,
struct V_334 * V_335 , char * V_61 )
{
struct V_336 * V_337 [ 16 ] ;
int V_124 = 0 ;
struct V_336 * V_338 ;
T_2 V_22 = 0 ;
F_284 () ;
F_285 (c) {
if ( ! V_338 -> V_28 )
continue;
if ( ! V_338 -> V_102 )
continue;
if ( ( V_338 -> V_50 & V_339 ) == 0 )
continue;
V_337 [ V_124 ++ ] = V_338 ;
if ( V_124 >= F_286 ( V_337 ) )
break;
}
while ( V_124 -- ) {
int V_29 = V_337 [ V_124 ] -> V_29 ;
struct V_27 * V_340 = V_337 [ V_124 ] -> V_28 ( V_337 [ V_124 ] , & V_29 ) ;
if ( V_340 && ( V_337 [ V_124 ] -> V_29 > 0 || V_340 -> V_31 != V_197 ) )
V_22 += F_121 ( V_340 , V_29 , V_61 + V_22 ) ;
else
V_22 += sprintf ( V_61 + V_22 , L_19 ,
V_337 [ V_124 ] -> V_15 , V_337 [ V_124 ] -> V_29 ) ;
V_22 += sprintf ( V_61 + V_22 , L_43 , V_124 ? ' ' : '\n' ) ;
}
F_287 () ;
return V_22 ;
}
void F_288 ( void )
{
if ( V_341 )
F_289 ( & V_341 -> V_305 , NULL , L_44 ) ;
}
int T_8 F_290 ( void )
{
F_291 ( & V_342 , & V_206 ) ;
if ( F_250 ( & V_342 , F_28 ( V_194 , 0 ) , 1 ) ||
F_273 ( F_28 ( V_194 , 0 ) , 1 , L_45 ) < 0 )
F_292 ( L_46 ) ;
F_293 ( V_299 , NULL , F_28 ( V_194 , 0 ) , NULL , L_17 ) ;
F_291 ( & V_343 , & V_344 ) ;
if ( F_250 ( & V_343 , F_28 ( V_194 , 1 ) , 1 ) ||
F_273 ( F_28 ( V_194 , 1 ) , 1 , L_47 ) < 0 )
F_292 ( L_48 ) ;
V_341 = F_294 ( V_299 , NULL ,
F_28 ( V_194 , 1 ) , NULL ,
V_345 , L_49 ) ;
if ( F_123 ( V_341 ) )
V_341 = NULL ;
#ifdef F_164
F_295 ( & V_344 ) ;
#endif
return 0 ;
}
