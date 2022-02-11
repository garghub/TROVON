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
V_8 = F_27 ( V_15 ) ;
if ( V_8 < 0 ) {
F_28 ( L_1 ) ;
goto V_38;
}
F_29 ( V_15 ) ;
F_30 ( V_15 ) ;
V_35 = 0 ;
V_34 = 0 ;
F_31 (encoder, &dev->mode_config.encoder_list, head)
V_34 |= ( 1 << ( V_35 ++ ) ) ;
F_31 (encoder, &dev->mode_config.encoder_list, head)
V_33 -> V_39 = V_34 ;
F_32 ( V_15 -> V_40 , V_15 ) ;
V_8 = F_33 ( V_15 -> V_15 , V_15 ) ;
if ( V_8 )
goto V_41;
V_8 = F_34 ( V_15 , V_15 -> V_42 . V_43 ) ;
if ( V_8 )
goto V_44;
V_8 = F_35 ( V_15 ) ;
if ( V_8 )
goto V_45;
F_36 ( V_15 ) ;
V_15 -> V_46 = true ;
V_15 -> V_47 = true ;
F_37 ( V_15 ) ;
F_38 ( V_15 ) ;
return 0 ;
V_45:
F_39 ( V_15 ) ;
V_44:
F_40 ( V_15 -> V_15 , V_15 ) ;
V_41:
F_41 ( V_15 ) ;
F_42 ( V_15 ) ;
V_38:
F_19 ( V_31 ) ;
return V_8 ;
}
static int F_43 ( struct V_14 * V_15 )
{
F_44 ( V_15 ) ;
F_45 ( V_15 ) ;
F_46 ( V_15 ) ;
F_39 ( V_15 ) ;
F_40 ( V_15 -> V_15 , V_15 ) ;
F_41 ( V_15 ) ;
F_42 ( V_15 ) ;
F_19 ( V_15 -> V_18 ) ;
V_15 -> V_18 = NULL ;
return 0 ;
}
static int F_47 ( struct V_16 * V_17 , T_1 V_26 )
{
bool V_25 ;
F_16 ( & V_17 -> V_24 ) ;
V_25 = V_17 -> V_25 & V_26 ;
F_17 ( & V_17 -> V_24 ) ;
return V_25 ;
}
int V_12 ( struct V_14 * V_15 , struct V_1 * V_2 ,
bool V_48 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_12 * V_13 ;
int V_7 , V_8 ;
V_13 = F_23 ( sizeof( * V_13 ) , V_36 ) ;
if ( ! V_13 )
return - V_37 ;
V_8 = F_48 ( V_15 , V_2 ) ;
if ( V_8 ) {
F_19 ( V_13 ) ;
return V_8 ;
}
F_49 ( & V_13 -> V_29 , F_20 ) ;
V_13 -> V_15 = V_15 ;
V_13 -> V_2 = V_2 ;
for ( V_7 = 0 ; V_7 < V_15 -> V_42 . V_43 ; ++ V_7 ) {
if ( V_2 -> V_26 [ V_7 ] )
V_13 -> V_26 |= 1 << F_50 ( V_2 -> V_26 [ V_7 ] ) ;
}
F_51 ( V_17 -> V_27 , ! F_47 ( V_17 , V_13 -> V_26 ) ) ;
F_16 ( & V_17 -> V_24 ) ;
V_17 -> V_25 |= V_13 -> V_26 ;
F_17 ( & V_17 -> V_24 ) ;
F_52 ( V_15 , V_2 ) ;
if ( V_48 )
F_53 ( & V_13 -> V_29 ) ;
else
F_7 ( V_13 ) ;
return 0 ;
}
static int F_54 ( struct V_14 * V_15 , struct V_49 * V_50 )
{
struct V_51 * V_52 ;
int V_8 ;
V_52 = F_23 ( sizeof( * V_52 ) , V_36 ) ;
if ( ! V_52 )
return - V_37 ;
V_50 -> V_53 = V_52 ;
V_8 = F_55 ( V_15 , V_50 ) ;
if ( V_8 )
goto V_54;
return V_8 ;
V_54:
F_19 ( V_52 ) ;
V_50 -> V_53 = NULL ;
return V_8 ;
}
static void F_56 ( struct V_14 * V_15 ,
struct V_49 * V_50 )
{
struct V_5 * V_6 ;
F_57 ( V_15 , V_50 ) ;
F_31 (crtc, &dev->mode_config.crtc_list, head)
F_58 ( V_6 , V_50 ) ;
}
static void F_59 ( struct V_14 * V_15 , struct V_49 * V_50 )
{
struct V_55 * V_56 , * V_57 ;
unsigned long V_30 ;
if ( ! V_50 -> V_53 )
return;
F_60 ( & V_15 -> V_58 , V_30 ) ;
F_61 (e, et, &file->event_list, link) {
F_62 ( & V_56 -> V_59 ) ;
V_56 -> V_60 ( V_56 ) ;
}
F_63 ( & V_15 -> V_58 , V_30 ) ;
F_19 ( V_50 -> V_53 ) ;
V_50 -> V_53 = NULL ;
}
static void F_64 ( struct V_14 * V_15 )
{
F_65 ( V_15 ) ;
}
static int F_66 ( struct V_61 * V_15 )
{
struct V_14 * V_62 = F_67 ( V_15 ) ;
struct V_63 * V_64 ;
if ( F_68 ( V_15 ) || ! V_62 )
return 0 ;
F_69 ( V_62 ) ;
F_70 (connector, drm_dev) {
int V_65 = V_64 -> V_66 ;
if ( V_64 -> V_67 -> V_66 )
V_64 -> V_67 -> V_66 ( V_64 , V_68 ) ;
V_64 -> V_66 = V_65 ;
}
F_71 ( V_62 ) ;
return 0 ;
}
static int F_72 ( struct V_61 * V_15 )
{
struct V_14 * V_62 = F_67 ( V_15 ) ;
struct V_63 * V_64 ;
if ( F_68 ( V_15 ) || ! V_62 )
return 0 ;
F_69 ( V_62 ) ;
F_70 (connector, drm_dev) {
if ( V_64 -> V_67 -> V_66 ) {
int V_66 = V_64 -> V_66 ;
V_64 -> V_66 = V_68 ;
V_64 -> V_67 -> V_66 ( V_64 , V_66 ) ;
}
}
F_71 ( V_62 ) ;
return 0 ;
}
static int F_73 ( struct V_61 * V_15 , void * V_69 )
{
return V_15 == (struct V_61 * ) V_69 ;
}
static struct V_70 * F_74 ( struct V_61 * V_15 )
{
struct V_70 * V_71 = NULL ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_75 ( V_72 ) ; ++ V_7 ) {
struct V_73 * V_74 = & V_72 [ V_7 ] -> V_75 ;
struct V_61 * V_76 = NULL , * V_77 ;
while ( ( V_77 = F_76 ( & V_78 , V_76 , V_74 ,
( void * ) V_78 . V_71 ) ) ) {
F_77 ( V_76 ) ;
F_78 ( V_15 , & V_71 , F_73 , V_77 ) ;
V_76 = V_77 ;
}
F_77 ( V_76 ) ;
}
return V_71 ? : F_79 ( - V_79 ) ;
}
static int F_80 ( struct V_61 * V_15 )
{
return F_81 ( & V_80 , F_82 ( V_15 ) ) ;
}
static void F_83 ( struct V_61 * V_15 )
{
F_84 ( F_67 ( V_15 ) ) ;
}
static int F_85 ( struct V_81 * V_82 )
{
struct V_70 * V_71 ;
V_82 -> V_15 . V_83 = F_86 ( 32 ) ;
V_80 . V_84 = F_75 ( V_85 ) ;
V_71 = F_74 ( & V_82 -> V_15 ) ;
if ( F_87 ( V_71 ) )
return F_88 ( V_71 ) ;
return F_89 ( & V_82 -> V_15 , & V_86 ,
V_71 ) ;
}
static int F_90 ( struct V_81 * V_82 )
{
F_91 ( & V_82 -> V_15 , & V_86 ) ;
return 0 ;
}
static void F_92 ( void )
{
int V_7 = V_87 ;
while ( -- V_7 >= 0 ) {
F_93 ( V_88 [ V_7 ] ) ;
V_88 [ V_7 ] = NULL ;
}
}
static int F_94 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_87 ; ++ V_7 ) {
struct V_89 * V_77 = V_90 [ V_7 ] ;
struct V_81 * V_82 =
F_95 ( V_77 -> V_75 . V_91 , - 1 ,
NULL , 0 ) ;
if ( ! F_87 ( V_82 ) ) {
V_88 [ V_7 ] = V_82 ;
continue;
}
while ( -- V_7 >= 0 ) {
F_93 ( V_88 [ V_7 ] ) ;
V_88 [ V_7 ] = NULL ;
}
return F_88 ( V_82 ) ;
}
return 0 ;
}
static void F_96 ( struct V_89 * const * V_74 ,
int V_92 )
{
while ( -- V_92 >= 0 )
F_97 ( V_74 [ V_92 ] ) ;
}
static int F_98 ( struct V_89 * const * V_74 ,
int V_92 )
{
int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_92 ; ++ V_7 ) {
V_8 = F_99 ( V_74 [ V_7 ] ) ;
if ( ! V_8 )
continue;
while ( -- V_7 >= 0 )
F_97 ( V_74 [ V_7 ] ) ;
return V_8 ;
}
return 0 ;
}
static inline int F_100 ( void )
{
return F_98 ( V_72 ,
F_75 ( V_72 ) ) ;
}
static inline int F_101 ( void )
{
return F_98 ( V_93 ,
F_75 ( V_93 ) ) ;
}
static inline void F_102 ( void )
{
F_96 ( V_72 ,
F_75 ( V_72 ) ) ;
}
static inline void F_103 ( void )
{
F_96 ( V_93 ,
F_75 ( V_93 ) ) ;
}
static int F_104 ( void )
{
int V_8 ;
V_8 = F_94 () ;
if ( V_8 )
return V_8 ;
V_8 = F_100 () ;
if ( V_8 )
goto V_94;
V_8 = F_101 () ;
if ( V_8 )
goto V_95;
return 0 ;
V_95:
F_102 () ;
V_94:
F_92 () ;
return V_8 ;
}
static void F_105 ( void )
{
F_103 () ;
F_102 () ;
F_92 () ;
}
