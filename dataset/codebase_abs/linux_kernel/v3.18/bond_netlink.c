static T_1 F_1 ( const struct V_1 * V_2 ,
const struct V_1 * V_3 )
{
return F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( V_6 ) +
F_2 ( sizeof( V_7 ) ) +
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
V_25 = F_11 ( V_10 ) -> V_26 . V_24 ;
if ( V_25 )
if ( F_9 ( V_9 , V_27 ,
V_25 -> V_28 ) )
goto V_12;
}
return 0 ;
V_12:
return - V_29 ;
}
static int F_12 ( struct V_30 * V_31 [] , struct V_30 * V_32 [] )
{
if ( V_31 [ V_33 ] ) {
if ( F_13 ( V_31 [ V_33 ] ) != V_34 )
return - V_35 ;
if ( ! F_14 ( F_15 ( V_31 [ V_33 ] ) ) )
return - V_36 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
struct V_30 * V_31 [] , struct V_30 * V_32 [] )
{
struct V_37 * V_22 = F_17 ( V_2 ) ;
struct V_38 V_39 ;
int V_40 ;
if ( ! V_32 )
return 0 ;
if ( V_32 [ V_20 ] ) {
V_7 V_21 = F_18 ( V_32 [ V_20 ] ) ;
char V_41 [ V_42 + 7 ] ;
snprintf ( V_41 , sizeof( V_41 ) , L_1 ,
V_3 -> V_43 , V_21 ) ;
F_19 ( & V_39 , V_41 ) ;
V_40 = F_20 ( V_22 , V_44 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_30 * V_31 [] , struct V_30 * V_32 [] )
{
struct V_37 * V_22 = F_17 ( V_2 ) ;
struct V_38 V_39 ;
int V_45 = 0 ;
int V_40 ;
if ( ! V_32 )
return 0 ;
if ( V_32 [ V_46 ] ) {
int V_47 = F_22 ( V_32 [ V_46 ] ) ;
F_23 ( & V_39 , V_47 ) ;
V_40 = F_20 ( V_22 , V_48 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_49 ] ) {
int V_50 = F_24 ( V_32 [ V_49 ] ) ;
struct V_1 * V_3 ;
char * V_51 = L_2 ;
if ( V_50 != 0 ) {
V_3 = F_25 ( F_26 ( V_2 ) ,
V_50 ) ;
if ( ! V_3 )
return - V_52 ;
V_51 = V_3 -> V_43 ;
}
F_19 ( & V_39 , V_51 ) ;
V_40 = F_20 ( V_22 , V_53 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_54 ] ) {
V_45 = F_24 ( V_32 [ V_54 ] ) ;
F_23 ( & V_39 , V_45 ) ;
V_40 = F_20 ( V_22 , V_55 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_56 ] ) {
int V_57 = F_24 ( V_32 [ V_56 ] ) ;
F_23 ( & V_39 , V_57 ) ;
V_40 = F_20 ( V_22 , V_58 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_59 ] ) {
int V_60 = F_24 ( V_32 [ V_59 ] ) ;
F_23 ( & V_39 , V_60 ) ;
V_40 = F_20 ( V_22 , V_61 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_62 ] ) {
int V_63 = F_22 ( V_32 [ V_62 ] ) ;
F_23 ( & V_39 , V_63 ) ;
V_40 = F_20 ( V_22 , V_64 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_65 ] ) {
int V_66 = F_24 ( V_32 [ V_65 ] ) ;
if ( V_66 && V_45 ) {
F_27 ( V_22 -> V_67 , L_3 ) ;
return - V_35 ;
}
F_23 ( & V_39 , V_66 ) ;
V_40 = F_20 ( V_22 , V_68 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_69 ] ) {
struct V_30 * V_70 ;
int V_71 = 0 , V_72 ;
F_28 ( V_22 ) ;
F_29 (attr, data[IFLA_BOND_ARP_IP_TARGET], rem) {
T_2 V_73 ;
if ( F_13 ( V_70 ) < sizeof( V_73 ) )
return - V_35 ;
V_73 = F_30 ( V_70 ) ;
F_23 ( & V_39 , ( V_74 V_75 ) V_73 ) ;
V_40 = F_20 ( V_22 , V_76 ,
& V_39 ) ;
if ( V_40 )
break;
V_71 ++ ;
}
if ( V_71 == 0 && V_22 -> V_77 . V_66 )
F_31 ( V_22 -> V_67 , L_4 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_78 ] ) {
int V_79 = F_24 ( V_32 [ V_78 ] ) ;
if ( V_79 && V_45 ) {
F_27 ( V_22 -> V_67 , L_5 ) ;
return - V_35 ;
}
F_23 ( & V_39 , V_79 ) ;
V_40 = F_20 ( V_22 , V_80 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_81 ] ) {
int V_82 =
F_24 ( V_32 [ V_81 ] ) ;
F_23 ( & V_39 , V_82 ) ;
V_40 = F_20 ( V_22 , V_83 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_84 ] ) {
int V_50 = F_24 ( V_32 [ V_84 ] ) ;
struct V_1 * V_67 ;
char * V_85 = L_2 ;
V_67 = F_25 ( F_26 ( V_2 ) , V_50 ) ;
if ( V_67 )
V_85 = V_67 -> V_43 ;
F_19 ( & V_39 , V_85 ) ;
V_40 = F_20 ( V_22 , V_86 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_87 ] ) {
int V_88 =
F_22 ( V_32 [ V_87 ] ) ;
F_23 ( & V_39 , V_88 ) ;
V_40 = F_20 ( V_22 , V_89 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_90 ] ) {
int V_91 =
F_22 ( V_32 [ V_90 ] ) ;
F_23 ( & V_39 , V_91 ) ;
V_40 = F_20 ( V_22 , V_92 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_93 ] ) {
int V_94 =
F_22 ( V_32 [ V_93 ] ) ;
F_23 ( & V_39 , V_94 ) ;
V_40 = F_20 ( V_22 , V_95 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_96 ] ) {
int V_97 =
F_24 ( V_32 [ V_96 ] ) ;
F_23 ( & V_39 , V_97 ) ;
V_40 = F_20 ( V_22 , V_98 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_99 ] ) {
int V_100 =
F_22 ( V_32 [ V_99 ] ) ;
F_23 ( & V_39 , V_100 ) ;
V_40 = F_20 ( V_22 , V_101 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_102 ] ) {
int V_103 =
F_22 ( V_32 [ V_102 ] ) ;
F_23 ( & V_39 , V_103 ) ;
V_40 = F_20 ( V_22 , V_104 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_105 ] ) {
int V_106 =
F_24 ( V_32 [ V_105 ] ) ;
F_23 ( & V_39 , V_106 ) ;
V_40 = F_20 ( V_22 , V_107 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_108 ] ) {
int V_109 =
F_24 ( V_32 [ V_108 ] ) ;
F_23 ( & V_39 , V_109 ) ;
V_40 = F_20 ( V_22 , V_110 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_111 ] ) {
int V_112 =
F_24 ( V_32 [ V_111 ] ) ;
F_23 ( & V_39 , V_112 ) ;
V_40 = F_20 ( V_22 , V_113 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_114 ] ) {
int V_115 =
F_22 ( V_32 [ V_114 ] ) ;
F_23 ( & V_39 , V_115 ) ;
V_40 = F_20 ( V_22 , V_116 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
if ( V_32 [ V_117 ] ) {
int V_118 =
F_22 ( V_32 [ V_117 ] ) ;
F_23 ( & V_39 , V_118 ) ;
V_40 = F_20 ( V_22 , V_119 , & V_39 ) ;
if ( V_40 )
return V_40 ;
}
return 0 ;
}
static int F_32 ( struct V_120 * V_121 , struct V_1 * V_2 ,
struct V_30 * V_31 [] , struct V_30 * V_32 [] )
{
int V_40 ;
V_40 = F_21 ( V_2 , V_31 , V_32 ) ;
if ( V_40 < 0 )
return V_40 ;
return F_33 ( V_2 ) ;
}
static T_1 F_34 ( const struct V_1 * V_2 )
{
return F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( struct V_30 ) ) +
F_2 ( sizeof( V_5 ) ) * V_122 +
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
F_2 ( sizeof( struct V_30 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( V_34 ) +
0 ;
}
static int F_35 ( struct V_37 * V_22 )
{
const struct V_1 * V_10 ;
int V_50 ;
F_36 () ;
V_10 = F_37 ( V_22 ) ;
V_50 = V_10 ? V_10 -> V_50 : 0 ;
F_38 () ;
return V_50 ;
}
static int F_39 ( struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
struct V_37 * V_22 = F_17 ( V_2 ) ;
unsigned int V_112 ;
int V_50 , V_71 , V_123 ;
struct V_30 * V_124 ;
struct V_10 * V_85 ;
if ( F_5 ( V_9 , V_46 , F_10 ( V_22 ) ) )
goto V_12;
V_50 = F_35 ( V_22 ) ;
if ( V_50 && F_7 ( V_9 , V_49 , V_50 ) )
goto V_12;
if ( F_7 ( V_9 , V_54 , V_22 -> V_77 . V_45 ) )
goto V_12;
if ( F_7 ( V_9 , V_56 ,
V_22 -> V_77 . V_57 * V_22 -> V_77 . V_45 ) )
goto V_12;
if ( F_7 ( V_9 , V_59 ,
V_22 -> V_77 . V_60 * V_22 -> V_77 . V_45 ) )
goto V_12;
if ( F_5 ( V_9 , V_62 , V_22 -> V_77 . V_63 ) )
goto V_12;
if ( F_7 ( V_9 , V_65 , V_22 -> V_77 . V_66 ) )
goto V_12;
V_124 = F_40 ( V_9 , V_69 ) ;
if ( ! V_124 )
goto V_12;
V_123 = 0 ;
for ( V_71 = 0 ; V_71 < V_122 ; V_71 ++ ) {
if ( V_22 -> V_77 . V_125 [ V_71 ] ) {
F_41 ( V_9 , V_71 , V_22 -> V_77 . V_125 [ V_71 ] ) ;
V_123 = 1 ;
}
}
if ( V_123 )
F_42 ( V_9 , V_124 ) ;
else
F_43 ( V_9 , V_124 ) ;
if ( F_7 ( V_9 , V_78 , V_22 -> V_77 . V_79 ) )
goto V_12;
if ( F_7 ( V_9 , V_81 ,
V_22 -> V_77 . V_82 ) )
goto V_12;
V_85 = F_44 ( V_22 -> V_126 ) ;
if ( V_85 &&
F_7 ( V_9 , V_84 , V_85 -> V_67 -> V_50 ) )
goto V_12;
if ( F_5 ( V_9 , V_87 ,
V_22 -> V_77 . V_88 ) )
goto V_12;
if ( F_5 ( V_9 , V_90 ,
V_22 -> V_77 . V_91 ) )
goto V_12;
if ( F_5 ( V_9 , V_93 ,
V_22 -> V_77 . V_127 ) )
goto V_12;
if ( F_7 ( V_9 , V_96 ,
V_22 -> V_77 . V_97 ) )
goto V_12;
if ( F_5 ( V_9 , V_99 ,
V_22 -> V_77 . V_100 ) )
goto V_12;
if ( F_5 ( V_9 , V_102 ,
V_22 -> V_77 . V_103 ) )
goto V_12;
if ( F_7 ( V_9 , V_105 ,
V_22 -> V_77 . V_106 ) )
goto V_12;
if ( F_7 ( V_9 , V_108 ,
V_22 -> V_77 . V_109 ) )
goto V_12;
V_112 = V_22 -> V_77 . V_112 ;
if ( F_7 ( V_9 , V_111 ,
V_112 ) )
goto V_12;
if ( F_5 ( V_9 , V_114 ,
V_22 -> V_77 . V_128 ) )
goto V_12;
if ( F_5 ( V_9 , V_117 ,
V_22 -> V_77 . V_118 ) )
goto V_12;
if ( F_10 ( V_22 ) == V_23 ) {
struct V_129 V_130 ;
if ( ! F_45 ( V_22 , & V_130 ) ) {
struct V_30 * V_131 ;
V_131 = F_40 ( V_9 , V_132 ) ;
if ( ! V_131 )
goto V_12;
if ( F_9 ( V_9 , V_133 ,
V_130 . V_134 ) )
goto V_12;
if ( F_9 ( V_9 , V_135 ,
V_130 . V_136 ) )
goto V_12;
if ( F_9 ( V_9 , V_137 ,
V_130 . V_138 ) )
goto V_12;
if ( F_9 ( V_9 , V_139 ,
V_130 . V_140 ) )
goto V_12;
if ( F_8 ( V_9 , V_141 ,
sizeof( V_130 . V_142 ) ,
& V_130 . V_142 ) )
goto V_12;
F_42 ( V_9 , V_131 ) ;
}
}
return 0 ;
V_12:
return - V_29 ;
}
int T_3 F_46 ( void )
{
return F_47 ( & V_143 ) ;
}
void F_48 ( void )
{
F_49 ( & V_143 ) ;
}
