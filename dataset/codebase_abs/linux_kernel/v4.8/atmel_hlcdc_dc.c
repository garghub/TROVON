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
if ( V_2 -> V_54 ) {
F_10 ( V_2 -> V_54 ) ;
} else {
V_2 -> V_54 = F_11 ( V_31 , 24 ,
V_31 -> V_55 . V_56 ,
V_31 -> V_55 . V_57 ) ;
if ( F_12 ( V_2 -> V_54 ) )
V_2 -> V_54 = NULL ;
}
}
static void
F_13 ( struct V_58 * V_59 )
{
struct V_30 * V_31 = V_59 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_60 * V_61 = V_59 -> V_62 ;
F_14 ( V_31 , V_61 ) ;
F_15 ( V_31 , V_61 , false ) ;
F_16 ( V_31 , V_61 ) ;
F_17 ( V_31 , V_61 ) ;
F_18 ( V_31 , V_61 ) ;
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
static int F_26 ( struct V_30 * V_31 ,
struct V_60 * V_62 ,
bool V_68 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_58 * V_59 ;
int V_69 ;
V_69 = F_27 ( V_31 , V_62 ) ;
if ( V_69 )
return V_69 ;
V_59 = F_28 ( sizeof( * V_59 ) , V_70 ) ;
if ( ! V_59 ) {
V_69 = - V_71 ;
goto error;
}
F_29 ( & V_59 -> V_67 , F_24 ) ;
V_59 -> V_31 = V_31 ;
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
if ( V_68 )
F_32 ( V_2 -> V_72 , & V_59 -> V_67 ) ;
else
F_13 ( V_59 ) ;
return 0 ;
error:
F_18 ( V_31 , V_62 ) ;
return V_69 ;
}
static int F_33 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
struct V_73 * V_74 ;
int V_69 ;
int V_36 ;
F_34 ( V_31 ) ;
V_69 = F_35 ( V_31 ) ;
if ( V_69 ) {
F_36 ( V_31 -> V_31 , L_1 , V_69 ) ;
return V_69 ;
}
V_74 = F_37 ( V_31 ) ;
if ( F_12 ( V_74 ) ) {
F_36 ( V_31 -> V_31 , L_2 ) ;
return F_38 ( V_74 ) ;
}
V_2 -> V_74 = V_74 ;
V_2 -> V_47 [ V_74 -> V_75 -> V_46 . V_19 -> V_76 ] =
& V_74 -> V_75 -> V_46 ;
if ( V_74 -> V_77 )
V_2 -> V_47 [ V_74 -> V_77 -> V_46 . V_19 -> V_76 ] =
& V_74 -> V_77 -> V_46 ;
for ( V_36 = 0 ; V_36 < V_74 -> V_78 ; V_36 ++ )
V_2 -> V_47 [ V_74 -> V_79 [ V_36 ] -> V_46 . V_19 -> V_76 ] =
& V_74 -> V_79 [ V_36 ] -> V_46 ;
V_69 = F_39 ( V_31 ) ;
if ( V_69 ) {
F_36 ( V_31 -> V_31 , L_3 ) ;
return V_69 ;
}
V_31 -> V_55 . V_80 = V_2 -> V_19 -> V_80 ;
V_31 -> V_55 . V_81 = V_2 -> V_19 -> V_81 ;
V_31 -> V_55 . V_82 = V_2 -> V_19 -> V_82 ;
V_31 -> V_55 . V_83 = V_2 -> V_19 -> V_83 ;
V_31 -> V_55 . V_84 = & V_85 ;
return 0 ;
}
static int F_40 ( struct V_30 * V_31 )
{
struct V_86 * V_87 = F_41 ( V_31 -> V_31 ) ;
const struct V_88 * V_89 ;
struct V_1 * V_2 ;
int V_69 ;
V_89 = F_42 ( V_90 , V_31 -> V_31 -> V_91 -> V_92 ) ;
if ( ! V_89 ) {
F_36 ( & V_87 -> V_31 , L_4 ) ;
return - V_93 ;
}
if ( ! V_89 -> V_29 ) {
F_36 ( & V_87 -> V_31 , L_5 ) ;
return - V_94 ;
}
V_2 = F_43 ( V_31 -> V_31 , sizeof( * V_2 ) , V_70 ) ;
if ( ! V_2 )
return - V_71 ;
V_2 -> V_72 = F_44 ( L_6 , 0 ) ;
if ( ! V_2 -> V_72 )
return - V_71 ;
F_45 ( & V_2 -> V_59 . V_63 ) ;
V_2 -> V_19 = V_89 -> V_29 ;
V_2 -> V_37 = F_46 ( V_31 -> V_31 -> V_91 ) ;
V_31 -> V_32 = V_2 ;
V_69 = F_47 ( V_2 -> V_37 -> V_95 ) ;
if ( V_69 ) {
F_36 ( V_31 -> V_31 , L_7 ) ;
goto V_96;
}
F_48 ( V_31 -> V_31 ) ;
V_69 = F_49 ( V_31 , 1 ) ;
if ( V_69 < 0 ) {
F_36 ( V_31 -> V_31 , L_8 ) ;
goto V_97;
}
V_69 = F_33 ( V_31 ) ;
if ( V_69 < 0 ) {
F_36 ( V_31 -> V_31 , L_9 ) ;
goto V_97;
}
F_50 ( V_31 ) ;
F_51 ( V_31 -> V_31 ) ;
V_69 = F_52 ( V_31 , V_2 -> V_37 -> V_28 ) ;
F_53 ( V_31 -> V_31 ) ;
if ( V_69 < 0 ) {
F_36 ( V_31 -> V_31 , L_10 ) ;
goto V_97;
}
F_54 ( V_87 , V_31 ) ;
F_55 ( V_31 ) ;
F_56 ( V_31 ) ;
return 0 ;
V_97:
F_57 ( V_31 -> V_31 ) ;
F_58 ( V_2 -> V_37 -> V_95 ) ;
V_96:
F_59 ( V_2 -> V_72 ) ;
return V_69 ;
}
static void F_60 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
if ( V_2 -> V_54 )
F_61 ( V_2 -> V_54 ) ;
F_62 ( V_2 -> V_72 ) ;
F_63 ( V_31 ) ;
F_64 ( V_31 ) ;
F_65 ( V_31 ) ;
F_51 ( V_31 -> V_31 ) ;
F_66 ( V_31 ) ;
F_53 ( V_31 -> V_31 ) ;
V_31 -> V_32 = NULL ;
F_57 ( V_31 -> V_31 ) ;
F_58 ( V_2 -> V_37 -> V_95 ) ;
F_59 ( V_2 -> V_72 ) ;
}
static void F_67 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
F_68 ( V_2 -> V_54 ) ;
}
static int F_69 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
unsigned int V_98 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_44 ; V_36 ++ ) {
if ( V_2 -> V_47 [ V_36 ] )
V_98 |= F_5 ( V_36 ) ;
}
F_70 ( V_2 -> V_37 -> V_38 , V_99 , V_98 ) ;
return 0 ;
}
static void F_71 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
unsigned int V_35 ;
F_70 ( V_2 -> V_37 -> V_38 , V_100 , 0xffffffff ) ;
F_3 ( V_2 -> V_37 -> V_38 , V_40 , & V_35 ) ;
}
static int F_72 ( struct V_30 * V_31 ,
unsigned int V_101 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
F_70 ( V_2 -> V_37 -> V_38 , V_99 , V_42 ) ;
return 0 ;
}
static void F_73 ( struct V_30 * V_31 ,
unsigned int V_101 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
F_70 ( V_2 -> V_37 -> V_38 , V_100 , V_42 ) ;
}
static int F_74 ( struct V_86 * V_87 )
{
struct V_30 * V_102 ;
int V_69 ;
V_102 = F_75 ( & V_103 , & V_87 -> V_31 ) ;
if ( ! V_102 )
return - V_71 ;
V_69 = F_40 ( V_102 ) ;
if ( V_69 )
goto V_104;
V_69 = F_76 ( V_102 , 0 ) ;
if ( V_69 )
goto V_105;
return 0 ;
V_105:
F_60 ( V_102 ) ;
V_104:
F_77 ( V_102 ) ;
return V_69 ;
}
static int F_78 ( struct V_86 * V_87 )
{
struct V_30 * V_102 = F_79 ( V_87 ) ;
F_80 ( V_102 ) ;
F_60 ( V_102 ) ;
F_77 ( V_102 ) ;
return 0 ;
}
static int F_81 ( struct V_106 * V_31 )
{
struct V_30 * V_107 = F_46 ( V_31 ) ;
struct V_108 * V_43 ;
if ( F_82 ( V_31 ) )
return 0 ;
F_83 ( V_107 ) ;
F_84 (crtc, &drm_dev->mode_config.crtc_list, head)
F_85 ( V_43 ) ;
F_86 ( V_107 ) ;
return 0 ;
}
static int F_87 ( struct V_106 * V_31 )
{
struct V_30 * V_107 = F_46 ( V_31 ) ;
struct V_108 * V_43 ;
if ( F_82 ( V_31 ) )
return 0 ;
F_83 ( V_107 ) ;
F_84 (crtc, &drm_dev->mode_config.crtc_list, head)
F_88 ( V_43 ) ;
F_86 ( V_107 ) ;
return 0 ;
}
