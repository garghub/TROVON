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
static void F_25 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
int V_52 , V_59 , V_60 , V_61 , V_62 = 3 , V_63 = 1 , V_64 = 4 ;
T_4 V_65 , V_66 , V_67 = 0 ;
T_4 V_30 = 0 , V_68 = V_69 ;
T_2 V_70 = 0 , V_71 ;
T_2 V_72 = V_73 | V_74 | V_75 |
V_76 | V_77 ;
const char * V_78 = V_10 -> V_79 -> V_80 ;
const T_4 * V_81 ;
int V_31 ;
if ( F_26 ( V_10 , 0 , 0 , V_82 ) ) {
if ( F_7 ( & V_21 -> V_83 ) >= V_84 ) {
V_62 = 2 ;
V_63 = 0 ;
V_64 = 3 ;
}
}
for( V_52 = 1 ; V_52 < 5 ; V_52 ++ )
F_24 ( & V_21 -> pow [ V_52 ] . V_58 , 0 ) ;
for ( V_52 = V_63 ; V_52 < V_64 ; V_52 ++ )
F_24 ( & V_21 -> V_85 [ V_52 ] . V_72 , 0 ) ;
for( V_52 = 0 , V_59 = 1 ; V_52 < 3 ; V_52 ++ ) {
if ( ! ( V_10 -> V_86 [ V_52 ] . V_51 & V_87 ) )
continue;
V_68 = F_27 ( V_68 , ( T_4 ) V_10 -> V_86 [ V_52 ] . V_48 ) ;
V_67 = F_28 ( V_67 , ( T_4 ) V_10 -> V_86 [ V_52 ] . V_88 ) ;
V_30 = V_10 -> V_89 [ V_52 ] ;
V_60 = F_18 ( V_21 , V_59 , & V_10 -> V_86 [ V_52 ] , V_30 ) ;
if ( V_60 < 0 || V_59 >= 5 ) {
F_29 ( L_2 , V_52 ) ;
V_10 -> V_86 [ V_52 ] . V_51 |= V_90 ;
} else
V_59 += V_60 ;
}
if ( V_10 -> V_91 . V_51 & V_92 ) {
if ( V_59 >= 5 ) {
F_29 ( L_3 ) ;
} else {
F_20 ( L_4
L_5 ,
( T_4 ) V_10 -> V_91 . V_48 ,
( T_4 ) F_19 ( & V_10 -> V_91 ) ,
( T_4 ) V_10 -> V_93 ) ;
F_24 ( & V_21 -> pow [ V_59 ] . V_55 , ( V_10 -> V_91 . V_48 >> 12 ) ) ;
F_24 ( & V_21 -> pow [ V_59 ] . V_56 , 0 ) ;
F_24 ( & V_21 -> pow [ V_59 ] . V_57 , ( V_10 -> V_93 >> 12 ) ) ;
F_24 ( & V_21 -> pow [ V_59 ] . V_58 , 0x80088000
| ( F_22 ( V_10 -> V_91 . V_88
- V_10 -> V_91 . V_48 + 1 ) - 1 ) ) ;
}
}
V_67 -= V_30 ;
V_68 -= V_30 ;
if ( V_67 == V_68 ) {
F_29 ( L_6 , V_78 ) ;
return;
}
if ( V_68 == 0 ) {
F_29 ( L_7 , V_78 ) ;
return;
}
F_30 ( V_10 , 0 , 0 , V_94 , 0xffffffff ) ;
F_6 ( V_10 , 0 , 0 , V_94 , & V_71 ) ;
V_71 = ~ V_71 + 1 ;
if ( V_67 < ( 0x100000000ull - V_71 ) ||
( V_68 > 0x100000000ull ) )
V_70 = 0x100000000ull - V_71 ;
else
V_70 = ( V_68 - V_71 ) & - V_71 ;
F_30 ( V_10 , 0 , 0 , V_94 , V_70 ) ;
V_68 = F_27 ( V_68 , ( T_4 ) V_70 ) ;
F_31 ( L_8 , V_78 , V_70 ) ;
V_65 = F_32 () ;
V_81 = F_33 ( V_10 -> V_79 , L_9 , & V_31 ) ;
if ( V_81 && ( V_31 == sizeof( T_4 ) ) ) {
T_4 V_95 = F_34 ( V_81 ) ;
if ( ( V_95 >= V_65 ) && ( V_95 < ( V_65 + V_96 ) ) ) {
F_31 ( L_10 , V_78 ) ;
V_65 += V_96 ;
} else {
F_35 ( L_11
L_12 , V_78 , V_95 ) ;
}
}
V_66 = F_27 ( V_65 , V_68 ) ;
V_61 = F_22 ( V_66 ) ;
if ( F_26 ( V_10 , 0 , 0 , V_82 ) ) {
if ( ( 1ull << V_61 ) != V_65 ) {
V_61 ++ ;
if ( ( 1ull << V_61 ) > V_65 )
F_31 ( L_13
L_14 , V_78 ) ;
}
V_72 |= ( ( V_61 - 1 ) & V_97 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_98 , 0x00000000 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_99 , 0x00000000 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_72 , V_72 ) ;
V_62 -- ;
V_10 -> V_100 = 0x00000000 ;
V_10 -> V_101 = ( T_5 ) V_66 ;
if ( V_66 != V_65 ) {
V_61 = F_22 ( V_65 ) ;
if ( ( 1ull << V_61 ) != V_65 )
V_61 ++ ;
V_72 = ( V_72 & ~ V_97 ) | ( V_61 - 1 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_98 , 0x00000000 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_102 ,
V_43 >> 44 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_99 ,
V_43 >> 12 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_72 , V_72 ) ;
V_103 . V_104 = F_12 ;
F_31 ( L_15 , V_78 ) ;
}
} else {
T_4 V_105 = 0 ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_98 , V_105 >> 12 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_99 , V_105 >> 12 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_72 , ( V_72 | ( V_61 - 1 ) ) ) ;
V_62 -- ;
V_105 += 1ull << V_61 ;
V_66 -= 1ull << V_61 ;
if ( V_66 ) {
V_61 = F_22 ( V_66 ) ;
V_72 |= ( V_61 - 1 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_98 , V_105 >> 12 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_99 , V_105 >> 12 ) ;
F_24 ( & V_21 -> V_85 [ V_62 ] . V_72 , V_72 ) ;
V_62 -- ;
V_105 += 1ull << V_61 ;
}
V_10 -> V_100 = 0x00000000 ;
V_10 -> V_101 = ( T_5 ) V_105 ;
}
if ( V_10 -> V_101 < V_65 ) {
#ifdef F_36
V_33 = 1 ;
#else
F_29 ( L_16
L_17 ,
V_78 ) ;
#endif
if ( V_67 < 0xffffffffull )
F_37 ( L_18
L_19
L_20 ,
V_78 ) ;
F_31 ( L_21 , V_78 ,
( T_4 ) V_10 -> V_101 ) ;
}
}
static void T_6 F_38 ( struct V_9 * V_10 )
{
T_7 V_106 ;
int V_107 ;
F_39 ( V_10 , 0 , 0 , V_108 , & V_106 ) ;
V_106 |= V_109 | V_110 | V_111
| V_112 ;
F_40 ( V_10 , 0 , 0 , V_108 , V_106 ) ;
V_107 = F_26 ( V_10 , 0 , 0 , V_113 ) ;
if ( V_107 ) {
int V_114 = V_107 + V_115 ;
V_106 = V_116 | V_117
| V_118 | V_119 ;
F_40 ( V_10 , 0 , 0 , V_114 , V_106 ) ;
} else {
F_41 ( V_10 , 0 , 0 , V_120 , 0x80 ) ;
}
}
void F_42 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
int V_52 , V_121 = 0 , V_122 ;
if ( V_8 )
V_121 = F_26 ( V_10 , 0 , 0 , V_82 ) ;
V_122 = ! ! ( V_10 -> V_12 & V_32 ) ;
if ( V_28 -> V_123 == V_10 -> V_28 && ( V_121 || V_122 ) ) {
for ( V_52 = 0 ; V_52 < V_124 ; ++ V_52 ) {
struct V_45 * V_46 = V_28 -> V_45 [ V_52 ] ;
struct V_45 * V_125 ;
if ( ! V_46 )
continue;
if ( V_52 == 0 )
V_125 = & V_10 -> V_91 ;
else if ( V_52 < 4 )
V_125 = & V_10 -> V_86 [ V_52 - 1 ] ;
else V_125 = NULL ;
V_46 -> V_48 = V_125 ? V_125 -> V_48 : 0 ;
V_46 -> V_88 = V_125 ? V_125 -> V_88 : 0 ;
V_46 -> V_51 = V_125 ? V_125 -> V_51 : 0 ;
}
}
}
int F_43 ( struct V_126 * V_127 , int V_128 )
{
int V_31 ;
struct V_9 * V_10 ;
struct V_45 V_129 ;
const int * V_130 ;
T_1 V_3 , V_131 ;
struct V_132 * V_2 ;
struct V_20 T_3 * V_21 ;
V_2 = V_127 -> V_2 . V_133 ;
if ( ! F_44 ( V_2 ) ) {
F_37 ( L_22 , V_2 -> V_80 ) ;
return - V_134 ;
}
F_20 ( L_23 , V_2 -> V_80 ) ;
if ( F_45 ( V_2 , 0 , & V_129 ) ) {
F_46 ( V_135 L_24 ) ;
return - V_136 ;
}
V_130 = F_33 ( V_2 , L_25 , & V_31 ) ;
if ( V_130 == NULL || V_31 < 2 * sizeof( int ) )
F_46 ( V_135 L_26
L_27 , V_2 -> V_80 ) ;
F_47 ( V_137 ) ;
V_10 = F_48 ( V_2 ) ;
if ( ! V_10 )
return - V_136 ;
V_10 -> V_123 = & V_127 -> V_2 ;
V_10 -> V_17 = V_130 ? V_130 [ 0 ] : 0x0 ;
V_10 -> V_138 = V_130 ? V_130 [ 1 ] : 0xff ;
F_20 ( L_28 ,
( T_4 ) V_129 . V_48 , ( T_4 ) F_19 ( & V_129 ) ) ;
V_21 = V_10 -> V_22 = F_49 ( V_129 . V_48 , F_19 ( & V_129 ) ) ;
if ( ! V_10 -> V_22 )
goto V_139;
F_50 ( V_10 , V_129 . V_48 , V_129 . V_48 + 0x4 ,
V_140 ) ;
if ( F_7 ( & V_21 -> V_83 ) < V_141 )
V_10 -> V_12 |= V_13 ;
if ( F_26 ( V_10 , 0 , 0 , V_82 ) ) {
V_10 -> V_14 = & V_142 ;
F_51 ( V_10 , 0 , 0 , V_4 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_5 )
goto V_139;
} else {
F_51 ( V_10 , 0 , 0 , V_143 , & V_131 ) ;
if ( ( V_131 & 1 ) &&
! F_52 ( V_2 , L_29 ) )
goto V_139;
}
F_38 ( V_10 ) ;
if ( F_26 ( V_10 , 0 , 0 , V_82 ) ) {
V_10 -> V_12 |= V_144 |
V_145 ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
}
F_46 ( V_146 L_30
L_31 ,
( unsigned long long ) V_129 . V_48 , V_10 -> V_17 ,
V_10 -> V_138 ) ;
F_20 ( L_32 ,
V_10 , V_10 -> V_147 , V_10 -> V_148 ) ;
F_53 ( V_10 , V_2 , V_128 ) ;
F_25 ( V_10 ) ;
F_10 ( V_10 ) ;
return 0 ;
V_139:
F_54 ( V_10 -> V_22 ) ;
if ( ( ( unsigned long ) V_10 -> V_148 & V_149 ) !=
( ( unsigned long ) V_10 -> V_147 & V_149 ) )
F_54 ( V_10 -> V_148 ) ;
F_54 ( V_10 -> V_147 ) ;
F_55 ( V_10 ) ;
return - V_134 ;
}
static int F_56 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_10 -> V_12 & V_32 )
return V_150 ;
if ( V_28 -> V_151 == V_10 -> V_17 ||
V_28 -> V_152 == V_10 -> V_17 ) {
if ( V_29 & 0xf8 )
return V_150 ;
}
if ( V_103 . V_153 ) {
if ( V_103 . V_153 ( V_10 , V_28 -> V_151 , V_29 ) )
return V_150 ;
}
return V_154 ;
}
static void T_3 * F_57 ( struct V_27 * V_28 ,
unsigned int V_29 , int V_30 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
struct V_155 * V_156 = V_10 -> V_79 -> V_157 ;
T_2 V_158 = V_28 -> V_151 << 24 | V_29 << 16 ;
int V_159 ;
V_159 = F_56 ( V_28 , V_29 ) ;
if ( V_159 )
return NULL ;
V_30 &= 0xfff ;
if ( V_28 -> V_151 == V_10 -> V_17 )
return V_156 -> V_160 + V_30 ;
if ( V_156 -> V_158 == V_158 )
goto V_161;
F_58 ( V_156 -> V_160 + V_162 , V_158 ) ;
V_156 -> V_158 = V_158 ;
V_161:
return V_156 -> V_163 + V_30 ;
}
static int F_59 ( struct V_27 * V_28 , unsigned int V_29 ,
int V_30 , int V_31 , T_2 V_11 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_30 == V_164 && V_28 -> V_151 == V_10 -> V_17 )
V_11 &= 0xffffff00 ;
return F_60 ( V_28 , V_29 , V_30 , V_31 , V_11 ) ;
}
static int T_6 F_61 ( struct V_9 * V_10 ,
struct V_45 * V_81 )
{
struct V_155 * V_156 ;
T_2 V_165 ;
int V_159 = - V_136 ;
V_156 = F_62 ( sizeof( * V_156 ) , V_166 ) ;
if ( ! V_156 )
return V_159 ;
V_156 -> V_160 = F_49 ( V_81 -> V_48 , F_19 ( V_81 ) ) ;
if ( ! V_156 -> V_160 )
goto V_167;
V_165 = F_63 ( V_156 -> V_160 + V_168 ) ;
if ( ! V_165 ) {
V_159 = - V_134 ;
goto V_169;
}
V_156 -> V_163 = F_49 ( V_165 , 0x1000 ) ;
if ( ! V_156 -> V_163 )
goto V_169;
F_64 ( V_10 -> V_79 -> V_157 ) ;
V_10 -> V_79 -> V_157 = V_156 ;
V_10 -> V_14 = & V_170 ;
V_10 -> V_12 |= V_13 ;
F_58 ( V_156 -> V_160 + V_171 , 0 ) ;
F_58 ( V_156 -> V_160 + V_162 , 0 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
return 0 ;
V_169:
F_54 ( V_156 -> V_160 ) ;
V_167:
F_65 ( V_156 ) ;
return V_159 ;
}
int T_6 F_66 ( struct V_132 * V_2 )
{
int V_159 ;
int V_31 ;
struct V_9 * V_10 ;
struct V_45 V_172 ;
struct V_45 V_173 ;
const int * V_130 ;
int V_152 ;
V_174 = 1 ;
if ( ! F_44 ( V_2 ) ) {
F_37 ( L_33 ,
V_2 -> V_80 ) ;
return - V_134 ;
}
F_20 ( L_23 , V_2 -> V_80 ) ;
if ( F_45 ( V_2 , 0 , & V_172 ) ) {
F_46 ( V_135 L_34 ) ;
return - V_136 ;
}
memset ( & V_173 , 0 , sizeof( V_173 ) ) ;
if ( F_45 ( V_2 , 1 , & V_173 ) ) {
F_46 ( V_135
L_35
L_36 ) ;
if ( ( V_172 . V_48 & 0xfffff ) == 0x8500 )
V_173 . V_48 = ( V_172 . V_48 & 0xfff00000 ) + 0x8300 ;
else if ( ( V_172 . V_48 & 0xfffff ) == 0x8600 )
V_173 . V_48 = ( V_172 . V_48 & 0xfff00000 ) + 0x8380 ;
}
if ( ( V_172 . V_48 & 0xfffff ) == 0x8500 )
V_152 = 1 ;
else
V_152 = 0 ;
V_130 = F_33 ( V_2 , L_25 , & V_31 ) ;
if ( V_130 == NULL || V_31 < 2 * sizeof( int ) ) {
F_46 ( V_135 L_26
L_27 , V_2 -> V_80 ) ;
}
F_47 ( V_137 ) ;
V_10 = F_48 ( V_2 ) ;
if ( ! V_10 )
return - V_136 ;
V_10 -> V_17 = V_130 ? V_130 [ 0 ] : 0 ;
V_10 -> V_138 = V_130 ? V_130 [ 1 ] : 0xff ;
if ( F_67 ( V_2 , L_37 ) ) {
V_159 = F_61 ( V_10 , & V_172 ) ;
if ( V_159 )
goto V_167;
} else {
F_50 ( V_10 , V_173 . V_48 ,
V_173 . V_48 + 4 , 0 ) ;
}
F_46 ( V_146 L_30
L_31 ,
( unsigned long long ) V_172 . V_48 , V_10 -> V_17 ,
V_10 -> V_138 ) ;
F_20 ( L_32 ,
V_10 , V_10 -> V_147 , V_10 -> V_148 ) ;
F_53 ( V_10 , V_2 , V_152 ) ;
return 0 ;
V_167:
F_55 ( V_10 ) ;
return V_159 ;
}
T_4 F_68 ( struct V_9 * V_10 )
{
#ifdef F_69
if ( V_174 ) {
struct V_155 * V_156 = V_10 -> V_79 -> V_157 ;
struct V_175 * V_176 ;
int V_52 ;
V_176 = V_156 -> V_160 + V_177 ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
if ( ! ( F_63 ( & V_176 [ V_52 ] . V_178 ) & V_179 ) )
continue;
if ( F_70 () == F_63 ( & V_176 [ V_52 ] . V_180 ) )
return ( T_4 ) F_63 ( & V_176 [ V_52 ] . V_181 ) << 32 |
F_63 ( & V_176 [ V_52 ] . V_182 ) ;
}
F_46 ( V_135 L_38 ) ;
}
#endif
#if F_71 ( V_183 ) || F_71 ( V_184 )
if ( ! V_174 ) {
T_2 V_185 ;
F_72 ( V_10 -> V_28 ,
F_73 ( 0 , 0 ) , V_94 , & V_185 ) ;
V_185 &= V_186 ;
return V_185 ;
}
#endif
return 0 ;
}
static int F_74 ( struct V_187 * V_188 , T_2 V_189 )
{
unsigned int V_190 , V_191 , V_192 , V_193 ;
V_190 = F_75 ( V_189 ) ;
V_191 = F_76 ( V_189 ) ;
V_192 = F_77 ( V_189 ) ;
V_193 = F_78 ( V_189 ) ;
switch ( F_79 ( V_189 ) ) {
case 31 :
switch ( F_80 ( V_189 ) ) {
case V_194 :
case V_195 :
V_188 -> V_196 [ V_190 ] = 0xffffffff ;
break;
case V_197 :
V_188 -> V_196 [ V_190 ] = 0xffffffff ;
V_188 -> V_196 [ V_191 ] += V_188 -> V_196 [ V_192 ] ;
break;
case V_198 :
V_188 -> V_196 [ V_190 ] = 0xff ;
break;
case V_199 :
V_188 -> V_196 [ V_190 ] = 0xff ;
V_188 -> V_196 [ V_191 ] += V_188 -> V_196 [ V_192 ] ;
break;
case V_200 :
case V_201 :
V_188 -> V_196 [ V_190 ] = 0xffff ;
break;
case V_202 :
V_188 -> V_196 [ V_190 ] = 0xffff ;
V_188 -> V_196 [ V_191 ] += V_188 -> V_196 [ V_192 ] ;
break;
case V_203 :
V_188 -> V_196 [ V_190 ] = ~ 0UL ;
break;
case V_204 :
V_188 -> V_196 [ V_190 ] = ~ 0UL ;
V_188 -> V_196 [ V_191 ] += V_188 -> V_196 [ V_192 ] ;
break;
default:
return 0 ;
}
break;
case V_205 :
V_188 -> V_196 [ V_190 ] = 0xffffffff ;
break;
case V_206 :
V_188 -> V_196 [ V_190 ] = 0xffffffff ;
V_188 -> V_196 [ V_191 ] += ( V_207 ) V_193 ;
break;
case V_208 :
V_188 -> V_196 [ V_190 ] = 0xff ;
break;
case V_209 :
V_188 -> V_196 [ V_190 ] = 0xff ;
V_188 -> V_196 [ V_191 ] += ( V_207 ) V_193 ;
break;
case V_210 :
V_188 -> V_196 [ V_190 ] = 0xffff ;
break;
case V_211 :
V_188 -> V_196 [ V_190 ] = 0xffff ;
V_188 -> V_196 [ V_191 ] += ( V_207 ) V_193 ;
break;
case V_212 :
V_188 -> V_196 [ V_190 ] = ~ 0UL ;
break;
case V_213 :
V_188 -> V_196 [ V_190 ] = ~ 0UL ;
V_188 -> V_196 [ V_191 ] += ( V_207 ) V_193 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_81 ( T_8 V_214 )
{
struct V_9 * V_10 ;
struct V_45 * V_46 ;
int V_52 ;
F_82 (hose, &hose_list, list_node) {
if ( ! ( V_10 -> V_12 & V_144 ) )
continue;
for ( V_52 = 0 ; V_52 < 3 ; V_52 ++ ) {
V_46 = & V_10 -> V_86 [ V_52 ] ;
if ( ( V_46 -> V_51 & V_87 ) &&
V_214 >= V_46 -> V_48 && V_214 <= V_46 -> V_88 )
return 1 ;
}
}
return 0 ;
}
int F_83 ( struct V_187 * V_188 )
{
T_2 V_189 ;
int V_159 ;
T_8 V_214 = 0 ;
if ( V_188 -> V_215 & V_216 )
return 0 ;
#ifdef F_84
V_214 = F_85 ( V_217 ) ;
V_214 <<= 32 ;
#endif
V_214 += F_85 ( V_218 ) ;
if ( F_81 ( V_214 ) ) {
if ( F_86 ( V_188 ) ) {
F_87 () ;
V_159 = F_88 ( V_188 -> V_219 , & V_189 ) ;
F_89 () ;
} else {
V_159 = F_90 ( V_188 -> V_219 , V_189 ) ;
}
if ( F_74 ( V_188 , V_189 ) ) {
V_188 -> V_219 += 4 ;
return 1 ;
}
}
return 0 ;
}
void F_91 ( void )
{
struct V_132 * V_220 ;
if ( V_221 )
return;
V_220 = F_92 ( NULL , L_39 ) ;
while ( ( V_221 = F_93 ( V_220 ) ) ) {
F_94 ( V_220 ) ;
V_220 = V_221 ;
if ( F_95 ( V_222 , V_220 ) && F_44 ( V_220 ) )
return;
}
F_96 (np, pci_ids) {
if ( F_44 ( V_220 ) ) {
V_221 = V_220 ;
F_94 ( V_220 ) ;
return;
}
}
}
static T_9 F_97 ( int V_223 , void * V_224 )
{
struct V_9 * V_10 = V_224 ;
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_225 ;
V_225 = F_7 ( & V_21 -> V_226 ) ;
if ( ! V_225 )
return V_227 ;
F_24 ( & V_21 -> V_226 , V_225 ) ;
return V_228 ;
}
static int F_98 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 ;
struct V_1 * V_2 ;
int V_229 ;
int V_46 ;
T_7 V_230 ;
V_2 = F_99 ( & V_10 -> V_28 -> V_231 , F_100 ( * V_2 ) , V_232 ) ;
F_101 ( V_2 , V_2 -> V_233 + V_234 , & V_230 ) ;
V_230 &= ~ V_235 ;
F_102 ( V_2 , V_2 -> V_233 + V_234 , V_230 ) ;
V_229 = F_103 ( V_10 -> V_79 , 0 ) ;
if ( ! V_229 ) {
F_104 ( & V_2 -> V_2 , L_40 ) ;
return - V_236 ;
}
V_46 = F_105 ( V_10 -> V_123 , V_229 ,
F_97 ,
V_237 ,
L_41 , V_10 ) ;
if ( V_46 < 0 ) {
F_104 ( & V_2 -> V_2 , L_42 , V_229 ) ;
F_106 ( V_229 ) ;
return - V_134 ;
}
V_21 = V_10 -> V_22 ;
F_107 ( & V_21 -> V_238 ,
V_239 | V_240 | V_241 ) ;
F_24 ( & V_21 -> V_242 , 0 ) ;
F_108 ( & V_21 -> V_242 ,
V_239 | V_240 | V_241 ) ;
F_101 ( V_2 , V_2 -> V_233 + V_234 , & V_230 ) ;
V_230 |= V_235 ;
F_102 ( V_2 , V_2 -> V_233 + V_234 , V_230 ) ;
return 0 ;
}
static void F_109 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_225 ;
int V_52 ;
F_108 ( & V_21 -> V_243 , V_244 ) ;
for ( V_52 = 0 ; V_52 < 150 ; V_52 ++ ) {
V_225 = F_7 ( & V_21 -> V_226 ) ;
if ( V_225 ) {
F_24 ( & V_21 -> V_226 , V_225 ) ;
break;
}
F_110 ( 1000 ) ;
}
}
static void F_111 ( struct V_9 * V_10 )
{
F_109 ( V_10 ) ;
}
static int F_112 ( void )
{
struct V_9 * V_10 , * V_245 ;
F_113 (hose, tmp, &hose_list, list_node)
F_111 ( V_10 ) ;
return 0 ;
}
static void F_114 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_225 ;
int V_52 ;
F_108 ( & V_21 -> V_243 , V_246 ) ;
for ( V_52 = 0 ; V_52 < 150 ; V_52 ++ ) {
V_225 = F_7 ( & V_21 -> V_226 ) ;
if ( V_225 ) {
F_24 ( & V_21 -> V_226 , V_225 ) ;
break;
}
F_110 ( 1000 ) ;
}
F_25 ( V_10 ) ;
}
static void F_115 ( void )
{
struct V_9 * V_10 , * V_245 ;
F_113 (hose, tmp, &hose_list, list_node)
F_114 ( V_10 ) ;
}
void F_116 ( struct V_9 * V_247 )
{
#ifdef F_117
F_98 ( V_247 ) ;
#endif
}
static int F_118 ( struct V_126 * V_127 )
{
struct V_132 * V_248 ;
int V_159 ;
V_248 = V_127 -> V_2 . V_133 ;
V_159 = F_43 ( V_127 , V_221 == V_248 ) ;
F_119 ( V_127 ) ;
return 0 ;
}
static int T_6 F_120 ( void )
{
#ifdef F_117
F_121 ( & V_249 ) ;
#endif
return F_122 ( & V_250 ) ;
}
