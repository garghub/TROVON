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
V_17 = V_15 -> V_18 ;
F_16 ( V_15 ) ;
F_17 ( V_15 ) ;
V_17 -> V_19 = F_18 ( V_15 ) ;
if ( F_19 ( V_17 -> V_19 ) ) {
F_20 ( V_15 ) ;
F_21 ( V_15 ) ;
return F_22 ( V_17 -> V_19 ) ;
}
return 0 ;
}
static int F_23 ( struct V_14 * V_2 )
{
struct V_1 * V_15 = F_14 ( V_2 ) ;
struct V_16 * V_17 ;
if ( F_15 ( V_2 ) || ! V_15 )
return 0 ;
V_17 = V_15 -> V_18 ;
F_24 ( V_15 , V_17 -> V_19 ) ;
F_20 ( V_15 ) ;
F_21 ( V_15 ) ;
return 0 ;
}
static int F_25 ( struct V_14 * V_2 , void * V_20 )
{
return V_2 == (struct V_14 * ) V_20 ;
}
static struct V_21 * F_26 ( struct V_14 * V_2 )
{
struct V_21 * V_22 = NULL ;
int V_23 ;
for ( V_23 = 0 ; V_23 < F_27 ( V_24 ) ; ++ V_23 ) {
struct V_25 * V_26 = & V_24 [ V_23 ] ;
struct V_14 * V_27 = NULL , * V_28 ;
if ( ! V_26 -> V_29 || ! ( V_26 -> V_30 & V_31 ) )
continue;
while ( ( V_28 = F_28 ( & V_32 , V_27 ,
& V_26 -> V_29 -> V_29 ,
( void * ) V_32 . V_22 ) ) ) {
F_29 ( V_27 ) ;
F_30 ( V_2 , & V_22 , F_25 , V_28 ) ;
V_27 = V_28 ;
}
F_29 ( V_27 ) ;
}
return V_22 ? : F_31 ( - V_33 ) ;
}
static int F_32 ( struct V_14 * V_2 )
{
struct V_16 * V_17 ;
struct V_34 * V_35 ;
struct V_1 * V_36 ;
unsigned int V_37 ;
int V_38 , V_5 ;
V_36 = F_33 ( & V_39 , V_2 ) ;
if ( F_19 ( V_36 ) )
return F_22 ( V_36 ) ;
V_17 = F_6 ( sizeof( struct V_16 ) , V_10 ) ;
if ( ! V_17 ) {
V_5 = - V_11 ;
goto V_40;
}
F_34 ( & V_17 -> V_41 ) ;
F_35 ( & V_17 -> V_42 ) ;
F_36 ( V_2 , V_36 ) ;
V_36 -> V_18 = ( void * ) V_17 ;
V_17 -> V_43 = F_37 () ;
if ( ! V_17 -> V_43 ) {
F_38 ( L_1 ) ;
V_5 = - V_33 ;
goto V_44;
}
F_39 ( L_2 ,
F_40 ( V_17 -> V_43 ) ) ;
V_5 = F_41 ( V_36 ) ;
if ( V_5 < 0 ) {
F_38 ( L_3 ) ;
goto V_44;
}
F_42 ( V_36 ) ;
F_43 ( V_36 ) ;
V_38 = 0 ;
V_37 = 0 ;
F_44 (encoder, &drm->mode_config.encoder_list, head)
V_37 |= ( 1 << ( V_38 ++ ) ) ;
F_44 (encoder, &drm->mode_config.encoder_list, head)
V_35 -> V_45 = V_37 ;
V_5 = F_45 ( V_36 -> V_2 , V_36 ) ;
if ( V_5 )
goto V_46;
V_5 = F_46 ( V_36 , V_36 -> V_47 . V_48 ) ;
if ( V_5 )
goto V_49;
V_5 = F_47 ( V_36 ) ;
if ( V_5 )
goto V_49;
F_48 ( V_36 ) ;
V_36 -> V_50 = true ;
F_49 ( V_36 ) ;
V_5 = F_50 ( V_36 ) ;
if ( V_5 )
goto V_51;
V_5 = F_51 ( V_36 , 0 ) ;
if ( V_5 < 0 )
goto V_52;
return 0 ;
V_52:
F_52 ( V_36 ) ;
V_51:
F_53 ( V_36 ) ;
F_54 ( V_36 ) ;
V_49:
F_55 ( V_36 -> V_2 , V_36 ) ;
V_46:
F_56 ( V_36 ) ;
F_57 ( V_36 ) ;
V_44:
F_8 ( V_17 ) ;
V_40:
F_58 ( V_36 ) ;
return V_5 ;
}
static void F_59 ( struct V_14 * V_2 )
{
struct V_1 * V_36 = F_14 ( V_2 ) ;
F_60 ( V_36 ) ;
F_54 ( V_36 ) ;
F_52 ( V_36 ) ;
F_53 ( V_36 ) ;
F_55 ( V_36 -> V_2 , V_36 ) ;
F_56 ( V_36 ) ;
F_57 ( V_36 ) ;
F_8 ( V_36 -> V_18 ) ;
V_36 -> V_18 = NULL ;
F_36 ( V_2 , NULL ) ;
F_58 ( V_36 ) ;
}
static int F_61 ( struct V_53 * V_54 )
{
struct V_21 * V_22 ;
V_54 -> V_2 . V_55 = F_62 ( 32 ) ;
V_22 = F_26 ( & V_54 -> V_2 ) ;
if ( F_19 ( V_22 ) )
return F_22 ( V_22 ) ;
return F_63 ( & V_54 -> V_2 , & V_56 ,
V_22 ) ;
}
static int F_64 ( struct V_53 * V_54 )
{
F_65 ( & V_54 -> V_2 , & V_56 ) ;
return 0 ;
}
static struct V_14 * F_37 ( void )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_27 ( V_24 ) ; ++ V_23 ) {
struct V_25 * V_26 = & V_24 [ V_23 ] ;
struct V_14 * V_2 ;
if ( ! V_26 -> V_29 || ! ( V_26 -> V_30 & V_57 ) )
continue;
while ( ( V_2 = F_28 ( & V_32 , NULL ,
& V_26 -> V_29 -> V_29 ,
( void * ) V_32 . V_22 ) ) ) {
F_29 ( V_2 ) ;
return V_2 ;
}
}
return NULL ;
}
static void F_66 ( void )
{
int V_23 ;
for ( V_23 = F_27 ( V_24 ) - 1 ; V_23 >= 0 ; -- V_23 ) {
struct V_25 * V_26 = & V_24 [ V_23 ] ;
struct V_14 * V_2 ;
if ( ! V_26 -> V_29 || ! ( V_26 -> V_30 & V_58 ) )
continue;
while ( ( V_2 = F_28 ( & V_32 , NULL ,
& V_26 -> V_29 -> V_29 ,
( void * ) V_32 . V_22 ) ) ) {
F_29 ( V_2 ) ;
F_67 ( F_68 ( V_2 ) ) ;
}
}
}
static int F_69 ( void )
{
struct V_53 * V_54 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < F_27 ( V_24 ) ; ++ V_23 ) {
struct V_25 * V_26 = & V_24 [ V_23 ] ;
if ( ! V_26 -> V_29 || ! ( V_26 -> V_30 & V_58 ) )
continue;
V_54 = F_70 (
V_26 -> V_29 -> V_29 . V_59 , - 1 , NULL , 0 ) ;
if ( F_19 ( V_54 ) )
goto V_60;
}
return 0 ;
V_60:
F_66 () ;
return F_22 ( V_54 ) ;
}
static void F_71 ( void )
{
int V_23 ;
for ( V_23 = F_27 ( V_24 ) - 1 ; V_23 >= 0 ; -- V_23 ) {
struct V_25 * V_26 = & V_24 [ V_23 ] ;
if ( ! V_26 -> V_29 )
continue;
F_72 ( V_26 -> V_29 ) ;
}
}
static int F_73 ( void )
{
int V_23 , V_5 ;
for ( V_23 = 0 ; V_23 < F_27 ( V_24 ) ; ++ V_23 ) {
struct V_25 * V_26 = & V_24 [ V_23 ] ;
if ( ! V_26 -> V_29 )
continue;
V_5 = F_74 ( V_26 -> V_29 ) ;
if ( V_5 )
goto V_60;
}
return 0 ;
V_60:
F_71 () ;
return V_5 ;
}
static int F_75 ( void )
{
int V_5 ;
V_5 = F_69 () ;
if ( V_5 )
return V_5 ;
V_5 = F_73 () ;
if ( V_5 )
goto V_61;
return 0 ;
V_61:
F_66 () ;
return V_5 ;
}
static void F_76 ( void )
{
F_71 () ;
F_66 () ;
}
