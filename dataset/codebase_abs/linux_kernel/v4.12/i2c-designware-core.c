static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
if ( V_2 -> V_5 & V_6 )
V_4 = F_2 ( V_2 -> V_7 + V_3 ) |
( F_2 ( V_2 -> V_7 + V_3 + 2 ) << 16 ) ;
else
V_4 = F_3 ( V_2 -> V_7 + V_3 ) ;
if ( V_2 -> V_5 & V_8 )
return F_4 ( V_4 ) ;
else
return V_4 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_9 , int V_3 )
{
if ( V_2 -> V_5 & V_8 )
V_9 = F_4 ( V_9 ) ;
if ( V_2 -> V_5 & V_6 ) {
F_6 ( ( V_10 ) V_9 , V_2 -> V_7 + V_3 ) ;
F_6 ( ( V_10 ) ( V_9 >> 16 ) , V_2 -> V_7 + V_3 + 2 ) ;
} else {
F_7 ( V_9 , V_2 -> V_7 + V_3 ) ;
}
}
static T_1
F_8 ( T_1 V_11 , T_1 V_12 , T_1 V_13 , int V_14 , int V_3 )
{
if ( V_14 )
return ( V_11 * V_12 + 500000 ) / 1000000 - 8 + V_3 ;
else
return ( V_11 * ( V_12 + V_13 ) + 500000 ) / 1000000
- 3 + V_3 ;
}
static T_1 F_9 ( T_1 V_11 , T_1 V_15 , T_1 V_13 , int V_3 )
{
return ( ( V_11 * ( V_15 + V_13 ) + 500000 ) / 1000000 ) - 1 + V_3 ;
}
static void F_10 ( struct V_1 * V_2 , bool V_16 )
{
F_5 ( V_2 , V_16 , V_17 ) ;
}
static void F_11 ( struct V_1 * V_2 , bool V_16 )
{
int V_18 = 100 ;
do {
F_10 ( V_2 , V_16 ) ;
if ( ( F_1 ( V_2 , V_19 ) & 1 ) == V_16 )
return;
F_12 ( 25 , 250 ) ;
} while ( V_18 -- );
F_13 ( V_2 -> V_2 , L_1 ,
V_16 ? L_2 : L_3 ) ;
}
static unsigned long F_14 ( struct V_1 * V_2 )
{
if ( F_15 ( ! V_2 -> V_20 ) )
return 0 ;
return V_2 -> V_20 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_21 ;
if ( ! V_2 -> V_22 )
return 0 ;
V_21 = V_2 -> V_22 ( V_2 ) ;
if ( ! V_21 )
return 0 ;
F_17 ( V_2 -> V_2 , L_4 ) ;
return V_21 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 )
V_2 -> V_23 ( V_2 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
T_1 V_24 , V_25 ;
T_1 V_26 , V_27 ;
T_1 V_28 , V_29 ;
int V_21 ;
V_21 = F_16 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_26 = F_1 ( V_2 , V_30 ) ;
if ( V_26 == F_20 ( V_31 ) ) {
V_2 -> V_5 |= V_8 ;
} else if ( V_26 == ( V_31 & 0x0000ffff ) ) {
V_2 -> V_5 |= V_6 ;
} else if ( V_26 != V_31 ) {
F_17 ( V_2 -> V_2 , L_5
L_6 , V_26 ) ;
F_18 ( V_2 ) ;
return - V_32 ;
}
V_27 = F_1 ( V_2 , V_33 ) ;
F_11 ( V_2 , false ) ;
V_28 = V_2 -> V_28 ? : 300 ;
V_29 = V_2 -> V_29 ? : 300 ;
if ( V_2 -> V_34 && V_2 -> V_35 ) {
V_24 = V_2 -> V_34 ;
V_25 = V_2 -> V_35 ;
} else {
V_24 = F_8 ( F_14 ( V_2 ) ,
4000 ,
V_28 ,
0 ,
0 ) ;
V_25 = F_9 ( F_14 ( V_2 ) ,
4700 ,
V_29 ,
0 ) ;
}
F_5 ( V_2 , V_24 , V_36 ) ;
F_5 ( V_2 , V_25 , V_37 ) ;
F_21 ( V_2 -> V_2 , L_7 , V_24 , V_25 ) ;
if ( ( V_2 -> V_38 == 1000000 ) && V_2 -> V_39 && V_2 -> V_40 ) {
V_24 = V_2 -> V_39 ;
V_25 = V_2 -> V_40 ;
} else if ( V_2 -> V_41 && V_2 -> V_42 ) {
V_24 = V_2 -> V_41 ;
V_25 = V_2 -> V_42 ;
} else {
V_24 = F_8 ( F_14 ( V_2 ) ,
600 ,
V_28 ,
0 ,
0 ) ;
V_25 = F_9 ( F_14 ( V_2 ) ,
1300 ,
V_29 ,
0 ) ;
}
F_5 ( V_2 , V_24 , V_43 ) ;
F_5 ( V_2 , V_25 , V_44 ) ;
F_21 ( V_2 -> V_2 , L_8 , V_24 , V_25 ) ;
if ( ( V_2 -> V_45 & V_46 ) ==
V_47 ) {
if ( ( V_27 & V_48 )
!= V_49 ) {
F_17 ( V_2 -> V_2 , L_9 ) ;
V_2 -> V_45 &= ~ V_46 ;
V_2 -> V_45 |= V_50 ;
} else if ( V_2 -> V_51 && V_2 -> V_52 ) {
V_24 = V_2 -> V_51 ;
V_25 = V_2 -> V_52 ;
F_5 ( V_2 , V_24 , V_53 ) ;
F_5 ( V_2 , V_25 , V_54 ) ;
F_21 ( V_2 -> V_2 , L_10 ,
V_24 , V_25 ) ;
}
}
V_26 = F_1 ( V_2 , V_55 ) ;
if ( V_26 >= V_56 ) {
if ( ! V_2 -> V_57 ) {
V_2 -> V_57 = F_1 ( V_2 , V_58 ) ;
}
if ( ! ( V_2 -> V_57 & V_59 ) )
V_2 -> V_57 |= 1 << V_60 ;
F_5 ( V_2 , V_2 -> V_57 , V_58 ) ;
} else {
F_13 ( V_2 -> V_2 ,
L_11 ) ;
}
F_5 ( V_2 , V_2 -> V_61 / 2 , V_62 ) ;
F_5 ( V_2 , 0 , V_63 ) ;
F_5 ( V_2 , V_2 -> V_45 , V_64 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_18 = V_65 ;
while ( F_1 ( V_2 , V_66 ) & V_67 ) {
if ( V_18 <= 0 ) {
F_13 ( V_2 -> V_2 , L_12 ) ;
return - V_68 ;
}
V_18 -- ;
F_12 ( 1000 , 1100 ) ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = V_2 -> V_70 ;
T_1 V_71 , V_72 = 0 ;
F_11 ( V_2 , false ) ;
V_71 = F_1 ( V_2 , V_64 ) ;
if ( V_70 [ V_2 -> V_73 ] . V_5 & V_74 ) {
V_71 |= V_75 ;
V_72 = V_76 ;
} else {
V_71 &= ~ V_75 ;
}
F_5 ( V_2 , V_71 , V_64 ) ;
F_5 ( V_2 , V_70 [ V_2 -> V_73 ] . V_77 | V_72 , V_78 ) ;
F_24 ( V_2 ) ;
F_10 ( V_2 , true ) ;
F_1 ( V_2 , V_79 ) ;
F_5 ( V_2 , V_80 , V_81 ) ;
}
static void
F_25 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = V_2 -> V_70 ;
T_1 V_82 ;
int V_83 , V_84 ;
T_1 V_77 = V_70 [ V_2 -> V_73 ] . V_77 ;
T_1 V_85 = V_2 -> V_86 ;
T_2 * V_87 = V_2 -> V_88 ;
bool V_89 = false ;
V_82 = V_80 ;
for (; V_2 -> V_73 < V_2 -> V_90 ; V_2 -> V_73 ++ ) {
T_1 V_5 = V_70 [ V_2 -> V_73 ] . V_5 ;
if ( V_70 [ V_2 -> V_73 ] . V_77 != V_77 ) {
F_17 ( V_2 -> V_2 ,
L_13 , V_91 ) ;
V_2 -> V_92 = - V_93 ;
break;
}
if ( V_70 [ V_2 -> V_73 ] . V_94 == 0 ) {
F_17 ( V_2 -> V_2 ,
L_14 , V_91 ) ;
V_2 -> V_92 = - V_93 ;
break;
}
if ( ! ( V_2 -> V_95 & V_96 ) ) {
V_87 = V_70 [ V_2 -> V_73 ] . V_87 ;
V_85 = V_70 [ V_2 -> V_73 ] . V_94 ;
if ( ( V_2 -> V_45 & V_97 ) &&
( V_2 -> V_73 > 0 ) )
V_89 = true ;
}
V_83 = V_2 -> V_61 - F_1 ( V_2 , V_98 ) ;
V_84 = V_2 -> V_99 - F_1 ( V_2 , V_100 ) ;
while ( V_85 > 0 && V_83 > 0 && V_84 > 0 ) {
T_1 V_101 = 0 ;
if ( V_2 -> V_73 == V_2 -> V_90 - 1 &&
V_85 == 1 && ! ( V_5 & V_102 ) )
V_101 |= F_26 ( 9 ) ;
if ( V_89 ) {
V_101 |= F_26 ( 10 ) ;
V_89 = false ;
}
if ( V_70 [ V_2 -> V_73 ] . V_5 & V_103 ) {
if ( V_2 -> V_104 >= V_2 -> V_99 )
break;
F_5 ( V_2 , V_101 | 0x100 , V_105 ) ;
V_84 -- ;
V_2 -> V_104 ++ ;
} else
F_5 ( V_2 , V_101 | * V_87 ++ , V_105 ) ;
V_83 -- ; V_85 -- ;
}
V_2 -> V_88 = V_87 ;
V_2 -> V_86 = V_85 ;
if ( V_85 > 0 || V_5 & V_102 ) {
V_2 -> V_95 |= V_96 ;
break;
} else
V_2 -> V_95 &= ~ V_96 ;
}
if ( V_2 -> V_73 == V_2 -> V_90 )
V_82 &= ~ V_106 ;
if ( V_2 -> V_92 )
V_82 = 0 ;
F_5 ( V_2 , V_82 , V_81 ) ;
}
static T_2
F_27 ( struct V_1 * V_2 , T_2 V_94 )
{
struct V_69 * V_70 = V_2 -> V_70 ;
T_1 V_5 = V_70 [ V_2 -> V_107 ] . V_5 ;
V_94 += ( V_5 & V_108 ) ? 2 : 1 ;
V_2 -> V_86 = V_94 - F_28 ( T_2 , V_94 , V_2 -> V_104 ) ;
V_70 [ V_2 -> V_107 ] . V_94 = V_94 ;
V_70 [ V_2 -> V_107 ] . V_5 &= ~ V_102 ;
return V_94 ;
}
static void
F_29 ( struct V_1 * V_2 )
{
struct V_69 * V_70 = V_2 -> V_70 ;
int V_109 ;
for (; V_2 -> V_107 < V_2 -> V_90 ; V_2 -> V_107 ++ ) {
T_1 V_94 ;
T_2 * V_87 ;
if ( ! ( V_70 [ V_2 -> V_107 ] . V_5 & V_103 ) )
continue;
if ( ! ( V_2 -> V_95 & V_110 ) ) {
V_94 = V_70 [ V_2 -> V_107 ] . V_94 ;
V_87 = V_70 [ V_2 -> V_107 ] . V_87 ;
} else {
V_94 = V_2 -> V_111 ;
V_87 = V_2 -> V_112 ;
}
V_109 = F_1 ( V_2 , V_100 ) ;
for (; V_94 > 0 && V_109 > 0 ; V_94 -- , V_109 -- ) {
T_1 V_5 = V_70 [ V_2 -> V_107 ] . V_5 ;
* V_87 = F_1 ( V_2 , V_105 ) ;
if ( V_5 & V_102 &&
* V_87 <= V_113 && * V_87 > 0 ) {
V_94 = F_27 ( V_2 , * V_87 ) ;
}
V_87 ++ ;
V_2 -> V_104 -- ;
}
if ( V_94 > 0 ) {
V_2 -> V_95 |= V_110 ;
V_2 -> V_111 = V_94 ;
V_2 -> V_112 = V_87 ;
return;
} else
V_2 -> V_95 &= ~ V_110 ;
}
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned long V_114 = V_2 -> V_114 ;
int V_115 ;
if ( V_114 & V_116 ) {
F_31 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_21 ( V_2 -> V_2 ,
L_15 , V_91 , V_117 [ V_115 ] ) ;
return - V_118 ;
}
F_31 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_17 ( V_2 -> V_2 , L_15 , V_91 , V_117 [ V_115 ] ) ;
if ( V_114 & V_119 )
return - V_120 ;
else if ( V_114 & V_121 )
return - V_93 ;
else
return - V_122 ;
}
static int
F_32 ( struct V_123 * V_124 , struct V_69 V_70 [] , int V_125 )
{
struct V_1 * V_2 = F_33 ( V_124 ) ;
int V_21 ;
F_21 ( V_2 -> V_2 , L_16 , V_91 , V_125 ) ;
F_34 ( V_2 -> V_2 ) ;
F_35 ( & V_2 -> V_126 ) ;
V_2 -> V_70 = V_70 ;
V_2 -> V_90 = V_125 ;
V_2 -> V_127 = 0 ;
V_2 -> V_73 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_92 = 0 ;
V_2 -> V_95 = V_128 ;
V_2 -> V_114 = 0 ;
V_2 -> V_104 = 0 ;
V_21 = F_16 ( V_2 ) ;
if ( V_21 )
goto V_129;
V_21 = F_22 ( V_2 ) ;
if ( V_21 < 0 )
goto V_130;
F_23 ( V_2 ) ;
if ( ! F_36 ( & V_2 -> V_126 , V_124 -> V_18 ) ) {
F_17 ( V_2 -> V_2 , L_17 ) ;
F_19 ( V_2 ) ;
V_21 = - V_68 ;
goto V_130;
}
F_10 ( V_2 , false ) ;
if ( V_2 -> V_92 ) {
V_21 = V_2 -> V_92 ;
goto V_130;
}
if ( F_37 ( ! V_2 -> V_127 && ! V_2 -> V_95 ) ) {
V_21 = V_125 ;
goto V_130;
}
if ( V_2 -> V_127 == V_131 ) {
V_21 = F_30 ( V_2 ) ;
goto V_130;
}
if ( V_2 -> V_95 )
F_17 ( V_2 -> V_2 ,
L_18 ) ;
V_21 = - V_122 ;
V_130:
F_18 ( V_2 ) ;
V_129:
F_38 ( V_2 -> V_2 ) ;
F_39 ( V_2 -> V_2 ) ;
return V_21 ;
}
static T_1 F_40 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_33 ( V_124 ) ;
return V_2 -> V_132 ;
}
static T_1 F_41 ( struct V_1 * V_2 )
{
T_1 V_133 ;
V_133 = F_1 ( V_2 , V_134 ) ;
if ( V_133 & V_135 )
F_1 ( V_2 , V_136 ) ;
if ( V_133 & V_137 )
F_1 ( V_2 , V_138 ) ;
if ( V_133 & V_139 )
F_1 ( V_2 , V_140 ) ;
if ( V_133 & V_141 )
F_1 ( V_2 , V_142 ) ;
if ( V_133 & V_143 ) {
V_2 -> V_114 = F_1 ( V_2 , V_144 ) ;
F_1 ( V_2 , V_145 ) ;
}
if ( V_133 & V_146 )
F_1 ( V_2 , V_147 ) ;
if ( V_133 & V_148 )
F_1 ( V_2 , V_149 ) ;
if ( V_133 & V_150 )
F_1 ( V_2 , V_151 ) ;
if ( V_133 & V_152 )
F_1 ( V_2 , V_153 ) ;
if ( V_133 & V_154 )
F_1 ( V_2 , V_155 ) ;
return V_133 ;
}
static T_3 F_42 ( int V_156 , void * V_157 )
{
struct V_1 * V_2 = V_157 ;
T_1 V_133 , V_158 ;
V_158 = F_1 ( V_2 , V_17 ) ;
V_133 = F_1 ( V_2 , V_159 ) ;
F_21 ( V_2 -> V_2 , L_19 , V_91 , V_158 , V_133 ) ;
if ( ! V_158 || ! ( V_133 & ~ V_148 ) )
return V_160 ;
V_133 = F_41 ( V_2 ) ;
if ( V_133 & V_143 ) {
V_2 -> V_127 |= V_131 ;
V_2 -> V_95 = V_128 ;
F_5 ( V_2 , 0 , V_81 ) ;
goto V_161;
}
if ( V_133 & V_162 )
F_29 ( V_2 ) ;
if ( V_133 & V_106 )
F_25 ( V_2 ) ;
V_161:
if ( ( V_133 & ( V_143 | V_150 ) ) || V_2 -> V_92 )
F_43 ( & V_2 -> V_126 ) ;
else if ( F_44 ( V_2 -> V_5 & V_163 ) ) {
V_133 = F_1 ( V_2 , V_81 ) ;
F_24 ( V_2 ) ;
F_5 ( V_2 , V_133 , V_81 ) ;
}
return V_164 ;
}
void F_45 ( struct V_1 * V_2 )
{
F_11 ( V_2 , false ) ;
F_5 ( V_2 , 0 , V_81 ) ;
F_1 ( V_2 , V_79 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , V_81 ) ;
}
T_1 F_46 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_33 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_123 * V_124 = & V_2 -> V_165 ;
unsigned long V_166 ;
int V_167 ;
F_48 ( & V_2 -> V_126 ) ;
V_167 = F_19 ( V_2 ) ;
if ( V_167 )
return V_167 ;
snprintf ( V_124 -> V_168 , sizeof( V_124 -> V_168 ) ,
L_20 ) ;
V_124 -> V_169 = 3 ;
V_124 -> V_170 = & V_171 ;
V_124 -> V_2 . V_172 = V_2 -> V_2 ;
F_49 ( V_124 , V_2 ) ;
if ( V_2 -> V_173 ) {
F_50 ( V_2 -> V_2 , true ) ;
V_166 = V_174 ;
} else {
V_166 = V_175 | V_176 ;
}
F_24 ( V_2 ) ;
V_167 = F_51 ( V_2 -> V_2 , V_2 -> V_177 , F_42 , V_166 ,
F_52 ( V_2 -> V_2 ) , V_2 ) ;
if ( V_167 ) {
F_17 ( V_2 -> V_2 , L_21 ,
V_2 -> V_177 , V_167 ) ;
return V_167 ;
}
F_53 ( V_2 -> V_2 ) ;
V_167 = F_54 ( V_124 ) ;
if ( V_167 )
F_17 ( V_2 -> V_2 , L_22 , V_167 ) ;
F_55 ( V_2 -> V_2 ) ;
return V_167 ;
}
