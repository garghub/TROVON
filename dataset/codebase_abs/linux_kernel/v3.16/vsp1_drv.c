static T_1 F_1 ( int V_1 , void * V_2 )
{
T_2 V_3 = V_4 | V_5 ;
struct V_6 * V_7 = V_2 ;
T_1 V_8 = V_9 ;
unsigned int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_12 ; ++ V_10 ) {
struct V_13 * V_14 = V_7 -> V_14 [ V_10 ] ;
struct V_15 * V_16 ;
T_2 V_17 ;
if ( V_14 == NULL )
continue;
V_16 = F_2 ( & V_14 -> V_18 . V_19 . V_18 ) ;
V_17 = F_3 ( V_7 , F_4 ( V_10 ) ) ;
F_5 ( V_7 , F_4 ( V_10 ) , ~ V_17 & V_3 ) ;
if ( V_17 & V_5 ) {
F_6 ( V_16 ) ;
V_8 = V_20 ;
}
}
return V_8 ;
}
static int F_7 ( struct V_6 * V_7 , struct V_21 * V_22 )
{
struct V_23 * V_18 = & V_22 -> V_19 . V_18 ;
struct V_21 * V_24 ;
unsigned int V_25 ;
int V_8 ;
F_8 (source, &vsp1->entities, list_dev) {
T_2 V_26 ;
if ( V_24 -> type == V_22 -> type )
continue;
if ( V_24 -> type == V_27 ||
V_24 -> type == V_28 )
continue;
V_26 = V_24 -> type == V_29 &&
V_22 -> type == V_28 &&
V_24 -> V_30 == V_22 -> V_30
? V_31 : 0 ;
for ( V_25 = 0 ; V_25 < V_18 -> V_32 ; ++ V_25 ) {
if ( ! ( V_18 -> V_33 [ V_25 ] . V_26 & V_34 ) )
continue;
V_8 = F_9 ( & V_24 -> V_19 . V_18 ,
V_24 -> V_35 ,
V_18 , V_25 , V_26 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_26 & V_31 )
V_24 -> V_22 = V_18 ;
}
}
return 0 ;
}
static void F_10 ( struct V_6 * V_7 )
{
struct V_21 * V_18 ;
struct V_21 * V_36 ;
F_11 (entity, next, &vsp1->entities, list_dev) {
F_12 ( & V_18 -> V_37 ) ;
F_13 ( V_18 ) ;
}
F_14 ( & V_7 -> V_38 ) ;
F_15 ( & V_7 -> V_39 ) ;
}
static int F_16 ( struct V_6 * V_7 )
{
struct V_40 * V_41 = & V_7 -> V_39 ;
struct V_42 * V_43 = & V_7 -> V_38 ;
struct V_21 * V_18 ;
unsigned int V_10 ;
int V_8 ;
V_41 -> V_44 = V_7 -> V_44 ;
F_17 ( V_41 -> V_45 , L_1 , sizeof( V_41 -> V_45 ) ) ;
snprintf ( V_41 -> V_46 , sizeof( V_41 -> V_46 ) , L_2 ,
F_18 ( V_41 -> V_44 ) ) ;
V_8 = F_19 ( V_41 ) ;
if ( V_8 < 0 ) {
F_20 ( V_7 -> V_44 , L_3 ,
V_8 ) ;
return V_8 ;
}
V_43 -> V_41 = V_41 ;
V_8 = F_21 ( V_7 -> V_44 , V_43 ) ;
if ( V_8 < 0 ) {
F_20 ( V_7 -> V_44 , L_4 ,
V_8 ) ;
goto V_47;
}
V_7 -> V_48 = F_22 ( V_7 ) ;
if ( F_23 ( V_7 -> V_48 ) ) {
V_8 = F_24 ( V_7 -> V_48 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_48 -> V_18 . V_37 , & V_7 -> V_49 ) ;
V_7 -> V_50 = F_26 ( V_7 , true ) ;
if ( F_23 ( V_7 -> V_50 ) ) {
V_8 = F_24 ( V_7 -> V_50 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_50 -> V_18 . V_37 , & V_7 -> V_49 ) ;
V_7 -> V_51 = F_26 ( V_7 , false ) ;
if ( F_23 ( V_7 -> V_51 ) ) {
V_8 = F_24 ( V_7 -> V_51 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_51 -> V_18 . V_37 , & V_7 -> V_49 ) ;
if ( V_7 -> V_11 -> V_52 & V_53 ) {
V_7 -> V_54 = F_27 ( V_7 ) ;
if ( F_23 ( V_7 -> V_54 ) ) {
V_8 = F_24 ( V_7 -> V_54 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_54 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
if ( V_7 -> V_11 -> V_52 & V_55 ) {
V_7 -> V_56 = F_28 ( V_7 ) ;
if ( F_23 ( V_7 -> V_56 ) ) {
V_8 = F_24 ( V_7 -> V_56 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_56 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_57 ; ++ V_10 ) {
struct V_13 * V_58 ;
V_58 = F_29 ( V_7 , V_10 ) ;
if ( F_23 ( V_58 ) ) {
V_8 = F_24 ( V_58 ) ;
goto V_47;
}
V_7 -> V_58 [ V_10 ] = V_58 ;
F_25 ( & V_58 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
if ( V_7 -> V_11 -> V_52 & V_59 ) {
V_7 -> V_60 = F_30 ( V_7 ) ;
if ( F_23 ( V_7 -> V_60 ) ) {
V_8 = F_24 ( V_7 -> V_60 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_60 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_61 ; ++ V_10 ) {
struct V_62 * V_63 ;
V_63 = F_31 ( V_7 , V_10 ) ;
if ( F_23 ( V_63 ) ) {
V_8 = F_24 ( V_63 ) ;
goto V_47;
}
V_7 -> V_63 [ V_10 ] = V_63 ;
F_25 ( & V_63 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_12 ; ++ V_10 ) {
struct V_13 * V_14 ;
V_14 = F_32 ( V_7 , V_10 ) ;
if ( F_23 ( V_14 ) ) {
V_8 = F_24 ( V_14 ) ;
goto V_47;
}
V_7 -> V_14 [ V_10 ] = V_14 ;
F_25 ( & V_14 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
F_8 (entity, &vsp1->entities, list_dev) {
if ( V_18 -> type == V_27 ||
V_18 -> type == V_29 )
continue;
V_8 = F_7 ( V_7 , V_18 ) ;
if ( V_8 < 0 )
goto V_47;
}
if ( V_7 -> V_11 -> V_52 & V_53 ) {
V_8 = F_9 (
& V_7 -> V_14 [ 0 ] -> V_18 . V_19 . V_18 , V_64 ,
& V_7 -> V_54 -> V_18 . V_19 . V_18 , V_65 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
F_8 (entity, &vsp1->entities, list_dev) {
V_8 = F_33 ( & V_7 -> V_38 ,
& V_18 -> V_19 ) ;
if ( V_8 < 0 )
goto V_47;
}
V_8 = F_34 ( & V_7 -> V_38 ) ;
V_47:
if ( V_8 < 0 )
F_10 ( V_7 ) ;
return V_8 ;
}
static int F_35 ( struct V_6 * V_7 )
{
unsigned int V_10 ;
T_2 V_17 ;
V_17 = F_3 ( V_7 , V_66 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_12 ; ++ V_10 ) {
unsigned int V_67 ;
if ( ! ( V_17 & F_36 ( V_10 ) ) )
continue;
F_5 ( V_7 , V_68 , F_37 ( V_10 ) ) ;
for ( V_67 = 10 ; V_67 > 0 ; -- V_67 ) {
V_17 = F_3 ( V_7 , V_66 ) ;
if ( ! ( V_17 & F_36 ( V_10 ) ) )
break;
F_38 ( 1000 , 2000 ) ;
}
if ( ! V_67 ) {
F_20 ( V_7 -> V_44 , L_5 , V_10 ) ;
return - V_69 ;
}
}
F_5 ( V_7 , V_70 , ( 8 << V_71 ) |
( 8 << V_72 ) ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_57 ; ++ V_10 )
F_5 ( V_7 , F_39 ( V_10 ) , V_73 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_61 ; ++ V_10 )
F_5 ( V_7 , F_40 ( V_10 ) , V_73 ) ;
F_5 ( V_7 , V_74 , V_73 ) ;
F_5 ( V_7 , V_75 , V_73 ) ;
F_5 ( V_7 , V_76 , V_73 ) ;
F_5 ( V_7 , V_77 , V_73 ) ;
F_5 ( V_7 , V_78 , V_73 ) ;
F_5 ( V_7 , V_79 , V_73 ) ;
F_5 ( V_7 , V_80 , ( 7 << V_81 ) |
( V_73 << V_82 ) ) ;
F_5 ( V_7 , V_83 , ( 7 << V_81 ) |
( V_73 << V_82 ) ) ;
return 0 ;
}
struct V_6 * F_41 ( struct V_6 * V_7 )
{
struct V_6 * V_84 = V_7 ;
int V_8 ;
F_42 ( & V_7 -> V_85 ) ;
if ( V_7 -> V_86 > 0 )
goto V_47;
V_8 = F_43 ( V_7 -> clock ) ;
if ( V_8 < 0 ) {
V_84 = NULL ;
goto V_47;
}
V_8 = F_35 ( V_7 ) ;
if ( V_8 < 0 ) {
F_44 ( V_7 -> clock ) ;
V_84 = NULL ;
goto V_47;
}
V_47:
if ( V_84 )
V_7 -> V_86 ++ ;
F_45 ( & V_7 -> V_85 ) ;
return V_84 ;
}
void F_46 ( struct V_6 * V_7 )
{
F_42 ( & V_7 -> V_85 ) ;
if ( -- V_7 -> V_86 == 0 )
F_44 ( V_7 -> clock ) ;
F_45 ( & V_7 -> V_85 ) ;
}
static int F_47 ( struct V_87 * V_44 )
{
struct V_6 * V_7 = F_48 ( V_44 ) ;
F_49 ( F_50 ( & V_7 -> V_85 ) ) ;
if ( V_7 -> V_86 == 0 )
return 0 ;
F_44 ( V_7 -> clock ) ;
return 0 ;
}
static int F_51 ( struct V_87 * V_44 )
{
struct V_6 * V_7 = F_48 ( V_44 ) ;
F_49 ( F_50 ( & V_7 -> V_85 ) ) ;
if ( V_7 -> V_86 )
return 0 ;
return F_43 ( V_7 -> clock ) ;
}
static int F_52 ( struct V_88 * V_89 ,
struct V_90 * V_11 )
{
if ( V_11 == NULL ) {
F_20 ( & V_89 -> V_44 , L_6 ) ;
return - V_91 ;
}
if ( V_11 -> V_57 <= 0 || V_11 -> V_57 > V_92 ) {
F_20 ( & V_89 -> V_44 , L_7 ,
V_11 -> V_57 ) ;
return - V_91 ;
}
if ( V_11 -> V_61 <= 0 || V_11 -> V_61 > V_93 ) {
F_20 ( & V_89 -> V_44 , L_8 ,
V_11 -> V_61 ) ;
return - V_91 ;
}
if ( V_11 -> V_12 <= 0 || V_11 -> V_12 > V_94 ) {
F_20 ( & V_89 -> V_44 , L_9 ,
V_11 -> V_12 ) ;
return - V_91 ;
}
return 0 ;
}
static struct V_90 *
F_53 ( struct V_88 * V_89 )
{
struct V_95 * V_96 = V_89 -> V_44 . V_97 ;
struct V_90 * V_11 ;
if ( ! F_54 ( V_98 ) || V_96 == NULL )
return V_89 -> V_44 . V_99 ;
V_11 = F_55 ( & V_89 -> V_44 , sizeof( * V_11 ) , V_100 ) ;
if ( V_11 == NULL )
return NULL ;
if ( F_56 ( V_96 , L_10 ) )
V_11 -> V_52 |= V_53 ;
if ( F_56 ( V_96 , L_11 ) )
V_11 -> V_52 |= V_55 ;
if ( F_56 ( V_96 , L_12 ) )
V_11 -> V_52 |= V_59 ;
F_57 ( V_96 , L_13 , & V_11 -> V_57 ) ;
F_57 ( V_96 , L_14 , & V_11 -> V_61 ) ;
F_57 ( V_96 , L_15 , & V_11 -> V_12 ) ;
return V_11 ;
}
static int F_58 ( struct V_88 * V_89 )
{
struct V_6 * V_7 ;
struct V_101 * V_1 ;
struct V_101 * V_102 ;
int V_8 ;
V_7 = F_55 ( & V_89 -> V_44 , sizeof( * V_7 ) , V_100 ) ;
if ( V_7 == NULL )
return - V_103 ;
V_7 -> V_44 = & V_89 -> V_44 ;
F_59 ( & V_7 -> V_85 ) ;
F_60 ( & V_7 -> V_49 ) ;
V_7 -> V_11 = F_53 ( V_89 ) ;
if ( V_7 -> V_11 == NULL )
return - V_104 ;
V_8 = F_52 ( V_89 , V_7 -> V_11 ) ;
if ( V_8 < 0 )
return V_8 ;
V_102 = F_61 ( V_89 , V_105 , 0 ) ;
V_7 -> V_106 = F_62 ( & V_89 -> V_44 , V_102 ) ;
if ( F_23 ( V_7 -> V_106 ) )
return F_24 ( V_7 -> V_106 ) ;
V_7 -> clock = F_63 ( & V_89 -> V_44 , NULL ) ;
if ( F_23 ( V_7 -> clock ) ) {
F_20 ( & V_89 -> V_44 , L_16 ) ;
return F_24 ( V_7 -> clock ) ;
}
V_1 = F_61 ( V_89 , V_107 , 0 ) ;
if ( ! V_1 ) {
F_20 ( & V_89 -> V_44 , L_17 ) ;
return - V_91 ;
}
V_8 = F_64 ( & V_89 -> V_44 , V_1 -> V_108 , F_1 ,
V_109 , F_18 ( & V_89 -> V_44 ) , V_7 ) ;
if ( V_8 < 0 ) {
F_20 ( & V_89 -> V_44 , L_18 ) ;
return V_8 ;
}
V_8 = F_16 ( V_7 ) ;
if ( V_8 < 0 ) {
F_20 ( & V_89 -> V_44 , L_19 ) ;
return V_8 ;
}
F_65 ( V_89 , V_7 ) ;
return 0 ;
}
static int F_66 ( struct V_88 * V_89 )
{
struct V_6 * V_7 = F_67 ( V_89 ) ;
F_10 ( V_7 ) ;
return 0 ;
}
