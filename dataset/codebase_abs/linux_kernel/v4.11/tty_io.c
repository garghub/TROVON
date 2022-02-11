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
return ( V_63 && V_63 -> V_101 == & V_105 ) ;
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
if ( ! V_2 || F_104 ( V_2 ) )
return - V_57 ;
V_83 = F_105 ( V_2 ) ;
if ( ! V_83 )
return F_46 ( V_6 , V_61 , V_22 , V_62 ) ;
if ( V_83 -> V_40 -> V_125 )
V_124 = V_83 -> V_40 -> V_125 ( V_2 , V_6 , V_61 , V_22 ) ;
else
V_124 = - V_57 ;
F_70 ( V_83 ) ;
if ( V_124 > 0 )
F_100 ( & V_17 -> V_126 ) ;
return V_124 ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_127 ) ;
F_71 ( & V_2 -> V_86 , V_66 ) ;
}
static int F_107 ( struct V_1 * V_2 , int V_128 )
{
if ( ! F_108 ( & V_2 -> V_127 ) ) {
if ( V_128 )
return - V_129 ;
if ( F_109 ( & V_2 -> V_127 ) )
return - V_59 ;
}
return 0 ;
}
static inline T_2 F_110 (
T_2 (* V_102)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_61 ,
T_4 V_22 )
{
T_2 V_54 , V_130 = 0 ;
unsigned int V_131 ;
V_54 = F_107 ( V_2 , V_6 -> V_132 & V_133 ) ;
if ( V_54 < 0 )
return V_54 ;
V_131 = 2048 ;
if ( F_68 ( V_134 , & V_2 -> V_50 ) )
V_131 = 65536 ;
if ( V_22 < V_131 )
V_131 = V_22 ;
if ( V_2 -> V_135 < V_131 ) {
unsigned char * V_136 ;
if ( V_131 < 1024 )
V_131 = 1024 ;
V_136 = F_7 ( V_131 , V_10 ) ;
if ( ! V_136 ) {
V_54 = - V_11 ;
goto V_137;
}
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_135 = V_131 ;
V_2 -> V_4 = V_136 ;
}
for (; ; ) {
T_4 V_138 = V_22 ;
if ( V_138 > V_131 )
V_138 = V_131 ;
V_54 = - V_139 ;
if ( F_111 ( V_2 -> V_4 , V_61 , V_138 ) )
break;
V_54 = V_102 ( V_2 , V_6 , V_2 -> V_4 , V_138 ) ;
if ( V_54 <= 0 )
break;
V_130 += V_54 ;
V_61 += V_54 ;
V_22 -= V_54 ;
if ( ! V_22 )
break;
V_54 = - V_59 ;
if ( F_112 ( V_43 ) )
break;
F_113 () ;
}
if ( V_130 ) {
F_100 ( & F_103 ( V_6 ) -> V_140 ) ;
V_54 = V_130 ;
}
V_137:
F_106 ( V_2 ) ;
return V_54 ;
}
void F_114 ( struct V_1 * V_2 , char * V_141 )
{
if ( V_2 ) {
F_32 ( & V_2 -> V_127 ) ;
F_77 ( V_2 ) ;
if ( V_2 -> V_40 -> V_102 && V_2 -> V_22 > 0 )
V_2 -> V_40 -> V_102 ( V_2 , V_141 , strlen ( V_141 ) ) ;
F_78 ( V_2 ) ;
F_106 ( V_2 ) ;
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
if ( ! V_2 || ! V_2 -> V_40 -> V_102 || F_104 ( V_2 ) )
return - V_57 ;
if ( V_2 -> V_40 -> V_142 == NULL )
F_115 ( V_2 , L_15 ) ;
V_83 = F_105 ( V_2 ) ;
if ( ! V_83 )
return F_47 ( V_6 , V_61 , V_22 , V_62 ) ;
if ( ! V_83 -> V_40 -> V_102 )
V_54 = - V_57 ;
else
V_54 = F_110 ( V_83 -> V_40 -> V_102 , V_2 , V_6 , V_61 , V_22 ) ;
F_70 ( V_83 ) ;
return V_54 ;
}
T_2 V_103 ( struct V_6 * V_6 , const char T_3 * V_61 ,
T_4 V_22 , T_5 * V_62 )
{
struct V_6 * V_21 = NULL ;
F_9 ( & V_98 ) ;
if ( V_99 )
V_21 = F_116 ( V_99 ) ;
F_11 ( & V_98 ) ;
if ( V_21 ) {
T_2 V_34 ;
V_34 = F_117 ( V_21 , V_61 , V_22 , & V_21 -> V_143 ) ;
F_83 ( V_21 ) ;
return V_34 ;
}
return V_104 ( V_6 , V_61 , V_22 , V_62 ) ;
}
int F_118 ( struct V_1 * V_2 , char V_144 )
{
int V_145 = V_2 -> V_116 ;
if ( V_2 -> V_40 -> V_146 ) {
F_119 ( & V_2 -> V_147 ) ;
V_2 -> V_40 -> V_146 ( V_2 , V_144 ) ;
F_120 ( & V_2 -> V_147 ) ;
return 0 ;
}
if ( F_107 ( V_2 , 0 ) < 0 )
return - V_59 ;
F_119 ( & V_2 -> V_147 ) ;
if ( V_145 )
F_99 ( V_2 ) ;
V_2 -> V_40 -> V_102 ( V_2 , & V_144 , 1 ) ;
if ( V_145 )
F_97 ( V_2 ) ;
F_120 ( & V_2 -> V_147 ) ;
F_106 ( V_2 ) ;
return 0 ;
}
static void F_121 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
int V_124 = V_29 + V_16 -> V_148 ;
sprintf ( V_21 , L_16 ,
V_16 -> V_24 == V_25 ? L_17 : V_16 -> V_15 ,
V_149 [ V_124 >> 4 & 0xf ] , V_124 & 0xf ) ;
}
static T_2 F_122 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
if ( V_16 -> V_50 & V_150 )
return sprintf ( V_21 , L_18 , V_16 -> V_15 ) ;
else
return sprintf ( V_21 , L_19 , V_16 -> V_15 ,
V_29 + V_16 -> V_148 ) ;
}
static struct V_1 * F_123 ( struct V_27 * V_16 ,
struct V_6 * V_6 , int V_151 )
{
struct V_1 * V_2 ;
if ( V_16 -> V_40 -> V_152 )
V_2 = V_16 -> V_40 -> V_152 ( V_16 , V_6 , V_151 ) ;
else
V_2 = V_16 -> V_153 [ V_151 ] ;
if ( ! F_124 ( V_2 ) )
F_59 ( V_2 ) ;
return V_2 ;
}
void F_125 ( struct V_1 * V_2 )
{
struct V_154 * V_155 ;
int V_151 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_50 & V_156 )
V_2 -> V_157 = V_2 -> V_16 -> V_158 ;
else {
V_155 = V_2 -> V_16 -> V_157 [ V_151 ] ;
if ( V_155 != NULL ) {
V_2 -> V_157 = * V_155 ;
V_2 -> V_157 . V_159 = V_2 -> V_16 -> V_158 . V_159 ;
} else
V_2 -> V_157 = V_2 -> V_16 -> V_158 ;
}
V_2 -> V_157 . V_160 = F_126 ( & V_2 -> V_157 ) ;
V_2 -> V_157 . V_161 = F_127 ( & V_2 -> V_157 ) ;
}
int F_128 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
F_125 ( V_2 ) ;
F_29 ( V_16 ) ;
V_2 -> V_22 ++ ;
V_16 -> V_153 [ V_2 -> V_29 ] = V_2 ;
return 0 ;
}
static int F_129 ( struct V_27 * V_16 ,
struct V_1 * V_2 )
{
return V_16 -> V_40 -> V_162 ? V_16 -> V_40 -> V_162 ( V_16 , V_2 ) :
F_128 ( V_16 , V_2 ) ;
}
static void F_130 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
if ( V_16 -> V_40 -> remove )
V_16 -> V_40 -> remove ( V_16 , V_2 ) ;
else
V_16 -> V_153 [ V_2 -> V_29 ] = NULL ;
}
static int F_131 ( struct V_1 * V_2 )
{
struct V_27 * V_16 = V_2 -> V_16 ;
if ( V_16 -> type == V_23 &&
V_16 -> V_24 == V_163 )
return - V_57 ;
if ( ! V_2 -> V_22 )
return - V_129 ;
if ( F_68 ( V_164 , & V_2 -> V_50 ) && ! F_132 ( V_165 ) )
return - V_166 ;
V_2 -> V_22 ++ ;
if ( ! V_2 -> V_167 )
return F_133 ( V_2 , V_2 -> V_157 . V_159 ) ;
return 0 ;
}
struct V_1 * F_134 ( struct V_27 * V_16 , int V_151 )
{
struct V_1 * V_2 ;
int V_168 ;
if ( ! F_135 ( V_16 -> V_169 ) )
return F_136 ( - V_170 ) ;
V_2 = F_137 ( V_16 , V_151 ) ;
if ( ! V_2 ) {
V_168 = - V_11 ;
goto V_171;
}
F_77 ( V_2 ) ;
V_168 = F_129 ( V_16 , V_2 ) ;
if ( V_168 < 0 )
goto V_172;
if ( ! V_2 -> V_173 )
V_2 -> V_173 = V_16 -> V_174 [ V_151 ] ;
F_138 ( ! V_2 -> V_173 ,
L_20 ,
V_175 , V_2 -> V_16 -> V_15 ) ;
V_2 -> V_173 -> V_176 = V_2 ;
V_168 = F_139 ( V_2 , V_2 -> V_26 ) ;
if ( V_168 )
goto V_177;
return V_2 ;
V_172:
F_78 ( V_2 ) ;
F_1 ( V_2 ) ;
V_171:
F_140 ( V_16 -> V_169 ) ;
return F_136 ( V_168 ) ;
V_177:
F_78 ( V_2 ) ;
F_141 ( V_2 , L_21 ,
V_168 , V_151 ) ;
F_142 ( V_2 , V_151 ) ;
return F_136 ( V_168 ) ;
}
static void F_143 ( struct V_1 * V_2 )
{
struct V_154 * V_155 ;
int V_151 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_50 & V_156 )
return;
V_155 = V_2 -> V_16 -> V_157 [ V_151 ] ;
if ( V_155 == NULL ) {
V_155 = F_7 ( sizeof( struct V_154 ) , V_10 ) ;
if ( V_155 == NULL )
return;
V_2 -> V_16 -> V_157 [ V_151 ] = V_155 ;
}
* V_155 = V_2 -> V_157 ;
}
static void F_144 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_178 ) ;
F_145 ( & V_2 -> V_112 ) ;
if ( V_2 -> V_26 ) {
F_145 ( & V_2 -> V_26 -> V_178 ) ;
F_145 ( & V_2 -> V_26 -> V_112 ) ;
}
}
static void F_146 ( struct V_110 * V_111 )
{
struct V_1 * V_2 =
F_85 ( V_111 , struct V_1 , V_112 ) ;
struct V_27 * V_16 = V_2 -> V_16 ;
struct V_179 * V_169 = V_16 -> V_169 ;
if ( V_2 -> V_40 -> V_180 )
V_2 -> V_40 -> V_180 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_147 ( V_16 ) ;
F_140 ( V_169 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_148 ( & V_2 -> V_14 ) ;
F_11 ( & V_2 -> V_12 ) ;
F_55 ( V_2 -> V_52 ) ;
F_55 ( V_2 -> V_79 ) ;
F_1 ( V_2 ) ;
}
static void F_149 ( struct V_181 * V_181 )
{
struct V_1 * V_2 = F_85 ( V_181 , struct V_1 , V_181 ) ;
F_150 ( & V_2 -> V_112 , F_146 ) ;
F_88 ( & V_2 -> V_112 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( V_2 )
F_151 ( & V_2 -> V_181 , F_149 ) ;
}
static void F_142 ( struct V_1 * V_2 , int V_151 )
{
F_152 ( V_2 -> V_29 != V_151 ) ;
F_152 ( ! F_153 ( & V_39 ) ) ;
if ( V_2 -> V_40 -> V_182 )
V_2 -> V_40 -> V_182 ( V_2 ) ;
F_143 ( V_2 ) ;
F_130 ( V_2 -> V_16 , V_2 ) ;
V_2 -> V_173 -> V_176 = NULL ;
if ( V_2 -> V_26 )
V_2 -> V_26 -> V_173 -> V_176 = NULL ;
F_154 ( V_2 -> V_173 ) ;
F_53 ( V_2 -> V_26 ) ;
F_53 ( V_2 ) ;
}
static int F_155 ( struct V_1 * V_2 , int V_151 )
{
#ifdef F_18
if ( V_151 < 0 || V_151 >= V_2 -> V_16 -> V_33 ) {
F_58 ( V_2 , L_22 , V_151 ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_50 & V_183 )
return 0 ;
if ( V_2 != V_2 -> V_16 -> V_153 [ V_151 ] ) {
F_58 ( V_2 , L_23 ,
V_151 , V_2 -> V_16 -> V_153 [ V_151 ] ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_184 ) {
struct V_1 * V_185 = V_2 -> V_26 ;
if ( V_185 != V_2 -> V_16 -> V_184 -> V_153 [ V_151 ] ) {
F_58 ( V_2 , L_24 ,
V_151 , V_2 -> V_16 -> V_184 -> V_153 [ V_151 ] ) ;
return - 1 ;
}
if ( V_185 -> V_26 != V_2 ) {
F_58 ( V_2 , L_25 , V_185 -> V_26 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
void F_156 ( struct V_1 * V_2 , int V_151 )
{
F_157 ( V_2 ) ;
F_144 ( V_2 ) ;
F_87 ( V_2 , L_26 ) ;
F_32 ( & V_39 ) ;
F_142 ( V_2 , V_151 ) ;
F_33 ( & V_39 ) ;
}
int F_158 ( struct V_17 * V_17 , struct V_6 * V_63 )
{
struct V_1 * V_2 = F_5 ( V_63 ) ;
struct V_1 * V_185 = NULL ;
int V_186 , V_187 ;
int V_151 ;
long V_188 = 0 ;
int V_189 = 1 ;
if ( F_17 ( V_2 , V_17 , V_175 ) )
return 0 ;
F_77 ( V_2 ) ;
F_22 ( V_2 , V_175 ) ;
F_79 ( - 1 , V_63 , 0 ) ;
V_151 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_163 )
V_185 = V_2 -> V_26 ;
if ( F_155 ( V_2 , V_151 ) ) {
F_78 ( V_2 ) ;
return 0 ;
}
F_87 ( V_2 , L_27 , V_2 -> V_22 ) ;
if ( V_2 -> V_40 -> V_108 )
V_2 -> V_40 -> V_108 ( V_2 , V_63 ) ;
F_159 ( V_185 ) ;
while ( 1 ) {
V_186 = 0 ;
if ( V_2 -> V_22 <= 1 ) {
if ( F_160 ( & V_2 -> V_190 ) ) {
F_161 ( & V_2 -> V_190 , V_65 ) ;
V_186 ++ ;
}
if ( F_160 ( & V_2 -> V_86 ) ) {
F_161 ( & V_2 -> V_86 , V_66 ) ;
V_186 ++ ;
}
}
if ( V_185 && V_185 -> V_22 <= 1 ) {
if ( F_160 ( & V_185 -> V_190 ) ) {
F_161 ( & V_185 -> V_190 , V_65 ) ;
V_186 ++ ;
}
if ( F_160 ( & V_185 -> V_86 ) ) {
F_161 ( & V_185 -> V_86 , V_66 ) ;
V_186 ++ ;
}
}
if ( ! V_186 )
break;
if ( V_189 ) {
V_189 = 0 ;
F_25 ( V_2 , L_28 ) ;
}
F_162 ( V_188 ) ;
if ( V_188 < 120 * V_191 )
V_188 = 2 * V_188 + 1 ;
else
V_188 = V_192 ;
}
if ( V_185 ) {
if ( -- V_185 -> V_22 < 0 ) {
F_25 ( V_2 , L_29 , V_185 -> V_22 ) ;
V_185 -> V_22 = 0 ;
}
}
if ( -- V_2 -> V_22 < 0 ) {
F_25 ( V_2 , L_30 , V_2 -> V_22 ) ;
V_2 -> V_22 = 0 ;
}
F_13 ( V_63 ) ;
if ( ! V_2 -> V_22 ) {
F_73 ( & V_89 ) ;
F_64 ( V_2 -> V_79 ) ;
if ( V_185 )
F_64 ( V_185 -> V_79 ) ;
F_75 ( & V_89 ) ;
}
V_187 = ! V_2 -> V_22 && ! ( V_185 && V_185 -> V_22 ) ;
F_163 ( V_185 ) ;
F_78 ( V_2 ) ;
if ( ! V_187 )
return 0 ;
F_87 ( V_2 , L_31 ) ;
F_156 ( V_2 , V_151 ) ;
return 0 ;
}
static struct V_1 * F_164 ( T_1 V_28 , struct V_6 * V_63 )
{
struct V_1 * V_2 ;
int V_168 ;
if ( V_28 != F_28 ( V_193 , 0 ) )
return NULL ;
V_2 = F_63 () ;
if ( ! V_2 )
return F_136 ( - V_194 ) ;
V_63 -> V_132 |= V_195 ;
F_77 ( V_2 ) ;
F_53 ( V_2 ) ;
V_168 = F_131 ( V_2 ) ;
if ( V_168 < 0 ) {
F_78 ( V_2 ) ;
V_2 = F_136 ( V_168 ) ;
}
return V_2 ;
}
static struct V_27 * F_165 ( T_1 V_28 , struct V_6 * V_63 ,
int * V_29 )
{
struct V_27 * V_16 ;
switch ( V_28 ) {
#ifdef F_166
case F_28 ( V_196 , 0 ) : {
extern struct V_27 * V_197 ;
V_16 = F_29 ( V_197 ) ;
* V_29 = V_198 ;
break;
}
#endif
case F_28 ( V_193 , 1 ) : {
struct V_27 * V_197 = F_167 ( V_29 ) ;
if ( V_197 ) {
V_16 = F_29 ( V_197 ) ;
if ( V_16 ) {
V_63 -> V_132 |= V_195 ;
break;
}
}
return F_136 ( - V_170 ) ;
}
default:
V_16 = F_26 ( V_28 , V_29 ) ;
if ( ! V_16 )
return F_136 ( - V_170 ) ;
break;
}
return V_16 ;
}
static struct V_1 * F_168 ( T_1 V_28 , struct V_17 * V_17 ,
struct V_6 * V_63 )
{
struct V_1 * V_2 ;
struct V_27 * V_16 = NULL ;
int V_29 = - 1 ;
int V_168 ;
F_32 ( & V_39 ) ;
V_16 = F_165 ( V_28 , V_63 , & V_29 ) ;
if ( F_124 ( V_16 ) ) {
F_33 ( & V_39 ) ;
return F_169 ( V_16 ) ;
}
V_2 = F_123 ( V_16 , V_63 , V_29 ) ;
if ( F_124 ( V_2 ) ) {
F_33 ( & V_39 ) ;
goto V_137;
}
if ( V_2 ) {
F_33 ( & V_39 ) ;
V_168 = F_170 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( V_168 ) {
if ( V_168 == - V_199 )
V_168 = - V_59 ;
V_2 = F_136 ( V_168 ) ;
goto V_137;
}
V_168 = F_131 ( V_2 ) ;
if ( V_168 < 0 ) {
F_78 ( V_2 ) ;
V_2 = F_136 ( V_168 ) ;
}
} else {
V_2 = F_134 ( V_16 , V_29 ) ;
F_33 ( & V_39 ) ;
}
V_137:
F_147 ( V_16 ) ;
return V_2 ;
}
static int F_171 ( struct V_17 * V_17 , struct V_6 * V_63 )
{
struct V_1 * V_2 ;
int V_200 , V_168 ;
T_1 V_28 = V_17 -> V_201 ;
unsigned V_202 = V_63 -> V_132 ;
F_172 ( V_17 , V_63 ) ;
V_203:
V_168 = F_6 ( V_63 ) ;
if ( V_168 )
return - V_11 ;
V_2 = F_164 ( V_28 , V_63 ) ;
if ( ! V_2 )
V_2 = F_168 ( V_28 , V_17 , V_63 ) ;
if ( F_124 ( V_2 ) ) {
F_12 ( V_63 ) ;
V_168 = F_173 ( V_2 ) ;
if ( V_168 != - V_129 || F_112 ( V_43 ) )
return V_168 ;
F_174 () ;
goto V_203;
}
F_8 ( V_2 , V_63 ) ;
F_22 ( V_2 , V_175 ) ;
F_87 ( V_2 , L_32 , V_2 -> V_22 ) ;
if ( V_2 -> V_40 -> V_204 )
V_168 = V_2 -> V_40 -> V_204 ( V_2 , V_63 ) ;
else
V_168 = - V_170 ;
V_63 -> V_132 = V_202 ;
if ( V_168 ) {
F_87 ( V_2 , L_33 , V_168 ) ;
F_78 ( V_2 ) ;
F_158 ( V_17 , V_63 ) ;
if ( V_168 != - V_59 )
return V_168 ;
if ( F_112 ( V_43 ) )
return V_168 ;
F_174 () ;
if ( F_92 ( V_63 ) )
V_63 -> V_101 = & V_205 ;
goto V_203;
}
F_81 ( V_100 , & V_2 -> V_50 ) ;
F_73 ( & V_89 ) ;
F_61 ( & V_43 -> V_45 -> V_78 ) ;
V_200 = ( V_63 -> V_132 & V_206 ) ||
( F_175 ( F_166 ) && V_28 == F_28 ( V_196 , 0 ) ) ||
V_28 == F_28 ( V_193 , 1 ) ||
( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_163 ) ;
if ( ! V_200 &&
V_43 -> signal -> V_90 &&
! V_43 -> signal -> V_2 &&
V_2 -> V_79 == NULL ) {
if ( V_63 -> V_207 & V_208 )
F_54 ( V_2 ) ;
}
F_62 ( & V_43 -> V_45 -> V_78 ) ;
F_75 ( & V_89 ) ;
F_78 ( V_2 ) ;
return 0 ;
}
static unsigned int F_176 ( struct V_6 * V_63 , T_6 * V_64 )
{
struct V_1 * V_2 = F_5 ( V_63 ) ;
struct V_82 * V_83 ;
int V_54 = 0 ;
if ( F_17 ( V_2 , F_103 ( V_63 ) , L_34 ) )
return 0 ;
V_83 = F_105 ( V_2 ) ;
if ( ! V_83 )
return F_48 ( V_63 , V_64 ) ;
if ( V_83 -> V_40 -> V_209 )
V_54 = V_83 -> V_40 -> V_209 ( V_2 , V_63 , V_64 ) ;
F_70 ( V_83 ) ;
return V_54 ;
}
static int F_79 ( int V_75 , struct V_6 * V_63 , int V_76 )
{
struct V_1 * V_2 = F_5 ( V_63 ) ;
unsigned long V_50 ;
int V_168 = 0 ;
if ( F_17 ( V_2 , F_103 ( V_63 ) , L_35 ) )
goto V_137;
V_168 = F_177 ( V_75 , V_63 , V_76 , & V_2 -> V_210 ) ;
if ( V_168 <= 0 )
goto V_137;
if ( V_76 ) {
enum V_211 type ;
struct V_51 * V_51 ;
F_39 ( & V_2 -> V_55 , V_50 ) ;
if ( V_2 -> V_52 ) {
V_51 = V_2 -> V_52 ;
type = V_212 ;
} else {
V_51 = F_178 ( V_43 ) ;
type = V_213 ;
}
F_56 ( V_51 ) ;
F_40 ( & V_2 -> V_55 , V_50 ) ;
F_179 ( V_63 , V_51 , type , 0 ) ;
F_55 ( V_51 ) ;
V_168 = 0 ;
}
V_137:
return V_168 ;
}
static int F_180 ( int V_75 , struct V_6 * V_63 , int V_76 )
{
struct V_1 * V_2 = F_5 ( V_63 ) ;
int V_168 = - V_74 ;
F_77 ( V_2 ) ;
if ( ! F_92 ( V_63 ) )
V_168 = F_79 ( V_75 , V_63 , V_76 ) ;
F_78 ( V_2 ) ;
return V_168 ;
}
static int F_181 ( struct V_1 * V_2 , char T_3 * V_21 )
{
char V_144 , V_214 = 0 ;
struct V_82 * V_83 ;
if ( ( V_43 -> signal -> V_2 != V_2 ) && ! F_132 ( V_165 ) )
return - V_215 ;
if ( F_182 ( V_144 , V_21 ) )
return - V_139 ;
F_183 ( V_2 , V_144 ) ;
V_83 = F_105 ( V_2 ) ;
if ( ! V_83 )
return - V_57 ;
V_83 -> V_40 -> V_216 ( V_2 , & V_144 , & V_214 , 1 ) ;
F_70 ( V_83 ) ;
return 0 ;
}
static int F_184 ( struct V_1 * V_2 , struct V_217 T_3 * V_72 )
{
int V_218 ;
F_32 ( & V_2 -> V_219 ) ;
V_218 = F_185 ( V_72 , & V_2 -> V_217 , sizeof( * V_72 ) ) ;
F_33 ( & V_2 -> V_219 ) ;
return V_218 ? - V_139 : 0 ;
}
int F_186 ( struct V_1 * V_2 , struct V_217 * V_220 )
{
struct V_51 * V_52 ;
F_32 ( & V_2 -> V_219 ) ;
if ( ! memcmp ( V_220 , & V_2 -> V_217 , sizeof( * V_220 ) ) )
goto V_221;
V_52 = F_94 ( V_2 ) ;
if ( V_52 )
F_42 ( V_52 , V_222 , 1 ) ;
F_55 ( V_52 ) ;
V_2 -> V_217 = * V_220 ;
V_221:
F_33 ( & V_2 -> V_219 ) ;
return 0 ;
}
static int F_187 ( struct V_1 * V_2 , struct V_217 T_3 * V_72 )
{
struct V_217 V_223 ;
if ( F_111 ( & V_223 , V_72 , sizeof( * V_72 ) ) )
return - V_139 ;
if ( V_2 -> V_40 -> V_224 )
return V_2 -> V_40 -> V_224 ( V_2 , & V_223 ) ;
else
return F_186 ( V_2 , & V_223 ) ;
}
static int F_188 ( struct V_6 * V_6 )
{
if ( ! F_132 ( V_165 ) )
return - V_215 ;
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
return - V_166 ;
}
V_99 = F_116 ( V_6 ) ;
F_11 ( & V_98 ) ;
return 0 ;
}
static int F_189 ( struct V_6 * V_6 , int T_3 * V_21 )
{
int V_225 ;
if ( F_182 ( V_225 , V_21 ) )
return - V_139 ;
F_9 ( & V_6 -> V_226 ) ;
if ( V_225 )
V_6 -> V_132 |= V_195 ;
else
V_6 -> V_132 &= ~ V_195 ;
F_11 ( & V_6 -> V_226 ) ;
return 0 ;
}
static int F_190 ( struct V_1 * V_2 , struct V_6 * V_6 , int V_72 )
{
int V_54 = 0 ;
F_77 ( V_2 ) ;
F_73 ( & V_89 ) ;
if ( V_43 -> signal -> V_90 && ( F_57 ( V_43 ) == V_2 -> V_79 ) )
goto V_227;
if ( ! V_43 -> signal -> V_90 || V_43 -> signal -> V_2 ) {
V_54 = - V_215 ;
goto V_227;
}
if ( V_2 -> V_79 ) {
if ( V_72 == 1 && F_132 ( V_165 ) ) {
F_64 ( V_2 -> V_79 ) ;
} else {
V_54 = - V_215 ;
goto V_227;
}
}
if ( ( V_6 -> V_207 & V_208 ) == 0 && ! F_132 ( V_165 ) ) {
V_54 = - V_215 ;
goto V_227;
}
F_60 ( V_2 ) ;
V_227:
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
static struct V_51 * F_191 ( struct V_51 * V_52 )
{
struct V_77 * V_21 ;
struct V_51 * V_228 = NULL ;
V_21 = F_192 ( V_52 , V_212 ) ;
if ( V_21 == NULL )
V_21 = F_192 ( V_52 , V_213 ) ;
if ( V_21 != NULL )
V_228 = F_57 ( V_21 ) ;
return V_228 ;
}
static int F_193 ( struct V_1 * V_2 , struct V_1 * V_229 , T_7 T_3 * V_21 )
{
struct V_51 * V_51 ;
int V_54 ;
if ( V_2 == V_229 && V_43 -> signal -> V_2 != V_229 )
return - V_74 ;
V_51 = F_94 ( V_229 ) ;
V_54 = F_194 ( F_195 ( V_51 ) , V_21 ) ;
F_55 ( V_51 ) ;
return V_54 ;
}
static int F_196 ( struct V_1 * V_2 , struct V_1 * V_229 , T_7 T_3 * V_21 )
{
struct V_51 * V_52 ;
T_7 V_230 ;
int V_168 = F_45 ( V_229 ) ;
if ( V_168 == - V_57 )
return - V_74 ;
if ( V_168 )
return V_168 ;
if ( ! V_43 -> signal -> V_2 ||
( V_43 -> signal -> V_2 != V_229 ) ||
( V_229 -> V_79 != F_57 ( V_43 ) ) )
return - V_74 ;
if ( F_182 ( V_230 , V_21 ) )
return - V_139 ;
if ( V_230 < 0 )
return - V_231 ;
F_37 () ;
V_52 = F_197 ( V_230 ) ;
V_168 = - V_232 ;
if ( ! V_52 )
goto V_233;
V_168 = - V_215 ;
if ( F_191 ( V_52 ) != F_57 ( V_43 ) )
goto V_233;
V_168 = 0 ;
F_61 ( & V_2 -> V_55 ) ;
F_55 ( V_229 -> V_52 ) ;
V_229 -> V_52 = F_56 ( V_52 ) ;
F_62 ( & V_2 -> V_55 ) ;
V_233:
F_44 () ;
return V_168 ;
}
static int F_198 ( struct V_1 * V_2 , struct V_1 * V_229 , T_7 T_3 * V_21 )
{
if ( V_2 == V_229 && V_43 -> signal -> V_2 != V_229 )
return - V_74 ;
if ( ! V_229 -> V_79 )
return - V_74 ;
return F_194 ( F_195 ( V_229 -> V_79 ) , V_21 ) ;
}
static int F_199 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_234 ;
int V_54 ;
if ( F_182 ( V_234 , V_21 ) )
return - V_139 ;
V_54 = F_200 ( V_2 , V_234 ) ;
return V_54 ;
}
static int F_201 ( struct V_1 * V_2 , int T_3 * V_21 )
{
struct V_82 * V_83 ;
int V_54 ;
V_83 = F_105 ( V_2 ) ;
if ( ! V_83 )
return - V_57 ;
V_54 = F_194 ( V_83 -> V_40 -> V_33 , V_21 ) ;
F_70 ( V_83 ) ;
return V_54 ;
}
static int F_202 ( struct V_1 * V_2 , unsigned int V_235 )
{
int V_168 ;
if ( V_2 -> V_40 -> V_236 == NULL )
return 0 ;
if ( V_2 -> V_16 -> V_50 & V_237 )
V_168 = V_2 -> V_40 -> V_236 ( V_2 , V_235 ) ;
else {
if ( F_107 ( V_2 , 0 ) < 0 )
return - V_199 ;
V_168 = V_2 -> V_40 -> V_236 ( V_2 , - 1 ) ;
if ( V_168 )
goto V_137;
if ( ! F_112 ( V_43 ) )
F_203 ( V_235 ) ;
V_168 = V_2 -> V_40 -> V_236 ( V_2 , 0 ) ;
V_137:
F_106 ( V_2 ) ;
if ( F_112 ( V_43 ) )
V_168 = - V_199 ;
}
return V_168 ;
}
static int F_204 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_168 = - V_231 ;
if ( V_2 -> V_40 -> V_238 ) {
V_168 = V_2 -> V_40 -> V_238 ( V_2 ) ;
if ( V_168 >= 0 )
V_168 = F_194 ( V_168 , V_21 ) ;
}
return V_168 ;
}
static int F_205 ( struct V_1 * V_2 , unsigned int V_71 ,
unsigned T_3 * V_21 )
{
int V_168 ;
unsigned int V_239 , V_240 , V_241 ;
if ( V_2 -> V_40 -> V_242 == NULL )
return - V_231 ;
V_168 = F_182 ( V_241 , V_21 ) ;
if ( V_168 )
return V_168 ;
V_239 = V_240 = 0 ;
switch ( V_71 ) {
case V_243 :
V_239 = V_241 ;
break;
case V_244 :
V_240 = V_241 ;
break;
case V_245 :
V_239 = V_241 ;
V_240 = ~ V_241 ;
break;
}
V_239 &= V_246 | V_247 | V_248 | V_249 | V_250 ;
V_240 &= V_246 | V_247 | V_248 | V_249 | V_250 ;
return V_2 -> V_40 -> V_242 ( V_2 , V_239 , V_240 ) ;
}
static int F_206 ( struct V_1 * V_2 , void T_3 * V_72 )
{
int V_168 = - V_231 ;
struct V_251 V_252 ;
memset ( & V_252 , 0 , sizeof( V_252 ) ) ;
if ( V_2 -> V_40 -> V_253 )
V_168 = V_2 -> V_40 -> V_253 ( V_2 , & V_252 ) ;
if ( V_168 != 0 )
return V_168 ;
if ( F_185 ( V_72 , & V_252 , sizeof( V_252 ) ) )
return - V_139 ;
return 0 ;
}
static void F_207 ( struct V_254 T_3 * V_255 )
{
static F_208 ( V_256 ,
V_257 ,
V_258 ) ;
char V_259 [ V_260 ] ;
int V_50 ;
if ( F_182 ( V_50 , & V_255 -> V_50 ) )
return;
V_50 &= V_261 ;
if ( V_50 && F_209 ( & V_256 ) )
F_210 ( L_36 ,
V_175 , F_211 ( V_259 , V_43 ) , V_50 ) ;
}
static struct V_1 * F_212 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_163 )
V_2 = V_2 -> V_26 ;
return V_2 ;
}
long F_213 ( struct V_6 * V_6 , unsigned int V_71 , unsigned long V_72 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_1 * V_229 ;
void T_3 * V_21 = ( void T_3 * ) V_72 ;
int V_168 ;
struct V_82 * V_83 ;
if ( F_17 ( V_2 , F_103 ( V_6 ) , L_37 ) )
return - V_231 ;
V_229 = F_212 ( V_2 ) ;
switch ( V_71 ) {
case V_262 :
case V_263 :
case V_264 :
case V_265 :
case V_266 :
V_168 = F_45 ( V_2 ) ;
if ( V_168 )
return V_168 ;
if ( V_71 != V_264 ) {
F_214 ( V_2 , 0 ) ;
if ( F_112 ( V_43 ) )
return - V_199 ;
}
break;
}
switch ( V_71 ) {
case V_267 :
return F_181 ( V_2 , V_21 ) ;
case V_268 :
return F_184 ( V_229 , V_21 ) ;
case V_269 :
return F_187 ( V_229 , V_21 ) ;
case V_270 :
return V_229 != V_2 ? - V_231 : F_188 ( V_6 ) ;
case V_271 :
return F_189 ( V_6 , V_21 ) ;
case V_272 :
F_82 ( V_164 , & V_2 -> V_50 ) ;
return 0 ;
case V_273 :
F_81 ( V_164 , & V_2 -> V_50 ) ;
return 0 ;
case V_274 :
{
int V_275 = F_68 ( V_164 , & V_2 -> V_50 ) ;
return F_194 ( V_275 , ( int T_3 * ) V_21 ) ;
}
case V_276 :
if ( V_43 -> signal -> V_2 != V_2 )
return - V_74 ;
F_95 () ;
return 0 ;
case V_277 :
return F_190 ( V_229 , V_6 , V_72 ) ;
case V_278 :
return F_193 ( V_2 , V_229 , V_21 ) ;
case V_73 :
return F_196 ( V_2 , V_229 , V_21 ) ;
case V_279 :
return F_198 ( V_2 , V_229 , V_21 ) ;
case V_280 :
return F_201 ( V_2 , V_21 ) ;
case V_262 :
return F_199 ( V_2 , V_21 ) ;
case V_281 :
if ( ! F_132 ( V_165 ) )
return - V_215 ;
F_89 ( V_2 ) ;
return 0 ;
case V_282 :
{
unsigned int V_54 = F_215 ( F_216 ( V_229 ) ) ;
return F_194 ( V_54 , ( unsigned int T_3 * ) V_21 ) ;
}
case V_263 :
if ( V_2 -> V_40 -> V_236 )
return V_2 -> V_40 -> V_236 ( V_2 , - 1 ) ;
return 0 ;
case V_264 :
if ( V_2 -> V_40 -> V_236 )
return V_2 -> V_40 -> V_236 ( V_2 , 0 ) ;
return 0 ;
case V_265 :
if ( ! V_72 )
return F_202 ( V_2 , 250 ) ;
return 0 ;
case V_266 :
return F_202 ( V_2 , V_72 ? V_72 * 100 : 250 ) ;
case V_283 :
return F_204 ( V_2 , V_21 ) ;
case V_245 :
case V_244 :
case V_243 :
return F_205 ( V_2 , V_71 , V_21 ) ;
case V_284 :
V_168 = F_206 ( V_2 , V_21 ) ;
if ( V_168 != - V_231 )
return V_168 ;
break;
case V_285 :
switch ( V_72 ) {
case V_286 :
case V_287 :
F_217 ( V_2 , NULL ) ;
break;
}
break;
case V_288 :
F_207 ( V_21 ) ;
break;
}
if ( V_2 -> V_40 -> V_289 ) {
V_168 = V_2 -> V_40 -> V_289 ( V_2 , V_71 , V_72 ) ;
if ( V_168 != - V_290 )
return V_168 ;
}
V_83 = F_105 ( V_2 ) ;
if ( ! V_83 )
return F_49 ( V_6 , V_71 , V_72 ) ;
V_168 = - V_231 ;
if ( V_83 -> V_40 -> V_289 ) {
V_168 = V_83 -> V_40 -> V_289 ( V_2 , V_6 , V_71 , V_72 ) ;
if ( V_168 == - V_290 )
V_168 = - V_74 ;
}
F_70 ( V_83 ) ;
return V_168 ;
}
static long F_218 ( struct V_6 * V_6 , unsigned int V_71 ,
unsigned long V_72 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_82 * V_83 ;
int V_168 = - V_290 ;
if ( F_17 ( V_2 , F_103 ( V_6 ) , L_37 ) )
return - V_231 ;
if ( V_2 -> V_40 -> V_291 ) {
V_168 = V_2 -> V_40 -> V_291 ( V_2 , V_71 , V_72 ) ;
if ( V_168 != - V_290 )
return V_168 ;
}
V_83 = F_105 ( V_2 ) ;
if ( ! V_83 )
return F_50 ( V_6 , V_71 , V_72 ) ;
if ( V_83 -> V_40 -> V_291 )
V_168 = V_83 -> V_40 -> V_291 ( V_2 , V_6 , V_71 , V_72 ) ;
else
V_168 = F_219 ( V_2 , V_6 , V_71 , V_72 ) ;
F_70 ( V_83 ) ;
return V_168 ;
}
static int F_220 ( const void * V_292 , struct V_6 * V_6 , unsigned V_75 )
{
if ( F_221 ( V_6 -> V_101 -> V_125 != F_102 ) )
return 0 ;
return F_5 ( V_6 ) != V_292 ? 0 : V_75 + 1 ;
}
void F_222 ( struct V_1 * V_2 )
{
#ifdef F_223
F_86 ( V_2 ) ;
#else
struct V_77 * V_293 , * V_21 ;
struct V_51 * V_79 ;
int V_124 ;
if ( ! V_2 )
return;
V_79 = V_2 -> V_79 ;
F_224 ( V_2 ) ;
F_225 ( V_2 ) ;
F_73 ( & V_89 ) ;
F_65 (session, PIDTYPE_SID, p) {
F_226 ( V_2 , L_38 ,
F_227 ( V_21 ) , V_21 -> V_259 ) ;
F_228 ( V_294 , V_21 , 1 ) ;
} F_66 ( V_79 , V_81 , V_21 ) ;
F_229 (g, p) {
if ( V_21 -> signal -> V_2 == V_2 ) {
F_226 ( V_2 , L_39 ,
F_227 ( V_21 ) , V_21 -> V_259 ) ;
F_228 ( V_294 , V_21 , 1 ) ;
continue;
}
F_230 ( V_21 ) ;
V_124 = F_231 ( V_21 -> V_295 , 0 , F_220 , V_2 ) ;
if ( V_124 != 0 ) {
F_226 ( V_2 , L_40 ,
F_227 ( V_21 ) , V_21 -> V_259 , V_124 - 1 ) ;
F_232 ( V_294 , V_21 ) ;
}
F_233 ( V_21 ) ;
} F_234 ( V_293 , V_21 ) ;
F_75 ( & V_89 ) ;
#endif
}
static void F_235 ( struct V_110 * V_111 )
{
struct V_1 * V_2 =
F_85 ( V_111 , struct V_1 , V_178 ) ;
F_222 ( V_2 ) ;
}
void F_236 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_88 ( & V_2 -> V_178 ) ;
}
static int F_237 ( struct V_28 * V_3 , const void * V_296 )
{
const T_1 * V_297 = V_296 ;
return V_3 -> V_297 == * V_297 ;
}
static struct V_28 * F_238 ( struct V_1 * V_2 )
{
T_1 V_297 = F_216 ( V_2 ) ;
return F_239 ( V_298 , NULL , & V_297 , F_237 ) ;
}
struct V_1 * F_137 ( struct V_27 * V_16 , int V_151 )
{
struct V_1 * V_2 ;
V_2 = F_240 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_241 ( & V_2 -> V_181 ) ;
V_2 -> V_5 = V_19 ;
F_242 ( V_2 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_52 = NULL ;
F_243 ( & V_2 -> V_299 ) ;
F_243 ( & V_2 -> V_300 ) ;
F_244 ( & V_2 -> V_147 ) ;
F_243 ( & V_2 -> V_219 ) ;
F_245 ( & V_2 -> V_301 ) ;
F_246 ( & V_2 -> V_86 ) ;
F_246 ( & V_2 -> V_190 ) ;
F_150 ( & V_2 -> V_112 , F_84 ) ;
F_243 ( & V_2 -> V_127 ) ;
F_247 ( & V_2 -> V_55 ) ;
F_247 ( & V_2 -> V_118 ) ;
F_247 ( & V_2 -> V_12 ) ;
F_248 ( & V_2 -> V_14 ) ;
F_150 ( & V_2 -> V_178 , F_235 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_40 = V_16 -> V_40 ;
V_2 -> V_29 = V_151 ;
F_122 ( V_16 , V_151 , V_2 -> V_15 ) ;
V_2 -> V_3 = F_238 ( V_2 ) ;
return V_2 ;
}
int F_249 ( struct V_1 * V_2 , unsigned char V_144 )
{
if ( V_2 -> V_40 -> V_302 )
return V_2 -> V_40 -> V_302 ( V_2 , V_144 ) ;
return V_2 -> V_40 -> V_102 ( V_2 , & V_144 , 1 ) ;
}
static int F_250 ( struct V_27 * V_16 , T_1 V_3 ,
unsigned int V_29 , unsigned int V_22 )
{
int V_218 ;
V_16 -> V_303 [ V_29 ] = F_251 () ;
if ( ! V_16 -> V_303 [ V_29 ] )
return - V_11 ;
V_16 -> V_303 [ V_29 ] -> V_40 = & V_205 ;
V_16 -> V_303 [ V_29 ] -> V_169 = V_16 -> V_169 ;
V_218 = F_252 ( V_16 -> V_303 [ V_29 ] , V_3 , V_22 ) ;
if ( V_218 )
F_253 ( & V_16 -> V_303 [ V_29 ] -> V_304 ) ;
return V_218 ;
}
struct V_28 * F_254 ( struct V_27 * V_16 , unsigned V_29 ,
struct V_28 * V_28 )
{
return F_255 ( V_16 , V_29 , V_28 , NULL , NULL ) ;
}
static void F_256 ( struct V_28 * V_3 )
{
F_257 ( V_3 , L_41 ) ;
F_4 ( V_3 ) ;
}
struct V_28 * F_255 ( struct V_27 * V_16 ,
unsigned V_29 , struct V_28 * V_28 ,
void * V_305 ,
const struct V_306 * * V_307 )
{
char V_15 [ 64 ] ;
T_1 V_297 = F_28 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ;
struct V_28 * V_3 = NULL ;
int V_168 = - V_170 ;
bool V_308 = false ;
if ( V_29 >= V_16 -> V_33 ) {
F_258 ( L_42 ,
V_16 -> V_15 , V_29 ) ;
return F_136 ( - V_231 ) ;
}
if ( V_16 -> type == V_23 )
F_121 ( V_16 , V_29 , V_15 ) ;
else
F_122 ( V_16 , V_29 , V_15 ) ;
if ( ! ( V_16 -> V_50 & V_309 ) ) {
V_168 = F_250 ( V_16 , V_297 , V_29 , 1 ) ;
if ( V_168 )
goto error;
V_308 = true ;
}
V_3 = F_240 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 ) {
V_168 = - V_11 ;
goto error;
}
V_3 -> V_297 = V_297 ;
V_3 -> V_310 = V_298 ;
V_3 -> V_311 = V_28 ;
V_3 -> V_312 = F_256 ;
F_259 ( V_3 , L_18 , V_15 ) ;
V_3 -> V_313 = V_307 ;
F_260 ( V_3 , V_305 ) ;
V_168 = F_261 ( V_3 ) ;
if ( V_168 )
goto error;
return V_3 ;
error:
F_3 ( V_3 ) ;
if ( V_308 ) {
F_262 ( V_16 -> V_303 [ V_29 ] ) ;
V_16 -> V_303 [ V_29 ] = NULL ;
}
return F_136 ( V_168 ) ;
}
void F_263 ( struct V_27 * V_16 , unsigned V_29 )
{
F_264 ( V_298 ,
F_28 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ) ;
if ( ! ( V_16 -> V_50 & V_309 ) ) {
F_262 ( V_16 -> V_303 [ V_29 ] ) ;
V_16 -> V_303 [ V_29 ] = NULL ;
}
}
struct V_27 * F_265 ( unsigned int V_314 , struct V_179 * V_169 ,
unsigned long V_50 )
{
struct V_27 * V_16 ;
unsigned int V_303 = 1 ;
int V_218 ;
if ( ! V_314 || ( V_50 & V_150 && V_314 > 1 ) )
return F_136 ( - V_231 ) ;
V_16 = F_240 ( sizeof( struct V_27 ) , V_10 ) ;
if ( ! V_16 )
return F_136 ( - V_11 ) ;
F_241 ( & V_16 -> V_181 ) ;
V_16 -> V_5 = V_315 ;
V_16 -> V_33 = V_314 ;
V_16 -> V_169 = V_169 ;
V_16 -> V_50 = V_50 ;
if ( ! ( V_50 & V_183 ) ) {
V_16 -> V_153 = F_266 ( V_314 , sizeof( * V_16 -> V_153 ) ,
V_10 ) ;
V_16 -> V_157 = F_266 ( V_314 , sizeof( * V_16 -> V_157 ) ,
V_10 ) ;
if ( ! V_16 -> V_153 || ! V_16 -> V_157 ) {
V_218 = - V_11 ;
goto V_316;
}
}
if ( ! ( V_50 & V_309 ) ) {
V_16 -> V_174 = F_266 ( V_314 , sizeof( * V_16 -> V_174 ) ,
V_10 ) ;
if ( ! V_16 -> V_174 ) {
V_218 = - V_11 ;
goto V_316;
}
V_303 = V_314 ;
}
V_16 -> V_303 = F_266 ( V_303 , sizeof( * V_16 -> V_303 ) , V_10 ) ;
if ( ! V_16 -> V_303 ) {
V_218 = - V_11 ;
goto V_316;
}
return V_16 ;
V_316:
F_4 ( V_16 -> V_174 ) ;
F_4 ( V_16 -> V_153 ) ;
F_4 ( V_16 -> V_157 ) ;
F_4 ( V_16 -> V_303 ) ;
F_4 ( V_16 ) ;
return F_136 ( V_218 ) ;
}
static void F_267 ( struct V_181 * V_181 )
{
struct V_27 * V_16 = F_85 ( V_181 , struct V_27 , V_181 ) ;
int V_124 ;
struct V_154 * V_155 ;
if ( V_16 -> V_50 & V_317 ) {
for ( V_124 = 0 ; V_124 < V_16 -> V_33 ; V_124 ++ ) {
V_155 = V_16 -> V_157 [ V_124 ] ;
if ( V_155 ) {
V_16 -> V_157 [ V_124 ] = NULL ;
F_4 ( V_155 ) ;
}
if ( ! ( V_16 -> V_50 & V_318 ) )
F_263 ( V_16 , V_124 ) ;
}
F_268 ( V_16 ) ;
if ( V_16 -> V_50 & V_309 )
F_262 ( V_16 -> V_303 [ 0 ] ) ;
}
F_4 ( V_16 -> V_303 ) ;
F_4 ( V_16 -> V_174 ) ;
F_4 ( V_16 -> V_157 ) ;
F_4 ( V_16 -> V_153 ) ;
F_4 ( V_16 ) ;
}
void F_147 ( struct V_27 * V_16 )
{
F_151 ( & V_16 -> V_181 , F_267 ) ;
}
void F_269 ( struct V_27 * V_16 ,
const struct V_319 * V_320 )
{
V_16 -> V_40 = V_320 ;
}
void F_270 ( struct V_27 * V_321 )
{
F_147 ( V_321 ) ;
}
int F_271 ( struct V_27 * V_16 )
{
int error ;
int V_124 ;
T_1 V_3 ;
struct V_28 * V_321 ;
if ( ! V_16 -> V_31 ) {
error = F_272 ( & V_3 , V_16 -> V_32 ,
V_16 -> V_33 , V_16 -> V_15 ) ;
if ( ! error ) {
V_16 -> V_31 = F_273 ( V_3 ) ;
V_16 -> V_32 = F_274 ( V_3 ) ;
}
} else {
V_3 = F_28 ( V_16 -> V_31 , V_16 -> V_32 ) ;
error = F_275 ( V_3 , V_16 -> V_33 , V_16 -> V_15 ) ;
}
if ( error < 0 )
goto V_218;
if ( V_16 -> V_50 & V_309 ) {
error = F_250 ( V_16 , V_3 , 0 , V_16 -> V_33 ) ;
if ( error )
goto V_322;
}
F_32 ( & V_39 ) ;
F_10 ( & V_16 -> V_323 , & V_323 ) ;
F_33 ( & V_39 ) ;
if ( ! ( V_16 -> V_50 & V_318 ) ) {
for ( V_124 = 0 ; V_124 < V_16 -> V_33 ; V_124 ++ ) {
V_321 = F_254 ( V_16 , V_124 , NULL ) ;
if ( F_124 ( V_321 ) ) {
error = F_173 ( V_321 ) ;
goto V_324;
}
}
}
F_276 ( V_16 ) ;
V_16 -> V_50 |= V_317 ;
return 0 ;
V_324:
for ( V_124 -- ; V_124 >= 0 ; V_124 -- )
F_263 ( V_16 , V_124 ) ;
F_32 ( & V_39 ) ;
F_14 ( & V_16 -> V_323 ) ;
F_33 ( & V_39 ) ;
V_322:
F_277 ( V_3 , V_16 -> V_33 ) ;
V_218:
return error ;
}
int F_278 ( struct V_27 * V_16 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_277 ( F_28 ( V_16 -> V_31 , V_16 -> V_32 ) ,
V_16 -> V_33 ) ;
F_32 ( & V_39 ) ;
F_14 ( & V_16 -> V_323 ) ;
F_33 ( & V_39 ) ;
return 0 ;
}
T_1 F_216 ( struct V_1 * V_2 )
{
return F_28 ( V_2 -> V_16 -> V_31 , V_2 -> V_16 -> V_32 ) + V_2 -> V_29 ;
}
void F_279 ( struct V_325 * V_326 )
{
* V_326 = V_205 ;
}
void T_8 F_280 ( void )
{
T_9 * V_327 ;
F_281 () ;
V_327 = V_328 ;
while ( V_327 < V_329 ) {
(* V_327)() ;
V_327 ++ ;
}
}
static char * F_282 ( struct V_28 * V_3 , T_10 * V_330 )
{
if ( ! V_330 )
return NULL ;
if ( V_3 -> V_297 == F_28 ( V_193 , 0 ) ||
V_3 -> V_297 == F_28 ( V_193 , 2 ) )
* V_330 = 0666 ;
return NULL ;
}
static int T_8 F_283 ( void )
{
V_298 = F_284 ( V_331 , L_17 ) ;
if ( F_124 ( V_298 ) )
return F_173 ( V_298 ) ;
V_298 -> V_332 = F_282 ;
return 0 ;
}
static T_2 F_285 ( struct V_28 * V_3 ,
struct V_333 * V_334 , char * V_61 )
{
struct V_335 * V_336 [ 16 ] ;
int V_124 = 0 ;
struct V_335 * V_337 ;
T_2 V_22 = 0 ;
F_286 () ;
F_287 (c) {
if ( ! V_337 -> V_28 )
continue;
if ( ! V_337 -> V_102 )
continue;
if ( ( V_337 -> V_50 & V_338 ) == 0 )
continue;
V_336 [ V_124 ++ ] = V_337 ;
if ( V_124 >= F_288 ( V_336 ) )
break;
}
while ( V_124 -- ) {
int V_29 = V_336 [ V_124 ] -> V_29 ;
struct V_27 * V_339 = V_336 [ V_124 ] -> V_28 ( V_336 [ V_124 ] , & V_29 ) ;
if ( V_339 && ( V_336 [ V_124 ] -> V_29 > 0 || V_339 -> V_31 != V_196 ) )
V_22 += F_122 ( V_339 , V_29 , V_61 + V_22 ) ;
else
V_22 += sprintf ( V_61 + V_22 , L_19 ,
V_336 [ V_124 ] -> V_15 , V_336 [ V_124 ] -> V_29 ) ;
V_22 += sprintf ( V_61 + V_22 , L_43 , V_124 ? ' ' : '\n' ) ;
}
F_289 () ;
return V_22 ;
}
void F_290 ( void )
{
if ( V_340 )
F_291 ( & V_340 -> V_304 , NULL , L_44 ) ;
}
int T_8 F_292 ( void )
{
F_293 ( & V_341 , & V_205 ) ;
if ( F_252 ( & V_341 , F_28 ( V_193 , 0 ) , 1 ) ||
F_275 ( F_28 ( V_193 , 0 ) , 1 , L_45 ) < 0 )
F_294 ( L_46 ) ;
F_295 ( V_298 , NULL , F_28 ( V_193 , 0 ) , NULL , L_17 ) ;
F_293 ( & V_342 , & V_343 ) ;
if ( F_252 ( & V_342 , F_28 ( V_193 , 1 ) , 1 ) ||
F_275 ( F_28 ( V_193 , 1 ) , 1 , L_47 ) < 0 )
F_294 ( L_48 ) ;
V_340 = F_296 ( V_298 , NULL ,
F_28 ( V_193 , 1 ) , NULL ,
V_344 , L_49 ) ;
if ( F_124 ( V_340 ) )
V_340 = NULL ;
#ifdef F_166
F_297 ( & V_343 ) ;
#endif
return 0 ;
}
