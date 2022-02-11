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
struct V_18 V_19 ;
if ( F_15 ( V_2 ) || ! V_15 )
return 0 ;
F_16 ( V_15 , & V_19 ) ;
F_17 (connector, &conn_iter) {
int V_20 = V_17 -> V_21 ;
if ( V_17 -> V_22 -> V_21 )
V_17 -> V_22 -> V_21 ( V_17 , V_23 ) ;
V_17 -> V_21 = V_20 ;
}
F_18 ( & V_19 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_2 )
{
struct V_1 * V_15 = F_14 ( V_2 ) ;
struct V_16 * V_17 ;
struct V_18 V_19 ;
if ( F_15 ( V_2 ) || ! V_15 )
return 0 ;
F_16 ( V_15 , & V_19 ) ;
F_17 (connector, &conn_iter) {
if ( V_17 -> V_22 -> V_21 ) {
int V_21 = V_17 -> V_21 ;
V_17 -> V_21 = V_23 ;
V_17 -> V_22 -> V_21 ( V_17 , V_21 ) ;
}
}
F_18 ( & V_19 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_2 , void * V_24 )
{
return V_2 == (struct V_14 * ) V_24 ;
}
static struct V_25 * F_21 ( struct V_14 * V_2 )
{
struct V_25 * V_26 = NULL ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_22 ( V_28 ) ; ++ V_27 ) {
struct V_29 * V_30 = & V_28 [ V_27 ] ;
struct V_14 * V_31 = NULL , * V_32 ;
if ( ! V_30 -> V_33 || ! ( V_30 -> V_34 & V_35 ) )
continue;
while ( ( V_32 = F_23 ( & V_36 , V_31 ,
& V_30 -> V_33 -> V_33 ,
( void * ) V_36 . V_26 ) ) ) {
F_24 ( V_31 ) ;
F_25 ( V_2 , & V_26 , F_20 , V_32 ) ;
V_31 = V_32 ;
}
F_24 ( V_31 ) ;
}
return V_26 ? : F_26 ( - V_37 ) ;
}
static int F_27 ( struct V_14 * V_2 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_1 * V_42 ;
unsigned int V_43 ;
int V_44 , V_5 ;
V_42 = F_28 ( & V_45 , V_2 ) ;
if ( F_29 ( V_42 ) )
return F_30 ( V_42 ) ;
V_39 = F_6 ( sizeof( struct V_38 ) , V_10 ) ;
if ( ! V_39 ) {
V_5 = - V_11 ;
goto V_46;
}
F_31 ( & V_39 -> V_47 ) ;
F_32 ( & V_39 -> V_48 ) ;
F_33 ( V_2 , V_42 ) ;
V_42 -> V_49 = ( void * ) V_39 ;
V_39 -> V_50 = F_34 () ;
if ( ! V_39 -> V_50 ) {
F_35 ( L_1 ) ;
V_5 = - V_37 ;
goto V_51;
}
F_36 ( L_2 ,
F_37 ( V_39 -> V_50 ) ) ;
V_5 = F_38 ( V_42 ) ;
if ( V_5 < 0 ) {
F_35 ( L_3 ) ;
goto V_51;
}
F_39 ( V_42 ) ;
F_40 ( V_42 ) ;
V_44 = 0 ;
V_43 = 0 ;
F_41 (encoder, &drm->mode_config.encoder_list, head)
V_43 |= ( 1 << ( V_44 ++ ) ) ;
F_41 (encoder, &drm->mode_config.encoder_list, head)
V_41 -> V_52 = V_43 ;
V_5 = F_42 ( V_42 -> V_2 , V_42 ) ;
if ( V_5 )
goto V_53;
V_5 = F_43 ( V_42 , V_42 -> V_54 . V_55 ) ;
if ( V_5 )
goto V_56;
V_5 = F_44 ( V_42 ) ;
if ( V_5 )
goto V_56;
F_45 ( V_42 ) ;
V_42 -> V_57 = true ;
F_46 ( V_42 ) ;
F_47 ( V_42 ) ;
V_5 = F_48 ( V_42 , 0 ) ;
if ( V_5 < 0 )
goto V_58;
return 0 ;
V_58:
F_49 ( V_42 ) ;
F_50 ( V_42 ) ;
F_51 ( V_42 ) ;
V_56:
F_52 ( V_42 -> V_2 , V_42 ) ;
V_53:
F_53 ( V_42 ) ;
F_54 ( V_42 ) ;
V_51:
F_8 ( V_39 ) ;
V_46:
F_55 ( V_42 ) ;
return V_5 ;
}
static void F_56 ( struct V_14 * V_2 )
{
struct V_1 * V_42 = F_14 ( V_2 ) ;
F_57 ( V_42 ) ;
F_51 ( V_42 ) ;
F_49 ( V_42 ) ;
F_50 ( V_42 ) ;
F_52 ( V_42 -> V_2 , V_42 ) ;
F_53 ( V_42 ) ;
F_54 ( V_42 ) ;
F_8 ( V_42 -> V_49 ) ;
V_42 -> V_49 = NULL ;
F_55 ( V_42 ) ;
}
static int F_58 ( struct V_59 * V_60 )
{
struct V_25 * V_26 ;
V_60 -> V_2 . V_61 = F_59 ( 32 ) ;
V_26 = F_21 ( & V_60 -> V_2 ) ;
if ( F_29 ( V_26 ) )
return F_30 ( V_26 ) ;
return F_60 ( & V_60 -> V_2 , & V_62 ,
V_26 ) ;
}
static int F_61 ( struct V_59 * V_60 )
{
F_62 ( & V_60 -> V_2 , & V_62 ) ;
return 0 ;
}
static struct V_14 * F_34 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < F_22 ( V_28 ) ; ++ V_27 ) {
struct V_29 * V_30 = & V_28 [ V_27 ] ;
struct V_14 * V_2 ;
if ( ! V_30 -> V_33 || ! ( V_30 -> V_34 & V_63 ) )
continue;
while ( ( V_2 = F_23 ( & V_36 , NULL ,
& V_30 -> V_33 -> V_33 ,
( void * ) V_36 . V_26 ) ) ) {
F_24 ( V_2 ) ;
return V_2 ;
}
}
return NULL ;
}
static void F_63 ( void )
{
int V_27 ;
for ( V_27 = F_22 ( V_28 ) - 1 ; V_27 >= 0 ; -- V_27 ) {
struct V_29 * V_30 = & V_28 [ V_27 ] ;
struct V_14 * V_2 ;
if ( ! V_30 -> V_33 || ! ( V_30 -> V_34 & V_64 ) )
continue;
while ( ( V_2 = F_23 ( & V_36 , NULL ,
& V_30 -> V_33 -> V_33 ,
( void * ) V_36 . V_26 ) ) ) {
F_24 ( V_2 ) ;
F_64 ( F_65 ( V_2 ) ) ;
}
}
}
static int F_66 ( void )
{
struct V_59 * V_60 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_22 ( V_28 ) ; ++ V_27 ) {
struct V_29 * V_30 = & V_28 [ V_27 ] ;
if ( ! V_30 -> V_33 || ! ( V_30 -> V_34 & V_64 ) )
continue;
V_60 = F_67 (
V_30 -> V_33 -> V_33 . V_65 , - 1 , NULL , 0 ) ;
if ( F_29 ( V_60 ) )
goto V_66;
}
return 0 ;
V_66:
F_63 () ;
return F_30 ( V_60 ) ;
}
static void F_68 ( void )
{
int V_27 ;
for ( V_27 = F_22 ( V_28 ) - 1 ; V_27 >= 0 ; -- V_27 ) {
struct V_29 * V_30 = & V_28 [ V_27 ] ;
if ( ! V_30 -> V_33 )
continue;
F_69 ( V_30 -> V_33 ) ;
}
}
static int F_70 ( void )
{
int V_27 , V_5 ;
for ( V_27 = 0 ; V_27 < F_22 ( V_28 ) ; ++ V_27 ) {
struct V_29 * V_30 = & V_28 [ V_27 ] ;
if ( ! V_30 -> V_33 )
continue;
V_5 = F_71 ( V_30 -> V_33 ) ;
if ( V_5 )
goto V_66;
}
return 0 ;
V_66:
F_68 () ;
return V_5 ;
}
static int F_72 ( void )
{
int V_5 ;
V_5 = F_66 () ;
if ( V_5 )
return V_5 ;
V_5 = F_70 () ;
if ( V_5 )
goto V_67;
return 0 ;
V_67:
F_63 () ;
return V_5 ;
}
static void F_73 ( void )
{
F_68 () ;
F_63 () ;
}
