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
const char * F_14 ( const struct V_1 * V_2 )
{
if ( ! V_2 )
return L_1 ;
return V_2 -> V_15 ;
}
const char * F_15 ( const struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_16 )
return L_2 ;
return V_2 -> V_16 -> V_15 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_17 * V_17 ,
const char * V_18 )
{
#ifdef F_17
if ( ! V_2 ) {
F_18 ( L_3 ,
F_19 ( V_17 ) , F_20 ( V_17 ) , V_18 ) ;
return 1 ;
}
if ( V_2 -> V_5 != V_19 ) {
F_18 ( L_4 ,
F_19 ( V_17 ) , F_20 ( V_17 ) , V_18 ) ;
return 1 ;
}
#endif
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , const char * V_18 )
{
#ifdef F_22
struct V_20 * V_21 ;
int V_22 = 0 ;
F_8 ( & V_12 ) ;
F_23 (p, &tty->tty_files) {
V_22 ++ ;
}
F_10 ( & V_12 ) ;
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_25 &&
V_2 -> V_26 && V_2 -> V_26 -> V_22 )
V_22 ++ ;
if ( V_2 -> V_22 != V_22 ) {
F_24 ( V_2 , L_5 ,
V_18 , V_2 -> V_22 , V_22 ) ;
return V_22 ;
}
#endif
return 0 ;
}
static struct V_27 * F_25 ( T_1 V_28 , int * V_29 )
{
struct V_27 * V_21 ;
F_26 (p, &tty_drivers, tty_drivers) {
T_1 V_30 = F_27 ( V_21 -> V_31 , V_21 -> V_32 ) ;
if ( V_28 < V_30 || V_28 >= V_30 + V_21 -> V_33 )
continue;
* V_29 = V_28 - V_30 ;
return F_28 ( V_21 ) ;
}
return NULL ;
}
struct V_27 * F_29 ( char * V_15 , int * line )
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
V_35 = F_30 ( V_37 , & V_37 , 10 ) ;
F_31 ( & V_39 ) ;
F_26 (p, &tty_drivers, tty_drivers) {
if ( strncmp ( V_15 , V_21 -> V_15 , V_36 ) != 0 )
continue;
V_38 = V_37 ;
if ( * V_38 == ',' )
V_38 ++ ;
if ( * V_38 == '\0' )
V_38 = NULL ;
if ( V_35 >= 0 && V_35 < V_21 -> V_33 && V_21 -> V_40 &&
V_21 -> V_40 -> V_41 && ! V_21 -> V_40 -> V_41 ( V_21 , V_35 , V_38 ) ) {
V_34 = F_28 ( V_21 ) ;
* line = V_35 ;
break;
}
}
F_32 ( & V_39 ) ;
return V_34 ;
}
int F_33 ( struct V_1 * V_2 , int V_42 )
{
unsigned long V_43 ;
struct V_44 * V_45 , * V_46 ;
int V_47 = 0 ;
if ( V_48 -> signal -> V_2 != V_2 )
return 0 ;
F_34 () ;
V_45 = F_35 ( V_48 ) ;
F_36 ( & V_2 -> V_49 , V_43 ) ;
V_46 = V_2 -> V_45 ;
F_37 ( & V_2 -> V_49 , V_43 ) ;
if ( V_46 && V_45 != V_2 -> V_45 ) {
if ( F_38 ( V_42 ) ) {
if ( V_42 == V_50 )
V_47 = - V_51 ;
} else if ( F_39 () )
V_47 = - V_51 ;
else {
F_40 ( V_45 , V_42 , 1 ) ;
F_41 ( V_52 ) ;
V_47 = - V_53 ;
}
}
F_42 () ;
if ( ! V_46 )
F_24 ( V_2 , L_6 , V_42 ) ;
return V_47 ;
}
int F_43 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , V_54 ) ;
}
static T_2 F_44 ( struct V_6 * V_6 , char T_3 * V_55 ,
T_4 V_22 , T_5 * V_56 )
{
return 0 ;
}
static T_2 F_45 ( struct V_6 * V_6 , const char T_3 * V_55 ,
T_4 V_22 , T_5 * V_56 )
{
return - V_51 ;
}
static unsigned int F_46 ( struct V_6 * V_57 , T_6 * V_58 )
{
return V_59 | V_60 | V_61 | V_62 | V_63 | V_64 ;
}
static long F_47 ( struct V_6 * V_6 , unsigned int V_65 ,
unsigned long V_66 )
{
return V_65 == V_67 ? - V_68 : - V_51 ;
}
static long F_48 ( struct V_6 * V_6 ,
unsigned int V_65 , unsigned long V_66 )
{
return V_65 == V_67 ? - V_68 : - V_51 ;
}
void F_49 ( struct V_69 * V_21 )
{
unsigned long V_43 ;
struct V_1 * V_2 ;
F_36 ( & V_21 -> V_70 -> V_71 , V_43 ) ;
V_2 = V_21 -> signal -> V_2 ;
V_21 -> signal -> V_2 = NULL ;
F_37 ( & V_21 -> V_70 -> V_71 , V_43 ) ;
F_50 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
F_36 ( & V_2 -> V_49 , V_43 ) ;
F_52 ( V_2 -> V_72 ) ;
F_52 ( V_2 -> V_45 ) ;
V_2 -> V_45 = F_53 ( F_35 ( V_48 ) ) ;
F_37 ( & V_2 -> V_49 , V_43 ) ;
V_2 -> V_72 = F_53 ( F_54 ( V_48 ) ) ;
if ( V_48 -> signal -> V_2 ) {
F_55 ( V_2 , L_7 ,
V_48 -> signal -> V_2 -> V_15 ) ;
F_50 ( V_48 -> signal -> V_2 ) ;
}
F_52 ( V_48 -> signal -> V_73 ) ;
V_48 -> signal -> V_2 = F_56 ( V_2 ) ;
V_48 -> signal -> V_73 = NULL ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_58 ( & V_48 -> V_70 -> V_71 ) ;
F_51 ( V_2 ) ;
F_59 ( & V_48 -> V_70 -> V_71 ) ;
}
struct V_1 * F_60 ( void )
{
struct V_1 * V_2 ;
unsigned long V_43 ;
F_36 ( & V_48 -> V_70 -> V_71 , V_43 ) ;
V_2 = F_56 ( V_48 -> signal -> V_2 ) ;
F_37 ( & V_48 -> V_70 -> V_71 , V_43 ) ;
return V_2 ;
}
static void F_61 ( struct V_44 * V_72 )
{
struct V_69 * V_21 ;
F_62 (session, PIDTYPE_SID, p) {
F_49 ( V_21 ) ;
} F_63 ( V_72 , V_74 , V_21 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
if ( F_65 ( V_77 , & V_2 -> V_43 ) ) {
V_76 = F_66 ( V_2 ) ;
if ( V_76 ) {
if ( V_76 -> V_40 -> V_78 )
V_76 -> V_40 -> V_78 ( V_2 ) ;
F_67 ( V_76 ) ;
}
}
F_68 ( & V_2 -> V_79 , V_60 ) ;
}
static int F_69 ( struct V_1 * V_2 , int V_80 )
{
struct V_69 * V_21 ;
int V_81 = 0 ;
struct V_44 * V_46 = NULL ;
F_70 ( & V_82 ) ;
if ( V_2 -> V_72 ) {
F_62 (tty->session, PIDTYPE_SID, p) {
F_58 ( & V_21 -> V_70 -> V_71 ) ;
if ( V_21 -> signal -> V_2 == V_2 ) {
V_21 -> signal -> V_2 = NULL ;
V_81 ++ ;
}
if ( ! V_21 -> signal -> V_83 ) {
F_59 ( & V_21 -> V_70 -> V_71 ) ;
continue;
}
F_71 ( V_84 , V_85 , V_21 ) ;
F_71 ( V_86 , V_85 , V_21 ) ;
F_52 ( V_21 -> signal -> V_73 ) ;
F_8 ( & V_2 -> V_49 ) ;
V_46 = F_53 ( V_2 -> V_45 ) ;
if ( V_2 -> V_45 )
V_21 -> signal -> V_73 = F_53 ( V_2 -> V_45 ) ;
F_10 ( & V_2 -> V_49 ) ;
F_59 ( & V_21 -> V_70 -> V_71 ) ;
} F_63 ( V_2 -> V_72 , V_74 , V_21 ) ;
}
F_72 ( & V_82 ) ;
if ( V_46 ) {
if ( V_80 )
F_40 ( V_46 , V_84 , V_80 ) ;
F_52 ( V_46 ) ;
}
return V_81 ;
}
static void F_73 ( struct V_1 * V_2 , int V_80 )
{
struct V_6 * V_87 = NULL ;
struct V_6 * V_57 , * V_88 = NULL ;
struct V_7 * V_9 ;
int V_89 = 0 , V_90 ;
int V_81 ;
if ( ! V_2 )
return;
F_8 ( & V_91 ) ;
if ( V_92 && F_4 ( V_92 ) == V_2 ) {
V_88 = V_92 ;
V_92 = NULL ;
}
F_10 ( & V_91 ) ;
F_74 ( V_2 ) ;
if ( F_65 ( V_93 , & V_2 -> V_43 ) ) {
F_75 ( V_2 ) ;
return;
}
F_21 ( V_2 , L_8 ) ;
F_8 ( & V_12 ) ;
F_26 (priv, &tty->tty_files, list) {
V_57 = V_9 -> V_6 ;
if ( V_57 -> V_94 -> V_95 == V_96 )
V_87 = V_57 ;
if ( V_57 -> V_94 -> V_95 != V_97 )
continue;
V_89 ++ ;
F_76 ( - 1 , V_57 , 0 ) ;
V_57 -> V_94 = & V_98 ;
}
F_10 ( & V_12 ) ;
V_81 = F_69 ( V_2 , V_80 ) ;
while ( V_81 -- )
F_50 ( V_2 ) ;
F_77 ( V_2 ) ;
F_58 ( & V_2 -> V_49 ) ;
F_78 ( V_99 , & V_2 -> V_43 ) ;
F_78 ( V_77 , & V_2 -> V_43 ) ;
F_52 ( V_2 -> V_72 ) ;
F_52 ( V_2 -> V_45 ) ;
V_2 -> V_72 = NULL ;
V_2 -> V_45 = NULL ;
V_2 -> V_100 = 0 ;
F_59 ( & V_2 -> V_49 ) ;
if ( V_87 ) {
if ( V_2 -> V_40 -> V_101 )
for ( V_90 = 0 ; V_90 < V_89 ; V_90 ++ )
V_2 -> V_40 -> V_101 ( V_2 , V_87 ) ;
} else if ( V_2 -> V_40 -> V_102 )
V_2 -> V_40 -> V_102 ( V_2 ) ;
F_79 ( V_93 , & V_2 -> V_43 ) ;
F_75 ( V_2 ) ;
if ( V_88 )
F_80 ( V_88 ) ;
}
static void F_81 ( struct V_103 * V_104 )
{
struct V_1 * V_2 =
F_82 ( V_104 , struct V_1 , V_105 ) ;
F_73 ( V_2 , 0 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_84 ( V_2 , L_9 ) ;
F_85 ( & V_2 -> V_105 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
F_84 ( V_2 , L_10 ) ;
F_73 ( V_2 , 0 ) ;
}
void F_87 ( void )
{
struct V_1 * V_2 ;
V_2 = F_60 () ;
if ( V_2 ) {
F_86 ( V_2 ) ;
F_50 ( V_2 ) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
F_84 ( V_2 , L_11 ) ;
F_73 ( V_2 , 1 ) ;
}
int F_89 ( struct V_6 * V_57 )
{
return ( V_57 -> V_94 == & V_98 ) ;
}
void F_90 ( int V_106 )
{
struct V_1 * V_2 ;
if ( ! V_48 -> signal -> V_83 )
return;
V_2 = F_60 () ;
if ( V_2 ) {
if ( V_106 && V_2 -> V_16 -> type != V_23 ) {
F_88 ( V_2 ) ;
} else {
struct V_44 * V_46 = F_91 ( V_2 ) ;
if ( V_46 ) {
F_40 ( V_46 , V_84 , V_106 ) ;
if ( ! V_106 )
F_40 ( V_46 , V_86 , V_106 ) ;
F_52 ( V_46 ) ;
}
}
F_50 ( V_2 ) ;
} else if ( V_106 ) {
struct V_44 * V_107 ;
F_58 ( & V_48 -> V_70 -> V_71 ) ;
V_107 = V_48 -> signal -> V_73 ;
V_48 -> signal -> V_73 = NULL ;
F_59 ( & V_48 -> V_70 -> V_71 ) ;
if ( V_107 ) {
F_40 ( V_107 , V_84 , V_106 ) ;
F_40 ( V_107 , V_86 , V_106 ) ;
F_52 ( V_107 ) ;
}
return;
}
F_58 ( & V_48 -> V_70 -> V_71 ) ;
F_52 ( V_48 -> signal -> V_73 ) ;
V_48 -> signal -> V_73 = NULL ;
V_2 = F_56 ( V_48 -> signal -> V_2 ) ;
if ( V_2 ) {
unsigned long V_43 ;
F_36 ( & V_2 -> V_49 , V_43 ) ;
F_52 ( V_2 -> V_72 ) ;
F_52 ( V_2 -> V_45 ) ;
V_2 -> V_72 = NULL ;
V_2 -> V_45 = NULL ;
F_37 ( & V_2 -> V_49 , V_43 ) ;
F_50 ( V_2 ) ;
} else
F_84 ( V_2 , L_12 ) ;
F_59 ( & V_48 -> V_70 -> V_71 ) ;
F_70 ( & V_82 ) ;
F_61 ( F_54 ( V_48 ) ) ;
F_72 ( & V_82 ) ;
}
void F_92 ( void )
{
struct V_69 * V_108 = V_48 ;
F_90 ( 0 ) ;
F_49 ( V_108 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
if ( V_2 -> V_109 )
return;
V_2 -> V_109 = 1 ;
if ( V_2 -> V_40 -> V_110 )
V_2 -> V_40 -> V_110 ( V_2 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
F_36 ( & V_2 -> V_111 , V_43 ) ;
F_93 ( V_2 ) ;
F_37 ( & V_2 -> V_111 , V_43 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_109 || V_2 -> V_112 )
return;
V_2 -> V_109 = 0 ;
if ( V_2 -> V_40 -> V_113 )
V_2 -> V_40 -> V_113 ( V_2 ) ;
F_64 ( V_2 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
F_36 ( & V_2 -> V_111 , V_43 ) ;
F_95 ( V_2 ) ;
F_37 ( & V_2 -> V_111 , V_43 ) ;
}
static void F_97 ( struct V_114 * time )
{
unsigned long V_115 = F_98 () ;
if ( ( V_115 ^ time -> V_116 ) & ~ 7 )
time -> V_116 = V_115 ;
}
static T_2 F_99 ( struct V_6 * V_6 , char T_3 * V_55 , T_4 V_22 ,
T_5 * V_56 )
{
int V_117 ;
struct V_17 * V_17 = F_100 ( V_6 ) ;
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_75 * V_76 ;
if ( F_16 ( V_2 , V_17 , L_13 ) )
return - V_51 ;
if ( ! V_2 || ( F_65 ( V_118 , & V_2 -> V_43 ) ) )
return - V_51 ;
V_76 = F_101 ( V_2 ) ;
if ( V_76 -> V_40 -> V_119 )
V_117 = V_76 -> V_40 -> V_119 ( V_2 , V_6 , V_55 , V_22 ) ;
else
V_117 = - V_51 ;
F_67 ( V_76 ) ;
if ( V_117 > 0 )
F_97 ( & V_17 -> V_120 ) ;
return V_117 ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_32 ( & V_2 -> V_121 ) ;
F_68 ( & V_2 -> V_79 , V_60 ) ;
}
static int F_103 ( struct V_1 * V_2 , int V_122 )
{
if ( ! F_104 ( & V_2 -> V_121 ) ) {
if ( V_122 )
return - V_123 ;
if ( F_105 ( & V_2 -> V_121 ) )
return - V_53 ;
}
return 0 ;
}
static inline T_2 F_106 (
T_2 (* V_95)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_55 ,
T_4 V_22 )
{
T_2 V_47 , V_124 = 0 ;
unsigned int V_125 ;
V_47 = F_103 ( V_2 , V_6 -> V_126 & V_127 ) ;
if ( V_47 < 0 )
return V_47 ;
V_125 = 2048 ;
if ( F_65 ( V_128 , & V_2 -> V_43 ) )
V_125 = 65536 ;
if ( V_22 < V_125 )
V_125 = V_22 ;
if ( V_2 -> V_129 < V_125 ) {
unsigned char * V_130 ;
if ( V_125 < 1024 )
V_125 = 1024 ;
V_130 = F_6 ( V_125 , V_10 ) ;
if ( ! V_130 ) {
V_47 = - V_11 ;
goto V_131;
}
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_129 = V_125 ;
V_2 -> V_4 = V_130 ;
}
for (; ; ) {
T_4 V_132 = V_22 ;
if ( V_132 > V_125 )
V_132 = V_125 ;
V_47 = - V_133 ;
if ( F_107 ( V_2 -> V_4 , V_55 , V_132 ) )
break;
V_47 = V_95 ( V_2 , V_6 , V_2 -> V_4 , V_132 ) ;
if ( V_47 <= 0 )
break;
V_124 += V_47 ;
V_55 += V_47 ;
V_22 -= V_47 ;
if ( ! V_22 )
break;
V_47 = - V_53 ;
if ( F_108 ( V_48 ) )
break;
F_109 () ;
}
if ( V_124 ) {
F_97 ( & F_100 ( V_6 ) -> V_134 ) ;
V_47 = V_124 ;
}
V_131:
F_102 ( V_2 ) ;
return V_47 ;
}
void F_110 ( struct V_1 * V_2 , char * V_135 )
{
if ( V_2 ) {
F_31 ( & V_2 -> V_121 ) ;
F_74 ( V_2 ) ;
if ( V_2 -> V_40 -> V_95 && V_2 -> V_22 > 0 )
V_2 -> V_40 -> V_95 ( V_2 , V_135 , strlen ( V_135 ) ) ;
F_75 ( V_2 ) ;
F_102 ( V_2 ) ;
}
return;
}
static T_2 V_97 ( struct V_6 * V_6 , const char T_3 * V_55 ,
T_4 V_22 , T_5 * V_56 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_75 * V_76 ;
T_2 V_47 ;
if ( F_16 ( V_2 , F_100 ( V_6 ) , L_14 ) )
return - V_51 ;
if ( ! V_2 || ! V_2 -> V_40 -> V_95 ||
( F_65 ( V_118 , & V_2 -> V_43 ) ) )
return - V_51 ;
if ( V_2 -> V_40 -> V_136 == NULL )
F_111 ( V_2 , L_15 ) ;
V_76 = F_101 ( V_2 ) ;
if ( ! V_76 -> V_40 -> V_95 )
V_47 = - V_51 ;
else
V_47 = F_106 ( V_76 -> V_40 -> V_95 , V_2 , V_6 , V_55 , V_22 ) ;
F_67 ( V_76 ) ;
return V_47 ;
}
T_2 V_96 ( struct V_6 * V_6 , const char T_3 * V_55 ,
T_4 V_22 , T_5 * V_56 )
{
struct V_6 * V_21 = NULL ;
F_8 ( & V_91 ) ;
if ( V_92 )
V_21 = F_112 ( V_92 ) ;
F_10 ( & V_91 ) ;
if ( V_21 ) {
T_2 V_34 ;
V_34 = F_113 ( V_21 , V_55 , V_22 , & V_21 -> V_137 ) ;
F_80 ( V_21 ) ;
return V_34 ;
}
return V_97 ( V_6 , V_55 , V_22 , V_56 ) ;
}
int F_114 ( struct V_1 * V_2 , char V_138 )
{
int V_139 = V_2 -> V_109 ;
if ( V_2 -> V_40 -> V_140 ) {
F_115 ( & V_2 -> V_141 ) ;
V_2 -> V_40 -> V_140 ( V_2 , V_138 ) ;
F_116 ( & V_2 -> V_141 ) ;
return 0 ;
}
if ( F_103 ( V_2 , 0 ) < 0 )
return - V_53 ;
F_115 ( & V_2 -> V_141 ) ;
if ( V_139 )
F_96 ( V_2 ) ;
V_2 -> V_40 -> V_95 ( V_2 , & V_138 , 1 ) ;
if ( V_139 )
F_94 ( V_2 ) ;
F_116 ( & V_2 -> V_141 ) ;
F_102 ( V_2 ) ;
return 0 ;
}
static void F_117 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
int V_117 = V_29 + V_16 -> V_142 ;
sprintf ( V_21 , L_16 ,
V_16 -> V_24 == V_25 ? L_17 : V_16 -> V_15 ,
V_143 [ V_117 >> 4 & 0xf ] , V_117 & 0xf ) ;
}
static T_2 F_118 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
if ( V_16 -> V_43 & V_144 )
return sprintf ( V_21 , L_18 , V_16 -> V_15 ) ;
else
return sprintf ( V_21 , L_19 , V_16 -> V_15 ,
V_29 + V_16 -> V_142 ) ;
}
static struct V_1 * F_119 ( struct V_27 * V_16 ,
struct V_17 * V_17 , int V_145 )
{
struct V_1 * V_2 ;
if ( V_16 -> V_40 -> V_146 )
V_2 = V_16 -> V_40 -> V_146 ( V_16 , V_17 , V_145 ) ;
else
V_2 = V_16 -> V_147 [ V_145 ] ;
if ( ! F_120 ( V_2 ) )
F_56 ( V_2 ) ;
return V_2 ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_148 * V_149 ;
int V_145 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_43 & V_150 )
V_2 -> V_151 = V_2 -> V_16 -> V_152 ;
else {
V_149 = V_2 -> V_16 -> V_151 [ V_145 ] ;
if ( V_149 != NULL )
V_2 -> V_151 = * V_149 ;
else
V_2 -> V_151 = V_2 -> V_16 -> V_152 ;
}
V_2 -> V_151 . V_153 = F_122 ( & V_2 -> V_151 ) ;
V_2 -> V_151 . V_154 = F_123 ( & V_2 -> V_151 ) ;
return 0 ;
}
int F_124 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
int V_47 = F_121 ( V_2 ) ;
if ( V_47 )
return V_47 ;
F_28 ( V_16 ) ;
V_2 -> V_22 ++ ;
V_16 -> V_147 [ V_2 -> V_29 ] = V_2 ;
return 0 ;
}
static int F_125 ( struct V_27 * V_16 ,
struct V_1 * V_2 )
{
return V_16 -> V_40 -> V_155 ? V_16 -> V_40 -> V_155 ( V_16 , V_2 ) :
F_124 ( V_16 , V_2 ) ;
}
void F_126 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
if ( V_16 -> V_40 -> remove )
V_16 -> V_40 -> remove ( V_16 , V_2 ) ;
else
V_16 -> V_147 [ V_2 -> V_29 ] = NULL ;
}
static int F_127 ( struct V_1 * V_2 )
{
struct V_27 * V_16 = V_2 -> V_16 ;
if ( V_16 -> type == V_23 &&
V_16 -> V_24 == V_156 )
return - V_51 ;
if ( ! V_2 -> V_22 )
return - V_123 ;
if ( F_65 ( V_157 , & V_2 -> V_43 ) && ! F_128 ( V_158 ) )
return - V_159 ;
V_2 -> V_22 ++ ;
F_129 ( ! V_2 -> V_160 ) ;
return 0 ;
}
struct V_1 * F_130 ( struct V_27 * V_16 , int V_145 )
{
struct V_1 * V_2 ;
int V_161 ;
if ( ! F_131 ( V_16 -> V_162 ) )
return F_132 ( - V_163 ) ;
V_2 = F_133 ( V_16 , V_145 ) ;
if ( ! V_2 ) {
V_161 = - V_11 ;
goto V_164;
}
F_74 ( V_2 ) ;
V_161 = F_125 ( V_16 , V_2 ) ;
if ( V_161 < 0 )
goto V_165;
if ( ! V_2 -> V_166 )
V_2 -> V_166 = V_16 -> V_167 [ V_145 ] ;
F_134 ( ! V_2 -> V_166 ,
L_20 ,
V_168 , V_2 -> V_16 -> V_15 ) ;
V_2 -> V_166 -> V_169 = V_2 ;
V_161 = F_135 ( V_2 , V_2 -> V_26 ) ;
if ( V_161 )
goto V_170;
return V_2 ;
V_165:
F_75 ( V_2 ) ;
F_136 ( V_2 ) ;
F_1 ( V_2 ) ;
V_164:
F_137 ( V_16 -> V_162 ) ;
return F_132 ( V_161 ) ;
V_170:
F_75 ( V_2 ) ;
F_138 ( V_2 , L_21 ,
V_161 , V_145 ) ;
F_139 ( V_2 , V_145 ) ;
return F_132 ( V_161 ) ;
}
void F_140 ( struct V_1 * V_2 )
{
struct V_148 * V_149 ;
int V_145 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_43 & V_150 )
return;
V_149 = V_2 -> V_16 -> V_151 [ V_145 ] ;
if ( V_149 == NULL ) {
V_149 = F_6 ( sizeof( struct V_148 ) , V_10 ) ;
if ( V_149 == NULL )
return;
V_2 -> V_16 -> V_151 [ V_145 ] = V_149 ;
}
* V_149 = V_2 -> V_151 ;
}
static void F_141 ( struct V_1 * V_2 )
{
F_142 ( & V_2 -> V_171 ) ;
F_142 ( & V_2 -> V_105 ) ;
if ( V_2 -> V_26 ) {
F_142 ( & V_2 -> V_26 -> V_171 ) ;
F_142 ( & V_2 -> V_26 -> V_105 ) ;
}
}
static void F_143 ( struct V_103 * V_104 )
{
struct V_1 * V_2 =
F_82 ( V_104 , struct V_1 , V_105 ) ;
struct V_27 * V_16 = V_2 -> V_16 ;
struct V_172 * V_162 = V_16 -> V_162 ;
if ( V_2 -> V_40 -> V_173 )
V_2 -> V_40 -> V_173 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_144 ( V_16 ) ;
F_137 ( V_162 ) ;
F_8 ( & V_12 ) ;
F_145 ( & V_2 -> V_14 ) ;
F_10 ( & V_12 ) ;
F_52 ( V_2 -> V_45 ) ;
F_52 ( V_2 -> V_72 ) ;
F_1 ( V_2 ) ;
}
static void F_146 ( struct V_174 * V_174 )
{
struct V_1 * V_2 = F_82 ( V_174 , struct V_1 , V_174 ) ;
F_147 ( & V_2 -> V_105 , F_143 ) ;
F_85 ( & V_2 -> V_105 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
if ( V_2 )
F_148 ( & V_2 -> V_174 , F_146 ) ;
}
static void F_139 ( struct V_1 * V_2 , int V_145 )
{
F_129 ( V_2 -> V_29 != V_145 ) ;
F_129 ( ! F_149 ( & V_39 ) ) ;
if ( V_2 -> V_40 -> V_175 )
V_2 -> V_40 -> V_175 ( V_2 ) ;
F_140 ( V_2 ) ;
F_126 ( V_2 -> V_16 , V_2 ) ;
V_2 -> V_166 -> V_169 = NULL ;
if ( V_2 -> V_26 )
V_2 -> V_26 -> V_166 -> V_169 = NULL ;
F_150 ( V_2 -> V_166 ) ;
F_50 ( V_2 -> V_26 ) ;
F_50 ( V_2 ) ;
}
static int F_151 ( struct V_1 * V_2 , int V_145 )
{
#ifdef F_17
if ( V_145 < 0 || V_145 >= V_2 -> V_16 -> V_33 ) {
F_55 ( V_2 , L_22 , V_145 ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_43 & V_176 )
return 0 ;
if ( V_2 != V_2 -> V_16 -> V_147 [ V_145 ] ) {
F_55 ( V_2 , L_23 ,
V_145 , V_2 -> V_16 -> V_147 [ V_145 ] ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_177 ) {
struct V_1 * V_178 = V_2 -> V_26 ;
if ( V_178 != V_2 -> V_16 -> V_177 -> V_147 [ V_145 ] ) {
F_55 ( V_2 , L_24 ,
V_145 , V_2 -> V_16 -> V_177 -> V_147 [ V_145 ] ) ;
return - 1 ;
}
if ( V_178 -> V_26 != V_2 ) {
F_55 ( V_2 , L_25 , V_178 -> V_26 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_152 ( struct V_17 * V_17 , struct V_6 * V_57 )
{
struct V_1 * V_2 = F_4 ( V_57 ) ;
struct V_1 * V_178 = NULL ;
int V_179 , V_180 ;
int V_145 ;
long V_181 = 0 ;
int V_182 = 1 ;
if ( F_16 ( V_2 , V_17 , V_168 ) )
return 0 ;
F_74 ( V_2 ) ;
F_21 ( V_2 , V_168 ) ;
F_76 ( - 1 , V_57 , 0 ) ;
V_145 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_156 )
V_178 = V_2 -> V_26 ;
if ( F_151 ( V_2 , V_145 ) ) {
F_75 ( V_2 ) ;
return 0 ;
}
F_84 ( V_2 , L_26 , V_2 -> V_22 ) ;
if ( V_2 -> V_40 -> V_101 )
V_2 -> V_40 -> V_101 ( V_2 , V_57 ) ;
F_153 ( V_178 ) ;
while ( 1 ) {
V_179 = 0 ;
if ( V_2 -> V_22 <= 1 ) {
if ( F_154 ( & V_2 -> V_183 ) ) {
F_155 ( & V_2 -> V_183 , V_59 ) ;
V_179 ++ ;
}
if ( F_154 ( & V_2 -> V_79 ) ) {
F_155 ( & V_2 -> V_79 , V_60 ) ;
V_179 ++ ;
}
}
if ( V_178 && V_178 -> V_22 <= 1 ) {
if ( F_154 ( & V_178 -> V_183 ) ) {
F_155 ( & V_178 -> V_183 , V_59 ) ;
V_179 ++ ;
}
if ( F_154 ( & V_178 -> V_79 ) ) {
F_155 ( & V_178 -> V_79 , V_60 ) ;
V_179 ++ ;
}
}
if ( ! V_179 )
break;
if ( V_182 ) {
V_182 = 0 ;
F_24 ( V_2 , L_27 ) ;
}
F_156 ( V_181 ) ;
if ( V_181 < 120 * V_184 )
V_181 = 2 * V_181 + 1 ;
else
V_181 = V_185 ;
}
if ( V_178 ) {
if ( -- V_178 -> V_22 < 0 ) {
F_24 ( V_2 , L_28 , V_178 -> V_22 ) ;
V_178 -> V_22 = 0 ;
}
}
if ( -- V_2 -> V_22 < 0 ) {
F_24 ( V_2 , L_29 , V_2 -> V_22 ) ;
V_2 -> V_22 = 0 ;
}
F_12 ( V_57 ) ;
if ( ! V_2 -> V_22 ) {
F_70 ( & V_82 ) ;
F_61 ( V_2 -> V_72 ) ;
if ( V_178 )
F_61 ( V_178 -> V_72 ) ;
F_72 ( & V_82 ) ;
}
V_180 = ! V_2 -> V_22 && ! ( V_178 && V_178 -> V_22 ) ;
F_157 ( V_178 ) ;
F_75 ( V_2 ) ;
if ( ! V_180 )
return 0 ;
F_84 ( V_2 , L_30 ) ;
F_158 ( V_2 ) ;
F_141 ( V_2 ) ;
F_84 ( V_2 , L_31 ) ;
F_31 ( & V_39 ) ;
F_139 ( V_2 , V_145 ) ;
F_32 ( & V_39 ) ;
return 0 ;
}
static struct V_1 * F_159 ( T_1 V_28 , struct V_6 * V_57 )
{
struct V_1 * V_2 ;
int V_161 ;
if ( V_28 != F_27 ( V_186 , 0 ) )
return NULL ;
V_2 = F_60 () ;
if ( ! V_2 )
return F_132 ( - V_187 ) ;
V_57 -> V_126 |= V_188 ;
F_74 ( V_2 ) ;
F_50 ( V_2 ) ;
V_161 = F_127 ( V_2 ) ;
if ( V_161 < 0 ) {
F_75 ( V_2 ) ;
V_2 = F_132 ( V_161 ) ;
}
return V_2 ;
}
static struct V_27 * F_160 ( T_1 V_28 , struct V_6 * V_57 ,
int * V_189 , int * V_29 )
{
struct V_27 * V_16 ;
switch ( V_28 ) {
#ifdef F_161
case F_27 ( V_190 , 0 ) : {
extern struct V_27 * V_191 ;
V_16 = F_28 ( V_191 ) ;
* V_29 = V_192 ;
* V_189 = 1 ;
break;
}
#endif
case F_27 ( V_186 , 1 ) : {
struct V_27 * V_191 = F_162 ( V_29 ) ;
if ( V_191 ) {
V_16 = F_28 ( V_191 ) ;
if ( V_16 ) {
V_57 -> V_126 |= V_188 ;
* V_189 = 1 ;
break;
}
}
return F_132 ( - V_163 ) ;
}
default:
V_16 = F_25 ( V_28 , V_29 ) ;
if ( ! V_16 )
return F_132 ( - V_163 ) ;
break;
}
return V_16 ;
}
static int F_163 ( struct V_17 * V_17 , struct V_6 * V_57 )
{
struct V_1 * V_2 ;
int V_189 , V_161 ;
struct V_27 * V_16 = NULL ;
int V_29 ;
T_1 V_28 = V_17 -> V_193 ;
unsigned V_194 = V_57 -> V_126 ;
F_164 ( V_17 , V_57 ) ;
V_195:
V_161 = F_5 ( V_57 ) ;
if ( V_161 )
return - V_11 ;
V_189 = V_57 -> V_126 & V_196 ;
V_29 = - 1 ;
V_161 = 0 ;
V_2 = F_159 ( V_28 , V_57 ) ;
if ( ! V_2 ) {
F_31 ( & V_39 ) ;
V_16 = F_160 ( V_28 , V_57 , & V_189 , & V_29 ) ;
if ( F_120 ( V_16 ) ) {
V_161 = F_165 ( V_16 ) ;
goto V_197;
}
V_2 = F_119 ( V_16 , V_17 , V_29 ) ;
if ( F_120 ( V_2 ) ) {
V_161 = F_165 ( V_2 ) ;
goto V_197;
}
if ( V_2 ) {
F_32 ( & V_39 ) ;
V_161 = F_166 ( V_2 ) ;
F_50 ( V_2 ) ;
if ( V_161 ) {
if ( V_161 == - V_198 )
V_161 = - V_53 ;
goto V_199;
}
V_161 = F_127 ( V_2 ) ;
if ( V_161 < 0 ) {
F_75 ( V_2 ) ;
V_2 = F_132 ( V_161 ) ;
}
} else {
V_2 = F_130 ( V_16 , V_29 ) ;
F_32 ( & V_39 ) ;
}
F_144 ( V_16 ) ;
}
if ( F_120 ( V_2 ) ) {
V_161 = F_165 ( V_2 ) ;
if ( V_161 != - V_123 || F_108 ( V_48 ) )
goto V_200;
F_11 ( V_57 ) ;
F_167 () ;
goto V_195;
}
F_7 ( V_2 , V_57 ) ;
F_21 ( V_2 , V_168 ) ;
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_156 )
V_189 = 1 ;
F_84 ( V_2 , L_32 , V_2 -> V_22 ) ;
if ( V_2 -> V_40 -> V_201 )
V_161 = V_2 -> V_40 -> V_201 ( V_2 , V_57 ) ;
else
V_161 = - V_163 ;
V_57 -> V_126 = V_194 ;
if ( V_161 ) {
F_84 ( V_2 , L_33 , V_161 ) ;
F_75 ( V_2 ) ;
F_152 ( V_17 , V_57 ) ;
if ( V_161 != - V_53 )
return V_161 ;
if ( F_108 ( V_48 ) )
return V_161 ;
F_167 () ;
if ( F_89 ( V_57 ) )
V_57 -> V_94 = & V_202 ;
goto V_195;
}
F_78 ( V_93 , & V_2 -> V_43 ) ;
F_70 ( & V_82 ) ;
F_58 ( & V_48 -> V_70 -> V_71 ) ;
if ( ! V_189 &&
V_48 -> signal -> V_83 &&
! V_48 -> signal -> V_2 &&
V_2 -> V_72 == NULL ) {
if ( V_57 -> V_203 & V_204 )
F_51 ( V_2 ) ;
}
F_59 ( & V_48 -> V_70 -> V_71 ) ;
F_72 ( & V_82 ) ;
F_75 ( V_2 ) ;
return 0 ;
V_197:
F_32 ( & V_39 ) ;
V_199:
if ( ! F_168 ( V_16 ) )
F_144 ( V_16 ) ;
V_200:
F_11 ( V_57 ) ;
return V_161 ;
}
static unsigned int F_169 ( struct V_6 * V_57 , T_6 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_57 ) ;
struct V_75 * V_76 ;
int V_47 = 0 ;
if ( F_16 ( V_2 , F_100 ( V_57 ) , L_34 ) )
return 0 ;
V_76 = F_101 ( V_2 ) ;
if ( V_76 -> V_40 -> V_205 )
V_47 = V_76 -> V_40 -> V_205 ( V_2 , V_57 , V_58 ) ;
F_67 ( V_76 ) ;
return V_47 ;
}
static int F_76 ( int V_206 , struct V_6 * V_57 , int V_207 )
{
struct V_1 * V_2 = F_4 ( V_57 ) ;
struct V_75 * V_160 ;
unsigned long V_43 ;
int V_161 = 0 ;
if ( F_16 ( V_2 , F_100 ( V_57 ) , L_35 ) )
goto V_131;
V_161 = F_170 ( V_206 , V_57 , V_207 , & V_2 -> V_208 ) ;
if ( V_161 <= 0 )
goto V_131;
V_160 = F_66 ( V_2 ) ;
if ( V_160 ) {
if ( V_160 -> V_40 -> V_208 )
V_160 -> V_40 -> V_208 ( V_2 , V_207 ) ;
F_67 ( V_160 ) ;
}
if ( V_207 ) {
enum V_209 type ;
struct V_44 * V_44 ;
F_36 ( & V_2 -> V_49 , V_43 ) ;
if ( V_2 -> V_45 ) {
V_44 = V_2 -> V_45 ;
type = V_210 ;
} else {
V_44 = F_171 ( V_48 ) ;
type = V_211 ;
}
F_53 ( V_44 ) ;
F_37 ( & V_2 -> V_49 , V_43 ) ;
F_172 ( V_57 , V_44 , type , 0 ) ;
F_52 ( V_44 ) ;
V_161 = 0 ;
}
V_131:
return V_161 ;
}
static int F_173 ( int V_206 , struct V_6 * V_57 , int V_207 )
{
struct V_1 * V_2 = F_4 ( V_57 ) ;
int V_161 ;
F_74 ( V_2 ) ;
V_161 = F_76 ( V_206 , V_57 , V_207 ) ;
F_75 ( V_2 ) ;
return V_161 ;
}
static int F_174 ( struct V_1 * V_2 , char T_3 * V_21 )
{
char V_138 , V_212 = 0 ;
struct V_75 * V_76 ;
if ( ( V_48 -> signal -> V_2 != V_2 ) && ! F_128 ( V_158 ) )
return - V_213 ;
if ( F_175 ( V_138 , V_21 ) )
return - V_133 ;
F_176 ( V_2 , V_138 ) ;
V_76 = F_101 ( V_2 ) ;
V_76 -> V_40 -> V_214 ( V_2 , & V_138 , & V_212 , 1 ) ;
F_67 ( V_76 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , struct V_215 T_3 * V_66 )
{
int V_216 ;
F_31 ( & V_2 -> V_217 ) ;
V_216 = F_178 ( V_66 , & V_2 -> V_215 , sizeof( * V_66 ) ) ;
F_32 ( & V_2 -> V_217 ) ;
return V_216 ? - V_133 : 0 ;
}
int F_179 ( struct V_1 * V_2 , struct V_215 * V_218 )
{
struct V_44 * V_45 ;
F_31 ( & V_2 -> V_217 ) ;
if ( ! memcmp ( V_218 , & V_2 -> V_215 , sizeof( * V_218 ) ) )
goto V_219;
V_45 = F_91 ( V_2 ) ;
if ( V_45 )
F_40 ( V_45 , V_220 , 1 ) ;
F_52 ( V_45 ) ;
V_2 -> V_215 = * V_218 ;
V_219:
F_32 ( & V_2 -> V_217 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 , struct V_215 T_3 * V_66 )
{
struct V_215 V_221 ;
if ( F_107 ( & V_221 , V_66 , sizeof( * V_66 ) ) )
return - V_133 ;
if ( V_2 -> V_40 -> V_222 )
return V_2 -> V_40 -> V_222 ( V_2 , & V_221 ) ;
else
return F_179 ( V_2 , & V_221 ) ;
}
static int F_181 ( struct V_6 * V_6 )
{
if ( ! F_128 ( V_158 ) )
return - V_213 ;
if ( V_6 -> V_94 -> V_95 == V_96 ) {
struct V_6 * V_88 ;
F_8 ( & V_91 ) ;
V_88 = V_92 ;
V_92 = NULL ;
F_10 ( & V_91 ) ;
if ( V_88 )
F_80 ( V_88 ) ;
return 0 ;
}
F_8 ( & V_91 ) ;
if ( V_92 ) {
F_10 ( & V_91 ) ;
return - V_159 ;
}
V_92 = F_112 ( V_6 ) ;
F_10 ( & V_91 ) ;
return 0 ;
}
static int F_182 ( struct V_6 * V_6 , int T_3 * V_21 )
{
int V_223 ;
if ( F_175 ( V_223 , V_21 ) )
return - V_133 ;
F_8 ( & V_6 -> V_224 ) ;
if ( V_223 )
V_6 -> V_126 |= V_188 ;
else
V_6 -> V_126 &= ~ V_188 ;
F_10 ( & V_6 -> V_224 ) ;
return 0 ;
}
static int F_183 ( struct V_1 * V_2 , struct V_6 * V_6 , int V_66 )
{
int V_47 = 0 ;
F_74 ( V_2 ) ;
F_70 ( & V_82 ) ;
if ( V_48 -> signal -> V_83 && ( F_54 ( V_48 ) == V_2 -> V_72 ) )
goto V_225;
if ( ! V_48 -> signal -> V_83 || V_48 -> signal -> V_2 ) {
V_47 = - V_213 ;
goto V_225;
}
if ( V_2 -> V_72 ) {
if ( V_66 == 1 && F_128 ( V_158 ) ) {
F_61 ( V_2 -> V_72 ) ;
} else {
V_47 = - V_213 ;
goto V_225;
}
}
if ( ( V_6 -> V_203 & V_204 ) == 0 && ! F_128 ( V_158 ) ) {
V_47 = - V_213 ;
goto V_225;
}
F_57 ( V_2 ) ;
V_225:
F_72 ( & V_82 ) ;
F_75 ( V_2 ) ;
return V_47 ;
}
struct V_44 * F_91 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_44 * V_45 ;
F_36 ( & V_2 -> V_49 , V_43 ) ;
V_45 = F_53 ( V_2 -> V_45 ) ;
F_37 ( & V_2 -> V_49 , V_43 ) ;
return V_45 ;
}
static struct V_44 * F_184 ( struct V_44 * V_45 )
{
struct V_69 * V_21 ;
struct V_44 * V_226 = NULL ;
V_21 = F_185 ( V_45 , V_210 ) ;
if ( V_21 == NULL )
V_21 = F_185 ( V_45 , V_211 ) ;
if ( V_21 != NULL )
V_226 = F_54 ( V_21 ) ;
return V_226 ;
}
static int F_186 ( struct V_1 * V_2 , struct V_1 * V_227 , T_7 T_3 * V_21 )
{
struct V_44 * V_44 ;
int V_47 ;
if ( V_2 == V_227 && V_48 -> signal -> V_2 != V_227 )
return - V_68 ;
V_44 = F_91 ( V_227 ) ;
V_47 = F_187 ( F_188 ( V_44 ) , V_21 ) ;
F_52 ( V_44 ) ;
return V_47 ;
}
static int F_189 ( struct V_1 * V_2 , struct V_1 * V_227 , T_7 T_3 * V_21 )
{
struct V_44 * V_45 ;
T_7 V_228 ;
int V_161 = F_43 ( V_227 ) ;
if ( V_161 == - V_51 )
return - V_68 ;
if ( V_161 )
return V_161 ;
if ( ! V_48 -> signal -> V_2 ||
( V_48 -> signal -> V_2 != V_227 ) ||
( V_227 -> V_72 != F_54 ( V_48 ) ) )
return - V_68 ;
if ( F_175 ( V_228 , V_21 ) )
return - V_133 ;
if ( V_228 < 0 )
return - V_229 ;
F_34 () ;
V_45 = F_190 ( V_228 ) ;
V_161 = - V_230 ;
if ( ! V_45 )
goto V_231;
V_161 = - V_213 ;
if ( F_184 ( V_45 ) != F_54 ( V_48 ) )
goto V_231;
V_161 = 0 ;
F_58 ( & V_2 -> V_49 ) ;
F_52 ( V_227 -> V_45 ) ;
V_227 -> V_45 = F_53 ( V_45 ) ;
F_59 ( & V_2 -> V_49 ) ;
V_231:
F_42 () ;
return V_161 ;
}
static int F_191 ( struct V_1 * V_2 , struct V_1 * V_227 , T_7 T_3 * V_21 )
{
if ( V_2 == V_227 && V_48 -> signal -> V_2 != V_227 )
return - V_68 ;
if ( ! V_227 -> V_72 )
return - V_68 ;
return F_187 ( F_188 ( V_227 -> V_72 ) , V_21 ) ;
}
static int F_192 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_160 ;
int V_47 ;
if ( F_175 ( V_160 , V_21 ) )
return - V_133 ;
V_47 = F_193 ( V_2 , V_160 ) ;
return V_47 ;
}
static int F_194 ( struct V_1 * V_2 , int T_3 * V_21 )
{
struct V_75 * V_76 ;
int V_47 ;
V_76 = F_101 ( V_2 ) ;
V_47 = F_187 ( V_76 -> V_40 -> V_33 , V_21 ) ;
F_67 ( V_76 ) ;
return V_47 ;
}
static int F_195 ( struct V_1 * V_2 , unsigned int V_232 )
{
int V_161 ;
if ( V_2 -> V_40 -> V_233 == NULL )
return 0 ;
if ( V_2 -> V_16 -> V_43 & V_234 )
V_161 = V_2 -> V_40 -> V_233 ( V_2 , V_232 ) ;
else {
if ( F_103 ( V_2 , 0 ) < 0 )
return - V_198 ;
V_161 = V_2 -> V_40 -> V_233 ( V_2 , - 1 ) ;
if ( V_161 )
goto V_131;
if ( ! F_108 ( V_48 ) )
F_196 ( V_232 ) ;
V_161 = V_2 -> V_40 -> V_233 ( V_2 , 0 ) ;
V_131:
F_102 ( V_2 ) ;
if ( F_108 ( V_48 ) )
V_161 = - V_198 ;
}
return V_161 ;
}
static int F_197 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_161 = - V_229 ;
if ( V_2 -> V_40 -> V_235 ) {
V_161 = V_2 -> V_40 -> V_235 ( V_2 ) ;
if ( V_161 >= 0 )
V_161 = F_187 ( V_161 , V_21 ) ;
}
return V_161 ;
}
static int F_198 ( struct V_1 * V_2 , unsigned int V_65 ,
unsigned T_3 * V_21 )
{
int V_161 ;
unsigned int V_236 , V_237 , V_238 ;
if ( V_2 -> V_40 -> V_239 == NULL )
return - V_229 ;
V_161 = F_175 ( V_238 , V_21 ) ;
if ( V_161 )
return V_161 ;
V_236 = V_237 = 0 ;
switch ( V_65 ) {
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
return V_2 -> V_40 -> V_239 ( V_2 , V_236 , V_237 ) ;
}
static int F_199 ( struct V_1 * V_2 , void T_3 * V_66 )
{
int V_161 = - V_229 ;
struct V_248 V_249 ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
if ( V_2 -> V_40 -> V_250 )
V_161 = V_2 -> V_40 -> V_250 ( V_2 , & V_249 ) ;
if ( V_161 != 0 )
return V_161 ;
if ( F_178 ( V_66 , & V_249 , sizeof( V_249 ) ) )
return - V_133 ;
return 0 ;
}
static void F_200 ( struct V_251 T_3 * V_252 )
{
static F_201 ( V_253 ,
V_254 ,
V_255 ) ;
char V_256 [ V_257 ] ;
int V_43 ;
if ( F_175 ( V_43 , & V_252 -> V_43 ) )
return;
V_43 &= V_258 ;
if ( V_43 && F_202 ( & V_253 ) )
F_203 ( L_36 ,
V_168 , F_204 ( V_256 , V_48 ) , V_43 ) ;
}
static struct V_1 * F_205 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_156 )
V_2 = V_2 -> V_26 ;
return V_2 ;
}
long F_206 ( struct V_6 * V_6 , unsigned int V_65 , unsigned long V_66 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_1 * V_227 ;
void T_3 * V_21 = ( void T_3 * ) V_66 ;
int V_161 ;
struct V_75 * V_76 ;
if ( F_16 ( V_2 , F_100 ( V_6 ) , L_37 ) )
return - V_229 ;
V_227 = F_205 ( V_2 ) ;
switch ( V_65 ) {
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
V_161 = F_43 ( V_2 ) ;
if ( V_161 )
return V_161 ;
if ( V_65 != V_261 ) {
F_207 ( V_2 , 0 ) ;
if ( F_108 ( V_48 ) )
return - V_198 ;
}
break;
}
switch ( V_65 ) {
case V_264 :
return F_174 ( V_2 , V_21 ) ;
case V_265 :
return F_177 ( V_227 , V_21 ) ;
case V_266 :
return F_180 ( V_227 , V_21 ) ;
case V_267 :
return V_227 != V_2 ? - V_229 : F_181 ( V_6 ) ;
case V_268 :
return F_182 ( V_6 , V_21 ) ;
case V_269 :
F_79 ( V_157 , & V_2 -> V_43 ) ;
return 0 ;
case V_270 :
F_78 ( V_157 , & V_2 -> V_43 ) ;
return 0 ;
case V_271 :
{
int V_272 = F_65 ( V_157 , & V_2 -> V_43 ) ;
return F_187 ( V_272 , ( int T_3 * ) V_21 ) ;
}
case V_273 :
if ( V_48 -> signal -> V_2 != V_2 )
return - V_68 ;
F_92 () ;
return 0 ;
case V_274 :
return F_183 ( V_227 , V_6 , V_66 ) ;
case V_275 :
return F_186 ( V_2 , V_227 , V_21 ) ;
case V_67 :
return F_189 ( V_2 , V_227 , V_21 ) ;
case V_276 :
return F_191 ( V_2 , V_227 , V_21 ) ;
case V_277 :
return F_194 ( V_2 , V_21 ) ;
case V_259 :
return F_192 ( V_2 , V_21 ) ;
case V_278 :
if ( ! F_128 ( V_158 ) )
return - V_213 ;
F_86 ( V_2 ) ;
return 0 ;
case V_279 :
{
unsigned int V_47 = F_208 ( F_209 ( V_227 ) ) ;
return F_187 ( V_47 , ( unsigned int T_3 * ) V_21 ) ;
}
case V_260 :
if ( V_2 -> V_40 -> V_233 )
return V_2 -> V_40 -> V_233 ( V_2 , - 1 ) ;
return 0 ;
case V_261 :
if ( V_2 -> V_40 -> V_233 )
return V_2 -> V_40 -> V_233 ( V_2 , 0 ) ;
return 0 ;
case V_262 :
if ( ! V_66 )
return F_195 ( V_2 , 250 ) ;
return 0 ;
case V_263 :
return F_195 ( V_2 , V_66 ? V_66 * 100 : 250 ) ;
case V_280 :
return F_197 ( V_2 , V_21 ) ;
case V_242 :
case V_241 :
case V_240 :
return F_198 ( V_2 , V_65 , V_21 ) ;
case V_281 :
V_161 = F_199 ( V_2 , V_21 ) ;
if ( V_161 != - V_229 )
return V_161 ;
break;
case V_282 :
switch ( V_66 ) {
case V_283 :
case V_284 :
F_210 ( V_2 , NULL ) ;
break;
}
break;
case V_285 :
F_200 ( V_21 ) ;
break;
}
if ( V_2 -> V_40 -> V_286 ) {
V_161 = V_2 -> V_40 -> V_286 ( V_2 , V_65 , V_66 ) ;
if ( V_161 != - V_287 )
return V_161 ;
}
V_76 = F_101 ( V_2 ) ;
V_161 = - V_229 ;
if ( V_76 -> V_40 -> V_286 ) {
V_161 = V_76 -> V_40 -> V_286 ( V_2 , V_6 , V_65 , V_66 ) ;
if ( V_161 == - V_287 )
V_161 = - V_68 ;
}
F_67 ( V_76 ) ;
return V_161 ;
}
static long F_211 ( struct V_6 * V_6 , unsigned int V_65 ,
unsigned long V_66 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_75 * V_76 ;
int V_161 = - V_287 ;
if ( F_16 ( V_2 , F_100 ( V_6 ) , L_37 ) )
return - V_229 ;
if ( V_2 -> V_40 -> V_288 ) {
V_161 = V_2 -> V_40 -> V_288 ( V_2 , V_65 , V_66 ) ;
if ( V_161 != - V_287 )
return V_161 ;
}
V_76 = F_101 ( V_2 ) ;
if ( V_76 -> V_40 -> V_288 )
V_161 = V_76 -> V_40 -> V_288 ( V_2 , V_6 , V_65 , V_66 ) ;
else
V_161 = F_212 ( V_2 , V_6 , V_65 , V_66 ) ;
F_67 ( V_76 ) ;
return V_161 ;
}
static int F_213 ( const void * V_289 , struct V_6 * V_6 , unsigned V_206 )
{
if ( F_214 ( V_6 -> V_94 -> V_119 != F_99 ) )
return 0 ;
return F_4 ( V_6 ) != V_289 ? 0 : V_206 + 1 ;
}
void F_215 ( struct V_1 * V_2 )
{
#ifdef F_216
F_83 ( V_2 ) ;
#else
struct V_69 * V_290 , * V_21 ;
struct V_44 * V_72 ;
int V_117 ;
if ( ! V_2 )
return;
V_72 = V_2 -> V_72 ;
F_217 ( V_2 ) ;
F_218 ( V_2 ) ;
F_70 ( & V_82 ) ;
F_62 (session, PIDTYPE_SID, p) {
F_219 ( V_2 , L_38 ,
F_220 ( V_21 ) , V_21 -> V_256 ) ;
F_221 ( V_291 , V_21 , 1 ) ;
} F_63 ( V_72 , V_74 , V_21 ) ;
F_222 (g, p) {
if ( V_21 -> signal -> V_2 == V_2 ) {
F_219 ( V_2 , L_39 ,
F_220 ( V_21 ) , V_21 -> V_256 ) ;
F_221 ( V_291 , V_21 , 1 ) ;
continue;
}
F_223 ( V_21 ) ;
V_117 = F_224 ( V_21 -> V_292 , 0 , F_213 , V_2 ) ;
if ( V_117 != 0 ) {
F_219 ( V_2 , L_40 ,
F_220 ( V_21 ) , V_21 -> V_256 , V_117 - 1 ) ;
F_225 ( V_291 , V_21 ) ;
}
F_226 ( V_21 ) ;
} F_227 ( V_290 , V_21 ) ;
F_72 ( & V_82 ) ;
#endif
}
static void F_228 ( struct V_103 * V_104 )
{
struct V_1 * V_2 =
F_82 ( V_104 , struct V_1 , V_171 ) ;
F_215 ( V_2 ) ;
}
void F_229 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_85 ( & V_2 -> V_171 ) ;
}
static int F_230 ( struct V_28 * V_3 , const void * V_293 )
{
const T_1 * V_294 = V_293 ;
return V_3 -> V_294 == * V_294 ;
}
static struct V_28 * F_231 ( struct V_1 * V_2 )
{
T_1 V_294 = F_209 ( V_2 ) ;
return F_232 ( V_295 , NULL , & V_294 , F_230 ) ;
}
struct V_1 * F_133 ( struct V_27 * V_16 , int V_145 )
{
struct V_1 * V_2 ;
V_2 = F_233 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_234 ( & V_2 -> V_174 ) ;
V_2 -> V_5 = V_19 ;
F_235 ( V_2 ) ;
V_2 -> V_72 = NULL ;
V_2 -> V_45 = NULL ;
F_236 ( & V_2 -> V_296 ) ;
F_236 ( & V_2 -> V_297 ) ;
F_237 ( & V_2 -> V_141 ) ;
F_236 ( & V_2 -> V_217 ) ;
F_238 ( & V_2 -> V_298 ) ;
F_239 ( & V_2 -> V_79 ) ;
F_239 ( & V_2 -> V_183 ) ;
F_147 ( & V_2 -> V_105 , F_81 ) ;
F_236 ( & V_2 -> V_121 ) ;
F_240 ( & V_2 -> V_49 ) ;
F_240 ( & V_2 -> V_111 ) ;
F_241 ( & V_2 -> V_14 ) ;
F_147 ( & V_2 -> V_171 , F_228 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_40 = V_16 -> V_40 ;
V_2 -> V_29 = V_145 ;
F_118 ( V_16 , V_145 , V_2 -> V_15 ) ;
V_2 -> V_3 = F_231 ( V_2 ) ;
return V_2 ;
}
void F_136 ( struct V_1 * V_2 )
{
F_242 ( V_2 ) ;
}
int F_243 ( struct V_1 * V_2 , unsigned char V_138 )
{
if ( V_2 -> V_40 -> V_299 )
return V_2 -> V_40 -> V_299 ( V_2 , V_138 ) ;
return V_2 -> V_40 -> V_95 ( V_2 , & V_138 , 1 ) ;
}
static int F_244 ( struct V_27 * V_16 , T_1 V_3 ,
unsigned int V_29 , unsigned int V_22 )
{
int V_216 ;
V_16 -> V_300 [ V_29 ] = F_245 () ;
if ( ! V_16 -> V_300 [ V_29 ] )
return - V_11 ;
V_16 -> V_300 [ V_29 ] -> V_40 = & V_202 ;
V_16 -> V_300 [ V_29 ] -> V_162 = V_16 -> V_162 ;
V_216 = F_246 ( V_16 -> V_300 [ V_29 ] , V_3 , V_22 ) ;
if ( V_216 )
F_247 ( & V_16 -> V_300 [ V_29 ] -> V_301 ) ;
return V_216 ;
}
struct V_28 * F_248 ( struct V_27 * V_16 , unsigned V_29 ,
struct V_28 * V_28 )
{
return F_249 ( V_16 , V_29 , V_28 , NULL , NULL ) ;
}
static void F_250 ( struct V_28 * V_3 )
{
F_251 ( V_3 , L_41 ) ;
F_3 ( V_3 ) ;
}
struct V_28 * F_249 ( struct V_27 * V_16 ,
unsigned V_29 , struct V_28 * V_28 ,
void * V_302 ,
const struct V_303 * * V_304 )
{
char V_15 [ 64 ] ;
T_1 V_294 = F_27 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ;
struct V_28 * V_3 = NULL ;
int V_161 = - V_163 ;
bool V_305 = false ;
if ( V_29 >= V_16 -> V_33 ) {
F_252 ( L_42 ,
V_16 -> V_15 , V_29 ) ;
return F_132 ( - V_229 ) ;
}
if ( V_16 -> type == V_23 )
F_117 ( V_16 , V_29 , V_15 ) ;
else
F_118 ( V_16 , V_29 , V_15 ) ;
if ( ! ( V_16 -> V_43 & V_306 ) ) {
V_161 = F_244 ( V_16 , V_294 , V_29 , 1 ) ;
if ( V_161 )
goto error;
V_305 = true ;
}
V_3 = F_233 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 ) {
V_161 = - V_11 ;
goto error;
}
V_3 -> V_294 = V_294 ;
V_3 -> V_307 = V_295 ;
V_3 -> V_308 = V_28 ;
V_3 -> V_309 = F_250 ;
F_253 ( V_3 , L_18 , V_15 ) ;
V_3 -> V_310 = V_304 ;
F_254 ( V_3 , V_302 ) ;
V_161 = F_255 ( V_3 ) ;
if ( V_161 )
goto error;
return V_3 ;
error:
F_2 ( V_3 ) ;
if ( V_305 ) {
F_256 ( V_16 -> V_300 [ V_29 ] ) ;
V_16 -> V_300 [ V_29 ] = NULL ;
}
return F_132 ( V_161 ) ;
}
void F_257 ( struct V_27 * V_16 , unsigned V_29 )
{
F_258 ( V_295 ,
F_27 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ) ;
if ( ! ( V_16 -> V_43 & V_306 ) ) {
F_256 ( V_16 -> V_300 [ V_29 ] ) ;
V_16 -> V_300 [ V_29 ] = NULL ;
}
}
struct V_27 * F_259 ( unsigned int V_311 , struct V_172 * V_162 ,
unsigned long V_43 )
{
struct V_27 * V_16 ;
unsigned int V_300 = 1 ;
int V_216 ;
if ( ! V_311 || ( V_43 & V_144 && V_311 > 1 ) )
return F_132 ( - V_229 ) ;
V_16 = F_233 ( sizeof( struct V_27 ) , V_10 ) ;
if ( ! V_16 )
return F_132 ( - V_11 ) ;
F_234 ( & V_16 -> V_174 ) ;
V_16 -> V_5 = V_312 ;
V_16 -> V_33 = V_311 ;
V_16 -> V_162 = V_162 ;
V_16 -> V_43 = V_43 ;
if ( ! ( V_43 & V_176 ) ) {
V_16 -> V_147 = F_260 ( V_311 , sizeof( * V_16 -> V_147 ) ,
V_10 ) ;
V_16 -> V_151 = F_260 ( V_311 , sizeof( * V_16 -> V_151 ) ,
V_10 ) ;
if ( ! V_16 -> V_147 || ! V_16 -> V_151 ) {
V_216 = - V_11 ;
goto V_313;
}
}
if ( ! ( V_43 & V_306 ) ) {
V_16 -> V_167 = F_260 ( V_311 , sizeof( * V_16 -> V_167 ) ,
V_10 ) ;
if ( ! V_16 -> V_167 ) {
V_216 = - V_11 ;
goto V_313;
}
V_300 = V_311 ;
}
V_16 -> V_300 = F_260 ( V_300 , sizeof( * V_16 -> V_300 ) , V_10 ) ;
if ( ! V_16 -> V_300 ) {
V_216 = - V_11 ;
goto V_313;
}
return V_16 ;
V_313:
F_3 ( V_16 -> V_167 ) ;
F_3 ( V_16 -> V_147 ) ;
F_3 ( V_16 -> V_151 ) ;
F_3 ( V_16 -> V_300 ) ;
F_3 ( V_16 ) ;
return F_132 ( V_216 ) ;
}
static void F_261 ( struct V_174 * V_174 )
{
struct V_27 * V_16 = F_82 ( V_174 , struct V_27 , V_174 ) ;
int V_117 ;
struct V_148 * V_149 ;
if ( V_16 -> V_43 & V_314 ) {
for ( V_117 = 0 ; V_117 < V_16 -> V_33 ; V_117 ++ ) {
V_149 = V_16 -> V_151 [ V_117 ] ;
if ( V_149 ) {
V_16 -> V_151 [ V_117 ] = NULL ;
F_3 ( V_149 ) ;
}
if ( ! ( V_16 -> V_43 & V_315 ) )
F_257 ( V_16 , V_117 ) ;
}
F_262 ( V_16 ) ;
if ( V_16 -> V_43 & V_306 )
F_256 ( V_16 -> V_300 [ 0 ] ) ;
}
F_3 ( V_16 -> V_300 ) ;
F_3 ( V_16 -> V_167 ) ;
F_3 ( V_16 -> V_151 ) ;
F_3 ( V_16 -> V_147 ) ;
F_3 ( V_16 ) ;
}
void F_144 ( struct V_27 * V_16 )
{
F_148 ( & V_16 -> V_174 , F_261 ) ;
}
void F_263 ( struct V_27 * V_16 ,
const struct V_316 * V_317 )
{
V_16 -> V_40 = V_317 ;
}
void F_264 ( struct V_27 * V_318 )
{
F_144 ( V_318 ) ;
}
int F_265 ( struct V_27 * V_16 )
{
int error ;
int V_117 ;
T_1 V_3 ;
struct V_28 * V_318 ;
if ( ! V_16 -> V_31 ) {
error = F_266 ( & V_3 , V_16 -> V_32 ,
V_16 -> V_33 , V_16 -> V_15 ) ;
if ( ! error ) {
V_16 -> V_31 = F_267 ( V_3 ) ;
V_16 -> V_32 = F_268 ( V_3 ) ;
}
} else {
V_3 = F_27 ( V_16 -> V_31 , V_16 -> V_32 ) ;
error = F_269 ( V_3 , V_16 -> V_33 , V_16 -> V_15 ) ;
}
if ( error < 0 )
goto V_216;
if ( V_16 -> V_43 & V_306 ) {
error = F_244 ( V_16 , V_3 , 0 , V_16 -> V_33 ) ;
if ( error )
goto V_319;
}
F_31 ( & V_39 ) ;
F_9 ( & V_16 -> V_320 , & V_320 ) ;
F_32 ( & V_39 ) ;
if ( ! ( V_16 -> V_43 & V_315 ) ) {
for ( V_117 = 0 ; V_117 < V_16 -> V_33 ; V_117 ++ ) {
V_318 = F_248 ( V_16 , V_117 , NULL ) ;
if ( F_120 ( V_318 ) ) {
error = F_165 ( V_318 ) ;
goto V_321;
}
}
}
F_270 ( V_16 ) ;
V_16 -> V_43 |= V_314 ;
return 0 ;
V_321:
for ( V_117 -- ; V_117 >= 0 ; V_117 -- )
F_257 ( V_16 , V_117 ) ;
F_31 ( & V_39 ) ;
F_13 ( & V_16 -> V_320 ) ;
F_32 ( & V_39 ) ;
V_319:
F_271 ( V_3 , V_16 -> V_33 ) ;
V_216:
return error ;
}
int F_272 ( struct V_27 * V_16 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_271 ( F_27 ( V_16 -> V_31 , V_16 -> V_32 ) ,
V_16 -> V_33 ) ;
F_31 ( & V_39 ) ;
F_13 ( & V_16 -> V_320 ) ;
F_32 ( & V_39 ) ;
return 0 ;
}
T_1 F_209 ( struct V_1 * V_2 )
{
return F_27 ( V_2 -> V_16 -> V_31 , V_2 -> V_16 -> V_32 ) + V_2 -> V_29 ;
}
void F_273 ( struct V_322 * V_323 )
{
* V_323 = V_202 ;
}
void T_8 F_274 ( void )
{
T_9 * V_324 ;
F_275 () ;
V_324 = V_325 ;
while ( V_324 < V_326 ) {
(* V_324)() ;
V_324 ++ ;
}
}
static char * F_276 ( struct V_28 * V_3 , T_10 * V_327 )
{
if ( ! V_327 )
return NULL ;
if ( V_3 -> V_294 == F_27 ( V_186 , 0 ) ||
V_3 -> V_294 == F_27 ( V_186 , 2 ) )
* V_327 = 0666 ;
return NULL ;
}
static int T_8 F_277 ( void )
{
V_295 = F_278 ( V_328 , L_17 ) ;
if ( F_120 ( V_295 ) )
return F_165 ( V_295 ) ;
V_295 -> V_329 = F_276 ;
return 0 ;
}
static T_2 F_279 ( struct V_28 * V_3 ,
struct V_330 * V_331 , char * V_55 )
{
struct V_332 * V_333 [ 16 ] ;
int V_117 = 0 ;
struct V_332 * V_334 ;
T_2 V_22 = 0 ;
F_280 () ;
F_281 (c) {
if ( ! V_334 -> V_28 )
continue;
if ( ! V_334 -> V_95 )
continue;
if ( ( V_334 -> V_43 & V_335 ) == 0 )
continue;
V_333 [ V_117 ++ ] = V_334 ;
if ( V_117 >= F_282 ( V_333 ) )
break;
}
while ( V_117 -- ) {
int V_29 = V_333 [ V_117 ] -> V_29 ;
struct V_27 * V_336 = V_333 [ V_117 ] -> V_28 ( V_333 [ V_117 ] , & V_29 ) ;
if ( V_336 && ( V_333 [ V_117 ] -> V_29 > 0 || V_336 -> V_31 != V_190 ) )
V_22 += F_118 ( V_336 , V_29 , V_55 + V_22 ) ;
else
V_22 += sprintf ( V_55 + V_22 , L_19 ,
V_333 [ V_117 ] -> V_15 , V_333 [ V_117 ] -> V_29 ) ;
V_22 += sprintf ( V_55 + V_22 , L_43 , V_117 ? ' ' : '\n' ) ;
}
F_283 () ;
return V_22 ;
}
void F_284 ( void )
{
if ( V_337 )
F_285 ( & V_337 -> V_301 , NULL , L_44 ) ;
}
int T_8 F_286 ( void )
{
F_287 ( & V_338 , & V_202 ) ;
if ( F_246 ( & V_338 , F_27 ( V_186 , 0 ) , 1 ) ||
F_269 ( F_27 ( V_186 , 0 ) , 1 , L_45 ) < 0 )
F_288 ( L_46 ) ;
F_289 ( V_295 , NULL , F_27 ( V_186 , 0 ) , NULL , L_17 ) ;
F_287 ( & V_339 , & V_340 ) ;
if ( F_246 ( & V_339 , F_27 ( V_186 , 1 ) , 1 ) ||
F_269 ( F_27 ( V_186 , 1 ) , 1 , L_47 ) < 0 )
F_288 ( L_48 ) ;
V_337 = F_290 ( V_295 , NULL ,
F_27 ( V_186 , 1 ) , NULL ,
V_341 , L_49 ) ;
if ( F_120 ( V_337 ) )
V_337 = NULL ;
#ifdef F_161
F_291 ( & V_340 ) ;
#endif
return 0 ;
}
