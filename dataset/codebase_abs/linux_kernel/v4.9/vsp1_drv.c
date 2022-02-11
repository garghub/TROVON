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
V_25 -> type == V_29 )
continue;
V_27 = V_25 -> type == V_30 &&
V_21 -> type == V_29 &&
V_25 -> V_31 == V_21 -> V_31
? V_32 : 0 ;
for ( V_26 = 0 ; V_26 < V_23 -> V_33 ; ++ V_26 ) {
if ( ! ( V_23 -> V_34 [ V_26 ] . V_27 & V_35 ) )
continue;
V_8 = F_9 ( & V_25 -> V_24 . V_23 ,
V_25 -> V_36 ,
V_23 , V_26 , V_27 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_27 & V_32 )
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
if ( V_23 -> type == V_28 ||
V_23 -> type == V_30 )
continue;
V_8 = F_7 ( V_7 , V_23 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_7 -> V_37 ) {
V_8 = F_9 ( & V_7 -> V_15 [ 0 ] -> V_23 . V_24 . V_23 ,
V_38 ,
& V_7 -> V_37 -> V_23 . V_24 . V_23 ,
V_39 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_40 ; ++ V_10 ) {
struct V_14 * V_41 = V_7 -> V_41 [ V_10 ] ;
V_8 = F_9 ( & V_41 -> V_42 -> V_42 . V_23 , 0 ,
& V_41 -> V_23 . V_24 . V_23 ,
V_43 ,
V_32 |
V_44 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 = V_7 -> V_15 [ V_10 ] ;
V_8 = F_9 ( & V_15 -> V_23 . V_24 . V_23 ,
V_38 ,
& V_15 -> V_42 -> V_42 . V_23 , 0 ,
V_44 |
V_32 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_20 * V_23 , * V_45 ;
struct V_46 * V_42 , * V_47 ;
F_12 (entity, _entity, &vsp1->entities, list_dev) {
F_13 ( & V_23 -> V_48 ) ;
F_14 ( V_23 ) ;
}
F_12 (video, _video, &vsp1->videos, list) {
F_13 ( & V_42 -> V_49 ) ;
F_15 ( V_42 ) ;
}
F_16 ( & V_7 -> V_50 ) ;
if ( V_7 -> V_12 -> V_51 )
F_17 ( & V_7 -> V_52 ) ;
F_18 ( & V_7 -> V_52 ) ;
if ( ! V_7 -> V_12 -> V_51 )
F_19 ( V_7 ) ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_53 * V_54 = & V_7 -> V_52 ;
struct V_55 * V_56 = & V_7 -> V_50 ;
struct V_20 * V_23 ;
unsigned int V_10 ;
int V_8 ;
V_54 -> V_57 = V_7 -> V_57 ;
V_54 -> V_58 = V_7 -> V_59 ;
F_21 ( V_54 -> V_60 , V_7 -> V_12 -> V_60 , sizeof( V_54 -> V_60 ) ) ;
snprintf ( V_54 -> V_61 , sizeof( V_54 -> V_61 ) , L_1 ,
F_22 ( V_54 -> V_57 ) ) ;
F_23 ( V_54 ) ;
V_7 -> V_62 . V_63 = V_64 ;
if ( V_7 -> V_12 -> V_51 )
V_7 -> V_62 . V_65 = V_66 ;
V_56 -> V_54 = V_54 ;
V_8 = F_24 ( V_7 -> V_57 , V_56 ) ;
if ( V_8 < 0 ) {
F_25 ( V_7 -> V_57 , L_2 ,
V_8 ) ;
goto V_67;
}
if ( V_7 -> V_12 -> V_68 & V_69 ) {
V_7 -> V_70 = F_26 ( V_7 ) ;
if ( F_27 ( V_7 -> V_70 ) ) {
V_8 = F_28 ( V_7 -> V_70 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_70 -> V_23 . V_48 , & V_7 -> V_71 ) ;
}
if ( V_7 -> V_12 -> V_68 & V_72 ) {
V_7 -> V_73 = F_30 ( V_7 ) ;
if ( F_27 ( V_7 -> V_73 ) ) {
V_8 = F_28 ( V_7 -> V_73 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_73 -> V_23 . V_48 , & V_7 -> V_71 ) ;
}
V_7 -> V_74 = F_31 ( V_7 , true ) ;
if ( F_27 ( V_7 -> V_74 ) ) {
V_8 = F_28 ( V_7 -> V_74 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_74 -> V_23 . V_48 , & V_7 -> V_71 ) ;
V_7 -> V_75 = F_31 ( V_7 , false ) ;
if ( F_27 ( V_7 -> V_75 ) ) {
V_8 = F_28 ( V_7 -> V_75 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_75 -> V_23 . V_48 , & V_7 -> V_71 ) ;
if ( V_7 -> V_12 -> V_68 & V_76 && ! V_7 -> V_12 -> V_51 ) {
V_7 -> V_37 = F_32 ( V_7 ) ;
if ( F_27 ( V_7 -> V_37 ) ) {
V_8 = F_28 ( V_7 -> V_37 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_37 -> V_23 . V_48 , & V_7 -> V_71 ) ;
}
if ( V_7 -> V_12 -> V_68 & V_77 ) {
V_7 -> V_78 = F_33 ( V_7 ) ;
if ( F_27 ( V_7 -> V_78 ) ) {
V_8 = F_28 ( V_7 -> V_78 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_78 -> V_23 . V_48 , & V_7 -> V_71 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_40 ; ++ V_10 ) {
struct V_14 * V_41 ;
V_41 = F_34 ( V_7 , V_10 ) ;
if ( F_27 ( V_41 ) ) {
V_8 = F_28 ( V_41 ) ;
goto V_67;
}
V_7 -> V_41 [ V_10 ] = V_41 ;
F_29 ( & V_41 -> V_23 . V_48 , & V_7 -> V_71 ) ;
if ( V_7 -> V_12 -> V_51 ) {
struct V_46 * V_42 = F_35 ( V_7 , V_41 ) ;
if ( F_27 ( V_42 ) ) {
V_8 = F_28 ( V_42 ) ;
goto V_67;
}
F_29 ( & V_42 -> V_49 , & V_7 -> V_79 ) ;
}
}
if ( V_7 -> V_12 -> V_68 & V_80 ) {
V_7 -> V_81 = F_36 ( V_7 ) ;
if ( F_27 ( V_7 -> V_81 ) ) {
V_8 = F_28 ( V_7 -> V_81 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_81 -> V_23 . V_48 , & V_7 -> V_71 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_82 ; ++ V_10 ) {
struct V_83 * V_84 ;
V_84 = F_37 ( V_7 , V_10 ) ;
if ( F_27 ( V_84 ) ) {
V_8 = F_28 ( V_84 ) ;
goto V_67;
}
V_7 -> V_84 [ V_10 ] = V_84 ;
F_29 ( & V_84 -> V_23 . V_48 , & V_7 -> V_71 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 ;
V_15 = F_38 ( V_7 , V_10 ) ;
if ( F_27 ( V_15 ) ) {
V_8 = F_28 ( V_15 ) ;
goto V_67;
}
V_7 -> V_15 [ V_10 ] = V_15 ;
F_29 ( & V_15 -> V_23 . V_48 , & V_7 -> V_71 ) ;
if ( V_7 -> V_12 -> V_51 ) {
struct V_46 * V_42 = F_35 ( V_7 , V_15 ) ;
if ( F_27 ( V_42 ) ) {
V_8 = F_28 ( V_42 ) ;
goto V_67;
}
F_29 ( & V_42 -> V_49 , & V_7 -> V_79 ) ;
V_15 -> V_23 . V_21 = & V_42 -> V_42 . V_23 ;
}
}
F_8 (entity, &vsp1->entities, list_dev) {
V_8 = F_39 ( & V_7 -> V_50 ,
& V_23 -> V_24 ) ;
if ( V_8 < 0 )
goto V_67;
}
if ( V_7 -> V_12 -> V_51 )
V_8 = F_10 ( V_7 ) ;
else
V_8 = F_40 ( V_7 ) ;
if ( V_8 < 0 )
goto V_67;
if ( V_7 -> V_12 -> V_51 ) {
V_8 = F_41 ( & V_7 -> V_50 ) ;
if ( V_8 < 0 )
goto V_67;
V_8 = F_42 ( V_54 ) ;
} else {
V_8 = F_43 ( V_7 ) ;
}
V_67:
if ( V_8 < 0 )
F_11 ( V_7 ) ;
return V_8 ;
}
int F_44 ( struct V_6 * V_7 , unsigned int V_31 )
{
unsigned int V_85 ;
T_2 V_11 ;
V_11 = F_2 ( V_7 , V_86 ) ;
if ( ! ( V_11 & F_45 ( V_31 ) ) )
return 0 ;
F_4 ( V_7 , V_87 , F_46 ( V_31 ) ) ;
for ( V_85 = 10 ; V_85 > 0 ; -- V_85 ) {
V_11 = F_2 ( V_7 , V_86 ) ;
if ( ! ( V_11 & F_45 ( V_31 ) ) )
break;
F_47 ( 1000 , 2000 ) ;
}
if ( ! V_85 ) {
F_25 ( V_7 -> V_57 , L_3 , V_31 ) ;
return - V_88 ;
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
F_4 ( V_7 , V_89 , ( 8 << V_90 ) |
( 8 << V_91 ) ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_40 ; ++ V_10 )
F_4 ( V_7 , F_49 ( V_10 ) , V_92 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_82 ; ++ V_10 )
F_4 ( V_7 , F_50 ( V_10 ) , V_92 ) ;
F_4 ( V_7 , V_93 , V_92 ) ;
F_4 ( V_7 , V_94 , V_92 ) ;
F_4 ( V_7 , V_95 , V_92 ) ;
F_4 ( V_7 , V_96 , V_92 ) ;
F_4 ( V_7 , V_97 , V_92 ) ;
F_4 ( V_7 , V_98 , V_92 ) ;
F_4 ( V_7 , V_99 , ( 7 << V_100 ) |
( V_92 << V_101 ) ) ;
F_4 ( V_7 , V_102 , ( 7 << V_100 ) |
( V_92 << V_101 ) ) ;
F_51 ( V_7 ) ;
return 0 ;
}
int F_52 ( struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_53 ( V_7 -> V_57 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
void F_54 ( struct V_6 * V_7 )
{
F_55 ( V_7 -> V_57 ) ;
}
static int T_3 F_56 ( struct V_103 * V_57 )
{
struct V_6 * V_7 = F_57 ( V_57 ) ;
F_58 ( V_7 ) ;
F_59 ( V_7 -> V_57 ) ;
return 0 ;
}
static int T_3 F_60 ( struct V_103 * V_57 )
{
struct V_6 * V_7 = F_57 ( V_57 ) ;
F_61 ( V_7 -> V_57 ) ;
F_62 ( V_7 ) ;
return 0 ;
}
static int T_3 F_63 ( struct V_103 * V_57 )
{
struct V_6 * V_7 = F_57 ( V_57 ) ;
F_64 ( V_7 -> V_104 ) ;
return 0 ;
}
static int T_3 F_65 ( struct V_103 * V_57 )
{
struct V_6 * V_7 = F_57 ( V_57 ) ;
int V_8 ;
if ( V_7 -> V_12 ) {
V_8 = F_48 ( V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return F_66 ( V_7 -> V_104 ) ;
}
static int F_67 ( struct V_105 * V_106 )
{
struct V_6 * V_7 ;
struct V_107 * V_108 ;
struct V_109 * V_1 ;
struct V_109 * V_110 ;
unsigned int V_10 ;
int V_8 ;
V_7 = F_68 ( & V_106 -> V_57 , sizeof( * V_7 ) , V_111 ) ;
if ( V_7 == NULL )
return - V_112 ;
V_7 -> V_57 = & V_106 -> V_57 ;
F_69 ( & V_7 -> V_71 ) ;
F_69 ( & V_7 -> V_79 ) ;
F_70 ( V_106 , V_7 ) ;
V_110 = F_71 ( V_106 , V_113 , 0 ) ;
V_7 -> V_114 = F_72 ( & V_106 -> V_57 , V_110 ) ;
if ( F_27 ( V_7 -> V_114 ) )
return F_28 ( V_7 -> V_114 ) ;
V_1 = F_71 ( V_106 , V_115 , 0 ) ;
if ( ! V_1 ) {
F_25 ( & V_106 -> V_57 , L_4 ) ;
return - V_116 ;
}
V_8 = F_73 ( & V_106 -> V_57 , V_1 -> V_117 , F_1 ,
V_118 , F_22 ( & V_106 -> V_57 ) , V_7 ) ;
if ( V_8 < 0 ) {
F_25 ( & V_106 -> V_57 , L_5 ) ;
return V_8 ;
}
V_108 = F_74 ( V_106 -> V_57 . V_119 , L_6 , 0 ) ;
if ( V_108 ) {
V_7 -> V_104 = F_75 ( V_108 ) ;
F_76 ( V_108 ) ;
if ( F_27 ( V_7 -> V_104 ) ) {
F_77 ( & V_106 -> V_57 , L_7 ,
F_28 ( V_7 -> V_104 ) ) ;
return F_28 ( V_7 -> V_104 ) ;
}
}
F_78 ( & V_106 -> V_57 ) ;
V_8 = F_53 ( & V_106 -> V_57 ) ;
if ( V_8 < 0 )
goto V_67;
V_7 -> V_59 = F_2 ( V_7 , V_120 ) ;
F_55 ( & V_106 -> V_57 ) ;
for ( V_10 = 0 ; V_10 < F_79 ( V_121 ) ; ++ V_10 ) {
if ( ( V_7 -> V_59 & V_122 ) ==
V_121 [ V_10 ] . V_59 ) {
V_7 -> V_12 = & V_121 [ V_10 ] ;
break;
}
}
if ( ! V_7 -> V_12 ) {
F_25 ( & V_106 -> V_57 , L_8 ,
V_7 -> V_59 ) ;
V_8 = - V_123 ;
goto V_67;
}
F_77 ( & V_106 -> V_57 , L_9 , V_7 -> V_59 ) ;
V_8 = F_20 ( V_7 ) ;
if ( V_8 < 0 ) {
F_25 ( & V_106 -> V_57 , L_10 ) ;
goto V_67;
}
V_67:
if ( V_8 )
F_80 ( & V_106 -> V_57 ) ;
return V_8 ;
}
static int F_81 ( struct V_105 * V_106 )
{
struct V_6 * V_7 = F_82 ( V_106 ) ;
F_11 ( V_7 ) ;
F_83 ( V_7 -> V_104 ) ;
F_80 ( & V_106 -> V_57 ) ;
return 0 ;
}
