static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_9 . V_10 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
memcpy ( V_5 , V_7 -> V_9 . V_11 , V_7 -> V_9 . V_12 ) ;
return V_7 -> V_9 . V_12 ;
}
static int F_4 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
struct V_6 * V_15 = F_2 ( V_13 -> V_16 ,
struct V_6 , V_17 ) ;
F_5 ( & V_15 -> V_8 ) ;
V_14 -> V_18 = V_15 ;
F_6 ( L_2 , V_15 ) ;
return 0 ;
}
static int F_7 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
struct V_6 * V_15 = V_14 -> V_18 ;
F_6 ( L_3 , V_14 -> V_18 ) ;
V_14 -> V_18 = NULL ;
F_8 ( & V_15 -> V_8 ) ;
return 0 ;
}
int F_9 ( unsigned V_19 , T_2 * V_20 )
{
if ( V_21 )
return - V_22 ;
V_21 = V_19 ;
V_23 = V_20 ;
return 0 ;
}
void F_10 ( unsigned V_19 )
{
if ( V_19 == V_21 ) {
V_21 = 0 ;
V_23 = NULL ;
}
}
static T_2 * F_11 ( unsigned V_24 )
{
if ( V_21 == V_24 )
return V_23 ;
else
return NULL ;
}
static long F_12 ( struct V_14 * V_14 , unsigned int V_24 ,
unsigned long V_25 )
{
struct V_6 * V_15 = V_14 -> V_18 ;
int V_26 ;
T_2 * V_20 ;
V_20 = F_11 ( V_24 ) ;
if ( V_20 )
V_26 = V_20 ( & V_15 -> V_27 , V_24 , V_25 ) ;
else {
F_13 ( L_4 , V_24 , V_15 ) ;
V_26 = - V_28 ;
}
return V_26 ;
}
struct V_29 * F_14 ( const char * V_30 )
{
struct V_6 * V_15 ;
struct V_31 * V_32 ;
struct V_14 * V_14 ;
int error ;
if ( ! V_30 || ! * V_30 ) {
F_13 ( L_5 ) ;
return F_15 ( - V_22 ) ;
}
V_32 = F_16 ( sizeof( * V_32 ) , V_33 ) ;
if ( F_17 ( ! V_32 ) )
return F_15 ( - V_34 ) ;
V_14 = F_18 ( V_30 , V_35 , 0 ) ;
if ( F_19 ( V_14 ) ) {
error = F_20 ( V_14 ) ;
goto V_36;
}
if ( V_14 -> V_37 != & V_38 ) {
error = - V_22 ;
goto V_39;
}
V_15 = V_14 -> V_18 ;
V_32 -> V_27 = V_15 -> V_27 ;
V_32 -> V_14 = V_14 ;
V_32 -> V_15 = V_15 ;
return & V_32 -> V_27 ;
V_39:
F_21 ( V_14 ) ;
V_36:
F_22 ( V_32 ) ;
return F_15 ( error ) ;
}
static inline bool F_23 ( const T_3 * V_40 , unsigned V_41 ,
const T_3 * V_42 , unsigned V_43 )
{
if ( ! V_43 )
return true ;
if ( V_41 != V_43 )
return false ;
return 0 == memcmp ( V_40 , V_42 , V_41 ) ;
}
static int F_24 ( struct V_1 * V_2 , const void * V_44 )
{
struct V_6 * V_15 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
const struct V_45 * V_9 = V_44 ;
if ( F_23 ( V_15 -> V_9 . V_11 , V_15 -> V_9 . V_12 ,
V_9 -> V_11 , V_9 -> V_12 ) &&
F_23 ( V_15 -> V_9 . V_10 , V_15 -> V_9 . V_46 ,
V_9 -> V_10 , V_9 -> V_46 ) ) {
F_6 ( L_6 ,
V_9 -> V_12 , V_9 -> V_46 ) ;
return 1 ;
} else {
return 0 ;
}
}
struct V_29 * F_25 ( const struct V_45 * V_9 )
{
struct V_1 * V_2 = F_26 ( & V_47 , NULL , V_9 , F_24 ) ;
if ( F_27 ( V_2 ) ) {
struct V_31 * V_32 = F_16 ( sizeof( * V_32 ) , V_33 ) ;
struct V_6 * V_15 = F_2 ( V_2 ,
struct V_6 , V_8 ) ;
if ( F_17 ( ! V_32 ) ) {
F_8 ( V_2 ) ;
return F_15 ( - V_34 ) ;
}
V_32 -> V_27 = V_15 -> V_27 ;
V_32 -> V_15 = V_15 ;
return & V_32 -> V_27 ;
}
return F_15 ( - V_48 ) ;
}
void F_28 ( struct V_29 * V_27 )
{
if ( V_27 && ! F_19 ( V_27 ) ) {
struct V_31 * V_32 =
F_2 ( V_27 , struct V_31 , V_27 ) ;
struct V_6 * V_15 = V_32 -> V_15 ;
F_29 ( V_27 -> V_49 != V_15 -> V_27 . V_49 ) ;
if ( V_32 -> V_14 ) {
F_5 ( & V_15 -> V_8 ) ;
F_21 ( V_32 -> V_14 ) ;
}
F_8 ( & V_15 -> V_8 ) ;
F_22 ( V_32 ) ;
}
}
const struct V_45 * F_30 ( struct V_29 * V_27 )
{
struct V_31 * V_32 =
F_2 ( V_27 , struct V_31 , V_27 ) ;
return & V_32 -> V_15 -> V_9 ;
}
bool F_31 ( struct V_29 * V_27 , const struct V_45 * V_9 )
{
struct V_31 * V_32 =
F_2 ( V_27 , struct V_31 , V_27 ) ;
struct V_6 * V_15 = V_32 -> V_15 ;
return ( V_15 -> V_9 . V_12 == V_9 -> V_12 ) &&
F_23 ( V_15 -> V_9 . V_11 , V_15 -> V_9 . V_12 ,
V_9 -> V_11 , V_9 -> V_12 ) &&
( V_15 -> V_9 . V_46 == V_9 -> V_46 ) &&
F_23 ( V_15 -> V_9 . V_10 , V_15 -> V_9 . V_46 ,
V_9 -> V_10 , V_9 -> V_46 ) ;
}
static int F_32 ( struct V_6 * V_15 )
{
struct V_49 * V_49 = V_15 -> V_27 . V_49 ;
char V_50 [ V_51 ] ;
int error ;
F_6 ( L_7 ,
V_15 , V_49 , V_49 -> V_52 ) ;
error = F_33 ( V_49 , 10 * V_53 , 5 , NULL ) ;
if ( error )
F_13 ( L_8 ) ;
F_34 ( V_50 , & V_54 , false , true ) ;
if ( F_35 ( & V_15 -> V_27 , V_50 , & V_15 -> V_9 ) )
return - V_48 ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_15 = F_2 ( V_2 , struct V_6 ,
V_8 ) ;
struct V_49 * V_49 = V_15 -> V_27 . V_49 ;
F_22 ( V_15 -> V_9 . V_10 ) ;
if ( V_15 -> V_17 . V_55 )
F_37 ( & V_15 -> V_17 ) ;
F_38 ( & V_15 -> V_27 ) ;
F_39 ( V_49 ) ;
F_40 ( L_9 ,
V_15 -> V_56 ? V_15 -> V_56 -> V_57 : NULL ) ;
if ( V_15 -> V_56 )
F_41 ( V_15 -> V_56 ) ;
F_42 ( & V_58 , V_15 -> V_59 ) ;
F_22 ( V_15 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_49 * V_49 = F_44 ( V_2 ) ;
struct V_60 * V_56 ;
struct V_6 * V_15 ;
int V_59 ;
int error ;
if ( V_49 -> type != V_61 )
return - V_48 ;
do {
if ( ! F_45 ( & V_58 , V_33 ) )
return - V_48 ;
error = F_46 ( & V_58 , & V_59 ) ;
} while ( error == - V_62 );
if ( error )
return error ;
if ( V_59 >= V_63 ) {
error = - V_64 ;
goto V_65;
}
error = - V_34 ;
V_15 = F_16 ( sizeof( * V_15 ) , V_33 ) ;
if ( NULL == V_15 )
goto V_65;
F_47 ( V_2 , V_15 ) ;
V_15 -> V_59 = V_59 ;
V_56 = F_48 ( 1 ) ;
if ( ! V_56 ) {
F_13 ( L_10 ) ;
goto V_66;
}
V_56 -> V_67 = V_68 ;
V_56 -> V_69 = V_15 -> V_59 ;
sprintf ( V_56 -> V_57 , L_11 , V_15 -> V_59 ) ;
V_15 -> V_56 = V_56 ;
F_49 ( V_49 ) ;
F_50 ( & V_15 -> V_27 , V_49 ) ;
error = F_32 ( V_15 ) ;
if ( error ) {
F_13 ( L_12 ) ;
goto V_70;
}
F_51 ( & V_15 -> V_17 , & V_38 ) ;
V_15 -> V_17 . V_55 = V_71 ;
error = F_52 ( & V_15 -> V_17 ,
F_53 ( V_68 , V_15 -> V_59 ) , 1 ) ;
if ( error ) {
F_13 ( L_13 ) ;
goto V_70;
}
V_15 -> V_8 . V_72 = V_15 -> V_17 . V_2 ;
V_15 -> V_8 . V_73 = & V_47 ;
V_15 -> V_8 . V_74 = V_2 ;
V_15 -> V_8 . V_75 = F_36 ;
error = F_54 ( & V_15 -> V_8 , V_56 -> V_57 ) ;
if ( error ) {
F_13 ( L_14 , error ) ;
goto V_76;
}
error = F_55 ( & V_15 -> V_8 ) ;
if ( error ) {
F_13 ( L_15 , error ) ;
goto V_76;
}
F_5 ( & V_15 -> V_8 ) ;
F_40 ( L_16 , V_56 -> V_57 ) ;
return 0 ;
V_76:
F_37 ( & V_15 -> V_17 ) ;
V_70:
F_39 ( V_49 ) ;
F_41 ( V_56 ) ;
V_66:
F_47 ( V_2 , NULL ) ;
F_22 ( V_15 ) ;
V_65:
F_42 ( & V_58 , V_59 ) ;
return error ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_49 * V_49 = F_44 ( V_2 ) ;
struct V_6 * V_15 = F_57 ( V_2 ) ;
if ( ! V_15 || ( V_15 -> V_27 . V_49 != V_49 ) ) {
F_13 ( L_17 ,
V_2 , V_15 , V_15 ? V_15 -> V_27 . V_49 : NULL ,
V_49 ) ;
}
F_58 ( & V_15 -> V_8 ) ;
F_8 ( & V_15 -> V_8 ) ;
return 0 ;
}
static int T_4 F_59 ( void )
{
int V_77 ;
V_77 = F_60 ( & V_47 ) ;
if ( V_77 ) {
F_13 ( L_18 , V_77 ) ;
return V_77 ;
}
V_77 = F_61 ( F_53 ( V_68 , 0 ) ,
V_63 , V_78 ) ;
if ( V_77 ) {
F_13 ( L_19 ,
V_68 , V_77 ) ;
goto V_79;
}
V_77 = F_62 ( & V_80 . V_81 ) ;
if ( V_77 ) {
F_13 ( L_20 , V_77 ) ;
goto V_82;
}
F_40 ( L_21 , V_83 ) ;
return 0 ;
V_82:
F_63 ( F_53 ( V_68 , 0 ) , V_63 ) ;
V_79:
F_64 ( & V_47 ) ;
return V_77 ;
}
static void T_5 F_65 ( void )
{
F_66 ( & V_80 . V_81 ) ;
F_63 ( F_53 ( V_68 , 0 ) , V_63 ) ;
F_64 ( & V_47 ) ;
F_40 ( L_22 , V_83 ) ;
}
