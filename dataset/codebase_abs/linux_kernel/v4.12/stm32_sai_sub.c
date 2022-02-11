static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_11 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
return true ;
default:
return false ;
}
}
static T_1 F_4 ( int V_12 , void * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_13 ;
struct V_16 * V_17 = V_15 -> V_17 ;
struct V_18 * V_19 = V_15 -> V_19 ;
unsigned int V_20 , V_21 , V_22 ;
T_2 V_23 = V_24 ;
F_5 ( V_15 -> V_25 , V_8 , & V_21 ) ;
F_5 ( V_15 -> V_25 , V_9 , & V_20 ) ;
V_22 = V_20 & V_21 ;
if ( ! V_22 )
return V_26 ;
F_6 ( V_15 -> V_25 , V_10 , V_27 ,
V_27 ) ;
if ( V_22 & V_28 ) {
F_7 ( & V_19 -> V_2 , L_1 ,
F_8 ( V_15 ) ? L_2 : L_3 ) ;
V_23 = V_29 ;
}
if ( V_22 & V_30 )
F_9 ( & V_19 -> V_2 , L_4 ) ;
if ( V_22 & V_31 ) {
F_7 ( & V_19 -> V_2 , L_5 ) ;
V_23 = V_32 ;
}
if ( V_22 & V_33 )
F_10 ( & V_19 -> V_2 , L_6 ) ;
if ( V_22 & V_34 ) {
F_10 ( & V_19 -> V_2 , L_7 ) ;
V_23 = V_29 ;
}
if ( V_22 & V_35 ) {
F_10 ( & V_19 -> V_2 , L_8 ) ;
V_23 = V_29 ;
}
if ( V_23 != V_24 ) {
F_11 ( V_17 ) ;
F_12 ( V_17 , V_29 ) ;
F_13 ( V_17 ) ;
}
return V_36 ;
}
static int F_14 ( struct V_37 * V_38 ,
int V_39 , unsigned int V_40 , int V_41 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
if ( ( V_41 == V_42 ) && V_15 -> V_43 ) {
V_15 -> V_44 = V_40 ;
F_9 ( V_38 -> V_2 , L_9 , V_40 ) ;
}
return 0 ;
}
static int F_16 ( struct V_37 * V_38 , T_3 V_45 ,
T_3 V_46 , int V_47 , int V_48 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
int V_49 , V_50 , V_51 ;
F_9 ( V_38 -> V_2 , L_10 ,
V_45 , V_46 , V_47 , V_48 ) ;
switch ( V_48 ) {
case 16 :
V_51 = V_52 ;
break;
case 32 :
V_51 = V_53 ;
break;
default:
V_51 = V_54 ;
break;
}
V_49 = F_17 ( V_51 ) |
F_18 ( V_47 - 1 ) ;
V_50 = V_55 | V_56 ;
if ( F_8 ( V_15 ) ) {
V_15 -> V_57 = V_45 ;
V_49 |= F_19 ( V_45 ) ;
}
if ( F_20 ( V_15 ) ) {
V_15 -> V_57 = V_46 ;
V_49 |= F_19 ( V_46 ) ;
}
V_50 |= V_58 ;
F_6 ( V_15 -> V_25 , V_7 , V_50 , V_49 ) ;
V_15 -> V_48 = V_48 ;
V_15 -> V_47 = V_47 ;
return 0 ;
}
static int F_21 ( struct V_37 * V_38 , unsigned int V_59 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
int V_60 = 0 , V_61 = 0 ;
int V_62 = 0 , V_63 = 0 ;
int V_64 ;
F_9 ( V_38 -> V_2 , L_11 , V_59 ) ;
switch ( V_59 & V_65 ) {
case V_66 :
V_60 |= V_67 ;
V_61 |= V_68 | V_69 ;
break;
case V_70 :
V_61 |= V_71 | V_69 ;
break;
case V_72 :
V_61 |= V_71 | V_69 ;
break;
case V_73 :
V_61 |= V_71 | V_68 ;
break;
case V_74 :
V_61 |= V_71 ;
break;
default:
F_7 ( V_38 -> V_2 , L_12 ,
V_59 & V_65 ) ;
return - V_75 ;
}
V_62 |= V_76 | V_67 ;
V_63 |= V_71 | V_68 |
V_69 ;
switch ( V_59 & V_77 ) {
case V_78 :
break;
case V_79 :
V_60 ^= V_67 ;
break;
case V_80 :
V_61 ^= V_71 ;
break;
case V_81 :
V_60 ^= V_67 ;
V_61 ^= V_71 ;
break;
default:
F_7 ( V_38 -> V_2 , L_13 ,
V_59 & V_77 ) ;
return - V_75 ;
}
V_62 |= V_67 ;
V_63 |= V_71 ;
F_6 ( V_15 -> V_25 , V_6 , V_63 , V_61 ) ;
switch ( V_59 & V_82 ) {
case V_83 :
V_60 |= V_84 ;
V_15 -> V_43 = false ;
break;
case V_85 :
V_15 -> V_43 = true ;
break;
default:
F_7 ( V_38 -> V_2 , L_14 ,
V_59 & V_82 ) ;
return - V_75 ;
}
V_62 |= V_84 ;
V_64 = F_6 ( V_15 -> V_25 , V_4 , V_62 , V_60 ) ;
if ( V_64 < 0 ) {
F_7 ( V_38 -> V_2 , L_15 ) ;
return V_64 ;
}
V_15 -> V_59 = V_59 ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_37 * V_38 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
int V_21 , V_86 , V_64 ;
V_15 -> V_17 = V_17 ;
V_64 = F_23 ( V_15 -> V_87 ) ;
if ( V_64 < 0 ) {
F_7 ( V_38 -> V_2 , L_16 , V_64 ) ;
return V_64 ;
}
F_6 ( V_15 -> V_25 , V_9 ,
V_88 , ( unsigned int ) ~ V_88 ) ;
F_6 ( V_15 -> V_25 , V_10 ,
V_27 , V_27 ) ;
V_21 = V_28 ;
if ( F_20 ( V_15 ) ) {
F_5 ( V_15 -> V_25 , V_5 , & V_86 ) ;
if ( V_86 & V_89 )
V_21 |= V_30 ;
}
if ( V_15 -> V_43 )
V_21 |= V_31 ;
else
V_21 |= V_34 | V_35 ;
F_6 ( V_15 -> V_25 , V_8 ,
V_90 , V_21 ) ;
return 0 ;
}
static int F_24 ( struct V_37 * V_38 ,
struct V_16 * V_17 ,
struct V_91 * V_92 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
int V_60 , V_62 , V_64 ;
int V_93 = V_94 ;
F_6 ( V_15 -> V_25 , V_5 ,
V_95 | V_96 ,
V_95 | F_25 ( V_93 ) ) ;
V_60 = F_26 ( V_97 ) ;
switch ( F_27 ( V_92 ) ) {
case V_98 :
V_60 |= F_28 ( V_99 ) ;
break;
case V_100 :
V_60 |= F_28 ( V_101 ) ;
break;
case V_102 :
V_60 |= F_28 ( V_103 ) ;
break;
default:
F_7 ( V_38 -> V_2 , L_17 ) ;
return - V_75 ;
}
V_62 = V_104 | V_76 ;
V_62 |= V_105 ;
if ( F_20 ( V_15 ) )
V_60 |= V_105 ;
V_62 |= V_106 ;
if ( ( V_15 -> V_47 == 2 ) && ( F_29 ( V_92 ) == 1 ) )
V_60 |= V_106 ;
V_64 = F_6 ( V_15 -> V_25 , V_4 , V_62 , V_60 ) ;
if ( V_64 < 0 ) {
F_7 ( V_38 -> V_2 , L_15 ) ;
return V_64 ;
}
V_15 -> V_107 . V_108 = V_109 * V_93 / sizeof( T_3 ) ;
F_30 ( V_38 , V_17 , ( void * ) & V_15 -> V_107 ) ;
return 0 ;
}
static int F_31 ( struct V_37 * V_38 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
int V_49 , V_110 ;
F_5 ( V_15 -> V_25 , V_7 , & V_49 ) ;
V_110 = V_49 & V_55 ;
if ( V_110 == F_17 ( V_54 ) )
V_15 -> V_48 = V_15 -> V_111 ;
if ( V_15 -> V_48 < V_15 -> V_111 ) {
F_7 ( V_38 -> V_2 ,
L_18 ,
V_15 -> V_111 ) ;
return - V_75 ;
}
if ( ! V_15 -> V_47 )
V_15 -> V_47 = 2 ;
F_6 ( V_15 -> V_25 , V_7 ,
V_56 ,
F_18 ( ( V_15 -> V_47 - 1 ) ) ) ;
if ( ! ( V_49 & V_58 ) ) {
V_15 -> V_57 = ( 1 << V_15 -> V_47 ) - 1 ;
F_6 ( V_15 -> V_25 ,
V_7 , V_58 ,
F_19 ( V_15 -> V_57 ) ) ;
}
F_9 ( V_38 -> V_2 , L_19 ,
V_15 -> V_47 , V_15 -> V_48 ) ;
return 0 ;
}
static void F_32 ( struct V_37 * V_38 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
int V_112 , V_113 , V_114 ;
int V_61 , V_63 ;
V_114 = V_15 -> V_59 & V_65 ;
V_15 -> V_115 = V_15 -> V_48 * V_15 -> V_47 ;
V_112 = V_15 -> V_115 / 2 ;
if ( ( V_114 == V_73 ) ||
( V_114 == V_74 ) )
V_112 = 1 ;
V_61 = F_33 ( ( V_15 -> V_115 - 1 ) ) ;
V_61 |= F_34 ( ( V_112 - 1 ) ) ;
V_63 = V_116 | V_117 ;
F_9 ( V_38 -> V_2 , L_20 ,
V_15 -> V_115 , V_112 ) ;
F_6 ( V_15 -> V_25 , V_6 , V_63 , V_61 ) ;
if ( ( V_15 -> V_59 & V_65 ) == V_72 ) {
V_113 = V_15 -> V_48 - V_15 -> V_111 ;
F_6 ( V_15 -> V_25 , V_7 ,
V_118 ,
F_35 ( V_113 ) ) ;
}
}
static int F_36 ( struct V_37 * V_38 ,
struct V_91 * V_92 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
int V_60 , V_119 , div = 0 ;
int V_120 , V_64 ;
if ( ! V_15 -> V_44 ) {
F_7 ( V_38 -> V_2 , L_21 ) ;
return - V_75 ;
}
if ( ! ( F_37 ( V_92 ) % 11025 ) )
F_38 ( V_15 -> V_87 , V_15 -> V_121 -> V_122 ) ;
else
F_38 ( V_15 -> V_87 , V_15 -> V_121 -> V_123 ) ;
V_120 = F_39 ( V_15 -> V_87 ) ;
if ( 2 * V_120 >= 3 * V_15 -> V_44 )
div = F_40 ( V_120 , 2 * V_15 -> V_44 ) ;
if ( div > V_124 ) {
F_7 ( V_38 -> V_2 , L_22 , div ) ;
return - V_75 ;
}
F_9 ( V_38 -> V_2 , L_23 , V_120 , div ) ;
V_119 = V_125 ;
V_60 = F_41 ( div ) ;
V_64 = F_6 ( V_15 -> V_25 , V_4 , V_119 , V_60 ) ;
if ( V_64 < 0 ) {
F_7 ( V_38 -> V_2 , L_15 ) ;
return V_64 ;
}
return 0 ;
}
static int F_42 ( struct V_16 * V_17 ,
struct V_91 * V_92 ,
struct V_37 * V_38 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
int V_64 ;
V_15 -> V_111 = F_43 ( V_92 ) ;
V_64 = F_31 ( V_38 ) ;
if ( V_64 < 0 )
return V_64 ;
F_32 ( V_38 ) ;
V_64 = F_24 ( V_38 , V_17 , V_92 ) ;
if ( V_64 )
return V_64 ;
if ( V_15 -> V_43 )
V_64 = F_36 ( V_38 , V_92 ) ;
return V_64 ;
}
static int F_44 ( struct V_16 * V_17 , int V_126 ,
struct V_37 * V_38 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
int V_64 ;
switch ( V_126 ) {
case V_127 :
case V_128 :
case V_129 :
F_9 ( V_38 -> V_2 , L_24 ) ;
F_6 ( V_15 -> V_25 , V_4 ,
V_130 , V_130 ) ;
V_64 = F_6 ( V_15 -> V_25 , V_4 ,
V_131 , V_131 ) ;
if ( V_64 < 0 )
F_7 ( V_38 -> V_2 , L_15 ) ;
break;
case V_132 :
case V_133 :
case V_134 :
F_9 ( V_38 -> V_2 , L_25 ) ;
F_6 ( V_15 -> V_25 , V_4 ,
V_130 ,
( unsigned int ) ~ V_130 ) ;
V_64 = F_6 ( V_15 -> V_25 , V_4 ,
V_131 ,
( unsigned int ) ~ V_131 ) ;
if ( V_64 < 0 )
F_7 ( V_38 -> V_2 , L_15 ) ;
break;
default:
return - V_75 ;
}
return V_64 ;
}
static void F_45 ( struct V_16 * V_17 ,
struct V_37 * V_38 )
{
struct V_14 * V_15 = F_15 ( V_38 ) ;
F_6 ( V_15 -> V_25 , V_8 , V_90 , 0 ) ;
F_46 ( V_15 -> V_87 ) ;
V_15 -> V_17 = NULL ;
}
static int F_47 ( struct V_37 * V_38 )
{
struct V_14 * V_15 = F_48 ( V_38 -> V_2 ) ;
V_15 -> V_107 . V_135 = ( V_136 ) ( V_15 -> V_137 + V_11 ) ;
V_15 -> V_107 . V_108 = 1 ;
V_15 -> V_107 . V_138 = V_139 ;
if ( F_8 ( V_15 ) )
F_49 ( V_38 , & V_15 -> V_107 , NULL ) ;
else
F_49 ( V_38 , NULL , & V_15 -> V_107 ) ;
return 0 ;
}
static int F_50 ( struct V_18 * V_19 ,
struct V_14 * V_15 )
{
struct V_140 * V_141 = V_19 -> V_2 . V_142 ;
struct V_143 * V_144 ;
void T_4 * V_145 ;
if ( ! V_141 )
return - V_146 ;
V_144 = F_51 ( V_19 , V_147 , 0 ) ;
F_7 ( & V_19 -> V_2 , L_26 , V_144 ) ;
V_145 = F_52 ( & V_19 -> V_2 , V_144 ) ;
if ( F_53 ( V_145 ) )
return F_54 ( V_145 ) ;
V_15 -> V_137 = V_144 -> V_148 ;
V_15 -> V_25 = F_55 ( & V_19 -> V_2 , V_145 ,
& V_149 ) ;
if ( F_56 ( V_141 , L_27 , L_28 ) >= 0 ) {
V_15 -> V_41 = V_150 ;
} else if ( F_56 ( V_141 , L_27 , L_29 ) >= 0 ) {
V_15 -> V_41 = V_151 ;
} else {
F_7 ( & V_19 -> V_2 , L_30 ) ;
return - V_75 ;
}
V_15 -> V_87 = F_57 ( & V_19 -> V_2 , L_31 ) ;
if ( F_53 ( V_15 -> V_87 ) ) {
F_7 ( & V_19 -> V_2 , L_32 ) ;
return F_54 ( V_15 -> V_87 ) ;
}
return 0 ;
}
static int F_58 ( struct V_18 * V_19 ,
struct V_14 * V_15 )
{
V_15 -> V_152 = F_59 ( & V_19 -> V_2 ,
sizeof( struct V_153 ) ,
V_154 ) ;
if ( ! V_15 -> V_152 )
return - V_155 ;
V_15 -> V_152 -> V_156 = F_60 ( & V_19 -> V_2 ) ;
if ( F_8 ( V_15 ) ) {
memcpy ( V_15 -> V_152 , & V_157 ,
sizeof( V_157 ) ) ;
V_15 -> V_152 -> V_158 . V_159 = V_15 -> V_152 -> V_156 ;
} else {
memcpy ( V_15 -> V_152 , & V_160 ,
sizeof( V_160 ) ) ;
V_15 -> V_152 -> V_161 . V_159 = V_15 -> V_152 -> V_156 ;
}
return 0 ;
}
static int F_61 ( struct V_18 * V_19 )
{
struct V_14 * V_15 ;
const struct V_162 * V_163 ;
int V_64 ;
V_15 = F_59 ( & V_19 -> V_2 , sizeof( * V_15 ) , V_154 ) ;
if ( ! V_15 )
return - V_155 ;
V_163 = F_62 ( V_164 , & V_19 -> V_2 ) ;
if ( ! V_163 )
return - V_75 ;
V_15 -> V_165 = ( V_166 ) V_163 -> V_167 ;
V_15 -> V_19 = V_19 ;
F_63 ( V_19 , V_15 ) ;
V_15 -> V_121 = F_48 ( V_19 -> V_2 . V_168 ) ;
if ( ! V_15 -> V_121 ) {
F_7 ( & V_19 -> V_2 , L_33 ) ;
return - V_75 ;
}
V_64 = F_50 ( V_19 , V_15 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_58 ( V_19 , V_15 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_64 ( & V_19 -> V_2 , V_15 -> V_121 -> V_12 , F_4 ,
V_169 , F_60 ( & V_19 -> V_2 ) , V_15 ) ;
if ( V_64 ) {
F_7 ( & V_19 -> V_2 , L_34 , V_64 ) ;
return V_64 ;
}
V_64 = F_65 ( & V_19 -> V_2 , & V_170 ,
V_15 -> V_152 , 1 ) ;
if ( V_64 )
return V_64 ;
V_64 = F_66 ( & V_19 -> V_2 ,
& V_171 , 0 ) ;
if ( V_64 ) {
F_7 ( & V_19 -> V_2 , L_35 ) ;
return V_64 ;
}
return 0 ;
}
