static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 V_2 )
{
return F_3 ( ( V_3 ) V_1 << V_4 , V_2 ) ;
}
static inline int F_4 ( T_1 V_1 )
{
int V_5 , V_6 ;
V_6 = F_5 ( V_1 ) ;
V_5 = ( 1 << V_4 ) - 1 ;
if ( V_1 & V_5 )
V_6 += 1 ;
return V_6 ;
}
static inline void F_6 ( struct V_7 * V_8 , int V_9 , int V_10 ,
int V_11 , int V_12 ) {
V_8 -> V_9 = V_9 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_12 = F_7 ( V_12 ) ;
V_8 -> V_13 = F_7 ( V_9 ) - F_7 ( V_10 ) ;
}
static inline void F_8 ( struct V_7 * V_8 , int V_14 )
{
V_8 -> V_15 = F_2 ( F_7 ( V_14 ) , F_7 ( 100 ) ) ;
}
static inline void F_9 ( struct V_7 * V_8 , int V_14 )
{
V_8 -> V_16 = F_2 ( F_7 ( V_14 ) , F_7 ( 100 ) ) ;
}
static inline void F_10 ( struct V_7 * V_8 , int V_14 )
{
V_8 -> V_17 = F_2 ( F_7 ( V_14 ) , F_7 ( 100 ) ) ;
}
static signed int F_11 ( struct V_7 * V_8 , T_1 V_10 )
{
signed int V_18 ;
T_1 V_19 , V_20 , V_21 ;
T_1 V_22 ;
V_21 = F_7 ( V_8 -> V_9 ) - V_10 ;
if ( abs ( V_21 ) <= F_7 ( V_8 -> V_11 ) )
return 0 ;
V_19 = F_1 ( V_8 -> V_15 , V_21 ) ;
V_8 -> V_12 += V_21 ;
V_22 = F_7 ( 30 ) ;
if ( V_8 -> V_12 > V_22 )
V_8 -> V_12 = V_22 ;
if ( V_8 -> V_12 < - V_22 )
V_8 -> V_12 = - V_22 ;
V_20 = F_1 ( V_8 -> V_17 , V_21 - V_8 -> V_13 ) ;
V_8 -> V_13 = V_21 ;
V_18 = V_19 + F_1 ( V_8 -> V_12 , V_8 -> V_16 ) + V_20 ;
V_18 = V_18 + ( 1 << ( V_4 - 1 ) ) ;
return ( signed int ) F_5 ( V_18 ) ;
}
static inline void F_12 ( struct V_23 * V_24 )
{
F_8 ( & V_24 -> V_8 , V_25 . V_26 ) ;
F_10 ( & V_24 -> V_8 , V_25 . V_27 ) ;
F_9 ( & V_24 -> V_8 , V_25 . V_28 ) ;
F_6 ( & V_24 -> V_8 , V_25 . V_9 , 100 , V_25 . V_11 , 0 ) ;
}
static inline void F_13 ( void )
{
unsigned int V_24 ;
F_14 (cpu) {
if ( V_29 [ V_24 ] )
F_12 ( V_29 [ V_24 ] ) ;
}
}
static inline void F_15 ( void )
{
T_2 V_30 ;
struct V_23 * V_24 ;
V_24 = V_29 [ 0 ] ;
F_16 ( V_31 , V_30 ) ;
V_32 . V_33 =
( V_30 & V_34 ||
V_24 -> V_35 . V_36 == V_24 -> V_35 . V_37 ) ;
}
static int F_17 ( void * V_38 , T_2 V_39 )
{
* ( V_40 * ) V_38 = V_39 ;
F_13 () ;
return 0 ;
}
static int F_18 ( void * V_38 , T_2 * V_39 )
{
* V_39 = * ( V_40 * ) V_38 ;
return 0 ;
}
static void T_3 F_19 ( void )
{
struct V_41 * V_42 ;
int V_43 = 0 ;
V_42 = F_20 ( L_1 , NULL ) ;
if ( F_21 ( V_42 ) )
return;
while ( V_44 [ V_43 ] . V_45 ) {
F_22 ( V_44 [ V_43 ] . V_45 , 0660 ,
V_42 , V_44 [ V_43 ] . V_46 ,
& V_47 ) ;
V_43 ++ ;
}
}
static T_4 F_23 ( struct V_48 * V_49 ,
struct V_50 * V_51 , char * V_52 )
{
T_4 V_6 ;
F_15 () ;
if ( V_32 . V_33 )
V_6 = sprintf ( V_52 , L_2 , V_32 . V_33 ) ;
else
V_6 = sprintf ( V_52 , L_2 , V_32 . V_53 ) ;
return V_6 ;
}
static T_4 F_24 ( struct V_48 * V_54 , struct V_50 * V_55 ,
const char * V_52 , T_5 V_56 )
{
unsigned int V_57 ;
int V_6 ;
V_6 = sscanf ( V_52 , L_3 , & V_57 ) ;
if ( V_6 != 1 )
return - V_58 ;
F_15 () ;
if ( V_32 . V_33 ) {
F_25 ( L_4 ) ;
return - V_59 ;
}
V_32 . V_53 = F_26 ( int , V_57 , 0 , 1 ) ;
return V_56 ;
}
static T_4 F_27 ( struct V_48 * V_54 , struct V_50 * V_55 ,
const char * V_52 , T_5 V_56 )
{
unsigned int V_57 ;
int V_6 ;
V_6 = sscanf ( V_52 , L_3 , & V_57 ) ;
if ( V_6 != 1 )
return - V_58 ;
V_32 . V_60 = F_26 ( int , V_57 , 0 , 100 ) ;
V_32 . V_61 = F_28 ( V_32 . V_62 , V_32 . V_60 ) ;
V_32 . V_63 = F_2 ( F_7 ( V_32 . V_61 ) , F_7 ( 100 ) ) ;
return V_56 ;
}
static T_4 F_29 ( struct V_48 * V_54 , struct V_50 * V_55 ,
const char * V_52 , T_5 V_56 )
{
unsigned int V_57 ;
int V_6 ;
V_6 = sscanf ( V_52 , L_3 , & V_57 ) ;
if ( V_6 != 1 )
return - V_58 ;
V_32 . V_64 = F_26 ( int , V_57 , 0 , 100 ) ;
V_32 . V_65 = F_2 ( F_7 ( V_32 . V_64 ) , F_7 ( 100 ) ) ;
return V_56 ;
}
static void T_3 F_30 ( void )
{
struct V_48 * V_66 ;
int V_67 ;
V_66 = F_31 ( L_5 ,
& V_68 . V_69 -> V_49 ) ;
F_32 ( ! V_66 ) ;
V_67 = F_33 ( V_66 , & V_70 ) ;
F_32 ( V_67 ) ;
}
static int F_34 ( void )
{
T_2 V_46 ;
F_16 ( V_71 , V_46 ) ;
return ( V_46 >> 8 ) & 0x7F ;
}
static int F_35 ( void )
{
T_2 V_46 ;
F_16 ( V_71 , V_46 ) ;
return ( V_46 >> 16 ) & 0x7F ;
}
static int F_36 ( void )
{
T_2 V_46 ;
F_16 ( V_72 , V_46 ) ;
return V_46 & 0x7F ;
}
static void F_37 ( struct V_23 * V_23 , int V_35 )
{
T_2 V_39 ;
T_1 V_73 ;
V_40 V_74 ;
V_39 = V_35 << 8 ;
if ( V_32 . V_53 && ! V_32 . V_33 )
V_39 |= ( T_2 ) 1 << 32 ;
V_73 = V_23 -> V_74 . F_28 + F_1 (
F_7 ( V_35 - V_23 -> V_35 . V_75 ) ,
V_23 -> V_74 . V_76 ) ;
V_73 = F_26 ( T_1 , V_73 , V_23 -> V_74 . F_28 , V_23 -> V_74 . V_77 ) ;
V_74 = F_4 ( V_73 ) ;
if ( V_35 > V_23 -> V_35 . V_36 )
V_74 = V_23 -> V_74 . V_78 ;
V_39 |= V_74 ;
F_38 ( V_79 , V_39 ) ;
}
static int F_39 ( void )
{
T_2 V_46 ;
int V_43 ;
F_16 ( V_80 , V_46 ) ;
V_43 = V_46 & 0x3 ;
F_32 ( V_43 > V_81 ) ;
return V_82 [ V_43 ] * 100 ;
}
static void F_40 ( struct V_23 * V_23 )
{
T_2 V_46 ;
F_16 ( V_83 , V_46 ) ;
V_23 -> V_74 . F_28 = F_7 ( ( V_46 >> 8 ) & 0x7f ) ;
V_23 -> V_74 . V_77 = F_7 ( ( V_46 >> 16 ) & 0x7f ) ;
V_23 -> V_74 . V_76 = F_2 (
V_23 -> V_74 . V_77 - V_23 -> V_74 . F_28 ,
F_7 ( V_23 -> V_35 . V_36 -
V_23 -> V_35 . V_75 ) ) ;
F_16 ( V_84 , V_46 ) ;
V_23 -> V_74 . V_78 = V_46 & 0x7f ;
}
static int F_41 ( void )
{
T_2 V_46 ;
F_16 ( V_85 , V_46 ) ;
return ( V_46 >> 40 ) & 0xFF ;
}
static int F_42 ( void )
{
T_2 V_46 ;
F_16 ( V_85 , V_46 ) ;
return ( V_46 >> 8 ) & 0xFF ;
}
static int F_43 ( void )
{
T_2 V_46 ;
int V_86 , V_6 ;
F_16 ( V_87 , V_46 ) ;
V_86 = F_42 () ;
V_6 = ( V_46 ) & 255 ;
if ( V_6 <= V_86 )
V_6 = V_86 ;
return V_6 ;
}
static inline int F_44 ( void )
{
return 100000 ;
}
static void F_45 ( struct V_23 * V_23 , int V_35 )
{
T_2 V_39 ;
V_39 = V_35 << 8 ;
if ( V_32 . V_53 && ! V_32 . V_33 )
V_39 |= ( T_2 ) 1 << 32 ;
F_46 ( V_23 -> V_24 , V_79 , V_39 ) ;
}
static void F_47 ( struct V_23 * V_24 , int * F_28 , int * V_77 )
{
int V_63 = V_24 -> V_35 . V_37 ;
int V_88 ;
int V_65 ;
if ( V_32 . V_53 || V_32 . V_33 )
V_63 = V_24 -> V_35 . V_36 ;
V_88 = F_5 ( F_1 ( F_7 ( V_63 ) , V_32 . V_63 ) ) ;
* V_77 = F_26 ( int , V_88 ,
V_24 -> V_35 . V_75 , V_24 -> V_35 . V_37 ) ;
V_65 = F_5 ( F_1 ( F_7 ( V_63 ) , V_32 . V_65 ) ) ;
* F_28 = F_26 ( int , V_65 , V_24 -> V_35 . V_75 , V_63 ) ;
}
static void F_48 ( struct V_23 * V_24 , int V_35 )
{
int V_63 , V_65 ;
F_15 () ;
F_47 ( V_24 , & V_65 , & V_63 ) ;
V_35 = F_26 ( int , V_35 , V_65 , V_63 ) ;
if ( V_35 == V_24 -> V_35 . V_89 )
return;
F_49 ( V_35 * V_24 -> V_35 . V_90 , V_24 -> V_24 ) ;
V_24 -> V_35 . V_89 = V_35 ;
V_91 . V_92 ( V_24 , V_35 ) ;
}
static void F_50 ( struct V_23 * V_24 )
{
V_24 -> V_35 . V_75 = V_91 . V_93 () ;
V_24 -> V_35 . V_36 = V_91 . V_94 () ;
V_24 -> V_35 . V_37 = V_91 . V_95 () ;
V_24 -> V_35 . V_90 = V_91 . V_96 () ;
if ( V_91 . V_97 )
V_91 . V_97 ( V_24 ) ;
F_48 ( V_24 , V_24 -> V_35 . V_75 ) ;
}
static inline void F_51 ( struct V_23 * V_24 )
{
struct V_98 * V_98 = & V_24 -> V_98 ;
V_3 V_99 ;
V_99 = F_7 ( V_98 -> V_100 ) * F_7 ( 100 ) ;
V_99 = F_52 ( V_99 , F_7 ( V_98 -> V_101 ) ) ;
V_98 -> V_102 = F_5 (
F_1 ( F_7 (
V_24 -> V_35 . V_36 * V_24 -> V_35 . V_90 / 100 ) ,
V_99 ) ) ;
V_98 -> V_103 = ( T_1 ) V_99 ;
}
static inline void F_53 ( struct V_23 * V_24 )
{
T_2 V_100 , V_101 ;
unsigned long V_104 ;
F_54 ( V_104 ) ;
F_16 ( V_105 , V_100 ) ;
F_16 ( V_106 , V_101 ) ;
F_55 ( V_104 ) ;
V_24 -> V_107 = V_24 -> V_98 . time ;
V_24 -> V_98 . time = F_56 () ;
V_24 -> V_98 . V_100 = V_100 ;
V_24 -> V_98 . V_101 = V_101 ;
V_24 -> V_98 . V_100 -= V_24 -> V_108 ;
V_24 -> V_98 . V_101 -= V_24 -> V_109 ;
F_51 ( V_24 ) ;
V_24 -> V_108 = V_100 ;
V_24 -> V_109 = V_101 ;
}
static inline void F_57 ( struct V_23 * V_24 )
{
int V_110 ;
V_110 = F_58 ( V_25 . V_111 ) ;
F_59 ( & V_24 -> V_112 , V_113 + V_110 ) ;
}
static inline T_1 F_60 ( struct V_23 * V_24 )
{
T_1 V_114 , V_36 , V_89 , V_115 ;
V_40 V_116 ;
V_40 V_117 ;
V_114 = V_24 -> V_98 . V_103 ;
V_36 = F_7 ( V_24 -> V_35 . V_36 ) ;
V_89 = F_7 ( V_24 -> V_35 . V_89 ) ;
V_114 = F_1 ( V_114 , F_2 ( V_36 , V_89 ) ) ;
V_117 = V_25 . V_111 * V_118 ;
V_116 = ( V_40 ) F_61 ( V_24 -> V_98 . time ,
V_24 -> V_107 ) ;
if ( V_116 > V_117 * 3 ) {
V_115 = F_2 ( F_7 ( V_117 ) ,
F_7 ( V_116 ) ) ;
V_114 = F_1 ( V_114 , V_115 ) ;
}
return V_114 ;
}
static inline void F_62 ( struct V_23 * V_24 )
{
T_1 V_119 ;
struct V_7 * V_8 ;
signed int V_120 ;
V_8 = & V_24 -> V_8 ;
V_119 = F_60 ( V_24 ) ;
V_120 = F_11 ( V_8 , V_119 ) ;
F_48 ( V_24 , V_24 -> V_35 . V_89 - V_120 ) ;
}
static void F_63 ( unsigned long V_121 )
{
struct V_23 * V_24 = (struct V_23 * ) V_121 ;
struct V_98 * V_98 ;
F_53 ( V_24 ) ;
V_98 = & V_24 -> V_98 ;
F_62 ( V_24 ) ;
F_64 ( F_5 ( V_98 -> V_103 ) ,
F_5 ( F_60 ( V_24 ) ) ,
V_24 -> V_35 . V_89 ,
V_98 -> V_101 ,
V_98 -> V_100 ,
V_98 -> V_102 ) ;
F_57 ( V_24 ) ;
}
static int F_65 ( unsigned int V_122 )
{
struct V_23 * V_24 ;
if ( ! V_29 [ V_122 ] )
V_29 [ V_122 ] = F_66 ( sizeof( struct V_23 ) ,
V_123 ) ;
if ( ! V_29 [ V_122 ] )
return - V_124 ;
V_24 = V_29 [ V_122 ] ;
V_24 -> V_24 = V_122 ;
F_50 ( V_24 ) ;
F_67 ( & V_24 -> V_112 ) ;
V_24 -> V_112 . V_125 = F_63 ;
V_24 -> V_112 . V_38 = ( unsigned long ) V_24 ;
V_24 -> V_112 . V_126 = V_113 + V_127 / 100 ;
F_12 ( V_24 ) ;
F_53 ( V_24 ) ;
F_68 ( & V_24 -> V_112 , V_122 ) ;
F_69 ( L_6 , V_122 ) ;
return 0 ;
}
static unsigned int F_70 ( unsigned int V_128 )
{
struct V_98 * V_98 ;
struct V_23 * V_24 ;
V_24 = V_29 [ V_128 ] ;
if ( ! V_24 )
return 0 ;
V_98 = & V_24 -> V_98 ;
return V_98 -> V_102 ;
}
static int F_71 ( struct V_129 * V_130 )
{
if ( ! V_130 -> V_131 . V_132 )
return - V_133 ;
if ( V_130 -> V_130 == V_134 ) {
V_32 . V_64 = 100 ;
V_32 . V_65 = F_7 ( 1 ) ;
V_32 . V_62 = 100 ;
V_32 . V_61 = 100 ;
V_32 . V_63 = F_7 ( 1 ) ;
V_32 . V_53 = 0 ;
return 0 ;
}
V_32 . V_64 = ( V_130 -> F_28 * 100 ) / V_130 -> V_131 . V_132 ;
V_32 . V_64 = F_26 ( int , V_32 . V_64 , 0 , 100 ) ;
V_32 . V_65 = F_2 ( F_7 ( V_32 . V_64 ) , F_7 ( 100 ) ) ;
V_32 . V_62 = ( V_130 -> V_77 * 100 ) / V_130 -> V_131 . V_132 ;
V_32 . V_62 = F_26 ( int , V_32 . V_62 , 0 , 100 ) ;
V_32 . V_61 = F_28 ( V_32 . V_62 , V_32 . V_60 ) ;
V_32 . V_63 = F_2 ( F_7 ( V_32 . V_61 ) , F_7 ( 100 ) ) ;
return 0 ;
}
static int F_72 ( struct V_129 * V_130 )
{
F_73 ( V_130 ) ;
if ( V_130 -> V_130 != V_135 &&
V_130 -> V_130 != V_134 )
return - V_58 ;
return 0 ;
}
static void F_74 ( struct V_129 * V_130 )
{
int V_128 = V_130 -> V_24 ;
struct V_23 * V_24 = V_29 [ V_128 ] ;
F_75 ( L_7 , V_128 ) ;
F_76 ( & V_29 [ V_128 ] -> V_112 ) ;
F_48 ( V_24 , V_24 -> V_35 . V_75 ) ;
}
static int F_77 ( struct V_129 * V_130 )
{
struct V_23 * V_24 ;
int V_67 ;
V_67 = F_65 ( V_130 -> V_24 ) ;
if ( V_67 )
return V_67 ;
V_24 = V_29 [ V_130 -> V_24 ] ;
if ( V_32 . V_64 == 100 && V_32 . V_61 == 100 )
V_130 -> V_130 = V_134 ;
else
V_130 -> V_130 = V_135 ;
V_130 -> F_28 = V_24 -> V_35 . V_75 * V_24 -> V_35 . V_90 ;
V_130 -> V_77 = V_24 -> V_35 . V_37 * V_24 -> V_35 . V_90 ;
V_130 -> V_131 . V_136 = V_24 -> V_35 . V_75 * V_24 -> V_35 . V_90 ;
V_130 -> V_131 . V_132 =
V_24 -> V_35 . V_37 * V_24 -> V_35 . V_90 ;
V_130 -> V_131 . V_137 = V_138 ;
F_78 ( V_130 -> V_24 , V_130 -> V_139 ) ;
return 0 ;
}
static int F_79 ( void )
{
T_2 V_100 , V_101 , V_140 ;
F_16 ( V_105 , V_100 ) ;
F_16 ( V_106 , V_101 ) ;
if ( ! V_91 . V_94 () ||
! V_91 . V_93 () ||
! V_91 . V_95 () )
return - V_133 ;
F_16 ( V_105 , V_140 ) ;
if ( ! ( V_140 - V_100 ) )
return - V_133 ;
F_16 ( V_106 , V_140 ) ;
if ( ! ( V_140 - V_101 ) )
return - V_133 ;
return 0 ;
}
static void F_80 ( struct V_141 * V_130 )
{
V_25 . V_111 = V_130 -> V_111 ;
V_25 . V_26 = V_130 -> V_26 ;
V_25 . V_28 = V_130 -> V_28 ;
V_25 . V_27 = V_130 -> V_27 ;
V_25 . V_11 = V_130 -> V_11 ;
V_25 . V_9 = V_130 -> V_9 ;
}
static void F_81 ( struct V_91 * V_142 )
{
V_91 . V_94 = V_142 -> V_94 ;
V_91 . V_93 = V_142 -> V_93 ;
V_91 . V_95 = V_142 -> V_95 ;
V_91 . V_96 = V_142 -> V_96 ;
V_91 . V_92 = V_142 -> V_92 ;
V_91 . V_97 = V_142 -> V_97 ;
}
static bool F_82 ( void )
{
int V_43 ;
F_83 (i) {
T_6 V_143 ;
union V_144 * V_145 ;
struct V_146 V_147 = { V_148 , NULL } ;
struct V_149 * V_150 = F_84 ( V_151 , V_43 ) ;
if ( ! V_150 )
continue;
V_143 = F_85 ( V_150 -> V_152 , L_8 , NULL , & V_147 ) ;
if ( F_86 ( V_143 ) )
continue;
V_145 = V_147 . V_153 ;
if ( V_145 && V_145 -> type == V_154 ) {
F_87 ( V_145 ) ;
return false ;
}
F_87 ( V_145 ) ;
}
return true ;
}
static bool F_88 ( void )
{
struct V_155 V_156 ;
struct V_157 * V_158 ;
if ( V_159 ||
F_86 ( F_89 ( V_160 , 0 , & V_156 ) ) )
return false ;
for ( V_158 = V_161 ; V_158 -> V_162 ; V_158 ++ ) {
if ( ! strncmp ( V_156 . V_163 , V_158 -> V_163 , V_164 ) &&
! strncmp ( V_156 . V_165 , V_158 -> V_165 , V_166 ) &&
F_82 () )
return true ;
}
return false ;
}
static inline bool F_88 ( void ) { return false ; }
static int T_3 F_90 ( void )
{
int V_24 , V_67 = 0 ;
const struct V_167 * V_168 ;
struct V_169 * V_170 ;
if ( V_171 )
return - V_133 ;
V_168 = F_91 ( V_172 ) ;
if ( ! V_168 )
return - V_133 ;
if ( F_88 () )
return - V_133 ;
V_170 = (struct V_169 * ) V_168 -> V_173 ;
F_80 ( & V_170 -> V_174 ) ;
F_81 ( & V_170 -> V_142 ) ;
if ( F_79 () )
return - V_133 ;
F_75 ( L_9 ) ;
V_29 = F_92 ( sizeof( void * ) * F_93 () ) ;
if ( ! V_29 )
return - V_124 ;
V_67 = F_94 ( & V_175 ) ;
if ( V_67 )
goto V_176;
F_19 () ;
F_30 () ;
return V_67 ;
V_176:
F_95 () ;
F_14 (cpu) {
if ( V_29 [ V_24 ] ) {
F_76 ( & V_29 [ V_24 ] -> V_112 ) ;
F_87 ( V_29 [ V_24 ] ) ;
}
}
F_96 () ;
F_97 ( V_29 ) ;
return - V_133 ;
}
static int T_3 F_98 ( char * V_177 )
{
if ( ! V_177 )
return - V_58 ;
if ( ! strcmp ( V_177 , L_10 ) )
V_171 = 1 ;
return 0 ;
}
