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
static int F_10 ( struct V_33 * V_2 , T_4 V_34 )
{
if ( ! V_2 -> V_34 || ! F_11 ( V_2 , V_34 ) )
return - V_35 ;
if ( ( F_12 ( V_2 ) ) &&
V_34 >= F_13 ( V_36 ) ) {
F_14 ( V_2 , & V_37 ) ;
F_15 ( V_2 , V_38 ) ;
}
* V_2 -> V_34 = V_34 ;
return 0 ;
}
static int F_16 ( struct V_20 T_3 * V_21 ,
unsigned int V_39 , const struct V_40 * V_41 ,
T_5 V_30 )
{
T_5 V_42 = V_41 -> V_43 - V_30 ;
T_5 V_44 = V_41 -> V_43 ;
T_5 V_45 = F_17 ( V_41 ) ;
T_2 V_46 = 0x80044000 ;
unsigned int V_47 ;
F_18 ( L_1 ,
( T_4 ) V_41 -> V_43 , ( T_4 ) V_45 ) ;
if ( V_41 -> V_46 & V_48 )
V_46 |= 0x10000000 ;
for ( V_47 = 0 ; V_45 > 0 ; V_47 ++ ) {
unsigned int V_49 = F_19 ( T_2 , F_20 ( V_45 ) ,
F_21 ( V_42 | V_44 ) ) ;
if ( V_39 + V_47 >= 5 )
return - 1 ;
F_22 ( & V_21 -> pow [ V_39 + V_47 ] . V_50 , V_42 >> 12 ) ;
F_22 ( & V_21 -> pow [ V_39 + V_47 ] . V_51 , ( T_4 ) V_42 >> 44 ) ;
F_22 ( & V_21 -> pow [ V_39 + V_47 ] . V_52 , V_44 >> 12 ) ;
F_22 ( & V_21 -> pow [ V_39 + V_47 ] . V_53 , V_46 | ( V_49 - 1 ) ) ;
V_42 += ( T_5 ) 1U << V_49 ;
V_44 += ( T_5 ) 1U << V_49 ;
V_45 -= ( T_5 ) 1U << V_49 ;
}
return V_47 ;
}
static void F_23 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
int V_47 , V_54 , V_55 , V_56 , V_57 = 3 , V_58 = 1 , V_59 = 4 ;
T_4 V_60 , V_61 , V_62 = 0 ;
T_4 V_30 = 0 , V_63 = V_64 ;
T_2 V_65 = 0 , V_66 ;
T_2 V_67 = V_68 | V_69 | V_70 |
V_71 | V_72 ;
const char * V_73 = V_10 -> V_74 -> V_75 ;
const T_4 * V_76 ;
int V_31 ;
if ( F_24 ( V_10 , 0 , 0 , V_77 ) ) {
if ( F_7 ( & V_21 -> V_78 ) >= V_79 ) {
V_57 = 2 ;
V_58 = 0 ;
V_59 = 3 ;
}
}
for( V_47 = 1 ; V_47 < 5 ; V_47 ++ )
F_22 ( & V_21 -> pow [ V_47 ] . V_53 , 0 ) ;
for ( V_47 = V_58 ; V_47 < V_59 ; V_47 ++ )
F_22 ( & V_21 -> V_80 [ V_47 ] . V_67 , 0 ) ;
for( V_47 = 0 , V_54 = 1 ; V_47 < 3 ; V_47 ++ ) {
if ( ! ( V_10 -> V_81 [ V_47 ] . V_46 & V_82 ) )
continue;
V_63 = F_25 ( V_63 , ( T_4 ) V_10 -> V_81 [ V_47 ] . V_43 ) ;
V_62 = F_26 ( V_62 , ( T_4 ) V_10 -> V_81 [ V_47 ] . V_83 ) ;
V_30 = V_10 -> V_84 [ V_47 ] ;
V_55 = F_16 ( V_21 , V_54 , & V_10 -> V_81 [ V_47 ] , V_30 ) ;
if ( V_55 < 0 || V_54 >= 5 ) {
F_27 ( L_2 , V_47 ) ;
V_10 -> V_81 [ V_47 ] . V_46 |= V_85 ;
} else
V_54 += V_55 ;
}
if ( V_10 -> V_86 . V_46 & V_87 ) {
if ( V_54 >= 5 ) {
F_27 ( L_3 ) ;
} else {
F_18 ( L_4
L_5 ,
( T_4 ) V_10 -> V_86 . V_43 ,
( T_4 ) F_17 ( & V_10 -> V_86 ) ,
( T_4 ) V_10 -> V_88 ) ;
F_22 ( & V_21 -> pow [ V_54 ] . V_50 , ( V_10 -> V_86 . V_43 >> 12 ) ) ;
F_22 ( & V_21 -> pow [ V_54 ] . V_51 , 0 ) ;
F_22 ( & V_21 -> pow [ V_54 ] . V_52 , ( V_10 -> V_88 >> 12 ) ) ;
F_22 ( & V_21 -> pow [ V_54 ] . V_53 , 0x80088000
| ( F_20 ( V_10 -> V_86 . V_83
- V_10 -> V_86 . V_43 + 1 ) - 1 ) ) ;
}
}
V_62 -= V_30 ;
V_63 -= V_30 ;
if ( V_62 == V_63 ) {
F_27 ( L_6 , V_73 ) ;
return;
}
if ( V_63 == 0 ) {
F_27 ( L_7 , V_73 ) ;
return;
}
F_28 ( V_10 , 0 , 0 , V_89 , 0xffffffff ) ;
F_6 ( V_10 , 0 , 0 , V_89 , & V_66 ) ;
V_66 = ~ V_66 + 1 ;
if ( V_62 < ( 0x100000000ull - V_66 ) ||
( V_63 > 0x100000000ull ) )
V_65 = 0x100000000ull - V_66 ;
else
V_65 = ( V_63 - V_66 ) & - V_66 ;
F_28 ( V_10 , 0 , 0 , V_89 , V_65 ) ;
V_63 = F_25 ( V_63 , ( T_4 ) V_65 ) ;
F_29 ( L_8 , V_73 , V_65 ) ;
V_60 = F_30 () ;
V_76 = F_31 ( V_10 -> V_74 , L_9 , & V_31 ) ;
if ( V_76 && ( V_31 == sizeof( T_4 ) ) ) {
T_4 V_90 = F_32 ( V_76 ) ;
if ( ( V_90 >= V_60 ) && ( V_90 < ( V_60 + V_91 ) ) ) {
F_29 ( L_10 , V_73 ) ;
V_60 += V_91 ;
} else {
F_33 ( L_11
L_12 , V_73 , V_90 ) ;
}
}
V_61 = F_25 ( V_60 , V_63 ) ;
V_56 = F_20 ( V_61 ) ;
if ( F_24 ( V_10 , 0 , 0 , V_77 ) ) {
if ( ( 1ull << V_56 ) != V_60 ) {
V_56 ++ ;
if ( ( 1ull << V_56 ) > V_60 )
F_29 ( L_13
L_14 , V_73 ) ;
}
V_67 |= ( ( V_56 - 1 ) & V_92 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_93 , 0x00000000 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_94 , 0x00000000 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_67 , V_67 ) ;
V_57 -- ;
V_10 -> V_95 = 0x00000000 ;
V_10 -> V_96 = ( T_5 ) V_61 ;
if ( V_61 != V_60 ) {
V_56 = F_20 ( V_60 ) ;
if ( ( 1ull << V_56 ) != V_60 )
V_56 ++ ;
V_67 = ( V_67 & ~ V_92 ) | ( V_56 - 1 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_93 , 0x00000000 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_97 ,
V_38 >> 44 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_94 ,
V_38 >> 12 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_67 , V_67 ) ;
V_98 . V_99 = F_10 ;
F_29 ( L_15 , V_73 ) ;
}
} else {
T_4 V_100 = 0 ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_93 , V_100 >> 12 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_94 , V_100 >> 12 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_67 , ( V_67 | ( V_56 - 1 ) ) ) ;
V_57 -- ;
V_100 += 1ull << V_56 ;
V_61 -= 1ull << V_56 ;
if ( V_61 ) {
V_56 = F_20 ( V_61 ) ;
V_67 |= ( V_56 - 1 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_93 , V_100 >> 12 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_94 , V_100 >> 12 ) ;
F_22 ( & V_21 -> V_80 [ V_57 ] . V_67 , V_67 ) ;
V_57 -- ;
V_100 += 1ull << V_56 ;
}
V_10 -> V_95 = 0x00000000 ;
V_10 -> V_96 = ( T_5 ) V_100 ;
}
if ( V_10 -> V_96 < V_60 ) {
#ifdef F_34
V_101 = 1 ;
#else
F_27 ( L_16
L_17 ,
V_73 ) ;
#endif
if ( V_62 < 0xffffffffull )
F_35 ( L_18
L_19
L_20 ,
V_73 ) ;
F_29 ( L_21 , V_73 ,
( T_4 ) V_10 -> V_96 ) ;
}
}
static void T_6 F_36 ( struct V_9 * V_10 )
{
T_7 V_102 ;
int V_103 ;
F_37 ( V_10 , 0 , 0 , V_104 , & V_102 ) ;
V_102 |= V_105 | V_106 | V_107
| V_108 ;
F_38 ( V_10 , 0 , 0 , V_104 , V_102 ) ;
V_103 = F_24 ( V_10 , 0 , 0 , V_109 ) ;
if ( V_103 ) {
int V_110 = V_103 + V_111 ;
V_102 = V_112 | V_113
| V_114 | V_115 ;
F_38 ( V_10 , 0 , 0 , V_110 , V_102 ) ;
} else {
F_39 ( V_10 , 0 , 0 , V_116 , 0x80 ) ;
}
}
void F_40 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
int V_47 , V_117 = 0 , V_118 ;
if ( V_8 )
V_117 = F_24 ( V_10 , 0 , 0 , V_77 ) ;
V_118 = ! ! ( V_10 -> V_12 & V_32 ) ;
if ( V_28 -> V_119 == V_10 -> V_28 && ( V_117 || V_118 ) ) {
for ( V_47 = 0 ; V_47 < V_120 ; ++ V_47 ) {
struct V_40 * V_41 = V_28 -> V_40 [ V_47 ] ;
struct V_40 * V_121 ;
if ( ! V_41 )
continue;
if ( V_47 == 0 )
V_121 = & V_10 -> V_86 ;
else if ( V_47 < 4 )
V_121 = & V_10 -> V_81 [ V_47 - 1 ] ;
else V_121 = NULL ;
V_41 -> V_43 = V_121 ? V_121 -> V_43 : 0 ;
V_41 -> V_83 = V_121 ? V_121 -> V_83 : 0 ;
V_41 -> V_46 = V_121 ? V_121 -> V_46 : 0 ;
}
}
}
int F_41 ( struct V_122 * V_123 , int V_124 )
{
int V_31 ;
struct V_9 * V_10 ;
struct V_40 V_125 ;
const int * V_126 ;
T_1 V_3 , V_127 ;
struct V_128 * V_2 ;
struct V_20 T_3 * V_21 ;
V_2 = V_123 -> V_2 . V_129 ;
if ( ! F_42 ( V_2 ) ) {
F_35 ( L_22 , V_2 -> V_75 ) ;
return - V_130 ;
}
F_18 ( L_23 , V_2 -> V_75 ) ;
if ( F_43 ( V_2 , 0 , & V_125 ) ) {
F_44 ( V_131 L_24 ) ;
return - V_132 ;
}
V_126 = F_31 ( V_2 , L_25 , & V_31 ) ;
if ( V_126 == NULL || V_31 < 2 * sizeof( int ) )
F_44 ( V_131 L_26
L_27 , V_2 -> V_75 ) ;
F_45 ( V_133 ) ;
V_10 = F_46 ( V_2 ) ;
if ( ! V_10 )
return - V_132 ;
V_10 -> V_119 = & V_123 -> V_2 ;
V_10 -> V_17 = V_126 ? V_126 [ 0 ] : 0x0 ;
V_10 -> V_134 = V_126 ? V_126 [ 1 ] : 0xff ;
F_18 ( L_28 ,
( T_4 ) V_125 . V_43 , ( T_4 ) F_17 ( & V_125 ) ) ;
V_21 = V_10 -> V_22 = F_47 ( V_125 . V_43 , F_17 ( & V_125 ) ) ;
if ( ! V_10 -> V_22 )
goto V_135;
F_48 ( V_10 , V_125 . V_43 , V_125 . V_43 + 0x4 ,
V_136 ) ;
if ( F_7 ( & V_21 -> V_78 ) < V_137 )
V_10 -> V_12 |= V_13 ;
if ( F_24 ( V_10 , 0 , 0 , V_77 ) ) {
V_10 -> V_14 = & V_138 ;
F_49 ( V_10 , 0 , 0 , V_4 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_5 )
goto V_135;
} else {
F_49 ( V_10 , 0 , 0 , V_139 , & V_127 ) ;
if ( ( V_127 & 1 ) &&
! F_50 ( V_2 , L_29 ) )
goto V_135;
}
F_36 ( V_10 ) ;
if ( F_24 ( V_10 , 0 , 0 , V_77 ) ) {
V_10 -> V_12 |= V_140 |
V_141 ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
}
F_44 ( V_142 L_30
L_31 ,
( unsigned long long ) V_125 . V_43 , V_10 -> V_17 ,
V_10 -> V_134 ) ;
F_18 ( L_32 ,
V_10 , V_10 -> V_143 , V_10 -> V_144 ) ;
F_51 ( V_10 , V_2 , V_124 ) ;
F_23 ( V_10 ) ;
return 0 ;
V_135:
F_52 ( V_10 -> V_22 ) ;
if ( ( ( unsigned long ) V_10 -> V_144 & V_145 ) !=
( ( unsigned long ) V_10 -> V_143 & V_145 ) )
F_52 ( V_10 -> V_144 ) ;
F_52 ( V_10 -> V_143 ) ;
F_53 ( V_10 ) ;
return - V_130 ;
}
static int F_54 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_10 -> V_12 & V_32 )
return V_146 ;
if ( V_28 -> V_147 == V_10 -> V_17 ||
V_28 -> V_148 == V_10 -> V_17 ) {
if ( V_29 & 0xf8 )
return V_146 ;
}
if ( V_98 . V_149 ) {
if ( V_98 . V_149 ( V_10 , V_28 -> V_147 , V_29 ) )
return V_146 ;
}
return V_150 ;
}
static void T_3 * F_55 ( struct V_27 * V_28 ,
unsigned int V_29 , int V_30 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
struct V_151 * V_152 = V_10 -> V_74 -> V_153 ;
T_2 V_154 = V_28 -> V_147 << 24 | V_29 << 16 ;
int V_155 ;
V_155 = F_54 ( V_28 , V_29 ) ;
if ( V_155 )
return NULL ;
V_30 &= 0xfff ;
if ( V_28 -> V_147 == V_10 -> V_17 )
return V_152 -> V_156 + V_30 ;
if ( V_152 -> V_154 == V_154 )
goto V_157;
F_56 ( V_152 -> V_156 + V_158 , V_154 ) ;
V_152 -> V_154 = V_154 ;
V_157:
return V_152 -> V_159 + V_30 ;
}
static int F_57 ( struct V_27 * V_28 , unsigned int V_29 ,
int V_30 , int V_31 , T_2 V_11 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_30 == V_160 && V_28 -> V_147 == V_10 -> V_17 )
V_11 &= 0xffffff00 ;
return F_58 ( V_28 , V_29 , V_30 , V_31 , V_11 ) ;
}
static int T_6 F_59 ( struct V_9 * V_10 ,
struct V_40 * V_76 )
{
struct V_151 * V_152 ;
T_2 V_161 ;
int V_155 = - V_132 ;
V_152 = F_60 ( sizeof( * V_152 ) , V_162 ) ;
if ( ! V_152 )
return V_155 ;
V_152 -> V_156 = F_47 ( V_76 -> V_43 , F_17 ( V_76 ) ) ;
if ( ! V_152 -> V_156 )
goto V_163;
V_161 = F_61 ( V_152 -> V_156 + V_164 ) ;
if ( ! V_161 ) {
V_155 = - V_130 ;
goto V_165;
}
V_152 -> V_159 = F_47 ( V_161 , 0x1000 ) ;
if ( ! V_152 -> V_159 )
goto V_165;
F_62 ( V_10 -> V_74 -> V_153 ) ;
V_10 -> V_74 -> V_153 = V_152 ;
V_10 -> V_14 = & V_166 ;
V_10 -> V_12 |= V_13 ;
F_56 ( V_152 -> V_156 + V_167 , 0 ) ;
F_56 ( V_152 -> V_156 + V_158 , 0 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
return 0 ;
V_165:
F_52 ( V_152 -> V_156 ) ;
V_163:
F_63 ( V_152 ) ;
return V_155 ;
}
int T_6 F_64 ( struct V_128 * V_2 )
{
int V_155 ;
int V_31 ;
struct V_9 * V_10 ;
struct V_40 V_168 ;
struct V_40 V_169 ;
const int * V_126 ;
int V_148 ;
V_170 = 1 ;
if ( ! F_42 ( V_2 ) ) {
F_35 ( L_33 ,
V_2 -> V_75 ) ;
return - V_130 ;
}
F_18 ( L_23 , V_2 -> V_75 ) ;
if ( F_43 ( V_2 , 0 , & V_168 ) ) {
F_44 ( V_131 L_34 ) ;
return - V_132 ;
}
memset ( & V_169 , 0 , sizeof( V_169 ) ) ;
if ( F_43 ( V_2 , 1 , & V_169 ) ) {
F_44 ( V_131
L_35
L_36 ) ;
if ( ( V_168 . V_43 & 0xfffff ) == 0x8500 )
V_169 . V_43 = ( V_168 . V_43 & 0xfff00000 ) + 0x8300 ;
else if ( ( V_168 . V_43 & 0xfffff ) == 0x8600 )
V_169 . V_43 = ( V_168 . V_43 & 0xfff00000 ) + 0x8380 ;
}
if ( ( V_168 . V_43 & 0xfffff ) == 0x8500 )
V_148 = 1 ;
else
V_148 = 0 ;
V_126 = F_31 ( V_2 , L_25 , & V_31 ) ;
if ( V_126 == NULL || V_31 < 2 * sizeof( int ) ) {
F_44 ( V_131 L_26
L_27 , V_2 -> V_75 ) ;
}
F_45 ( V_133 ) ;
V_10 = F_46 ( V_2 ) ;
if ( ! V_10 )
return - V_132 ;
V_10 -> V_17 = V_126 ? V_126 [ 0 ] : 0 ;
V_10 -> V_134 = V_126 ? V_126 [ 1 ] : 0xff ;
if ( F_65 ( V_2 , L_37 ) ) {
V_155 = F_59 ( V_10 , & V_168 ) ;
if ( V_155 )
goto V_163;
} else {
F_48 ( V_10 , V_169 . V_43 ,
V_169 . V_43 + 4 , 0 ) ;
}
F_44 ( V_142 L_30
L_31 ,
( unsigned long long ) V_168 . V_43 , V_10 -> V_17 ,
V_10 -> V_134 ) ;
F_18 ( L_32 ,
V_10 , V_10 -> V_143 , V_10 -> V_144 ) ;
F_51 ( V_10 , V_2 , V_148 ) ;
return 0 ;
V_163:
F_53 ( V_10 ) ;
return V_155 ;
}
T_4 F_66 ( struct V_9 * V_10 )
{
#ifdef F_67
if ( V_170 ) {
struct V_151 * V_152 = V_10 -> V_74 -> V_153 ;
struct V_171 * V_172 ;
int V_47 ;
V_172 = V_152 -> V_156 + V_173 ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
if ( ! ( F_61 ( & V_172 [ V_47 ] . V_174 ) & V_175 ) )
continue;
if ( F_68 () == F_61 ( & V_172 [ V_47 ] . V_176 ) )
return ( T_4 ) F_61 ( & V_172 [ V_47 ] . V_177 ) << 32 |
F_61 ( & V_172 [ V_47 ] . V_178 ) ;
}
F_44 ( V_131 L_38 ) ;
}
#endif
#if F_69 ( V_179 ) || F_69 ( V_180 )
if ( ! V_170 ) {
T_2 V_181 ;
F_70 ( V_10 -> V_28 ,
F_71 ( 0 , 0 ) , V_89 , & V_181 ) ;
V_181 &= V_182 ;
return V_181 ;
}
#endif
return 0 ;
}
static int F_72 ( struct V_183 * V_184 , T_2 V_185 )
{
unsigned int V_186 , V_187 , V_188 , V_189 ;
V_186 = F_73 ( V_185 ) ;
V_187 = F_74 ( V_185 ) ;
V_188 = F_75 ( V_185 ) ;
V_189 = F_76 ( V_185 ) ;
switch ( F_77 ( V_185 ) ) {
case 31 :
switch ( F_78 ( V_185 ) ) {
case V_190 :
case V_191 :
V_184 -> V_192 [ V_186 ] = 0xffffffff ;
break;
case V_193 :
V_184 -> V_192 [ V_186 ] = 0xffffffff ;
V_184 -> V_192 [ V_187 ] += V_184 -> V_192 [ V_188 ] ;
break;
case V_194 :
V_184 -> V_192 [ V_186 ] = 0xff ;
break;
case V_195 :
V_184 -> V_192 [ V_186 ] = 0xff ;
V_184 -> V_192 [ V_187 ] += V_184 -> V_192 [ V_188 ] ;
break;
case V_196 :
case V_197 :
V_184 -> V_192 [ V_186 ] = 0xffff ;
break;
case V_198 :
V_184 -> V_192 [ V_186 ] = 0xffff ;
V_184 -> V_192 [ V_187 ] += V_184 -> V_192 [ V_188 ] ;
break;
case V_199 :
V_184 -> V_192 [ V_186 ] = ~ 0UL ;
break;
case V_200 :
V_184 -> V_192 [ V_186 ] = ~ 0UL ;
V_184 -> V_192 [ V_187 ] += V_184 -> V_192 [ V_188 ] ;
break;
default:
return 0 ;
}
break;
case V_201 :
V_184 -> V_192 [ V_186 ] = 0xffffffff ;
break;
case V_202 :
V_184 -> V_192 [ V_186 ] = 0xffffffff ;
V_184 -> V_192 [ V_187 ] += ( V_203 ) V_189 ;
break;
case V_204 :
V_184 -> V_192 [ V_186 ] = 0xff ;
break;
case V_205 :
V_184 -> V_192 [ V_186 ] = 0xff ;
V_184 -> V_192 [ V_187 ] += ( V_203 ) V_189 ;
break;
case V_206 :
V_184 -> V_192 [ V_186 ] = 0xffff ;
break;
case V_207 :
V_184 -> V_192 [ V_186 ] = 0xffff ;
V_184 -> V_192 [ V_187 ] += ( V_203 ) V_189 ;
break;
case V_208 :
V_184 -> V_192 [ V_186 ] = ~ 0UL ;
break;
case V_209 :
V_184 -> V_192 [ V_186 ] = ~ 0UL ;
V_184 -> V_192 [ V_187 ] += ( V_203 ) V_189 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_79 ( T_8 V_210 )
{
struct V_9 * V_10 ;
struct V_40 * V_41 ;
int V_47 ;
F_80 (hose, &hose_list, list_node) {
if ( ! ( V_10 -> V_12 & V_140 ) )
continue;
for ( V_47 = 0 ; V_47 < 3 ; V_47 ++ ) {
V_41 = & V_10 -> V_81 [ V_47 ] ;
if ( ( V_41 -> V_46 & V_82 ) &&
V_210 >= V_41 -> V_43 && V_210 <= V_41 -> V_83 )
return 1 ;
}
}
return 0 ;
}
int F_81 ( struct V_183 * V_184 )
{
T_2 V_185 ;
int V_155 ;
T_8 V_210 = 0 ;
if ( V_184 -> V_211 & V_212 )
return 0 ;
#ifdef F_82
V_210 = F_83 ( V_213 ) ;
V_210 <<= 32 ;
#endif
V_210 += F_83 ( V_214 ) ;
if ( F_79 ( V_210 ) ) {
if ( F_84 ( V_184 ) ) {
F_85 () ;
V_155 = F_86 ( V_184 -> V_215 , & V_185 ) ;
F_87 () ;
} else {
V_155 = F_88 ( V_184 -> V_215 , V_185 ) ;
}
if ( F_72 ( V_184 , V_185 ) ) {
V_184 -> V_215 += 4 ;
return 1 ;
}
}
return 0 ;
}
void F_89 ( void )
{
struct V_128 * V_216 ;
if ( V_217 )
return;
V_216 = F_90 ( NULL , L_39 ) ;
while ( ( V_217 = F_91 ( V_216 ) ) ) {
F_92 ( V_216 ) ;
V_216 = V_217 ;
if ( F_93 ( V_218 , V_216 ) && F_42 ( V_216 ) )
return;
}
F_94 (np, pci_ids) {
if ( F_42 ( V_216 ) ) {
V_217 = V_216 ;
F_92 ( V_216 ) ;
return;
}
}
}
static T_9 F_95 ( int V_219 , void * V_220 )
{
struct V_9 * V_10 = V_220 ;
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_221 ;
V_221 = F_7 ( & V_21 -> V_222 ) ;
if ( ! V_221 )
return V_223 ;
F_22 ( & V_21 -> V_222 , V_221 ) ;
return V_224 ;
}
static int F_96 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 ;
struct V_1 * V_2 ;
int V_225 ;
int V_41 ;
T_7 V_226 ;
V_2 = F_97 ( & V_10 -> V_28 -> V_227 , F_98 ( * V_2 ) , V_228 ) ;
F_99 ( V_2 , V_2 -> V_229 + V_230 , & V_226 ) ;
V_226 &= ~ V_231 ;
F_100 ( V_2 , V_2 -> V_229 + V_230 , V_226 ) ;
V_225 = F_101 ( V_10 -> V_74 , 0 ) ;
if ( ! V_225 ) {
F_102 ( & V_2 -> V_2 , L_40 ) ;
return - V_232 ;
}
V_41 = F_103 ( V_10 -> V_119 , V_225 ,
F_95 ,
V_233 ,
L_41 , V_10 ) ;
if ( V_41 < 0 ) {
F_102 ( & V_2 -> V_2 , L_42 , V_225 ) ;
F_104 ( V_225 ) ;
return - V_130 ;
}
V_21 = V_10 -> V_22 ;
F_105 ( & V_21 -> V_234 ,
V_235 | V_236 | V_237 ) ;
F_22 ( & V_21 -> V_238 , 0 ) ;
F_106 ( & V_21 -> V_238 ,
V_235 | V_236 | V_237 ) ;
F_99 ( V_2 , V_2 -> V_229 + V_230 , & V_226 ) ;
V_226 |= V_231 ;
F_100 ( V_2 , V_2 -> V_229 + V_230 , V_226 ) ;
return 0 ;
}
static void F_107 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_221 ;
int V_47 ;
F_106 ( & V_21 -> V_239 , V_240 ) ;
for ( V_47 = 0 ; V_47 < 150 ; V_47 ++ ) {
V_221 = F_7 ( & V_21 -> V_222 ) ;
if ( V_221 ) {
F_22 ( & V_21 -> V_222 , V_221 ) ;
break;
}
F_108 ( 1000 ) ;
}
}
static void F_109 ( struct V_9 * V_10 )
{
F_107 ( V_10 ) ;
}
static int F_110 ( void )
{
struct V_9 * V_10 , * V_241 ;
F_111 (hose, tmp, &hose_list, list_node)
F_109 ( V_10 ) ;
return 0 ;
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_221 ;
int V_47 ;
F_106 ( & V_21 -> V_239 , V_242 ) ;
for ( V_47 = 0 ; V_47 < 150 ; V_47 ++ ) {
V_221 = F_7 ( & V_21 -> V_222 ) ;
if ( V_221 ) {
F_22 ( & V_21 -> V_222 , V_221 ) ;
break;
}
F_108 ( 1000 ) ;
}
F_23 ( V_10 ) ;
}
static void F_113 ( void )
{
struct V_9 * V_10 , * V_241 ;
F_111 (hose, tmp, &hose_list, list_node)
F_112 ( V_10 ) ;
}
void F_114 ( struct V_9 * V_243 )
{
#ifdef F_115
F_96 ( V_243 ) ;
#endif
}
static int F_116 ( struct V_122 * V_123 )
{
struct V_128 * V_244 ;
int V_155 ;
V_244 = V_123 -> V_2 . V_129 ;
V_155 = F_41 ( V_123 , V_217 == V_244 ) ;
F_117 ( V_123 ) ;
return 0 ;
}
static int T_6 F_118 ( void )
{
#ifdef F_115
F_119 ( & V_245 ) ;
#endif
return F_120 ( & V_246 ) ;
}
