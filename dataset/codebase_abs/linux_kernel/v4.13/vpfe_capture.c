static const struct V_1 * F_1 ( T_1 V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
if ( V_2 == V_4 [ V_3 ] . V_5 . V_6 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
int F_3 ( struct V_7 * V_8 )
{
int V_9 = 0 ;
F_4 ( V_10 L_1 , V_8 -> V_11 ) ;
F_5 ( ! V_8 -> V_12 . V_13 ) ;
F_5 ( ! V_8 -> V_12 . V_14 ) ;
F_5 ( ! V_8 -> V_12 . V_15 ) ;
F_5 ( ! V_8 -> V_12 . V_16 ) ;
F_5 ( ! V_8 -> V_12 . V_17 ) ;
F_5 ( ! V_8 -> V_12 . V_18 ) ;
F_5 ( ! V_8 -> V_12 . V_19 ) ;
F_5 ( ! V_8 -> V_12 . V_20 ) ;
F_5 ( ! V_8 -> V_12 . V_21 ) ;
F_5 ( ! V_8 -> V_12 . V_22 ) ;
F_5 ( ! V_8 -> V_12 . V_23 ) ;
F_5 ( ! V_8 -> V_12 . V_24 ) ;
F_5 ( ! V_8 -> V_12 . V_25 ) ;
F_5 ( ! V_8 -> V_12 . V_26 ) ;
F_5 ( ! V_8 -> V_12 . V_27 ) ;
F_6 ( & V_28 ) ;
if ( ! V_29 ) {
F_4 ( V_30 L_2 ) ;
V_9 = - V_31 ;
goto V_32;
}
if ( strcmp ( V_8 -> V_11 , V_29 -> V_11 ) ) {
V_9 = - V_33 ;
goto V_32;
}
if ( V_34 ) {
F_4 ( V_30 L_3 ) ;
V_9 = - V_33 ;
goto V_32;
}
V_34 = V_8 ;
V_32:
F_7 ( & V_28 ) ;
return V_9 ;
}
void F_8 ( struct V_7 * V_8 )
{
if ( ! V_8 ) {
F_4 ( V_30 L_4 ) ;
return;
}
F_4 ( V_10 L_5 ,
V_8 -> V_11 ) ;
if ( strcmp ( V_8 -> V_11 , V_29 -> V_11 ) ) {
return;
}
F_6 ( & V_28 ) ;
V_34 = NULL ;
F_7 ( & V_28 ) ;
}
static int F_9 ( struct V_35 * V_36 )
{
enum V_37 V_38 = V_39 ;
int V_9 = 0 ;
if ( V_34 -> V_12 . V_23 (
V_36 -> V_40 . V_40 . V_41 . V_6 ) < 0 ) {
F_10 ( & V_36 -> V_42 ,
L_6 ) ;
return - V_33 ;
}
V_34 -> V_12 . V_24 ( & V_36 -> V_43 ) ;
switch ( V_36 -> V_40 . V_40 . V_41 . V_44 ) {
case V_45 :
V_9 = V_34 -> V_12 . V_17 (
V_46 ) ;
break;
case V_47 :
V_38 = V_48 ;
break;
case V_49 :
V_9 = V_34 -> V_12 . V_17 (
V_50 ) ;
break;
default:
return - V_33 ;
}
if ( ! V_9 )
V_9 = V_34 -> V_12 . V_20 ( V_38 ) ;
return V_9 ;
}
static int F_11 ( struct V_35 * V_36 ,
T_2 V_51 )
{
struct V_52 * V_53 = V_36 -> V_54 ;
struct V_55 V_40 = {
. V_56 = V_57 ,
} ;
struct V_58 * V_59 = & V_40 . V_60 ;
struct V_61 * V_41 = & V_36 -> V_40 . V_40 . V_41 ;
int V_3 , V_9 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_62 ) ; V_3 ++ ) {
if ( V_62 [ V_3 ] . V_51 & V_51 ) {
V_36 -> V_63 . V_64 =
V_62 [ V_3 ] . V_65 ;
V_36 -> V_63 . V_66 =
V_62 [ V_3 ] . V_67 ;
V_36 -> V_63 . V_68 =
V_62 [ V_3 ] . V_68 ;
V_36 -> V_69 = V_3 ;
break;
}
}
if ( V_3 == F_2 ( V_62 ) ) {
F_10 ( & V_36 -> V_42 , L_7 ) ;
return - V_33 ;
}
V_36 -> V_43 . V_70 = 0 ;
V_36 -> V_43 . V_71 = 0 ;
V_36 -> V_43 . V_65 = V_36 -> V_63 . V_64 ;
V_36 -> V_43 . V_67 = V_36 -> V_63 . V_66 ;
V_41 -> V_65 = V_36 -> V_43 . V_65 ;
V_41 -> V_67 = V_36 -> V_43 . V_67 ;
if ( V_36 -> V_63 . V_68 ) {
V_41 -> V_44 = V_45 ;
V_41 -> V_6 = V_72 ;
F_12 ( V_59 , V_41 ,
V_73 ) ;
} else {
V_41 -> V_44 = V_47 ;
V_41 -> V_6 = V_74 ;
F_12 ( V_59 , V_41 ,
V_75 ) ;
}
V_9 = F_13 ( & V_36 -> V_42 ,
V_53 -> V_76 , V_77 , V_78 , NULL , & V_40 ) ;
if ( V_9 && V_9 != - V_79 ) {
F_10 ( & V_36 -> V_42 ,
L_8 ) ;
return V_9 ;
}
F_14 ( V_41 , V_59 ) ;
V_41 -> V_80 = V_41 -> V_65 * 2 ;
V_41 -> V_81 = V_41 -> V_80 * V_41 -> V_67 ;
V_9 = F_9 ( V_36 ) ;
if ( V_9 )
return V_9 ;
V_41 -> V_80 = V_34 -> V_12 . V_26 () ;
V_41 -> V_81 = V_41 -> V_80 * V_41 -> V_67 ;
return 0 ;
}
static int F_15 ( struct V_35 * V_36 )
{
int V_9 ;
V_36 -> V_82 = 0 ;
V_36 -> V_69 = 0 ;
V_9 = F_11 ( V_36 ,
V_62 [ V_36 -> V_69 ] . V_51 ) ;
if ( V_9 )
return V_9 ;
F_6 ( & V_28 ) ;
if ( ! V_34 ) {
F_10 ( & V_36 -> V_42 , L_9 ) ;
V_9 = - V_83 ;
goto V_32;
}
if ( ! F_16 ( V_34 -> V_84 ) ) {
F_10 ( & V_36 -> V_42 , L_10 ) ;
V_9 = - V_83 ;
goto V_32;
}
V_9 = V_34 -> V_12 . V_13 ( V_36 -> V_85 ) ;
if ( ! V_9 )
V_36 -> V_86 = 1 ;
if ( V_36 -> V_87 -> V_88 )
V_36 -> V_87 -> V_88 ( - 1 ) ;
V_32:
F_7 ( & V_28 ) ;
return V_9 ;
}
static int F_17 ( struct V_89 * V_89 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_90 * V_91 = F_19 ( V_89 ) ;
struct V_92 * V_93 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_11 ) ;
if ( ! V_36 -> V_87 -> V_95 ) {
F_10 ( & V_36 -> V_42 , L_12 ) ;
return - V_83 ;
}
V_93 = F_21 ( sizeof( * V_93 ) , V_96 ) ;
if ( ! V_93 )
return - V_97 ;
V_89 -> V_98 = V_93 ;
V_93 -> V_36 = V_36 ;
F_22 ( & V_93 -> V_93 , V_91 ) ;
F_6 ( & V_36 -> V_99 ) ;
if ( ! V_36 -> V_86 ) {
if ( F_15 ( V_36 ) ) {
F_7 ( & V_36 -> V_99 ) ;
F_23 ( & V_93 -> V_93 ) ;
F_24 ( V_93 ) ;
return - V_83 ;
}
}
V_36 -> V_100 ++ ;
V_93 -> V_101 = 0 ;
F_25 ( & V_93 -> V_93 ) ;
F_7 ( & V_36 -> V_99 ) ;
return 0 ;
}
static void F_26 ( struct V_35 * V_36 )
{
unsigned long V_102 ;
V_36 -> V_103 = F_27 ( V_36 -> V_104 . V_105 ,
struct V_106 , V_107 ) ;
F_28 ( & V_36 -> V_103 -> V_107 ) ;
V_36 -> V_103 -> V_108 = V_109 ;
V_102 = F_29 ( V_36 -> V_103 ) ;
V_34 -> V_12 . V_110 ( V_102 ) ;
}
static void F_30 ( struct V_35 * V_36 )
{
unsigned long V_102 ;
V_102 = F_29 ( V_36 -> V_111 ) ;
V_102 += V_36 -> V_112 ;
V_34 -> V_12 . V_110 ( V_102 ) ;
}
static void F_31 ( struct V_35 * V_36 )
{
F_32 ( & V_36 -> V_111 -> V_113 ) ;
V_36 -> V_111 -> V_108 = V_114 ;
V_36 -> V_111 -> V_115 = V_36 -> V_40 . V_40 . V_41 . V_81 ;
F_33 ( & V_36 -> V_111 -> V_116 ) ;
V_36 -> V_111 = V_36 -> V_103 ;
}
static T_3 F_34 ( int V_117 , void * V_118 )
{
struct V_35 * V_36 = V_118 ;
enum V_119 V_44 ;
int V_120 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_13 ) ;
V_44 = V_36 -> V_40 . V_40 . V_41 . V_44 ;
if ( ! V_36 -> V_121 )
goto V_122;
if ( V_34 -> V_12 . V_123 )
V_34 -> V_12 . V_123 () ;
if ( V_44 == V_47 ) {
F_20 ( 1 , V_94 , & V_36 -> V_42 ,
L_14 ) ;
if ( V_36 -> V_111 != V_36 -> V_103 )
F_31 ( V_36 ) ;
goto V_122;
}
V_120 = V_34 -> V_12 . V_27 () ;
V_36 -> V_124 ^= 1 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_15 ,
V_120 , V_36 -> V_124 ) ;
if ( V_120 == V_36 -> V_124 ) {
if ( V_120 == 0 ) {
if ( V_36 -> V_111 != V_36 -> V_103 )
F_31 ( V_36 ) ;
if ( V_44 == V_49 )
F_30 ( V_36 ) ;
goto V_122;
}
F_35 ( & V_36 -> V_125 ) ;
if ( ! F_36 ( & V_36 -> V_104 ) &&
V_36 -> V_111 == V_36 -> V_103 )
F_26 ( V_36 ) ;
F_37 ( & V_36 -> V_125 ) ;
} else if ( V_120 == 0 ) {
V_36 -> V_124 = V_120 ;
}
V_122:
if ( V_36 -> V_87 -> V_88 )
V_36 -> V_87 -> V_88 ( V_117 ) ;
return V_126 ;
}
static T_3 F_38 ( int V_117 , void * V_118 )
{
struct V_35 * V_36 = V_118 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_16 ) ;
if ( ! V_36 -> V_121 ) {
if ( V_36 -> V_87 -> V_88 )
V_36 -> V_87 -> V_88 ( V_117 ) ;
return V_126 ;
}
F_35 ( & V_36 -> V_125 ) ;
if ( ( V_36 -> V_40 . V_40 . V_41 . V_44 == V_47 ) &&
! F_36 ( & V_36 -> V_104 ) &&
V_36 -> V_111 == V_36 -> V_103 )
F_26 ( V_36 ) ;
F_37 ( & V_36 -> V_125 ) ;
if ( V_36 -> V_87 -> V_88 )
V_36 -> V_87 -> V_88 ( V_117 ) ;
return V_126 ;
}
static void F_39 ( struct V_35 * V_36 )
{
enum V_37 V_68 ;
V_68 = V_34 -> V_12 . V_21 () ;
if ( V_68 == V_48 )
F_40 ( V_36 -> V_127 , V_36 ) ;
}
static int F_41 ( struct V_35 * V_36 )
{
enum V_37 V_68 ;
V_68 = V_34 -> V_12 . V_21 () ;
if ( V_68 == V_48 ) {
return F_42 ( V_36 -> V_127 , F_38 ,
0 , L_17 ,
V_36 ) ;
}
return 0 ;
}
static void F_43 ( struct V_35 * V_36 )
{
V_36 -> V_121 = 0 ;
V_34 -> V_12 . V_14 ( 0 ) ;
if ( V_34 -> V_12 . V_128 )
V_34 -> V_12 . V_128 ( 0 ) ;
}
static int F_44 ( struct V_89 * V_89 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_92 * V_93 = V_89 -> V_98 ;
struct V_52 * V_53 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_18 ) ;
F_6 ( & V_36 -> V_99 ) ;
if ( V_93 -> V_101 ) {
if ( V_36 -> V_121 ) {
V_53 = V_36 -> V_54 ;
V_9 = F_13 ( & V_36 -> V_42 ,
V_53 -> V_76 ,
V_129 , V_130 , 0 ) ;
if ( V_9 && ( V_9 != - V_79 ) )
F_10 ( & V_36 -> V_42 ,
L_19 ) ;
F_43 ( V_36 ) ;
F_39 ( V_36 ) ;
F_45 ( & V_36 -> V_131 ) ;
}
V_36 -> V_132 = 0 ;
V_36 -> V_133 = V_134 . V_133 ;
F_46 ( & V_36 -> V_131 ) ;
F_47 ( & V_36 -> V_131 ) ;
}
V_36 -> V_100 -- ;
F_48 ( & V_93 -> V_93 ) ;
F_23 ( & V_93 -> V_93 ) ;
if ( ! V_36 -> V_100 ) {
V_36 -> V_86 = 0 ;
if ( V_34 -> V_12 . V_135 )
V_34 -> V_12 . V_135 ( V_36 -> V_85 ) ;
F_49 ( V_34 -> V_84 ) ;
}
F_7 ( & V_36 -> V_99 ) ;
V_89 -> V_98 = NULL ;
F_24 ( V_93 ) ;
return 0 ;
}
static int F_50 ( struct V_89 * V_89 , struct V_136 * V_137 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_20 ) ;
return F_51 ( & V_36 -> V_131 , V_137 ) ;
}
static unsigned int F_52 ( struct V_89 * V_89 , T_4 * V_138 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_21 ) ;
if ( V_36 -> V_121 )
return F_53 ( V_89 ,
& V_36 -> V_131 , V_138 ) ;
return 0 ;
}
static const struct V_1 *
F_54 ( struct V_35 * V_36 ,
struct V_61 * V_139 )
{
T_1 V_140 = 1 , V_141 = 32 , V_142 , V_143 ;
const struct V_1 * V_144 ;
T_1 V_41 ;
int V_145 , V_146 ;
V_144 = F_1 ( V_139 -> V_6 ) ;
if ( ! V_144 ) {
V_139 -> V_6 = V_36 -> V_40 . V_40 . V_41 . V_6 ;
V_144 = F_1 ( V_139 -> V_6 ) ;
}
V_145 = 0 ;
V_146 = 0 ;
while ( V_34 -> V_12 . V_19 ( & V_41 , V_145 ) >= 0 ) {
if ( V_144 -> V_5 . V_6 == V_41 ) {
V_146 = 1 ;
break;
}
V_145 ++ ;
}
if ( ! V_146 ) {
V_139 -> V_6 = V_36 -> V_40 . V_40 . V_41 . V_6 ;
V_144 = F_1 ( V_139 -> V_6 ) ;
}
if ( V_139 -> V_44 == V_147 ) {
V_139 -> V_44 = V_36 -> V_40 . V_40 . V_41 . V_44 ;
}
if ( V_36 -> V_40 . V_40 . V_41 . V_44 != V_139 -> V_44 ) {
switch ( V_139 -> V_44 ) {
case V_45 :
case V_49 :
if ( ! V_36 -> V_63 . V_68 )
V_139 -> V_44 = V_47 ;
break;
case V_47 :
if ( V_36 -> V_63 . V_68 )
V_139 -> V_44 = V_45 ;
break;
default:
V_139 -> V_44 = V_36 -> V_40 . V_40 . V_41 . V_44 ;
break;
}
}
if ( V_139 -> V_44 == V_45 ||
V_139 -> V_44 == V_49 )
V_140 = 2 ;
V_142 = V_36 -> V_63 . V_64 ;
V_143 = V_36 -> V_63 . V_66 ;
V_141 /= V_144 -> V_148 ;
F_55 ( & V_36 -> V_42 , L_22 ,
V_139 -> V_65 , V_139 -> V_67 , V_144 -> V_148 ) ;
V_139 -> V_65 = F_56 ( ( V_139 -> V_65 ) , V_141 , V_142 ) ;
V_139 -> V_67 = F_56 ( ( V_139 -> V_67 ) , V_140 , V_143 ) ;
if ( V_139 -> V_44 == V_45 )
V_139 -> V_67 &= ( ~ 1 ) ;
V_139 -> V_80 = ( ( ( V_139 -> V_65 * V_144 -> V_148 ) + 31 )
& ~ 31 ) ;
if ( V_139 -> V_6 == V_149 )
V_139 -> V_81 =
V_139 -> V_80 * V_139 -> V_67 +
( ( V_139 -> V_80 * V_139 -> V_67 ) >> 1 ) ;
else
V_139 -> V_81 = V_139 -> V_80 * V_139 -> V_67 ;
F_55 ( & V_36 -> V_42 , L_23 ,
V_139 -> V_65 , V_139 -> V_67 , V_144 -> V_148 ,
V_139 -> V_80 , V_139 -> V_81 ) ;
return V_144 ;
}
static int F_57 ( struct V_89 * V_89 , void * V_150 ,
struct V_151 * V_152 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_24 ) ;
V_152 -> V_153 = V_154 | V_155 ;
V_152 -> V_156 = V_152 -> V_153 | V_157 ;
F_58 ( V_152 -> V_158 , V_159 , sizeof( V_152 -> V_158 ) ) ;
F_58 ( V_152 -> V_160 , L_25 , sizeof( V_152 -> V_160 ) ) ;
F_58 ( V_152 -> V_161 , V_36 -> V_87 -> V_162 , sizeof( V_152 -> V_161 ) ) ;
return 0 ;
}
static int F_59 ( struct V_89 * V_89 , void * V_150 ,
struct V_163 * V_40 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_26 ) ;
* V_40 = V_36 -> V_40 ;
return 0 ;
}
static int F_60 ( struct V_89 * V_89 , void * V_150 ,
struct V_164 * V_40 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
const struct V_1 * V_165 ;
int V_166 ;
T_1 V_41 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_27 ) ;
if ( V_34 -> V_12 . V_19 ( & V_41 , V_40 -> V_167 ) < 0 )
return - V_33 ;
V_165 = F_1 ( V_41 ) ;
if ( V_165 ) {
V_166 = V_40 -> V_167 ;
* V_40 = V_165 -> V_5 ;
V_40 -> V_167 = V_166 ;
return 0 ;
}
return - V_33 ;
}
static int F_61 ( struct V_89 * V_89 , void * V_150 ,
struct V_163 * V_40 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
const struct V_1 * V_168 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_28 ) ;
if ( V_36 -> V_121 ) {
F_10 ( & V_36 -> V_42 , L_29 ) ;
return - V_169 ;
}
V_168 = F_54 ( V_36 , & V_40 -> V_40 . V_41 ) ;
if ( ! V_168 )
return - V_33 ;
V_9 = F_62 ( & V_36 -> V_99 ) ;
if ( V_9 )
return V_9 ;
F_39 ( V_36 ) ;
V_36 -> V_40 = * V_40 ;
V_9 = F_9 ( V_36 ) ;
F_7 ( & V_36 -> V_99 ) ;
return V_9 ;
}
static int F_63 ( struct V_89 * V_89 , void * V_150 ,
struct V_163 * V_170 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
const struct V_1 * V_168 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_30 ) ;
V_168 = F_54 ( V_36 , & V_170 -> V_40 . V_41 ) ;
if ( ! V_168 )
return - V_33 ;
return 0 ;
}
static int F_64 ( struct V_35 * V_36 ,
int * V_171 ,
int * V_172 ,
int V_173 )
{
struct V_174 * V_87 = V_36 -> V_87 ;
struct V_52 * V_53 ;
int V_3 , V_175 = 0 ;
for ( V_3 = 0 ; V_3 < V_87 -> V_95 ; V_3 ++ ) {
V_53 = & V_87 -> V_176 [ V_3 ] ;
if ( V_173 < ( V_175 + V_53 -> V_177 ) ) {
* V_171 = V_3 ;
* V_172 = V_173 - V_175 ;
return 0 ;
}
V_175 += V_53 -> V_177 ;
}
return - V_33 ;
}
static int F_65 ( struct V_35 * V_36 ,
int * V_173 )
{
struct V_174 * V_87 = V_36 -> V_87 ;
struct V_52 * V_53 ;
int V_3 , V_175 = 0 ;
for ( V_3 = 0 ; V_3 < V_87 -> V_95 ; V_3 ++ ) {
V_53 = & V_87 -> V_176 [ V_3 ] ;
if ( ! strcmp ( V_53 -> V_11 , V_36 -> V_54 -> V_11 ) ) {
if ( V_36 -> V_82 >= V_53 -> V_177 )
return - 1 ;
* V_173 = V_175 + V_36 -> V_82 ;
return 0 ;
}
V_175 += V_53 -> V_177 ;
}
return - V_33 ;
}
static int F_66 ( struct V_89 * V_89 , void * V_150 ,
struct V_178 * V_179 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_52 * V_53 ;
int V_180 , V_167 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_31 ) ;
if ( F_64 ( V_36 ,
& V_180 ,
& V_167 ,
V_179 -> V_167 ) < 0 ) {
F_10 ( & V_36 -> V_42 , L_32 ) ;
return - V_33 ;
}
V_53 = & V_36 -> V_87 -> V_176 [ V_180 ] ;
* V_179 = V_53 -> V_181 [ V_167 ] ;
return 0 ;
}
static int F_67 ( struct V_89 * V_89 , void * V_150 , unsigned int * V_167 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_33 ) ;
return F_65 ( V_36 , V_167 ) ;
}
static int F_68 ( struct V_89 * V_89 , void * V_150 , unsigned int V_167 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_182 * V_183 ;
struct V_52 * V_53 ;
int V_171 , V_184 ;
struct V_185 * V_186 ;
T_1 V_187 , V_188 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_34 ) ;
V_9 = F_62 ( & V_36 -> V_99 ) ;
if ( V_9 )
return V_9 ;
if ( V_36 -> V_121 ) {
F_10 ( & V_36 -> V_42 , L_35 ) ;
V_9 = - V_169 ;
goto V_189;
}
V_9 = F_64 ( V_36 ,
& V_171 ,
& V_184 ,
V_167 ) ;
if ( V_9 < 0 ) {
F_10 ( & V_36 -> V_42 , L_36 ) ;
goto V_189;
}
V_53 = & V_36 -> V_87 -> V_176 [ V_171 ] ;
V_183 = V_36 -> V_183 [ V_171 ] ;
V_186 = & V_53 -> V_190 [ V_184 ] ;
if ( V_186 && V_53 -> V_191 ) {
V_187 = V_186 -> V_187 ;
V_188 = V_186 -> V_188 ;
} else {
V_187 = 0 ;
V_188 = 0 ;
}
if ( V_183 )
V_9 = F_69 ( V_183 , V_129 , V_192 , V_187 , V_188 , 0 ) ;
if ( V_9 ) {
F_10 ( & V_36 -> V_42 ,
L_37 ) ;
V_9 = - V_33 ;
goto V_189;
}
V_36 -> V_54 = V_53 ;
if ( V_183 )
V_36 -> V_42 . V_193 = V_183 -> V_193 ;
V_36 -> V_82 = V_167 ;
V_36 -> V_69 = 0 ;
V_9 = V_34 -> V_12 . V_15 ( & V_53 -> V_194 ) ;
if ( V_9 )
goto V_189;
V_9 = F_11 ( V_36 ,
V_62 [ V_36 -> V_69 ] . V_51 ) ;
V_189:
F_7 ( & V_36 -> V_99 ) ;
return V_9 ;
}
static int F_70 ( struct V_89 * V_89 , void * V_150 , T_2 * V_51 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_52 * V_53 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_38 ) ;
V_9 = F_62 ( & V_36 -> V_99 ) ;
V_53 = V_36 -> V_54 ;
if ( V_9 )
return V_9 ;
V_9 = F_13 ( & V_36 -> V_42 , V_53 -> V_76 ,
V_129 , V_195 , V_51 ) ;
F_7 ( & V_36 -> V_99 ) ;
return V_9 ;
}
static int F_71 ( struct V_89 * V_89 , void * V_150 , T_2 V_51 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_52 * V_53 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_39 ) ;
V_9 = F_62 ( & V_36 -> V_99 ) ;
if ( V_9 )
return V_9 ;
V_53 = V_36 -> V_54 ;
if ( V_36 -> V_121 ) {
F_10 ( & V_36 -> V_42 , L_40 ) ;
V_9 = - V_169 ;
goto V_189;
}
V_9 = F_13 ( & V_36 -> V_42 , V_53 -> V_76 ,
V_129 , V_196 , V_51 ) ;
if ( V_9 < 0 ) {
F_10 ( & V_36 -> V_42 , L_41 ) ;
goto V_189;
}
V_9 = F_11 ( V_36 , V_51 ) ;
V_189:
F_7 ( & V_36 -> V_99 ) ;
return V_9 ;
}
static int F_72 ( struct V_89 * V_89 , void * V_150 , T_2 * V_51 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_42 ) ;
* V_51 = V_62 [ V_36 -> V_69 ] . V_51 ;
return 0 ;
}
static int F_73 ( struct V_197 * V_198 ,
unsigned int * V_199 ,
unsigned int * V_115 )
{
struct V_92 * V_93 = V_198 -> V_200 ;
struct V_35 * V_36 = V_93 -> V_36 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_43 ) ;
* V_115 = V_36 -> V_40 . V_40 . V_41 . V_81 ;
if ( V_36 -> V_201 == V_202 &&
V_36 -> V_40 . V_40 . V_41 . V_81 > V_134 . V_203 )
* V_115 = V_134 . V_203 ;
if ( * V_199 < V_134 . V_204 )
* V_199 = V_134 . V_204 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 ,
L_44 , * V_199 , * V_115 ) ;
return 0 ;
}
static int F_74 ( struct V_197 * V_198 ,
struct V_106 * V_205 ,
enum V_119 V_44 )
{
struct V_92 * V_93 = V_198 -> V_200 ;
struct V_35 * V_36 = V_93 -> V_36 ;
unsigned long V_102 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_45 ) ;
if ( V_206 == V_205 -> V_108 ) {
V_205 -> V_65 = V_36 -> V_40 . V_40 . V_41 . V_65 ;
V_205 -> V_67 = V_36 -> V_40 . V_40 . V_41 . V_67 ;
V_205 -> V_115 = V_36 -> V_40 . V_40 . V_41 . V_81 ;
V_205 -> V_44 = V_44 ;
V_9 = F_75 ( V_198 , V_205 , NULL ) ;
if ( V_9 < 0 )
return V_9 ;
V_102 = F_29 ( V_205 ) ;
if ( ! F_76 ( V_102 , 32 ) )
return - V_33 ;
V_205 -> V_108 = V_207 ;
}
return 0 ;
}
static void F_77 ( struct V_197 * V_198 ,
struct V_106 * V_205 )
{
struct V_92 * V_93 = V_198 -> V_200 ;
struct V_35 * V_36 = V_93 -> V_36 ;
unsigned long V_208 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_46 ) ;
F_78 ( & V_36 -> V_125 , V_208 ) ;
F_79 ( & V_205 -> V_107 , & V_36 -> V_104 ) ;
F_80 ( & V_36 -> V_125 , V_208 ) ;
V_205 -> V_108 = V_209 ;
}
static void F_81 ( struct V_197 * V_198 ,
struct V_106 * V_205 )
{
struct V_92 * V_93 = V_198 -> V_200 ;
struct V_35 * V_36 = V_93 -> V_36 ;
unsigned long V_208 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_47 ) ;
F_78 ( & V_36 -> V_125 , V_208 ) ;
F_82 ( & V_36 -> V_104 ) ;
F_80 ( & V_36 -> V_125 , V_208 ) ;
F_83 ( V_198 , V_205 ) ;
V_205 -> V_108 = V_206 ;
}
static int F_84 ( struct V_89 * V_89 , void * V_150 ,
struct V_210 * V_211 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_92 * V_93 = V_89 -> V_98 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_48 ) ;
if ( V_212 != V_211 -> type ) {
F_10 ( & V_36 -> V_42 , L_49 ) ;
return - V_33 ;
}
V_9 = F_62 ( & V_36 -> V_99 ) ;
if ( V_9 )
return V_9 ;
if ( V_36 -> V_132 != 0 ) {
F_10 ( & V_36 -> V_42 , L_50 ) ;
V_9 = - V_169 ;
goto V_189;
}
V_36 -> V_201 = V_211 -> V_201 ;
F_85 ( & V_36 -> V_131 ,
& V_213 ,
V_36 -> V_85 ,
& V_36 -> V_214 ,
V_211 -> type ,
V_36 -> V_40 . V_40 . V_41 . V_44 ,
sizeof( struct V_106 ) ,
V_93 , NULL ) ;
V_93 -> V_101 = 1 ;
V_36 -> V_132 = 1 ;
F_82 ( & V_36 -> V_104 ) ;
V_9 = F_86 ( & V_36 -> V_131 , V_211 ) ;
V_189:
F_7 ( & V_36 -> V_99 ) ;
return V_9 ;
}
static int F_87 ( struct V_89 * V_89 , void * V_150 ,
struct V_215 * V_216 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_51 ) ;
if ( V_212 != V_216 -> type ) {
F_10 ( & V_36 -> V_42 , L_52 ) ;
return - V_33 ;
}
if ( V_36 -> V_201 != V_202 ) {
F_10 ( & V_36 -> V_42 , L_53 ) ;
return - V_33 ;
}
return F_88 ( & V_36 -> V_131 , V_216 ) ;
}
static int F_89 ( struct V_89 * V_89 , void * V_150 ,
struct V_215 * V_217 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_92 * V_93 = V_89 -> V_98 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_54 ) ;
if ( V_212 != V_217 -> type ) {
F_10 ( & V_36 -> V_42 , L_52 ) ;
return - V_33 ;
}
if ( ! V_93 -> V_101 ) {
F_10 ( & V_36 -> V_42 , L_55 ) ;
return - V_218 ;
}
return F_90 ( & V_36 -> V_131 , V_217 ) ;
}
static int F_91 ( struct V_89 * V_89 , void * V_150 ,
struct V_215 * V_216 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_56 ) ;
if ( V_212 != V_216 -> type ) {
F_10 ( & V_36 -> V_42 , L_52 ) ;
return - V_33 ;
}
return F_92 ( & V_36 -> V_131 ,
V_216 , V_89 -> V_219 & V_220 ) ;
}
static void F_93 ( struct V_35 * V_36 )
{
struct V_221 V_222 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_57 ) ;
V_34 -> V_12 . V_25 ( & V_222 ) ;
V_36 -> V_112 = V_222 . V_67 * V_222 . V_65 ;
}
static void F_94 ( struct V_35 * V_36 )
{
V_34 -> V_12 . V_14 ( 1 ) ;
if ( V_34 -> V_12 . V_128 )
V_34 -> V_12 . V_128 ( 1 ) ;
V_36 -> V_121 = 1 ;
}
static int F_95 ( struct V_89 * V_89 , void * V_150 ,
enum V_223 V_224 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_92 * V_93 = V_89 -> V_98 ;
struct V_52 * V_53 ;
unsigned long V_102 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_58 ) ;
if ( V_212 != V_224 ) {
F_10 ( & V_36 -> V_42 , L_52 ) ;
return - V_33 ;
}
if ( ! V_93 -> V_101 ) {
F_10 ( & V_36 -> V_42 , L_55 ) ;
return - V_218 ;
}
V_53 = V_36 -> V_54 ;
V_9 = F_13 ( & V_36 -> V_42 , V_53 -> V_76 ,
V_129 , V_130 , 1 ) ;
if ( V_9 && ( V_9 != - V_79 ) ) {
F_10 ( & V_36 -> V_42 , L_59 ) ;
return - V_33 ;
}
if ( F_36 ( & V_36 -> V_131 . V_225 ) ) {
F_10 ( & V_36 -> V_42 , L_60 ) ;
return - V_226 ;
}
V_9 = F_96 ( & V_36 -> V_131 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_62 ( & V_36 -> V_99 ) ;
if ( V_9 )
goto V_227;
V_36 -> V_103 = F_27 ( V_36 -> V_104 . V_105 ,
struct V_106 , V_107 ) ;
V_36 -> V_111 = V_36 -> V_103 ;
F_28 ( & V_36 -> V_111 -> V_107 ) ;
V_36 -> V_111 -> V_108 = V_109 ;
V_36 -> V_124 = 0 ;
V_102 = F_29 ( V_36 -> V_111 ) ;
F_93 ( V_36 ) ;
if ( F_41 ( V_36 ) < 0 ) {
F_10 ( & V_36 -> V_42 ,
L_61 ) ;
V_9 = - V_31 ;
goto V_189;
}
if ( V_34 -> V_12 . V_16 () < 0 ) {
F_10 ( & V_36 -> V_42 ,
L_62 ) ;
V_9 = - V_33 ;
goto V_189;
}
V_34 -> V_12 . V_110 ( ( unsigned long ) ( V_102 ) ) ;
F_94 ( V_36 ) ;
F_7 ( & V_36 -> V_99 ) ;
return V_9 ;
V_189:
F_7 ( & V_36 -> V_99 ) ;
V_227:
V_9 = F_45 ( & V_36 -> V_131 ) ;
return V_9 ;
}
static int F_97 ( struct V_89 * V_89 , void * V_150 ,
enum V_223 V_224 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_92 * V_93 = V_89 -> V_98 ;
struct V_52 * V_53 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_63 ) ;
if ( V_212 != V_224 ) {
F_10 ( & V_36 -> V_42 , L_52 ) ;
return - V_33 ;
}
if ( ! V_93 -> V_101 ) {
F_10 ( & V_36 -> V_42 , L_55 ) ;
return - V_218 ;
}
if ( ! V_36 -> V_121 ) {
F_10 ( & V_36 -> V_42 , L_64 ) ;
return - V_33 ;
}
V_9 = F_62 ( & V_36 -> V_99 ) ;
if ( V_9 )
return V_9 ;
F_43 ( V_36 ) ;
F_39 ( V_36 ) ;
V_53 = V_36 -> V_54 ;
V_9 = F_13 ( & V_36 -> V_42 , V_53 -> V_76 ,
V_129 , V_130 , 0 ) ;
if ( V_9 && ( V_9 != - V_79 ) )
F_10 ( & V_36 -> V_42 , L_19 ) ;
V_9 = F_45 ( & V_36 -> V_131 ) ;
F_7 ( & V_36 -> V_99 ) ;
return V_9 ;
}
static int F_98 ( struct V_89 * V_89 , void * V_150 ,
struct V_228 * V_43 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_65 ) ;
if ( V_43 -> type != V_212 )
return - V_33 ;
if ( V_36 -> V_69 >= F_2 ( V_62 ) )
return 0 ;
V_43 -> V_229 = V_62 [ V_36 -> V_69 ] . V_229 ;
return 0 ;
}
static int F_99 ( struct V_89 * V_89 , void * V_150 ,
struct V_230 * V_231 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_66 ) ;
if ( V_231 -> type != V_212 )
return - V_33 ;
switch ( V_231 -> V_232 ) {
case V_233 :
V_231 -> V_234 = V_36 -> V_43 ;
break;
case V_235 :
case V_236 :
V_231 -> V_234 . V_65 = V_62 [ V_36 -> V_69 ] . V_65 ;
V_231 -> V_234 . V_67 = V_62 [ V_36 -> V_69 ] . V_67 ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static int F_100 ( struct V_89 * V_89 , void * V_150 ,
struct V_230 * V_231 )
{
struct V_35 * V_36 = F_18 ( V_89 ) ;
struct V_221 V_237 = V_231 -> V_234 ;
int V_9 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 , L_67 ) ;
if ( V_231 -> type != V_212 ||
V_231 -> V_232 != V_233 )
return - V_33 ;
if ( V_36 -> V_121 ) {
F_10 ( & V_36 -> V_42 ,
L_68 ) ;
return - V_169 ;
}
V_9 = F_62 ( & V_36 -> V_99 ) ;
if ( V_9 )
return V_9 ;
if ( V_237 . V_70 < 0 || V_237 . V_71 < 0 ) {
F_10 ( & V_36 -> V_42 ,
L_69 ) ;
V_9 = - V_33 ;
goto V_189;
}
V_237 . V_65 = ( ( V_237 . V_65 + 15 ) & ~ 0xf ) ;
if ( ( V_237 . V_71 + V_237 . V_65 >
V_36 -> V_63 . V_64 ) ||
( V_237 . V_70 + V_237 . V_67 >
V_36 -> V_63 . V_66 ) ) {
F_10 ( & V_36 -> V_42 , L_70 ) ;
V_9 = - V_33 ;
goto V_189;
}
V_34 -> V_12 . V_24 ( & V_237 ) ;
V_36 -> V_40 . V_40 . V_41 . V_65 = V_237 . V_65 ;
V_36 -> V_40 . V_40 . V_41 . V_67 = V_237 . V_67 ;
V_36 -> V_40 . V_40 . V_41 . V_80 =
V_34 -> V_12 . V_26 () ;
V_36 -> V_40 . V_40 . V_41 . V_81 =
V_36 -> V_40 . V_40 . V_41 . V_80 *
V_36 -> V_40 . V_40 . V_41 . V_67 ;
V_36 -> V_43 = V_237 ;
V_231 -> V_234 = V_237 ;
V_189:
F_7 ( & V_36 -> V_99 ) ;
return V_9 ;
}
static struct V_35 * F_101 ( void )
{
struct V_35 * V_36 ;
if ( ( V_133 > 0 ) &&
( V_133 < V_134 . V_204 ) )
V_133 = V_134 . V_204 ;
if ( V_238 < V_134 . V_239 )
V_238 = V_134 . V_239 ;
V_134 . V_133 = V_133 ;
if ( V_133 )
V_134 . V_203 = V_238 ;
V_36 = F_102 ( sizeof( * V_36 ) , V_96 ) ;
return V_36 ;
}
static int F_103 ( struct V_240 * V_85 )
{
struct V_52 * V_53 ;
struct V_174 * V_241 ;
struct V_242 * V_243 ;
struct V_35 * V_36 ;
struct V_244 * V_245 ;
struct V_90 * V_246 ;
int V_9 , V_3 , V_175 ;
int V_95 = 0 ;
V_36 = F_101 () ;
if ( ! V_36 ) {
F_10 ( V_85 -> V_8 . V_158 ,
L_71 ) ;
return - V_97 ;
}
V_36 -> V_85 = & V_85 -> V_8 ;
if ( ! V_85 -> V_8 . V_247 ) {
F_10 ( V_85 -> V_8 . V_158 , L_72 ) ;
V_9 = - V_83 ;
goto V_248;
}
V_241 = V_85 -> V_8 . V_247 ;
V_36 -> V_87 = V_241 ;
if ( ! V_241 -> V_249 || ! V_241 -> V_162 || ! V_241 -> V_176 ) {
F_10 ( V_85 -> V_8 . V_158 , L_73 ) ;
V_9 = - V_250 ;
goto V_248;
}
V_29 = F_21 ( sizeof( * V_29 ) , V_96 ) ;
if ( ! V_29 ) {
V_9 = - V_97 ;
goto V_248;
}
F_6 ( & V_28 ) ;
strncpy ( V_29 -> V_11 , V_241 -> V_249 , 32 ) ;
V_243 = F_104 ( V_85 , V_251 , 0 ) ;
if ( ! V_243 ) {
F_10 ( V_85 -> V_8 . V_158 ,
L_74 ) ;
V_9 = - V_83 ;
goto V_252;
}
V_36 -> V_253 = V_243 -> V_254 ;
V_243 = F_104 ( V_85 , V_251 , 1 ) ;
if ( ! V_243 ) {
F_10 ( V_85 -> V_8 . V_158 ,
L_75 ) ;
V_9 = - V_83 ;
goto V_252;
}
V_36 -> V_127 = V_243 -> V_254 ;
V_9 = F_42 ( V_36 -> V_253 , F_34 , 0 ,
L_76 , V_36 ) ;
if ( 0 != V_9 ) {
F_10 ( V_85 -> V_8 . V_158 , L_77 ) ;
goto V_252;
}
V_246 = & V_36 -> V_255 ;
V_246 -> V_256 = V_257 ;
V_246 -> V_258 = & V_259 ;
V_246 -> V_260 = & V_261 ;
V_246 -> V_262 = 0 ;
V_246 -> V_42 = & V_36 -> V_42 ;
snprintf ( V_246 -> V_11 , sizeof( V_246 -> V_11 ) ,
L_78 ,
V_159 ,
( V_263 >> 16 ) & 0xff ,
( V_263 >> 8 ) & 0xff ,
( V_263 ) & 0xff ) ;
V_9 = F_105 ( & V_85 -> V_8 , & V_36 -> V_42 ) ;
if ( V_9 ) {
F_10 ( V_85 -> V_8 . V_158 ,
L_79 ) ;
goto V_264;
}
F_55 ( & V_36 -> V_42 , L_80 ) ;
F_106 ( & V_36 -> V_214 ) ;
F_106 ( & V_36 -> V_125 ) ;
F_107 ( & V_36 -> V_99 ) ;
V_36 -> V_133 = V_134 . V_133 ;
F_20 ( 1 , V_94 , & V_36 -> V_42 ,
L_81 ) ;
F_20 ( 1 , V_94 , & V_36 -> V_42 ,
L_82 , & V_36 -> V_255 ) ;
V_36 -> V_40 . type = V_212 ;
V_9 = F_108 ( & V_36 -> V_255 ,
V_265 , - 1 ) ;
if ( V_9 ) {
F_10 ( V_85 -> V_8 . V_158 ,
L_83 ) ;
goto V_266;
}
F_55 ( & V_36 -> V_42 , L_84 ) ;
F_109 ( V_85 , V_36 ) ;
F_110 ( & V_36 -> V_255 , V_36 ) ;
V_245 = F_111 ( V_241 -> V_267 ) ;
V_95 = V_241 -> V_95 ;
V_36 -> V_183 = F_112 ( V_95 ,
sizeof( * V_36 -> V_183 ) ,
V_96 ) ;
if ( ! V_36 -> V_183 ) {
V_9 = - V_97 ;
goto V_268;
}
for ( V_3 = 0 ; V_3 < V_95 ; V_3 ++ ) {
struct V_178 * V_269 ;
V_53 = & V_241 -> V_176 [ V_3 ] ;
V_36 -> V_183 [ V_3 ] =
F_113 ( & V_36 -> V_42 ,
V_245 ,
& V_53 -> V_270 ,
NULL ) ;
if ( V_36 -> V_183 [ V_3 ] ) {
F_55 ( & V_36 -> V_42 ,
L_85 ,
V_53 -> V_11 ) ;
V_36 -> V_183 [ V_3 ] -> V_76 = V_53 -> V_76 ;
for ( V_175 = 0 ; V_175 < V_53 -> V_177 ; V_175 ++ ) {
V_269 = & V_53 -> V_181 [ V_175 ] ;
V_246 -> V_262 |= V_269 -> V_271 ;
}
} else {
F_55 ( & V_36 -> V_42 ,
L_86 ,
V_53 -> V_11 ) ;
V_9 = - V_272 ;
goto V_273;
}
}
V_36 -> V_54 = & V_241 -> V_176 [ 0 ] ;
V_36 -> V_42 . V_193 = V_36 -> V_183 [ 0 ] -> V_193 ;
F_7 ( & V_28 ) ;
return 0 ;
V_273:
F_24 ( V_36 -> V_183 ) ;
V_268:
F_114 ( & V_36 -> V_255 ) ;
V_266:
F_115 ( & V_36 -> V_42 ) ;
V_264:
F_40 ( V_36 -> V_253 , V_36 ) ;
V_252:
F_24 ( V_29 ) ;
F_7 ( & V_28 ) ;
V_248:
F_24 ( V_36 ) ;
return V_9 ;
}
static int F_116 ( struct V_240 * V_85 )
{
struct V_35 * V_36 = F_117 ( V_85 ) ;
F_55 ( V_85 -> V_8 . V_158 , L_87 ) ;
F_40 ( V_36 -> V_253 , V_36 ) ;
F_24 ( V_36 -> V_183 ) ;
F_115 ( & V_36 -> V_42 ) ;
F_114 ( & V_36 -> V_255 ) ;
F_24 ( V_36 ) ;
F_24 ( V_29 ) ;
return 0 ;
}
static int F_118 ( struct V_274 * V_8 )
{
return 0 ;
}
static int F_119 ( struct V_274 * V_8 )
{
return 0 ;
}
