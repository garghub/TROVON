unsigned int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_4 ( V_6 -> V_8 ) ;
}
static int F_5 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_6 ( V_4 ) ;
if ( V_6 -> V_8 )
F_7 ( V_6 -> V_8 ) ;
F_8 ( V_4 -> V_9 , V_4 ) ;
F_9 ( V_4 ) ;
F_10 ( V_4 ) ;
F_11 ( V_4 -> V_10 , NULL ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_1 )
{
return F_13 ( V_1 -> V_2 ) ;
}
void F_14 ( struct V_1 * V_1 )
{
F_15 ( V_1 -> V_2 ) ;
}
void F_16 ( struct V_1 * V_1 )
{
F_17 ( V_1 -> V_2 ) ;
}
static int F_18 ( struct V_3 * V_4 , unsigned int V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 = V_6 -> V_2 [ V_11 ] ;
int V_12 ;
if ( ! V_1 )
return - V_13 ;
if ( ! V_1 -> V_14 . V_15 )
return - V_16 ;
V_12 = V_1 -> V_14 . V_15 (
V_1 -> V_2 ) ;
return V_12 ;
}
static void F_19 ( struct V_3 * V_4 , unsigned int V_11 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 = V_6 -> V_2 [ V_11 ] ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_14 . V_17 )
return;
V_1 -> V_14 . V_17 ( V_1 -> V_2 ) ;
}
void F_20 ( struct V_18 * V_19 )
{
F_21 ( V_19 ) ;
F_22 ( V_19 ) ;
}
void F_23 ( struct V_20 * V_21 )
{
F_24 ( V_21 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
F_26 ( V_6 -> V_8 ) ;
}
static int F_27 ( struct V_3 * V_9 ,
struct V_22 * V_23 )
{
int V_12 ;
V_12 = F_28 ( V_9 , V_23 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_29 ( V_9 , V_23 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_28 ( V_9 , V_23 ) ;
if ( V_12 )
return V_12 ;
return V_12 ;
}
static void F_30 ( struct V_22 * V_23 )
{
struct V_3 * V_9 = V_23 -> V_9 ;
struct V_24 * V_2 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
unsigned V_33 ;
struct V_31 * * V_34 ;
unsigned int V_35 , V_36 ;
int V_12 ;
F_31 (state, crtc, crtc_state, i) {
V_28 = V_2 -> V_37 -> V_23 ;
if ( V_28 -> V_38 ) {
V_30 = F_32 ( V_28 -> V_38 , 0 ) ;
if ( V_30 -> V_39 . V_40 ) {
V_12 = F_33 (
V_30 -> V_39 . V_40 -> V_41 , & V_32 ,
& V_33 , & V_34 ) ;
if ( F_34 ( V_12 ) )
F_35 ( L_1
L_2 ) ;
if ( V_32 ) {
F_36 ( V_32 , false ) ;
F_37 ( V_32 ) ;
}
for ( V_36 = 0 ; V_36 < V_33 ; V_35 ++ ) {
F_36 ( V_34 [ V_36 ] , false ) ;
F_37 ( V_34 [ V_36 ] ) ;
}
}
}
}
F_38 ( V_9 , V_23 ) ;
F_39 ( V_9 , V_23 , true ) ;
F_40 ( V_9 , V_23 ) ;
F_41 ( V_23 ) ;
F_42 ( V_9 , V_23 ) ;
F_43 ( V_9 , V_23 ) ;
}
static int F_44 ( struct V_3 * V_4 , unsigned long V_42 )
{
struct V_5 * V_6 ;
struct V_18 * V_19 ;
int V_12 ;
V_6 = F_45 ( V_4 -> V_9 , sizeof( * V_6 ) , V_43 ) ;
if ( ! V_6 )
return - V_44 ;
V_6 -> V_4 = V_4 ;
V_4 -> V_7 = V_6 ;
V_4 -> V_45 = true ;
V_4 -> V_46 . V_47 = 64 ;
V_4 -> V_46 . V_48 = 64 ;
V_4 -> V_46 . V_49 = 4096 ;
V_4 -> V_46 . V_50 = 4096 ;
V_4 -> V_46 . V_51 = & V_52 ;
V_4 -> V_46 . V_53 = & V_54 ;
F_46 ( V_4 ) ;
V_12 = F_47 ( V_4 , V_55 ) ;
if ( V_12 )
goto V_56;
F_11 ( V_4 -> V_10 , V_4 ) ;
V_12 = F_48 ( V_4 -> V_9 , V_4 ) ;
if ( V_12 )
goto V_57;
F_49 (connector, &drm->mode_config.connector_list, head) {
V_12 = F_50 ( V_19 ) ;
if ( V_12 ) {
F_51 ( V_4 -> V_9 ,
L_3 ,
V_19 -> V_39 . V_58 ,
V_19 -> V_59 , V_12 ) ;
goto V_60;
}
}
F_52 ( V_4 ) ;
#if F_53 ( V_61 )
if ( V_62 != 16 && V_62 != 32 ) {
F_54 ( V_4 -> V_9 , L_4 ) ;
V_62 = 16 ;
}
V_6 -> V_8 = F_55 ( V_4 , V_62 ,
V_4 -> V_46 . V_63 , V_55 ) ;
if ( F_56 ( V_6 -> V_8 ) ) {
V_12 = F_57 ( V_6 -> V_8 ) ;
V_6 -> V_8 = NULL ;
goto V_60;
}
#endif
F_58 ( V_4 ) ;
return 0 ;
V_60:
F_8 ( V_4 -> V_9 , V_4 ) ;
V_57:
F_9 ( V_4 ) ;
V_56:
F_10 ( V_4 ) ;
return V_12 ;
}
int F_59 ( struct V_3 * V_4 , struct V_24 * V_2 ,
struct V_1 * * V_64 , struct V_65 * V_66 ,
const struct V_67 * V_14 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_1 ;
if ( V_6 -> V_70 >= V_55 )
return - V_13 ;
if ( V_6 -> V_4 -> V_71 )
return - V_72 ;
V_1 = F_60 ( sizeof( * V_1 ) , V_43 ) ;
if ( ! V_1 )
return - V_44 ;
V_1 -> V_14 = * V_14 ;
V_1 -> V_2 = V_2 ;
V_2 -> V_69 = V_69 ;
V_6 -> V_2 [ V_6 -> V_70 ++ ] = V_1 ;
* V_64 = V_1 ;
F_61 ( V_2 ,
V_1 -> V_14 . V_73 ) ;
F_62 ( V_4 , V_2 , V_66 , NULL ,
V_1 -> V_14 . V_74 , NULL ) ;
return 0 ;
}
int F_63 ( struct V_1 * V_1 )
{
struct V_5 * V_6 = V_1 -> V_2 -> V_9 -> V_7 ;
unsigned int V_11 = F_2 ( V_1 -> V_2 ) ;
F_64 ( V_1 -> V_2 ) ;
V_6 -> V_2 [ V_11 ] = NULL ;
F_65 ( V_1 ) ;
return 0 ;
}
int F_66 ( struct V_3 * V_4 ,
struct V_20 * V_21 , struct V_68 * V_75 )
{
T_1 V_76 = F_67 ( V_4 , V_75 ) ;
if ( V_76 == 0 )
return - V_77 ;
V_21 -> V_78 = V_76 ;
V_21 -> V_79 = ~ 0 ;
return 0 ;
}
static int F_68 ( struct V_80 * V_9 , void * V_81 )
{
struct V_68 * V_75 = V_81 ;
if ( strcmp ( V_9 -> V_82 -> V_59 , L_5 ) == 0 ) {
struct V_83 * V_84 = V_9 -> V_85 ;
return V_84 -> V_86 == V_75 ;
}
if ( F_69 ( V_75 -> V_59 , L_6 ) == 0 ) {
V_75 = F_70 ( V_75 ) ;
F_71 ( V_75 ) ;
}
return V_9 -> V_86 == V_75 ;
}
static int F_72 ( struct V_80 * V_9 )
{
return F_73 ( & V_87 , F_74 ( V_9 ) ) ;
}
static void F_75 ( struct V_80 * V_9 )
{
F_76 ( F_77 ( V_9 ) ) ;
}
static int F_78 ( struct V_88 * V_89 )
{
int V_12 = F_79 ( & V_89 -> V_9 , F_68 , & V_90 ) ;
if ( ! V_12 )
V_12 = F_80 ( & V_89 -> V_9 , F_81 ( 32 ) ) ;
return V_12 ;
}
static int F_82 ( struct V_88 * V_89 )
{
F_83 ( & V_89 -> V_9 , & V_90 ) ;
return 0 ;
}
static int F_84 ( struct V_80 * V_9 )
{
struct V_3 * V_91 = F_77 ( V_9 ) ;
struct V_5 * V_6 ;
if ( V_91 == NULL )
return 0 ;
F_85 ( V_91 ) ;
V_6 = V_91 -> V_7 ;
V_6 -> V_23 = F_86 ( V_91 ) ;
if ( F_56 ( V_6 -> V_23 ) ) {
F_87 ( V_91 ) ;
return F_57 ( V_6 -> V_23 ) ;
}
return 0 ;
}
static int F_88 ( struct V_80 * V_9 )
{
struct V_3 * V_91 = F_77 ( V_9 ) ;
struct V_5 * V_92 ;
if ( V_91 == NULL )
return 0 ;
V_92 = V_91 -> V_7 ;
F_89 ( V_91 , V_92 -> V_23 ) ;
F_87 ( V_91 ) ;
return 0 ;
}
