static inline int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_5 ;
}
static inline int F_2 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_4 == V_6 ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
return F_1 ( V_2 ) ? F_4 ( V_7 ) : V_7 ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_8 , V_2 -> V_9 + V_10 ) ;
F_6 ( V_11 , V_2 -> V_9 + V_12 ) ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_8 , V_2 -> V_9 + V_10 ) ;
F_6 ( V_13 , V_2 -> V_9 + V_12 ) ;
}
static T_2 F_8 ( int V_14 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
T_1 V_16 ;
V_16 = F_9 ( V_2 -> V_9 + V_17 ) ;
F_6 ( V_16 , V_2 -> V_9 + V_17 ) ;
if ( V_16 & V_18 )
F_10 ( & V_2 -> V_19 ) ;
F_11 ( V_2 -> V_20 , L_1 , V_2 -> V_21 , V_16 ) ;
return V_22 ;
}
static void F_12 ( struct V_1 * V_2 )
{
void T_3 * V_23 = V_2 -> V_9 ;
int V_24 = V_2 -> V_3 -> V_24 ;
T_1 V_25 ;
T_4 V_26 , V_27 , V_28 ;
int V_29 ;
F_5 ( V_2 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ )
F_6 ( 0 , V_23 + V_31 + V_29 * 4 ) ;
V_25 = V_32 * 4 ;
if ( V_2 -> V_33 <= V_34 ) {
V_26 = V_35 ;
V_27 = V_36 ;
V_28 = 8 ;
} else {
V_26 = V_35 ;
V_27 = V_37 ;
V_28 = 8 ;
}
F_6 ( F_13 ( V_38 , V_39 , V_26 ) | F_14 ( V_40 , V_39 , V_27 ) ,
V_23 + F_15 ( V_25 ) ) ;
F_6 ( F_13 ( V_41 , V_39 , V_28 ) | F_14 ( V_42 , V_43 , V_24 ) ,
V_23 + F_15 ( V_25 + 1 ) ) ;
V_25 = V_44 * 4 ;
F_6 ( F_13 ( V_38 , V_39 , V_45 ) , V_23 + F_15 ( V_25 ) ) ;
V_25 = V_46 * 4 ;
if ( V_2 -> V_33 <= V_34 ) {
V_26 = V_47 ;
V_27 = V_36 ;
} else {
V_26 = V_47 ;
V_27 = V_37 ;
}
F_6 ( F_13 ( V_38 , V_39 , V_26 ) | F_14 ( V_40 , V_39 , V_27 ) ,
V_23 + F_15 ( V_25 ) ) ;
F_6 ( F_13 ( V_48 , V_39 , 0 ) , V_23 + F_15 ( V_25 + 1 ) ) ;
V_25 = V_49 * 4 ;
F_6 ( F_13 ( V_38 , V_39 , V_50 ) | F_14 ( V_42 , V_39 , 0x1 ) ,
V_23 + F_15 ( V_25 ) ) ;
V_25 = V_51 * 4 ;
if ( V_2 -> V_33 <= V_34 ) {
V_26 = V_52 ;
V_27 = V_36 ;
} else {
V_26 = V_52 ;
V_27 = V_37 ;
}
F_6 ( F_13 ( V_38 , V_39 , V_26 ) | F_14 ( V_40 , V_39 , V_27 ) ,
V_23 + F_15 ( V_25 ) ) ;
V_25 = V_53 * 4 ;
F_6 ( F_13 ( V_38 , V_39 , V_54 ) ,
V_23 + F_15 ( V_25 ) ) ;
V_25 = V_55 * 4 ;
F_6 ( F_13 ( V_38 , V_39 , V_56 ) | F_14 ( V_42 , V_39 , 0x8 ) ,
V_23 + F_15 ( V_25 ) ) ;
V_25 = V_57 * 4 ;
F_6 ( F_13 ( V_38 , V_39 , V_58 ) | F_14 ( V_48 , V_39 , 0x2 ) ,
V_23 + F_15 ( V_25 ) ) ;
V_25 = V_59 * 4 ;
F_6 ( F_13 ( V_38 , V_39 , V_60 ) | F_14 ( V_42 , V_39 , 0x1 ) ,
V_23 + F_15 ( V_25 ) ) ;
V_25 = V_61 * 4 ;
F_6 ( F_13 ( V_38 , V_39 , V_62 ) , V_23 + F_15 ( V_25 ) ) ;
V_25 = V_63 * 4 ;
F_6 ( F_13 ( V_38 , V_39 , V_64 ) , V_23 + F_15 ( V_25 ) ) ;
V_25 = V_65 * 4 ;
F_6 ( F_13 ( V_38 , V_39 , V_66 ) , V_23 + F_15 ( V_25 ) ) ;
F_7 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_4 V_26 )
{
switch ( V_26 ) {
case V_35 :
return V_32 ;
case V_45 :
return V_44 ;
case V_62 :
return V_61 ;
case V_50 :
return V_49 ;
case V_52 :
return V_51 ;
case V_54 :
return V_53 ;
case V_47 :
return V_46 ;
case V_56 :
return V_55 ;
case V_58 :
return V_57 ;
case V_60 :
return V_59 ;
case V_64 :
return V_63 ;
case V_66 :
return V_65 ;
default:
F_17 ( V_2 -> V_20 , L_2 , V_26 ) ;
break;
}
return - V_67 ;
}
static int
F_18 ( struct V_1 * V_2 , T_4 V_26 , unsigned int V_68 , int V_69 )
{
void T_3 * V_23 = V_2 -> V_9 ;
int V_70 ;
T_1 V_16 , V_71 ;
int V_72 ;
F_19 ( & V_2 -> V_19 ) ;
F_11 ( V_2 -> V_20 , L_3 ,
V_2 -> V_21 , V_68 , V_69 , V_26 ) ;
V_16 = F_9 ( V_23 + V_73 ) ;
F_6 ( V_2 -> V_74 + V_2 -> V_21 + V_68 , V_23 + V_75 ) ;
F_6 ( V_76 | V_77 ,
V_23 + V_78 ) ;
F_6 ( V_16 | V_79 , V_23 + V_73 ) ;
do {
V_71 = F_9 ( V_23 + V_80 ) ;
if ( V_71 & ( V_81 | V_82 ) ) {
F_20 ( 1 ) ;
F_11 ( V_2 -> V_20 , L_4 , V_71 ) ;
continue;
}
break;
} while ( 1 );
V_70 = F_16 ( V_2 , V_26 ) ;
F_6 ( ( V_70 << V_83 ) | V_69 , V_23 + V_84 ) ;
V_72 = F_21 ( & V_2 -> V_19 , F_22 ( 1000 ) ) ;
if ( ! V_72 ) {
F_17 ( V_2 -> V_20 ,
L_5 ,
V_26 , V_68 , F_9 ( V_23 + V_17 ) ,
F_9 ( V_23 + V_80 ) ) ;
V_72 = - V_85 ;
} else {
V_72 = 0 ;
}
F_6 ( V_16 , V_23 + V_73 ) ;
return V_72 ;
}
static void F_23 ( struct V_1 * V_2 , int V_69 , T_4 * V_86 )
{
T_1 V_87 ;
int V_29 = 0 ;
while ( V_69 > 0 ) {
V_87 = F_9 ( V_2 -> V_9 + V_88 + V_29 * 4 ) ;
V_87 = F_3 ( V_2 , V_87 ) ;
F_11 ( V_2 -> V_20 , L_6 ,
V_2 -> V_21 , V_87 ) ;
if ( V_69 >= 4 ) {
* ( ( T_1 * ) V_86 ) = V_87 ;
V_86 += 4 ;
} else {
memcpy ( V_86 , & V_87 , V_69 ) ;
break;
}
V_69 -= 4 ;
V_29 ++ ;
}
}
static inline void F_24 ( struct V_1 * V_2 )
{
T_1 V_16 ;
V_16 = F_9 ( V_2 -> V_9 + V_73 ) ;
V_16 |= V_89 | V_90 ;
F_6 ( V_16 , V_2 -> V_9 + V_73 ) ;
F_20 ( 1 ) ;
V_16 &= ~ ( V_89 | V_90 ) ;
F_6 ( V_16 , V_2 -> V_9 + V_73 ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_91 * V_92 ,
T_4 V_93 , unsigned int V_94 , T_1 * V_95 ,
unsigned V_96 , T_5 * V_97 )
{
int V_98 , V_29 , V_99 ;
T_1 V_87 ;
F_11 ( V_2 -> V_20 , L_7 ,
V_2 -> V_21 , V_94 , V_96 ) ;
V_87 = F_9 ( V_2 -> V_9 + V_73 ) ;
F_6 ( V_87 | V_79 , V_2 -> V_9 + V_73 ) ;
for ( V_99 = 0 , V_29 = ( ( V_96 + 3 ) / 4 ) ; V_99 < V_29 ; V_99 ++ ) {
V_87 = F_3 ( V_2 , * V_95 ) ;
F_6 ( V_87 , V_2 -> V_9 + V_100 ) ;
V_95 ++ ;
}
V_98 = F_18 ( V_2 , V_93 , V_94 , V_96 ) ;
if ( V_98 == 0 && V_97 )
* V_97 += V_96 ;
return V_98 ;
}
static void F_26 ( struct V_1 * V_2 )
{
int V_33 = V_2 -> V_33 ;
void T_3 * V_23 = V_2 -> V_9 ;
F_6 ( V_33 + V_2 -> V_74 , V_23 + V_101 ) ;
F_6 ( V_33 * 2 + V_2 -> V_74 , V_23 + V_102 ) ;
F_6 ( V_33 * 3 + V_2 -> V_74 , V_23 + V_103 ) ;
F_6 ( V_33 * 4 + V_2 -> V_74 , V_23 + V_104 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
void T_3 * V_23 = V_2 -> V_9 ;
int V_70 ;
F_6 ( V_105 , V_23 + V_106 ) ;
F_6 ( V_105 , V_23 + V_107 ) ;
F_6 ( V_105 , V_23 + V_108 ) ;
F_6 ( V_109 , V_23 + V_110 ) ;
F_6 ( 0 , V_23 + V_111 ) ;
F_6 ( 0 , V_23 + V_112 ) ;
F_6 ( 0 , V_23 + V_113 ) ;
V_70 = F_16 ( V_2 , V_2 -> V_92 [ 0 ] . V_114 ) ;
F_6 ( V_70 << V_115 ,
V_2 -> V_9 + V_116 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
void T_3 * V_23 = V_2 -> V_9 ;
T_1 V_16 ;
int V_98 ;
V_98 = F_29 ( V_2 -> V_117 , 66000000 ) ;
if ( V_98 )
return V_98 ;
F_12 ( V_2 ) ;
F_6 ( V_118 | V_119 ,
V_23 + V_73 ) ;
V_16 = F_9 ( V_23 + V_120 ) ;
F_6 ( V_16 & ~ ( V_121
| V_122
| V_123
| V_124 ) , V_23 + V_120 ) ;
F_6 ( V_119 | V_125 ,
V_23 + V_73 ) ;
F_6 ( V_126 , V_2 -> V_9 + V_127 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
unsigned long V_128 = V_2 -> V_129 ;
int V_98 ;
if ( F_2 ( V_2 ) )
V_128 *= 4 ;
V_98 = F_29 ( V_2 -> V_117 , V_128 ) ;
if ( V_98 )
return V_98 ;
F_12 ( V_2 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
V_2 -> V_21 = V_2 -> V_33 * ( V_92 - V_2 -> V_92 ) ;
}
static int F_32 ( struct V_91 * V_92 , T_4 V_93 , T_4 * V_130 , int V_69 )
{
int V_98 ;
struct V_1 * V_2 = V_92 -> V_131 ;
V_98 = F_18 ( V_2 , V_93 , 0 , V_69 ) ;
if ( V_98 )
return V_98 ;
F_23 ( V_2 , V_69 , V_130 ) ;
return 0 ;
}
static int F_33 ( struct V_91 * V_92 , T_4 V_93 , T_4 * V_130 , int V_69 ,
int V_132 )
{
struct V_1 * V_2 = V_92 -> V_131 ;
int V_98 ;
if ( ! V_130 ) {
V_98 = F_18 ( V_2 , V_93 , 0 , 1 ) ;
if ( V_98 )
return V_98 ;
if ( V_93 == V_54 )
F_24 ( V_2 ) ;
} else if ( V_69 > 0 ) {
V_98 = F_25 ( V_2 , V_92 , V_93 , 0 ,
( T_1 * ) V_130 , V_69 , NULL ) ;
} else {
F_17 ( V_2 -> V_20 , L_8 , V_93 ) ;
V_98 = - V_67 ;
}
return V_98 ;
}
static void F_34 ( struct V_91 * V_92 , T_6 V_94 ,
T_5 V_69 , T_5 * V_97 , const T_7 * V_130 )
{
struct V_1 * V_2 = V_92 -> V_131 ;
F_25 ( V_2 , V_92 , V_92 -> V_133 , V_94 ,
( T_1 * ) V_130 , V_69 , V_97 ) ;
F_24 ( V_2 ) ;
}
static int F_35 ( struct V_91 * V_92 , T_6 V_134 ,
T_5 V_69 , T_5 * V_97 , T_7 * V_130 )
{
struct V_1 * V_2 = V_92 -> V_131 ;
T_4 V_26 = V_92 -> V_114 ;
int V_98 ;
F_11 ( V_2 -> V_20 , L_9 ,
V_26 , V_2 -> V_135 , V_2 -> V_21 , ( unsigned int ) V_134 , V_69 ) ;
V_98 = V_92 -> V_136 ( V_92 ) ;
if ( V_98 )
return V_98 ;
memcpy ( V_130 , V_2 -> V_135 + V_2 -> V_21 + V_134 , V_69 ) ;
* V_97 += V_69 ;
return 0 ;
}
static int F_36 ( struct V_91 * V_92 , T_6 V_137 )
{
struct V_1 * V_2 = V_92 -> V_131 ;
int V_98 ;
F_11 ( V_92 -> V_20 , L_10 ,
V_92 -> V_138 -> V_139 / 1024 , V_2 -> V_21 , ( T_1 ) V_137 ) ;
V_98 = V_92 -> V_136 ( V_92 ) ;
if ( V_98 )
return V_98 ;
V_98 = V_92 -> V_140 ( V_92 , V_45 , NULL , 0 , 0 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_18 ( V_2 , V_92 -> V_141 , V_137 , 0 ) ;
if ( V_98 )
return V_98 ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_91 * V_92 , enum V_142 V_143 )
{
struct V_1 * V_2 = V_92 -> V_131 ;
int V_98 ;
V_98 = F_38 ( V_2 -> V_144 ) ;
if ( V_98 )
return V_98 ;
V_98 = F_38 ( V_2 -> V_117 ) ;
if ( V_98 ) {
F_39 ( V_2 -> V_144 ) ;
return V_98 ;
}
F_31 ( V_2 , V_92 ) ;
return 0 ;
}
static void F_40 ( struct V_91 * V_92 , enum V_142 V_143 )
{
struct V_1 * V_2 = V_92 -> V_131 ;
F_39 ( V_2 -> V_117 ) ;
F_39 ( V_2 -> V_144 ) ;
}
static int F_41 ( struct V_145 * V_146 )
{
struct V_147 * V_148 = V_146 -> V_20 . V_149 ;
struct V_150 V_151 ;
struct V_152 * V_20 = & V_146 -> V_20 ;
struct V_1 * V_2 ;
struct V_153 * V_154 ;
struct V_91 * V_92 ;
struct V_155 * V_138 ;
int V_98 , V_29 = 0 ;
bool V_156 = false ;
const struct V_157 * V_158 =
F_42 ( V_159 , & V_146 -> V_20 ) ;
V_2 = F_43 ( V_20 , sizeof( * V_2 ) , V_160 ) ;
if ( ! V_2 )
return - V_161 ;
V_2 -> V_162 = F_44 ( V_20 -> V_149 ) ;
if ( ! V_2 -> V_162 || V_2 -> V_162 > V_163 )
return - V_164 ;
V_154 = F_45 ( V_146 , V_165 , L_11 ) ;
V_2 -> V_9 = F_46 ( V_20 , V_154 ) ;
if ( F_47 ( V_2 -> V_9 ) ) {
V_98 = F_48 ( V_2 -> V_9 ) ;
goto V_166;
}
V_154 = F_45 ( V_146 , V_165 ,
L_12 ) ;
V_2 -> V_135 = F_46 ( V_20 , V_154 ) ;
if ( F_47 ( V_2 -> V_135 ) ) {
V_98 = F_48 ( V_2 -> V_135 ) ;
goto V_166;
}
V_2 -> V_74 = V_154 -> V_167 ;
V_2 -> V_144 = F_49 ( V_20 , L_13 ) ;
if ( F_47 ( V_2 -> V_144 ) ) {
V_98 = F_48 ( V_2 -> V_144 ) ;
goto V_166;
}
V_2 -> V_117 = F_49 ( V_20 , L_14 ) ;
if ( F_47 ( V_2 -> V_117 ) ) {
V_98 = F_48 ( V_2 -> V_117 ) ;
goto V_166;
}
V_98 = F_50 ( V_2 -> V_144 ) ;
if ( V_98 ) {
F_17 ( V_20 , L_15 ) ;
goto V_166;
}
V_98 = F_50 ( V_2 -> V_117 ) ;
if ( V_98 ) {
F_51 ( V_2 -> V_144 ) ;
F_17 ( V_20 , L_16 ) ;
goto V_166;
}
V_98 = F_52 ( V_146 , 0 ) ;
if ( V_98 < 0 ) {
F_17 ( V_20 , L_17 ) ;
goto V_168;
}
V_98 = F_53 ( V_20 , V_98 ,
F_8 , 0 , V_146 -> V_169 , V_2 ) ;
if ( V_98 ) {
F_17 ( V_20 , L_18 ) ;
goto V_168;
}
V_2 -> V_20 = V_20 ;
V_2 -> V_3 = (struct V_170 * ) V_158 -> V_171 ;
F_54 ( V_146 , V_2 ) ;
V_98 = F_28 ( V_2 ) ;
if ( V_98 )
goto V_168;
if ( F_55 ( V_148 , L_19 , NULL ) )
V_156 = true ;
F_56 (dev->of_node, np) {
char V_172 [ 40 ] ;
if ( ! V_156 )
V_29 *= 2 ;
V_92 = & V_2 -> V_92 [ V_29 ] ;
V_138 = & V_2 -> V_138 [ V_29 ] ;
V_92 -> V_138 = V_138 ;
V_92 -> V_20 = V_20 ;
V_92 -> V_131 = V_2 ;
V_138 -> V_131 = V_92 ;
V_92 -> V_173 = F_32 ;
V_92 -> V_140 = F_33 ;
V_92 -> V_174 = F_35 ;
V_92 -> V_175 = F_34 ;
V_92 -> V_176 = F_36 ;
V_92 -> V_177 = F_37 ;
V_92 -> V_178 = F_40 ;
if ( F_57 ( V_148 , V_172 , sizeof( V_172 ) ) < 0 )
goto V_166;
V_98 = F_58 ( V_148 , L_20 ,
& V_2 -> V_129 ) ;
if ( V_98 < 0 )
goto V_166;
F_31 ( V_2 , V_92 ) ;
V_98 = F_59 ( V_92 , V_172 , V_179 ) ;
if ( V_98 )
goto V_166;
V_151 . V_149 = V_148 ;
V_98 = F_60 ( V_138 , NULL , & V_151 , NULL , 0 ) ;
if ( V_98 )
goto V_166;
if ( V_2 -> V_33 == 0 ) {
V_2 -> V_33 = V_138 -> V_180 ;
F_26 ( V_2 ) ;
}
if ( V_92 -> V_181 > V_2 -> V_3 -> V_182 )
V_92 -> V_181 = V_2 -> V_3 -> V_182 ;
V_29 ++ ;
}
V_98 = F_30 ( V_2 ) ;
if ( V_98 )
goto V_183;
F_39 ( V_2 -> V_117 ) ;
F_39 ( V_2 -> V_144 ) ;
F_61 ( V_20 , L_21 ) ;
return 0 ;
V_183:
for ( V_29 = 0 ; V_29 < V_2 -> V_162 ; V_29 ++ )
F_62 ( & V_2 -> V_138 [ V_29 ] ) ;
V_168:
F_51 ( V_2 -> V_117 ) ;
F_51 ( V_2 -> V_144 ) ;
V_166:
F_17 ( V_20 , L_22 ) ;
return V_98 ;
}
static int F_63 ( struct V_145 * V_146 )
{
struct V_1 * V_2 = F_64 ( V_146 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_2 -> V_162 ; V_29 ++ )
F_62 ( & V_2 -> V_138 [ V_29 ] ) ;
F_6 ( V_118 , V_2 -> V_9 + V_73 ) ;
F_6 ( 0x0 , V_2 -> V_9 + V_127 ) ;
F_65 ( V_2 -> V_117 ) ;
F_65 ( V_2 -> V_144 ) ;
return 0 ;
}
