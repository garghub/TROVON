static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_2 -> V_5 . V_4 = V_4 ;
F_2 ( & V_2 -> V_5 . V_6 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 ;
F_4 (state, plane, plane_state, i)
F_5 ( V_8 -> V_4 -> V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_3 ( V_4 ) ;
F_7 ( V_14 , V_4 ) ;
F_8 ( V_14 , V_4 , false ) ;
F_9 ( V_14 , V_4 ) ;
F_10 ( V_14 , V_4 ) ;
F_11 ( V_14 , V_4 ) ;
F_12 ( V_4 ) ;
}
static void F_13 ( struct V_15 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ,
struct V_1 , V_5 . V_6 ) ;
F_6 ( V_2 , V_2 -> V_5 . V_4 ) ;
}
static int F_15 ( struct V_13 * V_14 ,
struct V_3 * V_4 ,
bool V_16 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
int V_18 ;
V_18 = F_16 ( V_14 , V_4 ) ;
if ( V_18 )
return V_18 ;
F_17 ( & V_2 -> V_5 . V_19 ) ;
F_18 ( & V_2 -> V_5 . V_6 ) ;
F_19 ( V_14 , V_4 ) ;
if ( V_16 )
F_1 ( V_2 , V_4 ) ;
else
F_6 ( V_2 , V_4 ) ;
F_20 ( & V_2 -> V_5 . V_19 ) ;
return 0 ;
}
static int F_21 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_17 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
int V_18 ;
if ( ! F_22 ( & V_24 ) )
return - V_25 ;
V_21 = F_23 ( V_2 -> V_26 ) ;
if ( ! V_21 ) {
F_24 ( V_14 -> V_27 , L_1 ,
V_2 -> V_26 -> V_28 ) ;
F_25 ( V_2 -> V_26 ) ;
return - V_25 ;
}
V_2 -> V_29 = & V_21 -> V_27 ;
F_26 ( V_14 ) ;
V_14 -> V_30 . V_31 = 64 ;
V_14 -> V_30 . V_32 = 64 ;
V_14 -> V_30 . V_33 = 4096 ;
V_14 -> V_30 . V_34 = 4096 ;
V_14 -> V_30 . V_35 = & V_36 ;
V_18 = F_27 ( V_14 -> V_27 , V_14 ) ;
if ( V_18 )
goto V_37;
V_18 = F_28 ( V_14 , V_38 , F_29 ( V_38 ) ) ;
if ( V_18 < 0 )
goto V_39;
V_18 = F_28 ( V_14 , V_40 , F_29 ( V_40 ) ) ;
if ( V_18 < 0 )
goto V_39;
V_23 = V_2 -> V_41 [ V_38 [ 0 ] ] ? :
V_2 -> V_41 [ V_40 [ 0 ] ] ;
V_21 = F_23 ( V_23 ) ;
if ( ! V_21 ) {
V_18 = - V_42 ;
F_24 ( V_14 -> V_27 , L_2 ) ;
goto V_39;
}
V_2 -> V_43 = & V_21 -> V_27 ;
V_14 -> V_44 = true ;
V_18 = F_30 ( V_14 , V_45 ) ;
if ( V_18 < 0 )
goto V_39;
F_31 ( V_14 ) ;
F_32 ( V_14 ) ;
return 0 ;
V_39:
F_33 ( V_14 -> V_27 , V_14 ) ;
V_37:
F_34 ( V_14 ) ;
return V_18 ;
}
static void F_35 ( struct V_13 * V_14 )
{
F_36 ( V_14 ) ;
F_37 ( V_14 ) ;
F_33 ( V_14 -> V_27 , V_14 ) ;
F_34 ( V_14 ) ;
}
static int F_38 ( struct V_46 * V_27 , void * V_47 )
{
return V_27 -> V_48 == V_47 ;
}
static int F_39 ( struct V_46 * V_27 )
{
struct V_1 * V_2 = F_40 ( V_27 ) ;
struct V_13 * V_14 ;
int V_18 ;
V_14 = F_41 ( & V_49 , V_27 ) ;
if ( ! V_14 )
return - V_50 ;
F_42 ( V_14 , F_43 ( V_27 ) ) ;
V_14 -> V_17 = V_2 ;
V_2 -> V_14 = V_14 ;
V_18 = F_21 ( V_14 ) ;
if ( V_18 < 0 )
goto V_51;
V_18 = F_44 ( V_14 , 0 ) ;
if ( V_18 < 0 )
goto V_52;
V_18 = F_45 ( V_14 ) ;
if ( V_18 < 0 )
goto V_53;
return 0 ;
V_53:
F_46 ( V_14 ) ;
V_52:
F_35 ( V_14 ) ;
V_51:
F_47 ( V_14 ) ;
return V_18 ;
}
static void F_48 ( struct V_46 * V_27 )
{
struct V_1 * V_2 = F_40 ( V_27 ) ;
F_49 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
static int F_50 ( struct V_20 * V_21 )
{
struct V_46 * V_27 = & V_21 -> V_27 ;
struct V_1 * V_2 ;
struct V_54 * V_55 ;
struct V_22 * V_56 ;
struct V_57 * V_58 = NULL ;
int V_18 ;
int V_11 ;
V_2 = F_51 ( V_27 , sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_50 ;
F_52 ( & V_2 -> V_5 . V_19 ) ;
F_53 ( & V_2 -> V_5 . V_6 , F_13 ) ;
V_55 = F_54 ( V_21 , V_60 , 0 ) ;
V_2 -> V_61 = F_55 ( V_27 , V_55 ) ;
if ( F_56 ( V_2 -> V_61 ) ) {
V_18 = F_57 ( V_2 -> V_61 ) ;
F_24 ( V_27 , L_3 ,
V_18 ) ;
return V_18 ;
}
F_58 (dev->of_node->parent, node) {
const struct V_62 * V_63 ;
enum V_64 V_65 ;
int V_66 ;
V_63 = F_59 ( V_67 , V_56 ) ;
if ( ! V_63 )
continue;
if ( ! F_60 ( V_56 ) ) {
F_61 ( V_27 , L_4 ,
V_56 -> V_28 ) ;
continue;
}
V_65 = (enum V_64 ) V_63 -> V_47 ;
if ( V_65 == V_68 ) {
V_2 -> V_26 = F_62 ( V_56 ) ;
continue;
}
V_66 = F_63 ( V_56 , V_65 ) ;
if ( V_66 < 0 ) {
F_64 ( V_27 , L_5 ,
V_56 -> V_28 ) ;
continue;
}
V_2 -> V_41 [ V_66 ] = F_62 ( V_56 ) ;
if ( V_65 == V_69 ||
V_65 == V_70 ||
V_65 == V_71 ||
V_65 == V_72 ) {
F_65 ( V_27 , L_6 ,
V_56 -> V_28 ) ;
F_66 ( V_27 , & V_58 , F_38 , V_56 ) ;
} else {
struct V_73 * V_74 ;
V_74 = F_51 ( V_27 , sizeof( * V_74 ) , V_59 ) ;
if ( ! V_74 ) {
V_18 = - V_50 ;
goto V_75;
}
V_18 = F_67 ( V_27 , V_56 , V_74 , V_66 , NULL ) ;
if ( V_18 )
goto V_75;
V_2 -> V_76 [ V_66 ] = V_74 ;
}
}
if ( ! V_2 -> V_26 ) {
F_24 ( V_27 , L_7 ) ;
V_18 = - V_42 ;
goto V_75;
}
F_68 ( V_27 ) ;
F_69 ( V_21 , V_2 ) ;
V_18 = F_70 ( V_27 , & V_77 , V_58 ) ;
if ( V_18 )
goto V_78;
return 0 ;
V_78:
F_71 ( V_27 ) ;
V_75:
F_25 ( V_2 -> V_26 ) ;
for ( V_11 = 0 ; V_11 < V_79 ; V_11 ++ )
F_25 ( V_2 -> V_41 [ V_11 ] ) ;
return V_18 ;
}
static int F_72 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_73 ( V_21 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_11 ;
F_74 ( V_14 ) ;
F_46 ( V_14 ) ;
F_35 ( V_14 ) ;
F_47 ( V_14 ) ;
F_75 ( & V_21 -> V_27 , & V_77 ) ;
F_71 ( & V_21 -> V_27 ) ;
F_25 ( V_2 -> V_26 ) ;
for ( V_11 = 0 ; V_11 < V_79 ; V_11 ++ )
F_25 ( V_2 -> V_41 [ V_11 ] ) ;
return 0 ;
}
static int F_76 ( struct V_46 * V_27 )
{
struct V_1 * V_2 = F_40 ( V_27 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
F_77 ( V_14 ) ;
V_2 -> V_80 = F_78 ( V_14 ) ;
if ( F_56 ( V_2 -> V_80 ) ) {
F_79 ( V_14 ) ;
return F_57 ( V_2 -> V_80 ) ;
}
F_80 ( L_8 ) ;
return 0 ;
}
static int F_81 ( struct V_46 * V_27 )
{
struct V_1 * V_2 = F_40 ( V_27 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
F_82 ( V_14 , V_2 -> V_80 ) ;
F_79 ( V_14 ) ;
F_80 ( L_9 ) ;
return 0 ;
}
static int T_1 F_83 ( void )
{
int V_18 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_29 ( V_81 ) ; V_11 ++ ) {
V_18 = F_84 ( V_81 [ V_11 ] ) ;
if ( V_18 < 0 ) {
F_85 ( L_10 ,
V_81 [ V_11 ] -> V_82 . V_83 , V_18 ) ;
goto V_84;
}
}
return 0 ;
V_84:
while ( -- V_11 >= 0 )
F_86 ( V_81 [ V_11 ] ) ;
return V_18 ;
}
static void T_2 F_87 ( void )
{
int V_11 ;
for ( V_11 = F_29 ( V_81 ) - 1 ; V_11 >= 0 ; V_11 -- )
F_86 ( V_81 [ V_11 ] ) ;
}
