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
F_8 ( V_15 L_1 ) ;
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
F_10 ( L_2 ) ;
F_11 ( & V_1 ) ;
V_1 . V_2 = false ;
}
F_7 ( & V_13 ) ;
}
static int F_12 ( struct V_16 * V_11 ,
const struct V_17 * V_18 ,
int V_9 , bool V_2 , bool V_19 )
{
struct V_6 * V_7 ;
V_7 = F_13 ( sizeof( * V_7 ) , V_20 ) ;
if ( ! V_7 )
return - V_21 ;
V_7 -> V_22 = V_23 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_19 = V_19 ;
F_6 ( & V_13 ) ;
F_14 ( & V_7 -> V_24 , & V_1 . V_25 ) ;
if ( F_15 ( V_7 ) )
V_1 . V_3 ++ ;
if ( F_1 () ) {
F_8 ( V_15 L_1 ) ;
F_2 () ;
}
F_7 ( & V_13 ) ;
return 0 ;
}
int F_16 ( struct V_16 * V_11 ,
const struct V_17 * V_18 ,
bool V_19 )
{
return F_12 ( V_11 , V_18 , - 1 ,
V_11 == F_17 () , V_19 ) ;
}
int F_18 ( struct V_16 * V_11 ,
const struct V_17 * V_18 ,
int V_9 , bool V_2 )
{
return F_12 ( V_11 , V_18 , V_9 | V_26 , V_2 , false ) ;
}
static struct V_6 *
F_19 ( struct V_27 * V_28 , struct V_16 * V_11 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_11 == V_11 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_20 ( struct V_27 * V_28 , int V_29 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_9 == V_29 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_21 ( struct V_27 * V_28 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_2 && F_15 ( V_7 ) )
return V_7 ;
return NULL ;
}
int F_22 ( struct V_16 * V_11 )
{
struct V_6 * V_7 ;
V_7 = F_19 ( & V_1 . V_25 , V_11 ) ;
if ( ! V_7 )
return V_30 ;
if ( ! V_1 . V_2 )
return V_31 ;
return V_7 -> V_22 ;
}
void F_23 ( struct V_16 * V_11 )
{
struct V_6 * V_7 ;
F_6 ( & V_13 ) ;
V_7 = F_19 ( & V_1 . V_25 , V_11 ) ;
if ( V_7 ) {
if ( F_15 ( V_7 ) )
V_1 . V_3 -- ;
F_24 ( & V_7 -> V_24 ) ;
F_25 ( V_7 ) ;
}
if ( V_1 . V_2 && V_1 . V_3 < 2 ) {
F_8 ( V_15 L_2 ) ;
F_11 ( & V_1 ) ;
V_1 . V_2 = false ;
}
F_7 ( & V_13 ) ;
}
void F_26 ( struct V_16 * V_11 ,
struct V_32 * V_33 )
{
struct V_6 * V_7 ;
F_6 ( & V_13 ) ;
V_7 = F_19 ( & V_1 . V_25 , V_11 ) ;
if ( V_7 )
V_7 -> V_32 = V_33 ;
F_7 ( & V_13 ) ;
}
static int F_27 ( struct V_34 * V_35 , void * V_36 )
{
struct V_6 * V_7 ;
int V_37 = 0 ;
F_6 ( & V_13 ) ;
F_3 (client, &vgasr_priv.clients, list) {
F_28 ( V_35 , L_3 , V_37 ,
V_29 ( V_7 ) == V_38 ? L_4 : L_5 ,
F_15 ( V_7 ) ? L_6 : L_7 ,
V_7 -> V_2 ? '+' : ' ' ,
V_7 -> V_19 ? L_8 : L_6 ,
V_7 -> V_22 ? L_9 : L_10 ,
F_29 ( V_7 -> V_11 ) ) ;
V_37 ++ ;
}
F_7 ( & V_13 ) ;
return 0 ;
}
static int F_30 ( struct V_39 * V_39 , struct V_40 * V_40 )
{
return F_31 ( V_40 , F_27 , NULL ) ;
}
static int F_32 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 )
return 0 ;
if ( V_1 . V_4 -> V_41 )
V_1 . V_4 -> V_41 ( V_7 -> V_9 , V_23 ) ;
V_7 -> V_18 -> V_42 ( V_7 -> V_11 , V_23 ) ;
V_7 -> V_22 = V_23 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
if ( V_7 -> V_19 )
return 0 ;
V_7 -> V_18 -> V_42 ( V_7 -> V_11 , V_43 ) ;
if ( V_1 . V_4 -> V_41 )
V_1 . V_4 -> V_41 ( V_7 -> V_9 , V_43 ) ;
V_7 -> V_22 = V_43 ;
return 0 ;
}
static void F_34 ( int V_9 , int V_44 )
{
struct V_6 * V_7 ;
V_7 = F_20 ( & V_1 . V_25 , V_9 | V_26 ) ;
if ( V_7 && V_7 -> V_22 != V_44 ) {
V_7 -> V_18 -> V_42 ( V_7 -> V_11 , V_44 ) ;
V_7 -> V_22 = V_44 ;
}
}
static int F_35 ( struct V_6 * V_45 )
{
struct V_6 * V_2 ;
V_2 = F_21 ( & V_1 . V_25 ) ;
if ( ! V_2 )
return 0 ;
if ( V_45 -> V_22 == V_43 )
F_32 ( V_45 ) ;
F_36 ( V_45 -> V_11 ) ;
return 0 ;
}
static int F_37 ( struct V_6 * V_45 )
{
int V_5 ;
struct V_6 * V_2 ;
V_2 = F_21 ( & V_1 . V_25 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_2 = false ;
F_34 ( V_2 -> V_9 , V_43 ) ;
if ( V_45 -> V_32 ) {
struct V_46 V_47 ;
F_38 () ;
V_47 . V_33 = V_45 -> V_32 ;
F_39 ( V_48 , & V_47 ) ;
F_40 () ;
}
V_5 = V_1 . V_4 -> V_49 ( V_45 -> V_9 ) ;
if ( V_5 )
return V_5 ;
if ( V_45 -> V_18 -> V_50 )
V_45 -> V_18 -> V_50 ( V_45 -> V_11 ) ;
if ( V_2 -> V_22 == V_23 )
F_33 ( V_2 ) ;
F_34 ( V_45 -> V_9 , V_23 ) ;
V_45 -> V_2 = true ;
return 0 ;
}
static bool F_41 ( void )
{
struct V_6 * V_7 ;
F_3 (client, &vgasr_priv.clients, list) {
if ( ! V_7 -> V_18 -> V_51 ( V_7 -> V_11 ) ) {
F_8 ( V_52 L_11 , V_7 -> V_9 ) ;
return false ;
}
}
return true ;
}
static T_1
F_42 ( struct V_40 * V_53 , const char T_2 * V_54 ,
T_3 V_55 , T_4 * V_56 )
{
char V_57 [ 64 ] ;
int V_5 ;
bool V_58 = false , V_51 ;
bool V_59 = false ;
int V_29 = - 1 ;
struct V_6 * V_7 = NULL ;
if ( V_55 > 63 )
V_55 = 63 ;
if ( F_43 ( V_57 , V_54 , V_55 ) )
return - V_60 ;
F_6 ( & V_13 ) ;
if ( ! V_1 . V_2 ) {
V_55 = - V_14 ;
goto V_61;
}
if ( strncmp ( V_57 , L_12 , 3 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_44 ( V_7 ) )
continue;
if ( V_7 -> V_19 )
continue;
F_34 ( V_7 -> V_9 , V_43 ) ;
if ( V_7 -> V_22 == V_23 )
F_33 ( V_7 ) ;
}
goto V_61;
}
if ( strncmp ( V_57 , L_13 , 2 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_44 ( V_7 ) )
continue;
if ( V_7 -> V_19 )
continue;
if ( V_7 -> V_22 == V_43 )
F_32 ( V_7 ) ;
F_34 ( V_7 -> V_9 , V_23 ) ;
}
goto V_61;
}
if ( strncmp ( V_57 , L_14 , 4 ) == 0 ) {
V_29 = V_62 ;
V_58 = true ;
}
if ( strncmp ( V_57 , L_15 , 4 ) == 0 ) {
V_29 = V_38 ;
V_58 = true ;
}
if ( strncmp ( V_57 , L_5 , 3 ) == 0 )
V_29 = V_62 ;
if ( strncmp ( V_57 , L_4 , 3 ) == 0 )
V_29 = V_38 ;
if ( strncmp ( V_57 , L_16 , 4 ) == 0 ) {
V_59 = true ;
V_29 = V_62 ;
}
if ( strncmp ( V_57 , L_17 , 4 ) == 0 ) {
V_59 = true ;
V_29 = V_38 ;
}
if ( V_29 == - 1 )
goto V_61;
V_7 = F_20 ( & V_1 . V_25 , V_29 ) ;
if ( ! V_7 )
goto V_61;
V_1 . V_63 = false ;
if ( V_59 ) {
V_5 = V_1 . V_4 -> V_49 ( V_29 ) ;
goto V_61;
}
if ( V_7 -> V_2 )
goto V_61;
V_51 = F_41 () ;
if ( V_51 == false && V_58 == false )
goto V_61;
if ( V_51 ) {
V_5 = F_35 ( V_7 ) ;
if ( V_5 )
F_8 ( V_52 L_18 , V_5 ) ;
V_5 = F_37 ( V_7 ) ;
if ( V_5 )
F_8 ( V_52 L_19 , V_5 ) ;
} else {
F_8 ( V_15 L_20 , V_7 -> V_9 ) ;
V_1 . V_63 = true ;
V_1 . V_64 = V_29 ;
V_5 = F_35 ( V_7 ) ;
if ( V_5 )
F_8 ( V_52 L_21 , V_5 ) ;
}
V_61:
F_7 ( & V_13 ) ;
return V_55 ;
}
static void F_11 ( struct V_1 * V_65 )
{
if ( V_65 -> V_66 ) {
F_45 ( V_65 -> V_66 ) ;
V_65 -> V_66 = NULL ;
}
if ( V_65 -> V_67 ) {
F_45 ( V_65 -> V_67 ) ;
V_65 -> V_67 = NULL ;
}
}
static int F_4 ( struct V_1 * V_65 )
{
if ( V_65 -> V_67 )
return 0 ;
V_65 -> V_67 = F_46 ( L_22 , NULL ) ;
if ( ! V_65 -> V_67 ) {
F_8 ( V_52 L_23 ) ;
goto V_68;
}
V_65 -> V_66 = F_47 ( L_24 , 0644 ,
V_65 -> V_67 , NULL , & V_69 ) ;
if ( ! V_65 -> V_66 ) {
F_8 ( V_52 L_25 ) ;
goto V_68;
}
return 0 ;
V_68:
F_11 ( V_65 ) ;
return - 1 ;
}
int F_48 ( void )
{
struct V_6 * V_7 ;
int V_5 ;
int V_70 = - V_14 ;
F_6 ( & V_13 ) ;
if ( ! V_1 . V_63 )
goto V_70;
F_8 ( V_15 L_26 , V_1 . V_64 ) ;
V_7 = F_20 ( & V_1 . V_25 ,
V_1 . V_64 ) ;
if ( ! V_7 || ! F_41 () )
goto V_70;
V_5 = F_37 ( V_7 ) ;
if ( V_5 )
F_8 ( V_52 L_27 , V_5 ) ;
V_1 . V_63 = false ;
V_70 = 0 ;
V_70:
F_7 ( & V_13 ) ;
return V_70 ;
}
static void F_49 ( struct V_16 * V_11 , enum V_71 V_44 )
{
struct V_6 * V_7 ;
if ( ! V_1 . V_4 -> V_41 )
return;
V_7 = F_19 ( & V_1 . V_25 , V_11 ) ;
if ( ! V_7 )
return;
if ( ! V_7 -> V_19 )
return;
V_1 . V_4 -> V_41 ( V_7 -> V_9 , V_44 ) ;
}
void F_50 ( struct V_16 * V_11 , enum V_71 V_72 )
{
struct V_6 * V_7 ;
V_7 = F_19 ( & V_1 . V_25 , V_11 ) ;
if ( ! V_7 )
return;
if ( ! V_7 -> V_19 )
return;
V_7 -> V_22 = V_72 ;
F_34 ( V_7 -> V_9 , V_72 ) ;
}
static int F_51 ( struct V_73 * V_74 )
{
struct V_16 * V_11 = F_52 ( V_74 ) ;
int V_5 ;
V_5 = V_74 -> V_75 -> V_76 -> V_77 ( V_74 ) ;
if ( V_5 )
return V_5 ;
F_49 ( V_11 , V_43 ) ;
return 0 ;
}
static int F_53 ( struct V_73 * V_74 )
{
struct V_16 * V_11 = F_52 ( V_74 ) ;
int V_5 ;
F_49 ( V_11 , V_23 ) ;
V_5 = V_74 -> V_75 -> V_76 -> V_78 ( V_74 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
int F_54 ( struct V_73 * V_74 , struct V_79 * V_80 )
{
if ( V_74 -> V_75 && V_74 -> V_75 -> V_76 ) {
V_80 -> V_18 = * V_74 -> V_75 -> V_76 ;
V_80 -> V_18 . V_77 = F_51 ;
V_80 -> V_18 . V_78 = F_53 ;
V_74 -> V_81 = V_80 ;
return 0 ;
}
V_74 -> V_81 = NULL ;
return - V_14 ;
}
static int F_55 ( struct V_73 * V_74 )
{
struct V_16 * V_11 = F_52 ( V_74 ) ;
int V_5 ;
struct V_6 * V_7 , * V_82 = NULL ;
F_3 (client, &vgasr_priv.clients, list) {
if ( F_56 ( V_7 -> V_11 -> V_83 ) == F_56 ( V_11 -> V_83 ) && F_15 ( V_7 ) ) {
V_82 = V_7 ;
V_5 = F_57 ( & V_7 -> V_11 -> V_74 ) ;
if ( V_5 ) {
if ( V_5 != 1 )
return V_5 ;
}
break;
}
}
V_5 = V_74 -> V_75 -> V_76 -> V_78 ( V_74 ) ;
if ( V_82 ) {
F_58 ( & V_82 -> V_11 -> V_74 ) ;
F_59 ( & V_82 -> V_11 -> V_74 ) ;
}
return V_5 ;
}
int F_60 ( struct V_73 * V_74 , struct V_79 * V_80 )
{
if ( V_74 -> V_75 && V_74 -> V_75 -> V_76 ) {
V_80 -> V_18 = * V_74 -> V_75 -> V_76 ;
V_80 -> V_18 . V_78 = F_55 ;
V_74 -> V_81 = V_80 ;
return 0 ;
}
V_74 -> V_81 = NULL ;
return - V_14 ;
}
