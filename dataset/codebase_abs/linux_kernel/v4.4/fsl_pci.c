static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ! F_2 ( V_2 ) )
return;
F_3 ( V_2 , V_4 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_5 )
return;
V_2 -> V_6 = V_7 << 8 ;
V_8 = 1 ;
return;
}
static int F_4 ( struct V_9 * V_10 )
{
T_2 V_11 = 0 ;
if ( V_10 -> V_12 & V_13 ) {
if ( V_10 -> V_14 -> V_15 == V_16 )
F_5 ( V_10 , V_10 -> V_17 , 0 ,
V_18 , 4 , & V_11 ) ;
else
F_6 ( V_10 , 0 , 0 , V_18 , & V_11 ) ;
if ( V_11 < V_19 )
return 1 ;
} else {
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
V_11 = ( F_7 ( & V_21 -> V_23 ) & V_24 )
>> V_25 ;
if ( V_11 != V_26 )
return 1 ;
}
return 0 ;
}
static int V_16 ( struct V_27 * V_28 , unsigned int V_29 ,
int V_30 , int V_31 , T_2 * V_11 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
else
V_10 -> V_12 &= ~ V_32 ;
return F_9 ( V_28 , V_29 , V_30 , V_31 , V_11 ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
if ( V_33 ) {
V_10 -> V_34 . V_35 = V_36 ;
F_11 ( & V_37 ) ;
}
}
static inline void F_10 ( struct V_9 * V_10 ) {}
static int F_12 ( struct V_38 * V_2 , T_4 V_39 )
{
if ( ! V_2 -> V_39 || ! F_13 ( V_2 , V_39 ) )
return - V_40 ;
if ( ( F_14 ( V_2 ) ) &&
V_39 >= F_15 ( V_41 ) ) {
F_16 ( V_2 , & V_42 ) ;
F_17 ( V_2 , V_43 ) ;
}
* V_2 -> V_39 = V_39 ;
return 0 ;
}
static int F_18 ( struct V_20 T_3 * V_21 ,
unsigned int V_44 , const struct V_45 * V_46 ,
T_5 V_30 )
{
T_5 V_47 = V_46 -> V_48 - V_30 ;
T_5 V_49 = V_46 -> V_48 ;
T_5 V_50 = F_19 ( V_46 ) ;
T_2 V_51 = 0x80044000 ;
unsigned int V_52 ;
F_20 ( L_1 ,
( T_4 ) V_46 -> V_48 , ( T_4 ) V_50 ) ;
if ( V_46 -> V_51 & V_53 )
V_51 |= 0x10000000 ;
for ( V_52 = 0 ; V_50 > 0 ; V_52 ++ ) {
unsigned int V_54 = F_21 ( T_2 , F_22 ( V_50 ) ,
F_23 ( V_47 | V_49 ) ) ;
if ( V_44 + V_52 >= 5 )
return - 1 ;
F_24 ( & V_21 -> pow [ V_44 + V_52 ] . V_55 , V_47 >> 12 ) ;
F_24 ( & V_21 -> pow [ V_44 + V_52 ] . V_56 , ( T_4 ) V_47 >> 44 ) ;
F_24 ( & V_21 -> pow [ V_44 + V_52 ] . V_57 , V_49 >> 12 ) ;
F_24 ( & V_21 -> pow [ V_44 + V_52 ] . V_58 , V_51 | ( V_54 - 1 ) ) ;
V_47 += ( T_5 ) 1U << V_54 ;
V_49 += ( T_5 ) 1U << V_54 ;
V_50 -= ( T_5 ) 1U << V_54 ;
}
return V_52 ;
}
static bool F_25 ( void )
{
struct V_59 * V_60 ;
V_60 = F_26 ( NULL , L_2 ) ;
if ( ! V_60 ) {
F_27 ( 1 ) ;
return false ;
}
return F_28 ( V_60 , L_3 ) ;
}
static void F_29 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
int V_52 , V_61 , V_62 , V_63 , V_64 = 3 , V_65 = 1 , V_66 = 4 ;
T_4 V_67 , V_68 , V_69 = 0 ;
T_4 V_30 = 0 , V_70 = V_71 ;
T_2 V_72 = 0 , V_73 ;
T_2 V_74 = V_75 | V_76 | V_77 |
V_78 | V_79 ;
const char * V_80 = V_10 -> V_81 -> V_82 ;
const T_4 * V_83 ;
int V_31 ;
bool V_84 ;
V_84 = ! F_25 () ;
if ( F_30 ( V_10 , 0 , 0 , V_85 ) ) {
if ( F_7 ( & V_21 -> V_86 ) >= V_87 ) {
V_64 = 2 ;
V_65 = 0 ;
V_66 = 3 ;
}
}
for( V_52 = 1 ; V_52 < 5 ; V_52 ++ )
F_24 ( & V_21 -> pow [ V_52 ] . V_58 , 0 ) ;
if ( V_84 ) {
for ( V_52 = V_65 ; V_52 < V_66 ; V_52 ++ )
F_24 ( & V_21 -> V_88 [ V_52 ] . V_74 , 0 ) ;
}
for( V_52 = 0 , V_61 = 1 ; V_52 < 3 ; V_52 ++ ) {
if ( ! ( V_10 -> V_89 [ V_52 ] . V_51 & V_90 ) )
continue;
V_70 = F_31 ( V_70 , ( T_4 ) V_10 -> V_89 [ V_52 ] . V_48 ) ;
V_69 = F_32 ( V_69 , ( T_4 ) V_10 -> V_89 [ V_52 ] . V_91 ) ;
V_30 = V_10 -> V_92 [ V_52 ] ;
V_62 = F_18 ( V_21 , V_61 , & V_10 -> V_89 [ V_52 ] , V_30 ) ;
if ( V_62 < 0 || V_61 >= 5 ) {
F_33 ( L_4 , V_52 ) ;
V_10 -> V_89 [ V_52 ] . V_51 |= V_93 ;
} else
V_61 += V_62 ;
}
if ( V_10 -> V_94 . V_51 & V_95 ) {
if ( V_61 >= 5 ) {
F_33 ( L_5 ) ;
} else {
F_20 ( L_6
L_7 ,
( T_4 ) V_10 -> V_94 . V_48 ,
( T_4 ) F_19 ( & V_10 -> V_94 ) ,
( T_4 ) V_10 -> V_96 ) ;
F_24 ( & V_21 -> pow [ V_61 ] . V_55 , ( V_10 -> V_94 . V_48 >> 12 ) ) ;
F_24 ( & V_21 -> pow [ V_61 ] . V_56 , 0 ) ;
F_24 ( & V_21 -> pow [ V_61 ] . V_57 , ( V_10 -> V_96 >> 12 ) ) ;
F_24 ( & V_21 -> pow [ V_61 ] . V_58 , 0x80088000
| ( F_22 ( V_10 -> V_94 . V_91
- V_10 -> V_94 . V_48 + 1 ) - 1 ) ) ;
}
}
V_69 -= V_30 ;
V_70 -= V_30 ;
if ( V_69 == V_70 ) {
F_33 ( L_8 , V_80 ) ;
return;
}
if ( V_70 == 0 ) {
F_33 ( L_9 , V_80 ) ;
return;
}
F_34 ( V_10 , 0 , 0 , V_97 , 0xffffffff ) ;
F_6 ( V_10 , 0 , 0 , V_97 , & V_73 ) ;
V_73 = ~ V_73 + 1 ;
if ( V_69 < ( 0x100000000ull - V_73 ) ||
( V_70 > 0x100000000ull ) )
V_72 = 0x100000000ull - V_73 ;
else
V_72 = ( V_70 - V_73 ) & - V_73 ;
F_34 ( V_10 , 0 , 0 , V_97 , V_72 ) ;
V_70 = F_31 ( V_70 , ( T_4 ) V_72 ) ;
F_35 ( L_10 , V_80 , V_72 ) ;
V_67 = F_36 () ;
F_35 ( L_11 , V_98 , V_67 ) ;
V_83 = F_37 ( V_10 -> V_81 , L_12 , & V_31 ) ;
if ( V_83 && ( V_31 == sizeof( T_4 ) ) ) {
T_4 V_99 = F_38 ( V_83 ) ;
if ( ( V_99 >= V_67 ) && ( V_99 < ( V_67 + V_100 ) ) ) {
F_35 ( L_13 , V_80 ) ;
V_67 += V_100 ;
} else {
F_39 ( L_14
L_15 , V_80 , V_99 ) ;
}
}
V_68 = F_31 ( V_67 , V_70 ) ;
V_63 = F_22 ( V_68 ) ;
if ( F_30 ( V_10 , 0 , 0 , V_85 ) ) {
if ( ( 1ull << V_63 ) != V_67 ) {
V_63 ++ ;
if ( ( 1ull << V_63 ) > V_67 )
F_35 ( L_16
L_17 , V_80 ) ;
}
V_74 |= ( ( V_63 - 1 ) & V_101 ) ;
if ( V_84 ) {
F_24 ( & V_21 -> V_88 [ V_64 ] . V_102 , 0x00000000 ) ;
F_24 ( & V_21 -> V_88 [ V_64 ] . V_103 , 0x00000000 ) ;
F_24 ( & V_21 -> V_88 [ V_64 ] . V_74 , V_74 ) ;
}
V_64 -- ;
V_10 -> V_104 = 0x00000000 ;
V_10 -> V_105 = ( T_5 ) V_68 ;
if ( V_68 != V_67 ) {
V_63 = F_22 ( V_67 ) ;
if ( ( 1ull << V_63 ) != V_67 )
V_63 ++ ;
V_74 = ( V_74 & ~ V_101 ) | ( V_63 - 1 ) ;
if ( V_84 ) {
F_24 ( & V_21 -> V_88 [ V_64 ] . V_102 , 0x00000000 ) ;
F_24 ( & V_21 -> V_88 [ V_64 ] . V_106 ,
V_43 >> 44 ) ;
F_24 ( & V_21 -> V_88 [ V_64 ] . V_103 ,
V_43 >> 12 ) ;
F_24 ( & V_21 -> V_88 [ V_64 ] . V_74 , V_74 ) ;
}
V_107 . V_108 = F_12 ;
F_35 ( L_18 , V_80 ) ;
}
} else {
T_4 V_109 = 0 ;
if ( V_84 ) {
F_24 ( & V_21 -> V_88 [ V_64 ] . V_102 , V_109 >> 12 ) ;
F_24 ( & V_21 -> V_88 [ V_64 ] . V_103 , V_109 >> 12 ) ;
F_24 ( & V_21 -> V_88 [ V_64 ] . V_74 ,
( V_74 | ( V_63 - 1 ) ) ) ;
}
V_64 -- ;
V_109 += 1ull << V_63 ;
V_68 -= 1ull << V_63 ;
if ( V_68 ) {
V_63 = F_22 ( V_68 ) ;
V_74 |= ( V_63 - 1 ) ;
if ( V_84 ) {
F_24 ( & V_21 -> V_88 [ V_64 ] . V_102 ,
V_109 >> 12 ) ;
F_24 ( & V_21 -> V_88 [ V_64 ] . V_103 ,
V_109 >> 12 ) ;
F_24 ( & V_21 -> V_88 [ V_64 ] . V_74 , V_74 ) ;
}
V_64 -- ;
V_109 += 1ull << V_63 ;
}
V_10 -> V_104 = 0x00000000 ;
V_10 -> V_105 = ( T_5 ) V_109 ;
}
if ( V_10 -> V_105 < V_67 ) {
#ifdef F_40
V_33 = 1 ;
#else
F_33 ( L_19
L_20 ,
V_80 ) ;
#endif
if ( V_69 < 0xffffffffull )
F_41 ( L_21
L_22
L_23 ,
V_80 ) ;
F_35 ( L_24 , V_80 ,
( T_4 ) V_10 -> V_105 ) ;
}
}
static void T_6 F_42 ( struct V_9 * V_10 )
{
T_7 V_110 ;
int V_111 ;
F_43 ( V_10 , 0 , 0 , V_112 , & V_110 ) ;
V_110 |= V_113 | V_114 | V_115
| V_116 ;
F_44 ( V_10 , 0 , 0 , V_112 , V_110 ) ;
V_111 = F_30 ( V_10 , 0 , 0 , V_117 ) ;
if ( V_111 ) {
int V_118 = V_111 + V_119 ;
V_110 = V_120 | V_121
| V_122 | V_123 ;
F_44 ( V_10 , 0 , 0 , V_118 , V_110 ) ;
} else {
F_45 ( V_10 , 0 , 0 , V_124 , 0x80 ) ;
}
}
void F_46 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
int V_52 , V_125 = 0 , V_126 ;
if ( V_8 )
V_125 = F_30 ( V_10 , 0 , 0 , V_85 ) ;
V_126 = ! ! ( V_10 -> V_12 & V_32 ) ;
if ( V_28 -> V_127 == V_10 -> V_28 && ( V_125 || V_126 ) ) {
for ( V_52 = 0 ; V_52 < V_128 ; ++ V_52 ) {
struct V_45 * V_46 = V_28 -> V_45 [ V_52 ] ;
struct V_45 * V_129 ;
if ( ! V_46 )
continue;
if ( V_52 == 0 )
V_129 = & V_10 -> V_94 ;
else if ( V_52 < 4 )
V_129 = & V_10 -> V_89 [ V_52 - 1 ] ;
else V_129 = NULL ;
V_46 -> V_48 = V_129 ? V_129 -> V_48 : 0 ;
V_46 -> V_91 = V_129 ? V_129 -> V_91 : 0 ;
V_46 -> V_51 = V_129 ? V_129 -> V_51 : 0 ;
}
}
}
int F_47 ( struct V_130 * V_131 , int V_132 )
{
int V_31 ;
struct V_9 * V_10 ;
struct V_45 V_133 ;
const int * V_134 ;
T_1 V_3 , V_135 ;
struct V_59 * V_2 ;
struct V_20 T_3 * V_21 ;
V_2 = V_131 -> V_2 . V_136 ;
if ( ! F_48 ( V_2 ) ) {
F_41 ( L_25 , V_2 -> V_82 ) ;
return - V_137 ;
}
F_20 ( L_26 , V_2 -> V_82 ) ;
if ( F_49 ( V_2 , 0 , & V_133 ) ) {
F_50 ( V_138 L_27 ) ;
return - V_139 ;
}
V_134 = F_37 ( V_2 , L_28 , & V_31 ) ;
if ( V_134 == NULL || V_31 < 2 * sizeof( int ) )
F_50 ( V_138 L_29
L_30 , V_2 -> V_82 ) ;
F_51 ( V_140 ) ;
V_10 = F_52 ( V_2 ) ;
if ( ! V_10 )
return - V_139 ;
V_10 -> V_127 = & V_131 -> V_2 ;
V_10 -> V_17 = V_134 ? V_134 [ 0 ] : 0x0 ;
V_10 -> V_141 = V_134 ? V_134 [ 1 ] : 0xff ;
F_20 ( L_31 ,
( T_4 ) V_133 . V_48 , ( T_4 ) F_19 ( & V_133 ) ) ;
V_21 = V_10 -> V_22 = F_53 ( V_133 . V_48 , F_19 ( & V_133 ) ) ;
if ( ! V_10 -> V_22 )
goto V_142;
F_54 ( V_10 , V_133 . V_48 , V_133 . V_48 + 0x4 ,
V_143 ) ;
if ( F_7 ( & V_21 -> V_86 ) < V_144 )
V_10 -> V_12 |= V_13 ;
if ( F_30 ( V_10 , 0 , 0 , V_85 ) ) {
V_10 -> V_14 = & V_145 ;
F_55 ( V_10 , 0 , 0 , V_4 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_5 )
goto V_142;
} else {
F_55 ( V_10 , 0 , 0 , V_146 , & V_135 ) ;
if ( ( V_135 & 1 ) &&
! F_28 ( V_2 , L_32 ) )
goto V_142;
}
F_42 ( V_10 ) ;
if ( F_30 ( V_10 , 0 , 0 , V_85 ) ) {
V_10 -> V_12 |= V_147 |
V_148 ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
}
F_50 ( V_149 L_33
L_34 ,
( unsigned long long ) V_133 . V_48 , V_10 -> V_17 ,
V_10 -> V_141 ) ;
F_20 ( L_35 ,
V_10 , V_10 -> V_150 , V_10 -> V_151 ) ;
F_56 ( V_10 , V_2 , V_132 ) ;
F_29 ( V_10 ) ;
F_10 ( V_10 ) ;
return 0 ;
V_142:
F_57 ( V_10 -> V_22 ) ;
if ( ( ( unsigned long ) V_10 -> V_151 & V_152 ) !=
( ( unsigned long ) V_10 -> V_150 & V_152 ) )
F_57 ( V_10 -> V_151 ) ;
F_57 ( V_10 -> V_150 ) ;
F_58 ( V_10 ) ;
return - V_137 ;
}
static int F_59 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_10 -> V_12 & V_32 )
return V_153 ;
if ( V_28 -> V_154 == V_10 -> V_17 ||
V_28 -> V_155 == V_10 -> V_17 ) {
if ( V_29 & 0xf8 )
return V_153 ;
}
if ( V_107 . V_156 ) {
if ( V_107 . V_156 ( V_10 , V_28 -> V_154 , V_29 ) )
return V_153 ;
}
return V_157 ;
}
static void T_3 * F_60 ( struct V_27 * V_28 ,
unsigned int V_29 , int V_30 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
struct V_158 * V_159 = V_10 -> V_81 -> V_160 ;
T_2 V_161 = V_28 -> V_154 << 24 | V_29 << 16 ;
int V_162 ;
V_162 = F_59 ( V_28 , V_29 ) ;
if ( V_162 )
return NULL ;
V_30 &= 0xfff ;
if ( V_28 -> V_154 == V_10 -> V_17 )
return V_159 -> V_163 + V_30 ;
if ( V_159 -> V_161 == V_161 )
goto V_164;
F_61 ( V_159 -> V_163 + V_165 , V_161 ) ;
V_159 -> V_161 = V_161 ;
V_164:
return V_159 -> V_166 + V_30 ;
}
static int F_62 ( struct V_27 * V_28 , unsigned int V_29 ,
int V_30 , int V_31 , T_2 V_11 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_30 == V_167 && V_28 -> V_154 == V_10 -> V_17 )
V_11 &= 0xffffff00 ;
return F_63 ( V_28 , V_29 , V_30 , V_31 , V_11 ) ;
}
static int T_6 F_64 ( struct V_9 * V_10 ,
struct V_45 * V_83 )
{
struct V_158 * V_159 ;
T_2 V_168 ;
int V_162 = - V_139 ;
V_159 = F_65 ( sizeof( * V_159 ) , V_169 ) ;
if ( ! V_159 )
return V_162 ;
V_159 -> V_163 = F_53 ( V_83 -> V_48 , F_19 ( V_83 ) ) ;
if ( ! V_159 -> V_163 )
goto V_170;
V_168 = F_66 ( V_159 -> V_163 + V_171 ) ;
if ( ! V_168 ) {
V_162 = - V_137 ;
goto V_172;
}
V_159 -> V_166 = F_53 ( V_168 , 0x1000 ) ;
if ( ! V_159 -> V_166 )
goto V_172;
F_67 ( V_10 -> V_81 -> V_160 ) ;
V_10 -> V_81 -> V_160 = V_159 ;
V_10 -> V_14 = & V_173 ;
V_10 -> V_12 |= V_13 ;
F_61 ( V_159 -> V_163 + V_174 , 0 ) ;
F_61 ( V_159 -> V_163 + V_165 , 0 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
return 0 ;
V_172:
F_57 ( V_159 -> V_163 ) ;
V_170:
F_68 ( V_159 ) ;
return V_162 ;
}
int T_6 F_69 ( struct V_59 * V_2 )
{
int V_162 ;
int V_31 ;
struct V_9 * V_10 ;
struct V_45 V_175 ;
struct V_45 V_176 ;
const int * V_134 ;
int V_155 ;
V_177 = 1 ;
if ( ! F_48 ( V_2 ) ) {
F_41 ( L_36 ,
V_2 -> V_82 ) ;
return - V_137 ;
}
F_20 ( L_26 , V_2 -> V_82 ) ;
if ( F_49 ( V_2 , 0 , & V_175 ) ) {
F_50 ( V_138 L_37 ) ;
return - V_139 ;
}
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
if ( F_49 ( V_2 , 1 , & V_176 ) ) {
F_50 ( V_138
L_38
L_39 ) ;
if ( ( V_175 . V_48 & 0xfffff ) == 0x8500 )
V_176 . V_48 = ( V_175 . V_48 & 0xfff00000 ) + 0x8300 ;
else if ( ( V_175 . V_48 & 0xfffff ) == 0x8600 )
V_176 . V_48 = ( V_175 . V_48 & 0xfff00000 ) + 0x8380 ;
}
if ( ( V_175 . V_48 & 0xfffff ) == 0x8500 )
V_155 = 1 ;
else
V_155 = 0 ;
V_134 = F_37 ( V_2 , L_28 , & V_31 ) ;
if ( V_134 == NULL || V_31 < 2 * sizeof( int ) ) {
F_50 ( V_138 L_29
L_30 , V_2 -> V_82 ) ;
}
F_51 ( V_140 ) ;
V_10 = F_52 ( V_2 ) ;
if ( ! V_10 )
return - V_139 ;
V_10 -> V_17 = V_134 ? V_134 [ 0 ] : 0 ;
V_10 -> V_141 = V_134 ? V_134 [ 1 ] : 0xff ;
if ( F_70 ( V_2 , L_40 ) ) {
V_162 = F_64 ( V_10 , & V_175 ) ;
if ( V_162 )
goto V_170;
} else {
F_54 ( V_10 , V_176 . V_48 ,
V_176 . V_48 + 4 , 0 ) ;
}
F_50 ( V_149 L_33
L_34 ,
( unsigned long long ) V_175 . V_48 , V_10 -> V_17 ,
V_10 -> V_141 ) ;
F_20 ( L_35 ,
V_10 , V_10 -> V_150 , V_10 -> V_151 ) ;
F_56 ( V_10 , V_2 , V_155 ) ;
return 0 ;
V_170:
F_58 ( V_10 ) ;
return V_162 ;
}
T_4 F_71 ( struct V_9 * V_10 )
{
#ifdef F_72
if ( V_177 ) {
struct V_158 * V_159 = V_10 -> V_81 -> V_160 ;
struct V_178 * V_179 ;
int V_52 ;
V_179 = V_159 -> V_163 + V_180 ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
if ( ! ( F_66 ( & V_179 [ V_52 ] . V_181 ) & V_182 ) )
continue;
if ( F_73 () == F_66 ( & V_179 [ V_52 ] . V_183 ) )
return ( T_4 ) F_66 ( & V_179 [ V_52 ] . V_184 ) << 32 |
F_66 ( & V_179 [ V_52 ] . V_185 ) ;
}
F_50 ( V_138 L_41 ) ;
}
#endif
#if F_74 ( V_186 ) || F_74 ( V_187 )
if ( ! V_177 ) {
T_2 V_188 ;
F_75 ( V_10 -> V_28 ,
F_76 ( 0 , 0 ) , V_97 , & V_188 ) ;
V_188 &= V_189 ;
return V_188 ;
}
#endif
return 0 ;
}
static int F_77 ( struct V_190 * V_191 , T_2 V_192 )
{
unsigned int V_193 , V_194 , V_195 , V_196 ;
V_193 = F_78 ( V_192 ) ;
V_194 = F_79 ( V_192 ) ;
V_195 = F_80 ( V_192 ) ;
V_196 = F_81 ( V_192 ) ;
switch ( F_82 ( V_192 ) ) {
case 31 :
switch ( F_83 ( V_192 ) ) {
case V_197 :
case V_198 :
V_191 -> V_199 [ V_193 ] = 0xffffffff ;
break;
case V_200 :
V_191 -> V_199 [ V_193 ] = 0xffffffff ;
V_191 -> V_199 [ V_194 ] += V_191 -> V_199 [ V_195 ] ;
break;
case V_201 :
V_191 -> V_199 [ V_193 ] = 0xff ;
break;
case V_202 :
V_191 -> V_199 [ V_193 ] = 0xff ;
V_191 -> V_199 [ V_194 ] += V_191 -> V_199 [ V_195 ] ;
break;
case V_203 :
case V_204 :
V_191 -> V_199 [ V_193 ] = 0xffff ;
break;
case V_205 :
V_191 -> V_199 [ V_193 ] = 0xffff ;
V_191 -> V_199 [ V_194 ] += V_191 -> V_199 [ V_195 ] ;
break;
case V_206 :
V_191 -> V_199 [ V_193 ] = ~ 0UL ;
break;
case V_207 :
V_191 -> V_199 [ V_193 ] = ~ 0UL ;
V_191 -> V_199 [ V_194 ] += V_191 -> V_199 [ V_195 ] ;
break;
default:
return 0 ;
}
break;
case V_208 :
V_191 -> V_199 [ V_193 ] = 0xffffffff ;
break;
case V_209 :
V_191 -> V_199 [ V_193 ] = 0xffffffff ;
V_191 -> V_199 [ V_194 ] += ( V_210 ) V_196 ;
break;
case V_211 :
V_191 -> V_199 [ V_193 ] = 0xff ;
break;
case V_212 :
V_191 -> V_199 [ V_193 ] = 0xff ;
V_191 -> V_199 [ V_194 ] += ( V_210 ) V_196 ;
break;
case V_213 :
V_191 -> V_199 [ V_193 ] = 0xffff ;
break;
case V_214 :
V_191 -> V_199 [ V_193 ] = 0xffff ;
V_191 -> V_199 [ V_194 ] += ( V_210 ) V_196 ;
break;
case V_215 :
V_191 -> V_199 [ V_193 ] = ~ 0UL ;
break;
case V_216 :
V_191 -> V_199 [ V_193 ] = ~ 0UL ;
V_191 -> V_199 [ V_194 ] += ( V_210 ) V_196 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_84 ( T_8 V_217 )
{
struct V_9 * V_10 ;
struct V_45 * V_46 ;
int V_52 ;
F_85 (hose, &hose_list, list_node) {
if ( ! ( V_10 -> V_12 & V_147 ) )
continue;
for ( V_52 = 0 ; V_52 < 3 ; V_52 ++ ) {
V_46 = & V_10 -> V_89 [ V_52 ] ;
if ( ( V_46 -> V_51 & V_90 ) &&
V_217 >= V_46 -> V_48 && V_217 <= V_46 -> V_91 )
return 1 ;
}
}
return 0 ;
}
int F_86 ( struct V_190 * V_191 )
{
T_2 V_192 ;
int V_162 ;
T_8 V_217 = 0 ;
if ( V_191 -> V_218 & V_219 )
return 0 ;
#ifdef F_87
V_217 = F_88 ( V_220 ) ;
V_217 <<= 32 ;
#endif
V_217 += F_88 ( V_221 ) ;
if ( F_84 ( V_217 ) ) {
if ( F_89 ( V_191 ) ) {
F_90 () ;
V_162 = F_91 ( V_191 -> V_222 , & V_192 ) ;
F_92 () ;
} else {
V_162 = F_93 ( ( void * ) V_191 -> V_222 , V_192 ) ;
}
if ( ! V_162 && F_77 ( V_191 , V_192 ) ) {
V_191 -> V_222 += 4 ;
return 1 ;
}
}
return 0 ;
}
void F_94 ( void )
{
struct V_59 * V_223 ;
if ( V_224 )
return;
V_223 = F_26 ( NULL , L_42 ) ;
while ( ( V_224 = F_95 ( V_223 ) ) ) {
F_96 ( V_223 ) ;
V_223 = V_224 ;
if ( F_97 ( V_225 , V_223 ) && F_48 ( V_223 ) )
return;
}
F_98 (np, pci_ids) {
if ( F_48 ( V_223 ) ) {
V_224 = V_223 ;
F_96 ( V_223 ) ;
return;
}
}
}
static T_9 F_99 ( int V_226 , void * V_227 )
{
struct V_9 * V_10 = V_227 ;
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_228 ;
V_228 = F_7 ( & V_21 -> V_229 ) ;
if ( ! V_228 )
return V_230 ;
F_24 ( & V_21 -> V_229 , V_228 ) ;
return V_231 ;
}
static int F_100 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 ;
struct V_1 * V_2 ;
int V_232 ;
int V_46 ;
T_7 V_233 ;
V_2 = F_101 ( & V_10 -> V_28 -> V_234 , F_102 ( * V_2 ) , V_235 ) ;
F_103 ( V_2 , V_2 -> V_236 + V_237 , & V_233 ) ;
V_233 &= ~ V_238 ;
F_104 ( V_2 , V_2 -> V_236 + V_237 , V_233 ) ;
V_232 = F_105 ( V_10 -> V_81 , 0 ) ;
if ( ! V_232 ) {
F_106 ( & V_2 -> V_2 , L_43 ) ;
return - V_239 ;
}
V_46 = F_107 ( V_10 -> V_127 , V_232 ,
F_99 ,
V_240 ,
L_44 , V_10 ) ;
if ( V_46 < 0 ) {
F_106 ( & V_2 -> V_2 , L_45 , V_232 ) ;
F_108 ( V_232 ) ;
return - V_137 ;
}
V_21 = V_10 -> V_22 ;
F_109 ( & V_21 -> V_241 ,
V_242 | V_243 | V_244 ) ;
F_24 ( & V_21 -> V_245 , 0 ) ;
F_110 ( & V_21 -> V_245 ,
V_242 | V_243 | V_244 ) ;
F_103 ( V_2 , V_2 -> V_236 + V_237 , & V_233 ) ;
V_233 |= V_238 ;
F_104 ( V_2 , V_2 -> V_236 + V_237 , V_233 ) ;
return 0 ;
}
static void F_111 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_228 ;
int V_52 ;
F_110 ( & V_21 -> V_246 , V_247 ) ;
for ( V_52 = 0 ; V_52 < 150 ; V_52 ++ ) {
V_228 = F_7 ( & V_21 -> V_229 ) ;
if ( V_228 ) {
F_24 ( & V_21 -> V_229 , V_228 ) ;
break;
}
F_112 ( 1000 ) ;
}
}
static void F_113 ( struct V_9 * V_10 )
{
F_111 ( V_10 ) ;
}
static int F_114 ( void )
{
struct V_9 * V_10 , * V_248 ;
F_115 (hose, tmp, &hose_list, list_node)
F_113 ( V_10 ) ;
return 0 ;
}
static void F_116 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_228 ;
int V_52 ;
F_110 ( & V_21 -> V_246 , V_249 ) ;
for ( V_52 = 0 ; V_52 < 150 ; V_52 ++ ) {
V_228 = F_7 ( & V_21 -> V_229 ) ;
if ( V_228 ) {
F_24 ( & V_21 -> V_229 , V_228 ) ;
break;
}
F_112 ( 1000 ) ;
}
F_29 ( V_10 ) ;
}
static void F_117 ( void )
{
struct V_9 * V_10 , * V_248 ;
F_115 (hose, tmp, &hose_list, list_node)
F_116 ( V_10 ) ;
}
void F_118 ( struct V_9 * V_250 )
{
#ifdef F_119
F_100 ( V_250 ) ;
#endif
}
static int F_120 ( struct V_130 * V_131 )
{
struct V_59 * V_60 ;
int V_162 ;
V_60 = V_131 -> V_2 . V_136 ;
V_162 = F_47 ( V_131 , V_224 == V_60 ) ;
F_121 ( V_131 ) ;
return 0 ;
}
static int T_6 F_122 ( void )
{
#ifdef F_119
F_123 ( & V_251 ) ;
#endif
return F_124 ( & V_252 ) ;
}
