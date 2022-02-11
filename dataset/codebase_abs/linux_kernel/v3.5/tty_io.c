struct V_1 * F_1 ( void )
{
return F_2 ( sizeof( struct V_1 ) , V_2 ) ;
}
void F_3 ( struct V_1 * V_3 )
{
if ( V_3 -> V_4 )
F_4 ( V_3 -> V_4 ) ;
F_5 ( V_3 -> V_5 ) ;
F_6 ( V_3 ) ;
F_5 ( V_3 ) ;
}
static inline struct V_1 * F_7 ( struct V_6 * V_6 )
{
return ( (struct V_7 * ) V_6 -> V_8 ) -> V_3 ;
}
int F_8 ( struct V_6 * V_6 )
{
struct V_7 * V_9 ;
V_9 = F_9 ( sizeof( * V_9 ) , V_2 ) ;
if ( ! V_9 )
return - V_10 ;
V_6 -> V_8 = V_9 ;
return 0 ;
}
void F_10 ( struct V_1 * V_3 , struct V_6 * V_6 )
{
struct V_7 * V_9 = V_6 -> V_8 ;
V_9 -> V_3 = V_3 ;
V_9 -> V_6 = V_6 ;
F_11 ( & V_11 ) ;
F_12 ( & V_9 -> V_12 , & V_3 -> V_13 ) ;
F_13 ( & V_11 ) ;
}
void F_14 ( struct V_6 * V_6 )
{
struct V_7 * V_9 = V_6 -> V_8 ;
V_6 -> V_8 = NULL ;
F_5 ( V_9 ) ;
}
void F_15 ( struct V_6 * V_6 )
{
struct V_7 * V_9 = V_6 -> V_8 ;
F_11 ( & V_11 ) ;
F_16 ( & V_9 -> V_12 ) ;
F_13 ( & V_11 ) ;
F_14 ( V_6 ) ;
}
char * F_17 ( struct V_1 * V_3 , char * V_14 )
{
if ( ! V_3 )
strcpy ( V_14 , L_1 ) ;
else
strcpy ( V_14 , V_3 -> V_15 ) ;
return V_14 ;
}
int F_18 ( struct V_1 * V_3 , struct V_16 * V_16 ,
const char * V_17 )
{
#ifdef F_19
if ( ! V_3 ) {
F_20 ( V_18
L_2 ,
F_21 ( V_16 ) , F_22 ( V_16 ) , V_17 ) ;
return 1 ;
}
if ( V_3 -> V_19 != V_20 ) {
F_20 ( V_18
L_3 ,
F_21 ( V_16 ) , F_22 ( V_16 ) , V_17 ) ;
return 1 ;
}
#endif
return 0 ;
}
static int F_23 ( struct V_1 * V_3 , const char * V_17 )
{
#ifdef F_24
struct V_21 * V_22 ;
int V_23 = 0 ;
F_11 ( & V_11 ) ;
F_25 (p, &tty->tty_files) {
V_23 ++ ;
}
F_13 ( & V_11 ) ;
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_27 &&
V_3 -> V_28 && V_3 -> V_28 -> V_23 )
V_23 ++ ;
if ( V_3 -> V_23 != V_23 ) {
F_20 ( V_18 L_4
L_5 ,
V_3 -> V_15 , V_3 -> V_23 , V_23 , V_17 ) ;
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
struct V_29 * F_30 ( char * V_15 , int * line )
{
struct V_29 * V_22 , * V_36 = NULL ;
int V_37 = 0 ;
int V_38 ;
char * V_39 , * V_40 ;
for ( V_39 = V_15 ; * V_39 ; V_39 ++ )
if ( ( * V_39 >= '0' && * V_39 <= '9' ) || * V_39 == ',' )
break;
if ( ! * V_39 )
return NULL ;
V_38 = V_39 - V_15 ;
V_37 = F_31 ( V_39 , & V_39 , 10 ) ;
F_32 ( & V_41 ) ;
F_27 (p, &tty_drivers, tty_drivers) {
if ( strncmp ( V_15 , V_22 -> V_15 , V_38 ) != 0 )
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
F_20 ( V_18 L_6 ) ;
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
static T_2 F_42 ( struct V_6 * V_6 , char T_3 * V_14 ,
T_4 V_23 , T_5 * V_55 )
{
return 0 ;
}
static T_2 F_43 ( struct V_6 * V_6 , const char T_3 * V_14 ,
T_4 V_23 , T_5 * V_55 )
{
return - V_52 ;
}
static unsigned int F_44 ( struct V_6 * V_56 , T_6 * V_57 )
{
return V_58 | V_59 | V_60 | V_61 | V_62 | V_63 ;
}
static long F_45 ( struct V_6 * V_6 , unsigned int V_64 ,
unsigned long V_65 )
{
return V_64 == V_66 ? - V_67 : - V_52 ;
}
static long F_46 ( struct V_6 * V_6 ,
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
struct V_6 * V_73 = NULL ;
struct V_6 * V_56 , * V_74 = NULL ;
struct V_75 * V_22 ;
struct V_7 * V_9 ;
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
F_53 () ;
F_54 ( V_81 , & V_3 -> V_44 ) ;
F_23 ( V_3 , L_7 ) ;
F_11 ( & V_11 ) ;
F_27 (priv, &tty->tty_files, list) {
V_56 = V_9 -> V_6 ;
if ( V_56 -> V_82 -> V_83 == V_84 )
V_73 = V_56 ;
if ( V_56 -> V_82 -> V_83 != V_85 )
continue;
V_76 ++ ;
F_55 ( - 1 , V_56 , 0 ) ;
V_56 -> V_82 = & V_86 ;
}
F_13 ( & V_11 ) ;
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
F_69 () ;
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
char V_14 [ 64 ] ;
F_20 ( V_106 L_8 , F_17 ( V_3 , V_14 ) ) ;
#endif
F_75 ( & V_3 -> V_105 ) ;
}
void F_76 ( struct V_1 * V_3 )
{
#ifdef F_74
char V_14 [ 64 ] ;
F_20 ( V_106 L_9 , F_17 ( V_3 , V_14 ) ) ;
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
int F_79 ( struct V_6 * V_56 )
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
static T_2 F_87 ( struct V_6 * V_6 , char T_3 * V_14 , T_4 V_23 ,
T_5 * V_55 )
{
int V_120 ;
struct V_16 * V_16 = V_6 -> V_121 . V_122 -> V_123 ;
struct V_1 * V_3 = F_7 ( V_6 ) ;
struct V_68 * V_69 ;
if ( F_18 ( V_3 , V_16 , L_12 ) )
return - V_52 ;
if ( ! V_3 || ( F_48 ( V_124 , & V_3 -> V_44 ) ) )
return - V_52 ;
V_69 = F_88 ( V_3 ) ;
if ( V_69 -> V_42 -> V_125 )
V_120 = ( V_69 -> V_42 -> V_125 ) ( V_3 , V_6 , V_14 , V_23 ) ;
else
V_120 = - V_52 ;
F_50 ( V_69 ) ;
if ( V_120 > 0 )
V_16 -> V_126 = F_89 ( V_16 -> V_127 ) ;
return V_120 ;
}
void F_90 ( struct V_1 * V_3 )
__releases( &tty->atomic_write_lock
int F_91 ( struct V_1 * V_3 , int V_128 )
__acquires( &tty->atomic_write_lock
static inline T_2 F_92 (
T_2 (* V_83)( struct V_1 * , struct V_6 * , const unsigned char * , T_4 ) ,
struct V_1 * V_3 ,
struct V_6 * V_6 ,
const char T_3 * V_14 ,
T_4 V_23 )
{
T_2 V_45 , V_129 = 0 ;
unsigned int V_130 ;
V_45 = F_91 ( V_3 , V_6 -> V_131 & V_132 ) ;
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
V_45 = - V_10 ;
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
if ( F_93 ( V_3 -> V_5 , V_14 , V_136 ) )
break;
V_45 = V_83 ( V_3 , V_6 , V_3 -> V_5 , V_136 ) ;
if ( V_45 <= 0 )
break;
V_129 += V_45 ;
V_14 += V_45 ;
V_23 -= V_45 ;
if ( ! V_23 )
break;
V_45 = - V_54 ;
if ( F_94 ( V_46 ) )
break;
F_95 () ;
}
if ( V_129 ) {
struct V_16 * V_16 = V_6 -> V_121 . V_122 -> V_123 ;
V_16 -> V_138 = F_89 ( V_16 -> V_127 ) ;
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
F_53 () ;
if ( V_3 -> V_42 -> V_83 && ! F_48 ( V_141 , & V_3 -> V_44 ) ) {
F_69 () ;
V_3 -> V_42 -> V_83 ( V_3 , V_139 , strlen ( V_139 ) ) ;
} else
F_69 () ;
F_90 ( V_3 ) ;
}
return;
}
static T_2 V_85 ( struct V_6 * V_6 , const char T_3 * V_14 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_16 * V_16 = V_6 -> V_121 . V_122 -> V_123 ;
struct V_1 * V_3 = F_7 ( V_6 ) ;
struct V_68 * V_69 ;
T_2 V_45 ;
if ( F_18 ( V_3 , V_16 , L_13 ) )
return - V_52 ;
if ( ! V_3 || ! V_3 -> V_42 -> V_83 ||
( F_48 ( V_124 , & V_3 -> V_44 ) ) )
return - V_52 ;
if ( V_3 -> V_42 -> V_142 == NULL )
F_20 ( V_143 L_14 ,
V_3 -> V_24 -> V_15 ) ;
V_69 = F_88 ( V_3 ) ;
if ( ! V_69 -> V_42 -> V_83 )
V_45 = - V_52 ;
else
V_45 = F_92 ( V_69 -> V_42 -> V_83 , V_3 , V_6 , V_14 , V_23 ) ;
F_50 ( V_69 ) ;
return V_45 ;
}
T_2 V_84 ( struct V_6 * V_6 , const char T_3 * V_14 ,
T_4 V_23 , T_5 * V_55 )
{
struct V_6 * V_22 = NULL ;
F_11 ( & V_79 ) ;
if ( V_80 ) {
F_97 ( V_80 ) ;
V_22 = V_80 ;
}
F_13 ( & V_79 ) ;
if ( V_22 ) {
T_2 V_36 ;
V_36 = F_98 ( V_22 , V_14 , V_23 , & V_22 -> V_144 ) ;
F_70 ( V_22 ) ;
return V_36 ;
}
return V_85 ( V_6 , V_14 , V_23 , V_55 ) ;
}
static void F_99 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
int V_120 = V_31 + V_24 -> V_145 ;
sprintf ( V_22 , L_15 ,
V_24 -> V_26 == V_27 ? L_16 : V_24 -> V_15 ,
V_146 [ V_120 >> 4 & 0xf ] , V_120 & 0xf ) ;
}
static void F_100 ( struct V_29 * V_24 , int V_31 , char * V_22 )
{
sprintf ( V_22 , L_17 , V_24 -> V_15 , V_31 + V_24 -> V_145 ) ;
}
static struct V_1 * F_101 ( struct V_29 * V_24 ,
struct V_16 * V_16 , int V_147 )
{
if ( V_24 -> V_42 -> V_148 )
return V_24 -> V_42 -> V_148 ( V_24 , V_16 , V_147 ) ;
return V_24 -> V_149 [ V_147 ] ;
}
int F_102 ( struct V_1 * V_3 )
{
struct V_150 * V_151 ;
int V_147 = V_3 -> V_31 ;
V_151 = V_3 -> V_24 -> V_152 [ V_147 ] ;
if ( V_151 == NULL ) {
V_151 = F_2 ( sizeof( struct V_150 [ 2 ] ) , V_2 ) ;
if ( V_151 == NULL )
return - V_10 ;
memcpy ( V_151 , & V_3 -> V_24 -> V_153 ,
sizeof( struct V_150 ) ) ;
V_3 -> V_24 -> V_152 [ V_147 ] = V_151 ;
}
V_3 -> V_152 = V_151 ;
V_3 -> V_154 = V_151 + 1 ;
V_3 -> V_152 -> V_155 = F_103 ( V_3 -> V_152 ) ;
V_3 -> V_152 -> V_156 = F_104 ( V_3 -> V_152 ) ;
return 0 ;
}
int F_105 ( struct V_29 * V_24 , struct V_1 * V_3 )
{
int V_45 = F_102 ( V_3 ) ;
if ( V_45 )
return V_45 ;
F_29 ( V_24 ) ;
V_3 -> V_23 ++ ;
V_24 -> V_149 [ V_3 -> V_31 ] = V_3 ;
return 0 ;
}
static int F_106 ( struct V_29 * V_24 ,
struct V_1 * V_3 )
{
return V_24 -> V_42 -> V_157 ? V_24 -> V_42 -> V_157 ( V_24 , V_3 ) :
F_105 ( V_24 , V_3 ) ;
}
void F_107 ( struct V_29 * V_24 , struct V_1 * V_3 )
{
if ( V_24 -> V_42 -> remove )
V_24 -> V_42 -> remove ( V_24 , V_3 ) ;
else
V_24 -> V_149 [ V_3 -> V_31 ] = NULL ;
}
static int F_108 ( struct V_1 * V_3 )
{
struct V_29 * V_24 = V_3 -> V_24 ;
if ( F_48 ( V_141 , & V_3 -> V_44 ) ||
F_48 ( V_81 , & V_3 -> V_44 ) ||
F_48 ( V_158 , & V_3 -> V_44 ) )
return - V_52 ;
if ( V_24 -> type == V_25 &&
V_24 -> V_26 == V_159 ) {
if ( V_3 -> V_23 )
return - V_52 ;
V_3 -> V_28 -> V_23 ++ ;
}
V_3 -> V_23 ++ ;
F_32 ( & V_3 -> V_160 ) ;
F_109 ( ! F_48 ( V_161 , & V_3 -> V_44 ) ) ;
F_33 ( & V_3 -> V_160 ) ;
return 0 ;
}
struct V_1 * F_110 ( struct V_29 * V_24 , int V_147 )
{
struct V_1 * V_3 ;
int V_162 ;
if ( ! F_111 ( V_24 -> V_163 ) )
return F_112 ( - V_164 ) ;
V_3 = F_1 () ;
if ( ! V_3 ) {
V_162 = - V_10 ;
goto V_165;
}
F_113 ( V_3 , V_24 , V_147 ) ;
V_162 = F_106 ( V_24 , V_3 ) ;
if ( V_162 < 0 )
goto V_166;
V_162 = F_114 ( V_3 , V_3 -> V_28 ) ;
if ( V_162 )
goto V_167;
return V_3 ;
V_166:
F_115 ( V_3 ) ;
F_3 ( V_3 ) ;
V_165:
F_116 ( V_24 -> V_163 ) ;
return F_112 ( V_162 ) ;
V_167:
F_117 ( V_168 L_18
L_19 , V_147 ) ;
F_118 ( V_3 , V_147 ) ;
return F_112 ( V_162 ) ;
}
void F_119 ( struct V_1 * V_3 )
{
struct V_150 * V_151 ;
int V_147 = V_3 -> V_31 ;
if ( V_3 -> V_24 -> V_44 & V_169 ) {
V_151 = V_3 -> V_152 ;
V_3 -> V_24 -> V_152 [ V_147 ] = NULL ;
F_5 ( V_151 ) ;
}
}
void F_120 ( struct V_1 * V_3 )
{
F_107 ( V_3 -> V_24 , V_3 ) ;
F_119 ( V_3 ) ;
}
static void F_121 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_72 ( V_104 , struct V_1 , V_105 ) ;
struct V_29 * V_24 = V_3 -> V_24 ;
if ( V_3 -> V_42 -> V_170 )
V_3 -> V_42 -> V_170 ( V_3 ) ;
V_3 -> V_19 = 0 ;
F_122 ( V_24 ) ;
F_116 ( V_24 -> V_163 ) ;
F_11 ( & V_11 ) ;
F_123 ( & V_3 -> V_13 ) ;
F_13 ( & V_11 ) ;
F_62 ( V_3 -> V_48 ) ;
F_62 ( V_3 -> V_88 ) ;
F_3 ( V_3 ) ;
}
static void F_124 ( struct V_171 * V_171 )
{
struct V_1 * V_3 = F_72 ( V_171 , struct V_1 , V_171 ) ;
if ( V_3 -> V_42 -> V_172 )
V_3 -> V_42 -> V_172 ( V_3 ) ;
else
F_120 ( V_3 ) ;
F_125 ( & V_3 -> V_105 , F_121 ) ;
F_75 ( & V_3 -> V_105 ) ;
}
void F_67 ( struct V_1 * V_3 )
{
if ( V_3 )
F_126 ( & V_3 -> V_171 , F_124 ) ;
}
static void F_118 ( struct V_1 * V_3 , int V_147 )
{
F_109 ( V_3 -> V_31 != V_147 ) ;
if ( V_3 -> V_28 )
F_67 ( V_3 -> V_28 ) ;
F_67 ( V_3 ) ;
}
static int F_127 ( struct V_1 * V_3 , struct V_1 * V_173 ,
int V_147 )
{
#ifdef F_19
if ( V_147 < 0 || V_147 >= V_3 -> V_24 -> V_35 ) {
F_20 ( V_106 L_20 ,
V_174 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_44 & V_175 )
return 0 ;
if ( V_3 != V_3 -> V_24 -> V_149 [ V_147 ] ) {
F_20 ( V_106 L_21 ,
V_174 , V_147 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_3 -> V_152 != V_3 -> V_24 -> V_152 [ V_147 ] ) {
F_20 ( V_106 L_22 ,
V_174 , V_147 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_176 ) {
if ( V_173 != V_3 -> V_24 -> V_176 -> V_149 [ V_147 ] ) {
F_20 ( V_106 L_23 ,
V_174 , V_147 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_173 -> V_152 != V_3 -> V_24 -> V_176 -> V_152 [ V_147 ] ) {
F_20 ( V_106 L_24 ,
V_174 , V_147 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_173 -> V_28 != V_3 ) {
F_20 ( V_106 L_25 , V_174 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_128 ( struct V_16 * V_16 , struct V_6 * V_56 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
struct V_1 * V_173 ;
int V_177 , V_178 , V_179 , V_180 ;
int V_181 ;
int V_147 ;
char V_14 [ 64 ] ;
if ( F_18 ( V_3 , V_16 , V_174 ) )
return 0 ;
F_53 () ;
F_23 ( V_3 , V_174 ) ;
F_55 ( - 1 , V_56 , 0 ) ;
V_147 = V_3 -> V_31 ;
V_177 = ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 ) ;
V_181 = ( V_3 -> V_24 -> V_44 & V_175 ) != 0 ;
V_173 = V_3 -> V_28 ;
if ( F_127 ( V_3 , V_173 , V_147 ) ) {
F_69 () ;
return 0 ;
}
#ifdef F_74
F_20 ( V_106 L_26 , V_174 ,
F_17 ( V_3 , V_14 ) , V_3 -> V_23 ) ;
#endif
if ( V_3 -> V_42 -> V_100 )
V_3 -> V_42 -> V_100 ( V_3 , V_56 ) ;
F_69 () ;
while ( 1 ) {
F_32 ( & V_41 ) ;
F_53 () ;
V_178 = V_3 -> V_23 <= 1 ;
V_179 = V_173 &&
( V_173 -> V_23 <= ( V_177 ? 1 : 0 ) ) ;
V_180 = 0 ;
if ( V_178 ) {
if ( F_129 ( & V_3 -> V_116 ) ) {
F_130 ( & V_3 -> V_116 , V_58 ) ;
V_180 ++ ;
}
if ( F_129 ( & V_3 -> V_72 ) ) {
F_130 ( & V_3 -> V_72 , V_59 ) ;
V_180 ++ ;
}
}
if ( V_179 ) {
if ( F_129 ( & V_173 -> V_116 ) ) {
F_130 ( & V_173 -> V_116 , V_58 ) ;
V_180 ++ ;
}
if ( F_129 ( & V_173 -> V_72 ) ) {
F_130 ( & V_173 -> V_72 , V_59 ) ;
V_180 ++ ;
}
}
if ( ! V_180 )
break;
F_20 ( V_18 L_27 ,
V_174 , F_17 ( V_3 , V_14 ) ) ;
F_69 () ;
F_33 ( & V_41 ) ;
F_131 () ;
}
if ( V_177 ) {
if ( -- V_173 -> V_23 < 0 ) {
F_20 ( V_18 L_28 ,
V_174 , V_173 -> V_23 , F_17 ( V_173 , V_14 ) ) ;
V_173 -> V_23 = 0 ;
}
}
if ( -- V_3 -> V_23 < 0 ) {
F_20 ( V_18 L_29 ,
V_174 , V_3 -> V_23 , F_17 ( V_3 , V_14 ) ) ;
V_3 -> V_23 = 0 ;
}
F_15 ( V_56 ) ;
if ( V_178 )
F_54 ( V_141 , & V_3 -> V_44 ) ;
if ( V_179 )
F_54 ( V_141 , & V_173 -> V_44 ) ;
if ( V_178 || V_179 ) {
F_57 ( & V_87 ) ;
F_80 ( V_3 -> V_88 ) ;
if ( V_173 )
F_80 ( V_173 -> V_88 ) ;
F_65 ( & V_87 ) ;
}
F_33 ( & V_41 ) ;
if ( ! V_178 || ( V_173 && ! V_179 ) ) {
F_69 () ;
return 0 ;
}
#ifdef F_74
F_20 ( V_106 L_30 , V_174 ) ;
#endif
F_132 ( V_3 , V_173 ) ;
F_118 ( V_3 , V_147 ) ;
if ( V_181 )
F_133 ( V_16 , V_147 ) ;
F_69 () ;
return 0 ;
}
static struct V_1 * F_134 ( T_1 V_30 , struct V_6 * V_56 )
{
struct V_1 * V_3 ;
if ( V_30 != F_28 ( V_182 , 0 ) )
return NULL ;
V_3 = F_78 () ;
if ( ! V_3 )
return F_112 ( - V_183 ) ;
V_56 -> V_131 |= V_184 ;
F_67 ( V_3 ) ;
return V_3 ;
}
static struct V_29 * F_135 ( T_1 V_30 , struct V_6 * V_56 ,
int * V_185 , int * V_31 )
{
struct V_29 * V_24 ;
switch ( V_30 ) {
#ifdef F_136
case F_28 ( V_186 , 0 ) : {
extern struct V_29 * V_187 ;
V_24 = F_29 ( V_187 ) ;
* V_31 = V_188 ;
* V_185 = 1 ;
break;
}
#endif
case F_28 ( V_182 , 1 ) : {
struct V_29 * V_187 = F_137 ( V_31 ) ;
if ( V_187 ) {
V_24 = F_29 ( V_187 ) ;
if ( V_24 ) {
V_56 -> V_131 |= V_184 ;
* V_185 = 1 ;
break;
}
}
return F_112 ( - V_164 ) ;
}
default:
V_24 = F_26 ( V_30 , V_31 ) ;
if ( ! V_24 )
return F_112 ( - V_164 ) ;
break;
}
return V_24 ;
}
static int F_138 ( struct V_16 * V_16 , struct V_6 * V_56 )
{
struct V_1 * V_3 ;
int V_185 , V_162 ;
struct V_29 * V_24 = NULL ;
int V_31 ;
T_1 V_30 = V_16 -> V_189 ;
unsigned V_190 = V_56 -> V_131 ;
F_139 ( V_16 , V_56 ) ;
V_191:
V_162 = F_8 ( V_56 ) ;
if ( V_162 )
return - V_10 ;
V_185 = V_56 -> V_131 & V_192 ;
V_31 = - 1 ;
V_162 = 0 ;
F_32 ( & V_41 ) ;
F_53 () ;
V_3 = F_134 ( V_30 , V_56 ) ;
if ( F_140 ( V_3 ) ) {
V_162 = F_141 ( V_3 ) ;
goto V_193;
} else if ( ! V_3 ) {
V_24 = F_135 ( V_30 , V_56 , & V_185 , & V_31 ) ;
if ( F_140 ( V_24 ) ) {
V_162 = F_141 ( V_24 ) ;
goto V_193;
}
V_3 = F_101 ( V_24 , V_16 , V_31 ) ;
if ( F_140 ( V_3 ) ) {
V_162 = F_141 ( V_3 ) ;
goto V_193;
}
}
if ( V_3 ) {
V_162 = F_108 ( V_3 ) ;
if ( V_162 )
V_3 = F_112 ( V_162 ) ;
} else
V_3 = F_110 ( V_24 , V_31 ) ;
F_33 ( & V_41 ) ;
if ( V_24 )
F_122 ( V_24 ) ;
if ( F_140 ( V_3 ) ) {
F_69 () ;
V_162 = F_141 ( V_3 ) ;
goto V_194;
}
F_10 ( V_3 , V_56 ) ;
F_23 ( V_3 , V_174 ) ;
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 )
V_185 = 1 ;
#ifdef F_74
F_20 ( V_106 L_31 , V_174 , V_3 -> V_15 ) ;
#endif
if ( V_3 -> V_42 -> V_195 )
V_162 = V_3 -> V_42 -> V_195 ( V_3 , V_56 ) ;
else
V_162 = - V_164 ;
V_56 -> V_131 = V_190 ;
if ( ! V_162 && F_48 ( V_196 , & V_3 -> V_44 ) &&
! F_142 ( V_197 ) )
V_162 = - V_198 ;
if ( V_162 ) {
#ifdef F_74
F_20 ( V_106 L_32 , V_174 ,
V_162 , V_3 -> V_15 ) ;
#endif
F_69 () ;
F_128 ( V_16 , V_56 ) ;
if ( V_162 != - V_54 )
return V_162 ;
if ( F_94 ( V_46 ) )
return V_162 ;
F_131 () ;
F_53 () ;
if ( V_56 -> V_82 == & V_86 )
V_56 -> V_82 = & V_199 ;
F_69 () ;
goto V_191;
}
F_69 () ;
F_32 ( & V_41 ) ;
F_53 () ;
F_59 ( & V_46 -> V_89 -> V_90 ) ;
if ( ! V_185 &&
V_46 -> signal -> V_91 &&
! V_46 -> signal -> V_3 &&
V_3 -> V_88 == NULL )
F_143 ( V_46 , V_3 ) ;
F_60 ( & V_46 -> V_89 -> V_90 ) ;
F_69 () ;
F_33 ( & V_41 ) ;
return 0 ;
V_193:
F_69 () ;
F_33 ( & V_41 ) ;
if ( ! F_144 ( V_24 ) )
F_122 ( V_24 ) ;
V_194:
F_14 ( V_56 ) ;
return V_162 ;
}
static unsigned int F_145 ( struct V_6 * V_56 , T_6 * V_57 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
struct V_68 * V_69 ;
int V_45 = 0 ;
if ( F_18 ( V_3 , V_56 -> V_121 . V_122 -> V_123 , L_33 ) )
return 0 ;
V_69 = F_88 ( V_3 ) ;
if ( V_69 -> V_42 -> V_200 )
V_45 = ( V_69 -> V_42 -> V_200 ) ( V_3 , V_56 , V_57 ) ;
F_50 ( V_69 ) ;
return V_45 ;
}
static int F_55 ( int V_201 , struct V_6 * V_56 , int V_202 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
unsigned long V_44 ;
int V_162 = 0 ;
if ( F_18 ( V_3 , V_56 -> V_121 . V_122 -> V_123 , L_34 ) )
goto V_51;
V_162 = F_146 ( V_201 , V_56 , V_202 , & V_3 -> V_203 ) ;
if ( V_162 <= 0 )
goto V_51;
if ( V_202 ) {
enum V_204 type ;
struct V_107 * V_107 ;
if ( ! F_129 ( & V_3 -> V_116 ) )
V_3 -> V_205 = 1 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_48 ) {
V_107 = V_3 -> V_48 ;
type = V_206 ;
} else {
V_107 = F_147 ( V_46 ) ;
type = V_207 ;
}
F_63 ( V_107 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
V_162 = F_148 ( V_56 , V_107 , type , 0 ) ;
F_62 ( V_107 ) ;
if ( V_162 )
goto V_51;
} else {
if ( ! V_3 -> V_203 && ! F_129 ( & V_3 -> V_116 ) )
V_3 -> V_205 = V_208 ;
}
V_162 = 0 ;
V_51:
return V_162 ;
}
static int F_149 ( int V_201 , struct V_6 * V_56 , int V_202 )
{
int V_162 ;
F_53 () ;
V_162 = F_55 ( V_201 , V_56 , V_202 ) ;
F_69 () ;
return V_162 ;
}
static int F_150 ( struct V_1 * V_3 , char T_3 * V_22 )
{
char V_209 , V_210 = 0 ;
struct V_68 * V_69 ;
if ( ( V_46 -> signal -> V_3 != V_3 ) && ! F_142 ( V_197 ) )
return - V_211 ;
if ( F_151 ( V_209 , V_22 ) )
return - V_137 ;
F_152 ( V_3 , V_209 ) ;
V_69 = F_88 ( V_3 ) ;
V_69 -> V_42 -> V_212 ( V_3 , & V_209 , & V_210 , 1 ) ;
F_50 ( V_69 ) ;
return 0 ;
}
static int F_153 ( struct V_1 * V_3 , struct V_213 T_3 * V_65 )
{
int V_214 ;
F_32 ( & V_3 -> V_215 ) ;
V_214 = F_154 ( V_65 , & V_3 -> V_213 , sizeof( * V_65 ) ) ;
F_33 ( & V_3 -> V_215 ) ;
return V_214 ? - V_137 : 0 ;
}
int F_155 ( struct V_1 * V_3 , struct V_213 * V_216 )
{
struct V_107 * V_48 ;
unsigned long V_44 ;
F_32 ( & V_3 -> V_215 ) ;
if ( ! memcmp ( V_216 , & V_3 -> V_213 , sizeof( * V_216 ) ) )
goto V_217;
F_35 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_63 ( V_3 -> V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
if ( V_48 )
F_40 ( V_48 , V_218 , 1 ) ;
F_62 ( V_48 ) ;
V_3 -> V_213 = * V_216 ;
V_217:
F_33 ( & V_3 -> V_215 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_3 , struct V_213 T_3 * V_65 )
{
struct V_213 V_219 ;
if ( F_93 ( & V_219 , V_65 , sizeof( * V_65 ) ) )
return - V_137 ;
if ( V_3 -> V_42 -> V_220 )
return V_3 -> V_42 -> V_220 ( V_3 , & V_219 ) ;
else
return F_155 ( V_3 , & V_219 ) ;
}
static int F_157 ( struct V_6 * V_6 )
{
if ( ! F_142 ( V_197 ) )
return - V_211 ;
if ( V_6 -> V_82 -> V_83 == V_84 ) {
struct V_6 * V_74 ;
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
return - V_198 ;
}
F_97 ( V_6 ) ;
V_80 = V_6 ;
F_13 ( & V_79 ) ;
return 0 ;
}
static int F_158 ( struct V_6 * V_6 , int T_3 * V_22 )
{
int V_221 ;
if ( F_151 ( V_221 , V_22 ) )
return - V_137 ;
F_11 ( & V_6 -> V_222 ) ;
if ( V_221 )
V_6 -> V_131 |= V_184 ;
else
V_6 -> V_131 &= ~ V_184 ;
F_13 ( & V_6 -> V_222 ) ;
return 0 ;
}
static int F_159 ( struct V_1 * V_3 , int V_65 )
{
int V_45 = 0 ;
if ( V_46 -> signal -> V_91 && ( F_83 ( V_46 ) == V_3 -> V_88 ) )
return V_45 ;
F_32 ( & V_41 ) ;
if ( ! V_46 -> signal -> V_91 || V_46 -> signal -> V_3 ) {
V_45 = - V_211 ;
goto V_223;
}
if ( V_3 -> V_88 ) {
if ( V_65 == 1 && F_142 ( V_197 ) ) {
F_57 ( & V_87 ) ;
F_80 ( V_3 -> V_88 ) ;
F_65 ( & V_87 ) ;
} else {
V_45 = - V_211 ;
goto V_223;
}
}
F_160 ( V_46 , V_3 ) ;
V_223:
F_33 ( & V_41 ) ;
return V_45 ;
}
struct V_107 * F_161 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
struct V_107 * V_48 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_63 ( V_3 -> V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
return V_48 ;
}
static int F_162 ( struct V_1 * V_3 , struct V_1 * V_224 , T_7 T_3 * V_22 )
{
struct V_107 * V_107 ;
int V_45 ;
if ( V_3 == V_224 && V_46 -> signal -> V_3 != V_224 )
return - V_67 ;
V_107 = F_161 ( V_224 ) ;
V_45 = F_163 ( F_164 ( V_107 ) , V_22 ) ;
F_62 ( V_107 ) ;
return V_45 ;
}
static int F_165 ( struct V_1 * V_3 , struct V_1 * V_224 , T_7 T_3 * V_22 )
{
struct V_107 * V_48 ;
T_7 V_225 ;
int V_162 = F_34 ( V_224 ) ;
unsigned long V_44 ;
if ( V_162 == - V_52 )
return - V_67 ;
if ( V_162 )
return V_162 ;
if ( ! V_46 -> signal -> V_3 ||
( V_46 -> signal -> V_3 != V_224 ) ||
( V_224 -> V_88 != F_83 ( V_46 ) ) )
return - V_67 ;
if ( F_151 ( V_225 , V_22 ) )
return - V_137 ;
if ( V_225 < 0 )
return - V_226 ;
F_166 () ;
V_48 = F_167 ( V_225 ) ;
V_162 = - V_227 ;
if ( ! V_48 )
goto V_49;
V_162 = - V_211 ;
if ( F_168 ( V_48 ) != F_83 ( V_46 ) )
goto V_49;
V_162 = 0 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
F_62 ( V_224 -> V_48 ) ;
V_224 -> V_48 = F_63 ( V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
V_49:
F_169 () ;
return V_162 ;
}
static int F_170 ( struct V_1 * V_3 , struct V_1 * V_224 , T_7 T_3 * V_22 )
{
if ( V_3 == V_224 && V_46 -> signal -> V_3 != V_224 )
return - V_67 ;
if ( ! V_224 -> V_88 )
return - V_67 ;
return F_163 ( F_164 ( V_224 -> V_88 ) , V_22 ) ;
}
static int F_171 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_228 ;
int V_45 ;
if ( F_151 ( V_228 , V_22 ) )
return - V_137 ;
V_45 = F_172 ( V_3 , V_228 ) ;
return V_45 ;
}
static int F_173 ( struct V_1 * V_3 , unsigned int V_229 )
{
int V_162 ;
if ( V_3 -> V_42 -> V_230 == NULL )
return 0 ;
if ( V_3 -> V_24 -> V_44 & V_231 )
V_162 = V_3 -> V_42 -> V_230 ( V_3 , V_229 ) ;
else {
if ( F_91 ( V_3 , 0 ) < 0 )
return - V_232 ;
V_162 = V_3 -> V_42 -> V_230 ( V_3 , - 1 ) ;
if ( V_162 )
goto V_51;
if ( ! F_94 ( V_46 ) )
F_174 ( V_229 ) ;
V_162 = V_3 -> V_42 -> V_230 ( V_3 , 0 ) ;
V_51:
F_90 ( V_3 ) ;
if ( F_94 ( V_46 ) )
V_162 = - V_232 ;
}
return V_162 ;
}
static int F_175 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_162 = - V_226 ;
if ( V_3 -> V_42 -> V_233 ) {
V_162 = V_3 -> V_42 -> V_233 ( V_3 ) ;
if ( V_162 >= 0 )
V_162 = F_163 ( V_162 , V_22 ) ;
}
return V_162 ;
}
static int F_176 ( struct V_1 * V_3 , unsigned int V_64 ,
unsigned T_3 * V_22 )
{
int V_162 ;
unsigned int V_234 , V_235 , V_236 ;
if ( V_3 -> V_42 -> V_237 == NULL )
return - V_226 ;
V_162 = F_151 ( V_236 , V_22 ) ;
if ( V_162 )
return V_162 ;
V_234 = V_235 = 0 ;
switch ( V_64 ) {
case V_238 :
V_234 = V_236 ;
break;
case V_239 :
V_235 = V_236 ;
break;
case V_240 :
V_234 = V_236 ;
V_235 = ~ V_236 ;
break;
}
V_234 &= V_241 | V_242 | V_243 | V_244 | V_245 ;
V_235 &= V_241 | V_242 | V_243 | V_244 | V_245 ;
return V_3 -> V_42 -> V_237 ( V_3 , V_234 , V_235 ) ;
}
static int F_177 ( struct V_1 * V_3 , void T_3 * V_65 )
{
int V_162 = - V_226 ;
struct V_246 V_247 ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
if ( V_3 -> V_42 -> V_248 )
V_162 = V_3 -> V_42 -> V_248 ( V_3 , & V_247 ) ;
if ( V_162 != 0 )
return V_162 ;
if ( F_154 ( V_65 , & V_247 , sizeof( V_247 ) ) )
return - V_137 ;
return 0 ;
}
struct V_1 * F_178 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 )
V_3 = V_3 -> V_28 ;
return V_3 ;
}
struct V_1 * F_179 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 )
return V_3 ;
return V_3 -> V_28 ;
}
long F_180 ( struct V_6 * V_6 , unsigned int V_64 , unsigned long V_65 )
{
struct V_1 * V_3 = F_7 ( V_6 ) ;
struct V_1 * V_224 ;
void T_3 * V_22 = ( void T_3 * ) V_65 ;
int V_162 ;
struct V_68 * V_69 ;
struct V_16 * V_16 = V_6 -> V_249 -> V_123 ;
if ( F_18 ( V_3 , V_16 , L_35 ) )
return - V_226 ;
V_224 = F_178 ( V_3 ) ;
switch ( V_64 ) {
case V_250 :
case V_251 :
case V_252 :
case V_253 :
case V_254 :
V_162 = F_34 ( V_3 ) ;
if ( V_162 )
return V_162 ;
if ( V_64 != V_252 ) {
F_181 ( V_3 , 0 ) ;
if ( F_94 ( V_46 ) )
return - V_232 ;
}
break;
}
switch ( V_64 ) {
case V_255 :
return F_150 ( V_3 , V_22 ) ;
case V_256 :
return F_153 ( V_224 , V_22 ) ;
case V_257 :
return F_156 ( V_224 , V_22 ) ;
case V_258 :
return V_224 != V_3 ? - V_226 : F_157 ( V_6 ) ;
case V_259 :
return F_158 ( V_6 , V_22 ) ;
case V_260 :
F_54 ( V_196 , & V_3 -> V_44 ) ;
return 0 ;
case V_261 :
F_66 ( V_196 , & V_3 -> V_44 ) ;
return 0 ;
case V_262 :
if ( V_46 -> signal -> V_3 != V_3 )
return - V_67 ;
F_84 () ;
return 0 ;
case V_263 :
return F_159 ( V_3 , V_65 ) ;
case V_264 :
return F_162 ( V_3 , V_224 , V_22 ) ;
case V_66 :
return F_165 ( V_3 , V_224 , V_22 ) ;
case V_265 :
return F_170 ( V_3 , V_224 , V_22 ) ;
case V_266 :
return F_163 ( V_3 -> V_228 -> V_42 -> V_35 , ( int T_3 * ) V_22 ) ;
case V_250 :
return F_171 ( V_3 , V_22 ) ;
case V_267 :
if ( ! F_142 ( V_197 ) )
return - V_211 ;
F_76 ( V_3 ) ;
return 0 ;
case V_268 :
{
unsigned int V_45 = F_182 ( F_183 ( V_224 ) ) ;
return F_163 ( V_45 , ( unsigned int T_3 * ) V_22 ) ;
}
case V_251 :
if ( V_3 -> V_42 -> V_230 )
return V_3 -> V_42 -> V_230 ( V_3 , - 1 ) ;
return 0 ;
case V_252 :
if ( V_3 -> V_42 -> V_230 )
return V_3 -> V_42 -> V_230 ( V_3 , 0 ) ;
return 0 ;
case V_253 :
if ( ! V_65 )
return F_173 ( V_3 , 250 ) ;
return 0 ;
case V_254 :
return F_173 ( V_3 , V_65 ? V_65 * 100 : 250 ) ;
case V_269 :
return F_175 ( V_3 , V_22 ) ;
case V_240 :
case V_239 :
case V_238 :
return F_176 ( V_3 , V_64 , V_22 ) ;
case V_270 :
V_162 = F_177 ( V_3 , V_22 ) ;
if ( V_162 != - V_226 )
return V_162 ;
break;
case V_271 :
switch ( V_65 ) {
case V_272 :
case V_273 :
F_184 ( V_3 ) ;
break;
}
break;
}
if ( V_3 -> V_42 -> V_274 ) {
V_162 = ( V_3 -> V_42 -> V_274 ) ( V_3 , V_64 , V_65 ) ;
if ( V_162 != - V_275 )
return V_162 ;
}
V_69 = F_88 ( V_3 ) ;
V_162 = - V_226 ;
if ( V_69 -> V_42 -> V_274 ) {
V_162 = V_69 -> V_42 -> V_274 ( V_3 , V_6 , V_64 , V_65 ) ;
if ( V_162 == - V_275 )
V_162 = - V_226 ;
}
F_50 ( V_69 ) ;
return V_162 ;
}
static long F_185 ( struct V_6 * V_6 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_16 * V_16 = V_6 -> V_249 -> V_123 ;
struct V_1 * V_3 = F_7 ( V_6 ) ;
struct V_68 * V_69 ;
int V_162 = - V_275 ;
if ( F_18 ( V_3 , V_16 , L_35 ) )
return - V_226 ;
if ( V_3 -> V_42 -> V_276 ) {
V_162 = ( V_3 -> V_42 -> V_276 ) ( V_3 , V_64 , V_65 ) ;
if ( V_162 != - V_275 )
return V_162 ;
}
V_69 = F_88 ( V_3 ) ;
if ( V_69 -> V_42 -> V_276 )
V_162 = V_69 -> V_42 -> V_276 ( V_3 , V_6 , V_64 , V_65 ) ;
else
V_162 = F_186 ( V_3 , V_6 , V_64 , V_65 ) ;
F_50 ( V_69 ) ;
return V_162 ;
}
void F_187 ( struct V_1 * V_3 )
{
#ifdef F_188
F_73 ( V_3 ) ;
#else
struct V_75 * V_277 , * V_22 ;
struct V_107 * V_88 ;
int V_120 ;
struct V_6 * V_56 ;
struct V_278 * V_279 ;
if ( ! V_3 )
return;
V_88 = V_3 -> V_88 ;
F_189 ( V_3 ) ;
F_190 ( V_3 ) ;
F_57 ( & V_87 ) ;
F_58 (session, PIDTYPE_SID, p) {
F_20 ( V_280 L_36
L_37 ,
F_191 ( V_22 ) , V_22 -> V_281 ) ;
F_192 ( V_282 , V_22 , 1 ) ;
} F_64 ( V_88 , V_96 , V_22 ) ;
F_193 (g, p) {
if ( V_22 -> signal -> V_3 == V_3 ) {
F_20 ( V_280 L_36
L_37 ,
F_191 ( V_22 ) , V_22 -> V_281 ) ;
F_192 ( V_282 , V_22 , 1 ) ;
continue;
}
F_194 ( V_22 ) ;
if ( V_22 -> V_283 ) {
F_11 ( & V_22 -> V_283 -> V_284 ) ;
V_279 = F_195 ( V_22 -> V_283 ) ;
for ( V_120 = 0 ; V_120 < V_279 -> V_285 ; V_120 ++ ) {
V_56 = F_196 ( V_22 -> V_283 , V_120 ) ;
if ( ! V_56 )
continue;
if ( V_56 -> V_82 -> V_125 == F_87 &&
F_7 ( V_56 ) == V_3 ) {
F_20 ( V_280 L_36
L_38 ,
F_191 ( V_22 ) , V_22 -> V_281 , V_120 ) ;
F_197 ( V_282 , V_22 ) ;
break;
}
}
F_13 ( & V_22 -> V_283 -> V_284 ) ;
}
F_198 ( V_22 ) ;
} F_199 ( V_277 , V_22 ) ;
F_65 ( & V_87 ) ;
#endif
}
static void F_200 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_72 ( V_104 , struct V_1 , V_286 ) ;
F_187 ( V_3 ) ;
}
void F_201 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
F_75 ( & V_3 -> V_286 ) ;
}
static int F_202 ( struct V_30 * V_4 , void * V_287 )
{
T_1 * V_288 = V_287 ;
return V_4 -> V_288 == * V_288 ;
}
static struct V_30 * F_203 ( struct V_1 * V_3 )
{
T_1 V_288 = F_183 ( V_3 ) ;
return F_204 ( V_289 , NULL , & V_288 , F_202 ) ;
}
void F_113 ( struct V_1 * V_3 ,
struct V_29 * V_24 , int V_147 )
{
memset ( V_3 , 0 , sizeof( struct V_1 ) ) ;
F_205 ( & V_3 -> V_171 ) ;
V_3 -> V_19 = V_20 ;
F_206 ( V_3 ) ;
V_3 -> V_88 = NULL ;
V_3 -> V_48 = NULL ;
V_3 -> V_290 = V_291 ;
F_207 ( V_3 ) ;
F_208 ( & V_3 -> V_215 ) ;
F_208 ( & V_3 -> V_160 ) ;
F_209 ( & V_3 -> V_72 ) ;
F_209 ( & V_3 -> V_116 ) ;
F_125 ( & V_3 -> V_105 , F_71 ) ;
F_208 ( & V_3 -> V_292 ) ;
F_208 ( & V_3 -> V_140 ) ;
F_208 ( & V_3 -> V_293 ) ;
F_208 ( & V_3 -> V_294 ) ;
F_210 ( & V_3 -> F_57 ) ;
F_210 ( & V_3 -> V_47 ) ;
F_211 ( & V_3 -> V_13 ) ;
F_125 ( & V_3 -> V_286 , F_200 ) ;
V_3 -> V_24 = V_24 ;
V_3 -> V_42 = V_24 -> V_42 ;
V_3 -> V_31 = V_147 ;
F_100 ( V_24 , V_147 , V_3 -> V_15 ) ;
V_3 -> V_4 = F_203 ( V_3 ) ;
}
void F_115 ( struct V_1 * V_3 )
{
F_212 ( V_3 ) ;
}
int F_213 ( struct V_1 * V_3 , unsigned char V_209 )
{
if ( V_3 -> V_42 -> V_295 )
return V_3 -> V_42 -> V_295 ( V_3 , V_209 ) ;
return V_3 -> V_42 -> V_83 ( V_3 , & V_209 , 1 ) ;
}
struct V_30 * F_214 ( struct V_29 * V_24 , unsigned V_31 ,
struct V_30 * V_30 )
{
char V_15 [ 64 ] ;
T_1 V_4 = F_28 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ;
if ( V_31 >= V_24 -> V_35 ) {
F_20 ( V_143 L_39
L_40 , V_31 ) ;
return F_112 ( - V_226 ) ;
}
if ( V_24 -> type == V_25 )
F_99 ( V_24 , V_31 , V_15 ) ;
else
F_100 ( V_24 , V_31 , V_15 ) ;
return F_215 ( V_289 , V_30 , V_4 , NULL , V_15 ) ;
}
void F_216 ( struct V_29 * V_24 , unsigned V_31 )
{
F_217 ( V_289 ,
F_28 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ) ;
}
struct V_29 * F_218 ( int V_296 , struct V_297 * V_163 )
{
struct V_29 * V_24 ;
V_24 = F_2 ( sizeof( struct V_29 ) , V_2 ) ;
if ( V_24 ) {
F_205 ( & V_24 -> V_171 ) ;
V_24 -> V_19 = V_298 ;
V_24 -> V_35 = V_296 ;
V_24 -> V_163 = V_163 ;
}
return V_24 ;
}
static void F_219 ( struct V_171 * V_171 )
{
struct V_29 * V_24 = F_72 ( V_171 , struct V_29 , V_171 ) ;
int V_120 ;
struct V_150 * V_151 ;
void * V_22 ;
if ( V_24 -> V_44 & V_299 ) {
for ( V_120 = 0 ; V_120 < V_24 -> V_35 ; V_120 ++ ) {
V_151 = V_24 -> V_152 [ V_120 ] ;
if ( V_151 ) {
V_24 -> V_152 [ V_120 ] = NULL ;
F_5 ( V_151 ) ;
}
if ( ! ( V_24 -> V_44 & V_300 ) )
F_216 ( V_24 , V_120 ) ;
}
V_22 = V_24 -> V_149 ;
F_220 ( V_24 ) ;
V_24 -> V_149 = NULL ;
V_24 -> V_152 = NULL ;
F_5 ( V_22 ) ;
F_221 ( & V_24 -> V_301 ) ;
}
F_5 ( V_24 ) ;
}
void F_122 ( struct V_29 * V_24 )
{
F_126 ( & V_24 -> V_171 , F_219 ) ;
}
void F_222 ( struct V_29 * V_24 ,
const struct V_302 * V_303 )
{
V_24 -> V_42 = V_303 ;
}
void F_223 ( struct V_29 * V_304 )
{
F_122 ( V_304 ) ;
}
int F_224 ( struct V_29 * V_24 )
{
int error ;
int V_120 ;
T_1 V_4 ;
void * * V_22 = NULL ;
struct V_30 * V_304 ;
if ( ! ( V_24 -> V_44 & V_175 ) && V_24 -> V_35 ) {
V_22 = F_2 ( V_24 -> V_35 * 2 * sizeof( void * ) , V_2 ) ;
if ( ! V_22 )
return - V_10 ;
}
if ( ! V_24 -> V_33 ) {
error = F_225 ( & V_4 , V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_15 ) ;
if ( ! error ) {
V_24 -> V_33 = F_226 ( V_4 ) ;
V_24 -> V_34 = F_227 ( V_4 ) ;
}
} else {
V_4 = F_28 ( V_24 -> V_33 , V_24 -> V_34 ) ;
error = F_228 ( V_4 , V_24 -> V_35 , V_24 -> V_15 ) ;
}
if ( error < 0 ) {
F_5 ( V_22 ) ;
return error ;
}
if ( V_22 ) {
V_24 -> V_149 = (struct V_1 * * ) V_22 ;
V_24 -> V_152 = (struct V_150 * * ) ( V_22 + V_24 -> V_35 ) ;
} else {
V_24 -> V_149 = NULL ;
V_24 -> V_152 = NULL ;
}
F_229 ( & V_24 -> V_301 , & V_199 ) ;
V_24 -> V_301 . V_163 = V_24 -> V_163 ;
error = F_230 ( & V_24 -> V_301 , V_4 , V_24 -> V_35 ) ;
if ( error ) {
F_231 ( V_4 , V_24 -> V_35 ) ;
V_24 -> V_149 = NULL ;
V_24 -> V_152 = NULL ;
F_5 ( V_22 ) ;
return error ;
}
F_32 ( & V_41 ) ;
F_12 ( & V_24 -> V_305 , & V_305 ) ;
F_33 ( & V_41 ) ;
if ( ! ( V_24 -> V_44 & V_300 ) ) {
for ( V_120 = 0 ; V_120 < V_24 -> V_35 ; V_120 ++ ) {
V_304 = F_214 ( V_24 , V_120 , NULL ) ;
if ( F_140 ( V_304 ) ) {
error = F_141 ( V_304 ) ;
goto V_214;
}
}
}
F_232 ( V_24 ) ;
V_24 -> V_44 |= V_299 ;
return 0 ;
V_214:
for ( V_120 -- ; V_120 >= 0 ; V_120 -- )
F_216 ( V_24 , V_120 ) ;
F_32 ( & V_41 ) ;
F_16 ( & V_24 -> V_305 ) ;
F_33 ( & V_41 ) ;
F_231 ( V_4 , V_24 -> V_35 ) ;
V_24 -> V_149 = NULL ;
V_24 -> V_152 = NULL ;
F_5 ( V_22 ) ;
return error ;
}
int F_233 ( struct V_29 * V_24 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_231 ( F_28 ( V_24 -> V_33 , V_24 -> V_34 ) ,
V_24 -> V_35 ) ;
F_32 ( & V_41 ) ;
F_16 ( & V_24 -> V_305 ) ;
F_33 ( & V_41 ) ;
return 0 ;
}
T_1 F_183 ( struct V_1 * V_3 )
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
static void F_143 ( struct V_75 * V_111 , struct V_1 * V_3 )
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
F_20 ( V_106 L_41 ) ;
F_67 ( V_111 -> signal -> V_3 ) ;
}
}
F_62 ( V_111 -> signal -> V_95 ) ;
V_111 -> signal -> V_3 = F_234 ( V_3 ) ;
V_111 -> signal -> V_95 = NULL ;
}
static void F_160 ( struct V_75 * V_111 , struct V_1 * V_3 )
{
F_59 ( & V_111 -> V_89 -> V_90 ) ;
F_143 ( V_111 , V_3 ) ;
F_60 ( & V_111 -> V_89 -> V_90 ) ;
}
struct V_1 * F_78 ( void )
{
struct V_1 * V_3 ;
unsigned long V_44 ;
F_35 ( & V_46 -> V_89 -> V_90 , V_44 ) ;
V_3 = F_234 ( V_46 -> signal -> V_3 ) ;
F_37 ( & V_46 -> V_89 -> V_90 , V_44 ) ;
return V_3 ;
}
void F_235 ( struct V_306 * V_307 )
{
* V_307 = V_199 ;
}
void T_8 F_236 ( void )
{
T_9 * V_308 ;
F_237 () ;
V_308 = V_309 ;
while ( V_308 < V_310 ) {
(* V_308)() ;
V_308 ++ ;
}
}
static char * F_238 ( struct V_30 * V_4 , T_10 * V_311 )
{
if ( ! V_311 )
return NULL ;
if ( V_4 -> V_288 == F_28 ( V_182 , 0 ) ||
V_4 -> V_288 == F_28 ( V_182 , 2 ) )
* V_311 = 0666 ;
return NULL ;
}
static int T_8 F_239 ( void )
{
V_289 = F_240 ( V_312 , L_16 ) ;
if ( F_140 ( V_289 ) )
return F_141 ( V_289 ) ;
V_289 -> V_313 = F_238 ;
return 0 ;
}
static T_2 F_241 ( struct V_30 * V_4 ,
struct V_314 * V_315 , char * V_14 )
{
struct V_316 * V_317 [ 16 ] ;
int V_120 = 0 ;
struct V_316 * V_318 ;
T_2 V_23 = 0 ;
F_242 () ;
F_243 (c) {
if ( ! V_318 -> V_30 )
continue;
if ( ! V_318 -> V_83 )
continue;
if ( ( V_318 -> V_44 & V_319 ) == 0 )
continue;
V_317 [ V_120 ++ ] = V_318 ;
if ( V_120 >= F_244 ( V_317 ) )
break;
}
while ( V_120 -- )
V_23 += sprintf ( V_14 + V_23 , L_42 ,
V_317 [ V_120 ] -> V_15 , V_317 [ V_120 ] -> V_31 , V_120 ? ' ' : '\n' ) ;
F_245 () ;
return V_23 ;
}
void F_246 ( void )
{
if ( V_320 )
F_247 ( & V_320 -> V_321 , NULL , L_43 ) ;
}
int T_8 F_248 ( void )
{
F_229 ( & V_322 , & V_199 ) ;
if ( F_230 ( & V_322 , F_28 ( V_182 , 0 ) , 1 ) ||
F_228 ( F_28 ( V_182 , 0 ) , 1 , L_44 ) < 0 )
F_249 ( L_45 ) ;
F_215 ( V_289 , NULL , F_28 ( V_182 , 0 ) , NULL , L_16 ) ;
F_229 ( & V_323 , & V_324 ) ;
if ( F_230 ( & V_323 , F_28 ( V_182 , 1 ) , 1 ) ||
F_228 ( F_28 ( V_182 , 1 ) , 1 , L_46 ) < 0 )
F_249 ( L_47 ) ;
V_320 = F_215 ( V_289 , NULL , F_28 ( V_182 , 1 ) , NULL ,
L_48 ) ;
if ( F_140 ( V_320 ) )
V_320 = NULL ;
else
F_109 ( F_250 ( V_320 , & V_325 ) < 0 ) ;
#ifdef F_136
F_251 ( & V_324 ) ;
#endif
return 0 ;
}
