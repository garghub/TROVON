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
V_8 -> V_9 = F_7 ( V_9 ) ;
V_8 -> V_11 = F_7 ( V_11 ) ;
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
V_21 = V_8 -> V_9 - V_10 ;
if ( abs ( V_21 ) <= V_8 -> V_11 )
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
static void F_17 ( const struct V_38 * V_38 )
{
int V_39 , V_40 , V_41 , V_42 , V_24 , V_43 , V_44 ;
T_3 V_45 , V_46 ;
F_16 ( V_47 , V_46 ) ;
V_40 = F_18 ( V_46 ) ;
V_42 = F_19 ( V_46 ) ;
V_43 = V_42 - V_40 ;
F_20 (cpu, cpumask) {
F_21 ( V_24 , V_48 , & V_45 ) ;
V_44 = V_32 -> V_49 * V_43 / 100 ;
V_39 = V_40 + V_44 ;
V_45 &= ~ F_22 ( ~ 0L ) ;
V_45 |= F_22 ( V_39 ) ;
V_44 = V_32 -> V_50 * V_43 / 100 ;
V_41 = V_40 + V_44 ;
if ( V_32 -> V_51 ) {
V_42 = F_23 ( V_46 ) ;
if ( V_42 < V_41 )
V_41 = V_42 ;
}
V_45 &= ~ F_24 ( ~ 0L ) ;
V_45 |= F_24 ( V_41 ) ;
F_25 ( V_24 , V_48 , V_45 ) ;
}
}
static int F_26 ( struct V_52 * V_53 )
{
if ( V_54 )
F_17 ( V_53 -> V_55 ) ;
return 0 ;
}
static void F_27 ( void )
{
F_28 () ;
F_17 ( V_56 ) ;
F_29 () ;
}
static int F_30 ( void * V_57 , T_3 V_58 )
{
* ( V_59 * ) V_57 = V_58 ;
F_13 () ;
return 0 ;
}
static int F_31 ( void * V_57 , T_3 * V_58 )
{
* V_58 = * ( V_59 * ) V_57 ;
return 0 ;
}
static void T_4 F_32 ( void )
{
struct V_60 * V_61 ;
int V_62 = 0 ;
if ( V_54 )
return;
V_61 = F_33 ( L_1 , NULL ) ;
if ( F_34 ( V_61 ) )
return;
while ( V_63 [ V_62 ] . V_64 ) {
F_35 ( V_63 [ V_62 ] . V_64 , 0660 ,
V_61 , V_63 [ V_62 ] . V_45 ,
& V_65 ) ;
V_62 ++ ;
}
}
static T_5 F_36 ( struct V_66 * V_67 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_23 * V_24 ;
int V_71 , V_51 , V_72 ;
T_6 V_73 ;
V_24 = V_29 [ 0 ] ;
V_71 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_74 + 1 ;
V_51 = V_24 -> V_35 . V_36 - V_24 -> V_35 . V_74 + 1 ;
V_73 = F_2 ( F_7 ( V_51 ) , F_7 ( V_71 ) ) ;
V_72 = 100 - F_5 ( F_1 ( V_73 , F_7 ( 100 ) ) ) ;
return sprintf ( V_70 , L_2 , V_72 ) ;
}
static T_5 F_37 ( struct V_66 * V_67 ,
struct V_68 * V_69 , char * V_70 )
{
struct V_23 * V_24 ;
int V_71 ;
V_24 = V_29 [ 0 ] ;
V_71 = V_24 -> V_35 . V_37 - V_24 -> V_35 . V_74 + 1 ;
return sprintf ( V_70 , L_2 , V_71 ) ;
}
static T_5 F_38 ( struct V_66 * V_67 ,
struct V_68 * V_69 , char * V_70 )
{
T_5 V_6 ;
F_15 () ;
if ( V_32 -> V_33 )
V_6 = sprintf ( V_70 , L_2 , V_32 -> V_33 ) ;
else
V_6 = sprintf ( V_70 , L_2 , V_32 -> V_51 ) ;
return V_6 ;
}
static T_5 F_39 ( struct V_66 * V_75 , struct V_68 * V_76 ,
const char * V_70 , T_7 V_77 )
{
unsigned int V_78 ;
int V_6 ;
V_6 = sscanf ( V_70 , L_3 , & V_78 ) ;
if ( V_6 != 1 )
return - V_79 ;
F_15 () ;
if ( V_32 -> V_33 ) {
F_40 ( L_4 ) ;
return - V_80 ;
}
V_32 -> V_51 = F_41 ( int , V_78 , 0 , 1 ) ;
if ( V_54 )
F_27 () ;
return V_77 ;
}
static T_5 F_42 ( struct V_66 * V_75 , struct V_68 * V_76 ,
const char * V_70 , T_7 V_77 )
{
unsigned int V_78 ;
int V_6 ;
V_6 = sscanf ( V_70 , L_3 , & V_78 ) ;
if ( V_6 != 1 )
return - V_79 ;
V_32 -> V_81 = F_41 ( int , V_78 , 0 , 100 ) ;
V_32 -> V_50 = V_39 ( V_32 -> V_82 ,
V_32 -> V_81 ) ;
V_32 -> V_50 = V_41 ( V_32 -> V_83 ,
V_32 -> V_50 ) ;
V_32 -> V_50 = V_41 ( V_32 -> V_49 ,
V_32 -> V_50 ) ;
V_32 -> V_84 = F_2 ( F_7 ( V_32 -> V_50 ) ,
F_7 ( 100 ) ) ;
if ( V_54 )
F_27 () ;
return V_77 ;
}
static T_5 F_43 ( struct V_66 * V_75 , struct V_68 * V_76 ,
const char * V_70 , T_7 V_77 )
{
unsigned int V_78 ;
int V_6 ;
V_6 = sscanf ( V_70 , L_3 , & V_78 ) ;
if ( V_6 != 1 )
return - V_79 ;
V_32 -> V_85 = F_41 ( int , V_78 , 0 , 100 ) ;
V_32 -> V_49 = V_41 ( V_32 -> V_83 ,
V_32 -> V_85 ) ;
V_32 -> V_49 = V_39 ( V_32 -> V_82 ,
V_32 -> V_49 ) ;
V_32 -> V_49 = V_39 ( V_32 -> V_50 ,
V_32 -> V_49 ) ;
V_32 -> V_86 = F_2 ( F_7 ( V_32 -> V_49 ) ,
F_7 ( 100 ) ) ;
if ( V_54 )
F_27 () ;
return V_77 ;
}
static void T_4 F_44 ( void )
{
struct V_66 * V_87 ;
int V_88 ;
V_87 = F_45 ( L_5 ,
& V_89 . V_90 -> V_67 ) ;
F_46 ( ! V_87 ) ;
V_88 = F_47 ( V_87 , & V_91 ) ;
F_46 ( V_88 ) ;
}
static void F_48 ( struct V_23 * V_23 )
{
F_25 ( V_23 -> V_24 , V_92 , 0x00 ) ;
F_25 ( V_23 -> V_24 , V_93 , 0x1 ) ;
}
static int F_49 ( void )
{
T_3 V_45 ;
F_16 ( V_94 , V_45 ) ;
return ( V_45 >> 8 ) & 0x7F ;
}
static int F_50 ( void )
{
T_3 V_45 ;
F_16 ( V_94 , V_45 ) ;
return ( V_45 >> 16 ) & 0x7F ;
}
static int F_51 ( void )
{
T_3 V_45 ;
F_16 ( V_95 , V_45 ) ;
return V_45 & 0x7F ;
}
static T_3 F_52 ( struct V_23 * V_23 , int V_35 )
{
T_3 V_58 ;
T_1 V_96 ;
V_59 V_97 ;
V_58 = ( T_3 ) V_35 << 8 ;
if ( V_32 -> V_51 && ! V_32 -> V_33 )
V_58 |= ( T_3 ) 1 << 32 ;
V_96 = V_23 -> V_97 . V_39 + F_1 (
F_7 ( V_35 - V_23 -> V_35 . V_74 ) ,
V_23 -> V_97 . V_98 ) ;
V_96 = F_41 ( T_1 , V_96 , V_23 -> V_97 . V_39 , V_23 -> V_97 . V_41 ) ;
V_97 = F_4 ( V_96 ) ;
if ( V_35 > V_23 -> V_35 . V_36 )
V_97 = V_23 -> V_97 . V_99 ;
return V_58 | V_97 ;
}
static int F_53 ( void )
{
T_3 V_45 ;
int V_62 ;
static int V_100 [] = {
83300 , 100000 , 133300 , 116700 , 80000 } ;
F_16 ( V_101 , V_45 ) ;
V_62 = V_45 & 0x7 ;
F_54 ( V_62 > 4 ) ;
return V_100 [ V_62 ] ;
}
static int F_55 ( void )
{
T_3 V_45 ;
int V_62 ;
static int V_102 [] = {
83300 , 100000 , 133300 , 116700 , 80000 ,
93300 , 90000 , 88900 , 87500 } ;
F_16 ( V_101 , V_45 ) ;
V_62 = V_45 & 0xF ;
F_54 ( V_62 > 8 ) ;
return V_102 [ V_62 ] ;
}
static void F_56 ( struct V_23 * V_23 )
{
T_3 V_45 ;
F_16 ( V_103 , V_45 ) ;
V_23 -> V_97 . V_39 = F_7 ( ( V_45 >> 8 ) & 0x7f ) ;
V_23 -> V_97 . V_41 = F_7 ( ( V_45 >> 16 ) & 0x7f ) ;
V_23 -> V_97 . V_98 = F_2 (
V_23 -> V_97 . V_41 - V_23 -> V_97 . V_39 ,
F_7 ( V_23 -> V_35 . V_36 -
V_23 -> V_35 . V_74 ) ) ;
F_16 ( V_104 , V_45 ) ;
V_23 -> V_97 . V_99 = V_45 & 0x7f ;
}
static int F_57 ( void )
{
T_3 V_45 ;
F_16 ( V_105 , V_45 ) ;
return ( V_45 >> 40 ) & 0xFF ;
}
static int F_58 ( void )
{
T_3 V_45 ;
F_16 ( V_105 , V_45 ) ;
return ( V_45 >> 8 ) & 0xFF ;
}
static int F_59 ( void )
{
T_3 V_106 ;
T_3 V_107 ;
int V_36 ;
int V_108 ;
F_16 ( V_105 , V_107 ) ;
V_36 = ( V_107 >> 8 ) & 0xFF ;
V_108 = F_60 ( V_109 , & V_106 ) ;
if ( ! V_108 ) {
if ( V_107 & 0x600000000 ) {
T_3 V_110 ;
T_3 V_111 ;
int V_112 ;
V_108 = F_60 ( V_113 , & V_110 ) ;
if ( V_108 )
goto V_114;
V_112 = V_115 + V_110 ;
V_108 = F_60 ( V_112 , & V_111 ) ;
if ( V_108 )
goto V_114;
if ( V_110 )
V_111 >>= 16 ;
V_111 &= 0xff ;
if ( V_111 - 1 == V_106 ) {
V_36 = V_106 ;
F_61 ( L_6 , V_36 ) ;
} else {
goto V_114;
}
}
}
V_114:
return V_36 ;
}
static int F_62 ( void )
{
T_3 V_45 ;
int V_116 , V_6 ;
F_16 ( V_117 , V_45 ) ;
V_116 = F_59 () ;
V_6 = ( V_45 ) & 255 ;
if ( V_6 <= V_116 )
V_6 = V_116 ;
return V_6 ;
}
static inline int F_63 ( void )
{
return 100000 ;
}
static T_3 F_64 ( struct V_23 * V_23 , int V_35 )
{
T_3 V_58 ;
V_58 = ( T_3 ) V_35 << 8 ;
if ( V_32 -> V_51 && ! V_32 -> V_33 )
V_58 |= ( T_3 ) 1 << 32 ;
return V_58 ;
}
static int F_65 ( void )
{
T_3 V_45 ;
int V_116 , V_6 ;
F_16 ( V_117 , V_45 ) ;
V_116 = F_59 () ;
V_6 = ( ( ( V_45 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_116 )
V_6 = V_116 ;
return V_6 ;
}
static void F_66 ( struct V_23 * V_24 , int * V_39 , int * V_41 )
{
int V_84 = V_24 -> V_35 . V_37 ;
int V_118 ;
int V_86 ;
if ( V_32 -> V_51 || V_32 -> V_33 )
V_84 = V_24 -> V_35 . V_36 ;
V_118 = F_5 ( V_84 * V_32 -> V_84 ) ;
* V_41 = F_41 ( int , V_118 ,
V_24 -> V_35 . V_74 , V_24 -> V_35 . V_37 ) ;
V_86 = F_5 ( V_84 * V_32 -> V_86 ) ;
* V_39 = F_41 ( int , V_86 , V_24 -> V_35 . V_74 , V_84 ) ;
}
static inline void F_67 ( struct V_23 * V_24 , int V_35 )
{
F_68 ( V_35 * V_24 -> V_35 . V_119 , V_24 -> V_24 ) ;
V_24 -> V_35 . V_120 = V_35 ;
}
static void F_69 ( struct V_23 * V_24 )
{
int V_35 = V_24 -> V_35 . V_74 ;
F_67 ( V_24 , V_35 ) ;
F_25 ( V_24 -> V_24 , V_121 ,
V_122 . V_123 ( V_24 , V_35 ) ) ;
}
static void F_70 ( struct V_23 * V_24 )
{
V_24 -> V_35 . V_74 = V_122 . V_124 () ;
V_24 -> V_35 . V_36 = V_122 . V_125 () ;
V_24 -> V_35 . V_126 = V_122 . V_127 () ;
V_24 -> V_35 . V_37 = V_122 . V_128 () ;
V_24 -> V_35 . V_119 = V_122 . V_129 () ;
if ( V_122 . V_130 )
V_122 . V_130 ( V_24 ) ;
F_69 ( V_24 ) ;
}
static inline void F_71 ( struct V_23 * V_24 )
{
struct V_131 * V_131 = & V_24 -> V_131 ;
V_3 V_132 ;
V_132 = F_7 ( V_131 -> V_133 ) * F_7 ( 100 ) ;
V_132 = F_72 ( V_132 , F_7 ( V_131 -> V_134 ) ) ;
V_131 -> V_135 = ( T_1 ) V_132 ;
}
static inline bool F_73 ( struct V_23 * V_24 , T_3 time )
{
T_3 V_133 , V_134 ;
unsigned long V_136 ;
T_3 V_137 ;
F_74 ( V_136 ) ;
F_16 ( V_138 , V_133 ) ;
F_16 ( V_139 , V_134 ) ;
V_137 = F_75 () ;
if ( V_24 -> V_140 == V_134 || V_24 -> V_141 == V_137 ) {
F_76 ( V_136 ) ;
return false ;
}
F_76 ( V_136 ) ;
V_24 -> V_142 = V_24 -> V_131 . time ;
V_24 -> V_131 . time = time ;
V_24 -> V_131 . V_133 = V_133 ;
V_24 -> V_131 . V_134 = V_134 ;
V_24 -> V_131 . V_137 = V_137 ;
V_24 -> V_131 . V_133 -= V_24 -> V_143 ;
V_24 -> V_131 . V_134 -= V_24 -> V_140 ;
V_24 -> V_131 . V_137 -= V_24 -> V_141 ;
V_24 -> V_143 = V_133 ;
V_24 -> V_140 = V_134 ;
V_24 -> V_141 = V_137 ;
return ! ! V_24 -> V_142 ;
}
static inline T_1 F_77 ( struct V_23 * V_24 )
{
return F_5 ( F_1 ( V_24 -> V_131 . V_135 ,
F_7 ( V_24 -> V_35 . V_126 *
V_24 -> V_35 . V_119 / 100 ) ) ) ;
}
static inline T_1 F_78 ( struct V_23 * V_24 )
{
struct V_131 * V_131 = & V_24 -> V_131 ;
T_3 V_144 , V_145 ;
T_3 V_146 ;
T_3 V_134 , V_147 ;
T_1 V_148 ;
V_144 = F_79 ( V_24 -> V_24 , & V_147 ) ;
V_145 = V_144 - V_24 -> V_149 ;
V_146 = F_72 ( V_145 * V_24 -> V_35 . V_119 *
V_24 -> V_35 . V_36 , V_150 ) ;
V_134 = V_24 -> V_131 . V_134 + V_146 ;
V_24 -> V_149 = V_144 ;
V_148 = F_72 ( F_7 ( 100 ) * V_134 , V_131 -> V_137 ) ;
V_24 -> V_131 . V_151 = V_148 ;
return V_24 -> V_35 . V_120 - F_11 ( & V_24 -> V_8 , V_148 ) ;
}
static inline T_1 F_80 ( struct V_23 * V_24 )
{
T_1 V_152 , V_36 , V_120 , V_153 ;
T_3 V_154 ;
V_152 = V_24 -> V_131 . V_135 ;
V_36 = F_7 ( V_24 -> V_35 . V_126 ) ;
V_120 = F_7 ( V_24 -> V_35 . V_120 ) ;
V_152 = F_1 ( V_152 , F_2 ( V_36 , V_120 ) ) ;
V_154 = V_24 -> V_131 . time - V_24 -> V_142 ;
if ( ( T_2 ) V_154 > V_25 . V_155 * 3 ) {
V_153 = F_2 ( F_7 ( V_25 . V_155 ) ,
F_7 ( V_154 ) ) ;
V_152 = F_1 ( V_152 , V_153 ) ;
} else {
V_153 = F_2 ( 100 * V_24 -> V_131 . V_134 , V_24 -> V_131 . V_137 ) ;
if ( V_153 < F_7 ( 1 ) )
V_152 = 0 ;
}
V_24 -> V_131 . V_151 = V_152 ;
return V_24 -> V_35 . V_120 - F_11 ( & V_24 -> V_8 , V_152 ) ;
}
static inline void F_81 ( struct V_23 * V_24 , int V_35 )
{
int V_84 , V_86 ;
F_15 () ;
F_66 ( V_24 , & V_86 , & V_84 ) ;
V_35 = F_41 ( int , V_35 , V_86 , V_84 ) ;
if ( V_35 == V_24 -> V_35 . V_120 )
return;
F_67 ( V_24 , V_35 ) ;
F_82 ( V_121 , V_122 . V_123 ( V_24 , V_35 ) ) ;
}
static inline void F_83 ( struct V_23 * V_24 )
{
int V_156 , V_157 ;
struct V_131 * V_131 ;
V_156 = V_24 -> V_35 . V_120 ;
V_157 = V_122 . V_158 ( V_24 ) ;
F_81 ( V_24 , V_157 ) ;
V_131 = & V_24 -> V_131 ;
F_84 ( F_5 ( V_131 -> V_135 ) ,
F_5 ( V_131 -> V_151 ) ,
V_156 ,
V_24 -> V_35 . V_120 ,
V_131 -> V_134 ,
V_131 -> V_133 ,
V_131 -> V_137 ,
F_77 ( V_24 ) ) ;
}
static void F_85 ( struct V_159 * V_57 , T_3 time ,
unsigned long V_160 , unsigned long V_41 )
{
struct V_23 * V_24 = F_86 ( V_57 , struct V_23 , V_161 ) ;
T_3 V_162 = time - V_24 -> V_131 . time ;
if ( ( T_2 ) V_162 >= V_25 . V_155 ) {
bool V_163 = F_73 ( V_24 , time ) ;
if ( V_163 ) {
F_71 ( V_24 ) ;
if ( ! V_54 )
F_83 ( V_24 ) ;
}
}
}
static int F_87 ( unsigned int V_164 )
{
struct V_23 * V_24 ;
if ( ! V_29 [ V_164 ] )
V_29 [ V_164 ] = F_88 ( sizeof( struct V_23 ) ,
V_165 ) ;
if ( ! V_29 [ V_164 ] )
return - V_166 ;
V_24 = V_29 [ V_164 ] ;
V_24 -> V_24 = V_164 ;
if ( V_54 ) {
F_48 ( V_24 ) ;
V_25 . V_167 = 50 ;
V_25 . V_155 = 50 * V_168 ;
}
F_70 ( V_24 ) ;
F_12 ( V_24 ) ;
V_24 -> V_161 . V_169 = F_85 ;
F_61 ( L_7 , V_164 ) ;
return 0 ;
}
static unsigned int F_89 ( unsigned int V_170 )
{
struct V_131 * V_131 ;
struct V_23 * V_24 ;
V_24 = V_29 [ V_170 ] ;
if ( ! V_24 )
return 0 ;
V_131 = & V_24 -> V_131 ;
return F_77 ( V_24 ) ;
}
static void F_90 ( unsigned int V_170 )
{
struct V_23 * V_24 = V_29 [ V_170 ] ;
V_24 -> V_131 . time = 0 ;
F_91 ( V_170 , & V_24 -> V_161 ) ;
}
static void F_92 ( unsigned int V_24 )
{
F_91 ( V_24 , NULL ) ;
F_93 () ;
}
static void F_94 ( struct V_171 * V_32 )
{
V_32 -> V_51 = 0 ;
V_32 -> V_33 = 0 ;
V_32 -> V_50 = 100 ;
V_32 -> V_84 = F_7 ( 1 ) ;
V_32 -> V_49 = 100 ;
V_32 -> V_86 = F_7 ( 1 ) ;
V_32 -> V_82 = 100 ;
V_32 -> V_81 = 100 ;
V_32 -> V_83 = 0 ;
V_32 -> V_85 = 0 ;
}
static int F_95 ( struct V_52 * V_53 )
{
if ( ! V_53 -> V_172 . V_173 )
return - V_174 ;
F_92 ( V_53 -> V_24 ) ;
if ( V_53 -> V_53 == V_175 ) {
V_32 = & V_176 ;
if ( V_53 -> V_41 >= V_53 -> V_172 . V_173 ) {
F_61 ( L_8 ) ;
F_94 ( V_32 ) ;
goto V_177;
}
} else {
F_61 ( L_9 ) ;
V_32 = & V_178 ;
}
V_32 -> V_83 = ( V_53 -> V_39 * 100 ) / V_53 -> V_172 . V_173 ;
V_32 -> V_83 = F_41 ( int , V_32 -> V_83 , 0 , 100 ) ;
V_32 -> V_82 = F_96 ( V_53 -> V_41 * 100 ,
V_53 -> V_172 . V_173 ) ;
V_32 -> V_82 = F_41 ( int , V_32 -> V_82 , 0 , 100 ) ;
V_32 -> V_49 = V_41 ( V_32 -> V_83 ,
V_32 -> V_85 ) ;
V_32 -> V_49 = V_39 ( V_32 -> V_82 ,
V_32 -> V_49 ) ;
V_32 -> V_50 = V_39 ( V_32 -> V_82 ,
V_32 -> V_81 ) ;
V_32 -> V_50 = V_41 ( V_32 -> V_83 ,
V_32 -> V_50 ) ;
V_32 -> V_84 = F_97 ( V_32 -> V_84 , V_4 ) ;
V_32 -> V_49 = V_39 ( V_32 -> V_50 , V_32 -> V_49 ) ;
V_32 -> V_86 = F_2 ( F_7 ( V_32 -> V_49 ) ,
F_7 ( 100 ) ) ;
V_32 -> V_84 = F_2 ( F_7 ( V_32 -> V_50 ) ,
F_7 ( 100 ) ) ;
V_177:
F_90 ( V_53 -> V_24 ) ;
F_26 ( V_53 ) ;
return 0 ;
}
static int F_98 ( struct V_52 * V_53 )
{
F_99 ( V_53 ) ;
if ( V_53 -> V_53 != V_179 &&
V_53 -> V_53 != V_175 )
return - V_79 ;
return 0 ;
}
static void F_100 ( struct V_52 * V_53 )
{
int V_170 = V_53 -> V_24 ;
struct V_23 * V_24 = V_29 [ V_170 ] ;
F_61 ( L_10 , V_170 ) ;
F_92 ( V_170 ) ;
if ( V_54 )
return;
F_69 ( V_24 ) ;
}
static int F_101 ( struct V_52 * V_53 )
{
struct V_23 * V_24 ;
int V_88 ;
V_88 = F_87 ( V_53 -> V_24 ) ;
if ( V_88 )
return V_88 ;
V_24 = V_29 [ V_53 -> V_24 ] ;
if ( V_32 -> V_49 == 100 && V_32 -> V_50 == 100 )
V_53 -> V_53 = V_175 ;
else
V_53 -> V_53 = V_179 ;
V_53 -> V_39 = V_24 -> V_35 . V_74 * V_24 -> V_35 . V_119 ;
V_53 -> V_41 = V_24 -> V_35 . V_37 * V_24 -> V_35 . V_119 ;
V_53 -> V_172 . V_180 = V_24 -> V_35 . V_74 * V_24 -> V_35 . V_119 ;
V_53 -> V_172 . V_173 =
V_24 -> V_35 . V_37 * V_24 -> V_35 . V_119 ;
V_53 -> V_172 . V_181 = V_182 ;
F_102 ( V_53 -> V_24 , V_53 -> V_55 ) ;
return 0 ;
}
static int F_103 ( void )
{
if ( ! V_122 . V_125 () ||
! V_122 . V_124 () ||
! V_122 . V_128 () )
return - V_174 ;
return 0 ;
}
static void F_104 ( struct V_183 * V_53 )
{
V_25 . V_167 = V_53 -> V_167 ;
V_25 . V_155 = V_25 . V_167 * V_168 ;
V_25 . V_26 = V_53 -> V_26 ;
V_25 . V_28 = V_53 -> V_28 ;
V_25 . V_27 = V_53 -> V_27 ;
V_25 . V_11 = V_53 -> V_11 ;
V_25 . V_9 = V_53 -> V_9 ;
}
static void F_105 ( struct V_122 * V_184 )
{
V_122 . V_125 = V_184 -> V_125 ;
V_122 . V_127 = V_184 -> V_127 ;
V_122 . V_124 = V_184 -> V_124 ;
V_122 . V_128 = V_184 -> V_128 ;
V_122 . V_129 = V_184 -> V_129 ;
V_122 . V_123 = V_184 -> V_123 ;
V_122 . V_130 = V_184 -> V_130 ;
V_122 . V_158 = V_184 -> V_158 ;
}
static bool F_106 ( void )
{
int V_62 ;
F_107 (i) {
T_8 V_185 ;
union V_186 * V_187 ;
struct V_188 V_189 = { V_190 , NULL } ;
struct V_191 * V_192 = F_108 ( V_193 , V_62 ) ;
if ( ! V_192 )
continue;
V_185 = F_109 ( V_192 -> V_194 , L_11 , NULL , & V_189 ) ;
if ( F_110 ( V_185 ) )
continue;
V_187 = V_189 . V_195 ;
if ( V_187 && V_187 -> type == V_196 ) {
F_111 ( V_187 ) ;
return false ;
}
F_111 ( V_187 ) ;
}
return true ;
}
static bool F_112 ( void )
{
int V_62 ;
F_107 (i) {
struct V_191 * V_192 = F_108 ( V_193 , V_62 ) ;
if ( ! V_192 )
continue;
if ( F_113 ( V_192 -> V_194 , L_12 ) )
return true ;
}
return false ;
}
static bool F_114 ( void )
{
struct V_197 V_198 ;
struct V_199 * V_200 ;
const struct V_201 * V_202 ;
T_3 V_203 ;
V_202 = F_115 ( V_204 ) ;
if ( V_202 ) {
F_16 ( V_205 , V_203 ) ;
if ( V_203 & ( 1 << 8 ) )
return true ;
}
if ( V_206 ||
F_110 ( F_116 ( V_207 , 0 , & V_198 ) ) )
return false ;
for ( V_200 = V_208 ; V_200 -> V_209 ; V_200 ++ ) {
if ( ! strncmp ( V_198 . V_210 , V_200 -> V_210 , V_211 ) &&
! strncmp ( V_198 . V_212 , V_200 -> V_212 ,
V_213 ) )
switch ( V_200 -> V_214 ) {
case V_215 :
return F_106 () ;
case V_216 :
return F_112 () &&
( ! V_217 ) ;
}
}
return false ;
}
static inline bool F_114 ( void ) { return false ; }
static inline bool F_112 ( void ) { return false ; }
static int T_4 F_117 ( void )
{
int V_24 , V_88 = 0 ;
const struct V_201 * V_202 ;
struct V_218 * V_219 ;
if ( V_220 )
return - V_174 ;
if ( F_115 ( V_221 ) && ! V_222 ) {
F_105 ( & V_223 . V_184 ) ;
V_54 ++ ;
goto V_224;
}
V_202 = F_115 ( V_225 ) ;
if ( ! V_202 )
return - V_174 ;
V_219 = (struct V_218 * ) V_202 -> V_226 ;
F_104 ( & V_219 -> V_227 ) ;
F_105 ( & V_219 -> V_184 ) ;
if ( F_103 () )
return - V_174 ;
V_224:
if ( F_114 () )
return - V_174 ;
F_118 ( L_13 ) ;
V_29 = F_119 ( sizeof( void * ) * F_120 () ) ;
if ( ! V_29 )
return - V_166 ;
if ( ! V_54 && V_228 )
goto V_177;
V_88 = F_121 ( & V_229 ) ;
if ( V_88 )
goto V_177;
F_32 () ;
F_44 () ;
if ( V_54 )
F_118 ( L_14 ) ;
return V_88 ;
V_177:
F_28 () ;
F_14 (cpu) {
if ( V_29 [ V_24 ] ) {
F_92 ( V_24 ) ;
F_111 ( V_29 [ V_24 ] ) ;
}
}
F_29 () ;
F_122 ( V_29 ) ;
return - V_174 ;
}
static int T_4 F_123 ( char * V_230 )
{
if ( ! V_230 )
return - V_79 ;
if ( ! strcmp ( V_230 , L_15 ) )
V_220 = 1 ;
if ( ! strcmp ( V_230 , L_16 ) ) {
F_118 ( L_17 ) ;
V_222 = 1 ;
}
if ( ! strcmp ( V_230 , L_18 ) )
V_217 = 1 ;
if ( ! strcmp ( V_230 , L_19 ) )
V_228 = 1 ;
return 0 ;
}
