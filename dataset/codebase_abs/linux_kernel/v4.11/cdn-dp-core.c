static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_1 ) ;
return V_5 ;
}
V_5 = F_4 ( V_2 -> V_8 , V_3 , V_4 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_2 , V_5 ) ;
return V_5 ;
}
F_5 ( V_2 -> V_6 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_5 ;
T_1 V_9 ;
V_5 = F_2 ( V_2 -> V_10 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_7 , L_3 , V_5 ) ;
goto V_11;
}
V_5 = F_2 ( V_2 -> V_12 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_7 , L_4 , V_5 ) ;
goto V_13;
}
V_5 = F_7 ( V_2 -> V_7 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_7 , L_5 , V_5 ) ;
goto V_14;
}
F_8 ( V_2 -> V_15 ) ;
F_8 ( V_2 -> V_16 ) ;
F_8 ( V_2 -> V_17 ) ;
F_9 ( V_2 -> V_15 ) ;
F_9 ( V_2 -> V_16 ) ;
F_9 ( V_2 -> V_17 ) ;
V_9 = F_10 ( V_2 -> V_12 ) ;
if ( ! V_9 ) {
F_3 ( V_2 -> V_7 , L_6 , V_9 ) ;
goto V_18;
}
F_11 ( V_2 , V_9 ) ;
F_12 ( V_2 ) ;
return 0 ;
V_18:
F_13 ( V_2 -> V_7 ) ;
V_14:
F_5 ( V_2 -> V_12 ) ;
V_13:
F_5 ( V_2 -> V_10 ) ;
V_11:
return V_5 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_7 ) ;
F_5 ( V_2 -> V_10 ) ;
F_5 ( V_2 -> V_12 ) ;
}
static int F_16 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
union V_24 V_25 ;
int V_26 ;
T_2 V_27 ;
V_26 = F_17 ( V_22 , V_28 ) ;
if ( V_26 > 0 ) {
F_18 ( V_22 , V_28 ,
V_29 , & V_25 ) ;
if ( V_25 . V_30 )
V_27 = 2 ;
else
V_27 = 4 ;
} else {
V_27 = 0 ;
}
return V_27 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 * V_31 )
{
int V_5 ;
T_2 V_32 ;
* V_31 = 0 ;
V_5 = F_20 ( V_2 , V_33 , & V_32 , 1 ) ;
if ( V_5 )
return V_5 ;
* V_31 = F_21 ( V_32 ) ;
return 0 ;
}
static struct V_19 * F_22 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
int V_34 , V_27 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ ) {
V_20 = V_2 -> V_20 [ V_34 ] ;
V_27 = F_16 ( V_20 ) ;
if ( V_27 )
return V_20 ;
}
return NULL ;
}
static bool F_23 ( struct V_1 * V_2 )
{
unsigned long V_36 = V_37 + F_24 ( V_38 ) ;
struct V_19 * V_20 ;
T_2 V_31 = 0 ;
if ( V_2 -> V_39 < 0 || V_2 -> V_39 >= V_2 -> V_35 ) {
F_3 ( V_2 -> V_7 , L_7 ) ;
return false ;
}
V_20 = V_2 -> V_20 [ V_2 -> V_39 ] ;
while ( F_25 ( V_37 , V_36 ) ) {
if ( ! F_17 ( V_20 -> V_23 , V_28 ) )
return false ;
if ( ! F_19 ( V_2 , & V_31 ) )
return V_31 ? true : false ;
F_26 ( 5000 , 10000 ) ;
}
F_3 ( V_2 -> V_7 , L_8 ) ;
return false ;
}
static enum V_40
F_27 ( struct V_41 * V_42 , bool V_43 )
{
struct V_1 * V_2 = F_28 ( V_42 ) ;
enum V_40 V_44 = V_45 ;
F_29 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_47 )
V_44 = V_48 ;
F_30 ( & V_2 -> V_46 ) ;
return V_44 ;
}
static void F_31 ( struct V_41 * V_42 )
{
F_32 ( V_42 ) ;
F_33 ( V_42 ) ;
}
static int F_34 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_28 ( V_42 ) ;
struct V_49 * V_49 ;
int V_5 = 0 ;
F_29 ( & V_2 -> V_46 ) ;
V_49 = V_2 -> V_49 ;
if ( V_49 ) {
F_35 ( V_2 -> V_7 , L_9 ,
V_49 -> V_50 , V_49 -> V_51 ) ;
V_2 -> V_52 = F_36 ( V_49 ) ;
V_5 = F_37 ( V_42 , V_49 ) ;
if ( V_5 ) {
F_38 ( V_42 ,
V_49 ) ;
F_39 ( V_42 , V_49 ) ;
}
}
F_30 ( & V_2 -> V_46 ) ;
return V_5 ;
}
static struct V_53 *
F_40 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_28 ( V_42 ) ;
return & V_2 -> V_54 ;
}
static int F_41 ( struct V_41 * V_42 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_28 ( V_42 ) ;
struct V_57 * V_58 = & V_2 -> V_42 . V_58 ;
T_1 V_59 , V_60 , V_9 , V_61 , V_62 = 0 ;
T_2 V_27 , V_63 ;
if ( ! V_2 -> V_47 )
return V_64 ;
switch ( V_58 -> V_63 ) {
case 10 :
V_63 = 10 ;
break;
case 6 :
V_63 = 6 ;
break;
default:
V_63 = 8 ;
break;
}
V_59 = V_56 -> clock * V_63 * 3 / 1000 ;
V_62 = V_2 -> V_27 ;
V_61 = F_42 ( V_2 -> V_65 ) ;
V_27 = F_43 ( V_62 , V_61 ) ;
V_62 = F_44 ( V_66 ) ;
V_61 = F_45 ( V_2 -> V_65 ) ;
V_9 = F_43 ( V_62 , V_61 ) ;
V_60 = V_9 * V_27 / 100 ;
V_60 = V_60 * 8 / 10 ;
if ( V_59 > V_60 ) {
F_35 ( V_2 -> V_7 ,
L_10 ,
V_59 , V_60 , V_56 -> clock ) ;
return V_67 ;
}
return V_68 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_5 ;
const T_1 * V_69 , * V_70 ;
const struct V_71 * V_72 = V_2 -> V_72 ;
const struct V_73 * V_74 ;
V_74 = (struct V_73 * ) V_72 -> V_75 ;
if ( V_72 -> V_76 != F_47 ( V_74 -> V_77 ) ) {
F_3 ( V_2 -> V_7 , L_11 ) ;
return - V_78 ;
}
V_69 = ( const T_1 * ) ( V_72 -> V_75 + V_74 -> V_79 ) ;
V_70 = ( const T_1 * ) ( V_72 -> V_75 + V_74 -> V_79 + V_74 -> V_80 ) ;
V_5 = F_48 ( V_2 , V_69 , V_74 -> V_80 ,
V_70 , V_74 -> V_81 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_49 ( V_2 , true ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_12 , V_5 ) ;
return V_5 ;
}
return F_50 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
int V_5 ;
if ( ! F_23 ( V_2 ) )
return - V_82 ;
V_5 = F_20 ( V_2 , V_83 , V_2 -> V_65 ,
V_84 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_13 , V_5 ) ;
return V_5 ;
}
F_52 ( V_2 -> V_49 ) ;
V_2 -> V_49 = F_53 ( & V_2 -> V_42 ,
V_85 , V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
union V_24 V_25 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_86 ,
( V_20 -> V_87 << V_88 ) | V_89 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_20 -> V_90 ) {
V_5 = F_55 ( V_20 -> V_91 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_14 ,
V_5 ) ;
goto V_92;
}
V_20 -> V_90 = true ;
}
V_5 = F_1 ( V_2 , V_86 ,
V_93 | V_94 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_15 , V_5 ) ;
goto V_95;
}
V_5 = F_56 ( V_2 ) ;
if ( V_5 <= 0 ) {
if ( ! V_5 )
F_3 ( V_2 -> V_7 , L_16 ) ;
goto V_95;
}
V_5 = F_18 ( V_20 -> V_23 , V_28 ,
V_96 , & V_25 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_17 ) ;
goto V_95;
}
V_20 -> V_27 = F_16 ( V_20 ) ;
V_5 = F_57 ( V_2 , V_20 -> V_27 , V_25 . V_30 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_18 ,
V_5 ) ;
goto V_95;
}
V_2 -> V_39 = V_20 -> V_87 ;
return 0 ;
V_95:
if ( F_58 ( V_20 -> V_91 ) )
F_3 ( V_2 -> V_7 , L_19 , V_5 ) ;
else
V_20 -> V_90 = false ;
V_92:
F_1 ( V_2 , V_86 ,
V_93 | V_97 ) ;
return V_5 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_5 ;
if ( V_20 -> V_90 ) {
V_5 = F_58 ( V_20 -> V_91 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_19 , V_5 ) ;
return V_5 ;
}
}
V_20 -> V_90 = false ;
V_20 -> V_27 = 0 ;
V_2 -> V_39 = - 1 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_5 , V_34 ;
if ( ! V_2 -> V_98 )
return 0 ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ )
F_59 ( V_2 , V_2 -> V_20 [ V_34 ] ) ;
V_5 = F_1 ( V_2 , V_86 ,
V_93 | V_97 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_20 ,
V_5 ) ;
return V_5 ;
}
F_49 ( V_2 , false ) ;
F_14 ( V_2 ) ;
V_2 -> V_98 = false ;
V_2 -> V_99 . V_9 = 0 ;
V_2 -> V_99 . V_100 = 0 ;
if ( ! V_2 -> V_47 ) {
F_52 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_5 , V_34 , V_27 ;
struct V_19 * V_20 ;
V_20 = F_22 ( V_2 ) ;
if ( ! V_20 ) {
F_3 ( V_2 -> V_7 ,
L_21 ) ;
return - V_82 ;
}
if ( V_2 -> V_98 )
return 0 ;
V_5 = F_6 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_46 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_22 , V_5 ) ;
goto V_101;
}
for ( V_34 = V_20 -> V_87 ; V_34 < V_2 -> V_35 ; V_34 ++ ) {
V_20 = V_2 -> V_20 [ V_34 ] ;
V_27 = F_16 ( V_20 ) ;
if ( V_27 ) {
V_5 = F_54 ( V_2 , V_20 ) ;
if ( V_5 )
continue;
V_5 = F_51 ( V_2 ) ;
if ( V_5 ) {
F_59 ( V_2 , V_20 ) ;
} else {
V_2 -> V_98 = true ;
V_2 -> V_27 = V_20 -> V_27 ;
return 0 ;
}
}
}
V_101:
F_14 ( V_2 ) ;
return V_5 ;
}
static void F_62 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_55 * V_102 )
{
struct V_1 * V_2 = F_63 ( V_54 ) ;
struct V_57 * V_58 = & V_2 -> V_42 . V_58 ;
struct V_103 * V_104 = & V_2 -> V_103 ;
switch ( V_58 -> V_63 ) {
case 10 :
V_104 -> V_105 = 10 ;
break;
case 6 :
V_104 -> V_105 = 6 ;
break;
default:
V_104 -> V_105 = 8 ;
break;
}
V_104 -> V_106 = V_107 ;
V_104 -> V_108 = ! ! ( V_56 -> V_109 & V_110 ) ;
V_104 -> V_111 = ! ! ( V_56 -> V_109 & V_112 ) ;
memcpy ( & V_2 -> V_56 , V_102 , sizeof( * V_56 ) ) ;
}
static bool F_64 ( struct V_1 * V_2 )
{
T_2 V_113 [ V_114 ] ;
struct V_19 * V_20 = F_22 ( V_2 ) ;
T_2 V_115 = F_42 ( V_2 -> V_65 ) ;
if ( ! V_20 || ! V_2 -> V_99 . V_9 || ! V_2 -> V_99 . V_100 )
return false ;
if ( F_20 ( V_2 , V_116 , V_113 ,
V_114 ) ) {
F_65 ( L_23 ) ;
return false ;
}
return F_66 ( V_113 , F_43 ( V_20 -> V_27 , V_115 ) ) ;
}
static void F_67 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_63 ( V_54 ) ;
int V_5 , V_4 ;
struct V_117 * V_118 ;
V_5 = F_68 ( V_2 -> V_7 -> V_119 , V_54 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_7 , L_24 , V_5 ) ;
return;
}
F_35 ( V_2 -> V_7 , L_25 ,
( V_5 ) ? L_26 : L_27 ) ;
V_118 = F_69 ( V_54 -> V_120 -> V_118 ) ;
if ( V_5 ) {
V_4 = V_121 | ( V_121 << 16 ) ;
V_118 -> V_122 = V_123 ;
} else {
V_4 = V_121 << 16 ;
V_118 -> V_122 = V_124 ;
}
V_5 = F_1 ( V_2 , V_125 , V_4 ) ;
if ( V_5 )
return;
F_29 ( & V_2 -> V_46 ) ;
V_5 = F_61 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_28 ,
V_5 ) ;
goto V_126;
}
if ( ! F_64 ( V_2 ) ) {
V_5 = F_70 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_29 , V_5 ) ;
goto V_126;
}
}
V_5 = F_71 ( V_2 , V_127 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_30 , V_5 ) ;
goto V_126;
}
V_5 = F_72 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_31 , V_5 ) ;
goto V_126;
}
V_5 = F_71 ( V_2 , V_128 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_32 , V_5 ) ;
goto V_126;
}
V_126:
F_30 ( & V_2 -> V_46 ) ;
}
static void F_73 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_63 ( V_54 ) ;
int V_5 ;
F_29 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_98 ) {
V_5 = F_60 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_33 ,
V_5 ) ;
}
}
F_30 ( & V_2 -> V_46 ) ;
if ( ! V_2 -> V_47 && F_22 ( V_2 ) )
F_74 ( & V_2 -> V_129 ) ;
}
static int F_75 ( struct V_53 * V_54 ,
struct V_130 * V_131 ,
struct V_132 * V_133 )
{
struct V_117 * V_134 = F_69 ( V_131 ) ;
V_134 -> V_122 = V_124 ;
V_134 -> V_135 = V_136 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_137 * V_7 = V_2 -> V_7 ;
struct V_138 * V_139 = V_7 -> V_119 ;
struct V_140 * V_141 = F_77 ( V_7 ) ;
struct V_142 * V_143 ;
V_2 -> V_8 = F_78 ( V_139 , L_34 ) ;
if ( F_79 ( V_2 -> V_8 ) ) {
F_3 ( V_7 , L_35 ) ;
return F_80 ( V_2 -> V_8 ) ;
}
V_143 = F_81 ( V_141 , V_144 , 0 ) ;
V_2 -> V_145 = F_82 ( V_7 , V_143 ) ;
if ( F_79 ( V_2 -> V_145 ) ) {
F_3 ( V_7 , L_36 ) ;
return F_80 ( V_2 -> V_145 ) ;
}
V_2 -> V_12 = F_83 ( V_7 , L_37 ) ;
if ( F_79 ( V_2 -> V_12 ) ) {
F_3 ( V_7 , L_38 ) ;
return F_80 ( V_2 -> V_12 ) ;
}
V_2 -> V_10 = F_83 ( V_7 , L_39 ) ;
if ( F_79 ( V_2 -> V_10 ) ) {
F_3 ( V_7 , L_40 ) ;
return F_80 ( V_2 -> V_10 ) ;
}
V_2 -> V_146 = F_83 ( V_7 , L_41 ) ;
if ( F_79 ( V_2 -> V_146 ) ) {
F_3 ( V_7 , L_42 ) ;
return F_80 ( V_2 -> V_146 ) ;
}
V_2 -> V_6 = F_83 ( V_7 , L_43 ) ;
if ( F_79 ( V_2 -> V_6 ) ) {
F_3 ( V_7 , L_44 ) ;
return F_80 ( V_2 -> V_6 ) ;
}
V_2 -> V_147 = F_84 ( V_7 , L_41 ) ;
if ( F_79 ( V_2 -> V_147 ) ) {
F_3 ( V_7 , L_45 ) ;
return F_80 ( V_2 -> V_147 ) ;
}
V_2 -> V_16 = F_84 ( V_7 , L_46 ) ;
if ( F_79 ( V_2 -> V_16 ) ) {
F_3 ( V_7 , L_47 ) ;
return F_80 ( V_2 -> V_16 ) ;
}
V_2 -> V_15 = F_84 ( V_7 , L_48 ) ;
if ( F_79 ( V_2 -> V_15 ) ) {
F_3 ( V_7 , L_49 ) ;
return F_80 ( V_2 -> V_15 ) ;
}
V_2 -> V_17 = F_84 ( V_7 , L_50 ) ;
if ( F_79 ( V_2 -> V_17 ) ) {
F_3 ( V_7 , L_51 ) ;
return F_80 ( V_2 -> V_17 ) ;
}
return 0 ;
}
static int F_85 ( struct V_137 * V_7 , void * V_75 ,
struct V_148 * V_149 ,
struct V_150 * V_151 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
struct V_152 V_153 = {
. V_154 = V_151 -> V_154 ,
. V_155 = V_151 -> V_155 ,
. V_156 = V_151 -> V_156 ,
} ;
int V_5 ;
F_29 ( & V_2 -> V_46 ) ;
if ( ! V_2 -> V_98 ) {
V_5 = - V_82 ;
goto V_126;
}
switch ( V_149 -> V_157 ) {
case V_158 :
V_153 . V_159 = V_160 ;
break;
case V_161 :
V_153 . V_159 = V_162 ;
break;
default:
F_3 ( V_7 , L_52 , V_149 -> V_157 ) ;
V_5 = - V_78 ;
goto V_126;
}
V_5 = F_87 ( V_2 , & V_153 ) ;
if ( ! V_5 )
V_2 -> V_152 = V_153 ;
V_126:
F_30 ( & V_2 -> V_46 ) ;
return V_5 ;
}
static void F_88 ( struct V_137 * V_7 , void * V_75 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
int V_5 ;
F_29 ( & V_2 -> V_46 ) ;
if ( ! V_2 -> V_98 )
goto V_126;
V_5 = F_89 ( V_2 , & V_2 -> V_152 ) ;
if ( ! V_5 )
V_2 -> V_152 . V_159 = V_163 ;
V_126:
F_30 ( & V_2 -> V_46 ) ;
}
static int F_90 ( struct V_137 * V_7 , void * V_75 ,
bool V_164 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
int V_5 ;
F_29 ( & V_2 -> V_46 ) ;
if ( ! V_2 -> V_98 ) {
V_5 = - V_82 ;
goto V_126;
}
V_5 = F_91 ( V_2 , V_164 ) ;
V_126:
F_30 ( & V_2 -> V_46 ) ;
return V_5 ;
}
static int F_92 ( struct V_137 * V_7 , void * V_75 ,
T_2 * V_165 , T_3 V_166 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
memcpy ( V_165 , V_2 -> V_42 . V_167 , F_43 ( sizeof( V_2 -> V_42 . V_167 ) , V_166 ) ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_137 * V_7 )
{
struct V_168 V_169 = {
. V_170 = 1 ,
. V_171 = 1 ,
. V_172 = & V_173 ,
. V_174 = 8 ,
} ;
V_2 -> V_175 = F_94 (
V_7 , V_176 , V_177 ,
& V_169 , sizeof( V_169 ) ) ;
return F_95 ( V_2 -> V_175 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_36 = V_37 + F_24 ( V_178 ) ;
unsigned long V_179 = 1000 ;
F_97 ( ! F_98 ( & V_2 -> V_46 ) ) ;
if ( V_2 -> V_180 )
return 0 ;
F_30 ( & V_2 -> V_46 ) ;
while ( F_25 ( V_37 , V_36 ) ) {
V_5 = F_99 ( & V_2 -> V_72 , V_181 , V_2 -> V_7 ) ;
if ( V_5 == - V_182 ) {
F_100 ( V_179 ) ;
V_179 *= 2 ;
continue;
} else if ( V_5 ) {
F_3 ( V_2 -> V_7 ,
L_53 , V_5 ) ;
goto V_126;
}
V_2 -> V_180 = true ;
V_5 = 0 ;
goto V_126;
}
F_3 ( V_2 -> V_7 , L_54 ) ;
V_5 = - V_183 ;
V_126:
F_29 ( & V_2 -> V_46 ) ;
return V_5 ;
}
static void F_101 ( struct V_184 * V_185 )
{
struct V_1 * V_2 = F_102 ( V_185 , struct V_1 ,
V_129 ) ;
struct V_41 * V_42 = & V_2 -> V_42 ;
enum V_40 V_186 ;
int V_5 ;
F_29 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_187 )
goto V_126;
V_5 = F_96 ( V_2 ) ;
if ( V_5 )
goto V_126;
V_2 -> V_47 = true ;
if ( ! F_22 ( V_2 ) ) {
F_103 ( V_2 -> V_7 , L_55 ) ;
V_2 -> V_47 = false ;
} else if ( ! V_2 -> V_98 ) {
F_103 ( V_2 -> V_7 , L_56 ) ;
V_5 = F_61 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_57 , V_5 ) ;
V_2 -> V_47 = false ;
}
} else if ( ! F_23 ( V_2 ) ) {
F_103 ( V_2 -> V_7 , L_58 ) ;
V_2 -> V_47 = false ;
} else if ( ! F_64 ( V_2 ) ) {
unsigned int V_9 = V_2 -> V_99 . V_9 ;
unsigned int V_27 = V_2 -> V_99 . V_100 ;
struct V_55 * V_56 = & V_2 -> V_56 ;
F_103 ( V_2 -> V_7 , L_59 ) ;
V_5 = F_70 ( V_2 ) ;
if ( V_5 ) {
V_2 -> V_47 = false ;
F_3 ( V_2 -> V_7 , L_60 , V_5 ) ;
goto V_126;
}
if ( V_56 -> clock &&
( V_9 != V_2 -> V_99 . V_9 || V_27 != V_2 -> V_99 . V_100 ) ) {
V_5 = F_72 ( V_2 ) ;
if ( V_5 ) {
V_2 -> V_47 = false ;
F_3 ( V_2 -> V_7 ,
L_31 ,
V_5 ) ;
}
}
}
V_126:
F_30 ( & V_2 -> V_46 ) ;
V_186 = V_42 -> V_44 ;
V_42 -> V_44 = V_42 -> V_188 -> V_189 ( V_42 , false ) ;
if ( V_186 != V_42 -> V_44 )
F_104 ( V_2 -> V_190 ) ;
}
static int F_105 ( struct V_191 * V_192 ,
unsigned long V_193 , void * V_194 )
{
struct V_19 * V_20 = F_102 ( V_192 , struct V_19 ,
V_195 ) ;
struct V_1 * V_2 = V_20 -> V_2 ;
F_74 ( & V_2 -> V_129 ) ;
return V_196 ;
}
static int F_106 ( struct V_137 * V_7 , struct V_137 * V_197 , void * V_75 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
struct V_53 * V_54 ;
struct V_41 * V_42 ;
struct V_19 * V_20 ;
struct V_198 * V_190 = V_75 ;
int V_5 , V_34 ;
V_5 = F_76 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_190 = V_190 ;
V_2 -> V_47 = false ;
V_2 -> V_98 = false ;
V_2 -> V_39 = - 1 ;
F_107 ( & V_2 -> V_129 , F_101 ) ;
V_54 = & V_2 -> V_54 ;
V_54 -> V_199 = F_108 ( V_190 ,
V_7 -> V_119 ) ;
F_109 ( L_61 , V_54 -> V_199 ) ;
V_5 = F_110 ( V_190 , V_54 , & V_200 ,
V_201 , NULL ) ;
if ( V_5 ) {
F_65 ( L_62 ) ;
return V_5 ;
}
F_111 ( V_54 , & V_202 ) ;
V_42 = & V_2 -> V_42 ;
V_42 -> V_203 = V_204 ;
V_42 -> V_205 = V_206 ;
V_5 = F_112 ( V_190 , V_42 ,
& V_207 ,
V_136 ) ;
if ( V_5 ) {
F_65 ( L_63 ) ;
goto V_208;
}
F_113 ( V_42 , & V_209 ) ;
V_5 = F_114 ( V_42 , V_54 ) ;
if ( V_5 ) {
F_65 ( L_64 ) ;
goto V_210;
}
F_93 ( V_2 , V_7 ) ;
for ( V_34 = 0 ; V_34 < V_2 -> V_35 ; V_34 ++ ) {
V_20 = V_2 -> V_20 [ V_34 ] ;
V_20 -> V_195 . V_211 = F_105 ;
V_5 = F_115 ( V_2 -> V_7 , V_20 -> V_23 ,
V_28 ,
& V_20 -> V_195 ) ;
if ( V_5 ) {
F_3 ( V_7 ,
L_65 ) ;
goto V_210;
}
}
F_116 ( V_7 ) ;
F_74 ( & V_2 -> V_129 ) ;
return 0 ;
V_210:
F_33 ( V_42 ) ;
V_208:
F_117 ( V_54 ) ;
return V_5 ;
}
static void F_118 ( struct V_137 * V_7 , struct V_137 * V_197 , void * V_75 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
struct V_53 * V_54 = & V_2 -> V_54 ;
struct V_41 * V_42 = & V_2 -> V_42 ;
F_119 ( & V_2 -> V_129 ) ;
F_120 ( V_2 -> V_175 ) ;
F_73 ( V_54 ) ;
V_54 -> V_188 -> V_212 ( V_54 ) ;
V_42 -> V_188 -> V_212 ( V_42 ) ;
F_121 ( V_7 ) ;
F_122 ( V_2 -> V_72 ) ;
F_52 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
}
int F_123 ( struct V_137 * V_7 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
int V_5 = 0 ;
F_29 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_98 )
V_5 = F_60 ( V_2 ) ;
V_2 -> V_187 = true ;
F_30 ( & V_2 -> V_46 ) ;
return V_5 ;
}
int F_124 ( struct V_137 * V_7 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
F_29 ( & V_2 -> V_46 ) ;
V_2 -> V_187 = false ;
if ( V_2 -> V_180 )
F_74 ( & V_2 -> V_129 ) ;
F_30 ( & V_2 -> V_46 ) ;
return 0 ;
}
static int F_125 ( struct V_140 * V_141 )
{
struct V_137 * V_7 = & V_141 -> V_7 ;
const struct V_213 * V_214 ;
struct V_215 * V_216 ;
struct V_19 * V_20 ;
struct V_1 * V_2 ;
struct V_21 * V_23 ;
struct V_91 * V_91 ;
int V_34 ;
V_2 = F_126 ( V_7 , sizeof( * V_2 ) , V_217 ) ;
if ( ! V_2 )
return - V_218 ;
V_2 -> V_7 = V_7 ;
V_214 = F_127 ( V_219 , V_141 -> V_7 . V_119 ) ;
V_216 = (struct V_215 * ) V_214 -> V_75 ;
for ( V_34 = 0 ; V_34 < V_216 -> V_220 ; V_34 ++ ) {
V_23 = F_128 ( V_7 , V_34 ) ;
V_91 = F_129 ( V_7 , V_7 -> V_119 , V_34 ) ;
if ( F_80 ( V_23 ) == - V_221 ||
F_80 ( V_91 ) == - V_221 )
return - V_221 ;
if ( F_79 ( V_23 ) || F_79 ( V_91 ) )
continue;
V_20 = F_126 ( V_7 , sizeof( * V_20 ) , V_217 ) ;
if ( ! V_2 )
return - V_218 ;
V_20 -> V_23 = V_23 ;
V_20 -> V_91 = V_91 ;
V_20 -> V_2 = V_2 ;
V_20 -> V_87 = V_34 ;
V_2 -> V_20 [ V_2 -> V_35 ++ ] = V_20 ;
}
if ( ! V_2 -> V_35 ) {
F_3 ( V_7 , L_66 ) ;
return - V_78 ;
}
F_130 ( & V_2 -> V_46 ) ;
F_131 ( V_7 , V_2 ) ;
return F_132 ( V_7 , & V_222 ) ;
}
static int F_133 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_134 ( V_141 ) ;
F_123 ( V_2 -> V_7 ) ;
F_135 ( & V_141 -> V_7 , & V_222 ) ;
return 0 ;
}
static void F_136 ( struct V_140 * V_141 )
{
struct V_1 * V_2 = F_134 ( V_141 ) ;
F_123 ( V_2 -> V_7 ) ;
}
