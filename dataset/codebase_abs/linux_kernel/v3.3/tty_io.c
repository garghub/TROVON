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
F_53 () ;
F_82 ( 0 ) ;
F_69 () ;
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
struct V_1 * V_3 ;
if ( V_24 -> V_42 -> V_148 )
return V_24 -> V_42 -> V_148 ( V_24 , V_16 , V_147 ) ;
V_3 = V_24 -> V_149 [ V_147 ] ;
return V_3 ;
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
static int F_105 ( struct V_29 * V_24 ,
struct V_1 * V_3 )
{
int V_147 = V_3 -> V_31 ;
int V_45 ;
if ( V_24 -> V_42 -> V_157 ) {
V_45 = V_24 -> V_42 -> V_157 ( V_24 , V_3 ) ;
return V_45 ;
}
if ( F_102 ( V_3 ) == 0 ) {
F_29 ( V_24 ) ;
V_3 -> V_23 ++ ;
V_24 -> V_149 [ V_147 ] = V_3 ;
return 0 ;
}
return - V_10 ;
}
void F_106 ( struct V_29 * V_24 , struct V_1 * V_3 )
{
if ( V_24 -> V_42 -> remove )
V_24 -> V_42 -> remove ( V_24 , V_3 ) ;
else
V_24 -> V_149 [ V_3 -> V_31 ] = NULL ;
}
static int F_107 ( struct V_1 * V_3 )
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
V_3 -> V_24 = V_24 ;
F_32 ( & V_3 -> V_160 ) ;
F_108 ( ! F_48 ( V_161 , & V_3 -> V_44 ) ) ;
F_33 ( & V_3 -> V_160 ) ;
return 0 ;
}
struct V_1 * F_109 ( struct V_29 * V_24 , int V_147 ,
int V_162 )
{
struct V_1 * V_3 ;
int V_163 ;
if ( V_24 -> V_26 == V_159 &&
( V_24 -> V_44 & V_164 ) && ! V_162 ) {
return F_110 ( - V_52 ) ;
}
if ( ! F_111 ( V_24 -> V_165 ) )
return F_110 ( - V_166 ) ;
V_3 = F_1 () ;
if ( ! V_3 ) {
V_163 = - V_10 ;
goto V_167;
}
F_112 ( V_3 , V_24 , V_147 ) ;
V_163 = F_105 ( V_24 , V_3 ) ;
if ( V_163 < 0 )
goto V_168;
V_163 = F_113 ( V_3 , V_3 -> V_28 ) ;
if ( V_163 )
goto V_169;
return V_3 ;
V_168:
F_114 ( V_3 ) ;
F_3 ( V_3 ) ;
V_167:
F_115 ( V_24 -> V_165 ) ;
return F_110 ( V_163 ) ;
V_169:
F_116 ( V_170 L_18
L_19 , V_147 ) ;
F_117 ( V_3 , V_147 ) ;
return F_110 ( V_163 ) ;
}
void F_118 ( struct V_1 * V_3 )
{
struct V_150 * V_151 ;
int V_147 = V_3 -> V_31 ;
if ( V_3 -> V_24 -> V_44 & V_171 ) {
V_151 = V_3 -> V_152 ;
V_3 -> V_24 -> V_152 [ V_147 ] = NULL ;
F_5 ( V_151 ) ;
}
}
void F_119 ( struct V_1 * V_3 )
{
F_106 ( V_3 -> V_24 , V_3 ) ;
F_118 ( V_3 ) ;
}
static void F_120 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_72 ( V_104 , struct V_1 , V_105 ) ;
struct V_29 * V_24 = V_3 -> V_24 ;
if ( V_3 -> V_42 -> V_172 )
V_3 -> V_42 -> V_172 ( V_3 ) ;
V_3 -> V_19 = 0 ;
F_121 ( V_24 ) ;
F_115 ( V_24 -> V_165 ) ;
F_11 ( & V_11 ) ;
F_122 ( & V_3 -> V_13 ) ;
F_13 ( & V_11 ) ;
F_62 ( V_3 -> V_48 ) ;
F_62 ( V_3 -> V_88 ) ;
F_3 ( V_3 ) ;
}
static void F_123 ( struct V_173 * V_173 )
{
struct V_1 * V_3 = F_72 ( V_173 , struct V_1 , V_173 ) ;
if ( V_3 -> V_42 -> V_174 )
V_3 -> V_42 -> V_174 ( V_3 ) ;
else
F_119 ( V_3 ) ;
F_124 ( & V_3 -> V_105 , F_120 ) ;
F_75 ( & V_3 -> V_105 ) ;
}
void F_67 ( struct V_1 * V_3 )
{
if ( V_3 )
F_125 ( & V_3 -> V_173 , F_123 ) ;
}
static void F_117 ( struct V_1 * V_3 , int V_147 )
{
F_108 ( V_3 -> V_31 != V_147 ) ;
if ( V_3 -> V_28 )
F_67 ( V_3 -> V_28 ) ;
F_67 ( V_3 ) ;
}
static int F_126 ( struct V_1 * V_3 , struct V_1 * V_175 ,
int V_147 )
{
#ifdef F_19
if ( V_147 < 0 || V_147 >= V_3 -> V_24 -> V_35 ) {
F_20 ( V_106 L_20 ,
V_176 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_44 & V_164 )
return 0 ;
if ( V_3 != V_3 -> V_24 -> V_149 [ V_147 ] ) {
F_20 ( V_106 L_21 ,
V_176 , V_147 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_3 -> V_152 != V_3 -> V_24 -> V_152 [ V_147 ] ) {
F_20 ( V_106 L_22 ,
V_176 , V_147 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_3 -> V_24 -> V_177 ) {
if ( V_175 != V_3 -> V_24 -> V_177 -> V_149 [ V_147 ] ) {
F_20 ( V_106 L_23 ,
V_176 , V_147 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_175 -> V_152 != V_3 -> V_24 -> V_177 -> V_152 [ V_147 ] ) {
F_20 ( V_106 L_24 ,
V_176 , V_147 , V_3 -> V_15 ) ;
return - 1 ;
}
if ( V_175 -> V_28 != V_3 ) {
F_20 ( V_106 L_25 , V_176 ) ;
return - 1 ;
}
}
#endif
return 0 ;
}
int F_127 ( struct V_16 * V_16 , struct V_6 * V_56 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
struct V_1 * V_175 ;
int V_178 , V_179 , V_180 , V_181 ;
int V_182 ;
int V_147 ;
char V_14 [ 64 ] ;
if ( F_18 ( V_3 , V_16 , V_176 ) )
return 0 ;
F_53 () ;
F_23 ( V_3 , V_176 ) ;
F_55 ( - 1 , V_56 , 0 ) ;
V_147 = V_3 -> V_31 ;
V_178 = ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 ) ;
V_182 = ( V_3 -> V_24 -> V_44 & V_164 ) != 0 ;
V_175 = V_3 -> V_28 ;
if ( F_126 ( V_3 , V_175 , V_147 ) ) {
F_69 () ;
return 0 ;
}
#ifdef F_74
F_20 ( V_106 L_26 , V_176 ,
F_17 ( V_3 , V_14 ) , V_3 -> V_23 ) ;
#endif
if ( V_3 -> V_42 -> V_100 )
V_3 -> V_42 -> V_100 ( V_3 , V_56 ) ;
F_69 () ;
while ( 1 ) {
F_32 ( & V_41 ) ;
F_53 () ;
V_179 = V_3 -> V_23 <= 1 ;
V_180 = V_175 &&
( V_175 -> V_23 <= ( V_178 ? 1 : 0 ) ) ;
V_181 = 0 ;
if ( V_179 ) {
if ( F_128 ( & V_3 -> V_116 ) ) {
F_129 ( & V_3 -> V_116 , V_58 ) ;
V_181 ++ ;
}
if ( F_128 ( & V_3 -> V_72 ) ) {
F_129 ( & V_3 -> V_72 , V_59 ) ;
V_181 ++ ;
}
}
if ( V_180 ) {
if ( F_128 ( & V_175 -> V_116 ) ) {
F_129 ( & V_175 -> V_116 , V_58 ) ;
V_181 ++ ;
}
if ( F_128 ( & V_175 -> V_72 ) ) {
F_129 ( & V_175 -> V_72 , V_59 ) ;
V_181 ++ ;
}
}
if ( ! V_181 )
break;
F_20 ( V_18 L_27 ,
V_176 , F_17 ( V_3 , V_14 ) ) ;
F_69 () ;
F_33 ( & V_41 ) ;
F_130 () ;
}
if ( V_178 ) {
if ( -- V_175 -> V_23 < 0 ) {
F_20 ( V_18 L_28 ,
V_176 , V_175 -> V_23 , F_17 ( V_175 , V_14 ) ) ;
V_175 -> V_23 = 0 ;
}
}
if ( -- V_3 -> V_23 < 0 ) {
F_20 ( V_18 L_29 ,
V_176 , V_3 -> V_23 , F_17 ( V_3 , V_14 ) ) ;
V_3 -> V_23 = 0 ;
}
F_15 ( V_56 ) ;
if ( V_179 )
F_54 ( V_141 , & V_3 -> V_44 ) ;
if ( V_180 )
F_54 ( V_141 , & V_175 -> V_44 ) ;
if ( V_179 || V_180 ) {
F_57 ( & V_87 ) ;
F_80 ( V_3 -> V_88 ) ;
if ( V_175 )
F_80 ( V_175 -> V_88 ) ;
F_65 ( & V_87 ) ;
}
F_33 ( & V_41 ) ;
if ( ! V_179 || ( V_175 && ! V_180 ) ) {
F_69 () ;
return 0 ;
}
#ifdef F_74
F_20 ( V_106 L_30 , V_176 ) ;
#endif
F_131 ( V_3 , V_175 ) ;
F_117 ( V_3 , V_147 ) ;
if ( V_182 )
F_132 ( V_16 , V_147 ) ;
F_69 () ;
return 0 ;
}
static struct V_1 * F_133 ( T_1 V_30 , struct V_6 * V_56 )
{
struct V_1 * V_3 ;
if ( V_30 != F_28 ( V_183 , 0 ) )
return NULL ;
V_3 = F_78 () ;
if ( ! V_3 )
return F_110 ( - V_184 ) ;
V_56 -> V_131 |= V_185 ;
F_67 ( V_3 ) ;
return V_3 ;
}
static struct V_29 * F_134 ( T_1 V_30 , struct V_6 * V_56 ,
int * V_186 , int * V_31 )
{
struct V_29 * V_24 ;
switch ( V_30 ) {
#ifdef F_135
case F_28 ( V_187 , 0 ) : {
extern struct V_29 * V_188 ;
V_24 = F_29 ( V_188 ) ;
* V_31 = V_189 ;
* V_186 = 1 ;
break;
}
#endif
case F_28 ( V_183 , 1 ) : {
struct V_29 * V_188 = F_136 ( V_31 ) ;
if ( V_188 ) {
V_24 = F_29 ( V_188 ) ;
if ( V_24 ) {
V_56 -> V_131 |= V_185 ;
* V_186 = 1 ;
break;
}
}
return F_110 ( - V_166 ) ;
}
default:
V_24 = F_26 ( V_30 , V_31 ) ;
if ( ! V_24 )
return F_110 ( - V_166 ) ;
break;
}
return V_24 ;
}
static int F_137 ( struct V_16 * V_16 , struct V_6 * V_56 )
{
struct V_1 * V_3 ;
int V_186 , V_163 ;
struct V_29 * V_24 = NULL ;
int V_31 ;
T_1 V_30 = V_16 -> V_190 ;
unsigned V_191 = V_56 -> V_131 ;
F_138 ( V_16 , V_56 ) ;
V_192:
V_163 = F_8 ( V_56 ) ;
if ( V_163 )
return - V_10 ;
V_186 = V_56 -> V_131 & V_193 ;
V_31 = - 1 ;
V_163 = 0 ;
F_32 ( & V_41 ) ;
F_53 () ;
V_3 = F_133 ( V_30 , V_56 ) ;
if ( F_139 ( V_3 ) ) {
V_163 = F_140 ( V_3 ) ;
goto V_194;
} else if ( ! V_3 ) {
V_24 = F_134 ( V_30 , V_56 , & V_186 , & V_31 ) ;
if ( F_139 ( V_24 ) ) {
V_163 = F_140 ( V_24 ) ;
goto V_194;
}
V_3 = F_101 ( V_24 , V_16 , V_31 ) ;
if ( F_139 ( V_3 ) ) {
V_163 = F_140 ( V_3 ) ;
goto V_194;
}
}
if ( V_3 ) {
V_163 = F_107 ( V_3 ) ;
if ( V_163 )
V_3 = F_110 ( V_163 ) ;
} else
V_3 = F_109 ( V_24 , V_31 , 0 ) ;
F_33 ( & V_41 ) ;
if ( V_24 )
F_121 ( V_24 ) ;
if ( F_139 ( V_3 ) ) {
F_69 () ;
V_163 = F_140 ( V_3 ) ;
goto V_195;
}
F_10 ( V_3 , V_56 ) ;
F_23 ( V_3 , V_176 ) ;
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 )
V_186 = 1 ;
#ifdef F_74
F_20 ( V_106 L_31 , V_176 , V_3 -> V_15 ) ;
#endif
if ( V_3 -> V_42 -> V_196 )
V_163 = V_3 -> V_42 -> V_196 ( V_3 , V_56 ) ;
else
V_163 = - V_166 ;
V_56 -> V_131 = V_191 ;
if ( ! V_163 && F_48 ( V_197 , & V_3 -> V_44 ) &&
! F_141 ( V_198 ) )
V_163 = - V_199 ;
if ( V_163 ) {
#ifdef F_74
F_20 ( V_106 L_32 , V_176 ,
V_163 , V_3 -> V_15 ) ;
#endif
F_69 () ;
F_127 ( V_16 , V_56 ) ;
if ( V_163 != - V_54 )
return V_163 ;
if ( F_94 ( V_46 ) )
return V_163 ;
F_130 () ;
F_53 () ;
if ( V_56 -> V_82 == & V_86 )
V_56 -> V_82 = & V_200 ;
F_69 () ;
goto V_192;
}
F_69 () ;
F_32 ( & V_41 ) ;
F_53 () ;
F_59 ( & V_46 -> V_89 -> V_90 ) ;
if ( ! V_186 &&
V_46 -> signal -> V_91 &&
! V_46 -> signal -> V_3 &&
V_3 -> V_88 == NULL )
F_142 ( V_46 , V_3 ) ;
F_60 ( & V_46 -> V_89 -> V_90 ) ;
F_69 () ;
F_33 ( & V_41 ) ;
return 0 ;
V_194:
F_69 () ;
F_33 ( & V_41 ) ;
if ( ! F_143 ( V_24 ) )
F_121 ( V_24 ) ;
V_195:
F_14 ( V_56 ) ;
return V_163 ;
}
static unsigned int F_144 ( struct V_6 * V_56 , T_6 * V_57 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
struct V_68 * V_69 ;
int V_45 = 0 ;
if ( F_18 ( V_3 , V_56 -> V_121 . V_122 -> V_123 , L_33 ) )
return 0 ;
V_69 = F_88 ( V_3 ) ;
if ( V_69 -> V_42 -> V_201 )
V_45 = ( V_69 -> V_42 -> V_201 ) ( V_3 , V_56 , V_57 ) ;
F_50 ( V_69 ) ;
return V_45 ;
}
static int F_55 ( int V_202 , struct V_6 * V_56 , int V_203 )
{
struct V_1 * V_3 = F_7 ( V_56 ) ;
unsigned long V_44 ;
int V_163 = 0 ;
if ( F_18 ( V_3 , V_56 -> V_121 . V_122 -> V_123 , L_34 ) )
goto V_51;
V_163 = F_145 ( V_202 , V_56 , V_203 , & V_3 -> V_204 ) ;
if ( V_163 <= 0 )
goto V_51;
if ( V_203 ) {
enum V_205 type ;
struct V_107 * V_107 ;
if ( ! F_128 ( & V_3 -> V_116 ) )
V_3 -> V_206 = 1 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
if ( V_3 -> V_48 ) {
V_107 = V_3 -> V_48 ;
type = V_207 ;
} else {
V_107 = F_146 ( V_46 ) ;
type = V_208 ;
}
F_63 ( V_107 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
V_163 = F_147 ( V_56 , V_107 , type , 0 ) ;
F_62 ( V_107 ) ;
if ( V_163 )
goto V_51;
} else {
if ( ! V_3 -> V_204 && ! F_128 ( & V_3 -> V_116 ) )
V_3 -> V_206 = V_209 ;
}
V_163 = 0 ;
V_51:
return V_163 ;
}
static int F_148 ( int V_202 , struct V_6 * V_56 , int V_203 )
{
int V_163 ;
F_53 () ;
V_163 = F_55 ( V_202 , V_56 , V_203 ) ;
F_69 () ;
return V_163 ;
}
static int F_149 ( struct V_1 * V_3 , char T_3 * V_22 )
{
char V_210 , V_211 = 0 ;
struct V_68 * V_69 ;
if ( ( V_46 -> signal -> V_3 != V_3 ) && ! F_141 ( V_198 ) )
return - V_212 ;
if ( F_150 ( V_210 , V_22 ) )
return - V_137 ;
F_151 ( V_3 , V_210 ) ;
V_69 = F_88 ( V_3 ) ;
V_69 -> V_42 -> V_213 ( V_3 , & V_210 , & V_211 , 1 ) ;
F_50 ( V_69 ) ;
return 0 ;
}
static int F_152 ( struct V_1 * V_3 , struct V_214 T_3 * V_65 )
{
int V_215 ;
F_32 ( & V_3 -> V_216 ) ;
V_215 = F_153 ( V_65 , & V_3 -> V_214 , sizeof( * V_65 ) ) ;
F_33 ( & V_3 -> V_216 ) ;
return V_215 ? - V_137 : 0 ;
}
int F_154 ( struct V_1 * V_3 , struct V_214 * V_217 )
{
struct V_107 * V_48 ;
unsigned long V_44 ;
F_32 ( & V_3 -> V_216 ) ;
if ( ! memcmp ( V_217 , & V_3 -> V_214 , sizeof( * V_217 ) ) )
goto V_218;
F_35 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_63 ( V_3 -> V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
if ( V_48 )
F_40 ( V_48 , V_219 , 1 ) ;
F_62 ( V_48 ) ;
V_3 -> V_214 = * V_217 ;
V_218:
F_33 ( & V_3 -> V_216 ) ;
return 0 ;
}
static int F_155 ( struct V_1 * V_3 , struct V_214 T_3 * V_65 )
{
struct V_214 V_220 ;
if ( F_93 ( & V_220 , V_65 , sizeof( * V_65 ) ) )
return - V_137 ;
if ( V_3 -> V_42 -> V_221 )
return V_3 -> V_42 -> V_221 ( V_3 , & V_220 ) ;
else
return F_154 ( V_3 , & V_220 ) ;
}
static int F_156 ( struct V_6 * V_6 )
{
if ( ! F_141 ( V_198 ) )
return - V_212 ;
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
return - V_199 ;
}
F_97 ( V_6 ) ;
V_80 = V_6 ;
F_13 ( & V_79 ) ;
return 0 ;
}
static int F_157 ( struct V_6 * V_6 , int T_3 * V_22 )
{
int V_222 ;
if ( F_150 ( V_222 , V_22 ) )
return - V_137 ;
F_11 ( & V_6 -> V_223 ) ;
if ( V_222 )
V_6 -> V_131 |= V_185 ;
else
V_6 -> V_131 &= ~ V_185 ;
F_13 ( & V_6 -> V_223 ) ;
return 0 ;
}
static int F_158 ( struct V_1 * V_3 , int V_65 )
{
int V_45 = 0 ;
if ( V_46 -> signal -> V_91 && ( F_83 ( V_46 ) == V_3 -> V_88 ) )
return V_45 ;
F_32 ( & V_41 ) ;
if ( ! V_46 -> signal -> V_91 || V_46 -> signal -> V_3 ) {
V_45 = - V_212 ;
goto V_224;
}
if ( V_3 -> V_88 ) {
if ( V_65 == 1 && F_141 ( V_198 ) ) {
F_57 ( & V_87 ) ;
F_80 ( V_3 -> V_88 ) ;
F_65 ( & V_87 ) ;
} else {
V_45 = - V_212 ;
goto V_224;
}
}
F_159 ( V_46 , V_3 ) ;
V_224:
F_33 ( & V_41 ) ;
return V_45 ;
}
struct V_107 * F_160 ( struct V_1 * V_3 )
{
unsigned long V_44 ;
struct V_107 * V_48 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
V_48 = F_63 ( V_3 -> V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
return V_48 ;
}
static int F_161 ( struct V_1 * V_3 , struct V_1 * V_225 , T_7 T_3 * V_22 )
{
struct V_107 * V_107 ;
int V_45 ;
if ( V_3 == V_225 && V_46 -> signal -> V_3 != V_225 )
return - V_67 ;
V_107 = F_160 ( V_225 ) ;
V_45 = F_162 ( F_163 ( V_107 ) , V_22 ) ;
F_62 ( V_107 ) ;
return V_45 ;
}
static int F_164 ( struct V_1 * V_3 , struct V_1 * V_225 , T_7 T_3 * V_22 )
{
struct V_107 * V_48 ;
T_7 V_226 ;
int V_163 = F_34 ( V_225 ) ;
unsigned long V_44 ;
if ( V_163 == - V_52 )
return - V_67 ;
if ( V_163 )
return V_163 ;
if ( ! V_46 -> signal -> V_3 ||
( V_46 -> signal -> V_3 != V_225 ) ||
( V_225 -> V_88 != F_83 ( V_46 ) ) )
return - V_67 ;
if ( F_150 ( V_226 , V_22 ) )
return - V_137 ;
if ( V_226 < 0 )
return - V_227 ;
F_165 () ;
V_48 = F_166 ( V_226 ) ;
V_163 = - V_228 ;
if ( ! V_48 )
goto V_49;
V_163 = - V_212 ;
if ( F_167 ( V_48 ) != F_83 ( V_46 ) )
goto V_49;
V_163 = 0 ;
F_35 ( & V_3 -> V_47 , V_44 ) ;
F_62 ( V_225 -> V_48 ) ;
V_225 -> V_48 = F_63 ( V_48 ) ;
F_37 ( & V_3 -> V_47 , V_44 ) ;
V_49:
F_168 () ;
return V_163 ;
}
static int F_169 ( struct V_1 * V_3 , struct V_1 * V_225 , T_7 T_3 * V_22 )
{
if ( V_3 == V_225 && V_46 -> signal -> V_3 != V_225 )
return - V_67 ;
if ( ! V_225 -> V_88 )
return - V_67 ;
return F_162 ( F_163 ( V_225 -> V_88 ) , V_22 ) ;
}
static int F_170 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_229 ;
int V_45 ;
if ( F_150 ( V_229 , V_22 ) )
return - V_137 ;
V_45 = F_171 ( V_3 , V_229 ) ;
return V_45 ;
}
static int F_172 ( struct V_1 * V_3 , unsigned int V_230 )
{
int V_163 ;
if ( V_3 -> V_42 -> V_231 == NULL )
return 0 ;
if ( V_3 -> V_24 -> V_44 & V_232 )
V_163 = V_3 -> V_42 -> V_231 ( V_3 , V_230 ) ;
else {
if ( F_91 ( V_3 , 0 ) < 0 )
return - V_233 ;
V_163 = V_3 -> V_42 -> V_231 ( V_3 , - 1 ) ;
if ( V_163 )
goto V_51;
if ( ! F_94 ( V_46 ) )
F_173 ( V_230 ) ;
V_163 = V_3 -> V_42 -> V_231 ( V_3 , 0 ) ;
V_51:
F_90 ( V_3 ) ;
if ( F_94 ( V_46 ) )
V_163 = - V_233 ;
}
return V_163 ;
}
static int F_174 ( struct V_1 * V_3 , int T_3 * V_22 )
{
int V_163 = - V_227 ;
if ( V_3 -> V_42 -> V_234 ) {
V_163 = V_3 -> V_42 -> V_234 ( V_3 ) ;
if ( V_163 >= 0 )
V_163 = F_162 ( V_163 , V_22 ) ;
}
return V_163 ;
}
static int F_175 ( struct V_1 * V_3 , unsigned int V_64 ,
unsigned T_3 * V_22 )
{
int V_163 ;
unsigned int V_235 , V_236 , V_237 ;
if ( V_3 -> V_42 -> V_238 == NULL )
return - V_227 ;
V_163 = F_150 ( V_237 , V_22 ) ;
if ( V_163 )
return V_163 ;
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
static int F_176 ( struct V_1 * V_3 , void T_3 * V_65 )
{
int V_163 = - V_227 ;
struct V_247 V_248 ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
if ( V_3 -> V_42 -> V_249 )
V_163 = V_3 -> V_42 -> V_249 ( V_3 , & V_248 ) ;
if ( V_163 != 0 )
return V_163 ;
if ( F_153 ( V_65 , & V_248 , sizeof( V_248 ) ) )
return - V_137 ;
return 0 ;
}
struct V_1 * F_177 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 )
V_3 = V_3 -> V_28 ;
return V_3 ;
}
struct V_1 * F_178 ( struct V_1 * V_3 )
{
if ( V_3 -> V_24 -> type == V_25 &&
V_3 -> V_24 -> V_26 == V_159 )
return V_3 ;
return V_3 -> V_28 ;
}
long F_179 ( struct V_6 * V_6 , unsigned int V_64 , unsigned long V_65 )
{
struct V_1 * V_3 = F_7 ( V_6 ) ;
struct V_1 * V_225 ;
void T_3 * V_22 = ( void T_3 * ) V_65 ;
int V_163 ;
struct V_68 * V_69 ;
struct V_16 * V_16 = V_6 -> V_250 -> V_123 ;
if ( F_18 ( V_3 , V_16 , L_35 ) )
return - V_227 ;
V_225 = F_177 ( V_3 ) ;
switch ( V_64 ) {
case V_251 :
case V_252 :
case V_253 :
case V_254 :
case V_255 :
V_163 = F_34 ( V_3 ) ;
if ( V_163 )
return V_163 ;
if ( V_64 != V_253 ) {
F_180 ( V_3 , 0 ) ;
if ( F_94 ( V_46 ) )
return - V_233 ;
}
break;
}
switch ( V_64 ) {
case V_256 :
return F_149 ( V_3 , V_22 ) ;
case V_257 :
return F_152 ( V_225 , V_22 ) ;
case V_258 :
return F_155 ( V_225 , V_22 ) ;
case V_259 :
return V_225 != V_3 ? - V_227 : F_156 ( V_6 ) ;
case V_260 :
return F_157 ( V_6 , V_22 ) ;
case V_261 :
F_54 ( V_197 , & V_3 -> V_44 ) ;
return 0 ;
case V_262 :
F_66 ( V_197 , & V_3 -> V_44 ) ;
return 0 ;
case V_263 :
if ( V_46 -> signal -> V_3 != V_3 )
return - V_67 ;
F_84 () ;
return 0 ;
case V_264 :
return F_158 ( V_3 , V_65 ) ;
case V_265 :
return F_161 ( V_3 , V_225 , V_22 ) ;
case V_66 :
return F_164 ( V_3 , V_225 , V_22 ) ;
case V_266 :
return F_169 ( V_3 , V_225 , V_22 ) ;
case V_267 :
return F_162 ( V_3 -> V_229 -> V_42 -> V_35 , ( int T_3 * ) V_22 ) ;
case V_251 :
return F_170 ( V_3 , V_22 ) ;
case V_268 :
if ( ! F_141 ( V_198 ) )
return - V_212 ;
F_76 ( V_3 ) ;
return 0 ;
case V_269 :
{
unsigned int V_45 = F_181 ( F_182 ( V_225 ) ) ;
return F_162 ( V_45 , ( unsigned int T_3 * ) V_22 ) ;
}
case V_252 :
if ( V_3 -> V_42 -> V_231 )
return V_3 -> V_42 -> V_231 ( V_3 , - 1 ) ;
return 0 ;
case V_253 :
if ( V_3 -> V_42 -> V_231 )
return V_3 -> V_42 -> V_231 ( V_3 , 0 ) ;
return 0 ;
case V_254 :
if ( ! V_65 )
return F_172 ( V_3 , 250 ) ;
return 0 ;
case V_255 :
return F_172 ( V_3 , V_65 ? V_65 * 100 : 250 ) ;
case V_270 :
return F_174 ( V_3 , V_22 ) ;
case V_241 :
case V_240 :
case V_239 :
return F_175 ( V_3 , V_64 , V_22 ) ;
case V_271 :
V_163 = F_176 ( V_3 , V_22 ) ;
if ( V_163 != - V_227 )
return V_163 ;
break;
case V_272 :
switch ( V_65 ) {
case V_273 :
case V_274 :
F_183 ( V_3 ) ;
break;
}
break;
}
if ( V_3 -> V_42 -> V_275 ) {
V_163 = ( V_3 -> V_42 -> V_275 ) ( V_3 , V_64 , V_65 ) ;
if ( V_163 != - V_276 )
return V_163 ;
}
V_69 = F_88 ( V_3 ) ;
V_163 = - V_227 ;
if ( V_69 -> V_42 -> V_275 ) {
V_163 = V_69 -> V_42 -> V_275 ( V_3 , V_6 , V_64 , V_65 ) ;
if ( V_163 == - V_276 )
V_163 = - V_227 ;
}
F_50 ( V_69 ) ;
return V_163 ;
}
static long F_184 ( struct V_6 * V_6 , unsigned int V_64 ,
unsigned long V_65 )
{
struct V_16 * V_16 = V_6 -> V_250 -> V_123 ;
struct V_1 * V_3 = F_7 ( V_6 ) ;
struct V_68 * V_69 ;
int V_163 = - V_276 ;
if ( F_18 ( V_3 , V_16 , L_35 ) )
return - V_227 ;
if ( V_3 -> V_42 -> V_277 ) {
V_163 = ( V_3 -> V_42 -> V_277 ) ( V_3 , V_64 , V_65 ) ;
if ( V_163 != - V_276 )
return V_163 ;
}
V_69 = F_88 ( V_3 ) ;
if ( V_69 -> V_42 -> V_277 )
V_163 = V_69 -> V_42 -> V_277 ( V_3 , V_6 , V_64 , V_65 ) ;
else
V_163 = F_185 ( V_3 , V_6 , V_64 , V_65 ) ;
F_50 ( V_69 ) ;
return V_163 ;
}
void F_186 ( struct V_1 * V_3 )
{
#ifdef F_187
F_73 ( V_3 ) ;
#else
struct V_75 * V_278 , * V_22 ;
struct V_107 * V_88 ;
int V_120 ;
struct V_6 * V_56 ;
struct V_279 * V_280 ;
if ( ! V_3 )
return;
V_88 = V_3 -> V_88 ;
F_188 ( V_3 ) ;
F_189 ( V_3 ) ;
F_57 ( & V_87 ) ;
F_58 (session, PIDTYPE_SID, p) {
F_20 ( V_281 L_36
L_37 ,
F_190 ( V_22 ) , V_22 -> V_282 ) ;
F_191 ( V_283 , V_22 , 1 ) ;
} F_64 ( V_88 , V_96 , V_22 ) ;
F_192 (g, p) {
if ( V_22 -> signal -> V_3 == V_3 ) {
F_20 ( V_281 L_36
L_37 ,
F_190 ( V_22 ) , V_22 -> V_282 ) ;
F_191 ( V_283 , V_22 , 1 ) ;
continue;
}
F_193 ( V_22 ) ;
if ( V_22 -> V_284 ) {
F_11 ( & V_22 -> V_284 -> V_285 ) ;
V_280 = F_194 ( V_22 -> V_284 ) ;
for ( V_120 = 0 ; V_120 < V_280 -> V_286 ; V_120 ++ ) {
V_56 = F_195 ( V_22 -> V_284 , V_120 ) ;
if ( ! V_56 )
continue;
if ( V_56 -> V_82 -> V_125 == F_87 &&
F_7 ( V_56 ) == V_3 ) {
F_20 ( V_281 L_36
L_38 ,
F_190 ( V_22 ) , V_22 -> V_282 , V_120 ) ;
F_196 ( V_283 , V_22 ) ;
break;
}
}
F_13 ( & V_22 -> V_284 -> V_285 ) ;
}
F_197 ( V_22 ) ;
} F_198 ( V_278 , V_22 ) ;
F_65 ( & V_87 ) ;
#endif
}
static void F_199 ( struct V_103 * V_104 )
{
struct V_1 * V_3 =
F_72 ( V_104 , struct V_1 , V_287 ) ;
F_186 ( V_3 ) ;
}
void F_200 ( struct V_1 * V_3 )
{
if ( ! V_3 )
return;
F_75 ( & V_3 -> V_287 ) ;
}
static int F_201 ( struct V_30 * V_4 , void * V_288 )
{
T_1 * V_289 = V_288 ;
return V_4 -> V_289 == * V_289 ;
}
static struct V_30 * F_202 ( struct V_1 * V_3 )
{
T_1 V_289 = F_182 ( V_3 ) ;
return F_203 ( V_290 , NULL , & V_289 , F_201 ) ;
}
void F_112 ( struct V_1 * V_3 ,
struct V_29 * V_24 , int V_147 )
{
memset ( V_3 , 0 , sizeof( struct V_1 ) ) ;
F_204 ( & V_3 -> V_173 ) ;
V_3 -> V_19 = V_20 ;
F_205 ( V_3 ) ;
V_3 -> V_88 = NULL ;
V_3 -> V_48 = NULL ;
V_3 -> V_291 = V_292 ;
V_3 -> V_14 . V_293 = V_3 -> V_14 . V_294 = NULL ;
F_206 ( V_3 ) ;
F_207 ( & V_3 -> V_216 ) ;
F_207 ( & V_3 -> V_160 ) ;
F_208 ( & V_3 -> V_72 ) ;
F_208 ( & V_3 -> V_116 ) ;
F_124 ( & V_3 -> V_105 , F_71 ) ;
F_207 ( & V_3 -> V_295 ) ;
F_207 ( & V_3 -> V_140 ) ;
F_207 ( & V_3 -> V_296 ) ;
F_207 ( & V_3 -> V_297 ) ;
F_209 ( & V_3 -> F_57 ) ;
F_209 ( & V_3 -> V_47 ) ;
F_210 ( & V_3 -> V_13 ) ;
F_124 ( & V_3 -> V_287 , F_199 ) ;
V_3 -> V_24 = V_24 ;
V_3 -> V_42 = V_24 -> V_42 ;
V_3 -> V_31 = V_147 ;
F_100 ( V_24 , V_147 , V_3 -> V_15 ) ;
V_3 -> V_4 = F_202 ( V_3 ) ;
}
void F_114 ( struct V_1 * V_3 )
{
F_211 ( V_3 ) ;
}
int F_212 ( struct V_1 * V_3 , unsigned char V_210 )
{
if ( V_3 -> V_42 -> V_298 )
return V_3 -> V_42 -> V_298 ( V_3 , V_210 ) ;
return V_3 -> V_42 -> V_83 ( V_3 , & V_210 , 1 ) ;
}
struct V_30 * F_213 ( struct V_29 * V_24 , unsigned V_31 ,
struct V_30 * V_30 )
{
char V_15 [ 64 ] ;
T_1 V_4 = F_28 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ;
if ( V_31 >= V_24 -> V_35 ) {
F_20 ( V_143 L_39
L_40 , V_31 ) ;
return F_110 ( - V_227 ) ;
}
if ( V_24 -> type == V_25 )
F_99 ( V_24 , V_31 , V_15 ) ;
else
F_100 ( V_24 , V_31 , V_15 ) ;
return F_214 ( V_290 , V_30 , V_4 , NULL , V_15 ) ;
}
void F_215 ( struct V_29 * V_24 , unsigned V_31 )
{
F_216 ( V_290 ,
F_28 ( V_24 -> V_33 , V_24 -> V_34 ) + V_31 ) ;
}
struct V_29 * F_217 ( int V_299 )
{
struct V_29 * V_24 ;
V_24 = F_2 ( sizeof( struct V_29 ) , V_2 ) ;
if ( V_24 ) {
F_204 ( & V_24 -> V_173 ) ;
V_24 -> V_19 = V_300 ;
V_24 -> V_35 = V_299 ;
}
return V_24 ;
}
static void F_218 ( struct V_173 * V_173 )
{
struct V_29 * V_24 = F_72 ( V_173 , struct V_29 , V_173 ) ;
int V_120 ;
struct V_150 * V_151 ;
void * V_22 ;
if ( V_24 -> V_44 & V_301 ) {
for ( V_120 = 0 ; V_120 < V_24 -> V_35 ; V_120 ++ ) {
V_151 = V_24 -> V_152 [ V_120 ] ;
if ( V_151 ) {
V_24 -> V_152 [ V_120 ] = NULL ;
F_5 ( V_151 ) ;
}
if ( ! ( V_24 -> V_44 & V_302 ) )
F_215 ( V_24 , V_120 ) ;
}
V_22 = V_24 -> V_149 ;
F_219 ( V_24 ) ;
V_24 -> V_149 = NULL ;
V_24 -> V_152 = NULL ;
F_5 ( V_22 ) ;
F_220 ( & V_24 -> V_303 ) ;
}
F_5 ( V_24 ) ;
}
void F_121 ( struct V_29 * V_24 )
{
F_125 ( & V_24 -> V_173 , F_218 ) ;
}
void F_221 ( struct V_29 * V_24 ,
const struct V_304 * V_305 )
{
V_24 -> V_42 = V_305 ;
}
void F_222 ( struct V_29 * V_306 )
{
F_121 ( V_306 ) ;
}
int F_223 ( struct V_29 * V_24 )
{
int error ;
int V_120 ;
T_1 V_4 ;
void * * V_22 = NULL ;
struct V_30 * V_306 ;
if ( ! ( V_24 -> V_44 & V_164 ) && V_24 -> V_35 ) {
V_22 = F_2 ( V_24 -> V_35 * 2 * sizeof( void * ) , V_2 ) ;
if ( ! V_22 )
return - V_10 ;
}
if ( ! V_24 -> V_33 ) {
error = F_224 ( & V_4 , V_24 -> V_34 ,
V_24 -> V_35 , V_24 -> V_15 ) ;
if ( ! error ) {
V_24 -> V_33 = F_225 ( V_4 ) ;
V_24 -> V_34 = F_226 ( V_4 ) ;
}
} else {
V_4 = F_28 ( V_24 -> V_33 , V_24 -> V_34 ) ;
error = F_227 ( V_4 , V_24 -> V_35 , V_24 -> V_15 ) ;
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
F_228 ( & V_24 -> V_303 , & V_200 ) ;
V_24 -> V_303 . V_165 = V_24 -> V_165 ;
error = F_229 ( & V_24 -> V_303 , V_4 , V_24 -> V_35 ) ;
if ( error ) {
F_230 ( V_4 , V_24 -> V_35 ) ;
V_24 -> V_149 = NULL ;
V_24 -> V_152 = NULL ;
F_5 ( V_22 ) ;
return error ;
}
F_32 ( & V_41 ) ;
F_12 ( & V_24 -> V_307 , & V_307 ) ;
F_33 ( & V_41 ) ;
if ( ! ( V_24 -> V_44 & V_302 ) ) {
for ( V_120 = 0 ; V_120 < V_24 -> V_35 ; V_120 ++ ) {
V_306 = F_213 ( V_24 , V_120 , NULL ) ;
if ( F_139 ( V_306 ) ) {
error = F_140 ( V_306 ) ;
goto V_215;
}
}
}
F_231 ( V_24 ) ;
V_24 -> V_44 |= V_301 ;
return 0 ;
V_215:
for ( V_120 -- ; V_120 >= 0 ; V_120 -- )
F_215 ( V_24 , V_120 ) ;
F_32 ( & V_41 ) ;
F_16 ( & V_24 -> V_307 ) ;
F_33 ( & V_41 ) ;
F_230 ( V_4 , V_24 -> V_35 ) ;
V_24 -> V_149 = NULL ;
V_24 -> V_152 = NULL ;
F_5 ( V_22 ) ;
return error ;
}
int F_232 ( struct V_29 * V_24 )
{
#if 0
if (driver->refcount)
return -EBUSY;
#endif
F_230 ( F_28 ( V_24 -> V_33 , V_24 -> V_34 ) ,
V_24 -> V_35 ) ;
F_32 ( & V_41 ) ;
F_16 ( & V_24 -> V_307 ) ;
F_33 ( & V_41 ) ;
return 0 ;
}
T_1 F_182 ( struct V_1 * V_3 )
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
static void F_142 ( struct V_75 * V_111 , struct V_1 * V_3 )
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
V_111 -> signal -> V_3 = F_233 ( V_3 ) ;
V_111 -> signal -> V_95 = NULL ;
}
static void F_159 ( struct V_75 * V_111 , struct V_1 * V_3 )
{
F_59 ( & V_111 -> V_89 -> V_90 ) ;
F_142 ( V_111 , V_3 ) ;
F_60 ( & V_111 -> V_89 -> V_90 ) ;
}
struct V_1 * F_78 ( void )
{
struct V_1 * V_3 ;
unsigned long V_44 ;
F_35 ( & V_46 -> V_89 -> V_90 , V_44 ) ;
V_3 = F_233 ( V_46 -> signal -> V_3 ) ;
F_37 ( & V_46 -> V_89 -> V_90 , V_44 ) ;
return V_3 ;
}
void F_234 ( struct V_308 * V_309 )
{
* V_309 = V_200 ;
}
void T_8 F_235 ( void )
{
T_9 * V_310 ;
F_236 () ;
V_310 = V_311 ;
while ( V_310 < V_312 ) {
(* V_310)() ;
V_310 ++ ;
}
}
static char * F_237 ( struct V_30 * V_4 , T_10 * V_313 )
{
if ( ! V_313 )
return NULL ;
if ( V_4 -> V_289 == F_28 ( V_183 , 0 ) ||
V_4 -> V_289 == F_28 ( V_183 , 2 ) )
* V_313 = 0666 ;
return NULL ;
}
static int T_8 F_238 ( void )
{
V_290 = F_239 ( V_314 , L_16 ) ;
if ( F_139 ( V_290 ) )
return F_140 ( V_290 ) ;
V_290 -> V_315 = F_237 ;
return 0 ;
}
static T_2 F_240 ( struct V_30 * V_4 ,
struct V_316 * V_317 , char * V_14 )
{
struct V_318 * V_319 [ 16 ] ;
int V_120 = 0 ;
struct V_318 * V_320 ;
T_2 V_23 = 0 ;
F_241 () ;
F_242 (c) {
if ( ! V_320 -> V_30 )
continue;
if ( ! V_320 -> V_83 )
continue;
if ( ( V_320 -> V_44 & V_321 ) == 0 )
continue;
V_319 [ V_120 ++ ] = V_320 ;
if ( V_120 >= F_243 ( V_319 ) )
break;
}
while ( V_120 -- )
V_23 += sprintf ( V_14 + V_23 , L_42 ,
V_319 [ V_120 ] -> V_15 , V_319 [ V_120 ] -> V_31 , V_120 ? ' ' : '\n' ) ;
F_244 () ;
return V_23 ;
}
void F_245 ( void )
{
if ( V_322 )
F_246 ( & V_322 -> V_323 , NULL , L_43 ) ;
}
int T_8 F_247 ( void )
{
F_228 ( & V_324 , & V_200 ) ;
if ( F_229 ( & V_324 , F_28 ( V_183 , 0 ) , 1 ) ||
F_227 ( F_28 ( V_183 , 0 ) , 1 , L_44 ) < 0 )
F_248 ( L_45 ) ;
F_214 ( V_290 , NULL , F_28 ( V_183 , 0 ) , NULL , L_16 ) ;
F_228 ( & V_325 , & V_326 ) ;
if ( F_229 ( & V_325 , F_28 ( V_183 , 1 ) , 1 ) ||
F_227 ( F_28 ( V_183 , 1 ) , 1 , L_46 ) < 0 )
F_248 ( L_47 ) ;
V_322 = F_214 ( V_290 , NULL , F_28 ( V_183 , 1 ) , NULL ,
L_48 ) ;
if ( F_139 ( V_322 ) )
V_322 = NULL ;
else
F_108 ( F_249 ( V_322 , & V_327 ) < 0 ) ;
#ifdef F_135
F_250 ( & V_326 ) ;
#endif
return 0 ;
}
