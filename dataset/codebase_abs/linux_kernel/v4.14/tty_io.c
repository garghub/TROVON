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
int V_22 = 0 , V_23 = 0 ;
F_9 ( & V_2 -> V_12 ) ;
F_24 (p, &tty->tty_files) {
V_22 ++ ;
}
F_11 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_16 -> type == V_24 &&
V_2 -> V_16 -> V_25 == V_26 &&
V_2 -> V_27 && V_2 -> V_27 -> V_22 )
V_22 ++ ;
if ( F_25 ( V_2 -> V_28 ) )
V_23 ++ ;
if ( V_2 -> V_22 != ( V_22 + V_23 ) ) {
F_26 ( V_2 , L_5 ,
V_18 , V_2 -> V_22 , V_22 , V_23 ) ;
return ( V_22 + V_23 ) ;
}
#endif
return 0 ;
}
static struct V_29 * F_27 ( T_1 V_30 , int * V_31 )
{
struct V_29 * V_21 ;
F_28 (p, &tty_drivers, tty_drivers) {
T_1 V_32 = F_29 ( V_21 -> V_33 , V_21 -> V_34 ) ;
if ( V_30 < V_32 || V_30 >= V_32 + V_21 -> V_35 )
continue;
* V_31 = V_30 - V_32 ;
return F_30 ( V_21 ) ;
}
return NULL ;
}
int F_31 ( const char * V_15 , T_1 * V_36 )
{
struct V_29 * V_21 ;
int V_37 ;
int V_31 , V_38 = 0 ;
const char * V_39 ;
for ( V_39 = V_15 ; * V_39 && ! isdigit ( * V_39 ) ; V_39 ++ )
;
if ( ! * V_39 )
return - V_40 ;
V_37 = F_32 ( V_39 , 10 , & V_31 ) ;
if ( V_37 )
return V_37 ;
V_38 = V_39 - V_15 ;
F_33 ( & V_41 ) ;
F_28 (p, &tty_drivers, tty_drivers)
if ( V_38 == strlen ( V_21 -> V_15 ) && strncmp ( V_15 ,
V_21 -> V_15 , V_38 ) == 0 ) {
if ( V_31 < V_21 -> V_35 ) {
* V_36 = F_29 ( V_21 -> V_33 , V_21 -> V_34 + V_31 ) ;
goto V_42;
}
}
V_37 = - V_43 ;
V_42:
F_34 ( & V_41 ) ;
return V_37 ;
}
struct V_29 * F_35 ( char * V_15 , int * line )
{
struct V_29 * V_21 , * V_44 = NULL ;
int V_45 = 0 ;
int V_46 ;
char * V_39 , * V_47 ;
for ( V_39 = V_15 ; * V_39 ; V_39 ++ )
if ( ( * V_39 >= '0' && * V_39 <= '9' ) || * V_39 == ',' )
break;
if ( ! * V_39 )
return NULL ;
V_46 = V_39 - V_15 ;
V_45 = F_36 ( V_39 , & V_39 , 10 ) ;
F_33 ( & V_41 ) ;
F_28 (p, &tty_drivers, tty_drivers) {
if ( strncmp ( V_15 , V_21 -> V_15 , V_46 ) != 0 )
continue;
V_47 = V_39 ;
if ( * V_47 == ',' )
V_47 ++ ;
if ( * V_47 == '\0' )
V_47 = NULL ;
if ( V_45 >= 0 && V_45 < V_21 -> V_35 && V_21 -> V_48 &&
V_21 -> V_48 -> V_49 && ! V_21 -> V_48 -> V_49 ( V_21 , V_45 , V_47 ) ) {
V_44 = F_30 ( V_21 ) ;
* line = V_45 ;
break;
}
}
F_34 ( & V_41 ) ;
return V_44 ;
}
static T_2 F_37 ( struct V_6 * V_6 , char T_3 * V_50 ,
T_4 V_22 , T_5 * V_51 )
{
return 0 ;
}
static T_2 F_38 ( struct V_6 * V_6 , const char T_3 * V_50 ,
T_4 V_22 , T_5 * V_51 )
{
return - V_52 ;
}
static unsigned int F_39 ( struct V_6 * V_53 , T_6 * V_54 )
{
return V_55 | V_56 | V_57 | V_58 | V_59 | V_60 ;
}
static long F_40 ( struct V_6 * V_6 , unsigned int V_61 ,
unsigned long V_62 )
{
return V_61 == V_63 ? - V_64 : - V_52 ;
}
static long F_41 ( struct V_6 * V_6 ,
unsigned int V_61 , unsigned long V_62 )
{
return V_61 == V_63 ? - V_64 : - V_52 ;
}
static int F_42 ( int V_65 , struct V_6 * V_6 , int V_66 )
{
return - V_64 ;
}
static void F_43 ( struct V_67 * V_68 , struct V_6 * V_6 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
if ( V_2 && V_2 -> V_48 && V_2 -> V_48 -> V_69 )
V_2 -> V_48 -> V_69 ( V_2 , V_68 ) ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_70 * V_71 ;
if ( F_45 ( V_72 , & V_2 -> V_73 ) ) {
V_71 = F_46 ( V_2 ) ;
if ( V_71 ) {
if ( V_71 -> V_48 -> V_74 )
V_71 -> V_48 -> V_74 ( V_2 ) ;
F_47 ( V_71 ) ;
}
}
F_48 ( & V_2 -> V_75 , V_56 ) ;
}
static void F_49 ( struct V_1 * V_2 , int V_76 )
{
struct V_6 * V_77 = NULL ;
struct V_6 * V_53 , * V_78 = NULL ;
struct V_7 * V_9 ;
int V_79 = 0 , V_80 ;
int V_81 ;
if ( ! V_2 )
return;
F_9 ( & V_82 ) ;
if ( V_83 && F_5 ( V_83 ) == V_2 ) {
V_78 = V_83 ;
V_83 = NULL ;
}
F_11 ( & V_82 ) ;
F_50 ( V_2 ) ;
if ( F_45 ( V_84 , & V_2 -> V_73 ) ) {
F_51 ( V_2 ) ;
return;
}
F_22 ( V_2 , L_6 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_28 (priv, &tty->tty_files, list) {
V_53 = V_9 -> V_6 ;
if ( V_53 -> V_85 -> V_86 == V_87 )
V_77 = V_53 ;
if ( V_53 -> V_85 -> V_86 != V_88 )
continue;
V_79 ++ ;
F_52 ( - 1 , V_53 , 0 ) ;
V_53 -> V_85 = & V_89 ;
}
F_11 ( & V_2 -> V_12 ) ;
V_81 = F_53 ( V_2 , V_76 ) ;
while ( V_81 -- )
F_54 ( V_2 ) ;
F_55 ( V_2 , V_77 != NULL ) ;
F_56 ( & V_2 -> V_90 ) ;
F_57 ( V_91 , & V_2 -> V_73 ) ;
F_57 ( V_72 , & V_2 -> V_73 ) ;
F_58 ( V_2 -> V_92 ) ;
F_58 ( V_2 -> V_93 ) ;
V_2 -> V_92 = NULL ;
V_2 -> V_93 = NULL ;
V_2 -> V_94 = 0 ;
F_59 ( & V_2 -> V_90 ) ;
if ( V_77 ) {
if ( V_2 -> V_48 -> V_95 )
for ( V_80 = 0 ; V_80 < V_79 ; V_80 ++ )
V_2 -> V_48 -> V_95 ( V_2 , V_77 ) ;
} else if ( V_2 -> V_48 -> V_96 )
V_2 -> V_48 -> V_96 ( V_2 ) ;
F_60 ( V_84 , & V_2 -> V_73 ) ;
F_51 ( V_2 ) ;
if ( V_78 )
F_61 ( V_78 ) ;
}
static void F_62 ( struct V_97 * V_98 )
{
struct V_1 * V_2 =
F_63 ( V_98 , struct V_1 , V_99 ) ;
F_49 ( V_2 , 0 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_65 ( V_2 , L_7 ) ;
F_66 ( & V_2 -> V_99 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_65 ( V_2 , L_8 ) ;
F_49 ( V_2 , 0 ) ;
}
void F_68 ( void )
{
struct V_1 * V_2 ;
V_2 = F_69 () ;
if ( V_2 ) {
F_67 ( V_2 ) ;
F_54 ( V_2 ) ;
}
}
void F_70 ( struct V_1 * V_2 )
{
F_65 ( V_2 , L_9 ) ;
F_49 ( V_2 , 1 ) ;
}
int F_71 ( struct V_6 * V_53 )
{
return ( V_53 && V_53 -> V_85 == & V_89 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_100 )
return;
V_2 -> V_100 = 1 ;
if ( V_2 -> V_48 -> V_101 )
V_2 -> V_48 -> V_101 ( V_2 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
unsigned long V_73 ;
F_74 ( & V_2 -> V_102 , V_73 ) ;
F_72 ( V_2 ) ;
F_75 ( & V_2 -> V_102 , V_73 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_100 || V_2 -> V_103 )
return;
V_2 -> V_100 = 0 ;
if ( V_2 -> V_48 -> V_104 )
V_2 -> V_48 -> V_104 ( V_2 ) ;
F_44 ( V_2 ) ;
}
void F_77 ( struct V_1 * V_2 )
{
unsigned long V_73 ;
F_74 ( & V_2 -> V_102 , V_73 ) ;
F_76 ( V_2 ) ;
F_75 ( & V_2 -> V_102 , V_73 ) ;
}
static void F_78 ( struct V_105 * time )
{
unsigned long V_106 = F_79 () ;
if ( ( V_106 ^ time -> V_107 ) & ~ 7 )
time -> V_107 = V_106 ;
}
static T_2 F_80 ( struct V_6 * V_6 , char T_3 * V_50 , T_4 V_22 ,
T_5 * V_51 )
{
int V_108 ;
struct V_17 * V_17 = F_81 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_70 * V_71 ;
if ( F_17 ( V_2 , V_17 , L_10 ) )
return - V_52 ;
if ( ! V_2 || F_82 ( V_2 ) )
return - V_52 ;
V_71 = F_83 ( V_2 ) ;
if ( ! V_71 )
return F_37 ( V_6 , V_50 , V_22 , V_51 ) ;
if ( V_71 -> V_48 -> V_109 )
V_108 = V_71 -> V_48 -> V_109 ( V_2 , V_6 , V_50 , V_22 ) ;
else
V_108 = - V_52 ;
F_47 ( V_71 ) ;
if ( V_108 > 0 )
F_78 ( & V_17 -> V_110 ) ;
return V_108 ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_111 ) ;
F_48 ( & V_2 -> V_75 , V_56 ) ;
}
static int F_85 ( struct V_1 * V_2 , int V_112 )
{
if ( ! F_86 ( & V_2 -> V_111 ) ) {
if ( V_112 )
return - V_113 ;
if ( F_87 ( & V_2 -> V_111 ) )
return - V_114 ;
}
return 0 ;
}
static inline T_2 F_88 (
T_2 (* V_86)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_50 ,
T_4 V_22 )
{
T_2 V_37 , V_115 = 0 ;
unsigned int V_116 ;
V_37 = F_85 ( V_2 , V_6 -> V_117 & V_118 ) ;
if ( V_37 < 0 )
return V_37 ;
V_116 = 2048 ;
if ( F_45 ( V_119 , & V_2 -> V_73 ) )
V_116 = 65536 ;
if ( V_22 < V_116 )
V_116 = V_22 ;
if ( V_2 -> V_120 < V_116 ) {
unsigned char * V_121 ;
if ( V_116 < 1024 )
V_116 = 1024 ;
V_121 = F_7 ( V_116 , V_10 ) ;
if ( ! V_121 ) {
V_37 = - V_11 ;
goto V_42;
}
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_120 = V_116 ;
V_2 -> V_4 = V_121 ;
}
for (; ; ) {
T_4 V_122 = V_22 ;
if ( V_122 > V_116 )
V_122 = V_116 ;
V_37 = - V_123 ;
if ( F_89 ( V_2 -> V_4 , V_50 , V_122 ) )
break;
V_37 = V_86 ( V_2 , V_6 , V_2 -> V_4 , V_122 ) ;
if ( V_37 <= 0 )
break;
V_115 += V_37 ;
V_50 += V_37 ;
V_22 -= V_37 ;
if ( ! V_22 )
break;
V_37 = - V_114 ;
if ( F_90 ( V_124 ) )
break;
F_91 () ;
}
if ( V_115 ) {
F_78 ( & F_81 ( V_6 ) -> V_125 ) ;
V_37 = V_115 ;
}
V_42:
F_84 ( V_2 ) ;
return V_37 ;
}
void F_92 ( struct V_1 * V_2 , char * V_126 )
{
if ( V_2 ) {
F_33 ( & V_2 -> V_111 ) ;
F_50 ( V_2 ) ;
if ( V_2 -> V_48 -> V_86 && V_2 -> V_22 > 0 )
V_2 -> V_48 -> V_86 ( V_2 , V_126 , strlen ( V_126 ) ) ;
F_51 ( V_2 ) ;
F_84 ( V_2 ) ;
}
return;
}
static T_2 V_88 ( struct V_6 * V_6 , const char T_3 * V_50 ,
T_4 V_22 , T_5 * V_51 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_70 * V_71 ;
T_2 V_37 ;
if ( F_17 ( V_2 , F_81 ( V_6 ) , L_11 ) )
return - V_52 ;
if ( ! V_2 || ! V_2 -> V_48 -> V_86 || F_82 ( V_2 ) )
return - V_52 ;
if ( V_2 -> V_48 -> V_127 == NULL )
F_93 ( V_2 , L_12 ) ;
V_71 = F_83 ( V_2 ) ;
if ( ! V_71 )
return F_38 ( V_6 , V_50 , V_22 , V_51 ) ;
if ( ! V_71 -> V_48 -> V_86 )
V_37 = - V_52 ;
else
V_37 = F_88 ( V_71 -> V_48 -> V_86 , V_2 , V_6 , V_50 , V_22 ) ;
F_47 ( V_71 ) ;
return V_37 ;
}
T_2 V_87 ( struct V_6 * V_6 , const char T_3 * V_50 ,
T_4 V_22 , T_5 * V_51 )
{
struct V_6 * V_21 = NULL ;
F_9 ( & V_82 ) ;
if ( V_83 )
V_21 = F_94 ( V_83 ) ;
F_11 ( & V_82 ) ;
if ( V_21 ) {
T_2 V_44 ;
V_44 = F_95 ( V_21 , V_50 , V_22 , & V_21 -> V_128 ) ;
F_61 ( V_21 ) ;
return V_44 ;
}
return V_88 ( V_6 , V_50 , V_22 , V_51 ) ;
}
int F_96 ( struct V_1 * V_2 , char V_129 )
{
int V_130 = V_2 -> V_100 ;
if ( V_2 -> V_48 -> V_131 ) {
F_97 ( & V_2 -> V_132 ) ;
V_2 -> V_48 -> V_131 ( V_2 , V_129 ) ;
F_98 ( & V_2 -> V_132 ) ;
return 0 ;
}
if ( F_85 ( V_2 , 0 ) < 0 )
return - V_114 ;
F_97 ( & V_2 -> V_132 ) ;
if ( V_130 )
F_77 ( V_2 ) ;
V_2 -> V_48 -> V_86 ( V_2 , & V_129 , 1 ) ;
if ( V_130 )
F_73 ( V_2 ) ;
F_98 ( & V_2 -> V_132 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static void F_99 ( struct V_29 * V_16 , int V_31 , char * V_21 )
{
int V_108 = V_31 + V_16 -> V_133 ;
sprintf ( V_21 , L_13 ,
V_16 -> V_25 == V_26 ? L_14 : V_16 -> V_15 ,
V_134 [ V_108 >> 4 & 0xf ] , V_108 & 0xf ) ;
}
static T_2 F_100 ( struct V_29 * V_16 , int V_31 , char * V_21 )
{
if ( V_16 -> V_73 & V_135 )
return sprintf ( V_21 , L_15 , V_16 -> V_15 ) ;
else
return sprintf ( V_21 , L_16 , V_16 -> V_15 ,
V_31 + V_16 -> V_133 ) ;
}
static struct V_1 * F_101 ( struct V_29 * V_16 ,
struct V_6 * V_6 , int V_136 )
{
struct V_1 * V_2 ;
if ( V_16 -> V_48 -> V_137 )
if ( ! V_6 )
V_2 = F_102 ( - V_52 ) ;
else
V_2 = V_16 -> V_48 -> V_137 ( V_16 , V_6 , V_136 ) ;
else
V_2 = V_16 -> V_138 [ V_136 ] ;
if ( ! F_103 ( V_2 ) )
F_104 ( V_2 ) ;
return V_2 ;
}
void F_105 ( struct V_1 * V_2 )
{
struct V_139 * V_140 ;
int V_136 = V_2 -> V_31 ;
if ( V_2 -> V_16 -> V_73 & V_141 )
V_2 -> V_142 = V_2 -> V_16 -> V_143 ;
else {
V_140 = V_2 -> V_16 -> V_142 [ V_136 ] ;
if ( V_140 != NULL ) {
V_2 -> V_142 = * V_140 ;
V_2 -> V_142 . V_144 = V_2 -> V_16 -> V_143 . V_144 ;
} else
V_2 -> V_142 = V_2 -> V_16 -> V_143 ;
}
V_2 -> V_142 . V_145 = F_106 ( & V_2 -> V_142 ) ;
V_2 -> V_142 . V_146 = F_107 ( & V_2 -> V_142 ) ;
}
int F_108 ( struct V_29 * V_16 , struct V_1 * V_2 )
{
F_105 ( V_2 ) ;
F_30 ( V_16 ) ;
V_2 -> V_22 ++ ;
V_16 -> V_138 [ V_2 -> V_31 ] = V_2 ;
return 0 ;
}
static int F_109 ( struct V_29 * V_16 ,
struct V_1 * V_2 )
{
return V_16 -> V_48 -> V_147 ? V_16 -> V_48 -> V_147 ( V_16 , V_2 ) :
F_108 ( V_16 , V_2 ) ;
}
static void F_110 ( struct V_29 * V_16 , struct V_1 * V_2 )
{
if ( V_16 -> V_48 -> remove )
V_16 -> V_48 -> remove ( V_16 , V_2 ) ;
else
V_16 -> V_138 [ V_2 -> V_31 ] = NULL ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_29 * V_16 = V_2 -> V_16 ;
if ( V_16 -> type == V_24 &&
V_16 -> V_25 == V_148 )
return - V_52 ;
if ( ! V_2 -> V_22 )
return - V_113 ;
if ( F_45 ( V_149 , & V_2 -> V_73 ) && ! F_112 ( V_150 ) )
return - V_151 ;
V_2 -> V_22 ++ ;
if ( ! V_2 -> V_152 )
return F_113 ( V_2 , V_2 -> V_142 . V_144 ) ;
return 0 ;
}
struct V_1 * F_114 ( struct V_29 * V_16 , int V_136 )
{
struct V_1 * V_2 ;
int V_153 ;
if ( ! F_115 ( V_16 -> V_154 ) )
return F_102 ( - V_43 ) ;
V_2 = F_116 ( V_16 , V_136 ) ;
if ( ! V_2 ) {
V_153 = - V_11 ;
goto V_155;
}
F_50 ( V_2 ) ;
V_153 = F_109 ( V_16 , V_2 ) ;
if ( V_153 < 0 )
goto V_156;
if ( ! V_2 -> V_28 )
V_2 -> V_28 = V_16 -> V_157 [ V_136 ] ;
F_117 ( ! V_2 -> V_28 ,
L_17 ,
V_158 , V_2 -> V_16 -> V_15 ) ;
V_2 -> V_28 -> V_159 = V_2 ;
V_153 = F_118 ( V_2 , V_2 -> V_27 ) ;
if ( V_153 )
goto V_160;
return V_2 ;
V_156:
F_51 ( V_2 ) ;
F_1 ( V_2 ) ;
V_155:
F_119 ( V_16 -> V_154 ) ;
return F_102 ( V_153 ) ;
V_160:
F_51 ( V_2 ) ;
F_120 ( V_2 , L_18 ,
V_153 , V_136 ) ;
F_121 ( V_2 , V_136 ) ;
return F_102 ( V_153 ) ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_139 * V_140 ;
int V_136 = V_2 -> V_31 ;
if ( V_2 -> V_16 -> V_73 & V_141 )
return;
V_140 = V_2 -> V_16 -> V_142 [ V_136 ] ;
if ( V_140 == NULL ) {
V_140 = F_7 ( sizeof( struct V_139 ) , V_10 ) ;
if ( V_140 == NULL )
return;
V_2 -> V_16 -> V_142 [ V_136 ] = V_140 ;
}
* V_140 = V_2 -> V_142 ;
}
static void F_123 ( struct V_1 * V_2 )
{
F_124 ( & V_2 -> V_161 ) ;
F_124 ( & V_2 -> V_99 ) ;
if ( V_2 -> V_27 ) {
F_124 ( & V_2 -> V_27 -> V_161 ) ;
F_124 ( & V_2 -> V_27 -> V_99 ) ;
}
}
static void F_125 ( struct V_97 * V_98 )
{
struct V_1 * V_2 =
F_63 ( V_98 , struct V_1 , V_99 ) ;
struct V_29 * V_16 = V_2 -> V_16 ;
struct V_162 * V_154 = V_16 -> V_154 ;
if ( V_2 -> V_48 -> V_163 )
V_2 -> V_48 -> V_163 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_126 ( V_16 ) ;
F_119 ( V_154 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_127 ( & V_2 -> V_14 ) ;
F_11 ( & V_2 -> V_12 ) ;
F_58 ( V_2 -> V_93 ) ;
F_58 ( V_2 -> V_92 ) ;
F_1 ( V_2 ) ;
}
static void F_128 ( struct V_164 * V_164 )
{
struct V_1 * V_2 = F_63 ( V_164 , struct V_1 , V_164 ) ;
F_129 ( & V_2 -> V_99 , F_125 ) ;
F_66 ( & V_2 -> V_99 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
if ( V_2 )
F_130 ( & V_2 -> V_164 , F_128 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_136 )
{
F_131 ( V_2 -> V_31 != V_136 ) ;
F_131 ( ! F_132 ( & V_41 ) ) ;
if ( V_2 -> V_48 -> V_165 )
V_2 -> V_48 -> V_165 ( V_2 ) ;
F_122 ( V_2 ) ;
F_110 ( V_2 -> V_16 , V_2 ) ;
V_2 -> V_28 -> V_159 = NULL ;
if ( V_2 -> V_27 )
V_2 -> V_27 -> V_28 -> V_159 = NULL ;
F_133 ( V_2 -> V_28 ) ;
F_54 ( V_2 -> V_27 ) ;
F_54 ( V_2 ) ;
}
static int F_134 ( struct V_1 * V_2 , int V_136 )
{
#ifdef F_18
if ( V_136 < 0 || V_136 >= V_2 -> V_16 -> V_35 ) {
F_135 ( V_2 , L_19 , V_136 ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_73 & V_166 )
return 0 ;
if ( V_2 != V_2 -> V_16 -> V_138 [ V_136 ] ) {
F_135 ( V_2 , L_20 ,
V_136 , V_2 -> V_16 -> V_138 [ V_136 ] ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_167 ) {
struct V_1 * V_168 = V_2 -> V_27 ;
if ( V_168 != V_2 -> V_16 -> V_167 -> V_138 [ V_136 ] ) {
F_135 ( V_2 , L_21 ,
V_136 , V_2 -> V_16 -> V_167 -> V_138 [ V_136 ] ) ;
return - 1 ;
}
if ( V_168 -> V_27 != V_2 ) {
F_135 ( V_2 , L_22 , V_168 -> V_27 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
void F_136 ( struct V_1 * V_2 )
{
F_137 ( V_2 ) ;
F_123 ( V_2 ) ;
F_65 ( V_2 , L_23 ) ;
F_33 ( & V_41 ) ;
F_138 ( V_2 -> V_28 , 0 ) ;
F_121 ( V_2 , V_2 -> V_31 ) ;
F_34 ( & V_41 ) ;
}
void F_139 ( struct V_1 * V_2 , int V_136 )
{
F_137 ( V_2 ) ;
F_123 ( V_2 ) ;
F_65 ( V_2 , L_23 ) ;
F_33 ( & V_41 ) ;
F_121 ( V_2 , V_136 ) ;
F_34 ( & V_41 ) ;
}
int F_140 ( struct V_17 * V_17 , struct V_6 * V_53 )
{
struct V_1 * V_2 = F_5 ( V_53 ) ;
struct V_1 * V_168 = NULL ;
int V_169 , V_170 ;
int V_136 ;
long V_171 = 0 ;
int V_172 = 1 ;
if ( F_17 ( V_2 , V_17 , V_158 ) )
return 0 ;
F_50 ( V_2 ) ;
F_22 ( V_2 , V_158 ) ;
F_52 ( - 1 , V_53 , 0 ) ;
V_136 = V_2 -> V_31 ;
if ( V_2 -> V_16 -> type == V_24 &&
V_2 -> V_16 -> V_25 == V_148 )
V_168 = V_2 -> V_27 ;
if ( F_134 ( V_2 , V_136 ) ) {
F_51 ( V_2 ) ;
return 0 ;
}
F_65 ( V_2 , L_24 , V_2 -> V_22 ) ;
if ( V_2 -> V_48 -> V_95 )
V_2 -> V_48 -> V_95 ( V_2 , V_53 ) ;
F_141 ( V_168 ) ;
while ( 1 ) {
V_169 = 0 ;
if ( V_2 -> V_22 <= 1 ) {
if ( F_142 ( & V_2 -> V_173 ) ) {
F_143 ( & V_2 -> V_173 , V_55 ) ;
V_169 ++ ;
}
if ( F_142 ( & V_2 -> V_75 ) ) {
F_143 ( & V_2 -> V_75 , V_56 ) ;
V_169 ++ ;
}
}
if ( V_168 && V_168 -> V_22 <= 1 ) {
if ( F_142 ( & V_168 -> V_173 ) ) {
F_143 ( & V_168 -> V_173 , V_55 ) ;
V_169 ++ ;
}
if ( F_142 ( & V_168 -> V_75 ) ) {
F_143 ( & V_168 -> V_75 , V_56 ) ;
V_169 ++ ;
}
}
if ( ! V_169 )
break;
if ( V_172 ) {
V_172 = 0 ;
F_26 ( V_2 , L_25 ) ;
}
F_144 ( V_171 ) ;
if ( V_171 < 120 * V_174 )
V_171 = 2 * V_171 + 1 ;
else
V_171 = V_175 ;
}
if ( V_168 ) {
if ( -- V_168 -> V_22 < 0 ) {
F_26 ( V_2 , L_26 , V_168 -> V_22 ) ;
V_168 -> V_22 = 0 ;
}
}
if ( -- V_2 -> V_22 < 0 ) {
F_26 ( V_2 , L_27 , V_2 -> V_22 ) ;
V_2 -> V_22 = 0 ;
}
F_13 ( V_53 ) ;
if ( ! V_2 -> V_22 ) {
F_145 ( & V_176 ) ;
F_146 ( V_2 -> V_92 ) ;
if ( V_168 )
F_146 ( V_168 -> V_92 ) ;
F_147 ( & V_176 ) ;
}
V_170 = ! V_2 -> V_22 && ! ( V_168 && V_168 -> V_22 ) ;
F_148 ( V_168 ) ;
F_51 ( V_2 ) ;
if ( ! V_170 )
return 0 ;
F_65 ( V_2 , L_28 ) ;
F_139 ( V_2 , V_136 ) ;
return 0 ;
}
static struct V_1 * F_149 ( T_1 V_30 , struct V_6 * V_53 )
{
struct V_1 * V_2 ;
int V_153 ;
if ( V_30 != F_29 ( V_177 , 0 ) )
return NULL ;
V_2 = F_69 () ;
if ( ! V_2 )
return F_102 ( - V_178 ) ;
V_53 -> V_117 |= V_179 ;
F_50 ( V_2 ) ;
F_54 ( V_2 ) ;
V_153 = F_111 ( V_2 ) ;
if ( V_153 < 0 ) {
F_51 ( V_2 ) ;
V_2 = F_102 ( V_153 ) ;
}
return V_2 ;
}
static struct V_29 * F_150 ( T_1 V_30 , struct V_6 * V_53 ,
int * V_31 )
{
struct V_29 * V_16 ;
switch ( V_30 ) {
#ifdef F_151
case F_29 ( V_180 , 0 ) : {
extern struct V_29 * V_181 ;
V_16 = F_30 ( V_181 ) ;
* V_31 = V_182 ;
break;
}
#endif
case F_29 ( V_177 , 1 ) : {
struct V_29 * V_181 = F_152 ( V_31 ) ;
if ( V_181 ) {
V_16 = F_30 ( V_181 ) ;
if ( V_16 && V_53 ) {
V_53 -> V_117 |= V_179 ;
break;
}
}
return F_102 ( - V_43 ) ;
}
default:
V_16 = F_27 ( V_30 , V_31 ) ;
if ( ! V_16 )
return F_102 ( - V_43 ) ;
break;
}
return V_16 ;
}
struct V_1 * F_153 ( T_1 V_30 )
{
struct V_1 * V_2 ;
struct V_29 * V_16 = NULL ;
int V_31 = - 1 ;
F_33 ( & V_41 ) ;
V_16 = F_150 ( V_30 , NULL , & V_31 ) ;
if ( F_103 ( V_16 ) ) {
F_34 ( & V_41 ) ;
return F_154 ( V_16 ) ;
}
V_2 = F_101 ( V_16 , NULL , V_31 ) ;
if ( F_103 ( V_2 ) )
goto V_42;
if ( V_2 ) {
F_54 ( V_2 ) ;
V_2 = F_102 ( - V_151 ) ;
} else {
V_2 = F_114 ( V_16 , V_31 ) ;
if ( F_103 ( V_2 ) )
goto V_42;
F_138 ( V_2 -> V_28 , 1 ) ;
}
V_42:
F_34 ( & V_41 ) ;
F_126 ( V_16 ) ;
return V_2 ;
}
static struct V_1 * F_155 ( T_1 V_30 , struct V_17 * V_17 ,
struct V_6 * V_53 )
{
struct V_1 * V_2 ;
struct V_29 * V_16 = NULL ;
int V_31 = - 1 ;
int V_153 ;
F_33 ( & V_41 ) ;
V_16 = F_150 ( V_30 , V_53 , & V_31 ) ;
if ( F_103 ( V_16 ) ) {
F_34 ( & V_41 ) ;
return F_154 ( V_16 ) ;
}
V_2 = F_101 ( V_16 , V_53 , V_31 ) ;
if ( F_103 ( V_2 ) ) {
F_34 ( & V_41 ) ;
goto V_42;
}
if ( V_2 ) {
if ( F_25 ( V_2 -> V_28 ) ) {
F_54 ( V_2 ) ;
F_34 ( & V_41 ) ;
V_2 = F_102 ( - V_151 ) ;
goto V_42;
}
F_34 ( & V_41 ) ;
V_153 = F_156 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( V_153 ) {
if ( V_153 == - V_183 )
V_153 = - V_114 ;
V_2 = F_102 ( V_153 ) ;
goto V_42;
}
V_153 = F_111 ( V_2 ) ;
if ( V_153 < 0 ) {
F_51 ( V_2 ) ;
V_2 = F_102 ( V_153 ) ;
}
} else {
V_2 = F_114 ( V_16 , V_31 ) ;
F_34 ( & V_41 ) ;
}
V_42:
F_126 ( V_16 ) ;
return V_2 ;
}
static int F_157 ( struct V_17 * V_17 , struct V_6 * V_53 )
{
struct V_1 * V_2 ;
int V_184 , V_153 ;
T_1 V_30 = V_17 -> V_185 ;
unsigned V_186 = V_53 -> V_117 ;
F_158 ( V_17 , V_53 ) ;
V_187:
V_153 = F_6 ( V_53 ) ;
if ( V_153 )
return - V_11 ;
V_2 = F_149 ( V_30 , V_53 ) ;
if ( ! V_2 )
V_2 = F_155 ( V_30 , V_17 , V_53 ) ;
if ( F_103 ( V_2 ) ) {
F_12 ( V_53 ) ;
V_153 = F_159 ( V_2 ) ;
if ( V_153 != - V_113 || F_90 ( V_124 ) )
return V_153 ;
F_160 () ;
goto V_187;
}
F_8 ( V_2 , V_53 ) ;
F_22 ( V_2 , V_158 ) ;
F_65 ( V_2 , L_29 , V_2 -> V_22 ) ;
if ( V_2 -> V_48 -> V_188 )
V_153 = V_2 -> V_48 -> V_188 ( V_2 , V_53 ) ;
else
V_153 = - V_43 ;
V_53 -> V_117 = V_186 ;
if ( V_153 ) {
F_65 ( V_2 , L_30 , V_153 ) ;
F_51 ( V_2 ) ;
F_140 ( V_17 , V_53 ) ;
if ( V_153 != - V_114 )
return V_153 ;
if ( F_90 ( V_124 ) )
return V_153 ;
F_160 () ;
if ( F_71 ( V_53 ) )
V_53 -> V_85 = & V_189 ;
goto V_187;
}
F_57 ( V_84 , & V_2 -> V_73 ) ;
V_184 = ( V_53 -> V_117 & V_190 ) ||
( F_161 ( F_151 ) && V_30 == F_29 ( V_180 , 0 ) ) ||
V_30 == F_29 ( V_177 , 1 ) ||
( V_2 -> V_16 -> type == V_24 &&
V_2 -> V_16 -> V_25 == V_148 ) ;
if ( ! V_184 )
F_162 ( V_53 , V_2 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static unsigned int F_163 ( struct V_6 * V_53 , T_6 * V_54 )
{
struct V_1 * V_2 = F_5 ( V_53 ) ;
struct V_70 * V_71 ;
int V_37 = 0 ;
if ( F_17 ( V_2 , F_81 ( V_53 ) , L_31 ) )
return 0 ;
V_71 = F_83 ( V_2 ) ;
if ( ! V_71 )
return F_39 ( V_53 , V_54 ) ;
if ( V_71 -> V_48 -> V_191 )
V_37 = V_71 -> V_48 -> V_191 ( V_2 , V_53 , V_54 ) ;
F_47 ( V_71 ) ;
return V_37 ;
}
static int F_52 ( int V_65 , struct V_6 * V_53 , int V_66 )
{
struct V_1 * V_2 = F_5 ( V_53 ) ;
unsigned long V_73 ;
int V_153 = 0 ;
if ( F_17 ( V_2 , F_81 ( V_53 ) , L_32 ) )
goto V_42;
V_153 = F_164 ( V_65 , V_53 , V_66 , & V_2 -> V_192 ) ;
if ( V_153 <= 0 )
goto V_42;
if ( V_66 ) {
enum V_193 type ;
struct V_194 * V_194 ;
F_74 ( & V_2 -> V_90 , V_73 ) ;
if ( V_2 -> V_93 ) {
V_194 = V_2 -> V_93 ;
type = V_195 ;
} else {
V_194 = F_165 ( V_124 ) ;
type = V_196 ;
}
F_166 ( V_194 ) ;
F_75 ( & V_2 -> V_90 , V_73 ) ;
F_167 ( V_53 , V_194 , type , 0 ) ;
F_58 ( V_194 ) ;
V_153 = 0 ;
}
V_42:
return V_153 ;
}
static int F_168 ( int V_65 , struct V_6 * V_53 , int V_66 )
{
struct V_1 * V_2 = F_5 ( V_53 ) ;
int V_153 = - V_64 ;
F_50 ( V_2 ) ;
if ( ! F_71 ( V_53 ) )
V_153 = F_52 ( V_65 , V_53 , V_66 ) ;
F_51 ( V_2 ) ;
return V_153 ;
}
static int F_169 ( struct V_1 * V_2 , char T_3 * V_21 )
{
char V_129 , V_197 = 0 ;
struct V_70 * V_71 ;
if ( ( V_124 -> signal -> V_2 != V_2 ) && ! F_112 ( V_150 ) )
return - V_198 ;
if ( F_170 ( V_129 , V_21 ) )
return - V_123 ;
F_171 ( V_2 , V_129 ) ;
V_71 = F_83 ( V_2 ) ;
if ( ! V_71 )
return - V_52 ;
V_71 -> V_48 -> V_199 ( V_2 , & V_129 , & V_197 , 1 ) ;
F_47 ( V_71 ) ;
return 0 ;
}
static int F_172 ( struct V_1 * V_2 , struct V_200 T_3 * V_62 )
{
int V_201 ;
F_33 ( & V_2 -> V_202 ) ;
V_201 = F_173 ( V_62 , & V_2 -> V_200 , sizeof( * V_62 ) ) ;
F_34 ( & V_2 -> V_202 ) ;
return V_201 ? - V_123 : 0 ;
}
int F_174 ( struct V_1 * V_2 , struct V_200 * V_203 )
{
struct V_194 * V_93 ;
F_33 ( & V_2 -> V_202 ) ;
if ( ! memcmp ( V_203 , & V_2 -> V_200 , sizeof( * V_203 ) ) )
goto V_204;
V_93 = F_175 ( V_2 ) ;
if ( V_93 )
F_176 ( V_93 , V_205 , 1 ) ;
F_58 ( V_93 ) ;
V_2 -> V_200 = * V_203 ;
V_204:
F_34 ( & V_2 -> V_202 ) ;
return 0 ;
}
static int F_177 ( struct V_1 * V_2 , struct V_200 T_3 * V_62 )
{
struct V_200 V_206 ;
if ( F_89 ( & V_206 , V_62 , sizeof( * V_62 ) ) )
return - V_123 ;
if ( V_2 -> V_48 -> V_207 )
return V_2 -> V_48 -> V_207 ( V_2 , & V_206 ) ;
else
return F_174 ( V_2 , & V_206 ) ;
}
static int F_178 ( struct V_6 * V_6 )
{
if ( ! F_112 ( V_150 ) )
return - V_198 ;
if ( V_6 -> V_85 -> V_86 == V_87 ) {
struct V_6 * V_78 ;
F_9 ( & V_82 ) ;
V_78 = V_83 ;
V_83 = NULL ;
F_11 ( & V_82 ) ;
if ( V_78 )
F_61 ( V_78 ) ;
return 0 ;
}
F_9 ( & V_82 ) ;
if ( V_83 ) {
F_11 ( & V_82 ) ;
return - V_151 ;
}
V_83 = F_94 ( V_6 ) ;
F_11 ( & V_82 ) ;
return 0 ;
}
static int F_179 ( struct V_6 * V_6 , int T_3 * V_21 )
{
int V_208 ;
if ( F_170 ( V_208 , V_21 ) )
return - V_123 ;
F_9 ( & V_6 -> V_209 ) ;
if ( V_208 )
V_6 -> V_117 |= V_179 ;
else
V_6 -> V_117 &= ~ V_179 ;
F_11 ( & V_6 -> V_209 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_210 ;
int V_37 ;
if ( F_170 ( V_210 , V_21 ) )
return - V_123 ;
V_37 = F_181 ( V_2 , V_210 ) ;
return V_37 ;
}
static int F_182 ( struct V_1 * V_2 , int T_3 * V_21 )
{
struct V_70 * V_71 ;
int V_37 ;
V_71 = F_83 ( V_2 ) ;
if ( ! V_71 )
return - V_52 ;
V_37 = F_183 ( V_71 -> V_48 -> V_35 , V_21 ) ;
F_47 ( V_71 ) ;
return V_37 ;
}
static int F_184 ( struct V_1 * V_2 , unsigned int V_211 )
{
int V_153 ;
if ( V_2 -> V_48 -> V_212 == NULL )
return 0 ;
if ( V_2 -> V_16 -> V_73 & V_213 )
V_153 = V_2 -> V_48 -> V_212 ( V_2 , V_211 ) ;
else {
if ( F_85 ( V_2 , 0 ) < 0 )
return - V_183 ;
V_153 = V_2 -> V_48 -> V_212 ( V_2 , - 1 ) ;
if ( V_153 )
goto V_42;
if ( ! F_90 ( V_124 ) )
F_185 ( V_211 ) ;
V_153 = V_2 -> V_48 -> V_212 ( V_2 , 0 ) ;
V_42:
F_84 ( V_2 ) ;
if ( F_90 ( V_124 ) )
V_153 = - V_183 ;
}
return V_153 ;
}
static int F_186 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_153 = - V_40 ;
if ( V_2 -> V_48 -> V_214 ) {
V_153 = V_2 -> V_48 -> V_214 ( V_2 ) ;
if ( V_153 >= 0 )
V_153 = F_183 ( V_153 , V_21 ) ;
}
return V_153 ;
}
static int F_187 ( struct V_1 * V_2 , unsigned int V_61 ,
unsigned T_3 * V_21 )
{
int V_153 ;
unsigned int V_215 , V_216 , V_217 ;
if ( V_2 -> V_48 -> V_218 == NULL )
return - V_40 ;
V_153 = F_170 ( V_217 , V_21 ) ;
if ( V_153 )
return V_153 ;
V_215 = V_216 = 0 ;
switch ( V_61 ) {
case V_219 :
V_215 = V_217 ;
break;
case V_220 :
V_216 = V_217 ;
break;
case V_221 :
V_215 = V_217 ;
V_216 = ~ V_217 ;
break;
}
V_215 &= V_222 | V_223 | V_224 | V_225 | V_226 ;
V_216 &= V_222 | V_223 | V_224 | V_225 | V_226 ;
return V_2 -> V_48 -> V_218 ( V_2 , V_215 , V_216 ) ;
}
static int F_188 ( struct V_1 * V_2 , void T_3 * V_62 )
{
int V_153 = - V_40 ;
struct V_227 V_228 ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
if ( V_2 -> V_48 -> V_229 )
V_153 = V_2 -> V_48 -> V_229 ( V_2 , & V_228 ) ;
if ( V_153 != 0 )
return V_153 ;
if ( F_173 ( V_62 , & V_228 , sizeof( V_228 ) ) )
return - V_123 ;
return 0 ;
}
static void F_189 ( struct V_230 T_3 * V_231 )
{
static F_190 ( V_232 ,
V_233 ,
V_234 ) ;
char V_235 [ V_236 ] ;
int V_73 ;
if ( F_170 ( V_73 , & V_231 -> V_73 ) )
return;
V_73 &= V_237 ;
if ( V_73 && F_191 ( & V_232 ) )
F_19 ( L_33 ,
V_158 , F_192 ( V_235 , V_124 ) , V_73 ) ;
}
static struct V_1 * F_193 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> type == V_24 &&
V_2 -> V_16 -> V_25 == V_148 )
V_2 = V_2 -> V_27 ;
return V_2 ;
}
long F_194 ( struct V_6 * V_6 , unsigned int V_61 , unsigned long V_62 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_1 * V_238 ;
void T_3 * V_21 = ( void T_3 * ) V_62 ;
int V_153 ;
struct V_70 * V_71 ;
if ( F_17 ( V_2 , F_81 ( V_6 ) , L_34 ) )
return - V_40 ;
V_238 = F_193 ( V_2 ) ;
switch ( V_61 ) {
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
V_153 = F_195 ( V_2 ) ;
if ( V_153 )
return V_153 ;
if ( V_61 != V_241 ) {
F_196 ( V_2 , 0 ) ;
if ( F_90 ( V_124 ) )
return - V_183 ;
}
break;
}
switch ( V_61 ) {
case V_244 :
return F_169 ( V_2 , V_21 ) ;
case V_245 :
return F_172 ( V_238 , V_21 ) ;
case V_246 :
return F_177 ( V_238 , V_21 ) ;
case V_247 :
return V_238 != V_2 ? - V_40 : F_178 ( V_6 ) ;
case V_248 :
return F_179 ( V_6 , V_21 ) ;
case V_249 :
F_60 ( V_149 , & V_2 -> V_73 ) ;
return 0 ;
case V_250 :
F_57 ( V_149 , & V_2 -> V_73 ) ;
return 0 ;
case V_251 :
{
int V_252 = F_45 ( V_149 , & V_2 -> V_73 ) ;
return F_183 ( V_252 , ( int T_3 * ) V_21 ) ;
}
case V_253 :
return F_182 ( V_2 , V_21 ) ;
case V_239 :
return F_180 ( V_2 , V_21 ) ;
case V_254 :
if ( ! F_112 ( V_150 ) )
return - V_198 ;
F_67 ( V_2 ) ;
return 0 ;
case V_255 :
{
unsigned int V_37 = F_197 ( F_198 ( V_238 ) ) ;
return F_183 ( V_37 , ( unsigned int T_3 * ) V_21 ) ;
}
case V_240 :
if ( V_2 -> V_48 -> V_212 )
return V_2 -> V_48 -> V_212 ( V_2 , - 1 ) ;
return 0 ;
case V_241 :
if ( V_2 -> V_48 -> V_212 )
return V_2 -> V_48 -> V_212 ( V_2 , 0 ) ;
return 0 ;
case V_242 :
if ( ! V_62 )
return F_184 ( V_2 , 250 ) ;
return 0 ;
case V_243 :
return F_184 ( V_2 , V_62 ? V_62 * 100 : 250 ) ;
case V_256 :
return F_186 ( V_2 , V_21 ) ;
case V_221 :
case V_220 :
case V_219 :
return F_187 ( V_2 , V_61 , V_21 ) ;
case V_257 :
V_153 = F_188 ( V_2 , V_21 ) ;
if ( V_153 != - V_40 )
return V_153 ;
break;
case V_258 :
switch ( V_62 ) {
case V_259 :
case V_260 :
F_199 ( V_2 , NULL ) ;
break;
}
break;
case V_261 :
F_189 ( V_21 ) ;
break;
case V_262 :
return F_200 ( V_6 , V_2 , ( int ) V_62 ) ;
default:
V_153 = F_201 ( V_2 , V_238 , V_6 , V_61 , V_62 ) ;
if ( V_153 != - V_263 )
return V_153 ;
}
if ( V_2 -> V_48 -> V_264 ) {
V_153 = V_2 -> V_48 -> V_264 ( V_2 , V_61 , V_62 ) ;
if ( V_153 != - V_263 )
return V_153 ;
}
V_71 = F_83 ( V_2 ) ;
if ( ! V_71 )
return F_40 ( V_6 , V_61 , V_62 ) ;
V_153 = - V_40 ;
if ( V_71 -> V_48 -> V_264 ) {
V_153 = V_71 -> V_48 -> V_264 ( V_2 , V_6 , V_61 , V_62 ) ;
if ( V_153 == - V_263 )
V_153 = - V_64 ;
}
F_47 ( V_71 ) ;
return V_153 ;
}
static long F_202 ( struct V_6 * V_6 , unsigned int V_61 ,
unsigned long V_62 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_70 * V_71 ;
int V_153 = - V_263 ;
if ( F_17 ( V_2 , F_81 ( V_6 ) , L_34 ) )
return - V_40 ;
if ( V_2 -> V_48 -> V_265 ) {
V_153 = V_2 -> V_48 -> V_265 ( V_2 , V_61 , V_62 ) ;
if ( V_153 != - V_263 )
return V_153 ;
}
V_71 = F_83 ( V_2 ) ;
if ( ! V_71 )
return F_41 ( V_6 , V_61 , V_62 ) ;
if ( V_71 -> V_48 -> V_265 )
V_153 = V_71 -> V_48 -> V_265 ( V_2 , V_6 , V_61 , V_62 ) ;
else
V_153 = F_203 ( V_2 , V_6 , V_61 , V_62 ) ;
F_47 ( V_71 ) ;
return V_153 ;
}
static int F_204 ( const void * V_266 , struct V_6 * V_6 , unsigned V_65 )
{
if ( F_205 ( V_6 -> V_85 -> V_109 != F_80 ) )
return 0 ;
return F_5 ( V_6 ) != V_266 ? 0 : V_65 + 1 ;
}
void F_206 ( struct V_1 * V_2 )
{
#ifdef F_207
F_64 ( V_2 ) ;
#else
struct V_267 * V_268 , * V_21 ;
struct V_194 * V_92 ;
int V_108 ;
if ( ! V_2 )
return;
V_92 = V_2 -> V_92 ;
F_208 ( V_2 ) ;
F_209 ( V_2 ) ;
F_145 ( & V_176 ) ;
F_210 (session, PIDTYPE_SID, p) {
F_211 ( V_2 , L_35 ,
F_212 ( V_21 ) , V_21 -> V_235 ) ;
F_213 ( V_269 , V_21 , 1 ) ;
} F_214 ( V_92 , V_270 , V_21 ) ;
F_215 (g, p) {
if ( V_21 -> signal -> V_2 == V_2 ) {
F_211 ( V_2 , L_36 ,
F_212 ( V_21 ) , V_21 -> V_235 ) ;
F_213 ( V_269 , V_21 , 1 ) ;
continue;
}
F_216 ( V_21 ) ;
V_108 = F_217 ( V_21 -> V_271 , 0 , F_204 , V_2 ) ;
if ( V_108 != 0 ) {
F_211 ( V_2 , L_37 ,
F_212 ( V_21 ) , V_21 -> V_235 , V_108 - 1 ) ;
F_218 ( V_269 , V_21 ) ;
}
F_219 ( V_21 ) ;
} F_220 ( V_268 , V_21 ) ;
F_147 ( & V_176 ) ;
#endif
}
static void F_221 ( struct V_97 * V_98 )
{
struct V_1 * V_2 =
F_63 ( V_98 , struct V_1 , V_161 ) ;
F_206 ( V_2 ) ;
}
void F_222 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_66 ( & V_2 -> V_161 ) ;
}
static int F_223 ( struct V_30 * V_3 , const void * V_272 )
{
const T_1 * V_273 = V_272 ;
return V_3 -> V_273 == * V_273 ;
}
static struct V_30 * F_224 ( struct V_1 * V_2 )
{
T_1 V_273 = F_198 ( V_2 ) ;
return F_225 ( V_274 , NULL , & V_273 , F_223 ) ;
}
struct V_1 * F_116 ( struct V_29 * V_16 , int V_136 )
{
struct V_1 * V_2 ;
V_2 = F_226 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_227 ( & V_2 -> V_164 ) ;
V_2 -> V_5 = V_19 ;
F_228 ( V_2 ) ;
V_2 -> V_92 = NULL ;
V_2 -> V_93 = NULL ;
F_229 ( & V_2 -> V_275 ) ;
F_229 ( & V_2 -> V_276 ) ;
F_230 ( & V_2 -> V_132 ) ;
F_229 ( & V_2 -> V_202 ) ;
F_231 ( & V_2 -> V_277 ) ;
F_232 ( & V_2 -> V_75 ) ;
F_232 ( & V_2 -> V_173 ) ;
F_129 ( & V_2 -> V_99 , F_62 ) ;
F_229 ( & V_2 -> V_111 ) ;
F_233 ( & V_2 -> V_90 ) ;
F_233 ( & V_2 -> V_102 ) ;
F_233 ( & V_2 -> V_12 ) ;
F_234 ( & V_2 -> V_14 ) ;
F_129 ( & V_2 -> V_161 , F_221 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_48 = V_16 -> V_48 ;
V_2 -> V_31 = V_136 ;
F_100 ( V_16 , V_136 , V_2 -> V_15 ) ;
V_2 -> V_3 = F_224 ( V_2 ) ;
return V_2 ;
}
int F_235 ( struct V_1 * V_2 , unsigned char V_129 )
{
if ( V_2 -> V_48 -> V_278 )
return V_2 -> V_48 -> V_278 ( V_2 , V_129 ) ;
return V_2 -> V_48 -> V_86 ( V_2 , & V_129 , 1 ) ;
}
static int F_236 ( struct V_29 * V_16 , T_1 V_3 ,
unsigned int V_31 , unsigned int V_22 )
{
int V_201 ;
V_16 -> V_279 [ V_31 ] = F_237 () ;
if ( ! V_16 -> V_279 [ V_31 ] )
return - V_11 ;
V_16 -> V_279 [ V_31 ] -> V_48 = & V_189 ;
V_16 -> V_279 [ V_31 ] -> V_154 = V_16 -> V_154 ;
V_201 = F_238 ( V_16 -> V_279 [ V_31 ] , V_3 , V_22 ) ;
if ( V_201 )
F_239 ( & V_16 -> V_279 [ V_31 ] -> V_280 ) ;
return V_201 ;
}
struct V_30 * F_240 ( struct V_29 * V_16 , unsigned V_31 ,
struct V_30 * V_30 )
{
return F_241 ( V_16 , V_31 , V_30 , NULL , NULL ) ;
}
static void F_242 ( struct V_30 * V_3 )
{
F_243 ( V_3 , L_38 ) ;
F_4 ( V_3 ) ;
}
struct V_30 * F_241 ( struct V_29 * V_16 ,
unsigned V_31 , struct V_30 * V_30 ,
void * V_281 ,
const struct V_282 * * V_283 )
{
char V_15 [ 64 ] ;
T_1 V_273 = F_29 ( V_16 -> V_33 , V_16 -> V_34 ) + V_31 ;
struct V_139 * V_140 ;
struct V_30 * V_3 ;
int V_153 ;
if ( V_31 >= V_16 -> V_35 ) {
F_244 ( L_39 ,
V_16 -> V_15 , V_31 ) ;
return F_102 ( - V_40 ) ;
}
if ( V_16 -> type == V_24 )
F_99 ( V_16 , V_31 , V_15 ) ;
else
F_100 ( V_16 , V_31 , V_15 ) ;
V_3 = F_226 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 )
return F_102 ( - V_11 ) ;
V_3 -> V_273 = V_273 ;
V_3 -> V_284 = V_274 ;
V_3 -> V_285 = V_30 ;
V_3 -> V_286 = F_242 ;
F_245 ( V_3 , L_15 , V_15 ) ;
V_3 -> V_287 = V_283 ;
F_246 ( V_3 , V_281 ) ;
F_247 ( V_3 , 1 ) ;
V_153 = F_248 ( V_3 ) ;
if ( V_153 )
goto V_288;
if ( ! ( V_16 -> V_73 & V_289 ) ) {
V_140 = V_16 -> V_142 [ V_31 ] ;
if ( V_140 ) {
V_16 -> V_142 [ V_31 ] = NULL ;
F_4 ( V_140 ) ;
}
V_153 = F_236 ( V_16 , V_273 , V_31 , 1 ) ;
if ( V_153 )
goto V_290;
}
F_247 ( V_3 , 0 ) ;
F_249 ( & V_3 -> V_280 , V_291 ) ;
return V_3 ;
V_290:
F_250 ( V_3 ) ;
V_288:
F_3 ( V_3 ) ;
return F_102 ( V_153 ) ;
}
void F_251 ( struct V_29 * V_16 , unsigned V_31 )
{
F_252 ( V_274 ,
F_29 ( V_16 -> V_33 , V_16 -> V_34 ) + V_31 ) ;
if ( ! ( V_16 -> V_73 & V_289 ) ) {
F_253 ( V_16 -> V_279 [ V_31 ] ) ;
V_16 -> V_279 [ V_31 ] = NULL ;
}
}
struct V_29 * F_254 ( unsigned int V_292 , struct V_162 * V_154 ,
unsigned long V_73 )
{
struct V_29 * V_16 ;
unsigned int V_279 = 1 ;
int V_201 ;
if ( ! V_292 || ( V_73 & V_135 && V_292 > 1 ) )
return F_102 ( - V_40 ) ;
V_16 = F_226 ( sizeof( struct V_29 ) , V_10 ) ;
if ( ! V_16 )
return F_102 ( - V_11 ) ;
F_227 ( & V_16 -> V_164 ) ;
V_16 -> V_5 = V_293 ;
V_16 -> V_35 = V_292 ;
V_16 -> V_154 = V_154 ;
V_16 -> V_73 = V_73 ;
if ( ! ( V_73 & V_166 ) ) {
V_16 -> V_138 = F_255 ( V_292 , sizeof( * V_16 -> V_138 ) ,
V_10 ) ;
V_16 -> V_142 = F_255 ( V_292 , sizeof( * V_16 -> V_142 ) ,
V_10 ) ;
if ( ! V_16 -> V_138 || ! V_16 -> V_142 ) {
V_201 = - V_11 ;
goto V_294;
}
}
if ( ! ( V_73 & V_289 ) ) {
V_16 -> V_157 = F_255 ( V_292 , sizeof( * V_16 -> V_157 ) ,
V_10 ) ;
if ( ! V_16 -> V_157 ) {
V_201 = - V_11 ;
goto V_294;
}
V_279 = V_292 ;
}
V_16 -> V_279 = F_255 ( V_279 , sizeof( * V_16 -> V_279 ) , V_10 ) ;
if ( ! V_16 -> V_279 ) {
V_201 = - V_11 ;
goto V_294;
}
return V_16 ;
V_294:
F_4 ( V_16 -> V_157 ) ;
F_4 ( V_16 -> V_138 ) ;
F_4 ( V_16 -> V_142 ) ;
F_4 ( V_16 -> V_279 ) ;
F_4 ( V_16 ) ;
return F_102 ( V_201 ) ;
}
static void F_256 ( struct V_164 * V_164 )
{
struct V_29 * V_16 = F_63 ( V_164 , struct V_29 , V_164 ) ;
int V_108 ;
struct V_139 * V_140 ;
if ( V_16 -> V_73 & V_295 ) {
for ( V_108 = 0 ; V_108 < V_16 -> V_35 ; V_108 ++ ) {
V_140 = V_16 -> V_142 [ V_108 ] ;
if ( V_140 ) {
V_16 -> V_142 [ V_108 ] = NULL ;
F_4 ( V_140 ) ;
}
if ( ! ( V_16 -> V_73 & V_296 ) )
F_251 ( V_16 , V_108 ) ;
}
F_257 ( V_16 ) ;
if ( V_16 -> V_73 & V_289 )
F_253 ( V_16 -> V_279 [ 0 ] ) ;
}
F_4 ( V_16 -> V_279 ) ;
F_4 ( V_16 -> V_157 ) ;
F_4 ( V_16 -> V_142 ) ;
F_4 ( V_16 -> V_138 ) ;
F_4 ( V_16 ) ;
}
void F_126 ( struct V_29 * V_16 )
{
F_130 ( & V_16 -> V_164 , F_256 ) ;
}
void F_258 ( struct V_29 * V_16 ,
const struct V_297 * V_298 )
{
V_16 -> V_48 = V_298 ;
}
void F_259 ( struct V_29 * V_299 )
{
F_126 ( V_299 ) ;
}
int F_260 ( struct V_29 * V_16 )
{
int error ;
int V_108 ;
T_1 V_3 ;
struct V_30 * V_299 ;
if ( ! V_16 -> V_33 ) {
error = F_261 ( & V_3 , V_16 -> V_34 ,
V_16 -> V_35 , V_16 -> V_15 ) ;
if ( ! error ) {
V_16 -> V_33 = F_262 ( V_3 ) ;
V_16 -> V_34 = F_263 ( V_3 ) ;
}
} else {
V_3 = F_29 ( V_16 -> V_33 , V_16 -> V_34 ) ;
error = F_264 ( V_3 , V_16 -> V_35 , V_16 -> V_15 ) ;
}
if ( error < 0 )
goto V_201;
if ( V_16 -> V_73 & V_289 ) {
error = F_236 ( V_16 , V_3 , 0 , V_16 -> V_35 ) ;
if ( error )
goto V_300;
}
F_33 ( & V_41 ) ;
F_10 ( & V_16 -> V_301 , & V_301 ) ;
F_34 ( & V_41 ) ;
if ( ! ( V_16 -> V_73 & V_296 ) ) {
for ( V_108 = 0 ; V_108 < V_16 -> V_35 ; V_108 ++ ) {
V_299 = F_240 ( V_16 , V_108 , NULL ) ;
if ( F_103 ( V_299 ) ) {
error = F_159 ( V_299 ) ;
goto V_302;
}
}
}
F_265 ( V_16 ) ;
V_16 -> V_73 |= V_295 ;
return 0 ;
V_302:
for ( V_108 -- ; V_108 >= 0 ; V_108 -- )
F_251 ( V_16 , V_108 ) ;
F_33 ( & V_41 ) ;
F_14 ( & V_16 -> V_301 ) ;
F_34 ( & V_41 ) ;
V_300:
F_266 ( V_3 , V_16 -> V_35 ) ;
V_201:
return error ;
}
int F_267 ( struct V_29 * V_16 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_266 ( F_29 ( V_16 -> V_33 , V_16 -> V_34 ) ,
V_16 -> V_35 ) ;
F_33 ( & V_41 ) ;
F_14 ( & V_16 -> V_301 ) ;
F_34 ( & V_41 ) ;
return 0 ;
}
T_1 F_198 ( struct V_1 * V_2 )
{
return F_29 ( V_2 -> V_16 -> V_33 , V_2 -> V_16 -> V_34 ) + V_2 -> V_31 ;
}
void F_268 ( struct V_303 * V_304 )
{
* V_304 = V_189 ;
}
static char * F_269 ( struct V_30 * V_3 , T_7 * V_305 )
{
if ( ! V_305 )
return NULL ;
if ( V_3 -> V_273 == F_29 ( V_177 , 0 ) ||
V_3 -> V_273 == F_29 ( V_177 , 2 ) )
* V_305 = 0666 ;
return NULL ;
}
static int T_8 F_270 ( void )
{
V_274 = F_271 ( V_306 , L_14 ) ;
if ( F_103 ( V_274 ) )
return F_159 ( V_274 ) ;
V_274 -> V_307 = F_269 ;
return 0 ;
}
static T_2 F_272 ( struct V_30 * V_3 ,
struct V_308 * V_309 , char * V_50 )
{
struct V_310 * V_311 [ 16 ] ;
int V_108 = 0 ;
struct V_310 * V_312 ;
T_2 V_22 = 0 ;
F_273 () ;
F_274 (c) {
if ( ! V_312 -> V_30 )
continue;
if ( ! V_312 -> V_86 )
continue;
if ( ( V_312 -> V_73 & V_313 ) == 0 )
continue;
V_311 [ V_108 ++ ] = V_312 ;
if ( V_108 >= F_275 ( V_311 ) )
break;
}
while ( V_108 -- ) {
int V_31 = V_311 [ V_108 ] -> V_31 ;
struct V_29 * V_314 = V_311 [ V_108 ] -> V_30 ( V_311 [ V_108 ] , & V_31 ) ;
if ( V_314 && ( V_311 [ V_108 ] -> V_31 > 0 || V_314 -> V_33 != V_180 ) )
V_22 += F_100 ( V_314 , V_31 , V_50 + V_22 ) ;
else
V_22 += sprintf ( V_50 + V_22 , L_16 ,
V_311 [ V_108 ] -> V_15 , V_311 [ V_108 ] -> V_31 ) ;
V_22 += sprintf ( V_50 + V_22 , L_40 , V_108 ? ' ' : '\n' ) ;
}
F_276 () ;
return V_22 ;
}
void F_277 ( void )
{
if ( V_315 )
F_278 ( & V_315 -> V_280 , NULL , L_41 ) ;
}
int T_8 F_279 ( void )
{
F_280 ( & V_316 , & V_189 ) ;
if ( F_238 ( & V_316 , F_29 ( V_177 , 0 ) , 1 ) ||
F_264 ( F_29 ( V_177 , 0 ) , 1 , L_42 ) < 0 )
F_281 ( L_43 ) ;
F_282 ( V_274 , NULL , F_29 ( V_177 , 0 ) , NULL , L_14 ) ;
F_280 ( & V_317 , & V_318 ) ;
if ( F_238 ( & V_317 , F_29 ( V_177 , 1 ) , 1 ) ||
F_264 ( F_29 ( V_177 , 1 ) , 1 , L_44 ) < 0 )
F_281 ( L_45 ) ;
V_315 = F_283 ( V_274 , NULL ,
F_29 ( V_177 , 1 ) , NULL ,
V_319 , L_46 ) ;
if ( F_103 ( V_315 ) )
V_315 = NULL ;
#ifdef F_151
F_284 ( & V_318 ) ;
#endif
return 0 ;
}
