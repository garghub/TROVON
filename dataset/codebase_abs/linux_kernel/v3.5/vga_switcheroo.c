int F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
if ( V_4 . V_2 ) {
F_3 ( & V_3 ) ;
return - V_5 ;
}
V_4 . V_2 = V_2 ;
F_3 ( & V_3 ) ;
return 0 ;
}
void F_4 ( void )
{
F_2 ( & V_3 ) ;
V_4 . V_2 = NULL ;
F_3 ( & V_3 ) ;
}
static void F_5 ( void )
{
int V_6 ;
struct V_7 * V_8 ;
V_4 . V_2 -> V_9 () ;
F_6 (client, &vgasr_priv.clients, list) {
if ( V_8 -> V_10 != - 1 )
continue;
V_6 = V_4 . V_2 -> V_11 ( V_8 -> V_12 ) ;
if ( V_6 < 0 )
return;
V_8 -> V_10 = V_6 ;
}
F_7 ( & V_4 ) ;
V_4 . V_13 = true ;
}
static int F_8 ( struct V_14 * V_12 ,
const struct V_15 * V_16 ,
int V_10 , bool V_13 )
{
struct V_7 * V_8 ;
V_8 = F_9 ( sizeof( * V_8 ) , V_17 ) ;
if ( ! V_8 )
return - V_18 ;
V_8 -> V_19 = V_20 ;
V_8 -> V_12 = V_12 ;
V_8 -> V_16 = V_16 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = V_13 ;
F_2 ( & V_3 ) ;
F_10 ( & V_8 -> V_21 , & V_4 . V_22 ) ;
if ( F_11 ( V_8 ) )
V_4 . V_23 ++ ;
if ( ! V_4 . V_13 &&
V_4 . V_23 == 2 && V_4 . V_2 ) {
F_12 ( V_24 L_1 ) ;
F_5 () ;
}
F_3 ( & V_3 ) ;
return 0 ;
}
int F_13 ( struct V_14 * V_12 ,
const struct V_15 * V_16 )
{
return F_8 ( V_12 , V_16 , - 1 ,
V_12 == F_14 () ) ;
}
int F_15 ( struct V_14 * V_12 ,
const struct V_15 * V_16 ,
int V_10 , bool V_13 )
{
return F_8 ( V_12 , V_16 , V_10 | V_25 , V_13 ) ;
}
static struct V_7 *
F_16 ( struct V_26 * V_27 , struct V_14 * V_12 )
{
struct V_7 * V_8 ;
F_6 (client, head, list)
if ( V_8 -> V_12 == V_12 )
return V_8 ;
return NULL ;
}
static struct V_7 *
F_17 ( struct V_26 * V_27 , int V_28 )
{
struct V_7 * V_8 ;
F_6 (client, head, list)
if ( V_8 -> V_10 == V_28 )
return V_8 ;
return NULL ;
}
static struct V_7 *
F_18 ( struct V_26 * V_27 )
{
struct V_7 * V_8 ;
F_6 (client, head, list)
if ( V_8 -> V_13 && F_11 ( V_8 ) )
return V_8 ;
return NULL ;
}
int F_19 ( struct V_14 * V_12 )
{
struct V_7 * V_8 ;
V_8 = F_16 ( & V_4 . V_22 , V_12 ) ;
if ( ! V_8 )
return V_29 ;
if ( ! V_4 . V_13 )
return V_30 ;
return V_8 -> V_19 ;
}
void F_20 ( struct V_14 * V_12 )
{
struct V_7 * V_8 ;
F_2 ( & V_3 ) ;
V_8 = F_16 ( & V_4 . V_22 , V_12 ) ;
if ( V_8 ) {
if ( F_11 ( V_8 ) )
V_4 . V_23 -- ;
F_21 ( & V_8 -> V_21 ) ;
F_22 ( V_8 ) ;
}
if ( V_4 . V_13 && V_4 . V_23 < 2 ) {
F_12 ( V_24 L_2 ) ;
F_23 ( & V_4 ) ;
V_4 . V_13 = false ;
}
F_3 ( & V_3 ) ;
}
void F_24 ( struct V_14 * V_12 ,
struct V_31 * V_32 )
{
struct V_7 * V_8 ;
F_2 ( & V_3 ) ;
V_8 = F_16 ( & V_4 . V_22 , V_12 ) ;
if ( V_8 )
V_8 -> V_31 = V_32 ;
F_3 ( & V_3 ) ;
}
static int F_25 ( struct V_33 * V_34 , void * V_35 )
{
struct V_7 * V_8 ;
int V_36 = 0 ;
F_2 ( & V_3 ) ;
F_6 (client, &vgasr_priv.clients, list) {
F_26 ( V_34 , L_3 , V_36 ,
V_28 ( V_8 ) == V_37 ? L_4 : L_5 ,
F_11 ( V_8 ) ? L_6 : L_7 ,
V_8 -> V_13 ? '+' : ' ' ,
V_8 -> V_19 ? L_8 : L_9 ,
F_27 ( V_8 -> V_12 ) ) ;
V_36 ++ ;
}
F_3 ( & V_3 ) ;
return 0 ;
}
static int F_28 ( struct V_38 * V_38 , struct V_39 * V_39 )
{
return F_29 ( V_39 , F_25 , NULL ) ;
}
static int F_30 ( struct V_7 * V_8 )
{
if ( V_4 . V_2 -> V_40 )
V_4 . V_2 -> V_40 ( V_8 -> V_10 , V_20 ) ;
V_8 -> V_16 -> V_41 ( V_8 -> V_12 , V_20 ) ;
V_8 -> V_19 = V_20 ;
return 0 ;
}
static int F_31 ( struct V_7 * V_8 )
{
V_8 -> V_16 -> V_41 ( V_8 -> V_12 , V_42 ) ;
if ( V_4 . V_2 -> V_40 )
V_4 . V_2 -> V_40 ( V_8 -> V_10 , V_42 ) ;
V_8 -> V_19 = V_42 ;
return 0 ;
}
static void F_32 ( int V_10 , int V_43 )
{
struct V_7 * V_8 ;
V_8 = F_17 ( & V_4 . V_22 , V_10 | V_25 ) ;
if ( V_8 && V_8 -> V_19 != V_43 ) {
V_8 -> V_16 -> V_41 ( V_8 -> V_12 , V_43 ) ;
V_8 -> V_19 = V_43 ;
}
}
static int F_33 ( struct V_7 * V_44 )
{
struct V_7 * V_13 ;
V_13 = F_18 ( & V_4 . V_22 ) ;
if ( ! V_13 )
return 0 ;
if ( V_44 -> V_19 == V_42 )
F_30 ( V_44 ) ;
F_34 ( V_44 -> V_12 ) ;
return 0 ;
}
static int F_35 ( struct V_7 * V_44 )
{
int V_6 ;
struct V_7 * V_13 ;
V_13 = F_18 ( & V_4 . V_22 ) ;
if ( ! V_13 )
return 0 ;
V_13 -> V_13 = false ;
F_32 ( V_13 -> V_10 , V_42 ) ;
if ( V_44 -> V_31 ) {
struct V_45 V_46 ;
V_46 . V_32 = V_44 -> V_31 ;
F_36 ( V_47 , & V_46 ) ;
}
V_6 = V_4 . V_2 -> V_48 ( V_44 -> V_10 ) ;
if ( V_6 )
return V_6 ;
if ( V_44 -> V_16 -> V_49 )
V_44 -> V_16 -> V_49 ( V_44 -> V_12 ) ;
if ( V_13 -> V_19 == V_20 )
F_31 ( V_13 ) ;
F_32 ( V_44 -> V_10 , V_20 ) ;
V_44 -> V_13 = true ;
return 0 ;
}
static bool F_37 ( void )
{
struct V_7 * V_8 ;
F_6 (client, &vgasr_priv.clients, list) {
if ( ! V_8 -> V_16 -> V_50 ( V_8 -> V_12 ) ) {
F_12 ( V_51 L_10 , V_8 -> V_10 ) ;
return false ;
}
}
return true ;
}
static T_1
F_38 ( struct V_39 * V_52 , const char T_2 * V_53 ,
T_3 V_54 , T_4 * V_55 )
{
char V_56 [ 64 ] ;
const char * V_57 ;
int V_6 ;
bool V_58 = false , V_50 ;
bool V_59 = false ;
int V_28 = - 1 ;
struct V_7 * V_8 = NULL ;
if ( V_54 > 63 )
V_54 = 63 ;
if ( F_39 ( V_56 , V_53 , V_54 ) )
return - V_60 ;
F_2 ( & V_3 ) ;
if ( ! V_4 . V_13 ) {
V_54 = - V_5 ;
goto V_61;
}
if ( strncmp ( V_56 , L_11 , 3 ) == 0 ) {
F_6 (client, &vgasr_priv.clients, list) {
if ( V_8 -> V_13 || F_40 ( V_8 ) )
continue;
F_32 ( V_8 -> V_10 , V_42 ) ;
if ( V_8 -> V_19 == V_20 )
F_31 ( V_8 ) ;
}
goto V_61;
}
if ( strncmp ( V_56 , L_12 , 2 ) == 0 ) {
F_6 (client, &vgasr_priv.clients, list) {
if ( V_8 -> V_13 || F_40 ( V_8 ) )
continue;
if ( V_8 -> V_19 == V_42 )
F_30 ( V_8 ) ;
F_32 ( V_8 -> V_10 , V_20 ) ;
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
V_8 = F_17 ( & V_4 . V_22 , V_28 ) ;
if ( ! V_8 )
goto V_61;
V_4 . V_63 = false ;
if ( V_59 ) {
V_6 = V_4 . V_2 -> V_48 ( V_28 ) ;
goto V_61;
}
if ( V_8 -> V_13 )
goto V_61;
V_50 = F_37 () ;
if ( V_50 == false && V_58 == false )
goto V_61;
if ( V_50 ) {
V_57 = F_27 ( V_8 -> V_12 ) ;
V_6 = F_33 ( V_8 ) ;
if ( V_6 )
F_12 ( V_51 L_17 , V_6 ) ;
V_6 = F_35 ( V_8 ) ;
if ( V_6 )
F_12 ( V_51 L_18 , V_6 ) ;
} else {
F_12 ( V_24 L_19 , V_8 -> V_10 ) ;
V_4 . V_63 = true ;
V_4 . V_64 = V_28 ;
V_6 = F_33 ( V_8 ) ;
if ( V_6 )
F_12 ( V_51 L_20 , V_6 ) ;
}
V_61:
F_3 ( & V_3 ) ;
return V_54 ;
}
static void F_23 ( struct V_4 * V_65 )
{
if ( V_65 -> V_66 ) {
F_41 ( V_65 -> V_66 ) ;
V_65 -> V_66 = NULL ;
}
if ( V_65 -> V_67 ) {
F_41 ( V_65 -> V_67 ) ;
V_65 -> V_67 = NULL ;
}
}
static int F_7 ( struct V_4 * V_65 )
{
if ( V_65 -> V_67 )
return 0 ;
V_65 -> V_67 = F_42 ( L_21 , NULL ) ;
if ( ! V_65 -> V_67 ) {
F_12 ( V_51 L_22 ) ;
goto V_68;
}
V_65 -> V_66 = F_43 ( L_23 , 0644 ,
V_65 -> V_67 , NULL , & V_69 ) ;
if ( ! V_65 -> V_66 ) {
F_12 ( V_51 L_24 ) ;
goto V_68;
}
return 0 ;
V_68:
F_23 ( V_65 ) ;
return - 1 ;
}
int F_44 ( void )
{
struct V_7 * V_8 ;
const char * V_57 ;
int V_6 ;
int V_70 = - V_5 ;
F_2 ( & V_3 ) ;
if ( ! V_4 . V_63 )
goto V_70;
F_12 ( V_24 L_25 , V_4 . V_64 ) ;
V_8 = F_17 ( & V_4 . V_22 ,
V_4 . V_64 ) ;
if ( ! V_8 || ! F_37 () )
goto V_70;
V_57 = F_27 ( V_8 -> V_12 ) ;
V_6 = F_35 ( V_8 ) ;
if ( V_6 )
F_12 ( V_51 L_26 , V_6 ) ;
V_4 . V_63 = false ;
V_70 = 0 ;
V_70:
F_3 ( & V_3 ) ;
return V_70 ;
}
