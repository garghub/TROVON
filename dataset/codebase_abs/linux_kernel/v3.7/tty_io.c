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
F_6 ( V_3 ) ;
V_3 -> V_6 = 0xDEADDEAD ;
F_5 ( V_3 ) ;
}
static inline struct V_1 * F_7 ( struct V_7 * V_7 )
{
return ( (struct V_8 * ) V_7 -> V_9 ) -> V_3 ;
}
int F_8 ( struct V_7 * V_7 )
{
struct V_8 * V_10 ;
V_10 = F_9 ( sizeof( * V_10 ) , V_2 ) ;
if ( ! V_10 )
return - V_11 ;
V_7 -> V_9 = V_10 ;
return 0 ;
}
void F_10 ( struct V_1 * V_3 , struct V_7 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_9 ;
V_10 -> V_3 = V_3 ;
V_10 -> V_7 = V_7 ;
F_11 ( & V_12 ) ;
F_12 ( & V_10 -> V_13 , & V_3 -> V_14 ) ;
F_13 ( & V_12 ) ;
}
void F_14 ( struct V_7 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_9 ;
V_7 -> V_9 = NULL ;
F_5 ( V_10 ) ;
}
void F_15 ( struct V_7 * V_7 )
{
struct V_8 * V_10 = V_7 -> V_9 ;
F_11 ( & V_12 ) ;
F_16 ( & V_10 -> V_13 ) ;
F_13 ( & V_12 ) ;
F_14 ( V_7 ) ;
}
char * F_17 ( struct V_1 * V_3 , char * V_15 )
{
if ( ! V_3 )
strcpy ( V_15 , L_1 ) ;
else
strcpy ( V_15 , V_3 -> V_16 ) ;
return V_15 ;
}
int F_18 ( struct V_1 * V_3 , struct V_17 * V_17 ,
const char * V_18 )
{
#ifdef F_19
if ( ! V_3 ) {
F_20 ( V_19
L_2 ,
F_21 ( V_17 ) , F_22 ( V_17 ) , V_18 ) ;
return 1 ;
}
if ( V_3 -> V_6 != V_20 ) {
F_20 ( V_19
L_3 ,
F_21 ( V_17 ) , F_22 ( V_17 ) , V_18 ) ;
return 1 ;
}
#endif
return 0 ;
}
static int F_23 ( struct V_1 * V_3 , const char * V_18 )
{
#ifdef F_24
struct V_21 * V_22 ;
int V_23 = 0 ;
F_11 ( & V_12 ) ;
F_25 (p, &tty->tty_files) {
V_23 ++ ;
}
F_13 ( & V_12 ) ;
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_27 &&
V_3 -> V_28 && V_3 -> V_28 -> V_23 )
V_23 ++ ;
if ( V_3 -> V_23 != V_23 ) {
F_20 ( V_19 L_4
L_5 ,
V_3 -> V_16 , V_3 -> V_23 , V_23 , V_18 ) ;
return V_23 ;
}
#endif
return 0 ;
}
static struct V_29 * F_26 ( T_1 V_30 , int * V_31 )
{
struct V_29 * V_22 ;
F_27 (p, &tty_drivers, tty_drivers) {
T_1 V_32 = F_28 ( V_22 -> V_33 , V_22 -> V_34 ) ;
if ( V_30 < V_32 || V_30 >= V_32 + V_22 -> V_35 )
continue;
* V_31 = V_30 - V_32 ;
return F_29 ( V_22 ) ;
}
return NULL ;
}
struct V_29 * F_30 ( char * V_16 , int * line )
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
V_37 = F_31 ( V_39 , & V_39 , 10 ) ;
F_32 ( & V_41 ) ;
F_27 (p, &tty_drivers, tty_drivers) {
if ( strncmp ( V_16 , V_22 -> V_16 , V_38 ) != 0 )
continue;
V_40 = V_39 ;
if ( * V_40 == ',' )
V_40 ++ ;
if ( * V_40 == '\0' )
V_40 = NULL ;
if ( V_37 >= 0 && V_37 < V_22 -> V_35 && V_22 -> V_42 &&
V_22 -> V_42 -> V_43 && ! V_22 -> V_42 -> V_43 ( V_22 , V_37 , V_40 ) ) {
V_36 = F_29 ( V_22 ) ;
* line = V_37 ;
break;
}
}
F_33 ( & V_41 ) ;
return V_36 ;
}
int F_34 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
int V_45 = 0 ;
if ( V_46 -> signal -> V_3 != V_3 )
return 0 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
if ( ! V_3 -> V_48 ) {
F_20 ( V_19 L_6 ) ;
goto V_49;
}
if ( F_36 ( V_46 ) == V_3 -> V_48 )
goto V_49;
F_37 ( & V_3 -> V_47 , V_44 ) ;
if ( F_38 ( V_50 ) )
goto V_51;
if ( F_39 () ) {
V_45 = - V_52 ;
goto V_51;
}
F_40 ( F_36 ( V_46 ) , V_50 , 1 ) ;
F_41 ( V_53 ) ;
V_45 = - V_54 ;
V_51:
return V_45 ;
V_49:
F_37 ( & V_3 -> V_47 , V_44 ) ;
return V_45 ;
}
static T_2 F_42 ( struct V_7 * V_7 , char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
return 0 ;
}
static T_2 F_43 ( struct V_7 * V_7 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
return - V_52 ;
}
static unsigned int F_44 ( struct V_7 * V_56 , T_6 * V_57 )
{
return V_58 | V_59 | V_60 | V_61 | V_62 | V_63 ;
}
static long F_45 ( struct V_7 * V_7 , unsigned int V_64 ,
unsigned long V_65 )
{
return V_64 == V_66 ? - V_67 : - V_52 ;
}
static long F_46 ( struct V_7 * V_7 ,
unsigned int V_64 , unsigned long V_65 )
{
return V_64 == V_66 ? - V_67 : - V_52 ;
}
void F_47 ( struct V_1 * V_3 )
{
struct V_68 * V_69 ;
if ( F_48 ( V_70 , & V_3 -> V_44 ) ) {
V_69 = F_49 ( V_3 ) ;
if ( V_69 ) {
if ( V_69 -> V_42 -> V_71 )
V_69 -> V_42 -> V_71 ( V_3 ) ;
F_50 ( V_69 ) ;
}
}
F_51 ( & V_3 -> V_72 , V_59 ) ;
}
void F_52 ( struct V_1 * V_3 )
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
F_11 ( & V_79 ) ;
if ( V_80 && F_7 ( V_80 ) == V_3 ) {
V_74 = V_80 ;
V_80 = NULL ;
}
F_13 ( & V_79 ) ;
F_53 ( V_3 ) ;
F_54 ( V_81 , & V_3 -> V_44 ) ;
F_23 ( V_3 , L_7 ) ;
F_11 ( & V_12 ) ;
F_27 (priv, &tty->tty_files, list) {
V_56 = V_10 -> V_7 ;
if ( V_56 -> V_82 -> V_83 == V_84 )
V_73 = V_56 ;
if ( V_56 -> V_82 -> V_83 != V_85 )
continue;
V_76 ++ ;
F_55 ( - 1 , V_56 , 0 ) ;
V_56 -> V_82 = & V_86 ;
}
F_13 ( & V_12 ) ;
F_56 ( V_3 ) ;
F_57 ( & V_87 ) ;
if ( V_3 -> V_88 ) {
F_58 (tty->session, PIDTYPE_SID, p) {
F_59 ( & V_22 -> V_89 -> V_90 ) ;
if ( V_22 -> signal -> V_3 == V_3 ) {
V_22 -> signal -> V_3 = NULL ;
V_78 ++ ;
}
if ( ! V_22 -> signal -> V_91 ) {
F_60 ( & V_22 -> V_89 -> V_90 ) ;
continue;
}
F_61 ( V_92 , V_93 , V_22 ) ;
F_61 ( V_94 , V_93 , V_22 ) ;
F_62 ( V_22 -> signal -> V_95 ) ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_48 )
V_22 -> signal -> V_95 = F_63 ( V_3 -> V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
F_60 ( & V_22 -> V_89 -> V_90 ) ;
} F_64 ( V_3 -> V_88 , V_96 , V_22 ) ;
}
F_65 ( & V_87 ) ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
F_66 ( V_97 , & V_3 -> V_44 ) ;
F_66 ( V_98 , & V_3 -> V_44 ) ;
F_66 ( V_70 , & V_3 -> V_44 ) ;
F_62 ( V_3 -> V_88 ) ;
F_62 ( V_3 -> V_48 ) ;
V_3 -> V_88 = NULL ;
V_3 -> V_48 = NULL ;
V_3 -> V_99 = 0 ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
while ( V_78 -- )
F_67 ( V_3 ) ;
if ( V_73 ) {
if ( V_3 -> V_42 -> V_100 )
for ( V_77 = 0 ; V_77 < V_76 ; V_77 ++ )
V_3 -> V_42 -> V_100 ( V_3 , V_73 ) ;
} else if ( V_3 -> V_42 -> V_101 )
( V_3 -> V_42 -> V_101 ) ( V_3 ) ;
F_54 ( V_102 , & V_3 -> V_44 ) ;
F_66 ( V_81 , & V_3 -> V_44 ) ;
F_68 ( V_3 ) ;
F_69 ( V_3 ) ;
if ( V_74 )
F_70 ( V_74 ) ;
}
static void F_71 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_72 ( V_104 , struct V_1 , V_105 ) ;
F_52 ( V_3 ) ;
}
void F_73 ( struct V_1 * V_3 )
{
#ifdef F_74
char V_15 [ 64 ] ;
F_20 ( V_106 L_8 , F_17 ( V_3 , V_15 ) ) ;
#endif
F_75 ( & V_3 -> V_105 ) ;
}
void F_76 ( struct V_1 * V_3 )
{
#ifdef F_74
char V_15 [ 64 ] ;
F_20 ( V_106 L_9 , F_17 ( V_3 , V_15 ) ) ;
#endif
F_52 ( V_3 ) ;
}
void F_77 ( void )
{
struct V_1 * V_3 ;
V_3 = F_78 () ;
if ( V_3 ) {
F_76 ( V_3 ) ;
F_67 ( V_3 ) ;
}
}
int F_79 ( struct V_7 * V_56 )
{
return ( V_56 -> V_82 == & V_86 ) ;
}
static void F_80 ( struct V_107 * V_88 )
{
struct V_75 * V_22 ;
F_58 (session, PIDTYPE_SID, p) {
F_81 ( V_22 ) ;
} F_64 ( V_88 , V_96 , V_22 ) ;
}
void F_82 ( int V_108 )
{
struct V_1 * V_3 ;
if ( ! V_46 -> signal -> V_91 )
return;
V_3 = F_78 () ;
if ( V_3 ) {
struct V_107 * V_109 = F_63 ( V_3 -> V_48 ) ;
if ( V_108 ) {
if ( V_3 -> V_24 -> type != V_25 )
F_76 ( V_3 ) ;
}
F_67 ( V_3 ) ;
if ( V_109 ) {
F_40 ( V_109 , V_92 , V_108 ) ;
if ( ! V_108 )
F_40 ( V_109 , V_94 , V_108 ) ;
F_62 ( V_109 ) ;
}
} else if ( V_108 ) {
struct V_107 * V_110 ;
F_59 ( & V_46 -> V_89 -> V_90 ) ;
V_110 = V_46 -> signal -> V_95 ;
V_46 -> signal -> V_95 = NULL ;
F_60 ( & V_46 -> V_89 -> V_90 ) ;
if ( V_110 ) {
F_40 ( V_110 , V_92 , V_108 ) ;
F_40 ( V_110 , V_94 , V_108 ) ;
F_62 ( V_110 ) ;
}
return;
}
F_59 ( & V_46 -> V_89 -> V_90 ) ;
F_62 ( V_46 -> signal -> V_95 ) ;
V_46 -> signal -> V_95 = NULL ;
F_60 ( & V_46 -> V_89 -> V_90 ) ;
V_3 = F_78 () ;
if ( V_3 ) {
unsigned long V_44 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
F_62 ( V_3 -> V_88 ) ;
F_62 ( V_3 -> V_48 ) ;
V_3 -> V_88 = NULL ;
V_3 -> V_48 = NULL ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
F_67 ( V_3 ) ;
} else {
#ifdef F_74
F_20 ( V_106 L_10
L_11 , V_3 ) ;
#endif
}
F_57 ( & V_87 ) ;
F_80 ( F_83 ( V_46 ) ) ;
F_65 ( & V_87 ) ;
}
void F_84 ( void )
{
struct V_75 * V_111 = V_46 ;
F_82 ( 0 ) ;
F_81 ( V_111 ) ;
}
void F_85 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_112 ) {
F_37 ( & V_3 -> V_47 , V_44 ) ;
return;
}
V_3 -> V_112 = 1 ;
if ( V_3 -> V_28 && V_3 -> V_28 -> V_113 ) {
V_3 -> V_99 &= ~ V_114 ;
V_3 -> V_99 |= V_115 ;
F_51 ( & V_3 -> V_28 -> V_116 , V_58 ) ;
}
F_37 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_42 -> V_117 )
( V_3 -> V_42 -> V_117 ) ( V_3 ) ;
}
void F_86 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
if ( ! V_3 -> V_112 || V_3 -> V_118 ) {
F_37 ( & V_3 -> V_47 , V_44 ) ;
return;
}
V_3 -> V_112 = 0 ;
if ( V_3 -> V_28 && V_3 -> V_28 -> V_113 ) {
V_3 -> V_99 &= ~ V_115 ;
V_3 -> V_99 |= V_114 ;
F_51 ( & V_3 -> V_28 -> V_116 , V_58 ) ;
}
F_37 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_42 -> V_119 )
( V_3 -> V_42 -> V_119 ) ( V_3 ) ;
F_47 ( V_3 ) ;
}
static T_2 F_87 ( struct V_7 * V_7 , char T_3 * V_15 , T_4 V_23 ,
T_5 * V_55 )
{
int V_120 ;
struct V_17 * V_17 = V_7 -> V_121 . V_122 -> V_123 ;
struct V_1 * V_3 = F_7 ( V_7 ) ;
struct V_68 * V_69 ;
if ( F_18 ( V_3 , V_17 , L_12 ) )
return - V_52 ;
if ( ! V_3 || ( F_48 ( V_124 , & V_3 -> V_44 ) ) )
return - V_52 ;
V_69 = F_88 ( V_3 ) ;
if ( V_69 -> V_42 -> V_125 )
V_120 = ( V_69 -> V_42 -> V_125 ) ( V_3 , V_7 , V_15 , V_23 ) ;
else
V_120 = - V_52 ;
F_50 ( V_69 ) ;
if ( V_120 > 0 )
V_17 -> V_126 = F_89 ( V_17 -> V_127 ) ;
return V_120 ;
}
void F_90 ( struct V_1 * V_3 )
__releases( &tty->atomic_write_lock
int F_91 ( struct V_1 * V_3 , int V_128 )
__acquires( &tty->atomic_write_lock
static inline T_2 F_92 (
T_2 (* V_83)( struct V_1 * , struct V_7 * , const unsigned char * , T_4 ) ,
struct V_1 * V_3 ,
struct V_7 * V_7 ,
const char T_3 * V_15 ,
T_4 V_23 )
{
T_2 V_45 , V_129 = 0 ;
unsigned int V_130 ;
V_45 = F_91 ( V_3 , V_7 -> V_131 & V_132 ) ;
if ( V_45 < 0 )
return V_45 ;
V_130 = 2048 ;
if ( F_48 ( V_133 , & V_3 -> V_44 ) )
V_130 = 65536 ;
if ( V_23 < V_130 )
V_130 = V_23 ;
if ( V_3 -> V_134 < V_130 ) {
unsigned char * V_135 ;
if ( V_130 < 1024 )
V_130 = 1024 ;
V_135 = F_9 ( V_130 , V_2 ) ;
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
if ( F_93 ( V_3 -> V_5 , V_15 , V_136 ) )
break;
V_45 = V_83 ( V_3 , V_7 , V_3 -> V_5 , V_136 ) ;
if ( V_45 <= 0 )
break;
V_129 += V_45 ;
V_15 += V_45 ;
V_23 -= V_45 ;
if ( ! V_23 )
break;
V_45 = - V_54 ;
if ( F_94 ( V_46 ) )
break;
F_95 () ;
}
if ( V_129 ) {
struct V_17 * V_17 = V_7 -> V_121 . V_122 -> V_123 ;
V_17 -> V_138 = F_89 ( V_17 -> V_127 ) ;
V_45 = V_129 ;
}
V_51:
F_90 ( V_3 ) ;
return V_45 ;
}
void F_96 ( struct V_1 * V_3 , char * V_139 )
{
if ( V_3 ) {
F_32 ( & V_3 -> V_140 ) ;
F_53 ( V_3 ) ;
if ( V_3 -> V_42 -> V_83 && ! F_48 ( V_141 , & V_3 -> V_44 ) ) {
F_69 ( V_3 ) ;
V_3 -> V_42 -> V_83 ( V_3 , V_139 , strlen ( V_139 ) ) ;
} else
F_69 ( V_3 ) ;
F_90 ( V_3 ) ;
}
return;
}
static T_2 V_85 ( struct V_7 * V_7 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_17 * V_17 = V_7 -> V_121 . V_122 -> V_123 ;
struct V_1 * V_3 = F_7 ( V_7 ) ;
struct V_68 * V_69 ;
T_2 V_45 ;
if ( F_18 ( V_3 , V_17 , L_13 ) )
return - V_52 ;
if ( ! V_3 || ! V_3 -> V_42 -> V_83 ||
( F_48 ( V_124 , & V_3 -> V_44 ) ) )
return - V_52 ;
if ( V_3 -> V_42 -> V_142 == NULL )
F_20 ( V_143 L_14 ,
V_3 -> V_24 -> V_16 ) ;
V_69 = F_88 ( V_3 ) ;
if ( ! V_69 -> V_42 -> V_83 )
V_45 = - V_52 ;
else
V_45 = F_92 ( V_69 -> V_42 -> V_83 , V_3 , V_7 , V_15 , V_23 ) ;
F_50 ( V_69 ) ;
return V_45 ;
}
T_2 V_84 ( struct V_7 * V_7 , const char T_3 * V_15 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_7 * V_22 = NULL ;
F_11 ( & V_79 ) ;
if ( V_80 )
V_22 = F_97 ( V_80 ) ;
F_13 ( & V_79 ) ;
if ( V_22 ) {
T_2 V_36 ;
V_36 = F_98 ( V_22 , V_15 , V_23 , & V_22 -> V_144 ) ;
F_70 ( V_22 ) ;
return V_36 ;
}
return V_85 ( V_7 , V_15 , V_23 , V_55 ) ;
}
static void F_99 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
int V_120 = V_31 + V_24 -> V_145 ;
sprintf ( V_22 , L_15 ,
V_24 -> V_26 == V_27 ? L_16 : V_24 -> V_16 ,
V_146 [ V_120 >> 4 & 0xf ] , V_120 & 0xf ) ;
}
static void F_100 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
if ( V_24 -> V_44 & V_147 )
strcpy ( V_22 , V_24 -> V_16 ) ;
else
sprintf ( V_22 , L_17 , V_24 -> V_16 , V_31 + V_24 -> V_145 ) ;
}
static struct V_1 * F_101 ( struct V_29 * V_24 ,
struct V_17 * V_17 , int V_148 )
{
if ( V_24 -> V_42 -> V_149 )
return V_24 -> V_42 -> V_149 ( V_24 , V_17 , V_148 ) ;
return V_24 -> V_150 [ V_148 ] ;
}
int F_102 ( struct V_1 * V_3 )
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
V_3 -> V_154 . V_156 = F_103 ( & V_3 -> V_154 ) ;
V_3 -> V_154 . V_157 = F_104 ( & V_3 -> V_154 ) ;
return 0 ;
}
int F_105 ( struct V_29 * V_24 , struct V_1 * V_3 )
{
int V_45 = F_102 ( V_3 ) ;
if ( V_45 )
return V_45 ;
F_29 ( V_24 ) ;
V_3 -> V_23 ++ ;
V_24 -> V_150 [ V_3 -> V_31 ] = V_3 ;
return 0 ;
}
static int F_106 ( struct V_29 * V_24 ,
struct V_1 * V_3 )
{
return V_24 -> V_42 -> V_158 ? V_24 -> V_42 -> V_158 ( V_24 , V_3 ) :
F_105 ( V_24 , V_3 ) ;
}
void F_107 ( struct V_29 * V_24 , struct V_1 * V_3 )
{
if ( V_24 -> V_42 -> remove )
V_24 -> V_42 -> remove ( V_24 , V_3 ) ;
else
V_24 -> V_150 [ V_3 -> V_31 ] = NULL ;
}
static int F_108 ( struct V_1 * V_3 )
{
struct V_29 * V_24 = V_3 -> V_24 ;
if ( F_48 ( V_141 , & V_3 -> V_44 ) ||
F_48 ( V_81 , & V_3 -> V_44 ) ||
F_48 ( V_159 , & V_3 -> V_44 ) )
return - V_52 ;
if ( V_24 -> type == V_25 &&
V_24 -> V_26 == V_160 ) {
if ( V_3 -> V_23 )
return - V_52 ;
V_3 -> V_28 -> V_23 ++ ;
}
V_3 -> V_23 ++ ;
F_32 ( & V_3 -> V_161 ) ;
F_109 ( ! F_48 ( V_162 , & V_3 -> V_44 ) ) ;
F_33 ( & V_3 -> V_161 ) ;
return 0 ;
}
struct V_1 * F_110 ( struct V_29 * V_24 , int V_148 )
{
struct V_1 * V_3 ;
int V_163 ;
if ( ! F_111 ( V_24 -> V_164 ) )
return F_112 ( - V_165 ) ;
V_3 = F_1 () ;
if ( ! V_3 ) {
V_163 = - V_11 ;
goto V_166;
}
F_113 ( V_3 , V_24 , V_148 ) ;
F_53 ( V_3 ) ;
V_163 = F_106 ( V_24 , V_3 ) ;
if ( V_163 < 0 )
goto V_167;
if ( ! V_3 -> V_168 )
V_3 -> V_168 = V_24 -> V_169 [ V_148 ] ;
F_114 ( ! V_3 -> V_168 ,
L_18 ,
V_170 , V_3 -> V_24 -> V_16 ) ;
V_163 = F_115 ( V_3 , V_3 -> V_28 ) ;
if ( V_163 )
goto V_171;
return V_3 ;
V_167:
F_69 ( V_3 ) ;
F_116 ( V_3 ) ;
F_3 ( V_3 ) ;
V_166:
F_117 ( V_24 -> V_164 ) ;
return F_112 ( V_163 ) ;
V_171:
F_69 ( V_3 ) ;
F_118 ( V_172 L_19
L_20 , V_148 ) ;
F_119 ( V_3 , V_148 ) ;
return F_112 ( V_163 ) ;
}
void F_120 ( struct V_1 * V_3 )
{
struct V_151 * V_152 ;
int V_148 = V_3 -> V_31 ;
if ( V_3 -> V_24 -> V_44 & V_153 )
return;
V_152 = V_3 -> V_24 -> V_154 [ V_148 ] ;
if ( V_152 == NULL ) {
V_152 = F_9 ( sizeof( struct V_151 ) , V_2 ) ;
if ( V_152 == NULL ) {
F_121 ( L_21 ) ;
return;
}
V_3 -> V_24 -> V_154 [ V_148 ] = V_152 ;
}
* V_152 = V_3 -> V_154 ;
}
static void F_122 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_72 ( V_104 , struct V_1 , V_105 ) ;
struct V_29 * V_24 = V_3 -> V_24 ;
if ( V_3 -> V_42 -> V_173 )
V_3 -> V_42 -> V_173 ( V_3 ) ;
V_3 -> V_6 = 0 ;
F_123 ( V_24 ) ;
F_117 ( V_24 -> V_164 ) ;
F_11 ( & V_12 ) ;
F_124 ( & V_3 -> V_14 ) ;
F_13 ( & V_12 ) ;
F_62 ( V_3 -> V_48 ) ;
F_62 ( V_3 -> V_88 ) ;
F_3 ( V_3 ) ;
}
static void F_125 ( struct V_174 * V_174 )
{
struct V_1 * V_3 = F_72 ( V_174 , struct V_1 , V_174 ) ;
F_126 ( & V_3 -> V_105 , F_122 ) ;
F_75 ( & V_3 -> V_105 ) ;
}
void F_67 ( struct V_1 * V_3 )
{
if ( V_3 )
F_127 ( & V_3 -> V_174 , F_125 ) ;
}
static void F_119 ( struct V_1 * V_3 , int V_148 )
{
F_109 ( V_3 -> V_31 != V_148 ) ;
F_109 ( ! F_128 ( & V_41 ) ) ;
if ( V_3 -> V_42 -> V_175 )
V_3 -> V_42 -> V_175 ( V_3 ) ;
F_120 ( V_3 ) ;
F_107 ( V_3 -> V_24 , V_3 ) ;
if ( V_3 -> V_28 )
F_67 ( V_3 -> V_28 ) ;
F_67 ( V_3 ) ;
}
static int F_129 ( struct V_1 * V_3 , struct V_1 * V_176 ,
int V_148 )
{
#ifdef F_19
if ( V_148 < 0 || V_148 >= V_3 -> V_24 -> V_35 ) {
F_20 ( V_106 L_22 ,
V_170 , V_3 -> V_16 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_44 & V_177 )
return 0 ;
if ( V_3 != V_3 -> V_24 -> V_150 [ V_148 ] ) {
F_20 ( V_106 L_23 ,
V_170 , V_148 , V_3 -> V_16 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_178 ) {
if ( V_176 != V_3 -> V_24 -> V_178 -> V_150 [ V_148 ] ) {
F_20 ( V_106 L_24 ,
V_170 , V_148 , V_3 -> V_16 ) ;
return - 1 ;
}
if ( V_176 -> V_28 != V_3 ) {
F_20 ( V_106 L_25 , V_170 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_130 ( struct V_17 * V_17 , struct V_7 * V_56 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
struct V_1 * V_176 ;
int V_179 , V_180 , V_181 , V_182 ;
int V_183 ;
int V_148 ;
char V_15 [ 64 ] ;
if ( F_18 ( V_3 , V_17 , V_170 ) )
return 0 ;
F_53 ( V_3 ) ;
F_23 ( V_3 , V_170 ) ;
F_55 ( - 1 , V_56 , 0 ) ;
V_148 = V_3 -> V_31 ;
V_179 = ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_160 ) ;
V_183 = ( V_3 -> V_24 -> V_44 & V_177 ) != 0 ;
V_176 = V_3 -> V_28 ;
if ( F_129 ( V_3 , V_176 , V_148 ) ) {
F_69 ( V_3 ) ;
return 0 ;
}
#ifdef F_74
F_20 ( V_106 L_26 , V_170 ,
F_17 ( V_3 , V_15 ) , V_3 -> V_23 ) ;
#endif
if ( V_3 -> V_42 -> V_100 )
V_3 -> V_42 -> V_100 ( V_3 , V_56 ) ;
F_69 ( V_3 ) ;
while ( 1 ) {
F_32 ( & V_41 ) ;
F_131 ( V_3 , V_176 ) ;
V_180 = V_3 -> V_23 <= 1 ;
V_181 = V_176 &&
( V_176 -> V_23 <= ( V_179 ? 1 : 0 ) ) ;
V_182 = 0 ;
if ( V_180 ) {
if ( F_132 ( & V_3 -> V_116 ) ) {
F_133 ( & V_3 -> V_116 , V_58 ) ;
V_182 ++ ;
}
if ( F_132 ( & V_3 -> V_72 ) ) {
F_133 ( & V_3 -> V_72 , V_59 ) ;
V_182 ++ ;
}
}
if ( V_181 ) {
if ( F_132 ( & V_176 -> V_116 ) ) {
F_133 ( & V_176 -> V_116 , V_58 ) ;
V_182 ++ ;
}
if ( F_132 ( & V_176 -> V_72 ) ) {
F_133 ( & V_176 -> V_72 , V_59 ) ;
V_182 ++ ;
}
}
if ( ! V_182 )
break;
F_20 ( V_19 L_27 ,
V_170 , F_17 ( V_3 , V_15 ) ) ;
F_134 ( V_3 , V_176 ) ;
F_33 ( & V_41 ) ;
F_135 () ;
}
if ( V_179 ) {
if ( -- V_176 -> V_23 < 0 ) {
F_20 ( V_19 L_28 ,
V_170 , V_176 -> V_23 , F_17 ( V_176 , V_15 ) ) ;
V_176 -> V_23 = 0 ;
}
}
if ( -- V_3 -> V_23 < 0 ) {
F_20 ( V_19 L_29 ,
V_170 , V_3 -> V_23 , F_17 ( V_3 , V_15 ) ) ;
V_3 -> V_23 = 0 ;
}
F_15 ( V_56 ) ;
if ( V_180 )
F_54 ( V_141 , & V_3 -> V_44 ) ;
if ( V_181 )
F_54 ( V_141 , & V_176 -> V_44 ) ;
if ( V_180 || V_181 ) {
F_57 ( & V_87 ) ;
F_80 ( V_3 -> V_88 ) ;
if ( V_176 )
F_80 ( V_176 -> V_88 ) ;
F_65 ( & V_87 ) ;
}
F_33 ( & V_41 ) ;
F_134 ( V_3 , V_176 ) ;
if ( ! V_180 || ( V_176 && ! V_181 ) )
return 0 ;
#ifdef F_74
F_20 ( V_106 L_30 , V_170 ) ;
#endif
F_136 ( V_3 , V_176 ) ;
F_32 ( & V_41 ) ;
F_119 ( V_3 , V_148 ) ;
F_33 ( & V_41 ) ;
if ( V_183 )
F_137 ( V_17 , V_148 ) ;
return 0 ;
}
static struct V_1 * F_138 ( T_1 V_30 , struct V_7 * V_56 )
{
struct V_1 * V_3 ;
if ( V_30 != F_28 ( V_184 , 0 ) )
return NULL ;
V_3 = F_78 () ;
if ( ! V_3 )
return F_112 ( - V_185 ) ;
V_56 -> V_131 |= V_186 ;
F_67 ( V_3 ) ;
return V_3 ;
}
static struct V_29 * F_139 ( T_1 V_30 , struct V_7 * V_56 ,
int * V_187 , int * V_31 )
{
struct V_29 * V_24 ;
switch ( V_30 ) {
#ifdef F_140
case F_28 ( V_188 , 0 ) : {
extern struct V_29 * V_189 ;
V_24 = F_29 ( V_189 ) ;
* V_31 = V_190 ;
* V_187 = 1 ;
break;
}
#endif
case F_28 ( V_184 , 1 ) : {
struct V_29 * V_189 = F_141 ( V_31 ) ;
if ( V_189 ) {
V_24 = F_29 ( V_189 ) ;
if ( V_24 ) {
V_56 -> V_131 |= V_186 ;
* V_187 = 1 ;
break;
}
}
return F_112 ( - V_165 ) ;
}
default:
V_24 = F_26 ( V_30 , V_31 ) ;
if ( ! V_24 )
return F_112 ( - V_165 ) ;
break;
}
return V_24 ;
}
static int F_142 ( struct V_17 * V_17 , struct V_7 * V_56 )
{
struct V_1 * V_3 ;
int V_187 , V_163 ;
struct V_29 * V_24 = NULL ;
int V_31 ;
T_1 V_30 = V_17 -> V_191 ;
unsigned V_192 = V_56 -> V_131 ;
F_143 ( V_17 , V_56 ) ;
V_193:
V_163 = F_8 ( V_56 ) ;
if ( V_163 )
return - V_11 ;
V_187 = V_56 -> V_131 & V_194 ;
V_31 = - 1 ;
V_163 = 0 ;
F_32 ( & V_41 ) ;
V_3 = F_138 ( V_30 , V_56 ) ;
if ( F_144 ( V_3 ) ) {
V_163 = F_145 ( V_3 ) ;
goto V_195;
} else if ( ! V_3 ) {
V_24 = F_139 ( V_30 , V_56 , & V_187 , & V_31 ) ;
if ( F_144 ( V_24 ) ) {
V_163 = F_145 ( V_24 ) ;
goto V_195;
}
V_3 = F_101 ( V_24 , V_17 , V_31 ) ;
if ( F_144 ( V_3 ) ) {
V_163 = F_145 ( V_3 ) ;
goto V_195;
}
}
if ( V_3 ) {
F_53 ( V_3 ) ;
V_163 = F_108 ( V_3 ) ;
if ( V_163 < 0 ) {
F_69 ( V_3 ) ;
V_3 = F_112 ( V_163 ) ;
}
} else
V_3 = F_110 ( V_24 , V_31 ) ;
F_33 ( & V_41 ) ;
if ( V_24 )
F_123 ( V_24 ) ;
if ( F_144 ( V_3 ) ) {
V_163 = F_145 ( V_3 ) ;
goto V_196;
}
F_10 ( V_3 , V_56 ) ;
F_23 ( V_3 , V_170 ) ;
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_160 )
V_187 = 1 ;
#ifdef F_74
F_20 ( V_106 L_31 , V_170 , V_3 -> V_16 ) ;
#endif
if ( V_3 -> V_42 -> V_197 )
V_163 = V_3 -> V_42 -> V_197 ( V_3 , V_56 ) ;
else
V_163 = - V_165 ;
V_56 -> V_131 = V_192 ;
if ( ! V_163 && F_48 ( V_198 , & V_3 -> V_44 ) &&
! F_146 ( V_199 ) )
V_163 = - V_200 ;
if ( V_163 ) {
#ifdef F_74
F_20 ( V_106 L_32 , V_170 ,
V_163 , V_3 -> V_16 ) ;
#endif
F_69 ( V_3 ) ;
F_130 ( V_17 , V_56 ) ;
if ( V_163 != - V_54 )
return V_163 ;
if ( F_94 ( V_46 ) )
return V_163 ;
F_135 () ;
if ( V_56 -> V_82 == & V_86 )
V_56 -> V_82 = & V_201 ;
goto V_193;
}
F_69 ( V_3 ) ;
F_32 ( & V_41 ) ;
F_53 ( V_3 ) ;
F_59 ( & V_46 -> V_89 -> V_90 ) ;
if ( ! V_187 &&
V_46 -> signal -> V_91 &&
! V_46 -> signal -> V_3 &&
V_3 -> V_88 == NULL )
F_147 ( V_46 , V_3 ) ;
F_60 ( & V_46 -> V_89 -> V_90 ) ;
F_69 ( V_3 ) ;
F_33 ( & V_41 ) ;
return 0 ;
V_195:
F_33 ( & V_41 ) ;
if ( ! F_148 ( V_24 ) )
F_123 ( V_24 ) ;
V_196:
F_14 ( V_56 ) ;
return V_163 ;
}
static unsigned int F_149 ( struct V_7 * V_56 , T_6 * V_57 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
struct V_68 * V_69 ;
int V_45 = 0 ;
if ( F_18 ( V_3 , V_56 -> V_121 . V_122 -> V_123 , L_33 ) )
return 0 ;
V_69 = F_88 ( V_3 ) ;
if ( V_69 -> V_42 -> V_202 )
V_45 = ( V_69 -> V_42 -> V_202 ) ( V_3 , V_56 , V_57 ) ;
F_50 ( V_69 ) ;
return V_45 ;
}
static int F_55 ( int V_203 , struct V_7 * V_56 , int V_204 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
unsigned long V_44 ;
int V_163 = 0 ;
if ( F_18 ( V_3 , V_56 -> V_121 . V_122 -> V_123 , L_34 ) )
goto V_51;
V_163 = F_150 ( V_203 , V_56 , V_204 , & V_3 -> V_205 ) ;
if ( V_163 <= 0 )
goto V_51;
if ( V_204 ) {
enum V_206 type ;
struct V_107 * V_107 ;
if ( ! F_132 ( & V_3 -> V_116 ) )
V_3 -> V_207 = 1 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_48 ) {
V_107 = V_3 -> V_48 ;
type = V_208 ;
} else {
V_107 = F_151 ( V_46 ) ;
type = V_209 ;
}
F_63 ( V_107 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
V_163 = F_152 ( V_56 , V_107 , type , 0 ) ;
F_62 ( V_107 ) ;
if ( V_163 )
goto V_51;
} else {
if ( ! V_3 -> V_205 && ! F_132 ( & V_3 -> V_116 ) )
V_3 -> V_207 = V_210 ;
}
V_163 = 0 ;
V_51:
return V_163 ;
}
static int F_153 ( int V_203 , struct V_7 * V_56 , int V_204 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
int V_163 ;
F_53 ( V_3 ) ;
V_163 = F_55 ( V_203 , V_56 , V_204 ) ;
F_69 ( V_3 ) ;
return V_163 ;
}
static int F_154 ( struct V_1 * V_3 , char T_3 * V_22 )
{
char V_211 , V_212 = 0 ;
struct V_68 * V_69 ;
if ( ( V_46 -> signal -> V_3 != V_3 ) && ! F_146 ( V_199 ) )
return - V_213 ;
if ( F_155 ( V_211 , V_22 ) )
return - V_137 ;
F_156 ( V_3 , V_211 ) ;
V_69 = F_88 ( V_3 ) ;
V_69 -> V_42 -> V_214 ( V_3 , & V_211 , & V_212 , 1 ) ;
F_50 ( V_69 ) ;
return 0 ;
}
static int F_157 ( struct V_1 * V_3 , struct V_215 T_3 * V_65 )
{
int V_216 ;
F_32 ( & V_3 -> V_217 ) ;
V_216 = F_158 ( V_65 , & V_3 -> V_215 , sizeof( * V_65 ) ) ;
F_33 ( & V_3 -> V_217 ) ;
return V_216 ? - V_137 : 0 ;
}
int F_159 ( struct V_1 * V_3 , struct V_215 * V_218 )
{
struct V_107 * V_48 ;
unsigned long V_44 ;
F_32 ( & V_3 -> V_217 ) ;
if ( ! memcmp ( V_218 , & V_3 -> V_215 , sizeof( * V_218 ) ) )
goto V_219;
F_35 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_63 ( V_3 -> V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
if ( V_48 )
F_40 ( V_48 , V_220 , 1 ) ;
F_62 ( V_48 ) ;
V_3 -> V_215 = * V_218 ;
V_219:
F_33 ( & V_3 -> V_217 ) ;
return 0 ;
}
static int F_160 ( struct V_1 * V_3 , struct V_215 T_3 * V_65 )
{
struct V_215 V_221 ;
if ( F_93 ( & V_221 , V_65 , sizeof( * V_65 ) ) )
return - V_137 ;
if ( V_3 -> V_42 -> V_222 )
return V_3 -> V_42 -> V_222 ( V_3 , & V_221 ) ;
else
return F_159 ( V_3 , & V_221 ) ;
}
static int F_161 ( struct V_7 * V_7 )
{
if ( ! F_146 ( V_199 ) )
return - V_213 ;
if ( V_7 -> V_82 -> V_83 == V_84 ) {
struct V_7 * V_74 ;
F_11 ( & V_79 ) ;
V_74 = V_80 ;
V_80 = NULL ;
F_13 ( & V_79 ) ;
if ( V_74 )
F_70 ( V_74 ) ;
return 0 ;
}
F_11 ( & V_79 ) ;
if ( V_80 ) {
F_13 ( & V_79 ) ;
return - V_200 ;
}
V_80 = F_97 ( V_7 ) ;
F_13 ( & V_79 ) ;
return 0 ;
}
static int F_162 ( struct V_7 * V_7 , int T_3 * V_22 )
{
int V_223 ;
if ( F_155 ( V_223 , V_22 ) )
return - V_137 ;
F_11 ( & V_7 -> V_224 ) ;
if ( V_223 )
V_7 -> V_131 |= V_186 ;
else
V_7 -> V_131 &= ~ V_186 ;
F_13 ( & V_7 -> V_224 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_3 , int V_65 )
{
int V_45 = 0 ;
if ( V_46 -> signal -> V_91 && ( F_83 ( V_46 ) == V_3 -> V_88 ) )
return V_45 ;
F_32 ( & V_41 ) ;
if ( ! V_46 -> signal -> V_91 || V_46 -> signal -> V_3 ) {
V_45 = - V_213 ;
goto V_225;
}
if ( V_3 -> V_88 ) {
if ( V_65 == 1 && F_146 ( V_199 ) ) {
F_57 ( & V_87 ) ;
F_80 ( V_3 -> V_88 ) ;
F_65 ( & V_87 ) ;
} else {
V_45 = - V_213 ;
goto V_225;
}
}
F_164 ( V_46 , V_3 ) ;
V_225:
F_33 ( & V_41 ) ;
return V_45 ;
}
struct V_107 * F_165 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
struct V_107 * V_48 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_63 ( V_3 -> V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
return V_48 ;
}
static int F_166 ( struct V_1 * V_3 , struct V_1 * V_226 , T_7 T_3 * V_22 )
{
struct V_107 * V_107 ;
int V_45 ;
if ( V_3 == V_226 && V_46 -> signal -> V_3 != V_226 )
return - V_67 ;
V_107 = F_165 ( V_226 ) ;
V_45 = F_167 ( F_168 ( V_107 ) , V_22 ) ;
F_62 ( V_107 ) ;
return V_45 ;
}
static int F_169 ( struct V_1 * V_3 , struct V_1 * V_226 , T_7 T_3 * V_22 )
{
struct V_107 * V_48 ;
T_7 V_227 ;
int V_163 = F_34 ( V_226 ) ;
unsigned long V_44 ;
if ( V_163 == - V_52 )
return - V_67 ;
if ( V_163 )
return V_163 ;
if ( ! V_46 -> signal -> V_3 ||
( V_46 -> signal -> V_3 != V_226 ) ||
( V_226 -> V_88 != F_83 ( V_46 ) ) )
return - V_67 ;
if ( F_155 ( V_227 , V_22 ) )
return - V_137 ;
if ( V_227 < 0 )
return - V_228 ;
F_170 () ;
V_48 = F_171 ( V_227 ) ;
V_163 = - V_229 ;
if ( ! V_48 )
goto V_49;
V_163 = - V_213 ;
if ( F_172 ( V_48 ) != F_83 ( V_46 ) )
goto V_49;
V_163 = 0 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
F_62 ( V_226 -> V_48 ) ;
V_226 -> V_48 = F_63 ( V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
V_49:
F_173 () ;
return V_163 ;
}
static int F_174 ( struct V_1 * V_3 , struct V_1 * V_226 , T_7 T_3 * V_22 )
{
if ( V_3 == V_226 && V_46 -> signal -> V_3 != V_226 )
return - V_67 ;
if ( ! V_226 -> V_88 )
return - V_67 ;
return F_167 ( F_168 ( V_226 -> V_88 ) , V_22 ) ;
}
static int F_175 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_230 ;
int V_45 ;
if ( F_155 ( V_230 , V_22 ) )
return - V_137 ;
V_45 = F_176 ( V_3 , V_230 ) ;
return V_45 ;
}
static int F_177 ( struct V_1 * V_3 , unsigned int V_231 )
{
int V_163 ;
if ( V_3 -> V_42 -> V_232 == NULL )
return 0 ;
if ( V_3 -> V_24 -> V_44 & V_233 )
V_163 = V_3 -> V_42 -> V_232 ( V_3 , V_231 ) ;
else {
if ( F_91 ( V_3 , 0 ) < 0 )
return - V_234 ;
V_163 = V_3 -> V_42 -> V_232 ( V_3 , - 1 ) ;
if ( V_163 )
goto V_51;
if ( ! F_94 ( V_46 ) )
F_178 ( V_231 ) ;
V_163 = V_3 -> V_42 -> V_232 ( V_3 , 0 ) ;
V_51:
F_90 ( V_3 ) ;
if ( F_94 ( V_46 ) )
V_163 = - V_234 ;
}
return V_163 ;
}
static int F_179 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_163 = - V_228 ;
if ( V_3 -> V_42 -> V_235 ) {
V_163 = V_3 -> V_42 -> V_235 ( V_3 ) ;
if ( V_163 >= 0 )
V_163 = F_167 ( V_163 , V_22 ) ;
}
return V_163 ;
}
static int F_180 ( struct V_1 * V_3 , unsigned int V_64 ,
unsigned T_3 * V_22 )
{
int V_163 ;
unsigned int V_236 , V_237 , V_238 ;
if ( V_3 -> V_42 -> V_239 == NULL )
return - V_228 ;
V_163 = F_155 ( V_238 , V_22 ) ;
if ( V_163 )
return V_163 ;
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
static int F_181 ( struct V_1 * V_3 , void T_3 * V_65 )
{
int V_163 = - V_228 ;
struct V_248 V_249 ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
if ( V_3 -> V_42 -> V_250 )
V_163 = V_3 -> V_42 -> V_250 ( V_3 , & V_249 ) ;
if ( V_163 != 0 )
return V_163 ;
if ( F_158 ( V_65 , & V_249 , sizeof( V_249 ) ) )
return - V_137 ;
return 0 ;
}
struct V_1 * F_182 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_160 )
V_3 = V_3 -> V_28 ;
return V_3 ;
}
struct V_1 * F_183 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_160 )
return V_3 ;
return V_3 -> V_28 ;
}
long F_184 ( struct V_7 * V_7 , unsigned int V_64 , unsigned long V_65 )
{
struct V_1 * V_3 = F_7 ( V_7 ) ;
struct V_1 * V_226 ;
void T_3 * V_22 = ( void T_3 * ) V_65 ;
int V_163 ;
struct V_68 * V_69 ;
struct V_17 * V_17 = V_7 -> V_251 -> V_123 ;
if ( F_18 ( V_3 , V_17 , L_35 ) )
return - V_228 ;
V_226 = F_182 ( V_3 ) ;
switch ( V_64 ) {
case V_252 :
case V_253 :
case V_254 :
case V_255 :
case V_256 :
V_163 = F_34 ( V_3 ) ;
if ( V_163 )
return V_163 ;
if ( V_64 != V_254 ) {
F_185 ( V_3 , 0 ) ;
if ( F_94 ( V_46 ) )
return - V_234 ;
}
break;
}
switch ( V_64 ) {
case V_257 :
return F_154 ( V_3 , V_22 ) ;
case V_258 :
return F_157 ( V_226 , V_22 ) ;
case V_259 :
return F_160 ( V_226 , V_22 ) ;
case V_260 :
return V_226 != V_3 ? - V_228 : F_161 ( V_7 ) ;
case V_261 :
return F_162 ( V_7 , V_22 ) ;
case V_262 :
F_54 ( V_198 , & V_3 -> V_44 ) ;
return 0 ;
case V_263 :
F_66 ( V_198 , & V_3 -> V_44 ) ;
return 0 ;
case V_264 :
if ( V_46 -> signal -> V_3 != V_3 )
return - V_67 ;
F_84 () ;
return 0 ;
case V_265 :
return F_163 ( V_3 , V_65 ) ;
case V_266 :
return F_166 ( V_3 , V_226 , V_22 ) ;
case V_66 :
return F_169 ( V_3 , V_226 , V_22 ) ;
case V_267 :
return F_174 ( V_3 , V_226 , V_22 ) ;
case V_268 :
return F_167 ( V_3 -> V_230 -> V_42 -> V_35 , ( int T_3 * ) V_22 ) ;
case V_252 :
return F_175 ( V_3 , V_22 ) ;
case V_269 :
if ( ! F_146 ( V_199 ) )
return - V_213 ;
F_76 ( V_3 ) ;
return 0 ;
case V_270 :
{
unsigned int V_45 = F_186 ( F_187 ( V_226 ) ) ;
return F_167 ( V_45 , ( unsigned int T_3 * ) V_22 ) ;
}
case V_253 :
if ( V_3 -> V_42 -> V_232 )
return V_3 -> V_42 -> V_232 ( V_3 , - 1 ) ;
return 0 ;
case V_254 :
if ( V_3 -> V_42 -> V_232 )
return V_3 -> V_42 -> V_232 ( V_3 , 0 ) ;
return 0 ;
case V_255 :
if ( ! V_65 )
return F_177 ( V_3 , 250 ) ;
return 0 ;
case V_256 :
return F_177 ( V_3 , V_65 ? V_65 * 100 : 250 ) ;
case V_271 :
return F_179 ( V_3 , V_22 ) ;
case V_242 :
case V_241 :
case V_240 :
return F_180 ( V_3 , V_64 , V_22 ) ;
case V_272 :
V_163 = F_181 ( V_3 , V_22 ) ;
if ( V_163 != - V_228 )
return V_163 ;
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
V_163 = ( V_3 -> V_42 -> V_276 ) ( V_3 , V_64 , V_65 ) ;
if ( V_163 != - V_277 )
return V_163 ;
}
V_69 = F_88 ( V_3 ) ;
V_163 = - V_228 ;
if ( V_69 -> V_42 -> V_276 ) {
V_163 = V_69 -> V_42 -> V_276 ( V_3 , V_7 , V_64 , V_65 ) ;
if ( V_163 == - V_277 )
V_163 = - V_67 ;
}
F_50 ( V_69 ) ;
return V_163 ;
}
static long F_189 ( struct V_7 * V_7 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_17 * V_17 = V_7 -> V_251 -> V_123 ;
struct V_1 * V_3 = F_7 ( V_7 ) ;
struct V_68 * V_69 ;
int V_163 = - V_277 ;
if ( F_18 ( V_3 , V_17 , L_35 ) )
return - V_228 ;
if ( V_3 -> V_42 -> V_278 ) {
V_163 = ( V_3 -> V_42 -> V_278 ) ( V_3 , V_64 , V_65 ) ;
if ( V_163 != - V_277 )
return V_163 ;
}
V_69 = F_88 ( V_3 ) ;
if ( V_69 -> V_42 -> V_278 )
V_163 = V_69 -> V_42 -> V_278 ( V_3 , V_7 , V_64 , V_65 ) ;
else
V_163 = F_190 ( V_3 , V_7 , V_64 , V_65 ) ;
F_50 ( V_69 ) ;
return V_163 ;
}
static int F_191 ( const void * V_279 , struct V_7 * V_7 , unsigned V_203 )
{
if ( F_192 ( V_7 -> V_82 -> V_125 != F_87 ) )
return 0 ;
return F_7 ( V_7 ) != V_279 ? 0 : V_203 + 1 ;
}
void F_193 ( struct V_1 * V_3 )
{
#ifdef F_194
F_73 ( V_3 ) ;
#else
struct V_75 * V_280 , * V_22 ;
struct V_107 * V_88 ;
int V_120 ;
if ( ! V_3 )
return;
V_88 = V_3 -> V_88 ;
F_195 ( V_3 ) ;
F_196 ( V_3 ) ;
F_57 ( & V_87 ) ;
F_58 (session, PIDTYPE_SID, p) {
F_20 ( V_281 L_36
L_37 ,
F_197 ( V_22 ) , V_22 -> V_282 ) ;
F_198 ( V_283 , V_22 , 1 ) ;
} F_64 ( V_88 , V_96 , V_22 ) ;
F_199 (g, p) {
if ( V_22 -> signal -> V_3 == V_3 ) {
F_20 ( V_281 L_36
L_37 ,
F_197 ( V_22 ) , V_22 -> V_282 ) ;
F_198 ( V_283 , V_22 , 1 ) ;
continue;
}
F_200 ( V_22 ) ;
V_120 = F_201 ( V_22 -> V_284 , 0 , F_191 , V_3 ) ;
if ( V_120 != 0 ) {
F_20 ( V_281 L_36
L_38 ,
F_197 ( V_22 ) , V_22 -> V_282 , V_120 - 1 ) ;
F_202 ( V_283 , V_22 ) ;
}
F_203 ( V_22 ) ;
} F_204 ( V_280 , V_22 ) ;
F_65 ( & V_87 ) ;
#endif
}
static void F_205 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_72 ( V_104 , struct V_1 , V_285 ) ;
F_193 ( V_3 ) ;
}
void F_206 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
F_75 ( & V_3 -> V_285 ) ;
}
static int F_207 ( struct V_30 * V_4 , void * V_286 )
{
T_1 * V_287 = V_286 ;
return V_4 -> V_287 == * V_287 ;
}
static struct V_30 * F_208 ( struct V_1 * V_3 )
{
T_1 V_287 = F_187 ( V_3 ) ;
return F_209 ( V_288 , NULL , & V_287 , F_207 ) ;
}
void F_113 ( struct V_1 * V_3 ,
struct V_29 * V_24 , int V_148 )
{
memset ( V_3 , 0 , sizeof( struct V_1 ) ) ;
F_210 ( & V_3 -> V_174 ) ;
V_3 -> V_6 = V_20 ;
F_211 ( V_3 ) ;
V_3 -> V_88 = NULL ;
V_3 -> V_48 = NULL ;
V_3 -> V_289 = V_290 ;
F_212 ( V_3 ) ;
F_213 ( & V_3 -> V_291 ) ;
F_213 ( & V_3 -> V_217 ) ;
F_213 ( & V_3 -> V_161 ) ;
F_214 ( & V_3 -> V_72 ) ;
F_214 ( & V_3 -> V_116 ) ;
F_126 ( & V_3 -> V_105 , F_71 ) ;
F_213 ( & V_3 -> V_292 ) ;
F_213 ( & V_3 -> V_140 ) ;
F_213 ( & V_3 -> V_293 ) ;
F_213 ( & V_3 -> V_294 ) ;
F_215 ( & V_3 -> F_57 ) ;
F_215 ( & V_3 -> V_47 ) ;
F_216 ( & V_3 -> V_14 ) ;
F_126 ( & V_3 -> V_285 , F_205 ) ;
V_3 -> V_24 = V_24 ;
V_3 -> V_42 = V_24 -> V_42 ;
V_3 -> V_31 = V_148 ;
F_100 ( V_24 , V_148 , V_3 -> V_16 ) ;
V_3 -> V_4 = F_208 ( V_3 ) ;
}
void F_116 ( struct V_1 * V_3 )
{
F_217 ( V_3 ) ;
}
int F_218 ( struct V_1 * V_3 , unsigned char V_211 )
{
if ( V_3 -> V_42 -> V_295 )
return V_3 -> V_42 -> V_295 ( V_3 , V_211 ) ;
return V_3 -> V_42 -> V_83 ( V_3 , & V_211 , 1 ) ;
}
static int F_219 ( struct V_29 * V_24 , T_1 V_4 ,
unsigned int V_31 , unsigned int V_23 )
{
F_220 ( & V_24 -> V_296 [ V_31 ] , & V_201 ) ;
V_24 -> V_296 [ V_31 ] . V_164 = V_24 -> V_164 ;
return F_221 ( & V_24 -> V_296 [ V_31 ] , V_4 , V_23 ) ;
}
struct V_30 * F_222 ( struct V_29 * V_24 , unsigned V_31 ,
struct V_30 * V_30 )
{
return F_223 ( V_24 , V_31 , V_30 , NULL , NULL ) ;
}
static void F_224 ( struct V_30 * V_4 )
{
F_225 ( L_39 , F_226 ( V_4 ) , V_170 ) ;
F_5 ( V_4 ) ;
}
struct V_30 * F_223 ( struct V_29 * V_24 ,
unsigned V_31 , struct V_30 * V_30 ,
void * V_297 ,
const struct V_298 * * V_299 )
{
char V_16 [ 64 ] ;
T_1 V_287 = F_28 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ;
struct V_30 * V_4 = NULL ;
int V_163 = - V_165 ;
bool V_300 = false ;
if ( V_31 >= V_24 -> V_35 ) {
F_20 ( V_143 L_40
L_41 , V_31 ) ;
return F_112 ( - V_228 ) ;
}
if ( V_24 -> type == V_25 )
F_99 ( V_24 , V_31 , V_16 ) ;
else
F_100 ( V_24 , V_31 , V_16 ) ;
if ( ! ( V_24 -> V_44 & V_301 ) ) {
V_163 = F_219 ( V_24 , V_287 , V_31 , 1 ) ;
if ( V_163 )
goto error;
V_300 = true ;
}
V_4 = F_2 ( sizeof( * V_4 ) , V_2 ) ;
if ( ! V_4 ) {
V_163 = - V_11 ;
goto error;
}
V_4 -> V_287 = V_287 ;
V_4 -> V_302 = V_288 ;
V_4 -> V_303 = V_30 ;
V_4 -> V_304 = F_224 ;
F_227 ( V_4 , L_42 , V_16 ) ;
V_4 -> V_305 = V_299 ;
F_228 ( V_4 , V_297 ) ;
V_163 = F_229 ( V_4 ) ;
if ( V_163 )
goto error;
return V_4 ;
error:
F_4 ( V_4 ) ;
if ( V_300 )
F_230 ( & V_24 -> V_296 [ V_31 ] ) ;
return F_112 ( V_163 ) ;
}
void F_231 ( struct V_29 * V_24 , unsigned V_31 )
{
F_232 ( V_288 ,
F_28 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ) ;
if ( ! ( V_24 -> V_44 & V_301 ) )
F_230 ( & V_24 -> V_296 [ V_31 ] ) ;
}
struct V_29 * F_233 ( unsigned int V_306 , struct V_307 * V_164 ,
unsigned long V_44 )
{
struct V_29 * V_24 ;
unsigned int V_296 = 1 ;
int V_216 ;
if ( ! V_306 || ( V_44 & V_147 && V_306 > 1 ) )
return F_112 ( - V_228 ) ;
V_24 = F_2 ( sizeof( struct V_29 ) , V_2 ) ;
if ( ! V_24 )
return F_112 ( - V_11 ) ;
F_210 ( & V_24 -> V_174 ) ;
V_24 -> V_6 = V_308 ;
V_24 -> V_35 = V_306 ;
V_24 -> V_164 = V_164 ;
V_24 -> V_44 = V_44 ;
if ( ! ( V_44 & V_177 ) ) {
V_24 -> V_150 = F_234 ( V_306 , sizeof( * V_24 -> V_150 ) ,
V_2 ) ;
V_24 -> V_154 = F_234 ( V_306 , sizeof( * V_24 -> V_154 ) ,
V_2 ) ;
if ( ! V_24 -> V_150 || ! V_24 -> V_154 ) {
V_216 = - V_11 ;
goto V_309;
}
}
if ( ! ( V_44 & V_301 ) ) {
V_24 -> V_169 = F_234 ( V_306 , sizeof( * V_24 -> V_169 ) ,
V_2 ) ;
if ( ! V_24 -> V_169 ) {
V_216 = - V_11 ;
goto V_309;
}
V_296 = V_306 ;
}
V_24 -> V_296 = F_234 ( V_296 , sizeof( * V_24 -> V_296 ) , V_2 ) ;
if ( ! V_24 -> V_296 ) {
V_216 = - V_11 ;
goto V_309;
}
return V_24 ;
V_309:
F_5 ( V_24 -> V_169 ) ;
F_5 ( V_24 -> V_150 ) ;
F_5 ( V_24 -> V_154 ) ;
F_5 ( V_24 ) ;
return F_112 ( V_216 ) ;
}
static void F_235 ( struct V_174 * V_174 )
{
struct V_29 * V_24 = F_72 ( V_174 , struct V_29 , V_174 ) ;
int V_120 ;
struct V_151 * V_152 ;
if ( V_24 -> V_44 & V_310 ) {
for ( V_120 = 0 ; V_120 < V_24 -> V_35 ; V_120 ++ ) {
V_152 = V_24 -> V_154 [ V_120 ] ;
if ( V_152 ) {
V_24 -> V_154 [ V_120 ] = NULL ;
F_5 ( V_152 ) ;
}
if ( ! ( V_24 -> V_44 & V_311 ) )
F_231 ( V_24 , V_120 ) ;
}
F_236 ( V_24 ) ;
if ( V_24 -> V_44 & V_301 )
F_230 ( & V_24 -> V_296 [ 0 ] ) ;
}
F_5 ( V_24 -> V_296 ) ;
F_5 ( V_24 -> V_169 ) ;
F_5 ( V_24 -> V_154 ) ;
F_5 ( V_24 -> V_150 ) ;
F_5 ( V_24 ) ;
}
void F_123 ( struct V_29 * V_24 )
{
F_127 ( & V_24 -> V_174 , F_235 ) ;
}
void F_237 ( struct V_29 * V_24 ,
const struct V_312 * V_313 )
{
V_24 -> V_42 = V_313 ;
}
void F_238 ( struct V_29 * V_314 )
{
F_123 ( V_314 ) ;
}
int F_239 ( struct V_29 * V_24 )
{
int error ;
int V_120 ;
T_1 V_4 ;
struct V_30 * V_314 ;
if ( ! V_24 -> V_33 ) {
error = F_240 ( & V_4 , V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_16 ) ;
if ( ! error ) {
V_24 -> V_33 = F_241 ( V_4 ) ;
V_24 -> V_34 = F_242 ( V_4 ) ;
}
} else {
V_4 = F_28 ( V_24 -> V_33 , V_24 -> V_34 ) ;
error = F_243 ( V_4 , V_24 -> V_35 , V_24 -> V_16 ) ;
}
if ( error < 0 )
goto V_216;
if ( V_24 -> V_44 & V_301 ) {
error = F_219 ( V_24 , V_4 , 0 , V_24 -> V_35 ) ;
if ( error )
goto V_315;
}
F_32 ( & V_41 ) ;
F_12 ( & V_24 -> V_316 , & V_316 ) ;
F_33 ( & V_41 ) ;
if ( ! ( V_24 -> V_44 & V_311 ) ) {
for ( V_120 = 0 ; V_120 < V_24 -> V_35 ; V_120 ++ ) {
V_314 = F_222 ( V_24 , V_120 , NULL ) ;
if ( F_144 ( V_314 ) ) {
error = F_145 ( V_314 ) ;
goto V_317;
}
}
}
F_244 ( V_24 ) ;
V_24 -> V_44 |= V_310 ;
return 0 ;
V_317:
for ( V_120 -- ; V_120 >= 0 ; V_120 -- )
F_231 ( V_24 , V_120 ) ;
F_32 ( & V_41 ) ;
F_16 ( & V_24 -> V_316 ) ;
F_33 ( & V_41 ) ;
V_315:
F_245 ( V_4 , V_24 -> V_35 ) ;
V_216:
return error ;
}
int F_246 ( struct V_29 * V_24 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_245 ( F_28 ( V_24 -> V_33 , V_24 -> V_34 ) ,
V_24 -> V_35 ) ;
F_32 ( & V_41 ) ;
F_16 ( & V_24 -> V_316 ) ;
F_33 ( & V_41 ) ;
return 0 ;
}
T_1 F_187 ( struct V_1 * V_3 )
{
return F_28 ( V_3 -> V_24 -> V_33 , V_3 -> V_24 -> V_34 ) + V_3 -> V_31 ;
}
void F_81 ( struct V_75 * V_22 )
{
unsigned long V_44 ;
struct V_1 * V_3 ;
F_35 ( & V_22 -> V_89 -> V_90 , V_44 ) ;
V_3 = V_22 -> signal -> V_3 ;
V_22 -> signal -> V_3 = NULL ;
F_37 ( & V_22 -> V_89 -> V_90 , V_44 ) ;
F_67 ( V_3 ) ;
}
static void F_147 ( struct V_75 * V_111 , struct V_1 * V_3 )
{
if ( V_3 ) {
unsigned long V_44 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
F_62 ( V_3 -> V_88 ) ;
F_62 ( V_3 -> V_48 ) ;
V_3 -> V_48 = F_63 ( F_36 ( V_111 ) ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
V_3 -> V_88 = F_63 ( F_83 ( V_111 ) ) ;
if ( V_111 -> signal -> V_3 ) {
F_20 ( V_106 L_43 ) ;
F_67 ( V_111 -> signal -> V_3 ) ;
}
}
F_62 ( V_111 -> signal -> V_95 ) ;
V_111 -> signal -> V_3 = F_247 ( V_3 ) ;
V_111 -> signal -> V_95 = NULL ;
}
static void F_164 ( struct V_75 * V_111 , struct V_1 * V_3 )
{
F_59 ( & V_111 -> V_89 -> V_90 ) ;
F_147 ( V_111 , V_3 ) ;
F_60 ( & V_111 -> V_89 -> V_90 ) ;
}
struct V_1 * F_78 ( void )
{
struct V_1 * V_3 ;
unsigned long V_44 ;
F_35 ( & V_46 -> V_89 -> V_90 , V_44 ) ;
V_3 = F_247 ( V_46 -> signal -> V_3 ) ;
F_37 ( & V_46 -> V_89 -> V_90 , V_44 ) ;
return V_3 ;
}
void F_248 ( struct V_318 * V_319 )
{
* V_319 = V_201 ;
}
void T_8 F_249 ( void )
{
T_9 * V_320 ;
F_250 () ;
V_320 = V_321 ;
while ( V_320 < V_322 ) {
(* V_320)() ;
V_320 ++ ;
}
}
static char * F_251 ( struct V_30 * V_4 , T_10 * V_323 )
{
if ( ! V_323 )
return NULL ;
if ( V_4 -> V_287 == F_28 ( V_184 , 0 ) ||
V_4 -> V_287 == F_28 ( V_184 , 2 ) )
* V_323 = 0666 ;
return NULL ;
}
static int T_8 F_252 ( void )
{
V_288 = F_253 ( V_324 , L_16 ) ;
if ( F_144 ( V_288 ) )
return F_145 ( V_288 ) ;
V_288 -> V_325 = F_251 ;
return 0 ;
}
static T_2 F_254 ( struct V_30 * V_4 ,
struct V_326 * V_327 , char * V_15 )
{
struct V_328 * V_329 [ 16 ] ;
int V_120 = 0 ;
struct V_328 * V_330 ;
T_2 V_23 = 0 ;
F_255 () ;
F_256 (c) {
if ( ! V_330 -> V_30 )
continue;
if ( ! V_330 -> V_83 )
continue;
if ( ( V_330 -> V_44 & V_331 ) == 0 )
continue;
V_329 [ V_120 ++ ] = V_330 ;
if ( V_120 >= F_257 ( V_329 ) )
break;
}
while ( V_120 -- )
V_23 += sprintf ( V_15 + V_23 , L_44 ,
V_329 [ V_120 ] -> V_16 , V_329 [ V_120 ] -> V_31 , V_120 ? ' ' : '\n' ) ;
F_258 () ;
return V_23 ;
}
void F_259 ( void )
{
if ( V_332 )
F_260 ( & V_332 -> V_333 , NULL , L_45 ) ;
}
int T_8 F_261 ( void )
{
F_220 ( & V_334 , & V_201 ) ;
if ( F_221 ( & V_334 , F_28 ( V_184 , 0 ) , 1 ) ||
F_243 ( F_28 ( V_184 , 0 ) , 1 , L_46 ) < 0 )
F_262 ( L_47 ) ;
F_263 ( V_288 , NULL , F_28 ( V_184 , 0 ) , NULL , L_16 ) ;
F_220 ( & V_335 , & V_336 ) ;
if ( F_221 ( & V_335 , F_28 ( V_184 , 1 ) , 1 ) ||
F_243 ( F_28 ( V_184 , 1 ) , 1 , L_48 ) < 0 )
F_262 ( L_49 ) ;
V_332 = F_263 ( V_288 , NULL , F_28 ( V_184 , 1 ) , NULL ,
L_50 ) ;
if ( F_144 ( V_332 ) )
V_332 = NULL ;
else
F_109 ( F_264 ( V_332 , & V_337 ) < 0 ) ;
#ifdef F_140
F_265 ( & V_336 ) ;
#endif
return 0 ;
}
