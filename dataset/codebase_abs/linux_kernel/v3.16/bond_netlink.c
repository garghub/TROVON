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
struct V_30 * V_31 [] , struct V_30 * V_32 [] )
{
struct V_37 * V_22 = F_17 ( V_2 ) ;
struct V_38 V_39 ;
int V_40 = 0 ;
int V_41 ;
if ( ! V_32 )
return 0 ;
if ( V_32 [ V_42 ] ) {
int V_43 = F_18 ( V_32 [ V_42 ] ) ;
F_19 ( & V_39 , V_43 ) ;
V_41 = F_20 ( V_22 , V_44 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_45 ] ) {
int V_46 = F_21 ( V_32 [ V_45 ] ) ;
struct V_1 * V_3 ;
char * V_47 = L_1 ;
if ( V_46 != 0 ) {
V_3 = F_22 ( F_23 ( V_2 ) ,
V_46 ) ;
if ( ! V_3 )
return - V_48 ;
V_47 = V_3 -> V_49 ;
}
F_24 ( & V_39 , V_47 ) ;
V_41 = F_20 ( V_22 , V_50 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_51 ] ) {
V_40 = F_21 ( V_32 [ V_51 ] ) ;
F_19 ( & V_39 , V_40 ) ;
V_41 = F_20 ( V_22 , V_52 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_53 ] ) {
int V_54 = F_21 ( V_32 [ V_53 ] ) ;
F_19 ( & V_39 , V_54 ) ;
V_41 = F_20 ( V_22 , V_55 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_56 ] ) {
int V_57 = F_21 ( V_32 [ V_56 ] ) ;
F_19 ( & V_39 , V_57 ) ;
V_41 = F_20 ( V_22 , V_58 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_59 ] ) {
int V_60 = F_18 ( V_32 [ V_59 ] ) ;
F_19 ( & V_39 , V_60 ) ;
V_41 = F_20 ( V_22 , V_61 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_62 ] ) {
int V_63 = F_21 ( V_32 [ V_62 ] ) ;
if ( V_63 && V_40 ) {
F_25 ( L_2 ,
V_22 -> V_64 -> V_49 ) ;
return - V_35 ;
}
F_19 ( & V_39 , V_63 ) ;
V_41 = F_20 ( V_22 , V_65 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_66 ] ) {
struct V_30 * V_67 ;
int V_68 = 0 , V_69 ;
F_26 ( V_22 ) ;
F_27 (attr, data[IFLA_BOND_ARP_IP_TARGET], rem) {
T_2 V_70 = F_28 ( V_67 ) ;
F_19 ( & V_39 , ( V_71 V_72 ) V_70 ) ;
V_41 = F_20 ( V_22 , V_73 ,
& V_39 ) ;
if ( V_41 )
break;
V_68 ++ ;
}
if ( V_68 == 0 && V_22 -> V_74 . V_63 )
F_29 ( L_3 ,
V_22 -> V_64 -> V_49 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_75 ] ) {
int V_76 = F_21 ( V_32 [ V_75 ] ) ;
if ( V_76 && V_40 ) {
F_25 ( L_4 ,
V_22 -> V_64 -> V_49 ) ;
return - V_35 ;
}
F_19 ( & V_39 , V_76 ) ;
V_41 = F_20 ( V_22 , V_77 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_78 ] ) {
int V_79 =
F_21 ( V_32 [ V_78 ] ) ;
F_19 ( & V_39 , V_79 ) ;
V_41 = F_20 ( V_22 , V_80 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_81 ] ) {
int V_46 = F_21 ( V_32 [ V_81 ] ) ;
struct V_1 * V_64 ;
char * V_82 = L_1 ;
V_64 = F_22 ( F_23 ( V_2 ) , V_46 ) ;
if ( V_64 )
V_82 = V_64 -> V_49 ;
F_24 ( & V_39 , V_82 ) ;
V_41 = F_20 ( V_22 , V_83 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_84 ] ) {
int V_85 =
F_18 ( V_32 [ V_84 ] ) ;
F_19 ( & V_39 , V_85 ) ;
V_41 = F_20 ( V_22 , V_86 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_87 ] ) {
int V_88 =
F_18 ( V_32 [ V_87 ] ) ;
F_19 ( & V_39 , V_88 ) ;
V_41 = F_20 ( V_22 , V_89 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_90 ] ) {
int V_91 =
F_18 ( V_32 [ V_90 ] ) ;
F_19 ( & V_39 , V_91 ) ;
V_41 = F_20 ( V_22 , V_92 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_93 ] ) {
int V_94 =
F_21 ( V_32 [ V_93 ] ) ;
F_19 ( & V_39 , V_94 ) ;
V_41 = F_20 ( V_22 , V_95 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_96 ] ) {
int V_97 =
F_18 ( V_32 [ V_96 ] ) ;
F_19 ( & V_39 , V_97 ) ;
V_41 = F_20 ( V_22 , V_98 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_99 ] ) {
int V_100 =
F_18 ( V_32 [ V_99 ] ) ;
F_19 ( & V_39 , V_100 ) ;
V_41 = F_20 ( V_22 , V_101 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_102 ] ) {
int V_103 =
F_21 ( V_32 [ V_102 ] ) ;
F_19 ( & V_39 , V_103 ) ;
V_41 = F_20 ( V_22 , V_104 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_105 ] ) {
int V_106 =
F_21 ( V_32 [ V_105 ] ) ;
F_19 ( & V_39 , V_106 ) ;
V_41 = F_20 ( V_22 , V_107 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_108 ] ) {
int V_109 =
F_21 ( V_32 [ V_108 ] ) ;
F_19 ( & V_39 , V_109 ) ;
V_41 = F_20 ( V_22 , V_110 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_111 ] ) {
int V_112 =
F_18 ( V_32 [ V_111 ] ) ;
F_19 ( & V_39 , V_112 ) ;
V_41 = F_20 ( V_22 , V_113 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_32 [ V_114 ] ) {
int V_115 =
F_18 ( V_32 [ V_114 ] ) ;
F_19 ( & V_39 , V_115 ) ;
V_41 = F_20 ( V_22 , V_116 , & V_39 ) ;
if ( V_41 )
return V_41 ;
}
return 0 ;
}
static int F_30 ( struct V_117 * V_118 , struct V_1 * V_2 ,
struct V_30 * V_31 [] , struct V_30 * V_32 [] )
{
int V_41 ;
V_41 = F_16 ( V_2 , V_31 , V_32 ) ;
if ( V_41 < 0 )
return V_41 ;
return F_31 ( V_2 ) ;
}
static T_1 F_32 ( const struct V_1 * V_2 )
{
return F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( V_4 ) ) +
F_2 ( sizeof( V_5 ) ) +
F_2 ( sizeof( struct V_30 ) ) +
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
F_2 ( sizeof( struct V_30 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( sizeof( V_7 ) ) +
F_2 ( V_34 ) +
0 ;
}
static int F_33 ( struct V_8 * V_9 ,
const struct V_1 * V_2 )
{
struct V_37 * V_22 = F_17 ( V_2 ) ;
struct V_1 * V_3 = F_34 ( V_22 ) ;
struct V_30 * V_120 ;
unsigned int V_109 ;
int V_68 , V_121 ;
if ( F_5 ( V_9 , V_42 , F_10 ( V_22 ) ) )
goto V_12;
if ( V_3 &&
F_7 ( V_9 , V_45 , V_3 -> V_46 ) )
goto V_12;
if ( F_7 ( V_9 , V_51 , V_22 -> V_74 . V_40 ) )
goto V_12;
if ( F_7 ( V_9 , V_53 ,
V_22 -> V_74 . V_54 * V_22 -> V_74 . V_40 ) )
goto V_12;
if ( F_7 ( V_9 , V_56 ,
V_22 -> V_74 . V_57 * V_22 -> V_74 . V_40 ) )
goto V_12;
if ( F_5 ( V_9 , V_59 , V_22 -> V_74 . V_60 ) )
goto V_12;
if ( F_7 ( V_9 , V_62 , V_22 -> V_74 . V_63 ) )
goto V_12;
V_120 = F_35 ( V_9 , V_66 ) ;
if ( ! V_120 )
goto V_12;
V_121 = 0 ;
for ( V_68 = 0 ; V_68 < V_119 ; V_68 ++ ) {
if ( V_22 -> V_74 . V_122 [ V_68 ] ) {
F_36 ( V_9 , V_68 , V_22 -> V_74 . V_122 [ V_68 ] ) ;
V_121 = 1 ;
}
}
if ( V_121 )
F_37 ( V_9 , V_120 ) ;
else
F_38 ( V_9 , V_120 ) ;
if ( F_7 ( V_9 , V_75 , V_22 -> V_74 . V_76 ) )
goto V_12;
if ( F_7 ( V_9 , V_78 ,
V_22 -> V_74 . V_79 ) )
goto V_12;
if ( V_22 -> V_123 &&
F_7 ( V_9 , V_81 ,
V_22 -> V_123 -> V_64 -> V_46 ) )
goto V_12;
if ( F_5 ( V_9 , V_84 ,
V_22 -> V_74 . V_85 ) )
goto V_12;
if ( F_5 ( V_9 , V_87 ,
V_22 -> V_74 . V_88 ) )
goto V_12;
if ( F_5 ( V_9 , V_90 ,
V_22 -> V_74 . V_124 ) )
goto V_12;
if ( F_7 ( V_9 , V_93 ,
V_22 -> V_74 . V_94 ) )
goto V_12;
if ( F_5 ( V_9 , V_96 ,
V_22 -> V_74 . V_97 ) )
goto V_12;
if ( F_5 ( V_9 , V_99 ,
V_22 -> V_74 . V_100 ) )
goto V_12;
if ( F_7 ( V_9 , V_102 ,
V_22 -> V_74 . V_103 ) )
goto V_12;
if ( F_7 ( V_9 , V_105 ,
V_22 -> V_74 . V_106 ) )
goto V_12;
V_109 = V_22 -> V_74 . V_109 ;
if ( F_7 ( V_9 , V_108 ,
V_109 ) )
goto V_12;
if ( F_5 ( V_9 , V_111 ,
V_22 -> V_74 . V_125 ) )
goto V_12;
if ( F_5 ( V_9 , V_114 ,
V_22 -> V_74 . V_115 ) )
goto V_12;
if ( F_10 ( V_22 ) == V_23 ) {
struct V_126 V_127 ;
if ( ! F_39 ( V_22 , & V_127 ) ) {
struct V_30 * V_128 ;
V_128 = F_35 ( V_9 , V_129 ) ;
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
F_37 ( V_9 , V_128 ) ;
}
}
return 0 ;
V_12:
return - V_29 ;
}
int T_3 F_40 ( void )
{
return F_41 ( & V_140 ) ;
}
void F_42 ( void )
{
F_43 ( & V_140 ) ;
}
