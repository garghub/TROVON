static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
T_2 V_8 , V_9 , V_10 ;
bool V_11 = true ;
V_10 = ( V_12 >> V_13 ) << V_14 ;
F_2 ( V_4 -> V_15 , V_16 , & V_9 ) ;
V_8 = V_9 & V_10 ;
if ( V_8 )
V_11 = false ;
else
goto V_17;
if ( V_8 & V_18 )
F_3 ( V_6 , L_1 ) ;
if ( V_8 & V_19 )
F_4 ( V_6 , L_2 ) ;
if ( V_8 & V_20 ) {
F_4 ( V_6 , L_3 ) ;
V_9 |= V_21 ;
}
if ( V_8 & V_22 )
F_3 ( V_6 , L_4 ) ;
if ( V_8 & V_23 )
F_3 ( V_6 , L_5 ) ;
V_8 &= V_24 ;
V_9 &= ~ V_25 ;
if ( V_8 )
F_5 ( V_4 -> V_15 , V_16 , V_8 | V_9 ) ;
V_17:
F_2 ( V_4 -> V_15 , V_26 , & V_9 ) ;
V_8 = V_9 & V_10 ;
if ( V_8 )
V_11 = false ;
else
goto V_27;
if ( V_8 & V_18 )
F_3 ( V_6 , L_6 ) ;
if ( V_8 & V_19 )
F_4 ( V_6 , L_7 ) ;
if ( V_8 & V_20 ) {
F_4 ( V_6 , L_8 ) ;
V_9 |= V_21 ;
}
if ( V_8 & V_22 )
F_3 ( V_6 , L_9 ) ;
if ( V_8 & V_23 )
F_3 ( V_6 , L_10 ) ;
V_8 &= V_24 ;
V_9 &= ~ V_25 ;
if ( V_8 )
F_5 ( V_4 -> V_15 , V_26 , V_8 | V_9 ) ;
V_27:
if ( V_11 )
return V_28 ;
else
return V_29 ;
}
static int F_6 ( struct V_30 * V_31 ,
int V_32 , unsigned int V_33 , int V_34 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_34 == V_36 ;
T_2 V_37 = 0 ;
switch ( V_32 ) {
case V_38 :
V_37 |= V_39 ;
break;
case V_40 :
V_37 |= V_41 ;
break;
case V_42 :
V_37 |= V_43 ;
break;
case V_44 :
V_37 |= V_45 ;
break;
default:
return - V_46 ;
}
F_8 ( V_4 -> V_15 , F_9 ( V_35 ) ,
V_47 , V_37 ) ;
return 0 ;
}
static int F_10 ( struct V_30 * V_31 ,
int V_32 , unsigned int V_33 , int V_48 )
{
int V_49 ;
if ( V_48 == V_50 )
return 0 ;
V_49 = F_6 ( V_31 , V_32 , V_33 ,
V_36 ) ;
if ( V_49 ) {
F_11 ( V_31 -> V_6 , L_11 , V_49 ) ;
return V_49 ;
}
V_49 = F_6 ( V_31 , V_32 , V_33 ,
V_51 ) ;
if ( V_49 )
F_11 ( V_31 -> V_6 , L_12 , V_49 ) ;
return V_49 ;
}
static int F_12 ( struct V_30 * V_31 ,
unsigned int V_52 , int V_34 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_34 == V_36 ;
T_2 V_37 = 0 , V_53 = 0 ;
if ( ! V_4 -> V_54 )
V_53 |= V_55 ;
switch ( V_52 & V_56 ) {
case V_57 :
V_37 |= V_58 ;
V_53 |= V_59 | V_60 ;
break;
case V_61 :
V_37 |= V_58 ;
break;
case V_62 :
V_37 |= V_58 ;
V_53 |= V_59 ;
V_4 -> V_63 = true ;
break;
case V_64 :
V_37 |= V_58 ;
V_4 -> V_63 = true ;
break;
case V_65 :
default:
return - V_46 ;
}
switch ( V_52 & V_66 ) {
case V_67 :
V_37 ^= V_58 ;
V_53 ^= V_60 ;
break;
case V_68 :
V_37 ^= V_58 ;
break;
case V_69 :
V_53 ^= V_60 ;
break;
case V_70 :
break;
default:
return - V_46 ;
}
switch ( V_52 & V_71 ) {
case V_72 :
V_37 |= V_73 ;
V_53 |= V_74 ;
break;
case V_75 :
V_4 -> V_76 = true ;
break;
case V_77 :
V_37 |= V_73 ;
break;
case V_78 :
V_53 |= V_74 ;
V_4 -> V_76 = true ;
break;
default:
return - V_46 ;
}
F_8 ( V_4 -> V_15 , F_9 ( V_35 ) ,
V_58 | V_73 , V_37 ) ;
F_8 ( V_4 -> V_15 , F_13 ( V_35 ) ,
V_55 | V_59 |
V_60 | V_74 , V_53 ) ;
return 0 ;
}
static int F_14 ( struct V_30 * V_31 , unsigned int V_52 )
{
int V_49 ;
V_49 = F_12 ( V_31 , V_52 , V_36 ) ;
if ( V_49 ) {
F_11 ( V_31 -> V_6 , L_13 , V_49 ) ;
return V_49 ;
}
V_49 = F_12 ( V_31 , V_52 , V_51 ) ;
if ( V_49 )
F_11 ( V_31 -> V_6 , L_14 , V_49 ) ;
return V_49 ;
}
static int F_15 ( struct V_30 * V_79 , bool V_35 , T_2 V_33 )
{
struct V_3 * V_4 = F_7 ( V_79 ) ;
unsigned long V_80 ;
T_2 V_81 = 0 , V_82 , V_83 = V_33 ;
T_2 V_84 ;
int V_49 = 0 ;
if ( V_4 -> V_76 )
return 0 ;
for ( V_84 = 0 ; V_84 < V_85 ; V_84 ++ ) {
V_80 = F_16 ( V_4 -> V_86 [ V_84 ] ) ;
if ( ! V_80 )
continue;
V_82 = V_80 / V_33 ;
V_49 = V_80 - V_82 * V_33 ;
if ( V_49 != 0 && V_80 / V_49 < 1000 )
continue;
F_3 ( V_79 -> V_6 ,
L_15 ,
V_82 , V_33 , V_80 ) ;
if ( V_82 % 2 == 0 && V_82 >= 2 && V_82 <= 512 )
V_82 /= 2 ;
else
continue;
if ( V_49 < V_83 ) {
V_81 = V_82 ;
V_4 -> V_87 [ V_35 ] = V_84 ;
V_83 = V_49 ;
}
if ( V_49 == 0 )
break;
}
if ( V_81 == 0 ) {
F_11 ( V_79 -> V_6 , L_16 ,
V_35 ? 'T' : 'R' , V_33 ) ;
return - V_46 ;
}
if ( ( V_35 && V_4 -> V_88 [ V_89 ] ) || ( ! V_35 && ! V_4 -> V_88 [ V_90 ] ) ) {
F_8 ( V_4 -> V_15 , V_91 ,
V_47 ,
F_17 ( V_4 -> V_87 [ V_35 ] ) ) ;
F_8 ( V_4 -> V_15 , V_91 ,
V_92 , V_81 - 1 ) ;
} else {
F_8 ( V_4 -> V_15 , V_93 ,
V_47 ,
F_17 ( V_4 -> V_87 [ V_35 ] ) ) ;
F_8 ( V_4 -> V_15 , V_93 ,
V_92 , V_81 - 1 ) ;
}
F_3 ( V_79 -> V_6 , L_17 ,
V_4 -> V_87 [ V_35 ] , V_81 , V_83 ) ;
return 0 ;
}
static int F_18 ( struct V_94 * V_95 ,
struct V_96 * V_97 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_95 -> V_98 == V_99 ;
unsigned int V_100 = F_19 ( V_97 ) ;
T_2 V_101 = F_20 ( F_21 ( V_97 ) ) ;
T_2 V_53 = 0 , V_102 = 0 ;
int V_49 ;
if ( ! V_4 -> V_76 ) {
V_49 = F_15 ( V_31 , V_35 ,
2 * V_101 * F_22 ( V_97 ) ) ;
if ( V_49 )
return V_49 ;
if ( ! ( V_4 -> V_103 & F_23 ( V_95 -> V_98 ) ) ) {
V_49 = F_24 ( V_4 -> V_86 [ V_4 -> V_87 [ V_35 ] ] ) ;
if ( V_49 )
return V_49 ;
V_4 -> V_103 |= F_23 ( V_95 -> V_98 ) ;
}
}
if ( ! V_4 -> V_63 )
V_53 |= F_25 ( V_101 ) ;
V_102 |= F_26 ( V_101 ) ;
V_102 |= F_27 ( V_101 ) ;
if ( V_4 -> V_54 )
V_102 |= F_28 ( 0 ) ;
else
V_102 |= F_28 ( V_101 - 1 ) ;
V_53 |= F_29 ( V_100 ) ;
F_8 ( V_4 -> V_15 , F_13 ( V_35 ) ,
V_104 | V_105 ,
V_53 ) ;
F_8 ( V_4 -> V_15 , F_30 ( V_35 ) ,
V_106 | V_107 |
V_108 , V_102 ) ;
F_5 ( V_4 -> V_15 , F_31 ( V_35 ) , ~ 0UL - ( ( 1 << V_100 ) - 1 ) ) ;
return 0 ;
}
static int F_32 ( struct V_94 * V_95 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_95 -> V_98 == V_99 ;
if ( ! V_4 -> V_76 &&
V_4 -> V_103 & F_23 ( V_95 -> V_98 ) ) {
F_33 ( V_4 -> V_86 [ V_4 -> V_87 [ V_35 ] ] ) ;
V_4 -> V_103 &= ~ F_23 ( V_95 -> V_98 ) ;
}
return 0 ;
}
static int F_34 ( struct V_94 * V_95 , int V_109 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_95 -> V_98 == V_99 ;
T_2 V_9 , V_110 = 100 ;
F_8 ( V_4 -> V_15 , V_93 , V_111 , 0 ) ;
F_8 ( V_4 -> V_15 , V_91 , V_111 ,
V_4 -> V_88 [ V_90 ] ? V_111 : 0 ) ;
switch ( V_109 ) {
case V_112 :
case V_113 :
case V_114 :
F_8 ( V_4 -> V_15 , F_35 ( V_35 ) ,
V_115 , V_115 ) ;
F_8 ( V_4 -> V_15 , V_26 ,
V_116 , V_116 ) ;
F_8 ( V_4 -> V_15 , V_16 ,
V_116 , V_116 ) ;
F_8 ( V_4 -> V_15 , F_35 ( V_35 ) ,
V_117 , V_12 ) ;
break;
case V_118 :
case V_119 :
case V_120 :
F_8 ( V_4 -> V_15 , F_35 ( V_35 ) ,
V_115 , 0 ) ;
F_8 ( V_4 -> V_15 , F_35 ( V_35 ) ,
V_117 , 0 ) ;
F_2 ( V_4 -> V_15 , F_35 ( ! V_35 ) , & V_9 ) ;
if ( ! ( V_9 & V_115 ) ) {
F_8 ( V_4 -> V_15 , V_16 ,
V_116 , 0 ) ;
F_8 ( V_4 -> V_15 , V_26 ,
V_116 , 0 ) ;
do {
F_36 ( 10 ) ;
F_2 ( V_4 -> V_15 , F_35 ( V_35 ) , & V_9 ) ;
} while ( -- V_110 && V_9 & V_116 );
F_8 ( V_4 -> V_15 , V_16 ,
V_21 , V_21 ) ;
F_8 ( V_4 -> V_15 , V_26 ,
V_21 , V_21 ) ;
}
break;
default:
return - V_46 ;
}
return 0 ;
}
static int F_37 ( struct V_94 * V_95 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_95 -> V_98 == V_99 ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
int V_49 ;
V_49 = F_24 ( V_4 -> V_121 ) ;
if ( V_49 ) {
F_11 ( V_6 , L_18 , V_49 ) ;
return V_49 ;
}
F_8 ( V_4 -> V_15 , F_38 ( V_35 ) , V_122 ,
V_122 ) ;
V_49 = F_39 ( V_95 -> V_123 , 0 ,
V_124 , & V_125 ) ;
return V_49 ;
}
static void F_40 ( struct V_94 * V_95 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_35 = V_95 -> V_98 == V_99 ;
F_8 ( V_4 -> V_15 , F_38 ( V_35 ) , V_122 , 0 ) ;
F_33 ( V_4 -> V_121 ) ;
}
static int F_41 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_42 ( V_31 -> V_6 ) ;
F_5 ( V_4 -> V_15 , V_16 , V_126 ) ;
F_5 ( V_4 -> V_15 , V_26 , V_126 ) ;
F_5 ( V_4 -> V_15 , V_16 , 0 ) ;
F_5 ( V_4 -> V_15 , V_26 , 0 ) ;
F_8 ( V_4 -> V_15 , V_127 , V_128 ,
V_129 * 2 ) ;
F_8 ( V_4 -> V_15 , V_130 , V_128 ,
V_131 - 1 ) ;
F_43 ( V_31 , & V_4 -> V_132 ,
& V_4 -> V_133 ) ;
F_44 ( V_31 , V_4 ) ;
return 0 ;
}
static bool F_45 ( struct V_5 * V_6 , unsigned int V_134 )
{
switch ( V_134 ) {
case V_16 :
case V_127 :
case V_93 :
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_26 :
case V_130 :
case V_91 :
case V_140 :
case V_141 :
case V_142 :
case V_143 :
case V_144 :
case V_145 :
return true ;
default:
return false ;
}
}
static bool F_46 ( struct V_5 * V_6 , unsigned int V_134 )
{
switch ( V_134 ) {
case V_138 :
case V_144 :
case V_146 :
case V_143 :
return true ;
default:
return false ;
}
}
static bool F_47 ( struct V_5 * V_6 , unsigned int V_134 )
{
switch ( V_134 ) {
case V_16 :
case V_127 :
case V_93 :
case V_135 :
case V_136 :
case V_137 :
case V_146 :
case V_139 :
case V_26 :
case V_130 :
case V_91 :
case V_140 :
case V_141 :
case V_142 :
case V_145 :
return true ;
default:
return false ;
}
}
static int F_48 ( struct V_147 * V_7 )
{
struct V_148 * V_149 = V_7 -> V_6 . V_150 ;
struct V_3 * V_4 ;
struct V_151 * V_152 ;
void T_3 * V_153 ;
char V_154 [ 8 ] ;
int V_1 , V_49 , V_155 ;
V_4 = F_49 ( & V_7 -> V_6 , sizeof( * V_4 ) , V_156 ) ;
if ( ! V_4 )
return - V_157 ;
V_4 -> V_7 = V_7 ;
if ( F_50 ( V_7 -> V_6 . V_150 , L_19 ) )
V_4 -> V_158 = true ;
V_4 -> V_54 = F_51 ( V_149 , L_20 ) ;
V_152 = F_52 ( V_7 , V_159 , 0 ) ;
V_153 = F_53 ( & V_7 -> V_6 , V_152 ) ;
if ( F_54 ( V_153 ) )
return F_55 ( V_153 ) ;
V_4 -> V_15 = F_56 ( & V_7 -> V_6 ,
L_21 , V_153 , & V_160 ) ;
if ( F_54 ( V_4 -> V_15 ) )
V_4 -> V_15 = F_56 ( & V_7 -> V_6 ,
L_22 , V_153 , & V_160 ) ;
if ( F_54 ( V_4 -> V_15 ) ) {
F_11 ( & V_7 -> V_6 , L_23 ) ;
return F_55 ( V_4 -> V_15 ) ;
}
V_4 -> V_121 = F_57 ( & V_7 -> V_6 , L_21 ) ;
if ( F_54 ( V_4 -> V_121 ) ) {
F_11 ( & V_7 -> V_6 , L_24 ,
F_55 ( V_4 -> V_121 ) ) ;
V_4 -> V_121 = NULL ;
}
V_4 -> V_86 [ 0 ] = V_4 -> V_121 ;
for ( V_155 = 1 ; V_155 < V_85 ; V_155 ++ ) {
sprintf ( V_154 , L_25 , V_155 ) ;
V_4 -> V_86 [ V_155 ] = F_57 ( & V_7 -> V_6 , V_154 ) ;
if ( F_54 ( V_4 -> V_86 [ V_155 ] ) ) {
F_11 ( & V_7 -> V_6 , L_26 ,
V_155 + 1 , F_55 ( V_4 -> V_86 [ V_155 ] ) ) ;
V_4 -> V_86 [ V_155 ] = NULL ;
}
}
V_1 = F_58 ( V_7 , 0 ) ;
if ( V_1 < 0 ) {
F_11 ( & V_7 -> V_6 , L_27 , V_7 -> V_161 ) ;
return V_1 ;
}
V_49 = F_59 ( & V_7 -> V_6 , V_1 , F_1 , 0 , V_149 -> V_161 , V_4 ) ;
if ( V_49 ) {
F_11 ( & V_7 -> V_6 , L_28 , V_1 ) ;
return V_49 ;
}
V_4 -> V_88 [ V_90 ] = true ;
V_4 -> V_88 [ V_89 ] = false ;
V_162 . V_163 = 1 ;
V_162 . V_164 = 1 ;
V_162 . V_165 = 1 ;
if ( F_60 ( V_149 , L_29 , NULL ) &&
F_60 ( V_149 , L_30 , NULL ) ) {
F_11 ( & V_7 -> V_6 , L_31 ) ;
return - V_46 ;
}
if ( F_60 ( V_149 , L_29 , NULL ) ) {
V_4 -> V_88 [ V_90 ] = false ;
V_4 -> V_88 [ V_89 ] = true ;
} else if ( F_60 ( V_149 , L_30 , NULL ) ) {
V_4 -> V_88 [ V_90 ] = false ;
V_4 -> V_88 [ V_89 ] = false ;
V_162 . V_163 = 0 ;
V_162 . V_164 = 0 ;
V_162 . V_165 = 0 ;
}
V_4 -> V_133 . V_166 = V_152 -> V_167 + V_143 ;
V_4 -> V_132 . V_166 = V_152 -> V_167 + V_146 ;
V_4 -> V_133 . V_168 = V_131 ;
V_4 -> V_132 . V_168 = V_129 ;
F_61 ( V_7 , V_4 ) ;
V_49 = F_62 ( & V_7 -> V_6 , & V_169 ,
& V_162 , 1 ) ;
if ( V_49 )
return V_49 ;
if ( V_4 -> V_158 )
return F_63 ( V_7 , V_170 ) ;
else
return F_64 ( & V_7 -> V_6 , NULL , 0 ) ;
}
