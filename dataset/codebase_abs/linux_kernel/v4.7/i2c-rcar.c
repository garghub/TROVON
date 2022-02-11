static void F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_6 , 0 ) ;
F_1 ( V_2 , V_7 , V_8 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
F_1 ( V_2 , V_10 , V_2 -> V_11 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
if ( ! ( F_3 ( V_2 , V_7 ) & V_14 ) )
return 0 ;
F_7 ( 1 ) ;
}
return - V_15 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
T_1 V_18 , V_19 , V_20 , V_21 , V_22 , V_23 , V_24 ;
unsigned long V_25 ;
struct V_26 * V_27 = F_9 ( V_2 ) ;
V_17 -> V_28 = V_17 -> V_28 ? : 100000 ;
V_17 -> V_29 = V_17 -> V_29 ? : 35 ;
V_17 -> V_30 = V_17 -> V_30 ? : 200 ;
V_17 -> V_31 = V_17 -> V_31 ? : 50 ;
switch ( V_2 -> V_32 ) {
case V_33 :
V_24 = 2 ;
break;
case V_34 :
case V_35 :
V_24 = 3 ;
break;
default:
F_10 ( V_27 , L_1 ) ;
return - V_36 ;
}
V_25 = F_11 ( V_2 -> V_37 ) ;
V_19 = V_25 / 20000000 ;
if ( V_19 >= 1U << V_24 ) {
F_10 ( V_27 , L_2 , V_25 ) ;
return - V_36 ;
}
V_21 = V_25 / ( V_19 + 1 ) ;
V_22 = V_17 -> V_29 + V_17 -> V_30 + V_17 -> V_31 ;
V_20 = ( V_21 + 500000 ) / 1000000 * V_22 ;
V_20 = ( V_20 + 500 ) / 1000 ;
for ( V_18 = 0 ; V_18 < 0x40 ; V_18 ++ ) {
V_23 = V_21 / ( 20 + ( V_18 * 8 ) + V_20 ) ;
if ( V_23 <= V_17 -> V_28 )
goto V_38;
}
F_10 ( V_27 , L_3 ) ;
return - V_36 ;
V_38:
F_12 ( V_27 , L_4 ,
V_23 , V_17 -> V_28 , F_11 ( V_2 -> V_37 ) , V_20 , V_19 , V_18 ) ;
V_2 -> V_11 = V_18 << V_24 | V_19 ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 )
{
int V_39 = ! ! F_14 ( V_2 ) ;
V_2 -> V_40 = 0 ;
if ( V_2 -> V_41 == 1 )
V_2 -> V_42 |= V_43 ;
F_1 ( V_2 , V_44 , ( V_2 -> V_45 -> V_46 << 1 ) | V_39 ) ;
if ( V_2 -> V_42 & V_47 ) {
F_1 ( V_2 , V_9 , 0 ) ;
F_1 ( V_2 , V_7 , V_48 ) ;
} else {
F_1 ( V_2 , V_7 , V_48 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
}
F_1 ( V_2 , V_6 , V_39 ? V_49 : V_50 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_45 ++ ;
V_2 -> V_41 -- ;
V_2 -> V_42 &= V_51 ;
F_13 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = V_2 -> V_54 == V_55
? V_2 -> V_56 : V_2 -> V_57 ;
F_1 ( V_2 , V_58 , 0 ) ;
F_1 ( V_2 , V_59 , V_60 ) ;
F_17 ( V_53 -> V_26 -> V_27 , F_18 ( & V_2 -> V_61 ) ,
V_2 -> V_45 -> V_62 , V_2 -> V_54 ) ;
V_2 -> V_54 = V_63 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_54 == V_63 )
return;
else if ( V_2 -> V_54 == V_55 )
F_20 ( V_2 -> V_56 ) ;
else if ( V_2 -> V_54 == V_64 )
F_20 ( V_2 -> V_57 ) ;
F_16 ( V_2 ) ;
}
static void F_21 ( void * V_65 )
{
struct V_1 * V_2 = V_65 ;
V_2 -> V_40 += F_22 ( & V_2 -> V_61 ) ;
F_16 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
struct V_66 * V_45 = V_2 -> V_45 ;
bool V_39 = V_45 -> V_42 & V_67 ;
enum V_68 V_69 = V_39 ? V_55 : V_64 ;
struct V_52 * V_53 = V_39 ? V_2 -> V_56 : V_2 -> V_57 ;
struct V_70 * V_71 ;
T_2 V_72 ;
T_3 V_73 ;
unsigned char * V_74 ;
int V_62 ;
if ( F_24 ( V_53 ) || V_45 -> V_62 < 8 )
return;
if ( V_39 ) {
V_74 = V_2 -> V_45 -> V_74 ;
V_62 = V_2 -> V_45 -> V_62 - 2 ;
} else {
V_74 = V_2 -> V_45 -> V_74 + 1 ;
V_62 = V_2 -> V_45 -> V_62 - 1 ;
}
V_72 = F_25 ( V_53 -> V_26 -> V_27 , V_74 , V_62 , V_69 ) ;
if ( F_26 ( V_27 , V_72 ) ) {
F_12 ( V_27 , L_5 ) ;
return;
}
F_22 ( & V_2 -> V_61 ) = V_62 ;
F_18 ( & V_2 -> V_61 ) = V_72 ;
V_2 -> V_54 = V_69 ;
V_71 = F_27 ( V_53 , & V_2 -> V_61 , 1 ,
V_39 ? V_75 : V_76 ,
V_77 | V_78 ) ;
if ( ! V_71 ) {
F_12 ( V_27 , L_6 ) ;
F_19 ( V_2 ) ;
return;
}
V_71 -> V_79 = F_21 ;
V_71 -> V_80 = V_2 ;
V_73 = F_28 ( V_71 ) ;
if ( F_29 ( V_73 ) ) {
F_12 ( V_27 , L_7 ) ;
F_19 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_59 , V_81 ) ;
if ( V_39 )
F_1 ( V_2 , V_58 , V_82 ) ;
else
F_1 ( V_2 , V_58 , V_83 ) ;
F_30 ( V_53 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_84 )
{
struct V_66 * V_45 = V_2 -> V_45 ;
if ( ! ( V_84 & V_85 ) )
return;
if ( V_2 -> V_40 < V_45 -> V_62 ) {
F_1 ( V_2 , V_86 , V_45 -> V_74 [ V_2 -> V_40 ] ) ;
V_2 -> V_40 ++ ;
if ( V_84 & V_87 )
F_23 ( V_2 ) ;
} else {
if ( V_2 -> V_42 & V_43 ) {
F_1 ( V_2 , V_7 , V_88 ) ;
} else {
F_15 ( V_2 ) ;
return;
}
}
F_1 ( V_2 , V_9 , V_89 ) ;
}
static void F_32 ( struct V_1 * V_2 , T_1 V_84 )
{
struct V_66 * V_45 = V_2 -> V_45 ;
if ( ! ( V_84 & V_90 ) )
return;
if ( V_84 & V_87 ) {
F_23 ( V_2 ) ;
} else if ( V_2 -> V_40 < V_45 -> V_62 ) {
V_45 -> V_74 [ V_2 -> V_40 ] = F_3 ( V_2 , V_86 ) ;
V_2 -> V_40 ++ ;
}
if ( V_2 -> V_40 + 1 >= V_45 -> V_62 )
F_1 ( V_2 , V_7 , V_88 ) ;
if ( V_2 -> V_40 == V_45 -> V_62 && ! ( V_2 -> V_42 & V_43 ) )
F_15 ( V_2 ) ;
else
F_1 ( V_2 , V_9 , V_91 ) ;
}
static bool F_33 ( struct V_1 * V_2 )
{
T_1 V_92 , V_93 ;
T_4 V_94 ;
V_92 = F_3 ( V_2 , V_95 ) & 0xff ;
V_93 = V_92 & F_3 ( V_2 , V_96 ) ;
if ( ! V_93 )
return false ;
if ( V_93 & V_97 ) {
if ( V_92 & V_98 ) {
F_34 ( V_2 -> V_99 , V_100 , & V_94 ) ;
F_1 ( V_2 , V_86 , V_94 ) ;
F_1 ( V_2 , V_96 , V_101 | V_102 | V_97 ) ;
} else {
F_34 ( V_2 -> V_99 , V_103 , & V_94 ) ;
F_3 ( V_2 , V_86 ) ;
F_1 ( V_2 , V_96 , V_104 | V_102 | V_97 ) ;
}
F_1 ( V_2 , V_95 , ~ V_97 & 0xff ) ;
}
if ( V_93 & V_102 ) {
F_34 ( V_2 -> V_99 , V_105 , & V_94 ) ;
F_1 ( V_2 , V_96 , V_97 | V_102 ) ;
F_1 ( V_2 , V_95 , ~ V_102 & 0xff ) ;
}
if ( V_93 & V_104 ) {
int V_106 ;
V_94 = F_3 ( V_2 , V_86 ) ;
V_106 = F_34 ( V_2 -> V_99 , V_107 , & V_94 ) ;
F_1 ( V_2 , V_108 , V_109 | V_110 | ( V_106 < 0 ? V_111 : 0 ) ) ;
F_1 ( V_2 , V_95 , ~ V_104 & 0xff ) ;
}
if ( V_93 & V_101 ) {
F_34 ( V_2 -> V_99 , V_112 , & V_94 ) ;
F_1 ( V_2 , V_86 , V_94 ) ;
F_1 ( V_2 , V_95 , ~ V_101 & 0xff ) ;
}
return true ;
}
static T_5 F_35 ( int V_113 , void * V_114 )
{
struct V_1 * V_2 = V_114 ;
T_1 V_84 , V_4 ;
V_4 = F_3 ( V_2 , V_7 ) ;
F_1 ( V_2 , V_7 , V_4 & V_115 ) ;
V_84 = F_3 ( V_2 , V_9 ) ;
V_84 &= F_3 ( V_2 , V_6 ) ;
if ( ! V_84 ) {
if ( F_33 ( V_2 ) )
return V_116 ;
return V_117 ;
}
if ( V_84 & V_118 ) {
V_2 -> V_42 |= V_119 | V_120 ;
goto V_121;
}
if ( V_84 & V_122 ) {
F_1 ( V_2 , V_6 , V_123 ) ;
V_2 -> V_42 |= V_124 ;
goto V_121;
}
if ( V_84 & V_125 ) {
V_2 -> V_41 -- ;
V_2 -> V_42 |= V_119 ;
goto V_121;
}
if ( F_14 ( V_2 ) )
F_32 ( V_2 , V_84 ) ;
else
F_31 ( V_2 , V_84 ) ;
V_121:
if ( V_2 -> V_42 & V_119 ) {
F_1 ( V_2 , V_6 , 0 ) ;
F_1 ( V_2 , V_9 , 0 ) ;
F_36 ( & V_2 -> V_126 ) ;
}
return V_116 ;
}
static struct V_52 * F_37 ( struct V_26 * V_27 ,
enum V_127 V_69 ,
T_2 V_128 )
{
struct V_52 * V_53 ;
struct V_129 V_130 ;
char * V_131 = V_69 == V_76 ? L_8 : L_9 ;
int V_106 ;
V_53 = F_38 ( V_27 , V_131 ) ;
if ( F_24 ( V_53 ) ) {
V_106 = F_39 ( V_53 ) ;
F_12 ( V_27 , L_10 ,
V_131 , V_106 ) ;
return V_53 ;
}
memset ( & V_130 , 0 , sizeof( V_130 ) ) ;
V_130 . V_132 = V_69 ;
if ( V_69 == V_76 ) {
V_130 . V_133 = V_128 ;
V_130 . V_134 = V_135 ;
} else {
V_130 . V_136 = V_128 ;
V_130 . V_137 = V_135 ;
}
V_106 = F_40 ( V_53 , & V_130 ) ;
if ( V_106 ) {
F_12 ( V_27 , L_11 ,
V_131 , V_106 ) ;
F_41 ( V_53 ) ;
return F_42 ( V_106 ) ;
}
F_12 ( V_27 , L_12 , V_131 ) ;
return V_53 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_66 * V_45 )
{
struct V_26 * V_27 = F_9 ( V_2 ) ;
bool V_39 ;
struct V_52 * V_53 ;
enum V_127 V_69 ;
V_39 = V_45 -> V_42 & V_67 ;
V_53 = V_39 ? V_2 -> V_56 : V_2 -> V_57 ;
if ( F_39 ( V_53 ) != - V_138 )
return;
V_69 = V_39 ? V_75 : V_76 ;
V_53 = F_37 ( V_27 , V_69 , V_2 -> V_139 -> V_140 + V_86 ) ;
if ( V_39 )
V_2 -> V_56 = V_53 ;
else
V_2 -> V_57 = V_53 ;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( ! F_24 ( V_2 -> V_57 ) ) {
F_41 ( V_2 -> V_57 ) ;
V_2 -> V_57 = F_42 ( - V_138 ) ;
}
if ( ! F_24 ( V_2 -> V_56 ) ) {
F_41 ( V_2 -> V_56 ) ;
V_2 -> V_56 = F_42 ( - V_138 ) ;
}
}
static int F_45 ( struct V_141 * V_142 ,
struct V_66 * V_143 ,
int V_144 )
{
struct V_1 * V_2 = F_46 ( V_142 ) ;
struct V_26 * V_27 = F_9 ( V_2 ) ;
int V_12 , V_106 ;
long V_145 ;
F_47 ( V_27 ) ;
V_106 = F_6 ( V_2 ) ;
if ( V_106 < 0 )
goto V_121;
for ( V_12 = 0 ; V_12 < V_144 ; V_12 ++ ) {
if ( V_143 [ V_12 ] . V_62 == 0 ) {
V_106 = - V_146 ;
goto V_121;
}
F_43 ( V_2 , V_143 + V_12 ) ;
}
V_2 -> V_45 = V_143 ;
V_2 -> V_41 = V_144 ;
V_2 -> V_42 = ( V_2 -> V_42 & V_51 ) | V_47 ;
F_13 ( V_2 ) ;
V_145 = F_48 ( V_2 -> V_126 , V_2 -> V_42 & V_119 ,
V_144 * V_142 -> V_147 ) ;
if ( ! V_145 ) {
F_19 ( V_2 ) ;
F_5 ( V_2 ) ;
V_106 = - V_148 ;
} else if ( V_2 -> V_42 & V_124 ) {
V_106 = - V_149 ;
} else if ( V_2 -> V_42 & V_120 ) {
V_106 = - V_150 ;
} else {
V_106 = V_144 - V_2 -> V_41 ;
}
V_121:
F_49 ( V_27 ) ;
if ( V_106 < 0 && V_106 != - V_149 )
F_10 ( V_27 , L_13 , V_106 , V_2 -> V_42 ) ;
return V_106 ;
}
static int F_50 ( struct V_151 * V_99 )
{
struct V_1 * V_2 = F_46 ( V_99 -> V_152 ) ;
if ( V_2 -> V_99 )
return - V_15 ;
if ( V_99 -> V_42 & V_153 )
return - V_154 ;
F_47 ( F_9 ( V_2 ) ) ;
V_2 -> V_99 = V_99 ;
F_1 ( V_2 , V_155 , V_99 -> V_46 ) ;
F_1 ( V_2 , V_95 , 0 ) ;
F_1 ( V_2 , V_96 , V_97 | V_102 ) ;
F_1 ( V_2 , V_108 , V_109 | V_110 ) ;
return 0 ;
}
static int F_51 ( struct V_151 * V_99 )
{
struct V_1 * V_2 = F_46 ( V_99 -> V_152 ) ;
F_52 ( ! V_2 -> V_99 ) ;
F_1 ( V_2 , V_96 , 0 ) ;
F_1 ( V_2 , V_108 , 0 ) ;
V_2 -> V_99 = NULL ;
F_49 ( F_9 ( V_2 ) ) ;
return 0 ;
}
static T_1 F_53 ( struct V_141 * V_142 )
{
return V_156 | V_157 |
( V_158 & ~ V_159 ) ;
}
static int F_54 ( struct V_160 * V_161 )
{
struct V_1 * V_2 ;
struct V_141 * V_142 ;
struct V_26 * V_27 = & V_161 -> V_27 ;
struct V_16 V_162 ;
int V_113 , V_106 ;
V_2 = F_55 ( V_27 , sizeof( struct V_1 ) , V_163 ) ;
if ( ! V_2 )
return - V_164 ;
V_2 -> V_37 = F_56 ( V_27 , NULL ) ;
if ( F_24 ( V_2 -> V_37 ) ) {
F_10 ( V_27 , L_14 ) ;
return F_39 ( V_2 -> V_37 ) ;
}
V_2 -> V_139 = F_57 ( V_161 , V_165 , 0 ) ;
V_2 -> V_5 = F_58 ( V_27 , V_2 -> V_139 ) ;
if ( F_24 ( V_2 -> V_5 ) )
return F_39 ( V_2 -> V_5 ) ;
V_2 -> V_32 = (enum V_166 ) F_59 ( V_27 ) ;
F_60 ( & V_2 -> V_126 ) ;
V_142 = & V_2 -> V_142 ;
V_142 -> V_167 = V_161 -> V_168 ;
V_142 -> V_169 = & V_170 ;
V_142 -> V_171 = V_172 ;
V_142 -> V_173 = 3 ;
V_142 -> V_27 . V_174 = V_27 ;
V_142 -> V_27 . V_175 = V_27 -> V_175 ;
F_61 ( V_142 , V_2 ) ;
F_62 ( V_142 -> V_176 , V_161 -> V_176 , sizeof( V_142 -> V_176 ) ) ;
F_63 ( V_27 , & V_162 , false ) ;
F_64 ( & V_2 -> V_61 , 1 ) ;
V_2 -> V_54 = V_63 ;
V_2 -> V_56 = V_2 -> V_57 = F_42 ( - V_138 ) ;
F_65 ( V_27 ) ;
F_47 ( V_27 ) ;
V_106 = F_8 ( V_2 , & V_162 ) ;
if ( V_106 < 0 )
goto V_177;
F_5 ( V_2 ) ;
if ( F_66 ( V_27 -> V_175 , L_15 ) )
V_2 -> V_42 |= V_178 ;
else
F_49 ( V_27 ) ;
V_113 = F_67 ( V_161 , 0 ) ;
V_106 = F_68 ( V_27 , V_113 , F_35 , 0 , F_69 ( V_27 ) , V_2 ) ;
if ( V_106 < 0 ) {
F_10 ( V_27 , L_16 , V_113 ) ;
goto V_179;
}
F_70 ( V_161 , V_2 ) ;
V_106 = F_71 ( V_142 ) ;
if ( V_106 < 0 ) {
F_10 ( V_27 , L_17 , V_106 ) ;
goto V_179;
}
F_72 ( V_27 , L_18 ) ;
return 0 ;
V_177:
F_49 ( V_27 ) ;
V_179:
F_73 ( V_27 ) ;
return V_106 ;
}
static int F_74 ( struct V_160 * V_161 )
{
struct V_1 * V_2 = F_75 ( V_161 ) ;
struct V_26 * V_27 = & V_161 -> V_27 ;
F_76 ( & V_2 -> V_142 ) ;
F_44 ( V_2 ) ;
if ( V_2 -> V_42 & V_178 )
F_49 ( V_27 ) ;
F_73 ( V_27 ) ;
return 0 ;
}
