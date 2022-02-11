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
if ( ( V_2 -> V_18 == & V_38 ) &&
V_36 >= F_11 ( V_39 ) ) {
F_12 ( V_2 , & V_40 ) ;
F_13 ( V_2 , V_41 ) ;
}
* V_2 -> V_36 = V_36 ;
return 0 ;
}
static int F_14 ( struct V_24 T_3 * V_25 ,
unsigned int V_42 , const struct V_43 * V_44 ,
T_5 V_32 )
{
T_5 V_45 = V_44 -> V_46 - V_32 ;
T_5 V_47 = V_44 -> V_46 ;
T_5 V_48 = F_15 ( V_44 ) ;
T_2 V_49 = 0x80044000 ;
unsigned int V_50 ;
F_16 ( L_1 ,
( T_4 ) V_44 -> V_46 , ( T_4 ) V_48 ) ;
if ( V_44 -> V_49 & V_51 )
V_49 |= 0x10000000 ;
for ( V_50 = 0 ; V_48 > 0 ; V_50 ++ ) {
unsigned int V_52 = F_17 ( F_18 ( V_48 ) ,
F_19 ( V_45 | V_47 ) ) ;
if ( V_42 + V_50 >= 5 )
return - 1 ;
F_20 ( & V_25 -> pow [ V_42 + V_50 ] . V_53 , V_45 >> 12 ) ;
F_20 ( & V_25 -> pow [ V_42 + V_50 ] . V_54 , ( T_4 ) V_45 >> 44 ) ;
F_20 ( & V_25 -> pow [ V_42 + V_50 ] . V_55 , V_47 >> 12 ) ;
F_20 ( & V_25 -> pow [ V_42 + V_50 ] . V_56 , V_49 | ( V_52 - 1 ) ) ;
V_45 += ( T_5 ) 1U << V_52 ;
V_47 += ( T_5 ) 1U << V_52 ;
V_48 -= ( T_5 ) 1U << V_52 ;
}
return V_50 ;
}
static void F_21 ( struct V_9 * V_10 )
{
struct V_24 T_3 * V_25 = V_10 -> V_26 ;
int V_50 , V_57 , V_58 , V_59 , V_60 = 3 , V_61 = 1 , V_62 = 4 ;
T_4 V_63 , V_64 , V_65 = 0 ;
T_4 V_32 = 0 , V_66 = V_67 ;
T_2 V_68 = 0 , V_69 ;
T_2 V_70 = V_71 | V_72 | V_73 |
V_74 | V_75 ;
const char * V_76 = V_10 -> V_77 -> V_78 ;
const T_4 * V_79 ;
int V_33 ;
if ( F_22 ( V_10 , 0 , 0 , V_80 ) ) {
if ( F_7 ( & V_25 -> V_81 ) >= V_82 ) {
V_60 = 2 ;
V_61 = 0 ;
V_62 = 3 ;
}
}
for( V_50 = 1 ; V_50 < 5 ; V_50 ++ )
F_20 ( & V_25 -> pow [ V_50 ] . V_56 , 0 ) ;
for ( V_50 = V_61 ; V_50 < V_62 ; V_50 ++ )
F_20 ( & V_25 -> V_83 [ V_50 ] . V_70 , 0 ) ;
for( V_50 = 0 , V_57 = 1 ; V_50 < 3 ; V_50 ++ ) {
if ( ! ( V_10 -> V_84 [ V_50 ] . V_49 & V_85 ) )
continue;
V_66 = F_17 ( V_66 , ( T_4 ) V_10 -> V_84 [ V_50 ] . V_46 ) ;
V_65 = F_23 ( V_65 , ( T_4 ) V_10 -> V_84 [ V_50 ] . V_86 ) ;
V_32 = V_10 -> V_87 [ V_50 ] ;
V_58 = F_14 ( V_25 , V_57 , & V_10 -> V_84 [ V_50 ] , V_32 ) ;
if ( V_58 < 0 || V_57 >= 5 ) {
F_24 ( L_2 , V_50 ) ;
V_10 -> V_84 [ V_50 ] . V_49 |= V_88 ;
} else
V_57 += V_58 ;
}
if ( V_10 -> V_89 . V_49 & V_90 ) {
if ( V_57 >= 5 ) {
F_24 ( L_3 ) ;
} else {
F_16 ( L_4
L_5 ,
( T_4 ) V_10 -> V_89 . V_46 ,
( T_4 ) F_15 ( & V_10 -> V_89 ) ,
( T_4 ) V_10 -> V_91 ) ;
F_20 ( & V_25 -> pow [ V_57 ] . V_53 , ( V_10 -> V_89 . V_46 >> 12 ) ) ;
F_20 ( & V_25 -> pow [ V_57 ] . V_54 , 0 ) ;
F_20 ( & V_25 -> pow [ V_57 ] . V_55 , ( V_10 -> V_91 >> 12 ) ) ;
F_20 ( & V_25 -> pow [ V_57 ] . V_56 , 0x80088000
| ( F_18 ( V_10 -> V_89 . V_86
- V_10 -> V_89 . V_46 + 1 ) - 1 ) ) ;
}
}
V_65 -= V_32 ;
V_66 -= V_32 ;
if ( V_65 == V_66 ) {
F_24 ( L_6 , V_76 ) ;
return;
}
if ( V_66 == 0 ) {
F_24 ( L_7 , V_76 ) ;
return;
}
F_25 ( V_10 , 0 , 0 , V_92 , 0xffffffff ) ;
F_6 ( V_10 , 0 , 0 , V_92 , & V_69 ) ;
V_69 = ~ V_69 + 1 ;
if ( V_65 < ( 0x100000000ull - V_69 ) ||
( V_66 > 0x100000000ull ) )
V_68 = 0x100000000ull - V_69 ;
else
V_68 = ( V_66 - V_69 ) & - V_69 ;
F_25 ( V_10 , 0 , 0 , V_92 , V_68 ) ;
V_66 = F_17 ( V_66 , ( T_4 ) V_68 ) ;
F_26 ( L_8 , V_76 , V_68 ) ;
V_63 = F_27 () ;
V_79 = F_28 ( V_10 -> V_77 , L_9 , & V_33 ) ;
if ( V_79 && ( V_33 == sizeof( T_4 ) ) ) {
T_4 V_93 = F_29 ( V_79 ) ;
if ( ( V_93 >= V_63 ) && ( V_93 < ( V_63 + V_94 ) ) ) {
F_26 ( L_10 , V_76 ) ;
V_63 += V_94 ;
} else {
F_30 ( L_11
L_12 , V_76 , V_93 ) ;
}
}
V_64 = F_17 ( V_63 , V_66 ) ;
V_59 = F_18 ( V_64 ) ;
if ( F_22 ( V_10 , 0 , 0 , V_80 ) ) {
if ( ( 1ull << V_59 ) != V_63 ) {
V_59 ++ ;
if ( ( 1ull << V_59 ) > V_63 )
F_26 ( L_13
L_14 , V_76 ) ;
}
V_70 |= ( ( V_59 - 1 ) & V_95 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_96 , 0x00000000 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_97 , 0x00000000 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_70 , V_70 ) ;
V_60 -- ;
V_10 -> V_98 = 0x00000000 ;
V_10 -> V_99 = ( T_5 ) V_64 ;
if ( V_64 != V_63 ) {
V_59 = F_18 ( V_63 ) ;
if ( ( 1ull << V_59 ) != V_63 )
V_59 ++ ;
V_70 = ( V_70 & ~ V_95 ) | ( V_59 - 1 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_96 , 0x00000000 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_100 ,
V_41 >> 44 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_97 ,
V_41 >> 12 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_70 , V_70 ) ;
V_101 . V_102 = F_9 ;
F_26 ( L_15 , V_76 ) ;
}
} else {
T_4 V_103 = 0 ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_96 , V_103 >> 12 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_97 , V_103 >> 12 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_70 , ( V_70 | ( V_59 - 1 ) ) ) ;
V_60 -- ;
V_103 += 1ull << V_59 ;
V_64 -= 1ull << V_59 ;
if ( V_64 ) {
V_59 = F_18 ( V_64 ) ;
V_70 |= ( V_59 - 1 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_96 , V_103 >> 12 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_97 , V_103 >> 12 ) ;
F_20 ( & V_25 -> V_83 [ V_60 ] . V_70 , V_70 ) ;
V_60 -- ;
V_103 += 1ull << V_59 ;
}
V_10 -> V_98 = 0x00000000 ;
V_10 -> V_99 = ( T_5 ) V_103 ;
}
if ( V_10 -> V_99 < V_63 ) {
#ifdef F_31
V_104 = 1 ;
#else
F_24 ( L_16
L_17 ,
V_76 ) ;
#endif
if ( V_65 < 0xffffffffull )
F_32 ( L_18
L_19
L_20 ,
V_76 ) ;
F_26 ( L_21 , V_76 ,
( T_4 ) V_10 -> V_99 ) ;
}
}
static void T_6 F_33 ( struct V_9 * V_10 )
{
T_7 V_105 ;
int V_106 ;
F_34 ( V_10 , 0 , 0 , V_107 , & V_105 ) ;
V_105 |= V_108 | V_109 | V_110
| V_111 ;
F_35 ( V_10 , 0 , 0 , V_107 , V_105 ) ;
V_106 = F_22 ( V_10 , 0 , 0 , V_112 ) ;
if ( V_106 ) {
int V_113 = V_106 + V_114 ;
V_105 = V_115 | V_116
| V_117 | V_118 ;
F_35 ( V_10 , 0 , 0 , V_113 , V_105 ) ;
} else {
F_36 ( V_10 , 0 , 0 , V_119 , 0x80 ) ;
}
}
void F_37 ( struct V_17 * V_18 )
{
struct V_9 * V_10 = F_8 ( V_18 ) ;
int V_50 , V_120 = 0 , V_121 ;
if ( V_8 )
V_120 = F_22 ( V_10 , 0 , 0 , V_80 ) ;
V_121 = ! ! ( V_10 -> V_12 & V_34 ) ;
if ( V_18 -> V_122 == V_10 -> V_18 && ( V_120 || V_121 ) ) {
for ( V_50 = 0 ; V_50 < V_123 ; ++ V_50 ) {
struct V_43 * V_44 = V_18 -> V_43 [ V_50 ] ;
struct V_43 * V_124 ;
if ( ! V_44 )
continue;
if ( V_50 == 0 )
V_124 = & V_10 -> V_89 ;
else if ( V_50 < 4 )
V_124 = & V_10 -> V_84 [ V_50 - 1 ] ;
else V_124 = NULL ;
V_44 -> V_46 = V_124 ? V_124 -> V_46 : 0 ;
V_44 -> V_86 = V_124 ? V_124 -> V_86 : 0 ;
V_44 -> V_49 = V_124 ? V_124 -> V_49 : 0 ;
}
}
}
int T_6 F_38 ( struct V_125 * V_126 , int V_127 )
{
int V_33 ;
struct V_9 * V_10 ;
struct V_43 V_128 ;
const int * V_129 ;
T_1 V_3 , V_130 ;
struct V_131 * V_2 ;
struct V_24 T_3 * V_25 ;
V_2 = V_126 -> V_2 . V_132 ;
if ( ! F_39 ( V_2 ) ) {
F_32 ( L_22 , V_2 -> V_78 ) ;
return - V_133 ;
}
F_16 ( L_23 , V_2 -> V_78 ) ;
if ( F_40 ( V_2 , 0 , & V_128 ) ) {
F_41 ( V_134 L_24 ) ;
return - V_135 ;
}
V_129 = F_28 ( V_2 , L_25 , & V_33 ) ;
if ( V_129 == NULL || V_33 < 2 * sizeof( int ) )
F_41 ( V_134 L_26
L_27 , V_2 -> V_78 ) ;
F_42 ( V_136 ) ;
V_10 = F_43 ( V_2 ) ;
if ( ! V_10 )
return - V_135 ;
V_10 -> V_122 = & V_126 -> V_2 ;
V_10 -> V_20 = V_129 ? V_129 [ 0 ] : 0x0 ;
V_10 -> V_137 = V_129 ? V_129 [ 1 ] : 0xff ;
F_16 ( L_28 ,
( T_4 ) V_128 . V_46 , ( T_4 ) F_15 ( & V_128 ) ) ;
V_25 = V_10 -> V_26 = F_44 ( V_128 . V_46 , F_15 ( & V_128 ) ) ;
if ( ! V_10 -> V_26 )
goto V_138;
F_45 ( V_10 , V_128 . V_46 , V_128 . V_46 + 0x4 ,
V_139 ) ;
if ( F_7 ( & V_25 -> V_81 ) < V_140 )
V_10 -> V_12 |= V_13 ;
if ( F_22 ( V_10 , 0 , 0 , V_80 ) ) {
V_10 -> V_14 = & V_141 ;
F_46 ( V_10 , 0 , 0 , V_4 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_5 )
goto V_138;
} else {
F_46 ( V_10 , 0 , 0 , V_142 , & V_130 ) ;
if ( ( V_130 & 1 ) == 1 )
goto V_138;
}
F_33 ( V_10 ) ;
if ( F_22 ( V_10 , 0 , 0 , V_80 ) ) {
V_10 -> V_12 |= V_143 |
V_144 ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_34 ;
}
F_41 ( V_145 L_29
L_30 ,
( unsigned long long ) V_128 . V_46 , V_10 -> V_20 ,
V_10 -> V_137 ) ;
F_16 ( L_31 ,
V_10 , V_10 -> V_146 , V_10 -> V_147 ) ;
F_47 ( V_10 , V_2 , V_127 ) ;
F_21 ( V_10 ) ;
return 0 ;
V_138:
F_48 ( V_10 -> V_26 ) ;
if ( ( ( unsigned long ) V_10 -> V_147 & V_148 ) !=
( ( unsigned long ) V_10 -> V_146 & V_148 ) )
F_48 ( V_10 -> V_147 ) ;
F_48 ( V_10 -> V_146 ) ;
F_49 ( V_10 ) ;
return - V_133 ;
}
static int F_50 ( struct V_17 * V_18 , unsigned int V_31 )
{
struct V_9 * V_10 = F_8 ( V_18 ) ;
if ( V_10 -> V_12 & V_34 )
return V_149 ;
if ( V_18 -> V_19 == V_10 -> V_20 ||
V_18 -> V_150 == V_10 -> V_20 ) {
if ( V_31 & 0xf8 )
return V_149 ;
}
if ( V_101 . V_151 ) {
if ( V_101 . V_151 ( V_10 , V_18 -> V_19 , V_31 ) )
return V_149 ;
}
return V_152 ;
}
static void T_3 * F_51 ( struct V_17 * V_18 ,
unsigned int V_31 , int V_32 )
{
struct V_9 * V_10 = F_8 ( V_18 ) ;
struct V_153 * V_154 = V_10 -> V_77 -> V_155 ;
T_2 V_156 = V_18 -> V_19 << 24 | V_31 << 16 ;
int V_157 ;
V_157 = F_50 ( V_18 , V_31 ) ;
if ( V_157 )
return NULL ;
V_32 &= 0xfff ;
if ( V_18 -> V_19 == V_10 -> V_20 )
return V_154 -> V_158 + V_32 ;
if ( V_154 -> V_156 == V_156 )
goto V_159;
F_52 ( V_154 -> V_158 + V_160 , V_156 ) ;
V_154 -> V_156 = V_156 ;
V_159:
return V_154 -> V_161 + V_32 ;
}
static int F_53 ( struct V_17 * V_18 , unsigned int V_31 ,
int V_32 , int V_33 , T_2 * V_11 )
{
void T_3 * V_146 ;
V_146 = F_51 ( V_18 , V_31 , V_32 ) ;
if ( ! V_146 )
return V_149 ;
switch ( V_33 ) {
case 1 :
* V_11 = F_54 ( V_146 ) ;
break;
case 2 :
* V_11 = F_55 ( V_146 ) ;
break;
default:
* V_11 = F_56 ( V_146 ) ;
break;
}
return V_152 ;
}
static int F_57 ( struct V_17 * V_18 , unsigned int V_31 ,
int V_32 , int V_33 , T_2 V_11 )
{
struct V_9 * V_10 = F_8 ( V_18 ) ;
void T_3 * V_146 ;
V_146 = F_51 ( V_18 , V_31 , V_32 ) ;
if ( ! V_146 )
return V_149 ;
if ( V_32 == V_162 && V_18 -> V_19 == V_10 -> V_20 )
V_11 &= 0xffffff00 ;
switch ( V_33 ) {
case 1 :
F_58 ( V_146 , V_11 ) ;
break;
case 2 :
F_59 ( V_146 , V_11 ) ;
break;
default:
F_52 ( V_146 , V_11 ) ;
break;
}
return V_152 ;
}
static int T_6 F_60 ( struct V_9 * V_10 ,
struct V_43 * V_79 )
{
struct V_153 * V_154 ;
T_2 V_163 ;
int V_157 = - V_135 ;
V_154 = F_61 ( sizeof( * V_154 ) , V_164 ) ;
if ( ! V_154 )
return V_157 ;
V_154 -> V_158 = F_44 ( V_79 -> V_46 , F_15 ( V_79 ) ) ;
if ( ! V_154 -> V_158 )
goto V_165;
V_163 = F_56 ( V_154 -> V_158 + V_166 ) ;
if ( ! V_163 ) {
V_157 = - V_133 ;
goto V_167;
}
V_154 -> V_161 = F_44 ( V_163 , 0x1000 ) ;
if ( ! V_154 -> V_161 )
goto V_167;
F_62 ( V_10 -> V_77 -> V_155 ) ;
V_10 -> V_77 -> V_155 = V_154 ;
V_10 -> V_14 = & V_168 ;
V_10 -> V_12 |= V_13 ;
F_52 ( V_154 -> V_158 + V_169 , 0 ) ;
F_52 ( V_154 -> V_158 + V_160 , 0 ) ;
if ( F_4 ( V_10 ) )
V_10 -> V_12 |= V_34 ;
return 0 ;
V_167:
F_48 ( V_154 -> V_158 ) ;
V_165:
F_63 ( V_154 ) ;
return V_157 ;
}
int T_6 F_64 ( struct V_131 * V_2 )
{
int V_157 ;
int V_33 ;
struct V_9 * V_10 ;
struct V_43 V_170 ;
struct V_43 V_171 ;
const int * V_129 ;
int V_150 ;
V_172 = 1 ;
if ( ! F_39 ( V_2 ) ) {
F_32 ( L_32 ,
V_2 -> V_78 ) ;
return - V_133 ;
}
F_16 ( L_23 , V_2 -> V_78 ) ;
if ( F_40 ( V_2 , 0 , & V_170 ) ) {
F_41 ( V_134 L_33 ) ;
return - V_135 ;
}
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
if ( F_40 ( V_2 , 1 , & V_171 ) ) {
F_41 ( V_134
L_34
L_35 ) ;
if ( ( V_170 . V_46 & 0xfffff ) == 0x8500 )
V_171 . V_46 = ( V_170 . V_46 & 0xfff00000 ) + 0x8300 ;
else if ( ( V_170 . V_46 & 0xfffff ) == 0x8600 )
V_171 . V_46 = ( V_170 . V_46 & 0xfff00000 ) + 0x8380 ;
}
if ( ( V_170 . V_46 & 0xfffff ) == 0x8500 )
V_150 = 1 ;
else
V_150 = 0 ;
V_129 = F_28 ( V_2 , L_25 , & V_33 ) ;
if ( V_129 == NULL || V_33 < 2 * sizeof( int ) ) {
F_41 ( V_134 L_26
L_27 , V_2 -> V_78 ) ;
}
F_42 ( V_136 ) ;
V_10 = F_43 ( V_2 ) ;
if ( ! V_10 )
return - V_135 ;
V_10 -> V_20 = V_129 ? V_129 [ 0 ] : 0 ;
V_10 -> V_137 = V_129 ? V_129 [ 1 ] : 0xff ;
if ( F_65 ( V_2 , L_36 ) ) {
V_157 = F_60 ( V_10 , & V_170 ) ;
if ( V_157 )
goto V_165;
} else {
F_45 ( V_10 , V_171 . V_46 ,
V_171 . V_46 + 4 , 0 ) ;
}
F_41 ( V_145 L_29
L_30 ,
( unsigned long long ) V_170 . V_46 , V_10 -> V_20 ,
V_10 -> V_137 ) ;
F_16 ( L_31 ,
V_10 , V_10 -> V_146 , V_10 -> V_147 ) ;
F_47 ( V_10 , V_2 , V_150 ) ;
return 0 ;
V_165:
F_49 ( V_10 ) ;
return V_157 ;
}
T_4 F_66 ( struct V_9 * V_10 )
{
#ifdef F_67
if ( V_172 ) {
struct V_153 * V_154 = V_10 -> V_77 -> V_155 ;
struct V_173 * V_174 ;
int V_50 ;
V_174 = V_154 -> V_158 + V_175 ;
for ( V_50 = 0 ; V_50 < 4 ; V_50 ++ ) {
if ( ! F_56 ( & V_174 [ V_50 ] . V_176 ) & V_177 )
continue;
if ( F_68 () == F_56 ( & V_174 [ V_50 ] . V_178 ) )
return ( T_4 ) F_56 ( & V_174 [ V_50 ] . V_179 ) << 32 |
F_56 ( & V_174 [ V_50 ] . V_180 ) ;
}
F_41 ( V_134 L_37 ) ;
}
#endif
#if F_69 ( V_181 ) || F_69 ( V_182 )
if ( ! V_172 ) {
T_2 V_183 ;
F_70 ( V_10 -> V_18 ,
F_71 ( 0 , 0 ) , V_92 , & V_183 ) ;
return V_183 ;
}
#endif
return 0 ;
}
static int F_72 ( struct V_184 * V_185 , T_2 V_186 )
{
unsigned int V_187 , V_188 , V_189 , V_190 ;
V_187 = F_73 ( V_186 ) ;
V_188 = F_74 ( V_186 ) ;
V_189 = F_75 ( V_186 ) ;
V_190 = F_76 ( V_186 ) ;
switch ( F_77 ( V_186 ) ) {
case 31 :
switch ( F_78 ( V_186 ) ) {
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
static int F_79 ( T_8 V_211 )
{
struct V_9 * V_10 ;
struct V_43 * V_44 ;
int V_50 ;
F_80 (hose, &hose_list, list_node) {
if ( ! ( V_10 -> V_12 & V_143 ) )
continue;
for ( V_50 = 0 ; V_50 < 3 ; V_50 ++ ) {
V_44 = & V_10 -> V_84 [ V_50 ] ;
if ( ( V_44 -> V_49 & V_85 ) &&
V_211 >= V_44 -> V_46 && V_211 <= V_44 -> V_86 )
return 1 ;
}
}
return 0 ;
}
int F_81 ( struct V_184 * V_185 )
{
T_2 V_186 ;
int V_157 ;
T_8 V_211 = 0 ;
if ( V_185 -> V_212 & V_213 )
return 0 ;
#ifdef F_82
V_211 = F_83 ( V_214 ) ;
V_211 <<= 32 ;
#endif
V_211 += F_83 ( V_215 ) ;
if ( F_79 ( V_211 ) ) {
if ( F_84 ( V_185 ) ) {
F_85 () ;
V_157 = F_86 ( V_185 -> V_216 , & V_186 ) ;
F_87 () ;
} else {
V_157 = F_88 ( V_185 -> V_216 , V_186 ) ;
}
if ( F_72 ( V_185 , V_186 ) ) {
V_185 -> V_216 += 4 ;
return 1 ;
}
}
return 0 ;
}
void F_89 ( void )
{
struct V_131 * V_217 ;
if ( V_218 )
return;
V_217 = F_90 ( NULL , L_38 ) ;
while ( ( V_218 = F_91 ( V_217 ) ) ) {
F_92 ( V_217 ) ;
V_217 = V_218 ;
if ( F_93 ( V_219 , V_217 ) && F_39 ( V_217 ) )
return;
}
F_94 (np, pci_ids) {
if ( F_39 ( V_217 ) ) {
V_218 = V_217 ;
F_92 ( V_217 ) ;
return;
}
}
}
static int F_95 ( struct V_125 * V_126 )
{
int V_157 ;
struct V_131 * V_220 ;
V_220 = V_126 -> V_2 . V_132 ;
V_157 = F_38 ( V_126 , V_218 == V_220 ) ;
F_96 ( V_126 ) ;
return 0 ;
}
static int F_97 ( struct V_35 * V_2 )
{
struct V_9 * V_10 ;
struct V_43 V_221 ;
V_10 = F_98 ( V_2 -> V_132 ) ;
if ( ! V_10 )
return - V_133 ;
if ( F_40 ( V_2 -> V_132 , 0 , & V_221 ) ) {
F_99 ( V_2 , L_39 ) ;
return - V_133 ;
}
F_21 ( V_10 ) ;
return 0 ;
}
static int T_6 F_100 ( void )
{
return F_101 ( & V_222 ) ;
}
