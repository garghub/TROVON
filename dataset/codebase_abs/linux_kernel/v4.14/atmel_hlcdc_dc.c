enum V_1
F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
int V_6 = V_5 -> V_7 - V_5 -> V_8 ;
int V_9 = V_5 -> V_10 - V_5 -> V_11 ;
int V_12 = V_5 -> V_11 - V_5 -> V_7 ;
int V_13 = V_5 -> V_14 - V_5 -> V_15 ;
int V_16 = V_5 -> V_17 - V_5 -> V_18 ;
int V_19 = V_5 -> V_18 - V_5 -> V_14 ;
if ( V_19 > V_3 -> V_20 -> V_21 + 1 || V_19 < 1 )
return V_22 ;
if ( V_12 > V_3 -> V_20 -> V_21 + 1 || V_12 < 1 )
return V_23 ;
if ( V_13 > V_3 -> V_20 -> V_24 + 1 || V_13 < 1 ||
V_16 > V_3 -> V_20 -> V_24 + 1 || V_16 < 1 ||
V_5 -> V_15 < 1 )
return V_25 ;
if ( V_6 > V_3 -> V_20 -> V_26 + 1 || V_6 < 1 ||
V_9 > V_3 -> V_20 -> V_26 || V_9 < 0 ||
V_5 -> V_8 < 1 )
return V_27 ;
return V_28 ;
}
static void F_2 ( struct V_29 * V_30 )
{
if ( ! V_30 )
return;
if ( V_30 -> V_20 -> type == V_31 ||
V_30 -> V_20 -> type == V_32 ||
V_30 -> V_20 -> type == V_33 )
F_3 ( F_4 ( V_30 ) ) ;
}
static T_1 F_5 ( int V_34 , void * V_35 )
{
struct V_36 * V_37 = V_35 ;
struct V_2 * V_3 = V_37 -> V_38 ;
unsigned long V_39 ;
unsigned int V_40 , V_41 ;
int V_42 ;
F_6 ( V_3 -> V_43 -> V_44 , V_45 , & V_40 ) ;
F_6 ( V_3 -> V_43 -> V_44 , V_46 , & V_41 ) ;
V_39 = V_40 & V_41 ;
if ( ! V_39 )
return V_47 ;
if ( V_39 & V_48 )
F_7 ( V_3 -> V_49 ) ;
for ( V_42 = 0 ; V_42 < V_50 ; V_42 ++ ) {
if ( F_8 ( V_42 ) & V_39 )
F_2 ( V_3 -> V_51 [ V_42 ] ) ;
}
return V_52 ;
}
static struct V_53 * F_9 ( struct V_36 * V_37 ,
struct V_54 * V_55 , const struct V_56 * V_57 )
{
return F_10 ( V_37 , V_55 , V_57 ) ;
}
static void F_11 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = V_37 -> V_38 ;
F_12 ( V_3 -> V_58 ) ;
}
static void
F_13 ( struct V_59 * V_60 )
{
struct V_36 * V_37 = V_60 -> V_37 ;
struct V_2 * V_3 = V_37 -> V_38 ;
struct V_61 * V_62 = V_60 -> V_63 ;
F_14 ( V_37 , V_62 ) ;
F_15 ( V_37 , V_62 , 0 ) ;
F_16 ( V_37 , V_62 ) ;
F_17 ( V_37 , V_62 ) ;
F_18 ( V_37 , V_62 ) ;
F_19 ( V_62 ) ;
F_20 ( & V_3 -> V_60 . V_64 . V_65 ) ;
V_3 -> V_60 . V_66 = false ;
F_21 ( & V_3 -> V_60 . V_64 ) ;
F_22 ( & V_3 -> V_60 . V_64 . V_65 ) ;
F_23 ( V_60 ) ;
}
static void F_24 ( struct V_67 * V_68 )
{
struct V_59 * V_60 =
F_25 ( V_68 , struct V_59 , V_68 ) ;
F_13 ( V_60 ) ;
}
static int F_26 ( struct V_36 * V_37 ,
struct V_61 * V_63 ,
bool V_69 )
{
struct V_2 * V_3 = V_37 -> V_38 ;
struct V_59 * V_60 ;
int V_70 ;
V_70 = F_27 ( V_37 , V_63 ) ;
if ( V_70 )
return V_70 ;
V_60 = F_28 ( sizeof( * V_60 ) , V_71 ) ;
if ( ! V_60 ) {
V_70 = - V_72 ;
goto error;
}
F_29 ( & V_60 -> V_68 , F_24 ) ;
V_60 -> V_37 = V_37 ;
V_60 -> V_63 = V_63 ;
F_20 ( & V_3 -> V_60 . V_64 . V_65 ) ;
V_70 = F_30 ( V_3 -> V_60 . V_64 ,
! V_3 -> V_60 . V_66 ) ;
if ( V_70 == 0 )
V_3 -> V_60 . V_66 = true ;
F_22 ( & V_3 -> V_60 . V_64 . V_65 ) ;
if ( V_70 )
goto V_73;
F_31 ( F_32 ( V_63 , false ) < 0 ) ;
F_33 ( V_63 ) ;
if ( V_69 )
F_34 ( V_3 -> V_74 , & V_60 -> V_68 ) ;
else
F_13 ( V_60 ) ;
return 0 ;
V_73:
F_23 ( V_60 ) ;
error:
F_18 ( V_37 , V_63 ) ;
return V_70 ;
}
static int F_35 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = V_37 -> V_38 ;
int V_70 ;
F_36 ( V_37 ) ;
V_70 = F_37 ( V_37 ) ;
if ( V_70 ) {
F_38 ( V_37 -> V_37 , L_1 , V_70 ) ;
return V_70 ;
}
V_70 = F_39 ( V_37 ) ;
if ( V_70 ) {
F_38 ( V_37 -> V_37 , L_2 , V_70 ) ;
return V_70 ;
}
V_70 = F_40 ( V_37 ) ;
if ( V_70 ) {
F_38 ( V_37 -> V_37 , L_3 ) ;
return V_70 ;
}
V_37 -> V_75 . V_76 = V_3 -> V_20 -> V_76 ;
V_37 -> V_75 . V_77 = V_3 -> V_20 -> V_77 ;
V_37 -> V_75 . V_78 = V_3 -> V_20 -> V_78 ;
V_37 -> V_75 . V_79 = V_3 -> V_20 -> V_79 ;
V_37 -> V_75 . V_80 = & V_81 ;
return 0 ;
}
static int F_41 ( struct V_36 * V_37 )
{
struct V_82 * V_83 = F_42 ( V_37 -> V_37 ) ;
const struct V_84 * V_85 ;
struct V_2 * V_3 ;
int V_70 ;
V_85 = F_43 ( V_86 , V_37 -> V_37 -> V_87 -> V_88 ) ;
if ( ! V_85 ) {
F_38 ( & V_83 -> V_37 , L_4 ) ;
return - V_89 ;
}
if ( ! V_85 -> V_35 ) {
F_38 ( & V_83 -> V_37 , L_5 ) ;
return - V_90 ;
}
V_3 = F_44 ( V_37 -> V_37 , sizeof( * V_3 ) , V_71 ) ;
if ( ! V_3 )
return - V_72 ;
V_3 -> V_74 = F_45 ( L_6 , 0 ) ;
if ( ! V_3 -> V_74 )
return - V_72 ;
F_46 ( & V_3 -> V_60 . V_64 ) ;
V_3 -> V_20 = V_85 -> V_35 ;
V_3 -> V_43 = F_47 ( V_37 -> V_37 -> V_87 ) ;
V_37 -> V_38 = V_3 ;
V_70 = F_48 ( V_3 -> V_43 -> V_91 ) ;
if ( V_70 ) {
F_38 ( V_37 -> V_37 , L_7 ) ;
goto V_92;
}
F_49 ( V_37 -> V_37 ) ;
V_70 = F_50 ( V_37 , 1 ) ;
if ( V_70 < 0 ) {
F_38 ( V_37 -> V_37 , L_8 ) ;
goto V_93;
}
V_70 = F_35 ( V_37 ) ;
if ( V_70 < 0 ) {
F_38 ( V_37 -> V_37 , L_9 ) ;
goto V_93;
}
F_51 ( V_37 ) ;
F_52 ( V_37 -> V_37 ) ;
V_70 = F_53 ( V_37 , V_3 -> V_43 -> V_34 ) ;
F_54 ( V_37 -> V_37 ) ;
if ( V_70 < 0 ) {
F_38 ( V_37 -> V_37 , L_10 ) ;
goto V_93;
}
F_55 ( V_83 , V_37 ) ;
V_3 -> V_58 = F_56 ( V_37 , 24 ,
V_37 -> V_75 . V_94 ) ;
if ( F_57 ( V_3 -> V_58 ) )
V_3 -> V_58 = NULL ;
F_58 ( V_37 ) ;
return 0 ;
V_93:
F_59 ( V_37 -> V_37 ) ;
F_60 ( V_3 -> V_43 -> V_91 ) ;
V_92:
F_61 ( V_3 -> V_74 ) ;
return V_70 ;
}
static void F_62 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = V_37 -> V_38 ;
if ( V_3 -> V_58 )
F_63 ( V_3 -> V_58 ) ;
F_64 ( V_3 -> V_74 ) ;
F_65 ( V_37 ) ;
F_66 ( V_37 ) ;
F_52 ( V_37 -> V_37 ) ;
F_67 ( V_37 ) ;
F_54 ( V_37 -> V_37 ) ;
V_37 -> V_38 = NULL ;
F_59 ( V_37 -> V_37 ) ;
F_60 ( V_3 -> V_43 -> V_91 ) ;
F_61 ( V_3 -> V_74 ) ;
}
static void F_68 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = V_37 -> V_38 ;
F_69 ( V_3 -> V_58 ) ;
}
static int F_70 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = V_37 -> V_38 ;
unsigned int V_95 = 0 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_50 ; V_42 ++ ) {
if ( V_3 -> V_51 [ V_42 ] )
V_95 |= F_8 ( V_42 ) ;
}
F_71 ( V_3 -> V_43 -> V_44 , V_96 , V_95 ) ;
return 0 ;
}
static void F_72 ( struct V_36 * V_37 )
{
struct V_2 * V_3 = V_37 -> V_38 ;
unsigned int V_41 ;
F_71 ( V_3 -> V_43 -> V_44 , V_97 , 0xffffffff ) ;
F_6 ( V_3 -> V_43 -> V_44 , V_46 , & V_41 ) ;
}
static int F_73 ( struct V_82 * V_83 )
{
struct V_36 * V_98 ;
int V_70 ;
V_98 = F_74 ( & V_99 , & V_83 -> V_37 ) ;
if ( F_57 ( V_98 ) )
return F_75 ( V_98 ) ;
V_70 = F_41 ( V_98 ) ;
if ( V_70 )
goto V_100;
V_70 = F_76 ( V_98 , 0 ) ;
if ( V_70 )
goto V_101;
return 0 ;
V_101:
F_62 ( V_98 ) ;
V_100:
F_77 ( V_98 ) ;
return V_70 ;
}
static int F_78 ( struct V_82 * V_83 )
{
struct V_36 * V_98 = F_79 ( V_83 ) ;
F_80 ( V_98 ) ;
F_62 ( V_98 ) ;
F_77 ( V_98 ) ;
return 0 ;
}
static int F_81 ( struct V_102 * V_37 )
{
struct V_36 * V_103 = F_47 ( V_37 ) ;
struct V_2 * V_3 = V_103 -> V_38 ;
struct V_44 * V_44 = V_3 -> V_43 -> V_44 ;
struct V_61 * V_63 ;
V_63 = F_82 ( V_103 ) ;
if ( F_57 ( V_63 ) )
return F_75 ( V_63 ) ;
V_3 -> V_104 . V_63 = V_63 ;
F_6 ( V_44 , V_45 , & V_3 -> V_104 . V_40 ) ;
F_71 ( V_44 , V_97 , V_3 -> V_104 . V_40 ) ;
F_60 ( V_3 -> V_43 -> V_91 ) ;
return 0 ;
}
static int F_83 ( struct V_102 * V_37 )
{
struct V_36 * V_103 = F_47 ( V_37 ) ;
struct V_2 * V_3 = V_103 -> V_38 ;
F_48 ( V_3 -> V_43 -> V_91 ) ;
F_71 ( V_3 -> V_43 -> V_44 , V_96 , V_3 -> V_104 . V_40 ) ;
return F_84 ( V_103 , V_3 -> V_104 . V_63 ) ;
}
