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
return ( V_25 -> V_27 &&
( strcasecmp ( ( char * ) V_23 , V_25 -> V_27 ) == 0 ) ) ;
}
static int F_17 ( struct V_1 * V_2 , void * V_23 )
{
return F_16 ( V_2 ) -> V_2 . V_26 == V_23 ;
}
static int F_18 ( struct V_24 * V_25 )
{
struct V_28 * V_2 ;
int V_29 ;
V_2 = F_19 ( V_25 , NULL , & V_30 ) ;
if ( ! V_2 )
return - V_31 ;
V_2 -> V_2 . V_32 = & V_33 ;
V_2 -> V_2 . V_34 = & V_35 ;
V_29 = F_20 ( V_2 ) ;
if ( V_29 )
F_21 ( V_2 ) ;
return V_29 ;
}
static int F_22 ( const struct V_36 * V_37 )
{
struct V_24 * V_38 , * V_39 ;
struct V_1 * V_2 ;
int V_29 = 0 ;
V_38 = F_23 ( L_1 ) ;
F_24 (root, child) {
if ( ! F_25 ( V_37 , V_39 ) )
continue;
V_2 = F_26 ( & V_33 , NULL , V_39 ,
F_17 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
continue;
}
V_29 = F_18 ( V_39 ) ;
if ( V_29 ) {
F_28 ( V_40 L_2 ,
V_41 , V_29 ) ;
F_29 ( V_39 ) ;
break;
}
}
F_29 ( V_38 ) ;
return V_29 ;
}
int F_30 ( struct V_42 * V_43 )
{
F_22 ( V_43 -> V_44 . V_45 ) ;
V_43 -> V_44 . V_32 = & V_33 ;
return F_31 ( & V_43 -> V_44 ) ;
}
void F_32 ( struct V_42 * V_43 )
{
F_33 ( & V_43 -> V_44 ) ;
}
int F_34 ( T_5 V_46 , T_6 V_47 ,
unsigned long V_48 , const char * V_49 ,
void * V_50 )
{
unsigned int V_51 = F_35 ( NULL , V_46 ) ;
if ( ! V_51 )
return - V_52 ;
return F_36 ( V_51 , V_47 , V_48 , V_49 , V_50 ) ;
}
void F_37 ( T_5 V_46 , void * V_50 )
{
unsigned int V_51 = F_38 ( NULL , V_46 ) ;
F_39 ( V_51 , V_50 ) ;
F_40 ( V_51 ) ;
}
static char * F_41 ( const char * V_53 , T_1 V_54 )
{
char * V_55 = F_2 ( V_54 + 1 , V_56 ) ;
if ( ! V_55 )
return NULL ;
memcpy ( V_55 , V_53 , V_54 ) ;
V_55 [ V_54 ] = '\0' ;
if ( V_55 [ V_54 - 1 ] == '\n' )
V_55 [ V_54 - 1 ] = '\0' ;
return V_55 ;
}
static T_7 F_42 ( struct V_57 * V_32 ,
const char * V_58 , T_1 V_54 )
{
struct V_24 * V_25 = NULL ;
struct V_1 * V_2 ;
char * V_59 ;
T_7 V_60 = 0 ;
V_59 = F_41 ( V_58 , V_54 ) ;
if ( ! V_59 )
return - V_31 ;
V_2 = F_26 ( & V_33 , NULL , V_59 ,
F_15 ) ;
if ( V_2 ) {
F_27 ( V_2 ) ;
F_28 ( V_61 L_3 ,
V_41 , V_59 ) ;
V_60 = - V_62 ;
goto V_55;
}
if ( ( V_25 = F_23 ( V_59 ) ) ) {
V_60 = F_18 ( V_25 ) ;
F_29 ( V_25 ) ;
} else {
F_28 ( V_61 L_4 ,
V_41 , V_59 ) ;
V_60 = - V_63 ;
}
V_55:
F_4 ( V_59 ) ;
if ( V_60 )
return V_60 ;
return V_54 ;
}
static T_7 F_43 ( struct V_57 * V_32 ,
const char * V_58 , T_1 V_54 )
{
struct V_1 * V_2 ;
char * V_59 ;
V_59 = F_41 ( V_58 , V_54 ) ;
if ( ! V_59 )
return - V_31 ;
if ( ( V_2 = F_26 ( & V_33 , NULL , V_59 ,
F_15 ) ) ) {
F_44 ( F_16 ( V_2 ) ) ;
F_27 ( V_2 ) ;
F_4 ( V_59 ) ;
return V_54 ;
} else {
F_28 ( V_61 L_5 ,
V_41 , V_59 ) ;
F_4 ( V_59 ) ;
return - V_63 ;
}
}
static int F_45 ( struct V_1 * V_2 , struct V_64 * V_43 )
{
const struct V_36 * V_37 = V_43 -> V_45 ;
if ( ! V_37 )
return 0 ;
return F_46 ( V_37 , V_2 ) != NULL ;
}
static int F_47 ( struct V_1 * V_2 )
{
int error = - V_63 ;
struct V_42 * V_43 ;
struct V_28 * V_65 ;
V_43 = F_48 ( V_2 -> V_44 ) ;
V_65 = F_16 ( V_2 ) ;
if ( ! V_43 -> V_66 )
return error ;
F_49 ( V_65 ) ;
if ( F_50 ( V_2 , V_2 -> V_44 ) )
error = V_43 -> V_66 ( V_65 ) ;
if ( error )
F_51 ( V_65 ) ;
return error ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_28 * V_65 = F_16 ( V_2 ) ;
struct V_42 * V_43 = F_48 ( V_2 -> V_44 ) ;
if ( V_2 -> V_44 && V_43 -> remove )
V_43 -> remove ( V_65 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_28 * V_65 = F_16 ( V_2 ) ;
struct V_42 * V_43 = F_48 ( V_2 -> V_44 ) ;
if ( V_2 -> V_44 && V_43 -> V_67 )
V_43 -> V_67 ( V_65 ) ;
}
static T_7 F_54 ( struct V_1 * V_2 ,
struct V_68 * V_69 , char * V_58 )
{
struct V_28 * V_70 ;
V_70 = F_16 ( V_2 ) ;
return sprintf ( V_58 , L_6 , V_70 -> V_2 . V_26 -> V_27 ) ;
}
static T_7 F_55 ( struct V_1 * V_2 ,
struct V_68 * V_69 , char * V_58 )
{
struct V_28 * V_70 ;
V_70 = F_16 ( V_2 ) ;
return sprintf ( V_58 , L_6 , V_70 -> V_2 . V_26 -> V_71 ) ;
}
static T_7 F_56 ( struct V_1 * V_2 ,
struct V_68 * V_69 , char * V_58 )
{
T_7 V_72 = F_57 ( V_2 , V_58 , V_73 - 2 ) ;
V_58 [ V_72 ] = '\n' ;
V_58 [ V_72 + 1 ] = 0 ;
return V_72 + 1 ;
}
static int T_8 F_58 ( void )
{
int V_74 ;
F_28 ( V_75 L_7 ) ;
V_74 = F_59 ( & V_33 ) ;
if ( V_74 ) {
F_28 ( V_40 L_8 ,
V_41 ) ;
return V_74 ;
}
V_74 = F_60 ( & V_30 ) ;
if ( V_74 ) {
F_28 ( V_61 L_9 ,
V_41 , V_74 ) ;
F_61 ( & V_33 ) ;
return V_74 ;
}
V_74 = F_22 ( V_76 ) ;
if ( V_74 ) {
F_62 ( & V_30 ) ;
F_61 ( & V_33 ) ;
return V_74 ;
}
return 0 ;
}
