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
int F_15 ( struct V_1 * V_2 , struct V_16 * V_16 ,
const char * V_17 )
{
#ifdef F_16
if ( ! V_2 ) {
F_17 ( V_18
L_2 ,
F_18 ( V_16 ) , F_19 ( V_16 ) , V_17 ) ;
return 1 ;
}
if ( V_2 -> V_5 != V_19 ) {
F_17 ( V_18
L_3 ,
F_18 ( V_16 ) , F_19 ( V_16 ) , V_17 ) ;
return 1 ;
}
#endif
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , const char * V_17 )
{
#ifdef F_21
struct V_20 * V_21 ;
int V_22 = 0 ;
F_8 ( & V_12 ) ;
F_22 (p, &tty->tty_files) {
V_22 ++ ;
}
F_10 ( & V_12 ) ;
if ( V_2 -> V_23 -> type == V_24 &&
V_2 -> V_23 -> V_25 == V_26 &&
V_2 -> V_27 && V_2 -> V_27 -> V_22 )
V_22 ++ ;
if ( V_2 -> V_22 != V_22 ) {
F_17 ( V_18 L_4
L_5 ,
V_2 -> V_15 , V_2 -> V_22 , V_22 , V_17 ) ;
return V_22 ;
}
#endif
return 0 ;
}
static struct V_28 * F_23 ( T_1 V_29 , int * V_30 )
{
struct V_28 * V_21 ;
F_24 (p, &tty_drivers, tty_drivers) {
T_1 V_31 = F_25 ( V_21 -> V_32 , V_21 -> V_33 ) ;
if ( V_29 < V_31 || V_29 >= V_31 + V_21 -> V_34 )
continue;
* V_30 = V_29 - V_31 ;
return F_26 ( V_21 ) ;
}
return NULL ;
}
struct V_28 * F_27 ( char * V_15 , int * line )
{
struct V_28 * V_21 , * V_35 = NULL ;
int V_36 = 0 ;
int V_37 ;
char * V_38 , * V_39 ;
for ( V_38 = V_15 ; * V_38 ; V_38 ++ )
if ( ( * V_38 >= '0' && * V_38 <= '9' ) || * V_38 == ',' )
break;
if ( ! * V_38 )
return NULL ;
V_37 = V_38 - V_15 ;
V_36 = F_28 ( V_38 , & V_38 , 10 ) ;
F_29 ( & V_40 ) ;
F_24 (p, &tty_drivers, tty_drivers) {
if ( strncmp ( V_15 , V_21 -> V_15 , V_37 ) != 0 )
continue;
V_39 = V_38 ;
if ( * V_39 == ',' )
V_39 ++ ;
if ( * V_39 == '\0' )
V_39 = NULL ;
if ( V_36 >= 0 && V_36 < V_21 -> V_34 && V_21 -> V_41 &&
V_21 -> V_41 -> V_42 && ! V_21 -> V_41 -> V_42 ( V_21 , V_36 , V_39 ) ) {
V_35 = F_26 ( V_21 ) ;
* line = V_36 ;
break;
}
}
F_30 ( & V_40 ) ;
return V_35 ;
}
int F_31 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_44 * V_45 ;
int V_46 = 0 ;
if ( V_47 -> signal -> V_2 != V_2 )
return 0 ;
F_32 () ;
V_45 = F_33 ( V_47 ) ;
F_34 ( & V_2 -> V_48 , V_43 ) ;
if ( ! V_2 -> V_45 ) {
F_17 ( V_18 L_6 ) ;
goto V_49;
}
if ( V_45 == V_2 -> V_45 )
goto V_49;
F_35 ( & V_2 -> V_48 , V_43 ) ;
if ( F_36 ( V_50 ) )
goto V_51;
if ( F_37 () ) {
V_46 = - V_52 ;
goto V_51;
}
F_38 ( V_45 , V_50 , 1 ) ;
F_39 () ;
F_40 ( V_53 ) ;
V_46 = - V_54 ;
return V_46 ;
V_49:
F_35 ( & V_2 -> V_48 , V_43 ) ;
V_51:
F_39 () ;
return V_46 ;
}
static T_2 F_41 ( struct V_6 * V_6 , char T_3 * V_55 ,
T_4 V_22 , T_5 * V_56 )
{
return 0 ;
}
static T_2 F_42 ( struct V_6 * V_6 , const char T_3 * V_55 ,
T_4 V_22 , T_5 * V_56 )
{
return - V_52 ;
}
static unsigned int F_43 ( struct V_6 * V_57 , T_6 * V_58 )
{
return V_59 | V_60 | V_61 | V_62 | V_63 | V_64 ;
}
static long F_44 ( struct V_6 * V_6 , unsigned int V_65 ,
unsigned long V_66 )
{
return V_65 == V_67 ? - V_68 : - V_52 ;
}
static long F_45 ( struct V_6 * V_6 ,
unsigned int V_65 , unsigned long V_66 )
{
return V_65 == V_67 ? - V_68 : - V_52 ;
}
void F_46 ( struct V_69 * V_21 )
{
unsigned long V_43 ;
struct V_1 * V_2 ;
F_34 ( & V_21 -> V_70 -> V_71 , V_43 ) ;
V_2 = V_21 -> signal -> V_2 ;
V_21 -> signal -> V_2 = NULL ;
F_35 ( & V_21 -> V_70 -> V_71 , V_43 ) ;
F_47 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
F_34 ( & V_2 -> V_48 , V_43 ) ;
F_49 ( V_2 -> V_72 ) ;
F_49 ( V_2 -> V_45 ) ;
V_2 -> V_45 = F_50 ( F_33 ( V_47 ) ) ;
F_35 ( & V_2 -> V_48 , V_43 ) ;
V_2 -> V_72 = F_50 ( F_51 ( V_47 ) ) ;
if ( V_47 -> signal -> V_2 ) {
F_52 ( V_2 , L_7 ,
V_47 -> signal -> V_2 -> V_15 ) ;
F_47 ( V_47 -> signal -> V_2 ) ;
}
F_49 ( V_47 -> signal -> V_73 ) ;
V_47 -> signal -> V_2 = F_53 ( V_2 ) ;
V_47 -> signal -> V_73 = NULL ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_55 ( & V_47 -> V_70 -> V_71 ) ;
F_48 ( V_2 ) ;
F_56 ( & V_47 -> V_70 -> V_71 ) ;
}
struct V_1 * F_57 ( void )
{
struct V_1 * V_2 ;
unsigned long V_43 ;
F_34 ( & V_47 -> V_70 -> V_71 , V_43 ) ;
V_2 = F_53 ( V_47 -> signal -> V_2 ) ;
F_35 ( & V_47 -> V_70 -> V_71 , V_43 ) ;
return V_2 ;
}
static void F_58 ( struct V_44 * V_72 )
{
struct V_69 * V_21 ;
F_59 (session, PIDTYPE_SID, p) {
F_46 ( V_21 ) ;
} F_60 ( V_72 , V_74 , V_21 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_75 * V_76 ;
if ( F_62 ( V_77 , & V_2 -> V_43 ) ) {
V_76 = F_63 ( V_2 ) ;
if ( V_76 ) {
if ( V_76 -> V_41 -> V_78 )
V_76 -> V_41 -> V_78 ( V_2 ) ;
F_64 ( V_76 ) ;
}
}
F_65 ( & V_2 -> V_79 , V_60 ) ;
}
static int F_66 ( struct V_1 * V_2 , int V_80 )
{
struct V_69 * V_21 ;
int V_81 = 0 ;
struct V_44 * V_82 = NULL ;
F_67 ( & V_83 ) ;
if ( V_2 -> V_72 ) {
F_59 (tty->session, PIDTYPE_SID, p) {
F_55 ( & V_21 -> V_70 -> V_71 ) ;
if ( V_21 -> signal -> V_2 == V_2 ) {
V_21 -> signal -> V_2 = NULL ;
V_81 ++ ;
}
if ( ! V_21 -> signal -> V_84 ) {
F_56 ( & V_21 -> V_70 -> V_71 ) ;
continue;
}
F_68 ( V_85 , V_86 , V_21 ) ;
F_68 ( V_87 , V_86 , V_21 ) ;
F_49 ( V_21 -> signal -> V_73 ) ;
F_8 ( & V_2 -> V_48 ) ;
V_82 = F_50 ( V_2 -> V_45 ) ;
if ( V_2 -> V_45 )
V_21 -> signal -> V_73 = F_50 ( V_2 -> V_45 ) ;
F_10 ( & V_2 -> V_48 ) ;
F_56 ( & V_21 -> V_70 -> V_71 ) ;
} F_60 ( V_2 -> V_72 , V_74 , V_21 ) ;
}
F_69 ( & V_83 ) ;
if ( V_82 ) {
if ( V_80 )
F_38 ( V_82 , V_85 , V_80 ) ;
F_49 ( V_82 ) ;
}
return V_81 ;
}
static void F_70 ( struct V_1 * V_2 , int V_80 )
{
struct V_6 * V_88 = NULL ;
struct V_6 * V_57 , * V_89 = NULL ;
struct V_7 * V_9 ;
int V_90 = 0 , V_91 ;
int V_81 ;
if ( ! V_2 )
return;
F_8 ( & V_92 ) ;
if ( V_93 && F_4 ( V_93 ) == V_2 ) {
V_89 = V_93 ;
V_93 = NULL ;
}
F_10 ( & V_92 ) ;
F_71 ( V_2 ) ;
if ( F_62 ( V_94 , & V_2 -> V_43 ) ) {
F_72 ( V_2 ) ;
return;
}
F_20 ( V_2 , L_8 ) ;
F_8 ( & V_12 ) ;
F_24 (priv, &tty->tty_files, list) {
V_57 = V_9 -> V_6 ;
if ( V_57 -> V_95 -> V_96 == V_97 )
V_88 = V_57 ;
if ( V_57 -> V_95 -> V_96 != V_98 )
continue;
V_90 ++ ;
F_73 ( - 1 , V_57 , 0 ) ;
V_57 -> V_95 = & V_99 ;
}
F_10 ( & V_12 ) ;
V_81 = F_66 ( V_2 , V_80 ) ;
while ( V_81 -- )
F_47 ( V_2 ) ;
F_74 ( V_2 ) ;
F_55 ( & V_2 -> V_48 ) ;
F_75 ( V_100 , & V_2 -> V_43 ) ;
F_75 ( V_77 , & V_2 -> V_43 ) ;
F_49 ( V_2 -> V_72 ) ;
F_49 ( V_2 -> V_45 ) ;
V_2 -> V_72 = NULL ;
V_2 -> V_45 = NULL ;
V_2 -> V_101 = 0 ;
F_56 ( & V_2 -> V_48 ) ;
if ( V_88 ) {
if ( V_2 -> V_41 -> V_102 )
for ( V_91 = 0 ; V_91 < V_90 ; V_91 ++ )
V_2 -> V_41 -> V_102 ( V_2 , V_88 ) ;
} else if ( V_2 -> V_41 -> V_103 )
V_2 -> V_41 -> V_103 ( V_2 ) ;
F_76 ( V_94 , & V_2 -> V_43 ) ;
F_72 ( V_2 ) ;
if ( V_89 )
F_77 ( V_89 ) ;
}
static void F_78 ( struct V_104 * V_105 )
{
struct V_1 * V_2 =
F_79 ( V_105 , struct V_1 , V_106 ) ;
F_70 ( V_2 , 0 ) ;
}
void F_80 ( struct V_1 * V_2 )
{
F_81 ( V_2 , L_9 ) ;
F_82 ( & V_2 -> V_106 ) ;
}
void F_83 ( struct V_1 * V_2 )
{
F_81 ( V_2 , L_9 ) ;
F_70 ( V_2 , 0 ) ;
}
void F_84 ( void )
{
struct V_1 * V_2 ;
V_2 = F_57 () ;
if ( V_2 ) {
F_83 ( V_2 ) ;
F_47 ( V_2 ) ;
}
}
static void F_85 ( struct V_1 * V_2 )
{
F_81 ( V_2 , L_9 ) ;
F_70 ( V_2 , 1 ) ;
}
int F_86 ( struct V_6 * V_57 )
{
return ( V_57 -> V_95 == & V_99 ) ;
}
void F_87 ( int V_107 )
{
struct V_1 * V_2 ;
if ( ! V_47 -> signal -> V_84 )
return;
V_2 = F_57 () ;
if ( V_2 ) {
if ( V_107 && V_2 -> V_23 -> type != V_24 ) {
F_85 ( V_2 ) ;
} else {
struct V_44 * V_82 = F_88 ( V_2 ) ;
if ( V_82 ) {
F_38 ( V_82 , V_85 , V_107 ) ;
if ( ! V_107 )
F_38 ( V_82 , V_87 , V_107 ) ;
F_49 ( V_82 ) ;
}
}
F_47 ( V_2 ) ;
} else if ( V_107 ) {
struct V_44 * V_108 ;
F_55 ( & V_47 -> V_70 -> V_71 ) ;
V_108 = V_47 -> signal -> V_73 ;
V_47 -> signal -> V_73 = NULL ;
F_56 ( & V_47 -> V_70 -> V_71 ) ;
if ( V_108 ) {
F_38 ( V_108 , V_85 , V_107 ) ;
F_38 ( V_108 , V_87 , V_107 ) ;
F_49 ( V_108 ) ;
}
return;
}
F_55 ( & V_47 -> V_70 -> V_71 ) ;
F_49 ( V_47 -> signal -> V_73 ) ;
V_47 -> signal -> V_73 = NULL ;
V_2 = F_53 ( V_47 -> signal -> V_2 ) ;
if ( V_2 ) {
unsigned long V_43 ;
F_34 ( & V_2 -> V_48 , V_43 ) ;
F_49 ( V_2 -> V_72 ) ;
F_49 ( V_2 -> V_45 ) ;
V_2 -> V_72 = NULL ;
V_2 -> V_45 = NULL ;
F_35 ( & V_2 -> V_48 , V_43 ) ;
F_47 ( V_2 ) ;
} else
F_81 ( V_2 , L_10 ) ;
F_56 ( & V_47 -> V_70 -> V_71 ) ;
F_67 ( & V_83 ) ;
F_58 ( F_51 ( V_47 ) ) ;
F_69 ( & V_83 ) ;
}
void F_89 ( void )
{
struct V_69 * V_109 = V_47 ;
F_87 ( 0 ) ;
F_46 ( V_109 ) ;
}
void F_90 ( struct V_1 * V_2 )
{
if ( V_2 -> V_110 )
return;
V_2 -> V_110 = 1 ;
if ( V_2 -> V_41 -> V_111 )
V_2 -> V_41 -> V_111 ( V_2 ) ;
}
void F_91 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
F_34 ( & V_2 -> V_112 , V_43 ) ;
F_90 ( V_2 ) ;
F_35 ( & V_2 -> V_112 , V_43 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_110 || V_2 -> V_113 )
return;
V_2 -> V_110 = 0 ;
if ( V_2 -> V_41 -> V_114 )
V_2 -> V_41 -> V_114 ( V_2 ) ;
F_61 ( V_2 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
F_34 ( & V_2 -> V_112 , V_43 ) ;
F_92 ( V_2 ) ;
F_35 ( & V_2 -> V_112 , V_43 ) ;
}
static void F_94 ( struct V_115 * time )
{
unsigned long V_116 = F_95 () ;
if ( ( V_116 ^ time -> V_117 ) & ~ 7 )
time -> V_117 = V_116 ;
}
static T_2 F_96 ( struct V_6 * V_6 , char T_3 * V_55 , T_4 V_22 ,
T_5 * V_56 )
{
int V_118 ;
struct V_16 * V_16 = F_97 ( V_6 ) ;
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_75 * V_76 ;
if ( F_15 ( V_2 , V_16 , L_11 ) )
return - V_52 ;
if ( ! V_2 || ( F_62 ( V_119 , & V_2 -> V_43 ) ) )
return - V_52 ;
V_76 = F_98 ( V_2 ) ;
if ( V_76 -> V_41 -> V_120 )
V_118 = V_76 -> V_41 -> V_120 ( V_2 , V_6 , V_55 , V_22 ) ;
else
V_118 = - V_52 ;
F_64 ( V_76 ) ;
if ( V_118 > 0 )
F_94 ( & V_16 -> V_121 ) ;
return V_118 ;
}
static void F_99 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_122 ) ;
F_65 ( & V_2 -> V_79 , V_60 ) ;
}
static int F_100 ( struct V_1 * V_2 , int V_123 )
{
if ( ! F_101 ( & V_2 -> V_122 ) ) {
if ( V_123 )
return - V_124 ;
if ( F_102 ( & V_2 -> V_122 ) )
return - V_54 ;
}
return 0 ;
}
static inline T_2 F_103 (
T_2 (* V_96)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_55 ,
T_4 V_22 )
{
T_2 V_46 , V_125 = 0 ;
unsigned int V_126 ;
V_46 = F_100 ( V_2 , V_6 -> V_127 & V_128 ) ;
if ( V_46 < 0 )
return V_46 ;
V_126 = 2048 ;
if ( F_62 ( V_129 , & V_2 -> V_43 ) )
V_126 = 65536 ;
if ( V_22 < V_126 )
V_126 = V_22 ;
if ( V_2 -> V_130 < V_126 ) {
unsigned char * V_131 ;
if ( V_126 < 1024 )
V_126 = 1024 ;
V_131 = F_6 ( V_126 , V_10 ) ;
if ( ! V_131 ) {
V_46 = - V_11 ;
goto V_132;
}
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_130 = V_126 ;
V_2 -> V_4 = V_131 ;
}
for (; ; ) {
T_4 V_133 = V_22 ;
if ( V_133 > V_126 )
V_133 = V_126 ;
V_46 = - V_134 ;
if ( F_104 ( V_2 -> V_4 , V_55 , V_133 ) )
break;
V_46 = V_96 ( V_2 , V_6 , V_2 -> V_4 , V_133 ) ;
if ( V_46 <= 0 )
break;
V_125 += V_46 ;
V_55 += V_46 ;
V_22 -= V_46 ;
if ( ! V_22 )
break;
V_46 = - V_54 ;
if ( F_105 ( V_47 ) )
break;
F_106 () ;
}
if ( V_125 ) {
F_94 ( & F_97 ( V_6 ) -> V_135 ) ;
V_46 = V_125 ;
}
V_132:
F_99 ( V_2 ) ;
return V_46 ;
}
void F_107 ( struct V_1 * V_2 , char * V_136 )
{
if ( V_2 ) {
F_29 ( & V_2 -> V_122 ) ;
F_71 ( V_2 ) ;
if ( V_2 -> V_41 -> V_96 && V_2 -> V_22 > 0 ) {
F_72 ( V_2 ) ;
V_2 -> V_41 -> V_96 ( V_2 , V_136 , strlen ( V_136 ) ) ;
} else
F_72 ( V_2 ) ;
F_99 ( V_2 ) ;
}
return;
}
static T_2 V_98 ( struct V_6 * V_6 , const char T_3 * V_55 ,
T_4 V_22 , T_5 * V_56 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_75 * V_76 ;
T_2 V_46 ;
if ( F_15 ( V_2 , F_97 ( V_6 ) , L_12 ) )
return - V_52 ;
if ( ! V_2 || ! V_2 -> V_41 -> V_96 ||
( F_62 ( V_119 , & V_2 -> V_43 ) ) )
return - V_52 ;
if ( V_2 -> V_41 -> V_137 == NULL )
F_17 ( V_138 L_13 ,
V_2 -> V_23 -> V_15 ) ;
V_76 = F_98 ( V_2 ) ;
if ( ! V_76 -> V_41 -> V_96 )
V_46 = - V_52 ;
else
V_46 = F_103 ( V_76 -> V_41 -> V_96 , V_2 , V_6 , V_55 , V_22 ) ;
F_64 ( V_76 ) ;
return V_46 ;
}
T_2 V_97 ( struct V_6 * V_6 , const char T_3 * V_55 ,
T_4 V_22 , T_5 * V_56 )
{
struct V_6 * V_21 = NULL ;
F_8 ( & V_92 ) ;
if ( V_93 )
V_21 = F_108 ( V_93 ) ;
F_10 ( & V_92 ) ;
if ( V_21 ) {
T_2 V_35 ;
V_35 = F_109 ( V_21 , V_55 , V_22 , & V_21 -> V_139 ) ;
F_77 ( V_21 ) ;
return V_35 ;
}
return V_98 ( V_6 , V_55 , V_22 , V_56 ) ;
}
int F_110 ( struct V_1 * V_2 , char V_140 )
{
int V_141 = V_2 -> V_110 ;
if ( V_2 -> V_41 -> V_142 ) {
V_2 -> V_41 -> V_142 ( V_2 , V_140 ) ;
return 0 ;
}
if ( F_100 ( V_2 , 0 ) < 0 )
return - V_54 ;
if ( V_141 )
F_93 ( V_2 ) ;
V_2 -> V_41 -> V_96 ( V_2 , & V_140 , 1 ) ;
if ( V_141 )
F_91 ( V_2 ) ;
F_99 ( V_2 ) ;
return 0 ;
}
static void F_111 ( struct V_28 * V_23 , int V_30 , char * V_21 )
{
int V_118 = V_30 + V_23 -> V_143 ;
sprintf ( V_21 , L_14 ,
V_23 -> V_25 == V_26 ? L_15 : V_23 -> V_15 ,
V_144 [ V_118 >> 4 & 0xf ] , V_118 & 0xf ) ;
}
static T_2 F_112 ( struct V_28 * V_23 , int V_30 , char * V_21 )
{
if ( V_23 -> V_43 & V_145 )
return sprintf ( V_21 , L_16 , V_23 -> V_15 ) ;
else
return sprintf ( V_21 , L_17 , V_23 -> V_15 ,
V_30 + V_23 -> V_143 ) ;
}
static struct V_1 * F_113 ( struct V_28 * V_23 ,
struct V_16 * V_16 , int V_146 )
{
struct V_1 * V_2 ;
if ( V_23 -> V_41 -> V_147 )
V_2 = V_23 -> V_41 -> V_147 ( V_23 , V_16 , V_146 ) ;
else
V_2 = V_23 -> V_148 [ V_146 ] ;
if ( ! F_114 ( V_2 ) )
F_53 ( V_2 ) ;
return V_2 ;
}
int F_115 ( struct V_1 * V_2 )
{
struct V_149 * V_150 ;
int V_146 = V_2 -> V_30 ;
if ( V_2 -> V_23 -> V_43 & V_151 )
V_2 -> V_152 = V_2 -> V_23 -> V_153 ;
else {
V_150 = V_2 -> V_23 -> V_152 [ V_146 ] ;
if ( V_150 != NULL )
V_2 -> V_152 = * V_150 ;
else
V_2 -> V_152 = V_2 -> V_23 -> V_153 ;
}
V_2 -> V_152 . V_154 = F_116 ( & V_2 -> V_152 ) ;
V_2 -> V_152 . V_155 = F_117 ( & V_2 -> V_152 ) ;
return 0 ;
}
int F_118 ( struct V_28 * V_23 , struct V_1 * V_2 )
{
int V_46 = F_115 ( V_2 ) ;
if ( V_46 )
return V_46 ;
F_26 ( V_23 ) ;
V_2 -> V_22 ++ ;
V_23 -> V_148 [ V_2 -> V_30 ] = V_2 ;
return 0 ;
}
static int F_119 ( struct V_28 * V_23 ,
struct V_1 * V_2 )
{
return V_23 -> V_41 -> V_156 ? V_23 -> V_41 -> V_156 ( V_23 , V_2 ) :
F_118 ( V_23 , V_2 ) ;
}
void F_120 ( struct V_28 * V_23 , struct V_1 * V_2 )
{
if ( V_23 -> V_41 -> remove )
V_23 -> V_41 -> remove ( V_23 , V_2 ) ;
else
V_23 -> V_148 [ V_2 -> V_30 ] = NULL ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_28 * V_23 = V_2 -> V_23 ;
if ( ! V_2 -> V_22 )
return - V_52 ;
if ( V_23 -> type == V_24 &&
V_23 -> V_25 == V_157 )
return - V_52 ;
if ( F_62 ( V_158 , & V_2 -> V_43 ) && ! F_122 ( V_159 ) )
return - V_160 ;
V_2 -> V_22 ++ ;
F_123 ( ! V_2 -> V_161 ) ;
return 0 ;
}
struct V_1 * F_124 ( struct V_28 * V_23 , int V_146 )
{
struct V_1 * V_2 ;
int V_162 ;
if ( ! F_125 ( V_23 -> V_163 ) )
return F_126 ( - V_164 ) ;
V_2 = F_127 ( V_23 , V_146 ) ;
if ( ! V_2 ) {
V_162 = - V_11 ;
goto V_165;
}
F_71 ( V_2 ) ;
V_162 = F_119 ( V_23 , V_2 ) ;
if ( V_162 < 0 )
goto V_166;
if ( ! V_2 -> V_167 )
V_2 -> V_167 = V_23 -> V_168 [ V_146 ] ;
F_128 ( ! V_2 -> V_167 ,
L_18 ,
V_169 , V_2 -> V_23 -> V_15 ) ;
V_2 -> V_167 -> V_170 = V_2 ;
V_162 = F_129 ( V_2 , V_2 -> V_27 ) ;
if ( V_162 )
goto V_171;
return V_2 ;
V_166:
F_72 ( V_2 ) ;
F_130 ( V_2 ) ;
F_1 ( V_2 ) ;
V_165:
F_131 ( V_23 -> V_163 ) ;
return F_126 ( V_162 ) ;
V_171:
F_72 ( V_2 ) ;
F_132 ( V_172 L_19
L_20 , V_146 ) ;
F_133 ( V_2 , V_146 ) ;
return F_126 ( V_162 ) ;
}
void F_134 ( struct V_1 * V_2 )
{
struct V_149 * V_150 ;
int V_146 = V_2 -> V_30 ;
if ( V_2 -> V_23 -> V_43 & V_151 )
return;
V_150 = V_2 -> V_23 -> V_152 [ V_146 ] ;
if ( V_150 == NULL ) {
V_150 = F_6 ( sizeof( struct V_149 ) , V_10 ) ;
if ( V_150 == NULL ) {
F_135 ( L_21 ) ;
return;
}
V_2 -> V_23 -> V_152 [ V_146 ] = V_150 ;
}
* V_150 = V_2 -> V_152 ;
}
static void F_136 ( struct V_1 * V_2 )
{
F_137 ( & V_2 -> V_173 ) ;
F_137 ( & V_2 -> V_106 ) ;
if ( V_2 -> V_27 ) {
F_137 ( & V_2 -> V_27 -> V_173 ) ;
F_137 ( & V_2 -> V_27 -> V_106 ) ;
}
}
static void F_138 ( struct V_104 * V_105 )
{
struct V_1 * V_2 =
F_79 ( V_105 , struct V_1 , V_106 ) ;
struct V_28 * V_23 = V_2 -> V_23 ;
struct V_174 * V_163 = V_23 -> V_163 ;
if ( V_2 -> V_41 -> V_175 )
V_2 -> V_41 -> V_175 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_139 ( V_23 ) ;
F_131 ( V_163 ) ;
F_8 ( & V_12 ) ;
F_140 ( & V_2 -> V_14 ) ;
F_10 ( & V_12 ) ;
F_49 ( V_2 -> V_45 ) ;
F_49 ( V_2 -> V_72 ) ;
F_1 ( V_2 ) ;
}
static void F_141 ( struct V_176 * V_176 )
{
struct V_1 * V_2 = F_79 ( V_176 , struct V_1 , V_176 ) ;
F_142 ( & V_2 -> V_106 , F_138 ) ;
F_82 ( & V_2 -> V_106 ) ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( V_2 )
F_143 ( & V_2 -> V_176 , F_141 ) ;
}
static void F_133 ( struct V_1 * V_2 , int V_146 )
{
F_123 ( V_2 -> V_30 != V_146 ) ;
F_123 ( ! F_144 ( & V_40 ) ) ;
if ( V_2 -> V_41 -> V_177 )
V_2 -> V_41 -> V_177 ( V_2 ) ;
F_134 ( V_2 ) ;
F_120 ( V_2 -> V_23 , V_2 ) ;
V_2 -> V_167 -> V_170 = NULL ;
if ( V_2 -> V_27 )
V_2 -> V_27 -> V_167 -> V_170 = NULL ;
F_145 ( & V_2 -> V_167 -> V_55 . V_105 ) ;
F_47 ( V_2 -> V_27 ) ;
F_47 ( V_2 ) ;
}
static int F_146 ( struct V_1 * V_2 , int V_146 )
{
#ifdef F_16
if ( V_146 < 0 || V_146 >= V_2 -> V_23 -> V_34 ) {
F_52 ( V_2 , L_22 , V_146 ) ;
return - 1 ;
}
if ( V_2 -> V_23 -> V_43 & V_178 )
return 0 ;
if ( V_2 != V_2 -> V_23 -> V_148 [ V_146 ] ) {
F_52 ( V_2 , L_23 ,
V_146 , V_2 -> V_23 -> V_148 [ V_146 ] ) ;
return - 1 ;
}
if ( V_2 -> V_23 -> V_179 ) {
struct V_1 * V_180 = V_2 -> V_27 ;
if ( V_180 != V_2 -> V_23 -> V_179 -> V_148 [ V_146 ] ) {
F_52 ( V_2 , L_24 ,
V_146 , V_2 -> V_23 -> V_179 -> V_148 [ V_146 ] ) ;
return - 1 ;
}
if ( V_180 -> V_27 != V_2 ) {
F_52 ( V_2 , L_25 , V_180 -> V_27 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_147 ( struct V_16 * V_16 , struct V_6 * V_57 )
{
struct V_1 * V_2 = F_4 ( V_57 ) ;
struct V_1 * V_180 = NULL ;
int V_181 , V_182 ;
int V_146 ;
long V_183 = 0 ;
int V_184 = 1 ;
if ( F_15 ( V_2 , V_16 , V_169 ) )
return 0 ;
F_71 ( V_2 ) ;
F_20 ( V_2 , V_169 ) ;
F_73 ( - 1 , V_57 , 0 ) ;
V_146 = V_2 -> V_30 ;
if ( V_2 -> V_23 -> type == V_24 &&
V_2 -> V_23 -> V_25 == V_157 )
V_180 = V_2 -> V_27 ;
if ( F_146 ( V_2 , V_146 ) ) {
F_72 ( V_2 ) ;
return 0 ;
}
F_81 ( V_2 , L_26 , V_2 -> V_22 ) ;
if ( V_2 -> V_41 -> V_102 )
V_2 -> V_41 -> V_102 ( V_2 , V_57 ) ;
F_148 ( V_180 ) ;
while ( 1 ) {
V_181 = 0 ;
if ( V_2 -> V_22 <= 1 ) {
if ( F_149 ( & V_2 -> V_185 ) ) {
F_150 ( & V_2 -> V_185 , V_59 ) ;
V_181 ++ ;
}
if ( F_149 ( & V_2 -> V_79 ) ) {
F_150 ( & V_2 -> V_79 , V_60 ) ;
V_181 ++ ;
}
}
if ( V_180 && V_180 -> V_22 <= 1 ) {
if ( F_149 ( & V_180 -> V_185 ) ) {
F_150 ( & V_180 -> V_185 , V_59 ) ;
V_181 ++ ;
}
if ( F_149 ( & V_180 -> V_79 ) ) {
F_150 ( & V_180 -> V_79 , V_60 ) ;
V_181 ++ ;
}
}
if ( ! V_181 )
break;
if ( V_184 ) {
V_184 = 0 ;
F_17 ( V_18 L_27 ,
V_169 , F_14 ( V_2 ) ) ;
}
F_151 ( V_183 ) ;
if ( V_183 < 120 * V_186 )
V_183 = 2 * V_183 + 1 ;
else
V_183 = V_187 ;
}
if ( V_180 ) {
if ( -- V_180 -> V_22 < 0 ) {
F_17 ( V_18 L_28 ,
V_169 , V_180 -> V_22 , F_14 ( V_180 ) ) ;
V_180 -> V_22 = 0 ;
}
}
if ( -- V_2 -> V_22 < 0 ) {
F_17 ( V_18 L_29 ,
V_169 , V_2 -> V_22 , F_14 ( V_2 ) ) ;
V_2 -> V_22 = 0 ;
}
F_12 ( V_57 ) ;
if ( ! V_2 -> V_22 ) {
F_67 ( & V_83 ) ;
F_58 ( V_2 -> V_72 ) ;
if ( V_180 )
F_58 ( V_180 -> V_72 ) ;
F_69 ( & V_83 ) ;
}
V_182 = ! V_2 -> V_22 && ! ( V_180 && V_180 -> V_22 ) ;
F_152 ( V_180 ) ;
F_72 ( V_2 ) ;
if ( ! V_182 )
return 0 ;
F_81 ( V_2 , L_30 ) ;
F_153 ( V_2 ) ;
F_136 ( V_2 ) ;
F_81 ( V_2 , L_31 ) ;
F_29 ( & V_40 ) ;
F_133 ( V_2 , V_146 ) ;
F_30 ( & V_40 ) ;
return 0 ;
}
static struct V_1 * F_154 ( T_1 V_29 , struct V_6 * V_57 )
{
struct V_1 * V_2 ;
int V_162 ;
if ( V_29 != F_25 ( V_188 , 0 ) )
return NULL ;
V_2 = F_57 () ;
if ( ! V_2 )
return F_126 ( - V_189 ) ;
V_57 -> V_127 |= V_190 ;
F_71 ( V_2 ) ;
F_47 ( V_2 ) ;
V_162 = F_121 ( V_2 ) ;
if ( V_162 < 0 ) {
F_72 ( V_2 ) ;
V_2 = F_126 ( V_162 ) ;
}
return V_2 ;
}
static struct V_28 * F_155 ( T_1 V_29 , struct V_6 * V_57 ,
int * V_191 , int * V_30 )
{
struct V_28 * V_23 ;
switch ( V_29 ) {
#ifdef F_156
case F_25 ( V_192 , 0 ) : {
extern struct V_28 * V_193 ;
V_23 = F_26 ( V_193 ) ;
* V_30 = V_194 ;
* V_191 = 1 ;
break;
}
#endif
case F_25 ( V_188 , 1 ) : {
struct V_28 * V_193 = F_157 ( V_30 ) ;
if ( V_193 ) {
V_23 = F_26 ( V_193 ) ;
if ( V_23 ) {
V_57 -> V_127 |= V_190 ;
* V_191 = 1 ;
break;
}
}
return F_126 ( - V_164 ) ;
}
default:
V_23 = F_23 ( V_29 , V_30 ) ;
if ( ! V_23 )
return F_126 ( - V_164 ) ;
break;
}
return V_23 ;
}
static int F_158 ( struct V_16 * V_16 , struct V_6 * V_57 )
{
struct V_1 * V_2 ;
int V_191 , V_162 ;
struct V_28 * V_23 = NULL ;
int V_30 ;
T_1 V_29 = V_16 -> V_195 ;
unsigned V_196 = V_57 -> V_127 ;
F_159 ( V_16 , V_57 ) ;
V_197:
V_162 = F_5 ( V_57 ) ;
if ( V_162 )
return - V_11 ;
V_191 = V_57 -> V_127 & V_198 ;
V_30 = - 1 ;
V_162 = 0 ;
V_2 = F_154 ( V_29 , V_57 ) ;
if ( ! V_2 ) {
F_29 ( & V_40 ) ;
V_23 = F_155 ( V_29 , V_57 , & V_191 , & V_30 ) ;
if ( F_114 ( V_23 ) ) {
V_162 = F_160 ( V_23 ) ;
goto V_199;
}
V_2 = F_113 ( V_23 , V_16 , V_30 ) ;
if ( F_114 ( V_2 ) ) {
V_162 = F_160 ( V_2 ) ;
goto V_199;
}
if ( V_2 ) {
F_30 ( & V_40 ) ;
F_71 ( V_2 ) ;
F_47 ( V_2 ) ;
V_162 = F_121 ( V_2 ) ;
if ( V_162 < 0 ) {
F_72 ( V_2 ) ;
V_2 = F_126 ( V_162 ) ;
}
} else {
V_2 = F_124 ( V_23 , V_30 ) ;
F_30 ( & V_40 ) ;
}
F_139 ( V_23 ) ;
}
if ( F_114 ( V_2 ) ) {
V_162 = F_160 ( V_2 ) ;
goto V_200;
}
F_7 ( V_2 , V_57 ) ;
F_20 ( V_2 , V_169 ) ;
if ( V_2 -> V_23 -> type == V_24 &&
V_2 -> V_23 -> V_25 == V_157 )
V_191 = 1 ;
F_81 ( V_2 , L_32 , V_2 -> V_22 ) ;
if ( V_2 -> V_41 -> V_201 )
V_162 = V_2 -> V_41 -> V_201 ( V_2 , V_57 ) ;
else
V_162 = - V_164 ;
V_57 -> V_127 = V_196 ;
if ( V_162 ) {
F_81 ( V_2 , L_33 , V_162 ) ;
F_72 ( V_2 ) ;
F_147 ( V_16 , V_57 ) ;
if ( V_162 != - V_54 )
return V_162 ;
if ( F_105 ( V_47 ) )
return V_162 ;
F_161 () ;
if ( F_86 ( V_57 ) )
V_57 -> V_95 = & V_202 ;
goto V_197;
}
F_75 ( V_94 , & V_2 -> V_43 ) ;
F_67 ( & V_83 ) ;
F_55 ( & V_47 -> V_70 -> V_71 ) ;
if ( ! V_191 &&
V_47 -> signal -> V_84 &&
! V_47 -> signal -> V_2 &&
V_2 -> V_72 == NULL ) {
if ( V_57 -> V_203 & V_204 )
F_48 ( V_2 ) ;
}
F_56 ( & V_47 -> V_70 -> V_71 ) ;
F_69 ( & V_83 ) ;
F_72 ( V_2 ) ;
return 0 ;
V_199:
F_30 ( & V_40 ) ;
if ( ! F_162 ( V_23 ) )
F_139 ( V_23 ) ;
V_200:
F_11 ( V_57 ) ;
return V_162 ;
}
static unsigned int F_163 ( struct V_6 * V_57 , T_6 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_57 ) ;
struct V_75 * V_76 ;
int V_46 = 0 ;
if ( F_15 ( V_2 , F_97 ( V_57 ) , L_34 ) )
return 0 ;
V_76 = F_98 ( V_2 ) ;
if ( V_76 -> V_41 -> V_205 )
V_46 = V_76 -> V_41 -> V_205 ( V_2 , V_57 , V_58 ) ;
F_64 ( V_76 ) ;
return V_46 ;
}
static int F_73 ( int V_206 , struct V_6 * V_57 , int V_207 )
{
struct V_1 * V_2 = F_4 ( V_57 ) ;
struct V_75 * V_161 ;
unsigned long V_43 ;
int V_162 = 0 ;
if ( F_15 ( V_2 , F_97 ( V_57 ) , L_35 ) )
goto V_132;
V_162 = F_164 ( V_206 , V_57 , V_207 , & V_2 -> V_208 ) ;
if ( V_162 <= 0 )
goto V_132;
V_161 = F_63 ( V_2 ) ;
if ( V_161 ) {
if ( V_161 -> V_41 -> V_208 )
V_161 -> V_41 -> V_208 ( V_2 , V_207 ) ;
F_64 ( V_161 ) ;
}
if ( V_207 ) {
enum V_209 type ;
struct V_44 * V_44 ;
F_34 ( & V_2 -> V_48 , V_43 ) ;
if ( V_2 -> V_45 ) {
V_44 = V_2 -> V_45 ;
type = V_210 ;
} else {
V_44 = F_165 ( V_47 ) ;
type = V_211 ;
}
F_50 ( V_44 ) ;
F_35 ( & V_2 -> V_48 , V_43 ) ;
F_166 ( V_57 , V_44 , type , 0 ) ;
F_49 ( V_44 ) ;
V_162 = 0 ;
}
V_132:
return V_162 ;
}
static int F_167 ( int V_206 , struct V_6 * V_57 , int V_207 )
{
struct V_1 * V_2 = F_4 ( V_57 ) ;
int V_162 ;
F_71 ( V_2 ) ;
V_162 = F_73 ( V_206 , V_57 , V_207 ) ;
F_72 ( V_2 ) ;
return V_162 ;
}
static int F_168 ( struct V_1 * V_2 , char T_3 * V_21 )
{
char V_140 , V_212 = 0 ;
struct V_75 * V_76 ;
if ( ( V_47 -> signal -> V_2 != V_2 ) && ! F_122 ( V_159 ) )
return - V_213 ;
if ( F_169 ( V_140 , V_21 ) )
return - V_134 ;
F_170 ( V_2 , V_140 ) ;
V_76 = F_98 ( V_2 ) ;
V_76 -> V_41 -> V_214 ( V_2 , & V_140 , & V_212 , 1 ) ;
F_64 ( V_76 ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 , struct V_215 T_3 * V_66 )
{
int V_216 ;
F_29 ( & V_2 -> V_217 ) ;
V_216 = F_172 ( V_66 , & V_2 -> V_215 , sizeof( * V_66 ) ) ;
F_30 ( & V_2 -> V_217 ) ;
return V_216 ? - V_134 : 0 ;
}
int F_173 ( struct V_1 * V_2 , struct V_215 * V_218 )
{
struct V_44 * V_45 ;
F_29 ( & V_2 -> V_217 ) ;
if ( ! memcmp ( V_218 , & V_2 -> V_215 , sizeof( * V_218 ) ) )
goto V_219;
V_45 = F_88 ( V_2 ) ;
if ( V_45 )
F_38 ( V_45 , V_220 , 1 ) ;
F_49 ( V_45 ) ;
V_2 -> V_215 = * V_218 ;
V_219:
F_30 ( & V_2 -> V_217 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , struct V_215 T_3 * V_66 )
{
struct V_215 V_221 ;
if ( F_104 ( & V_221 , V_66 , sizeof( * V_66 ) ) )
return - V_134 ;
if ( V_2 -> V_41 -> V_222 )
return V_2 -> V_41 -> V_222 ( V_2 , & V_221 ) ;
else
return F_173 ( V_2 , & V_221 ) ;
}
static int F_175 ( struct V_6 * V_6 )
{
if ( ! F_122 ( V_159 ) )
return - V_213 ;
if ( V_6 -> V_95 -> V_96 == V_97 ) {
struct V_6 * V_89 ;
F_8 ( & V_92 ) ;
V_89 = V_93 ;
V_93 = NULL ;
F_10 ( & V_92 ) ;
if ( V_89 )
F_77 ( V_89 ) ;
return 0 ;
}
F_8 ( & V_92 ) ;
if ( V_93 ) {
F_10 ( & V_92 ) ;
return - V_160 ;
}
V_93 = F_108 ( V_6 ) ;
F_10 ( & V_92 ) ;
return 0 ;
}
static int F_176 ( struct V_6 * V_6 , int T_3 * V_21 )
{
int V_223 ;
if ( F_169 ( V_223 , V_21 ) )
return - V_134 ;
F_8 ( & V_6 -> V_224 ) ;
if ( V_223 )
V_6 -> V_127 |= V_190 ;
else
V_6 -> V_127 &= ~ V_190 ;
F_10 ( & V_6 -> V_224 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , struct V_6 * V_6 , int V_66 )
{
int V_46 = 0 ;
F_71 ( V_2 ) ;
F_67 ( & V_83 ) ;
if ( V_47 -> signal -> V_84 && ( F_51 ( V_47 ) == V_2 -> V_72 ) )
goto V_225;
if ( ! V_47 -> signal -> V_84 || V_47 -> signal -> V_2 ) {
V_46 = - V_213 ;
goto V_225;
}
if ( V_2 -> V_72 ) {
if ( V_66 == 1 && F_122 ( V_159 ) ) {
F_58 ( V_2 -> V_72 ) ;
} else {
V_46 = - V_213 ;
goto V_225;
}
}
if ( ( V_6 -> V_203 & V_204 ) == 0 && ! F_122 ( V_159 ) ) {
V_46 = - V_213 ;
goto V_225;
}
F_54 ( V_2 ) ;
V_225:
F_69 ( & V_83 ) ;
F_72 ( V_2 ) ;
return V_46 ;
}
struct V_44 * F_88 ( struct V_1 * V_2 )
{
unsigned long V_43 ;
struct V_44 * V_45 ;
F_34 ( & V_2 -> V_48 , V_43 ) ;
V_45 = F_50 ( V_2 -> V_45 ) ;
F_35 ( & V_2 -> V_48 , V_43 ) ;
return V_45 ;
}
static struct V_44 * F_178 ( struct V_44 * V_45 )
{
struct V_69 * V_21 ;
struct V_44 * V_226 = NULL ;
V_21 = F_179 ( V_45 , V_210 ) ;
if ( V_21 == NULL )
V_21 = F_179 ( V_45 , V_211 ) ;
if ( V_21 != NULL )
V_226 = F_51 ( V_21 ) ;
return V_226 ;
}
static int F_180 ( struct V_1 * V_2 , struct V_1 * V_227 , T_7 T_3 * V_21 )
{
struct V_44 * V_44 ;
int V_46 ;
if ( V_2 == V_227 && V_47 -> signal -> V_2 != V_227 )
return - V_68 ;
V_44 = F_88 ( V_227 ) ;
V_46 = F_181 ( F_182 ( V_44 ) , V_21 ) ;
F_49 ( V_44 ) ;
return V_46 ;
}
static int F_183 ( struct V_1 * V_2 , struct V_1 * V_227 , T_7 T_3 * V_21 )
{
struct V_44 * V_45 ;
T_7 V_228 ;
int V_162 = F_31 ( V_227 ) ;
unsigned long V_43 ;
if ( V_162 == - V_52 )
return - V_68 ;
if ( V_162 )
return V_162 ;
if ( ! V_47 -> signal -> V_2 ||
( V_47 -> signal -> V_2 != V_227 ) ||
( V_227 -> V_72 != F_51 ( V_47 ) ) )
return - V_68 ;
if ( F_169 ( V_228 , V_21 ) )
return - V_134 ;
if ( V_228 < 0 )
return - V_229 ;
F_32 () ;
V_45 = F_184 ( V_228 ) ;
V_162 = - V_230 ;
if ( ! V_45 )
goto V_49;
V_162 = - V_213 ;
if ( F_178 ( V_45 ) != F_51 ( V_47 ) )
goto V_49;
V_162 = 0 ;
F_34 ( & V_2 -> V_48 , V_43 ) ;
F_49 ( V_227 -> V_45 ) ;
V_227 -> V_45 = F_50 ( V_45 ) ;
F_35 ( & V_2 -> V_48 , V_43 ) ;
V_49:
F_39 () ;
return V_162 ;
}
static int F_185 ( struct V_1 * V_2 , struct V_1 * V_227 , T_7 T_3 * V_21 )
{
if ( V_2 == V_227 && V_47 -> signal -> V_2 != V_227 )
return - V_68 ;
if ( ! V_227 -> V_72 )
return - V_68 ;
return F_181 ( F_182 ( V_227 -> V_72 ) , V_21 ) ;
}
static int F_186 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_161 ;
int V_46 ;
if ( F_169 ( V_161 , V_21 ) )
return - V_134 ;
V_46 = F_187 ( V_2 , V_161 ) ;
return V_46 ;
}
static int F_188 ( struct V_1 * V_2 , unsigned int V_231 )
{
int V_162 ;
if ( V_2 -> V_41 -> V_232 == NULL )
return 0 ;
if ( V_2 -> V_23 -> V_43 & V_233 )
V_162 = V_2 -> V_41 -> V_232 ( V_2 , V_231 ) ;
else {
if ( F_100 ( V_2 , 0 ) < 0 )
return - V_234 ;
V_162 = V_2 -> V_41 -> V_232 ( V_2 , - 1 ) ;
if ( V_162 )
goto V_132;
if ( ! F_105 ( V_47 ) )
F_189 ( V_231 ) ;
V_162 = V_2 -> V_41 -> V_232 ( V_2 , 0 ) ;
V_132:
F_99 ( V_2 ) ;
if ( F_105 ( V_47 ) )
V_162 = - V_234 ;
}
return V_162 ;
}
static int F_190 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_162 = - V_229 ;
if ( V_2 -> V_41 -> V_235 ) {
V_162 = V_2 -> V_41 -> V_235 ( V_2 ) ;
if ( V_162 >= 0 )
V_162 = F_181 ( V_162 , V_21 ) ;
}
return V_162 ;
}
static int F_191 ( struct V_1 * V_2 , unsigned int V_65 ,
unsigned T_3 * V_21 )
{
int V_162 ;
unsigned int V_236 , V_237 , V_238 ;
if ( V_2 -> V_41 -> V_239 == NULL )
return - V_229 ;
V_162 = F_169 ( V_238 , V_21 ) ;
if ( V_162 )
return V_162 ;
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
return V_2 -> V_41 -> V_239 ( V_2 , V_236 , V_237 ) ;
}
static int F_192 ( struct V_1 * V_2 , void T_3 * V_66 )
{
int V_162 = - V_229 ;
struct V_248 V_249 ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
if ( V_2 -> V_41 -> V_250 )
V_162 = V_2 -> V_41 -> V_250 ( V_2 , & V_249 ) ;
if ( V_162 != 0 )
return V_162 ;
if ( F_172 ( V_66 , & V_249 , sizeof( V_249 ) ) )
return - V_134 ;
return 0 ;
}
static void F_193 ( struct V_251 T_3 * V_252 )
{
static F_194 ( V_253 ,
V_254 ,
V_255 ) ;
char V_256 [ V_257 ] ;
int V_43 ;
if ( F_169 ( V_43 , & V_252 -> V_43 ) )
return;
V_43 &= V_258 ;
if ( V_43 && F_195 ( & V_253 ) )
F_196 ( L_36 ,
V_169 , F_197 ( V_256 , V_47 ) , V_43 ) ;
}
static struct V_1 * F_198 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 -> type == V_24 &&
V_2 -> V_23 -> V_25 == V_157 )
V_2 = V_2 -> V_27 ;
return V_2 ;
}
long F_199 ( struct V_6 * V_6 , unsigned int V_65 , unsigned long V_66 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_1 * V_227 ;
void T_3 * V_21 = ( void T_3 * ) V_66 ;
int V_162 ;
struct V_75 * V_76 ;
if ( F_15 ( V_2 , F_97 ( V_6 ) , L_37 ) )
return - V_229 ;
V_227 = F_198 ( V_2 ) ;
switch ( V_65 ) {
case V_259 :
case V_260 :
case V_261 :
case V_262 :
case V_263 :
V_162 = F_31 ( V_2 ) ;
if ( V_162 )
return V_162 ;
if ( V_65 != V_261 ) {
F_200 ( V_2 , 0 ) ;
if ( F_105 ( V_47 ) )
return - V_234 ;
}
break;
}
switch ( V_65 ) {
case V_264 :
return F_168 ( V_2 , V_21 ) ;
case V_265 :
return F_171 ( V_227 , V_21 ) ;
case V_266 :
return F_174 ( V_227 , V_21 ) ;
case V_267 :
return V_227 != V_2 ? - V_229 : F_175 ( V_6 ) ;
case V_268 :
return F_176 ( V_6 , V_21 ) ;
case V_269 :
F_76 ( V_158 , & V_2 -> V_43 ) ;
return 0 ;
case V_270 :
F_75 ( V_158 , & V_2 -> V_43 ) ;
return 0 ;
case V_271 :
{
int V_272 = F_62 ( V_158 , & V_2 -> V_43 ) ;
return F_181 ( V_272 , ( int T_3 * ) V_21 ) ;
}
case V_273 :
if ( V_47 -> signal -> V_2 != V_2 )
return - V_68 ;
F_89 () ;
return 0 ;
case V_274 :
return F_177 ( V_2 , V_6 , V_66 ) ;
case V_275 :
return F_180 ( V_2 , V_227 , V_21 ) ;
case V_67 :
return F_183 ( V_2 , V_227 , V_21 ) ;
case V_276 :
return F_185 ( V_2 , V_227 , V_21 ) ;
case V_277 :
return F_181 ( V_2 -> V_161 -> V_41 -> V_34 , ( int T_3 * ) V_21 ) ;
case V_259 :
return F_186 ( V_2 , V_21 ) ;
case V_278 :
if ( ! F_122 ( V_159 ) )
return - V_213 ;
F_83 ( V_2 ) ;
return 0 ;
case V_279 :
{
unsigned int V_46 = F_201 ( F_202 ( V_227 ) ) ;
return F_181 ( V_46 , ( unsigned int T_3 * ) V_21 ) ;
}
case V_260 :
if ( V_2 -> V_41 -> V_232 )
return V_2 -> V_41 -> V_232 ( V_2 , - 1 ) ;
return 0 ;
case V_261 :
if ( V_2 -> V_41 -> V_232 )
return V_2 -> V_41 -> V_232 ( V_2 , 0 ) ;
return 0 ;
case V_262 :
if ( ! V_66 )
return F_188 ( V_2 , 250 ) ;
return 0 ;
case V_263 :
return F_188 ( V_2 , V_66 ? V_66 * 100 : 250 ) ;
case V_280 :
return F_190 ( V_2 , V_21 ) ;
case V_242 :
case V_241 :
case V_240 :
return F_191 ( V_2 , V_65 , V_21 ) ;
case V_281 :
V_162 = F_192 ( V_2 , V_21 ) ;
if ( V_162 != - V_229 )
return V_162 ;
break;
case V_282 :
switch ( V_66 ) {
case V_283 :
case V_284 :
F_203 ( V_2 , NULL ) ;
break;
}
break;
case V_285 :
F_193 ( V_21 ) ;
break;
}
if ( V_2 -> V_41 -> V_286 ) {
V_162 = V_2 -> V_41 -> V_286 ( V_2 , V_65 , V_66 ) ;
if ( V_162 != - V_287 )
return V_162 ;
}
V_76 = F_98 ( V_2 ) ;
V_162 = - V_229 ;
if ( V_76 -> V_41 -> V_286 ) {
V_162 = V_76 -> V_41 -> V_286 ( V_2 , V_6 , V_65 , V_66 ) ;
if ( V_162 == - V_287 )
V_162 = - V_68 ;
}
F_64 ( V_76 ) ;
return V_162 ;
}
static long F_204 ( struct V_6 * V_6 , unsigned int V_65 ,
unsigned long V_66 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_75 * V_76 ;
int V_162 = - V_287 ;
if ( F_15 ( V_2 , F_97 ( V_6 ) , L_37 ) )
return - V_229 ;
if ( V_2 -> V_41 -> V_288 ) {
V_162 = V_2 -> V_41 -> V_288 ( V_2 , V_65 , V_66 ) ;
if ( V_162 != - V_287 )
return V_162 ;
}
V_76 = F_98 ( V_2 ) ;
if ( V_76 -> V_41 -> V_288 )
V_162 = V_76 -> V_41 -> V_288 ( V_2 , V_6 , V_65 , V_66 ) ;
else
V_162 = F_205 ( V_2 , V_6 , V_65 , V_66 ) ;
F_64 ( V_76 ) ;
return V_162 ;
}
static int F_206 ( const void * V_289 , struct V_6 * V_6 , unsigned V_206 )
{
if ( F_207 ( V_6 -> V_95 -> V_120 != F_96 ) )
return 0 ;
return F_4 ( V_6 ) != V_289 ? 0 : V_206 + 1 ;
}
void F_208 ( struct V_1 * V_2 )
{
#ifdef F_209
F_80 ( V_2 ) ;
#else
struct V_69 * V_290 , * V_21 ;
struct V_44 * V_72 ;
int V_118 ;
if ( ! V_2 )
return;
V_72 = V_2 -> V_72 ;
F_210 ( V_2 ) ;
F_211 ( V_2 ) ;
F_67 ( & V_83 ) ;
F_59 (session, PIDTYPE_SID, p) {
F_17 ( V_291 L_38
L_39 ,
F_212 ( V_21 ) , V_21 -> V_256 ) ;
F_213 ( V_292 , V_21 , 1 ) ;
} F_60 ( V_72 , V_74 , V_21 ) ;
F_214 (g, p) {
if ( V_21 -> signal -> V_2 == V_2 ) {
F_17 ( V_291 L_38
L_39 ,
F_212 ( V_21 ) , V_21 -> V_256 ) ;
F_213 ( V_292 , V_21 , 1 ) ;
continue;
}
F_215 ( V_21 ) ;
V_118 = F_216 ( V_21 -> V_293 , 0 , F_206 , V_2 ) ;
if ( V_118 != 0 ) {
F_17 ( V_291 L_38
L_40 ,
F_212 ( V_21 ) , V_21 -> V_256 , V_118 - 1 ) ;
F_217 ( V_292 , V_21 ) ;
}
F_218 ( V_21 ) ;
} F_219 ( V_290 , V_21 ) ;
F_69 ( & V_83 ) ;
#endif
}
static void F_220 ( struct V_104 * V_105 )
{
struct V_1 * V_2 =
F_79 ( V_105 , struct V_1 , V_173 ) ;
F_208 ( V_2 ) ;
}
void F_221 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_82 ( & V_2 -> V_173 ) ;
}
static int F_222 ( struct V_29 * V_3 , const void * V_294 )
{
const T_1 * V_295 = V_294 ;
return V_3 -> V_295 == * V_295 ;
}
static struct V_29 * F_223 ( struct V_1 * V_2 )
{
T_1 V_295 = F_202 ( V_2 ) ;
return F_224 ( V_296 , NULL , & V_295 , F_222 ) ;
}
struct V_1 * F_127 ( struct V_28 * V_23 , int V_146 )
{
struct V_1 * V_2 ;
V_2 = F_225 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_226 ( & V_2 -> V_176 ) ;
V_2 -> V_5 = V_19 ;
F_227 ( V_2 ) ;
V_2 -> V_72 = NULL ;
V_2 -> V_45 = NULL ;
F_228 ( & V_2 -> V_297 ) ;
F_228 ( & V_2 -> V_298 ) ;
F_229 ( & V_2 -> V_299 ) ;
F_228 ( & V_2 -> V_217 ) ;
F_230 ( & V_2 -> V_300 ) ;
F_231 ( & V_2 -> V_79 ) ;
F_231 ( & V_2 -> V_185 ) ;
F_142 ( & V_2 -> V_106 , F_78 ) ;
F_228 ( & V_2 -> V_122 ) ;
F_232 ( & V_2 -> V_48 ) ;
F_232 ( & V_2 -> V_112 ) ;
F_233 ( & V_2 -> V_14 ) ;
F_142 ( & V_2 -> V_173 , F_220 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_41 = V_23 -> V_41 ;
V_2 -> V_30 = V_146 ;
F_112 ( V_23 , V_146 , V_2 -> V_15 ) ;
V_2 -> V_3 = F_223 ( V_2 ) ;
return V_2 ;
}
void F_130 ( struct V_1 * V_2 )
{
F_234 ( V_2 ) ;
}
int F_235 ( struct V_1 * V_2 , unsigned char V_140 )
{
if ( V_2 -> V_41 -> V_301 )
return V_2 -> V_41 -> V_301 ( V_2 , V_140 ) ;
return V_2 -> V_41 -> V_96 ( V_2 , & V_140 , 1 ) ;
}
static int F_236 ( struct V_28 * V_23 , T_1 V_3 ,
unsigned int V_30 , unsigned int V_22 )
{
int V_216 ;
V_23 -> V_302 [ V_30 ] = F_237 () ;
if ( ! V_23 -> V_302 [ V_30 ] )
return - V_11 ;
V_23 -> V_302 [ V_30 ] -> V_41 = & V_202 ;
V_23 -> V_302 [ V_30 ] -> V_163 = V_23 -> V_163 ;
V_216 = F_238 ( V_23 -> V_302 [ V_30 ] , V_3 , V_22 ) ;
if ( V_216 )
F_239 ( & V_23 -> V_302 [ V_30 ] -> V_303 ) ;
return V_216 ;
}
struct V_29 * F_240 ( struct V_28 * V_23 , unsigned V_30 ,
struct V_29 * V_29 )
{
return F_241 ( V_23 , V_30 , V_29 , NULL , NULL ) ;
}
static void F_242 ( struct V_29 * V_3 )
{
F_243 ( L_41 , F_244 ( V_3 ) , V_169 ) ;
F_3 ( V_3 ) ;
}
struct V_29 * F_241 ( struct V_28 * V_23 ,
unsigned V_30 , struct V_29 * V_29 ,
void * V_304 ,
const struct V_305 * * V_306 )
{
char V_15 [ 64 ] ;
T_1 V_295 = F_25 ( V_23 -> V_32 , V_23 -> V_33 ) + V_30 ;
struct V_29 * V_3 = NULL ;
int V_162 = - V_164 ;
bool V_307 = false ;
if ( V_30 >= V_23 -> V_34 ) {
F_17 ( V_138 L_42
L_43 , V_30 ) ;
return F_126 ( - V_229 ) ;
}
if ( V_23 -> type == V_24 )
F_111 ( V_23 , V_30 , V_15 ) ;
else
F_112 ( V_23 , V_30 , V_15 ) ;
if ( ! ( V_23 -> V_43 & V_308 ) ) {
V_162 = F_236 ( V_23 , V_295 , V_30 , 1 ) ;
if ( V_162 )
goto error;
V_307 = true ;
}
V_3 = F_225 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 ) {
V_162 = - V_11 ;
goto error;
}
V_3 -> V_295 = V_295 ;
V_3 -> V_309 = V_296 ;
V_3 -> V_310 = V_29 ;
V_3 -> V_311 = F_242 ;
F_245 ( V_3 , L_16 , V_15 ) ;
V_3 -> V_312 = V_306 ;
F_246 ( V_3 , V_304 ) ;
V_162 = F_247 ( V_3 ) ;
if ( V_162 )
goto error;
return V_3 ;
error:
F_2 ( V_3 ) ;
if ( V_307 ) {
F_248 ( V_23 -> V_302 [ V_30 ] ) ;
V_23 -> V_302 [ V_30 ] = NULL ;
}
return F_126 ( V_162 ) ;
}
void F_249 ( struct V_28 * V_23 , unsigned V_30 )
{
F_250 ( V_296 ,
F_25 ( V_23 -> V_32 , V_23 -> V_33 ) + V_30 ) ;
if ( ! ( V_23 -> V_43 & V_308 ) ) {
F_248 ( V_23 -> V_302 [ V_30 ] ) ;
V_23 -> V_302 [ V_30 ] = NULL ;
}
}
struct V_28 * F_251 ( unsigned int V_313 , struct V_174 * V_163 ,
unsigned long V_43 )
{
struct V_28 * V_23 ;
unsigned int V_302 = 1 ;
int V_216 ;
if ( ! V_313 || ( V_43 & V_145 && V_313 > 1 ) )
return F_126 ( - V_229 ) ;
V_23 = F_225 ( sizeof( struct V_28 ) , V_10 ) ;
if ( ! V_23 )
return F_126 ( - V_11 ) ;
F_226 ( & V_23 -> V_176 ) ;
V_23 -> V_5 = V_314 ;
V_23 -> V_34 = V_313 ;
V_23 -> V_163 = V_163 ;
V_23 -> V_43 = V_43 ;
if ( ! ( V_43 & V_178 ) ) {
V_23 -> V_148 = F_252 ( V_313 , sizeof( * V_23 -> V_148 ) ,
V_10 ) ;
V_23 -> V_152 = F_252 ( V_313 , sizeof( * V_23 -> V_152 ) ,
V_10 ) ;
if ( ! V_23 -> V_148 || ! V_23 -> V_152 ) {
V_216 = - V_11 ;
goto V_315;
}
}
if ( ! ( V_43 & V_308 ) ) {
V_23 -> V_168 = F_252 ( V_313 , sizeof( * V_23 -> V_168 ) ,
V_10 ) ;
if ( ! V_23 -> V_168 ) {
V_216 = - V_11 ;
goto V_315;
}
V_302 = V_313 ;
}
V_23 -> V_302 = F_252 ( V_302 , sizeof( * V_23 -> V_302 ) , V_10 ) ;
if ( ! V_23 -> V_302 ) {
V_216 = - V_11 ;
goto V_315;
}
return V_23 ;
V_315:
F_3 ( V_23 -> V_168 ) ;
F_3 ( V_23 -> V_148 ) ;
F_3 ( V_23 -> V_152 ) ;
F_3 ( V_23 -> V_302 ) ;
F_3 ( V_23 ) ;
return F_126 ( V_216 ) ;
}
static void F_253 ( struct V_176 * V_176 )
{
struct V_28 * V_23 = F_79 ( V_176 , struct V_28 , V_176 ) ;
int V_118 ;
struct V_149 * V_150 ;
if ( V_23 -> V_43 & V_316 ) {
for ( V_118 = 0 ; V_118 < V_23 -> V_34 ; V_118 ++ ) {
V_150 = V_23 -> V_152 [ V_118 ] ;
if ( V_150 ) {
V_23 -> V_152 [ V_118 ] = NULL ;
F_3 ( V_150 ) ;
}
if ( ! ( V_23 -> V_43 & V_317 ) )
F_249 ( V_23 , V_118 ) ;
}
F_254 ( V_23 ) ;
if ( V_23 -> V_43 & V_308 )
F_248 ( V_23 -> V_302 [ 0 ] ) ;
}
F_3 ( V_23 -> V_302 ) ;
F_3 ( V_23 -> V_168 ) ;
F_3 ( V_23 -> V_152 ) ;
F_3 ( V_23 -> V_148 ) ;
F_3 ( V_23 ) ;
}
void F_139 ( struct V_28 * V_23 )
{
F_143 ( & V_23 -> V_176 , F_253 ) ;
}
void F_255 ( struct V_28 * V_23 ,
const struct V_318 * V_319 )
{
V_23 -> V_41 = V_319 ;
}
void F_256 ( struct V_28 * V_320 )
{
F_139 ( V_320 ) ;
}
int F_257 ( struct V_28 * V_23 )
{
int error ;
int V_118 ;
T_1 V_3 ;
struct V_29 * V_320 ;
if ( ! V_23 -> V_32 ) {
error = F_258 ( & V_3 , V_23 -> V_33 ,
V_23 -> V_34 , V_23 -> V_15 ) ;
if ( ! error ) {
V_23 -> V_32 = F_259 ( V_3 ) ;
V_23 -> V_33 = F_260 ( V_3 ) ;
}
} else {
V_3 = F_25 ( V_23 -> V_32 , V_23 -> V_33 ) ;
error = F_261 ( V_3 , V_23 -> V_34 , V_23 -> V_15 ) ;
}
if ( error < 0 )
goto V_216;
if ( V_23 -> V_43 & V_308 ) {
error = F_236 ( V_23 , V_3 , 0 , V_23 -> V_34 ) ;
if ( error )
goto V_321;
}
F_29 ( & V_40 ) ;
F_9 ( & V_23 -> V_322 , & V_322 ) ;
F_30 ( & V_40 ) ;
if ( ! ( V_23 -> V_43 & V_317 ) ) {
for ( V_118 = 0 ; V_118 < V_23 -> V_34 ; V_118 ++ ) {
V_320 = F_240 ( V_23 , V_118 , NULL ) ;
if ( F_114 ( V_320 ) ) {
error = F_160 ( V_320 ) ;
goto V_323;
}
}
}
F_262 ( V_23 ) ;
V_23 -> V_43 |= V_316 ;
return 0 ;
V_323:
for ( V_118 -- ; V_118 >= 0 ; V_118 -- )
F_249 ( V_23 , V_118 ) ;
F_29 ( & V_40 ) ;
F_13 ( & V_23 -> V_322 ) ;
F_30 ( & V_40 ) ;
V_321:
F_263 ( V_3 , V_23 -> V_34 ) ;
V_216:
return error ;
}
int F_264 ( struct V_28 * V_23 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_263 ( F_25 ( V_23 -> V_32 , V_23 -> V_33 ) ,
V_23 -> V_34 ) ;
F_29 ( & V_40 ) ;
F_13 ( & V_23 -> V_322 ) ;
F_30 ( & V_40 ) ;
return 0 ;
}
T_1 F_202 ( struct V_1 * V_2 )
{
return F_25 ( V_2 -> V_23 -> V_32 , V_2 -> V_23 -> V_33 ) + V_2 -> V_30 ;
}
void F_265 ( struct V_324 * V_325 )
{
* V_325 = V_202 ;
}
void T_8 F_266 ( void )
{
T_9 * V_326 ;
F_267 () ;
V_326 = V_327 ;
while ( V_326 < V_328 ) {
(* V_326)() ;
V_326 ++ ;
}
}
static char * F_268 ( struct V_29 * V_3 , T_10 * V_329 )
{
if ( ! V_329 )
return NULL ;
if ( V_3 -> V_295 == F_25 ( V_188 , 0 ) ||
V_3 -> V_295 == F_25 ( V_188 , 2 ) )
* V_329 = 0666 ;
return NULL ;
}
static int T_8 F_269 ( void )
{
V_296 = F_270 ( V_330 , L_15 ) ;
if ( F_114 ( V_296 ) )
return F_160 ( V_296 ) ;
V_296 -> V_331 = F_268 ;
return 0 ;
}
static T_2 F_271 ( struct V_29 * V_3 ,
struct V_332 * V_333 , char * V_55 )
{
struct V_334 * V_335 [ 16 ] ;
int V_118 = 0 ;
struct V_334 * V_336 ;
T_2 V_22 = 0 ;
F_272 () ;
F_273 (c) {
if ( ! V_336 -> V_29 )
continue;
if ( ! V_336 -> V_96 )
continue;
if ( ( V_336 -> V_43 & V_337 ) == 0 )
continue;
V_335 [ V_118 ++ ] = V_336 ;
if ( V_118 >= F_274 ( V_335 ) )
break;
}
while ( V_118 -- ) {
int V_30 = V_335 [ V_118 ] -> V_30 ;
struct V_28 * V_338 = V_335 [ V_118 ] -> V_29 ( V_335 [ V_118 ] , & V_30 ) ;
if ( V_338 && ( V_335 [ V_118 ] -> V_30 > 0 || V_338 -> V_32 != V_192 ) )
V_22 += F_112 ( V_338 , V_30 , V_55 + V_22 ) ;
else
V_22 += sprintf ( V_55 + V_22 , L_17 ,
V_335 [ V_118 ] -> V_15 , V_335 [ V_118 ] -> V_30 ) ;
V_22 += sprintf ( V_55 + V_22 , L_44 , V_118 ? ' ' : '\n' ) ;
}
F_275 () ;
return V_22 ;
}
void F_276 ( void )
{
if ( V_339 )
F_277 ( & V_339 -> V_303 , NULL , L_45 ) ;
}
int T_8 F_278 ( void )
{
F_279 ( & V_340 , & V_202 ) ;
if ( F_238 ( & V_340 , F_25 ( V_188 , 0 ) , 1 ) ||
F_261 ( F_25 ( V_188 , 0 ) , 1 , L_46 ) < 0 )
F_280 ( L_47 ) ;
F_281 ( V_296 , NULL , F_25 ( V_188 , 0 ) , NULL , L_15 ) ;
F_279 ( & V_341 , & V_342 ) ;
if ( F_238 ( & V_341 , F_25 ( V_188 , 1 ) , 1 ) ||
F_261 ( F_25 ( V_188 , 1 ) , 1 , L_48 ) < 0 )
F_280 ( L_49 ) ;
V_339 = F_282 ( V_296 , NULL ,
F_25 ( V_188 , 1 ) , NULL ,
V_343 , L_50 ) ;
if ( F_114 ( V_339 ) )
V_339 = NULL ;
#ifdef F_156
F_283 ( & V_342 ) ;
#endif
return 0 ;
}
