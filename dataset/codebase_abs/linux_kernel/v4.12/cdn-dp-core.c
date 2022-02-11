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
unsigned long V_9 ;
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
F_3 ( V_2 -> V_7 , L_6 ) ;
V_5 = - V_18 ;
goto V_19;
}
F_11 ( V_2 , V_9 ) ;
F_12 ( V_2 ) ;
return 0 ;
V_19:
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
static int F_16 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_24 ;
union V_25 V_26 ;
int V_27 ;
T_1 V_28 ;
V_27 = F_17 ( V_23 , V_29 ) ;
if ( V_27 > 0 ) {
F_18 ( V_23 , V_29 ,
V_30 , & V_26 ) ;
if ( V_26 . V_31 )
V_28 = 2 ;
else
V_28 = 4 ;
} else {
V_28 = 0 ;
}
return V_28 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 * V_32 )
{
int V_5 ;
T_1 V_33 ;
* V_32 = 0 ;
V_5 = F_20 ( V_2 , V_34 , & V_33 , 1 ) ;
if ( V_5 )
return V_5 ;
* V_32 = F_21 ( V_33 ) ;
return 0 ;
}
static struct V_20 * F_22 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_35 , V_28 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_36 ; V_35 ++ ) {
V_21 = V_2 -> V_21 [ V_35 ] ;
V_28 = F_16 ( V_21 ) ;
if ( V_28 )
return V_21 ;
}
return NULL ;
}
static bool F_23 ( struct V_1 * V_2 )
{
unsigned long V_37 = V_38 + F_24 ( V_39 ) ;
struct V_20 * V_21 ;
T_1 V_32 = 0 ;
if ( V_2 -> V_40 < 0 || V_2 -> V_40 >= V_2 -> V_36 ) {
F_3 ( V_2 -> V_7 , L_7 ) ;
return false ;
}
V_21 = V_2 -> V_21 [ V_2 -> V_40 ] ;
while ( F_25 ( V_38 , V_37 ) ) {
if ( ! F_17 ( V_21 -> V_24 , V_29 ) )
return false ;
if ( ! F_19 ( V_2 , & V_32 ) )
return V_32 ? true : false ;
F_26 ( 5000 , 10000 ) ;
}
F_3 ( V_2 -> V_7 , L_8 ) ;
return false ;
}
static enum V_41
F_27 ( struct V_42 * V_43 , bool V_44 )
{
struct V_1 * V_2 = F_28 ( V_43 ) ;
enum V_41 V_45 = V_46 ;
F_29 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_48 )
V_45 = V_49 ;
F_30 ( & V_2 -> V_47 ) ;
return V_45 ;
}
static void F_31 ( struct V_42 * V_43 )
{
F_32 ( V_43 ) ;
F_33 ( V_43 ) ;
}
static int F_34 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_28 ( V_43 ) ;
struct V_50 * V_50 ;
int V_5 = 0 ;
F_29 ( & V_2 -> V_47 ) ;
V_50 = V_2 -> V_50 ;
if ( V_50 ) {
F_35 ( V_2 -> V_7 , L_9 ,
V_50 -> V_51 , V_50 -> V_52 ) ;
V_2 -> V_53 = F_36 ( V_50 ) ;
V_5 = F_37 ( V_43 , V_50 ) ;
if ( V_5 ) {
F_38 ( V_43 ,
V_50 ) ;
F_39 ( V_43 , V_50 ) ;
}
}
F_30 ( & V_2 -> V_47 ) ;
return V_5 ;
}
static struct V_54 *
F_40 ( struct V_42 * V_43 )
{
struct V_1 * V_2 = F_28 ( V_43 ) ;
return & V_2 -> V_55 ;
}
static int F_41 ( struct V_42 * V_43 ,
struct V_56 * V_57 )
{
struct V_1 * V_2 = F_28 ( V_43 ) ;
struct V_58 * V_59 = & V_2 -> V_43 . V_59 ;
T_2 V_60 , V_61 , V_9 , V_62 , V_63 = 0 ;
T_1 V_28 , V_64 ;
if ( ! V_2 -> V_48 )
return V_65 ;
switch ( V_59 -> V_64 ) {
case 10 :
V_64 = 10 ;
break;
case 6 :
V_64 = 6 ;
break;
default:
V_64 = 8 ;
break;
}
V_60 = V_57 -> clock * V_64 * 3 / 1000 ;
V_63 = V_2 -> V_28 ;
V_62 = F_42 ( V_2 -> V_66 ) ;
V_28 = F_43 ( V_63 , V_62 ) ;
V_63 = F_44 ( V_67 ) ;
V_62 = F_45 ( V_2 -> V_66 ) ;
V_9 = F_43 ( V_63 , V_62 ) ;
V_61 = V_9 * V_28 / 100 ;
V_61 = V_61 * 8 / 10 ;
if ( V_60 > V_61 ) {
F_35 ( V_2 -> V_7 ,
L_10 ,
V_60 , V_61 , V_57 -> clock ) ;
return V_68 ;
}
return V_69 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_5 ;
const T_2 * V_70 , * V_71 ;
const struct V_72 * V_73 = V_2 -> V_73 ;
const struct V_74 * V_75 ;
V_75 = (struct V_74 * ) V_73 -> V_76 ;
if ( V_73 -> V_77 != F_47 ( V_75 -> V_78 ) ) {
F_3 ( V_2 -> V_7 , L_11 ) ;
return - V_18 ;
}
V_70 = ( const T_2 * ) ( V_73 -> V_76 + V_75 -> V_79 ) ;
V_71 = ( const T_2 * ) ( V_73 -> V_76 + V_75 -> V_79 + V_75 -> V_80 ) ;
V_5 = F_48 ( V_2 , V_70 , V_75 -> V_80 ,
V_71 , V_75 -> V_81 ) ;
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
V_5 = F_20 ( V_2 , V_83 , V_2 -> V_66 ,
V_84 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_13 , V_5 ) ;
return V_5 ;
}
F_52 ( V_2 -> V_50 ) ;
V_2 -> V_50 = F_53 ( & V_2 -> V_43 ,
V_85 , V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
union V_25 V_26 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_86 ,
( V_21 -> V_87 << V_88 ) | V_89 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_21 -> V_90 ) {
V_5 = F_55 ( V_21 -> V_91 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_14 ,
V_5 ) ;
goto V_92;
}
V_21 -> V_90 = true ;
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
V_5 = F_18 ( V_21 -> V_24 , V_29 ,
V_96 , & V_26 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_17 ) ;
goto V_95;
}
V_21 -> V_28 = F_16 ( V_21 ) ;
V_5 = F_57 ( V_2 , V_21 -> V_28 , V_26 . V_31 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_18 ,
V_5 ) ;
goto V_95;
}
V_2 -> V_40 = V_21 -> V_87 ;
return 0 ;
V_95:
if ( F_58 ( V_21 -> V_91 ) )
F_3 ( V_2 -> V_7 , L_19 , V_5 ) ;
else
V_21 -> V_90 = false ;
V_92:
F_1 ( V_2 , V_86 ,
V_93 | V_97 ) ;
return V_5 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_5 ;
if ( V_21 -> V_90 ) {
V_5 = F_58 ( V_21 -> V_91 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_19 , V_5 ) ;
return V_5 ;
}
}
V_21 -> V_90 = false ;
V_21 -> V_28 = 0 ;
V_2 -> V_40 = - 1 ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
int V_5 , V_35 ;
if ( ! V_2 -> V_98 )
return 0 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_36 ; V_35 ++ )
F_59 ( V_2 , V_2 -> V_21 [ V_35 ] ) ;
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
if ( ! V_2 -> V_48 ) {
F_52 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
int V_5 , V_35 , V_28 ;
struct V_20 * V_21 ;
V_21 = F_22 ( V_2 ) ;
if ( ! V_21 ) {
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
for ( V_35 = V_21 -> V_87 ; V_35 < V_2 -> V_36 ; V_35 ++ ) {
V_21 = V_2 -> V_21 [ V_35 ] ;
V_28 = F_16 ( V_21 ) ;
if ( V_28 ) {
V_5 = F_54 ( V_2 , V_21 ) ;
if ( V_5 )
continue;
V_5 = F_51 ( V_2 ) ;
if ( V_5 ) {
F_59 ( V_2 , V_21 ) ;
} else {
V_2 -> V_98 = true ;
V_2 -> V_28 = V_21 -> V_28 ;
return 0 ;
}
}
}
V_101:
F_14 ( V_2 ) ;
return V_5 ;
}
static void F_62 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_56 * V_102 )
{
struct V_1 * V_2 = F_63 ( V_55 ) ;
struct V_58 * V_59 = & V_2 -> V_43 . V_59 ;
struct V_103 * V_104 = & V_2 -> V_103 ;
switch ( V_59 -> V_64 ) {
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
V_104 -> V_108 = ! ! ( V_57 -> V_109 & V_110 ) ;
V_104 -> V_111 = ! ! ( V_57 -> V_109 & V_112 ) ;
memcpy ( & V_2 -> V_57 , V_102 , sizeof( * V_57 ) ) ;
}
static bool F_64 ( struct V_1 * V_2 )
{
T_1 V_113 [ V_114 ] ;
struct V_20 * V_21 = F_22 ( V_2 ) ;
T_1 V_115 = F_42 ( V_2 -> V_66 ) ;
if ( ! V_21 || ! V_2 -> V_99 . V_9 || ! V_2 -> V_99 . V_100 )
return false ;
if ( F_20 ( V_2 , V_116 , V_113 ,
V_114 ) ) {
F_65 ( L_23 ) ;
return false ;
}
return F_66 ( V_113 , F_43 ( V_21 -> V_28 , V_115 ) ) ;
}
static void F_67 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_63 ( V_55 ) ;
int V_5 , V_4 ;
V_5 = F_68 ( V_2 -> V_7 -> V_117 , V_55 ) ;
if ( V_5 < 0 ) {
F_3 ( V_2 -> V_7 , L_24 , V_5 ) ;
return;
}
F_35 ( V_2 -> V_7 , L_25 ,
( V_5 ) ? L_26 : L_27 ) ;
if ( V_5 )
V_4 = V_118 | ( V_118 << 16 ) ;
else
V_4 = V_118 << 16 ;
V_5 = F_1 ( V_2 , V_119 , V_4 ) ;
if ( V_5 )
return;
F_29 ( & V_2 -> V_47 ) ;
V_5 = F_61 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_28 ,
V_5 ) ;
goto V_120;
}
if ( ! F_64 ( V_2 ) ) {
V_5 = F_69 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_29 , V_5 ) ;
goto V_120;
}
}
V_5 = F_70 ( V_2 , V_121 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_30 , V_5 ) ;
goto V_120;
}
V_5 = F_71 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_31 , V_5 ) ;
goto V_120;
}
V_5 = F_70 ( V_2 , V_122 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_32 , V_5 ) ;
goto V_120;
}
V_120:
F_30 ( & V_2 -> V_47 ) ;
}
static void F_72 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_63 ( V_55 ) ;
int V_5 ;
F_29 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_98 ) {
V_5 = F_60 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_33 ,
V_5 ) ;
}
}
F_30 ( & V_2 -> V_47 ) ;
if ( ! V_2 -> V_48 && F_22 ( V_2 ) )
F_73 ( & V_2 -> V_123 ) ;
}
static int F_74 ( struct V_54 * V_55 ,
struct V_124 * V_125 ,
struct V_126 * V_127 )
{
struct V_128 * V_129 = F_75 ( V_125 ) ;
V_129 -> V_130 = V_131 ;
V_129 -> V_132 = V_133 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_134 * V_7 = V_2 -> V_7 ;
struct V_135 * V_136 = V_7 -> V_117 ;
struct V_137 * V_138 = F_77 ( V_7 ) ;
struct V_139 * V_140 ;
V_2 -> V_8 = F_78 ( V_136 , L_34 ) ;
if ( F_79 ( V_2 -> V_8 ) ) {
F_3 ( V_7 , L_35 ) ;
return F_80 ( V_2 -> V_8 ) ;
}
V_140 = F_81 ( V_138 , V_141 , 0 ) ;
V_2 -> V_142 = F_82 ( V_7 , V_140 ) ;
if ( F_79 ( V_2 -> V_142 ) ) {
F_3 ( V_7 , L_36 ) ;
return F_80 ( V_2 -> V_142 ) ;
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
V_2 -> V_143 = F_83 ( V_7 , L_41 ) ;
if ( F_79 ( V_2 -> V_143 ) ) {
F_3 ( V_7 , L_42 ) ;
return F_80 ( V_2 -> V_143 ) ;
}
V_2 -> V_6 = F_83 ( V_7 , L_43 ) ;
if ( F_79 ( V_2 -> V_6 ) ) {
F_3 ( V_7 , L_44 ) ;
return F_80 ( V_2 -> V_6 ) ;
}
V_2 -> V_144 = F_84 ( V_7 , L_41 ) ;
if ( F_79 ( V_2 -> V_144 ) ) {
F_3 ( V_7 , L_45 ) ;
return F_80 ( V_2 -> V_144 ) ;
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
static int F_85 ( struct V_134 * V_7 , void * V_76 ,
struct V_145 * V_146 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
struct V_149 V_150 = {
. V_151 = V_148 -> V_151 ,
. V_152 = V_148 -> V_152 ,
. V_153 = V_148 -> V_153 ,
} ;
int V_5 ;
F_29 ( & V_2 -> V_47 ) ;
if ( ! V_2 -> V_98 ) {
V_5 = - V_82 ;
goto V_120;
}
switch ( V_146 -> V_154 ) {
case V_155 :
V_150 . V_156 = V_157 ;
break;
case V_158 :
V_150 . V_156 = V_159 ;
break;
default:
F_3 ( V_7 , L_52 , V_146 -> V_154 ) ;
V_5 = - V_18 ;
goto V_120;
}
V_5 = F_87 ( V_2 , & V_150 ) ;
if ( ! V_5 )
V_2 -> V_149 = V_150 ;
V_120:
F_30 ( & V_2 -> V_47 ) ;
return V_5 ;
}
static void F_88 ( struct V_134 * V_7 , void * V_76 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
int V_5 ;
F_29 ( & V_2 -> V_47 ) ;
if ( ! V_2 -> V_98 )
goto V_120;
V_5 = F_89 ( V_2 , & V_2 -> V_149 ) ;
if ( ! V_5 )
V_2 -> V_149 . V_156 = V_160 ;
V_120:
F_30 ( & V_2 -> V_47 ) ;
}
static int F_90 ( struct V_134 * V_7 , void * V_76 ,
bool V_161 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
int V_5 ;
F_29 ( & V_2 -> V_47 ) ;
if ( ! V_2 -> V_98 ) {
V_5 = - V_82 ;
goto V_120;
}
V_5 = F_91 ( V_2 , V_161 ) ;
V_120:
F_30 ( & V_2 -> V_47 ) ;
return V_5 ;
}
static int F_92 ( struct V_134 * V_7 , void * V_76 ,
T_1 * V_162 , T_3 V_163 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
memcpy ( V_162 , V_2 -> V_43 . V_164 , F_43 ( sizeof( V_2 -> V_43 . V_164 ) , V_163 ) ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_134 * V_7 )
{
struct V_165 V_166 = {
. V_167 = 1 ,
. V_168 = 1 ,
. V_169 = & V_170 ,
. V_171 = 8 ,
} ;
V_2 -> V_172 = F_94 (
V_7 , V_173 , V_174 ,
& V_166 , sizeof( V_166 ) ) ;
return F_95 ( V_2 -> V_172 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_5 ;
unsigned long V_37 = V_38 + F_24 ( V_175 ) ;
unsigned long V_176 = 1000 ;
F_97 ( ! F_98 ( & V_2 -> V_47 ) ) ;
if ( V_2 -> V_177 )
return 0 ;
F_30 ( & V_2 -> V_47 ) ;
while ( F_25 ( V_38 , V_37 ) ) {
V_5 = F_99 ( & V_2 -> V_73 , V_178 , V_2 -> V_7 ) ;
if ( V_5 == - V_179 ) {
F_100 ( V_176 ) ;
V_176 *= 2 ;
continue;
} else if ( V_5 ) {
F_3 ( V_2 -> V_7 ,
L_53 , V_5 ) ;
goto V_120;
}
V_2 -> V_177 = true ;
V_5 = 0 ;
goto V_120;
}
F_3 ( V_2 -> V_7 , L_54 ) ;
V_5 = - V_180 ;
V_120:
F_29 ( & V_2 -> V_47 ) ;
return V_5 ;
}
static void F_101 ( struct V_181 * V_182 )
{
struct V_1 * V_2 = F_102 ( V_182 , struct V_1 ,
V_123 ) ;
struct V_42 * V_43 = & V_2 -> V_43 ;
enum V_41 V_183 ;
int V_5 ;
F_29 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_184 )
goto V_120;
V_5 = F_96 ( V_2 ) ;
if ( V_5 )
goto V_120;
V_2 -> V_48 = true ;
if ( ! F_22 ( V_2 ) ) {
F_103 ( V_2 -> V_7 , L_55 ) ;
V_2 -> V_48 = false ;
} else if ( ! V_2 -> V_98 ) {
F_103 ( V_2 -> V_7 , L_56 ) ;
V_5 = F_61 ( V_2 ) ;
if ( V_5 ) {
F_3 ( V_2 -> V_7 , L_57 , V_5 ) ;
V_2 -> V_48 = false ;
}
} else if ( ! F_23 ( V_2 ) ) {
F_103 ( V_2 -> V_7 , L_58 ) ;
V_2 -> V_48 = false ;
} else if ( ! F_64 ( V_2 ) ) {
unsigned int V_9 = V_2 -> V_99 . V_9 ;
unsigned int V_28 = V_2 -> V_99 . V_100 ;
struct V_56 * V_57 = & V_2 -> V_57 ;
F_103 ( V_2 -> V_7 , L_59 ) ;
V_5 = F_69 ( V_2 ) ;
if ( V_5 ) {
V_2 -> V_48 = false ;
F_3 ( V_2 -> V_7 , L_60 , V_5 ) ;
goto V_120;
}
if ( V_57 -> clock &&
( V_9 != V_2 -> V_99 . V_9 || V_28 != V_2 -> V_99 . V_100 ) ) {
V_5 = F_71 ( V_2 ) ;
if ( V_5 ) {
V_2 -> V_48 = false ;
F_3 ( V_2 -> V_7 ,
L_31 ,
V_5 ) ;
}
}
}
V_120:
F_30 ( & V_2 -> V_47 ) ;
V_183 = V_43 -> V_45 ;
V_43 -> V_45 = V_43 -> V_185 -> V_186 ( V_43 , false ) ;
if ( V_183 != V_43 -> V_45 )
F_104 ( V_2 -> V_187 ) ;
}
static int F_105 ( struct V_188 * V_189 ,
unsigned long V_190 , void * V_191 )
{
struct V_20 * V_21 = F_102 ( V_189 , struct V_20 ,
V_192 ) ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_73 ( & V_2 -> V_123 ) ;
return V_193 ;
}
static int F_106 ( struct V_134 * V_7 , struct V_134 * V_194 , void * V_76 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
struct V_54 * V_55 ;
struct V_42 * V_43 ;
struct V_20 * V_21 ;
struct V_195 * V_187 = V_76 ;
int V_5 , V_35 ;
V_5 = F_76 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_187 = V_187 ;
V_2 -> V_48 = false ;
V_2 -> V_98 = false ;
V_2 -> V_40 = - 1 ;
V_2 -> V_177 = false ;
F_107 ( & V_2 -> V_123 , F_101 ) ;
V_55 = & V_2 -> V_55 ;
V_55 -> V_196 = F_108 ( V_187 ,
V_7 -> V_117 ) ;
F_109 ( L_61 , V_55 -> V_196 ) ;
V_5 = F_110 ( V_187 , V_55 , & V_197 ,
V_198 , NULL ) ;
if ( V_5 ) {
F_65 ( L_62 ) ;
return V_5 ;
}
F_111 ( V_55 , & V_199 ) ;
V_43 = & V_2 -> V_43 ;
V_43 -> V_200 = V_201 ;
V_43 -> V_202 = V_203 ;
V_5 = F_112 ( V_187 , V_43 ,
& V_204 ,
V_133 ) ;
if ( V_5 ) {
F_65 ( L_63 ) ;
goto V_205;
}
F_113 ( V_43 , & V_206 ) ;
V_5 = F_114 ( V_43 , V_55 ) ;
if ( V_5 ) {
F_65 ( L_64 ) ;
goto V_207;
}
for ( V_35 = 0 ; V_35 < V_2 -> V_36 ; V_35 ++ ) {
V_21 = V_2 -> V_21 [ V_35 ] ;
V_21 -> V_192 . V_208 = F_105 ;
V_5 = F_115 ( V_2 -> V_7 , V_21 -> V_24 ,
V_29 ,
& V_21 -> V_192 ) ;
if ( V_5 ) {
F_3 ( V_7 ,
L_65 ) ;
goto V_207;
}
}
F_116 ( V_7 ) ;
F_73 ( & V_2 -> V_123 ) ;
return 0 ;
V_207:
F_33 ( V_43 ) ;
V_205:
F_117 ( V_55 ) ;
return V_5 ;
}
static void F_118 ( struct V_134 * V_7 , struct V_134 * V_194 , void * V_76 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
struct V_54 * V_55 = & V_2 -> V_55 ;
struct V_42 * V_43 = & V_2 -> V_43 ;
F_119 ( & V_2 -> V_123 ) ;
F_72 ( V_55 ) ;
V_55 -> V_185 -> V_209 ( V_55 ) ;
V_43 -> V_185 -> V_209 ( V_43 ) ;
F_120 ( V_7 ) ;
if ( V_2 -> V_177 )
F_121 ( V_2 -> V_73 ) ;
F_52 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
}
int F_122 ( struct V_134 * V_7 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
int V_5 = 0 ;
F_29 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_98 )
V_5 = F_60 ( V_2 ) ;
V_2 -> V_184 = true ;
F_30 ( & V_2 -> V_47 ) ;
return V_5 ;
}
int F_123 ( struct V_134 * V_7 )
{
struct V_1 * V_2 = F_86 ( V_7 ) ;
F_29 ( & V_2 -> V_47 ) ;
V_2 -> V_184 = false ;
if ( V_2 -> V_177 )
F_73 ( & V_2 -> V_123 ) ;
F_30 ( & V_2 -> V_47 ) ;
return 0 ;
}
static int F_124 ( struct V_137 * V_138 )
{
struct V_134 * V_7 = & V_138 -> V_7 ;
const struct V_210 * V_211 ;
struct V_212 * V_213 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_22 * V_24 ;
struct V_91 * V_91 ;
int V_35 ;
V_2 = F_125 ( V_7 , sizeof( * V_2 ) , V_214 ) ;
if ( ! V_2 )
return - V_215 ;
V_2 -> V_7 = V_7 ;
V_211 = F_126 ( V_216 , V_138 -> V_7 . V_117 ) ;
V_213 = (struct V_212 * ) V_211 -> V_76 ;
for ( V_35 = 0 ; V_35 < V_213 -> V_217 ; V_35 ++ ) {
V_24 = F_127 ( V_7 , V_35 ) ;
V_91 = F_128 ( V_7 , V_7 -> V_117 , V_35 ) ;
if ( F_80 ( V_24 ) == - V_218 ||
F_80 ( V_91 ) == - V_218 )
return - V_218 ;
if ( F_79 ( V_24 ) || F_79 ( V_91 ) )
continue;
V_21 = F_125 ( V_7 , sizeof( * V_21 ) , V_214 ) ;
if ( ! V_2 )
return - V_215 ;
V_21 -> V_24 = V_24 ;
V_21 -> V_91 = V_91 ;
V_21 -> V_2 = V_2 ;
V_21 -> V_87 = V_35 ;
V_2 -> V_21 [ V_2 -> V_36 ++ ] = V_21 ;
}
if ( ! V_2 -> V_36 ) {
F_3 ( V_7 , L_66 ) ;
return - V_18 ;
}
F_129 ( & V_2 -> V_47 ) ;
F_130 ( V_7 , V_2 ) ;
F_93 ( V_2 , V_7 ) ;
return F_131 ( V_7 , & V_219 ) ;
}
static int F_132 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_133 ( V_138 ) ;
F_134 ( V_2 -> V_172 ) ;
F_122 ( V_2 -> V_7 ) ;
F_135 ( & V_138 -> V_7 , & V_219 ) ;
return 0 ;
}
static void F_136 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_133 ( V_138 ) ;
F_122 ( V_2 -> V_7 ) ;
}
