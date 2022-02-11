static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_4 , struct V_6 , V_4 ) ;
return sprintf ( V_5 , L_1 , ( char * ) V_7 -> V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_4 , struct V_6 , V_4 ) ;
return sprintf ( V_5 , L_2 , ( unsigned long ) V_7 -> V_8 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_9 * V_10 = F_5 ( F_6 ( V_2 ) ) ;
return F_7 ( true , V_5 , & V_10 -> V_11 -> V_12 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
int V_13 ;
V_13 = F_9 ( V_10 -> V_14 ,
V_10 -> V_15 ) ;
if ( V_13 == V_10 -> V_15 )
return - V_16 ;
F_10 ( V_13 , V_10 -> V_14 ) ;
return V_13 ;
}
static void F_11 ( struct V_9 * V_10 , int V_13 )
{
F_12 ( V_13 , V_10 -> V_14 ) ;
}
static inline void F_13 ( struct V_17 * V_17 )
{
F_14 ( V_18 , V_17 -> V_19 + V_20 ) ;
}
static inline void F_15 ( struct V_17 * V_17 )
{
F_14 ( V_21 , V_17 -> V_19 + V_20 ) ;
}
static inline T_2 F_16 ( struct V_9 * V_10 , int V_22 )
{
return F_17 ( V_10 -> V_23 -> V_24 + V_25 + ( 4 * V_22 ) ) ;
}
static inline void
F_18 ( struct V_9 * V_10 , int V_22 , T_2 V_26 )
{
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_25 + ( 4 * V_22 ) ) ;
}
static inline void
F_19 ( struct V_9 * V_10 , int V_22 , T_2 V_26 )
{
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_27 + ( 4 * V_22 ) ) ;
}
static inline void
F_20 ( struct V_9 * V_10 , T_2 V_26 )
{
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_28 ) ;
}
static inline void
F_21 ( struct V_9 * V_10 , T_2 V_26 )
{
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_29 ) ;
}
static inline void
F_22 ( struct V_9 * V_10 , int V_22 )
{
T_2 V_26 ;
V_26 = F_17 ( V_10 -> V_23 -> V_24 + V_30 ) ;
V_26 |= 1 << V_22 ;
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_30 ) ;
}
static inline void
F_23 ( struct V_9 * V_10 , int V_22 )
{
T_2 V_26 ;
V_26 = F_17 ( V_10 -> V_23 -> V_24 + V_31 ) ;
V_26 |= 1 << V_22 ;
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_31 ) ;
}
static inline void
F_24 ( struct V_9 * V_10 , int V_22 )
{
T_2 V_26 ;
V_26 = F_17 ( V_10 -> V_23 -> V_24 + V_32 ) ;
V_26 |= 1 << V_22 ;
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_32 ) ;
}
static inline void
F_25 ( struct V_9 * V_10 , int V_22 )
{
T_2 V_26 ;
V_26 = F_17 ( V_10 -> V_23 -> V_24 + V_33 ) ;
V_26 |= 1 << V_22 ;
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_33 ) ;
}
static inline void F_26 ( struct V_9 * V_10 )
{
T_2 V_26 ;
V_26 = F_17 ( V_10 -> V_23 -> V_24 + V_34 ) ;
V_26 |= V_35 ;
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_34 ) ;
}
static inline void F_27 ( struct V_9 * V_10 )
{
T_2 V_26 ;
V_26 = F_17 ( V_10 -> V_23 -> V_24 + V_34 ) ;
V_26 |= V_36 ;
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_34 ) ;
}
static inline void F_28 ( struct V_9 * V_10 )
{
T_2 V_26 ;
V_26 = F_17 ( V_10 -> V_23 -> V_24 + V_34 ) ;
V_26 &= ~ V_36 ;
F_14 ( V_26 , V_10 -> V_23 -> V_24 + V_34 ) ;
}
static void F_29 ( struct V_37 * V_37 )
{
struct V_9 * V_10 = F_5 ( V_37 ) ;
int V_38 = F_30 ( V_10 -> V_14 ,
V_10 -> V_15 ) ;
if ( ! V_38 )
return;
F_27 ( V_10 ) ;
}
static void F_31 ( struct V_37 * V_37 )
{
struct V_9 * V_10 = F_5 ( V_37 ) ;
F_28 ( V_10 ) ;
}
static int F_32 ( struct V_39 * V_40 )
{
struct V_9 * V_10 = F_5 ( V_40 -> V_37 ) ;
struct V_41 * V_42 = & V_40 -> V_42 ;
struct V_39 * V_43 ;
if ( V_40 -> V_4 . type != V_40 -> V_37 -> type )
return - V_44 ;
if ( F_33 ( V_40 ) || V_40 -> V_45 & V_46 )
return - V_47 ;
if ( V_40 -> V_4 . V_48 || V_40 -> V_4 . V_49 ||
V_40 -> V_4 . V_50 || V_40 -> V_4 . V_51 )
return - V_47 ;
if ( V_40 -> V_12 < 0 )
return - V_47 ;
V_40 -> V_12 = F_34 ( & V_10 -> V_11 -> V_12 ) ;
V_42 -> V_52 = V_40 -> V_4 . V_52 ;
V_42 -> V_53 = V_40 -> V_4 . V_54 ;
if ( V_40 -> V_55 -> V_37 != V_40 -> V_37 &&
! F_35 ( V_40 -> V_55 ) )
return - V_47 ;
F_36 (sibling, &event->group_leader->sibling_list,
group_entry)
if ( V_43 -> V_37 != V_40 -> V_37 &&
! F_35 ( V_43 ) )
return - V_47 ;
return 0 ;
}
static void F_37 ( struct V_39 * V_40 )
{
struct V_9 * V_10 = F_5 ( V_40 -> V_37 ) ;
F_19 ( V_10 , F_38 ( V_40 ) , F_39 ( V_40 ) ) ;
F_20 ( V_10 , ~ ( ( T_2 ) F_40 ( V_40 ) ) ) ;
if ( V_10 -> V_23 -> type == V_56 )
F_21 ( V_10 , ~ ( ( T_2 ) F_41 ( V_40 ) ) ) ;
F_22 ( V_10 , F_38 ( V_40 ) ) ;
F_24 ( V_10 , F_38 ( V_40 ) ) ;
}
static void F_42 ( struct V_39 * V_40 )
{
struct V_9 * V_10 = F_5 ( V_40 -> V_37 ) ;
F_23 ( V_10 , F_38 ( V_40 ) ) ;
F_25 ( V_10 , F_38 ( V_40 ) ) ;
}
static void F_43 ( struct V_39 * V_40 )
{
struct V_9 * V_10 = F_5 ( V_40 -> V_37 ) ;
struct V_41 * V_42 = & V_40 -> V_42 ;
T_3 V_26 = 1ULL << 31 ;
F_44 ( & V_42 -> V_57 , V_26 ) ;
F_18 ( V_10 , V_42 -> V_22 , ( T_2 ) V_26 ) ;
}
static void F_45 ( struct V_39 * V_40 )
{
struct V_9 * V_10 = F_5 ( V_40 -> V_37 ) ;
struct V_41 * V_42 = & V_40 -> V_42 ;
T_3 V_58 , V_59 , V_60 ;
V_61:
V_59 = F_46 ( & V_42 -> V_57 ) ;
V_60 = F_16 ( V_10 , F_38 ( V_40 ) ) ;
if ( F_47 ( & V_42 -> V_57 , V_59 ,
V_60 ) != V_59 )
goto V_61;
V_58 = ( V_60 - V_59 ) & V_10 -> V_62 ;
F_48 ( V_58 , & V_40 -> V_63 ) ;
}
static void F_49 ( struct V_39 * V_40 )
{
F_45 ( V_40 ) ;
}
static void F_50 ( struct V_39 * V_40 , int V_64 )
{
struct V_9 * V_10 = F_5 ( V_40 -> V_37 ) ;
struct V_41 * V_42 = & V_40 -> V_42 ;
if ( F_51 ( ! ( V_42 -> V_65 & V_66 ) ) )
return;
F_51 ( ! ( V_42 -> V_65 & V_67 ) ) ;
V_42 -> V_65 = 0 ;
F_43 ( V_40 ) ;
if ( V_64 & V_68 ) {
T_3 V_59 = F_46 ( & V_42 -> V_57 ) ;
F_18 ( V_10 , F_38 ( V_40 ) ,
( T_2 ) V_59 ) ;
}
F_37 ( V_40 ) ;
F_52 ( V_40 ) ;
}
static void F_53 ( struct V_39 * V_40 , int V_64 )
{
struct V_41 * V_42 = & V_40 -> V_42 ;
T_3 V_52 ;
if ( V_42 -> V_65 & V_67 )
return;
F_42 ( V_40 ) ;
F_51 ( V_42 -> V_65 & V_66 ) ;
V_42 -> V_65 |= V_66 ;
if ( V_42 -> V_65 & V_67 )
return;
V_52 = V_42 -> V_52 ;
F_49 ( V_40 ) ;
V_42 -> V_65 |= V_67 ;
}
static int F_54 ( struct V_39 * V_40 , int V_64 )
{
struct V_9 * V_10 = F_5 ( V_40 -> V_37 ) ;
struct V_41 * V_42 = & V_40 -> V_42 ;
V_42 -> V_65 = V_67 | V_66 ;
V_42 -> V_22 = F_8 ( V_10 ) ;
if ( V_42 -> V_22 < 0 )
return - V_69 ;
V_10 -> V_70 [ V_42 -> V_22 ] = V_40 ;
if ( V_64 & V_71 )
F_50 ( V_40 , V_68 ) ;
return 0 ;
}
static void F_55 ( struct V_39 * V_40 , int V_64 )
{
struct V_9 * V_10 = F_5 ( V_40 -> V_37 ) ;
struct V_41 * V_42 = & V_40 -> V_42 ;
F_53 ( V_40 , V_72 ) ;
F_11 ( V_10 , F_38 ( V_40 ) ) ;
F_52 ( V_40 ) ;
V_10 -> V_70 [ V_42 -> V_22 ] = NULL ;
}
static int F_56 ( struct V_9 * V_10 , char * V_73 )
{
struct V_17 * V_17 ;
V_10 -> V_62 = V_74 - 1 ;
V_17 = V_10 -> V_11 ;
if ( V_17 -> V_75 == V_76 )
V_10 -> V_15 = 1 ;
else
V_10 -> V_15 = V_77 ;
V_10 -> V_37 = (struct V_37 ) {
. V_78 = V_10 -> V_78 ,
. V_79 = V_80 ,
. V_81 = F_29 ,
. V_82 = F_31 ,
. V_83 = F_32 ,
. V_84 = F_54 ,
. V_85 = F_55 ,
. V_86 = F_50 ,
. V_87 = F_53 ,
. V_88 = F_49 ,
} ;
F_28 ( V_10 ) ;
F_26 ( V_10 ) ;
return F_57 ( & V_10 -> V_37 , V_73 , - 1 ) ;
}
static int
F_58 ( struct V_17 * V_17 , struct V_89 * V_90 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_9 * V_37 ;
int V_91 ;
V_37 = F_59 ( V_2 , sizeof( * V_37 ) , V_92 ) ;
if ( ! V_37 )
return - V_93 ;
V_37 -> V_11 = V_17 ;
V_37 -> V_23 = & V_90 -> V_23 ;
V_90 -> V_10 = V_37 ;
switch ( V_37 -> V_23 -> type ) {
case V_94 :
V_37 -> V_78 = V_95 ;
break;
case V_56 :
V_37 -> V_78 = V_96 ;
break;
case V_97 :
if ( ! ( V_17 -> V_98 & V_37 -> V_23 -> V_99 ) )
goto V_100;
V_37 -> V_78 = V_101 ;
break;
case V_102 :
if ( ! ( V_17 -> V_103 & V_37 -> V_23 -> V_99 ) )
goto V_100;
V_37 -> V_78 = V_104 ;
break;
default:
return - V_47 ;
}
V_91 = F_56 ( V_37 , V_90 -> V_73 ) ;
if ( V_91 ) {
V_100 ( V_2 , L_3 , V_90 -> V_73 ) ;
goto V_100;
}
F_60 ( V_2 , L_4 , V_90 -> V_73 ) ;
return V_91 ;
V_100:
F_61 ( V_2 , V_37 ) ;
return - V_105 ;
}
static void F_62 ( int V_106 , struct V_9 * V_10 )
{
struct V_17 * V_17 = V_10 -> V_11 ;
T_2 V_107 ;
int V_22 ;
V_107 = F_17 ( V_10 -> V_23 -> V_24 + V_108 ) & V_109 ;
if ( ! V_107 )
return;
if ( V_17 -> V_75 == V_76 )
F_14 ( 0x0 , V_10 -> V_23 -> V_24 + V_108 ) ;
else
F_14 ( V_107 , V_10 -> V_23 -> V_24 + V_108 ) ;
for ( V_22 = 0 ; V_22 < V_77 ; V_22 ++ ) {
struct V_39 * V_40 = V_10 -> V_70 [ V_22 ] ;
int V_110 = V_107 & F_63 ( V_22 ) ;
if ( ! V_40 || ! V_110 )
continue;
F_45 ( V_40 ) ;
F_43 ( V_40 ) ;
}
}
static T_4 F_64 ( int V_106 , void * V_111 )
{
struct V_89 * V_90 ;
struct V_17 * V_17 = V_111 ;
unsigned long V_64 ;
T_2 V_26 ;
F_65 ( & V_17 -> V_112 , V_64 ) ;
V_26 = F_17 ( V_17 -> V_19 + V_113 ) ;
if ( V_26 & V_114 ) {
F_36 (ctx, &xgene_pmu->mcpmus, next) {
F_62 ( V_106 , V_90 -> V_10 ) ;
}
}
if ( V_26 & V_115 ) {
F_36 (ctx, &xgene_pmu->mcbpmus, next) {
F_62 ( V_106 , V_90 -> V_10 ) ;
}
}
if ( V_26 & V_116 ) {
F_36 (ctx, &xgene_pmu->l3cpmus, next) {
F_62 ( V_106 , V_90 -> V_10 ) ;
}
}
if ( V_26 & V_117 ) {
F_36 (ctx, &xgene_pmu->iobpmus, next) {
F_62 ( V_106 , V_90 -> V_10 ) ;
}
}
F_66 ( & V_17 -> V_112 , V_64 ) ;
return V_118 ;
}
static int F_67 ( struct V_17 * V_17 ,
struct V_119 * V_120 )
{
void T_5 * V_121 , * V_122 , * V_123 ;
struct V_124 * V_125 ;
unsigned int V_126 ;
V_125 = F_68 ( V_120 , V_127 , 1 ) ;
V_121 = F_69 ( & V_120 -> V_2 , V_125 ) ;
if ( F_70 ( V_121 ) ) {
V_100 ( & V_120 -> V_2 , L_5 ) ;
return F_71 ( V_121 ) ;
}
V_125 = F_68 ( V_120 , V_127 , 2 ) ;
V_122 = F_69 ( & V_120 -> V_2 , V_125 ) ;
if ( F_70 ( V_122 ) ) {
V_100 ( & V_120 -> V_2 , L_6 ) ;
return F_71 ( V_122 ) ;
}
V_125 = F_68 ( V_120 , V_127 , 3 ) ;
V_123 = F_69 ( & V_120 -> V_2 , V_125 ) ;
if ( F_70 ( V_123 ) ) {
V_100 ( & V_120 -> V_2 , L_7 ) ;
return F_71 ( V_123 ) ;
}
V_126 = F_17 ( V_121 + V_128 ) ;
if ( V_126 & V_129 ) {
V_17 -> V_98 = 0x3 ;
V_126 = F_17 ( V_123 + V_128 ) ;
V_17 -> V_103 =
( V_126 & V_130 ) ? 0xF : 0x5 ;
} else {
V_17 -> V_98 = 0x1 ;
V_126 = F_17 ( V_122 + V_128 ) ;
V_17 -> V_103 =
( V_126 & V_130 ) ? 0x3 : 0x1 ;
}
return 0 ;
}
static int F_72 ( struct V_17 * V_17 ,
struct V_119 * V_120 )
{
struct V_131 * V_132 , * V_133 , * V_134 ;
struct V_135 * V_136 = V_120 -> V_2 . V_137 ;
unsigned int V_126 ;
V_132 = F_73 ( V_136 , L_8 ) ;
if ( F_70 ( V_132 ) ) {
V_100 ( & V_120 -> V_2 , L_9 ) ;
return F_71 ( V_132 ) ;
}
V_133 = F_73 ( V_136 , L_10 ) ;
if ( F_70 ( V_133 ) ) {
V_100 ( & V_120 -> V_2 , L_11 ) ;
return F_71 ( V_133 ) ;
}
V_134 = F_73 ( V_136 , L_12 ) ;
if ( F_70 ( V_134 ) ) {
V_100 ( & V_120 -> V_2 , L_13 ) ;
return F_71 ( V_134 ) ;
}
if ( F_74 ( V_132 , V_128 , & V_126 ) )
return - V_47 ;
if ( V_126 & V_129 ) {
V_17 -> V_98 = 0x3 ;
if ( F_74 ( V_134 , V_138 , & V_126 ) )
return 0 ;
V_17 -> V_103 =
( V_126 & V_130 ) ? 0xF : 0x5 ;
} else {
V_17 -> V_98 = 0x1 ;
if ( F_74 ( V_133 , V_138 , & V_126 ) )
return 0 ;
V_17 -> V_103 =
( V_126 & V_130 ) ? 0x3 : 0x1 ;
}
return 0 ;
}
static int F_75 ( struct V_17 * V_17 ,
struct V_119 * V_120 )
{
if ( F_76 ( & V_120 -> V_2 ) )
return F_67 ( V_17 , V_120 ) ;
return F_72 ( V_17 , V_120 ) ;
}
static char * F_77 ( struct V_1 * V_2 , T_2 type , int V_139 )
{
switch ( type ) {
case V_94 :
return F_78 ( V_2 , V_92 , L_14 , V_139 ) ;
case V_56 :
return F_78 ( V_2 , V_92 , L_15 , V_139 ) ;
case V_97 :
return F_78 ( V_2 , V_92 , L_16 , V_139 ) ;
case V_102 :
return F_78 ( V_2 , V_92 , L_17 , V_139 ) ;
default:
return F_78 ( V_2 , V_92 , L_18 ) ;
}
}
static int F_79 ( struct V_140 * V_141 , void * V_142 )
{
struct V_124 * V_125 = V_142 ;
if ( V_141 -> type == V_143 )
F_80 ( V_141 , V_125 ) ;
return 1 ;
}
static struct
V_89 * F_81 ( struct V_17 * V_17 ,
struct V_144 * V_145 , T_2 type )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_146 V_147 ;
struct V_89 * V_90 ;
const union V_148 * V_149 ;
struct V_150 * V_23 ;
void T_5 * V_151 ;
struct V_124 V_125 ;
int V_152 ;
int V_91 ;
V_90 = F_59 ( V_2 , sizeof( * V_90 ) , V_92 ) ;
if ( ! V_90 )
return NULL ;
F_82 ( & V_147 ) ;
V_91 = F_83 ( V_145 , & V_147 ,
F_79 , & V_125 ) ;
F_84 ( & V_147 ) ;
if ( V_91 < 0 ) {
V_100 ( V_2 , L_19 , type ) ;
goto V_153;
}
V_151 = F_69 ( V_2 , & V_125 ) ;
if ( F_70 ( V_151 ) ) {
V_100 ( V_2 , L_20 , type ) ;
goto V_153;
}
V_91 = F_85 ( V_145 , L_21 ,
V_154 , & V_149 ) ;
if ( V_91 < 0 )
V_152 = 0 ;
else
V_152 = ( int ) V_149 -> integer . V_155 ;
V_90 -> V_73 = F_77 ( V_2 , type , V_152 ) ;
if ( ! V_90 -> V_73 ) {
V_100 ( V_2 , L_22 , type ) ;
goto V_153;
}
V_23 = & V_90 -> V_23 ;
V_23 -> type = type ;
V_23 -> V_24 = V_151 ;
V_23 -> V_99 = 1 << V_152 ;
return V_90 ;
V_153:
F_61 ( V_2 , V_90 ) ;
return NULL ;
}
static T_6 F_86 ( T_7 V_156 , T_2 V_157 ,
void * V_142 , void * * V_158 )
{
struct V_17 * V_17 = V_142 ;
struct V_89 * V_90 ;
struct V_144 * V_145 ;
if ( F_87 ( V_156 , & V_145 ) )
return V_159 ;
if ( F_88 ( V_145 ) || ! V_145 -> V_160 . V_161 )
return V_159 ;
if ( ! strcmp ( F_89 ( V_145 ) , L_23 ) )
V_90 = F_81 ( V_17 , V_145 , V_94 ) ;
else if ( ! strcmp ( F_89 ( V_145 ) , L_24 ) )
V_90 = F_81 ( V_17 , V_145 , V_56 ) ;
else if ( ! strcmp ( F_89 ( V_145 ) , L_25 ) )
V_90 = F_81 ( V_17 , V_145 , V_97 ) ;
else if ( ! strcmp ( F_89 ( V_145 ) , L_26 ) )
V_90 = F_81 ( V_17 , V_145 , V_102 ) ;
else
V_90 = NULL ;
if ( ! V_90 )
return V_159 ;
if ( F_58 ( V_17 , V_90 ) ) {
F_61 ( V_17 -> V_2 , V_90 ) ;
return V_159 ;
}
switch ( V_90 -> V_23 . type ) {
case V_94 :
F_90 ( & V_90 -> V_162 , & V_17 -> V_163 ) ;
break;
case V_56 :
F_90 ( & V_90 -> V_162 , & V_17 -> V_164 ) ;
break;
case V_97 :
F_90 ( & V_90 -> V_162 , & V_17 -> V_165 ) ;
break;
case V_102 :
F_90 ( & V_90 -> V_162 , & V_17 -> V_166 ) ;
break;
}
return V_159 ;
}
static int F_91 ( struct V_17 * V_17 ,
struct V_119 * V_120 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
T_7 V_156 ;
T_6 V_160 ;
V_156 = F_92 ( V_2 ) ;
if ( ! V_156 )
return - V_47 ;
V_160 = F_93 ( V_167 , V_156 , 1 ,
F_86 , NULL , V_17 , NULL ) ;
if ( F_94 ( V_160 ) ) {
V_100 ( V_2 , L_27 ) ;
return - V_105 ;
}
return 0 ;
}
static int F_91 ( struct V_17 * V_17 ,
struct V_119 * V_120 )
{
return 0 ;
}
static struct
V_89 * F_95 ( struct V_17 * V_17 ,
struct V_135 * V_136 , T_2 type )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_89 * V_90 ;
struct V_150 * V_23 ;
void T_5 * V_151 ;
struct V_124 V_125 ;
int V_152 ;
int V_91 ;
V_90 = F_59 ( V_2 , sizeof( * V_90 ) , V_92 ) ;
if ( ! V_90 )
return NULL ;
V_91 = F_96 ( V_136 , 0 , & V_125 ) ;
if ( V_91 < 0 ) {
V_100 ( V_2 , L_19 , type ) ;
goto V_153;
}
V_151 = F_69 ( V_2 , & V_125 ) ;
if ( F_70 ( V_151 ) ) {
V_100 ( V_2 , L_20 , type ) ;
goto V_153;
}
if ( F_97 ( V_136 , L_21 , & V_152 ) )
V_152 = 0 ;
V_90 -> V_73 = F_77 ( V_2 , type , V_152 ) ;
if ( ! V_90 -> V_73 ) {
V_100 ( V_2 , L_22 , type ) ;
goto V_153;
}
V_23 = & V_90 -> V_23 ;
V_23 -> type = type ;
V_23 -> V_24 = V_151 ;
V_23 -> V_99 = 1 << V_152 ;
return V_90 ;
V_153:
F_61 ( V_2 , V_90 ) ;
return NULL ;
}
static int F_98 ( struct V_17 * V_17 ,
struct V_119 * V_120 )
{
struct V_89 * V_90 ;
struct V_135 * V_136 ;
F_99 (pdev->dev.of_node, np) {
if ( ! F_100 ( V_136 ) )
continue;
if ( F_101 ( V_136 , L_28 ) )
V_90 = F_95 ( V_17 , V_136 , V_94 ) ;
else if ( F_101 ( V_136 , L_29 ) )
V_90 = F_95 ( V_17 , V_136 , V_56 ) ;
else if ( F_101 ( V_136 , L_30 ) )
V_90 = F_95 ( V_17 , V_136 , V_97 ) ;
else if ( F_101 ( V_136 , L_31 ) )
V_90 = F_95 ( V_17 , V_136 , V_102 ) ;
else
V_90 = NULL ;
if ( ! V_90 )
continue;
if ( F_58 ( V_17 , V_90 ) ) {
F_61 ( V_17 -> V_2 , V_90 ) ;
continue;
}
switch ( V_90 -> V_23 . type ) {
case V_94 :
F_90 ( & V_90 -> V_162 , & V_17 -> V_163 ) ;
break;
case V_56 :
F_90 ( & V_90 -> V_162 , & V_17 -> V_164 ) ;
break;
case V_97 :
F_90 ( & V_90 -> V_162 , & V_17 -> V_165 ) ;
break;
case V_102 :
F_90 ( & V_90 -> V_162 , & V_17 -> V_166 ) ;
break;
}
}
return 0 ;
}
static int F_102 ( struct V_17 * V_17 ,
struct V_119 * V_120 )
{
if ( F_76 ( & V_120 -> V_2 ) )
return F_91 ( V_17 , V_120 ) ;
return F_98 ( V_17 , V_120 ) ;
}
static int F_103 ( struct V_119 * V_120 )
{
const struct V_168 * V_169 ;
const struct V_170 * V_171 ;
struct V_17 * V_17 ;
struct V_124 * V_125 ;
int V_106 , V_91 ;
int V_75 ;
V_17 = F_59 ( & V_120 -> V_2 , sizeof( * V_17 ) , V_92 ) ;
if ( ! V_17 )
return - V_93 ;
V_17 -> V_2 = & V_120 -> V_2 ;
F_104 ( V_120 , V_17 ) ;
V_75 = - V_47 ;
V_171 = F_105 ( V_172 , & V_120 -> V_2 ) ;
if ( V_171 ) {
V_169 = ( const struct V_168 * ) V_171 -> V_142 ;
V_75 = V_169 -> V_139 ;
}
#ifdef F_106
if ( F_107 ( & V_120 -> V_2 ) ) {
const struct V_173 * V_174 ;
V_174 = F_108 ( V_175 , & V_120 -> V_2 ) ;
if ( V_174 )
V_75 = ( int ) V_174 -> V_176 ;
}
#endif
if ( V_75 < 0 )
return - V_105 ;
F_82 ( & V_17 -> V_163 ) ;
F_82 ( & V_17 -> V_164 ) ;
F_82 ( & V_17 -> V_165 ) ;
F_82 ( & V_17 -> V_166 ) ;
V_17 -> V_75 = V_75 ;
F_60 ( & V_120 -> V_2 , L_32 , V_17 -> V_75 ) ;
V_125 = F_68 ( V_120 , V_127 , 0 ) ;
V_17 -> V_19 = F_69 ( & V_120 -> V_2 , V_125 ) ;
if ( F_70 ( V_17 -> V_19 ) ) {
V_100 ( & V_120 -> V_2 , L_33 ) ;
V_91 = F_71 ( V_17 -> V_19 ) ;
goto V_153;
}
V_106 = F_109 ( V_120 , 0 ) ;
if ( V_106 < 0 ) {
V_100 ( & V_120 -> V_2 , L_34 ) ;
V_91 = - V_47 ;
goto V_153;
}
V_91 = F_110 ( & V_120 -> V_2 , V_106 , F_64 ,
V_177 | V_178 ,
F_111 ( & V_120 -> V_2 ) , V_17 ) ;
if ( V_91 ) {
V_100 ( & V_120 -> V_2 , L_35 , V_106 ) ;
goto V_153;
}
F_112 ( & V_17 -> V_112 ) ;
V_91 = F_75 ( V_17 , V_120 ) ;
if ( V_91 ) {
F_113 ( & V_120 -> V_2 , L_36 ) ;
V_17 -> V_98 = 0x1 ;
V_17 -> V_103 = 0x1 ;
}
F_114 ( F_115 () , & V_17 -> V_12 ) ;
V_91 = F_116 ( V_106 , & V_17 -> V_12 ) ;
if ( V_91 ) {
V_100 ( & V_120 -> V_2 , L_37 ) ;
goto V_153;
}
V_91 = F_102 ( V_17 , V_120 ) ;
if ( V_91 ) {
V_100 ( & V_120 -> V_2 , L_38 ) ;
goto V_153;
}
F_15 ( V_17 ) ;
return 0 ;
V_153:
if ( V_17 -> V_19 )
F_117 ( & V_120 -> V_2 , V_17 -> V_19 ) ;
F_61 ( & V_120 -> V_2 , V_17 ) ;
return V_91 ;
}
static void
F_118 ( struct V_17 * V_17 , struct V_146 * V_179 )
{
struct V_89 * V_90 ;
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_9 * V_10 ;
F_36 (ctx, pmus, next) {
V_10 = V_90 -> V_10 ;
if ( V_10 -> V_23 -> V_24 )
F_117 ( V_2 , V_10 -> V_23 -> V_24 ) ;
F_61 ( V_2 , V_90 ) ;
F_61 ( V_2 , V_10 ) ;
}
}
static int F_119 ( struct V_119 * V_120 )
{
struct V_17 * V_17 = F_6 ( & V_120 -> V_2 ) ;
F_118 ( V_17 , & V_17 -> V_163 ) ;
F_118 ( V_17 , & V_17 -> V_164 ) ;
F_118 ( V_17 , & V_17 -> V_165 ) ;
F_118 ( V_17 , & V_17 -> V_166 ) ;
if ( V_17 -> V_19 )
F_117 ( & V_120 -> V_2 , V_17 -> V_19 ) ;
F_61 ( & V_120 -> V_2 , V_17 ) ;
return 0 ;
}
