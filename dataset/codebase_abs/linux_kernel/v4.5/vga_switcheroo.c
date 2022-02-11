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
int F_5 ( const struct V_13 * V_4 )
{
F_6 ( & V_14 ) ;
if ( V_1 . V_4 ) {
F_7 ( & V_14 ) ;
return - V_15 ;
}
V_1 . V_4 = V_4 ;
if ( F_1 () ) {
F_8 ( L_1 ) ;
F_2 () ;
}
F_7 ( & V_14 ) ;
return 0 ;
}
void F_9 ( void )
{
F_6 ( & V_14 ) ;
V_1 . V_4 = NULL ;
if ( V_1 . V_2 ) {
F_8 ( L_2 ) ;
F_10 ( & V_1 ) ;
V_1 . V_2 = false ;
}
F_7 ( & V_14 ) ;
}
static int F_11 ( struct V_16 * V_12 ,
const struct V_17 * V_18 ,
enum V_19 V_9 , bool V_2 ,
bool V_20 )
{
struct V_6 * V_7 ;
V_7 = F_12 ( sizeof( * V_7 ) , V_21 ) ;
if ( ! V_7 )
return - V_22 ;
V_7 -> V_23 = V_24 ;
V_7 -> V_12 = V_12 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_20 = V_20 ;
F_6 ( & V_14 ) ;
F_13 ( & V_7 -> V_25 , & V_1 . V_26 ) ;
if ( F_14 ( V_7 ) )
V_1 . V_3 ++ ;
if ( F_1 () ) {
F_8 ( L_1 ) ;
F_2 () ;
}
F_7 ( & V_14 ) ;
return 0 ;
}
int F_15 ( struct V_16 * V_12 ,
const struct V_17 * V_18 ,
bool V_20 )
{
return F_11 ( V_12 , V_18 , V_10 ,
V_12 == F_16 () ,
V_20 ) ;
}
int F_17 ( struct V_16 * V_12 ,
const struct V_17 * V_18 ,
enum V_19 V_9 )
{
return F_11 ( V_12 , V_18 , V_9 | V_27 , false , false ) ;
}
static struct V_6 *
F_18 ( struct V_28 * V_29 , struct V_16 * V_12 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_12 == V_12 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_19 ( struct V_28 * V_29 ,
enum V_19 V_30 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_9 == V_30 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_20 ( struct V_28 * V_29 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_2 )
return V_7 ;
return NULL ;
}
enum V_31 F_21 ( struct V_16 * V_12 )
{
struct V_6 * V_7 ;
enum V_31 V_5 ;
F_6 ( & V_14 ) ;
V_7 = F_18 ( & V_1 . V_26 , V_12 ) ;
if ( ! V_7 )
V_5 = V_32 ;
else
V_5 = V_7 -> V_23 ;
F_7 ( & V_14 ) ;
return V_5 ;
}
void F_22 ( struct V_16 * V_12 )
{
struct V_6 * V_7 ;
F_6 ( & V_14 ) ;
V_7 = F_18 ( & V_1 . V_26 , V_12 ) ;
if ( V_7 ) {
if ( F_14 ( V_7 ) )
V_1 . V_3 -- ;
F_23 ( & V_7 -> V_25 ) ;
F_24 ( V_7 ) ;
}
if ( V_1 . V_2 && V_1 . V_3 < 2 ) {
F_8 ( L_2 ) ;
F_10 ( & V_1 ) ;
V_1 . V_2 = false ;
}
F_7 ( & V_14 ) ;
}
void F_25 ( struct V_16 * V_12 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 ;
F_6 ( & V_14 ) ;
V_7 = F_18 ( & V_1 . V_26 , V_12 ) ;
if ( V_7 )
V_7 -> V_33 = V_34 ;
F_7 ( & V_14 ) ;
}
static int F_26 ( struct V_35 * V_36 , void * V_37 )
{
struct V_6 * V_7 ;
int V_38 = 0 ;
F_6 ( & V_14 ) ;
F_3 (client, &vgasr_priv.clients, list) {
F_27 ( V_36 , L_3 , V_38 ,
V_30 ( V_7 ) == V_39 ? L_4 :
L_5 ,
F_14 ( V_7 ) ? L_6 : L_7 ,
V_7 -> V_2 ? '+' : ' ' ,
V_7 -> V_20 ? L_8 : L_6 ,
V_7 -> V_23 ? L_9 : L_10 ,
F_28 ( V_7 -> V_12 ) ) ;
V_38 ++ ;
}
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_29 ( struct V_40 * V_40 , struct V_41 * V_41 )
{
return F_30 ( V_41 , F_26 , NULL ) ;
}
static int F_31 ( struct V_6 * V_7 )
{
if ( V_7 -> V_20 )
return 0 ;
if ( V_1 . V_4 -> V_42 )
V_1 . V_4 -> V_42 ( V_7 -> V_9 , V_24 ) ;
V_7 -> V_18 -> V_43 ( V_7 -> V_12 , V_24 ) ;
V_7 -> V_23 = V_24 ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 )
{
if ( V_7 -> V_20 )
return 0 ;
V_7 -> V_18 -> V_43 ( V_7 -> V_12 , V_44 ) ;
if ( V_1 . V_4 -> V_42 )
V_1 . V_4 -> V_42 ( V_7 -> V_9 , V_44 ) ;
V_7 -> V_23 = V_44 ;
return 0 ;
}
static void F_33 ( enum V_19 V_9 ,
enum V_31 V_45 )
{
struct V_6 * V_7 ;
V_7 = F_19 ( & V_1 . V_26 , V_9 | V_27 ) ;
if ( V_7 && V_7 -> V_23 != V_45 ) {
V_7 -> V_18 -> V_43 ( V_7 -> V_12 , V_45 ) ;
V_7 -> V_23 = V_45 ;
}
}
static int F_34 ( struct V_6 * V_46 )
{
struct V_6 * V_2 ;
V_2 = F_20 ( & V_1 . V_26 ) ;
if ( ! V_2 )
return 0 ;
if ( V_46 -> V_23 == V_44 )
F_31 ( V_46 ) ;
F_35 ( V_46 -> V_12 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_46 )
{
int V_5 ;
struct V_6 * V_2 ;
V_2 = F_20 ( & V_1 . V_26 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_2 = false ;
F_33 ( V_2 -> V_9 , V_44 ) ;
if ( V_46 -> V_33 ) {
struct V_47 V_48 ;
F_37 () ;
V_48 . V_34 = V_46 -> V_33 ;
F_38 ( V_49 , & V_48 ) ;
F_39 () ;
}
V_5 = V_1 . V_4 -> V_50 ( V_46 -> V_9 ) ;
if ( V_5 )
return V_5 ;
if ( V_46 -> V_18 -> V_51 )
V_46 -> V_18 -> V_51 ( V_46 -> V_12 ) ;
if ( V_2 -> V_23 == V_24 )
F_32 ( V_2 ) ;
F_33 ( V_46 -> V_9 , V_24 ) ;
V_46 -> V_2 = true ;
return 0 ;
}
static bool F_40 ( void )
{
struct V_6 * V_7 ;
F_3 (client, &vgasr_priv.clients, list) {
if ( ! V_7 -> V_18 -> V_52 ( V_7 -> V_12 ) ) {
F_41 ( L_11 , V_7 -> V_9 ) ;
return false ;
}
}
return true ;
}
static T_1
F_42 ( struct V_41 * V_53 , const char T_2 * V_54 ,
T_3 V_55 , T_4 * V_56 )
{
char V_57 [ 64 ] ;
int V_5 ;
bool V_58 = false , V_52 ;
bool V_59 = false ;
enum V_19 V_30 = V_10 ;
struct V_6 * V_7 = NULL ;
if ( V_55 > 63 )
V_55 = 63 ;
if ( F_43 ( V_57 , V_54 , V_55 ) )
return - V_60 ;
F_6 ( & V_14 ) ;
if ( ! V_1 . V_2 ) {
V_55 = - V_15 ;
goto V_61;
}
if ( strncmp ( V_57 , L_12 , 3 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_44 ( V_7 ) )
continue;
if ( V_7 -> V_20 )
continue;
F_33 ( V_7 -> V_9 , V_44 ) ;
if ( V_7 -> V_23 == V_24 )
F_32 ( V_7 ) ;
}
goto V_61;
}
if ( strncmp ( V_57 , L_13 , 2 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_44 ( V_7 ) )
continue;
if ( V_7 -> V_20 )
continue;
if ( V_7 -> V_23 == V_44 )
F_31 ( V_7 ) ;
F_33 ( V_7 -> V_9 , V_24 ) ;
}
goto V_61;
}
if ( strncmp ( V_57 , L_14 , 4 ) == 0 ) {
V_30 = V_62 ;
V_58 = true ;
}
if ( strncmp ( V_57 , L_15 , 4 ) == 0 ) {
V_30 = V_39 ;
V_58 = true ;
}
if ( strncmp ( V_57 , L_5 , 3 ) == 0 )
V_30 = V_62 ;
if ( strncmp ( V_57 , L_4 , 3 ) == 0 )
V_30 = V_39 ;
if ( strncmp ( V_57 , L_16 , 4 ) == 0 ) {
V_59 = true ;
V_30 = V_62 ;
}
if ( strncmp ( V_57 , L_17 , 4 ) == 0 ) {
V_59 = true ;
V_30 = V_39 ;
}
if ( V_30 == V_10 )
goto V_61;
V_7 = F_19 ( & V_1 . V_26 , V_30 ) ;
if ( ! V_7 )
goto V_61;
V_1 . V_63 = false ;
if ( V_59 ) {
V_5 = V_1 . V_4 -> V_50 ( V_30 ) ;
goto V_61;
}
if ( V_7 -> V_2 )
goto V_61;
V_52 = F_40 () ;
if ( V_52 == false && V_58 == false )
goto V_61;
if ( V_52 ) {
V_5 = F_34 ( V_7 ) ;
if ( V_5 )
F_41 ( L_18 , V_5 ) ;
V_5 = F_36 ( V_7 ) ;
if ( V_5 )
F_41 ( L_19 , V_5 ) ;
} else {
F_8 ( L_20 , V_7 -> V_9 ) ;
V_1 . V_63 = true ;
V_1 . V_64 = V_30 ;
V_5 = F_34 ( V_7 ) ;
if ( V_5 )
F_41 ( L_21 , V_5 ) ;
}
V_61:
F_7 ( & V_14 ) ;
return V_55 ;
}
static void F_10 ( struct V_1 * V_65 )
{
F_45 ( V_65 -> V_66 ) ;
V_65 -> V_66 = NULL ;
F_45 ( V_65 -> V_67 ) ;
V_65 -> V_67 = NULL ;
}
static int F_4 ( struct V_1 * V_65 )
{
static const char V_68 [] = L_22 ;
if ( V_65 -> V_67 )
return 0 ;
V_65 -> V_67 = F_46 ( L_23 , NULL ) ;
if ( ! V_65 -> V_67 ) {
F_41 ( L_24 , V_68 ) ;
goto V_69;
}
V_65 -> V_66 = F_47 ( L_25 , 0644 ,
V_65 -> V_67 , NULL ,
& V_70 ) ;
if ( ! V_65 -> V_66 ) {
F_41 ( L_26 , V_68 ) ;
goto V_69;
}
return 0 ;
V_69:
F_10 ( V_65 ) ;
return - 1 ;
}
int F_48 ( void )
{
struct V_6 * V_7 ;
int V_5 ;
int V_71 = - V_15 ;
F_6 ( & V_14 ) ;
if ( ! V_1 . V_63 )
goto V_71;
F_8 ( L_27 ,
V_1 . V_64 ) ;
V_7 = F_19 ( & V_1 . V_26 ,
V_1 . V_64 ) ;
if ( ! V_7 || ! F_40 () )
goto V_71;
V_5 = F_36 ( V_7 ) ;
if ( V_5 )
F_41 ( L_28 , V_5 ) ;
V_1 . V_63 = false ;
V_71 = 0 ;
V_71:
F_7 ( & V_14 ) ;
return V_71 ;
}
static void F_49 ( struct V_16 * V_12 ,
enum V_31 V_45 )
{
struct V_6 * V_7 ;
if ( ! V_1 . V_4 -> V_42 )
return;
V_7 = F_18 ( & V_1 . V_26 , V_12 ) ;
if ( ! V_7 )
return;
if ( ! V_7 -> V_20 )
return;
V_1 . V_4 -> V_42 ( V_7 -> V_9 , V_45 ) ;
}
void F_50 ( struct V_16 * V_12 ,
enum V_31 V_72 )
{
struct V_6 * V_7 ;
F_6 ( & V_14 ) ;
V_7 = F_18 ( & V_1 . V_26 , V_12 ) ;
if ( ! V_7 || ! V_7 -> V_20 ) {
F_7 ( & V_14 ) ;
return;
}
V_7 -> V_23 = V_72 ;
F_33 ( V_7 -> V_9 , V_72 ) ;
F_7 ( & V_14 ) ;
}
static int F_51 ( struct V_73 * V_74 )
{
struct V_16 * V_12 = F_52 ( V_74 ) ;
int V_5 ;
V_5 = V_74 -> V_75 -> V_76 -> V_77 ( V_74 ) ;
if ( V_5 )
return V_5 ;
F_6 ( & V_14 ) ;
if ( V_1 . V_4 -> V_50 )
V_1 . V_4 -> V_50 ( V_62 ) ;
F_49 ( V_12 , V_44 ) ;
F_7 ( & V_14 ) ;
return 0 ;
}
static int F_53 ( struct V_73 * V_74 )
{
struct V_16 * V_12 = F_52 ( V_74 ) ;
int V_5 ;
F_6 ( & V_14 ) ;
F_49 ( V_12 , V_24 ) ;
F_7 ( & V_14 ) ;
V_5 = V_74 -> V_75 -> V_76 -> V_78 ( V_74 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
int F_54 ( struct V_73 * V_74 ,
struct V_79 * V_80 )
{
if ( V_74 -> V_75 && V_74 -> V_75 -> V_76 ) {
V_80 -> V_18 = * V_74 -> V_75 -> V_76 ;
V_80 -> V_18 . V_77 = F_51 ;
V_80 -> V_18 . V_78 = F_53 ;
F_55 ( V_74 , V_80 ) ;
return 0 ;
}
F_55 ( V_74 , NULL ) ;
return - V_15 ;
}
void F_56 ( struct V_73 * V_74 )
{
F_55 ( V_74 , NULL ) ;
}
static int F_57 ( struct V_73 * V_74 )
{
struct V_16 * V_12 = F_52 ( V_74 ) ;
struct V_6 * V_7 ;
struct V_73 * V_81 = NULL ;
int V_5 ;
F_6 ( & V_14 ) ;
F_3 (client, &vgasr_priv.clients, list) {
if ( F_58 ( V_7 -> V_12 -> V_82 ) == F_58 ( V_12 -> V_82 ) &&
F_14 ( V_7 ) ) {
V_81 = & V_7 -> V_12 -> V_74 ;
break;
}
}
F_7 ( & V_14 ) ;
if ( V_81 ) {
V_5 = F_59 ( V_81 ) ;
if ( V_5 && V_5 != 1 )
return V_5 ;
}
V_5 = V_74 -> V_75 -> V_76 -> V_78 ( V_74 ) ;
if ( V_81 ) {
F_60 ( V_81 ) ;
F_61 ( V_81 ) ;
}
return V_5 ;
}
int
F_62 ( struct V_73 * V_74 ,
struct V_79 * V_80 )
{
if ( V_74 -> V_75 && V_74 -> V_75 -> V_76 ) {
V_80 -> V_18 = * V_74 -> V_75 -> V_76 ;
V_80 -> V_18 . V_78 =
F_57 ;
F_55 ( V_74 , V_80 ) ;
return 0 ;
}
F_55 ( V_74 , NULL ) ;
return - V_15 ;
}
