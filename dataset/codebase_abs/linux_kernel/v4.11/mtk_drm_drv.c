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
F_8 ( V_14 , V_4 ) ;
F_9 ( V_14 , V_4 ,
V_15 ) ;
F_10 ( V_14 , V_4 ) ;
F_11 ( V_14 , V_4 ) ;
F_12 ( V_4 ) ;
}
static void F_13 ( struct V_16 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ,
struct V_1 , V_5 . V_6 ) ;
F_6 ( V_2 , V_2 -> V_5 . V_4 ) ;
}
static int F_15 ( struct V_13 * V_14 ,
struct V_3 * V_4 ,
bool V_17 )
{
struct V_1 * V_2 = V_14 -> V_18 ;
int V_19 ;
V_19 = F_16 ( V_14 , V_4 ) ;
if ( V_19 )
return V_19 ;
F_17 ( & V_2 -> V_5 . V_20 ) ;
F_18 ( & V_2 -> V_5 . V_6 ) ;
F_19 ( V_4 , true ) ;
F_20 ( V_4 ) ;
if ( V_17 )
F_1 ( V_2 , V_4 ) ;
else
F_6 ( V_2 , V_4 ) ;
F_21 ( & V_2 -> V_5 . V_20 ) ;
return 0 ;
}
static int F_22 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_18 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_19 ;
if ( ! F_23 ( & V_25 ) )
return - V_26 ;
V_22 = F_24 ( V_2 -> V_27 ) ;
if ( ! V_22 ) {
F_25 ( V_14 -> V_28 , L_1 ,
V_2 -> V_27 -> V_29 ) ;
F_26 ( V_2 -> V_27 ) ;
return - V_26 ;
}
V_2 -> V_30 = & V_22 -> V_28 ;
F_27 ( V_14 ) ;
V_14 -> V_31 . V_32 = 64 ;
V_14 -> V_31 . V_33 = 64 ;
V_14 -> V_31 . V_34 = 4096 ;
V_14 -> V_31 . V_35 = 4096 ;
V_14 -> V_31 . V_36 = & V_37 ;
V_19 = F_28 ( V_14 -> V_28 , V_14 ) ;
if ( V_19 )
goto V_38;
V_19 = F_29 ( V_14 , V_39 , F_30 ( V_39 ) ) ;
if ( V_19 < 0 )
goto V_40;
V_19 = F_29 ( V_14 , V_41 , F_30 ( V_41 ) ) ;
if ( V_19 < 0 )
goto V_40;
V_24 = V_2 -> V_42 [ V_39 [ 0 ] ] ? :
V_2 -> V_42 [ V_41 [ 0 ] ] ;
V_22 = F_24 ( V_24 ) ;
if ( ! V_22 ) {
V_19 = - V_43 ;
F_25 ( V_14 -> V_28 , L_2 ) ;
goto V_40;
}
V_2 -> V_44 = & V_22 -> V_28 ;
V_14 -> V_45 = true ;
V_19 = F_31 ( V_14 , V_46 ) ;
if ( V_19 < 0 )
goto V_40;
F_32 ( V_14 ) ;
F_33 ( V_14 ) ;
return 0 ;
V_40:
F_34 ( V_14 -> V_28 , V_14 ) ;
V_38:
F_35 ( V_14 ) ;
return V_19 ;
}
static void F_36 ( struct V_13 * V_14 )
{
F_37 ( V_14 ) ;
F_38 ( V_14 ) ;
F_34 ( V_14 -> V_28 , V_14 ) ;
F_35 ( V_14 ) ;
}
static int F_39 ( struct V_47 * V_28 , void * V_48 )
{
return V_28 -> V_49 == V_48 ;
}
static int F_40 ( struct V_47 * V_28 )
{
struct V_1 * V_2 = F_41 ( V_28 ) ;
struct V_13 * V_14 ;
int V_19 ;
V_14 = F_42 ( & V_50 , V_28 ) ;
if ( F_43 ( V_14 ) )
return F_44 ( V_14 ) ;
V_14 -> V_18 = V_2 ;
V_2 -> V_14 = V_14 ;
V_19 = F_22 ( V_14 ) ;
if ( V_19 < 0 )
goto V_51;
V_19 = F_45 ( V_14 , 0 ) ;
if ( V_19 < 0 )
goto V_52;
return 0 ;
V_52:
F_36 ( V_14 ) ;
V_51:
F_46 ( V_14 ) ;
return V_19 ;
}
static void F_47 ( struct V_47 * V_28 )
{
struct V_1 * V_2 = F_41 ( V_28 ) ;
F_48 ( V_2 -> V_14 ) ;
F_46 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
static int F_49 ( struct V_21 * V_22 )
{
struct V_47 * V_28 = & V_22 -> V_28 ;
struct V_1 * V_2 ;
struct V_53 * V_54 ;
struct V_23 * V_55 ;
struct V_56 * V_57 = NULL ;
int V_19 ;
int V_11 ;
V_2 = F_50 ( V_28 , sizeof( * V_2 ) , V_58 ) ;
if ( ! V_2 )
return - V_59 ;
F_51 ( & V_2 -> V_5 . V_20 ) ;
F_52 ( & V_2 -> V_5 . V_6 , F_13 ) ;
V_54 = F_53 ( V_22 , V_60 , 0 ) ;
V_2 -> V_61 = F_54 ( V_28 , V_54 ) ;
if ( F_43 ( V_2 -> V_61 ) ) {
V_19 = F_44 ( V_2 -> V_61 ) ;
F_25 ( V_28 , L_3 ,
V_19 ) ;
return V_19 ;
}
F_55 (dev->of_node->parent, node) {
const struct V_62 * V_63 ;
enum V_64 V_65 ;
int V_66 ;
V_63 = F_56 ( V_67 , V_55 ) ;
if ( ! V_63 )
continue;
if ( ! F_57 ( V_55 ) ) {
F_58 ( V_28 , L_4 ,
V_55 -> V_29 ) ;
continue;
}
V_65 = (enum V_64 ) V_63 -> V_48 ;
if ( V_65 == V_68 ) {
V_2 -> V_27 = F_59 ( V_55 ) ;
continue;
}
V_66 = F_60 ( V_55 , V_65 ) ;
if ( V_66 < 0 ) {
F_61 ( V_28 , L_5 ,
V_55 -> V_29 ) ;
continue;
}
V_2 -> V_42 [ V_66 ] = F_59 ( V_55 ) ;
if ( V_65 == V_69 ||
V_65 == V_70 ||
V_65 == V_71 ||
V_65 == V_72 ) {
F_62 ( V_28 , L_6 ,
V_55 -> V_29 ) ;
F_63 ( V_28 , & V_57 , F_39 ,
V_55 ) ;
} else {
struct V_73 * V_74 ;
V_74 = F_50 ( V_28 , sizeof( * V_74 ) , V_58 ) ;
if ( ! V_74 ) {
V_19 = - V_59 ;
goto V_75;
}
V_19 = F_64 ( V_28 , V_55 , V_74 , V_66 , NULL ) ;
if ( V_19 )
goto V_75;
V_2 -> V_76 [ V_66 ] = V_74 ;
}
}
if ( ! V_2 -> V_27 ) {
F_25 ( V_28 , L_7 ) ;
V_19 = - V_43 ;
goto V_75;
}
F_65 ( V_28 ) ;
F_66 ( V_22 , V_2 ) ;
V_19 = F_67 ( V_28 , & V_77 , V_57 ) ;
if ( V_19 )
goto V_78;
return 0 ;
V_78:
F_68 ( V_28 ) ;
V_75:
F_26 ( V_2 -> V_27 ) ;
for ( V_11 = 0 ; V_11 < V_79 ; V_11 ++ )
F_26 ( V_2 -> V_42 [ V_11 ] ) ;
return V_19 ;
}
static int F_69 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_70 ( V_22 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_11 ;
F_48 ( V_14 ) ;
F_36 ( V_14 ) ;
F_46 ( V_14 ) ;
F_71 ( & V_22 -> V_28 , & V_77 ) ;
F_68 ( & V_22 -> V_28 ) ;
F_26 ( V_2 -> V_27 ) ;
for ( V_11 = 0 ; V_11 < V_79 ; V_11 ++ )
F_26 ( V_2 -> V_42 [ V_11 ] ) ;
return 0 ;
}
static int F_72 ( struct V_47 * V_28 )
{
struct V_1 * V_2 = F_41 ( V_28 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
F_73 ( V_14 ) ;
V_2 -> V_80 = F_74 ( V_14 ) ;
if ( F_43 ( V_2 -> V_80 ) ) {
F_75 ( V_14 ) ;
return F_44 ( V_2 -> V_80 ) ;
}
F_76 ( L_8 ) ;
return 0 ;
}
static int F_77 ( struct V_47 * V_28 )
{
struct V_1 * V_2 = F_41 ( V_28 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
F_78 ( V_14 , V_2 -> V_80 ) ;
F_75 ( V_14 ) ;
F_76 ( L_9 ) ;
return 0 ;
}
static int T_1 F_79 ( void )
{
int V_19 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < F_30 ( V_81 ) ; V_11 ++ ) {
V_19 = F_80 ( V_81 [ V_11 ] ) ;
if ( V_19 < 0 ) {
F_81 ( L_10 ,
V_81 [ V_11 ] -> V_82 . V_83 , V_19 ) ;
goto V_84;
}
}
return 0 ;
V_84:
while ( -- V_11 >= 0 )
F_82 ( V_81 [ V_11 ] ) ;
return V_19 ;
}
static void T_2 F_83 ( void )
{
int V_11 ;
for ( V_11 = F_30 ( V_81 ) - 1 ; V_11 >= 0 ; V_11 -- )
F_82 ( V_81 [ V_11 ] ) ;
}
