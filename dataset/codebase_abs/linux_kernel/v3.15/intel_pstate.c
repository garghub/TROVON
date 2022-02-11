static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 V_2 )
{
return F_3 ( ( V_3 ) V_1 << V_4 , ( V_3 ) V_2 ) ;
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
if ( V_16 >= 0 )
V_16 = V_16 + ( 1 << ( V_4 - 1 ) ) ;
else
V_16 = V_16 - ( 1 << ( V_4 - 1 ) ) ;
return ( signed int ) F_10 ( V_16 ) ;
}
static inline void F_11 ( struct V_21 * V_22 )
{
F_6 ( & V_22 -> V_6 , V_23 . V_24 ) ;
F_8 ( & V_22 -> V_6 , V_23 . V_25 ) ;
F_7 ( & V_22 -> V_6 , V_23 . V_26 ) ;
F_4 ( & V_22 -> V_6 ,
V_23 . V_7 ,
100 ,
V_23 . V_9 ,
0 ) ;
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
static void F_16 ( void )
{
int V_31 = 0 ;
V_32 = F_17 ( L_1 , NULL ) ;
if ( F_18 ( V_32 ) )
return;
while ( V_33 [ V_31 ] . V_34 ) {
F_19 ( V_33 [ V_31 ] . V_34 , 0660 ,
V_32 , V_33 [ V_31 ] . V_35 ,
& V_36 ) ;
V_31 ++ ;
}
}
static T_3 F_20 ( struct V_37 * V_38 , struct V_39 * V_40 ,
const char * V_41 , T_4 V_42 )
{
unsigned int V_43 ;
int V_44 ;
V_44 = sscanf ( V_41 , L_2 , & V_43 ) ;
if ( V_44 != 1 )
return - V_45 ;
V_46 . V_47 = F_21 ( int , V_43 , 0 , 1 ) ;
return V_42 ;
}
static T_3 F_22 ( struct V_37 * V_38 , struct V_39 * V_40 ,
const char * V_41 , T_4 V_42 )
{
unsigned int V_43 ;
int V_44 ;
V_44 = sscanf ( V_41 , L_2 , & V_43 ) ;
if ( V_44 != 1 )
return - V_45 ;
V_46 . V_48 = F_21 ( int , V_43 , 0 , 100 ) ;
V_46 . V_49 = F_23 ( V_46 . V_50 , V_46 . V_48 ) ;
V_46 . V_51 = F_2 ( F_5 ( V_46 . V_49 ) , F_5 ( 100 ) ) ;
return V_42 ;
}
static T_3 F_24 ( struct V_37 * V_38 , struct V_39 * V_40 ,
const char * V_41 , T_4 V_42 )
{
unsigned int V_43 ;
int V_44 ;
V_44 = sscanf ( V_41 , L_2 , & V_43 ) ;
if ( V_44 != 1 )
return - V_45 ;
V_46 . V_52 = F_21 ( int , V_43 , 0 , 100 ) ;
V_46 . V_53 = F_2 ( F_5 ( V_46 . V_52 ) , F_5 ( 100 ) ) ;
return V_42 ;
}
static void F_25 ( void )
{
int V_54 ;
V_55 = F_26 ( L_3 ,
& V_56 . V_57 -> V_58 ) ;
F_27 ( ! V_55 ) ;
V_54 = F_28 ( V_55 ,
& V_59 ) ;
F_27 ( V_54 ) ;
}
static int F_29 ( void )
{
T_2 V_35 ;
F_30 ( V_60 , V_35 ) ;
return ( V_35 >> 8 ) & 0x3F ;
}
static int F_31 ( void )
{
T_2 V_35 ;
F_30 ( V_60 , V_35 ) ;
return ( V_35 >> 16 ) & 0x3F ;
}
static int F_32 ( void )
{
T_2 V_35 ;
F_30 ( V_61 , V_35 ) ;
return V_35 & 0x3F ;
}
static void F_33 ( struct V_21 * V_21 , int V_62 )
{
T_2 V_29 ;
T_1 V_63 ;
V_30 V_64 ;
V_29 = V_62 << 8 ;
if ( V_46 . V_47 )
V_29 |= ( T_2 ) 1 << 32 ;
V_63 = V_21 -> V_64 . F_23 + F_1 (
F_5 ( V_62 - V_21 -> V_62 . V_65 ) ,
V_21 -> V_64 . V_66 ) ;
V_63 = F_21 ( T_1 , V_63 , V_21 -> V_64 . F_23 , V_21 -> V_64 . V_67 ) ;
V_64 = F_10 ( V_63 ) ;
if ( V_62 > V_21 -> V_62 . V_68 )
V_64 = V_21 -> V_64 . V_69 ;
V_29 |= V_64 ;
F_34 ( V_70 , V_29 ) ;
}
static void F_35 ( struct V_21 * V_21 )
{
T_2 V_35 ;
F_30 ( V_71 , V_35 ) ;
V_21 -> V_64 . F_23 = F_5 ( ( V_35 >> 8 ) & 0x3f ) ;
V_21 -> V_64 . V_67 = F_5 ( ( V_35 >> 16 ) & 0x3f ) ;
V_21 -> V_64 . V_66 = F_2 (
V_21 -> V_64 . V_67 - V_21 -> V_64 . F_23 ,
F_5 ( V_21 -> V_62 . V_68 -
V_21 -> V_62 . V_65 ) ) ;
F_30 ( V_72 , V_35 ) ;
V_21 -> V_64 . V_69 = V_35 & 0x7f ;
}
static int F_36 ( void )
{
T_2 V_35 ;
F_30 ( V_73 , V_35 ) ;
return ( V_35 >> 40 ) & 0xFF ;
}
static int F_37 ( void )
{
T_2 V_35 ;
F_30 ( V_73 , V_35 ) ;
return ( V_35 >> 8 ) & 0xFF ;
}
static int F_38 ( void )
{
T_2 V_35 ;
int V_74 , V_44 ;
F_30 ( V_75 , V_35 ) ;
V_74 = F_37 () ;
V_44 = ( ( V_35 ) & 255 ) ;
if ( V_44 <= V_74 )
V_44 = V_74 ;
return V_44 ;
}
static void F_39 ( struct V_21 * V_21 , int V_62 )
{
T_2 V_29 ;
V_29 = V_62 << 8 ;
if ( V_46 . V_47 )
V_29 |= ( T_2 ) 1 << 32 ;
F_40 ( V_21 -> V_22 , V_70 , V_29 ) ;
}
static void F_41 ( struct V_21 * V_22 , int * F_23 , int * V_67 )
{
int V_51 = V_22 -> V_62 . V_76 ;
int V_77 ;
int V_53 ;
if ( V_46 . V_47 )
V_51 = V_22 -> V_62 . V_68 ;
V_77 = F_10 ( F_1 ( F_5 ( V_51 ) , V_46 . V_51 ) ) ;
* V_67 = F_21 ( int , V_77 ,
V_22 -> V_62 . V_65 , V_22 -> V_62 . V_76 ) ;
V_53 = F_10 ( F_1 ( F_5 ( V_51 ) , V_46 . V_53 ) ) ;
* F_23 = F_21 ( int , V_53 ,
V_22 -> V_62 . V_65 , V_51 ) ;
}
static void F_42 ( struct V_21 * V_22 , int V_62 )
{
int V_51 , V_53 ;
F_41 ( V_22 , & V_53 , & V_51 ) ;
V_62 = F_21 ( int , V_62 , V_53 , V_51 ) ;
if ( V_62 == V_22 -> V_62 . V_78 )
return;
F_43 ( V_62 * 100000 , V_22 -> V_22 ) ;
V_22 -> V_62 . V_78 = V_62 ;
V_79 . V_80 ( V_22 , V_62 ) ;
}
static inline void F_44 ( struct V_21 * V_22 , int V_81 )
{
int V_82 ;
V_82 = V_22 -> V_62 . V_78 + V_81 ;
F_42 ( V_22 , V_82 ) ;
}
static inline void F_45 ( struct V_21 * V_22 , int V_81 )
{
int V_82 ;
V_82 = V_22 -> V_62 . V_78 - V_81 ;
F_42 ( V_22 , V_82 ) ;
}
static void F_46 ( struct V_21 * V_22 )
{
sprintf ( V_22 -> V_34 , L_4 ) ;
V_22 -> V_62 . V_65 = V_79 . V_83 () ;
V_22 -> V_62 . V_68 = V_79 . V_84 () ;
V_22 -> V_62 . V_76 = V_79 . V_85 () ;
if ( V_79 . V_86 )
V_79 . V_86 ( V_22 ) ;
F_42 ( V_22 , V_22 -> V_62 . V_65 ) ;
}
static inline void F_47 ( struct V_21 * V_22 ,
struct V_87 * V_87 )
{
V_3 V_88 ;
T_1 V_89 ;
V_88 = F_5 ( V_87 -> V_90 ) * F_5 ( 100 ) ;
V_88 = F_48 ( V_88 , F_5 ( V_87 -> V_91 ) , & V_89 ) ;
if ( ( V_89 << 1 ) >= F_5 ( V_87 -> V_91 ) )
V_88 += 1 ;
V_87 -> V_92 = F_10 (
F_1 ( F_5 ( V_22 -> V_62 . V_68 * 1000 ) , V_88 ) ) ;
V_87 -> V_93 = ( T_1 ) V_88 ;
}
static inline void F_49 ( struct V_21 * V_22 )
{
T_2 V_90 , V_91 ;
F_30 ( V_94 , V_90 ) ;
F_30 ( V_95 , V_91 ) ;
V_90 = V_90 >> V_4 ;
V_91 = V_91 >> V_4 ;
V_22 -> V_96 = V_22 -> V_87 . time ;
V_22 -> V_87 . time = F_50 () ;
V_22 -> V_87 . V_90 = V_90 ;
V_22 -> V_87 . V_91 = V_91 ;
V_22 -> V_87 . V_90 -= V_22 -> V_97 ;
V_22 -> V_87 . V_91 -= V_22 -> V_98 ;
F_47 ( V_22 , & V_22 -> V_87 ) ;
V_22 -> V_97 = V_90 ;
V_22 -> V_98 = V_91 ;
}
static inline void F_51 ( struct V_21 * V_22 )
{
int V_99 , V_100 ;
V_99 = V_23 . V_101 ;
V_100 = F_52 ( V_99 ) ;
F_53 ( & V_22 -> V_102 , V_103 + V_100 ) ;
}
static inline T_1 F_54 ( struct V_21 * V_22 )
{
T_1 V_104 , V_68 , V_78 , V_105 ;
V_30 V_106 ;
V_30 V_99 ;
V_104 = V_22 -> V_87 . V_93 ;
V_68 = F_5 ( V_22 -> V_62 . V_68 ) ;
V_78 = F_5 ( V_22 -> V_62 . V_78 ) ;
V_104 = F_1 ( V_104 , F_2 ( V_68 , V_78 ) ) ;
V_99 = ( V_23 . V_101 * V_107 ) ;
V_106 = ( V_30 ) F_55 ( V_22 -> V_87 . time ,
V_22 -> V_96 ) ;
if ( V_106 > V_99 * 3 ) {
V_105 = F_2 ( F_5 ( V_99 ) ,
F_5 ( V_106 ) ) ;
V_104 = F_1 ( V_104 , V_105 ) ;
}
return V_104 ;
}
static inline void F_56 ( struct V_21 * V_22 )
{
T_1 V_108 ;
struct V_5 * V_6 ;
signed int V_109 = 0 ;
int V_81 ;
V_6 = & V_22 -> V_6 ;
V_108 = F_54 ( V_22 ) ;
V_109 = F_9 ( V_6 , V_108 ) ;
V_81 = abs ( V_109 ) ;
if ( V_109 < 0 )
F_44 ( V_22 , V_81 ) ;
else
F_45 ( V_22 , V_81 ) ;
}
static void F_57 ( unsigned long V_110 )
{
struct V_21 * V_22 = (struct V_21 * ) V_110 ;
struct V_87 * V_87 ;
F_49 ( V_22 ) ;
V_87 = & V_22 -> V_87 ;
F_56 ( V_22 ) ;
F_58 ( F_10 ( V_87 -> V_93 ) ,
F_10 ( F_54 ( V_22 ) ) ,
V_22 -> V_62 . V_78 ,
V_87 -> V_91 ,
V_87 -> V_90 ,
V_87 -> V_92 ) ;
F_51 ( V_22 ) ;
}
static int F_59 ( unsigned int V_111 )
{
const struct V_112 * V_113 ;
struct V_21 * V_22 ;
V_113 = F_60 ( V_114 ) ;
if ( ! V_113 )
return - V_115 ;
V_27 [ V_111 ] = F_61 ( sizeof( struct V_21 ) , V_116 ) ;
if ( ! V_27 [ V_111 ] )
return - V_117 ;
V_22 = V_27 [ V_111 ] ;
F_46 ( V_22 ) ;
V_22 -> V_22 = V_111 ;
F_62 ( & V_22 -> V_102 ) ;
V_22 -> V_102 . V_118 = F_57 ;
V_22 -> V_102 . V_28 =
( unsigned long ) V_22 ;
V_22 -> V_102 . V_119 = V_103 + V_120 / 100 ;
F_11 ( V_22 ) ;
F_49 ( V_22 ) ;
F_63 ( & V_22 -> V_102 , V_111 ) ;
F_64 ( L_5 , V_111 ) ;
return 0 ;
}
static unsigned int F_65 ( unsigned int V_121 )
{
struct V_87 * V_87 ;
struct V_21 * V_22 ;
V_22 = V_27 [ V_121 ] ;
if ( ! V_22 )
return 0 ;
V_87 = & V_22 -> V_87 ;
return V_87 -> V_92 ;
}
static int F_66 ( struct V_122 * V_123 )
{
struct V_21 * V_22 ;
V_22 = V_27 [ V_123 -> V_22 ] ;
if ( ! V_123 -> V_124 . V_125 )
return - V_115 ;
if ( V_123 -> V_123 == V_126 ) {
V_46 . V_52 = 100 ;
V_46 . V_53 = F_5 ( 1 ) ;
V_46 . V_49 = 100 ;
V_46 . V_51 = F_5 ( 1 ) ;
V_46 . V_47 = 0 ;
return 0 ;
}
V_46 . V_52 = ( V_123 -> F_23 * 100 ) / V_123 -> V_124 . V_125 ;
V_46 . V_52 = F_21 ( int , V_46 . V_52 , 0 , 100 ) ;
V_46 . V_53 = F_2 ( F_5 ( V_46 . V_52 ) , F_5 ( 100 ) ) ;
V_46 . V_50 = V_123 -> V_67 * 100 / V_123 -> V_124 . V_125 ;
V_46 . V_50 = F_21 ( int , V_46 . V_50 , 0 , 100 ) ;
V_46 . V_49 = F_23 ( V_46 . V_50 , V_46 . V_48 ) ;
V_46 . V_51 = F_2 ( F_5 ( V_46 . V_49 ) , F_5 ( 100 ) ) ;
return 0 ;
}
static int F_67 ( struct V_122 * V_123 )
{
F_68 ( V_123 ) ;
if ( ( V_123 -> V_123 != V_127 ) &&
( V_123 -> V_123 != V_126 ) )
return - V_45 ;
return 0 ;
}
static void F_69 ( struct V_122 * V_123 )
{
int V_121 = V_123 -> V_22 ;
struct V_21 * V_22 = V_27 [ V_121 ] ;
F_64 ( L_6 , V_121 ) ;
F_70 ( & V_27 [ V_121 ] -> V_102 ) ;
F_42 ( V_22 , V_22 -> V_62 . V_65 ) ;
F_71 ( V_27 [ V_121 ] ) ;
V_27 [ V_121 ] = NULL ;
}
static int F_72 ( struct V_122 * V_123 )
{
struct V_21 * V_22 ;
int V_54 ;
V_54 = F_59 ( V_123 -> V_22 ) ;
if ( V_54 )
return V_54 ;
V_22 = V_27 [ V_123 -> V_22 ] ;
if ( ! V_46 . V_47 &&
V_46 . V_52 == 100 && V_46 . V_49 == 100 )
V_123 -> V_123 = V_126 ;
else
V_123 -> V_123 = V_127 ;
V_123 -> F_23 = V_22 -> V_62 . V_65 * 100000 ;
V_123 -> V_67 = V_22 -> V_62 . V_76 * 100000 ;
V_123 -> V_124 . V_128 = V_22 -> V_62 . V_65 * 100000 ;
V_123 -> V_124 . V_125 = V_22 -> V_62 . V_76 * 100000 ;
V_123 -> V_124 . V_129 = V_130 ;
F_73 ( V_123 -> V_22 , V_123 -> V_131 ) ;
return 0 ;
}
static int F_74 ( void )
{
T_2 V_90 , V_91 , V_132 ;
F_30 ( V_94 , V_90 ) ;
F_30 ( V_95 , V_91 ) ;
if ( ! V_79 . V_84 () ||
! V_79 . V_83 () ||
! V_79 . V_85 () )
return - V_115 ;
F_30 ( V_94 , V_132 ) ;
if ( ! ( V_132 - V_90 ) )
return - V_115 ;
F_30 ( V_95 , V_132 ) ;
if ( ! ( V_132 - V_91 ) )
return - V_115 ;
return 0 ;
}
static void F_75 ( struct V_133 * V_123 )
{
V_23 . V_101 = V_123 -> V_101 ;
V_23 . V_24 = V_123 -> V_24 ;
V_23 . V_26 = V_123 -> V_26 ;
V_23 . V_25 = V_123 -> V_25 ;
V_23 . V_9 = V_123 -> V_9 ;
V_23 . V_7 = V_123 -> V_7 ;
}
static void F_76 ( struct V_79 * V_134 )
{
V_79 . V_84 = V_134 -> V_84 ;
V_79 . V_83 = V_134 -> V_83 ;
V_79 . V_85 = V_134 -> V_85 ;
V_79 . V_80 = V_134 -> V_80 ;
V_79 . V_86 = V_134 -> V_86 ;
}
static bool F_77 ( void )
{
int V_31 ;
F_78 (i) {
T_5 V_135 ;
union V_136 * V_137 ;
struct V_138 V_139 = { V_140 , NULL } ;
struct V_141 * V_142 = F_79 ( V_143 , V_31 ) ;
if ( ! V_142 )
continue;
V_135 = F_80 ( V_142 -> V_144 , L_7 , NULL , & V_139 ) ;
if ( F_81 ( V_135 ) )
continue;
V_137 = V_139 . V_145 ;
if ( V_137 && V_137 -> type == V_146 ) {
F_71 ( V_137 ) ;
return false ;
}
F_71 ( V_137 ) ;
}
return true ;
}
static bool F_82 ( void )
{
struct V_147 V_148 ;
struct V_149 * V_150 ;
if ( V_151
|| F_81 ( F_83 ( V_152 , 0 , & V_148 ) ) )
return false ;
for ( V_150 = V_153 ; V_150 -> V_154 ; V_150 ++ ) {
if ( ! strncmp ( V_148 . V_155 , V_150 -> V_155 , V_156 )
&& ! strncmp ( V_148 . V_157 , V_150 -> V_157 , V_158 )
&& F_77 () )
return true ;
}
return false ;
}
static inline bool F_82 ( void ) { return false ; }
static int T_6 F_84 ( void )
{
int V_22 , V_54 = 0 ;
const struct V_112 * V_113 ;
struct V_159 * V_160 ;
if ( V_161 )
return - V_115 ;
V_113 = F_60 ( V_114 ) ;
if ( ! V_113 )
return - V_115 ;
if ( F_82 () )
return - V_115 ;
V_160 = (struct V_159 * ) V_113 -> V_162 ;
F_75 ( & V_160 -> V_163 ) ;
F_76 ( & V_160 -> V_134 ) ;
if ( F_74 () )
return - V_115 ;
F_64 ( L_8 ) ;
V_27 = F_85 ( sizeof( void * ) * F_86 () ) ;
if ( ! V_27 )
return - V_117 ;
V_54 = F_87 ( & V_164 ) ;
if ( V_54 )
goto V_165;
F_16 () ;
F_25 () ;
return V_54 ;
V_165:
F_88 () ;
F_13 (cpu) {
if ( V_27 [ V_22 ] ) {
F_70 ( & V_27 [ V_22 ] -> V_102 ) ;
F_71 ( V_27 [ V_22 ] ) ;
}
}
F_89 () ;
F_90 ( V_27 ) ;
return - V_115 ;
}
static int T_6 F_91 ( char * V_166 )
{
if ( ! V_166 )
return - V_45 ;
if ( ! strcmp ( V_166 , L_9 ) )
V_161 = 1 ;
return 0 ;
}
