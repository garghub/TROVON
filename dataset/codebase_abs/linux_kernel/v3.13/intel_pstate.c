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
V_6 -> V_11 = V_7 - V_8 ;
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
return V_35 & 0xFF ;
}
static int F_31 ( void )
{
T_2 V_35 ;
F_30 ( V_60 , V_35 ) ;
return ( V_35 >> 16 ) & 0xFF ;
}
static int F_32 ( void )
{
T_2 V_35 ;
F_30 ( V_61 , V_35 ) ;
return ( V_35 >> 40 ) & 0xFF ;
}
static int F_33 ( void )
{
T_2 V_35 ;
F_30 ( V_61 , V_35 ) ;
return ( V_35 >> 8 ) & 0xFF ;
}
static int F_34 ( void )
{
T_2 V_35 ;
int V_62 , V_44 ;
F_30 ( V_63 , V_35 ) ;
V_62 = F_33 () ;
V_44 = ( ( V_35 ) & 255 ) ;
if ( V_44 <= V_62 )
V_44 = V_62 ;
return V_44 ;
}
static void F_35 ( int V_64 )
{
T_2 V_29 ;
V_29 = V_64 << 8 ;
if ( V_46 . V_47 )
V_29 |= ( T_2 ) 1 << 32 ;
F_36 ( V_65 , V_29 ) ;
}
static void F_37 ( struct V_21 * V_22 , int * F_23 , int * V_66 )
{
int V_51 = V_22 -> V_64 . V_67 ;
int V_68 ;
int V_53 ;
if ( V_46 . V_47 )
V_51 = V_22 -> V_64 . V_69 ;
V_68 = F_10 ( F_1 ( F_5 ( V_51 ) , V_46 . V_51 ) ) ;
* V_66 = F_21 ( int , V_68 ,
V_22 -> V_64 . V_70 , V_22 -> V_64 . V_67 ) ;
V_53 = F_10 ( F_1 ( F_5 ( V_51 ) , V_46 . V_53 ) ) ;
* F_23 = F_21 ( int , V_53 ,
V_22 -> V_64 . V_70 , V_51 ) ;
}
static void F_38 ( struct V_21 * V_22 , int V_64 )
{
int V_51 , V_53 ;
F_37 ( V_22 , & V_53 , & V_51 ) ;
V_64 = F_21 ( int , V_64 , V_53 , V_51 ) ;
if ( V_64 == V_22 -> V_64 . V_71 )
return;
F_39 ( V_64 * 100000 , V_22 -> V_22 ) ;
V_22 -> V_64 . V_71 = V_64 ;
V_72 . V_73 ( V_64 ) ;
}
static inline void F_40 ( struct V_21 * V_22 , int V_74 )
{
int V_75 ;
V_75 = V_22 -> V_64 . V_71 + V_74 ;
F_38 ( V_22 , V_75 ) ;
}
static inline void F_41 ( struct V_21 * V_22 , int V_74 )
{
int V_75 ;
V_75 = V_22 -> V_64 . V_71 - V_74 ;
F_38 ( V_22 , V_75 ) ;
}
static void F_42 ( struct V_21 * V_22 )
{
sprintf ( V_22 -> V_34 , L_4 ) ;
V_22 -> V_64 . V_70 = V_72 . V_76 () ;
V_22 -> V_64 . V_69 = V_72 . V_77 () ;
V_22 -> V_64 . V_67 = V_72 . V_78 () ;
F_38 ( V_22 , V_22 -> V_64 . V_69 ) ;
}
static inline void F_43 ( struct V_21 * V_22 ,
struct V_79 * V_79 )
{
T_2 V_80 ;
V_80 = F_44 ( F_5 ( V_79 -> V_81 * 100 ) ,
V_79 -> V_82 ) ;
V_79 -> V_83 = F_10 ( V_22 -> V_64 . V_69 * V_80 * 1000 ) ;
V_79 -> V_84 = V_80 ;
}
static inline void F_45 ( struct V_21 * V_22 )
{
T_2 V_81 , V_82 ;
F_30 ( V_85 , V_81 ) ;
F_30 ( V_86 , V_82 ) ;
V_22 -> V_87 = ( V_22 -> V_87 + 1 ) % V_88 ;
V_22 -> V_89 [ V_22 -> V_87 ] . V_81 = V_81 ;
V_22 -> V_89 [ V_22 -> V_87 ] . V_82 = V_82 ;
V_22 -> V_89 [ V_22 -> V_87 ] . V_81 -= V_22 -> V_90 ;
V_22 -> V_89 [ V_22 -> V_87 ] . V_82 -= V_22 -> V_91 ;
F_43 ( V_22 , & V_22 -> V_89 [ V_22 -> V_87 ] ) ;
V_22 -> V_90 = V_81 ;
V_22 -> V_91 = V_82 ;
}
static inline void F_46 ( struct V_21 * V_22 )
{
int V_92 , V_93 ;
V_92 = V_23 . V_94 ;
V_93 = F_47 ( V_92 ) ;
F_48 ( & V_22 -> V_95 , V_96 + V_93 ) ;
}
static inline T_1 F_49 ( struct V_21 * V_22 )
{
T_1 V_97 , V_69 , V_71 ;
V_97 = V_22 -> V_89 [ V_22 -> V_87 ] . V_84 ;
V_69 = F_5 ( V_22 -> V_64 . V_69 ) ;
V_71 = F_5 ( V_22 -> V_64 . V_71 ) ;
return F_1 ( V_97 , F_2 ( V_69 , V_71 ) ) ;
}
static inline void F_50 ( struct V_21 * V_22 )
{
T_1 V_98 ;
struct V_5 * V_6 ;
signed int V_99 = 0 ;
int V_74 ;
V_6 = & V_22 -> V_6 ;
V_98 = F_49 ( V_22 ) ;
V_99 = F_9 ( V_6 , V_98 ) ;
V_74 = abs ( V_99 ) ;
if ( V_99 < 0 )
F_40 ( V_22 , V_74 ) ;
else
F_41 ( V_22 , V_74 ) ;
}
static void F_51 ( unsigned long V_100 )
{
struct V_21 * V_22 = (struct V_21 * ) V_100 ;
F_45 ( V_22 ) ;
F_50 ( V_22 ) ;
if ( V_22 -> V_64 . V_71 == V_22 -> V_64 . V_70 ) {
V_22 -> V_101 ++ ;
if ( ! ( V_22 -> V_101 % 5 ) ) {
F_38 ( V_22 , V_22 -> V_64 . V_69 ) ;
}
} else
V_22 -> V_101 = 0 ;
F_46 ( V_22 ) ;
}
static int F_52 ( unsigned int V_102 )
{
const struct V_103 * V_104 ;
struct V_21 * V_22 ;
V_104 = F_53 ( V_105 ) ;
if ( ! V_104 )
return - V_106 ;
V_27 [ V_102 ] = F_54 ( sizeof( struct V_21 ) , V_107 ) ;
if ( ! V_27 [ V_102 ] )
return - V_108 ;
V_22 = V_27 [ V_102 ] ;
F_42 ( V_22 ) ;
if ( ! V_22 -> V_64 . V_71 ) {
V_27 [ V_102 ] = NULL ;
F_55 ( V_22 ) ;
return - V_109 ;
}
V_22 -> V_22 = V_102 ;
F_56 ( & V_22 -> V_95 ) ;
V_22 -> V_95 . V_110 = F_51 ;
V_22 -> V_95 . V_28 =
( unsigned long ) V_22 ;
V_22 -> V_95 . V_111 = V_96 + V_112 / 100 ;
F_11 ( V_22 ) ;
F_45 ( V_22 ) ;
F_38 ( V_22 , V_22 -> V_64 . V_69 ) ;
F_57 ( & V_22 -> V_95 , V_102 ) ;
F_58 ( L_5 , V_102 ) ;
return 0 ;
}
static unsigned int F_59 ( unsigned int V_113 )
{
struct V_79 * V_79 ;
struct V_21 * V_22 ;
V_22 = V_27 [ V_113 ] ;
if ( ! V_22 )
return 0 ;
V_79 = & V_22 -> V_89 [ V_22 -> V_87 ] ;
return V_79 -> V_83 ;
}
static int F_60 ( struct V_114 * V_115 )
{
struct V_21 * V_22 ;
V_22 = V_27 [ V_115 -> V_22 ] ;
if ( ! V_115 -> V_116 . V_117 )
return - V_106 ;
if ( V_115 -> V_115 == V_118 ) {
V_46 . V_52 = 100 ;
V_46 . V_53 = F_5 ( 1 ) ;
V_46 . V_49 = 100 ;
V_46 . V_51 = F_5 ( 1 ) ;
V_46 . V_47 = 0 ;
return 0 ;
}
V_46 . V_52 = ( V_115 -> F_23 * 100 ) / V_115 -> V_116 . V_117 ;
V_46 . V_52 = F_21 ( int , V_46 . V_52 , 0 , 100 ) ;
V_46 . V_53 = F_2 ( F_5 ( V_46 . V_52 ) , F_5 ( 100 ) ) ;
V_46 . V_50 = V_115 -> V_66 * 100 / V_115 -> V_116 . V_117 ;
V_46 . V_50 = F_21 ( int , V_46 . V_50 , 0 , 100 ) ;
V_46 . V_49 = F_23 ( V_46 . V_50 , V_46 . V_48 ) ;
V_46 . V_51 = F_2 ( F_5 ( V_46 . V_49 ) , F_5 ( 100 ) ) ;
return 0 ;
}
static int F_61 ( struct V_114 * V_115 )
{
F_62 ( V_115 ) ;
if ( ( V_115 -> V_115 != V_119 ) &&
( V_115 -> V_115 != V_118 ) )
return - V_45 ;
return 0 ;
}
static int F_63 ( struct V_114 * V_115 )
{
int V_22 = V_115 -> V_22 ;
F_64 ( & V_27 [ V_22 ] -> V_95 ) ;
F_55 ( V_27 [ V_22 ] ) ;
V_27 [ V_22 ] = NULL ;
return 0 ;
}
static int F_65 ( struct V_114 * V_115 )
{
struct V_21 * V_22 ;
int V_54 ;
V_54 = F_52 ( V_115 -> V_22 ) ;
if ( V_54 )
return V_54 ;
V_22 = V_27 [ V_115 -> V_22 ] ;
if ( ! V_46 . V_47 &&
V_46 . V_52 == 100 && V_46 . V_49 == 100 )
V_115 -> V_115 = V_118 ;
else
V_115 -> V_115 = V_119 ;
V_115 -> F_23 = V_22 -> V_64 . V_70 * 100000 ;
V_115 -> V_66 = V_22 -> V_64 . V_67 * 100000 ;
V_115 -> V_116 . V_120 = V_22 -> V_64 . V_70 * 100000 ;
V_115 -> V_116 . V_117 = V_22 -> V_64 . V_67 * 100000 ;
V_115 -> V_116 . V_121 = V_122 ;
F_66 ( V_115 -> V_22 , V_115 -> V_123 ) ;
return 0 ;
}
static int F_67 ( void )
{
T_2 V_81 , V_82 , V_124 ;
F_30 ( V_85 , V_81 ) ;
F_30 ( V_86 , V_82 ) ;
if ( ! V_72 . V_77 () ||
! V_72 . V_76 () ||
! V_72 . V_78 () )
return - V_106 ;
F_30 ( V_85 , V_124 ) ;
if ( ! ( V_124 - V_81 ) )
return - V_106 ;
F_30 ( V_86 , V_124 ) ;
if ( ! ( V_124 - V_82 ) )
return - V_106 ;
return 0 ;
}
static void F_68 ( struct V_125 * V_115 )
{
V_23 . V_94 = V_115 -> V_94 ;
V_23 . V_24 = V_115 -> V_24 ;
V_23 . V_26 = V_115 -> V_26 ;
V_23 . V_25 = V_115 -> V_25 ;
V_23 . V_9 = V_115 -> V_9 ;
V_23 . V_7 = V_115 -> V_7 ;
}
static void F_69 ( struct V_72 * V_126 )
{
V_72 . V_77 = V_126 -> V_77 ;
V_72 . V_76 = V_126 -> V_76 ;
V_72 . V_78 = V_126 -> V_78 ;
V_72 . V_73 = V_126 -> V_73 ;
}
static bool F_70 ( void )
{
int V_31 ;
F_71 (i) {
T_5 V_127 ;
union V_128 * V_129 ;
struct V_130 V_131 = { V_132 , NULL } ;
struct V_133 * V_134 = F_72 ( V_135 , V_31 ) ;
if ( ! V_134 )
continue;
V_127 = F_73 ( V_134 -> V_136 , L_6 , NULL , & V_131 ) ;
if ( F_74 ( V_127 ) )
continue;
V_129 = V_131 . V_137 ;
if ( V_129 && V_129 -> type == V_138 ) {
F_55 ( V_129 ) ;
return false ;
}
F_55 ( V_129 ) ;
}
return true ;
}
static bool F_75 ( void )
{
struct V_139 V_140 ;
struct V_141 * V_142 ;
if ( V_143
|| F_74 ( F_76 ( V_144 , 0 , & V_140 ) ) )
return false ;
for ( V_142 = V_145 ; V_142 -> V_146 ; V_142 ++ ) {
if ( ! strncmp ( V_140 . V_147 , V_142 -> V_147 , V_148 )
&& ! strncmp ( V_140 . V_149 , V_142 -> V_149 , V_150 )
&& F_70 () )
return true ;
}
return false ;
}
static inline bool F_75 ( void ) { return false ; }
static int T_6 F_77 ( void )
{
int V_22 , V_54 = 0 ;
const struct V_103 * V_104 ;
struct V_151 * V_152 ;
if ( V_153 )
return - V_106 ;
V_104 = F_53 ( V_105 ) ;
if ( ! V_104 )
return - V_106 ;
if ( F_75 () )
return - V_106 ;
V_152 = (struct V_151 * ) V_104 -> V_154 ;
F_68 ( & V_152 -> V_155 ) ;
F_69 ( & V_152 -> V_126 ) ;
if ( F_67 () )
return - V_106 ;
F_58 ( L_7 ) ;
V_27 = F_78 ( sizeof( void * ) * F_79 () ) ;
if ( ! V_27 )
return - V_108 ;
V_54 = F_80 ( & V_156 ) ;
if ( V_54 )
goto V_157;
F_16 () ;
F_25 () ;
return V_54 ;
V_157:
F_81 () ;
F_13 (cpu) {
if ( V_27 [ V_22 ] ) {
F_82 ( & V_27 [ V_22 ] -> V_95 ) ;
F_55 ( V_27 [ V_22 ] ) ;
}
}
F_83 () ;
F_84 ( V_27 ) ;
return - V_106 ;
}
static int T_6 F_85 ( char * V_158 )
{
if ( ! V_158 )
return - V_45 ;
if ( ! strcmp ( V_158 , L_8 ) )
V_153 = 1 ;
return 0 ;
}
