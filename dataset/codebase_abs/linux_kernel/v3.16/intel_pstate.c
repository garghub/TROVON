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
V_16 = V_16 + ( 1 << ( V_4 - 1 ) ) ;
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
if ( V_46 . V_48 ) {
F_22 ( L_3 ) ;
V_46 . V_47 = V_46 . V_48 ;
}
return V_42 ;
}
static T_3 F_23 ( struct V_37 * V_38 , struct V_39 * V_40 ,
const char * V_41 , T_4 V_42 )
{
unsigned int V_43 ;
int V_44 ;
V_44 = sscanf ( V_41 , L_2 , & V_43 ) ;
if ( V_44 != 1 )
return - V_45 ;
V_46 . V_49 = F_21 ( int , V_43 , 0 , 100 ) ;
V_46 . V_50 = F_24 ( V_46 . V_51 , V_46 . V_49 ) ;
V_46 . V_52 = F_2 ( F_5 ( V_46 . V_50 ) , F_5 ( 100 ) ) ;
return V_42 ;
}
static T_3 F_25 ( struct V_37 * V_38 , struct V_39 * V_40 ,
const char * V_41 , T_4 V_42 )
{
unsigned int V_43 ;
int V_44 ;
V_44 = sscanf ( V_41 , L_2 , & V_43 ) ;
if ( V_44 != 1 )
return - V_45 ;
V_46 . V_53 = F_21 ( int , V_43 , 0 , 100 ) ;
V_46 . V_54 = F_2 ( F_5 ( V_46 . V_53 ) , F_5 ( 100 ) ) ;
return V_42 ;
}
static void F_26 ( void )
{
int V_55 ;
V_56 = F_27 ( L_4 ,
& V_57 . V_58 -> V_59 ) ;
F_28 ( ! V_56 ) ;
V_55 = F_29 ( V_56 ,
& V_60 ) ;
F_28 ( V_55 ) ;
}
static int F_30 ( void )
{
T_2 V_35 ;
F_31 ( V_61 , V_35 ) ;
return ( V_35 >> 8 ) & 0x7F ;
}
static int F_32 ( void )
{
T_2 V_35 ;
F_31 ( V_61 , V_35 ) ;
return ( V_35 >> 16 ) & 0x7F ;
}
static int F_33 ( void )
{
T_2 V_35 ;
F_31 ( V_62 , V_35 ) ;
return V_35 & 0x7F ;
}
static void F_34 ( struct V_21 * V_21 , int V_63 )
{
T_2 V_29 ;
T_1 V_64 ;
V_30 V_65 ;
V_29 = V_63 << 8 ;
if ( V_46 . V_47 && ! V_46 . V_48 )
V_29 |= ( T_2 ) 1 << 32 ;
V_64 = V_21 -> V_65 . F_24 + F_1 (
F_5 ( V_63 - V_21 -> V_63 . V_66 ) ,
V_21 -> V_65 . V_67 ) ;
V_64 = F_21 ( T_1 , V_64 , V_21 -> V_65 . F_24 , V_21 -> V_65 . V_68 ) ;
V_65 = F_10 ( V_64 ) ;
if ( V_63 > V_21 -> V_63 . V_69 )
V_65 = V_21 -> V_65 . V_70 ;
V_29 |= V_65 ;
F_35 ( V_71 , V_29 ) ;
}
static void F_36 ( struct V_21 * V_21 )
{
T_2 V_35 ;
F_31 ( V_72 , V_35 ) ;
V_21 -> V_65 . F_24 = F_5 ( ( V_35 >> 8 ) & 0x7f ) ;
V_21 -> V_65 . V_68 = F_5 ( ( V_35 >> 16 ) & 0x7f ) ;
V_21 -> V_65 . V_67 = F_2 (
V_21 -> V_65 . V_68 - V_21 -> V_65 . F_24 ,
F_5 ( V_21 -> V_63 . V_69 -
V_21 -> V_63 . V_66 ) ) ;
F_31 ( V_73 , V_35 ) ;
V_21 -> V_65 . V_70 = V_35 & 0x7f ;
}
static int F_37 ( void )
{
T_2 V_35 ;
F_31 ( V_74 , V_35 ) ;
return ( V_35 >> 40 ) & 0xFF ;
}
static int F_38 ( void )
{
T_2 V_35 ;
F_31 ( V_74 , V_35 ) ;
return ( V_35 >> 8 ) & 0xFF ;
}
static int F_39 ( void )
{
T_2 V_35 ;
int V_75 , V_44 ;
F_31 ( V_76 , V_35 ) ;
V_75 = F_38 () ;
V_44 = ( ( V_35 ) & 255 ) ;
if ( V_44 <= V_75 )
V_44 = V_75 ;
return V_44 ;
}
static void F_40 ( struct V_21 * V_21 , int V_63 )
{
T_2 V_29 ;
V_29 = V_63 << 8 ;
if ( V_46 . V_47 && ! V_46 . V_48 )
V_29 |= ( T_2 ) 1 << 32 ;
F_41 ( V_21 -> V_22 , V_71 , V_29 ) ;
}
static void F_42 ( struct V_21 * V_22 , int * F_24 , int * V_68 )
{
int V_52 = V_22 -> V_63 . V_77 ;
int V_78 ;
int V_54 ;
if ( V_46 . V_47 )
V_52 = V_22 -> V_63 . V_69 ;
V_78 = F_10 ( F_1 ( F_5 ( V_52 ) , V_46 . V_52 ) ) ;
* V_68 = F_21 ( int , V_78 ,
V_22 -> V_63 . V_66 , V_22 -> V_63 . V_77 ) ;
V_54 = F_10 ( F_1 ( F_5 ( V_52 ) , V_46 . V_54 ) ) ;
* F_24 = F_21 ( int , V_54 ,
V_22 -> V_63 . V_66 , V_52 ) ;
}
static void F_43 ( struct V_21 * V_22 , int V_63 )
{
int V_52 , V_54 ;
F_42 ( V_22 , & V_54 , & V_52 ) ;
V_63 = F_21 ( int , V_63 , V_54 , V_52 ) ;
if ( V_63 == V_22 -> V_63 . V_79 )
return;
F_44 ( V_63 * 100000 , V_22 -> V_22 ) ;
V_22 -> V_63 . V_79 = V_63 ;
V_80 . V_81 ( V_22 , V_63 ) ;
}
static inline void F_45 ( struct V_21 * V_22 , int V_82 )
{
int V_83 ;
V_83 = V_22 -> V_63 . V_79 + V_82 ;
F_43 ( V_22 , V_83 ) ;
}
static inline void F_46 ( struct V_21 * V_22 , int V_82 )
{
int V_83 ;
V_83 = V_22 -> V_63 . V_79 - V_82 ;
F_43 ( V_22 , V_83 ) ;
}
static void F_47 ( struct V_21 * V_22 )
{
V_22 -> V_63 . V_66 = V_80 . V_84 () ;
V_22 -> V_63 . V_69 = V_80 . V_85 () ;
V_22 -> V_63 . V_77 = V_80 . V_86 () ;
if ( V_80 . V_87 )
V_80 . V_87 ( V_22 ) ;
F_43 ( V_22 , V_22 -> V_63 . V_66 ) ;
}
static inline void F_48 ( struct V_21 * V_22 )
{
struct V_88 * V_88 = & V_22 -> V_88 ;
V_3 V_89 ;
T_1 V_90 ;
V_89 = F_5 ( V_88 -> V_91 ) * F_5 ( 100 ) ;
V_89 = F_49 ( V_89 , F_5 ( V_88 -> V_92 ) , & V_90 ) ;
if ( ( V_90 << 1 ) >= F_5 ( V_88 -> V_92 ) )
V_89 += 1 ;
V_88 -> V_93 = F_10 (
F_1 ( F_5 ( V_22 -> V_63 . V_69 * 1000 ) , V_89 ) ) ;
V_88 -> V_94 = ( T_1 ) V_89 ;
}
static inline void F_50 ( struct V_21 * V_22 )
{
T_2 V_91 , V_92 ;
F_31 ( V_95 , V_91 ) ;
F_31 ( V_96 , V_92 ) ;
V_91 = V_91 >> V_4 ;
V_92 = V_92 >> V_4 ;
V_22 -> V_97 = V_22 -> V_88 . time ;
V_22 -> V_88 . time = F_51 () ;
V_22 -> V_88 . V_91 = V_91 ;
V_22 -> V_88 . V_92 = V_92 ;
V_22 -> V_88 . V_91 -= V_22 -> V_98 ;
V_22 -> V_88 . V_92 -= V_22 -> V_99 ;
F_48 ( V_22 ) ;
V_22 -> V_98 = V_91 ;
V_22 -> V_99 = V_92 ;
}
static inline void F_52 ( struct V_21 * V_22 )
{
int V_100 , V_101 ;
V_100 = V_23 . V_102 ;
V_101 = F_53 ( V_100 ) ;
F_54 ( & V_22 -> V_103 , V_104 + V_101 ) ;
}
static inline T_1 F_55 ( struct V_21 * V_22 )
{
T_1 V_105 , V_69 , V_79 , V_106 ;
V_30 V_107 ;
V_30 V_100 ;
V_105 = V_22 -> V_88 . V_94 ;
V_69 = F_5 ( V_22 -> V_63 . V_69 ) ;
V_79 = F_5 ( V_22 -> V_63 . V_79 ) ;
V_105 = F_1 ( V_105 , F_2 ( V_69 , V_79 ) ) ;
V_100 = ( V_23 . V_102 * V_108 ) ;
V_107 = ( V_30 ) F_56 ( V_22 -> V_88 . time ,
V_22 -> V_97 ) ;
if ( V_107 > V_100 * 3 ) {
V_106 = F_2 ( F_5 ( V_100 ) ,
F_5 ( V_107 ) ) ;
V_105 = F_1 ( V_105 , V_106 ) ;
}
return V_105 ;
}
static inline void F_57 ( struct V_21 * V_22 )
{
T_1 V_109 ;
struct V_5 * V_6 ;
signed int V_110 = 0 ;
int V_82 ;
V_6 = & V_22 -> V_6 ;
V_109 = F_55 ( V_22 ) ;
V_110 = F_9 ( V_6 , V_109 ) ;
V_82 = abs ( V_110 ) ;
if ( V_110 < 0 )
F_45 ( V_22 , V_82 ) ;
else
F_46 ( V_22 , V_82 ) ;
}
static void F_58 ( unsigned long V_111 )
{
struct V_21 * V_22 = (struct V_21 * ) V_111 ;
struct V_88 * V_88 ;
F_50 ( V_22 ) ;
V_88 = & V_22 -> V_88 ;
F_57 ( V_22 ) ;
F_59 ( F_10 ( V_88 -> V_94 ) ,
F_10 ( F_55 ( V_22 ) ) ,
V_22 -> V_63 . V_79 ,
V_88 -> V_92 ,
V_88 -> V_91 ,
V_88 -> V_93 ) ;
F_52 ( V_22 ) ;
}
static int F_60 ( unsigned int V_112 )
{
struct V_21 * V_22 ;
V_27 [ V_112 ] = F_61 ( sizeof( struct V_21 ) , V_113 ) ;
if ( ! V_27 [ V_112 ] )
return - V_114 ;
V_22 = V_27 [ V_112 ] ;
V_22 -> V_22 = V_112 ;
F_47 ( V_22 ) ;
F_62 ( & V_22 -> V_103 ) ;
V_22 -> V_103 . V_115 = F_58 ;
V_22 -> V_103 . V_28 =
( unsigned long ) V_22 ;
V_22 -> V_103 . V_116 = V_104 + V_117 / 100 ;
F_11 ( V_22 ) ;
F_50 ( V_22 ) ;
F_63 ( & V_22 -> V_103 , V_112 ) ;
F_64 ( L_5 , V_112 ) ;
return 0 ;
}
static unsigned int F_65 ( unsigned int V_118 )
{
struct V_88 * V_88 ;
struct V_21 * V_22 ;
V_22 = V_27 [ V_118 ] ;
if ( ! V_22 )
return 0 ;
V_88 = & V_22 -> V_88 ;
return V_88 -> V_93 ;
}
static int F_66 ( struct V_119 * V_120 )
{
struct V_21 * V_22 ;
V_22 = V_27 [ V_120 -> V_22 ] ;
if ( ! V_120 -> V_121 . V_122 )
return - V_123 ;
if ( V_120 -> V_120 == V_124 ) {
V_46 . V_53 = 100 ;
V_46 . V_54 = F_5 ( 1 ) ;
V_46 . V_50 = 100 ;
V_46 . V_52 = F_5 ( 1 ) ;
V_46 . V_47 = V_46 . V_48 ;
return 0 ;
}
V_46 . V_53 = ( V_120 -> F_24 * 100 ) / V_120 -> V_121 . V_122 ;
V_46 . V_53 = F_21 ( int , V_46 . V_53 , 0 , 100 ) ;
V_46 . V_54 = F_2 ( F_5 ( V_46 . V_53 ) , F_5 ( 100 ) ) ;
V_46 . V_51 = V_120 -> V_68 * 100 / V_120 -> V_121 . V_122 ;
V_46 . V_51 = F_21 ( int , V_46 . V_51 , 0 , 100 ) ;
V_46 . V_50 = F_24 ( V_46 . V_51 , V_46 . V_49 ) ;
V_46 . V_52 = F_2 ( F_5 ( V_46 . V_50 ) , F_5 ( 100 ) ) ;
return 0 ;
}
static int F_67 ( struct V_119 * V_120 )
{
F_68 ( V_120 ) ;
if ( ( V_120 -> V_120 != V_125 ) &&
( V_120 -> V_120 != V_124 ) )
return - V_45 ;
return 0 ;
}
static void F_69 ( struct V_119 * V_120 )
{
int V_118 = V_120 -> V_22 ;
struct V_21 * V_22 = V_27 [ V_118 ] ;
F_64 ( L_6 , V_118 ) ;
F_70 ( & V_27 [ V_118 ] -> V_103 ) ;
F_43 ( V_22 , V_22 -> V_63 . V_66 ) ;
F_71 ( V_27 [ V_118 ] ) ;
V_27 [ V_118 ] = NULL ;
}
static int F_72 ( struct V_119 * V_120 )
{
struct V_21 * V_22 ;
int V_55 ;
T_2 V_126 ;
V_55 = F_60 ( V_120 -> V_22 ) ;
if ( V_55 )
return V_55 ;
V_22 = V_27 [ V_120 -> V_22 ] ;
F_31 ( V_127 , V_126 ) ;
if ( V_126 & V_128 ||
V_22 -> V_63 . V_69 == V_22 -> V_63 . V_77 ) {
V_46 . V_48 = 1 ;
V_46 . V_47 = 1 ;
}
if ( V_46 . V_53 == 100 && V_46 . V_50 == 100 )
V_120 -> V_120 = V_124 ;
else
V_120 -> V_120 = V_125 ;
V_120 -> F_24 = V_22 -> V_63 . V_66 * 100000 ;
V_120 -> V_68 = V_22 -> V_63 . V_77 * 100000 ;
V_120 -> V_121 . V_129 = V_22 -> V_63 . V_66 * 100000 ;
V_120 -> V_121 . V_122 = V_22 -> V_63 . V_77 * 100000 ;
V_120 -> V_121 . V_130 = V_131 ;
F_73 ( V_120 -> V_22 , V_120 -> V_132 ) ;
return 0 ;
}
static int F_74 ( void )
{
T_2 V_91 , V_92 , V_133 ;
F_31 ( V_95 , V_91 ) ;
F_31 ( V_96 , V_92 ) ;
if ( ! V_80 . V_85 () ||
! V_80 . V_84 () ||
! V_80 . V_86 () )
return - V_123 ;
F_31 ( V_95 , V_133 ) ;
if ( ! ( V_133 - V_91 ) )
return - V_123 ;
F_31 ( V_96 , V_133 ) ;
if ( ! ( V_133 - V_92 ) )
return - V_123 ;
return 0 ;
}
static void F_75 ( struct V_134 * V_120 )
{
V_23 . V_102 = V_120 -> V_102 ;
V_23 . V_24 = V_120 -> V_24 ;
V_23 . V_26 = V_120 -> V_26 ;
V_23 . V_25 = V_120 -> V_25 ;
V_23 . V_9 = V_120 -> V_9 ;
V_23 . V_7 = V_120 -> V_7 ;
}
static void F_76 ( struct V_80 * V_135 )
{
V_80 . V_85 = V_135 -> V_85 ;
V_80 . V_84 = V_135 -> V_84 ;
V_80 . V_86 = V_135 -> V_86 ;
V_80 . V_81 = V_135 -> V_81 ;
V_80 . V_87 = V_135 -> V_87 ;
}
static bool F_77 ( void )
{
int V_31 ;
F_78 (i) {
T_5 V_136 ;
union V_137 * V_138 ;
struct V_139 V_140 = { V_141 , NULL } ;
struct V_142 * V_143 = F_79 ( V_144 , V_31 ) ;
if ( ! V_143 )
continue;
V_136 = F_80 ( V_143 -> V_145 , L_7 , NULL , & V_140 ) ;
if ( F_81 ( V_136 ) )
continue;
V_138 = V_140 . V_146 ;
if ( V_138 && V_138 -> type == V_147 ) {
F_71 ( V_138 ) ;
return false ;
}
F_71 ( V_138 ) ;
}
return true ;
}
static bool F_82 ( void )
{
struct V_148 V_149 ;
struct V_150 * V_151 ;
if ( V_152
|| F_81 ( F_83 ( V_153 , 0 , & V_149 ) ) )
return false ;
for ( V_151 = V_154 ; V_151 -> V_155 ; V_151 ++ ) {
if ( ! strncmp ( V_149 . V_156 , V_151 -> V_156 , V_157 )
&& ! strncmp ( V_149 . V_158 , V_151 -> V_158 , V_159 )
&& F_77 () )
return true ;
}
return false ;
}
static inline bool F_82 ( void ) { return false ; }
static int T_6 F_84 ( void )
{
int V_22 , V_55 = 0 ;
const struct V_160 * V_161 ;
struct V_162 * V_163 ;
if ( V_164 )
return - V_123 ;
V_161 = F_85 ( V_165 ) ;
if ( ! V_161 )
return - V_123 ;
if ( F_82 () )
return - V_123 ;
V_163 = (struct V_162 * ) V_161 -> V_166 ;
F_75 ( & V_163 -> V_167 ) ;
F_76 ( & V_163 -> V_135 ) ;
if ( F_74 () )
return - V_123 ;
F_64 ( L_8 ) ;
V_27 = F_86 ( sizeof( void * ) * F_87 () ) ;
if ( ! V_27 )
return - V_114 ;
V_55 = F_88 ( & V_168 ) ;
if ( V_55 )
goto V_169;
F_16 () ;
F_26 () ;
return V_55 ;
V_169:
F_89 () ;
F_13 (cpu) {
if ( V_27 [ V_22 ] ) {
F_70 ( & V_27 [ V_22 ] -> V_103 ) ;
F_71 ( V_27 [ V_22 ] ) ;
}
}
F_90 () ;
F_91 ( V_27 ) ;
return - V_123 ;
}
static int T_6 F_92 ( char * V_170 )
{
if ( ! V_170 )
return - V_45 ;
if ( ! strcmp ( V_170 , L_9 ) )
V_164 = 1 ;
return 0 ;
}
