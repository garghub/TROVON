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
if ( V_11 & V_5 ) {
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
if ( V_7 -> V_12 -> V_37 & V_38 ) {
V_8 = F_9 ( & V_7 -> V_15 [ 0 ] -> V_23 . V_24 . V_23 ,
V_39 ,
& V_7 -> V_40 -> V_23 . V_24 . V_23 ,
V_41 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_42 ; ++ V_10 ) {
struct V_14 * V_43 = V_7 -> V_43 [ V_10 ] ;
V_8 = F_9 ( & V_43 -> V_44 -> V_44 . V_23 , 0 ,
& V_43 -> V_23 . V_24 . V_23 ,
V_45 ,
V_32 |
V_46 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 = V_7 -> V_15 [ V_10 ] ;
unsigned int V_27 = V_32 ;
if ( ! ( V_7 -> V_12 -> V_37 & V_38 ) || V_10 != 0 )
V_27 |= V_46 ;
V_8 = F_9 ( & V_15 -> V_23 . V_24 . V_23 ,
V_39 ,
& V_15 -> V_44 -> V_44 . V_23 , 0 ,
V_27 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_20 * V_23 , * V_47 ;
struct V_48 * V_44 , * V_49 ;
F_12 (entity, _entity, &vsp1->entities, list_dev) {
F_13 ( & V_23 -> V_50 ) ;
F_14 ( V_23 ) ;
}
F_12 (video, _video, &vsp1->videos, list) {
F_13 ( & V_44 -> V_51 ) ;
F_15 ( V_44 ) ;
}
F_16 ( & V_7 -> V_52 ) ;
F_17 ( & V_7 -> V_53 ) ;
F_18 ( & V_7 -> V_53 ) ;
if ( ! V_7 -> V_12 -> V_54 )
F_19 ( V_7 ) ;
}
static int F_20 ( struct V_6 * V_7 )
{
struct V_55 * V_56 = & V_7 -> V_53 ;
struct V_57 * V_58 = & V_7 -> V_52 ;
struct V_20 * V_23 ;
unsigned int V_10 ;
int V_8 ;
V_56 -> V_59 = V_7 -> V_59 ;
F_21 ( V_56 -> V_60 , L_1 , sizeof( V_56 -> V_60 ) ) ;
snprintf ( V_56 -> V_61 , sizeof( V_56 -> V_61 ) , L_2 ,
F_22 ( V_56 -> V_59 ) ) ;
F_23 ( V_56 ) ;
V_7 -> V_62 . V_63 = V_64 ;
if ( V_7 -> V_12 -> V_54 )
V_7 -> V_62 . V_65 = V_66 ;
V_58 -> V_56 = V_56 ;
V_8 = F_24 ( V_7 -> V_59 , V_58 ) ;
if ( V_8 < 0 ) {
F_25 ( V_7 -> V_59 , L_3 ,
V_8 ) ;
goto V_67;
}
if ( V_7 -> V_12 -> V_37 & V_68 ) {
V_7 -> V_69 = F_26 ( V_7 ) ;
if ( F_27 ( V_7 -> V_69 ) ) {
V_8 = F_28 ( V_7 -> V_69 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_69 -> V_23 . V_50 , & V_7 -> V_70 ) ;
}
V_7 -> V_71 = F_30 ( V_7 , true ) ;
if ( F_27 ( V_7 -> V_71 ) ) {
V_8 = F_28 ( V_7 -> V_71 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_71 -> V_23 . V_50 , & V_7 -> V_70 ) ;
V_7 -> V_72 = F_30 ( V_7 , false ) ;
if ( F_27 ( V_7 -> V_72 ) ) {
V_8 = F_28 ( V_7 -> V_72 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_72 -> V_23 . V_50 , & V_7 -> V_70 ) ;
if ( V_7 -> V_12 -> V_37 & V_38 ) {
V_7 -> V_40 = F_31 ( V_7 ) ;
if ( F_27 ( V_7 -> V_40 ) ) {
V_8 = F_28 ( V_7 -> V_40 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_40 -> V_23 . V_50 , & V_7 -> V_70 ) ;
}
if ( V_7 -> V_12 -> V_37 & V_73 ) {
V_7 -> V_74 = F_32 ( V_7 ) ;
if ( F_27 ( V_7 -> V_74 ) ) {
V_8 = F_28 ( V_7 -> V_74 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_74 -> V_23 . V_50 , & V_7 -> V_70 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_42 ; ++ V_10 ) {
struct V_14 * V_43 ;
V_43 = F_33 ( V_7 , V_10 ) ;
if ( F_27 ( V_43 ) ) {
V_8 = F_28 ( V_43 ) ;
goto V_67;
}
V_7 -> V_43 [ V_10 ] = V_43 ;
F_29 ( & V_43 -> V_23 . V_50 , & V_7 -> V_70 ) ;
if ( V_7 -> V_12 -> V_54 ) {
struct V_48 * V_44 = F_34 ( V_7 , V_43 ) ;
if ( F_27 ( V_44 ) ) {
V_8 = F_28 ( V_44 ) ;
goto V_67;
}
F_29 ( & V_44 -> V_51 , & V_7 -> V_75 ) ;
}
}
if ( V_7 -> V_12 -> V_37 & V_76 ) {
V_7 -> V_77 = F_35 ( V_7 ) ;
if ( F_27 ( V_7 -> V_77 ) ) {
V_8 = F_28 ( V_7 -> V_77 ) ;
goto V_67;
}
F_29 ( & V_7 -> V_77 -> V_23 . V_50 , & V_7 -> V_70 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_78 ; ++ V_10 ) {
struct V_79 * V_80 ;
V_80 = F_36 ( V_7 , V_10 ) ;
if ( F_27 ( V_80 ) ) {
V_8 = F_28 ( V_80 ) ;
goto V_67;
}
V_7 -> V_80 [ V_10 ] = V_80 ;
F_29 ( & V_80 -> V_23 . V_50 , & V_7 -> V_70 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 ;
V_15 = F_37 ( V_7 , V_10 ) ;
if ( F_27 ( V_15 ) ) {
V_8 = F_28 ( V_15 ) ;
goto V_67;
}
V_7 -> V_15 [ V_10 ] = V_15 ;
F_29 ( & V_15 -> V_23 . V_50 , & V_7 -> V_70 ) ;
if ( V_7 -> V_12 -> V_54 ) {
struct V_48 * V_44 = F_34 ( V_7 , V_15 ) ;
if ( F_27 ( V_44 ) ) {
V_8 = F_28 ( V_44 ) ;
goto V_67;
}
F_29 ( & V_44 -> V_51 , & V_7 -> V_75 ) ;
V_15 -> V_23 . V_21 = & V_44 -> V_44 . V_23 ;
}
}
F_8 (entity, &vsp1->entities, list_dev) {
V_8 = F_38 ( & V_7 -> V_52 ,
& V_23 -> V_24 ) ;
if ( V_8 < 0 )
goto V_67;
}
if ( V_7 -> V_12 -> V_54 )
V_8 = F_10 ( V_7 ) ;
else
V_8 = F_39 ( V_7 ) ;
if ( V_8 < 0 )
goto V_67;
if ( V_7 -> V_12 -> V_54 )
V_8 = F_40 ( & V_7 -> V_52 ) ;
else
V_8 = F_41 ( V_7 ) ;
if ( V_8 < 0 )
goto V_67;
V_8 = F_42 ( V_56 ) ;
V_67:
if ( V_8 < 0 )
F_11 ( V_7 ) ;
return V_8 ;
}
int F_43 ( struct V_6 * V_7 , unsigned int V_31 )
{
unsigned int V_81 ;
T_2 V_11 ;
V_11 = F_2 ( V_7 , V_82 ) ;
if ( ! ( V_11 & F_44 ( V_31 ) ) )
return 0 ;
F_4 ( V_7 , V_83 , F_45 ( V_31 ) ) ;
for ( V_81 = 10 ; V_81 > 0 ; -- V_81 ) {
V_11 = F_2 ( V_7 , V_82 ) ;
if ( ! ( V_11 & F_44 ( V_31 ) ) )
break;
F_46 ( 1000 , 2000 ) ;
}
if ( ! V_81 ) {
F_25 ( V_7 -> V_59 , L_4 , V_31 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_47 ( struct V_6 * V_7 )
{
unsigned int V_10 ;
int V_8 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
V_8 = F_43 ( V_7 , V_10 ) ;
if ( V_8 < 0 )
return V_8 ;
}
F_4 ( V_7 , V_85 , ( 8 << V_86 ) |
( 8 << V_87 ) ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_42 ; ++ V_10 )
F_4 ( V_7 , F_48 ( V_10 ) , V_88 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_78 ; ++ V_10 )
F_4 ( V_7 , F_49 ( V_10 ) , V_88 ) ;
F_4 ( V_7 , V_89 , V_88 ) ;
F_4 ( V_7 , V_90 , V_88 ) ;
F_4 ( V_7 , V_91 , V_88 ) ;
F_4 ( V_7 , V_92 , V_88 ) ;
F_4 ( V_7 , V_93 , V_88 ) ;
F_4 ( V_7 , V_94 , V_88 ) ;
F_4 ( V_7 , V_95 , ( 7 << V_96 ) |
( V_88 << V_97 ) ) ;
F_4 ( V_7 , V_98 , ( 7 << V_96 ) |
( V_88 << V_97 ) ) ;
F_50 ( V_7 ) ;
return 0 ;
}
int F_51 ( struct V_6 * V_7 )
{
int V_8 = 0 ;
F_52 ( & V_7 -> V_99 ) ;
if ( V_7 -> V_100 > 0 )
goto V_67;
V_8 = F_53 ( V_7 -> clock ) ;
if ( V_8 < 0 )
goto V_67;
V_8 = F_47 ( V_7 ) ;
if ( V_8 < 0 ) {
F_54 ( V_7 -> clock ) ;
goto V_67;
}
V_67:
if ( ! V_8 )
V_7 -> V_100 ++ ;
F_55 ( & V_7 -> V_99 ) ;
return V_8 ;
}
void F_56 ( struct V_6 * V_7 )
{
F_52 ( & V_7 -> V_99 ) ;
if ( -- V_7 -> V_100 == 0 )
F_54 ( V_7 -> clock ) ;
F_55 ( & V_7 -> V_99 ) ;
}
static int F_57 ( struct V_101 * V_59 )
{
struct V_6 * V_7 = F_58 ( V_59 ) ;
F_59 ( F_60 ( & V_7 -> V_99 ) ) ;
if ( V_7 -> V_100 == 0 )
return 0 ;
F_61 ( V_7 ) ;
F_54 ( V_7 -> clock ) ;
return 0 ;
}
static int F_62 ( struct V_101 * V_59 )
{
struct V_6 * V_7 = F_58 ( V_59 ) ;
F_59 ( F_60 ( & V_7 -> V_99 ) ) ;
if ( V_7 -> V_100 == 0 )
return 0 ;
F_53 ( V_7 -> clock ) ;
F_63 ( V_7 ) ;
return 0 ;
}
static int F_64 ( struct V_102 * V_103 )
{
struct V_6 * V_7 ;
struct V_104 * V_1 ;
struct V_104 * V_105 ;
unsigned int V_10 ;
T_2 V_106 ;
int V_8 ;
V_7 = F_65 ( & V_103 -> V_59 , sizeof( * V_7 ) , V_107 ) ;
if ( V_7 == NULL )
return - V_108 ;
V_7 -> V_59 = & V_103 -> V_59 ;
F_66 ( & V_7 -> V_99 ) ;
F_67 ( & V_7 -> V_70 ) ;
F_67 ( & V_7 -> V_75 ) ;
V_105 = F_68 ( V_103 , V_109 , 0 ) ;
V_7 -> V_110 = F_69 ( & V_103 -> V_59 , V_105 ) ;
if ( F_27 ( V_7 -> V_110 ) )
return F_28 ( V_7 -> V_110 ) ;
V_7 -> clock = F_70 ( & V_103 -> V_59 , NULL ) ;
if ( F_27 ( V_7 -> clock ) ) {
F_25 ( & V_103 -> V_59 , L_5 ) ;
return F_28 ( V_7 -> clock ) ;
}
V_1 = F_68 ( V_103 , V_111 , 0 ) ;
if ( ! V_1 ) {
F_25 ( & V_103 -> V_59 , L_6 ) ;
return - V_112 ;
}
V_8 = F_71 ( & V_103 -> V_59 , V_1 -> V_113 , F_1 ,
V_114 , F_22 ( & V_103 -> V_59 ) , V_7 ) ;
if ( V_8 < 0 ) {
F_25 ( & V_103 -> V_59 , L_7 ) ;
return V_8 ;
}
V_8 = F_53 ( V_7 -> clock ) ;
if ( V_8 < 0 )
return V_8 ;
V_106 = F_2 ( V_7 , V_115 ) ;
F_54 ( V_7 -> clock ) ;
for ( V_10 = 0 ; V_10 < F_72 ( V_116 ) ; ++ V_10 ) {
if ( ( V_106 & V_117 ) ==
V_116 [ V_10 ] . V_106 ) {
V_7 -> V_12 = & V_116 [ V_10 ] ;
break;
}
}
if ( ! V_7 -> V_12 ) {
F_25 ( & V_103 -> V_59 , L_8 , V_106 ) ;
return - V_118 ;
}
F_73 ( & V_103 -> V_59 , L_9 , V_106 ) ;
V_8 = F_20 ( V_7 ) ;
if ( V_8 < 0 ) {
F_25 ( & V_103 -> V_59 , L_10 ) ;
return V_8 ;
}
F_74 ( V_103 , V_7 ) ;
return 0 ;
}
static int F_75 ( struct V_102 * V_103 )
{
struct V_6 * V_7 = F_76 ( V_103 ) ;
F_11 ( V_7 ) ;
return 0 ;
}
