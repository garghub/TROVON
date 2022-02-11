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
if ( F_30 ( V_10 -> V_81 , L_4 ) ) {
V_74 &= ~ V_77 ;
}
if ( F_31 ( V_10 , 0 , 0 , V_85 ) ) {
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
V_70 = F_32 ( V_70 , ( T_4 ) V_10 -> V_89 [ V_52 ] . V_48 ) ;
V_69 = F_33 ( V_69 , ( T_4 ) V_10 -> V_89 [ V_52 ] . V_91 ) ;
V_30 = V_10 -> V_92 [ V_52 ] ;
V_62 = F_18 ( V_21 , V_61 , & V_10 -> V_89 [ V_52 ] , V_30 ) ;
if ( V_62 < 0 || V_61 >= 5 ) {
F_34 ( L_5 , V_52 ) ;
V_10 -> V_89 [ V_52 ] . V_51 |= V_93 ;
} else
V_61 += V_62 ;
}
if ( V_10 -> V_94 . V_51 & V_95 ) {
if ( V_61 >= 5 ) {
F_34 ( L_6 ) ;
} else {
F_20 ( L_7
L_8 ,
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
F_34 ( L_9 , V_80 ) ;
return;
}
if ( V_70 == 0 ) {
F_34 ( L_10 , V_80 ) ;
return;
}
F_35 ( V_10 , 0 , 0 , V_97 , 0xffffffff ) ;
F_6 ( V_10 , 0 , 0 , V_97 , & V_73 ) ;
V_73 = ~ V_73 + 1 ;
if ( V_69 < ( 0x100000000ull - V_73 ) ||
( V_70 > 0x100000000ull ) )
V_72 = 0x100000000ull - V_73 ;
else
V_72 = ( V_70 - V_73 ) & - V_73 ;
F_35 ( V_10 , 0 , 0 , V_97 , V_72 ) ;
V_70 = F_32 ( V_70 , ( T_4 ) V_72 ) ;
F_36 ( L_11 , V_80 , V_72 ) ;
V_67 = F_37 () ;
F_36 ( L_12 , V_98 , V_67 ) ;
V_83 = F_38 ( V_10 -> V_81 , L_13 , & V_31 ) ;
if ( V_83 && ( V_31 == sizeof( T_4 ) ) ) {
T_4 V_99 = F_39 ( V_83 ) ;
if ( ( V_99 >= V_67 ) && ( V_99 < ( V_67 + V_100 ) ) ) {
F_36 ( L_14 , V_80 ) ;
V_67 += V_100 ;
} else {
F_40 ( L_15
L_16 , V_80 , V_99 ) ;
}
}
V_68 = F_32 ( V_67 , V_70 ) ;
V_63 = F_22 ( V_68 ) ;
if ( F_31 ( V_10 , 0 , 0 , V_85 ) ) {
if ( ( 1ull << V_63 ) != V_67 ) {
V_63 ++ ;
if ( ( 1ull << V_63 ) > V_67 )
F_36 ( L_17
L_18 , V_80 ) ;
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
F_36 ( L_19 , V_80 ) ;
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
#ifdef F_41
V_33 = 1 ;
#else
F_34 ( L_20
L_21 ,
V_80 ) ;
#endif
if ( V_69 < 0xffffffffull )
F_42 ( L_22
L_23
L_24 ,
V_80 ) ;
F_36 ( L_25 , V_80 ,
( T_4 ) V_10 -> V_105 ) ;
}
}
static void T_6 F_43 ( struct V_9 * V_10 )
{
T_7 V_110 ;
int V_111 ;
F_44 ( V_10 , 0 , 0 , V_112 , & V_110 ) ;
V_110 |= V_113 | V_114 | V_115
| V_116 ;
F_45 ( V_10 , 0 , 0 , V_112 , V_110 ) ;
V_111 = F_31 ( V_10 , 0 , 0 , V_117 ) ;
if ( V_111 ) {
int V_118 = V_111 + V_119 ;
V_110 = V_120 | V_121
| V_122 | V_123 ;
F_45 ( V_10 , 0 , 0 , V_118 , V_110 ) ;
} else {
F_46 ( V_10 , 0 , 0 , V_124 , 0x80 ) ;
}
}
void F_47 ( struct V_27 * V_28 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
int V_52 , V_125 = 0 , V_126 ;
if ( V_8 )
V_125 = F_31 ( V_10 , 0 , 0 , V_85 ) ;
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
int F_48 ( struct V_130 * V_131 , int V_132 )
{
int V_31 ;
struct V_9 * V_10 ;
struct V_45 V_133 ;
const int * V_134 ;
T_1 V_3 , V_135 ;
struct V_59 * V_2 ;
struct V_20 T_3 * V_21 ;
T_7 V_136 ;
T_2 V_137 = F_49 ( V_138 ) ;
V_2 = V_131 -> V_2 . V_139 ;
if ( ! F_50 ( V_2 ) ) {
F_42 ( L_26 , V_2 -> V_82 ) ;
return - V_140 ;
}
F_20 ( L_27 , V_2 -> V_82 ) ;
if ( F_51 ( V_2 , 0 , & V_133 ) ) {
F_52 ( V_141 L_28 ) ;
return - V_142 ;
}
V_134 = F_38 ( V_2 , L_29 , & V_31 ) ;
if ( V_134 == NULL || V_31 < 2 * sizeof( int ) )
F_52 ( V_141 L_30
L_31 , V_2 -> V_82 ) ;
F_53 ( V_143 ) ;
V_10 = F_54 ( V_2 ) ;
if ( ! V_10 )
return - V_142 ;
V_10 -> V_127 = & V_131 -> V_2 ;
V_10 -> V_17 = V_134 ? V_134 [ 0 ] : 0x0 ;
V_10 -> V_144 = V_134 ? V_134 [ 1 ] : 0xff ;
F_20 ( L_32 ,
( T_4 ) V_133 . V_48 , ( T_4 ) F_19 ( & V_133 ) ) ;
V_21 = V_10 -> V_22 = F_55 ( V_133 . V_48 , F_19 ( & V_133 ) ) ;
if ( ! V_10 -> V_22 )
goto V_145;
F_56 ( V_10 , V_133 . V_48 , V_133 . V_48 + 0x4 ,
V_146 ) ;
if ( F_7 ( & V_21 -> V_86 ) < V_147 )
V_10 -> V_12 |= V_13 ;
if ( F_31 ( V_10 , 0 , 0 , V_85 ) ) {
V_10 -> V_14 = & V_148 ;
F_57 ( V_10 , 0 , 0 , V_4 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_5 )
goto V_145;
} else {
F_57 ( V_10 , 0 , 0 , V_149 , & V_135 ) ;
if ( ( V_135 & 1 ) &&
! F_28 ( V_2 , L_33 ) )
goto V_145;
}
F_43 ( V_10 ) ;
if ( F_31 ( V_10 , 0 , 0 , V_85 ) ) {
V_10 -> V_12 |= V_150 |
V_151 ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
} else {
#define F_58 0x44
#define F_59 0x400
if ( ( ( F_60 ( V_137 ) == V_152 ) ||
( F_60 ( V_137 ) == V_153 ) ||
( F_60 ( V_137 ) == V_154 ) ||
( F_60 ( V_137 ) == V_155 ) ) &&
! F_31 ( V_10 , 0 , 0 , V_117 ) ) {
F_44 ( V_10 , 0 , 0 ,
F_58 , & V_136 ) ;
V_136 |= F_59 ;
F_45 ( V_10 , 0 , 0 ,
F_58 , V_136 ) ;
}
}
F_52 ( V_156 L_34
L_35 ,
( unsigned long long ) V_133 . V_48 , V_10 -> V_17 ,
V_10 -> V_144 ) ;
F_20 ( L_36 ,
V_10 , V_10 -> V_157 , V_10 -> V_158 ) ;
F_61 ( V_10 , V_2 , V_132 ) ;
F_29 ( V_10 ) ;
F_10 ( V_10 ) ;
return 0 ;
V_145:
F_62 ( V_10 -> V_22 ) ;
if ( ( ( unsigned long ) V_10 -> V_158 & V_159 ) !=
( ( unsigned long ) V_10 -> V_157 & V_159 ) )
F_62 ( V_10 -> V_158 ) ;
F_62 ( V_10 -> V_157 ) ;
F_63 ( V_10 ) ;
return - V_140 ;
}
static int F_64 ( struct V_27 * V_28 , unsigned int V_29 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_10 -> V_12 & V_32 )
return V_160 ;
if ( V_28 -> V_161 == V_10 -> V_17 ||
V_28 -> V_162 == V_10 -> V_17 ) {
if ( V_29 & 0xf8 )
return V_160 ;
}
if ( V_107 . V_163 ) {
if ( V_107 . V_163 ( V_10 , V_28 -> V_161 , V_29 ) )
return V_160 ;
}
return V_164 ;
}
static void T_3 * F_65 ( struct V_27 * V_28 ,
unsigned int V_29 , int V_30 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
struct V_165 * V_166 = V_10 -> V_81 -> V_167 ;
T_2 V_168 = V_28 -> V_161 << 24 | V_29 << 16 ;
int V_169 ;
V_169 = F_64 ( V_28 , V_29 ) ;
if ( V_169 )
return NULL ;
V_30 &= 0xfff ;
if ( V_28 -> V_161 == V_10 -> V_17 )
return V_166 -> V_170 + V_30 ;
if ( V_166 -> V_168 == V_168 )
goto V_171;
F_66 ( V_166 -> V_170 + V_172 , V_168 ) ;
V_166 -> V_168 = V_168 ;
V_171:
return V_166 -> V_173 + V_30 ;
}
static int F_67 ( struct V_27 * V_28 , unsigned int V_29 ,
int V_30 , int V_31 , T_2 V_11 )
{
struct V_9 * V_10 = F_8 ( V_28 ) ;
if ( V_30 == V_174 && V_28 -> V_161 == V_10 -> V_17 )
V_11 &= 0xffffff00 ;
return F_68 ( V_28 , V_29 , V_30 , V_31 , V_11 ) ;
}
static int T_6 F_69 ( struct V_9 * V_10 ,
struct V_45 * V_83 )
{
struct V_165 * V_166 ;
T_2 V_175 ;
int V_169 = - V_142 ;
V_166 = F_70 ( sizeof( * V_166 ) , V_176 ) ;
if ( ! V_166 )
return V_169 ;
V_166 -> V_170 = F_55 ( V_83 -> V_48 , F_19 ( V_83 ) ) ;
if ( ! V_166 -> V_170 )
goto V_177;
V_175 = F_71 ( V_166 -> V_170 + V_178 ) ;
if ( ! V_175 ) {
V_169 = - V_140 ;
goto V_179;
}
V_166 -> V_173 = F_55 ( V_175 , 0x1000 ) ;
if ( ! V_166 -> V_173 )
goto V_179;
F_72 ( V_10 -> V_81 -> V_167 ) ;
V_10 -> V_81 -> V_167 = V_166 ;
V_10 -> V_14 = & V_180 ;
V_10 -> V_12 |= V_13 ;
F_66 ( V_166 -> V_170 + V_181 , 0 ) ;
F_66 ( V_166 -> V_170 + V_172 , 0 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_32 ;
return 0 ;
V_179:
F_62 ( V_166 -> V_170 ) ;
V_177:
F_73 ( V_166 ) ;
return V_169 ;
}
int T_6 F_74 ( struct V_59 * V_2 )
{
int V_169 ;
int V_31 ;
struct V_9 * V_10 ;
struct V_45 V_182 ;
struct V_45 V_183 ;
const int * V_134 ;
int V_162 ;
V_184 = 1 ;
if ( ! F_50 ( V_2 ) ) {
F_42 ( L_37 ,
V_2 -> V_82 ) ;
return - V_140 ;
}
F_20 ( L_27 , V_2 -> V_82 ) ;
if ( F_51 ( V_2 , 0 , & V_182 ) ) {
F_52 ( V_141 L_38 ) ;
return - V_142 ;
}
memset ( & V_183 , 0 , sizeof( V_183 ) ) ;
if ( F_51 ( V_2 , 1 , & V_183 ) ) {
F_52 ( V_141
L_39
L_40 ) ;
if ( ( V_182 . V_48 & 0xfffff ) == 0x8500 )
V_183 . V_48 = ( V_182 . V_48 & 0xfff00000 ) + 0x8300 ;
else if ( ( V_182 . V_48 & 0xfffff ) == 0x8600 )
V_183 . V_48 = ( V_182 . V_48 & 0xfff00000 ) + 0x8380 ;
}
if ( ( V_182 . V_48 & 0xfffff ) == 0x8500 )
V_162 = 1 ;
else
V_162 = 0 ;
V_134 = F_38 ( V_2 , L_29 , & V_31 ) ;
if ( V_134 == NULL || V_31 < 2 * sizeof( int ) ) {
F_52 ( V_141 L_30
L_31 , V_2 -> V_82 ) ;
}
F_53 ( V_143 ) ;
V_10 = F_54 ( V_2 ) ;
if ( ! V_10 )
return - V_142 ;
V_10 -> V_17 = V_134 ? V_134 [ 0 ] : 0 ;
V_10 -> V_144 = V_134 ? V_134 [ 1 ] : 0xff ;
if ( F_30 ( V_2 , L_41 ) ) {
V_169 = F_69 ( V_10 , & V_182 ) ;
if ( V_169 )
goto V_177;
} else {
F_56 ( V_10 , V_183 . V_48 ,
V_183 . V_48 + 4 , 0 ) ;
}
F_52 ( V_156 L_34
L_35 ,
( unsigned long long ) V_182 . V_48 , V_10 -> V_17 ,
V_10 -> V_144 ) ;
F_20 ( L_36 ,
V_10 , V_10 -> V_157 , V_10 -> V_158 ) ;
F_61 ( V_10 , V_2 , V_162 ) ;
return 0 ;
V_177:
F_63 ( V_10 ) ;
return V_169 ;
}
T_4 F_75 ( struct V_9 * V_10 )
{
#ifdef F_76
if ( V_184 ) {
struct V_165 * V_166 = V_10 -> V_81 -> V_167 ;
struct V_185 * V_186 ;
int V_52 ;
V_186 = V_166 -> V_170 + V_187 ;
for ( V_52 = 0 ; V_52 < 4 ; V_52 ++ ) {
if ( ! ( F_71 ( & V_186 [ V_52 ] . V_188 ) & V_189 ) )
continue;
if ( F_77 () == F_71 ( & V_186 [ V_52 ] . V_190 ) )
return ( T_4 ) F_71 ( & V_186 [ V_52 ] . V_191 ) << 32 |
F_71 ( & V_186 [ V_52 ] . V_192 ) ;
}
F_52 ( V_141 L_42 ) ;
}
#endif
#if F_78 ( V_193 ) || F_78 ( V_194 )
if ( ! V_184 ) {
T_2 V_195 ;
F_79 ( V_10 -> V_28 ,
F_80 ( 0 , 0 ) , V_97 , & V_195 ) ;
V_195 &= V_196 ;
return V_195 ;
}
#endif
return 0 ;
}
static int F_81 ( struct V_197 * V_198 , T_2 V_199 )
{
unsigned int V_200 , V_201 , V_202 , V_203 ;
V_200 = F_82 ( V_199 ) ;
V_201 = F_83 ( V_199 ) ;
V_202 = F_84 ( V_199 ) ;
V_203 = F_85 ( V_199 ) ;
switch ( F_86 ( V_199 ) ) {
case 31 :
switch ( F_87 ( V_199 ) ) {
case V_204 :
case V_205 :
V_198 -> V_206 [ V_200 ] = 0xffffffff ;
break;
case V_207 :
V_198 -> V_206 [ V_200 ] = 0xffffffff ;
V_198 -> V_206 [ V_201 ] += V_198 -> V_206 [ V_202 ] ;
break;
case V_208 :
V_198 -> V_206 [ V_200 ] = 0xff ;
break;
case V_209 :
V_198 -> V_206 [ V_200 ] = 0xff ;
V_198 -> V_206 [ V_201 ] += V_198 -> V_206 [ V_202 ] ;
break;
case V_210 :
case V_211 :
V_198 -> V_206 [ V_200 ] = 0xffff ;
break;
case V_212 :
V_198 -> V_206 [ V_200 ] = 0xffff ;
V_198 -> V_206 [ V_201 ] += V_198 -> V_206 [ V_202 ] ;
break;
case V_213 :
V_198 -> V_206 [ V_200 ] = ~ 0UL ;
break;
case V_214 :
V_198 -> V_206 [ V_200 ] = ~ 0UL ;
V_198 -> V_206 [ V_201 ] += V_198 -> V_206 [ V_202 ] ;
break;
default:
return 0 ;
}
break;
case V_215 :
V_198 -> V_206 [ V_200 ] = 0xffffffff ;
break;
case V_216 :
V_198 -> V_206 [ V_200 ] = 0xffffffff ;
V_198 -> V_206 [ V_201 ] += ( V_217 ) V_203 ;
break;
case V_218 :
V_198 -> V_206 [ V_200 ] = 0xff ;
break;
case V_219 :
V_198 -> V_206 [ V_200 ] = 0xff ;
V_198 -> V_206 [ V_201 ] += ( V_217 ) V_203 ;
break;
case V_220 :
V_198 -> V_206 [ V_200 ] = 0xffff ;
break;
case V_221 :
V_198 -> V_206 [ V_200 ] = 0xffff ;
V_198 -> V_206 [ V_201 ] += ( V_217 ) V_203 ;
break;
case V_222 :
V_198 -> V_206 [ V_200 ] = ~ 0UL ;
break;
case V_223 :
V_198 -> V_206 [ V_200 ] = ~ 0UL ;
V_198 -> V_206 [ V_201 ] += ( V_217 ) V_203 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_88 ( T_8 V_224 )
{
struct V_9 * V_10 ;
struct V_45 * V_46 ;
int V_52 ;
F_89 (hose, &hose_list, list_node) {
if ( ! ( V_10 -> V_12 & V_150 ) )
continue;
for ( V_52 = 0 ; V_52 < 3 ; V_52 ++ ) {
V_46 = & V_10 -> V_89 [ V_52 ] ;
if ( ( V_46 -> V_51 & V_90 ) &&
V_224 >= V_46 -> V_48 && V_224 <= V_46 -> V_91 )
return 1 ;
}
}
return 0 ;
}
int F_90 ( struct V_197 * V_198 )
{
T_2 V_199 ;
int V_169 ;
T_8 V_224 = 0 ;
if ( V_198 -> V_225 & V_226 )
return 0 ;
#ifdef F_91
V_224 = F_49 ( V_227 ) ;
V_224 <<= 32 ;
#endif
V_224 += F_49 ( V_228 ) ;
if ( F_88 ( V_224 ) ) {
if ( F_92 ( V_198 ) ) {
F_93 () ;
V_169 = F_94 ( V_198 -> V_229 , & V_199 ) ;
F_95 () ;
} else {
V_169 = F_96 ( ( void * ) V_198 -> V_229 , V_199 ) ;
}
if ( ! V_169 && F_81 ( V_198 , V_199 ) ) {
V_198 -> V_229 += 4 ;
return 1 ;
}
}
return 0 ;
}
void F_97 ( void )
{
struct V_59 * V_230 ;
if ( V_231 )
return;
V_230 = F_26 ( NULL , L_43 ) ;
while ( ( V_231 = F_98 ( V_230 ) ) ) {
F_99 ( V_230 ) ;
V_230 = V_231 ;
if ( F_100 ( V_232 , V_230 ) && F_50 ( V_230 ) )
return;
}
F_101 (np, pci_ids) {
if ( F_50 ( V_230 ) ) {
V_231 = V_230 ;
F_99 ( V_230 ) ;
return;
}
}
}
static T_9 F_102 ( int V_233 , void * V_234 )
{
struct V_9 * V_10 = V_234 ;
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_235 ;
V_235 = F_7 ( & V_21 -> V_236 ) ;
if ( ! V_235 )
return V_237 ;
F_24 ( & V_21 -> V_236 , V_235 ) ;
return V_238 ;
}
static int F_103 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 ;
struct V_1 * V_2 ;
int V_239 ;
int V_46 ;
T_7 V_240 ;
V_2 = F_104 ( & V_10 -> V_28 -> V_241 , F_105 ( * V_2 ) , V_242 ) ;
F_106 ( V_2 , V_2 -> V_243 + V_244 , & V_240 ) ;
V_240 &= ~ V_245 ;
F_107 ( V_2 , V_2 -> V_243 + V_244 , V_240 ) ;
V_239 = F_108 ( V_10 -> V_81 , 0 ) ;
if ( ! V_239 ) {
F_109 ( & V_2 -> V_2 , L_44 ) ;
return - V_246 ;
}
V_46 = F_110 ( V_10 -> V_127 , V_239 ,
F_102 ,
V_247 ,
L_45 , V_10 ) ;
if ( V_46 < 0 ) {
F_109 ( & V_2 -> V_2 , L_46 , V_239 ) ;
F_111 ( V_239 ) ;
return - V_140 ;
}
V_21 = V_10 -> V_22 ;
F_112 ( & V_21 -> V_248 ,
V_249 | V_250 | V_251 ) ;
F_24 ( & V_21 -> V_252 , 0 ) ;
F_113 ( & V_21 -> V_252 ,
V_249 | V_250 | V_251 ) ;
F_106 ( V_2 , V_2 -> V_243 + V_244 , & V_240 ) ;
V_240 |= V_245 ;
F_107 ( V_2 , V_2 -> V_243 + V_244 , V_240 ) ;
return 0 ;
}
static void F_114 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_235 ;
int V_52 ;
F_113 ( & V_21 -> V_253 , V_254 ) ;
for ( V_52 = 0 ; V_52 < 150 ; V_52 ++ ) {
V_235 = F_7 ( & V_21 -> V_236 ) ;
if ( V_235 ) {
F_24 ( & V_21 -> V_236 , V_235 ) ;
break;
}
F_115 ( 1000 ) ;
}
}
static void F_116 ( struct V_9 * V_10 )
{
F_114 ( V_10 ) ;
}
static int F_117 ( void )
{
struct V_9 * V_10 , * V_255 ;
F_118 (hose, tmp, &hose_list, list_node)
F_116 ( V_10 ) ;
return 0 ;
}
static void F_119 ( struct V_9 * V_10 )
{
struct V_20 T_3 * V_21 = V_10 -> V_22 ;
T_2 V_235 ;
int V_52 ;
F_113 ( & V_21 -> V_253 , V_256 ) ;
for ( V_52 = 0 ; V_52 < 150 ; V_52 ++ ) {
V_235 = F_7 ( & V_21 -> V_236 ) ;
if ( V_235 ) {
F_24 ( & V_21 -> V_236 , V_235 ) ;
break;
}
F_115 ( 1000 ) ;
}
F_29 ( V_10 ) ;
}
static void F_120 ( void )
{
struct V_9 * V_10 , * V_255 ;
F_118 (hose, tmp, &hose_list, list_node)
F_119 ( V_10 ) ;
}
void F_121 ( struct V_9 * V_257 )
{
#ifdef F_122
F_103 ( V_257 ) ;
#endif
}
static int F_123 ( struct V_130 * V_131 )
{
struct V_130 * V_258 ;
struct V_259 V_260 = {
. V_139 = V_131 -> V_2 . V_139
} ;
V_258 = F_124 ( & V_131 -> V_2 ,
L_47 ,
V_261 ,
V_131 -> V_45 ,
V_131 -> V_262 ,
& V_260 , sizeof( V_260 ) ) ;
if ( F_125 ( V_258 ) )
return F_126 ( V_258 ) ;
return 0 ;
}
static int F_127 ( struct V_130 * V_131 )
{
struct V_59 * V_60 ;
int V_169 ;
V_60 = V_131 -> V_2 . V_139 ;
V_169 = F_48 ( V_131 , V_231 == V_60 ) ;
if ( V_169 )
return V_169 ;
V_169 = F_123 ( V_131 ) ;
if ( V_169 )
F_109 ( & V_131 -> V_2 , L_48 ,
V_169 ) ;
return 0 ;
}
static int T_6 F_128 ( void )
{
#ifdef F_122
F_129 ( & V_263 ) ;
#endif
return F_130 ( & V_264 ) ;
}
