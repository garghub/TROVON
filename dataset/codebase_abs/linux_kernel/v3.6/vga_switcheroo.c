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
int V_9 , bool V_2 )
{
struct V_6 * V_7 ;
V_7 = F_13 ( sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return - V_20 ;
V_7 -> V_21 = V_22 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_2 = V_2 ;
F_6 ( & V_13 ) ;
F_14 ( & V_7 -> V_23 , & V_1 . V_24 ) ;
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
const struct V_17 * V_18 )
{
return F_12 ( V_11 , V_18 , - 1 ,
V_11 == F_17 () ) ;
}
int F_18 ( struct V_16 * V_11 ,
const struct V_17 * V_18 ,
int V_9 , bool V_2 )
{
return F_12 ( V_11 , V_18 , V_9 | V_25 , V_2 ) ;
}
static struct V_6 *
F_19 ( struct V_26 * V_27 , struct V_16 * V_11 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_11 == V_11 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_20 ( struct V_26 * V_27 , int V_28 )
{
struct V_6 * V_7 ;
F_3 (client, head, list)
if ( V_7 -> V_9 == V_28 )
return V_7 ;
return NULL ;
}
static struct V_6 *
F_21 ( struct V_26 * V_27 )
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
V_7 = F_19 ( & V_1 . V_24 , V_11 ) ;
if ( ! V_7 )
return V_29 ;
if ( ! V_1 . V_2 )
return V_30 ;
return V_7 -> V_21 ;
}
void F_23 ( struct V_16 * V_11 )
{
struct V_6 * V_7 ;
F_6 ( & V_13 ) ;
V_7 = F_19 ( & V_1 . V_24 , V_11 ) ;
if ( V_7 ) {
if ( F_15 ( V_7 ) )
V_1 . V_3 -- ;
F_24 ( & V_7 -> V_23 ) ;
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
struct V_31 * V_32 )
{
struct V_6 * V_7 ;
F_6 ( & V_13 ) ;
V_7 = F_19 ( & V_1 . V_24 , V_11 ) ;
if ( V_7 )
V_7 -> V_31 = V_32 ;
F_7 ( & V_13 ) ;
}
static int F_27 ( struct V_33 * V_34 , void * V_35 )
{
struct V_6 * V_7 ;
int V_36 = 0 ;
F_6 ( & V_13 ) ;
F_3 (client, &vgasr_priv.clients, list) {
F_28 ( V_34 , L_3 , V_36 ,
V_28 ( V_7 ) == V_37 ? L_4 : L_5 ,
F_15 ( V_7 ) ? L_6 : L_7 ,
V_7 -> V_2 ? '+' : ' ' ,
V_7 -> V_21 ? L_8 : L_9 ,
F_29 ( V_7 -> V_11 ) ) ;
V_36 ++ ;
}
F_7 ( & V_13 ) ;
return 0 ;
}
static int F_30 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_31 ( V_39 , F_27 , NULL ) ;
}
static int F_32 ( struct V_6 * V_7 )
{
if ( V_1 . V_4 -> V_40 )
V_1 . V_4 -> V_40 ( V_7 -> V_9 , V_22 ) ;
V_7 -> V_18 -> V_41 ( V_7 -> V_11 , V_22 ) ;
V_7 -> V_21 = V_22 ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 )
{
V_7 -> V_18 -> V_41 ( V_7 -> V_11 , V_42 ) ;
if ( V_1 . V_4 -> V_40 )
V_1 . V_4 -> V_40 ( V_7 -> V_9 , V_42 ) ;
V_7 -> V_21 = V_42 ;
return 0 ;
}
static void F_34 ( int V_9 , int V_43 )
{
struct V_6 * V_7 ;
V_7 = F_20 ( & V_1 . V_24 , V_9 | V_25 ) ;
if ( V_7 && V_7 -> V_21 != V_43 ) {
V_7 -> V_18 -> V_41 ( V_7 -> V_11 , V_43 ) ;
V_7 -> V_21 = V_43 ;
}
}
static int F_35 ( struct V_6 * V_44 )
{
struct V_6 * V_2 ;
V_2 = F_21 ( & V_1 . V_24 ) ;
if ( ! V_2 )
return 0 ;
if ( V_44 -> V_21 == V_42 )
F_32 ( V_44 ) ;
F_36 ( V_44 -> V_11 ) ;
return 0 ;
}
static int F_37 ( struct V_6 * V_44 )
{
int V_5 ;
struct V_6 * V_2 ;
V_2 = F_21 ( & V_1 . V_24 ) ;
if ( ! V_2 )
return 0 ;
V_2 -> V_2 = false ;
F_34 ( V_2 -> V_9 , V_42 ) ;
if ( V_44 -> V_31 ) {
struct V_45 V_46 ;
V_46 . V_32 = V_44 -> V_31 ;
F_38 ( V_47 , & V_46 ) ;
}
V_5 = V_1 . V_4 -> V_48 ( V_44 -> V_9 ) ;
if ( V_5 )
return V_5 ;
if ( V_44 -> V_18 -> V_49 )
V_44 -> V_18 -> V_49 ( V_44 -> V_11 ) ;
if ( V_2 -> V_21 == V_22 )
F_33 ( V_2 ) ;
F_34 ( V_44 -> V_9 , V_22 ) ;
V_44 -> V_2 = true ;
return 0 ;
}
static bool F_39 ( void )
{
struct V_6 * V_7 ;
F_3 (client, &vgasr_priv.clients, list) {
if ( ! V_7 -> V_18 -> V_50 ( V_7 -> V_11 ) ) {
F_8 ( V_51 L_10 , V_7 -> V_9 ) ;
return false ;
}
}
return true ;
}
static T_1
F_40 ( struct V_39 * V_52 , const char T_2 * V_53 ,
T_3 V_54 , T_4 * V_55 )
{
char V_56 [ 64 ] ;
const char * V_57 ;
int V_5 ;
bool V_58 = false , V_50 ;
bool V_59 = false ;
int V_28 = - 1 ;
struct V_6 * V_7 = NULL ;
if ( V_54 > 63 )
V_54 = 63 ;
if ( F_41 ( V_56 , V_53 , V_54 ) )
return - V_60 ;
F_6 ( & V_13 ) ;
if ( ! V_1 . V_2 ) {
V_54 = - V_14 ;
goto V_61;
}
if ( strncmp ( V_56 , L_11 , 3 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_42 ( V_7 ) )
continue;
F_34 ( V_7 -> V_9 , V_42 ) ;
if ( V_7 -> V_21 == V_22 )
F_33 ( V_7 ) ;
}
goto V_61;
}
if ( strncmp ( V_56 , L_12 , 2 ) == 0 ) {
F_3 (client, &vgasr_priv.clients, list) {
if ( V_7 -> V_2 || F_42 ( V_7 ) )
continue;
if ( V_7 -> V_21 == V_42 )
F_32 ( V_7 ) ;
F_34 ( V_7 -> V_9 , V_22 ) ;
}
goto V_61;
}
if ( strncmp ( V_56 , L_13 , 4 ) == 0 ) {
V_28 = V_62 ;
V_58 = true ;
}
if ( strncmp ( V_56 , L_14 , 4 ) == 0 ) {
V_28 = V_37 ;
V_58 = true ;
}
if ( strncmp ( V_56 , L_5 , 3 ) == 0 )
V_28 = V_62 ;
if ( strncmp ( V_56 , L_4 , 3 ) == 0 )
V_28 = V_37 ;
if ( strncmp ( V_56 , L_15 , 4 ) == 0 ) {
V_59 = true ;
V_28 = V_62 ;
}
if ( strncmp ( V_56 , L_16 , 4 ) == 0 ) {
V_59 = true ;
V_28 = V_37 ;
}
if ( V_28 == - 1 )
goto V_61;
V_7 = F_20 ( & V_1 . V_24 , V_28 ) ;
if ( ! V_7 )
goto V_61;
V_1 . V_63 = false ;
if ( V_59 ) {
V_5 = V_1 . V_4 -> V_48 ( V_28 ) ;
goto V_61;
}
if ( V_7 -> V_2 )
goto V_61;
V_50 = F_39 () ;
if ( V_50 == false && V_58 == false )
goto V_61;
if ( V_50 ) {
V_57 = F_29 ( V_7 -> V_11 ) ;
V_5 = F_35 ( V_7 ) ;
if ( V_5 )
F_8 ( V_51 L_17 , V_5 ) ;
V_5 = F_37 ( V_7 ) ;
if ( V_5 )
F_8 ( V_51 L_18 , V_5 ) ;
} else {
F_8 ( V_15 L_19 , V_7 -> V_9 ) ;
V_1 . V_63 = true ;
V_1 . V_64 = V_28 ;
V_5 = F_35 ( V_7 ) ;
if ( V_5 )
F_8 ( V_51 L_20 , V_5 ) ;
}
V_61:
F_7 ( & V_13 ) ;
return V_54 ;
}
static void F_11 ( struct V_1 * V_65 )
{
if ( V_65 -> V_66 ) {
F_43 ( V_65 -> V_66 ) ;
V_65 -> V_66 = NULL ;
}
if ( V_65 -> V_67 ) {
F_43 ( V_65 -> V_67 ) ;
V_65 -> V_67 = NULL ;
}
}
static int F_4 ( struct V_1 * V_65 )
{
if ( V_65 -> V_67 )
return 0 ;
V_65 -> V_67 = F_44 ( L_21 , NULL ) ;
if ( ! V_65 -> V_67 ) {
F_8 ( V_51 L_22 ) ;
goto V_68;
}
V_65 -> V_66 = F_45 ( L_23 , 0644 ,
V_65 -> V_67 , NULL , & V_69 ) ;
if ( ! V_65 -> V_66 ) {
F_8 ( V_51 L_24 ) ;
goto V_68;
}
return 0 ;
V_68:
F_11 ( V_65 ) ;
return - 1 ;
}
int F_46 ( void )
{
struct V_6 * V_7 ;
const char * V_57 ;
int V_5 ;
int V_70 = - V_14 ;
F_6 ( & V_13 ) ;
if ( ! V_1 . V_63 )
goto V_70;
F_8 ( V_15 L_25 , V_1 . V_64 ) ;
V_7 = F_20 ( & V_1 . V_24 ,
V_1 . V_64 ) ;
if ( ! V_7 || ! F_39 () )
goto V_70;
V_57 = F_29 ( V_7 -> V_11 ) ;
V_5 = F_37 ( V_7 ) ;
if ( V_5 )
F_8 ( V_51 L_26 , V_5 ) ;
V_1 . V_63 = false ;
V_70 = 0 ;
V_70:
F_7 ( & V_13 ) ;
return V_70 ;
}
