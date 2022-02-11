void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
if ( V_2 -> V_3 )
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
void F_44 ( struct V_1 * V_2 )
{
struct V_68 * V_69 ;
if ( F_45 ( V_70 , & V_2 -> V_44 ) ) {
V_69 = F_46 ( V_2 ) ;
if ( V_69 ) {
if ( V_69 -> V_42 -> V_71 )
V_69 -> V_42 -> V_71 ( V_2 ) ;
F_47 ( V_69 ) ;
}
}
F_48 ( & V_2 -> V_72 , V_59 ) ;
}
static int F_49 ( struct V_1 * V_2 , int V_73 )
{
struct V_74 * V_22 ;
int V_75 = 0 ;
struct V_76 * V_77 = NULL ;
F_50 ( & V_78 ) ;
if ( V_2 -> V_79 ) {
F_51 (tty->session, PIDTYPE_SID, p) {
F_52 ( & V_22 -> V_80 -> V_81 ) ;
if ( V_22 -> signal -> V_2 == V_2 ) {
V_22 -> signal -> V_2 = NULL ;
V_75 ++ ;
}
if ( ! V_22 -> signal -> V_82 ) {
F_53 ( & V_22 -> V_80 -> V_81 ) ;
continue;
}
F_54 ( V_83 , V_84 , V_22 ) ;
F_54 ( V_85 , V_84 , V_22 ) ;
F_55 ( V_22 -> signal -> V_86 ) ;
F_8 ( & V_2 -> V_47 ) ;
V_77 = F_56 ( V_2 -> V_48 ) ;
if ( V_2 -> V_48 )
V_22 -> signal -> V_86 = F_56 ( V_2 -> V_48 ) ;
F_10 ( & V_2 -> V_47 ) ;
F_53 ( & V_22 -> V_80 -> V_81 ) ;
} F_57 ( V_2 -> V_79 , V_87 , V_22 ) ;
}
F_58 ( & V_78 ) ;
if ( V_77 ) {
if ( V_73 )
F_37 ( V_77 , V_83 , V_73 ) ;
F_55 ( V_77 ) ;
}
return V_75 ;
}
static void F_59 ( struct V_1 * V_2 , int V_73 )
{
struct V_6 * V_88 = NULL ;
struct V_6 * V_56 , * V_89 = NULL ;
struct V_7 * V_9 ;
int V_90 = 0 , V_91 ;
int V_75 ;
if ( ! V_2 )
return;
F_8 ( & V_92 ) ;
if ( V_93 && F_4 ( V_93 ) == V_2 ) {
V_89 = V_93 ;
V_93 = NULL ;
}
F_10 ( & V_92 ) ;
F_60 ( V_2 ) ;
if ( F_45 ( V_94 , & V_2 -> V_44 ) ) {
F_61 ( V_2 ) ;
return;
}
F_62 ( V_95 , & V_2 -> V_44 ) ;
F_20 ( V_2 , L_7 ) ;
F_8 ( & V_12 ) ;
F_24 (priv, &tty->tty_files, list) {
V_56 = V_9 -> V_6 ;
if ( V_56 -> V_96 -> V_97 == V_98 )
V_88 = V_56 ;
if ( V_56 -> V_96 -> V_97 != V_99 )
continue;
V_90 ++ ;
F_63 ( - 1 , V_56 , 0 ) ;
V_56 -> V_96 = & V_100 ;
}
F_10 ( & V_12 ) ;
V_75 = F_49 ( V_2 , V_73 ) ;
while ( V_75 -- )
F_64 ( V_2 ) ;
F_65 ( V_2 ) ;
F_52 ( & V_2 -> V_47 ) ;
F_66 ( V_101 , & V_2 -> V_44 ) ;
F_66 ( V_70 , & V_2 -> V_44 ) ;
F_55 ( V_2 -> V_79 ) ;
F_55 ( V_2 -> V_48 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_48 = NULL ;
V_2 -> V_102 = 0 ;
F_53 ( & V_2 -> V_47 ) ;
if ( V_88 ) {
if ( V_2 -> V_42 -> V_103 )
for ( V_91 = 0 ; V_91 < V_90 ; V_91 ++ )
V_2 -> V_42 -> V_103 ( V_2 , V_88 ) ;
} else if ( V_2 -> V_42 -> V_104 )
V_2 -> V_42 -> V_104 ( V_2 ) ;
F_62 ( V_94 , & V_2 -> V_44 ) ;
F_66 ( V_95 , & V_2 -> V_44 ) ;
F_61 ( V_2 ) ;
if ( V_89 )
F_67 ( V_89 ) ;
}
static void F_68 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_69 ( V_106 , struct V_1 , V_107 ) ;
F_59 ( V_2 , 0 ) ;
}
void F_70 ( struct V_1 * V_2 )
{
#ifdef F_71
char V_15 [ 64 ] ;
F_17 ( V_108 L_8 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_72 ( & V_2 -> V_107 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
#ifdef F_71
char V_15 [ 64 ] ;
F_17 ( V_108 L_9 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_59 ( V_2 , 0 ) ;
}
void F_74 ( void )
{
struct V_1 * V_2 ;
V_2 = F_75 () ;
if ( V_2 ) {
F_73 ( V_2 ) ;
F_64 ( V_2 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
#ifdef F_71
char V_15 [ 64 ] ;
F_17 ( V_108 L_10 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_59 ( V_2 , 1 ) ;
}
int F_77 ( struct V_6 * V_56 )
{
return ( V_56 -> V_96 == & V_100 ) ;
}
static void F_78 ( struct V_76 * V_79 )
{
struct V_74 * V_22 ;
F_51 (session, PIDTYPE_SID, p) {
F_79 ( V_22 ) ;
} F_57 ( V_79 , V_87 , V_22 ) ;
}
void F_80 ( int V_109 )
{
struct V_1 * V_2 ;
if ( ! V_46 -> signal -> V_82 )
return;
V_2 = F_75 () ;
if ( V_2 ) {
if ( V_109 && V_2 -> V_24 -> type != V_25 ) {
F_76 ( V_2 ) ;
} else {
struct V_76 * V_77 = F_81 ( V_2 ) ;
if ( V_77 ) {
F_37 ( V_77 , V_83 , V_109 ) ;
if ( ! V_109 )
F_37 ( V_77 , V_85 , V_109 ) ;
F_55 ( V_77 ) ;
}
}
F_64 ( V_2 ) ;
} else if ( V_109 ) {
struct V_76 * V_110 ;
F_52 ( & V_46 -> V_80 -> V_81 ) ;
V_110 = V_46 -> signal -> V_86 ;
V_46 -> signal -> V_86 = NULL ;
F_53 ( & V_46 -> V_80 -> V_81 ) ;
if ( V_110 ) {
F_37 ( V_110 , V_83 , V_109 ) ;
F_37 ( V_110 , V_85 , V_109 ) ;
F_55 ( V_110 ) ;
}
return;
}
F_52 ( & V_46 -> V_80 -> V_81 ) ;
F_55 ( V_46 -> signal -> V_86 ) ;
V_46 -> signal -> V_86 = NULL ;
V_2 = F_82 ( V_46 -> signal -> V_2 ) ;
if ( V_2 ) {
unsigned long V_44 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
F_55 ( V_2 -> V_79 ) ;
F_55 ( V_2 -> V_48 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_48 = NULL ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
F_64 ( V_2 ) ;
} else {
#ifdef F_71
F_17 ( V_108 L_11
L_12 , V_2 ) ;
#endif
}
F_53 ( & V_46 -> V_80 -> V_81 ) ;
F_50 ( & V_78 ) ;
F_78 ( F_83 ( V_46 ) ) ;
F_58 ( & V_78 ) ;
}
void F_84 ( void )
{
struct V_74 * V_111 = V_46 ;
F_80 ( 0 ) ;
F_79 ( V_111 ) ;
}
void F_85 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_112 ) {
F_34 ( & V_2 -> V_47 , V_44 ) ;
return;
}
V_2 -> V_112 = 1 ;
if ( V_2 -> V_28 && V_2 -> V_28 -> V_113 ) {
V_2 -> V_102 &= ~ V_114 ;
V_2 -> V_102 |= V_115 ;
F_48 ( & V_2 -> V_28 -> V_116 , V_58 ) ;
}
F_34 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_42 -> V_117 )
( V_2 -> V_42 -> V_117 ) ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
if ( ! V_2 -> V_112 || V_2 -> V_118 ) {
F_34 ( & V_2 -> V_47 , V_44 ) ;
return;
}
V_2 -> V_112 = 0 ;
if ( V_2 -> V_28 && V_2 -> V_28 -> V_113 ) {
V_2 -> V_102 &= ~ V_115 ;
V_2 -> V_102 |= V_114 ;
F_48 ( & V_2 -> V_28 -> V_116 , V_58 ) ;
}
F_34 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_42 -> V_119 )
( V_2 -> V_42 -> V_119 ) ( V_2 ) ;
F_44 ( V_2 ) ;
}
static void F_87 ( struct V_120 * time )
{
unsigned long V_121 = F_88 () & ~ 7 ;
if ( ( long ) ( V_121 - time -> V_122 ) > 0 )
time -> V_122 = V_121 ;
}
static T_2 F_89 ( struct V_6 * V_6 , char T_3 * V_15 , T_4 V_23 ,
T_5 * V_55 )
{
int V_123 ;
struct V_17 * V_17 = F_90 ( V_6 ) ;
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_68 * V_69 ;
if ( F_15 ( V_2 , V_17 , L_13 ) )
return - V_52 ;
if ( ! V_2 || ( F_45 ( V_124 , & V_2 -> V_44 ) ) )
return - V_52 ;
V_69 = F_91 ( V_2 ) ;
if ( V_69 -> V_42 -> V_125 )
V_123 = ( V_69 -> V_42 -> V_125 ) ( V_2 , V_6 , V_15 , V_23 ) ;
else
V_123 = - V_52 ;
F_47 ( V_69 ) ;
if ( V_123 > 0 )
F_87 ( & V_17 -> V_126 ) ;
return V_123 ;
}
void F_92 ( struct V_1 * V_2 )
__releases( &tty->atomic_write_lock
int F_93 ( struct V_1 * V_2 , int V_127 )
__acquires( &tty->atomic_write_lock
static inline T_2 F_94 (
T_2 (* V_97)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_2 ,
struct V_6 * V_6 ,
const char T_3 * V_15 ,
T_4 V_23 )
{
T_2 V_45 , V_128 = 0 ;
unsigned int V_129 ;
V_45 = F_93 ( V_2 , V_6 -> V_130 & V_131 ) ;
if ( V_45 < 0 )
return V_45 ;
V_129 = 2048 ;
if ( F_45 ( V_132 , & V_2 -> V_44 ) )
V_129 = 65536 ;
if ( V_23 < V_129 )
V_129 = V_23 ;
if ( V_2 -> V_133 < V_129 ) {
unsigned char * V_134 ;
if ( V_129 < 1024 )
V_129 = 1024 ;
V_134 = F_6 ( V_129 , V_10 ) ;
if ( ! V_134 ) {
V_45 = - V_11 ;
goto V_51;
}
F_3 ( V_2 -> V_4 ) ;
V_2 -> V_133 = V_129 ;
V_2 -> V_4 = V_134 ;
}
for (; ; ) {
T_4 V_135 = V_23 ;
if ( V_135 > V_129 )
V_135 = V_129 ;
V_45 = - V_136 ;
if ( F_95 ( V_2 -> V_4 , V_15 , V_135 ) )
break;
V_45 = V_97 ( V_2 , V_6 , V_2 -> V_4 , V_135 ) ;
if ( V_45 <= 0 )
break;
V_128 += V_45 ;
V_15 += V_45 ;
V_23 -= V_45 ;
if ( ! V_23 )
break;
V_45 = - V_54 ;
if ( F_96 ( V_46 ) )
break;
F_97 () ;
}
if ( V_128 ) {
F_87 ( & F_90 ( V_6 ) -> V_137 ) ;
V_45 = V_128 ;
}
V_51:
F_92 ( V_2 ) ;
return V_45 ;
}
void F_98 ( struct V_1 * V_2 , char * V_138 )
{
if ( V_2 ) {
F_29 ( & V_2 -> V_139 ) ;
F_60 ( V_2 ) ;
if ( V_2 -> V_42 -> V_97 && ! F_45 ( V_140 , & V_2 -> V_44 ) ) {
F_61 ( V_2 ) ;
V_2 -> V_42 -> V_97 ( V_2 , V_138 , strlen ( V_138 ) ) ;
} else
F_61 ( V_2 ) ;
F_92 ( V_2 ) ;
}
return;
}
static T_2 V_99 ( struct V_6 * V_6 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_68 * V_69 ;
T_2 V_45 ;
if ( F_15 ( V_2 , F_90 ( V_6 ) , L_14 ) )
return - V_52 ;
if ( ! V_2 || ! V_2 -> V_42 -> V_97 ||
( F_45 ( V_124 , & V_2 -> V_44 ) ) )
return - V_52 ;
if ( V_2 -> V_42 -> V_141 == NULL )
F_17 ( V_142 L_15 ,
V_2 -> V_24 -> V_16 ) ;
V_69 = F_91 ( V_2 ) ;
if ( ! V_69 -> V_42 -> V_97 )
V_45 = - V_52 ;
else
V_45 = F_94 ( V_69 -> V_42 -> V_97 , V_2 , V_6 , V_15 , V_23 ) ;
F_47 ( V_69 ) ;
return V_45 ;
}
T_2 V_98 ( struct V_6 * V_6 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_6 * V_22 = NULL ;
F_8 ( & V_92 ) ;
if ( V_93 )
V_22 = F_99 ( V_93 ) ;
F_10 ( & V_92 ) ;
if ( V_22 ) {
T_2 V_36 ;
V_36 = F_100 ( V_22 , V_15 , V_23 , & V_22 -> V_143 ) ;
F_67 ( V_22 ) ;
return V_36 ;
}
return V_99 ( V_6 , V_15 , V_23 , V_55 ) ;
}
static void F_101 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
int V_123 = V_31 + V_24 -> V_144 ;
sprintf ( V_22 , L_16 ,
V_24 -> V_26 == V_27 ? L_17 : V_24 -> V_16 ,
V_145 [ V_123 >> 4 & 0xf ] , V_123 & 0xf ) ;
}
static T_2 F_102 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
if ( V_24 -> V_44 & V_146 )
return sprintf ( V_22 , L_18 , V_24 -> V_16 ) ;
else
return sprintf ( V_22 , L_19 , V_24 -> V_16 ,
V_31 + V_24 -> V_144 ) ;
}
static struct V_1 * F_103 ( struct V_29 * V_24 ,
struct V_17 * V_17 , int V_147 )
{
if ( V_24 -> V_42 -> V_148 )
return V_24 -> V_42 -> V_148 ( V_24 , V_17 , V_147 ) ;
return V_24 -> V_149 [ V_147 ] ;
}
int F_104 ( struct V_1 * V_2 )
{
struct V_150 * V_151 ;
int V_147 = V_2 -> V_31 ;
if ( V_2 -> V_24 -> V_44 & V_152 )
V_2 -> V_153 = V_2 -> V_24 -> V_154 ;
else {
V_151 = V_2 -> V_24 -> V_153 [ V_147 ] ;
if ( V_151 != NULL )
V_2 -> V_153 = * V_151 ;
else
V_2 -> V_153 = V_2 -> V_24 -> V_154 ;
}
V_2 -> V_153 . V_155 = F_105 ( & V_2 -> V_153 ) ;
V_2 -> V_153 . V_156 = F_106 ( & V_2 -> V_153 ) ;
return 0 ;
}
int F_107 ( struct V_29 * V_24 , struct V_1 * V_2 )
{
int V_45 = F_104 ( V_2 ) ;
if ( V_45 )
return V_45 ;
F_26 ( V_24 ) ;
V_2 -> V_23 ++ ;
V_24 -> V_149 [ V_2 -> V_31 ] = V_2 ;
return 0 ;
}
static int F_108 ( struct V_29 * V_24 ,
struct V_1 * V_2 )
{
return V_24 -> V_42 -> V_157 ? V_24 -> V_42 -> V_157 ( V_24 , V_2 ) :
F_107 ( V_24 , V_2 ) ;
}
void F_109 ( struct V_29 * V_24 , struct V_1 * V_2 )
{
if ( V_24 -> V_42 -> remove )
V_24 -> V_42 -> remove ( V_24 , V_2 ) ;
else
V_24 -> V_149 [ V_2 -> V_31 ] = NULL ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_29 * V_24 = V_2 -> V_24 ;
if ( F_45 ( V_140 , & V_2 -> V_44 ) ||
F_45 ( V_95 , & V_2 -> V_44 ) )
return - V_52 ;
if ( V_24 -> type == V_25 &&
V_24 -> V_26 == V_158 ) {
if ( V_2 -> V_23 )
return - V_52 ;
V_2 -> V_28 -> V_23 ++ ;
}
V_2 -> V_23 ++ ;
F_111 ( ! V_2 -> V_159 ) ;
return 0 ;
}
struct V_1 * F_112 ( struct V_29 * V_24 , int V_147 )
{
struct V_1 * V_2 ;
int V_160 ;
if ( ! F_113 ( V_24 -> V_161 ) )
return F_114 ( - V_162 ) ;
V_2 = F_115 ( V_24 , V_147 ) ;
if ( ! V_2 ) {
V_160 = - V_11 ;
goto V_163;
}
F_60 ( V_2 ) ;
V_160 = F_108 ( V_24 , V_2 ) ;
if ( V_160 < 0 )
goto V_164;
if ( ! V_2 -> V_165 )
V_2 -> V_165 = V_24 -> V_166 [ V_147 ] ;
F_116 ( ! V_2 -> V_165 ,
L_20 ,
V_167 , V_2 -> V_24 -> V_16 ) ;
V_2 -> V_165 -> V_168 = V_2 ;
V_160 = F_117 ( V_2 , V_2 -> V_28 ) ;
if ( V_160 )
goto V_169;
return V_2 ;
V_164:
F_61 ( V_2 ) ;
F_118 ( V_2 ) ;
F_1 ( V_2 ) ;
V_163:
F_119 ( V_24 -> V_161 ) ;
return F_114 ( V_160 ) ;
V_169:
F_61 ( V_2 ) ;
F_120 ( V_170 L_21
L_22 , V_147 ) ;
F_121 ( V_2 , V_147 ) ;
return F_114 ( V_160 ) ;
}
void F_122 ( struct V_1 * V_2 )
{
struct V_150 * V_151 ;
int V_147 = V_2 -> V_31 ;
if ( V_2 -> V_24 -> V_44 & V_152 )
return;
V_151 = V_2 -> V_24 -> V_153 [ V_147 ] ;
if ( V_151 == NULL ) {
V_151 = F_6 ( sizeof( struct V_150 ) , V_10 ) ;
if ( V_151 == NULL ) {
F_123 ( L_23 ) ;
return;
}
V_2 -> V_24 -> V_153 [ V_147 ] = V_151 ;
}
* V_151 = V_2 -> V_153 ;
}
static void F_124 ( struct V_1 * V_2 )
{
F_125 ( & V_2 -> V_171 ) ;
F_125 ( & V_2 -> V_107 ) ;
}
static void F_126 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_69 ( V_106 , struct V_1 , V_107 ) ;
struct V_29 * V_24 = V_2 -> V_24 ;
if ( V_2 -> V_42 -> V_172 )
V_2 -> V_42 -> V_172 ( V_2 ) ;
V_2 -> V_5 = 0 ;
F_127 ( V_24 ) ;
F_119 ( V_24 -> V_161 ) ;
F_8 ( & V_12 ) ;
F_128 ( & V_2 -> V_14 ) ;
F_10 ( & V_12 ) ;
F_55 ( V_2 -> V_48 ) ;
F_55 ( V_2 -> V_79 ) ;
F_1 ( V_2 ) ;
}
static void F_129 ( struct V_173 * V_173 )
{
struct V_1 * V_2 = F_69 ( V_173 , struct V_1 , V_173 ) ;
F_130 ( & V_2 -> V_107 , F_126 ) ;
F_72 ( & V_2 -> V_107 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
if ( V_2 )
F_131 ( & V_2 -> V_173 , F_129 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_147 )
{
F_111 ( V_2 -> V_31 != V_147 ) ;
F_111 ( ! F_132 ( & V_41 ) ) ;
if ( V_2 -> V_42 -> V_174 )
V_2 -> V_42 -> V_174 ( V_2 ) ;
F_122 ( V_2 ) ;
F_109 ( V_2 -> V_24 , V_2 ) ;
V_2 -> V_165 -> V_168 = NULL ;
if ( V_2 -> V_28 )
V_2 -> V_28 -> V_165 -> V_168 = NULL ;
F_133 ( & V_2 -> V_165 -> V_15 . V_106 ) ;
if ( V_2 -> V_28 )
F_64 ( V_2 -> V_28 ) ;
F_64 ( V_2 ) ;
}
static int F_134 ( struct V_1 * V_2 , struct V_1 * V_175 ,
int V_147 )
{
#ifdef F_16
if ( V_147 < 0 || V_147 >= V_2 -> V_24 -> V_35 ) {
F_17 ( V_108 L_24 ,
V_167 , V_2 -> V_16 ) ;
return - 1 ;
}
if ( V_2 -> V_24 -> V_44 & V_176 )
return 0 ;
if ( V_2 != V_2 -> V_24 -> V_149 [ V_147 ] ) {
F_17 ( V_108 L_25 ,
V_167 , V_147 , V_2 -> V_16 ) ;
return - 1 ;
}
if ( V_2 -> V_24 -> V_177 ) {
if ( V_175 != V_2 -> V_24 -> V_177 -> V_149 [ V_147 ] ) {
F_17 ( V_108 L_26 ,
V_167 , V_147 , V_2 -> V_16 ) ;
return - 1 ;
}
if ( V_175 -> V_28 != V_2 ) {
F_17 ( V_108 L_27 , V_167 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_135 ( struct V_17 * V_17 , struct V_6 * V_56 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
struct V_1 * V_175 ;
int V_178 , V_179 , V_180 , V_181 ;
int V_147 ;
char V_15 [ 64 ] ;
if ( F_15 ( V_2 , V_17 , V_167 ) )
return 0 ;
F_60 ( V_2 ) ;
F_20 ( V_2 , V_167 ) ;
F_63 ( - 1 , V_56 , 0 ) ;
V_147 = V_2 -> V_31 ;
V_178 = ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_158 ) ;
V_175 = V_2 -> V_28 ;
if ( F_134 ( V_2 , V_175 , V_147 ) ) {
F_61 ( V_2 ) ;
return 0 ;
}
#ifdef F_71
F_17 ( V_108 L_28 , V_167 ,
F_14 ( V_2 , V_15 ) , V_2 -> V_23 ) ;
#endif
if ( V_2 -> V_42 -> V_103 )
V_2 -> V_42 -> V_103 ( V_2 , V_56 ) ;
F_61 ( V_2 ) ;
while ( 1 ) {
F_29 ( & V_41 ) ;
F_136 ( V_2 , V_175 ) ;
V_179 = V_2 -> V_23 <= 1 ;
V_180 = V_175 &&
( V_175 -> V_23 <= ( V_178 ? 1 : 0 ) ) ;
V_181 = 0 ;
if ( V_179 ) {
if ( F_137 ( & V_2 -> V_116 ) ) {
F_138 ( & V_2 -> V_116 , V_58 ) ;
V_181 ++ ;
}
if ( F_137 ( & V_2 -> V_72 ) ) {
F_138 ( & V_2 -> V_72 , V_59 ) ;
V_181 ++ ;
}
}
if ( V_180 ) {
if ( F_137 ( & V_175 -> V_116 ) ) {
F_138 ( & V_175 -> V_116 , V_58 ) ;
V_181 ++ ;
}
if ( F_137 ( & V_175 -> V_72 ) ) {
F_138 ( & V_175 -> V_72 , V_59 ) ;
V_181 ++ ;
}
}
if ( ! V_181 )
break;
F_17 ( V_19 L_29 ,
V_167 , F_14 ( V_2 , V_15 ) ) ;
F_139 ( V_2 , V_175 ) ;
F_30 ( & V_41 ) ;
F_140 () ;
}
if ( V_178 ) {
if ( -- V_175 -> V_23 < 0 ) {
F_17 ( V_19 L_30 ,
V_167 , V_175 -> V_23 , F_14 ( V_175 , V_15 ) ) ;
V_175 -> V_23 = 0 ;
}
}
if ( -- V_2 -> V_23 < 0 ) {
F_17 ( V_19 L_31 ,
V_167 , V_2 -> V_23 , F_14 ( V_2 , V_15 ) ) ;
V_2 -> V_23 = 0 ;
}
F_12 ( V_56 ) ;
if ( V_179 )
F_62 ( V_140 , & V_2 -> V_44 ) ;
if ( V_180 )
F_62 ( V_140 , & V_175 -> V_44 ) ;
if ( V_179 || V_180 ) {
F_50 ( & V_78 ) ;
F_78 ( V_2 -> V_79 ) ;
if ( V_175 )
F_78 ( V_175 -> V_79 ) ;
F_58 ( & V_78 ) ;
}
F_30 ( & V_41 ) ;
F_139 ( V_2 , V_175 ) ;
if ( ! V_179 || ( V_175 && ! V_180 ) )
return 0 ;
#ifdef F_71
F_17 ( V_108 L_32 , V_167 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_141 ( V_2 , V_175 ) ;
F_124 ( V_2 ) ;
if ( V_175 )
F_124 ( V_175 ) ;
#ifdef F_71
F_17 ( V_108 L_33 , V_167 , F_14 ( V_2 , V_15 ) ) ;
#endif
F_29 ( & V_41 ) ;
F_121 ( V_2 , V_147 ) ;
F_30 ( & V_41 ) ;
return 0 ;
}
static struct V_1 * F_142 ( T_1 V_30 , struct V_6 * V_56 )
{
struct V_1 * V_2 ;
if ( V_30 != F_25 ( V_182 , 0 ) )
return NULL ;
V_2 = F_75 () ;
if ( ! V_2 )
return F_114 ( - V_183 ) ;
V_56 -> V_130 |= V_184 ;
F_64 ( V_2 ) ;
return V_2 ;
}
static struct V_29 * F_143 ( T_1 V_30 , struct V_6 * V_56 ,
int * V_185 , int * V_31 )
{
struct V_29 * V_24 ;
switch ( V_30 ) {
#ifdef F_144
case F_25 ( V_186 , 0 ) : {
extern struct V_29 * V_187 ;
V_24 = F_26 ( V_187 ) ;
* V_31 = V_188 ;
* V_185 = 1 ;
break;
}
#endif
case F_25 ( V_182 , 1 ) : {
struct V_29 * V_187 = F_145 ( V_31 ) ;
if ( V_187 ) {
V_24 = F_26 ( V_187 ) ;
if ( V_24 ) {
V_56 -> V_130 |= V_184 ;
* V_185 = 1 ;
break;
}
}
return F_114 ( - V_162 ) ;
}
default:
V_24 = F_23 ( V_30 , V_31 ) ;
if ( ! V_24 )
return F_114 ( - V_162 ) ;
break;
}
return V_24 ;
}
static int F_146 ( struct V_17 * V_17 , struct V_6 * V_56 )
{
struct V_1 * V_2 ;
int V_185 , V_160 ;
struct V_29 * V_24 = NULL ;
int V_31 ;
T_1 V_30 = V_17 -> V_189 ;
unsigned V_190 = V_56 -> V_130 ;
F_147 ( V_17 , V_56 ) ;
V_191:
V_160 = F_5 ( V_56 ) ;
if ( V_160 )
return - V_11 ;
V_185 = V_56 -> V_130 & V_192 ;
V_31 = - 1 ;
V_160 = 0 ;
F_29 ( & V_41 ) ;
V_2 = F_142 ( V_30 , V_56 ) ;
if ( F_148 ( V_2 ) ) {
V_160 = F_149 ( V_2 ) ;
goto V_193;
} else if ( ! V_2 ) {
V_24 = F_143 ( V_30 , V_56 , & V_185 , & V_31 ) ;
if ( F_148 ( V_24 ) ) {
V_160 = F_149 ( V_24 ) ;
goto V_193;
}
V_2 = F_103 ( V_24 , V_17 , V_31 ) ;
if ( F_148 ( V_2 ) ) {
V_160 = F_149 ( V_2 ) ;
goto V_193;
}
}
if ( V_2 ) {
F_60 ( V_2 ) ;
V_160 = F_110 ( V_2 ) ;
if ( V_160 < 0 ) {
F_61 ( V_2 ) ;
V_2 = F_114 ( V_160 ) ;
}
} else
V_2 = F_112 ( V_24 , V_31 ) ;
F_30 ( & V_41 ) ;
if ( V_24 )
F_127 ( V_24 ) ;
if ( F_148 ( V_2 ) ) {
V_160 = F_149 ( V_2 ) ;
goto V_194;
}
F_7 ( V_2 , V_56 ) ;
F_20 ( V_2 , V_167 ) ;
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_158 )
V_185 = 1 ;
#ifdef F_71
F_17 ( V_108 L_34 , V_167 , V_2 -> V_16 ) ;
#endif
if ( V_2 -> V_42 -> V_195 )
V_160 = V_2 -> V_42 -> V_195 ( V_2 , V_56 ) ;
else
V_160 = - V_162 ;
V_56 -> V_130 = V_190 ;
if ( ! V_160 && F_45 ( V_196 , & V_2 -> V_44 ) &&
! F_150 ( V_197 ) )
V_160 = - V_198 ;
if ( V_160 ) {
#ifdef F_71
F_17 ( V_108 L_35 , V_167 ,
V_160 , V_2 -> V_16 ) ;
#endif
F_61 ( V_2 ) ;
F_135 ( V_17 , V_56 ) ;
if ( V_160 != - V_54 )
return V_160 ;
if ( F_96 ( V_46 ) )
return V_160 ;
F_140 () ;
if ( V_56 -> V_96 == & V_100 )
V_56 -> V_96 = & V_199 ;
goto V_191;
}
F_66 ( V_94 , & V_2 -> V_44 ) ;
F_61 ( V_2 ) ;
F_29 ( & V_41 ) ;
F_60 ( V_2 ) ;
F_52 ( & V_46 -> V_80 -> V_81 ) ;
if ( ! V_185 &&
V_46 -> signal -> V_82 &&
! V_46 -> signal -> V_2 &&
V_2 -> V_79 == NULL )
F_151 ( V_46 , V_2 ) ;
F_53 ( & V_46 -> V_80 -> V_81 ) ;
F_61 ( V_2 ) ;
F_30 ( & V_41 ) ;
return 0 ;
V_193:
F_30 ( & V_41 ) ;
if ( ! F_152 ( V_24 ) )
F_127 ( V_24 ) ;
V_194:
F_11 ( V_56 ) ;
return V_160 ;
}
static unsigned int F_153 ( struct V_6 * V_56 , T_6 * V_57 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
struct V_68 * V_69 ;
int V_45 = 0 ;
if ( F_15 ( V_2 , F_90 ( V_56 ) , L_36 ) )
return 0 ;
V_69 = F_91 ( V_2 ) ;
if ( V_69 -> V_42 -> V_200 )
V_45 = ( V_69 -> V_42 -> V_200 ) ( V_2 , V_56 , V_57 ) ;
F_47 ( V_69 ) ;
return V_45 ;
}
static int F_63 ( int V_201 , struct V_6 * V_56 , int V_202 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
struct V_68 * V_159 ;
unsigned long V_44 ;
int V_160 = 0 ;
if ( F_15 ( V_2 , F_90 ( V_56 ) , L_37 ) )
goto V_51;
V_160 = F_154 ( V_201 , V_56 , V_202 , & V_2 -> V_203 ) ;
if ( V_160 <= 0 )
goto V_51;
V_159 = F_46 ( V_2 ) ;
if ( V_159 ) {
if ( V_159 -> V_42 -> V_203 )
V_159 -> V_42 -> V_203 ( V_2 , V_202 ) ;
F_47 ( V_159 ) ;
}
if ( V_202 ) {
enum V_204 type ;
struct V_76 * V_76 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
if ( V_2 -> V_48 ) {
V_76 = V_2 -> V_48 ;
type = V_205 ;
} else {
V_76 = F_155 ( V_46 ) ;
type = V_206 ;
}
F_56 ( V_76 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
V_160 = F_156 ( V_56 , V_76 , type , 0 ) ;
F_55 ( V_76 ) ;
}
V_51:
return V_160 ;
}
static int F_157 ( int V_201 , struct V_6 * V_56 , int V_202 )
{
struct V_1 * V_2 = F_4 ( V_56 ) ;
int V_160 ;
F_60 ( V_2 ) ;
V_160 = F_63 ( V_201 , V_56 , V_202 ) ;
F_61 ( V_2 ) ;
return V_160 ;
}
static int F_158 ( struct V_1 * V_2 , char T_3 * V_22 )
{
char V_207 , V_208 = 0 ;
struct V_68 * V_69 ;
if ( ( V_46 -> signal -> V_2 != V_2 ) && ! F_150 ( V_197 ) )
return - V_209 ;
if ( F_159 ( V_207 , V_22 ) )
return - V_136 ;
F_160 ( V_2 , V_207 ) ;
V_69 = F_91 ( V_2 ) ;
V_69 -> V_42 -> V_210 ( V_2 , & V_207 , & V_208 , 1 ) ;
F_47 ( V_69 ) ;
return 0 ;
}
static int F_161 ( struct V_1 * V_2 , struct V_211 T_3 * V_65 )
{
int V_212 ;
F_29 ( & V_2 -> V_213 ) ;
V_212 = F_162 ( V_65 , & V_2 -> V_211 , sizeof( * V_65 ) ) ;
F_30 ( & V_2 -> V_213 ) ;
return V_212 ? - V_136 : 0 ;
}
int F_163 ( struct V_1 * V_2 , struct V_211 * V_214 )
{
struct V_76 * V_48 ;
unsigned long V_44 ;
F_29 ( & V_2 -> V_213 ) ;
if ( ! memcmp ( V_214 , & V_2 -> V_211 , sizeof( * V_214 ) ) )
goto V_215;
F_32 ( & V_2 -> V_47 , V_44 ) ;
V_48 = F_56 ( V_2 -> V_48 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
if ( V_48 )
F_37 ( V_48 , V_216 , 1 ) ;
F_55 ( V_48 ) ;
V_2 -> V_211 = * V_214 ;
V_215:
F_30 ( & V_2 -> V_213 ) ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 , struct V_211 T_3 * V_65 )
{
struct V_211 V_217 ;
if ( F_95 ( & V_217 , V_65 , sizeof( * V_65 ) ) )
return - V_136 ;
if ( V_2 -> V_42 -> V_218 )
return V_2 -> V_42 -> V_218 ( V_2 , & V_217 ) ;
else
return F_163 ( V_2 , & V_217 ) ;
}
static int F_165 ( struct V_6 * V_6 )
{
if ( ! F_150 ( V_197 ) )
return - V_209 ;
if ( V_6 -> V_96 -> V_97 == V_98 ) {
struct V_6 * V_89 ;
F_8 ( & V_92 ) ;
V_89 = V_93 ;
V_93 = NULL ;
F_10 ( & V_92 ) ;
if ( V_89 )
F_67 ( V_89 ) ;
return 0 ;
}
F_8 ( & V_92 ) ;
if ( V_93 ) {
F_10 ( & V_92 ) ;
return - V_198 ;
}
V_93 = F_99 ( V_6 ) ;
F_10 ( & V_92 ) ;
return 0 ;
}
static int F_166 ( struct V_6 * V_6 , int T_3 * V_22 )
{
int V_219 ;
if ( F_159 ( V_219 , V_22 ) )
return - V_136 ;
F_8 ( & V_6 -> V_220 ) ;
if ( V_219 )
V_6 -> V_130 |= V_184 ;
else
V_6 -> V_130 &= ~ V_184 ;
F_10 ( & V_6 -> V_220 ) ;
return 0 ;
}
static int F_167 ( struct V_1 * V_2 , int V_65 )
{
int V_45 = 0 ;
if ( V_46 -> signal -> V_82 && ( F_83 ( V_46 ) == V_2 -> V_79 ) )
return V_45 ;
F_29 ( & V_41 ) ;
if ( ! V_46 -> signal -> V_82 || V_46 -> signal -> V_2 ) {
V_45 = - V_209 ;
goto V_221;
}
if ( V_2 -> V_79 ) {
if ( V_65 == 1 && F_150 ( V_197 ) ) {
F_50 ( & V_78 ) ;
F_78 ( V_2 -> V_79 ) ;
F_58 ( & V_78 ) ;
} else {
V_45 = - V_209 ;
goto V_221;
}
}
F_168 ( V_46 , V_2 ) ;
V_221:
F_30 ( & V_41 ) ;
return V_45 ;
}
struct V_76 * F_81 ( struct V_1 * V_2 )
{
unsigned long V_44 ;
struct V_76 * V_48 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
V_48 = F_56 ( V_2 -> V_48 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
return V_48 ;
}
static int F_169 ( struct V_1 * V_2 , struct V_1 * V_222 , T_7 T_3 * V_22 )
{
struct V_76 * V_76 ;
int V_45 ;
if ( V_2 == V_222 && V_46 -> signal -> V_2 != V_222 )
return - V_67 ;
V_76 = F_81 ( V_222 ) ;
V_45 = F_170 ( F_171 ( V_76 ) , V_22 ) ;
F_55 ( V_76 ) ;
return V_45 ;
}
static int F_172 ( struct V_1 * V_2 , struct V_1 * V_222 , T_7 T_3 * V_22 )
{
struct V_76 * V_48 ;
T_7 V_223 ;
int V_160 = F_31 ( V_222 ) ;
unsigned long V_44 ;
if ( V_160 == - V_52 )
return - V_67 ;
if ( V_160 )
return V_160 ;
if ( ! V_46 -> signal -> V_2 ||
( V_46 -> signal -> V_2 != V_222 ) ||
( V_222 -> V_79 != F_83 ( V_46 ) ) )
return - V_67 ;
if ( F_159 ( V_223 , V_22 ) )
return - V_136 ;
if ( V_223 < 0 )
return - V_224 ;
F_173 () ;
V_48 = F_174 ( V_223 ) ;
V_160 = - V_225 ;
if ( ! V_48 )
goto V_49;
V_160 = - V_209 ;
if ( F_175 ( V_48 ) != F_83 ( V_46 ) )
goto V_49;
V_160 = 0 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
F_55 ( V_222 -> V_48 ) ;
V_222 -> V_48 = F_56 ( V_48 ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
V_49:
F_176 () ;
return V_160 ;
}
static int F_177 ( struct V_1 * V_2 , struct V_1 * V_222 , T_7 T_3 * V_22 )
{
if ( V_2 == V_222 && V_46 -> signal -> V_2 != V_222 )
return - V_67 ;
if ( ! V_222 -> V_79 )
return - V_67 ;
return F_170 ( F_171 ( V_222 -> V_79 ) , V_22 ) ;
}
static int F_178 ( struct V_1 * V_2 , int T_3 * V_22 )
{
int V_159 ;
int V_45 ;
if ( F_159 ( V_159 , V_22 ) )
return - V_136 ;
V_45 = F_179 ( V_2 , V_159 ) ;
return V_45 ;
}
static int F_180 ( struct V_1 * V_2 , unsigned int V_226 )
{
int V_160 ;
if ( V_2 -> V_42 -> V_227 == NULL )
return 0 ;
if ( V_2 -> V_24 -> V_44 & V_228 )
V_160 = V_2 -> V_42 -> V_227 ( V_2 , V_226 ) ;
else {
if ( F_93 ( V_2 , 0 ) < 0 )
return - V_229 ;
V_160 = V_2 -> V_42 -> V_227 ( V_2 , - 1 ) ;
if ( V_160 )
goto V_51;
if ( ! F_96 ( V_46 ) )
F_181 ( V_226 ) ;
V_160 = V_2 -> V_42 -> V_227 ( V_2 , 0 ) ;
V_51:
F_92 ( V_2 ) ;
if ( F_96 ( V_46 ) )
V_160 = - V_229 ;
}
return V_160 ;
}
static int F_182 ( struct V_1 * V_2 , int T_3 * V_22 )
{
int V_160 = - V_224 ;
if ( V_2 -> V_42 -> V_230 ) {
V_160 = V_2 -> V_42 -> V_230 ( V_2 ) ;
if ( V_160 >= 0 )
V_160 = F_170 ( V_160 , V_22 ) ;
}
return V_160 ;
}
static int F_183 ( struct V_1 * V_2 , unsigned int V_64 ,
unsigned T_3 * V_22 )
{
int V_160 ;
unsigned int V_231 , V_232 , V_233 ;
if ( V_2 -> V_42 -> V_234 == NULL )
return - V_224 ;
V_160 = F_159 ( V_233 , V_22 ) ;
if ( V_160 )
return V_160 ;
V_231 = V_232 = 0 ;
switch ( V_64 ) {
case V_235 :
V_231 = V_233 ;
break;
case V_236 :
V_232 = V_233 ;
break;
case V_237 :
V_231 = V_233 ;
V_232 = ~ V_233 ;
break;
}
V_231 &= V_238 | V_239 | V_240 | V_241 | V_242 ;
V_232 &= V_238 | V_239 | V_240 | V_241 | V_242 ;
return V_2 -> V_42 -> V_234 ( V_2 , V_231 , V_232 ) ;
}
static int F_184 ( struct V_1 * V_2 , void T_3 * V_65 )
{
int V_160 = - V_224 ;
struct V_243 V_244 ;
memset ( & V_244 , 0 , sizeof( V_244 ) ) ;
if ( V_2 -> V_42 -> V_245 )
V_160 = V_2 -> V_42 -> V_245 ( V_2 , & V_244 ) ;
if ( V_160 != 0 )
return V_160 ;
if ( F_162 ( V_65 , & V_244 , sizeof( V_244 ) ) )
return - V_136 ;
return 0 ;
}
struct V_1 * F_185 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_158 )
V_2 = V_2 -> V_28 ;
return V_2 ;
}
struct V_1 * F_186 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 -> type == V_25 &&
V_2 -> V_24 -> V_26 == V_158 )
return V_2 ;
return V_2 -> V_28 ;
}
long F_187 ( struct V_6 * V_6 , unsigned int V_64 , unsigned long V_65 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_1 * V_222 ;
void T_3 * V_22 = ( void T_3 * ) V_65 ;
int V_160 ;
struct V_68 * V_69 ;
if ( F_15 ( V_2 , F_90 ( V_6 ) , L_38 ) )
return - V_224 ;
V_222 = F_185 ( V_2 ) ;
switch ( V_64 ) {
case V_246 :
case V_247 :
case V_248 :
case V_249 :
case V_250 :
V_160 = F_31 ( V_2 ) ;
if ( V_160 )
return V_160 ;
if ( V_64 != V_248 ) {
F_188 ( V_2 , 0 ) ;
if ( F_96 ( V_46 ) )
return - V_229 ;
}
break;
}
switch ( V_64 ) {
case V_251 :
return F_158 ( V_2 , V_22 ) ;
case V_252 :
return F_161 ( V_222 , V_22 ) ;
case V_253 :
return F_164 ( V_222 , V_22 ) ;
case V_254 :
return V_222 != V_2 ? - V_224 : F_165 ( V_6 ) ;
case V_255 :
return F_166 ( V_6 , V_22 ) ;
case V_256 :
F_62 ( V_196 , & V_2 -> V_44 ) ;
return 0 ;
case V_257 :
F_66 ( V_196 , & V_2 -> V_44 ) ;
return 0 ;
case V_258 :
{
int V_259 = F_45 ( V_196 , & V_2 -> V_44 ) ;
return F_170 ( V_259 , ( int T_3 * ) V_22 ) ;
}
case V_260 :
if ( V_46 -> signal -> V_2 != V_2 )
return - V_67 ;
F_84 () ;
return 0 ;
case V_261 :
return F_167 ( V_2 , V_65 ) ;
case V_262 :
return F_169 ( V_2 , V_222 , V_22 ) ;
case V_66 :
return F_172 ( V_2 , V_222 , V_22 ) ;
case V_263 :
return F_177 ( V_2 , V_222 , V_22 ) ;
case V_264 :
return F_170 ( V_2 -> V_159 -> V_42 -> V_35 , ( int T_3 * ) V_22 ) ;
case V_246 :
return F_178 ( V_2 , V_22 ) ;
case V_265 :
if ( ! F_150 ( V_197 ) )
return - V_209 ;
F_73 ( V_2 ) ;
return 0 ;
case V_266 :
{
unsigned int V_45 = F_189 ( F_190 ( V_222 ) ) ;
return F_170 ( V_45 , ( unsigned int T_3 * ) V_22 ) ;
}
case V_247 :
if ( V_2 -> V_42 -> V_227 )
return V_2 -> V_42 -> V_227 ( V_2 , - 1 ) ;
return 0 ;
case V_248 :
if ( V_2 -> V_42 -> V_227 )
return V_2 -> V_42 -> V_227 ( V_2 , 0 ) ;
return 0 ;
case V_249 :
if ( ! V_65 )
return F_180 ( V_2 , 250 ) ;
return 0 ;
case V_250 :
return F_180 ( V_2 , V_65 ? V_65 * 100 : 250 ) ;
case V_267 :
return F_182 ( V_2 , V_22 ) ;
case V_237 :
case V_236 :
case V_235 :
return F_183 ( V_2 , V_64 , V_22 ) ;
case V_268 :
V_160 = F_184 ( V_2 , V_22 ) ;
if ( V_160 != - V_224 )
return V_160 ;
break;
case V_269 :
switch ( V_65 ) {
case V_270 :
case V_271 :
F_191 ( V_2 ) ;
break;
}
break;
}
if ( V_2 -> V_42 -> V_272 ) {
V_160 = ( V_2 -> V_42 -> V_272 ) ( V_2 , V_64 , V_65 ) ;
if ( V_160 != - V_273 )
return V_160 ;
}
V_69 = F_91 ( V_2 ) ;
V_160 = - V_224 ;
if ( V_69 -> V_42 -> V_272 ) {
V_160 = V_69 -> V_42 -> V_272 ( V_2 , V_6 , V_64 , V_65 ) ;
if ( V_160 == - V_273 )
V_160 = - V_67 ;
}
F_47 ( V_69 ) ;
return V_160 ;
}
static long F_192 ( struct V_6 * V_6 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_1 * V_2 = F_4 ( V_6 ) ;
struct V_68 * V_69 ;
int V_160 = - V_273 ;
if ( F_15 ( V_2 , F_90 ( V_6 ) , L_38 ) )
return - V_224 ;
if ( V_2 -> V_42 -> V_274 ) {
V_160 = ( V_2 -> V_42 -> V_274 ) ( V_2 , V_64 , V_65 ) ;
if ( V_160 != - V_273 )
return V_160 ;
}
V_69 = F_91 ( V_2 ) ;
if ( V_69 -> V_42 -> V_274 )
V_160 = V_69 -> V_42 -> V_274 ( V_2 , V_6 , V_64 , V_65 ) ;
else
V_160 = F_193 ( V_2 , V_6 , V_64 , V_65 ) ;
F_47 ( V_69 ) ;
return V_160 ;
}
static int F_194 ( const void * V_275 , struct V_6 * V_6 , unsigned V_201 )
{
if ( F_195 ( V_6 -> V_96 -> V_125 != F_89 ) )
return 0 ;
return F_4 ( V_6 ) != V_275 ? 0 : V_201 + 1 ;
}
void F_196 ( struct V_1 * V_2 )
{
#ifdef F_197
F_70 ( V_2 ) ;
#else
struct V_74 * V_276 , * V_22 ;
struct V_76 * V_79 ;
int V_123 ;
if ( ! V_2 )
return;
V_79 = V_2 -> V_79 ;
F_198 ( V_2 ) ;
F_199 ( V_2 ) ;
F_50 ( & V_78 ) ;
F_51 (session, PIDTYPE_SID, p) {
F_17 ( V_277 L_39
L_40 ,
F_200 ( V_22 ) , V_22 -> V_278 ) ;
F_201 ( V_279 , V_22 , 1 ) ;
} F_57 ( V_79 , V_87 , V_22 ) ;
F_202 (g, p) {
if ( V_22 -> signal -> V_2 == V_2 ) {
F_17 ( V_277 L_39
L_40 ,
F_200 ( V_22 ) , V_22 -> V_278 ) ;
F_201 ( V_279 , V_22 , 1 ) ;
continue;
}
F_203 ( V_22 ) ;
V_123 = F_204 ( V_22 -> V_280 , 0 , F_194 , V_2 ) ;
if ( V_123 != 0 ) {
F_17 ( V_277 L_39
L_41 ,
F_200 ( V_22 ) , V_22 -> V_278 , V_123 - 1 ) ;
F_205 ( V_279 , V_22 ) ;
}
F_206 ( V_22 ) ;
} F_207 ( V_276 , V_22 ) ;
F_58 ( & V_78 ) ;
#endif
}
static void F_208 ( struct V_105 * V_106 )
{
struct V_1 * V_2 =
F_69 ( V_106 , struct V_1 , V_171 ) ;
F_196 ( V_2 ) ;
}
void F_209 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_72 ( & V_2 -> V_171 ) ;
}
static int F_210 ( struct V_30 * V_3 , const void * V_281 )
{
const T_1 * V_282 = V_281 ;
return V_3 -> V_282 == * V_282 ;
}
static struct V_30 * F_211 ( struct V_1 * V_2 )
{
T_1 V_282 = F_190 ( V_2 ) ;
return F_212 ( V_283 , NULL , & V_282 , F_210 ) ;
}
struct V_1 * F_115 ( struct V_29 * V_24 , int V_147 )
{
struct V_1 * V_2 ;
V_2 = F_213 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 )
return NULL ;
F_214 ( & V_2 -> V_173 ) ;
V_2 -> V_5 = V_20 ;
F_215 ( V_2 ) ;
V_2 -> V_79 = NULL ;
V_2 -> V_48 = NULL ;
F_216 ( & V_2 -> V_284 ) ;
F_216 ( & V_2 -> V_285 ) ;
F_217 ( & V_2 -> V_286 ) ;
F_216 ( & V_2 -> V_213 ) ;
F_218 ( & V_2 -> V_287 ) ;
F_219 ( & V_2 -> V_72 ) ;
F_219 ( & V_2 -> V_116 ) ;
F_130 ( & V_2 -> V_107 , F_68 ) ;
F_216 ( & V_2 -> V_139 ) ;
F_220 ( & V_2 -> V_47 ) ;
F_221 ( & V_2 -> V_14 ) ;
F_130 ( & V_2 -> V_171 , F_208 ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_42 = V_24 -> V_42 ;
V_2 -> V_31 = V_147 ;
F_102 ( V_24 , V_147 , V_2 -> V_16 ) ;
V_2 -> V_3 = F_211 ( V_2 ) ;
return V_2 ;
}
void F_118 ( struct V_1 * V_2 )
{
F_222 ( V_2 ) ;
}
int F_223 ( struct V_1 * V_2 , unsigned char V_207 )
{
if ( V_2 -> V_42 -> V_288 )
return V_2 -> V_42 -> V_288 ( V_2 , V_207 ) ;
return V_2 -> V_42 -> V_97 ( V_2 , & V_207 , 1 ) ;
}
static int F_224 ( struct V_29 * V_24 , T_1 V_3 ,
unsigned int V_31 , unsigned int V_23 )
{
F_225 ( & V_24 -> V_289 [ V_31 ] , & V_199 ) ;
V_24 -> V_289 [ V_31 ] . V_161 = V_24 -> V_161 ;
return F_226 ( & V_24 -> V_289 [ V_31 ] , V_3 , V_23 ) ;
}
struct V_30 * F_227 ( struct V_29 * V_24 , unsigned V_31 ,
struct V_30 * V_30 )
{
return F_228 ( V_24 , V_31 , V_30 , NULL , NULL ) ;
}
static void F_229 ( struct V_30 * V_3 )
{
F_230 ( L_42 , F_231 ( V_3 ) , V_167 ) ;
F_3 ( V_3 ) ;
}
struct V_30 * F_228 ( struct V_29 * V_24 ,
unsigned V_31 , struct V_30 * V_30 ,
void * V_290 ,
const struct V_291 * * V_292 )
{
char V_16 [ 64 ] ;
T_1 V_282 = F_25 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ;
struct V_30 * V_3 = NULL ;
int V_160 = - V_162 ;
bool V_293 = false ;
if ( V_31 >= V_24 -> V_35 ) {
F_17 ( V_142 L_43
L_44 , V_31 ) ;
return F_114 ( - V_224 ) ;
}
if ( V_24 -> type == V_25 )
F_101 ( V_24 , V_31 , V_16 ) ;
else
F_102 ( V_24 , V_31 , V_16 ) ;
if ( ! ( V_24 -> V_44 & V_294 ) ) {
V_160 = F_224 ( V_24 , V_282 , V_31 , 1 ) ;
if ( V_160 )
goto error;
V_293 = true ;
}
V_3 = F_213 ( sizeof( * V_3 ) , V_10 ) ;
if ( ! V_3 ) {
V_160 = - V_11 ;
goto error;
}
V_3 -> V_282 = V_282 ;
V_3 -> V_295 = V_283 ;
V_3 -> V_296 = V_30 ;
V_3 -> V_297 = F_229 ;
F_232 ( V_3 , L_18 , V_16 ) ;
V_3 -> V_298 = V_292 ;
F_233 ( V_3 , V_290 ) ;
V_160 = F_234 ( V_3 ) ;
if ( V_160 )
goto error;
return V_3 ;
error:
F_2 ( V_3 ) ;
if ( V_293 )
F_235 ( & V_24 -> V_289 [ V_31 ] ) ;
return F_114 ( V_160 ) ;
}
void F_236 ( struct V_29 * V_24 , unsigned V_31 )
{
F_237 ( V_283 ,
F_25 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ) ;
if ( ! ( V_24 -> V_44 & V_294 ) )
F_235 ( & V_24 -> V_289 [ V_31 ] ) ;
}
struct V_29 * F_238 ( unsigned int V_299 , struct V_300 * V_161 ,
unsigned long V_44 )
{
struct V_29 * V_24 ;
unsigned int V_289 = 1 ;
int V_212 ;
if ( ! V_299 || ( V_44 & V_146 && V_299 > 1 ) )
return F_114 ( - V_224 ) ;
V_24 = F_213 ( sizeof( struct V_29 ) , V_10 ) ;
if ( ! V_24 )
return F_114 ( - V_11 ) ;
F_214 ( & V_24 -> V_173 ) ;
V_24 -> V_5 = V_301 ;
V_24 -> V_35 = V_299 ;
V_24 -> V_161 = V_161 ;
V_24 -> V_44 = V_44 ;
if ( ! ( V_44 & V_176 ) ) {
V_24 -> V_149 = F_239 ( V_299 , sizeof( * V_24 -> V_149 ) ,
V_10 ) ;
V_24 -> V_153 = F_239 ( V_299 , sizeof( * V_24 -> V_153 ) ,
V_10 ) ;
if ( ! V_24 -> V_149 || ! V_24 -> V_153 ) {
V_212 = - V_11 ;
goto V_302;
}
}
if ( ! ( V_44 & V_294 ) ) {
V_24 -> V_166 = F_239 ( V_299 , sizeof( * V_24 -> V_166 ) ,
V_10 ) ;
if ( ! V_24 -> V_166 ) {
V_212 = - V_11 ;
goto V_302;
}
V_289 = V_299 ;
}
V_24 -> V_289 = F_239 ( V_289 , sizeof( * V_24 -> V_289 ) , V_10 ) ;
if ( ! V_24 -> V_289 ) {
V_212 = - V_11 ;
goto V_302;
}
return V_24 ;
V_302:
F_3 ( V_24 -> V_166 ) ;
F_3 ( V_24 -> V_149 ) ;
F_3 ( V_24 -> V_153 ) ;
F_3 ( V_24 ) ;
return F_114 ( V_212 ) ;
}
static void F_240 ( struct V_173 * V_173 )
{
struct V_29 * V_24 = F_69 ( V_173 , struct V_29 , V_173 ) ;
int V_123 ;
struct V_150 * V_151 ;
if ( V_24 -> V_44 & V_303 ) {
for ( V_123 = 0 ; V_123 < V_24 -> V_35 ; V_123 ++ ) {
V_151 = V_24 -> V_153 [ V_123 ] ;
if ( V_151 ) {
V_24 -> V_153 [ V_123 ] = NULL ;
F_3 ( V_151 ) ;
}
if ( ! ( V_24 -> V_44 & V_304 ) )
F_236 ( V_24 , V_123 ) ;
}
F_241 ( V_24 ) ;
if ( V_24 -> V_44 & V_294 )
F_235 ( & V_24 -> V_289 [ 0 ] ) ;
}
F_3 ( V_24 -> V_289 ) ;
F_3 ( V_24 -> V_166 ) ;
F_3 ( V_24 -> V_153 ) ;
F_3 ( V_24 -> V_149 ) ;
F_3 ( V_24 ) ;
}
void F_127 ( struct V_29 * V_24 )
{
F_131 ( & V_24 -> V_173 , F_240 ) ;
}
void F_242 ( struct V_29 * V_24 ,
const struct V_305 * V_306 )
{
V_24 -> V_42 = V_306 ;
}
void F_243 ( struct V_29 * V_307 )
{
F_127 ( V_307 ) ;
}
int F_244 ( struct V_29 * V_24 )
{
int error ;
int V_123 ;
T_1 V_3 ;
struct V_30 * V_307 ;
if ( ! V_24 -> V_33 ) {
error = F_245 ( & V_3 , V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_16 ) ;
if ( ! error ) {
V_24 -> V_33 = F_246 ( V_3 ) ;
V_24 -> V_34 = F_247 ( V_3 ) ;
}
} else {
V_3 = F_25 ( V_24 -> V_33 , V_24 -> V_34 ) ;
error = F_248 ( V_3 , V_24 -> V_35 , V_24 -> V_16 ) ;
}
if ( error < 0 )
goto V_212;
if ( V_24 -> V_44 & V_294 ) {
error = F_224 ( V_24 , V_3 , 0 , V_24 -> V_35 ) ;
if ( error )
goto V_308;
}
F_29 ( & V_41 ) ;
F_9 ( & V_24 -> V_309 , & V_309 ) ;
F_30 ( & V_41 ) ;
if ( ! ( V_24 -> V_44 & V_304 ) ) {
for ( V_123 = 0 ; V_123 < V_24 -> V_35 ; V_123 ++ ) {
V_307 = F_227 ( V_24 , V_123 , NULL ) ;
if ( F_148 ( V_307 ) ) {
error = F_149 ( V_307 ) ;
goto V_310;
}
}
}
F_249 ( V_24 ) ;
V_24 -> V_44 |= V_303 ;
return 0 ;
V_310:
for ( V_123 -- ; V_123 >= 0 ; V_123 -- )
F_236 ( V_24 , V_123 ) ;
F_29 ( & V_41 ) ;
F_13 ( & V_24 -> V_309 ) ;
F_30 ( & V_41 ) ;
V_308:
F_250 ( V_3 , V_24 -> V_35 ) ;
V_212:
return error ;
}
int F_251 ( struct V_29 * V_24 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_250 ( F_25 ( V_24 -> V_33 , V_24 -> V_34 ) ,
V_24 -> V_35 ) ;
F_29 ( & V_41 ) ;
F_13 ( & V_24 -> V_309 ) ;
F_30 ( & V_41 ) ;
return 0 ;
}
T_1 F_190 ( struct V_1 * V_2 )
{
return F_25 ( V_2 -> V_24 -> V_33 , V_2 -> V_24 -> V_34 ) + V_2 -> V_31 ;
}
void F_79 ( struct V_74 * V_22 )
{
unsigned long V_44 ;
struct V_1 * V_2 ;
F_32 ( & V_22 -> V_80 -> V_81 , V_44 ) ;
V_2 = V_22 -> signal -> V_2 ;
V_22 -> signal -> V_2 = NULL ;
F_34 ( & V_22 -> V_80 -> V_81 , V_44 ) ;
F_64 ( V_2 ) ;
}
static void F_151 ( struct V_74 * V_111 , struct V_1 * V_2 )
{
if ( V_2 ) {
unsigned long V_44 ;
F_32 ( & V_2 -> V_47 , V_44 ) ;
F_55 ( V_2 -> V_79 ) ;
F_55 ( V_2 -> V_48 ) ;
V_2 -> V_48 = F_56 ( F_33 ( V_111 ) ) ;
F_34 ( & V_2 -> V_47 , V_44 ) ;
V_2 -> V_79 = F_56 ( F_83 ( V_111 ) ) ;
if ( V_111 -> signal -> V_2 ) {
F_17 ( V_108 L_45 ) ;
F_64 ( V_111 -> signal -> V_2 ) ;
}
}
F_55 ( V_111 -> signal -> V_86 ) ;
V_111 -> signal -> V_2 = F_82 ( V_2 ) ;
V_111 -> signal -> V_86 = NULL ;
}
static void F_168 ( struct V_74 * V_111 , struct V_1 * V_2 )
{
F_52 ( & V_111 -> V_80 -> V_81 ) ;
F_151 ( V_111 , V_2 ) ;
F_53 ( & V_111 -> V_80 -> V_81 ) ;
}
struct V_1 * F_75 ( void )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
F_32 ( & V_46 -> V_80 -> V_81 , V_44 ) ;
V_2 = F_82 ( V_46 -> signal -> V_2 ) ;
F_34 ( & V_46 -> V_80 -> V_81 , V_44 ) ;
return V_2 ;
}
void F_252 ( struct V_311 * V_312 )
{
* V_312 = V_199 ;
}
void T_8 F_253 ( void )
{
T_9 * V_313 ;
F_254 () ;
V_313 = V_314 ;
while ( V_313 < V_315 ) {
(* V_313)() ;
V_313 ++ ;
}
}
static char * F_255 ( struct V_30 * V_3 , T_10 * V_316 )
{
if ( ! V_316 )
return NULL ;
if ( V_3 -> V_282 == F_25 ( V_182 , 0 ) ||
V_3 -> V_282 == F_25 ( V_182 , 2 ) )
* V_316 = 0666 ;
return NULL ;
}
static int T_8 F_256 ( void )
{
V_283 = F_257 ( V_317 , L_17 ) ;
if ( F_148 ( V_283 ) )
return F_149 ( V_283 ) ;
V_283 -> V_318 = F_255 ;
return 0 ;
}
static T_2 F_258 ( struct V_30 * V_3 ,
struct V_319 * V_320 , char * V_15 )
{
struct V_321 * V_322 [ 16 ] ;
int V_123 = 0 ;
struct V_321 * V_323 ;
T_2 V_23 = 0 ;
F_259 () ;
F_260 (c) {
if ( ! V_323 -> V_30 )
continue;
if ( ! V_323 -> V_97 )
continue;
if ( ( V_323 -> V_44 & V_324 ) == 0 )
continue;
V_322 [ V_123 ++ ] = V_323 ;
if ( V_123 >= F_261 ( V_322 ) )
break;
}
while ( V_123 -- ) {
int V_31 = V_322 [ V_123 ] -> V_31 ;
struct V_29 * V_325 = V_322 [ V_123 ] -> V_30 ( V_322 [ V_123 ] , & V_31 ) ;
if ( V_325 && ( V_322 [ V_123 ] -> V_31 > 0 || V_325 -> V_33 != V_186 ) )
V_23 += F_102 ( V_325 , V_31 , V_15 + V_23 ) ;
else
V_23 += sprintf ( V_15 + V_23 , L_19 ,
V_322 [ V_123 ] -> V_16 , V_322 [ V_123 ] -> V_31 ) ;
V_23 += sprintf ( V_15 + V_23 , L_46 , V_123 ? ' ' : '\n' ) ;
}
F_262 () ;
return V_23 ;
}
void F_263 ( void )
{
if ( V_326 )
F_264 ( & V_326 -> V_327 , NULL , L_47 ) ;
}
int T_8 F_265 ( void )
{
F_225 ( & V_328 , & V_199 ) ;
if ( F_226 ( & V_328 , F_25 ( V_182 , 0 ) , 1 ) ||
F_248 ( F_25 ( V_182 , 0 ) , 1 , L_48 ) < 0 )
F_266 ( L_49 ) ;
F_267 ( V_283 , NULL , F_25 ( V_182 , 0 ) , NULL , L_17 ) ;
F_225 ( & V_329 , & V_330 ) ;
if ( F_226 ( & V_329 , F_25 ( V_182 , 1 ) , 1 ) ||
F_248 ( F_25 ( V_182 , 1 ) , 1 , L_50 ) < 0 )
F_266 ( L_51 ) ;
V_326 = F_267 ( V_283 , NULL , F_25 ( V_182 , 1 ) , NULL ,
L_52 ) ;
if ( F_148 ( V_326 ) )
V_326 = NULL ;
else
F_111 ( F_268 ( V_326 , & V_331 ) < 0 ) ;
#ifdef F_144
F_269 ( & V_330 ) ;
#endif
return 0 ;
}
