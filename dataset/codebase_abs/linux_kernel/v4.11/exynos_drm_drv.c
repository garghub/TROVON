static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
unsigned int V_8 ;
int V_9 , V_10 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_11 ) ;
if ( ! V_5 )
return - V_12 ;
F_3 ( & V_5 -> V_13 ) ;
F_4 ( & V_5 -> V_14 ) ;
F_5 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_15 = ( void * ) V_5 ;
V_5 -> V_16 = F_6 () ;
if ( ! V_5 -> V_16 ) {
F_7 ( L_1 ) ;
V_10 = - V_17 ;
goto V_18;
}
F_8 ( L_2 ,
F_9 ( V_5 -> V_16 ) ) ;
V_10 = F_10 ( V_2 ) ;
if ( V_10 < 0 ) {
F_7 ( L_3 ) ;
goto V_18;
}
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
V_9 = 0 ;
V_8 = 0 ;
F_13 (encoder, &dev->mode_config.encoder_list, head)
V_8 |= ( 1 << ( V_9 ++ ) ) ;
F_13 (encoder, &dev->mode_config.encoder_list, head)
V_7 -> V_19 = V_8 ;
F_14 ( V_2 -> V_20 , V_2 ) ;
V_10 = F_15 ( V_2 -> V_2 , V_2 ) ;
if ( V_10 )
goto V_21;
V_10 = F_16 ( V_2 , V_2 -> V_22 . V_23 ) ;
if ( V_10 )
goto V_24;
V_10 = F_17 ( V_2 ) ;
if ( V_10 )
goto V_25;
F_18 ( V_2 ) ;
V_2 -> V_26 = true ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
return 0 ;
V_25:
F_21 ( V_2 ) ;
V_24:
F_22 ( V_2 -> V_2 , V_2 ) ;
V_21:
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
V_18:
F_25 ( V_5 ) ;
return V_10 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 -> V_2 , V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
int V_10 ;
V_10 = F_31 ( V_2 , V_28 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_32 ( V_2 , V_28 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_33 ( V_2 , V_28 ) ;
if ( V_10 )
return V_10 ;
return V_10 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
struct V_31 * V_32 ;
int V_10 ;
V_32 = F_2 ( sizeof( * V_32 ) , V_11 ) ;
if ( ! V_32 )
return - V_12 ;
V_30 -> V_33 = V_32 ;
V_10 = F_35 ( V_2 , V_30 ) ;
if ( V_10 )
goto V_34;
return V_10 ;
V_34:
F_25 ( V_32 ) ;
V_30 -> V_33 = NULL ;
return V_10 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
F_37 ( V_2 , V_30 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
F_25 ( V_30 -> V_33 ) ;
V_30 -> V_33 = NULL ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_35 * V_2 )
{
struct V_1 * V_36 = F_42 ( V_2 ) ;
struct V_37 * V_38 ;
if ( F_43 ( V_2 ) || ! V_36 )
return 0 ;
F_44 ( V_36 ) ;
F_45 (connector, drm_dev) {
int V_39 = V_38 -> V_40 ;
if ( V_38 -> V_41 -> V_40 )
V_38 -> V_41 -> V_40 ( V_38 , V_42 ) ;
V_38 -> V_40 = V_39 ;
}
F_46 ( V_36 ) ;
return 0 ;
}
static int F_47 ( struct V_35 * V_2 )
{
struct V_1 * V_36 = F_42 ( V_2 ) ;
struct V_37 * V_38 ;
if ( F_43 ( V_2 ) || ! V_36 )
return 0 ;
F_44 ( V_36 ) ;
F_45 (connector, drm_dev) {
if ( V_38 -> V_41 -> V_40 ) {
int V_40 = V_38 -> V_40 ;
V_38 -> V_40 = V_42 ;
V_38 -> V_41 -> V_40 ( V_38 , V_40 ) ;
}
}
F_46 ( V_36 ) ;
return 0 ;
}
static int F_48 ( struct V_35 * V_2 , void * V_43 )
{
return V_2 == (struct V_35 * ) V_43 ;
}
static struct V_44 * F_49 ( struct V_35 * V_2 )
{
struct V_44 * V_45 = NULL ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_50 ( V_47 ) ; ++ V_46 ) {
struct V_48 * V_49 = & V_47 [ V_46 ] ;
struct V_35 * V_50 = NULL , * V_51 ;
if ( ! V_49 -> V_52 || ! ( V_49 -> V_3 & V_53 ) )
continue;
while ( ( V_51 = F_51 ( & V_54 , V_50 ,
& V_49 -> V_52 -> V_52 ,
( void * ) V_54 . V_45 ) ) ) {
F_52 ( V_50 ) ;
F_53 ( V_2 , & V_45 , F_48 , V_51 ) ;
V_50 = V_51 ;
}
F_52 ( V_50 ) ;
}
return V_45 ? : F_54 ( - V_17 ) ;
}
static int F_55 ( struct V_35 * V_2 )
{
return F_56 ( & V_55 , F_57 ( V_2 ) ) ;
}
static void F_58 ( struct V_35 * V_2 )
{
F_59 ( F_42 ( V_2 ) ) ;
}
static int F_60 ( struct V_56 * V_57 )
{
struct V_44 * V_45 ;
V_57 -> V_2 . V_58 = F_61 ( 32 ) ;
V_55 . V_59 = F_50 ( V_60 ) ;
V_45 = F_49 ( & V_57 -> V_2 ) ;
if ( F_62 ( V_45 ) )
return F_63 ( V_45 ) ;
return F_64 ( & V_57 -> V_2 , & V_61 ,
V_45 ) ;
}
static int F_65 ( struct V_56 * V_57 )
{
F_66 ( & V_57 -> V_2 , & V_61 ) ;
return 0 ;
}
static struct V_35 * F_6 ( void )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < F_50 ( V_47 ) ; ++ V_46 ) {
struct V_48 * V_49 = & V_47 [ V_46 ] ;
struct V_35 * V_2 ;
if ( ! V_49 -> V_52 || ! ( V_49 -> V_3 & V_62 ) )
continue;
while ( ( V_2 = F_51 ( & V_54 , NULL ,
& V_49 -> V_52 -> V_52 ,
( void * ) V_54 . V_45 ) ) ) {
F_52 ( V_2 ) ;
return V_2 ;
}
}
return NULL ;
}
static void F_67 ( void )
{
int V_46 ;
for ( V_46 = F_50 ( V_47 ) - 1 ; V_46 >= 0 ; -- V_46 ) {
struct V_48 * V_49 = & V_47 [ V_46 ] ;
struct V_35 * V_2 ;
if ( ! V_49 -> V_52 || ! ( V_49 -> V_3 & V_63 ) )
continue;
while ( ( V_2 = F_51 ( & V_54 , NULL ,
& V_49 -> V_52 -> V_52 ,
( void * ) V_54 . V_45 ) ) ) {
F_52 ( V_2 ) ;
F_68 ( F_57 ( V_2 ) ) ;
}
}
}
static int F_69 ( void )
{
struct V_56 * V_57 ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_50 ( V_47 ) ; ++ V_46 ) {
struct V_48 * V_49 = & V_47 [ V_46 ] ;
if ( ! V_49 -> V_52 || ! ( V_49 -> V_3 & V_63 ) )
continue;
V_57 = F_70 (
V_49 -> V_52 -> V_52 . V_64 , - 1 , NULL , 0 ) ;
if ( F_62 ( V_57 ) )
goto V_65;
}
return 0 ;
V_65:
F_67 () ;
return F_63 ( V_57 ) ;
}
static void F_71 ( void )
{
int V_46 ;
for ( V_46 = F_50 ( V_47 ) - 1 ; V_46 >= 0 ; -- V_46 ) {
struct V_48 * V_49 = & V_47 [ V_46 ] ;
if ( ! V_49 -> V_52 )
continue;
F_72 ( V_49 -> V_52 ) ;
}
}
static int F_73 ( void )
{
int V_46 , V_10 ;
for ( V_46 = 0 ; V_46 < F_50 ( V_47 ) ; ++ V_46 ) {
struct V_48 * V_49 = & V_47 [ V_46 ] ;
if ( ! V_49 -> V_52 )
continue;
V_10 = F_74 ( V_49 -> V_52 ) ;
if ( V_10 )
goto V_65;
}
return 0 ;
V_65:
F_71 () ;
return V_10 ;
}
static int F_75 ( void )
{
int V_10 ;
V_10 = F_69 () ;
if ( V_10 )
return V_10 ;
V_10 = F_73 () ;
if ( V_10 )
goto V_66;
return 0 ;
V_66:
F_67 () ;
return V_10 ;
}
static void F_76 ( void )
{
F_71 () ;
F_67 () ;
}
