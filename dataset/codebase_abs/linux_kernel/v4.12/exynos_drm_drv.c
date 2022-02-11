int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_3 ( V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_2 , V_4 ) ;
if ( V_5 )
return V_5 ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_5 ;
V_9 = F_6 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
V_7 -> V_12 = V_9 ;
V_5 = F_7 ( V_2 , V_7 ) ;
if ( V_5 )
goto V_13;
return V_5 ;
V_13:
F_8 ( V_9 ) ;
V_7 -> V_12 = NULL ;
return V_5 ;
}
static void F_9 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
F_10 ( V_2 , V_7 ) ;
F_8 ( V_7 -> V_12 ) ;
V_7 -> V_12 = NULL ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
static int F_13 ( struct V_14 * V_2 )
{
struct V_1 * V_15 = F_14 ( V_2 ) ;
struct V_16 * V_17 ;
if ( F_15 ( V_2 ) || ! V_15 )
return 0 ;
F_16 ( V_15 ) ;
F_17 (connector, drm_dev) {
int V_18 = V_17 -> V_19 ;
if ( V_17 -> V_20 -> V_19 )
V_17 -> V_20 -> V_19 ( V_17 , V_21 ) ;
V_17 -> V_19 = V_18 ;
}
F_18 ( V_15 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_2 )
{
struct V_1 * V_15 = F_14 ( V_2 ) ;
struct V_16 * V_17 ;
if ( F_15 ( V_2 ) || ! V_15 )
return 0 ;
F_16 ( V_15 ) ;
F_17 (connector, drm_dev) {
if ( V_17 -> V_20 -> V_19 ) {
int V_19 = V_17 -> V_19 ;
V_17 -> V_19 = V_21 ;
V_17 -> V_20 -> V_19 ( V_17 , V_19 ) ;
}
}
F_18 ( V_15 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_2 , void * V_22 )
{
return V_2 == (struct V_14 * ) V_22 ;
}
static struct V_23 * F_21 ( struct V_14 * V_2 )
{
struct V_23 * V_24 = NULL ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_22 ( V_26 ) ; ++ V_25 ) {
struct V_27 * V_28 = & V_26 [ V_25 ] ;
struct V_14 * V_29 = NULL , * V_30 ;
if ( ! V_28 -> V_31 || ! ( V_28 -> V_32 & V_33 ) )
continue;
while ( ( V_30 = F_23 ( & V_34 , V_29 ,
& V_28 -> V_31 -> V_31 ,
( void * ) V_34 . V_24 ) ) ) {
F_24 ( V_29 ) ;
F_25 ( V_2 , & V_24 , F_20 , V_30 ) ;
V_29 = V_30 ;
}
F_24 ( V_29 ) ;
}
return V_24 ? : F_26 ( - V_35 ) ;
}
static int F_27 ( struct V_14 * V_2 )
{
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_1 * V_40 ;
unsigned int V_41 ;
int V_42 , V_5 ;
V_40 = F_28 ( & V_43 , V_2 ) ;
if ( F_29 ( V_40 ) )
return F_30 ( V_40 ) ;
V_37 = F_6 ( sizeof( struct V_36 ) , V_10 ) ;
if ( ! V_37 ) {
V_5 = - V_11 ;
goto V_44;
}
F_31 ( & V_37 -> V_45 ) ;
F_32 ( & V_37 -> V_46 ) ;
F_33 ( V_2 , V_40 ) ;
V_40 -> V_47 = ( void * ) V_37 ;
V_37 -> V_48 = F_34 () ;
if ( ! V_37 -> V_48 ) {
F_35 ( L_1 ) ;
V_5 = - V_35 ;
goto V_49;
}
F_36 ( L_2 ,
F_37 ( V_37 -> V_48 ) ) ;
V_5 = F_38 ( V_40 ) ;
if ( V_5 < 0 ) {
F_35 ( L_3 ) ;
goto V_49;
}
F_39 ( V_40 ) ;
F_40 ( V_40 ) ;
V_42 = 0 ;
V_41 = 0 ;
F_41 (encoder, &drm->mode_config.encoder_list, head)
V_41 |= ( 1 << ( V_42 ++ ) ) ;
F_41 (encoder, &drm->mode_config.encoder_list, head)
V_39 -> V_50 = V_41 ;
V_5 = F_42 ( V_40 -> V_2 , V_40 ) ;
if ( V_5 )
goto V_51;
V_5 = F_43 ( V_40 , V_40 -> V_52 . V_53 ) ;
if ( V_5 )
goto V_54;
V_5 = F_44 ( V_40 ) ;
if ( V_5 )
goto V_55;
F_45 ( V_40 ) ;
V_40 -> V_56 = true ;
F_46 ( V_40 ) ;
F_47 ( V_40 ) ;
V_5 = F_48 ( V_40 , 0 ) ;
if ( V_5 < 0 )
goto V_57;
return 0 ;
V_57:
F_49 ( V_40 ) ;
F_50 ( V_40 ) ;
F_51 ( V_40 ) ;
V_55:
F_52 ( V_40 ) ;
V_54:
F_53 ( V_40 -> V_2 , V_40 ) ;
V_51:
F_54 ( V_40 ) ;
F_55 ( V_40 ) ;
V_49:
F_8 ( V_37 ) ;
V_44:
F_56 ( V_40 ) ;
return V_5 ;
}
static void F_57 ( struct V_14 * V_2 )
{
struct V_1 * V_40 = F_14 ( V_2 ) ;
F_58 ( V_40 ) ;
F_51 ( V_40 ) ;
F_49 ( V_40 ) ;
F_50 ( V_40 ) ;
F_53 ( V_40 -> V_2 , V_40 ) ;
F_54 ( V_40 ) ;
F_55 ( V_40 ) ;
F_8 ( V_40 -> V_47 ) ;
V_40 -> V_47 = NULL ;
F_56 ( V_40 ) ;
}
static int F_59 ( struct V_58 * V_59 )
{
struct V_23 * V_24 ;
V_59 -> V_2 . V_60 = F_60 ( 32 ) ;
V_43 . V_61 = F_22 ( V_62 ) ;
V_24 = F_21 ( & V_59 -> V_2 ) ;
if ( F_29 ( V_24 ) )
return F_30 ( V_24 ) ;
return F_61 ( & V_59 -> V_2 , & V_63 ,
V_24 ) ;
}
static int F_62 ( struct V_58 * V_59 )
{
F_63 ( & V_59 -> V_2 , & V_63 ) ;
return 0 ;
}
static struct V_14 * F_34 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < F_22 ( V_26 ) ; ++ V_25 ) {
struct V_27 * V_28 = & V_26 [ V_25 ] ;
struct V_14 * V_2 ;
if ( ! V_28 -> V_31 || ! ( V_28 -> V_32 & V_64 ) )
continue;
while ( ( V_2 = F_23 ( & V_34 , NULL ,
& V_28 -> V_31 -> V_31 ,
( void * ) V_34 . V_24 ) ) ) {
F_24 ( V_2 ) ;
return V_2 ;
}
}
return NULL ;
}
static void F_64 ( void )
{
int V_25 ;
for ( V_25 = F_22 ( V_26 ) - 1 ; V_25 >= 0 ; -- V_25 ) {
struct V_27 * V_28 = & V_26 [ V_25 ] ;
struct V_14 * V_2 ;
if ( ! V_28 -> V_31 || ! ( V_28 -> V_32 & V_65 ) )
continue;
while ( ( V_2 = F_23 ( & V_34 , NULL ,
& V_28 -> V_31 -> V_31 ,
( void * ) V_34 . V_24 ) ) ) {
F_24 ( V_2 ) ;
F_65 ( F_66 ( V_2 ) ) ;
}
}
}
static int F_67 ( void )
{
struct V_58 * V_59 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_22 ( V_26 ) ; ++ V_25 ) {
struct V_27 * V_28 = & V_26 [ V_25 ] ;
if ( ! V_28 -> V_31 || ! ( V_28 -> V_32 & V_65 ) )
continue;
V_59 = F_68 (
V_28 -> V_31 -> V_31 . V_66 , - 1 , NULL , 0 ) ;
if ( F_29 ( V_59 ) )
goto V_67;
}
return 0 ;
V_67:
F_64 () ;
return F_30 ( V_59 ) ;
}
static void F_69 ( void )
{
int V_25 ;
for ( V_25 = F_22 ( V_26 ) - 1 ; V_25 >= 0 ; -- V_25 ) {
struct V_27 * V_28 = & V_26 [ V_25 ] ;
if ( ! V_28 -> V_31 )
continue;
F_70 ( V_28 -> V_31 ) ;
}
}
static int F_71 ( void )
{
int V_25 , V_5 ;
for ( V_25 = 0 ; V_25 < F_22 ( V_26 ) ; ++ V_25 ) {
struct V_27 * V_28 = & V_26 [ V_25 ] ;
if ( ! V_28 -> V_31 )
continue;
V_5 = F_72 ( V_28 -> V_31 ) ;
if ( V_5 )
goto V_67;
}
return 0 ;
V_67:
F_69 () ;
return V_5 ;
}
static int F_73 ( void )
{
int V_5 ;
V_5 = F_67 () ;
if ( V_5 )
return V_5 ;
V_5 = F_71 () ;
if ( V_5 )
goto V_68;
return 0 ;
V_68:
F_64 () ;
return V_5 ;
}
static void F_74 ( void )
{
F_69 () ;
F_64 () ;
}
