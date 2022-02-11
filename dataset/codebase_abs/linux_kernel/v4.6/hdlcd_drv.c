static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_2 -> V_9 ) ;
struct V_10 * V_11 ;
T_1 V_12 ;
int V_13 ;
V_5 -> V_14 = F_3 ( V_2 -> V_9 , L_1 ) ;
if ( F_4 ( V_5 -> V_14 ) )
return F_5 ( V_5 -> V_14 ) ;
#ifdef F_6
F_7 ( & V_5 -> V_15 , 0 ) ;
F_7 ( & V_5 -> V_16 , 0 ) ;
F_7 ( & V_5 -> V_17 , 0 ) ;
F_7 ( & V_5 -> V_18 , 0 ) ;
#endif
F_8 ( & V_5 -> V_19 ) ;
V_11 = F_9 ( V_8 , V_20 , 0 ) ;
V_5 -> V_21 = F_10 ( V_2 -> V_9 , V_11 ) ;
if ( F_4 ( V_5 -> V_21 ) ) {
F_11 ( L_2 ) ;
V_13 = F_5 ( V_5 -> V_21 ) ;
V_5 -> V_21 = NULL ;
return V_13 ;
}
V_12 = F_12 ( V_5 , V_22 ) ;
if ( ( V_12 & V_23 ) != V_24 ) {
F_11 ( L_3 , V_12 ) ;
return - V_25 ;
}
F_13 ( L_4 ,
( V_12 & V_26 ) >> 8 ,
V_12 & V_27 ) ;
V_13 = F_14 ( V_2 -> V_9 ) ;
if ( V_13 && V_13 != - V_28 )
return V_13 ;
V_13 = F_15 ( V_2 -> V_9 , F_16 ( 32 ) ) ;
if ( V_13 )
goto V_29;
V_13 = F_17 ( V_2 ) ;
if ( V_13 < 0 ) {
F_11 ( L_5 ) ;
goto V_29;
}
F_18 ( V_2 -> V_9 ) ;
F_19 ( V_2 -> V_9 ) ;
V_13 = F_20 ( V_2 , F_21 ( V_8 , 0 ) ) ;
F_22 ( V_2 -> V_9 ) ;
if ( V_13 < 0 ) {
F_11 ( L_6 ) ;
goto V_30;
}
return 0 ;
V_30:
F_23 ( & V_5 -> V_31 ) ;
V_29:
F_24 ( V_2 -> V_9 ) ;
return V_13 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_32 )
F_26 ( V_5 -> V_32 ) ;
}
static int F_27 ( struct V_1 * V_9 ,
struct V_33 * V_34 , bool V_35 )
{
return F_28 ( V_9 , V_34 , false ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
V_2 -> V_36 . V_37 = 0 ;
V_2 -> V_36 . V_38 = 0 ;
V_2 -> V_36 . V_39 = V_40 ;
V_2 -> V_36 . V_41 = V_42 ;
V_2 -> V_36 . V_43 = & V_44 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_32 ( V_5 -> V_32 ) ;
}
static T_2 F_33 ( int V_45 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_47 ;
V_47 = F_12 ( V_5 , V_48 ) ;
#ifdef F_6
if ( V_47 & V_49 )
F_34 ( & V_5 -> V_15 ) ;
if ( V_47 & V_50 )
F_34 ( & V_5 -> V_18 ) ;
if ( V_47 & V_51 )
F_34 ( & V_5 -> V_16 ) ;
if ( V_47 & V_52 )
F_34 ( & V_5 -> V_17 ) ;
#endif
if ( V_47 & V_52 ) {
bool V_53 = false ;
unsigned long V_3 ;
struct V_54 * V_55 , * V_56 ;
F_35 ( & V_5 -> V_31 ) ;
F_36 ( & V_2 -> V_57 , V_3 ) ;
F_37 (e, t, &hdlcd->event_list, base.link) {
F_38 ( & V_55 -> V_58 . V_59 ) ;
F_39 ( & V_5 -> V_31 , V_55 ) ;
V_53 = true ;
}
if ( V_53 )
F_40 ( & V_5 -> V_31 ) ;
F_41 ( & V_2 -> V_57 , V_3 ) ;
}
F_42 ( V_5 , V_60 , V_47 ) ;
return V_61 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_42 ( V_5 , V_62 , 0 ) ;
F_42 ( V_5 , V_60 , ~ 0 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
#ifdef F_6
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_63 = F_12 ( V_5 , V_62 ) ;
V_63 |= V_64 ;
F_42 ( V_5 , V_62 , V_63 ) ;
#endif
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_63 = F_12 ( V_5 , V_62 ) ;
#ifdef F_6
V_63 &= ~ V_64 ;
#endif
V_63 &= ~ V_52 ;
F_42 ( V_5 , V_62 , V_63 ) ;
}
static int F_46 ( struct V_1 * V_2 , unsigned int V_31 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_65 = F_12 ( V_5 , V_62 ) ;
F_42 ( V_5 , V_62 , V_65 | V_52 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , unsigned int V_31 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_65 = F_12 ( V_5 , V_62 ) ;
F_42 ( V_5 , V_62 , V_65 & ~ V_52 ) ;
}
static int F_48 ( struct V_66 * V_67 , void * V_46 )
{
struct V_68 * V_69 = (struct V_68 * ) V_67 -> V_70 ;
struct V_1 * V_2 = V_69 -> V_71 -> V_9 ;
struct V_4 * V_5 = V_2 -> V_6 ;
F_49 ( V_67 , L_7 , F_50 ( & V_5 -> V_15 ) ) ;
F_49 ( V_67 , L_8 , F_50 ( & V_5 -> V_18 ) ) ;
F_49 ( V_67 , L_9 , F_50 ( & V_5 -> V_16 ) ) ;
F_49 ( V_67 , L_10 , F_50 ( & V_5 -> V_17 ) ) ;
return 0 ;
}
static int F_51 ( struct V_66 * V_67 , void * V_46 )
{
struct V_68 * V_69 = (struct V_68 * ) V_67 -> V_70 ;
struct V_1 * V_2 = V_69 -> V_71 -> V_9 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_72 = F_52 ( V_5 -> V_14 ) ;
unsigned long V_73 = V_5 -> V_31 . V_74 . V_75 * 1000 ;
F_49 ( V_67 , L_11 , V_72 ) ;
F_49 ( V_67 , L_12 , V_73 ) ;
return 0 ;
}
static int F_53 ( struct V_76 * V_71 )
{
return F_54 ( V_77 ,
F_55 ( V_77 ) , V_71 -> V_78 , V_71 ) ;
}
static void F_56 ( struct V_76 * V_71 )
{
F_57 ( V_77 ,
F_55 ( V_77 ) , V_71 ) ;
}
static int F_58 ( struct V_79 * V_9 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_13 ;
V_5 = F_59 ( V_9 , sizeof( * V_5 ) , V_80 ) ;
if ( ! V_5 )
return - V_81 ;
V_2 = F_60 ( & V_82 , V_9 ) ;
if ( ! V_2 )
return - V_81 ;
V_2 -> V_6 = V_5 ;
F_29 ( V_2 ) ;
V_13 = F_1 ( V_2 , 0 ) ;
if ( V_13 )
goto V_83;
V_13 = F_61 ( V_2 , 0 ) ;
if ( V_13 )
goto V_84;
F_62 ( V_9 , V_2 ) ;
V_13 = F_63 ( V_9 , V_2 ) ;
if ( V_13 ) {
F_11 ( L_13 ) ;
goto V_85;
}
V_13 = F_64 ( V_2 , V_2 -> V_36 . V_86 ) ;
if ( V_13 < 0 ) {
F_11 ( L_14 ) ;
goto V_87;
}
V_2 -> V_88 = true ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
V_5 -> V_32 = F_67 ( V_2 , 32 , V_2 -> V_36 . V_86 ,
V_2 -> V_36 . V_89 ) ;
if ( F_4 ( V_5 -> V_32 ) ) {
V_13 = F_5 ( V_5 -> V_32 ) ;
V_5 -> V_32 = NULL ;
goto V_90;
}
return 0 ;
V_90:
F_68 ( V_2 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 ) ;
V_87:
F_71 ( V_9 , V_2 ) ;
V_85:
F_72 ( V_2 ) ;
V_84:
F_19 ( V_2 -> V_9 ) ;
F_73 ( V_2 ) ;
F_22 ( V_2 -> V_9 ) ;
F_74 ( V_2 -> V_9 ) ;
F_24 ( V_2 -> V_9 ) ;
V_83:
F_75 ( V_2 ) ;
return V_13 ;
}
static void F_76 ( struct V_79 * V_9 )
{
struct V_1 * V_2 = F_77 ( V_9 ) ;
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_5 -> V_32 ) {
F_78 ( V_5 -> V_32 ) ;
V_5 -> V_32 = NULL ;
}
F_68 ( V_2 ) ;
F_71 ( V_9 , V_2 ) ;
F_70 ( V_2 ) ;
F_19 ( V_2 -> V_9 ) ;
F_73 ( V_2 ) ;
F_22 ( V_2 -> V_9 ) ;
F_74 ( V_2 -> V_9 ) ;
F_24 ( V_2 -> V_9 ) ;
F_69 ( V_2 ) ;
F_72 ( V_2 ) ;
F_75 ( V_2 ) ;
V_2 -> V_6 = NULL ;
F_62 ( V_9 , NULL ) ;
}
static int F_79 ( struct V_79 * V_9 , void * V_91 )
{
return V_9 -> V_92 == V_91 ;
}
static int F_80 ( struct V_7 * V_8 )
{
struct V_93 * V_94 , * V_95 ;
struct V_96 * V_97 = NULL ;
if ( ! V_8 -> V_9 . V_92 )
return - V_28 ;
V_95 = F_81 ( V_8 -> V_9 . V_92 , NULL ) ;
if ( ! V_95 )
return - V_28 ;
if ( ! F_82 ( V_95 ) ) {
F_83 ( V_95 ) ;
return - V_28 ;
}
V_94 = F_84 ( V_95 ) ;
F_83 ( V_95 ) ;
if ( ! V_94 || ! F_82 ( V_94 ) ) {
F_83 ( V_94 ) ;
return - V_98 ;
}
F_85 ( & V_8 -> V_9 , & V_97 , F_79 , V_94 ) ;
return F_86 ( & V_8 -> V_9 , & V_99 ,
V_97 ) ;
}
static int F_87 ( struct V_7 * V_8 )
{
F_88 ( & V_8 -> V_9 , & V_99 ) ;
return 0 ;
}
static int T_3 F_89 ( struct V_79 * V_9 )
{
struct V_1 * V_2 = F_77 ( V_9 ) ;
struct V_100 * V_31 ;
if ( F_90 ( V_9 ) )
return 0 ;
F_91 ( V_2 ) ;
F_92 (crtc, &drm->mode_config.crtc_list, head)
F_93 ( V_31 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
static int T_3 F_95 ( struct V_79 * V_9 )
{
struct V_1 * V_2 = F_77 ( V_9 ) ;
struct V_100 * V_31 ;
if ( ! F_90 ( V_9 ) )
return 0 ;
F_91 ( V_2 ) ;
F_92 (crtc, &drm->mode_config.crtc_list, head)
F_96 ( V_31 ) ;
F_94 ( V_2 ) ;
return 0 ;
}
