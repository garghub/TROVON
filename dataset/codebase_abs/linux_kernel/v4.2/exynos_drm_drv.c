static int F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_2 ( sizeof( struct V_4 ) , V_7 ) ;
if ( ! V_5 )
return - V_8 ;
F_3 ( V_2 -> V_2 , V_2 ) ;
V_2 -> V_9 = ( void * ) V_5 ;
V_6 = F_4 ( V_2 ) ;
if ( V_6 < 0 ) {
F_5 ( L_1 ) ;
goto V_10;
}
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( V_2 -> V_11 , V_2 ) ;
V_6 = F_10 ( V_2 -> V_2 , V_2 ) ;
if ( V_6 )
goto V_12;
V_6 = F_11 ( V_2 , V_2 -> V_13 . V_14 ) ;
if ( V_6 )
goto V_15;
V_6 = F_12 ( V_2 ) ;
if ( V_6 )
goto V_16;
F_13 ( V_2 ) ;
V_2 -> V_17 = true ;
V_2 -> V_18 = true ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
return 0 ;
V_16:
F_16 ( V_2 ) ;
V_15:
F_17 ( V_2 -> V_2 , V_2 ) ;
V_12:
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
V_10:
F_20 ( V_5 ) ;
return V_6 ;
}
static int F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 -> V_2 , V_2 ) ;
F_18 ( V_2 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_20 * V_21 ;
F_26 ( V_2 ) ;
F_27 (connector, &dev->mode_config.connector_list, head) {
int V_22 = V_21 -> V_23 ;
if ( V_21 -> V_24 -> V_23 )
V_21 -> V_24 -> V_23 ( V_21 , V_25 ) ;
V_21 -> V_23 = V_22 ;
}
F_28 ( V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
F_26 ( V_2 ) ;
F_27 (connector, &dev->mode_config.connector_list, head) {
if ( V_21 -> V_24 -> V_23 ) {
int V_23 = V_21 -> V_23 ;
V_21 -> V_23 = V_25 ;
V_21 -> V_24 -> V_23 ( V_21 , V_23 ) ;
}
}
F_28 ( V_2 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_28 * V_29 ;
int V_6 ;
V_29 = F_2 ( sizeof( * V_29 ) , V_7 ) ;
if ( ! V_29 )
return - V_8 ;
V_27 -> V_30 = V_29 ;
V_6 = F_31 ( V_2 , V_27 ) ;
if ( V_6 )
goto V_31;
return V_6 ;
V_31:
F_20 ( V_29 ) ;
V_27 -> V_30 = NULL ;
return V_6 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
F_33 ( V_2 , V_27 ) ;
}
static void F_34 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
struct V_32 * V_33 , * V_34 ;
unsigned long V_3 ;
if ( ! V_27 -> V_30 )
return;
F_35 ( & V_2 -> V_35 , V_3 ) ;
F_36 (e, et, &file->event_list, link) {
F_37 ( & V_33 -> V_36 ) ;
V_33 -> V_37 ( V_33 ) ;
}
F_38 ( & V_2 -> V_35 , V_3 ) ;
F_20 ( V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
}
static int F_41 ( struct V_38 * V_2 )
{
struct V_1 * V_39 = F_42 ( V_2 ) ;
T_1 V_40 ;
if ( F_43 ( V_2 ) || ! V_39 )
return 0 ;
V_40 . V_41 = V_42 ;
return F_25 ( V_39 , V_40 ) ;
}
static int F_44 ( struct V_38 * V_2 )
{
struct V_1 * V_39 = F_42 ( V_2 ) ;
if ( F_43 ( V_2 ) || ! V_39 )
return 0 ;
return F_29 ( V_39 ) ;
}
static int F_45 ( struct V_38 * V_2 , void * V_43 )
{
return V_2 == (struct V_38 * ) V_43 ;
}
static struct V_44 * F_46 ( struct V_38 * V_2 )
{
struct V_44 * V_45 = NULL ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_47 ( V_47 ) ; ++ V_46 ) {
struct V_48 * V_49 = & V_47 [ V_46 ] -> V_50 ;
struct V_38 * V_51 = NULL , * V_52 ;
while ( ( V_52 = F_48 ( & V_53 , V_51 , V_49 ,
( void * ) V_53 . V_45 ) ) ) {
F_49 ( V_51 ) ;
F_50 ( V_2 , & V_45 , F_45 , V_52 ) ;
V_51 = V_52 ;
}
F_49 ( V_51 ) ;
}
return V_45 ? : F_51 ( - V_54 ) ;
}
static int F_52 ( struct V_38 * V_2 )
{
return F_53 ( & V_55 , F_54 ( V_2 ) ) ;
}
static void F_55 ( struct V_38 * V_2 )
{
F_56 ( F_42 ( V_2 ) ) ;
}
static int F_57 ( struct V_56 * V_57 )
{
struct V_44 * V_45 ;
V_57 -> V_2 . V_58 = F_58 ( 32 ) ;
V_55 . V_59 = F_47 ( V_60 ) ;
V_45 = F_46 ( & V_57 -> V_2 ) ;
if ( F_59 ( V_45 ) )
return F_60 ( V_45 ) ;
return F_61 ( & V_57 -> V_2 , & V_61 ,
V_45 ) ;
}
static int F_62 ( struct V_56 * V_57 )
{
F_63 ( & V_57 -> V_2 , & V_61 ) ;
return 0 ;
}
static void F_64 ( void )
{
int V_46 = V_62 ;
while ( -- V_46 >= 0 ) {
F_65 ( V_63 [ V_46 ] ) ;
V_63 [ V_46 ] = NULL ;
}
}
static int F_66 ( void )
{
int V_46 ;
for ( V_46 = 0 ; V_46 < V_62 ; ++ V_46 ) {
struct V_64 * V_52 = V_65 [ V_46 ] ;
struct V_56 * V_57 =
F_67 ( V_52 -> V_50 . V_66 , - 1 ,
NULL , 0 ) ;
if ( ! F_59 ( V_57 ) ) {
V_63 [ V_46 ] = V_57 ;
continue;
}
while ( -- V_46 >= 0 ) {
F_65 ( V_63 [ V_46 ] ) ;
V_63 [ V_46 ] = NULL ;
}
return F_60 ( V_57 ) ;
}
return 0 ;
}
static void F_68 ( struct V_64 * const * V_49 ,
int V_67 )
{
while ( -- V_67 >= 0 )
F_69 ( V_49 [ V_67 ] ) ;
}
static int F_70 ( struct V_64 * const * V_49 ,
int V_67 )
{
int V_46 , V_6 ;
for ( V_46 = 0 ; V_46 < V_67 ; ++ V_46 ) {
V_6 = F_71 ( V_49 [ V_46 ] ) ;
if ( ! V_6 )
continue;
while ( -- V_46 >= 0 )
F_69 ( V_49 [ V_46 ] ) ;
return V_6 ;
}
return 0 ;
}
static inline int F_72 ( void )
{
return F_70 ( V_47 ,
F_47 ( V_47 ) ) ;
}
static inline int F_73 ( void )
{
return F_70 ( V_68 ,
F_47 ( V_68 ) ) ;
}
static inline void F_74 ( void )
{
F_68 ( V_47 ,
F_47 ( V_47 ) ) ;
}
static inline void F_75 ( void )
{
F_68 ( V_68 ,
F_47 ( V_68 ) ) ;
}
static int F_76 ( void )
{
int V_6 ;
V_6 = F_66 () ;
if ( V_6 )
return V_6 ;
V_6 = F_72 () ;
if ( V_6 )
goto V_69;
V_6 = F_73 () ;
if ( V_6 )
goto V_70;
return 0 ;
V_70:
F_74 () ;
V_69:
F_64 () ;
return V_6 ;
}
static void F_77 ( void )
{
F_75 () ;
F_74 () ;
F_64 () ;
}
