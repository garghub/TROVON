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
int V_112 ;
V_43 = F_67 ( V_2 , sizeof( * V_43 ) , V_113 ) ;
if ( ! V_43 )
return - V_114 ;
V_43 -> V_11 = V_17 ;
V_43 -> V_25 = & V_111 -> V_25 ;
V_111 -> V_10 = V_43 ;
switch ( V_43 -> V_25 -> type ) {
case V_115 :
if ( ! ( V_17 -> V_116 & V_43 -> V_25 -> V_117 ) )
goto V_118;
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_119 ;
else
V_43 -> V_98 = V_120 ;
break;
case V_67 :
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_121 ;
else
V_43 -> V_98 = V_122 ;
break;
case V_123 :
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_124 ;
break;
case V_125 :
if ( ! ( V_17 -> V_126 & V_43 -> V_25 -> V_117 ) )
goto V_118;
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_127 ;
else
V_43 -> V_98 = V_128 ;
break;
case V_129 :
if ( ! ( V_17 -> V_130 & V_43 -> V_25 -> V_117 ) )
goto V_118;
if ( V_17 -> V_92 == V_93 )
V_43 -> V_98 = V_131 ;
else
V_43 -> V_98 = V_132 ;
break;
default:
return - V_56 ;
}
V_112 = F_64 ( V_43 , V_111 -> V_91 ) ;
if ( V_112 ) {
V_118 ( V_2 , L_3 , V_111 -> V_91 ) ;
goto V_118;
}
F_68 ( V_2 , L_4 , V_111 -> V_91 ) ;
return V_112 ;
V_118:
F_69 ( V_2 , V_43 ) ;
return - V_133 ;
}
static void F_70 ( int V_134 , struct V_9 * V_10 )
{
struct V_17 * V_17 = V_10 -> V_11 ;
void T_4 * V_26 = V_10 -> V_25 -> V_26 ;
T_3 V_135 ;
int V_24 ;
V_17 -> V_45 -> V_47 ( V_10 ) ;
if ( V_17 -> V_92 == V_93 )
V_135 = F_19 ( V_26 + V_136 ) & V_137 ;
else
V_135 = F_19 ( V_26 + V_138 ) & V_137 ;
if ( ! V_135 )
goto V_139;
if ( V_17 -> V_92 == V_96 )
F_14 ( 0x0 , V_26 + V_138 ) ;
else if ( V_17 -> V_92 == V_140 )
F_14 ( V_135 , V_26 + V_138 ) ;
else
F_14 ( V_135 , V_26 + V_141 ) ;
for ( V_24 = 0 ; V_24 < V_97 ; V_24 ++ ) {
struct V_48 * V_49 = V_10 -> V_88 [ V_24 ] ;
int V_142 = V_135 & F_71 ( V_24 ) ;
if ( ! V_49 || ! V_142 )
continue;
F_53 ( V_49 ) ;
F_51 ( V_49 ) ;
}
V_139:
V_17 -> V_45 -> V_46 ( V_10 ) ;
}
static T_5 F_72 ( int V_134 , void * V_143 )
{
T_3 V_144 , V_145 , V_146 , V_147 ;
struct V_110 * V_111 ;
struct V_17 * V_17 = V_143 ;
unsigned long V_82 ;
T_3 V_30 ;
F_73 ( & V_17 -> V_148 , V_82 ) ;
V_30 = F_19 ( V_17 -> V_19 + V_149 ) ;
if ( V_17 -> V_92 == V_93 ) {
V_144 = V_150 ;
V_145 = V_151 ;
V_146 = V_152 ;
V_147 = V_153 ;
} else {
V_144 = V_154 ;
V_145 = V_155 ;
V_146 = V_156 ;
V_147 = V_157 ;
}
if ( V_30 & V_144 ) {
F_44 (ctx, &xgene_pmu->mcpmus, next) {
F_70 ( V_134 , V_111 -> V_10 ) ;
}
}
if ( V_30 & V_145 ) {
F_44 (ctx, &xgene_pmu->mcbpmus, next) {
F_70 ( V_134 , V_111 -> V_10 ) ;
}
}
if ( V_30 & V_146 ) {
F_44 (ctx, &xgene_pmu->l3cpmus, next) {
F_70 ( V_134 , V_111 -> V_10 ) ;
}
}
if ( V_30 & V_147 ) {
F_44 (ctx, &xgene_pmu->iobpmus, next) {
F_70 ( V_134 , V_111 -> V_10 ) ;
}
}
F_74 ( & V_17 -> V_148 , V_82 ) ;
return V_158 ;
}
static int F_75 ( struct V_17 * V_17 ,
struct V_159 * V_160 )
{
void T_4 * V_161 , * V_162 , * V_163 ;
struct V_164 * V_165 ;
unsigned int V_166 ;
V_165 = F_76 ( V_160 , V_167 , 1 ) ;
V_161 = F_77 ( & V_160 -> V_2 , V_165 ) ;
if ( F_78 ( V_161 ) ) {
V_118 ( & V_160 -> V_2 , L_5 ) ;
return F_79 ( V_161 ) ;
}
V_165 = F_76 ( V_160 , V_167 , 2 ) ;
V_162 = F_77 ( & V_160 -> V_2 , V_165 ) ;
if ( F_78 ( V_162 ) ) {
V_118 ( & V_160 -> V_2 , L_6 ) ;
return F_79 ( V_162 ) ;
}
V_165 = F_76 ( V_160 , V_167 , 3 ) ;
V_163 = F_77 ( & V_160 -> V_2 , V_165 ) ;
if ( F_78 ( V_163 ) ) {
V_118 ( & V_160 -> V_2 , L_7 ) ;
return F_79 ( V_163 ) ;
}
V_17 -> V_116 = 0x1 ;
V_166 = F_19 ( V_161 + V_168 ) ;
if ( V_166 & V_169 ) {
V_17 -> V_126 = 0x3 ;
V_166 = F_19 ( V_163 + V_168 ) ;
V_17 -> V_130 =
( V_166 & V_170 ) ? 0xF : 0x5 ;
} else {
V_17 -> V_126 = 0x1 ;
V_166 = F_19 ( V_162 + V_168 ) ;
V_17 -> V_130 =
( V_166 & V_170 ) ? 0x3 : 0x1 ;
}
return 0 ;
}
static int F_80 ( struct V_17 * V_17 ,
struct V_159 * V_160 )
{
void T_4 * V_161 ;
struct V_164 * V_165 ;
unsigned int V_166 ;
T_3 V_171 ;
T_3 V_172 ;
V_165 = F_76 ( V_160 , V_167 , 1 ) ;
V_161 = F_77 ( & V_160 -> V_2 , V_165 ) ;
if ( F_78 ( V_161 ) ) {
V_118 ( & V_160 -> V_2 , L_5 ) ;
return F_79 ( V_161 ) ;
}
V_166 = F_19 ( V_161 + V_168 ) ;
V_171 = F_81 ( V_166 ) ;
V_172 = F_82 ( V_166 ) ;
if ( V_166 & V_169 ) {
V_17 -> V_126 = 0x3 ;
V_17 -> V_116 = 0xFF ;
if ( ( V_171 == 0x2 ) && ( V_172 == 0x2 ) )
V_17 -> V_130 = 0xFF ;
else if ( ( V_171 == 0x1 ) && ( V_172 == 0x1 ) )
V_17 -> V_130 = 0x33 ;
else
V_17 -> V_130 = 0x11 ;
} else {
V_17 -> V_126 = 0x1 ;
V_17 -> V_116 = 0x0F ;
if ( V_171 == 0x2 )
V_17 -> V_130 = 0x0F ;
else if ( V_171 == 0x1 )
V_17 -> V_130 = 0x03 ;
else
V_17 -> V_130 = 0x01 ;
}
return 0 ;
}
static int F_83 ( struct V_17 * V_17 ,
struct V_159 * V_160 )
{
struct V_173 * V_174 , * V_175 , * V_176 ;
struct V_177 * V_178 = V_160 -> V_2 . V_179 ;
unsigned int V_166 ;
V_174 = F_84 ( V_178 , L_8 ) ;
if ( F_78 ( V_174 ) ) {
V_118 ( & V_160 -> V_2 , L_9 ) ;
return F_79 ( V_174 ) ;
}
V_175 = F_84 ( V_178 , L_10 ) ;
if ( F_78 ( V_175 ) ) {
V_118 ( & V_160 -> V_2 , L_11 ) ;
return F_79 ( V_175 ) ;
}
V_176 = F_84 ( V_178 , L_12 ) ;
if ( F_78 ( V_176 ) ) {
V_118 ( & V_160 -> V_2 , L_13 ) ;
return F_79 ( V_176 ) ;
}
V_17 -> V_116 = 0x1 ;
if ( F_85 ( V_174 , V_168 , & V_166 ) )
return - V_56 ;
if ( V_166 & V_169 ) {
V_17 -> V_126 = 0x3 ;
if ( F_85 ( V_176 , V_180 , & V_166 ) )
return 0 ;
V_17 -> V_130 =
( V_166 & V_170 ) ? 0xF : 0x5 ;
} else {
V_17 -> V_126 = 0x1 ;
if ( F_85 ( V_175 , V_180 , & V_166 ) )
return 0 ;
V_17 -> V_130 =
( V_166 & V_170 ) ? 0x3 : 0x1 ;
}
return 0 ;
}
static int F_86 ( struct V_17 * V_17 ,
struct V_159 * V_160 )
{
if ( F_87 ( & V_160 -> V_2 ) ) {
if ( V_17 -> V_92 == V_93 )
return F_80 ( V_17 ,
V_160 ) ;
else
return F_75 ( V_17 ,
V_160 ) ;
}
return F_83 ( V_17 , V_160 ) ;
}
static char * F_88 ( struct V_1 * V_2 , T_3 type , int V_181 )
{
switch ( type ) {
case V_115 :
return F_89 ( V_2 , V_113 , L_14 , V_181 ) ;
case V_67 :
return F_89 ( V_2 , V_113 , L_15 , V_181 ) ;
case V_123 :
return F_89 ( V_2 , V_113 , L_16 , V_181 ) ;
case V_125 :
return F_89 ( V_2 , V_113 , L_17 , V_181 ) ;
case V_129 :
return F_89 ( V_2 , V_113 , L_18 , V_181 ) ;
default:
return F_89 ( V_2 , V_113 , L_19 ) ;
}
}
static int F_90 ( struct V_182 * V_183 , void * V_184 )
{
struct V_164 * V_165 = V_184 ;
if ( V_183 -> type == V_185 )
F_91 ( V_183 , V_165 ) ;
return 1 ;
}
static struct
V_110 * F_92 ( struct V_17 * V_17 ,
struct V_186 * V_187 , T_3 type )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_188 V_189 ;
struct V_110 * V_111 ;
const union V_190 * V_191 ;
struct V_192 * V_25 ;
void T_4 * V_193 ;
struct V_164 V_165 ;
int V_194 ;
int V_112 ;
V_111 = F_67 ( V_2 , sizeof( * V_111 ) , V_113 ) ;
if ( ! V_111 )
return NULL ;
F_93 ( & V_189 ) ;
V_112 = F_94 ( V_187 , & V_189 ,
F_90 , & V_165 ) ;
F_95 ( & V_189 ) ;
if ( V_112 < 0 ) {
V_118 ( V_2 , L_20 , type ) ;
goto V_195;
}
V_193 = F_77 ( V_2 , & V_165 ) ;
if ( F_78 ( V_193 ) ) {
V_118 ( V_2 , L_21 , type ) ;
goto V_195;
}
V_112 = F_96 ( V_187 , L_22 ,
V_196 , & V_191 ) ;
if ( V_112 < 0 )
V_194 = 0 ;
else
V_194 = ( int ) V_191 -> integer . V_197 ;
V_111 -> V_91 = F_88 ( V_2 , type , V_194 ) ;
if ( ! V_111 -> V_91 ) {
V_118 ( V_2 , L_23 , type ) ;
goto V_195;
}
V_25 = & V_111 -> V_25 ;
V_25 -> type = type ;
V_25 -> V_26 = V_193 ;
V_25 -> V_117 = 1 << V_194 ;
return V_111 ;
V_195:
F_69 ( V_2 , V_111 ) ;
return NULL ;
}
static const struct V_198 * F_97 (
const struct V_198 * V_199 ,
struct V_186 * V_187 )
{
const struct V_198 * V_200 = NULL ;
const struct V_198 * V_181 ;
for ( V_181 = V_199 ; V_181 -> V_181 [ 0 ] || V_181 -> V_201 ; V_181 ++ ) {
if ( ! F_98 ( V_187 , V_181 ) )
V_200 = V_181 ;
else if ( V_200 )
break;
}
return V_200 ;
}
static T_6 F_99 ( T_7 V_202 , T_3 V_203 ,
void * V_184 , void * * V_204 )
{
const struct V_198 * V_205 ;
struct V_17 * V_17 = V_184 ;
struct V_110 * V_111 ;
struct V_186 * V_187 ;
if ( F_100 ( V_202 , & V_187 ) )
return V_206 ;
if ( F_101 ( V_187 ) || ! V_187 -> V_207 . V_208 )
return V_206 ;
V_205 = F_97 ( V_209 , V_187 ) ;
if ( ! V_205 )
return V_206 ;
V_111 = F_92 ( V_17 , V_187 , ( T_3 ) V_205 -> V_210 ) ;
if ( ! V_111 )
return V_206 ;
if ( F_66 ( V_17 , V_111 ) ) {
F_69 ( V_17 -> V_2 , V_111 ) ;
return V_206 ;
}
switch ( V_111 -> V_25 . type ) {
case V_115 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_212 ) ;
break;
case V_67 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_213 ) ;
break;
case V_123 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_213 ) ;
break;
case V_125 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_214 ) ;
break;
case V_129 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_215 ) ;
break;
}
return V_206 ;
}
static int F_103 ( struct V_17 * V_17 ,
struct V_159 * V_160 )
{
struct V_1 * V_2 = V_17 -> V_2 ;
T_7 V_202 ;
T_6 V_207 ;
V_202 = F_104 ( V_2 ) ;
if ( ! V_202 )
return - V_56 ;
V_207 = F_105 ( V_216 , V_202 , 1 ,
F_99 , NULL , V_17 , NULL ) ;
if ( F_106 ( V_207 ) ) {
V_118 ( V_2 , L_24 ) ;
return - V_133 ;
}
return 0 ;
}
static int F_103 ( struct V_17 * V_17 ,
struct V_159 * V_160 )
{
return 0 ;
}
static struct
V_110 * F_107 ( struct V_17 * V_17 ,
struct V_177 * V_178 , T_3 type )
{
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_110 * V_111 ;
struct V_192 * V_25 ;
void T_4 * V_193 ;
struct V_164 V_165 ;
int V_194 ;
int V_112 ;
V_111 = F_67 ( V_2 , sizeof( * V_111 ) , V_113 ) ;
if ( ! V_111 )
return NULL ;
V_112 = F_108 ( V_178 , 0 , & V_165 ) ;
if ( V_112 < 0 ) {
V_118 ( V_2 , L_20 , type ) ;
goto V_195;
}
V_193 = F_77 ( V_2 , & V_165 ) ;
if ( F_78 ( V_193 ) ) {
V_118 ( V_2 , L_21 , type ) ;
goto V_195;
}
if ( F_109 ( V_178 , L_22 , & V_194 ) )
V_194 = 0 ;
V_111 -> V_91 = F_88 ( V_2 , type , V_194 ) ;
if ( ! V_111 -> V_91 ) {
V_118 ( V_2 , L_23 , type ) ;
goto V_195;
}
V_25 = & V_111 -> V_25 ;
V_25 -> type = type ;
V_25 -> V_26 = V_193 ;
V_25 -> V_117 = 1 << V_194 ;
return V_111 ;
V_195:
F_69 ( V_2 , V_111 ) ;
return NULL ;
}
static int F_110 ( struct V_17 * V_17 ,
struct V_159 * V_160 )
{
struct V_110 * V_111 ;
struct V_177 * V_178 ;
F_111 (pdev->dev.of_node, np) {
if ( ! F_112 ( V_178 ) )
continue;
if ( F_113 ( V_178 , L_25 ) )
V_111 = F_107 ( V_17 , V_178 , V_115 ) ;
else if ( F_113 ( V_178 , L_26 ) )
V_111 = F_107 ( V_17 , V_178 , V_67 ) ;
else if ( F_113 ( V_178 , L_27 ) )
V_111 = F_107 ( V_17 , V_178 , V_125 ) ;
else if ( F_113 ( V_178 , L_28 ) )
V_111 = F_107 ( V_17 , V_178 , V_129 ) ;
else
V_111 = NULL ;
if ( ! V_111 )
continue;
if ( F_66 ( V_17 , V_111 ) ) {
F_69 ( V_17 -> V_2 , V_111 ) ;
continue;
}
switch ( V_111 -> V_25 . type ) {
case V_115 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_212 ) ;
break;
case V_67 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_213 ) ;
break;
case V_123 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_213 ) ;
break;
case V_125 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_214 ) ;
break;
case V_129 :
F_102 ( & V_111 -> V_211 , & V_17 -> V_215 ) ;
break;
}
}
return 0 ;
}
static int F_114 ( struct V_17 * V_17 ,
struct V_159 * V_160 )
{
if ( F_87 ( & V_160 -> V_2 ) )
return F_103 ( V_17 , V_160 ) ;
return F_110 ( V_17 , V_160 ) ;
}
static int F_115 ( struct V_159 * V_160 )
{
const struct V_217 * V_218 ;
const struct V_219 * V_220 ;
struct V_17 * V_17 ;
struct V_164 * V_165 ;
int V_134 , V_112 ;
int V_92 ;
V_17 = F_67 ( & V_160 -> V_2 , sizeof( * V_17 ) , V_113 ) ;
if ( ! V_17 )
return - V_114 ;
V_17 -> V_2 = & V_160 -> V_2 ;
F_116 ( V_160 , V_17 ) ;
V_92 = - V_56 ;
V_220 = F_117 ( V_221 , & V_160 -> V_2 ) ;
if ( V_220 ) {
V_218 = ( const struct V_217 * ) V_220 -> V_184 ;
V_92 = V_218 -> V_181 ;
}
#ifdef F_118
if ( F_119 ( & V_160 -> V_2 ) ) {
const struct V_198 * V_205 ;
V_205 = F_120 ( V_222 , & V_160 -> V_2 ) ;
if ( V_205 )
V_92 = ( int ) V_205 -> V_210 ;
}
#endif
if ( V_92 < 0 )
return - V_133 ;
if ( V_92 == V_93 )
V_17 -> V_45 = & V_223 ;
else
V_17 -> V_45 = & V_224 ;
F_93 ( & V_17 -> V_212 ) ;
F_93 ( & V_17 -> V_213 ) ;
F_93 ( & V_17 -> V_214 ) ;
F_93 ( & V_17 -> V_215 ) ;
V_17 -> V_92 = V_92 ;
F_68 ( & V_160 -> V_2 , L_29 , V_17 -> V_92 ) ;
V_165 = F_76 ( V_160 , V_167 , 0 ) ;
V_17 -> V_19 = F_77 ( & V_160 -> V_2 , V_165 ) ;
if ( F_78 ( V_17 -> V_19 ) ) {
V_118 ( & V_160 -> V_2 , L_30 ) ;
V_112 = F_79 ( V_17 -> V_19 ) ;
goto V_195;
}
V_134 = F_121 ( V_160 , 0 ) ;
if ( V_134 < 0 ) {
V_118 ( & V_160 -> V_2 , L_31 ) ;
V_112 = - V_56 ;
goto V_195;
}
V_112 = F_122 ( & V_160 -> V_2 , V_134 , F_72 ,
V_225 | V_226 ,
F_123 ( & V_160 -> V_2 ) , V_17 ) ;
if ( V_112 ) {
V_118 ( & V_160 -> V_2 , L_32 , V_134 ) ;
goto V_195;
}
F_124 ( & V_17 -> V_148 ) ;
V_112 = F_86 ( V_17 , V_160 ) ;
if ( V_112 ) {
F_125 ( & V_160 -> V_2 , L_33 ) ;
V_17 -> V_126 = 0x1 ;
V_17 -> V_130 = 0x1 ;
}
F_126 ( F_127 () , & V_17 -> V_12 ) ;
V_112 = F_128 ( V_134 , & V_17 -> V_12 ) ;
if ( V_112 ) {
V_118 ( & V_160 -> V_2 , L_34 ) ;
goto V_195;
}
V_112 = F_114 ( V_17 , V_160 ) ;
if ( V_112 ) {
V_118 ( & V_160 -> V_2 , L_35 ) ;
goto V_195;
}
V_17 -> V_45 -> V_227 ( V_17 ) ;
return 0 ;
V_195:
if ( V_17 -> V_19 )
F_129 ( & V_160 -> V_2 , V_17 -> V_19 ) ;
F_69 ( & V_160 -> V_2 , V_17 ) ;
return V_112 ;
}
static void
F_130 ( struct V_17 * V_17 , struct V_188 * V_228 )
{
struct V_110 * V_111 ;
struct V_1 * V_2 = V_17 -> V_2 ;
struct V_9 * V_10 ;
F_44 (ctx, pmus, next) {
V_10 = V_111 -> V_10 ;
if ( V_10 -> V_25 -> V_26 )
F_129 ( V_2 , V_10 -> V_25 -> V_26 ) ;
F_69 ( V_2 , V_111 ) ;
F_69 ( V_2 , V_10 ) ;
}
}
static int F_131 ( struct V_159 * V_160 )
{
struct V_17 * V_17 = F_6 ( & V_160 -> V_2 ) ;
F_130 ( V_17 , & V_17 -> V_212 ) ;
F_130 ( V_17 , & V_17 -> V_213 ) ;
F_130 ( V_17 , & V_17 -> V_214 ) ;
F_130 ( V_17 , & V_17 -> V_215 ) ;
if ( V_17 -> V_19 )
F_129 ( & V_160 -> V_2 , V_17 -> V_19 ) ;
F_69 ( & V_160 -> V_2 , V_17 ) ;
return 0 ;
}
