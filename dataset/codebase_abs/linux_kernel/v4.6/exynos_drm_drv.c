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
V_15 -> V_49 = true ;
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
bool V_50 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
struct V_12 * V_13 ;
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
for ( V_7 = 0 ; V_7 < V_15 -> V_44 . V_45 ; ++ V_7 ) {
if ( V_2 -> V_26 [ V_7 ] )
V_13 -> V_26 |= 1 << F_53 ( V_2 -> V_26 [ V_7 ] ) ;
}
F_54 ( V_17 -> V_27 , ! F_50 ( V_17 , V_13 -> V_26 ) ) ;
F_16 ( & V_17 -> V_24 ) ;
V_17 -> V_25 |= V_13 -> V_26 ;
F_17 ( & V_17 -> V_24 ) ;
F_55 ( V_15 , V_2 ) ;
if ( V_50 )
F_56 ( & V_13 -> V_29 ) ;
else
F_7 ( V_13 ) ;
return 0 ;
}
static int F_57 ( struct V_14 * V_15 , struct V_51 * V_52 )
{
struct V_53 * V_54 ;
int V_8 ;
V_54 = F_23 ( sizeof( * V_54 ) , V_36 ) ;
if ( ! V_54 )
return - V_37 ;
V_52 -> V_55 = V_54 ;
V_8 = F_58 ( V_15 , V_52 ) ;
if ( V_8 )
goto V_56;
return V_8 ;
V_56:
F_19 ( V_54 ) ;
V_52 -> V_55 = NULL ;
return V_8 ;
}
static void F_59 ( struct V_14 * V_15 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 ;
F_60 ( V_15 , V_52 ) ;
F_34 (crtc, &dev->mode_config.crtc_list, head)
F_61 ( V_6 , V_52 ) ;
}
static void F_62 ( struct V_14 * V_15 , struct V_51 * V_52 )
{
F_19 ( V_52 -> V_55 ) ;
V_52 -> V_55 = NULL ;
}
static void F_63 ( struct V_14 * V_15 )
{
F_64 ( V_15 ) ;
}
static int F_65 ( struct V_57 * V_15 )
{
struct V_14 * V_58 = F_66 ( V_15 ) ;
struct V_59 * V_60 ;
if ( F_67 ( V_15 ) || ! V_58 )
return 0 ;
F_68 ( V_58 ) ;
F_69 (connector, drm_dev) {
int V_61 = V_60 -> V_62 ;
if ( V_60 -> V_63 -> V_62 )
V_60 -> V_63 -> V_62 ( V_60 , V_64 ) ;
V_60 -> V_62 = V_61 ;
}
F_70 ( V_58 ) ;
return 0 ;
}
static int F_71 ( struct V_57 * V_15 )
{
struct V_14 * V_58 = F_66 ( V_15 ) ;
struct V_59 * V_60 ;
if ( F_67 ( V_15 ) || ! V_58 )
return 0 ;
F_68 ( V_58 ) ;
F_69 (connector, drm_dev) {
if ( V_60 -> V_63 -> V_62 ) {
int V_62 = V_60 -> V_62 ;
V_60 -> V_62 = V_64 ;
V_60 -> V_63 -> V_62 ( V_60 , V_62 ) ;
}
}
F_70 ( V_58 ) ;
return 0 ;
}
static int F_72 ( struct V_57 * V_15 , void * V_65 )
{
return V_15 == (struct V_57 * ) V_65 ;
}
static struct V_66 * F_73 ( struct V_57 * V_15 )
{
struct V_66 * V_67 = NULL ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_74 ( V_68 ) ; ++ V_7 ) {
struct V_69 * V_70 = & V_68 [ V_7 ] ;
struct V_57 * V_71 = NULL , * V_72 ;
if ( ! V_70 -> V_73 || ! ( V_70 -> V_30 & V_74 ) )
continue;
while ( ( V_72 = F_75 ( & V_75 , V_71 ,
& V_70 -> V_73 -> V_73 ,
( void * ) V_75 . V_67 ) ) ) {
F_76 ( V_71 ) ;
F_77 ( V_15 , & V_67 , F_72 , V_72 ) ;
V_71 = V_72 ;
}
F_76 ( V_71 ) ;
}
return V_67 ? : F_78 ( - V_39 ) ;
}
static int F_79 ( struct V_57 * V_15 )
{
return F_80 ( & V_76 , F_81 ( V_15 ) ) ;
}
static void F_82 ( struct V_57 * V_15 )
{
F_83 ( F_66 ( V_15 ) ) ;
}
static int F_84 ( struct V_77 * V_78 )
{
struct V_66 * V_67 ;
V_78 -> V_15 . V_79 = F_85 ( 32 ) ;
V_76 . V_80 = F_74 ( V_81 ) ;
V_67 = F_73 ( & V_78 -> V_15 ) ;
if ( F_86 ( V_67 ) )
return F_87 ( V_67 ) ;
return F_88 ( & V_78 -> V_15 , & V_82 ,
V_67 ) ;
}
static int F_89 ( struct V_77 * V_78 )
{
F_90 ( & V_78 -> V_15 , & V_82 ) ;
return 0 ;
}
static struct V_57 * F_27 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_74 ( V_68 ) ; ++ V_7 ) {
struct V_69 * V_70 = & V_68 [ V_7 ] ;
struct V_57 * V_15 ;
if ( ! V_70 -> V_73 || ! ( V_70 -> V_30 & V_83 ) )
continue;
while ( ( V_15 = F_75 ( & V_75 , NULL ,
& V_70 -> V_73 -> V_73 ,
( void * ) V_75 . V_67 ) ) ) {
F_76 ( V_15 ) ;
return V_15 ;
}
}
return NULL ;
}
static void F_91 ( void )
{
int V_7 ;
for ( V_7 = F_74 ( V_68 ) - 1 ; V_7 >= 0 ; -- V_7 ) {
struct V_69 * V_70 = & V_68 [ V_7 ] ;
struct V_57 * V_15 ;
if ( ! V_70 -> V_73 || ! ( V_70 -> V_30 & V_84 ) )
continue;
while ( ( V_15 = F_75 ( & V_75 , NULL ,
& V_70 -> V_73 -> V_73 ,
( void * ) V_75 . V_67 ) ) ) {
F_76 ( V_15 ) ;
F_92 ( F_81 ( V_15 ) ) ;
}
}
}
static int F_93 ( void )
{
struct V_77 * V_78 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_74 ( V_68 ) ; ++ V_7 ) {
struct V_69 * V_70 = & V_68 [ V_7 ] ;
if ( ! V_70 -> V_73 || ! ( V_70 -> V_30 & V_84 ) )
continue;
V_78 = F_94 (
V_70 -> V_73 -> V_73 . V_85 , - 1 , NULL , 0 ) ;
if ( F_86 ( V_78 ) )
goto V_86;
}
return 0 ;
V_86:
F_91 () ;
return F_87 ( V_78 ) ;
}
static void F_95 ( void )
{
int V_7 ;
for ( V_7 = F_74 ( V_68 ) - 1 ; V_7 >= 0 ; -- V_7 ) {
struct V_69 * V_70 = & V_68 [ V_7 ] ;
if ( ! V_70 -> V_73 )
continue;
F_96 ( V_70 -> V_73 ) ;
}
}
static int F_97 ( void )
{
int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < F_74 ( V_68 ) ; ++ V_7 ) {
struct V_69 * V_70 = & V_68 [ V_7 ] ;
if ( ! V_70 -> V_73 )
continue;
V_8 = F_98 ( V_70 -> V_73 ) ;
if ( V_8 )
goto V_86;
}
return 0 ;
V_86:
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
goto V_87;
return 0 ;
V_87:
F_91 () ;
return V_8 ;
}
static void F_100 ( void )
{
F_95 () ;
F_91 () ;
}
