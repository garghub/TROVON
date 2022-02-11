static unsigned F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_6 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_8 = F_1 ( V_2 , V_9 ) & V_7 ;
F_5 ( V_2 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_10 , V_2 -> V_8 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
F_3 ( V_2 , V_11 , V_12 ) ;
if ( V_2 -> V_13 )
F_3 ( V_2 , V_11 , V_14 ) ;
F_3 ( V_2 , V_11 , V_15 ) ;
F_3 ( V_2 , V_11 , V_16 ) ;
F_3 ( V_2 , V_17 , V_2 -> V_18 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_19 )
{
int V_20 , V_21 , div ;
struct V_22 * V_23 = V_2 -> V_23 ;
int V_24 = V_23 -> V_25 ;
int V_26 = V_23 -> V_27 ;
div = F_10 ( 0 , ( int ) F_11 ( F_12 ( V_2 -> V_28 ) ,
2 * V_19 ) - V_24 ) ;
V_20 = F_13 ( div >> 8 ) ;
V_21 = div >> V_20 ;
if ( V_20 > V_26 ) {
F_14 ( V_2 -> V_2 , L_1 ,
V_20 , V_26 ) ;
V_20 = V_26 ;
V_21 = 255 ;
}
V_2 -> V_18 = ( V_20 << 16 ) | ( V_21 << 8 ) | V_21 ;
F_15 ( V_2 -> V_2 , L_2 , V_21 , V_20 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = & V_2 -> V_30 ;
F_6 ( V_2 ) ;
if ( V_30 -> V_31 ) {
if ( V_30 -> V_32 == V_33 )
F_17 ( V_30 -> V_34 ) ;
else
F_17 ( V_30 -> V_35 ) ;
V_30 -> V_31 = false ;
}
if ( V_30 -> V_36 ) {
F_18 ( V_2 -> V_2 , F_19 ( & V_30 -> V_37 [ 0 ] ) ,
V_2 -> V_38 , V_30 -> V_32 ) ;
V_30 -> V_36 = false ;
}
F_7 ( V_2 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_38 )
return;
F_21 ( * V_2 -> V_39 , V_2 -> V_4 + V_40 ) ;
if ( -- V_2 -> V_38 == 0 )
if ( ! V_2 -> V_23 -> V_41 )
F_3 ( V_2 , V_11 , V_42 ) ;
F_15 ( V_2 -> V_2 , L_3 , * V_2 -> V_39 , V_2 -> V_38 ) ;
++ V_2 -> V_39 ;
}
static void F_22 ( void * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
F_18 ( V_2 -> V_2 , F_19 ( & V_2 -> V_30 . V_37 [ 0 ] ) ,
V_2 -> V_38 , V_44 ) ;
F_3 ( V_2 , V_10 , V_45 ) ;
if ( ! V_2 -> V_23 -> V_41 )
F_3 ( V_2 , V_11 , V_42 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_1 V_46 ;
struct V_47 * V_48 ;
struct V_29 * V_30 = & V_2 -> V_30 ;
struct V_49 * V_35 = V_30 -> V_35 ;
unsigned int V_50 = 1 ;
if ( ! V_2 -> V_38 )
return;
V_30 -> V_32 = V_44 ;
F_6 ( V_2 ) ;
V_46 = F_24 ( V_2 -> V_2 , V_2 -> V_39 , V_2 -> V_38 ,
V_44 ) ;
if ( F_25 ( V_2 -> V_2 , V_46 ) ) {
F_26 ( V_2 -> V_2 , L_4 ) ;
return;
}
V_30 -> V_36 = true ;
F_7 ( V_2 ) ;
if ( V_2 -> V_13 ) {
T_2 V_51 , V_52 ;
struct V_53 * V_37 ;
unsigned V_54 ;
V_50 = 0 ;
V_51 = V_2 -> V_38 & ~ 0x3 ;
if ( V_51 ) {
V_37 = & V_30 -> V_37 [ V_50 ++ ] ;
F_27 ( V_37 ) = V_51 ;
F_19 ( V_37 ) = V_46 ;
}
V_52 = V_2 -> V_38 & 0x3 ;
if ( V_52 ) {
V_37 = & V_30 -> V_37 [ V_50 ++ ] ;
F_27 ( V_37 ) = V_52 ;
F_19 ( V_37 ) = V_46 + V_51 ;
}
V_54 = F_1 ( V_2 , V_55 ) ;
V_54 &= ~ V_56 ;
V_54 |= F_28 ( V_57 ) ;
F_3 ( V_2 , V_55 , V_54 ) ;
} else {
F_27 ( & V_30 -> V_37 [ 0 ] ) = V_2 -> V_38 ;
F_19 ( & V_30 -> V_37 [ 0 ] ) = V_46 ;
}
V_48 = F_29 ( V_35 , V_30 -> V_37 , V_50 ,
V_58 ,
V_59 | V_60 ) ;
if ( ! V_48 ) {
F_26 ( V_2 -> V_2 , L_5 ) ;
goto error;
}
V_48 -> V_61 = F_22 ;
V_48 -> V_62 = V_2 ;
V_30 -> V_31 = true ;
F_30 ( V_48 ) ;
F_31 ( V_35 ) ;
return;
error:
F_16 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_38 ) {
F_1 ( V_2 , V_63 ) ;
return;
}
* V_2 -> V_39 = F_33 ( V_2 -> V_4 + V_63 ) ;
-- V_2 -> V_38 ;
if ( V_2 -> V_64 )
return;
if ( F_34 ( V_2 -> V_65 -> V_66 & V_67 ) ) {
if ( * V_2 -> V_39 <= V_68 && * V_2 -> V_39 > 0 ) {
V_2 -> V_65 -> V_66 &= ~ V_67 ;
V_2 -> V_38 += * V_2 -> V_39 ;
V_2 -> V_65 -> V_69 = V_2 -> V_38 + 1 ;
F_15 ( V_2 -> V_2 , L_6 ,
V_2 -> V_38 ) ;
} else {
V_2 -> V_64 = true ;
V_2 -> V_38 = 1 ;
}
}
if ( ! V_2 -> V_23 -> V_41 && V_2 -> V_38 == 1 )
F_3 ( V_2 , V_11 , V_42 ) ;
F_15 ( V_2 -> V_2 , L_7 , * V_2 -> V_39 , V_2 -> V_38 ) ;
++ V_2 -> V_39 ;
}
static void F_35 ( void * V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_43 ;
unsigned V_70 = V_45 ;
F_18 ( V_2 -> V_2 , F_19 ( & V_2 -> V_30 . V_37 [ 0 ] ) ,
V_2 -> V_38 , V_33 ) ;
if ( ! V_2 -> V_23 -> V_41 ) {
V_2 -> V_39 += V_2 -> V_38 - 2 ;
V_2 -> V_38 = 2 ;
V_70 |= V_71 ;
}
F_3 ( V_2 , V_10 , V_70 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
T_1 V_46 ;
struct V_47 * V_72 ;
struct V_29 * V_30 = & V_2 -> V_30 ;
struct V_49 * V_34 = V_30 -> V_34 ;
T_2 V_38 ;
V_38 = ( V_2 -> V_23 -> V_41 ) ? V_2 -> V_38 : V_2 -> V_38 - 2 ;
V_30 -> V_32 = V_33 ;
F_6 ( V_2 ) ;
V_46 = F_24 ( V_2 -> V_2 , V_2 -> V_39 , V_38 , V_33 ) ;
if ( F_25 ( V_2 -> V_2 , V_46 ) ) {
F_26 ( V_2 -> V_2 , L_4 ) ;
return;
}
V_30 -> V_36 = true ;
F_7 ( V_2 ) ;
if ( V_2 -> V_13 && F_37 ( V_38 , 4 ) ) {
unsigned V_54 ;
V_54 = F_1 ( V_2 , V_55 ) ;
V_54 &= ~ V_73 ;
V_54 |= F_38 ( V_57 ) ;
F_3 ( V_2 , V_55 , V_54 ) ;
}
F_27 ( & V_30 -> V_37 [ 0 ] ) = V_38 ;
F_19 ( & V_30 -> V_37 [ 0 ] ) = V_46 ;
V_72 = F_29 ( V_34 , V_30 -> V_37 , 1 , V_74 ,
V_59 | V_60 ) ;
if ( ! V_72 ) {
F_26 ( V_2 -> V_2 , L_5 ) ;
goto error;
}
V_72 -> V_61 = F_35 ;
V_72 -> V_62 = V_2 ;
V_30 -> V_31 = true ;
F_30 ( V_72 ) ;
F_31 ( V_30 -> V_34 ) ;
return;
error:
F_16 ( V_2 ) ;
}
static T_3 F_39 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
const unsigned V_77 = F_1 ( V_2 , V_78 ) ;
const unsigned V_79 = V_77 & F_1 ( V_2 , V_9 ) ;
if ( ! V_79 )
return V_80 ;
if ( V_79 & V_71 )
F_32 ( V_2 ) ;
if ( V_79 & ( V_45 | V_81 ) ) {
F_5 ( V_2 ) ;
F_40 ( & V_2 -> V_82 ) ;
} else if ( V_79 & V_83 ) {
F_20 ( V_2 ) ;
}
V_2 -> V_84 |= V_77 ;
return V_85 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_86 ;
unsigned long V_87 ;
bool V_88 = V_2 -> V_23 -> V_88 ;
bool V_41 = V_2 -> V_23 -> V_41 ;
F_15 ( V_2 -> V_2 , L_8 ,
( V_2 -> V_65 -> V_66 & V_89 ) ? L_9 : L_10 , V_2 -> V_38 ) ;
F_42 ( & V_2 -> V_82 ) ;
V_2 -> V_84 = 0 ;
F_1 ( V_2 , V_78 ) ;
if ( V_2 -> V_13 ) {
unsigned V_54 = F_1 ( V_2 , V_55 ) ;
V_54 &= ~ ( V_56 |
V_73 ) ;
V_54 |= F_28 ( V_90 ) ;
V_54 |= F_38 ( V_90 ) ;
F_3 ( V_2 , V_55 , V_54 ) ;
F_3 ( V_2 , V_11 ,
V_91 | V_92 ) ;
}
if ( ! V_2 -> V_38 ) {
F_3 ( V_2 , V_11 , V_93 ) ;
F_3 ( V_2 , V_10 , V_45 ) ;
} else if ( V_2 -> V_65 -> V_66 & V_89 ) {
unsigned V_94 = V_95 ;
if ( ! V_41 && V_2 -> V_38 <= 1 &&
! ( V_2 -> V_65 -> V_66 & V_67 ) )
V_94 |= V_42 ;
F_3 ( V_2 , V_11 , V_94 ) ;
if ( V_2 -> V_96 && ( V_2 -> V_38 > V_97 ) ) {
F_3 ( V_2 , V_10 , V_81 ) ;
F_36 ( V_2 ) ;
} else {
F_3 ( V_2 , V_10 ,
V_45 |
V_81 |
V_71 ) ;
}
} else {
if ( V_2 -> V_96 && ( V_2 -> V_38 > V_97 ) ) {
F_3 ( V_2 , V_10 , V_81 ) ;
F_23 ( V_2 ) ;
} else {
F_20 ( V_2 ) ;
F_3 ( V_2 , V_10 ,
V_45 |
V_81 |
V_83 ) ;
}
}
V_87 = F_43 ( & V_2 -> V_82 ,
V_2 -> V_98 . V_99 ) ;
if ( V_87 == 0 ) {
V_2 -> V_84 |= F_1 ( V_2 , V_78 ) ;
F_26 ( V_2 -> V_2 , L_11 ) ;
F_8 ( V_2 ) ;
V_86 = - V_100 ;
goto error;
}
if ( V_2 -> V_84 & V_81 ) {
F_15 ( V_2 -> V_2 , L_12 ) ;
V_86 = - V_101 ;
goto error;
}
if ( V_2 -> V_84 & V_102 ) {
F_26 ( V_2 -> V_2 , L_13 ) ;
V_86 = - V_103 ;
goto error;
}
if ( V_88 && V_2 -> V_84 & V_104 ) {
F_26 ( V_2 -> V_2 , L_14 ) ;
V_86 = - V_103 ;
goto error;
}
if ( ( V_41 || V_2 -> V_13 ) &&
( V_2 -> V_84 & V_105 ) ) {
F_26 ( V_2 -> V_2 , L_15 ) ;
V_86 = - V_103 ;
goto error;
}
if ( V_2 -> V_64 ) {
F_26 ( V_2 -> V_2 , L_16 ) ;
V_86 = - V_106 ;
goto error;
}
F_15 ( V_2 -> V_2 , L_17 ) ;
return 0 ;
error:
F_16 ( V_2 ) ;
if ( ( V_41 || V_2 -> V_13 ) &&
( V_2 -> V_84 & V_105 ) ) {
F_15 ( V_2 -> V_2 , L_18 ) ;
F_3 ( V_2 , V_11 ,
V_91 | V_107 ) ;
}
return V_86 ;
}
static int F_44 ( struct V_108 * V_109 , struct V_110 * V_65 , int V_111 )
{
struct V_1 * V_2 = F_45 ( V_109 ) ;
int V_86 ;
unsigned V_112 = 0 ;
struct V_110 * V_113 = V_65 ;
bool V_114 , V_115 = false ;
F_15 ( & V_109 -> V_2 , L_19 , V_111 ) ;
V_86 = F_46 ( V_2 -> V_2 ) ;
if ( V_86 < 0 )
goto V_116;
if ( V_111 == 2 ) {
int V_117 = 0 ;
int V_118 ;
V_113 = & V_65 [ 1 ] ;
for ( V_118 = 0 ; V_118 < V_65 -> V_69 ; ++ V_118 ) {
const unsigned V_119 = V_65 -> V_39 [ V_65 -> V_69 - 1 - V_118 ] ;
V_117 |= V_119 << ( 8 * V_118 ) ;
V_112 += V_120 ;
}
F_3 ( V_2 , V_121 , V_117 ) ;
}
V_114 = ( V_113 -> V_66 & V_89 ) ;
if ( V_2 -> V_23 -> V_41 ) {
if ( V_113 -> V_69 > 0 ) {
F_3 ( V_2 , V_11 , V_122 ) ;
F_3 ( V_2 , V_123 ,
F_47 ( V_113 -> V_69 ) |
( ( V_114 ) ? V_124 : 0 ) ) ;
V_115 = true ;
} else {
F_3 ( V_2 , V_11 , V_125 ) ;
}
}
F_3 ( V_2 , V_126 ,
( V_113 -> V_119 << 16 ) |
V_112 |
( ( ! V_115 && V_114 ) ? V_127 : 0 ) ) ;
V_2 -> V_38 = V_113 -> V_69 ;
V_2 -> V_39 = V_113 -> V_39 ;
V_2 -> V_65 = V_113 ;
V_2 -> V_64 = false ;
V_86 = F_41 ( V_2 ) ;
V_86 = ( V_86 < 0 ) ? V_86 : V_111 ;
V_116:
F_48 ( V_2 -> V_2 ) ;
F_49 ( V_2 -> V_2 ) ;
return V_86 ;
}
static T_4 F_50 ( struct V_108 * V_98 )
{
return V_128 | V_129
| V_130 ;
}
static int F_51 ( struct V_1 * V_2 , T_4 V_131 )
{
int V_86 = 0 ;
struct V_132 V_133 ;
struct V_29 * V_30 = & V_2 -> V_30 ;
enum V_134 V_135 = V_136 ;
if ( V_2 -> V_13 )
V_135 = V_137 ;
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_133 . V_138 = ( T_1 ) V_131 + V_63 ;
V_133 . V_139 = V_135 ;
V_133 . V_140 = 1 ;
V_133 . V_141 = ( T_1 ) V_131 + V_40 ;
V_133 . V_142 = V_135 ;
V_133 . V_143 = 1 ;
V_133 . V_144 = false ;
V_30 -> V_35 = F_52 ( V_2 -> V_2 , L_20 ) ;
if ( F_53 ( V_30 -> V_35 ) ) {
V_86 = F_54 ( V_30 -> V_35 ) ;
V_30 -> V_35 = NULL ;
goto error;
}
V_30 -> V_34 = F_52 ( V_2 -> V_2 , L_21 ) ;
if ( F_53 ( V_30 -> V_34 ) ) {
V_86 = F_54 ( V_30 -> V_34 ) ;
V_30 -> V_34 = NULL ;
goto error;
}
V_133 . V_32 = V_58 ;
if ( F_55 ( V_30 -> V_35 , & V_133 ) ) {
F_26 ( V_2 -> V_2 , L_22 ) ;
V_86 = - V_145 ;
goto error;
}
V_133 . V_32 = V_74 ;
if ( F_55 ( V_30 -> V_34 , & V_133 ) ) {
F_26 ( V_2 -> V_2 , L_23 ) ;
V_86 = - V_145 ;
goto error;
}
F_56 ( V_30 -> V_37 , 2 ) ;
V_30 -> V_36 = false ;
V_30 -> V_31 = false ;
V_2 -> V_96 = true ;
F_57 ( V_2 -> V_2 , L_24 ,
F_58 ( V_30 -> V_35 ) , F_58 ( V_30 -> V_34 ) ) ;
return V_86 ;
error:
if ( V_86 != - V_146 )
F_57 ( V_2 -> V_2 , L_25 , V_86 ) ;
if ( V_30 -> V_34 )
F_59 ( V_30 -> V_34 ) ;
if ( V_30 -> V_35 )
F_59 ( V_30 -> V_35 ) ;
return V_86 ;
}
static struct V_22 * F_60 (
struct V_147 * V_148 )
{
if ( V_148 -> V_2 . V_149 ) {
const struct V_150 * V_151 ;
V_151 = F_61 ( V_152 , V_148 -> V_2 . V_149 ) ;
if ( ! V_151 )
return NULL ;
return (struct V_22 * ) V_151 -> V_43 ;
}
return (struct V_22 * ) F_62 ( V_148 ) -> V_153 ;
}
static int F_63 ( struct V_147 * V_148 )
{
struct V_1 * V_2 ;
struct V_154 * V_155 ;
int V_156 ;
T_4 V_131 ;
T_4 V_157 ;
V_2 = F_64 ( & V_148 -> V_2 , sizeof( * V_2 ) , V_158 ) ;
if ( ! V_2 )
return - V_159 ;
F_65 ( & V_2 -> V_82 ) ;
V_2 -> V_2 = & V_148 -> V_2 ;
V_155 = F_66 ( V_148 , V_160 , 0 ) ;
if ( ! V_155 )
return - V_161 ;
V_131 = V_155 -> V_162 ;
V_2 -> V_23 = F_60 ( V_148 ) ;
if ( ! V_2 -> V_23 )
return - V_161 ;
V_2 -> V_4 = F_67 ( & V_148 -> V_2 , V_155 ) ;
if ( F_53 ( V_2 -> V_4 ) )
return F_54 ( V_2 -> V_4 ) ;
V_2 -> V_75 = F_68 ( V_148 , 0 ) ;
if ( V_2 -> V_75 < 0 )
return V_2 -> V_75 ;
V_156 = F_69 ( & V_148 -> V_2 , V_2 -> V_75 , F_39 , 0 ,
F_70 ( V_2 -> V_2 ) , V_2 ) ;
if ( V_156 ) {
F_26 ( V_2 -> V_2 , L_26 , V_2 -> V_75 , V_156 ) ;
return V_156 ;
}
F_71 ( V_148 , V_2 ) ;
V_2 -> V_28 = F_72 ( V_2 -> V_2 , NULL ) ;
if ( F_53 ( V_2 -> V_28 ) ) {
F_26 ( V_2 -> V_2 , L_27 ) ;
return - V_161 ;
}
F_73 ( V_2 -> V_28 ) ;
if ( V_2 -> V_2 -> V_149 ) {
V_156 = F_51 ( V_2 , V_131 ) ;
if ( V_156 == - V_146 )
return V_156 ;
}
if ( ! F_74 ( V_148 -> V_2 . V_149 , L_28 ,
& V_2 -> V_13 ) ) {
F_57 ( V_2 -> V_2 , L_29 , V_2 -> V_13 ) ;
}
V_156 = F_74 ( V_2 -> V_2 -> V_149 , L_30 ,
& V_157 ) ;
if ( V_156 )
V_157 = V_163 ;
F_9 ( V_2 , V_157 ) ;
F_8 ( V_2 ) ;
snprintf ( V_2 -> V_98 . V_164 , sizeof( V_2 -> V_98 . V_164 ) , L_31 ) ;
F_75 ( & V_2 -> V_98 , V_2 ) ;
V_2 -> V_98 . V_165 = V_166 ;
V_2 -> V_98 . V_167 = V_168 ;
V_2 -> V_98 . V_169 = & V_170 ;
V_2 -> V_98 . V_171 = & V_172 ;
V_2 -> V_98 . V_2 . V_173 = V_2 -> V_2 ;
V_2 -> V_98 . V_174 = V_148 -> V_175 ;
V_2 -> V_98 . V_99 = V_176 ;
V_2 -> V_98 . V_2 . V_149 = V_148 -> V_2 . V_149 ;
F_76 ( V_2 -> V_2 , V_177 ) ;
F_77 ( V_2 -> V_2 ) ;
F_78 ( V_2 -> V_2 ) ;
F_79 ( V_2 -> V_2 ) ;
V_156 = F_80 ( & V_2 -> V_98 ) ;
if ( V_156 ) {
F_26 ( V_2 -> V_2 , L_32 ,
V_2 -> V_98 . V_164 ) ;
F_81 ( V_2 -> V_28 ) ;
F_82 ( V_2 -> V_2 ) ;
F_83 ( V_2 -> V_2 ) ;
return V_156 ;
}
F_57 ( V_2 -> V_2 , L_33 ,
F_1 ( V_2 , V_178 ) ) ;
return 0 ;
}
static int F_84 ( struct V_147 * V_148 )
{
struct V_1 * V_2 = F_85 ( V_148 ) ;
F_86 ( & V_2 -> V_98 ) ;
F_81 ( V_2 -> V_28 ) ;
F_82 ( V_2 -> V_2 ) ;
F_83 ( V_2 -> V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_179 * V_2 )
{
struct V_1 * V_180 = F_88 ( V_2 ) ;
F_81 ( V_180 -> V_28 ) ;
F_89 ( V_2 ) ;
return 0 ;
}
static int F_90 ( struct V_179 * V_2 )
{
struct V_1 * V_180 = F_88 ( V_2 ) ;
F_91 ( V_2 ) ;
return F_73 ( V_180 -> V_28 ) ;
}
static int F_92 ( struct V_179 * V_2 )
{
if ( ! F_93 ( V_2 ) )
F_87 ( V_2 ) ;
return 0 ;
}
static int F_94 ( struct V_179 * V_2 )
{
int V_86 ;
if ( ! F_93 ( V_2 ) ) {
V_86 = F_90 ( V_2 ) ;
if ( V_86 )
return V_86 ;
}
F_48 ( V_2 ) ;
F_95 ( V_2 ) ;
return 0 ;
}
static int T_5 F_96 ( void )
{
return F_97 ( & V_181 ) ;
}
static void T_6 F_98 ( void )
{
F_99 ( & V_181 ) ;
}
