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
static int F_51 ( struct V_1 * V_3 , int V_73 )
{
struct V_74 * V_22 ;
int V_75 = 0 ;
struct V_76 * V_77 = NULL ;
F_52 ( & V_78 ) ;
if ( V_3 -> V_79 ) {
F_53 (tty->session, PIDTYPE_SID, p) {
F_54 ( & V_22 -> V_80 -> V_81 ) ;
if ( V_22 -> signal -> V_3 == V_3 ) {
V_22 -> signal -> V_3 = NULL ;
V_75 ++ ;
}
if ( ! V_22 -> signal -> V_82 ) {
F_55 ( & V_22 -> V_80 -> V_81 ) ;
continue;
}
F_56 ( V_83 , V_84 , V_22 ) ;
F_56 ( V_85 , V_84 , V_22 ) ;
F_57 ( V_22 -> signal -> V_86 ) ;
F_10 ( & V_3 -> V_47 ) ;
V_77 = F_58 ( V_3 -> V_48 ) ;
if ( V_3 -> V_48 )
V_22 -> signal -> V_86 = F_58 ( V_3 -> V_48 ) ;
F_12 ( & V_3 -> V_47 ) ;
F_55 ( & V_22 -> V_80 -> V_81 ) ;
} F_59 ( V_3 -> V_79 , V_87 , V_22 ) ;
}
F_60 ( & V_78 ) ;
if ( V_77 ) {
if ( V_73 )
F_39 ( V_77 , V_83 , V_73 ) ;
F_57 ( V_77 ) ;
}
return V_75 ;
}
static void F_61 ( struct V_1 * V_3 , int V_73 )
{
struct V_7 * V_88 = NULL ;
struct V_7 * V_56 , * V_89 = NULL ;
struct V_8 * V_10 ;
int V_90 = 0 , V_91 ;
int V_75 ;
if ( ! V_3 )
return;
F_10 ( & V_92 ) ;
if ( V_93 && F_6 ( V_93 ) == V_3 ) {
V_89 = V_93 ;
V_93 = NULL ;
}
F_12 ( & V_92 ) ;
F_62 ( V_3 ) ;
F_63 ( V_94 , & V_3 -> V_44 ) ;
F_22 ( V_3 , L_7 ) ;
F_10 ( & V_12 ) ;
F_26 (priv, &tty->tty_files, list) {
V_56 = V_10 -> V_7 ;
if ( V_56 -> V_95 -> V_96 == V_97 )
V_88 = V_56 ;
if ( V_56 -> V_95 -> V_96 != V_98 )
continue;
V_90 ++ ;
F_64 ( - 1 , V_56 , 0 ) ;
V_56 -> V_95 = & V_99 ;
}
F_12 ( & V_12 ) ;
V_75 = F_51 ( V_3 , V_73 ) ;
while ( V_75 -- )
F_65 ( V_3 ) ;
F_66 ( V_3 ) ;
F_54 ( & V_3 -> V_47 ) ;
F_67 ( V_100 , & V_3 -> V_44 ) ;
F_67 ( V_101 , & V_3 -> V_44 ) ;
F_67 ( V_70 , & V_3 -> V_44 ) ;
F_57 ( V_3 -> V_79 ) ;
F_57 ( V_3 -> V_48 ) ;
V_3 -> V_79 = NULL ;
V_3 -> V_48 = NULL ;
V_3 -> V_102 = 0 ;
F_55 ( & V_3 -> V_47 ) ;
if ( V_88 ) {
if ( V_3 -> V_42 -> V_103 )
for ( V_91 = 0 ; V_91 < V_90 ; V_91 ++ )
V_3 -> V_42 -> V_103 ( V_3 , V_88 ) ;
} else if ( V_3 -> V_42 -> V_104 )
( V_3 -> V_42 -> V_104 ) ( V_3 ) ;
F_63 ( V_105 , & V_3 -> V_44 ) ;
F_67 ( V_94 , & V_3 -> V_44 ) ;
F_68 ( V_3 ) ;
if ( V_89 )
F_69 ( V_89 ) ;
}
static void F_70 ( struct V_106 * V_107 )
{
struct V_1 * V_3 =
F_71 ( V_107 , struct V_1 , V_108 ) ;
F_61 ( V_3 , 0 ) ;
}
void F_72 ( struct V_1 * V_3 )
{
#ifdef F_73
char V_15 [ 64 ] ;
F_19 ( V_109 L_8 , F_16 ( V_3 , V_15 ) ) ;
#endif
F_74 ( & V_3 -> V_108 ) ;
}
void F_75 ( struct V_1 * V_3 )
{
#ifdef F_73
char V_15 [ 64 ] ;
F_19 ( V_109 L_9 , F_16 ( V_3 , V_15 ) ) ;
#endif
F_61 ( V_3 , 0 ) ;
}
void F_76 ( void )
{
struct V_1 * V_3 ;
V_3 = F_77 () ;
if ( V_3 ) {
F_75 ( V_3 ) ;
F_65 ( V_3 ) ;
}
}
static void F_78 ( struct V_1 * V_3 )
{
#ifdef F_73
char V_15 [ 64 ] ;
F_19 ( V_109 L_10 , F_16 ( V_3 , V_15 ) ) ;
#endif
F_61 ( V_3 , 1 ) ;
}
int F_79 ( struct V_7 * V_56 )
{
return ( V_56 -> V_95 == & V_99 ) ;
}
static void F_80 ( struct V_76 * V_79 )
{
struct V_74 * V_22 ;
F_53 (session, PIDTYPE_SID, p) {
F_81 ( V_22 ) ;
} F_59 ( V_79 , V_87 , V_22 ) ;
}
void F_82 ( int V_110 )
{
struct V_1 * V_3 ;
if ( ! V_46 -> signal -> V_82 )
return;
V_3 = F_77 () ;
if ( V_3 ) {
if ( V_110 && V_3 -> V_24 -> type != V_25 ) {
F_78 ( V_3 ) ;
} else {
struct V_76 * V_77 = F_83 ( V_3 ) ;
if ( V_77 ) {
F_39 ( V_77 , V_83 , V_110 ) ;
F_39 ( V_77 , V_85 , V_110 ) ;
F_57 ( V_77 ) ;
}
}
F_65 ( V_3 ) ;
} else if ( V_110 ) {
struct V_76 * V_111 ;
F_54 ( & V_46 -> V_80 -> V_81 ) ;
V_111 = V_46 -> signal -> V_86 ;
V_46 -> signal -> V_86 = NULL ;
F_55 ( & V_46 -> V_80 -> V_81 ) ;
if ( V_111 ) {
F_39 ( V_111 , V_83 , V_110 ) ;
F_39 ( V_111 , V_85 , V_110 ) ;
F_57 ( V_111 ) ;
}
return;
}
F_54 ( & V_46 -> V_80 -> V_81 ) ;
F_57 ( V_46 -> signal -> V_86 ) ;
V_46 -> signal -> V_86 = NULL ;
F_55 ( & V_46 -> V_80 -> V_81 ) ;
V_3 = F_77 () ;
if ( V_3 ) {
unsigned long V_44 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
F_57 ( V_3 -> V_79 ) ;
F_57 ( V_3 -> V_48 ) ;
V_3 -> V_79 = NULL ;
V_3 -> V_48 = NULL ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
F_65 ( V_3 ) ;
} else {
#ifdef F_73
F_19 ( V_109 L_11
L_12 , V_3 ) ;
#endif
}
F_52 ( & V_78 ) ;
F_80 ( F_84 ( V_46 ) ) ;
F_60 ( & V_78 ) ;
}
void F_85 ( void )
{
struct V_74 * V_112 = V_46 ;
F_82 ( 0 ) ;
F_81 ( V_112 ) ;
}
void F_86 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_113 ) {
F_36 ( & V_3 -> V_47 , V_44 ) ;
return;
}
V_3 -> V_113 = 1 ;
if ( V_3 -> V_28 && V_3 -> V_28 -> V_114 ) {
V_3 -> V_102 &= ~ V_115 ;
V_3 -> V_102 |= V_116 ;
F_50 ( & V_3 -> V_28 -> V_117 , V_58 ) ;
}
F_36 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_42 -> V_118 )
( V_3 -> V_42 -> V_118 ) ( V_3 ) ;
}
void F_87 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
if ( ! V_3 -> V_113 || V_3 -> V_119 ) {
F_36 ( & V_3 -> V_47 , V_44 ) ;
return;
}
V_3 -> V_113 = 0 ;
if ( V_3 -> V_28 && V_3 -> V_28 -> V_114 ) {
V_3 -> V_102 &= ~ V_116 ;
V_3 -> V_102 |= V_115 ;
F_50 ( & V_3 -> V_28 -> V_117 , V_58 ) ;
}
F_36 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_42 -> V_120 )
( V_3 -> V_42 -> V_120 ) ( V_3 ) ;
F_46 ( V_3 ) ;
}
static void F_88 ( struct V_121 * time )
{
unsigned long V_122 = F_89 () & ~ 7 ;
if ( ( long ) ( V_122 - time -> V_123 ) > 0 )
time -> V_123 = V_122 ;
}
static T_2 F_90 ( struct V_7 * V_7 , char T_3 * V_15 , T_4 V_23 ,
T_5 * V_55 )
{
int V_124 ;
struct V_17 * V_17 = F_91 ( V_7 ) ;
struct V_1 * V_3 = F_6 ( V_7 ) ;
struct V_68 * V_69 ;
if ( F_17 ( V_3 , V_17 , L_13 ) )
return - V_52 ;
if ( ! V_3 || ( F_47 ( V_125 , & V_3 -> V_44 ) ) )
return - V_52 ;
V_69 = F_92 ( V_3 ) ;
if ( V_69 -> V_42 -> V_126 )
V_124 = ( V_69 -> V_42 -> V_126 ) ( V_3 , V_7 , V_15 , V_23 ) ;
else
V_124 = - V_52 ;
F_49 ( V_69 ) ;
if ( V_124 > 0 )
F_88 ( & V_17 -> V_127 ) ;
return V_124 ;
}
void F_93 ( struct V_1 * V_3 )
__releases( &tty->atomic_write_lock
int F_94 ( struct V_1 * V_3 , int V_128 )
__acquires( &tty->atomic_write_lock
static inline T_2 F_95 (
T_2 (* V_96)( struct V_1 * , struct V_7 * , const unsigned char * , T_4 ) ,
struct V_1 * V_3 ,
struct V_7 * V_7 ,
const char T_3 * V_15 ,
T_4 V_23 )
{
T_2 V_45 , V_129 = 0 ;
unsigned int V_130 ;
V_45 = F_94 ( V_3 , V_7 -> V_131 & V_132 ) ;
if ( V_45 < 0 )
return V_45 ;
V_130 = 2048 ;
if ( F_47 ( V_133 , & V_3 -> V_44 ) )
V_130 = 65536 ;
if ( V_23 < V_130 )
V_130 = V_23 ;
if ( V_3 -> V_134 < V_130 ) {
unsigned char * V_135 ;
if ( V_130 < 1024 )
V_130 = 1024 ;
V_135 = F_8 ( V_130 , V_2 ) ;
if ( ! V_135 ) {
V_45 = - V_11 ;
goto V_51;
}
F_5 ( V_3 -> V_5 ) ;
V_3 -> V_134 = V_130 ;
V_3 -> V_5 = V_135 ;
}
for (; ; ) {
T_4 V_136 = V_23 ;
if ( V_136 > V_130 )
V_136 = V_130 ;
V_45 = - V_137 ;
if ( F_96 ( V_3 -> V_5 , V_15 , V_136 ) )
break;
V_45 = V_96 ( V_3 , V_7 , V_3 -> V_5 , V_136 ) ;
if ( V_45 <= 0 )
break;
V_129 += V_45 ;
V_15 += V_45 ;
V_23 -= V_45 ;
if ( ! V_23 )
break;
V_45 = - V_54 ;
if ( F_97 ( V_46 ) )
break;
F_98 () ;
}
if ( V_129 ) {
F_88 ( & F_91 ( V_7 ) -> V_138 ) ;
V_45 = V_129 ;
}
V_51:
F_93 ( V_3 ) ;
return V_45 ;
}
void F_99 ( struct V_1 * V_3 , char * V_139 )
{
if ( V_3 ) {
F_31 ( & V_3 -> V_140 ) ;
F_62 ( V_3 ) ;
if ( V_3 -> V_42 -> V_96 && ! F_47 ( V_141 , & V_3 -> V_44 ) ) {
F_68 ( V_3 ) ;
V_3 -> V_42 -> V_96 ( V_3 , V_139 , strlen ( V_139 ) ) ;
} else
F_68 ( V_3 ) ;
F_93 ( V_3 ) ;
}
return;
}
static T_2 V_98 ( struct V_7 * V_7 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_1 * V_3 = F_6 ( V_7 ) ;
struct V_68 * V_69 ;
T_2 V_45 ;
if ( F_17 ( V_3 , F_91 ( V_7 ) , L_14 ) )
return - V_52 ;
if ( ! V_3 || ! V_3 -> V_42 -> V_96 ||
( F_47 ( V_125 , & V_3 -> V_44 ) ) )
return - V_52 ;
if ( V_3 -> V_42 -> V_142 == NULL )
F_19 ( V_143 L_15 ,
V_3 -> V_24 -> V_16 ) ;
V_69 = F_92 ( V_3 ) ;
if ( ! V_69 -> V_42 -> V_96 )
V_45 = - V_52 ;
else
V_45 = F_95 ( V_69 -> V_42 -> V_96 , V_3 , V_7 , V_15 , V_23 ) ;
F_49 ( V_69 ) ;
return V_45 ;
}
T_2 V_97 ( struct V_7 * V_7 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_7 * V_22 = NULL ;
F_10 ( & V_92 ) ;
if ( V_93 )
V_22 = F_100 ( V_93 ) ;
F_12 ( & V_92 ) ;
if ( V_22 ) {
T_2 V_36 ;
V_36 = F_101 ( V_22 , V_15 , V_23 , & V_22 -> V_144 ) ;
F_69 ( V_22 ) ;
return V_36 ;
}
return V_98 ( V_7 , V_15 , V_23 , V_55 ) ;
}
static void F_102 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
int V_124 = V_31 + V_24 -> V_145 ;
sprintf ( V_22 , L_16 ,
V_24 -> V_26 == V_27 ? L_17 : V_24 -> V_16 ,
V_146 [ V_124 >> 4 & 0xf ] , V_124 & 0xf ) ;
}
static void F_103 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
if ( V_24 -> V_44 & V_147 )
strcpy ( V_22 , V_24 -> V_16 ) ;
else
sprintf ( V_22 , L_18 , V_24 -> V_16 , V_31 + V_24 -> V_145 ) ;
}
static struct V_1 * F_104 ( struct V_29 * V_24 ,
struct V_17 * V_17 , int V_148 )
{
if ( V_24 -> V_42 -> V_149 )
return V_24 -> V_42 -> V_149 ( V_24 , V_17 , V_148 ) ;
return V_24 -> V_150 [ V_148 ] ;
}
int F_105 ( struct V_1 * V_3 )
{
struct V_151 * V_152 ;
int V_148 = V_3 -> V_31 ;
if ( V_3 -> V_24 -> V_44 & V_153 )
V_3 -> V_154 = V_3 -> V_24 -> V_155 ;
else {
V_152 = V_3 -> V_24 -> V_154 [ V_148 ] ;
if ( V_152 != NULL )
V_3 -> V_154 = * V_152 ;
else
V_3 -> V_154 = V_3 -> V_24 -> V_155 ;
}
V_3 -> V_154 . V_156 = F_106 ( & V_3 -> V_154 ) ;
V_3 -> V_154 . V_157 = F_107 ( & V_3 -> V_154 ) ;
return 0 ;
}
int F_108 ( struct V_29 * V_24 , struct V_1 * V_3 )
{
int V_45 = F_105 ( V_3 ) ;
if ( V_45 )
return V_45 ;
F_28 ( V_24 ) ;
V_3 -> V_23 ++ ;
V_24 -> V_150 [ V_3 -> V_31 ] = V_3 ;
return 0 ;
}
static int F_109 ( struct V_29 * V_24 ,
struct V_1 * V_3 )
{
return V_24 -> V_42 -> V_158 ? V_24 -> V_42 -> V_158 ( V_24 , V_3 ) :
F_108 ( V_24 , V_3 ) ;
}
void F_110 ( struct V_29 * V_24 , struct V_1 * V_3 )
{
if ( V_24 -> V_42 -> remove )
V_24 -> V_42 -> remove ( V_24 , V_3 ) ;
else
V_24 -> V_150 [ V_3 -> V_31 ] = NULL ;
}
static int F_111 ( struct V_1 * V_3 )
{
struct V_29 * V_24 = V_3 -> V_24 ;
if ( F_47 ( V_141 , & V_3 -> V_44 ) ||
F_47 ( V_94 , & V_3 -> V_44 ) ||
F_47 ( V_159 , & V_3 -> V_44 ) )
return - V_52 ;
if ( V_24 -> type == V_25 &&
V_24 -> V_26 == V_160 ) {
if ( V_3 -> V_23 )
return - V_52 ;
V_3 -> V_28 -> V_23 ++ ;
}
V_3 -> V_23 ++ ;
F_112 ( ! F_47 ( V_161 , & V_3 -> V_44 ) ) ;
return 0 ;
}
struct V_1 * F_113 ( struct V_29 * V_24 , int V_148 )
{
struct V_1 * V_3 ;
int V_162 ;
if ( ! F_114 ( V_24 -> V_163 ) )
return F_115 ( - V_164 ) ;
V_3 = F_1 () ;
if ( ! V_3 ) {
V_162 = - V_11 ;
goto V_165;
}
F_116 ( V_3 , V_24 , V_148 ) ;
F_62 ( V_3 ) ;
V_162 = F_109 ( V_24 , V_3 ) ;
if ( V_162 < 0 )
goto V_166;
if ( ! V_3 -> V_167 )
V_3 -> V_167 = V_24 -> V_168 [ V_148 ] ;
F_117 ( ! V_3 -> V_167 ,
L_19 ,
V_169 , V_3 -> V_24 -> V_16 ) ;
V_3 -> V_167 -> V_170 = V_3 ;
V_162 = F_118 ( V_3 , V_3 -> V_28 ) ;
if ( V_162 )
goto V_171;
return V_3 ;
V_166:
F_68 ( V_3 ) ;
F_119 ( V_3 ) ;
F_3 ( V_3 ) ;
V_165:
F_120 ( V_24 -> V_163 ) ;
return F_115 ( V_162 ) ;
V_171:
F_68 ( V_3 ) ;
F_121 ( V_172 L_20
L_21 , V_148 ) ;
F_122 ( V_3 , V_148 ) ;
return F_115 ( V_162 ) ;
}
void F_123 ( struct V_1 * V_3 )
{
struct V_151 * V_152 ;
int V_148 = V_3 -> V_31 ;
if ( V_3 -> V_24 -> V_44 & V_153 )
return;
V_152 = V_3 -> V_24 -> V_154 [ V_148 ] ;
if ( V_152 == NULL ) {
V_152 = F_8 ( sizeof( struct V_151 ) , V_2 ) ;
if ( V_152 == NULL ) {
F_124 ( L_22 ) ;
return;
}
V_3 -> V_24 -> V_154 [ V_148 ] = V_152 ;
}
* V_152 = V_3 -> V_154 ;
}
static void F_125 ( struct V_1 * V_3 )
{
F_126 ( & V_3 -> V_173 ) ;
F_126 ( & V_3 -> V_108 ) ;
}
static void F_127 ( struct V_106 * V_107 )
{
struct V_1 * V_3 =
F_71 ( V_107 , struct V_1 , V_108 ) ;
struct V_29 * V_24 = V_3 -> V_24 ;
if ( V_3 -> V_42 -> V_174 )
V_3 -> V_42 -> V_174 ( V_3 ) ;
V_3 -> V_6 = 0 ;
F_128 ( V_24 ) ;
F_120 ( V_24 -> V_163 ) ;
F_10 ( & V_12 ) ;
F_129 ( & V_3 -> V_14 ) ;
F_12 ( & V_12 ) ;
F_57 ( V_3 -> V_48 ) ;
F_57 ( V_3 -> V_79 ) ;
F_3 ( V_3 ) ;
}
static void F_130 ( struct V_175 * V_175 )
{
struct V_1 * V_3 = F_71 ( V_175 , struct V_1 , V_175 ) ;
F_131 ( & V_3 -> V_108 , F_127 ) ;
F_74 ( & V_3 -> V_108 ) ;
}
void F_65 ( struct V_1 * V_3 )
{
if ( V_3 )
F_132 ( & V_3 -> V_175 , F_130 ) ;
}
static void F_122 ( struct V_1 * V_3 , int V_148 )
{
F_112 ( V_3 -> V_31 != V_148 ) ;
F_112 ( ! F_133 ( & V_41 ) ) ;
if ( V_3 -> V_42 -> V_176 )
V_3 -> V_42 -> V_176 ( V_3 ) ;
F_123 ( V_3 ) ;
F_110 ( V_3 -> V_24 , V_3 ) ;
V_3 -> V_167 -> V_170 = NULL ;
F_134 ( & V_3 -> V_167 -> V_15 . V_107 ) ;
if ( V_3 -> V_28 )
F_65 ( V_3 -> V_28 ) ;
F_65 ( V_3 ) ;
}
static int F_135 ( struct V_1 * V_3 , struct V_1 * V_177 ,
int V_148 )
{
#ifdef F_18
if ( V_148 < 0 || V_148 >= V_3 -> V_24 -> V_35 ) {
F_19 ( V_109 L_23 ,
V_169 , V_3 -> V_16 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_44 & V_178 )
return 0 ;
if ( V_3 != V_3 -> V_24 -> V_150 [ V_148 ] ) {
F_19 ( V_109 L_24 ,
V_169 , V_148 , V_3 -> V_16 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_179 ) {
if ( V_177 != V_3 -> V_24 -> V_179 -> V_150 [ V_148 ] ) {
F_19 ( V_109 L_25 ,
V_169 , V_148 , V_3 -> V_16 ) ;
return - 1 ;
}
if ( V_177 -> V_28 != V_3 ) {
F_19 ( V_109 L_26 , V_169 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_136 ( struct V_17 * V_17 , struct V_7 * V_56 )
{
struct V_1 * V_3 = F_6 ( V_56 ) ;
struct V_1 * V_177 ;
int V_180 , V_181 , V_182 , V_183 ;
int V_148 ;
char V_15 [ 64 ] ;
if ( F_17 ( V_3 , V_17 , V_169 ) )
return 0 ;
F_62 ( V_3 ) ;
F_22 ( V_3 , V_169 ) ;
F_64 ( - 1 , V_56 , 0 ) ;
V_148 = V_3 -> V_31 ;
V_180 = ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_160 ) ;
V_177 = V_3 -> V_28 ;
if ( F_135 ( V_3 , V_177 , V_148 ) ) {
F_68 ( V_3 ) ;
return 0 ;
}
#ifdef F_73
F_19 ( V_109 L_27 , V_169 ,
F_16 ( V_3 , V_15 ) , V_3 -> V_23 ) ;
#endif
if ( V_3 -> V_42 -> V_103 )
V_3 -> V_42 -> V_103 ( V_3 , V_56 ) ;
F_68 ( V_3 ) ;
while ( 1 ) {
F_31 ( & V_41 ) ;
F_137 ( V_3 , V_177 ) ;
V_181 = V_3 -> V_23 <= 1 ;
V_182 = V_177 &&
( V_177 -> V_23 <= ( V_180 ? 1 : 0 ) ) ;
V_183 = 0 ;
if ( V_181 ) {
if ( F_138 ( & V_3 -> V_117 ) ) {
F_139 ( & V_3 -> V_117 , V_58 ) ;
V_183 ++ ;
}
if ( F_138 ( & V_3 -> V_72 ) ) {
F_139 ( & V_3 -> V_72 , V_59 ) ;
V_183 ++ ;
}
}
if ( V_182 ) {
if ( F_138 ( & V_177 -> V_117 ) ) {
F_139 ( & V_177 -> V_117 , V_58 ) ;
V_183 ++ ;
}
if ( F_138 ( & V_177 -> V_72 ) ) {
F_139 ( & V_177 -> V_72 , V_59 ) ;
V_183 ++ ;
}
}
if ( ! V_183 )
break;
F_19 ( V_19 L_28 ,
V_169 , F_16 ( V_3 , V_15 ) ) ;
F_140 ( V_3 , V_177 ) ;
F_32 ( & V_41 ) ;
F_141 () ;
}
if ( V_180 ) {
if ( -- V_177 -> V_23 < 0 ) {
F_19 ( V_19 L_29 ,
V_169 , V_177 -> V_23 , F_16 ( V_177 , V_15 ) ) ;
V_177 -> V_23 = 0 ;
}
}
if ( -- V_3 -> V_23 < 0 ) {
F_19 ( V_19 L_30 ,
V_169 , V_3 -> V_23 , F_16 ( V_3 , V_15 ) ) ;
V_3 -> V_23 = 0 ;
}
F_14 ( V_56 ) ;
if ( V_181 )
F_63 ( V_141 , & V_3 -> V_44 ) ;
if ( V_182 )
F_63 ( V_141 , & V_177 -> V_44 ) ;
if ( V_181 || V_182 ) {
F_52 ( & V_78 ) ;
F_80 ( V_3 -> V_79 ) ;
if ( V_177 )
F_80 ( V_177 -> V_79 ) ;
F_60 ( & V_78 ) ;
}
F_32 ( & V_41 ) ;
F_140 ( V_3 , V_177 ) ;
if ( ! V_181 || ( V_177 && ! V_182 ) )
return 0 ;
#ifdef F_73
F_19 ( V_109 L_31 , V_169 , F_16 ( V_3 , V_15 ) ) ;
#endif
F_142 ( V_3 , V_177 ) ;
F_125 ( V_3 ) ;
if ( V_177 )
F_125 ( V_177 ) ;
#ifdef F_73
F_19 ( V_109 L_32 , V_169 , F_16 ( V_3 , V_15 ) ) ;
#endif
F_31 ( & V_41 ) ;
F_122 ( V_3 , V_148 ) ;
F_32 ( & V_41 ) ;
return 0 ;
}
static struct V_1 * F_143 ( T_1 V_30 , struct V_7 * V_56 )
{
struct V_1 * V_3 ;
if ( V_30 != F_27 ( V_184 , 0 ) )
return NULL ;
V_3 = F_77 () ;
if ( ! V_3 )
return F_115 ( - V_185 ) ;
V_56 -> V_131 |= V_186 ;
F_65 ( V_3 ) ;
return V_3 ;
}
static struct V_29 * F_144 ( T_1 V_30 , struct V_7 * V_56 ,
int * V_187 , int * V_31 )
{
struct V_29 * V_24 ;
switch ( V_30 ) {
#ifdef F_145
case F_27 ( V_188 , 0 ) : {
extern struct V_29 * V_189 ;
V_24 = F_28 ( V_189 ) ;
* V_31 = V_190 ;
* V_187 = 1 ;
break;
}
#endif
case F_27 ( V_184 , 1 ) : {
struct V_29 * V_189 = F_146 ( V_31 ) ;
if ( V_189 ) {
V_24 = F_28 ( V_189 ) ;
if ( V_24 ) {
V_56 -> V_131 |= V_186 ;
* V_187 = 1 ;
break;
}
}
return F_115 ( - V_164 ) ;
}
default:
V_24 = F_25 ( V_30 , V_31 ) ;
if ( ! V_24 )
return F_115 ( - V_164 ) ;
break;
}
return V_24 ;
}
static int F_147 ( struct V_17 * V_17 , struct V_7 * V_56 )
{
struct V_1 * V_3 ;
int V_187 , V_162 ;
struct V_29 * V_24 = NULL ;
int V_31 ;
T_1 V_30 = V_17 -> V_191 ;
unsigned V_192 = V_56 -> V_131 ;
F_148 ( V_17 , V_56 ) ;
V_193:
V_162 = F_7 ( V_56 ) ;
if ( V_162 )
return - V_11 ;
V_187 = V_56 -> V_131 & V_194 ;
V_31 = - 1 ;
V_162 = 0 ;
F_31 ( & V_41 ) ;
V_3 = F_143 ( V_30 , V_56 ) ;
if ( F_149 ( V_3 ) ) {
V_162 = F_150 ( V_3 ) ;
goto V_195;
} else if ( ! V_3 ) {
V_24 = F_144 ( V_30 , V_56 , & V_187 , & V_31 ) ;
if ( F_149 ( V_24 ) ) {
V_162 = F_150 ( V_24 ) ;
goto V_195;
}
V_3 = F_104 ( V_24 , V_17 , V_31 ) ;
if ( F_149 ( V_3 ) ) {
V_162 = F_150 ( V_3 ) ;
goto V_195;
}
}
if ( V_3 ) {
F_62 ( V_3 ) ;
V_162 = F_111 ( V_3 ) ;
if ( V_162 < 0 ) {
F_68 ( V_3 ) ;
V_3 = F_115 ( V_162 ) ;
}
} else
V_3 = F_113 ( V_24 , V_31 ) ;
F_32 ( & V_41 ) ;
if ( V_24 )
F_128 ( V_24 ) ;
if ( F_149 ( V_3 ) ) {
V_162 = F_150 ( V_3 ) ;
goto V_196;
}
F_9 ( V_3 , V_56 ) ;
F_22 ( V_3 , V_169 ) ;
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_160 )
V_187 = 1 ;
#ifdef F_73
F_19 ( V_109 L_33 , V_169 , V_3 -> V_16 ) ;
#endif
if ( V_3 -> V_42 -> V_197 )
V_162 = V_3 -> V_42 -> V_197 ( V_3 , V_56 ) ;
else
V_162 = - V_164 ;
V_56 -> V_131 = V_192 ;
if ( ! V_162 && F_47 ( V_198 , & V_3 -> V_44 ) &&
! F_151 ( V_199 ) )
V_162 = - V_200 ;
if ( V_162 ) {
#ifdef F_73
F_19 ( V_109 L_34 , V_169 ,
V_162 , V_3 -> V_16 ) ;
#endif
F_68 ( V_3 ) ;
F_136 ( V_17 , V_56 ) ;
if ( V_162 != - V_54 )
return V_162 ;
if ( F_97 ( V_46 ) )
return V_162 ;
F_141 () ;
if ( V_56 -> V_95 == & V_99 )
V_56 -> V_95 = & V_201 ;
goto V_193;
}
F_68 ( V_3 ) ;
F_31 ( & V_41 ) ;
F_62 ( V_3 ) ;
F_54 ( & V_46 -> V_80 -> V_81 ) ;
if ( ! V_187 &&
V_46 -> signal -> V_82 &&
! V_46 -> signal -> V_3 &&
V_3 -> V_79 == NULL )
F_152 ( V_46 , V_3 ) ;
F_55 ( & V_46 -> V_80 -> V_81 ) ;
F_68 ( V_3 ) ;
F_32 ( & V_41 ) ;
return 0 ;
V_195:
F_32 ( & V_41 ) ;
if ( ! F_153 ( V_24 ) )
F_128 ( V_24 ) ;
V_196:
F_13 ( V_56 ) ;
return V_162 ;
}
static unsigned int F_154 ( struct V_7 * V_56 , T_6 * V_57 )
{
struct V_1 * V_3 = F_6 ( V_56 ) ;
struct V_68 * V_69 ;
int V_45 = 0 ;
if ( F_17 ( V_3 , F_91 ( V_56 ) , L_35 ) )
return 0 ;
V_69 = F_92 ( V_3 ) ;
if ( V_69 -> V_42 -> V_202 )
V_45 = ( V_69 -> V_42 -> V_202 ) ( V_3 , V_56 , V_57 ) ;
F_49 ( V_69 ) ;
return V_45 ;
}
static int F_64 ( int V_203 , struct V_7 * V_56 , int V_204 )
{
struct V_1 * V_3 = F_6 ( V_56 ) ;
unsigned long V_44 ;
int V_162 = 0 ;
if ( F_17 ( V_3 , F_91 ( V_56 ) , L_36 ) )
goto V_51;
V_162 = F_155 ( V_203 , V_56 , V_204 , & V_3 -> V_205 ) ;
if ( V_162 <= 0 )
goto V_51;
if ( V_204 ) {
enum V_206 type ;
struct V_76 * V_76 ;
if ( ! F_138 ( & V_3 -> V_117 ) )
V_3 -> V_207 = 1 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_48 ) {
V_76 = V_3 -> V_48 ;
type = V_208 ;
} else {
V_76 = F_156 ( V_46 ) ;
type = V_209 ;
}
F_58 ( V_76 ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
V_162 = F_157 ( V_56 , V_76 , type , 0 ) ;
F_57 ( V_76 ) ;
if ( V_162 )
goto V_51;
} else {
if ( ! V_3 -> V_205 && ! F_138 ( & V_3 -> V_117 ) )
V_3 -> V_207 = V_210 ;
}
V_162 = 0 ;
V_51:
return V_162 ;
}
static int F_158 ( int V_203 , struct V_7 * V_56 , int V_204 )
{
struct V_1 * V_3 = F_6 ( V_56 ) ;
int V_162 ;
F_62 ( V_3 ) ;
V_162 = F_64 ( V_203 , V_56 , V_204 ) ;
F_68 ( V_3 ) ;
return V_162 ;
}
static int F_159 ( struct V_1 * V_3 , char T_3 * V_22 )
{
char V_211 , V_212 = 0 ;
struct V_68 * V_69 ;
if ( ( V_46 -> signal -> V_3 != V_3 ) && ! F_151 ( V_199 ) )
return - V_213 ;
if ( F_160 ( V_211 , V_22 ) )
return - V_137 ;
F_161 ( V_3 , V_211 ) ;
V_69 = F_92 ( V_3 ) ;
V_69 -> V_42 -> V_214 ( V_3 , & V_211 , & V_212 , 1 ) ;
F_49 ( V_69 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_3 , struct V_215 T_3 * V_65 )
{
int V_216 ;
F_31 ( & V_3 -> V_217 ) ;
V_216 = F_163 ( V_65 , & V_3 -> V_215 , sizeof( * V_65 ) ) ;
F_32 ( & V_3 -> V_217 ) ;
return V_216 ? - V_137 : 0 ;
}
int F_164 ( struct V_1 * V_3 , struct V_215 * V_218 )
{
struct V_76 * V_48 ;
unsigned long V_44 ;
F_31 ( & V_3 -> V_217 ) ;
if ( ! memcmp ( V_218 , & V_3 -> V_215 , sizeof( * V_218 ) ) )
goto V_219;
F_34 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_58 ( V_3 -> V_48 ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
if ( V_48 )
F_39 ( V_48 , V_220 , 1 ) ;
F_57 ( V_48 ) ;
V_3 -> V_215 = * V_218 ;
V_219:
F_32 ( & V_3 -> V_217 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_3 , struct V_215 T_3 * V_65 )
{
struct V_215 V_221 ;
if ( F_96 ( & V_221 , V_65 , sizeof( * V_65 ) ) )
return - V_137 ;
if ( V_3 -> V_42 -> V_222 )
return V_3 -> V_42 -> V_222 ( V_3 , & V_221 ) ;
else
return F_164 ( V_3 , & V_221 ) ;
}
static int F_166 ( struct V_7 * V_7 )
{
if ( ! F_151 ( V_199 ) )
return - V_213 ;
if ( V_7 -> V_95 -> V_96 == V_97 ) {
struct V_7 * V_89 ;
F_10 ( & V_92 ) ;
V_89 = V_93 ;
V_93 = NULL ;
F_12 ( & V_92 ) ;
if ( V_89 )
F_69 ( V_89 ) ;
return 0 ;
}
F_10 ( & V_92 ) ;
if ( V_93 ) {
F_12 ( & V_92 ) ;
return - V_200 ;
}
V_93 = F_100 ( V_7 ) ;
F_12 ( & V_92 ) ;
return 0 ;
}
static int F_167 ( struct V_7 * V_7 , int T_3 * V_22 )
{
int V_223 ;
if ( F_160 ( V_223 , V_22 ) )
return - V_137 ;
F_10 ( & V_7 -> V_224 ) ;
if ( V_223 )
V_7 -> V_131 |= V_186 ;
else
V_7 -> V_131 &= ~ V_186 ;
F_12 ( & V_7 -> V_224 ) ;
return 0 ;
}
static int F_168 ( struct V_1 * V_3 , int V_65 )
{
int V_45 = 0 ;
if ( V_46 -> signal -> V_82 && ( F_84 ( V_46 ) == V_3 -> V_79 ) )
return V_45 ;
F_31 ( & V_41 ) ;
if ( ! V_46 -> signal -> V_82 || V_46 -> signal -> V_3 ) {
V_45 = - V_213 ;
goto V_225;
}
if ( V_3 -> V_79 ) {
if ( V_65 == 1 && F_151 ( V_199 ) ) {
F_52 ( & V_78 ) ;
F_80 ( V_3 -> V_79 ) ;
F_60 ( & V_78 ) ;
} else {
V_45 = - V_213 ;
goto V_225;
}
}
F_169 ( V_46 , V_3 ) ;
V_225:
F_32 ( & V_41 ) ;
return V_45 ;
}
struct V_76 * F_83 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
struct V_76 * V_48 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_58 ( V_3 -> V_48 ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
return V_48 ;
}
static int F_170 ( struct V_1 * V_3 , struct V_1 * V_226 , T_7 T_3 * V_22 )
{
struct V_76 * V_76 ;
int V_45 ;
if ( V_3 == V_226 && V_46 -> signal -> V_3 != V_226 )
return - V_67 ;
V_76 = F_83 ( V_226 ) ;
V_45 = F_171 ( F_172 ( V_76 ) , V_22 ) ;
F_57 ( V_76 ) ;
return V_45 ;
}
static int F_173 ( struct V_1 * V_3 , struct V_1 * V_226 , T_7 T_3 * V_22 )
{
struct V_76 * V_48 ;
T_7 V_227 ;
int V_162 = F_33 ( V_226 ) ;
unsigned long V_44 ;
if ( V_162 == - V_52 )
return - V_67 ;
if ( V_162 )
return V_162 ;
if ( ! V_46 -> signal -> V_3 ||
( V_46 -> signal -> V_3 != V_226 ) ||
( V_226 -> V_79 != F_84 ( V_46 ) ) )
return - V_67 ;
if ( F_160 ( V_227 , V_22 ) )
return - V_137 ;
if ( V_227 < 0 )
return - V_228 ;
F_174 () ;
V_48 = F_175 ( V_227 ) ;
V_162 = - V_229 ;
if ( ! V_48 )
goto V_49;
V_162 = - V_213 ;
if ( F_176 ( V_48 ) != F_84 ( V_46 ) )
goto V_49;
V_162 = 0 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
F_57 ( V_226 -> V_48 ) ;
V_226 -> V_48 = F_58 ( V_48 ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
V_49:
F_177 () ;
return V_162 ;
}
static int F_178 ( struct V_1 * V_3 , struct V_1 * V_226 , T_7 T_3 * V_22 )
{
if ( V_3 == V_226 && V_46 -> signal -> V_3 != V_226 )
return - V_67 ;
if ( ! V_226 -> V_79 )
return - V_67 ;
return F_171 ( F_172 ( V_226 -> V_79 ) , V_22 ) ;
}
static int F_179 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_230 ;
int V_45 ;
if ( F_160 ( V_230 , V_22 ) )
return - V_137 ;
V_45 = F_180 ( V_3 , V_230 ) ;
return V_45 ;
}
static int F_181 ( struct V_1 * V_3 , unsigned int V_231 )
{
int V_162 ;
if ( V_3 -> V_42 -> V_232 == NULL )
return 0 ;
if ( V_3 -> V_24 -> V_44 & V_233 )
V_162 = V_3 -> V_42 -> V_232 ( V_3 , V_231 ) ;
else {
if ( F_94 ( V_3 , 0 ) < 0 )
return - V_234 ;
V_162 = V_3 -> V_42 -> V_232 ( V_3 , - 1 ) ;
if ( V_162 )
goto V_51;
if ( ! F_97 ( V_46 ) )
F_182 ( V_231 ) ;
V_162 = V_3 -> V_42 -> V_232 ( V_3 , 0 ) ;
V_51:
F_93 ( V_3 ) ;
if ( F_97 ( V_46 ) )
V_162 = - V_234 ;
}
return V_162 ;
}
static int F_183 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_162 = - V_228 ;
if ( V_3 -> V_42 -> V_235 ) {
V_162 = V_3 -> V_42 -> V_235 ( V_3 ) ;
if ( V_162 >= 0 )
V_162 = F_171 ( V_162 , V_22 ) ;
}
return V_162 ;
}
static int F_184 ( struct V_1 * V_3 , unsigned int V_64 ,
unsigned T_3 * V_22 )
{
int V_162 ;
unsigned int V_236 , V_237 , V_238 ;
if ( V_3 -> V_42 -> V_239 == NULL )
return - V_228 ;
V_162 = F_160 ( V_238 , V_22 ) ;
if ( V_162 )
return V_162 ;
V_236 = V_237 = 0 ;
switch ( V_64 ) {
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
return V_3 -> V_42 -> V_239 ( V_3 , V_236 , V_237 ) ;
}
static int F_185 ( struct V_1 * V_3 , void T_3 * V_65 )
{
int V_162 = - V_228 ;
struct V_248 V_249 ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
if ( V_3 -> V_42 -> V_250 )
V_162 = V_3 -> V_42 -> V_250 ( V_3 , & V_249 ) ;
if ( V_162 != 0 )
return V_162 ;
if ( F_163 ( V_65 , & V_249 , sizeof( V_249 ) ) )
return - V_137 ;
return 0 ;
}
struct V_1 * F_186 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_160 )
V_3 = V_3 -> V_28 ;
return V_3 ;
}
struct V_1 * F_187 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_160 )
return V_3 ;
return V_3 -> V_28 ;
}
long F_188 ( struct V_7 * V_7 , unsigned int V_64 , unsigned long V_65 )
{
struct V_1 * V_3 = F_6 ( V_7 ) ;
struct V_1 * V_226 ;
void T_3 * V_22 = ( void T_3 * ) V_65 ;
int V_162 ;
struct V_68 * V_69 ;
if ( F_17 ( V_3 , F_91 ( V_7 ) , L_37 ) )
return - V_228 ;
V_226 = F_186 ( V_3 ) ;
switch ( V_64 ) {
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
V_162 = F_33 ( V_3 ) ;
if ( V_162 )
return V_162 ;
if ( V_64 != V_253 ) {
F_189 ( V_3 , 0 ) ;
if ( F_97 ( V_46 ) )
return - V_234 ;
}
break;
}
switch ( V_64 ) {
case V_256 :
return F_159 ( V_3 , V_22 ) ;
case V_257 :
return F_162 ( V_226 , V_22 ) ;
case V_258 :
return F_165 ( V_226 , V_22 ) ;
case V_259 :
return V_226 != V_3 ? - V_228 : F_166 ( V_7 ) ;
case V_260 :
return F_167 ( V_7 , V_22 ) ;
case V_261 :
F_63 ( V_198 , & V_3 -> V_44 ) ;
return 0 ;
case V_262 :
F_67 ( V_198 , & V_3 -> V_44 ) ;
return 0 ;
case V_263 :
{
int V_264 = F_47 ( V_198 , & V_3 -> V_44 ) ;
return F_171 ( V_264 , ( int T_3 * ) V_22 ) ;
}
case V_265 :
if ( V_46 -> signal -> V_3 != V_3 )
return - V_67 ;
F_85 () ;
return 0 ;
case V_266 :
return F_168 ( V_3 , V_65 ) ;
case V_267 :
return F_170 ( V_3 , V_226 , V_22 ) ;
case V_66 :
return F_173 ( V_3 , V_226 , V_22 ) ;
case V_268 :
return F_178 ( V_3 , V_226 , V_22 ) ;
case V_269 :
return F_171 ( V_3 -> V_230 -> V_42 -> V_35 , ( int T_3 * ) V_22 ) ;
case V_251 :
return F_179 ( V_3 , V_22 ) ;
case V_270 :
if ( ! F_151 ( V_199 ) )
return - V_213 ;
F_75 ( V_3 ) ;
return 0 ;
case V_271 :
{
unsigned int V_45 = F_190 ( F_191 ( V_226 ) ) ;
return F_171 ( V_45 , ( unsigned int T_3 * ) V_22 ) ;
}
case V_252 :
if ( V_3 -> V_42 -> V_232 )
return V_3 -> V_42 -> V_232 ( V_3 , - 1 ) ;
return 0 ;
case V_253 :
if ( V_3 -> V_42 -> V_232 )
return V_3 -> V_42 -> V_232 ( V_3 , 0 ) ;
return 0 ;
case V_254 :
if ( ! V_65 )
return F_181 ( V_3 , 250 ) ;
return 0 ;
case V_255 :
return F_181 ( V_3 , V_65 ? V_65 * 100 : 250 ) ;
case V_272 :
return F_183 ( V_3 , V_22 ) ;
case V_242 :
case V_241 :
case V_240 :
return F_184 ( V_3 , V_64 , V_22 ) ;
case V_273 :
V_162 = F_185 ( V_3 , V_22 ) ;
if ( V_162 != - V_228 )
return V_162 ;
break;
case V_274 :
switch ( V_65 ) {
case V_275 :
case V_276 :
F_192 ( V_3 ) ;
break;
}
break;
}
if ( V_3 -> V_42 -> V_277 ) {
V_162 = ( V_3 -> V_42 -> V_277 ) ( V_3 , V_64 , V_65 ) ;
if ( V_162 != - V_278 )
return V_162 ;
}
V_69 = F_92 ( V_3 ) ;
V_162 = - V_228 ;
if ( V_69 -> V_42 -> V_277 ) {
V_162 = V_69 -> V_42 -> V_277 ( V_3 , V_7 , V_64 , V_65 ) ;
if ( V_162 == - V_278 )
V_162 = - V_67 ;
}
F_49 ( V_69 ) ;
return V_162 ;
}
static long F_193 ( struct V_7 * V_7 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_1 * V_3 = F_6 ( V_7 ) ;
struct V_68 * V_69 ;
int V_162 = - V_278 ;
if ( F_17 ( V_3 , F_91 ( V_7 ) , L_37 ) )
return - V_228 ;
if ( V_3 -> V_42 -> V_279 ) {
V_162 = ( V_3 -> V_42 -> V_279 ) ( V_3 , V_64 , V_65 ) ;
if ( V_162 != - V_278 )
return V_162 ;
}
V_69 = F_92 ( V_3 ) ;
if ( V_69 -> V_42 -> V_279 )
V_162 = V_69 -> V_42 -> V_279 ( V_3 , V_7 , V_64 , V_65 ) ;
else
V_162 = F_194 ( V_3 , V_7 , V_64 , V_65 ) ;
F_49 ( V_69 ) ;
return V_162 ;
}
static int F_195 ( const void * V_280 , struct V_7 * V_7 , unsigned V_203 )
{
if ( F_196 ( V_7 -> V_95 -> V_126 != F_90 ) )
return 0 ;
return F_6 ( V_7 ) != V_280 ? 0 : V_203 + 1 ;
}
void F_197 ( struct V_1 * V_3 )
{
#ifdef F_198
F_72 ( V_3 ) ;
#else
struct V_74 * V_281 , * V_22 ;
struct V_76 * V_79 ;
int V_124 ;
if ( ! V_3 )
return;
V_79 = V_3 -> V_79 ;
F_199 ( V_3 ) ;
F_200 ( V_3 ) ;
F_52 ( & V_78 ) ;
F_53 (session, PIDTYPE_SID, p) {
F_19 ( V_282 L_38
L_39 ,
F_201 ( V_22 ) , V_22 -> V_283 ) ;
F_202 ( V_284 , V_22 , 1 ) ;
} F_59 ( V_79 , V_87 , V_22 ) ;
F_203 (g, p) {
if ( V_22 -> signal -> V_3 == V_3 ) {
F_19 ( V_282 L_38
L_39 ,
F_201 ( V_22 ) , V_22 -> V_283 ) ;
F_202 ( V_284 , V_22 , 1 ) ;
continue;
}
F_204 ( V_22 ) ;
V_124 = F_205 ( V_22 -> V_285 , 0 , F_195 , V_3 ) ;
if ( V_124 != 0 ) {
F_19 ( V_282 L_38
L_40 ,
F_201 ( V_22 ) , V_22 -> V_283 , V_124 - 1 ) ;
F_206 ( V_284 , V_22 ) ;
}
F_207 ( V_22 ) ;
} F_208 ( V_281 , V_22 ) ;
F_60 ( & V_78 ) ;
#endif
}
static void F_209 ( struct V_106 * V_107 )
{
struct V_1 * V_3 =
F_71 ( V_107 , struct V_1 , V_173 ) ;
F_197 ( V_3 ) ;
}
void F_210 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
F_74 ( & V_3 -> V_173 ) ;
}
static int F_211 ( struct V_30 * V_4 , const void * V_286 )
{
const T_1 * V_287 = V_286 ;
return V_4 -> V_287 == * V_287 ;
}
static struct V_30 * F_212 ( struct V_1 * V_3 )
{
T_1 V_287 = F_191 ( V_3 ) ;
return F_213 ( V_288 , NULL , & V_287 , F_211 ) ;
}
void F_116 ( struct V_1 * V_3 ,
struct V_29 * V_24 , int V_148 )
{
memset ( V_3 , 0 , sizeof( struct V_1 ) ) ;
F_214 ( & V_3 -> V_175 ) ;
V_3 -> V_6 = V_20 ;
F_215 ( V_3 ) ;
V_3 -> V_79 = NULL ;
V_3 -> V_48 = NULL ;
F_216 ( & V_3 -> V_289 ) ;
F_216 ( & V_3 -> V_217 ) ;
F_216 ( & V_3 -> V_290 ) ;
F_217 ( & V_3 -> V_72 ) ;
F_217 ( & V_3 -> V_117 ) ;
F_131 ( & V_3 -> V_108 , F_70 ) ;
F_216 ( & V_3 -> V_140 ) ;
F_218 ( & V_3 -> V_47 ) ;
F_219 ( & V_3 -> V_14 ) ;
F_131 ( & V_3 -> V_173 , F_209 ) ;
V_3 -> V_24 = V_24 ;
V_3 -> V_42 = V_24 -> V_42 ;
V_3 -> V_31 = V_148 ;
F_103 ( V_24 , V_148 , V_3 -> V_16 ) ;
V_3 -> V_4 = F_212 ( V_3 ) ;
}
void F_119 ( struct V_1 * V_3 )
{
F_220 ( V_3 ) ;
}
int F_221 ( struct V_1 * V_3 , unsigned char V_211 )
{
if ( V_3 -> V_42 -> V_291 )
return V_3 -> V_42 -> V_291 ( V_3 , V_211 ) ;
return V_3 -> V_42 -> V_96 ( V_3 , & V_211 , 1 ) ;
}
static int F_222 ( struct V_29 * V_24 , T_1 V_4 ,
unsigned int V_31 , unsigned int V_23 )
{
F_223 ( & V_24 -> V_292 [ V_31 ] , & V_201 ) ;
V_24 -> V_292 [ V_31 ] . V_163 = V_24 -> V_163 ;
return F_224 ( & V_24 -> V_292 [ V_31 ] , V_4 , V_23 ) ;
}
struct V_30 * F_225 ( struct V_29 * V_24 , unsigned V_31 ,
struct V_30 * V_30 )
{
return F_226 ( V_24 , V_31 , V_30 , NULL , NULL ) ;
}
static void F_227 ( struct V_30 * V_4 )
{
F_228 ( L_41 , F_229 ( V_4 ) , V_169 ) ;
F_5 ( V_4 ) ;
}
struct V_30 * F_226 ( struct V_29 * V_24 ,
unsigned V_31 , struct V_30 * V_30 ,
void * V_293 ,
const struct V_294 * * V_295 )
{
char V_16 [ 64 ] ;
T_1 V_287 = F_27 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ;
struct V_30 * V_4 = NULL ;
int V_162 = - V_164 ;
bool V_296 = false ;
if ( V_31 >= V_24 -> V_35 ) {
F_19 ( V_143 L_42
L_43 , V_31 ) ;
return F_115 ( - V_228 ) ;
}
if ( V_24 -> type == V_25 )
F_102 ( V_24 , V_31 , V_16 ) ;
else
F_103 ( V_24 , V_31 , V_16 ) ;
if ( ! ( V_24 -> V_44 & V_297 ) ) {
V_162 = F_222 ( V_24 , V_287 , V_31 , 1 ) ;
if ( V_162 )
goto error;
V_296 = true ;
}
V_4 = F_2 ( sizeof( * V_4 ) , V_2 ) ;
if ( ! V_4 ) {
V_162 = - V_11 ;
goto error;
}
V_4 -> V_287 = V_287 ;
V_4 -> V_298 = V_288 ;
V_4 -> V_299 = V_30 ;
V_4 -> V_300 = F_227 ;
F_230 ( V_4 , L_44 , V_16 ) ;
V_4 -> V_301 = V_295 ;
F_231 ( V_4 , V_293 ) ;
V_162 = F_232 ( V_4 ) ;
if ( V_162 )
goto error;
return V_4 ;
error:
F_4 ( V_4 ) ;
if ( V_296 )
F_233 ( & V_24 -> V_292 [ V_31 ] ) ;
return F_115 ( V_162 ) ;
}
void F_234 ( struct V_29 * V_24 , unsigned V_31 )
{
F_235 ( V_288 ,
F_27 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ) ;
if ( ! ( V_24 -> V_44 & V_297 ) )
F_233 ( & V_24 -> V_292 [ V_31 ] ) ;
}
struct V_29 * F_236 ( unsigned int V_302 , struct V_303 * V_163 ,
unsigned long V_44 )
{
struct V_29 * V_24 ;
unsigned int V_292 = 1 ;
int V_216 ;
if ( ! V_302 || ( V_44 & V_147 && V_302 > 1 ) )
return F_115 ( - V_228 ) ;
V_24 = F_2 ( sizeof( struct V_29 ) , V_2 ) ;
if ( ! V_24 )
return F_115 ( - V_11 ) ;
F_214 ( & V_24 -> V_175 ) ;
V_24 -> V_6 = V_304 ;
V_24 -> V_35 = V_302 ;
V_24 -> V_163 = V_163 ;
V_24 -> V_44 = V_44 ;
if ( ! ( V_44 & V_178 ) ) {
V_24 -> V_150 = F_237 ( V_302 , sizeof( * V_24 -> V_150 ) ,
V_2 ) ;
V_24 -> V_154 = F_237 ( V_302 , sizeof( * V_24 -> V_154 ) ,
V_2 ) ;
if ( ! V_24 -> V_150 || ! V_24 -> V_154 ) {
V_216 = - V_11 ;
goto V_305;
}
}
if ( ! ( V_44 & V_297 ) ) {
V_24 -> V_168 = F_237 ( V_302 , sizeof( * V_24 -> V_168 ) ,
V_2 ) ;
if ( ! V_24 -> V_168 ) {
V_216 = - V_11 ;
goto V_305;
}
V_292 = V_302 ;
}
V_24 -> V_292 = F_237 ( V_292 , sizeof( * V_24 -> V_292 ) , V_2 ) ;
if ( ! V_24 -> V_292 ) {
V_216 = - V_11 ;
goto V_305;
}
return V_24 ;
V_305:
F_5 ( V_24 -> V_168 ) ;
F_5 ( V_24 -> V_150 ) ;
F_5 ( V_24 -> V_154 ) ;
F_5 ( V_24 ) ;
return F_115 ( V_216 ) ;
}
static void F_238 ( struct V_175 * V_175 )
{
struct V_29 * V_24 = F_71 ( V_175 , struct V_29 , V_175 ) ;
int V_124 ;
struct V_151 * V_152 ;
if ( V_24 -> V_44 & V_306 ) {
for ( V_124 = 0 ; V_124 < V_24 -> V_35 ; V_124 ++ ) {
V_152 = V_24 -> V_154 [ V_124 ] ;
if ( V_152 ) {
V_24 -> V_154 [ V_124 ] = NULL ;
F_5 ( V_152 ) ;
}
if ( ! ( V_24 -> V_44 & V_307 ) )
F_234 ( V_24 , V_124 ) ;
}
F_239 ( V_24 ) ;
if ( V_24 -> V_44 & V_297 )
F_233 ( & V_24 -> V_292 [ 0 ] ) ;
}
F_5 ( V_24 -> V_292 ) ;
F_5 ( V_24 -> V_168 ) ;
F_5 ( V_24 -> V_154 ) ;
F_5 ( V_24 -> V_150 ) ;
F_5 ( V_24 ) ;
}
void F_128 ( struct V_29 * V_24 )
{
F_132 ( & V_24 -> V_175 , F_238 ) ;
}
void F_240 ( struct V_29 * V_24 ,
const struct V_308 * V_309 )
{
V_24 -> V_42 = V_309 ;
}
void F_241 ( struct V_29 * V_310 )
{
F_128 ( V_310 ) ;
}
int F_242 ( struct V_29 * V_24 )
{
int error ;
int V_124 ;
T_1 V_4 ;
struct V_30 * V_310 ;
if ( ! V_24 -> V_33 ) {
error = F_243 ( & V_4 , V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_16 ) ;
if ( ! error ) {
V_24 -> V_33 = F_244 ( V_4 ) ;
V_24 -> V_34 = F_245 ( V_4 ) ;
}
} else {
V_4 = F_27 ( V_24 -> V_33 , V_24 -> V_34 ) ;
error = F_246 ( V_4 , V_24 -> V_35 , V_24 -> V_16 ) ;
}
if ( error < 0 )
goto V_216;
if ( V_24 -> V_44 & V_297 ) {
error = F_222 ( V_24 , V_4 , 0 , V_24 -> V_35 ) ;
if ( error )
goto V_311;
}
F_31 ( & V_41 ) ;
F_11 ( & V_24 -> V_312 , & V_312 ) ;
F_32 ( & V_41 ) ;
if ( ! ( V_24 -> V_44 & V_307 ) ) {
for ( V_124 = 0 ; V_124 < V_24 -> V_35 ; V_124 ++ ) {
V_310 = F_225 ( V_24 , V_124 , NULL ) ;
if ( F_149 ( V_310 ) ) {
error = F_150 ( V_310 ) ;
goto V_313;
}
}
}
F_247 ( V_24 ) ;
V_24 -> V_44 |= V_306 ;
return 0 ;
V_313:
for ( V_124 -- ; V_124 >= 0 ; V_124 -- )
F_234 ( V_24 , V_124 ) ;
F_31 ( & V_41 ) ;
F_15 ( & V_24 -> V_312 ) ;
F_32 ( & V_41 ) ;
V_311:
F_248 ( V_4 , V_24 -> V_35 ) ;
V_216:
return error ;
}
int F_249 ( struct V_29 * V_24 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_248 ( F_27 ( V_24 -> V_33 , V_24 -> V_34 ) ,
V_24 -> V_35 ) ;
F_31 ( & V_41 ) ;
F_15 ( & V_24 -> V_312 ) ;
F_32 ( & V_41 ) ;
return 0 ;
}
T_1 F_191 ( struct V_1 * V_3 )
{
return F_27 ( V_3 -> V_24 -> V_33 , V_3 -> V_24 -> V_34 ) + V_3 -> V_31 ;
}
void F_81 ( struct V_74 * V_22 )
{
unsigned long V_44 ;
struct V_1 * V_3 ;
F_34 ( & V_22 -> V_80 -> V_81 , V_44 ) ;
V_3 = V_22 -> signal -> V_3 ;
V_22 -> signal -> V_3 = NULL ;
F_36 ( & V_22 -> V_80 -> V_81 , V_44 ) ;
F_65 ( V_3 ) ;
}
static void F_152 ( struct V_74 * V_112 , struct V_1 * V_3 )
{
if ( V_3 ) {
unsigned long V_44 ;
F_34 ( & V_3 -> V_47 , V_44 ) ;
F_57 ( V_3 -> V_79 ) ;
F_57 ( V_3 -> V_48 ) ;
V_3 -> V_48 = F_58 ( F_35 ( V_112 ) ) ;
F_36 ( & V_3 -> V_47 , V_44 ) ;
V_3 -> V_79 = F_58 ( F_84 ( V_112 ) ) ;
if ( V_112 -> signal -> V_3 ) {
F_19 ( V_109 L_45 ) ;
F_65 ( V_112 -> signal -> V_3 ) ;
}
}
F_57 ( V_112 -> signal -> V_86 ) ;
V_112 -> signal -> V_3 = F_250 ( V_3 ) ;
V_112 -> signal -> V_86 = NULL ;
}
static void F_169 ( struct V_74 * V_112 , struct V_1 * V_3 )
{
F_54 ( & V_112 -> V_80 -> V_81 ) ;
F_152 ( V_112 , V_3 ) ;
F_55 ( & V_112 -> V_80 -> V_81 ) ;
}
struct V_1 * F_77 ( void )
{
struct V_1 * V_3 ;
unsigned long V_44 ;
F_34 ( & V_46 -> V_80 -> V_81 , V_44 ) ;
V_3 = F_250 ( V_46 -> signal -> V_3 ) ;
F_36 ( & V_46 -> V_80 -> V_81 , V_44 ) ;
return V_3 ;
}
void F_251 ( struct V_314 * V_315 )
{
* V_315 = V_201 ;
}
void T_8 F_252 ( void )
{
T_9 * V_316 ;
F_253 () ;
V_316 = V_317 ;
while ( V_316 < V_318 ) {
(* V_316)() ;
V_316 ++ ;
}
}
static char * F_254 ( struct V_30 * V_4 , T_10 * V_319 )
{
if ( ! V_319 )
return NULL ;
if ( V_4 -> V_287 == F_27 ( V_184 , 0 ) ||
V_4 -> V_287 == F_27 ( V_184 , 2 ) )
* V_319 = 0666 ;
return NULL ;
}
static int T_8 F_255 ( void )
{
V_288 = F_256 ( V_320 , L_17 ) ;
if ( F_149 ( V_288 ) )
return F_150 ( V_288 ) ;
V_288 -> V_321 = F_254 ;
return 0 ;
}
static T_2 F_257 ( struct V_30 * V_4 ,
struct V_322 * V_323 , char * V_15 )
{
struct V_324 * V_325 [ 16 ] ;
int V_124 = 0 ;
struct V_324 * V_326 ;
T_2 V_23 = 0 ;
F_258 () ;
F_259 (c) {
if ( ! V_326 -> V_30 )
continue;
if ( ! V_326 -> V_96 )
continue;
if ( ( V_326 -> V_44 & V_327 ) == 0 )
continue;
V_325 [ V_124 ++ ] = V_326 ;
if ( V_124 >= F_260 ( V_325 ) )
break;
}
while ( V_124 -- )
V_23 += sprintf ( V_15 + V_23 , L_46 ,
V_325 [ V_124 ] -> V_16 , V_325 [ V_124 ] -> V_31 , V_124 ? ' ' : '\n' ) ;
F_261 () ;
return V_23 ;
}
void F_262 ( void )
{
if ( V_328 )
F_263 ( & V_328 -> V_329 , NULL , L_47 ) ;
}
int T_8 F_264 ( void )
{
F_223 ( & V_330 , & V_201 ) ;
if ( F_224 ( & V_330 , F_27 ( V_184 , 0 ) , 1 ) ||
F_246 ( F_27 ( V_184 , 0 ) , 1 , L_48 ) < 0 )
F_265 ( L_49 ) ;
F_266 ( V_288 , NULL , F_27 ( V_184 , 0 ) , NULL , L_17 ) ;
F_223 ( & V_331 , & V_332 ) ;
if ( F_224 ( & V_331 , F_27 ( V_184 , 1 ) , 1 ) ||
F_246 ( F_27 ( V_184 , 1 ) , 1 , L_50 ) < 0 )
F_265 ( L_51 ) ;
V_328 = F_266 ( V_288 , NULL , F_27 ( V_184 , 1 ) , NULL ,
L_52 ) ;
if ( F_149 ( V_328 ) )
V_328 = NULL ;
else
F_112 ( F_267 ( V_328 , & V_333 ) < 0 ) ;
#ifdef F_145
F_268 ( & V_332 ) ;
#endif
return 0 ;
}
