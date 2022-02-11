static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 V_2 )
{
return F_3 ( ( V_3 ) V_1 << V_4 , V_2 ) ;
}
static inline void F_4 ( struct V_5 * V_6 , int V_7 , int V_8 ,
int V_9 , int V_10 ) {
V_6 -> V_7 = V_7 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_10 = F_5 ( V_10 ) ;
V_6 -> V_11 = F_5 ( V_7 ) - F_5 ( V_8 ) ;
}
static inline void F_6 ( struct V_5 * V_6 , int V_12 )
{
V_6 -> V_13 = F_2 ( F_5 ( V_12 ) , F_5 ( 100 ) ) ;
}
static inline void F_7 ( struct V_5 * V_6 , int V_12 )
{
V_6 -> V_14 = F_2 ( F_5 ( V_12 ) , F_5 ( 100 ) ) ;
}
static inline void F_8 ( struct V_5 * V_6 , int V_12 )
{
V_6 -> V_15 = F_2 ( F_5 ( V_12 ) , F_5 ( 100 ) ) ;
}
static signed int F_9 ( struct V_5 * V_6 , T_1 V_8 )
{
signed int V_16 ;
T_1 V_17 , V_18 , V_19 ;
T_1 V_20 ;
V_19 = F_5 ( V_6 -> V_7 ) - V_8 ;
if ( abs ( V_19 ) <= F_5 ( V_6 -> V_9 ) )
return 0 ;
V_17 = F_1 ( V_6 -> V_13 , V_19 ) ;
V_6 -> V_10 += V_19 ;
V_20 = F_5 ( 30 ) ;
if ( V_6 -> V_10 > V_20 )
V_6 -> V_10 = V_20 ;
if ( V_6 -> V_10 < - V_20 )
V_6 -> V_10 = - V_20 ;
V_18 = F_1 ( V_6 -> V_15 , V_19 - V_6 -> V_11 ) ;
V_6 -> V_11 = V_19 ;
V_16 = V_17 + F_1 ( V_6 -> V_10 , V_6 -> V_14 ) + V_18 ;
V_16 = V_16 + ( 1 << ( V_4 - 1 ) ) ;
return ( signed int ) F_10 ( V_16 ) ;
}
static inline void F_11 ( struct V_21 * V_22 )
{
F_6 ( & V_22 -> V_6 , V_23 . V_24 ) ;
F_8 ( & V_22 -> V_6 , V_23 . V_25 ) ;
F_7 ( & V_22 -> V_6 , V_23 . V_26 ) ;
F_4 ( & V_22 -> V_6 , V_23 . V_7 , 100 , V_23 . V_9 , 0 ) ;
}
static inline void F_12 ( void )
{
unsigned int V_22 ;
F_13 (cpu) {
if ( V_27 [ V_22 ] )
F_11 ( V_27 [ V_22 ] ) ;
}
}
static int F_14 ( void * V_28 , T_2 V_29 )
{
* ( V_30 * ) V_28 = V_29 ;
F_12 () ;
return 0 ;
}
static int F_15 ( void * V_28 , T_2 * V_29 )
{
* V_29 = * ( V_30 * ) V_28 ;
return 0 ;
}
static void T_3 F_16 ( void )
{
struct V_31 * V_32 ;
int V_33 = 0 ;
V_32 = F_17 ( L_1 , NULL ) ;
if ( F_18 ( V_32 ) )
return;
while ( V_34 [ V_33 ] . V_35 ) {
F_19 ( V_34 [ V_33 ] . V_35 , 0660 ,
V_32 , V_34 [ V_33 ] . V_36 ,
& V_37 ) ;
V_33 ++ ;
}
}
static T_4 F_20 ( struct V_38 * V_39 , struct V_40 * V_41 ,
const char * V_42 , T_5 V_43 )
{
unsigned int V_44 ;
int V_45 ;
V_45 = sscanf ( V_42 , L_2 , & V_44 ) ;
if ( V_45 != 1 )
return - V_46 ;
V_47 . V_48 = F_21 ( int , V_44 , 0 , 1 ) ;
if ( V_47 . V_49 ) {
F_22 ( L_3 ) ;
V_47 . V_48 = V_47 . V_49 ;
}
return V_43 ;
}
static T_4 F_23 ( struct V_38 * V_39 , struct V_40 * V_41 ,
const char * V_42 , T_5 V_43 )
{
unsigned int V_44 ;
int V_45 ;
V_45 = sscanf ( V_42 , L_2 , & V_44 ) ;
if ( V_45 != 1 )
return - V_46 ;
V_47 . V_50 = F_21 ( int , V_44 , 0 , 100 ) ;
V_47 . V_51 = F_24 ( V_47 . V_52 , V_47 . V_50 ) ;
V_47 . V_53 = F_2 ( F_5 ( V_47 . V_51 ) , F_5 ( 100 ) ) ;
return V_43 ;
}
static T_4 F_25 ( struct V_38 * V_39 , struct V_40 * V_41 ,
const char * V_42 , T_5 V_43 )
{
unsigned int V_44 ;
int V_45 ;
V_45 = sscanf ( V_42 , L_2 , & V_44 ) ;
if ( V_45 != 1 )
return - V_46 ;
V_47 . V_54 = F_21 ( int , V_44 , 0 , 100 ) ;
V_47 . V_55 = F_2 ( F_5 ( V_47 . V_54 ) , F_5 ( 100 ) ) ;
return V_43 ;
}
static void T_3 F_26 ( void )
{
struct V_38 * V_56 ;
int V_57 ;
V_56 = F_27 ( L_4 ,
& V_58 . V_59 -> V_60 ) ;
F_28 ( ! V_56 ) ;
V_57 = F_29 ( V_56 , & V_61 ) ;
F_28 ( V_57 ) ;
}
static int F_30 ( void )
{
T_2 V_36 ;
F_31 ( V_62 , V_36 ) ;
return ( V_36 >> 8 ) & 0x7F ;
}
static int F_32 ( void )
{
T_2 V_36 ;
F_31 ( V_62 , V_36 ) ;
return ( V_36 >> 16 ) & 0x7F ;
}
static int F_33 ( void )
{
T_2 V_36 ;
F_31 ( V_63 , V_36 ) ;
return V_36 & 0x7F ;
}
static void F_34 ( struct V_21 * V_21 , int V_64 )
{
T_2 V_29 ;
T_1 V_65 ;
V_30 V_66 ;
V_29 = V_64 << 8 ;
if ( V_47 . V_48 && ! V_47 . V_49 )
V_29 |= ( T_2 ) 1 << 32 ;
V_65 = V_21 -> V_66 . F_24 + F_1 (
F_5 ( V_64 - V_21 -> V_64 . V_67 ) ,
V_21 -> V_66 . V_68 ) ;
V_65 = F_21 ( T_1 , V_65 , V_21 -> V_66 . F_24 , V_21 -> V_66 . V_69 ) ;
V_66 = F_10 ( V_65 ) ;
if ( V_64 > V_21 -> V_64 . V_70 )
V_66 = V_21 -> V_66 . V_71 ;
V_29 |= V_66 ;
F_35 ( V_72 , V_29 ) ;
}
static void F_36 ( struct V_21 * V_21 )
{
T_2 V_36 ;
F_31 ( V_73 , V_36 ) ;
V_21 -> V_66 . F_24 = F_5 ( ( V_36 >> 8 ) & 0x7f ) ;
V_21 -> V_66 . V_69 = F_5 ( ( V_36 >> 16 ) & 0x7f ) ;
V_21 -> V_66 . V_68 = F_2 (
V_21 -> V_66 . V_69 - V_21 -> V_66 . F_24 ,
F_5 ( V_21 -> V_64 . V_70 -
V_21 -> V_64 . V_67 ) ) ;
F_31 ( V_74 , V_36 ) ;
V_21 -> V_66 . V_71 = V_36 & 0x7f ;
}
static int F_37 ( void )
{
T_2 V_36 ;
F_31 ( V_75 , V_36 ) ;
return ( V_36 >> 40 ) & 0xFF ;
}
static int F_38 ( void )
{
T_2 V_36 ;
F_31 ( V_75 , V_36 ) ;
return ( V_36 >> 8 ) & 0xFF ;
}
static int F_39 ( void )
{
T_2 V_36 ;
int V_76 , V_45 ;
F_31 ( V_77 , V_36 ) ;
V_76 = F_38 () ;
V_45 = ( V_36 ) & 255 ;
if ( V_45 <= V_76 )
V_45 = V_76 ;
return V_45 ;
}
static void F_40 ( struct V_21 * V_21 , int V_64 )
{
T_2 V_29 ;
V_29 = V_64 << 8 ;
if ( V_47 . V_48 && ! V_47 . V_49 )
V_29 |= ( T_2 ) 1 << 32 ;
F_41 ( V_21 -> V_22 , V_72 , V_29 ) ;
}
static void F_42 ( struct V_21 * V_22 , int * F_24 , int * V_69 )
{
int V_53 = V_22 -> V_64 . V_78 ;
int V_79 ;
int V_55 ;
if ( V_47 . V_48 )
V_53 = V_22 -> V_64 . V_70 ;
V_79 = F_10 ( F_1 ( F_5 ( V_53 ) , V_47 . V_53 ) ) ;
* V_69 = F_21 ( int , V_79 ,
V_22 -> V_64 . V_67 , V_22 -> V_64 . V_78 ) ;
V_55 = F_10 ( F_1 ( F_5 ( V_53 ) , V_47 . V_55 ) ) ;
* F_24 = F_21 ( int , V_55 , V_22 -> V_64 . V_67 , V_53 ) ;
}
static void F_43 ( struct V_21 * V_22 , int V_64 )
{
int V_53 , V_55 ;
F_42 ( V_22 , & V_55 , & V_53 ) ;
V_64 = F_21 ( int , V_64 , V_55 , V_53 ) ;
if ( V_64 == V_22 -> V_64 . V_80 )
return;
F_44 ( V_64 * 100000 , V_22 -> V_22 ) ;
V_22 -> V_64 . V_80 = V_64 ;
V_81 . V_82 ( V_22 , V_64 ) ;
}
static void F_45 ( struct V_21 * V_22 )
{
V_22 -> V_64 . V_67 = V_81 . V_83 () ;
V_22 -> V_64 . V_70 = V_81 . V_84 () ;
V_22 -> V_64 . V_78 = V_81 . V_85 () ;
if ( V_81 . V_86 )
V_81 . V_86 ( V_22 ) ;
F_43 ( V_22 , V_22 -> V_64 . V_67 ) ;
}
static inline void F_46 ( struct V_21 * V_22 )
{
struct V_87 * V_87 = & V_22 -> V_87 ;
V_3 V_88 ;
V_88 = F_5 ( V_87 -> V_89 ) * F_5 ( 100 ) ;
V_88 = F_47 ( V_88 , F_5 ( V_87 -> V_90 ) ) ;
V_87 -> V_91 = F_10 (
F_1 ( F_5 ( V_22 -> V_64 . V_70 * 1000 ) , V_88 ) ) ;
V_87 -> V_92 = ( T_1 ) V_88 ;
}
static inline void F_48 ( struct V_21 * V_22 )
{
T_2 V_89 , V_90 ;
unsigned long V_93 ;
F_49 ( V_93 ) ;
F_31 ( V_94 , V_89 ) ;
F_31 ( V_95 , V_90 ) ;
F_50 ( V_93 ) ;
V_22 -> V_96 = V_22 -> V_87 . time ;
V_22 -> V_87 . time = F_51 () ;
V_22 -> V_87 . V_89 = V_89 ;
V_22 -> V_87 . V_90 = V_90 ;
V_22 -> V_87 . V_89 -= V_22 -> V_97 ;
V_22 -> V_87 . V_90 -= V_22 -> V_98 ;
F_46 ( V_22 ) ;
V_22 -> V_97 = V_89 ;
V_22 -> V_98 = V_90 ;
}
static inline void F_52 ( struct V_21 * V_22 )
{
int V_99 ;
V_99 = F_53 ( V_23 . V_100 ) ;
F_54 ( & V_22 -> V_101 , V_102 + V_99 ) ;
}
static inline T_1 F_55 ( struct V_21 * V_22 )
{
T_1 V_103 , V_70 , V_80 , V_104 ;
V_30 V_105 ;
V_30 V_106 ;
V_103 = V_22 -> V_87 . V_92 ;
V_70 = F_5 ( V_22 -> V_64 . V_70 ) ;
V_80 = F_5 ( V_22 -> V_64 . V_80 ) ;
V_103 = F_1 ( V_103 , F_2 ( V_70 , V_80 ) ) ;
V_106 = V_23 . V_100 * V_107 ;
V_105 = ( V_30 ) F_56 ( V_22 -> V_87 . time ,
V_22 -> V_96 ) ;
if ( V_105 > V_106 * 3 ) {
V_104 = F_2 ( F_5 ( V_106 ) ,
F_5 ( V_105 ) ) ;
V_103 = F_1 ( V_103 , V_104 ) ;
}
return V_103 ;
}
static inline void F_57 ( struct V_21 * V_22 )
{
T_1 V_108 ;
struct V_5 * V_6 ;
signed int V_109 ;
V_6 = & V_22 -> V_6 ;
V_108 = F_55 ( V_22 ) ;
V_109 = F_9 ( V_6 , V_108 ) ;
F_43 ( V_22 , V_22 -> V_64 . V_80 - V_109 ) ;
}
static void F_58 ( unsigned long V_110 )
{
struct V_21 * V_22 = (struct V_21 * ) V_110 ;
struct V_87 * V_87 ;
F_48 ( V_22 ) ;
V_87 = & V_22 -> V_87 ;
F_57 ( V_22 ) ;
F_59 ( F_10 ( V_87 -> V_92 ) ,
F_10 ( F_55 ( V_22 ) ) ,
V_22 -> V_64 . V_80 ,
V_87 -> V_90 ,
V_87 -> V_89 ,
V_87 -> V_91 ) ;
F_52 ( V_22 ) ;
}
static int F_60 ( unsigned int V_111 )
{
struct V_21 * V_22 ;
V_27 [ V_111 ] = F_61 ( sizeof( struct V_21 ) , V_112 ) ;
if ( ! V_27 [ V_111 ] )
return - V_113 ;
V_22 = V_27 [ V_111 ] ;
V_22 -> V_22 = V_111 ;
F_45 ( V_22 ) ;
F_62 ( & V_22 -> V_101 ) ;
V_22 -> V_101 . V_114 = F_58 ;
V_22 -> V_101 . V_28 = ( unsigned long ) V_22 ;
V_22 -> V_101 . V_115 = V_102 + V_116 / 100 ;
F_11 ( V_22 ) ;
F_48 ( V_22 ) ;
F_63 ( & V_22 -> V_101 , V_111 ) ;
F_64 ( L_5 , V_111 ) ;
return 0 ;
}
static unsigned int F_65 ( unsigned int V_117 )
{
struct V_87 * V_87 ;
struct V_21 * V_22 ;
V_22 = V_27 [ V_117 ] ;
if ( ! V_22 )
return 0 ;
V_87 = & V_22 -> V_87 ;
return V_87 -> V_91 ;
}
static int F_66 ( struct V_118 * V_119 )
{
if ( ! V_119 -> V_120 . V_121 )
return - V_122 ;
if ( V_119 -> V_119 == V_123 ) {
V_47 . V_54 = 100 ;
V_47 . V_55 = F_5 ( 1 ) ;
V_47 . V_51 = 100 ;
V_47 . V_53 = F_5 ( 1 ) ;
V_47 . V_48 = V_47 . V_49 ;
return 0 ;
}
V_47 . V_54 = ( V_119 -> F_24 * 100 ) / V_119 -> V_120 . V_121 ;
V_47 . V_54 = F_21 ( int , V_47 . V_54 , 0 , 100 ) ;
V_47 . V_55 = F_2 ( F_5 ( V_47 . V_54 ) , F_5 ( 100 ) ) ;
V_47 . V_52 = ( V_119 -> V_69 * 100 ) / V_119 -> V_120 . V_121 ;
V_47 . V_52 = F_21 ( int , V_47 . V_52 , 0 , 100 ) ;
V_47 . V_51 = F_24 ( V_47 . V_52 , V_47 . V_50 ) ;
V_47 . V_53 = F_2 ( F_5 ( V_47 . V_51 ) , F_5 ( 100 ) ) ;
return 0 ;
}
static int F_67 ( struct V_118 * V_119 )
{
F_68 ( V_119 ) ;
if ( V_119 -> V_119 != V_124 &&
V_119 -> V_119 != V_123 )
return - V_46 ;
return 0 ;
}
static void F_69 ( struct V_118 * V_119 )
{
int V_117 = V_119 -> V_22 ;
struct V_21 * V_22 = V_27 [ V_117 ] ;
F_70 ( L_6 , V_117 ) ;
F_71 ( & V_27 [ V_117 ] -> V_101 ) ;
F_43 ( V_22 , V_22 -> V_64 . V_67 ) ;
F_72 ( V_27 [ V_117 ] ) ;
V_27 [ V_117 ] = NULL ;
}
static int F_73 ( struct V_118 * V_119 )
{
struct V_21 * V_22 ;
int V_57 ;
T_2 V_125 ;
V_57 = F_60 ( V_119 -> V_22 ) ;
if ( V_57 )
return V_57 ;
V_22 = V_27 [ V_119 -> V_22 ] ;
F_31 ( V_126 , V_125 ) ;
if ( V_125 & V_127 ||
V_22 -> V_64 . V_70 == V_22 -> V_64 . V_78 ) {
V_47 . V_49 = 1 ;
V_47 . V_48 = 1 ;
}
if ( V_47 . V_54 == 100 && V_47 . V_51 == 100 )
V_119 -> V_119 = V_123 ;
else
V_119 -> V_119 = V_124 ;
V_119 -> F_24 = V_22 -> V_64 . V_67 * 100000 ;
V_119 -> V_69 = V_22 -> V_64 . V_78 * 100000 ;
V_119 -> V_120 . V_128 = V_22 -> V_64 . V_67 * 100000 ;
V_119 -> V_120 . V_121 = V_22 -> V_64 . V_78 * 100000 ;
V_119 -> V_120 . V_129 = V_130 ;
F_74 ( V_119 -> V_22 , V_119 -> V_131 ) ;
return 0 ;
}
static int F_75 ( void )
{
T_2 V_89 , V_90 , V_132 ;
F_31 ( V_94 , V_89 ) ;
F_31 ( V_95 , V_90 ) ;
if ( ! V_81 . V_84 () ||
! V_81 . V_83 () ||
! V_81 . V_85 () )
return - V_122 ;
F_31 ( V_94 , V_132 ) ;
if ( ! ( V_132 - V_89 ) )
return - V_122 ;
F_31 ( V_95 , V_132 ) ;
if ( ! ( V_132 - V_90 ) )
return - V_122 ;
return 0 ;
}
static void F_76 ( struct V_133 * V_119 )
{
V_23 . V_100 = V_119 -> V_100 ;
V_23 . V_24 = V_119 -> V_24 ;
V_23 . V_26 = V_119 -> V_26 ;
V_23 . V_25 = V_119 -> V_25 ;
V_23 . V_9 = V_119 -> V_9 ;
V_23 . V_7 = V_119 -> V_7 ;
}
static void F_77 ( struct V_81 * V_134 )
{
V_81 . V_84 = V_134 -> V_84 ;
V_81 . V_83 = V_134 -> V_83 ;
V_81 . V_85 = V_134 -> V_85 ;
V_81 . V_82 = V_134 -> V_82 ;
V_81 . V_86 = V_134 -> V_86 ;
}
static bool F_78 ( void )
{
int V_33 ;
F_79 (i) {
T_6 V_135 ;
union V_136 * V_137 ;
struct V_138 V_139 = { V_140 , NULL } ;
struct V_141 * V_142 = F_80 ( V_143 , V_33 ) ;
if ( ! V_142 )
continue;
V_135 = F_81 ( V_142 -> V_144 , L_7 , NULL , & V_139 ) ;
if ( F_82 ( V_135 ) )
continue;
V_137 = V_139 . V_145 ;
if ( V_137 && V_137 -> type == V_146 ) {
F_72 ( V_137 ) ;
return false ;
}
F_72 ( V_137 ) ;
}
return true ;
}
static bool F_83 ( void )
{
struct V_147 V_148 ;
struct V_149 * V_150 ;
if ( V_151 ||
F_82 ( F_84 ( V_152 , 0 , & V_148 ) ) )
return false ;
for ( V_150 = V_153 ; V_150 -> V_154 ; V_150 ++ ) {
if ( ! strncmp ( V_148 . V_155 , V_150 -> V_155 , V_156 ) &&
! strncmp ( V_148 . V_157 , V_150 -> V_157 , V_158 ) &&
F_78 () )
return true ;
}
return false ;
}
static inline bool F_83 ( void ) { return false ; }
static int T_3 F_85 ( void )
{
int V_22 , V_57 = 0 ;
const struct V_159 * V_160 ;
struct V_161 * V_162 ;
if ( V_163 )
return - V_122 ;
V_160 = F_86 ( V_164 ) ;
if ( ! V_160 )
return - V_122 ;
if ( F_83 () )
return - V_122 ;
V_162 = (struct V_161 * ) V_160 -> V_165 ;
F_76 ( & V_162 -> V_166 ) ;
F_77 ( & V_162 -> V_134 ) ;
if ( F_75 () )
return - V_122 ;
F_70 ( L_8 ) ;
V_27 = F_87 ( sizeof( void * ) * F_88 () ) ;
if ( ! V_27 )
return - V_113 ;
V_57 = F_89 ( & V_167 ) ;
if ( V_57 )
goto V_168;
F_16 () ;
F_26 () ;
return V_57 ;
V_168:
F_90 () ;
F_13 (cpu) {
if ( V_27 [ V_22 ] ) {
F_71 ( & V_27 [ V_22 ] -> V_101 ) ;
F_72 ( V_27 [ V_22 ] ) ;
}
}
F_91 () ;
F_92 ( V_27 ) ;
return - V_122 ;
}
static int T_3 F_93 ( char * V_169 )
{
if ( ! V_169 )
return - V_46 ;
if ( ! strcmp ( V_169 , L_9 ) )
V_163 = 1 ;
return 0 ;
}
