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
int F_30 ( const char * V_15 , T_1 * V_34 )
{
struct V_27 * V_21 ;
int V_35 ;
int V_29 , V_36 = 0 ;
const char * V_37 ;
for ( V_37 = V_15 ; * V_37 && ! isdigit ( * V_37 ) ; V_37 ++ )
;
if ( ! * V_37 )
return - V_38 ;
V_35 = F_31 ( V_37 , 10 , & V_29 ) ;
if ( V_35 )
return V_35 ;
V_36 = V_37 - V_15 ;
F_32 ( & V_39 ) ;
F_27 (p, &tty_drivers, tty_drivers)
if ( V_36 == strlen ( V_21 -> V_15 ) && strncmp ( V_15 ,
V_21 -> V_15 , V_36 ) == 0 ) {
if ( V_29 < V_21 -> V_33 ) {
* V_34 = F_28 ( V_21 -> V_31 , V_21 -> V_32 + V_29 ) ;
goto V_40;
}
}
V_35 = - V_41 ;
V_40:
F_33 ( & V_39 ) ;
return V_35 ;
}
struct V_27 * F_34 ( char * V_15 , int * line )
{
struct V_27 * V_21 , * V_42 = NULL ;
int V_43 = 0 ;
int V_44 ;
char * V_37 , * V_45 ;
for ( V_37 = V_15 ; * V_37 ; V_37 ++ )
if ( ( * V_37 >= '0' && * V_37 <= '9' ) || * V_37 == ',' )
break;
if ( ! * V_37 )
return NULL ;
V_44 = V_37 - V_15 ;
V_43 = F_35 ( V_37 , & V_37 , 10 ) ;
F_32 ( & V_39 ) ;
F_27 (p, &tty_drivers, tty_drivers) {
if ( strncmp ( V_15 , V_21 -> V_15 , V_44 ) != 0 )
continue;
V_45 = V_37 ;
if ( * V_45 == ',' )
V_45 ++ ;
if ( * V_45 == '\0' )
V_45 = NULL ;
if ( V_43 >= 0 && V_43 < V_21 -> V_33 && V_21 -> V_46 &&
V_21 -> V_46 -> V_47 && ! V_21 -> V_46 -> V_47 ( V_21 , V_43 , V_45 ) ) {
V_42 = F_29 ( V_21 ) ;
* line = V_43 ;
break;
}
}
F_33 ( & V_39 ) ;
return V_42 ;
}
static T_2 F_36 ( struct V_6 * V_6 , char T_3 * V_48 ,
T_4 V_22 , T_5 * V_49 )
{
return 0 ;
}
static T_2 F_37 ( struct V_6 * V_6 , const char T_3 * V_48 ,
T_4 V_22 , T_5 * V_49 )
{
return - V_50 ;
}
static unsigned int F_38 ( struct V_6 * V_51 , T_6 * V_52 )
{
return V_53 | V_54 | V_55 | V_56 | V_57 | V_58 ;
}
static long F_39 ( struct V_6 * V_6 , unsigned int V_59 ,
unsigned long V_60 )
{
return V_59 == V_61 ? - V_62 : - V_50 ;
}
static long F_40 ( struct V_6 * V_6 ,
unsigned int V_59 , unsigned long V_60 )
{
return V_59 == V_61 ? - V_62 : - V_50 ;
}
static int F_41 ( int V_63 , struct V_6 * V_6 , int V_64 )
{
return - V_62 ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
if ( F_43 ( V_67 , & V_2 -> V_68 ) ) {
V_66 = F_44 ( V_2 ) ;
if ( V_66 ) {
if ( V_66 -> V_46 -> V_69 )
V_66 -> V_46 -> V_69 ( V_2 ) ;
F_45 ( V_66 ) ;
}
}
F_46 ( & V_2 -> V_70 , V_54 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_71 )
{
struct V_6 * V_72 = NULL ;
struct V_6 * V_51 , * V_73 = NULL ;
struct V_7 * V_9 ;
int V_74 = 0 , V_75 ;
int V_76 ;
if ( ! V_2 )
return;
F_9 ( & V_77 ) ;
if ( V_78 && F_5 ( V_78 ) == V_2 ) {
V_73 = V_78 ;
V_78 = NULL ;
}
F_11 ( & V_77 ) ;
F_48 ( V_2 ) ;
if ( F_43 ( V_79 , & V_2 -> V_68 ) ) {
F_49 ( V_2 ) ;
return;
}
F_22 ( V_2 , L_6 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_27 (priv, &tty->tty_files, list) {
V_51 = V_9 -> V_6 ;
if ( V_51 -> V_80 -> V_81 == V_82 )
V_72 = V_51 ;
if ( V_51 -> V_80 -> V_81 != V_83 )
continue;
V_74 ++ ;
F_50 ( - 1 , V_51 , 0 ) ;
V_51 -> V_80 = & V_84 ;
}
F_11 ( & V_2 -> V_12 ) ;
V_76 = F_51 ( V_2 , V_71 ) ;
while ( V_76 -- )
F_52 ( V_2 ) ;
F_53 ( V_2 , V_72 != NULL ) ;
F_54 ( & V_2 -> V_85 ) ;
F_55 ( V_86 , & V_2 -> V_68 ) ;
F_55 ( V_67 , & V_2 -> V_68 ) ;
F_56 ( V_2 -> V_87 ) ;
F_56 ( V_2 -> V_88 ) ;
V_2 -> V_87 = NULL ;
V_2 -> V_88 = NULL ;
V_2 -> V_89 = 0 ;
F_57 ( & V_2 -> V_85 ) ;
if ( V_72 ) {
if ( V_2 -> V_46 -> V_90 )
for ( V_75 = 0 ; V_75 < V_74 ; V_75 ++ )
V_2 -> V_46 -> V_90 ( V_2 , V_72 ) ;
} else if ( V_2 -> V_46 -> V_91 )
V_2 -> V_46 -> V_91 ( V_2 ) ;
F_58 ( V_79 , & V_2 -> V_68 ) ;
F_49 ( V_2 ) ;
if ( V_73 )
F_59 ( V_73 ) ;
}
static void F_60 ( struct V_92 * V_93 )
{
struct V_1 * V_2 =
F_61 ( V_93 , struct V_1 , V_94 ) ;
F_47 ( V_2 , 0 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
F_63 ( V_2 , L_7 ) ;
F_64 ( & V_2 -> V_94 ) ;
}
void F_65 ( struct V_1 * V_2 )
{
F_63 ( V_2 , L_8 ) ;
F_47 ( V_2 , 0 ) ;
}
void F_66 ( void )
{
struct V_1 * V_2 ;
V_2 = F_67 () ;
if ( V_2 ) {
F_65 ( V_2 ) ;
F_52 ( V_2 ) ;
}
}
void F_68 ( struct V_1 * V_2 )
{
F_63 ( V_2 , L_9 ) ;
F_47 ( V_2 , 1 ) ;
}
int F_69 ( struct V_6 * V_51 )
{
return ( V_51 && V_51 -> V_80 == & V_84 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_95 )
return;
V_2 -> V_95 = 1 ;
if ( V_2 -> V_46 -> V_96 )
V_2 -> V_46 -> V_96 ( V_2 ) ;
}
void F_71 ( struct V_1 * V_2 )
{
unsigned long V_68 ;
F_72 ( & V_2 -> V_97 , V_68 ) ;
F_70 ( V_2 ) ;
F_73 ( & V_2 -> V_97 , V_68 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_95 || V_2 -> V_98 )
return;
V_2 -> V_95 = 0 ;
if ( V_2 -> V_46 -> V_99 )
V_2 -> V_46 -> V_99 ( V_2 ) ;
F_42 ( V_2 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
unsigned long V_68 ;
F_72 ( & V_2 -> V_97 , V_68 ) ;
F_74 ( V_2 ) ;
F_73 ( & V_2 -> V_97 , V_68 ) ;
}
static void F_76 ( struct V_100 * time )
{
unsigned long V_101 = F_77 () ;
if ( ( V_101 ^ time -> V_102 ) & ~ 7 )
time -> V_102 = V_101 ;
}
static T_2 F_78 ( struct V_6 * V_6 , char T_3 * V_48 , T_4 V_22 ,
T_5 * V_49 )
{
int V_103 ;
struct V_17 * V_17 = F_79 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_65 * V_66 ;
if ( F_17 ( V_2 , V_17 , L_10 ) )
return - V_50 ;
if ( ! V_2 || F_80 ( V_2 ) )
return - V_50 ;
V_66 = F_81 ( V_2 ) ;
if ( ! V_66 )
return F_36 ( V_6 , V_48 , V_22 , V_49 ) ;
if ( V_66 -> V_46 -> V_104 )
V_103 = V_66 -> V_46 -> V_104 ( V_2 , V_6 , V_48 , V_22 ) ;
else
V_103 = - V_50 ;
F_45 ( V_66 ) ;
if ( V_103 > 0 )
F_76 ( & V_17 -> V_105 ) ;
return V_103 ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_106 ) ;
F_46 ( & V_2 -> V_70 , V_54 ) ;
}
static int F_83 ( struct V_1 * V_2 , int V_107 )
{
if ( ! F_84 ( & V_2 -> V_106 ) ) {
if ( V_107 )
return - V_108 ;
if ( F_85 ( & V_2 -> V_106 ) )
return - V_109 ;
}
return 0 ;
}
static inline T_2 F_86 (
T_2 (* V_81)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_48 ,
T_4 V_22 )
{
T_2 V_35 , V_110 = 0 ;
unsigned int V_111 ;
V_35 = F_83 ( V_2 , V_6 -> V_112 & V_113 ) ;
if ( V_35 < 0 )
return V_35 ;
V_111 = 2048 ;
if ( F_43 ( V_114 , & V_2 -> V_68 ) )
V_111 = 65536 ;
if ( V_22 < V_111 )
V_111 = V_22 ;
if ( V_2 -> V_115 < V_111 ) {
unsigned char * V_116 ;
if ( V_111 < 1024 )
V_111 = 1024 ;
V_116 = F_7 ( V_111 , V_10 ) ;
if ( ! V_116 ) {
V_35 = - V_11 ;
goto V_40;
}
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_115 = V_111 ;
V_2 -> V_4 = V_116 ;
}
for (; ; ) {
T_4 V_117 = V_22 ;
if ( V_117 > V_111 )
V_117 = V_111 ;
V_35 = - V_118 ;
if ( F_87 ( V_2 -> V_4 , V_48 , V_117 ) )
break;
V_35 = V_81 ( V_2 , V_6 , V_2 -> V_4 , V_117 ) ;
if ( V_35 <= 0 )
break;
V_110 += V_35 ;
V_48 += V_35 ;
V_22 -= V_35 ;
if ( ! V_22 )
break;
V_35 = - V_109 ;
if ( F_88 ( V_119 ) )
break;
F_89 () ;
}
if ( V_110 ) {
F_76 ( & F_79 ( V_6 ) -> V_120 ) ;
V_35 = V_110 ;
}
V_40:
F_82 ( V_2 ) ;
return V_35 ;
}
void F_90 ( struct V_1 * V_2 , char * V_121 )
{
if ( V_2 ) {
F_32 ( & V_2 -> V_106 ) ;
F_48 ( V_2 ) ;
if ( V_2 -> V_46 -> V_81 && V_2 -> V_22 > 0 )
V_2 -> V_46 -> V_81 ( V_2 , V_121 , strlen ( V_121 ) ) ;
F_49 ( V_2 ) ;
F_82 ( V_2 ) ;
}
return;
}
static T_2 V_83 ( struct V_6 * V_6 , const char T_3 * V_48 ,
T_4 V_22 , T_5 * V_49 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_65 * V_66 ;
T_2 V_35 ;
if ( F_17 ( V_2 , F_79 ( V_6 ) , L_11 ) )
return - V_50 ;
if ( ! V_2 || ! V_2 -> V_46 -> V_81 || F_80 ( V_2 ) )
return - V_50 ;
if ( V_2 -> V_46 -> V_122 == NULL )
F_91 ( V_2 , L_12 ) ;
V_66 = F_81 ( V_2 ) ;
if ( ! V_66 )
return F_37 ( V_6 , V_48 , V_22 , V_49 ) ;
if ( ! V_66 -> V_46 -> V_81 )
V_35 = - V_50 ;
else
V_35 = F_86 ( V_66 -> V_46 -> V_81 , V_2 , V_6 , V_48 , V_22 ) ;
F_45 ( V_66 ) ;
return V_35 ;
}
T_2 V_82 ( struct V_6 * V_6 , const char T_3 * V_48 ,
T_4 V_22 , T_5 * V_49 )
{
struct V_6 * V_21 = NULL ;
F_9 ( & V_77 ) ;
if ( V_78 )
V_21 = F_92 ( V_78 ) ;
F_11 ( & V_77 ) ;
if ( V_21 ) {
T_2 V_42 ;
V_42 = F_93 ( V_21 , V_48 , V_22 , & V_21 -> V_123 ) ;
F_59 ( V_21 ) ;
return V_42 ;
}
return V_83 ( V_6 , V_48 , V_22 , V_49 ) ;
}
int F_94 ( struct V_1 * V_2 , char V_124 )
{
int V_125 = V_2 -> V_95 ;
if ( V_2 -> V_46 -> V_126 ) {
F_95 ( & V_2 -> V_127 ) ;
V_2 -> V_46 -> V_126 ( V_2 , V_124 ) ;
F_96 ( & V_2 -> V_127 ) ;
return 0 ;
}
if ( F_83 ( V_2 , 0 ) < 0 )
return - V_109 ;
F_95 ( & V_2 -> V_127 ) ;
if ( V_125 )
F_75 ( V_2 ) ;
V_2 -> V_46 -> V_81 ( V_2 , & V_124 , 1 ) ;
if ( V_125 )
F_71 ( V_2 ) ;
F_96 ( & V_2 -> V_127 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static void F_97 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
int V_103 = V_29 + V_16 -> V_128 ;
sprintf ( V_21 , L_13 ,
V_16 -> V_24 == V_25 ? L_14 : V_16 -> V_15 ,
V_129 [ V_103 >> 4 & 0xf ] , V_103 & 0xf ) ;
}
static T_2 F_98 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
if ( V_16 -> V_68 & V_130 )
return sprintf ( V_21 , L_15 , V_16 -> V_15 ) ;
else
return sprintf ( V_21 , L_16 , V_16 -> V_15 ,
V_29 + V_16 -> V_128 ) ;
}
static struct V_1 * F_99 ( struct V_27 * V_16 ,
struct V_6 * V_6 , int V_131 )
{
struct V_1 * V_2 ;
if ( V_16 -> V_46 -> V_132 )
if ( ! V_6 )
V_2 = F_100 ( - V_50 ) ;
else
V_2 = V_16 -> V_46 -> V_132 ( V_16 , V_6 , V_131 ) ;
else
V_2 = V_16 -> V_133 [ V_131 ] ;
if ( ! F_101 ( V_2 ) )
F_102 ( V_2 ) ;
return V_2 ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_134 * V_135 ;
int V_131 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_68 & V_136 )
V_2 -> V_137 = V_2 -> V_16 -> V_138 ;
else {
V_135 = V_2 -> V_16 -> V_137 [ V_131 ] ;
if ( V_135 != NULL ) {
V_2 -> V_137 = * V_135 ;
V_2 -> V_137 . V_139 = V_2 -> V_16 -> V_138 . V_139 ;
} else
V_2 -> V_137 = V_2 -> V_16 -> V_138 ;
}
V_2 -> V_137 . V_140 = F_104 ( & V_2 -> V_137 ) ;
V_2 -> V_137 . V_141 = F_105 ( & V_2 -> V_137 ) ;
}
int F_106 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
F_103 ( V_2 ) ;
F_29 ( V_16 ) ;
V_2 -> V_22 ++ ;
V_16 -> V_133 [ V_2 -> V_29 ] = V_2 ;
return 0 ;
}
static int F_107 ( struct V_27 * V_16 ,
struct V_1 * V_2 )
{
return V_16 -> V_46 -> V_142 ? V_16 -> V_46 -> V_142 ( V_16 , V_2 ) :
F_106 ( V_16 , V_2 ) ;
}
static void F_108 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
if ( V_16 -> V_46 -> remove )
V_16 -> V_46 -> remove ( V_16 , V_2 ) ;
else
V_16 -> V_133 [ V_2 -> V_29 ] = NULL ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_27 * V_16 = V_2 -> V_16 ;
if ( V_16 -> type == V_23 &&
V_16 -> V_24 == V_143 )
return - V_50 ;
if ( ! V_2 -> V_22 )
return - V_108 ;
if ( F_43 ( V_144 , & V_2 -> V_68 ) && ! F_110 ( V_145 ) )
return - V_146 ;
V_2 -> V_22 ++ ;
if ( ! V_2 -> V_147 )
return F_111 ( V_2 , V_2 -> V_137 . V_139 ) ;
return 0 ;
}
struct V_1 * F_112 ( struct V_27 * V_16 , int V_131 )
{
struct V_1 * V_2 ;
int V_148 ;
if ( ! F_113 ( V_16 -> V_149 ) )
return F_100 ( - V_41 ) ;
V_2 = F_114 ( V_16 , V_131 ) ;
if ( ! V_2 ) {
V_148 = - V_11 ;
goto V_150;
}
F_48 ( V_2 ) ;
V_148 = F_107 ( V_16 , V_2 ) ;
if ( V_148 < 0 )
goto V_151;
if ( ! V_2 -> V_152 )
V_2 -> V_152 = V_16 -> V_153 [ V_131 ] ;
F_115 ( ! V_2 -> V_152 ,
L_17 ,
V_154 , V_2 -> V_16 -> V_15 ) ;
V_2 -> V_152 -> V_155 = V_2 ;
V_148 = F_116 ( V_2 , V_2 -> V_26 ) ;
if ( V_148 )
goto V_156;
return V_2 ;
V_151:
F_49 ( V_2 ) ;
F_1 ( V_2 ) ;
V_150:
F_117 ( V_16 -> V_149 ) ;
return F_100 ( V_148 ) ;
V_156:
F_49 ( V_2 ) ;
F_118 ( V_2 , L_18 ,
V_148 , V_131 ) ;
F_119 ( V_2 , V_131 ) ;
return F_100 ( V_148 ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_134 * V_135 ;
int V_131 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_68 & V_136 )
return;
V_135 = V_2 -> V_16 -> V_137 [ V_131 ] ;
if ( V_135 == NULL ) {
V_135 = F_7 ( sizeof( struct V_134 ) , V_10 ) ;
if ( V_135 == NULL )
return;
V_2 -> V_16 -> V_137 [ V_131 ] = V_135 ;
}
* V_135 = V_2 -> V_137 ;
}
static void F_121 ( struct V_1 * V_2 )
{
F_122 ( & V_2 -> V_157 ) ;
F_122 ( & V_2 -> V_94 ) ;
if ( V_2 -> V_26 ) {
F_122 ( & V_2 -> V_26 -> V_157 ) ;
F_122 ( & V_2 -> V_26 -> V_94 ) ;
}
}
static void F_123 ( struct V_92 * V_93 )
{
struct V_1 * V_2 =
F_61 ( V_93 , struct V_1 , V_94 ) ;
struct V_27 * V_16 = V_2 -> V_16 ;
struct V_158 * V_149 = V_16 -> V_149 ;
if ( V_2 -> V_46 -> V_159 )
V_2 -> V_46 -> V_159 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_124 ( V_16 ) ;
F_117 ( V_149 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_125 ( & V_2 -> V_14 ) ;
F_11 ( & V_2 -> V_12 ) ;
F_56 ( V_2 -> V_88 ) ;
F_56 ( V_2 -> V_87 ) ;
F_1 ( V_2 ) ;
}
static void F_126 ( struct V_160 * V_160 )
{
struct V_1 * V_2 = F_61 ( V_160 , struct V_1 , V_160 ) ;
F_127 ( & V_2 -> V_94 , F_123 ) ;
F_64 ( & V_2 -> V_94 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
if ( V_2 )
F_128 ( & V_2 -> V_160 , F_126 ) ;
}
static void F_119 ( struct V_1 * V_2 , int V_131 )
{
F_129 ( V_2 -> V_29 != V_131 ) ;
F_129 ( ! F_130 ( & V_39 ) ) ;
if ( V_2 -> V_46 -> V_161 )
V_2 -> V_46 -> V_161 ( V_2 ) ;
F_120 ( V_2 ) ;
F_108 ( V_2 -> V_16 , V_2 ) ;
V_2 -> V_152 -> V_155 = NULL ;
if ( V_2 -> V_26 )
V_2 -> V_26 -> V_152 -> V_155 = NULL ;
F_131 ( V_2 -> V_152 ) ;
F_52 ( V_2 -> V_26 ) ;
F_52 ( V_2 ) ;
}
static int F_132 ( struct V_1 * V_2 , int V_131 )
{
#ifdef F_18
if ( V_131 < 0 || V_131 >= V_2 -> V_16 -> V_33 ) {
F_133 ( V_2 , L_19 , V_131 ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_68 & V_162 )
return 0 ;
if ( V_2 != V_2 -> V_16 -> V_133 [ V_131 ] ) {
F_133 ( V_2 , L_20 ,
V_131 , V_2 -> V_16 -> V_133 [ V_131 ] ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_163 ) {
struct V_1 * V_164 = V_2 -> V_26 ;
if ( V_164 != V_2 -> V_16 -> V_163 -> V_133 [ V_131 ] ) {
F_133 ( V_2 , L_21 ,
V_131 , V_2 -> V_16 -> V_163 -> V_133 [ V_131 ] ) ;
return - 1 ;
}
if ( V_164 -> V_26 != V_2 ) {
F_133 ( V_2 , L_22 , V_164 -> V_26 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
void F_134 ( struct V_1 * V_2 , int V_131 )
{
F_135 ( V_2 ) ;
F_121 ( V_2 ) ;
F_63 ( V_2 , L_23 ) ;
F_32 ( & V_39 ) ;
F_119 ( V_2 , V_131 ) ;
F_33 ( & V_39 ) ;
}
int F_136 ( struct V_17 * V_17 , struct V_6 * V_51 )
{
struct V_1 * V_2 = F_5 ( V_51 ) ;
struct V_1 * V_164 = NULL ;
int V_165 , V_166 ;
int V_131 ;
long V_167 = 0 ;
int V_168 = 1 ;
if ( F_17 ( V_2 , V_17 , V_154 ) )
return 0 ;
F_48 ( V_2 ) ;
F_22 ( V_2 , V_154 ) ;
F_50 ( - 1 , V_51 , 0 ) ;
V_131 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_143 )
V_164 = V_2 -> V_26 ;
if ( F_132 ( V_2 , V_131 ) ) {
F_49 ( V_2 ) ;
return 0 ;
}
F_63 ( V_2 , L_24 , V_2 -> V_22 ) ;
if ( V_2 -> V_46 -> V_90 )
V_2 -> V_46 -> V_90 ( V_2 , V_51 ) ;
F_137 ( V_164 ) ;
while ( 1 ) {
V_165 = 0 ;
if ( V_2 -> V_22 <= 1 ) {
if ( F_138 ( & V_2 -> V_169 ) ) {
F_139 ( & V_2 -> V_169 , V_53 ) ;
V_165 ++ ;
}
if ( F_138 ( & V_2 -> V_70 ) ) {
F_139 ( & V_2 -> V_70 , V_54 ) ;
V_165 ++ ;
}
}
if ( V_164 && V_164 -> V_22 <= 1 ) {
if ( F_138 ( & V_164 -> V_169 ) ) {
F_139 ( & V_164 -> V_169 , V_53 ) ;
V_165 ++ ;
}
if ( F_138 ( & V_164 -> V_70 ) ) {
F_139 ( & V_164 -> V_70 , V_54 ) ;
V_165 ++ ;
}
}
if ( ! V_165 )
break;
if ( V_168 ) {
V_168 = 0 ;
F_25 ( V_2 , L_25 ) ;
}
F_140 ( V_167 ) ;
if ( V_167 < 120 * V_170 )
V_167 = 2 * V_167 + 1 ;
else
V_167 = V_171 ;
}
if ( V_164 ) {
if ( -- V_164 -> V_22 < 0 ) {
F_25 ( V_2 , L_26 , V_164 -> V_22 ) ;
V_164 -> V_22 = 0 ;
}
}
if ( -- V_2 -> V_22 < 0 ) {
F_25 ( V_2 , L_27 , V_2 -> V_22 ) ;
V_2 -> V_22 = 0 ;
}
F_13 ( V_51 ) ;
if ( ! V_2 -> V_22 ) {
F_141 ( & V_172 ) ;
F_142 ( V_2 -> V_87 ) ;
if ( V_164 )
F_142 ( V_164 -> V_87 ) ;
F_143 ( & V_172 ) ;
}
V_166 = ! V_2 -> V_22 && ! ( V_164 && V_164 -> V_22 ) ;
F_144 ( V_164 ) ;
F_49 ( V_2 ) ;
if ( ! V_166 )
return 0 ;
F_63 ( V_2 , L_28 ) ;
F_134 ( V_2 , V_131 ) ;
return 0 ;
}
static struct V_1 * F_145 ( T_1 V_28 , struct V_6 * V_51 )
{
struct V_1 * V_2 ;
int V_148 ;
if ( V_28 != F_28 ( V_173 , 0 ) )
return NULL ;
V_2 = F_67 () ;
if ( ! V_2 )
return F_100 ( - V_174 ) ;
V_51 -> V_112 |= V_175 ;
F_48 ( V_2 ) ;
F_52 ( V_2 ) ;
V_148 = F_109 ( V_2 ) ;
if ( V_148 < 0 ) {
F_49 ( V_2 ) ;
V_2 = F_100 ( V_148 ) ;
}
return V_2 ;
}
static struct V_27 * F_146 ( T_1 V_28 , struct V_6 * V_51 ,
int * V_29 )
{
struct V_27 * V_16 ;
switch ( V_28 ) {
#ifdef F_147
case F_28 ( V_176 , 0 ) : {
extern struct V_27 * V_177 ;
V_16 = F_29 ( V_177 ) ;
* V_29 = V_178 ;
break;
}
#endif
case F_28 ( V_173 , 1 ) : {
struct V_27 * V_177 = F_148 ( V_29 ) ;
if ( V_177 ) {
V_16 = F_29 ( V_177 ) ;
if ( V_16 && V_51 ) {
V_51 -> V_112 |= V_175 ;
break;
}
}
return F_100 ( - V_41 ) ;
}
default:
V_16 = F_26 ( V_28 , V_29 ) ;
if ( ! V_16 )
return F_100 ( - V_41 ) ;
break;
}
return V_16 ;
}
struct V_1 * F_149 ( T_1 V_28 , struct V_17 * V_17 ,
struct V_6 * V_51 )
{
struct V_1 * V_2 ;
struct V_27 * V_16 = NULL ;
int V_29 = - 1 ;
int V_148 ;
F_32 ( & V_39 ) ;
V_16 = F_146 ( V_28 , V_51 , & V_29 ) ;
if ( F_101 ( V_16 ) ) {
F_33 ( & V_39 ) ;
return F_150 ( V_16 ) ;
}
V_2 = F_99 ( V_16 , V_51 , V_29 ) ;
if ( F_101 ( V_2 ) ) {
F_33 ( & V_39 ) ;
goto V_40;
}
if ( V_2 ) {
F_33 ( & V_39 ) ;
V_148 = F_151 ( V_2 ) ;
F_52 ( V_2 ) ;
if ( V_148 ) {
if ( V_148 == - V_179 )
V_148 = - V_109 ;
V_2 = F_100 ( V_148 ) ;
goto V_40;
}
V_148 = F_109 ( V_2 ) ;
if ( V_148 < 0 ) {
F_49 ( V_2 ) ;
V_2 = F_100 ( V_148 ) ;
}
} else {
V_2 = F_112 ( V_16 , V_29 ) ;
F_33 ( & V_39 ) ;
}
V_40:
F_124 ( V_16 ) ;
return V_2 ;
}
static int F_152 ( struct V_17 * V_17 , struct V_6 * V_51 )
{
struct V_1 * V_2 ;
int V_180 , V_148 ;
T_1 V_28 = V_17 -> V_181 ;
unsigned V_182 = V_51 -> V_112 ;
F_153 ( V_17 , V_51 ) ;
V_183:
V_148 = F_6 ( V_51 ) ;
if ( V_148 )
return - V_11 ;
V_2 = F_145 ( V_28 , V_51 ) ;
if ( ! V_2 )
V_2 = F_149 ( V_28 , V_17 , V_51 ) ;
if ( F_101 ( V_2 ) ) {
F_12 ( V_51 ) ;
V_148 = F_154 ( V_2 ) ;
if ( V_148 != - V_108 || F_88 ( V_119 ) )
return V_148 ;
F_155 () ;
goto V_183;
}
F_8 ( V_2 , V_51 ) ;
F_22 ( V_2 , V_154 ) ;
F_63 ( V_2 , L_29 , V_2 -> V_22 ) ;
if ( V_2 -> V_46 -> V_184 )
V_148 = V_2 -> V_46 -> V_184 ( V_2 , V_51 ) ;
else
V_148 = - V_41 ;
V_51 -> V_112 = V_182 ;
if ( V_148 ) {
F_63 ( V_2 , L_30 , V_148 ) ;
F_49 ( V_2 ) ;
F_136 ( V_17 , V_51 ) ;
if ( V_148 != - V_109 )
return V_148 ;
if ( F_88 ( V_119 ) )
return V_148 ;
F_155 () ;
if ( F_69 ( V_51 ) )
V_51 -> V_80 = & V_185 ;
goto V_183;
}
F_55 ( V_79 , & V_2 -> V_68 ) ;
V_180 = ( V_51 -> V_112 & V_186 ) ||
( F_156 ( F_147 ) && V_28 == F_28 ( V_176 , 0 ) ) ||
V_28 == F_28 ( V_173 , 1 ) ||
( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_143 ) ;
if ( ! V_180 )
F_157 ( V_51 , V_2 ) ;
F_49 ( V_2 ) ;
return 0 ;
}
static unsigned int F_158 ( struct V_6 * V_51 , T_6 * V_52 )
{
struct V_1 * V_2 = F_5 ( V_51 ) ;
struct V_65 * V_66 ;
int V_35 = 0 ;
if ( F_17 ( V_2 , F_79 ( V_51 ) , L_31 ) )
return 0 ;
V_66 = F_81 ( V_2 ) ;
if ( ! V_66 )
return F_38 ( V_51 , V_52 ) ;
if ( V_66 -> V_46 -> V_187 )
V_35 = V_66 -> V_46 -> V_187 ( V_2 , V_51 , V_52 ) ;
F_45 ( V_66 ) ;
return V_35 ;
}
static int F_50 ( int V_63 , struct V_6 * V_51 , int V_64 )
{
struct V_1 * V_2 = F_5 ( V_51 ) ;
unsigned long V_68 ;
int V_148 = 0 ;
if ( F_17 ( V_2 , F_79 ( V_51 ) , L_32 ) )
goto V_40;
V_148 = F_159 ( V_63 , V_51 , V_64 , & V_2 -> V_188 ) ;
if ( V_148 <= 0 )
goto V_40;
if ( V_64 ) {
enum V_189 type ;
struct V_190 * V_190 ;
F_72 ( & V_2 -> V_85 , V_68 ) ;
if ( V_2 -> V_88 ) {
V_190 = V_2 -> V_88 ;
type = V_191 ;
} else {
V_190 = F_160 ( V_119 ) ;
type = V_192 ;
}
F_161 ( V_190 ) ;
F_73 ( & V_2 -> V_85 , V_68 ) ;
F_162 ( V_51 , V_190 , type , 0 ) ;
F_56 ( V_190 ) ;
V_148 = 0 ;
}
V_40:
return V_148 ;
}
static int F_163 ( int V_63 , struct V_6 * V_51 , int V_64 )
{
struct V_1 * V_2 = F_5 ( V_51 ) ;
int V_148 = - V_62 ;
F_48 ( V_2 ) ;
if ( ! F_69 ( V_51 ) )
V_148 = F_50 ( V_63 , V_51 , V_64 ) ;
F_49 ( V_2 ) ;
return V_148 ;
}
static int F_164 ( struct V_1 * V_2 , char T_3 * V_21 )
{
char V_124 , V_193 = 0 ;
struct V_65 * V_66 ;
if ( ( V_119 -> signal -> V_2 != V_2 ) && ! F_110 ( V_145 ) )
return - V_194 ;
if ( F_165 ( V_124 , V_21 ) )
return - V_118 ;
F_166 ( V_2 , V_124 ) ;
V_66 = F_81 ( V_2 ) ;
if ( ! V_66 )
return - V_50 ;
V_66 -> V_46 -> V_195 ( V_2 , & V_124 , & V_193 , 1 ) ;
F_45 ( V_66 ) ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , struct V_196 T_3 * V_60 )
{
int V_197 ;
F_32 ( & V_2 -> V_198 ) ;
V_197 = F_168 ( V_60 , & V_2 -> V_196 , sizeof( * V_60 ) ) ;
F_33 ( & V_2 -> V_198 ) ;
return V_197 ? - V_118 : 0 ;
}
int F_169 ( struct V_1 * V_2 , struct V_196 * V_199 )
{
struct V_190 * V_88 ;
F_32 ( & V_2 -> V_198 ) ;
if ( ! memcmp ( V_199 , & V_2 -> V_196 , sizeof( * V_199 ) ) )
goto V_200;
V_88 = F_170 ( V_2 ) ;
if ( V_88 )
F_171 ( V_88 , V_201 , 1 ) ;
F_56 ( V_88 ) ;
V_2 -> V_196 = * V_199 ;
V_200:
F_33 ( & V_2 -> V_198 ) ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 , struct V_196 T_3 * V_60 )
{
struct V_196 V_202 ;
if ( F_87 ( & V_202 , V_60 , sizeof( * V_60 ) ) )
return - V_118 ;
if ( V_2 -> V_46 -> V_203 )
return V_2 -> V_46 -> V_203 ( V_2 , & V_202 ) ;
else
return F_169 ( V_2 , & V_202 ) ;
}
static int F_173 ( struct V_6 * V_6 )
{
if ( ! F_110 ( V_145 ) )
return - V_194 ;
if ( V_6 -> V_80 -> V_81 == V_82 ) {
struct V_6 * V_73 ;
F_9 ( & V_77 ) ;
V_73 = V_78 ;
V_78 = NULL ;
F_11 ( & V_77 ) ;
if ( V_73 )
F_59 ( V_73 ) ;
return 0 ;
}
F_9 ( & V_77 ) ;
if ( V_78 ) {
F_11 ( & V_77 ) ;
return - V_146 ;
}
V_78 = F_92 ( V_6 ) ;
F_11 ( & V_77 ) ;
return 0 ;
}
static int F_174 ( struct V_6 * V_6 , int T_3 * V_21 )
{
int V_204 ;
if ( F_165 ( V_204 , V_21 ) )
return - V_118 ;
F_9 ( & V_6 -> V_205 ) ;
if ( V_204 )
V_6 -> V_112 |= V_175 ;
else
V_6 -> V_112 &= ~ V_175 ;
F_11 ( & V_6 -> V_205 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_206 ;
int V_35 ;
if ( F_165 ( V_206 , V_21 ) )
return - V_118 ;
V_35 = F_176 ( V_2 , V_206 ) ;
return V_35 ;
}
static int F_177 ( struct V_1 * V_2 , int T_3 * V_21 )
{
struct V_65 * V_66 ;
int V_35 ;
V_66 = F_81 ( V_2 ) ;
if ( ! V_66 )
return - V_50 ;
V_35 = F_178 ( V_66 -> V_46 -> V_33 , V_21 ) ;
F_45 ( V_66 ) ;
return V_35 ;
}
static int F_179 ( struct V_1 * V_2 , unsigned int V_207 )
{
int V_148 ;
if ( V_2 -> V_46 -> V_208 == NULL )
return 0 ;
if ( V_2 -> V_16 -> V_68 & V_209 )
V_148 = V_2 -> V_46 -> V_208 ( V_2 , V_207 ) ;
else {
if ( F_83 ( V_2 , 0 ) < 0 )
return - V_179 ;
V_148 = V_2 -> V_46 -> V_208 ( V_2 , - 1 ) ;
if ( V_148 )
goto V_40;
if ( ! F_88 ( V_119 ) )
F_180 ( V_207 ) ;
V_148 = V_2 -> V_46 -> V_208 ( V_2 , 0 ) ;
V_40:
F_82 ( V_2 ) ;
if ( F_88 ( V_119 ) )
V_148 = - V_179 ;
}
return V_148 ;
}
static int F_181 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_148 = - V_38 ;
if ( V_2 -> V_46 -> V_210 ) {
V_148 = V_2 -> V_46 -> V_210 ( V_2 ) ;
if ( V_148 >= 0 )
V_148 = F_178 ( V_148 , V_21 ) ;
}
return V_148 ;
}
static int F_182 ( struct V_1 * V_2 , unsigned int V_59 ,
unsigned T_3 * V_21 )
{
int V_148 ;
unsigned int V_211 , V_212 , V_213 ;
if ( V_2 -> V_46 -> V_214 == NULL )
return - V_38 ;
V_148 = F_165 ( V_213 , V_21 ) ;
if ( V_148 )
return V_148 ;
V_211 = V_212 = 0 ;
switch ( V_59 ) {
case V_215 :
V_211 = V_213 ;
break;
case V_216 :
V_212 = V_213 ;
break;
case V_217 :
V_211 = V_213 ;
V_212 = ~ V_213 ;
break;
}
V_211 &= V_218 | V_219 | V_220 | V_221 | V_222 ;
V_212 &= V_218 | V_219 | V_220 | V_221 | V_222 ;
return V_2 -> V_46 -> V_214 ( V_2 , V_211 , V_212 ) ;
}
static int F_183 ( struct V_1 * V_2 , void T_3 * V_60 )
{
int V_148 = - V_38 ;
struct V_223 V_224 ;
memset ( & V_224 , 0 , sizeof( V_224 ) ) ;
if ( V_2 -> V_46 -> V_225 )
V_148 = V_2 -> V_46 -> V_225 ( V_2 , & V_224 ) ;
if ( V_148 != 0 )
return V_148 ;
if ( F_168 ( V_60 , & V_224 , sizeof( V_224 ) ) )
return - V_118 ;
return 0 ;
}
static void F_184 ( struct V_226 T_3 * V_227 )
{
static F_185 ( V_228 ,
V_229 ,
V_230 ) ;
char V_231 [ V_232 ] ;
int V_68 ;
if ( F_165 ( V_68 , & V_227 -> V_68 ) )
return;
V_68 &= V_233 ;
if ( V_68 && F_186 ( & V_228 ) )
F_19 ( L_33 ,
V_154 , F_187 ( V_231 , V_119 ) , V_68 ) ;
}
static struct V_1 * F_188 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_143 )
V_2 = V_2 -> V_26 ;
return V_2 ;
}
long F_189 ( struct V_6 * V_6 , unsigned int V_59 , unsigned long V_60 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_1 * V_234 ;
void T_3 * V_21 = ( void T_3 * ) V_60 ;
int V_148 ;
struct V_65 * V_66 ;
if ( F_17 ( V_2 , F_79 ( V_6 ) , L_34 ) )
return - V_38 ;
V_234 = F_188 ( V_2 ) ;
switch ( V_59 ) {
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
V_148 = F_190 ( V_2 ) ;
if ( V_148 )
return V_148 ;
if ( V_59 != V_237 ) {
F_191 ( V_2 , 0 ) ;
if ( F_88 ( V_119 ) )
return - V_179 ;
}
break;
}
switch ( V_59 ) {
case V_240 :
return F_164 ( V_2 , V_21 ) ;
case V_241 :
return F_167 ( V_234 , V_21 ) ;
case V_242 :
return F_172 ( V_234 , V_21 ) ;
case V_243 :
return V_234 != V_2 ? - V_38 : F_173 ( V_6 ) ;
case V_244 :
return F_174 ( V_6 , V_21 ) ;
case V_245 :
F_58 ( V_144 , & V_2 -> V_68 ) ;
return 0 ;
case V_246 :
F_55 ( V_144 , & V_2 -> V_68 ) ;
return 0 ;
case V_247 :
{
int V_248 = F_43 ( V_144 , & V_2 -> V_68 ) ;
return F_178 ( V_248 , ( int T_3 * ) V_21 ) ;
}
case V_249 :
return F_177 ( V_2 , V_21 ) ;
case V_235 :
return F_175 ( V_2 , V_21 ) ;
case V_250 :
if ( ! F_110 ( V_145 ) )
return - V_194 ;
F_65 ( V_2 ) ;
return 0 ;
case V_251 :
{
unsigned int V_35 = F_192 ( F_193 ( V_234 ) ) ;
return F_178 ( V_35 , ( unsigned int T_3 * ) V_21 ) ;
}
case V_236 :
if ( V_2 -> V_46 -> V_208 )
return V_2 -> V_46 -> V_208 ( V_2 , - 1 ) ;
return 0 ;
case V_237 :
if ( V_2 -> V_46 -> V_208 )
return V_2 -> V_46 -> V_208 ( V_2 , 0 ) ;
return 0 ;
case V_238 :
if ( ! V_60 )
return F_179 ( V_2 , 250 ) ;
return 0 ;
case V_239 :
return F_179 ( V_2 , V_60 ? V_60 * 100 : 250 ) ;
case V_252 :
return F_181 ( V_2 , V_21 ) ;
case V_217 :
case V_216 :
case V_215 :
return F_182 ( V_2 , V_59 , V_21 ) ;
case V_253 :
V_148 = F_183 ( V_2 , V_21 ) ;
if ( V_148 != - V_38 )
return V_148 ;
break;
case V_254 :
switch ( V_60 ) {
case V_255 :
case V_256 :
F_194 ( V_2 , NULL ) ;
break;
}
break;
case V_257 :
F_184 ( V_21 ) ;
break;
case V_258 :
return F_195 ( V_6 , V_2 , ( int ) V_60 ) ;
default:
V_148 = F_196 ( V_2 , V_234 , V_6 , V_59 , V_60 ) ;
if ( V_148 != - V_259 )
return V_148 ;
}
if ( V_2 -> V_46 -> V_260 ) {
V_148 = V_2 -> V_46 -> V_260 ( V_2 , V_59 , V_60 ) ;
if ( V_148 != - V_259 )
return V_148 ;
}
V_66 = F_81 ( V_2 ) ;
if ( ! V_66 )
return F_39 ( V_6 , V_59 , V_60 ) ;
V_148 = - V_38 ;
if ( V_66 -> V_46 -> V_260 ) {
V_148 = V_66 -> V_46 -> V_260 ( V_2 , V_6 , V_59 , V_60 ) ;
if ( V_148 == - V_259 )
V_148 = - V_62 ;
}
F_45 ( V_66 ) ;
return V_148 ;
}
static long F_197 ( struct V_6 * V_6 , unsigned int V_59 ,
unsigned long V_60 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_65 * V_66 ;
int V_148 = - V_259 ;
if ( F_17 ( V_2 , F_79 ( V_6 ) , L_34 ) )
return - V_38 ;
if ( V_2 -> V_46 -> V_261 ) {
V_148 = V_2 -> V_46 -> V_261 ( V_2 , V_59 , V_60 ) ;
if ( V_148 != - V_259 )
return V_148 ;
}
V_66 = F_81 ( V_2 ) ;
if ( ! V_66 )
return F_40 ( V_6 , V_59 , V_60 ) ;
if ( V_66 -> V_46 -> V_261 )
V_148 = V_66 -> V_46 -> V_261 ( V_2 , V_6 , V_59 , V_60 ) ;
else
V_148 = F_198 ( V_2 , V_6 , V_59 , V_60 ) ;
F_45 ( V_66 ) ;
return V_148 ;
}
static int F_199 ( const void * V_262 , struct V_6 * V_6 , unsigned V_63 )
{
if ( F_200 ( V_6 -> V_80 -> V_104 != F_78 ) )
return 0 ;
return F_5 ( V_6 ) != V_262 ? 0 : V_63 + 1 ;
}
void F_201 ( struct V_1 * V_2 )
{
#ifdef F_202
F_62 ( V_2 ) ;
#else
struct V_263 * V_264 , * V_21 ;
struct V_190 * V_87 ;
int V_103 ;
if ( ! V_2 )
return;
V_87 = V_2 -> V_87 ;
F_203 ( V_2 ) ;
F_204 ( V_2 ) ;
F_141 ( & V_172 ) ;
F_205 (session, PIDTYPE_SID, p) {
F_206 ( V_2 , L_35 ,
F_207 ( V_21 ) , V_21 -> V_231 ) ;
F_208 ( V_265 , V_21 , 1 ) ;
} F_209 ( V_87 , V_266 , V_21 ) ;
F_210 (g, p) {
if ( V_21 -> signal -> V_2 == V_2 ) {
F_206 ( V_2 , L_36 ,
F_207 ( V_21 ) , V_21 -> V_231 ) ;
F_208 ( V_265 , V_21 , 1 ) ;
continue;
}
F_211 ( V_21 ) ;
V_103 = F_212 ( V_21 -> V_267 , 0 , F_199 , V_2 ) ;
if ( V_103 != 0 ) {
F_206 ( V_2 , L_37 ,
F_207 ( V_21 ) , V_21 -> V_231 , V_103 - 1 ) ;
F_213 ( V_265 , V_21 ) ;
}
F_214 ( V_21 ) ;
} F_215 ( V_264 , V_21 ) ;
F_143 ( & V_172 ) ;
#endif
}
static void F_216 ( struct V_92 * V_93 )
{
struct V_1 * V_2 =
F_61 ( V_93 , struct V_1 , V_157 ) ;
F_201 ( V_2 ) ;
}
void F_217 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_64 ( & V_2 -> V_157 ) ;
}
static int F_218 ( struct V_28 * V_3 , const void * V_268 )
{
const T_1 * V_269 = V_268 ;
return V_3 -> V_269 == * V_269 ;
}
static struct V_28 * F_219 ( struct V_1 * V_2 )
{
T_1 V_269 = F_193 ( V_2 ) ;
return F_220 ( V_270 , NULL , & V_269 , F_218 ) ;
}
struct V_1 * F_114 ( struct V_27 * V_16 , int V_131 )
{
struct V_1 * V_2 ;
V_2 = F_221 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_222 ( & V_2 -> V_160 ) ;
V_2 -> V_5 = V_19 ;
F_223 ( V_2 ) ;
V_2 -> V_87 = NULL ;
V_2 -> V_88 = NULL ;
F_224 ( & V_2 -> V_271 ) ;
F_224 ( & V_2 -> V_272 ) ;
F_225 ( & V_2 -> V_127 ) ;
F_224 ( & V_2 -> V_198 ) ;
F_226 ( & V_2 -> V_273 ) ;
F_227 ( & V_2 -> V_70 ) ;
F_227 ( & V_2 -> V_169 ) ;
F_127 ( & V_2 -> V_94 , F_60 ) ;
F_224 ( & V_2 -> V_106 ) ;
F_228 ( & V_2 -> V_85 ) ;
F_228 ( & V_2 -> V_97 ) ;
F_228 ( & V_2 -> V_12 ) ;
F_229 ( & V_2 -> V_14 ) ;
F_127 ( & V_2 -> V_157 , F_216 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_46 = V_16 -> V_46 ;
V_2 -> V_29 = V_131 ;
F_98 ( V_16 , V_131 , V_2 -> V_15 ) ;
V_2 -> V_3 = F_219 ( V_2 ) ;
return V_2 ;
}
int F_230 ( struct V_1 * V_2 , unsigned char V_124 )
{
if ( V_2 -> V_46 -> V_274 )
return V_2 -> V_46 -> V_274 ( V_2 , V_124 ) ;
return V_2 -> V_46 -> V_81 ( V_2 , & V_124 , 1 ) ;
}
static int F_231 ( struct V_27 * V_16 , T_1 V_3 ,
unsigned int V_29 , unsigned int V_22 )
{
int V_197 ;
V_16 -> V_275 [ V_29 ] = F_232 () ;
if ( ! V_16 -> V_275 [ V_29 ] )
return - V_11 ;
V_16 -> V_275 [ V_29 ] -> V_46 = & V_185 ;
V_16 -> V_275 [ V_29 ] -> V_149 = V_16 -> V_149 ;
V_197 = F_233 ( V_16 -> V_275 [ V_29 ] , V_3 , V_22 ) ;
if ( V_197 )
F_234 ( & V_16 -> V_275 [ V_29 ] -> V_276 ) ;
return V_197 ;
}
struct V_28 * F_235 ( struct V_27 * V_16 , unsigned V_29 ,
struct V_28 * V_28 )
{
return F_236 ( V_16 , V_29 , V_28 , NULL , NULL ) ;
}
static void F_237 ( struct V_28 * V_3 )
{
F_238 ( V_3 , L_38 ) ;
F_4 ( V_3 ) ;
}
struct V_28 * F_236 ( struct V_27 * V_16 ,
unsigned V_29 , struct V_28 * V_28 ,
void * V_277 ,
const struct V_278 * * V_279 )
{
char V_15 [ 64 ] ;
T_1 V_269 = F_28 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ;
struct V_134 * V_135 ;
struct V_28 * V_3 ;
int V_148 ;
if ( V_29 >= V_16 -> V_33 ) {
F_239 ( L_39 ,
V_16 -> V_15 , V_29 ) ;
return F_100 ( - V_38 ) ;
}
if ( V_16 -> type == V_23 )
F_97 ( V_16 , V_29 , V_15 ) ;
else
F_98 ( V_16 , V_29 , V_15 ) ;
V_3 = F_221 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 )
return F_100 ( - V_11 ) ;
V_3 -> V_269 = V_269 ;
V_3 -> V_280 = V_270 ;
V_3 -> V_281 = V_28 ;
V_3 -> V_282 = F_237 ;
F_240 ( V_3 , L_15 , V_15 ) ;
V_3 -> V_283 = V_279 ;
F_241 ( V_3 , V_277 ) ;
F_242 ( V_3 , 1 ) ;
V_148 = F_243 ( V_3 ) ;
if ( V_148 )
goto V_284;
if ( ! ( V_16 -> V_68 & V_285 ) ) {
V_135 = V_16 -> V_137 [ V_29 ] ;
if ( V_135 ) {
V_16 -> V_137 [ V_29 ] = NULL ;
F_4 ( V_135 ) ;
}
V_148 = F_231 ( V_16 , V_269 , V_29 , 1 ) ;
if ( V_148 )
goto V_286;
}
F_242 ( V_3 , 0 ) ;
F_244 ( & V_3 -> V_276 , V_287 ) ;
return V_3 ;
V_286:
F_245 ( V_3 ) ;
V_284:
F_3 ( V_3 ) ;
return F_100 ( V_148 ) ;
}
void F_246 ( struct V_27 * V_16 , unsigned V_29 )
{
F_247 ( V_270 ,
F_28 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ) ;
if ( ! ( V_16 -> V_68 & V_285 ) ) {
F_248 ( V_16 -> V_275 [ V_29 ] ) ;
V_16 -> V_275 [ V_29 ] = NULL ;
}
}
struct V_27 * F_249 ( unsigned int V_288 , struct V_158 * V_149 ,
unsigned long V_68 )
{
struct V_27 * V_16 ;
unsigned int V_275 = 1 ;
int V_197 ;
if ( ! V_288 || ( V_68 & V_130 && V_288 > 1 ) )
return F_100 ( - V_38 ) ;
V_16 = F_221 ( sizeof( struct V_27 ) , V_10 ) ;
if ( ! V_16 )
return F_100 ( - V_11 ) ;
F_222 ( & V_16 -> V_160 ) ;
V_16 -> V_5 = V_289 ;
V_16 -> V_33 = V_288 ;
V_16 -> V_149 = V_149 ;
V_16 -> V_68 = V_68 ;
if ( ! ( V_68 & V_162 ) ) {
V_16 -> V_133 = F_250 ( V_288 , sizeof( * V_16 -> V_133 ) ,
V_10 ) ;
V_16 -> V_137 = F_250 ( V_288 , sizeof( * V_16 -> V_137 ) ,
V_10 ) ;
if ( ! V_16 -> V_133 || ! V_16 -> V_137 ) {
V_197 = - V_11 ;
goto V_290;
}
}
if ( ! ( V_68 & V_285 ) ) {
V_16 -> V_153 = F_250 ( V_288 , sizeof( * V_16 -> V_153 ) ,
V_10 ) ;
if ( ! V_16 -> V_153 ) {
V_197 = - V_11 ;
goto V_290;
}
V_275 = V_288 ;
}
V_16 -> V_275 = F_250 ( V_275 , sizeof( * V_16 -> V_275 ) , V_10 ) ;
if ( ! V_16 -> V_275 ) {
V_197 = - V_11 ;
goto V_290;
}
return V_16 ;
V_290:
F_4 ( V_16 -> V_153 ) ;
F_4 ( V_16 -> V_133 ) ;
F_4 ( V_16 -> V_137 ) ;
F_4 ( V_16 -> V_275 ) ;
F_4 ( V_16 ) ;
return F_100 ( V_197 ) ;
}
static void F_251 ( struct V_160 * V_160 )
{
struct V_27 * V_16 = F_61 ( V_160 , struct V_27 , V_160 ) ;
int V_103 ;
struct V_134 * V_135 ;
if ( V_16 -> V_68 & V_291 ) {
for ( V_103 = 0 ; V_103 < V_16 -> V_33 ; V_103 ++ ) {
V_135 = V_16 -> V_137 [ V_103 ] ;
if ( V_135 ) {
V_16 -> V_137 [ V_103 ] = NULL ;
F_4 ( V_135 ) ;
}
if ( ! ( V_16 -> V_68 & V_292 ) )
F_246 ( V_16 , V_103 ) ;
}
F_252 ( V_16 ) ;
if ( V_16 -> V_68 & V_285 )
F_248 ( V_16 -> V_275 [ 0 ] ) ;
}
F_4 ( V_16 -> V_275 ) ;
F_4 ( V_16 -> V_153 ) ;
F_4 ( V_16 -> V_137 ) ;
F_4 ( V_16 -> V_133 ) ;
F_4 ( V_16 ) ;
}
void F_124 ( struct V_27 * V_16 )
{
F_128 ( & V_16 -> V_160 , F_251 ) ;
}
void F_253 ( struct V_27 * V_16 ,
const struct V_293 * V_294 )
{
V_16 -> V_46 = V_294 ;
}
void F_254 ( struct V_27 * V_295 )
{
F_124 ( V_295 ) ;
}
int F_255 ( struct V_27 * V_16 )
{
int error ;
int V_103 ;
T_1 V_3 ;
struct V_28 * V_295 ;
if ( ! V_16 -> V_31 ) {
error = F_256 ( & V_3 , V_16 -> V_32 ,
V_16 -> V_33 , V_16 -> V_15 ) ;
if ( ! error ) {
V_16 -> V_31 = F_257 ( V_3 ) ;
V_16 -> V_32 = F_258 ( V_3 ) ;
}
} else {
V_3 = F_28 ( V_16 -> V_31 , V_16 -> V_32 ) ;
error = F_259 ( V_3 , V_16 -> V_33 , V_16 -> V_15 ) ;
}
if ( error < 0 )
goto V_197;
if ( V_16 -> V_68 & V_285 ) {
error = F_231 ( V_16 , V_3 , 0 , V_16 -> V_33 ) ;
if ( error )
goto V_296;
}
F_32 ( & V_39 ) ;
F_10 ( & V_16 -> V_297 , & V_297 ) ;
F_33 ( & V_39 ) ;
if ( ! ( V_16 -> V_68 & V_292 ) ) {
for ( V_103 = 0 ; V_103 < V_16 -> V_33 ; V_103 ++ ) {
V_295 = F_235 ( V_16 , V_103 , NULL ) ;
if ( F_101 ( V_295 ) ) {
error = F_154 ( V_295 ) ;
goto V_298;
}
}
}
F_260 ( V_16 ) ;
V_16 -> V_68 |= V_291 ;
return 0 ;
V_298:
for ( V_103 -- ; V_103 >= 0 ; V_103 -- )
F_246 ( V_16 , V_103 ) ;
F_32 ( & V_39 ) ;
F_14 ( & V_16 -> V_297 ) ;
F_33 ( & V_39 ) ;
V_296:
F_261 ( V_3 , V_16 -> V_33 ) ;
V_197:
return error ;
}
int F_262 ( struct V_27 * V_16 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_261 ( F_28 ( V_16 -> V_31 , V_16 -> V_32 ) ,
V_16 -> V_33 ) ;
F_32 ( & V_39 ) ;
F_14 ( & V_16 -> V_297 ) ;
F_33 ( & V_39 ) ;
return 0 ;
}
T_1 F_193 ( struct V_1 * V_2 )
{
return F_28 ( V_2 -> V_16 -> V_31 , V_2 -> V_16 -> V_32 ) + V_2 -> V_29 ;
}
void F_263 ( struct V_299 * V_300 )
{
* V_300 = V_185 ;
}
static char * F_264 ( struct V_28 * V_3 , T_7 * V_301 )
{
if ( ! V_301 )
return NULL ;
if ( V_3 -> V_269 == F_28 ( V_173 , 0 ) ||
V_3 -> V_269 == F_28 ( V_173 , 2 ) )
* V_301 = 0666 ;
return NULL ;
}
static int T_8 F_265 ( void )
{
V_270 = F_266 ( V_302 , L_14 ) ;
if ( F_101 ( V_270 ) )
return F_154 ( V_270 ) ;
V_270 -> V_303 = F_264 ;
return 0 ;
}
static T_2 F_267 ( struct V_28 * V_3 ,
struct V_304 * V_305 , char * V_48 )
{
struct V_306 * V_307 [ 16 ] ;
int V_103 = 0 ;
struct V_306 * V_308 ;
T_2 V_22 = 0 ;
F_268 () ;
F_269 (c) {
if ( ! V_308 -> V_28 )
continue;
if ( ! V_308 -> V_81 )
continue;
if ( ( V_308 -> V_68 & V_309 ) == 0 )
continue;
V_307 [ V_103 ++ ] = V_308 ;
if ( V_103 >= F_270 ( V_307 ) )
break;
}
while ( V_103 -- ) {
int V_29 = V_307 [ V_103 ] -> V_29 ;
struct V_27 * V_310 = V_307 [ V_103 ] -> V_28 ( V_307 [ V_103 ] , & V_29 ) ;
if ( V_310 && ( V_307 [ V_103 ] -> V_29 > 0 || V_310 -> V_31 != V_176 ) )
V_22 += F_98 ( V_310 , V_29 , V_48 + V_22 ) ;
else
V_22 += sprintf ( V_48 + V_22 , L_16 ,
V_307 [ V_103 ] -> V_15 , V_307 [ V_103 ] -> V_29 ) ;
V_22 += sprintf ( V_48 + V_22 , L_40 , V_103 ? ' ' : '\n' ) ;
}
F_271 () ;
return V_22 ;
}
void F_272 ( void )
{
if ( V_311 )
F_273 ( & V_311 -> V_276 , NULL , L_41 ) ;
}
int T_8 F_274 ( void )
{
F_275 ( & V_312 , & V_185 ) ;
if ( F_233 ( & V_312 , F_28 ( V_173 , 0 ) , 1 ) ||
F_259 ( F_28 ( V_173 , 0 ) , 1 , L_42 ) < 0 )
F_276 ( L_43 ) ;
F_277 ( V_270 , NULL , F_28 ( V_173 , 0 ) , NULL , L_14 ) ;
F_275 ( & V_313 , & V_314 ) ;
if ( F_233 ( & V_313 , F_28 ( V_173 , 1 ) , 1 ) ||
F_259 ( F_28 ( V_173 , 1 ) , 1 , L_44 ) < 0 )
F_276 ( L_45 ) ;
V_311 = F_278 ( V_270 , NULL ,
F_28 ( V_173 , 1 ) , NULL ,
V_315 , L_46 ) ;
if ( F_101 ( V_311 ) )
V_311 = NULL ;
#ifdef F_147
F_279 ( & V_314 ) ;
#endif
return 0 ;
}
