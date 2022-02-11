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
int F_31 ( struct V_1 * V_2 , int V_43 )
{
unsigned long V_44 ;
struct V_45 * V_46 , * V_47 ;
int V_48 = 0 ;
if ( V_49 -> signal -> V_2 != V_2 )
return 0 ;
F_32 () ;
V_46 = F_33 ( V_49 ) ;
F_34 ( & V_2 -> V_50 , V_44 ) ;
V_47 = V_2 -> V_46 ;
F_35 ( & V_2 -> V_50 , V_44 ) ;
if ( V_47 && V_46 != V_2 -> V_46 ) {
if ( F_36 ( V_43 ) ) {
if ( V_43 == V_51 )
V_48 = - V_52 ;
} else if ( F_37 () )
V_48 = - V_52 ;
else {
F_38 ( V_46 , V_43 , 1 ) ;
F_39 ( V_53 ) ;
V_48 = - V_54 ;
}
}
F_40 () ;
if ( ! V_47 ) {
F_41 ( L_6 ,
F_14 ( V_2 ) , V_43 ) ;
}
return V_48 ;
}
int F_42 ( struct V_1 * V_2 )
{
return F_31 ( V_2 , V_55 ) ;
}
static T_2 F_43 ( struct V_6 * V_6 , char T_3 * V_56 ,
T_4 V_22 , T_5 * V_57 )
{
return 0 ;
}
static T_2 F_44 ( struct V_6 * V_6 , const char T_3 * V_56 ,
T_4 V_22 , T_5 * V_57 )
{
return - V_52 ;
}
static unsigned int F_45 ( struct V_6 * V_58 , T_6 * V_59 )
{
return V_60 | V_61 | V_62 | V_63 | V_64 | V_65 ;
}
static long F_46 ( struct V_6 * V_6 , unsigned int V_66 ,
unsigned long V_67 )
{
return V_66 == V_68 ? - V_69 : - V_52 ;
}
static long F_47 ( struct V_6 * V_6 ,
unsigned int V_66 , unsigned long V_67 )
{
return V_66 == V_68 ? - V_69 : - V_52 ;
}
void F_48 ( struct V_70 * V_21 )
{
unsigned long V_44 ;
struct V_1 * V_2 ;
F_34 ( & V_21 -> V_71 -> V_72 , V_44 ) ;
V_2 = V_21 -> signal -> V_2 ;
V_21 -> signal -> V_2 = NULL ;
F_35 ( & V_21 -> V_71 -> V_72 , V_44 ) ;
F_49 ( V_2 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_34 ( & V_2 -> V_50 , V_44 ) ;
F_51 ( V_2 -> V_73 ) ;
F_51 ( V_2 -> V_46 ) ;
V_2 -> V_46 = F_52 ( F_33 ( V_49 ) ) ;
F_35 ( & V_2 -> V_50 , V_44 ) ;
V_2 -> V_73 = F_52 ( F_53 ( V_49 ) ) ;
if ( V_49 -> signal -> V_2 ) {
F_54 ( V_2 , L_7 ,
V_49 -> signal -> V_2 -> V_15 ) ;
F_49 ( V_49 -> signal -> V_2 ) ;
}
F_51 ( V_49 -> signal -> V_74 ) ;
V_49 -> signal -> V_2 = F_55 ( V_2 ) ;
V_49 -> signal -> V_74 = NULL ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_49 -> V_71 -> V_72 ) ;
F_50 ( V_2 ) ;
F_58 ( & V_49 -> V_71 -> V_72 ) ;
}
struct V_1 * F_59 ( void )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
F_34 ( & V_49 -> V_71 -> V_72 , V_44 ) ;
V_2 = F_55 ( V_49 -> signal -> V_2 ) ;
F_35 ( & V_49 -> V_71 -> V_72 , V_44 ) ;
return V_2 ;
}
static void F_60 ( struct V_45 * V_73 )
{
struct V_70 * V_21 ;
F_61 (session, PIDTYPE_SID, p) {
F_48 ( V_21 ) ;
} F_62 ( V_73 , V_75 , V_21 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
if ( F_64 ( V_78 , & V_2 -> V_44 ) ) {
V_77 = F_65 ( V_2 ) ;
if ( V_77 ) {
if ( V_77 -> V_41 -> V_79 )
V_77 -> V_41 -> V_79 ( V_2 ) ;
F_66 ( V_77 ) ;
}
}
F_67 ( & V_2 -> V_80 , V_61 ) ;
}
static int F_68 ( struct V_1 * V_2 , int V_81 )
{
struct V_70 * V_21 ;
int V_82 = 0 ;
struct V_45 * V_47 = NULL ;
F_69 ( & V_83 ) ;
if ( V_2 -> V_73 ) {
F_61 (tty->session, PIDTYPE_SID, p) {
F_57 ( & V_21 -> V_71 -> V_72 ) ;
if ( V_21 -> signal -> V_2 == V_2 ) {
V_21 -> signal -> V_2 = NULL ;
V_82 ++ ;
}
if ( ! V_21 -> signal -> V_84 ) {
F_58 ( & V_21 -> V_71 -> V_72 ) ;
continue;
}
F_70 ( V_85 , V_86 , V_21 ) ;
F_70 ( V_87 , V_86 , V_21 ) ;
F_51 ( V_21 -> signal -> V_74 ) ;
F_8 ( & V_2 -> V_50 ) ;
V_47 = F_52 ( V_2 -> V_46 ) ;
if ( V_2 -> V_46 )
V_21 -> signal -> V_74 = F_52 ( V_2 -> V_46 ) ;
F_10 ( & V_2 -> V_50 ) ;
F_58 ( & V_21 -> V_71 -> V_72 ) ;
} F_62 ( V_2 -> V_73 , V_75 , V_21 ) ;
}
F_71 ( & V_83 ) ;
if ( V_47 ) {
if ( V_81 )
F_38 ( V_47 , V_85 , V_81 ) ;
F_51 ( V_47 ) ;
}
return V_82 ;
}
static void F_72 ( struct V_1 * V_2 , int V_81 )
{
struct V_6 * V_88 = NULL ;
struct V_6 * V_58 , * V_89 = NULL ;
struct V_7 * V_9 ;
int V_90 = 0 , V_91 ;
int V_82 ;
if ( ! V_2 )
return;
F_8 ( & V_92 ) ;
if ( V_93 && F_4 ( V_93 ) == V_2 ) {
V_89 = V_93 ;
V_93 = NULL ;
}
F_10 ( & V_92 ) ;
F_73 ( V_2 ) ;
if ( F_64 ( V_94 , & V_2 -> V_44 ) ) {
F_74 ( V_2 ) ;
return;
}
F_20 ( V_2 , L_8 ) ;
F_8 ( & V_12 ) ;
F_24 (priv, &tty->tty_files, list) {
V_58 = V_9 -> V_6 ;
if ( V_58 -> V_95 -> V_96 == V_97 )
V_88 = V_58 ;
if ( V_58 -> V_95 -> V_96 != V_98 )
continue;
V_90 ++ ;
F_75 ( - 1 , V_58 , 0 ) ;
V_58 -> V_95 = & V_99 ;
}
F_10 ( & V_12 ) ;
V_82 = F_68 ( V_2 , V_81 ) ;
while ( V_82 -- )
F_49 ( V_2 ) ;
F_76 ( V_2 ) ;
F_57 ( & V_2 -> V_50 ) ;
F_77 ( V_100 , & V_2 -> V_44 ) ;
F_77 ( V_78 , & V_2 -> V_44 ) ;
F_51 ( V_2 -> V_73 ) ;
F_51 ( V_2 -> V_46 ) ;
V_2 -> V_73 = NULL ;
V_2 -> V_46 = NULL ;
V_2 -> V_101 = 0 ;
F_58 ( & V_2 -> V_50 ) ;
if ( V_88 ) {
if ( V_2 -> V_41 -> V_102 )
for ( V_91 = 0 ; V_91 < V_90 ; V_91 ++ )
V_2 -> V_41 -> V_102 ( V_2 , V_88 ) ;
} else if ( V_2 -> V_41 -> V_103 )
V_2 -> V_41 -> V_103 ( V_2 ) ;
F_78 ( V_94 , & V_2 -> V_44 ) ;
F_74 ( V_2 ) ;
if ( V_89 )
F_79 ( V_89 ) ;
}
static void F_80 ( struct V_104 * V_105 )
{
struct V_1 * V_2 =
F_81 ( V_105 , struct V_1 , V_106 ) ;
F_72 ( V_2 , 0 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
F_83 ( V_2 , L_9 ) ;
F_84 ( & V_2 -> V_106 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
F_83 ( V_2 , L_9 ) ;
F_72 ( V_2 , 0 ) ;
}
void F_86 ( void )
{
struct V_1 * V_2 ;
V_2 = F_59 () ;
if ( V_2 ) {
F_85 ( V_2 ) ;
F_49 ( V_2 ) ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
F_83 ( V_2 , L_9 ) ;
F_72 ( V_2 , 1 ) ;
}
int F_88 ( struct V_6 * V_58 )
{
return ( V_58 -> V_95 == & V_99 ) ;
}
void F_89 ( int V_107 )
{
struct V_1 * V_2 ;
if ( ! V_49 -> signal -> V_84 )
return;
V_2 = F_59 () ;
if ( V_2 ) {
if ( V_107 && V_2 -> V_23 -> type != V_24 ) {
F_87 ( V_2 ) ;
} else {
struct V_45 * V_47 = F_90 ( V_2 ) ;
if ( V_47 ) {
F_38 ( V_47 , V_85 , V_107 ) ;
if ( ! V_107 )
F_38 ( V_47 , V_87 , V_107 ) ;
F_51 ( V_47 ) ;
}
}
F_49 ( V_2 ) ;
} else if ( V_107 ) {
struct V_45 * V_108 ;
F_57 ( & V_49 -> V_71 -> V_72 ) ;
V_108 = V_49 -> signal -> V_74 ;
V_49 -> signal -> V_74 = NULL ;
F_58 ( & V_49 -> V_71 -> V_72 ) ;
if ( V_108 ) {
F_38 ( V_108 , V_85 , V_107 ) ;
F_38 ( V_108 , V_87 , V_107 ) ;
F_51 ( V_108 ) ;
}
return;
}
F_57 ( & V_49 -> V_71 -> V_72 ) ;
F_51 ( V_49 -> signal -> V_74 ) ;
V_49 -> signal -> V_74 = NULL ;
V_2 = F_55 ( V_49 -> signal -> V_2 ) ;
if ( V_2 ) {
unsigned long V_44 ;
F_34 ( & V_2 -> V_50 , V_44 ) ;
F_51 ( V_2 -> V_73 ) ;
F_51 ( V_2 -> V_46 ) ;
V_2 -> V_73 = NULL ;
V_2 -> V_46 = NULL ;
F_35 ( & V_2 -> V_50 , V_44 ) ;
F_49 ( V_2 ) ;
} else
F_83 ( V_2 , L_10 ) ;
F_58 ( & V_49 -> V_71 -> V_72 ) ;
F_69 ( & V_83 ) ;
F_60 ( F_53 ( V_49 ) ) ;
F_71 ( & V_83 ) ;
}
void F_91 ( void )
{
struct V_70 * V_109 = V_49 ;
F_89 ( 0 ) ;
F_48 ( V_109 ) ;
}
void F_92 ( struct V_1 * V_2 )
{
if ( V_2 -> V_110 )
return;
V_2 -> V_110 = 1 ;
if ( V_2 -> V_41 -> V_111 )
V_2 -> V_41 -> V_111 ( V_2 ) ;
}
void F_93 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_34 ( & V_2 -> V_112 , V_44 ) ;
F_92 ( V_2 ) ;
F_35 ( & V_2 -> V_112 , V_44 ) ;
}
void F_94 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_110 || V_2 -> V_113 )
return;
V_2 -> V_110 = 0 ;
if ( V_2 -> V_41 -> V_114 )
V_2 -> V_41 -> V_114 ( V_2 ) ;
F_63 ( V_2 ) ;
}
void F_95 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_34 ( & V_2 -> V_112 , V_44 ) ;
F_94 ( V_2 ) ;
F_35 ( & V_2 -> V_112 , V_44 ) ;
}
static void F_96 ( struct V_115 * time )
{
unsigned long V_116 = F_97 () ;
if ( ( V_116 ^ time -> V_117 ) & ~ 7 )
time -> V_117 = V_116 ;
}
static T_2 F_98 ( struct V_6 * V_6 , char T_3 * V_56 , T_4 V_22 ,
T_5 * V_57 )
{
int V_118 ;
struct V_16 * V_16 = F_99 ( V_6 ) ;
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_76 * V_77 ;
if ( F_15 ( V_2 , V_16 , L_11 ) )
return - V_52 ;
if ( ! V_2 || ( F_64 ( V_119 , & V_2 -> V_44 ) ) )
return - V_52 ;
V_77 = F_100 ( V_2 ) ;
if ( V_77 -> V_41 -> V_120 )
V_118 = V_77 -> V_41 -> V_120 ( V_2 , V_6 , V_56 , V_22 ) ;
else
V_118 = - V_52 ;
F_66 ( V_77 ) ;
if ( V_118 > 0 )
F_96 ( & V_16 -> V_121 ) ;
return V_118 ;
}
static void F_101 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_122 ) ;
F_67 ( & V_2 -> V_80 , V_61 ) ;
}
static int F_102 ( struct V_1 * V_2 , int V_123 )
{
if ( ! F_103 ( & V_2 -> V_122 ) ) {
if ( V_123 )
return - V_124 ;
if ( F_104 ( & V_2 -> V_122 ) )
return - V_54 ;
}
return 0 ;
}
static inline T_2 F_105 (
T_2 (* V_96)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_56 ,
T_4 V_22 )
{
T_2 V_48 , V_125 = 0 ;
unsigned int V_126 ;
V_48 = F_102 ( V_2 , V_6 -> V_127 & V_128 ) ;
if ( V_48 < 0 )
return V_48 ;
V_126 = 2048 ;
if ( F_64 ( V_129 , & V_2 -> V_44 ) )
V_126 = 65536 ;
if ( V_22 < V_126 )
V_126 = V_22 ;
if ( V_2 -> V_130 < V_126 ) {
unsigned char * V_131 ;
if ( V_126 < 1024 )
V_126 = 1024 ;
V_131 = F_6 ( V_126 , V_10 ) ;
if ( ! V_131 ) {
V_48 = - V_11 ;
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
V_48 = - V_134 ;
if ( F_106 ( V_2 -> V_4 , V_56 , V_133 ) )
break;
V_48 = V_96 ( V_2 , V_6 , V_2 -> V_4 , V_133 ) ;
if ( V_48 <= 0 )
break;
V_125 += V_48 ;
V_56 += V_48 ;
V_22 -= V_48 ;
if ( ! V_22 )
break;
V_48 = - V_54 ;
if ( F_107 ( V_49 ) )
break;
F_108 () ;
}
if ( V_125 ) {
F_96 ( & F_99 ( V_6 ) -> V_135 ) ;
V_48 = V_125 ;
}
V_132:
F_101 ( V_2 ) ;
return V_48 ;
}
void F_109 ( struct V_1 * V_2 , char * V_136 )
{
if ( V_2 ) {
F_29 ( & V_2 -> V_122 ) ;
F_73 ( V_2 ) ;
if ( V_2 -> V_41 -> V_96 && V_2 -> V_22 > 0 )
V_2 -> V_41 -> V_96 ( V_2 , V_136 , strlen ( V_136 ) ) ;
F_74 ( V_2 ) ;
F_101 ( V_2 ) ;
}
return;
}
static T_2 V_98 ( struct V_6 * V_6 , const char T_3 * V_56 ,
T_4 V_22 , T_5 * V_57 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_76 * V_77 ;
T_2 V_48 ;
if ( F_15 ( V_2 , F_99 ( V_6 ) , L_12 ) )
return - V_52 ;
if ( ! V_2 || ! V_2 -> V_41 -> V_96 ||
( F_64 ( V_119 , & V_2 -> V_44 ) ) )
return - V_52 ;
if ( V_2 -> V_41 -> V_137 == NULL )
F_17 ( V_138 L_13 ,
V_2 -> V_23 -> V_15 ) ;
V_77 = F_100 ( V_2 ) ;
if ( ! V_77 -> V_41 -> V_96 )
V_48 = - V_52 ;
else
V_48 = F_105 ( V_77 -> V_41 -> V_96 , V_2 , V_6 , V_56 , V_22 ) ;
F_66 ( V_77 ) ;
return V_48 ;
}
T_2 V_97 ( struct V_6 * V_6 , const char T_3 * V_56 ,
T_4 V_22 , T_5 * V_57 )
{
struct V_6 * V_21 = NULL ;
F_8 ( & V_92 ) ;
if ( V_93 )
V_21 = F_110 ( V_93 ) ;
F_10 ( & V_92 ) ;
if ( V_21 ) {
T_2 V_35 ;
V_35 = F_111 ( V_21 , V_56 , V_22 , & V_21 -> V_139 ) ;
F_79 ( V_21 ) ;
return V_35 ;
}
return V_98 ( V_6 , V_56 , V_22 , V_57 ) ;
}
int F_112 ( struct V_1 * V_2 , char V_140 )
{
int V_141 = V_2 -> V_110 ;
if ( V_2 -> V_41 -> V_142 ) {
F_113 ( & V_2 -> V_143 ) ;
V_2 -> V_41 -> V_142 ( V_2 , V_140 ) ;
F_114 ( & V_2 -> V_143 ) ;
return 0 ;
}
if ( F_102 ( V_2 , 0 ) < 0 )
return - V_54 ;
F_113 ( & V_2 -> V_143 ) ;
if ( V_141 )
F_95 ( V_2 ) ;
V_2 -> V_41 -> V_96 ( V_2 , & V_140 , 1 ) ;
if ( V_141 )
F_93 ( V_2 ) ;
F_114 ( & V_2 -> V_143 ) ;
F_101 ( V_2 ) ;
return 0 ;
}
static void F_115 ( struct V_28 * V_23 , int V_30 , char * V_21 )
{
int V_118 = V_30 + V_23 -> V_144 ;
sprintf ( V_21 , L_14 ,
V_23 -> V_25 == V_26 ? L_15 : V_23 -> V_15 ,
V_145 [ V_118 >> 4 & 0xf ] , V_118 & 0xf ) ;
}
static T_2 F_116 ( struct V_28 * V_23 , int V_30 , char * V_21 )
{
if ( V_23 -> V_44 & V_146 )
return sprintf ( V_21 , L_16 , V_23 -> V_15 ) ;
else
return sprintf ( V_21 , L_17 , V_23 -> V_15 ,
V_30 + V_23 -> V_144 ) ;
}
static struct V_1 * F_117 ( struct V_28 * V_23 ,
struct V_16 * V_16 , int V_147 )
{
struct V_1 * V_2 ;
if ( V_23 -> V_41 -> V_148 )
V_2 = V_23 -> V_41 -> V_148 ( V_23 , V_16 , V_147 ) ;
else
V_2 = V_23 -> V_149 [ V_147 ] ;
if ( ! F_118 ( V_2 ) )
F_55 ( V_2 ) ;
return V_2 ;
}
int F_119 ( struct V_1 * V_2 )
{
struct V_150 * V_151 ;
int V_147 = V_2 -> V_30 ;
if ( V_2 -> V_23 -> V_44 & V_152 )
V_2 -> V_153 = V_2 -> V_23 -> V_154 ;
else {
V_151 = V_2 -> V_23 -> V_153 [ V_147 ] ;
if ( V_151 != NULL )
V_2 -> V_153 = * V_151 ;
else
V_2 -> V_153 = V_2 -> V_23 -> V_154 ;
}
V_2 -> V_153 . V_155 = F_120 ( & V_2 -> V_153 ) ;
V_2 -> V_153 . V_156 = F_121 ( & V_2 -> V_153 ) ;
return 0 ;
}
int F_122 ( struct V_28 * V_23 , struct V_1 * V_2 )
{
int V_48 = F_119 ( V_2 ) ;
if ( V_48 )
return V_48 ;
F_26 ( V_23 ) ;
V_2 -> V_22 ++ ;
V_23 -> V_149 [ V_2 -> V_30 ] = V_2 ;
return 0 ;
}
static int F_123 ( struct V_28 * V_23 ,
struct V_1 * V_2 )
{
return V_23 -> V_41 -> V_157 ? V_23 -> V_41 -> V_157 ( V_23 , V_2 ) :
F_122 ( V_23 , V_2 ) ;
}
void F_124 ( struct V_28 * V_23 , struct V_1 * V_2 )
{
if ( V_23 -> V_41 -> remove )
V_23 -> V_41 -> remove ( V_23 , V_2 ) ;
else
V_23 -> V_149 [ V_2 -> V_30 ] = NULL ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_28 * V_23 = V_2 -> V_23 ;
if ( ! V_2 -> V_22 )
return - V_52 ;
if ( V_23 -> type == V_24 &&
V_23 -> V_25 == V_158 )
return - V_52 ;
if ( F_64 ( V_159 , & V_2 -> V_44 ) && ! F_126 ( V_160 ) )
return - V_161 ;
V_2 -> V_22 ++ ;
F_127 ( ! V_2 -> V_162 ) ;
return 0 ;
}
struct V_1 * F_128 ( struct V_28 * V_23 , int V_147 )
{
struct V_1 * V_2 ;
int V_163 ;
if ( ! F_129 ( V_23 -> V_164 ) )
return F_130 ( - V_165 ) ;
V_2 = F_131 ( V_23 , V_147 ) ;
if ( ! V_2 ) {
V_163 = - V_11 ;
goto V_166;
}
F_73 ( V_2 ) ;
V_163 = F_123 ( V_23 , V_2 ) ;
if ( V_163 < 0 )
goto V_167;
if ( ! V_2 -> V_168 )
V_2 -> V_168 = V_23 -> V_169 [ V_147 ] ;
F_132 ( ! V_2 -> V_168 ,
L_18 ,
V_170 , V_2 -> V_23 -> V_15 ) ;
V_2 -> V_168 -> V_171 = V_2 ;
V_163 = F_133 ( V_2 , V_2 -> V_27 ) ;
if ( V_163 )
goto V_172;
return V_2 ;
V_167:
F_74 ( V_2 ) ;
F_134 ( V_2 ) ;
F_1 ( V_2 ) ;
V_166:
F_135 ( V_23 -> V_164 ) ;
return F_130 ( V_163 ) ;
V_172:
F_74 ( V_2 ) ;
F_136 ( V_173 L_19
L_20 , V_147 ) ;
F_137 ( V_2 , V_147 ) ;
return F_130 ( V_163 ) ;
}
void F_138 ( struct V_1 * V_2 )
{
struct V_150 * V_151 ;
int V_147 = V_2 -> V_30 ;
if ( V_2 -> V_23 -> V_44 & V_152 )
return;
V_151 = V_2 -> V_23 -> V_153 [ V_147 ] ;
if ( V_151 == NULL ) {
V_151 = F_6 ( sizeof( struct V_150 ) , V_10 ) ;
if ( V_151 == NULL ) {
F_41 ( L_21 ) ;
return;
}
V_2 -> V_23 -> V_153 [ V_147 ] = V_151 ;
}
* V_151 = V_2 -> V_153 ;
}
static void F_139 ( struct V_1 * V_2 )
{
F_140 ( & V_2 -> V_174 ) ;
F_140 ( & V_2 -> V_106 ) ;
if ( V_2 -> V_27 ) {
F_140 ( & V_2 -> V_27 -> V_174 ) ;
F_140 ( & V_2 -> V_27 -> V_106 ) ;
}
}
static void F_141 ( struct V_104 * V_105 )
{
struct V_1 * V_2 =
F_81 ( V_105 , struct V_1 , V_106 ) ;
struct V_28 * V_23 = V_2 -> V_23 ;
struct V_175 * V_164 = V_23 -> V_164 ;
if ( V_2 -> V_41 -> V_176 )
V_2 -> V_41 -> V_176 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_142 ( V_23 ) ;
F_135 ( V_164 ) ;
F_8 ( & V_12 ) ;
F_143 ( & V_2 -> V_14 ) ;
F_10 ( & V_12 ) ;
F_51 ( V_2 -> V_46 ) ;
F_51 ( V_2 -> V_73 ) ;
F_1 ( V_2 ) ;
}
static void F_144 ( struct V_177 * V_177 )
{
struct V_1 * V_2 = F_81 ( V_177 , struct V_1 , V_177 ) ;
F_145 ( & V_2 -> V_106 , F_141 ) ;
F_84 ( & V_2 -> V_106 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
if ( V_2 )
F_146 ( & V_2 -> V_177 , F_144 ) ;
}
static void F_137 ( struct V_1 * V_2 , int V_147 )
{
F_127 ( V_2 -> V_30 != V_147 ) ;
F_127 ( ! F_147 ( & V_40 ) ) ;
if ( V_2 -> V_41 -> V_178 )
V_2 -> V_41 -> V_178 ( V_2 ) ;
F_138 ( V_2 ) ;
F_124 ( V_2 -> V_23 , V_2 ) ;
V_2 -> V_168 -> V_171 = NULL ;
if ( V_2 -> V_27 )
V_2 -> V_27 -> V_168 -> V_171 = NULL ;
F_148 ( V_2 -> V_168 ) ;
F_49 ( V_2 -> V_27 ) ;
F_49 ( V_2 ) ;
}
static int F_149 ( struct V_1 * V_2 , int V_147 )
{
#ifdef F_16
if ( V_147 < 0 || V_147 >= V_2 -> V_23 -> V_34 ) {
F_54 ( V_2 , L_22 , V_147 ) ;
return - 1 ;
}
if ( V_2 -> V_23 -> V_44 & V_179 )
return 0 ;
if ( V_2 != V_2 -> V_23 -> V_149 [ V_147 ] ) {
F_54 ( V_2 , L_23 ,
V_147 , V_2 -> V_23 -> V_149 [ V_147 ] ) ;
return - 1 ;
}
if ( V_2 -> V_23 -> V_180 ) {
struct V_1 * V_181 = V_2 -> V_27 ;
if ( V_181 != V_2 -> V_23 -> V_180 -> V_149 [ V_147 ] ) {
F_54 ( V_2 , L_24 ,
V_147 , V_2 -> V_23 -> V_180 -> V_149 [ V_147 ] ) ;
return - 1 ;
}
if ( V_181 -> V_27 != V_2 ) {
F_54 ( V_2 , L_25 , V_181 -> V_27 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_150 ( struct V_16 * V_16 , struct V_6 * V_58 )
{
struct V_1 * V_2 = F_4 ( V_58 ) ;
struct V_1 * V_181 = NULL ;
int V_182 , V_183 ;
int V_147 ;
long V_184 = 0 ;
int V_185 = 1 ;
if ( F_15 ( V_2 , V_16 , V_170 ) )
return 0 ;
F_73 ( V_2 ) ;
F_20 ( V_2 , V_170 ) ;
F_75 ( - 1 , V_58 , 0 ) ;
V_147 = V_2 -> V_30 ;
if ( V_2 -> V_23 -> type == V_24 &&
V_2 -> V_23 -> V_25 == V_158 )
V_181 = V_2 -> V_27 ;
if ( F_149 ( V_2 , V_147 ) ) {
F_74 ( V_2 ) ;
return 0 ;
}
F_83 ( V_2 , L_26 , V_2 -> V_22 ) ;
if ( V_2 -> V_41 -> V_102 )
V_2 -> V_41 -> V_102 ( V_2 , V_58 ) ;
F_151 ( V_181 ) ;
while ( 1 ) {
V_182 = 0 ;
if ( V_2 -> V_22 <= 1 ) {
if ( F_152 ( & V_2 -> V_186 ) ) {
F_153 ( & V_2 -> V_186 , V_60 ) ;
V_182 ++ ;
}
if ( F_152 ( & V_2 -> V_80 ) ) {
F_153 ( & V_2 -> V_80 , V_61 ) ;
V_182 ++ ;
}
}
if ( V_181 && V_181 -> V_22 <= 1 ) {
if ( F_152 ( & V_181 -> V_186 ) ) {
F_153 ( & V_181 -> V_186 , V_60 ) ;
V_182 ++ ;
}
if ( F_152 ( & V_181 -> V_80 ) ) {
F_153 ( & V_181 -> V_80 , V_61 ) ;
V_182 ++ ;
}
}
if ( ! V_182 )
break;
if ( V_185 ) {
V_185 = 0 ;
F_17 ( V_18 L_27 ,
V_170 , F_14 ( V_2 ) ) ;
}
F_154 ( V_184 ) ;
if ( V_184 < 120 * V_187 )
V_184 = 2 * V_184 + 1 ;
else
V_184 = V_188 ;
}
if ( V_181 ) {
if ( -- V_181 -> V_22 < 0 ) {
F_17 ( V_18 L_28 ,
V_170 , V_181 -> V_22 , F_14 ( V_181 ) ) ;
V_181 -> V_22 = 0 ;
}
}
if ( -- V_2 -> V_22 < 0 ) {
F_17 ( V_18 L_29 ,
V_170 , V_2 -> V_22 , F_14 ( V_2 ) ) ;
V_2 -> V_22 = 0 ;
}
F_12 ( V_58 ) ;
if ( ! V_2 -> V_22 ) {
F_69 ( & V_83 ) ;
F_60 ( V_2 -> V_73 ) ;
if ( V_181 )
F_60 ( V_181 -> V_73 ) ;
F_71 ( & V_83 ) ;
}
V_183 = ! V_2 -> V_22 && ! ( V_181 && V_181 -> V_22 ) ;
F_155 ( V_181 ) ;
F_74 ( V_2 ) ;
if ( ! V_183 )
return 0 ;
F_83 ( V_2 , L_30 ) ;
F_156 ( V_2 ) ;
F_139 ( V_2 ) ;
F_83 ( V_2 , L_31 ) ;
F_29 ( & V_40 ) ;
F_137 ( V_2 , V_147 ) ;
F_30 ( & V_40 ) ;
return 0 ;
}
static struct V_1 * F_157 ( T_1 V_29 , struct V_6 * V_58 )
{
struct V_1 * V_2 ;
int V_163 ;
if ( V_29 != F_25 ( V_189 , 0 ) )
return NULL ;
V_2 = F_59 () ;
if ( ! V_2 )
return F_130 ( - V_190 ) ;
V_58 -> V_127 |= V_191 ;
F_73 ( V_2 ) ;
F_49 ( V_2 ) ;
V_163 = F_125 ( V_2 ) ;
if ( V_163 < 0 ) {
F_74 ( V_2 ) ;
V_2 = F_130 ( V_163 ) ;
}
return V_2 ;
}
static struct V_28 * F_158 ( T_1 V_29 , struct V_6 * V_58 ,
int * V_192 , int * V_30 )
{
struct V_28 * V_23 ;
switch ( V_29 ) {
#ifdef F_159
case F_25 ( V_193 , 0 ) : {
extern struct V_28 * V_194 ;
V_23 = F_26 ( V_194 ) ;
* V_30 = V_195 ;
* V_192 = 1 ;
break;
}
#endif
case F_25 ( V_189 , 1 ) : {
struct V_28 * V_194 = F_160 ( V_30 ) ;
if ( V_194 ) {
V_23 = F_26 ( V_194 ) ;
if ( V_23 ) {
V_58 -> V_127 |= V_191 ;
* V_192 = 1 ;
break;
}
}
return F_130 ( - V_165 ) ;
}
default:
V_23 = F_23 ( V_29 , V_30 ) ;
if ( ! V_23 )
return F_130 ( - V_165 ) ;
break;
}
return V_23 ;
}
static int F_161 ( struct V_16 * V_16 , struct V_6 * V_58 )
{
struct V_1 * V_2 ;
int V_192 , V_163 ;
struct V_28 * V_23 = NULL ;
int V_30 ;
T_1 V_29 = V_16 -> V_196 ;
unsigned V_197 = V_58 -> V_127 ;
F_162 ( V_16 , V_58 ) ;
V_198:
V_163 = F_5 ( V_58 ) ;
if ( V_163 )
return - V_11 ;
V_192 = V_58 -> V_127 & V_199 ;
V_30 = - 1 ;
V_163 = 0 ;
V_2 = F_157 ( V_29 , V_58 ) ;
if ( ! V_2 ) {
F_29 ( & V_40 ) ;
V_23 = F_158 ( V_29 , V_58 , & V_192 , & V_30 ) ;
if ( F_118 ( V_23 ) ) {
V_163 = F_163 ( V_23 ) ;
goto V_200;
}
V_2 = F_117 ( V_23 , V_16 , V_30 ) ;
if ( F_118 ( V_2 ) ) {
V_163 = F_163 ( V_2 ) ;
goto V_200;
}
if ( V_2 ) {
F_30 ( & V_40 ) ;
F_73 ( V_2 ) ;
F_49 ( V_2 ) ;
V_163 = F_125 ( V_2 ) ;
if ( V_163 < 0 ) {
F_74 ( V_2 ) ;
V_2 = F_130 ( V_163 ) ;
}
} else {
V_2 = F_128 ( V_23 , V_30 ) ;
F_30 ( & V_40 ) ;
}
F_142 ( V_23 ) ;
}
if ( F_118 ( V_2 ) ) {
V_163 = F_163 ( V_2 ) ;
goto V_201;
}
F_7 ( V_2 , V_58 ) ;
F_20 ( V_2 , V_170 ) ;
if ( V_2 -> V_23 -> type == V_24 &&
V_2 -> V_23 -> V_25 == V_158 )
V_192 = 1 ;
F_83 ( V_2 , L_32 , V_2 -> V_22 ) ;
if ( V_2 -> V_41 -> V_202 )
V_163 = V_2 -> V_41 -> V_202 ( V_2 , V_58 ) ;
else
V_163 = - V_165 ;
V_58 -> V_127 = V_197 ;
if ( V_163 ) {
F_83 ( V_2 , L_33 , V_163 ) ;
F_74 ( V_2 ) ;
F_150 ( V_16 , V_58 ) ;
if ( V_163 != - V_54 )
return V_163 ;
if ( F_107 ( V_49 ) )
return V_163 ;
F_164 () ;
if ( F_88 ( V_58 ) )
V_58 -> V_95 = & V_203 ;
goto V_198;
}
F_77 ( V_94 , & V_2 -> V_44 ) ;
F_69 ( & V_83 ) ;
F_57 ( & V_49 -> V_71 -> V_72 ) ;
if ( ! V_192 &&
V_49 -> signal -> V_84 &&
! V_49 -> signal -> V_2 &&
V_2 -> V_73 == NULL ) {
if ( V_58 -> V_204 & V_205 )
F_50 ( V_2 ) ;
}
F_58 ( & V_49 -> V_71 -> V_72 ) ;
F_71 ( & V_83 ) ;
F_74 ( V_2 ) ;
return 0 ;
V_200:
F_30 ( & V_40 ) ;
if ( ! F_165 ( V_23 ) )
F_142 ( V_23 ) ;
V_201:
F_11 ( V_58 ) ;
return V_163 ;
}
static unsigned int F_166 ( struct V_6 * V_58 , T_6 * V_59 )
{
struct V_1 * V_2 = F_4 ( V_58 ) ;
struct V_76 * V_77 ;
int V_48 = 0 ;
if ( F_15 ( V_2 , F_99 ( V_58 ) , L_34 ) )
return 0 ;
V_77 = F_100 ( V_2 ) ;
if ( V_77 -> V_41 -> V_206 )
V_48 = V_77 -> V_41 -> V_206 ( V_2 , V_58 , V_59 ) ;
F_66 ( V_77 ) ;
return V_48 ;
}
static int F_75 ( int V_207 , struct V_6 * V_58 , int V_208 )
{
struct V_1 * V_2 = F_4 ( V_58 ) ;
struct V_76 * V_162 ;
unsigned long V_44 ;
int V_163 = 0 ;
if ( F_15 ( V_2 , F_99 ( V_58 ) , L_35 ) )
goto V_132;
V_163 = F_167 ( V_207 , V_58 , V_208 , & V_2 -> V_209 ) ;
if ( V_163 <= 0 )
goto V_132;
V_162 = F_65 ( V_2 ) ;
if ( V_162 ) {
if ( V_162 -> V_41 -> V_209 )
V_162 -> V_41 -> V_209 ( V_2 , V_208 ) ;
F_66 ( V_162 ) ;
}
if ( V_208 ) {
enum V_210 type ;
struct V_45 * V_45 ;
F_34 ( & V_2 -> V_50 , V_44 ) ;
if ( V_2 -> V_46 ) {
V_45 = V_2 -> V_46 ;
type = V_211 ;
} else {
V_45 = F_168 ( V_49 ) ;
type = V_212 ;
}
F_52 ( V_45 ) ;
F_35 ( & V_2 -> V_50 , V_44 ) ;
F_169 ( V_58 , V_45 , type , 0 ) ;
F_51 ( V_45 ) ;
V_163 = 0 ;
}
V_132:
return V_163 ;
}
static int F_170 ( int V_207 , struct V_6 * V_58 , int V_208 )
{
struct V_1 * V_2 = F_4 ( V_58 ) ;
int V_163 ;
F_73 ( V_2 ) ;
V_163 = F_75 ( V_207 , V_58 , V_208 ) ;
F_74 ( V_2 ) ;
return V_163 ;
}
static int F_171 ( struct V_1 * V_2 , char T_3 * V_21 )
{
char V_140 , V_213 = 0 ;
struct V_76 * V_77 ;
if ( ( V_49 -> signal -> V_2 != V_2 ) && ! F_126 ( V_160 ) )
return - V_214 ;
if ( F_172 ( V_140 , V_21 ) )
return - V_134 ;
F_173 ( V_2 , V_140 ) ;
V_77 = F_100 ( V_2 ) ;
V_77 -> V_41 -> V_215 ( V_2 , & V_140 , & V_213 , 1 ) ;
F_66 ( V_77 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , struct V_216 T_3 * V_67 )
{
int V_217 ;
F_29 ( & V_2 -> V_218 ) ;
V_217 = F_175 ( V_67 , & V_2 -> V_216 , sizeof( * V_67 ) ) ;
F_30 ( & V_2 -> V_218 ) ;
return V_217 ? - V_134 : 0 ;
}
int F_176 ( struct V_1 * V_2 , struct V_216 * V_219 )
{
struct V_45 * V_46 ;
F_29 ( & V_2 -> V_218 ) ;
if ( ! memcmp ( V_219 , & V_2 -> V_216 , sizeof( * V_219 ) ) )
goto V_220;
V_46 = F_90 ( V_2 ) ;
if ( V_46 )
F_38 ( V_46 , V_221 , 1 ) ;
F_51 ( V_46 ) ;
V_2 -> V_216 = * V_219 ;
V_220:
F_30 ( & V_2 -> V_218 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , struct V_216 T_3 * V_67 )
{
struct V_216 V_222 ;
if ( F_106 ( & V_222 , V_67 , sizeof( * V_67 ) ) )
return - V_134 ;
if ( V_2 -> V_41 -> V_223 )
return V_2 -> V_41 -> V_223 ( V_2 , & V_222 ) ;
else
return F_176 ( V_2 , & V_222 ) ;
}
static int F_178 ( struct V_6 * V_6 )
{
if ( ! F_126 ( V_160 ) )
return - V_214 ;
if ( V_6 -> V_95 -> V_96 == V_97 ) {
struct V_6 * V_89 ;
F_8 ( & V_92 ) ;
V_89 = V_93 ;
V_93 = NULL ;
F_10 ( & V_92 ) ;
if ( V_89 )
F_79 ( V_89 ) ;
return 0 ;
}
F_8 ( & V_92 ) ;
if ( V_93 ) {
F_10 ( & V_92 ) ;
return - V_161 ;
}
V_93 = F_110 ( V_6 ) ;
F_10 ( & V_92 ) ;
return 0 ;
}
static int F_179 ( struct V_6 * V_6 , int T_3 * V_21 )
{
int V_224 ;
if ( F_172 ( V_224 , V_21 ) )
return - V_134 ;
F_8 ( & V_6 -> V_225 ) ;
if ( V_224 )
V_6 -> V_127 |= V_191 ;
else
V_6 -> V_127 &= ~ V_191 ;
F_10 ( & V_6 -> V_225 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 , struct V_6 * V_6 , int V_67 )
{
int V_48 = 0 ;
F_73 ( V_2 ) ;
F_69 ( & V_83 ) ;
if ( V_49 -> signal -> V_84 && ( F_53 ( V_49 ) == V_2 -> V_73 ) )
goto V_226;
if ( ! V_49 -> signal -> V_84 || V_49 -> signal -> V_2 ) {
V_48 = - V_214 ;
goto V_226;
}
if ( V_2 -> V_73 ) {
if ( V_67 == 1 && F_126 ( V_160 ) ) {
F_60 ( V_2 -> V_73 ) ;
} else {
V_48 = - V_214 ;
goto V_226;
}
}
if ( ( V_6 -> V_204 & V_205 ) == 0 && ! F_126 ( V_160 ) ) {
V_48 = - V_214 ;
goto V_226;
}
F_56 ( V_2 ) ;
V_226:
F_71 ( & V_83 ) ;
F_74 ( V_2 ) ;
return V_48 ;
}
struct V_45 * F_90 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
struct V_45 * V_46 ;
F_34 ( & V_2 -> V_50 , V_44 ) ;
V_46 = F_52 ( V_2 -> V_46 ) ;
F_35 ( & V_2 -> V_50 , V_44 ) ;
return V_46 ;
}
static struct V_45 * F_181 ( struct V_45 * V_46 )
{
struct V_70 * V_21 ;
struct V_45 * V_227 = NULL ;
V_21 = F_182 ( V_46 , V_211 ) ;
if ( V_21 == NULL )
V_21 = F_182 ( V_46 , V_212 ) ;
if ( V_21 != NULL )
V_227 = F_53 ( V_21 ) ;
return V_227 ;
}
static int F_183 ( struct V_1 * V_2 , struct V_1 * V_228 , T_7 T_3 * V_21 )
{
struct V_45 * V_45 ;
int V_48 ;
if ( V_2 == V_228 && V_49 -> signal -> V_2 != V_228 )
return - V_69 ;
V_45 = F_90 ( V_228 ) ;
V_48 = F_184 ( F_185 ( V_45 ) , V_21 ) ;
F_51 ( V_45 ) ;
return V_48 ;
}
static int F_186 ( struct V_1 * V_2 , struct V_1 * V_228 , T_7 T_3 * V_21 )
{
struct V_45 * V_46 ;
T_7 V_229 ;
int V_163 = F_42 ( V_228 ) ;
if ( V_163 == - V_52 )
return - V_69 ;
if ( V_163 )
return V_163 ;
if ( ! V_49 -> signal -> V_2 ||
( V_49 -> signal -> V_2 != V_228 ) ||
( V_228 -> V_73 != F_53 ( V_49 ) ) )
return - V_69 ;
if ( F_172 ( V_229 , V_21 ) )
return - V_134 ;
if ( V_229 < 0 )
return - V_230 ;
F_32 () ;
V_46 = F_187 ( V_229 ) ;
V_163 = - V_231 ;
if ( ! V_46 )
goto V_232;
V_163 = - V_214 ;
if ( F_181 ( V_46 ) != F_53 ( V_49 ) )
goto V_232;
V_163 = 0 ;
F_57 ( & V_2 -> V_50 ) ;
F_51 ( V_228 -> V_46 ) ;
V_228 -> V_46 = F_52 ( V_46 ) ;
F_58 ( & V_2 -> V_50 ) ;
V_232:
F_40 () ;
return V_163 ;
}
static int F_188 ( struct V_1 * V_2 , struct V_1 * V_228 , T_7 T_3 * V_21 )
{
if ( V_2 == V_228 && V_49 -> signal -> V_2 != V_228 )
return - V_69 ;
if ( ! V_228 -> V_73 )
return - V_69 ;
return F_184 ( F_185 ( V_228 -> V_73 ) , V_21 ) ;
}
static int F_189 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_162 ;
int V_48 ;
if ( F_172 ( V_162 , V_21 ) )
return - V_134 ;
V_48 = F_190 ( V_2 , V_162 ) ;
return V_48 ;
}
static int F_191 ( struct V_1 * V_2 , unsigned int V_233 )
{
int V_163 ;
if ( V_2 -> V_41 -> V_234 == NULL )
return 0 ;
if ( V_2 -> V_23 -> V_44 & V_235 )
V_163 = V_2 -> V_41 -> V_234 ( V_2 , V_233 ) ;
else {
if ( F_102 ( V_2 , 0 ) < 0 )
return - V_236 ;
V_163 = V_2 -> V_41 -> V_234 ( V_2 , - 1 ) ;
if ( V_163 )
goto V_132;
if ( ! F_107 ( V_49 ) )
F_192 ( V_233 ) ;
V_163 = V_2 -> V_41 -> V_234 ( V_2 , 0 ) ;
V_132:
F_101 ( V_2 ) ;
if ( F_107 ( V_49 ) )
V_163 = - V_236 ;
}
return V_163 ;
}
static int F_193 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_163 = - V_230 ;
if ( V_2 -> V_41 -> V_237 ) {
V_163 = V_2 -> V_41 -> V_237 ( V_2 ) ;
if ( V_163 >= 0 )
V_163 = F_184 ( V_163 , V_21 ) ;
}
return V_163 ;
}
static int F_194 ( struct V_1 * V_2 , unsigned int V_66 ,
unsigned T_3 * V_21 )
{
int V_163 ;
unsigned int V_238 , V_239 , V_240 ;
if ( V_2 -> V_41 -> V_241 == NULL )
return - V_230 ;
V_163 = F_172 ( V_240 , V_21 ) ;
if ( V_163 )
return V_163 ;
V_238 = V_239 = 0 ;
switch ( V_66 ) {
case V_242 :
V_238 = V_240 ;
break;
case V_243 :
V_239 = V_240 ;
break;
case V_244 :
V_238 = V_240 ;
V_239 = ~ V_240 ;
break;
}
V_238 &= V_245 | V_246 | V_247 | V_248 | V_249 ;
V_239 &= V_245 | V_246 | V_247 | V_248 | V_249 ;
return V_2 -> V_41 -> V_241 ( V_2 , V_238 , V_239 ) ;
}
static int F_195 ( struct V_1 * V_2 , void T_3 * V_67 )
{
int V_163 = - V_230 ;
struct V_250 V_251 ;
memset ( & V_251 , 0 , sizeof( V_251 ) ) ;
if ( V_2 -> V_41 -> V_252 )
V_163 = V_2 -> V_41 -> V_252 ( V_2 , & V_251 ) ;
if ( V_163 != 0 )
return V_163 ;
if ( F_175 ( V_67 , & V_251 , sizeof( V_251 ) ) )
return - V_134 ;
return 0 ;
}
static void F_196 ( struct V_253 T_3 * V_254 )
{
static F_197 ( V_255 ,
V_256 ,
V_257 ) ;
char V_258 [ V_259 ] ;
int V_44 ;
if ( F_172 ( V_44 , & V_254 -> V_44 ) )
return;
V_44 &= V_260 ;
if ( V_44 && F_198 ( & V_255 ) )
F_199 ( L_36 ,
V_170 , F_200 ( V_258 , V_49 ) , V_44 ) ;
}
static struct V_1 * F_201 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 -> type == V_24 &&
V_2 -> V_23 -> V_25 == V_158 )
V_2 = V_2 -> V_27 ;
return V_2 ;
}
long F_202 ( struct V_6 * V_6 , unsigned int V_66 , unsigned long V_67 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_1 * V_228 ;
void T_3 * V_21 = ( void T_3 * ) V_67 ;
int V_163 ;
struct V_76 * V_77 ;
if ( F_15 ( V_2 , F_99 ( V_6 ) , L_37 ) )
return - V_230 ;
V_228 = F_201 ( V_2 ) ;
switch ( V_66 ) {
case V_261 :
case V_262 :
case V_263 :
case V_264 :
case V_265 :
V_163 = F_42 ( V_2 ) ;
if ( V_163 )
return V_163 ;
if ( V_66 != V_263 ) {
F_203 ( V_2 , 0 ) ;
if ( F_107 ( V_49 ) )
return - V_236 ;
}
break;
}
switch ( V_66 ) {
case V_266 :
return F_171 ( V_2 , V_21 ) ;
case V_267 :
return F_174 ( V_228 , V_21 ) ;
case V_268 :
return F_177 ( V_228 , V_21 ) ;
case V_269 :
return V_228 != V_2 ? - V_230 : F_178 ( V_6 ) ;
case V_270 :
return F_179 ( V_6 , V_21 ) ;
case V_271 :
F_78 ( V_159 , & V_2 -> V_44 ) ;
return 0 ;
case V_272 :
F_77 ( V_159 , & V_2 -> V_44 ) ;
return 0 ;
case V_273 :
{
int V_274 = F_64 ( V_159 , & V_2 -> V_44 ) ;
return F_184 ( V_274 , ( int T_3 * ) V_21 ) ;
}
case V_275 :
if ( V_49 -> signal -> V_2 != V_2 )
return - V_69 ;
F_91 () ;
return 0 ;
case V_276 :
return F_180 ( V_2 , V_6 , V_67 ) ;
case V_277 :
return F_183 ( V_2 , V_228 , V_21 ) ;
case V_68 :
return F_186 ( V_2 , V_228 , V_21 ) ;
case V_278 :
return F_188 ( V_2 , V_228 , V_21 ) ;
case V_279 :
return F_184 ( V_2 -> V_162 -> V_41 -> V_34 , ( int T_3 * ) V_21 ) ;
case V_261 :
return F_189 ( V_2 , V_21 ) ;
case V_280 :
if ( ! F_126 ( V_160 ) )
return - V_214 ;
F_85 ( V_2 ) ;
return 0 ;
case V_281 :
{
unsigned int V_48 = F_204 ( F_205 ( V_228 ) ) ;
return F_184 ( V_48 , ( unsigned int T_3 * ) V_21 ) ;
}
case V_262 :
if ( V_2 -> V_41 -> V_234 )
return V_2 -> V_41 -> V_234 ( V_2 , - 1 ) ;
return 0 ;
case V_263 :
if ( V_2 -> V_41 -> V_234 )
return V_2 -> V_41 -> V_234 ( V_2 , 0 ) ;
return 0 ;
case V_264 :
if ( ! V_67 )
return F_191 ( V_2 , 250 ) ;
return 0 ;
case V_265 :
return F_191 ( V_2 , V_67 ? V_67 * 100 : 250 ) ;
case V_282 :
return F_193 ( V_2 , V_21 ) ;
case V_244 :
case V_243 :
case V_242 :
return F_194 ( V_2 , V_66 , V_21 ) ;
case V_283 :
V_163 = F_195 ( V_2 , V_21 ) ;
if ( V_163 != - V_230 )
return V_163 ;
break;
case V_284 :
switch ( V_67 ) {
case V_285 :
case V_286 :
F_206 ( V_2 , NULL ) ;
break;
}
break;
case V_287 :
F_196 ( V_21 ) ;
break;
}
if ( V_2 -> V_41 -> V_288 ) {
V_163 = V_2 -> V_41 -> V_288 ( V_2 , V_66 , V_67 ) ;
if ( V_163 != - V_289 )
return V_163 ;
}
V_77 = F_100 ( V_2 ) ;
V_163 = - V_230 ;
if ( V_77 -> V_41 -> V_288 ) {
V_163 = V_77 -> V_41 -> V_288 ( V_2 , V_6 , V_66 , V_67 ) ;
if ( V_163 == - V_289 )
V_163 = - V_69 ;
}
F_66 ( V_77 ) ;
return V_163 ;
}
static long F_207 ( struct V_6 * V_6 , unsigned int V_66 ,
unsigned long V_67 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_76 * V_77 ;
int V_163 = - V_289 ;
if ( F_15 ( V_2 , F_99 ( V_6 ) , L_37 ) )
return - V_230 ;
if ( V_2 -> V_41 -> V_290 ) {
V_163 = V_2 -> V_41 -> V_290 ( V_2 , V_66 , V_67 ) ;
if ( V_163 != - V_289 )
return V_163 ;
}
V_77 = F_100 ( V_2 ) ;
if ( V_77 -> V_41 -> V_290 )
V_163 = V_77 -> V_41 -> V_290 ( V_2 , V_6 , V_66 , V_67 ) ;
else
V_163 = F_208 ( V_2 , V_6 , V_66 , V_67 ) ;
F_66 ( V_77 ) ;
return V_163 ;
}
static int F_209 ( const void * V_291 , struct V_6 * V_6 , unsigned V_207 )
{
if ( F_210 ( V_6 -> V_95 -> V_120 != F_98 ) )
return 0 ;
return F_4 ( V_6 ) != V_291 ? 0 : V_207 + 1 ;
}
void F_211 ( struct V_1 * V_2 )
{
#ifdef F_212
F_82 ( V_2 ) ;
#else
struct V_70 * V_292 , * V_21 ;
struct V_45 * V_73 ;
int V_118 ;
if ( ! V_2 )
return;
V_73 = V_2 -> V_73 ;
F_213 ( V_2 ) ;
F_214 ( V_2 ) ;
F_69 ( & V_83 ) ;
F_61 (session, PIDTYPE_SID, p) {
F_17 ( V_293 L_38
L_39 ,
F_215 ( V_21 ) , V_21 -> V_258 ) ;
F_216 ( V_294 , V_21 , 1 ) ;
} F_62 ( V_73 , V_75 , V_21 ) ;
F_217 (g, p) {
if ( V_21 -> signal -> V_2 == V_2 ) {
F_17 ( V_293 L_38
L_39 ,
F_215 ( V_21 ) , V_21 -> V_258 ) ;
F_216 ( V_294 , V_21 , 1 ) ;
continue;
}
F_218 ( V_21 ) ;
V_118 = F_219 ( V_21 -> V_295 , 0 , F_209 , V_2 ) ;
if ( V_118 != 0 ) {
F_17 ( V_293 L_38
L_40 ,
F_215 ( V_21 ) , V_21 -> V_258 , V_118 - 1 ) ;
F_220 ( V_294 , V_21 ) ;
}
F_221 ( V_21 ) ;
} F_222 ( V_292 , V_21 ) ;
F_71 ( & V_83 ) ;
#endif
}
static void F_223 ( struct V_104 * V_105 )
{
struct V_1 * V_2 =
F_81 ( V_105 , struct V_1 , V_174 ) ;
F_211 ( V_2 ) ;
}
void F_224 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_84 ( & V_2 -> V_174 ) ;
}
static int F_225 ( struct V_29 * V_3 , const void * V_296 )
{
const T_1 * V_297 = V_296 ;
return V_3 -> V_297 == * V_297 ;
}
static struct V_29 * F_226 ( struct V_1 * V_2 )
{
T_1 V_297 = F_205 ( V_2 ) ;
return F_227 ( V_298 , NULL , & V_297 , F_225 ) ;
}
struct V_1 * F_131 ( struct V_28 * V_23 , int V_147 )
{
struct V_1 * V_2 ;
V_2 = F_228 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_229 ( & V_2 -> V_177 ) ;
V_2 -> V_5 = V_19 ;
F_230 ( V_2 ) ;
V_2 -> V_73 = NULL ;
V_2 -> V_46 = NULL ;
F_231 ( & V_2 -> V_299 ) ;
F_231 ( & V_2 -> V_300 ) ;
F_232 ( & V_2 -> V_143 ) ;
F_231 ( & V_2 -> V_218 ) ;
F_233 ( & V_2 -> V_301 ) ;
F_234 ( & V_2 -> V_80 ) ;
F_234 ( & V_2 -> V_186 ) ;
F_145 ( & V_2 -> V_106 , F_80 ) ;
F_231 ( & V_2 -> V_122 ) ;
F_235 ( & V_2 -> V_50 ) ;
F_235 ( & V_2 -> V_112 ) ;
F_236 ( & V_2 -> V_14 ) ;
F_145 ( & V_2 -> V_174 , F_223 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_41 = V_23 -> V_41 ;
V_2 -> V_30 = V_147 ;
F_116 ( V_23 , V_147 , V_2 -> V_15 ) ;
V_2 -> V_3 = F_226 ( V_2 ) ;
return V_2 ;
}
void F_134 ( struct V_1 * V_2 )
{
F_237 ( V_2 ) ;
}
int F_238 ( struct V_1 * V_2 , unsigned char V_140 )
{
if ( V_2 -> V_41 -> V_302 )
return V_2 -> V_41 -> V_302 ( V_2 , V_140 ) ;
return V_2 -> V_41 -> V_96 ( V_2 , & V_140 , 1 ) ;
}
static int F_239 ( struct V_28 * V_23 , T_1 V_3 ,
unsigned int V_30 , unsigned int V_22 )
{
int V_217 ;
V_23 -> V_303 [ V_30 ] = F_240 () ;
if ( ! V_23 -> V_303 [ V_30 ] )
return - V_11 ;
V_23 -> V_303 [ V_30 ] -> V_41 = & V_203 ;
V_23 -> V_303 [ V_30 ] -> V_164 = V_23 -> V_164 ;
V_217 = F_241 ( V_23 -> V_303 [ V_30 ] , V_3 , V_22 ) ;
if ( V_217 )
F_242 ( & V_23 -> V_303 [ V_30 ] -> V_304 ) ;
return V_217 ;
}
struct V_29 * F_243 ( struct V_28 * V_23 , unsigned V_30 ,
struct V_29 * V_29 )
{
return F_244 ( V_23 , V_30 , V_29 , NULL , NULL ) ;
}
static void F_245 ( struct V_29 * V_3 )
{
F_246 ( L_41 , F_247 ( V_3 ) , V_170 ) ;
F_3 ( V_3 ) ;
}
struct V_29 * F_244 ( struct V_28 * V_23 ,
unsigned V_30 , struct V_29 * V_29 ,
void * V_305 ,
const struct V_306 * * V_307 )
{
char V_15 [ 64 ] ;
T_1 V_297 = F_25 ( V_23 -> V_32 , V_23 -> V_33 ) + V_30 ;
struct V_29 * V_3 = NULL ;
int V_163 = - V_165 ;
bool V_308 = false ;
if ( V_30 >= V_23 -> V_34 ) {
F_17 ( V_138 L_42
L_43 , V_30 ) ;
return F_130 ( - V_230 ) ;
}
if ( V_23 -> type == V_24 )
F_115 ( V_23 , V_30 , V_15 ) ;
else
F_116 ( V_23 , V_30 , V_15 ) ;
if ( ! ( V_23 -> V_44 & V_309 ) ) {
V_163 = F_239 ( V_23 , V_297 , V_30 , 1 ) ;
if ( V_163 )
goto error;
V_308 = true ;
}
V_3 = F_228 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 ) {
V_163 = - V_11 ;
goto error;
}
V_3 -> V_297 = V_297 ;
V_3 -> V_310 = V_298 ;
V_3 -> V_311 = V_29 ;
V_3 -> V_312 = F_245 ;
F_248 ( V_3 , L_16 , V_15 ) ;
V_3 -> V_313 = V_307 ;
F_249 ( V_3 , V_305 ) ;
V_163 = F_250 ( V_3 ) ;
if ( V_163 )
goto error;
return V_3 ;
error:
F_2 ( V_3 ) ;
if ( V_308 ) {
F_251 ( V_23 -> V_303 [ V_30 ] ) ;
V_23 -> V_303 [ V_30 ] = NULL ;
}
return F_130 ( V_163 ) ;
}
void F_252 ( struct V_28 * V_23 , unsigned V_30 )
{
F_253 ( V_298 ,
F_25 ( V_23 -> V_32 , V_23 -> V_33 ) + V_30 ) ;
if ( ! ( V_23 -> V_44 & V_309 ) ) {
F_251 ( V_23 -> V_303 [ V_30 ] ) ;
V_23 -> V_303 [ V_30 ] = NULL ;
}
}
struct V_28 * F_254 ( unsigned int V_314 , struct V_175 * V_164 ,
unsigned long V_44 )
{
struct V_28 * V_23 ;
unsigned int V_303 = 1 ;
int V_217 ;
if ( ! V_314 || ( V_44 & V_146 && V_314 > 1 ) )
return F_130 ( - V_230 ) ;
V_23 = F_228 ( sizeof( struct V_28 ) , V_10 ) ;
if ( ! V_23 )
return F_130 ( - V_11 ) ;
F_229 ( & V_23 -> V_177 ) ;
V_23 -> V_5 = V_315 ;
V_23 -> V_34 = V_314 ;
V_23 -> V_164 = V_164 ;
V_23 -> V_44 = V_44 ;
if ( ! ( V_44 & V_179 ) ) {
V_23 -> V_149 = F_255 ( V_314 , sizeof( * V_23 -> V_149 ) ,
V_10 ) ;
V_23 -> V_153 = F_255 ( V_314 , sizeof( * V_23 -> V_153 ) ,
V_10 ) ;
if ( ! V_23 -> V_149 || ! V_23 -> V_153 ) {
V_217 = - V_11 ;
goto V_316;
}
}
if ( ! ( V_44 & V_309 ) ) {
V_23 -> V_169 = F_255 ( V_314 , sizeof( * V_23 -> V_169 ) ,
V_10 ) ;
if ( ! V_23 -> V_169 ) {
V_217 = - V_11 ;
goto V_316;
}
V_303 = V_314 ;
}
V_23 -> V_303 = F_255 ( V_303 , sizeof( * V_23 -> V_303 ) , V_10 ) ;
if ( ! V_23 -> V_303 ) {
V_217 = - V_11 ;
goto V_316;
}
return V_23 ;
V_316:
F_3 ( V_23 -> V_169 ) ;
F_3 ( V_23 -> V_149 ) ;
F_3 ( V_23 -> V_153 ) ;
F_3 ( V_23 -> V_303 ) ;
F_3 ( V_23 ) ;
return F_130 ( V_217 ) ;
}
static void F_256 ( struct V_177 * V_177 )
{
struct V_28 * V_23 = F_81 ( V_177 , struct V_28 , V_177 ) ;
int V_118 ;
struct V_150 * V_151 ;
if ( V_23 -> V_44 & V_317 ) {
for ( V_118 = 0 ; V_118 < V_23 -> V_34 ; V_118 ++ ) {
V_151 = V_23 -> V_153 [ V_118 ] ;
if ( V_151 ) {
V_23 -> V_153 [ V_118 ] = NULL ;
F_3 ( V_151 ) ;
}
if ( ! ( V_23 -> V_44 & V_318 ) )
F_252 ( V_23 , V_118 ) ;
}
F_257 ( V_23 ) ;
if ( V_23 -> V_44 & V_309 )
F_251 ( V_23 -> V_303 [ 0 ] ) ;
}
F_3 ( V_23 -> V_303 ) ;
F_3 ( V_23 -> V_169 ) ;
F_3 ( V_23 -> V_153 ) ;
F_3 ( V_23 -> V_149 ) ;
F_3 ( V_23 ) ;
}
void F_142 ( struct V_28 * V_23 )
{
F_146 ( & V_23 -> V_177 , F_256 ) ;
}
void F_258 ( struct V_28 * V_23 ,
const struct V_319 * V_320 )
{
V_23 -> V_41 = V_320 ;
}
void F_259 ( struct V_28 * V_321 )
{
F_142 ( V_321 ) ;
}
int F_260 ( struct V_28 * V_23 )
{
int error ;
int V_118 ;
T_1 V_3 ;
struct V_29 * V_321 ;
if ( ! V_23 -> V_32 ) {
error = F_261 ( & V_3 , V_23 -> V_33 ,
V_23 -> V_34 , V_23 -> V_15 ) ;
if ( ! error ) {
V_23 -> V_32 = F_262 ( V_3 ) ;
V_23 -> V_33 = F_263 ( V_3 ) ;
}
} else {
V_3 = F_25 ( V_23 -> V_32 , V_23 -> V_33 ) ;
error = F_264 ( V_3 , V_23 -> V_34 , V_23 -> V_15 ) ;
}
if ( error < 0 )
goto V_217;
if ( V_23 -> V_44 & V_309 ) {
error = F_239 ( V_23 , V_3 , 0 , V_23 -> V_34 ) ;
if ( error )
goto V_322;
}
F_29 ( & V_40 ) ;
F_9 ( & V_23 -> V_323 , & V_323 ) ;
F_30 ( & V_40 ) ;
if ( ! ( V_23 -> V_44 & V_318 ) ) {
for ( V_118 = 0 ; V_118 < V_23 -> V_34 ; V_118 ++ ) {
V_321 = F_243 ( V_23 , V_118 , NULL ) ;
if ( F_118 ( V_321 ) ) {
error = F_163 ( V_321 ) ;
goto V_324;
}
}
}
F_265 ( V_23 ) ;
V_23 -> V_44 |= V_317 ;
return 0 ;
V_324:
for ( V_118 -- ; V_118 >= 0 ; V_118 -- )
F_252 ( V_23 , V_118 ) ;
F_29 ( & V_40 ) ;
F_13 ( & V_23 -> V_323 ) ;
F_30 ( & V_40 ) ;
V_322:
F_266 ( V_3 , V_23 -> V_34 ) ;
V_217:
return error ;
}
int F_267 ( struct V_28 * V_23 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_266 ( F_25 ( V_23 -> V_32 , V_23 -> V_33 ) ,
V_23 -> V_34 ) ;
F_29 ( & V_40 ) ;
F_13 ( & V_23 -> V_323 ) ;
F_30 ( & V_40 ) ;
return 0 ;
}
T_1 F_205 ( struct V_1 * V_2 )
{
return F_25 ( V_2 -> V_23 -> V_32 , V_2 -> V_23 -> V_33 ) + V_2 -> V_30 ;
}
void F_268 ( struct V_325 * V_326 )
{
* V_326 = V_203 ;
}
void T_8 F_269 ( void )
{
T_9 * V_327 ;
F_270 () ;
V_327 = V_328 ;
while ( V_327 < V_329 ) {
(* V_327)() ;
V_327 ++ ;
}
}
static char * F_271 ( struct V_29 * V_3 , T_10 * V_330 )
{
if ( ! V_330 )
return NULL ;
if ( V_3 -> V_297 == F_25 ( V_189 , 0 ) ||
V_3 -> V_297 == F_25 ( V_189 , 2 ) )
* V_330 = 0666 ;
return NULL ;
}
static int T_8 F_272 ( void )
{
V_298 = F_273 ( V_331 , L_15 ) ;
if ( F_118 ( V_298 ) )
return F_163 ( V_298 ) ;
V_298 -> V_332 = F_271 ;
return 0 ;
}
static T_2 F_274 ( struct V_29 * V_3 ,
struct V_333 * V_334 , char * V_56 )
{
struct V_335 * V_336 [ 16 ] ;
int V_118 = 0 ;
struct V_335 * V_337 ;
T_2 V_22 = 0 ;
F_275 () ;
F_276 (c) {
if ( ! V_337 -> V_29 )
continue;
if ( ! V_337 -> V_96 )
continue;
if ( ( V_337 -> V_44 & V_338 ) == 0 )
continue;
V_336 [ V_118 ++ ] = V_337 ;
if ( V_118 >= F_277 ( V_336 ) )
break;
}
while ( V_118 -- ) {
int V_30 = V_336 [ V_118 ] -> V_30 ;
struct V_28 * V_339 = V_336 [ V_118 ] -> V_29 ( V_336 [ V_118 ] , & V_30 ) ;
if ( V_339 && ( V_336 [ V_118 ] -> V_30 > 0 || V_339 -> V_32 != V_193 ) )
V_22 += F_116 ( V_339 , V_30 , V_56 + V_22 ) ;
else
V_22 += sprintf ( V_56 + V_22 , L_17 ,
V_336 [ V_118 ] -> V_15 , V_336 [ V_118 ] -> V_30 ) ;
V_22 += sprintf ( V_56 + V_22 , L_44 , V_118 ? ' ' : '\n' ) ;
}
F_278 () ;
return V_22 ;
}
void F_279 ( void )
{
if ( V_340 )
F_280 ( & V_340 -> V_304 , NULL , L_45 ) ;
}
int T_8 F_281 ( void )
{
F_282 ( & V_341 , & V_203 ) ;
if ( F_241 ( & V_341 , F_25 ( V_189 , 0 ) , 1 ) ||
F_264 ( F_25 ( V_189 , 0 ) , 1 , L_46 ) < 0 )
F_283 ( L_47 ) ;
F_284 ( V_298 , NULL , F_25 ( V_189 , 0 ) , NULL , L_15 ) ;
F_282 ( & V_342 , & V_343 ) ;
if ( F_241 ( & V_342 , F_25 ( V_189 , 1 ) , 1 ) ||
F_264 ( F_25 ( V_189 , 1 ) , 1 , L_48 ) < 0 )
F_283 ( L_49 ) ;
V_340 = F_285 ( V_298 , NULL ,
F_25 ( V_189 , 1 ) , NULL ,
V_344 , L_50 ) ;
if ( F_118 ( V_340 ) )
V_340 = NULL ;
#ifdef F_159
F_286 ( & V_343 ) ;
#endif
return 0 ;
}
