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
static T_2 F_34 ( struct V_6 * V_6 , char T_3 * V_42 ,
T_4 V_22 , T_5 * V_43 )
{
return 0 ;
}
static T_2 F_35 ( struct V_6 * V_6 , const char T_3 * V_42 ,
T_4 V_22 , T_5 * V_43 )
{
return - V_44 ;
}
static unsigned int F_36 ( struct V_6 * V_45 , T_6 * V_46 )
{
return V_47 | V_48 | V_49 | V_50 | V_51 | V_52 ;
}
static long F_37 ( struct V_6 * V_6 , unsigned int V_53 ,
unsigned long V_54 )
{
return V_53 == V_55 ? - V_56 : - V_44 ;
}
static long F_38 ( struct V_6 * V_6 ,
unsigned int V_53 , unsigned long V_54 )
{
return V_53 == V_55 ? - V_56 : - V_44 ;
}
static int F_39 ( int V_57 , struct V_6 * V_6 , int V_58 )
{
return - V_56 ;
}
void F_40 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
if ( F_41 ( V_61 , & V_2 -> V_62 ) ) {
V_60 = F_42 ( V_2 ) ;
if ( V_60 ) {
if ( V_60 -> V_40 -> V_63 )
V_60 -> V_40 -> V_63 ( V_2 ) ;
F_43 ( V_60 ) ;
}
}
F_44 ( & V_2 -> V_64 , V_48 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_65 )
{
struct V_6 * V_66 = NULL ;
struct V_6 * V_45 , * V_67 = NULL ;
struct V_7 * V_9 ;
int V_68 = 0 , V_69 ;
int V_70 ;
if ( ! V_2 )
return;
F_9 ( & V_71 ) ;
if ( V_72 && F_5 ( V_72 ) == V_2 ) {
V_67 = V_72 ;
V_72 = NULL ;
}
F_11 ( & V_71 ) ;
F_46 ( V_2 ) ;
if ( F_41 ( V_73 , & V_2 -> V_62 ) ) {
F_47 ( V_2 ) ;
return;
}
F_22 ( V_2 , L_6 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_27 (priv, &tty->tty_files, list) {
V_45 = V_9 -> V_6 ;
if ( V_45 -> V_74 -> V_75 == V_76 )
V_66 = V_45 ;
if ( V_45 -> V_74 -> V_75 != V_77 )
continue;
V_68 ++ ;
F_48 ( - 1 , V_45 , 0 ) ;
V_45 -> V_74 = & V_78 ;
}
F_11 ( & V_2 -> V_12 ) ;
V_70 = F_49 ( V_2 , V_65 ) ;
while ( V_70 -- )
F_50 ( V_2 ) ;
F_51 ( V_2 , V_66 != NULL ) ;
F_52 ( & V_2 -> V_79 ) ;
F_53 ( V_80 , & V_2 -> V_62 ) ;
F_53 ( V_61 , & V_2 -> V_62 ) ;
F_54 ( V_2 -> V_81 ) ;
F_54 ( V_2 -> V_82 ) ;
V_2 -> V_81 = NULL ;
V_2 -> V_82 = NULL ;
V_2 -> V_83 = 0 ;
F_55 ( & V_2 -> V_79 ) ;
if ( V_66 ) {
if ( V_2 -> V_40 -> V_84 )
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ )
V_2 -> V_40 -> V_84 ( V_2 , V_66 ) ;
} else if ( V_2 -> V_40 -> V_85 )
V_2 -> V_40 -> V_85 ( V_2 ) ;
F_56 ( V_73 , & V_2 -> V_62 ) ;
F_47 ( V_2 ) ;
if ( V_67 )
F_57 ( V_67 ) ;
}
static void F_58 ( struct V_86 * V_87 )
{
struct V_1 * V_2 =
F_59 ( V_87 , struct V_1 , V_88 ) ;
F_45 ( V_2 , 0 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_61 ( V_2 , L_7 ) ;
F_62 ( & V_2 -> V_88 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_61 ( V_2 , L_8 ) ;
F_45 ( V_2 , 0 ) ;
}
void F_64 ( void )
{
struct V_1 * V_2 ;
V_2 = F_65 () ;
if ( V_2 ) {
F_63 ( V_2 ) ;
F_50 ( V_2 ) ;
}
}
void F_66 ( struct V_1 * V_2 )
{
F_61 ( V_2 , L_9 ) ;
F_45 ( V_2 , 1 ) ;
}
int F_67 ( struct V_6 * V_45 )
{
return ( V_45 && V_45 -> V_74 == & V_78 ) ;
}
void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_89 )
return;
V_2 -> V_89 = 1 ;
if ( V_2 -> V_40 -> V_90 )
V_2 -> V_40 -> V_90 ( V_2 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
unsigned long V_62 ;
F_70 ( & V_2 -> V_91 , V_62 ) ;
F_68 ( V_2 ) ;
F_71 ( & V_2 -> V_91 , V_62 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_89 || V_2 -> V_92 )
return;
V_2 -> V_89 = 0 ;
if ( V_2 -> V_40 -> V_93 )
V_2 -> V_40 -> V_93 ( V_2 ) ;
F_40 ( V_2 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
unsigned long V_62 ;
F_70 ( & V_2 -> V_91 , V_62 ) ;
F_72 ( V_2 ) ;
F_71 ( & V_2 -> V_91 , V_62 ) ;
}
static void F_74 ( struct V_94 * time )
{
unsigned long V_95 = F_75 () ;
if ( ( V_95 ^ time -> V_96 ) & ~ 7 )
time -> V_96 = V_95 ;
}
static T_2 F_76 ( struct V_6 * V_6 , char T_3 * V_42 , T_4 V_22 ,
T_5 * V_43 )
{
int V_97 ;
struct V_17 * V_17 = F_77 ( V_6 ) ;
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_59 * V_60 ;
if ( F_17 ( V_2 , V_17 , L_10 ) )
return - V_44 ;
if ( ! V_2 || F_78 ( V_2 ) )
return - V_44 ;
V_60 = F_79 ( V_2 ) ;
if ( ! V_60 )
return F_34 ( V_6 , V_42 , V_22 , V_43 ) ;
if ( V_60 -> V_40 -> V_98 )
V_97 = V_60 -> V_40 -> V_98 ( V_2 , V_6 , V_42 , V_22 ) ;
else
V_97 = - V_44 ;
F_43 ( V_60 ) ;
if ( V_97 > 0 )
F_74 ( & V_17 -> V_99 ) ;
return V_97 ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_33 ( & V_2 -> V_100 ) ;
F_44 ( & V_2 -> V_64 , V_48 ) ;
}
static int F_81 ( struct V_1 * V_2 , int V_101 )
{
if ( ! F_82 ( & V_2 -> V_100 ) ) {
if ( V_101 )
return - V_102 ;
if ( F_83 ( & V_2 -> V_100 ) )
return - V_103 ;
}
return 0 ;
}
static inline T_2 F_84 (
T_2 (* V_75)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_42 ,
T_4 V_22 )
{
T_2 V_104 , V_105 = 0 ;
unsigned int V_106 ;
V_104 = F_81 ( V_2 , V_6 -> V_107 & V_108 ) ;
if ( V_104 < 0 )
return V_104 ;
V_106 = 2048 ;
if ( F_41 ( V_109 , & V_2 -> V_62 ) )
V_106 = 65536 ;
if ( V_22 < V_106 )
V_106 = V_22 ;
if ( V_2 -> V_110 < V_106 ) {
unsigned char * V_111 ;
if ( V_106 < 1024 )
V_106 = 1024 ;
V_111 = F_7 ( V_106 , V_10 ) ;
if ( ! V_111 ) {
V_104 = - V_11 ;
goto V_112;
}
F_4 ( V_2 -> V_4 ) ;
V_2 -> V_110 = V_106 ;
V_2 -> V_4 = V_111 ;
}
for (; ; ) {
T_4 V_113 = V_22 ;
if ( V_113 > V_106 )
V_113 = V_106 ;
V_104 = - V_114 ;
if ( F_85 ( V_2 -> V_4 , V_42 , V_113 ) )
break;
V_104 = V_75 ( V_2 , V_6 , V_2 -> V_4 , V_113 ) ;
if ( V_104 <= 0 )
break;
V_105 += V_104 ;
V_42 += V_104 ;
V_22 -= V_104 ;
if ( ! V_22 )
break;
V_104 = - V_103 ;
if ( F_86 ( V_115 ) )
break;
F_87 () ;
}
if ( V_105 ) {
F_74 ( & F_77 ( V_6 ) -> V_116 ) ;
V_104 = V_105 ;
}
V_112:
F_80 ( V_2 ) ;
return V_104 ;
}
void F_88 ( struct V_1 * V_2 , char * V_117 )
{
if ( V_2 ) {
F_32 ( & V_2 -> V_100 ) ;
F_46 ( V_2 ) ;
if ( V_2 -> V_40 -> V_75 && V_2 -> V_22 > 0 )
V_2 -> V_40 -> V_75 ( V_2 , V_117 , strlen ( V_117 ) ) ;
F_47 ( V_2 ) ;
F_80 ( V_2 ) ;
}
return;
}
static T_2 V_77 ( struct V_6 * V_6 , const char T_3 * V_42 ,
T_4 V_22 , T_5 * V_43 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_59 * V_60 ;
T_2 V_104 ;
if ( F_17 ( V_2 , F_77 ( V_6 ) , L_11 ) )
return - V_44 ;
if ( ! V_2 || ! V_2 -> V_40 -> V_75 || F_78 ( V_2 ) )
return - V_44 ;
if ( V_2 -> V_40 -> V_118 == NULL )
F_89 ( V_2 , L_12 ) ;
V_60 = F_79 ( V_2 ) ;
if ( ! V_60 )
return F_35 ( V_6 , V_42 , V_22 , V_43 ) ;
if ( ! V_60 -> V_40 -> V_75 )
V_104 = - V_44 ;
else
V_104 = F_84 ( V_60 -> V_40 -> V_75 , V_2 , V_6 , V_42 , V_22 ) ;
F_43 ( V_60 ) ;
return V_104 ;
}
T_2 V_76 ( struct V_6 * V_6 , const char T_3 * V_42 ,
T_4 V_22 , T_5 * V_43 )
{
struct V_6 * V_21 = NULL ;
F_9 ( & V_71 ) ;
if ( V_72 )
V_21 = F_90 ( V_72 ) ;
F_11 ( & V_71 ) ;
if ( V_21 ) {
T_2 V_34 ;
V_34 = F_91 ( V_21 , V_42 , V_22 , & V_21 -> V_119 ) ;
F_57 ( V_21 ) ;
return V_34 ;
}
return V_77 ( V_6 , V_42 , V_22 , V_43 ) ;
}
int F_92 ( struct V_1 * V_2 , char V_120 )
{
int V_121 = V_2 -> V_89 ;
if ( V_2 -> V_40 -> V_122 ) {
F_93 ( & V_2 -> V_123 ) ;
V_2 -> V_40 -> V_122 ( V_2 , V_120 ) ;
F_94 ( & V_2 -> V_123 ) ;
return 0 ;
}
if ( F_81 ( V_2 , 0 ) < 0 )
return - V_103 ;
F_93 ( & V_2 -> V_123 ) ;
if ( V_121 )
F_73 ( V_2 ) ;
V_2 -> V_40 -> V_75 ( V_2 , & V_120 , 1 ) ;
if ( V_121 )
F_69 ( V_2 ) ;
F_94 ( & V_2 -> V_123 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static void F_95 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
int V_97 = V_29 + V_16 -> V_124 ;
sprintf ( V_21 , L_13 ,
V_16 -> V_24 == V_25 ? L_14 : V_16 -> V_15 ,
V_125 [ V_97 >> 4 & 0xf ] , V_97 & 0xf ) ;
}
static T_2 F_96 ( struct V_27 * V_16 , int V_29 , char * V_21 )
{
if ( V_16 -> V_62 & V_126 )
return sprintf ( V_21 , L_15 , V_16 -> V_15 ) ;
else
return sprintf ( V_21 , L_16 , V_16 -> V_15 ,
V_29 + V_16 -> V_124 ) ;
}
static struct V_1 * F_97 ( struct V_27 * V_16 ,
struct V_6 * V_6 , int V_127 )
{
struct V_1 * V_2 ;
if ( V_16 -> V_40 -> V_128 )
V_2 = V_16 -> V_40 -> V_128 ( V_16 , V_6 , V_127 ) ;
else
V_2 = V_16 -> V_129 [ V_127 ] ;
if ( ! F_98 ( V_2 ) )
F_99 ( V_2 ) ;
return V_2 ;
}
void F_100 ( struct V_1 * V_2 )
{
struct V_130 * V_131 ;
int V_127 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_62 & V_132 )
V_2 -> V_133 = V_2 -> V_16 -> V_134 ;
else {
V_131 = V_2 -> V_16 -> V_133 [ V_127 ] ;
if ( V_131 != NULL ) {
V_2 -> V_133 = * V_131 ;
V_2 -> V_133 . V_135 = V_2 -> V_16 -> V_134 . V_135 ;
} else
V_2 -> V_133 = V_2 -> V_16 -> V_134 ;
}
V_2 -> V_133 . V_136 = F_101 ( & V_2 -> V_133 ) ;
V_2 -> V_133 . V_137 = F_102 ( & V_2 -> V_133 ) ;
}
int F_103 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
F_100 ( V_2 ) ;
F_29 ( V_16 ) ;
V_2 -> V_22 ++ ;
V_16 -> V_129 [ V_2 -> V_29 ] = V_2 ;
return 0 ;
}
static int F_104 ( struct V_27 * V_16 ,
struct V_1 * V_2 )
{
return V_16 -> V_40 -> V_138 ? V_16 -> V_40 -> V_138 ( V_16 , V_2 ) :
F_103 ( V_16 , V_2 ) ;
}
static void F_105 ( struct V_27 * V_16 , struct V_1 * V_2 )
{
if ( V_16 -> V_40 -> remove )
V_16 -> V_40 -> remove ( V_16 , V_2 ) ;
else
V_16 -> V_129 [ V_2 -> V_29 ] = NULL ;
}
static int F_106 ( struct V_1 * V_2 )
{
struct V_27 * V_16 = V_2 -> V_16 ;
if ( V_16 -> type == V_23 &&
V_16 -> V_24 == V_139 )
return - V_44 ;
if ( ! V_2 -> V_22 )
return - V_102 ;
if ( F_41 ( V_140 , & V_2 -> V_62 ) && ! F_107 ( V_141 ) )
return - V_142 ;
V_2 -> V_22 ++ ;
if ( ! V_2 -> V_143 )
return F_108 ( V_2 , V_2 -> V_133 . V_135 ) ;
return 0 ;
}
struct V_1 * F_109 ( struct V_27 * V_16 , int V_127 )
{
struct V_1 * V_2 ;
int V_144 ;
if ( ! F_110 ( V_16 -> V_145 ) )
return F_111 ( - V_146 ) ;
V_2 = F_112 ( V_16 , V_127 ) ;
if ( ! V_2 ) {
V_144 = - V_11 ;
goto V_147;
}
F_46 ( V_2 ) ;
V_144 = F_104 ( V_16 , V_2 ) ;
if ( V_144 < 0 )
goto V_148;
if ( ! V_2 -> V_149 )
V_2 -> V_149 = V_16 -> V_150 [ V_127 ] ;
F_113 ( ! V_2 -> V_149 ,
L_17 ,
V_151 , V_2 -> V_16 -> V_15 ) ;
V_2 -> V_149 -> V_152 = V_2 ;
V_144 = F_114 ( V_2 , V_2 -> V_26 ) ;
if ( V_144 )
goto V_153;
return V_2 ;
V_148:
F_47 ( V_2 ) ;
F_1 ( V_2 ) ;
V_147:
F_115 ( V_16 -> V_145 ) ;
return F_111 ( V_144 ) ;
V_153:
F_47 ( V_2 ) ;
F_116 ( V_2 , L_18 ,
V_144 , V_127 ) ;
F_117 ( V_2 , V_127 ) ;
return F_111 ( V_144 ) ;
}
static void F_118 ( struct V_1 * V_2 )
{
struct V_130 * V_131 ;
int V_127 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> V_62 & V_132 )
return;
V_131 = V_2 -> V_16 -> V_133 [ V_127 ] ;
if ( V_131 == NULL ) {
V_131 = F_7 ( sizeof( struct V_130 ) , V_10 ) ;
if ( V_131 == NULL )
return;
V_2 -> V_16 -> V_133 [ V_127 ] = V_131 ;
}
* V_131 = V_2 -> V_133 ;
}
static void F_119 ( struct V_1 * V_2 )
{
F_120 ( & V_2 -> V_154 ) ;
F_120 ( & V_2 -> V_88 ) ;
if ( V_2 -> V_26 ) {
F_120 ( & V_2 -> V_26 -> V_154 ) ;
F_120 ( & V_2 -> V_26 -> V_88 ) ;
}
}
static void F_121 ( struct V_86 * V_87 )
{
struct V_1 * V_2 =
F_59 ( V_87 , struct V_1 , V_88 ) ;
struct V_27 * V_16 = V_2 -> V_16 ;
struct V_155 * V_145 = V_16 -> V_145 ;
if ( V_2 -> V_40 -> V_156 )
V_2 -> V_40 -> V_156 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_122 ( V_16 ) ;
F_115 ( V_145 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_123 ( & V_2 -> V_14 ) ;
F_11 ( & V_2 -> V_12 ) ;
F_54 ( V_2 -> V_82 ) ;
F_54 ( V_2 -> V_81 ) ;
F_1 ( V_2 ) ;
}
static void F_124 ( struct V_157 * V_157 )
{
struct V_1 * V_2 = F_59 ( V_157 , struct V_1 , V_157 ) ;
F_125 ( & V_2 -> V_88 , F_121 ) ;
F_62 ( & V_2 -> V_88 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
if ( V_2 )
F_126 ( & V_2 -> V_157 , F_124 ) ;
}
static void F_117 ( struct V_1 * V_2 , int V_127 )
{
F_127 ( V_2 -> V_29 != V_127 ) ;
F_127 ( ! F_128 ( & V_39 ) ) ;
if ( V_2 -> V_40 -> V_158 )
V_2 -> V_40 -> V_158 ( V_2 ) ;
F_118 ( V_2 ) ;
F_105 ( V_2 -> V_16 , V_2 ) ;
V_2 -> V_149 -> V_152 = NULL ;
if ( V_2 -> V_26 )
V_2 -> V_26 -> V_149 -> V_152 = NULL ;
F_129 ( V_2 -> V_149 ) ;
F_50 ( V_2 -> V_26 ) ;
F_50 ( V_2 ) ;
}
static int F_130 ( struct V_1 * V_2 , int V_127 )
{
#ifdef F_18
if ( V_127 < 0 || V_127 >= V_2 -> V_16 -> V_33 ) {
F_131 ( V_2 , L_19 , V_127 ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_62 & V_159 )
return 0 ;
if ( V_2 != V_2 -> V_16 -> V_129 [ V_127 ] ) {
F_131 ( V_2 , L_20 ,
V_127 , V_2 -> V_16 -> V_129 [ V_127 ] ) ;
return - 1 ;
}
if ( V_2 -> V_16 -> V_160 ) {
struct V_1 * V_161 = V_2 -> V_26 ;
if ( V_161 != V_2 -> V_16 -> V_160 -> V_129 [ V_127 ] ) {
F_131 ( V_2 , L_21 ,
V_127 , V_2 -> V_16 -> V_160 -> V_129 [ V_127 ] ) ;
return - 1 ;
}
if ( V_161 -> V_26 != V_2 ) {
F_131 ( V_2 , L_22 , V_161 -> V_26 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
void F_132 ( struct V_1 * V_2 , int V_127 )
{
F_133 ( V_2 ) ;
F_119 ( V_2 ) ;
F_61 ( V_2 , L_23 ) ;
F_32 ( & V_39 ) ;
F_117 ( V_2 , V_127 ) ;
F_33 ( & V_39 ) ;
}
int F_134 ( struct V_17 * V_17 , struct V_6 * V_45 )
{
struct V_1 * V_2 = F_5 ( V_45 ) ;
struct V_1 * V_161 = NULL ;
int V_162 , V_163 ;
int V_127 ;
long V_164 = 0 ;
int V_165 = 1 ;
if ( F_17 ( V_2 , V_17 , V_151 ) )
return 0 ;
F_46 ( V_2 ) ;
F_22 ( V_2 , V_151 ) ;
F_48 ( - 1 , V_45 , 0 ) ;
V_127 = V_2 -> V_29 ;
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_139 )
V_161 = V_2 -> V_26 ;
if ( F_130 ( V_2 , V_127 ) ) {
F_47 ( V_2 ) ;
return 0 ;
}
F_61 ( V_2 , L_24 , V_2 -> V_22 ) ;
if ( V_2 -> V_40 -> V_84 )
V_2 -> V_40 -> V_84 ( V_2 , V_45 ) ;
F_135 ( V_161 ) ;
while ( 1 ) {
V_162 = 0 ;
if ( V_2 -> V_22 <= 1 ) {
if ( F_136 ( & V_2 -> V_166 ) ) {
F_137 ( & V_2 -> V_166 , V_47 ) ;
V_162 ++ ;
}
if ( F_136 ( & V_2 -> V_64 ) ) {
F_137 ( & V_2 -> V_64 , V_48 ) ;
V_162 ++ ;
}
}
if ( V_161 && V_161 -> V_22 <= 1 ) {
if ( F_136 ( & V_161 -> V_166 ) ) {
F_137 ( & V_161 -> V_166 , V_47 ) ;
V_162 ++ ;
}
if ( F_136 ( & V_161 -> V_64 ) ) {
F_137 ( & V_161 -> V_64 , V_48 ) ;
V_162 ++ ;
}
}
if ( ! V_162 )
break;
if ( V_165 ) {
V_165 = 0 ;
F_25 ( V_2 , L_25 ) ;
}
F_138 ( V_164 ) ;
if ( V_164 < 120 * V_167 )
V_164 = 2 * V_164 + 1 ;
else
V_164 = V_168 ;
}
if ( V_161 ) {
if ( -- V_161 -> V_22 < 0 ) {
F_25 ( V_2 , L_26 , V_161 -> V_22 ) ;
V_161 -> V_22 = 0 ;
}
}
if ( -- V_2 -> V_22 < 0 ) {
F_25 ( V_2 , L_27 , V_2 -> V_22 ) ;
V_2 -> V_22 = 0 ;
}
F_13 ( V_45 ) ;
if ( ! V_2 -> V_22 ) {
F_139 ( & V_169 ) ;
F_140 ( V_2 -> V_81 ) ;
if ( V_161 )
F_140 ( V_161 -> V_81 ) ;
F_141 ( & V_169 ) ;
}
V_163 = ! V_2 -> V_22 && ! ( V_161 && V_161 -> V_22 ) ;
F_142 ( V_161 ) ;
F_47 ( V_2 ) ;
if ( ! V_163 )
return 0 ;
F_61 ( V_2 , L_28 ) ;
F_132 ( V_2 , V_127 ) ;
return 0 ;
}
static struct V_1 * F_143 ( T_1 V_28 , struct V_6 * V_45 )
{
struct V_1 * V_2 ;
int V_144 ;
if ( V_28 != F_28 ( V_170 , 0 ) )
return NULL ;
V_2 = F_65 () ;
if ( ! V_2 )
return F_111 ( - V_171 ) ;
V_45 -> V_107 |= V_172 ;
F_46 ( V_2 ) ;
F_50 ( V_2 ) ;
V_144 = F_106 ( V_2 ) ;
if ( V_144 < 0 ) {
F_47 ( V_2 ) ;
V_2 = F_111 ( V_144 ) ;
}
return V_2 ;
}
static struct V_27 * F_144 ( T_1 V_28 , struct V_6 * V_45 ,
int * V_29 )
{
struct V_27 * V_16 ;
switch ( V_28 ) {
#ifdef F_145
case F_28 ( V_173 , 0 ) : {
extern struct V_27 * V_174 ;
V_16 = F_29 ( V_174 ) ;
* V_29 = V_175 ;
break;
}
#endif
case F_28 ( V_170 , 1 ) : {
struct V_27 * V_174 = F_146 ( V_29 ) ;
if ( V_174 ) {
V_16 = F_29 ( V_174 ) ;
if ( V_16 ) {
V_45 -> V_107 |= V_172 ;
break;
}
}
return F_111 ( - V_146 ) ;
}
default:
V_16 = F_26 ( V_28 , V_29 ) ;
if ( ! V_16 )
return F_111 ( - V_146 ) ;
break;
}
return V_16 ;
}
static struct V_1 * F_147 ( T_1 V_28 , struct V_17 * V_17 ,
struct V_6 * V_45 )
{
struct V_1 * V_2 ;
struct V_27 * V_16 = NULL ;
int V_29 = - 1 ;
int V_144 ;
F_32 ( & V_39 ) ;
V_16 = F_144 ( V_28 , V_45 , & V_29 ) ;
if ( F_98 ( V_16 ) ) {
F_33 ( & V_39 ) ;
return F_148 ( V_16 ) ;
}
V_2 = F_97 ( V_16 , V_45 , V_29 ) ;
if ( F_98 ( V_2 ) ) {
F_33 ( & V_39 ) ;
goto V_112;
}
if ( V_2 ) {
F_33 ( & V_39 ) ;
V_144 = F_149 ( V_2 ) ;
F_50 ( V_2 ) ;
if ( V_144 ) {
if ( V_144 == - V_176 )
V_144 = - V_103 ;
V_2 = F_111 ( V_144 ) ;
goto V_112;
}
V_144 = F_106 ( V_2 ) ;
if ( V_144 < 0 ) {
F_47 ( V_2 ) ;
V_2 = F_111 ( V_144 ) ;
}
} else {
V_2 = F_109 ( V_16 , V_29 ) ;
F_33 ( & V_39 ) ;
}
V_112:
F_122 ( V_16 ) ;
return V_2 ;
}
static int F_150 ( struct V_17 * V_17 , struct V_6 * V_45 )
{
struct V_1 * V_2 ;
int V_177 , V_144 ;
T_1 V_28 = V_17 -> V_178 ;
unsigned V_179 = V_45 -> V_107 ;
F_151 ( V_17 , V_45 ) ;
V_180:
V_144 = F_6 ( V_45 ) ;
if ( V_144 )
return - V_11 ;
V_2 = F_143 ( V_28 , V_45 ) ;
if ( ! V_2 )
V_2 = F_147 ( V_28 , V_17 , V_45 ) ;
if ( F_98 ( V_2 ) ) {
F_12 ( V_45 ) ;
V_144 = F_152 ( V_2 ) ;
if ( V_144 != - V_102 || F_86 ( V_115 ) )
return V_144 ;
F_153 () ;
goto V_180;
}
F_8 ( V_2 , V_45 ) ;
F_22 ( V_2 , V_151 ) ;
F_61 ( V_2 , L_29 , V_2 -> V_22 ) ;
if ( V_2 -> V_40 -> V_181 )
V_144 = V_2 -> V_40 -> V_181 ( V_2 , V_45 ) ;
else
V_144 = - V_146 ;
V_45 -> V_107 = V_179 ;
if ( V_144 ) {
F_61 ( V_2 , L_30 , V_144 ) ;
F_47 ( V_2 ) ;
F_134 ( V_17 , V_45 ) ;
if ( V_144 != - V_103 )
return V_144 ;
if ( F_86 ( V_115 ) )
return V_144 ;
F_153 () ;
if ( F_67 ( V_45 ) )
V_45 -> V_74 = & V_182 ;
goto V_180;
}
F_53 ( V_73 , & V_2 -> V_62 ) ;
V_177 = ( V_45 -> V_107 & V_183 ) ||
( F_154 ( F_145 ) && V_28 == F_28 ( V_173 , 0 ) ) ||
V_28 == F_28 ( V_170 , 1 ) ||
( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_139 ) ;
if ( ! V_177 )
F_155 ( V_45 , V_2 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
static unsigned int F_156 ( struct V_6 * V_45 , T_6 * V_46 )
{
struct V_1 * V_2 = F_5 ( V_45 ) ;
struct V_59 * V_60 ;
int V_104 = 0 ;
if ( F_17 ( V_2 , F_77 ( V_45 ) , L_31 ) )
return 0 ;
V_60 = F_79 ( V_2 ) ;
if ( ! V_60 )
return F_36 ( V_45 , V_46 ) ;
if ( V_60 -> V_40 -> V_184 )
V_104 = V_60 -> V_40 -> V_184 ( V_2 , V_45 , V_46 ) ;
F_43 ( V_60 ) ;
return V_104 ;
}
static int F_48 ( int V_57 , struct V_6 * V_45 , int V_58 )
{
struct V_1 * V_2 = F_5 ( V_45 ) ;
unsigned long V_62 ;
int V_144 = 0 ;
if ( F_17 ( V_2 , F_77 ( V_45 ) , L_32 ) )
goto V_112;
V_144 = F_157 ( V_57 , V_45 , V_58 , & V_2 -> V_185 ) ;
if ( V_144 <= 0 )
goto V_112;
if ( V_58 ) {
enum V_186 type ;
struct V_187 * V_187 ;
F_70 ( & V_2 -> V_79 , V_62 ) ;
if ( V_2 -> V_82 ) {
V_187 = V_2 -> V_82 ;
type = V_188 ;
} else {
V_187 = F_158 ( V_115 ) ;
type = V_189 ;
}
F_159 ( V_187 ) ;
F_71 ( & V_2 -> V_79 , V_62 ) ;
F_160 ( V_45 , V_187 , type , 0 ) ;
F_54 ( V_187 ) ;
V_144 = 0 ;
}
V_112:
return V_144 ;
}
static int F_161 ( int V_57 , struct V_6 * V_45 , int V_58 )
{
struct V_1 * V_2 = F_5 ( V_45 ) ;
int V_144 = - V_56 ;
F_46 ( V_2 ) ;
if ( ! F_67 ( V_45 ) )
V_144 = F_48 ( V_57 , V_45 , V_58 ) ;
F_47 ( V_2 ) ;
return V_144 ;
}
static int F_162 ( struct V_1 * V_2 , char T_3 * V_21 )
{
char V_120 , V_190 = 0 ;
struct V_59 * V_60 ;
if ( ( V_115 -> signal -> V_2 != V_2 ) && ! F_107 ( V_141 ) )
return - V_191 ;
if ( F_163 ( V_120 , V_21 ) )
return - V_114 ;
F_164 ( V_2 , V_120 ) ;
V_60 = F_79 ( V_2 ) ;
if ( ! V_60 )
return - V_44 ;
V_60 -> V_40 -> V_192 ( V_2 , & V_120 , & V_190 , 1 ) ;
F_43 ( V_60 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , struct V_193 T_3 * V_54 )
{
int V_194 ;
F_32 ( & V_2 -> V_195 ) ;
V_194 = F_166 ( V_54 , & V_2 -> V_193 , sizeof( * V_54 ) ) ;
F_33 ( & V_2 -> V_195 ) ;
return V_194 ? - V_114 : 0 ;
}
int F_167 ( struct V_1 * V_2 , struct V_193 * V_196 )
{
struct V_187 * V_82 ;
F_32 ( & V_2 -> V_195 ) ;
if ( ! memcmp ( V_196 , & V_2 -> V_193 , sizeof( * V_196 ) ) )
goto V_197;
V_82 = F_168 ( V_2 ) ;
if ( V_82 )
F_169 ( V_82 , V_198 , 1 ) ;
F_54 ( V_82 ) ;
V_2 -> V_193 = * V_196 ;
V_197:
F_33 ( & V_2 -> V_195 ) ;
return 0 ;
}
static int F_170 ( struct V_1 * V_2 , struct V_193 T_3 * V_54 )
{
struct V_193 V_199 ;
if ( F_85 ( & V_199 , V_54 , sizeof( * V_54 ) ) )
return - V_114 ;
if ( V_2 -> V_40 -> V_200 )
return V_2 -> V_40 -> V_200 ( V_2 , & V_199 ) ;
else
return F_167 ( V_2 , & V_199 ) ;
}
static int F_171 ( struct V_6 * V_6 )
{
if ( ! F_107 ( V_141 ) )
return - V_191 ;
if ( V_6 -> V_74 -> V_75 == V_76 ) {
struct V_6 * V_67 ;
F_9 ( & V_71 ) ;
V_67 = V_72 ;
V_72 = NULL ;
F_11 ( & V_71 ) ;
if ( V_67 )
F_57 ( V_67 ) ;
return 0 ;
}
F_9 ( & V_71 ) ;
if ( V_72 ) {
F_11 ( & V_71 ) ;
return - V_142 ;
}
V_72 = F_90 ( V_6 ) ;
F_11 ( & V_71 ) ;
return 0 ;
}
static int F_172 ( struct V_6 * V_6 , int T_3 * V_21 )
{
int V_201 ;
if ( F_163 ( V_201 , V_21 ) )
return - V_114 ;
F_9 ( & V_6 -> V_202 ) ;
if ( V_201 )
V_6 -> V_107 |= V_172 ;
else
V_6 -> V_107 &= ~ V_172 ;
F_11 ( & V_6 -> V_202 ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_203 ;
int V_104 ;
if ( F_163 ( V_203 , V_21 ) )
return - V_114 ;
V_104 = F_174 ( V_2 , V_203 ) ;
return V_104 ;
}
static int F_175 ( struct V_1 * V_2 , int T_3 * V_21 )
{
struct V_59 * V_60 ;
int V_104 ;
V_60 = F_79 ( V_2 ) ;
if ( ! V_60 )
return - V_44 ;
V_104 = F_176 ( V_60 -> V_40 -> V_33 , V_21 ) ;
F_43 ( V_60 ) ;
return V_104 ;
}
static int F_177 ( struct V_1 * V_2 , unsigned int V_204 )
{
int V_144 ;
if ( V_2 -> V_40 -> V_205 == NULL )
return 0 ;
if ( V_2 -> V_16 -> V_62 & V_206 )
V_144 = V_2 -> V_40 -> V_205 ( V_2 , V_204 ) ;
else {
if ( F_81 ( V_2 , 0 ) < 0 )
return - V_176 ;
V_144 = V_2 -> V_40 -> V_205 ( V_2 , - 1 ) ;
if ( V_144 )
goto V_112;
if ( ! F_86 ( V_115 ) )
F_178 ( V_204 ) ;
V_144 = V_2 -> V_40 -> V_205 ( V_2 , 0 ) ;
V_112:
F_80 ( V_2 ) ;
if ( F_86 ( V_115 ) )
V_144 = - V_176 ;
}
return V_144 ;
}
static int F_179 ( struct V_1 * V_2 , int T_3 * V_21 )
{
int V_144 = - V_207 ;
if ( V_2 -> V_40 -> V_208 ) {
V_144 = V_2 -> V_40 -> V_208 ( V_2 ) ;
if ( V_144 >= 0 )
V_144 = F_176 ( V_144 , V_21 ) ;
}
return V_144 ;
}
static int F_180 ( struct V_1 * V_2 , unsigned int V_53 ,
unsigned T_3 * V_21 )
{
int V_144 ;
unsigned int V_209 , V_210 , V_211 ;
if ( V_2 -> V_40 -> V_212 == NULL )
return - V_207 ;
V_144 = F_163 ( V_211 , V_21 ) ;
if ( V_144 )
return V_144 ;
V_209 = V_210 = 0 ;
switch ( V_53 ) {
case V_213 :
V_209 = V_211 ;
break;
case V_214 :
V_210 = V_211 ;
break;
case V_215 :
V_209 = V_211 ;
V_210 = ~ V_211 ;
break;
}
V_209 &= V_216 | V_217 | V_218 | V_219 | V_220 ;
V_210 &= V_216 | V_217 | V_218 | V_219 | V_220 ;
return V_2 -> V_40 -> V_212 ( V_2 , V_209 , V_210 ) ;
}
static int F_181 ( struct V_1 * V_2 , void T_3 * V_54 )
{
int V_144 = - V_207 ;
struct V_221 V_222 ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
if ( V_2 -> V_40 -> V_223 )
V_144 = V_2 -> V_40 -> V_223 ( V_2 , & V_222 ) ;
if ( V_144 != 0 )
return V_144 ;
if ( F_166 ( V_54 , & V_222 , sizeof( V_222 ) ) )
return - V_114 ;
return 0 ;
}
static void F_182 ( struct V_224 T_3 * V_225 )
{
static F_183 ( V_226 ,
V_227 ,
V_228 ) ;
char V_229 [ V_230 ] ;
int V_62 ;
if ( F_163 ( V_62 , & V_225 -> V_62 ) )
return;
V_62 &= V_231 ;
if ( V_62 && F_184 ( & V_226 ) )
F_19 ( L_33 ,
V_151 , F_185 ( V_229 , V_115 ) , V_62 ) ;
}
static struct V_1 * F_186 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 -> type == V_23 &&
V_2 -> V_16 -> V_24 == V_139 )
V_2 = V_2 -> V_26 ;
return V_2 ;
}
long F_187 ( struct V_6 * V_6 , unsigned int V_53 , unsigned long V_54 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_1 * V_232 ;
void T_3 * V_21 = ( void T_3 * ) V_54 ;
int V_144 ;
struct V_59 * V_60 ;
if ( F_17 ( V_2 , F_77 ( V_6 ) , L_34 ) )
return - V_207 ;
V_232 = F_186 ( V_2 ) ;
switch ( V_53 ) {
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
V_144 = F_188 ( V_2 ) ;
if ( V_144 )
return V_144 ;
if ( V_53 != V_235 ) {
F_189 ( V_2 , 0 ) ;
if ( F_86 ( V_115 ) )
return - V_176 ;
}
break;
}
switch ( V_53 ) {
case V_238 :
return F_162 ( V_2 , V_21 ) ;
case V_239 :
return F_165 ( V_232 , V_21 ) ;
case V_240 :
return F_170 ( V_232 , V_21 ) ;
case V_241 :
return V_232 != V_2 ? - V_207 : F_171 ( V_6 ) ;
case V_242 :
return F_172 ( V_6 , V_21 ) ;
case V_243 :
F_56 ( V_140 , & V_2 -> V_62 ) ;
return 0 ;
case V_244 :
F_53 ( V_140 , & V_2 -> V_62 ) ;
return 0 ;
case V_245 :
{
int V_246 = F_41 ( V_140 , & V_2 -> V_62 ) ;
return F_176 ( V_246 , ( int T_3 * ) V_21 ) ;
}
case V_247 :
return F_175 ( V_2 , V_21 ) ;
case V_233 :
return F_173 ( V_2 , V_21 ) ;
case V_248 :
if ( ! F_107 ( V_141 ) )
return - V_191 ;
F_63 ( V_2 ) ;
return 0 ;
case V_249 :
{
unsigned int V_104 = F_190 ( F_191 ( V_232 ) ) ;
return F_176 ( V_104 , ( unsigned int T_3 * ) V_21 ) ;
}
case V_234 :
if ( V_2 -> V_40 -> V_205 )
return V_2 -> V_40 -> V_205 ( V_2 , - 1 ) ;
return 0 ;
case V_235 :
if ( V_2 -> V_40 -> V_205 )
return V_2 -> V_40 -> V_205 ( V_2 , 0 ) ;
return 0 ;
case V_236 :
if ( ! V_54 )
return F_177 ( V_2 , 250 ) ;
return 0 ;
case V_237 :
return F_177 ( V_2 , V_54 ? V_54 * 100 : 250 ) ;
case V_250 :
return F_179 ( V_2 , V_21 ) ;
case V_215 :
case V_214 :
case V_213 :
return F_180 ( V_2 , V_53 , V_21 ) ;
case V_251 :
V_144 = F_181 ( V_2 , V_21 ) ;
if ( V_144 != - V_207 )
return V_144 ;
break;
case V_252 :
switch ( V_54 ) {
case V_253 :
case V_254 :
F_192 ( V_2 , NULL ) ;
break;
}
break;
case V_255 :
F_182 ( V_21 ) ;
break;
default:
V_144 = F_193 ( V_2 , V_232 , V_6 , V_53 , V_54 ) ;
if ( V_144 != - V_256 )
return V_144 ;
}
if ( V_2 -> V_40 -> V_257 ) {
V_144 = V_2 -> V_40 -> V_257 ( V_2 , V_53 , V_54 ) ;
if ( V_144 != - V_256 )
return V_144 ;
}
V_60 = F_79 ( V_2 ) ;
if ( ! V_60 )
return F_37 ( V_6 , V_53 , V_54 ) ;
V_144 = - V_207 ;
if ( V_60 -> V_40 -> V_257 ) {
V_144 = V_60 -> V_40 -> V_257 ( V_2 , V_6 , V_53 , V_54 ) ;
if ( V_144 == - V_256 )
V_144 = - V_56 ;
}
F_43 ( V_60 ) ;
return V_144 ;
}
static long F_194 ( struct V_6 * V_6 , unsigned int V_53 ,
unsigned long V_54 )
{
struct V_1 * V_2 = F_5 ( V_6 ) ;
struct V_59 * V_60 ;
int V_144 = - V_256 ;
if ( F_17 ( V_2 , F_77 ( V_6 ) , L_34 ) )
return - V_207 ;
if ( V_2 -> V_40 -> V_258 ) {
V_144 = V_2 -> V_40 -> V_258 ( V_2 , V_53 , V_54 ) ;
if ( V_144 != - V_256 )
return V_144 ;
}
V_60 = F_79 ( V_2 ) ;
if ( ! V_60 )
return F_38 ( V_6 , V_53 , V_54 ) ;
if ( V_60 -> V_40 -> V_258 )
V_144 = V_60 -> V_40 -> V_258 ( V_2 , V_6 , V_53 , V_54 ) ;
else
V_144 = F_195 ( V_2 , V_6 , V_53 , V_54 ) ;
F_43 ( V_60 ) ;
return V_144 ;
}
static int F_196 ( const void * V_259 , struct V_6 * V_6 , unsigned V_57 )
{
if ( F_197 ( V_6 -> V_74 -> V_98 != F_76 ) )
return 0 ;
return F_5 ( V_6 ) != V_259 ? 0 : V_57 + 1 ;
}
void F_198 ( struct V_1 * V_2 )
{
#ifdef F_199
F_60 ( V_2 ) ;
#else
struct V_260 * V_261 , * V_21 ;
struct V_187 * V_81 ;
int V_97 ;
if ( ! V_2 )
return;
V_81 = V_2 -> V_81 ;
F_200 ( V_2 ) ;
F_201 ( V_2 ) ;
F_139 ( & V_169 ) ;
F_202 (session, PIDTYPE_SID, p) {
F_203 ( V_2 , L_35 ,
F_204 ( V_21 ) , V_21 -> V_229 ) ;
F_205 ( V_262 , V_21 , 1 ) ;
} F_206 ( V_81 , V_263 , V_21 ) ;
F_207 (g, p) {
if ( V_21 -> signal -> V_2 == V_2 ) {
F_203 ( V_2 , L_36 ,
F_204 ( V_21 ) , V_21 -> V_229 ) ;
F_205 ( V_262 , V_21 , 1 ) ;
continue;
}
F_208 ( V_21 ) ;
V_97 = F_209 ( V_21 -> V_264 , 0 , F_196 , V_2 ) ;
if ( V_97 != 0 ) {
F_203 ( V_2 , L_37 ,
F_204 ( V_21 ) , V_21 -> V_229 , V_97 - 1 ) ;
F_210 ( V_262 , V_21 ) ;
}
F_211 ( V_21 ) ;
} F_212 ( V_261 , V_21 ) ;
F_141 ( & V_169 ) ;
#endif
}
static void F_213 ( struct V_86 * V_87 )
{
struct V_1 * V_2 =
F_59 ( V_87 , struct V_1 , V_154 ) ;
F_198 ( V_2 ) ;
}
void F_214 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_62 ( & V_2 -> V_154 ) ;
}
static int F_215 ( struct V_28 * V_3 , const void * V_265 )
{
const T_1 * V_266 = V_265 ;
return V_3 -> V_266 == * V_266 ;
}
static struct V_28 * F_216 ( struct V_1 * V_2 )
{
T_1 V_266 = F_191 ( V_2 ) ;
return F_217 ( V_267 , NULL , & V_266 , F_215 ) ;
}
struct V_1 * F_112 ( struct V_27 * V_16 , int V_127 )
{
struct V_1 * V_2 ;
V_2 = F_218 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_219 ( & V_2 -> V_157 ) ;
V_2 -> V_5 = V_19 ;
F_220 ( V_2 ) ;
V_2 -> V_81 = NULL ;
V_2 -> V_82 = NULL ;
F_221 ( & V_2 -> V_268 ) ;
F_221 ( & V_2 -> V_269 ) ;
F_222 ( & V_2 -> V_123 ) ;
F_221 ( & V_2 -> V_195 ) ;
F_223 ( & V_2 -> V_270 ) ;
F_224 ( & V_2 -> V_64 ) ;
F_224 ( & V_2 -> V_166 ) ;
F_125 ( & V_2 -> V_88 , F_58 ) ;
F_221 ( & V_2 -> V_100 ) ;
F_225 ( & V_2 -> V_79 ) ;
F_225 ( & V_2 -> V_91 ) ;
F_225 ( & V_2 -> V_12 ) ;
F_226 ( & V_2 -> V_14 ) ;
F_125 ( & V_2 -> V_154 , F_213 ) ;
V_2 -> V_16 = V_16 ;
V_2 -> V_40 = V_16 -> V_40 ;
V_2 -> V_29 = V_127 ;
F_96 ( V_16 , V_127 , V_2 -> V_15 ) ;
V_2 -> V_3 = F_216 ( V_2 ) ;
return V_2 ;
}
int F_227 ( struct V_1 * V_2 , unsigned char V_120 )
{
if ( V_2 -> V_40 -> V_271 )
return V_2 -> V_40 -> V_271 ( V_2 , V_120 ) ;
return V_2 -> V_40 -> V_75 ( V_2 , & V_120 , 1 ) ;
}
static int F_228 ( struct V_27 * V_16 , T_1 V_3 ,
unsigned int V_29 , unsigned int V_22 )
{
int V_194 ;
V_16 -> V_272 [ V_29 ] = F_229 () ;
if ( ! V_16 -> V_272 [ V_29 ] )
return - V_11 ;
V_16 -> V_272 [ V_29 ] -> V_40 = & V_182 ;
V_16 -> V_272 [ V_29 ] -> V_145 = V_16 -> V_145 ;
V_194 = F_230 ( V_16 -> V_272 [ V_29 ] , V_3 , V_22 ) ;
if ( V_194 )
F_231 ( & V_16 -> V_272 [ V_29 ] -> V_273 ) ;
return V_194 ;
}
struct V_28 * F_232 ( struct V_27 * V_16 , unsigned V_29 ,
struct V_28 * V_28 )
{
return F_233 ( V_16 , V_29 , V_28 , NULL , NULL ) ;
}
static void F_234 ( struct V_28 * V_3 )
{
F_235 ( V_3 , L_38 ) ;
F_4 ( V_3 ) ;
}
struct V_28 * F_233 ( struct V_27 * V_16 ,
unsigned V_29 , struct V_28 * V_28 ,
void * V_274 ,
const struct V_275 * * V_276 )
{
char V_15 [ 64 ] ;
T_1 V_266 = F_28 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ;
struct V_130 * V_131 ;
struct V_28 * V_3 ;
int V_144 ;
if ( V_29 >= V_16 -> V_33 ) {
F_236 ( L_39 ,
V_16 -> V_15 , V_29 ) ;
return F_111 ( - V_207 ) ;
}
if ( V_16 -> type == V_23 )
F_95 ( V_16 , V_29 , V_15 ) ;
else
F_96 ( V_16 , V_29 , V_15 ) ;
V_3 = F_218 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 )
return F_111 ( - V_11 ) ;
V_3 -> V_266 = V_266 ;
V_3 -> V_277 = V_267 ;
V_3 -> V_278 = V_28 ;
V_3 -> V_279 = F_234 ;
F_237 ( V_3 , L_15 , V_15 ) ;
V_3 -> V_280 = V_276 ;
F_238 ( V_3 , V_274 ) ;
F_239 ( V_3 , 1 ) ;
V_144 = F_240 ( V_3 ) ;
if ( V_144 )
goto V_281;
if ( ! ( V_16 -> V_62 & V_282 ) ) {
V_131 = V_16 -> V_133 [ V_29 ] ;
if ( V_131 ) {
V_16 -> V_133 [ V_29 ] = NULL ;
F_4 ( V_131 ) ;
}
V_144 = F_228 ( V_16 , V_266 , V_29 , 1 ) ;
if ( V_144 )
goto V_283;
}
F_239 ( V_3 , 0 ) ;
F_241 ( & V_3 -> V_273 , V_284 ) ;
return V_3 ;
V_283:
F_242 ( V_3 ) ;
V_281:
F_3 ( V_3 ) ;
return F_111 ( V_144 ) ;
}
void F_243 ( struct V_27 * V_16 , unsigned V_29 )
{
F_244 ( V_267 ,
F_28 ( V_16 -> V_31 , V_16 -> V_32 ) + V_29 ) ;
if ( ! ( V_16 -> V_62 & V_282 ) ) {
F_245 ( V_16 -> V_272 [ V_29 ] ) ;
V_16 -> V_272 [ V_29 ] = NULL ;
}
}
struct V_27 * F_246 ( unsigned int V_285 , struct V_155 * V_145 ,
unsigned long V_62 )
{
struct V_27 * V_16 ;
unsigned int V_272 = 1 ;
int V_194 ;
if ( ! V_285 || ( V_62 & V_126 && V_285 > 1 ) )
return F_111 ( - V_207 ) ;
V_16 = F_218 ( sizeof( struct V_27 ) , V_10 ) ;
if ( ! V_16 )
return F_111 ( - V_11 ) ;
F_219 ( & V_16 -> V_157 ) ;
V_16 -> V_5 = V_286 ;
V_16 -> V_33 = V_285 ;
V_16 -> V_145 = V_145 ;
V_16 -> V_62 = V_62 ;
if ( ! ( V_62 & V_159 ) ) {
V_16 -> V_129 = F_247 ( V_285 , sizeof( * V_16 -> V_129 ) ,
V_10 ) ;
V_16 -> V_133 = F_247 ( V_285 , sizeof( * V_16 -> V_133 ) ,
V_10 ) ;
if ( ! V_16 -> V_129 || ! V_16 -> V_133 ) {
V_194 = - V_11 ;
goto V_287;
}
}
if ( ! ( V_62 & V_282 ) ) {
V_16 -> V_150 = F_247 ( V_285 , sizeof( * V_16 -> V_150 ) ,
V_10 ) ;
if ( ! V_16 -> V_150 ) {
V_194 = - V_11 ;
goto V_287;
}
V_272 = V_285 ;
}
V_16 -> V_272 = F_247 ( V_272 , sizeof( * V_16 -> V_272 ) , V_10 ) ;
if ( ! V_16 -> V_272 ) {
V_194 = - V_11 ;
goto V_287;
}
return V_16 ;
V_287:
F_4 ( V_16 -> V_150 ) ;
F_4 ( V_16 -> V_129 ) ;
F_4 ( V_16 -> V_133 ) ;
F_4 ( V_16 -> V_272 ) ;
F_4 ( V_16 ) ;
return F_111 ( V_194 ) ;
}
static void F_248 ( struct V_157 * V_157 )
{
struct V_27 * V_16 = F_59 ( V_157 , struct V_27 , V_157 ) ;
int V_97 ;
struct V_130 * V_131 ;
if ( V_16 -> V_62 & V_288 ) {
for ( V_97 = 0 ; V_97 < V_16 -> V_33 ; V_97 ++ ) {
V_131 = V_16 -> V_133 [ V_97 ] ;
if ( V_131 ) {
V_16 -> V_133 [ V_97 ] = NULL ;
F_4 ( V_131 ) ;
}
if ( ! ( V_16 -> V_62 & V_289 ) )
F_243 ( V_16 , V_97 ) ;
}
F_249 ( V_16 ) ;
if ( V_16 -> V_62 & V_282 )
F_245 ( V_16 -> V_272 [ 0 ] ) ;
}
F_4 ( V_16 -> V_272 ) ;
F_4 ( V_16 -> V_150 ) ;
F_4 ( V_16 -> V_133 ) ;
F_4 ( V_16 -> V_129 ) ;
F_4 ( V_16 ) ;
}
void F_122 ( struct V_27 * V_16 )
{
F_126 ( & V_16 -> V_157 , F_248 ) ;
}
void F_250 ( struct V_27 * V_16 ,
const struct V_290 * V_291 )
{
V_16 -> V_40 = V_291 ;
}
void F_251 ( struct V_27 * V_292 )
{
F_122 ( V_292 ) ;
}
int F_252 ( struct V_27 * V_16 )
{
int error ;
int V_97 ;
T_1 V_3 ;
struct V_28 * V_292 ;
if ( ! V_16 -> V_31 ) {
error = F_253 ( & V_3 , V_16 -> V_32 ,
V_16 -> V_33 , V_16 -> V_15 ) ;
if ( ! error ) {
V_16 -> V_31 = F_254 ( V_3 ) ;
V_16 -> V_32 = F_255 ( V_3 ) ;
}
} else {
V_3 = F_28 ( V_16 -> V_31 , V_16 -> V_32 ) ;
error = F_256 ( V_3 , V_16 -> V_33 , V_16 -> V_15 ) ;
}
if ( error < 0 )
goto V_194;
if ( V_16 -> V_62 & V_282 ) {
error = F_228 ( V_16 , V_3 , 0 , V_16 -> V_33 ) ;
if ( error )
goto V_293;
}
F_32 ( & V_39 ) ;
F_10 ( & V_16 -> V_294 , & V_294 ) ;
F_33 ( & V_39 ) ;
if ( ! ( V_16 -> V_62 & V_289 ) ) {
for ( V_97 = 0 ; V_97 < V_16 -> V_33 ; V_97 ++ ) {
V_292 = F_232 ( V_16 , V_97 , NULL ) ;
if ( F_98 ( V_292 ) ) {
error = F_152 ( V_292 ) ;
goto V_295;
}
}
}
F_257 ( V_16 ) ;
V_16 -> V_62 |= V_288 ;
return 0 ;
V_295:
for ( V_97 -- ; V_97 >= 0 ; V_97 -- )
F_243 ( V_16 , V_97 ) ;
F_32 ( & V_39 ) ;
F_14 ( & V_16 -> V_294 ) ;
F_33 ( & V_39 ) ;
V_293:
F_258 ( V_3 , V_16 -> V_33 ) ;
V_194:
return error ;
}
int F_259 ( struct V_27 * V_16 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_258 ( F_28 ( V_16 -> V_31 , V_16 -> V_32 ) ,
V_16 -> V_33 ) ;
F_32 ( & V_39 ) ;
F_14 ( & V_16 -> V_294 ) ;
F_33 ( & V_39 ) ;
return 0 ;
}
T_1 F_191 ( struct V_1 * V_2 )
{
return F_28 ( V_2 -> V_16 -> V_31 , V_2 -> V_16 -> V_32 ) + V_2 -> V_29 ;
}
void F_260 ( struct V_296 * V_297 )
{
* V_297 = V_182 ;
}
static char * F_261 ( struct V_28 * V_3 , T_7 * V_298 )
{
if ( ! V_298 )
return NULL ;
if ( V_3 -> V_266 == F_28 ( V_170 , 0 ) ||
V_3 -> V_266 == F_28 ( V_170 , 2 ) )
* V_298 = 0666 ;
return NULL ;
}
static int T_8 F_262 ( void )
{
V_267 = F_263 ( V_299 , L_14 ) ;
if ( F_98 ( V_267 ) )
return F_152 ( V_267 ) ;
V_267 -> V_300 = F_261 ;
return 0 ;
}
static T_2 F_264 ( struct V_28 * V_3 ,
struct V_301 * V_302 , char * V_42 )
{
struct V_303 * V_304 [ 16 ] ;
int V_97 = 0 ;
struct V_303 * V_305 ;
T_2 V_22 = 0 ;
F_265 () ;
F_266 (c) {
if ( ! V_305 -> V_28 )
continue;
if ( ! V_305 -> V_75 )
continue;
if ( ( V_305 -> V_62 & V_306 ) == 0 )
continue;
V_304 [ V_97 ++ ] = V_305 ;
if ( V_97 >= F_267 ( V_304 ) )
break;
}
while ( V_97 -- ) {
int V_29 = V_304 [ V_97 ] -> V_29 ;
struct V_27 * V_307 = V_304 [ V_97 ] -> V_28 ( V_304 [ V_97 ] , & V_29 ) ;
if ( V_307 && ( V_304 [ V_97 ] -> V_29 > 0 || V_307 -> V_31 != V_173 ) )
V_22 += F_96 ( V_307 , V_29 , V_42 + V_22 ) ;
else
V_22 += sprintf ( V_42 + V_22 , L_16 ,
V_304 [ V_97 ] -> V_15 , V_304 [ V_97 ] -> V_29 ) ;
V_22 += sprintf ( V_42 + V_22 , L_40 , V_97 ? ' ' : '\n' ) ;
}
F_268 () ;
return V_22 ;
}
void F_269 ( void )
{
if ( V_308 )
F_270 ( & V_308 -> V_273 , NULL , L_41 ) ;
}
int T_8 F_271 ( void )
{
F_272 ( & V_309 , & V_182 ) ;
if ( F_230 ( & V_309 , F_28 ( V_170 , 0 ) , 1 ) ||
F_256 ( F_28 ( V_170 , 0 ) , 1 , L_42 ) < 0 )
F_273 ( L_43 ) ;
F_274 ( V_267 , NULL , F_28 ( V_170 , 0 ) , NULL , L_14 ) ;
F_272 ( & V_310 , & V_311 ) ;
if ( F_230 ( & V_310 , F_28 ( V_170 , 1 ) , 1 ) ||
F_256 ( F_28 ( V_170 , 1 ) , 1 , L_44 ) < 0 )
F_273 ( L_45 ) ;
V_308 = F_275 ( V_267 , NULL ,
F_28 ( V_170 , 1 ) , NULL ,
V_312 , L_46 ) ;
if ( F_98 ( V_308 ) )
V_308 = NULL ;
#ifdef F_145
F_276 ( & V_311 ) ;
#endif
return 0 ;
}
