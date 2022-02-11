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
static int F_12 ( struct V_36 * V_37 [] , struct V_36 * V_38 [] )
{
if ( V_37 [ V_39 ] ) {
if ( F_13 ( V_37 [ V_39 ] ) != V_40 )
return - V_41 ;
if ( ! F_14 ( F_15 ( V_37 [ V_39 ] ) ) )
return - V_42 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_36 * V_37 [] , struct V_36 * V_38 [] )
{
struct V_43 * V_22 = F_17 ( V_2 ) ;
struct V_44 V_45 ;
int V_46 ;
if ( ! V_38 )
return 0 ;
if ( V_38 [ V_20 ] ) {
V_7 V_21 = F_18 ( V_38 [ V_20 ] ) ;
char V_47 [ V_48 + 7 ] ;
snprintf ( V_47 , sizeof( V_47 ) , L_1 ,
V_3 -> V_49 , V_21 ) ;
F_19 ( & V_45 , V_47 ) ;
V_46 = F_20 ( V_22 , V_50 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_36 * V_37 [] , struct V_36 * V_38 [] )
{
struct V_43 * V_22 = F_17 ( V_2 ) ;
struct V_44 V_45 ;
int V_51 = 0 ;
int V_46 ;
if ( ! V_38 )
return 0 ;
if ( V_38 [ V_52 ] ) {
int V_53 = F_22 ( V_38 [ V_52 ] ) ;
F_23 ( & V_45 , V_53 ) ;
V_46 = F_20 ( V_22 , V_54 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_55 ] ) {
int V_56 = F_24 ( V_38 [ V_55 ] ) ;
struct V_1 * V_3 ;
char * V_57 = L_2 ;
if ( V_56 != 0 ) {
V_3 = F_25 ( F_26 ( V_2 ) ,
V_56 ) ;
if ( ! V_3 )
return - V_58 ;
V_57 = V_3 -> V_49 ;
}
F_19 ( & V_45 , V_57 ) ;
V_46 = F_20 ( V_22 , V_59 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_60 ] ) {
V_51 = F_24 ( V_38 [ V_60 ] ) ;
F_23 ( & V_45 , V_51 ) ;
V_46 = F_20 ( V_22 , V_61 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_62 ] ) {
int V_63 = F_24 ( V_38 [ V_62 ] ) ;
F_23 ( & V_45 , V_63 ) ;
V_46 = F_20 ( V_22 , V_64 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_65 ] ) {
int V_66 = F_24 ( V_38 [ V_65 ] ) ;
F_23 ( & V_45 , V_66 ) ;
V_46 = F_20 ( V_22 , V_67 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_68 ] ) {
int V_69 = F_22 ( V_38 [ V_68 ] ) ;
F_23 ( & V_45 , V_69 ) ;
V_46 = F_20 ( V_22 , V_70 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_71 ] ) {
int V_72 = F_24 ( V_38 [ V_71 ] ) ;
if ( V_72 && V_51 ) {
F_27 ( V_22 -> V_73 , L_3 ) ;
return - V_41 ;
}
F_23 ( & V_45 , V_72 ) ;
V_46 = F_20 ( V_22 , V_74 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_75 ] ) {
struct V_36 * V_76 ;
int V_77 = 0 , V_78 ;
F_28 ( V_22 ) ;
F_29 (attr, data[IFLA_BOND_ARP_IP_TARGET], rem) {
T_2 V_79 ;
if ( F_13 ( V_76 ) < sizeof( V_79 ) )
return - V_41 ;
V_79 = F_30 ( V_76 ) ;
F_23 ( & V_45 , ( V_80 V_81 ) V_79 ) ;
V_46 = F_20 ( V_22 , V_82 ,
& V_45 ) ;
if ( V_46 )
break;
V_77 ++ ;
}
if ( V_77 == 0 && V_22 -> V_83 . V_72 )
F_31 ( V_22 -> V_73 , L_4 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_84 ] ) {
int V_85 = F_24 ( V_38 [ V_84 ] ) ;
if ( V_85 && V_51 ) {
F_27 ( V_22 -> V_73 , L_5 ) ;
return - V_41 ;
}
F_23 ( & V_45 , V_85 ) ;
V_46 = F_20 ( V_22 , V_86 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_87 ] ) {
int V_88 =
F_24 ( V_38 [ V_87 ] ) ;
F_23 ( & V_45 , V_88 ) ;
V_46 = F_20 ( V_22 , V_89 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_90 ] ) {
int V_56 = F_24 ( V_38 [ V_90 ] ) ;
struct V_1 * V_73 ;
char * V_91 = L_2 ;
V_73 = F_25 ( F_26 ( V_2 ) , V_56 ) ;
if ( V_73 )
V_91 = V_73 -> V_49 ;
F_19 ( & V_45 , V_91 ) ;
V_46 = F_20 ( V_22 , V_92 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_93 ] ) {
int V_94 =
F_22 ( V_38 [ V_93 ] ) ;
F_23 ( & V_45 , V_94 ) ;
V_46 = F_20 ( V_22 , V_95 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_96 ] ) {
int V_97 =
F_22 ( V_38 [ V_96 ] ) ;
F_23 ( & V_45 , V_97 ) ;
V_46 = F_20 ( V_22 , V_98 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_99 ] ) {
int V_100 =
F_22 ( V_38 [ V_99 ] ) ;
F_23 ( & V_45 , V_100 ) ;
V_46 = F_20 ( V_22 , V_101 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_102 ] ) {
int V_103 =
F_24 ( V_38 [ V_102 ] ) ;
F_23 ( & V_45 , V_103 ) ;
V_46 = F_20 ( V_22 , V_104 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_105 ] ) {
int V_106 =
F_22 ( V_38 [ V_105 ] ) ;
F_23 ( & V_45 , V_106 ) ;
V_46 = F_20 ( V_22 , V_107 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_108 ] ) {
int V_109 =
F_22 ( V_38 [ V_108 ] ) ;
F_23 ( & V_45 , V_109 ) ;
V_46 = F_20 ( V_22 , V_110 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_111 ] ) {
int V_112 =
F_24 ( V_38 [ V_111 ] ) ;
F_23 ( & V_45 , V_112 ) ;
V_46 = F_20 ( V_22 , V_113 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_114 ] ) {
int V_115 =
F_24 ( V_38 [ V_114 ] ) ;
F_23 ( & V_45 , V_115 ) ;
V_46 = F_20 ( V_22 , V_116 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_117 ] ) {
int V_118 =
F_24 ( V_38 [ V_117 ] ) ;
F_23 ( & V_45 , V_118 ) ;
V_46 = F_20 ( V_22 , V_119 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_120 ] ) {
int V_121 =
F_22 ( V_38 [ V_120 ] ) ;
F_23 ( & V_45 , V_121 ) ;
V_46 = F_20 ( V_22 , V_122 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_123 ] ) {
int V_124 =
F_22 ( V_38 [ V_123 ] ) ;
F_23 ( & V_45 , V_124 ) ;
V_46 = F_20 ( V_22 , V_125 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_126 ] ) {
int V_127 =
F_18 ( V_38 [ V_126 ] ) ;
F_23 ( & V_45 , V_127 ) ;
V_46 = F_20 ( V_22 , V_128 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_129 ] ) {
int V_130 =
F_18 ( V_38 [ V_129 ] ) ;
F_23 ( & V_45 , V_130 ) ;
V_46 = F_20 ( V_22 , V_131 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_132 ] ) {
if ( F_13 ( V_38 [ V_132 ] ) != V_40 )
return - V_41 ;
F_23 ( & V_45 ,
F_32 ( V_38 [ V_132 ] ) ) ;
V_46 = F_20 ( V_22 , V_133 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
if ( V_38 [ V_134 ] ) {
int V_135 = F_22 ( V_38 [ V_134 ] ) ;
F_23 ( & V_45 , V_135 ) ;
V_46 = F_20 ( V_22 , V_136 , & V_45 ) ;
if ( V_46 )
return V_46 ;
}
return 0 ;
}
static int F_33 ( struct V_137 * V_138 , struct V_1 * V_2 ,
struct V_36 * V_37 [] , struct V_36 * V_38 [] )
{
int V_46 ;
V_46 = F_21 ( V_2 , V_37 , V_38 ) ;
if ( V_46 < 0 )
return V_46 ;
V_46 = F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
return V_46 ;
}
static T_1 F_36 ( const struct V_1 * V_2 )
{
return F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( struct V_36 ) ) +
F_2 ( sizeof( V_5 ) ) * V_139 +
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
F_2 ( V_40 ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( V_40 ) +
F_2 ( sizeof( V_4 ) ) +
0 ;
}
static int F_37 ( struct V_43 * V_22 )
{
const struct V_1 * V_10 ;
int V_56 ;
F_38 () ;
V_10 = F_39 ( V_22 ) ;
V_56 = V_10 ? V_10 -> V_56 : 0 ;
F_40 () ;
return V_56 ;
}
static int F_41 ( struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
struct V_43 * V_22 = F_17 ( V_2 ) ;
unsigned int V_118 ;
int V_56 , V_77 , V_140 ;
struct V_36 * V_141 ;
struct V_10 * V_91 ;
if ( F_5 ( V_9 , V_52 , F_10 ( V_22 ) ) )
goto V_12;
V_56 = F_37 ( V_22 ) ;
if ( V_56 && F_7 ( V_9 , V_55 , V_56 ) )
goto V_12;
if ( F_7 ( V_9 , V_60 , V_22 -> V_83 . V_51 ) )
goto V_12;
if ( F_7 ( V_9 , V_62 ,
V_22 -> V_83 . V_63 * V_22 -> V_83 . V_51 ) )
goto V_12;
if ( F_7 ( V_9 , V_65 ,
V_22 -> V_83 . V_66 * V_22 -> V_83 . V_51 ) )
goto V_12;
if ( F_5 ( V_9 , V_68 , V_22 -> V_83 . V_69 ) )
goto V_12;
if ( F_7 ( V_9 , V_71 , V_22 -> V_83 . V_72 ) )
goto V_12;
V_141 = F_42 ( V_9 , V_75 ) ;
if ( ! V_141 )
goto V_12;
V_140 = 0 ;
for ( V_77 = 0 ; V_77 < V_139 ; V_77 ++ ) {
if ( V_22 -> V_83 . V_142 [ V_77 ] ) {
F_43 ( V_9 , V_77 , V_22 -> V_83 . V_142 [ V_77 ] ) ;
V_140 = 1 ;
}
}
if ( V_140 )
F_44 ( V_9 , V_141 ) ;
else
F_45 ( V_9 , V_141 ) ;
if ( F_7 ( V_9 , V_84 , V_22 -> V_83 . V_85 ) )
goto V_12;
if ( F_7 ( V_9 , V_87 ,
V_22 -> V_83 . V_88 ) )
goto V_12;
V_91 = F_46 ( V_22 -> V_143 ) ;
if ( V_91 &&
F_7 ( V_9 , V_90 , V_91 -> V_73 -> V_56 ) )
goto V_12;
if ( F_5 ( V_9 , V_93 ,
V_22 -> V_83 . V_94 ) )
goto V_12;
if ( F_5 ( V_9 , V_96 ,
V_22 -> V_83 . V_97 ) )
goto V_12;
if ( F_5 ( V_9 , V_99 ,
V_22 -> V_83 . V_144 ) )
goto V_12;
if ( F_7 ( V_9 , V_102 ,
V_22 -> V_83 . V_103 ) )
goto V_12;
if ( F_5 ( V_9 , V_105 ,
V_22 -> V_83 . V_106 ) )
goto V_12;
if ( F_5 ( V_9 , V_108 ,
V_22 -> V_83 . V_109 ) )
goto V_12;
if ( F_7 ( V_9 , V_111 ,
V_22 -> V_83 . V_112 ) )
goto V_12;
if ( F_7 ( V_9 , V_114 ,
V_22 -> V_83 . V_115 ) )
goto V_12;
V_118 = V_22 -> V_83 . V_118 ;
if ( F_7 ( V_9 , V_117 ,
V_118 ) )
goto V_12;
if ( F_5 ( V_9 , V_120 ,
V_22 -> V_83 . V_145 ) )
goto V_12;
if ( F_5 ( V_9 , V_123 ,
V_22 -> V_83 . V_124 ) )
goto V_12;
if ( F_5 ( V_9 , V_134 ,
V_22 -> V_83 . V_146 ) )
goto V_12;
if ( F_10 ( V_22 ) == V_23 ) {
struct V_147 V_148 ;
if ( F_47 ( V_149 ) ) {
if ( F_9 ( V_9 , V_126 ,
V_22 -> V_83 . V_150 ) )
goto V_12;
if ( F_9 ( V_9 , V_129 ,
V_22 -> V_83 . V_151 ) )
goto V_12;
if ( F_8 ( V_9 , V_132 ,
sizeof( V_22 -> V_83 . V_152 ) ,
& V_22 -> V_83 . V_152 ) )
goto V_12;
}
if ( ! F_48 ( V_22 , & V_148 ) ) {
struct V_36 * V_153 ;
V_153 = F_42 ( V_9 , V_154 ) ;
if ( ! V_153 )
goto V_12;
if ( F_9 ( V_9 , V_155 ,
V_148 . V_156 ) )
goto V_12;
if ( F_9 ( V_9 , V_157 ,
V_148 . V_158 ) )
goto V_12;
if ( F_9 ( V_9 , V_159 ,
V_148 . V_160 ) )
goto V_12;
if ( F_9 ( V_9 , V_161 ,
V_148 . V_162 ) )
goto V_12;
if ( F_8 ( V_9 , V_163 ,
sizeof( V_148 . V_164 ) ,
& V_148 . V_164 ) )
goto V_12;
F_44 ( V_9 , V_153 ) ;
}
}
return 0 ;
V_12:
return - V_35 ;
}
int T_3 F_49 ( void )
{
return F_50 ( & V_165 ) ;
}
void F_51 ( void )
{
F_52 ( & V_165 ) ;
}
