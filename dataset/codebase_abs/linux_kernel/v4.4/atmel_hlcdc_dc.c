int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_4 -> V_6 - V_4 -> V_7 ;
int V_8 = V_4 -> V_9 - V_4 -> V_10 ;
int V_11 = V_4 -> V_10 - V_4 -> V_6 ;
int V_12 = V_4 -> V_13 - V_4 -> V_14 ;
int V_15 = V_4 -> V_16 - V_4 -> V_17 ;
int V_18 = V_4 -> V_17 - V_4 -> V_13 ;
if ( V_18 > 0x40 || V_18 < 1 )
return V_19 ;
if ( V_11 > 0x40 || V_11 < 1 )
return V_20 ;
if ( V_12 > 0x200 || V_12 < 1 ||
V_15 > 0x200 || V_15 < 1 ||
V_4 -> V_14 < 1 )
return V_21 ;
if ( V_5 > 0x40 || V_5 < 1 ||
V_8 > 0x40 || V_8 < 0 ||
V_4 -> V_7 < 1 )
return V_22 ;
return V_23 ;
}
static T_1 F_2 ( int V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_1 * V_2 = V_27 -> V_28 ;
unsigned long V_29 ;
unsigned int V_30 , V_31 ;
int V_32 ;
F_3 ( V_2 -> V_33 -> V_34 , V_35 , & V_30 ) ;
F_3 ( V_2 -> V_33 -> V_34 , V_36 , & V_31 ) ;
V_29 = V_30 & V_31 ;
if ( ! V_29 )
return V_37 ;
if ( V_29 & V_38 )
F_4 ( V_2 -> V_39 ) ;
for ( V_32 = 0 ; V_32 < V_40 ; V_32 ++ ) {
struct V_41 * V_42 = V_2 -> V_43 [ V_32 ] ;
if ( ! ( F_5 ( V_32 ) & V_29 ) || ! V_42 )
continue;
F_6 ( V_42 ) ;
}
return V_44 ;
}
static struct V_45 * F_7 ( struct V_26 * V_27 ,
struct V_46 * V_47 , struct V_48 * V_49 )
{
return F_8 ( V_27 , V_47 , V_49 ) ;
}
static void F_9 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
if ( V_2 -> V_50 ) {
F_10 ( V_2 -> V_50 ) ;
} else {
V_2 -> V_50 = F_11 ( V_27 , 24 ,
V_27 -> V_51 . V_52 ,
V_27 -> V_51 . V_53 ) ;
if ( F_12 ( V_2 -> V_50 ) )
V_2 -> V_50 = NULL ;
}
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
struct V_54 * V_55 ;
int V_56 ;
int V_32 ;
F_14 ( V_27 ) ;
V_56 = F_15 ( V_27 ) ;
if ( V_56 ) {
F_16 ( V_27 -> V_27 , L_1 , V_56 ) ;
return V_56 ;
}
V_55 = F_17 ( V_27 ) ;
if ( F_12 ( V_55 ) ) {
F_16 ( V_27 -> V_27 , L_2 ) ;
return F_18 ( V_55 ) ;
}
V_2 -> V_55 = V_55 ;
V_2 -> V_43 [ V_55 -> V_57 -> V_42 . V_58 -> V_59 ] =
& V_55 -> V_57 -> V_42 ;
if ( V_55 -> V_60 )
V_2 -> V_43 [ V_55 -> V_60 -> V_42 . V_58 -> V_59 ] =
& V_55 -> V_60 -> V_42 ;
for ( V_32 = 0 ; V_32 < V_55 -> V_61 ; V_32 ++ )
V_2 -> V_43 [ V_55 -> V_62 [ V_32 ] -> V_42 . V_58 -> V_59 ] =
& V_55 -> V_62 [ V_32 ] -> V_42 ;
V_56 = F_19 ( V_27 ) ;
if ( V_56 ) {
F_16 ( V_27 -> V_27 , L_3 ) ;
return V_56 ;
}
V_27 -> V_51 . V_63 = V_2 -> V_58 -> V_63 ;
V_27 -> V_51 . V_64 = V_2 -> V_58 -> V_64 ;
V_27 -> V_51 . V_65 = V_2 -> V_58 -> V_65 ;
V_27 -> V_51 . V_66 = V_2 -> V_58 -> V_66 ;
V_27 -> V_51 . V_67 = & V_68 ;
return 0 ;
}
static int F_20 ( struct V_26 * V_27 )
{
struct V_69 * V_70 = F_21 ( V_27 -> V_27 ) ;
const struct V_71 * V_72 ;
struct V_1 * V_2 ;
int V_56 ;
V_72 = F_22 ( V_73 , V_27 -> V_27 -> V_74 -> V_75 ) ;
if ( ! V_72 ) {
F_16 ( & V_70 -> V_27 , L_4 ) ;
return - V_76 ;
}
if ( ! V_72 -> V_25 ) {
F_16 ( & V_70 -> V_27 , L_5 ) ;
return - V_77 ;
}
V_2 = F_23 ( V_27 -> V_27 , sizeof( * V_2 ) , V_78 ) ;
if ( ! V_2 )
return - V_79 ;
V_2 -> V_80 = F_24 ( L_6 , 0 ) ;
if ( ! V_2 -> V_80 )
return - V_79 ;
V_2 -> V_58 = V_72 -> V_25 ;
V_2 -> V_33 = F_25 ( V_27 -> V_27 -> V_74 ) ;
V_27 -> V_28 = V_2 ;
V_56 = F_26 ( V_2 -> V_33 -> V_81 ) ;
if ( V_56 ) {
F_16 ( V_27 -> V_27 , L_7 ) ;
goto V_82;
}
F_27 ( V_27 -> V_27 ) ;
V_56 = F_28 ( V_27 , 1 ) ;
if ( V_56 < 0 ) {
F_16 ( V_27 -> V_27 , L_8 ) ;
goto V_83;
}
V_56 = F_13 ( V_27 ) ;
if ( V_56 < 0 ) {
F_16 ( V_27 -> V_27 , L_9 ) ;
goto V_83;
}
F_29 ( V_27 ) ;
F_30 ( V_27 -> V_27 ) ;
V_56 = F_31 ( V_27 , V_2 -> V_33 -> V_24 ) ;
F_32 ( V_27 -> V_27 ) ;
if ( V_56 < 0 ) {
F_16 ( V_27 -> V_27 , L_10 ) ;
goto V_83;
}
F_33 ( V_70 , V_27 ) ;
F_34 ( V_27 ) ;
F_35 ( V_27 ) ;
return 0 ;
V_83:
F_36 ( V_27 -> V_27 ) ;
F_37 ( V_2 -> V_33 -> V_81 ) ;
V_82:
F_38 ( V_2 -> V_80 ) ;
return V_56 ;
}
static void F_39 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
if ( V_2 -> V_50 )
F_40 ( V_2 -> V_50 ) ;
F_41 ( V_2 -> V_80 ) ;
F_42 ( V_27 ) ;
F_43 ( V_27 ) ;
F_44 ( V_27 ) ;
F_30 ( V_27 -> V_27 ) ;
F_45 ( V_27 ) ;
F_32 ( V_27 -> V_27 ) ;
V_27 -> V_28 = NULL ;
F_36 ( V_27 -> V_27 ) ;
F_37 ( V_2 -> V_33 -> V_81 ) ;
F_38 ( V_2 -> V_80 ) ;
}
static int F_46 ( struct V_26 * V_27 )
{
struct V_84 * V_85 , * V_86 ;
int V_56 ;
F_47 ( & V_27 -> V_51 . V_87 ) ;
F_48 (connector, &dev->mode_config.connector_list, head) {
V_56 = F_49 ( V_85 ) ;
if ( V_56 ) {
V_86 = V_85 ;
goto V_88;
}
}
F_50 ( & V_27 -> V_51 . V_87 ) ;
return 0 ;
V_88:
F_48 (connector, &dev->mode_config.connector_list, head) {
if ( V_86 == V_85 )
break;
F_51 ( V_85 ) ;
}
F_50 ( & V_27 -> V_51 . V_87 ) ;
return V_56 ;
}
static void F_52 ( struct V_26 * V_27 )
{
F_47 ( & V_27 -> V_51 . V_87 ) ;
F_53 ( V_27 ) ;
F_50 ( & V_27 -> V_51 . V_87 ) ;
}
static void F_54 ( struct V_26 * V_27 ,
struct V_46 * V_89 )
{
struct V_90 * V_39 ;
F_48 (crtc, &dev->mode_config.crtc_list, head)
F_55 ( V_39 , V_89 ) ;
}
static void F_56 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_57 ( V_2 -> V_50 ) ;
}
static int F_58 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
unsigned int V_91 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_40 ; V_32 ++ ) {
if ( V_2 -> V_43 [ V_32 ] )
V_91 |= F_5 ( V_32 ) ;
}
F_59 ( V_2 -> V_33 -> V_34 , V_92 , V_91 ) ;
return 0 ;
}
static void F_60 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
unsigned int V_31 ;
F_59 ( V_2 -> V_33 -> V_34 , V_93 , 0xffffffff ) ;
F_3 ( V_2 -> V_33 -> V_34 , V_36 , & V_31 ) ;
}
static int F_61 ( struct V_26 * V_27 ,
unsigned int V_94 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_59 ( V_2 -> V_33 -> V_34 , V_92 , V_38 ) ;
return 0 ;
}
static void F_62 ( struct V_26 * V_27 ,
unsigned int V_94 )
{
struct V_1 * V_2 = V_27 -> V_28 ;
F_59 ( V_2 -> V_33 -> V_34 , V_93 , V_38 ) ;
}
static int F_63 ( struct V_69 * V_70 )
{
struct V_26 * V_95 ;
int V_56 ;
V_95 = F_64 ( & V_96 , & V_70 -> V_27 ) ;
if ( ! V_95 )
return - V_79 ;
V_56 = F_65 ( V_95 , F_66 ( V_95 -> V_27 ) ) ;
if ( V_56 )
goto V_97;
V_56 = F_20 ( V_95 ) ;
if ( V_56 )
goto V_97;
V_56 = F_67 ( V_95 , 0 ) ;
if ( V_56 )
goto V_98;
V_56 = F_46 ( V_95 ) ;
if ( V_56 )
goto V_99;
return 0 ;
V_99:
F_68 ( V_95 ) ;
V_98:
F_39 ( V_95 ) ;
V_97:
F_69 ( V_95 ) ;
return V_56 ;
}
static int F_70 ( struct V_69 * V_70 )
{
struct V_26 * V_95 = F_71 ( V_70 ) ;
F_52 ( V_95 ) ;
F_68 ( V_95 ) ;
F_39 ( V_95 ) ;
F_69 ( V_95 ) ;
return 0 ;
}
static int F_72 ( struct V_100 * V_27 )
{
struct V_26 * V_101 = F_25 ( V_27 ) ;
struct V_90 * V_39 ;
if ( F_73 ( V_27 ) )
return 0 ;
F_74 ( V_101 ) ;
F_48 (crtc, &drm_dev->mode_config.crtc_list, head)
F_75 ( V_39 ) ;
F_76 ( V_101 ) ;
return 0 ;
}
static int F_77 ( struct V_100 * V_27 )
{
struct V_26 * V_101 = F_25 ( V_27 ) ;
struct V_90 * V_39 ;
if ( F_73 ( V_27 ) )
return 0 ;
F_74 ( V_101 ) ;
F_48 (crtc, &drm_dev->mode_config.crtc_list, head)
F_78 ( V_39 ) ;
F_76 ( V_101 ) ;
return 0 ;
}
