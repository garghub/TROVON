static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 , V_8 ;
F_2 (state, crtc, crtc_state, i) {
struct V_9 * V_10 = F_3 ( V_6 ) ;
if ( ! V_6 -> V_2 -> V_11 )
continue;
V_8 = F_4 ( V_6 ) ;
if ( V_8 )
continue;
F_5 ( V_10 ) ;
F_6 ( V_6 ) ;
}
}
static void F_7 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_19 * V_20 ;
struct V_5 * V_6 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
int V_7 ;
F_8 ( V_15 , V_2 ) ;
F_9 ( V_15 , V_2 ) ;
F_2 (state, crtc, crtc_state, i) {
struct V_9 * V_10 = F_3 ( V_6 ) ;
F_10 ( & V_10 -> V_23 , 0 ) ;
}
F_11 (state, plane, plane_state, i) {
struct V_9 * V_10 =
F_3 ( V_20 -> V_6 ) ;
if ( ! V_20 -> V_6 )
continue;
F_12 ( & V_10 -> V_23 ) ;
}
F_13 ( V_15 , V_2 , false ) ;
F_1 ( V_2 ) ;
F_14 ( V_15 , V_2 ) ;
F_15 ( V_2 ) ;
F_16 ( & V_17 -> V_24 ) ;
V_17 -> V_25 &= ~ V_13 -> V_26 ;
F_17 ( & V_17 -> V_24 ) ;
F_18 ( & V_17 -> V_27 ) ;
F_19 ( V_13 ) ;
}
static void F_20 ( struct V_28 * V_29 )
{
struct V_12 * V_13 = F_21 ( V_29 ,
struct V_12 , V_29 ) ;
F_7 ( V_13 ) ;
}
static int F_22 ( struct V_14 * V_15 , unsigned long V_30 )
{
struct V_16 * V_31 ;
struct V_32 * V_33 ;
unsigned int V_34 ;
int V_35 , V_8 ;
V_31 = F_23 ( sizeof( struct V_16 ) , V_36 ) ;
if ( ! V_31 )
return - V_37 ;
F_24 ( & V_31 -> V_27 ) ;
F_25 ( & V_31 -> V_24 ) ;
F_26 ( V_15 -> V_15 , V_15 ) ;
V_15 -> V_18 = ( void * ) V_31 ;
V_31 -> V_38 = F_27 () ;
if ( ! V_31 -> V_38 ) {
F_28 ( L_1 ) ;
V_8 = - V_39 ;
goto V_40;
}
F_29 ( L_2 ,
F_30 ( V_31 -> V_38 ) ) ;
V_8 = F_31 ( V_15 ) ;
if ( V_8 < 0 ) {
F_28 ( L_3 ) ;
goto V_40;
}
F_32 ( V_15 ) ;
F_33 ( V_15 ) ;
V_35 = 0 ;
V_34 = 0 ;
F_34 (encoder, &dev->mode_config.encoder_list, head)
V_34 |= ( 1 << ( V_35 ++ ) ) ;
F_34 (encoder, &dev->mode_config.encoder_list, head)
V_33 -> V_41 = V_34 ;
F_35 ( V_15 -> V_42 , V_15 ) ;
V_8 = F_36 ( V_15 -> V_15 , V_15 ) ;
if ( V_8 )
goto V_43;
V_8 = F_37 ( V_15 , V_15 -> V_44 . V_45 ) ;
if ( V_8 )
goto V_46;
V_8 = F_38 ( V_15 ) ;
if ( V_8 )
goto V_47;
F_39 ( V_15 ) ;
V_15 -> V_48 = true ;
F_40 ( V_15 ) ;
F_41 ( V_15 ) ;
return 0 ;
V_47:
F_42 ( V_15 ) ;
V_46:
F_43 ( V_15 -> V_15 , V_15 ) ;
V_43:
F_44 ( V_15 ) ;
F_45 ( V_15 ) ;
V_40:
F_19 ( V_31 ) ;
return V_8 ;
}
static int F_46 ( struct V_14 * V_15 )
{
F_47 ( V_15 ) ;
F_48 ( V_15 ) ;
F_49 ( V_15 ) ;
F_42 ( V_15 ) ;
F_43 ( V_15 -> V_15 , V_15 ) ;
F_44 ( V_15 ) ;
F_45 ( V_15 ) ;
F_19 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
return 0 ;
}
static int F_50 ( struct V_16 * V_17 , T_1 V_26 )
{
bool V_25 ;
F_16 ( & V_17 -> V_24 ) ;
V_25 = V_17 -> V_25 & V_26 ;
F_17 ( & V_17 -> V_24 ) ;
return V_25 ;
}
int V_12 ( struct V_14 * V_15 , struct V_1 * V_2 ,
bool V_49 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_12 * V_13 ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_7 , V_8 ;
V_13 = F_23 ( sizeof( * V_13 ) , V_36 ) ;
if ( ! V_13 )
return - V_37 ;
V_8 = F_51 ( V_15 , V_2 ) ;
if ( V_8 ) {
F_19 ( V_13 ) ;
return V_8 ;
}
F_52 ( & V_13 -> V_29 , F_20 ) ;
V_13 -> V_15 = V_15 ;
V_13 -> V_2 = V_2 ;
F_2 (state, crtc, crtc_state, i)
V_13 -> V_26 |= F_53 ( V_6 ) ;
F_54 ( V_17 -> V_27 , ! F_50 ( V_17 , V_13 -> V_26 ) ) ;
F_16 ( & V_17 -> V_24 ) ;
V_17 -> V_25 |= V_13 -> V_26 ;
F_17 ( & V_17 -> V_24 ) ;
F_55 ( V_2 , true ) ;
if ( V_49 )
F_56 ( & V_13 -> V_29 ) ;
else
F_7 ( V_13 ) ;
return 0 ;
}
static int F_57 ( struct V_14 * V_15 , struct V_50 * V_51 )
{
struct V_52 * V_53 ;
int V_8 ;
V_53 = F_23 ( sizeof( * V_53 ) , V_36 ) ;
if ( ! V_53 )
return - V_37 ;
V_51 -> V_54 = V_53 ;
V_8 = F_58 ( V_15 , V_51 ) ;
if ( V_8 )
goto V_55;
return V_8 ;
V_55:
F_19 ( V_53 ) ;
V_51 -> V_54 = NULL ;
return V_8 ;
}
static void F_59 ( struct V_14 * V_15 ,
struct V_50 * V_51 )
{
struct V_5 * V_6 ;
F_60 ( V_15 , V_51 ) ;
F_34 (crtc, &dev->mode_config.crtc_list, head)
F_61 ( V_6 , V_51 ) ;
}
static void F_62 ( struct V_14 * V_15 , struct V_50 * V_51 )
{
F_19 ( V_51 -> V_54 ) ;
V_51 -> V_54 = NULL ;
}
static void F_63 ( struct V_14 * V_15 )
{
F_64 ( V_15 ) ;
}
static int F_65 ( struct V_56 * V_15 )
{
struct V_14 * V_57 = F_66 ( V_15 ) ;
struct V_58 * V_59 ;
if ( F_67 ( V_15 ) || ! V_57 )
return 0 ;
F_68 ( V_57 ) ;
F_69 (connector, drm_dev) {
int V_60 = V_59 -> V_61 ;
if ( V_59 -> V_62 -> V_61 )
V_59 -> V_62 -> V_61 ( V_59 , V_63 ) ;
V_59 -> V_61 = V_60 ;
}
F_70 ( V_57 ) ;
return 0 ;
}
static int F_71 ( struct V_56 * V_15 )
{
struct V_14 * V_57 = F_66 ( V_15 ) ;
struct V_58 * V_59 ;
if ( F_67 ( V_15 ) || ! V_57 )
return 0 ;
F_68 ( V_57 ) ;
F_69 (connector, drm_dev) {
if ( V_59 -> V_62 -> V_61 ) {
int V_61 = V_59 -> V_61 ;
V_59 -> V_61 = V_63 ;
V_59 -> V_62 -> V_61 ( V_59 , V_61 ) ;
}
}
F_70 ( V_57 ) ;
return 0 ;
}
static int F_72 ( struct V_56 * V_15 , void * V_64 )
{
return V_15 == (struct V_56 * ) V_64 ;
}
static struct V_65 * F_73 ( struct V_56 * V_15 )
{
struct V_65 * V_66 = NULL ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_74 ( V_67 ) ; ++ V_7 ) {
struct V_68 * V_69 = & V_67 [ V_7 ] ;
struct V_56 * V_70 = NULL , * V_71 ;
if ( ! V_69 -> V_72 || ! ( V_69 -> V_30 & V_73 ) )
continue;
while ( ( V_71 = F_75 ( & V_74 , V_70 ,
& V_69 -> V_72 -> V_72 ,
( void * ) V_74 . V_66 ) ) ) {
F_76 ( V_70 ) ;
F_77 ( V_15 , & V_66 , F_72 , V_71 ) ;
V_70 = V_71 ;
}
F_76 ( V_70 ) ;
}
return V_66 ? : F_78 ( - V_39 ) ;
}
static int F_79 ( struct V_56 * V_15 )
{
return F_80 ( & V_75 , F_81 ( V_15 ) ) ;
}
static void F_82 ( struct V_56 * V_15 )
{
F_83 ( F_66 ( V_15 ) ) ;
}
static int F_84 ( struct V_76 * V_77 )
{
struct V_65 * V_66 ;
V_77 -> V_15 . V_78 = F_85 ( 32 ) ;
V_75 . V_79 = F_74 ( V_80 ) ;
V_66 = F_73 ( & V_77 -> V_15 ) ;
if ( F_86 ( V_66 ) )
return F_87 ( V_66 ) ;
return F_88 ( & V_77 -> V_15 , & V_81 ,
V_66 ) ;
}
static int F_89 ( struct V_76 * V_77 )
{
F_90 ( & V_77 -> V_15 , & V_81 ) ;
return 0 ;
}
static struct V_56 * F_27 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_74 ( V_67 ) ; ++ V_7 ) {
struct V_68 * V_69 = & V_67 [ V_7 ] ;
struct V_56 * V_15 ;
if ( ! V_69 -> V_72 || ! ( V_69 -> V_30 & V_82 ) )
continue;
while ( ( V_15 = F_75 ( & V_74 , NULL ,
& V_69 -> V_72 -> V_72 ,
( void * ) V_74 . V_66 ) ) ) {
F_76 ( V_15 ) ;
return V_15 ;
}
}
return NULL ;
}
static void F_91 ( void )
{
int V_7 ;
for ( V_7 = F_74 ( V_67 ) - 1 ; V_7 >= 0 ; -- V_7 ) {
struct V_68 * V_69 = & V_67 [ V_7 ] ;
struct V_56 * V_15 ;
if ( ! V_69 -> V_72 || ! ( V_69 -> V_30 & V_83 ) )
continue;
while ( ( V_15 = F_75 ( & V_74 , NULL ,
& V_69 -> V_72 -> V_72 ,
( void * ) V_74 . V_66 ) ) ) {
F_76 ( V_15 ) ;
F_92 ( F_81 ( V_15 ) ) ;
}
}
}
static int F_93 ( void )
{
struct V_76 * V_77 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_74 ( V_67 ) ; ++ V_7 ) {
struct V_68 * V_69 = & V_67 [ V_7 ] ;
if ( ! V_69 -> V_72 || ! ( V_69 -> V_30 & V_83 ) )
continue;
V_77 = F_94 (
V_69 -> V_72 -> V_72 . V_84 , - 1 , NULL , 0 ) ;
if ( F_86 ( V_77 ) )
goto V_85;
}
return 0 ;
V_85:
F_91 () ;
return F_87 ( V_77 ) ;
}
static void F_95 ( void )
{
int V_7 ;
for ( V_7 = F_74 ( V_67 ) - 1 ; V_7 >= 0 ; -- V_7 ) {
struct V_68 * V_69 = & V_67 [ V_7 ] ;
if ( ! V_69 -> V_72 )
continue;
F_96 ( V_69 -> V_72 ) ;
}
}
static int F_97 ( void )
{
int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < F_74 ( V_67 ) ; ++ V_7 ) {
struct V_68 * V_69 = & V_67 [ V_7 ] ;
if ( ! V_69 -> V_72 )
continue;
V_8 = F_98 ( V_69 -> V_72 ) ;
if ( V_8 )
goto V_85;
}
return 0 ;
V_85:
F_95 () ;
return V_8 ;
}
static int F_99 ( void )
{
int V_8 ;
V_8 = F_93 () ;
if ( V_8 )
return V_8 ;
V_8 = F_97 () ;
if ( V_8 )
goto V_86;
return 0 ;
V_86:
F_91 () ;
return V_8 ;
}
static void F_100 ( void )
{
F_95 () ;
F_91 () ;
}
