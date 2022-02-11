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
static int F_54 ( struct V_14 * V_15 , T_2 V_2 )
{
struct V_49 * V_50 ;
F_55 ( V_15 ) ;
F_31 (connector, &dev->mode_config.connector_list, head) {
int V_51 = V_50 -> V_52 ;
if ( V_50 -> V_53 -> V_52 )
V_50 -> V_53 -> V_52 ( V_50 , V_54 ) ;
V_50 -> V_52 = V_51 ;
}
F_56 ( V_15 ) ;
return 0 ;
}
static int F_57 ( struct V_14 * V_15 )
{
struct V_49 * V_50 ;
F_55 ( V_15 ) ;
F_31 (connector, &dev->mode_config.connector_list, head) {
if ( V_50 -> V_53 -> V_52 ) {
int V_52 = V_50 -> V_52 ;
V_50 -> V_52 = V_54 ;
V_50 -> V_53 -> V_52 ( V_50 , V_52 ) ;
}
}
F_56 ( V_15 ) ;
return 0 ;
}
static int F_58 ( struct V_14 * V_15 , struct V_55 * V_56 )
{
struct V_57 * V_58 ;
int V_8 ;
V_58 = F_23 ( sizeof( * V_58 ) , V_36 ) ;
if ( ! V_58 )
return - V_37 ;
V_56 -> V_59 = V_58 ;
V_8 = F_59 ( V_15 , V_56 ) ;
if ( V_8 )
goto V_60;
return V_8 ;
V_60:
F_19 ( V_58 ) ;
V_56 -> V_59 = NULL ;
return V_8 ;
}
static void F_60 ( struct V_14 * V_15 ,
struct V_55 * V_56 )
{
F_61 ( V_15 , V_56 ) ;
}
static void F_62 ( struct V_14 * V_15 , struct V_55 * V_56 )
{
struct V_61 * V_62 , * V_63 ;
unsigned long V_30 ;
if ( ! V_56 -> V_59 )
return;
F_63 ( & V_15 -> V_64 , V_30 ) ;
F_64 (e, et, &file->event_list, link) {
F_65 ( & V_62 -> V_65 ) ;
V_62 -> V_66 ( V_62 ) ;
}
F_66 ( & V_15 -> V_64 , V_30 ) ;
F_19 ( V_56 -> V_59 ) ;
V_56 -> V_59 = NULL ;
}
static void F_67 ( struct V_14 * V_15 )
{
F_68 ( V_15 ) ;
}
static int F_69 ( struct V_67 * V_15 )
{
struct V_14 * V_68 = F_70 ( V_15 ) ;
T_2 V_69 ;
if ( F_71 ( V_15 ) || ! V_68 )
return 0 ;
V_69 . V_70 = V_71 ;
return F_54 ( V_68 , V_69 ) ;
}
static int F_72 ( struct V_67 * V_15 )
{
struct V_14 * V_68 = F_70 ( V_15 ) ;
if ( F_71 ( V_15 ) || ! V_68 )
return 0 ;
return F_57 ( V_68 ) ;
}
static int F_73 ( struct V_67 * V_15 , void * V_72 )
{
return V_15 == (struct V_67 * ) V_72 ;
}
static struct V_73 * F_74 ( struct V_67 * V_15 )
{
struct V_73 * V_74 = NULL ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_75 ( V_75 ) ; ++ V_7 ) {
struct V_76 * V_77 = & V_75 [ V_7 ] -> V_78 ;
struct V_67 * V_79 = NULL , * V_80 ;
while ( ( V_80 = F_76 ( & V_81 , V_79 , V_77 ,
( void * ) V_81 . V_74 ) ) ) {
F_77 ( V_79 ) ;
F_78 ( V_15 , & V_74 , F_73 , V_80 ) ;
V_79 = V_80 ;
}
F_77 ( V_79 ) ;
}
return V_74 ? : F_79 ( - V_82 ) ;
}
static int F_80 ( struct V_67 * V_15 )
{
return F_81 ( & V_83 , F_82 ( V_15 ) ) ;
}
static void F_83 ( struct V_67 * V_15 )
{
F_84 ( F_70 ( V_15 ) ) ;
}
static int F_85 ( struct V_84 * V_85 )
{
struct V_73 * V_74 ;
V_85 -> V_15 . V_86 = F_86 ( 32 ) ;
V_83 . V_87 = F_75 ( V_88 ) ;
V_74 = F_74 ( & V_85 -> V_15 ) ;
if ( F_87 ( V_74 ) )
return F_88 ( V_74 ) ;
return F_89 ( & V_85 -> V_15 , & V_89 ,
V_74 ) ;
}
static int F_90 ( struct V_84 * V_85 )
{
F_91 ( & V_85 -> V_15 , & V_89 ) ;
return 0 ;
}
static void F_92 ( void )
{
int V_7 = V_90 ;
while ( -- V_7 >= 0 ) {
F_93 ( V_91 [ V_7 ] ) ;
V_91 [ V_7 ] = NULL ;
}
}
static int F_94 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_90 ; ++ V_7 ) {
struct V_92 * V_80 = V_93 [ V_7 ] ;
struct V_84 * V_85 =
F_95 ( V_80 -> V_78 . V_94 , - 1 ,
NULL , 0 ) ;
if ( ! F_87 ( V_85 ) ) {
V_91 [ V_7 ] = V_85 ;
continue;
}
while ( -- V_7 >= 0 ) {
F_93 ( V_91 [ V_7 ] ) ;
V_91 [ V_7 ] = NULL ;
}
return F_88 ( V_85 ) ;
}
return 0 ;
}
static void F_96 ( struct V_92 * const * V_77 ,
int V_95 )
{
while ( -- V_95 >= 0 )
F_97 ( V_77 [ V_95 ] ) ;
}
static int F_98 ( struct V_92 * const * V_77 ,
int V_95 )
{
int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_95 ; ++ V_7 ) {
V_8 = F_99 ( V_77 [ V_7 ] ) ;
if ( ! V_8 )
continue;
while ( -- V_7 >= 0 )
F_97 ( V_77 [ V_7 ] ) ;
return V_8 ;
}
return 0 ;
}
static inline int F_100 ( void )
{
return F_98 ( V_75 ,
F_75 ( V_75 ) ) ;
}
static inline int F_101 ( void )
{
return F_98 ( V_96 ,
F_75 ( V_96 ) ) ;
}
static inline void F_102 ( void )
{
F_96 ( V_75 ,
F_75 ( V_75 ) ) ;
}
static inline void F_103 ( void )
{
F_96 ( V_96 ,
F_75 ( V_96 ) ) ;
}
static int F_104 ( void )
{
int V_8 ;
V_8 = F_94 () ;
if ( V_8 )
return V_8 ;
V_8 = F_100 () ;
if ( V_8 )
goto V_97;
V_8 = F_101 () ;
if ( V_8 )
goto V_98;
return 0 ;
V_98:
F_102 () ;
V_97:
F_92 () ;
return V_8 ;
}
static void F_105 ( void )
{
F_103 () ;
F_102 () ;
F_92 () ;
}
