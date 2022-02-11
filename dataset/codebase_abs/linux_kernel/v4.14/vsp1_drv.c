static T_1 F_1 ( int V_1 , void * V_2 )
{
T_2 V_3 = V_4 | V_5 ;
struct V_6 * V_7 = V_2 ;
T_1 V_8 = V_9 ;
unsigned int V_10 ;
T_2 V_11 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 = V_7 -> V_15 [ V_10 ] ;
if ( V_15 == NULL )
continue;
V_11 = F_2 ( V_7 , F_3 ( V_10 ) ) ;
F_4 ( V_7 , F_3 ( V_10 ) , ~ V_11 & V_3 ) ;
if ( V_11 & V_4 ) {
F_5 ( V_15 -> V_16 ) ;
V_8 = V_17 ;
}
}
return V_8 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = & V_19 -> V_22 . V_21 ;
struct V_18 * V_23 ;
unsigned int V_24 ;
int V_8 ;
F_7 (source, &vsp1->entities, list_dev) {
T_2 V_25 ;
if ( V_23 -> type == V_19 -> type )
continue;
if ( V_23 -> type == V_26 ||
V_23 -> type == V_27 ||
V_23 -> type == V_28 ||
V_23 -> type == V_29 )
continue;
V_25 = V_23 -> type == V_30 &&
V_19 -> type == V_29 &&
V_23 -> V_31 == V_19 -> V_31
? V_32 : 0 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_33 ; ++ V_24 ) {
if ( ! ( V_21 -> V_34 [ V_24 ] . V_25 & V_35 ) )
continue;
V_8 = F_8 ( & V_23 -> V_22 . V_21 ,
V_23 -> V_36 ,
V_21 , V_24 , V_25 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_25 & V_32 )
V_23 -> V_19 = V_19 ;
}
}
return 0 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_18 * V_21 ;
unsigned int V_10 ;
int V_8 ;
F_7 (entity, &vsp1->entities, list_dev) {
if ( V_21 -> type == V_28 ||
V_21 -> type == V_30 )
continue;
V_8 = F_6 ( V_7 , V_21 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_7 -> V_37 ) {
V_8 = F_8 ( & V_7 -> V_37 -> V_38 . V_21 . V_22 . V_21 ,
V_39 ,
& V_7 -> V_37 -> V_38 . V_40 . V_21 , 0 ,
V_32 |
V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_7 -> V_42 ) {
V_8 = F_8 ( & V_7 -> V_42 -> V_38 . V_21 . V_22 . V_21 ,
V_39 ,
& V_7 -> V_42 -> V_38 . V_40 . V_21 , 0 ,
V_32 |
V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_43 ; ++ V_10 ) {
if ( ! V_7 -> V_44 [ V_10 ] )
continue;
V_8 = F_8 ( & V_7 -> V_15 [ V_10 ] -> V_21 . V_22 . V_21 ,
V_45 ,
& V_7 -> V_44 [ V_10 ] -> V_21 . V_22 . V_21 ,
V_46 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_47 ; ++ V_10 ) {
struct V_14 * V_48 = V_7 -> V_48 [ V_10 ] ;
V_8 = F_8 ( & V_48 -> V_40 -> V_40 . V_21 , 0 ,
& V_48 -> V_21 . V_22 . V_21 ,
V_49 ,
V_32 |
V_41 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 = V_7 -> V_15 [ V_10 ] ;
V_8 = F_8 ( & V_15 -> V_21 . V_22 . V_21 ,
V_45 ,
& V_15 -> V_40 -> V_40 . V_21 , 0 ,
V_41 |
V_32 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_18 * V_21 , * V_50 ;
struct V_51 * V_40 , * V_52 ;
F_11 (entity, _entity, &vsp1->entities, list_dev) {
F_12 ( & V_21 -> V_53 ) ;
F_13 ( V_21 ) ;
}
F_11 (video, _video, &vsp1->videos, list) {
F_12 ( & V_40 -> V_54 ) ;
F_14 ( V_40 ) ;
}
F_15 ( & V_7 -> V_55 ) ;
if ( V_7 -> V_12 -> V_56 )
F_16 ( & V_7 -> V_57 ) ;
F_17 ( & V_7 -> V_57 ) ;
if ( ! V_7 -> V_12 -> V_56 )
F_18 ( V_7 ) ;
}
static int F_19 ( struct V_6 * V_7 )
{
struct V_58 * V_59 = & V_7 -> V_57 ;
struct V_60 * V_61 = & V_7 -> V_55 ;
struct V_18 * V_21 ;
unsigned int V_10 ;
int V_8 ;
V_59 -> V_62 = V_7 -> V_62 ;
V_59 -> V_63 = V_7 -> V_64 ;
F_20 ( V_59 -> V_65 , V_7 -> V_12 -> V_65 , sizeof( V_59 -> V_65 ) ) ;
snprintf ( V_59 -> V_66 , sizeof( V_59 -> V_66 ) , L_1 ,
F_21 ( V_59 -> V_62 ) ) ;
F_22 ( V_59 ) ;
V_7 -> V_67 . V_68 = V_69 ;
if ( V_7 -> V_12 -> V_56 )
V_7 -> V_67 . V_70 = V_71 ;
V_61 -> V_59 = V_59 ;
V_8 = F_23 ( V_7 -> V_62 , V_61 ) ;
if ( V_8 < 0 ) {
F_24 ( V_7 -> V_62 , L_2 ,
V_8 ) ;
goto V_72;
}
if ( V_7 -> V_12 -> V_73 & V_74 ) {
V_7 -> V_75 = F_25 ( V_7 , V_76 ) ;
if ( F_26 ( V_7 -> V_75 ) ) {
V_8 = F_27 ( V_7 -> V_75 ) ;
goto V_72;
}
F_28 ( & V_7 -> V_75 -> V_21 . V_53 , & V_7 -> V_77 ) ;
}
if ( V_7 -> V_12 -> V_73 & V_78 ) {
V_7 -> V_79 = F_25 ( V_7 , V_80 ) ;
if ( F_26 ( V_7 -> V_79 ) ) {
V_8 = F_27 ( V_7 -> V_79 ) ;
goto V_72;
}
F_28 ( & V_7 -> V_79 -> V_21 . V_53 , & V_7 -> V_77 ) ;
}
if ( V_7 -> V_12 -> V_73 & V_81 ) {
V_7 -> V_82 = F_29 ( V_7 ) ;
if ( F_26 ( V_7 -> V_82 ) ) {
V_8 = F_27 ( V_7 -> V_82 ) ;
goto V_72;
}
F_28 ( & V_7 -> V_82 -> V_21 . V_53 , & V_7 -> V_77 ) ;
}
V_7 -> V_83 = F_30 ( V_7 , true ) ;
if ( F_26 ( V_7 -> V_83 ) ) {
V_8 = F_27 ( V_7 -> V_83 ) ;
goto V_72;
}
F_28 ( & V_7 -> V_83 -> V_21 . V_53 , & V_7 -> V_77 ) ;
V_7 -> V_84 = F_30 ( V_7 , false ) ;
if ( F_26 ( V_7 -> V_84 ) ) {
V_8 = F_27 ( V_7 -> V_84 ) ;
goto V_72;
}
F_28 ( & V_7 -> V_84 -> V_21 . V_53 , & V_7 -> V_77 ) ;
if ( V_7 -> V_12 -> V_73 & V_85 && V_7 -> V_12 -> V_56 ) {
V_7 -> V_37 = F_31 ( V_7 ) ;
if ( F_26 ( V_7 -> V_37 ) ) {
V_8 = F_27 ( V_7 -> V_37 ) ;
goto V_72;
}
F_28 ( & V_7 -> V_37 -> V_38 . V_21 . V_53 ,
& V_7 -> V_77 ) ;
}
if ( V_7 -> V_12 -> V_73 & V_86 && V_7 -> V_12 -> V_56 ) {
V_7 -> V_42 = F_32 ( V_7 ) ;
if ( F_26 ( V_7 -> V_42 ) ) {
V_8 = F_27 ( V_7 -> V_42 ) ;
goto V_72;
}
F_28 ( & V_7 -> V_42 -> V_38 . V_21 . V_53 ,
& V_7 -> V_77 ) ;
}
if ( ! V_7 -> V_12 -> V_56 ) {
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_43 ; ++ V_10 ) {
struct V_87 * V_44 ;
V_44 = F_33 ( V_7 , V_10 ) ;
if ( F_26 ( V_44 ) ) {
V_8 = F_27 ( V_44 ) ;
goto V_72;
}
V_7 -> V_44 [ V_10 ] = V_44 ;
F_28 ( & V_44 -> V_21 . V_53 , & V_7 -> V_77 ) ;
}
}
if ( V_7 -> V_12 -> V_73 & V_88 ) {
V_7 -> V_89 = F_34 ( V_7 ) ;
if ( F_26 ( V_7 -> V_89 ) ) {
V_8 = F_27 ( V_7 -> V_89 ) ;
goto V_72;
}
F_28 ( & V_7 -> V_89 -> V_21 . V_53 , & V_7 -> V_77 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_47 ; ++ V_10 ) {
struct V_14 * V_48 ;
V_48 = F_35 ( V_7 , V_10 ) ;
if ( F_26 ( V_48 ) ) {
V_8 = F_27 ( V_48 ) ;
goto V_72;
}
V_7 -> V_48 [ V_10 ] = V_48 ;
F_28 ( & V_48 -> V_21 . V_53 , & V_7 -> V_77 ) ;
if ( V_7 -> V_12 -> V_56 ) {
struct V_51 * V_40 = F_36 ( V_7 , V_48 ) ;
if ( F_26 ( V_40 ) ) {
V_8 = F_27 ( V_40 ) ;
goto V_72;
}
F_28 ( & V_40 -> V_54 , & V_7 -> V_90 ) ;
}
}
if ( V_7 -> V_12 -> V_73 & V_91 ) {
V_7 -> V_92 = F_37 ( V_7 ) ;
if ( F_26 ( V_7 -> V_92 ) ) {
V_8 = F_27 ( V_7 -> V_92 ) ;
goto V_72;
}
F_28 ( & V_7 -> V_92 -> V_21 . V_53 , & V_7 -> V_77 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_93 ; ++ V_10 ) {
struct V_94 * V_95 ;
V_95 = F_38 ( V_7 , V_10 ) ;
if ( F_26 ( V_95 ) ) {
V_8 = F_27 ( V_95 ) ;
goto V_72;
}
V_7 -> V_95 [ V_10 ] = V_95 ;
F_28 ( & V_95 -> V_21 . V_53 , & V_7 -> V_77 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 ;
V_15 = F_39 ( V_7 , V_10 ) ;
if ( F_26 ( V_15 ) ) {
V_8 = F_27 ( V_15 ) ;
goto V_72;
}
V_7 -> V_15 [ V_10 ] = V_15 ;
F_28 ( & V_15 -> V_21 . V_53 , & V_7 -> V_77 ) ;
if ( V_7 -> V_12 -> V_56 ) {
struct V_51 * V_40 = F_36 ( V_7 , V_15 ) ;
if ( F_26 ( V_40 ) ) {
V_8 = F_27 ( V_40 ) ;
goto V_72;
}
F_28 ( & V_40 -> V_54 , & V_7 -> V_90 ) ;
}
}
F_7 (entity, &vsp1->entities, list_dev) {
V_8 = F_40 ( & V_7 -> V_55 ,
& V_21 -> V_22 ) ;
if ( V_8 < 0 )
goto V_72;
}
if ( V_7 -> V_12 -> V_56 ) {
V_8 = F_9 ( V_7 ) ;
if ( V_8 < 0 )
goto V_72;
V_8 = F_41 ( & V_7 -> V_55 ) ;
if ( V_8 < 0 )
goto V_72;
V_8 = F_42 ( V_59 ) ;
} else {
V_8 = F_43 ( V_7 ) ;
}
V_72:
if ( V_8 < 0 )
F_10 ( V_7 ) ;
return V_8 ;
}
int F_44 ( struct V_6 * V_7 , unsigned int V_31 )
{
unsigned int V_96 ;
T_2 V_11 ;
V_11 = F_2 ( V_7 , V_97 ) ;
if ( ! ( V_11 & F_45 ( V_31 ) ) )
return 0 ;
F_4 ( V_7 , V_98 , F_46 ( V_31 ) ) ;
for ( V_96 = 10 ; V_96 > 0 ; -- V_96 ) {
V_11 = F_2 ( V_7 , V_97 ) ;
if ( ! ( V_11 & F_45 ( V_31 ) ) )
break;
F_47 ( 1000 , 2000 ) ;
}
if ( ! V_96 ) {
F_24 ( V_7 -> V_62 , L_3 , V_31 ) ;
return - V_99 ;
}
return 0 ;
}
static int F_48 ( struct V_6 * V_7 )
{
unsigned int V_10 ;
int V_8 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
V_8 = F_44 ( V_7 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
}
F_4 ( V_7 , V_100 , ( 8 << V_101 ) |
( 8 << V_102 ) ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_47 ; ++ V_10 )
F_4 ( V_7 , F_49 ( V_10 ) , V_103 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_93 ; ++ V_10 )
F_4 ( V_7 , F_50 ( V_10 ) , V_103 ) ;
F_4 ( V_7 , V_104 , V_103 ) ;
F_4 ( V_7 , V_105 , V_103 ) ;
F_4 ( V_7 , V_106 , V_103 ) ;
F_4 ( V_7 , V_107 , V_103 ) ;
F_4 ( V_7 , V_108 , V_103 ) ;
F_4 ( V_7 , V_109 , V_103 ) ;
if ( V_7 -> V_12 -> V_73 & V_74 )
F_4 ( V_7 , V_110 , V_103 ) ;
F_4 ( V_7 , V_111 , ( 7 << V_112 ) |
( V_103 << V_113 ) ) ;
F_4 ( V_7 , V_114 , ( 7 << V_112 ) |
( V_103 << V_113 ) ) ;
F_51 ( V_7 ) ;
return 0 ;
}
int F_52 ( struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_53 ( V_7 -> V_62 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
void F_54 ( struct V_6 * V_7 )
{
F_55 ( V_7 -> V_62 ) ;
}
static int T_3 F_56 ( struct V_115 * V_62 )
{
struct V_6 * V_7 = F_57 ( V_62 ) ;
F_58 ( V_7 ) ;
F_59 ( V_7 -> V_62 ) ;
return 0 ;
}
static int T_3 F_60 ( struct V_115 * V_62 )
{
struct V_6 * V_7 = F_57 ( V_62 ) ;
F_61 ( V_7 -> V_62 ) ;
F_62 ( V_7 ) ;
return 0 ;
}
static int T_3 F_63 ( struct V_115 * V_62 )
{
struct V_6 * V_7 = F_57 ( V_62 ) ;
F_64 ( V_7 -> V_116 ) ;
return 0 ;
}
static int T_3 F_65 ( struct V_115 * V_62 )
{
struct V_6 * V_7 = F_57 ( V_62 ) ;
int V_8 ;
if ( V_7 -> V_12 ) {
V_8 = F_48 ( V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return F_66 ( V_7 -> V_116 ) ;
}
static int F_67 ( struct V_117 * V_118 )
{
struct V_6 * V_7 ;
struct V_119 * V_120 ;
struct V_121 * V_1 ;
struct V_121 * V_122 ;
unsigned int V_10 ;
int V_8 ;
V_7 = F_68 ( & V_118 -> V_62 , sizeof( * V_7 ) , V_123 ) ;
if ( V_7 == NULL )
return - V_124 ;
V_7 -> V_62 = & V_118 -> V_62 ;
F_69 ( & V_7 -> V_77 ) ;
F_69 ( & V_7 -> V_90 ) ;
F_70 ( V_118 , V_7 ) ;
V_122 = F_71 ( V_118 , V_125 , 0 ) ;
V_7 -> V_126 = F_72 ( & V_118 -> V_62 , V_122 ) ;
if ( F_26 ( V_7 -> V_126 ) )
return F_27 ( V_7 -> V_126 ) ;
V_1 = F_71 ( V_118 , V_127 , 0 ) ;
if ( ! V_1 ) {
F_24 ( & V_118 -> V_62 , L_4 ) ;
return - V_128 ;
}
V_8 = F_73 ( & V_118 -> V_62 , V_1 -> V_129 , F_1 ,
V_130 , F_21 ( & V_118 -> V_62 ) , V_7 ) ;
if ( V_8 < 0 ) {
F_24 ( & V_118 -> V_62 , L_5 ) ;
return V_8 ;
}
V_120 = F_74 ( V_118 -> V_62 . V_131 , L_6 , 0 ) ;
if ( V_120 ) {
V_7 -> V_116 = F_75 ( V_120 ) ;
F_76 ( V_120 ) ;
if ( F_26 ( V_7 -> V_116 ) ) {
F_77 ( & V_118 -> V_62 , L_7 ,
F_27 ( V_7 -> V_116 ) ) ;
return F_27 ( V_7 -> V_116 ) ;
}
V_7 -> V_132 = F_78 ( V_7 -> V_116 ) ;
} else {
V_7 -> V_132 = V_7 -> V_62 ;
}
F_79 ( & V_118 -> V_62 ) ;
V_8 = F_53 ( & V_118 -> V_62 ) ;
if ( V_8 < 0 )
goto V_72;
V_7 -> V_64 = F_2 ( V_7 , V_133 ) ;
F_55 ( & V_118 -> V_62 ) ;
for ( V_10 = 0 ; V_10 < F_80 ( V_134 ) ; ++ V_10 ) {
if ( ( V_7 -> V_64 & V_135 ) ==
V_134 [ V_10 ] . V_64 ) {
V_7 -> V_12 = & V_134 [ V_10 ] ;
break;
}
}
if ( ! V_7 -> V_12 ) {
F_24 ( & V_118 -> V_62 , L_8 ,
V_7 -> V_64 ) ;
V_8 = - V_136 ;
goto V_72;
}
F_77 ( & V_118 -> V_62 , L_9 , V_7 -> V_64 ) ;
V_8 = F_19 ( V_7 ) ;
if ( V_8 < 0 ) {
F_24 ( & V_118 -> V_62 , L_10 ) ;
goto V_72;
}
V_72:
if ( V_8 )
F_81 ( & V_118 -> V_62 ) ;
return V_8 ;
}
static int F_82 ( struct V_117 * V_118 )
{
struct V_6 * V_7 = F_83 ( V_118 ) ;
F_10 ( V_7 ) ;
F_84 ( V_7 -> V_116 ) ;
F_81 ( & V_118 -> V_62 ) ;
return 0 ;
}
