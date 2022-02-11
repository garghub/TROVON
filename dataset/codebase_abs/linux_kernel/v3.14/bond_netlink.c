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
F_18 ( & V_41 , V_71 ) ;
V_43 = F_19 ( V_22 , V_72 ,
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
if ( V_34 [ V_73 ] ) {
int V_74 = F_20 ( V_34 [ V_73 ] ) ;
if ( V_74 && V_42 ) {
F_24 ( L_4 ,
V_22 -> V_65 -> V_50 ) ;
return - V_37 ;
}
F_18 ( & V_41 , V_74 ) ;
V_43 = F_19 ( V_22 , V_75 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_76 ] ) {
int V_77 =
F_20 ( V_34 [ V_76 ] ) ;
F_18 ( & V_41 , V_77 ) ;
V_43 = F_19 ( V_22 , V_78 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_79 ] ) {
int V_47 = F_20 ( V_34 [ V_79 ] ) ;
struct V_1 * V_65 ;
char * V_80 = L_1 ;
V_65 = F_21 ( F_22 ( V_2 ) , V_47 ) ;
if ( V_65 )
V_80 = V_65 -> V_50 ;
F_23 ( & V_41 , V_80 ) ;
V_43 = F_19 ( V_22 , V_81 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_82 ] ) {
int V_83 =
F_17 ( V_34 [ V_82 ] ) ;
F_18 ( & V_41 , V_83 ) ;
V_43 = F_19 ( V_22 , V_84 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_85 ] ) {
int V_86 =
F_17 ( V_34 [ V_85 ] ) ;
F_18 ( & V_41 , V_86 ) ;
V_43 = F_19 ( V_22 , V_87 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_88 ] ) {
int V_89 =
F_17 ( V_34 [ V_88 ] ) ;
F_18 ( & V_41 , V_89 ) ;
V_43 = F_19 ( V_22 , V_90 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_91 ] ) {
int V_92 =
F_20 ( V_34 [ V_91 ] ) ;
F_18 ( & V_41 , V_92 ) ;
V_43 = F_19 ( V_22 , V_93 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_94 ] ) {
int V_95 =
F_17 ( V_34 [ V_94 ] ) ;
F_18 ( & V_41 , V_95 ) ;
V_43 = F_19 ( V_22 , V_96 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_97 ] ) {
int V_98 =
F_17 ( V_34 [ V_97 ] ) ;
F_18 ( & V_41 , V_98 ) ;
V_43 = F_19 ( V_22 , V_99 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_100 ] ) {
int V_101 =
F_20 ( V_34 [ V_100 ] ) ;
F_18 ( & V_41 , V_101 ) ;
V_43 = F_19 ( V_22 , V_102 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_103 ] ) {
int V_104 =
F_20 ( V_34 [ V_103 ] ) ;
F_18 ( & V_41 , V_104 ) ;
V_43 = F_19 ( V_22 , V_105 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_106 ] ) {
int V_107 =
F_20 ( V_34 [ V_106 ] ) ;
F_18 ( & V_41 , V_107 ) ;
V_43 = F_19 ( V_22 , V_108 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_109 ] ) {
int V_110 =
F_17 ( V_34 [ V_109 ] ) ;
F_18 ( & V_41 , V_110 ) ;
V_43 = F_19 ( V_22 , V_111 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
if ( V_34 [ V_112 ] ) {
int V_113 =
F_17 ( V_34 [ V_112 ] ) ;
F_18 ( & V_41 , V_113 ) ;
V_43 = F_19 ( V_22 , V_114 , & V_41 ) ;
if ( V_43 )
return V_43 ;
}
return 0 ;
}
static int F_29 ( struct V_115 * V_116 , struct V_1 * V_2 ,
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
F_2 ( sizeof( V_5 ) ) * V_117 +
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
struct V_32 * V_118 ;
unsigned int V_107 ;
int V_69 , V_119 ;
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
V_118 = F_34 ( V_9 , V_67 ) ;
if ( ! V_118 )
goto V_12;
V_119 = 0 ;
for ( V_69 = 0 ; V_69 < V_117 ; V_69 ++ ) {
if ( V_22 -> V_23 . V_120 [ V_69 ] ) {
F_35 ( V_9 , V_69 , V_22 -> V_23 . V_120 [ V_69 ] ) ;
V_119 = 1 ;
}
}
if ( V_119 )
F_36 ( V_9 , V_118 ) ;
else
F_37 ( V_9 , V_118 ) ;
if ( F_7 ( V_9 , V_73 , V_22 -> V_23 . V_74 ) )
goto V_12;
if ( F_7 ( V_9 , V_76 ,
V_22 -> V_23 . V_77 ) )
goto V_12;
if ( V_22 -> V_121 &&
F_7 ( V_9 , V_79 ,
V_22 -> V_121 -> V_65 -> V_47 ) )
goto V_12;
if ( F_5 ( V_9 , V_82 ,
V_22 -> V_23 . V_83 ) )
goto V_12;
if ( F_5 ( V_9 , V_85 ,
V_22 -> V_23 . V_86 ) )
goto V_12;
if ( F_5 ( V_9 , V_88 ,
V_22 -> V_23 . V_122 ) )
goto V_12;
if ( F_7 ( V_9 , V_91 ,
V_22 -> V_23 . V_92 ) )
goto V_12;
if ( F_5 ( V_9 , V_94 ,
V_22 -> V_23 . V_95 ) )
goto V_12;
if ( F_5 ( V_9 , V_97 ,
V_22 -> V_23 . V_98 ) )
goto V_12;
if ( F_7 ( V_9 , V_100 ,
V_22 -> V_23 . V_101 ) )
goto V_12;
if ( F_7 ( V_9 , V_103 ,
V_22 -> V_23 . V_104 ) )
goto V_12;
V_107 = V_22 -> V_23 . V_107 ;
if ( F_7 ( V_9 , V_106 ,
V_107 ) )
goto V_12;
if ( F_5 ( V_9 , V_109 ,
V_22 -> V_23 . V_123 ) )
goto V_12;
if ( F_5 ( V_9 , V_112 ,
V_22 -> V_23 . V_113 ) )
goto V_12;
if ( V_22 -> V_23 . V_24 == V_25 ) {
struct V_124 V_125 ;
if ( ! F_38 ( V_22 , & V_125 ) ) {
struct V_32 * V_126 ;
V_126 = F_34 ( V_9 , V_127 ) ;
if ( ! V_126 )
goto V_12;
if ( F_9 ( V_9 , V_128 ,
V_125 . V_129 ) )
goto V_12;
if ( F_9 ( V_9 , V_130 ,
V_125 . V_131 ) )
goto V_12;
if ( F_9 ( V_9 , V_132 ,
V_125 . V_133 ) )
goto V_12;
if ( F_9 ( V_9 , V_134 ,
V_125 . V_135 ) )
goto V_12;
if ( F_8 ( V_9 , V_136 ,
sizeof( V_125 . V_137 ) ,
& V_125 . V_137 ) )
goto V_12;
F_36 ( V_9 , V_126 ) ;
}
}
return 0 ;
V_12:
return - V_31 ;
}
int T_3 F_39 ( void )
{
return F_40 ( & V_138 ) ;
}
void F_41 ( void )
{
F_42 ( & V_138 ) ;
}
