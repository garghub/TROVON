void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_3 ( & V_2 -> clock , V_3 ) ;
F_4 ( & V_2 -> V_7 ) ;
V_5 -> V_8 = F_5 ( V_6 ) ;
}
static T_1 F_6 ( const struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 , struct V_1 ,
V_11 ) ;
return F_8 ( V_2 -> V_12 ) & V_10 -> V_13 ;
}
static void F_9 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_7 ( V_15 , struct V_16 ,
V_18 ) ;
struct V_1 * V_2 = F_7 ( V_17 , struct V_1 ,
V_17 ) ;
T_2 V_19 [ F_10 ( V_20 ) ] = { 0 } ;
unsigned long V_21 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
T_1 V_25 ;
F_11 ( & V_2 -> V_7 , V_21 ) ;
V_25 = V_2 -> V_17 . V_26 [ V_22 ] ;
V_2 -> V_17 . V_26 [ V_22 ] = 0 ;
F_12 ( & V_2 -> V_7 , V_21 ) ;
if ( ! V_25 )
continue;
F_13 ( V_20 , V_19 , V_27 , V_22 ) ;
F_14 ( V_20 , V_19 , V_28 , V_25 ) ;
F_13 ( V_20 , V_19 , V_29 , V_30 ) ;
F_15 ( V_2 -> V_12 , V_19 , sizeof( V_19 ) ) ;
}
}
static void F_16 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = F_17 ( V_15 ) ;
struct V_1 * V_2 = F_7 ( V_32 , struct V_1 ,
V_33 ) ;
struct V_34 * V_35 = F_7 ( V_2 , struct V_34 , V_2 ) ;
unsigned long V_21 ;
F_11 ( & V_2 -> V_7 , V_21 ) ;
F_18 ( & V_2 -> clock ) ;
F_12 ( & V_2 -> V_7 , V_21 ) ;
F_19 ( V_35 -> V_36 , & V_2 -> V_33 ,
F_20 ( V_2 -> V_37 * 1000 ) ) ;
}
int F_21 ( struct V_34 * V_35 , struct V_38 * V_39 )
{
struct V_40 V_41 ;
int V_42 ;
if ( ! F_22 ( V_35 -> V_12 , V_43 ) )
return - V_44 ;
if ( F_23 ( & V_41 , V_39 -> V_45 , sizeof( V_41 ) ) )
return - V_46 ;
switch ( V_41 . V_47 ) {
case V_48 :
case V_49 :
break;
default:
return - V_50 ;
}
F_24 ( & V_35 -> V_51 ) ;
switch ( V_41 . V_52 ) {
case V_53 :
F_25 ( V_35 , V_35 -> V_54 . V_55 . V_56 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
F_26 ( V_35 -> V_72 , L_1 ) ;
V_42 = F_25 ( V_35 , false ) ;
if ( V_42 ) {
F_27 ( V_35 -> V_72 , L_2 , V_42 ) ;
F_28 ( & V_35 -> V_51 ) ;
return V_42 ;
}
V_41 . V_52 = V_57 ;
break;
default:
F_28 ( & V_35 -> V_51 ) ;
return - V_50 ;
}
memcpy ( & V_35 -> V_2 . V_40 , & V_41 , sizeof( V_41 ) ) ;
F_28 ( & V_35 -> V_51 ) ;
return F_29 ( V_39 -> V_45 , & V_41 ,
sizeof( V_41 ) ) ? - V_46 : 0 ;
}
int F_30 ( struct V_34 * V_35 , struct V_38 * V_39 )
{
struct V_40 * V_73 = & V_35 -> V_2 . V_40 ;
if ( ! F_22 ( V_35 -> V_12 , V_43 ) )
return - V_44 ;
return F_29 ( V_39 -> V_45 , V_73 , sizeof( * V_73 ) ) ? - V_46 : 0 ;
}
static int F_31 ( struct V_74 * V_75 ,
const struct V_76 * V_77 )
{
struct V_1 * V_2 = F_7 ( V_75 , struct V_1 ,
V_23 ) ;
T_1 V_78 = F_32 ( V_77 ) ;
unsigned long V_21 ;
F_11 ( & V_2 -> V_7 , V_21 ) ;
F_33 ( & V_2 -> clock , & V_2 -> V_11 , V_78 ) ;
F_12 ( & V_2 -> V_7 , V_21 ) ;
return 0 ;
}
static int F_34 ( struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_1 * V_2 = F_7 ( V_75 , struct V_1 ,
V_23 ) ;
T_1 V_78 ;
unsigned long V_21 ;
F_11 ( & V_2 -> V_7 , V_21 ) ;
V_78 = F_18 ( & V_2 -> clock ) ;
F_12 ( & V_2 -> V_7 , V_21 ) ;
* V_77 = F_35 ( V_78 ) ;
return 0 ;
}
static int F_36 ( struct V_74 * V_75 , T_3 V_79 )
{
struct V_1 * V_2 = F_7 ( V_75 , struct V_1 ,
V_23 ) ;
unsigned long V_21 ;
F_11 ( & V_2 -> V_7 , V_21 ) ;
F_37 ( & V_2 -> clock , V_79 ) ;
F_12 ( & V_2 -> V_7 , V_21 ) ;
return 0 ;
}
static int F_38 ( struct V_74 * V_75 , T_4 V_79 )
{
T_1 V_80 ;
T_2 V_81 ;
unsigned long V_21 ;
int V_82 = 0 ;
struct V_1 * V_2 = F_7 ( V_75 , struct V_1 ,
V_23 ) ;
if ( V_79 < 0 ) {
V_82 = 1 ;
V_79 = - V_79 ;
}
V_80 = V_2 -> V_83 ;
V_80 *= V_79 ;
V_81 = F_39 ( V_80 , 1000000000ULL ) ;
F_11 ( & V_2 -> V_7 , V_21 ) ;
F_18 ( & V_2 -> clock ) ;
V_2 -> V_11 . V_84 = V_82 ? V_2 -> V_83 - V_81 :
V_2 -> V_83 + V_81 ;
F_12 ( & V_2 -> V_7 , V_21 ) ;
return 0 ;
}
static int F_40 ( struct V_74 * V_75 ,
struct V_85 * V_86 ,
int V_87 )
{
struct V_1 * V_2 =
F_7 ( V_75 , struct V_1 , V_23 ) ;
struct V_34 * V_35 =
F_7 ( V_2 , struct V_34 , V_2 ) ;
T_2 V_19 [ F_10 ( V_20 ) ] = { 0 } ;
T_2 V_29 = 0 ;
T_5 V_88 = 0 ;
T_5 V_89 = 0 ;
int V_27 = - 1 ;
int V_42 = 0 ;
if ( ! F_41 ( V_35 -> V_12 ) )
return - V_44 ;
if ( V_86 -> V_90 . V_91 >= V_2 -> V_23 . V_24 )
return - V_92 ;
if ( V_87 ) {
V_27 = F_42 ( V_2 -> V_75 , V_93 , V_86 -> V_90 . V_91 ) ;
if ( V_27 < 0 )
return - V_94 ;
V_88 = V_95 ;
V_89 = ! ! ( V_86 -> V_90 . V_21 & V_96 ) ;
V_29 = V_97 |
V_98 |
V_99 ;
} else {
V_27 = V_86 -> V_90 . V_91 ;
V_29 = V_99 ;
}
F_13 ( V_20 , V_19 , V_27 , V_27 ) ;
F_13 ( V_20 , V_19 , V_88 , V_88 ) ;
F_13 ( V_20 , V_19 , V_89 , V_89 ) ;
F_13 ( V_20 , V_19 , V_100 , V_87 ) ;
F_13 ( V_20 , V_19 , V_29 , V_29 ) ;
V_42 = F_15 ( V_35 -> V_12 , V_19 , sizeof( V_19 ) ) ;
if ( V_42 )
return V_42 ;
return F_43 ( V_35 -> V_12 , V_27 , 0 ,
V_101 & V_87 ) ;
}
static int F_44 ( struct V_74 * V_75 ,
struct V_85 * V_86 ,
int V_87 )
{
struct V_1 * V_2 =
F_7 ( V_75 , struct V_1 , V_23 ) ;
struct V_34 * V_35 =
F_7 ( V_2 , struct V_34 , V_2 ) ;
T_2 V_19 [ F_10 ( V_20 ) ] = { 0 } ;
T_1 V_102 , V_103 , V_28 = 0 ;
T_1 V_104 , V_105 ;
struct V_76 V_77 ;
unsigned long V_21 ;
T_2 V_29 = 0 ;
T_5 V_88 = 0 ;
T_5 V_89 = 0 ;
int V_27 = - 1 ;
int V_42 = 0 ;
T_3 V_78 ;
if ( ! F_41 ( V_35 -> V_12 ) )
return - V_44 ;
if ( V_86 -> V_106 . V_91 >= V_2 -> V_23 . V_24 )
return - V_92 ;
if ( V_87 ) {
V_27 = F_42 ( V_2 -> V_75 , V_107 ,
V_86 -> V_106 . V_91 ) ;
if ( V_27 < 0 )
return - V_94 ;
V_88 = V_108 ;
V_89 = V_109 ;
V_77 . V_110 = V_86 -> V_106 . V_111 . V_112 ;
V_77 . V_113 = V_86 -> V_106 . V_111 . V_6 ;
V_78 = F_32 ( & V_77 ) ;
if ( ( V_78 >> 1 ) != 500000000LL )
return - V_92 ;
V_77 . V_110 = V_86 -> V_106 . V_26 . V_112 ;
V_77 . V_113 = V_86 -> V_106 . V_26 . V_6 ;
V_78 = F_32 ( & V_77 ) ;
V_104 = F_8 ( V_2 -> V_12 ) ;
F_11 ( & V_2 -> V_7 , V_21 ) ;
V_102 = F_3 ( & V_2 -> clock , V_104 ) ;
V_103 = V_78 - V_102 ;
V_105 = F_45 ( V_103 << V_2 -> V_11 . V_114 ,
V_2 -> V_11 . V_84 ) ;
F_12 ( & V_2 -> V_7 , V_21 ) ;
V_28 = V_104 + V_105 ;
V_29 = V_97 |
V_98 |
V_99 |
V_30 ;
} else {
V_27 = V_86 -> V_106 . V_91 ;
V_29 = V_99 ;
}
F_13 ( V_20 , V_19 , V_27 , V_27 ) ;
F_13 ( V_20 , V_19 , V_88 , V_88 ) ;
F_13 ( V_20 , V_19 , V_89 , V_89 ) ;
F_13 ( V_20 , V_19 , V_100 , V_87 ) ;
F_14 ( V_20 , V_19 , V_28 , V_28 ) ;
F_13 ( V_20 , V_19 , V_29 , V_29 ) ;
V_42 = F_15 ( V_35 -> V_12 , V_19 , sizeof( V_19 ) ) ;
if ( V_42 )
return V_42 ;
return F_43 ( V_35 -> V_12 , V_27 , 0 ,
V_101 & V_87 ) ;
}
static int F_46 ( struct V_74 * V_75 ,
struct V_85 * V_86 ,
int V_87 )
{
struct V_1 * V_2 =
F_7 ( V_75 , struct V_1 , V_23 ) ;
V_2 -> V_17 . V_115 = ! ! V_87 ;
return 0 ;
}
static int F_47 ( struct V_74 * V_75 ,
struct V_85 * V_86 ,
int V_87 )
{
switch ( V_86 -> type ) {
case V_116 :
return F_40 ( V_75 , V_86 , V_87 ) ;
case V_117 :
return F_44 ( V_75 , V_86 , V_87 ) ;
case V_118 :
return F_46 ( V_75 , V_86 , V_87 ) ;
default:
return - V_44 ;
}
return 0 ;
}
static int F_48 ( struct V_74 * V_75 , unsigned int V_27 ,
enum V_119 V_120 , unsigned int V_121 )
{
return ( V_120 == V_122 ) ? - V_44 : 0 ;
}
static void F_49 ( struct V_1 * V_2 )
{
V_2 -> V_40 . V_47 = V_48 ;
V_2 -> V_40 . V_52 = V_53 ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_22 ;
V_2 -> V_23 . V_123 =
F_51 ( sizeof( * V_2 -> V_23 . V_123 ) *
V_2 -> V_23 . V_24 , V_124 ) ;
if ( ! V_2 -> V_23 . V_123 )
return - V_125 ;
V_2 -> V_23 . V_100 = F_47 ;
V_2 -> V_23 . V_126 = F_48 ;
V_2 -> V_23 . V_127 = 1 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_23 . V_24 ; V_22 ++ ) {
snprintf ( V_2 -> V_23 . V_123 [ V_22 ] . V_128 ,
sizeof( V_2 -> V_23 . V_123 [ V_22 ] . V_128 ) ,
L_3 , V_22 ) ;
V_2 -> V_23 . V_123 [ V_22 ] . V_91 = V_22 ;
V_2 -> V_23 . V_123 [ V_22 ] . V_120 = V_129 ;
V_2 -> V_23 . V_123 [ V_22 ] . V_121 = V_22 ;
}
return 0 ;
}
static void F_52 ( struct V_34 * V_35 ,
struct V_1 * V_2 )
{
T_2 V_130 [ F_10 ( V_20 ) ] = { 0 } ;
F_53 ( V_35 -> V_12 , V_130 , sizeof( V_130 ) ) ;
V_2 -> V_23 . V_24 = F_54 ( V_20 , V_130 ,
V_131 ) ;
V_2 -> V_23 . V_132 = F_54 ( V_20 , V_130 ,
V_133 ) ;
V_2 -> V_23 . V_134 = F_54 ( V_20 , V_130 ,
V_135 ) ;
V_2 -> V_17 . V_136 [ 0 ] = F_54 ( V_20 , V_130 , V_137 ) ;
V_2 -> V_17 . V_136 [ 1 ] = F_54 ( V_20 , V_130 , V_138 ) ;
V_2 -> V_17 . V_136 [ 2 ] = F_54 ( V_20 , V_130 , V_139 ) ;
V_2 -> V_17 . V_136 [ 3 ] = F_54 ( V_20 , V_130 , V_140 ) ;
V_2 -> V_17 . V_136 [ 4 ] = F_54 ( V_20 , V_130 , V_141 ) ;
V_2 -> V_17 . V_136 [ 5 ] = F_54 ( V_20 , V_130 , V_142 ) ;
V_2 -> V_17 . V_136 [ 6 ] = F_54 ( V_20 , V_130 , V_143 ) ;
V_2 -> V_17 . V_136 [ 7 ] = F_54 ( V_20 , V_130 , V_144 ) ;
}
void F_55 ( struct V_34 * V_35 ,
struct V_145 * V_146 )
{
struct V_147 * V_72 = V_35 -> V_72 ;
struct V_1 * V_2 = & V_35 -> V_2 ;
struct V_76 V_77 ;
T_1 V_102 , V_103 ;
T_1 V_104 , V_105 ;
int V_27 = V_146 -> V_91 ;
T_3 V_78 ;
unsigned long V_21 ;
switch ( V_2 -> V_23 . V_123 [ V_27 ] . V_120 ) {
case V_93 :
if ( V_2 -> V_17 . V_115 ) {
V_146 -> type = V_148 ;
V_146 -> V_149 . V_150 = F_35 ( V_146 -> V_3 ) ;
} else {
V_146 -> type = V_151 ;
}
V_145 ( V_2 -> V_75 , V_146 ) ;
break;
case V_107 :
F_34 ( & V_2 -> V_23 , & V_77 ) ;
V_104 = F_8 ( V_2 -> V_12 ) ;
V_77 . V_110 += 1 ;
V_77 . V_113 = 0 ;
V_78 = F_32 ( & V_77 ) ;
F_11 ( & V_2 -> V_7 , V_21 ) ;
V_102 = F_3 ( & V_2 -> clock , V_104 ) ;
V_103 = V_78 - V_102 ;
V_105 = F_45 ( V_103 << V_2 -> V_11 . V_114 ,
V_2 -> V_11 . V_84 ) ;
V_2 -> V_17 . V_26 [ V_27 ] = V_104 + V_105 ;
F_56 ( V_35 -> V_36 , & V_2 -> V_17 . V_18 ) ;
F_12 ( & V_2 -> V_7 , V_21 ) ;
break;
default:
F_27 ( V_72 , L_4 , V_152 ) ;
}
}
void F_57 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = & V_35 -> V_2 ;
T_1 V_78 ;
T_1 V_153 = 0 ;
T_2 V_154 ;
F_49 ( V_2 ) ;
V_154 = F_22 ( V_35 -> V_12 , V_43 ) ;
if ( ! V_154 ) {
F_58 ( V_35 -> V_12 , L_5 ) ;
return;
}
F_59 ( & V_2 -> V_7 ) ;
V_2 -> V_11 . V_155 = F_6 ;
V_2 -> V_11 . V_114 = V_156 ;
V_2 -> V_11 . V_84 = F_60 ( V_154 ,
V_2 -> V_11 . V_114 ) ;
V_2 -> V_83 = V_2 -> V_11 . V_84 ;
V_2 -> V_11 . V_13 = F_61 ( 41 ) ;
V_2 -> V_12 = V_35 -> V_12 ;
F_33 ( & V_2 -> clock , & V_2 -> V_11 ,
F_62 ( F_63 () ) ) ;
V_78 = F_64 ( & V_2 -> V_11 , V_2 -> V_11 . V_13 ,
V_153 , & V_153 ) ;
F_65 ( V_78 , V_157 / 2 / V_158 ) ;
V_2 -> V_37 = V_78 ;
F_66 ( & V_2 -> V_17 . V_18 , F_9 ) ;
F_67 ( & V_2 -> V_33 , F_16 ) ;
if ( V_2 -> V_37 )
F_19 ( V_35 -> V_36 , & V_2 -> V_33 , 0 ) ;
else
F_58 ( V_35 -> V_12 , L_6 ) ;
V_2 -> V_23 = V_159 ;
snprintf ( V_2 -> V_23 . V_128 , 16 , L_7 ) ;
if ( F_41 ( V_35 -> V_12 ) )
F_52 ( V_35 , V_2 ) ;
if ( V_2 -> V_23 . V_24 )
F_50 ( V_2 ) ;
V_2 -> V_75 = F_68 ( & V_2 -> V_23 ,
& V_35 -> V_12 -> V_160 -> V_161 ) ;
if ( F_69 ( V_2 -> V_75 ) ) {
F_58 ( V_35 -> V_12 , L_8 ,
F_70 ( V_2 -> V_75 ) ) ;
V_2 -> V_75 = NULL ;
}
}
void F_71 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = & V_35 -> V_2 ;
if ( ! F_22 ( V_35 -> V_12 , V_43 ) )
return;
if ( V_35 -> V_2 . V_75 ) {
F_72 ( V_35 -> V_2 . V_75 ) ;
V_35 -> V_2 . V_75 = NULL ;
}
F_73 ( & V_2 -> V_17 . V_18 ) ;
F_74 ( & V_2 -> V_33 ) ;
F_75 ( V_2 -> V_23 . V_123 ) ;
}
