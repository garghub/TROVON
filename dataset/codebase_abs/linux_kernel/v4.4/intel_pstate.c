static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_3 ) V_1 * ( V_3 ) V_2 ) >> V_4 ;
}
static inline T_1 F_2 ( T_2 V_1 , T_2 V_2 )
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
T_3 V_30 ;
struct V_23 * V_24 ;
V_24 = V_29 [ 0 ] ;
F_16 ( V_31 , V_30 ) ;
V_32 -> V_33 =
( V_30 & V_34 ||
V_24 -> V_35 . V_36 == V_24 -> V_35 . V_37 ) ;
}
static void F_17 ( void )
{
int V_38 , V_39 , V_40 , V_41 , V_24 , V_42 , V_43 ;
T_3 V_44 , V_45 ;
F_16 ( V_46 , V_45 ) ;
V_39 = F_18 ( V_45 ) ;
V_41 = F_19 ( V_45 ) ;
V_42 = V_41 - V_39 ;
F_20 () ;
F_14 (cpu) {
F_21 ( V_24 , V_47 , & V_44 ) ;
V_43 = V_32 -> V_48 * V_42 / 100 ;
V_38 = V_39 + V_43 ;
V_44 &= ~ F_22 ( ~ 0L ) ;
V_44 |= F_22 ( V_38 ) ;
V_43 = V_32 -> V_49 * V_42 / 100 ;
V_40 = V_39 + V_43 ;
if ( V_32 -> V_50 ) {
V_41 = F_23 ( V_45 ) ;
if ( V_41 < V_40 )
V_40 = V_41 ;
}
V_44 &= ~ F_24 ( ~ 0L ) ;
V_44 |= F_24 ( V_40 ) ;
F_25 ( V_24 , V_47 , V_44 ) ;
}
F_26 () ;
}
static int F_27 ( void * V_51 , T_3 V_52 )
{
* ( V_53 * ) V_51 = V_52 ;
F_13 () ;
return 0 ;
}
static int F_28 ( void * V_51 , T_3 * V_52 )
{
* V_52 = * ( V_53 * ) V_51 ;
return 0 ;
}
static void T_4 F_29 ( void )
{
struct V_54 * V_55 ;
int V_56 = 0 ;
if ( V_57 )
return;
V_55 = F_30 ( L_1 , NULL ) ;
if ( F_31 ( V_55 ) )
return;
while ( V_58 [ V_56 ] . V_59 ) {
F_32 ( V_58 [ V_56 ] . V_59 , 0660 ,
V_55 , V_58 [ V_56 ] . V_44 ,
& V_60 ) ;
V_56 ++ ;
}
}
static T_5 F_33 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_23 * V_24 ;
int V_66 , V_50 , V_67 ;
T_6 V_68 ;
V_24 = V_29 [ 0 ] ;
V_66 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_69 + 1 ;
V_50 = V_24 -> V_35 . V_36 - V_24 -> V_35 . V_69 + 1 ;
V_68 = F_2 ( F_7 ( V_50 ) , F_7 ( V_66 ) ) ;
V_67 = 100 - F_5 ( F_1 ( V_68 , F_7 ( 100 ) ) ) ;
return sprintf ( V_65 , L_2 , V_67 ) ;
}
static T_5 F_34 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
struct V_23 * V_24 ;
int V_66 ;
V_24 = V_29 [ 0 ] ;
V_66 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_69 + 1 ;
return sprintf ( V_65 , L_2 , V_66 ) ;
}
static T_5 F_35 ( struct V_61 * V_62 ,
struct V_63 * V_64 , char * V_65 )
{
T_5 V_6 ;
F_15 () ;
if ( V_32 -> V_33 )
V_6 = sprintf ( V_65 , L_2 , V_32 -> V_33 ) ;
else
V_6 = sprintf ( V_65 , L_2 , V_32 -> V_50 ) ;
return V_6 ;
}
static T_5 F_36 ( struct V_61 * V_70 , struct V_63 * V_71 ,
const char * V_65 , T_7 V_72 )
{
unsigned int V_73 ;
int V_6 ;
V_6 = sscanf ( V_65 , L_3 , & V_73 ) ;
if ( V_6 != 1 )
return - V_74 ;
F_15 () ;
if ( V_32 -> V_33 ) {
F_37 ( L_4 ) ;
return - V_75 ;
}
V_32 -> V_50 = F_38 ( int , V_73 , 0 , 1 ) ;
if ( V_57 )
F_17 () ;
return V_72 ;
}
static T_5 F_39 ( struct V_61 * V_70 , struct V_63 * V_71 ,
const char * V_65 , T_7 V_72 )
{
unsigned int V_73 ;
int V_6 ;
V_6 = sscanf ( V_65 , L_3 , & V_73 ) ;
if ( V_6 != 1 )
return - V_74 ;
V_32 -> V_76 = F_38 ( int , V_73 , 0 , 100 ) ;
V_32 -> V_49 = V_38 ( V_32 -> V_77 ,
V_32 -> V_76 ) ;
V_32 -> V_49 = V_40 ( V_32 -> V_78 ,
V_32 -> V_49 ) ;
V_32 -> V_49 = V_40 ( V_32 -> V_48 ,
V_32 -> V_49 ) ;
V_32 -> V_79 = F_2 ( F_7 ( V_32 -> V_49 ) ,
F_7 ( 100 ) ) ;
if ( V_57 )
F_17 () ;
return V_72 ;
}
static T_5 F_40 ( struct V_61 * V_70 , struct V_63 * V_71 ,
const char * V_65 , T_7 V_72 )
{
unsigned int V_73 ;
int V_6 ;
V_6 = sscanf ( V_65 , L_3 , & V_73 ) ;
if ( V_6 != 1 )
return - V_74 ;
V_32 -> V_80 = F_38 ( int , V_73 , 0 , 100 ) ;
V_32 -> V_48 = V_40 ( V_32 -> V_78 ,
V_32 -> V_80 ) ;
V_32 -> V_48 = V_38 ( V_32 -> V_77 ,
V_32 -> V_48 ) ;
V_32 -> V_48 = V_38 ( V_32 -> V_49 ,
V_32 -> V_48 ) ;
V_32 -> V_81 = F_2 ( F_7 ( V_32 -> V_48 ) ,
F_7 ( 100 ) ) ;
if ( V_57 )
F_17 () ;
return V_72 ;
}
static void T_4 F_41 ( void )
{
struct V_61 * V_82 ;
int V_83 ;
V_82 = F_42 ( L_5 ,
& V_84 . V_85 -> V_62 ) ;
F_43 ( ! V_82 ) ;
V_83 = F_44 ( V_82 , & V_86 ) ;
F_43 ( V_83 ) ;
}
static void F_45 ( struct V_23 * V_23 )
{
F_25 ( V_23 -> V_24 , V_87 , 0x1 ) ;
}
static int F_46 ( void )
{
T_3 V_44 ;
F_16 ( V_88 , V_44 ) ;
return ( V_44 >> 8 ) & 0x7F ;
}
static int F_47 ( void )
{
T_3 V_44 ;
F_16 ( V_88 , V_44 ) ;
return ( V_44 >> 16 ) & 0x7F ;
}
static int F_48 ( void )
{
T_3 V_44 ;
F_16 ( V_89 , V_44 ) ;
return V_44 & 0x7F ;
}
static void F_49 ( struct V_23 * V_23 , int V_35 )
{
T_3 V_52 ;
T_1 V_90 ;
V_53 V_91 ;
V_52 = ( T_3 ) V_35 << 8 ;
if ( V_32 -> V_50 && ! V_32 -> V_33 )
V_52 |= ( T_3 ) 1 << 32 ;
V_90 = V_23 -> V_91 . V_38 + F_1 (
F_7 ( V_35 - V_23 -> V_35 . V_69 ) ,
V_23 -> V_91 . V_92 ) ;
V_90 = F_38 ( T_1 , V_90 , V_23 -> V_91 . V_38 , V_23 -> V_91 . V_40 ) ;
V_91 = F_4 ( V_90 ) ;
if ( V_35 > V_23 -> V_35 . V_36 )
V_91 = V_23 -> V_91 . V_93 ;
V_52 |= V_91 ;
F_25 ( V_23 -> V_24 , V_94 , V_52 ) ;
}
static int F_50 ( void )
{
T_3 V_44 ;
int V_56 ;
static int V_95 [] = {
83300 , 100000 , 133300 , 116700 , 80000 } ;
F_16 ( V_96 , V_44 ) ;
V_56 = V_44 & 0x7 ;
F_51 ( V_56 > 4 ) ;
return V_95 [ V_56 ] ;
}
static int F_52 ( void )
{
T_3 V_44 ;
int V_56 ;
static int V_97 [] = {
83300 , 100000 , 133300 , 116700 , 80000 ,
93300 , 90000 , 88900 , 87500 } ;
F_16 ( V_96 , V_44 ) ;
V_56 = V_44 & 0xF ;
F_51 ( V_56 > 8 ) ;
return V_97 [ V_56 ] ;
}
static void F_53 ( struct V_23 * V_23 )
{
T_3 V_44 ;
F_16 ( V_98 , V_44 ) ;
V_23 -> V_91 . V_38 = F_7 ( ( V_44 >> 8 ) & 0x7f ) ;
V_23 -> V_91 . V_40 = F_7 ( ( V_44 >> 16 ) & 0x7f ) ;
V_23 -> V_91 . V_92 = F_2 (
V_23 -> V_91 . V_40 - V_23 -> V_91 . V_38 ,
F_7 ( V_23 -> V_35 . V_36 -
V_23 -> V_35 . V_69 ) ) ;
F_16 ( V_99 , V_44 ) ;
V_23 -> V_91 . V_93 = V_44 & 0x7f ;
}
static int F_54 ( void )
{
T_3 V_44 ;
F_16 ( V_100 , V_44 ) ;
return ( V_44 >> 40 ) & 0xFF ;
}
static int F_55 ( void )
{
T_3 V_44 ;
F_16 ( V_100 , V_44 ) ;
return ( V_44 >> 8 ) & 0xFF ;
}
static int F_56 ( void )
{
T_3 V_101 ;
T_3 V_102 ;
int V_36 ;
int V_103 ;
F_16 ( V_100 , V_102 ) ;
V_36 = ( V_102 >> 8 ) & 0xFF ;
V_103 = F_57 ( V_104 , & V_101 ) ;
if ( ! V_103 ) {
if ( V_102 & 0x600000000 ) {
T_3 V_105 ;
T_3 V_106 ;
int V_107 ;
V_103 = F_57 ( V_108 , & V_105 ) ;
if ( V_103 )
goto V_109;
V_107 = V_110 + V_105 ;
V_103 = F_57 ( V_107 , & V_106 ) ;
if ( V_103 )
goto V_109;
if ( V_106 - 1 == V_101 ) {
V_36 = V_101 ;
F_58 ( L_6 , V_36 ) ;
} else {
goto V_109;
}
}
}
V_109:
return V_36 ;
}
static int F_59 ( void )
{
T_3 V_44 ;
int V_111 , V_6 ;
F_16 ( V_112 , V_44 ) ;
V_111 = F_56 () ;
V_6 = ( V_44 ) & 255 ;
if ( V_6 <= V_111 )
V_6 = V_111 ;
return V_6 ;
}
static inline int F_60 ( void )
{
return 100000 ;
}
static void F_61 ( struct V_23 * V_23 , int V_35 )
{
T_3 V_52 ;
V_52 = ( T_3 ) V_35 << 8 ;
if ( V_32 -> V_50 && ! V_32 -> V_33 )
V_52 |= ( T_3 ) 1 << 32 ;
F_25 ( V_23 -> V_24 , V_94 , V_52 ) ;
}
static int F_62 ( void )
{
T_3 V_44 ;
int V_111 , V_6 ;
F_16 ( V_112 , V_44 ) ;
V_111 = F_56 () ;
V_6 = ( ( ( V_44 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_111 )
V_6 = V_111 ;
return V_6 ;
}
static void F_63 ( struct V_23 * V_24 , int * V_38 , int * V_40 )
{
int V_79 = V_24 -> V_35 . V_37 ;
int V_113 ;
int V_81 ;
if ( V_32 -> V_50 || V_32 -> V_33 )
V_79 = V_24 -> V_35 . V_36 ;
V_113 = F_5 ( F_1 ( F_7 ( V_79 ) , V_32 -> V_79 ) ) ;
* V_40 = F_38 ( int , V_113 ,
V_24 -> V_35 . V_69 , V_24 -> V_35 . V_37 ) ;
V_81 = F_5 ( F_1 ( F_7 ( V_79 ) , V_32 -> V_81 ) ) ;
* V_38 = F_38 ( int , V_81 , V_24 -> V_35 . V_69 , V_79 ) ;
}
static void F_64 ( struct V_23 * V_24 , int V_35 , bool V_114 )
{
int V_79 , V_81 ;
if ( V_114 ) {
F_15 () ;
F_63 ( V_24 , & V_81 , & V_79 ) ;
V_35 = F_38 ( int , V_35 , V_81 , V_79 ) ;
if ( V_35 == V_24 -> V_35 . V_115 )
return;
}
F_65 ( V_35 * V_24 -> V_35 . V_116 , V_24 -> V_24 ) ;
V_24 -> V_35 . V_115 = V_35 ;
V_117 . V_118 ( V_24 , V_35 ) ;
}
static void F_66 ( struct V_23 * V_24 )
{
V_24 -> V_35 . V_69 = V_117 . V_119 () ;
V_24 -> V_35 . V_36 = V_117 . V_120 () ;
V_24 -> V_35 . V_121 = V_117 . V_122 () ;
V_24 -> V_35 . V_37 = V_117 . V_123 () ;
V_24 -> V_35 . V_116 = V_117 . V_124 () ;
if ( V_117 . V_125 )
V_117 . V_125 ( V_24 ) ;
F_64 ( V_24 , V_24 -> V_35 . V_69 , false ) ;
}
static inline void F_67 ( struct V_23 * V_24 )
{
struct V_126 * V_126 = & V_24 -> V_126 ;
V_3 V_127 ;
V_127 = F_7 ( V_126 -> V_128 ) * F_7 ( 100 ) ;
V_127 = F_68 ( V_127 , F_7 ( V_126 -> V_129 ) ) ;
V_126 -> V_130 = F_5 (
F_1 ( F_7 (
V_24 -> V_35 . V_121 *
V_24 -> V_35 . V_116 / 100 ) ,
V_127 ) ) ;
V_126 -> V_131 = ( T_1 ) V_127 ;
}
static inline void F_69 ( struct V_23 * V_24 )
{
T_3 V_128 , V_129 ;
unsigned long V_132 ;
T_3 V_133 ;
F_70 ( V_132 ) ;
F_16 ( V_134 , V_128 ) ;
F_16 ( V_135 , V_129 ) ;
if ( V_24 -> V_136 == V_129 ) {
F_71 ( V_132 ) ;
return;
}
V_133 = F_72 () ;
F_71 ( V_132 ) ;
V_24 -> V_137 = V_24 -> V_126 . time ;
V_24 -> V_126 . time = F_73 () ;
V_24 -> V_126 . V_128 = V_128 ;
V_24 -> V_126 . V_129 = V_129 ;
V_24 -> V_126 . V_133 = V_133 ;
V_24 -> V_126 . V_128 -= V_24 -> V_138 ;
V_24 -> V_126 . V_129 -= V_24 -> V_136 ;
V_24 -> V_126 . V_133 -= V_24 -> V_139 ;
F_67 ( V_24 ) ;
V_24 -> V_138 = V_128 ;
V_24 -> V_136 = V_129 ;
V_24 -> V_139 = V_133 ;
}
static inline void F_74 ( struct V_23 * V_24 )
{
int V_140 ;
V_140 = F_75 ( 50 ) ;
F_76 ( & V_24 -> V_141 , V_142 + V_140 ) ;
}
static inline void F_77 ( struct V_23 * V_24 )
{
int V_140 ;
V_140 = F_75 ( V_25 . V_143 ) ;
F_76 ( & V_24 -> V_141 , V_142 + V_140 ) ;
}
static inline T_1 F_78 ( struct V_23 * V_24 )
{
T_1 V_144 , V_36 , V_115 , V_145 ;
T_2 V_146 ;
V_53 V_147 ;
V_144 = V_24 -> V_126 . V_131 ;
V_36 = F_7 ( V_24 -> V_35 . V_121 ) ;
V_115 = F_7 ( V_24 -> V_35 . V_115 ) ;
V_144 = F_1 ( V_144 , F_2 ( V_36 , V_115 ) ) ;
V_147 = V_25 . V_143 * V_148 ;
V_146 = F_79 ( V_24 -> V_126 . time ,
V_24 -> V_137 ) ;
if ( V_146 > V_147 * 3 ) {
V_145 = F_2 ( F_7 ( V_147 ) ,
F_7 ( V_146 ) ) ;
V_144 = F_1 ( V_144 , V_145 ) ;
}
return V_144 ;
}
static inline void F_80 ( struct V_23 * V_24 )
{
T_1 V_149 ;
struct V_7 * V_8 ;
signed int V_150 ;
int V_151 ;
struct V_126 * V_126 ;
V_151 = V_24 -> V_35 . V_115 ;
V_8 = & V_24 -> V_8 ;
V_149 = F_78 ( V_24 ) ;
V_150 = F_11 ( V_8 , V_149 ) ;
F_64 ( V_24 , V_24 -> V_35 . V_115 - V_150 , true ) ;
V_126 = & V_24 -> V_126 ;
F_81 ( F_5 ( V_126 -> V_131 ) ,
F_5 ( V_149 ) ,
V_151 ,
V_24 -> V_35 . V_115 ,
V_126 -> V_129 ,
V_126 -> V_128 ,
V_126 -> V_133 ,
V_126 -> V_130 ) ;
}
static void F_82 ( unsigned long V_152 )
{
struct V_23 * V_24 = (struct V_23 * ) V_152 ;
F_69 ( V_24 ) ;
F_74 ( V_24 ) ;
}
static void F_83 ( unsigned long V_152 )
{
struct V_23 * V_24 = (struct V_23 * ) V_152 ;
F_69 ( V_24 ) ;
F_80 ( V_24 ) ;
F_77 ( V_24 ) ;
}
static int F_84 ( unsigned int V_153 )
{
struct V_23 * V_24 ;
if ( ! V_29 [ V_153 ] )
V_29 [ V_153 ] = F_85 ( sizeof( struct V_23 ) ,
V_154 ) ;
if ( ! V_29 [ V_153 ] )
return - V_155 ;
V_24 = V_29 [ V_153 ] ;
V_24 -> V_24 = V_153 ;
if ( V_57 )
F_45 ( V_24 ) ;
F_66 ( V_24 ) ;
F_86 ( & V_24 -> V_141 ) ;
V_24 -> V_141 . V_51 = ( unsigned long ) V_24 ;
V_24 -> V_141 . V_156 = V_142 + V_157 / 100 ;
if ( ! V_57 )
V_24 -> V_141 . V_158 = F_83 ;
else
V_24 -> V_141 . V_158 = F_82 ;
F_12 ( V_24 ) ;
F_69 ( V_24 ) ;
F_87 ( & V_24 -> V_141 , V_153 ) ;
F_58 ( L_7 , V_153 ) ;
return 0 ;
}
static unsigned int F_88 ( unsigned int V_159 )
{
struct V_126 * V_126 ;
struct V_23 * V_24 ;
V_24 = V_29 [ V_159 ] ;
if ( ! V_24 )
return 0 ;
V_126 = & V_24 -> V_126 ;
return V_126 -> V_130 ;
}
static int F_89 ( struct V_160 * V_161 )
{
if ( ! V_161 -> V_162 . V_163 )
return - V_164 ;
if ( V_161 -> V_161 == V_165 &&
V_161 -> V_40 >= V_161 -> V_162 . V_163 ) {
F_58 ( L_8 ) ;
V_32 = & V_166 ;
if ( V_57 )
F_17 () ;
return 0 ;
}
F_58 ( L_9 ) ;
V_32 = & V_167 ;
V_32 -> V_78 = ( V_161 -> V_38 * 100 ) / V_161 -> V_162 . V_163 ;
V_32 -> V_78 = F_38 ( int , V_32 -> V_78 , 0 , 100 ) ;
V_32 -> V_77 = F_90 ( V_161 -> V_40 * 100 ,
V_161 -> V_162 . V_163 ) ;
V_32 -> V_77 = F_38 ( int , V_32 -> V_77 , 0 , 100 ) ;
V_32 -> V_48 = V_40 ( V_32 -> V_78 ,
V_32 -> V_80 ) ;
V_32 -> V_48 = V_38 ( V_32 -> V_77 ,
V_32 -> V_48 ) ;
V_32 -> V_49 = V_38 ( V_32 -> V_77 ,
V_32 -> V_76 ) ;
V_32 -> V_49 = V_40 ( V_32 -> V_78 ,
V_32 -> V_49 ) ;
V_32 -> V_79 = F_91 ( V_32 -> V_79 , V_4 ) ;
V_32 -> V_48 = V_38 ( V_32 -> V_49 , V_32 -> V_48 ) ;
V_32 -> V_81 = F_2 ( F_7 ( V_32 -> V_48 ) ,
F_7 ( 100 ) ) ;
V_32 -> V_79 = F_2 ( F_7 ( V_32 -> V_49 ) ,
F_7 ( 100 ) ) ;
if ( V_57 )
F_17 () ;
return 0 ;
}
static int F_92 ( struct V_160 * V_161 )
{
F_93 ( V_161 ) ;
if ( V_161 -> V_161 != V_168 &&
V_161 -> V_161 != V_165 )
return - V_74 ;
return 0 ;
}
static void F_94 ( struct V_160 * V_161 )
{
int V_159 = V_161 -> V_24 ;
struct V_23 * V_24 = V_29 [ V_159 ] ;
F_58 ( L_10 , V_159 ) ;
F_95 ( & V_29 [ V_159 ] -> V_141 ) ;
if ( V_57 )
return;
F_64 ( V_24 , V_24 -> V_35 . V_69 , false ) ;
}
static int F_96 ( struct V_160 * V_161 )
{
struct V_23 * V_24 ;
int V_83 ;
V_83 = F_84 ( V_161 -> V_24 ) ;
if ( V_83 )
return V_83 ;
V_24 = V_29 [ V_161 -> V_24 ] ;
if ( V_32 -> V_48 == 100 && V_32 -> V_49 == 100 )
V_161 -> V_161 = V_165 ;
else
V_161 -> V_161 = V_168 ;
V_161 -> V_38 = V_24 -> V_35 . V_69 * V_24 -> V_35 . V_116 ;
V_161 -> V_40 = V_24 -> V_35 . V_37 * V_24 -> V_35 . V_116 ;
V_161 -> V_162 . V_169 = V_24 -> V_35 . V_69 * V_24 -> V_35 . V_116 ;
V_161 -> V_162 . V_163 =
V_24 -> V_35 . V_37 * V_24 -> V_35 . V_116 ;
V_161 -> V_162 . V_170 = V_171 ;
F_97 ( V_161 -> V_24 , V_161 -> V_172 ) ;
return 0 ;
}
static int F_98 ( void )
{
if ( ! V_117 . V_120 () ||
! V_117 . V_119 () ||
! V_117 . V_123 () )
return - V_164 ;
return 0 ;
}
static void F_99 ( struct V_173 * V_161 )
{
V_25 . V_143 = V_161 -> V_143 ;
V_25 . V_26 = V_161 -> V_26 ;
V_25 . V_28 = V_161 -> V_28 ;
V_25 . V_27 = V_161 -> V_27 ;
V_25 . V_11 = V_161 -> V_11 ;
V_25 . V_9 = V_161 -> V_9 ;
}
static void F_100 ( struct V_117 * V_174 )
{
V_117 . V_120 = V_174 -> V_120 ;
V_117 . V_122 = V_174 -> V_122 ;
V_117 . V_119 = V_174 -> V_119 ;
V_117 . V_123 = V_174 -> V_123 ;
V_117 . V_124 = V_174 -> V_124 ;
V_117 . V_118 = V_174 -> V_118 ;
V_117 . V_125 = V_174 -> V_125 ;
}
static bool F_101 ( void )
{
int V_56 ;
F_102 (i) {
T_8 V_175 ;
union V_176 * V_177 ;
struct V_178 V_179 = { V_180 , NULL } ;
struct V_181 * V_182 = F_103 ( V_183 , V_56 ) ;
if ( ! V_182 )
continue;
V_175 = F_104 ( V_182 -> V_184 , L_11 , NULL , & V_179 ) ;
if ( F_105 ( V_175 ) )
continue;
V_177 = V_179 . V_185 ;
if ( V_177 && V_177 -> type == V_186 ) {
F_106 ( V_177 ) ;
return false ;
}
F_106 ( V_177 ) ;
}
return true ;
}
static bool F_107 ( void )
{
int V_56 ;
F_102 (i) {
struct V_181 * V_182 = F_103 ( V_183 , V_56 ) ;
if ( ! V_182 )
continue;
if ( F_108 ( V_182 -> V_184 , L_12 ) )
return true ;
}
return false ;
}
static bool F_109 ( void )
{
struct V_187 V_188 ;
struct V_189 * V_190 ;
const struct V_191 * V_192 ;
T_3 V_193 ;
V_192 = F_110 ( V_194 ) ;
if ( V_192 ) {
F_16 ( V_195 , V_193 ) ;
if ( V_193 & ( 1 << 8 ) )
return true ;
}
if ( V_196 ||
F_105 ( F_111 ( V_197 , 0 , & V_188 ) ) )
return false ;
for ( V_190 = V_198 ; V_190 -> V_199 ; V_190 ++ ) {
if ( ! strncmp ( V_188 . V_200 , V_190 -> V_200 , V_201 ) &&
! strncmp ( V_188 . V_202 , V_190 -> V_202 ,
V_203 ) )
switch ( V_190 -> V_204 ) {
case V_205 :
return F_101 () ;
case V_206 :
return F_107 () &&
( ! V_207 ) ;
}
}
return false ;
}
static inline bool F_109 ( void ) { return false ; }
static inline bool F_107 ( void ) { return false ; }
static int T_4 F_112 ( void )
{
int V_24 , V_83 = 0 ;
const struct V_191 * V_192 ;
struct V_208 * V_209 ;
if ( V_210 )
return - V_164 ;
V_192 = F_110 ( V_211 ) ;
if ( ! V_192 )
return - V_164 ;
if ( F_109 () )
return - V_164 ;
V_209 = (struct V_208 * ) V_192 -> V_212 ;
F_99 ( & V_209 -> V_213 ) ;
F_100 ( & V_209 -> V_174 ) ;
if ( F_98 () )
return - V_164 ;
F_113 ( L_13 ) ;
V_29 = F_114 ( sizeof( void * ) * F_115 () ) ;
if ( ! V_29 )
return - V_155 ;
if ( F_116 ( V_214 ) && ! V_215 ) {
F_113 ( L_14 ) ;
V_57 ++ ;
}
if ( ! V_57 && V_216 )
goto V_217;
V_83 = F_117 ( & V_218 ) ;
if ( V_83 )
goto V_217;
F_29 () ;
F_41 () ;
return V_83 ;
V_217:
F_20 () ;
F_14 (cpu) {
if ( V_29 [ V_24 ] ) {
F_95 ( & V_29 [ V_24 ] -> V_141 ) ;
F_106 ( V_29 [ V_24 ] ) ;
}
}
F_26 () ;
F_118 ( V_29 ) ;
return - V_164 ;
}
static int T_4 F_119 ( char * V_219 )
{
if ( ! V_219 )
return - V_74 ;
if ( ! strcmp ( V_219 , L_15 ) )
V_210 = 1 ;
if ( ! strcmp ( V_219 , L_16 ) ) {
F_113 ( L_17 ) ;
V_215 = 1 ;
}
if ( ! strcmp ( V_219 , L_18 ) )
V_207 = 1 ;
if ( ! strcmp ( V_219 , L_19 ) )
V_216 = 1 ;
return 0 ;
}
