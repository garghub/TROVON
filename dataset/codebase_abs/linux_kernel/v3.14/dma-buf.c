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
static T_1 F_9 ( struct V_2 * V_2 , T_1 V_21 , int V_22 )
{
struct V_3 * V_4 ;
T_1 V_23 ;
if ( ! F_2 ( V_2 ) )
return - V_24 ;
V_4 = V_2 -> V_6 ;
if ( V_22 == V_25 )
V_23 = V_4 -> V_19 ;
else if ( V_22 == V_26 )
V_23 = 0 ;
else
return - V_5 ;
if ( V_21 != 0 )
return - V_5 ;
return V_23 + V_21 ;
}
static inline int F_2 ( struct V_2 * V_2 )
{
return V_2 -> V_27 == & V_28 ;
}
struct V_3 * F_10 ( void * V_29 , const struct V_30 * V_8 ,
T_2 V_19 , int V_31 , const char * V_32 )
{
struct V_3 * V_4 ;
struct V_2 * V_2 ;
if ( F_11 ( ! V_29 || ! V_8
|| ! V_8 -> V_33
|| ! V_8 -> V_34
|| ! V_8 -> V_9
|| ! V_8 -> V_35
|| ! V_8 -> V_36
|| ! V_8 -> V_20 ) ) {
return F_12 ( - V_5 ) ;
}
V_4 = F_13 ( sizeof( struct V_3 ) , V_37 ) ;
if ( V_4 == NULL )
return F_12 ( - V_38 ) ;
V_4 -> V_29 = V_29 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_19 = V_19 ;
V_4 -> V_32 = V_32 ;
V_2 = F_14 ( L_1 , & V_28 , V_4 , V_31 ) ;
if ( F_15 ( V_2 ) ) {
F_7 ( V_4 ) ;
return F_16 ( V_2 ) ;
}
V_2 -> V_39 |= V_40 ;
V_4 -> V_2 = V_2 ;
F_17 ( & V_4 -> V_11 ) ;
F_18 ( & V_4 -> V_41 ) ;
F_4 ( & V_10 . V_11 ) ;
F_19 ( & V_4 -> V_12 , & V_10 . V_42 ) ;
F_6 ( & V_10 . V_11 ) ;
return V_4 ;
}
int F_20 ( struct V_3 * V_4 , int V_31 )
{
int V_43 ;
if ( ! V_4 || ! V_4 -> V_2 )
return - V_5 ;
V_43 = F_21 ( V_31 ) ;
if ( V_43 < 0 )
return V_43 ;
F_22 ( V_43 , V_4 -> V_2 ) ;
return V_43 ;
}
struct V_3 * F_23 ( int V_43 )
{
struct V_2 * V_2 ;
V_2 = F_24 ( V_43 ) ;
if ( ! V_2 )
return F_12 ( - V_24 ) ;
if ( ! F_2 ( V_2 ) ) {
F_25 ( V_2 ) ;
return F_12 ( - V_5 ) ;
}
return V_2 -> V_6 ;
}
void F_26 ( struct V_3 * V_4 )
{
if ( F_11 ( ! V_4 || ! V_4 -> V_2 ) )
return;
F_25 ( V_4 -> V_2 ) ;
}
struct V_44 * F_27 ( struct V_3 * V_4 ,
struct V_45 * V_46 )
{
struct V_44 * V_47 ;
int V_48 ;
if ( F_11 ( ! V_4 || ! V_46 ) )
return F_12 ( - V_5 ) ;
V_47 = F_13 ( sizeof( struct V_44 ) , V_37 ) ;
if ( V_47 == NULL )
return F_12 ( - V_38 ) ;
V_47 -> V_46 = V_46 ;
V_47 -> V_4 = V_4 ;
F_4 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_8 -> V_47 ) {
V_48 = V_4 -> V_8 -> V_47 ( V_4 , V_46 , V_47 ) ;
if ( V_48 )
goto V_49;
}
F_19 ( & V_47 -> V_50 , & V_4 -> V_41 ) ;
F_6 ( & V_4 -> V_11 ) ;
return V_47 ;
V_49:
F_7 ( V_47 ) ;
F_6 ( & V_4 -> V_11 ) ;
return F_12 ( V_48 ) ;
}
void F_28 ( struct V_3 * V_4 , struct V_44 * V_47 )
{
if ( F_11 ( ! V_4 || ! V_47 ) )
return;
F_4 ( & V_4 -> V_11 ) ;
F_5 ( & V_47 -> V_50 ) ;
if ( V_4 -> V_8 -> V_51 )
V_4 -> V_8 -> V_51 ( V_4 , V_47 ) ;
F_6 ( & V_4 -> V_11 ) ;
F_7 ( V_47 ) ;
}
struct V_52 * F_29 ( struct V_44 * V_47 ,
enum V_53 V_54 )
{
struct V_52 * V_52 = F_12 ( - V_5 ) ;
F_30 () ;
if ( F_11 ( ! V_47 || ! V_47 -> V_4 ) )
return F_12 ( - V_5 ) ;
V_52 = V_47 -> V_4 -> V_8 -> V_33 ( V_47 , V_54 ) ;
return V_52 ;
}
void F_31 ( struct V_44 * V_47 ,
struct V_52 * V_52 ,
enum V_53 V_54 )
{
F_30 () ;
if ( F_11 ( ! V_47 || ! V_47 -> V_4 || ! V_52 ) )
return;
V_47 -> V_4 -> V_8 -> V_34 ( V_47 , V_52 ,
V_54 ) ;
}
int F_32 ( struct V_3 * V_4 , T_2 V_55 , T_2 V_56 ,
enum V_53 V_54 )
{
int V_48 = 0 ;
if ( F_11 ( ! V_4 ) )
return - V_5 ;
if ( V_4 -> V_8 -> V_57 )
V_48 = V_4 -> V_8 -> V_57 ( V_4 , V_55 , V_56 , V_54 ) ;
return V_48 ;
}
void F_33 ( struct V_3 * V_4 , T_2 V_55 , T_2 V_56 ,
enum V_53 V_54 )
{
F_11 ( ! V_4 ) ;
if ( V_4 -> V_8 -> V_58 )
V_4 -> V_8 -> V_58 ( V_4 , V_55 , V_56 , V_54 ) ;
}
void * F_34 ( struct V_3 * V_4 , unsigned long V_59 )
{
F_11 ( ! V_4 ) ;
return V_4 -> V_8 -> V_35 ( V_4 , V_59 ) ;
}
void F_35 ( struct V_3 * V_4 , unsigned long V_59 ,
void * V_60 )
{
F_11 ( ! V_4 ) ;
if ( V_4 -> V_8 -> V_61 )
V_4 -> V_8 -> V_61 ( V_4 , V_59 , V_60 ) ;
}
void * F_36 ( struct V_3 * V_4 , unsigned long V_59 )
{
F_11 ( ! V_4 ) ;
return V_4 -> V_8 -> V_36 ( V_4 , V_59 ) ;
}
void F_37 ( struct V_3 * V_4 , unsigned long V_59 ,
void * V_60 )
{
F_11 ( ! V_4 ) ;
if ( V_4 -> V_8 -> V_62 )
V_4 -> V_8 -> V_62 ( V_4 , V_59 , V_60 ) ;
}
int F_38 ( struct V_3 * V_4 , struct V_13 * V_14 ,
unsigned long V_63 )
{
struct V_2 * V_64 ;
int V_48 ;
if ( F_11 ( ! V_4 || ! V_14 ) )
return - V_5 ;
if ( V_63 + ( ( V_14 -> V_16 - V_14 -> V_17 ) >> V_18 ) < V_63 )
return - V_65 ;
if ( V_63 + ( ( V_14 -> V_16 - V_14 -> V_17 ) >> V_18 ) >
V_4 -> V_19 >> V_18 )
return - V_5 ;
F_39 ( V_4 -> V_2 ) ;
V_64 = V_14 -> V_66 ;
V_14 -> V_66 = V_4 -> V_2 ;
V_14 -> V_15 = V_63 ;
V_48 = V_4 -> V_8 -> V_20 ( V_4 , V_14 ) ;
if ( V_48 ) {
V_14 -> V_66 = V_64 ;
F_25 ( V_4 -> V_2 ) ;
} else {
if ( V_64 )
F_25 ( V_64 ) ;
}
return V_48 ;
}
void * F_40 ( struct V_3 * V_4 )
{
void * V_67 ;
if ( F_11 ( ! V_4 ) )
return NULL ;
if ( ! V_4 -> V_8 -> V_68 )
return NULL ;
F_4 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 ++ ;
F_3 ( ! V_4 -> V_69 ) ;
V_67 = V_4 -> V_69 ;
goto V_70;
}
F_3 ( V_4 -> V_69 ) ;
V_67 = V_4 -> V_8 -> V_68 ( V_4 ) ;
if ( F_41 ( V_67 ) )
goto V_70;
V_4 -> V_69 = V_67 ;
V_4 -> V_7 = 1 ;
V_70:
F_6 ( & V_4 -> V_11 ) ;
return V_67 ;
}
void F_42 ( struct V_3 * V_4 , void * V_60 )
{
if ( F_11 ( ! V_4 ) )
return;
F_3 ( ! V_4 -> V_69 ) ;
F_3 ( V_4 -> V_7 == 0 ) ;
F_3 ( V_4 -> V_69 != V_60 ) ;
F_4 ( & V_4 -> V_11 ) ;
if ( -- V_4 -> V_7 == 0 ) {
if ( V_4 -> V_8 -> V_71 )
V_4 -> V_8 -> V_71 ( V_4 , V_60 ) ;
V_4 -> V_69 = NULL ;
}
F_6 ( & V_4 -> V_11 ) ;
}
static int F_43 ( struct V_72 * V_73 )
{
int V_48 ;
struct V_3 * V_74 ;
struct V_44 * V_75 ;
int V_76 = 0 , V_77 ;
T_2 V_19 = 0 ;
V_48 = F_44 ( & V_10 . V_11 ) ;
if ( V_48 )
return V_48 ;
F_45 ( V_73 , L_2 ) ;
F_45 ( V_73 , L_3 ) ;
F_46 (buf_obj, &db_list.head, list_node) {
V_48 = F_44 ( & V_74 -> V_11 ) ;
if ( V_48 ) {
F_45 ( V_73 ,
L_4 ) ;
continue;
}
F_47 ( V_73 , L_5 ,
V_74 -> V_19 ,
V_74 -> V_2 -> V_78 , V_74 -> V_2 -> V_39 ,
( long ) ( V_74 -> V_2 -> V_79 . V_80 ) ,
V_74 -> V_32 ) ;
F_45 ( V_73 , L_6 ) ;
V_77 = 0 ;
F_46 (attach_obj, &buf_obj->attachments, node) {
F_45 ( V_73 , L_7 ) ;
F_47 ( V_73 , L_8 , F_48 ( V_75 -> V_46 ) ) ;
V_77 ++ ;
}
F_47 ( V_73 , L_9 ,
V_77 ) ;
V_76 ++ ;
V_19 += V_74 -> V_19 ;
F_6 ( & V_74 -> V_11 ) ;
}
F_47 ( V_73 , L_10 , V_76 , V_19 ) ;
F_6 ( & V_10 . V_11 ) ;
return 0 ;
}
static int F_49 ( struct V_72 * V_73 , void * V_81 )
{
void (* F_50)( struct V_72 * ) = V_73 -> V_82 ;
F_50 ( V_73 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_52 ( V_2 , F_49 , V_1 -> V_83 ) ;
}
static int F_53 ( void )
{
int V_84 = 0 ;
V_85 = F_54 ( L_11 , NULL ) ;
if ( F_15 ( V_85 ) ) {
V_84 = F_55 ( V_85 ) ;
V_85 = NULL ;
return V_84 ;
}
V_84 = F_56 ( L_12 , F_43 ) ;
if ( V_84 )
F_57 ( L_13 ) ;
return V_84 ;
}
static void F_58 ( void )
{
if ( V_85 )
F_59 ( V_85 ) ;
}
int F_56 ( const char * V_86 ,
int (* F_60)( struct V_72 * ) )
{
struct V_87 * V_88 ;
V_88 = F_61 ( V_86 , V_89 , V_85 ,
F_60 , & V_90 ) ;
return F_62 ( V_88 ) ;
}
static inline int F_53 ( void )
{
return 0 ;
}
static inline void F_58 ( void )
{
}
static int T_3 F_63 ( void )
{
F_17 ( & V_10 . V_11 ) ;
F_18 ( & V_10 . V_42 ) ;
F_53 () ;
return 0 ;
}
static void T_4 F_64 ( void )
{
F_58 () ;
}
