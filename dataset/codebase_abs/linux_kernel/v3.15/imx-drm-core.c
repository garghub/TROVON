int F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static void F_2 ( struct V_4 * V_5 )
{
#if F_3 ( V_6 )
struct V_7 * V_8 = V_5 -> V_9 ;
if ( V_8 -> V_10 )
F_4 ( V_8 -> V_10 ) ;
#endif
}
static int F_5 ( struct V_4 * V_5 )
{
#if F_3 ( V_6 )
struct V_7 * V_8 = V_5 -> V_9 ;
#endif
F_6 ( V_5 ) ;
#if F_3 ( V_6 )
if ( V_8 -> V_10 )
F_7 ( V_8 -> V_10 ) ;
#endif
F_8 ( V_5 -> V_11 , V_5 ) ;
F_9 ( V_5 ) ;
F_10 ( V_5 ) ;
return 0 ;
}
static struct V_1 * F_11 ( struct V_12 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_11 -> V_9 ;
unsigned V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
if ( V_8 -> V_2 [ V_13 ] && V_8 -> V_2 [ V_13 ] -> V_2 == V_2 )
return V_8 -> V_2 [ V_13 ] ;
return NULL ;
}
int F_12 ( struct V_15 * V_16 ,
T_1 V_17 , int V_18 , int V_19 )
{
struct V_20 * V_21 ;
struct V_1 * V_22 ;
V_22 = F_11 ( V_16 -> V_2 ) ;
if ( ! V_22 )
return - V_23 ;
V_21 = & V_22 -> V_24 ;
if ( V_21 -> V_25 )
return V_21 -> V_25 ( V_16 -> V_2 ,
V_16 -> V_26 , V_17 ,
V_18 , V_19 ) ;
return 0 ;
}
int F_13 ( struct V_15 * V_16 , T_1 V_17 )
{
return F_12 ( V_16 , V_17 , 2 , 3 ) ;
}
int F_14 ( struct V_1 * V_1 )
{
return F_15 ( V_1 -> V_2 -> V_11 , V_1 -> V_3 ) ;
}
void F_16 ( struct V_1 * V_1 )
{
F_17 ( V_1 -> V_2 -> V_11 , V_1 -> V_3 ) ;
}
void F_18 ( struct V_1 * V_1 )
{
F_19 ( V_1 -> V_2 -> V_11 , V_1 -> V_3 ) ;
}
static int F_20 ( struct V_4 * V_5 , int V_2 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 = V_8 -> V_2 [ V_2 ] ;
int V_27 ;
if ( ! V_1 )
return - V_23 ;
if ( ! V_1 -> V_24 . V_28 )
return - V_29 ;
V_27 = V_1 -> V_24 . V_28 (
V_1 -> V_2 ) ;
return V_27 ;
}
static void F_21 ( struct V_4 * V_5 , int V_2 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 = V_8 -> V_2 [ V_2 ] ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_24 . V_30 )
return;
V_1 -> V_24 . V_30 ( V_1 -> V_2 ) ;
}
static void F_22 ( struct V_4 * V_5 ,
struct V_31 * V_32 )
{
int V_13 ;
if ( ! V_32 -> V_33 )
return;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ )
F_21 ( V_5 , V_13 ) ;
}
int F_23 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
return V_38 ;
}
void F_24 ( struct V_34 * V_35 )
{
F_25 ( V_35 ) ;
F_26 ( V_35 ) ;
}
void F_27 ( struct V_15 * V_16 )
{
F_28 ( V_16 ) ;
}
static void F_29 ( struct V_4 * V_5 )
{
#if F_3 ( V_6 )
struct V_7 * V_8 = V_5 -> V_9 ;
F_30 ( V_8 -> V_10 ) ;
#endif
}
static int F_31 ( struct V_4 * V_5 , unsigned long V_39 )
{
struct V_7 * V_8 ;
struct V_34 * V_35 ;
int V_27 ;
V_8 = F_32 ( V_5 -> V_11 , sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 )
return - V_41 ;
V_8 -> V_5 = V_5 ;
V_5 -> V_9 = V_8 ;
V_5 -> V_42 = true ;
V_5 -> V_43 . V_44 = 64 ;
V_5 -> V_43 . V_45 = 64 ;
V_5 -> V_43 . V_46 = 4096 ;
V_5 -> V_43 . V_47 = 4096 ;
V_5 -> V_43 . V_48 = & V_49 ;
F_33 ( V_5 ) ;
V_27 = F_34 ( V_5 , V_14 ) ;
if ( V_27 )
goto V_50;
V_5 -> V_51 = true ;
F_35 ( V_5 -> V_52 , V_5 ) ;
V_27 = F_36 ( V_5 -> V_11 , V_5 ) ;
if ( V_27 )
goto V_53;
F_37 (connector, &drm->mode_config.connector_list, head) {
V_27 = F_38 ( V_35 ) ;
if ( V_27 ) {
F_39 ( V_5 -> V_11 ,
L_1 ,
V_35 -> V_54 . V_55 ,
F_40 ( V_35 ) , V_27 ) ;
goto V_56;
}
}
#if F_3 ( V_6 )
if ( V_57 != 16 && V_57 != 32 ) {
F_41 ( V_5 -> V_11 , L_2 ) ;
V_57 = 16 ;
}
V_8 -> V_10 = F_42 ( V_5 , V_57 ,
V_5 -> V_43 . V_58 , V_14 ) ;
if ( F_43 ( V_8 -> V_10 ) ) {
V_27 = F_44 ( V_8 -> V_10 ) ;
V_8 -> V_10 = NULL ;
goto V_56;
}
#endif
F_45 ( V_5 ) ;
return 0 ;
V_56:
F_8 ( V_5 -> V_11 , V_5 ) ;
V_53:
F_9 ( V_5 ) ;
V_50:
F_10 ( V_5 ) ;
return V_27 ;
}
int F_46 ( struct V_4 * V_5 , struct V_12 * V_2 ,
struct V_1 * * V_59 ,
const struct V_20 * V_24 ,
struct V_60 * V_61 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_1 * V_1 ;
int V_27 ;
if ( V_8 -> V_62 >= V_14 )
return - V_23 ;
if ( V_8 -> V_5 -> V_63 )
return - V_64 ;
V_1 = F_47 ( sizeof( * V_1 ) , V_40 ) ;
if ( ! V_1 )
return - V_41 ;
V_1 -> V_24 = * V_24 ;
V_1 -> V_3 = V_8 -> V_62 ++ ;
V_1 -> V_61 = V_61 ;
V_1 -> V_2 = V_2 ;
V_8 -> V_2 [ V_1 -> V_3 ] = V_1 ;
* V_59 = V_1 ;
V_27 = F_48 ( V_1 -> V_2 , 256 ) ;
if ( V_27 )
goto V_65;
F_49 ( V_2 ,
V_1 -> V_24 . V_66 ) ;
F_50 ( V_5 , V_2 ,
V_1 -> V_24 . V_67 ) ;
return 0 ;
V_65:
V_8 -> V_2 [ V_1 -> V_3 ] = NULL ;
F_51 ( V_1 ) ;
return V_27 ;
}
int F_52 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_2 -> V_11 -> V_9 ;
F_53 ( V_1 -> V_2 ) ;
V_8 -> V_2 [ V_1 -> V_3 ] = NULL ;
F_51 ( V_1 ) ;
return 0 ;
}
static T_2 F_54 ( struct V_7 * V_8 ,
struct V_60 * V_68 )
{
struct V_60 * V_61 ;
unsigned V_13 ;
V_61 = F_55 ( V_68 ) ;
if ( ! V_61 )
return 0 ;
F_56 ( V_61 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
struct V_1 * V_1 = V_8 -> V_2 [ V_13 ] ;
if ( V_1 && V_1 -> V_61 == V_61 )
return F_57 ( V_1 -> V_2 ) ;
}
return 0 ;
}
static struct V_60 * F_58 (
const struct V_60 * V_69 , struct V_60 * V_70 )
{
struct V_60 * V_71 = F_59 ( V_69 , V_70 ) ;
F_56 ( V_70 ) ;
return V_71 ;
}
int F_60 ( struct V_4 * V_5 ,
struct V_15 * V_16 , struct V_60 * V_72 )
{
struct V_7 * V_8 = V_5 -> V_9 ;
struct V_60 * V_73 = NULL ;
T_2 V_74 = 0 ;
int V_13 ;
for ( V_13 = 0 ; ; V_13 ++ ) {
T_1 V_75 ;
V_73 = F_58 ( V_72 , V_73 ) ;
if ( ! V_73 )
break;
V_75 = F_54 ( V_8 , V_73 ) ;
if ( V_75 == 0 )
return - V_76 ;
V_74 |= V_75 ;
}
if ( V_73 )
F_56 ( V_73 ) ;
if ( V_13 == 0 )
return - V_77 ;
V_16 -> V_78 = V_74 ;
V_16 -> V_79 = ~ 0 ;
return 0 ;
}
int F_61 ( struct V_60 * V_71 ,
struct V_15 * V_16 )
{
struct V_1 * V_22 = F_11 ( V_16 -> V_2 ) ;
struct V_60 * V_73 = NULL ;
struct V_80 V_68 ;
struct V_60 * V_61 ;
int V_27 ;
if ( ! V_71 || ! V_22 )
return - V_23 ;
do {
V_73 = F_58 ( V_71 , V_73 ) ;
if ( ! V_73 )
break;
V_61 = F_55 ( V_73 ) ;
F_56 ( V_61 ) ;
if ( V_61 == V_22 -> V_61 ) {
V_27 = F_62 ( V_73 , & V_68 ) ;
return V_27 ? V_27 : V_68 . V_61 ;
}
} while ( V_73 );
return - V_23 ;
}
static int F_63 ( struct V_81 * V_11 , void * V_82 )
{
struct V_60 * V_72 = V_82 ;
if ( F_64 ( V_72 -> V_83 , L_3 ) == 0 ) {
V_72 = F_65 ( V_72 ) ;
F_56 ( V_72 ) ;
}
return V_11 -> V_84 == V_72 ;
}
static int F_66 ( struct V_81 * V_85 , struct V_85 * V_86 )
{
struct V_87 * V_88 ;
int V_27 ;
F_37 (component, &imx_drm_components, list) {
V_27 = F_67 ( V_86 , F_63 ,
V_88 -> V_84 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_68 ( struct V_81 * V_11 )
{
return F_69 ( & V_89 , F_70 ( V_11 ) ) ;
}
static void F_71 ( struct V_81 * V_11 )
{
F_72 ( F_73 ( V_11 ) ) ;
}
static struct V_87 * F_74 ( struct V_81 * V_11 ,
struct V_60 * V_71 )
{
struct V_87 * V_88 ;
F_37 (component, &imx_drm_components, list)
if ( V_88 -> V_84 == V_71 )
return V_88 ;
return NULL ;
}
static int F_75 ( struct V_81 * V_11 , struct V_60 * V_71 )
{
struct V_87 * V_88 ;
if ( F_74 ( V_11 , V_71 ) )
return 0 ;
V_88 = F_32 ( V_11 , sizeof( * V_88 ) , V_40 ) ;
if ( ! V_88 )
return - V_41 ;
V_88 -> V_84 = V_71 ;
F_76 ( & V_88 -> V_90 , & V_91 ) ;
return 0 ;
}
static int F_77 ( struct V_92 * V_93 )
{
struct V_60 * V_73 , * V_61 , * V_94 ;
int V_27 ;
int V_13 ;
for ( V_13 = 0 ; ; V_13 ++ ) {
V_61 = F_78 ( V_93 -> V_11 . V_84 , L_4 , V_13 ) ;
if ( ! V_61 )
break;
V_27 = F_75 ( & V_93 -> V_11 , V_61 ) ;
if ( V_27 < 0 )
return V_27 ;
}
if ( V_13 == 0 ) {
F_39 ( & V_93 -> V_11 , L_5 ) ;
return - V_95 ;
}
for ( V_13 = 0 ; ; V_13 ++ ) {
V_61 = F_78 ( V_93 -> V_11 . V_84 , L_4 , V_13 ) ;
if ( ! V_61 )
break;
F_79 (port, ep) {
V_94 = F_80 ( V_73 ) ;
if ( ! V_94 || ! F_81 ( V_94 ) ) {
F_56 ( V_94 ) ;
continue;
} else if ( ! F_81 ( V_94 -> V_69 ) ) {
F_41 ( & V_93 -> V_11 , L_6 ,
V_94 -> V_96 ) ;
F_56 ( V_94 ) ;
continue;
}
V_27 = F_75 ( & V_93 -> V_11 , V_94 ) ;
F_56 ( V_94 ) ;
if ( V_27 < 0 )
return V_27 ;
}
F_56 ( V_61 ) ;
}
V_27 = F_82 ( & V_93 -> V_11 , F_83 ( 32 ) ) ;
if ( V_27 )
return V_27 ;
return F_84 ( & V_93 -> V_11 , & V_97 ) ;
}
static int F_85 ( struct V_92 * V_93 )
{
F_86 ( & V_93 -> V_11 , & V_97 ) ;
return 0 ;
}
