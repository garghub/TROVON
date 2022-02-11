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
static T_1 F_2 ( int V_28 , void * V_29 )
{
struct V_30 * V_31 = V_29 ;
struct V_1 * V_2 = V_31 -> V_32 ;
unsigned long V_33 ;
unsigned int V_34 , V_35 ;
int V_36 ;
F_3 ( V_2 -> V_37 -> V_38 , V_39 , & V_34 ) ;
F_3 ( V_2 -> V_37 -> V_38 , V_40 , & V_35 ) ;
V_33 = V_34 & V_35 ;
if ( ! V_33 )
return V_41 ;
if ( V_33 & V_42 )
F_4 ( V_2 -> V_43 ) ;
for ( V_36 = 0 ; V_36 < V_44 ; V_36 ++ ) {
struct V_45 * V_46 = V_2 -> V_47 [ V_36 ] ;
if ( ! ( F_5 ( V_36 ) & V_33 ) || ! V_46 )
continue;
F_6 ( V_46 ) ;
}
return V_48 ;
}
static struct V_49 * F_7 ( struct V_30 * V_31 ,
struct V_50 * V_51 , const struct V_52 * V_53 )
{
return F_8 ( V_31 , V_51 , V_53 ) ;
}
static void F_9 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
if ( V_2 -> V_54 )
F_10 ( V_2 -> V_54 ) ;
}
static void
F_11 ( struct V_55 * V_56 )
{
struct V_30 * V_31 = V_56 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_57 * V_58 = V_56 -> V_59 ;
F_12 ( V_31 , V_58 ) ;
F_13 ( V_31 , V_58 , 0 ) ;
F_14 ( V_31 , V_58 ) ;
F_15 ( V_31 , V_58 ) ;
F_16 ( V_31 , V_58 ) ;
F_17 ( V_58 ) ;
F_18 ( & V_2 -> V_56 . V_60 . V_61 ) ;
V_2 -> V_56 . V_62 = false ;
F_19 ( & V_2 -> V_56 . V_60 ) ;
F_20 ( & V_2 -> V_56 . V_60 . V_61 ) ;
F_21 ( V_56 ) ;
}
static void F_22 ( struct V_63 * V_64 )
{
struct V_55 * V_56 =
F_23 ( V_64 , struct V_55 , V_64 ) ;
F_11 ( V_56 ) ;
}
static int F_24 ( struct V_30 * V_31 ,
struct V_57 * V_59 ,
bool V_65 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_55 * V_56 ;
int V_66 ;
V_66 = F_25 ( V_31 , V_59 ) ;
if ( V_66 )
return V_66 ;
V_56 = F_26 ( sizeof( * V_56 ) , V_67 ) ;
if ( ! V_56 ) {
V_66 = - V_68 ;
goto error;
}
F_27 ( & V_56 -> V_64 , F_22 ) ;
V_56 -> V_31 = V_31 ;
V_56 -> V_59 = V_59 ;
F_18 ( & V_2 -> V_56 . V_60 . V_61 ) ;
V_66 = F_28 ( V_2 -> V_56 . V_60 ,
! V_2 -> V_56 . V_62 ) ;
if ( V_66 == 0 )
V_2 -> V_56 . V_62 = true ;
F_20 ( & V_2 -> V_56 . V_60 . V_61 ) ;
if ( V_66 ) {
F_21 ( V_56 ) ;
goto error;
}
F_29 ( V_59 , true ) ;
F_30 ( V_59 ) ;
if ( V_65 )
F_31 ( V_2 -> V_69 , & V_56 -> V_64 ) ;
else
F_11 ( V_56 ) ;
return 0 ;
error:
F_16 ( V_31 , V_59 ) ;
return V_66 ;
}
static int F_32 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_70 * V_71 ;
int V_66 ;
int V_36 ;
F_33 ( V_31 ) ;
V_66 = F_34 ( V_31 ) ;
if ( V_66 ) {
F_35 ( V_31 -> V_31 , L_1 , V_66 ) ;
return V_66 ;
}
V_71 = F_36 ( V_31 ) ;
if ( F_37 ( V_71 ) ) {
F_35 ( V_31 -> V_31 , L_2 ) ;
return F_38 ( V_71 ) ;
}
V_2 -> V_71 = V_71 ;
V_2 -> V_47 [ V_71 -> V_72 -> V_46 . V_19 -> V_73 ] =
& V_71 -> V_72 -> V_46 ;
if ( V_71 -> V_74 )
V_2 -> V_47 [ V_71 -> V_74 -> V_46 . V_19 -> V_73 ] =
& V_71 -> V_74 -> V_46 ;
for ( V_36 = 0 ; V_36 < V_71 -> V_75 ; V_36 ++ )
V_2 -> V_47 [ V_71 -> V_76 [ V_36 ] -> V_46 . V_19 -> V_73 ] =
& V_71 -> V_76 [ V_36 ] -> V_46 ;
V_66 = F_39 ( V_31 ) ;
if ( V_66 ) {
F_35 ( V_31 -> V_31 , L_3 ) ;
return V_66 ;
}
V_31 -> V_77 . V_78 = V_2 -> V_19 -> V_78 ;
V_31 -> V_77 . V_79 = V_2 -> V_19 -> V_79 ;
V_31 -> V_77 . V_80 = V_2 -> V_19 -> V_80 ;
V_31 -> V_77 . V_81 = V_2 -> V_19 -> V_81 ;
V_31 -> V_77 . V_82 = & V_83 ;
return 0 ;
}
static int F_40 ( struct V_30 * V_31 )
{
struct V_84 * V_85 = F_41 ( V_31 -> V_31 ) ;
const struct V_86 * V_87 ;
struct V_1 * V_2 ;
int V_66 ;
V_87 = F_42 ( V_88 , V_31 -> V_31 -> V_89 -> V_90 ) ;
if ( ! V_87 ) {
F_35 ( & V_85 -> V_31 , L_4 ) ;
return - V_91 ;
}
if ( ! V_87 -> V_29 ) {
F_35 ( & V_85 -> V_31 , L_5 ) ;
return - V_92 ;
}
V_2 = F_43 ( V_31 -> V_31 , sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
V_2 -> V_69 = F_44 ( L_6 , 0 ) ;
if ( ! V_2 -> V_69 )
return - V_68 ;
F_45 ( & V_2 -> V_56 . V_60 ) ;
V_2 -> V_19 = V_87 -> V_29 ;
V_2 -> V_37 = F_46 ( V_31 -> V_31 -> V_89 ) ;
V_31 -> V_32 = V_2 ;
V_66 = F_47 ( V_2 -> V_37 -> V_93 ) ;
if ( V_66 ) {
F_35 ( V_31 -> V_31 , L_7 ) ;
goto V_94;
}
F_48 ( V_31 -> V_31 ) ;
V_66 = F_49 ( V_31 , 1 ) ;
if ( V_66 < 0 ) {
F_35 ( V_31 -> V_31 , L_8 ) ;
goto V_95;
}
V_66 = F_32 ( V_31 ) ;
if ( V_66 < 0 ) {
F_35 ( V_31 -> V_31 , L_9 ) ;
goto V_95;
}
F_50 ( V_31 ) ;
F_51 ( V_31 -> V_31 ) ;
V_66 = F_52 ( V_31 , V_2 -> V_37 -> V_28 ) ;
F_53 ( V_31 -> V_31 ) ;
if ( V_66 < 0 ) {
F_35 ( V_31 -> V_31 , L_10 ) ;
goto V_95;
}
F_54 ( V_85 , V_31 ) ;
V_2 -> V_54 = F_55 ( V_31 , 24 ,
V_31 -> V_77 . V_96 ) ;
if ( F_37 ( V_2 -> V_54 ) )
V_2 -> V_54 = NULL ;
F_56 ( V_31 ) ;
return 0 ;
V_95:
F_57 ( V_31 -> V_31 ) ;
F_58 ( V_2 -> V_37 -> V_93 ) ;
V_94:
F_59 ( V_2 -> V_69 ) ;
return V_66 ;
}
static void F_60 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
if ( V_2 -> V_54 )
F_61 ( V_2 -> V_54 ) ;
F_62 ( V_2 -> V_69 ) ;
F_63 ( V_31 ) ;
F_64 ( V_31 ) ;
F_65 ( V_31 ) ;
F_51 ( V_31 -> V_31 ) ;
F_66 ( V_31 ) ;
F_53 ( V_31 -> V_31 ) ;
V_31 -> V_32 = NULL ;
F_57 ( V_31 -> V_31 ) ;
F_58 ( V_2 -> V_37 -> V_93 ) ;
F_59 ( V_2 -> V_69 ) ;
}
static void F_67 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
F_68 ( V_2 -> V_54 ) ;
}
static int F_69 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
unsigned int V_97 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_44 ; V_36 ++ ) {
if ( V_2 -> V_47 [ V_36 ] )
V_97 |= F_5 ( V_36 ) ;
}
F_70 ( V_2 -> V_37 -> V_38 , V_98 , V_97 ) ;
return 0 ;
}
static void F_71 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
unsigned int V_35 ;
F_70 ( V_2 -> V_37 -> V_38 , V_99 , 0xffffffff ) ;
F_3 ( V_2 -> V_37 -> V_38 , V_40 , & V_35 ) ;
}
static int F_72 ( struct V_30 * V_31 ,
unsigned int V_100 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
F_70 ( V_2 -> V_37 -> V_38 , V_98 , V_42 ) ;
return 0 ;
}
static void F_73 ( struct V_30 * V_31 ,
unsigned int V_100 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
F_70 ( V_2 -> V_37 -> V_38 , V_99 , V_42 ) ;
}
static int F_74 ( struct V_84 * V_85 )
{
struct V_30 * V_101 ;
int V_66 ;
V_101 = F_75 ( & V_102 , & V_85 -> V_31 ) ;
if ( F_37 ( V_101 ) )
return F_38 ( V_101 ) ;
V_66 = F_40 ( V_101 ) ;
if ( V_66 )
goto V_103;
V_66 = F_76 ( V_101 , 0 ) ;
if ( V_66 )
goto V_104;
return 0 ;
V_104:
F_60 ( V_101 ) ;
V_103:
F_77 ( V_101 ) ;
return V_66 ;
}
static int F_78 ( struct V_84 * V_85 )
{
struct V_30 * V_101 = F_79 ( V_85 ) ;
F_80 ( V_101 ) ;
F_60 ( V_101 ) ;
F_77 ( V_101 ) ;
return 0 ;
}
static int F_81 ( struct V_105 * V_31 )
{
struct V_30 * V_106 = F_46 ( V_31 ) ;
struct V_107 * V_43 ;
if ( F_82 ( V_31 ) )
return 0 ;
F_83 ( V_106 ) ;
F_84 (crtc, &drm_dev->mode_config.crtc_list, head)
F_85 ( V_43 ) ;
F_86 ( V_106 ) ;
return 0 ;
}
static int F_87 ( struct V_105 * V_31 )
{
struct V_30 * V_106 = F_46 ( V_31 ) ;
struct V_107 * V_43 ;
if ( F_82 ( V_31 ) )
return 0 ;
F_83 ( V_106 ) ;
F_84 (crtc, &drm_dev->mode_config.crtc_list, head)
F_88 ( V_43 ) ;
F_86 ( V_106 ) ;
return 0 ;
}
