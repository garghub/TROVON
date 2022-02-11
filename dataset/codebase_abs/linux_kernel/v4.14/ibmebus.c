static void * F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_4 ,
T_3 V_5 ,
unsigned long V_6 )
{
void * V_7 ;
V_7 = F_2 ( V_3 , V_5 ) ;
* V_4 = ( T_2 ) V_7 ;
return V_7 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_8 ,
T_2 V_4 ,
unsigned long V_6 )
{
F_4 ( V_8 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 ,
struct V_9 * V_9 ,
unsigned long V_10 ,
T_1 V_3 ,
enum V_11 V_12 ,
unsigned long V_6 )
{
return ( T_2 ) ( F_6 ( V_9 ) + V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_2 V_13 ,
T_1 V_3 ,
enum V_11 V_12 ,
unsigned long V_6 )
{
return;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
int V_16 , enum V_11 V_12 ,
unsigned long V_6 )
{
struct V_14 * V_17 ;
int V_18 ;
F_9 (sgl, sg, nents, i) {
V_17 -> V_19 = ( T_2 ) F_10 ( V_17 ) ;
V_17 -> V_20 = V_17 -> V_21 ;
}
return V_16 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_14 * V_17 ,
int V_16 , enum V_11 V_12 ,
unsigned long V_6 )
{
return;
}
static int F_12 ( struct V_1 * V_2 , T_4 V_22 )
{
return V_22 == F_13 ( 64 ) ;
}
static T_4 F_14 ( struct V_1 * V_2 )
{
return F_13 ( 64 ) ;
}
static int F_15 ( struct V_1 * V_2 , void * V_23 )
{
struct V_24 * V_25 = F_16 ( V_2 ) -> V_2 . V_26 ;
return ( F_17 ( V_23 ) == V_25 ) ;
}
static int F_18 ( struct V_1 * V_2 , void * V_23 )
{
return F_16 ( V_2 ) -> V_2 . V_26 == V_23 ;
}
static int F_19 ( struct V_24 * V_25 )
{
struct V_27 * V_2 ;
int V_28 ;
V_2 = F_20 ( V_25 , NULL , & V_29 ) ;
if ( ! V_2 )
return - V_30 ;
V_2 -> V_2 . V_31 = & V_32 ;
V_2 -> V_2 . V_33 = & V_34 ;
V_28 = F_21 ( V_2 ) ;
if ( V_28 )
F_22 ( V_2 ) ;
return V_28 ;
}
static int F_23 ( const struct V_35 * V_36 )
{
struct V_24 * V_37 , * V_38 ;
struct V_1 * V_2 ;
int V_28 = 0 ;
V_37 = F_17 ( L_1 ) ;
F_24 (root, child) {
if ( ! F_25 ( V_36 , V_38 ) )
continue;
V_2 = F_26 ( & V_32 , NULL , V_38 ,
F_18 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
continue;
}
V_28 = F_19 ( V_38 ) ;
if ( V_28 ) {
F_28 ( V_39 L_2 ,
V_40 , V_28 ) ;
F_29 ( V_38 ) ;
break;
}
}
F_29 ( V_37 ) ;
return V_28 ;
}
int F_30 ( struct V_41 * V_42 )
{
F_23 ( V_42 -> V_43 . V_44 ) ;
V_42 -> V_43 . V_31 = & V_32 ;
return F_31 ( & V_42 -> V_43 ) ;
}
void F_32 ( struct V_41 * V_42 )
{
F_33 ( & V_42 -> V_43 ) ;
}
int F_34 ( T_5 V_45 , T_6 V_46 ,
unsigned long V_47 , const char * V_48 ,
void * V_49 )
{
unsigned int V_50 = F_35 ( NULL , V_45 ) ;
if ( ! V_50 )
return - V_51 ;
return F_36 ( V_50 , V_46 , V_47 , V_48 , V_49 ) ;
}
void F_37 ( T_5 V_45 , void * V_49 )
{
unsigned int V_50 = F_38 ( NULL , V_45 ) ;
F_39 ( V_50 , V_49 ) ;
F_40 ( V_50 ) ;
}
static char * F_41 ( const char * V_52 , T_1 V_53 )
{
char * V_54 = F_2 ( V_53 + 1 , V_55 ) ;
if ( ! V_54 )
return NULL ;
memcpy ( V_54 , V_52 , V_53 ) ;
V_54 [ V_53 ] = '\0' ;
if ( V_54 [ V_53 - 1 ] == '\n' )
V_54 [ V_53 - 1 ] = '\0' ;
return V_54 ;
}
static T_7 F_42 ( struct V_56 * V_31 ,
const char * V_57 , T_1 V_53 )
{
struct V_24 * V_25 = NULL ;
struct V_1 * V_2 ;
char * V_58 ;
T_7 V_59 = 0 ;
V_58 = F_41 ( V_57 , V_53 ) ;
if ( ! V_58 )
return - V_30 ;
V_2 = F_26 ( & V_32 , NULL , V_58 ,
F_15 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
F_28 ( V_60 L_3 ,
V_40 , V_58 ) ;
V_59 = - V_61 ;
goto V_54;
}
if ( ( V_25 = F_17 ( V_58 ) ) ) {
V_59 = F_19 ( V_25 ) ;
F_29 ( V_25 ) ;
} else {
F_28 ( V_60 L_4 ,
V_40 , V_58 ) ;
V_59 = - V_62 ;
}
V_54:
F_4 ( V_58 ) ;
if ( V_59 )
return V_59 ;
return V_53 ;
}
static T_7 F_43 ( struct V_56 * V_31 ,
const char * V_57 , T_1 V_53 )
{
struct V_1 * V_2 ;
char * V_58 ;
V_58 = F_41 ( V_57 , V_53 ) ;
if ( ! V_58 )
return - V_30 ;
if ( ( V_2 = F_26 ( & V_32 , NULL , V_58 ,
F_15 ) ) ) {
F_44 ( F_16 ( V_2 ) ) ;
F_27 ( V_2 ) ;
F_4 ( V_58 ) ;
return V_53 ;
} else {
F_28 ( V_60 L_5 ,
V_40 , V_58 ) ;
F_4 ( V_58 ) ;
return - V_62 ;
}
}
static int F_45 ( struct V_1 * V_2 , struct V_63 * V_42 )
{
const struct V_35 * V_36 = V_42 -> V_44 ;
if ( ! V_36 )
return 0 ;
return F_46 ( V_36 , V_2 ) != NULL ;
}
static int F_47 ( struct V_1 * V_2 )
{
int error = - V_62 ;
struct V_41 * V_42 ;
struct V_27 * V_64 ;
V_42 = F_48 ( V_2 -> V_43 ) ;
V_64 = F_16 ( V_2 ) ;
if ( ! V_42 -> V_65 )
return error ;
F_49 ( V_64 ) ;
if ( F_50 ( V_2 , V_2 -> V_43 ) )
error = V_42 -> V_65 ( V_64 ) ;
if ( error )
F_51 ( V_64 ) ;
return error ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_27 * V_64 = F_16 ( V_2 ) ;
struct V_41 * V_42 = F_48 ( V_2 -> V_43 ) ;
if ( V_2 -> V_43 && V_42 -> remove )
V_42 -> remove ( V_64 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_27 * V_64 = F_16 ( V_2 ) ;
struct V_41 * V_42 = F_48 ( V_2 -> V_43 ) ;
if ( V_2 -> V_43 && V_42 -> V_66 )
V_42 -> V_66 ( V_64 ) ;
}
static T_7 F_54 ( struct V_1 * V_2 ,
struct V_67 * V_68 , char * V_57 )
{
struct V_27 * V_69 ;
V_69 = F_16 ( V_2 ) ;
return sprintf ( V_57 , L_6 , V_69 -> V_2 . V_26 ) ;
}
static T_7 F_55 ( struct V_1 * V_2 ,
struct V_67 * V_68 , char * V_57 )
{
struct V_27 * V_69 ;
V_69 = F_16 ( V_2 ) ;
return sprintf ( V_57 , L_7 , V_69 -> V_2 . V_26 -> V_70 ) ;
}
static T_7 F_56 ( struct V_1 * V_2 ,
struct V_67 * V_68 , char * V_57 )
{
return F_57 ( V_2 , V_57 , V_71 ) ;
}
static int T_8 F_58 ( void )
{
int V_72 ;
F_28 ( V_73 L_8 ) ;
V_72 = F_59 ( & V_32 ) ;
if ( V_72 ) {
F_28 ( V_39 L_9 ,
V_40 ) ;
return V_72 ;
}
V_72 = F_60 ( & V_29 ) ;
if ( V_72 ) {
F_28 ( V_60 L_10 ,
V_40 , V_72 ) ;
F_61 ( & V_32 ) ;
return V_72 ;
}
V_72 = F_23 ( V_74 ) ;
if ( V_72 ) {
F_62 ( & V_29 ) ;
F_61 ( & V_32 ) ;
return V_72 ;
}
return 0 ;
}
