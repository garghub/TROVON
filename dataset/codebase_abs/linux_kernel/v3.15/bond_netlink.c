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
if ( V_10 -> V_22 -> V_23 . V_24 == V_25 ) {
const struct V_26 * V_27 ;
V_27 = F_10 ( V_10 ) . V_28 . V_26 ;
if ( V_27 )
if ( F_9 ( V_9 , V_29 ,
V_27 -> V_30 ) )
goto V_12;
}
return 0 ;
V_12:
return - V_31 ;
}
static int F_11 ( struct V_32 * V_33 [] , struct V_32 * V_34 [] )
{
if ( V_33 [ V_35 ] ) {
if ( F_12 ( V_33 [ V_35 ] ) != V_36 )
return - V_37 ;
if ( ! F_13 ( F_14 ( V_33 [ V_35 ] ) ) )
return - V_38 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_32 * V_33 [] , struct V_32 * V_34 [] )
{
struct V_39 * V_22 = F_16 ( V_2 ) ;
struct V_40 V_41 ;
int V_42 = 0 ;
int V_43 ;
if ( ! V_34 )
return 0 ;
if ( V_34 [ V_44 ] ) {
int V_24 = F_17 ( V_34 [ V_44 ] ) ;
F_18 ( & V_41 , V_24 ) ;
V_43 = F_19 ( V_22 , V_45 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_46 ] ) {
int V_47 = F_20 ( V_34 [ V_46 ] ) ;
struct V_1 * V_3 ;
char * V_48 = L_1 ;
if ( V_47 != 0 ) {
V_3 = F_21 ( F_22 ( V_2 ) ,
V_47 ) ;
if ( ! V_3 )
return - V_49 ;
V_48 = V_3 -> V_50 ;
}
F_23 ( & V_41 , V_48 ) ;
V_43 = F_19 ( V_22 , V_51 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_52 ] ) {
V_42 = F_20 ( V_34 [ V_52 ] ) ;
F_18 ( & V_41 , V_42 ) ;
V_43 = F_19 ( V_22 , V_53 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_54 ] ) {
int V_55 = F_20 ( V_34 [ V_54 ] ) ;
F_18 ( & V_41 , V_55 ) ;
V_43 = F_19 ( V_22 , V_56 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_57 ] ) {
int V_58 = F_20 ( V_34 [ V_57 ] ) ;
F_18 ( & V_41 , V_58 ) ;
V_43 = F_19 ( V_22 , V_59 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_60 ] ) {
int V_61 = F_17 ( V_34 [ V_60 ] ) ;
F_18 ( & V_41 , V_61 ) ;
V_43 = F_19 ( V_22 , V_62 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_63 ] ) {
int V_64 = F_20 ( V_34 [ V_63 ] ) ;
if ( V_64 && V_42 ) {
F_24 ( L_2 ,
V_22 -> V_65 -> V_50 ) ;
return - V_37 ;
}
F_18 ( & V_41 , V_64 ) ;
V_43 = F_19 ( V_22 , V_66 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_67 ] ) {
struct V_32 * V_68 ;
int V_69 = 0 , V_70 ;
F_25 ( V_22 ) ;
F_26 (attr, data[IFLA_BOND_ARP_IP_TARGET], rem) {
T_2 V_71 = F_27 ( V_68 ) ;
F_18 ( & V_41 , ( V_72 V_73 ) V_71 ) ;
V_43 = F_19 ( V_22 , V_74 ,
& V_41 ) ;
if ( V_43 )
break;
V_69 ++ ;
}
if ( V_69 == 0 && V_22 -> V_23 . V_64 )
F_28 ( L_3 ,
V_22 -> V_65 -> V_50 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_75 ] ) {
int V_76 = F_20 ( V_34 [ V_75 ] ) ;
if ( V_76 && V_42 ) {
F_24 ( L_4 ,
V_22 -> V_65 -> V_50 ) ;
return - V_37 ;
}
F_18 ( & V_41 , V_76 ) ;
V_43 = F_19 ( V_22 , V_77 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_78 ] ) {
int V_79 =
F_20 ( V_34 [ V_78 ] ) ;
F_18 ( & V_41 , V_79 ) ;
V_43 = F_19 ( V_22 , V_80 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_81 ] ) {
int V_47 = F_20 ( V_34 [ V_81 ] ) ;
struct V_1 * V_65 ;
char * V_82 = L_1 ;
V_65 = F_21 ( F_22 ( V_2 ) , V_47 ) ;
if ( V_65 )
V_82 = V_65 -> V_50 ;
F_23 ( & V_41 , V_82 ) ;
V_43 = F_19 ( V_22 , V_83 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_84 ] ) {
int V_85 =
F_17 ( V_34 [ V_84 ] ) ;
F_18 ( & V_41 , V_85 ) ;
V_43 = F_19 ( V_22 , V_86 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_87 ] ) {
int V_88 =
F_17 ( V_34 [ V_87 ] ) ;
F_18 ( & V_41 , V_88 ) ;
V_43 = F_19 ( V_22 , V_89 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_90 ] ) {
int V_91 =
F_17 ( V_34 [ V_90 ] ) ;
F_18 ( & V_41 , V_91 ) ;
V_43 = F_19 ( V_22 , V_92 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_93 ] ) {
int V_94 =
F_20 ( V_34 [ V_93 ] ) ;
F_18 ( & V_41 , V_94 ) ;
V_43 = F_19 ( V_22 , V_95 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_96 ] ) {
int V_97 =
F_17 ( V_34 [ V_96 ] ) ;
F_18 ( & V_41 , V_97 ) ;
V_43 = F_19 ( V_22 , V_98 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_99 ] ) {
int V_100 =
F_17 ( V_34 [ V_99 ] ) ;
F_18 ( & V_41 , V_100 ) ;
V_43 = F_19 ( V_22 , V_101 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_102 ] ) {
int V_103 =
F_20 ( V_34 [ V_102 ] ) ;
F_18 ( & V_41 , V_103 ) ;
V_43 = F_19 ( V_22 , V_104 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_105 ] ) {
int V_106 =
F_20 ( V_34 [ V_105 ] ) ;
F_18 ( & V_41 , V_106 ) ;
V_43 = F_19 ( V_22 , V_107 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_108 ] ) {
int V_109 =
F_20 ( V_34 [ V_108 ] ) ;
F_18 ( & V_41 , V_109 ) ;
V_43 = F_19 ( V_22 , V_110 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_111 ] ) {
int V_112 =
F_17 ( V_34 [ V_111 ] ) ;
F_18 ( & V_41 , V_112 ) ;
V_43 = F_19 ( V_22 , V_113 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_114 ] ) {
int V_115 =
F_17 ( V_34 [ V_114 ] ) ;
F_18 ( & V_41 , V_115 ) ;
V_43 = F_19 ( V_22 , V_116 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static int F_29 ( struct V_117 * V_118 , struct V_1 * V_2 ,
struct V_32 * V_33 [] , struct V_32 * V_34 [] )
{
int V_43 ;
V_43 = F_15 ( V_2 , V_33 , V_34 ) ;
if ( V_43 < 0 )
return V_43 ;
return F_30 ( V_2 ) ;
}
static T_1 F_31 ( const struct V_1 * V_2 )
{
return F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( struct V_32 ) ) +
F_2 ( sizeof( V_5 ) ) * V_119 +
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
F_2 ( sizeof( struct V_32 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( V_36 ) +
0 ;
}
static int F_32 ( struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
struct V_39 * V_22 = F_16 ( V_2 ) ;
struct V_1 * V_3 = F_33 ( V_22 ) ;
struct V_32 * V_120 ;
unsigned int V_109 ;
int V_69 , V_121 ;
if ( F_5 ( V_9 , V_44 , V_22 -> V_23 . V_24 ) )
goto V_12;
if ( V_3 &&
F_7 ( V_9 , V_46 , V_3 -> V_47 ) )
goto V_12;
if ( F_7 ( V_9 , V_52 , V_22 -> V_23 . V_42 ) )
goto V_12;
if ( F_7 ( V_9 , V_54 ,
V_22 -> V_23 . V_55 * V_22 -> V_23 . V_42 ) )
goto V_12;
if ( F_7 ( V_9 , V_57 ,
V_22 -> V_23 . V_58 * V_22 -> V_23 . V_42 ) )
goto V_12;
if ( F_5 ( V_9 , V_60 , V_22 -> V_23 . V_61 ) )
goto V_12;
if ( F_7 ( V_9 , V_63 , V_22 -> V_23 . V_64 ) )
goto V_12;
V_120 = F_34 ( V_9 , V_67 ) ;
if ( ! V_120 )
goto V_12;
V_121 = 0 ;
for ( V_69 = 0 ; V_69 < V_119 ; V_69 ++ ) {
if ( V_22 -> V_23 . V_122 [ V_69 ] ) {
F_35 ( V_9 , V_69 , V_22 -> V_23 . V_122 [ V_69 ] ) ;
V_121 = 1 ;
}
}
if ( V_121 )
F_36 ( V_9 , V_120 ) ;
else
F_37 ( V_9 , V_120 ) ;
if ( F_7 ( V_9 , V_75 , V_22 -> V_23 . V_76 ) )
goto V_12;
if ( F_7 ( V_9 , V_78 ,
V_22 -> V_23 . V_79 ) )
goto V_12;
if ( V_22 -> V_123 &&
F_7 ( V_9 , V_81 ,
V_22 -> V_123 -> V_65 -> V_47 ) )
goto V_12;
if ( F_5 ( V_9 , V_84 ,
V_22 -> V_23 . V_85 ) )
goto V_12;
if ( F_5 ( V_9 , V_87 ,
V_22 -> V_23 . V_88 ) )
goto V_12;
if ( F_5 ( V_9 , V_90 ,
V_22 -> V_23 . V_124 ) )
goto V_12;
if ( F_7 ( V_9 , V_93 ,
V_22 -> V_23 . V_94 ) )
goto V_12;
if ( F_5 ( V_9 , V_96 ,
V_22 -> V_23 . V_97 ) )
goto V_12;
if ( F_5 ( V_9 , V_99 ,
V_22 -> V_23 . V_100 ) )
goto V_12;
if ( F_7 ( V_9 , V_102 ,
V_22 -> V_23 . V_103 ) )
goto V_12;
if ( F_7 ( V_9 , V_105 ,
V_22 -> V_23 . V_106 ) )
goto V_12;
V_109 = V_22 -> V_23 . V_109 ;
if ( F_7 ( V_9 , V_108 ,
V_109 ) )
goto V_12;
if ( F_5 ( V_9 , V_111 ,
V_22 -> V_23 . V_125 ) )
goto V_12;
if ( F_5 ( V_9 , V_114 ,
V_22 -> V_23 . V_115 ) )
goto V_12;
if ( V_22 -> V_23 . V_24 == V_25 ) {
struct V_126 V_127 ;
if ( ! F_38 ( V_22 , & V_127 ) ) {
struct V_32 * V_128 ;
V_128 = F_34 ( V_9 , V_129 ) ;
if ( ! V_128 )
goto V_12;
if ( F_9 ( V_9 , V_130 ,
V_127 . V_131 ) )
goto V_12;
if ( F_9 ( V_9 , V_132 ,
V_127 . V_133 ) )
goto V_12;
if ( F_9 ( V_9 , V_134 ,
V_127 . V_135 ) )
goto V_12;
if ( F_9 ( V_9 , V_136 ,
V_127 . V_137 ) )
goto V_12;
if ( F_8 ( V_9 , V_138 ,
sizeof( V_127 . V_139 ) ,
& V_127 . V_139 ) )
goto V_12;
F_36 ( V_9 , V_128 ) ;
}
}
return 0 ;
V_12:
return - V_31 ;
}
int T_3 F_39 ( void )
{
return F_40 ( & V_140 ) ;
}
void F_41 ( void )
{
F_42 ( & V_140 ) ;
}
