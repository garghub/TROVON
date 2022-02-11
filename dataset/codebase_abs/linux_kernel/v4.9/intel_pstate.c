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
F_27 (cpu, cpumask) {
F_28 ( V_16 , V_72 , & V_71 ) ;
V_65 = F_29 ( V_71 ) ;
V_67 = F_30 ( V_71 ) ;
V_68 = V_67 - V_65 ;
F_28 ( V_16 , V_73 , & V_70 ) ;
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
if ( F_58 ( V_112 ) )
F_34 ( V_15 -> V_16 , V_113 , 0x00 ) ;
F_34 ( V_15 -> V_16 , V_114 , 0x1 ) ;
}
static int F_59 ( void )
{
T_3 V_70 ;
F_25 ( V_115 , V_70 ) ;
return ( V_70 >> 8 ) & 0x7F ;
}
static int F_60 ( void )
{
T_3 V_70 ;
F_25 ( V_115 , V_70 ) ;
return ( V_70 >> 16 ) & 0x7F ;
}
static int F_61 ( void )
{
T_3 V_70 ;
F_25 ( V_116 , V_70 ) ;
return V_70 & 0x7F ;
}
static T_3 F_62 ( struct V_15 * V_15 , int V_60 )
{
T_3 V_80 ;
T_1 V_117 ;
V_27 V_118 ;
V_80 = ( T_3 ) V_60 << 8 ;
if ( V_32 -> V_76 && ! V_32 -> V_33 )
V_80 |= ( T_3 ) 1 << 32 ;
V_117 = V_15 -> V_118 . V_64 + F_1 (
F_16 ( V_60 - V_15 -> V_60 . V_94 ) ,
V_15 -> V_118 . V_119 ) ;
V_117 = F_50 ( T_1 , V_117 , V_15 -> V_118 . V_64 , V_15 -> V_118 . V_66 ) ;
V_118 = F_4 ( V_117 ) ;
if ( V_60 > V_15 -> V_60 . V_61 )
V_118 = V_15 -> V_118 . V_120 ;
return V_80 | V_118 ;
}
static int F_63 ( void )
{
T_3 V_70 ;
int V_17 ;
static int V_121 [] = {
83300 , 100000 , 133300 , 116700 , 80000 } ;
F_25 ( V_122 , V_70 ) ;
V_17 = V_70 & 0x7 ;
F_64 ( V_17 > 4 ) ;
return V_121 [ V_17 ] ;
}
static int F_65 ( void )
{
T_3 V_70 ;
int V_17 ;
static int V_123 [] = {
83300 , 100000 , 133300 , 116700 , 80000 ,
93300 , 90000 , 88900 , 87500 } ;
F_25 ( V_122 , V_70 ) ;
V_17 = V_70 & 0xF ;
F_64 ( V_17 > 8 ) ;
return V_123 [ V_17 ] ;
}
static void F_66 ( struct V_15 * V_15 )
{
T_3 V_70 ;
F_25 ( V_124 , V_70 ) ;
V_15 -> V_118 . V_64 = F_16 ( ( V_70 >> 8 ) & 0x7f ) ;
V_15 -> V_118 . V_66 = F_16 ( ( V_70 >> 16 ) & 0x7f ) ;
V_15 -> V_118 . V_119 = F_2 (
V_15 -> V_118 . V_66 - V_15 -> V_118 . V_64 ,
F_16 ( V_15 -> V_60 . V_61 -
V_15 -> V_60 . V_94 ) ) ;
F_25 ( V_125 , V_70 ) ;
V_15 -> V_118 . V_120 = V_70 & 0x7f ;
}
static int F_67 ( void )
{
T_3 V_70 ;
F_25 ( V_126 , V_70 ) ;
return ( V_70 >> 40 ) & 0xFF ;
}
static int F_68 ( void )
{
T_3 V_70 ;
F_25 ( V_126 , V_70 ) ;
return ( V_70 >> 8 ) & 0xFF ;
}
static int F_69 ( void )
{
T_3 V_127 ;
T_3 V_128 ;
int V_61 ;
int V_24 ;
F_25 ( V_126 , V_128 ) ;
V_61 = ( V_128 >> 8 ) & 0xFF ;
V_24 = F_70 ( V_129 , & V_127 ) ;
if ( ! V_24 ) {
if ( V_128 & 0x600000000 ) {
T_3 V_130 ;
T_3 V_131 ;
int V_132 ;
V_24 = F_70 ( V_133 , & V_130 ) ;
if ( V_24 )
goto V_134;
V_132 = V_135 + ( V_130 & 0x3 ) ;
V_24 = F_70 ( V_132 , & V_131 ) ;
if ( V_24 )
goto V_134;
if ( V_130 )
V_131 >>= 16 ;
V_131 &= 0xff ;
if ( V_131 - 1 == V_127 ) {
V_61 = V_127 ;
F_12 ( L_9 , V_61 ) ;
} else {
goto V_134;
}
}
}
V_134:
return V_61 ;
}
static int F_71 ( void )
{
T_3 V_70 ;
int V_136 , V_6 ;
F_25 ( V_137 , V_70 ) ;
V_136 = F_69 () ;
V_6 = ( V_70 ) & 255 ;
if ( V_6 <= V_136 )
V_6 = V_136 ;
return V_6 ;
}
static inline int F_72 ( void )
{
return 100000 ;
}
static T_3 F_73 ( struct V_15 * V_15 , int V_60 )
{
T_3 V_80 ;
V_80 = ( T_3 ) V_60 << 8 ;
if ( V_32 -> V_76 && ! V_32 -> V_33 )
V_80 |= ( T_3 ) 1 << 32 ;
return V_80 ;
}
static int F_74 ( void )
{
T_3 V_70 ;
int V_136 , V_6 ;
F_25 ( V_137 , V_70 ) ;
V_136 = F_69 () ;
V_6 = ( ( ( V_70 ) >> 8 ) & 0xFF ) ;
if ( V_6 <= V_136 )
V_6 = V_136 ;
return V_6 ;
}
static void F_75 ( struct V_15 * V_16 , int * V_64 , int * V_66 )
{
int V_104 = V_16 -> V_60 . V_62 ;
int V_138 ;
int V_106 ;
if ( V_32 -> V_76 || V_32 -> V_33 )
V_104 = V_16 -> V_60 . V_61 ;
V_138 = F_5 ( V_104 * V_32 -> V_104 ) ;
* V_66 = F_50 ( int , V_138 ,
V_16 -> V_60 . V_94 , V_16 -> V_60 . V_62 ) ;
V_106 = F_5 ( V_104 * V_32 -> V_106 ) ;
* V_64 = F_50 ( int , V_106 , V_16 -> V_60 . V_94 , V_104 ) ;
}
static void F_76 ( struct V_15 * V_16 , int V_60 )
{
F_77 ( V_60 * V_16 -> V_60 . V_139 , V_16 -> V_16 ) ;
V_16 -> V_60 . V_140 = V_60 ;
F_34 ( V_16 -> V_16 , V_141 ,
V_142 . V_143 ( V_16 , V_60 ) ) ;
}
static void F_78 ( struct V_15 * V_16 )
{
F_76 ( V_16 , V_16 -> V_60 . V_94 ) ;
}
static void F_79 ( struct V_15 * V_16 )
{
int V_94 , V_61 ;
F_24 () ;
F_75 ( V_16 , & V_94 , & V_61 ) ;
F_76 ( V_16 , V_61 ) ;
}
static void F_80 ( struct V_15 * V_16 )
{
V_16 -> V_60 . V_94 = V_142 . V_144 () ;
V_16 -> V_60 . V_61 = V_142 . V_145 () ;
V_16 -> V_60 . V_146 = V_142 . V_147 () ;
V_16 -> V_60 . V_62 = V_142 . V_148 () ;
V_16 -> V_60 . V_139 = V_142 . V_149 () ;
if ( V_142 . V_150 )
V_142 . V_150 ( V_16 ) ;
F_78 ( V_16 ) ;
}
static inline void F_81 ( struct V_15 * V_16 )
{
struct V_151 * V_151 = & V_16 -> V_151 ;
V_151 -> V_152 = F_7 ( V_151 -> V_153 , V_151 -> V_154 ) ;
}
static inline bool F_82 ( struct V_15 * V_16 , T_3 time )
{
T_3 V_153 , V_154 ;
unsigned long V_155 ;
T_3 V_156 ;
F_83 ( V_155 ) ;
F_25 ( V_157 , V_153 ) ;
F_25 ( V_158 , V_154 ) ;
V_156 = F_84 () ;
if ( V_16 -> V_159 == V_154 || V_16 -> V_160 == V_156 ) {
F_85 ( V_155 ) ;
return false ;
}
F_85 ( V_155 ) ;
V_16 -> V_161 = V_16 -> V_151 . time ;
V_16 -> V_151 . time = time ;
V_16 -> V_151 . V_153 = V_153 ;
V_16 -> V_151 . V_154 = V_154 ;
V_16 -> V_151 . V_156 = V_156 ;
V_16 -> V_151 . V_153 -= V_16 -> V_162 ;
V_16 -> V_151 . V_154 -= V_16 -> V_159 ;
V_16 -> V_151 . V_156 -= V_16 -> V_160 ;
V_16 -> V_162 = V_153 ;
V_16 -> V_159 = V_154 ;
V_16 -> V_160 = V_156 ;
return ! ! V_16 -> V_161 ;
}
static inline T_1 F_86 ( struct V_15 * V_16 )
{
return F_6 ( V_16 -> V_151 . V_152 ,
V_16 -> V_60 . V_146 * V_16 -> V_60 . V_139 ) ;
}
static inline T_1 F_87 ( struct V_15 * V_16 )
{
return F_6 ( V_16 -> V_60 . V_146 ,
V_16 -> V_151 . V_152 ) ;
}
static inline T_1 F_88 ( struct V_15 * V_16 )
{
struct V_151 * V_151 = & V_16 -> V_151 ;
T_1 V_163 , V_164 ;
int V_165 , V_166 ;
V_163 = F_2 ( V_151 -> V_154 , V_151 -> V_156 ) ;
V_164 = V_16 -> V_167 ;
V_16 -> V_167 >>= 1 ;
if ( V_163 < V_164 )
V_163 = V_164 ;
V_151 -> V_168 = V_163 * 100 ;
V_165 = V_32 -> V_76 || V_32 -> V_33 ?
V_16 -> V_60 . V_61 : V_16 -> V_60 . V_62 ;
V_165 += V_165 >> 2 ;
V_165 = F_1 ( V_165 , V_163 ) ;
if ( V_165 < V_16 -> V_60 . V_94 )
V_165 = V_16 -> V_60 . V_94 ;
V_166 = F_87 ( V_16 ) ;
if ( V_166 > V_165 )
V_165 += ( V_166 - V_165 ) >> 1 ;
return V_165 ;
}
static inline T_1 F_89 ( struct V_15 * V_16 )
{
T_1 V_169 , V_61 , V_140 , V_170 ;
T_3 V_171 ;
V_61 = V_16 -> V_60 . V_146 ;
V_140 = V_16 -> V_60 . V_140 ;
V_169 = F_6 ( V_16 -> V_151 . V_152 ,
F_2 ( 100 * V_61 , V_140 ) ) ;
V_171 = V_16 -> V_151 . time - V_16 -> V_161 ;
if ( ( T_2 ) V_171 > V_53 . V_172 * 3 ) {
V_170 = F_2 ( V_53 . V_172 , V_171 ) ;
V_169 = F_1 ( V_169 , V_170 ) ;
} else {
V_170 = F_2 ( 100 * V_16 -> V_151 . V_154 , V_16 -> V_151 . V_156 ) ;
if ( V_170 < F_16 ( 1 ) )
V_169 = 0 ;
}
V_16 -> V_151 . V_168 = V_169 ;
return V_16 -> V_60 . V_140 - F_20 ( & V_16 -> V_38 , V_169 ) ;
}
static inline void F_90 ( struct V_15 * V_16 , int V_60 )
{
int V_104 , V_106 ;
F_24 () ;
F_75 ( V_16 , & V_106 , & V_104 ) ;
V_60 = F_50 ( int , V_60 , V_106 , V_104 ) ;
F_77 ( V_60 * V_16 -> V_60 . V_139 , V_16 -> V_16 ) ;
if ( V_60 == V_16 -> V_60 . V_140 )
return;
V_16 -> V_60 . V_140 = V_60 ;
F_91 ( V_141 , V_142 . V_143 ( V_16 , V_60 ) ) ;
}
static inline void F_92 ( struct V_15 * V_16 )
{
int V_173 , V_174 ;
struct V_151 * V_151 ;
V_173 = V_16 -> V_60 . V_140 ;
V_174 = V_16 -> V_14 == V_175 ?
V_16 -> V_60 . V_62 : V_142 . V_176 ( V_16 ) ;
F_90 ( V_16 , V_174 ) ;
V_151 = & V_16 -> V_151 ;
F_93 ( F_6 ( 100 , V_151 -> V_152 ) ,
F_5 ( V_151 -> V_168 ) ,
V_173 ,
V_16 -> V_60 . V_140 ,
V_151 -> V_154 ,
V_151 -> V_153 ,
V_151 -> V_156 ,
F_86 ( V_16 ) ,
F_5 ( V_16 -> V_167 * 100 ) ) ;
}
static void F_94 ( struct V_177 * V_79 , T_3 time ,
unsigned int V_155 )
{
struct V_15 * V_16 = F_95 ( V_79 , struct V_15 , V_178 ) ;
T_3 V_179 ;
if ( V_53 . V_180 ) {
if ( V_155 & V_181 ) {
V_16 -> V_167 = F_16 ( 1 ) ;
} else if ( V_16 -> V_167 ) {
V_179 = time - V_16 -> V_182 ;
if ( V_179 > V_183 )
V_16 -> V_167 = 0 ;
}
V_16 -> V_182 = time ;
}
V_179 = time - V_16 -> V_151 . time ;
if ( ( T_2 ) V_179 >= V_53 . V_172 ) {
bool V_184 = F_82 ( V_16 , time ) ;
if ( V_184 ) {
F_81 ( V_16 ) ;
if ( ! V_18 )
F_92 ( V_16 ) ;
}
}
}
static int F_96 ( unsigned int V_185 )
{
struct V_15 * V_16 ;
if ( ! V_19 [ V_185 ] )
V_19 [ V_185 ] = F_97 ( sizeof( struct V_15 ) ,
V_186 ) ;
if ( ! V_19 [ V_185 ] )
return - V_187 ;
V_16 = V_19 [ V_185 ] ;
V_16 -> V_16 = V_185 ;
if ( V_18 ) {
F_57 ( V_16 ) ;
V_53 . V_188 = 50 ;
V_53 . V_172 = 50 * V_189 ;
}
F_80 ( V_16 ) ;
F_21 ( V_16 ) ;
F_12 ( L_10 , V_185 ) ;
return 0 ;
}
static unsigned int F_98 ( unsigned int V_190 )
{
struct V_15 * V_16 = V_19 [ V_190 ] ;
return V_16 ? F_86 ( V_16 ) : 0 ;
}
static void F_99 ( unsigned int V_190 )
{
struct V_15 * V_16 = V_19 [ V_190 ] ;
if ( V_16 -> V_191 )
return;
V_16 -> V_151 . time = 0 ;
F_100 ( V_190 , & V_16 -> V_178 ,
F_94 ) ;
V_16 -> V_191 = true ;
}
static void F_101 ( unsigned int V_16 )
{
struct V_15 * V_192 = V_19 [ V_16 ] ;
if ( ! V_192 -> V_191 )
return;
F_102 ( V_16 ) ;
V_192 -> V_191 = false ;
F_103 () ;
}
static void F_104 ( struct V_193 * V_32 )
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
static int F_105 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
if ( ! V_14 -> V_34 . V_35 )
return - V_194 ;
F_12 ( L_11 ,
V_14 -> V_34 . V_35 , V_14 -> V_66 ) ;
V_16 = V_19 [ V_14 -> V_16 ] ;
V_16 -> V_14 = V_14 -> V_14 ;
if ( V_16 -> V_60 . V_146 > V_16 -> V_60 . V_61 &&
V_14 -> V_66 < V_14 -> V_34 . V_35 &&
V_14 -> V_66 > V_16 -> V_60 . V_61 * V_16 -> V_60 . V_139 ) {
F_12 ( L_12 ) ;
V_14 -> V_66 = V_14 -> V_34 . V_35 ;
}
if ( V_16 -> V_14 == V_175 ) {
V_32 = & V_195 ;
if ( V_14 -> V_66 >= V_14 -> V_34 . V_35 ) {
F_12 ( L_13 ) ;
F_104 ( V_32 ) ;
goto V_196;
}
} else {
F_12 ( L_14 ) ;
V_32 = & V_197 ;
}
V_32 -> V_103 = ( V_14 -> V_64 * 100 ) / V_14 -> V_34 . V_35 ;
V_32 -> V_103 = F_50 ( int , V_32 -> V_103 , 0 , 100 ) ;
V_32 -> V_102 = F_106 ( V_14 -> V_66 * 100 ,
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
V_32 -> V_104 = F_107 ( V_32 -> V_104 , V_4 ) ;
V_196:
if ( V_16 -> V_14 == V_175 ) {
F_101 ( V_14 -> V_16 ) ;
F_79 ( V_16 ) ;
}
F_99 ( V_14 -> V_16 ) ;
F_35 ( V_14 ) ;
return 0 ;
}
static int F_108 ( struct V_13 * V_14 )
{
F_109 ( V_14 ) ;
if ( V_14 -> V_14 != V_198 &&
V_14 -> V_14 != V_175 )
return - V_99 ;
return 0 ;
}
static void F_110 ( struct V_13 * V_14 )
{
int V_190 = V_14 -> V_16 ;
struct V_15 * V_16 = V_19 [ V_190 ] ;
F_12 ( L_15 , V_190 ) ;
F_101 ( V_190 ) ;
if ( V_18 )
return;
F_78 ( V_16 ) ;
}
static int F_111 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
int V_108 ;
V_108 = F_96 ( V_14 -> V_16 ) ;
if ( V_108 )
return V_108 ;
V_16 = V_19 [ V_14 -> V_16 ] ;
if ( V_32 -> V_74 == 100 && V_32 -> V_75 == 100 )
V_14 -> V_14 = V_175 ;
else
V_14 -> V_14 = V_198 ;
V_14 -> V_64 = V_16 -> V_60 . V_94 * V_16 -> V_60 . V_139 ;
V_14 -> V_66 = V_16 -> V_60 . V_62 * V_16 -> V_60 . V_139 ;
V_14 -> V_34 . V_199 = V_16 -> V_60 . V_94 * V_16 -> V_60 . V_139 ;
F_24 () ;
V_14 -> V_34 . V_35 = V_32 -> V_33 ?
V_16 -> V_60 . V_61 : V_16 -> V_60 . V_62 ;
V_14 -> V_34 . V_35 *= V_16 -> V_60 . V_139 ;
F_10 ( V_14 ) ;
V_14 -> V_34 . V_200 = V_201 ;
F_112 ( V_14 -> V_16 , V_14 -> V_77 ) ;
return 0 ;
}
static int F_113 ( struct V_13 * V_14 )
{
F_14 ( V_14 ) ;
return 0 ;
}
static int T_4 F_114 ( void )
{
if ( ! V_142 . V_145 () ||
! V_142 . V_144 () ||
! V_142 . V_148 () )
return - V_194 ;
return 0 ;
}
static void T_4 F_115 ( struct V_202 * V_14 )
{
V_53 . V_188 = V_14 -> V_188 ;
V_53 . V_172 = V_53 . V_188 * V_189 ;
V_53 . V_54 = V_14 -> V_54 ;
V_53 . V_56 = V_14 -> V_56 ;
V_53 . V_55 = V_14 -> V_55 ;
V_53 . V_41 = V_14 -> V_41 ;
V_53 . V_39 = V_14 -> V_39 ;
}
static void T_4 F_116 ( struct V_142 * V_203 )
{
V_142 . V_145 = V_203 -> V_145 ;
V_142 . V_147 = V_203 -> V_147 ;
V_142 . V_144 = V_203 -> V_144 ;
V_142 . V_148 = V_203 -> V_148 ;
V_142 . V_149 = V_203 -> V_149 ;
V_142 . V_143 = V_203 -> V_143 ;
V_142 . V_150 = V_203 -> V_150 ;
V_142 . V_176 = V_203 -> V_176 ;
}
static bool T_4 F_117 ( void )
{
int V_17 ;
F_118 (i) {
T_8 V_204 ;
union V_205 * V_206 ;
struct V_207 V_208 = { V_209 , NULL } ;
struct V_210 * V_211 = F_119 ( V_212 , V_17 ) ;
if ( ! V_211 )
continue;
V_204 = F_120 ( V_211 -> V_213 , L_16 , NULL , & V_208 ) ;
if ( F_121 ( V_204 ) )
continue;
V_206 = V_208 . V_214 ;
if ( V_206 && V_206 -> type == V_215 ) {
F_122 ( V_206 ) ;
return false ;
}
F_122 ( V_206 ) ;
}
return true ;
}
static bool T_4 F_123 ( void )
{
int V_17 ;
F_118 (i) {
struct V_210 * V_211 = F_119 ( V_212 , V_17 ) ;
if ( ! V_211 )
continue;
if ( F_124 ( V_211 -> V_213 , L_17 ) )
return true ;
}
return false ;
}
static bool T_4 F_125 ( void )
{
struct V_216 V_217 ;
struct V_218 * V_219 ;
const struct V_220 * V_221 ;
T_3 V_222 ;
V_221 = F_126 ( V_223 ) ;
if ( V_221 ) {
F_25 ( V_224 , V_222 ) ;
if ( V_222 & ( 1 << 8 ) )
return true ;
}
if ( V_225 ||
F_121 ( F_127 ( V_226 , 0 , & V_217 ) ) )
return false ;
for ( V_219 = V_227 ; V_219 -> V_228 ; V_219 ++ ) {
if ( ! strncmp ( V_217 . V_229 , V_219 -> V_229 , V_230 ) &&
! strncmp ( V_217 . V_231 , V_219 -> V_231 ,
V_232 ) )
switch ( V_219 -> V_233 ) {
case V_234 :
return F_117 () ;
case V_235 :
return F_123 () &&
( ! V_236 ) ;
}
}
return false ;
}
static inline bool F_125 ( void ) { return false ; }
static inline bool F_123 ( void ) { return false ; }
static int T_4 F_128 ( void )
{
int V_16 , V_108 = 0 ;
const struct V_220 * V_221 ;
struct V_237 * V_238 ;
if ( V_239 )
return - V_194 ;
if ( F_126 ( V_240 ) && ! V_241 ) {
F_116 ( & V_242 . V_203 ) ;
V_18 ++ ;
goto V_243;
}
V_221 = F_126 ( V_244 ) ;
if ( ! V_221 )
return - V_194 ;
V_238 = (struct V_237 * ) V_221 -> V_245 ;
F_115 ( & V_238 -> V_246 ) ;
F_116 ( & V_238 -> V_203 ) ;
if ( F_114 () )
return - V_194 ;
V_243:
if ( F_125 () )
return - V_194 ;
F_129 ( L_18 ) ;
V_19 = F_130 ( sizeof( void * ) * F_131 () ) ;
if ( ! V_19 )
return - V_187 ;
if ( ! V_18 && V_247 )
goto V_196;
V_108 = F_132 ( & V_248 ) ;
if ( V_108 )
goto V_196;
F_41 () ;
F_53 () ;
if ( V_18 )
F_129 ( L_19 ) ;
return V_108 ;
V_196:
F_37 () ;
F_23 (cpu) {
if ( V_19 [ V_16 ] ) {
F_101 ( V_16 ) ;
F_122 ( V_19 [ V_16 ] ) ;
}
}
F_38 () ;
F_133 ( V_19 ) ;
return - V_194 ;
}
static int T_4 F_134 ( char * V_249 )
{
if ( ! V_249 )
return - V_99 ;
if ( ! strcmp ( V_249 , L_20 ) )
V_239 = 1 ;
if ( ! strcmp ( V_249 , L_21 ) ) {
F_129 ( L_22 ) ;
V_241 = 1 ;
}
if ( ! strcmp ( V_249 , L_23 ) )
V_236 = 1 ;
if ( ! strcmp ( V_249 , L_24 ) )
V_247 = 1 ;
#ifdef F_135
if ( ! strcmp ( V_249 , L_25 ) )
V_12 = true ;
#endif
return 0 ;
}
