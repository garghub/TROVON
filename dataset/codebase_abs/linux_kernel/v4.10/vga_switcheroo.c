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
if ( V_7 -> V_9 != V_10 )
continue;
V_5 = V_1 . V_4 -> V_11 ( V_7 -> V_12 ) ;
if ( V_5 < 0 )
return;
V_7 -> V_9 = V_5 ;
}
F_4 ( & V_1 ) ;
V_1 . V_2 = true ;
}
int F_5 ( const struct V_13 * V_4 ,
enum V_14 V_15 )
{
F_6 ( & V_16 ) ;
if ( V_1 . V_4 ) {
F_7 ( & V_16 ) ;
return - V_17 ;
}
V_1 . V_4 = V_4 ;
V_1 . V_15 = V_15 ;
if ( F_1 () ) {
F_8 ( L_1 ) ;
F_2 () ;
}
F_7 ( & V_16 ) ;
return 0 ;
}
void F_9 ( void )
{
F_6 ( & V_16 ) ;
F_6 ( & V_1 . V_18 ) ;
V_1 . V_15 = 0 ;
V_1 . V_4 = NULL ;
if ( V_1 . V_2 ) {
F_8 ( L_2 ) ;
F_10 ( & V_1 ) ;
V_1 . V_2 = false ;
}
F_7 ( & V_1 . V_18 ) ;
F_7 ( & V_16 ) ;
}
enum V_14 F_11 ( void )
{
return V_1 . V_15 ;
}
static int F_12 ( struct V_19 * V_12 ,
const struct V_20 * V_21 ,
enum V_22 V_9 , bool V_2 ,
bool V_23 )
{
struct V_6 * V_7 ;
V_7 = F_13 ( sizeof( * V_7 ) , V_24 ) ;
if ( ! V_7 )
return - V_25 ;
V_7 -> V_26 = V_27 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_21 = V_21 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_23 = V_23 ;
F_6 ( & V_16 ) ;
F_14 ( & V_7 -> V_28 , & V_1 . V_29 ) ;
if ( F_15 ( V_7 ) )
V_1 . V_3 ++ ;
if ( F_1 () ) {
F_8 ( L_1 ) ;
F_2 () ;
}
F_7 ( & V_16 ) ;
return 0 ;
}
int F_16 ( struct V_19 * V_12 ,
const struct V_20 * V_21 ,
bool V_23 )
{
return F_12 ( V_12 , V_21 , V_10 ,
V_12 == F_17 () ,
V_23 ) ;
}
int F_18 ( struct V_19 * V_12 ,
const struct V_20 * V_21 ,
enum V_22 V_9 )
{
return F_12 ( V_12 , V_21 , V_9 | V_30 , false , false ) ;
}
static struct V_6 *
F_19 ( struct V_31 * V_32 , struct V_19 * V_12 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_12 == V_12 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_20 ( struct V_31 * V_32 ,
enum V_22 V_33 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_9 == V_33 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_21 ( struct V_31 * V_32 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_2 )
return V_7 ;
return NULL ;
}
bool F_22 ( struct V_19 * V_12 )
{
if ( ( V_12 -> V_34 >> 16 ) == V_35 ) {
if ( F_23 () && V_12 != F_17 () &&
! V_1 . V_15 )
return true ;
}
return false ;
}
enum V_36 F_24 ( struct V_19 * V_12 )
{
struct V_6 * V_7 ;
enum V_36 V_5 ;
F_6 ( & V_16 ) ;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( ! V_7 )
V_5 = V_37 ;
else
V_5 = V_7 -> V_26 ;
F_7 ( & V_16 ) ;
return V_5 ;
}
void F_25 ( struct V_19 * V_12 )
{
struct V_6 * V_7 ;
F_6 ( & V_16 ) ;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( V_7 ) {
if ( F_15 ( V_7 ) )
V_1 . V_3 -- ;
F_26 ( & V_7 -> V_28 ) ;
F_27 ( V_7 ) ;
}
if ( V_1 . V_2 && V_1 . V_3 < 2 ) {
F_8 ( L_2 ) ;
F_10 ( & V_1 ) ;
V_1 . V_2 = false ;
}
F_7 ( & V_16 ) ;
}
void F_28 ( struct V_19 * V_12 ,
struct V_38 * V_39 )
{
struct V_6 * V_7 ;
F_6 ( & V_16 ) ;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( V_7 )
V_7 -> V_38 = V_39 ;
F_7 ( & V_16 ) ;
}
int F_29 ( struct V_19 * V_12 )
{
enum V_22 V_9 ;
F_6 ( & V_1 . V_18 ) ;
if ( ! V_1 . V_4 || ! V_1 . V_4 -> V_40 ) {
V_1 . V_41 = - V_42 ;
return - V_42 ;
}
V_9 = V_1 . V_4 -> V_11 ( V_12 ) ;
V_1 . V_41 = V_1 . V_4 -> V_40 ( V_9 ) ;
return V_1 . V_41 ;
}
int F_30 ( struct V_19 * V_12 )
{
enum V_22 V_9 ;
int V_5 = V_1 . V_41 ;
if ( F_31 ( ! F_32 ( & V_1 . V_18 ) ) )
return - V_17 ;
if ( V_1 . V_41 >= 0 ) {
V_9 = V_1 . V_4 -> V_11 ( V_12 ) ;
if ( V_1 . V_41 != V_9 )
V_5 = V_1 . V_4 -> V_40 (
V_1 . V_41 ) ;
}
F_7 ( & V_1 . V_18 ) ;
return V_5 ;
}
static int F_33 ( struct V_43 * V_44 , void * V_45 )
{
struct V_6 * V_7 ;
int V_46 = 0 ;
F_6 ( & V_16 ) ;
F_3 (client, &vgasr_priv.clients, list) {
F_34 ( V_44 , L_3 , V_46 ,
V_33 ( V_7 ) == V_47 ? L_4 :
L_5 ,
F_15 ( V_7 ) ? L_6 : L_7 ,
V_7 -> V_2 ? '+' : ' ' ,
V_7 -> V_23 ? L_8 : L_6 ,
V_7 -> V_26 ? L_9 : L_10 ,
F_35 ( V_7 -> V_12 ) ) ;
V_46 ++ ;
}
F_7 ( & V_16 ) ;
return 0 ;
}
static int F_36 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_37 ( V_49 , F_33 , NULL ) ;
}
static int F_38 ( struct V_6 * V_7 )
{
if ( V_7 -> V_23 )
return 0 ;
if ( V_1 . V_4 -> V_50 )
V_1 . V_4 -> V_50 ( V_7 -> V_9 , V_27 ) ;
V_7 -> V_21 -> V_51 ( V_7 -> V_12 , V_27 ) ;
V_7 -> V_26 = V_27 ;
return 0 ;
}
static int F_39 ( struct V_6 * V_7 )
{
if ( V_7 -> V_23 )
return 0 ;
V_7 -> V_21 -> V_51 ( V_7 -> V_12 , V_52 ) ;
if ( V_1 . V_4 -> V_50 )
V_1 . V_4 -> V_50 ( V_7 -> V_9 , V_52 ) ;
V_7 -> V_26 = V_52 ;
return 0 ;
}
static void F_40 ( enum V_22 V_9 ,
enum V_36 V_53 )
{
struct V_6 * V_7 ;
V_7 = F_20 ( & V_1 . V_29 , V_9 | V_30 ) ;
if ( V_7 && V_7 -> V_26 != V_53 ) {
V_7 -> V_21 -> V_51 ( V_7 -> V_12 , V_53 ) ;
V_7 -> V_26 = V_53 ;
}
}
static int F_41 ( struct V_6 * V_54 )
{
struct V_6 * V_2 ;
V_2 = F_21 ( & V_1 . V_29 ) ;
if ( ! V_2 )
return 0 ;
if ( V_54 -> V_26 == V_52 )
F_38 ( V_54 ) ;
F_42 ( V_54 -> V_12 ) ;
return 0 ;
}
static int F_43 ( struct V_6 * V_54 )
{
int V_5 ;
struct V_6 * V_2 ;
V_2 = F_21 ( & V_1 . V_29 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_2 = false ;
F_40 ( V_2 -> V_9 , V_52 ) ;
if ( V_54 -> V_38 ) {
struct V_55 V_56 ;
F_44 () ;
V_56 . V_39 = V_54 -> V_38 ;
F_45 ( V_57 , & V_56 ) ;
F_46 () ;
}
F_6 ( & V_1 . V_18 ) ;
V_5 = V_1 . V_4 -> V_58 ( V_54 -> V_9 ) ;
F_7 ( & V_1 . V_18 ) ;
if ( V_5 )
return V_5 ;
if ( V_54 -> V_21 -> V_59 )
V_54 -> V_21 -> V_59 ( V_54 -> V_12 ) ;
if ( V_2 -> V_26 == V_27 )
F_39 ( V_2 ) ;
F_40 ( V_54 -> V_9 , V_27 ) ;
V_54 -> V_2 = true ;
return 0 ;
}
static bool F_47 ( void )
{
struct V_6 * V_7 ;
F_3 (client, &vgasr_priv.clients, list) {
if ( ! V_7 -> V_21 -> V_60 ( V_7 -> V_12 ) ) {
F_48 ( L_11 , V_7 -> V_9 ) ;
return false ;
}
}
return true ;
}
static T_1
F_49 ( struct V_49 * V_61 , const char T_2 * V_62 ,
T_3 V_63 , T_4 * V_64 )
{
char V_65 [ 64 ] ;
int V_5 ;
bool V_66 = false , V_60 ;
bool V_67 = false ;
enum V_22 V_33 = V_10 ;
struct V_6 * V_7 = NULL ;
if ( V_63 > 63 )
V_63 = 63 ;
if ( F_50 ( V_65 , V_62 , V_63 ) )
return - V_68 ;
F_6 ( & V_16 ) ;
if ( ! V_1 . V_2 ) {
V_63 = - V_17 ;
goto V_69;
}
if ( strncmp ( V_65 , L_12 , 3 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_51 ( V_7 ) )
continue;
if ( V_7 -> V_23 )
continue;
F_40 ( V_7 -> V_9 , V_52 ) ;
if ( V_7 -> V_26 == V_27 )
F_39 ( V_7 ) ;
}
goto V_69;
}
if ( strncmp ( V_65 , L_13 , 2 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_51 ( V_7 ) )
continue;
if ( V_7 -> V_23 )
continue;
if ( V_7 -> V_26 == V_52 )
F_38 ( V_7 ) ;
F_40 ( V_7 -> V_9 , V_27 ) ;
}
goto V_69;
}
if ( strncmp ( V_65 , L_14 , 4 ) == 0 ) {
V_33 = V_70 ;
V_66 = true ;
}
if ( strncmp ( V_65 , L_15 , 4 ) == 0 ) {
V_33 = V_47 ;
V_66 = true ;
}
if ( strncmp ( V_65 , L_5 , 3 ) == 0 )
V_33 = V_70 ;
if ( strncmp ( V_65 , L_4 , 3 ) == 0 )
V_33 = V_47 ;
if ( strncmp ( V_65 , L_16 , 4 ) == 0 ) {
V_67 = true ;
V_33 = V_70 ;
}
if ( strncmp ( V_65 , L_17 , 4 ) == 0 ) {
V_67 = true ;
V_33 = V_47 ;
}
if ( V_33 == V_10 )
goto V_69;
V_7 = F_20 ( & V_1 . V_29 , V_33 ) ;
if ( ! V_7 )
goto V_69;
V_1 . V_71 = false ;
if ( V_67 ) {
F_6 ( & V_1 . V_18 ) ;
V_5 = V_1 . V_4 -> V_58 ( V_33 ) ;
F_7 ( & V_1 . V_18 ) ;
goto V_69;
}
if ( V_7 -> V_2 )
goto V_69;
V_60 = F_47 () ;
if ( V_60 == false && V_66 == false )
goto V_69;
if ( V_60 ) {
V_5 = F_41 ( V_7 ) ;
if ( V_5 )
F_48 ( L_18 , V_5 ) ;
V_5 = F_43 ( V_7 ) ;
if ( V_5 )
F_48 ( L_19 , V_5 ) ;
} else {
F_8 ( L_20 , V_7 -> V_9 ) ;
V_1 . V_71 = true ;
V_1 . V_72 = V_33 ;
V_5 = F_41 ( V_7 ) ;
if ( V_5 )
F_48 ( L_21 , V_5 ) ;
}
V_69:
F_7 ( & V_16 ) ;
return V_63 ;
}
static void F_10 ( struct V_1 * V_73 )
{
F_52 ( V_73 -> V_74 ) ;
V_73 -> V_74 = NULL ;
F_52 ( V_73 -> V_75 ) ;
V_73 -> V_75 = NULL ;
}
static int F_4 ( struct V_1 * V_73 )
{
static const char V_76 [] = L_22 ;
if ( V_73 -> V_75 )
return 0 ;
V_73 -> V_75 = F_53 ( L_23 , NULL ) ;
if ( ! V_73 -> V_75 ) {
F_48 ( L_24 , V_76 ) ;
goto V_77;
}
V_73 -> V_74 = F_54 ( L_25 , 0644 ,
V_73 -> V_75 , NULL ,
& V_78 ) ;
if ( ! V_73 -> V_74 ) {
F_48 ( L_26 , V_76 ) ;
goto V_77;
}
return 0 ;
V_77:
F_10 ( V_73 ) ;
return - 1 ;
}
int F_55 ( void )
{
struct V_6 * V_7 ;
int V_5 ;
int V_79 = - V_17 ;
F_6 ( & V_16 ) ;
if ( ! V_1 . V_71 )
goto V_79;
F_8 ( L_27 ,
V_1 . V_72 ) ;
V_7 = F_20 ( & V_1 . V_29 ,
V_1 . V_72 ) ;
if ( ! V_7 || ! F_47 () )
goto V_79;
V_5 = F_43 ( V_7 ) ;
if ( V_5 )
F_48 ( L_28 , V_5 ) ;
V_1 . V_71 = false ;
V_79 = 0 ;
V_79:
F_7 ( & V_16 ) ;
return V_79 ;
}
static void F_56 ( struct V_19 * V_12 ,
enum V_36 V_53 )
{
struct V_6 * V_7 ;
if ( ! V_1 . V_4 -> V_50 )
return;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( ! V_7 )
return;
if ( ! V_7 -> V_23 )
return;
V_1 . V_4 -> V_50 ( V_7 -> V_9 , V_53 ) ;
}
void F_57 ( struct V_19 * V_12 ,
enum V_36 V_80 )
{
struct V_6 * V_7 ;
F_6 ( & V_16 ) ;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( ! V_7 || ! V_7 -> V_23 ) {
F_7 ( & V_16 ) ;
return;
}
V_7 -> V_26 = V_80 ;
F_40 ( V_7 -> V_9 , V_80 ) ;
F_7 ( & V_16 ) ;
}
static int F_58 ( struct V_81 * V_82 )
{
struct V_19 * V_12 = F_59 ( V_82 ) ;
int V_5 ;
V_5 = V_82 -> V_83 -> V_84 -> V_85 ( V_82 ) ;
if ( V_5 )
return V_5 ;
F_6 ( & V_16 ) ;
if ( V_1 . V_4 -> V_58 ) {
F_6 ( & V_1 . V_18 ) ;
V_1 . V_4 -> V_58 ( V_70 ) ;
F_7 ( & V_1 . V_18 ) ;
}
F_56 ( V_12 , V_52 ) ;
F_7 ( & V_16 ) ;
return 0 ;
}
static int F_60 ( struct V_81 * V_82 )
{
struct V_19 * V_12 = F_59 ( V_82 ) ;
int V_5 ;
F_6 ( & V_16 ) ;
F_56 ( V_12 , V_27 ) ;
F_7 ( & V_16 ) ;
V_5 = V_82 -> V_83 -> V_84 -> V_86 ( V_82 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
int F_61 ( struct V_81 * V_82 ,
struct V_87 * V_88 )
{
if ( V_82 -> V_83 && V_82 -> V_83 -> V_84 ) {
V_88 -> V_21 = * V_82 -> V_83 -> V_84 ;
V_88 -> V_21 . V_85 = F_58 ;
V_88 -> V_21 . V_86 = F_60 ;
F_62 ( V_82 , V_88 ) ;
return 0 ;
}
F_62 ( V_82 , NULL ) ;
return - V_17 ;
}
void F_63 ( struct V_81 * V_82 )
{
F_62 ( V_82 , NULL ) ;
}
static int F_64 ( struct V_81 * V_82 )
{
struct V_19 * V_12 = F_59 ( V_82 ) ;
struct V_6 * V_7 ;
struct V_81 * V_89 = NULL ;
int V_5 ;
F_6 ( & V_16 ) ;
F_3 (client, &vgasr_priv.clients, list) {
if ( F_65 ( V_7 -> V_12 -> V_90 ) == F_65 ( V_12 -> V_90 ) &&
F_15 ( V_7 ) ) {
V_89 = & V_7 -> V_12 -> V_82 ;
break;
}
}
F_7 ( & V_16 ) ;
if ( V_89 ) {
V_5 = F_66 ( V_89 ) ;
if ( V_5 && V_5 != 1 )
return V_5 ;
}
V_5 = V_82 -> V_83 -> V_84 -> V_86 ( V_82 ) ;
if ( V_89 ) {
F_67 ( V_89 ) ;
F_68 ( V_89 ) ;
}
return V_5 ;
}
int
F_69 ( struct V_81 * V_82 ,
struct V_87 * V_88 )
{
if ( V_82 -> V_83 && V_82 -> V_83 -> V_84 ) {
V_88 -> V_21 = * V_82 -> V_83 -> V_84 ;
V_88 -> V_21 . V_86 =
F_64 ;
F_62 ( V_82 , V_88 ) ;
return 0 ;
}
F_62 ( V_82 , NULL ) ;
return - V_17 ;
}
