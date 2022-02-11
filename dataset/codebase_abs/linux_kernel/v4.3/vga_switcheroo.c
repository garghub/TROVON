static bool F_1 ( void )
{
return ! V_1 . V_2 &&
V_1 . V_3 == 2 && V_1 . V_4 ;
}
static void F_2 ( void )
{
int V_5 ;
struct V_6 * V_7 ;
if ( V_1 . V_4 -> V_8 )
V_1 . V_4 -> V_8 () ;
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_9 != - 1 )
continue;
V_5 = V_1 . V_4 -> V_10 ( V_7 -> V_11 ) ;
if ( V_5 < 0 )
return;
V_7 -> V_9 = V_5 ;
}
F_4 ( & V_1 ) ;
V_1 . V_2 = true ;
}
int F_5 ( struct V_12 * V_4 )
{
F_6 ( & V_13 ) ;
if ( V_1 . V_4 ) {
F_7 ( & V_13 ) ;
return - V_14 ;
}
V_1 . V_4 = V_4 ;
if ( F_1 () ) {
F_8 ( L_1 ) ;
F_2 () ;
}
F_7 ( & V_13 ) ;
return 0 ;
}
void F_9 ( void )
{
F_6 ( & V_13 ) ;
V_1 . V_4 = NULL ;
if ( V_1 . V_2 ) {
F_8 ( L_2 ) ;
F_10 ( & V_1 ) ;
V_1 . V_2 = false ;
}
F_7 ( & V_13 ) ;
}
static int F_11 ( struct V_15 * V_11 ,
const struct V_16 * V_17 ,
int V_9 , bool V_2 , bool V_18 )
{
struct V_6 * V_7 ;
V_7 = F_12 ( sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return - V_20 ;
V_7 -> V_21 = V_22 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_17 = V_17 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_18 = V_18 ;
F_6 ( & V_13 ) ;
F_13 ( & V_7 -> V_23 , & V_1 . V_24 ) ;
if ( F_14 ( V_7 ) )
V_1 . V_3 ++ ;
if ( F_1 () ) {
F_8 ( L_1 ) ;
F_2 () ;
}
F_7 ( & V_13 ) ;
return 0 ;
}
int F_15 ( struct V_15 * V_11 ,
const struct V_16 * V_17 ,
bool V_18 )
{
return F_11 ( V_11 , V_17 , - 1 ,
V_11 == F_16 () ,
V_18 ) ;
}
int F_17 ( struct V_15 * V_11 ,
const struct V_16 * V_17 ,
int V_9 , bool V_2 )
{
return F_11 ( V_11 , V_17 , V_9 | V_25 , V_2 , false ) ;
}
static struct V_6 *
F_18 ( struct V_26 * V_27 , struct V_15 * V_11 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_11 == V_11 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_19 ( struct V_26 * V_27 , int V_28 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_9 == V_28 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_20 ( struct V_26 * V_27 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_2 && F_14 ( V_7 ) )
return V_7 ;
return NULL ;
}
int F_21 ( struct V_15 * V_11 )
{
struct V_6 * V_7 ;
V_7 = F_18 ( & V_1 . V_24 , V_11 ) ;
if ( ! V_7 )
return V_29 ;
if ( ! V_1 . V_2 )
return V_30 ;
return V_7 -> V_21 ;
}
void F_22 ( struct V_15 * V_11 )
{
struct V_6 * V_7 ;
F_6 ( & V_13 ) ;
V_7 = F_18 ( & V_1 . V_24 , V_11 ) ;
if ( V_7 ) {
if ( F_14 ( V_7 ) )
V_1 . V_3 -- ;
F_23 ( & V_7 -> V_23 ) ;
F_24 ( V_7 ) ;
}
if ( V_1 . V_2 && V_1 . V_3 < 2 ) {
F_8 ( L_2 ) ;
F_10 ( & V_1 ) ;
V_1 . V_2 = false ;
}
F_7 ( & V_13 ) ;
}
void F_25 ( struct V_15 * V_11 ,
struct V_31 * V_32 )
{
struct V_6 * V_7 ;
F_6 ( & V_13 ) ;
V_7 = F_18 ( & V_1 . V_24 , V_11 ) ;
if ( V_7 )
V_7 -> V_31 = V_32 ;
F_7 ( & V_13 ) ;
}
static int F_26 ( struct V_33 * V_34 , void * V_35 )
{
struct V_6 * V_7 ;
int V_36 = 0 ;
F_6 ( & V_13 ) ;
F_3 (client, &vgasr_priv.clients, list) {
F_27 ( V_34 , L_3 , V_36 ,
V_28 ( V_7 ) == V_37 ? L_4 :
L_5 ,
F_14 ( V_7 ) ? L_6 : L_7 ,
V_7 -> V_2 ? '+' : ' ' ,
V_7 -> V_18 ? L_8 : L_6 ,
V_7 -> V_21 ? L_9 : L_10 ,
F_28 ( V_7 -> V_11 ) ) ;
V_36 ++ ;
}
F_7 ( & V_13 ) ;
return 0 ;
}
static int F_29 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_30 ( V_39 , F_26 , NULL ) ;
}
static int F_31 ( struct V_6 * V_7 )
{
if ( V_7 -> V_18 )
return 0 ;
if ( V_1 . V_4 -> V_40 )
V_1 . V_4 -> V_40 ( V_7 -> V_9 , V_22 ) ;
V_7 -> V_17 -> V_41 ( V_7 -> V_11 , V_22 ) ;
V_7 -> V_21 = V_22 ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 )
{
if ( V_7 -> V_18 )
return 0 ;
V_7 -> V_17 -> V_41 ( V_7 -> V_11 , V_42 ) ;
if ( V_1 . V_4 -> V_40 )
V_1 . V_4 -> V_40 ( V_7 -> V_9 , V_42 ) ;
V_7 -> V_21 = V_42 ;
return 0 ;
}
static void F_33 ( int V_9 , int V_43 )
{
struct V_6 * V_7 ;
V_7 = F_19 ( & V_1 . V_24 , V_9 | V_25 ) ;
if ( V_7 && V_7 -> V_21 != V_43 ) {
V_7 -> V_17 -> V_41 ( V_7 -> V_11 , V_43 ) ;
V_7 -> V_21 = V_43 ;
}
}
static int F_34 ( struct V_6 * V_44 )
{
struct V_6 * V_2 ;
V_2 = F_20 ( & V_1 . V_24 ) ;
if ( ! V_2 )
return 0 ;
if ( V_44 -> V_21 == V_42 )
F_31 ( V_44 ) ;
F_35 ( V_44 -> V_11 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_44 )
{
int V_5 ;
struct V_6 * V_2 ;
V_2 = F_20 ( & V_1 . V_24 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_2 = false ;
F_33 ( V_2 -> V_9 , V_42 ) ;
if ( V_44 -> V_31 ) {
struct V_45 V_46 ;
F_37 () ;
V_46 . V_32 = V_44 -> V_31 ;
F_38 ( V_47 , & V_46 ) ;
F_39 () ;
}
V_5 = V_1 . V_4 -> V_48 ( V_44 -> V_9 ) ;
if ( V_5 )
return V_5 ;
if ( V_44 -> V_17 -> V_49 )
V_44 -> V_17 -> V_49 ( V_44 -> V_11 ) ;
if ( V_2 -> V_21 == V_22 )
F_32 ( V_2 ) ;
F_33 ( V_44 -> V_9 , V_22 ) ;
V_44 -> V_2 = true ;
return 0 ;
}
static bool F_40 ( void )
{
struct V_6 * V_7 ;
F_3 (client, &vgasr_priv.clients, list) {
if ( ! V_7 -> V_17 -> V_50 ( V_7 -> V_11 ) ) {
F_41 ( L_11 , V_7 -> V_9 ) ;
return false ;
}
}
return true ;
}
static T_1
F_42 ( struct V_39 * V_51 , const char T_2 * V_52 ,
T_3 V_53 , T_4 * V_54 )
{
char V_55 [ 64 ] ;
int V_5 ;
bool V_56 = false , V_50 ;
bool V_57 = false ;
int V_28 = - 1 ;
struct V_6 * V_7 = NULL ;
if ( V_53 > 63 )
V_53 = 63 ;
if ( F_43 ( V_55 , V_52 , V_53 ) )
return - V_58 ;
F_6 ( & V_13 ) ;
if ( ! V_1 . V_2 ) {
V_53 = - V_14 ;
goto V_59;
}
if ( strncmp ( V_55 , L_12 , 3 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_44 ( V_7 ) )
continue;
if ( V_7 -> V_18 )
continue;
F_33 ( V_7 -> V_9 , V_42 ) ;
if ( V_7 -> V_21 == V_22 )
F_32 ( V_7 ) ;
}
goto V_59;
}
if ( strncmp ( V_55 , L_13 , 2 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_44 ( V_7 ) )
continue;
if ( V_7 -> V_18 )
continue;
if ( V_7 -> V_21 == V_42 )
F_31 ( V_7 ) ;
F_33 ( V_7 -> V_9 , V_22 ) ;
}
goto V_59;
}
if ( strncmp ( V_55 , L_14 , 4 ) == 0 ) {
V_28 = V_60 ;
V_56 = true ;
}
if ( strncmp ( V_55 , L_15 , 4 ) == 0 ) {
V_28 = V_37 ;
V_56 = true ;
}
if ( strncmp ( V_55 , L_5 , 3 ) == 0 )
V_28 = V_60 ;
if ( strncmp ( V_55 , L_4 , 3 ) == 0 )
V_28 = V_37 ;
if ( strncmp ( V_55 , L_16 , 4 ) == 0 ) {
V_57 = true ;
V_28 = V_60 ;
}
if ( strncmp ( V_55 , L_17 , 4 ) == 0 ) {
V_57 = true ;
V_28 = V_37 ;
}
if ( V_28 == - 1 )
goto V_59;
V_7 = F_19 ( & V_1 . V_24 , V_28 ) ;
if ( ! V_7 )
goto V_59;
V_1 . V_61 = false ;
if ( V_57 ) {
V_5 = V_1 . V_4 -> V_48 ( V_28 ) ;
goto V_59;
}
if ( V_7 -> V_2 )
goto V_59;
V_50 = F_40 () ;
if ( V_50 == false && V_56 == false )
goto V_59;
if ( V_50 ) {
V_5 = F_34 ( V_7 ) ;
if ( V_5 )
F_41 ( L_18 , V_5 ) ;
V_5 = F_36 ( V_7 ) ;
if ( V_5 )
F_41 ( L_19 , V_5 ) ;
} else {
F_8 ( L_20 , V_7 -> V_9 ) ;
V_1 . V_61 = true ;
V_1 . V_62 = V_28 ;
V_5 = F_34 ( V_7 ) ;
if ( V_5 )
F_41 ( L_21 , V_5 ) ;
}
V_59:
F_7 ( & V_13 ) ;
return V_53 ;
}
static void F_10 ( struct V_1 * V_63 )
{
F_45 ( V_63 -> V_64 ) ;
V_63 -> V_64 = NULL ;
F_45 ( V_63 -> V_65 ) ;
V_63 -> V_65 = NULL ;
}
static int F_4 ( struct V_1 * V_63 )
{
static const char V_66 [] = L_22 ;
if ( V_63 -> V_65 )
return 0 ;
V_63 -> V_65 = F_46 ( L_23 , NULL ) ;
if ( ! V_63 -> V_65 ) {
F_41 ( L_24 , V_66 ) ;
goto V_67;
}
V_63 -> V_64 = F_47 ( L_25 , 0644 ,
V_63 -> V_65 , NULL ,
& V_68 ) ;
if ( ! V_63 -> V_64 ) {
F_41 ( L_26 , V_66 ) ;
goto V_67;
}
return 0 ;
V_67:
F_10 ( V_63 ) ;
return - 1 ;
}
int F_48 ( void )
{
struct V_6 * V_7 ;
int V_5 ;
int V_69 = - V_14 ;
F_6 ( & V_13 ) ;
if ( ! V_1 . V_61 )
goto V_69;
F_8 ( L_27 ,
V_1 . V_62 ) ;
V_7 = F_19 ( & V_1 . V_24 ,
V_1 . V_62 ) ;
if ( ! V_7 || ! F_40 () )
goto V_69;
V_5 = F_36 ( V_7 ) ;
if ( V_5 )
F_41 ( L_28 , V_5 ) ;
V_1 . V_61 = false ;
V_69 = 0 ;
V_69:
F_7 ( & V_13 ) ;
return V_69 ;
}
static void F_49 ( struct V_15 * V_11 ,
enum V_70 V_43 )
{
struct V_6 * V_7 ;
if ( ! V_1 . V_4 -> V_40 )
return;
V_7 = F_18 ( & V_1 . V_24 , V_11 ) ;
if ( ! V_7 )
return;
if ( ! V_7 -> V_18 )
return;
V_1 . V_4 -> V_40 ( V_7 -> V_9 , V_43 ) ;
}
void F_50 ( struct V_15 * V_11 ,
enum V_70 V_71 )
{
struct V_6 * V_7 ;
V_7 = F_18 ( & V_1 . V_24 , V_11 ) ;
if ( ! V_7 )
return;
if ( ! V_7 -> V_18 )
return;
V_7 -> V_21 = V_71 ;
F_33 ( V_7 -> V_9 , V_71 ) ;
}
static int F_51 ( struct V_72 * V_73 )
{
struct V_15 * V_11 = F_52 ( V_73 ) ;
int V_5 ;
V_5 = V_73 -> V_74 -> V_75 -> V_76 ( V_73 ) ;
if ( V_5 )
return V_5 ;
if ( V_1 . V_4 -> V_48 )
V_1 . V_4 -> V_48 ( V_60 ) ;
F_49 ( V_11 , V_42 ) ;
return 0 ;
}
static int F_53 ( struct V_72 * V_73 )
{
struct V_15 * V_11 = F_52 ( V_73 ) ;
int V_5 ;
F_49 ( V_11 , V_22 ) ;
V_5 = V_73 -> V_74 -> V_75 -> V_77 ( V_73 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
int F_54 ( struct V_72 * V_73 ,
struct V_78 * V_79 )
{
if ( V_73 -> V_74 && V_73 -> V_74 -> V_75 ) {
V_79 -> V_17 = * V_73 -> V_74 -> V_75 ;
V_79 -> V_17 . V_76 = F_51 ;
V_79 -> V_17 . V_77 = F_53 ;
V_73 -> V_80 = V_79 ;
return 0 ;
}
V_73 -> V_80 = NULL ;
return - V_14 ;
}
void F_55 ( struct V_72 * V_73 )
{
V_73 -> V_80 = NULL ;
}
static int F_56 ( struct V_72 * V_73 )
{
struct V_15 * V_11 = F_52 ( V_73 ) ;
int V_5 ;
struct V_6 * V_7 , * V_81 = NULL ;
F_3 (client, &vgasr_priv.clients, list) {
if ( F_57 ( V_7 -> V_11 -> V_82 ) == F_57 ( V_11 -> V_82 ) &&
F_14 ( V_7 ) ) {
V_81 = V_7 ;
V_5 = F_58 ( & V_7 -> V_11 -> V_73 ) ;
if ( V_5 ) {
if ( V_5 != 1 )
return V_5 ;
}
break;
}
}
V_5 = V_73 -> V_74 -> V_75 -> V_77 ( V_73 ) ;
if ( V_81 ) {
F_59 ( & V_81 -> V_11 -> V_73 ) ;
F_60 ( & V_81 -> V_11 -> V_73 ) ;
}
return V_5 ;
}
int
F_61 ( struct V_72 * V_73 ,
struct V_78 * V_79 )
{
if ( V_73 -> V_74 && V_73 -> V_74 -> V_75 ) {
V_79 -> V_17 = * V_73 -> V_74 -> V_75 ;
V_79 -> V_17 . V_77 =
F_56 ;
V_73 -> V_80 = V_79 ;
return 0 ;
}
V_73 -> V_80 = NULL ;
return - V_14 ;
}
