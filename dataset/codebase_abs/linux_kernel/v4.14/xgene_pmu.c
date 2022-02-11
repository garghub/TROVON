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
static inline void F_16 ( struct V_17 * V_17 )
{
F_14 ( V_22 , V_17 -> V_19 + V_20 ) ;
}
static inline void F_17 ( struct V_17 * V_17 )
{
F_14 ( V_23 ,
V_17 -> V_19 + V_20 ) ;
}
static inline T_2 F_18 ( struct V_9 * V_10 ,
int V_24 )
{
return F_19 ( V_10 -> V_25 -> V_26 + V_27 + ( 4 * V_24 ) ) ;
}
static inline T_2 F_20 ( struct V_9 * V_10 ,
int V_24 )
{
T_3 V_28 , V_29 ;
do {
V_29 = F_18 ( V_10 , 2 * V_24 + 1 ) ;
V_28 = F_18 ( V_10 , 2 * V_24 ) ;
} while ( V_29 != F_18 ( V_10 , 2 * V_24 + 1 ) );
return ( ( ( T_2 ) V_29 << 32 ) | V_28 ) ;
}
static inline void
F_21 ( struct V_9 * V_10 , int V_24 , T_2 V_30 )
{
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_27 + ( 4 * V_24 ) ) ;
}
static inline void
F_22 ( struct V_9 * V_10 , int V_24 , T_2 V_30 )
{
T_3 V_31 , V_32 ;
V_32 = F_23 ( V_30 ) ;
V_31 = F_24 ( V_30 ) ;
F_21 ( V_10 , 2 * V_24 , V_31 ) ;
F_21 ( V_10 , 2 * V_24 + 1 , V_32 ) ;
}
static inline void
F_25 ( struct V_9 * V_10 , int V_24 , T_3 V_30 )
{
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_33 + ( 4 * V_24 ) ) ;
}
static inline void
F_26 ( struct V_9 * V_10 , T_3 V_30 )
{
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_34 ) ;
}
static inline void
F_27 ( struct V_9 * V_10 , T_3 V_30 ) { }
static inline void
F_28 ( struct V_9 * V_10 , T_3 V_30 )
{
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_35 ) ;
}
static inline void
F_29 ( struct V_9 * V_10 , T_3 V_30 ) { }
static inline void
F_30 ( struct V_9 * V_10 , int V_24 )
{
T_3 V_30 ;
V_30 = F_19 ( V_10 -> V_25 -> V_26 + V_36 ) ;
V_30 |= 1 << V_24 ;
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_36 ) ;
}
static inline void
F_31 ( struct V_9 * V_10 , int V_24 )
{
T_3 V_30 ;
V_30 = F_19 ( V_10 -> V_25 -> V_26 + V_37 ) ;
V_30 |= 1 << V_24 ;
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_37 ) ;
}
static inline void
F_32 ( struct V_9 * V_10 , int V_24 )
{
T_3 V_30 ;
V_30 = F_19 ( V_10 -> V_25 -> V_26 + V_38 ) ;
V_30 |= 1 << V_24 ;
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_38 ) ;
}
static inline void
F_33 ( struct V_9 * V_10 , int V_24 )
{
T_3 V_30 ;
V_30 = F_19 ( V_10 -> V_25 -> V_26 + V_39 ) ;
V_30 |= 1 << V_24 ;
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_39 ) ;
}
static inline void F_34 ( struct V_9 * V_10 )
{
T_3 V_30 ;
V_30 = F_19 ( V_10 -> V_25 -> V_26 + V_40 ) ;
V_30 |= V_41 ;
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_40 ) ;
}
static inline void F_35 ( struct V_9 * V_10 )
{
T_3 V_30 ;
V_30 = F_19 ( V_10 -> V_25 -> V_26 + V_40 ) ;
V_30 |= V_42 ;
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_40 ) ;
}
static inline void F_36 ( struct V_9 * V_10 )
{
T_3 V_30 ;
V_30 = F_19 ( V_10 -> V_25 -> V_26 + V_40 ) ;
V_30 &= ~ V_42 ;
F_14 ( V_30 , V_10 -> V_25 -> V_26 + V_40 ) ;
}
static void F_37 ( struct V_43 * V_43 )
{
struct V_9 * V_10 = F_5 ( V_43 ) ;
struct V_17 * V_17 = V_10 -> V_11 ;
int V_44 = F_38 ( V_10 -> V_14 ,
V_10 -> V_15 ) ;
if ( ! V_44 )
return;
V_17 -> V_45 -> V_46 ( V_10 ) ;
}
static void F_39 ( struct V_43 * V_43 )
{
struct V_9 * V_10 = F_5 ( V_43 ) ;
struct V_17 * V_17 = V_10 -> V_11 ;
V_17 -> V_45 -> V_47 ( V_10 ) ;
}
static int F_40 ( struct V_48 * V_49 )
{
struct V_9 * V_10 = F_5 ( V_49 -> V_43 ) ;
struct V_50 * V_51 = & V_49 -> V_51 ;
struct V_48 * V_52 ;
if ( V_49 -> V_4 . type != V_49 -> V_43 -> type )
return - V_53 ;
if ( F_41 ( V_49 ) || V_49 -> V_54 & V_55 )
return - V_56 ;
if ( V_49 -> V_4 . V_57 || V_49 -> V_4 . V_58 ||
V_49 -> V_4 . V_59 || V_49 -> V_4 . V_60 )
return - V_56 ;
if ( V_49 -> V_12 < 0 )
return - V_56 ;
V_49 -> V_12 = F_42 ( & V_10 -> V_11 -> V_12 ) ;
V_51 -> V_61 = V_49 -> V_4 . V_61 ;
V_51 -> V_62 = V_49 -> V_4 . V_63 ;
if ( V_49 -> V_64 -> V_43 != V_49 -> V_43 &&
! F_43 ( V_49 -> V_64 ) )
return - V_56 ;
F_44 (sibling, &event->group_leader->sibling_list,
group_entry)
if ( V_52 -> V_43 != V_49 -> V_43 &&
! F_43 ( V_52 ) )
return - V_56 ;
return 0 ;
}
static void F_45 ( struct V_48 * V_49 )
{
struct V_9 * V_10 = F_5 ( V_49 -> V_43 ) ;
struct V_17 * V_17 = V_10 -> V_11 ;
V_17 -> V_45 -> V_65 ( V_10 , F_46 ( V_49 ) ,
F_47 ( V_49 ) ) ;
V_17 -> V_45 -> V_66 ( V_10 , ~ ( ( T_3 ) F_48 ( V_49 ) ) ) ;
if ( V_10 -> V_25 -> type == V_67 )
V_17 -> V_45 -> V_68 ( V_10 ,
~ ( ( T_3 ) F_49 ( V_49 ) ) ) ;
V_17 -> V_45 -> V_69 ( V_10 , F_46 ( V_49 ) ) ;
V_17 -> V_45 -> V_70 ( V_10 , F_46 ( V_49 ) ) ;
}
static void F_50 ( struct V_48 * V_49 )
{
struct V_9 * V_10 = F_5 ( V_49 -> V_43 ) ;
struct V_17 * V_17 = V_10 -> V_11 ;
V_17 -> V_45 -> V_71 ( V_10 , F_46 ( V_49 ) ) ;
V_17 -> V_45 -> V_72 ( V_10 , F_46 ( V_49 ) ) ;
}
static void F_51 ( struct V_48 * V_49 )
{
struct V_9 * V_10 = F_5 ( V_49 -> V_43 ) ;
struct V_17 * V_17 = V_10 -> V_11 ;
struct V_50 * V_51 = & V_49 -> V_51 ;
T_2 V_30 = 1ULL << 31 ;
F_52 ( & V_51 -> V_73 , V_30 ) ;
V_17 -> V_45 -> V_74 ( V_10 , V_51 -> V_24 , V_30 ) ;
}
static void F_53 ( struct V_48 * V_49 )
{
struct V_9 * V_10 = F_5 ( V_49 -> V_43 ) ;
struct V_17 * V_17 = V_10 -> V_11 ;
struct V_50 * V_51 = & V_49 -> V_51 ;
T_2 V_75 , V_76 , V_77 ;
V_78:
V_76 = F_54 ( & V_51 -> V_73 ) ;
V_77 = V_17 -> V_45 -> V_79 ( V_10 , F_46 ( V_49 ) ) ;
if ( F_55 ( & V_51 -> V_73 , V_76 ,
V_77 ) != V_76 )
goto V_78;
V_75 = ( V_77 - V_76 ) & V_10 -> V_80 ;
F_56 ( V_75 , & V_49 -> V_81 ) ;
}
static void F_57 ( struct V_48 * V_49 )
{
F_53 ( V_49 ) ;
}
static void F_58 ( struct V_48 * V_49 , int V_82 )
{
struct V_9 * V_10 = F_5 ( V_49 -> V_43 ) ;
struct V_17 * V_17 = V_10 -> V_11 ;
struct V_50 * V_51 = & V_49 -> V_51 ;
if ( F_59 ( ! ( V_51 -> V_83 & V_84 ) ) )
return;
F_59 ( ! ( V_51 -> V_83 & V_85 ) ) ;
V_51 -> V_83 = 0 ;
F_51 ( V_49 ) ;
if ( V_82 & V_86 ) {
T_2 V_76 = F_54 ( & V_51 -> V_73 ) ;
V_17 -> V_45 -> V_74 ( V_10 , F_46 ( V_49 ) ,
V_76 ) ;
}
F_45 ( V_49 ) ;
F_60 ( V_49 ) ;
}
static void F_61 ( struct V_48 * V_49 , int V_82 )
{
struct V_50 * V_51 = & V_49 -> V_51 ;
T_2 V_61 ;
if ( V_51 -> V_83 & V_85 )
return;
F_50 ( V_49 ) ;
F_59 ( V_51 -> V_83 & V_84 ) ;
V_51 -> V_83 |= V_84 ;
if ( V_51 -> V_83 & V_85 )
return;
V_61 = V_51 -> V_61 ;
F_57 ( V_49 ) ;
V_51 -> V_83 |= V_85 ;
}
static int F_62 ( struct V_48 * V_49 , int V_82 )
{
struct V_9 * V_10 = F_5 ( V_49 -> V_43 ) ;
struct V_50 * V_51 = & V_49 -> V_51 ;
V_51 -> V_83 = V_85 | V_84 ;
V_51 -> V_24 = F_8 ( V_10 ) ;
if ( V_51 -> V_24 < 0 )
return - V_87 ;
V_10 -> V_88 [ V_51 -> V_24 ] = V_49 ;
if ( V_82 & V_89 )
F_58 ( V_49 , V_86 ) ;
return 0 ;
}
static void F_63 ( struct V_48 * V_49 , int V_82 )
{
struct V_9 * V_10 = F_5 ( V_49 -> V_43 ) ;
struct V_50 * V_51 = & V_49 -> V_51 ;
F_61 ( V_49 , V_90 ) ;
F_11 ( V_10 , F_46 ( V_49 ) ) ;
F_60 ( V_49 ) ;
V_10 -> V_88 [ V_51 -> V_24 ] = NULL ;
}
static int F_64 ( struct V_9 * V_10 , char * V_91 )
{
struct V_17 * V_17 ;
if ( V_10 -> V_11 -> V_92 == V_93 )
V_10 -> V_80 = V_94 ;
else
V_10 -> V_80 = V_95 ;
V_17 = V_10 -> V_11 ;
if ( V_17 -> V_92 == V_96 )
V_10 -> V_15 = 1 ;
else
V_10 -> V_15 = V_97 ;
V_10 -> V_43 = (struct V_43 ) {
. V_98 = V_10 -> V_98 ,
. V_99 = V_100 ,
. V_101 = F_37 ,
. V_102 = F_39 ,
. V_103 = F_40 ,
. V_104 = F_62 ,
. V_105 = F_63 ,
. V_106 = F_58 ,
. V_107 = F_61 ,
. V_108 = F_57 ,
} ;
V_17 -> V_45 -> V_47 ( V_10 ) ;
V_17 -> V_45 -> V_109 ( V_10 ) ;
return F_65 ( & V_10 -> V_43 , V_91 , - 1 ) ;
}
static int
F_66 ( struct V_17 * V_17 , struct V_110 * V_111 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_9 * V_43 ;
V_43 = F_67 ( V_2 , sizeof( * V_43 ) , V_112 ) ;
if ( ! V_43 )
return - V_113 ;
V_43 -> V_11 = V_17 ;
V_43 -> V_25 = & V_111 -> V_25 ;
V_111 -> V_10 = V_43 ;
switch ( V_43 -> V_25 -> type ) {
case V_114 :
if ( ! ( V_17 -> V_115 & V_43 -> V_25 -> V_116 ) )
return - V_117 ;
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_118 ;
else
V_43 -> V_98 = V_119 ;
break;
case V_67 :
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_120 ;
else
V_43 -> V_98 = V_121 ;
break;
case V_122 :
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_123 ;
break;
case V_124 :
if ( ! ( V_17 -> V_125 & V_43 -> V_25 -> V_116 ) )
return - V_117 ;
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_126 ;
else
V_43 -> V_98 = V_127 ;
break;
case V_128 :
if ( ! ( V_17 -> V_129 & V_43 -> V_25 -> V_116 ) )
return - V_117 ;
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_130 ;
else
V_43 -> V_98 = V_131 ;
break;
default:
return - V_56 ;
}
if ( F_64 ( V_43 , V_111 -> V_91 ) ) {
F_68 ( V_2 , L_3 , V_111 -> V_91 ) ;
return - V_117 ;
}
F_69 ( V_2 , L_4 , V_111 -> V_91 ) ;
return 0 ;
}
static void F_70 ( int V_132 , struct V_9 * V_10 )
{
struct V_17 * V_17 = V_10 -> V_11 ;
void T_4 * V_26 = V_10 -> V_25 -> V_26 ;
T_3 V_133 ;
int V_24 ;
V_17 -> V_45 -> V_47 ( V_10 ) ;
if ( V_17 -> V_92 == V_93 )
V_133 = F_19 ( V_26 + V_134 ) & V_135 ;
else
V_133 = F_19 ( V_26 + V_136 ) & V_135 ;
if ( ! V_133 )
goto V_137;
if ( V_17 -> V_92 == V_96 )
F_14 ( 0x0 , V_26 + V_136 ) ;
else if ( V_17 -> V_92 == V_138 )
F_14 ( V_133 , V_26 + V_136 ) ;
else
F_14 ( V_133 , V_26 + V_139 ) ;
for ( V_24 = 0 ; V_24 < V_97 ; V_24 ++ ) {
struct V_48 * V_49 = V_10 -> V_88 [ V_24 ] ;
int V_140 = V_133 & F_71 ( V_24 ) ;
if ( ! V_49 || ! V_140 )
continue;
F_53 ( V_49 ) ;
F_51 ( V_49 ) ;
}
V_137:
V_17 -> V_45 -> V_46 ( V_10 ) ;
}
static T_5 F_72 ( int V_132 , void * V_141 )
{
T_3 V_142 , V_143 , V_144 , V_145 ;
struct V_110 * V_111 ;
struct V_17 * V_17 = V_141 ;
unsigned long V_82 ;
T_3 V_30 ;
F_73 ( & V_17 -> V_146 , V_82 ) ;
V_30 = F_19 ( V_17 -> V_19 + V_147 ) ;
if ( V_17 -> V_92 == V_93 ) {
V_142 = V_148 ;
V_143 = V_149 ;
V_144 = V_150 ;
V_145 = V_151 ;
} else {
V_142 = V_152 ;
V_143 = V_153 ;
V_144 = V_154 ;
V_145 = V_155 ;
}
if ( V_30 & V_142 ) {
F_44 (ctx, &xgene_pmu->mcpmus, next) {
F_70 ( V_132 , V_111 -> V_10 ) ;
}
}
if ( V_30 & V_143 ) {
F_44 (ctx, &xgene_pmu->mcbpmus, next) {
F_70 ( V_132 , V_111 -> V_10 ) ;
}
}
if ( V_30 & V_144 ) {
F_44 (ctx, &xgene_pmu->l3cpmus, next) {
F_70 ( V_132 , V_111 -> V_10 ) ;
}
}
if ( V_30 & V_145 ) {
F_44 (ctx, &xgene_pmu->iobpmus, next) {
F_70 ( V_132 , V_111 -> V_10 ) ;
}
}
F_74 ( & V_17 -> V_146 , V_82 ) ;
return V_156 ;
}
static int F_75 ( struct V_17 * V_17 ,
struct V_157 * V_158 )
{
void T_4 * V_159 , * V_160 , * V_161 ;
struct V_162 * V_163 ;
unsigned int V_164 ;
V_163 = F_76 ( V_158 , V_165 , 1 ) ;
V_159 = F_77 ( & V_158 -> V_2 , V_163 ) ;
if ( F_78 ( V_159 ) ) {
F_68 ( & V_158 -> V_2 , L_5 ) ;
return F_79 ( V_159 ) ;
}
V_163 = F_76 ( V_158 , V_165 , 2 ) ;
V_160 = F_77 ( & V_158 -> V_2 , V_163 ) ;
if ( F_78 ( V_160 ) ) {
F_68 ( & V_158 -> V_2 , L_6 ) ;
return F_79 ( V_160 ) ;
}
V_163 = F_76 ( V_158 , V_165 , 3 ) ;
V_161 = F_77 ( & V_158 -> V_2 , V_163 ) ;
if ( F_78 ( V_161 ) ) {
F_68 ( & V_158 -> V_2 , L_7 ) ;
return F_79 ( V_161 ) ;
}
V_17 -> V_115 = 0x1 ;
V_164 = F_19 ( V_159 + V_166 ) ;
if ( V_164 & V_167 ) {
V_17 -> V_125 = 0x3 ;
V_164 = F_19 ( V_161 + V_166 ) ;
V_17 -> V_129 =
( V_164 & V_168 ) ? 0xF : 0x5 ;
} else {
V_17 -> V_125 = 0x1 ;
V_164 = F_19 ( V_160 + V_166 ) ;
V_17 -> V_129 =
( V_164 & V_168 ) ? 0x3 : 0x1 ;
}
return 0 ;
}
static int F_80 ( struct V_17 * V_17 ,
struct V_157 * V_158 )
{
void T_4 * V_159 ;
struct V_162 * V_163 ;
unsigned int V_164 ;
T_3 V_169 ;
T_3 V_170 ;
V_163 = F_76 ( V_158 , V_165 , 1 ) ;
V_159 = F_77 ( & V_158 -> V_2 , V_163 ) ;
if ( F_78 ( V_159 ) ) {
F_68 ( & V_158 -> V_2 , L_5 ) ;
return F_79 ( V_159 ) ;
}
V_164 = F_19 ( V_159 + V_166 ) ;
V_169 = F_81 ( V_164 ) ;
V_170 = F_82 ( V_164 ) ;
if ( V_164 & V_167 ) {
V_17 -> V_125 = 0x3 ;
V_17 -> V_115 = 0xFF ;
if ( ( V_169 == 0x2 ) && ( V_170 == 0x2 ) )
V_17 -> V_129 = 0xFF ;
else if ( ( V_169 == 0x1 ) && ( V_170 == 0x1 ) )
V_17 -> V_129 = 0x33 ;
else
V_17 -> V_129 = 0x11 ;
} else {
V_17 -> V_125 = 0x1 ;
V_17 -> V_115 = 0x0F ;
if ( V_169 == 0x2 )
V_17 -> V_129 = 0x0F ;
else if ( V_169 == 0x1 )
V_17 -> V_129 = 0x03 ;
else
V_17 -> V_129 = 0x01 ;
}
return 0 ;
}
static int F_83 ( struct V_17 * V_17 ,
struct V_157 * V_158 )
{
struct V_171 * V_172 , * V_173 , * V_174 ;
struct V_175 * V_176 = V_158 -> V_2 . V_177 ;
unsigned int V_164 ;
V_172 = F_84 ( V_176 , L_8 ) ;
if ( F_78 ( V_172 ) ) {
F_68 ( & V_158 -> V_2 , L_9 ) ;
return F_79 ( V_172 ) ;
}
V_173 = F_84 ( V_176 , L_10 ) ;
if ( F_78 ( V_173 ) ) {
F_68 ( & V_158 -> V_2 , L_11 ) ;
return F_79 ( V_173 ) ;
}
V_174 = F_84 ( V_176 , L_12 ) ;
if ( F_78 ( V_174 ) ) {
F_68 ( & V_158 -> V_2 , L_13 ) ;
return F_79 ( V_174 ) ;
}
V_17 -> V_115 = 0x1 ;
if ( F_85 ( V_172 , V_166 , & V_164 ) )
return - V_56 ;
if ( V_164 & V_167 ) {
V_17 -> V_125 = 0x3 ;
if ( F_85 ( V_174 , V_178 , & V_164 ) )
return 0 ;
V_17 -> V_129 =
( V_164 & V_168 ) ? 0xF : 0x5 ;
} else {
V_17 -> V_125 = 0x1 ;
if ( F_85 ( V_173 , V_178 , & V_164 ) )
return 0 ;
V_17 -> V_129 =
( V_164 & V_168 ) ? 0x3 : 0x1 ;
}
return 0 ;
}
static int F_86 ( struct V_17 * V_17 ,
struct V_157 * V_158 )
{
if ( F_87 ( & V_158 -> V_2 ) ) {
if ( V_17 -> V_92 == V_93 )
return F_80 ( V_17 ,
V_158 ) ;
else
return F_75 ( V_17 ,
V_158 ) ;
}
return F_83 ( V_17 , V_158 ) ;
}
static char * F_88 ( struct V_1 * V_2 , T_3 type , int V_179 )
{
switch ( type ) {
case V_114 :
return F_89 ( V_2 , V_112 , L_14 , V_179 ) ;
case V_67 :
return F_89 ( V_2 , V_112 , L_15 , V_179 ) ;
case V_122 :
return F_89 ( V_2 , V_112 , L_16 , V_179 ) ;
case V_124 :
return F_89 ( V_2 , V_112 , L_17 , V_179 ) ;
case V_128 :
return F_89 ( V_2 , V_112 , L_18 , V_179 ) ;
default:
return F_89 ( V_2 , V_112 , L_19 ) ;
}
}
static int F_90 ( struct V_180 * V_181 , void * V_182 )
{
struct V_162 * V_163 = V_182 ;
if ( V_181 -> type == V_183 )
F_91 ( V_181 , V_163 ) ;
return 1 ;
}
static struct
V_110 * F_92 ( struct V_17 * V_17 ,
struct V_184 * V_185 , T_3 type )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_186 V_187 ;
struct V_110 * V_111 ;
const union V_188 * V_189 ;
struct V_190 * V_25 ;
void T_4 * V_191 ;
struct V_162 V_163 ;
int V_192 ;
int V_193 ;
V_111 = F_67 ( V_2 , sizeof( * V_111 ) , V_112 ) ;
if ( ! V_111 )
return NULL ;
F_93 ( & V_187 ) ;
V_193 = F_94 ( V_185 , & V_187 ,
F_90 , & V_163 ) ;
F_95 ( & V_187 ) ;
if ( V_193 < 0 ) {
F_68 ( V_2 , L_20 , type ) ;
return NULL ;
}
V_191 = F_77 ( V_2 , & V_163 ) ;
if ( F_78 ( V_191 ) ) {
F_68 ( V_2 , L_21 , type ) ;
return NULL ;
}
V_193 = F_96 ( V_185 , L_22 ,
V_194 , & V_189 ) ;
if ( V_193 < 0 )
V_192 = 0 ;
else
V_192 = ( int ) V_189 -> integer . V_195 ;
V_111 -> V_91 = F_88 ( V_2 , type , V_192 ) ;
if ( ! V_111 -> V_91 ) {
F_68 ( V_2 , L_23 , type ) ;
return NULL ;
}
V_25 = & V_111 -> V_25 ;
V_25 -> type = type ;
V_25 -> V_26 = V_191 ;
V_25 -> V_116 = 1 << V_192 ;
return V_111 ;
}
static const struct V_196 * F_97 (
const struct V_196 * V_197 ,
struct V_184 * V_185 )
{
const struct V_196 * V_198 = NULL ;
const struct V_196 * V_179 ;
for ( V_179 = V_197 ; V_179 -> V_179 [ 0 ] || V_179 -> V_199 ; V_179 ++ ) {
if ( ! F_98 ( V_185 , V_179 ) )
V_198 = V_179 ;
else if ( V_198 )
break;
}
return V_198 ;
}
static T_6 F_99 ( T_7 V_200 , T_3 V_201 ,
void * V_182 , void * * V_202 )
{
const struct V_196 * V_203 ;
struct V_17 * V_17 = V_182 ;
struct V_110 * V_111 ;
struct V_184 * V_185 ;
if ( F_100 ( V_200 , & V_185 ) )
return V_204 ;
if ( F_101 ( V_185 ) || ! V_185 -> V_205 . V_206 )
return V_204 ;
V_203 = F_97 ( V_207 , V_185 ) ;
if ( ! V_203 )
return V_204 ;
V_111 = F_92 ( V_17 , V_185 , ( T_3 ) V_203 -> V_208 ) ;
if ( ! V_111 )
return V_204 ;
if ( F_66 ( V_17 , V_111 ) ) {
F_102 ( V_17 -> V_2 , V_111 ) ;
return V_204 ;
}
switch ( V_111 -> V_25 . type ) {
case V_114 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_210 ) ;
break;
case V_67 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_211 ) ;
break;
case V_122 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_211 ) ;
break;
case V_124 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_212 ) ;
break;
case V_128 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_213 ) ;
break;
}
return V_204 ;
}
static int F_104 ( struct V_17 * V_17 ,
struct V_157 * V_158 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
T_7 V_200 ;
T_6 V_205 ;
V_200 = F_105 ( V_2 ) ;
if ( ! V_200 )
return - V_56 ;
V_205 = F_106 ( V_214 , V_200 , 1 ,
F_99 , NULL , V_17 , NULL ) ;
if ( F_107 ( V_205 ) ) {
F_68 ( V_2 , L_24 ) ;
return - V_117 ;
}
return 0 ;
}
static int F_104 ( struct V_17 * V_17 ,
struct V_157 * V_158 )
{
return 0 ;
}
static struct
V_110 * F_108 ( struct V_17 * V_17 ,
struct V_175 * V_176 , T_3 type )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_110 * V_111 ;
struct V_190 * V_25 ;
void T_4 * V_191 ;
struct V_162 V_163 ;
int V_192 ;
V_111 = F_67 ( V_2 , sizeof( * V_111 ) , V_112 ) ;
if ( ! V_111 )
return NULL ;
if ( F_109 ( V_176 , 0 , & V_163 ) < 0 ) {
F_68 ( V_2 , L_20 , type ) ;
return NULL ;
}
V_191 = F_77 ( V_2 , & V_163 ) ;
if ( F_78 ( V_191 ) ) {
F_68 ( V_2 , L_21 , type ) ;
return NULL ;
}
if ( F_110 ( V_176 , L_22 , & V_192 ) )
V_192 = 0 ;
V_111 -> V_91 = F_88 ( V_2 , type , V_192 ) ;
if ( ! V_111 -> V_91 ) {
F_68 ( V_2 , L_23 , type ) ;
return NULL ;
}
V_25 = & V_111 -> V_25 ;
V_25 -> type = type ;
V_25 -> V_26 = V_191 ;
V_25 -> V_116 = 1 << V_192 ;
return V_111 ;
}
static int F_111 ( struct V_17 * V_17 ,
struct V_157 * V_158 )
{
struct V_110 * V_111 ;
struct V_175 * V_176 ;
F_112 (pdev->dev.of_node, np) {
if ( ! F_113 ( V_176 ) )
continue;
if ( F_114 ( V_176 , L_25 ) )
V_111 = F_108 ( V_17 , V_176 , V_114 ) ;
else if ( F_114 ( V_176 , L_26 ) )
V_111 = F_108 ( V_17 , V_176 , V_67 ) ;
else if ( F_114 ( V_176 , L_27 ) )
V_111 = F_108 ( V_17 , V_176 , V_124 ) ;
else if ( F_114 ( V_176 , L_28 ) )
V_111 = F_108 ( V_17 , V_176 , V_128 ) ;
else
V_111 = NULL ;
if ( ! V_111 )
continue;
if ( F_66 ( V_17 , V_111 ) ) {
F_102 ( V_17 -> V_2 , V_111 ) ;
continue;
}
switch ( V_111 -> V_25 . type ) {
case V_114 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_210 ) ;
break;
case V_67 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_211 ) ;
break;
case V_122 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_211 ) ;
break;
case V_124 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_212 ) ;
break;
case V_128 :
F_103 ( & V_111 -> V_209 , & V_17 -> V_213 ) ;
break;
}
}
return 0 ;
}
static int F_115 ( struct V_17 * V_17 ,
struct V_157 * V_158 )
{
if ( F_87 ( & V_158 -> V_2 ) )
return F_104 ( V_17 , V_158 ) ;
return F_111 ( V_17 , V_158 ) ;
}
static int F_116 ( struct V_157 * V_158 )
{
const struct V_215 * V_216 ;
const struct V_217 * V_218 ;
struct V_17 * V_17 ;
struct V_162 * V_163 ;
int V_132 , V_193 ;
int V_92 ;
V_17 = F_67 ( & V_158 -> V_2 , sizeof( * V_17 ) , V_112 ) ;
if ( ! V_17 )
return - V_113 ;
V_17 -> V_2 = & V_158 -> V_2 ;
F_117 ( V_158 , V_17 ) ;
V_92 = - V_56 ;
V_218 = F_118 ( V_219 , & V_158 -> V_2 ) ;
if ( V_218 ) {
V_216 = ( const struct V_215 * ) V_218 -> V_182 ;
V_92 = V_216 -> V_179 ;
}
#ifdef F_119
if ( F_120 ( & V_158 -> V_2 ) ) {
const struct V_196 * V_203 ;
V_203 = F_121 ( V_220 , & V_158 -> V_2 ) ;
if ( V_203 )
V_92 = ( int ) V_203 -> V_208 ;
}
#endif
if ( V_92 < 0 )
return - V_117 ;
if ( V_92 == V_93 )
V_17 -> V_45 = & V_221 ;
else
V_17 -> V_45 = & V_222 ;
F_93 ( & V_17 -> V_210 ) ;
F_93 ( & V_17 -> V_211 ) ;
F_93 ( & V_17 -> V_212 ) ;
F_93 ( & V_17 -> V_213 ) ;
V_17 -> V_92 = V_92 ;
F_69 ( & V_158 -> V_2 , L_29 , V_17 -> V_92 ) ;
V_163 = F_76 ( V_158 , V_165 , 0 ) ;
V_17 -> V_19 = F_77 ( & V_158 -> V_2 , V_163 ) ;
if ( F_78 ( V_17 -> V_19 ) ) {
F_68 ( & V_158 -> V_2 , L_30 ) ;
return F_79 ( V_17 -> V_19 ) ;
}
V_132 = F_122 ( V_158 , 0 ) ;
if ( V_132 < 0 ) {
F_68 ( & V_158 -> V_2 , L_31 ) ;
return - V_56 ;
}
V_193 = F_123 ( & V_158 -> V_2 , V_132 , F_72 ,
V_223 | V_224 ,
F_124 ( & V_158 -> V_2 ) , V_17 ) ;
if ( V_193 ) {
F_68 ( & V_158 -> V_2 , L_32 , V_132 ) ;
return V_193 ;
}
F_125 ( & V_17 -> V_146 ) ;
V_193 = F_86 ( V_17 , V_158 ) ;
if ( V_193 ) {
F_126 ( & V_158 -> V_2 , L_33 ) ;
V_17 -> V_125 = 0x1 ;
V_17 -> V_129 = 0x1 ;
}
F_127 ( F_128 () , & V_17 -> V_12 ) ;
V_193 = F_129 ( V_132 , & V_17 -> V_12 ) ;
if ( V_193 ) {
F_68 ( & V_158 -> V_2 , L_34 ) ;
return V_193 ;
}
V_193 = F_115 ( V_17 , V_158 ) ;
if ( V_193 ) {
F_68 ( & V_158 -> V_2 , L_35 ) ;
return V_193 ;
}
V_17 -> V_45 -> V_225 ( V_17 ) ;
return 0 ;
}
static void
F_130 ( struct V_17 * V_17 , struct V_186 * V_226 )
{
struct V_110 * V_111 ;
F_44 (ctx, pmus, next) {
F_131 ( & V_111 -> V_10 -> V_43 ) ;
}
}
static int F_132 ( struct V_157 * V_158 )
{
struct V_17 * V_17 = F_6 ( & V_158 -> V_2 ) ;
F_130 ( V_17 , & V_17 -> V_210 ) ;
F_130 ( V_17 , & V_17 -> V_211 ) ;
F_130 ( V_17 , & V_17 -> V_212 ) ;
F_130 ( V_17 , & V_17 -> V_213 ) ;
return 0 ;
}
