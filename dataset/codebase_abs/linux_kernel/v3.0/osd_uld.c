static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_5 ,
struct V_3 , V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 ;
F_4 ( L_1 , V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_4 ( L_2 , V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
F_6 ( & V_4 -> V_7 ) ;
return 0 ;
}
int F_7 ( unsigned V_9 , T_1 * V_10 )
{
if ( V_11 )
return - V_12 ;
V_11 = V_9 ;
V_13 = V_10 ;
return 0 ;
}
void F_8 ( unsigned V_9 )
{
if ( V_9 == V_11 ) {
V_11 = 0 ;
V_13 = NULL ;
}
}
static T_1 * F_9 ( unsigned V_14 )
{
if ( V_11 == V_14 )
return V_13 ;
else
return NULL ;
}
static long F_10 ( struct V_2 * V_2 , unsigned int V_14 ,
unsigned long V_15 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
int V_16 ;
T_1 * V_10 ;
V_10 = F_9 ( V_14 ) ;
if ( V_10 )
V_16 = V_10 ( & V_4 -> V_17 , V_14 , V_15 ) ;
else {
F_11 ( L_3 , V_14 , V_4 ) ;
V_16 = - V_18 ;
}
return V_16 ;
}
struct V_19 * F_12 ( const char * V_20 )
{
struct V_3 * V_4 ;
struct V_21 * V_22 ;
struct V_2 * V_2 ;
int error ;
if ( ! V_20 || ! * V_20 ) {
F_11 ( L_4 ) ;
return F_13 ( - V_12 ) ;
}
V_22 = F_14 ( sizeof( * V_22 ) , V_23 ) ;
if ( F_15 ( ! V_22 ) )
return F_13 ( - V_24 ) ;
V_2 = F_16 ( V_20 , V_25 , 0 ) ;
if ( F_17 ( V_2 ) ) {
error = F_18 ( V_2 ) ;
goto V_26;
}
if ( V_2 -> V_27 != & V_28 ) {
error = - V_12 ;
goto V_29;
}
V_4 = V_2 -> V_8 ;
V_22 -> V_17 = V_4 -> V_17 ;
V_22 -> V_2 = V_2 ;
V_22 -> V_4 = V_4 ;
return & V_22 -> V_17 ;
V_29:
F_19 ( V_2 ) ;
V_26:
F_20 ( V_22 ) ;
return F_13 ( error ) ;
}
static inline bool F_21 ( const T_2 * V_30 , unsigned V_31 ,
const T_2 * V_32 , unsigned V_33 )
{
if ( ! V_33 )
return true ;
if ( V_31 != V_33 )
return false ;
return 0 == memcmp ( V_30 , V_32 , V_31 ) ;
}
int F_22 ( struct V_34 * V_35 , void * V_36 )
{
struct V_3 * V_4 = F_2 ( V_35 , struct V_3 ,
V_7 ) ;
struct V_37 * V_38 = V_36 ;
const struct V_39 * V_40 = V_38 -> V_40 ;
if ( F_21 ( V_4 -> V_40 . V_41 , V_4 -> V_40 . V_42 ,
V_40 -> V_41 , V_40 -> V_42 ) &&
F_21 ( V_4 -> V_40 . V_43 , V_4 -> V_40 . V_44 ,
V_40 -> V_43 , V_40 -> V_44 ) ) {
F_4 ( L_5 ,
V_40 -> V_42 , V_40 -> V_44 ) ;
V_38 -> V_4 = V_4 ;
return 1 ;
} else {
return 0 ;
}
}
struct V_19 * F_23 ( const struct V_39 * V_40 )
{
struct V_37 V_45 = { . V_40 = V_40 } ;
V_45 . V_35 = F_24 ( & V_46 , NULL , & V_45 , F_22 ) ;
if ( F_25 ( V_45 . V_35 ) ) {
struct V_21 * V_22 = F_14 ( sizeof( * V_22 ) , V_23 ) ;
if ( F_15 ( ! V_22 ) ) {
F_6 ( V_45 . V_35 ) ;
return F_13 ( - V_24 ) ;
}
V_22 -> V_17 = V_45 . V_4 -> V_17 ;
V_22 -> V_4 = V_45 . V_4 ;
return & V_22 -> V_17 ;
}
return F_13 ( - V_47 ) ;
}
void F_26 ( struct V_19 * V_17 )
{
if ( V_17 && ! F_17 ( V_17 ) ) {
struct V_21 * V_22 =
F_2 ( V_17 , struct V_21 , V_17 ) ;
struct V_3 * V_4 = V_22 -> V_4 ;
F_27 ( V_17 -> V_48 != V_4 -> V_17 . V_48 ) ;
if ( V_22 -> V_2 ) {
F_3 ( & V_4 -> V_7 ) ;
F_19 ( V_22 -> V_2 ) ;
}
F_6 ( & V_4 -> V_7 ) ;
F_20 ( V_22 ) ;
}
}
const struct V_39 * F_28 ( struct V_19 * V_17 )
{
struct V_21 * V_22 =
F_2 ( V_17 , struct V_21 , V_17 ) ;
return & V_22 -> V_4 -> V_40 ;
}
bool F_29 ( struct V_19 * V_17 , const struct V_39 * V_40 )
{
struct V_21 * V_22 =
F_2 ( V_17 , struct V_21 , V_17 ) ;
struct V_3 * V_4 = V_22 -> V_4 ;
return ( V_4 -> V_40 . V_42 == V_40 -> V_42 ) &&
F_21 ( V_4 -> V_40 . V_41 , V_4 -> V_40 . V_42 ,
V_40 -> V_41 , V_40 -> V_42 ) &&
( V_4 -> V_40 . V_44 == V_40 -> V_44 ) &&
F_21 ( V_4 -> V_40 . V_43 , V_4 -> V_40 . V_44 ,
V_40 -> V_43 , V_40 -> V_44 ) ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_48 * V_48 = V_4 -> V_17 . V_48 ;
char V_49 [ V_50 ] ;
int error ;
F_4 ( L_6 ,
V_4 , V_48 , V_48 -> V_51 ) ;
error = F_31 ( V_48 , 10 * V_52 , 5 , NULL ) ;
if ( error )
F_11 ( L_7 ) ;
F_32 ( V_49 , & V_53 , false , true ) ;
if ( F_33 ( & V_4 -> V_17 , V_49 , & V_4 -> V_40 ) )
return - V_47 ;
return 0 ;
}
static void F_34 ( struct V_34 * V_35 )
{
struct V_3 * V_4 = F_2 ( V_35 , struct V_3 ,
V_7 ) ;
struct V_48 * V_48 = V_4 -> V_17 . V_48 ;
F_20 ( V_4 -> V_40 . V_43 ) ;
if ( V_4 -> V_6 . V_54 )
F_35 ( & V_4 -> V_6 ) ;
F_36 ( & V_4 -> V_17 ) ;
F_37 ( V_48 ) ;
F_38 ( L_8 ,
V_4 -> V_55 ? V_4 -> V_55 -> V_56 : NULL ) ;
if ( V_4 -> V_55 )
F_39 ( V_4 -> V_55 ) ;
F_40 ( & V_57 , V_4 -> V_58 ) ;
F_20 ( V_4 ) ;
}
static int F_41 ( struct V_34 * V_35 )
{
struct V_48 * V_48 = F_42 ( V_35 ) ;
struct V_59 * V_55 ;
struct V_3 * V_4 ;
int V_58 ;
int error ;
if ( V_48 -> type != V_60 )
return - V_47 ;
do {
if ( ! F_43 ( & V_57 , V_23 ) )
return - V_47 ;
error = F_44 ( & V_57 , & V_58 ) ;
} while ( error == - V_61 );
if ( error )
return error ;
if ( V_58 >= V_62 ) {
error = - V_63 ;
goto V_64;
}
error = - V_24 ;
V_4 = F_14 ( sizeof( * V_4 ) , V_23 ) ;
if ( NULL == V_4 )
goto V_64;
F_45 ( V_35 , V_4 ) ;
V_4 -> V_58 = V_58 ;
V_55 = F_46 ( 1 ) ;
if ( ! V_55 ) {
F_11 ( L_9 ) ;
goto V_65;
}
V_55 -> V_66 = V_67 ;
V_55 -> V_68 = V_4 -> V_58 ;
sprintf ( V_55 -> V_56 , L_10 , V_4 -> V_58 ) ;
V_4 -> V_55 = V_55 ;
F_47 ( V_48 ) ;
F_48 ( & V_4 -> V_17 , V_48 ) ;
error = F_30 ( V_4 ) ;
if ( error ) {
F_11 ( L_11 ) ;
goto V_69;
}
F_49 ( & V_4 -> V_6 , & V_28 ) ;
V_4 -> V_6 . V_54 = V_70 ;
error = F_50 ( & V_4 -> V_6 ,
F_51 ( V_67 , V_4 -> V_58 ) , 1 ) ;
if ( error ) {
F_11 ( L_12 ) ;
goto V_69;
}
V_4 -> V_7 . V_71 = V_4 -> V_6 . V_35 ;
V_4 -> V_7 . V_72 = & V_46 ;
V_4 -> V_7 . V_73 = V_35 ;
V_4 -> V_7 . V_74 = F_34 ;
error = F_52 ( & V_4 -> V_7 , V_55 -> V_56 ) ;
if ( error ) {
F_11 ( L_13 , error ) ;
goto V_75;
}
error = F_53 ( & V_4 -> V_7 ) ;
if ( error ) {
F_11 ( L_14 , error ) ;
goto V_75;
}
F_3 ( & V_4 -> V_7 ) ;
F_38 ( L_15 , V_55 -> V_56 ) ;
return 0 ;
V_75:
F_35 ( & V_4 -> V_6 ) ;
V_69:
F_37 ( V_48 ) ;
F_39 ( V_55 ) ;
V_65:
F_45 ( V_35 , NULL ) ;
F_20 ( V_4 ) ;
V_64:
F_40 ( & V_57 , V_58 ) ;
return error ;
}
static int F_54 ( struct V_34 * V_35 )
{
struct V_48 * V_48 = F_42 ( V_35 ) ;
struct V_3 * V_4 = F_55 ( V_35 ) ;
if ( ! V_4 || ( V_4 -> V_17 . V_48 != V_48 ) ) {
F_11 ( L_16 ,
V_35 , V_4 , V_4 ? V_4 -> V_17 . V_48 : NULL ,
V_48 ) ;
}
F_56 ( & V_4 -> V_7 ) ;
F_6 ( & V_4 -> V_7 ) ;
return 0 ;
}
static int T_3 F_57 ( void )
{
int V_76 ;
V_76 = F_58 ( & V_46 ) ;
if ( V_76 ) {
F_11 ( L_17 , V_76 ) ;
return V_76 ;
}
V_76 = F_59 ( F_51 ( V_67 , 0 ) ,
V_62 , V_77 ) ;
if ( V_76 ) {
F_11 ( L_18 ,
V_67 , V_76 ) ;
goto V_78;
}
V_76 = F_60 ( & V_79 . V_80 ) ;
if ( V_76 ) {
F_11 ( L_19 , V_76 ) ;
goto V_81;
}
F_38 ( L_20 , V_82 ) ;
return 0 ;
V_81:
F_61 ( F_51 ( V_67 , 0 ) , V_62 ) ;
V_78:
F_62 ( & V_46 ) ;
return V_76 ;
}
static void T_4 F_63 ( void )
{
F_64 ( & V_79 . V_80 ) ;
F_61 ( F_51 ( V_67 , 0 ) , V_62 ) ;
F_62 ( & V_46 ) ;
F_38 ( L_21 , V_82 ) ;
}
