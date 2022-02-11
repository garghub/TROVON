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
if ( F_14 ( V_2 ) && V_39 >= V_41 * 2 - 1 ) {
F_15 ( V_2 , & V_42 ) ;
F_16 ( V_2 , V_41 ) ;
}
* V_2 -> V_39 = V_39 ;
return 0 ;
}
static int F_17 ( struct V_20 T_3 * V_21 ,
unsigned int V_43 , const struct V_44 * V_45 ,
T_5 V_30 )
{
T_5 V_46 = V_45 -> V_47 - V_30 ;
T_5 V_48 = V_45 -> V_47 ;
T_5 V_49 = F_18 ( V_45 ) ;
T_2 V_50 = 0x80044000 ;
unsigned int V_51 ;
F_19 ( L_1 ,
( T_4 ) V_45 -> V_47 , ( T_4 ) V_49 ) ;
if ( V_45 -> V_50 & V_52 )
V_50 |= 0x10000000 ;
for ( V_51 = 0 ; V_49 > 0 ; V_51 ++ ) {
unsigned int V_53 = F_20 ( T_2 , F_21 ( V_49 ) ,
F_22 ( V_46 | V_48 ) ) ;
if ( V_43 + V_51 >= 5 )
return - 1 ;
F_23 ( & V_21 -> pow [ V_43 + V_51 ] . V_54 , V_46 >> 12 ) ;
F_23 ( & V_21 -> pow [ V_43 + V_51 ] . V_55 , ( T_4 ) V_46 >> 44 ) ;
F_23 ( & V_21 -> pow [ V_43 + V_51 ] . V_56 , V_48 >> 12 ) ;
F_23 ( & V_21 -> pow [ V_43 + V_51 ] . V_57 , V_50 | ( V_53 - 1 ) ) ;
V_46 += ( T_5 ) 1U << V_53 ;
V_48 += ( T_5 ) 1U << V_53 ;
V_49 -= ( T_5 ) 1U << V_53 ;
}
return V_51 ;
}
static bool F_24 ( void )
{
struct V_58 * V_59 ;
V_59 = F_25 ( NULL , L_2 ) ;
if ( ! V_59 ) {
F_26 ( 1 ) ;
return false ;
}
return F_27 ( V_59 , L_3 ) ;
}
static void F_28 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
int V_51 , V_60 , V_61 , V_62 , V_63 = 3 , V_64 = 1 , V_65 = 4 ;
T_4 V_66 , V_67 , V_68 = 0 ;
T_4 V_30 = 0 , V_69 = V_70 ;
T_2 V_71 = 0 , V_72 ;
T_2 V_73 = V_74 | V_75 | V_76 |
V_77 | V_78 ;
const T_4 * V_79 ;
int V_31 ;
bool V_80 ;
V_80 = ! F_24 () ;
if ( F_29 ( V_10 -> V_81 , L_4 ) ) {
V_73 &= ~ V_76 ;
}
if ( F_30 ( V_10 , 0 , 0 , V_82 ) ) {
if ( F_7 ( & V_21 -> V_83 ) >= V_84 ) {
V_63 = 2 ;
V_64 = 0 ;
V_65 = 3 ;
}
}
for( V_51 = 1 ; V_51 < 5 ; V_51 ++ )
F_23 ( & V_21 -> pow [ V_51 ] . V_57 , 0 ) ;
if ( V_80 ) {
for ( V_51 = V_64 ; V_51 < V_65 ; V_51 ++ )
F_23 ( & V_21 -> V_85 [ V_51 ] . V_73 , 0 ) ;
}
for( V_51 = 0 , V_60 = 1 ; V_51 < 3 ; V_51 ++ ) {
if ( ! ( V_10 -> V_86 [ V_51 ] . V_50 & V_87 ) )
continue;
V_69 = F_31 ( V_69 , ( T_4 ) V_10 -> V_86 [ V_51 ] . V_47 ) ;
V_68 = F_32 ( V_68 , ( T_4 ) V_10 -> V_86 [ V_51 ] . V_88 ) ;
V_30 = V_10 -> V_89 [ V_51 ] ;
V_61 = F_17 ( V_21 , V_60 , & V_10 -> V_86 [ V_51 ] , V_30 ) ;
if ( V_61 < 0 || V_60 >= 5 ) {
F_33 ( L_5 , V_51 ) ;
V_10 -> V_86 [ V_51 ] . V_50 |= V_90 ;
} else
V_60 += V_61 ;
}
if ( V_10 -> V_91 . V_50 & V_92 ) {
if ( V_60 >= 5 ) {
F_33 ( L_6 ) ;
} else {
F_19 ( L_7
L_8 ,
( T_4 ) V_10 -> V_91 . V_47 ,
( T_4 ) F_18 ( & V_10 -> V_91 ) ,
( T_4 ) V_10 -> V_93 ) ;
F_23 ( & V_21 -> pow [ V_60 ] . V_54 , ( V_10 -> V_91 . V_47 >> 12 ) ) ;
F_23 ( & V_21 -> pow [ V_60 ] . V_55 , 0 ) ;
F_23 ( & V_21 -> pow [ V_60 ] . V_56 , ( V_10 -> V_93 >> 12 ) ) ;
F_23 ( & V_21 -> pow [ V_60 ] . V_57 , 0x80088000
| ( F_21 ( V_10 -> V_91 . V_88
- V_10 -> V_91 . V_47 + 1 ) - 1 ) ) ;
}
}
V_68 -= V_30 ;
V_69 -= V_30 ;
if ( V_68 == V_69 ) {
F_33 ( L_9 , V_10 -> V_81 ) ;
return;
}
if ( V_69 == 0 ) {
F_33 ( L_10 , V_10 -> V_81 ) ;
return;
}
F_34 ( V_10 , 0 , 0 , V_94 , 0xffffffff ) ;
F_6 ( V_10 , 0 , 0 , V_94 , & V_72 ) ;
V_72 = ~ V_72 + 1 ;
if ( V_68 < ( 0x100000000ull - V_72 ) ||
( V_69 > 0x100000000ull ) )
V_71 = 0x100000000ull - V_72 ;
else
V_71 = ( V_69 - V_72 ) & - V_72 ;
F_34 ( V_10 , 0 , 0 , V_94 , V_71 ) ;
V_69 = F_31 ( V_69 , ( T_4 ) V_71 ) ;
F_35 ( L_11 , V_10 -> V_81 , V_71 ) ;
V_66 = F_36 () ;
F_35 ( L_12 , V_95 , V_66 ) ;
V_79 = F_37 ( V_10 -> V_81 , L_13 , & V_31 ) ;
if ( V_79 && ( V_31 == sizeof( T_4 ) ) ) {
T_4 V_96 = F_38 ( V_79 ) ;
if ( ( V_96 >= V_66 ) && ( V_96 < ( V_66 + V_97 ) ) ) {
F_35 ( L_14 , V_10 -> V_81 ) ;
V_66 += V_97 ;
} else {
F_39 ( L_15
L_16 , V_10 -> V_81 , V_96 ) ;
}
}
V_67 = F_31 ( V_66 , V_69 ) ;
V_62 = F_21 ( V_67 ) ;
if ( F_30 ( V_10 , 0 , 0 , V_82 ) ) {
if ( ( 1ull << V_62 ) != V_66 ) {
V_62 ++ ;
if ( ( 1ull << V_62 ) > V_66 )
F_35 ( L_17
L_18 , V_10 -> V_81 ) ;
}
V_73 |= ( ( V_62 - 1 ) & V_98 ) ;
if ( V_80 ) {
F_23 ( & V_21 -> V_85 [ V_63 ] . V_99 , 0x00000000 ) ;
F_23 ( & V_21 -> V_85 [ V_63 ] . V_100 , 0x00000000 ) ;
F_23 ( & V_21 -> V_85 [ V_63 ] . V_73 , V_73 ) ;
}
V_63 -- ;
V_10 -> V_101 = 0x00000000 ;
V_10 -> V_102 = ( T_5 ) V_67 ;
if ( V_67 != V_66 ) {
V_62 = F_21 ( V_66 ) ;
if ( ( 1ull << V_62 ) != V_66 )
V_62 ++ ;
V_73 = ( V_73 & ~ V_98 ) | ( V_62 - 1 ) ;
V_41 = 1ULL << V_62 ;
if ( V_80 ) {
F_23 ( & V_21 -> V_85 [ V_63 ] . V_99 , 0x00000000 ) ;
F_23 ( & V_21 -> V_85 [ V_63 ] . V_103 ,
V_41 >> 44 ) ;
F_23 ( & V_21 -> V_85 [ V_63 ] . V_100 ,
V_41 >> 12 ) ;
F_23 ( & V_21 -> V_85 [ V_63 ] . V_73 , V_73 ) ;
}
V_104 . V_105 = F_12 ;
F_35 ( L_19 , V_10 -> V_81 ) ;
}
} else {
T_4 V_106 = 0 ;
if ( V_80 ) {
F_23 ( & V_21 -> V_85 [ V_63 ] . V_99 , V_106 >> 12 ) ;
F_23 ( & V_21 -> V_85 [ V_63 ] . V_100 , V_106 >> 12 ) ;
F_23 ( & V_21 -> V_85 [ V_63 ] . V_73 ,
( V_73 | ( V_62 - 1 ) ) ) ;
}
V_63 -- ;
V_106 += 1ull << V_62 ;
V_67 -= 1ull << V_62 ;
if ( V_67 ) {
V_62 = F_21 ( V_67 ) ;
V_73 |= ( V_62 - 1 ) ;
if ( V_80 ) {
F_23 ( & V_21 -> V_85 [ V_63 ] . V_99 ,
V_106 >> 12 ) ;
F_23 ( & V_21 -> V_85 [ V_63 ] . V_100 ,
V_106 >> 12 ) ;
F_23 ( & V_21 -> V_85 [ V_63 ] . V_73 , V_73 ) ;
}
V_63 -- ;
V_106 += 1ull << V_62 ;
}
V_10 -> V_101 = 0x00000000 ;
V_10 -> V_102 = ( T_5 ) V_106 ;
}
if ( V_10 -> V_102 < V_66 ) {
#ifdef F_40
V_33 = 1 ;
#else
F_33 ( L_20
L_21 ,
V_10 -> V_81 ) ;
#endif
if ( V_68 < 0xffffffffull )
F_41 ( L_22
L_23
L_24 ,
V_10 -> V_81 ) ;
F_35 ( L_25 , V_10 -> V_81 ,
( T_4 ) V_10 -> V_102 ) ;
}
}
static void T_6 F_42 ( struct V_9 * V_10 )
{
T_7 V_107 ;
int V_108 ;
F_43 ( V_10 , 0 , 0 , V_109 , & V_107 ) ;
V_107 |= V_110 | V_111 | V_112
| V_113 ;
F_44 ( V_10 , 0 , 0 , V_109 , V_107 ) ;
V_108 = F_30 ( V_10 , 0 , 0 , V_114 ) ;
if ( V_108 ) {
int V_115 = V_108 + V_116 ;
V_107 = V_117 | V_118
| V_119 | V_120 ;
F_44 ( V_10 , 0 , 0 , V_115 , V_107 ) ;
} else {
F_45 ( V_10 , 0 , 0 , V_121 , 0x80 ) ;
}
}
void F_46 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
int V_51 , V_122 = 0 , V_123 ;
if ( V_8 )
V_122 = F_30 ( V_10 , 0 , 0 , V_82 ) ;
V_123 = ! ! ( V_10 -> V_12 & V_32 ) ;
if ( V_28 -> V_124 == V_10 -> V_28 && ( V_122 || V_123 ) ) {
for ( V_51 = 0 ; V_51 < V_125 ; ++ V_51 ) {
struct V_44 * V_45 = V_28 -> V_44 [ V_51 ] ;
struct V_44 * V_126 ;
if ( ! V_45 )
continue;
if ( V_51 == 0 )
V_126 = & V_10 -> V_91 ;
else if ( V_51 < 4 )
V_126 = & V_10 -> V_86 [ V_51 - 1 ] ;
else V_126 = NULL ;
V_45 -> V_47 = V_126 ? V_126 -> V_47 : 0 ;
V_45 -> V_88 = V_126 ? V_126 -> V_88 : 0 ;
V_45 -> V_50 = V_126 ? V_126 -> V_50 : 0 ;
}
}
}
int F_47 ( struct V_127 * V_128 , int V_129 )
{
int V_31 ;
struct V_9 * V_10 ;
struct V_44 V_130 ;
const int * V_131 ;
T_1 V_3 , V_132 ;
struct V_58 * V_2 ;
struct V_20 T_3 * V_21 ;
T_7 V_133 ;
T_2 V_134 = F_48 ( V_135 ) ;
V_2 = V_128 -> V_2 . V_136 ;
if ( ! F_49 ( V_2 ) ) {
F_41 ( L_26 , V_2 ) ;
return - V_137 ;
}
F_19 ( L_27 , V_2 ) ;
if ( F_50 ( V_2 , 0 , & V_130 ) ) {
F_51 ( V_138 L_28 ) ;
return - V_139 ;
}
V_131 = F_37 ( V_2 , L_29 , & V_31 ) ;
if ( V_131 == NULL || V_31 < 2 * sizeof( int ) )
F_51 ( V_138 L_30
L_31 , V_2 ) ;
F_52 ( V_140 ) ;
V_10 = F_53 ( V_2 ) ;
if ( ! V_10 )
return - V_139 ;
V_10 -> V_124 = & V_128 -> V_2 ;
V_10 -> V_17 = V_131 ? V_131 [ 0 ] : 0x0 ;
V_10 -> V_141 = V_131 ? V_131 [ 1 ] : 0xff ;
F_19 ( L_32 ,
( T_4 ) V_130 . V_47 , ( T_4 ) F_18 ( & V_130 ) ) ;
V_21 = V_10 -> V_22 = F_54 ( V_130 . V_47 , F_18 ( & V_130 ) ) ;
if ( ! V_10 -> V_22 )
goto V_142;
F_55 ( V_10 , V_130 . V_47 , V_130 . V_47 + 0x4 ,
V_143 ) ;
if ( F_7 ( & V_21 -> V_83 ) < V_144 )
V_10 -> V_12 |= V_13 ;
if ( F_30 ( V_10 , 0 , 0 , V_82 ) ) {
V_10 -> V_14 = & V_145 ;
F_56 ( V_10 , 0 , 0 , V_4 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_5 )
goto V_142;
} else {
F_56 ( V_10 , 0 , 0 , V_146 , & V_132 ) ;
if ( ( V_132 & 1 ) &&
! F_27 ( V_2 , L_33 ) )
goto V_142;
}
F_42 ( V_10 ) ;
if ( F_30 ( V_10 , 0 , 0 , V_82 ) ) {
V_10 -> V_12 |= V_147 |
V_148 ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
} else {
#define F_57 0x44
#define F_58 0x400
if ( ( ( F_59 ( V_134 ) == V_149 ) ||
( F_59 ( V_134 ) == V_150 ) ||
( F_59 ( V_134 ) == V_151 ) ||
( F_59 ( V_134 ) == V_152 ) ) &&
! F_30 ( V_10 , 0 , 0 , V_114 ) ) {
F_43 ( V_10 , 0 , 0 ,
F_57 , & V_133 ) ;
V_133 |= F_58 ;
F_44 ( V_10 , 0 , 0 ,
F_57 , V_133 ) ;
}
}
F_51 ( V_153 L_34
L_35 ,
( unsigned long long ) V_130 . V_47 , V_10 -> V_17 ,
V_10 -> V_141 ) ;
F_19 ( L_36 ,
V_10 , V_10 -> V_154 , V_10 -> V_155 ) ;
F_60 ( V_10 , V_2 , V_129 ) ;
F_28 ( V_10 ) ;
F_10 ( V_10 ) ;
return 0 ;
V_142:
F_61 ( V_10 -> V_22 ) ;
if ( ( ( unsigned long ) V_10 -> V_155 & V_156 ) !=
( ( unsigned long ) V_10 -> V_154 & V_156 ) )
F_61 ( V_10 -> V_155 ) ;
F_61 ( V_10 -> V_154 ) ;
F_62 ( V_10 ) ;
return - V_137 ;
}
static int F_63 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_10 -> V_12 & V_32 )
return V_157 ;
if ( V_28 -> V_158 == V_10 -> V_17 ||
V_28 -> V_159 == V_10 -> V_17 ) {
if ( V_29 & 0xf8 )
return V_157 ;
}
if ( V_104 . V_160 ) {
if ( V_104 . V_160 ( V_10 , V_28 -> V_158 , V_29 ) )
return V_157 ;
}
return V_161 ;
}
static void T_3 * F_64 ( struct V_27 * V_28 ,
unsigned int V_29 , int V_30 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
struct V_162 * V_163 = V_10 -> V_81 -> V_164 ;
T_2 V_165 = V_28 -> V_158 << 24 | V_29 << 16 ;
int V_166 ;
V_166 = F_63 ( V_28 , V_29 ) ;
if ( V_166 )
return NULL ;
V_30 &= 0xfff ;
if ( V_28 -> V_158 == V_10 -> V_17 )
return V_163 -> V_167 + V_30 ;
if ( V_163 -> V_165 == V_165 )
goto V_168;
F_65 ( V_163 -> V_167 + V_169 , V_165 ) ;
V_163 -> V_165 = V_165 ;
V_168:
return V_163 -> V_170 + V_30 ;
}
static int F_66 ( struct V_27 * V_28 , unsigned int V_29 ,
int V_30 , int V_31 , T_2 V_11 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_30 == V_171 && V_28 -> V_158 == V_10 -> V_17 )
V_11 &= 0xffffff00 ;
return F_67 ( V_28 , V_29 , V_30 , V_31 , V_11 ) ;
}
static int T_6 F_68 ( struct V_9 * V_10 ,
struct V_44 * V_79 )
{
struct V_162 * V_163 ;
T_2 V_172 ;
int V_166 = - V_139 ;
V_163 = F_69 ( sizeof( * V_163 ) , V_173 ) ;
if ( ! V_163 )
return V_166 ;
V_163 -> V_167 = F_54 ( V_79 -> V_47 , F_18 ( V_79 ) ) ;
if ( ! V_163 -> V_167 )
goto V_174;
V_172 = F_70 ( V_163 -> V_167 + V_175 ) ;
if ( ! V_172 ) {
V_166 = - V_137 ;
goto V_176;
}
V_163 -> V_170 = F_54 ( V_172 , 0x1000 ) ;
if ( ! V_163 -> V_170 )
goto V_176;
F_71 ( V_10 -> V_81 -> V_164 ) ;
V_10 -> V_81 -> V_164 = V_163 ;
V_10 -> V_14 = & V_177 ;
V_10 -> V_12 |= V_13 ;
F_65 ( V_163 -> V_167 + V_178 , 0 ) ;
F_65 ( V_163 -> V_167 + V_169 , 0 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
return 0 ;
V_176:
F_61 ( V_163 -> V_167 ) ;
V_174:
F_72 ( V_163 ) ;
return V_166 ;
}
int T_6 F_73 ( struct V_58 * V_2 )
{
int V_166 ;
int V_31 ;
struct V_9 * V_10 ;
struct V_44 V_179 ;
struct V_44 V_180 ;
const int * V_131 ;
int V_159 ;
V_181 = 1 ;
if ( ! F_49 ( V_2 ) ) {
F_41 ( L_37 ,
V_2 ) ;
return - V_137 ;
}
F_19 ( L_27 , V_2 ) ;
if ( F_50 ( V_2 , 0 , & V_179 ) ) {
F_51 ( V_138 L_38 ) ;
return - V_139 ;
}
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
if ( F_50 ( V_2 , 1 , & V_180 ) ) {
F_51 ( V_138
L_39
L_40 ) ;
if ( ( V_179 . V_47 & 0xfffff ) == 0x8500 )
V_180 . V_47 = ( V_179 . V_47 & 0xfff00000 ) + 0x8300 ;
else if ( ( V_179 . V_47 & 0xfffff ) == 0x8600 )
V_180 . V_47 = ( V_179 . V_47 & 0xfff00000 ) + 0x8380 ;
}
if ( ( V_179 . V_47 & 0xfffff ) == 0x8500 )
V_159 = 1 ;
else
V_159 = 0 ;
V_131 = F_37 ( V_2 , L_29 , & V_31 ) ;
if ( V_131 == NULL || V_31 < 2 * sizeof( int ) ) {
F_51 ( V_138 L_30
L_31 , V_2 ) ;
}
F_52 ( V_140 ) ;
V_10 = F_53 ( V_2 ) ;
if ( ! V_10 )
return - V_139 ;
V_10 -> V_17 = V_131 ? V_131 [ 0 ] : 0 ;
V_10 -> V_141 = V_131 ? V_131 [ 1 ] : 0xff ;
if ( F_29 ( V_2 , L_41 ) ) {
V_166 = F_68 ( V_10 , & V_179 ) ;
if ( V_166 )
goto V_174;
} else {
F_55 ( V_10 , V_180 . V_47 ,
V_180 . V_47 + 4 , 0 ) ;
}
F_51 ( V_153 L_34
L_35 ,
( unsigned long long ) V_179 . V_47 , V_10 -> V_17 ,
V_10 -> V_141 ) ;
F_19 ( L_36 ,
V_10 , V_10 -> V_154 , V_10 -> V_155 ) ;
F_60 ( V_10 , V_2 , V_159 ) ;
return 0 ;
V_174:
F_62 ( V_10 ) ;
return V_166 ;
}
T_4 F_74 ( struct V_9 * V_10 )
{
#ifdef F_75
if ( V_181 ) {
struct V_162 * V_163 = V_10 -> V_81 -> V_164 ;
struct V_182 * V_183 ;
int V_51 ;
V_183 = V_163 -> V_167 + V_184 ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
if ( ! ( F_70 ( & V_183 [ V_51 ] . V_185 ) & V_186 ) )
continue;
if ( F_76 () == F_70 ( & V_183 [ V_51 ] . V_187 ) )
return ( T_4 ) F_70 ( & V_183 [ V_51 ] . V_188 ) << 32 |
F_70 ( & V_183 [ V_51 ] . V_189 ) ;
}
F_51 ( V_138 L_42 ) ;
}
#endif
#if F_77 ( V_190 ) || F_77 ( V_191 )
if ( ! V_181 ) {
T_2 V_192 ;
F_78 ( V_10 -> V_28 ,
F_79 ( 0 , 0 ) , V_94 , & V_192 ) ;
V_192 &= V_193 ;
return V_192 ;
}
#endif
return 0 ;
}
static int F_80 ( struct V_194 * V_195 , T_2 V_196 )
{
unsigned int V_197 , V_198 , V_199 , V_200 ;
V_197 = F_81 ( V_196 ) ;
V_198 = F_82 ( V_196 ) ;
V_199 = F_83 ( V_196 ) ;
V_200 = F_84 ( V_196 ) ;
switch ( F_85 ( V_196 ) ) {
case 31 :
switch ( F_86 ( V_196 ) ) {
case V_201 :
case V_202 :
V_195 -> V_203 [ V_197 ] = 0xffffffff ;
break;
case V_204 :
V_195 -> V_203 [ V_197 ] = 0xffffffff ;
V_195 -> V_203 [ V_198 ] += V_195 -> V_203 [ V_199 ] ;
break;
case V_205 :
V_195 -> V_203 [ V_197 ] = 0xff ;
break;
case V_206 :
V_195 -> V_203 [ V_197 ] = 0xff ;
V_195 -> V_203 [ V_198 ] += V_195 -> V_203 [ V_199 ] ;
break;
case V_207 :
case V_208 :
V_195 -> V_203 [ V_197 ] = 0xffff ;
break;
case V_209 :
V_195 -> V_203 [ V_197 ] = 0xffff ;
V_195 -> V_203 [ V_198 ] += V_195 -> V_203 [ V_199 ] ;
break;
case V_210 :
V_195 -> V_203 [ V_197 ] = ~ 0UL ;
break;
case V_211 :
V_195 -> V_203 [ V_197 ] = ~ 0UL ;
V_195 -> V_203 [ V_198 ] += V_195 -> V_203 [ V_199 ] ;
break;
default:
return 0 ;
}
break;
case V_212 :
V_195 -> V_203 [ V_197 ] = 0xffffffff ;
break;
case V_213 :
V_195 -> V_203 [ V_197 ] = 0xffffffff ;
V_195 -> V_203 [ V_198 ] += ( V_214 ) V_200 ;
break;
case V_215 :
V_195 -> V_203 [ V_197 ] = 0xff ;
break;
case V_216 :
V_195 -> V_203 [ V_197 ] = 0xff ;
V_195 -> V_203 [ V_198 ] += ( V_214 ) V_200 ;
break;
case V_217 :
V_195 -> V_203 [ V_197 ] = 0xffff ;
break;
case V_218 :
V_195 -> V_203 [ V_197 ] = 0xffff ;
V_195 -> V_203 [ V_198 ] += ( V_214 ) V_200 ;
break;
case V_219 :
V_195 -> V_203 [ V_197 ] = ~ 0UL ;
break;
case V_220 :
V_195 -> V_203 [ V_197 ] = ~ 0UL ;
V_195 -> V_203 [ V_198 ] += ( V_214 ) V_200 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_87 ( T_8 V_221 )
{
struct V_9 * V_10 ;
struct V_44 * V_45 ;
int V_51 ;
F_88 (hose, &hose_list, list_node) {
if ( ! ( V_10 -> V_12 & V_147 ) )
continue;
for ( V_51 = 0 ; V_51 < 3 ; V_51 ++ ) {
V_45 = & V_10 -> V_86 [ V_51 ] ;
if ( ( V_45 -> V_50 & V_87 ) &&
V_221 >= V_45 -> V_47 && V_221 <= V_45 -> V_88 )
return 1 ;
}
}
return 0 ;
}
int F_89 ( struct V_194 * V_195 )
{
T_2 V_196 ;
int V_166 ;
T_8 V_221 = 0 ;
if ( V_195 -> V_222 & V_223 )
return 0 ;
#ifdef F_90
V_221 = F_48 ( V_224 ) ;
V_221 <<= 32 ;
#endif
V_221 += F_48 ( V_225 ) ;
if ( F_87 ( V_221 ) ) {
if ( F_91 ( V_195 ) ) {
F_92 () ;
V_166 = F_93 ( V_195 -> V_226 , & V_196 ) ;
F_94 () ;
} else {
V_166 = F_95 ( ( void * ) V_195 -> V_226 , V_196 ) ;
}
if ( ! V_166 && F_80 ( V_195 , V_196 ) ) {
V_195 -> V_226 += 4 ;
return 1 ;
}
}
return 0 ;
}
void F_96 ( void )
{
struct V_58 * V_227 ;
if ( V_228 )
return;
V_227 = F_25 ( NULL , L_43 ) ;
while ( ( V_228 = F_97 ( V_227 ) ) ) {
F_98 ( V_227 ) ;
V_227 = V_228 ;
if ( F_99 ( V_229 , V_227 ) && F_49 ( V_227 ) )
return;
}
F_100 (np, pci_ids) {
if ( F_49 ( V_227 ) ) {
V_228 = V_227 ;
F_98 ( V_227 ) ;
return;
}
}
}
static T_9 F_101 ( int V_230 , void * V_231 )
{
struct V_9 * V_10 = V_231 ;
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_232 ;
V_232 = F_7 ( & V_21 -> V_233 ) ;
if ( ! V_232 )
return V_234 ;
F_23 ( & V_21 -> V_233 , V_232 ) ;
return V_235 ;
}
static int F_102 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 ;
struct V_1 * V_2 ;
int V_236 ;
int V_45 ;
T_7 V_237 ;
V_2 = F_103 ( & V_10 -> V_28 -> V_238 , F_104 ( * V_2 ) , V_239 ) ;
F_105 ( V_2 , V_2 -> V_240 + V_241 , & V_237 ) ;
V_237 &= ~ V_242 ;
F_106 ( V_2 , V_2 -> V_240 + V_241 , V_237 ) ;
V_236 = F_107 ( V_10 -> V_81 , 0 ) ;
if ( ! V_236 ) {
F_108 ( & V_2 -> V_2 , L_44 ) ;
return - V_243 ;
}
V_45 = F_109 ( V_10 -> V_124 , V_236 ,
F_101 ,
V_244 ,
L_45 , V_10 ) ;
if ( V_45 < 0 ) {
F_108 ( & V_2 -> V_2 , L_46 , V_236 ) ;
F_110 ( V_236 ) ;
return - V_137 ;
}
V_21 = V_10 -> V_22 ;
F_111 ( & V_21 -> V_245 ,
V_246 | V_247 | V_248 ) ;
F_23 ( & V_21 -> V_249 , 0 ) ;
F_112 ( & V_21 -> V_249 ,
V_246 | V_247 | V_248 ) ;
F_105 ( V_2 , V_2 -> V_240 + V_241 , & V_237 ) ;
V_237 |= V_242 ;
F_106 ( V_2 , V_2 -> V_240 + V_241 , V_237 ) ;
return 0 ;
}
static void F_113 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_232 ;
int V_51 ;
F_112 ( & V_21 -> V_250 , V_251 ) ;
for ( V_51 = 0 ; V_51 < 150 ; V_51 ++ ) {
V_232 = F_7 ( & V_21 -> V_233 ) ;
if ( V_232 ) {
F_23 ( & V_21 -> V_233 , V_232 ) ;
break;
}
F_114 ( 1000 ) ;
}
}
static void F_115 ( struct V_9 * V_10 )
{
F_113 ( V_10 ) ;
}
static int F_116 ( void )
{
struct V_9 * V_10 , * V_252 ;
F_117 (hose, tmp, &hose_list, list_node)
F_115 ( V_10 ) ;
return 0 ;
}
static void F_118 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_232 ;
int V_51 ;
F_112 ( & V_21 -> V_250 , V_253 ) ;
for ( V_51 = 0 ; V_51 < 150 ; V_51 ++ ) {
V_232 = F_7 ( & V_21 -> V_233 ) ;
if ( V_232 ) {
F_23 ( & V_21 -> V_233 , V_232 ) ;
break;
}
F_114 ( 1000 ) ;
}
F_28 ( V_10 ) ;
}
static void F_119 ( void )
{
struct V_9 * V_10 , * V_252 ;
F_117 (hose, tmp, &hose_list, list_node)
F_118 ( V_10 ) ;
}
void F_120 ( struct V_9 * V_254 )
{
#ifdef F_121
F_102 ( V_254 ) ;
#endif
}
static int F_122 ( struct V_127 * V_128 )
{
struct V_127 * V_255 ;
struct V_256 V_257 = {
. V_136 = V_128 -> V_2 . V_136
} ;
V_255 = F_123 ( & V_128 -> V_2 ,
L_47 ,
V_258 ,
V_128 -> V_44 ,
V_128 -> V_259 ,
& V_257 , sizeof( V_257 ) ) ;
if ( F_124 ( V_255 ) )
return F_125 ( V_255 ) ;
return 0 ;
}
static int F_126 ( struct V_127 * V_128 )
{
struct V_58 * V_59 ;
int V_166 ;
V_59 = V_128 -> V_2 . V_136 ;
V_166 = F_47 ( V_128 , V_228 == V_59 ) ;
if ( V_166 )
return V_166 ;
V_166 = F_122 ( V_128 ) ;
if ( V_166 )
F_108 ( & V_128 -> V_2 , L_48 ,
V_166 ) ;
return 0 ;
}
static int T_6 F_127 ( void )
{
#ifdef F_121
F_128 ( & V_260 ) ;
#endif
return F_129 ( & V_261 ) ;
}
