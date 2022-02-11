int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_4 -> V_6 - V_4 -> V_7 ;
int V_8 = V_4 -> V_9 - V_4 -> V_10 ;
int V_11 = V_4 -> V_10 - V_4 -> V_6 ;
int V_12 = V_4 -> V_13 - V_4 -> V_14 ;
int V_15 = V_4 -> V_16 - V_4 -> V_17 ;
int V_18 = V_4 -> V_17 - V_4 -> V_13 ;
if ( V_18 > V_2 -> V_19 -> V_20 + 1 || V_18 < 1 )
return V_21 ;
if ( V_11 > V_2 -> V_19 -> V_20 + 1 || V_11 < 1 )
return V_22 ;
if ( V_12 > V_2 -> V_19 -> V_23 + 1 || V_12 < 1 ||
V_15 > V_2 -> V_19 -> V_23 + 1 || V_15 < 1 ||
V_4 -> V_14 < 1 )
return V_24 ;
if ( V_5 > V_2 -> V_19 -> V_25 + 1 || V_5 < 1 ||
V_8 > V_2 -> V_19 -> V_25 || V_8 < 0 ||
V_4 -> V_7 < 1 )
return V_26 ;
return V_27 ;
}
static void F_2 ( struct V_28 * V_29 )
{
if ( ! V_29 )
return;
if ( V_29 -> V_19 -> type == V_30 ||
V_29 -> V_19 -> type == V_31 ||
V_29 -> V_19 -> type == V_32 )
F_3 ( F_4 ( V_29 ) ) ;
}
static T_1 F_5 ( int V_33 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
struct V_1 * V_2 = V_36 -> V_37 ;
unsigned long V_38 ;
unsigned int V_39 , V_40 ;
int V_41 ;
F_6 ( V_2 -> V_42 -> V_43 , V_44 , & V_39 ) ;
F_6 ( V_2 -> V_42 -> V_43 , V_45 , & V_40 ) ;
V_38 = V_39 & V_40 ;
if ( ! V_38 )
return V_46 ;
if ( V_38 & V_47 )
F_7 ( V_2 -> V_48 ) ;
for ( V_41 = 0 ; V_41 < V_49 ; V_41 ++ ) {
if ( F_8 ( V_41 ) & V_38 )
F_2 ( V_2 -> V_50 [ V_41 ] ) ;
}
return V_51 ;
}
static struct V_52 * F_9 ( struct V_35 * V_36 ,
struct V_53 * V_54 , const struct V_55 * V_56 )
{
return F_10 ( V_36 , V_54 , V_56 ) ;
}
static void F_11 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
if ( V_2 -> V_57 )
F_12 ( V_2 -> V_57 ) ;
}
static void
F_13 ( struct V_58 * V_59 )
{
struct V_35 * V_36 = V_59 -> V_36 ;
struct V_1 * V_2 = V_36 -> V_37 ;
struct V_60 * V_61 = V_59 -> V_62 ;
F_14 ( V_36 , V_61 ) ;
F_15 ( V_36 , V_61 , 0 ) ;
F_16 ( V_36 , V_61 ) ;
F_17 ( V_36 , V_61 ) ;
F_18 ( V_36 , V_61 ) ;
F_19 ( V_61 ) ;
F_20 ( & V_2 -> V_59 . V_63 . V_64 ) ;
V_2 -> V_59 . V_65 = false ;
F_21 ( & V_2 -> V_59 . V_63 ) ;
F_22 ( & V_2 -> V_59 . V_63 . V_64 ) ;
F_23 ( V_59 ) ;
}
static void F_24 ( struct V_66 * V_67 )
{
struct V_58 * V_59 =
F_25 ( V_67 , struct V_58 , V_67 ) ;
F_13 ( V_59 ) ;
}
static int F_26 ( struct V_35 * V_36 ,
struct V_60 * V_62 ,
bool V_68 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
struct V_58 * V_59 ;
int V_69 ;
V_69 = F_27 ( V_36 , V_62 ) ;
if ( V_69 )
return V_69 ;
V_59 = F_28 ( sizeof( * V_59 ) , V_70 ) ;
if ( ! V_59 ) {
V_69 = - V_71 ;
goto error;
}
F_29 ( & V_59 -> V_67 , F_24 ) ;
V_59 -> V_36 = V_36 ;
V_59 -> V_62 = V_62 ;
F_20 ( & V_2 -> V_59 . V_63 . V_64 ) ;
V_69 = F_30 ( V_2 -> V_59 . V_63 ,
! V_2 -> V_59 . V_65 ) ;
if ( V_69 == 0 )
V_2 -> V_59 . V_65 = true ;
F_22 ( & V_2 -> V_59 . V_63 . V_64 ) ;
if ( V_69 ) {
F_23 ( V_59 ) ;
goto error;
}
F_31 ( V_62 , true ) ;
F_32 ( V_62 ) ;
if ( V_68 )
F_33 ( V_2 -> V_72 , & V_59 -> V_67 ) ;
else
F_13 ( V_59 ) ;
return 0 ;
error:
F_18 ( V_36 , V_62 ) ;
return V_69 ;
}
static int F_34 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
int V_69 ;
F_35 ( V_36 ) ;
V_69 = F_36 ( V_36 ) ;
if ( V_69 ) {
F_37 ( V_36 -> V_36 , L_1 , V_69 ) ;
return V_69 ;
}
V_69 = F_38 ( V_36 ) ;
if ( V_69 ) {
F_37 ( V_36 -> V_36 , L_2 , V_69 ) ;
return V_69 ;
}
V_69 = F_39 ( V_36 ) ;
if ( V_69 ) {
F_37 ( V_36 -> V_36 , L_3 ) ;
return V_69 ;
}
V_36 -> V_73 . V_74 = V_2 -> V_19 -> V_74 ;
V_36 -> V_73 . V_75 = V_2 -> V_19 -> V_75 ;
V_36 -> V_73 . V_76 = V_2 -> V_19 -> V_76 ;
V_36 -> V_73 . V_77 = V_2 -> V_19 -> V_77 ;
V_36 -> V_73 . V_78 = & V_79 ;
return 0 ;
}
static int F_40 ( struct V_35 * V_36 )
{
struct V_80 * V_81 = F_41 ( V_36 -> V_36 ) ;
const struct V_82 * V_83 ;
struct V_1 * V_2 ;
int V_69 ;
V_83 = F_42 ( V_84 , V_36 -> V_36 -> V_85 -> V_86 ) ;
if ( ! V_83 ) {
F_37 ( & V_81 -> V_36 , L_4 ) ;
return - V_87 ;
}
if ( ! V_83 -> V_34 ) {
F_37 ( & V_81 -> V_36 , L_5 ) ;
return - V_88 ;
}
V_2 = F_43 ( V_36 -> V_36 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_72 = F_44 ( L_6 , 0 ) ;
if ( ! V_2 -> V_72 )
return - V_71 ;
F_45 ( & V_2 -> V_59 . V_63 ) ;
V_2 -> V_19 = V_83 -> V_34 ;
V_2 -> V_42 = F_46 ( V_36 -> V_36 -> V_85 ) ;
V_36 -> V_37 = V_2 ;
V_69 = F_47 ( V_2 -> V_42 -> V_89 ) ;
if ( V_69 ) {
F_37 ( V_36 -> V_36 , L_7 ) ;
goto V_90;
}
F_48 ( V_36 -> V_36 ) ;
V_69 = F_49 ( V_36 , 1 ) ;
if ( V_69 < 0 ) {
F_37 ( V_36 -> V_36 , L_8 ) ;
goto V_91;
}
V_69 = F_34 ( V_36 ) ;
if ( V_69 < 0 ) {
F_37 ( V_36 -> V_36 , L_9 ) ;
goto V_91;
}
F_50 ( V_36 ) ;
F_51 ( V_36 -> V_36 ) ;
V_69 = F_52 ( V_36 , V_2 -> V_42 -> V_33 ) ;
F_53 ( V_36 -> V_36 ) ;
if ( V_69 < 0 ) {
F_37 ( V_36 -> V_36 , L_10 ) ;
goto V_91;
}
F_54 ( V_81 , V_36 ) ;
V_2 -> V_57 = F_55 ( V_36 , 24 ,
V_36 -> V_73 . V_92 ) ;
if ( F_56 ( V_2 -> V_57 ) )
V_2 -> V_57 = NULL ;
F_57 ( V_36 ) ;
return 0 ;
V_91:
F_58 ( V_36 -> V_36 ) ;
F_59 ( V_2 -> V_42 -> V_89 ) ;
V_90:
F_60 ( V_2 -> V_72 ) ;
return V_69 ;
}
static void F_61 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
if ( V_2 -> V_57 )
F_62 ( V_2 -> V_57 ) ;
F_63 ( V_2 -> V_72 ) ;
F_64 ( V_36 ) ;
F_65 ( V_36 ) ;
F_66 ( V_36 ) ;
F_51 ( V_36 -> V_36 ) ;
F_67 ( V_36 ) ;
F_53 ( V_36 -> V_36 ) ;
V_36 -> V_37 = NULL ;
F_58 ( V_36 -> V_36 ) ;
F_59 ( V_2 -> V_42 -> V_89 ) ;
F_60 ( V_2 -> V_72 ) ;
}
static void F_68 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
F_69 ( V_2 -> V_57 ) ;
}
static int F_70 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
unsigned int V_93 = 0 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_49 ; V_41 ++ ) {
if ( V_2 -> V_50 [ V_41 ] )
V_93 |= F_8 ( V_41 ) ;
}
F_71 ( V_2 -> V_42 -> V_43 , V_94 , V_93 ) ;
return 0 ;
}
static void F_72 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_37 ;
unsigned int V_40 ;
F_71 ( V_2 -> V_42 -> V_43 , V_95 , 0xffffffff ) ;
F_6 ( V_2 -> V_42 -> V_43 , V_45 , & V_40 ) ;
}
static int F_73 ( struct V_80 * V_81 )
{
struct V_35 * V_96 ;
int V_69 ;
V_96 = F_74 ( & V_97 , & V_81 -> V_36 ) ;
if ( F_56 ( V_96 ) )
return F_75 ( V_96 ) ;
V_69 = F_40 ( V_96 ) ;
if ( V_69 )
goto V_98;
V_69 = F_76 ( V_96 , 0 ) ;
if ( V_69 )
goto V_99;
return 0 ;
V_99:
F_61 ( V_96 ) ;
V_98:
F_77 ( V_96 ) ;
return V_69 ;
}
static int F_78 ( struct V_80 * V_81 )
{
struct V_35 * V_96 = F_79 ( V_81 ) ;
F_80 ( V_96 ) ;
F_61 ( V_96 ) ;
F_77 ( V_96 ) ;
return 0 ;
}
static int F_81 ( struct V_100 * V_36 )
{
struct V_35 * V_101 = F_46 ( V_36 ) ;
struct V_1 * V_2 = V_101 -> V_37 ;
struct V_43 * V_43 = V_2 -> V_42 -> V_43 ;
struct V_60 * V_62 ;
V_62 = F_82 ( V_101 ) ;
if ( F_56 ( V_62 ) )
return F_75 ( V_62 ) ;
V_2 -> V_102 . V_62 = V_62 ;
F_6 ( V_43 , V_44 , & V_2 -> V_102 . V_39 ) ;
F_71 ( V_43 , V_95 , V_2 -> V_102 . V_39 ) ;
F_59 ( V_2 -> V_42 -> V_89 ) ;
return 0 ;
}
static int F_83 ( struct V_100 * V_36 )
{
struct V_35 * V_101 = F_46 ( V_36 ) ;
struct V_1 * V_2 = V_101 -> V_37 ;
F_47 ( V_2 -> V_42 -> V_89 ) ;
F_71 ( V_2 -> V_42 -> V_43 , V_94 , V_2 -> V_102 . V_39 ) ;
return F_84 ( V_101 , V_2 -> V_102 . V_62 ) ;
}
