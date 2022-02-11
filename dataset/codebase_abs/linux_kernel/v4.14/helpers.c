bool F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_6 ;
T_1 V_7 ;
switch ( V_3 ) {
case V_8 :
V_7 = V_9 ;
break;
case V_10 :
V_7 = V_11 ;
break;
case V_12 :
V_7 = V_13 ;
break;
case V_14 :
V_7 = V_15 ;
break;
case V_16 :
V_7 = V_17 ;
break;
case V_18 :
case V_19 :
V_7 = V_20 ;
break;
case V_21 :
V_7 = V_22 ;
break;
case V_23 :
V_7 = V_24 ;
break;
case V_25 :
V_7 = V_26 ;
break;
default:
return false ;
}
if ( V_6 == V_27 && V_5 -> V_28 & V_7 )
return true ;
if ( V_6 == V_29 && V_5 -> V_30 & V_7 )
return true ;
return false ;
}
static int F_2 ( struct V_1 * V_2 , T_1 type )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_31 * V_32 = V_5 -> V_32 ;
struct V_33 V_34 ;
struct V_35 V_36 ;
struct V_37 * V_38 ;
unsigned int V_39 ;
int V_40 ;
V_40 = F_3 ( V_2 , type , & V_34 ) ;
if ( V_40 )
return 0 ;
if ( ! V_34 . V_41 )
return 0 ;
for ( V_39 = 0 ; V_39 < V_34 . V_42 ; V_39 ++ ) {
V_38 = F_4 ( sizeof( * V_38 ) , V_43 ) ;
if ( ! V_38 ) {
V_40 = - V_44 ;
goto V_45;
}
V_38 -> type = V_34 . type ;
V_38 -> V_41 = V_34 . V_41 ;
V_38 -> V_46 = V_47 |
V_48 ;
V_38 -> V_49 = F_5 ( V_32 , V_38 -> V_41 , & V_38 -> V_50 , V_43 ,
V_38 -> V_46 ) ;
if ( ! V_38 -> V_49 ) {
V_40 = - V_44 ;
goto V_45;
}
memset ( & V_36 , 0 , sizeof( V_36 ) ) ;
V_36 . V_51 = V_38 -> V_41 ;
V_36 . V_52 = V_38 -> type ;
V_36 . V_53 = 1 ;
V_36 . V_54 = V_38 -> V_50 ;
V_40 = F_6 ( V_2 , & V_36 ) ;
if ( V_40 ) {
F_7 ( V_32 , L_1 ) ;
goto V_55;
}
F_8 ( & V_38 -> V_56 , & V_2 -> V_57 ) ;
}
return 0 ;
V_55:
F_9 ( V_32 , V_38 -> V_41 , V_38 -> V_49 , V_38 -> V_50 , V_38 -> V_46 ) ;
V_45:
F_10 ( V_38 ) ;
return V_40 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_35 V_36 = { 0 } ;
struct V_37 * V_38 , * V_58 ;
int V_40 = 0 ;
F_12 (buf, n, &inst->internalbufs, list) {
V_36 . V_51 = V_38 -> V_41 ;
V_36 . V_52 = V_38 -> type ;
V_36 . V_53 = 1 ;
V_36 . V_54 = V_38 -> V_50 ;
V_36 . V_59 = true ;
V_40 = F_13 ( V_2 , & V_36 ) ;
F_14 ( & V_38 -> V_56 ) ;
F_9 ( V_2 -> V_5 -> V_32 , V_38 -> V_41 , V_38 -> V_49 , V_38 -> V_50 ,
V_38 -> V_46 ) ;
F_10 ( V_38 ) ;
}
return V_40 ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned int V_39 ;
int V_40 ;
for ( V_39 = 0 ; V_39 < F_16 ( V_60 ) ; V_39 ++ ) {
V_40 = F_2 ( V_2 , V_60 [ V_39 ] ) ;
if ( V_40 )
goto error;
}
return 0 ;
error:
F_11 ( V_2 ) ;
return V_40 ;
}
static int F_17 ( struct V_1 * V_2 )
{
return F_11 ( V_2 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
T_1 V_61 ;
if ( ! V_2 || ! ( V_2 -> V_62 >= V_63 && V_2 -> V_62 < V_64 ) )
return 0 ;
V_61 = ( F_19 ( V_2 -> V_65 , 16 ) / 16 ) * ( F_19 ( V_2 -> V_66 , 16 ) / 16 ) ;
return V_61 * V_2 -> V_67 ;
}
static T_1 F_20 ( struct V_4 * V_5 , T_1 V_6 )
{
struct V_1 * V_2 = NULL ;
T_1 V_68 = 0 ;
F_21 ( & V_5 -> V_69 ) ;
F_22 (inst, &core->instances, list) {
if ( V_2 -> V_6 != V_6 )
continue;
V_68 += F_18 ( V_2 ) ;
}
F_23 ( & V_5 -> V_69 ) ;
return V_68 ;
}
static int F_24 ( struct V_4 * V_5 )
{
const struct V_70 * V_71 = V_5 -> V_72 -> V_70 ;
unsigned int V_73 = V_5 -> V_72 -> V_74 ;
unsigned long V_75 = V_71 [ 0 ] . V_75 ;
struct V_76 * V_76 = V_5 -> V_77 [ 0 ] ;
struct V_31 * V_32 = V_5 -> V_32 ;
T_1 V_68 ;
unsigned int V_39 ;
int V_40 ;
V_68 = F_20 ( V_5 , V_27 ) +
F_20 ( V_5 , V_29 ) ;
if ( V_68 > V_5 -> V_72 -> V_78 )
F_25 ( V_32 , L_2 ,
V_68 , V_5 -> V_72 -> V_78 ) ;
if ( ! V_68 && V_73 > 1 ) {
V_75 = V_71 [ V_73 - 1 ] . V_75 ;
goto V_79;
}
for ( V_39 = 0 ; V_39 < V_73 ; V_39 ++ ) {
if ( V_68 > V_71 [ V_39 ] . V_80 )
break;
V_75 = V_71 [ V_39 ] . V_75 ;
}
V_79:
if ( V_5 -> V_72 -> V_81 == V_82 ) {
V_40 = F_26 ( V_76 , V_75 ) ;
V_40 |= F_26 ( V_5 -> V_83 , V_75 ) ;
V_40 |= F_26 ( V_5 -> V_84 , V_75 ) ;
} else {
V_40 = F_26 ( V_76 , V_75 ) ;
}
if ( V_40 ) {
F_7 ( V_32 , L_3 , V_75 , V_40 ) ;
return V_40 ;
}
return 0 ;
}
static void F_27 ( const struct V_85 * V_38 ,
struct V_35 * V_36 , bool V_86 )
{
memset ( V_36 , 0 , sizeof( * V_36 ) ) ;
V_36 -> V_52 = V_87 ;
V_36 -> V_51 = V_38 -> V_41 ;
V_36 -> V_53 = 1 ;
V_36 -> V_54 = V_38 -> V_88 ;
V_36 -> V_59 = V_86 ;
}
static void F_28 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_91 * V_92 = V_2 -> V_92 ;
if ( V_90 -> V_93 . type == V_94 )
F_29 ( V_92 , V_90 ) ;
else
F_30 ( V_92 , V_90 ) ;
F_31 ( V_90 , V_95 ) ;
}
static int
F_32 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
struct V_85 * V_38 = F_33 ( V_90 ) ;
struct V_96 * V_97 = & V_90 -> V_93 ;
unsigned int type = V_97 -> type ;
struct V_98 V_99 ;
int V_40 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_100 = V_38 -> V_41 ;
V_99 . V_54 = V_38 -> V_88 ;
V_99 . V_101 = V_97 -> V_101 ;
F_34 ( V_99 . V_101 , V_102 ) ;
V_99 . V_103 = 0 ;
V_99 . V_104 = V_90 -> V_93 . V_105 ;
if ( ! V_99 . V_101 )
V_99 . V_103 |= V_106 ;
if ( type == V_94 ) {
V_99 . V_52 = V_107 ;
V_99 . V_108 = F_35 ( V_97 , 0 ) ;
V_99 . V_109 = V_97 -> V_110 [ 0 ] . V_111 ;
if ( V_90 -> V_103 & V_112 || ! V_99 . V_108 )
V_99 . V_103 |= V_113 ;
} else if ( type == V_114 ) {
V_99 . V_52 = V_87 ;
V_99 . V_108 = 0 ;
V_99 . V_109 = 0 ;
}
V_40 = F_36 ( V_2 , & V_99 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
static inline int F_37 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 == V_29 &&
V_2 -> V_5 -> V_72 -> V_81 == V_82 )
return 0 ;
if ( V_2 -> V_6 == V_29 &&
V_2 -> V_115 &&
V_2 -> V_5 -> V_72 -> V_81 == V_116 )
return 0 ;
return 1 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_85 * V_38 , * V_58 ;
struct V_35 V_36 ;
int V_40 = 0 ;
if ( ! F_37 ( V_2 ) )
return 0 ;
F_12 (buf, n, &inst->registeredbufs, reg_list) {
F_27 ( V_38 , & V_36 , true ) ;
V_40 = F_13 ( V_2 , & V_36 ) ;
F_14 ( & V_38 -> V_117 ) ;
}
return V_40 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_31 * V_32 = V_5 -> V_32 ;
struct V_35 V_36 ;
struct V_85 * V_38 ;
int V_40 = 0 ;
if ( ! F_37 ( V_2 ) )
return 0 ;
F_22 (buf, &inst->registeredbufs, reg_list) {
F_27 ( V_38 , & V_36 , false ) ;
V_40 = F_6 ( V_2 , & V_36 ) ;
if ( V_40 ) {
F_7 ( V_32 , L_4 , V_118 ) ;
break;
}
}
return V_40 ;
}
int F_3 ( struct V_1 * V_2 , T_1 type ,
struct V_33 * V_119 )
{
T_1 V_120 = V_121 ;
union V_122 V_123 ;
unsigned int V_39 ;
int V_40 ;
if ( V_119 )
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
V_40 = F_40 ( V_2 , V_120 , & V_123 ) ;
if ( V_40 )
return V_40 ;
V_40 = - V_124 ;
for ( V_39 = 0 ; V_39 < V_125 ; V_39 ++ ) {
if ( V_123 . V_34 [ V_39 ] . type != type )
continue;
if ( V_119 )
memcpy ( V_119 , & V_123 . V_34 [ V_39 ] , sizeof( * V_119 ) ) ;
V_40 = 0 ;
break;
}
return V_40 ;
}
int F_41 ( struct V_1 * V_2 ,
unsigned int V_65 , unsigned int V_66 )
{
T_1 V_120 = V_126 ;
struct V_127 V_128 ;
V_128 . V_52 = V_107 ;
V_128 . V_65 = V_65 ;
V_128 . V_66 = V_66 ;
return F_42 ( V_2 , V_120 , & V_128 ) ;
}
int F_43 ( struct V_1 * V_2 ,
unsigned int V_65 , unsigned int V_66 )
{
T_1 V_120 = V_126 ;
struct V_127 V_128 ;
V_128 . V_52 = V_87 ;
V_128 . V_65 = V_65 ;
V_128 . V_66 = V_66 ;
return F_42 ( V_2 , V_120 , & V_128 ) ;
}
int F_44 ( struct V_1 * V_2 , unsigned int V_129 ,
unsigned int V_130 )
{
T_1 V_120 = V_131 ;
struct V_132 V_133 ;
int V_40 ;
V_133 . type = V_107 ;
V_133 . V_42 = V_129 ;
V_40 = F_42 ( V_2 , V_120 , & V_133 ) ;
if ( V_40 )
return V_40 ;
V_133 . type = V_87 ;
V_133 . V_42 = V_130 ;
return F_42 ( V_2 , V_120 , & V_133 ) ;
}
int F_45 ( struct V_1 * V_2 , T_1 V_134 )
{
struct V_135 V_136 ;
T_1 V_120 = V_137 ;
int V_40 ;
if ( V_2 -> V_6 == V_29 )
V_136 . V_52 = V_87 ;
else if ( V_2 -> V_6 == V_27 )
V_136 . V_52 = V_107 ;
else
return - V_124 ;
switch ( V_134 ) {
case V_138 :
V_136 . V_139 = V_140 ;
break;
case V_141 :
V_136 . V_139 = V_142 ;
break;
default:
return - V_124 ;
}
V_40 = F_42 ( V_2 , V_120 , & V_136 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
static void F_46 ( struct V_143 * V_144 )
{
struct V_85 * V_38 , * V_58 ;
struct V_1 * V_2 ;
int V_40 ;
V_2 = F_47 ( V_144 , struct V_1 , V_145 ) ;
F_21 ( & V_2 -> V_69 ) ;
if ( ! ( V_2 -> V_146 & V_2 -> V_147 ) )
goto V_148;
F_12 (buf, n, &inst->delayed_process, ref_list) {
if ( V_38 -> V_103 & V_149 )
continue;
V_40 = F_32 ( V_2 , & V_38 -> V_97 ) ;
if ( V_40 )
F_28 ( V_2 , & V_38 -> V_97 ) ;
F_14 ( & V_38 -> V_150 ) ;
}
V_148:
F_23 ( & V_2 -> V_69 ) ;
}
void F_48 ( struct V_1 * V_2 , unsigned int V_151 )
{
struct V_85 * V_38 ;
F_22 (buf, &inst->registeredbufs, reg_list) {
if ( V_38 -> V_97 . V_93 . V_105 == V_151 ) {
V_38 -> V_103 &= ~ V_149 ;
F_49 ( & V_2 -> V_145 ) ;
break;
}
}
}
void F_50 ( struct V_89 * V_90 )
{
struct V_85 * V_38 = F_33 ( V_90 ) ;
V_38 -> V_103 |= V_149 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
struct V_85 * V_38 = F_33 ( V_90 ) ;
if ( V_38 -> V_103 & V_149 ) {
F_8 ( & V_38 -> V_150 , & V_2 -> V_152 ) ;
F_49 ( & V_2 -> V_145 ) ;
return 1 ;
}
return 0 ;
}
struct V_89 *
F_52 ( struct V_1 * V_2 , unsigned int type , T_1 V_151 )
{
struct V_91 * V_92 = V_2 -> V_92 ;
if ( type == V_94 )
return F_53 ( V_92 , V_151 ) ;
else
return F_54 ( V_92 , V_151 ) ;
}
int F_55 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_56 ( V_97 -> V_153 ) ;
struct V_89 * V_90 = F_57 ( V_97 ) ;
struct V_85 * V_38 = F_33 ( V_90 ) ;
struct V_154 * V_155 ;
V_155 = F_58 ( V_97 , 0 ) ;
if ( ! V_155 )
return - V_156 ;
V_38 -> V_41 = F_59 ( V_97 , 0 ) ;
V_38 -> V_88 = F_60 ( V_155 -> V_157 ) ;
if ( V_97 -> type == V_114 )
F_8 ( & V_38 -> V_117 , & V_2 -> V_158 ) ;
return 0 ;
}
int F_61 ( struct V_96 * V_97 )
{
struct V_1 * V_2 = F_56 ( V_97 -> V_153 ) ;
if ( V_97 -> type == V_114 &&
F_59 ( V_97 , 0 ) < V_2 -> V_159 )
return - V_124 ;
if ( V_97 -> type == V_94 &&
F_59 ( V_97 , 0 ) < V_2 -> V_160 )
return - V_124 ;
return 0 ;
}
void F_62 ( struct V_96 * V_97 )
{
struct V_89 * V_90 = F_57 ( V_97 ) ;
struct V_1 * V_2 = F_56 ( V_97 -> V_153 ) ;
struct V_91 * V_92 = V_2 -> V_92 ;
int V_40 ;
F_21 ( & V_2 -> V_69 ) ;
if ( V_2 -> V_161 ) {
V_90 -> V_103 |= V_112 ;
F_31 ( V_90 , V_162 ) ;
V_2 -> V_161 = false ;
goto V_148;
}
F_63 ( V_92 , V_90 ) ;
if ( ! ( V_2 -> V_146 & V_2 -> V_147 ) )
goto V_148;
V_40 = F_51 ( V_2 , V_90 ) ;
if ( V_40 )
goto V_148;
V_40 = F_32 ( V_2 , V_90 ) ;
if ( V_40 )
F_28 ( V_2 , V_90 ) ;
V_148:
F_23 ( & V_2 -> V_69 ) ;
}
void F_64 ( struct V_1 * V_2 ,
enum V_163 V_62 )
{
struct V_89 * V_38 ;
while ( ( V_38 = F_65 ( V_2 -> V_92 ) ) )
F_31 ( V_38 , V_62 ) ;
while ( ( V_38 = F_66 ( V_2 -> V_92 ) ) )
F_31 ( V_38 , V_62 ) ;
}
void F_67 ( struct V_153 * V_164 )
{
struct V_1 * V_2 = F_56 ( V_164 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_40 ;
F_21 ( & V_2 -> V_69 ) ;
if ( V_2 -> V_146 & V_2 -> V_147 ) {
V_40 = F_68 ( V_2 ) ;
V_40 |= F_69 ( V_2 ) ;
V_40 |= F_38 ( V_2 ) ;
V_40 |= F_17 ( V_2 ) ;
V_40 |= F_70 ( V_2 ) ;
if ( V_2 -> V_165 || V_5 -> V_166 )
V_40 = - V_167 ;
if ( V_40 )
F_71 ( V_2 ) ;
F_24 ( V_5 ) ;
F_72 ( & V_2 -> V_158 ) ;
}
F_64 ( V_2 , V_95 ) ;
if ( V_164 -> type == V_94 )
V_2 -> V_146 = 0 ;
else
V_2 -> V_147 = 0 ;
F_23 ( & V_2 -> V_69 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_40 ;
V_40 = F_15 ( V_2 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_39 ( V_2 ) ;
if ( V_40 )
goto V_168;
F_24 ( V_5 ) ;
V_40 = F_74 ( V_2 ) ;
if ( V_40 )
goto V_169;
V_40 = F_75 ( V_2 ) ;
if ( V_40 )
goto V_170;
return 0 ;
V_170:
F_69 ( V_2 ) ;
V_169:
F_38 ( V_2 ) ;
V_168:
F_17 ( V_2 ) ;
return V_40 ;
}
void F_76 ( void * V_171 )
{
struct V_1 * V_2 = V_171 ;
struct V_91 * V_92 = V_2 -> V_92 ;
struct V_172 * V_38 , * V_58 ;
int V_40 ;
F_21 ( & V_2 -> V_69 ) ;
F_77 (m2m_ctx, buf, n) {
V_40 = F_32 ( V_2 , & V_38 -> V_97 ) ;
if ( V_40 )
F_28 ( V_2 , & V_38 -> V_97 ) ;
}
F_78 (m2m_ctx, buf, n) {
V_40 = F_32 ( V_2 , & V_38 -> V_97 ) ;
if ( V_40 )
F_28 ( V_2 , & V_38 -> V_97 ) ;
}
F_23 ( & V_2 -> V_69 ) ;
}
void F_79 ( void * V_171 )
{
struct V_1 * V_2 = V_171 ;
F_80 ( V_2 -> V_173 , V_2 -> V_92 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 == V_29 ) {
F_72 ( & V_2 -> V_152 ) ;
F_82 ( & V_2 -> V_145 ,
F_46 ) ;
}
}
