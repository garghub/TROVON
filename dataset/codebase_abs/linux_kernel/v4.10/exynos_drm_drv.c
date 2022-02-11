static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
F_2 ( V_4 , V_9 ) ;
F_3 ( V_4 , V_9 ) ;
F_4 ( V_4 , V_9 , 0 ) ;
F_5 ( V_4 , V_9 ) ;
F_6 ( V_4 , V_9 ) ;
F_7 ( V_9 ) ;
F_8 ( & V_6 -> V_10 ) ;
V_6 -> V_11 &= ~ V_2 -> V_12 ;
F_9 ( & V_6 -> V_10 ) ;
F_10 ( & V_6 -> V_13 ) ;
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_13 ( V_15 ,
struct V_1 , V_15 ) ;
F_1 ( V_2 ) ;
}
static int F_14 ( struct V_3 * V_4 , unsigned long V_16 )
{
struct V_5 * V_17 ;
struct V_18 * V_19 ;
unsigned int V_20 ;
int V_21 , V_22 ;
V_17 = F_15 ( sizeof( struct V_5 ) , V_23 ) ;
if ( ! V_17 )
return - V_24 ;
F_16 ( & V_17 -> V_13 ) ;
F_17 ( & V_17 -> V_10 ) ;
F_18 ( V_4 -> V_4 , V_4 ) ;
V_4 -> V_7 = ( void * ) V_17 ;
V_17 -> V_25 = F_19 () ;
if ( ! V_17 -> V_25 ) {
F_20 ( L_1 ) ;
V_22 = - V_26 ;
goto V_27;
}
F_21 ( L_2 ,
F_22 ( V_17 -> V_25 ) ) ;
V_22 = F_23 ( V_4 ) ;
if ( V_22 < 0 ) {
F_20 ( L_3 ) ;
goto V_27;
}
F_24 ( V_4 ) ;
F_25 ( V_4 ) ;
V_21 = 0 ;
V_20 = 0 ;
F_26 (encoder, &dev->mode_config.encoder_list, head)
V_20 |= ( 1 << ( V_21 ++ ) ) ;
F_26 (encoder, &dev->mode_config.encoder_list, head)
V_19 -> V_28 = V_20 ;
F_27 ( V_4 -> V_29 , V_4 ) ;
V_22 = F_28 ( V_4 -> V_4 , V_4 ) ;
if ( V_22 )
goto V_30;
V_22 = F_29 ( V_4 , V_4 -> V_31 . V_32 ) ;
if ( V_22 )
goto V_33;
V_22 = F_30 ( V_4 ) ;
if ( V_22 )
goto V_34;
F_31 ( V_4 ) ;
V_4 -> V_35 = true ;
F_32 ( V_4 ) ;
F_33 ( V_4 ) ;
return 0 ;
V_34:
F_34 ( V_4 ) ;
V_33:
F_35 ( V_4 -> V_4 , V_4 ) ;
V_30:
F_36 ( V_4 ) ;
F_37 ( V_4 ) ;
V_27:
F_11 ( V_17 ) ;
return V_22 ;
}
static int F_38 ( struct V_3 * V_4 )
{
F_39 ( V_4 ) ;
F_40 ( V_4 ) ;
F_41 ( V_4 ) ;
F_34 ( V_4 ) ;
F_35 ( V_4 -> V_4 , V_4 ) ;
F_36 ( V_4 ) ;
F_37 ( V_4 ) ;
F_11 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
return 0 ;
}
static int F_42 ( struct V_5 * V_6 , T_1 V_12 )
{
bool V_11 ;
F_8 ( & V_6 -> V_10 ) ;
V_11 = V_6 -> V_11 & V_12 ;
F_9 ( & V_6 -> V_10 ) ;
return V_11 ;
}
int V_1 ( struct V_3 * V_4 , struct V_8 * V_9 ,
bool V_36 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_41 , V_22 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_22 = F_43 ( V_4 , V_9 ) ;
if ( V_22 ) {
F_11 ( V_2 ) ;
return V_22 ;
}
F_44 ( & V_2 -> V_15 , F_12 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_9 = V_9 ;
F_45 (state, crtc, crtc_state, i)
V_2 -> V_12 |= F_46 ( V_38 ) ;
F_47 ( V_6 -> V_13 , ! F_42 ( V_6 , V_2 -> V_12 ) ) ;
F_8 ( & V_6 -> V_10 ) ;
V_6 -> V_11 |= V_2 -> V_12 ;
F_9 ( & V_6 -> V_10 ) ;
F_48 ( V_9 , true ) ;
F_49 ( V_9 ) ;
if ( V_36 )
F_50 ( & V_2 -> V_15 ) ;
else
F_1 ( V_2 ) ;
return 0 ;
}
int F_51 ( struct V_3 * V_4 ,
struct V_8 * V_9 )
{
int V_22 ;
V_22 = F_52 ( V_4 , V_9 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_53 ( V_4 , V_9 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_54 ( V_4 , V_9 ) ;
if ( V_22 )
return V_22 ;
return V_22 ;
}
static int F_55 ( struct V_3 * V_4 , struct V_42 * V_43 )
{
struct V_44 * V_45 ;
int V_22 ;
V_45 = F_15 ( sizeof( * V_45 ) , V_23 ) ;
if ( ! V_45 )
return - V_24 ;
V_43 -> V_46 = V_45 ;
V_22 = F_56 ( V_4 , V_43 ) ;
if ( V_22 )
goto V_47;
return V_22 ;
V_47:
F_11 ( V_45 ) ;
V_43 -> V_46 = NULL ;
return V_22 ;
}
static void F_57 ( struct V_3 * V_4 ,
struct V_42 * V_43 )
{
struct V_37 * V_38 ;
F_58 ( V_4 , V_43 ) ;
F_26 (crtc, &dev->mode_config.crtc_list, head)
F_59 ( V_38 , V_43 ) ;
}
static void F_60 ( struct V_3 * V_4 , struct V_42 * V_43 )
{
F_11 ( V_43 -> V_46 ) ;
V_43 -> V_46 = NULL ;
}
static void F_61 ( struct V_3 * V_4 )
{
F_62 ( V_4 ) ;
}
static int F_63 ( struct V_48 * V_4 )
{
struct V_3 * V_49 = F_64 ( V_4 ) ;
struct V_50 * V_51 ;
if ( F_65 ( V_4 ) || ! V_49 )
return 0 ;
F_66 ( V_49 ) ;
F_67 (connector, drm_dev) {
int V_52 = V_51 -> V_53 ;
if ( V_51 -> V_54 -> V_53 )
V_51 -> V_54 -> V_53 ( V_51 , V_55 ) ;
V_51 -> V_53 = V_52 ;
}
F_68 ( V_49 ) ;
return 0 ;
}
static int F_69 ( struct V_48 * V_4 )
{
struct V_3 * V_49 = F_64 ( V_4 ) ;
struct V_50 * V_51 ;
if ( F_65 ( V_4 ) || ! V_49 )
return 0 ;
F_66 ( V_49 ) ;
F_67 (connector, drm_dev) {
if ( V_51 -> V_54 -> V_53 ) {
int V_53 = V_51 -> V_53 ;
V_51 -> V_53 = V_55 ;
V_51 -> V_54 -> V_53 ( V_51 , V_53 ) ;
}
}
F_68 ( V_49 ) ;
return 0 ;
}
static int F_70 ( struct V_48 * V_4 , void * V_56 )
{
return V_4 == (struct V_48 * ) V_56 ;
}
static struct V_57 * F_71 ( struct V_48 * V_4 )
{
struct V_57 * V_58 = NULL ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_72 ( V_59 ) ; ++ V_41 ) {
struct V_60 * V_61 = & V_59 [ V_41 ] ;
struct V_48 * V_62 = NULL , * V_63 ;
if ( ! V_61 -> V_64 || ! ( V_61 -> V_16 & V_65 ) )
continue;
while ( ( V_63 = F_73 ( & V_66 , V_62 ,
& V_61 -> V_64 -> V_64 ,
( void * ) V_66 . V_58 ) ) ) {
F_74 ( V_62 ) ;
F_75 ( V_4 , & V_58 , F_70 , V_63 ) ;
V_62 = V_63 ;
}
F_74 ( V_62 ) ;
}
return V_58 ? : F_76 ( - V_26 ) ;
}
static int F_77 ( struct V_48 * V_4 )
{
return F_78 ( & V_67 , F_79 ( V_4 ) ) ;
}
static void F_80 ( struct V_48 * V_4 )
{
F_81 ( F_64 ( V_4 ) ) ;
}
static int F_82 ( struct V_68 * V_69 )
{
struct V_57 * V_58 ;
V_69 -> V_4 . V_70 = F_83 ( 32 ) ;
V_67 . V_71 = F_72 ( V_72 ) ;
V_58 = F_71 ( & V_69 -> V_4 ) ;
if ( F_84 ( V_58 ) )
return F_85 ( V_58 ) ;
return F_86 ( & V_69 -> V_4 , & V_73 ,
V_58 ) ;
}
static int F_87 ( struct V_68 * V_69 )
{
F_88 ( & V_69 -> V_4 , & V_73 ) ;
return 0 ;
}
static struct V_48 * F_19 ( void )
{
int V_41 ;
for ( V_41 = 0 ; V_41 < F_72 ( V_59 ) ; ++ V_41 ) {
struct V_60 * V_61 = & V_59 [ V_41 ] ;
struct V_48 * V_4 ;
if ( ! V_61 -> V_64 || ! ( V_61 -> V_16 & V_74 ) )
continue;
while ( ( V_4 = F_73 ( & V_66 , NULL ,
& V_61 -> V_64 -> V_64 ,
( void * ) V_66 . V_58 ) ) ) {
F_74 ( V_4 ) ;
return V_4 ;
}
}
return NULL ;
}
static void F_89 ( void )
{
int V_41 ;
for ( V_41 = F_72 ( V_59 ) - 1 ; V_41 >= 0 ; -- V_41 ) {
struct V_60 * V_61 = & V_59 [ V_41 ] ;
struct V_48 * V_4 ;
if ( ! V_61 -> V_64 || ! ( V_61 -> V_16 & V_75 ) )
continue;
while ( ( V_4 = F_73 ( & V_66 , NULL ,
& V_61 -> V_64 -> V_64 ,
( void * ) V_66 . V_58 ) ) ) {
F_74 ( V_4 ) ;
F_90 ( F_79 ( V_4 ) ) ;
}
}
}
static int F_91 ( void )
{
struct V_68 * V_69 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < F_72 ( V_59 ) ; ++ V_41 ) {
struct V_60 * V_61 = & V_59 [ V_41 ] ;
if ( ! V_61 -> V_64 || ! ( V_61 -> V_16 & V_75 ) )
continue;
V_69 = F_92 (
V_61 -> V_64 -> V_64 . V_76 , - 1 , NULL , 0 ) ;
if ( F_84 ( V_69 ) )
goto V_77;
}
return 0 ;
V_77:
F_89 () ;
return F_85 ( V_69 ) ;
}
static void F_93 ( void )
{
int V_41 ;
for ( V_41 = F_72 ( V_59 ) - 1 ; V_41 >= 0 ; -- V_41 ) {
struct V_60 * V_61 = & V_59 [ V_41 ] ;
if ( ! V_61 -> V_64 )
continue;
F_94 ( V_61 -> V_64 ) ;
}
}
static int F_95 ( void )
{
int V_41 , V_22 ;
for ( V_41 = 0 ; V_41 < F_72 ( V_59 ) ; ++ V_41 ) {
struct V_60 * V_61 = & V_59 [ V_41 ] ;
if ( ! V_61 -> V_64 )
continue;
V_22 = F_96 ( V_61 -> V_64 ) ;
if ( V_22 )
goto V_77;
}
return 0 ;
V_77:
F_93 () ;
return V_22 ;
}
static int F_97 ( void )
{
int V_22 ;
V_22 = F_91 () ;
if ( V_22 )
return V_22 ;
V_22 = F_95 () ;
if ( V_22 )
goto V_78;
return 0 ;
V_78:
F_89 () ;
return V_22 ;
}
static void F_98 ( void )
{
F_93 () ;
F_89 () ;
}
