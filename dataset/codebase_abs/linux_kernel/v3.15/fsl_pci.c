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
if ( V_10 -> V_14 -> V_15 == V_16 ) {
struct V_17 V_18 ;
V_18 . V_19 = V_10 -> V_20 ;
V_18 . V_21 = V_10 ;
V_18 . V_14 = V_10 -> V_14 ;
F_5 ( & V_18 , 0 , V_22 , 4 , & V_11 ) ;
} else
F_6 ( V_10 , 0 , 0 , V_22 , & V_11 ) ;
if ( V_11 < V_23 )
return 1 ;
} else {
struct V_24 T_3 * V_25 = V_10 -> V_26 ;
V_11 = ( F_7 ( & V_25 -> V_27 ) & V_28 )
>> V_29 ;
if ( V_11 != V_30 )
return 1 ;
}
return 0 ;
}
static int V_16 ( struct V_17 * V_18 , unsigned int V_31 ,
int V_32 , int V_33 , T_2 * V_11 )
{
struct V_9 * V_10 = F_8 ( V_18 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_34 ;
else
V_10 -> V_12 &= ~ V_34 ;
return F_5 ( V_18 , V_31 , V_32 , V_33 , V_11 ) ;
}
static int F_9 ( struct V_35 * V_2 , T_4 V_36 )
{
if ( ! V_2 -> V_36 || ! F_10 ( V_2 , V_36 ) )
return - V_37 ;
if ( ( F_11 ( V_2 ) ) &&
V_36 >= F_12 ( V_38 ) ) {
F_13 ( V_2 , & V_39 ) ;
F_14 ( V_2 , V_40 ) ;
}
* V_2 -> V_36 = V_36 ;
return 0 ;
}
static int F_15 ( struct V_24 T_3 * V_25 ,
unsigned int V_41 , const struct V_42 * V_43 ,
T_5 V_32 )
{
T_5 V_44 = V_43 -> V_45 - V_32 ;
T_5 V_46 = V_43 -> V_45 ;
T_5 V_47 = F_16 ( V_43 ) ;
T_2 V_48 = 0x80044000 ;
unsigned int V_49 ;
F_17 ( L_1 ,
( T_4 ) V_43 -> V_45 , ( T_4 ) V_47 ) ;
if ( V_43 -> V_48 & V_50 )
V_48 |= 0x10000000 ;
for ( V_49 = 0 ; V_47 > 0 ; V_49 ++ ) {
unsigned int V_51 = F_18 ( F_19 ( V_47 ) ,
F_20 ( V_44 | V_46 ) ) ;
if ( V_41 + V_49 >= 5 )
return - 1 ;
F_21 ( & V_25 -> pow [ V_41 + V_49 ] . V_52 , V_44 >> 12 ) ;
F_21 ( & V_25 -> pow [ V_41 + V_49 ] . V_53 , ( T_4 ) V_44 >> 44 ) ;
F_21 ( & V_25 -> pow [ V_41 + V_49 ] . V_54 , V_46 >> 12 ) ;
F_21 ( & V_25 -> pow [ V_41 + V_49 ] . V_55 , V_48 | ( V_51 - 1 ) ) ;
V_44 += ( T_5 ) 1U << V_51 ;
V_46 += ( T_5 ) 1U << V_51 ;
V_47 -= ( T_5 ) 1U << V_51 ;
}
return V_49 ;
}
static void F_22 ( struct V_9 * V_10 )
{
struct V_24 T_3 * V_25 = V_10 -> V_26 ;
int V_49 , V_56 , V_57 , V_58 , V_59 = 3 , V_60 = 1 , V_61 = 4 ;
T_4 V_62 , V_63 , V_64 = 0 ;
T_4 V_32 = 0 , V_65 = V_66 ;
T_2 V_67 = 0 , V_68 ;
T_2 V_69 = V_70 | V_71 | V_72 |
V_73 | V_74 ;
const char * V_75 = V_10 -> V_76 -> V_77 ;
const T_4 * V_78 ;
int V_33 ;
if ( F_23 ( V_10 , 0 , 0 , V_79 ) ) {
if ( F_7 ( & V_25 -> V_80 ) >= V_81 ) {
V_59 = 2 ;
V_60 = 0 ;
V_61 = 3 ;
}
}
for( V_49 = 1 ; V_49 < 5 ; V_49 ++ )
F_21 ( & V_25 -> pow [ V_49 ] . V_55 , 0 ) ;
for ( V_49 = V_60 ; V_49 < V_61 ; V_49 ++ )
F_21 ( & V_25 -> V_82 [ V_49 ] . V_69 , 0 ) ;
for( V_49 = 0 , V_56 = 1 ; V_49 < 3 ; V_49 ++ ) {
if ( ! ( V_10 -> V_83 [ V_49 ] . V_48 & V_84 ) )
continue;
V_65 = F_18 ( V_65 , ( T_4 ) V_10 -> V_83 [ V_49 ] . V_45 ) ;
V_64 = F_24 ( V_64 , ( T_4 ) V_10 -> V_83 [ V_49 ] . V_85 ) ;
V_32 = V_10 -> V_86 [ V_49 ] ;
V_57 = F_15 ( V_25 , V_56 , & V_10 -> V_83 [ V_49 ] , V_32 ) ;
if ( V_57 < 0 || V_56 >= 5 ) {
F_25 ( L_2 , V_49 ) ;
V_10 -> V_83 [ V_49 ] . V_48 |= V_87 ;
} else
V_56 += V_57 ;
}
if ( V_10 -> V_88 . V_48 & V_89 ) {
if ( V_56 >= 5 ) {
F_25 ( L_3 ) ;
} else {
F_17 ( L_4
L_5 ,
( T_4 ) V_10 -> V_88 . V_45 ,
( T_4 ) F_16 ( & V_10 -> V_88 ) ,
( T_4 ) V_10 -> V_90 ) ;
F_21 ( & V_25 -> pow [ V_56 ] . V_52 , ( V_10 -> V_88 . V_45 >> 12 ) ) ;
F_21 ( & V_25 -> pow [ V_56 ] . V_53 , 0 ) ;
F_21 ( & V_25 -> pow [ V_56 ] . V_54 , ( V_10 -> V_90 >> 12 ) ) ;
F_21 ( & V_25 -> pow [ V_56 ] . V_55 , 0x80088000
| ( F_19 ( V_10 -> V_88 . V_85
- V_10 -> V_88 . V_45 + 1 ) - 1 ) ) ;
}
}
V_64 -= V_32 ;
V_65 -= V_32 ;
if ( V_64 == V_65 ) {
F_25 ( L_6 , V_75 ) ;
return;
}
if ( V_65 == 0 ) {
F_25 ( L_7 , V_75 ) ;
return;
}
F_26 ( V_10 , 0 , 0 , V_91 , 0xffffffff ) ;
F_6 ( V_10 , 0 , 0 , V_91 , & V_68 ) ;
V_68 = ~ V_68 + 1 ;
if ( V_64 < ( 0x100000000ull - V_68 ) ||
( V_65 > 0x100000000ull ) )
V_67 = 0x100000000ull - V_68 ;
else
V_67 = ( V_65 - V_68 ) & - V_68 ;
F_26 ( V_10 , 0 , 0 , V_91 , V_67 ) ;
V_65 = F_18 ( V_65 , ( T_4 ) V_67 ) ;
F_27 ( L_8 , V_75 , V_67 ) ;
V_62 = F_28 () ;
V_78 = F_29 ( V_10 -> V_76 , L_9 , & V_33 ) ;
if ( V_78 && ( V_33 == sizeof( T_4 ) ) ) {
T_4 V_92 = F_30 ( V_78 ) ;
if ( ( V_92 >= V_62 ) && ( V_92 < ( V_62 + V_93 ) ) ) {
F_27 ( L_10 , V_75 ) ;
V_62 += V_93 ;
} else {
F_31 ( L_11
L_12 , V_75 , V_92 ) ;
}
}
V_63 = F_18 ( V_62 , V_65 ) ;
V_58 = F_19 ( V_63 ) ;
if ( F_23 ( V_10 , 0 , 0 , V_79 ) ) {
if ( ( 1ull << V_58 ) != V_62 ) {
V_58 ++ ;
if ( ( 1ull << V_58 ) > V_62 )
F_27 ( L_13
L_14 , V_75 ) ;
}
V_69 |= ( ( V_58 - 1 ) & V_94 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_95 , 0x00000000 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_96 , 0x00000000 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_69 , V_69 ) ;
V_59 -- ;
V_10 -> V_97 = 0x00000000 ;
V_10 -> V_98 = ( T_5 ) V_63 ;
if ( V_63 != V_62 ) {
V_58 = F_19 ( V_62 ) ;
if ( ( 1ull << V_58 ) != V_62 )
V_58 ++ ;
V_69 = ( V_69 & ~ V_94 ) | ( V_58 - 1 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_95 , 0x00000000 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_99 ,
V_40 >> 44 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_96 ,
V_40 >> 12 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_69 , V_69 ) ;
V_100 . V_101 = F_9 ;
F_27 ( L_15 , V_75 ) ;
}
} else {
T_4 V_102 = 0 ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_95 , V_102 >> 12 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_96 , V_102 >> 12 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_69 , ( V_69 | ( V_58 - 1 ) ) ) ;
V_59 -- ;
V_102 += 1ull << V_58 ;
V_63 -= 1ull << V_58 ;
if ( V_63 ) {
V_58 = F_19 ( V_63 ) ;
V_69 |= ( V_58 - 1 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_95 , V_102 >> 12 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_96 , V_102 >> 12 ) ;
F_21 ( & V_25 -> V_82 [ V_59 ] . V_69 , V_69 ) ;
V_59 -- ;
V_102 += 1ull << V_58 ;
}
V_10 -> V_97 = 0x00000000 ;
V_10 -> V_98 = ( T_5 ) V_102 ;
}
if ( V_10 -> V_98 < V_62 ) {
#ifdef F_32
V_103 = 1 ;
#else
F_25 ( L_16
L_17 ,
V_75 ) ;
#endif
if ( V_64 < 0xffffffffull )
F_33 ( L_18
L_19
L_20 ,
V_75 ) ;
F_27 ( L_21 , V_75 ,
( T_4 ) V_10 -> V_98 ) ;
}
}
static void T_6 F_34 ( struct V_9 * V_10 )
{
T_7 V_104 ;
int V_105 ;
F_35 ( V_10 , 0 , 0 , V_106 , & V_104 ) ;
V_104 |= V_107 | V_108 | V_109
| V_110 ;
F_36 ( V_10 , 0 , 0 , V_106 , V_104 ) ;
V_105 = F_23 ( V_10 , 0 , 0 , V_111 ) ;
if ( V_105 ) {
int V_112 = V_105 + V_113 ;
V_104 = V_114 | V_115
| V_116 | V_117 ;
F_36 ( V_10 , 0 , 0 , V_112 , V_104 ) ;
} else {
F_37 ( V_10 , 0 , 0 , V_118 , 0x80 ) ;
}
}
void F_38 ( struct V_17 * V_18 )
{
struct V_9 * V_10 = F_8 ( V_18 ) ;
int V_49 , V_119 = 0 , V_120 ;
if ( V_8 )
V_119 = F_23 ( V_10 , 0 , 0 , V_79 ) ;
V_120 = ! ! ( V_10 -> V_12 & V_34 ) ;
if ( V_18 -> V_121 == V_10 -> V_18 && ( V_119 || V_120 ) ) {
for ( V_49 = 0 ; V_49 < V_122 ; ++ V_49 ) {
struct V_42 * V_43 = V_18 -> V_42 [ V_49 ] ;
struct V_42 * V_123 ;
if ( ! V_43 )
continue;
if ( V_49 == 0 )
V_123 = & V_10 -> V_88 ;
else if ( V_49 < 4 )
V_123 = & V_10 -> V_83 [ V_49 - 1 ] ;
else V_123 = NULL ;
V_43 -> V_45 = V_123 ? V_123 -> V_45 : 0 ;
V_43 -> V_85 = V_123 ? V_123 -> V_85 : 0 ;
V_43 -> V_48 = V_123 ? V_123 -> V_48 : 0 ;
}
}
}
int F_39 ( struct V_124 * V_125 , int V_126 )
{
int V_33 ;
struct V_9 * V_10 ;
struct V_42 V_127 ;
const int * V_128 ;
T_1 V_3 , V_129 ;
struct V_130 * V_2 ;
struct V_24 T_3 * V_25 ;
V_2 = V_125 -> V_2 . V_131 ;
if ( ! F_40 ( V_2 ) ) {
F_33 ( L_22 , V_2 -> V_77 ) ;
return - V_132 ;
}
F_17 ( L_23 , V_2 -> V_77 ) ;
if ( F_41 ( V_2 , 0 , & V_127 ) ) {
F_42 ( V_133 L_24 ) ;
return - V_134 ;
}
V_128 = F_29 ( V_2 , L_25 , & V_33 ) ;
if ( V_128 == NULL || V_33 < 2 * sizeof( int ) )
F_42 ( V_133 L_26
L_27 , V_2 -> V_77 ) ;
F_43 ( V_135 ) ;
V_10 = F_44 ( V_2 ) ;
if ( ! V_10 )
return - V_134 ;
V_10 -> V_121 = & V_125 -> V_2 ;
V_10 -> V_20 = V_128 ? V_128 [ 0 ] : 0x0 ;
V_10 -> V_136 = V_128 ? V_128 [ 1 ] : 0xff ;
F_17 ( L_28 ,
( T_4 ) V_127 . V_45 , ( T_4 ) F_16 ( & V_127 ) ) ;
V_25 = V_10 -> V_26 = F_45 ( V_127 . V_45 , F_16 ( & V_127 ) ) ;
if ( ! V_10 -> V_26 )
goto V_137;
F_46 ( V_10 , V_127 . V_45 , V_127 . V_45 + 0x4 ,
V_138 ) ;
if ( F_7 ( & V_25 -> V_80 ) < V_139 )
V_10 -> V_12 |= V_13 ;
if ( F_23 ( V_10 , 0 , 0 , V_79 ) ) {
V_10 -> V_14 = & V_140 ;
F_47 ( V_10 , 0 , 0 , V_4 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_5 )
goto V_137;
} else {
F_47 ( V_10 , 0 , 0 , V_141 , & V_129 ) ;
if ( ( V_129 & 1 ) == 1 )
goto V_137;
}
F_34 ( V_10 ) ;
if ( F_23 ( V_10 , 0 , 0 , V_79 ) ) {
V_10 -> V_12 |= V_142 |
V_143 ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_34 ;
}
F_42 ( V_144 L_29
L_30 ,
( unsigned long long ) V_127 . V_45 , V_10 -> V_20 ,
V_10 -> V_136 ) ;
F_17 ( L_31 ,
V_10 , V_10 -> V_145 , V_10 -> V_146 ) ;
F_48 ( V_10 , V_2 , V_126 ) ;
F_22 ( V_10 ) ;
return 0 ;
V_137:
F_49 ( V_10 -> V_26 ) ;
if ( ( ( unsigned long ) V_10 -> V_146 & V_147 ) !=
( ( unsigned long ) V_10 -> V_145 & V_147 ) )
F_49 ( V_10 -> V_146 ) ;
F_49 ( V_10 -> V_145 ) ;
F_50 ( V_10 ) ;
return - V_132 ;
}
static int F_51 ( struct V_17 * V_18 , unsigned int V_31 )
{
struct V_9 * V_10 = F_8 ( V_18 ) ;
if ( V_10 -> V_12 & V_34 )
return V_148 ;
if ( V_18 -> V_19 == V_10 -> V_20 ||
V_18 -> V_149 == V_10 -> V_20 ) {
if ( V_31 & 0xf8 )
return V_148 ;
}
if ( V_100 . V_150 ) {
if ( V_100 . V_150 ( V_10 , V_18 -> V_19 , V_31 ) )
return V_148 ;
}
return V_151 ;
}
static void T_3 * F_52 ( struct V_17 * V_18 ,
unsigned int V_31 , int V_32 )
{
struct V_9 * V_10 = F_8 ( V_18 ) ;
struct V_152 * V_153 = V_10 -> V_76 -> V_154 ;
T_2 V_155 = V_18 -> V_19 << 24 | V_31 << 16 ;
int V_156 ;
V_156 = F_51 ( V_18 , V_31 ) ;
if ( V_156 )
return NULL ;
V_32 &= 0xfff ;
if ( V_18 -> V_19 == V_10 -> V_20 )
return V_153 -> V_157 + V_32 ;
if ( V_153 -> V_155 == V_155 )
goto V_158;
F_53 ( V_153 -> V_157 + V_159 , V_155 ) ;
V_153 -> V_155 = V_155 ;
V_158:
return V_153 -> V_160 + V_32 ;
}
static int F_54 ( struct V_17 * V_18 , unsigned int V_31 ,
int V_32 , int V_33 , T_2 * V_11 )
{
void T_3 * V_145 ;
V_145 = F_52 ( V_18 , V_31 , V_32 ) ;
if ( ! V_145 )
return V_148 ;
switch ( V_33 ) {
case 1 :
* V_11 = F_55 ( V_145 ) ;
break;
case 2 :
* V_11 = F_56 ( V_145 ) ;
break;
default:
* V_11 = F_57 ( V_145 ) ;
break;
}
return V_151 ;
}
static int F_58 ( struct V_17 * V_18 , unsigned int V_31 ,
int V_32 , int V_33 , T_2 V_11 )
{
struct V_9 * V_10 = F_8 ( V_18 ) ;
void T_3 * V_145 ;
V_145 = F_52 ( V_18 , V_31 , V_32 ) ;
if ( ! V_145 )
return V_148 ;
if ( V_32 == V_161 && V_18 -> V_19 == V_10 -> V_20 )
V_11 &= 0xffffff00 ;
switch ( V_33 ) {
case 1 :
F_59 ( V_145 , V_11 ) ;
break;
case 2 :
F_60 ( V_145 , V_11 ) ;
break;
default:
F_53 ( V_145 , V_11 ) ;
break;
}
return V_151 ;
}
static int T_6 F_61 ( struct V_9 * V_10 ,
struct V_42 * V_78 )
{
struct V_152 * V_153 ;
T_2 V_162 ;
int V_156 = - V_134 ;
V_153 = F_62 ( sizeof( * V_153 ) , V_163 ) ;
if ( ! V_153 )
return V_156 ;
V_153 -> V_157 = F_45 ( V_78 -> V_45 , F_16 ( V_78 ) ) ;
if ( ! V_153 -> V_157 )
goto V_164;
V_162 = F_57 ( V_153 -> V_157 + V_165 ) ;
if ( ! V_162 ) {
V_156 = - V_132 ;
goto V_166;
}
V_153 -> V_160 = F_45 ( V_162 , 0x1000 ) ;
if ( ! V_153 -> V_160 )
goto V_166;
F_63 ( V_10 -> V_76 -> V_154 ) ;
V_10 -> V_76 -> V_154 = V_153 ;
V_10 -> V_14 = & V_167 ;
V_10 -> V_12 |= V_13 ;
F_53 ( V_153 -> V_157 + V_168 , 0 ) ;
F_53 ( V_153 -> V_157 + V_159 , 0 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_34 ;
return 0 ;
V_166:
F_49 ( V_153 -> V_157 ) ;
V_164:
F_64 ( V_153 ) ;
return V_156 ;
}
int T_6 F_65 ( struct V_130 * V_2 )
{
int V_156 ;
int V_33 ;
struct V_9 * V_10 ;
struct V_42 V_169 ;
struct V_42 V_170 ;
const int * V_128 ;
int V_149 ;
V_171 = 1 ;
if ( ! F_40 ( V_2 ) ) {
F_33 ( L_32 ,
V_2 -> V_77 ) ;
return - V_132 ;
}
F_17 ( L_23 , V_2 -> V_77 ) ;
if ( F_41 ( V_2 , 0 , & V_169 ) ) {
F_42 ( V_133 L_33 ) ;
return - V_134 ;
}
memset ( & V_170 , 0 , sizeof( V_170 ) ) ;
if ( F_41 ( V_2 , 1 , & V_170 ) ) {
F_42 ( V_133
L_34
L_35 ) ;
if ( ( V_169 . V_45 & 0xfffff ) == 0x8500 )
V_170 . V_45 = ( V_169 . V_45 & 0xfff00000 ) + 0x8300 ;
else if ( ( V_169 . V_45 & 0xfffff ) == 0x8600 )
V_170 . V_45 = ( V_169 . V_45 & 0xfff00000 ) + 0x8380 ;
}
if ( ( V_169 . V_45 & 0xfffff ) == 0x8500 )
V_149 = 1 ;
else
V_149 = 0 ;
V_128 = F_29 ( V_2 , L_25 , & V_33 ) ;
if ( V_128 == NULL || V_33 < 2 * sizeof( int ) ) {
F_42 ( V_133 L_26
L_27 , V_2 -> V_77 ) ;
}
F_43 ( V_135 ) ;
V_10 = F_44 ( V_2 ) ;
if ( ! V_10 )
return - V_134 ;
V_10 -> V_20 = V_128 ? V_128 [ 0 ] : 0 ;
V_10 -> V_136 = V_128 ? V_128 [ 1 ] : 0xff ;
if ( F_66 ( V_2 , L_36 ) ) {
V_156 = F_61 ( V_10 , & V_169 ) ;
if ( V_156 )
goto V_164;
} else {
F_46 ( V_10 , V_170 . V_45 ,
V_170 . V_45 + 4 , 0 ) ;
}
F_42 ( V_144 L_29
L_30 ,
( unsigned long long ) V_169 . V_45 , V_10 -> V_20 ,
V_10 -> V_136 ) ;
F_17 ( L_31 ,
V_10 , V_10 -> V_145 , V_10 -> V_146 ) ;
F_48 ( V_10 , V_2 , V_149 ) ;
return 0 ;
V_164:
F_50 ( V_10 ) ;
return V_156 ;
}
T_4 F_67 ( struct V_9 * V_10 )
{
#ifdef F_68
if ( V_171 ) {
struct V_152 * V_153 = V_10 -> V_76 -> V_154 ;
struct V_172 * V_173 ;
int V_49 ;
V_173 = V_153 -> V_157 + V_174 ;
for ( V_49 = 0 ; V_49 < 4 ; V_49 ++ ) {
if ( ! F_57 ( & V_173 [ V_49 ] . V_175 ) & V_176 )
continue;
if ( F_69 () == F_57 ( & V_173 [ V_49 ] . V_177 ) )
return ( T_4 ) F_57 ( & V_173 [ V_49 ] . V_178 ) << 32 |
F_57 ( & V_173 [ V_49 ] . V_179 ) ;
}
F_42 ( V_133 L_37 ) ;
}
#endif
#if F_70 ( V_180 ) || F_70 ( V_181 )
if ( ! V_171 ) {
T_2 V_182 ;
F_71 ( V_10 -> V_18 ,
F_72 ( 0 , 0 ) , V_91 , & V_182 ) ;
V_182 &= V_183 ;
return V_182 ;
}
#endif
return 0 ;
}
static int F_73 ( struct V_184 * V_185 , T_2 V_186 )
{
unsigned int V_187 , V_188 , V_189 , V_190 ;
V_187 = F_74 ( V_186 ) ;
V_188 = F_75 ( V_186 ) ;
V_189 = F_76 ( V_186 ) ;
V_190 = F_77 ( V_186 ) ;
switch ( F_78 ( V_186 ) ) {
case 31 :
switch ( F_79 ( V_186 ) ) {
case V_191 :
case V_192 :
V_185 -> V_193 [ V_187 ] = 0xffffffff ;
break;
case V_194 :
V_185 -> V_193 [ V_187 ] = 0xffffffff ;
V_185 -> V_193 [ V_188 ] += V_185 -> V_193 [ V_189 ] ;
break;
case V_195 :
V_185 -> V_193 [ V_187 ] = 0xff ;
break;
case V_196 :
V_185 -> V_193 [ V_187 ] = 0xff ;
V_185 -> V_193 [ V_188 ] += V_185 -> V_193 [ V_189 ] ;
break;
case V_197 :
case V_198 :
V_185 -> V_193 [ V_187 ] = 0xffff ;
break;
case V_199 :
V_185 -> V_193 [ V_187 ] = 0xffff ;
V_185 -> V_193 [ V_188 ] += V_185 -> V_193 [ V_189 ] ;
break;
case V_200 :
V_185 -> V_193 [ V_187 ] = ~ 0UL ;
break;
case V_201 :
V_185 -> V_193 [ V_187 ] = ~ 0UL ;
V_185 -> V_193 [ V_188 ] += V_185 -> V_193 [ V_189 ] ;
break;
default:
return 0 ;
}
break;
case V_202 :
V_185 -> V_193 [ V_187 ] = 0xffffffff ;
break;
case V_203 :
V_185 -> V_193 [ V_187 ] = 0xffffffff ;
V_185 -> V_193 [ V_188 ] += ( V_204 ) V_190 ;
break;
case V_205 :
V_185 -> V_193 [ V_187 ] = 0xff ;
break;
case V_206 :
V_185 -> V_193 [ V_187 ] = 0xff ;
V_185 -> V_193 [ V_188 ] += ( V_204 ) V_190 ;
break;
case V_207 :
V_185 -> V_193 [ V_187 ] = 0xffff ;
break;
case V_208 :
V_185 -> V_193 [ V_187 ] = 0xffff ;
V_185 -> V_193 [ V_188 ] += ( V_204 ) V_190 ;
break;
case V_209 :
V_185 -> V_193 [ V_187 ] = ~ 0UL ;
break;
case V_210 :
V_185 -> V_193 [ V_187 ] = ~ 0UL ;
V_185 -> V_193 [ V_188 ] += ( V_204 ) V_190 ;
break;
default:
return 0 ;
}
return 1 ;
}
static int F_80 ( T_8 V_211 )
{
struct V_9 * V_10 ;
struct V_42 * V_43 ;
int V_49 ;
F_81 (hose, &hose_list, list_node) {
if ( ! ( V_10 -> V_12 & V_142 ) )
continue;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
V_43 = & V_10 -> V_83 [ V_49 ] ;
if ( ( V_43 -> V_48 & V_84 ) &&
V_211 >= V_43 -> V_45 && V_211 <= V_43 -> V_85 )
return 1 ;
}
}
return 0 ;
}
int F_82 ( struct V_184 * V_185 )
{
T_2 V_186 ;
int V_156 ;
T_8 V_211 = 0 ;
if ( V_185 -> V_212 & V_213 )
return 0 ;
#ifdef F_83
V_211 = F_84 ( V_214 ) ;
V_211 <<= 32 ;
#endif
V_211 += F_84 ( V_215 ) ;
if ( F_80 ( V_211 ) ) {
if ( F_85 ( V_185 ) ) {
F_86 () ;
V_156 = F_87 ( V_185 -> V_216 , & V_186 ) ;
F_88 () ;
} else {
V_156 = F_89 ( V_185 -> V_216 , V_186 ) ;
}
if ( F_73 ( V_185 , V_186 ) ) {
V_185 -> V_216 += 4 ;
return 1 ;
}
}
return 0 ;
}
void F_90 ( void )
{
struct V_130 * V_217 ;
if ( V_218 )
return;
V_217 = F_91 ( NULL , L_38 ) ;
while ( ( V_218 = F_92 ( V_217 ) ) ) {
F_93 ( V_217 ) ;
V_217 = V_218 ;
if ( F_94 ( V_219 , V_217 ) && F_40 ( V_217 ) )
return;
}
F_95 (np, pci_ids) {
if ( F_40 ( V_217 ) ) {
V_218 = V_217 ;
F_93 ( V_217 ) ;
return;
}
}
}
static T_9 F_96 ( int V_220 , void * V_221 )
{
struct V_9 * V_10 = V_221 ;
struct V_24 T_3 * V_25 = V_10 -> V_26 ;
T_2 V_222 ;
V_222 = F_7 ( & V_25 -> V_223 ) ;
if ( ! V_222 )
return V_224 ;
F_21 ( & V_25 -> V_223 , V_222 ) ;
return V_225 ;
}
static int F_97 ( struct V_9 * V_10 )
{
struct V_24 T_3 * V_25 ;
struct V_1 * V_2 ;
int V_226 ;
int V_43 ;
T_7 V_227 ;
V_2 = F_98 ( & V_10 -> V_18 -> V_228 , F_99 ( * V_2 ) , V_229 ) ;
F_100 ( V_2 , V_2 -> V_230 + V_231 , & V_227 ) ;
V_227 &= ~ V_232 ;
F_101 ( V_2 , V_2 -> V_230 + V_231 , V_227 ) ;
V_226 = F_102 ( V_10 -> V_76 , 0 ) ;
if ( ! V_226 ) {
F_103 ( & V_2 -> V_2 , L_39 ) ;
return - V_233 ;
}
V_43 = F_104 ( V_10 -> V_121 , V_226 ,
F_96 ,
V_234 ,
L_40 , V_10 ) ;
if ( V_43 < 0 ) {
F_103 ( & V_2 -> V_2 , L_41 , V_226 ) ;
F_105 ( V_226 ) ;
return - V_132 ;
}
V_25 = V_10 -> V_26 ;
F_21 ( & V_25 -> V_235 , 0 ) ;
F_106 ( & V_25 -> V_235 ,
V_236 | V_237 | V_238 ) ;
F_21 ( & V_25 -> V_239 , 0 ) ;
F_106 ( & V_25 -> V_239 ,
V_236 | V_237 | V_238 ) ;
F_100 ( V_2 , V_2 -> V_230 + V_231 , & V_227 ) ;
V_227 |= V_232 ;
F_101 ( V_2 , V_2 -> V_230 + V_231 , V_227 ) ;
return 0 ;
}
static void F_107 ( struct V_9 * V_10 )
{
struct V_24 T_3 * V_25 = V_10 -> V_26 ;
T_2 V_222 ;
int V_49 ;
F_106 ( & V_25 -> V_240 , V_241 ) ;
for ( V_49 = 0 ; V_49 < 150 ; V_49 ++ ) {
V_222 = F_7 ( & V_25 -> V_223 ) ;
if ( V_222 ) {
F_21 ( & V_25 -> V_223 , V_222 ) ;
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
struct V_9 * V_10 , * V_242 ;
F_111 (hose, tmp, &hose_list, list_node)
F_109 ( V_10 ) ;
return 0 ;
}
static void F_112 ( struct V_9 * V_10 )
{
struct V_24 T_3 * V_25 = V_10 -> V_26 ;
T_2 V_222 ;
int V_49 ;
F_106 ( & V_25 -> V_240 , V_243 ) ;
for ( V_49 = 0 ; V_49 < 150 ; V_49 ++ ) {
V_222 = F_7 ( & V_25 -> V_223 ) ;
if ( V_222 ) {
F_21 ( & V_25 -> V_223 , V_222 ) ;
break;
}
F_108 ( 1000 ) ;
}
F_22 ( V_10 ) ;
}
static void F_113 ( void )
{
struct V_9 * V_10 , * V_242 ;
F_111 (hose, tmp, &hose_list, list_node)
F_112 ( V_10 ) ;
}
void F_114 ( struct V_9 * V_244 )
{
#ifdef F_115
F_97 ( V_244 ) ;
#endif
}
static int F_116 ( struct V_124 * V_125 )
{
struct V_130 * V_245 ;
int V_156 ;
V_245 = V_125 -> V_2 . V_131 ;
V_156 = F_39 ( V_125 , V_218 == V_245 ) ;
F_117 ( V_125 ) ;
return 0 ;
}
static int T_6 F_118 ( void )
{
#ifdef F_115
F_119 ( & V_246 ) ;
#endif
return F_120 ( & V_247 ) ;
}
