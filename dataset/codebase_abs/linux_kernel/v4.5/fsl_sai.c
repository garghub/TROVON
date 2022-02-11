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
static int F_6 ( struct V_30 * V_31 , T_2 V_32 ,
T_2 V_33 , int V_34 , int V_35 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
V_4 -> V_34 = V_34 ;
V_4 -> V_35 = V_35 ;
return 0 ;
}
static int F_8 ( struct V_30 * V_31 ,
int V_36 , unsigned int V_37 , int V_38 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_39 = V_38 == V_40 ;
T_2 V_41 = 0 ;
switch ( V_36 ) {
case V_42 :
V_41 |= V_43 ;
break;
case V_44 :
V_41 |= V_45 ;
break;
case V_46 :
V_41 |= V_47 ;
break;
case V_48 :
V_41 |= V_49 ;
break;
default:
return - V_50 ;
}
F_9 ( V_4 -> V_15 , F_10 ( V_39 ) ,
V_51 , V_41 ) ;
return 0 ;
}
static int F_11 ( struct V_30 * V_31 ,
int V_36 , unsigned int V_37 , int V_52 )
{
int V_53 ;
if ( V_52 == V_54 )
return 0 ;
V_53 = F_8 ( V_31 , V_36 , V_37 ,
V_40 ) ;
if ( V_53 ) {
F_12 ( V_31 -> V_6 , L_11 , V_53 ) ;
return V_53 ;
}
V_53 = F_8 ( V_31 , V_36 , V_37 ,
V_55 ) ;
if ( V_53 )
F_12 ( V_31 -> V_6 , L_12 , V_53 ) ;
return V_53 ;
}
static int F_13 ( struct V_30 * V_31 ,
unsigned int V_56 , int V_38 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_39 = V_38 == V_40 ;
T_2 V_41 = 0 , V_57 = 0 ;
if ( ! V_4 -> V_58 )
V_57 |= V_59 ;
switch ( V_56 & V_60 ) {
case V_61 :
V_41 |= V_62 ;
V_57 |= V_63 | V_64 ;
break;
case V_65 :
V_41 |= V_62 ;
break;
case V_66 :
V_41 |= V_62 ;
V_57 |= V_63 ;
V_4 -> V_67 = true ;
break;
case V_68 :
V_41 |= V_62 ;
V_4 -> V_67 = true ;
break;
case V_69 :
default:
return - V_50 ;
}
switch ( V_56 & V_70 ) {
case V_71 :
V_41 ^= V_62 ;
V_57 ^= V_64 ;
break;
case V_72 :
V_41 ^= V_62 ;
break;
case V_73 :
V_57 ^= V_64 ;
break;
case V_74 :
break;
default:
return - V_50 ;
}
switch ( V_56 & V_75 ) {
case V_76 :
V_41 |= V_77 ;
V_57 |= V_78 ;
break;
case V_79 :
V_4 -> V_80 = true ;
break;
case V_81 :
V_41 |= V_77 ;
break;
case V_82 :
V_57 |= V_78 ;
V_4 -> V_80 = true ;
break;
default:
return - V_50 ;
}
F_9 ( V_4 -> V_15 , F_10 ( V_39 ) ,
V_62 | V_77 , V_41 ) ;
F_9 ( V_4 -> V_15 , F_14 ( V_39 ) ,
V_59 | V_63 |
V_64 | V_78 , V_57 ) ;
return 0 ;
}
static int F_15 ( struct V_30 * V_31 , unsigned int V_56 )
{
int V_53 ;
V_53 = F_13 ( V_31 , V_56 , V_40 ) ;
if ( V_53 ) {
F_12 ( V_31 -> V_6 , L_13 , V_53 ) ;
return V_53 ;
}
V_53 = F_13 ( V_31 , V_56 , V_55 ) ;
if ( V_53 )
F_12 ( V_31 -> V_6 , L_14 , V_53 ) ;
return V_53 ;
}
static int F_16 ( struct V_30 * V_83 , bool V_39 , T_2 V_37 )
{
struct V_3 * V_4 = F_7 ( V_83 ) ;
unsigned long V_84 ;
T_2 V_85 = 0 , V_86 , V_87 = V_37 ;
T_2 V_88 ;
int V_53 = 0 ;
if ( V_4 -> V_80 )
return 0 ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ ) {
V_84 = F_17 ( V_4 -> V_90 [ V_88 ] ) ;
if ( ! V_84 )
continue;
V_86 = V_84 / V_37 ;
V_53 = V_84 - V_86 * V_37 ;
if ( V_53 != 0 && V_84 / V_53 < 1000 )
continue;
F_3 ( V_83 -> V_6 ,
L_15 ,
V_86 , V_37 , V_84 ) ;
if ( V_86 % 2 == 0 && V_86 >= 2 && V_86 <= 512 )
V_86 /= 2 ;
else
continue;
if ( V_53 < V_87 ) {
V_85 = V_86 ;
V_4 -> V_91 [ V_39 ] = V_88 ;
V_87 = V_53 ;
}
if ( V_53 == 0 )
break;
}
if ( V_85 == 0 ) {
F_12 ( V_83 -> V_6 , L_16 ,
V_39 ? 'T' : 'R' , V_37 ) ;
return - V_50 ;
}
if ( ( V_4 -> V_92 [ V_93 ] && ! V_4 -> V_92 [ V_94 ] ) ||
( ! V_39 && ! V_4 -> V_92 [ V_94 ] ) ) {
F_9 ( V_4 -> V_15 , V_95 ,
V_51 ,
F_18 ( V_4 -> V_91 [ V_39 ] ) ) ;
F_9 ( V_4 -> V_15 , V_95 ,
V_96 , V_85 - 1 ) ;
} else if ( ( V_4 -> V_92 [ V_94 ] && ! V_4 -> V_92 [ V_93 ] ) ||
( V_39 && ! V_4 -> V_92 [ V_93 ] ) ) {
F_9 ( V_4 -> V_15 , V_97 ,
V_51 ,
F_18 ( V_4 -> V_91 [ V_39 ] ) ) ;
F_9 ( V_4 -> V_15 , V_97 ,
V_96 , V_85 - 1 ) ;
}
F_3 ( V_83 -> V_6 , L_17 ,
V_4 -> V_91 [ V_39 ] , V_85 , V_87 ) ;
return 0 ;
}
static int F_19 ( struct V_98 * V_99 ,
struct V_100 * V_101 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_39 = V_99 -> V_102 == V_103 ;
unsigned int V_104 = F_20 ( V_101 ) ;
T_2 V_105 = F_21 ( V_101 ) ;
T_2 V_57 = 0 , V_106 = 0 ;
T_2 V_34 = ( V_104 == 1 ) ? 2 : V_104 ;
T_2 V_35 = V_105 ;
int V_53 ;
if ( V_4 -> V_34 )
V_34 = V_4 -> V_34 ;
if ( V_4 -> V_35 )
V_35 = V_4 -> V_35 ;
if ( ! V_4 -> V_80 ) {
V_53 = F_16 ( V_31 , V_39 ,
V_34 * V_35 * F_22 ( V_101 ) ) ;
if ( V_53 )
return V_53 ;
if ( ! ( V_4 -> V_107 & F_23 ( V_99 -> V_102 ) ) ) {
V_53 = F_24 ( V_4 -> V_90 [ V_4 -> V_91 [ V_39 ] ] ) ;
if ( V_53 )
return V_53 ;
V_4 -> V_107 |= F_23 ( V_99 -> V_102 ) ;
}
}
if ( ! V_4 -> V_67 )
V_57 |= F_25 ( V_35 ) ;
V_106 |= F_26 ( V_35 ) ;
V_106 |= F_27 ( V_35 ) ;
if ( V_4 -> V_58 )
V_106 |= F_28 ( 0 ) ;
else
V_106 |= F_28 ( V_105 - 1 ) ;
V_57 |= F_29 ( V_34 ) ;
if ( ! V_4 -> V_80 ) {
if ( ! V_4 -> V_92 [ V_93 ] && V_4 -> V_92 [ V_94 ] && ! V_39 ) {
F_9 ( V_4 -> V_15 , V_108 ,
V_109 | V_110 ,
V_57 ) ;
F_9 ( V_4 -> V_15 , V_111 ,
V_112 | V_113 |
V_114 , V_106 ) ;
F_5 ( V_4 -> V_15 , V_115 ,
~ 0UL - ( ( 1 << V_104 ) - 1 ) ) ;
} else if ( ! V_4 -> V_92 [ V_94 ] && V_4 -> V_92 [ V_93 ] && V_39 ) {
F_9 ( V_4 -> V_15 , V_116 ,
V_109 | V_110 ,
V_57 ) ;
F_9 ( V_4 -> V_15 , V_117 ,
V_112 | V_113 |
V_114 , V_106 ) ;
F_5 ( V_4 -> V_15 , V_118 ,
~ 0UL - ( ( 1 << V_104 ) - 1 ) ) ;
}
}
F_9 ( V_4 -> V_15 , F_14 ( V_39 ) ,
V_109 | V_110 ,
V_57 ) ;
F_9 ( V_4 -> V_15 , F_30 ( V_39 ) ,
V_112 | V_113 |
V_114 , V_106 ) ;
F_5 ( V_4 -> V_15 , F_31 ( V_39 ) , ~ 0UL - ( ( 1 << V_104 ) - 1 ) ) ;
return 0 ;
}
static int F_32 ( struct V_98 * V_99 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_39 = V_99 -> V_102 == V_103 ;
if ( ! V_4 -> V_80 &&
V_4 -> V_107 & F_23 ( V_99 -> V_102 ) ) {
F_33 ( V_4 -> V_90 [ V_4 -> V_91 [ V_39 ] ] ) ;
V_4 -> V_107 &= ~ F_23 ( V_99 -> V_102 ) ;
}
return 0 ;
}
static int F_34 ( struct V_98 * V_99 , int V_119 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_39 = V_99 -> V_102 == V_103 ;
T_2 V_9 , V_120 = 100 ;
F_9 ( V_4 -> V_15 , V_97 , V_121 ,
V_4 -> V_92 [ V_93 ] ? V_121 : 0 ) ;
F_9 ( V_4 -> V_15 , V_95 , V_121 ,
V_4 -> V_92 [ V_94 ] ? V_121 : 0 ) ;
switch ( V_119 ) {
case V_122 :
case V_123 :
case V_124 :
F_9 ( V_4 -> V_15 , F_35 ( V_39 ) ,
V_125 , V_125 ) ;
F_9 ( V_4 -> V_15 , V_26 ,
V_126 , V_126 ) ;
F_9 ( V_4 -> V_15 , V_16 ,
V_126 , V_126 ) ;
F_9 ( V_4 -> V_15 , F_35 ( V_39 ) ,
V_127 , V_12 ) ;
break;
case V_128 :
case V_129 :
case V_130 :
F_9 ( V_4 -> V_15 , F_35 ( V_39 ) ,
V_125 , 0 ) ;
F_9 ( V_4 -> V_15 , F_35 ( V_39 ) ,
V_127 , 0 ) ;
F_2 ( V_4 -> V_15 , F_35 ( ! V_39 ) , & V_9 ) ;
if ( ! ( V_9 & V_125 ) ) {
F_9 ( V_4 -> V_15 , V_16 ,
V_126 , 0 ) ;
F_9 ( V_4 -> V_15 , V_26 ,
V_126 , 0 ) ;
do {
F_36 ( 10 ) ;
F_2 ( V_4 -> V_15 , F_35 ( V_39 ) , & V_9 ) ;
} while ( -- V_120 && V_9 & V_126 );
F_9 ( V_4 -> V_15 , V_16 ,
V_21 , V_21 ) ;
F_9 ( V_4 -> V_15 , V_26 ,
V_21 , V_21 ) ;
if ( ! V_4 -> V_80 ) {
F_5 ( V_4 -> V_15 ,
V_16 , V_131 ) ;
F_5 ( V_4 -> V_15 ,
V_26 , V_131 ) ;
F_5 ( V_4 -> V_15 , V_16 , 0 ) ;
F_5 ( V_4 -> V_15 , V_26 , 0 ) ;
}
}
break;
default:
return - V_50 ;
}
return 0 ;
}
static int F_37 ( struct V_98 * V_99 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_39 = V_99 -> V_102 == V_103 ;
struct V_5 * V_6 = & V_4 -> V_7 -> V_6 ;
int V_53 ;
V_53 = F_24 ( V_4 -> V_132 ) ;
if ( V_53 ) {
F_12 ( V_6 , L_18 , V_53 ) ;
return V_53 ;
}
F_9 ( V_4 -> V_15 , F_38 ( V_39 ) , V_133 ,
V_133 ) ;
V_53 = F_39 ( V_99 -> V_134 , 0 ,
V_135 , & V_136 ) ;
return V_53 ;
}
static void F_40 ( struct V_98 * V_99 ,
struct V_30 * V_31 )
{
struct V_3 * V_4 = F_7 ( V_31 ) ;
bool V_39 = V_99 -> V_102 == V_103 ;
F_9 ( V_4 -> V_15 , F_38 ( V_39 ) , V_133 , 0 ) ;
F_33 ( V_4 -> V_132 ) ;
}
static int F_41 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = F_42 ( V_31 -> V_6 ) ;
F_5 ( V_4 -> V_15 , V_16 , V_131 ) ;
F_5 ( V_4 -> V_15 , V_26 , V_131 ) ;
F_5 ( V_4 -> V_15 , V_16 , 0 ) ;
F_5 ( V_4 -> V_15 , V_26 , 0 ) ;
F_9 ( V_4 -> V_15 , V_137 , V_138 ,
V_139 * 2 ) ;
F_9 ( V_4 -> V_15 , V_140 , V_138 ,
V_141 - 1 ) ;
F_43 ( V_31 , & V_4 -> V_142 ,
& V_4 -> V_143 ) ;
F_44 ( V_31 , V_4 ) ;
return 0 ;
}
static bool F_45 ( struct V_5 * V_6 , unsigned int V_144 )
{
switch ( V_144 ) {
case V_16 :
case V_137 :
case V_97 :
case V_145 :
case V_108 :
case V_111 :
case V_146 :
case V_115 :
case V_26 :
case V_140 :
case V_95 :
case V_147 :
case V_116 :
case V_117 :
case V_148 :
case V_149 :
case V_118 :
return true ;
default:
return false ;
}
}
static bool F_46 ( struct V_5 * V_6 , unsigned int V_144 )
{
switch ( V_144 ) {
case V_16 :
case V_26 :
case V_146 :
case V_149 :
case V_148 :
return true ;
default:
return false ;
}
}
static bool F_47 ( struct V_5 * V_6 , unsigned int V_144 )
{
switch ( V_144 ) {
case V_16 :
case V_137 :
case V_97 :
case V_145 :
case V_108 :
case V_111 :
case V_150 :
case V_115 :
case V_26 :
case V_140 :
case V_95 :
case V_147 :
case V_116 :
case V_117 :
case V_118 :
return true ;
default:
return false ;
}
}
static int F_48 ( struct V_151 * V_7 )
{
struct V_152 * V_153 = V_7 -> V_6 . V_154 ;
struct V_3 * V_4 ;
struct V_155 * V_156 ;
void T_3 * V_157 ;
char V_158 [ 8 ] ;
int V_1 , V_53 , V_159 ;
V_4 = F_49 ( & V_7 -> V_6 , sizeof( * V_4 ) , V_160 ) ;
if ( ! V_4 )
return - V_161 ;
V_4 -> V_7 = V_7 ;
if ( F_50 ( V_7 -> V_6 . V_154 , L_19 ) )
V_4 -> V_162 = true ;
V_4 -> V_58 = F_51 ( V_153 , L_20 ) ;
V_156 = F_52 ( V_7 , V_163 , 0 ) ;
V_157 = F_53 ( & V_7 -> V_6 , V_156 ) ;
if ( F_54 ( V_157 ) )
return F_55 ( V_157 ) ;
V_4 -> V_15 = F_56 ( & V_7 -> V_6 ,
L_21 , V_157 , & V_164 ) ;
if ( F_54 ( V_4 -> V_15 ) )
V_4 -> V_15 = F_56 ( & V_7 -> V_6 ,
L_22 , V_157 , & V_164 ) ;
if ( F_54 ( V_4 -> V_15 ) ) {
F_12 ( & V_7 -> V_6 , L_23 ) ;
return F_55 ( V_4 -> V_15 ) ;
}
V_4 -> V_132 = F_57 ( & V_7 -> V_6 , L_21 ) ;
if ( F_54 ( V_4 -> V_132 ) ) {
F_12 ( & V_7 -> V_6 , L_24 ,
F_55 ( V_4 -> V_132 ) ) ;
V_4 -> V_132 = NULL ;
}
V_4 -> V_90 [ 0 ] = V_4 -> V_132 ;
for ( V_159 = 1 ; V_159 < V_89 ; V_159 ++ ) {
sprintf ( V_158 , L_25 , V_159 ) ;
V_4 -> V_90 [ V_159 ] = F_57 ( & V_7 -> V_6 , V_158 ) ;
if ( F_54 ( V_4 -> V_90 [ V_159 ] ) ) {
F_12 ( & V_7 -> V_6 , L_26 ,
V_159 + 1 , F_55 ( V_4 -> V_90 [ V_159 ] ) ) ;
V_4 -> V_90 [ V_159 ] = NULL ;
}
}
V_1 = F_58 ( V_7 , 0 ) ;
if ( V_1 < 0 ) {
F_12 ( & V_7 -> V_6 , L_27 , V_7 -> V_165 ) ;
return V_1 ;
}
V_53 = F_59 ( & V_7 -> V_6 , V_1 , F_1 , 0 , V_153 -> V_165 , V_4 ) ;
if ( V_53 ) {
F_12 ( & V_7 -> V_6 , L_28 , V_1 ) ;
return V_53 ;
}
V_4 -> V_92 [ V_94 ] = true ;
V_4 -> V_92 [ V_93 ] = false ;
V_166 . V_167 = 1 ;
V_166 . V_168 = 1 ;
V_166 . V_169 = 1 ;
if ( F_60 ( V_153 , L_29 , NULL ) &&
F_60 ( V_153 , L_30 , NULL ) ) {
F_12 ( & V_7 -> V_6 , L_31 ) ;
return - V_50 ;
}
if ( F_60 ( V_153 , L_29 , NULL ) ) {
V_4 -> V_92 [ V_94 ] = false ;
V_4 -> V_92 [ V_93 ] = true ;
} else if ( F_60 ( V_153 , L_30 , NULL ) ) {
V_4 -> V_92 [ V_94 ] = false ;
V_4 -> V_92 [ V_93 ] = false ;
V_166 . V_167 = 0 ;
V_166 . V_168 = 0 ;
V_166 . V_169 = 0 ;
}
V_4 -> V_143 . V_170 = V_156 -> V_171 + V_148 ;
V_4 -> V_142 . V_170 = V_156 -> V_171 + V_150 ;
V_4 -> V_143 . V_172 = V_141 ;
V_4 -> V_142 . V_172 = V_139 ;
F_61 ( V_7 , V_4 ) ;
V_53 = F_62 ( & V_7 -> V_6 , & V_173 ,
& V_166 , 1 ) ;
if ( V_53 )
return V_53 ;
if ( V_4 -> V_162 )
return F_63 ( V_7 , V_174 ) ;
else
return F_64 ( & V_7 -> V_6 , NULL , 0 ) ;
}
static int F_65 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_42 ( V_6 ) ;
F_66 ( V_4 -> V_15 , true ) ;
F_67 ( V_4 -> V_15 ) ;
return 0 ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_42 ( V_6 ) ;
F_66 ( V_4 -> V_15 , false ) ;
F_5 ( V_4 -> V_15 , V_16 , V_131 ) ;
F_5 ( V_4 -> V_15 , V_26 , V_131 ) ;
F_69 ( 1 ) ;
F_5 ( V_4 -> V_15 , V_16 , 0 ) ;
F_5 ( V_4 -> V_15 , V_26 , 0 ) ;
return F_70 ( V_4 -> V_15 ) ;
}
