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
static inline T_3 F_6 ( T_3 V_1 , T_3 V_2 )
{
return ( V_1 * V_2 ) >> V_7 ;
}
static inline T_3 F_7 ( T_3 V_1 , T_3 V_2 )
{
return F_8 ( V_1 << V_7 , V_2 ) ;
}
static bool F_9 ( void )
{
if ( V_8 . V_9 == V_10 ||
V_8 . V_9 == V_11 )
return true ;
return V_12 ;
}
static void F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_6 ;
int V_17 ;
if ( V_18 )
return;
if ( ! F_9 () )
return;
V_16 = V_19 [ V_14 -> V_16 ] ;
V_6 = F_11 ( & V_16 -> V_20 ,
V_14 -> V_16 ) ;
if ( V_6 )
return;
if ( V_16 -> V_20 . V_21 . V_22 !=
V_23 )
goto V_24;
if ( V_16 -> V_20 . V_25 < 2 )
goto V_24;
F_12 ( L_1 , V_14 -> V_16 ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_20 . V_25 ; V_17 ++ ) {
F_12 ( L_2 ,
( V_17 == V_16 -> V_20 . V_26 ? '*' : ' ' ) , V_17 ,
( V_27 ) V_16 -> V_20 . V_28 [ V_17 ] . V_29 ,
( V_27 ) V_16 -> V_20 . V_28 [ V_17 ] . V_30 ,
( V_27 ) V_16 -> V_20 . V_28 [ V_17 ] . V_31 ) ;
}
if ( ! V_32 -> V_33 )
V_16 -> V_20 . V_28 [ 0 ] . V_29 =
V_14 -> V_34 . V_35 / 1000 ;
V_16 -> V_36 = true ;
F_12 ( L_3 ) ;
return;
V_24:
V_16 -> V_36 = false ;
F_13 ( V_14 -> V_16 ) ;
}
static void F_14 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
V_16 = V_19 [ V_14 -> V_16 ] ;
if ( ! V_16 -> V_36 )
return;
F_13 ( V_14 -> V_16 ) ;
}
static void F_10 ( struct V_13 * V_14 )
{
}
static void F_14 ( struct V_13 * V_14 )
{
}
static inline void F_15 ( struct V_37 * V_38 , int V_39 , int V_40 ,
int V_41 , int V_42 ) {
V_38 -> V_39 = F_16 ( V_39 ) ;
V_38 -> V_41 = F_16 ( V_41 ) ;
V_38 -> V_42 = F_16 ( V_42 ) ;
V_38 -> V_43 = F_16 ( V_39 ) - F_16 ( V_40 ) ;
}
static inline void F_17 ( struct V_37 * V_38 , int V_44 )
{
V_38 -> V_45 = F_2 ( V_44 , 100 ) ;
}
static inline void F_18 ( struct V_37 * V_38 , int V_44 )
{
V_38 -> V_46 = F_2 ( V_44 , 100 ) ;
}
static inline void F_19 ( struct V_37 * V_38 , int V_44 )
{
V_38 -> V_47 = F_2 ( V_44 , 100 ) ;
}
static signed int F_20 ( struct V_37 * V_38 , T_1 V_40 )
{
signed int V_48 ;
T_1 V_49 , V_50 , V_51 ;
T_1 V_52 ;
V_51 = V_38 -> V_39 - V_40 ;
if ( abs ( V_51 ) <= V_38 -> V_41 )
return 0 ;
V_49 = F_1 ( V_38 -> V_45 , V_51 ) ;
V_38 -> V_42 += V_51 ;
V_52 = F_16 ( 30 ) ;
if ( V_38 -> V_42 > V_52 )
V_38 -> V_42 = V_52 ;
if ( V_38 -> V_42 < - V_52 )
V_38 -> V_42 = - V_52 ;
V_50 = F_1 ( V_38 -> V_47 , V_51 - V_38 -> V_43 ) ;
V_38 -> V_43 = V_51 ;
V_48 = V_49 + F_1 ( V_38 -> V_42 , V_38 -> V_46 ) + V_50 ;
V_48 = V_48 + ( 1 << ( V_4 - 1 ) ) ;
return ( signed int ) F_5 ( V_48 ) ;
}
static inline void F_21 ( struct V_15 * V_16 )
{
F_17 ( & V_16 -> V_38 , V_53 . V_54 ) ;
F_19 ( & V_16 -> V_38 , V_53 . V_55 ) ;
F_18 ( & V_16 -> V_38 , V_53 . V_56 ) ;
F_15 ( & V_16 -> V_38 , V_53 . V_39 , 100 , V_53 . V_41 , 0 ) ;
}
static inline void F_22 ( void )
{
unsigned int V_16 ;
F_23 (cpu) {
if ( V_19 [ V_16 ] )
F_21 ( V_19 [ V_16 ] ) ;
}
}
static inline void F_24 ( void )
{
T_3 V_57 ;
struct V_15 * V_16 ;
V_16 = V_19 [ 0 ] ;
F_25 ( V_58 , V_57 ) ;
V_32 -> V_33 =
( V_57 & V_59 ||
V_16 -> V_60 . V_61 == V_16 -> V_60 . V_62 ) ;
}
static void F_26 ( const struct V_63 * V_63 )
{
int V_64 , V_65 , V_66 , V_67 , V_16 , V_68 , V_69 ;
T_3 V_70 , V_71 ;
F_25 ( V_72 , V_71 ) ;
V_65 = F_27 ( V_71 ) ;
V_67 = F_28 ( V_71 ) ;
V_68 = V_67 - V_65 ;
F_29 (cpu, cpumask) {
F_30 ( V_16 , V_73 , & V_70 ) ;
V_69 = V_32 -> V_74 * V_68 / 100 ;
V_64 = V_65 + V_69 ;
V_70 &= ~ F_31 ( ~ 0L ) ;
V_70 |= F_31 ( V_64 ) ;
V_69 = V_32 -> V_75 * V_68 / 100 ;
V_66 = V_65 + V_69 ;
if ( V_32 -> V_76 ) {
V_67 = F_32 ( V_71 ) ;
if ( V_67 < V_66 )
V_66 = V_67 ;
}
V_70 &= ~ F_33 ( ~ 0L ) ;
V_70 |= F_33 ( V_66 ) ;
F_34 ( V_16 , V_73 , V_70 ) ;
}
}
static int F_35 ( struct V_13 * V_14 )
{
if ( V_18 )
F_26 ( V_14 -> V_77 ) ;
return 0 ;
}
static void F_36 ( void )
{
F_37 () ;
F_26 ( V_78 ) ;
F_38 () ;
}
static int F_39 ( void * V_79 , T_3 V_80 )
{
* ( V_27 * ) V_79 = V_80 ;
F_22 () ;
return 0 ;
}
static int F_40 ( void * V_79 , T_3 * V_80 )
{
* V_80 = * ( V_27 * ) V_79 ;
return 0 ;
}
static void T_4 F_41 ( void )
{
struct V_81 * V_82 ;
int V_17 = 0 ;
if ( V_18 )
return;
V_82 = F_42 ( L_4 , NULL ) ;
if ( F_43 ( V_82 ) )
return;
while ( V_83 [ V_17 ] . V_84 ) {
F_44 ( V_83 [ V_17 ] . V_84 , 0660 ,
V_82 , V_83 [ V_17 ] . V_70 ,
& V_85 ) ;
V_17 ++ ;
}
}
static T_5 F_45 ( struct V_86 * V_87 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_15 * V_16 ;
int V_91 , V_76 , V_92 ;
T_6 V_93 ;
V_16 = V_19 [ 0 ] ;
V_91 = V_16 -> V_60 . V_62 - V_16 -> V_60 . V_94 + 1 ;
V_76 = V_16 -> V_60 . V_61 - V_16 -> V_60 . V_94 + 1 ;
V_93 = F_2 ( V_76 , V_91 ) ;
V_92 = 100 - F_5 ( F_1 ( V_93 , F_16 ( 100 ) ) ) ;
return sprintf ( V_90 , L_5 , V_92 ) ;
}
static T_5 F_46 ( struct V_86 * V_87 ,
struct V_88 * V_89 , char * V_90 )
{
struct V_15 * V_16 ;
int V_91 ;
V_16 = V_19 [ 0 ] ;
V_91 = V_16 -> V_60 . V_62 - V_16 -> V_60 . V_94 + 1 ;
return sprintf ( V_90 , L_5 , V_91 ) ;
}
static T_5 F_47 ( struct V_86 * V_87 ,
struct V_88 * V_89 , char * V_90 )
{
T_5 V_6 ;
F_24 () ;
if ( V_32 -> V_33 )
V_6 = sprintf ( V_90 , L_5 , V_32 -> V_33 ) ;
else
V_6 = sprintf ( V_90 , L_5 , V_32 -> V_76 ) ;
return V_6 ;
}
static T_5 F_48 ( struct V_86 * V_95 , struct V_88 * V_96 ,
const char * V_90 , T_7 V_97 )
{
unsigned int V_98 ;
int V_6 ;
V_6 = sscanf ( V_90 , L_6 , & V_98 ) ;
if ( V_6 != 1 )
return - V_99 ;
F_24 () ;
if ( V_32 -> V_33 ) {
F_49 ( L_7 ) ;
return - V_100 ;
}
V_32 -> V_76 = F_50 ( int , V_98 , 0 , 1 ) ;
if ( V_18 )
F_36 () ;
return V_97 ;
}
static T_5 F_51 ( struct V_86 * V_95 , struct V_88 * V_96 ,
const char * V_90 , T_7 V_97 )
{
unsigned int V_98 ;
int V_6 ;
V_6 = sscanf ( V_90 , L_6 , & V_98 ) ;
if ( V_6 != 1 )
return - V_99 ;
V_32 -> V_101 = F_50 ( int , V_98 , 0 , 100 ) ;
V_32 -> V_75 = V_64 ( V_32 -> V_102 ,
V_32 -> V_101 ) ;
V_32 -> V_75 = V_66 ( V_32 -> V_103 ,
V_32 -> V_75 ) ;
V_32 -> V_75 = V_66 ( V_32 -> V_74 ,
V_32 -> V_75 ) ;
V_32 -> V_104 = F_2 ( V_32 -> V_75 , 100 ) ;
if ( V_18 )
F_36 () ;
return V_97 ;
}
static T_5 F_52 ( struct V_86 * V_95 , struct V_88 * V_96 ,
const char * V_90 , T_7 V_97 )
{
unsigned int V_98 ;
int V_6 ;
V_6 = sscanf ( V_90 , L_6 , & V_98 ) ;
if ( V_6 != 1 )
return - V_99 ;
V_32 -> V_105 = F_50 ( int , V_98 , 0 , 100 ) ;
V_32 -> V_74 = V_66 ( V_32 -> V_103 ,
V_32 -> V_105 ) ;
V_32 -> V_74 = V_64 ( V_32 -> V_102 ,
V_32 -> V_74 ) ;
V_32 -> V_74 = V_64 ( V_32 -> V_75 ,
V_32 -> V_74 ) ;
V_32 -> V_106 = F_2 ( V_32 -> V_74 , 100 ) ;
if ( V_18 )
F_36 () ;
return V_97 ;
}
static void T_4 F_53 ( void )
{
struct V_86 * V_107 ;
int V_108 ;
V_107 = F_54 ( L_8 ,
& V_109 . V_110 -> V_87 ) ;
F_55 ( ! V_107 ) ;
V_108 = F_56 ( V_107 , & V_111 ) ;
F_55 ( V_108 ) ;
}
static void F_57 ( struct V_15 * V_15 )
{
F_34 ( V_15 -> V_16 , V_112 , 0x00 ) ;
F_34 ( V_15 -> V_16 , V_113 , 0x1 ) ;
}
static int F_58 ( void )
{
T_3 V_70 ;
F_25 ( V_114 , V_70 ) ;
return ( V_70 >> 8 ) & 0x7F ;
}
static int F_59 ( void )
{
T_3 V_70 ;
F_25 ( V_114 , V_70 ) ;
return ( V_70 >> 16 ) & 0x7F ;
}
static int F_60 ( void )
{
T_3 V_70 ;
F_25 ( V_115 , V_70 ) ;
return V_70 & 0x7F ;
}
static T_3 F_61 ( struct V_15 * V_15 , int V_60 )
{
T_3 V_80 ;
T_1 V_116 ;
V_27 V_117 ;
V_80 = ( T_3 ) V_60 << 8 ;
if ( V_32 -> V_76 && ! V_32 -> V_33 )
V_80 |= ( T_3 ) 1 << 32 ;
V_116 = V_15 -> V_117 . V_64 + F_1 (
F_16 ( V_60 - V_15 -> V_60 . V_94 ) ,
V_15 -> V_117 . V_118 ) ;
V_116 = F_50 ( T_1 , V_116 , V_15 -> V_117 . V_64 , V_15 -> V_117 . V_66 ) ;
V_117 = F_4 ( V_116 ) ;
if ( V_60 > V_15 -> V_60 . V_61 )
V_117 = V_15 -> V_117 . V_119 ;
return V_80 | V_117 ;
}
static int F_62 ( void )
{
T_3 V_70 ;
int V_17 ;
static int V_120 [] = {
83300 , 100000 , 133300 , 116700 , 80000 } ;
F_25 ( V_121 , V_70 ) ;
V_17 = V_70 & 0x7 ;
F_63 ( V_17 > 4 ) ;
return V_120 [ V_17 ] ;
}
static int F_64 ( void )
{
T_3 V_70 ;
int V_17 ;
static int V_122 [] = {
83300 , 100000 , 133300 , 116700 , 80000 ,
93300 , 90000 , 88900 , 87500 } ;
F_25 ( V_121 , V_70 ) ;
V_17 = V_70 & 0xF ;
F_63 ( V_17 > 8 ) ;
return V_122 [ V_17 ] ;
}
static void F_65 ( struct V_15 * V_15 )
{
T_3 V_70 ;
F_25 ( V_123 , V_70 ) ;
V_15 -> V_117 . V_64 = F_16 ( ( V_70 >> 8 ) & 0x7f ) ;
V_15 -> V_117 . V_66 = F_16 ( ( V_70 >> 16 ) & 0x7f ) ;
V_15 -> V_117 . V_118 = F_2 (
V_15 -> V_117 . V_66 - V_15 -> V_117 . V_64 ,
F_16 ( V_15 -> V_60 . V_61 -
V_15 -> V_60 . V_94 ) ) ;
F_25 ( V_124 , V_70 ) ;
V_15 -> V_117 . V_119 = V_70 & 0x7f ;
}
static int F_66 ( void )
{
T_3 V_70 ;
F_25 ( V_125 , V_70 ) ;
return ( V_70 >> 40 ) & 0xFF ;
}
static int F_67 ( void )
{
T_3 V_70 ;
F_25 ( V_125 , V_70 ) ;
return ( V_70 >> 8 ) & 0xFF ;
}
static int F_68 ( void )
{
T_3 V_126 ;
T_3 V_127 ;
int V_61 ;
int V_24 ;
F_25 ( V_125 , V_127 ) ;
V_61 = ( V_127 >> 8 ) & 0xFF ;
V_24 = F_69 ( V_128 , & V_126 ) ;
if ( ! V_24 ) {
if ( V_127 & 0x600000000 ) {
T_3 V_129 ;
T_3 V_130 ;
int V_131 ;
V_24 = F_69 ( V_132 , & V_129 ) ;
if ( V_24 )
goto V_133;
V_131 = V_134 + V_129 ;
V_24 = F_69 ( V_131 , & V_130 ) ;
if ( V_24 )
goto V_133;
if ( V_129 )
V_130 >>= 16 ;
V_130 &= 0xff ;
if ( V_130 - 1 == V_126 ) {
V_61 = V_126 ;
F_12 ( L_9 , V_61 ) ;
} else {
goto V_133;
}
}
}
V_133:
return V_61 ;
}
static int F_70 ( void )
{
T_3 V_70 ;
int V_135 , V_6 ;
F_25 ( V_136 , V_70 ) ;
V_135 = F_68 () ;
V_6 = ( V_70 ) & 255 ;
if ( V_6 <= V_135 )
V_6 = V_135 ;
return V_6 ;
}
static inline int F_71 ( void )
{
return 100000 ;
}
static T_3 F_72 ( struct V_15 * V_15 , int V_60 )
{
T_3 V_80 ;
V_80 = ( T_3 ) V_60 << 8 ;
if ( V_32 -> V_76 && ! V_32 -> V_33 )
V_80 |= ( T_3 ) 1 << 32 ;
return V_80 ;
}
static int F_73 ( void )
{
T_3 V_70 ;
int V_135 , V_6 ;
F_25 ( V_136 , V_70 ) ;
V_135 = F_68 () ;
V_6 = ( ( ( V_70 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_135 )
V_6 = V_135 ;
return V_6 ;
}
static void F_74 ( struct V_15 * V_16 , int * V_64 , int * V_66 )
{
int V_104 = V_16 -> V_60 . V_62 ;
int V_137 ;
int V_106 ;
if ( V_32 -> V_76 || V_32 -> V_33 )
V_104 = V_16 -> V_60 . V_61 ;
V_137 = F_5 ( V_104 * V_32 -> V_104 ) ;
* V_66 = F_50 ( int , V_137 ,
V_16 -> V_60 . V_94 , V_16 -> V_60 . V_62 ) ;
V_106 = F_5 ( V_104 * V_32 -> V_106 ) ;
* V_64 = F_50 ( int , V_106 , V_16 -> V_60 . V_94 , V_104 ) ;
}
static inline void F_75 ( struct V_15 * V_16 , int V_60 )
{
F_76 ( V_60 * V_16 -> V_60 . V_138 , V_16 -> V_16 ) ;
V_16 -> V_60 . V_139 = V_60 ;
}
static void F_77 ( struct V_15 * V_16 )
{
int V_60 = V_16 -> V_60 . V_94 ;
F_75 ( V_16 , V_60 ) ;
F_34 ( V_16 -> V_16 , V_140 ,
V_141 . V_142 ( V_16 , V_60 ) ) ;
}
static void F_78 ( struct V_15 * V_16 )
{
V_16 -> V_60 . V_94 = V_141 . V_143 () ;
V_16 -> V_60 . V_61 = V_141 . V_144 () ;
V_16 -> V_60 . V_145 = V_141 . V_146 () ;
V_16 -> V_60 . V_62 = V_141 . V_147 () ;
V_16 -> V_60 . V_138 = V_141 . V_148 () ;
if ( V_141 . V_149 )
V_141 . V_149 ( V_16 ) ;
F_77 ( V_16 ) ;
}
static inline void F_79 ( struct V_15 * V_16 )
{
struct V_150 * V_150 = & V_16 -> V_150 ;
V_150 -> V_151 = F_7 ( V_150 -> V_152 , V_150 -> V_153 ) ;
}
static inline bool F_80 ( struct V_15 * V_16 , T_3 time )
{
T_3 V_152 , V_153 ;
unsigned long V_154 ;
T_3 V_155 ;
F_81 ( V_154 ) ;
F_25 ( V_156 , V_152 ) ;
F_25 ( V_157 , V_153 ) ;
V_155 = F_82 () ;
if ( V_16 -> V_158 == V_153 || V_16 -> V_159 == V_155 ) {
F_83 ( V_154 ) ;
return false ;
}
F_83 ( V_154 ) ;
V_16 -> V_160 = V_16 -> V_150 . time ;
V_16 -> V_150 . time = time ;
V_16 -> V_150 . V_152 = V_152 ;
V_16 -> V_150 . V_153 = V_153 ;
V_16 -> V_150 . V_155 = V_155 ;
V_16 -> V_150 . V_152 -= V_16 -> V_161 ;
V_16 -> V_150 . V_153 -= V_16 -> V_158 ;
V_16 -> V_150 . V_155 -= V_16 -> V_159 ;
V_16 -> V_161 = V_152 ;
V_16 -> V_158 = V_153 ;
V_16 -> V_159 = V_155 ;
return ! ! V_16 -> V_160 ;
}
static inline T_1 F_84 ( struct V_15 * V_16 )
{
return F_6 ( V_16 -> V_150 . V_151 ,
V_16 -> V_60 . V_145 * V_16 -> V_60 . V_138 ) ;
}
static inline T_1 F_85 ( struct V_15 * V_16 )
{
return F_6 ( V_16 -> V_60 . V_145 ,
V_16 -> V_150 . V_151 ) ;
}
static inline T_1 F_86 ( struct V_15 * V_16 )
{
struct V_150 * V_150 = & V_16 -> V_150 ;
T_3 V_162 , V_163 ;
T_3 V_164 ;
T_3 V_153 , V_165 ;
T_1 V_166 ;
V_162 = F_87 ( V_16 -> V_16 , & V_165 ) ;
V_163 = V_162 - V_16 -> V_167 ;
V_164 = F_8 ( V_163 * V_16 -> V_60 . V_138 *
V_16 -> V_60 . V_61 , V_168 ) ;
V_153 = V_16 -> V_150 . V_153 + V_164 ;
V_16 -> V_167 = V_162 ;
V_166 = F_8 ( F_16 ( 100 ) * V_153 , V_150 -> V_155 ) ;
V_16 -> V_150 . V_169 = V_166 ;
return F_85 ( V_16 ) - F_20 ( & V_16 -> V_38 , V_166 ) ;
}
static inline T_1 F_88 ( struct V_15 * V_16 )
{
T_1 V_170 , V_61 , V_139 , V_171 ;
T_3 V_172 ;
V_61 = V_16 -> V_60 . V_145 ;
V_139 = V_16 -> V_60 . V_139 ;
V_170 = F_6 ( V_16 -> V_150 . V_151 ,
F_2 ( 100 * V_61 , V_139 ) ) ;
V_172 = V_16 -> V_150 . time - V_16 -> V_160 ;
if ( ( T_2 ) V_172 > V_53 . V_173 * 3 ) {
V_171 = F_2 ( V_53 . V_173 , V_172 ) ;
V_170 = F_1 ( V_170 , V_171 ) ;
} else {
V_171 = F_2 ( 100 * V_16 -> V_150 . V_153 , V_16 -> V_150 . V_155 ) ;
if ( V_171 < F_16 ( 1 ) )
V_170 = 0 ;
}
V_16 -> V_150 . V_169 = V_170 ;
return V_16 -> V_60 . V_139 - F_20 ( & V_16 -> V_38 , V_170 ) ;
}
static inline void F_89 ( struct V_15 * V_16 , int V_60 )
{
int V_104 , V_106 ;
F_24 () ;
F_74 ( V_16 , & V_106 , & V_104 ) ;
V_60 = F_50 ( int , V_60 , V_106 , V_104 ) ;
if ( V_60 == V_16 -> V_60 . V_139 )
return;
F_75 ( V_16 , V_60 ) ;
F_90 ( V_140 , V_141 . V_142 ( V_16 , V_60 ) ) ;
}
static inline void F_91 ( struct V_15 * V_16 )
{
int V_174 , V_175 ;
struct V_150 * V_150 ;
V_174 = V_16 -> V_60 . V_139 ;
V_175 = V_141 . V_176 ( V_16 ) ;
F_89 ( V_16 , V_175 ) ;
V_150 = & V_16 -> V_150 ;
F_92 ( F_6 ( 100 , V_150 -> V_151 ) ,
F_5 ( V_150 -> V_169 ) ,
V_174 ,
V_16 -> V_60 . V_139 ,
V_150 -> V_153 ,
V_150 -> V_152 ,
V_150 -> V_155 ,
F_84 ( V_16 ) ) ;
}
static void F_93 ( struct V_177 * V_79 , T_3 time ,
unsigned long V_178 , unsigned long V_66 )
{
struct V_15 * V_16 = F_94 ( V_79 , struct V_15 , V_179 ) ;
T_3 V_180 = time - V_16 -> V_150 . time ;
if ( ( T_2 ) V_180 >= V_53 . V_173 ) {
bool V_181 = F_80 ( V_16 , time ) ;
if ( V_181 ) {
F_79 ( V_16 ) ;
if ( ! V_18 )
F_91 ( V_16 ) ;
}
}
}
static int F_95 ( unsigned int V_182 )
{
struct V_15 * V_16 ;
if ( ! V_19 [ V_182 ] )
V_19 [ V_182 ] = F_96 ( sizeof( struct V_15 ) ,
V_183 ) ;
if ( ! V_19 [ V_182 ] )
return - V_184 ;
V_16 = V_19 [ V_182 ] ;
V_16 -> V_16 = V_182 ;
if ( V_18 ) {
F_57 ( V_16 ) ;
V_53 . V_185 = 50 ;
V_53 . V_173 = 50 * V_186 ;
}
F_78 ( V_16 ) ;
F_21 ( V_16 ) ;
F_12 ( L_10 , V_182 ) ;
return 0 ;
}
static unsigned int F_97 ( unsigned int V_187 )
{
struct V_15 * V_16 = V_19 [ V_187 ] ;
return V_16 ? F_84 ( V_16 ) : 0 ;
}
static void F_98 ( unsigned int V_187 )
{
struct V_15 * V_16 = V_19 [ V_187 ] ;
if ( V_16 -> V_188 )
return;
V_16 -> V_150 . time = 0 ;
F_99 ( V_187 , & V_16 -> V_179 ,
F_93 ) ;
V_16 -> V_188 = true ;
}
static void F_100 ( unsigned int V_16 )
{
struct V_15 * V_189 = V_19 [ V_16 ] ;
if ( ! V_189 -> V_188 )
return;
F_101 ( V_16 ) ;
V_189 -> V_188 = false ;
F_102 () ;
}
static void F_103 ( struct V_190 * V_32 )
{
V_32 -> V_76 = 0 ;
V_32 -> V_33 = 0 ;
V_32 -> V_75 = 100 ;
V_32 -> V_104 = F_16 ( 1 ) ;
V_32 -> V_74 = 100 ;
V_32 -> V_106 = F_16 ( 1 ) ;
V_32 -> V_102 = 100 ;
V_32 -> V_101 = 100 ;
V_32 -> V_103 = 0 ;
V_32 -> V_105 = 0 ;
}
static int F_104 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
if ( ! V_14 -> V_34 . V_35 )
return - V_191 ;
F_12 ( L_11 ,
V_14 -> V_34 . V_35 , V_14 -> V_66 ) ;
V_16 = V_19 [ 0 ] ;
if ( V_16 -> V_60 . V_145 > V_16 -> V_60 . V_61 &&
V_14 -> V_66 < V_14 -> V_34 . V_35 &&
V_14 -> V_66 > V_16 -> V_60 . V_61 * V_16 -> V_60 . V_138 ) {
F_12 ( L_12 ) ;
V_14 -> V_66 = V_14 -> V_34 . V_35 ;
}
if ( V_14 -> V_14 == V_192 ) {
V_32 = & V_193 ;
if ( V_14 -> V_66 >= V_14 -> V_34 . V_35 ) {
F_12 ( L_13 ) ;
F_103 ( V_32 ) ;
goto V_194;
}
} else {
F_12 ( L_14 ) ;
V_32 = & V_195 ;
}
V_32 -> V_103 = ( V_14 -> V_64 * 100 ) / V_14 -> V_34 . V_35 ;
V_32 -> V_103 = F_50 ( int , V_32 -> V_103 , 0 , 100 ) ;
V_32 -> V_102 = F_105 ( V_14 -> V_66 * 100 ,
V_14 -> V_34 . V_35 ) ;
V_32 -> V_102 = F_50 ( int , V_32 -> V_102 , 0 , 100 ) ;
V_32 -> V_74 = V_66 ( V_32 -> V_103 ,
V_32 -> V_105 ) ;
V_32 -> V_74 = V_64 ( V_32 -> V_102 ,
V_32 -> V_74 ) ;
V_32 -> V_75 = V_64 ( V_32 -> V_102 ,
V_32 -> V_101 ) ;
V_32 -> V_75 = V_66 ( V_32 -> V_103 ,
V_32 -> V_75 ) ;
V_32 -> V_74 = V_64 ( V_32 -> V_75 , V_32 -> V_74 ) ;
V_32 -> V_106 = F_2 ( V_32 -> V_74 , 100 ) ;
V_32 -> V_104 = F_2 ( V_32 -> V_75 , 100 ) ;
V_32 -> V_104 = F_106 ( V_32 -> V_104 , V_4 ) ;
V_194:
F_98 ( V_14 -> V_16 ) ;
F_35 ( V_14 ) ;
return 0 ;
}
static int F_107 ( struct V_13 * V_14 )
{
F_108 ( V_14 ) ;
if ( V_14 -> V_14 != V_196 &&
V_14 -> V_14 != V_192 )
return - V_99 ;
return 0 ;
}
static void F_109 ( struct V_13 * V_14 )
{
int V_187 = V_14 -> V_16 ;
struct V_15 * V_16 = V_19 [ V_187 ] ;
F_12 ( L_15 , V_187 ) ;
F_100 ( V_187 ) ;
if ( V_18 )
return;
F_77 ( V_16 ) ;
}
static int F_110 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_108 ;
V_108 = F_95 ( V_14 -> V_16 ) ;
if ( V_108 )
return V_108 ;
V_16 = V_19 [ V_14 -> V_16 ] ;
if ( V_32 -> V_74 == 100 && V_32 -> V_75 == 100 )
V_14 -> V_14 = V_192 ;
else
V_14 -> V_14 = V_196 ;
V_14 -> V_64 = V_16 -> V_60 . V_94 * V_16 -> V_60 . V_138 ;
V_14 -> V_66 = V_16 -> V_60 . V_62 * V_16 -> V_60 . V_138 ;
V_14 -> V_34 . V_197 = V_16 -> V_60 . V_94 * V_16 -> V_60 . V_138 ;
F_24 () ;
V_14 -> V_34 . V_35 = V_32 -> V_33 ?
V_16 -> V_60 . V_61 : V_16 -> V_60 . V_62 ;
V_14 -> V_34 . V_35 *= V_16 -> V_60 . V_138 ;
F_10 ( V_14 ) ;
V_14 -> V_34 . V_198 = V_199 ;
F_111 ( V_14 -> V_16 , V_14 -> V_77 ) ;
return 0 ;
}
static int F_112 ( struct V_13 * V_14 )
{
F_14 ( V_14 ) ;
return 0 ;
}
static int F_113 ( void )
{
if ( ! V_141 . V_144 () ||
! V_141 . V_143 () ||
! V_141 . V_147 () )
return - V_191 ;
return 0 ;
}
static void F_114 ( struct V_200 * V_14 )
{
V_53 . V_185 = V_14 -> V_185 ;
V_53 . V_173 = V_53 . V_185 * V_186 ;
V_53 . V_54 = V_14 -> V_54 ;
V_53 . V_56 = V_14 -> V_56 ;
V_53 . V_55 = V_14 -> V_55 ;
V_53 . V_41 = V_14 -> V_41 ;
V_53 . V_39 = V_14 -> V_39 ;
}
static void F_115 ( struct V_141 * V_201 )
{
V_141 . V_144 = V_201 -> V_144 ;
V_141 . V_146 = V_201 -> V_146 ;
V_141 . V_143 = V_201 -> V_143 ;
V_141 . V_147 = V_201 -> V_147 ;
V_141 . V_148 = V_201 -> V_148 ;
V_141 . V_142 = V_201 -> V_142 ;
V_141 . V_149 = V_201 -> V_149 ;
V_141 . V_176 = V_201 -> V_176 ;
}
static bool F_116 ( void )
{
int V_17 ;
F_117 (i) {
T_8 V_202 ;
union V_203 * V_204 ;
struct V_205 V_206 = { V_207 , NULL } ;
struct V_208 * V_209 = F_118 ( V_210 , V_17 ) ;
if ( ! V_209 )
continue;
V_202 = F_119 ( V_209 -> V_211 , L_16 , NULL , & V_206 ) ;
if ( F_120 ( V_202 ) )
continue;
V_204 = V_206 . V_212 ;
if ( V_204 && V_204 -> type == V_213 ) {
F_121 ( V_204 ) ;
return false ;
}
F_121 ( V_204 ) ;
}
return true ;
}
static bool F_122 ( void )
{
int V_17 ;
F_117 (i) {
struct V_208 * V_209 = F_118 ( V_210 , V_17 ) ;
if ( ! V_209 )
continue;
if ( F_123 ( V_209 -> V_211 , L_17 ) )
return true ;
}
return false ;
}
static bool F_124 ( void )
{
struct V_214 V_215 ;
struct V_216 * V_217 ;
const struct V_218 * V_219 ;
T_3 V_220 ;
V_219 = F_125 ( V_221 ) ;
if ( V_219 ) {
F_25 ( V_222 , V_220 ) ;
if ( V_220 & ( 1 << 8 ) )
return true ;
}
if ( V_223 ||
F_120 ( F_126 ( V_224 , 0 , & V_215 ) ) )
return false ;
for ( V_217 = V_225 ; V_217 -> V_226 ; V_217 ++ ) {
if ( ! strncmp ( V_215 . V_227 , V_217 -> V_227 , V_228 ) &&
! strncmp ( V_215 . V_229 , V_217 -> V_229 ,
V_230 ) )
switch ( V_217 -> V_231 ) {
case V_232 :
return F_116 () ;
case V_233 :
return F_122 () &&
( ! V_234 ) ;
}
}
return false ;
}
static inline bool F_124 ( void ) { return false ; }
static inline bool F_122 ( void ) { return false ; }
static int T_4 F_127 ( void )
{
int V_16 , V_108 = 0 ;
const struct V_218 * V_219 ;
struct V_235 * V_236 ;
if ( V_237 )
return - V_191 ;
if ( F_125 ( V_238 ) && ! V_239 ) {
F_115 ( & V_240 . V_201 ) ;
V_18 ++ ;
goto V_241;
}
V_219 = F_125 ( V_242 ) ;
if ( ! V_219 )
return - V_191 ;
V_236 = (struct V_235 * ) V_219 -> V_243 ;
F_114 ( & V_236 -> V_244 ) ;
F_115 ( & V_236 -> V_201 ) ;
if ( F_113 () )
return - V_191 ;
V_241:
if ( F_124 () )
return - V_191 ;
F_128 ( L_18 ) ;
V_19 = F_129 ( sizeof( void * ) * F_130 () ) ;
if ( ! V_19 )
return - V_184 ;
if ( ! V_18 && V_245 )
goto V_194;
V_108 = F_131 ( & V_246 ) ;
if ( V_108 )
goto V_194;
F_41 () ;
F_53 () ;
if ( V_18 )
F_128 ( L_19 ) ;
return V_108 ;
V_194:
F_37 () ;
F_23 (cpu) {
if ( V_19 [ V_16 ] ) {
F_100 ( V_16 ) ;
F_121 ( V_19 [ V_16 ] ) ;
}
}
F_38 () ;
F_132 ( V_19 ) ;
return - V_191 ;
}
static int T_4 F_133 ( char * V_247 )
{
if ( ! V_247 )
return - V_99 ;
if ( ! strcmp ( V_247 , L_20 ) )
V_237 = 1 ;
if ( ! strcmp ( V_247 , L_21 ) ) {
F_128 ( L_22 ) ;
V_239 = 1 ;
}
if ( ! strcmp ( V_247 , L_23 ) )
V_234 = 1 ;
if ( ! strcmp ( V_247 , L_24 ) )
V_245 = 1 ;
#ifdef F_134
if ( ! strcmp ( V_247 , L_25 ) )
V_12 = true ;
#endif
return 0 ;
}
