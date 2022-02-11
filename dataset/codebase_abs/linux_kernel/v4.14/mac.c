static void F_1 ( void * V_1 , enum V_2 V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_5 = V_1 ;
V_7 = V_5 -> V_7 ;
if ( V_3 == V_8 ) {
V_5 -> V_9 ( V_5 -> V_10 ,
V_8 , false ) ;
F_2 ( V_7 -> V_11 , L_1 , V_3 ) ;
}
F_3 ( V_7 -> V_11 , L_2 , V_12 L_3 ,
V_13 , V_3 ) ;
}
static void F_4 ( struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
V_15 -> V_16 = ( F_5 ( V_15 -> V_16 ) )
F_6 ( V_7 -> V_11 , V_5 -> V_17 -> V_18 ,
F_7 ( V_5 -> V_17 ) ) ;
memcpy ( & V_15 -> V_19 , V_5 -> V_19 , sizeof( V_5 -> V_19 ) ) ;
V_15 -> V_20 = V_7 -> V_20 ;
V_15 -> V_21 = V_7 -> V_21 ;
V_15 -> V_22 = false ;
V_15 -> V_23 = V_7 -> V_24 ;
V_15 -> V_25 = ( void * ) V_7 -> V_26 ;
V_15 -> V_27 = F_1 ;
V_15 -> V_28 = F_1 ;
V_15 -> V_29 = V_5 ;
V_15 -> V_30 = V_7 -> V_30 ;
}
static int F_8 ( struct V_4 * V_5 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_14 V_15 ;
T_1 V_32 ;
V_7 = V_5 -> V_7 ;
F_4 ( V_5 , & V_15 ) ;
V_5 -> V_10 = F_9 ( & V_15 ) ;
if ( ! V_5 -> V_10 ) {
V_31 = - V_33 ;
goto V_34;
}
V_31 = F_10 ( V_5 -> V_10 , F_11 () ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = F_12 ( V_5 -> V_10 ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = V_5 -> V_9 ( V_5 -> V_10 ,
V_36 , false ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = F_13 ( V_5 -> V_10 , & V_32 ) ;
if ( V_31 < 0 )
goto V_35;
F_14 ( V_7 -> V_11 , L_4 , V_32 ) ;
goto V_34;
V_35:
F_15 ( V_5 -> V_10 ) ;
V_34:
return V_31 ;
}
static int F_16 ( struct V_4 * V_5 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_14 V_15 ;
T_1 V_32 ;
V_7 = V_5 -> V_7 ;
F_4 ( V_5 , & V_15 ) ;
V_5 -> V_10 = F_17 ( & V_15 ) ;
if ( ! V_5 -> V_10 ) {
V_31 = - V_33 ;
goto V_34;
}
V_31 = F_18 ( V_5 -> V_10 , F_11 () ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = F_19 ( V_5 -> V_10 , true ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = F_20 ( V_5 -> V_10 ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = V_5 -> V_9 ( V_5 -> V_10 ,
V_37 , false ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = F_21 ( V_5 -> V_10 , & V_32 ) ;
if ( V_31 < 0 )
goto V_35;
F_14 ( V_7 -> V_11 , L_5 , V_32 ) ;
goto V_34;
V_35:
F_22 ( V_5 -> V_10 ) ;
V_34:
return V_31 ;
}
static int F_23 ( struct V_4 * V_5 )
{
int V_31 ;
struct V_6 * V_7 ;
struct V_14 V_15 ;
V_7 = V_5 -> V_7 ;
F_4 ( V_5 , & V_15 ) ;
if ( V_7 -> V_20 == V_38 )
V_15 . V_21 = V_39 ;
V_5 -> V_10 = F_24 ( & V_15 ) ;
if ( ! V_5 -> V_10 ) {
V_31 = - V_33 ;
goto V_34;
}
V_31 = F_25 ( V_5 -> V_10 , F_11 () ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = F_26 ( V_5 -> V_10 , true ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = F_27 ( V_5 -> V_10 , V_7 -> V_40 ) ;
if ( V_31 < 0 )
goto V_35;
V_31 = F_28 ( V_5 -> V_10 ) ;
if ( V_31 < 0 )
goto V_35;
F_14 ( V_7 -> V_11 , L_6 ) ;
goto V_34;
V_35:
F_29 ( V_5 -> V_10 ) ;
V_34:
return V_31 ;
}
static int V_18 ( struct V_4 * V_5 )
{
int V_31 ;
struct V_41 * V_42 = V_5 -> V_42 ;
struct V_6 * V_7 = V_5 -> V_7 ;
V_31 = V_7 -> V_43 ( V_5 -> V_10 , V_44 ) ;
if ( ! V_31 && V_42 )
F_30 ( V_42 ) ;
return V_31 ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_5 -> V_42 )
F_32 ( V_5 -> V_42 ) ;
return V_7 -> V_45 ( V_5 -> V_10 , V_44 ) ;
}
static int F_33 ( struct V_46 * V_47 , struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_48 * V_49 , * V_50 ;
struct V_51 * V_52 ;
int V_31 ;
T_2 * V_19 ;
V_7 = V_5 -> V_7 ;
F_34 (old_addr, tmp, &priv->mc_addr_list, list) {
V_19 = ( T_2 * ) V_49 -> V_19 ;
V_31 = V_5 -> V_53 ( V_5 -> V_10 , V_19 ) ;
if ( V_31 < 0 )
return V_31 ;
F_35 ( & V_49 -> V_54 ) ;
F_36 ( V_49 ) ;
}
F_37 (ha, net_dev) {
V_19 = ( T_2 * ) V_52 -> V_19 ;
V_31 = V_5 -> V_55 ( V_5 -> V_10 , V_19 ) ;
if ( V_31 < 0 )
return V_31 ;
V_50 = F_38 ( sizeof( * V_50 ) , V_56 ) ;
if ( ! V_50 )
return - V_57 ;
F_39 ( V_50 -> V_19 , V_52 -> V_19 ) ;
F_40 ( & V_50 -> V_54 , & V_7 -> V_58 ) ;
}
return 0 ;
}
int F_41 ( struct V_4 * V_5 , bool V_59 , bool V_60 )
{
struct V_10 * V_10 = V_5 -> V_10 ;
int V_31 = 0 ;
if ( V_59 != V_5 -> V_61 ) {
V_31 = V_5 -> V_62 ( V_10 , V_59 ) ;
if ( F_42 ( V_31 == 0 ) )
V_5 -> V_61 = V_59 ;
}
if ( V_60 != V_5 -> V_63 ) {
T_3 V_64 = ( V_60 ? V_65 :
V_66 ) ;
V_31 = V_5 -> V_67 ( V_10 , 0 , V_64 , 0 ) ;
if ( F_42 ( V_31 == 0 ) )
V_5 -> V_63 = V_60 ;
}
return V_31 ;
}
void F_43 ( struct V_4 * V_5 , bool * V_68 ,
bool * V_69 )
{
struct V_41 * V_42 = V_5 -> V_42 ;
T_3 V_70 , V_71 ;
T_4 V_72 ;
* V_68 = * V_69 = false ;
if ( ! V_42 -> V_73 )
return;
if ( ! V_5 -> V_74 ) {
* V_68 = V_5 -> V_75 ;
* V_69 = V_5 -> V_76 ;
return;
}
V_70 = 0 ;
if ( V_42 -> V_77 & V_78 )
V_70 |= V_79 ;
if ( V_42 -> V_77 & V_80 )
V_70 |= V_81 ;
V_71 = 0 ;
if ( V_42 -> V_82 )
V_71 |= V_83 ;
if ( V_42 -> V_84 )
V_71 |= V_85 ;
V_72 = F_44 ( V_70 , V_71 ) ;
if ( V_72 & V_86 )
* V_68 = true ;
if ( V_72 & V_87 )
* V_69 = true ;
}
static void F_45 ( struct V_46 * V_47 )
{
}
static void F_46 ( struct V_46 * V_47 )
{
struct V_88 * V_11 = V_47 -> V_11 . V_89 ;
struct V_90 * V_91 = V_11 -> V_92 ;
struct V_4 * V_5 = V_91 -> V_5 ;
struct V_41 * V_42 = V_5 -> V_42 ;
struct V_10 * V_10 ;
bool V_68 , V_69 ;
int V_31 ;
V_10 = V_5 -> V_10 ;
if ( ! V_42 -> V_93 ) {
F_47 ( V_10 ) ;
return;
}
F_48 ( V_10 , V_42 -> V_94 ) ;
F_43 ( V_5 , & V_68 , & V_69 ) ;
V_31 = F_41 ( V_5 , V_68 , V_69 ) ;
if ( V_31 < 0 )
F_49 ( V_47 , L_7 , V_31 ) ;
}
static void F_50 ( struct V_46 * V_47 )
{
struct V_88 * V_11 = V_47 -> V_11 . V_89 ;
struct V_90 * V_91 = V_11 -> V_92 ;
struct V_4 * V_5 = V_91 -> V_5 ;
struct V_41 * V_42 = V_5 -> V_42 ;
struct V_10 * V_10 ;
bool V_68 , V_69 ;
int V_31 ;
V_10 = V_5 -> V_10 ;
F_51 ( V_10 , V_42 -> V_94 ) ;
F_43 ( V_5 , & V_68 , & V_69 ) ;
V_31 = F_41 ( V_5 , V_68 , V_69 ) ;
if ( V_31 < 0 )
F_49 ( V_47 , L_7 , V_31 ) ;
}
static struct V_41 * F_52 ( struct V_46 * V_47 ,
struct V_4 * V_5 ,
void (* F_53)( struct V_46 * ) )
{
struct V_41 * V_42 ;
struct V_6 * V_7 = V_5 -> V_7 ;
V_42 = F_54 ( V_47 , V_7 -> V_95 , F_53 , 0 ,
V_7 -> V_21 ) ;
if ( ! V_42 ) {
F_49 ( V_47 , L_8 ) ;
return NULL ;
}
V_42 -> V_96 &= V_5 -> V_97 ;
V_42 -> V_96 |= ( V_98 | V_99 ) ;
V_42 -> V_77 = V_42 -> V_96 ;
V_5 -> V_42 = V_42 ;
return V_42 ;
}
static struct V_41 * F_55 ( struct V_46 * V_47 ,
struct V_4 * V_5 )
{
return F_52 ( V_47 , V_5 , & F_46 ) ;
}
static struct V_41 * F_56 ( struct V_46 * V_47 ,
struct V_4 * V_5 )
{
return F_52 ( V_47 , V_5 , F_45 ) ;
}
static struct V_41 * F_57 ( struct V_46 * V_47 ,
struct V_4 * V_5 )
{
return F_52 ( V_47 , V_5 , & F_50 ) ;
}
static void F_58 ( struct V_4 * V_5 )
{
V_5 -> F_52 = F_55 ;
V_5 -> V_100 = F_16 ;
V_5 -> V_101 = V_102 ;
V_5 -> V_103 = V_104 ;
V_5 -> V_55 = V_105 ;
V_5 -> V_53 = V_106 ;
V_5 -> V_67 = V_107 ;
V_5 -> V_62 = V_108 ;
V_5 -> V_9 = V_109 ;
V_5 -> F_33 = F_33 ;
V_5 -> V_18 = V_18 ;
V_5 -> F_31 = F_31 ;
V_5 -> V_7 -> V_43 = V_110 ;
V_5 -> V_7 -> V_45 = V_111 ;
}
static void F_59 ( struct V_4 * V_5 )
{
V_5 -> F_52 = F_56 ;
V_5 -> V_100 = F_8 ;
V_5 -> V_101 = V_112 ;
V_5 -> V_103 = V_113 ;
V_5 -> V_55 = V_114 ;
V_5 -> V_53 = V_115 ;
V_5 -> V_67 = V_116 ;
V_5 -> V_62 = V_117 ;
V_5 -> V_9 = V_118 ;
V_5 -> F_33 = F_33 ;
V_5 -> V_18 = V_18 ;
V_5 -> F_31 = F_31 ;
V_5 -> V_7 -> V_43 = V_119 ;
V_5 -> V_7 -> V_45 = V_120 ;
}
static void F_60 ( struct V_4 * V_5 )
{
V_5 -> F_52 = F_57 ;
V_5 -> V_100 = F_23 ;
V_5 -> V_101 = V_121 ;
V_5 -> V_103 = V_122 ;
V_5 -> V_55 = V_123 ;
V_5 -> V_53 = V_124 ;
V_5 -> V_67 = V_125 ;
V_5 -> V_62 = V_126 ;
V_5 -> V_9 = V_127 ;
V_5 -> F_33 = F_33 ;
V_5 -> V_18 = V_18 ;
V_5 -> F_31 = F_31 ;
V_5 -> V_7 -> V_43 = V_128 ;
V_5 -> V_7 -> V_45 = V_129 ;
}
static struct V_130 * F_61 ( int V_131 ,
struct V_4 * V_5 ,
struct V_132 * V_133 )
{
struct V_130 * V_134 ;
struct V_90 V_135 ;
struct V_6 * V_7 ;
static int V_136 ;
int V_137 ;
V_7 = V_5 -> V_7 ;
V_135 . V_5 = V_5 ;
V_135 . V_138 = V_7 -> V_24 ;
V_135 . V_139 = V_131 ;
V_135 . V_140 = V_133 ;
F_62 ( & V_141 ) ;
V_134 = F_63 ( L_9 , V_136 ) ;
if ( ! V_134 ) {
V_137 = - V_57 ;
goto V_142;
}
V_134 -> V_11 . V_143 = V_133 ;
V_134 -> V_11 . V_89 = V_7 -> V_11 ;
F_64 ( & V_134 -> V_11 , F_65 ( V_7 -> V_11 ) ) ;
V_137 = F_66 ( V_134 , & V_135 , sizeof( V_135 ) ) ;
if ( V_137 )
goto V_31;
V_137 = F_67 ( V_134 ) ;
if ( V_137 )
goto V_31;
V_136 ++ ;
F_68 ( & V_141 ) ;
return V_134 ;
V_31:
F_69 ( V_134 ) ;
V_142:
F_68 ( & V_141 ) ;
return F_70 ( V_137 ) ;
}
static int F_71 ( struct V_130 * V_144 )
{
int V_31 , V_145 , V_146 ;
struct V_88 * V_11 ;
struct V_132 * V_140 , * V_147 ;
struct V_4 * V_5 ;
struct V_130 * V_148 ;
struct V_149 V_17 ;
struct V_6 * V_7 ;
const T_4 * V_150 ;
T_1 V_151 ;
T_4 V_131 ;
int V_21 ;
V_11 = & V_144 -> V_11 ;
V_140 = V_11 -> V_143 ;
V_5 = F_72 ( V_11 , sizeof( * V_5 ) , V_152 ) ;
if ( ! V_5 ) {
V_31 = - V_57 ;
F_2 ( V_11 , L_10 , V_31 ) ;
goto V_34;
}
V_7 = F_72 ( V_11 , sizeof( * V_7 ) , V_152 ) ;
if ( ! V_7 ) {
V_31 = - V_57 ;
goto V_34;
}
V_5 -> V_7 = V_7 ;
V_7 -> V_11 = V_11 ;
if ( F_73 ( V_140 , L_11 ) ) {
F_58 ( V_5 ) ;
V_7 -> V_30 = F_74 ( V_140 ,
L_12 , 0 ) ;
} else if ( F_73 ( V_140 , L_13 ) ) {
F_59 ( V_5 ) ;
} else if ( F_73 ( V_140 , L_14 ) ) {
F_60 ( V_5 ) ;
V_7 -> V_30 = F_74 ( V_140 ,
L_15 , 0 ) ;
} else {
F_2 ( V_11 , L_16 ,
V_140 ) ;
V_31 = - V_33 ;
goto V_34;
}
F_75 ( V_11 , V_5 ) ;
F_76 ( & V_7 -> V_58 ) ;
V_147 = F_77 ( V_140 ) ;
if ( ! V_147 ) {
F_2 ( V_11 , L_17 ,
V_140 ) ;
V_31 = - V_33 ;
goto V_153;
}
V_148 = F_78 ( V_147 ) ;
if ( ! V_148 ) {
F_2 ( V_11 , L_18 , V_147 ) ;
V_31 = - V_33 ;
goto V_154;
}
V_31 = F_79 ( V_147 , L_19 , & V_151 ) ;
if ( V_31 ) {
F_2 ( V_11 , L_20 , V_147 ) ;
V_31 = - V_33 ;
goto V_154;
}
V_131 = ( T_4 ) ( V_151 + 1 ) ;
V_7 -> V_26 = F_80 ( & V_148 -> V_11 ) ;
if ( ! V_7 -> V_26 ) {
F_2 ( V_11 , L_21 , V_147 ) ;
V_31 = - V_155 ;
goto V_154;
}
F_81 ( V_147 ) ;
V_31 = F_82 ( V_140 , 0 , & V_17 ) ;
if ( V_31 < 0 ) {
F_2 ( V_11 , L_22 ,
V_140 , V_31 ) ;
goto V_153;
}
V_5 -> V_17 = F_83 ( V_11 ,
F_84 ( V_7 -> V_26 ) ,
V_17 . V_18 , V_17 . V_156 + 1 - V_17 . V_18 ,
L_23 ) ;
if ( ! V_5 -> V_17 ) {
F_2 ( V_11 , L_24 ) ;
V_31 = - V_157 ;
goto V_153;
}
V_7 -> V_158 = F_6 ( V_11 , V_5 -> V_17 -> V_18 ,
V_5 -> V_17 -> V_156 + 1 - V_5 -> V_17 -> V_18 ) ;
if ( ! V_7 -> V_158 ) {
F_2 ( V_11 , L_25 ) ;
V_31 = - V_159 ;
goto V_153;
}
if ( ! F_85 ( V_140 ) ) {
F_86 ( V_11 , V_7 -> V_158 ) ;
F_87 ( V_11 , F_84 ( V_7 -> V_26 ) ,
V_17 . V_18 , V_17 . V_156 + 1 - V_17 . V_18 ) ;
F_88 ( V_11 , V_5 ) ;
F_75 ( V_11 , NULL ) ;
return - V_155 ;
}
V_31 = F_79 ( V_140 , L_19 , & V_151 ) ;
if ( V_31 ) {
F_2 ( V_11 , L_20 , V_140 ) ;
V_31 = - V_33 ;
goto V_153;
}
V_7 -> V_24 = ( T_4 ) V_151 ;
V_150 = F_89 ( V_140 ) ;
if ( ! V_150 ) {
F_2 ( V_11 , L_26 , V_140 ) ;
V_31 = - V_33 ;
goto V_153;
}
memcpy ( V_5 -> V_19 , V_150 , sizeof( V_5 -> V_19 ) ) ;
V_146 = F_90 ( V_140 , L_27 , NULL ) ;
if ( F_91 ( V_146 < 0 ) ) {
F_2 ( V_11 , L_28 ,
V_140 ) ;
V_31 = V_146 ;
goto V_153;
}
if ( V_146 != F_92 ( V_5 -> V_160 ) ) {
F_2 ( V_11 , L_29 ,
V_140 ) ;
V_31 = - V_33 ;
goto V_153;
}
for ( V_145 = 0 ; V_145 < F_92 ( V_5 -> V_160 ) ; V_145 ++ ) {
V_147 = F_74 ( V_140 , L_27 , V_145 ) ;
if ( ! V_147 ) {
F_2 ( V_11 , L_30 ,
V_140 ) ;
V_31 = - V_33 ;
goto V_154;
}
V_148 = F_78 ( V_147 ) ;
if ( ! V_148 ) {
F_2 ( V_11 , L_18 ,
V_147 ) ;
V_31 = - V_33 ;
goto V_154;
}
V_5 -> V_160 [ V_145 ] = F_93 ( & V_148 -> V_11 ) ;
if ( ! V_5 -> V_160 [ V_145 ] ) {
F_2 ( V_11 , L_31 ,
V_147 ) ;
V_31 = - V_33 ;
goto V_154;
}
F_81 ( V_147 ) ;
}
V_21 = F_94 ( V_140 ) ;
if ( V_21 < 0 ) {
F_95 ( V_11 ,
L_32 ,
V_140 ) ;
V_21 = V_161 ;
}
V_7 -> V_21 = V_21 ;
V_7 -> V_94 = V_162 [ V_7 -> V_21 ] ;
V_7 -> V_20 = V_7 -> V_94 ;
V_5 -> V_97 = V_163 ;
if ( V_7 -> V_21 == V_161 )
V_5 -> V_97 &= ~ ( V_164 |
V_165 ) ;
if ( V_7 -> V_20 == 1000 )
V_5 -> V_97 |= V_166 ;
if ( V_7 -> V_21 == V_39 )
V_5 -> V_97 = V_167 ;
V_7 -> V_95 = F_74 ( V_140 , L_33 , 0 ) ;
if ( ! V_7 -> V_95 && F_96 ( V_140 ) ) {
struct V_41 * V_168 ;
V_31 = F_97 ( V_140 ) ;
if ( V_31 )
goto V_153;
V_7 -> V_40 = F_98 ( sizeof( * V_7 -> V_40 ) ,
V_152 ) ;
if ( ! V_7 -> V_40 ) {
V_31 = - V_57 ;
goto V_153;
}
V_7 -> V_95 = F_99 ( V_140 ) ;
V_168 = F_100 ( V_7 -> V_95 ) ;
if ( ! V_168 ) {
V_31 = - V_33 ;
goto V_153;
}
V_7 -> V_40 -> V_93 = V_168 -> V_93 ;
V_7 -> V_40 -> V_94 = V_168 -> V_94 ;
V_7 -> V_40 -> V_73 = V_168 -> V_73 ;
V_7 -> V_40 -> V_82 = V_168 -> V_82 ;
V_7 -> V_40 -> V_84 = V_168 -> V_84 ;
F_101 ( & V_168 -> V_169 . V_11 ) ;
}
V_31 = V_5 -> V_100 ( V_5 ) ;
if ( V_31 < 0 ) {
F_2 ( V_11 , L_34 , V_31 ) ;
F_81 ( V_7 -> V_95 ) ;
goto V_153;
}
V_5 -> V_74 = true ;
V_5 -> V_75 = true ;
V_5 -> V_76 = true ;
V_5 -> V_61 = false ;
V_5 -> V_63 = false ;
V_31 = F_41 ( V_5 , true , true ) ;
if ( V_31 < 0 )
F_2 ( V_11 , L_7 , V_31 ) ;
F_14 ( V_11 , L_35 ,
V_5 -> V_19 [ 0 ] , V_5 -> V_19 [ 1 ] , V_5 -> V_19 [ 2 ] ,
V_5 -> V_19 [ 3 ] , V_5 -> V_19 [ 4 ] , V_5 -> V_19 [ 5 ] ) ;
V_7 -> V_170 = F_61 ( V_131 , V_5 , V_140 ) ;
if ( F_102 ( V_7 -> V_170 ) ) {
F_2 ( V_11 , L_36 ,
V_7 -> V_24 ) ;
V_7 -> V_170 = NULL ;
}
goto V_34;
V_154:
F_81 ( V_147 ) ;
V_153:
F_36 ( V_7 -> V_40 ) ;
F_75 ( V_11 , NULL ) ;
V_34:
return V_31 ;
}
