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
V_7 -> V_48 = F_22 ( V_7 , true ) ;
if ( F_23 ( V_7 -> V_48 ) ) {
V_8 = F_24 ( V_7 -> V_48 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_48 -> V_18 . V_37 , & V_7 -> V_49 ) ;
V_7 -> V_50 = F_22 ( V_7 , false ) ;
if ( F_23 ( V_7 -> V_50 ) ) {
V_8 = F_24 ( V_7 -> V_50 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_50 -> V_18 . V_37 , & V_7 -> V_49 ) ;
if ( V_7 -> V_11 -> V_51 & V_52 ) {
V_7 -> V_53 = F_26 ( V_7 ) ;
if ( F_23 ( V_7 -> V_53 ) ) {
V_8 = F_24 ( V_7 -> V_53 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_53 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
if ( V_7 -> V_11 -> V_51 & V_54 ) {
V_7 -> V_55 = F_27 ( V_7 ) ;
if ( F_23 ( V_7 -> V_55 ) ) {
V_8 = F_24 ( V_7 -> V_55 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_55 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_56 ; ++ V_10 ) {
struct V_13 * V_57 ;
V_57 = F_28 ( V_7 , V_10 ) ;
if ( F_23 ( V_57 ) ) {
V_8 = F_24 ( V_57 ) ;
goto V_47;
}
V_7 -> V_57 [ V_10 ] = V_57 ;
F_25 ( & V_57 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
if ( V_7 -> V_11 -> V_51 & V_58 ) {
V_7 -> V_59 = F_29 ( V_7 ) ;
if ( F_23 ( V_7 -> V_59 ) ) {
V_8 = F_24 ( V_7 -> V_59 ) ;
goto V_47;
}
F_25 ( & V_7 -> V_59 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_60 ; ++ V_10 ) {
struct V_61 * V_62 ;
V_62 = F_30 ( V_7 , V_10 ) ;
if ( F_23 ( V_62 ) ) {
V_8 = F_24 ( V_62 ) ;
goto V_47;
}
V_7 -> V_62 [ V_10 ] = V_62 ;
F_25 ( & V_62 -> V_18 . V_37 , & V_7 -> V_49 ) ;
}
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_12 ; ++ V_10 ) {
struct V_13 * V_14 ;
V_14 = F_31 ( V_7 , V_10 ) ;
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
if ( V_7 -> V_11 -> V_51 & V_52 ) {
V_8 = F_9 (
& V_7 -> V_14 [ 0 ] -> V_18 . V_19 . V_18 , V_63 ,
& V_7 -> V_53 -> V_18 . V_19 . V_18 , V_64 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
}
F_8 (entity, &vsp1->entities, list_dev) {
V_8 = F_32 ( & V_7 -> V_38 ,
& V_18 -> V_19 ) ;
if ( V_8 < 0 )
goto V_47;
}
V_8 = F_33 ( & V_7 -> V_38 ) ;
V_47:
if ( V_8 < 0 )
F_10 ( V_7 ) ;
return V_8 ;
}
static int F_34 ( struct V_6 * V_7 )
{
unsigned int V_10 ;
T_2 V_17 ;
V_17 = F_3 ( V_7 , V_65 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_12 ; ++ V_10 ) {
unsigned int V_66 ;
if ( ! ( V_17 & F_35 ( V_10 ) ) )
continue;
F_5 ( V_7 , V_67 , F_36 ( V_10 ) ) ;
for ( V_66 = 10 ; V_66 > 0 ; -- V_66 ) {
V_17 = F_3 ( V_7 , V_65 ) ;
if ( ! ( V_17 & F_35 ( V_10 ) ) )
break;
F_37 ( 1000 , 2000 ) ;
}
if ( ! V_66 ) {
F_20 ( V_7 -> V_44 , L_5 , V_10 ) ;
return - V_68 ;
}
}
F_5 ( V_7 , V_69 , ( 8 << V_70 ) |
( 8 << V_71 ) ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_56 ; ++ V_10 )
F_5 ( V_7 , F_38 ( V_10 ) , V_72 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_11 -> V_60 ; ++ V_10 )
F_5 ( V_7 , F_39 ( V_10 ) , V_72 ) ;
F_5 ( V_7 , V_73 , V_72 ) ;
F_5 ( V_7 , V_74 , V_72 ) ;
F_5 ( V_7 , V_75 , V_72 ) ;
F_5 ( V_7 , V_76 , V_72 ) ;
F_5 ( V_7 , V_77 , V_72 ) ;
F_5 ( V_7 , V_78 , V_72 ) ;
F_5 ( V_7 , V_79 , ( 7 << V_80 ) |
( V_72 << V_81 ) ) ;
F_5 ( V_7 , V_82 , ( 7 << V_80 ) |
( V_72 << V_81 ) ) ;
return 0 ;
}
static int F_40 ( struct V_6 * V_7 )
{
int V_8 ;
V_8 = F_41 ( V_7 -> clock ) ;
if ( V_8 < 0 )
return V_8 ;
if ( F_23 ( V_7 -> V_83 ) )
return 0 ;
V_8 = F_41 ( V_7 -> V_83 ) ;
if ( V_8 < 0 ) {
F_42 ( V_7 -> clock ) ;
return V_8 ;
}
return 0 ;
}
static void F_43 ( struct V_6 * V_7 )
{
if ( ! F_23 ( V_7 -> V_83 ) )
F_42 ( V_7 -> V_83 ) ;
F_42 ( V_7 -> clock ) ;
}
struct V_6 * F_44 ( struct V_6 * V_7 )
{
struct V_6 * V_84 = V_7 ;
int V_8 ;
F_45 ( & V_7 -> V_85 ) ;
if ( V_7 -> V_86 > 0 )
goto V_47;
V_8 = F_40 ( V_7 ) ;
if ( V_8 < 0 ) {
V_84 = NULL ;
goto V_47;
}
V_8 = F_34 ( V_7 ) ;
if ( V_8 < 0 ) {
F_43 ( V_7 ) ;
V_84 = NULL ;
goto V_47;
}
V_47:
if ( V_84 )
V_7 -> V_86 ++ ;
F_46 ( & V_7 -> V_85 ) ;
return V_84 ;
}
void F_47 ( struct V_6 * V_7 )
{
F_45 ( & V_7 -> V_85 ) ;
if ( -- V_7 -> V_86 == 0 )
F_43 ( V_7 ) ;
F_46 ( & V_7 -> V_85 ) ;
}
static int F_48 ( struct V_87 * V_44 )
{
struct V_6 * V_7 = F_49 ( V_44 ) ;
F_50 ( F_51 ( & V_7 -> V_85 ) ) ;
if ( V_7 -> V_86 == 0 )
return 0 ;
F_43 ( V_7 ) ;
return 0 ;
}
static int F_52 ( struct V_87 * V_44 )
{
struct V_6 * V_7 = F_49 ( V_44 ) ;
F_50 ( F_51 ( & V_7 -> V_85 ) ) ;
if ( V_7 -> V_86 )
return 0 ;
return F_40 ( V_7 ) ;
}
static struct V_88 *
F_53 ( struct V_89 * V_90 )
{
struct V_88 * V_11 = V_90 -> V_44 . V_91 ;
if ( V_11 == NULL ) {
F_20 ( & V_90 -> V_44 , L_6 ) ;
return NULL ;
}
if ( V_11 -> V_56 <= 0 || V_11 -> V_56 > V_92 ) {
F_20 ( & V_90 -> V_44 , L_7 ,
V_11 -> V_56 ) ;
return NULL ;
}
if ( V_11 -> V_60 <= 0 || V_11 -> V_60 > V_93 ) {
F_20 ( & V_90 -> V_44 , L_8 ,
V_11 -> V_60 ) ;
return NULL ;
}
if ( V_11 -> V_12 <= 0 || V_11 -> V_12 > V_94 ) {
F_20 ( & V_90 -> V_44 , L_9 ,
V_11 -> V_12 ) ;
return NULL ;
}
return V_11 ;
}
static int F_54 ( struct V_89 * V_90 )
{
struct V_6 * V_7 ;
struct V_95 * V_1 ;
struct V_95 * V_96 ;
int V_8 ;
V_7 = F_55 ( & V_90 -> V_44 , sizeof( * V_7 ) , V_97 ) ;
if ( V_7 == NULL )
return - V_98 ;
V_7 -> V_44 = & V_90 -> V_44 ;
F_56 ( & V_7 -> V_85 ) ;
F_57 ( & V_7 -> V_49 ) ;
V_7 -> V_11 = F_53 ( V_90 ) ;
if ( V_7 -> V_11 == NULL )
return - V_99 ;
V_96 = F_58 ( V_90 , V_100 , 0 ) ;
V_7 -> V_101 = F_59 ( & V_90 -> V_44 , V_96 ) ;
if ( F_23 ( V_7 -> V_101 ) )
return F_24 ( V_7 -> V_101 ) ;
V_7 -> clock = F_60 ( & V_90 -> V_44 , NULL ) ;
if ( F_23 ( V_7 -> clock ) ) {
F_20 ( & V_90 -> V_44 , L_10 ) ;
return F_24 ( V_7 -> clock ) ;
}
V_7 -> V_83 = F_60 ( & V_90 -> V_44 , L_11 ) ;
V_1 = F_58 ( V_90 , V_102 , 0 ) ;
if ( ! V_1 ) {
F_20 ( & V_90 -> V_44 , L_12 ) ;
return - V_103 ;
}
V_8 = F_61 ( & V_90 -> V_44 , V_1 -> V_104 , F_1 ,
V_105 , F_18 ( & V_90 -> V_44 ) , V_7 ) ;
if ( V_8 < 0 ) {
F_20 ( & V_90 -> V_44 , L_13 ) ;
return V_8 ;
}
V_8 = F_16 ( V_7 ) ;
if ( V_8 < 0 ) {
F_20 ( & V_90 -> V_44 , L_14 ) ;
return V_8 ;
}
F_62 ( V_90 , V_7 ) ;
return 0 ;
}
static int F_63 ( struct V_89 * V_90 )
{
struct V_6 * V_7 = F_64 ( V_90 ) ;
F_10 ( V_7 ) ;
return 0 ;
}
