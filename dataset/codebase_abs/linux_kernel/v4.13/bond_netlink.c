static T_1 F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( V_6 ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_7 ) ) +
0 ;
}
static int F_3 ( struct V_8 * V_9 ,
const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
struct V_10 * V_10 = F_4 ( V_3 ) ;
if ( F_5 ( V_9 , V_11 , F_6 ( V_10 ) ) )
goto V_12;
if ( F_5 ( V_9 , V_13 , V_10 -> V_14 ) )
goto V_12;
if ( F_7 ( V_9 , V_15 ,
V_10 -> V_16 ) )
goto V_12;
if ( F_8 ( V_9 , V_17 ,
V_3 -> V_18 , V_10 -> V_19 ) )
goto V_12;
if ( F_9 ( V_9 , V_20 , V_10 -> V_21 ) )
goto V_12;
if ( F_10 ( V_10 -> V_22 ) == V_23 ) {
const struct V_24 * V_25 ;
const struct V_26 * V_27 ;
V_27 = & F_11 ( V_10 ) -> V_26 ;
V_25 = F_11 ( V_10 ) -> V_26 . V_24 ;
if ( V_25 ) {
if ( F_9 ( V_9 , V_28 ,
V_25 -> V_29 ) )
goto V_12;
if ( F_5 ( V_9 ,
V_30 ,
V_27 -> V_31 ) )
goto V_12;
if ( F_9 ( V_9 ,
V_32 ,
V_27 -> V_33 . V_34 ) )
goto V_12;
}
}
return 0 ;
V_12:
return - V_35 ;
}
static int F_12 ( struct V_36 * V_37 [] , struct V_36 * V_38 [] ,
struct V_39 * V_40 )
{
if ( V_37 [ V_41 ] ) {
if ( F_13 ( V_37 [ V_41 ] ) != V_42 )
return - V_43 ;
if ( ! F_14 ( F_15 ( V_37 [ V_41 ] ) ) )
return - V_44 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_36 * V_37 [] , struct V_36 * V_38 [] ,
struct V_39 * V_40 )
{
struct V_45 * V_22 = F_17 ( V_2 ) ;
struct V_46 V_47 ;
int V_48 ;
if ( ! V_38 )
return 0 ;
if ( V_38 [ V_20 ] ) {
V_7 V_21 = F_18 ( V_38 [ V_20 ] ) ;
char V_49 [ V_50 + 7 ] ;
snprintf ( V_49 , sizeof( V_49 ) , L_1 ,
V_3 -> V_51 , V_21 ) ;
F_19 ( & V_47 , V_49 ) ;
V_48 = F_20 ( V_22 , V_52 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_36 * V_37 [] ,
struct V_36 * V_38 [] ,
struct V_39 * V_40 )
{
struct V_45 * V_22 = F_17 ( V_2 ) ;
struct V_46 V_47 ;
int V_53 = 0 ;
int V_48 ;
if ( ! V_38 )
return 0 ;
if ( V_38 [ V_54 ] ) {
int V_55 = F_22 ( V_38 [ V_54 ] ) ;
F_23 ( & V_47 , V_55 ) ;
V_48 = F_20 ( V_22 , V_56 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_57 ] ) {
int V_58 = F_24 ( V_38 [ V_57 ] ) ;
struct V_1 * V_3 ;
char * V_59 = L_2 ;
if ( V_58 != 0 ) {
V_3 = F_25 ( F_26 ( V_2 ) ,
V_58 ) ;
if ( ! V_3 )
return - V_60 ;
V_59 = V_3 -> V_51 ;
}
F_19 ( & V_47 , V_59 ) ;
V_48 = F_20 ( V_22 , V_61 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_62 ] ) {
V_53 = F_24 ( V_38 [ V_62 ] ) ;
F_23 ( & V_47 , V_53 ) ;
V_48 = F_20 ( V_22 , V_63 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_64 ] ) {
int V_65 = F_24 ( V_38 [ V_64 ] ) ;
F_23 ( & V_47 , V_65 ) ;
V_48 = F_20 ( V_22 , V_66 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_67 ] ) {
int V_68 = F_24 ( V_38 [ V_67 ] ) ;
F_23 ( & V_47 , V_68 ) ;
V_48 = F_20 ( V_22 , V_69 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_70 ] ) {
int V_71 = F_22 ( V_38 [ V_70 ] ) ;
F_23 ( & V_47 , V_71 ) ;
V_48 = F_20 ( V_22 , V_72 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_73 ] ) {
int V_74 = F_24 ( V_38 [ V_73 ] ) ;
if ( V_74 && V_53 ) {
F_27 ( V_22 -> V_75 , L_3 ) ;
return - V_43 ;
}
F_23 ( & V_47 , V_74 ) ;
V_48 = F_20 ( V_22 , V_76 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_77 ] ) {
struct V_36 * V_78 ;
int V_79 = 0 , V_80 ;
F_28 ( V_22 ) ;
F_29 (attr, data[IFLA_BOND_ARP_IP_TARGET], rem) {
T_2 V_81 ;
if ( F_13 ( V_78 ) < sizeof( V_81 ) )
return - V_43 ;
V_81 = F_30 ( V_78 ) ;
F_23 ( & V_47 , ( V_82 V_83 ) V_81 ) ;
V_48 = F_20 ( V_22 , V_84 ,
& V_47 ) ;
if ( V_48 )
break;
V_79 ++ ;
}
if ( V_79 == 0 && V_22 -> V_85 . V_74 )
F_31 ( V_22 -> V_75 , L_4 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_86 ] ) {
int V_87 = F_24 ( V_38 [ V_86 ] ) ;
if ( V_87 && V_53 ) {
F_27 ( V_22 -> V_75 , L_5 ) ;
return - V_43 ;
}
F_23 ( & V_47 , V_87 ) ;
V_48 = F_20 ( V_22 , V_88 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_89 ] ) {
int V_90 =
F_24 ( V_38 [ V_89 ] ) ;
F_23 ( & V_47 , V_90 ) ;
V_48 = F_20 ( V_22 , V_91 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_92 ] ) {
int V_58 = F_24 ( V_38 [ V_92 ] ) ;
struct V_1 * V_75 ;
char * V_93 = L_2 ;
V_75 = F_25 ( F_26 ( V_2 ) , V_58 ) ;
if ( V_75 )
V_93 = V_75 -> V_51 ;
F_19 ( & V_47 , V_93 ) ;
V_48 = F_20 ( V_22 , V_94 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_95 ] ) {
int V_96 =
F_22 ( V_38 [ V_95 ] ) ;
F_23 ( & V_47 , V_96 ) ;
V_48 = F_20 ( V_22 , V_97 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_98 ] ) {
int V_99 =
F_22 ( V_38 [ V_98 ] ) ;
F_23 ( & V_47 , V_99 ) ;
V_48 = F_20 ( V_22 , V_100 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_101 ] ) {
int V_102 =
F_22 ( V_38 [ V_101 ] ) ;
F_23 ( & V_47 , V_102 ) ;
V_48 = F_20 ( V_22 , V_103 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_104 ] ) {
int V_105 =
F_24 ( V_38 [ V_104 ] ) ;
F_23 ( & V_47 , V_105 ) ;
V_48 = F_20 ( V_22 , V_106 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_107 ] ) {
int V_108 =
F_22 ( V_38 [ V_107 ] ) ;
F_23 ( & V_47 , V_108 ) ;
V_48 = F_20 ( V_22 , V_109 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_110 ] ) {
int V_111 =
F_22 ( V_38 [ V_110 ] ) ;
F_23 ( & V_47 , V_111 ) ;
V_48 = F_20 ( V_22 , V_112 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_113 ] ) {
int V_114 =
F_24 ( V_38 [ V_113 ] ) ;
F_23 ( & V_47 , V_114 ) ;
V_48 = F_20 ( V_22 , V_115 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_116 ] ) {
int V_117 =
F_24 ( V_38 [ V_116 ] ) ;
F_23 ( & V_47 , V_117 ) ;
V_48 = F_20 ( V_22 , V_118 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_119 ] ) {
int V_120 =
F_24 ( V_38 [ V_119 ] ) ;
F_23 ( & V_47 , V_120 ) ;
V_48 = F_20 ( V_22 , V_121 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_122 ] ) {
int V_123 =
F_22 ( V_38 [ V_122 ] ) ;
F_23 ( & V_47 , V_123 ) ;
V_48 = F_20 ( V_22 , V_124 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_125 ] ) {
int V_126 =
F_22 ( V_38 [ V_125 ] ) ;
F_23 ( & V_47 , V_126 ) ;
V_48 = F_20 ( V_22 , V_127 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_128 ] ) {
int V_129 =
F_18 ( V_38 [ V_128 ] ) ;
F_23 ( & V_47 , V_129 ) ;
V_48 = F_20 ( V_22 , V_130 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_131 ] ) {
int V_132 =
F_18 ( V_38 [ V_131 ] ) ;
F_23 ( & V_47 , V_132 ) ;
V_48 = F_20 ( V_22 , V_133 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_134 ] ) {
if ( F_13 ( V_38 [ V_134 ] ) != V_42 )
return - V_43 ;
F_23 ( & V_47 ,
F_32 ( V_38 [ V_134 ] ) ) ;
V_48 = F_20 ( V_22 , V_135 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
if ( V_38 [ V_136 ] ) {
int V_137 = F_22 ( V_38 [ V_136 ] ) ;
F_23 ( & V_47 , V_137 ) ;
V_48 = F_20 ( V_22 , V_138 , & V_47 ) ;
if ( V_48 )
return V_48 ;
}
return 0 ;
}
static int F_33 ( struct V_139 * V_140 , struct V_1 * V_2 ,
struct V_36 * V_37 [] , struct V_36 * V_38 [] ,
struct V_39 * V_40 )
{
int V_48 ;
V_48 = F_21 ( V_2 , V_37 , V_38 , V_40 ) ;
if ( V_48 < 0 )
return V_48 ;
V_48 = F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
if ( ! V_48 ) {
struct V_45 * V_22 = F_17 ( V_2 ) ;
F_36 ( V_22 ) ;
}
return V_48 ;
}
static T_1 F_37 ( const struct V_1 * V_2 )
{
return F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( struct V_36 ) ) +
F_2 ( sizeof( V_5 ) ) * V_141 +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( struct V_36 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( V_42 ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( V_42 ) +
F_2 ( sizeof( V_4 ) ) +
0 ;
}
static int F_38 ( struct V_45 * V_22 )
{
const struct V_1 * V_10 ;
int V_58 ;
F_39 () ;
V_10 = F_40 ( V_22 ) ;
V_58 = V_10 ? V_10 -> V_58 : 0 ;
F_41 () ;
return V_58 ;
}
static int F_42 ( struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
struct V_45 * V_22 = F_17 ( V_2 ) ;
unsigned int V_120 ;
int V_58 , V_79 , V_142 ;
struct V_36 * V_143 ;
struct V_10 * V_93 ;
if ( F_5 ( V_9 , V_54 , F_10 ( V_22 ) ) )
goto V_12;
V_58 = F_38 ( V_22 ) ;
if ( V_58 && F_7 ( V_9 , V_57 , V_58 ) )
goto V_12;
if ( F_7 ( V_9 , V_62 , V_22 -> V_85 . V_53 ) )
goto V_12;
if ( F_7 ( V_9 , V_64 ,
V_22 -> V_85 . V_65 * V_22 -> V_85 . V_53 ) )
goto V_12;
if ( F_7 ( V_9 , V_67 ,
V_22 -> V_85 . V_68 * V_22 -> V_85 . V_53 ) )
goto V_12;
if ( F_5 ( V_9 , V_70 , V_22 -> V_85 . V_71 ) )
goto V_12;
if ( F_7 ( V_9 , V_73 , V_22 -> V_85 . V_74 ) )
goto V_12;
V_143 = F_43 ( V_9 , V_77 ) ;
if ( ! V_143 )
goto V_12;
V_142 = 0 ;
for ( V_79 = 0 ; V_79 < V_141 ; V_79 ++ ) {
if ( V_22 -> V_85 . V_144 [ V_79 ] ) {
if ( F_44 ( V_9 , V_79 , V_22 -> V_85 . V_144 [ V_79 ] ) )
goto V_12;
V_142 = 1 ;
}
}
if ( V_142 )
F_45 ( V_9 , V_143 ) ;
else
F_46 ( V_9 , V_143 ) ;
if ( F_7 ( V_9 , V_86 , V_22 -> V_85 . V_87 ) )
goto V_12;
if ( F_7 ( V_9 , V_89 ,
V_22 -> V_85 . V_90 ) )
goto V_12;
V_93 = F_47 ( V_22 -> V_145 ) ;
if ( V_93 &&
F_7 ( V_9 , V_92 , V_93 -> V_75 -> V_58 ) )
goto V_12;
if ( F_5 ( V_9 , V_95 ,
V_22 -> V_85 . V_96 ) )
goto V_12;
if ( F_5 ( V_9 , V_98 ,
V_22 -> V_85 . V_99 ) )
goto V_12;
if ( F_5 ( V_9 , V_101 ,
V_22 -> V_85 . V_146 ) )
goto V_12;
if ( F_7 ( V_9 , V_104 ,
V_22 -> V_85 . V_105 ) )
goto V_12;
if ( F_5 ( V_9 , V_107 ,
V_22 -> V_85 . V_108 ) )
goto V_12;
if ( F_5 ( V_9 , V_110 ,
V_22 -> V_85 . V_111 ) )
goto V_12;
if ( F_7 ( V_9 , V_113 ,
V_22 -> V_85 . V_114 ) )
goto V_12;
if ( F_7 ( V_9 , V_116 ,
V_22 -> V_85 . V_117 ) )
goto V_12;
V_120 = V_22 -> V_85 . V_120 ;
if ( F_7 ( V_9 , V_119 ,
V_120 ) )
goto V_12;
if ( F_5 ( V_9 , V_122 ,
V_22 -> V_85 . V_147 ) )
goto V_12;
if ( F_5 ( V_9 , V_125 ,
V_22 -> V_85 . V_126 ) )
goto V_12;
if ( F_5 ( V_9 , V_136 ,
V_22 -> V_85 . V_148 ) )
goto V_12;
if ( F_10 ( V_22 ) == V_23 ) {
struct V_149 V_150 ;
if ( F_48 ( V_151 ) ) {
if ( F_9 ( V_9 , V_128 ,
V_22 -> V_85 . V_152 ) )
goto V_12;
if ( F_9 ( V_9 , V_131 ,
V_22 -> V_85 . V_153 ) )
goto V_12;
if ( F_8 ( V_9 , V_134 ,
sizeof( V_22 -> V_85 . V_154 ) ,
& V_22 -> V_85 . V_154 ) )
goto V_12;
}
if ( ! F_49 ( V_22 , & V_150 ) ) {
struct V_36 * V_155 ;
V_155 = F_43 ( V_9 , V_156 ) ;
if ( ! V_155 )
goto V_12;
if ( F_9 ( V_9 , V_157 ,
V_150 . V_158 ) )
goto V_12;
if ( F_9 ( V_9 , V_159 ,
V_150 . V_160 ) )
goto V_12;
if ( F_9 ( V_9 , V_161 ,
V_150 . V_162 ) )
goto V_12;
if ( F_9 ( V_9 , V_163 ,
V_150 . V_164 ) )
goto V_12;
if ( F_8 ( V_9 , V_165 ,
sizeof( V_150 . V_166 ) ,
& V_150 . V_166 ) )
goto V_12;
F_45 ( V_9 , V_155 ) ;
}
}
return 0 ;
V_12:
return - V_35 ;
}
int T_3 F_50 ( void )
{
return F_51 ( & V_167 ) ;
}
void F_52 ( void )
{
F_53 ( & V_167 ) ;
}
