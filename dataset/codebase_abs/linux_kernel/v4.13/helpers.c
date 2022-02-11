static int F_1 ( struct V_1 * V_2 , T_1 type )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 V_8 ;
struct V_9 V_10 ;
struct V_11 * V_12 ;
unsigned int V_13 ;
int V_14 ;
V_14 = F_2 ( V_2 , type , & V_8 ) ;
if ( V_14 )
return 0 ;
if ( ! V_8 . V_15 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_8 . V_16 ; V_13 ++ ) {
V_12 = F_3 ( sizeof( * V_12 ) , V_17 ) ;
if ( ! V_12 ) {
V_14 = - V_18 ;
goto V_19;
}
V_12 -> type = V_8 . type ;
V_12 -> V_15 = V_8 . V_15 ;
V_12 -> V_20 = V_21 |
V_22 ;
V_12 -> V_23 = F_4 ( V_6 , V_12 -> V_15 , & V_12 -> V_24 , V_17 ,
V_12 -> V_20 ) ;
if ( ! V_12 -> V_23 ) {
V_14 = - V_18 ;
goto V_19;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_25 = V_12 -> V_15 ;
V_10 . V_26 = V_12 -> type ;
V_10 . V_27 = 1 ;
V_10 . V_28 = V_12 -> V_24 ;
V_14 = F_5 ( V_2 , & V_10 ) ;
if ( V_14 ) {
F_6 ( V_6 , L_1 ) ;
goto V_29;
}
F_7 ( & V_12 -> V_30 , & V_2 -> V_31 ) ;
}
return 0 ;
V_29:
F_8 ( V_6 , V_12 -> V_15 , V_12 -> V_23 , V_12 -> V_24 , V_12 -> V_20 ) ;
V_19:
F_9 ( V_12 ) ;
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_9 V_10 = { 0 } ;
struct V_11 * V_12 , * V_32 ;
int V_14 = 0 ;
F_11 (buf, n, &inst->internalbufs, list) {
V_10 . V_25 = V_12 -> V_15 ;
V_10 . V_26 = V_12 -> type ;
V_10 . V_27 = 1 ;
V_10 . V_28 = V_12 -> V_24 ;
V_10 . V_33 = true ;
V_14 = F_12 ( V_2 , & V_10 ) ;
F_13 ( & V_12 -> V_30 ) ;
F_8 ( V_2 -> V_4 -> V_6 , V_12 -> V_15 , V_12 -> V_23 , V_12 -> V_24 ,
V_12 -> V_20 ) ;
F_9 ( V_12 ) ;
}
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned int V_13 ;
int V_14 ;
for ( V_13 = 0 ; V_13 < F_15 ( V_34 ) ; V_13 ++ ) {
V_14 = F_1 ( V_2 , V_34 [ V_13 ] ) ;
if ( V_14 )
goto error;
}
return 0 ;
error:
F_10 ( V_2 ) ;
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_10 ( V_2 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 )
{
T_1 V_35 ;
if ( ! V_2 || ! ( V_2 -> V_36 >= V_37 && V_2 -> V_36 < V_38 ) )
return 0 ;
V_35 = ( F_18 ( V_2 -> V_39 , 16 ) / 16 ) * ( F_18 ( V_2 -> V_40 , 16 ) / 16 ) ;
return V_35 * V_2 -> V_41 ;
}
static T_1 F_19 ( struct V_3 * V_4 , T_1 V_42 )
{
struct V_1 * V_2 = NULL ;
T_1 V_43 = 0 ;
F_20 ( & V_4 -> V_44 ) ;
F_21 (inst, &core->instances, list) {
if ( V_2 -> V_42 != V_42 )
continue;
V_43 += F_17 ( V_2 ) ;
}
F_22 ( & V_4 -> V_44 ) ;
return V_43 ;
}
static int F_23 ( struct V_3 * V_4 )
{
const struct V_45 * V_46 = V_4 -> V_47 -> V_45 ;
unsigned int V_48 = V_4 -> V_47 -> V_49 ;
unsigned long V_50 = V_46 [ 0 ] . V_50 ;
struct V_51 * V_51 = V_4 -> V_52 [ 0 ] ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_1 V_43 ;
unsigned int V_13 ;
int V_14 ;
V_43 = F_19 ( V_4 , V_53 ) +
F_19 ( V_4 , V_54 ) ;
if ( V_43 > V_4 -> V_47 -> V_55 )
F_24 ( V_6 , L_2 ,
V_43 , V_4 -> V_47 -> V_55 ) ;
if ( ! V_43 && V_48 > 1 ) {
V_50 = V_46 [ V_48 - 1 ] . V_50 ;
goto V_56;
}
for ( V_13 = 0 ; V_13 < V_48 ; V_13 ++ ) {
if ( V_43 > V_46 [ V_13 ] . V_57 )
break;
V_50 = V_46 [ V_13 ] . V_50 ;
}
V_56:
if ( V_4 -> V_47 -> V_58 == V_59 ) {
V_14 = F_25 ( V_51 , V_50 ) ;
V_14 |= F_25 ( V_4 -> V_60 , V_50 ) ;
V_14 |= F_25 ( V_4 -> V_61 , V_50 ) ;
} else {
V_14 = F_25 ( V_51 , V_50 ) ;
}
if ( V_14 ) {
F_6 ( V_6 , L_3 , V_50 , V_14 ) ;
return V_14 ;
}
return 0 ;
}
static void F_26 ( const struct V_62 * V_12 ,
struct V_9 * V_10 , bool V_63 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_26 = V_64 ;
V_10 -> V_25 = V_12 -> V_15 ;
V_10 -> V_27 = 1 ;
V_10 -> V_28 = V_12 -> V_65 ;
V_10 -> V_33 = V_63 ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
struct V_68 * V_69 = V_2 -> V_69 ;
if ( V_67 -> V_70 . type == V_71 )
F_28 ( V_69 , V_67 ) ;
else
F_28 ( V_69 , V_67 ) ;
F_29 ( V_67 , V_72 ) ;
}
static int
F_30 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_62 * V_12 = F_31 ( V_67 ) ;
struct V_73 * V_74 = & V_67 -> V_70 ;
unsigned int type = V_74 -> type ;
struct V_75 V_76 ;
int V_14 ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_76 . V_77 = V_12 -> V_15 ;
V_76 . V_28 = V_12 -> V_65 ;
V_76 . V_78 = V_74 -> V_78 ;
F_32 ( V_76 . V_78 , V_79 ) ;
V_76 . V_80 = 0 ;
V_76 . V_81 = V_67 -> V_70 . V_82 ;
if ( ! V_76 . V_78 )
V_76 . V_80 |= V_83 ;
if ( type == V_71 ) {
V_76 . V_26 = V_84 ;
V_76 . V_85 = F_33 ( V_74 , 0 ) ;
V_76 . V_86 = V_74 -> V_87 [ 0 ] . V_88 ;
if ( V_67 -> V_80 & V_89 || ! V_76 . V_85 )
V_76 . V_80 |= V_90 ;
} else if ( type == V_91 ) {
V_76 . V_26 = V_64 ;
V_76 . V_85 = 0 ;
V_76 . V_86 = 0 ;
}
V_14 = F_34 ( V_2 , & V_76 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static inline int F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 == V_54 &&
V_2 -> V_4 -> V_47 -> V_58 == V_59 )
return 0 ;
if ( V_2 -> V_42 == V_54 &&
V_2 -> V_92 &&
V_2 -> V_4 -> V_47 -> V_58 == V_93 )
return 0 ;
return 1 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_62 * V_12 , * V_32 ;
struct V_9 V_10 ;
int V_14 = 0 ;
if ( ! F_35 ( V_2 ) )
return 0 ;
F_11 (buf, n, &inst->registeredbufs, reg_list) {
F_26 ( V_12 , & V_10 , true ) ;
V_14 = F_12 ( V_2 , & V_10 ) ;
F_13 ( & V_12 -> V_94 ) ;
}
return V_14 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_9 V_10 ;
struct V_62 * V_12 ;
int V_14 = 0 ;
if ( ! F_35 ( V_2 ) )
return 0 ;
F_21 (buf, &inst->registeredbufs, reg_list) {
F_26 ( V_12 , & V_10 , false ) ;
V_14 = F_5 ( V_2 , & V_10 ) ;
if ( V_14 ) {
F_6 ( V_6 , L_4 , V_95 ) ;
break;
}
}
return V_14 ;
}
int F_2 ( struct V_1 * V_2 , T_1 type ,
struct V_7 * V_96 )
{
T_1 V_97 = V_98 ;
union V_99 V_100 ;
unsigned int V_13 ;
int V_14 ;
if ( V_96 )
memset ( V_96 , 0 , sizeof( * V_96 ) ) ;
V_14 = F_38 ( V_2 , V_97 , & V_100 ) ;
if ( V_14 )
return V_14 ;
V_14 = - V_101 ;
for ( V_13 = 0 ; V_13 < V_102 ; V_13 ++ ) {
if ( V_100 . V_8 [ V_13 ] . type != type )
continue;
if ( V_96 )
memcpy ( V_96 , & V_100 . V_8 [ V_13 ] , sizeof( * V_96 ) ) ;
V_14 = 0 ;
break;
}
return V_14 ;
}
int F_39 ( struct V_1 * V_2 ,
unsigned int V_39 , unsigned int V_40 )
{
T_1 V_97 = V_103 ;
struct V_104 V_105 ;
V_105 . V_26 = V_84 ;
V_105 . V_39 = V_39 ;
V_105 . V_40 = V_40 ;
return F_40 ( V_2 , V_97 , & V_105 ) ;
}
int F_41 ( struct V_1 * V_2 ,
unsigned int V_39 , unsigned int V_40 )
{
T_1 V_97 = V_103 ;
struct V_104 V_105 ;
V_105 . V_26 = V_64 ;
V_105 . V_39 = V_39 ;
V_105 . V_40 = V_40 ;
return F_40 ( V_2 , V_97 , & V_105 ) ;
}
int F_42 ( struct V_1 * V_2 , unsigned int V_106 ,
unsigned int V_107 )
{
T_1 V_97 = V_108 ;
struct V_109 V_110 ;
int V_14 ;
V_110 . type = V_84 ;
V_110 . V_16 = V_106 ;
V_14 = F_40 ( V_2 , V_97 , & V_110 ) ;
if ( V_14 )
return V_14 ;
V_110 . type = V_64 ;
V_110 . V_16 = V_107 ;
return F_40 ( V_2 , V_97 , & V_110 ) ;
}
int F_43 ( struct V_1 * V_2 , T_1 V_111 )
{
struct V_112 V_113 ;
T_1 V_97 = V_114 ;
int V_14 ;
if ( V_2 -> V_42 == V_54 )
V_113 . V_26 = V_64 ;
else if ( V_2 -> V_42 == V_53 )
V_113 . V_26 = V_84 ;
else
return - V_101 ;
switch ( V_111 ) {
case V_115 :
V_113 . V_116 = V_117 ;
break;
case V_118 :
V_113 . V_116 = V_119 ;
break;
default:
return - V_101 ;
}
V_14 = F_40 ( V_2 , V_97 , & V_113 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static void F_44 ( struct V_120 * V_121 )
{
struct V_62 * V_12 , * V_32 ;
struct V_1 * V_2 ;
int V_14 ;
V_2 = F_45 ( V_121 , struct V_1 , V_122 ) ;
F_20 ( & V_2 -> V_44 ) ;
if ( ! ( V_2 -> V_123 & V_2 -> V_124 ) )
goto V_125;
F_11 (buf, n, &inst->delayed_process, ref_list) {
if ( V_12 -> V_80 & V_126 )
continue;
V_14 = F_30 ( V_2 , & V_12 -> V_74 ) ;
if ( V_14 )
F_27 ( V_2 , & V_12 -> V_74 ) ;
F_13 ( & V_12 -> V_127 ) ;
}
V_125:
F_22 ( & V_2 -> V_44 ) ;
}
void F_46 ( struct V_1 * V_2 , unsigned int V_128 )
{
struct V_62 * V_12 ;
F_21 (buf, &inst->registeredbufs, reg_list) {
if ( V_12 -> V_74 . V_70 . V_82 == V_128 ) {
V_12 -> V_80 &= ~ V_126 ;
F_47 ( & V_2 -> V_122 ) ;
break;
}
}
}
void F_48 ( struct V_66 * V_67 )
{
struct V_62 * V_12 = F_31 ( V_67 ) ;
V_12 -> V_80 |= V_126 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_66 * V_67 )
{
struct V_62 * V_12 = F_31 ( V_67 ) ;
if ( V_12 -> V_80 & V_126 ) {
F_7 ( & V_12 -> V_127 , & V_2 -> V_129 ) ;
F_47 ( & V_2 -> V_122 ) ;
return 1 ;
}
return 0 ;
}
struct V_66 *
F_50 ( struct V_1 * V_2 , unsigned int type , T_1 V_128 )
{
struct V_68 * V_69 = V_2 -> V_69 ;
if ( type == V_71 )
return F_51 ( V_69 , V_128 ) ;
else
return F_52 ( V_69 , V_128 ) ;
}
int F_53 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_54 ( V_74 -> V_130 ) ;
struct V_66 * V_67 = F_55 ( V_74 ) ;
struct V_62 * V_12 = F_31 ( V_67 ) ;
struct V_131 * V_132 ;
V_132 = F_56 ( V_74 , 0 ) ;
if ( ! V_132 )
return - V_133 ;
V_12 -> V_15 = F_57 ( V_74 , 0 ) ;
V_12 -> V_65 = F_58 ( V_132 -> V_134 ) ;
if ( V_74 -> type == V_91 )
F_7 ( & V_12 -> V_94 , & V_2 -> V_135 ) ;
return 0 ;
}
int F_59 ( struct V_73 * V_74 )
{
struct V_1 * V_2 = F_54 ( V_74 -> V_130 ) ;
if ( V_74 -> type == V_91 &&
F_57 ( V_74 , 0 ) < V_2 -> V_136 )
return - V_101 ;
if ( V_74 -> type == V_71 &&
F_57 ( V_74 , 0 ) < V_2 -> V_137 )
return - V_101 ;
return 0 ;
}
void F_60 ( struct V_73 * V_74 )
{
struct V_66 * V_67 = F_55 ( V_74 ) ;
struct V_1 * V_2 = F_54 ( V_74 -> V_130 ) ;
struct V_68 * V_69 = V_2 -> V_69 ;
int V_14 ;
F_20 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_138 ) {
V_67 -> V_80 |= V_89 ;
F_29 ( V_67 , V_139 ) ;
V_2 -> V_138 = false ;
goto V_125;
}
F_61 ( V_69 , V_67 ) ;
if ( ! ( V_2 -> V_123 & V_2 -> V_124 ) )
goto V_125;
V_14 = F_49 ( V_2 , V_67 ) ;
if ( V_14 )
goto V_125;
V_14 = F_30 ( V_2 , V_67 ) ;
if ( V_14 )
F_27 ( V_2 , V_67 ) ;
V_125:
F_22 ( & V_2 -> V_44 ) ;
}
void F_62 ( struct V_1 * V_2 ,
enum V_140 V_36 )
{
struct V_66 * V_12 ;
while ( ( V_12 = F_63 ( V_2 -> V_69 ) ) )
F_29 ( V_12 , V_36 ) ;
while ( ( V_12 = F_64 ( V_2 -> V_69 ) ) )
F_29 ( V_12 , V_36 ) ;
}
void F_65 ( struct V_130 * V_141 )
{
struct V_1 * V_2 = F_54 ( V_141 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_14 ;
F_20 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_123 & V_2 -> V_124 ) {
V_14 = F_66 ( V_2 ) ;
V_14 |= F_67 ( V_2 ) ;
V_14 |= F_36 ( V_2 ) ;
V_14 |= F_16 ( V_2 ) ;
V_14 |= F_68 ( V_2 ) ;
if ( V_2 -> V_142 || V_4 -> V_143 )
V_14 = - V_144 ;
if ( V_14 )
F_69 ( V_2 ) ;
F_23 ( V_4 ) ;
}
F_62 ( V_2 , V_72 ) ;
if ( V_141 -> type == V_71 )
V_2 -> V_123 = 0 ;
else
V_2 -> V_124 = 0 ;
F_22 ( & V_2 -> V_44 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_14 ;
V_14 = F_14 ( V_2 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_37 ( V_2 ) ;
if ( V_14 )
goto V_145;
F_23 ( V_4 ) ;
V_14 = F_71 ( V_2 ) ;
if ( V_14 )
goto V_146;
V_14 = F_72 ( V_2 ) ;
if ( V_14 )
goto V_147;
return 0 ;
V_147:
F_67 ( V_2 ) ;
V_146:
F_36 ( V_2 ) ;
V_145:
F_16 ( V_2 ) ;
return V_14 ;
}
void F_73 ( void * V_148 )
{
struct V_1 * V_2 = V_148 ;
struct V_68 * V_69 = V_2 -> V_69 ;
struct V_149 * V_12 , * V_32 ;
int V_14 ;
F_20 ( & V_2 -> V_44 ) ;
F_74 (m2m_ctx, buf, n) {
V_14 = F_30 ( V_2 , & V_12 -> V_74 ) ;
if ( V_14 )
F_27 ( V_2 , & V_12 -> V_74 ) ;
}
F_75 (m2m_ctx, buf, n) {
V_14 = F_30 ( V_2 , & V_12 -> V_74 ) ;
if ( V_14 )
F_27 ( V_2 , & V_12 -> V_74 ) ;
}
F_22 ( & V_2 -> V_44 ) ;
}
void F_76 ( void * V_148 )
{
struct V_1 * V_2 = V_148 ;
F_77 ( V_2 -> V_150 , V_2 -> V_69 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
if ( V_2 -> V_42 == V_54 ) {
F_79 ( & V_2 -> V_129 ) ;
F_80 ( & V_2 -> V_122 ,
F_44 ) ;
}
}
