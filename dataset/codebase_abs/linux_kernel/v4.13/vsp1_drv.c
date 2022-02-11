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
V_11 = F_2 ( V_7 , V_18 ) ;
F_4 ( V_7 , V_18 , ~ V_11 & V_19 ) ;
if ( V_11 & V_19 ) {
F_6 ( V_7 ) ;
V_8 = V_17 ;
}
return V_8 ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 = & V_21 -> V_24 . V_23 ;
struct V_20 * V_25 ;
unsigned int V_26 ;
int V_8 ;
F_8 (source, &vsp1->entities, list_dev) {
T_2 V_27 ;
if ( V_25 -> type == V_21 -> type )
continue;
if ( V_25 -> type == V_28 ||
V_25 -> type == V_29 ||
V_25 -> type == V_30 ||
V_25 -> type == V_31 )
continue;
V_27 = V_25 -> type == V_32 &&
V_21 -> type == V_31 &&
V_25 -> V_33 == V_21 -> V_33
? V_34 : 0 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_35 ; ++ V_26 ) {
if ( ! ( V_23 -> V_36 [ V_26 ] . V_27 & V_37 ) )
continue;
V_8 = F_9 ( & V_25 -> V_24 . V_23 ,
V_25 -> V_38 ,
V_23 , V_26 , V_27 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_27 & V_34 )
V_25 -> V_21 = V_23 ;
}
}
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_20 * V_23 ;
unsigned int V_10 ;
int V_8 ;
F_8 (entity, &vsp1->entities, list_dev) {
if ( V_23 -> type == V_30 ||
V_23 -> type == V_32 )
continue;
V_8 = F_7 ( V_7 , V_23 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_7 -> V_39 ) {
V_8 = F_9 ( & V_7 -> V_39 -> V_40 . V_23 . V_24 . V_23 ,
V_41 ,
& V_7 -> V_39 -> V_40 . V_42 . V_23 , 0 ,
V_34 |
V_43 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_7 -> V_44 ) {
V_8 = F_9 ( & V_7 -> V_44 -> V_40 . V_23 . V_24 . V_23 ,
V_41 ,
& V_7 -> V_44 -> V_40 . V_42 . V_23 , 0 ,
V_34 |
V_43 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_7 -> V_45 ) {
V_8 = F_9 ( & V_7 -> V_15 [ 0 ] -> V_23 . V_24 . V_23 ,
V_46 ,
& V_7 -> V_45 -> V_23 . V_24 . V_23 ,
V_47 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_48 ; ++ V_10 ) {
struct V_14 * V_49 = V_7 -> V_49 [ V_10 ] ;
V_8 = F_9 ( & V_49 -> V_42 -> V_42 . V_23 , 0 ,
& V_49 -> V_23 . V_24 . V_23 ,
V_50 ,
V_34 |
V_43 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 = V_7 -> V_15 [ V_10 ] ;
V_8 = F_9 ( & V_15 -> V_23 . V_24 . V_23 ,
V_46 ,
& V_15 -> V_42 -> V_42 . V_23 , 0 ,
V_43 |
V_34 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_20 * V_23 , * V_51 ;
struct V_52 * V_42 , * V_53 ;
F_12 (entity, _entity, &vsp1->entities, list_dev) {
F_13 ( & V_23 -> V_54 ) ;
F_14 ( V_23 ) ;
}
F_12 (video, _video, &vsp1->videos, list) {
F_13 ( & V_42 -> V_55 ) ;
F_15 ( V_42 ) ;
}
F_16 ( & V_7 -> V_56 ) ;
if ( V_7 -> V_12 -> V_57 )
F_17 ( & V_7 -> V_58 ) ;
F_18 ( & V_7 -> V_58 ) ;
if ( ! V_7 -> V_12 -> V_57 )
F_19 ( V_7 ) ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_59 * V_60 = & V_7 -> V_58 ;
struct V_61 * V_62 = & V_7 -> V_56 ;
struct V_20 * V_23 ;
unsigned int V_10 ;
int V_8 ;
V_60 -> V_63 = V_7 -> V_63 ;
V_60 -> V_64 = V_7 -> V_65 ;
F_21 ( V_60 -> V_66 , V_7 -> V_12 -> V_66 , sizeof( V_60 -> V_66 ) ) ;
snprintf ( V_60 -> V_67 , sizeof( V_60 -> V_67 ) , L_1 ,
F_22 ( V_60 -> V_63 ) ) ;
F_23 ( V_60 ) ;
V_7 -> V_68 . V_69 = V_70 ;
if ( V_7 -> V_12 -> V_57 )
V_7 -> V_68 . V_71 = V_72 ;
V_62 -> V_60 = V_60 ;
V_8 = F_24 ( V_7 -> V_63 , V_62 ) ;
if ( V_8 < 0 ) {
F_25 ( V_7 -> V_63 , L_2 ,
V_8 ) ;
goto V_73;
}
if ( V_7 -> V_12 -> V_74 & V_75 ) {
V_7 -> V_76 = F_26 ( V_7 ) ;
if ( F_27 ( V_7 -> V_76 ) ) {
V_8 = F_28 ( V_7 -> V_76 ) ;
goto V_73;
}
F_29 ( & V_7 -> V_76 -> V_23 . V_54 , & V_7 -> V_77 ) ;
}
if ( V_7 -> V_12 -> V_74 & V_78 ) {
V_7 -> V_79 = F_30 ( V_7 ) ;
if ( F_27 ( V_7 -> V_79 ) ) {
V_8 = F_28 ( V_7 -> V_79 ) ;
goto V_73;
}
F_29 ( & V_7 -> V_79 -> V_23 . V_54 , & V_7 -> V_77 ) ;
}
V_7 -> V_80 = F_31 ( V_7 , true ) ;
if ( F_27 ( V_7 -> V_80 ) ) {
V_8 = F_28 ( V_7 -> V_80 ) ;
goto V_73;
}
F_29 ( & V_7 -> V_80 -> V_23 . V_54 , & V_7 -> V_77 ) ;
V_7 -> V_81 = F_31 ( V_7 , false ) ;
if ( F_27 ( V_7 -> V_81 ) ) {
V_8 = F_28 ( V_7 -> V_81 ) ;
goto V_73;
}
F_29 ( & V_7 -> V_81 -> V_23 . V_54 , & V_7 -> V_77 ) ;
if ( V_7 -> V_12 -> V_74 & V_82 && V_7 -> V_12 -> V_57 ) {
V_7 -> V_39 = F_32 ( V_7 ) ;
if ( F_27 ( V_7 -> V_39 ) ) {
V_8 = F_28 ( V_7 -> V_39 ) ;
goto V_73;
}
F_29 ( & V_7 -> V_39 -> V_40 . V_23 . V_54 ,
& V_7 -> V_77 ) ;
}
if ( V_7 -> V_12 -> V_74 & V_83 && V_7 -> V_12 -> V_57 ) {
V_7 -> V_44 = F_33 ( V_7 ) ;
if ( F_27 ( V_7 -> V_44 ) ) {
V_8 = F_28 ( V_7 -> V_44 ) ;
goto V_73;
}
F_29 ( & V_7 -> V_44 -> V_40 . V_23 . V_54 ,
& V_7 -> V_77 ) ;
}
if ( V_7 -> V_12 -> V_74 & V_84 && ! V_7 -> V_12 -> V_57 ) {
V_7 -> V_45 = F_34 ( V_7 ) ;
if ( F_27 ( V_7 -> V_45 ) ) {
V_8 = F_28 ( V_7 -> V_45 ) ;
goto V_73;
}
F_29 ( & V_7 -> V_45 -> V_23 . V_54 , & V_7 -> V_77 ) ;
}
if ( V_7 -> V_12 -> V_74 & V_85 ) {
V_7 -> V_86 = F_35 ( V_7 ) ;
if ( F_27 ( V_7 -> V_86 ) ) {
V_8 = F_28 ( V_7 -> V_86 ) ;
goto V_73;
}
F_29 ( & V_7 -> V_86 -> V_23 . V_54 , & V_7 -> V_77 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_48 ; ++ V_10 ) {
struct V_14 * V_49 ;
V_49 = F_36 ( V_7 , V_10 ) ;
if ( F_27 ( V_49 ) ) {
V_8 = F_28 ( V_49 ) ;
goto V_73;
}
V_7 -> V_49 [ V_10 ] = V_49 ;
F_29 ( & V_49 -> V_23 . V_54 , & V_7 -> V_77 ) ;
if ( V_7 -> V_12 -> V_57 ) {
struct V_52 * V_42 = F_37 ( V_7 , V_49 ) ;
if ( F_27 ( V_42 ) ) {
V_8 = F_28 ( V_42 ) ;
goto V_73;
}
F_29 ( & V_42 -> V_55 , & V_7 -> V_87 ) ;
}
}
if ( V_7 -> V_12 -> V_74 & V_88 ) {
V_7 -> V_89 = F_38 ( V_7 ) ;
if ( F_27 ( V_7 -> V_89 ) ) {
V_8 = F_28 ( V_7 -> V_89 ) ;
goto V_73;
}
F_29 ( & V_7 -> V_89 -> V_23 . V_54 , & V_7 -> V_77 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_90 ; ++ V_10 ) {
struct V_91 * V_92 ;
V_92 = F_39 ( V_7 , V_10 ) ;
if ( F_27 ( V_92 ) ) {
V_8 = F_28 ( V_92 ) ;
goto V_73;
}
V_7 -> V_92 [ V_10 ] = V_92 ;
F_29 ( & V_92 -> V_23 . V_54 , & V_7 -> V_77 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 ;
V_15 = F_40 ( V_7 , V_10 ) ;
if ( F_27 ( V_15 ) ) {
V_8 = F_28 ( V_15 ) ;
goto V_73;
}
V_7 -> V_15 [ V_10 ] = V_15 ;
F_29 ( & V_15 -> V_23 . V_54 , & V_7 -> V_77 ) ;
if ( V_7 -> V_12 -> V_57 ) {
struct V_52 * V_42 = F_37 ( V_7 , V_15 ) ;
if ( F_27 ( V_42 ) ) {
V_8 = F_28 ( V_42 ) ;
goto V_73;
}
F_29 ( & V_42 -> V_55 , & V_7 -> V_87 ) ;
V_15 -> V_23 . V_21 = & V_42 -> V_42 . V_23 ;
}
}
F_8 (entity, &vsp1->entities, list_dev) {
V_8 = F_41 ( & V_7 -> V_56 ,
& V_23 -> V_24 ) ;
if ( V_8 < 0 )
goto V_73;
}
if ( V_7 -> V_12 -> V_57 )
V_8 = F_10 ( V_7 ) ;
else
V_8 = F_42 ( V_7 ) ;
if ( V_8 < 0 )
goto V_73;
if ( V_7 -> V_12 -> V_57 ) {
V_8 = F_43 ( & V_7 -> V_56 ) ;
if ( V_8 < 0 )
goto V_73;
V_8 = F_44 ( V_60 ) ;
} else {
V_8 = F_45 ( V_7 ) ;
}
V_73:
if ( V_8 < 0 )
F_11 ( V_7 ) ;
return V_8 ;
}
int F_46 ( struct V_6 * V_7 , unsigned int V_33 )
{
unsigned int V_93 ;
T_2 V_11 ;
V_11 = F_2 ( V_7 , V_94 ) ;
if ( ! ( V_11 & F_47 ( V_33 ) ) )
return 0 ;
F_4 ( V_7 , V_95 , F_48 ( V_33 ) ) ;
for ( V_93 = 10 ; V_93 > 0 ; -- V_93 ) {
V_11 = F_2 ( V_7 , V_94 ) ;
if ( ! ( V_11 & F_47 ( V_33 ) ) )
break;
F_49 ( 1000 , 2000 ) ;
}
if ( ! V_93 ) {
F_25 ( V_7 -> V_63 , L_3 , V_33 ) ;
return - V_96 ;
}
return 0 ;
}
static int F_50 ( struct V_6 * V_7 )
{
unsigned int V_10 ;
int V_8 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
V_8 = F_46 ( V_7 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
}
F_4 ( V_7 , V_97 , ( 8 << V_98 ) |
( 8 << V_99 ) ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_48 ; ++ V_10 )
F_4 ( V_7 , F_51 ( V_10 ) , V_100 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_90 ; ++ V_10 )
F_4 ( V_7 , F_52 ( V_10 ) , V_100 ) ;
F_4 ( V_7 , V_101 , V_100 ) ;
F_4 ( V_7 , V_102 , V_100 ) ;
F_4 ( V_7 , V_103 , V_100 ) ;
F_4 ( V_7 , V_104 , V_100 ) ;
F_4 ( V_7 , V_105 , V_100 ) ;
F_4 ( V_7 , V_106 , V_100 ) ;
F_4 ( V_7 , V_107 , ( 7 << V_108 ) |
( V_100 << V_109 ) ) ;
F_4 ( V_7 , V_110 , ( 7 << V_108 ) |
( V_100 << V_109 ) ) ;
F_53 ( V_7 ) ;
return 0 ;
}
int F_54 ( struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_55 ( V_7 -> V_63 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
void F_56 ( struct V_6 * V_7 )
{
F_57 ( V_7 -> V_63 ) ;
}
static int T_3 F_58 ( struct V_111 * V_63 )
{
struct V_6 * V_7 = F_59 ( V_63 ) ;
F_60 ( V_7 ) ;
F_61 ( V_7 -> V_63 ) ;
return 0 ;
}
static int T_3 F_62 ( struct V_111 * V_63 )
{
struct V_6 * V_7 = F_59 ( V_63 ) ;
F_63 ( V_7 -> V_63 ) ;
F_64 ( V_7 ) ;
return 0 ;
}
static int T_3 F_65 ( struct V_111 * V_63 )
{
struct V_6 * V_7 = F_59 ( V_63 ) ;
F_66 ( V_7 -> V_112 ) ;
return 0 ;
}
static int T_3 F_67 ( struct V_111 * V_63 )
{
struct V_6 * V_7 = F_59 ( V_63 ) ;
int V_8 ;
if ( V_7 -> V_12 ) {
V_8 = F_50 ( V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return F_68 ( V_7 -> V_112 ) ;
}
static int F_69 ( struct V_113 * V_114 )
{
struct V_6 * V_7 ;
struct V_115 * V_116 ;
struct V_117 * V_1 ;
struct V_117 * V_118 ;
unsigned int V_10 ;
int V_8 ;
V_7 = F_70 ( & V_114 -> V_63 , sizeof( * V_7 ) , V_119 ) ;
if ( V_7 == NULL )
return - V_120 ;
V_7 -> V_63 = & V_114 -> V_63 ;
F_71 ( & V_7 -> V_77 ) ;
F_71 ( & V_7 -> V_87 ) ;
F_72 ( V_114 , V_7 ) ;
V_118 = F_73 ( V_114 , V_121 , 0 ) ;
V_7 -> V_122 = F_74 ( & V_114 -> V_63 , V_118 ) ;
if ( F_27 ( V_7 -> V_122 ) )
return F_28 ( V_7 -> V_122 ) ;
V_1 = F_73 ( V_114 , V_123 , 0 ) ;
if ( ! V_1 ) {
F_25 ( & V_114 -> V_63 , L_4 ) ;
return - V_124 ;
}
V_8 = F_75 ( & V_114 -> V_63 , V_1 -> V_125 , F_1 ,
V_126 , F_22 ( & V_114 -> V_63 ) , V_7 ) ;
if ( V_8 < 0 ) {
F_25 ( & V_114 -> V_63 , L_5 ) ;
return V_8 ;
}
V_116 = F_76 ( V_114 -> V_63 . V_127 , L_6 , 0 ) ;
if ( V_116 ) {
V_7 -> V_112 = F_77 ( V_116 ) ;
F_78 ( V_116 ) ;
if ( F_27 ( V_7 -> V_112 ) ) {
F_79 ( & V_114 -> V_63 , L_7 ,
F_28 ( V_7 -> V_112 ) ) ;
return F_28 ( V_7 -> V_112 ) ;
}
V_7 -> V_128 = F_80 ( V_7 -> V_112 ) ;
} else {
V_7 -> V_128 = V_7 -> V_63 ;
}
F_81 ( & V_114 -> V_63 ) ;
V_8 = F_55 ( & V_114 -> V_63 ) ;
if ( V_8 < 0 )
goto V_73;
V_7 -> V_65 = F_2 ( V_7 , V_129 ) ;
F_57 ( & V_114 -> V_63 ) ;
for ( V_10 = 0 ; V_10 < F_82 ( V_130 ) ; ++ V_10 ) {
if ( ( V_7 -> V_65 & V_131 ) ==
V_130 [ V_10 ] . V_65 ) {
V_7 -> V_12 = & V_130 [ V_10 ] ;
break;
}
}
if ( ! V_7 -> V_12 ) {
F_25 ( & V_114 -> V_63 , L_8 ,
V_7 -> V_65 ) ;
V_8 = - V_132 ;
goto V_73;
}
F_79 ( & V_114 -> V_63 , L_9 , V_7 -> V_65 ) ;
V_8 = F_20 ( V_7 ) ;
if ( V_8 < 0 ) {
F_25 ( & V_114 -> V_63 , L_10 ) ;
goto V_73;
}
V_73:
if ( V_8 )
F_83 ( & V_114 -> V_63 ) ;
return V_8 ;
}
static int F_84 ( struct V_113 * V_114 )
{
struct V_6 * V_7 = F_85 ( V_114 ) ;
F_11 ( V_7 ) ;
F_86 ( V_7 -> V_112 ) ;
F_83 ( & V_114 -> V_63 ) ;
return 0 ;
}
