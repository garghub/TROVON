static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ! F_2 ( V_2 , V_4 ) )
return;
F_3 ( V_2 , V_5 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_6 )
return;
V_2 -> V_7 = V_8 << 8 ;
V_9 = 1 ;
return;
}
static int F_4 ( struct V_10 * V_11 )
{
T_2 V_12 = 0 ;
if ( V_11 -> V_13 & V_14 ) {
if ( V_11 -> V_15 -> V_16 == V_17 ) {
struct V_18 V_19 ;
V_19 . V_20 = V_11 -> V_21 ;
V_19 . V_22 = V_11 ;
V_19 . V_15 = V_11 -> V_15 ;
F_5 ( & V_19 , 0 , V_23 , 4 , & V_12 ) ;
} else
F_6 ( V_11 , 0 , 0 , V_23 , & V_12 ) ;
if ( V_12 < V_24 )
return 1 ;
} else {
struct V_25 T_3 * V_26 = V_11 -> V_27 ;
V_12 = ( F_7 ( & V_26 -> V_28 ) & V_29 )
>> V_30 ;
if ( V_12 != V_31 )
return 1 ;
}
return 0 ;
}
static int V_17 ( struct V_18 * V_19 , unsigned int V_32 ,
int V_33 , int V_34 , T_2 * V_12 )
{
struct V_10 * V_11 = F_8 ( V_19 ) ;
if ( F_4 ( V_11 ) )
V_11 -> V_13 |= V_35 ;
else
V_11 -> V_13 &= ~ V_35 ;
return F_5 ( V_19 , V_32 , V_33 , V_34 , V_12 ) ;
}
static int F_9 ( struct V_36 * V_2 , T_4 V_37 )
{
if ( ! V_2 -> V_37 || ! F_10 ( V_2 , V_37 ) )
return - V_38 ;
if ( ( V_2 -> V_19 == & V_39 ) &&
V_37 >= F_11 ( V_40 ) ) {
F_12 ( V_2 , & V_41 ) ;
F_13 ( V_2 , V_42 ) ;
}
* V_2 -> V_37 = V_37 ;
return 0 ;
}
static int F_14 ( struct V_25 T_3 * V_26 ,
unsigned int V_43 , const struct V_44 * V_45 ,
T_5 V_33 )
{
T_5 V_46 = V_45 -> V_47 - V_33 ;
T_5 V_48 = V_45 -> V_47 ;
T_5 V_49 = F_15 ( V_45 ) ;
T_2 V_50 = 0x80044000 ;
unsigned int V_51 ;
F_16 ( L_1 ,
( T_4 ) V_45 -> V_47 , ( T_4 ) V_49 ) ;
if ( V_45 -> V_50 & V_52 )
V_50 |= 0x10000000 ;
for ( V_51 = 0 ; V_49 > 0 ; V_51 ++ ) {
unsigned int V_53 = F_17 ( F_18 ( V_49 ) ,
F_19 ( V_46 | V_48 ) ) ;
if ( V_43 + V_51 >= 5 )
return - 1 ;
F_20 ( & V_26 -> pow [ V_43 + V_51 ] . V_54 , V_46 >> 12 ) ;
F_20 ( & V_26 -> pow [ V_43 + V_51 ] . V_55 , ( T_4 ) V_46 >> 44 ) ;
F_20 ( & V_26 -> pow [ V_43 + V_51 ] . V_56 , V_48 >> 12 ) ;
F_20 ( & V_26 -> pow [ V_43 + V_51 ] . V_57 , V_50 | ( V_53 - 1 ) ) ;
V_46 += ( T_5 ) 1U << V_53 ;
V_48 += ( T_5 ) 1U << V_53 ;
V_49 -= ( T_5 ) 1U << V_53 ;
}
return V_51 ;
}
static void F_21 ( struct V_10 * V_11 )
{
struct V_25 T_3 * V_26 = V_11 -> V_27 ;
int V_51 , V_58 , V_59 , V_60 , V_61 = 3 , V_62 = 1 , V_63 = 4 ;
T_4 V_64 , V_65 , V_66 = 0 ;
T_4 V_33 = 0 , V_67 = V_68 ;
T_2 V_69 = 0 , V_70 ;
T_2 V_71 = V_72 | V_73 | V_74 |
V_75 | V_76 ;
const char * V_77 = V_11 -> V_78 -> V_79 ;
const T_4 * V_80 ;
int V_34 ;
if ( F_22 ( V_11 , 0 , 0 , V_4 ) ) {
if ( F_7 ( & V_26 -> V_81 ) >= V_82 ) {
V_61 = 2 ;
V_62 = 0 ;
V_63 = 3 ;
}
}
for( V_51 = 1 ; V_51 < 5 ; V_51 ++ )
F_20 ( & V_26 -> pow [ V_51 ] . V_57 , 0 ) ;
for ( V_51 = V_62 ; V_51 < V_63 ; V_51 ++ )
F_20 ( & V_26 -> V_83 [ V_51 ] . V_71 , 0 ) ;
for( V_51 = 0 , V_58 = 1 ; V_51 < 3 ; V_51 ++ ) {
if ( ! ( V_11 -> V_84 [ V_51 ] . V_50 & V_85 ) )
continue;
V_67 = F_17 ( V_67 , ( T_4 ) V_11 -> V_84 [ V_51 ] . V_47 ) ;
V_66 = F_23 ( V_66 , ( T_4 ) V_11 -> V_84 [ V_51 ] . V_86 ) ;
V_33 = V_11 -> V_87 [ V_51 ] ;
V_59 = F_14 ( V_26 , V_58 , & V_11 -> V_84 [ V_51 ] , V_33 ) ;
if ( V_59 < 0 || V_58 >= 5 ) {
F_24 ( L_2 , V_51 ) ;
V_11 -> V_84 [ V_51 ] . V_50 |= V_88 ;
} else
V_58 += V_59 ;
}
if ( V_11 -> V_89 . V_50 & V_90 ) {
if ( V_58 >= 5 ) {
F_24 ( L_3 ) ;
} else {
F_16 ( L_4
L_5 ,
( T_4 ) V_11 -> V_89 . V_47 ,
( T_4 ) F_15 ( & V_11 -> V_89 ) ,
( T_4 ) V_11 -> V_91 ) ;
F_20 ( & V_26 -> pow [ V_58 ] . V_54 , ( V_11 -> V_89 . V_47 >> 12 ) ) ;
F_20 ( & V_26 -> pow [ V_58 ] . V_55 , 0 ) ;
F_20 ( & V_26 -> pow [ V_58 ] . V_56 , ( V_11 -> V_91 >> 12 ) ) ;
F_20 ( & V_26 -> pow [ V_58 ] . V_57 , 0x80088000
| ( F_18 ( V_11 -> V_89 . V_86
- V_11 -> V_89 . V_47 + 1 ) - 1 ) ) ;
}
}
V_66 -= V_33 ;
V_67 -= V_33 ;
if ( V_66 == V_67 ) {
F_24 ( L_6 , V_77 ) ;
return;
}
if ( V_67 == 0 ) {
F_24 ( L_7 , V_77 ) ;
return;
}
F_25 ( V_11 , 0 , 0 , V_92 , 0xffffffff ) ;
F_6 ( V_11 , 0 , 0 , V_92 , & V_70 ) ;
V_70 = ~ V_70 + 1 ;
if ( V_66 < ( 0x100000000ull - V_70 ) ||
( V_67 > 0x100000000ull ) )
V_69 = 0x100000000ull - V_70 ;
else
V_69 = ( V_67 - V_70 ) & - V_70 ;
F_25 ( V_11 , 0 , 0 , V_92 , V_69 ) ;
V_67 = F_17 ( V_67 , ( T_4 ) V_69 ) ;
F_26 ( L_8 , V_77 , V_69 ) ;
V_64 = F_27 () ;
V_80 = F_28 ( V_11 -> V_78 , L_9 , & V_34 ) ;
if ( V_80 && ( V_34 == sizeof( T_4 ) ) ) {
T_4 V_93 = F_29 ( V_80 ) ;
if ( ( V_93 >= V_64 ) && ( V_93 < ( V_64 + V_94 ) ) ) {
F_26 ( L_10 , V_77 ) ;
V_64 += V_94 ;
} else {
F_30 ( L_11
L_12 , V_77 , V_93 ) ;
}
}
V_65 = F_17 ( V_64 , V_67 ) ;
V_60 = F_18 ( V_65 ) ;
if ( F_22 ( V_11 , 0 , 0 , V_4 ) ) {
if ( ( 1ull << V_60 ) != V_64 ) {
V_60 ++ ;
if ( ( 1ull << V_60 ) > V_64 )
F_26 ( L_13
L_14 , V_77 ) ;
}
V_71 |= ( ( V_60 - 1 ) & V_95 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_96 , 0x00000000 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_97 , 0x00000000 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_71 , V_71 ) ;
V_61 -- ;
V_11 -> V_98 = 0x00000000 ;
V_11 -> V_99 = ( T_5 ) V_65 ;
if ( V_65 != V_64 ) {
V_60 = F_18 ( V_64 ) ;
if ( ( 1ull << V_60 ) != V_64 )
V_60 ++ ;
V_71 = ( V_71 & ~ V_95 ) | ( V_60 - 1 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_96 , 0x00000000 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_100 ,
V_42 >> 44 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_97 ,
V_42 >> 12 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_71 , V_71 ) ;
V_101 . V_102 = F_9 ;
F_26 ( L_15 , V_77 ) ;
}
} else {
T_4 V_103 = 0 ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_96 , V_103 >> 12 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_97 , V_103 >> 12 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_71 , ( V_71 | ( V_60 - 1 ) ) ) ;
V_61 -- ;
V_103 += 1ull << V_60 ;
V_65 -= 1ull << V_60 ;
if ( V_65 ) {
V_60 = F_18 ( V_65 ) ;
V_71 |= ( V_60 - 1 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_96 , V_103 >> 12 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_97 , V_103 >> 12 ) ;
F_20 ( & V_26 -> V_83 [ V_61 ] . V_71 , V_71 ) ;
V_61 -- ;
V_103 += 1ull << V_60 ;
}
V_11 -> V_98 = 0x00000000 ;
V_11 -> V_99 = ( T_5 ) V_103 ;
}
if ( V_11 -> V_99 < V_64 ) {
#ifdef F_31
V_104 = 1 ;
#else
F_24 ( L_16
L_17 ,
V_77 ) ;
#endif
if ( V_66 < 0xffffffffull )
F_32 ( L_18
L_19
L_20 ,
V_77 ) ;
F_26 ( L_21 , V_77 ,
( T_4 ) V_11 -> V_99 ) ;
}
}
static void T_6 F_33 ( struct V_10 * V_11 )
{
T_7 V_105 ;
int V_106 ;
F_34 ( V_11 , 0 , 0 , V_107 , & V_105 ) ;
V_105 |= V_108 | V_109 | V_110
| V_111 ;
F_35 ( V_11 , 0 , 0 , V_107 , V_105 ) ;
V_106 = F_22 ( V_11 , 0 , 0 , V_112 ) ;
if ( V_106 ) {
int V_113 = V_106 + V_114 ;
V_105 = V_115 | V_116
| V_117 | V_118 ;
F_35 ( V_11 , 0 , 0 , V_113 , V_105 ) ;
} else {
F_36 ( V_11 , 0 , 0 , V_119 , 0x80 ) ;
}
}
void F_37 ( struct V_18 * V_19 )
{
struct V_10 * V_11 = F_8 ( V_19 ) ;
int V_51 , V_120 = 0 , V_121 ;
if ( V_9 )
V_120 = F_22 ( V_11 , 0 , 0 , V_4 ) ;
V_121 = ! ! ( V_11 -> V_13 & V_35 ) ;
if ( V_19 -> V_122 == V_11 -> V_19 && ( V_120 || V_121 ) ) {
for ( V_51 = 0 ; V_51 < V_123 ; ++ V_51 ) {
struct V_44 * V_45 = V_19 -> V_44 [ V_51 ] ;
struct V_44 * V_124 ;
if ( ! V_45 )
continue;
if ( V_51 == 0 )
V_124 = & V_11 -> V_89 ;
else if ( V_51 < 4 )
V_124 = & V_11 -> V_84 [ V_51 - 1 ] ;
else V_124 = NULL ;
V_45 -> V_47 = V_124 ? V_124 -> V_47 : 0 ;
V_45 -> V_86 = V_124 ? V_124 -> V_86 : 0 ;
V_45 -> V_50 = V_124 ? V_124 -> V_50 : 0 ;
}
}
}
int T_6 F_38 ( struct V_125 * V_126 , int V_127 )
{
int V_34 ;
struct V_10 * V_11 ;
struct V_44 V_128 ;
const int * V_129 ;
T_1 V_3 , V_130 ;
struct V_131 * V_2 ;
struct V_25 T_3 * V_26 ;
V_2 = V_126 -> V_2 . V_132 ;
if ( ! F_39 ( V_2 ) ) {
F_32 ( L_22 , V_2 -> V_79 ) ;
return - V_133 ;
}
F_16 ( L_23 , V_2 -> V_79 ) ;
if ( F_40 ( V_2 , 0 , & V_128 ) ) {
F_41 ( V_134 L_24 ) ;
return - V_135 ;
}
V_129 = F_28 ( V_2 , L_25 , & V_34 ) ;
if ( V_129 == NULL || V_34 < 2 * sizeof( int ) )
F_41 ( V_134 L_26
L_27 , V_2 -> V_79 ) ;
F_42 ( V_136 ) ;
V_11 = F_43 ( V_2 ) ;
if ( ! V_11 )
return - V_135 ;
V_11 -> V_122 = & V_126 -> V_2 ;
V_11 -> V_21 = V_129 ? V_129 [ 0 ] : 0x0 ;
V_11 -> V_137 = V_129 ? V_129 [ 1 ] : 0xff ;
F_16 ( L_28 ,
( T_4 ) V_128 . V_47 , ( T_4 ) F_15 ( & V_128 ) ) ;
V_26 = V_11 -> V_27 = F_44 ( V_128 . V_47 , F_15 ( & V_128 ) ) ;
if ( ! V_11 -> V_27 )
goto V_138;
F_45 ( V_11 , V_128 . V_47 , V_128 . V_47 + 0x4 ,
V_139 ) ;
if ( F_7 ( & V_26 -> V_81 ) < V_140 )
V_11 -> V_13 |= V_14 ;
if ( F_22 ( V_11 , 0 , 0 , V_4 ) ) {
V_11 -> V_15 = & V_141 ;
F_46 ( V_11 , 0 , 0 , V_5 , & V_3 ) ;
if ( ( V_3 & 0x7f ) != V_6 )
goto V_138;
} else {
F_46 ( V_11 , 0 , 0 , V_142 , & V_130 ) ;
if ( ( V_130 & 1 ) == 1 )
goto V_138;
}
F_33 ( V_11 ) ;
if ( F_22 ( V_11 , 0 , 0 , V_4 ) ) {
V_11 -> V_13 |= V_143 |
V_144 ;
if ( F_4 ( V_11 ) )
V_11 -> V_13 |= V_35 ;
}
F_41 ( V_145 L_29
L_30 ,
( unsigned long long ) V_128 . V_47 , V_11 -> V_21 ,
V_11 -> V_137 ) ;
F_16 ( L_31 ,
V_11 , V_11 -> V_146 , V_11 -> V_147 ) ;
F_47 ( V_11 , V_2 , V_127 ) ;
F_21 ( V_11 ) ;
return 0 ;
V_138:
F_48 ( V_11 -> V_27 ) ;
if ( ( ( unsigned long ) V_11 -> V_147 & V_148 ) !=
( ( unsigned long ) V_11 -> V_146 & V_148 ) )
F_48 ( V_11 -> V_147 ) ;
F_48 ( V_11 -> V_146 ) ;
F_49 ( V_11 ) ;
return - V_133 ;
}
static int F_50 ( struct V_18 * V_19 , unsigned int V_32 )
{
struct V_10 * V_11 = F_8 ( V_19 ) ;
if ( V_11 -> V_13 & V_35 )
return V_149 ;
if ( V_19 -> V_20 == V_11 -> V_21 ||
V_19 -> V_150 == V_11 -> V_21 ) {
if ( V_32 & 0xf8 )
return V_149 ;
}
if ( V_101 . V_151 ) {
if ( V_101 . V_151 ( V_11 , V_19 -> V_20 , V_32 ) )
return V_149 ;
}
return V_152 ;
}
static void T_3 * F_51 ( struct V_18 * V_19 ,
unsigned int V_32 , int V_33 )
{
struct V_10 * V_11 = F_8 ( V_19 ) ;
struct V_153 * V_154 = V_11 -> V_78 -> V_155 ;
T_2 V_156 = V_19 -> V_20 << 24 | V_32 << 16 ;
int V_157 ;
V_157 = F_50 ( V_19 , V_32 ) ;
if ( V_157 )
return NULL ;
V_33 &= 0xfff ;
if ( V_19 -> V_20 == V_11 -> V_21 )
return V_154 -> V_158 + V_33 ;
if ( V_154 -> V_156 == V_156 )
goto V_159;
F_52 ( V_154 -> V_158 + V_160 , V_156 ) ;
V_154 -> V_156 = V_156 ;
V_159:
return V_154 -> V_161 + V_33 ;
}
static int F_53 ( struct V_18 * V_19 , unsigned int V_32 ,
int V_33 , int V_34 , T_2 * V_12 )
{
void T_3 * V_146 ;
V_146 = F_51 ( V_19 , V_32 , V_33 ) ;
if ( ! V_146 )
return V_149 ;
switch ( V_34 ) {
case 1 :
* V_12 = F_54 ( V_146 ) ;
break;
case 2 :
* V_12 = F_55 ( V_146 ) ;
break;
default:
* V_12 = F_56 ( V_146 ) ;
break;
}
return V_152 ;
}
static int F_57 ( struct V_18 * V_19 , unsigned int V_32 ,
int V_33 , int V_34 , T_2 V_12 )
{
struct V_10 * V_11 = F_8 ( V_19 ) ;
void T_3 * V_146 ;
V_146 = F_51 ( V_19 , V_32 , V_33 ) ;
if ( ! V_146 )
return V_149 ;
if ( V_33 == V_162 && V_19 -> V_20 == V_11 -> V_21 )
V_12 &= 0xffffff00 ;
switch ( V_34 ) {
case 1 :
F_58 ( V_146 , V_12 ) ;
break;
case 2 :
F_59 ( V_146 , V_12 ) ;
break;
default:
F_52 ( V_146 , V_12 ) ;
break;
}
return V_152 ;
}
static int T_6 F_60 ( struct V_10 * V_11 ,
struct V_44 * V_80 )
{
struct V_153 * V_154 ;
T_2 V_163 ;
int V_157 = - V_135 ;
V_154 = F_61 ( sizeof( * V_154 ) , V_164 ) ;
if ( ! V_154 )
return V_157 ;
V_154 -> V_158 = F_44 ( V_80 -> V_47 , F_15 ( V_80 ) ) ;
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
F_62 ( V_11 -> V_78 -> V_155 ) ;
V_11 -> V_78 -> V_155 = V_154 ;
V_11 -> V_15 = & V_168 ;
V_11 -> V_13 |= V_14 ;
F_52 ( V_154 -> V_158 + V_169 , 0 ) ;
F_52 ( V_154 -> V_158 + V_160 , 0 ) ;
if ( F_4 ( V_11 ) )
V_11 -> V_13 |= V_35 ;
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
int V_34 ;
struct V_10 * V_11 ;
struct V_44 V_170 ;
struct V_44 V_171 ;
const int * V_129 ;
int V_150 ;
V_172 = 1 ;
if ( ! F_39 ( V_2 ) ) {
F_32 ( L_32 ,
V_2 -> V_79 ) ;
return - V_133 ;
}
F_16 ( L_23 , V_2 -> V_79 ) ;
if ( F_40 ( V_2 , 0 , & V_170 ) ) {
F_41 ( V_134 L_33 ) ;
return - V_135 ;
}
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
if ( F_40 ( V_2 , 1 , & V_171 ) ) {
F_41 ( V_134
L_34
L_35 ) ;
if ( ( V_170 . V_47 & 0xfffff ) == 0x8500 )
V_171 . V_47 = ( V_170 . V_47 & 0xfff00000 ) + 0x8300 ;
else if ( ( V_170 . V_47 & 0xfffff ) == 0x8600 )
V_171 . V_47 = ( V_170 . V_47 & 0xfff00000 ) + 0x8380 ;
}
if ( ( V_170 . V_47 & 0xfffff ) == 0x8500 )
V_150 = 1 ;
else
V_150 = 0 ;
V_129 = F_28 ( V_2 , L_25 , & V_34 ) ;
if ( V_129 == NULL || V_34 < 2 * sizeof( int ) ) {
F_41 ( V_134 L_26
L_27 , V_2 -> V_79 ) ;
}
F_42 ( V_136 ) ;
V_11 = F_43 ( V_2 ) ;
if ( ! V_11 )
return - V_135 ;
V_11 -> V_21 = V_129 ? V_129 [ 0 ] : 0 ;
V_11 -> V_137 = V_129 ? V_129 [ 1 ] : 0xff ;
if ( F_65 ( V_2 , L_36 ) ) {
V_157 = F_60 ( V_11 , & V_170 ) ;
if ( V_157 )
goto V_165;
} else {
F_45 ( V_11 , V_171 . V_47 ,
V_171 . V_47 + 4 , 0 ) ;
}
F_41 ( V_145 L_29
L_30 ,
( unsigned long long ) V_170 . V_47 , V_11 -> V_21 ,
V_11 -> V_137 ) ;
F_16 ( L_31 ,
V_11 , V_11 -> V_146 , V_11 -> V_147 ) ;
F_47 ( V_11 , V_2 , V_150 ) ;
return 0 ;
V_165:
F_49 ( V_11 ) ;
return V_157 ;
}
T_4 F_66 ( struct V_10 * V_11 )
{
#ifdef F_67
if ( V_172 ) {
struct V_153 * V_154 = V_11 -> V_78 -> V_155 ;
struct V_173 * V_174 ;
int V_51 ;
V_174 = V_154 -> V_158 + V_175 ;
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
if ( ! F_56 ( & V_174 [ V_51 ] . V_176 ) & V_177 )
continue;
if ( F_68 () == F_56 ( & V_174 [ V_51 ] . V_178 ) )
return ( T_4 ) F_56 ( & V_174 [ V_51 ] . V_179 ) << 32 |
F_56 ( & V_174 [ V_51 ] . V_180 ) ;
}
F_41 ( V_134 L_37 ) ;
}
#endif
#if F_69 ( V_181 ) || F_69 ( V_182 )
if ( ! V_172 ) {
T_2 V_183 ;
F_70 ( V_11 -> V_19 ,
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
struct V_10 * V_11 ;
struct V_44 * V_45 ;
int V_51 ;
F_80 (hose, &hose_list, list_node) {
if ( ! ( V_11 -> V_13 & V_143 ) )
continue;
for ( V_51 = 0 ; V_51 < 3 ; V_51 ++ ) {
V_45 = & V_11 -> V_84 [ V_51 ] ;
if ( ( V_45 -> V_50 & V_85 ) &&
V_211 >= V_45 -> V_47 && V_211 <= V_45 -> V_86 )
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
static int F_97 ( struct V_36 * V_2 )
{
struct V_10 * V_11 ;
struct V_44 V_221 ;
V_11 = F_98 ( V_2 -> V_132 ) ;
if ( ! V_11 )
return - V_133 ;
if ( F_40 ( V_2 -> V_132 , 0 , & V_221 ) ) {
F_99 ( V_2 , L_39 ) ;
return - V_133 ;
}
F_21 ( V_11 ) ;
return 0 ;
}
static int T_6 F_100 ( void )
{
return F_101 ( & V_222 ) ;
}
