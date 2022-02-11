static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
F_3 ( V_4 -> V_7 ) ;
V_4 -> V_8 -> V_9 ( V_4 ) ;
F_4 ( & V_10 . V_11 ) ;
F_5 ( & V_4 -> V_12 ) ;
F_6 ( & V_10 . V_11 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_2 , struct V_13 * V_14 )
{
struct V_3 * V_4 ;
if ( ! F_2 ( V_2 ) )
return - V_5 ;
V_4 = V_2 -> V_6 ;
if ( V_14 -> V_15 + ( ( V_14 -> V_16 - V_14 -> V_17 ) >> V_18 ) >
V_4 -> V_19 >> V_18 )
return - V_5 ;
return V_4 -> V_8 -> V_20 ( V_4 , V_14 ) ;
}
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_21 == & V_22 ;
}
struct V_3 * F_9 ( void * V_23 , const struct V_24 * V_8 ,
T_1 V_19 , int V_25 , const char * V_26 )
{
struct V_3 * V_4 ;
struct V_2 * V_2 ;
if ( F_10 ( ! V_23 || ! V_8
|| ! V_8 -> V_27
|| ! V_8 -> V_28
|| ! V_8 -> V_9
|| ! V_8 -> V_29
|| ! V_8 -> V_30
|| ! V_8 -> V_20 ) ) {
return F_11 ( - V_5 ) ;
}
V_4 = F_12 ( sizeof( struct V_3 ) , V_31 ) ;
if ( V_4 == NULL )
return F_11 ( - V_32 ) ;
V_4 -> V_23 = V_23 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_26 = V_26 ;
V_2 = F_13 ( L_1 , & V_22 , V_4 , V_25 ) ;
V_4 -> V_2 = V_2 ;
F_14 ( & V_4 -> V_11 ) ;
F_15 ( & V_4 -> V_33 ) ;
F_4 ( & V_10 . V_11 ) ;
F_16 ( & V_4 -> V_12 , & V_10 . V_34 ) ;
F_6 ( & V_10 . V_11 ) ;
return V_4 ;
}
int F_17 ( struct V_3 * V_4 , int V_25 )
{
int V_35 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
V_35 = F_18 ( V_25 ) ;
if ( V_35 < 0 )
return V_35 ;
F_19 ( V_35 , V_4 -> V_2 ) ;
return V_35 ;
}
struct V_3 * F_20 ( int V_35 )
{
struct V_2 * V_2 ;
V_2 = F_21 ( V_35 ) ;
if ( ! V_2 )
return F_11 ( - V_36 ) ;
if ( ! F_2 ( V_2 ) ) {
F_22 ( V_2 ) ;
return F_11 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_23 ( struct V_3 * V_4 )
{
if ( F_10 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_22 ( V_4 -> V_2 ) ;
}
struct V_37 * F_24 ( struct V_3 * V_4 ,
struct V_38 * V_39 )
{
struct V_37 * V_40 ;
int V_41 ;
if ( F_10 ( ! V_4 || ! V_39 ) )
return F_11 ( - V_5 ) ;
V_40 = F_12 ( sizeof( struct V_37 ) , V_31 ) ;
if ( V_40 == NULL )
return F_11 ( - V_32 ) ;
V_40 -> V_39 = V_39 ;
V_40 -> V_4 = V_4 ;
F_4 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_8 -> V_40 ) {
V_41 = V_4 -> V_8 -> V_40 ( V_4 , V_39 , V_40 ) ;
if ( V_41 )
goto V_42;
}
F_16 ( & V_40 -> V_43 , & V_4 -> V_33 ) ;
F_6 ( & V_4 -> V_11 ) ;
return V_40 ;
V_42:
F_7 ( V_40 ) ;
F_6 ( & V_4 -> V_11 ) ;
return F_11 ( V_41 ) ;
}
void F_25 ( struct V_3 * V_4 , struct V_37 * V_40 )
{
if ( F_10 ( ! V_4 || ! V_40 ) )
return;
F_4 ( & V_4 -> V_11 ) ;
F_5 ( & V_40 -> V_43 ) ;
if ( V_4 -> V_8 -> V_44 )
V_4 -> V_8 -> V_44 ( V_4 , V_40 ) ;
F_6 ( & V_4 -> V_11 ) ;
F_7 ( V_40 ) ;
}
struct V_45 * F_26 ( struct V_37 * V_40 ,
enum V_46 V_47 )
{
struct V_45 * V_45 = F_11 ( - V_5 ) ;
F_27 () ;
if ( F_10 ( ! V_40 || ! V_40 -> V_4 ) )
return F_11 ( - V_5 ) ;
V_45 = V_40 -> V_4 -> V_8 -> V_27 ( V_40 , V_47 ) ;
return V_45 ;
}
void F_28 ( struct V_37 * V_40 ,
struct V_45 * V_45 ,
enum V_46 V_47 )
{
F_27 () ;
if ( F_10 ( ! V_40 || ! V_40 -> V_4 || ! V_45 ) )
return;
V_40 -> V_4 -> V_8 -> V_28 ( V_40 , V_45 ,
V_47 ) ;
}
int F_29 ( struct V_3 * V_4 , T_1 V_48 , T_1 V_49 ,
enum V_46 V_47 )
{
int V_41 = 0 ;
if ( F_10 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_8 -> V_50 )
V_41 = V_4 -> V_8 -> V_50 ( V_4 , V_48 , V_49 , V_47 ) ;
return V_41 ;
}
void F_30 ( struct V_3 * V_4 , T_1 V_48 , T_1 V_49 ,
enum V_46 V_47 )
{
F_10 ( ! V_4 ) ;
if ( V_4 -> V_8 -> V_51 )
V_4 -> V_8 -> V_51 ( V_4 , V_48 , V_49 , V_47 ) ;
}
void * F_31 ( struct V_3 * V_4 , unsigned long V_52 )
{
F_10 ( ! V_4 ) ;
return V_4 -> V_8 -> V_29 ( V_4 , V_52 ) ;
}
void F_32 ( struct V_3 * V_4 , unsigned long V_52 ,
void * V_53 )
{
F_10 ( ! V_4 ) ;
if ( V_4 -> V_8 -> V_54 )
V_4 -> V_8 -> V_54 ( V_4 , V_52 , V_53 ) ;
}
void * F_33 ( struct V_3 * V_4 , unsigned long V_52 )
{
F_10 ( ! V_4 ) ;
return V_4 -> V_8 -> V_30 ( V_4 , V_52 ) ;
}
void F_34 ( struct V_3 * V_4 , unsigned long V_52 ,
void * V_53 )
{
F_10 ( ! V_4 ) ;
if ( V_4 -> V_8 -> V_55 )
V_4 -> V_8 -> V_55 ( V_4 , V_52 , V_53 ) ;
}
int F_35 ( struct V_3 * V_4 , struct V_13 * V_14 ,
unsigned long V_56 )
{
struct V_2 * V_57 ;
int V_41 ;
if ( F_10 ( ! V_4 || ! V_14 ) )
return - V_5 ;
if ( V_56 + ( ( V_14 -> V_16 - V_14 -> V_17 ) >> V_18 ) < V_56 )
return - V_58 ;
if ( V_56 + ( ( V_14 -> V_16 - V_14 -> V_17 ) >> V_18 ) >
V_4 -> V_19 >> V_18 )
return - V_5 ;
F_36 ( V_4 -> V_2 ) ;
V_57 = V_14 -> V_59 ;
V_14 -> V_59 = V_4 -> V_2 ;
V_14 -> V_15 = V_56 ;
V_41 = V_4 -> V_8 -> V_20 ( V_4 , V_14 ) ;
if ( V_41 ) {
V_14 -> V_59 = V_57 ;
F_22 ( V_4 -> V_2 ) ;
} else {
if ( V_57 )
F_22 ( V_57 ) ;
}
return V_41 ;
}
void * F_37 ( struct V_3 * V_4 )
{
void * V_60 ;
if ( F_10 ( ! V_4 ) )
return NULL ;
if ( ! V_4 -> V_8 -> V_61 )
return NULL ;
F_4 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 ++ ;
F_3 ( ! V_4 -> V_62 ) ;
V_60 = V_4 -> V_62 ;
goto V_63;
}
F_3 ( V_4 -> V_62 ) ;
V_60 = V_4 -> V_8 -> V_61 ( V_4 ) ;
if ( F_38 ( V_60 ) )
goto V_63;
V_4 -> V_62 = V_60 ;
V_4 -> V_7 = 1 ;
V_63:
F_6 ( & V_4 -> V_11 ) ;
return V_60 ;
}
void F_39 ( struct V_3 * V_4 , void * V_53 )
{
if ( F_10 ( ! V_4 ) )
return;
F_3 ( ! V_4 -> V_62 ) ;
F_3 ( V_4 -> V_7 == 0 ) ;
F_3 ( V_4 -> V_62 != V_53 ) ;
F_4 ( & V_4 -> V_11 ) ;
if ( -- V_4 -> V_7 == 0 ) {
if ( V_4 -> V_8 -> V_64 )
V_4 -> V_8 -> V_64 ( V_4 , V_53 ) ;
V_4 -> V_62 = NULL ;
}
F_6 ( & V_4 -> V_11 ) ;
}
static int F_40 ( struct V_65 * V_66 )
{
int V_41 ;
struct V_3 * V_67 ;
struct V_37 * V_68 ;
int V_69 = 0 , V_70 ;
T_1 V_19 = 0 ;
V_41 = F_41 ( & V_10 . V_11 ) ;
if ( V_41 )
return V_41 ;
F_42 ( V_66 , L_2 ) ;
F_42 ( V_66 , L_3 ) ;
F_43 (buf_obj, &db_list.head, list_node) {
V_41 = F_41 ( & V_67 -> V_11 ) ;
if ( V_41 ) {
F_42 ( V_66 ,
L_4 ) ;
continue;
}
F_42 ( V_66 , L_5 ) ;
F_42 ( V_66 , L_6 ,
V_67 -> V_26 , V_67 -> V_19 ,
V_67 -> V_2 -> V_71 , V_67 -> V_2 -> V_72 ,
( long ) ( V_67 -> V_2 -> V_73 . V_74 ) ) ;
F_42 ( V_66 , L_7 ) ;
V_70 = 0 ;
F_43 (attach_obj, &buf_obj->attachments, node) {
F_42 ( V_66 , L_8 ) ;
F_42 ( V_66 , L_9 , V_68 -> V_39 -> V_75 ) ;
V_70 ++ ;
}
F_42 ( V_66 , L_10 ,
V_70 ) ;
V_69 ++ ;
V_19 += V_67 -> V_19 ;
F_6 ( & V_67 -> V_11 ) ;
}
F_42 ( V_66 , L_11 , V_69 , V_19 ) ;
F_6 ( & V_10 . V_11 ) ;
return 0 ;
}
static int F_44 ( struct V_65 * V_66 , void * V_76 )
{
void (* F_45)( struct V_65 * ) = V_66 -> V_77 ;
F_45 ( V_66 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_47 ( V_2 , F_44 , V_1 -> V_78 ) ;
}
static int F_48 ( void )
{
int V_79 = 0 ;
V_80 = F_49 ( L_12 , NULL ) ;
if ( F_50 ( V_80 ) ) {
V_79 = F_51 ( V_80 ) ;
V_80 = NULL ;
return V_79 ;
}
V_79 = F_52 ( L_13 , F_40 ) ;
if ( V_79 )
F_53 ( L_14 ) ;
return V_79 ;
}
static void F_54 ( void )
{
if ( V_80 )
F_55 ( V_80 ) ;
}
int F_52 ( const char * V_81 ,
int (* F_56)( struct V_65 * ) )
{
struct V_82 * V_83 ;
V_83 = F_57 ( V_81 , V_84 , V_80 ,
F_56 , & V_85 ) ;
return F_58 ( V_83 ) ;
}
static inline int F_48 ( void )
{
return 0 ;
}
static inline void F_54 ( void )
{
}
static int T_2 F_59 ( void )
{
F_14 ( & V_10 . V_11 ) ;
F_15 ( & V_10 . V_34 ) ;
F_48 () ;
return 0 ;
}
static void T_3 F_60 ( void )
{
F_54 () ;
}
