static T_1 F_1 ( int V_1 , void * V_2 )
{
T_2 V_3 = V_4 | V_5 ;
struct V_6 * V_7 = V_2 ;
T_1 V_8 = V_9 ;
unsigned int V_10 ;
T_2 V_11 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 = V_7 -> V_15 [ V_10 ] ;
struct V_16 * V_17 ;
if ( V_15 == NULL )
continue;
V_17 = F_2 ( & V_15 -> V_18 . V_19 . V_18 ) ;
V_11 = F_3 ( V_7 , F_4 ( V_10 ) ) ;
F_5 ( V_7 , F_4 ( V_10 ) , ~ V_11 & V_3 ) ;
if ( V_11 & V_5 ) {
F_6 ( V_17 ) ;
V_8 = V_20 ;
}
}
V_11 = F_3 ( V_7 , V_21 ) ;
F_5 ( V_7 , V_21 , ~ V_11 & V_22 ) ;
if ( V_11 & V_22 ) {
struct V_14 * V_15 = V_7 -> V_15 [ 0 ] ;
struct V_16 * V_17 ;
if ( V_15 ) {
V_17 = F_2 ( & V_15 -> V_18 . V_19 . V_18 ) ;
F_7 ( V_17 ) ;
}
V_8 = V_20 ;
}
return V_8 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_23 * V_24 )
{
struct V_25 * V_18 = & V_24 -> V_19 . V_18 ;
struct V_23 * V_26 ;
unsigned int V_27 ;
int V_8 ;
F_9 (source, &vsp1->entities, list_dev) {
T_2 V_28 ;
if ( V_26 -> type == V_24 -> type )
continue;
if ( V_26 -> type == V_29 ||
V_26 -> type == V_30 )
continue;
V_28 = V_26 -> type == V_31 &&
V_24 -> type == V_30 &&
V_26 -> V_32 == V_24 -> V_32
? V_33 : 0 ;
for ( V_27 = 0 ; V_27 < V_18 -> V_34 ; ++ V_27 ) {
if ( ! ( V_18 -> V_35 [ V_27 ] . V_28 & V_36 ) )
continue;
V_8 = F_10 ( & V_26 -> V_19 . V_18 ,
V_26 -> V_37 ,
V_18 , V_27 , V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_28 & V_33 )
V_26 -> V_24 = V_18 ;
}
}
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_23 * V_18 ;
unsigned int V_10 ;
int V_8 ;
F_9 (entity, &vsp1->entities, list_dev) {
if ( V_18 -> type == V_29 ||
V_18 -> type == V_31 )
continue;
V_8 = F_8 ( V_7 , V_18 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_7 -> V_12 -> V_38 & V_39 ) {
V_8 = F_10 ( & V_7 -> V_15 [ 0 ] -> V_18 . V_19 . V_18 ,
V_40 ,
& V_7 -> V_41 -> V_18 . V_19 . V_18 ,
V_42 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_43 ; ++ V_10 ) {
struct V_14 * V_44 = V_7 -> V_44 [ V_10 ] ;
V_8 = F_10 ( & V_44 -> V_45 -> V_45 . V_18 , 0 ,
& V_44 -> V_18 . V_19 . V_18 ,
V_46 ,
V_33 |
V_47 ) ;
if ( V_8 < 0 )
return V_8 ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 = V_7 -> V_15 [ V_10 ] ;
unsigned int V_28 = V_33 ;
if ( ! ( V_7 -> V_12 -> V_38 & V_39 ) || V_10 != 0 )
V_28 |= V_47 ;
V_8 = F_10 ( & V_15 -> V_18 . V_19 . V_18 ,
V_40 ,
& V_15 -> V_45 -> V_45 . V_18 , 0 ,
V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static void F_12 ( struct V_6 * V_7 )
{
struct V_23 * V_18 , * V_48 ;
struct V_49 * V_45 , * V_50 ;
F_13 (entity, _entity, &vsp1->entities, list_dev) {
F_14 ( & V_18 -> V_51 ) ;
F_15 ( V_18 ) ;
}
F_13 (video, _video, &vsp1->videos, list) {
F_14 ( & V_45 -> V_52 ) ;
F_16 ( V_45 ) ;
}
F_17 ( & V_7 -> V_53 ) ;
F_18 ( & V_7 -> V_54 ) ;
F_19 ( & V_7 -> V_54 ) ;
if ( ! V_7 -> V_12 -> V_55 )
F_20 ( V_7 ) ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_56 * V_57 = & V_7 -> V_54 ;
struct V_58 * V_59 = & V_7 -> V_53 ;
struct V_23 * V_18 ;
unsigned int V_10 ;
int V_8 ;
V_57 -> V_60 = V_7 -> V_60 ;
F_22 ( V_57 -> V_61 , L_1 , sizeof( V_57 -> V_61 ) ) ;
snprintf ( V_57 -> V_62 , sizeof( V_57 -> V_62 ) , L_2 ,
F_23 ( V_57 -> V_60 ) ) ;
F_24 ( V_57 ) ;
V_7 -> V_63 . V_64 = V_65 ;
if ( V_7 -> V_12 -> V_55 )
V_7 -> V_63 . V_66 = V_67 ;
V_59 -> V_57 = V_57 ;
V_8 = F_25 ( V_7 -> V_60 , V_59 ) ;
if ( V_8 < 0 ) {
F_26 ( V_7 -> V_60 , L_3 ,
V_8 ) ;
goto V_68;
}
if ( V_7 -> V_12 -> V_38 & V_69 ) {
V_7 -> V_70 = F_27 ( V_7 ) ;
if ( F_28 ( V_7 -> V_70 ) ) {
V_8 = F_29 ( V_7 -> V_70 ) ;
goto V_68;
}
F_30 ( & V_7 -> V_70 -> V_18 . V_51 , & V_7 -> V_71 ) ;
}
V_7 -> V_72 = F_31 ( V_7 , true ) ;
if ( F_28 ( V_7 -> V_72 ) ) {
V_8 = F_29 ( V_7 -> V_72 ) ;
goto V_68;
}
F_30 ( & V_7 -> V_72 -> V_18 . V_51 , & V_7 -> V_71 ) ;
V_7 -> V_73 = F_31 ( V_7 , false ) ;
if ( F_28 ( V_7 -> V_73 ) ) {
V_8 = F_29 ( V_7 -> V_73 ) ;
goto V_68;
}
F_30 ( & V_7 -> V_73 -> V_18 . V_51 , & V_7 -> V_71 ) ;
if ( V_7 -> V_12 -> V_38 & V_39 ) {
V_7 -> V_41 = F_32 ( V_7 ) ;
if ( F_28 ( V_7 -> V_41 ) ) {
V_8 = F_29 ( V_7 -> V_41 ) ;
goto V_68;
}
F_30 ( & V_7 -> V_41 -> V_18 . V_51 , & V_7 -> V_71 ) ;
}
if ( V_7 -> V_12 -> V_38 & V_74 ) {
V_7 -> V_75 = F_33 ( V_7 ) ;
if ( F_28 ( V_7 -> V_75 ) ) {
V_8 = F_29 ( V_7 -> V_75 ) ;
goto V_68;
}
F_30 ( & V_7 -> V_75 -> V_18 . V_51 , & V_7 -> V_71 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_43 ; ++ V_10 ) {
struct V_14 * V_44 ;
V_44 = F_34 ( V_7 , V_10 ) ;
if ( F_28 ( V_44 ) ) {
V_8 = F_29 ( V_44 ) ;
goto V_68;
}
V_7 -> V_44 [ V_10 ] = V_44 ;
F_30 ( & V_44 -> V_18 . V_51 , & V_7 -> V_71 ) ;
if ( V_7 -> V_12 -> V_55 ) {
struct V_49 * V_45 = F_35 ( V_7 , V_44 ) ;
if ( F_28 ( V_45 ) ) {
V_8 = F_29 ( V_45 ) ;
goto V_68;
}
F_30 ( & V_45 -> V_52 , & V_7 -> V_76 ) ;
}
}
if ( V_7 -> V_12 -> V_38 & V_77 ) {
V_7 -> V_78 = F_36 ( V_7 ) ;
if ( F_28 ( V_7 -> V_78 ) ) {
V_8 = F_29 ( V_7 -> V_78 ) ;
goto V_68;
}
F_30 ( & V_7 -> V_78 -> V_18 . V_51 , & V_7 -> V_71 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_79 ; ++ V_10 ) {
struct V_80 * V_81 ;
V_81 = F_37 ( V_7 , V_10 ) ;
if ( F_28 ( V_81 ) ) {
V_8 = F_29 ( V_81 ) ;
goto V_68;
}
V_7 -> V_81 [ V_10 ] = V_81 ;
F_30 ( & V_81 -> V_18 . V_51 , & V_7 -> V_71 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_13 ; ++ V_10 ) {
struct V_14 * V_15 ;
V_15 = F_38 ( V_7 , V_10 ) ;
if ( F_28 ( V_15 ) ) {
V_8 = F_29 ( V_15 ) ;
goto V_68;
}
V_7 -> V_15 [ V_10 ] = V_15 ;
F_30 ( & V_15 -> V_18 . V_51 , & V_7 -> V_71 ) ;
if ( V_7 -> V_12 -> V_55 ) {
struct V_49 * V_45 = F_35 ( V_7 , V_15 ) ;
if ( F_28 ( V_45 ) ) {
V_8 = F_29 ( V_45 ) ;
goto V_68;
}
F_30 ( & V_45 -> V_52 , & V_7 -> V_76 ) ;
V_15 -> V_18 . V_24 = & V_45 -> V_45 . V_18 ;
}
}
F_9 (entity, &vsp1->entities, list_dev) {
V_8 = F_39 ( & V_7 -> V_53 ,
& V_18 -> V_19 ) ;
if ( V_8 < 0 )
goto V_68;
}
if ( V_7 -> V_12 -> V_55 )
V_8 = F_11 ( V_7 ) ;
else
V_8 = F_40 ( V_7 ) ;
if ( V_8 < 0 )
goto V_68;
if ( V_7 -> V_12 -> V_55 ) {
V_7 -> V_82 = false ;
V_8 = F_41 ( & V_7 -> V_53 ) ;
} else {
V_7 -> V_82 = true ;
V_8 = F_42 ( V_7 ) ;
}
if ( V_8 < 0 )
goto V_68;
V_8 = F_43 ( V_57 ) ;
V_68:
if ( V_8 < 0 )
F_12 ( V_7 ) ;
return V_8 ;
}
int F_44 ( struct V_6 * V_7 , unsigned int V_32 )
{
unsigned int V_83 ;
T_2 V_11 ;
V_11 = F_3 ( V_7 , V_84 ) ;
if ( ! ( V_11 & F_45 ( V_32 ) ) )
return 0 ;
F_5 ( V_7 , V_85 , F_46 ( V_32 ) ) ;
for ( V_83 = 10 ; V_83 > 0 ; -- V_83 ) {
V_11 = F_3 ( V_7 , V_84 ) ;
if ( ! ( V_11 & F_45 ( V_32 ) ) )
break;
F_47 ( 1000 , 2000 ) ;
}
if ( ! V_83 ) {
F_26 ( V_7 -> V_60 , L_4 , V_32 ) ;
return - V_86 ;
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
F_5 ( V_7 , V_87 , ( 8 << V_88 ) |
( 8 << V_89 ) ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_43 ; ++ V_10 )
F_5 ( V_7 , F_49 ( V_10 ) , V_90 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_12 -> V_79 ; ++ V_10 )
F_5 ( V_7 , F_50 ( V_10 ) , V_90 ) ;
F_5 ( V_7 , V_91 , V_90 ) ;
F_5 ( V_7 , V_92 , V_90 ) ;
F_5 ( V_7 , V_93 , V_90 ) ;
F_5 ( V_7 , V_94 , V_90 ) ;
F_5 ( V_7 , V_95 , V_90 ) ;
F_5 ( V_7 , V_96 , V_90 ) ;
F_5 ( V_7 , V_97 , ( 7 << V_98 ) |
( V_90 << V_99 ) ) ;
F_5 ( V_7 , V_100 , ( 7 << V_98 ) |
( V_90 << V_99 ) ) ;
if ( V_7 -> V_82 )
F_51 ( V_7 ) ;
return 0 ;
}
int F_52 ( struct V_6 * V_7 )
{
int V_8 = 0 ;
F_53 ( & V_7 -> V_101 ) ;
if ( V_7 -> V_102 > 0 )
goto V_68;
V_8 = F_54 ( V_7 -> clock ) ;
if ( V_8 < 0 )
goto V_68;
V_8 = F_48 ( V_7 ) ;
if ( V_8 < 0 ) {
F_55 ( V_7 -> clock ) ;
goto V_68;
}
V_68:
if ( ! V_8 )
V_7 -> V_102 ++ ;
F_56 ( & V_7 -> V_101 ) ;
return V_8 ;
}
void F_57 ( struct V_6 * V_7 )
{
F_53 ( & V_7 -> V_101 ) ;
if ( -- V_7 -> V_102 == 0 )
F_55 ( V_7 -> clock ) ;
F_56 ( & V_7 -> V_101 ) ;
}
static int F_58 ( struct V_103 * V_60 )
{
struct V_6 * V_7 = F_59 ( V_60 ) ;
F_60 ( F_61 ( & V_7 -> V_101 ) ) ;
if ( V_7 -> V_102 == 0 )
return 0 ;
F_62 ( V_7 ) ;
F_55 ( V_7 -> clock ) ;
return 0 ;
}
static int F_63 ( struct V_103 * V_60 )
{
struct V_6 * V_7 = F_59 ( V_60 ) ;
F_60 ( F_61 ( & V_7 -> V_101 ) ) ;
if ( V_7 -> V_102 == 0 )
return 0 ;
F_54 ( V_7 -> clock ) ;
F_64 ( V_7 ) ;
return 0 ;
}
static int F_65 ( struct V_104 * V_105 )
{
struct V_6 * V_7 ;
struct V_106 * V_1 ;
struct V_106 * V_107 ;
unsigned int V_10 ;
T_2 V_108 ;
int V_8 ;
V_7 = F_66 ( & V_105 -> V_60 , sizeof( * V_7 ) , V_109 ) ;
if ( V_7 == NULL )
return - V_110 ;
V_7 -> V_60 = & V_105 -> V_60 ;
F_67 ( & V_7 -> V_101 ) ;
F_68 ( & V_7 -> V_71 ) ;
F_68 ( & V_7 -> V_76 ) ;
V_107 = F_69 ( V_105 , V_111 , 0 ) ;
V_7 -> V_112 = F_70 ( & V_105 -> V_60 , V_107 ) ;
if ( F_28 ( V_7 -> V_112 ) )
return F_29 ( V_7 -> V_112 ) ;
V_7 -> clock = F_71 ( & V_105 -> V_60 , NULL ) ;
if ( F_28 ( V_7 -> clock ) ) {
F_26 ( & V_105 -> V_60 , L_5 ) ;
return F_29 ( V_7 -> clock ) ;
}
V_1 = F_69 ( V_105 , V_113 , 0 ) ;
if ( ! V_1 ) {
F_26 ( & V_105 -> V_60 , L_6 ) ;
return - V_114 ;
}
V_8 = F_72 ( & V_105 -> V_60 , V_1 -> V_115 , F_1 ,
V_116 , F_23 ( & V_105 -> V_60 ) , V_7 ) ;
if ( V_8 < 0 ) {
F_26 ( & V_105 -> V_60 , L_7 ) ;
return V_8 ;
}
V_8 = F_54 ( V_7 -> clock ) ;
if ( V_8 < 0 )
return V_8 ;
V_108 = F_3 ( V_7 , V_117 ) ;
F_55 ( V_7 -> clock ) ;
for ( V_10 = 0 ; V_10 < F_73 ( V_118 ) ; ++ V_10 ) {
if ( ( V_108 & V_119 ) ==
V_118 [ V_10 ] . V_108 ) {
V_7 -> V_12 = & V_118 [ V_10 ] ;
break;
}
}
if ( ! V_7 -> V_12 ) {
F_26 ( & V_105 -> V_60 , L_8 , V_108 ) ;
return - V_120 ;
}
F_74 ( & V_105 -> V_60 , L_9 , V_108 ) ;
V_8 = F_21 ( V_7 ) ;
if ( V_8 < 0 ) {
F_26 ( & V_105 -> V_60 , L_10 ) ;
return V_8 ;
}
F_75 ( V_105 , V_7 ) ;
return 0 ;
}
static int F_76 ( struct V_104 * V_105 )
{
struct V_6 * V_7 = F_77 ( V_105 ) ;
F_12 ( V_7 ) ;
return 0 ;
}
