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
enum V_34 F_22 ( struct V_19 * V_12 )
{
struct V_6 * V_7 ;
enum V_34 V_5 ;
F_6 ( & V_16 ) ;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( ! V_7 )
V_5 = V_35 ;
else
V_5 = V_7 -> V_26 ;
F_7 ( & V_16 ) ;
return V_5 ;
}
void F_23 ( struct V_19 * V_12 )
{
struct V_6 * V_7 ;
F_6 ( & V_16 ) ;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( V_7 ) {
if ( F_15 ( V_7 ) )
V_1 . V_3 -- ;
F_24 ( & V_7 -> V_28 ) ;
F_25 ( V_7 ) ;
}
if ( V_1 . V_2 && V_1 . V_3 < 2 ) {
F_8 ( L_2 ) ;
F_10 ( & V_1 ) ;
V_1 . V_2 = false ;
}
F_7 ( & V_16 ) ;
}
void F_26 ( struct V_19 * V_12 ,
struct V_36 * V_37 )
{
struct V_6 * V_7 ;
F_6 ( & V_16 ) ;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( V_7 )
V_7 -> V_36 = V_37 ;
F_7 ( & V_16 ) ;
}
int F_27 ( struct V_19 * V_12 )
{
enum V_22 V_9 ;
F_6 ( & V_1 . V_18 ) ;
if ( ! V_1 . V_4 || ! V_1 . V_4 -> V_38 ) {
V_1 . V_39 = - V_40 ;
return - V_40 ;
}
V_9 = V_1 . V_4 -> V_11 ( V_12 ) ;
V_1 . V_39 = V_1 . V_4 -> V_38 ( V_9 ) ;
return V_1 . V_39 ;
}
int F_28 ( struct V_19 * V_12 )
{
enum V_22 V_9 ;
int V_5 = V_1 . V_39 ;
if ( F_29 ( ! F_30 ( & V_1 . V_18 ) ) )
return - V_17 ;
if ( V_1 . V_39 >= 0 ) {
V_9 = V_1 . V_4 -> V_11 ( V_12 ) ;
if ( V_1 . V_39 != V_9 )
V_5 = V_1 . V_4 -> V_38 (
V_1 . V_39 ) ;
}
F_7 ( & V_1 . V_18 ) ;
return V_5 ;
}
static int F_31 ( struct V_41 * V_42 , void * V_43 )
{
struct V_6 * V_7 ;
int V_44 = 0 ;
F_6 ( & V_16 ) ;
F_3 (client, &vgasr_priv.clients, list) {
F_32 ( V_42 , L_3 , V_44 ,
V_33 ( V_7 ) == V_45 ? L_4 :
L_5 ,
F_15 ( V_7 ) ? L_6 : L_7 ,
V_7 -> V_2 ? '+' : ' ' ,
V_7 -> V_23 ? L_8 : L_6 ,
V_7 -> V_26 ? L_9 : L_10 ,
F_33 ( V_7 -> V_12 ) ) ;
V_44 ++ ;
}
F_7 ( & V_16 ) ;
return 0 ;
}
static int F_34 ( struct V_46 * V_46 , struct V_47 * V_47 )
{
return F_35 ( V_47 , F_31 , NULL ) ;
}
static int F_36 ( struct V_6 * V_7 )
{
if ( V_7 -> V_23 )
return 0 ;
if ( V_1 . V_4 -> V_48 )
V_1 . V_4 -> V_48 ( V_7 -> V_9 , V_27 ) ;
V_7 -> V_21 -> V_49 ( V_7 -> V_12 , V_27 ) ;
V_7 -> V_26 = V_27 ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 )
{
if ( V_7 -> V_23 )
return 0 ;
V_7 -> V_21 -> V_49 ( V_7 -> V_12 , V_50 ) ;
if ( V_1 . V_4 -> V_48 )
V_1 . V_4 -> V_48 ( V_7 -> V_9 , V_50 ) ;
V_7 -> V_26 = V_50 ;
return 0 ;
}
static void F_38 ( enum V_22 V_9 ,
enum V_34 V_51 )
{
struct V_6 * V_7 ;
V_7 = F_20 ( & V_1 . V_29 , V_9 | V_30 ) ;
if ( V_7 && V_7 -> V_26 != V_51 ) {
V_7 -> V_21 -> V_49 ( V_7 -> V_12 , V_51 ) ;
V_7 -> V_26 = V_51 ;
}
}
static int F_39 ( struct V_6 * V_52 )
{
struct V_6 * V_2 ;
V_2 = F_21 ( & V_1 . V_29 ) ;
if ( ! V_2 )
return 0 ;
if ( V_52 -> V_26 == V_50 )
F_36 ( V_52 ) ;
F_40 ( V_52 -> V_12 ) ;
return 0 ;
}
static int F_41 ( struct V_6 * V_52 )
{
int V_5 ;
struct V_6 * V_2 ;
V_2 = F_21 ( & V_1 . V_29 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_2 = false ;
F_38 ( V_2 -> V_9 , V_50 ) ;
if ( V_52 -> V_36 ) {
struct V_53 V_54 ;
F_42 () ;
V_54 . V_37 = V_52 -> V_36 ;
F_43 ( V_55 , & V_54 ) ;
F_44 () ;
}
F_6 ( & V_1 . V_18 ) ;
V_5 = V_1 . V_4 -> V_56 ( V_52 -> V_9 ) ;
F_7 ( & V_1 . V_18 ) ;
if ( V_5 )
return V_5 ;
if ( V_52 -> V_21 -> V_57 )
V_52 -> V_21 -> V_57 ( V_52 -> V_12 ) ;
if ( V_2 -> V_26 == V_27 )
F_37 ( V_2 ) ;
F_38 ( V_52 -> V_9 , V_27 ) ;
V_52 -> V_2 = true ;
return 0 ;
}
static bool F_45 ( void )
{
struct V_6 * V_7 ;
F_3 (client, &vgasr_priv.clients, list) {
if ( ! V_7 -> V_21 -> V_58 ( V_7 -> V_12 ) ) {
F_46 ( L_11 , V_7 -> V_9 ) ;
return false ;
}
}
return true ;
}
static T_1
F_47 ( struct V_47 * V_59 , const char T_2 * V_60 ,
T_3 V_61 , T_4 * V_62 )
{
char V_63 [ 64 ] ;
int V_5 ;
bool V_64 = false , V_58 ;
bool V_65 = false ;
enum V_22 V_33 = V_10 ;
struct V_6 * V_7 = NULL ;
if ( V_61 > 63 )
V_61 = 63 ;
if ( F_48 ( V_63 , V_60 , V_61 ) )
return - V_66 ;
F_6 ( & V_16 ) ;
if ( ! V_1 . V_2 ) {
V_61 = - V_17 ;
goto V_67;
}
if ( strncmp ( V_63 , L_12 , 3 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_49 ( V_7 ) )
continue;
if ( V_7 -> V_23 )
continue;
F_38 ( V_7 -> V_9 , V_50 ) ;
if ( V_7 -> V_26 == V_27 )
F_37 ( V_7 ) ;
}
goto V_67;
}
if ( strncmp ( V_63 , L_13 , 2 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_49 ( V_7 ) )
continue;
if ( V_7 -> V_23 )
continue;
if ( V_7 -> V_26 == V_50 )
F_36 ( V_7 ) ;
F_38 ( V_7 -> V_9 , V_27 ) ;
}
goto V_67;
}
if ( strncmp ( V_63 , L_14 , 4 ) == 0 ) {
V_33 = V_68 ;
V_64 = true ;
}
if ( strncmp ( V_63 , L_15 , 4 ) == 0 ) {
V_33 = V_45 ;
V_64 = true ;
}
if ( strncmp ( V_63 , L_5 , 3 ) == 0 )
V_33 = V_68 ;
if ( strncmp ( V_63 , L_4 , 3 ) == 0 )
V_33 = V_45 ;
if ( strncmp ( V_63 , L_16 , 4 ) == 0 ) {
V_65 = true ;
V_33 = V_68 ;
}
if ( strncmp ( V_63 , L_17 , 4 ) == 0 ) {
V_65 = true ;
V_33 = V_45 ;
}
if ( V_33 == V_10 )
goto V_67;
V_7 = F_20 ( & V_1 . V_29 , V_33 ) ;
if ( ! V_7 )
goto V_67;
V_1 . V_69 = false ;
if ( V_65 ) {
F_6 ( & V_1 . V_18 ) ;
V_5 = V_1 . V_4 -> V_56 ( V_33 ) ;
F_7 ( & V_1 . V_18 ) ;
goto V_67;
}
if ( V_7 -> V_2 )
goto V_67;
V_58 = F_45 () ;
if ( V_58 == false && V_64 == false )
goto V_67;
if ( V_58 ) {
V_5 = F_39 ( V_7 ) ;
if ( V_5 )
F_46 ( L_18 , V_5 ) ;
V_5 = F_41 ( V_7 ) ;
if ( V_5 )
F_46 ( L_19 , V_5 ) ;
} else {
F_8 ( L_20 , V_7 -> V_9 ) ;
V_1 . V_69 = true ;
V_1 . V_70 = V_33 ;
V_5 = F_39 ( V_7 ) ;
if ( V_5 )
F_46 ( L_21 , V_5 ) ;
}
V_67:
F_7 ( & V_16 ) ;
return V_61 ;
}
static void F_10 ( struct V_1 * V_71 )
{
F_50 ( V_71 -> V_72 ) ;
V_71 -> V_72 = NULL ;
F_50 ( V_71 -> V_73 ) ;
V_71 -> V_73 = NULL ;
}
static int F_4 ( struct V_1 * V_71 )
{
static const char V_74 [] = L_22 ;
if ( V_71 -> V_73 )
return 0 ;
V_71 -> V_73 = F_51 ( L_23 , NULL ) ;
if ( ! V_71 -> V_73 ) {
F_46 ( L_24 , V_74 ) ;
goto V_75;
}
V_71 -> V_72 = F_52 ( L_25 , 0644 ,
V_71 -> V_73 , NULL ,
& V_76 ) ;
if ( ! V_71 -> V_72 ) {
F_46 ( L_26 , V_74 ) ;
goto V_75;
}
return 0 ;
V_75:
F_10 ( V_71 ) ;
return - 1 ;
}
int F_53 ( void )
{
struct V_6 * V_7 ;
int V_5 ;
int V_77 = - V_17 ;
F_6 ( & V_16 ) ;
if ( ! V_1 . V_69 )
goto V_77;
F_8 ( L_27 ,
V_1 . V_70 ) ;
V_7 = F_20 ( & V_1 . V_29 ,
V_1 . V_70 ) ;
if ( ! V_7 || ! F_45 () )
goto V_77;
V_5 = F_41 ( V_7 ) ;
if ( V_5 )
F_46 ( L_28 , V_5 ) ;
V_1 . V_69 = false ;
V_77 = 0 ;
V_77:
F_7 ( & V_16 ) ;
return V_77 ;
}
static void F_54 ( struct V_19 * V_12 ,
enum V_34 V_51 )
{
struct V_6 * V_7 ;
if ( ! V_1 . V_4 -> V_48 )
return;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( ! V_7 )
return;
if ( ! V_7 -> V_23 )
return;
V_1 . V_4 -> V_48 ( V_7 -> V_9 , V_51 ) ;
}
void F_55 ( struct V_19 * V_12 ,
enum V_34 V_78 )
{
struct V_6 * V_7 ;
F_6 ( & V_16 ) ;
V_7 = F_19 ( & V_1 . V_29 , V_12 ) ;
if ( ! V_7 || ! V_7 -> V_23 ) {
F_7 ( & V_16 ) ;
return;
}
V_7 -> V_26 = V_78 ;
F_38 ( V_7 -> V_9 , V_78 ) ;
F_7 ( & V_16 ) ;
}
static int F_56 ( struct V_79 * V_80 )
{
struct V_19 * V_12 = F_57 ( V_80 ) ;
int V_5 ;
V_5 = V_80 -> V_81 -> V_82 -> V_83 ( V_80 ) ;
if ( V_5 )
return V_5 ;
F_6 ( & V_16 ) ;
if ( V_1 . V_4 -> V_56 ) {
F_6 ( & V_1 . V_18 ) ;
V_1 . V_4 -> V_56 ( V_68 ) ;
F_7 ( & V_1 . V_18 ) ;
}
F_54 ( V_12 , V_50 ) ;
F_7 ( & V_16 ) ;
return 0 ;
}
static int F_58 ( struct V_79 * V_80 )
{
struct V_19 * V_12 = F_57 ( V_80 ) ;
int V_5 ;
F_6 ( & V_16 ) ;
F_54 ( V_12 , V_27 ) ;
F_7 ( & V_16 ) ;
V_5 = V_80 -> V_81 -> V_82 -> V_84 ( V_80 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
int F_59 ( struct V_79 * V_80 ,
struct V_85 * V_86 )
{
if ( V_80 -> V_81 && V_80 -> V_81 -> V_82 ) {
V_86 -> V_21 = * V_80 -> V_81 -> V_82 ;
V_86 -> V_21 . V_83 = F_56 ;
V_86 -> V_21 . V_84 = F_58 ;
F_60 ( V_80 , V_86 ) ;
return 0 ;
}
F_60 ( V_80 , NULL ) ;
return - V_17 ;
}
void F_61 ( struct V_79 * V_80 )
{
F_60 ( V_80 , NULL ) ;
}
static int F_62 ( struct V_79 * V_80 )
{
struct V_19 * V_12 = F_57 ( V_80 ) ;
struct V_6 * V_7 ;
struct V_79 * V_87 = NULL ;
int V_5 ;
F_6 ( & V_16 ) ;
F_3 (client, &vgasr_priv.clients, list) {
if ( F_63 ( V_7 -> V_12 -> V_88 ) == F_63 ( V_12 -> V_88 ) &&
F_15 ( V_7 ) ) {
V_87 = & V_7 -> V_12 -> V_80 ;
break;
}
}
F_7 ( & V_16 ) ;
if ( V_87 ) {
V_5 = F_64 ( V_87 ) ;
if ( V_5 && V_5 != 1 )
return V_5 ;
}
V_5 = V_80 -> V_81 -> V_82 -> V_84 ( V_80 ) ;
if ( V_87 ) {
F_65 ( V_87 ) ;
F_66 ( V_87 ) ;
}
return V_5 ;
}
int
F_67 ( struct V_79 * V_80 ,
struct V_85 * V_86 )
{
if ( V_80 -> V_81 && V_80 -> V_81 -> V_82 ) {
V_86 -> V_21 = * V_80 -> V_81 -> V_82 ;
V_86 -> V_21 . V_84 =
F_62 ;
F_60 ( V_80 , V_86 ) ;
return 0 ;
}
F_60 ( V_80 , NULL ) ;
return - V_17 ;
}
