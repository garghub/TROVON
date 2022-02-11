struct V_1 * F_1 ( void )
{
return F_2 ( sizeof( struct V_1 ) , V_2 ) ;
}
void F_3 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
if ( V_3 -> V_4 )
F_4 ( V_3 -> V_4 ) ;
F_5 ( V_3 -> V_5 ) ;
V_3 -> V_6 = 0xDEADDEAD ;
F_5 ( V_3 ) ;
}
static inline struct V_1 * F_6 ( struct V_7 * V_7 )
{
return ( (struct V_8 * ) V_7 -> V_9 ) -> V_3 ;
}
int F_7 ( struct V_7 * V_7 )
{
struct V_8 * V_10 ;
V_10 = F_8 ( sizeof( * V_10 ) , V_2 ) ;
if ( ! V_10 )
return - V_11 ;
V_7 -> V_9 = V_10 ;
return 0 ;
}
void F_9 ( struct V_1 * V_3 , struct V_7 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_9 ;
V_10 -> V_3 = V_3 ;
V_10 -> V_7 = V_7 ;
F_10 ( & V_12 ) ;
F_11 ( & V_10 -> V_13 , & V_3 -> V_14 ) ;
F_12 ( & V_12 ) ;
}
void F_13 ( struct V_7 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_9 ;
V_7 -> V_9 = NULL ;
F_5 ( V_10 ) ;
}
static void F_14 ( struct V_7 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_9 ;
F_10 ( & V_12 ) ;
F_15 ( & V_10 -> V_13 ) ;
F_12 ( & V_12 ) ;
F_13 ( V_7 ) ;
}
char * F_16 ( struct V_1 * V_3 , char * V_15 )
{
if ( ! V_3 )
strcpy ( V_15 , L_1 ) ;
else
strcpy ( V_15 , V_3 -> V_16 ) ;
return V_15 ;
}
int F_17 ( struct V_1 * V_3 , struct V_17 * V_17 ,
const char * V_18 )
{
#ifdef F_18
if ( ! V_3 ) {
F_19 ( V_19
L_2 ,
F_20 ( V_17 ) , F_21 ( V_17 ) , V_18 ) ;
return 1 ;
}
if ( V_3 -> V_6 != V_20 ) {
F_19 ( V_19
L_3 ,
F_20 ( V_17 ) , F_21 ( V_17 ) , V_18 ) ;
return 1 ;
}
#endif
return 0 ;
}
static int F_22 ( struct V_1 * V_3 , const char * V_18 )
{
#ifdef F_23
struct V_21 * V_22 ;
int V_23 = 0 ;
F_10 ( & V_12 ) ;
F_24 (p, &tty->tty_files) {
V_23 ++ ;
}
F_12 ( & V_12 ) ;
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_27 &&
V_3 -> V_28 && V_3 -> V_28 -> V_23 )
V_23 ++ ;
if ( V_3 -> V_23 != V_23 ) {
F_19 ( V_19 L_4
L_5 ,
V_3 -> V_16 , V_3 -> V_23 , V_23 , V_18 ) ;
return V_23 ;
}
#endif
return 0 ;
}
static struct V_29 * F_25 ( T_1 V_30 , int * V_31 )
{
struct V_29 * V_22 ;
F_26 (p, &tty_drivers, tty_drivers) {
T_1 V_32 = F_27 ( V_22 -> V_33 , V_22 -> V_34 ) ;
if ( V_30 < V_32 || V_30 >= V_32 + V_22 -> V_35 )
continue;
* V_31 = V_30 - V_32 ;
return F_28 ( V_22 ) ;
}
return NULL ;
}
struct V_29 * F_29 ( char * V_16 , int * line )
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
V_37 = F_30 ( V_39 , & V_39 , 10 ) ;
F_31 ( & V_41 ) ;
F_26 (p, &tty_drivers, tty_drivers) {
if ( strncmp ( V_16 , V_22 -> V_16 , V_38 ) != 0 )
continue;
V_40 = V_39 ;
if ( * V_40 == ',' )
V_40 ++ ;
if ( * V_40 == '\0' )
V_40 = NULL ;
if ( V_37 >= 0 && V_37 < V_22 -> V_35 && V_22 -> V_42 &&
V_22 -> V_42 -> V_43 && ! V_22 -> V_42 -> V_43 ( V_22 , V_37 , V_40 ) ) {
V_36 = F_28 ( V_22 ) ;
* line = V_37 ;
break;
}
}
F_32 ( & V_41 ) ;
return V_36 ;
}
int F_33 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
int V_45 = 0 ;
if ( V_46 -> signal -> V_3 != V_3 )
return 0 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
if ( ! V_3 -> V_48 ) {
F_19 ( V_19 L_6 ) ;
goto V_49;
}
if ( F_35 ( V_46 ) == V_3 -> V_48 )
goto V_49;
F_36 ( & V_3 -> V_47 , V_44 ) ;
if ( F_37 ( V_50 ) )
goto V_51;
if ( F_38 () ) {
V_45 = - V_52 ;
goto V_51;
}
F_39 ( F_35 ( V_46 ) , V_50 , 1 ) ;
F_40 ( V_53 ) ;
V_45 = - V_54 ;
V_51:
return V_45 ;
V_49:
F_36 ( & V_3 -> V_47 , V_44 ) ;
return V_45 ;
}
static T_2 F_41 ( struct V_7 * V_7 , char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
return 0 ;
}
static T_2 F_42 ( struct V_7 * V_7 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
return - V_52 ;
}
static unsigned int F_43 ( struct V_7 * V_56 , T_6 * V_57 )
{
return V_58 | V_59 | V_60 | V_61 | V_62 | V_63 ;
}
static long F_44 ( struct V_7 * V_7 , unsigned int V_64 ,
unsigned long V_65 )
{
return V_64 == V_66 ? - V_67 : - V_52 ;
}
static long F_45 ( struct V_7 * V_7 ,
unsigned int V_64 , unsigned long V_65 )
{
return V_64 == V_66 ? - V_67 : - V_52 ;
}
void F_46 ( struct V_1 * V_3 )
{
struct V_68 * V_69 ;
if ( F_47 ( V_70 , & V_3 -> V_44 ) ) {
V_69 = F_48 ( V_3 ) ;
if ( V_69 ) {
if ( V_69 -> V_42 -> V_71 )
V_69 -> V_42 -> V_71 ( V_3 ) ;
F_49 ( V_69 ) ;
}
}
F_50 ( & V_3 -> V_72 , V_59 ) ;
}
static void F_51 ( struct V_1 * V_3 )
{
struct V_7 * V_73 = NULL ;
struct V_7 * V_56 , * V_74 = NULL ;
struct V_75 * V_22 ;
struct V_8 * V_10 ;
int V_76 = 0 , V_77 ;
unsigned long V_44 ;
int V_78 = 0 ;
if ( ! V_3 )
return;
F_10 ( & V_79 ) ;
if ( V_80 && F_6 ( V_80 ) == V_3 ) {
V_74 = V_80 ;
V_80 = NULL ;
}
F_12 ( & V_79 ) ;
F_52 ( V_3 ) ;
F_53 ( V_81 , & V_3 -> V_44 ) ;
F_22 ( V_3 , L_7 ) ;
F_10 ( & V_12 ) ;
F_26 (priv, &tty->tty_files, list) {
V_56 = V_10 -> V_7 ;
if ( V_56 -> V_82 -> V_83 == V_84 )
V_73 = V_56 ;
if ( V_56 -> V_82 -> V_83 != V_85 )
continue;
V_76 ++ ;
F_54 ( - 1 , V_56 , 0 ) ;
V_56 -> V_82 = & V_86 ;
}
F_12 ( & V_12 ) ;
F_55 ( V_3 ) ;
F_56 ( & V_87 ) ;
if ( V_3 -> V_88 ) {
F_57 (tty->session, PIDTYPE_SID, p) {
F_58 ( & V_22 -> V_89 -> V_90 ) ;
if ( V_22 -> signal -> V_3 == V_3 ) {
V_22 -> signal -> V_3 = NULL ;
V_78 ++ ;
}
if ( ! V_22 -> signal -> V_91 ) {
F_59 ( & V_22 -> V_89 -> V_90 ) ;
continue;
}
F_60 ( V_92 , V_93 , V_22 ) ;
F_60 ( V_94 , V_93 , V_22 ) ;
F_61 ( V_22 -> signal -> V_95 ) ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_48 )
V_22 -> signal -> V_95 = F_62 ( V_3 -> V_48 ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
F_59 ( & V_22 -> V_89 -> V_90 ) ;
} F_63 ( V_3 -> V_88 , V_96 , V_22 ) ;
}
F_64 ( & V_87 ) ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
F_65 ( V_97 , & V_3 -> V_44 ) ;
F_65 ( V_98 , & V_3 -> V_44 ) ;
F_65 ( V_70 , & V_3 -> V_44 ) ;
F_61 ( V_3 -> V_88 ) ;
F_61 ( V_3 -> V_48 ) ;
V_3 -> V_88 = NULL ;
V_3 -> V_48 = NULL ;
V_3 -> V_99 = 0 ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
while ( V_78 -- )
F_66 ( V_3 ) ;
if ( V_73 ) {
if ( V_3 -> V_42 -> V_100 )
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
V_3 -> V_42 -> V_100 ( V_3 , V_73 ) ;
} else if ( V_3 -> V_42 -> V_101 )
( V_3 -> V_42 -> V_101 ) ( V_3 ) ;
F_53 ( V_102 , & V_3 -> V_44 ) ;
F_65 ( V_81 , & V_3 -> V_44 ) ;
F_67 ( V_3 ) ;
F_68 ( V_3 ) ;
if ( V_74 )
F_69 ( V_74 ) ;
}
static void F_70 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_71 ( V_104 , struct V_1 , V_105 ) ;
F_51 ( V_3 ) ;
}
void F_72 ( struct V_1 * V_3 )
{
#ifdef F_73
char V_15 [ 64 ] ;
F_19 ( V_106 L_8 , F_16 ( V_3 , V_15 ) ) ;
#endif
F_74 ( & V_3 -> V_105 ) ;
}
void F_75 ( struct V_1 * V_3 )
{
#ifdef F_73
char V_15 [ 64 ] ;
F_19 ( V_106 L_9 , F_16 ( V_3 , V_15 ) ) ;
#endif
F_51 ( V_3 ) ;
}
void F_76 ( void )
{
struct V_1 * V_3 ;
V_3 = F_77 () ;
if ( V_3 ) {
F_75 ( V_3 ) ;
F_66 ( V_3 ) ;
}
}
int F_78 ( struct V_7 * V_56 )
{
return ( V_56 -> V_82 == & V_86 ) ;
}
static void F_79 ( struct V_107 * V_88 )
{
struct V_75 * V_22 ;
F_57 (session, PIDTYPE_SID, p) {
F_80 ( V_22 ) ;
} F_63 ( V_88 , V_96 , V_22 ) ;
}
void F_81 ( int V_108 )
{
struct V_1 * V_3 ;
if ( ! V_46 -> signal -> V_91 )
return;
V_3 = F_77 () ;
if ( V_3 ) {
struct V_107 * V_109 = F_62 ( V_3 -> V_48 ) ;
if ( V_108 ) {
if ( V_3 -> V_24 -> type != V_25 )
F_75 ( V_3 ) ;
}
F_66 ( V_3 ) ;
if ( V_109 ) {
F_39 ( V_109 , V_92 , V_108 ) ;
if ( ! V_108 )
F_39 ( V_109 , V_94 , V_108 ) ;
F_61 ( V_109 ) ;
}
} else if ( V_108 ) {
struct V_107 * V_110 ;
F_58 ( & V_46 -> V_89 -> V_90 ) ;
V_110 = V_46 -> signal -> V_95 ;
V_46 -> signal -> V_95 = NULL ;
F_59 ( & V_46 -> V_89 -> V_90 ) ;
if ( V_110 ) {
F_39 ( V_110 , V_92 , V_108 ) ;
F_39 ( V_110 , V_94 , V_108 ) ;
F_61 ( V_110 ) ;
}
return;
}
F_58 ( & V_46 -> V_89 -> V_90 ) ;
F_61 ( V_46 -> signal -> V_95 ) ;
V_46 -> signal -> V_95 = NULL ;
F_59 ( & V_46 -> V_89 -> V_90 ) ;
V_3 = F_77 () ;
if ( V_3 ) {
unsigned long V_44 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
F_61 ( V_3 -> V_88 ) ;
F_61 ( V_3 -> V_48 ) ;
V_3 -> V_88 = NULL ;
V_3 -> V_48 = NULL ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
F_66 ( V_3 ) ;
} else {
#ifdef F_73
F_19 ( V_106 L_10
L_11 , V_3 ) ;
#endif
}
F_56 ( & V_87 ) ;
F_79 ( F_82 ( V_46 ) ) ;
F_64 ( & V_87 ) ;
}
void F_83 ( void )
{
struct V_75 * V_111 = V_46 ;
F_81 ( 0 ) ;
F_80 ( V_111 ) ;
}
void F_84 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_112 ) {
F_36 ( & V_3 -> V_47 , V_44 ) ;
return;
}
V_3 -> V_112 = 1 ;
if ( V_3 -> V_28 && V_3 -> V_28 -> V_113 ) {
V_3 -> V_99 &= ~ V_114 ;
V_3 -> V_99 |= V_115 ;
F_50 ( & V_3 -> V_28 -> V_116 , V_58 ) ;
}
F_36 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_42 -> V_117 )
( V_3 -> V_42 -> V_117 ) ( V_3 ) ;
}
void F_85 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
if ( ! V_3 -> V_112 || V_3 -> V_118 ) {
F_36 ( & V_3 -> V_47 , V_44 ) ;
return;
}
V_3 -> V_112 = 0 ;
if ( V_3 -> V_28 && V_3 -> V_28 -> V_113 ) {
V_3 -> V_99 &= ~ V_115 ;
V_3 -> V_99 |= V_114 ;
F_50 ( & V_3 -> V_28 -> V_116 , V_58 ) ;
}
F_36 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_42 -> V_119 )
( V_3 -> V_42 -> V_119 ) ( V_3 ) ;
F_46 ( V_3 ) ;
}
static void F_86 ( struct V_120 * time )
{
unsigned long V_121 = F_87 () ;
V_121 -= V_121 % 60 ;
if ( ( long ) ( V_121 - time -> V_122 ) > 0 )
time -> V_122 = V_121 ;
}
static T_2 F_88 ( struct V_7 * V_7 , char T_3 * V_15 , T_4 V_23 ,
T_5 * V_55 )
{
int V_123 ;
struct V_17 * V_17 = F_89 ( V_7 ) ;
struct V_1 * V_3 = F_6 ( V_7 ) ;
struct V_68 * V_69 ;
if ( F_17 ( V_3 , V_17 , L_12 ) )
return - V_52 ;
if ( ! V_3 || ( F_47 ( V_124 , & V_3 -> V_44 ) ) )
return - V_52 ;
V_69 = F_90 ( V_3 ) ;
if ( V_69 -> V_42 -> V_125 )
V_123 = ( V_69 -> V_42 -> V_125 ) ( V_3 , V_7 , V_15 , V_23 ) ;
else
V_123 = - V_52 ;
F_49 ( V_69 ) ;
if ( V_123 > 0 )
F_86 ( & V_17 -> V_126 ) ;
return V_123 ;
}
void F_91 ( struct V_1 * V_3 )
__releases( &tty->atomic_write_lock
int F_92 ( struct V_1 * V_3 , int V_127 )
__acquires( &tty->atomic_write_lock
static inline T_2 F_93 (
T_2 (* V_83)( struct V_1 * , struct V_7 * , const unsigned char * , T_4 ) ,
struct V_1 * V_3 ,
struct V_7 * V_7 ,
const char T_3 * V_15 ,
T_4 V_23 )
{
T_2 V_45 , V_128 = 0 ;
unsigned int V_129 ;
V_45 = F_92 ( V_3 , V_7 -> V_130 & V_131 ) ;
if ( V_45 < 0 )
return V_45 ;
V_129 = 2048 ;
if ( F_47 ( V_132 , & V_3 -> V_44 ) )
V_129 = 65536 ;
if ( V_23 < V_129 )
V_129 = V_23 ;
if ( V_3 -> V_133 < V_129 ) {
unsigned char * V_134 ;
if ( V_129 < 1024 )
V_129 = 1024 ;
V_134 = F_8 ( V_129 , V_2 ) ;
if ( ! V_134 ) {
V_45 = - V_11 ;
goto V_51;
}
F_5 ( V_3 -> V_5 ) ;
V_3 -> V_133 = V_129 ;
V_3 -> V_5 = V_134 ;
}
for (; ; ) {
T_4 V_135 = V_23 ;
if ( V_135 > V_129 )
V_135 = V_129 ;
V_45 = - V_136 ;
if ( F_94 ( V_3 -> V_5 , V_15 , V_135 ) )
break;
V_45 = V_83 ( V_3 , V_7 , V_3 -> V_5 , V_135 ) ;
if ( V_45 <= 0 )
break;
V_128 += V_45 ;
V_15 += V_45 ;
V_23 -= V_45 ;
if ( ! V_23 )
break;
V_45 = - V_54 ;
if ( F_95 ( V_46 ) )
break;
F_96 () ;
}
if ( V_128 ) {
F_86 ( & F_89 ( V_7 ) -> V_137 ) ;
V_45 = V_128 ;
}
V_51:
F_91 ( V_3 ) ;
return V_45 ;
}
void F_97 ( struct V_1 * V_3 , char * V_138 )
{
if ( V_3 ) {
F_31 ( & V_3 -> V_139 ) ;
F_52 ( V_3 ) ;
if ( V_3 -> V_42 -> V_83 && ! F_47 ( V_140 , & V_3 -> V_44 ) ) {
F_68 ( V_3 ) ;
V_3 -> V_42 -> V_83 ( V_3 , V_138 , strlen ( V_138 ) ) ;
} else
F_68 ( V_3 ) ;
F_91 ( V_3 ) ;
}
return;
}
static T_2 V_85 ( struct V_7 * V_7 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_1 * V_3 = F_6 ( V_7 ) ;
struct V_68 * V_69 ;
T_2 V_45 ;
if ( F_17 ( V_3 , F_89 ( V_7 ) , L_13 ) )
return - V_52 ;
if ( ! V_3 || ! V_3 -> V_42 -> V_83 ||
( F_47 ( V_124 , & V_3 -> V_44 ) ) )
return - V_52 ;
if ( V_3 -> V_42 -> V_141 == NULL )
F_19 ( V_142 L_14 ,
V_3 -> V_24 -> V_16 ) ;
V_69 = F_90 ( V_3 ) ;
if ( ! V_69 -> V_42 -> V_83 )
V_45 = - V_52 ;
else
V_45 = F_93 ( V_69 -> V_42 -> V_83 , V_3 , V_7 , V_15 , V_23 ) ;
F_49 ( V_69 ) ;
return V_45 ;
}
T_2 V_84 ( struct V_7 * V_7 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_7 * V_22 = NULL ;
F_10 ( & V_79 ) ;
if ( V_80 )
V_22 = F_98 ( V_80 ) ;
F_12 ( & V_79 ) ;
if ( V_22 ) {
T_2 V_36 ;
V_36 = F_99 ( V_22 , V_15 , V_23 , & V_22 -> V_143 ) ;
F_69 ( V_22 ) ;
return V_36 ;
}
return V_85 ( V_7 , V_15 , V_23 , V_55 ) ;
}
static void F_100 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
int V_123 = V_31 + V_24 -> V_144 ;
sprintf ( V_22 , L_15 ,
V_24 -> V_26 == V_27 ? L_16 : V_24 -> V_16 ,
V_145 [ V_123 >> 4 & 0xf ] , V_123 & 0xf ) ;
}
static void F_101 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
if ( V_24 -> V_44 & V_146 )
strcpy ( V_22 , V_24 -> V_16 ) ;
else
sprintf ( V_22 , L_17 , V_24 -> V_16 , V_31 + V_24 -> V_144 ) ;
}
static struct V_1 * F_102 ( struct V_29 * V_24 ,
struct V_17 * V_17 , int V_147 )
{
if ( V_24 -> V_42 -> V_148 )
return V_24 -> V_42 -> V_148 ( V_24 , V_17 , V_147 ) ;
return V_24 -> V_149 [ V_147 ] ;
}
int F_103 ( struct V_1 * V_3 )
{
struct V_150 * V_151 ;
int V_147 = V_3 -> V_31 ;
if ( V_3 -> V_24 -> V_44 & V_152 )
V_3 -> V_153 = V_3 -> V_24 -> V_154 ;
else {
V_151 = V_3 -> V_24 -> V_153 [ V_147 ] ;
if ( V_151 != NULL )
V_3 -> V_153 = * V_151 ;
else
V_3 -> V_153 = V_3 -> V_24 -> V_154 ;
}
V_3 -> V_153 . V_155 = F_104 ( & V_3 -> V_153 ) ;
V_3 -> V_153 . V_156 = F_105 ( & V_3 -> V_153 ) ;
return 0 ;
}
int F_106 ( struct V_29 * V_24 , struct V_1 * V_3 )
{
int V_45 = F_103 ( V_3 ) ;
if ( V_45 )
return V_45 ;
F_28 ( V_24 ) ;
V_3 -> V_23 ++ ;
V_24 -> V_149 [ V_3 -> V_31 ] = V_3 ;
return 0 ;
}
static int F_107 ( struct V_29 * V_24 ,
struct V_1 * V_3 )
{
return V_24 -> V_42 -> V_157 ? V_24 -> V_42 -> V_157 ( V_24 , V_3 ) :
F_106 ( V_24 , V_3 ) ;
}
void F_108 ( struct V_29 * V_24 , struct V_1 * V_3 )
{
if ( V_24 -> V_42 -> remove )
V_24 -> V_42 -> remove ( V_24 , V_3 ) ;
else
V_24 -> V_149 [ V_3 -> V_31 ] = NULL ;
}
static int F_109 ( struct V_1 * V_3 )
{
struct V_29 * V_24 = V_3 -> V_24 ;
if ( F_47 ( V_140 , & V_3 -> V_44 ) ||
F_47 ( V_81 , & V_3 -> V_44 ) ||
F_47 ( V_158 , & V_3 -> V_44 ) )
return - V_52 ;
if ( V_24 -> type == V_25 &&
V_24 -> V_26 == V_159 ) {
if ( V_3 -> V_23 )
return - V_52 ;
V_3 -> V_28 -> V_23 ++ ;
}
V_3 -> V_23 ++ ;
F_31 ( & V_3 -> V_160 ) ;
F_110 ( ! F_47 ( V_161 , & V_3 -> V_44 ) ) ;
F_32 ( & V_3 -> V_160 ) ;
return 0 ;
}
struct V_1 * F_111 ( struct V_29 * V_24 , int V_147 )
{
struct V_1 * V_3 ;
int V_162 ;
if ( ! F_112 ( V_24 -> V_163 ) )
return F_113 ( - V_164 ) ;
V_3 = F_1 () ;
if ( ! V_3 ) {
V_162 = - V_11 ;
goto V_165;
}
F_114 ( V_3 , V_24 , V_147 ) ;
F_52 ( V_3 ) ;
V_162 = F_107 ( V_24 , V_3 ) ;
if ( V_162 < 0 )
goto V_166;
if ( ! V_3 -> V_167 )
V_3 -> V_167 = V_24 -> V_168 [ V_147 ] ;
F_115 ( ! V_3 -> V_167 ,
L_18 ,
V_169 , V_3 -> V_24 -> V_16 ) ;
V_3 -> V_167 -> V_170 = V_3 ;
V_162 = F_116 ( V_3 , V_3 -> V_28 ) ;
if ( V_162 )
goto V_171;
return V_3 ;
V_166:
F_68 ( V_3 ) ;
F_117 ( V_3 ) ;
F_3 ( V_3 ) ;
V_165:
F_118 ( V_24 -> V_163 ) ;
return F_113 ( V_162 ) ;
V_171:
F_68 ( V_3 ) ;
F_119 ( V_172 L_19
L_20 , V_147 ) ;
F_120 ( V_3 , V_147 ) ;
return F_113 ( V_162 ) ;
}
void F_121 ( struct V_1 * V_3 )
{
struct V_150 * V_151 ;
int V_147 = V_3 -> V_31 ;
if ( V_3 -> V_24 -> V_44 & V_152 )
return;
V_151 = V_3 -> V_24 -> V_153 [ V_147 ] ;
if ( V_151 == NULL ) {
V_151 = F_8 ( sizeof( struct V_150 ) , V_2 ) ;
if ( V_151 == NULL ) {
F_122 ( L_21 ) ;
return;
}
V_3 -> V_24 -> V_153 [ V_147 ] = V_151 ;
}
* V_151 = V_3 -> V_153 ;
}
static void F_123 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_71 ( V_104 , struct V_1 , V_105 ) ;
struct V_29 * V_24 = V_3 -> V_24 ;
if ( V_3 -> V_42 -> V_173 )
V_3 -> V_42 -> V_173 ( V_3 ) ;
V_3 -> V_6 = 0 ;
F_124 ( V_24 ) ;
F_118 ( V_24 -> V_163 ) ;
F_10 ( & V_12 ) ;
F_125 ( & V_3 -> V_14 ) ;
F_12 ( & V_12 ) ;
F_61 ( V_3 -> V_48 ) ;
F_61 ( V_3 -> V_88 ) ;
F_3 ( V_3 ) ;
}
static void F_126 ( struct V_174 * V_174 )
{
struct V_1 * V_3 = F_71 ( V_174 , struct V_1 , V_174 ) ;
F_127 ( & V_3 -> V_105 , F_123 ) ;
F_74 ( & V_3 -> V_105 ) ;
}
void F_66 ( struct V_1 * V_3 )
{
if ( V_3 )
F_128 ( & V_3 -> V_174 , F_126 ) ;
}
static void F_120 ( struct V_1 * V_3 , int V_147 )
{
F_110 ( V_3 -> V_31 != V_147 ) ;
F_110 ( ! F_129 ( & V_41 ) ) ;
if ( V_3 -> V_42 -> V_175 )
V_3 -> V_42 -> V_175 ( V_3 ) ;
F_121 ( V_3 ) ;
F_108 ( V_3 -> V_24 , V_3 ) ;
V_3 -> V_167 -> V_170 = NULL ;
if ( V_3 -> V_28 )
F_66 ( V_3 -> V_28 ) ;
F_66 ( V_3 ) ;
}
static int F_130 ( struct V_1 * V_3 , struct V_1 * V_176 ,
int V_147 )
{
#ifdef F_18
if ( V_147 < 0 || V_147 >= V_3 -> V_24 -> V_35 ) {
F_19 ( V_106 L_22 ,
V_169 , V_3 -> V_16 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_44 & V_177 )
return 0 ;
if ( V_3 != V_3 -> V_24 -> V_149 [ V_147 ] ) {
F_19 ( V_106 L_23 ,
V_169 , V_147 , V_3 -> V_16 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_178 ) {
if ( V_176 != V_3 -> V_24 -> V_178 -> V_149 [ V_147 ] ) {
F_19 ( V_106 L_24 ,
V_169 , V_147 , V_3 -> V_16 ) ;
return - 1 ;
}
if ( V_176 -> V_28 != V_3 ) {
F_19 ( V_106 L_25 , V_169 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_131 ( struct V_17 * V_17 , struct V_7 * V_56 )
{
struct V_1 * V_3 = F_6 ( V_56 ) ;
struct V_1 * V_176 ;
int V_179 , V_180 , V_181 , V_182 ;
int V_147 ;
char V_15 [ 64 ] ;
if ( F_17 ( V_3 , V_17 , V_169 ) )
return 0 ;
F_52 ( V_3 ) ;
F_22 ( V_3 , V_169 ) ;
F_54 ( - 1 , V_56 , 0 ) ;
V_147 = V_3 -> V_31 ;
V_179 = ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 ) ;
V_176 = V_3 -> V_28 ;
if ( F_130 ( V_3 , V_176 , V_147 ) ) {
F_68 ( V_3 ) ;
return 0 ;
}
#ifdef F_73
F_19 ( V_106 L_26 , V_169 ,
F_16 ( V_3 , V_15 ) , V_3 -> V_23 ) ;
#endif
if ( V_3 -> V_42 -> V_100 )
V_3 -> V_42 -> V_100 ( V_3 , V_56 ) ;
F_68 ( V_3 ) ;
while ( 1 ) {
F_31 ( & V_41 ) ;
F_132 ( V_3 , V_176 ) ;
V_180 = V_3 -> V_23 <= 1 ;
V_181 = V_176 &&
( V_176 -> V_23 <= ( V_179 ? 1 : 0 ) ) ;
V_182 = 0 ;
if ( V_180 ) {
if ( F_133 ( & V_3 -> V_116 ) ) {
F_134 ( & V_3 -> V_116 , V_58 ) ;
V_182 ++ ;
}
if ( F_133 ( & V_3 -> V_72 ) ) {
F_134 ( & V_3 -> V_72 , V_59 ) ;
V_182 ++ ;
}
}
if ( V_181 ) {
if ( F_133 ( & V_176 -> V_116 ) ) {
F_134 ( & V_176 -> V_116 , V_58 ) ;
V_182 ++ ;
}
if ( F_133 ( & V_176 -> V_72 ) ) {
F_134 ( & V_176 -> V_72 , V_59 ) ;
V_182 ++ ;
}
}
if ( ! V_182 )
break;
F_19 ( V_19 L_27 ,
V_169 , F_16 ( V_3 , V_15 ) ) ;
F_135 ( V_3 , V_176 ) ;
F_32 ( & V_41 ) ;
F_136 () ;
}
if ( V_179 ) {
if ( -- V_176 -> V_23 < 0 ) {
F_19 ( V_19 L_28 ,
V_169 , V_176 -> V_23 , F_16 ( V_176 , V_15 ) ) ;
V_176 -> V_23 = 0 ;
}
}
if ( -- V_3 -> V_23 < 0 ) {
F_19 ( V_19 L_29 ,
V_169 , V_3 -> V_23 , F_16 ( V_3 , V_15 ) ) ;
V_3 -> V_23 = 0 ;
}
F_14 ( V_56 ) ;
if ( V_180 )
F_53 ( V_140 , & V_3 -> V_44 ) ;
if ( V_181 )
F_53 ( V_140 , & V_176 -> V_44 ) ;
if ( V_180 || V_181 ) {
F_56 ( & V_87 ) ;
F_79 ( V_3 -> V_88 ) ;
if ( V_176 )
F_79 ( V_176 -> V_88 ) ;
F_64 ( & V_87 ) ;
}
F_32 ( & V_41 ) ;
F_135 ( V_3 , V_176 ) ;
if ( ! V_180 || ( V_176 && ! V_181 ) )
return 0 ;
#ifdef F_73
F_19 ( V_106 L_30 , V_169 ) ;
#endif
F_137 ( V_3 , V_176 ) ;
F_31 ( & V_41 ) ;
F_120 ( V_3 , V_147 ) ;
F_32 ( & V_41 ) ;
return 0 ;
}
static struct V_1 * F_138 ( T_1 V_30 , struct V_7 * V_56 )
{
struct V_1 * V_3 ;
if ( V_30 != F_27 ( V_183 , 0 ) )
return NULL ;
V_3 = F_77 () ;
if ( ! V_3 )
return F_113 ( - V_184 ) ;
V_56 -> V_130 |= V_185 ;
F_66 ( V_3 ) ;
return V_3 ;
}
static struct V_29 * F_139 ( T_1 V_30 , struct V_7 * V_56 ,
int * V_186 , int * V_31 )
{
struct V_29 * V_24 ;
switch ( V_30 ) {
#ifdef F_140
case F_27 ( V_187 , 0 ) : {
extern struct V_29 * V_188 ;
V_24 = F_28 ( V_188 ) ;
* V_31 = V_189 ;
* V_186 = 1 ;
break;
}
#endif
case F_27 ( V_183 , 1 ) : {
struct V_29 * V_188 = F_141 ( V_31 ) ;
if ( V_188 ) {
V_24 = F_28 ( V_188 ) ;
if ( V_24 ) {
V_56 -> V_130 |= V_185 ;
* V_186 = 1 ;
break;
}
}
return F_113 ( - V_164 ) ;
}
default:
V_24 = F_25 ( V_30 , V_31 ) ;
if ( ! V_24 )
return F_113 ( - V_164 ) ;
break;
}
return V_24 ;
}
static int F_142 ( struct V_17 * V_17 , struct V_7 * V_56 )
{
struct V_1 * V_3 ;
int V_186 , V_162 ;
struct V_29 * V_24 = NULL ;
int V_31 ;
T_1 V_30 = V_17 -> V_190 ;
unsigned V_191 = V_56 -> V_130 ;
F_143 ( V_17 , V_56 ) ;
V_192:
V_162 = F_7 ( V_56 ) ;
if ( V_162 )
return - V_11 ;
V_186 = V_56 -> V_130 & V_193 ;
V_31 = - 1 ;
V_162 = 0 ;
F_31 ( & V_41 ) ;
V_3 = F_138 ( V_30 , V_56 ) ;
if ( F_144 ( V_3 ) ) {
V_162 = F_145 ( V_3 ) ;
goto V_194;
} else if ( ! V_3 ) {
V_24 = F_139 ( V_30 , V_56 , & V_186 , & V_31 ) ;
if ( F_144 ( V_24 ) ) {
V_162 = F_145 ( V_24 ) ;
goto V_194;
}
V_3 = F_102 ( V_24 , V_17 , V_31 ) ;
if ( F_144 ( V_3 ) ) {
V_162 = F_145 ( V_3 ) ;
goto V_194;
}
}
if ( V_3 ) {
F_52 ( V_3 ) ;
V_162 = F_109 ( V_3 ) ;
if ( V_162 < 0 ) {
F_68 ( V_3 ) ;
V_3 = F_113 ( V_162 ) ;
}
} else
V_3 = F_111 ( V_24 , V_31 ) ;
F_32 ( & V_41 ) ;
if ( V_24 )
F_124 ( V_24 ) ;
if ( F_144 ( V_3 ) ) {
V_162 = F_145 ( V_3 ) ;
goto V_195;
}
F_9 ( V_3 , V_56 ) ;
F_22 ( V_3 , V_169 ) ;
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 )
V_186 = 1 ;
#ifdef F_73
F_19 ( V_106 L_31 , V_169 , V_3 -> V_16 ) ;
#endif
if ( V_3 -> V_42 -> V_196 )
V_162 = V_3 -> V_42 -> V_196 ( V_3 , V_56 ) ;
else
V_162 = - V_164 ;
V_56 -> V_130 = V_191 ;
if ( ! V_162 && F_47 ( V_197 , & V_3 -> V_44 ) &&
! F_146 ( V_198 ) )
V_162 = - V_199 ;
if ( V_162 ) {
#ifdef F_73
F_19 ( V_106 L_32 , V_169 ,
V_162 , V_3 -> V_16 ) ;
#endif
F_68 ( V_3 ) ;
F_131 ( V_17 , V_56 ) ;
if ( V_162 != - V_54 )
return V_162 ;
if ( F_95 ( V_46 ) )
return V_162 ;
F_136 () ;
if ( V_56 -> V_82 == & V_86 )
V_56 -> V_82 = & V_200 ;
goto V_192;
}
F_68 ( V_3 ) ;
F_31 ( & V_41 ) ;
F_52 ( V_3 ) ;
F_58 ( & V_46 -> V_89 -> V_90 ) ;
if ( ! V_186 &&
V_46 -> signal -> V_91 &&
! V_46 -> signal -> V_3 &&
V_3 -> V_88 == NULL )
F_147 ( V_46 , V_3 ) ;
F_59 ( & V_46 -> V_89 -> V_90 ) ;
F_68 ( V_3 ) ;
F_32 ( & V_41 ) ;
return 0 ;
V_194:
F_32 ( & V_41 ) ;
if ( ! F_148 ( V_24 ) )
F_124 ( V_24 ) ;
V_195:
F_13 ( V_56 ) ;
return V_162 ;
}
static unsigned int F_149 ( struct V_7 * V_56 , T_6 * V_57 )
{
struct V_1 * V_3 = F_6 ( V_56 ) ;
struct V_68 * V_69 ;
int V_45 = 0 ;
if ( F_17 ( V_3 , F_89 ( V_56 ) , L_33 ) )
return 0 ;
V_69 = F_90 ( V_3 ) ;
if ( V_69 -> V_42 -> V_201 )
V_45 = ( V_69 -> V_42 -> V_201 ) ( V_3 , V_56 , V_57 ) ;
F_49 ( V_69 ) ;
return V_45 ;
}
static int F_54 ( int V_202 , struct V_7 * V_56 , int V_203 )
{
struct V_1 * V_3 = F_6 ( V_56 ) ;
unsigned long V_44 ;
int V_162 = 0 ;
if ( F_17 ( V_3 , F_89 ( V_56 ) , L_34 ) )
goto V_51;
V_162 = F_150 ( V_202 , V_56 , V_203 , & V_3 -> V_204 ) ;
if ( V_162 <= 0 )
goto V_51;
if ( V_203 ) {
enum V_205 type ;
struct V_107 * V_107 ;
if ( ! F_133 ( & V_3 -> V_116 ) )
V_3 -> V_206 = 1 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_48 ) {
V_107 = V_3 -> V_48 ;
type = V_207 ;
} else {
V_107 = F_151 ( V_46 ) ;
type = V_208 ;
}
F_62 ( V_107 ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
V_162 = F_152 ( V_56 , V_107 , type , 0 ) ;
F_61 ( V_107 ) ;
if ( V_162 )
goto V_51;
} else {
if ( ! V_3 -> V_204 && ! F_133 ( & V_3 -> V_116 ) )
V_3 -> V_206 = V_209 ;
}
V_162 = 0 ;
V_51:
return V_162 ;
}
static int F_153 ( int V_202 , struct V_7 * V_56 , int V_203 )
{
struct V_1 * V_3 = F_6 ( V_56 ) ;
int V_162 ;
F_52 ( V_3 ) ;
V_162 = F_54 ( V_202 , V_56 , V_203 ) ;
F_68 ( V_3 ) ;
return V_162 ;
}
static int F_154 ( struct V_1 * V_3 , char T_3 * V_22 )
{
char V_210 , V_211 = 0 ;
struct V_68 * V_69 ;
if ( ( V_46 -> signal -> V_3 != V_3 ) && ! F_146 ( V_198 ) )
return - V_212 ;
if ( F_155 ( V_210 , V_22 ) )
return - V_136 ;
F_156 ( V_3 , V_210 ) ;
V_69 = F_90 ( V_3 ) ;
V_69 -> V_42 -> V_213 ( V_3 , & V_210 , & V_211 , 1 ) ;
F_49 ( V_69 ) ;
return 0 ;
}
static int F_157 ( struct V_1 * V_3 , struct V_214 T_3 * V_65 )
{
int V_215 ;
F_31 ( & V_3 -> V_216 ) ;
V_215 = F_158 ( V_65 , & V_3 -> V_214 , sizeof( * V_65 ) ) ;
F_32 ( & V_3 -> V_216 ) ;
return V_215 ? - V_136 : 0 ;
}
int F_159 ( struct V_1 * V_3 , struct V_214 * V_217 )
{
struct V_107 * V_48 ;
unsigned long V_44 ;
F_31 ( & V_3 -> V_216 ) ;
if ( ! memcmp ( V_217 , & V_3 -> V_214 , sizeof( * V_217 ) ) )
goto V_218;
F_34 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_62 ( V_3 -> V_48 ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
if ( V_48 )
F_39 ( V_48 , V_219 , 1 ) ;
F_61 ( V_48 ) ;
V_3 -> V_214 = * V_217 ;
V_218:
F_32 ( & V_3 -> V_216 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_3 , struct V_214 T_3 * V_65 )
{
struct V_214 V_220 ;
if ( F_94 ( & V_220 , V_65 , sizeof( * V_65 ) ) )
return - V_136 ;
if ( V_3 -> V_42 -> V_221 )
return V_3 -> V_42 -> V_221 ( V_3 , & V_220 ) ;
else
return F_159 ( V_3 , & V_220 ) ;
}
static int F_161 ( struct V_7 * V_7 )
{
if ( ! F_146 ( V_198 ) )
return - V_212 ;
if ( V_7 -> V_82 -> V_83 == V_84 ) {
struct V_7 * V_74 ;
F_10 ( & V_79 ) ;
V_74 = V_80 ;
V_80 = NULL ;
F_12 ( & V_79 ) ;
if ( V_74 )
F_69 ( V_74 ) ;
return 0 ;
}
F_10 ( & V_79 ) ;
if ( V_80 ) {
F_12 ( & V_79 ) ;
return - V_199 ;
}
V_80 = F_98 ( V_7 ) ;
F_12 ( & V_79 ) ;
return 0 ;
}
static int F_162 ( struct V_7 * V_7 , int T_3 * V_22 )
{
int V_222 ;
if ( F_155 ( V_222 , V_22 ) )
return - V_136 ;
F_10 ( & V_7 -> V_223 ) ;
if ( V_222 )
V_7 -> V_130 |= V_185 ;
else
V_7 -> V_130 &= ~ V_185 ;
F_12 ( & V_7 -> V_223 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_3 , int V_65 )
{
int V_45 = 0 ;
if ( V_46 -> signal -> V_91 && ( F_82 ( V_46 ) == V_3 -> V_88 ) )
return V_45 ;
F_31 ( & V_41 ) ;
if ( ! V_46 -> signal -> V_91 || V_46 -> signal -> V_3 ) {
V_45 = - V_212 ;
goto V_224;
}
if ( V_3 -> V_88 ) {
if ( V_65 == 1 && F_146 ( V_198 ) ) {
F_56 ( & V_87 ) ;
F_79 ( V_3 -> V_88 ) ;
F_64 ( & V_87 ) ;
} else {
V_45 = - V_212 ;
goto V_224;
}
}
F_164 ( V_46 , V_3 ) ;
V_224:
F_32 ( & V_41 ) ;
return V_45 ;
}
struct V_107 * F_165 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
struct V_107 * V_48 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_62 ( V_3 -> V_48 ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
return V_48 ;
}
static int F_166 ( struct V_1 * V_3 , struct V_1 * V_225 , T_7 T_3 * V_22 )
{
struct V_107 * V_107 ;
int V_45 ;
if ( V_3 == V_225 && V_46 -> signal -> V_3 != V_225 )
return - V_67 ;
V_107 = F_165 ( V_225 ) ;
V_45 = F_167 ( F_168 ( V_107 ) , V_22 ) ;
F_61 ( V_107 ) ;
return V_45 ;
}
static int F_169 ( struct V_1 * V_3 , struct V_1 * V_225 , T_7 T_3 * V_22 )
{
struct V_107 * V_48 ;
T_7 V_226 ;
int V_162 = F_33 ( V_225 ) ;
unsigned long V_44 ;
if ( V_162 == - V_52 )
return - V_67 ;
if ( V_162 )
return V_162 ;
if ( ! V_46 -> signal -> V_3 ||
( V_46 -> signal -> V_3 != V_225 ) ||
( V_225 -> V_88 != F_82 ( V_46 ) ) )
return - V_67 ;
if ( F_155 ( V_226 , V_22 ) )
return - V_136 ;
if ( V_226 < 0 )
return - V_227 ;
F_170 () ;
V_48 = F_171 ( V_226 ) ;
V_162 = - V_228 ;
if ( ! V_48 )
goto V_49;
V_162 = - V_212 ;
if ( F_172 ( V_48 ) != F_82 ( V_46 ) )
goto V_49;
V_162 = 0 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
F_61 ( V_225 -> V_48 ) ;
V_225 -> V_48 = F_62 ( V_48 ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
V_49:
F_173 () ;
return V_162 ;
}
static int F_174 ( struct V_1 * V_3 , struct V_1 * V_225 , T_7 T_3 * V_22 )
{
if ( V_3 == V_225 && V_46 -> signal -> V_3 != V_225 )
return - V_67 ;
if ( ! V_225 -> V_88 )
return - V_67 ;
return F_167 ( F_168 ( V_225 -> V_88 ) , V_22 ) ;
}
static int F_175 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_229 ;
int V_45 ;
if ( F_155 ( V_229 , V_22 ) )
return - V_136 ;
V_45 = F_176 ( V_3 , V_229 ) ;
return V_45 ;
}
static int F_177 ( struct V_1 * V_3 , unsigned int V_230 )
{
int V_162 ;
if ( V_3 -> V_42 -> V_231 == NULL )
return 0 ;
if ( V_3 -> V_24 -> V_44 & V_232 )
V_162 = V_3 -> V_42 -> V_231 ( V_3 , V_230 ) ;
else {
if ( F_92 ( V_3 , 0 ) < 0 )
return - V_233 ;
V_162 = V_3 -> V_42 -> V_231 ( V_3 , - 1 ) ;
if ( V_162 )
goto V_51;
if ( ! F_95 ( V_46 ) )
F_178 ( V_230 ) ;
V_162 = V_3 -> V_42 -> V_231 ( V_3 , 0 ) ;
V_51:
F_91 ( V_3 ) ;
if ( F_95 ( V_46 ) )
V_162 = - V_233 ;
}
return V_162 ;
}
static int F_179 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_162 = - V_227 ;
if ( V_3 -> V_42 -> V_234 ) {
V_162 = V_3 -> V_42 -> V_234 ( V_3 ) ;
if ( V_162 >= 0 )
V_162 = F_167 ( V_162 , V_22 ) ;
}
return V_162 ;
}
static int F_180 ( struct V_1 * V_3 , unsigned int V_64 ,
unsigned T_3 * V_22 )
{
int V_162 ;
unsigned int V_235 , V_236 , V_237 ;
if ( V_3 -> V_42 -> V_238 == NULL )
return - V_227 ;
V_162 = F_155 ( V_237 , V_22 ) ;
if ( V_162 )
return V_162 ;
V_235 = V_236 = 0 ;
switch ( V_64 ) {
case V_239 :
V_235 = V_237 ;
break;
case V_240 :
V_236 = V_237 ;
break;
case V_241 :
V_235 = V_237 ;
V_236 = ~ V_237 ;
break;
}
V_235 &= V_242 | V_243 | V_244 | V_245 | V_246 ;
V_236 &= V_242 | V_243 | V_244 | V_245 | V_246 ;
return V_3 -> V_42 -> V_238 ( V_3 , V_235 , V_236 ) ;
}
static int F_181 ( struct V_1 * V_3 , void T_3 * V_65 )
{
int V_162 = - V_227 ;
struct V_247 V_248 ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
if ( V_3 -> V_42 -> V_249 )
V_162 = V_3 -> V_42 -> V_249 ( V_3 , & V_248 ) ;
if ( V_162 != 0 )
return V_162 ;
if ( F_158 ( V_65 , & V_248 , sizeof( V_248 ) ) )
return - V_136 ;
return 0 ;
}
struct V_1 * F_182 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 )
V_3 = V_3 -> V_28 ;
return V_3 ;
}
struct V_1 * F_183 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 )
return V_3 ;
return V_3 -> V_28 ;
}
long F_184 ( struct V_7 * V_7 , unsigned int V_64 , unsigned long V_65 )
{
struct V_1 * V_3 = F_6 ( V_7 ) ;
struct V_1 * V_225 ;
void T_3 * V_22 = ( void T_3 * ) V_65 ;
int V_162 ;
struct V_68 * V_69 ;
if ( F_17 ( V_3 , F_89 ( V_7 ) , L_35 ) )
return - V_227 ;
V_225 = F_182 ( V_3 ) ;
switch ( V_64 ) {
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
V_162 = F_33 ( V_3 ) ;
if ( V_162 )
return V_162 ;
if ( V_64 != V_252 ) {
F_185 ( V_3 , 0 ) ;
if ( F_95 ( V_46 ) )
return - V_233 ;
}
break;
}
switch ( V_64 ) {
case V_255 :
return F_154 ( V_3 , V_22 ) ;
case V_256 :
return F_157 ( V_225 , V_22 ) ;
case V_257 :
return F_160 ( V_225 , V_22 ) ;
case V_258 :
return V_225 != V_3 ? - V_227 : F_161 ( V_7 ) ;
case V_259 :
return F_162 ( V_7 , V_22 ) ;
case V_260 :
F_53 ( V_197 , & V_3 -> V_44 ) ;
return 0 ;
case V_261 :
F_65 ( V_197 , & V_3 -> V_44 ) ;
return 0 ;
case V_262 :
{
int V_263 = F_47 ( V_197 , & V_3 -> V_44 ) ;
return F_167 ( V_263 , ( int T_3 * ) V_22 ) ;
}
case V_264 :
if ( V_46 -> signal -> V_3 != V_3 )
return - V_67 ;
F_83 () ;
return 0 ;
case V_265 :
return F_163 ( V_3 , V_65 ) ;
case V_266 :
return F_166 ( V_3 , V_225 , V_22 ) ;
case V_66 :
return F_169 ( V_3 , V_225 , V_22 ) ;
case V_267 :
return F_174 ( V_3 , V_225 , V_22 ) ;
case V_268 :
return F_167 ( V_3 -> V_229 -> V_42 -> V_35 , ( int T_3 * ) V_22 ) ;
case V_250 :
return F_175 ( V_3 , V_22 ) ;
case V_269 :
if ( ! F_146 ( V_198 ) )
return - V_212 ;
F_75 ( V_3 ) ;
return 0 ;
case V_270 :
{
unsigned int V_45 = F_186 ( F_187 ( V_225 ) ) ;
return F_167 ( V_45 , ( unsigned int T_3 * ) V_22 ) ;
}
case V_251 :
if ( V_3 -> V_42 -> V_231 )
return V_3 -> V_42 -> V_231 ( V_3 , - 1 ) ;
return 0 ;
case V_252 :
if ( V_3 -> V_42 -> V_231 )
return V_3 -> V_42 -> V_231 ( V_3 , 0 ) ;
return 0 ;
case V_253 :
if ( ! V_65 )
return F_177 ( V_3 , 250 ) ;
return 0 ;
case V_254 :
return F_177 ( V_3 , V_65 ? V_65 * 100 : 250 ) ;
case V_271 :
return F_179 ( V_3 , V_22 ) ;
case V_241 :
case V_240 :
case V_239 :
return F_180 ( V_3 , V_64 , V_22 ) ;
case V_272 :
V_162 = F_181 ( V_3 , V_22 ) ;
if ( V_162 != - V_227 )
return V_162 ;
break;
case V_273 :
switch ( V_65 ) {
case V_274 :
case V_275 :
F_188 ( V_3 ) ;
break;
}
break;
}
if ( V_3 -> V_42 -> V_276 ) {
V_162 = ( V_3 -> V_42 -> V_276 ) ( V_3 , V_64 , V_65 ) ;
if ( V_162 != - V_277 )
return V_162 ;
}
V_69 = F_90 ( V_3 ) ;
V_162 = - V_227 ;
if ( V_69 -> V_42 -> V_276 ) {
V_162 = V_69 -> V_42 -> V_276 ( V_3 , V_7 , V_64 , V_65 ) ;
if ( V_162 == - V_277 )
V_162 = - V_67 ;
}
F_49 ( V_69 ) ;
return V_162 ;
}
static long F_189 ( struct V_7 * V_7 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_1 * V_3 = F_6 ( V_7 ) ;
struct V_68 * V_69 ;
int V_162 = - V_277 ;
if ( F_17 ( V_3 , F_89 ( V_7 ) , L_35 ) )
return - V_227 ;
if ( V_3 -> V_42 -> V_278 ) {
V_162 = ( V_3 -> V_42 -> V_278 ) ( V_3 , V_64 , V_65 ) ;
if ( V_162 != - V_277 )
return V_162 ;
}
V_69 = F_90 ( V_3 ) ;
if ( V_69 -> V_42 -> V_278 )
V_162 = V_69 -> V_42 -> V_278 ( V_3 , V_7 , V_64 , V_65 ) ;
else
V_162 = F_190 ( V_3 , V_7 , V_64 , V_65 ) ;
F_49 ( V_69 ) ;
return V_162 ;
}
static int F_191 ( const void * V_279 , struct V_7 * V_7 , unsigned V_202 )
{
if ( F_192 ( V_7 -> V_82 -> V_125 != F_88 ) )
return 0 ;
return F_6 ( V_7 ) != V_279 ? 0 : V_202 + 1 ;
}
void F_193 ( struct V_1 * V_3 )
{
#ifdef F_194
F_72 ( V_3 ) ;
#else
struct V_75 * V_280 , * V_22 ;
struct V_107 * V_88 ;
int V_123 ;
if ( ! V_3 )
return;
V_88 = V_3 -> V_88 ;
F_195 ( V_3 ) ;
F_196 ( V_3 ) ;
F_56 ( & V_87 ) ;
F_57 (session, PIDTYPE_SID, p) {
F_19 ( V_281 L_36
L_37 ,
F_197 ( V_22 ) , V_22 -> V_282 ) ;
F_198 ( V_283 , V_22 , 1 ) ;
} F_63 ( V_88 , V_96 , V_22 ) ;
F_199 (g, p) {
if ( V_22 -> signal -> V_3 == V_3 ) {
F_19 ( V_281 L_36
L_37 ,
F_197 ( V_22 ) , V_22 -> V_282 ) ;
F_198 ( V_283 , V_22 , 1 ) ;
continue;
}
F_200 ( V_22 ) ;
V_123 = F_201 ( V_22 -> V_284 , 0 , F_191 , V_3 ) ;
if ( V_123 != 0 ) {
F_19 ( V_281 L_36
L_38 ,
F_197 ( V_22 ) , V_22 -> V_282 , V_123 - 1 ) ;
F_202 ( V_283 , V_22 ) ;
}
F_203 ( V_22 ) ;
} F_204 ( V_280 , V_22 ) ;
F_64 ( & V_87 ) ;
#endif
}
static void F_205 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_71 ( V_104 , struct V_1 , V_285 ) ;
F_193 ( V_3 ) ;
}
void F_206 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
F_74 ( & V_3 -> V_285 ) ;
}
static int F_207 ( struct V_30 * V_4 , const void * V_286 )
{
const T_1 * V_287 = V_286 ;
return V_4 -> V_287 == * V_287 ;
}
static struct V_30 * F_208 ( struct V_1 * V_3 )
{
T_1 V_287 = F_187 ( V_3 ) ;
return F_209 ( V_288 , NULL , & V_287 , F_207 ) ;
}
void F_114 ( struct V_1 * V_3 ,
struct V_29 * V_24 , int V_147 )
{
memset ( V_3 , 0 , sizeof( struct V_1 ) ) ;
F_210 ( & V_3 -> V_174 ) ;
V_3 -> V_6 = V_20 ;
F_211 ( V_3 ) ;
V_3 -> V_88 = NULL ;
V_3 -> V_48 = NULL ;
F_212 ( & V_3 -> V_289 ) ;
F_212 ( & V_3 -> V_216 ) ;
F_212 ( & V_3 -> V_160 ) ;
F_213 ( & V_3 -> V_72 ) ;
F_213 ( & V_3 -> V_116 ) ;
F_127 ( & V_3 -> V_105 , F_70 ) ;
F_212 ( & V_3 -> V_139 ) ;
F_214 ( & V_3 -> V_47 ) ;
F_215 ( & V_3 -> V_14 ) ;
F_127 ( & V_3 -> V_285 , F_205 ) ;
V_3 -> V_24 = V_24 ;
V_3 -> V_42 = V_24 -> V_42 ;
V_3 -> V_31 = V_147 ;
F_101 ( V_24 , V_147 , V_3 -> V_16 ) ;
V_3 -> V_4 = F_208 ( V_3 ) ;
}
void F_117 ( struct V_1 * V_3 )
{
F_216 ( V_3 ) ;
}
int F_217 ( struct V_1 * V_3 , unsigned char V_210 )
{
if ( V_3 -> V_42 -> V_290 )
return V_3 -> V_42 -> V_290 ( V_3 , V_210 ) ;
return V_3 -> V_42 -> V_83 ( V_3 , & V_210 , 1 ) ;
}
static int F_218 ( struct V_29 * V_24 , T_1 V_4 ,
unsigned int V_31 , unsigned int V_23 )
{
F_219 ( & V_24 -> V_291 [ V_31 ] , & V_200 ) ;
V_24 -> V_291 [ V_31 ] . V_163 = V_24 -> V_163 ;
return F_220 ( & V_24 -> V_291 [ V_31 ] , V_4 , V_23 ) ;
}
struct V_30 * F_221 ( struct V_29 * V_24 , unsigned V_31 ,
struct V_30 * V_30 )
{
return F_222 ( V_24 , V_31 , V_30 , NULL , NULL ) ;
}
static void F_223 ( struct V_30 * V_4 )
{
F_224 ( L_39 , F_225 ( V_4 ) , V_169 ) ;
F_5 ( V_4 ) ;
}
struct V_30 * F_222 ( struct V_29 * V_24 ,
unsigned V_31 , struct V_30 * V_30 ,
void * V_292 ,
const struct V_293 * * V_294 )
{
char V_16 [ 64 ] ;
T_1 V_287 = F_27 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ;
struct V_30 * V_4 = NULL ;
int V_162 = - V_164 ;
bool V_295 = false ;
if ( V_31 >= V_24 -> V_35 ) {
F_19 ( V_142 L_40
L_41 , V_31 ) ;
return F_113 ( - V_227 ) ;
}
if ( V_24 -> type == V_25 )
F_100 ( V_24 , V_31 , V_16 ) ;
else
F_101 ( V_24 , V_31 , V_16 ) ;
if ( ! ( V_24 -> V_44 & V_296 ) ) {
V_162 = F_218 ( V_24 , V_287 , V_31 , 1 ) ;
if ( V_162 )
goto error;
V_295 = true ;
}
V_4 = F_2 ( sizeof( * V_4 ) , V_2 ) ;
if ( ! V_4 ) {
V_162 = - V_11 ;
goto error;
}
V_4 -> V_287 = V_287 ;
V_4 -> V_297 = V_288 ;
V_4 -> V_298 = V_30 ;
V_4 -> V_299 = F_223 ;
F_226 ( V_4 , L_42 , V_16 ) ;
V_4 -> V_300 = V_294 ;
F_227 ( V_4 , V_292 ) ;
V_162 = F_228 ( V_4 ) ;
if ( V_162 )
goto error;
return V_4 ;
error:
F_4 ( V_4 ) ;
if ( V_295 )
F_229 ( & V_24 -> V_291 [ V_31 ] ) ;
return F_113 ( V_162 ) ;
}
void F_230 ( struct V_29 * V_24 , unsigned V_31 )
{
F_231 ( V_288 ,
F_27 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ) ;
if ( ! ( V_24 -> V_44 & V_296 ) )
F_229 ( & V_24 -> V_291 [ V_31 ] ) ;
}
struct V_29 * F_232 ( unsigned int V_301 , struct V_302 * V_163 ,
unsigned long V_44 )
{
struct V_29 * V_24 ;
unsigned int V_291 = 1 ;
int V_215 ;
if ( ! V_301 || ( V_44 & V_146 && V_301 > 1 ) )
return F_113 ( - V_227 ) ;
V_24 = F_2 ( sizeof( struct V_29 ) , V_2 ) ;
if ( ! V_24 )
return F_113 ( - V_11 ) ;
F_210 ( & V_24 -> V_174 ) ;
V_24 -> V_6 = V_303 ;
V_24 -> V_35 = V_301 ;
V_24 -> V_163 = V_163 ;
V_24 -> V_44 = V_44 ;
if ( ! ( V_44 & V_177 ) ) {
V_24 -> V_149 = F_233 ( V_301 , sizeof( * V_24 -> V_149 ) ,
V_2 ) ;
V_24 -> V_153 = F_233 ( V_301 , sizeof( * V_24 -> V_153 ) ,
V_2 ) ;
if ( ! V_24 -> V_149 || ! V_24 -> V_153 ) {
V_215 = - V_11 ;
goto V_304;
}
}
if ( ! ( V_44 & V_296 ) ) {
V_24 -> V_168 = F_233 ( V_301 , sizeof( * V_24 -> V_168 ) ,
V_2 ) ;
if ( ! V_24 -> V_168 ) {
V_215 = - V_11 ;
goto V_304;
}
V_291 = V_301 ;
}
V_24 -> V_291 = F_233 ( V_291 , sizeof( * V_24 -> V_291 ) , V_2 ) ;
if ( ! V_24 -> V_291 ) {
V_215 = - V_11 ;
goto V_304;
}
return V_24 ;
V_304:
F_5 ( V_24 -> V_168 ) ;
F_5 ( V_24 -> V_149 ) ;
F_5 ( V_24 -> V_153 ) ;
F_5 ( V_24 ) ;
return F_113 ( V_215 ) ;
}
static void F_234 ( struct V_174 * V_174 )
{
struct V_29 * V_24 = F_71 ( V_174 , struct V_29 , V_174 ) ;
int V_123 ;
struct V_150 * V_151 ;
if ( V_24 -> V_44 & V_305 ) {
for ( V_123 = 0 ; V_123 < V_24 -> V_35 ; V_123 ++ ) {
V_151 = V_24 -> V_153 [ V_123 ] ;
if ( V_151 ) {
V_24 -> V_153 [ V_123 ] = NULL ;
F_5 ( V_151 ) ;
}
if ( ! ( V_24 -> V_44 & V_306 ) )
F_230 ( V_24 , V_123 ) ;
}
F_235 ( V_24 ) ;
if ( V_24 -> V_44 & V_296 )
F_229 ( & V_24 -> V_291 [ 0 ] ) ;
}
F_5 ( V_24 -> V_291 ) ;
F_5 ( V_24 -> V_168 ) ;
F_5 ( V_24 -> V_153 ) ;
F_5 ( V_24 -> V_149 ) ;
F_5 ( V_24 ) ;
}
void F_124 ( struct V_29 * V_24 )
{
F_128 ( & V_24 -> V_174 , F_234 ) ;
}
void F_236 ( struct V_29 * V_24 ,
const struct V_307 * V_308 )
{
V_24 -> V_42 = V_308 ;
}
void F_237 ( struct V_29 * V_309 )
{
F_124 ( V_309 ) ;
}
int F_238 ( struct V_29 * V_24 )
{
int error ;
int V_123 ;
T_1 V_4 ;
struct V_30 * V_309 ;
if ( ! V_24 -> V_33 ) {
error = F_239 ( & V_4 , V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_16 ) ;
if ( ! error ) {
V_24 -> V_33 = F_240 ( V_4 ) ;
V_24 -> V_34 = F_241 ( V_4 ) ;
}
} else {
V_4 = F_27 ( V_24 -> V_33 , V_24 -> V_34 ) ;
error = F_242 ( V_4 , V_24 -> V_35 , V_24 -> V_16 ) ;
}
if ( error < 0 )
goto V_215;
if ( V_24 -> V_44 & V_296 ) {
error = F_218 ( V_24 , V_4 , 0 , V_24 -> V_35 ) ;
if ( error )
goto V_310;
}
F_31 ( & V_41 ) ;
F_11 ( & V_24 -> V_311 , & V_311 ) ;
F_32 ( & V_41 ) ;
if ( ! ( V_24 -> V_44 & V_306 ) ) {
for ( V_123 = 0 ; V_123 < V_24 -> V_35 ; V_123 ++ ) {
V_309 = F_221 ( V_24 , V_123 , NULL ) ;
if ( F_144 ( V_309 ) ) {
error = F_145 ( V_309 ) ;
goto V_312;
}
}
}
F_243 ( V_24 ) ;
V_24 -> V_44 |= V_305 ;
return 0 ;
V_312:
for ( V_123 -- ; V_123 >= 0 ; V_123 -- )
F_230 ( V_24 , V_123 ) ;
F_31 ( & V_41 ) ;
F_15 ( & V_24 -> V_311 ) ;
F_32 ( & V_41 ) ;
V_310:
F_244 ( V_4 , V_24 -> V_35 ) ;
V_215:
return error ;
}
int F_245 ( struct V_29 * V_24 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_244 ( F_27 ( V_24 -> V_33 , V_24 -> V_34 ) ,
V_24 -> V_35 ) ;
F_31 ( & V_41 ) ;
F_15 ( & V_24 -> V_311 ) ;
F_32 ( & V_41 ) ;
return 0 ;
}
T_1 F_187 ( struct V_1 * V_3 )
{
return F_27 ( V_3 -> V_24 -> V_33 , V_3 -> V_24 -> V_34 ) + V_3 -> V_31 ;
}
void F_80 ( struct V_75 * V_22 )
{
unsigned long V_44 ;
struct V_1 * V_3 ;
F_34 ( & V_22 -> V_89 -> V_90 , V_44 ) ;
V_3 = V_22 -> signal -> V_3 ;
V_22 -> signal -> V_3 = NULL ;
F_36 ( & V_22 -> V_89 -> V_90 , V_44 ) ;
F_66 ( V_3 ) ;
}
static void F_147 ( struct V_75 * V_111 , struct V_1 * V_3 )
{
if ( V_3 ) {
unsigned long V_44 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
F_61 ( V_3 -> V_88 ) ;
F_61 ( V_3 -> V_48 ) ;
V_3 -> V_48 = F_62 ( F_35 ( V_111 ) ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
V_3 -> V_88 = F_62 ( F_82 ( V_111 ) ) ;
if ( V_111 -> signal -> V_3 ) {
F_19 ( V_106 L_43 ) ;
F_66 ( V_111 -> signal -> V_3 ) ;
}
}
F_61 ( V_111 -> signal -> V_95 ) ;
V_111 -> signal -> V_3 = F_246 ( V_3 ) ;
V_111 -> signal -> V_95 = NULL ;
}
static void F_164 ( struct V_75 * V_111 , struct V_1 * V_3 )
{
F_58 ( & V_111 -> V_89 -> V_90 ) ;
F_147 ( V_111 , V_3 ) ;
F_59 ( & V_111 -> V_89 -> V_90 ) ;
}
struct V_1 * F_77 ( void )
{
struct V_1 * V_3 ;
unsigned long V_44 ;
F_34 ( & V_46 -> V_89 -> V_90 , V_44 ) ;
V_3 = F_246 ( V_46 -> signal -> V_3 ) ;
F_36 ( & V_46 -> V_89 -> V_90 , V_44 ) ;
return V_3 ;
}
void F_247 ( struct V_313 * V_314 )
{
* V_314 = V_200 ;
}
void T_8 F_248 ( void )
{
T_9 * V_315 ;
F_249 () ;
V_315 = V_316 ;
while ( V_315 < V_317 ) {
(* V_315)() ;
V_315 ++ ;
}
}
static char * F_250 ( struct V_30 * V_4 , T_10 * V_318 )
{
if ( ! V_318 )
return NULL ;
if ( V_4 -> V_287 == F_27 ( V_183 , 0 ) ||
V_4 -> V_287 == F_27 ( V_183 , 2 ) )
* V_318 = 0666 ;
return NULL ;
}
static int T_8 F_251 ( void )
{
V_288 = F_252 ( V_319 , L_16 ) ;
if ( F_144 ( V_288 ) )
return F_145 ( V_288 ) ;
V_288 -> V_320 = F_250 ;
return 0 ;
}
static T_2 F_253 ( struct V_30 * V_4 ,
struct V_321 * V_322 , char * V_15 )
{
struct V_323 * V_324 [ 16 ] ;
int V_123 = 0 ;
struct V_323 * V_325 ;
T_2 V_23 = 0 ;
F_254 () ;
F_255 (c) {
if ( ! V_325 -> V_30 )
continue;
if ( ! V_325 -> V_83 )
continue;
if ( ( V_325 -> V_44 & V_326 ) == 0 )
continue;
V_324 [ V_123 ++ ] = V_325 ;
if ( V_123 >= F_256 ( V_324 ) )
break;
}
while ( V_123 -- )
V_23 += sprintf ( V_15 + V_23 , L_44 ,
V_324 [ V_123 ] -> V_16 , V_324 [ V_123 ] -> V_31 , V_123 ? ' ' : '\n' ) ;
F_257 () ;
return V_23 ;
}
void F_258 ( void )
{
if ( V_327 )
F_259 ( & V_327 -> V_328 , NULL , L_45 ) ;
}
int T_8 F_260 ( void )
{
F_219 ( & V_329 , & V_200 ) ;
if ( F_220 ( & V_329 , F_27 ( V_183 , 0 ) , 1 ) ||
F_242 ( F_27 ( V_183 , 0 ) , 1 , L_46 ) < 0 )
F_261 ( L_47 ) ;
F_262 ( V_288 , NULL , F_27 ( V_183 , 0 ) , NULL , L_16 ) ;
F_219 ( & V_330 , & V_331 ) ;
if ( F_220 ( & V_330 , F_27 ( V_183 , 1 ) , 1 ) ||
F_242 ( F_27 ( V_183 , 1 ) , 1 , L_48 ) < 0 )
F_261 ( L_49 ) ;
V_327 = F_262 ( V_288 , NULL , F_27 ( V_183 , 1 ) , NULL ,
L_50 ) ;
if ( F_144 ( V_327 ) )
V_327 = NULL ;
else
F_110 ( F_263 ( V_327 , & V_332 ) < 0 ) ;
#ifdef F_140
F_264 ( & V_331 ) ;
#endif
return 0 ;
}
